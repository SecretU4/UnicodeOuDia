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
#if !defined(AFX_CDLGROSENVIEW_H__DDF0CE6B_85EB_403A_9D22_02ACAED5776C__INCLUDED_)
#define AFX_CDLGROSENVIEW_H__DDF0CE6B_85EB_403A_9D22_02ACAED5776C__INCLUDED_
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// CDlgRosenView.h : �w�b�_�[ �t�@�C��
//
#include "resource.h"
#include "..\entDed\CentDedRosen.h"
#include "CRosenViewTreeCtrl.h"

namespace ViewRosen{
using namespace entDed;
/////////////////////////////////////////////////////////////////////////////
// CDlgRosenView �_�C�A���O

/**
  @brief
 	�����y�C���́w�H���r���[�x���������Ă��܂��B
 
 	���́w�H���r���[�x�́A���[�h���X�_�C�A���O�Ƃ��Ď������Ă��܂��B
 	CMainFrame �ɕ�܂���܂��B
 	
 	�w�H���r���[�x���X�V����̂́A���[�gDoc/View �� CDiagramEditView ��
 	�Ӗ��ł��B�w�H���r���[�x�̍X�V�̕K�v�𔻒f����̂��A CDiagramEditView ��
 	�Ӗ��ł��B
 */
class CDlgRosenView : public CDialog
{
private:
	// ********************************
	///@name	���
	// ********************************
	///@{
	/**
	 	�C���[�W���X�g�B
	 	OnCreate() �Ő������܂��B
	 */	
	CImageList	m_imagelistROSEN ;
	///@}

public:
	// --------------------------------
	///@name	�����֐�
	// --------------------------------
	///@{
	/**
	 	OnOK(),OnClickTreeRosen(),OnDblclkTreeRosen() �̉����֐��ł��B
	 	���X�g�r���[�̃A�C�e�� aItem ���N���b�N���ꂽ�Ƃ���
	 	����E�_�u���N���b�N���ꂽ�Ƃ��̓���E
	 	�A�C�e�� aItem ���I�����ꂽ��Ԃ� Enter �L�[�������ꂽ
	 	�Ƃ��̓�������s���܂��B
	 	
	 	<H5>
	 	�w�H���x�A�C�e�����N���b�N�����ꍇ
	 	</H5>
	 	�w�H���t�@�C���̃v���p�e�B�x
	 	�_�C�A���O���N�����܂��B
	 
	 	<H5>
	 	�w�w�x�A�C�e�����N���b�N�����ꍇ
	 	</H5>
	 	�w�w�x�r���[���J���܂��B
	 	
	 	<H5>
	 	�w��Ԏ�ʁx�A�C�e�����N���b�N�����ꍇ
	 	</H5>
	 	�w��Ԏ�ʁx�r���[���J���܂��B
	 	
	 	<H5>
	 	�w�_�C���x�A�C�e�����N���b�N�����ꍇ
	 	</H5>
	 	�w�_�C���ꗗ�x�_�C�A���O���J���܂��B
	 	
	 	<H5>
	 	�w�����\�����聄�x�A�C�e�����N���b�N�����ꍇ
	 	</H5>
	 	�w�����\�����聄�x�r���[���J���܂��B
	 	
	 	<H5>
	 	�w�����\����聄�x�A�C�e�����N���b�N�����ꍇ
	 	</H5>
	 	�w�����\����聄�x�r���[���J���܂��B
	 	
	 	<H5>
	 	�w�_�C���O�����x�A�C�e�����N���b�N�����ꍇ
	 	</H5>
	 	�w�_�C���O�����x�r���[���J���܂��B
	 	
	  @param aItem [in]
	 	���X�g�r���[�A�C�e�����w�肵�Ă��������B
	  @param iAction [in]
	 	�A�C�e���ɑ΂��鑀����w�肵�Ă��������B
	 	-	0 ;	//	Enter �L�[�̑���
	 	-	1 ;	//	�N���b�N����
	 			//	�i���[�_���_�C�A���O���o���悤�ȓ���͍s���܂���j
	 	-	2 ;	//	�_�u���N���b�N����
	 			//	�i���[�_���_�C�A���O���o���悤�ȓ���݂̂��s���܂��j
	  @return 
	 	-	1 ;	//	�w��̃A�C�e���ɑΉ����鏈�����s���܂����B
	 	-	0 ;	//	���������͂���܂���ł����B
	 */
	virtual int onEnterItem( HTREEITEM aItem , int iAction ) ;
	///@}
public:
	// ********************************
	///@name	CWnd
	// ********************************
	///@{
	/**
		�_�C�A���O(��̃R���g���[��)�Ƀt�H�[�J�X�������Ԃ� 
        �A�N�Z�����[�^�ɂ�郁�j���[�R�}���h�ւ̃A�N�Z�X�� 
        �s�����߂ɂ́A���C���t���[���E�C���h�E�� PreTranslateMessage() �� 
        �Ϗ����Ȃ��Ă͂Ȃ�܂���B 
	*/
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	///@}

public:
	// ********************************
	//	CDlgRosenView
	// ********************************
	// ********************************
	///@name CDlgRosenView-����
	// ********************************
	///@{
	/**
	  @param pCentDedRosen [in]
	   CentDedRosen ���ێ����Ă���H���̏����A
	 	�c���[�R���g���[�� m_treeROSEN �ɔ��f���܂��B
	 */
	void UpdateROSEN( const CentDedRosen* pCentDedRosen ) ;

	/**
	 	���[�gDoc��UpdateAllSubDocviews()����Ăяo����܂��B
	  @param pSender [in]
	  @param lHint [in]
	  @param pHint [in]
	 */
	virtual void OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint ) ;
	
	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// �R���X�g���N�V����
public:
	CDlgRosenView(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgRosenView)
	enum { IDD = IDD_ROSEN_VIEW };
	CRosenViewTreeCtrl 	m_treeROSEN;
	//}}AFX_DATA

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgRosenView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgRosenView)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnClickTreeRosen(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkTreeRosen(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuitemOpen();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace ViewRosen

#endif // !defined(AFX_CDLGROSENVIEW_H__DDF0CE6B_85EB_403A_9D22_02ACAED5776C__INCLUDED_)
