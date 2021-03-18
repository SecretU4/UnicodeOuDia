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
//	CHidemdiApp.h
// ****************************************************************
*/
/** @file */
#ifndef  CHidemidApp_h
#define  CHidemidApp_h

#include <afxwin.h>

#include "CHidemdiRootDoctmpl.h"
#include "CHidemdiRootDoc.h" 

namespace OuMfc{
namespace Hidemdi{

// ****************************************************************
//	CHidemdiApp
// ****************************************************************
/** @brief
【概要】
 Hidemdi アプリケーションにおける、アプリケーションクラスの基本クラスです。

 ルートDoc/Viewのテンプレートをメンバとして保持します。
 Hidemdi アプリケーションでは、このクラスを継承し、派生クラスの
InitInstance() で ルートDoc/View・サブDoc/Viewのテンプレートを生成しなくては
なりません。ルートDoc/Viewのテンプレートは、RegisterRootDoctmplで、thisに
登録しなくてはなりません。
  このクラスは、ルートDoc/Viewのテンプレート・ドキュメントを取得する
サービスを提供しています。

  コマンドメッセージは、RootDocに委譲されます。
*/
class CHidemdiApp : public CWinApp
{
// ********************************
//	従属型
// ********************************
 public:
	typedef CWinApp	super ;

//--------------------------------
//	データメンバ
//--------------------------------
 private:
	/**
		初期値はNULLです。
		InitInstance() で、RegisterRootDoctmpl()
		を使って、ルートDoc/Viewのテンプレートへの
		ポインタを登録します。
	*/
	CHidemdiRootDoctmpl*	m_pdoctemplateRoot ;

//--------------------------------
//	下請関数
//--------------------------------
 protected:
	/**
		InitInstance() でDoctemplateを生成したときに、
		ルートDoctemplateオブジェクトのポインタを、このメソッドで
		登録してください。
	*/
	virtual BOOL RegisterRootDoctmpl
								( CHidemdiRootDoctmpl* prootdoctemplateEv ) ;

// ********************************
//	CHidemdiTestApp
// ********************************
 public:
	/**
	@return
		ルートDoc/Viewのテンプレートへの
		ポインタを返します
	*/
	virtual CHidemdiRootDoctmpl*	pRootDoctmpl() ;

	/**
	@return
		ルートDocへのポインタを返します
	*/
	virtual CHidemdiRootDoc*			pRootDoc() ;

	/**
		ファイル名を、MRUリストから削除します
	@param lpszEFilename [in]
		削除するファイル名を返します
	@return
		削除したエントリの数を返します
	*/
	virtual int RemoveFromRecentFileList( LPCTSTR lpszEFilename ) ;

//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------
public:
	CHidemdiApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CHidemdiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL
	
// インプリメンテーション
	//{{AFX_MSG(CHidemdiApp)
	afx_msg void OnFileNew();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSaveAs(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
};

} //namespace Hidemdi
} //namespace OuMfc

#endif /*CHidemdiApp_h*/


