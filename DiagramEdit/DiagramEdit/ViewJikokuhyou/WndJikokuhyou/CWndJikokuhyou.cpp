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
//	CWndJikokuhyou.cpp
//	$Id: CWndJikokuhyou.cpp 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "NsOu\OuNew.h"
#include "NsOu\dynamic_castOu.h"
#include "str\CsvDocument\CConvCsvDocument.h"
#include "str\vectorToFile.h"
#include "logmsg\LogMsg.h"

#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CDcdLine.h"
#include "DcDraw\CDcdFillrectRop.h"
#include "DcDraw\CDcdTextbox.h"
#include "DcDraw\CConverter_WinGdi.h"

#include "MfcUtil\MfcUtil.h"

#include "..\JikokuhyouColSpec\JikokuhyouColSpec.h"
#include "..\..\DedRosenFileData\EditCmd\CRfEditCmd_Rosen.h"
#include "..\..\resource.h"
#include "..\..\entDed\CentDedRosen.h"
#include "..\..\DiagramEdit.h"
#include "..\..\ViewJikokuhyou\CDlgJikokuhyouViewProp.h"
#include "..\..\ViewDiagram\CDedDiagramView.h"
#include "..\CDlgOuJikokuhyouCsvExport.h"
#include "CCellBuilder.h"
#include "CWndJikokuhyou.h"
#include "CWjkState_Ressyahensyu.h"
#include "CWjkState_Renzoku.h"
#include "CWndJikokuhyou.h"

#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{ namespace WndJikokuhyou{
using namespace std ;
using namespace OuMfc::MfcUtil ;
using namespace OuLib::Str;
// ****************************************************************
//	CWndJikokuhyou
// ****************************************************************
// --------------------------------
//@name 下請関数
// --------------------------------
CJikokuhyouDoc*	CWndJikokuhyou::GetDocument() 
{
	CView* pCView = (CView*)GetParent() ;
	return (CJikokuhyouDoc*)pCView->GetDocument() ;
};

ERessyahoukou CWndJikokuhyou::getRessyahoukou() 
{
	return GetDocument()->getRessyahoukou() ;
};


const CentDedDia*	CWndJikokuhyou::getCentDedDia()
{
	const CentDedRosen*	pCentDedRosen = 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	int iDiaIndex = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( 
			GetDocument()->getDiaName() ) ;
	if ( iDiaIndex < 0 ){
		return ( NULL ) ;
	}
	const CentDedDia* pCentDedDia = pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( iDiaIndex ) ;
	return ( pCentDedDia ) ;
};

const CentDedRessyaCont*	CWndJikokuhyou::getCentDedRessyaCont()
{
	const CentDedDia* pCentDedDia = getCentDedDia() ;
	if ( pCentDedDia == NULL ){
		return ( NULL ) ;
	}
	return ( pCentDedDia->getCentDedRessyaCont( getRessyahoukou() ) ) ;
};	


	// --------------------------------
	//@name updateUI...() ・セルの更新
	// --------------------------------

void  CWndJikokuhyou::updateUIAll() 
{
	//	この変数が true のときは、
	//	「ビューがアクティブな状態での updateUIAll() 」
	//	まで、あらゆる更新操作は行われません。
	if ( m_bUpdate_All_Requested )
	{
		return ;
	}
	// --------------------------------

	//	全更新
	CView *pView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	if ( pView != GetParent() )
	{
		//	全更新を必要とする場合で、
		//	このビューがアクティブでない場合は
		//	全更新を保留します。
		LogMsg( "CWndJikokuhyou::OnUpdate_All() " 
			"m_bUpdate_All_Requested=true" ) ;
		m_bUpdate_All_Requested = true ;
	}
	else
	{
		//	全更新を必要とする場合で、
		//	このビューがアクティブの場合は、
		//	全更新を行います。
		CWaitCursor	aCWaitCursor ;


		// --------------------------------
		//	セルを更新
		// --------------------------------
		//	コマンドオブジェクト実行によるセル移動でセル選択にならないように、
		//	セル選択機能を一時的に中止します。
		{
			clearSelect() ;
			CPropStack aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		}


		//	セルを更新
		ViewJikokuhyou::WndJikokuhyou::CCellBuilder	aCellBuilder(
			getCDiagramEditDoc()->getCDedRosenFileData() ,
			getCentDedRessyaCont() , 
			m_bDisplayTsuukaEkiJikoku ,
			m_bDisplayAllEkiJikoku );
		aCellBuilder.update( 
			this ) ;

		InvalidateGrid() ;

		m_bUpdate_All_Requested = false ;
	}
}
void CWndJikokuhyou::updateUISetAllRessya() 
{
	//	この変数が true のときは、
	//	「ビューがアクティブな状態での OnUpdate_All() 」
	//	まで、あらゆる更新操作は行われません。
	if ( m_bUpdate_All_Requested )
	{
		return ;
	}
	// --------------------------------
	//	セルを更新
	// --------------------------------
	{
		//	コマンドオブジェクト実行によるセル移動でセル選択にならないように、
		//	セル選択を解除し、セル選択機能も一時的に中止します。
		{
			clearSelect() ;
			CPropStack aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		}

		//	セルを更新
		ViewJikokuhyou::WndJikokuhyou::CCellBuilder	aCellBuilder(
			getCDiagramEditDoc()->getCDedRosenFileData() ,
			getCentDedRessyaCont() , 
			m_bDisplayTsuukaEkiJikoku ,
			m_bDisplayAllEkiJikoku );
		aCellBuilder.updateAllRessya(
			this ) ;
	}
}

void CWndJikokuhyou::updateUI_ReplaceRessya( 
		int iDstRessyaIndex , 
		int iDstDelCount , 
		int iInsertCount ) 

{
	//	この変数が true のときは、
	//	「ビューがアクティブな状態での OnUpdate_All() 」
	//	まで、あらゆる更新操作は行われません。
	if ( m_bUpdate_All_Requested )
	{
		return ;
	}
	// --------------------------------
	//	セルを更新
	// --------------------------------
	{
		//	列の増減を伴うコマンドを実行する場合は、
		//	コマンドオブジェクト実行によるセル移動でセル選択にならないように、
		//	セル選択を解除し、セル選択機能も一時的に中止します。
		if ( iDstDelCount != iInsertCount )
		{
			clearSelect() ;
			CPropStack aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		}

		//	セルを更新
		ViewJikokuhyou::WndJikokuhyou::CCellBuilder	aCellBuilder(
			getCDiagramEditDoc()->getCDedRosenFileData() ,
			getCentDedRessyaCont() , 
			m_bDisplayTsuukaEkiJikoku ,
			m_bDisplayAllEkiJikoku );
		aCellBuilder.replaceRessya(
			iDstRessyaIndex , 
			iDstDelCount , 
			iInsertCount , 
			this ) ;
	}
}



	// --------------------------------
	//@name CWndJikokuhyou-MFCコマンドハンドラ下請関数
	// --------------------------------
int CWndJikokuhyou::OnFileExportJikokuhyoucsv_Process( 
	BOOL bQueryEnable )  
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		CJikokuhyouDoc* pCJikokuhyouDoc = (CJikokuhyouDoc*)GetDocument() ;

		const CDedRosenFileData* pCDedRosenFileData = 
			getCDiagramEditDoc()->getCDedRosenFileData() ;

		CDlgOuJikokuhyouCsvExport	aDlg( 
			pCDedRosenFileData->getCentDedRosen() , 
			pCJikokuhyouDoc->getDiaIndex() , 
			pCJikokuhyouDoc->getRessyahoukou() , 
			this ) ;
		aDlg.DoModal() ;
	
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnFileImportJikokuhyoucsv_Process( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	CString	strError ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	const Mu<const CentDedRessya*>* pCentDedRessyaCont 
		= getCentDedRessyaCont()->getMuPtr() ;
	CDcdGridCell*	pCDcdGridCell = NULL ;
	if ( iRv >= 0 ){
		 pCDcdGridCell = getCFocus()->getFocusCell() ;
		if ( pCDcdGridCell == NULL ){
			iRv = -1  ;	//	セルの場所が不正
		}
	}
	//pCDcdGridCell = 編集中のセル
	int iRessyaIdx = -1 ;
	if ( iRv >= 0 ){
		iRessyaIdx = getXColSpecOfFocus().getRessyaIndex() ;
		if ( !( 0 <= iRessyaIdx && iRessyaIdx < pCentDedRessyaCont->size() ) ){
			//	セルの位置が、特定の列車の特定の時刻の場所ではない
			//	エラーにはしません。
			iRessyaIdx = pCentDedRessyaCont->size() ;
		}
	}
	//iRessyaIdx = 列車Index
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		CentDedRosen aCentDedRosen = *getCDiagramEditDoc()
			->getCDedRosenFileData()->getCentDedRosen() ;

		// --------------------------------
		//	入力ファイル名入力値の取得
		// --------------------------------
		CString strCsvFilename ;
		if ( iRv >= 0 )
		{
			CFileDialog aDlg( 
				TRUE , 
				_T( "csv" ) , 
				NULL , 
				OFN_HIDEREADONLY , 
				getCDiagramEditApp()->getCFileDialogFilterCsv(), 
				this );
			if ( aDlg.DoModal() != IDOK )
			{
				iRv = -2 ;	//	Cancelされました。
			}
			else
			{
				strCsvFilename = aDlg.GetPathName() ;
			}
		}
		//strCsvFilename = 指定されたCSVファイル名
		// --------------------------------
		//	CSVファイルの読み出し
		// --------------------------------
		CWaitCursor aCursor ;
		CdCsvDocument aCdCsvDocument ;
		if ( iRv >= 0 )
		{
			string strCsvDocument ;
			int iResult = stringFromFile( 
				&strCsvDocument , 
				(LPCSTR)strCsvFilename ) ; 
			if ( iResult < 0 )
			{
				strError.Format( IDS_ERR_FILENOTFOUND , 
					(LPCTSTR)strCsvFilename ) ;
				iRv = -11 ;	//	ファイルが見つかりません。
			}
			else
			{
				CConvCsvDocument	aConv ;
				int iResult = aConv.decode( &aCdCsvDocument , strCsvDocument ) ;
				if ( iResult < 0 )
				{
					strError.Format( IDS_ERR_FILEFORMAT , 
						(LPCTSTR)strCsvFilename ) ;
					iRv = -12 ;	//	CSVの解釈に失敗しました。
				}
			}

		}

		if ( iRv >= 0 )
		{
			int iDiaIndex = GetDocument()->getDiaIndex() ;
			ERessyahoukou eRessyahoukou = GetDocument()->getRessyahoukou() ;
			string strErrorInfoString ;		
			CconvJikokuhyouCsv	aConv( 
				getCDiagramEditApp()->createCconvJikokuhyouCsv() ) ;
			int iResult = aConv.decode(
				&aCentDedRosen ,
				iDiaIndex , 
				eRessyahoukou , 
				iRessyaIdx , 
				aCdCsvDocument , 
				&strErrorInfoString ) ;
			//iResult = 
			//	-1 ; // 行が少なすぎます。
			//	-2 ; // 列が少なすぎます。
			//	-3 ; // ファイル形式が認識できません
			//	-4 ; // ファイル形式が認識できません
			//	-11 ; // 駅名が見つかりません。
			//	-21 ; // iDiaIndex が不正です。
			//	-22 ; // iRessyaIndex が不正です。 
			if ( iResult < 0 )
			{
				strError.Format( IDS_ERR_FILEFORMAT , 
					(LPCTSTR)strCsvFilename , iResult ) ;
				strError += _T( "\n" ) ;
				strError += _T( "(" ) ;
				strError += strErrorInfoString.c_str()  ;
				strError += _T( ")" ) ;
				iRv = iResult - 100 ;
				//	-101 ; // 行が少なすぎます。
				//	-102 ; // 列が少なすぎます。
				//	-103 ; // ファイル形式が認識できません
				//	-104 ; // ファイル形式が認識できません
				//	-111 ; // 駅名が見つかりません。
				//	-121 ; // iDiaIndex が不正です。
				//	-122 ; // iRessyaIndex が不正です。 
			}
		}
		//	編集コマンドを実行
		if ( iRv >= 0 )
		{
			Ou<CRfEditCmd> pCmd 
				= OuNew<CRfEditCmd_Rosen>( 
					new CRfEditCmd_Rosen( aCentDedRosen ) );
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}	
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		if ( iRv < 0 )
		{
			if ( !strError.IsEmpty() )
			{
				MessageBox( strError , NULL , MB_ICONSTOP ) ;
			}
		}
		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnJikokuhyouViewProp_Process( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		CDlgJikokuhyouViewProp aDlg( 
			m_jikanPasteIdouryou , 
			m_eEkijikokuSort ,
			this ) ;
		if ( aDlg.DoModal() == IDOK )
		{
			m_jikanPasteIdouryou = aDlg.getPasteIdouryou() ;
			m_jikanPasteIdouryouPrevValue = 0 ;
			m_eEkijikokuSort = aDlg.getEkijikokuSort() ;

			//	EkijikokuSort の設定を、
			//	.ini ファイルに保存
			getCDiagramEditApp()->writeCWndJikokuhyouViewProp( this ) ;

			iRv = 1 ;	//	ダイアログボックスでの入力が適用されました。
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnJikokuhyouDiagramHeIdou_Process( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	const Mu<const CentDedRessya*>* pCentDedRessyaCont = getCentDedRessyaCont()->getMuPtr() ;

	CDcdGridCell*	pCDcdGridCell = NULL ;
	if ( iRv >= 0 ){
		 pCDcdGridCell = getCFocus()->getFocusCell() ;
		if ( pCDcdGridCell == NULL ){
			iRv = -11  ;	//	セルの場所が不正
		}
	}
	//pCDcdGridCell = 編集中のセル
	
	int iRessyaIdx = -1 ;
	const CentDedRessya* pCentDedRessya = NULL ;
	if ( iRv >= 0 ){
		iRessyaIdx = getXColSpecOfFocus().getRessyaIndex() ;

		if ( !( 0 <= iRessyaIdx && iRessyaIdx < pCentDedRessyaCont->size() ) ){
			//	セルの位置が、特定の列車の特定の時刻の場所ではない
			//	エラーにはしません。
		}	else	{
			pCentDedRessya = pCentDedRessyaCont->get( iRessyaIdx ) ;
		}
	}
	//iRessyaIdx = 列車Index
	//pCentDedRessya = 指定のセルに対応する『列車』
	//	対応する列車がない場合はNULL
	
	CdDedJikokuOrder aJikokuOrder;
	if ( iRv >= 0 )
	{
		aJikokuOrder = CdDedJikokuOrderOf( getYColSpecOfFocus() ) ;
	}
	//aJikokuOrder = 指定のセルに対応する『時刻Order』
	//	ないならNULL

	CdDedJikoku	jikokuFocus ;
	if ( iRv >= 0 ){
		if ( pCentDedRessya != NULL ){
			jikokuFocus = pCentDedRessya->getEkiJikoku( aJikokuOrder ) ;
		}
	}
	//jikokuFocus = フォーカスのあるセルの時刻。ないならNULL

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	ダイヤグラムビューを開く
		// --------------------------------
		CDedDiagramView* pCDedDiagramView = NULL ;
		if ( iRv >= 0 ){
			
			const CDedDiagramDoc* pCDedDiagramDoc = NULL ;
			if ( iRv >= 0 ){
				pCDedDiagramDoc = 
					getCDiagramEditApp()->openCDedDiagramDoc( 
						getCentDedDia()  ) ; 
				if ( pCDedDiagramDoc == NULL ){
					iRv = -2 ;	//	ダイヤグラムビューのオープンに失敗しました
				}
			}
			//pCJikokuhyouDoc = ダイヤグラムドキュメント
			//	ビューがアクティブになっています。
			
			if ( iRv >= 0 ){
				POSITION aPOSITION = pCDedDiagramDoc->GetFirstViewPosition() ;
				if ( aPOSITION != NULL ){
					pCDedDiagramView = (CDedDiagramView*)pCDedDiagramDoc->GetNextView( aPOSITION ) ;
				}
				if ( pCDedDiagramView == NULL ){
					iRv = -3 ;	//	ダイヤグラムビューのオープンに失敗しました
				}
			}
		}
		//pCDedDiagramView = ダイヤグラムビュー
		if ( iRv >= 0 ){
			pCDedDiagramView->setZone_Dgr( jikokuFocus , 
				getCentDedRessyaCont()->EkiIndexOfEkiOrder( aJikokuOrder.getEkiOrder() ) , 
				getRessyahoukou() == Ressyahoukou_Nobori ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnVIEWDisplayTsuukaEkiJikoku_Process( 
	BOOL bQueryEnable )  
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( getDisplayTsuukaEkiJikoku() )
	{
		iRv = 1 ;	//(bQueryEnable==TRUEの場合)[全時刻を表示]が有効です。
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		setDisplayTsuukaEkiJikoku( !getDisplayTsuukaEkiJikoku() ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnViewDisplayallekijikoku_Process( 
	BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( getDisplayAllEkiJikoku() )
	{
		iRv = 1 ;	//	(bQueryEnable==TRUEの場合)[全時刻を表示]が有効です。
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		const CentDedRosen*	pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		// --------------------------------
		//	Gridの配置を変更する前の、
		//	フォーカスセルの表示内容を取得
		// --------------------------------
		CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;
		int iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell(
			pCDcdGridCell) ;
		int iXColumnNumber = getCXDcdGrid()->getXColumnNumberOfCell(
			pCDcdGridCell) ;

		CdYColSpecCont aYColumnSpecCont 
			= createYColSpecCont() ;

		CdYColSpec aYColumnSpec = 
			aYColumnSpecCont.ColumnNumberToSpec( iYColumnNumber ) ;
		//aYColumnSpec = フォーカスセルの表示内容。

		// --------------------------------
		//	全時刻表示モードの変更
		// --------------------------------
		setDisplayAllEkiJikoku( !getDisplayAllEkiJikoku() ) ;
		// --------------------------------
		//	フォーカスセルを、Grid配置変更前と同じ表示内容の位置に移動
		// --------------------------------
		//	Grid配置が変わったため、『列番号-表示内容』の対応表を再作成します。
		aYColumnSpecCont = createYColSpecCont() ;

		//	Grid配置前のフォーカスセルの表示内容に対応した
		//	Y列番号を取得
		iYColumnNumber = aYColumnSpecCont.ColumnNumberFromSpec(
			aYColumnSpec , true ) ;

		pCDcdGridCell = getCXDcdGrid()->getCell( 
			iXColumnNumber , iYColumnNumber ) ;
		getCFocus()->setFocusCell( pCDcdGridCell ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

CString CWndJikokuhyou::OnUpdateINDICATOR_PasteZoubun_Process() 
{
	CString	strLs ;
	if ( m_StateMachine.getCurrentStateIdx() == StateIdx_Renzoku  )
	{
		//	連続入力モード
		strLs.LoadString( IDS_INDICATOR_Renzoku ) ;
	}
	else
	{
		//	その他
		strLs.Format( ID_INDICATOR_PasteZoubun , 
			m_jikanPasteIdouryou.getTotalSeconds() / 60 , 
			( m_jikanPasteIdouryouPrevValue.getTotalSeconds() + 
				m_jikanPasteIdouryou.getTotalSeconds() ) / 60 ) ;
	}
	return strLs ;
}



// --------------------------------
//@name 下請関数
// --------------------------------


// ********************************
//@name	CDcdGrid
// ********************************

	// --------------------------------
	//@name 行・列・セルの初期化
	// --------------------------------
void CWndJikokuhyou::OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	pCDcdGridXColumn->getCDcdGridXBorder()->setAutoColumnBorderSize( false ) ;
	pCDcdGridXColumn->setAutoColumnSize( false ) ;

	super::OnCreateXColumn( iXColumnNumber , 
		pCDcdGridXColumn ) ;
}

	
void CWndJikokuhyou::OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
	pCDcdGridYColumn->getCDcdGridYBorder()->setAutoColumnBorderSize( false ) ;
	pCDcdGridYColumn->setAutoColumnSize( false ) ;

	super::OnCreateYColumn( iYColumnNumber , 
			pCDcdGridYColumn ) ;
}

	
// ********************************
//@name	CWndDcdGrid
// ********************************
	// --------------------------------
	//@name	イベント処理のための仮想関数
	// --------------------------------
void CWndJikokuhyou::OnSetFocusCell( CDcdGridCell* pCDcdGridCell ) 
{
	m_StateMachine.getCurrentState()->
		OnSetFocusCell( pCDcdGridCell ) ;

	//	super::OnSetFocusCell( pCDcdGridCell ) ;
}

void CWndJikokuhyou::OnSetXFixafterColumnNumber( int iFixafterColumnNumber ) 
{
	m_StateMachine.getCurrentState()->
		OnSetXFixafterColumnNumber( iFixafterColumnNumber ) ;
	//	super::OnSetXFixafterColumnNumber( iFixafterColumnNumber ) ;
}

void CWndJikokuhyou::OnSetYFixafterColumnNumber( int iFixafterColumnNumber ) 
{
	m_StateMachine.getCurrentState()->
		OnSetYFixafterColumnNumber( iFixafterColumnNumber ) ;
	//	super::OnSetYFixafterColumnNumber( iFixafterColumnNumber ) ;
}

void CWndJikokuhyou::OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) 
{
	m_StateMachine.getCurrentState()->
		OnChangeSelectCell( iXColumnNumber , iYColumnNumber , bIsSelected ) ;
}


// ********************************
//	コンストラクタ
// ********************************
CWndJikokuhyou::CWndJikokuhyou()
	: m_jikanPasteIdouryou( 0 )
	, m_bDisplayTsuukaEkiJikoku( true )
	, m_bDisplayAllEkiJikoku( false ) 
	, m_eEkijikokuSort( EEkijikokuSort_Ekiatsukai )	// 駅扱でのソート
	, m_bModifyEkijikoku( true )
	, m_jikanPasteIdouryouPrevValue( 0 )
	, m_bUpdate_All_Requested( true )
	, m_bReadCWndJikokuhyouDefault( false ) 
{
	//	選択テキストカラーを設定
	{
		Ou<CDcdFillrectRop>	pIfDcDraw = dynamic_castOu<CDcdFillrectRop>(
			getCSelect()->getIfDcDrawSelect() ) ;

		//	選択テキストカラー=黒
		pIfDcDraw->setCdBrushProp( CdColorProp( 0 , 0 , 0 ) ) ;
	}
}
CWndJikokuhyou::~CWndJikokuhyou()
{
}


// ********************************
//@name	CWndJikokuhyou
// ********************************
	// ********************************
	//@name CWndJikokuhyou-属性
	// ********************************
bool CWndJikokuhyou::getDisplayTsuukaEkiJikoku()const 
{
	return m_bDisplayTsuukaEkiJikoku ;
}
int CWndJikokuhyou::setDisplayTsuukaEkiJikoku( bool value ) 
{
	int iRv = 0 ;
	if ( m_bDisplayTsuukaEkiJikoku != value )
	{
		m_bDisplayTsuukaEkiJikoku = value ;

		//	通過列車の表示の有無が変化した場合は、
		//	ビューの駅時刻を更新します。
		updateUISetAllRessya() ;
		InvalidateGrid() ;

		//	通過列車の表示の有無を、
		//	.ini ファイルに保存
		getCDiagramEditApp()->writeCWndJikokuhyouViewProp( this ) ;
	}
	return ( iRv ) ;
}

bool CWndJikokuhyou::getDisplayAllEkiJikoku()const
{	return m_bDisplayAllEkiJikoku ;};

int CWndJikokuhyou::setDisplayAllEkiJikoku( bool value )
{
	int iRv = 0 ;
	if ( m_bDisplayAllEkiJikoku != value )
	{
		m_bDisplayAllEkiJikoku = value ;

		//	グリッドの列数が変わりますので、
		//	ビューの全更新が必要です。
		//	ただし、他のビューを更新する 必要はありません。
		updateUIAll() ;

		//	表示設定を .ini ファイルに保存
		getCDiagramEditApp()->writeCWndJikokuhyouViewProp( this ) ;
	}
	return ( iRv ) ;
}


void CWndJikokuhyou::setModifyEkijikoku( bool value )
{
	if ( m_bModifyEkijikoku != value )
	{
		m_bModifyEkijikoku = value ;
	
		//	表示設定を .ini ファイルに保存
		getCDiagramEditApp()->writeCWndJikokuhyouViewProp( this ) ;
	}
};

	// ********************************
	//@name CDiagramView からの委譲
	// ********************************
void CWndJikokuhyou::OnUpdate(
	CView* pSender, LPARAM lHint, CObject* pHint)
{
	if ( !m_bReadCWndJikokuhyouDefault )
	{
		// --------------------------------
		//	.ini ファイルから、状態を読み込み
		// --------------------------------
		getCDiagramEditApp()->readCWndJikokuhyouViewProp( this ) ;
		
		m_bReadCWndJikokuhyouDefault = true ;
	}

	//	更新は、CWjkState オブジェクトで行います。
	{
		m_StateMachine.getCurrentState()->
			OnUpdate( pSender, lHint, pHint) ;
		//memo:
		//	「全更新要求 AND このビューが非アクティブビュー」の場合でも、
		//	更新を行う必要があります。
		//	全更新要求の場合は、列車選択モード・連続入力モードを
		//	退場する必要があるためです。
	}


}

void CWndJikokuhyou::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	LogMsg( "CWndJikokuhyou::OnActivateView(%d,,)" , bActivate ) ;
	
	if ( bActivate && m_bUpdate_All_Requested ){
		//	updateUI... 関数を呼び出す前に、この変数を false に
		//	しなくてはなりません。
		//	この変数が true だと、OnUpdate の下請関数は何もせずに
		//	return します。
		m_bUpdate_All_Requested = false ;

		updateUIAll() ;
	}
}

	// ********************************
	//@name static CWndJikokuhyou-操作
	// ********************************
CdDedJikokuOrder 
CWndJikokuhyou::CdDedJikokuOrderOf( 
		const CdYColSpec& aYColSpec ) 
{
	CdDedJikokuOrder	aJikokuOrder ;
	if ( aYColSpec.getColumnType() 
		== CdYColSpec::ColumnType_Ekijikoku_Chaku )
	{
		aJikokuOrder.setEkiOrder( aYColSpec.getEkiOrder() , 
			CdDedJikokuOrder::EkiJikokuItem_Chaku ) ;
	}
	else if ( aYColSpec.getColumnType() 
		== CdYColSpec::ColumnType_Ekijikoku_Hatsu )
	{
		aJikokuOrder.setEkiOrder( aYColSpec.getEkiOrder() , 
			CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ;
	}
	return aJikokuOrder ;
}
CdYColSpec 
CWndJikokuhyou::CdYColSpecOf( 
		const CdDedJikokuOrder& aJikokuOrder ) 
{
	CdYColSpec aYColSpec ;
	if ( aJikokuOrder.getEkiJikokuItem() 
		== CdDedJikokuOrder::EkiJikokuItem_Chaku )
	{
		aYColSpec.set( CdYColSpec::ColumnType_Ekijikoku_Chaku ,
			aJikokuOrder.getEkiOrder() ) ;
	}
	else if ( aJikokuOrder.getEkiJikokuItem() 
		== CdDedJikokuOrder::EkiJikokuItem_Hatsu )
	{
		aYColSpec.set( CdYColSpec::ColumnType_Ekijikoku_Hatsu ,
			aJikokuOrder.getEkiOrder() ) ;
	}
	return aYColSpec ;
}


	// ********************************
	//@name CWndJikokuhyou-操作
	// ********************************

CdXColSpecCont 
CWndJikokuhyou::createXColSpecCont() 
{
	CdXColSpecCont aXColumnSpecCont ;
	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	if ( pCentDedRessyaCont != NULL )
	{
		aXColumnSpecCont.scan( pCentDedRessyaCont ) ;
	}
	return aXColumnSpecCont ;
}

CdYColSpecCont 
CWndJikokuhyou::createYColSpecCont() 
{
	const CentDedRosen*	pCentDedRosen = 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;

	CdYColSpecCont aYColumnSpecCont ;

	aYColumnSpecCont.scan(
		pCentDedRosen->getCentDedEkiCont() ,
		getRessyahoukou() ,
		m_bDisplayAllEkiJikoku ) ;
	return aYColumnSpecCont ;
}

CdXColSpec 
CWndJikokuhyou::getXColSpecOfFocus() 
{
	CdXColSpec aXColSpec ;

	CdXColSpecCont aXColSpecCont 
				= createXColSpecCont() ;
	CdDcdPosXy	posFocusCell = getCFocus()->getFocusCellColumnNumber() ;
	aXColSpec = aXColSpecCont.ColumnNumberToSpec( posFocusCell.getX() ) ;

	return aXColSpec ;
}
CdYColSpec 
CWndJikokuhyou::getYColSpecOfFocus() 
{
	CdYColSpec aYColSpec ;

	CdYColSpecCont aYColSpecCont 
				= createYColSpecCont() ;
	CdDcdPosXy	posFocusCell = getCFocus()->getFocusCellColumnNumber() ;
	aYColSpec = aYColSpecCont.ColumnNumberToSpec( posFocusCell.getY() ) ;

	return aYColSpec ;
}


int CWndJikokuhyou::
	moveFocusCellToNext( bool bJikokuhyouFocusToRight , bool bNextEkiOrder ) 
{
	int iRv = 0 ;
	CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;

	CdXColSpecCont	aXColSpecCont
		= createXColSpecCont() ;

	//	フォーカスを上下に移動
	if ( !bJikokuhyouFocusToRight )
	{
		//	セル移動時に、列車選択が変動しないようにします。
		CPropStack aPropStack( this ) ;
		aPropStack.CBoxSelect_setIsEnable( false ).CRandomSelect_setIsEnable( false ) ;

		//	移動先のセル位置を求める
		CdYColSpecCont aYColSpecCont = createYColSpecCont() ;

		int iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell(pCDcdGridCell) ;
		int iXColumnNumber = getCXDcdGrid()->getXColumnNumberOfCell(pCDcdGridCell) ;
		if ( 0 <= iYColumnNumber && 
				iYColumnNumber < 
				aYColSpecCont.getColumnNumber_Ekijikoku_begin() )
		{
			//iYColumnNumber = 列車番号〜号数までの間（駅時刻の上）
			//	にあります。
			//	この場合は、一番上の駅時刻に移動します。
			iYColumnNumber = 
				aYColSpecCont.getColumnNumber_Ekijikoku_begin() ;
		}
		else if ( 
			aYColSpecCont.getColumnNumber_Ekijikoku_begin() <= 
				iYColumnNumber && 
			iYColumnNumber < 
				aYColSpecCont.getColumnNumber_Ekijikoku_end() )
		{
			//iYColumnNumber = 駅時刻の位置にあります。
			if ( bNextEkiOrder && 
				aXColSpecCont.getColumnNumber_Ressya_begin() <= iXColumnNumber	)
			{
				//	bNextEkiOrder が真で、フォーカスが特定列車上にある場合	
				CdDedJikokuOrder	aJikokuOrder = CdDedJikokuOrderOf( 
					aYColSpecCont.ColumnNumberToSpec( iYColumnNumber ) ) ;
				if ( !aJikokuOrder.getIsNull() )
				{
					//iYColumnNumber = 駅時刻の位置にあります。
					//	次の駅の着時刻の列番号
					iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
						CdYColSpec(
							CdYColSpec::ColumnType_Ekijikoku_Chaku ,
							aJikokuOrder.getEkiOrder() + 1  ) , false ) ;
					//iYColumnNumber=次の駅の着時刻の列番号
					if ( iYColumnNumber < 0 )
					{
						iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
						CdYColSpec(
							CdYColSpec::ColumnType_Ekijikoku_Hatsu ,
							aJikokuOrder.getEkiOrder() + 1  ) , false ) ;
					}
					if ( iYColumnNumber < 0 )
					{
						//	一番下の駅時刻からの移動です。
						//	駅時刻の次に移動しました。
						iYColumnNumber = aYColSpecCont.getColumnNumber_Ekijikoku_end() ;
					}

				}
			}
			else
			{
				//	bNextEkiOrder が偽の場合、
				//	フォーカスが特定列車上にある場合	

				//フォーカスセルを次へ移動
				CDcdGridCell*	pCell = 
					getCXDcdGrid()->calcMovedCell( 
						pCDcdGridCell , 
						0 , 
						1 ) ;
				if ( pCell != NULL )
				{
					iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ;
				}
			}
		}
		else if ( aYColSpecCont.getColumnNumber_Ekijikoku_end() <= 
					iYColumnNumber )
		{
			//iYColumnNumber = 駅時刻の後(備考欄)にあります。
			//	この場合は、次の列(次の列車)の最上行に移動します。	
			iYColumnNumber = 0 ;
			if ( 0 <= iXColumnNumber && 
				iXColumnNumber < aXColSpecCont.getColumnNumber_Ressya_begin() )
			{
				iXColumnNumber = aXColSpecCont.getColumnNumber_Ressya_begin() ;
			}
			else
			{
				iXColumnNumber ++ ;
			}

		}

		//iYColumnNumber = 次の駅時刻の列番号
		//	(-1の場合もあります。(路線の終着駅の駅時刻入力を終えた後))
		if ( iYColumnNumber >= 0 )
		{
			CDcdGridCell*	pCell = 
				getCXDcdGrid()->getCell( 
					iXColumnNumber , 
					iYColumnNumber ) ;
			if ( pCell )
			{
				getCFocus()->setFocusCell( pCell ) ;
			}
		}
	}
	//	フォーカス横移動モード
	else
	{
		CDcdGridCell*	pCell = 
			getCXDcdGrid()->calcMovedCell( 
				getCFocus()->getFocusCell() , 
				+1 , 
				0 ) ;
		if ( pCell ){
			getCFocus()->setFocusCell( pCell ) ;
		}

		//	フォーカス横移動モードでは、選択を解除します。
		clearSelect() ;

	}


	return ( iRv ) ;
}

int CWndJikokuhyou::
	moveFocusCellToPrev( bool bJikokuhyouFocusToRight , bool bNextEkiOrder ) 
{
	int iRv = 0 ;
	CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;

	CdXColSpecCont	aXColSpecCont
		= createXColSpecCont() ;
	CdYColSpecCont	aYColSpecCont
		= createYColSpecCont() ;

	//	フォーカスを上下に移動
	if ( !bJikokuhyouFocusToRight )
	{
		//	セル移動時に、列車選択が変動しないようにします。
		CPropStack aPropStack( this ) ;
		aPropStack.CBoxSelect_setIsEnable( false ).CRandomSelect_setIsEnable( false ) ;


		//	移動先のセル位置を求める
		int iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell(pCDcdGridCell) ;
		int iXColumnNumber = getCXDcdGrid()->getXColumnNumberOfCell(pCDcdGridCell) ;
		if ( 0 <= iYColumnNumber && 
			iYColumnNumber < 
			aYColSpecCont.getColumnNumber_Ekijikoku_begin() )
		{
			//iYColumnNumber = 列車番号〜号数までの間（駅時刻の上）
			//	にあります。
			//	この場合は、前の列(列車)の、備考欄 に移動します。
			iYColumnNumber = aYColSpecCont.getColumnNumber_Ekijikoku_end()  ;

			iXColumnNumber -- ;

		}
		else if ( 
			aYColSpecCont.getColumnNumber_Ekijikoku_begin() <= 
				iYColumnNumber && 
			iYColumnNumber < 
				aYColSpecCont.getColumnNumber_Ekijikoku_end() )
		{
			//iYColumnNumber = 駅時刻の位置にあります。
			if ( bNextEkiOrder &&
				aXColSpecCont.getColumnNumber_Ressya_begin() <= iXColumnNumber	)
			{
				//	bNextEkiOrder が真で、フォーカスが特定列車上にある場合	

				CdDedJikokuOrder aJikokuOrder = CdDedJikokuOrderOf(
					aYColSpecCont.ColumnNumberToSpec( iYColumnNumber ) )  ;

				if ( !aJikokuOrder.getIsNull() )
				{
					//iYColumnNumber = 駅時刻の位置にあります。
					iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
						CdYColSpec( 
							CdYColSpec::ColumnType_Ekijikoku_Chaku ,
							aJikokuOrder.getEkiOrder() - 1  ) , false ) ;
					//iYColumnNumber = 前の駅の着駅
					if ( iYColumnNumber < 0 )
					{
						iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
							CdYColSpec( 
								CdYColSpec::ColumnType_Ekijikoku_Hatsu ,
								aJikokuOrder.getEkiOrder() - 1  ) , false ) ;
					}
					if ( iYColumnNumber < 0 )
					{
						//	フォーカスが始発駅の駅時刻より前になります。
						//	この場合は、列車番号の位置に移動します。
						iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
							CdYColSpec(
							CdYColSpec::ColumnType_Ressyabangou )
							, false ) ;
					}
				}
			}
			else
			{
				CDcdGridCell*	pCell = 
					getCXDcdGrid()->calcMovedCell( 
						pCDcdGridCell , 
						0 , 
						-1 ) ;
				if ( pCell != NULL )
				{
					iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ;
				}
			}
		}
		else if ( aYColSpecCont.getColumnNumber_Ekijikoku_end() <= iYColumnNumber )
		{
			//iYColumnNumber = 駅時刻の位置よりあとにあります。
			//	終着駅の最後の駅時刻に移動します。
			iYColumnNumber = aYColSpecCont.getColumnNumber_Ekijikoku_end() - 1 ;
		}

		//iYColumnNumber = 次の駅時刻の列番号
		//	(-1の場合もあります。(路線の終着駅の駅時刻入力を終えた後))
		if ( iYColumnNumber >= 0 )
		{
			CDcdGridCell*	pCell = 
				getCXDcdGrid()->getCell( 
					iXColumnNumber , 
					iYColumnNumber ) ;
			if ( pCell )
			{
				getCFocus()->setFocusCell( pCell ) ;
			}
		}
	}
	//	フォーカス横移動モード
	else
	{
		CDcdGridCell*	pCell = 
			getCXDcdGrid()->calcMovedCell( 
				getCFocus()->getFocusCell() , 
				-1 , 
				0 ) ;
		if ( pCell )
		{
			getCFocus()->setFocusCell( pCell ) ;
		}

		//	フォーカス横移動モードでは、選択を解除します。
		clearSelect() ;

	}


	return ( iRv ) ;
}


int CWndJikokuhyou::execCdModifyEkijikokuCmd(
		Ou<EditCmd::CRfEditCmd_Ressya> pCmd , 
		CdDedJikokuOrder aCdJikokuOrder ) 
{
	int iRv = 0 ;
	CString	strError ;
	// --------------------------------
	int idxError = -1 ;

	// --------------------------------
	//	コマンドオブジェクトの列車を編集
	// --------------------------------
	if ( iRv >= 0 )
	{
		for ( int idxRessya = 0 ; 
			iRv >= 0 && idxRessya < pCmd->getCaMuiSelect()->size() ; 
			idxRessya ++ )
		{
			CentDedRessya*	pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( idxRessya ) ; 
			//pCentDedRessya = pCmd 内の列車オブジェクトを指します。

			int iResult = m_EkijikokuModifyOperation2.execute( 
				pCentDedRessya , 
				aCdJikokuOrder ) ;
			//	-	-1 ;	//	iJikokuOrder が範囲外です。
			if ( iResult < 0 )
			{
				switch ( iResult ){
				case -1 :	
					iRv = -1 ;	//	X列番号が不正です。
					break ;
				default :	
					iRv = iResult ;
					break ;
				}
				idxError = idxRessya ;
			}
		}
	}
	//idxError = エラーが発生した場合は、
	//	エラーの発生した列車の aCentDedRessyaCont 内でのIndexです。

	// --------------------------------
	//	コマンドオブジェクトを実行
	// --------------------------------
	if ( iRv >= 0 )
	{
		getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
	}
	// --------------------------------
	//	エラー表示
	// --------------------------------
	if ( iRv < 0 )
	{
		//	フォーカスセルをエラーの発生した列車へ移します。
		{
			CdDcdPosXy	posFocusCell = getCFocus()->getFocusCellColumnNumber() ;

			CdXColSpecCont aXColSpecCont 
				= createXColSpecCont() ;
			posFocusCell.setX( aXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Ressya ,
					pCmd->getIndexDst() + pCmd->getCaMuiSelect()->indexFromAdapteeIndex( idxError ) )
			) );
			
			getCFocus()->setFocusCellColumnNumber( posFocusCell ) ;
		}

		// --------------------------------
		if ( strError.IsEmpty() )
		{
			strError.Format( IDS_ERR_ERRORCODE , iRv ) ;
		}
		MessageBox( strError , NULL , MB_ICONEXCLAMATION | MB_OK ) ; 
	}
	return ( iRv ) ;

}



bool CWndJikokuhyou::createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>* ppCmd )
{
	bool bRv = false ;
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya> pCmd ;

	CdXColSpecCont aCdXColSpecCont = createXColSpecCont() ;
	CdXColSpec  aCdXColSpecOfFocus = getXColSpecOfFocus() ;

	// ********************************
	//	ECreateCmd_NewTrain
	//　新規列車を対象としたコマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_NewItem )
	{
		//	時刻表ビュー上で複数選択がOFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{
			//	新規に追加される列車の、初期オブジェクト
			CentDedRessya aNewRessya = getCentDedRessyaCont()->createNullRessya() ;
			aNewRessya.setRessyasyubetsuIndex( 0 ) ;

			//　時刻表ビュー上で複数選択がOFF・フォーカスセルが既存列車上にある場合: 
			// - m_iIndexDst = フォーカスセルの列車Index、m_iIndexSize = 0
			// - m_CentDedRessyaCont = 空列車(NULLではない)
			// - CaMuSelect,CaMuiSelect = 当該列車を選択。
			if ( aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_Ressya )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
						new CRfEditCmd_Ressya( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							GetDocument()->getDiaIndex() , 
							GetDocument()->getRessyahoukou() ,
							aCdXColSpecOfFocus.getRessyaIndex() , 
							0 ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewRessya , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}
			// 　時刻表ビュー上で複数選択がOFF・フォーカスセルが新規列車位置にある場合:
			// - m_iIndexDst = 末尾列車Index+1、m_iIndexSize = 0
			// - m_CentDedRessyaCont = 空列車(NULLではない)
			// - CaMuSelect,CaMuiSelect = 当該列車を選択。
			else if ( aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_NewRessya )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
						new CRfEditCmd_Ressya( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							GetDocument()->getDiaIndex() , 
							GetDocument()->getRessyahoukou() ,
							aCdXColSpecOfFocus.getRessyaIndex() , 
							0 ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewRessya , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}
		}
		// 　時刻表ビュー上で複数選択ON:
		// NULLを返します([14/05/18]旧:複数選択OFFの場合と同じ動作)
	}
	// ********************************
	//	ECreateCmd_Focus
	//　フォーカスセル上の1列車を対象としたコマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_Focus )
	{
		//	時刻表ビュー上で複数選択がOFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{
			//　時刻表ビュー上で複数選択がOFF・フォーカスセルが既存列車上にある場合: 
			// - m_iIndexDst = フォーカスセルの列車Index、m_iIndexSize = 1
			// - m_CentDedRessyaCont = フォーカスセル上の列車1個のコピー
			// - m_CaMuiSelect = フォーカスセル上の列車を選択。
			if ( aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_Ressya )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
						new CRfEditCmd_Ressya( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							GetDocument()->getDiaIndex() , 
							GetDocument()->getRessyahoukou() ,
							aCdXColSpecOfFocus.getRessyaIndex() , 
							1 ) ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			//　時刻表ビュー上で複数選択がOFF・フォーカスセルが新規列車位置にある場合: 
			// - NULLを返します。
		}
		//　時刻表ビュー上で複数選択ON
		// NULLを返します([14/05/18]旧:複数選択OFFの場合と同じ動作)
	}
	// ********************************
	//	ECreateCmd_Select
	//　既存の単数または複数選択されている列車を対象とした
	//	コマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select )
	{
		//　時刻表ビュー上で複数選択がOFF・フォーカスセルが既存列車上にある場合: 
		//
		// - m_iIndexDst = フォーカスセルの列車Index、m_iIndexSize = 1
		// - m_CentDedRessyaCont = フォーカスセルのある列車1個のコピー
		// - CaMuiSelect = 当該列車を選択。
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_Ressya )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
					new CRfEditCmd_Ressya( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						GetDocument()->getDiaIndex() , 
						GetDocument()->getRessyahoukou() ,
						aCdXColSpecOfFocus.getRessyaIndex() , 
						1 ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		//　時刻表ビュー上で複数選択がOFF・フォーカスセルが新規列車位置にある場合: 
		// - NULLを返します。

		//　時刻表ビュー上で複数選択ON
		// - m_iIndexDst = 選択されている列車の先頭index
		// - m_iIndexSize = 選択されている列車の末尾index-先頭index+1
		// - m_CentDedRessyaCont = 選択されている列車の先頭indexから
		//  末尾indexまでの列車のコピー
		// - CaMuiSelect は、フォーカスセルに合わせて列車を選択。
		
		//(A)の位置で処理します。
	}


	// ********************************
	//		ECreateCmd_All ,
	//　全列車を対象としたコマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_All )
	{

		//  時刻表ビュー上で複数選択がOFF・フォーカスセルが列車上にある場合: 
		//
		// - m_iIndexDst = 0、m_iIndexSize = 列車の数
		// - m_CentDedRessyaCont = 全列車のコピー
		// - m_CaMuiSelect2 は、全列車を選択。
		//  時刻表ビュー上で複数選択がOFF・フォーカスセルが新規列車位置にある場合: 
		// 
		// - m_iIndexDst = 0、m_iIndexSize = 列車の数
		// - m_CentDedRessyaCont = 全列車のコピー
		// - CaMuiSelect2 は、全列車を選択。
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& ( aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_Ressya 
			|| aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_NewRessya ) )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
					new CRfEditCmd_Ressya( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						GetDocument()->getDiaIndex() , 
						GetDocument()->getRessyahoukou() ,
						0 , 
						getCentDedRessyaCont()->size() ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		//時刻表ビュー上で複数選択ON
		//
		// - m_iIndexDst = 選択されている列車の先頭index
		// - m_iIndexSize = 選択されている列車の末尾index-先頭index+1
		// - m_CentDedRessyaCont = 選択されている列車の先頭indexから
		//	末尾indexまでの列車のコピー
		// - m_CaMuiSelect2 は、セルの選択に合わせて列車を選択。

		//(A)の位置で処理します。
	}

	// ********************************
	//	(A)ECreateCmd_Select・ECreateCmd_All で
	//　複数選択されている列車を対象とした
	//	コマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select 
		|| eCreateCmd == ECreateCmd_All )
	{
		if ( getCSelect()->getSelectedCellCount() > 0 )
		{
			//	選択されている列車の列車Indexを取得
			deque<int> contiRessyaIndex ;
			for ( int iColumnNumber = 0 ; iColumnNumber < getCXDcdGrid()->getXColumnCount() ;iColumnNumber ++ )
			{
				if ( getCSelect()->getXColumnNumberSelected( iColumnNumber ) )
				{
					CdXColSpec aCdXColSpec = aCdXColSpecCont.ColumnNumberToSpec( iColumnNumber ) ;
					if ( aCdXColSpec.getColumnType() == CdXColSpec::ColumnType_Ressya )
					{
						contiRessyaIndex.push_back( aCdXColSpec.getRessyaIndex() ) ;
					}
				}
			}
			//contiRessyaIndex = 列の複数選択が実施されている場合は、
			//	選択されている列車Indexが格納されます。
			//	そうでない場合は、空です。

			if ( contiRessyaIndex.size() > 1 )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					//	コマンドオブジェクト内に、選択されている列車の先頭から末尾までの
					//	列車を格納します(先頭・末尾以外には、選択されていない列車が
					//	含まれている場合もあります)
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
						new CRfEditCmd_Ressya( 
							*getCDiagramEditDoc()->getCDedRosenFileData() ,
							GetDocument()->getDiaIndex() , 
							GetDocument()->getRessyahoukou() ,
							contiRessyaIndex.front() , 
							contiRessyaIndex.back() - contiRessyaIndex.front() + 1 ) ) ;

					//	コマンドオブジェクトの
					//	m_CentDedRessyaContSrc  内の列車を選択します。
					pCmd->getCaMuiSelect()->setSelectAll( false ) ;
					for ( int i = 0 ; i < (int)contiRessyaIndex.size() ; i ++ )
					{
						pCmd->getCaMuiSelect()->setSelect( contiRessyaIndex[i] - contiRessyaIndex.front()  , true ) ;
					}
				}
			}
		}
	}
	// ================================
	if ( ppCmd != NULL && pCmd != NULL )
	{
		*ppCmd = pCmd ;
	}
	return bRv ;
}

bool CWndJikokuhyou::createCmd( int iRessyaIndex , int iRessyaCount , 
		Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>* ppCmd) 
{
	bool bRv = false ;
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya> pCmd ;
	int iRv = 0 ;

	//  --------------------------------
	//	コマンドオブジェクトを生成
	//  --------------------------------
	if ( iRv >= 0 )
	{
		//	コマンドオブジェクト内に、指定された範囲の
		//	列車を格納します
		//	列車は全選択となります。
		bRv = true ;
		if ( ppCmd != NULL )
		{
			pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
				new CRfEditCmd_Ressya( 
					*getCDiagramEditDoc()->getCDedRosenFileData() , 
					GetDocument()->getDiaIndex() , 
					GetDocument()->getRessyahoukou() ,
					iRessyaIndex , 
					iRessyaCount ) ) ;
		}
	}
	// ================================
	if ( ppCmd != NULL && pCmd != NULL )
	{
		*ppCmd = pCmd ;
	}
	return bRv ;
}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
BEGIN_MESSAGE_MAP(CWndJikokuhyou,CWndJikokuhyou::super)
	//{{AFX_MSG_MAP(CWndJikokuhyou)
	ON_WM_CREATE()
	ON_WM_KEYUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_Jikokuhyou_RessyaProp, OnJikokuhyouRessyaProp)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_RessyaProp, OnUpdateJikokuhyouRessyaProp)
	ON_COMMAND(ID_Jikokuhyou_RessyaInsert, OnJikokuhyouRessyaInsert)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_RessyaInsert, OnUpdateJikokuhyouRessyaInsert)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_Edit_PasteEkiJikoku, OnEditPasteEkiJikoku)
	ON_UPDATE_COMMAND_UI(ID_Edit_PasteEkiJikoku, OnUpdateEditPasteEkiJikoku)
	ON_COMMAND(ID_Jikokuhyou_Tsuuka, OnJikokuhyouTsuuka)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Tsuuka, OnUpdateJikokuhyouTsuuka)
	ON_COMMAND(ID_Jikokuhyou_Keiyunasi, OnJikokuhyouKeiyunasi)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Keiyunasi, OnUpdateJikokuhyouKeiyunasi)
	ON_COMMAND(ID_Jikokuhyou_Sihatsu, OnJikokuhyouSihatsu)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Sihatsu, OnUpdateJikokuhyouSihatsu)
	ON_COMMAND(ID_Jikokuhyou_Syuuchaku, OnJikokuhyouSyuuchaku)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Syuuchaku, OnUpdateJikokuhyouSyuuchaku)
	ON_COMMAND(ID_Jikokuhyou_Renzoku, OnJikokuhyouRenzoku)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Renzoku, OnUpdateJikokuhyouRenzoku)
	ON_COMMAND(ID_Jikokuhyou_ViewProp, OnJikokuhyouViewProp)
	ON_COMMAND(ID_Jikokuhyou_FocusMoveDown, OnJikokuhyouFocusMoveDown)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_FocusMoveDown, OnUpdateJikokuhyouFocusMoveDown)
	ON_COMMAND(ID_Jikokuhyou_FocusMoveRight, OnJikokuhyouFocusMoveRight)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_FocusMoveRight, OnUpdateJikokuhyouFocusMoveRight)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuProp, OnJikokuhyouEkijikokuProp)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuProp, OnUpdateJikokuhyouEkijikokuProp)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuInsert, OnJikokuhyouEkijikokuInsert)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuInsert, OnUpdateJikokuhyouEkijikokuInsert)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuErase, OnJikokuhyouEkijikokuErase)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuErase, OnUpdateJikokuhyouEkijikokuErase)
	ON_WM_CHAR()
	ON_COMMAND(ID_Jikokuhyou_ModifyEkijikokuCmd, OnJikokuhyouModifyEkijikokuCmd)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_ModifyEkijikokuCmd, OnUpdateJikokuhyouModifyEkijikokuCmd)
	ON_COMMAND(ID_Jikokuhyou_ModifyEkijikokuCmdRepeat, OnJikokuhyouModifyEkijikokuCmdRepeat)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_ModifyEkijikokuCmdRepeat, OnUpdateJikokuhyouModifyEkijikokuCmdRepeat)
	ON_COMMAND(ID_Jikokuhyou_JikokuSakujo, OnJikokuhyouJikokuSakujo)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_JikokuSakujo, OnUpdateJikokuhyouJikokuSakujo)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuDec, OnJikokuhyouEkijikokuDec)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuDec, OnUpdateJikokuhyouEkijikokuDec)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuNext, OnJikokuhyouEkijikokuNext)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuNext, OnUpdateJikokuhyouEkijikokuNext)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuInc, OnJikokuhyouEkijikokuInc)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuInc, OnUpdateJikokuhyouEkijikokuInc)
	ON_COMMAND(ID_Jikokuhyou_EKikanSaisyouSec, OnJikokuhyouEKikanSaisyouSec)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EKikanSaisyouSec, OnUpdateJikokuhyouEKikanSaisyouSec)
	ON_COMMAND(ID_Jikokuhyou_DiagramHeIdou, OnJikokuhyouDiagramHeIdou)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_DiagramHeIdou, OnUpdateJikokuhyouDiagramHeIdou)
	ON_COMMAND(ID_VIEW_DisplayTsuukaEkiJikoku, OnVIEWDisplayTsuukaEkiJikoku)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DisplayTsuukaEkiJikoku, OnUpdateVIEWDisplayTsuukaEkiJikoku)
	ON_COMMAND(ID_FILE_EXPORT_JIKOKUHYOUCSV, OnFileExportJikokuhyoucsv)
	ON_COMMAND(ID_FILE_IMPORT_JIKOKUHYOUCSV, OnFileImportJikokuhyoucsv)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_PasteZoubun, OnUpdateINDICATOR_PasteZoubun)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuDecNoMove, &CWndJikokuhyou::OnJikokuhyouEkijikokudecnomove)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuDecNoMove, &CWndJikokuhyou::OnUpdateJikokuhyouEkijikokudecnomove)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuIncNoMove, &CWndJikokuhyou::OnJikokuhyouEkijikokuincnomove)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuIncNoMove, &CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuincnomove)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuPrev, &CWndJikokuhyou::OnJikokuhyouEkijikokuPrev)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuPrev, &CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuPrev)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CWndJikokuhyou::OnEditSelectAll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SELECT_ALL, &CWndJikokuhyou::OnUpdateEditSelectAll)
	ON_COMMAND(ID_Jikokuhyou_SORT, &CWndJikokuhyou::OnJikokuhyouSort)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_SORT, &CWndJikokuhyou::OnUpdateJikokuhyouSort)
	ON_COMMAND(ID_Jikokuhyou_TsuukaTeisya, &CWndJikokuhyou::OnJikokuhyouTsuukateisya)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_TsuukaTeisya, &CWndJikokuhyou::OnUpdateJikokuhyouTsuukateisya)
	ON_COMMAND(ID_Jikokuhyou_Direct, &CWndJikokuhyou::OnJikokuhyouDirect)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Direct, &CWndJikokuhyou::OnUpdateJikokuhyouDirect)
	ON_COMMAND(ID_Jikokuhyou_Undirect, &CWndJikokuhyou::OnJikokuhyouUndirect)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Undirect, &CWndJikokuhyou::OnUpdateJikokuhyouUndirect)
	ON_COMMAND(ID_VIEW_DisplayAllEkiJikoku, &CWndJikokuhyou::OnViewDisplayallekijikoku)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DisplayAllEkiJikoku, &CWndJikokuhyou::OnUpdateViewDisplayallekijikoku)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_Jikokuhyou_Unify, &CWndJikokuhyou::OnJikokuhyouUnify)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Unify, &CWndJikokuhyou::OnUpdateJikokuhyouUnify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


int CWndJikokuhyou::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (super::OnCreate(lpCreateStruct) == -1)
		return -1;


	// --------------------------------
	//	状態の初期値を設定
	// --------------------------------
	m_StateMachine.add( OuNew< CWjkState >( new CWjkState_Ressyahensyu( this ) ) ) ;
	m_StateMachine.add( OuNew< CWjkState >( new CWjkState_Renzoku( this ) ) ) ;
	m_StateMachine.setCurrentStateIdx( StateIdx_Ressyahensyu ) ;


	// --------------------------------
	//	列の数を指定
	// --------------------------------
	//	駅名
	//	発着
	//	列車(1...*)
	getCXDcdGrid()->setXColumnCount( 3 ) ;
	getCXDcdGrid()->setXFixColumnCount( 2 ) ;
	//	列車番号
	//	種別
	//	列車名
	//	号数
	//	号
	//	駅時刻(0...*)
	//	備考
	getCXDcdGrid()->setYColumnCount( 6 ) ;
	getCXDcdGrid()->setYFixColumnCount( 5 ) ;

	// --------------------------------
	//	フォーカスセルの初期位置を設定
	// --------------------------------
	getCFocus()->setFocusCell( getCXDcdGrid()->getCell( 1 , 1 ) ) ;	
	
	return 0;
}

void CWndJikokuhyou::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	m_StateMachine.getCurrentState()->
		OnKeyDown(nChar, nRepCnt, nFlags);
	//	super::OnKeyDown(nChar, nRepCnt, nFlags);
}
void CWndJikokuhyou::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	m_StateMachine.getCurrentState()->
		OnKeyUp(nChar, nRepCnt, nFlags);
	//super::OnKeyUp(nChar, nRepCnt, nFlags);
}



void CWndJikokuhyou::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	m_StateMachine.getCurrentState()->
		OnChar( nChar, nRepCnt, nFlags)  ;
	
	
}

void CWndJikokuhyou::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	m_StateMachine.getCurrentState()->
		OnLButtonDblClk(nFlags, point);
	//super::OnLButtonDblClk(nFlags, point);

}

//TODO:リファクタリング
//	GridからのOnContextMenu() は、実装が重複しています。
//	これは、CWndDcdGrid2(将来は、CWndDcdGrid3)に置くべきです。
void CWndJikokuhyou::OnContextMenu(CWnd* pWnd, CPoint point)
{
	int iMenuIndex = -1 ;
	//	フォーカスセルが列車にあるか、駅時刻にあるかを判定します
	//	これにより、表示するコンテキストメニューが変わります。
	{
		const Mu<const CentDedRessya*>* pCentDedRessyaCont = getCentDedRessyaCont()->getMuPtr() ;
		CdXColSpec aXColSpec = getXColSpecOfFocus() ;
		CdYColSpec aYColSpec = getYColSpecOfFocus() ;
		
		//	フォーカスセルが駅名部分・列車(新しい列車 を含む)にある場合は、
		//	コンテキストメニューを表示します。
		if ( aXColSpec.getColumnType() 
				== CdXColSpec::ColumnType_Ekimei || 
			aXColSpec.getColumnType() 
				== CdXColSpec::ColumnType_Chakuhatsu || 
			aXColSpec.getColumnType() 
				== CdXColSpec::ColumnType_Ressya || 
			aXColSpec.getColumnType() 
				== CdXColSpec::ColumnType_NewRessya )
		{
			if ( aYColSpec.isEkiJikoku() )
			{
				//	列車の駅時刻にセルがある場合は、駅時刻用のメニュー
				iMenuIndex = 1 ;
			}
			else
			{
				//	列車の、駅時刻以外の列車情報にセルがある場合は、
				//	列車用のメニュー
				iMenuIndex = 0 ;
			}
		}
	}
	//iMenuIndex = 
	//	0: 列車のコンテキストメニュー
	//	1: 列車・駅時刻のコンテキストメニュー
	//	-1: 該当するコンテキストメニューがありません。

	{
		//	コンテキストメニューがマウス以外で呼び出された場合は、
		//	コンテキストメニューの表示位置は、フォーカスセルの中央の位置とします。
		if ( point.x ==-1 || point.y == -1 )
		{
			//	コンテキストメニューがマウス以外で呼び出されました
			CdDcdPosXy posxyFocusCellColumnNumber = getCFocus()->getFocusCellColumnNumber() ;
			if ( posxyFocusCellColumnNumber !=  
					CFocus::ColumnNumberPosXy_NULL() )
			{
				CdDcdZoneXy	zonexyFocusCell = getCellZone( 
					posxyFocusCellColumnNumber.getX() , 
					posxyFocusCellColumnNumber.getY() ) ;
				point.x = zonexyFocusCell.getX().getPos() + zonexyFocusCell.getX().getSize() / 2 ;
				point.y = zonexyFocusCell.getY().getPos() + zonexyFocusCell.getY().getSize() / 2 ;
				ClientToScreen( &point ) ;
			}
		}
	}
	//point = コンテキストメニューの表示位置。
	//	-1の場合は、コンテキストメニューは表示できません。

	if ( iMenuIndex >= 0 && point.x >= 0 &&  point.y >= 0 )
	{
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_JIKOKUHYOUVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( iMenuIndex ) ;
	
		pContextMenu->TrackPopupMenu( 
			TPM_LEFTALIGN | TPM_RIGHTBUTTON ,
			point.x , point.y , 
			AfxGetMainWnd() ) ;	//	this を指定すると、App→Doc→View の
								//コマンドチェーンが動作しません。
	}
	else
	{
		super::OnContextMenu(pWnd, point);
	}
}

void CWndJikokuhyou::OnEditCut() 
{
	m_StateMachine.getCurrentState()->
		OnEditCut_Process( FALSE )  ;

}

void CWndJikokuhyou::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditCut_Process( TRUE ) >= 0 );
}

void CWndJikokuhyou::OnEditCopy() 
{
	m_StateMachine.getCurrentState()->
		OnEditCopy_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditCopy_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnEditPaste() 
{
	m_StateMachine.getCurrentState()->
		OnEditPaste_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditPaste_Process( TRUE ) >= 0 ) ;
}
void CWndJikokuhyou::OnEditClear() 
{
	m_StateMachine.getCurrentState()->
		OnEditClear_Process( FALSE ) ;

}

void CWndJikokuhyou::OnUpdateEditClear(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditClear_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnEditPasteEkiJikoku() 
{
	m_StateMachine.getCurrentState()->
		OnEditPasteEkiJikoku_Process( FALSE ) ;

	
}

void CWndJikokuhyou::OnUpdateEditPasteEkiJikoku(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditPasteEkiJikoku_Process( TRUE ) >= 0 ) ;
	
}

void CWndJikokuhyou::OnEditSelectAll()
{
	m_StateMachine.getCurrentState()->
		OnEditSelectAll_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateEditSelectAll(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditSelectAll_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouRessyaProp() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouRessyaProp_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouRessyaProp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouRessyaProp_Process( TRUE )  >= 0 ) ;
	
}

void CWndJikokuhyou::OnJikokuhyouRessyaInsert() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouRessyaInsert_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouRessyaInsert(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouRessyaInsert_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouTsuuka() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouTsuuka_Process(FALSE) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouTsuuka(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouTsuuka_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouKeiyunasi() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouKeiyunasi_Process(FALSE) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouKeiyunasi(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouKeiyunasi_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouSihatsu() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouSihatsu_Process(FALSE) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouSihatsu(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouSihatsu_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouSyuuchaku() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouSyuuchaku_Process(FALSE) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouSyuuchaku(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouSyuuchaku_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouRenzoku() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouRenzoku_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouRenzoku(CCmdUI* pCmdUI) 
{
	int iResult = m_StateMachine.getCurrentState()->
		OnJikokuhyouRenzoku_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ; 
	pCmdUI->SetCheck( iResult > 0 ) ; 
}

void CWndJikokuhyou::OnJikokuhyouViewProp() 
{
	OnJikokuhyouViewProp_Process( FALSE ) ;
}



void CWndJikokuhyou::OnUpdateINDICATOR_PasteZoubun(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(); 
	pCmdUI->SetText( OnUpdateINDICATOR_PasteZoubun_Process() ) ;
}



void CWndJikokuhyou::OnJikokuhyouFocusMoveDown() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouFocusMoveDown_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouFocusMoveDown(CCmdUI* pCmdUI) 
{
	int iResult = m_StateMachine.getCurrentState()
		->OnJikokuhyouFocusMoveDown_Process( TRUE ) ;
	//iResult = 
	//	-	1 ;	//	(bQueryEnable=TRUEの場合)この項目はすでに選択されています
	//	-	0 ;	//	(bQueryEnable=TRUEの場合)この項目は選択されていません
	//	-  -1 ;	//	このコマンドは選択できません(メニューが無効)
	pCmdUI->Enable( iResult >= 0 );
	pCmdUI->SetCheck( iResult > 0 );
}

void CWndJikokuhyou::OnJikokuhyouFocusMoveRight() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouFocusMoveRight_Process( FALSE ) ;

}

void CWndJikokuhyou::OnUpdateJikokuhyouFocusMoveRight(CCmdUI* pCmdUI) 
{
	int iResult = m_StateMachine.getCurrentState()
		->OnJikokuhyouFocusMoveRight_Process( TRUE ) ;
	//iResult = 
	//	-	1 ;	//	(bQueryEnable=TRUEの場合)この項目はすでに選択されています
	//	-	0 ;	//	(bQueryEnable=TRUEの場合)この項目は選択されていません
	//	-  -1 ;	//	このコマンドは選択できません(メニューが無効)
	pCmdUI->Enable( iResult >= 0 );
	pCmdUI->SetCheck( iResult > 0 );
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuProp() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuProp_Process( FALSE ) ;

}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuProp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuProp_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouJikokuSakujo() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouJikokuSakujo_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouJikokuSakujo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouJikokuSakujo_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuInsert() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuInsert_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuInsert(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuInsert_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuErase() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuErase_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuErase(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuErase_Process( TRUE ) >= 0 ) ;
}


void CWndJikokuhyou::OnJikokuhyouModifyEkijikokuCmd() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouModifyEkijikokuCmd_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouModifyEkijikokuCmd(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouModifyEkijikokuCmd_Process( TRUE ) >= 0 ) ;
	
}

void CWndJikokuhyou::OnJikokuhyouModifyEkijikokuCmdRepeat() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouModifyEkijikokuCmdRepeat_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouModifyEkijikokuCmdRepeat(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouModifyEkijikokuCmdRepeat_Process( TRUE ) >= 0 ) ;
}


void CWndJikokuhyou::OnJikokuhyouEkijikokuDec() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuDec_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuDec(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuDec_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuNext() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuNext_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuNext(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuNext_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuInc() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuInc_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuInc(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuInc_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokudecnomove()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuDecNoMove_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokudecnomove(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuDecNoMove_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuincnomove()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuIncNoMove_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuincnomove(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuIncNoMove_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuPrev()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuPrev_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuPrev(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuPrev_Process( TRUE ) >= 0 ) ;
}





void CWndJikokuhyou::OnJikokuhyouEKikanSaisyouSec() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEKikanSaisyouSec_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEKikanSaisyouSec(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEKikanSaisyouSec_Process( TRUE ) >= 0 );
}

void CWndJikokuhyou::OnJikokuhyouSort()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouSort_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouSort(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouSort_Process( TRUE ) >= 0 );
}

void CWndJikokuhyou::OnJikokuhyouDiagramHeIdou() 
{
	OnJikokuhyouDiagramHeIdou_Process( FALSE ) ;
}
void CWndJikokuhyou::OnUpdateJikokuhyouDiagramHeIdou(CCmdUI* pCmdUI) 
{
	int iResult = OnJikokuhyouDiagramHeIdou_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ? TRUE : FALSE ) ;
}

void CWndJikokuhyou::OnVIEWDisplayTsuukaEkiJikoku() 
{
	OnVIEWDisplayTsuukaEkiJikoku_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateVIEWDisplayTsuukaEkiJikoku(CCmdUI* pCmdUI) 
{
	int iResult = OnVIEWDisplayTsuukaEkiJikoku_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ? TRUE : FALSE ) ;
	pCmdUI->SetCheck( iResult >= 1 ? TRUE : FALSE ) ;
	
}

//TODO:OnUpdate... ハンドラを追加する
void CWndJikokuhyou::OnFileExportJikokuhyoucsv() 
{
	OnFileExportJikokuhyoucsv_Process( FALSE ) ;
}

//TODO:OnUpdate... ハンドラを追加する
void CWndJikokuhyou::OnFileImportJikokuhyoucsv() 
{
	OnFileImportJikokuhyoucsv_Process( FALSE ) ;
}


void CWndJikokuhyou::OnJikokuhyouTsuukateisya()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouTsuukateisya_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouTsuukateisya(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouTsuukateisya_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouDirect()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouDirect_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouDirect(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouDirect_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouUndirect()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouUndirect_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouUndirect(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouUndirect_Process( TRUE ) >= 0 ) ;
}



void CWndJikokuhyou::OnViewDisplayallekijikoku()
{
	OnViewDisplayallekijikoku_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateViewDisplayallekijikoku(CCmdUI *pCmdUI)
{
	int iResult = OnViewDisplayallekijikoku_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}

void CWndJikokuhyou::OnJikokuhyouUnify()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouUnify_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouUnify(CCmdUI *pCmdUI)
{
	int iResult = m_StateMachine.getCurrentState()->
		OnJikokuhyouUnify_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
}

} } // namespace WndJikokuhyou namespace ViewJikokuhyou

