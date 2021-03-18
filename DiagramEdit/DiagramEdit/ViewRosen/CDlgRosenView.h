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
#if !defined(AFX_CDLGROSENVIEW_H__DDF0CE6B_85EB_403A_9D22_02ACAED5776C__INCLUDED_)
#define AFX_CDLGROSENVIEW_H__DDF0CE6B_85EB_403A_9D22_02ACAED5776C__INCLUDED_
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// CDlgRosenView.h : ヘッダー ファイル
//
#include "resource.h"
#include "..\entDed\CentDedRosen.h"
#include "CRosenViewTreeCtrl.h"

namespace ViewRosen{
using namespace entDed;
/////////////////////////////////////////////////////////////////////////////
// CDlgRosenView ダイアログ

/**
  @brief
 	左側ペインの『路線ビュー』を実装しています。
 
 	この『路線ビュー』は、モードレスダイアログとして実現しています。
 	CMainFrame に包含されます。
 	
 	『路線ビュー』を更新するのは、ルートDoc/View の CDiagramEditView の
 	責務です。『路線ビュー』の更新の必要を判断するのも、 CDiagramEditView の
 	責務です。
 */
class CDlgRosenView : public CDialog
{
private:
	// ********************************
	///@name	包含
	// ********************************
	///@{
	/**
	 	イメージリスト。
	 	OnCreate() で生成します。
	 */	
	CImageList	m_imagelistROSEN ;
	///@}

public:
	// --------------------------------
	///@name	下請関数
	// --------------------------------
	///@{
	/**
	 	OnOK(),OnClickTreeRosen(),OnDblclkTreeRosen() の下請関数です。
	 	リストビューのアイテム aItem がクリックされたときの
	 	動作・ダブルクリックされたときの動作・
	 	アイテム aItem が選択された状態で Enter キーが押された
	 	ときの動作を実行します。
	 	
	 	<H5>
	 	『路線』アイテムをクリックした場合
	 	</H5>
	 	『路線ファイルのプロパティ』
	 	ダイアログを起動します。
	 
	 	<H5>
	 	『駅』アイテムをクリックした場合
	 	</H5>
	 	『駅』ビューを開きます。
	 	
	 	<H5>
	 	『列車種別』アイテムをクリックした場合
	 	</H5>
	 	『列車種別』ビューを開きます。
	 	
	 	<H5>
	 	『ダイヤ』アイテムをクリックした場合
	 	</H5>
	 	『ダイヤ一覧』ダイアログを開きます。
	 	
	 	<H5>
	 	『時刻表＜下り＞』アイテムをクリックした場合
	 	</H5>
	 	『時刻表＜下り＞』ビューを開きます。
	 	
	 	<H5>
	 	『時刻表＜上り＞』アイテムをクリックした場合
	 	</H5>
	 	『時刻表＜上り＞』ビューを開きます。
	 	
	 	<H5>
	 	『ダイヤグラム』アイテムをクリックした場合
	 	</H5>
	 	『ダイヤグラム』ビューを開きます。
	 	
	  @param aItem [in]
	 	リストビューアイテムを指定してください。
	  @param iAction [in]
	 	アイテムに対する操作を指定してください。
	 	-	0 ;	//	Enter キーの操作
	 	-	1 ;	//	クリック操作
	 			//	（モーダルダイアログを出すような動作は行いません）
	 	-	2 ;	//	ダブルクリック操作
	 			//	（モーダルダイアログを出すような動作のみを行います）
	  @return 
	 	-	1 ;	//	指定のアイテムに対応する処理を行いました。
	 	-	0 ;	//	何も処理はありませんでした。
	 */
	virtual int onEnterItem( HTREEITEM aItem , int iAction ) ;
	///@}
public:
	// ********************************
	///@name	CWnd
	// ********************************
	///@{
	/**
		ダイアログ(上のコントロール)にフォーカスがある状態で 
        アクセラレータによるメニューコマンドへのアクセスを 
        行うためには、メインフレームウインドウに PreTranslateMessage() を 
        委譲しなくてはなりません。 
	*/
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	///@}

public:
	// ********************************
	//	CDlgRosenView
	// ********************************
	// ********************************
	///@name CDlgRosenView-操作
	// ********************************
	///@{
	/**
	  @param pCentDedRosen [in]
	   CentDedRosen が保持している路線の情報を、
	 	ツリーコントロール m_treeROSEN に反映します。
	 */
	void UpdateROSEN( const CentDedRosen* pCentDedRosen ) ;

	/**
	 	ルートDocのUpdateAllSubDocviews()から呼び出されます。
	  @param pSender [in]
	  @param lHint [in]
	  @param pHint [in]
	 */
	virtual void OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint ) ;
	
	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// コンストラクション
public:
	CDlgRosenView(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CDlgRosenView)
	enum { IDD = IDD_ROSEN_VIEW };
	CRosenViewTreeCtrl 	m_treeROSEN;
	//}}AFX_DATA

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CDlgRosenView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CDlgRosenView)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnClickTreeRosen(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkTreeRosen(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuitemOpen();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace ViewRosen

#endif // !defined(AFX_CDLGROSENVIEW_H__DDF0CE6B_85EB_403A_9D22_02ACAED5776C__INCLUDED_)
