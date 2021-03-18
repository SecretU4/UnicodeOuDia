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
// CDiagramEditDoc.cpp : CDiagramEditDoc �N���X�̓���̒�`���s���܂��B
// $Id: CDiagramEditDoc.cpp 295 2016-06-11 05:14:13Z okm $
/** @file */
#include "stdafx.h"

#include "logmsg/LogMsg.h"
#include "str/vectorToFile.h"
#include "str/CdFilenameStr.h"
#include "str/OuPropertiesText\CConvNodeContainer.h"
#include "str/OuPropertiesText\ErrorInfo\COuErrorInfoContainer.h"
#include "str/strprintf.h"
#include "str/strToVector.h"
#include "str/strToWstr.h"
#include "str/tstring.h"
#include "str/strLf.h"
#include "NsOu/dynamic_castOu.h"
#include "NsOu/OuNew.h"
#include "MfcUtil/MfcUtil.h"

#include "DiagramEdit.h"
#include "CDiagramEditDoc.h"
#include "DedRosenFileData\CconvCDedRosenFileData.h"
#include "entDed\CconvCentDed.h"
#include "WinDia\CconvWinDia.h"
#include "CRfEditCmdHolder.h"
#include "WinDia\CDlgDiaSaveSelect.h"
#include "ConvFile\CConvFileDll.h"
#include "ConvFile\CaByteBuffer_vector.h"
#include "ConvFile\CaByteBuffer_string.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace std ;
using namespace OuLib::Str ;
using namespace OuLib::Str::OuPropertiesText ;
using namespace OuLib::Str::OuPropertiesText::ErrorInfo ;
using namespace WinDia;
using namespace ConvFile;
using namespace OuMfc;

/////////////////////////////////////////////////////////////////////////////
// CDiagramEditDoc

/**	Undo �̍ő�񐔂ł��B */
const int iUndoLevel = 8 ;
// --------------------------------
//@name	�����֐�-WinDia�`��
// --------------------------------
BOOL CDiagramEditDoc::OnOpenDocument_WinDia( LPCTSTR lpszPathName ) 
{
	LogMsg( "CDiagramEditDoc::OnOpenDocument_WinDia(%s)" , lpszPathName ) ;
	int iRv = 0 ;

	// --------------------------------
	//	�t�@�C���̓��e���Astring�ɕۑ�
	// --------------------------------
	string	aString ;
	CString	strError ;
	if ( iRv >= 0 ){
		int iResult = stringFromFile( &aString , lpszPathName ) ;
		//iResult = 
		//	-1: �t�@�C�����I�[�v���ł��܂���B
		//	-2 ; �ǂݍ��݂Ɏ��s���܂����B
		//	-3 ; �t�@�C���ɂ� "\0" ���܂܂�܂�(�o�C�i���t�@�C���ł���� 
		//	�v���܂�)�B
		//	 ���̏ꍇ�ApString �ɂ́A "\0" �̒��O�܂ł̃f�[�^���i�[����� 
		//	���܂��B 
		if ( iResult < 0 ){
			iRv = iResult ;
			switch( iResult ){
			 case -1 :	// �t�@�C�����I�[�v���ł��܂���B
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILENOTFOUND ) ;
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -2 :	//; �ǂݍ��݂Ɏ��s���܂����B
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEREAD ) ;
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -3 :	// �t�@�C���ɂ� "\0" ���܂܂�܂�
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEFORMAT ) ;
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			}
			//iRv = 
			//	-1: �t�@�C�����I�[�v���ł��܂���B
			//	-2 ; �ǂݍ��݂Ɏ��s���܂����B
			//	-3 ; �t�@�C���ɂ� "\0" ���܂܂�܂�(�o�C�i���t�@�C���ł���� 
			//	�v���܂�)�B
			//	 ���̏ꍇ�ApString �ɂ́A "\0" �̒��O�܂ł̃f�[�^���i�[����� 
			//	���܂��B 
		}
	}
	//aString = �t�@�C���̓��e��ێ����܂��B

	LogMsg( "CDiagramEditDoc::OnOpenDocument_WinDia()1" ) ;

	// --------------------------------
	//	�t�@�C���̓��e�̕����������
	// --------------------------------
	if ( iRv >= 0 ){
		CDedRosenFileData	aCDedRosenFileData ;
		CconvWinDia aCconvWinDia ;
		int iResult = aCconvWinDia.CDedRosenFileData_From_WinDiaFileString( 
			&aCDedRosenFileData , aString ) ;
		if ( iResult < 0 ){
			iRv = iResult ;
		}	else	{
			m_CDedRosenFileData = aCDedRosenFileData ;
		}
	}	

	// --------------------------------
	//	�H���r���[���X�V
	// --------------------------------
	getCDiagramEditApp()->getCDlgRosenView()->OnUpdate( NULL , 0 , NULL ) ;

	// --------------------------------
	LogMsg( "CDiagramEditDoc::OnOpenDocument_WinDia()=%d" , iRv ) ;
	if ( iRv < 0 ){
		if ( strError.IsEmpty() ){
			CString	strFmt ;
			strFmt.LoadString( IDS_ERR_ERRORCODE ) ;
			strError.Format( strFmt , iRv ) ;
		}
		AfxMessageBox( strError , MB_ICONSTOP ) ; 
		return ( FALSE ) ;
	}
	//	�h�L�������g�̃t�@�C�����́A
	//	CDiagramEditDoc::SetPathName()�Ń`�F�b�N����܂��B
	//	�g���q .dia �́A�h�L�������g�̗L���ȃt�@�C�����Ƃ�
	//	���܂���(.dia �ւ̏㏑���ۑ��͂��܂���)
	return TRUE;

}

	
BOOL CDiagramEditDoc::OnSaveDocument_WinDia(  LPCTSTR lpszPathName ) 
{
	/*
	 *	OnSaveDocument() �̉����֐��ł��B
	 *	�h�L�������g�̓��e���AWinDia �`���̃t�@�C���ɕۑ����܂��B
	 * @param lpszPathName [in]
	 * 	�ۑ�����t�@�C�������w�肵�ĉ������B
	 * @return
	 *	���������� TRUE �E �G���[�Ȃ� FALSE �ł��B
	 *
	 *	���̊֐��́A�G���[�̏ꍇ�̓��b�Z�[�W�{�b�N�X��\�����܂��B
	 */
	// --------------------------------
	int iRv = 0 ;

	CString	strError ;
	string	aString ;

	// --------------------------------
	//	�ۑ�����_�C����I��
	// --------------------------------
	int idxDia = -1 ;
	if ( iRv >= 0 ){
		CentDedRosen* pCentDedRosen = m_CDedRosenFileData.getCentDedRosen();
		if ( pCentDedRosen->getCentDedDiaCont()->getMuPtr()->size() == 0 )
		{
			iRv = -101 ;	//	�_�C�������݂��܂���B
			CString strFmt ;
			strFmt.LoadString( IDS_ERR_NoDia ) ;
			strError.Format( strFmt , lpszPathName ) ;
		}
		else if ( pCentDedRosen->getCentDedDiaCont()->getMuPtr()->size() == 1 )
		{
			idxDia = 0 ;
		}	else	{
			Mu<CentDedDia*>* pCentDedDiaContGet = 
				pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

			CMup_deque< string > contstrDiaName ;
			for ( int idxDiaName = 0 ; 
				idxDiaName < pCentDedDiaContGet->size() ; 
				idxDiaName ++ ){
				contstrDiaName.insert( pCentDedDiaContGet->get( idxDiaName )->getName() ) ;
			}
			CDlgDiaSaveSelect	aDlg( contstrDiaName , NULL ) ;
			if ( aDlg.DoModal() == IDOK ){
				idxDia = aDlg.getDiaIndex() ;
			}	else	{
				return FALSE ;
			}
		}
	}
	//idxDia = �I�����ꂽ�_�C���̃C���f�N�X
	// --------------------------------
	//	WinDIA�`���̃t�@�C���̕�������쐬
	// --------------------------------
	if ( iRv >= 0 ){
		CconvWinDia aCconvWinDia ;
		int iResult = aCconvWinDia.CDedRosenFileData_To_WinDiaFileString( &m_CDedRosenFileData ,idxDia , &aString ) ;
		//iResult = 
		//	-21 ;	//	WinDIA �`���ł́A��Ԏ�ʂ�24��ނ܂łɐ�������Ă��܂��B
		//	-22 ;	//	���̂̒��������p�T�����𒴂����Ԏ�ʂ�����܂��B
		//			//	WinDIA �`���ɕۑ����邽�߂ɂ́A���ׂĂ̗�Ԏ�ʗ��̂�
		//			//	�S�p�Q�����ȓ��łȂ��Ă͂Ȃ�܂���B
		//	-1 ;	//	idxDia �̎w�肪�s���ł��B
		if ( iResult < 0 ){
			iRv = iResult ;
			switch( iResult ){
			 case -21 : //	WinDIA �`���ł́A��Ԏ�ʂ�24��ނ܂łɐ�������Ă��܂��B
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_RessyasyubetsuTooMany ) ;
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -22 :	//	���̂̒��������p�T�����𒴂����Ԏ�ʂ�����܂��B
				 {
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_RyakusyouTooLong ) ;
					strError.Format( strFmt , lpszPathName ) ;
				 }
			}
			//iRv = 
			//	-	-21 ;	//	WinDIA �`���ł́A��Ԏ�ʂ�24��ނ܂łɐ�������Ă��܂��B
			//	-	-22 :	//	���̂̒��������p�T�����𒴂����Ԏ�ʂ�����܂��B
			//	-	-1 ;	//	idxDia �̎w�肪�s���ł��B
		}
	}	
	//aString = �t�@�C���ɏ������ށw�H���t�@�C���x�`���̕������ێ����܂��B

	// --------------------------------
	//	�t�@�C���̕ۑ�
	// --------------------------------
	LogMsg( "CDiagramEditDoc::OnSaveDocument()1" ) ;
	if ( iRv >= 0 ){
		int iResult = stringToFile( aString , lpszPathName ) ;
		//iResult = 
		//	-1: �t�@�C�����I�[�v���ł��܂���B
		//	-2 ; // �������݂Ɏ��s���܂����B 
		if ( iResult < 0 ){
			switch( iResult ){
			 case -1 :	// �t�@�C�����I�[�v���ł��܂���B
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILECREATE ) ;
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -2 :	//;�������݂Ɏ��s���܂���
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEWRITE ) ;
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			}
			//iRv = 
			//	-1: �t�@�C�����I�[�v���ł��܂���B
			//	-2 ; �������݂Ɏ��s���܂���
			iRv = iResult - 100 ;
		}
	}

	// --------------------------------
	LogMsg( "CDiagramEditDoc::OnSaveDocument()=%d" , iRv ) ;

	if ( iRv < 0 ){
		if ( strError.IsEmpty() ){
			CString	strFmt ;
			strFmt.LoadString( IDS_ERR_ERRORCODE ) ;
			strError.Format( strFmt , iRv ) ;
		}
		AfxMessageBox( strError , MB_ICONSTOP ) ; 
		return ( FALSE ) ;
	}

	//	WinDIA �`���̕ۑ��́A�����ȃh�L�������g�̕ۑ��Ƃ͂��܂���B
	//	WinDIA �`���̕ۑ��ɐ������Ă��A�h�L�������g�t�@�C������
	//	WinDIA �t�@�C���̃t�@�C�����ɂ͂��܂���B
	//	�h�L�������g�̕ύX�t���O���A�N���A���܂���B
	//	�iWinDIA�t�@�C���́A�h�L�������g�S�̂�ێ����邱�Ƃ�
	//	�ł��Ȃ����߂ł��B�j
	//	���̂��߁A�ȉ��̏����͍s���܂���
	// --------------------------------
	//	SetModifiedFlag( FALSE ) ;
	//	return TRUE;
	// --------------------------------
	
	//iRv = 
	//	-	-101 ;	//	�_�C�������݂��܂���B
	//	-	-21 ;	//	WinDIA �`���ł́A��Ԏ�ʂ�24��ނ܂łɐ�������Ă��܂��B
	//	-	-22 :	//	���̂̒��������p�T�����𒴂����Ԏ�ʂ�����܂��B
	//	-	-1 ;	//	idxDia �̎w�肪�s���ł��B
	//	-	-201: �t�@�C�����I�[�v���ł��܂���B
	//	-	-202 ; �������݂Ɏ��s���܂���
	return FALSE ;
}
	

// ********************************
//	CHidemdiRootDoc
// ********************************
void CDiagramEditDoc::UpdateAllSubDocviews( CView* pSender
							, LPARAM lHint , CObject* pHint )
{
	// --------------------------------
	//	�����\�E�_�C���O�����r���[�ɑΉ�����
	//	�_�C�����폜����Ă�����A
	//	�Ή�����T�uView����܂��B
	// --------------------------------
	POSITION	LPosition = AfxGetApp()->GetFirstDocTemplatePosition() ;
	while( LPosition != NULL ){
		CDocTemplate*	pLDocTemplate = AfxGetApp()
						->GetNextDocTemplate( LPosition ) ;
		{
			POSITION	LPosition = pLDocTemplate->GetFirstDocPosition() ;
			while( LPosition != NULL ){
				CDocument*	pLDocument = 
					pLDocTemplate->GetNextDoc( LPosition ) ;
				
				if ( pLDocument != NULL && 
						pLDocument->IsKindOf( RUNTIME_CLASS( CJikokuhyouDoc ) ) ){
					CJikokuhyouDoc*	pCJikokuhyouDoc = 
						(CJikokuhyouDoc*)pLDocument ;
					
					const CentDedRosen*	pCentDedRosen = 
						getCDiagramEditDoc()->getCDedRosenFileData()->
						getCentDedRosen() ;
					CentDedDia*	pCentDedDia = NULL ;
					int idxDia = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( 
						pCJikokuhyouDoc->getDiaName() ) ;
					if ( idxDia < 0 ){
						//	���̃h�L�������g�ɑΉ�����_�C���͍폜����܂���
						pCJikokuhyouDoc->OnCloseDocument() ;
						pLDocument = NULL ;
					}
				}
				if (  pLDocument != NULL && 
						pLDocument->IsKindOf( RUNTIME_CLASS( CDedDiagramDoc ) ) ){
					CDedDiagramDoc*	pCDedDiagramDoc = 
						(CDedDiagramDoc*)pLDocument ;
					
					const CentDedRosen*	pCentDedRosen = 
						getCDiagramEditDoc()->getCDedRosenFileData()->
						getCentDedRosen() ;
					CentDedDia*	pCentDedDia = NULL ;
					int idxDia = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( 
						pCDedDiagramDoc->getDiaName() ) ;
					if ( idxDia < 0 ){
						//	���̃h�L�������g�ɑΉ�����_�C���͍폜����܂���
						pCDedDiagramDoc->OnCloseDocument() ;
						pLDocument = NULL ;
					}
				}
			}
		}
	}
	// --------------------------------
	//	���ׂẴT�uView���X�V
	// --------------------------------
	super::UpdateAllSubDocviews( pSender , lHint , pHint );
	// --------------------------------
	//	�H��View���X�V
	// --------------------------------
	getCDiagramEditApp()->getCDlgRosenView()->OnUpdate(  pSender , lHint , pHint ) ;

}

// ********************************
//	CDiagramEditDoc
// ********************************
	// ********************************
	//@name ���
	// ********************************
const CDedRosenFileData*	CDiagramEditDoc::getCDedRosenFileData()const 
{
	return &m_CDedRosenFileData ;
}



	// ********************************
	//@name �N���b�v�{�[�h����
	// ********************************

UINT CDiagramEditDoc::getCF_CentDedEki()
{
	return RegisterClipboardFormat( "CF_CentDedEki" ) ;
} ;

/**
	string ���A�N���b�v�{�[�h�ɃR�s�[���܂��B
@param aHwnd [in]
	�N���b�v�{�[�h�̃I�[�i�[�ƂȂ�E�C���h�E���w�肵�Ă��������B
@param uiClipboardFormat [in]
	�N���b�v�{�[�h�t�H�[�}�b�g���w�肵�Ă��������B
@param strData [in]
	�N���b�v�{�[�h�ɃR�s�[���镶������w�肵�Ă��������B
@return
	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	-	-2 ;	//	�������̊m�ۂɎ��s���܂����B
	-	-11 ;	//	�N���b�v�{�[�h���I�[�v���ł��܂���B
	-	-12 ;	//	�N���b�v�{�[�h�ւ̃f�[�^�ݒ肪���s
*/
static int stringToClipboard( 
		HWND aHwnd , 
		UINT uiClipboardFormat , 
		const string& strData ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	�N���b�v�{�[�h�ւ̓]��
	// --------------------------------
	HGLOBAL	hGlobal = NULL ;
	if ( iRv >= 0 )
	{	
		hGlobal = GlobalAlloc( GMEM_MOVEABLE, strData.length() + 1);
		if ( hGlobal == NULL )
		{
			iRv = -2 ;	//	�������̊m�ۂɎ��s���܂����B
		}
		else
		{
			void*	pGlobal = GlobalLock( hGlobal ) ;
			memcpy( pGlobal , strData.c_str() , strData.length() + 1 ) ;
			GlobalUnlock( hGlobal ) ;
		}
	}
	//hGlobal = CentDedEki �̓��e��ێ����Ă��܂��B
	
	bool	bIsOpen = false ;
	if ( iRv >= 0 )
	{	
		if ( !OpenClipboard( aHwnd ) )
		{
			iRv = -11 ;	//	�N���b�v�{�[�h���I�[�v���ł��܂���B
		}
		else
		{
			bIsOpen = true ;
		}
	}
	if ( iRv >= 0 ){	
		EmptyClipboard();
		HANDLE hResult = SetClipboardData( uiClipboardFormat , hGlobal);
		if ( hResult == NULL )
		{
			iRv = -12 ;	//	�N���b�v�{�[�h�ւ̃f�[�^�ݒ肪���s
		}
		else
		{
			//	�N���b�v�{�[�h�ւ̓]�����������܂����̂ŁA
			//	���̃A�v���P�[�V������ hGlobal ����������ɕ������܂��B
			hGlobal = NULL ;
		}
	}
	if ( bIsOpen )
	{
		CloseClipboard();
	}
	if ( hGlobal != NULL )
	{
		GlobalFree( hGlobal ) ;
		hGlobal = NULL ;
	}
	return iRv ;
}



/**
	string ���A�N���b�v�{�[�h�ɃR�s�[���܂��B
@param aHwnd [in]
	�N���b�v�{�[�h�̃I�[�i�[�ƂȂ�E�C���h�E���w�肵�Ă��������B
@param uiClipboardFormat [in]
	�N���b�v�{�[�h�t�H�[�}�b�g���w�肵�Ă��������B
@param pstrData [out]
	���̊֐��͂��̕�����ɁA�N���b�v�{�[�h�̕�������R�s�[���܂��B
	�s�v�Ȃ� NULL ���w�肵�Ă����܂��܂���B
@return
	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	-	-1 ;	//	�N���b�v�{�[�h�ɂ͗L���ȃf�[�^�͂���܂���B
	-	-11 ;	//	�N���b�v�{�[�h���I�[�v���ł��܂���B
*/
static int stringFromClipboard( 
		HWND aHwnd , 
		UINT uiClipboardFormat , 
		string* pstrData )
{
	int iRv = 0 ;
	// --------------------------------
	//	�N���b�v�{�[�h����f�[�^���擾
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 )
	{	
		if ( !IsClipboardFormatAvailable(uiClipboardFormat) ) 
		{
			iRv = -1 ;	//	�N���b�v�{�[�h�ɂ͗L���ȃf�[�^�͂���܂���B
		}
	}
	bool	bIsOpen = false ;
	if ( iRv >= 0 )
	{ 
		if ( !OpenClipboard( aHwnd ) )
		{
			iRv = -11 ;	//	�N���b�v�{�[�h���I�[�v���ł��܂���B
		}
		else
		{
			bIsOpen = true ;
		}
	}
	if ( iRv >= 0 )
	{
		HGLOBAL	hGlobal = NULL ;
        hGlobal = GetClipboardData(uiClipboardFormat);
		if ( hGlobal != NULL )
		{
			const char* lpszData = (const char*)GlobalLock( hGlobal ) ;
			strData = lpszData ;
			GlobalUnlock( hGlobal ) ;
		}
	}
	if ( bIsOpen )
	{
        CloseClipboard();
	} 
	// --------------------------------
	if ( pstrData != NULL )
	{
		*pstrData = strData ;
	}
	// --------------------------------
	return iRv ;
}


int CDiagramEditDoc::CentDedEki_To_Cliboard( 
	const Mu<CentDedEki>* pMuCentDedEki ) 
{
	int iRv = 0 ;

	// --------------------------------
	//	Mu ���� EkiCont �ɕϊ�
	// --------------------------------
	CentDedEkiCont	aEkiCont ;
	if ( iRv >= 0 )
	{
		CaMui<CentDedEki> aCaMui( &aEkiCont ) ;
		aCaMui.insert( pMuCentDedEki ) ;
	}

	// --------------------------------
	//	�f�[�^�𕶎���
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 )
	{
		CNodeContainer aCNodeContainer ;
		CconvCentDed aCconvCentDed ;
		int iResult = aCconvCentDed.CentDedEkiCont_To_OuPropertiesText( 
			aEkiCont , 
			&aCNodeContainer ) ;
		if ( iRv < 0 )
		{
			iRv = -1 ;	//	CentDedEki �̓��e���s���ł��B
		}
		else
		{
			CConvNodeContainer	aCConvNodeContainer ;
			strData = aCConvNodeContainer.encode( &aCNodeContainer ) ;
			if ( strData.length() == 0 )
			{
				iRv = -1 ;	//	CentDedEki �̓��e���s���ł��B
			}
		}
	}
	//strData = CentDedEki �̓��e

	// --------------------------------
	//	�N���b�v�{�[�h�ւ̓]��
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult = stringToClipboard(  
			AfxGetMainWnd()->GetSafeHwnd() ,
			getCF_CentDedEki() , 
			strData ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	�N���b�v�{�[�h�ւ̃f�[�^�ݒ肪���s
		}
	}
	return iRv ;
}

int CDiagramEditDoc::CentDedEki_From_Cliboard( 
		Mui<CentDedEki>* pCentDedEki ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	�N���b�v�{�[�h����f�[�^���擾
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 )
	{	
		if (!IsClipboardFormatAvailable(getCF_CentDedEki())) 
		{
			iRv = -1 ;	//	�N���b�v�{�[�h�ɂ͗L���ȃf�[�^�͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = stringFromClipboard( 
			AfxGetMainWnd()->GetSafeHwnd() , 
			getCF_CentDedEki() , 
			&strData ) ;
		if ( iResult < 0 )
		{
			iRv = -2 ;	//	�N���b�v�{�[�h����̓ǂݍ��݂Ɏ��s���܂����B	
		}
	}
	//strData = CentDedEki �̓��e
	// --------------------------------
	//	�����񂩂�w�f�[�^���쐬
	// --------------------------------
	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		CConvNodeContainer aCConvNodeContainer ;
		int iResult = aCConvNodeContainer.decode( 
			strData , 
			&aCNodeContainer ) ;
		if ( iResult < 0 )
		{
			iRv = -3 ;	//	�N���b�v�{�[�h�̓��e���s���ł��B
		}
	}
	CentDedEkiCont	aCentDedEkiCont ;
	if ( iRv >= 0 )
	{
		CconvCentDed aCconvCentDed ;
		COuErrorInfoContainer aCOuErrorInfoContainer ;
		int iResult = aCconvCentDed.CentDedEkiCont_From_OuPropertiesText( 
			&aCentDedEkiCont , 
			aCNodeContainer.getIfNodeContainerConst() , 
			&aCOuErrorInfoContainer ) ;
		//iResult = 
		//	-22 ; // Ekijikokukeisiki �̒l���s���ł��B
		//	-32 ; // Ekikibo �̒l���s���ł��B 
		if ( iRv < 0 )
		{
			iRv = -4 ;	//	CentDedEki �̓��e���s���ł��B
		}
	}

	// --------------------------------
	//	Mu ���� EkiCont �ɕϊ�
	// --------------------------------
	if ( iRv >= 0 )
	{
		CaMui<CentDedEki> aCaMui( pCentDedEki ) ;
		aCaMui.insert( &aCentDedEkiCont ) ;
	}
	// --------------------------------
	return ( iRv ) ;
}



bool CDiagramEditDoc::CentDedEki_IsClipboardFormatAvailable() 
{
	return ( IsClipboardFormatAvailable( getCF_CentDedEki() ) != 0 );
}

UINT CDiagramEditDoc::getCF_CentDedRessyasyubetsu()
{
	return RegisterClipboardFormat( "CF_CentDedRessyasyubetsu" ) ;
} ;

int CDiagramEditDoc::CentDedRessyasyubetsu_To_Cliboard( 
		const Mu<CentDedRessyasyubetsu>* pMuCentDedRessyasyubetsu ) 
{
	int iRv = 0 ;

	// --------------------------------
	//	Mu ���� CentDedRessyasyubetsuCont �ɕϊ�
	// --------------------------------
	CentDedRessyasyubetsuCont	aRessyasyubetsuCont ;
	if ( iRv >= 0 )
	{
		CaMui<CentDedRessyasyubetsu> aCaMui( &aRessyasyubetsuCont ) ;
		aCaMui.insert( pMuCentDedRessyasyubetsu ) ;
	}
	// --------------------------------
	//	�f�[�^�𕶎���
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 )
	{
		CNodeContainer aCNodeContainer ;
		CconvCentDed aCconvCentDed ;
		int iResult = aCconvCentDed.CentDedRessyasyubetsuCont_To_OuPropertiesText( 
			aRessyasyubetsuCont , 
			&aCNodeContainer ) ;
		//iResult = 
		//	-	-11 ;	//	Syubetsumei ���w�肳��Ă��܂���B
		//	-	-52 ;	//	DiagramSenStyle �̒l���s���ł��B
		if ( iRv < 0 )
		{
			iRv = -1 ;	//	CentDedRessyasyubetsuCont �̓��e���s���ł��B
		}
		else
		{
			CConvNodeContainer	aCConvNodeContainer ;
			strData = aCConvNodeContainer.encode( &aCNodeContainer ) ;
			if ( strData.length() == 0 )
			{
				iRv = -1 ;	//	CentDedRessyasyubetsu �̓��e���s���ł��B
			}
		}
	}
	//strData = CentDedRessyasyubetsu �̓��e	return iRv ;
	// --------------------------------
	//	�N���b�v�{�[�h�ւ̓]��
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult = stringToClipboard(  
			AfxGetMainWnd()->GetSafeHwnd() ,
			getCF_CentDedRessyasyubetsu() , 
			strData ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	�N���b�v�{�[�h�ւ̃f�[�^�ݒ肪���s
		}
	}
	return iRv ;
}

int CDiagramEditDoc::CentDedRessyasyubetsu_From_Cliboard( 
	Mui<CentDedRessyasyubetsu>* pMuCentDedRessyasyubetsu ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	�N���b�v�{�[�h����f�[�^���擾
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 )
	{	
		if (!IsClipboardFormatAvailable(getCF_CentDedRessyasyubetsu())) 
		{
			iRv = -1 ;	//	�N���b�v�{�[�h�ɂ͗L���ȃf�[�^�͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = stringFromClipboard( 
			AfxGetMainWnd()->GetSafeHwnd() , 
			getCF_CentDedRessyasyubetsu() , 
			&strData ) ;
		if ( iResult < 0 )
		{
			iRv = -2 ;	//	�N���b�v�{�[�h����̓ǂݍ��݂Ɏ��s���܂����B	
		}
	}
	//strData = CentDedEki �̓��e
	// --------------------------------
	//	�����񂩂��Ԏ�ʃf�[�^���쐬
	// --------------------------------
	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		CConvNodeContainer aCConvNodeContainer ;
		int iResult = aCConvNodeContainer.decode( 
			strData , 
			&aCNodeContainer ) ;
		if ( iResult < 0 )
		{
			iRv = -3 ;	//	�N���b�v�{�[�h�̓��e���s���ł��B
		}
	}
	CentDedRessyasyubetsuCont	aCentDedRessyasyubetsuCont ;
	if ( iRv >= 0 )
	{
		CconvCentDed aCconvCentDed ;
		COuErrorInfoContainer aCOuErrorInfoContainer ;
		int iResult = aCconvCentDed.CentDedRessyasyubetsuCont_From_OuPropertiesText( 
			&aCentDedRessyasyubetsuCont , 
			aCNodeContainer.getIfNodeContainerConst() , 
			&aCOuErrorInfoContainer ) ;
		//iResult = 
		//-	-11 ;	//	Syubetsumei ���w�肳��Ă��܂���B
		//-	-52 ;	//	DiagramSenStyle �̒l���s���ł��B
		//-	-101 ;	//	�l�̌`��������������܂���B
		if ( iRv < 0 )
		{
			iRv = -4 ;	//	CentDedEki �̓��e���s���ł��B
		}
	}
	// --------------------------------
	//	Mu ���� EkiCont �ɕϊ�
	// --------------------------------
	if ( iRv >= 0 )
	{
		CaMui<CentDedRessyasyubetsu> aCaMui( pMuCentDedRessyasyubetsu ) ;
		aCaMui.insert( &aCentDedRessyasyubetsuCont ) ;
	}
	// --------------------------------

	return iRv ;
}


bool CDiagramEditDoc::CentDedRessyasyubetsu_IsClipboardFormatAvailable() 
{
	return ( IsClipboardFormatAvailable( getCF_CentDedRessyasyubetsu() ) != 0 );
}

UINT CDiagramEditDoc::getCF_CentDedRessyaCont() 
{
	return RegisterClipboardFormat( "CF_CentDedRessyaCont" ) ;
}

int CDiagramEditDoc::CentDedRessyaCont_To_Cliboard( 
		const CentDedRessyaCont& aCentDedRessyaCont ) 
{
	int iRv = 0 ;

	// --------------------------------
	//	�f�[�^�𕶎���
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 )
	{
		CNodeContainer aCNodeContainer ;
		CconvCentDed aCconvCentDed ;
		int iResult = aCconvCentDed.CentDedRessyaCont_To_OuPropertiesText( 
			&aCentDedRessyaCont , 
			&aCNodeContainer ) ;
		if ( iRv < 0 )
		{
			iRv = -1 ;	//	aCentDedRessyaCont �̓��e���s���ł��B
		}
		else
		{
			CConvNodeContainer	aCConvNodeContainer ;
			strData = aCConvNodeContainer.encode( &aCNodeContainer ) ;
			if ( strData.length() == 0 )
			{
				iRv = -1 ;	//	aCentDedRessyaCont �̓��e���s���ł��B
			}
		}
	}
	//string = aCentDedRessyaCont �̓��e

	// --------------------------------
	//	�N���b�v�{�[�h�ւ̓]��
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult = stringToClipboard(  
			AfxGetMainWnd()->GetSafeHwnd() ,
			getCF_CentDedRessyaCont() , 
			strData ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	�N���b�v�{�[�h�ւ̃f�[�^�ݒ肪���s
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CDiagramEditDoc::CentDedRessyaCont_From_Cliboard( 
		CentDedRessyaCont* pCentDedRessyaCont ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	�N���b�v�{�[�h����f�[�^���擾
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 ){	
		if (!IsClipboardFormatAvailable(getCF_CentDedRessyaCont())) {
			iRv = -1 ;	//	�N���b�v�{�[�h�ɂ͗L���ȃf�[�^�͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = stringFromClipboard( 
			AfxGetMainWnd()->GetSafeHwnd() , 
			getCF_CentDedRessyaCont() , 
			&strData ) ;
		if ( iResult < 0 )
		{
			iRv = -2 ;	//	�N���b�v�{�[�h����̓ǂݍ��݂Ɏ��s���܂����B	
		}
	}
	//strData = CentDedRessyaCont �̓��e
	// --------------------------------
	//	�����񂩂��ԃf�[�^���쐬
	// --------------------------------
	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		CConvNodeContainer aCConvNodeContainer ;
		int iResult = aCConvNodeContainer.decode( 
			strData , 
			&aCNodeContainer ) ;
		if ( iResult < 0 )
		{
			iRv = -3 ;	//	�N���b�v�{�[�h�̓��e���s���ł��B
		}
	}

	if ( iRv >= 0 )
	{
		CconvCentDed aCconvCentDed ;
		COuErrorInfoContainer aCOuErrorInfoContainer ;
		int iResult = aCconvCentDed.CentDedRessyaCont_From_OuPropertiesText( 
			pCentDedRessyaCont , 
			aCNodeContainer.getIfNodeContainerConst() , 
			&aCOuErrorInfoContainer ) ;
		if ( iResult < 0 )
		{
			iRv = -4 ;	//	CentDedRessyaCont �̓��e���s���ł��B
		}
	}
	//pCentDedRessyaCont = CentDedRessyaCont �̓��e

	// --------------------------------
	return ( iRv ) ;
}

bool CDiagramEditDoc::CentDedRessyaCont_IsClipboardFormatAvailable() 
{
	return ( IsClipboardFormatAvailable( getCF_CentDedRessyaCont() ) != 0 );
}
	// ********************************
	//@name ����
	// ********************************
int CDiagramEditDoc::executeEditCmd( Ou< CRfEditCmd > pCmd ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	�R�}���h�����s
	// --------------------------------
	if ( iRv >= 0 )
	{
		iRv = pCmd->execute( &m_CDedRosenFileData ) ;
	}
	// --------------------------------
	//	�r���[�̍X�V
	// --------------------------------
	if ( iRv >= 0 )
	{
		UpdateAllSubDocviews( NULL , 0 , 
			&CRfEditCmdHolder( pCmd ) ) ;
	}
	// --------------------------------
	//	Undo,Redo�֌W�����f�[�^ ���X�V
	//	Undo���̕ۑ�/Redo���̓N���A
	// --------------------------------
	if ( iRv >= 0 )
	{
		m_contUndo.insert( pCmd ) ;
		while ( m_contUndo.size() > iUndoLevel )
		{
			m_contUndo.erase( 0 ) ;
		}

		m_contRedo.erase( 0 , INT_MAX ) ;
		
		if ( m_iModifyCountFromDoc != INT_MAX )
		{
			if ( m_iModifyCountFromDoc < 0 )
			{
				m_iModifyCountFromDoc = INT_MAX ;
			}
			else
			{
				m_iModifyCountFromDoc ++ ;
			}
		}
	}
	// --------------------------------
	//	ModifiedFlag ���X�V
	// --------------------------------
	SetModifiedFlag( m_iModifyCountFromDoc != 0 ) ;

	return ( iRv ) ;
}


bool CDiagramEditDoc::canUndo() 
{
	return ( m_contUndo.size() > 0 ) ; 
}
int CDiagramEditDoc::undo() 
{
	LogMsg( "CDiagramEditDoc::undo()" ) ;
	int iRv = 0 ;

	Ou< CRfEditCmd >	pCmd ;
	// --------------------------------
	//	�R�}���h���L���[����擾
	// --------------------------------
	if ( iRv >= 0 ){
		if ( m_contUndo.size() >= 1 ){
			pCmd = m_contUndo.get( INT_MAX ) ;
		}	else	{
			iRv = -1 ;	//	undo ��񂪂���܂���B
		}
	}
	//pcmdUndo = undo �̂��߂̃R�}���h
	// --------------------------------
	//	�R�}���h�����s
	// --------------------------------
	Ou< CRfEditCmd >	pUndoCmd ;
	if ( iRv >= 0 ){
		pUndoCmd = pCmd->createUndoCmd() ;
		if ( pUndoCmd == NULL ){
			iRv = -2 ;	//	undo �̎��s�Ɏ��s
		}
	}
	if ( iRv >= 0 ){
		int iResult  = pUndoCmd->execute( &m_CDedRosenFileData ) ;
		if ( iResult < 0 ){
			iRv = -2 ;	//	undo �̎��s�Ɏ��s
		}
	}
	// --------------------------------
	//	�r���[�̍X�V
	// --------------------------------
	if ( iRv >= 0 ){
		UpdateAllSubDocviews( NULL , 0 , 
			&CRfEditCmdHolder( pUndoCmd ) ) ;
	}
	// --------------------------------
	//	Undo,Redo�֌W�����f�[�^ ���X�V
	//	Undo����Redo���Ɉړ�
	// --------------------------------
	if ( iRv >= 0 )
	{
		m_contUndo.erase( INT_MAX ) ;
		m_contRedo.insert( pCmd ) ;

		if ( m_iModifyCountFromDoc != INT_MAX )
		{
				m_iModifyCountFromDoc -- ;
		}
	}

	// --------------------------------
	//	ModifiedFlag ���X�V
	// --------------------------------
	SetModifiedFlag( m_iModifyCountFromDoc != 0 ) ;
	LogMsg( "CDiagramEditDoc::undo()=" ) ;


	return ( iRv ) ;
}

bool CDiagramEditDoc::canRedo() 
{
	return ( m_contRedo.size() > 0 ) ; 
}

int CDiagramEditDoc::redo() 
{
	LogMsg( "CDiagramEditDoc::redo()" ) ;
	int iRv = 0 ;

	Ou< CRfEditCmd >	pCmd ;
	// --------------------------------
	//	�R�}���h���L���[����擾
	// --------------------------------
	if ( iRv >= 0 ){
		if ( m_contRedo.size() >= 1 ){
			pCmd = m_contRedo.get( INT_MAX ) ;
		}	else	{
			iRv = -1 ;	//	redo ��񂪂���܂���B
		}
	}
	//pcmdUndo = undo �̂��߂̃R�}���h
	// --------------------------------
	//	�R�}���h�����s
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult  = pCmd->execute( &m_CDedRosenFileData ) ;
		if ( iResult < 0 ){
			iRv = -2 ;	//	redo �̎��s�Ɏ��s
		}
	}
	// --------------------------------
	//	�r���[�̍X�V
	// --------------------------------
	if ( iRv >= 0 ){
		UpdateAllSubDocviews( NULL , 0 , 
			&CRfEditCmdHolder( pCmd ) ) ;
	}
	// --------------------------------
	//	Undo,Redo�֌W�����f�[�^ ���X�V
	//	Redo����Undo���Ɉړ�
	// --------------------------------
	if ( iRv >= 0 ){
		m_contRedo.erase( INT_MAX ) ;
		m_contUndo.insert( pCmd ) ;

		if ( m_iModifyCountFromDoc != INT_MAX )
		{
				m_iModifyCountFromDoc ++ ;
		}
	}

	// --------------------------------
	//	ModifiedFlag ���X�V
	// --------------------------------
	SetModifiedFlag( m_iModifyCountFromDoc != 0 ) ;

	LogMsg( "CDiagramEditDoc::redo()=" ) ;
	return ( iRv ) ;
}


// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

IMPLEMENT_DYNCREATE(CDiagramEditDoc, CHidemdiRootDoc)

BEGIN_MESSAGE_MAP(CDiagramEditDoc, CHidemdiRootDoc)
	//{{AFX_MSG_MAP(CDiagramEditDoc)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CDiagramEditDoc::OnUpdateEditUndo)
	ON_COMMAND(ID_EDIT_UNDO, &CDiagramEditDoc::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, &CDiagramEditDoc::OnUpdateEditRedo)
	ON_COMMAND(ID_EDIT_REDO, &CDiagramEditDoc::OnEditRedo)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, &CDiagramEditDoc::OnUpdateFileSaveAs)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagramEditDoc �N���X�̍\�z/����

CDiagramEditDoc::CDiagramEditDoc()
	: m_iModifyCountFromDoc( 0 ) 
{

}

CDiagramEditDoc::~CDiagramEditDoc()
{
}

BOOL CDiagramEditDoc::OnNewDocument()
{
	if (!CHidemdiRootDoc::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




/////////////////////////////////////////////////////////////////////////////
// CDiagramEditDoc �N���X�̐f�f

#ifdef _DEBUG
void CDiagramEditDoc::AssertValid() const
{
	CHidemdiRootDoc::AssertValid();
}

void CDiagramEditDoc::Dump(CDumpContext& dc) const
{
	CHidemdiRootDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiagramEditDoc �R�}���h

void CDiagramEditDoc::DeleteContents() 
{
	m_CDedRosenFileData.clear() ;
	// --------------------------------
	//	Undo,Redo�֌W�����f�[�^ ���X�V
	// --------------------------------
	m_contUndo.erase( 0 , INT_MAX ) ;
	m_contRedo.erase( 0 , INT_MAX ) ;
	m_iModifyCountFromDoc = 0 ;

	// --------------------------------
	//	�H���r���[���X�V
	// --------------------------------
	getCDiagramEditApp()->getCDlgRosenView()->OnUpdate( NULL , 0 , NULL ) ;
	// --------------------------------

	CHidemdiRootDoc::DeleteContents();
}

int CDiagramEditDoc::OnOpenDocument_ConvFile( 
	LPCTSTR lpszDllFilename , 
	std::vector< char >* pbinFileContent , 
	CString* pstrError ) 
{
	int iRv = 0 ;
	CString	strError ;

		if ( iRv >= 0 )
		{
			IfConvFile* pIfConvFile = NULL ;
			CConvFileDll	aCConvFileDll( lpszDllFilename ) ;
			if ( iRv >= 0 )
			{
				int iResult = aCConvFileDll.validate() ;
				if ( iResult < 0 )
				{
					strError = MfcUtil::LoadCString( IDS_ERR_DLLNOTFOUND ) ;
					strError += "\n" ;
					strError += aCConvFileDll.getDllFilename().c_str()  ;
					iRv = -101 ;
				}
				else
				{
					pIfConvFile = aCConvFileDll.getIfConvFile() ;
				}
			}
			//aCConvFileDll = DLL�����[�h���܂����B
	
			LogMsg( "CDiagramEditDoc::OnOpenDocument()31" ) ;
			if ( iRv >= 0 )
			{
				std::vector<char>	binFileContentNew ;
				int iResult = pIfConvFile->isLeftFormat( 
					&CaByteBuffer_vector< std::vector< char > >( pbinFileContent ) ) ;
				LogMsg( "CDiagramEditDoc::OnOpenDocument()32" ) ;
				if ( iResult >= 0 )
				{
					//	FileFormat ���A����DLL�ł��邱�Ƃ��m�F�ł��܂����B
					string strErrorInfoString ;
					int iResult = pIfConvFile->LeftToRight( 
						&CaByteBuffer_vector< std::vector< char > >( pbinFileContent ) , 
						&CaByteBuffer_vector< std::vector< char > >( &binFileContentNew ) , 
						&CaByteBuffer_string( &strErrorInfoString )  ) ;
					if ( iResult >= 0 )
					{
						*pbinFileContent = binFileContentNew ;
					}
					else
					{
						
						strError = MfcUtil::LoadCString( IDS_ERR_FILECONVERT_FAILED ) ;
						strError += "\n" ;
						//strError += aCConvFileDll.getDllFilename().c_str()  ;
						if ( strErrorInfoString.size() > 0 )
						{
							strError += strErrorInfoString.c_str() ;
							strError += "\n" ;
						}
						iRv = -102 ;	//	�t�@�C���̕ϊ��Ɏ��s���܂����B
					}
				}
				else	
				{
					iRv = -1 ;	//����DLL���T�|�[�g����t�@�C���`���ł͂���܂���ł����B
				}
			}
			LogMsg( "CDiagramEditDoc::OnOpenDocument()33" ) ;
		}
	// --------------------------------
	if ( pstrError != NULL )
	{
		*pstrError = strError ;
	}
	return iRv ;
}


BOOL CDiagramEditDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	CWaitCursor	aCWaitCursor ;

	LogMsg( "CDiagramEditDoc::OnOpenDocument(%s)" , lpszPathName ) ;
	//	Serialize �͎g���܂���B
	//
	//if (!CHidemdiRootDoc::OnOpenDocument(lpszPathName))
	//	return FALSE;

	// --------------------------------
	//	�g���q�� .dia �Ȃ�A
	//	WinDIA �̏���
	// --------------------------------
	CdFilenameStr	aCdFilenameStr( lpszPathName ) ;
	if ( stricmp( "dia" , aCdFilenameStr.Extension().c_str() ) == 0 )
	{
		return OnOpenDocument_WinDia( lpszPathName ) ;
	}
	// --------------------------------
	int iRv = 0 ;
	CString	strError ;

	// --------------------------------
	//	�t�@�C���̓��e���Astring�ɕۑ�
	// --------------------------------
	string	strFile ;
	if ( iRv >= 0 )
	{
		int iResult = stringFromFile( &strFile , lpszPathName ) ;
		//iResult = 
		//	-1: �t�@�C�����I�[�v���ł��܂���B
		//	-2 ; �ǂݍ��݂Ɏ��s���܂����B
		//	-3 ; �t�@�C���ɂ� "\0" ���܂܂�܂�(�o�C�i���t�@�C���ł���� 
		//	�v���܂�)�B
		//	 ���̏ꍇ�ApString �ɂ́A "\0" �̒��O�܂ł̃f�[�^���i�[����� 
		//	���܂��B 
		if ( iResult < 0 ){
			iRv = iResult ;
			switch( iResult ){
			 case -1 :	// �t�@�C�����I�[�v���ł��܂���B
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILENOTFOUND ) ;
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -2 :	//; �ǂݍ��݂Ɏ��s���܂����B
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEREAD ) ;
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -3 :	// �t�@�C���ɂ� "\0" ���܂܂�܂�
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEFORMAT ) ;
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			}
			//iRv = 
			//	-1: �t�@�C�����I�[�v���ł��܂���B
			//	-2 ; �ǂݍ��݂Ɏ��s���܂����B
			//	-3 ; �t�@�C���ɂ� "\0" ���܂܂�܂�(�o�C�i���t�@�C���ł���� 
			//	�v���܂�)�B
			//	 ���̏ꍇ�ApString �ɂ́A "\0" �̒��O�܂ł̃f�[�^���i�[����� 
			//	���܂��B 
		}
	}
	//strFile = �t�@�C���̓��e

	string strOudFile = strFile ;
	//strOudFile = �t�@�C���̓��e��ێ����܂��B
	//	�A���A���̃t�@�C���̃t�H�[�}�b�g���Â��ꍇ�́A
	//	����̏����œ��e������܂��B


	LogMsg( "CDiagramEditDoc::OnOpenDocument()1" ) ;



	// --------------------------------
	//	�t�@�C�������ߕs�\�̏ꍇ��
	//	�ϊ������݂܂��B
	// --------------------------------
	CconvCDedRosenFileData	aConv ;
	if ( iRv >= 0 && aConv.isEncodeAbleFormat( strOudFile ) < 0 )
	{
		LogMsg( "CDiagramEditDoc::OnOpenDocument()2" ) ;
		
		bool	bFileTypeDetected = false ;
		std::vector<char>	binFileContent ;
		binFileContent = vectorCharOf( strCrlfOf( strOudFile ) ) ;

		LogMsg( "CDiagramEditDoc::OnOpenDocument()3" ) ;

		// --------------------------------
		//	�t�@�C���ϊ����������s
		// --------------------------------
		const TCHAR* const arstrConvFileDllFilename[] = 
		{
			_T("ConvFileOudia02To03.dll" ),		//	Ver01,Ver02 �� Ver03 �ɕϊ�
			_T(  "ConvFileOudia03To05.dll"  ) , //	Ver03 �� Ver05 �ɕϊ�
			_T( "ConvFileOudia05To06.dll"  ) ,	//	Ver05 �� Ver06 �ɕϊ�
			_T( "ConvFileOudia06To101.dll" ) ,	//	Ver06 �� Ver1.01 �ɕϊ�
			_T( "ConvFileOudia101To102.dll" ) ,	//	Ver1.01 �� Ver1.02 �ɕϊ�
 		};
		for ( int idx = 0 ;
			iRv >= 0 && idx < sizeof(arstrConvFileDllFilename)/sizeof(arstrConvFileDllFilename[0]);
			idx ++ )
		{
			iRv = OnOpenDocument_ConvFile( 
				arstrConvFileDllFilename[idx], 
				&binFileContent , 
				&strError ) ;
			if ( iRv == -1 )
			{
				//	�t�H�[�}�b�g���F���ł��Ȃ��ꍇ�́A
				//	���̃t�H�[�}�b�g�ϊ������s���邽�߁A
				//	�G���[�ɂ͂��܂���B
				iRv = 0 ;	
			}
			else
			{
				bFileTypeDetected = true ;
			}
		}

		// --------------------------------
		if ( iRv >= 0 && !bFileTypeDetected )
		{
			strError.Format( MfcUtil::LoadCString( IDS_ERR_FILEFORMAT ) , 
					lpszPathName ) ;
			iRv = -31 ;	// FileType���F���ł��܂���B
				//iRv = 
				//	-31 ; // FileType���F���ł��܂���B
		}
		if ( iRv >= 0 )
		{
			strOudFile = strLfOf( stringOf( binFileContent ) ) ;
		}
		LogMsg( "CDiagramEditDoc::OnOpenDocument()101" ) ;
	}
	//strOudFile = ���o�[�W�����t�@�C������ϊ���̓��e�ɕς��܂����B

	// --------------------------------
	//	CDedRosenFileData
	//	�J�����g�o�[�W�����t�@�C��
	//	aString �t�@�C���̓��e�����߂��܂��B
	// --------------------------------
	if ( iRv >= 0 )
	{
		CDedRosenFileData	aCDedRosenFileData ;
		CconvCDedRosenFileData aConv ;
		COuErrorInfoContainer aCOuErrorInfoContainer ;
		int iResult = aConv.CDedRosenFileData_from_string( 
			&aCDedRosenFileData , 
			strOudFile , 
			&aCOuErrorInfoContainer ) ;
		//iResult = 
		//	-	-1 ;	//	�f�B���N�g�����r���ŕ��Ă��܂��B	
		//	-	-1001 ;	//	FileType ������������܂���B
		//	-	-1002 ;	//	Rosen Directory��������܂���B
		//	-	-1022 ;	//	Ekijikokukeisiki �̒l���s���ł��B
		//	-	-1032 ;	//	Ekikibo �̒l���s���ł��B
		//	-	-1101 ;	//	Eki ���f�B���N�g���ł͂���܂���B
		//	-	-1111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
		//	-	-1152 ;	//	DiagramSenStyle �̒l���s���ł��B
		//	-	-1201 ;	//	Ressyasyubetsu ���f�B���N�g���ł͂���܂���B
		//	-	-1211 ;	//	DiaName ���w�肳��Ă��܂���B
		//	-	-1212 ;	//	RessyaCont��������܂���B
		//	-	-1352 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
		//	-	-1003 ;	//	DispProp Directory��������܂���B
		//	-	-1512 ;	//	JikokuhyouFont �̓��e���s���ł��B
		//	-	-1522 ;	//	DiaEkimeiFont �̓��e���s���ł��B
		//	-	-1532 ;	//	DiaJikokuFont �̓��e���s���ł��B
		//	-	-1582 ;	//	DisplayRessyabangou ���s���ł��B
		//	-	-1592 ;	//	DisplayRessyamei ���s���ł��B
		//	-	-1602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
		//	-	-1612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B
		if ( iResult < 0 )
		{
			iRv = iResult ;
			//iRv = 
			//	-	-1 ;	//	�f�B���N�g�����r���ŕ��Ă��܂��B	
			//	-	-1001 ;	//	FileType ������������܂���B
			//	-	-1002 ;	//	Rosen Directory��������܂���B
			//	-	-1022 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			//	-	-1032 ;	//	Ekikibo �̒l���s���ł��B
			//	-	-1101 ;	//	Eki ���f�B���N�g���ł͂���܂���B
			//	-	-1111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			//	-	-1152 ;	//	DiagramSenStyle �̒l���s���ł��B
			//	-	-1201 ;	//	Ressyasyubetsu ���f�B���N�g���ł͂���܂���B
			//	-	-1211 ;	//	DiaName ���w�肳��Ă��܂���B
			//	-	-1212 ;	//	RessyaCont��������܂���B
			//	-	-1352 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
			//	-	-1003 ;	//	DispProp Directory��������܂���B
			//	-	-1512 ;	//	JikokuhyouFont �̓��e���s���ł��B
			//	-	-1522 ;	//	DiaEkimeiFont �̓��e���s���ł��B
			//	-	-1532 ;	//	DiaJikokuFont �̓��e���s���ł��B
			//	-	-1582 ;	//	DisplayRessyabangou ���s���ł��B
			//	-	-1592 ;	//	DisplayRessyamei ���s���ł��B
			//	-	-1602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
			//	-	-1612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B

			{
				CString	strFmt ;
				strFmt.LoadString( IDS_ERR_FILEFORMAT_ERRORCODE ) ;
				strError.Format( strFmt , lpszPathName , iRv ) ;
			}

			string strOuErrorInfoText = aCOuErrorInfoContainer.toOuErrorInfoText() ;
			if ( !strOuErrorInfoText.empty() )
			{
				strError += "\n\n" ;
				strError += "(" ;
				strError += strOuErrorInfoText.c_str() ;
				strError += ")" ;
			}

		}
		else
		{
			m_CDedRosenFileData = aCDedRosenFileData ;
		}
	}


	// --------------------------------
	//	�H���r���[���X�V
	// --------------------------------
	getCDiagramEditApp()->getCDlgRosenView()->OnUpdate( NULL , 0 , NULL ) ;
	// --------------------------------
	//	�G���[���b�Z�[�W�̕\��
	// --------------------------------
	LogMsg( "CDiagramEditDoc::OnOpenDocument()=%d" , iRv ) ;
	if ( iRv < 0 )
	{
		string strFileTypeAppComment ;
		//	strFileTypeAppComment ���擾
		CNodeContainer aCNodeContainer ;
		CConvNodeContainer aCConvNodeContainer ;
		int iResult = aCConvNodeContainer.decode( 
			strFile , 
			&aCNodeContainer ) ;
		if ( iResult >= 0 )
		{
			strFileTypeAppComment = aCNodeContainer.getValue( nameFileTypeAppComment );
		}
		//strFileTypeAppComment = ���ږ� FileTypeAppComment �̓��e

		
		if ( strError.IsEmpty() )
		{
			CString	strFmt ;
			strFmt.LoadString( IDS_ERR_ERRORCODE ) ;
			strError.Format( strFmt , iRv ) ;
		}
		if ( !strFileTypeAppComment.empty() )
		{
			CString strFmt ;
			strFmt.LoadString( IDS_ERR_FileTypeAppComment ) ;
			CString strLs ;
			strLs.Format( strFmt , strFileTypeAppComment.c_str() ) ;
			strError += "\n\n(" ;
			strError += strLs ;
			strError += ")" ;

		}
		AfxMessageBox( strError , MB_ICONSTOP ) ; 
	}
	return ( iRv >= 0 ) ;
}
BOOL CDiagramEditDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	CWaitCursor	aCWaitCursor ;

	
	LogMsg( "CDiagramEditDoc::OnSaveDocument(%s)" , lpszPathName ) ;
	//Serialize() �͎g���܂���B
	//
	//return CHidemdiRootDoc::OnSaveDocument(lpszPathName);


	// --------------------------------
	//	�g���q�� .dia �Ȃ�A
	//	WinDIA �̏���
	// --------------------------------
	CdFilenameStr	aCdFilenameStr( lpszPathName ) ;
	if ( stricmp( "dia" , aCdFilenameStr.Extension().c_str() ) == 0 )
	{
		return OnSaveDocument_WinDia( lpszPathName ) ;
	}
	// --------------------------------
	int iRv = 0 ;

	CString strError ;

	// --------------------------------
	//	�t�@�C���̓��e��CdConnectedString2���쐬
	// --------------------------------
	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData aConv ;
		int iResult = aConv.CDedRosenFileData_to_OuPropertiesText( 
			&m_CDedRosenFileData , 
			&aCNodeContainer ) ;
		//iResult = 
		//		-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
		//		-	-32 ;	//	Ekikibo �̒l���s���ł��B
		//		-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
		//		-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
		//		-	-212 ;	//	DiagramEkiatsukai �̒l���s���ł��B
		if ( iResult < 0 )
		{
			iRv = iResult ;
			strError.Format( IDS_ERR_FILEFORMAT , lpszPathName ) ;
			//iRv = 
			//		-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			//		-	-32 ;	//	Ekikibo �̒l���s���ł��B
			//		-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			//		-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
			//		-	-212 ;	//	DiagramEkiatsukai �̒l���s���ł��B
		}
	}	
	//aString = �t�@�C���ɏ������ށw�H���t�@�C���x�`���̕������ێ����܂��B

	LogMsg( "CDiagramEditDoc::OnSaveDocument()1" ) ;

	// --------------------------------
	//	FileTypeAppComment ��t�^
	// --------------------------------
	if ( iRv >= 0 )
	{
		string strFileTypeAppComment ;
		strFileTypeAppComment += AfxGetAppName() ;
		strFileTypeAppComment += " Ver. " ;
		strFileTypeAppComment += getCDiagramEditApp()->getProgramVer() ;
		aCNodeContainer.setValue( nameFileTypeAppComment , strFileTypeAppComment );
	}
	
	// --------------------------------
	//	aCNodeContainer �̓��e��
	//	������Ɋi�[
	// --------------------------------
	string aString ;
	if ( iRv >= 0 ){
		//	CConnectedStringCompress �ɂ�鈳�k
		CConvNodeContainer aCConvNodeContainer ;
		aString = aCConvNodeContainer.encode( &aCNodeContainer ) ;
	}
	//	aString = �t�@�C���ɏo�͂��镶����

	// --------------------------------
	//	string�̓��e���A�t�@�C���ɏ�������
	// --------------------------------
	if ( iRv >= 0 ){
		int iResult = stringToFile( aString , lpszPathName ) ;
		//iResult = 
		//	-1: �t�@�C�����I�[�v���ł��܂���B
		//	-2 ; // �������݂Ɏ��s���܂����B 
		if ( iResult < 0 ){
			iRv = iResult ;
			switch( iResult ){
			 case -1 :	// �t�@�C�����I�[�v���ł��܂���B
				{
					CString	strFmt ;
					strError.Format( IDS_ERR_FILECREATE , lpszPathName ) ;
				}
				break ;
			 case -2 :	//;�������݂Ɏ��s���܂���
				{
					CString	strFmt ;
					strError.Format( IDS_ERR_FILEWRITE , lpszPathName ) ;
				}
				break ;
			}
			//iRv = 
			//	-1: �t�@�C�����I�[�v���ł��܂���B
			//	-2 ; �������݂Ɏ��s���܂����B
		}
	}

	// --------------------------------
	LogMsg( "CDiagramEditDoc::OnSaveDocument()=%d" , iRv ) ;

	if ( iRv < 0 )
	{
		if ( strError.IsEmpty() )
		{
			CString	strFmt ;
			strFmt.LoadString( IDS_ERR_ERRORCODE ) ;
			strError.Format( strFmt , iRv ) ;
		}
		AfxMessageBox( strError , MB_ICONSTOP ) ; 
		return ( FALSE ) ;
	}
	//	�ۑ��ɐ���������A�����I��
	//	�ύX�t���O���������Ȃ��Ă͂Ȃ�܂���B

	// --------------------------------
	//	Undo,Redo�֌W�����f�[�^ ���X�V
	//	Undo����Redo���Ɉړ�
	// --------------------------------
	if ( iRv >= 0 )
	{
		m_iModifyCountFromDoc = 0 ;
	}

	// --------------------------------
	//	ModifiedFlag ���X�V
	// --------------------------------
	SetModifiedFlag( m_iModifyCountFromDoc != 0 ) ;
	return TRUE;
}

void CDiagramEditDoc::OnFileSaveAs() 
{
	CString	strExt ;
	getCDiagramEditApp()->pRootDoctmpl()->GetDocString( strExt , CDocTemplate::filterExt ) ;

	CFileDialog	aDlg( FALSE , strExt , 	GetPathName()  , 
	  OFN_HIDEREADONLY | OFN_PATHMUSTEXIST
	  | OFN_OVERWRITEPROMPT , 
		getCDiagramEditApp()->getCFileDialogFilter() , NULL ) ;
	if ( aDlg.DoModal() != IDOK )
	{
		return ;
	}	
	// --------------------------------
	DoSave(aDlg.GetPathName(), TRUE ) ;
}



void CDiagramEditDoc::OnUpdateFileSaveAs(CCmdUI *pCmdUI)
{
	//	���O��t���ĕۑ� �́A�펞�L���ɂ��܂����B
	pCmdUI->Enable( TRUE ) ;
}

void CDiagramEditDoc::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU) 
{
	CdFilenameStr	aCdFilenameStr( lpszPathName ) ;
	if ( stricmp( "dia" , aCdFilenameStr.Extension().c_str() ) == 0 )
	{
		//	�g���q .dia �́A�h�L�������g�̗L���ȃt�@�C�����Ƃ�
		//	�F�߂܂���B
		//	�������A�h�L�������g�̃^�C�g���Ƃ��āA
		//	�g���q����菜������t�@�C������ݒ肵�܂��B

		if ( GetTitle().IsEmpty() )
		{
			SetTitle(aCdFilenameStr.BaseFilename().c_str() );
		}
		return ;
	}	
	
	CHidemdiRootDoc::SetPathName(aCdFilenameStr.FullpathFilename().c_str() , bAddToMRU);
}

void CDiagramEditDoc::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	BOOL bEnable = FALSE ;
	{
		bEnable = this->canUndo() ;
	}
	pCmdUI->Enable( bEnable ) ;	
}

void CDiagramEditDoc::OnEditUndo()
{
	this->undo() ;
}

void CDiagramEditDoc::OnUpdateEditRedo(CCmdUI *pCmdUI)
{
	BOOL bEnable = FALSE ;
	{
		bEnable = this->canRedo() ;
	}
	pCmdUI->Enable( bEnable ) ;	
}

void CDiagramEditDoc::OnEditRedo()
{
	this->redo() ;
}
