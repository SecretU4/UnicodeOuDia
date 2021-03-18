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
// CDlgDiaList.cpp : �C���v�������e�[�V���� �t�@�C��
//	$Id: CDlgDiaList.cpp 378 2016-11-16 21:10:54Z okm $

#include "stdafx.h"

#include "NsOu/OuNew.h"
#include "NsMu/CaMui.h"

#include "..\DiagramEdit.h"
#include "..\DedRosenFileData\EditCmd\CRfEditCmd_Dia.h"
#include "..\DedRosenFileData\EditCmd\CRfEditCmd_DiaProp.h"
#include "CDlgDiaList.h"
#include "CDlgDiaProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRosen{
using namespace std ;


/////////////////////////////////////////////////////////////////////////////
// CDlgDiaList �_�C�A���O

void CDlgDiaList::updateControl() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;

	//	m_listboxDia
	{
		bool bMustUpdate = false ;
		{
			const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

			if ( pCentDedDiaContGet->size() != m_listboxDia.GetCount() ){
				bMustUpdate = true ;
			}	else	{
				int idx ;
				for ( idx = 0 ; !bMustUpdate && idx < m_listboxDia.GetCount() ; idx ++ ){
					const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idx ) ;
					string	strDiaName = pCentDedDia->getName() ;
					CString	strItem ;
					m_listboxDia.GetText( idx , strItem ) ;
					if ( strDiaName != (LPCTSTR)strItem ){
						bMustUpdate = true ;
					}
				}
			}
		}
		//bMustUpdate = ���X�g�{�b�N�X�̍X�V�̕K�v������Ȃ�^�ł�
		if ( bMustUpdate )
		{	

				int idxSelect = m_listboxDia.GetCurSel() ;

				// --------------------------------
				//	���X�g�{�b�N�X�̓��e��ݒ�
				// --------------------------------
				const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;
				m_listboxDia.ResetContent() ;
				int idx ;
				for ( idx = 0 ; idx < pCentDedDiaContGet->size() ; 
						idx ++ )
				{
					const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idx ) ;
					string	strDiaName = pCentDedDia->getName() ;
					m_listboxDia.AddString( strDiaName.c_str() ) ;
				}
				
				// --------------------------------
				//	���X�g�{�b�N�X�̑I���ʒu��ݒ�
				// --------------------------------
				if ( 0 <= idxSelect && idxSelect < m_listboxDia.GetCount() ){
					m_listboxDia.SetCurSel( idxSelect ) ;
				}
		}
	}
	//IDC_BUTTON_PROP
	{
		BOOL	bEnable = FALSE ;
		int idxSel = m_listboxDia.GetCurSel() ;
		if ( 0 <= idxSel && idxSel < m_listboxDia.GetCount() ){
			bEnable = TRUE ;
		}
		GetDlgItem( IDC_BUTTON_PROP )->EnableWindow( bEnable ) ;
	}
	//IDC_BUTTON_DELETE
	{
		BOOL	bEnable = FALSE ;
		int idxSel = m_listboxDia.GetCurSel() ;
		if ( 0 <= idxSel && idxSel < m_listboxDia.GetCount() ){
			bEnable = TRUE ;
		}
		GetDlgItem( IDC_BUTTON_DELETE )->EnableWindow( bEnable ) ;
	}
	//IDC_BUTTON_UP
	{
		BOOL	bEnable = FALSE ;
		int idxSel = m_listboxDia.GetCurSel() ;
		if ( 0 < idxSel && idxSel < m_listboxDia.GetCount() ){
			bEnable = TRUE ;
		}
		GetDlgItem( IDC_BUTTON_UP )->EnableWindow( bEnable ) ;
	}
	//IDC_BUTTON_DOWN
	{
		BOOL	bEnable = FALSE ;
		int idxSel = m_listboxDia.GetCurSel() ;
		if ( 0 <= idxSel && idxSel < m_listboxDia.GetCount() - 1 ){
			bEnable = TRUE ;
		}
		GetDlgItem( IDC_BUTTON_DOWN )->EnableWindow( bEnable ) ;
	}
}
void CDlgDiaList::execDlgDiaProp() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

	string	strDiaNamePrev ;
	int idx = m_listboxDia.GetCurSel() ;
	if ( !( 0 <= idx && idx < pCentDedDiaContGet->size() ) ){
		return ;
	}	else	{
		const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idx ) ;
		strDiaNamePrev = pCentDedDia->getName() ;
	}
	//idx = �ύX����_�C���̃C���f�N�X
	//strDiaNamePrev = �ύX����_�C���̃v���p�e�B(����)

	CDlgDiaProp	aDlg( strDiaNamePrev , this ) ;
	if ( aDlg.DoModal() == IDOK ){
		string strDiaName = aDlg.getName() ;
		
		// --------------------------------
		//	���ꖼ�̃_�C���́A�G���[�ɂ��܂��B
		// --------------------------------
		if ( strDiaName != strDiaNamePrev ){ 
			int idxDia = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( strDiaName ) ;
			if ( idxDia >= 0 ){
				CString strError ;
				strError.Format( IDS_ERR_DiaNameDuplex , strDiaName.c_str() ) ;
				MessageBox( strError , NULL , MB_OK | MB_ICONERROR ) ;
				return ;
			}
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�𐶐��E���s
		// --------------------------------
		{
			OuNew<CRfEditCmd>	pCmd( 
				new CRfEditCmd_DiaProp( 
					idx , strDiaName ) ) ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;
			
		}

		// --------------------------------
		//	�_�C�A���O�̍X�V
		// --------------------------------
		updateControl() ;
	}
	
}


// ----------------------------------------------------------------
CDlgDiaList::CDlgDiaList(
		CDiagramEditDoc* pCDiagramEditDoc ,
		CWnd* pParent )
	: CDialog(CDlgDiaList::IDD, pParent)
	, m_pCDiagramEditDoc( pCDiagramEditDoc ) 
{
	//{{AFX_DATA_INIT(CDlgDiaList)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CDlgDiaList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDiaList)
	DDX_Control(pDX, IDC_LIST_Dia, m_listboxDia);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDiaList, CDialog)
	//{{AFX_MSG_MAP(CDlgDiaList)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_PROP, OnButtonProp)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UP, OnButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, OnButtonDown)
	ON_LBN_SELCHANGE(IDC_LIST_Dia, OnSelchangeLISTDia)
	ON_LBN_DBLCLK(IDC_LIST_Dia, &CDlgDiaList::OnLbnDblclkListDia)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDiaList ���b�Z�[�W �n���h��

BOOL CDlgDiaList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	updateControl() ;
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgDiaList::OnOK() 
{
	//Return �L�[�ɂ��N���[�Y�͗}�~���܂��B	
	//CDialog::OnOK();
}

void CDlgDiaList::OnCancel() 
{
	CDialog::OnCancel();
}

void CDlgDiaList::OnButtonNew() 
{
	const CentDedRosen*	pCentDedRosen = m_pCDiagramEditDoc->
			getCDedRosenFileData()->getCentDedRosen() ;


	CDlgDiaProp	aDlg( "" , this ) ;
	if ( aDlg.DoModal() == IDOK ){
		string strDiaName = aDlg.getName() ;

		// --------------------------------
		//	���ꖼ�̃_�C���́A�G���[�ɂ��܂��B
		// --------------------------------
		int idxDia = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( strDiaName ) ;
		if ( idxDia >= 0 ){
			CString strError ;
			strError.Format( IDS_ERR_DiaNameDuplex , strDiaName.c_str() ) ;
			MessageBox( strError , NULL , MB_OK | MB_ICONERROR ) ;
			return ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�𐶐��E���s
		// --------------------------------
		{
			CentDedDiaCont	aCentDedDiaCont ;
			aCentDedDiaCont.insert( CentDedDia( strDiaName , 
				pCentDedRosen->getCentDedEkiCont()->getMuPtr()->size()  ) ) ;
			OuNew<CRfEditCmd>	pCmd( 
				new CRfEditCmd_Dia( INT_MAX , 0 , aCentDedDiaCont ) 
				) ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;
		}

		
		// --------------------------------
		//	�_�C�A���O�̍X�V
		// --------------------------------
		//	���X�g�{�b�N�X�ɃA�C�e����ǉ�
		m_listboxDia.AddString( strDiaName.c_str() ) ;
		m_listboxDia.SetCurSel( m_listboxDia.GetCount() - 1 ) ;

		updateControl() ;
		
	}
	
}

void CDlgDiaList::OnButtonProp() 
{
	execDlgDiaProp() ;	
}

void CDlgDiaList::OnButtonDelete() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

	string	strDiaName ;
	int idx = m_listboxDia.GetCurSel() ;
	if ( !( 0 <= idx && idx < pCentDedDiaContGet->size() ) ){
		return ;
	}	else	{
		const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idx ) ;
		strDiaName = pCentDedDia->getName() ;
	}
	//idx = �ύX����_�C���̃C���f�N�X

	// --------------------------------
	//	�폜�̊m�F
	// --------------------------------
	{
		CString	strMsg ;
		CString	strMsgFormat ;
		CString	strCaption ;
		GetDlgItemText( IDC_STATIC_ERROR_DeleteDiaPrompt , strMsgFormat ) ;
		GetDlgItemText( IDC_STATIC_ERROR_DeleteDiaPrompt2 , strCaption ) ;
		strMsg.Format( strMsgFormat , strDiaName.c_str() ) ;
		int iResult = MessageBox( strMsg , strCaption , MB_OKCANCEL | MB_ICONQUESTION ) ;
		if ( iResult != IDOK ){
			return ;
		}
	}	
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�𐶐��E���s
		// --------------------------------
		{
			CentDedDiaCont	aCentDedDiaCont ;
			OuNew<CRfEditCmd>	pCmd( 
				new CRfEditCmd_Dia( idx , 1 , aCentDedDiaCont ) 
				) ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;
		}
	// --------------------------------
	//	�_�C�A���O�̍X�V
	// --------------------------------
	updateControl() ;
}

void CDlgDiaList::OnButtonUp() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

	string	strDiaName ;
	int idx = m_listboxDia.GetCurSel() ;
	if ( !( 0 < idx && idx < pCentDedDiaContGet->size() ) ){
		return ;
	}
	// --------------------------------
	//	�R�}���h�I�u�W�F�N�g�𐶐��E���s
	// --------------------------------
	{
		CentDedDiaCont	aCentDedDiaCont;
		aCentDedDiaCont.insert( *pCentDedDiaContGet->get( idx ) ) ; 
		aCentDedDiaCont.insert( *pCentDedDiaContGet->get( idx - 1 ) ) ; 

		OuNew<CRfEditCmd>	pCmd( 
			new CRfEditCmd_Dia( idx - 1  , 2 , aCentDedDiaCont ) 
			) ;
		int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		ASSERT( iResult >= 0 ) ;
	}
	// --------------------------------
	//	�_�C�A���O�̍X�V
	// --------------------------------
	m_listboxDia.SetCurSel( idx - 1 ) ;
	updateControl() ;
}

void CDlgDiaList::OnButtonDown() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

	string	strDiaName ;
	int idx = m_listboxDia.GetCurSel() ;
	if ( !( 0 <= idx && idx < pCentDedDiaContGet->size() - 1 ) ){
		return ;
	}
	// --------------------------------
	//	�R�}���h�I�u�W�F�N�g�𐶐��E���s
	// --------------------------------
	{
		CentDedDiaCont	aCentDedDiaCont ;
		aCentDedDiaCont.insert( *pCentDedDiaContGet->get( idx + 1 ) ) ; 
		aCentDedDiaCont.insert( *pCentDedDiaContGet->get( idx  ) ) ; 

		OuNew<CRfEditCmd>	pCmd( 
			new CRfEditCmd_Dia( idx , 2 , aCentDedDiaCont ) 
			) ;
		int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		ASSERT( iResult >= 0 ) ;
	}
	// --------------------------------
	//	�_�C�A���O�̍X�V
	// --------------------------------
	m_listboxDia.SetCurSel( idx + 1 ) ;
	updateControl() ;
}

void CDlgDiaList::OnSelchangeLISTDia() 
{
	updateControl() ;
	
}

void CDlgDiaList::OnLbnDblclkListDia()
{
	execDlgDiaProp() ;
}
} //namespace ViewRosen
