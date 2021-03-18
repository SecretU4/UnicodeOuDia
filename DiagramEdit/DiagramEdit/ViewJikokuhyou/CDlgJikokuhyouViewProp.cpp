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
// CDlgJikokuhyouViewProp.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"

#include "str/tstring.h"
#include "str/strToWstr.h"
#include "str/CStrCharSizeMb.h"

#include "..\DiagramEdit.h"
#include "CDlgJikokuhyouViewProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

/////////////////////////////////////////////////////////////////////////////
// CDlgJikokuhyouViewProp �_�C�A���O


CDlgJikokuhyouViewProp::CDlgJikokuhyouViewProp(
		const CdDedJikan& jikanPasteIdouryou , 
		enum CWndJikokuhyou::EEkijikokuSort eEkijikokuSort ,
		CWnd* pParent )
	: CDialog(CDlgJikokuhyouViewProp::IDD, pParent)
	, m_jikanPasteIdouryou( jikanPasteIdouryou ) 
	, m_eEkijikokuSort( eEkijikokuSort ) 
	, m_iEDIT_PasteZoubun(0)
	, m_iRADIO_EKIJIKOKUSORT(0)
{
	//{{AFX_DATA_INIT(CDlgJikokuhyouViewProp)
	//}}AFX_DATA_INIT

	m_iEDIT_PasteZoubun = jikanPasteIdouryou.getTotalSeconds() / 60 ;
	m_iRADIO_EKIJIKOKUSORT = (int)m_eEkijikokuSort ;
}


void CDlgJikokuhyouViewProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgJikokuhyouViewProp)
	DDX_Text(pDX, IDC_EDIT_PasteZoubun, m_iEDIT_PasteZoubun);
	//}}AFX_DATA_MAP
	DDX_Radio(pDX, IDC_RADIO_EKIJIKOUSORT_0, m_iRADIO_EKIJIKOKUSORT);
}


BEGIN_MESSAGE_MAP(CDlgJikokuhyouViewProp, CDialog)
	//{{AFX_MSG_MAP(CDlgJikokuhyouViewProp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgJikokuhyouViewProp ���b�Z�[�W �n���h��

void CDlgJikokuhyouViewProp::OnOK() 
{
	int iRv = 0 ;
	// --------------------------------
	//	UpdateData()�̑O����
	// --------------------------------
	//IDC_EDIT_PasteZoubun 
	{
		//	�󕶎���Ȃ�A0��₢�܂��B
		CWnd* pCWnd = GetDlgItem( IDC_EDIT_PasteZoubun ) ;
		CString	strLs ;
		pCWnd->GetWindowText( strLs ) ;
		strLs = tstringOf( 
			CStrCharSizeMb::strToSingleByte( (LPCTSTR)strLs ) ).c_str();
		if ( strLs.IsEmpty() )
		{
			strLs = _T( "0" ) ;
		}
		pCWnd->SetWindowText( strLs ) ;
	}

	if ( !UpdateData() )
	{
		iRv = -1 ;	//	UpdateData()�Ɏ��s���܂����B(�G���[�\���ς�)
	}
	
	// --------------------------------
	//	�R���g���[���̒l����荞��
	// --------------------------------
	if ( iRv >= 0 )
	{
		m_jikanPasteIdouryou = m_iEDIT_PasteZoubun * 60 ;	
		{
			switch( m_iRADIO_EKIJIKOKUSORT )
			{
			case 0:
				m_eEkijikokuSort = CWndJikokuhyou::EEkijikokuSort_Ekiatsukai ;
				break ;
			case 1:
				m_eEkijikokuSort = CWndJikokuhyou::EEkijikokuSort_Transfer ;
				break ;
			}
		}
	}

	// --------------------------------
	if ( iRv >= 0 )
	{
		//	�G���[���Ȃ���΃_�C�A���O���I��
		CDialog::OnOK();
	}
	else
	{
		CString strErrorMsg ;
		switch( iRv )
		{
		case -1:	//	UpdateData()�Ɏ��s���܂����B(�G���[�\���ς�)
			//	���̏ꍇ�́A�G���[���b�Z�[�W�͕\�����܂���B
			break ;
		default:
			strErrorMsg.Format( _T( "Error=%d" ) , iRv ) ;
			break ;
		}
		if ( strErrorMsg.GetLength() > 0 )
		{
			MessageBox( strErrorMsg , NULL , MB_ICONERROR ) ; 
		}
	}
}
} //namespace ViewJikokuhyou
