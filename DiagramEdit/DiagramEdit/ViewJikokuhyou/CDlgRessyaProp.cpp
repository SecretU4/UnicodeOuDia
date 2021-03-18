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
// CDlgRessyaProp.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"

#include "str\strtoint.h"

#include "..\DiagramEdit.h"
#include "CDlgRessyaProp.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

using namespace std ;


// ================================================================
//	CDlgRessyaProp::CPropEditUiInternal
// ================================================================

		// ================================
		//@name UI�Ƃ̃C���^�[�t�F�[�X
		// ================================
void CDlgRessyaProp::CPropEditUiInternal::UiDataToUi( const UIDATA* pUiData ) 
{
	CDlgRessyaProp* pOuter = (CDlgRessyaProp*)( (BYTE*)this - offsetof( CDlgRessyaProp , m_PropEditUiInternal ) ) ;
	CWnd* pFocus = CWnd::GetFocus() ;

	// --------------------------------
	//	DDX��p�����AUiControl�ւ̐ݒ�
	// --------------------------------
	{
		// --------------------------------
		pOuter->UpdateData( FALSE ) ;
	}
	// --------------------------------
	//	DDX��p���Ȃ��AUiControl�ւ̐ݒ�
	//	�����́ADDX�ɂ��l�ݒ�̌��
	//	�s��Ȃ��Ă͂Ȃ�܂���B
	// --------------------------------
	//iIsNull
	{
		CButton* pControl = (CButton*)( pOuter->GetDlgItem( IDC_CHECK_IsNull ) ) ;
		int nCheck = BST_UNCHECKED ;
		switch( pUiData->iIsNull )
		{
		case 1:
			nCheck = BST_CHECKED ;
			break ;
		case -1:
			nCheck = BST_INDETERMINATE ;
			break ;
		}
		pControl->SetCheck( nCheck ) ;
	}
	//strRessyabangou,bRessyabangouIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Ressyabangou ) ) ;
		pControl->SetWindowText( pUiData->strRessyabangou.c_str() ) ;
		pControl->EnableWindow( pUiData->bRessyabangouIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
	//iRessyasyubetsuIndex,bRessyasyubetsuIndexIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ) ;
		pControl->SetCurSel( pUiData->iRessyasyubetsuIndex ) ;
		pControl->EnableWindow( pUiData->bRessyasyubetsuIndexIsEnable ) ;
	}
	//strRessyamei,bRessyameiIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Ressyamei ) ) ;
		pControl->SetWindowText( pUiData->strRessyamei.c_str() ) ;
		pControl->EnableWindow( pUiData->bRessyameiIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
	//strGousuu,bGousuuIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Gousuu ) ) ;
		pControl->SetWindowText( pUiData->strGousuu.c_str() ) ;
		pControl->EnableWindow( pUiData->bGousuuIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
	//strBikou,bBikouIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Bikou ) ) ;
		pControl->SetWindowText( pUiData->strBikou.c_str() ) ;
		pControl->EnableWindow( pUiData->bBikouIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
}



void CDlgRessyaProp::CPropEditUiInternal::UiDataFromUi( UIDATA* pUiData )  
{
	int iRv = 0 ; 

	CDlgRessyaProp* pOuter = (CDlgRessyaProp*)( (BYTE*)this - offsetof( CDlgRessyaProp , m_PropEditUiInternal ) ) ;

	//iIsNull
	{
		CButton* pControl = (CButton*)( pOuter->GetDlgItem( IDC_CHECK_IsNull ) ) ;
		int nCheck = pControl->GetCheck() ;
		pUiData->iIsNull = 0 ; 
		switch( nCheck )
		{
		case BST_CHECKED:
			pUiData->iIsNull = 1 ;
			break ;
		case BST_UNCHECKED:
			pUiData->iIsNull = 0 ;
			break ;
		}
		//	�`�F�b�N�{�b�N�X�́A���ԏ�Ԃւ̕ύX��F�߂܂���B
		//	���[�U�[�ɂ���Ē��ԏ�Ԃ֕ύX���ꂽ�ꍇ�́A
		//	�`�F�b�N�Ȃ���ԂɕύX���܂��B
		if ( pUiData->iIsNull == -1 && nCheck == BST_INDETERMINATE )
		{
			pUiData->iIsNull = 0 ;
		}
	}
	//strRessyabangou,bRessyabangouIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Ressyabangou ) ) ;
		CString strText ;
		pControl->GetWindowText( strText ) ;
		pUiData->strRessyabangou = strText ;
	}
	//iRessyasyubetsuIndex,bRessyasyubetsuIndexIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ) ;
		int iIndex = pControl->GetCurSel() ;
		if ( iIndex == CB_ERR )
		{
			iIndex = -1 ;
		}
		pUiData->iRessyasyubetsuIndex = iIndex ;
	}
	//strRessyamei,bRessyameiIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_EDIT_Ressyamei ) ) ;
		CString strText ;
		pControl->GetWindowText( strText ) ;
		pUiData->strRessyamei = strText ;
	}
	//strGousuu,bGousuuIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_EDIT_Gousuu ) ) ;
		CString strText ;
		pControl->GetWindowText( strText ) ;
		pUiData->strGousuu = strText ;
	}
	//strBikou,bBikouIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_EDIT_Bikou ) ) ;
		CString strText ;
		pControl->GetWindowText( strText ) ;
		pUiData->strBikou = strText ;
	}
}
		
void CDlgRessyaProp::CPropEditUiInternal::ShowError( 
			const std::string& strErrorReason ,
			const std::string& strInfo )  
{
	CDlgRessyaProp* pOuter = (CDlgRessyaProp*)( (BYTE*)this - offsetof( CDlgRessyaProp , m_PropEditUiInternal ) ) ;
	CString strErrorMsg = strErrorReason.c_str() ;

	pOuter->MessageBox( strErrorMsg , NULL , MB_OK | MB_ICONEXCLAMATION ) ;
}


void CDlgRessyaProp::CPropEditUiInternal::SetFocus( int iOffsetofUiDataMember )  
{
	int iResult = 0 ; 

	//	NULL��Ԃ̏ꍇ�́A�t�H�[�J�X�ʒu�́w��s�x�Ɉړ����܂�
	if ( GetUiData()->iIsNull == 1 )	//	ON
	{
		iOffsetofUiDataMember = offsetof(UIDATA , iIsNull ) ;
	}
	// --------------------------------



	CDlgRessyaProp* pOuter = (CDlgRessyaProp*)( (BYTE*)this - offsetof( CDlgRessyaProp , m_PropEditUiInternal ) ) ;
	CWnd* pWnd = NULL ;
	//iIsNull
	if ( iOffsetofUiDataMember == offsetof(UIDATA , iIsNull ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_CHECK_IsNull ) ) ;
	}
	//strRessyabangou,bRessyabangouIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , strRessyabangou ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_EDIT_Ressyabangou ) ) ;
	}
	//iRessyasyubetsuIndex,bRessyasyubetsuIndexIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , iRessyasyubetsuIndex ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ) ;
	}
	//strRessyamei,bRessyameiIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , strRessyamei ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_EDIT_Ressyamei ) ) ;
	}
	//strGousuu,bGousuuIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , strGousuu ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_EDIT_Gousuu ) ) ;
	}
	//strBikou,bBikouIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , strBikou ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_EDIT_Bikou ) ) ;
	}

	if ( pWnd != NULL )
	{
		pOuter->GotoDlgCtrl( pWnd ) ;
	}
}
		// ********************************
		//	�R���X�g���N�^
		// ********************************
CDlgRessyaProp::CPropEditUiInternal::CPropEditUiInternal(
	bool bNewItem , 
	Mu<CentDedRessya*>* pTarget , 
	int iRessyasyubetsu ) 
	: CPropEditUi_Ressya( bNewItem , pTarget , iRessyasyubetsu ) 		
{
}
		


/////////////////////////////////////////////////////////////////////////////
// CDlgRessyaProp �_�C�A���O
// --------------------------------
//@name �����֐�
// --------------------------------
int CDlgRessyaProp::FirstFocusItemArgConvert( int iFocusItem ) 
{
	int iFirstFocusItemOffset = -1 ;

	switch( iFocusItem )
	{
	case 0:	//	��s
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , iIsNull ) ;
		break ;
	case 1:	//	��Ԕԍ�
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , strRessyabangou ) ;
		break ;
	case 2:	//	��Ԏ��
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , iRessyasyubetsuIndex ) ;
		break ;
	case 3:	//	��Ԗ�
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , strRessyamei ) ;
		break ;
	case 4:	//	����
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , strGousuu ) ;
		break ;
	case 5:	//	���l
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , strBikou ) ;
		break ;
	}
	return iFirstFocusItemOffset ;

}

// ********************************
//	CDlgRessyaProp
// ********************************
	// ********************************
	//@name ����
	// ********************************

// ----------------------------------------------------------------



CDlgRessyaProp::CDlgRessyaProp(
	   bool bNewEdit ,
		Mu<CentDedRessya*>* pTarget ,
		int iFocusItem ,
		CKeyinputSenderToModalDlg*	pCKeyinputSenderToModalDlg ,
		CWnd* pParent )
	: CDialog(CDlgRessyaProp::IDD, pParent)
	, m_iFocusItem( iFocusItem ) 
	, m_PropEditUiInternal( bNewEdit ,  pTarget , getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont()->size() ) 
	, m_pCKeyinputSenderToModalDlg(	pCKeyinputSenderToModalDlg ) 
{
	//{{AFX_DATA_INIT(CDlgRessyaProp)
	//}}AFX_DATA_INIT
}


void CDlgRessyaProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRessyaProp)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRessyaProp, CDialog)
	//{{AFX_MSG_MAP(CDlgRessyaProp)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_CHECK_IsNull, OnCHECKIsNull)
	//}}AFX_MSG_MAP
	ON_EN_KILLFOCUS(IDC_EDIT_Ressyabangou, &CDlgRessyaProp::OnEnKillfocusEditRessyabangou)
	ON_CBN_SELCHANGE(IDC_COMBO_Ressyasyubetsu, &CDlgRessyaProp::OnCbnSelchangeComboRessyasyubetsu)
	ON_EN_KILLFOCUS(IDC_EDIT_Ressyamei, &CDlgRessyaProp::OnEnKillfocusEditRessyamei)
	ON_EN_KILLFOCUS(IDC_EDIT_Gousuu, &CDlgRessyaProp::OnEnKillfocusEditGousuu)
	ON_EN_KILLFOCUS(IDC_EDIT_Bikou, &CDlgRessyaProp::OnEnKillfocusEditBikou)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRessyaProp ���b�Z�[�W �n���h��

BOOL CDlgRessyaProp::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//IDC_COMBO_Ressyasyubetsu
	{
		const CentDedRosen* pCentDedRosen = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu = 
			pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;
		
		CComboBox*	pCComboBox = (CComboBox*)GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ;
		for ( int idxRessyasyubetsu = 0 ; 
			idxRessyasyubetsu < pMuCentDedRessyasyubetsu->size() ; 
			idxRessyasyubetsu ++ )
		{
			const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = 
				pMuCentDedRessyasyubetsu->get( idxRessyasyubetsu ) ;

			string	strSyubetsumei = pCentDedRessyasyubetsu->getSyubetsumei() ;
			
			// �w��Ԃ̃v���p�e�B�x�_�C�A���O�́w��Ԏ�ʁx��
			//	�h���b�v�_�E�����X�g�̍��ڂ̐擪10�ɁA
			//	"0. " �` "9. " �܂ł̐�����ǉ�
			//	(��:�@"����"��"0. ����" ) 
			if ( idxRessyasyubetsu < 10 )
			{
				strSyubetsumei = stringOf( idxRessyasyubetsu ) 
					+ ". " 
					+ strSyubetsumei ;
			}

			pCComboBox->AddString( strSyubetsumei.c_str() ) ;
		}
	}

	m_PropEditUiInternal.StartEdit() ;

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgRessyaProp::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	if ( bShow )
	{
		//	�ҏW�J�n���̃t�H�[�J�X�ʒu��ݒ肵�܂��B
		//	���̏����́A OnInitDialog() �ł͂ł��܂���B
		//	OnShowWindow() �ŁA�_�C�A���O�{�b�N�X���\�����ꂽ�Ƃ���
		//	�s���K�v������܂��B

		CWnd*	pControl = NULL ;

		//	��Ԃ���s�ȊO
		if ( m_PropEditUiInternal.GetUiData()->iIsNull != 1 ) 
		{
			switch( m_iFocusItem ){
			 case 0	:	//	��s
				pControl = GetDlgItem( IDC_CHECK_IsNull ) ;
				break ;
			 case 1	:	//	��Ԕԍ�
				pControl = GetDlgItem( IDC_EDIT_Ressyabangou ) ;
				break ;
			 case 2	:	//	��Ԏ��
				pControl = GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ;
				break ;
			 case 3	:	//	��Ԗ�
				pControl = GetDlgItem( IDC_EDIT_Ressyamei ) ;
				break ;
			 case 4	:	//	����
				pControl = GetDlgItem( IDC_EDIT_Gousuu ) ;
				break ;
			 case 5	:	//	���l
				pControl = GetDlgItem( IDC_EDIT_Bikou ) ;
				break ;
			}
		}
		else
		{
				//	��Ԃ�Null��Ԃ̏ꍇ�́A
				//	�w��s�x�ȊO�̃R���g���[���͂��ׂ�
				//	�����ɂȂ邽�߁A
				//	�w��s�x�R���g���[���Ƀt�H�[�J�X�������܂��B
				pControl = GetDlgItem( IDC_CHECK_IsNull ) ;
		}
		if ( pControl != NULL )
		{
			GotoDlgCtrl( pControl ) ;
			if ( m_pCKeyinputSenderToModalDlg != NULL ){
				m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
			}
		}
		
	}
}

void CDlgRessyaProp::OnOK() 
{
	int iResult = m_PropEditUiInternal.EndEdit() ;
	if ( iResult >= 0 )
	{
		CDialog::OnOK();
	}
}

void CDlgRessyaProp::OnCHECKIsNull() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}


void CDlgRessyaProp::OnEnKillfocusEditRessyabangou()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyaProp::OnCbnSelchangeComboRessyasyubetsu()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyaProp::OnEnKillfocusEditRessyamei()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyaProp::OnEnKillfocusEditGousuu()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyaProp::OnEnKillfocusEditBikou()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

} //namespace ViewJikokuhyou
