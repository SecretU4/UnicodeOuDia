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
#if !defined(AFX_CDLGPRINTPAGEPROP_H__3DA59686_AFFF_46F4_A968_09F46A8F6C39__INCLUDED_)
#define AFX_CDLGPRINTPAGEPROP_H__3DA59686_AFFF_46F4_A968_09F46A8F6C39__INCLUDED_
/** @file */
#include "CdPrintPageProp.h"
#include "resource.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgPrintPageProp.h : �w�b�_�[ �t�@�C��
//

namespace Print{
/////////////////////////////////////////////////////////////////////////////
// CDlgPrintPageProp �_�C�A���O

/**
 * @brief
 *	�w����y�[�W�ݒ�x���[�_���_�C�A���O�ł��B
 *
 * �y�g�����z
 *
 *	�P�D  �R���X�g���N�^�̈����ɂ́A�_�C�A���O�̏����ݒ�l��
 *	�w�肵�Ă��������B
 *	
 *	�Q�D  DoModal() �ŁA�_�C�A���O���J�n���Ă��������B
 *	
 *	�R�D  DoModal() �̖߂�l�� IDOK �̏ꍇ�́A
 *	 m_CdPrintPageProp �ɁA�_�C�A���O�ւ̓��͓��e���i�[
 *	����Ă��܂��B
 */
class CDlgPrintPageProp : public CDialog
{
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 *	�_�C�A���O�ŕҏW����l�B
	 *
	 *	�R���X�g���N�^�`OnOK()���s�܂ł́A�_�C�A���O�ւ̏����ݒ�l��
	 *	�ێ����܂��B
	 *	OnOK() �Ȍ�i�_�C�A���O�� IDOK �ŏI���������Ɓj�́A
	 *	�_�C�A���O�ɓ��͂���Ă����l��ێ����܂��B
	 */
	CdPrintPageProp	m_CdPrintPageProp ;
///@}

// ********************************
//	CDlgPrintPageProp
// ********************************
 public:
	// ********************************
	///@name CDlgPrintPageProp-����
	// ********************************
	///@{
	CdPrintPageProp	getCdPrintPageProp(){
		return m_CdPrintPageProp ; } ;
	///@}

// ----------------------------------------------------------------
// �R���X�g���N�V����
public:
	/**
	 * @param aCdPrintPageProp [in]
	 *	�_�C�A���O�ɏ����ݒ肷��l���w�肵�Ă��������B
	 * @param pParent [in]
	 *	�e�E�C���h�E���w�肵�Ă��������B
	 */
	CDlgPrintPageProp( 
		const CdPrintPageProp& aCdPrintPageProp , 
		CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
 protected:
	//{{AFX_DATA(CDlgPrintPageProp)
	enum { IDD = IDD_PrintPageProp };
	double	m_dEDIT_MarginLeft;
	double	m_dEDIT_MarginTop;
	double	m_dEDIT_MarginRight;
	double	m_dEDIT_MarginBottom;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgPrintPageProp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgPrintPageProp)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B
} //namespace Print

#endif // !defined(AFX_CDLGPRINTPAGEPROP_H__3DA59686_AFFF_46F4_A968_09F46A8F6C39__INCLUDED_)
