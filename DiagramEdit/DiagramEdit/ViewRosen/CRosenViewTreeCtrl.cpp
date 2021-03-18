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
// ****************************************************************
//	$Id: CRosenViewTreeCtrl.cpp 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
#include "stdafx.h"
#include "TreeCtrl\CaTreeCtrl.h"

#include "CDlgRosenView.h"
#include "CRosenViewTreeCtrl.h"
#include "..\resource.h"

namespace ViewRosen{

// CTreeCtrlContextMenu
using OuMfc::TreeCtrl::CaTreeCtrl ;

BOOL CRosenViewTreeCtrl::OnContextMenu_TrackPopupMenu( 
	CWnd* pWnd, 
	HTREEITEM htItem ,
	int x , int y ) 
{
	BOOL bRv = FALSE ;
	CaTreeCtrl	aCaTreeCtrl( this ) ;
	CaTreeCtrl::Itemlocation aItemPos ;
	aCaTreeCtrl.HTREEITEM_to_Itemlocation( htItem , &aItemPos ) ;

	CDlgRosenView* pDlgRosenView = (CDlgRosenView*)GetParent() ;

	//	路線
	if ( aItemPos.size() == 1 && 
			aItemPos[0] == 0 )
	{
		m_itemContextMenu = htItem ;
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_ROSENVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( 0 ) ;
		//pContextMenu->SetDefaultItem( 0 , TRUE ) ;
		pContextMenu->TrackPopupMenu( TPM_LEFTALIGN , x , y , AfxGetMainWnd() ) ;

		bRv = TRUE ;
	}
	//	駅
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 0 )
	{
		m_itemContextMenu = htItem ;
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_ROSENVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( 1 ) ;
		//pContextMenu->SetDefaultItem( 0 , TRUE ) ;
		UINT uiRet = pContextMenu->TrackPopupMenu( TPM_LEFTALIGN | TPM_RETURNCMD , 
			x , y , pWnd ) ;
		if ( uiRet == ID_MENUITEM_OPEN ) 
		{
			pDlgRosenView->onEnterItem( htItem , 1 ) ;
		}
		bRv = TRUE ;
	}
	//	列車種別
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 1 )
	{
		m_itemContextMenu = htItem ;
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_ROSENVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( 2 ) ;
		//pContextMenu->SetDefaultItem( 0 , TRUE ) ;
		UINT uiRet = pContextMenu->TrackPopupMenu( TPM_LEFTALIGN | TPM_RETURNCMD , 
			x , y , pWnd ) ;
		if ( uiRet == ID_MENUITEM_OPEN ) 
		{
			pDlgRosenView->onEnterItem( htItem , 1 ) ;
		}
		bRv = TRUE ;
	}
	//	ダイヤ
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 )
	{
		m_itemContextMenu = htItem ;
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_ROSENVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( 3 ) ;
		//pContextMenu->SetDefaultItem( 0 , TRUE ) ;
		pContextMenu->TrackPopupMenu( TPM_LEFTALIGN , x , y , AfxGetMainWnd() ) ;

		bRv = TRUE ;
	}
	//	時刻表＜下り＞
	if ( aItemPos.size() == 4 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 && 
			aItemPos[3] == 0 )
	{
		m_itemContextMenu = htItem ;
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_ROSENVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( 5 ) ;
		//pContextMenu->SetDefaultItem( 0 , TRUE ) ;
		UINT uiRet = pContextMenu->TrackPopupMenu( TPM_LEFTALIGN | TPM_RETURNCMD , 
			x , y , pWnd ) ;
		if ( uiRet == ID_MENUITEM_OPEN ) 
		{
			pDlgRosenView->onEnterItem( htItem , 1 ) ;
		}
		bRv = TRUE ;
	}
	//	時刻表＜上り＞
	if ( aItemPos.size() == 4 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 &&
			aItemPos[3] == 1 )
	{
		m_itemContextMenu = htItem ;
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_ROSENVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( 5 ) ;
		//pContextMenu->SetDefaultItem( 0 , TRUE ) ;
		UINT uiRet = pContextMenu->TrackPopupMenu( TPM_LEFTALIGN | TPM_RETURNCMD , 
			x , y , pWnd ) ;
		if ( uiRet == ID_MENUITEM_OPEN ) 
		{
			pDlgRosenView->onEnterItem( htItem , 1 ) ;
		}
		bRv = TRUE ;
	}
	//	ダイヤグラム
	if ( aItemPos.size() == 4 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 && 
			aItemPos[3] == 2 )
	{
		m_itemContextMenu = htItem ;
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_ROSENVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( 6 ) ;
		//pContextMenu->SetDefaultItem( 0 , TRUE ) ;
		UINT uiRet = pContextMenu->TrackPopupMenu( TPM_LEFTALIGN | TPM_RETURNCMD , 
			x , y , pWnd ) ;
		if ( uiRet == ID_MENUITEM_OPEN ) 
		{
			pDlgRosenView->onEnterItem( htItem , 1 ) ;
		}
		bRv = TRUE ;
	}
	//	コメント
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 3 )
	{
		m_itemContextMenu = htItem ;
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_ROSENVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( 7 ) ;
		//pContextMenu->SetDefaultItem( 0 , TRUE ) ;
		UINT uiRet = pContextMenu->TrackPopupMenu( TPM_LEFTALIGN | TPM_RETURNCMD , 
			x , y , pWnd ) ;
		if ( uiRet == ID_MENUITEM_OPEN ) 
		{
			pDlgRosenView->onEnterItem( htItem , 1 ) ;
		}
		bRv = TRUE ;
	}

	m_itemContextMenu = NULL ;
	return bRv ;
}



IMPLEMENT_DYNAMIC(CRosenViewTreeCtrl, CTreeCtrlContextMenu)

CRosenViewTreeCtrl::CRosenViewTreeCtrl():
	m_itemContextMenu( NULL )
{

}

CRosenViewTreeCtrl::~CRosenViewTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CRosenViewTreeCtrl, CTreeCtrlContextMenu)
END_MESSAGE_MAP()


} //namespace ViewRosen

// CTreeCtrlContextMenu メッセージ ハンドラ

