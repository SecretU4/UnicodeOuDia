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


(訳: 

	OuDia - 列車時刻表をもとに、ダイヤグラムを描画するWin32アプリケーシ
ョン。

Copyright (C) 2006-2017 take-okm 

このプログラムはフリーソフトウェアです。あなたはこれを、フリーソフトウェア財
団によって発行されたGNU 一般公衆利用許諾書(バージョン3か、それ以降のバージョ
ンのうちどれか)が定める条件の下で再頒布または改変 することができます。

このプログラムは有用であることを願って頒布されますが、*全くの無保証 *です。
商業可能性の保証や特定目的への適合性は、言外に示されたものも 含め、全く存在
しません。詳しくはGNU 一般公衆利用許諾書をご覧ください。

あなたはこのプログラムと共に、GNU 一般公衆利用許諾書のコピーを一部 受け取っ
ているはずです。もし受け取っていなければ、<http://www.gnu.org/licenses/> を
ご覧ください。

)

  加えて、特別な例外として、take-okm はこのプログラムのコードを 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  あるいは "MFC Version 9.0" と同じライセンスが適用された
  "MFC Version 9.0" の改変されたバージョン)とリンクし、
  リンクされた両者を含む結合著作物を頒布する許可を与えます。
  あなたは "MFC" 以外で使われているすべて
  のコードに関しては全面的にGNU一般公衆利用許諾契約書に従わなければ
  なりません。あなたがこのファイルを改変したならば、あなたはこの例外
  をあなたのバージョンのファイルに引き続き設けることもできますが、そ
  うする義務はありません。もし例外を設けたくなければ、この例外条項を
  あなたのバージョンからは削除してください。)
*/
// DiagramEdit.cpp : アプリケーション用クラスの機能定義を行います。
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
	//	下請関数
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

		//	バージョンを文字列化
		int idxLength = 0 ;
		for ( idxLength = sizeof(awVersion) / sizeof(awVersion[0]) ;
			idxLength > 2 && awVersion[idxLength-1] == 0 ;
			idxLength -- ){}
		//idxLength = awVersion[] から、末尾の0を除いた要素数
		//	バージョンが 1.2.3.4 なら、 idxLength = 4
		//	バージョンが 1.2.3.0 なら、 idxLength = 3
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
	//@name CDiagramEditApp-属性
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
			iRv = -1 ;	//	pCentDedDia が見つかりません。
		}
	}
	if ( iRv >= 0 )
	{
		CString	strDocument ;
		strDocument.Format( "%s\n%d" , pCentDedDia->getName().c_str() , 
			(int)eRessyahoukou ) ;
		//strDocument= pCentDedDia に対応する"<ダイヤ名>\n<列車方向>"
		
		CDocument*	pCDocument = m_pdoctmplJikokuhyou->OpenDocumentFile( strDocument ) ;
		if ( pCDocument != NULL )
		{
			pCJikokuhyouDoc = (CJikokuhyouDoc*)pCDocument ;
		}
		else
		{
			iRv = -2 ; //	pCentDedDia に対応する時刻表ビューが開けません。
		}
	}
	//pCJikokuhyouDoc = CJikokuhyouDocへのポインタ
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
	//@name	操作 - ファイル名
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
	//strProgramDir = .exe ファイルのあるディレクトリ(例:"c:\program files\oudia\" )。

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
		//	末尾に '\\' がある場合は、これを削除
		if ( strLocalAppdataFolder.GetLength() > 0 && 
			strLocalAppdataFolder[ strLocalAppdataFolder.GetLength() - 1 ] 
				== _T( '\\' ) )
		{
			strLocalAppdataFolder.Delete( 
				strLocalAppdataFolder.GetLength() - 1 ) ;
		}
	}
	//strLocalAppdataFolder = LocalAppData(取得できなければテンポラリディレクトリ)
	//	末尾には '\' はありません。

	strLocalAppdataFolder += _T( "\\OuDia\\" ) ;
	//strLocalAppdataFolder = OuDiaのLocalAppDataフォルダ。
	//	末尾には '\\' があります。
	//	このディレクトリは、作成されています。

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
	//@name	操作- .ini ファイル
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
	
	//属性を取得
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
			iRv = -1 ;	//	DiagramPosDgr が指定されていません。
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
			iRv = -2 ;	//	DcdPerDgrX が指定されていません。
		}	else	{
			dDcdPerDgrX = doubleOf( strValue ) ; 
		}
	}
	//DcdPerDgrY
	if ( iRv >= 0 ){
		string	strValue = GetProfileString( nameSection , 
			nameCWndDiagram_DcdPerDgrY ) ;
		if ( strValue.empty() ){
			iRv = -2 ;	//	DcdPerDgrY が指定されていません。
		}	else	{
			dDcdPerDgrY = doubleOf( strValue ) ; 
		}
	}



	//DiagramVlineMode
	if ( iRv >= 0 ){
		string	strValue = GetProfileString( nameSection , 
			nameCWndDiagram_VlineMode ) ;
		if ( strValue.empty() ){
			iRv = -2 ;	//	DiagramVlineMode が指定されていません。
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
			iRv = -3 ;	//	DisplayRessyabangou が指定されていません。
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
			iRv = -4 ;	//	DisplayRessyamei が指定されていません。
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
			iRv = -5 ;	//	DisplayRessyasen が指定されていません。
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
			iRv = -6 ;	//	HideIppanekiEkimei が指定されていません。
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
			iRv = -7 ;	//	StopMarkDraw が指定されていません。
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
			iRv = -8 ;	//	KeepZoneDgrOnSize が指定されていません。
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
	
	//属性を取得
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
			iRv = -1 ;	//	DisplayTsuukaEkiJikoku が指定されていません。
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
			iRv = -1 ;	//	DisplayTsuukaEkiJikoku が指定されていません。
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
			iRv = -1 ;	//	DisplayTsuukaEkiJikoku が指定されていません。
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
			iRv = -1 ;	//	ModifyEkijikoku が指定されていません。
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

	//属性を取得
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
			iRv = -1 ;	//	EkiProp_AdjustByEkijikokukeisiki が指定されていません。
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
	// 標準のファイル基本ドキュメント コマンド
	ON_COMMAND(ID_FILE_NEW, CHidemdiApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CHidemdiApp::OnFileOpen)
	// 標準の印刷セットアップ コマンド
	ON_COMMAND(ID_FILE_PRINT_SETUP, CHidemdiApp::OnFilePrintSetup)
//	ON_COMMAND(ID_EDIT_REDO, &CDiagramEditApp::OnEditRedo)
//	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, &CDiagramEditApp::OnUpdateEditRedo)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagramEditApp クラスの構築

CDiagramEditApp::CDiagramEditApp()
{
	m_pdoctmplEki = NULL ;
	m_pdoctmplResssyasyubetsu = NULL ;
	m_pdoctmplJikokuhyou = NULL ;
	m_pdoctmplDiagram = NULL ;
	m_pdoctmplComment = NULL ;
}

/////////////////////////////////////////////////////////////////////////////
// 唯一の CDiagramEditApp オブジェクト

CDiagramEditApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDiagramEditApp クラスの初期化

BOOL CDiagramEditApp::InitInstance()
{
	// 標準的な初期化処理
	// もしこれらの機能を使用せず、実行ファイルのサイズを小さく
	// したければ以下の特定の初期化ルーチンの中から不必要なもの
	// を削除してください。

#ifdef _AFXDLL
	//VisualStudio 2008
	//	warning C4996: 'CWinApp::Enable3dControls': 
	//	CWinApp::Enable3dControlsStatic is no longer needed. 
	//	You should remove this call.
	Enable3dControls();		// 共有 DLL の中で MFC を使用する場合にはここを呼び出してください。
#else
	//VisualStudio 2008
	//	warning C4996: 'CWinApp::Enable3dControlsStatic': 
	//	CWinApp::Enable3dControlsStatic is no longer needed. 
	//	You should remove this call.
	Enable3dControlsStatic();	// MFC と静的にリンクしている場合にはここを呼び出してください。
#endif

	// --------------------------------
	//	LocalAppData ディレクトリを作成
	// --------------------------------
	{
		CString	strLocalAppdataOudiaFolder ;
		strLocalAppdataOudiaFolder = makeLocalAppdataFilename( _T( "" ) ) ;

		//strLocalAppdataOudiaFolder = OuDiaのLocalAppDataフォルダ。
		//	末尾には '\' はありません。
		//	このディレクトリは、作成されています。

		OuLib::Dir::mkdirs( stringOf( (LPCTSTR)strLocalAppdataOudiaFolder ) );
	}
	


	// --------------------------------
	//	LogMsg() ファイルのファイル名設定
	// --------------------------------
	{
		logmsg_setFilename( makeLocalAppdataFilename( "OuDia.log" ) ) ;

		//	LogLevel は、このあとに 
		//	.ini ファイルの[AppProp]LogLevel から読み出します。
		logmsg_setLogLevel( 2 ) ;
	}

	// --------------------------------
	//	.Iniファイルのファイル名設定
	// --------------------------------
	//SetRegistryKey(_T("DiagramEdit"));
	{
		free((void*)m_pszProfileName);
		m_pszProfileName=_tcsdup( makeLocalAppdataFilename( "OuDia.ini" ) );
	}
	LoadStdProfileSettings();  // 標準の INI ファイルのオプションをローﾄﾞします (MRU を含む)

	// --------------------------------
	//	.Iniファイルの読み込み
	// --------------------------------
	{
		//	印刷ページ設定
		CString aStr = GetProfileString( nameSection , namePrintPageProp ) ;
		m_CdPrintPageProp.decode( (LPCTSTR)aStr ) ;

		//	LogLevel設定
		logmsg_setLogLevel( GetProfileInt( nameSection , nameLogLevel , 0 ) );
		
	}

	// ----------------------------------------------------------------
	// アプリケーション用のドキュメント テンプレートを登録します。ドキュメント テンプレート
	//  はドキュメント、フレーム ウィンドウとビューを結合するために機能します。

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
			RUNTIME_CLASS(CEkiDoc),		// ドキュメント クラス
			RUNTIME_CLASS(CMDIChildWnd),		// フレーム クラス
			RUNTIME_CLASS(CEkiView));	// ビュー クラス
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplEki = pNewDocTemplate ;
			//	このドキュメントテンプレートを、アプリケーションクラスの
			//	メンバ変数に保存
	}

	{
		CHidemdiSubDoctmpl* pNewDocTemplate = new CHidemdiDoctmplDocstrAlone(
			IDR_DOCVIEW_Ressyasyubetsu,
			RUNTIME_CLASS(CRessyasyubetsuDoc),		// ドキュメント クラス
			RUNTIME_CLASS(CMDIChildWnd),		// フレーム クラス
			RUNTIME_CLASS(CRessyasyubetsuView));	// ビュー クラス
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplResssyasyubetsu = pNewDocTemplate ;
			//	このドキュメントテンプレートを、アプリケーションクラスの
			//	メンバ変数に保存
	}


	{
		CHidemdiSubDoctmpl* pNewDocTemplate = new CHidemdiDoctmplDocstrAlone(
			IDR_DOCVIEW_Jikokuhyou,
			RUNTIME_CLASS(CJikokuhyouDoc),		// ドキュメント クラス
			RUNTIME_CLASS(CMDIChildWnd),		// フレーム クラス
			RUNTIME_CLASS(CJikokuhyouView));	// ビュー クラス
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplJikokuhyou = pNewDocTemplate ;
			//	このドキュメントテンプレートを、アプリケーションクラスの
			//	メンバ変数に保存
	}
	{
		CHidemdiSubDoctmpl* pNewDocTemplate = new CHidemdiDoctmplDocstrAlone(
			IDR_DOCVIEW_Diagram,
			RUNTIME_CLASS(CDedDiagramDoc),		// ドキュメント クラス
			RUNTIME_CLASS(CMDIChildWnd),		// フレーム クラス
			RUNTIME_CLASS(CDedDiagramView));	// ビュー クラス
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplDiagram = pNewDocTemplate ;
			//	このドキュメントテンプレートを、アプリケーションクラスの
			//	メンバ変数に保存
	}
	{
		CHidemdiSubDoctmpl* pNewDocTemplate = new CHidemdiDoctmplDocstrAlone(
			IDR_DOCVIEW_Comment,
			RUNTIME_CLASS(CDedCommentDoc),		// ドキュメント クラス
			RUNTIME_CLASS(CMDIChildWnd),		// フレーム クラス
			RUNTIME_CLASS(CDedCommentView));	// ビュー クラス
		AddDocTemplate(pNewDocTemplate);
		
		m_pdoctmplComment = pNewDocTemplate ;
			//	このドキュメントテンプレートを、アプリケーションクラスの
			//	メンバ変数に保存
	}


	// メイン MDI フレーム ウィンドウを作成
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// ドラッグ/ドロップ のオープンを許可します
	m_pMainWnd->DragAcceptFiles();

	// DDE Execute open を使用可能にします。
	EnableShellOpen();
	
	//	(このアプリケーションからは、ファイルタイプのレジストリへの登録は
	//	行いません。
	//	登録は、VisualStudioInstaller で行います）
	// --------------------------------
	//	RegisterShellFileTypes(TRUE);

	// DDE、file open など標準のシェル コマンドのコマンドラインを解析します。
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// コマンドラインでディスパッチ コマンドを指定します。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// メイン ウィンドウが初期化されたので、表示と更新を行います。
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

//memo: 現在は、IDD_AboutBoxGpl に代替されました。
///////////////////////////////////////////////////////////////////////////////
//// アプリケーションのバージョン情報で使われる CAboutDlg ダイアログ
//
///**
// @brief
//	バージョン情報のダイアログのクラスです。
//*/
//class CAboutDlg : public CDialog
//{
//public:
//	CAboutDlg( const string& strProgramVer );
//
//// ダイアログ データ
//	//{{AFX_DATA(CAboutDlg)
//	enum { IDD = IDD_ABOUTBOX };
//	CString	m_strSTATIC_VERSION;
//	//}}AFX_DATA
//
//	// ClassWizard 仮想関数のオーバーライドを生成します。
//	//{{AFX_VIRTUAL(CAboutDlg)
//	protected:
//	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV のサポート
//	//}}AFX_VIRTUAL
//
//// インプリメンテーション
//protected:
//	//{{AFX_MSG(CAboutDlg)
//		// メッセージ ハンドラはありません。
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
//		// メッセージ ハンドラはありません。
//	//}}AFX_MSG_MAP
//END_MESSAGE_MAP()
//



// ダイアログを実行するためのアプリケーション コマンド
void CDiagramEditApp::OnAppAbout()
{
	string strProgramVer ;
	string strLegalCopyright ;
	readVersionResource( &strProgramVer , &strLegalCopyright ) ;


	CAboutBoxGpl aboutDlg( strProgramVer , strLegalCopyright ) ;

	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CDiagramEditApp メッセージ ハンドラ

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

	//	第一引数をアプリケーションのメインウインドウにすると、
	//	メインウインドウは常にHTMLHelpウインドウの上になります。
	HWND hwndCaller = NULL ;
	HWND hwnd =
		::HtmlHelp(
			hwndCaller ,
				strUrl , 
				 HH_DISPLAY_TOPIC,
	             NULL) ;
}
