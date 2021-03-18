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
#if !defined(AFX_CDLGROSENFILEPROP_H__A77A598D_541C_4EF8_B8EA_587920B81B1E__INCLUDED_)
#define AFX_CDLGROSENFILEPROP_H__A77A598D_541C_4EF8_B8EA_587920B81B1E__INCLUDED_
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgRosenFileProp.h : �w�b�_�[ �t�@�C��
//

#include <string>

#include "..\DedRosenFileData\CdDedDispProp.h"
#include "CDlgRosenFileProp_Rosen.h"
#include "CDlgRosenFileProp_FontColor.h"
#include "CDlgRosenFileProp_Diagram.h"

namespace ViewRosen{

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp �_�C�A���O

/**
@brief
 	�w�H���t�@�C���̃v���p�e�B�x�_�C�A���O�B
 	
 	  �_�C�A���O��OK�{�^���ŏI�������Ƃ��́A getPropEditorData() �ŁA
 	 m_PropEditorData �ɃA�N�Z�X���A���͌��ʂ��擾���Ă��������B
 	  this�́A�_�C�A���O��OK�{�^���I�������Ƃ��A�_�C�A���O�ւ̓��͌��ʂ�
 	 m_PropEditorData �I�u�W�F�N�g�Ɋi�[���܂��B
 */
class CDlgRosenFileProp : public CDialog
{
public:
	// ****************************************************************
	//	CPropEditorData
	// ****************************************************************
	/**
	@brief
		�w�H���t�@�C���̃v���p�e�B�x�_�C�A���O�́A
		�ҏW�Ώۃf�[�^��ێ�����N���X�ł��B
		
		�ҏW�Ώۃf�[�^�́A���̃_�C�A���O�ŕҏW�\�ȃf�[�^�̃R�s�[�ł��B

		���̃N���X�́A�ȉ��̐Ӗ��������܂��B
		
		-	CDedRosenFileData�E�������͂��̈ꕔ����A�ҏW�Ώۃf�[�^�𐶐�
		-	�ҏW�Ώۃf�[�^����AUI�\���f�[�^�𐶐�
		-	UI�\���f�[�^�����ƂɁA�ҏW�Ώۃf�[�^���X�V
		-	�ҏW�Ώۃf�[�^���ACRosenFileData�E�������͂��̈ꕔ�ɓK�p���܂��B
		-	�ҏW�Ώۃf�[�^����A CEditCmd_ �I�u�W�F�N�g�𐶐�����B

	 	�_�C�A���O�{�b�N�X�́A�N�����ɁA�����\����UI�\���f�[�^���A
	 	���̃I�u�W�F�N�g����擾���܂��B
	 	�܂��AOK�{�^���ŏI�������Ƃ��ɁA
	 	���͌��ʂ�UI�\���f�[�^���A���̃I�u�W�F�N�g�Ɋi�[���܂��B
	*/
	class CPropEditorData
	{
	private:
		// ********************************
		///@name	����
		// ********************************
		///@{
		/**
		 	�H�����B
		 */
		std::string	m_strRosenName ;

		/**
			�_�C���̋N�_�����ł��B
		*/
		CdDedJikoku	m_jikokuKitenJikoku ;
		
		/**
			�_�C���O�����̊���̉w�ԕ��B

			��Ԑݒ�̂Ȃ��w�Ԃ́A�_�C���O�����r���[��ł�
			�c�����̕����w�_�C���O�����G���e�B�e�BY���W�x�P��(�b)�Ŏw�肵�܂��B
		
			����l�� 60 �ł��B
		*/
		int	m_iDiagramDgrYZahyouKyoriDefault ;
		

		/**
			DiagramEdit �̕\���Ɋ֌W����v���p�e�B��ێ�����
			�P���f�[�^�N���X�ł��B
		*/
		CdDedDispProp	m_CdDedDispProp ;
		///@}
	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************
		/**
		 @param pCDedRosenFileData [in]
			�w�H���t�@�C���x�̃f�[�^
		 */
		CPropEditorData( const CDedRosenFileData* pCDedRosenFileData ) ;

	public:
		// ********************************
		///@name UI�\���f�[�^���擾�E�ݒ�
		// ********************************
		///@{
		/**
		@return
		 	�H������UI�\���f�[�^
		 */
		std::string	getUIRosenName()const ;
		/**
		@param value [in]
		 	�H������UI�\���f�[�^
		 */
		void setUIRosenName( const std::string& value ) ;

		/**
		@return
			�_�C���̋N�_������UI�\���f�[�^
		*/
		CdDedJikoku	getUIKitenJikoku()const ;
		/**
		@param value [in]
			�_�C���̋N�_������UI�\���f�[�^
		*/
		void setUIKitenJikoku( const CdDedJikoku& value ) ;
		
		/**
		@return
			�_�C���O�����̊���̉w�ԕ��BUI�\���f�[�^�B
		*/
		int	getUIDiagramDgrYZahyouKyoriDefault()const ;

		/**
		@param value [in]
			�_�C���O�����̊���̉w�ԕ��BUI�\���f�[�^�B
		*/
		void setUIDiagramDgrYZahyouKyoriDefault( int value ) ;
		

		/**
		@return
			DiagramEdit �̕\�������BUI�\���f�[�^�B
		*/
		CdDedDispProp	getUIDispProp()const ;
		/**
		@return
			DiagramEdit �̕\�������BUI�\���f�[�^�B
		*/
		void setUIDispProp(CdDedDispProp& value ) ;

	public:
		// ********************************
		///@name �ҏW�Ώۃf�[�^��K�p
		// ********************************
		///@{
		/**
			�ҏW�Ώۃf�[�^���A�H���t�@�C���f�[�^�ɓK�p���܂��B
		@param pApplyTo [in]
			�ҏW�Ώۃf�[�^�̓K�p����w�肵�Ă��������B
		*/
		void applyTo( CDedRosenFileData* pApplyTo ) ;
		
		/**
			�ҏW�Ώۃf�[�^�����ƂɁA
			�H���t�@�C���f�[�^�̍X�V�R�}���h�𐶐����܂��B
		*/
		Ou<CRfEditCmd> createEditCmd  ();
		///@}
	};


private:
	// ********************************
	///@name	����
	// ********************************
	///@{
	///@}
private:
	// ********************************
	///@name	���
	// ********************************
	///@{
	/**
		�ҏW�Ώۃf�[�^��ێ����܂��B
	*/
	CPropEditorData	m_PropEditorData ;

	/** �w�H���x�y�[�W */
	CDlgRosenFileProp_Rosen	m_CDlgRosenFileProp_Rosen ;

	/** �w�t�H���g�E�F�x�y�[�W */
	CDlgRosenFileProp_FontColor	m_CDlgRosenFileProp_FontColor ;

	/** �w�_�C���O�����x�y�[�W */
	CDlgRosenFileProp_Diagram	m_CDlgRosenFileProp_Diagram ;
	///@}

	// --------------------------------
	///@name	CDlgRosenFileProp-�����֐�
	// --------------------------------
	///@{
	/**
		�^�u�R���g���[���̑���ɏ]���āA
		�q�_�C�A���O�̕\���E��\����Ԃ�
		�X�V���܂��B
	*/
	void CDlgRosenFileProp::UpdateChildWindowShow() ;
	///@}
// ********************************
//	CDlgRosenFileProp
// ********************************
 public:
	// ********************************
	///@name	CDlgRosenFileProp-����
	// ********************************
	///@{
	///@}
	// ********************************
	///@name	CDlgRosenFileProp-���
	// ********************************
	///@{
	/**
		�ҏW�Ώۃf�[�^��ێ����܂��B
	*/
	CPropEditorData* getPropEditorData() ;
	///@}

// ----------------------------------------------------------------
// �R���X�g���N�V����
public:
	/**
	 @param pCDedRosenFileData [in]
		�w�H���t�@�C���x�̃f�[�^
	 @param pParent [in]
		�e�E�C���h�E���w�肵�Ă��������B
	 */
	CDlgRosenFileProp(
		const CDedRosenFileData*	pCDedRosenFileData ,
		CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgRosenFileProp)
	enum { IDD = IDD_RosenFileProp };
	CTabCtrl	m_tabMAIN;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgRosenFileProp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgRosenFileProp)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace ViewRosen

#endif // !defined(AFX_CDLGROSENFILEPROP_H__A77A598D_541C_4EF8_B8EA_587920B81B1E__INCLUDED_)
