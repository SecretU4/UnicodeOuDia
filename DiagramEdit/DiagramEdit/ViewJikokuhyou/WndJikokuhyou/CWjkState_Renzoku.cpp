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
//	CWjkState_Renzoku.cpp
//	$Id: CWjkState_Renzoku.cpp 368 2016-08-19 11:11:10Z okm $
// ****************************************************************
*/
#include "stdafx.h"


#include <imm.h>

#include "NsOu\Ou.h"
#include "NsOu\OuNew.h"
#include "NsOu\dynamic_castOu.h"
#include "logmsg\LogMsg.h"
#include "DcDraw\CDcdLine.h"
#include "DcDraw\CDcdTextbox.h"
#include "str\strprintf.h"
#include "str\strtoint.h"

#include "..\CDlgRessyaProp.h"
#include "..\CDlgEkiJikokuProp.h"
#include "..\..\DiagramEdit.h"
#include "..\..\CRfEditCmdHolder.h"
#include "..\..\DedRosenFileData\EditCmd\EditCmd.h"
#include "CWjkState_Renzoku.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{ namespace WndJikokuhyou{
using namespace std ;
using namespace OuLib ;

// ****************************************************************
//	CWjkState_Renzoku
// ****************************************************************
// --------------------------------
//@name OnUpdate下請関数
// --------------------------------
void CWjkState_Renzoku::OnUpdate_All() 
{
	LogMsg( "CWjkState_Renzoku::OnUpdate_All()" ) ;

	//	『連続入力モード』->『列車編集モード』
	//	に遷移します。
	//	OnUpdate() は、『列車編集モード』に委譲します。
	getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
		CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
	CWjkState* pCState = 
		getCWndDcdGrid()->getStateMachine()->getCStateContGet()->get( 
		CWndJikokuhyou::StateIdx_Ressyahensyu  ) ;
	pCState->OnUpdate( NULL , 0 , NULL ) ;

	LogMsg( "CWjkState_Renzoku::OnUpdate_All()=" ) ;
}


void CWjkState_Renzoku::OnUpdate_CentDedRessya( 
	Ou<CRfEditCmd_Ressya> pCommand ) 
{
	//	このビューに対する列車の変更でない場合は、後続を実行しません。
	int iDiaIndex = GetDocument()->getDiaIndex() ;
	if ( !( pCommand->getDiaIndex() == iDiaIndex && 
		pCommand->getRessyahoukou() == GetDocument()->getRessyahoukou() ) ){
			return ;
	}
	const CentDedRessyaCont*	pCentDedRessyaContSrc = 
		pCommand->getCentDedRessyaContSrc() ;
	if ( !( pCommand->getSizeDst() == 1 && 
		pCentDedRessyaContSrc->size() == 1 ) )
	{
			//	１本の列車の置換え以外の場合は、
			//	『連続入力モード』->『列車編集モード』
			//	に遷移します。
			//	OnUpdate() は、『列車編集モード』に委譲します。
			getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
				CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
			CWjkState* pCState = 
				getCWndDcdGrid()->getStateMachine()->getCStateContGet()->get( 
				CWndJikokuhyou::StateIdx_Ressyahensyu  ) ;

			pCState->OnUpdate( NULL , 0 , NULL ) ; ;
			//	現在は、この場合の更新は全更新扱いにしています。
			//	最適化の余地があります。
			//
			//	連続モードで入力中の列車(m_iXColumnNumberFocus)
			//	より前の列に対して列車の追加･削除が発生した場合、
			//	m_iXColumnNumberFocus は、連続入力を行っていた
			//	列を指さなくなっています。
			//	このため、endEditCell() で正しく連続入力モードを解消する
			//	ことができません。
			//	pCommand から列車の増減を判断し、
			//	それをもとに m_iXColumnNumberFocus を調整してから
			//	endEditCell() を呼び出すことにより、
			//	更新量を最小にすることができます。
			//
			//pCState->OnUpdate( NULL , 0 , 
			//	&CRfEditCmdHolder( pCommand ) ) ;

	}
	else
	{
		//	１本の列車
		int iRessyaIndex = pCommand->getIndexDst() ;
		getCWndDcdGrid()->updateUI_ReplaceRessya( iRessyaIndex , 1 , 1 ) ;
	}
}

// --------------------------------
//@name 下請関数
// --------------------------------
bool CWjkState_Renzoku::update_adjustProp() 
{
	int iRv = 0 ;


	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	CdDcdPosXy	posFocusCell = getCWndDcdGrid()->getCFocus()->getFocusCellColumnNumber() ;

	// --------------------------------
	int iRessyaIndex = -1 ;		//	フォーカスセルの列車Index
	const CentDedRessya* pCentDedRessya = NULL ;	//	フォーカスセルの列車オブジェクト
	CdDedJikokuOrder aJikokuOrder ;	//	フォーカスセルの時刻Order
	if ( iRv >= 0 )
	{
		CdXColSpec aXColSpec = 
			getCWndDcdGrid()->getXColSpecOfFocus() ;
		if ( aXColSpec.getColumnType() == 
			CdXColSpec::ColumnType_Ressya )
		{
			iRessyaIndex = aXColSpec.getRessyaIndex()  ;
			pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
		}
		else
		{
			iRv = -1 ;	//	フォーカスセルが、列車の位置ではありません。
		}
	}
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	フォーカスセルが、駅時刻の位置ではありません。
		}
	}
	//iRessyaIndex = フォーカスセルの列車Index
	//pCentDedRessya = フォーカスセルの列車オブジェクト
	//aJikokuOrder = フォーカスセルの時刻Order

	// --------------------------------
	//  ○[フォーカス位置の駅時刻Ourder以前に、駅時刻の入力された駅が一つもない]Ressyahensyuに遷移
	if ( iRv >= 0 )
	{
		CdDedJikokuOrder	aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
			pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
		if ( aJikokuOrderRev.getIsNull() )
		{
			iRv = -3 ;	//	フォーカス位置の駅時刻Ourder以前に、駅時刻の入力された駅が一つもない
		}
	}
	//  ○[フォーカスセルが編集中列車の着発時刻ではない]Ressyahensyuに遷移
	if ( iRv >= 0 )
	{
		if ( posFocusCell.getX() != m_iXColumnNumberFocus )
		{
			iRv = -4 ;	//	フォーカスセルが、編集中列車ではありません。
		}
	}
	// --------------------------------
	if ( iRv < 0 )
	{
		//iRv
		//	-1 ;	//	フォーカスセルが、列車の位置ではありません。
		//	-2 ;	//	フォーカスセルが、駅時刻の位置ではありません。
		//	-3 ;	//	フォーカス位置の駅時刻Ourder以前に、駅時刻の入力された駅が一つもない
		//	-4 ;	//	フォーカスセルが、編集中列車ではありません。
		getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
	}
	return ( iRv != 0 ) ;

}

bool CWjkState_Renzoku::update_updateScreen( bool bOnExit ) 
{
	int iRv = 0 ;

	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	// --------------------------------
	int iRessyaIndex = -1 ;
	const CentDedRessya* pCentDedRessya = NULL ;
	CdDedJikokuOrder aJikokuOrder ;
	CdDcdPosXy	posFocusCell = getCWndDcdGrid()->getCFocus()->getFocusCellColumnNumber() ;

	
	if ( iRv >= 0 )
	{
		if ( m_iXColumnNumberFocus < 0 )
		{
			iRv = -1 ;
		}
	}
	CdXColSpec aXColSpec ;
	CdYColSpec aYColSpec ;
	if ( iRv >= 0 )
	{
		CdXColSpecCont aXColSpecCont(
			getCWndDcdGrid()->createXColSpecCont() ) ;
		CdYColSpecCont aYColSpecCont = 
			getCWndDcdGrid()->createYColSpecCont() ;


		aXColSpec = aXColSpecCont.ColumnNumberToSpec( m_iXColumnNumberFocus ) ;
		if ( aXColSpec.getColumnType() == 
			CdXColSpec::ColumnType_Ressya )
		{
			iRessyaIndex = aXColSpec.getRessyaIndex() ;
			pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
		}
		else
		{
			iRv = -1 ;	//	フォーカスセルが、列車の位置ではありません。
		}
	}
	if ( iRv >= 0 )
	{
		aYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( aYColSpec ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	フォーカスセルが、駅時刻の位置ではありません。
		}
	}
	//posFocusCell = フォーカスセル
	//iRessyaIndex = 連続入力中(m_iXColumnNumberFocus)の列車Index
	//pCentDedRessya = 連続入力中(m_iXColumnNumberFocus)の列車オブジェクト
	//aJikokuOrder = フォーカスセルの時刻Order

	// --------------------------------
	//	- 1. 編集中列を、駅時刻で更新
	// --------------------------------

	//	編集中の列車列を更新
	if ( iRv >= 0 )
	{
		getCWndDcdGrid()->updateUI_ReplaceRessya( iRessyaIndex , 1 , 1 ) ;
		iRv = 1 ;
	}
	// --------------------------------
	//	- 2. 編集中の駅時刻Orderに対して、「直前の駅時刻の時+編集中の分」を設定
	// --------------------------------
	//	編集中セルに、分を追加
	if ( iRv >= 0 )
	{
		if ( !bOnExit )
		{
			//	フォーカスセル位置に、編集中の駅時刻を追加

			CdDedJikokuOrder	aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
				pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
			if ( aJikokuOrderRev.getIsNull() )
			{
				iRv = -5 ;	//	フォーカス位置の前に、駅時刻の入力された駅が一つもない
			}
			else
			{
				CdDedJikoku	aJikokuRev = pCentDedRessya->getEkiJikoku( aJikokuOrderRev ) ;
				string	strJikoku = strprintf( "%2d%-2s" , 
					aJikokuRev.getHour() ,
					m_strMinutes.c_str() ) ;
				CDcdGridCell* pCell = getCWndDcdGrid()->getCFocus()->getFocusCell() ;
				Ou<CDcdTextbox>	pCDcdTextbox = pCell->getIfDcDraw() ;
				pCDcdTextbox->setText( strJikoku ) ;
				getCWndDcdGrid()->InvalidateCell( posFocusCell.getX() , posFocusCell.getY() ) ;

				iRv = 1 ;
			}
		}
	}
	return ( iRv > 0 ) ;
}

bool CWjkState_Renzoku::update() 
{
	bool bRv = false ;
	bRv |= update_adjustProp() ;
	bRv |= update_updateScreen() ;
	return bRv ;
}


CDcdGridCell* CWjkState_Renzoku::calcCellToNext( CDcdGridCell* pcellCurrent , int iSign ) 
{
	CDcdGridCell* pcellNext = NULL ;
	if ( iSign < 0 )
	{
		iSign = -1 ;
	}
	else 
	{
		iSign = +1 ;
	}
	// --------------------------------

	//	カレントセルの次の駅時刻セルを検索します。
	CdYColSpecCont aYColSpecCont = getCWndDcdGrid()->createYColSpecCont() ;
	for ( CDcdGridCell* pCell = getCWndDcdGrid()->getCXDcdGrid()->calcMovedCell( pcellCurrent , 0 , iSign ) ;
		pcellNext == NULL && pCell != NULL ;
		pCell = getCWndDcdGrid()->getCXDcdGrid()->calcMovedCell( pCell , 0 , iSign ) )
	{
		int iYColumnNumberNext = getCWndDcdGrid()->getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ;

		//	Y列番号が時刻列以外(駅時刻開始位置から駅時刻終了位置の範囲の外)に移動した場合は、ループ終了
		if ( !(
			aYColSpecCont.getColumnNumber_Ekijikoku_begin() <= iYColumnNumberNext && 
			iYColumnNumberNext < aYColSpecCont.getColumnNumber_Ekijikoku_end() ) ) 
		{
			break ;
		}

		// Y列番号に対応する時刻Orderがなければ、次にフォーカスを移動
		//	(将来・時刻表の途中に着時刻・発時刻以外が登場した場合に備えています)
		CdDedJikokuOrder	aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf(
			aYColSpecCont.ColumnNumberToSpec( iYColumnNumberNext ) );
		if ( aJikokuOrder.getIsNull() )
		{
			continue ;
		}
		pcellNext = pCell ;
	}

	return ( pcellNext ) ;
}


// ********************************
//	コンストラクタ
// ********************************
CWjkState_Renzoku::
CWjkState_Renzoku( 
	CWndJikokuhyou*	pCWndDcdGrid )
	: super( pCWndDcdGrid )
	, m_iXColumnNumberFocus( -1 ) 
{
}
CWjkState_Renzoku::
~CWjkState_Renzoku() 
{
}

// ********************************
//	CWjkState
// ********************************
/**
	指定のウインドウの、IMEをON/OFFにします。
 @param hWnd [in]
	ウインドウハンドルを指定してください。
 @param iOn [in]
	- TRUE ;	//	IMEをONにする
	- FALSE ;	//	IMEをOFFにする
 @return
	-	1 ;	//	状態を変更しました。
	-	0 ;	//	状態を変更する必要はありませんでした。
	-	-1 ;	//	エラー(ImmGetContext() に失敗)
*/
static int ImeControl( HWND hWnd, BOOL iOn )
{
	int iRv = 0 ;

	HIMC hImc = ::ImmGetContext( hWnd );
	if ( hImc )
	{
		int j = (::ImmGetOpenStatus( hImc )) ? TRUE : FALSE;
		if ( j != iOn ){
			iRv = 1 ;
			::ImmSetOpenStatus( hImc, iOn );
		}
		::ImmReleaseContext( hWnd , hImc );
	}	else	{
		iRv = -1 ;	//	エラー(ImmGetContext() に失敗)
	}
	return ( iRv ) ;
}

	// ********************************
	//@name CWjkState-操作
	// ********************************
int CWjkState_Renzoku::canEnter() 
{
	int iRv = 0 ;

	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	CdDcdPosXy	posFocusCell = getCWndDcdGrid()->getCFocus()->getFocusCellColumnNumber() ;
	// --------------------------------
	int iRessyaIndex = -1 ;		//	フォーカスセルの列車Index
	const CentDedRessya* pCentDedRessya = NULL ;	//	フォーカスセルの列車オブジェクト
	CdDedJikokuOrder aJikokuOrder ;	//	フォーカスセルの時刻Order
	if ( iRv >= 0 )
	{
		iRessyaIndex = getCWndDcdGrid()->getXColSpecOfFocus().getRessyaIndex() ;

		if ( 0 <= iRessyaIndex 
				&& iRessyaIndex < pCentDedRessyaCont->getMuPtr()->size() )
		{
			pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
		}
		else
		{
			iRv = -1 ;	//	フォーカスセルが、列車の位置ではありません。
		}
	}
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	フォーカスセルが、駅時刻の位置ではありません。
		}
	}
	//iRessyaIndex = フォーカスセルの列車Index
	//pCentDedRessya = フォーカスセルの列車オブジェクト
	//aJikokuOrder = フォーカスセルの時刻Order

	// --------------------------------
	//  ○[フォーカス位置の駅時刻Ourder以前に、駅時刻の入力された駅が一つもない]Ressyahensyuに遷移
	if ( iRv >= 0 )
	{
		CdDedJikokuOrder	aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
			pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
		if ( aJikokuOrderRev.getIsNull() )
		{
			iRv = -3 ;	//	フォーカス位置の駅時刻Ourder以前に、駅時刻の入力された駅が一つもない
		}
	}
	// --------------------------------
	return ( iRv ) ;		
}

void CWjkState_Renzoku::onEnter() 
{
	int iRv = 0 ;

	//	選択範囲の設定
	getCWndDcdGrid()->getCSelect()->setSelectMode( CSelect::SelectMode_NONE ) ;

	//	
	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	const Mu<const CentDedRessya*>* pMuCentDedRessya = pCentDedRessyaCont->getMuPtr() ;
	CdDcdPosXy	posFocusCell = getCWndDcdGrid()->getCFocus()->getFocusCellColumnNumber() ;
	// --------------------------------
	int iRessyaIndex = -1 ;		//	フォーカスセルの列車Index
	const CentDedRessya* pCentDedRessya = NULL ;	//	フォーカスセルの列車オブジェクト
	CdDedJikokuOrder aJikokuOrder ;	//	フォーカスセルの時刻Order
	if ( iRv >= 0 )
	{
		iRessyaIndex = getCWndDcdGrid()->getXColSpecOfFocus().getRessyaIndex() ;

		if ( iRessyaIndex >= 0 )
		{
			pCentDedRessya = pMuCentDedRessya->get( iRessyaIndex ) ;
		}
		else
		{
			iRv = -1 ;	//	フォーカスセルが、列車の位置ではありません。
		}
	}
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	フォーカスセルが、駅時刻の位置ではありません。
		}
	}
	//iRessyaIndex = フォーカスセルの列車Index
	//pCentDedRessya = フォーカスセルの列車オブジェクト
	//aJikokuOrder = フォーカスセルの時刻Order

	// --------------------------------
	//  ○[フォーカス位置の駅時刻Ourder以前に、駅時刻の入力された駅が一つもない]Ressyahensyuに遷移
	if ( iRv >= 0 )
	{
		CdDedJikokuOrder	aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
			pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
		if ( aJikokuOrderRev.getIsNull() )
		{
			iRv = -3 ;	//	フォーカス位置の駅時刻Ourder以前に、駅時刻の入力された駅が一つもない
		}
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		//	連続入力モードに入ったら、
		//	IMEをOFFにします。
		ImeControl( getCWndDcdGrid()->GetSafeHwnd() , FALSE ) ;

		m_iXColumnNumberFocus = posFocusCell.getX() ;

		update() ;
	}
	else
	{
		//	入場に失敗したら、
		//	『連続入力モード』->『列車編集モード』
		//	に遷移します。
		getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
	}

}
void CWjkState_Renzoku::onExit() 
{
	//	画面の更新(編集中マークをクリアします)
	update_updateScreen( true ) ;

	m_iXColumnNumberFocus = -1 ;
	m_strMinutes.clear() ;
}


	// ********************************
	//@name CView からの委譲
	// ********************************
void CWjkState_Renzoku::
OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC ){
		return ;
	}

	//	このビューが非アクティブで、全更新が要求されている場合は
	//	更新は行いません。
	CView *pActiveView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	if ( pActiveView != getCWndDcdGrid()->GetParent() && getCWndDcdGrid()->getUpdate_All_Requested() )
	{
		//	このビューが非アクティブで、全更新が要求されている場合は
		//	すべての更新を行いません。
		//	また、列車選択モードは退場します。
		getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
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
				//	の場合は、更新の必要がありません。
				bUpdateComplete = true ;
			}
			else if ( dynamic_castOu<CRfEditCmd_Ressya>( pCmd )	) 
			{
				//	列車の変更
				Ou<CRfEditCmd_Ressya>	pCommand = dynamic_castOu<CRfEditCmd_Ressya>( pCmd );
				if ( pCommand->getSizeDst() == pCommand->getCentDedRessyaContSrc()->size() )
				{
					//	既存列車の置換え(列車の追加・削除なし)の場合だけ、
					//	この状態で処理します。
					OnUpdate_CentDedRessya( pCommand ) ;
					bUpdateComplete = true ;
				}
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
				//CRfEditCmd_RessyaDirect
				//	列車の直通化は、列車本数の増減が発生するため、
			}
		}
		if ( !bUpdateComplete )
		{
			//	最適化更新以外
			//	モードを『列車編集』に遷移させて、
			//	OnUpdate() も委譲します。
			getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
				CWndJikokuhyou::StateIdx_Ressyahensyu ) ;

			//CWjkState* pCState = 
			//	getCWndDcdGrid()->getCStateContGet()->
			//	get( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
			//pCState->OnUpdate( pSender, lHint, pHint) ;

			OnUpdate_All() ;
		}
	}
	// --------------------------------
	//	列選択範囲を設定
	// --------------------------------
	{
		//	連続入力モードでは、選択は禁止
		getCWndDcdGrid()->getCSelect()->setSelectMode( CSelect::SelectMode_NONE ) ;
	}

	// --------------------------------
	//	カレント列の更新
	// --------------------------------
	{
		update_updateScreen() ;
	}

	super::OnUpdate(pSender,  lHint,  pHint) ;
}

// ********************************
//@name メッセージハンドラ・コマンドハンドラ
// ********************************
/**
*	時刻の文字列が何文字入力されているかを返します。
*	（時刻の文字列は、 " 000" か "0000" の形式の４バイトで、
*	未入力の位置にはスペースが入っています。（例:" 0  " ・" 90 " ））
*/
static int JikokuLen( const string& aString )
{
	if ( aString[2] == ' ' )
	{
		return 2 ;
	}
	else if ( aString[3] == ' ' )
	{
		return 3 ;
	}
	return 4 ;
}

	// ********************************
	//@name メッセージハンドラ・コマンドハンドラ-CWnd
	// ********************************
void CWjkState_Renzoku::
OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int iRv = 0 ;

	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , &pCmd ) )
		{
			iRv = -1 ;	//	フォーカスセルが列車の位置ではありません。
		}
	}
	CdDedJikokuOrder aJikokuOrder ;
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	フォーカスセルが駅時刻の位置ではありません。
		}
	}

	// ****************************************************************
	//	編集の実行
	// ****************************************************************

	// --------------------------------
	//	入力されたキー毎の解釈処理
	// --------------------------------
	if ( iRv >= 0 )
	{
		//	分の入力中のバックスペース→入力中の分を訂正
		if ( nChar == VK_BACK && m_strMinutes.length() >= 1 )
		{
			m_strMinutes.erase( m_strMinutes.length() - 1 , 1 ) ;

			//	属性の正規化と、画面の更新
			update() ;
		}
		//	分の入力がない状態でのバックスペース→前の駅に戻る
		else if ( nChar == VK_BACK && m_strMinutes.length() == 0 )
		{
			//	バックスペース
			// --------------------------------
			//	フォーカスを移動
			// --------------------------------
			//	startFocusCell() で、フォーカスを次の位置に移動します。
			//	次のフォーカス位置が『駅時刻』でないのなら、
			//	モードは
			//	『連続入力モード』->『列車編集モード』
			//	に遷移します。
			CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , -1 ) ;
			if ( pcellNext != NULL )
			{
				getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
			}
			else
			{
				//	フォーカスが駅時刻外になったら、列車編集モードに遷移
				getCWndDcdGrid()->getStateMachine()
					->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
			}

			//	属性の正規化と、画面の更新
			update() ;
		}
		//	ESCキーなら、連続入力を退場
		else if ( nChar == VK_ESCAPE )
		{	
			//	ESC
			getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
				CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}
		else
		{
			super::OnKeyDown(  nChar , nRepCnt , nFlags  ) ;
		}
	}
	if ( iRv >= 0 )
	{
		return ;
	}
	super::OnKeyDown(  nChar , nRepCnt , nFlags  ) ;
}

void CWjkState_Renzoku::
OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int iRv = 0 ;

	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , &pCmd ) )
		{
			iRv = -1 ;	//	フォーカスセルが列車の位置ではありません。
		}
	}
	CdDedJikokuOrder aJikokuOrder ;
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	フォーカスセルが駅時刻の位置ではありません。
		}
	}
	int iRessyaIndex = -1 ;
	if ( iRv >= 0 )
	{
		CdXColSpec aCdXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
		if ( aCdXColSpec.getColumnType() == CdXColSpec::ColumnType_Ressya )
		{
			iRessyaIndex = aCdXColSpec.getRessyaIndex() ;
		}
		else
		{
			iRv = -1 ;	//	フォーカスセルが列車の位置ではありません。
		}
	}
	//iRessyaIndex = フォーカスセルの列車Index
	//aCdJikokuOrder = 指定のセルに対応する『時刻Order』
	// ****************************************************************
	//	編集の実行
	// ****************************************************************
	CentDedRessya* pCentDedRessya = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 
	}
	CdDedJikokuOrder	aJikokuOrderRev ;	//	直前駅の駅時刻Order
	CdDedJikoku	jikokuRev ;					//	直前駅の駅時刻
	if ( iRv >= 0 )
	{
		aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
			pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
		if ( aJikokuOrderRev.getIsNull() )
		{
			iRv = -3 ;	//	フォーカス位置の駅時刻Ourder以前に、駅時刻の入力された駅が一つもない
		}
		else
		{
			jikokuRev = pCentDedRessya->getEkiJikoku( aJikokuOrderRev ) ;
		}
	}
	//aJikokuOrderRev =	//	直前駅の駅時刻Order
	//jikokuRev = 		//	直前駅の駅時刻
	// --------------------------------
	//	入力されたキー毎の解釈処理
	// --------------------------------
	if ( iRv >= 0 )
	{
		//	分の入力がない状態→10の位の入力を受付
		if ( m_strMinutes.length() == 0  && '0' <= nChar && nChar <= '5' )
		{
			//	分の１０の位が入力されました。
			m_strMinutes += nChar ;

			//	属性の正規化と、画面の更新
			update() ;
		}
		//	10の位のが入力された状態→1の位の入力を受付
		else if ( m_strMinutes.length() == 1 && 
			( '0' <= nChar && nChar <= '9' ) )
		{
			//	分の１の位が入力されました。
			m_strMinutes += nChar ;

			CdDedJikoku	jikokuCurrent(
				jikokuRev.getHour() ,
				intOf( m_strMinutes ) ,
				0 ) ;

			//	入力された時刻が前の駅の時刻より小さい場合は、
			//	入力時刻に１時間を加算します。
			CdDedJikan	jikanSub = jikokuCurrent.subJikoku( 
				jikokuRev ) ;
			if ( jikanSub.getTotalSeconds() < 0 )
			{
				jikokuCurrent = jikokuCurrent.getTotalSeconds() + 60*60 ;
			}


			// --------------------------------
			//	列車を取得して、編集
			// --------------------------------
			//	入力された時刻を設定
			pCentDedRessya->setEkiJikoku( jikokuCurrent , aJikokuOrder ) ;

			//	駅扱を停車に変更
			{
				CentDedEkiJikoku aCentDedEkiJikoku =
					pCentDedRessya->getCentDedEkiJikoku( aJikokuOrder.getEkiOrder() ) ;
				aCentDedEkiJikoku.setEkiatsukai( 
					CentDedEkiJikoku::Ekiatsukai_Teisya ) ;
				pCentDedRessya->setCentDedEkiJikoku( aJikokuOrder.getEkiOrder() , 
					aCentDedEkiJikoku ) ;
			}
			//pCentDedRessya = 取得した列車のコピーに対して、
			//	駅時刻の編集を行いました。

			// --------------------------------
			//	コマンドオブジェクトを実行
			// --------------------------------
			{
				getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			}

			// --------------------------------

			//	分を削除
			m_strMinutes.clear()  ;

			// --------------------------------
			//	フォーカスを移動
			// --------------------------------
			//	startFocusCell() で、フォーカスを次の位置に移動します。
			//	次のフォーカス位置が『駅時刻』でないのなら、
			//	モードは
			//	『連続入力モード』->『列車編集モード』
			//	に遷移します。
			CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
			if ( pcellNext != NULL )
			{
				getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
			}
			else
			{
				//	フォーカスが駅時刻外になったら、列車編集モードに遷移
				getCWndDcdGrid()->getStateMachine()
					->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
			}

			// --------------------------------
			//	属性の正規化と、画面の更新
			update() ;
		}
		else
		{
			super::OnChar(  nChar , nRepCnt , nFlags  ) ;
		}

	}
	if ( iRv >= 0 )
	{
		return ;
	}

	super::OnChar(  nChar , nRepCnt , nFlags  ) ;
}

// --------------------------------
int CWjkState_Renzoku::
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
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		{
			CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 


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
		//	startFocusCell() で、フォーカスを次の位置に移動します。
		//	次のフォーカス位置が『駅時刻』でないのなら、
		//	モードは
		//	『連続入力モード』->『列車編集モード』
		//	に遷移します。
		CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
		if ( pcellNext != NULL )
		{
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
		}
		else
		{
			//	フォーカスが駅時刻外になったら、列車編集モードに遷移
			getCWndDcdGrid()->getStateMachine()
				->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}

		//	属性の正規化と、画面の更新
		update() ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Renzoku::
	OnJikokuhyouTsuuka_Process( BOOL bQueryEnable )
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
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		{
			CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 

			CentDedEkiJikoku aCentDedEkiJikoku =
				pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;
			aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Tsuuka ) ;

			//	駅時刻もNULLにする
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
		//	startFocusCell() で、フォーカスを次の位置に移動します。
		//	次のフォーカス位置が『駅時刻』でないのなら、
		//	モードは
		//	『連続入力モード』->『列車編集モード』
		//	に遷移します。
		CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
		if ( pcellNext != NULL )
		{
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
		}
		else
		{
			//	フォーカスが駅時刻外になったら、列車編集モードに遷移
			getCWndDcdGrid()->getStateMachine()
				->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}

		//	属性の正規化と、画面の更新
		update() ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Renzoku::
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
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	コマンドオブジェクトの列車を編集
		// --------------------------------
		{
			CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 
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
		//	startFocusCell() で、フォーカスを次の位置に移動します。
		//	次のフォーカス位置が『駅時刻』でないのなら、
		//	モードは
		//	『連続入力モード』->『列車編集モード』
		//	に遷移します。
		CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
		if ( pcellNext != NULL )
		{
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
		}
		else
		{
			//	フォーカスが駅時刻外になったら、列車編集モードに遷移
			getCWndDcdGrid()->getStateMachine()
				->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}

		//	属性の正規化と、画面の更新
		update() ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
		
	
}


int CWjkState_Renzoku::
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , ppCmd ) )
		{
			iRv = -1 ;	//	列車選択位置が正しくありません。
		}
	}
	CdDedJikokuOrder	aJikokuOrder ;
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	フォーカスセルが駅時刻の位置ではありません。
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
	// --------------------------------
	//□＜12.3＞連続入力時の[発着]表示の駅の発時刻に対する
	//	[経由なし]コマンド動作を無効にする
	// --------------------------------
	//　従来、時刻表ビューの連続入力モードで、発着表示の駅の
	//	着に時刻を入れる
	//	発に[経由なし]を指定する
	//と、発時刻と同時に着時刻も[経由なし]によって時刻が消されてしまう問題がありました　
	//　これを避けるため、時刻表ビューの連続入力モード時には、以下のルールを適用します。
	//　フォーカスセル位置が[発着]表示の駅の[発時刻]にある状態で、
	//	メニューコマンド[駅時刻]−[経由なし]（または、 "=" キー）を入力したとき、その駅の駅時刻は
	//	[経由なし]にしません（変更を行いません）。このとき、フォーカスセルは次の駅に移します。
	bool bSkip = false ;
	if ( iRv >= 0 ){
		const Mu<CentDedEkiCont::CdDedEki>* pCdDedEkiContGet = 
			getCDiagramEditDoc()->getCDedRosenFileData()->
			getCentDedRosen()->getCentDedEkiCont()->getMuPtr( getRessyahoukou() ) ;
		CentDedEkiCont::CdDedEki	aCdDedEki = pCdDedEkiContGet->get( aJikokuOrder.getEkiOrder() ) ;
		if ( aCdDedEki.isHatsuChakuHyouji() && 
			aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
		{
			bSkip = true ;
		}
	}
	//bSkip = 今回のフォーカスセルに対する　[経由なし]は
	//	無効とします（フォーカスは次に移します）。

	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		if ( !bSkip )
		{
			// --------------------------------
			//	コマンドオブジェクトの列車を編集
			// --------------------------------
			{
				CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 

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
		}
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		//	startFocusCell() で、フォーカスを次の位置に移動します。
		//	次のフォーカス位置が『駅時刻』でないのなら、
		//	モードは
		//	『連続入力モード』->『列車編集モード』
		//	に遷移します。
		CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
		if ( pcellNext != NULL )
		{
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
		}
		else
		{
			//	フォーカスが駅時刻外になったら、列車編集モードに遷移
			getCWndDcdGrid()->getStateMachine()
				->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}

		//	属性の正規化と、画面の更新
		update() ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;				


}



int CWjkState_Renzoku::
	OnJikokuhyouRenzoku_Process( BOOL bQueryEnable )
{
	int iRv = 1 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	CWjkState* pCState = 
		getCWndDcdGrid()->getStateMachine()->getCStateContGet()->get( 
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
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
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;
}


	// ********************************
	//@name	CWndDcdGrid
	// ********************************
void CWjkState_Renzoku::OnSetFocusCell( 
	CDcdGridCell* pCDcdGridCell ) 
{
	//	フォーカスセルが移動した場合は、
	//	入力中の分はクリア
	m_strMinutes.clear() ;

	update() ;
	super::OnSetFocusCell( pCDcdGridCell ) ; 
} 

void CWjkState_Renzoku::OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) 
{
	super::OnChangeSelectCell( 
		iXColumnNumber , iYColumnNumber , bIsSelected ); 
}

} } // namespace WndJikokuhyou namespace ViewJikokuhyou
