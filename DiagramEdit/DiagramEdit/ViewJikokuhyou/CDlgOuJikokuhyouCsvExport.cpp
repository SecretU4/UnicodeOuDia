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
// CDlgOuJikokuhyouCsvExport.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "MfcUtil\MfcUtil.h"
#include "str\CsvDocument\CdCsvDocument.h"
#include "str\CsvDocument\CconvCsvDocument.h"
#include "str\strtoint.h"
#include "str\vectorToFile.h"

#include "..\diagramedit.h"
#include "..\resource.h"
#include "CDlgOuJikokuhyouCsvExport.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{
using namespace std ;

/////////////////////////////////////////////////////////////////////////////
// CDlgOuJikokuhyouCsvExport �_�C�A���O


CDlgOuJikokuhyouCsvExport::CDlgOuJikokuhyouCsvExport(
 	const CentDedRosen* pCentDedRosen ,
	int  iDiaIndex ,
	ERessyahoukou  eRessyahoukou ,
	CWnd* pParent )
	: CDialog(CDlgOuJikokuhyouCsvExport::IDD, pParent)
 	, m_pCentDedRosen( pCentDedRosen )
	, m_iDiaIndex( iDiaIndex ) 
	, m_eRessyahoukou( eRessyahoukou )
{
	//{{AFX_DATA_INIT(CDlgOuJikokuhyouCsvExport)
	//}}AFX_DATA_INIT
}


void CDlgOuJikokuhyouCsvExport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOuJikokuhyouCsvExport)
	DDX_Control(pDX, IDC_EDIT_RESSYACOUNT, m_wndEDIT_RESSYACOUNT);
	DDX_Control(pDX, IDC_EDIT_RESSYAINDEX, m_wndEDIT_RESSYAINDEX);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOuJikokuhyouCsvExport, CDialog)
	//{{AFX_MSG_MAP(CDlgOuJikokuhyouCsvExport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOuJikokuhyouCsvExport ���b�Z�[�W �n���h��

BOOL CDlgOuJikokuhyouCsvExport::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// --------------------------------
	int iRv = 0 ;
	const CentDedDia* pCentDedDia = NULL ;
	const Mu<const CentDedRessya*>* pCentDedRessyaContGet = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedDia = m_pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( m_iDiaIndex ) ;
		if ( pCentDedDia == NULL )
		{
			iRv = -11 ;	//	m_iDiaIndex ���s���ł��B
		}
	}
	if 	( iRv >= 0 )
	{
		pCentDedRessyaContGet = pCentDedDia->getCentDedRessyaCont( m_eRessyahoukou )->getMuPtr() ;
	}
	//pCentDedRessyaContGet = �ΏۂƂȂ��ԃR���e�i
	
	
	// --------------------------------
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgOuJikokuhyouCsvExport::OnOK() 
{
	int iRv = 0 ;
	CString	strError ;
	// --------------------------------
	const CentDedDia* pCentDedDia = NULL ;
	const Mu<const CentDedRessya*>* pCentDedRessyaContGet = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedDia = m_pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( m_iDiaIndex ) ;
		if ( pCentDedDia == NULL )
		{
			iRv = -11 ;	//	m_iDiaIndex ���s���ł��B
		}
	}
	if 	( iRv >= 0 )
	{
		pCentDedRessyaContGet = pCentDedDia->getCentDedRessyaCont( m_eRessyahoukou )->getMuPtr() ;
	}
	//pCentDedRessyaContGet = �ΏۂƂȂ��ԃR���e�i
	
	
	// --------------------------------
	//	���͒l�̎擾
	// --------------------------------
	int iRessyaIndex = 0 ;
	int iRessyaCount = 0 ;
	if ( iRv >= 0 )
	{
		CString aString ;
		GetDlgItemText( IDC_EDIT_RESSYAINDEX , aString ) ;
		BOOL bTrans = FALSE ;
		if ( !aString.IsEmpty() )
		{
			iRessyaIndex = (int)GetDlgItemInt( IDC_EDIT_RESSYAINDEX , &bTrans , FALSE ) - 1 ;
			if ( !bTrans || !( 0 <= iRessyaIndex && iRessyaIndex < pCentDedRessyaContGet->size() ) )
			{
				GetDlgItemText( IDC_TEXT_INPUTERROR , strError ) ;
				GotoDlgCtrl( GetDlgItem( IDC_EDIT_RESSYAINDEX ) ) ;
				iRv = -1 ;	//	���̓G���[����
			}
		}
		else
		{
			iRessyaIndex = 0 ;
		}
	}
	if ( iRv >= 0 )
	{
		CString aString ;
		GetDlgItemText( IDC_EDIT_RESSYACOUNT , aString ) ;
		BOOL bTrans = FALSE ;
		if ( !aString.IsEmpty() )
		{
			iRessyaCount = (int)GetDlgItemInt( IDC_EDIT_RESSYACOUNT , &bTrans , FALSE ) ;
			if ( !bTrans )
			{
				GetDlgItemText( IDC_TEXT_INPUTERROR , strError ) ;
				GotoDlgCtrl( GetDlgItem( IDC_EDIT_RESSYACOUNT ) ) ;
				iRv = -1 ;	//	���̓G���[����
			}
		}
		else
		{
			iRessyaCount = pCentDedRessyaContGet->size() - iRessyaIndex  ;
		}
	}
	if ( iRessyaCount > pCentDedRessyaContGet->size() - iRessyaIndex ) 
	{
		iRessyaCount = pCentDedRessyaContGet->size() - iRessyaIndex ;
	}
	//iRessyaIndex,iRessyaCount = ��Ԗ{���B
	
	// --------------------------------
	//	�o�̓t�@�C�������͒l�̎擾
	// --------------------------------
	if ( iRv >= 0 )
	{
		CFileDialog aDlg( 
			FALSE , 
			_T( "csv" ) , 
			m_strCsvFilename , 
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
			getCDiagramEditApp()->getCFileDialogFilterCsv(), 
			this );
		if ( aDlg.DoModal() != IDOK )
		{
			iRv = -2 ;	//	Cancel����܂����B
		}
		else
		{
			m_strCsvFilename = aDlg.GetPathName() ;
		}
	}
	//m_strCsvFilename = �w�肳�ꂽCSV�t�@�C����
	// --------------------------------
	//	CSV�t�@�C���̏o��
	// --------------------------------
	CWaitCursor aCursor ;
	if ( iRv >= 0 )
	{
		CconvJikokuhyouCsv	aConv( getCDiagramEditApp()->createCconvJikokuhyouCsv() ) ;
		CdCsvDocument	aCdCsvDocument ;
		int iResult = aConv.encode(
			*m_pCentDedRosen , 
			m_iDiaIndex , 
			m_eRessyahoukou , 
			iRessyaIndex , 
			iRessyaCount , 
			&aCdCsvDocument ) ;
		//iResult = 
		//	-1 ; // iDiaIndex ���s���ł��B
		//	-2 ; // iRessyaIndex ���s���ł��B
		//	-3 ; // iRessyaCount ���s���ł��B 
		if ( iResult < 0 )
		{
			GetDlgItemText( IDC_TEXT_ENCODE_ERROR , strError ) ;
			//strError="CSV�ւ̕ϊ��Ɏ��s���܂����B"

			strError.Format( _T( "%s(%d)" ) , CString( strError ), iResult ) ; 
			iRv = iResult - 10 ;
			//	-11 ; // iDiaIndex ���s���ł��B
			//	-12 ; // iRessyaIndex ���s���ł��B
			//	-13 ; // iRessyaCount ���s���ł��B 
		}
		else
		{
			string strCsvDocument ;
			CConvCsvDocument	aCConvCsvDocument ;
			strCsvDocument = aCConvCsvDocument.encode( &aCdCsvDocument ) ;
			int iResult = stringToFile( strCsvDocument , (LPCSTR)m_strCsvFilename ) ;
			if ( iResult < 0 )
			{
				GetDlgItemText( IDC_TEXT_FILE_SAVE_FAILED , strError ) ;
				//strError="�t�@�C���ւ̕ۑ��Ɏ��s���܂����B"

				iRv = -21 ; // �t�@�C���ւ̕ۑ��Ɏ��s���܂����B

			}
		}
	}
	// --------------------------------
	//	��Ԃ͈̔͂��w�肵��CSV�փG�N�X�|�[�g
	//	�����ꍇ�́A���̗�Ԕ͈͂��R���g���[���ɐݒ�
	// --------------------------------
	if ( iRv >= 0 )
	{
		if ( iRessyaIndex + iRessyaCount <  pCentDedRessyaContGet->size() )
		{
			iRessyaIndex += iRessyaCount ;
			SetDlgItemText( IDC_EDIT_RESSYAINDEX , stringOf( iRessyaIndex + 1 ).c_str() ) ;
			SetDlgItemText( IDC_EDIT_RESSYACOUNT , stringOf( iRessyaCount ).c_str() ) ;
		}
	}
	// --------------------------------

	if ( iRv < 0 )
	{
		if ( !strError.IsEmpty() )
		{
			MessageBox( strError , NULL , MB_ICONEXCLAMATION ) ;
		}
	}
	//CDialog::OnOK();
}

} //namespace ViewJikokuhyou
