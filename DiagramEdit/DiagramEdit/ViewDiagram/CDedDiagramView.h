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
#if !defined(AFX_CDEDDIAGRAMVIEW_H__51A5E4F0_D26B_4032_A34F_3BC45B6B3F1F__INCLUDED_)
#define AFX_CDEDDIAGRAMVIEW_H__51A5E4F0_D26B_4032_A34F_3BC45B6B3F1F__INCLUDED_
// cdeddiagramview.h : ヘッダー ファイル
//	$Id: CDedDiagramView.h 295 2016-06-11 05:14:13Z okm $
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NsOu/Ou.h"

#include "DiagramEdit.h"
#include "..\entDgr\CentDedDgrDia.h"
#include "CWndDiagram.h"
#include "DedRosenFileData\EditCmd\CRfEditCmd_Ressya.h"

namespace ViewDiagram{
	using namespace DedRosenFileData::EditCmd;
	using namespace entDed;

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView ビュー
/**
	@brief
	ダイヤグラムのビューです。
 */
class CDedDiagramView : public CView
{
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
		『ダイヤグラムエンティティクラス群』の
		『ダイヤグラムダイヤ』オブジェクト。
	
		このオブジェクトの破棄の責務は this にあります。
		OnInitialUpdate()で生成し、デストラクタで破棄します。
	 */
	CentDedDgrDia* m_pCentDedDgrDia ;

	/**
		ダイヤグラムを描画する子ウインドウ。
		OnCreate() で生成し、 OnDestroy() で破棄します。
		このオブジェクトの破棄の責務は this にあります。
		
	*/
	CWndDiagram* m_pCWndDiagram ;
	///@}

private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
		全更新が保留されていたら true 。

		通常は false 。
		このビューがアクティブでないときに 
		全更新（ OnUpdate_All() を呼び出す）が必要になってから、
		ビューがアクティブになるまでの間だけ true になります。
		
		この変数が true のときは、
		ビューの更新を、次にビューがアクティブ化されるまで
		保留していることを示します。
	
		ビューがアクティブでないときに OnUpdate_All() が
		要求されたら、この変数を true にし、
		OnUpdate_All() は実行しません。
	
		この値が true のときに、ビューがアクティブ化されたら、
		OnUpdate_All() を実行します。
	*/
	bool m_bUpdate_All_Requested ;

	/**
		印刷時に、１ページに印刷するダイヤグラムの範囲を、
		ダイヤグラムエンティティ座標で保持します。

		この値は、ユーザーがメニューコマンド
		[印刷][印刷プレビュー]を選択した時点で
		ビューに表示されているダイヤグラムの範囲になります。
	*/
	CdDcdSizeXy	m_sizePrintSize_Dgr ;

	///@}
protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
	 @return
		対応するドキュメントオブジェクトを返します。
	 */
	CDedDiagramDoc*	GetDocument() {
		CView* pCView = this ;
		return (CDedDiagramDoc*)pCView->GetDocument() ;};
	
	/**
	 @return
		CentDedDia オブジェクトを返します。
	 */
	const CentDedDia*	getCentDedDia()
	{
		const CentDedRosen*	pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		return pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get(  
			pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( 
				GetDocument()->getDiaName() 
			) 
		) ;
	};
	///@}
private:
	// --------------------------------
	///@name OnUpdate下請関数
	// --------------------------------
	///@{
	/**
		OnUpdate() の pHint が CHint_CentDedRessya オブジェクトで
		ない場合です。
	
		m_pCentDedDgrDia オブジェクトを完全に更新し、
		ウインドウ m_pCWndDiagram に反映させます。
	 */
	void OnUpdate_All() ;
	/**
		OnUpdate() の pHint が CHint_CentDedRessya オブジェクトの
		場合です。
	
		m_pCentDedDgrDia オブジェクトを完全に更新し、
		ウインドウ m_pCWndDiagram に反映させます。
	 */
	void OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) ;
	///@}
private:
	// --------------------------------
	///@name MFCコマンドハンドラ下請関数
	// --------------------------------
	///@{
	/** [表示]-[横軸方向縮小]
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
				エラーが発生した場合は、エラーメッセージボックスを表示します。
	@return
		-	0 :	成功
		-	-1 :	現在は実行できません。(エラーメッセージは表示しません)
		-	-2 ;	//	ダイヤグラムは表示されていません。
	*/
	int OnDiagramXDgrSizeInc_Process( BOOL bQueryEnable );
	/** [表示]-[横軸方向拡大]
	@return
		-	0 :	成功
		-	-1 :	現在は実行できません。(エラーメッセージは表示しません)
		-	-2 ;	//	ダイヤグラムは表示されていません。
	*/
	int OnDiagramXDgrSizeDec_Process( BOOL bQueryEnable );
	/** [表示]-[縦軸方向縮小] 
	@return
		-	0 :	成功
		-	-1 :	現在は実行できません。(エラーメッセージは表示しません)
		-	-2 ;	//	ダイヤグラムは表示されていません。
	*/
	int OnDiagramYDgrSizeInc_Process( BOOL bQueryEnable );
	/** [表示]-[縦軸方向拡大]
	@return
		-	0 :	成功
		-	-1 :	現在は実行できません。(エラーメッセージは表示しません)
		-	-2 ;	//	ダイヤグラムは表示されていません。
	*/
	int OnDiagramYDgrSizeDec_Process( BOOL bQueryEnable );
	/** [表示]-[縦軸方向リセット]
	@return
		-	0 :	成功
		-	-2 ;	//	ダイヤグラムは表示されていません。
	*/
	int OnDiagramYDgrSizeReset_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [表示]-[目盛を細かくする]
	@return
		-	0 :	成功
		-	-1 ;	//	コマンドを無効
	*/
	int OnDiagramMemoriDown_Process( BOOL bQueryEnable );
	/** [表示]-[目盛を粗くする]
	@return
		-	0 :	成功
		-	-1 ;	//	コマンドを無効
	*/
	int OnDiagramMemoriUp_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [表示]-[列車番号の表示]
	@return
		0以上は成功、エラーなら負の数です。
		-	1 	(bQueryEnable==TRUEの場合)このメニューコマンドが有効です。
		-	0 	(bQueryEnable==TRUEの場合)このメニューコマンドが無効です。
	*/
	int OnDiagramRessyabangou_Process( BOOL bQueryEnable );

	/** [表示]-[列車名の表示]
	@return
		0以上は成功、エラーなら負の数です。
		-	1 	(bQueryEnable==TRUEの場合)このメニューコマンドが有効です。
		-	0 	(bQueryEnable==TRUEの場合)このメニューコマンドが無効です。
	*/
	int OnUpdateDiagramRessyamei_Process( BOOL bQueryEnable );

	/** [表示]-[下り列車の表示]
	@return
		0以上は成功、エラーなら負の数です。
		-	1 	(bQueryEnable==TRUEの場合)このメニューコマンドが有効です。
		-	0 	(bQueryEnable==TRUEの場合)このメニューコマンドが無効です。
	*/
	int OnDiagramRessyasenKudari_Process( BOOL bQueryEnable );
	/** [表示]-[上り列車の表示]
	@return
		0以上は成功、エラーなら負の数です。
		-	1 	(bQueryEnable==TRUEの場合)このメニューコマンドが有効です。
		-	0 	(bQueryEnable==TRUEの場合)このメニューコマンドが無効です。
	*/
	int OnDiagramRessyasenNobori_Process( BOOL bQueryEnable );
	/** [表示]-[一般駅の駅名を表示しない]
	@return
		0以上は成功、エラーなら負の数です。
		-	1 	(bQueryEnable==TRUEの場合)このメニューコマンドが有効です。
		-	0 	(bQueryEnable==TRUEの場合)このメニューコマンドが無効です。
	*/
	int OnDiagramHideIppanekiEkimei_Process( BOOL bQueryEnable );
	/** [表示]-[停車駅の明示]
	@return
		0以上は成功、エラーなら負の数です。
		-	1 	(bQueryEnable==TRUEの場合)このメニューコマンドが有効です。
		-	0 	(bQueryEnable==TRUEの場合)このメニューコマンドが無効です。
	*/
	int OnDiagramStopmarkdraw_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [表示]-[更新]
	@see OnDiagramXDgrSizeInc_Process  
	*/
	int OnViewUpdate_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [表示]-[ダイヤグラムビューのプロパティ]
	@see OnDiagramXDgrSizeInc_Process  
	*/
	int OnDiagramViewProp_Process( BOOL bQueryEnable );
	
	///@}
// ********************************
//	CDedDiagramView
// ********************************
public:
	// ********************************
	///@name CDedDiagramView-操作
	// ********************************
	///@{
	/**
		ダイヤグラムビューの表示位置を、
		指定の時刻、指定の駅Orderに移動させます。
	 @param aCdDedJikoku [in]
		時刻を指定してください。
		この関数は、ダイヤグラムビューの左端を、この時刻にします。
		NULL 時刻を指定した場合、ダイヤグラムビューのX方向の位置を
		変更しません。
	 @param iEkiIndex [in]
		『駅Index』を指定してください。
		この関数は、ダイヤグラムの上端・下端を、この『駅Index』にします。
		負の数を指定した場合、ダイヤグラムビューのY方向の位置を
		変更しません。
		ダイヤグラムの上端・下端のどちらをこの『駅Index』にするかは、
		bEkiOrderIsBottom で指定します。
	 @param bEkiIndexIsBottom [in]
		- false ;	//	この関数は iEkiIndex を、ダイヤグラムの上端にします。
		- true ;	//	この関数は iEkiIndex を、ダイヤグラムの下端にします。
	 */
	virtual int setZone_Dgr( 
		const CdDedJikoku& aCdDedJikoku ,
		int iEkiIndex , bool bEkiIndexIsBottom ) ; 
	///@}


// ----------------------------------------------------------------
protected:
	CDedDiagramView();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(CDedDiagramView)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CDedDiagramView)
	public:
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
	virtual ~CDedDiagramView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:

private:
	// 生成されたメッセージ マップ関数

	//{{AFX_MSG(CDedDiagramView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDiagramViewProp();
	afx_msg void OnDiagramXDgrSizeInc();
	afx_msg void OnUpdateDiagramXDgrSizeInc(CCmdUI* pCmdUI);
	afx_msg void OnDiagramXDgrSizeDec();
	afx_msg void OnUpdateDiagramXDgrSizeDec(CCmdUI* pCmdUI);
	afx_msg void OnDiagramYDgrSizeInc();
	afx_msg void OnUpdateDiagramYDgrSizeInc(CCmdUI* pCmdUI);
	afx_msg void OnDiagramYDgrSizeDec();
	afx_msg void OnUpdateDiagramYDgrSizeDec(CCmdUI* pCmdUI);
	afx_msg void OnDiagramYDgrSizeReset();
	afx_msg void OnUpdateDiagramYDgrSizeReset(CCmdUI* pCmdUI);
	afx_msg void OnDiagramMemoriDown();
	afx_msg void OnUpdateDiagramMemoriDown(CCmdUI* pCmdUI);
	afx_msg void OnDiagramMemoriUp();
	afx_msg void OnUpdateDiagramMemoriUp(CCmdUI* pCmdUI);
	afx_msg void OnDiagramRessyabangou();
	afx_msg void OnUpdateDiagramRessyabangou(CCmdUI* pCmdUI);
	afx_msg void OnDiagramRessyamei();
	afx_msg void OnUpdateDiagramRessyamei(CCmdUI* pCmdUI);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnDiagramRessyasenKudari();
	afx_msg void OnUpdateDiagramRessyasenKudari(CCmdUI* pCmdUI);
	afx_msg void OnDiagramRessyasenNobori();
	afx_msg void OnUpdateDiagramRessyasenNobori(CCmdUI* pCmdUI);
	afx_msg void OnDiagramHideIppanekiEkimei();
	afx_msg void OnUpdateDiagramHideIppanekiEkimei(CCmdUI* pCmdUI);
	afx_msg void OnViewUpdate();
	afx_msg void OnDiagramStopmarkdraw();
	afx_msg void OnUpdateDiagramStopmarkdraw(CCmdUI* pCmdUI);
	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace ViewDiagram

#endif // !defined(AFX_CDEDDIAGRAMVIEW_H__51A5E4F0_D26B_4032_A34F_3BC45B6B3F1F__INCLUDED_)
