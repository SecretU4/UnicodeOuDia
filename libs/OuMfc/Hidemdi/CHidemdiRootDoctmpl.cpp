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
/*
// ****************************************************************
//	CHidemdiRootDoctmpl.cpp
// ****************************************************************
*/

#include "CHidemdiRootDoctmpl.h"
#include "CHidemdiRootFrame.h"
#include "CHidemdiRootView.h"
#include "CHidemdiApp.h" 

namespace OuMfc{
namespace Hidemdi{


// ****************************************************************
//	CHidemdiCSubdoctemplate
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CHidemdiRootDoctmpl::CHidemdiRootDoctmpl( UINT nIDResource
				, CRuntimeClass* pDocClass ) : 
	super( nIDResource , 
		pDocClass , 
		RUNTIME_CLASS(CHidemdiRootFrame) , 
		RUNTIME_CLASS(CHidemdiRootView) ) 
{
}
CHidemdiRootDoctmpl::~CHidemdiRootDoctmpl() 
{
}

// ********************************
//	CDocTemplate
// ********************************
CDocument* CHidemdiRootDoctmpl::OpenDocumentFile( LPCTSTR lpszPathName
								, BOOL bMakeVisible ) 
		//【オーバライド】
		//	既存のドキュメントをすべて閉じてから、
		//	新しいドキュメントを生成します。
{

	CDocument*	pRv = NULL ;
	BOOL	bLSaveIsContinued = TRUE ;

	//--------------------------------
	//	ルートドキュメントを保存
	//--------------------------------
	if ( bLSaveIsContinued ){
		bLSaveIsContinued = super::SaveAllModified() ;
			//bLSaveIsContinued = ルートドキュメントの保存が
			//	キャンセルされたら偽です
	}
	if ( bLSaveIsContinued )
	{
		//--------------------------------
		//	すべてのサブドキュメントを閉じる
		//--------------------------------
		CloseAllSubDocuviews( FALSE ) ;

		//--------------------------------
		//	ルートドキュメントがないなら生成
		//	あるなら、既存の要素を破棄
		//--------------------------------
		CDocument*	pDocument = ((CHidemdiApp*)AfxGetApp())->pRootDoc() ;
		if ( pDocument == NULL )
		{
			//	ルートDocumentがないなら生成
			pDocument = CreateNewDocument();

		}	else	{
			pDocument->DeleteContents() ;
		}

		//--------------------------------
		//	ファイル名が指定されていたら、
		//	ファイルを開く
		//--------------------------------
		if (lpszPathName == NULL)
		{
			// create a new document - with default document name
			SetDefaultTitle(pDocument);

			// avoid creating temporary compound file when starting up invisible
			if (!bMakeVisible)
				pDocument->m_bEmbedded = TRUE;

			if (!pDocument->OnNewDocument())
			{
				// user has be alerted to what failed in OnNewDocument
				TRACE0("CDocument::OnNewDocument returned FALSE.\n");
				//pFrame->DestroyWindow();
				return NULL;
			}

			// it worked, now bump untitled count
			m_nUntitledCount++;
		}
		else
		{
			// open an existing document
			CWaitCursor wait;
			if (!pDocument->OnOpenDocument(lpszPathName))
			{
				// user has be alerted to what failed in OnOpenDocument
				TRACE0("CDocument::OnOpenDocument returned FALSE.\n");
				//pFrame->DestroyWindow();
				return NULL;
			}
			pDocument->SetPathName(lpszPathName);
		}
		pRv = pDocument ;
	}

	return ( pRv ) ;
};
/*sankou
CDocument* CMultiDocTemplate::OpenDocumentFile(LPCTSTR lpszPathName,
	BOOL bMakeVisible)
{
	CDocument* pDocument = CreateNewDocument();
	if (pDocument == NULL)
	{
		TRACE0("CDocTemplate::CreateNewDocument returned NULL.\n");
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
		return NULL;
	}
	ASSERT_VALID(pDocument);

	BOOL bAutoDelete = pDocument->m_bAutoDelete;
	pDocument->m_bAutoDelete = FALSE;   // don't destroy if something goes wrong
	CFrameWnd* pFrame = CreateNewFrame(pDocument, NULL);
	pDocument->m_bAutoDelete = bAutoDelete;
	if (pFrame == NULL)
	{
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
		delete pDocument;       // explicit delete on error
		return NULL;
	}
	ASSERT_VALID(pFrame);

	if (lpszPathName == NULL)
	{
		// create a new document - with default document name
		SetDefaultTitle(pDocument);

		// avoid creating temporary compound file when starting up invisible
		if (!bMakeVisible)
			pDocument->m_bEmbedded = TRUE;

		if (!pDocument->OnNewDocument())
		{
			// user has be alerted to what failed in OnNewDocument
			TRACE0("CDocument::OnNewDocument returned FALSE.\n");
			pFrame->DestroyWindow();
			return NULL;
		}

		// it worked, now bump untitled count
		m_nUntitledCount++;
	}
	else
	{
		// open an existing document
		CWaitCursor wait;
		if (!pDocument->OnOpenDocument(lpszPathName))
		{
			// user has be alerted to what failed in OnOpenDocument
			TRACE0("CDocument::OnOpenDocument returned FALSE.\n");
			pFrame->DestroyWindow();
			return NULL;
		}
		pDocument->SetPathName(lpszPathName);
	}

	InitialUpdateFrame(pFrame, pDocument, bMakeVisible);
	return pDocument;
}

*/

BOOL CHidemdiRootDoctmpl::SaveAllModified( )
		//【オーバライド】
		//	すべてのサブDocviewを保存してから、このDocviewを保存します
{
	BOOL	bLSaveIsContinued = TRUE ;
	if ( bLSaveIsContinued ){
		bLSaveIsContinued = super::SaveAllModified() ;
	}
	return ( bLSaveIsContinued ) ;
}
	
void CHidemdiRootDoctmpl::CloseAllDocuments( BOOL bEndSession )
{
		//【オーバライド】
		//	すべてのサブDocviewにCloseAllDocumentsを実行してから、
		//	このDocviewを閉じます
	CloseAllSubDocuviews( bEndSession ) ;
	super::CloseAllDocuments( bEndSession ) ;
}
// ********************************
//	CHidemdiRootDoctmpl
// ********************************
BOOL CHidemdiRootDoctmpl::SaveAllModifiedSubDocviews( )
{
	BOOL	bLSaveIsContinued = TRUE ;

	POSITION	LPosition = AfxGetApp()->GetFirstDocTemplatePosition() ;
	while( LPosition != NULL && bLSaveIsContinued ){
		CDocTemplate*	pLDocTemplate = AfxGetApp()
							->GetNextDocTemplate( LPosition ) ;

		if ( pLDocTemplate != this ){
			bLSaveIsContinued = pLDocTemplate->SaveAllModified() ;
				//bLSaveIsContinued = サブドキュメントの保存が
				//	キャンセルされたら偽です
		}
	}

	return ( bLSaveIsContinued ) ;
}

void CHidemdiRootDoctmpl::CloseAllSubDocuviews( BOOL bEndSession )
		//	すべてのサブDocviewを閉じます
{

	POSITION	LPosition = AfxGetApp()->GetFirstDocTemplatePosition() ;
	while( LPosition != NULL ){
		CDocTemplate*	pLDocTemplate = AfxGetApp()
						->GetNextDocTemplate( LPosition ) ;

		if ( pLDocTemplate != this ){
			pLDocTemplate->CloseAllDocuments( bEndSession ) ;
		}
	}
}

} //namespace Hidemdi
} //namespace OuMfc

