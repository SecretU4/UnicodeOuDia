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
// CJikokuhyouView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"

#include "NsOu/OuNew.h"
#include "str/strToInt.h"
#include "DcDraw/CDcdLine.h"
#include "DcDraw/CDcdTargetPrinter.h"
#include "DcDraw/CDcDeviceUnitSizeX.h"
#include "DcDraw/CDcDeviceUnitSizeY.h"
#include "DcDraw/CDcdText.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/CConverter_WinGdi.h"
#include "DcDraw/print/CaDcdTargetZoomDisplay.h"
#include "DcDrawMfc/CDcdTargetMfcPrintInfo.h"
#include "DcdGrid\WndDcdGrid3\WndDcdGrid3.h"
#include "DcdGrid\CaDcdGrid_PageSelector.h"
#include "LogMsg\LogMsg.h"

#include "..\DiagramEdit.h"
#include "..\Print\CconvCdPrintPageProp.h"
#include "CJikokuhyouView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

using namespace std ;
using namespace DcDrawLib::DcDrawMfc;
using namespace DcDrawLib::DcDraw::Print;

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouView
// --------------------------------
//@name 下請関数
// --------------------------------
// ********************************
//@name 操作
// ********************************
int CJikokuhyouView::setFocusToRessyaIndex( int iRessyaIdx  , int iEkiOrder ) 
{
	int iRv = 0 ;

	CdXColSpecCont aXColSpecCont = m_pCWndDcdGrid->createXColSpecCont() ;


	int iXColumnNumber = aXColSpecCont.ColumnNumberFromSpec( 
		CdXColSpec( 
			CdXColSpec::ColumnType_Ressya , iRessyaIdx ) ) ;
	if ( iRv >= 0 )
	{
		if ( iXColumnNumber < 0  )
		{
			iRv = -1 ;
		}
	}
	if ( iRv >= 0 )
	{
		CdYColSpecCont aYColSpecCont = m_pCWndDcdGrid->createYColSpecCont() ;

		int iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec(
			CdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
				iEkiOrder ) , false ) ;
		if ( iYColumnNumber < 0 )
		{
			iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec(
				CdYColSpec( 
					CdYColSpec::ColumnType_Ekijikoku_Chaku , 
					iEkiOrder ) , false ) ;
		}
		if ( iYColumnNumber < 0 )
		{
			iYColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getYColumnNumberOfCell( 
				m_pCWndDcdGrid->getCFocus()->getFocusCell() )  ;
		}

		CDcdGridCell* pCell = m_pCWndDcdGrid->getCXDcdGrid()->getCell( 
			iXColumnNumber , iYColumnNumber ) ;
		if ( pCell != NULL )
		{
			m_pCWndDcdGrid->getCFocus()->setFocusCell( pCell )  ;
		}
	}
	return ( iRv ) ;
}

// ----------------------------------------------------------------

IMPLEMENT_DYNCREATE(CJikokuhyouView, CView)

CJikokuhyouView::CJikokuhyouView()
	: m_pCWndDcdGrid( NULL ) 
{
}

CJikokuhyouView::~CJikokuhyouView()
{
}


BEGIN_MESSAGE_MAP(CJikokuhyouView, CView)
	//{{AFX_MSG_MAP(CJikokuhyouView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouView 描画

void CJikokuhyouView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
}

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouView 診断

#ifdef _DEBUG
void CJikokuhyouView::AssertValid() const
{
	CView::AssertValid();
}

void CJikokuhyouView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouView メッセージ ハンドラ

int CJikokuhyouView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_pCWndDcdGrid = new CWndJikokuhyou() ;
	m_pCWndDcdGrid->Create( this ) ;
	m_pCWndDcdGrid->ShowWindow( SW_SHOW ) ;
	
	return 0;
}

void CJikokuhyouView::OnDestroy() 
{
	//	ダイヤグラムビューの属性を .ini ファイルに書き込み。
	getCDiagramEditApp()->writeCWndJikokuhyouViewProp( m_pCWndDcdGrid ) ;
	if ( m_pCWndDcdGrid != NULL )
	{
		m_pCWndDcdGrid->DestroyWindow() ;
		delete m_pCWndDcdGrid ;
		m_pCWndDcdGrid = NULL ;	
	}
	CView::OnDestroy();
}

void CJikokuhyouView::OnSize(UINT nType, int cx, int cy) 
{
	if ( nType == SIZE_MAXIMIZED   //ウィンドウは最大表示されます。
		|| nType == SIZE_RESTORED  // ウィンドウはサイズ変更されますが、SIZE_MINIMIZED と SIZE_MAXIMIZED は適用されません。
	){
		m_pCWndDcdGrid->MoveWindow( 0 , 0 , cx , cy , TRUE ) ;
		return ;
	}
	
	CView::OnSize(nType, cx, cy);
	
}

void CJikokuhyouView::OnSetFocus(CWnd* pOldWnd) 
{
	//CView::OnSetFocus(pOldWnd);
	CWnd*	pControl = GetNextDlgTabItem( (CWnd*)NULL , FALSE ) ;
	pControl->SetFocus() ;
	
}

void CJikokuhyouView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC ){
		return ;
	}
	// --------------------------------
	m_pCWndDcdGrid->OnUpdate( pSender, lHint, pHint) ;
}


BOOL CJikokuhyouView::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	//	コマンドハンドラは、可能なら CWndDcdGrid に委譲します。
	if ( m_pCWndDcdGrid != NULL && 
		m_pCWndDcdGrid->OnCmdMsg( nID, nCode, pExtra, pHandlerInfo) )
	{
		return ( TRUE ) ;
	} 

	
	return CView::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CJikokuhyouView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	
}

BOOL CJikokuhyouView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	// デフォルトの印刷準備
	return DoPreparePrinting( pInfo ) ;
	//return CView::OnPreparePrinting(pInfo);
}

void CJikokuhyouView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	//	この時点では、 
	//	pInfo->m_rectDraw
	//	の値は決定していません。

	//	状態を、列車編集モードに変更
	m_pCWndDcdGrid->getStateMachine()->setCurrentStateIdx( 
		m_pCWndDcdGrid->StateIdx_Ressyahensyu ) ;


	//	このビューをアクティブにして、更新
	getCDiagramEditApp()->getCMainFrame()->MDIActivate( GetParent() ) ;
	m_pCWndDcdGrid->OnUpdate( NULL , 0 , NULL ) ;
	

	CView::OnBeginPrinting(pDC, pInfo);
}

void CJikokuhyouView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	//	この時点では、 
	//	pInfo->m_rectDraw
	//	の値は決定していません。

	if ( pInfo != NULL ){
		//	印刷に関する処理
		LogMsg( "CJikokuhyouView::OnPrepareDC() " ) ;
		LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;

		//	複数ページの印刷を行う場合は、
		//CView::OnPrepareDC(pDC, pInfo);
		//	を呼び出してはいけません。
	}	else	{
		CView::OnPrepareDC(pDC, pInfo);
	}
}

/**
@return
	時刻表ビューの印刷時の、キャプション
	(上部のタイトル・下部のページ番号)のための
	フォント属性を返します。
*/
static CdDrawTextProp	getCdDrawTextPropStandard()
{ 
	const CDedRosenFileData* pCDedRosenFileData = 
		getCDiagramEditDoc()->getCDedRosenFileData() ;
	CdDedDispProp aCdDedDispProp = pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		aCdDedDispProp.getJikokuhyouFont(0) ,
		CdColorProp( 0 , 0 , 0 ) ) ;
}

void CJikokuhyouView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	LogMsg( "CJikokuhyouView::OnPrint() " ) ;
	LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;

	// --------------------------------
	//	描画面を作成
	// --------------------------------
	CDcdTargetMfcPrintInfo	aCDcdTargetMfcPrintInfo( pDC, pInfo ) ;

	LogMsg( "CJikokuhyouView::OnPrint()1" ) ;
	// --------------------------------
	//	余白を除いた領域を作成
	// --------------------------------
	CaDcdTargetItemPosition	aTargetInnerMargin( &aCDcdTargetMfcPrintInfo , 
		CdDcdZoneXy() ) ;
	{
		LogMsg( DeviceCapsToString( 
			aCDcdTargetMfcPrintInfo.getPrinterHdc() ).c_str() ) ;
	
		CconvCdPrintPageProp aCconvCdPrintPageProp ;
		CdDcdZoneXy	zonexyInneraMargin = 
			aCconvCdPrintPageProp.calcZoneInnerMargin( 
				getCDiagramEditApp()->getCdPrintPageProp() , 
				aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
		if ( zonexyInneraMargin.getX().getSize() <= 0 ){
			zonexyInneraMargin.setX( 
				aCDcdTargetMfcPrintInfo.getZone().getX() ) ;
		}
		if ( zonexyInneraMargin.getY().getSize() <= 0 ){
			zonexyInneraMargin.setY( 
				aCDcdTargetMfcPrintInfo.getZone().getY() ) ;
		}

		aTargetInnerMargin.setZone( zonexyInneraMargin ) ;

	}

	//aTargetInnerMargin = 余白部分を除いた描画領域。
	//	単位はプリンタのピクセルです。

	LogMsg( "CJikokuhyouView::OnPrint()2" ) ;
	// --------------------------------
	//	論理座標を設定
	// --------------------------------
	CaDcdTargetZoomDisplay	aCaDcdTargetZoomDisplay( 
		&aTargetInnerMargin , 
		aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
	//aCaDcdTargetZoomDisplay = 余白部分を除いた描画領域。
	//	単位は、画面上の１ピクセル相当になりました。

	LogMsg( "CJikokuhyouView::OnPrint()3" ) ;
	// --------------------------------
	//	キャプションとページ番号の部品を作成
	// --------------------------------
	Ou<CDcdText>	pdcdCaption ;
	Ou<CDcdText>	pdcdPage ;
	{
		const CentDedRosen* pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		CJikokuhyouDoc* pCJikokuhyouDoc = (CJikokuhyouDoc*)GetDocument() ;

		string	strText ;
		//	路線名
		if ( !pCentDedRosen->getName().empty() ){
			strText += pCentDedRosen->getName() ;
			strText += " " ;
		}
		//	ダイヤ名
		if ( !pCJikokuhyouDoc->getDiaName().empty() ){
			strText += pCJikokuhyouDoc->getDiaName() ;
			strText += " " ;
		}
		//	方向
		{
			CString	strHoukou ;
			if ( pCJikokuhyouDoc->getRessyahoukou() == Ressyahoukou_Kudari ){
				strHoukou.LoadString( IDS_WORD_Kudari ) ;
			}	else	{
				strHoukou.LoadString( IDS_WORD_Nobori ) ;
			}
			strText += (LPCTSTR)strHoukou ;
			strText += " " ;
		}

		pdcdCaption = OuNew<CDcdText>( new CDcdText( 
			strText , getCdDrawTextPropStandard() ) ) ;
	}
	// --------------------------------
	{
		CdDrawTextProp	aProp = getCdDrawTextPropStandard() ;
		CdDrawTextFormat	aFormat = aProp.getCdDrawTextFormat() ;
		aFormat.setHorizontal( aFormat.H_CENTER ) ;
		aProp.setCdDrawTextFormat( aFormat ) ;
		pdcdPage = OuNew<CDcdText>( new CDcdText( "" ,aProp , "99" ) ) ;
	}

	LogMsg( "CJikokuhyouView::OnPrint()4" ) ;
	// --------------------------------
	//	キャプションとページ番号の部品・
	//	グリッドのレイアウトを決める	
	// --------------------------------
	Ou<IfDcdTarget>	pTargetCaption ;
	Ou<IfDcdTarget>	pTargetGrid ;
	Ou<IfDcdTarget>	pTargetPage ;
	{
		CdDcdZoneXy	zoneGrid = aCaDcdTargetZoomDisplay.getZone() ;
		CdDcdSizeXy	aSize ;

		pdcdCaption->getItemSize( &aCaDcdTargetZoomDisplay , &aSize ) ;
		CdDcdZoneXy zoneCaption( zoneGrid.getX() , 
			CdDcdZone( zoneGrid.getY().getPos() , aSize.getY() ) ) ;
		zoneGrid.setY( CdDcdZone().setBeginEndPos( 
			zoneCaption.getY().getEndPos() , zoneGrid.getY().getEndPos() ) ) ;
		//zoneCaption = 全領域の上部を、キャプション用に割り当てています。
		//zoneGrid = 全領域から、上部のキャプション領域を除いた領域です。

		pdcdPage->getItemSize( &aCaDcdTargetZoomDisplay , &aSize ) ;
		CdDcdZoneXy zonePage( zoneGrid.getX() , 
			CdDcdZone( zoneGrid.getY().getEndPos() - aSize.getY() , aSize.getY() ) ) ;
		zoneGrid.setY( CdDcdZone().setBeginEndPos( 
			zoneCaption.getY().getEndPos() , zonePage.getY().getPos() ) ) ;
		//zonePage = 全領域の下部を、ページ用に割り当てています。
		//zoneGrid = 上部のキャプションに続いて、下部のページ領域も除いた領域です。


		pTargetCaption = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( &aCaDcdTargetZoomDisplay , zoneCaption ) ) ;
		pTargetGrid = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( &aCaDcdTargetZoomDisplay , zoneGrid ) ) ;
		pTargetPage = OuNew<CaDcdTargetItemPosition>(
			new CaDcdTargetItemPosition( &aCaDcdTargetZoomDisplay , zonePage ) ) ;
	}


	LogMsg( "CJikokuhyouView::OnPrint()5" ) ;
	// --------------------------------
	//	グリッドを描画
	// --------------------------------
	int iPage = 0 ;
	int iXPage = 0 ;
	{
		//	印刷時には、スクロールバーが動作しないようにします。
		//	スクロールと再描画を抑止します。
		CPropStack	aPropStack( m_pCWndDcdGrid ) ;
		aPropStack.CDcdGrid_setUpdateCWndDcdGrid( false )
			.CFocus_setFixafterColumnNumberChange( false );
			

		CDcdGrid*	pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
		CaDcdGrid_PageSelector	aCaDcdGrid_PageSelector( pCDcdGrid , pTargetGrid ) ;

		if ( (int)pInfo->m_nCurPage > aCaDcdGrid_PageSelector.getPageCount() ){
			//	ページ番号が大きすぎます。
			//	この場合は、印刷は中断します。	
			pInfo->m_bContinuePrinting = false ;
			return ;
		}
			
		aCaDcdGrid_PageSelector.setPage( pInfo->m_nCurPage - 1 ) ;
		aCaDcdGrid_PageSelector.DcDraw() ;


		//OnPrint() で 
		//pInfo->SetMaxPage( aCaDcdGrid_PageSelector.getPageCount() ) ;
		//	をしても効果はありません。
		//	(印刷ループは、OnBeginPrinting() 終了時点の
		//	値をもとに行われるからです)
		pInfo->SetMinPage( 1 ) ;
		pInfo->SetMaxPage( aCaDcdGrid_PageSelector.getPageCount() ) ;

		if ( (int)pInfo->m_nCurPage >= aCaDcdGrid_PageSelector.getPageCount() ){
			//最終ページを印刷したら、印刷ループを終わります。
			//OnPrint() で 
			//pInfo->SetMaxPage( aCaDcdGrid_PageSelector.getPageCount() ) ;
			//	をしても効果はありません。

			pInfo->m_bContinuePrinting = false ;
		}	else	{
			pInfo->m_bContinuePrinting = true ;
		}


		iPage = aCaDcdGrid_PageSelector.getPage() ;
		iXPage = aCaDcdGrid_PageSelector.getXPage() ;
	}

	LogMsg( "CJikokuhyouView::OnPrint()6" ) ;
	// --------------------------------
	//	キャプションとページ番号のテキストを作成
	// --------------------------------
	{
		//キャプションにページを追加
		{
			string	strCaption = pdcdCaption->getText() ;
			CString	strSono ;
			strSono.Format( IDS_WORD_Sono , iXPage + 1 ) ;
			strCaption += (LPCTSTR)strSono ;
			strCaption += " " ;
			pdcdCaption->setText( strCaption ) ;
		}
		//ページ番号も決定
		{
			string	strPage = stringOf( iPage + 1) ;
			pdcdPage->setText( strPage ) ;
		}
	}

	LogMsg( "CJikokuhyouView::OnPrint()7" ) ;
	// --------------------------------
	//	キャプションとページ番号を描画
	// --------------------------------
	{
			pdcdCaption->DcDraw( pTargetCaption ) ;
			pdcdPage->DcDraw( pTargetPage ) ;
	}
	// --------------------------------
	//CView::OnPrint(pDC, pInfo);
}

void CJikokuhyouView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	//	印刷終了後に画面表示が崩れる問題を回避。
	//
	//	このクラスは、印刷中はグリッドのスクロール位置を
	//	一時的に変更します。
	//	このときに m_pCWndDcdGrid に再描画が発生すると、
	//	画面には一時的に位置の変更されたグリッドが
	//	描画されるため、画面が崩れます。
	m_pCWndDcdGrid->InvalidateGrid() ;

	// --------------------------------
	CView::OnEndPrinting(pDC, pInfo);
}


void CJikokuhyouView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	if ( m_pCWndDcdGrid != NULL )
	{
		m_pCWndDcdGrid->OnActivateView( bActivate, pActivateView, pDeactiveView ) ;
	}
	//CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
} //namespace ViewJikokuhyou
