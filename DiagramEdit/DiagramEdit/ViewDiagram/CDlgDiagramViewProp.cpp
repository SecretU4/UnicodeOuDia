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
// CDlgDiagramViewProp.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "str/strToInt.h"
#include "str/CStrCharSizeMb.h"

#include "..\diagramedit.h"
#include "..\entDed\entDed.h"
#include "DcdCd/Pos/CLineFunc.h"
#include "CDlgDiagramViewProp.h"

using namespace std ;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewDiagram{

/** �����̏�����ێ����܂��B */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	false ,		//	NoColon 
	CdDedJikoku::CConv::EHour_Zero ,	// ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" �Ƃ��܂�
	CdDedJikoku::CConv::ESecond_NoSecond 	// �b����ɏo�͂��܂���B 
	) ;

/** ���Ԃ̏�����ێ����܂��B */
const CdDedJikan::CConv	g_CdDedJikanConv(
	true ,		//	NoSecond
	false ,		//	PlusDisplay 
	false ) ;	//	PlusToSpace 

/////////////////////////////////////////////////////////////////////////////
// CDlgDiagramViewProp �_�C�A���O


CDlgDiagramViewProp::CDlgDiagramViewProp(
		const CdDcdZoneXy&	zonexyCentDedDiaZone_Dgr ,
		BOOL bEnableYokojiku ,
		BOOL bEnableTatejiku ,
		const CdDcdZoneXy&	zonexyCWndDiagramZone_Dgr ,
		int idxVlineMode ,
		CWnd* pParent )
	: CDialog(CDlgDiagramViewProp::IDD, pParent)
	, m_zonexyCentDedDiaZone_Dgr( zonexyCentDedDiaZone_Dgr )
	, m_bEnableYokojiku(bEnableYokojiku)
	, m_bEnableTatejiku(bEnableTatejiku)
	, m_zonexyCWndDiagramZone_Dgr( zonexyCWndDiagramZone_Dgr )
	, m_idxVlineMode( idxVlineMode ) 
{
	//{{AFX_DATA_INIT(CDlgDiagramViewProp)
	m_strEDIT_YokojikuPos = _T("");
	m_strEDIT_YokojikuSize = _T("");
	m_iCOMBO_Jikanmemori = -1;
	m_iEDIT_TatejikuPos = 0;
	m_iEDIT_TatejikuSize = 0;
	//}}AFX_DATA_INIT

	if ( m_bEnableYokojiku )
	{
		m_strEDIT_YokojikuPos = g_CdDedJikokuConv.encode( CdDedJikoku( m_zonexyCWndDiagramZone_Dgr.getX().getPos() ) ).c_str() ;
		m_strEDIT_YokojikuSize = g_CdDedJikanConv.encode( CdDedJikan( m_zonexyCWndDiagramZone_Dgr.getX().getSize() ) ).c_str() ;
	}
	if ( m_bEnableTatejiku )
	{
		m_iEDIT_TatejikuPos = ( m_zonexyCWndDiagramZone_Dgr.getY().getPos() - 
			m_zonexyCentDedDiaZone_Dgr.getY().getPos() ) * 
			100 / m_zonexyCentDedDiaZone_Dgr.getY().getSize() ;
		m_iEDIT_TatejikuSize = ( m_zonexyCWndDiagramZone_Dgr.getY().getSize() * 
			100 / m_zonexyCentDedDiaZone_Dgr.getY().getSize() );
	}
	m_iCOMBO_Jikanmemori = m_idxVlineMode ;


}


void CDlgDiagramViewProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDiagramViewProp)
	DDX_Text(pDX, IDC_EDIT_YokojikuPos, m_strEDIT_YokojikuPos);
	DDX_Text(pDX, IDC_EDIT_YokojikuSize, m_strEDIT_YokojikuSize);
	DDX_CBIndex(pDX, IDC_COMBO_Jikanmemori, m_iCOMBO_Jikanmemori);
	DDX_Text(pDX, IDC_EDIT_TatejikuPos, m_iEDIT_TatejikuPos);
	DDX_Text(pDX, IDC_EDIT_TatejikuSize, m_iEDIT_TatejikuSize);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDiagramViewProp, CDialog)
	//{{AFX_MSG_MAP(CDlgDiagramViewProp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDiagramViewProp ���b�Z�[�W �n���h��

void CDlgDiagramViewProp::OnOK() 
{
	int iRv = 0 ;
	
	if ( !UpdateData() )
	{
		return ;
	}
	
	if ( m_bEnableYokojiku )	//�����̃G�f�B�b�g�{�b�N�X��L��
	{
		CdDedJikoku	jikokuYokojikuPos ;
		CdDedJikan	jikanYokojikuSize ;


		if ( iRv >= 0 )
		{
			if ( jikokuYokojikuPos.decode( 
				CStrCharSizeMb::strToSingleByte( (LPCTSTR)m_strEDIT_YokojikuPos ) 
				) < 0 )
			{
				iRv = -1 ;	//	�����\���͈͂̋N�_���A�����Ƃ��ĉ��߂ł��܂���B
			}
		}
		if ( iRv >= 0 )
		{
			if ( jikanYokojikuSize.decode( 
				CStrCharSizeMb::strToSingleByte( (LPCTSTR)m_strEDIT_YokojikuSize ) 
				) < 0 )
			{
				iRv = -2 ;	//	�����\���͈͂��A���ԂƂ��ĉ��߂ł��܂���B
			}
			else if ( jikanYokojikuSize.getTotalSeconds() > 24*60*60 )
			{
				iRv = -3 ;	//	�����\���͈͂��傫�����܂��B24���Ԉȉ��̒l��ݒ肵�Ă��������B
			}
			else if ( jikanYokojikuSize.getTotalSeconds() <= 0 )
			{
				iRv = -6 ;	//	�����\���͈͂����������܂��B1���ȏ�̒l��ݒ肵�Ă��������B
			}
		}
		if ( iRv >= 0 )
		{
			CdDcdZone	zoneX( 
				jikokuYokojikuPos.getTotalSeconds() ,
				jikanYokojikuSize.getTotalSeconds() ) ;
			if ( zoneX.getPos() < m_zonexyCentDedDiaZone_Dgr.getX().getPos() )
			{
				//	�����\���͈͂̋N�_���A
				//	�w�_�C���O�����G���e�B�e�B���W�n�x�̋N�_��菬�����Ȃ�A
				//	24���Ԃ����Z
				zoneX.setPos( zoneX.getPos() + 24*60*60 ) ;
			}
			if ( m_zonexyCentDedDiaZone_Dgr.getX().getEndPos() < zoneX.getEndPos() )
			{
				iRv = -4 ;	//	�����\���͈͂��A�_�C���O�����̋N�_�������z���Ă��܂��B
							//	%s ���z���Ȃ��悤�ɐݒ肵�Ă��������B
			}
			else
			{
				m_zonexyCWndDiagramZone_Dgr.setX( zoneX ) ;
			}
			
		}	
		
	}
	if ( m_bEnableTatejiku )	//	�c���̃G�f�B�b�g�{�b�N�X��L��
	{
		if ( iRv >= 0 )
		{
			if ( !( 0 <= m_iEDIT_TatejikuPos && m_iEDIT_TatejikuPos <= 100 ) )
			{
				iRv = -8 ;	//	�c���\���͈͂̏�[���͈͓��ɂ���܂���\n
							//	0%�ȏ�100%�ȉ��̒l���w�肵�Ă��������B
			}
			else if ( !( 1 <= m_iEDIT_TatejikuSize && m_iEDIT_TatejikuSize <= 1000 ) )
			{
				iRv = -9 ;	//	�c���\���͈͂̕����͈͓��ɂ���܂���\n
							//	1%�ȏ�1000%�ȉ��̒l���w�肵�Ă��������B
			}
		}
		if ( iRv >= 0 )
		{
			CdDcdZone	zoneY( m_iEDIT_TatejikuPos * m_zonexyCentDedDiaZone_Dgr.getY().getSize() / 100 +
				m_zonexyCentDedDiaZone_Dgr.getY().getPos() ,
				m_iEDIT_TatejikuSize * m_zonexyCentDedDiaZone_Dgr.getY().getSize() / 100 ) ;
			
			m_zonexyCWndDiagramZone_Dgr.setY( zoneY ) ;
		}
	}
	if ( iRv >= 0 )
	{
		m_idxVlineMode = m_iCOMBO_Jikanmemori ;
		if ( m_idxVlineMode < 0 ){
			m_idxVlineMode = 0 ;
		}
	}
		//iRv = 
		//		-1 ;	//	�����\���͈͂̋N�_���A�����Ƃ��ĉ��߂ł��܂���B
		//		-2 ;	//	�����\���͈͂��A���ԂƂ��ĉ��߂ł��܂���B
		//		-3 ;	//	�����\���͈͂��傫�����܂��B24���Ԉȉ��̒l��ݒ肵�Ă��������B
		//		-4 ;	//	�����\���͈͂��A�_�C���O�����̋N�_�������z���Ă��܂��B
		//				//	%s ���z���Ȃ��悤�ɐݒ肵�Ă��������B
		//		-6 ;	//	�����\���͈͂����������܂��B1���ȏ�̒l��ݒ肵�Ă��������B
		//		-8 ;	//	�c���\���͈͂̏�[���͈͓��ɂ���܂���
		//				//	0%�ȏ�100%�ȉ��̒l���w�肵�Ă��������B
		//		-9 ;	//	�c���\���͈͂̕����͈͓��ɂ���܂���
		//				//	1%�ȏ�1000%�ȉ��̒l���w�肵�Ă��������B
	if ( iRv >= 0 )
	{
		CDialog::OnOK();
	}
	else
	{
		CString	strError ;
		switch( iRv ){
		 case -1 :	
			{
				GetDlgItem(IDC_ERR_1)->GetWindowText( strError ) ;
			}
			break ;
		 case -2 :	
			{
				GetDlgItem(IDC_ERR_2)->GetWindowText( strError ) ;
			}
			break ;
		 case -3 :	
			{
				GetDlgItem(IDC_ERR_3)->GetWindowText( strError ) ;
			}
			break ;
		 case -4 :	
			{
				string	strJikoku = g_CdDedJikokuConv.encode( CdDedJikoku( m_zonexyCentDedDiaZone_Dgr.getX().getPos() ) ) ;
				CString	strFmt ;
				GetDlgItem(IDC_ERR_4)->GetWindowText( strFmt ) ;
				strError.Format( strFmt , strJikoku.c_str() ) ;
			}
			break ;
		 case -6 :	
			{
				GetDlgItem(IDC_ERR_6)->GetWindowText( strError ) ;
			}
			break ;
		 case -8 :	
			{
				GetDlgItem(IDC_ERR_8)->GetWindowText( strError ) ;
			}
			break ;
		 case -9 :	
			{
				GetDlgItem(IDC_ERR_9)->GetWindowText( strError ) ;
			}
			break ;
		 default :	
			{
				CString	strFmt ;
				GetDlgItem(IDC_ERR_X)->GetWindowText( strFmt ) ;
				strError.Format( strFmt , iRv ) ;
			}
			break ;
		}
		MessageBox( strError , NULL , MB_ICONEXCLAMATION | MB_OK ) ;
	}

}

BOOL CDlgDiagramViewProp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if( !m_bEnableYokojiku )
	{
		GetDlgItem(IDC_EDIT_YokojikuPos)->EnableWindow(FALSE) ;
		GetDlgItem(IDC_EDIT_YokojikuSize)->EnableWindow(FALSE) ;
	}
	if( !m_bEnableTatejiku )
	{
		GetDlgItem(IDC_EDIT_TatejikuPos)->EnableWindow(FALSE) ;
		GetDlgItem(IDC_EDIT_TatejikuSize)->EnableWindow(FALSE) ;
	}
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
} //namespace ViewDiagram
