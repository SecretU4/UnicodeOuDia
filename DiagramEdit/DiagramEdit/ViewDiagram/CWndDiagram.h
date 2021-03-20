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
#if !defined(AFX_CWNDDIAGRAM_H__E5EA7615_628B_4059_BBA7_DD1DB661E133__INCLUDED_)
#define AFX_CWNDDIAGRAM_H__E5EA7615_628B_4059_BBA7_DD1DB661E133__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CWndDiagram.h : ヘッダー ファイル
//

#include "..\entDgr\CentDedDgrDia.h"
#include "CDcdDiagram2.h"
#include "WinUtil\CdScrollbarProp.h"

namespace ViewDiagram{
	using namespace DcDrawLib::WinUtil ;
/////////////////////////////////////////////////////////////////////////////
// CWndDiagram ウィンドウ
/**
 @brief
【概要】
	ダイヤグラムを描画する子ウインドウです。
  CDcdDiagram クラスを使って、クライアント領域にダイヤグラムを描画します。

	このクラスは、CDcdDiagram2,CDcdDiagram オブジェクトを包含します。
	このクラスは、CDcdDiagram2,CDcdDiagram オブジェクトの属性をもとに
	描画を行います。

	<H4>
 【使い方１−動的に子ウインドウを生成する】
	</H4>

	１．  親ウインドウクラスでは、このクラスのインスタンスを生成し、
	 Create() メソッドでウインドウ（HWND）を生成してください。
	  その後は、 CWnd::ShowWindow() ・ CWnd::UpdateWindow() 
	で、子ウインドウを画面上に表示してください。@n
	 通常この生成の手順は、親ウインドウの OnCreate()(WM_CREATE) で、
	行うことになります。

	２．  setCentDedDgrDia() で、対応する『ダイヤグラムダイヤ』オブジェクトと
	this の関連を確立してください。

	３．  readCdDedDispProp() で、
	ダイヤグラムの各部の色やフォントの属性を指定して下さい。
	  また、 setVlineMode() で、罫線のモードを設定してください。

	４．  setZone_Dgr() で、ウインドウ上に表示するダイヤグラムの範囲
	（スクロール位置）を指定して下さい。
	
	５．  this はこれ以降、 OnPaint() で、
	『ダイヤグラムダイヤ』 CentDedDgrDia オブジェクトに
	格納されているダイヤの情報をもとに、ウインドウに
	ダイヤグラムを描画します。
	
	<H4>
 【使い方２−CentDedDgrDia の更新時】
	</H4>

	 <H5>
	 CentDedDgrDia オブジェクトの内容が変化した場合
	 </H5>

	onUpdateCentDedDgrDia() を呼び出してください。
	  この関数は、 スクロールバーの範囲を最適化し、ウインドウを再描画して
	新しいダイヤの内容をウインドウに表示します。

	 <H5>
	   CentDedDgrDia オブジェクトに包含される
	『ダイヤグラム列車』 CentDedDgrRessya オブジェクトが追加・削除・
	変更された場合
	 </H5>

	   onUpdateCentDedDgrRessya() を呼び出してください。
	  この関数は、ウインドウを再描画して、新しいダイヤの内容をウインドウに
	表示します。

	<H4>
 【使い方３−親ウインドウ破棄】
	</H4>
	
 １．  親ウインドウが破棄されたとき（親ウインドウの WM_DESTROY/OnDestroy() ）
	では、このオブジェクトに対して CWnd::DestroyWindow() を呼び出して
	CWndDcdGrid の HWND を破棄してから、この CWndDcdGrid オブジェクトを
	破棄してください。


 */
class CWndDiagram : public CWnd
{
// ********************************
//	インナータイプ
// ********************************
public:
	typedef CWnd	super ;
private:
	// ********************************
	///@name	包含
	// ********************************
	///@{
	/**
		『ダイヤグラムエンティティクラス群』の属性をもとに、 IfDcdTarget 
		オブジェクトに『ダイヤグラム』を描画します。
	
		このオブジェクトの破棄の責務は、thisにあります。
		コンストラクタで生成・デストラクタでで破棄します。
	*/
	CDcdDiagram2*	m_pCDcdDiagram ;
	///@}

	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
		初期値は偽です。
		最初の onUpdateCentDedDgrDia() で、 
		.ini ファイルから、スクロール位置と
		罫線の設定を読み込んだあとは、真となります。
	 */
	bool m_bReadCWndDiagramDefault ;

	/**
		スクロールバー属性
	*/
	CdScrollbarProp	m_CdScrollbarPropX ;
	/** @see m_CdScrollbarPropX */
	CdScrollbarProp	m_CdScrollbarPropY ;

	///@}
 protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
		属性値を正規化します。
		対象となるのは、以下の属性です。
	
		- m_pCDcdDiagram->m_zonexyZone_Dgr 
		(m_pCentDedDgrDia->Zone() の内側になるように正規化します。)
	
	 @return
		何らかの値を変更した場合は真です。
	 */
	virtual bool update_adjustProp() ;

	/**
		ウインドウ上のコントロールを、現在の状況に合わせて
		更新します。
	
		m_pCDcdDiagram の、ダイヤグラムの表示位置の変更に
		合わせて、ウインドウをスクロールします。

		スクロールバーを、
		m_pCDcdDiagram->m_zonexyZone_Dgr 
		にあわせて調整します。
	 */
	virtual void update_updateScreen() ;
	///@}
protected:
	// --------------------------------
	///@name MFCメッセージハンドラの下請関数
	// --------------------------------
	///@{
	/**
		OnLButtonDblClk() の下請関数です。

		point が列車線上にあれば、時刻表ビューを開き、
		時刻表ビューのフォーカスを point が指している
		列車・駅時刻に移動させます。
	@param point [in]
		マウスカーソルの座標を指定してください。
		座標は、クライアント領域で指定してください。
	@return 
		-	1 ;	//	時刻表ビューへ移動しました
		-	-1 ;	//	point が列車線上にありません。
		-	-2 ;	//	ダイヤグラムビューに対応する 
				CentDedDia が見つかりません。
		-	-3 ;	//	時刻表ビューを開くのに失敗しました。

	*/
	int OnLButtonDblClk_openJikokuhyouView( CPoint point) ;
	/**
		OnLButtonDblClk() の下請関数です。

		point が、左側の駅名領域にあれば、
		駅ビューを開きます。
		また、point の直下の列車線の駅の、
		駅のプロパティダイアログを開きます。
	@param point [in]
		マウスカーソルの座標を指定してください。
		座標は、クライアント領域で指定してください。
	@return 
		-	1 ;	//	駅のプロパティダイアログを開きます。

	*/
	int OnLButtonDblClk_openDlgEkiProp( CPoint point) ;
	///@}
public:
	// ********************************
	///@name	CDcdDiagram-関連
	// ********************************
	///@{
	CentDedDgrDia* getCentDedDgrDia() ;
	CWndDiagram& setCentDedDgrDia( CentDedDgrDia* value ) ;
	///@}
public:
	// ********************************
	///@name CDcdDiagram-属性-CdDedDispProp にはないもの
	// ********************************
	///@{
	virtual bool	getDisplayRessyabangou()const ;

	/**
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	*/
	virtual int setDisplayRessyabangou( bool value ) ;

	virtual bool	getDisplayRessyamei()const ;
	/**
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	*/
	virtual int setDisplayRessyamei( bool value ) ;

	CdDcdPosXy	getPosDgr()const ;

	/** @return 
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	*/
	int setPosDgr( CdDcdPosXy value );

	double getDcdPerDgrX()const ;

	/** @return 
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	*/
	int setDcdPerDgrX( double value ) ;

	double getDcdPerDgrY()const ;

	/** @return 
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	*/
	int setDcdPerDgrY( double value ) ;


	virtual int	getVlineMode()const ;

	/**
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	*/
	virtual int setVlineMode( int value ) ;

	/**
		m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori 
		の値を取得します。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari ;	//	下り列車 (m_bDisplayRessyasenKudari)
		- Ressyahoukou_Nobori ; //	上り列車 (m_bDisplayRessyasenNobori)
	 @return 
		- true ;	//	列車線を表示する
		- false ;	//	列車線を表示しない
	 */
	virtual bool getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const ;
	
	/**
		m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori 
		の値を設定します。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari ;	//	下り列車 (m_bDisplayRessyasenKudari)
		- Ressyahoukou_Nobori ; //	上り列車 (m_bDisplayRessyasenNobori)
	 @param value [in]
		- true ;	//	列車線を表示する
		- false ;	//	列車線を表示しない
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	 */
	virtual int setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) ;
	
	/**
		CDcdDiagram::m_eStopMarkDraw 
		の値を取得します。
	 @return
		- StopMarkDraw_Not  停車記号を描画しません。  
		- StopMarkDraw_BriefStop  短時間停車の駅に、停車記号を描画します。  
	*/
	virtual CDcdDiagram::EStopMarkDraw	getStopMarkDraw()const ;

	/**
		CDcdDiagram::m_eStopMarkDraw 
		の値を設定します。
	 @param value [in]
		- StopMarkDraw_Not  停車記号を描画しません。  
		- StopMarkDraw_BriefStop  短時間停車の駅に、停車記号を描画します。  
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	*/
	virtual int setStopMarkDraw( CDcdDiagram::EStopMarkDraw value ) ;

	/**
		このクラスがサポートする、
		縦罫の間隔の設定の選択肢を取得することができます。
	 @param pContVLINE [out]
		この関数はこのコンテナに、縦罫の間隔の設定を書き込みます。
		コンテナがそれまで保持していた要素は破棄します。
		このコンテナのインデクスは、m_idxVlineMode に対応します。
		\n不要であれば NULL でもかまいません。
	 @return
		選択肢の数を返します。	
	 */
	virtual int getVlineChoices( Mui<CDcdDiagram::VLINE>* pContVLINE ) ;
	
	// ********************************
	///@name	CDcdDiagram-操作
	// ********************************
	///@{
	/**
		CdDedDispProp オブジェクトの属性から、 
		ダイヤグラムの各部の色やフォントの属性を決定します。
	
		また、ウインドウの再描画を行わせます。
	
		このメソッドが設定する属性は、m_pCDcdDiagram の以下のものです。
	
		- CdFontProp	m_fontpropDiaRessyaFont ;
		- COLORREF	m_colorDiaMojiColor ;
		- COLORREF	m_colorDiaHaikeiColor ;
		- COLORREF	m_colorDiaRessyaColor ;
		- COLORREF	m_colorDiaJikuColor ;
		- int m_iDiaRessyajouhouHyoujiEkiOrderKudari ;
		- int m_iDiaRessyajouhouHyoujiEkiOrderNobori ;
		
	 @param value [in]
		CdDedDispProp オブジェクトを指定して下さい。
	 @return
		成功したら0以上、エラーなら負の数です。
		但し、現状では 0 しか返しません。
	 */	
	virtual int readCdDedDispProp( const CdDedDispProp& value ) ;
	
	/**
		このクラスが描画を行う領域の座標を、
	 	『ダイヤグラムエンティティ座標系』で取得します。
		この値は、m_posDgr・m_dwDcdPerDgrX・m_dwDcdPerDgrY から
		導出されます。
	@return 
		このクラスが描画を行う領域の座標を
		『ダイヤグラムエンティティ座標系』で返します。
	@attention
		pIfDcdTarget へのダイヤグラム表示が不可能な場合、
		戻り値のgetX().getSize() , getY().getSize() のいずれかが
		0になります。
	*/
	virtual CdDcdZoneXy	getZone_Dgr()const ;

	/**
		このクラスが描画を行う領域の座標を、
	 	『ダイヤグラムエンティティ座標系』で設定します。
		この値は、m_posDgr・m_dwDcdPerDgrX・m_dwDcdPerDgrY に
		換算のうえで設定されます。
	@param value [in]
		このクラスが描画を行う領域の座標を
		『ダイヤグラムエンティティ座標系』で指定してください。

		ダイヤグラムが pIfDcdTarget 内に描画できない場合は、
		setZone_Dgr() は動作しません。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	 */
	virtual int setZone_Dgr( const CdDcdZoneXy& value ) ;
	
	/**
		ウインドウサイズ変更時の動作を取得します。
	@return 
		- false:表示範囲を変更(OuDia Ver.1.00.04 より後)
		- true: 表示範囲を変更しない(OuDia Ver.1.00.04 互換)
	*/
	bool getKeepZoneDgrOnSize()const ;

	/**
		ウインドウサイズ変更時の動作を設定します。
	@param value [in] 
		- false:表示範囲を変更(OuDia Ver.1.00.04 より後)
		- true: 表示範囲を変更しない(OuDia Ver.1.00.04 互換)
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	*/
	int setKeepZoneDgrOnSize( bool value );
	
	///@}	
	
	
	// ********************************
	///@name	CDcdDiagrem-操作
	// ********************************
	///@{
	///@}
	// ********************************
	///@name	CDcdDiagrem2-属性
	// ********************************
	///@{
	bool getHideIppanekiEkimei()const ;

	/**
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	値が変更され、ウインドウが再描画されました。
	*/
	int setHideIppanekiEkimei( bool value )  ;
	///@}
	// ********************************
	///@name	CDcdDiagrem2-操作
	// ********************************
	///@{
	/**
		ウインドウ内で、ダイヤグラムを描画する領域の大きさを求めます。
		単位は、 IfDcdTarget 上の座標です。
	 @return
		ダイヤグラムの描画領域を返します。
		この値の X,Y いずれかのサイズが0以下の場合、
		ダイヤグラムの描画はできません。
	 */
	virtual CdDcdZoneXy calcDiagramZoneDcd()const ;
	///@}
	// ********************************
	///@name	CWndDiagram-包含
	// ********************************
	///@{
	CDcdDiagram2* getCDcdDiagram() ;
	///@}

	// ********************************
	///@name	CWndDiagram-構築
	// ********************************
	///@{
	/**
		ウインドウのHWNDを生成します。
	 @param rect [in]
		ウインドウのサイズと位置を指定します。
		CRect オブジェクトまたは RECT 構造体を指定できます。
	 @param pParentWnd [in]
		コントロールの親ウィンドウ (CDialogの場合が多い) を指定します。
		NULL は指定できません。
	 @param nID [in]
		コントロールの ID を指定します。
	 */
	BOOL Create( const RECT& rect, CWnd* pParentWnd, UINT nID = 0 );

	/**
		サイズ０で、ウインドウのHWNDを生成します。
		親ウインドウのサイズをもとに位置を決定する場合には、
		こちらを使うことができます。
	 @param pParentWnd [in]
		コントロールの親ウィンドウ (CDialogの場合が多い) を指定します。
		NULL は指定できません。
	 @param nID [in]
		コントロールの ID を指定します。
	 */
	BOOL Create( CWnd* pParentWnd, UINT nID  = 0 );
	///@}

	///@}

	// ********************************
	///@name	CWndDiagram-操作
	// ********************************
	///@{
	/**
		クラスユーザーは、
		 m_pCentDedDgrDia オブジェクトの内容を更新したときに、
		onUpdateCentDedDgrDia() を呼び出してください。
		  この関数は、 スクロールバーの範囲を最適化し、ウインドウを再描画して
		新しいダイヤの内容をウインドウに表示します。
	 */
	virtual void onUpdateCentDedDgrDia() ;
	
	/**
		クラスユーザーは、
		   CentDedDgrDia オブジェクトに包含される
		『ダイヤグラム列車』 CentDedDgrRessya オブジェクトが追加・削除・
		変更された場合
		   onUpdateCentDedDgrRessya() を呼び出してください。
		  この関数は、ウインドウを再描画して、新しいダイヤの内容をウインドウに
		表示します。
	 */
	virtual void onUpdateCentDedDgrRessya() ;
	///@}

// ----------------------------------------------------------------
// コンストラクション
public:
	CWndDiagram();

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CWndDiagram)
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CWndDiagram();

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CWndDiagram)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace ViewDiagram

#endif // !defined(AFX_CWNDDIAGRAM_H__E5EA7615_628B_4059_BBA7_DD1DB661E133__INCLUDED_)
