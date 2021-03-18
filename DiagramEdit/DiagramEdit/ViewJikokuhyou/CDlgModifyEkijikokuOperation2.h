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
#if !defined(AFX_CDLGMODIFYEKIJIKOKUOPERATION2_H__10F94D00_0F5B_43AA_BAAC_6330BDCE7CD9__INCLUDED_)
#define AFX_CDLGMODIFYEKIJIKOKUOPERATION2_H__10F94D00_0F5B_43AA_BAAC_6330BDCE7CD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cdlgmodifyekijikokuoperation2.h : �w�b�_�[ �t�@�C��
//
/** @file */
#include "..\entDed\CentDedRessya.h"
#include "..\entDed\CentDedRessya_EkijikokuModifyOperation2.h"

namespace ViewJikokuhyou{

/////////////////////////////////////////////////////////////////////////////
// CDlgModifyEkijikokuOperation2 �_�C�A���O
/**
   @brief
  	�w�w�����ύX�x���[�_���_�C�A���O�ł��B
  
   �y�g�����z
  
  	�P�D  �R���X�g���N�^�̈����ɂ́A�_�C�A���O�̏����ݒ�l��
  	�w�肵�Ă��������B
  	
  	�Q�D  DoModal() �ŁA�_�C�A���O���J�n���Ă��������B
  	
  	�R�D  DoModal() �̖߂�l�� IDOK �̏ꍇ�́A
  	 m_EkijikokuModifyOperation �ɁA�_�C�A���O�ւ̓��͓��e���i�[
  	����Ă��܂��B
 */

class CDlgModifyEkijikokuOperation2 : public CDialog
{
private:
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
		�w����ێ����܂��B
		�R���X�g���N�^�� pCentDedEkiContGet �����ƂɌ��܂�܂��B
	*/
	std::deque<std::string>	m_contstrEkimei ;
	/**
	  	�R���X�g���N�^�Ō��܂�܂��B
	  	���̒l�́A�_�C�A���O�̏����l�ɔ��f����܂��B
	  
	    OnOK() �́A�_�C�A���O�̓��͓��e���A���̕ϐ��ɐݒ肵�܂��B
	    ���̒l�́A���\�b�h�Ŏ擾�ł��܂��B
	 */
	CentDedRessya_EkijikokuModifyOperation2 m_EkijikokuModifyOperation2 ;
	///@}
protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
	  	�R���g���[���̑I���󋵂ɉ����āA�L���E������؂�ւ��܂��B
	   @return
	  	�R���g���[���̏�Ԃ�ύX�����ꍇ�͐^�ł��B
	 */
	virtual bool updateControl() ; 

	/**
		�R�s�[���R���{�{�b�N�X�̃C���f�N�X���A
		CdDedJikokuOrder ���瓱�o���܂��B
	@param aJikokuOrder [in]
		����Order���w�肵�Ă��������B
	@return 
		�Ή�����R���{�{�b�N�X��Index��Ԃ��܂��B
		�R���{�{�b�N�X�ɑΉ�����A�C�e�����Ȃ��ꍇ�́A-1��Ԃ��܂��B
	*/
	int COMBO_JikokuOuderCopySrcFromJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder ) ;

	/**
		�R�s�[���R���{�{�b�N�X�̃C���f�N�X����A
		CdDedJikokuOrder �𓱏o���܂��B
	@param iComboIndex [in]
		�R���{�{�b�N�X��Index���w�肵�Ă��������B
	@return 
		�Ή�����CdDedJikokuOrder��Ԃ��܂��B
		�Ή����鎞��Order���Ȃ��ꍇ�́A NULL��Ԃ�Ԃ��܂��B
	*/
	CdDedJikokuOrder COMBO_JikokuOuderCopySrcToJikokuOrder( 
		int iComboIndex ) ;

	///@}
public:
	// ********************************
	//	CDlgModifyEkijikokuOperation
	// ********************************
	// ********************************
	///@name	����
	// ********************************
	///@{
	CentDedRessya_EkijikokuModifyOperation2 getCentDedRessya_EkijikokuModifyOperation2(){
		return m_EkijikokuModifyOperation2 ;};
	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

// �R���X�g���N�V����
public:
	/**
	 @param aEkijikokuModifyOperation2 [in]
		������Ԃ́w�w�����ύX�x������e���w�肵�Ă��������B
	 @param pCentDedEkiContGet [in]
		�w����ێ�����R���e�i���w�肵�Ă��������B
		���̈����Ŏw�肷��R���e�i�́A���p���鎞���\�r���[�̏��E����ɏ�����
		���̂��w�肵�Ă��������B
		���̃C���X�^���X�́A�R���X�g���N�^���I���������Ƃ́A�j�����邱�Ƃ��ł��܂��B
	 @param pParent [in]
		�e�E�C���h�E���w�肵�Ă��������B
	*/
	CDlgModifyEkijikokuOperation2(
		CentDedRessya_EkijikokuModifyOperation2& aEkijikokuModifyOperation2 ,
		const Mu<CentDedEkiCont::CdDedEki>* pCentDedEkiContGet , 
		CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgModifyEkijikokuOperation2)
	enum { IDD = IDD_ModifyEkijikokuOperation2 };
	int		m_iRADIO_Ekiatsukai;
	BOOL	m_bCHECK_EkiatsukaiModify;
	int		m_iRADIO_EkijikokuOperation;
	int		m_iCOMBO_JikokuOuderCopySrc;
	int		m_iEDIT_Seconds1;
	int		m_iEDIT_Seconds2;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgModifyEkijikokuOperation2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgModifyEkijikokuOperation2)
	virtual BOOL OnInitDialog();
	afx_msg void OnRADIOEkijikokuOperation();
	afx_msg void OnRADIOEkijikokuOperation1();
	afx_msg void OnRADIOEkijikokuOperation3();
	afx_msg void OnRADIOEkijikokuOperation2();
	virtual void OnOK();
	afx_msg void OnCHECKEkiatsukaiModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace ViewJikokuhyou

#endif // !defined(AFX_CDLGMODIFYEKIJIKOKUOPERATION2_H__10F94D00_0F5B_43AA_BAAC_6330BDCE7CD9__INCLUDED_)
