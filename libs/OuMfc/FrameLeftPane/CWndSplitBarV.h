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
#if !defined(AFX_CWNDSPLITBARV_H__4D5499AB_1C6F_4AA9_9F02_12CC9B690B84__INCLUDED_)
#define AFX_CWNDSPLITBARV_H__4D5499AB_1C6F_4AA9_9F02_12CC9B690B84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>

// CWndSplitBarV.h : �w�b�_�[ �t�@�C��
//

namespace OuMfc{
namespace FrameLeftPane{

/////////////////////////////////////////////////////////////////////////////
// CWndSplitBarV �E�B���h�E
/**
@brief
 MDIClient �E�C���h�E�̍����y�C���Ƃ̊Ԃɂ���
�X�v���b�g�o�[�̃E�C���h�E�ł��B

�yMDIFrameLeftPane �A�v���P�[�V�����̊T�v�z
	
  MDIFrameLeftPane �A�v���P�[�V�����́A�����Ɂu�����y�C���v�q�E�C���h�E
�i�c���[�r���[�Ȃǁj�E�E���� MDIClient �E�C���h�E�������A
MDIClient �E�C���h�E���ɂ� MDI�q�E�C���h�E���J�����Ƃ̂ł���
�A�v���P�[�V�����ł��B
  �����y�C����MDIClient�E�C���h�E�̊Ԃɂ́A�u�X�v���b�g�o�[�v��
����܂��B�u�X�v���b�g�o�[�v���h���b�O���邱�Ƃɂ��A�u�����y�C���v��
 MDIClient �̋��E�i�傫���j�𒲐߂��邱�Ƃ��ł��܂��B
	
  ���̃A�v���P�[�V�����̃��C���E�C���h�E�́A CMDIFrameWnd �̔h���N���X
�Ƃ��Ď������܂��B�u�����y�C���v�E�u�X�v���b�g�o�[�v�́A
���C���E�C���h�E�̎q�E�C���h�E�Ƃ��܂��B
 �u�����y�C���v�́A CWnd �̔h���N���X�Ƃ��Ď������܂��B
 �u�X�v���b�g�o�[�v�́A CWndSplitBar �N���X�̃I�u�W�F�N�g�𐶐����܂��B
	

�y�g�����z

�P�D  ���炩���߁A�u�����y�C���v�̃E�C���h�E�̓�����A
 CWnd �̔h���N���X�Ƃ��Ď������Ă��������B
	
�Q�D  ���C���t���[���E�C���h�E�̃N���X�́A CMDIFrameWnd ��
�h���N���X�Ƃ��Ă��������B
  ���̃N���X�ɂ́A�u�����y�C���v�̃N���X�̃C���X�^���X(CWnd�h���N���X)
�ƁA�u�X�v���b�g�o�[�v�N���X�̃C���X�^���X�iCWndSpkitterV�j��
�����o�ϐ��Ƃ��ĕێ����Ă��������B  @n
  ���C���t���[���E�C���h�E�� OnCreate() �ł́A �u�����y�C���v�E
�u�X�v���b�g�o�[�v�ɑ΂��� Create() ���Ăяo���āA�q�E�C���h�E��
 HWND �𐶐����Ă��������B
	
�R�D  ���C���t���[���E�C���h�E�̃N���X�i CMDIFrameWnd �h���N���X ) �ł́A
�K�� RecalcLayout() ���I�[�o���C�h���āA���̃N���X��
 CMDIFrameWnd_RecalcLayout() �ɏ������Ϗ����Ă��������B
 */
class CWndSplitBarV : public CWnd
{
 private:
	// ********************************
	///@name	�֘A
	// ********************************
	///@{
	/**
		�����y�C���̃E�C���h�E�ւ̃|�C���^�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷��
		�������Ȃ��Ă͂Ȃ�܂���B
	*/
	CWnd*	m_pwndLeftPane ;
	///@}
 private:
	// --------------------------------
	///@name	�����f�[�^
	// --------------------------------
	///@{
	/**
		�ʏ�� -1 �B
		���̃E�C���h�E���h���b�O���Ă���Œ������́A
		�h���b�O���J�n�����Ƃ��̃}�E�X�̍��W���A
		���̃E�C���h�E��̍��W�ŕێ����܂��i0�ȏ�j�B
	 */
	int	m_iDragPosX ;
	///@}
 public:
	// ********************************
	//	�\�z
	// ********************************
	///@{
	/**
		�E�C���h�E�𐶐����܂��B
	@param pParentWnd [in]
		�e�E�C���h�E���w�肵�Ă��������B
	@param pwndLeftPane [in]
		�����y�C���̃E�C���h�E�ւ̃|�C���^�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷��
		�������Ȃ��Ă͂Ȃ�܂���B
	@param nID [in]
		���̃E�C���h�E�i�X�v���b�g�o�[�j��
		�q�E�C���h�EID ���w�肵�Ă��������B
	@return
		����I�������ꍇ�� 0 �ȊO��Ԃ��܂��B����ȊO�̏ꍇ�� 0 ��Ԃ��܂��B
	 */
	BOOL Create( CWnd* pParentWnd, 	
		CWnd* pwndLeftPane ,
		UINT nID);
	
	///@}
 public:
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
		 CMDIFrameWnd �̂Ȃ��� �����y�C���ƁA
		�X�v���b�g�o�[(CWndSplitBarV)��z�u����A�v���P�[�V�����́A
		���C���E�C���h�E�I�u�W�F�N�g�̃N���X�iCMDIFrameWnd �h���N���X�j
		�� CFrameWnd::RecalcLayout() ���I�[�o���C�h���A
		���̊֐��ɏ������Ϗ����Ă��������B
		���̂Ƃ��A��{�N���X�̎����iCFrameWnd::RecalcLayout()�j��
		�Ăяo���͍s��Ȃ��ł��������B
	
		���̊֐��́A�����y�C���E�X�v���b�g�o�[�EMDIClient �E�C���h�E��
		�K�؂ɍĔz�u���܂��B
	
	@param pCMDIFrameWnd [in]
		���C���E�C���h�E�� CMDIFrameWnd �I�u�W�F�N�g��
		�w�肵�Ă��������B
		�ʏ�́A this ���w�肷�邱�ƂɂȂ�܂��B
	@param pwndLeftPane [in]
		�����y�C���̃I�u�W�F�N�g���w�肵�Ă��������B
	@param pCWndSplitBarV [in]
		�X�v���b�g�o�[ �̃I�u�W�F�N�g���w�肵�Ă��������B
	@param bNotify [in]
		 CFrameWnd �h���N���X�� RecalcLayout( BOOL bNotify ) ��
		�n���ꂽ bNotify ���A���̂܂ܓn���Ă��������B
	 */
	static void CMDIFrameWnd_RecalcLayout(
			CMDIFrameWnd* pCMDIFrameWnd ,
			CWnd* pwndLeftPane ,
			CWndSplitBarV* pCWndSplitBarV ,
			BOOL bNotify ) ;
	
	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// �R���X�g���N�V����
public:
	CWndSplitBarV();

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CWndSplitBarV)
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CWndSplitBarV();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CWndSplitBarV)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace FrameLeftPane
} //namespace OuMfc

#endif // !defined(AFX_CWNDSPLITBARV_H__4D5499AB_1C6F_4AA9_9F02_12CC9B690B84__INCLUDED_)
