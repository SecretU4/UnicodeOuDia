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
//	$Id: CTreeCtrlContextMenu.cpp 304 2016-06-11 08:45:22Z okm $
// ****************************************************************
#include "TreeCtrl\CTreeCtrlContextMenu.h"

namespace OuMfc{
namespace TreeCtrl{

// CTreeCtrlContextMenu

BOOL CTreeCtrlContextMenu::OnContextMenu_TrackPopupMenu( 
	CWnd* pWnd, 
	HTREEITEM htItem ,
	int x , int y ) 
{
	return FALSE ;
}



IMPLEMENT_DYNAMIC(CTreeCtrlContextMenu, CTreeCtrl)

CTreeCtrlContextMenu::CTreeCtrlContextMenu()
{

}

CTreeCtrlContextMenu::~CTreeCtrlContextMenu()
{
}


BEGIN_MESSAGE_MAP(CTreeCtrlContextMenu, CTreeCtrl)
	ON_NOTIFY_REFLECT(NM_RCLICK, &CTreeCtrlContextMenu::OnNMRClick)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()



// CTreeCtrlContextMenu ���b�Z�[�W �n���h��



void CTreeCtrlContextMenu::OnNMRClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	// Send WM_CONTEXTMENU to self
	SendMessage(WM_CONTEXTMENU, (WPARAM) m_hWnd, GetMessagePos());
	// Mark message as handled and suppress default handling
	*pResult = 1;
}

void CTreeCtrlContextMenu::OnContextMenu(CWnd* pWnd, CPoint point)
{
	HTREEITEM	htItem = NULL ;
	BOOL bProcessed = FALSE ;

	CPoint	pointMenu ;
	//	�L�[����ɂ��R���e�L�X�g���j���[
	//	���̏ꍇ�́A�R���e�L�X�g���j���[�̑Ώۂ�
	//	�t�H�[�J�X�̂���A�C�e���ƂȂ�܂��B
	//	�܂��A���j���[�\���ʒu�� �Ώۂ̃A�C�e���̉E���ł��B
	if (point.x == -1 && point.y == -1)
	{
		htItem = GetSelectedItem() ;
		if ( htItem != NULL )
		{
			CRect	aRect ;
			CPoint pointClient ;
			if ( GetItemRect( htItem,
			   &aRect ,
			   FALSE ) )
			{
				pointClient.x = aRect.left ;
				pointClient.y = aRect.bottom ;
				pointMenu = pointClient ;
				ClientToScreen( &pointMenu ) ;
			}
		}
	}
	//	�}�E�X�E�N���b�N�ɂ��R���e�L�X�g���j���[
	//	���̏ꍇ�́A�R���e�L�X�g���j���[�̑Ώۂ�
	//	�}�E�X�|�C���^�̂���ʒu�̃A�C�e���ł��B
	else
	{
		CPoint pointClient = point ;
		ScreenToClient(&pointClient);
		UINT uFlags = 0 ;
		htItem = HitTest( pointClient, &uFlags );
		pointMenu = point ;
	}
	//htItem = �R���e�L�X�g���j���[�̑ΏۂƂȂ�c���[�A�C�e��
	//	(NULL�̏ꍇ�A�R���e�L�X�g���j���[�̕\���͂ł��܂���j
	//pointMenu=�R���e�L�X�g���j���[�̕\���ʒu(�X�N���[�����W)

	if ( htItem != NULL )
	{
		bProcessed = OnContextMenu_TrackPopupMenu( 
			pWnd , 
			htItem , 
			pointMenu.x , pointMenu.y ) ;
	}

	//	�R���e�L�X�g���j���[��\�����Ȃ��ꍇ�́A
	//	�f�t�H���g�����ɈϏ����܂��B
	if ( !bProcessed )
	{
		CTreeCtrl::OnContextMenu( pWnd , point ) ;
	}

}

} //namespace TreeCtrl
} //namespace OuMfc
