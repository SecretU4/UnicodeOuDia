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
//	CHidemdiRootDoc.cpp
// ****************************************************************
*/

#include "CHidemdiRootDoc.h"
#include "CHidemdiApp.h"

namespace OuMfc{
namespace Hidemdi{


// ****************************************************************
//	CHidemdiRootDoc
// ****************************************************************
// ********************************
//	CHidemdiRootDoc
// ********************************
void CHidemdiRootDoc::UpdateAllSubDocviews( CView* pSender	
								, LPARAM lHint , CObject* pHint )
		//	すべてのサブDocviewに対して、UpdateAllViews()を実行します
		//pSender
		//	ドキュメントを変更したビューへのポインタ。
		//すべてのビューを更新するときには NULL を指定します。
		//lHint
		//	変更に関する情報を指定します。
		//	ただし、 LHINT_SUBVIEW_TO_ROOTDOC が指定された場合は、
		//	すべてのDocviewに対して、
		//	内容をルートドキュメントに反映し、必要ならばルートDocに対して
		//	SetModifiedFlag()を実行させます。
		//pHint
		//	変更に関する情報が格納されているオブジェクトへのポインタ。
{
	POSITION	LPosition = AfxGetApp()->GetFirstDocTemplatePosition() ;

	//	すべてのサブDocViewへの、UpdateAllViews() 呼び出し
	while( LPosition != NULL ){
		CDocTemplate*	pLDocTemplate = AfxGetApp()
						->GetNextDocTemplate( LPosition ) ;
		if ( pLDocTemplate != GetDocTemplate() ){
			POSITION	LPosition = pLDocTemplate->GetFirstDocPosition() ;
			while( LPosition != NULL ){
				CDocument*	pLDocument = 
					pLDocTemplate->GetNextDoc( LPosition ) ;
				pLDocument->UpdateAllViews( pSender	, lHint , pHint ) ;
			}
		}
	}
}

//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------
IMPLEMENT_DYNCREATE(CHidemdiRootDoc, CDocument)

BEGIN_MESSAGE_MAP(CHidemdiRootDoc, CHidemdiRootDoc::super)
	//{{AFX_MSG_MAP(CHidemdiRootDoc)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CHidemdiRootDoc::CHidemdiRootDoc()
{

}

CHidemdiRootDoc::~CHidemdiRootDoc()
{
}

#ifdef _DEBUG
void CHidemdiRootDoc::AssertValid() const
{
	super::AssertValid();
}

void CHidemdiRootDoc::Dump(CDumpContext& dc) const
{
	super::Dump(dc);
}
#endif //_DEBUG

BOOL CHidemdiRootDoc::SaveModified() 
	//	SaveAllModifiedSubDocviews（）
	//	（すべてのサブDocviewに対してSaveModofiedを実行する）
	//	を実行してから、自分自身のSaveModifiedを実行します)
{
	BOOL	bRv = TRUE ;
	bRv = ((CHidemdiApp*)AfxGetApp())->pRootDoctmpl()
									->SaveAllModifiedSubDocviews() ;
	if ( bRv ){
		bRv = super::SaveModified();
	}
	return ( bRv ) ;
}




void CHidemdiRootDoc::SetTitle(LPCTSTR lpszTitle) 
{
	//[Attention]
	//	ドキュメントを名前をつけて保存した場合などは、
	//	ここで OnUpdateFrameTitle() を呼び出さないと、
	//	メインフレームウインドウのタイトルバーが変わりません。
	super::SetTitle(lpszTitle);
	( (CFrameWnd*)AfxGetMainWnd() )->OnUpdateFrameTitle( TRUE ) ;
}

void CHidemdiRootDoc::OnFileSave() 
{
	BOOL	bRv = TRUE ;

	//[Attention]
	//	このコマンドメッセージの場合は、自動的には
	//	SaveModified()が呼ばれませんので、明示的に
	//	SaveAllModifiedSubDocviews（）
	//	（すべてのサブDocviewに対してSaveModofiedを実行する）
	//	を実行してから、自分自身の処理を実行します
	bRv = ((CHidemdiApp*)AfxGetApp())->pRootDoctmpl()
								->SaveAllModifiedSubDocviews() ;

	if ( bRv ){
		super::OnFileSave() ;
	}

}

void CHidemdiRootDoc::OnFileSaveAs() 
{
	BOOL	bRv = TRUE ;

	//[Attention]
	//	このコマンドメッセージの場合は、自動的には
	//	SaveModified()が呼ばれませんので、明示的に
	//	SaveAllModifiedSubDocviews（）
	//	（すべてのサブDocviewに対してSaveModofiedを実行する）
	//	を実行してから、自分自身の処理を実行します
	bRv = ((CHidemdiApp*)AfxGetApp())->pRootDoctmpl()
								->SaveAllModifiedSubDocviews() ;

	if ( bRv ){
		super::OnFileSaveAs() ;
	}
}


void CHidemdiRootDoc::OnFileClose() 
{
	//attention
	// RootDoc に対する ID_FILE_CLOSE は、
	//	処理してはいけません
	//	（ルートドキュメントが０個になってしまいます。
	//	Hidemdi アプリケーションは、常に１個の
	//	ルートドキュメントオブジェクトを持たなくてはなりません)
	//	
	//	RootDoc のメニューからは
	//	 FILE_CLOSE を削除しなくてはなりません。
	ASSERT( 0 ) ;
	//CHidemdiRootDoc::super::OnFileClose();
}


void CHidemdiRootDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( ((CHidemdiApp*)AfxGetApp())->pRootDoc()->IsModified() ) ;
}

void CHidemdiRootDoc::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( ((CHidemdiApp*)AfxGetApp())->pRootDoc()->IsModified() ) ;
}

} //namespace Hidemdi
} //namespace OuMfc

