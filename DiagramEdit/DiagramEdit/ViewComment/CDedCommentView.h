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
#if !defined(AFX_CDEDCOMMENTVIEW_H__FBDDE445_4FAC_4AA4_A9CB_3B4100283066__INCLUDED_)
#define AFX_CDEDCOMMENTVIEW_H__FBDDE445_4FAC_4AA4_A9CB_3B4100283066__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDedCommentView.h : �w�b�_�[ �t�@�C��
//
#include "NsOu/Ou.h"
//#include "CDedRosenFileData_CEditCmd_Comment.h"
#include "DedRosenFileData\EditCmd\EditCmd.h"

namespace ViewComment{
	using namespace DcDrawLib::DcdCd::DcDrawProp;
	using namespace OuLib::NsOu;
	using namespace DedRosenFileData::EditCmd;
/////////////////////////////////////////////////////////////////////////////
// CDedCommentView �r���[

class CDedCommentView : public CEditView
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
public:
	typedef CEditView	super ;
// --------------------------------
///@name �����f�[�^
// --------------------------------
///@{
private:
	/**
	 *	���̃r���[�Ŏg�p���Ă���t�H���g�B
	 *	OnUpdate() �ō쐬���܂��B
	 */
	CdFontProp	m_CdFontProp ;
	CFont	m_CFont ;

	/**
	 *	�ʏ�� false �B
	 *	�r���[���A�N�e�B�u�łȂ��Ƃ��ɁA
	 *	OnUpdate() �ɂ���āA���̃r���[����
	 *	���Ԃ̂�����X�V���v�����ꂽ�Ƃ�����A
	 *	�r���[�̑S�X�V�����s����܂ł̊Ԃ��� true �ɂȂ�܂��B
	 *	
	 *	���̕ϐ��� true �̂Ƃ��́A
	 *	�r���[�̍X�V���A���Ƀr���[���A�N�e�B�u�������܂�
	 *	�ۗ����Ă��邱�Ƃ������܂��B
	 *	
	 *	OnUpdate() �ɂ���āA���̃r���[����
	 *	���Ԃ̂�����X�V���v�����ꂽ�ꍇ�A
	 *	���̕ϐ��� true �ɂ��A
	 *	OnUpdate_All() �͎��s���܂���B
	 *
	 *	���̒l�� true �̂Ƃ��ɁA�r���[���A�N�e�B�u�����ꂽ��A
	 *	OnUpdate() �����s���܂��B
	 */
	bool m_bUpdate_All_Requested ;

	/**
	 *	�ʏ�� false �B
	 *	�r���[��ύX���Ă���A���̃r���[�̓��e��
	 *	OnUpdate() �ɂ���āA���[�gDocument()�ɏ������ނ܂ł̊Ԃ���
	 *	true �ł��B
	 */
	bool m_bIsChanged ;

///@}
// --------------------------------
///@name �������֐�
// --------------------------------
///@{
private:
	/**
	 *	OnUpdate() �̉������֐��ł��B
	 *
	 *	�h�L�������g�̓��e���r���[�ɔ��f���܂��B
	 */
	void OnUpdate_All() ; 
	/**
	 *	OnUpdate() �̉������֐��ł��B
	 *
	 *	pHint �� CRfEditCmd_Comment ����
	 *	�������s���܂��B
	 */
	void OnUpdate_Comment( Ou<CRfEditCmd_Comment> pCommand );

	/**
	 *	���̃I�u�W�F�N�g�ɂ�����A�W���̃e�L�X�g�`����@��Ԃ��܂��B
	 */
	CdDrawTextProp	getCdDrawTextPropStandard() ;
///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
protected:
	CDedCommentView();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^
	DECLARE_DYNCREATE(CDedCommentView)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CDedCommentView)
	protected:
	virtual void OnDraw(CDC* pDC);      // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h���܂����B
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CDedCommentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CDedCommentView)
	afx_msg void OnChange();
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace ViewComment

#endif // !defined(AFX_CDEDCOMMENTVIEW_H__FBDDE445_4FAC_4AA4_A9CB_3B4100283066__INCLUDED_)
