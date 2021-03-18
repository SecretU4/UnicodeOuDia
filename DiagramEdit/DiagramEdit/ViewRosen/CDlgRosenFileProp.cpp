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
// CDlgRosenFileProp.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"

#include "str/CStrCharSizeMb.h"
#include "DcDraw\CConverter_WinGdi.h"

#include "..\DiagramEdit.h"
#include "..\DedRosenFileData\EditCmd\CRfEditCmd_DedRosenFileDataProp.h"
#include "CDlgRosenFileProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRosen{


// ****************************************************************
//	CPropEditorData
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
/**
 @param pCDedRosenFileData [in]
	�w�H���t�@�C���x�̃f�[�^
 */
CDlgRosenFileProp::CPropEditorData::CPropEditorData( 
	const CDedRosenFileData* pCDedRosenFileData ) :
	m_strRosenName( pCDedRosenFileData->getCentDedRosen()->getName() ) 
	, m_jikokuKitenJikoku( pCDedRosenFileData->getCentDedRosen()->getKitenJikoku() ) 
	, m_iDiagramDgrYZahyouKyoriDefault( pCDedRosenFileData->getCentDedRosen()->getDiagramDgrYZahyouKyoriDefault() ) 
	, m_CdDedDispProp( pCDedRosenFileData->getCdDedDispProp() ) 
{
}

	// ********************************
	//@name UI�\���f�[�^���擾�E�ݒ�
	// ********************************
std::string	CDlgRosenFileProp::CPropEditorData::getUIRosenName()const 
{
	return m_strRosenName ;
}
void CDlgRosenFileProp::CPropEditorData::setUIRosenName( 
	const std::string& value ) 
{
	m_strRosenName = value ;
}

CdDedJikoku	CDlgRosenFileProp::CPropEditorData::getUIKitenJikoku()const 
{
	return m_jikokuKitenJikoku ;
}
void CDlgRosenFileProp::CPropEditorData::setUIKitenJikoku( 
	const CdDedJikoku& value ) 
{
	m_jikokuKitenJikoku = value ;
}
int	
CDlgRosenFileProp::CPropEditorData::getUIDiagramDgrYZahyouKyoriDefault()const 
{
	return m_iDiagramDgrYZahyouKyoriDefault ;
}


void CDlgRosenFileProp::CPropEditorData::setUIDiagramDgrYZahyouKyoriDefault( 
	int value ) 
{
	m_iDiagramDgrYZahyouKyoriDefault = value ;
}


CdDedDispProp CDlgRosenFileProp::CPropEditorData::getUIDispProp()const
{
	return m_CdDedDispProp ;
}


void 
CDlgRosenFileProp::CPropEditorData::setUIDispProp(CdDedDispProp& value)
{
	m_CdDedDispProp = value ;
}

	// ********************************
	//@name �ҏW�Ώۃf�[�^��K�p
	// ********************************
void CDlgRosenFileProp::CPropEditorData::applyTo( CDedRosenFileData* pApplyTo )
{
	pApplyTo->getCentDedRosen()->setName( m_strRosenName ) ;
	pApplyTo->getCentDedRosen()->setKitenJikoku( m_jikokuKitenJikoku ) ;
	pApplyTo->getCentDedRosen()->setDiagramDgrYZahyouKyoriDefault( m_iDiagramDgrYZahyouKyoriDefault ) ;
	pApplyTo->setCdDedDispProp( m_CdDedDispProp ) ;
}

Ou<CRfEditCmd> 
CDlgRosenFileProp::CPropEditorData::createEditCmd  ()
{
	OuNew<CRfEditCmd> pCmd( 
		new CRfEditCmd_DedRosenFileDataProp( 
			m_strRosenName , 
			m_jikokuKitenJikoku , 
			m_iDiagramDgrYZahyouKyoriDefault , 
			m_CdDedDispProp 
		) 
	) ;
	return pCmd ;
}


/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp �_�C�A���O
void CDlgRosenFileProp::UpdateChildWindowShow()
{
		int	iLCurSel = m_tabMAIN.GetCurSel() ;
	
		switch( iLCurSel ){
		 case 0:
			m_CDlgRosenFileProp_Rosen.ShowWindow( SW_SHOWNORMAL ) ;
			m_CDlgRosenFileProp_FontColor.ShowWindow( SW_HIDE ) ;
			m_CDlgRosenFileProp_Diagram.ShowWindow( SW_HIDE ) ;
			break ;
		 case 1:
			m_CDlgRosenFileProp_Rosen.ShowWindow( SW_HIDE ) ;
			m_CDlgRosenFileProp_FontColor.ShowWindow( SW_SHOWNORMAL ) ;
			m_CDlgRosenFileProp_Diagram.ShowWindow( SW_HIDE ) ;
			break ;
		 case 2:
			m_CDlgRosenFileProp_Rosen.ShowWindow( SW_HIDE ) ;
			m_CDlgRosenFileProp_FontColor.ShowWindow( SW_HIDE ) ;
			m_CDlgRosenFileProp_Diagram.ShowWindow( SW_SHOWNORMAL ) ;
			break ;
		}
	
}

/** �����̏�����ێ����܂��B */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	false ,		//	NoColon 
	CdDedJikoku::CConv::EHour_Zero ,	// ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" �Ƃ��܂�
	CdDedJikoku::CConv::ESecond_NoSecond 	// �b����ɏo�͂��܂���B 
	) ;


CDlgRosenFileProp::CPropEditorData* 
CDlgRosenFileProp::getPropEditorData() 
{
	return &m_PropEditorData ;
}

CDlgRosenFileProp::CDlgRosenFileProp(
		const CDedRosenFileData*	pCDedRosenFileData ,
		CWnd* pParent )
	: CDialog(CDlgRosenFileProp::IDD, pParent)
	, m_PropEditorData( pCDedRosenFileData ) 
{
	//{{AFX_DATA_INIT(CDlgRosenFileProp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT

}



void CDlgRosenFileProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRosenFileProp)
	DDX_Control(pDX, IDC_TAB_MAIN, m_tabMAIN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRosenFileProp, CDialog)
	//{{AFX_MSG_MAP(CDlgRosenFileProp)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, OnSelchangeTabMain)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp ���b�Z�[�W �n���h��

BOOL CDlgRosenFileProp::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CWaitCursor	aCursor ;

	//--------------------------------
	//	�q�_�C�A���O�𐶐�
	//--------------------------------
	{
		m_CDlgRosenFileProp_Rosen.Create( m_CDlgRosenFileProp_Rosen.IDD , this ) ;
		m_CDlgRosenFileProp_FontColor.Create( m_CDlgRosenFileProp_FontColor.IDD , this ) ;
		m_CDlgRosenFileProp_Diagram.Create( m_CDlgRosenFileProp_Diagram.IDD , this ) ;
	}
	// --------------------------------	
	//	�^�u�ɃA�C�e����ǉ�
	//	(���̏����́A�q�_�C�A���O������Ɏ��s����K�v������܂��B
	//	���R�F�q�_�C�A���O�̃R���g���[������^�u�����擾���邽��)
	// --------------------------------	
	{
		CString	aStr ;
		m_CDlgRosenFileProp_Rosen.GetDlgItem( IDC_STATIC_TABNAME )->GetWindowText( aStr ) ;
		TC_ITEM	LTcItem ;
		LTcItem.mask = TCIF_TEXT ;
		LTcItem.pszText = const_cast<char*>( (LPCTSTR)aStr ) ;
		m_tabMAIN.InsertItem( m_tabMAIN.GetItemCount() 
											, &LTcItem ) ;
	}	
	{
		CString	aStr ;
		m_CDlgRosenFileProp_FontColor.GetDlgItem( IDC_STATIC_TABNAME )->GetWindowText( aStr ) ;
		TC_ITEM	LTcItem ;
		LTcItem.mask = TCIF_TEXT ;
		LTcItem.pszText = const_cast<char*>( (LPCTSTR)aStr ) ;
		m_tabMAIN.InsertItem( m_tabMAIN.GetItemCount() 
											, &LTcItem ) ;
	}	
	{
		CString	aStr ;
		m_CDlgRosenFileProp_Diagram.GetDlgItem( IDC_STATIC_TABNAME )->GetWindowText( aStr ) ;
		TC_ITEM	LTcItem ;
		LTcItem.mask = TCIF_TEXT ;
		LTcItem.pszText = const_cast<char*>( (LPCTSTR)aStr ) ;
		m_tabMAIN.InsertItem( m_tabMAIN.GetItemCount() 
											, &LTcItem ) ;
	}	

	//--------------------------------
	//	�q�_�C�A���O�̈ʒu������
	//--------------------------------
	{
		WINDOWPLACEMENT	LWindowplacement ;
		CRect	LRect ;
		m_tabMAIN.GetWindowPlacement( &LWindowplacement ) ;
		LRect = LWindowplacement.rcNormalPosition ;
		m_tabMAIN.AdjustRect( FALSE , &LRect ) ;
		LWindowplacement.rcNormalPosition = LRect ;

		m_CDlgRosenFileProp_Rosen.SetWindowPlacement( &LWindowplacement ) ;
		m_CDlgRosenFileProp_Rosen.SetWindowPos( &m_tabMAIN
			, 0 , 0 , 0 , 0 , SWP_NOMOVE | SWP_NOSIZE ) ;

		m_CDlgRosenFileProp_FontColor.SetWindowPlacement( &LWindowplacement ) ;
		m_CDlgRosenFileProp_FontColor.SetWindowPos( &m_tabMAIN
			, 0 , 0 , 0 , 0 , SWP_NOMOVE | SWP_NOSIZE ) ;

		m_CDlgRosenFileProp_Diagram.SetWindowPlacement( &LWindowplacement ) ;
		m_CDlgRosenFileProp_Diagram.SetWindowPos( &m_tabMAIN
			, 0 , 0 , 0 , 0 , SWP_NOMOVE | SWP_NOSIZE ) ;
	}
	//--------------------------------
	//	�ҏW�Ώۃf�[�^��UI�ɔ��f����
	//--------------------------------
	{
		m_CDlgRosenFileProp_Rosen.updateUI() ;
		m_CDlgRosenFileProp_FontColor.updateUI() ;
		m_CDlgRosenFileProp_Diagram.updateUI() ;
	}
	// --------------------------------
	UpdateChildWindowShow() ;

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgRosenFileProp::OnOK() 
{
	if ( m_CDlgRosenFileProp_Rosen.updatePropEditorData() < 0 )
	{
		m_tabMAIN.SetCurSel( 0 ) ;
		UpdateChildWindowShow() ;
	}
	else if ( m_CDlgRosenFileProp_FontColor.updatePropEditorData() < 0 )
	{
		m_tabMAIN.SetCurSel( 1 ) ;
		UpdateChildWindowShow() ;
	}
	else if ( m_CDlgRosenFileProp_Diagram.updatePropEditorData() < 0 )
	{
		m_tabMAIN.SetCurSel( 2 ) ;
		UpdateChildWindowShow() ;
	}
	else
	{
		CDialog::OnOK();
	}
}

void CDlgRosenFileProp::OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateChildWindowShow() ;
	
	*pResult = 0;
}
} //namespace ViewRosen
