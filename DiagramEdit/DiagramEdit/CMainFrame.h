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
// CMainFrame.h : CMainFrame クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMAINFRAME_H__30AFE159_0874_4392_957E_EC27183039B9__INCLUDED_)
#define AFX_CMAINFRAME_H__30AFE159_0874_4392_957E_EC27183039B9__INCLUDED_
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Hidemdi\CHidemdiMainfrm.h"
#include "FrameLeftPane\CWndSplitBarV.h"

#include "ViewRosen\CDlgRosenView.h"
#include "CDedStatusBar.h"

using namespace OuMfc::Hidemdi;
using namespace ViewRosen;
using namespace OuMfc::FrameLeftPane;
/**
 *	@brief
 *	アプリケーションのメインフレームウインドウクラスです。
 */
class CMainFrame : public CHidemdiMainfrm
{
 private:
	// ********************************
	//	包含
	// ********************************
	/**
	 	路線ビュー（左側ペイン）
	 	OnCreate() で生成します。
	 */
	CDlgRosenView	m_CDlgRosenView ;	
	/**
	 	スプリットバー
	 	OnCreate() で生成します。
	 */
	CWndSplitBarV	m_CWndSplitBarV ;	
 protected:
	// --------------------------------
	//	CFrameWnd
	// --------------------------------
	/**
	  【オーバライド】
	 	CWndSplitBarV::RecalcLayout() によって
	 	コントロールバーを配置してから、
	 	MDIClientWindow と
	 	路線ビュー（左側ペイン）を配置します。
	 */
	virtual void RecalcLayout( BOOL bNotify = TRUE );

	/**
	 	アプリケーションのメイン フレーム ウィンドウが
	 	印刷プレビュー モードに入るときと、抜けるときに呼び出します。
	 
	  @param bPreview [in]
	 	アプリケーションが印刷プレビュー モードで
	 	あるかないかを指定します。
	 	印刷プレビューモードであれば TRUE を、プレビュー モードを
	 	キャンセルし元に戻すには FALSE を設定します。
	  @param pModeStuff [in]
	 	CPrintPreviewState 構造体へのポインタ。
	 
	  【オーバライド】
	 	プレビューモード実行中は、 m_CDlgRosenView を無効にします。
	 */
	virtual void OnSetPreviewMode( BOOL bPreview, CPrintPreviewState* pModeStuff );
protected:
	// --------------------------------
	///@name メニューコマンドの下請関数
	// --------------------------------
	///@{
	/**	
		[ファイル]-[路線ファイルの組入れ]
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します。
	@return
		-	0 :	成功
		-	-21 ;	//	駅が2つ未満なら、このコマンドは使用できません。
		-	-1 :	//	キャンセル
		-	-11 :	//	ファイルがみつかりません。
		-	-12 :	//	ファイルの形式が不正です。
	@memo
		この関数は CDiagramEditDoc のメンバにする、という考え方もあります。
		しかし、この関数の処理はUI(ダイアログボックス)を持っているため、
		ここでは  CDiagramEditDoc のメンバにするのを避けました。
	*/
	int OnFileRosenFileInsert_Process( BOOL bQueryEnable ) ;

	/**	
		[ファイル]-[路線ファイルの切り出し]
	@memo
		この関数は CDiagramEditDoc のメンバにする、という考え方もあります。
		しかし、この関数の処理はUI(ダイアログボックス)を持っているため、
		ここでは  CDiagramEditDoc のメンバにするのを避けました。
	*/
	int OnFileRosenCreateSubRosen_Process( BOOL bQueryEnable ) ;
	///@}

// ********************************
//	CMainFrame
// ********************************
 public:
	// ********************************
	///@name	CMainFrame-包含
	// ********************************
	///@{
	CDlgRosenView*	getCDlgRosenView()
	{	return &m_CDlgRosenView ; } ;
	///@}
	// ********************************
	///@name	CMainFrame-操作
	// ********************************
	///@{
	/**
	 	『路線ファイルのプロパティ』ダイアログを開きます。
	 
	 	ダイアログが『OK』で閉じられたら、路線ファイルの
	 	プロパティを『ルートドキュメント』 CDiagramEditDoc 
	 	に反映します。
	  @return
	 	0 以上は成功、エラーなら負の数です。 
	 	-	1 ;	//	『OK』が押されて、入力内容が
	 		『ルートドキュメント』に反映しました。
	 	-	0 ;	//	『Cancel』が押されました。
	 	
	 */
	int execCDlgRosenFileProp() ;
	/**
	 	『ダイヤの一覧』ダイアログを開きます。
	 
	 	※『ダイヤの一覧』ダイアログは、ルートドキュメントを
	 	変更する能力を持っています。
	  @return
	 	0 以上は成功、エラーなら負の数です。 
	 	現在のところ、 0 しか返しません。	
	 */
	int execCDlgDiaList() ;

	/**
	  @return
	 	現在アクティブなMDI子ウインドウが
	 	アクティブなビューを保持していれば、
	 	そのビューオブジェクトへのポインタを返します。
	 	アクティブなビューがないならNULLです。
	 */
	CView* getMDIChildActiveView() ;
	///@}
// ----------------------------------------------------------------

	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // コントロール バー用メンバ
	CDedStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CToolBar    m_wndToolBarDiagram;

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFileRosenfileInsert();
	afx_msg void OnUpdateFileRosenfileInsert(CCmdUI *pCmdUI);
	afx_msg void OnFileRosenCreateSubRosen();
	afx_msg void OnUpdateFileRosenCreateSubRosen(CCmdUI *pCmdUI);
	afx_msg void OnRosenFileProp();
	afx_msg void OnRosenDialist();
	afx_msg void OnWindowRosenView();
	afx_msg void OnUpdateINDICATOR_PasteZoubun(CCmdUI *pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CMAINFRAME_H__30AFE159_0874_4392_957E_EC27183039B9__INCLUDED_)
