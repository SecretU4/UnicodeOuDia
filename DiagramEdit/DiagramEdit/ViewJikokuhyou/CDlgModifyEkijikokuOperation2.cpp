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
// cdlgmodifyekijikokuoperation2.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "..\diagramedit.h"
#include "cdlgmodifyekijikokuoperation2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

/////////////////////////////////////////////////////////////////////////////
// CDlgModifyEkijikokuOperation2 �_�C�A���O
// --------------------------------
//@name �����֐�
// --------------------------------
bool CDlgModifyEkijikokuOperation2::updateControl() 
{
	bool bRv = false ;
	{
		CWnd* pCWnd = GetDlgItem( IDC_RADIO_Ekiatsukai ) ;
		BOOL bCurrentState = pCWnd->IsWindowEnabled() ;
		CButton* pCChekcbox = (CButton*)GetDlgItem(IDC_CHECK_EkiatsukaiModify) ;
		BOOL bState = ( pCChekcbox->GetCheck() == 1 );

		if ( ( bState && !bCurrentState ) ||
			( !bState && bCurrentState ) )
		{
			GetDlgItem( IDC_RADIO_Ekiatsukai )->EnableWindow( bState ) ;
			GetDlgItem( IDC_RADIO_Ekiatsukai1 )->EnableWindow( bState ) ;
			GetDlgItem( IDC_RADIO_Ekiatsukai2 )->EnableWindow( bState ) ;
			GetDlgItem( IDC_RADIO_Ekiatsukai3 )->EnableWindow( bState ) ;
			bRv = true ;
		}
	}
	{
		CButton* pCWnd = (CButton*)GetDlgItem( IDC_RADIO_EkijikokuOperation1 ) ;
		BOOL bCurrentState = GetDlgItem( IDC_EDIT_Seconds1 )->IsWindowEnabled() ;
		BOOL bState = ( ( pCWnd->GetCheck() & 3 ) == 1 ) ;
		if ( ( bState && !bCurrentState ) ||
			( !bState && bCurrentState ) ){
			GetDlgItem( IDC_EDIT_Seconds1 )->EnableWindow( bState ) ;
			bRv = true ;
		}
	}
	{
		CButton* pCWnd = (CButton*)GetDlgItem( IDC_RADIO_EkijikokuOperation2 ) ;
		BOOL bState = ( ( pCWnd->GetCheck() & 3 ) == 1 ) ;

		{
			BOOL bCurrentState = GetDlgItem( IDC_COMBO_JikokuOrderCopySrc )->IsWindowEnabled() ;

			if ( ( bState && !bCurrentState ) ||
				( !bState && bCurrentState ) ){
				GetDlgItem( IDC_COMBO_JikokuOrderCopySrc )->EnableWindow( bState ) ;
				bRv = true ;
			}
		}
		{
			BOOL bCurrentState = GetDlgItem( IDC_EDIT_Seconds2 )->IsWindowEnabled() ;
			if ( ( bState && !bCurrentState ) ||
				( !bState && bCurrentState ) ){
				GetDlgItem( IDC_EDIT_Seconds2 )->EnableWindow( bState ) ;
				bRv = true ;
			}
		}
	}
	return bRv ;
}

int CDlgModifyEkijikokuOperation2::COMBO_JikokuOuderCopySrcFromJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder ) 
{
	int iRv = -1 ;
	if ( !aJikokuOrder.getIsNull() )
	{
		iRv = aJikokuOrder.getEkiOrder() * 2 ;
		if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
		{
			iRv ++ ;
		}
	}
	return iRv ;
}

CdDedJikokuOrder 
CDlgModifyEkijikokuOperation2::COMBO_JikokuOuderCopySrcToJikokuOrder( 
		int iComboIndex ) 
{
	CdDedJikokuOrder	aRv ;
	if ( 0 <= iComboIndex && iComboIndex < (int)m_contstrEkimei.size() * 2 )
	{
		CdDedJikokuOrder::EEkiJikokuItem eEkiJikokuItem = CdDedJikokuOrder::EkiJikokuItem_Chaku ;
		if ( iComboIndex % 2 == 1 )
		{
			eEkiJikokuItem = CdDedJikokuOrder::EkiJikokuItem_Hatsu ;
		}
		aRv.setEkiOrder( iComboIndex / 2 , eEkiJikokuItem ) ;
	}
	return aRv ;
}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

CDlgModifyEkijikokuOperation2::CDlgModifyEkijikokuOperation2(
 	CentDedRessya_EkijikokuModifyOperation2& aEkijikokuModifyOperation2 ,
	const Mu<CentDedEkiCont::CdDedEki>* pCentDedEkiContGet , 
	CWnd* pParent )
	: CDialog(CDlgModifyEkijikokuOperation2::IDD, pParent)
	, m_EkijikokuModifyOperation2( aEkijikokuModifyOperation2 ) 
{
	//{{AFX_DATA_INIT(CDlgModifyEkijikokuOperation2)
	m_iRADIO_Ekiatsukai = aEkijikokuModifyOperation2.getEkiatsukai() ;
	m_bCHECK_EkiatsukaiModify = aEkijikokuModifyOperation2.getSetEkiatsukai() ;
	m_iRADIO_EkijikokuOperation = aEkijikokuModifyOperation2.getOperation() ;
	m_iCOMBO_JikokuOuderCopySrc = -1 ;
	m_iEDIT_Seconds1 = aEkijikokuModifyOperation2.getSeconds();
	m_iEDIT_Seconds2 = aEkijikokuModifyOperation2.getSeconds();
	//}}AFX_DATA_INIT

	CdDedJikokuOrder	aJikokuOrderCopySrc = aEkijikokuModifyOperation2.getJikokuOrderCopySrc() ;
	m_iCOMBO_JikokuOuderCopySrc = aJikokuOrderCopySrc.getEkiOrder()*2 ;
	if ( aJikokuOrderCopySrc.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu ){
		m_iCOMBO_JikokuOuderCopySrc ;
	}


	{
		int idxEki ;
		for ( idxEki = 0 ; idxEki < pCentDedEkiContGet->size() ; idxEki ++ )
		{
			m_contstrEkimei.push_back( pCentDedEkiContGet->get( idxEki ).getEkimei() ) ;
		}
	}
}


void CDlgModifyEkijikokuOperation2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgModifyEkijikokuOperation2)
	DDX_Radio(pDX, IDC_RADIO_Ekiatsukai, m_iRADIO_Ekiatsukai);
	DDX_Check(pDX, IDC_CHECK_EkiatsukaiModify, m_bCHECK_EkiatsukaiModify);
	DDX_Radio(pDX, IDC_RADIO_EkijikokuOperation, m_iRADIO_EkijikokuOperation);
	DDX_CBIndex(pDX, IDC_COMBO_JikokuOrderCopySrc, m_iCOMBO_JikokuOuderCopySrc);
	DDX_Text(pDX, IDC_EDIT_Seconds1, m_iEDIT_Seconds1);
	DDX_Text(pDX, IDC_EDIT_Seconds2, m_iEDIT_Seconds2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgModifyEkijikokuOperation2, CDialog)
	//{{AFX_MSG_MAP(CDlgModifyEkijikokuOperation2)
	ON_BN_CLICKED(IDC_RADIO_EkijikokuOperation, OnRADIOEkijikokuOperation)
	ON_BN_CLICKED(IDC_RADIO_EkijikokuOperation1, OnRADIOEkijikokuOperation1)
	ON_BN_CLICKED(IDC_RADIO_EkijikokuOperation3, OnRADIOEkijikokuOperation3)
	ON_BN_CLICKED(IDC_RADIO_EkijikokuOperation2, OnRADIOEkijikokuOperation2)
	ON_BN_CLICKED(IDC_CHECK_EkiatsukaiModify, OnCHECKEkiatsukaiModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgModifyEkijikokuOperation2 ���b�Z�[�W �n���h��

BOOL CDlgModifyEkijikokuOperation2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	{
		CComboBox*	pCComnoBox = (CComboBox*)GetDlgItem( IDC_COMBO_JikokuOrderCopySrc ) ;
		CString	strChaku ;
		CString	strHatsu ;
		strChaku.LoadString( IDS_WORD_Chaku ) ;
		strHatsu.LoadString( IDS_WORD_Hatsu ) ;
		int idxEki ;
		for ( idxEki = 0 ; idxEki < (int)m_contstrEkimei.size() ; idxEki ++ )
		{
			CString	strItem ;
			strItem = m_contstrEkimei[idxEki].c_str() ;
			pCComnoBox->AddString( strItem + strChaku ) ;
			pCComnoBox->AddString( strItem + strHatsu ) ;
		}
		pCComnoBox->SetCurSel( 
			COMBO_JikokuOuderCopySrcFromJikokuOrder( 
				m_EkijikokuModifyOperation2.getJikokuOrderCopySrc() ) );
	}
	updateControl() ;
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgModifyEkijikokuOperation2::OnRADIOEkijikokuOperation() 
{
	updateControl() ;
	
}

void CDlgModifyEkijikokuOperation2::OnRADIOEkijikokuOperation1() 
{
	updateControl() ;
	
}

void CDlgModifyEkijikokuOperation2::OnRADIOEkijikokuOperation3() 
{
	updateControl() ;
	
}

void CDlgModifyEkijikokuOperation2::OnRADIOEkijikokuOperation2() 
{
	updateControl() ;
	
}

void CDlgModifyEkijikokuOperation2::OnOK() 
{
	int iRv = 0 ;
	if ( iRv >= 0 )
	{
		if ( !UpdateData() )
		{
			iRv = -1 ;	//	�l���s���ł��B
		}
		else
		{
			m_EkijikokuModifyOperation2.setSetEkiatsukai( m_bCHECK_EkiatsukaiModify != FALSE ) ;
			m_EkijikokuModifyOperation2.setEkiatsukai( 
				(CentDedEkiJikoku::EEkiatsukai)m_iRADIO_Ekiatsukai ) ;
			m_EkijikokuModifyOperation2.setOperation( 
				(CentDedRessya_EkijikokuModifyOperation2::EOperation)m_iRADIO_EkijikokuOperation ) ;
			if ( m_EkijikokuModifyOperation2.getOperation() == 
				CentDedRessya_EkijikokuModifyOperation2::OperationModify )
			{
				m_EkijikokuModifyOperation2.setSeconds( m_iEDIT_Seconds1 ) ;
			}
			else if ( m_EkijikokuModifyOperation2.getOperation() == 
				CentDedRessya_EkijikokuModifyOperation2::OperationCopy )
			{
				m_EkijikokuModifyOperation2.setJikokuOrderCopySrc( 
					COMBO_JikokuOuderCopySrcToJikokuOrder( m_iCOMBO_JikokuOuderCopySrc ) ) ;
				m_EkijikokuModifyOperation2.setSeconds( m_iEDIT_Seconds2 ) ;
			}
		}
	}

	if ( iRv >= 0 )
	{
		CDialog::OnOK();
	}
}

void CDlgModifyEkijikokuOperation2::OnCHECKEkiatsukaiModify() 
{
	updateControl() ;
	
}
} //namespace ViewJikokuhyou

