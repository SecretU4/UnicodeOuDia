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
// CDiagramEditDoc.cpp : CDiagramEditDoc クラスの動作の定義を行います。
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

/**	Undo の最大回数です。 */
const int iUndoLevel = 8 ;

// The historical format-conversion DLLs are MBCS/CP932 components.
// Keep their byte contract isolated from the application's UTF-8 strings.
static bool cp932BytesOfUtf8(
	const std::string& utf8,
	std::string* cp932 )
{
	if ( cp932 == NULL ) return false ;
	cp932->clear() ;
	std::wstring wide ;
	if ( !wstringFromUtf8( utf8 , &wide ) ) return false ;
	if ( wide.empty() ) return true ;
	BOOL usedDefaultChar = FALSE ;
	int cb = WideCharToMultiByte( 932 , WC_NO_BEST_FIT_CHARS ,
		wide.data() , (int)wide.size() , NULL , 0 , NULL ,
		&usedDefaultChar ) ;
	if ( cb <= 0 || usedDefaultChar ) return false ;
	std::vector<char> bytes( cb ) ;
	usedDefaultChar = FALSE ;
	if ( WideCharToMultiByte( 932 , WC_NO_BEST_FIT_CHARS ,
		wide.data() , (int)wide.size() , &bytes[0] , cb , NULL ,
		&usedDefaultChar ) != cb || usedDefaultChar )
		return false ;
	cp932->assign( &bytes[0] , cb ) ;
	return true ;
}

static bool utf8OfCp932Bytes(
	const std::string& cp932,
	std::string* utf8 )
{
	if ( utf8 == NULL ) return false ;
	utf8->clear() ;
	if ( cp932.empty() ) return true ;
	if ( cp932.size() > 0x7fffffff ) return false ;
	int cch = MultiByteToWideChar( 932 , 0 , cp932.data() ,
		(int)cp932.size() , NULL , 0 ) ;
	if ( cch <= 0 ) return false ;
	std::vector<wchar_t> wide( cch ) ;
	if ( MultiByteToWideChar( 932 , 0 , cp932.data() ,
		(int)cp932.size() , &wide[0] , cch ) != cch )
		return false ;
	return utf8Of( std::wstring( &wide[0] , cch ) , utf8 ) ;
}

// A current-format .oud file must be decoded as UTF-8 or CP932 before
// model validation. FileTypeAppComment is shown as a hint, not trusted as
// an encoding declaration: old and Unicode builds can share a version number.
static bool isValidCurrentOudText( const std::string& text )
{
	CconvCDedRosenFileData conv ;
	if ( conv.isEncodeAbleFormat( text ) < 0 ) return false ;
	CDedRosenFileData data ;
	COuErrorInfoContainer errors ;
	return conv.CDedRosenFileData_from_string( &data , text , &errors ) >= 0 ;
}

// Returns UTF-8 text. Legacy FileType values are kept on the CP932 path for
// the historical conversion DLLs. Current-format BOM-less files are tested
// in both encodings; if both parse, the user chooses rather than risking
// silent mojibake.
static int utf8TextOfOudFileBytes(
	const std::string& rawBytes , std::string* utf8Text )
{
	if ( utf8Text == NULL ) return -3 ;
	utf8Text->clear() ;
	if ( rawBytes.find( '\0' ) != std::string::npos ) return -3 ;

	std::string content = rawBytes ;
	const bool hasUtf8Bom = content.size() >= 3 &&
		(unsigned char)content[0] == 0xef &&
		(unsigned char)content[1] == 0xbb &&
		(unsigned char)content[2] == 0xbf ;
	if ( hasUtf8Bom )
	{
		content.erase( 0 , 3 ) ;
		std::wstring wide ;
		if ( !wstringFromUtf8( content , &wide ) ) return -3 ;
		*utf8Text = content ;
		return 0 ;
	}

	// The OuPropertiesText syntax and metadata keys are ASCII. Decoding this
	// structural layer from raw bytes is safe for both UTF-8 and CP932 payloads.
	CNodeContainer metadata ;
	CConvNodeContainer metadataDecoder ;
	const bool hasMetadata = metadataDecoder.decode( content , &metadata ) >= 0 ;
	const std::string fileType = hasMetadata ? metadata.getValue( "FileType" ) : std::string() ;

	if ( fileType == "OuDia.1.10" )
	{
		// OuDia.1.10 defines UTF-8 regardless of whether the BOM is present.
		std::wstring wide ;
		if ( !wstringFromUtf8( content , &wide ) ) return -3 ;
		*utf8Text = content ;
		return 0 ;
	}
	if ( fileType != "OuDia.1.02" )
	{
		// Do not reinterpret an explicitly unknown/future format as CP932.
		// Known historical FileTypes (and very old files without FileType)
		// continue through the legacy CP932 conversion DLL chain.
		const bool isKnownLegacyFileType =
			fileType.empty() ||
			fileType == "OuDia.2" ||
			fileType == "OuDia.3" ||
			fileType == "OuDia.5" ||
			fileType == "OuDia.6" ||
			fileType == "OuDia.1.01" ;
		if ( !isKnownLegacyFileType ) return -3 ;
		return utf8OfCp932Bytes( content , utf8Text ) ? 0 : -3 ;
	}

	std::string utf8Candidate ;
	std::wstring wideCandidate ;
	const bool utf8Decodes = wstringFromUtf8( content , &wideCandidate ) ;
	if ( utf8Decodes ) utf8Candidate = content ;
	const bool utf8Parses = utf8Decodes && isValidCurrentOudText( utf8Candidate ) ;

	std::string cp932Candidate ;
	const bool cp932Decodes = utf8OfCp932Bytes( content , &cp932Candidate ) ;
	const bool cp932Parses = cp932Decodes && isValidCurrentOudText( cp932Candidate ) ;

	if ( utf8Parses && !cp932Parses )
	{
		*utf8Text = utf8Candidate ;
		return 0 ;
	}
	if ( cp932Parses && !utf8Parses )
	{
		*utf8Text = cp932Candidate ;
		return 0 ;
	}
	if ( !utf8Parses && !cp932Parses ) return -3 ;

	// Both interpretations produce a structurally valid OuDia document.
	// The save-comment version is not a reliable discriminator by itself.
	const std::string appComment = metadata.getValue( "FileTypeAppComment" ) ;
	std::wstring commentWide ;
	for ( std::string::const_iterator it = appComment.begin() ;
		it != appComment.end() ; ++it )
	{
		const unsigned char ch = (unsigned char)*it ;
		commentWide += ( ch >= 0x20 && ch < 0x7f ) ? (wchar_t)ch : L'?' ;
	}
	CString prompt ;
	if ( commentWide.empty() )
	{
		prompt = _T( "This .oud file has no UTF-8 BOM and is valid as both UTF-8 and CP932.\n\n"
			"Yes: open as UTF-8\nNo: open as CP932\nCancel: do not open" ) ;
	}
	else
	{
		prompt.Format( _T( "This .oud file has no UTF-8 BOM and is valid as both UTF-8 and CP932.\n"
			"Last saved by: %s\n\nYes: open as UTF-8\nNo: open as CP932\nCancel: do not open" ) ,
			commentWide.c_str() ) ;
	}
	const int choice = AfxMessageBox( prompt , MB_YESNOCANCEL | MB_ICONQUESTION ) ;
	if ( choice == IDYES )
	{
		*utf8Text = utf8Candidate ;
		return 0 ;
	}
	if ( choice == IDNO )
	{
		*utf8Text = cp932Candidate ;
		return 0 ;
	}
	return -4 ;
}

// --------------------------------
//@name	下請関数-WinDia形式
// --------------------------------
BOOL CDiagramEditDoc::OnOpenDocument_WinDia( LPCTSTR lpszPathName ) 
{
	LogMsg( "CDiagramEditDoc::OnOpenDocument_WinDia(%s)" , stringOf( std::wstring( lpszPathName ) ).c_str() ) ;
	int iRv = 0 ;

	// --------------------------------
	//	ファイルの内容を、stringに保存
	// --------------------------------
	string	aString ;
	CString	strError ;
	if ( iRv >= 0 ){
		int iResult = stringFromFile( &aString , std::wstring( lpszPathName ) ) ;
		//iResult = 
		//	-1: ファイルがオープンできません。
		//	-2 ; 読み込みに失敗しました。
		//	-3 ; ファイルには "\0" が含まれます(バイナリファイルであると 
		//	思われます)。
		//	 この場合、pString には、 "\0" の直前までのデータが格納されて 
		//	います。 
		if ( iResult < 0 ){
			iRv = iResult ;
			switch( iResult ){
			 case -1 :	// ファイルがオープンできません。
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILENOTFOUND ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -2 :	//; 読み込みに失敗しました。
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEREAD ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -3 :	// ファイルには "\0" が含まれます
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEFORMAT ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			}
			//iRv = 
			//	-1: ファイルがオープンできません。
			//	-2 ; 読み込みに失敗しました。
			//	-3 ; ファイルには "\0" が含まれます(バイナリファイルであると 
			//	思われます)。
			//	 この場合、pString には、 "\0" の直前までのデータが格納されて 
			//	います。 
		}
	}
	//aString = ファイルの内容を保持します。

	LogMsg( "CDiagramEditDoc::OnOpenDocument_WinDia()1" ) ;

	// --------------------------------
	//	ファイルの内容の文字列を解釈
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
	//	路線ビューを更新
	// --------------------------------
	getCDiagramEditApp()->getCDlgRosenView()->OnUpdate( NULL , 0 , NULL ) ;

	// --------------------------------
	LogMsg( "CDiagramEditDoc::OnOpenDocument_WinDia()=%d" , iRv ) ;
	if ( iRv < 0 ){
		if ( strError.IsEmpty() ){
			CString	strFmt ;
			strFmt.LoadString( IDS_ERR_ERRORCODE ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
			strError.Format( strFmt , iRv ) ;
		}
		AfxMessageBox( LocalizeUiText(std::wstring((LPCTSTR)strError)).c_str() , MB_ICONSTOP ) ; 
		return ( FALSE ) ;
	}
	//	ドキュメントのファイル名は、
	//	CDiagramEditDoc::SetPathName()でチェックされます。
	//	拡張子 .dia は、ドキュメントの有効なファイル名とは
	//	しません(.dia への上書き保存はしません)
	return TRUE;

}

	
BOOL CDiagramEditDoc::OnSaveDocument_WinDia(  LPCTSTR lpszPathName ) 
{
	/*
	 *	OnSaveDocument() の下請関数です。
	 *	ドキュメントの内容を、WinDia 形式のファイルに保存します。
	 * @param lpszPathName [in]
	 * 	保存するファイル名を指定して下さい。
	 * @return
	 *	成功したら TRUE ・ エラーなら FALSE です。
	 *
	 *	この関数は、エラーの場合はメッセージボックスを表示します。
	 */
	// --------------------------------
	int iRv = 0 ;

	CString	strError ;
	string	aString ;

	// --------------------------------
	//	保存するダイヤを選択
	// --------------------------------
	int idxDia = -1 ;
	if ( iRv >= 0 ){
		CentDedRosen* pCentDedRosen = m_CDedRosenFileData.getCentDedRosen();
		if ( pCentDedRosen->getCentDedDiaCont()->getMuPtr()->size() == 0 )
		{
			iRv = -101 ;	//	ダイヤが存在しません。
			CString strFmt ;
			strFmt.LoadString( IDS_ERR_NoDia ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
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
	//idxDia = 選択されたダイヤのインデクス
	// --------------------------------
	//	WinDIA形式のファイルの文字列を作成
	// --------------------------------
	if ( iRv >= 0 ){
		CconvWinDia aCconvWinDia ;
		int iResult = aCconvWinDia.CDedRosenFileData_To_WinDiaFileString( &m_CDedRosenFileData ,idxDia , &aString ) ;
		//iResult = 
		//	-21 ;	//	WinDIA 形式では、列車種別は24種類までに制限されています。
		//	-22 ;	//	略称の長さが半角５文字を超える列車種別があります。
		//			//	WinDIA 形式に保存するためには、すべての列車種別略称は
		//			//	全角２文字以内でなくてはなりません。
		//	-1 ;	//	idxDia の指定が不正です。
		if ( iResult < 0 ){
			iRv = iResult ;
			switch( iResult ){
			 case -21 : //	WinDIA 形式では、列車種別は24種類までに制限されています。
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_RessyasyubetsuTooMany ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -22 :	//	略称の長さが半角５文字を超える列車種別があります。
				 {
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_RyakusyouTooLong ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				 }
			}
			//iRv = 
			//	-	-21 ;	//	WinDIA 形式では、列車種別は24種類までに制限されています。
			//	-	-22 :	//	略称の長さが半角５文字を超える列車種別があります。
			//	-	-1 ;	//	idxDia の指定が不正です。
		}
	}	
	//aString = ファイルに書き込む『路線ファイル』形式の文字列を保持します。

	// --------------------------------
	//	ファイルの保存
	// --------------------------------
	LogMsg( "CDiagramEditDoc::OnSaveDocument()1" ) ;
	if ( iRv >= 0 ){
		int iResult = stringToFile( aString , std::wstring( lpszPathName ) ) ;
		//iResult = 
		//	-1: ファイルがオープンできません。
		//	-2 ; // 書き込みに失敗しました。 
		if ( iResult < 0 ){
			switch( iResult ){
			 case -1 :	// ファイルがオープンできません。
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILECREATE ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -2 :	//;書き込みに失敗しました
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEWRITE ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			}
			//iRv = 
			//	-1: ファイルがオープンできません。
			//	-2 ; 書き込みに失敗しました
			iRv = iResult - 100 ;
		}
	}

	// --------------------------------
	LogMsg( "CDiagramEditDoc::OnSaveDocument()=%d" , iRv ) ;

	if ( iRv < 0 ){
		if ( strError.IsEmpty() ){
			CString	strFmt ;
			strFmt.LoadString( IDS_ERR_ERRORCODE ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
			strError.Format( strFmt , iRv ) ;
		}
		AfxMessageBox( LocalizeUiText(std::wstring((LPCTSTR)strError)).c_str() , MB_ICONSTOP ) ; 
		return ( FALSE ) ;
	}

	//	WinDIA 形式の保存は、正式なドキュメントの保存とはしません。
	//	WinDIA 形式の保存に成功しても、ドキュメントファイル名は
	//	WinDIA ファイルのファイル名にはしません。
	//	ドキュメントの変更フラグも、クリアしません。
	//	（WinDIAファイルは、ドキュメント全体を保持することが
	//	できないためです。）
	//	このため、以下の処理は行いません
	// --------------------------------
	//	SetModifiedFlag( FALSE ) ;
	//	return TRUE;
	// --------------------------------
	
	//iRv = 
	//	-	-101 ;	//	ダイヤが存在しません。
	//	-	-21 ;	//	WinDIA 形式では、列車種別は24種類までに制限されています。
	//	-	-22 :	//	略称の長さが半角５文字を超える列車種別があります。
	//	-	-1 ;	//	idxDia の指定が不正です。
	//	-	-201: ファイルがオープンできません。
	//	-	-202 ; 書き込みに失敗しました
	return FALSE ;
}
	

// ********************************
//	CHidemdiRootDoc
// ********************************
void CDiagramEditDoc::UpdateAllSubDocviews( CView* pSender
							, LPARAM lHint , CObject* pHint )
{
	// --------------------------------
	//	時刻表・ダイヤグラムビューに対応する
	//	ダイヤが削除されていたら、
	//	対応するサブViewを閉じます。
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
						//	このドキュメントに対応するダイヤは削除されました
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
						//	このドキュメントに対応するダイヤは削除されました
						pCDedDiagramDoc->OnCloseDocument() ;
						pLDocument = NULL ;
					}
				}
			}
		}
	}
	// --------------------------------
	//	すべてのサブViewを更新
	// --------------------------------
	super::UpdateAllSubDocviews( pSender , lHint , pHint );
	// --------------------------------
	//	路線Viewを更新
	// --------------------------------
	getCDiagramEditApp()->getCDlgRosenView()->OnUpdate(  pSender , lHint , pHint ) ;

}

// ********************************
//	CDiagramEditDoc
// ********************************
	// ********************************
	//@name 包含
	// ********************************
const CDedRosenFileData*	CDiagramEditDoc::getCDedRosenFileData()const 
{
	return &m_CDedRosenFileData ;
}



	// ********************************
	//@name クリップボード操作
	// ********************************

UINT CDiagramEditDoc::getCF_CentDedEki()
{
	return RegisterClipboardFormat( _T("CF_CentDedEki_UTF8") ) ;
} ;

/**
	string を、クリップボードにコピーします。
@param aHwnd [in]
	クリップボードのオーナーとなるウインドウを指定してください。
@param uiClipboardFormat [in]
	クリップボードフォーマットを指定してください。
@param strData [in]
	クリップボードにコピーする文字列を指定してください。
@return
	成功したら 0 以上、エラーなら負の数です。
	-	-2 ;	//	メモリの確保に失敗しました。
	-	-11 ;	//	クリップボードがオープンできません。
	-	-12 ;	//	クリップボードへのデータ設定が失敗
*/
static int stringToClipboard(
		HWND aHwnd,
		UINT uiClipboardFormat,
		const string& strData )
{
	int iRv = 0 ;
	std::wstring wideData ;
	if ( !wstringFromUtf8( strData , &wideData ) )
	{
		iRv = -2 ;
	}

	HGLOBAL hUtf8 = NULL ;
	HGLOBAL hUnicode = NULL ;
	if ( iRv >= 0 )
	{
		hUtf8 = GlobalAlloc( GMEM_MOVEABLE , strData.size() + 1 ) ;
		if ( hUtf8 == NULL ) iRv = -2 ;
	}
	if ( iRv >= 0 )
	{
		void* p = GlobalLock( hUtf8 ) ;
		if ( p == NULL ) iRv = -2 ;
		else
		{
			memcpy( p , strData.c_str() , strData.size() + 1 ) ;
			GlobalUnlock( hUtf8 ) ;
		}
	}
	if ( iRv >= 0 )
	{
		const SIZE_T cbUnicode = ( wideData.size() + 1 ) * sizeof(wchar_t) ;
		hUnicode = GlobalAlloc( GMEM_MOVEABLE , cbUnicode ) ;
		if ( hUnicode == NULL ) iRv = -2 ;
	}
	if ( iRv >= 0 )
	{
		void* p = GlobalLock( hUnicode ) ;
		if ( p == NULL ) iRv = -2 ;
		else
		{
			memcpy( p , wideData.c_str() ,
				( wideData.size() + 1 ) * sizeof(wchar_t) ) ;
			GlobalUnlock( hUnicode ) ;
		}
	}

	bool bIsOpen = false ;
	if ( iRv >= 0 )
	{
		if ( !OpenClipboard( aHwnd ) ) iRv = -11 ;
		else bIsOpen = true ;
	}
	if ( iRv >= 0 )
	{
		EmptyClipboard() ;
		if ( SetClipboardData( uiClipboardFormat , hUtf8 ) == NULL )
			iRv = -12 ;
		else hUtf8 = NULL ;
		if ( iRv >= 0 )
		{
			if ( SetClipboardData( CF_UNICODETEXT , hUnicode ) == NULL )
				iRv = -12 ;
			else hUnicode = NULL ;
		}
	}
	if ( bIsOpen ) CloseClipboard() ;
	if ( hUtf8 != NULL ) GlobalFree( hUtf8 ) ;
	if ( hUnicode != NULL ) GlobalFree( hUnicode ) ;
	return iRv ;
}

static int stringFromClipboard(
		HWND aHwnd,
		UINT uiClipboardFormat,
		string* pstrData )
{
	int iRv = 0 ;
	string strData ;
	bool bIsOpen = false ;
	if ( pstrData == NULL )
	{
		iRv = -1 ;
	}
	if ( iRv >= 0 &&
		!IsClipboardFormatAvailable( uiClipboardFormat ) &&
		!IsClipboardFormatAvailable( CF_UNICODETEXT ) )
	{
		iRv = -1 ;
	}
	if ( iRv >= 0 )
	{
		if ( !OpenClipboard( aHwnd ) ) iRv = -11 ;
		else bIsOpen = true ;
	}

	// The application-specific formats carry UTF-8 bytes. CF_UNICODETEXT
	// remains UTF-16 for interoperability with standard Windows applications.
	bool bGotPrivateFormat = false ;
	if ( iRv >= 0 && IsClipboardFormatAvailable( uiClipboardFormat ) )
	{
		HGLOBAL hGlobal = GetClipboardData( uiClipboardFormat ) ;
		if ( hGlobal != NULL )
		{
			const char* pData = (const char*)GlobalLock( hGlobal ) ;
			if ( pData != NULL )
			{
				std::string utf8Data( pData ) ;
				GlobalUnlock( hGlobal ) ;
				std::wstring wideCheck ;
				if ( wstringFromUtf8( utf8Data , &wideCheck ) )
				{
					strData = utf8Data ;
					bGotPrivateFormat = true ;
				}
			}
		}
	}

	// Fall back to the standard UTF-16 representation if the private
	// UTF-8 format is unavailable or contains invalid UTF-8.
	if ( iRv >= 0 && !bGotPrivateFormat &&
		IsClipboardFormatAvailable( CF_UNICODETEXT ) )
	{
		HGLOBAL hUnicode = GetClipboardData( CF_UNICODETEXT ) ;
		if ( hUnicode != NULL )
		{
			const wchar_t* pWide = (const wchar_t*)GlobalLock( hUnicode ) ;
			if ( pWide != NULL )
			{
				std::wstring wide( pWide ) ;
				GlobalUnlock( hUnicode ) ;
				if ( !utf8Of( wide , &strData ) ) iRv = -12 ;
			}
		}
	}
	if ( bIsOpen ) CloseClipboard() ;
	if ( iRv >= 0 && !bGotPrivateFormat && strData.empty() )
	{
		iRv = -1 ;
	}
	if ( pstrData != NULL ) *pstrData = strData ;
	return iRv ;
}

int CDiagramEditDoc::CentDedEki_To_Cliboard( 
	const Mu<CentDedEki>* pMuCentDedEki ) 
{
	int iRv = 0 ;

	// --------------------------------
	//	Mu から EkiCont に変換
	// --------------------------------
	CentDedEkiCont	aEkiCont ;
	if ( iRv >= 0 )
	{
		CaMui<CentDedEki> aCaMui( &aEkiCont ) ;
		aCaMui.insert( pMuCentDedEki ) ;
	}

	// --------------------------------
	//	データを文字列化
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
			iRv = -1 ;	//	CentDedEki の内容が不正です。
		}
		else
		{
			CConvNodeContainer	aCConvNodeContainer ;
			strData = aCConvNodeContainer.encode( &aCNodeContainer ) ;
			if ( strData.length() == 0 )
			{
				iRv = -1 ;	//	CentDedEki の内容が不正です。
			}
		}
	}
	//strData = CentDedEki の内容

	// --------------------------------
	//	クリップボードへの転送
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult = stringToClipboard(  
			AfxGetMainWnd()->GetSafeHwnd() ,
			getCF_CentDedEki() , 
			strData ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	クリップボードへのデータ設定が失敗
		}
	}
	return iRv ;
}

int CDiagramEditDoc::CentDedEki_From_Cliboard( 
		Mui<CentDedEki>* pCentDedEki ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	クリップボードからデータを取得
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 )
	{	
		if (!IsClipboardFormatAvailable(getCF_CentDedEki()) &&
			!IsClipboardFormatAvailable( CF_UNICODETEXT )) 
		{
			iRv = -1 ;	//	クリップボードには有効なデータはありません。
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
			iRv = -2 ;	//	クリップボードからの読み込みに失敗しました。	
		}
	}
	//strData = CentDedEki の内容
	// --------------------------------
	//	文字列から駅データを作成
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
			iRv = -3 ;	//	クリップボードの内容が不正です。
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
		//	-22 ; // Ekijikokukeisiki の値が不正です。
		//	-32 ; // Ekikibo の値が不正です。 
		if ( iRv < 0 )
		{
			iRv = -4 ;	//	CentDedEki の内容が不正です。
		}
	}

	// --------------------------------
	//	Mu から EkiCont に変換
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
	return ( IsClipboardFormatAvailable( getCF_CentDedEki() ) != 0 ||
		IsClipboardFormatAvailable( CF_UNICODETEXT ) != 0 );
}

UINT CDiagramEditDoc::getCF_CentDedRessyasyubetsu()
{
	return RegisterClipboardFormat( _T("CF_CentDedRessyasyubetsu_UTF8") ) ;
} ;

int CDiagramEditDoc::CentDedRessyasyubetsu_To_Cliboard( 
		const Mu<CentDedRessyasyubetsu>* pMuCentDedRessyasyubetsu ) 
{
	int iRv = 0 ;

	// --------------------------------
	//	Mu から CentDedRessyasyubetsuCont に変換
	// --------------------------------
	CentDedRessyasyubetsuCont	aRessyasyubetsuCont ;
	if ( iRv >= 0 )
	{
		CaMui<CentDedRessyasyubetsu> aCaMui( &aRessyasyubetsuCont ) ;
		aCaMui.insert( pMuCentDedRessyasyubetsu ) ;
	}
	// --------------------------------
	//	データを文字列化
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
		//	-	-11 ;	//	Syubetsumei が指定されていません。
		//	-	-52 ;	//	DiagramSenStyle の値が不正です。
		if ( iRv < 0 )
		{
			iRv = -1 ;	//	CentDedRessyasyubetsuCont の内容が不正です。
		}
		else
		{
			CConvNodeContainer	aCConvNodeContainer ;
			strData = aCConvNodeContainer.encode( &aCNodeContainer ) ;
			if ( strData.length() == 0 )
			{
				iRv = -1 ;	//	CentDedRessyasyubetsu の内容が不正です。
			}
		}
	}
	//strData = CentDedRessyasyubetsu の内容	return iRv ;
	// --------------------------------
	//	クリップボードへの転送
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult = stringToClipboard(  
			AfxGetMainWnd()->GetSafeHwnd() ,
			getCF_CentDedRessyasyubetsu() , 
			strData ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	クリップボードへのデータ設定が失敗
		}
	}
	return iRv ;
}

int CDiagramEditDoc::CentDedRessyasyubetsu_From_Cliboard( 
	Mui<CentDedRessyasyubetsu>* pMuCentDedRessyasyubetsu ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	クリップボードからデータを取得
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 )
	{	
		if (!IsClipboardFormatAvailable(getCF_CentDedRessyasyubetsu()) &&
			!IsClipboardFormatAvailable( CF_UNICODETEXT )) 
		{
			iRv = -1 ;	//	クリップボードには有効なデータはありません。
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
			iRv = -2 ;	//	クリップボードからの読み込みに失敗しました。	
		}
	}
	//strData = CentDedEki の内容
	// --------------------------------
	//	文字列から列車種別データを作成
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
			iRv = -3 ;	//	クリップボードの内容が不正です。
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
		//-	-11 ;	//	Syubetsumei が指定されていません。
		//-	-52 ;	//	DiagramSenStyle の値が不正です。
		//-	-101 ;	//	値の形式が正しくありません。
		if ( iRv < 0 )
		{
			iRv = -4 ;	//	CentDedEki の内容が不正です。
		}
	}
	// --------------------------------
	//	Mu から EkiCont に変換
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
	return ( IsClipboardFormatAvailable( getCF_CentDedRessyasyubetsu() ) != 0 ||
		IsClipboardFormatAvailable( CF_UNICODETEXT ) != 0 );
}

UINT CDiagramEditDoc::getCF_CentDedRessyaCont() 
{
	return RegisterClipboardFormat( _T("CF_CentDedRessyaCont_UTF8") ) ;
}

int CDiagramEditDoc::CentDedRessyaCont_To_Cliboard( 
		const CentDedRessyaCont& aCentDedRessyaCont ) 
{
	int iRv = 0 ;

	// --------------------------------
	//	データを文字列化
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
			iRv = -1 ;	//	aCentDedRessyaCont の内容が不正です。
		}
		else
		{
			CConvNodeContainer	aCConvNodeContainer ;
			strData = aCConvNodeContainer.encode( &aCNodeContainer ) ;
			if ( strData.length() == 0 )
			{
				iRv = -1 ;	//	aCentDedRessyaCont の内容が不正です。
			}
		}
	}
	//string = aCentDedRessyaCont の内容

	// --------------------------------
	//	クリップボードへの転送
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult = stringToClipboard(  
			AfxGetMainWnd()->GetSafeHwnd() ,
			getCF_CentDedRessyaCont() , 
			strData ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	クリップボードへのデータ設定が失敗
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
	//	クリップボードからデータを取得
	// --------------------------------
	string	strData ;
	if ( iRv >= 0 ){	
		if (!IsClipboardFormatAvailable(getCF_CentDedRessyaCont()) &&
			!IsClipboardFormatAvailable( CF_UNICODETEXT )) {
			iRv = -1 ;	//	クリップボードには有効なデータはありません。
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
			iRv = -2 ;	//	クリップボードからの読み込みに失敗しました。	
		}
	}
	//strData = CentDedRessyaCont の内容
	// --------------------------------
	//	文字列から列車データを作成
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
			iRv = -3 ;	//	クリップボードの内容が不正です。
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
			iRv = -4 ;	//	CentDedRessyaCont の内容が不正です。
		}
	}
	//pCentDedRessyaCont = CentDedRessyaCont の内容

	// --------------------------------
	return ( iRv ) ;
}

bool CDiagramEditDoc::CentDedRessyaCont_IsClipboardFormatAvailable() 
{
	return ( IsClipboardFormatAvailable( getCF_CentDedRessyaCont() ) != 0 ||
		IsClipboardFormatAvailable( CF_UNICODETEXT ) != 0 );
}
	// ********************************
	//@name 操作
	// ********************************
int CDiagramEditDoc::executeEditCmd( Ou< CRfEditCmd > pCmd ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	コマンドを実行
	// --------------------------------
	if ( iRv >= 0 )
	{
		iRv = pCmd->execute( &m_CDedRosenFileData ) ;
	}
	// --------------------------------
	//	ビューの更新
	// --------------------------------
	if ( iRv >= 0 )
	{
		UpdateAllSubDocviews( NULL , 0 , 
			&CRfEditCmdHolder( pCmd ) ) ;
	}
	// --------------------------------
	//	Undo,Redo関係内部データ を更新
	//	Undo情報の保存/Redo情報はクリア
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
	//	ModifiedFlag を更新
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
	//	コマンドをキューから取得
	// --------------------------------
	if ( iRv >= 0 ){
		if ( m_contUndo.size() >= 1 ){
			pCmd = m_contUndo.get( INT_MAX ) ;
		}	else	{
			iRv = -1 ;	//	undo 情報がありません。
		}
	}
	//pcmdUndo = undo のためのコマンド
	// --------------------------------
	//	コマンドを実行
	// --------------------------------
	Ou< CRfEditCmd >	pUndoCmd ;
	if ( iRv >= 0 ){
		pUndoCmd = pCmd->createUndoCmd() ;
		if ( pUndoCmd == NULL ){
			iRv = -2 ;	//	undo の実行に失敗
		}
	}
	if ( iRv >= 0 ){
		int iResult  = pUndoCmd->execute( &m_CDedRosenFileData ) ;
		if ( iResult < 0 ){
			iRv = -2 ;	//	undo の実行に失敗
		}
	}
	// --------------------------------
	//	ビューの更新
	// --------------------------------
	if ( iRv >= 0 ){
		UpdateAllSubDocviews( NULL , 0 , 
			&CRfEditCmdHolder( pUndoCmd ) ) ;
	}
	// --------------------------------
	//	Undo,Redo関係内部データ を更新
	//	Undo情報をRedo情報に移動
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
	//	ModifiedFlag を更新
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
	//	コマンドをキューから取得
	// --------------------------------
	if ( iRv >= 0 ){
		if ( m_contRedo.size() >= 1 ){
			pCmd = m_contRedo.get( INT_MAX ) ;
		}	else	{
			iRv = -1 ;	//	redo 情報がありません。
		}
	}
	//pcmdUndo = undo のためのコマンド
	// --------------------------------
	//	コマンドを実行
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult  = pCmd->execute( &m_CDedRosenFileData ) ;
		if ( iResult < 0 ){
			iRv = -2 ;	//	redo の実行に失敗
		}
	}
	// --------------------------------
	//	ビューの更新
	// --------------------------------
	if ( iRv >= 0 ){
		UpdateAllSubDocviews( NULL , 0 , 
			&CRfEditCmdHolder( pCmd ) ) ;
	}
	// --------------------------------
	//	Undo,Redo関係内部データ を更新
	//	Redo情報をUndo情報に移動
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
	//	ModifiedFlag を更新
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
// CDiagramEditDoc クラスの構築/消滅

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

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




/////////////////////////////////////////////////////////////////////////////
// CDiagramEditDoc クラスの診断

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
// CDiagramEditDoc コマンド

void CDiagramEditDoc::DeleteContents() 
{
	m_CDedRosenFileData.clear() ;
	// --------------------------------
	//	Undo,Redo関係内部データ を更新
	// --------------------------------
	m_contUndo.erase( 0 , INT_MAX ) ;
	m_contRedo.erase( 0 , INT_MAX ) ;
	m_iModifyCountFromDoc = 0 ;

	// --------------------------------
	//	路線ビューを更新
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
					strError += _T( "\n" ) ;
					strError += aCConvFileDll.getDllFilename().c_str()  ;
					iRv = -101 ;
				}
				else
				{
					pIfConvFile = aCConvFileDll.getIfConvFile() ;
				}
			}
			//aCConvFileDll = DLLをロードしました。
	
			LogMsg( "CDiagramEditDoc::OnOpenDocument()31" ) ;
			if ( iRv >= 0 )
			{
				std::vector<char>	binFileContentNew ;
				int iResult = pIfConvFile->isLeftFormat( 
					&CaByteBuffer_vector< std::vector< char > >( pbinFileContent ) ) ;
				LogMsg( "CDiagramEditDoc::OnOpenDocument()32" ) ;
				if ( iResult >= 0 )
				{
					//	FileFormat が、このDLLであることが確認できました。
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
						strError += _T( "\n" ) ;
						//strError += aCConvFileDll.getDllFilename().c_str()  ;
						if ( strErrorInfoString.size() > 0 )
						{
							strError += wstringOf( strErrorInfoString ).c_str() ;
							strError += _T( "\n" ) ;
						}
						iRv = -102 ;	//	ファイルの変換に失敗しました。
					}
				}
				else	
				{
					iRv = -1 ;	//このDLLがサポートするファイル形式ではありませんでした。
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

	LogMsg( "CDiagramEditDoc::OnOpenDocument(%s)" , stringOf( std::wstring( lpszPathName ) ).c_str() ) ;
	//	Serialize は使いません。
	//
	//if (!CHidemdiRootDoc::OnOpenDocument(lpszPathName))
	//	return FALSE;

	// --------------------------------
	//	拡張子が .dia なら、
	//	WinDIA の処理
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
	//	ファイルの内容を、stringに保存
	// --------------------------------
	string	strFile ;
	if ( iRv >= 0 )
	{
		std::string rawFileBytes ;
		int iResult = stringFromFile( &rawFileBytes , std::wstring( lpszPathName ) ) ;
		if ( iResult >= 0 )
		{
			iResult = utf8TextOfOudFileBytes( rawFileBytes , &strFile ) ;
		}
		//iResult = 
		//	-1: ファイルがオープンできません。
		//	-2 ; 読み込みに失敗しました。
		//	-3 ; ファイルには "\0" が含まれます(バイナリファイルであると 
		//	思われます)。
		//	 この場合、pString には、 "\0" の直前までのデータが格納されて 
		//	います。 
		if ( iResult < 0 ){
			iRv = iResult ;
			switch( iResult ){
			 case -1 :	// ファイルがオープンできません。
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILENOTFOUND ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -2 :	//; 読み込みに失敗しました。
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEREAD ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;
			 case -3 :	// ファイルには "\0" が含まれます
				{
					CString	strFmt ;
					strFmt.LoadString( IDS_ERR_FILEFORMAT ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
					strError.Format( strFmt , lpszPathName ) ;
				}
				break ;

			}
			//iRv = 
			//	-1: ファイルがオープンできません。
			//	-2 ; 読み込みに失敗しました。
			//	-3 ; ファイルには "\0" が含まれます(バイナリファイルであると 
			//	思われます)。
			//	 この場合、pString には、 "\0" の直前までのデータが格納されて 
			//	います。 
		}
	}
	//strFile = ファイルの内容

	string strOudFile = strFile ;
	//strOudFile = ファイルの内容を保持します。
	//	但し、このファイルのフォーマットが古い場合は、
	//	今後の処理で内容が代わります。


	LogMsg( "CDiagramEditDoc::OnOpenDocument()1" ) ;



	// --------------------------------
	//	ファイルが解釈不能の場合は
	//	変換を試みます。
	// --------------------------------
	CconvCDedRosenFileData	aConv ;
	if ( iRv >= 0 && aConv.isEncodeAbleFormat( strOudFile ) < 0 )
	{
		LogMsg( "CDiagramEditDoc::OnOpenDocument()2" ) ;
		
		bool	bFileTypeDetected = false ;
		std::vector<char>	binFileContent ;
		std::string strLegacyCp932 ;
		if ( !cp932BytesOfUtf8( strCrlfOf( strOudFile ) ,
			&strLegacyCp932 ) )
		{
			iRv = -32 ; // The legacy converter only accepts CP932 text.
		}
		else
		{
			binFileContent = vectorCharOf( strLegacyCp932 ) ;
		}

		LogMsg( "CDiagramEditDoc::OnOpenDocument()3" ) ;

		// --------------------------------
		//	ファイル変換を順次実行
		// --------------------------------
		const TCHAR* const arstrConvFileDllFilename[] = 
		{
			_T("ConvFileOudia02To03.dll" ),		//	Ver01,Ver02 → Ver03 に変換
			_T(  "ConvFileOudia03To05.dll"  ) , //	Ver03 → Ver05 に変換
			_T( "ConvFileOudia05To06.dll"  ) ,	//	Ver05 → Ver06 に変換
			_T( "ConvFileOudia06To101.dll" ) ,	//	Ver06 → Ver1.01 に変換
			_T( "ConvFileOudia101To102.dll" ) ,	//	Ver1.01 → Ver1.02 に変換
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
				//	フォーマットが認識できない場合は、
				//	他のフォーマット変換を試行するため、
				//	エラーにはしません。
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
			iRv = -31 ;	// FileTypeが認識できません。
				//iRv = 
				//	-31 ; // FileTypeが認識できません。
		}
		if ( iRv >= 0 )
		{
			std::string strConvertedCp932 = stringOf( binFileContent ) ;
			std::string strConvertedUtf8 ;
			if ( !utf8OfCp932Bytes( strConvertedCp932 ,
				&strConvertedUtf8 ) )
			{
				iRv = -33 ; // Converter returned invalid CP932 text.
			}
			else
			{
				strOudFile = strLfOf( strConvertedUtf8 ) ;
			}
		}
		LogMsg( "CDiagramEditDoc::OnOpenDocument()101" ) ;
	}
	//strOudFile = 旧バージョンファイルから変換後の内容に変わりました。

	// --------------------------------
	//	CDedRosenFileData
	//	カレントバージョンファイル
	//	aString ファイルの内容を解釈します。
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
		//	-	-1 ;	//	ディレクトリが途中で閉じています。	
		//	-	-1001 ;	//	FileType が正しくありません。
		//	-	-1002 ;	//	Rosen Directoryが見つかりません。
		//	-	-1022 ;	//	Ekijikokukeisiki の値が不正です。
		//	-	-1032 ;	//	Ekikibo の値が不正です。
		//	-	-1101 ;	//	Eki がディレクトリではありません。
		//	-	-1111 ;	//	Syubetsumei が指定されていません。
		//	-	-1152 ;	//	DiagramSenStyle の値が不正です。
		//	-	-1201 ;	//	Ressyasyubetsu がディレクトリではありません。
		//	-	-1211 ;	//	DiaName が指定されていません。
		//	-	-1212 ;	//	RessyaContが見つかりません。
		//	-	-1352 ;	//	起点時刻の設定が不適切です。
		//	-	-1003 ;	//	DispProp Directoryが見つかりません。
		//	-	-1512 ;	//	JikokuhyouFont の内容が不正です。
		//	-	-1522 ;	//	DiaEkimeiFont の内容が不正です。
		//	-	-1532 ;	//	DiaJikokuFont の内容が不正です。
		//	-	-1582 ;	//	DisplayRessyabangou が不正です。
		//	-	-1592 ;	//	DisplayRessyamei が不正です。
		//	-	-1602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari が不正です。
		//	-	-1612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori が不正です。
		if ( iResult < 0 )
		{
			iRv = iResult ;
			//iRv = 
			//	-	-1 ;	//	ディレクトリが途中で閉じています。	
			//	-	-1001 ;	//	FileType が正しくありません。
			//	-	-1002 ;	//	Rosen Directoryが見つかりません。
			//	-	-1022 ;	//	Ekijikokukeisiki の値が不正です。
			//	-	-1032 ;	//	Ekikibo の値が不正です。
			//	-	-1101 ;	//	Eki がディレクトリではありません。
			//	-	-1111 ;	//	Syubetsumei が指定されていません。
			//	-	-1152 ;	//	DiagramSenStyle の値が不正です。
			//	-	-1201 ;	//	Ressyasyubetsu がディレクトリではありません。
			//	-	-1211 ;	//	DiaName が指定されていません。
			//	-	-1212 ;	//	RessyaContが見つかりません。
			//	-	-1352 ;	//	起点時刻の設定が不適切です。
			//	-	-1003 ;	//	DispProp Directoryが見つかりません。
			//	-	-1512 ;	//	JikokuhyouFont の内容が不正です。
			//	-	-1522 ;	//	DiaEkimeiFont の内容が不正です。
			//	-	-1532 ;	//	DiaJikokuFont の内容が不正です。
			//	-	-1582 ;	//	DisplayRessyabangou が不正です。
			//	-	-1592 ;	//	DisplayRessyamei が不正です。
			//	-	-1602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari が不正です。
			//	-	-1612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori が不正です。

			{
				CString	strFmt ;
				strFmt.LoadString( IDS_ERR_FILEFORMAT_ERRORCODE ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
				strError.Format( strFmt , lpszPathName , iRv ) ;
			}

			string strOuErrorInfoText = aCOuErrorInfoContainer.toOuErrorInfoText() ;
			if ( !strOuErrorInfoText.empty() )
			{
				strError += _T( "\n\n" ) ;
				strError += _T( "(" ) ;
				strError += wstringOf( strOuErrorInfoText ).c_str() ;
				strError += _T( ")" ) ;
			}

		}
		else
		{
			m_CDedRosenFileData = aCDedRosenFileData ;
		}
	}


	// --------------------------------
	//	路線ビューを更新
	// --------------------------------
	getCDiagramEditApp()->getCDlgRosenView()->OnUpdate( NULL , 0 , NULL ) ;
	// --------------------------------
	//	エラーメッセージの表示
	// --------------------------------
	LogMsg( "CDiagramEditDoc::OnOpenDocument()=%d" , iRv ) ;
	if ( iRv < 0 && iRv != -4 )
	{
		string strFileTypeAppComment ;
		//	strFileTypeAppComment を取得
		CNodeContainer aCNodeContainer ;
		CConvNodeContainer aCConvNodeContainer ;
		int iResult = aCConvNodeContainer.decode( 
			strFile , 
			&aCNodeContainer ) ;
		if ( iResult >= 0 )
		{
			strFileTypeAppComment = aCNodeContainer.getValue( nameFileTypeAppComment );
		}
		//strFileTypeAppComment = 項目名 FileTypeAppComment の内容

		
		if ( strError.IsEmpty() )
		{
			CString	strFmt ;
			strFmt.LoadString( IDS_ERR_ERRORCODE ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
			strError.Format( strFmt , iRv ) ;
		}
		if ( !strFileTypeAppComment.empty() )
		{
			CString strFmt ;
			strFmt.LoadString( IDS_ERR_FileTypeAppComment ) ;
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
			CString strLs ;
			strLs.Format( strFmt , wstringOf( strFileTypeAppComment ).c_str() ) ;
			strError += _T( "\n\n(" ) ;
			strError += strLs ;
			strError += _T( ")" ) ;

		}
		AfxMessageBox( LocalizeUiText(std::wstring((LPCTSTR)strError)).c_str() , MB_ICONSTOP ) ; 
	}
	return ( iRv >= 0 ) ;
}
BOOL CDiagramEditDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	CWaitCursor	aCWaitCursor ;

	
	LogMsg( "CDiagramEditDoc::OnSaveDocument(%s)" , stringOf( std::wstring( lpszPathName ) ).c_str() ) ;
	//Serialize() は使いません。
	//
	//return CHidemdiRootDoc::OnSaveDocument(lpszPathName);


	// --------------------------------
	//	拡張子が .dia なら、
	//	WinDIA の処理
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
	//	ファイルの内容のCdConnectedString2を作成
	// --------------------------------
	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData aConv ;
		int iResult = aConv.CDedRosenFileData_to_OuPropertiesText( 
			&m_CDedRosenFileData , 
			&aCNodeContainer ) ;
		//iResult = 
		//		-	-22 ;	//	Ekijikokukeisiki の値が不正です。
		//		-	-32 ;	//	Ekikibo の値が不正です。
		//		-	-111 ;	//	Syubetsumei が指定されていません。
		//		-	-152 ;	//	DiagramSenStyle の値が不正です。
		//		-	-212 ;	//	DiagramEkiatsukai の値が不正です。
		if ( iResult < 0 )
		{
			iRv = iResult ;
			strError.Format( IDS_ERR_FILEFORMAT , lpszPathName ) ;
			//iRv = 
			//		-	-22 ;	//	Ekijikokukeisiki の値が不正です。
			//		-	-32 ;	//	Ekikibo の値が不正です。
			//		-	-111 ;	//	Syubetsumei が指定されていません。
			//		-	-152 ;	//	DiagramSenStyle の値が不正です。
			//		-	-212 ;	//	DiagramEkiatsukai の値が不正です。
		}
	}	
	//aString = ファイルに書き込む『路線ファイル』形式の文字列を保持します。

	LogMsg( "CDiagramEditDoc::OnSaveDocument()1" ) ;

	// --------------------------------
	//	FileTypeAppComment を付与
	// --------------------------------
	if ( iRv >= 0 )
	{
		string strFileTypeAppComment ;
		strFileTypeAppComment += stringOf( std::wstring( AfxGetAppName() ) ) ;
		strFileTypeAppComment += " Ver. " ;
		strFileTypeAppComment += getCDiagramEditApp()->getProgramVer() ;
		aCNodeContainer.setValue( nameFileTypeAppComment , strFileTypeAppComment );
	}
	
	// --------------------------------
	//	aCNodeContainer の内容を
	//	文字列に格納
	// --------------------------------
	string aString ;
	if ( iRv >= 0 ){
		//	CConnectedStringCompress による圧縮
		CConvNodeContainer aCConvNodeContainer ;
		aString = aCConvNodeContainer.encode( &aCNodeContainer ) ;
	}
	//	aString = ファイルに出力する文字列

	// --------------------------------
	//	stringの内容を、ファイルに書き込み
	// --------------------------------
	if ( iRv >= 0 ){
		int iResult = stringToFileUtf8( aString , std::wstring( lpszPathName ) ) ;
		//iResult = 
		//	-1: ファイルがオープンできません。
		//	-2 ; // 書き込みに失敗しました。 
		if ( iResult < 0 ){
			iRv = iResult ;
			switch( iResult ){
			 case -1 :	// ファイルがオープンできません。
				{
					CString	strFmt ;
					strError.Format( IDS_ERR_FILECREATE , lpszPathName ) ;
				}
				break ;
			 case -2 :	//;書き込みに失敗しました
				{
					CString	strFmt ;
					strError.Format( IDS_ERR_FILEWRITE , lpszPathName ) ;
				}
				break ;
			}
			//iRv = 
			//	-1: ファイルがオープンできません。
			//	-2 ; 書き込みに失敗しました。
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
		strFmt = LocalizeUiText(std::wstring((LPCTSTR)strFmt)).c_str();
			strError.Format( strFmt , iRv ) ;
		}
		AfxMessageBox( LocalizeUiText(std::wstring((LPCTSTR)strError)).c_str() , MB_ICONSTOP ) ; 
		return ( FALSE ) ;
	}
	//	保存に成功したら、明示的に
	//	変更フラグを解除しなくてはなりません。

	// --------------------------------
	//	Undo,Redo関係内部データ を更新
	//	Undo情報をRedo情報に移動
	// --------------------------------
	if ( iRv >= 0 )
	{
		m_iModifyCountFromDoc = 0 ;
	}

	// --------------------------------
	//	ModifiedFlag を更新
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
	//	名前を付けて保存 は、常時有効にしました。
	pCmdUI->Enable( TRUE ) ;
}

void CDiagramEditDoc::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU) 
{
	CdFilenameStr	aCdFilenameStr( lpszPathName ) ;
	if ( stricmp( "dia" , aCdFilenameStr.Extension().c_str() ) == 0 )
	{
		//	拡張子 .dia は、ドキュメントの有効なファイル名とは
		//	認めません。
		//	ただし、ドキュメントのタイトルとして、
		//	拡張子を取り除いた主ファイル名を設定します。

		if ( GetTitle().IsEmpty() )
		{
			SetTitle( wstringOf( aCdFilenameStr.BaseFilename() ).c_str() );
		}
		return ;
	}	
	
	CHidemdiRootDoc::SetPathName(
		wstringOf( aCdFilenameStr.FullpathFilename() ).c_str() , bAddToMRU);
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
