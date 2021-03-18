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
// CDlgRessyasyubetsuProp.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"

#include "MfcUtil\MfcUtil.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CDcdTargetOnPaint.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "LogMsg\LogMsg.h"

#include "..\DiagramEdit.h"
#include "..\entDed\CconvCentDed.h"
#include "CDlgRessyasyubetsuProp.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRessyasyubetsu{ 
using namespace std ;
using namespace OuMfc;


// ================================================================
//	CDlgRessyasyubetsuProp::CPropEditUiInternal
// ================================================================
		// ================================
		// �I�[�o�[���C�g�̕K�v�ȃ��\�b�h2-UI�Ɉˑ����鏈��
		// ================================
void CDlgRessyasyubetsuProp::CPropEditUiInternal::
UiDataToUi( const UIDATA* pUiData ) 
{
	CDlgRessyasyubetsuProp* pOuter = (CDlgRessyasyubetsuProp*)( (char*)this - offsetof( CDlgRessyasyubetsuProp , m_PropEditUiInternal ) ) ;

	// --------------------------------
	//	DDX��p�����AUiControl�ւ̐ݒ�
	// --------------------------------
	{
		//	�����ŁADDX�ϐ��ɐݒ�

		pOuter->UpdateData( FALSE ) ;
	}
	// --------------------------------
	//	DDX��p���Ȃ��AUiControl�ւ̐ݒ�
	//	�����́ADDX�ɂ��l�ݒ�̌��
	//	�s��Ȃ��Ă͂Ȃ�܂���B
	// --------------------------------

	// ��Ԏ�ʖ� 
	{
		CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Syubetsumei ) ;
		pEdit->EnableWindow(  pUiData->bSyubetsumeiIsEnable ? TRUE : FALSE ) ;
		pEdit->SetWindowText( pUiData->strSyubetsumei.c_str() ) ;
		pEdit->SetSel( 0 , -1 ) ;
	}
	// ���́i��ʖ��̗��́j
	{
		CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ryakusyou ) ;
		pEdit->SetWindowText( pUiData->strRyakusyou.c_str() ) ;
		pEdit->SetSel( 0 , -1 ) ;
	}
	
	//	�����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)
	{
		//	���̍��ڂ́A�R���g���[���ɂ͋L������܂���B
	}
	//�����\�r���[�ŁA���̗�Ԏ�ʂ̎�����\�����邽�߂̎����\�t�H���g
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_JikokuhyouFontIndex ) ;
		pComboBox->SetCurSel( pUiData->iJikokuhyouFontIndex ) ;
	}

	// �_�C���O�������̐F
	{
		//	���̍��ڂ́A�R���g���[���ɂ͋L������܂���B
	}

	// �_�C���O�������̐��X�^�C��	
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramSenStyle ) ;
		pComboBox->SetCurSel( pUiData->iDiagramSenStyle ) ;
	}

	// �_�C���O�������̐��X�^�C�����������ۂ����w�肵�܂��B
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_DiagramSenStyleIsBold ) ;
		int nCheck = BST_INDETERMINATE ;
		switch( pUiData->iDiagramSenIsBold )
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
	
	// ��ԉw�����̕��@
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_StopMarkDrawType ) ;
		pComboBox->SetCurSel( pUiData->iStopMarkDrawType ) ;
	}


	// --------------------------------	
	//	DcDraw �ւ̐ݒ�
	// --------------------------------	
	//	�����F�̐ݒ�
	{
		pOuter->m_pdcdJikokuhyouMojiColor->setCdBrushProp( 
			pUiData->colorJikokuhyouMojiColor ) ;
		CRect	aRect = MfcUtil::GetDlgControlRect( pOuter , IDC_STATIC_JikokuhyouMojiColor ) ;
		pOuter->InvalidateRect( &aRect ) ;
	}
	//	�����\�t�H���g(�����F�Ǝ����\�t�H���g)
	{
		CdDrawTextProp	aCdDrawTextProp = pOuter->m_pdcdJikokuhyouFont->getCdDrawTextProp() ;
		aCdDrawTextProp.setTextColor( pUiData->colorJikokuhyouMojiColor ) ;
		
		// --------------------------------
		//	�����\�t�H���g���ݒ肳��Ă���ꍇ�́A
		//	�������T���v�����\���ł��܂��B
		if ( pUiData->iJikokuhyouFontIndex >= 0 )
		{
			aCdDrawTextProp.setCdFontProp( pOuter->m_fontpropJikokuhyouFont[pUiData->iJikokuhyouFontIndex] );
		}
		//	�����\�t�H���g���ݒ肳��Ă��Ȃ��ꍇ�́A
		//	�������T���v�����\���ł��܂���B
		else
		{
			//	�����\�t�H���g�̃T���v�����\���ł��܂���B
			//	���̂Ƃ��́A�f�t�H���g�t�H���g�ŕ\�����܂��B
			CConverter_WinGdi	aConv ;
			aCdDrawTextProp.setCdFontProp( aConv.CdFontPropOf( DEFAULT_GUI_FONT ) );
		}
		// --------------------------------
		pOuter->m_pdcdJikokuhyouFont->setCdDrawTextProp( aCdDrawTextProp ) ;
		
			
		CRect	aRect = MfcUtil::GetDlgControlRect( pOuter , IDC_STATIC_JikokuhyouFont ) ;
		pOuter->InvalidateRect( &aRect ) ;
	}
	//	�_�C���O������
	// (�_�C���O�������̐F�E���X�^�C���E����)
	{
		CdDcdFreeLineProp	aCdLineProp ;
		//	���X�^�C���E�������ǂ�����ݒ肳��Ă���ꍇ�́A
		//	�������T���v�����\���ł��܂��B
		if ( pUiData->iDiagramSenStyle >= 0 && pUiData->iDiagramSenIsBold  >= 0 )
		{
			CconvCentDed aCconvCentDed ;
			aCconvCentDed.CentDedRessyasyubetsu_to_CDcdFreeLineProp( 
				CentDedRessyasyubetsu::CdDiagramLineStyle( 
					pUiData->colorDiagramSenColor ,
					(CentDedRessyasyubetsu::ESenStyle)pUiData->iDiagramSenStyle , 
					pUiData->iDiagramSenIsBold == 1 ) ,
				&aCdLineProp ) ;
		}
		//	���X�^�C���E�����̂����ꂩ���s��̏ꍇ�́A
		//	�T���v�����\���ł��܂���
		else
		{
			//	�T���v�����\���ł��܂���B
			//	���̏ꍇ�́A����\�����܂���(�����Ȃ̂ŁA�����܂���)
			aCdLineProp = CdDcdFreeLineProp().setColor( CdColorProp( 255 , 255 , 255 ) ) ;
			
		}
		pOuter->m_pdcdDiagramSen->setCdLineProp( aCdLineProp ) ;
		CRect	aRect = MfcUtil::GetDlgControlRect( pOuter , IDC_STATIC_DiagramSen ) ;
		pOuter->InvalidateRect( &aRect ) ;
	}
}


void CDlgRessyasyubetsuProp::CPropEditUiInternal::UiDataFromUi( UIDATA* pUiData ) 
{
	CDlgRessyasyubetsuProp* pOuter = (CDlgRessyasyubetsuProp*)( (char*)this - offsetof( CDlgRessyasyubetsuProp , m_PropEditUiInternal ) ) ;
	int iRv = 0 ;
	// --------------------------------
	//	DDX��p�����AUiControl�ւ̐ݒ�
	// --------------------------------
	if ( !pOuter->UpdateData( TRUE ) )
	{
		iRv = -1 ;	//	UpdateData �ŃG���[���������܂����B
	}
	// --------------------------------
	//	DDX��p���Ȃ��AUiControl�ւ̐ݒ�
	//	�����́ADDX�ɂ��l�ݒ�̌��
	//	�s��Ȃ��Ă͂Ȃ�܂���B
	// --------------------------------

	// ��Ԏ�ʖ� 
	if ( iRv >= 0 )
	{
		{
			CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Syubetsumei ) ;
			CString aString ;
			pEdit->GetWindowText( aString ) ;
			pUiData->strSyubetsumei = (LPCTSTR)aString ;
		}
	}
	// ���́i��ʖ��̗��́j
	if ( iRv >= 0 )
	{
		{
			CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ryakusyou ) ;
			CString aString ;
			pEdit->GetWindowText( aString ) ;
			pUiData->strRyakusyou = (LPCTSTR)aString ;
		}
	}
	
	//	�����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)
	if ( iRv >= 0 )
	{
		//	���̍��ڂ́A�R���g���[���ɂ͋L������܂���B
	}
	//�����\�r���[�ŁA���̗�Ԏ�ʂ̎�����\�����邽�߂̎����\�t�H���g
	if ( iRv >= 0 )
	{
		{
			CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_JikokuhyouFontIndex ) ;
			int iSel = pComboBox->GetCurSel(  ) ;
			if ( iSel != CB_ERR )
			{
				pUiData->iJikokuhyouFontIndex = iSel ;
			}
		}
	}

	// �_�C���O�������̐F
	if ( iRv >= 0 )
	{
		//	���̍��ڂ́A�R���g���[���ɂ͋L������܂���B
	}

	// �_�C���O�������̐��X�^�C��	
	if ( iRv >= 0 )
	{
		{
			CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramSenStyle ) ;
			int iSel = pComboBox->GetCurSel(  ) ;
			if ( iSel != CB_ERR )
			{
				pUiData->iDiagramSenStyle = iSel ;
			}
		}
	}

	// �_�C���O�������̐��X�^�C�����������ۂ����w�肵�܂��B
	if ( iRv >= 0 )
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_DiagramSenStyleIsBold ) ;
		int nCheck =  pButton->GetCheck() ; 
		switch( nCheck )
		{
		case BST_CHECKED: // ���E������
			pUiData->iDiagramSenIsBold = 1 ;
			break ;
		case BST_UNCHECKED: //�Ȃ�
			pUiData->iDiagramSenIsBold = 0 ;
			break ;
		}

		//	�`�F�b�N�{�b�N�X�́A���ԏ�Ԃւ̕ύX��F�߂܂���B
		//	���[�U�[�ɂ���Ē��ԏ�ԈȊO�����ԏ�Ԃ֕ύX���ꂽ�ꍇ�́A
		//	�`�F�b�N�Ȃ���ԂɕύX���܂��B
		if ( pUiData->iDiagramSenIsBold != -1 && nCheck == BST_INDETERMINATE )
		{
			pUiData->iDiagramSenIsBold = 0 ;
		}
	}
	
	// ��ԉw�����̕��@
	if ( iRv >= 0 )
	{
		{
			CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_StopMarkDrawType ) ;
			int iSel = pComboBox->GetCurSel(  ) ;
			if ( iSel != CB_ERR )
			{
				pUiData->iStopMarkDrawType = iSel ;
			}
		}
	}
}		
void CDlgRessyasyubetsuProp::CPropEditUiInternal::ShowError( 
			const std::string& strErrorReason ,
			const std::string& strInfo )  

{
	CDlgRessyasyubetsuProp* pOuter = (CDlgRessyasyubetsuProp*)( (char*)this - offsetof( CDlgRessyasyubetsuProp , m_PropEditUiInternal ) ) ;
	CString strErrorMsg = strErrorReason.c_str() ;
	if ( strErrorReason == ERRMSG_SYUBETUSMEI_EMPTY )
	{
		pOuter->GetDlgItem( IDC_ERROR_SyubetsumeiEmpty )->GetWindowText( strErrorMsg )  ;
	}
	else if ( strErrorReason == ERRMSG_RYAKUSYOULENGTH )
	{
		pOuter->GetDlgItem( IDC_ERROR_RyakusyouLength )->GetWindowText( strErrorMsg )  ;
	}
	pOuter->MessageBox( strErrorMsg , NULL , MB_OK | MB_ICONEXCLAMATION ) ;

}


void CDlgRessyasyubetsuProp::CPropEditUiInternal::
	SetFocus( int iOffsetofUiDataMember )
{
	CDlgRessyasyubetsuProp* pOuter = (CDlgRessyasyubetsuProp*)( (char*)this - offsetof( CDlgRessyasyubetsuProp , m_PropEditUiInternal ) ) ;
	CWnd* pControl = NULL ;

	// ��Ԏ�ʖ� 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , strSyubetsumei ) )
		{
			pControl = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Syubetsumei ) ;
		}
	}
	// ���́i��ʖ��̗��́j
	{
		if (iOffsetofUiDataMember == offsetof( UIDATA , strRyakusyou ) )
		{
			pControl = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ryakusyou ) ;
		}
	}
	
	//	�����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)
	{
		//	���̍��ڂ́A�R���g���[���ɂ͋L������܂���B
	}
	//�����\�r���[�ŁA���̗�Ԏ�ʂ̎�����\�����邽�߂̎����\�t�H���g
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iJikokuhyouFontIndex ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_JikokuhyouFontIndex ) ;
		}
	}

	// �_�C���O�������̐F
	{
		//	���̍��ڂ́A�R���g���[���ɂ͋L������܂���B
	}

	// �_�C���O�������̐��X�^�C��	
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iDiagramSenStyle ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramSenStyle ) ;
		}
	}

	// �_�C���O�������̐��X�^�C�����������ۂ����w�肵�܂��B
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iDiagramSenIsBold ) )
		{
			pControl = (CButton*)pOuter->GetDlgItem( IDC_CHECK_DiagramSenStyleIsBold ) ;
		}
	}
	
	// ��ԉw�����̕��@
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iStopMarkDrawType ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_StopMarkDrawType ) ;
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
CDlgRessyasyubetsuProp::CPropEditUiInternal::
CPropEditUiInternal( bool bNewItem , Mu<CentDedRessyasyubetsu*>* pTarget )
	: CPropEditUi_Ressyasyubetsu( bNewItem ,pTarget  ) 
{
}



/////////////////////////////////////////////////////////////////////////////
// CDlgRessyasyubetsuProp �_�C�A���O


// ----------------------------------------------------------------

CDlgRessyasyubetsuProp::CDlgRessyasyubetsuProp(
		bool bNewItem , 
		Mu<CentDedRessyasyubetsu*>* pTarget,
		const CdDedDispProp&	aCdDedDispProp ,
		int iFocusItem , 
		CKeyinputSenderToModalDlg* pCKeyinputSenderToModalDlg , 
		CWnd* pParent )
	: CDialog(CDlgRessyasyubetsuProp::IDD, pParent)
	, m_PropEditUiInternal( bNewItem , pTarget ) 
	, m_iFocusItem( iFocusItem ) 
	, m_pCKeyinputSenderToModalDlg( pCKeyinputSenderToModalDlg )
	, m_pdcdJikokuhyouMojiColor( NULL ) 
	, m_pdcdJikokuhyouFont( NULL )
	, m_pdcdDiagramSen( NULL ) 
{
	for ( int idx = 0 ; idx < CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT ; idx ++ )
	{
		m_fontpropJikokuhyouFont[idx] = aCdDedDispProp.getJikokuhyouFont(idx) ;
	}


	//{{AFX_DATA_INIT(CDlgRessyasyubetsuProp)
	//}}AFX_DATA_INIT

	// --------------------------------
	//	DcDraw(�_�C�A���O��ɕ`����s���I�u�W�F�N�g)�̐���
	// --------------------------------
	CConverter_WinGdi aCConverter_WinGdi ;
	m_pdcdJikokuhyouMojiColor = new CDcdRectangle( 
		CdPenProp( 1 ) ) ;
	m_pdcdJikokuhyouFont = new CDcdTextbox( 
		CdPenProp( 1 ) , 2 , 2 , 
		TEXT( "1000" ) , 
		CdDrawTextProp( 
			aCConverter_WinGdi.CdFontPropOf( DEFAULT_GUI_FONT ) , 
			CdColorProp( 0 , 0 , 0 ) , 
			CdDrawTextFormat (
				CdDrawTextFormat::H_CENTER, 
				CdDrawTextFormat::V_SINGLELINT_CENTER 
			) 
		) ,
		TEXT( "" ) , 
		1 , 
		CdColorProp( 255 , 255 , 255 ) 
	) ;
	m_pdcdDiagramSen = new CDcdFreeLine_StyleSample() ;

}

CDlgRessyasyubetsuProp::~CDlgRessyasyubetsuProp()
{
	delete m_pdcdDiagramSen ;
	delete m_pdcdJikokuhyouFont ;
	delete m_pdcdJikokuhyouMojiColor ; 

}

void CDlgRessyasyubetsuProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRessyasyubetsuProp)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRessyasyubetsuProp, CDialog)
	//{{AFX_MSG_MAP(CDlgRessyasyubetsuProp)
	ON_WM_SHOWWINDOW()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHECK_DiagramSenStyleIsBold, OnCHECKDiagramSenStyleIsBold)
	ON_BN_CLICKED(IDC_BUTTON_JikokuhyouMojiColor, OnBUTTONJikokuhyouMojiColor)
	ON_BN_CLICKED(IDC_BUTTON_DiagramSeniColor, OnBUTTONDiagramSeniColor)
	ON_CBN_SELCHANGE(IDC_COMBO_DiagramSenStyle, OnSelchangeCOMBODiagramSenStyle)
	ON_CBN_SELCHANGE(IDC_COMBO_JikokuhyouFontIndex, &CDlgRessyasyubetsuProp::OnCbnSelchangeComboJikokuhyoufontindex)
	//}}AFX_MSG_MAP
	ON_EN_KILLFOCUS(IDC_EDIT_Syubetsumei, &CDlgRessyasyubetsuProp::OnEnKillfocusEditSyubetsumei)
	ON_EN_KILLFOCUS(IDC_EDIT_Ryakusyou, &CDlgRessyasyubetsuProp::OnEnKillfocusEditRyakusyou)
	ON_CBN_SELCHANGE(IDC_COMBO_StopMarkDrawType, &CDlgRessyasyubetsuProp::OnCbnSelchangeComboStopmarkdrawtype)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRessyasyubetsuProp ���b�Z�[�W �n���h��

BOOL CDlgRessyasyubetsuProp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//	�ҏW���J�n
	m_PropEditUiInternal.StartEdit() ;

	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgRessyasyubetsuProp::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	if ( bShow )
	{
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		switch( m_iFocusItem )
		{
		 //��Ԏ�ʖ�
		 case 0 :
			{
				CWnd*	pControl = GetDlgItem( IDC_EDIT_Syubetsumei );
				GotoDlgCtrl( pControl ) ;
				if ( m_pCKeyinputSenderToModalDlg != NULL )
				{
					m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
				}
			}
			break ;
		 //����
		 case 1 :
			{
				CWnd*	pControl = GetDlgItem( IDC_EDIT_Ryakusyou );
				GotoDlgCtrl( pControl ) ;
				if ( m_pCKeyinputSenderToModalDlg != NULL )
				{
					m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
				}
			}
			break ;
	
		 //���X�^�C��
		 case 2 :
			{
				CWnd*	pControl = GetDlgItem( IDC_BUTTON_DiagramSeniColor );
				GotoDlgCtrl( pControl ) ;
				if ( m_pCKeyinputSenderToModalDlg != NULL )
				{
					m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
				}
			}
			break ;
		}		
	}
	
}

void CDlgRessyasyubetsuProp::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	CDcdTargetOnPaint	aCDcdTargetOnPaint( GetSafeHwnd() , &dc.m_ps ) ; 
	
	{
		//�����\�����F
		CConverter_WinGdi	aConverter ;

		CRect	aRect = MfcUtil::GetDlgControlRect( this , IDC_STATIC_JikokuhyouMojiColor ) ;
		CdDcdZoneXy	aCdDcdZoneXy = aConverter.CdDcdZoneXyOf( aRect ) ;
		CaDcdTargetItemPosition	aTarget( &aCDcdTargetOnPaint , aCdDcdZoneXy ) ;
		m_pdcdJikokuhyouMojiColor->DcDraw( &aTarget ) ;
	}
	{
		//�����\�t�H���g
		CConverter_WinGdi	aConverter ;

		CRect	aRect = MfcUtil::GetDlgControlRect( this , IDC_STATIC_JikokuhyouFont ) ;
		CdDcdZoneXy	aCdDcdZoneXy = aConverter.CdDcdZoneXyOf( aRect ) ;
		CaDcdTargetItemPosition	aTarget( &aCDcdTargetOnPaint , aCdDcdZoneXy ) ;
		m_pdcdJikokuhyouFont->DcDraw( &aTarget ) ;
	}
	{
		//�_�C���O�������X�^�C��
		CConverter_WinGdi	aConverter ;

		CRect	aRect = MfcUtil::GetDlgControlRect( this , IDC_STATIC_DiagramSen ) ;
		CdDcdZoneXy	aCdDcdZoneXy = aConverter.CdDcdZoneXyOf( aRect ) ;
		CaDcdTargetItemPosition	aTarget( &aCDcdTargetOnPaint , aCdDcdZoneXy ) ;
		m_pdcdDiagramSen->DcDraw( &aTarget ) ;
	}
}




void CDlgRessyasyubetsuProp::OnOK() 
{
	int iResult = m_PropEditUiInternal.EndEdit() ;
	if ( iResult >= 0 )
	{
		CDialog::OnOK();
	}

}

void CDlgRessyasyubetsuProp::OnCHECKDiagramSenStyleIsBold() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyasyubetsuProp::OnBUTTONJikokuhyouMojiColor() 
{
	CConverter_WinGdi aConverter ;
	CColorDialog	aCColorDialog( 
		aConverter.COLORREFOf( m_PropEditUiInternal.GetUiData()->colorJikokuhyouMojiColor), 
		0 , 
		this ) ;
	if ( aCColorDialog.DoModal() == IDOK )
	{ 
		m_PropEditUiInternal.GetUiData()->colorJikokuhyouMojiColor  
			= aConverter.CdColorPropOf( aCColorDialog.GetColor() ) ;
		m_PropEditUiInternal.OnUiDataChanged() ;
	}
	
}

void CDlgRessyasyubetsuProp::OnBUTTONDiagramSeniColor() 
{
	CConverter_WinGdi aConverter ;
	CColorDialog	aCColorDialog( 
		aConverter.COLORREFOf( m_PropEditUiInternal.GetUiData()->colorDiagramSenColor ) , 
		0 , this ) ;
	if ( aCColorDialog.DoModal() == IDOK )
	{ 
		m_PropEditUiInternal.GetUiData()->colorDiagramSenColor 
			= aConverter.CdColorPropOf( aCColorDialog.GetColor() ) ;
		m_PropEditUiInternal.OnUiDataChanged() ;

	}
	
}

void CDlgRessyasyubetsuProp::OnSelchangeCOMBODiagramSenStyle() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}
void CDlgRessyasyubetsuProp::OnCbnSelchangeComboJikokuhyoufontindex()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyasyubetsuProp::OnEnKillfocusEditSyubetsumei()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyasyubetsuProp::OnEnKillfocusEditRyakusyou()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyasyubetsuProp::OnCbnSelchangeComboStopmarkdrawtype()
{
	m_PropEditUiInternal.OnUiChanged() ;
}


} //namespace ViewRessyasyubetsu
