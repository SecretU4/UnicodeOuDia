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
// ViewRosen\CDlgRosenCreateSubRosen.cpp : �����t�@�C��
//

#include "stdafx.h"

#include "str\strToWstr.h"
#include "str\tstring.h"

#include "..\DiagramEdit.h"
#include "CDlgRosenCreateSubRosen.h"

namespace ViewRosen{
using namespace OuLib ;

// CDlgRosenCreateSubRosen �_�C�A���O

IMPLEMENT_DYNAMIC(CDlgRosenCreateSubRosen, CDialog)

CDlgRosenCreateSubRosen::CDlgRosenCreateSubRosen(
	const CentDedEkiCont&	aCentDedEkiCont , 
	CWnd* pParent )
	: CDialog(CDlgRosenCreateSubRosen::IDD, pParent)
{
	const Mu<const CentDedEki*>* muCentDedEki = aCentDedEkiCont.getMuPtr() ;
	for ( int iEkiIndex = 0 ; iEkiIndex < muCentDedEki->size() ; iEkiIndex ++ )
	{
		m_arstrEkimei.push_back( muCentDedEki->get( iEkiIndex )->getEkimei() ) ;
	}
}

CDlgRosenCreateSubRosen::~CDlgRosenCreateSubRosen()
{
}

void CDlgRosenCreateSubRosen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SIHATSU_EKIINDEX, m_wndCOMBO_SIHATSU_EKIINDEX);
	DDX_Control(pDX, IDC_COMBO_SYUUCHAKU_EKIINDEX, m_wndCOMBO_SYUUCHAKU_EKIINDEX);
}


BEGIN_MESSAGE_MAP(CDlgRosenCreateSubRosen, CDialog)
END_MESSAGE_MAP()


// CDlgRosenCreateSubRosen ���b�Z�[�W �n���h��

BOOL CDlgRosenCreateSubRosen::OnInitDialog()
{
	CDialog::OnInitDialog();

	int iRv = 0 ;

	//IDC_COMBO_SIHATSU_EKIINDEX
	//IDC_COMBO_SYUUCHAKU_EKIINDEX
	if ( iRv >= 0 )
	{
		if ( m_arstrEkimei.size() < 3 )
		{
			iRv = -11 ;	//	3�w�����̘H���ł͎g�p�ł��܂���B
		}
		else
		{
			for ( int iEkiIndex = 0 ; iEkiIndex < (int)m_arstrEkimei.size() ; iEkiIndex ++ )
			{
				m_wndCOMBO_SIHATSU_EKIINDEX.AddString( 
					tstringOf( m_arstrEkimei[ iEkiIndex ] ).c_str() ) ;
				m_wndCOMBO_SYUUCHAKU_EKIINDEX.AddString( 
					tstringOf( m_arstrEkimei[ iEkiIndex ] ).c_str() ) ;
			}
			m_wndCOMBO_SIHATSU_EKIINDEX.SetCurSel( 0 ) ;
			m_wndCOMBO_SYUUCHAKU_EKIINDEX.SetCurSel( m_wndCOMBO_SYUUCHAKU_EKIINDEX.GetCount() - 1 ) ;
		}
	}
	// --------------------------------
	CString strErrorMsg ;
	if ( iRv < 0 )
	{
		switch( iRv )
		{
		case -11 :	//	3�w�����̘H���ł͎g�p�ł��܂���B
			GetDlgItem( IDC_ERR_EKI_TOO_FEW )->GetWindowText( strErrorMsg ) ;
			break ;
		default:
			strErrorMsg.Format( _T( "Error (%d)" ) , iRv ) ;
			break ;
		}
	}
	if ( !strErrorMsg.IsEmpty() )
	{
		MessageBox( strErrorMsg , NULL , MB_ICONSTOP );
		EndDialog( IDCANCEL ) ;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}

void CDlgRosenCreateSubRosen::OnOK()
{
	int iRv = 0 ;
	if ( iRv >= 0 )
	{
		m_iSihatsuEkiIndex = m_wndCOMBO_SIHATSU_EKIINDEX.GetCurSel() ;
		if ( m_iSihatsuEkiIndex < 0 )
		{
			m_iSihatsuEkiIndex = 0 ;
		}
		m_iSyuuchakuEkiIndex = m_wndCOMBO_SYUUCHAKU_EKIINDEX.GetCurSel() ;
		if ( m_iSyuuchakuEkiIndex < 0 )
		{
			m_iSyuuchakuEkiIndex = m_wndCOMBO_SYUUCHAKU_EKIINDEX.GetCount() - 1 ;
		}
		if ( !( m_iSihatsuEkiIndex < m_iSyuuchakuEkiIndex ) )
		{
			iRv = -12 ;	//	�n���w���I���w����ɂ��Ă��������B
		}
	}
	// --------------------------------
	if ( iRv < 0 )
	{
		CString strErrorMsg ;
		switch( iRv )
		{
		case -12 :	//	3�w�����̘H���ł͎g�p�ł��܂���B
			GetDlgItem( IDC_ERR_EKIINDEX_ORDER )->GetWindowText( strErrorMsg ) ;
			break ;
		default:
			strErrorMsg.Format( _T( "Error (%d)" ) , iRv ) ;
			break ;
		}
		if ( !strErrorMsg.IsEmpty() )
		{
			MessageBox( strErrorMsg , NULL , MB_ICONSTOP );
		}
	}
	else
	{
		CDialog::OnOK();
	}
}
} //namespace ViewRosen
