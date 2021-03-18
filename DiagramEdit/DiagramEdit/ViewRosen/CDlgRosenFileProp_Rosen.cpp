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
// DlgRosenFileProp_Rosen.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "str/CStrCharSizeMb.h"

#include "..\DiagramEdit.h"
#include "CDlgRosenFileProp.h"
#include "CDlgRosenFileProp_Rosen.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRosen{

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp_Rosen �_�C�A���O
// ********************************
//	CDlgRosenFileProp_Rosen
// ********************************

CDlgRosenFileProp* CDlgRosenFileProp_Rosen::GetParent() 
{
	return static_cast<CDlgRosenFileProp*>( CWnd::GetParent() ) ;
}

void CDlgRosenFileProp_Rosen::updateUI() 
{
	CDlgRosenFileProp::CPropEditorData*	pPropEditorData = GetParent()->getPropEditorData() ;	
	// --------------------------------
	m_strEDIT_RosenName 
		= pPropEditorData->getUIRosenName().c_str()  ;	
	m_iEDIT_EkimeiLength 
		= pPropEditorData->getUIDispProp().getEkimeiLength()  ;	
	m_iEDIT_JikokuhyouRessyaWidth 
		= pPropEditorData->getUIDispProp().getJikokuhyouRessyaWidth(); 
	// --------------------------------

	UpdateData( FALSE ) ;
}

int CDlgRosenFileProp_Rosen::updatePropEditorData() 
{
	CDlgRosenFileProp::CPropEditorData*	pPropEditorData = GetParent()->getPropEditorData() ;	
	// --------------------------------
	int	iRv = 0 ;
	if ( iRv >= 0 )
	{
		CString	aString ;
		GetDlgItemText( IDC_EDIT_EkimeiLength , aString ) ;
		aString = CStrCharSizeMb::strToSingleByte( (LPCTSTR)aString ).c_str() ;
		SetDlgItemText( IDC_EDIT_EkimeiLength , aString ) ;
		GetDlgItemText( IDC_EDIT_JikokuhyouRessyaWidth , aString ) ;
		aString = CStrCharSizeMb::strToSingleByte( (LPCTSTR)aString ).c_str() ;
		SetDlgItemText( IDC_EDIT_JikokuhyouRessyaWidth , aString ) ;

		if ( !UpdateData() )
		{
			iRv = -1 ;
		}
	}
	if ( iRv >= 0 )
	{
		pPropEditorData->setUIRosenName( (LPCTSTR)m_strEDIT_RosenName ) ;
		{
			CdDedDispProp	aDispProp = pPropEditorData->getUIDispProp() ;
			aDispProp.setEkimeiLength( m_iEDIT_EkimeiLength ) ;
			aDispProp.setJikokuhyouRessyaWidth( m_iEDIT_JikokuhyouRessyaWidth ) ;
			pPropEditorData->setUIDispProp( aDispProp ) ;
		}
	}
	// --------------------------------
	return iRv ;	
}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

CDlgRosenFileProp_Rosen::CDlgRosenFileProp_Rosen(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRosenFileProp_Rosen::IDD, pParent)
	, m_iEDIT_JikokuhyouRessyaWidth(0)
{
	//{{AFX_DATA_INIT(CDlgRosenFileProp_Rosen)
	m_strEDIT_RosenName = _T("");
	m_iEDIT_EkimeiLength = 5;
	//}}AFX_DATA_INIT
}


void CDlgRosenFileProp_Rosen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRosenFileProp_Rosen)
	DDX_Text(pDX, IDC_EDIT_RosenName, m_strEDIT_RosenName);
	DDX_Text(pDX, IDC_EDIT_EkimeiLength, m_iEDIT_EkimeiLength);
	DDV_MinMaxUInt(pDX, m_iEDIT_EkimeiLength, 1, 29);
	DDX_Text(pDX, IDC_EDIT_JikokuhyouRessyaWidth, m_iEDIT_JikokuhyouRessyaWidth);
	DDV_MinMaxInt(pDX, m_iEDIT_JikokuhyouRessyaWidth, 4, 6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRosenFileProp_Rosen, CDialog)
	//{{AFX_MSG_MAP(CDlgRosenFileProp_Rosen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp_Rosen ���b�Z�[�W �n���h��

BOOL CDlgRosenFileProp_Rosen::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

} //namespace ViewRosen
