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
#if !defined(AFX_CDEDCOMMENTVIEW_H__FBDDE445_4FAC_4AA4_A9CB_3B4100283066__INCLUDED_)
#define AFX_CDEDCOMMENTVIEW_H__FBDDE445_4FAC_4AA4_A9CB_3B4100283066__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDedCommentView.h : ヘッダー ファイル
//
#include "NsOu/Ou.h"
//#include "CDedRosenFileData_CEditCmd_Comment.h"
#include "DedRosenFileData\EditCmd\EditCmd.h"

namespace ViewComment{
	using namespace DcDrawLib::DcdCd::DcDrawProp;
	using namespace OuLib::NsOu;
	using namespace DedRosenFileData::EditCmd;
/////////////////////////////////////////////////////////////////////////////
// CDedCommentView ビュー

class CDedCommentView : public CEditView
{
// ********************************
//	インナータイプ
// ********************************
public:
	typedef CEditView	super ;
// --------------------------------
///@name 内部データ
// --------------------------------
///@{
private:
	/**
	 *	このビューで使用しているフォント。
	 *	OnUpdate() で作成します。
	 */
	CdFontProp	m_CdFontProp ;
	CFont	m_CFont ;

	/**
	 *	通常は false 。
	 *	ビューがアクティブでないときに、
	 *	OnUpdate() によって、他のビューから
	 *	時間のかかる更新が要求されたときから、
	 *	ビューの全更新を実行するまでの間だけ true になります。
	 *	
	 *	この変数が true のときは、
	 *	ビューの更新を、次にビューがアクティブ化されるまで
	 *	保留していることを示します。
	 *	
	 *	OnUpdate() によって、他のビューから
	 *	時間のかかる更新が要求された場合、
	 *	この変数を true にし、
	 *	OnUpdate_All() は実行しません。
	 *
	 *	この値が true のときに、ビューがアクティブ化されたら、
	 *	OnUpdate() を実行します。
	 */
	bool m_bUpdate_All_Requested ;

	/**
	 *	通常は false 。
	 *	ビューを変更してから、そのビューの内容を
	 *	OnUpdate() によって、ルートDocument()に書き込むまでの間だけ
	 *	true です。
	 */
	bool m_bIsChanged ;

///@}
// --------------------------------
///@name 下請け関数
// --------------------------------
///@{
private:
	/**
	 *	OnUpdate() の下請け関数です。
	 *
	 *	ドキュメントの内容をビューに反映します。
	 */
	void OnUpdate_All() ; 
	/**
	 *	OnUpdate() の下請け関数です。
	 *
	 *	pHint が CRfEditCmd_Comment 時の
	 *	処理を行います。
	 */
	void OnUpdate_Comment( Ou<CRfEditCmd_Comment> pCommand );

	/**
	 *	このオブジェクトにおける、標準のテキスト描画方法を返します。
	 */
	CdDrawTextProp	getCdDrawTextPropStandard() ;
///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
protected:
	CDedCommentView();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CDedCommentView)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CDedCommentView)
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CDedCommentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CDedCommentView)
	afx_msg void OnChange();
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace ViewComment

#endif // !defined(AFX_CDEDCOMMENTVIEW_H__FBDDE445_4FAC_4AA4_A9CB_3B4100283066__INCLUDED_)
