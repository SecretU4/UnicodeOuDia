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
//	CHidemdiMainfrm.h
// ****************************************************************
*/
/** @file */
#ifndef  CHidemdiMainfrm_h
#define  CHidemdiMainfrm_h

#include <afxwin.h>

namespace OuMfc{
namespace Hidemdi{

// ****************************************************************
//	CHidemdiMainfrm
// ****************************************************************
/** @brief
 * 【概要】
 *   Hidemdi アプリケーションにおける、MDIフレームウインドウクラスです。
 *
 *   Hidemdi アプリケーションのメインフレームウインドウは、このクラスの
 *	派生クラスでなくてはなりません。
 *
 *	  Hidemdi アプリケーションでは、オペレータのメニュー操作に応じて、
 *	サブViewを開くのは、メインフレームウインドウの責務です。
 *	アプリケーションは、 CHidemdiMainMDIFrameWnd を継承した
 *	『メインフレームウインドウ』クラスを作成し、これらのUI機能を
 *	実装する必要があります。
 *
 *	【使い方】
 *	Doc/ViewモデルのMFCアプリケーションにおける、
 *	一般的なメインウインドウの使い方と同じです。
 *	
 *	  CHidemdiApp派生クラス の InitInstance() のオーバライド内で、
 *	以下の順序を経て、メインフレームウインドウを作成してください。
 *
 *	１．  オブジェクトを生成します。
 *
 *	２． CFrameWnd::LoadFrame() でウインドウを作成します。
 *
 *	３． CWinApp::m_pMainWnd に、このオブジェクトのポインタをセットします。
 *
 *	このオブジェクトの後始末は、MFCのフレームワークが行います。
 *
 * @see 上記の手順の例は、CHidemdiRootDoctmpl の説明をご覧ください。
 *
 * @attention
 *	メインフレームウインドウを生成するときに
 *	CFrameWnd::LoadFrame() に渡すIDと、
 *	HidemdiRootDoctmpl() のコンストラクタの第一引数に
 *	渡すIDは、同じ値にすべきです。
 *	(このドキュメントテンプレートが利用する
 *	メニュー・アイコン・アクセラレータと、メインフレームウインドウ
 *	が利用する メニュー・アイコン・アクセラレータ は
 *	同一であるべきです）
 */
class CHidemdiMainfrm : public CMDIFrameWnd
{
// ********************************
//	従属型
// ********************************
 public:
	typedef CMDIFrameWnd	super ;

// ********************************
///@name	属性
// ********************************
///@{
 private:
	/**
	 *	真なら、『ルートドキュメント』に変更が
	 *	あったときに、タイトルバーに "*" を表示します。
	 *
	 *	初期値は false ですが、メソッドで
	 *	変更できました。
	 * @attention
	 *	この機構は、現在動作していません。
	 *	これは、 OnUpdateFrameTitle() が呼び出される
	 *	回数が少ないためです。
	 */
	bool m_bIsModifiedSign ;

///@}

// --------------------------------
//	CFrameWnd
// --------------------------------
 protected:
	/**
	 * 	フレームワークが呼び出す関数です。
	 *
	 *	この関数では、メインフレームウインドウの
	 *	タイトルバーを更新します。
	 * @param bAddToTitle [in]
	 *	- true ;	タイトルバーに、アプリケーション名と
	 *		ドキュメント名を付加します。
	 *	- false ;	タイトルバーは、アプリケーション名のみとします。
	 *
	 * 【オーバライド】
	 *	MainwndTitlebarUpdate() を呼び出して、
	 *	タイトルバーを更新します。
	 */
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle)  ;


// --------------------------------
//	CHidemdiMainfrm
// --------------------------------
 protected:
	/**
	* 	メインウインドウのタイトルバーを、最新の状態に更新します
	*
	* 【オーバライド】
	* 	 MainwndTitlebarStrGet() の結果をタイトルバーにセットします
	*/
	virtual BOOL MainwndTitlebarUpdate() ;

	/**
	* 	メインウインドウのタイトルバーにセットすべき文字列を
	* 	作成して返します。
	*
	*	この関数をオーバライドすることにより、
	*	タイトルバー文字列の作成方法を変更することができます。
	*
	* @param pRString [out]
	* 	  この関数はこの文字列オブジェクトに、タイトルバー文字列を
	* 	セットします。
	* 	  必要ないならNULLでかまいません。
	*
	* 【オーバライド】
	* 	 AfxGetAppName() の結果と、現在編集しているファイル名から
	* 	文字列を作成します。
	*
	*	(例) "document.ext - ApplicationName"
	*/
	virtual void MainwndTitlebarStrGet( CString* pRString ) ;


// ********************************
//	CHidemdiMainfrm
// ********************************
 public:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	bool getIsModifiedSign()  ;
	void setIsModifiedSign( bool value ) ;
	///@}

		
//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------
	DECLARE_DYNAMIC(CHidemdiMainfrm)
public:
	CHidemdiMainfrm();

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CHidemdiMainfrm)
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CHidemdiMainfrm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // コントロール バー用メンバ

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CHidemdiMainfrm)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


} //namespace Hidemdi
} //namespace OuMfc

#endif /*CHidemdiMainfrm_h*/
