/*
	OuDia - Win32 Application Software to draw a "Train Service Planning
 Diagram" based on a "Train Timetable".

Copyright (C) 2006-2017 take-okm

This program is free software; you can redistribute it and/or modify it 
under the terms of the GNU General Public License as published by the Free 
Software Foundation; either version 3 of the License, or (at your option) 
any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT 
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
more details. 

You should have received a copy of the GNU General Public License along with
 this program. If not, see <http://www.gnu.org/licenses/>.

  In addition, as a special exception, take-okm
  gives permission to link the code of this program with
  the "MFC(Microsoft Foundation Class library) Version 9.0" 
  (or with modified versions of "MFC Version 9.0" that use the same license as 
  "MFC Version 9.0" ), and distribute linked combinations including
  the two.  You must obey the GNU General Public License in all
  respects for all of the code used other than  "MFC".  If you modify
  this file, you may extend this exception to your version of the
  file, but you are not obligated to do so.  If you do not wish to
  do so, delete this exception statement from your version.


(訳: 

	OuDia - 列車時刻表をもとに、ダイヤグラムを描画するWin32アプリケーシ
ョン。

Copyright (C) 2006-2017 take-okm 

このプログラムはフリーソフトウェアです。あなたはこれを、フリーソフトウェア財
団によって発行されたGNU 一般公衆利用許諾書(バージョン3か、それ以降のバージョ
ンのうちどれか)が定める条件の下で再頒布または改変 することができます。

このプログラムは有用であることを願って頒布されますが、*全くの無保証 *です。
商業可能性の保証や特定目的への適合性は、言外に示されたものも 含め、全く存在
しません。詳しくはGNU 一般公衆利用許諾書をご覧ください。

あなたはこのプログラムと共に、GNU 一般公衆利用許諾書のコピーを一部 受け取っ
ているはずです。もし受け取っていなければ、<http://www.gnu.org/licenses/> を
ご覧ください。

)

  加えて、特別な例外として、take-okm はこのプログラムのコードを 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  あるいは "MFC Version 9.0" と同じライセンスが適用された
  "MFC Version 9.0" の改変されたバージョン)とリンクし、
  リンクされた両者を含む結合著作物を頒布する許可を与えます。
  あなたは "MFC" 以外で使われているすべて
  のコードに関しては全面的にGNU一般公衆利用許諾契約書に従わなければ
  なりません。あなたがこのファイルを改変したならば、あなたはこの例外
  をあなたのバージョンのファイルに引き続き設けることもできますが、そ
  うする義務はありません。もし例外を設けたくなければ、この例外条項を
  あなたのバージョンからは削除してください。)
*/
/*
// ****************************************************************
//	CWjkState_Ressyahensyu.cpp
// $Id: CWjkState_Ressyahensyu.cpp 357 2016-08-18 16:59:16Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"



#include "logmsg/LogMsg.h"
#include "DcDraw/CDcdLine.h"
#include "NsOu/OuNew.h"
#include "NsOu/dynamic_castOu.h"
#include "NsMu\CaMui.h"

#include "CWjkState_Ressyahensyu.h"
#include "CWjkState_Renzoku.h"
#include "..\..\DiagramEdit.h"
#include "..\CDlgRessyaProp.h"
#include "..\CDlgEkiJikokuProp.h"
#include "..\CDlgModifyEkijikokuOperation2.h"
#include "..\..\CRfEditCmdHolder.h"
#include "..\..\DedRosenFileData\EditCmd\EditCmd.h"

#include "..\..\entDed\CDedRessyaSoater_Ressyasyubetsu.h"
#include "..\..\entDed\CDedRessyaSoater_Bikou.h"
#include "..\..\entDed\CDedRessyaSoater_Ekiatsukai.h"
#include "..\..\entDed\CRessyaContUnifier.h"
#include "..\..\entDgr\CDedRessyaSoater_Transfer.h"

#include "..\..\CDlgProgress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



namespace ViewJikokuhyou{ namespace WndJikokuhyou{

// ****************************************************************
//	CWjkState_Ressyahensyu
// ****************************************************************
// --------------------------------
//@name OnUpdate下請関数
// --------------------------------
void CWjkState_Ressyahensyu::OnUpdate_All() 
{
	LogMsg( "CWjkState_Ressyahensyu::OnUpdate_All()" ) ;
 
	getCWndDcdGrid()->updateUIAll() ;

	LogMsg( "CWjkState_Ressyahensyu::OnUpdate_All()=" ) ;
}


void CWjkState_Ressyahensyu::OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) 
{
	int iDiaIndex = GetDocument()->getDiaIndex() ;
	if ( !( pCommand->getDiaIndex() == iDiaIndex && 
		pCommand->getRessyahoukou() == GetDocument()->getRessyahoukou() ) )
	{
		return ;
	}
	//	列車のセルを置き換え
	getCWndDcdGrid()->updateUI_ReplaceRessya( 
		pCommand->getIndexDst() ,
		pCommand->getSizeDst() ,
		pCommand->getCentDedRessyaContSrc()->size() ) ;

}



int CWjkState_Ressyahensyu::
		execJikokuhyouPropDlg( bool bInsert , BOOL bQueryEnable  ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	
	//iType = { 0: 駅時刻の編集,1: 列車の編集,2;駅の編集 } 
	int iType = -1 ;

	if ( iRv >= 0 && iType == -1 )
	{
		//	駅プロパティダイアログの使用を判定
		int iResult = execCDlgEkiProp( TRUE ) ;
		if ( iResult >= 0 )
		{
			iType = 2;	//	駅の編集
		}
	}
	if ( iRv >= 0 && iType == -1 )
	{
		int iResult = execCDlgEkijikokuProp( bInsert , TRUE ) ;
		if ( iResult >= 0 )
		{	
			iType = 0 ;	// 駅時刻の編集
		}
	}
	if ( iRv >= 0 && iType == -1 )
	{
		int iResult = execCDlgRessyaProp( bInsert , TRUE ) ;
		//iResult = 
 		//	-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
 		//	-	0 ;	//	ダイアログがキャンセルで終了したため、
 		//		//	変更は発生しませんでした。
 		//	-	-1 ;	//	X列番号が不正です。
 		//	-	-2 ;	//	Y列番号が不正です。
		if ( iResult >= 0 )
		{	
			iType = 1 ;	// 列車の編集
		}
		else
		{
			iRv = iResult ;
		}
	}
	//iType = { 0: 駅時刻の編集,1: 列車の編集,2;駅の編集 } 
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		if ( iType == 2 ) //	2;駅の編集
		{
			iRv = execCDlgEkiProp( FALSE ) ;
		}
		if ( iType == 1 ) //	1: 列車の編集
		{
			// --------------------------------
			//	『列車プロパティ』ダイアログを開く
			// --------------------------------
			iRv = execCDlgRessyaProp( bInsert , FALSE ) ;
			//iRv = 
	 		//	-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
	 		//	-	0 ;	//	ダイアログがキャンセルで終了したため、@n
	 		//			変更は発生しませんでした。
	 		//	-	-1 ;	//	X列番号が不正です。
		}
		if ( iType == 0 )	//0: 駅時刻の編集,, } 
		{
			// --------------------------------
			//	『駅時刻のプロパティ』ダイアログを開く
			// --------------------------------
			iRv = execCDlgEkijikokuProp( bInsert , FALSE ) ;
			//iRv = 
	 		//	-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
	 		//	-	0 ;	//	ダイアログがキャンセルで終了したため、
	 		//		//	変更は発生しませんでした。
	 		//	-	-1 ;	//	X列番号が不正です。
	 		//	-	-2 ;	//	Y列番号が不正です。
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;
}


int CWjkState_Ressyahensyu::
	execCDlgRessyaProp( bool bInsert , BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( bInsert )
		{
			if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_NewItem , ppCmd ) )
			{
				iRv = -1 ;	//	列車選択位置が正しくありません。
			}
		}
		else
		{
			if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
			{
				iRv = -1 ;	//	列車選択位置が正しくありません。
			}
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	『列車プロパティ』ダイアログを開く
		// --------------------------------
		CdYColSpecCont	aYColSpecCont
			= getCWndDcdGrid()->createYColSpecCont() ;

		int iFocus = getCWndDcdGrid()->getCFocus()
			->getFocusCellColumnNumber().getY() + 1 ;
		CdYColSpec	aYColSpec = 
			getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( aYColSpec.getColumnType() 
			== CdYColSpec::ColumnType_Gou )
		{
			iFocus = 4	;	//	号数
		}
		if ( aYColSpec.getColumnType() 
			== CdYColSpec::ColumnType_Bikou )
		{
			iFocus = 5	;	//	備考
		}

		CDlgRessyaProp	aDlg( 
			bInsert , 
			pCmd->getCaMuiSelect()->getMuPtr() , 
			iFocus , 
			&m_CKeyinputSenderToModalDlg , 
			getCWndDcdGrid() );
		if ( aDlg.DoModal() == IDOK )
		{
			iRv = 1 ;
		}
		//iRv = 
		//	1 ;	//	列車の追加・またはプロパティの変更を行いました。
		//	0 ;	//	ダイアログがキャンセルで終了したため、
		//		//	変更は発生しませんでした。
		//pCentDedRessyaSelectedCont = 
		//	ダイアログがOKで終了した場合は、
		//	pCentDedRessyaSelectedCont->m_pRessyaContAdaptee の
		//	内容が変更されています。


		// --------------------------------
		//	ダイアログOK時の処理
		// --------------------------------
		if ( iRv == 1 )
		{
			// --------------------------------
			//	編集コマンドを実行
			// --------------------------------
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;

			// --------------------------------
			//	フォーカスセルを、新設列車の始発駅に
			//	移します。
			// --------------------------------
			if ( bInsert )
			{
				//	フォーカスセルを、新設列車のX列に移動
				CDcdGridCell*	pCell = getCWndDcdGrid()->
					getCXDcdGrid()->calcMovedCell( 
						getCWndDcdGrid()->getCFocus()->getFocusCell() , 
						-1 , 
						0 ) ;
				if ( pCell )
				{
					getCWndDcdGrid()->getCFocus()->setFocusCell( pCell ) ;
				}
			}

			// --------------------------------
			//	フォーカスセルのY列番号が
			//	列車番号・列車種別・列車名・号数・備考の
			//	いずれかにある場合だけ、次の位置にフォーカスを
			//	移動します。
			// --------------------------------
			{
				CdYColSpecCont	aYColSpecCont
					= getCWndDcdGrid()->createYColSpecCont() ;

				int iYColumnNumber = getCWndDcdGrid()->getCFocus()
					->getFocusCellColumnNumber().getY() ;
				if ( !( aYColSpecCont.getColumnNumber_Ekijikoku_begin() 
						<= iYColumnNumber && 
						iYColumnNumber 
						 < aYColSpecCont.getColumnNumber_Ekijikoku_end()
				) )
				{
					moveFocusCellToNext( true ) ;
				}
			}
		}
		
	}
	return iRv ;
}

int  CWjkState_Ressyahensyu::
	execCDlgEkiProp( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	int iEkiIndex = -1 ;
	{
		CdXColSpec	aXColSpecFocus = 
			getCWndDcdGrid()->getXColSpecOfFocus() ;
		CdYColSpec	aYColSpecFocus = 
			getCWndDcdGrid()->getYColSpecOfFocus() ;
		if (  
			( aXColSpecFocus.getColumnType() == 
				CdXColSpec::ColumnType_Ekimei ||
			  aXColSpecFocus.getColumnType() == 
				CdXColSpec::ColumnType_Chakuhatsu ) && 
			aYColSpecFocus.getEkiOrder() >= 0 
		)
		{
			const CentDedEkiCont* pCentDedEkiCont = 
				getCDiagramEditDoc()->getCDedRosenFileData()
				->getCentDedRosen()->getCentDedEkiCont() ;
			iEkiIndex = pCentDedEkiCont->EkiOrderOfEkiIndex( 
				getCWndDcdGrid()->getRessyahoukou() ,
				aYColSpecFocus.getEkiOrder() ) ;
		}
		else
		{
			iRv = -1 ;	//	セルの位置が駅名ではありません。
		}
	}
	//iEkiIndex = 駅Index
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		CEkiView* pCEkiView = NULL ;
		getCDiagramEditApp()->openCEkiDoc( &pCEkiView ) ;
		if ( pCEkiView != NULL )
		{
			pCEkiView->openCDlgEkiProp( iEkiIndex ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;
}



int CWjkState_Ressyahensyu::
	execCDlgEkijikokuProp( bool bInsert , BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	CdDedJikokuOrder	aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		if ( bInsert )
		{
			if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_NewItem , ppCmd ) )
			{
				iRv = -1 ;	//	列車選択位置が正しくありません。
			}
		}
		else
		{
			if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
			{
				iRv = -1 ;	//	列車選択位置が正しくありません。
			}
		}
	}
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
				getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	Y列番号が不正です。
		}
	}
	//aCdJikokuOrder = 編集対象の時刻Orderです

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	『駅時刻のプロパティ』ダイアログを開く
		// --------------------------------
		bool bJikokuModify = getCWndDcdGrid()->getModifyEkijikoku() ;

		CDlgEkijikokuProp	aDlg( 
			pCmd->getCaMuiSelect()->getMuPtr() , 
			&bJikokuModify ,
			aCdJikokuOrder.getEkiOrder() ,
			aCdJikokuOrder.getEkiJikokuItem() 
				== CdDedJikokuOrder::EkiJikokuItem_Hatsu ? 2 : 1  , 
			&m_CKeyinputSenderToModalDlg ,  
			getCWndDcdGrid()  ) ;
		if ( aDlg.DoModal() == IDOK )
		{
			iRv = 1 ;
		}
		// --------------------------------
		//	ダイアログOK時の処理
		// --------------------------------
		if ( iRv == 1 )
		{
			//	CWndJikokuhyou オブジェクトに
			//	繰上げ・繰下げの設定を反映
			getCWndDcdGrid()->setModifyEkijikoku( bJikokuModify ) ;

			// --------------------------------
			//	編集コマンドを実行
			// --------------------------------
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;

			// --------------------------------
			//	フォーカスセルを移します。
			// --------------------------------
			if ( bInsert )
			{
				// --------------------------------
				//	フォーカスセルを、新設列車の次の駅に
				//	移します。
				// --------------------------------

				//	フォーカスセルを、新設列車のX列に移動
				{
					CDcdGridCell*	pCell = getCWndDcdGrid()->
						getCXDcdGrid()->calcMovedCell( 
							getCWndDcdGrid()->getCFocus()->getFocusCell() , 
							-1 , 
							0 ) ;
					if ( pCell ){
						getCWndDcdGrid()->getCFocus()->setFocusCell( pCell ) ;
					}
				}
				//	フォーカスセルを次へ移します。
				moveFocusCellToNext( true ) ;	
			}
			else 
			{
				//	フォーカスセルを次へ移します。
				moveFocusCellToNext( true ) ;
			}
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;

}

int CWjkState_Ressyahensyu::
	moveFocusCellToNext( bool bNextEkiOrder ) 
{
	int iRv = 0 ;
	iRv = getCWndDcdGrid()->moveFocusCellToNext( m_bJikokuhyouFocusMoveRight , bNextEkiOrder ) ;
	return iRv ;
}

int CWjkState_Ressyahensyu::
	moveFocusCellToPrev( bool bNextEkiOrder ) 
{
	int iRv = 0 ;
	iRv = getCWndDcdGrid()->moveFocusCellToPrev( m_bJikokuhyouFocusMoveRight , bNextEkiOrder ) ;
	return iRv ;
}

// ********************************
//	コンストラクタ
// ********************************
CWjkState_Ressyahensyu::
	CWjkState_Ressyahensyu( 
		CWndJikokuhyou*	pCWndDcdGrid )
	: super( pCWndDcdGrid )
	, m_bJikokuhyouFocusMoveRight( false ) 
{
}
CWjkState_Ressyahensyu::
	~CWjkState_Ressyahensyu() 
{
}

	// ********************************
	//	CWjkState
	// ********************************
		// ********************************
		//@name 操作
		// ********************************
void CWjkState_Ressyahensyu::onEnter() 
{

	//	選択範囲の設定
	getCWndDcdGrid()->getCSelect()->setSelectMode( CSelect::SelectMode_XColumn ) ;

	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	if ( pCentDedRessyaCont != NULL )
	{
		const Mu<const CentDedRessya*>* pMuCentDedRessyaCont = pCentDedRessyaCont->getMuPtr() ;
		getCWndDcdGrid()->getCSelect()->setColumnNumberSelectLimit(
			CdDcdZoneXy( 
				CdDcdZone( 2 , pMuCentDedRessyaCont->size() ) , 
				CdDcdZone( 0 , INT_MAX ) 
			) );
	}

	//	この状態に入場時は、全列車選択を解除
	getCWndDcdGrid()->clearSelect() ;
	

}
void CWjkState_Ressyahensyu::onExit() 
{
}

	// ********************************
	//@name CView からの委譲
	// ********************************
void CWjkState_Ressyahensyu::
	OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC )
	{
		return ;
	}
	// --------------------------------
	//pHint= 
	//	pHintが CRfEditCmdHolder オブジェクトなら、
	//	対応する編集コマンド CRfEditCmd を保持しています。
	//	この場合、this は CRfEditCmd の内容に最適化した
	//	更新を行います。
	//	NULLなら、全更新が要求されています。


	//	このビューが非アクティブで、全更新が要求されている場合は
	//	更新は行いません。
	CView *pActiveView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	if ( pActiveView != getCWndDcdGrid()->GetParent() && getCWndDcdGrid()->getUpdate_All_Requested() )
	{
		//	このビューが非アクティブで、全更新が要求されている場合は
		//	すべての更新を行いません。
	}
	else
	{
		bool bUpdateComplete = false ;
		// --------------------------------
		//	CRfEditCmd に最適化された更新
		// --------------------------------

		Ou<CRfEditCmd> pCmd ;
		if ( pHint != NULL && pHint->IsKindOf( RUNTIME_CLASS( CRfEditCmdHolder ) ) )
		{
			CRfEditCmdHolder* pHolder = 
				(CRfEditCmdHolder*)pHint ;
			pCmd = pHolder->getCmd() ; 
		}


		if ( pCmd != NULL )
		{
			if ( dynamic_castOu<CRfEditCmd_Comment>( pCmd ) || 
				dynamic_castOu<CRfEditCmd_Dia>( pCmd ) || 
				dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) || 
				dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd )
			) 
			{
				//	このビューは、
				//		コメントの変更
				//		ダイヤの変更
				//		ダイヤのプロパティの変更
				//		列車種別の入替
				//	の場合は、更新を行いません。
				bUpdateComplete = true ;
			}
			else if ( dynamic_castOu<CRfEditCmd_Ressya>( pCmd )	) 
			{
				//	列車の変更
				Ou<CRfEditCmd_Ressya>	pCommand = 
					dynamic_castOu<CRfEditCmd_Ressya>( pCmd );
				OnUpdate_CentDedRessya( pCommand ) ;
				bUpdateComplete = true ;
			}
			else
			{
				//CRfEditCmd_Eki
				//	駅の変更は、全更新が必要です。
				//CRfEditCmd_Ressyasyubetsu
				//	列車種別の変更は、全更新が必要です。
				//CRfEditCmd_DedRosenFileDataProp
				//	  路線ファイルのプロパティの変更は、
				//	フォントの変化を伴うため、全更新が必要です。
				//CRfEditCmd_Rosen
				//CRfEditCmd_RosenFileData
				//	駅を包含するオブジェクトです。これが更新された場合は、
				//	全更新が必要です。
			}
		}
		// --------------------------------
		if ( !bUpdateComplete )
		{
			//	全要素を更新
			OnUpdate_All() ;
		}
	}

	// --------------------------------
	//	列選択範囲を設定
	// --------------------------------
	{
		getCWndDcdGrid()->getCSelect()->setSelectMode( CSelect::SelectMode_XColumn ) ;
		const Mu<const CentDedRessya*>* pMuCentDedRessyaCont = getCentDedRessyaCont()->getMuPtr() ;
		getCWndDcdGrid()->getCSelect()->setColumnNumberSelectLimit(
			CdDcdZoneXy( 
				CdDcdZone( 2 , pMuCentDedRessyaCont->size() ) , 
				CdDcdZone( 0 , INT_MAX ) 
			) );
	}

	super::OnUpdate(pSender,  lHint,  pHint) ;
}

	// ********************************
	//@name メッセージハンドラ・コマンドハンドラ-CWnd
	// ********************************
void CWjkState_Ressyahensyu::
	OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	LogMsg( "CWjkState_Ressyahensyu::OnKeyDown %02x %d %02x" , nChar , nRepCnt , nFlags ) ;

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	//	フォーカスセルが新規列車位置にあるときは、
	//	「新規列車のプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdXColSpec aXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
	if ( aXColSpec.getColumnType() == CdXColSpec::ColumnType_NewRessya )
	{
		bInsert = true ;
	}	

	// ****************************************************************

	//	文字キーが押されていて、ダイアログボックスが開いていない場合は
	//	ダイアログボックスを開きます。
	if ( CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown() && 
			m_CKeyinputSenderToModalDlg.startSend() >= 0 )
	{
		m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) ;
		execJikokuhyouPropDlg( bInsert , FALSE ) ;
		m_CKeyinputSenderToModalDlg.endSend() ;
	}
	//	すでにダイアログが起動中→ダイアログボックスにメッセージを転送
	else
	{
		if ( !m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) )
		{
			super::OnKeyDown(  nChar , nRepCnt , nFlags  ) ;
		}
	}
}

void CWjkState_Ressyahensyu::
	OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	LogMsg( "CWjkState_Ressyahensyu::OnKeyUp %02x %d %02x" , nChar , nRepCnt , nFlags ) ;

	{
		if ( !m_CKeyinputSenderToModalDlg.OnKeyUp( nChar , nRepCnt , nFlags ) )
		{
			super::OnKeyUp(  nChar , nRepCnt , nFlags  ) ;
		}
	}
}
void CWjkState_Ressyahensyu::
	OnLButtonDblClk(UINT nFlags, CPoint point)
{
	//	フォーカスセルが新規列車位置にあるときは、
	//	「新規列車のプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdXColSpec aXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
	if ( aXColSpec.getColumnType() == CdXColSpec::ColumnType_NewRessya )
	{
		bInsert = true ;
	}	

	execJikokuhyouPropDlg( bInsert , FALSE ) ;
	super::OnLButtonDblClk(  nFlags , point ) ;
}

void CWjkState_Ressyahensyu::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	LogMsg( "CWjkState_Ressyahensyu::OnChar %02x %d %02x" , nChar , nRepCnt , nFlags ) ;

	{
		super::OnChar( nChar, nRepCnt, nFlags ) ;
	}
}

void CWjkState_Ressyahensyu::OnWM_IME_STARTCOMPOSITION() 
{
	{
		super::OnWM_IME_STARTCOMPOSITION() ;
	}
}

// --------------------------------
int CWjkState_Ressyahensyu::
OnEditCut_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	削除される列車を取得
		// --------------------------------
		CentDedRessyaCont	aCentDedRessyaCont( getCentDedRessyaCont()->createEmptyCont() ) ;
		CaMui<CentDedRessya> aCaMui( &aCentDedRessyaCont ) ;
		aCaMui.insert( pCmd->getCaMuiSelect() ) ;

		// -------------------------------- 
		//	列車をクリップボードに格納
		//	『貼り付け移動量(秒)』の値は、０にします。
		// --------------------------------
		getCDiagramEditDoc()->CentDedRessyaCont_To_Cliboard( 
			aCentDedRessyaCont ) ;
		getCWndDcdGrid()->m_jikanPasteIdouryou = 0 ;
		getCWndDcdGrid()->m_jikanPasteIdouryouPrevValue = 0 ;
		
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		{
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;	
}


int CWjkState_Ressyahensyu::
OnEditCopy_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	削除される列車を取得
		// --------------------------------
		CentDedRessyaCont	aCentDedRessyaCont( getCentDedRessyaCont()->createEmptyCont() ) ;
		CaMui<CentDedRessya> aCaMui( &aCentDedRessyaCont ) ;
		aCaMui.insert( pCmd->getCaMuiSelect() ) ;

		// -------------------------------- 
		//	列車をクリップボードに格納
		//	『貼り付け移動量(秒)』の値は、０にします。
		// --------------------------------
		getCDiagramEditDoc()->CentDedRessyaCont_To_Cliboard( 
			aCentDedRessyaCont ) ;
		getCWndDcdGrid()->m_jikanPasteIdouryou = 0 ;
		getCWndDcdGrid()->m_jikanPasteIdouryouPrevValue = 0 ;
		
		// -------------------------------- 
		//	フォーカスセルを、選択列車中で最大の列車Indexの次位に移動
		// --------------------------------
		{
			//	フォーカスセルの移動によるセル選択を無効化します。
			CPropStack	aPropStack( getCWndDcdGrid() ) ;
			aPropStack.CSelect_setSelectMode( CSelect::SelectMode_NONE ) ;
		
			int iRessyaIndexMax = -1 ;
			{
				CaMuiSelect<CentDedRessya>* pCaMuiSelect = pCmd->getCaMuiSelect() ;
				for ( int iRessyaIndex = pCaMuiSelect->getAdapteeMu()->size() - 1  ; 
					iRessyaIndexMax == -1 && iRessyaIndex >= 0 ; iRessyaIndex -- )
				{
					if ( pCaMuiSelect->getSelect( iRessyaIndex ) )
					{
						iRessyaIndexMax = iRessyaIndex + pCmd->getIndexDst() ;
					}
				}
			}
			//iRessyaIndexMax = 選択されている列車のうち、最大のIndex
			
			int iXColumnNumber = -1 ;
			{
				CdXColSpecCont aCdXColSpecCont = getCWndDcdGrid()->createXColSpecCont() ;
				iXColumnNumber = aCdXColSpecCont.ColumnNumberFromSpec( CdXColSpec( 
								CdXColSpec::ColumnType_Ressya , 
								iRessyaIndexMax ) ) + 1 ;
			}
			//iXColumnNumber = 選択されている列車のうち、最大のIndexの列車の右の列番号
			//	これが、次のフォーカスセルの列番号になります。

			int iYColumnNmber = -1 ;
			{
				CDcdGridCell* pCDcdGridCell = getCWndDcdGrid()->getCFocus()->getFocusCell() ;
				if ( pCDcdGridCell != NULL )
				{
					iYColumnNmber = getCWndDcdGrid()->getCXDcdGrid()->getYColumnNumberOfCell( pCDcdGridCell ) ;
				}
			}
			//iYColumnNmber = 現在のフォーカスセル。次のフォーカスセルも同じ位置になります。

			{
				CDcdGridCell* pCDcdGridCellNew = getCWndDcdGrid()->getCXDcdGrid()->getCell( 
					iXColumnNumber , iYColumnNmber ) ; 
				if ( pCDcdGridCellNew != NULL ){
					getCWndDcdGrid()->getCFocus()->setFocusCell( pCDcdGridCellNew ) ;
				}
			}

		}

		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWjkState_Ressyahensyu::
OnEditPaste_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_NewItem , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		if ( !getCDiagramEditDoc()->
				CentDedRessyaCont_IsClipboardFormatAvailable() )
		{
			iRv = -2 ;	//	クリップボードにデータがありません。
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	クリップボードから列車を取得
		// --------------------------------
		CentDedRessyaCont	aCentDedRessyaCont( 
			getCentDedRessyaCont()->createEmptyCont()) ;
		getCDiagramEditDoc()->CentDedRessyaCont_From_Cliboard( 
			&aCentDedRessyaCont ) ;
		//aCentDedRessyaCont = クリップボード内の列車

		// --------------------------------
		//	貼り付ける列車に移動量を加算
		// --------------------------------
		{
			CdDedJikan	aCdDedJikan = getCWndDcdGrid()->m_jikanPasteIdouryouPrevValue + 
				getCWndDcdGrid()->m_jikanPasteIdouryou ;
			int iInsertIndex ;
			for ( iInsertIndex = 0 ; iInsertIndex < aCentDedRessyaCont.size() ; 
				iInsertIndex ++ )
			{
				CentDedRessya*	pCentDedRessya = 
					aCentDedRessyaCont.getMuPtr()->get( iInsertIndex ) ;
				pCentDedRessya->modifyRessyaJikoku( 
					aCdDedJikan , 
					CdDedJikokuOrder( 0 , CdDedJikokuOrder::EkiJikokuItem_Chaku ) ) ;
			}
		}
		// --------------------------------
		//	貼り付け移動量(秒)を追加
		// --------------------------------
		getCWndDcdGrid()->m_jikanPasteIdouryouPrevValue += 
			getCWndDcdGrid()->m_jikanPasteIdouryou ;
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		{
			//	CWndJikokuhyou::ECreateCmd_NewTrain によって生成された
			//	新規アイテムは削除します。
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;

			//	コマンドにクリップボードからのアイテムを追加します。
			CaMui<CentDedRessya> aCaMui( pCmd->getCaMuiSelect() ) ;
			aCaMui.insert( &aCentDedRessyaCont , 0 , INT_MAX , 0 ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}

	}
	return iRv ;

}


int CWjkState_Ressyahensyu::
OnEditClear_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		{
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;		
}




int CWjkState_Ressyahensyu::
OnEditPasteEkiJikoku_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		if ( !getCDiagramEditDoc()->
				CentDedRessyaCont_IsClipboardFormatAvailable() )
		{
			iRv = -2 ;	//	クリップボードにデータがありません。
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	クリップボードから列車を取得
		// --------------------------------
		CentDedRessyaCont	aCentDedRessyaCont( 
			getCentDedRessyaCont()->createEmptyCont()) ;
		getCDiagramEditDoc()->CentDedRessyaCont_From_Cliboard( 
			&aCentDedRessyaCont ) ;
		//aCentDedRessyaCont = クリップボード内の列車

		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		{
			CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ;
			pCentDedRessya->pasteEkiJikoku( aCentDedRessyaCont.get( 0 ) ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
	}
	return iRv ;	

}


int CWjkState_Ressyahensyu::OnEditSelectAll_Process( 
	BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		getCWndDcdGrid()->selectAll() ;
	}
	return iRv ;
}

// --------------------------------

int CWjkState_Ressyahensyu::
	OnJikokuhyouRessyaProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	//	フォーカスセルが新規列車位置にあるときは、
	//	「新規列車のプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdXColSpec aXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
	if ( aXColSpec.getColumnType() == CdXColSpec::ColumnType_NewRessya )
	{
		bInsert = true ;
	}

	iRv = execCDlgRessyaProp( bInsert , TRUE ) ;

	//iRv = 
	// 	-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
	//	-	0 ;	//	ダイアログがキャンセルで終了したため、@n
	//				変更は発生しませんでした。
	//	-	-1 ;	//	X列番号が不正です。

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		iRv = execCDlgRessyaProp( bInsert , FALSE ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
OnJikokuhyouRessyaInsert_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_NewItem , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		//	列車の挿入の場合は、空列車(列車種別Index=0)ではなく、
		//	NULL列車を挿入します。
		//	Command 内の列車を置き換えます。
		{
			Mu<CentDedRessya*>* pmuRessya = pCmd->getCaMuiSelect()->getMuPtr() ;
			pmuRessya->get( 0 )->setIsNull( true ) ; 
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
	OnJikokuhyouFocusMoveDown_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( !m_bJikokuhyouFocusMoveRight )
	{
		iRv = 1 ;	//(bQueryEnable=TRUEの場合)この項目はすでに選択されています
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		m_bJikokuhyouFocusMoveRight = false ;
		
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWjkState_Ressyahensyu::
	OnJikokuhyouFocusMoveRight_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( m_bJikokuhyouFocusMoveRight )
	{
		iRv = 1 ;	//(bQueryEnable=TRUEの場合)この項目はすでに選択されています
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		m_bJikokuhyouFocusMoveRight = true ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
	OnJikokuhyouEKikanSaisyouSec_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString strErrorMessage ;
	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	CdYColSpec aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
	if ( iRv >= 0 )
	{
		if ( !( aCdYColSpec.getColumnType() == CdYColSpec::ColumnType_Ekijikoku_Chaku || 
				aCdYColSpec.getColumnType() == CdYColSpec::ColumnType_Ekijikoku_Hatsu ) )
		{
			iRv = -1 ;	//	フォーカスセルの位置が不正です。
		}
	}
	if ( iRv >= 0 )
	{
		if ( !( 0 <= aCdYColSpec.getEkiOrder() 
			&& aCdYColSpec.getEkiOrder() <  pCentDedRessyaCont->getEkiCount() - 1 ) )
		{
			iRv = -2 ;	//	フォーカスセルが終着駅にある場合は実行できません。
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		int iEkikanSaisyouSecRessyaIndex = -1 ;

		pCentDedRessyaCont->findEkikanSaisyouSec( 
			aCdYColSpec.getEkiOrder() , &iEkikanSaisyouSecRessyaIndex ) ;
		
		if ( iEkikanSaisyouSecRessyaIndex >= 0 )
		{
			CdXColSpecCont aXColSpecCont 
				= getCWndDcdGrid()->createXColSpecCont() ;
			CDcdGridCell* pcellCurrent 
				= getCWndDcdGrid()->getCFocus()->getFocusCell() ;
			int iXColumnNumberNew = aXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Ressya ,
					iEkikanSaisyouSecRessyaIndex ) ) ;
			int iYColumnNumberNew = getCWndDcdGrid()->getCXDcdGrid()
				->getYColumnNumberOfCell( pcellCurrent );
			
			CDcdGridCell* pcellNew 
				= getCWndDcdGrid()->getCXDcdGrid()->getCell( 
					iXColumnNumberNew , 
					iYColumnNumberNew ) ; 
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNew ) ;
		}
		else	
		{
			const CentDedRosen* pCentDedRosen = getCDiagramEditDoc()
				->getCDedRosenFileData()->getCentDedRosen() ;
			const Mu<CentDedEkiCont::CdDedEki>* pCentDedEkiCont 
				= pCentDedRosen->getCentDedEkiCont()
					->getMuPtr( getRessyahoukou() ) ;
			CString	strFmt ;
			strFmt.LoadString( IDS_ERR_EkikanSaisyouSecIsNone ) ;
			CString strEkimei0 = pCentDedEkiCont->get( 
				aCdYColSpec.getEkiOrder() ).getEkimei().c_str() ;
			CString strEkimei1 = pCentDedEkiCont->get( 
				aCdYColSpec.getEkiOrder() + 1 ).getEkimei().c_str() ;
			CString aStr ;
			aStr.Format( strFmt , strEkimei0 , strEkimei1 ) ;
			
			strErrorMessage = aStr ;
			iRv = -21 ;	//	駅間最小所要秒数列車が決定できません。
						//	時刻が%s駅と%s駅の両方に設定された列車が１本も
						//	ありません。"
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	フォーカスセルの位置が不正です。
			case -2 :	//	フォーカスセルが終着駅にある場合は、
						//	この機能は実行できません
			case -21 :	//	駅間最小所要秒数列車が決定できません。
				break ;
			default:
				strErrorMessage.Format( _T( "Error=%d" ) , iRv ) ;
				break ;
			}
			if ( strErrorMessage.GetLength() > 0 )
			{
				getCWndDcdGrid()->MessageBox( strErrorMessage , NULL , 
					MB_OK | MB_ICONEXCLAMATION ) ;
			}
		}
		// ****************************************************************
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
	OnJikokuhyouSort_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	CdYColSpec aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	bool bRessyasyubetsuSort = false ;
	CdDedJikokuOrder aJikokuOrder  ;
	bool bBikouSort = false ;
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_All , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		if ( 
			aCdYColSpec.getColumnType() == 
				CdYColSpec::ColumnType_Ressyabangou || 
			aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Ressyasyubetsu || 
			aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Ressyamei || 
			aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Gousuu || 
			aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Gou )
		{
			bRessyasyubetsuSort = true ;
		}
		else if ( aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Bikou )
 		{
			//	フォーカスセルが備考列にある場合は、備考でソート
			bBikouSort = true ;
		}
		else if ( aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Ekijikoku_Chaku )
		{
			aJikokuOrder.setEkiOrder( aCdYColSpec.getEkiOrder() , CdDedJikokuOrder::EkiJikokuItem_Chaku ) ;
		}
		else if ( aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Ekijikoku_Hatsu )
		{
			aJikokuOrder.setEkiOrder( aCdYColSpec.getEkiOrder() , CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ;
		}
		else
		{
			iRv = -1 ;	//	フォーカスセルの位置が不正です。
		}
	}
	//bRessyasyubetsuSort = 列車種別でソートする場合はtrue ;
	//iJikokuOrder = 指定のセルに対応する『時刻Order』
	//bBikouSort = 備考でソートする場合はtrue ;

	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		CWaitCursor	aCursor ;	

		// --------------------------------
		//	対象列車を取得し、ソート用のコンテナに移動
		// --------------------------------
		CentDedRessyaCont aCentDedRessyaCont( getCentDedRessyaCont()->createEmptyCont() ) ;
		CaMui<CentDedRessya> aCaMui( &aCentDedRessyaCont ) ;
		aCaMui.insert( pCmd->getCaMuiSelect() ) ;


		// --------------------------------
		//	対象列車をソート
		// --------------------------------
		if ( bRessyasyubetsuSort )
		{
			//	列車種別でソート
			CDedRessyaSoater_Ressyasyubetsu	aSoater ;
			aSoater.sort( &aCentDedRessyaCont , NULL ) ;
		}
		else if ( bBikouSort )
		{
			//	備考でソート
			CDedRessyaSoater_Bikou	aSoater ;
			aSoater.sort( &aCentDedRessyaCont , NULL ) ;

		}
		else
		{
			if ( getCWndDcdGrid()->getEkijikokuSort() 
				== CWndJikokuhyou::EEkijikokuSort_Ekiatsukai )
			{
				//	駅扱ソート

				//	起点時刻
				CdDedJikoku jikokuKitenJikoku = getCDiagramEditDoc()
					->getCDedRosenFileData()->getCentDedRosen()
					->getKitenJikoku() ;

				//	駅時刻でソート
				CDedRessyaSoater_Ekiatsukai	aSoater( 
					aJikokuOrder ,
					jikokuKitenJikoku ) ;

				aSoater.sort( &aCentDedRessyaCont , NULL ) ;

			}
			else if ( getCWndDcdGrid()->getEkijikokuSort() 
				== CWndJikokuhyou::EEkijikokuSort_Transfer )
			{
				//	乗継ソート

				//	進捗ダイアログの作成
				CWnd* pWndToDisable = AfxGetMainWnd() ;
				pWndToDisable->EnableWindow( FALSE ) ;

				CDlgProgress	aDlg ;
				aDlg.Create( pWndToDisable ) ;
				aDlg.ShowWindow( SW_SHOW ) ;
				aDlg.CenterWindow() ;

				//	ソートオブジェクトを生成
				CDedRessyaSoater_Transfer	aRessyaContTransferSort( 
					getCDiagramEditDoc()->getCDedRosenFileData()
						->getCentDedRosen() , 
					getCentDedDia() , 
					aJikokuOrder ) ;
				aRessyaContTransferSort.validate() ;

				//	乗継ソート
				aRessyaContTransferSort.sort(
					&aCentDedRessyaCont ,
					&aDlg ) ;

				pWndToDisable->EnableWindow( TRUE ) ;
				aDlg.DestroyWindow() ;
			}
		}
		// --------------------------------
		//	ソート用のコンテナの内容をコマンドオブジェクトに
		//	書き戻す
		// --------------------------------
		{
			for ( int i = 0 ; i < pCmd->getCaMuiSelect()->size() ; i ++ )
			{
				pCmd->getCaMuiSelect()->set( aCentDedRessyaCont.get( i ) , i ) ;
			}
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
	}
	return iRv ;
}

int CWjkState_Ressyahensyu::
OnJikokuhyouUnify_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_All , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		CWaitCursor	aCursor ;	
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		{
			//	進捗ダイアログの作成
			CWnd* pWndToDisable = AfxGetMainWnd() ;
			pWndToDisable->EnableWindow( FALSE ) ;
			CDlgProgress	aDlg ;
			aDlg.Create( pWndToDisable ) ;
			aDlg.ShowWindow( SW_SHOW ) ;
			aDlg.CenterWindow() ;

			//	編集操作を実行
			{
				Mui<CentDedRessya>* muCentDedRessya = 
					pCmd->getCaMuiSelect() ;
				entDed::CRessyaContUnifier	aUnifier ;
				aUnifier.unify( 
					muCentDedRessya ,
					&aDlg ) ;
			}

			//	進捗ダイアログを閉じる
			pWndToDisable->EnableWindow( TRUE ) ;
			aDlg.DestroyWindow() ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
	}
	return iRv ;
}



// --------------------------------

int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	//	フォーカスセルが新規列車位置にあるときは、
	//	「新規列車のプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdXColSpec aXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
	if ( aXColSpec.getColumnType() == CdXColSpec::ColumnType_NewRessya )
	{
		bInsert = true ;
	}	
	iRv = execJikokuhyouPropDlg( bInsert , TRUE ) ;

	//iRv = 
	//	-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
	//	-	0 ;	//	ダイアログがキャンセルで終了したため、
	//			//	変更は発生しませんでした。
	//	-	-1 ;	//	X列番号が不正です。
	//	-	-2 ;	//	Y列番号が不正です。

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		iRv = execJikokuhyouPropDlg( bInsert , FALSE ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}

	return iRv ;
}

int CWjkState_Ressyahensyu::
	OnJikokuhyouJikokuSakujo_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			//	フォーカスのある駅の駅時刻を『停車』に変更し、
			//	フォーカスのある時刻をNULL時刻にします。
			//
			//	これに伴って、着・発ともNULL時刻になると、駅扱は Ekiatsukai_None 
			//	になります。
			CentDedEkiJikoku aCentDedEkiJikoku =
				pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;

			aCentDedEkiJikoku.setEkiatsukai( 
				CentDedEkiJikoku::Ekiatsukai_Teisya )	 ;
			if ( aCdYColSpec.getColumnType() == CdYColSpec::ColumnType_Ekijikoku_Chaku )
			{	//	着時刻の消去
				aCentDedEkiJikoku.setChakujikoku( CdDedJikoku() ) ;
			}
			else
			{	//	発時刻の消去
				aCentDedEkiJikoku.setHatsujikoku( CdDedJikoku() ) ;
			}
			//	これに伴って、着・発ともNULL時刻になると、駅扱は Ekiatsukai_None 
			//	になります。
			if ( aCentDedEkiJikoku.getChakujikoku().isNull() && 
				aCentDedEkiJikoku.getHatsujikoku().isNull() )
			{
				aCentDedEkiJikoku.setEkiatsukai( 
					CentDedEkiJikoku::Ekiatsukai_None )	 ;
			}
			pCentDedRessya->setCentDedEkiJikoku( aCdYColSpec.getEkiOrder() , aCentDedEkiJikoku ) ;

		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		//	着発表示で、着にフォーカスがある場合、
		//	発に移動します。
		{
			moveFocusCellToNext( false ) ;
		}
	}
	return iRv ;

}



int CWjkState_Ressyahensyu
	::OnJikokuhyouTsuuka_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			CentDedEkiJikoku aCentDedEkiJikoku =
				pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;
			aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Tsuuka ) ;

			//	駅時刻もNULLにする
			//	このほうが便利
			aCentDedEkiJikoku.setChakujikoku( CdDedJikoku() ) ;
			aCentDedEkiJikoku.setHatsujikoku( CdDedJikoku() ) ;

			pCentDedRessya->setCentDedEkiJikoku( aCdYColSpec.getEkiOrder() , aCentDedEkiJikoku ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
	}
	return iRv ;

}



int CWjkState_Ressyahensyu::
	OnJikokuhyouTsuukateisya_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;
			CentDedEkiJikoku aCentDedEkiJikoku =
					pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;
			
			if ( aCentDedEkiJikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka )
			{
				//フォーカスセルの位置が『通過』ならば『停車』に変更します。駅時刻は変更しません。
				aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Teisya ) ;
			}
			else
			{
				//フォーカスセルの位置の『駅時刻』が『停車』『運行なし』『経由なし』なら、
				//『通過』に変更します。駅時刻は変更しません。
				aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Tsuuka ) ;
			}

			pCentDedRessya->setCentDedEkiJikoku( aCdYColSpec.getEkiOrder() , aCentDedEkiJikoku ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
	OnJikokuhyouKeiyunasi_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;
			CentDedEkiJikoku aCentDedEkiJikoku =
					pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;

			aCentDedEkiJikoku.setEkiatsukai( 
				CentDedEkiJikoku::Ekiatsukai_Keiyunasi ) ;

			pCentDedRessya->setCentDedEkiJikoku( aCdYColSpec.getEkiOrder() , aCentDedEkiJikoku ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Ressyahensyu::
	OnJikokuhyouSihatsu_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			//	コンテナの列車を編集
			pCentDedRessya->setSihatsuEki(  aCdYColSpec.getEkiOrder() ) ;

		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Ressyahensyu::
	OnJikokuhyouSyuuchaku_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			//	コンテナの列車を編集
			pCentDedRessya->setSyuuchakuEki(  aCdYColSpec.getEkiOrder() ) ;

		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}



int CWjkState_Ressyahensyu::
	OnJikokuhyouDirect_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	const CentDedRessyaCont* pCentDedRessyaCont = NULL ;
	const CentDedRessya* pCentDedRessya = NULL ;
	int idxRessyaSyuuchaku = -1 ;
	if ( iRv >= 0 )
	{
		pCentDedRessyaCont = getCentDedRessyaCont() ;
		CdXColSpec aCdXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
		idxRessyaSyuuchaku = aCdXColSpec.getRessyaIndex() ;
		pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( aCdXColSpec.getRessyaIndex() ) ;
	}

	//○途中駅止まり列車を取得　　　　　　CentDedRessyaCont
	//◇[フォーカスセルの位置が、その列車の終着駅Orderより上]→エラー
	if ( iRv >= 0 )
	{
		if ( aCdYColSpec.getEkiOrder() < pCentDedRessya->getSyuuchakuEki() )
		{
			iRv = -13;	//	セルの位置が、終着駅より上
		}
	}
	//idxRessyaSyuuchaku = フォーカスのある位置の列車
	//pCentDedRessya = フォーカスセルのある位置の列車


	//○対応する途中駅始発列車を検索      CentDedRessyaCont
	//◇[対応する列車がない]→処理終了
	int idxRessyaSihatsu = -1 ;
	if ( iRv >= 0 )
	{
		idxRessyaSihatsu = pCentDedRessyaCont->findTrainToDirect(
			idxRessyaSyuuchaku  , 
			aCdYColSpec.getEkiOrder() ) ;
		if ( idxRessyaSihatsu < 0 )
		{
			iRv = -14 ;	//	対応する始発列車が見つかりません。
		}
	}
	//idxRessyaSihatsu = 対応する始発列車のインデクス

	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトを生成
		// --------------------------------
		if ( !getCWndDcdGrid()->createCmd( idxRessyaSyuuchaku , idxRessyaSihatsu - idxRessyaSyuuchaku + 1  , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
		// --------------------------------
		//	コマンドオブジェクト内の列車を編集
		// --------------------------------
		if ( iRv >= 0 )
		{
			CentDedRessya aRessyaSyuuchaku = pCmd->getCaMuiSelect()->get( 0 ) ; 
			CentDedRessya aCentDedRessyaToDirect = pCmd->getCaMuiSelect()->get( INT_MAX ) ;
			int iResult = aRessyaSyuuchaku.direct( aCentDedRessyaToDirect ) ;
			//iResult = 
			//-	-1 ;	//	この列車には駅時刻が指定されていません。
			//-	-2 ;	//	始発列車には駅時刻が指定されていません。
			//-	-3 ;	//	aRessyaSihatsu との直通化はできません。\n
			//	//aRessyaSihatsu の始発駅は、	this の終着駅と同じか、
			//	//	それ以降でなくてはなりません。

			if ( iResult < 0 )
			{
				iRv = iResult  ;
			}
			else
			{
				pCmd->getCaMuiSelect()->set( aRessyaSyuuchaku , 0 ); 
				pCmd->getCaMuiSelect()->erase( INT_MAX , 1 ); 
			}
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}

		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		CString strErrorMsg ;
		if ( iRv < 0 )
		{
			//switch( iRv )
			//{
			//default:
				strErrorMsg.Format( _T( "Error(%d)" ) , iRv ) ;	
			//	break ;
			//}
			if ( strErrorMsg.IsEmpty() )
			{
				getCWndDcdGrid()->MessageBox( 
					strErrorMsg , NULL , MB_ICONSTOP ) ;
			}
		}

		// ****************************************************************
	}
	return iRv ;

}

int CWjkState_Ressyahensyu::
	OnJikokuhyouUndirect_Process( BOOL bQueryEnable )

{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	const CentDedRessyaCont* pCentDedRessyaCont = NULL ;
	const CentDedRessya* pCentDedRessya = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedRessyaCont = getCentDedRessyaCont() ;
		CdXColSpec aCdXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
		pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( aCdXColSpec.getRessyaIndex() ) ;
	}

	//●メニュー[駅時刻]-[分断]
	//↓
	//○分断する列車を取得	CentDedRessyaCont
	//◇[!(その列車の始発駅Order<フォーカスセルの位置<終着駅Order)]→エラー
	if ( iRv >= 0 )
	{
		if ( !( pCentDedRessya->getSihatsuEki() < aCdYColSpec.getEkiOrder() 
			&& aCdYColSpec.getEkiOrder() < pCentDedRessya->getSyuuchakuEki()
		) )
		{
			iRv = -21 ;	//	その列車の始発駅・終着駅では分断はできません。
		}
	}
	//◇[駅時刻に着時刻も発時刻も指定されていない駅では、この機能は使用できません]→エラー
	if ( iRv >= 0 )
	{
		CentDedEkiJikoku	aCentDedEkiJikoku 
			= pCentDedRessya->getCentDedEkiJikoku( 
				aCdYColSpec.getEkiOrder() ) ;
		if ( aCentDedEkiJikoku.getChakujikoku().isNull() && 
			aCentDedEkiJikoku.getHatsujikoku().isNull() )
		{
			iRv = -22 ;	//	駅時刻に着時刻も発時刻も指定されていない駅では、この機能は使用できません
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクト内の列車を編集
		// --------------------------------
		CentDedRessya aRessyaSyuuchaku( getCentDedRessyaCont()->createNullRessya() ) ;
		CentDedRessya aRessyaSihatsu( getCentDedRessyaCont()->createNullRessya() ) ;
		if ( iRv >= 0 )
		{
			CentDedRessya aRessya = pCmd->getCaMuiSelect()->get( 0 ) ; 

			int iResult = pCentDedRessya->undirect( 
				aCdYColSpec.getEkiOrder() , 
				&aRessyaSyuuchaku, 
				&aRessyaSihatsu ) ;
			//iResult = 
			//	-	-1 ;	//	指定の駅Orderでは、分断はできません
			if ( iResult < 0 )
			{
				iRv = iResult - 30 ;
			}
			else
			{
				pCmd->getCaMuiSelect()->set( aRessyaSyuuchaku , 0 ) ;
				pCmd->getCaMuiSelect()->insert( aRessyaSihatsu , 1 ) ; 
			}
			//iRv = 
			//	-	-31 ;	//	指定の駅Orderでは、分断はできません
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		if ( iRv >= 0 )
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		if ( iRv >= 0 ){
			moveFocusCellToNext( true ) ;
		}

		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		CString strErrorMsg ;
		if ( iRv < 0 )
		{
			//switch( iRv )
			//{
			//default:
				strErrorMsg.Format( _T( "Error(%d)" ) , iRv ) ;	
			//	break ;
			//}
			if ( strErrorMsg.IsEmpty() )
			{
				getCWndDcdGrid()->MessageBox( 
					strErrorMsg , NULL , MB_ICONSTOP ) ;
			}
		}
	}
	return iRv ;

}

int CWjkState_Ressyahensyu::
	OnJikokuhyouRenzoku_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	CWjkState* pCState = 
		getCWndDcdGrid()->getStateMachine()->getCStateContGet()->get( 
			CWndJikokuhyou::StateIdx_Renzoku ) ;
	int iResult = pCState->canEnter() ;
	if ( iResult < 0 )
	{
		iRv = -1 ;	//	現在、このコマンドは選択できません
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
			CWndJikokuhyou::StateIdx_Renzoku ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;
}



int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuInsert_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	if ( iRv >= 0 ){
		if ( !( 0 <= aCdYColSpec.getEkiOrder() && 
			aCdYColSpec.getEkiOrder() 
			< getCentDedRessyaCont()->getEkiCount() - 1 ) )
		{
			iRv = -2 ;	//	一番下の駅では、この操作はできません。
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;

		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			int iEkiOrderCurr = 0 ;
			for ( iEkiOrderCurr = pCentDedRessyaCont->getEkiCount() - 1 ;
					iEkiOrderCurr > aCdYColSpec.getEkiOrder() ;
					iEkiOrderCurr -- ){
				CentDedEkiJikoku aCentDedEkiJikoku = 
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrderCurr - 1 ) ;
				pCentDedRessya->setCentDedEkiJikoku( iEkiOrderCurr , 
					aCentDedEkiJikoku ) ;
			}
			CentDedEkiJikoku aCentDedEkiJikoku ;
			pCentDedRessya->setCentDedEkiJikoku( iEkiOrderCurr , 
				aCentDedEkiJikoku ) ;

		}	
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;


}



int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuErase_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			int iEkiOrderCurr ;
			for ( iEkiOrderCurr = aCdYColSpec.getEkiOrder() ;
					iEkiOrderCurr < pCentDedRessyaCont->getEkiCount() - 1 ;
					iEkiOrderCurr ++ ){
				CentDedEkiJikoku aCentDedEkiJikoku = 
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrderCurr + 1 ) ;
				pCentDedRessya->setCentDedEkiJikoku( iEkiOrderCurr , 
					aCentDedEkiJikoku ) ;
			}
			CentDedEkiJikoku aCentDedEkiJikoku ;
			pCentDedRessya->setCentDedEkiJikoku( iEkiOrderCurr , 
				aCentDedEkiJikoku ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;

}
// --------------------------------
int CWjkState_Ressyahensyu::
OnJikokuhyouModifyEkijikokuCmd_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
		}
	}
	//aCdJikokuOrder = 指定のセルに対応する『時刻Order』
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		bool bRepeat = false ;
		do{
			bRepeat = false ;
			// --------------------------------
			//	ダイアログを起動
			// --------------------------------
			CDlgModifyEkijikokuOperation2 aCDlgModifyEkijikokuOperation2( 
				getCWndDcdGrid()->getEkijikokuModifyOperation2() , 
				getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->
					getCentDedEkiCont()->getMuPtr( getCWndDcdGrid()->getRessyahoukou() ) , 
				getCWndDcdGrid() ) ;
			if ( aCDlgModifyEkijikokuOperation2.DoModal() == IDOK )
			{
				getCWndDcdGrid()->setEkijikokuModifyOperation2(
					aCDlgModifyEkijikokuOperation2.getCentDedRessya_EkijikokuModifyOperation2() ) ;

				// --------------------------------
				//	駅時刻変更の動作を実行
				// --------------------------------
				int iResult = getCWndDcdGrid()->execCdModifyEkijikokuCmd(
					pCmd , 
					aCdJikokuOrder ) ;
				if  ( iResult < 0 )
				{
					//	エラーが発生した場合は、ダイアログを再度開きます。
					bRepeat = true ;
				}
				else
				{
					// --------------------------------
					//	フォーカスセルを次へ移します。
					// --------------------------------
					moveFocusCellToNext( true ) ;
				}
			}
		}	while ( bRepeat ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;




}


int CWjkState_Ressyahensyu::OnJikokuhyouModifyEkijikokuCmdRepeat_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
		}
	}
	//aCdJikokuOrder = 指定のセルに対応する『時刻Order』
	if ( iRv >= 0 )
	{
		if ( getCWndDcdGrid()->getEkijikokuModifyOperation2().isNull() )
		{
			iRv = -1 ;	//	前回の「駅時刻変更」が無効です。
		}
	}

	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		{
				// --------------------------------
				//	駅時刻変更の動作を実行
				// --------------------------------
				int iResult = getCWndDcdGrid()->execCdModifyEkijikokuCmd(
					pCmd , 
					aCdJikokuOrder ) ;
				if  ( iResult >= 0 )
				{
					//	フォーカスセルを次へ移します。
					moveFocusCellToNext( true ) ;
				}
		}
	}
	return iRv ; 

}

// --------------------------------
int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuDec_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;
		}
	}
	//aCdJikokuOrder = 指定のセルに対応する『時刻Order』
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;	
			
			pCentDedRessya->modifyRessyaJikoku( CdDedJikan(  -1 * 60 ) , 
				aCdJikokuOrder ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		{
			moveFocusCellToNext( false ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;
			

}

int CWjkState_Ressyahensyu::
OnJikokuhyouEkijikokuDecNoMove_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;
		}
	}
	//aCdJikokuOrder = 指定のセルに対応する『時刻Order』
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;	
			
			pCentDedRessya->modifyRessyaJikoku( CdDedJikan(  -1 * 60 ) , 
				aCdJikokuOrder ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuNext_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	CDcdGridCell*	pCDcdGridCell = NULL ;
	if ( iRv >= 0 )
	{
		pCDcdGridCell = getCWndDcdGrid()->getCFocus()->getFocusCell() ;
		if ( pCDcdGridCell == NULL )
		{
			iRv = -11  ;	//	セルの場所が不正
		}
	}
	//pCDcdGridCell = 編集中のセル
	
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		{
			moveFocusCellToNext( false ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;
}



int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuPrev_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	CDcdGridCell*	pCDcdGridCell = NULL ;
	if ( iRv >= 0 )
	{
		pCDcdGridCell = getCWndDcdGrid()->getCFocus()->getFocusCell() ;
		if ( pCDcdGridCell == NULL )
		{
			iRv = -11  ;	//	セルの場所が不正
		}
	}
	//pCDcdGridCell = 編集中のセル
	
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		{
			moveFocusCellToPrev( false ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;
}

int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuInc_Process( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;
		}
	}
	//aCdJikokuOrder = 指定のセルに対応する『時刻Order』
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;		
	
			pCentDedRessya->modifyRessyaJikoku( CdDedJikan(  +1 * 60 ) , 
				aCdJikokuOrder ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		{
			moveFocusCellToNext( false ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;
}



int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuIncNoMove_Process( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;
		}
	}
	//aCdJikokuOrder = 指定のセルに対応する『時刻Order』
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;		
			
			pCentDedRessya->modifyRessyaJikoku( CdDedJikan(  +1 * 60 ) , 
				aCdJikokuOrder ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;
			
			

}


		// ********************************
		//@name	CWndDcdGrid
		// ********************************
void CWjkState_Ressyahensyu::OnSetFocusCell( 
		CDcdGridCell* pCDcdGridCell ) 
{
}

void CWjkState_Ressyahensyu::OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) 
{
	super::OnChangeSelectCell( iXColumnNumber , iYColumnNumber , bIsSelected );
}



} } // namespace WndJikokuhyou namespace ViewJikokuhyou
