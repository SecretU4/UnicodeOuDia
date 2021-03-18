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
// CDlgRosenFileProp_Diagram.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"


#include "str/CStrCharSizeMb.h"

#include "..\DiagramEdit.h"
#include "CDlgRosenFileProp.h"
#include "CDlgRosenFileProp_Diagram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRosen{

/** �����̏�����ێ����܂��B */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	false ,		//	NoColon 
	CdDedJikoku::CConv::EHour_Zero ,	// ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" �Ƃ��܂�
	CdDedJikoku::CConv::ESecond_NoSecond 	// �b����ɏo�͂��܂���B 
	) ;

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp_Diagram �_�C�A���O
// --------------------------------
//	�����֐�
// --------------------------------
CDlgRosenFileProp* CDlgRosenFileProp_Diagram::GetParent() 
{
	return static_cast<CDlgRosenFileProp*>( CWnd::GetParent() ) ;
}

void CDlgRosenFileProp_Diagram::updateUIState() 
{
}
	
// ********************************
//	CDlgRosenFileProp_Diagram
// ********************************
void CDlgRosenFileProp_Diagram::updateUI()
{
	CDlgRosenFileProp::CPropEditorData* pPropEditorData = GetParent()->getPropEditorData() ;

	m_strEDIT_DoagramKitenJikoku = 
		g_CdDedJikokuConv.encode( pPropEditorData->getUIKitenJikoku() ).c_str() ;
	m_iEDIT_DiagramDgrYZahyouKyoriDefault = 
		pPropEditorData->getUIDiagramDgrYZahyouKyoriDefault() / 60  ;

	UpdateData( FALSE ) ;
}
int CDlgRosenFileProp_Diagram::updatePropEditorData()
{
	CDlgRosenFileProp::CPropEditorData* pPropEditorData = GetParent()->getPropEditorData() ;
	int	iRv = 0 ;
	if ( iRv >= 0 )
	{
		if ( !UpdateData() )
		{
			iRv = -1 ;
		}
	}
	CdDedJikoku	jikokuKitenJikoku ;
	if ( iRv >= 0 )
	{
		if ( jikokuKitenJikoku.decode( 
				CStrCharSizeMb::strToSingleByte( (LPCTSTR)m_strEDIT_DoagramKitenJikoku ) ) < 0 )
		{
			iRv = -11 ;	//	�_�C���O�����N�_�������s���ł�
		}
	}
	//jikokuKitenJikoku = �_�C���O�����N�_����
	if ( iRv >= 0 )
	{
		pPropEditorData->setUIKitenJikoku( jikokuKitenJikoku ) ; 
		pPropEditorData->setUIDiagramDgrYZahyouKyoriDefault( 
			m_iEDIT_DiagramDgrYZahyouKyoriDefault * 60 );
	}
	// --------------------------------
	if ( iRv < 0 )
	{
		CString	strError ;
		switch( iRv )
		{
		 case -11 :	
			GetDlgItem( IDC_STATIC_ERROR_KitenJikoku )->GetWindowText( strError ) ;
			break ;
		}
		if ( !strError.IsEmpty() )
		{
			MessageBox( strError , NULL ,  MB_OK | MB_ICONEXCLAMATION ) ;
		}
	}


	return iRv ;	
}


// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

CDlgRosenFileProp_Diagram::CDlgRosenFileProp_Diagram(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRosenFileProp_Diagram::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRosenFileProp_Diagram)
	m_strEDIT_DoagramKitenJikoku = _T("");
	m_iEDIT_DiagramDgrYZahyouKyoriDefault = 0;
	//}}AFX_DATA_INIT
}


void CDlgRosenFileProp_Diagram::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRosenFileProp_Diagram)
	DDX_Text(pDX, IDC_EDIT_DiagramKitenJikoku, m_strEDIT_DoagramKitenJikoku);
	DDX_Text(pDX, IDC_EDIT_DiagramDgrYZahyouKyoriDefault, m_iEDIT_DiagramDgrYZahyouKyoriDefault);
	DDV_MinMaxInt(pDX, m_iEDIT_DiagramDgrYZahyouKyoriDefault, 1, 30);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRosenFileProp_Diagram, CDialog)
	//{{AFX_MSG_MAP(CDlgRosenFileProp_Diagram)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp_Diagram ���b�Z�[�W �n���h��

BOOL CDlgRosenFileProp_Diagram::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// --------------------------------
	updateUIState() ;
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgRosenFileProp_Diagram::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
	
}
} //namespace ViewRosen
