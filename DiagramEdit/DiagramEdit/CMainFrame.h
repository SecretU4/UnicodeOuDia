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
// CMainFrame.h : CMainFrame �N���X�̐錾����уC���^�[�t�F�C�X�̒�`�����܂��B
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMAINFRAME_H__30AFE159_0874_4392_957E_EC27183039B9__INCLUDED_)
#define AFX_CMAINFRAME_H__30AFE159_0874_4392_957E_EC27183039B9__INCLUDED_
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Hidemdi\CHidemdiMainfrm.h"
#include "FrameLeftPane\CWndSplitBarV.h"

#include "ViewRosen\CDlgRosenView.h"
#include "CDedStatusBar.h"

using namespace OuMfc::Hidemdi;
using namespace ViewRosen;
using namespace OuMfc::FrameLeftPane;
/**
 *	@brief
 *	�A�v���P�[�V�����̃��C���t���[���E�C���h�E�N���X�ł��B
 */
class CMainFrame : public CHidemdiMainfrm
{
 private:
	// ********************************
	//	���
	// ********************************
	/**
	 	�H���r���[�i�����y�C���j
	 	OnCreate() �Ő������܂��B
	 */
	CDlgRosenView	m_CDlgRosenView ;	
	/**
	 	�X�v���b�g�o�[
	 	OnCreate() �Ő������܂��B
	 */
	CWndSplitBarV	m_CWndSplitBarV ;	
 protected:
	// --------------------------------
	//	CFrameWnd
	// --------------------------------
	/**
	  �y�I�[�o���C�h�z
	 	CWndSplitBarV::RecalcLayout() �ɂ����
	 	�R���g���[���o�[��z�u���Ă���A
	 	MDIClientWindow ��
	 	�H���r���[�i�����y�C���j��z�u���܂��B
	 */
	virtual void RecalcLayout( BOOL bNotify = TRUE );

	/**
	 	�A�v���P�[�V�����̃��C�� �t���[�� �E�B���h�E��
	 	����v���r���[ ���[�h�ɓ���Ƃ��ƁA������Ƃ��ɌĂяo���܂��B
	 
	  @param bPreview [in]
	 	�A�v���P�[�V����������v���r���[ ���[�h��
	 	���邩�Ȃ������w�肵�܂��B
	 	����v���r���[���[�h�ł���� TRUE ���A�v���r���[ ���[�h��
	 	�L�����Z�������ɖ߂��ɂ� FALSE ��ݒ肵�܂��B
	  @param pModeStuff [in]
	 	CPrintPreviewState �\���̂ւ̃|�C���^�B
	 
	  �y�I�[�o���C�h�z
	 	�v���r���[���[�h���s���́A m_CDlgRosenView �𖳌��ɂ��܂��B
	 */
	virtual void OnSetPreviewMode( BOOL bPreview, CPrintPreviewState* pModeStuff );
protected:
	// --------------------------------
	///@name ���j���[�R�}���h�̉����֐�
	// --------------------------------
	///@{
	/**	
		[�t�@�C��]-[�H���t�@�C���̑g����]
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂��B
	@return
		-	0 :	����
		-	-21 ;	//	�w��2�����Ȃ�A���̃R�}���h�͎g�p�ł��܂���B
		-	-1 :	//	�L�����Z��
		-	-11 :	//	�t�@�C�����݂���܂���B
		-	-12 :	//	�t�@�C���̌`�����s���ł��B
	@memo
		���̊֐��� CDiagramEditDoc �̃����o�ɂ���A�Ƃ����l����������܂��B
		�������A���̊֐��̏�����UI(�_�C�A���O�{�b�N�X)�������Ă��邽�߁A
		�����ł�  CDiagramEditDoc �̃����o�ɂ���̂�����܂����B
	*/
	int OnFileRosenFileInsert_Process( BOOL bQueryEnable ) ;

	/**	
		[�t�@�C��]-[�H���t�@�C���̐؂�o��]
	@memo
		���̊֐��� CDiagramEditDoc �̃����o�ɂ���A�Ƃ����l����������܂��B
		�������A���̊֐��̏�����UI(�_�C�A���O�{�b�N�X)�������Ă��邽�߁A
		�����ł�  CDiagramEditDoc �̃����o�ɂ���̂�����܂����B
	*/
	int OnFileRosenCreateSubRosen_Process( BOOL bQueryEnable ) ;
	///@}

// ********************************
//	CMainFrame
// ********************************
 public:
	// ********************************
	///@name	CMainFrame-���
	// ********************************
	///@{
	CDlgRosenView*	getCDlgRosenView()
	{	return &m_CDlgRosenView ; } ;
	///@}
	// ********************************
	///@name	CMainFrame-����
	// ********************************
	///@{
	/**
	 	�w�H���t�@�C���̃v���p�e�B�x�_�C�A���O���J���܂��B
	 
	 	�_�C�A���O���wOK�x�ŕ���ꂽ��A�H���t�@�C����
	 	�v���p�e�B���w���[�g�h�L�������g�x CDiagramEditDoc 
	 	�ɔ��f���܂��B
	  @return
	 	0 �ȏ�͐����A�G���[�Ȃ畉�̐��ł��B 
	 	-	1 ;	//	�wOK�x��������āA���͓��e��
	 		�w���[�g�h�L�������g�x�ɔ��f���܂����B
	 	-	0 ;	//	�wCancel�x��������܂����B
	 	
	 */
	int execCDlgRosenFileProp() ;
	/**
	 	�w�_�C���̈ꗗ�x�_�C�A���O���J���܂��B
	 
	 	���w�_�C���̈ꗗ�x�_�C�A���O�́A���[�g�h�L�������g��
	 	�ύX����\�͂������Ă��܂��B
	  @return
	 	0 �ȏ�͐����A�G���[�Ȃ畉�̐��ł��B 
	 	���݂̂Ƃ���A 0 �����Ԃ��܂���B	
	 */
	int execCDlgDiaList() ;

	/**
	  @return
	 	���݃A�N�e�B�u��MDI�q�E�C���h�E��
	 	�A�N�e�B�u�ȃr���[��ێ����Ă���΁A
	 	���̃r���[�I�u�W�F�N�g�ւ̃|�C���^��Ԃ��܂��B
	 	�A�N�e�B�u�ȃr���[���Ȃ��Ȃ�NULL�ł��B
	 */
	CView* getMDIChildActiveView() ;
	///@}
// ----------------------------------------------------------------

	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �R���g���[�� �o�[�p�����o
	CDedStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CToolBar    m_wndToolBarDiagram;

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFileRosenfileInsert();
	afx_msg void OnUpdateFileRosenfileInsert(CCmdUI *pCmdUI);
	afx_msg void OnFileRosenCreateSubRosen();
	afx_msg void OnUpdateFileRosenCreateSubRosen(CCmdUI *pCmdUI);
	afx_msg void OnRosenFileProp();
	afx_msg void OnRosenDialist();
	afx_msg void OnWindowRosenView();
	afx_msg void OnUpdateINDICATOR_PasteZoubun(CCmdUI *pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_CMAINFRAME_H__30AFE159_0874_4392_957E_EC27183039B9__INCLUDED_)
