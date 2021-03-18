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
#if !defined(AFX_CDLGDIALIST_H__3F4A38DE_8A42_4951_81E0_8091BE103CDF__INCLUDED_)
#define AFX_CDLGDIALIST_H__3F4A38DE_8A42_4951_81E0_8091BE103CDF__INCLUDED_
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgDiaList.h : �w�b�_�[ �t�@�C��
//

#include "CDiagramEditDoc.h"

namespace ViewRosen{

/////////////////////////////////////////////////////////////////////////////
// CDlgDiaList �_�C�A���O

/**
 * @brief
 *	�w�_�C���̈ꗗ�x�_�C�A���O�ł��B
 */
class CDlgDiaList : public CDialog
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
	 *	���[�g�h�L�������g�I�u�W�F�N�g�B
	 *	this �́A���̃I�u�W�F�N�g�̓��e��ҏW���܂��B
	 *
	 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
	 *	���̃I�u�W�F�N�g�́Athis��蒷���������Ȃ��Ă͂Ȃ�܂���B
	 *	�R���X�g���N�^�Ō��܂�܂��B
	 */
	CDiagramEditDoc* m_pCDiagramEditDoc ;
	///@}
protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		���݂̃��[�g�h�L�������g�̓��e���A��ʂ̃R���g���[���ɔ��f���܂��B
	
		�ΏۂƂȂ�R���g���[���́A�ȉ��̂悤�Ȃ��̂ł��B
		-	IDC_LIST_Dia
		-	IDC_BUTTON_PROP
		-	IDC_BUTTON_DELETE
		-	IDC_BUTTON_UP
		-	IDC_BUTTON_DOWN
	*/
	void updateControl() ;

	/**
		�w�_�C���̃v���p�e�B�x�_�C�A���O���N�����āA
		���� IDC_LIST_Dia �ɑI������Ă���_�C���̃v���p�e�B��ҏW���܂��B
	*/
	void execDlgDiaProp() ;
	///@}
// ----------------------------------------------------------------
// �R���X�g���N�V����
public:
	/**
	 * @param pCDiagramEditDoc [in,out]
	 *	���[�g�h�L�������g�I�u�W�F�N�g�B
	 *	this �́A���̃I�u�W�F�N�g�̓��e��ҏW���܂��B
	 *	\n���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
	 *	���̃I�u�W�F�N�g�́Athis��蒷���������Ȃ��Ă͂Ȃ�܂���B
	 * @param pParent [in]
	 *	�e�E�C���h�E�I�u�W�F�N�g�B�s�v�E�܂��͕s���Ȃ� NULL ���w��ł��܂��B
	 */
	CDlgDiaList(
		CDiagramEditDoc* pCDiagramEditDoc ,
		CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgDiaList)
	enum { IDD = IDD_DiaList };
	CListBox	m_listboxDia;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgDiaList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgDiaList)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonProp();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUp();
	afx_msg void OnButtonDown();
	afx_msg void OnSelchangeLISTDia();
	afx_msg void OnLbnDblclkListDia();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B
} //namespace ViewRosen

#endif // !defined(AFX_CDLGDIALIST_H__3F4A38DE_8A42_4951_81E0_8091BE103CDF__INCLUDED_)
