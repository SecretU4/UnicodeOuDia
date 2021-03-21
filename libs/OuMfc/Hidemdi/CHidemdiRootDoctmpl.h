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
//	CHidemdiRootDoctmpl.h
// ****************************************************************
*/
/** @file */
#ifndef  crootdoctemplate_h
#define  crootdoctemplate_h

#include <afxwin.h>

namespace OuMfc{
namespace Hidemdi{


// ****************************************************************
//	CHidemdiRootDoctmpl
// ****************************************************************
/** @brief
【概要】
  Hidemdi アプリケーションにおける、ルートDoc/Viewのテンプレートです。
  ルートDoctemplateは、アプリケーションに１つだけ存在します。
  ルートDoctemplate は、以下のオブジェクトを生成・管理する役目を持ちます。

 - ルートDocument(CHidemdiRootDocの派生クラス) 
 
【使い方】

  Doc/ViewモデルのMFCアプリケーションにおける、
  一般的なDocTemplateの使い方と同じです。但し、
	
<H4>
（CHidemdiApp::InitInstance() オーバライドの例（一部））
</H4>

@code

	{
		CHidemdiRootDoctmpl* pDocTemplate;
		pDocTemplate = new CHidemdiRootDoctmpl(		
			IDR_HIDEMDTYPE,	
			RUNTIME_CLASS(CHidemditestDoc));
		AddDocTemplate(pDocTemplate);
		RegisterRootDoctmpl( pDocTemplate ) ;
	}

		：
		（中略）
		：

	// メイン MDI フレーム ウィンドウを作成
	CMainFrame* pMainFrame = new CMainFrame;

	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

@endcode

*/
class CHidemdiRootDoctmpl : public CMultiDocTemplate
{
// ********************************
//	従属型
// ********************************
 public:
	typedef CMultiDocTemplate	super ;

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 *	引数は、CMultiDocTemplate と同じです。
	 *
	 * @param nIDResource [in]
	 *	 ドキュメント型で使うリソースの ID を指定します。
	 *	メニュー、アイコン、アクセラレータ テーブル、文字列リソースを
	 *	指定できます。
	 * @param pDocClass [in]
	 *	  ルート Document の RUNTIME_CLASS を指定してください。
	 */
	CHidemdiRootDoctmpl( UINT nIDResource
				, CRuntimeClass* pDocClass ) ;
	virtual ~CHidemdiRootDoctmpl() ;

// ********************************
//	CDocTemplate
// ********************************
 public:
	/**
	* 【オーバライド】
	* 	既存のドキュメントをすべて閉じてから、
	* 	新しいドキュメントを生成します。
	*/
	virtual CDocument* OpenDocumentFile( LPCTSTR lpszPathName
								, BOOL bMakeVisible = TRUE ) ;
	
	/**
	* 【オーバライド】
	* 	すべてのサブDocviewを保存してから、このDocviewを保存します
	*/
	virtual BOOL SaveAllModified( );
	
	/**
	* 【オーバライド】
	* 	すべてのサブDocviewにCloseAllDocumentsを実行してから、
	* 	このDocviewを閉じます
	*/
	virtual void CloseAllDocuments( BOOL bEndSession );
// ********************************
//	CHidemdiRootDoctmpl
// ********************************
 public:
	/**
	* 	すべてのサブDocviewを保存します
	* @return
	* 	すべてのサブDocviewを閉じる動作が正常終了したら真、
	* 	処理が途中でキャンセルされたら偽を返します。
	*/
	virtual BOOL SaveAllModifiedSubDocviews( );
	
	/**
	* 	すべてのサブDocviewを閉じます
	*/
	virtual void CloseAllSubDocuviews( BOOL bEndSession );

};

/**
 *	CView::OnUpdate()の lHint 引数に指定することのできる値です。
 *
 *	サブViewに対して、「編集中のデータをルートDocumentに反映する」
 *	ことを指示します。
 *
 *  以下の関数の lHint に、この値を指定することができます。
 *
 *	- void CHidemdiRootDoc::UpdateAllSubDocviews( 
 *		CView* pSender , LPARAM lHint = 0L , CObject* pHint = NULL );
 *	- void CHidemdiRootDoctmpl::UpdateAllSubDocviews( CView* pSender
 *		, LPARAM lHint = 0L, CObject* pHint = NULL );
 *	- void CHidemdiSubDoc::UpdateAllViews(CView* pSender, 
 *		LPARAM lHint = 0L, CObject* pHint = NULL );
 *
 *  上記関数で指定したこの値は、最終的に
 *	サブViewの lHint に指定されます。
 *
 *	- void CView::OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint );
 */
const LPARAM LHINT_SUBVIEW_TO_ROOTDOC = -1 ;

} //namespace Hidemdi
} //namespace OuMfc

#endif /*crootdoctemplate_h*/

