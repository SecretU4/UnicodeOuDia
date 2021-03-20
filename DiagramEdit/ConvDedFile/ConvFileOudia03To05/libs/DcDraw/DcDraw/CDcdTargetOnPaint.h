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
//	CDcdTargetOnPaint.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdTargetOnPaint_h
#define  CDcdTargetOnPaint_h

#include "./IfDcdTarget.h"
#include "./CGdiCache.h"

// ****************************************************************
//	CDcdTargetOnPaint
// ****************************************************************
/**
* @brief
* 【概要】
*	ウインドウにWM_PAINTが到着したときの、描画領域を表すクラスです。
*
* 	  このクラスは、WM_PAINTメッセージが到着したときのイベントハンドラで
* 	スタック上に生成することを想定しています。
* 	  DcDrawモデルにおける、描画を行う領域を表すオブジェクトのインターフェース
* 	です。
*
* 【使い方】
*
* １． WM_PAINT メッセージがウインドウに到着したときにだけ、
* 	オブジェクトをスタック上に生成してください。
* 	  使い方は、次の３通りがあります。
*
* 	（１）  BeginPaint() を呼び出して、コンストラクタでPAINTSTRUCTを渡して
* 	ください。
*
* 	（２）   MFCアプリケーションの場合は、CPaintDCオブジェクトを生成して
* 	そのメンバ CPaintDC::m_ps をコンストラクタに渡してください。
*
* 	（３）ウインドウハンドルを、コンストラクタに渡してください。
* 	このクラスは、コンストラクタで BeginPaint() を呼び出し、DCを取得します。
* 	  この場合、thisはデストラクタではEndPaint() を実行します。
*
* ２．   this を IfDcDraw オブジェクトに渡して、描画を行わせてください。
* 
*/
class CDcdTargetOnPaint : public IfDcdTarget
{
// --------------------------------
///@name	内部データ
// --------------------------------
///@{
 private:
	/**
	* 	ウインドウハンドル。
	* 	コンストラクタで決まります。
	* 	このウインドウは,thisより長く生存しなくてはなりません。
	*/
	HWND		m_hWnd ;
	
	/**
	* 	描画領域を表す構造体です。
	* 	コンストラクタで決まります。
	* 
	* 	コンストラクタでPAINTSTRUCTが渡された場合は、そのアドレスを
	* 	保持します。
	* 	この場合、EndPaint() の責務は、クラスユーザーにあります。
	* 	thisが生存している間は、EndPaint()をしてはいけません。
	* 	また、PAINTSTRUCTもthisよりながく存続しなくてはなりません。
	* 
	* 	コンストラクタでPAINTSTRUCTが渡されたなかった場合は、
	* 	コンストラクタはPAINTSTRUCTを生成し、BeginPaint()を行います。
	* 	この場合、EndPaint() の責務は、thisにあります。
	*/
	PAINTSTRUCT*	m_pPaintstruct ;
	
	/**
	* 	thisがコンストラクタでBeginPaint()を行った場合は真になります。
	*/
	bool			m_bPaintstructEndPaintObligatory ;
	
	
	/**
	 *	GDIオブジェクトの属性と、ハンドルの対照表を保持します。
	 */
	CGdiCache	m_CGdiCache ;
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	* @param hWnd [in]
	* 	ウインドウハンドル。
	* 	このウインドウは,thisより長く生存しなくてはなりません。
	* @param pPaintstruct [in]
	* 	描画領域を表す構造体です。
	* 	コンストラクタで決まります。
	*/
	CDcdTargetOnPaint( HWND hWnd , PAINTSTRUCT* pPaintstruct ) ;

	/**
	* @param hWnd [in]
	* 	ウインドウハンドル。
	* 	このウインドウは,thisより長く生存しなくてはなりません。
	*/
	CDcdTargetOnPaint( HWND hWnd ) ;
	
	virtual ~CDcdTargetOnPaint() ;

// ********************************
///@name	IfDcdTarget
// ********************************
///@{
 public:
	/**
	* @return
	* 	描画を行うDCを取得します。
	* 	このHDCの破棄の責務は、thisにあります。
	*/
	virtual HDC	getHdc() ;
	
	/**
	* @return
	* 	描画の必要な領域の座標範囲を取得することができます。
	* 	単位は、論理単位です。
	*/
	virtual CdDcdZoneXy getZone() ;
	
	/**
	* @return
	* 	描画が有効な範囲を取得できます。
	* 	通常は、getZone()と同じ領域となります。
	* 
	* 	ウインドウのWM_PAINTによる描画の場合、この関数が返すのは、
	* 	再描画が必要な領域となります。
	* 	この領域を無視してもかまいません。ただし、この範囲外への描画は
	* 	意味がありませんので、この範囲外への描画を抑制するようにすれば、
	* 	描画処理の効率の改善が期待できます。
	*/
	virtual CdDcdZoneXy getDrawableZone() ;

	/**
	* 	CdFontPropオブジェクトの属性をもとに、フォントを生成します
	* @param aCdFontProp [in]
	* 	フォント属性を指定してください。
	* @param hDc [in]
	* 	CdFontProp オブジェクトに設定されている高さ属性が
	* 	PointTextHeight で指定されている場合は、LOGFONTに変換
	* 	する際には、その変換には、フォントの描画を行うHDCが必要です。
	* 	ここには、そのHDCを指定してください。
	* 	もし、このケースでHDCに NULL を指定した場合は、スクリーンDCを
	* 	もとにLOGFONT構造体を作成します。
	* 	CdFontProp オブジェクトに設定されている高さ属性が
	* 	Logicalunit... で指定されている場合は、このHDCには
	* 	意味がありません。
	* @return
	*	フォントのハンドルを返します。
	*	このハンドルの破棄の責務は、thisにあります。
	*	関数呼出元は、ハンドルを解放してはいけません。
	*/
	virtual HFONT	CreateFont(  const CdFontProp& aCdFontProp ) {
		return m_CGdiCache.CreateFont( aCdFontProp , getHdc() ) ;};
	
	/**
	* 	CdPenPropオブジェクトの属性をもとに、ペンを生成します
	* @param aCdPenProp [in]
	* 	ペン属性を指定してください。
	* @return
	*	ペンのハンドルを返します。
	*	このハンドルの破棄の責務は、thisにあります。
	*	関数呼出元は、ハンドルを解放してはいけません。
	*/
	virtual HPEN	CreatePen(  const CdPenProp& aCdPenProp )   {
		return m_CGdiCache.CreatePen( aCdPenProp ) ;};

	/**
	* 	CdBrushPropオブジェクトの属性をもとに、ペンを生成します
	* @param aCdBrushProp [in]
	* 	ペン属性を指定してください。
	* @return
	*	ペンのハンドルを返します。
	*	このハンドルの破棄の責務は、thisにあります。
	*	関数呼出元は、ハンドルを解放してはいけません。
	*/
	virtual HBRUSH	CreateBrush(  const CdBrushProp& aCdBrushProp ) {
		return m_CGdiCache.CreateBrush( aCdBrushProp ) ;};
///@}
};



#endif /*CDcdTargetOnPaint_h*/
