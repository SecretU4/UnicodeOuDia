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


(��: 

	OuDia - ��Ԏ����\�����ƂɁA�_�C���O������`�悷��Win32�A�v���P�[�V
�����B

Copyright (C) 2006-2017 take-okm 

���̃v���O�����̓t���[�\�t�g�E�F�A�ł��B���Ȃ��͂�����A�t���[�\�t�g�E�F�A��
�c�ɂ���Ĕ��s���ꂽGNU ��ʌ��O���p������(�o�[�W����3���A����ȍ~�̃o�[�W��
���̂����ǂꂩ)����߂�����̉��ōĔЕz�܂��͉��� ���邱�Ƃ��ł��܂��B

���̃v���O�����͗L�p�ł��邱�Ƃ�����ĔЕz����܂����A*�S���̖��ۏ� *�ł��B
���Ɖ\���̕ۏ؂����ړI�ւ̓K�����́A���O�Ɏ����ꂽ���̂� �܂߁A�S������
���܂���B�ڂ�����GNU ��ʌ��O���p���������������������B

���Ȃ��͂��̃v���O�����Ƌ��ɁAGNU ��ʌ��O���p�������̃R�s�[���ꕔ �󂯎��
�Ă���͂��ł��B�����󂯎���Ă��Ȃ���΁A<http://www.gnu.org/licenses/> ��
�������������B

)

  �����āA���ʂȗ�O�Ƃ��āAtake-okm �͂��̃v���O�����̃R�[�h�� 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  ���邢�� "MFC Version 9.0" �Ɠ������C�Z���X���K�p���ꂽ
  "MFC Version 9.0" �̉��ς��ꂽ�o�[�W����)�ƃ����N���A
  �����N���ꂽ���҂��܂ތ������앨��Еz���鋖��^���܂��B
  ���Ȃ��� "MFC" �ȊO�Ŏg���Ă��邷�ׂ�
  �̃R�[�h�Ɋւ��Ă͑S�ʓI��GNU��ʌ��O���p�����_�񏑂ɏ]��Ȃ����
  �Ȃ�܂���B���Ȃ������̃t�@�C�������ς����Ȃ�΁A���Ȃ��͂��̗�O
  �����Ȃ��̃o�[�W�����̃t�@�C���Ɉ��������݂��邱�Ƃ��ł��܂����A��
  ������`���͂���܂���B������O��݂������Ȃ���΁A���̗�O������
  ���Ȃ��̃o�[�W��������͍폜���Ă��������B)
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

	//	�H��
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
	//	�w
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
	//	��Ԏ��
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
	//	�_�C��
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
	//	�����\�����聄
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
	//	�����\����聄
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
	//	�_�C���O����
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
	//	�R�����g
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

// CTreeCtrlContextMenu ���b�Z�[�W �n���h��

