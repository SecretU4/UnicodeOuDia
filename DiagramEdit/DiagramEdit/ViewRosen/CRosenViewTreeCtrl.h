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
//	$Id: CRosenViewTreeCtrl.h 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
#ifndef  ViewRosen_CRosenViewTreeCtrl_h
#define  ViewRosen_CRosenViewTreeCtrl_h

#pragma once
#include "TreeCtrl\CTreeCtrlContextMenu.h"

namespace ViewRosen{
	using namespace OuMfc::TreeCtrl;
/**
@brief
	�H���r���[�̃c���[�R���g���[���ɁA�R���e�L�X�g���j���[��񋟂��܂��B
*/
class CRosenViewTreeCtrl : public CTreeCtrlContextMenu
{
private:
	/**
		�ʏ��NULL�B
		�R���e�L�X�g���j���[�\�����́A���̃R���e�L�X�g���j���[��
		�Ή������A�C�e���ƂȂ�܂��B
	*/
	HTREEITEM	m_itemContextMenu ;
protected:
	/**
		OnContextMenu() �̉������֐��ł��B

		�I�[�o���C�h���āA�A�C�e���ɑΉ�����
		�R���e�L�X�g���j���[�� CMenu �I�u�W�F�N�g�𐶐����A
		CMenu::TrackPopupMenu() �ŃR���e�L�X�g���j���[��
		�N�����Ă��������B
	@param pWnd[in]
		���[�U�[�ɂ���ă}�E�X�̉E�{�^�����N���b�N���ꂽ
		�E�B���h�E�̃n���h���ł��B
	@param htItem[in]
		�R���e�L�X�g���j���[�ɑΉ������A�C�e�����w�肵�܂��B
	@param x [in]
		�R���e�L�X�g���j���[��\������ʒu���AScreen���W�Ŏw�肵�܂��B
		���̒l�́ACMenu::TrackPopupMenu()�̈��� x ��
		�n���Ă��������B
	@param y [in]
		�R���e�L�X�g���j���[��\������ʒu���A
		Screen���W�Ŏw�肵�܂��B
		���̒l�́ACMenu::TrackPopupMenu()�̈��� y ��
		�n���Ă��������B
	@return
		�R���e�L�X�g���j���[��\�������ꍇ�� TRUE ���A
		�R���e�L�X�g���j���[

		
		���� x , y �́A���[�U�[���}�E�X�ŃR���e�L�X�g���j���[��
		�v�������Ƃ��́A
		���̒l�́A�}�E�X�J�[�\���̈ʒu�ł��B
		���[�U�[���L�[����ŃR���e�L�X�g���j���[��
		�Ăяo�����Ƃ��́A�A�C�e�� htItem �̍������W�ł��B
	*/
	virtual BOOL OnContextMenu_TrackPopupMenu( 
		CWnd* pWnd, 
		HTREEITEM htItem ,
		int x , int y )  ;
public:
	HTREEITEM	getItemContextMenu(){	return m_itemContextMenu ;}
	// --------------------------------
	DECLARE_DYNAMIC(CRosenViewTreeCtrl)

public:
	CRosenViewTreeCtrl();
	virtual ~CRosenViewTreeCtrl();

protected:
	DECLARE_MESSAGE_MAP()
};

} //namespace ViewRosen
#endif //ViewRosen_CRosenViewTreeCtrl_h

