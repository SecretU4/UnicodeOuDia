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
// CHidemdiSubDoc.cpp : インプリメンテーション ファイル
//
/** @file */

#include "CHidemdiSubDoc.h"
#include "CHidemdiRootDoctmpl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace OuMfc{
namespace Hidemdi{


/////////////////////////////////////////////////////////////////////////////
// CHidemdiSubDoc
// ********************************
//	CHidemdiSubDoc
// ********************************
CString	CHidemdiSubDoc::DocStr() 
		//	ドキュメント文字列を返します
{
	return ( m_strDocStr ) ;
}
//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------
IMPLEMENT_DYNCREATE(CHidemdiSubDoc, CDocument)

CHidemdiSubDoc::CHidemdiSubDoc()
{
}

/**
 *	ドキュメント文字列（ルートDocument内で、このサブDoc/Viewが
 *	編集する部分を特定するための文字列）
 *	を空文字列にします。
 */	
BOOL CHidemdiSubDoc::OnNewDocument()
{
	if (!super::OnNewDocument())
		return FALSE;
	
	m_strDocStr.Empty() ;
	
	return TRUE;
}

CHidemdiSubDoc::~CHidemdiSubDoc()
{
}


BEGIN_MESSAGE_MAP(CHidemdiSubDoc, CHidemdiSubDoc::super)
	//{{AFX_MSG_MAP(CHidemdiSubDoc)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHidemdiSubDoc 診断

#ifdef _DEBUG
void CHidemdiSubDoc::AssertValid() const
{
	super::AssertValid();
}

void CHidemdiSubDoc::Dump(CDumpContext& dc) const
{
	super::Dump(dc);
}
#endif //_DEBUG


	//[Attention]
	//	Serialize() メソッドは、このクラスではﾌｧｲﾙを扱わないため、
	//	当然不要です。

/////////////////////////////////////////////////////////////////////////////
// CHidemdiSubDoc コマンド

/**
 *	ドキュメントのディスク ファイルのフル パスを設定します。
 *
 *	CMultiDocTemplate::OpenDocumentFile() から呼び出されます。
 * @param lpszPathName [in]
 *	ドキュメントのパスとして使われる文字列へのポインタ。
 * @param bAddToMRU [in]
 *	ファイル名を MRU (最後に使用された) ファイル リストに追加するかどうかを決めます。
 *	TRUE を指定すると追加され、FALSE を指定すると追加されません。
 *
 * [オーバライド]
 *	ファイル名として渡された文字列を、ドキュメント文字列として
 *	保存します。
 */
void CHidemdiSubDoc::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU) 
{
	m_strDocStr = lpszPathName ;
		//[Attention]
		//	ファイル名として渡された文字列を、ドキュメント文字列として
		//	保存します

	SetTitle( lpszPathName ) ;
	//super::SetPathName(lpszPathName, FALSE);
		//[Attention]
		//	これはファイル名ではないので、ファイル名に特化した処理を行う
		//	CDocument::SetPathName() に委譲してはいけません。
		//	直接、タイトルにセットします。
}


/**
 *	ドキュメントのディスク ファイルのフル パスを設定します。
 *
 *	CMultiDocTemplate::OpenDocumentFile() から呼び出されます。
 * @param lpszPathName [in]
 *	ドキュメントのパスとして使われる文字列へのポインタ。
 *
 * [オーバライド]
 *	ファイル名として渡された文字列を、ドキュメント文字列として
 *	保存します。
 */
BOOL CHidemdiSubDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	//if (!super::OnOpenDocument(lpszPathName))
	//	return FALSE;
		//[Attention]
		//	このクラスではﾌｧｲﾙを扱わないので、Serialize() を扱う
		//	基本クラス呼出は行いません。
	
	m_strDocStr = lpszPathName ;
		//[Attention]
		//	ファイル名として渡された文字列を、ドキュメント文字列として
		//	保存します

	return TRUE;
}

BOOL CHidemdiSubDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	//return CHidemdiSubDoc::super::OnSaveDocument(lpszPathName);
		//[Attention]
		//	このクラスではﾌｧｲﾙを扱わないので、Serialize() を扱う
		//	基本クラス呼出は行いません。
	
	return ( TRUE ) ;
}

/**
 *	すべてのビューに対して、lHintを LHINT_SUBVIEW_TO_ROOTDOC 
 *	(ビューの内容をドキュメントに反映する指令)にして、
 *	OnUpdate()を呼び出します。コントロール（子ウインドウ）
 *	を持つビューでは、このときにコントロールの入力内容
 *	を読みとって、それをルートドキュメントに反映します
 */
BOOL CHidemdiSubDoc::SaveModified() 
{
	UpdateAllViews( NULL , LHINT_SUBVIEW_TO_ROOTDOC , NULL ) ;
	
	return super::SaveModified();
}

void CHidemdiSubDoc::OnFileSave() 
{
	AfxGetApp()->OnCmdMsg( ID_FILE_SAVE , 0 , NULL , NULL ) ;
		//[Attention]
		//	アプリケーションクラスに委譲します
}

void CHidemdiSubDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	pCmdUI->DoUpdate( AfxGetApp() , FALSE ) ;
		//[Attention]
		//	アプリケーションクラスに委譲します
}

void CHidemdiSubDoc::OnFileSaveAs() 
{
	AfxGetApp()->OnCmdMsg( ID_FILE_SAVE_AS , 0 , NULL , NULL ) ;
		//[Attention]
		//	アプリケーションクラスに委譲します
	
}

void CHidemdiSubDoc::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	pCmdUI->DoUpdate( AfxGetApp() , FALSE ) ;
		//[Attention]
		//	アプリケーションクラスに委譲します
}


} //namespace Hidemdi
} //namespace OuMfc

