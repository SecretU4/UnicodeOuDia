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
//	CaDcdTargetZoomDisplay.h
// ****************************************************************
*/
/** @file */
#ifndef  CaDcdTargetZoomDisplay_h
#define  CaDcdTargetZoomDisplay_h

#include <windows.h>
#include "DcDraw/IfDcdTarget.h"
//#include "CDcdTargetMfcPrintInfo.h"

namespace DcDrawLib{
namespace DcDraw{
namespace Print{

// ****************************************************************
//	CaDcdTargetZoomDisplay
// ****************************************************************
/**
@brief
  印刷/印刷プレビューの描画領域である IfDcdTarget オブジェクトを
ターゲットとする、アダプタクラスです。ターゲットのDCに、
ディスプレイに準じた論理座標を設定します。

<H4>
【座標系について】
</H4>
 ターゲットオブジェクトとなる IfDcdTarget オブジェクトの DC の
座標系は、印刷の場合も印刷プレビューの場合も、
  プリンタの１ドット＝１論理単位 
でなくてはなりません。

  このクラスは、対象となる DC の座標系を、ディスプレイ画面に
準じたものに変更します。
  たとえば、 

	ディスプレイのDPI：プリンタのDPI が １：４ 

の場合は、このクラスはDCのマッピングモードを変更して、

	１論理単位：プリンタの４ドット

となるようにします。
  これにより、IfDcDraw オブジェクトにこのオブジェクトを渡して
描画すると、ほぼ画面の大きさに準じた印刷結果を得ることができます。

<H4>
【使い方】
</H4>

１．  あらかじめ、 印刷/印刷プレビューの描画領域である IfDcdTarget 
オブジェクトを生成していなくてはなりません。

２．  コンストラクタでは、ターゲットのIfDcdTarget と、プリンタのDCを
指定してください。プリンタの DC は、DPIの計算を行う場合に必要です。
  コンストラクタは、指定された DC からプリンタのDPIを取得して、
その計算をもとにマッピングモードを変更します。

３．  このオブジェクトを IfDcDraw インターフェースに渡して、描画を
行うことができます。

４．  このクラスのデストラクタは、２．で変更したマッピングモードを
元に戻します。
 */
class CaDcdTargetZoomDisplay : public IfDcdTarget 
{
// ********************************
///@name 関連
// ********************************
///@{
 private:
	/**
	 *  ターゲットオブジェクトです。
	 *
	 *	印刷/印刷プレビューの描画領域である IfDcdTarget オブジェクトです。
	 *
	 *	 ターゲットオブジェクトとなる IfDcdTarget オブジェクトの DC の
	 *	座標系は、印刷の場合も印刷プレビューの場合も、
	 *	プリンタの１ドット＝１論理単位 でなくてはなりません。
	 *	
	 *	  このオブジェクトの破棄の責務は、クラスユーザーにあります。
	 *	  このオブジェクトは、this が破棄されるまでは生存しなくてはなりません。
	 *	
	 *	  コンストラクタで決まります。
	 */
	IfDcdTarget* m_pTarget ;

	/**
	 *  プリンタの DC へのハンドルです。
	 *
	 *	印刷の場合、
	   @code
	  	m_pTarget->getHdc() = プリンタのDC
	 	this->m_hPrinterHdc = プリンタのDC
	   @endcode
	 *	印刷プレビューの場合、
	   @code
	 	m_pTarget->getHdc() = プレビュー画面のDC
	 	this->m_hPrinterHdc = プリンタのDC
	   @endcode
	 *	となります。
	 */
	HDC	m_hPrinterHdc ;
///@}
// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 * 	  描画の必要な領域の座標範囲。
	 *	  描画領域の座標値は、このクラスにより、マップモードがディスプレイに
	 *	準じたものに変更されています。
	 *	
	 *	コンストラクタで決まります。
	 */
	CdDcdZoneXy	m_zonexyZone ;
	
	
///@}

// --------------------------------
///@name 内部データ
// --------------------------------
///@{
 private:
	/**
	 *	コンストラクタにおける、SaveDC() の戻り値を保存します。
	 *	SaveDC() が失敗した場合は、 0 となります。
	 */
	int	m_iSaveDcId ;
///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param pTarget [in]
	 *  ターゲットオブジェクトです。@n
	 *	印刷/印刷プレビューの描画領域である IfDcdTarget オブジェクトです。@n
	 *	 ターゲットオブジェクトとなる IfDcdTarget オブジェクトの DC の
	 *	座標系は、印刷の場合も印刷プレビューの場合も、
	 *	プリンタの１ドット＝１論理単位 でなくてはなりません。@n
	 *	このオブジェクトの破棄の責務は、クラスユーザーにあります。
	 *	このオブジェクトは、this が破棄されるまでは生存しなくてはなりません。
	 * @param hPrinterHdc [in]
	 *  プリンタの DC へのハンドルです。@n
	 *	このオブジェクトの破棄の責務は、クラスユーザーにあります。
	 *	このオブジェクトは、this が破棄されるまでは生存しなくてはなりません。
	 */
	CaDcdTargetZoomDisplay( 
		IfDcdTarget* pTarget ,
		HDC	hPrinterHdc ) ;
	virtual ~CaDcdTargetZoomDisplay() ; 

// ********************************
///@name	IfDcdTarget
// ********************************
///@{
 public:
	/**
	 * @return
	 * 	描画を行うDCを取得します。
	 * 	このHDCの破棄の責務は、thisにあります。
	 *
	 *	【オーバライド】
	 *
	 *	印刷の場合、この関数が返すのは プリンタのDCです。
	 *	印刷プレビューの場合は、この関数が返すのは、プレビュー画面のDCです。
	 *
	 *	印刷プレビューの場合は、プリンタのDCは getPrinterHdc() で取得できます。
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
	virtual Ou<CGdiHFontHolder>	createGdiHFontHolder(  const CdFontProp& aCdFontProp )
	{
		return m_pTarget->createGdiHFontHolder( aCdFontProp ) ;
	};
	
	/**
	 	CdPenPropオブジェクトの属性をもとに、ペンを生成します
	 @param aCdPenProp [in]
	 	ペン属性を指定してください。
	 @return
		ペンのハンドルを保持する CGdiHPenHolder を返します。
	*/
	virtual  Ou<CGdiHPenHolder>		createGdiHPenHolder(  const CdPenProp& aCdPenProp ) 
	{
		return m_pTarget->createGdiHPenHolder( aCdPenProp ) ;
	};

	/**
	 	CdBrushPropオブジェクトの属性をもとに、ブラシを生成します
	 @param aCdBrushProp [in]
	 	ブラシ属性を指定してください。
	 @return
		ブラシのハンドルを保持する CGdiHBrushHolder を返します。
	*/
	virtual Ou<CGdiHBrushHolder>	createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) 
	{
		return m_pTarget->createGdiHBrushHolder( aCdBrushProp ) ;
	};

///@}
// ********************************
//	CaDcdTargetZoomDisplay_h
// ********************************
 public:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	///@}
};

} //namespace Print
} //namespace DcDraw
} //namespace DcDrawLib

#endif /*CaDcdTargetZoomDisplay_h*/
