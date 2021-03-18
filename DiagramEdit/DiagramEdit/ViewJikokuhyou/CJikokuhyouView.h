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
#if !defined(AFX_CJIKOKUHYOUVIEW_H__53F013EC_64B4_4505_8EAC_330E227A8B69__INCLUDED_)
#define AFX_CJIKOKUHYOUVIEW_H__53F013EC_64B4_4505_8EAC_330E227A8B69__INCLUDED_
/** @file */
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CJikokuhyouView.h : ヘッダー ファイル
//

#include "ViewJikokuhyou\WndJikokuhyou\CWndJikokuhyou.h"

namespace ViewJikokuhyou{
	using namespace WndJikokuhyou;
/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouView ビュー
/**
 * @brief
 *	時刻表ビューの、View クラスです。
 */
class CJikokuhyouView : public CView
{
// ********************************
///@name 包含
// ********************************
///@{
 private:
	/**
	 *	『時刻表ビュー』のグリッドです。
	 *	OnCreate() で生成・OnDestroy() で破棄します。
	 */
	CWndJikokuhyou* m_pCWndDcdGrid ;
///@}
// --------------------------------
///@name 下請関数
// --------------------------------
///@{
 protected:
	
///@}
// --------------------------------
///@name OnUpdate下請関数
// --------------------------------
///@{
 private:


///@}
// ********************************
///@name 操作
// ********************************
///@{
 public:
	/**
	 *	指定のインデクスの列車の、指定の駅Orderに、フォーカスを移動します。
	 *	フォーカスは、指定の駅Orderの発時刻に移動します。
	 *	発時刻の欄がない場合には、着時刻に移動します（発時刻が優先です）。
	 * @param iRessyaIdx [in]
	 *	列車インデクスを指定して下さい。
	 * @param iEkiOrder [in]
	 *	フォーカスをセットする駅Order を指定してください。
	 *	駅Orderが(0以上駅数未満)の範囲にない場合は、
	 *	フォーカスセルのY座標は移動しません。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	パラメータが不正です。 
	 */
	virtual int setFocusToRessyaIndex( int iRessuaIdx , int iEkiOrder ) ;
///@}

// ----------------------------------------------------------------
protected:
	CJikokuhyouView();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CJikokuhyouView)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CJikokuhyouView)
	public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CJikokuhyouView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CJikokuhyouView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace ViewJikokuhyou

#endif // !defined(AFX_CJIKOKUHYOUVIEW_H__53F013EC_64B4_4505_8EAC_330E227A8B69__INCLUDED_)
