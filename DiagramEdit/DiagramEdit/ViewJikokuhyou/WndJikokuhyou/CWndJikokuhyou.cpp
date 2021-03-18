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
/*
// ****************************************************************
//	CWndJikokuhyou.cpp
//	$Id: CWndJikokuhyou.cpp 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "NsOu\OuNew.h"
#include "NsOu\dynamic_castOu.h"
#include "str\CsvDocument\CConvCsvDocument.h"
#include "str\vectorToFile.h"
#include "logmsg\LogMsg.h"

#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CDcdLine.h"
#include "DcDraw\CDcdFillrectRop.h"
#include "DcDraw\CDcdTextbox.h"
#include "DcDraw\CConverter_WinGdi.h"

#include "MfcUtil\MfcUtil.h"

#include "..\JikokuhyouColSpec\JikokuhyouColSpec.h"
#include "..\..\DedRosenFileData\EditCmd\CRfEditCmd_Rosen.h"
#include "..\..\resource.h"
#include "..\..\entDed\CentDedRosen.h"
#include "..\..\DiagramEdit.h"
#include "..\..\ViewJikokuhyou\CDlgJikokuhyouViewProp.h"
#include "..\..\ViewDiagram\CDedDiagramView.h"
#include "..\CDlgOuJikokuhyouCsvExport.h"
#include "CCellBuilder.h"
#include "CWndJikokuhyou.h"
#include "CWjkState_Ressyahensyu.h"
#include "CWjkState_Renzoku.h"
#include "CWndJikokuhyou.h"

#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{ namespace WndJikokuhyou{
using namespace std ;
using namespace OuMfc::MfcUtil ;
using namespace OuLib::Str;
// ****************************************************************
//	CWndJikokuhyou
// ****************************************************************
// --------------------------------
//@name �����֐�
// --------------------------------
CJikokuhyouDoc*	CWndJikokuhyou::GetDocument() 
{
	CView* pCView = (CView*)GetParent() ;
	return (CJikokuhyouDoc*)pCView->GetDocument() ;
};

ERessyahoukou CWndJikokuhyou::getRessyahoukou() 
{
	return GetDocument()->getRessyahoukou() ;
};


const CentDedDia*	CWndJikokuhyou::getCentDedDia()
{
	const CentDedRosen*	pCentDedRosen = 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	int iDiaIndex = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( 
			GetDocument()->getDiaName() ) ;
	if ( iDiaIndex < 0 ){
		return ( NULL ) ;
	}
	const CentDedDia* pCentDedDia = pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( iDiaIndex ) ;
	return ( pCentDedDia ) ;
};

const CentDedRessyaCont*	CWndJikokuhyou::getCentDedRessyaCont()
{
	const CentDedDia* pCentDedDia = getCentDedDia() ;
	if ( pCentDedDia == NULL ){
		return ( NULL ) ;
	}
	return ( pCentDedDia->getCentDedRessyaCont( getRessyahoukou() ) ) ;
};	


	// --------------------------------
	//@name updateUI...() �E�Z���̍X�V
	// --------------------------------

void  CWndJikokuhyou::updateUIAll() 
{
	//	���̕ϐ��� true �̂Ƃ��́A
	//	�u�r���[���A�N�e�B�u�ȏ�Ԃł� updateUIAll() �v
	//	�܂ŁA������X�V����͍s���܂���B
	if ( m_bUpdate_All_Requested )
	{
		return ;
	}
	// --------------------------------

	//	�S�X�V
	CView *pView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	if ( pView != GetParent() )
	{
		//	�S�X�V��K�v�Ƃ���ꍇ�ŁA
		//	���̃r���[���A�N�e�B�u�łȂ��ꍇ��
		//	�S�X�V��ۗ����܂��B
		LogMsg( "CWndJikokuhyou::OnUpdate_All() " 
			"m_bUpdate_All_Requested=true" ) ;
		m_bUpdate_All_Requested = true ;
	}
	else
	{
		//	�S�X�V��K�v�Ƃ���ꍇ�ŁA
		//	���̃r���[���A�N�e�B�u�̏ꍇ�́A
		//	�S�X�V���s���܂��B
		CWaitCursor	aCWaitCursor ;


		// --------------------------------
		//	�Z�����X�V
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g���s�ɂ��Z���ړ��ŃZ���I���ɂȂ�Ȃ��悤�ɁA
		//	�Z���I���@�\���ꎞ�I�ɒ��~���܂��B
		{
			clearSelect() ;
			CPropStack aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		}


		//	�Z�����X�V
		ViewJikokuhyou::WndJikokuhyou::CCellBuilder	aCellBuilder(
			getCDiagramEditDoc()->getCDedRosenFileData() ,
			getCentDedRessyaCont() , 
			m_bDisplayTsuukaEkiJikoku ,
			m_bDisplayAllEkiJikoku );
		aCellBuilder.update( 
			this ) ;

		InvalidateGrid() ;

		m_bUpdate_All_Requested = false ;
	}
}
void CWndJikokuhyou::updateUISetAllRessya() 
{
	//	���̕ϐ��� true �̂Ƃ��́A
	//	�u�r���[���A�N�e�B�u�ȏ�Ԃł� OnUpdate_All() �v
	//	�܂ŁA������X�V����͍s���܂���B
	if ( m_bUpdate_All_Requested )
	{
		return ;
	}
	// --------------------------------
	//	�Z�����X�V
	// --------------------------------
	{
		//	�R�}���h�I�u�W�F�N�g���s�ɂ��Z���ړ��ŃZ���I���ɂȂ�Ȃ��悤�ɁA
		//	�Z���I�����������A�Z���I���@�\���ꎞ�I�ɒ��~���܂��B
		{
			clearSelect() ;
			CPropStack aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		}

		//	�Z�����X�V
		ViewJikokuhyou::WndJikokuhyou::CCellBuilder	aCellBuilder(
			getCDiagramEditDoc()->getCDedRosenFileData() ,
			getCentDedRessyaCont() , 
			m_bDisplayTsuukaEkiJikoku ,
			m_bDisplayAllEkiJikoku );
		aCellBuilder.updateAllRessya(
			this ) ;
	}
}

void CWndJikokuhyou::updateUI_ReplaceRessya( 
		int iDstRessyaIndex , 
		int iDstDelCount , 
		int iInsertCount ) 

{
	//	���̕ϐ��� true �̂Ƃ��́A
	//	�u�r���[���A�N�e�B�u�ȏ�Ԃł� OnUpdate_All() �v
	//	�܂ŁA������X�V����͍s���܂���B
	if ( m_bUpdate_All_Requested )
	{
		return ;
	}
	// --------------------------------
	//	�Z�����X�V
	// --------------------------------
	{
		//	��̑����𔺂��R�}���h�����s����ꍇ�́A
		//	�R�}���h�I�u�W�F�N�g���s�ɂ��Z���ړ��ŃZ���I���ɂȂ�Ȃ��悤�ɁA
		//	�Z���I�����������A�Z���I���@�\���ꎞ�I�ɒ��~���܂��B
		if ( iDstDelCount != iInsertCount )
		{
			clearSelect() ;
			CPropStack aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		}

		//	�Z�����X�V
		ViewJikokuhyou::WndJikokuhyou::CCellBuilder	aCellBuilder(
			getCDiagramEditDoc()->getCDedRosenFileData() ,
			getCentDedRessyaCont() , 
			m_bDisplayTsuukaEkiJikoku ,
			m_bDisplayAllEkiJikoku );
		aCellBuilder.replaceRessya(
			iDstRessyaIndex , 
			iDstDelCount , 
			iInsertCount , 
			this ) ;
	}
}



	// --------------------------------
	//@name CWndJikokuhyou-MFC�R�}���h�n���h�������֐�
	// --------------------------------
int CWndJikokuhyou::OnFileExportJikokuhyoucsv_Process( 
	BOOL bQueryEnable )  
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		CJikokuhyouDoc* pCJikokuhyouDoc = (CJikokuhyouDoc*)GetDocument() ;

		const CDedRosenFileData* pCDedRosenFileData = 
			getCDiagramEditDoc()->getCDedRosenFileData() ;

		CDlgOuJikokuhyouCsvExport	aDlg( 
			pCDedRosenFileData->getCentDedRosen() , 
			pCJikokuhyouDoc->getDiaIndex() , 
			pCJikokuhyouDoc->getRessyahoukou() , 
			this ) ;
		aDlg.DoModal() ;
	
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnFileImportJikokuhyoucsv_Process( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	CString	strError ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	const Mu<const CentDedRessya*>* pCentDedRessyaCont 
		= getCentDedRessyaCont()->getMuPtr() ;
	CDcdGridCell*	pCDcdGridCell = NULL ;
	if ( iRv >= 0 ){
		 pCDcdGridCell = getCFocus()->getFocusCell() ;
		if ( pCDcdGridCell == NULL ){
			iRv = -1  ;	//	�Z���̏ꏊ���s��
		}
	}
	//pCDcdGridCell = �ҏW���̃Z��
	int iRessyaIdx = -1 ;
	if ( iRv >= 0 ){
		iRessyaIdx = getXColSpecOfFocus().getRessyaIndex() ;
		if ( !( 0 <= iRessyaIdx && iRessyaIdx < pCentDedRessyaCont->size() ) ){
			//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
			//	�G���[�ɂ͂��܂���B
			iRessyaIdx = pCentDedRessyaCont->size() ;
		}
	}
	//iRessyaIdx = ���Index
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		CentDedRosen aCentDedRosen = *getCDiagramEditDoc()
			->getCDedRosenFileData()->getCentDedRosen() ;

		// --------------------------------
		//	���̓t�@�C�������͒l�̎擾
		// --------------------------------
		CString strCsvFilename ;
		if ( iRv >= 0 )
		{
			CFileDialog aDlg( 
				TRUE , 
				_T( "csv" ) , 
				NULL , 
				OFN_HIDEREADONLY , 
				getCDiagramEditApp()->getCFileDialogFilterCsv(), 
				this );
			if ( aDlg.DoModal() != IDOK )
			{
				iRv = -2 ;	//	Cancel����܂����B
			}
			else
			{
				strCsvFilename = aDlg.GetPathName() ;
			}
		}
		//strCsvFilename = �w�肳�ꂽCSV�t�@�C����
		// --------------------------------
		//	CSV�t�@�C���̓ǂݏo��
		// --------------------------------
		CWaitCursor aCursor ;
		CdCsvDocument aCdCsvDocument ;
		if ( iRv >= 0 )
		{
			string strCsvDocument ;
			int iResult = stringFromFile( 
				&strCsvDocument , 
				(LPCSTR)strCsvFilename ) ; 
			if ( iResult < 0 )
			{
				strError.Format( IDS_ERR_FILENOTFOUND , 
					(LPCTSTR)strCsvFilename ) ;
				iRv = -11 ;	//	�t�@�C����������܂���B
			}
			else
			{
				CConvCsvDocument	aConv ;
				int iResult = aConv.decode( &aCdCsvDocument , strCsvDocument ) ;
				if ( iResult < 0 )
				{
					strError.Format( IDS_ERR_FILEFORMAT , 
						(LPCTSTR)strCsvFilename ) ;
					iRv = -12 ;	//	CSV�̉��߂Ɏ��s���܂����B
				}
			}

		}

		if ( iRv >= 0 )
		{
			int iDiaIndex = GetDocument()->getDiaIndex() ;
			ERessyahoukou eRessyahoukou = GetDocument()->getRessyahoukou() ;
			string strErrorInfoString ;		
			CconvJikokuhyouCsv	aConv( 
				getCDiagramEditApp()->createCconvJikokuhyouCsv() ) ;
			int iResult = aConv.decode(
				&aCentDedRosen ,
				iDiaIndex , 
				eRessyahoukou , 
				iRessyaIdx , 
				aCdCsvDocument , 
				&strErrorInfoString ) ;
			//iResult = 
			//	-1 ; // �s�����Ȃ����܂��B
			//	-2 ; // �񂪏��Ȃ����܂��B
			//	-3 ; // �t�@�C���`�����F���ł��܂���
			//	-4 ; // �t�@�C���`�����F���ł��܂���
			//	-11 ; // �w����������܂���B
			//	-21 ; // iDiaIndex ���s���ł��B
			//	-22 ; // iRessyaIndex ���s���ł��B 
			if ( iResult < 0 )
			{
				strError.Format( IDS_ERR_FILEFORMAT , 
					(LPCTSTR)strCsvFilename , iResult ) ;
				strError += _T( "\n" ) ;
				strError += _T( "(" ) ;
				strError += strErrorInfoString.c_str()  ;
				strError += _T( ")" ) ;
				iRv = iResult - 100 ;
				//	-101 ; // �s�����Ȃ����܂��B
				//	-102 ; // �񂪏��Ȃ����܂��B
				//	-103 ; // �t�@�C���`�����F���ł��܂���
				//	-104 ; // �t�@�C���`�����F���ł��܂���
				//	-111 ; // �w����������܂���B
				//	-121 ; // iDiaIndex ���s���ł��B
				//	-122 ; // iRessyaIndex ���s���ł��B 
			}
		}
		//	�ҏW�R�}���h�����s
		if ( iRv >= 0 )
		{
			Ou<CRfEditCmd> pCmd 
				= OuNew<CRfEditCmd_Rosen>( 
					new CRfEditCmd_Rosen( aCentDedRosen ) );
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}	
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		if ( iRv < 0 )
		{
			if ( !strError.IsEmpty() )
			{
				MessageBox( strError , NULL , MB_ICONSTOP ) ;
			}
		}
		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnJikokuhyouViewProp_Process( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		CDlgJikokuhyouViewProp aDlg( 
			m_jikanPasteIdouryou , 
			m_eEkijikokuSort ,
			this ) ;
		if ( aDlg.DoModal() == IDOK )
		{
			m_jikanPasteIdouryou = aDlg.getPasteIdouryou() ;
			m_jikanPasteIdouryouPrevValue = 0 ;
			m_eEkijikokuSort = aDlg.getEkijikokuSort() ;

			//	EkijikokuSort �̐ݒ���A
			//	.ini �t�@�C���ɕۑ�
			getCDiagramEditApp()->writeCWndJikokuhyouViewProp( this ) ;

			iRv = 1 ;	//	�_�C�A���O�{�b�N�X�ł̓��͂��K�p����܂����B
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnJikokuhyouDiagramHeIdou_Process( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	const Mu<const CentDedRessya*>* pCentDedRessyaCont = getCentDedRessyaCont()->getMuPtr() ;

	CDcdGridCell*	pCDcdGridCell = NULL ;
	if ( iRv >= 0 ){
		 pCDcdGridCell = getCFocus()->getFocusCell() ;
		if ( pCDcdGridCell == NULL ){
			iRv = -11  ;	//	�Z���̏ꏊ���s��
		}
	}
	//pCDcdGridCell = �ҏW���̃Z��
	
	int iRessyaIdx = -1 ;
	const CentDedRessya* pCentDedRessya = NULL ;
	if ( iRv >= 0 ){
		iRessyaIdx = getXColSpecOfFocus().getRessyaIndex() ;

		if ( !( 0 <= iRessyaIdx && iRessyaIdx < pCentDedRessyaCont->size() ) ){
			//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
			//	�G���[�ɂ͂��܂���B
		}	else	{
			pCentDedRessya = pCentDedRessyaCont->get( iRessyaIdx ) ;
		}
	}
	//iRessyaIdx = ���Index
	//pCentDedRessya = �w��̃Z���ɑΉ�����w��ԁx
	//	�Ή������Ԃ��Ȃ��ꍇ��NULL
	
	CdDedJikokuOrder aJikokuOrder;
	if ( iRv >= 0 )
	{
		aJikokuOrder = CdDedJikokuOrderOf( getYColSpecOfFocus() ) ;
	}
	//aJikokuOrder = �w��̃Z���ɑΉ�����w����Order�x
	//	�Ȃ��Ȃ�NULL

	CdDedJikoku	jikokuFocus ;
	if ( iRv >= 0 ){
		if ( pCentDedRessya != NULL ){
			jikokuFocus = pCentDedRessya->getEkiJikoku( aJikokuOrder ) ;
		}
	}
	//jikokuFocus = �t�H�[�J�X�̂���Z���̎����B�Ȃ��Ȃ�NULL

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�_�C���O�����r���[���J��
		// --------------------------------
		CDedDiagramView* pCDedDiagramView = NULL ;
		if ( iRv >= 0 ){
			
			const CDedDiagramDoc* pCDedDiagramDoc = NULL ;
			if ( iRv >= 0 ){
				pCDedDiagramDoc = 
					getCDiagramEditApp()->openCDedDiagramDoc( 
						getCentDedDia()  ) ; 
				if ( pCDedDiagramDoc == NULL ){
					iRv = -2 ;	//	�_�C���O�����r���[�̃I�[�v���Ɏ��s���܂���
				}
			}
			//pCJikokuhyouDoc = �_�C���O�����h�L�������g
			//	�r���[���A�N�e�B�u�ɂȂ��Ă��܂��B
			
			if ( iRv >= 0 ){
				POSITION aPOSITION = pCDedDiagramDoc->GetFirstViewPosition() ;
				if ( aPOSITION != NULL ){
					pCDedDiagramView = (CDedDiagramView*)pCDedDiagramDoc->GetNextView( aPOSITION ) ;
				}
				if ( pCDedDiagramView == NULL ){
					iRv = -3 ;	//	�_�C���O�����r���[�̃I�[�v���Ɏ��s���܂���
				}
			}
		}
		//pCDedDiagramView = �_�C���O�����r���[
		if ( iRv >= 0 ){
			pCDedDiagramView->setZone_Dgr( jikokuFocus , 
				getCentDedRessyaCont()->EkiIndexOfEkiOrder( aJikokuOrder.getEkiOrder() ) , 
				getRessyahoukou() == Ressyahoukou_Nobori ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnVIEWDisplayTsuukaEkiJikoku_Process( 
	BOOL bQueryEnable )  
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( getDisplayTsuukaEkiJikoku() )
	{
		iRv = 1 ;	//(bQueryEnable==TRUE�̏ꍇ)[�S������\��]���L���ł��B
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		setDisplayTsuukaEkiJikoku( !getDisplayTsuukaEkiJikoku() ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWndJikokuhyou::OnViewDisplayallekijikoku_Process( 
	BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( getDisplayAllEkiJikoku() )
	{
		iRv = 1 ;	//	(bQueryEnable==TRUE�̏ꍇ)[�S������\��]���L���ł��B
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		const CentDedRosen*	pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		// --------------------------------
		//	Grid�̔z�u��ύX����O�́A
		//	�t�H�[�J�X�Z���̕\�����e���擾
		// --------------------------------
		CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;
		int iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell(
			pCDcdGridCell) ;
		int iXColumnNumber = getCXDcdGrid()->getXColumnNumberOfCell(
			pCDcdGridCell) ;

		CdYColSpecCont aYColumnSpecCont 
			= createYColSpecCont() ;

		CdYColSpec aYColumnSpec = 
			aYColumnSpecCont.ColumnNumberToSpec( iYColumnNumber ) ;
		//aYColumnSpec = �t�H�[�J�X�Z���̕\�����e�B

		// --------------------------------
		//	�S�����\�����[�h�̕ύX
		// --------------------------------
		setDisplayAllEkiJikoku( !getDisplayAllEkiJikoku() ) ;
		// --------------------------------
		//	�t�H�[�J�X�Z�����AGrid�z�u�ύX�O�Ɠ����\�����e�̈ʒu�Ɉړ�
		// --------------------------------
		//	Grid�z�u���ς�������߁A�w��ԍ�-�\�����e�x�̑Ή��\���č쐬���܂��B
		aYColumnSpecCont = createYColSpecCont() ;

		//	Grid�z�u�O�̃t�H�[�J�X�Z���̕\�����e�ɑΉ�����
		//	Y��ԍ����擾
		iYColumnNumber = aYColumnSpecCont.ColumnNumberFromSpec(
			aYColumnSpec , true ) ;

		pCDcdGridCell = getCXDcdGrid()->getCell( 
			iXColumnNumber , iYColumnNumber ) ;
		getCFocus()->setFocusCell( pCDcdGridCell ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

CString CWndJikokuhyou::OnUpdateINDICATOR_PasteZoubun_Process() 
{
	CString	strLs ;
	if ( m_StateMachine.getCurrentStateIdx() == StateIdx_Renzoku  )
	{
		//	�A�����̓��[�h
		strLs.LoadString( IDS_INDICATOR_Renzoku ) ;
	}
	else
	{
		//	���̑�
		strLs.Format( ID_INDICATOR_PasteZoubun , 
			m_jikanPasteIdouryou.getTotalSeconds() / 60 , 
			( m_jikanPasteIdouryouPrevValue.getTotalSeconds() + 
				m_jikanPasteIdouryou.getTotalSeconds() ) / 60 ) ;
	}
	return strLs ;
}



// --------------------------------
//@name �����֐�
// --------------------------------


// ********************************
//@name	CDcdGrid
// ********************************

	// --------------------------------
	//@name �s�E��E�Z���̏�����
	// --------------------------------
void CWndJikokuhyou::OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	pCDcdGridXColumn->getCDcdGridXBorder()->setAutoColumnBorderSize( false ) ;
	pCDcdGridXColumn->setAutoColumnSize( false ) ;

	super::OnCreateXColumn( iXColumnNumber , 
		pCDcdGridXColumn ) ;
}

	
void CWndJikokuhyou::OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
	pCDcdGridYColumn->getCDcdGridYBorder()->setAutoColumnBorderSize( false ) ;
	pCDcdGridYColumn->setAutoColumnSize( false ) ;

	super::OnCreateYColumn( iYColumnNumber , 
			pCDcdGridYColumn ) ;
}

	
// ********************************
//@name	CWndDcdGrid
// ********************************
	// --------------------------------
	//@name	�C�x���g�����̂��߂̉��z�֐�
	// --------------------------------
void CWndJikokuhyou::OnSetFocusCell( CDcdGridCell* pCDcdGridCell ) 
{
	m_StateMachine.getCurrentState()->
		OnSetFocusCell( pCDcdGridCell ) ;

	//	super::OnSetFocusCell( pCDcdGridCell ) ;
}

void CWndJikokuhyou::OnSetXFixafterColumnNumber( int iFixafterColumnNumber ) 
{
	m_StateMachine.getCurrentState()->
		OnSetXFixafterColumnNumber( iFixafterColumnNumber ) ;
	//	super::OnSetXFixafterColumnNumber( iFixafterColumnNumber ) ;
}

void CWndJikokuhyou::OnSetYFixafterColumnNumber( int iFixafterColumnNumber ) 
{
	m_StateMachine.getCurrentState()->
		OnSetYFixafterColumnNumber( iFixafterColumnNumber ) ;
	//	super::OnSetYFixafterColumnNumber( iFixafterColumnNumber ) ;
}

void CWndJikokuhyou::OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) 
{
	m_StateMachine.getCurrentState()->
		OnChangeSelectCell( iXColumnNumber , iYColumnNumber , bIsSelected ) ;
}


// ********************************
//	�R���X�g���N�^
// ********************************
CWndJikokuhyou::CWndJikokuhyou()
	: m_jikanPasteIdouryou( 0 )
	, m_bDisplayTsuukaEkiJikoku( true )
	, m_bDisplayAllEkiJikoku( false ) 
	, m_eEkijikokuSort( EEkijikokuSort_Ekiatsukai )	// �w���ł̃\�[�g
	, m_bModifyEkijikoku( true )
	, m_jikanPasteIdouryouPrevValue( 0 )
	, m_bUpdate_All_Requested( true )
	, m_bReadCWndJikokuhyouDefault( false ) 
{
	//	�I���e�L�X�g�J���[��ݒ�
	{
		Ou<CDcdFillrectRop>	pIfDcDraw = dynamic_castOu<CDcdFillrectRop>(
			getCSelect()->getIfDcDrawSelect() ) ;

		//	�I���e�L�X�g�J���[=��
		pIfDcDraw->setCdBrushProp( CdColorProp( 0 , 0 , 0 ) ) ;
	}
}
CWndJikokuhyou::~CWndJikokuhyou()
{
}


// ********************************
//@name	CWndJikokuhyou
// ********************************
	// ********************************
	//@name CWndJikokuhyou-����
	// ********************************
bool CWndJikokuhyou::getDisplayTsuukaEkiJikoku()const 
{
	return m_bDisplayTsuukaEkiJikoku ;
}
int CWndJikokuhyou::setDisplayTsuukaEkiJikoku( bool value ) 
{
	int iRv = 0 ;
	if ( m_bDisplayTsuukaEkiJikoku != value )
	{
		m_bDisplayTsuukaEkiJikoku = value ;

		//	�ʉߗ�Ԃ̕\���̗L�����ω������ꍇ�́A
		//	�r���[�̉w�������X�V���܂��B
		updateUISetAllRessya() ;
		InvalidateGrid() ;

		//	�ʉߗ�Ԃ̕\���̗L�����A
		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndJikokuhyouViewProp( this ) ;
	}
	return ( iRv ) ;
}

bool CWndJikokuhyou::getDisplayAllEkiJikoku()const
{	return m_bDisplayAllEkiJikoku ;};

int CWndJikokuhyou::setDisplayAllEkiJikoku( bool value )
{
	int iRv = 0 ;
	if ( m_bDisplayAllEkiJikoku != value )
	{
		m_bDisplayAllEkiJikoku = value ;

		//	�O���b�h�̗񐔂��ς��܂��̂ŁA
		//	�r���[�̑S�X�V���K�v�ł��B
		//	�������A���̃r���[���X�V���� �K�v�͂���܂���B
		updateUIAll() ;

		//	�\���ݒ�� .ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndJikokuhyouViewProp( this ) ;
	}
	return ( iRv ) ;
}


void CWndJikokuhyou::setModifyEkijikoku( bool value )
{
	if ( m_bModifyEkijikoku != value )
	{
		m_bModifyEkijikoku = value ;
	
		//	�\���ݒ�� .ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndJikokuhyouViewProp( this ) ;
	}
};

	// ********************************
	//@name CDiagramView ����̈Ϗ�
	// ********************************
void CWndJikokuhyou::OnUpdate(
	CView* pSender, LPARAM lHint, CObject* pHint)
{
	if ( !m_bReadCWndJikokuhyouDefault )
	{
		// --------------------------------
		//	.ini �t�@�C������A��Ԃ�ǂݍ���
		// --------------------------------
		getCDiagramEditApp()->readCWndJikokuhyouViewProp( this ) ;
		
		m_bReadCWndJikokuhyouDefault = true ;
	}

	//	�X�V�́ACWjkState �I�u�W�F�N�g�ōs���܂��B
	{
		m_StateMachine.getCurrentState()->
			OnUpdate( pSender, lHint, pHint) ;
		//memo:
		//	�u�S�X�V�v�� AND ���̃r���[����A�N�e�B�u�r���[�v�̏ꍇ�ł��A
		//	�X�V���s���K�v������܂��B
		//	�S�X�V�v���̏ꍇ�́A��ԑI�����[�h�E�A�����̓��[�h��
		//	�ޏꂷ��K�v�����邽�߂ł��B
	}


}

void CWndJikokuhyou::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	LogMsg( "CWndJikokuhyou::OnActivateView(%d,,)" , bActivate ) ;
	
	if ( bActivate && m_bUpdate_All_Requested ){
		//	updateUI... �֐����Ăяo���O�ɁA���̕ϐ��� false ��
		//	���Ȃ��Ă͂Ȃ�܂���B
		//	���̕ϐ��� true ���ƁAOnUpdate �̉����֐��͉���������
		//	return ���܂��B
		m_bUpdate_All_Requested = false ;

		updateUIAll() ;
	}
}

	// ********************************
	//@name static CWndJikokuhyou-����
	// ********************************
CdDedJikokuOrder 
CWndJikokuhyou::CdDedJikokuOrderOf( 
		const CdYColSpec& aYColSpec ) 
{
	CdDedJikokuOrder	aJikokuOrder ;
	if ( aYColSpec.getColumnType() 
		== CdYColSpec::ColumnType_Ekijikoku_Chaku )
	{
		aJikokuOrder.setEkiOrder( aYColSpec.getEkiOrder() , 
			CdDedJikokuOrder::EkiJikokuItem_Chaku ) ;
	}
	else if ( aYColSpec.getColumnType() 
		== CdYColSpec::ColumnType_Ekijikoku_Hatsu )
	{
		aJikokuOrder.setEkiOrder( aYColSpec.getEkiOrder() , 
			CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ;
	}
	return aJikokuOrder ;
}
CdYColSpec 
CWndJikokuhyou::CdYColSpecOf( 
		const CdDedJikokuOrder& aJikokuOrder ) 
{
	CdYColSpec aYColSpec ;
	if ( aJikokuOrder.getEkiJikokuItem() 
		== CdDedJikokuOrder::EkiJikokuItem_Chaku )
	{
		aYColSpec.set( CdYColSpec::ColumnType_Ekijikoku_Chaku ,
			aJikokuOrder.getEkiOrder() ) ;
	}
	else if ( aJikokuOrder.getEkiJikokuItem() 
		== CdDedJikokuOrder::EkiJikokuItem_Hatsu )
	{
		aYColSpec.set( CdYColSpec::ColumnType_Ekijikoku_Hatsu ,
			aJikokuOrder.getEkiOrder() ) ;
	}
	return aYColSpec ;
}


	// ********************************
	//@name CWndJikokuhyou-����
	// ********************************

CdXColSpecCont 
CWndJikokuhyou::createXColSpecCont() 
{
	CdXColSpecCont aXColumnSpecCont ;
	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	if ( pCentDedRessyaCont != NULL )
	{
		aXColumnSpecCont.scan( pCentDedRessyaCont ) ;
	}
	return aXColumnSpecCont ;
}

CdYColSpecCont 
CWndJikokuhyou::createYColSpecCont() 
{
	const CentDedRosen*	pCentDedRosen = 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;

	CdYColSpecCont aYColumnSpecCont ;

	aYColumnSpecCont.scan(
		pCentDedRosen->getCentDedEkiCont() ,
		getRessyahoukou() ,
		m_bDisplayAllEkiJikoku ) ;
	return aYColumnSpecCont ;
}

CdXColSpec 
CWndJikokuhyou::getXColSpecOfFocus() 
{
	CdXColSpec aXColSpec ;

	CdXColSpecCont aXColSpecCont 
				= createXColSpecCont() ;
	CdDcdPosXy	posFocusCell = getCFocus()->getFocusCellColumnNumber() ;
	aXColSpec = aXColSpecCont.ColumnNumberToSpec( posFocusCell.getX() ) ;

	return aXColSpec ;
}
CdYColSpec 
CWndJikokuhyou::getYColSpecOfFocus() 
{
	CdYColSpec aYColSpec ;

	CdYColSpecCont aYColSpecCont 
				= createYColSpecCont() ;
	CdDcdPosXy	posFocusCell = getCFocus()->getFocusCellColumnNumber() ;
	aYColSpec = aYColSpecCont.ColumnNumberToSpec( posFocusCell.getY() ) ;

	return aYColSpec ;
}


int CWndJikokuhyou::
	moveFocusCellToNext( bool bJikokuhyouFocusToRight , bool bNextEkiOrder ) 
{
	int iRv = 0 ;
	CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;

	CdXColSpecCont	aXColSpecCont
		= createXColSpecCont() ;

	//	�t�H�[�J�X���㉺�Ɉړ�
	if ( !bJikokuhyouFocusToRight )
	{
		//	�Z���ړ����ɁA��ԑI�����ϓ����Ȃ��悤�ɂ��܂��B
		CPropStack aPropStack( this ) ;
		aPropStack.CBoxSelect_setIsEnable( false ).CRandomSelect_setIsEnable( false ) ;

		//	�ړ���̃Z���ʒu�����߂�
		CdYColSpecCont aYColSpecCont = createYColSpecCont() ;

		int iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell(pCDcdGridCell) ;
		int iXColumnNumber = getCXDcdGrid()->getXColumnNumberOfCell(pCDcdGridCell) ;
		if ( 0 <= iYColumnNumber && 
				iYColumnNumber < 
				aYColSpecCont.getColumnNumber_Ekijikoku_begin() )
		{
			//iYColumnNumber = ��Ԕԍ��`�����܂ł̊ԁi�w�����̏�j
			//	�ɂ���܂��B
			//	���̏ꍇ�́A��ԏ�̉w�����Ɉړ����܂��B
			iYColumnNumber = 
				aYColSpecCont.getColumnNumber_Ekijikoku_begin() ;
		}
		else if ( 
			aYColSpecCont.getColumnNumber_Ekijikoku_begin() <= 
				iYColumnNumber && 
			iYColumnNumber < 
				aYColSpecCont.getColumnNumber_Ekijikoku_end() )
		{
			//iYColumnNumber = �w�����̈ʒu�ɂ���܂��B
			if ( bNextEkiOrder && 
				aXColSpecCont.getColumnNumber_Ressya_begin() <= iXColumnNumber	)
			{
				//	bNextEkiOrder ���^�ŁA�t�H�[�J�X�������ԏ�ɂ���ꍇ	
				CdDedJikokuOrder	aJikokuOrder = CdDedJikokuOrderOf( 
					aYColSpecCont.ColumnNumberToSpec( iYColumnNumber ) ) ;
				if ( !aJikokuOrder.getIsNull() )
				{
					//iYColumnNumber = �w�����̈ʒu�ɂ���܂��B
					//	���̉w�̒������̗�ԍ�
					iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
						CdYColSpec(
							CdYColSpec::ColumnType_Ekijikoku_Chaku ,
							aJikokuOrder.getEkiOrder() + 1  ) , false ) ;
					//iYColumnNumber=���̉w�̒������̗�ԍ�
					if ( iYColumnNumber < 0 )
					{
						iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
						CdYColSpec(
							CdYColSpec::ColumnType_Ekijikoku_Hatsu ,
							aJikokuOrder.getEkiOrder() + 1  ) , false ) ;
					}
					if ( iYColumnNumber < 0 )
					{
						//	��ԉ��̉w��������̈ړ��ł��B
						//	�w�����̎��Ɉړ����܂����B
						iYColumnNumber = aYColSpecCont.getColumnNumber_Ekijikoku_end() ;
					}

				}
			}
			else
			{
				//	bNextEkiOrder ���U�̏ꍇ�A
				//	�t�H�[�J�X�������ԏ�ɂ���ꍇ	

				//�t�H�[�J�X�Z�������ֈړ�
				CDcdGridCell*	pCell = 
					getCXDcdGrid()->calcMovedCell( 
						pCDcdGridCell , 
						0 , 
						1 ) ;
				if ( pCell != NULL )
				{
					iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ;
				}
			}
		}
		else if ( aYColSpecCont.getColumnNumber_Ekijikoku_end() <= 
					iYColumnNumber )
		{
			//iYColumnNumber = �w�����̌�(���l��)�ɂ���܂��B
			//	���̏ꍇ�́A���̗�(���̗��)�̍ŏ�s�Ɉړ����܂��B	
			iYColumnNumber = 0 ;
			if ( 0 <= iXColumnNumber && 
				iXColumnNumber < aXColSpecCont.getColumnNumber_Ressya_begin() )
			{
				iXColumnNumber = aXColSpecCont.getColumnNumber_Ressya_begin() ;
			}
			else
			{
				iXColumnNumber ++ ;
			}

		}

		//iYColumnNumber = ���̉w�����̗�ԍ�
		//	(-1�̏ꍇ������܂��B(�H���̏I���w�̉w�������͂��I������))
		if ( iYColumnNumber >= 0 )
		{
			CDcdGridCell*	pCell = 
				getCXDcdGrid()->getCell( 
					iXColumnNumber , 
					iYColumnNumber ) ;
			if ( pCell )
			{
				getCFocus()->setFocusCell( pCell ) ;
			}
		}
	}
	//	�t�H�[�J�X���ړ����[�h
	else
	{
		CDcdGridCell*	pCell = 
			getCXDcdGrid()->calcMovedCell( 
				getCFocus()->getFocusCell() , 
				+1 , 
				0 ) ;
		if ( pCell ){
			getCFocus()->setFocusCell( pCell ) ;
		}

		//	�t�H�[�J�X���ړ����[�h�ł́A�I�����������܂��B
		clearSelect() ;

	}


	return ( iRv ) ;
}

int CWndJikokuhyou::
	moveFocusCellToPrev( bool bJikokuhyouFocusToRight , bool bNextEkiOrder ) 
{
	int iRv = 0 ;
	CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;

	CdXColSpecCont	aXColSpecCont
		= createXColSpecCont() ;
	CdYColSpecCont	aYColSpecCont
		= createYColSpecCont() ;

	//	�t�H�[�J�X���㉺�Ɉړ�
	if ( !bJikokuhyouFocusToRight )
	{
		//	�Z���ړ����ɁA��ԑI�����ϓ����Ȃ��悤�ɂ��܂��B
		CPropStack aPropStack( this ) ;
		aPropStack.CBoxSelect_setIsEnable( false ).CRandomSelect_setIsEnable( false ) ;


		//	�ړ���̃Z���ʒu�����߂�
		int iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell(pCDcdGridCell) ;
		int iXColumnNumber = getCXDcdGrid()->getXColumnNumberOfCell(pCDcdGridCell) ;
		if ( 0 <= iYColumnNumber && 
			iYColumnNumber < 
			aYColSpecCont.getColumnNumber_Ekijikoku_begin() )
		{
			//iYColumnNumber = ��Ԕԍ��`�����܂ł̊ԁi�w�����̏�j
			//	�ɂ���܂��B
			//	���̏ꍇ�́A�O�̗�(���)�́A���l�� �Ɉړ����܂��B
			iYColumnNumber = aYColSpecCont.getColumnNumber_Ekijikoku_end()  ;

			iXColumnNumber -- ;

		}
		else if ( 
			aYColSpecCont.getColumnNumber_Ekijikoku_begin() <= 
				iYColumnNumber && 
			iYColumnNumber < 
				aYColSpecCont.getColumnNumber_Ekijikoku_end() )
		{
			//iYColumnNumber = �w�����̈ʒu�ɂ���܂��B
			if ( bNextEkiOrder &&
				aXColSpecCont.getColumnNumber_Ressya_begin() <= iXColumnNumber	)
			{
				//	bNextEkiOrder ���^�ŁA�t�H�[�J�X�������ԏ�ɂ���ꍇ	

				CdDedJikokuOrder aJikokuOrder = CdDedJikokuOrderOf(
					aYColSpecCont.ColumnNumberToSpec( iYColumnNumber ) )  ;

				if ( !aJikokuOrder.getIsNull() )
				{
					//iYColumnNumber = �w�����̈ʒu�ɂ���܂��B
					iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
						CdYColSpec( 
							CdYColSpec::ColumnType_Ekijikoku_Chaku ,
							aJikokuOrder.getEkiOrder() - 1  ) , false ) ;
					//iYColumnNumber = �O�̉w�̒��w
					if ( iYColumnNumber < 0 )
					{
						iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
							CdYColSpec( 
								CdYColSpec::ColumnType_Ekijikoku_Hatsu ,
								aJikokuOrder.getEkiOrder() - 1  ) , false ) ;
					}
					if ( iYColumnNumber < 0 )
					{
						//	�t�H�[�J�X���n���w�̉w�������O�ɂȂ�܂��B
						//	���̏ꍇ�́A��Ԕԍ��̈ʒu�Ɉړ����܂��B
						iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
							CdYColSpec(
							CdYColSpec::ColumnType_Ressyabangou )
							, false ) ;
					}
				}
			}
			else
			{
				CDcdGridCell*	pCell = 
					getCXDcdGrid()->calcMovedCell( 
						pCDcdGridCell , 
						0 , 
						-1 ) ;
				if ( pCell != NULL )
				{
					iYColumnNumber = getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ;
				}
			}
		}
		else if ( aYColSpecCont.getColumnNumber_Ekijikoku_end() <= iYColumnNumber )
		{
			//iYColumnNumber = �w�����̈ʒu��肠�Ƃɂ���܂��B
			//	�I���w�̍Ō�̉w�����Ɉړ����܂��B
			iYColumnNumber = aYColSpecCont.getColumnNumber_Ekijikoku_end() - 1 ;
		}

		//iYColumnNumber = ���̉w�����̗�ԍ�
		//	(-1�̏ꍇ������܂��B(�H���̏I���w�̉w�������͂��I������))
		if ( iYColumnNumber >= 0 )
		{
			CDcdGridCell*	pCell = 
				getCXDcdGrid()->getCell( 
					iXColumnNumber , 
					iYColumnNumber ) ;
			if ( pCell )
			{
				getCFocus()->setFocusCell( pCell ) ;
			}
		}
	}
	//	�t�H�[�J�X���ړ����[�h
	else
	{
		CDcdGridCell*	pCell = 
			getCXDcdGrid()->calcMovedCell( 
				getCFocus()->getFocusCell() , 
				-1 , 
				0 ) ;
		if ( pCell )
		{
			getCFocus()->setFocusCell( pCell ) ;
		}

		//	�t�H�[�J�X���ړ����[�h�ł́A�I�����������܂��B
		clearSelect() ;

	}


	return ( iRv ) ;
}


int CWndJikokuhyou::execCdModifyEkijikokuCmd(
		Ou<EditCmd::CRfEditCmd_Ressya> pCmd , 
		CdDedJikokuOrder aCdJikokuOrder ) 
{
	int iRv = 0 ;
	CString	strError ;
	// --------------------------------
	int idxError = -1 ;

	// --------------------------------
	//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
	// --------------------------------
	if ( iRv >= 0 )
	{
		for ( int idxRessya = 0 ; 
			iRv >= 0 && idxRessya < pCmd->getCaMuiSelect()->size() ; 
			idxRessya ++ )
		{
			CentDedRessya*	pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( idxRessya ) ; 
			//pCentDedRessya = pCmd ���̗�ԃI�u�W�F�N�g���w���܂��B

			int iResult = m_EkijikokuModifyOperation2.execute( 
				pCentDedRessya , 
				aCdJikokuOrder ) ;
			//	-	-1 ;	//	iJikokuOrder ���͈͊O�ł��B
			if ( iResult < 0 )
			{
				switch ( iResult ){
				case -1 :	
					iRv = -1 ;	//	X��ԍ����s���ł��B
					break ;
				default :	
					iRv = iResult ;
					break ;
				}
				idxError = idxRessya ;
			}
		}
	}
	//idxError = �G���[�����������ꍇ�́A
	//	�G���[�̔���������Ԃ� aCentDedRessyaCont ���ł�Index�ł��B

	// --------------------------------
	//	�R�}���h�I�u�W�F�N�g�����s
	// --------------------------------
	if ( iRv >= 0 )
	{
		getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
	}
	// --------------------------------
	//	�G���[�\��
	// --------------------------------
	if ( iRv < 0 )
	{
		//	�t�H�[�J�X�Z�����G���[�̔���������Ԃֈڂ��܂��B
		{
			CdDcdPosXy	posFocusCell = getCFocus()->getFocusCellColumnNumber() ;

			CdXColSpecCont aXColSpecCont 
				= createXColSpecCont() ;
			posFocusCell.setX( aXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Ressya ,
					pCmd->getIndexDst() + pCmd->getCaMuiSelect()->indexFromAdapteeIndex( idxError ) )
			) );
			
			getCFocus()->setFocusCellColumnNumber( posFocusCell ) ;
		}

		// --------------------------------
		if ( strError.IsEmpty() )
		{
			strError.Format( IDS_ERR_ERRORCODE , iRv ) ;
		}
		MessageBox( strError , NULL , MB_ICONEXCLAMATION | MB_OK ) ; 
	}
	return ( iRv ) ;

}



bool CWndJikokuhyou::createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>* ppCmd )
{
	bool bRv = false ;
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya> pCmd ;

	CdXColSpecCont aCdXColSpecCont = createXColSpecCont() ;
	CdXColSpec  aCdXColSpecOfFocus = getXColSpecOfFocus() ;

	// ********************************
	//	ECreateCmd_NewTrain
	//�@�V�K��Ԃ�ΏۂƂ����R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_NewItem )
	{
		//	�����\�r���[��ŕ����I����OFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{
			//	�V�K�ɒǉ�������Ԃ́A�����I�u�W�F�N�g
			CentDedRessya aNewRessya = getCentDedRessyaCont()->createNullRessya() ;
			aNewRessya.setRessyasyubetsuIndex( 0 ) ;

			//�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z����������ԏ�ɂ���ꍇ: 
			// - m_iIndexDst = �t�H�[�J�X�Z���̗��Index�Am_iIndexSize = 0
			// - m_CentDedRessyaCont = ����(NULL�ł͂Ȃ�)
			// - CaMuSelect,CaMuiSelect = ���Y��Ԃ�I���B
			if ( aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_Ressya )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
						new CRfEditCmd_Ressya( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							GetDocument()->getDiaIndex() , 
							GetDocument()->getRessyahoukou() ,
							aCdXColSpecOfFocus.getRessyaIndex() , 
							0 ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewRessya , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}
			// �@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���ꍇ:
			// - m_iIndexDst = �������Index+1�Am_iIndexSize = 0
			// - m_CentDedRessyaCont = ����(NULL�ł͂Ȃ�)
			// - CaMuSelect,CaMuiSelect = ���Y��Ԃ�I���B
			else if ( aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_NewRessya )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
						new CRfEditCmd_Ressya( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							GetDocument()->getDiaIndex() , 
							GetDocument()->getRessyahoukou() ,
							aCdXColSpecOfFocus.getRessyaIndex() , 
							0 ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewRessya , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}
		}
		// �@�����\�r���[��ŕ����I��ON:
		// NULL��Ԃ��܂�([14/05/18]��:�����I��OFF�̏ꍇ�Ɠ�������)
	}
	// ********************************
	//	ECreateCmd_Focus
	//�@�t�H�[�J�X�Z�����1��Ԃ�ΏۂƂ����R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_Focus )
	{
		//	�����\�r���[��ŕ����I����OFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{
			//�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z����������ԏ�ɂ���ꍇ: 
			// - m_iIndexDst = �t�H�[�J�X�Z���̗��Index�Am_iIndexSize = 1
			// - m_CentDedRessyaCont = �t�H�[�J�X�Z����̗��1�̃R�s�[
			// - m_CaMuiSelect = �t�H�[�J�X�Z����̗�Ԃ�I���B
			if ( aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_Ressya )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
						new CRfEditCmd_Ressya( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							GetDocument()->getDiaIndex() , 
							GetDocument()->getRessyahoukou() ,
							aCdXColSpecOfFocus.getRessyaIndex() , 
							1 ) ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			//�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���ꍇ: 
			// - NULL��Ԃ��܂��B
		}
		//�@�����\�r���[��ŕ����I��ON
		// NULL��Ԃ��܂�([14/05/18]��:�����I��OFF�̏ꍇ�Ɠ�������)
	}
	// ********************************
	//	ECreateCmd_Select
	//�@�����̒P���܂��͕����I������Ă����Ԃ�ΏۂƂ���
	//	�R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select )
	{
		//�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z����������ԏ�ɂ���ꍇ: 
		//
		// - m_iIndexDst = �t�H�[�J�X�Z���̗��Index�Am_iIndexSize = 1
		// - m_CentDedRessyaCont = �t�H�[�J�X�Z���̂�����1�̃R�s�[
		// - CaMuiSelect = ���Y��Ԃ�I���B
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_Ressya )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
					new CRfEditCmd_Ressya( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						GetDocument()->getDiaIndex() , 
						GetDocument()->getRessyahoukou() ,
						aCdXColSpecOfFocus.getRessyaIndex() , 
						1 ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		//�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���ꍇ: 
		// - NULL��Ԃ��܂��B

		//�@�����\�r���[��ŕ����I��ON
		// - m_iIndexDst = �I������Ă����Ԃ̐擪index
		// - m_iIndexSize = �I������Ă����Ԃ̖���index-�擪index+1
		// - m_CentDedRessyaCont = �I������Ă����Ԃ̐擪index����
		//  ����index�܂ł̗�Ԃ̃R�s�[
		// - CaMuiSelect �́A�t�H�[�J�X�Z���ɍ��킹�ė�Ԃ�I���B
		
		//(A)�̈ʒu�ŏ������܂��B
	}


	// ********************************
	//		ECreateCmd_All ,
	//�@�S��Ԃ�ΏۂƂ����R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_All )
	{

		//  �����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z������ԏ�ɂ���ꍇ: 
		//
		// - m_iIndexDst = 0�Am_iIndexSize = ��Ԃ̐�
		// - m_CentDedRessyaCont = �S��Ԃ̃R�s�[
		// - m_CaMuiSelect2 �́A�S��Ԃ�I���B
		//  �����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���ꍇ: 
		// 
		// - m_iIndexDst = 0�Am_iIndexSize = ��Ԃ̐�
		// - m_CentDedRessyaCont = �S��Ԃ̃R�s�[
		// - CaMuiSelect2 �́A�S��Ԃ�I���B
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& ( aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_Ressya 
			|| aCdXColSpecOfFocus.getColumnType() == CdXColSpec::ColumnType_NewRessya ) )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
					new CRfEditCmd_Ressya( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						GetDocument()->getDiaIndex() , 
						GetDocument()->getRessyahoukou() ,
						0 , 
						getCentDedRessyaCont()->size() ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		//�����\�r���[��ŕ����I��ON
		//
		// - m_iIndexDst = �I������Ă����Ԃ̐擪index
		// - m_iIndexSize = �I������Ă����Ԃ̖���index-�擪index+1
		// - m_CentDedRessyaCont = �I������Ă����Ԃ̐擪index����
		//	����index�܂ł̗�Ԃ̃R�s�[
		// - m_CaMuiSelect2 �́A�Z���̑I���ɍ��킹�ė�Ԃ�I���B

		//(A)�̈ʒu�ŏ������܂��B
	}

	// ********************************
	//	(A)ECreateCmd_Select�EECreateCmd_All ��
	//�@�����I������Ă����Ԃ�ΏۂƂ���
	//	�R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select 
		|| eCreateCmd == ECreateCmd_All )
	{
		if ( getCSelect()->getSelectedCellCount() > 0 )
		{
			//	�I������Ă����Ԃ̗��Index���擾
			deque<int> contiRessyaIndex ;
			for ( int iColumnNumber = 0 ; iColumnNumber < getCXDcdGrid()->getXColumnCount() ;iColumnNumber ++ )
			{
				if ( getCSelect()->getXColumnNumberSelected( iColumnNumber ) )
				{
					CdXColSpec aCdXColSpec = aCdXColSpecCont.ColumnNumberToSpec( iColumnNumber ) ;
					if ( aCdXColSpec.getColumnType() == CdXColSpec::ColumnType_Ressya )
					{
						contiRessyaIndex.push_back( aCdXColSpec.getRessyaIndex() ) ;
					}
				}
			}
			//contiRessyaIndex = ��̕����I�������{����Ă���ꍇ�́A
			//	�I������Ă�����Index���i�[����܂��B
			//	�����łȂ��ꍇ�́A��ł��B

			if ( contiRessyaIndex.size() > 1 )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					//	�R�}���h�I�u�W�F�N�g���ɁA�I������Ă����Ԃ̐擪���疖���܂ł�
					//	��Ԃ��i�[���܂�(�擪�E�����ȊO�ɂ́A�I������Ă��Ȃ���Ԃ�
					//	�܂܂�Ă���ꍇ������܂�)
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
						new CRfEditCmd_Ressya( 
							*getCDiagramEditDoc()->getCDedRosenFileData() ,
							GetDocument()->getDiaIndex() , 
							GetDocument()->getRessyahoukou() ,
							contiRessyaIndex.front() , 
							contiRessyaIndex.back() - contiRessyaIndex.front() + 1 ) ) ;

					//	�R�}���h�I�u�W�F�N�g��
					//	m_CentDedRessyaContSrc  ���̗�Ԃ�I�����܂��B
					pCmd->getCaMuiSelect()->setSelectAll( false ) ;
					for ( int i = 0 ; i < (int)contiRessyaIndex.size() ; i ++ )
					{
						pCmd->getCaMuiSelect()->setSelect( contiRessyaIndex[i] - contiRessyaIndex.front()  , true ) ;
					}
				}
			}
		}
	}
	// ================================
	if ( ppCmd != NULL && pCmd != NULL )
	{
		*ppCmd = pCmd ;
	}
	return bRv ;
}

bool CWndJikokuhyou::createCmd( int iRessyaIndex , int iRessyaCount , 
		Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>* ppCmd) 
{
	bool bRv = false ;
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya> pCmd ;
	int iRv = 0 ;

	//  --------------------------------
	//	�R�}���h�I�u�W�F�N�g�𐶐�
	//  --------------------------------
	if ( iRv >= 0 )
	{
		//	�R�}���h�I�u�W�F�N�g���ɁA�w�肳�ꂽ�͈͂�
		//	��Ԃ��i�[���܂�
		//	��Ԃ͑S�I���ƂȂ�܂��B
		bRv = true ;
		if ( ppCmd != NULL )
		{
			pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>( 
				new CRfEditCmd_Ressya( 
					*getCDiagramEditDoc()->getCDedRosenFileData() , 
					GetDocument()->getDiaIndex() , 
					GetDocument()->getRessyahoukou() ,
					iRessyaIndex , 
					iRessyaCount ) ) ;
		}
	}
	// ================================
	if ( ppCmd != NULL && pCmd != NULL )
	{
		*ppCmd = pCmd ;
	}
	return bRv ;
}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
BEGIN_MESSAGE_MAP(CWndJikokuhyou,CWndJikokuhyou::super)
	//{{AFX_MSG_MAP(CWndJikokuhyou)
	ON_WM_CREATE()
	ON_WM_KEYUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_Jikokuhyou_RessyaProp, OnJikokuhyouRessyaProp)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_RessyaProp, OnUpdateJikokuhyouRessyaProp)
	ON_COMMAND(ID_Jikokuhyou_RessyaInsert, OnJikokuhyouRessyaInsert)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_RessyaInsert, OnUpdateJikokuhyouRessyaInsert)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_Edit_PasteEkiJikoku, OnEditPasteEkiJikoku)
	ON_UPDATE_COMMAND_UI(ID_Edit_PasteEkiJikoku, OnUpdateEditPasteEkiJikoku)
	ON_COMMAND(ID_Jikokuhyou_Tsuuka, OnJikokuhyouTsuuka)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Tsuuka, OnUpdateJikokuhyouTsuuka)
	ON_COMMAND(ID_Jikokuhyou_Keiyunasi, OnJikokuhyouKeiyunasi)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Keiyunasi, OnUpdateJikokuhyouKeiyunasi)
	ON_COMMAND(ID_Jikokuhyou_Sihatsu, OnJikokuhyouSihatsu)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Sihatsu, OnUpdateJikokuhyouSihatsu)
	ON_COMMAND(ID_Jikokuhyou_Syuuchaku, OnJikokuhyouSyuuchaku)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Syuuchaku, OnUpdateJikokuhyouSyuuchaku)
	ON_COMMAND(ID_Jikokuhyou_Renzoku, OnJikokuhyouRenzoku)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Renzoku, OnUpdateJikokuhyouRenzoku)
	ON_COMMAND(ID_Jikokuhyou_ViewProp, OnJikokuhyouViewProp)
	ON_COMMAND(ID_Jikokuhyou_FocusMoveDown, OnJikokuhyouFocusMoveDown)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_FocusMoveDown, OnUpdateJikokuhyouFocusMoveDown)
	ON_COMMAND(ID_Jikokuhyou_FocusMoveRight, OnJikokuhyouFocusMoveRight)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_FocusMoveRight, OnUpdateJikokuhyouFocusMoveRight)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuProp, OnJikokuhyouEkijikokuProp)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuProp, OnUpdateJikokuhyouEkijikokuProp)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuInsert, OnJikokuhyouEkijikokuInsert)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuInsert, OnUpdateJikokuhyouEkijikokuInsert)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuErase, OnJikokuhyouEkijikokuErase)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuErase, OnUpdateJikokuhyouEkijikokuErase)
	ON_WM_CHAR()
	ON_COMMAND(ID_Jikokuhyou_ModifyEkijikokuCmd, OnJikokuhyouModifyEkijikokuCmd)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_ModifyEkijikokuCmd, OnUpdateJikokuhyouModifyEkijikokuCmd)
	ON_COMMAND(ID_Jikokuhyou_ModifyEkijikokuCmdRepeat, OnJikokuhyouModifyEkijikokuCmdRepeat)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_ModifyEkijikokuCmdRepeat, OnUpdateJikokuhyouModifyEkijikokuCmdRepeat)
	ON_COMMAND(ID_Jikokuhyou_JikokuSakujo, OnJikokuhyouJikokuSakujo)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_JikokuSakujo, OnUpdateJikokuhyouJikokuSakujo)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuDec, OnJikokuhyouEkijikokuDec)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuDec, OnUpdateJikokuhyouEkijikokuDec)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuNext, OnJikokuhyouEkijikokuNext)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuNext, OnUpdateJikokuhyouEkijikokuNext)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuInc, OnJikokuhyouEkijikokuInc)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuInc, OnUpdateJikokuhyouEkijikokuInc)
	ON_COMMAND(ID_Jikokuhyou_EKikanSaisyouSec, OnJikokuhyouEKikanSaisyouSec)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EKikanSaisyouSec, OnUpdateJikokuhyouEKikanSaisyouSec)
	ON_COMMAND(ID_Jikokuhyou_DiagramHeIdou, OnJikokuhyouDiagramHeIdou)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_DiagramHeIdou, OnUpdateJikokuhyouDiagramHeIdou)
	ON_COMMAND(ID_VIEW_DisplayTsuukaEkiJikoku, OnVIEWDisplayTsuukaEkiJikoku)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DisplayTsuukaEkiJikoku, OnUpdateVIEWDisplayTsuukaEkiJikoku)
	ON_COMMAND(ID_FILE_EXPORT_JIKOKUHYOUCSV, OnFileExportJikokuhyoucsv)
	ON_COMMAND(ID_FILE_IMPORT_JIKOKUHYOUCSV, OnFileImportJikokuhyoucsv)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_PasteZoubun, OnUpdateINDICATOR_PasteZoubun)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuDecNoMove, &CWndJikokuhyou::OnJikokuhyouEkijikokudecnomove)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuDecNoMove, &CWndJikokuhyou::OnUpdateJikokuhyouEkijikokudecnomove)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuIncNoMove, &CWndJikokuhyou::OnJikokuhyouEkijikokuincnomove)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuIncNoMove, &CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuincnomove)
	ON_COMMAND(ID_Jikokuhyou_EkijikokuPrev, &CWndJikokuhyou::OnJikokuhyouEkijikokuPrev)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_EkijikokuPrev, &CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuPrev)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CWndJikokuhyou::OnEditSelectAll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SELECT_ALL, &CWndJikokuhyou::OnUpdateEditSelectAll)
	ON_COMMAND(ID_Jikokuhyou_SORT, &CWndJikokuhyou::OnJikokuhyouSort)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_SORT, &CWndJikokuhyou::OnUpdateJikokuhyouSort)
	ON_COMMAND(ID_Jikokuhyou_TsuukaTeisya, &CWndJikokuhyou::OnJikokuhyouTsuukateisya)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_TsuukaTeisya, &CWndJikokuhyou::OnUpdateJikokuhyouTsuukateisya)
	ON_COMMAND(ID_Jikokuhyou_Direct, &CWndJikokuhyou::OnJikokuhyouDirect)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Direct, &CWndJikokuhyou::OnUpdateJikokuhyouDirect)
	ON_COMMAND(ID_Jikokuhyou_Undirect, &CWndJikokuhyou::OnJikokuhyouUndirect)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Undirect, &CWndJikokuhyou::OnUpdateJikokuhyouUndirect)
	ON_COMMAND(ID_VIEW_DisplayAllEkiJikoku, &CWndJikokuhyou::OnViewDisplayallekijikoku)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DisplayAllEkiJikoku, &CWndJikokuhyou::OnUpdateViewDisplayallekijikoku)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_Jikokuhyou_Unify, &CWndJikokuhyou::OnJikokuhyouUnify)
	ON_UPDATE_COMMAND_UI(ID_Jikokuhyou_Unify, &CWndJikokuhyou::OnUpdateJikokuhyouUnify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


int CWndJikokuhyou::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (super::OnCreate(lpCreateStruct) == -1)
		return -1;


	// --------------------------------
	//	��Ԃ̏����l��ݒ�
	// --------------------------------
	m_StateMachine.add( OuNew< CWjkState >( new CWjkState_Ressyahensyu( this ) ) ) ;
	m_StateMachine.add( OuNew< CWjkState >( new CWjkState_Renzoku( this ) ) ) ;
	m_StateMachine.setCurrentStateIdx( StateIdx_Ressyahensyu ) ;


	// --------------------------------
	//	��̐����w��
	// --------------------------------
	//	�w��
	//	����
	//	���(1...*)
	getCXDcdGrid()->setXColumnCount( 3 ) ;
	getCXDcdGrid()->setXFixColumnCount( 2 ) ;
	//	��Ԕԍ�
	//	���
	//	��Ԗ�
	//	����
	//	��
	//	�w����(0...*)
	//	���l
	getCXDcdGrid()->setYColumnCount( 6 ) ;
	getCXDcdGrid()->setYFixColumnCount( 5 ) ;

	// --------------------------------
	//	�t�H�[�J�X�Z���̏����ʒu��ݒ�
	// --------------------------------
	getCFocus()->setFocusCell( getCXDcdGrid()->getCell( 1 , 1 ) ) ;	
	
	return 0;
}

void CWndJikokuhyou::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	m_StateMachine.getCurrentState()->
		OnKeyDown(nChar, nRepCnt, nFlags);
	//	super::OnKeyDown(nChar, nRepCnt, nFlags);
}
void CWndJikokuhyou::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	m_StateMachine.getCurrentState()->
		OnKeyUp(nChar, nRepCnt, nFlags);
	//super::OnKeyUp(nChar, nRepCnt, nFlags);
}



void CWndJikokuhyou::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	m_StateMachine.getCurrentState()->
		OnChar( nChar, nRepCnt, nFlags)  ;
	
	
}

void CWndJikokuhyou::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	m_StateMachine.getCurrentState()->
		OnLButtonDblClk(nFlags, point);
	//super::OnLButtonDblClk(nFlags, point);

}

//TODO:���t�@�N�^�����O
//	Grid�����OnContextMenu() �́A�������d�����Ă��܂��B
//	����́ACWndDcdGrid2(�����́ACWndDcdGrid3)�ɒu���ׂ��ł��B
void CWndJikokuhyou::OnContextMenu(CWnd* pWnd, CPoint point)
{
	int iMenuIndex = -1 ;
	//	�t�H�[�J�X�Z������Ԃɂ��邩�A�w�����ɂ��邩�𔻒肵�܂�
	//	����ɂ��A�\������R���e�L�X�g���j���[���ς��܂��B
	{
		const Mu<const CentDedRessya*>* pCentDedRessyaCont = getCentDedRessyaCont()->getMuPtr() ;
		CdXColSpec aXColSpec = getXColSpecOfFocus() ;
		CdYColSpec aYColSpec = getYColSpecOfFocus() ;
		
		//	�t�H�[�J�X�Z�����w�������E���(�V������� ���܂�)�ɂ���ꍇ�́A
		//	�R���e�L�X�g���j���[��\�����܂��B
		if ( aXColSpec.getColumnType() 
				== CdXColSpec::ColumnType_Ekimei || 
			aXColSpec.getColumnType() 
				== CdXColSpec::ColumnType_Chakuhatsu || 
			aXColSpec.getColumnType() 
				== CdXColSpec::ColumnType_Ressya || 
			aXColSpec.getColumnType() 
				== CdXColSpec::ColumnType_NewRessya )
		{
			if ( aYColSpec.isEkiJikoku() )
			{
				//	��Ԃ̉w�����ɃZ��������ꍇ�́A�w�����p�̃��j���[
				iMenuIndex = 1 ;
			}
			else
			{
				//	��Ԃ́A�w�����ȊO�̗�ԏ��ɃZ��������ꍇ�́A
				//	��ԗp�̃��j���[
				iMenuIndex = 0 ;
			}
		}
	}
	//iMenuIndex = 
	//	0: ��Ԃ̃R���e�L�X�g���j���[
	//	1: ��ԁE�w�����̃R���e�L�X�g���j���[
	//	-1: �Y������R���e�L�X�g���j���[������܂���B

	{
		//	�R���e�L�X�g���j���[���}�E�X�ȊO�ŌĂяo���ꂽ�ꍇ�́A
		//	�R���e�L�X�g���j���[�̕\���ʒu�́A�t�H�[�J�X�Z���̒����̈ʒu�Ƃ��܂��B
		if ( point.x ==-1 || point.y == -1 )
		{
			//	�R���e�L�X�g���j���[���}�E�X�ȊO�ŌĂяo����܂���
			CdDcdPosXy posxyFocusCellColumnNumber = getCFocus()->getFocusCellColumnNumber() ;
			if ( posxyFocusCellColumnNumber !=  
					CFocus::ColumnNumberPosXy_NULL() )
			{
				CdDcdZoneXy	zonexyFocusCell = getCellZone( 
					posxyFocusCellColumnNumber.getX() , 
					posxyFocusCellColumnNumber.getY() ) ;
				point.x = zonexyFocusCell.getX().getPos() + zonexyFocusCell.getX().getSize() / 2 ;
				point.y = zonexyFocusCell.getY().getPos() + zonexyFocusCell.getY().getSize() / 2 ;
				ClientToScreen( &point ) ;
			}
		}
	}
	//point = �R���e�L�X�g���j���[�̕\���ʒu�B
	//	-1�̏ꍇ�́A�R���e�L�X�g���j���[�͕\���ł��܂���B

	if ( iMenuIndex >= 0 && point.x >= 0 &&  point.y >= 0 )
	{
		CMenu	aMenu ;
		aMenu.LoadMenu( IDR_MENU_JIKOKUHYOUVIEW_CONTEXT ) ;
		CMenu* pContextMenu = aMenu.GetSubMenu( iMenuIndex ) ;
	
		pContextMenu->TrackPopupMenu( 
			TPM_LEFTALIGN | TPM_RIGHTBUTTON ,
			point.x , point.y , 
			AfxGetMainWnd() ) ;	//	this ���w�肷��ƁAApp��Doc��View ��
								//�R�}���h�`�F�[�������삵�܂���B
	}
	else
	{
		super::OnContextMenu(pWnd, point);
	}
}

void CWndJikokuhyou::OnEditCut() 
{
	m_StateMachine.getCurrentState()->
		OnEditCut_Process( FALSE )  ;

}

void CWndJikokuhyou::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditCut_Process( TRUE ) >= 0 );
}

void CWndJikokuhyou::OnEditCopy() 
{
	m_StateMachine.getCurrentState()->
		OnEditCopy_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditCopy_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnEditPaste() 
{
	m_StateMachine.getCurrentState()->
		OnEditPaste_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditPaste_Process( TRUE ) >= 0 ) ;
}
void CWndJikokuhyou::OnEditClear() 
{
	m_StateMachine.getCurrentState()->
		OnEditClear_Process( FALSE ) ;

}

void CWndJikokuhyou::OnUpdateEditClear(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditClear_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnEditPasteEkiJikoku() 
{
	m_StateMachine.getCurrentState()->
		OnEditPasteEkiJikoku_Process( FALSE ) ;

	
}

void CWndJikokuhyou::OnUpdateEditPasteEkiJikoku(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditPasteEkiJikoku_Process( TRUE ) >= 0 ) ;
	
}

void CWndJikokuhyou::OnEditSelectAll()
{
	m_StateMachine.getCurrentState()->
		OnEditSelectAll_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateEditSelectAll(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnEditSelectAll_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouRessyaProp() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouRessyaProp_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouRessyaProp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouRessyaProp_Process( TRUE )  >= 0 ) ;
	
}

void CWndJikokuhyou::OnJikokuhyouRessyaInsert() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouRessyaInsert_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouRessyaInsert(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouRessyaInsert_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouTsuuka() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouTsuuka_Process(FALSE) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouTsuuka(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouTsuuka_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouKeiyunasi() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouKeiyunasi_Process(FALSE) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouKeiyunasi(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouKeiyunasi_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouSihatsu() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouSihatsu_Process(FALSE) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouSihatsu(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouSihatsu_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouSyuuchaku() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouSyuuchaku_Process(FALSE) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouSyuuchaku(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouSyuuchaku_Process( TRUE )  >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouRenzoku() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouRenzoku_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouRenzoku(CCmdUI* pCmdUI) 
{
	int iResult = m_StateMachine.getCurrentState()->
		OnJikokuhyouRenzoku_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ; 
	pCmdUI->SetCheck( iResult > 0 ) ; 
}

void CWndJikokuhyou::OnJikokuhyouViewProp() 
{
	OnJikokuhyouViewProp_Process( FALSE ) ;
}



void CWndJikokuhyou::OnUpdateINDICATOR_PasteZoubun(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(); 
	pCmdUI->SetText( OnUpdateINDICATOR_PasteZoubun_Process() ) ;
}



void CWndJikokuhyou::OnJikokuhyouFocusMoveDown() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouFocusMoveDown_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouFocusMoveDown(CCmdUI* pCmdUI) 
{
	int iResult = m_StateMachine.getCurrentState()
		->OnJikokuhyouFocusMoveDown_Process( TRUE ) ;
	//iResult = 
	//	-	1 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͂��łɑI������Ă��܂�
	//	-	0 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͑I������Ă��܂���
	//	-  -1 ;	//	���̃R�}���h�͑I���ł��܂���(���j���[������)
	pCmdUI->Enable( iResult >= 0 );
	pCmdUI->SetCheck( iResult > 0 );
}

void CWndJikokuhyou::OnJikokuhyouFocusMoveRight() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouFocusMoveRight_Process( FALSE ) ;

}

void CWndJikokuhyou::OnUpdateJikokuhyouFocusMoveRight(CCmdUI* pCmdUI) 
{
	int iResult = m_StateMachine.getCurrentState()
		->OnJikokuhyouFocusMoveRight_Process( TRUE ) ;
	//iResult = 
	//	-	1 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͂��łɑI������Ă��܂�
	//	-	0 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͑I������Ă��܂���
	//	-  -1 ;	//	���̃R�}���h�͑I���ł��܂���(���j���[������)
	pCmdUI->Enable( iResult >= 0 );
	pCmdUI->SetCheck( iResult > 0 );
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuProp() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuProp_Process( FALSE ) ;

}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuProp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuProp_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouJikokuSakujo() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouJikokuSakujo_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouJikokuSakujo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouJikokuSakujo_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuInsert() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuInsert_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuInsert(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuInsert_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuErase() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuErase_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuErase(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuErase_Process( TRUE ) >= 0 ) ;
}


void CWndJikokuhyou::OnJikokuhyouModifyEkijikokuCmd() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouModifyEkijikokuCmd_Process( FALSE ) ;
	
}

void CWndJikokuhyou::OnUpdateJikokuhyouModifyEkijikokuCmd(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouModifyEkijikokuCmd_Process( TRUE ) >= 0 ) ;
	
}

void CWndJikokuhyou::OnJikokuhyouModifyEkijikokuCmdRepeat() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouModifyEkijikokuCmdRepeat_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouModifyEkijikokuCmdRepeat(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouModifyEkijikokuCmdRepeat_Process( TRUE ) >= 0 ) ;
}


void CWndJikokuhyou::OnJikokuhyouEkijikokuDec() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuDec_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuDec(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuDec_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuNext() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuNext_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuNext(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuNext_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuInc() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuInc_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuInc(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuInc_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokudecnomove()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuDecNoMove_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokudecnomove(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuDecNoMove_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuincnomove()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuIncNoMove_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuincnomove(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuIncNoMove_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouEkijikokuPrev()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuPrev_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEkijikokuPrev(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEkijikokuPrev_Process( TRUE ) >= 0 ) ;
}





void CWndJikokuhyou::OnJikokuhyouEKikanSaisyouSec() 
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouEKikanSaisyouSec_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouEKikanSaisyouSec(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouEKikanSaisyouSec_Process( TRUE ) >= 0 );
}

void CWndJikokuhyou::OnJikokuhyouSort()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouSort_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouSort(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouSort_Process( TRUE ) >= 0 );
}

void CWndJikokuhyou::OnJikokuhyouDiagramHeIdou() 
{
	OnJikokuhyouDiagramHeIdou_Process( FALSE ) ;
}
void CWndJikokuhyou::OnUpdateJikokuhyouDiagramHeIdou(CCmdUI* pCmdUI) 
{
	int iResult = OnJikokuhyouDiagramHeIdou_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ? TRUE : FALSE ) ;
}

void CWndJikokuhyou::OnVIEWDisplayTsuukaEkiJikoku() 
{
	OnVIEWDisplayTsuukaEkiJikoku_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateVIEWDisplayTsuukaEkiJikoku(CCmdUI* pCmdUI) 
{
	int iResult = OnVIEWDisplayTsuukaEkiJikoku_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ? TRUE : FALSE ) ;
	pCmdUI->SetCheck( iResult >= 1 ? TRUE : FALSE ) ;
	
}

//TODO:OnUpdate... �n���h����ǉ�����
void CWndJikokuhyou::OnFileExportJikokuhyoucsv() 
{
	OnFileExportJikokuhyoucsv_Process( FALSE ) ;
}

//TODO:OnUpdate... �n���h����ǉ�����
void CWndJikokuhyou::OnFileImportJikokuhyoucsv() 
{
	OnFileImportJikokuhyoucsv_Process( FALSE ) ;
}


void CWndJikokuhyou::OnJikokuhyouTsuukateisya()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouTsuukateisya_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouTsuukateisya(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouTsuukateisya_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouDirect()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouDirect_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouDirect(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouDirect_Process( TRUE ) >= 0 ) ;
}

void CWndJikokuhyou::OnJikokuhyouUndirect()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouUndirect_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouUndirect(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( m_StateMachine.getCurrentState()->
		OnJikokuhyouUndirect_Process( TRUE ) >= 0 ) ;
}



void CWndJikokuhyou::OnViewDisplayallekijikoku()
{
	OnViewDisplayallekijikoku_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateViewDisplayallekijikoku(CCmdUI *pCmdUI)
{
	int iResult = OnViewDisplayallekijikoku_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}

void CWndJikokuhyou::OnJikokuhyouUnify()
{
	m_StateMachine.getCurrentState()->
		OnJikokuhyouUnify_Process( FALSE ) ;
}

void CWndJikokuhyou::OnUpdateJikokuhyouUnify(CCmdUI *pCmdUI)
{
	int iResult = m_StateMachine.getCurrentState()->
		OnJikokuhyouUnify_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
}

} } // namespace WndJikokuhyou namespace ViewJikokuhyou

