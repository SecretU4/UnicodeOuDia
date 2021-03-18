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
// CDlgEkiProp.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"

#include "..\DiagramEdit.h"
#include "CDlgEkiProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


namespace ViewEki{


// ================================================================
//	CDlgEkiProp::CPropEditUiInternal
// ================================================================
	// ================================
	//@name CPropEditUi - UiData - UiControl �Ԃ̃f�[�^�]��
	// ================================
void CDlgEkiProp::CPropEditUiInternal::UiDataToUi( const UIDATA* pUiData ) 
{
	CDlgEkiProp* pOuter = (CDlgEkiProp*)( (char*)this - offsetof( CDlgEkiProp , m_PropEditUiInternal ) ) ;

	// --------------------------------
	//	DDX��p�����AUiControl�ւ̐ݒ�
	// --------------------------------
	{
		// �w�����`��
		{
			pOuter->m_iRADIO_Jikokukeisiki = pUiData->iEkijikokukeisiki ;
		}
		// �w�K�� 
		{
			pOuter->m_iRADIO_Ekikibo = pUiData->iEkikibo ;
		}
		// --------------------------------
		pOuter->UpdateData( FALSE ) ;
	}
	// --------------------------------
	//	DDX��p���Ȃ��AUiControl�ւ̐ݒ�
	//	�����́ADDX�ɂ��l�ݒ�̌��
	//	�s��Ȃ��Ă͂Ȃ�܂���B
	// --------------------------------
	// �w�� 
	{
		CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ekimei ) ;
		pEdit->SetWindowText( pUiData->strEkimei.c_str() ) ;
		pEdit->SetSel( 0 , -1 ) ;
	}	
	// ���E������ 
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_Kyoukaisen ) ;
		int nCheck = BST_INDETERMINATE ;
		switch( pUiData->iKyoukaisen )
		{
		case 1: // ���E������
			nCheck = BST_CHECKED ;
			break ;
		case 0: //�Ȃ�
			nCheck = BST_UNCHECKED ;
			break ;
		}
		pButton->SetCheck( nCheck ) ;
	}

	//�_�C���O������ԏ��\���i����j
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiKudari ) ;
		pComboBox->SetCurSel( pUiData->iDiagramRessyajouhouHyoujiKudari ) ;
	}
	// �_�C���O������ԏ��\���i���j 
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiNobori ) ;
		pComboBox->SetCurSel( pUiData->iDiagramRessyajouhouHyoujiNobori ) ;
	}

	//[�w�������w�����`���Ő��K��]�̐ݒ�ł��B
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_AdjustByEkijikokukeisiki ) ;
		int nCheck = ( pUiData->bAdjustByEkijikokukeisiki ? BST_CHECKED : BST_UNCHECKED );
		pButton->SetCheck( nCheck ) ;	
	}
}

void CDlgEkiProp::CPropEditUiInternal::UiDataFromUi( UIDATA* pUiData ) 
{
	CDlgEkiProp* pOuter = (CDlgEkiProp*)( (char*)this - offsetof( CDlgEkiProp , m_PropEditUiInternal ) ) ;
	int iRv = 0 ;
	
	// --------------------------------
	//	DDX��p�����AUiControl�ւ̐ݒ�
	// --------------------------------
	if ( !pOuter->UpdateData( TRUE ) )
	{
		iRv = -1 ;	//	UpdateData �ŃG���[���������܂����B
	}

	if ( iRv >= 0 )
	{
		// �w�����`��
		{
			pUiData->iEkijikokukeisiki = pOuter->m_iRADIO_Jikokukeisiki ;
		}
		// �w�K�� 
		{
			pUiData->iEkikibo = pOuter->m_iRADIO_Ekikibo ;
		}
	}
	// --------------------------------
	//	DDX��p���Ȃ��AUiControl�ւ̐ݒ�
	//	�����́ADDX�ɂ��l�ݒ�̌��
	//	�s��Ȃ��Ă͂Ȃ�܂���B
	// --------------------------------
	// �w�� 
	{
		CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ekimei ) ;
		CString aString ;
		pEdit->GetWindowText( aString ) ;
		pUiData->strEkimei = (LPCTSTR)aString ;
	}
	// ���E������ 
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_Kyoukaisen ) ;
		int nCheck = pButton->GetCheck() ;
		switch( nCheck )
		{
		case BST_CHECKED: 
			pUiData->iKyoukaisen = 1 ; 
			break ;
		case BST_UNCHECKED:
			pUiData->iKyoukaisen = 0 ; 
			break ;
		}

		//	�`�F�b�N�{�b�N�X�́A���ԏ�Ԃւ̕ύX��F�߂܂���B
		//	���[�U�[�ɂ���Ē��ԏ�Ԃ֕ύX���ꂽ�ꍇ�́A
		//	�`�F�b�N�Ȃ���ԂɕύX���܂��B
		if ( pUiData->iKyoukaisen != -1 && nCheck == BST_INDETERMINATE )
		{
			pUiData->iKyoukaisen = 0 ;
		}
	}

	//�_�C���O������ԏ��\���i����j
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiKudari ) ;
		int iSel = pComboBox->GetCurSel(  ) ;
		if ( iSel != CB_ERR )
		{
			pUiData->iDiagramRessyajouhouHyoujiKudari = iSel ;
		}
	}
	// �_�C���O������ԏ��\���i���j 
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiNobori ) ;
		int iSel = pComboBox->GetCurSel(  ) ;
		if ( iSel != CB_ERR )
		{
			pUiData->iDiagramRessyajouhouHyoujiNobori = iSel ;
		}
	}

	//[�w�������w�����`���Ő��K��]�̐ݒ�ł��B
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_AdjustByEkijikokukeisiki ) ;
		int nCheck =  pButton->GetCheck() ; 
		switch( nCheck )
		{
		case BST_CHECKED: 
			pUiData->bAdjustByEkijikokukeisiki = true  ; 
			break ;
		case BST_UNCHECKED:
			pUiData->bAdjustByEkijikokukeisiki = false  ; 
			break ;
		}
	}
}

void CDlgEkiProp::CPropEditUiInternal::ShowError( 
			const std::string& strErrorReason ,
			const std::string& strInfo ) 
{
	CDlgEkiProp* pOuter = (CDlgEkiProp*)( (char*)this - offsetof( CDlgEkiProp , m_PropEditUiInternal ) ) ;

	CString strErrorMsg = strErrorReason.c_str() ;

	if ( strErrorReason == ERRMSG_EKIMEI_TOO_LONG )
	{
		pOuter->GetDlgItem( IDC_ERR_EkimeiNo )->GetWindowText( strErrorMsg )  ;
	}
	pOuter->MessageBox( strErrorMsg , NULL , MB_OK | MB_ICONEXCLAMATION ) ;

}

void CDlgEkiProp::CPropEditUiInternal::SetFocus( int iOffsetofUiDataMember ) 
{
	CDlgEkiProp* pOuter = (CDlgEkiProp*)( (char*)this - offsetof( CDlgEkiProp , m_PropEditUiInternal ) ) ;
	CWnd* pControl = NULL ;
	
	// �w�����`��
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iEkijikokukeisiki ) )
		{
			pControl = pOuter->GetDlgItem( IDC_RADIO_Jikokukeisiki ) ;
		}
	}
	// �w�K�� 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iEkikibo ) )
		{
			pControl = pOuter->GetDlgItem( IDC_RADIO_Ekikibo ) ;
		}
	}
	// --------------------------------
	// �w�� 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , strEkimei ) )
		{
			pControl = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ekimei ) ;
		}
	}	
	// ���E������ 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iKyoukaisen ) )
		{
			pControl = (CButton*)pOuter->GetDlgItem( IDC_CHECK_Kyoukaisen ) ;
		}
	}

	//�_�C���O������ԏ��\���i����j
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iDiagramRessyajouhouHyoujiKudari ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiKudari ) ;
		}
	}
	// �_�C���O������ԏ��\���i���j 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iDiagramRessyajouhouHyoujiNobori ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiNobori ) ;
		}
	}

	//[�w�������w�����`���Ő��K��]�̐ݒ�ł��B
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , bAdjustByEkijikokukeisiki ) )
		{
			pControl = (CButton*)pOuter->GetDlgItem( IDC_CHECK_Kyoukaisen ) ;
		}
	}
	// --------------------------------
	if ( pControl != NULL )
	{
		pOuter->GotoDlgCtrl( pControl ) ; 
	}
}	

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CDlgEkiProp::CPropEditUiInternal::CPropEditUiInternal(
	bool bNewItem , 
	Mu<CentDedEki*>* pTarget ,
	bool* pbAdjustBuEkijikokukeisiki )
	: CPropEditUi_Eki( bNewItem , pTarget , pbAdjustBuEkijikokukeisiki ) 
{
}

/////////////////////////////////////////////////////////////////////////////
// CDlgEkiProp �_�C�A���O

	// --------------------------------
	//@name �����֐�
	// --------------------------------

	// ********************************
	//@name ����
	// ********************************
// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
CDlgEkiProp::CDlgEkiProp(
		Mu<CentDedEki*>* pTarget ,
		bool* pbAdjustBuEkijikokukeisiki , 
		int iFocusItem ,
		CKeyinputSenderToModalDlg*	pCKeyinputSenderToModalDlg ,
		CWnd* pParent )
	: CDialog(CDlgEkiProp::IDD, pParent)
	, m_PropEditUiInternal( false , pTarget , pbAdjustBuEkijikokukeisiki ) 
	, m_iFocusItem( iFocusItem ) 
	, m_pCKeyinputSenderToModalDlg(	pCKeyinputSenderToModalDlg ) 
{
	//{{AFX_DATA_INIT(CDlgEkiProp)
	m_iRADIO_Jikokukeisiki = -1;
	m_iRADIO_Ekikibo = -1;
	//}}AFX_DATA_INIT
}


void CDlgEkiProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEkiProp)
	DDX_Radio(pDX, IDC_RADIO_Jikokukeisiki, m_iRADIO_Jikokukeisiki);
	DDX_Radio(pDX, IDC_RADIO_Ekikibo, m_iRADIO_Ekikibo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEkiProp, CDialog)
	//{{AFX_MSG_MAP(CDlgEkiProp)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
	ON_EN_KILLFOCUS(IDC_EDIT_Ekimei, &CDlgEkiProp::OnEnKillfocusEditEkimei)
	ON_BN_CLICKED(IDC_CHECK_Kyoukaisen, &CDlgEkiProp::OnBnClickedCheckKyoukaisen)
	ON_BN_CLICKED(IDC_RADIO_Jikokukeisiki, &CDlgEkiProp::OnBnClickedRadioJikokukeisiki)
	ON_BN_CLICKED(IDC_RADIO_Jikokukeisiki2, &CDlgEkiProp::OnBnClickedRadioJikokukeisiki2)
	ON_BN_CLICKED(IDC_RADIO_Jikokukeisiki3, &CDlgEkiProp::OnBnClickedRadioJikokukeisiki3)
	ON_BN_CLICKED(IDC_RADIO_Jikokukeisiki4, &CDlgEkiProp::OnBnClickedRadioJikokukeisiki4)
	ON_BN_CLICKED(IDC_RADIO_Ekikibo, &CDlgEkiProp::OnBnClickedRadioEkikibo)
	ON_BN_CLICKED(IDC_RADIO_Ekikibo2, &CDlgEkiProp::OnBnClickedRadioEkikibo2)
	ON_CBN_SELCHANGE(IDC_COMBO_DiagramRessyajouhouHyoujiKudari, &CDlgEkiProp::OnCbnSelchangeComboDiagramressyajouhouhyoujikudari)
	ON_CBN_SELCHANGE(IDC_COMBO_DiagramRessyajouhouHyoujiNobori, &CDlgEkiProp::OnCbnSelchangeComboDiagramressyajouhouhyoujinobori)
	ON_BN_CLICKED(IDC_CHECK_AdjustByEkijikokukeisiki, &CDlgEkiProp::OnBnClickedCheckAdjustbyekijikokukeisiki)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEkiProp ���b�Z�[�W �n���h��

BOOL CDlgEkiProp::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//	�ҏW���J�n
	m_PropEditUiInternal.StartEdit() ;
	
	// --------------------------------
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgEkiProp::OnOK() 
{
	int iResult = m_PropEditUiInternal.EndEdit() ;
	if ( iResult >= 0 )
	{
		CDialog::OnOK();
	}

}

void CDlgEkiProp::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	
	
	if ( bShow )
	{
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		//�w��
		if ( m_iFocusItem == 0 ){
			CEdit*	pControl = (CEdit*)GetDlgItem( IDC_EDIT_Ekimei );
			GotoDlgCtrl( pControl ) ;
			if ( m_pCKeyinputSenderToModalDlg != NULL ){
				m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
			}
		}
		//�w�����`��
		if ( m_iFocusItem == 1 ){
			CWnd*	pControl = GetDlgItem( IDC_RADIO_Jikokukeisiki );
			GotoDlgCtrl( pControl ) ;
			if ( m_pCKeyinputSenderToModalDlg != NULL ){
				m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
			}
		}
		//�w�K��
		if ( m_iFocusItem == 2 ){
			CWnd*	pControl = GetDlgItem( IDC_RADIO_Ekikibo );
			GotoDlgCtrl( pControl ) ;
			if ( m_pCKeyinputSenderToModalDlg != NULL ){
				m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
			}
		}
		
		m_iFocusItem = -1 ;
	}	
	
}

void CDlgEkiProp::OnEnKillfocusEditEkimei()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedCheckKyoukaisen()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioJikokukeisiki()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioJikokukeisiki2()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioJikokukeisiki3()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioJikokukeisiki4()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioEkikibo()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioEkikibo2()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnCbnSelchangeComboDiagramressyajouhouhyoujikudari()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnCbnSelchangeComboDiagramressyajouhouhyoujinobori()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedCheckAdjustbyekijikokukeisiki()
{
	m_PropEditUiInternal.OnUiChanged();
}

} //namespace ViewEki
