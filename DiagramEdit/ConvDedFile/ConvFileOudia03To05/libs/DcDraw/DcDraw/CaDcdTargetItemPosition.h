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
//	CaDcdTargetItemPosition.h
// ****************************************************************
*/
/** @file */
#ifndef  CaDcdTargetItemPosition_h
#define  CaDcdTargetItemPosition_h

#include "./IfDcdTarget.h"

// ****************************************************************
//	CaDcdTargetItemPosition
// ****************************************************************
/**
* @brief
* 【概要】
*	DcDrawモデルにおいて、他の IfDcdTarget の中の特定の領域を
*	描画領域として提供します。アダプタクラスです。
*
*	画面全体の IfDcDrawTarget オブジェクト内の一部の領域を、
*	ウインドウ内の可視部品一つを描画する『描画アイテム』オブジェクトに対して、
*	指示するのに使います。
*
*	このオブジェクトは、画面全体の IfDcDrawTarget オブジェクトと関連を
*	持ちます。
*/
class CaDcdTargetItemPosition : public IfDcdTarget
{
// ********************************
///@name	属性
// ********************************
///@{

 private:
	/**
	* 	描画の必要な領域の座標範囲
	* 	単位は、論理単位です。
	*/
	CdDcdZoneXy	m_zonexyZone ;
	
///@}
// ********************************
///@name	関連
// ********************************
///@{
 private:
	/**
	*	画面全体（あるいは、 this より広い範囲）を表す DcDrawTarget 
	*	オブジェクトです。
	*	このオブジェクトは、 this より長く生存しなくてはなりません。
	*/
	IfDcdTarget*	m_pIfDcdTarget ;
	
///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param pIfDcdTarget [in]
	 *	画面全体（あるいは、 this より広い範囲）を表す DcDrawTarget 
	 *	オブジェクトです。
	 *	このオブジェクトは、 this より長く生存しなくてはなりません。
	 * @param zonexyZone [in]
	 * 	描画の必要な領域の座標範囲
	 * 	単位は、論理単位です。
	 */
	CaDcdTargetItemPosition( 
			IfDcdTarget* pIfDcdTarget ,
			const CdDcdZoneXy& zonexyZone 
		) ;
	virtual ~CaDcdTargetItemPosition() ;

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
	* @return
	*	フォントのハンドルを返します。
	*	このハンドルの破棄の責務は、thisにあります。
	*	関数呼出元は、ハンドルを解放してはいけません。
	*/
	virtual HFONT	CreateFont(  const CdFontProp& aCdFontProp ) {
		return m_pIfDcdTarget->CreateFont( aCdFontProp )  ;} ;
	
	/**
	* 	CdPenPropオブジェクトの属性をもとに、ペンを生成します
	* @param aCdPenProp [in]
	* 	ペン属性を指定してください。
	* @return
	*	ペンのハンドルを返します。
	*	このハンドルの破棄の責務は、thisにあります。
	*	関数呼出元は、ハンドルを解放してはいけません。
	*/
	virtual HPEN	CreatePen(  const CdPenProp& aCdPenProp ) {
		return m_pIfDcdTarget->CreatePen( aCdPenProp )  ;} ;

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
		return m_pIfDcdTarget->CreateBrush( aCdBrushProp )  ;} ;
		
///@}
// ********************************
///@name	CaDcdTargetItemPosition
// ********************************
///@{
 public:
	virtual CaDcdTargetItemPosition& setZone( const CdDcdZoneXy& ev ) ;

	/**
	 * @return
	 *	m_zonexyZone で示される、この部品の描画位置が、
	 *	getDrawableZone() と全く接していない場合に真です。
	 *	この値が真であれば、この描画領域への描画は
	 *	全く意味がありません。
	 */
	virtual bool isDrawable() ;
///@}
};



#endif /*CaDcdTargetItemPosition_h*/
