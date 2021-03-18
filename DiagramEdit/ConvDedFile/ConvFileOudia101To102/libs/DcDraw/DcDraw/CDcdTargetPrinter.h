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
//	CDcdTargetPrinter.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdTargetPrinter_h
#define  CDcdTargetPrinter_h

#include "DcDraw/IfDcdTarget.h"
#include "DcDraw/CGdiCache.h"

// ****************************************************************
//	CDcdTargetPrinter
// ****************************************************************
/**
 * @brief
 * 【概要】
 *	プリンタの、描画領域を提供するクラスです。
 *	指定されたプリンタのDCの用紙の領域を Win32 GetDeviceCaps() 
 *	APIで取得し、描画領域とします。
 *
 *	インスタンスは、スタック上に生成することを想定しています。
 *
 *	このクラスは、コンストラクタで、 DC のマッピングモードを変更します。
 *	
 *	- MapMode を MM_ANISOTROPIC 
 *	- 原点は左上で、座標は右下が正方向
 *	- 論理座標は、ウインドウへの描画と同様の描画ができるように調整
 *
 *	このマッピングモードを使うことにより、この DC に対しては、
 *	 MM_TEXT モードのウインドウへの描画アルゴリズムと同様の描画ができるように
 *	なります。
 *
 *	なお、このクラスは、 DC への StartDoc()・StartPage()・EndPage()・
 *	EndDoc() は行いません。これらは、暮らすユーザーの責務です。
 *
 * 【使い方】
 *
 * １． スタック上にインスタンスを生成してください。
 *	コンストラクタでは、対象となるプリンタの DC を指定してください。
 *
 * ※  プリンタの DC の生成は、 CPrintDialog の使用が便利です。
 *
 * ２． 必要に応じて、 DC に対して StartDoc()・StartPage() を呼び出して
 *	ください。
 *	
 * ３． StartPage() を行ってから、  this を IfDcDraw オブジェクトに渡して、
 *	描画を行わせてください。
 * 
 * ４． 必要に応じて、 DC に対して EndPage() ・ EndDoc() を呼び出して
 *	ください。
 *	
 */
class CDcdTargetPrinter : public IfDcdTarget
{
// ********************************
///@name 関連
// ********************************
///@{
 private:
	/**
	 * 	対象となるプリンタ DC 。
	 *	この HDC の破棄の責務は クラスユーザーにあります。
	 * 	このHWNDは、thisより長く生存しなくてはなりません。
	 */
	HDC			m_hDc ;
///@}
// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 * 	描画の必要な領域（プリンタDC）の座標範囲
	 *	これは同時に、描画が有効な範囲ともなります。
	 * 	単位は、論理単位です。
	 *
	 *	コンストラクタで決まります。
	 */
	CdDcdZoneXy	m_zoneLogical ;
	
	/**
	 * 	描画の必要な領域（プリンタDC）の座標範囲
	 *	これは同時に、描画が有効な範囲ともなります。
	 * 	単位は、デバイス単位（ピクセル）です。
	 *
	 *	コンストラクタで決まります。
	 */
	CdDcdZoneXy	m_zonePixel ;
	
///@}

// ********************************
///@name	集約
// ********************************
///@{
 private:
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
	 * @param hDc [in]
	 * 	対象となるプリンタ DC 。
	 *	この HDC の破棄の責務は クラスユーザーにあります。
	 * 	このHWNDは、thisより長く生存しなくてはなりません。
	 */
	CDcdTargetPrinter( HDC hDc ) ;
	
	virtual ~CDcdTargetPrinter() ;

public:
	// ********************************
	///@name	IfDcdTarget
	// ********************************
	///@{
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
	 	CdFontPropオブジェクトの属性をもとに、フォントを生成します
	 @param aCdFontProp [in]
	 	フォント属性を指定してください。
	 @return
		フォントのハンドルを保持する CGdiHFontHolder を返します。
	*/
	virtual Ou<CGdiHFontHolder>	createGdiHFontHolder(  const CdFontProp& aCdFontProp ) ;
	
	/**
	 	CdPenPropオブジェクトの属性をもとに、ペンを生成します
	 @param aCdPenProp [in]
	 	ペン属性を指定してください。
	 @return
		ペンのハンドルを保持する CGdiHPenHolder を返します。
	*/
	virtual  Ou<CGdiHPenHolder>		createGdiHPenHolder(  const CdPenProp& aCdPenProp ) ;

	/**
	 	CdBrushPropオブジェクトの属性をもとに、ブラシを生成します
	 @param aCdBrushProp [in]
	 	ブラシ属性を指定してください。
	 @return
		ブラシのハンドルを保持する CGdiHBrushHolder を返します。
	*/
	virtual Ou<CGdiHBrushHolder>	createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) ;

	///@}
// ********************************
//	CDcdTargetGetDC
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	CdDcdZoneXy	getZoneLogical(){
		return m_zoneLogical ;	};
	CdDcdZoneXy	getZonePixel(){	
		return m_zonePixel ;};
	///@}

};
#endif /*CDcdTargetPrinter_h*/

