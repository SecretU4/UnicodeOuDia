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
// CWndSplitBarV.cpp : インプリメンテーション ファイル
//

#include "CWndSplitBarV.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace OuMfc{
namespace FrameLeftPane{

/////////////////////////////////////////////////////////////////////////////
// CWndSplitBarV

// ********************************
//@param	構築
// ********************************
BOOL CWndSplitBarV::Create( CWnd* pParentWnd, 
			CWnd* pwndLeftPane ,
			UINT nID)
{
	BOOL	bRv = TRUE ;

	m_pwndLeftPane = pwndLeftPane ;
	
	CRect	aCRect( 0 , 0 , 
		GetSystemMetrics( SM_CXEDGE ) * 2 , 
		GetSystemMetrics( SM_CYEDGE ) * 2 ) ;

	CString	strClassName = AfxRegisterWndClass( 0 , 
		LoadCursor( NULL , IDC_SIZEWE ) , 
		NULL , NULL ) ;
	
	bRv = CWnd::Create( strClassName , _T("CWndSplitBarV"), 
		WS_CHILD | WS_VISIBLE , 
		aCRect, pParentWnd, nID, NULL);

	return ( bRv ) ;
}
//SM_CXEDGE,
//SM_CYEDGE 立体効果付きのウィンドウの境界線の幅と高さを取得します。SM_CXBORDER と SM_CYBORDER の 3D 版です。 

// ********************************
//@param	操作
// ********************************

void CWndSplitBarV::CMDIFrameWnd_RecalcLayout(
		CMDIFrameWnd* pCMDIFrameWnd ,
		CWnd* pwndLeftPane ,
		CWndSplitBarV* pCWndSplitBarV ,
		BOOL bNotify ) 

{
	CWnd*	wndMDIClient = pCMDIFrameWnd->GetDlgItem( AFX_IDW_PANE_FIRST ) ;
	//wndMDIClient=MDIClient のオブジェクト

	// --------------------------------
	//	この操作を行う間は、
	//	MDIClient ウインドウを非表示に
	//	しなくてななりません。
	//	ただし、すでに MDIClient が
	//	非表示である場合は、その状態は
	//	変更しません（PrintPreviewを
	//	表示している場合が、これにあたります）
	// --------------------------------
	bool	bMDIClientMustShow = false ;
	if ( wndMDIClient != NULL ){
		if ( wndMDIClient->IsWindowVisible() ){
			wndMDIClient->ShowWindow( SW_HIDE ) ;

			bMDIClientMustShow = true ;
		}
	}
	
	// --------------------------------
	//	基本クラスの実装で、
	//	MDIClient ウインドウを配置
	// --------------------------------
	pCMDIFrameWnd->CMDIFrameWnd::RecalcLayout(bNotify);

	// --------------------------------
	if ( pwndLeftPane->GetSafeHwnd() == NULL ||
		pCWndSplitBarV->GetSafeHwnd() == NULL ){

		// --------------------------------
		//	この操作を行う間は、
		//	MDIClient ウインドウを非表示に
		//	しなくてななりません。
		// --------------------------------
		if ( bMDIClientMustShow ){
			wndMDIClient->ShowWindow( SW_SHOW ) ;
		}
		return ;
	}


	//	この時点では、MDIClient の位置とサイズは、
	//	左側ペインと、スプリットバーがない状態の
	//	ものになっています。

	// --------------------------------
	//	各ウインドウの現在の位置を取得
	// --------------------------------
	CRect	rectMDIClient ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		wndMDIClient->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectMDIClient = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	CRect	rectLeftpane ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		pwndLeftPane->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectLeftpane = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	CRect	rectSplitBarV ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		pCWndSplitBarV->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectSplitBarV = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	//rectMDIClient=MDIClient の位置とサイズ
	//	(左側ペインと、スプリットバーがない状態)
	//rectLeftpane = LeftPaneの現在の位置
	//rectSplitBarV = SplitBarVの現在の位置



	// --------------------------------
	//	各ウインドウの新しい位置を算定
	// --------------------------------
	CRect	rectLeftpaneNew ;
	{
		rectLeftpaneNew = rectLeftpane  ;
		rectLeftpaneNew.left = rectMDIClient.left ;
		rectLeftpaneNew.right = rectLeftpaneNew.left + rectLeftpane.Width() ;
		if ( rectLeftpaneNew.right >= rectMDIClient.right - rectSplitBarV.Width() ){
			rectLeftpaneNew.right = rectMDIClient.right - rectSplitBarV.Width() ;
		}
		rectLeftpaneNew.top = rectMDIClient.top ;
		rectLeftpaneNew.bottom = rectMDIClient.bottom ;
	}
	CRect	rectSplitBarVNew ;
	{
		rectSplitBarVNew = rectSplitBarV ;
		rectSplitBarVNew.left = rectLeftpaneNew.right ;
		rectSplitBarVNew.right = rectSplitBarVNew.left + rectSplitBarV.Width() ;
		rectSplitBarVNew.top = rectMDIClient.top ;
		rectSplitBarVNew.bottom = rectMDIClient.bottom ;
	}
	CRect	rectMDIClientNew  ;
	{
		rectMDIClientNew = rectMDIClient  ;
		rectMDIClientNew.left = rectSplitBarVNew.right  ;
		if ( rectMDIClientNew.right < rectMDIClientNew.left ){
			rectMDIClientNew.right = rectMDIClientNew.left ; 
		}
		

	}
	//rectLeftpaneNew=左側ペインの の位置とサイズ
	//rectSplitBarVNew=スプリットバーの位置とサイズ
	//rectMDIClientNew=MDIClient の位置とサイズ
	//	(左側ペインと、スプリットバーの領域を確保したサイズ)

	// --------------------------------
	//	各ウインドウの新しい位置を設定
	// --------------------------------
	pwndLeftPane->SetWindowPos( NULL , 
		rectLeftpaneNew.left , 
		rectLeftpaneNew.top , 
		rectLeftpaneNew.Width() , 
		rectLeftpaneNew.Height() , 
		SWP_NOZORDER ) ;   
	pCWndSplitBarV->SetWindowPos( NULL , 
		rectSplitBarVNew.left , 
		rectSplitBarVNew.top , 
		rectSplitBarVNew.Width() , 
		rectSplitBarVNew.Height() , 
		SWP_NOZORDER ) ;   
	wndMDIClient->SetWindowPos( NULL , 
		rectMDIClientNew.left , 
		rectMDIClientNew.top , 
		rectMDIClientNew.Width() , 
		rectMDIClientNew.Height() , 
		SWP_NOZORDER ) ;   

	// --------------------------------
	//	この操作を行う間は、
	//	MDIClient ウインドウを非表示に
	//	しなくてななりません。
	// --------------------------------
	if ( bMDIClientMustShow ){
		wndMDIClient->ShowWindow( SW_SHOW ) ;
	}
}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
CWndSplitBarV::CWndSplitBarV() :
	m_pwndLeftPane( NULL ) , m_iDragPosX( -1 ) 
{
}

CWndSplitBarV::~CWndSplitBarV()
{
}


BEGIN_MESSAGE_MAP(CWndSplitBarV, CWnd)
	//{{AFX_MSG_MAP(CWndSplitBarV)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CWndSplitBarV メッセージ ハンドラ

void CWndSplitBarV::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	
	CRect	rectClient ;
	GetClientRect( &rectClient ) ;
	// 描画用メッセージとして CWnd::OnPaint() を呼び出してはいけません

	{
		CRect	rectFill = rectClient ;
		rectClient.right = rectClient.left + 1 ;
		FillRect(  dc.GetSafeHdc() , &rectFill , GetSysColorBrush( COLOR_3DLIGHT ) ) ;
	}
	{
		CRect	rectFill = rectClient ;
		rectClient.left  = rectClient.left + 1 ;
		rectClient.right = rectClient.right - 1 ;
		FillRect(  dc.GetSafeHdc() , &rectFill , GetSysColorBrush( COLOR_3DFACE ) ) ;
	}

	{
		CRect	rectFill = rectClient ;
		rectClient.left  = rectClient.right - 1 ;
		FillRect(  dc.GetSafeHdc() , &rectFill , GetSysColorBrush( COLOR_3DSHADOW ) ) ;
	}

//COLOR_3DDKSHADOW 3D オブジェクトの暗い影の色。 
//COLOR_3DFACE, COLOR_BTNFACE 3D オブジェクトの表面色と、ダイアログボックスの背景色。 
//COLOR_3DHILIGHT, COLOR_3DHIGHLIGHT, COLOR_BTNHILIGHT, COLOR_BTNHIGHLIGHT 3D オブジェクトの最も明るい色（光源に面した辺）。 
//COLOR_3DLIGHT 3D オブジェクトの明るい色（光源に面した辺）。 
//COLOR_3DSHADOW, COLOR_BTNSHADOW 3D オブジェクトの影の色（光源に面していない辺）。 



}


void CWndSplitBarV::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_iDragPosX = point.x ;
	SetCapture() ;
	
	//CWnd::OnLButtonDown(nFlags, point);
}

void CWndSplitBarV::OnLButtonUp(UINT nFlags, CPoint point) 
{
	ReleaseCapture() ;
	m_iDragPosX = -1 ;
	
	//CWnd::OnLButtonUp(nFlags, point);
}

void CWndSplitBarV::OnMouseMove(UINT nFlags, CPoint point) 
{
	//CWnd::OnMouseMove(nFlags, point);


	if ( ( nFlags & MK_LBUTTON ) != MK_LBUTTON ){
		if ( m_iDragPosX != -1 ){
			ReleaseCapture() ;
			m_iDragPosX = -1 ;
		}
	} 
	if ( m_iDragPosX == -1 ){
		return ;
	}
	// --------------------------------
	//	各ウインドウの現在の位置を取得
	// --------------------------------
	CWnd*	wndMDIClient = GetParent()-> GetDlgItem( AFX_IDW_PANE_FIRST ) ;

	CRect	rectMDIClient ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		wndMDIClient->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectMDIClient = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	CRect	rectLeftpane ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		m_pwndLeftPane->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectLeftpane = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	CRect	rectSplitBarV ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectSplitBarV = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	//rectMDIClient=MDIClient の位置とサイズ
	//	(左側ペインと、スプリットバーがない状態)
	//rectLeftpane = LeftPaneの現在の位置
	//rectSplitBarV = SplitBarVの現在の位置

	// --------------------------------
	//	各ウインドウの新しい位置を算定
	// --------------------------------
	CRect	rectSplitBarVNew ;
	{
		rectSplitBarVNew = rectSplitBarV ;
		rectSplitBarVNew.left = rectSplitBarV.left + ( point.x - m_iDragPosX ) ;
		if ( rectSplitBarVNew.left < rectLeftpane.left ){
			rectSplitBarVNew.left = rectLeftpane.left ;
		}
		if ( rectSplitBarVNew.left > rectMDIClient.right - rectSplitBarV.Width() ){
			rectSplitBarVNew.left = rectMDIClient.right - rectSplitBarV.Width() ;
		}
		rectSplitBarVNew.right = rectSplitBarVNew.left + rectSplitBarV.Width() ;
	}
	CRect	rectLeftpaneNew ;
	{
		rectLeftpaneNew = rectLeftpane  ;
		rectLeftpaneNew.right = rectSplitBarVNew.left ;
	}
	CRect	rectMDIClientNew  ;
	{
		rectMDIClientNew = rectMDIClient  ;
		rectMDIClientNew.left = rectSplitBarVNew.right  ;
	}
	// --------------------------------
	//	各ウインドウの新しい位置を設定
	// --------------------------------
	m_pwndLeftPane->SetWindowPos( NULL , 
		rectLeftpaneNew.left , 
		rectLeftpaneNew.top , 
		rectLeftpaneNew.Width() , 
		rectLeftpaneNew.Height() , 
		SWP_NOZORDER ) ;   
	SetWindowPos( NULL , 
		rectSplitBarVNew.left , 
		rectSplitBarVNew.top , 
		rectSplitBarVNew.Width() , 
		rectSplitBarVNew.Height() , 
		SWP_NOZORDER ) ;   
	wndMDIClient->SetWindowPos( NULL , 
		rectMDIClientNew.left , 
		rectMDIClientNew.top , 
		rectMDIClientNew.Width() , 
		rectMDIClientNew.Height() , 
		SWP_NOZORDER ) ;   



	
}

} //namespace FrameLeftPane
} //namespace OuMfc
