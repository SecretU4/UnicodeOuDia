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
#if !defined(AFX_CWNDSPLITBARV_H__4D5499AB_1C6F_4AA9_9F02_12CC9B690B84__INCLUDED_)
#define AFX_CWNDSPLITBARV_H__4D5499AB_1C6F_4AA9_9F02_12CC9B690B84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>

// CWndSplitBarV.h : ヘッダー ファイル
//

namespace OuMfc{
namespace FrameLeftPane{

/////////////////////////////////////////////////////////////////////////////
// CWndSplitBarV ウィンドウ
/**
@brief
 MDIClient ウインドウの左側ペインとの間にある
スプリットバーのウインドウです。

【MDIFrameLeftPane アプリケーションの概要】
	
  MDIFrameLeftPane アプリケーションは、左側に「左側ペイン」子ウインドウ
（ツリービューなど）・右側に MDIClient ウインドウを持ち、
MDIClient ウインドウ内には MDI子ウインドウを開くことのできる
アプリケーションです。
  左側ペインとMDIClientウインドウの間には、「スプリットバー」が
あります。「スプリットバー」をドラッグすることにより、「左側ペイン」と
 MDIClient の境界（大きさ）を調節することができます。
	
  このアプリケーションのメインウインドウは、 CMDIFrameWnd の派生クラス
として実装します。「左側ペイン」・「スプリットバー」は、
メインウインドウの子ウインドウとします。
 「左側ペイン」は、 CWnd の派生クラスとして実装します。
 「スプリットバー」は、 CWndSplitBar クラスのオブジェクトを生成します。
	

【使い方】

１．  あらかじめ、「左側ペイン」のウインドウの動作を、
 CWnd の派生クラスとして実装してください。
	
２．  メインフレームウインドウのクラスは、 CMDIFrameWnd の
派生クラスとしてください。
  このクラスには、「左側ペイン」のクラスのインスタンス(CWnd派生クラス)
と、「スプリットバー」クラスのインスタンス（CWndSpkitterV）を
メンバ変数として保持してください。  @n
  メインフレームウインドウの OnCreate() では、 「左側ペイン」・
「スプリットバー」に対して Create() を呼び出して、子ウインドウの
 HWND を生成してください。
	
３．  メインフレームウインドウのクラス（ CMDIFrameWnd 派生クラス ) では、
必ず RecalcLayout() をオーバライドして、このクラスの
 CMDIFrameWnd_RecalcLayout() に処理を委譲してください。
 */
class CWndSplitBarV : public CWnd
{
 private:
	// ********************************
	///@name	関連
	// ********************************
	///@{
	/**
		左側ペインのウインドウへのポインタです。
		このオブジェクトの破棄の責務は、クラスユーザにあります。
		このオブジェクトは、 this より長く
		生存しなくてはなりません。
	*/
	CWnd*	m_pwndLeftPane ;
	///@}
 private:
	// --------------------------------
	///@name	内部データ
	// --------------------------------
	///@{
	/**
		通常は -1 。
		このウインドウをドラッグしている最中だけは、
		ドラッグを開始したときのマウスの座標を、
		このウインドウ上の座標で保持します（0以上）。
	 */
	int	m_iDragPosX ;
	///@}
 public:
	// ********************************
	//	構築
	// ********************************
	///@{
	/**
		ウインドウを生成します。
	@param pParentWnd [in]
		親ウインドウを指定してください。
	@param pwndLeftPane [in]
		左側ペインのウインドウへのポインタです。
		このオブジェクトの破棄の責務は、クラスユーザにあります。
		このオブジェクトは、 this より長く
		生存しなくてはなりません。
	@param nID [in]
		このウインドウ（スプリットバー）の
		子ウインドウID を指定してください。
	@return
		正常終了した場合は 0 以外を返します。それ以外の場合は 0 を返します。
	 */
	BOOL Create( CWnd* pParentWnd, 	
		CWnd* pwndLeftPane ,
		UINT nID);
	
	///@}
 public:
	// ********************************
	///@name	操作
	// ********************************
	///@{
	/**
		 CMDIFrameWnd のなかに 左側ペインと、
		スプリットバー(CWndSplitBarV)を配置するアプリケーションは、
		メインウインドウオブジェクトのクラス（CMDIFrameWnd 派生クラス）
		で CFrameWnd::RecalcLayout() をオーバライドし、
		この関数に処理を委譲してください。
		このとき、基本クラスの実装（CFrameWnd::RecalcLayout()）の
		呼び出しは行わないでください。
	
		この関数は、左側ペイン・スプリットバー・MDIClient ウインドウを
		適切に再配置します。
	
	@param pCMDIFrameWnd [in]
		メインウインドウの CMDIFrameWnd オブジェクトを
		指定してください。
		通常は、 this を指定することになります。
	@param pwndLeftPane [in]
		左側ペインのオブジェクトを指定してください。
	@param pCWndSplitBarV [in]
		スプリットバー のオブジェクトを指定してください。
	@param bNotify [in]
		 CFrameWnd 派生クラスの RecalcLayout( BOOL bNotify ) で
		渡された bNotify を、そのまま渡してください。
	 */
	static void CMDIFrameWnd_RecalcLayout(
			CMDIFrameWnd* pCMDIFrameWnd ,
			CWnd* pwndLeftPane ,
			CWndSplitBarV* pCWndSplitBarV ,
			BOOL bNotify ) ;
	
	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// コンストラクション
public:
	CWndSplitBarV();

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CWndSplitBarV)
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CWndSplitBarV();

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CWndSplitBarV)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace FrameLeftPane
} //namespace OuMfc

#endif // !defined(AFX_CWNDSPLITBARV_H__4D5499AB_1C6F_4AA9_9F02_12CC9B690B84__INCLUDED_)
