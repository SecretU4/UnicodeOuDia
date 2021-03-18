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
// DiagramEdit.cpp : �A�v���P�[�V�����p�N���X�̋@�\��`���s���܂��B
//$Id: DiagramEdit.cpp 418 2017-01-21 05:00:05Z okm $ 
/** @file */
#include "stdafx.h"


#include "str\strToInt.h"
#include "str\strToWstr.h"
#include "str\tstring.h"
#include "str\strprintf.h"
#include "dir\Directries.h"
#include "MfcUtil\MfcUtil.h"

#include "DiagramEdit.h"
#include "resource.h"
#include "CAboutBoxGpl.h"

#include "CDiagramEditDoc.h"
#include "CDiagramEditDoctmpl.h"

#include "entDed\CdDedJikoku.h"
#include "entDed\CdDedJikan.h"

#include "ViewEki\CEkiDoc.h"
#include "ViewEki\CEkiView.h"
#include "ViewRessyasyubetsu\CRessyasyubetsuDoc.h"
#include "ViewRessyasyubetsu\CRessyasyubetsuView.h"
#include "ViewJikokuhyou\CJikokuhyouDoc.h"
#include "ViewJikokuhyou\CJikokuhyouView.h"
#include "ViewDiagram\CDedDiagramDoc.h"
#include "ViewDiagram\CDedDiagramView.h"
#include "ViewComment\CDedCommentView.h"

#include "Print\CDlgPrintPageProp.h"
#include "ConvJikokuhyouCsv\CconvJikokuhyouCsv.h"

using namespace std ;
using namespace OuMfc;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CDiagramEditApp
const TCHAR nameSection[] = _T( "AppProp" ) ;
const TCHAR namePrintPageProp[] = _T( "PrintPageProp" ) ;
const TCHAR nameLogLevel[] = _T( "LogLevel" ) ;

	// ================================
	//	�����֐�
	// ================================
void CDiagramEditApp::readVersionResource( 
		string* pstrFileVersion , 
		string* pstrLegalCopyright )
{

	vector<char>	szInfo ;
	{
		TCHAR	szExeName[MAX_PATH] ;
		GetModuleFileName( NULL , szExeName , 
			sizeof(szExeName)/sizeof(szExeName[0]) ) ;
		DWORD	dwValue = 0 ;
		DWORD dwSize = GetFileVersionInfoSize( szExeName , &dwValue ) ;
		if ( dwSize > 0 )
		{ 
			szInfo.resize( dwSize ) ; 
			GetFileVersionInfo( szExeName , NULL , dwSize , &szInfo[0] ) ;
		}
	}
	string strFileVersion ;
	if ( szInfo.size() > 0 )
	{
		WORD	awVersion[4] = { 0 , 0 , 0 , 0 } ;
		VS_FIXEDFILEINFO*	pVS_FIXEDFILEINFO = NULL ;
		UINT uiLen = 0 ;
		VerQueryValue( &szInfo[0] , _T( "\\" ) , 
			(void**)&pVS_FIXEDFILEINFO , 
			&uiLen ) ;
		awVersion[0] = HIWORD( pVS_FIXEDFILEINFO->dwFileVersionMS ) ;
		awVersion[1] = LOWORD( pVS_FIXEDFILEINFO->dwFileVersionMS ) ;
		awVersion[2] = HIWORD( pVS_FIXEDFILEINFO->dwFileVersionLS ) ;
		awVersion[3] = LOWORD( pVS_FIXEDFILEINFO->dwFileVersionLS ) ;

		//	�o�[�W�����𕶎���
		int idxLength = 0 ;
		for ( idxLength = sizeof(awVersion) / sizeof(awVersion[0]) ;
			idxLength > 2 && awVersion[idxLength-1] == 0 ;
			idxLength -- ){}
		//idxLength = awVersion[] ����A������0���������v�f��
		//	�o�[�W������ 1.2.3.4 �Ȃ�A idxLength = 4
		//	�o�[�W������ 1.2.3.0 �Ȃ�A idxLength = 3
		for ( int idx = 0 ; idx < idxLength ; idx ++ )
		{
			if ( !strFileVersion.empty() )
			{
				strFileVersion += "." ;
			}

			if ( idx == 0 )
			{
				strFileVersion += strprintf( "%d" , awVersion[idx] ) ;
			}
			else
			{
				strFileVersion += strprintf( "%02d" , awVersion[idx] ) ;
			}
		}
	}
	string strLegalCopyright ;
	if ( szInfo.size() > 0 )
	{
		UINT uiLen = 0 ;
		const char* lpszLegalCopyright ;
		VerQueryValue( &szInfo[0] , _T( "\\StringFileInfo\\041104b0\\LegalCopyright" ) 
			, (void**)&lpszLegalCopyright , &uiLen ) ; 
		if ( uiLen > 0 )
		{
			strLegalCopyright = lpszLegalCopyright ;
		}
	}
	if ( pstrFileVersion != NULL ){	*pstrFileVersion = strFileVersion ;}
	if ( pstrLegalCopyright != NULL ){ *pstrLegalCopyright = strLegalCopyright ;}

}
	// ********************************
	//@name CDiagramEditApp-����
	// ********************************
std::string CDiagramEditApp::getProgramVer()const 
{
	string strFileVersion ;
	readVersionResource( &strFileVersion , NULL  ) ; 
	return strFileVersion ;
}


// ********************************
//	CDiagramEditApp
// ********************************
CMainFrame*	CDiagramEditApp::getCMainFrame() 
{
	return ( (CMainFrame*)m_pMainWnd ) ;
}

CDlgRosenView*	CDiagramEditApp::getCDlgRosenView() 
{
	return ( getCMainFrame()->getCDlgRosenView() ) ;
}

CEkiDoc* CDiagramEditApp::openCEkiDoc( CEkiView** ppEkiView )
{
	if ( ppEkiView != NULL )
	{
		*ppEkiView = NULL ;
	}
	// --------------------------------
	CEkiDoc* pEkiDoc = (CEkiDoc*)m_pdoctmplEki->OpenDocumentFile( NULL ) ;

	if ( pEkiDoc != NULL && ppEkiView != NULL )
	{

		POSITION aPOSITION = pEkiDoc->GetFirstViewPosition() ;
		if ( aPOSITION != NULL ){
			*ppEkiView = (CEkiView*)pEkiDoc->GetNextView( aPOSITION ) ;
		}
	}
	return pEkiDoc ;
}

CRessyasyubetsuDoc* CDiagramEditApp::openCRessyasyubetsuDoc() 
{
	return (CRessyasyubetsuDoc*)m_pdoctmplResssyasyubetsu->OpenDocumentFile( NULL ) ;
}

CJikokuhyouDoc* CDiagramEditApp::openCJikokuhyouDoc( 
	const CentDedDia* pCentDedDia , 
	ERessyahoukou eRessyahoukou ,
	CJikokuhyouView** ppJikokuhyouView ) 
{
	int iRv = 0 ;
	CJikokuhyouDoc*	pCJikokuhyouDoc = NULL ;
	if ( ppJikokuhyouView != NULL )
	{
		*ppJikokuhyouView = NULL ;
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		const CentDedRosen* pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		int idx = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( pCentDedDia->getName() ) ;
		if ( idx < 0 )
		{
			iRv = -1 ;	//	pCentDedDia ��������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		CString	strDocument ;
		strDocument.Format( "%s\n%d" , pCentDedDia->getName().c_str() , 
			(int)eRessyahoukou ) ;
		//strDocument= pCentDedDia �ɑΉ�����"<�_�C����>\n<��ԕ���>"
		
		CDocument*	pCDocument = m_pdoctmplJikokuhyou->OpenDocumentFile( strDocument ) ;
		if ( pCDocument != NULL )
		{
			pCJikokuhyouDoc = (CJikokuhyouDoc*)pCDocument ;
		}
		else
		{
			iRv = -2 ; //	pCentDedDia �ɑΉ����鎞���\�r���[���J���܂���B
		}
	}
	//pCJikokuhyouDoc = CJikokuhyouDoc�ւ̃|�C���^
	if ( iRv >= 0 && ppJikokuhyouView != NULL )
	{
		POSITION aPOSITION = pCJikokuhyouDoc->GetFirstViewPosition() ;
		if ( aPOSITION != NULL ){
			*ppJikokuhyouView = (CJikokuhyouView*)pCJikokuhyouDoc
				->GetNextView( aPOSITION ) ;
		}
	}

	return ( pCJikokuhyouDoc ) ;
}

CDedDiagramDoc* CDiagramEditApp::openCDedDiagramDoc( const CentDedDia* pCentDedDia )
{
	const CentDedRosen* pCentDedRosen = 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;

	int idx = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( pCentDedDia->getName() ) ;
	if ( idx < 0 ){
		return NULL ;
	}

	CString	strDocument = pCentDedDia->getName().c_str() ;
	CDocument*	pCDocument = m_pdoctmplDiagram->OpenDocumentFile( strDocument ) ;
	
	return ( (CDedDiagramDoc*)pCDocument ) ;

}

CDedCommentDoc* CDiagramEditApp::openCDedCommentDoc() 
{
	return (CDedCommentDoc*)m_pdoctmplComment->OpenDocumentFile( NULL ) ;
}



CString CDiagramEditApp::getCFileDialogFilter()
{
	CString	strWinDIAFilter ;
	strWinDIAFilter.LoadString( IDS_WinDIAFilter ) ;

	CString	strFilter ;
	//OuDia
	{
		CString	strFilterName ;
		pRootDoctmpl()->GetDocString( strFilterName , CDocTemplate::filterName ) ;
		CString	strExt ;
		pRootDoctmpl()->GetDocString( strExt , CDocTemplate::filterExt ) ;
		strFilter += strFilterName ;
		strFilter += _T( "|*" )  ;
		strFilter += strExt ;
		strFilter += _T( "|" )  ;
	}
	//WinDIA
	{
		strFilter += strWinDIAFilter ;
	}
	//all
	{
		CString allFilter;
		VERIFY(allFilter.LoadString(AFX_IDS_ALLFILTER));
		strFilter += allFilter;
		strFilter += _T( "|" ) ;
		strFilter += _T("*.*");
		strFilter += _T( "||" ) ;
	}
	return ( strFilter ) ;
}

CString CDiagramEditApp::getCFileDialogOudFilter()
{
	CString	strFilter ;
	//OuDia
	{
		CString	strFilterName ;
		pRootDoctmpl()->GetDocString( strFilterName , CDocTemplate::filterName ) ;
		CString	strExt ;
		pRootDoctmpl()->GetDocString( strExt , CDocTemplate::filterExt ) ;
		strFilter += strFilterName ;
		strFilter += _T( "|*" )  ;
		strFilter += strExt ;
		strFilter += _T( "|" )  ;
	}
	//all
	{
		CString allFilter;
		VERIFY(allFilter.LoadString(AFX_IDS_ALLFILTER));
		strFilter += allFilter;
		strFilter += _T( "|" ) ;
		strFilter += _T("*.*");
		strFilter += _T( "||" ) ;
	}
	return ( strFilter ) ;
}

CString CDiagramEditApp::getCFileDialogFilterCsv() 
{
	CString	strWinDIAFilter ;
	strWinDIAFilter.LoadString( IDS_WinDIAFilter ) ;

	CString	strFilter ;
	//CSV
	{
		strFilter += MfcUtil::LoadCString( IDS_CSVFilter )  ;
	}
	//all
	{
		CString allFilter;
		VERIFY(allFilter.LoadString(AFX_IDS_ALLFILTER));
		strFilter += allFilter;
		strFilter += _T( "|" ) ;
		strFilter += _T("*.*");
		strFilter += _T( "||" ) ;
	}
	return ( strFilter ) ;
}

CconvJikokuhyouCsv CDiagramEditApp::createCconvJikokuhyouCsv() 
{
	return	CconvJikokuhyouCsv( 
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_Kudari ) , 
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_Nobori ) , 
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_Ressyabangou ) , 
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_RESSYASYUBETSU ) ,
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_Ressyamei ) ,
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_Gousuu ) ,
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_GOUSUU2 ) ,
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_Bikou ) ,
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_Chaku ) ,
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_Hatsu ) ,
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_JIKOKUHYOU_TSUUKA ) , 
		(LPCSTR)MfcUtil::LoadCString( IDS_WORD_JIKOKUHYOU_KEIYUNASI ) //"||"
	);	

}
	// ********************************
	//@name	���� - �t�@�C����
	// ********************************
CString CDiagramEditApp::makeProgramDirFilename( const CString& strFilename ) 
{
	CString	strProgramDir ;
	{
		TCHAR	szExe[MAX_PATH] ;
		GetModuleFileName( NULL , szExe , sizeof(szExe) ) ;
		strProgramDir = szExe ;
		int idx = strProgramDir.ReverseFind( _T( '\\' ) ) ;
		strProgramDir = strProgramDir.Left( idx + 1 ) ;
	}
	//strProgramDir = .exe �t�@�C���̂���f�B���N�g��(��:"c:\program files\oudia\" )�B

	if ( strFilename.GetLength() > 0 )
	{
		strProgramDir += strFilename ;
	}
	return strProgramDir ;
}

CString CDiagramEditApp::makeLocalAppdataFilename( const CString& strFilename ) 
{
	CString	strLocalAppdataFolder ;
	{
		TCHAR	szPath[MAX_PATH] ;
		BOOL bResult = SHGetSpecialFolderPath( 
			NULL , 
			szPath , 
			CSIDL_LOCAL_APPDATA , 
			TRUE ) ;
		if ( bResult )
		{
			strLocalAppdataFolder = szPath ;
		}
		else
		{
			GetTempPath( sizeof(szPath) / sizeof(szPath[0] ) , szPath ) ;
			strLocalAppdataFolder = szPath ;
		}
		//	������ '\\' ������ꍇ�́A������폜
		if ( strLocalAppdataFolder.GetLength() > 0 && 
			strLocalAppdataFolder[ strLocalAppdataFolder.GetLength() - 1 ] 
				== _T( '\\' ) )
		{
			strLocalAppdataFolder.Delete( 
				strLocalAppdataFolder.GetLength() - 1 ) ;
		}
	}
	//strLocalAppdataFolder = LocalAppData(�擾�ł��Ȃ���΃e���|�����f�B���N�g��)
	//	�����ɂ� '\' �͂���܂���B

	strLocalAppdataFolder += _T( "\\OuDia\\" ) ;
	//strLocalAppdataFolder = OuDia��LocalAppData�t�H���_�B
	//	�����ɂ� '\\' ������܂��B
	//	���̃f�B���N�g���́A�쐬����Ă��܂��B

	if ( strFilename.GetLength() > 0 )
	{
		strLocalAppdataFolder += strFilename ;
	}
	return strLocalAppdataFolder ;
}


CString CDiagramEditApp::makeHtmlHelpUrl( const CString& strTopic ) 
{
	CString strHtmlHelpUrl = makeProgramDirFilename( _T( "oudia.chm" ) ) ;
	if ( !strTopic.IsEmpty() )
	{
		strHtmlHelpUrl += _T( "::" ) ;
		strHtmlHelpUrl += strTopic ;
	}
	return strHtmlHelpUrl ;
}


	// ********************************
	//@name	����- .ini �t�@�C��
	// ********************************
const TCHAR nameCWndDiagram_DiagramPosDgr[] = "DiagramPosDgr" ;
const TCHAR nameCWndDiagram_DcdPerDgrX[] = "DcdPerDgrX" ;
const TCHAR nameCWndDiagram_DcdPerDgrY[] = "DcdPerDgrY" ;

const TCHAR nameCWndDiagram_VlineMode[] = "DiagramVlineMode" ;
const TCHAR nameCWndDiagram_DisplayRessyabangou[] = 
	"DiagramDisplayRessyabangou" ;
const TCHAR nameCWndDiagram_DisplayRessyamei[] = 
	"DiagramDisplayRessyamei" ;
const TCHAR nameCWndDiagram_DisplayRessyasen[] = 
	"DiagramDisplayRessyasen" ;
const TCHAR nameCWndDiagram_HideIppanekiEkimei[] = 
	"DiagramHideIppanekiEkimei" ;
const TCHAR nameCWndDiagram_StopMarkDraw[] = 
	"DiagramStopMarkDraw" ;
const TCHAR nameCWndDiagram_KeepZoneDgrOnSize[] = 
	"DiagramKeepZoneDgrOnSize" ;

int CDiagramEditApp::writeCWndDiagramViewProp( const CWndDiagram* pCWndDiagram )
{
	int iRv = 0 ;
	
	//�������擾
	CdDcdPosXy	posPosDgr = pCWndDiagram->getPosDgr() ;
	double	dDcdPerDgrX = pCWndDiagram->getDcdPerDgrX() ;
	double	dDcdPerDgrY = pCWndDiagram->getDcdPerDgrY() ;

	int idxVlineMode = pCWndDiagram->getVlineMode() ;
	bool	bDisplayRessyabangou = pCWndDiagram->getDisplayRessyabangou() ;
	bool	bDisplayRessyamei = pCWndDiagram->getDisplayRessyamei() ;
	bool bDisplayRessyasenKudari = 
		pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Kudari ) ;
	bool bDisplayRessyasenNobori = 
		pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Nobori ) ;
	bool bHideIppanekiEkimei = 
		pCWndDiagram->getHideIppanekiEkimei() ;
	CDcdDiagram::EStopMarkDraw eStopMarkDraw = pCWndDiagram->getStopMarkDraw() ;
	bool bKeepZoneDgrOnSize = pCWndDiagram->getKeepZoneDgrOnSize() ;
	// --------------------------------
	//DiagramPosDgr
	if ( iRv >= 0 )
	{
		string	strValue ;
		strValue += stringOf( posPosDgr.getX() ) ;
		strValue += ',' ;
		strValue += stringOf( posPosDgr.getY() ) ;
		WriteProfileString( 
			nameSection , 
			nameCWndDiagram_DiagramPosDgr , 
			strValue.c_str() ) ;
	}
	//"DcdPerDgrX" ;
	{
		string	strValue ;
		strValue += stringOf( dDcdPerDgrX ) ;
		WriteProfileString( 
			nameSection , 
			nameCWndDiagram_DcdPerDgrX , 
			strValue.c_str() ) ;
	}

	//"DcdPerDgrY" ;
	{
		string	strValue ;
		strValue += stringOf( dDcdPerDgrY ) ;
		WriteProfileString( 
			nameSection , 
			nameCWndDiagram_DcdPerDgrY , 
			strValue.c_str() ) ;
	}


	//DiagramVlineMode
	if ( iRv >= 0 ){
		string	strValue ;
		strValue += stringOf( idxVlineMode ) ;
		WriteProfileString( nameSection , nameCWndDiagram_VlineMode , 
			strValue.c_str() ) ;
	}
	
	//DisplayRessyabangou
	if ( iRv >= 0 ){
		string	strValue ;
		strValue += stringOf( bDisplayRessyabangou ) ;
		WriteProfileString( nameSection , nameCWndDiagram_DisplayRessyabangou ,
			strValue.c_str() ) ;
	}
	
	//DisplayRessyamei
	if ( iRv >= 0 ){
		string	strValue ;
		strValue += stringOf( bDisplayRessyamei ) ;
		WriteProfileString( nameSection , nameCWndDiagram_DisplayRessyamei ,
			strValue.c_str() ) ;
	}
	
	//DisplayRessyasen
	if ( iRv >= 0 ){
		string	strValue ;
		strValue += ( bDisplayRessyasenKudari ? "1" : "0" ) ;
		strValue += ',' ;
		strValue += ( bDisplayRessyasenNobori ? "1" : "0" ) ;
		WriteProfileString( nameSection , nameCWndDiagram_DisplayRessyasen ,
			strValue.c_str() ) ;
	}
	//DiagramHideIppanekiEkimei
	if ( iRv >= 0 )
	{
		string	strValue = ( bHideIppanekiEkimei ? "1" : "0" ) ;
		WriteProfileString( nameSection , nameCWndDiagram_HideIppanekiEkimei ,
			strValue.c_str() ) ;
	}
	//DiagramStopMarkDraw
	if ( iRv >= 0 )
	{
		string strValue = stringOf( (int)eStopMarkDraw ) ;
		WriteProfileString( nameSection , nameCWndDiagram_StopMarkDraw , 
			strValue.c_str() ) ;
	}
	//DiagramKeepZoneDgrOnSize
	if ( iRv >= 0 )
	{
		string strValue = ( bKeepZoneDgrOnSize ? "1" : "0" ) ;
		WriteProfileString( nameSection , nameCWndDiagram_KeepZoneDgrOnSize ,
			strValue.c_str() ) ;
	}
	return ( iRv ) ;
}

int CDiagramEditApp::readCWndDiagramViewProp( CWndDiagram* pCWndDiagram ) 
{
	int iRv = 0 ;

	CdDcdPosXy	posPosDgr( 0 , 0 ) ;
	double	dDcdPerDgrX = CDcdDiagram::DEFAULT_DCD_PER_DGR_X() ;
	double	dDcdPerDgrY = CDcdDiagram::DEFAULT_DCD_PER_DGR_Y() ;

	int idxVlineMode = 1 ;
	bool bDisplayRessyabangou = false ;
	bool bDisplayRessyamei = false ;
	bool bDisplayRessyasenKudari = true ;
	bool bDisplayRessyasenNobori = true ;
	bool bHideIppanekiEkimei = false ;
	CDcdDiagram::EStopMarkDraw eStopMarkDraw = CDcdDiagram::EStopMarkDraw_Nothing ;
	bool bKeepZoneDgrOnSize = false ;
	// --------------------------------
	//DiagramPosDgr
	if ( iRv >= 0 )
	{
		string	strValue = GetProfileString( nameSection , 
			nameCWndDiagram_DiagramPosDgr ) ;
		deque<string>	contstrValue = 
			splitc< deque< string > >( ',' , strValue ) ;
		if ( contstrValue.size() != 2 )
		{
			iRv = -1 ;	//	DiagramPosDgr ���w�肳��Ă��܂���B
		}
		else
		{
			int iXPos  = intOf( contstrValue[0] ) ;
			int iYPos  = intOf( contstrValue[1] ) ;
			posPosDgr.setX( iXPos ).setY( iYPos ) ;
		}
	}
	//DcdPerDgrX
	if ( iRv >= 0 ){
		string	strValue = GetProfileString( nameSection , 
			nameCWndDiagram_DcdPerDgrX ) ;
		if ( strValue.empty() ){
			iRv = -2 ;	//	DcdPerDgrX ���w�肳��Ă��܂���B
		}	else	{
			dDcdPerDgrX = doubleOf( strValue ) ; 
		}
	}
	//DcdPerDgrY
	if ( iRv >= 0 ){
		string	strValue = GetProfileString( nameSection , 
			nameCWndDiagram_DcdPerDgrY ) ;
		if ( strValue.empty() ){
			iRv = -2 ;	//	DcdPerDgrY ���w�肳��Ă��܂���B
		}	else	{
			dDcdPerDgrY = doubleOf( strValue ) ; 
		}
	}



	//DiagramVlineMode
	if ( iRv >= 0 ){
		string	strValue = GetProfileString( nameSection , 
			nameCWndDiagram_VlineMode ) ;
		if ( strValue.empty() ){
			iRv = -2 ;	//	DiagramVlineMode ���w�肳��Ă��܂���B
		}	else	{
			idxVlineMode = intOf( strValue ) ; 
		}
	}

	//DisplayRessyabangou
	if ( iRv >= 0 )
	{
		string	strValue = GetProfileString( nameSection , 
			nameCWndDiagram_DisplayRessyabangou ) ;
		if ( strValue.empty() )
		{
			iRv = -3 ;	//	DisplayRessyabangou ���w�肳��Ă��܂���B
		}
		else
		{
			bDisplayRessyabangou = ( intOf( strValue ) != 0 ); 
		}
	}

	//DisplayRessyamei
	if ( iRv >= 0 ){
		string	strValue = GetProfileString( nameSection , 
			nameCWndDiagram_DisplayRessyamei ) ;
		if ( strValue.empty() ){
			iRv = -4 ;	//	DisplayRessyamei ���w�肳��Ă��܂���B
		}	else	{
			bDisplayRessyamei = ( intOf( strValue ) != 0 ); 
		}
	}
	//DisplayRessyasen
	if ( iRv >= 0 )
	{
		string	strValue = GetProfileString( 
			nameSection , nameCWndDiagram_DisplayRessyasen ) ;
		deque<string>	contstrValue = 
			splitc< deque< string > >( ',' , strValue ) ;
		if ( contstrValue.size() != 2 )
		{
			iRv = -5 ;	//	DisplayRessyasen ���w�肳��Ă��܂���B
		}
		else
		{
			bDisplayRessyasenKudari = ( contstrValue[0] == "1" ) ;
			bDisplayRessyasenNobori = ( contstrValue[1] == "1" ) ;
		}
	}
	//DiagramHideIppanekiEkimei
	if ( iRv >= 0 )
	{
		string	strValue = GetProfileString( 
			nameSection , nameCWndDiagram_HideIppanekiEkimei ) ;
		if ( strValue.empty() )
		{
			iRv = -6 ;	//	HideIppanekiEkimei ���w�肳��Ă��܂���B
		}
		else
		{
			bHideIppanekiEkimei = ( intOf( strValue ) != 0 ) ;
		}
	}
	//DiagramStopMarkDraw
	if ( iRv >= 0 )
	{
		string	strValue = GetProfileString( 
			nameSection , nameCWndDiagram_StopMarkDraw ) ;
		if ( strValue.empty() )
		{
			iRv = -7 ;	//	StopMarkDraw ���w�肳��Ă��܂���B
		}
		else
		{
			eStopMarkDraw = (CDcdDiagram::EStopMarkDraw)intOf( strValue ) ;
		}
	}
	//DiagramKeepZoneDgrOnSize
	if ( iRv >= 0 )
	{
		string	strValue = GetProfileString( 
			nameSection , nameCWndDiagram_KeepZoneDgrOnSize ) ;
		if ( strValue.empty() )
		{
			iRv = -8 ;	//	KeepZoneDgrOnSize ���w�肳��Ă��܂���B
		}
		else
		{
			bKeepZoneDgrOnSize = (intOf( strValue )!=0) ;
		}
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCWndDiagram->setPosDgr( posPosDgr ) ;
		pCWndDiagram->setDcdPerDgrX( dDcdPerDgrX ) ;
		pCWndDiagram->setDcdPerDgrY( dDcdPerDgrY ) ;

		pCWndDiagram->setVlineMode( idxVlineMode ) ;
		pCWndDiagram->setDisplayRessyabangou( bDisplayRessyabangou ) ;
		pCWndDiagram->setDisplayRessyamei( bDisplayRessyamei ) ;
		pCWndDiagram->setDisplayRessyasen( Ressyahoukou_Kudari , 
			 bDisplayRessyasenKudari ) ;
		pCWndDiagram->setDisplayRessyasen( Ressyahoukou_Nobori , 
			 bDisplayRessyasenNobori ) ;
		pCWndDiagram->setHideIppanekiEkimei( bHideIppanekiEkimei ) ;
		pCWndDiagram->setStopMarkDraw( eStopMarkDraw ) ;
		pCWndDiagram->setKeepZoneDgrOnSize( bKeepZoneDgrOnSize ) ;
	}
	
	return ( iRv ) ;
}

const TCHAR nameCWndJikokuhyou_DisplayTsuukaEkiJikoku[] = 
	_T( "Jikokuhyou_DisplayTsuukaEkiJikoku" ) ;
const TCHAR nameCWndJikokuhyou_DisplayAllEkiJikoku[] = 
	_T( "Jikokuhyou_DisplayAllEkiJikoku" ) ;
const TCHAR nameCWndJikokuhyou_EkijikokuSort[] = 
	_T( "Jikokuhyou_EkijikokuSort" );
const TCHAR nameCWndJikokuhyou_ModifyEkijikoku[] = 
	_T( "Jikokuhyou_ModifyEkiJikoku" );

int CDiagramEditApp::writeCWndJikokuhyouViewProp( const CWndJikokuhyou* pCWndJikokuhyou ) 
{
	int iRv = 0 ;
	
	//�������擾
	bool	bDisplayTsuukaEkiJikoku = pCWndJikokuhyou->getDisplayTsuukaEkiJikoku() ;
	bool	bDisplayAllEkiJikoku = pCWndJikokuhyou->getDisplayAllEkiJikoku() ;
	CWndJikokuhyou::EEkijikokuSort	eEkijikokuSort = pCWndJikokuhyou->getEkijikokuSort() ;
	bool bModifyEkijikoku = pCWndJikokuhyou->getModifyEkijikoku() ;

	// --------------------------------

	//DisplayTsuukaEkiJikoku
	if ( iRv >= 0 )
	{
		string	strValue ;
		strValue += stringOf( bDisplayTsuukaEkiJikoku ? 1 : 0 ) ;
		WriteProfileString( nameSection , nameCWndJikokuhyou_DisplayTsuukaEkiJikoku ,
			tstringOf( strValue ).c_str() ) ;
	}
	//DisplayAllEkiJikoku
	{
		string	strValue ;
		strValue += stringOf( bDisplayAllEkiJikoku ) ;
		WriteProfileString( nameSection , nameCWndJikokuhyou_DisplayAllEkiJikoku ,
			tstringOf( strValue ).c_str() ) ;
	}
	//EkijikokuSort
	if ( iRv >= 0 )
	{
		string strValue ;
		strValue += stringOf( (int)eEkijikokuSort ) ;
		WriteProfileString( nameSection , nameCWndJikokuhyou_EkijikokuSort ,
			tstringOf( strValue ).c_str() ) ;
	}

	//ModifyEkijikoku
	if ( iRv >= 0 )
	{
		string strValue ;
		strValue = ( bModifyEkijikoku ? _T( "1" ) : _T( "0" ) ) ;
		WriteProfileString( nameSection , nameCWndJikokuhyou_ModifyEkijikoku ,
			tstringOf( strValue ).c_str() ) ;
	}
	return ( iRv ) ;
}
int CDiagramEditApp::readCWndJikokuhyouViewProp( CWndJikokuhyou* pCWndJikokuhyou ) 
{
	int iRv = 0 ;
	bool	bDisplayTsuukaEkiJikoku = true  ;
	bool 	bDisplayAllEkiJikoku = false ;
	CWndJikokuhyou::EEkijikokuSort	eEkijikokuSort = CWndJikokuhyou::EEkijikokuSort_Ekiatsukai ;
	bool bModifyEkijikoku = true ;
	

	// --------------------------------
	//DisplayTsuukaEkiJikoku
	if ( iRv >= 0 )
	{
		string	strValue = stringOf( (LPCTSTR)GetProfileString( 
			nameSection , nameCWndJikokuhyou_DisplayTsuukaEkiJikoku ) ) ;
		if ( strValue.empty() )
		{
			iRv = -1 ;	//	DisplayTsuukaEkiJikoku ���w�肳��Ă��܂���B
		}
		else
		{
			bDisplayTsuukaEkiJikoku = ( intOf( strValue ) != 0 ) ;
		}
	}
	//DisplayAllEkiJikoku
	{
		string	strValue = stringOf( (LPCTSTR)GetProfileString( 
			nameSection , nameCWndJikokuhyou_DisplayAllEkiJikoku ) );
		if ( strValue.empty() )
		{
			iRv = -1 ;	//	DisplayTsuukaEkiJikoku ���w�肳��Ă��܂���B
		}
		else
		{
			bDisplayAllEkiJikoku = ( intOf( strValue ) != 0 ) ;
		}
	}
	//EkijikokuSort
	if ( iRv >= 0 )
	{
		string	strValue = stringOf( (LPCTSTR)GetProfileString( 
			nameSection , nameCWndJikokuhyou_EkijikokuSort ) ) ;
		if ( strValue.empty() )
		{
			iRv = -1 ;	//	DisplayTsuukaEkiJikoku ���w�肳��Ă��܂���B
		}
		else
		{
			int iValue = intOf( strValue ) ;
			switch( iValue )
			{
			case (int)CWndJikokuhyou::EEkijikokuSort_Ekiatsukai :
				eEkijikokuSort = CWndJikokuhyou::EEkijikokuSort_Ekiatsukai ;
				break ;
			case (int)CWndJikokuhyou::EEkijikokuSort_Transfer :
				eEkijikokuSort = CWndJikokuhyou::EEkijikokuSort_Transfer ;
				break ;
			}
		}
	}
	//ModifyEkijikoku
	if ( iRv >= 0 )
	{
		string	strValue = GetProfileString( 
			nameSection , nameCWndJikokuhyou_ModifyEkijikoku ) ;
		if ( strValue.empty() )
		{
			iRv = -1 ;	//	ModifyEkijikoku ���w�肳��Ă��܂���B
		}
		else
		{
			int iValue = intOf( strValue ) ;
			bModifyEkijikoku = ( iValue != 0 ) ;
		}
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCWndJikokuhyou->setDisplayTsuukaEkiJikoku( bDisplayTsuukaEkiJikoku ) ;
		pCWndJikokuhyou->setDisplayAllEkiJikoku( bDisplayAllEkiJikoku ) ;
		pCWndJikokuhyou->setEkijikokuSort( eEkijikokuSort ) ;
		pCWndJikokuhyou->setModifyEkijikoku( bModifyEkijikoku ) ;
	}


	return ( iRv ) ;
}

const TCHAR nameCWndDcdGridEkiProp_AdjustByEkijikokukeisiki[] = 
	_T( "EkiProp_AdjustByEkijikokukeisiki" ) ;


int CDiagramEditApp::writeCWndDcdGridEkiProp( 
		const CWndDcdGridEki* pCWndDcdGridEki ) 
{
	int iRv = 0 ;

	//�������擾
	bool bAdjustByEkijikokukeisiki = pCWndDcdGridEki->getAdjustByEkijikokukeisiki() ;
	// --------------------------------

	//EkiProp_AdjustByEkijikokukeisiki
	if ( iRv >= 0 )
	{
		string strValue ;
		strValue += stringOf( bAdjustByEkijikokukeisiki ? 1:0 ) ;
		WriteProfileString( nameSection , nameCWndDcdGridEkiProp_AdjustByEkijikokukeisiki ,
			tstringOf( strValue ).c_str() ) ;
	}


	return iRv ;
}
int CDiagramEditApp::readCWndDcdGridEkiProp( 
		CWndDcdGridEki* pCWndDcdGridEki ) 
{
	int iRv = 0 ;
	bool	bAdjustByEkijikokukeisiki = true  ;
	//EkiProp_AdjustByEkijikokukeisiki
	if ( iRv >= 0 )
	{
		string	strValue = stringOf( (LPCTSTR)GetProfileString( 
			nameSection , nameCWndDcdGridEkiProp_AdjustByEkijikokukeisiki ) ) ;
		if ( strValue.empty() )
		{
			iRv = -1 ;	//	EkiProp_AdjustByEkijikokukeisiki ���w�肳��Ă��܂���B
		}
		else
		{
			bAdjustByEkijikokukeisiki = ( intOf( strValue ) != 0 ) ;
		}
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCWndDcdGridEki->setAdjustByEkijikokukeisiki( bAdjustByEkijikokukeisiki ) ;
	}
	return iRv ;
}


// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------


BEGIN_MESSAGE_MAP(CDiagramEditApp, CHidemdiApp)
	//{{AFX_MSG_MAP(CDiagramEditApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_COMMAND(ID_FILE_PrintPageProp, OnFILEPrintPageProp)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_HELP, OnHelp)
//	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
//	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	//}}AFX_MSG_MAP
	// �W���̃t�@�C����{�h�L�������g �R�}���h
	ON_COMMAND(ID_FILE_NEW, CHidemdiApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CHidemdiApp::OnFileOpen)
	// �W���̈���Z�b�g�A�b�v �R�}���h
	ON_COMMAND(ID_FILE_PRINT_SETUP, CHidemdiApp::OnFilePrintSetup)
//	ON_COMMAND(ID_EDIT_REDO, &CDiagramEditApp::OnEditRedo)
//	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, &CDiagramEditApp::OnUpdateEditRedo)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagramEditApp �N���X�̍\�z

CDiagramEditApp::CDiagramEditApp()
{
	m_pdoctmplEki = NULL ;
	m_pdoctmplResssyasyubetsu = NULL ;
	m_pdoctmplJikokuhyou = NULL ;
	m_pdoctmplDiagram = NULL ;
	m_pdoctmplComment = NULL ;
}

/////////////////////////////////////////////////////////////////////////////
// �B��� CDiagramEditApp �I�u�W�F�N�g

CDiagramEditApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDiagramEditApp �N���X�̏�����

BOOL CDiagramEditApp::InitInstance()
{
	// �W���I�ȏ���������
	// ���������̋@�\���g�p�����A���s�t�@�C���̃T�C�Y��������
	// ��������Έȉ��̓���̏��������[�`���̒�����s�K�v�Ȃ���
	// ���폜���Ă��������B

#ifdef _AFXDLL
	//VisualStudio 2008
	//	warning C4996: 'CWinApp::Enable3dControls': 
	//	CWinApp::Enable3dControlsStatic is no longer needed. 
	//	You should remove this call.
	Enable3dControls();		// ���L DLL �̒��� MFC ���g�p����ꍇ�ɂ͂������Ăяo���Ă��������B
#else
	//VisualStudio 2008
	//	warning C4996: 'CWinApp::Enable3dControlsStatic': 
	//	CWinApp::Enable3dControlsStatic is no longer needed. 
	//	You should remove this call.
	Enable3dControlsStatic();	// MFC �ƐÓI�Ƀ����N���Ă���ꍇ�ɂ͂������Ăяo���Ă��������B
#endif

	// --------------------------------
	//	LocalAppData �f�B���N�g�����쐬
	// --------------------------------
	{
		CString	strLocalAppdataOudiaFolder ;
		strLocalAppdataOudiaFolder = makeLocalAppdataFilename( _T( "" ) ) ;

		//strLocalAppdataOudiaFolder = OuDia��LocalAppData�t�H���_�B
		//	�����ɂ� '\' �͂���܂���B
		//	���̃f�B���N�g���́A�쐬����Ă��܂��B

		OuLib::Dir::mkdirs( stringOf( (LPCTSTR)strLocalAppdataOudiaFolder ) );
	}
	


	// --------------------------------
	//	LogMsg() �t�@�C���̃t�@�C�����ݒ�
	// --------------------------------
	{
		logmsg_setFilename( makeLocalAppdataFilename( "OuDia.log" ) ) ;

		//	LogLevel �́A���̂��Ƃ� 
		//	.ini �t�@�C����[AppProp]LogLevel ����ǂݏo���܂��B
		logmsg_setLogLevel( 2 ) ;
	}

	// --------------------------------
	//	.Ini�t�@�C���̃t�@�C�����ݒ�
	// --------------------------------
	//SetRegistryKey(_T("DiagramEdit"));
	{
		free((void*)m_pszProfileName);
		m_pszProfileName=_tcsdup( makeLocalAppdataFilename( "OuDia.ini" ) );
	}
	LoadStdProfileSettings();  // �W���� INI �t�@�C���̃I�v�V���������[�ނ��܂� (MRU ���܂�)

	// --------------------------------
	//	.Ini�t�@�C���̓ǂݍ���
	// --------------------------------
	{
		//	����y�[�W�ݒ�
		CString aStr = GetProfileString( nameSection , namePrintPageProp ) ;
		m_CdPrintPageProp.decode( (LPCTSTR)aStr ) ;

		//	LogLevel�ݒ�
		logmsg_setLogLevel( GetProfileInt( nameSection , nameLogLevel , 0 ) );
		
	}

	// ----------------------------------------------------------------
	// �A�v���P�[�V�����p�̃h�L�������g �e���v���[�g��o�^���܂��B�h�L�������g �e���v���[�g
	//  �̓h�L�������g�A�t���[�� �E�B���h�E�ƃr���[���������邽�߂ɋ@�\���܂��B

	{
		CHidemdiRootDoctmpl* pDocTemplate;
		pDocTemplate = new CDiagramEditDoctmpl(
			IDR_DIATYPE,
			RUNTIME_CLASS(CDiagramEditDoc));
		AddDocTemplate(pDocTemplate);
		RegisterRootDoctmpl( pDocTemplate ) ;
	}

	{
		CHidemdiSubDoctmpl* pNewDocTemplate = new CHidemdiDoctmplDocstrAlone(
			IDR_DOCVIEW_Eki,
			RUNTIME_CLASS(CEkiDoc),		// �h�L�������g �N���X
			RUNTIME_CLASS(CMDIChildWnd),		// �t���[�� �N���X
			RUNTIME_CLASS(CEkiView));	// �r���[ �N���X
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplEki = pNewDocTemplate ;
			//	���̃h�L�������g�e���v���[�g���A�A�v���P�[�V�����N���X��
			//	�����o�ϐ��ɕۑ�
	}

	{
		CHidemdiSubDoctmpl* pNewDocTemplate = new CHidemdiDoctmplDocstrAlone(
			IDR_DOCVIEW_Ressyasyubetsu,
			RUNTIME_CLASS(CRessyasyubetsuDoc),		// �h�L�������g �N���X
			RUNTIME_CLASS(CMDIChildWnd),		// �t���[�� �N���X
			RUNTIME_CLASS(CRessyasyubetsuView));	// �r���[ �N���X
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplResssyasyubetsu = pNewDocTemplate ;
			//	���̃h�L�������g�e���v���[�g���A�A�v���P�[�V�����N���X��
			//	�����o�ϐ��ɕۑ�
	}


	{
		CHidemdiSubDoctmpl* pNewDocTemplate = new CHidemdiDoctmplDocstrAlone(
			IDR_DOCVIEW_Jikokuhyou,
			RUNTIME_CLASS(CJikokuhyouDoc),		// �h�L�������g �N���X
			RUNTIME_CLASS(CMDIChildWnd),		// �t���[�� �N���X
			RUNTIME_CLASS(CJikokuhyouView));	// �r���[ �N���X
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplJikokuhyou = pNewDocTemplate ;
			//	���̃h�L�������g�e���v���[�g���A�A�v���P�[�V�����N���X��
			//	�����o�ϐ��ɕۑ�
	}
	{
		CHidemdiSubDoctmpl* pNewDocTemplate = new CHidemdiDoctmplDocstrAlone(
			IDR_DOCVIEW_Diagram,
			RUNTIME_CLASS(CDedDiagramDoc),		// �h�L�������g �N���X
			RUNTIME_CLASS(CMDIChildWnd),		// �t���[�� �N���X
			RUNTIME_CLASS(CDedDiagramView));	// �r���[ �N���X
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplDiagram = pNewDocTemplate ;
			//	���̃h�L�������g�e���v���[�g���A�A�v���P�[�V�����N���X��
			//	�����o�ϐ��ɕۑ�
	}
	{
		CHidemdiSubDoctmpl* pNewDocTemplate = new CHidemdiDoctmplDocstrAlone(
			IDR_DOCVIEW_Comment,
			RUNTIME_CLASS(CDedCommentDoc),		// �h�L�������g �N���X
			RUNTIME_CLASS(CMDIChildWnd),		// �t���[�� �N���X
			RUNTIME_CLASS(CDedCommentView));	// �r���[ �N���X
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplComment = pNewDocTemplate ;
			//	���̃h�L�������g�e���v���[�g���A�A�v���P�[�V�����N���X��
			//	�����o�ϐ��ɕۑ�
	}


	// ���C�� MDI �t���[�� �E�B���h�E���쐬
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// �h���b�O/�h���b�v �̃I�[�v���������܂�
	m_pMainWnd->DragAcceptFiles();

	// DDE Execute open ���g�p�\�ɂ��܂��B
	EnableShellOpen();
	
	//	(���̃A�v���P�[�V��������́A�t�@�C���^�C�v�̃��W�X�g���ւ̓o�^��
	//	�s���܂���B
	//	�o�^�́AVisualStudioInstaller �ōs���܂��j
	// --------------------------------
	//	RegisterShellFileTypes(TRUE);

	// DDE�Afile open �ȂǕW���̃V�F�� �R�}���h�̃R�}���h���C������͂��܂��B
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// �R�}���h���C���Ńf�B�X�p�b�` �R�}���h���w�肵�܂��B
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// ���C�� �E�B���h�E�����������ꂽ�̂ŁA�\���ƍX�V���s���܂��B
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

//memo: ���݂́AIDD_AboutBoxGpl �ɑ�ւ���܂����B
///////////////////////////////////////////////////////////////////////////////
//// �A�v���P�[�V�����̃o�[�W�������Ŏg���� CAboutDlg �_�C�A���O
//
///**
// @brief
//	�o�[�W�������̃_�C�A���O�̃N���X�ł��B
//*/
//class CAboutDlg : public CDialog
//{
//public:
//	CAboutDlg( const string& strProgramVer );
//
//// �_�C�A���O �f�[�^
//	//{{AFX_DATA(CAboutDlg)
//	enum { IDD = IDD_ABOUTBOX };
//	CString	m_strSTATIC_VERSION;
//	//}}AFX_DATA
//
//	// ClassWizard ���z�֐��̃I�[�o�[���C�h�𐶐����܂��B
//	//{{AFX_VIRTUAL(CAboutDlg)
//	protected:
//	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �̃T�|�[�g
//	//}}AFX_VIRTUAL
//
//// �C���v�������e�[�V����
//protected:
//	//{{AFX_MSG(CAboutDlg)
//		// ���b�Z�[�W �n���h���͂���܂���B
//	//}}AFX_MSG
//	DECLARE_MESSAGE_MAP()
//};
//
//CAboutDlg::CAboutDlg( const string& strProgramVer ) : CDialog(CAboutDlg::IDD)
//{
//	//{{AFX_DATA_INIT(CAboutDlg)
//	m_strSTATIC_VERSION = "Ver. " ;
//	//}}AFX_DATA_INIT
//	m_strSTATIC_VERSION += strProgramVer.c_str() ;
//}
//
//void CAboutDlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialog::DoDataExchange(pDX);
//	//{{AFX_DATA_MAP(CAboutDlg)
//	DDX_Text(pDX, IDC_STATIC_VERSION, m_strSTATIC_VERSION);
//	//}}AFX_DATA_MAP
//}
//
//BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//	//{{AFX_MSG_MAP(CAboutDlg)
//		// ���b�Z�[�W �n���h���͂���܂���B
//	//}}AFX_MSG_MAP
//END_MESSAGE_MAP()
//



// �_�C�A���O�����s���邽�߂̃A�v���P�[�V���� �R�}���h
void CDiagramEditApp::OnAppAbout()
{
	string strProgramVer ;
	string strLegalCopyright ;
	readVersionResource( &strProgramVer , &strLegalCopyright ) ;


	CAboutBoxGpl aboutDlg( strProgramVer , strLegalCopyright ) ;

	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CDiagramEditApp ���b�Z�[�W �n���h��

void CDiagramEditApp::OnVIEWEki() 
{
	openCEkiDoc() ;
	
}

void CDiagramEditApp::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	CDocument*	pCDocument = getCDiagramEditDoc() ;
	BOOL	bIsModified = FALSE ;
	if ( pCDocument != NULL ){
		bIsModified = pCDocument->IsModified() ;
	}
	pCmdUI->Enable( bIsModified ) ;

	
}

int CDiagramEditApp::ExitInstance() 
{
	string	strPrintPageProp = m_CdPrintPageProp.encode() ;
	WriteProfileString( nameSection , namePrintPageProp , strPrintPageProp.c_str() ) ;

	return CHidemdiApp::ExitInstance();
}

void CDiagramEditApp::OnFILEPrintPageProp() 
{
	CDlgPrintPageProp	aDlg( m_CdPrintPageProp  ) ;
	if ( aDlg.DoModal() == IDOK ){
		m_CdPrintPageProp = aDlg.getCdPrintPageProp() ;
	}
	
}



void CDiagramEditApp::OnFileOpen() 
{
	CString	strExt ;
	pRootDoctmpl()->GetDocString( strExt , CDocTemplate::filterExt ) ;

	CFileDialog	aDlg( TRUE , strExt , NULL , 
	  OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, getCFileDialogFilter() , NULL ) ;
	if ( aDlg.DoModal() != IDOK ){
		return ;
	}	
	// --------------------------------

	AfxGetApp()->OpenDocumentFile(aDlg.GetPathName() );
		// if returns NULL, the user has already been alerted
	
}

#include <htmlhelp.h>

void CDiagramEditApp::OnHelp() 
{
	CString	strUrl = makeHtmlHelpUrl( _T( "" ) )  ;

	//	���������A�v���P�[�V�����̃��C���E�C���h�E�ɂ���ƁA
	//	���C���E�C���h�E�͏��HTMLHelp�E�C���h�E�̏�ɂȂ�܂��B
	HWND hwndCaller = NULL ;
	HWND hwnd =
		::HtmlHelp(
			hwndCaller ,
				strUrl , 
				 HH_DISPLAY_TOPIC,
	             NULL) ;
}
