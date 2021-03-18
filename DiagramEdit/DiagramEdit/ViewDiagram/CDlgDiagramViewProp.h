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
#if !defined(AFX_CDLGDIAGRAMVIEWPROP_H__D8AE6377_97CA_40C0_9F4F_20941F78F55F__INCLUDED_)
#define AFX_CDLGDIAGRAMVIEWPROP_H__D8AE6377_97CA_40C0_9F4F_20941F78F55F__INCLUDED_
/** @file */
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgDiagramViewProp.h : �w�b�_�[ �t�@�C��
//
namespace ViewDiagram{

/////////////////////////////////////////////////////////////////////////////
// CDlgDiagramViewProp �_�C�A���O
/**
 @brief
	�_�C���O�����r���[�̃v���p�e�B�_�C�A���O�ł��B
 */
class CDlgDiagramViewProp : public CDialog
{
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
		�w�_�C���O�����G���e�B�e�B���W�n�x�͈̔́B
		�ʏ�́A CentDedDgrDia::getZone() �̒l��
		�w�肵�ĉ������B
		
		���̒l�́A m_zonexyCWndDiagramZone_Dgr ��
		���~�b�g�Ƃ��Ďg���܂��Bthis �͂��̒l��ύX���܂���B
	 */
	CdDcdZoneXy	m_zonexyCentDedDiaZone_Dgr ;

	/**
		�����̃G�f�B�b�g�{�b�N�X��L���ɂ��邩�ۂ��������܂��B
		�R���X�g���N�^�Ō��܂�܂��B
	*/
	BOOL m_bEnableYokojiku ;

	/**
		�c���̃G�f�B�b�g�{�b�N�X��L���ɂ��邩�ۂ��������܂��B
		�R���X�g���N�^�Ō��܂�܂��B
	*/
	BOOL m_bEnableTatejiku ;


	/**
		�_�C���O�����r���[�̃E�C���h�E�̃N���C�A���g�̈���A
		�w�_�C���O�����G���e�B�e�B���W�n�x�ŕ\���܂��B
		�ʏ�́A CWndDiagram::getZone_Dgr() �̒l�ƂȂ�܂��B
	
		�����l�̓R���X�g���N�^�Ō��܂�܂��B
		���̒l�̓_�C�A���O�J�n���ɁA
		�_�C�A���O��ɔ��f����܂��B
		�_�C�A���O�� OK �ŏI���������Ƃ́Athis ��
		�R���g���[���̓��e�����̒l�ɔ��f���܂��B
	 */
	CdDcdZoneXy	m_zonexyCWndDiagramZone_Dgr ;

	/**
		�c�r�̊Ԋu�̃��[�h�B
	
		�����l�̓R���X�g���N�^�Ō��܂�܂��B
		���̒l�̓_�C�A���O�J�n���ɁA
		�_�C�A���O��ɔ��f����܂��B
		�_�C�A���O�� OK �ŏI���������Ƃ́Athis ��
		�R���g���[���̓��e�����̒l�ɔ��f���܂��B
	 */
	int m_idxVlineMode ; 
///@}

// ********************************
//	CDlgDiagramViewProp
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	CdDcdZoneXy	getCentDedDiaZone_Dgr(){
		return m_zonexyCentDedDiaZone_Dgr ;};
	CdDcdZoneXy	getCWndDiagramZone_Dgr(){
		return m_zonexyCWndDiagramZone_Dgr ;};
	int getVlineMode(){
		return m_idxVlineMode ;}; 
///@}

// ----------------------------------------------------------------
// �R���X�g���N�V����
public:
	/**
	 @param zonexyCentDedDiaZone_Dgr [in]
		�w�_�C���O�����G���e�B�e�B���W�n�x�͈̔́B
		�ʏ�́A CentDedDgrDia::getZone() �̒l��
		�w�肵�ĉ������B
	 @param bEnableYokojiku[in]
		�����̃G�f�B�b�g�{�b�N�X��L���ɂ��邩�ۂ���
		�w�肵�Ă��������B
	 @param bEnableTatejiku[in]
		�c���̃G�f�B�b�g�{�b�N�X��L���ɂ��邩�ۂ��������܂��B
		�w�肵�Ă��������B
	 @param zonexyCWndDiagramZone_Dgr [in]
		�_�C���O�����r���[�̃E�C���h�E�̃N���C�A���g�̈���A
		�w�_�C���O�����G���e�B�e�B���W�n�x�ŕ\���܂��B
		�ʏ�́A CWndDiagram::getZone_Dgr() �̒l�ƂȂ�܂��B
	 @param idxVlineMode [in]
		�c�r�̊Ԋu�̃��[�h�B
	 @param pParent [in]
		�e�E�C���h�E���w�肵�ĉ������B
	 */
	CDlgDiagramViewProp(
		const CdDcdZoneXy&	zonexyCentDedDiaZone_Dgr ,
		BOOL bEnableYokojiku ,
		BOOL bEnableTatejiku ,
		const CdDcdZoneXy&	zonexyCWndDiagramZone_Dgr ,
		int idxVlineMode ,
		CWnd* pParent = NULL);   // �W���̃R���X�g���N�^


// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgDiagramViewProp)
	enum { IDD = IDD_DiagramViewProp };
	CString	m_strEDIT_YokojikuPos;
	CString	m_strEDIT_YokojikuSize;
	int		m_iCOMBO_Jikanmemori;
	UINT	m_iEDIT_TatejikuPos;
	UINT	m_iEDIT_TatejikuSize;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgDiagramViewProp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgDiagramViewProp)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace ViewDiagram

#endif // !defined(AFX_CDLGDIAGRAMVIEWPROP_H__D8AE6377_97CA_40C0_9F4F_20941F78F55F__INCLUDED_)
