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
#if !defined(AFX_CDLGRESSYASYUBETSUPROP_H__DD11A21B_8A73_4E63_86B1_61F55508609E__INCLUDED_)
#define AFX_CDLGRESSYASYUBETSUPROP_H__DD11A21B_8A73_4E63_86B1_61F55508609E__INCLUDED_
/** @file */
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgRessyasyubetsuProp.h : �w�b�_�[ �t�@�C��
//

#include "OuDlg/CKeyinputSenderToModalDlg.h"
#include "CDcdFreeLine_StyleSample.h"
#include "DcDraw\CDcdTextbox.h"
#include "DedRosenFileData\CdDedDispProp.h"
#include "CPropEditUi_Ressyasyubetsu.h"

namespace ViewRessyasyubetsu{ 

/////////////////////////////////////////////////////////////////////////////
// CDlgRessyasyubetsuProp �_�C�A���O

/**
 * @brief
 *	�w��Ԏ�ʂ̃v���p�e�B�x�_�C�A���O�ł��B
 */
class CDlgRessyasyubetsuProp : public CDialog
{
private:
	// ================================================================
	//	CDlgRessyasyubetsuProp::CPropEditUiInternal
	// ================================================================
	/**
	@brief
	  ��Ԏ�ʃv���p�e�B�̕ҏW���s���N���X�ł��B

	 �wUiData - UiControl �Ԃ̃f�[�^�]���x�̉��z�֐��ɁA
	UI���Ɉˑ������������������Ă��܂��B
	*/
	
	class CPropEditUiInternal : public CPropEditUi_Ressyasyubetsu
	{
	protected:
		// ================================
		/** @name �I�[�o�[���C�g�̕K�v�ȃ��\�b�h2-UI�Ɉˑ����鏈��
			UiData �� Ui �Ƃ̊Ԃ̃f�[�^�����̂��߂̃��\�b�h�ł��B
			���̃O���[�v�̃��\�b�h�́A Ui �̊�(Windows,MFC�Ȃ�)
			�Ɉˑ����鏈���������������܂��B
		*/
		// ================================
		///@{
		/**
			UiData�̓��e��Ui�ɔ��f���܂��B
			
			CPropEditUi2::StartEdit(),CPropEditUi2::OnUiChanged(),
			CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
			����Ăяo����܂��B
			
			�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
			UiData�̃����o�̓��e��Ui�ɕ\�����鏈�����������Ă��������B
		@param pUiData [in]
			UiData �̃I�u�W�F�N�g�B
		*/
		virtual void UiDataToUi( const UIDATA* pUiData ) ;
		
		
		/**
			Ui�̓��͓��e��UiData�ɔ��f���܂��B
			
			CPropEditUi2::OnUiChanged(),
			CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
			����Ăяo����܂��B
			
			�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
			Ui �ւ̕ύX���e��UiData �ɔ��f���鏈�����������Ă��������B
		@param pUiData [out]
			UiData �̃I�u�W�F�N�g�B
		*/
		virtual void UiDataFromUi( UIDATA* pUiData ) ;
		
		/**
			��ʏ�ɃG���[���b�Z�[�W��\�����܂��B

			�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
			�G���[���b�Z�[�W��\�����鏈�����������Ă��������B
			
			MFC�A�v���P�[�V�����ł́A�ʏ�́A���b�Z�[�W�{�b�N�X��\�����܂��B
		@param strErrorReason [in]
			�G���[�̓��e������������
		@param strInfo [in]
			�G���[�̕⏕��������������B�s�v�ł���΁A�󕶎����
			�w�肵�Ă��������B
		*/
		virtual void ShowError( 
			const std::string& strErrorReason ,
			const std::string& strInfo = "" )  ;
		
		/**
			Ui ��̓���̃R���g���[���ɁA�t�H�[�J�X��ݒ肵�܂��B

			�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
			�w�肳�ꂽ�R���g���[���Ƀt�H�[�J�X��ݒ肷�鏈�����������Ă��������B
			
		@param iOffsetofUiDataMember [in]
			�t�H�[�J�X��ݒ肷��ҏW���ڂ��w�肵�Ă��������B
			UiData���̑ΏۂƂȂ�f�[�^�����o�́A�\���̂̐擪�A�h���X�����
			�I�t�Z�b�g���w�肵�Ă��������B

		��:�t�H�[�J�X���AUiData�̃����o strNumber ����͂���R���g���[���ɐݒ�
			����ꍇ�́A�ȉ��̂悤�ɂ��Ă��������B
		@code
			SetFocus( offsetof(UIDATA,strNumber ) ) ;
		@endcode
		*/
		virtual void SetFocus( int iOffsetofUiDataMember )  ;
		///@}

	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************
		/**
		@param bNewItem [in]
			�ҏW�Ώۂ��w�肵�Ă��������B
			- true: �V�K�I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
			- false: �����I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
		@param pTarget [in,out]
		�@Target(�ҏW�Ώۂ̃v���p�e�B��ێ�����ϐ��ւ̃|�C���^)�B 
		�@�R���X�g���N�^�Ō��܂�܂��B
		*/
		CPropEditUiInternal( bool bNewItem , Mu<CentDedRessyasyubetsu*>* pTarget );
		
	} m_PropEditUiInternal ;
	friend class CPropEditUiInternal ;

private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
	  �e�E�C���h�E�ւ̃L�[���͂��_�@�� ModalDialog ���J���ꍇ�A
	 ���[�_���_�C�A���O�̓���̃G�f�B�b�g�R���g���[���ɁA
	 �L�[���̓��b�Z�[�W�i WM_KEYDOWN , WM_KEYUP �j��]�����܂��B
	
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�i�w�]�����E�C���h�E�x�j
		�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
		�s�v�ł���� NULL �ł����܂��܂���B
		�R���X�g���N�^�Ō��܂�܂��B
	*/
	CKeyinputSenderToModalDlg*	m_pCKeyinputSenderToModalDlg ;
	///@}
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	�ŏ��Ƀt�H�[�J�X��ݒ肷�鍀�ڂ�ێ����܂��B
	�R���X�g���N�^�Ō��܂�܂��B
	-	0	;	//	��Ԏ�ʖ�
	-	1	;	//	����
	-	2	;	//	�_�C���O������

	OnShowWindow() �Ńt�H�[�J�X��ݒ肵�܂��B
	�t�H�[�J�X�ݒ��́A -1 �ɕς��܂��B
	 */
	int m_iFocusItem ;
	///@}
 private:
	// --------------------------------
	//	�����f�[�^
	// --------------------------------
	///@{
	/**
		����̎����\�t�H���g�B
		
		�R���X�g���N�^�Ō��܂�܂��B
	*/
	CdFontProp	m_fontpropJikokuhyouFont[CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT] ;

	/**
	 IDC_STATIC_JikokuhyouMojiColor
	�ɕ\������A�F�̌��{�ł��B
	 OnInitDialog �Ő����BOnDestroy�Ŕj�����܂��B
	 �\���Ɋւ��鑮���́AupdateControl() �Ŕ��f���܂��B
	 */
	CDcdRectangle*	m_pdcdJikokuhyouMojiColor ;

	/**
	 IDC_STATIC_JikokuhyouFont
	�ɕ\������A�����̌��{�ł��B
	 OnInitDialog �Ő����BOnDestroy�Ŕj�����܂��B
	 �\���Ɋւ��鑮���́AupdateControl() �Ŕ��f���܂��B
	OnInitDialog() �Ő����EOnDestroy() �Ŕj�����܂��B
	*/
	CDcdTextbox*	m_pdcdJikokuhyouFont ;

	/**
	 IDC_STATIC_DiagramSen
	�ɕ\������A���̌��{�ł��B
	 OnInitDialog �Ő����BOnDestroy�Ŕj�����܂��B
	 �\���Ɋւ��鑮���́AupdateControl() �Ŕ��f���܂��B
	*/
	CDcdFreeLine_StyleSample*	m_pdcdDiagramSen ;
	///@}
protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	///@}


 public:
	// ********************************
	///@name CDlgRessyasyubetsuProp-����
	// ********************************
	///@{
	///@}

// ----------------------------------------------------------------
// �R���X�g���N�V����
public:

	/**
	@param bNewItem 
		�ҏW�Ώۂ��w�肵�Ă��������B
		- true: �V�K�I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
		- false: �����I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
	@param pTarget [in,out]
		�ҏW�ΏہB�R���X�g���N�^�Ō��܂�܂��B
		��Ԏ�ʂ��i�[�����R���e�i�ł��B
	@param aCdDedDispProp 
		OuDia�̕\�������B
		���̃I�u�W�F�N�g�́A�t�H���g��\�����邽�߂�
		m_fontpropJikokuhyouFont �̏������Ɏg���܂��B
	@param iFocusItem 
		�ŏ��Ƀt�H�[�J�X��ݒ肷�鍀�ڂ�ێ����܂��B
		�R���X�g���N�^�Ō��܂�܂��B
		- 0	;	//	��Ԏ�ʖ�
		- 1	;	//	����
		- 2	;	//	�_�C���O������
	@param pCKeyinputSenderToModalDlg 
	  �e�E�C���h�E�ւ̃L�[���͂��_�@�� ModalDialog ���J���ꍇ�A
	 ���[�_���_�C�A���O�̓���̃G�f�B�b�g�R���g���[���ɁA
	 �L�[���̓��b�Z�[�W�i WM_KEYDOWN , WM_KEYUP �j��]�����܂��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�i�w�]�����E�C���h�E�x�j
		�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
		�s�v�ł���� NULL �ł����܂��܂���B
	@param pParent 
		�e�E�C���h�E�I�u�W�F�N�g���w�肵�Ă��������B
	*/
	CDlgRessyasyubetsuProp(
		bool bNewItem , 
		Mu<CentDedRessyasyubetsu*>* pTarget ,
		const CdDedDispProp&	aCdDedDispProp ,
		int iFocusItem , 
		CKeyinputSenderToModalDlg* pCKeyinputSenderToModalDlg , 
		CWnd* pParent = NULL);

	virtual ~CDlgRessyasyubetsuProp() ;

// �_�C�A���O �f�[�^
private:
	//{{AFX_DATA(CDlgRessyasyubetsuProp)
	enum { IDD = IDD_RessyasyubetsuProp };
	//}}AFX_DATA
// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgRessyasyubetsuProp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgRessyasyubetsuProp)
	virtual BOOL OnInitDialog();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnPaint();
	virtual void OnOK();
	afx_msg void OnCHECKDiagramSenStyleIsBold();
	afx_msg void OnBUTTONJikokuhyouMojiColor();
	afx_msg void OnBUTTONDiagramSeniColor();
	afx_msg void OnSelchangeCOMBODiagramSenStyle();
	afx_msg void OnCbnSelchangeComboJikokuhyoufontindex();
	afx_msg void OnEnKillfocusEditSyubetsumei();
	afx_msg void OnEnKillfocusEditRyakusyou();
	afx_msg void OnCbnSelchangeComboStopmarkdrawtype();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B


} //namespace ViewRessyasyubetsu

#endif // !defined(AFX_CDLGRESSYASYUBETSUPROP_H__DD11A21B_8A73_4E63_86B1_61F55508609E__INCLUDED_)
