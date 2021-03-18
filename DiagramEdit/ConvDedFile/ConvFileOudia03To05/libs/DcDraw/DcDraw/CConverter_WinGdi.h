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
//	CConverter_WinGdi.h
// ****************************************************************
*/
/** @file */
#ifndef  CConverter_WinGdi_h

#include <windows.h>
#include "CdFontProp.h"
#include "CdPenProp.h"
#include "CdBrushProp.h"
#include "CdDcdPosXy.h"
#include "CdDcdZoneXy.h"
#include "CdDcdSizeXy.h"
#include "str\tstring.h"
#include "CdDrawTextProp.h"
#include "CdColorProp.h"

// ****************************************************************
//	CConverter_WinGdi
// ****************************************************************
/**
* @brief
* 【概要】
* 	WIN32で使用する構造体と、DcDrawで使用するクラスとの間の相互変換を
* 	行います。
*/
class CConverter_WinGdi
{
 public:
	// ********************************
	///	@name 座標を扱う関数群
	// ********************************
	///@{
	/**
	 *	POINT 型を CdDcdPosXy に変換します。
	 * @param aPOINT [in]
	 *	変換元
	 * @param pCdDcdPosXy [out]
	 *	この関数はこのアドレスに、変換した値を書き込みます。
	 */
	void toCdDcdPosXy( const POINT& aPOINT , CdDcdPosXy* pCdDcdPosXy ) ; 

	CdDcdPosXy CdDcdPosXyOf( const POINT& aPOINT ) {
		CdDcdPosXy	aCdDcdPosXy ;
		toCdDcdPosXy( aPOINT , &aCdDcdPosXy ) ;
		return ( aCdDcdPosXy ) ;
	};
	
	/**
	 *	CdDcdPosXy を POINT 型に変換します。
	 * @param aCdDcdPosXy [in]
	 *	変換元
	 * @param pPOINT [out]
	 *	この関数はこのアドレスに、変換した値を書き込みます。
	 */
	void toPOINT( const CdDcdPosXy& aCdDcdPosXy , POINT* pPOINT ) ;
	
	POINT POINTOf( const CdDcdPosXy& aCdDcdPosXy ) {
		POINT	aPOINT ;
		toPOINT( aCdDcdPosXy  , &aPOINT ) ;
		return ( aPOINT ) ;
	};

	/**
	 *	RECT 型を CdDcdZoneXy に変換します。
	 * @param aPOINT [in]
	 *	変換元
	 * @param pCdDcdZoneXy [out]
	 *	この関数はこのアドレスに、変換した値を書き込みます。
	 */
	void toCdDcdZoneXy( const RECT& aRECT , CdDcdZoneXy* pCdDcdZoneXy ) ; 

	CdDcdZoneXy CdDcdZoneXyOf( const RECT& aRECT ) {
		CdDcdZoneXy	aCdDcdZoneXy ;
		toCdDcdZoneXy( aRECT , &aCdDcdZoneXy ) ;
		return ( aCdDcdZoneXy ) ;
	};
	
	/**
	 *	CdDcdZoneXy を RECT 型に変換します。
	 * @param aCdDcdPosXy [in]
	 *	変換元
	 * @param pPOINT [out]
	 *	この関数はこのアドレスに、変換した値を書き込みます。
	 */
	void toRECT( const CdDcdZoneXy& aCdDcdZoneXy , RECT* pRECT ) ;
	
	RECT RECTOf( const CdDcdZoneXy& aCdDcdZoneXy ) {
		RECT	aRECT ;
		toRECT( aCdDcdZoneXy  , &aRECT ) ;
		return ( aRECT ) ;
	};

	///@}
	// ********************************
	///	@name Colorを扱う関数群
	// ********************************
	///@{
	/**
		COLORREF を、CdColorProp に変換します。
	@param value [in]
		変換元の値を指定してください。
	@return 
		変換後の値を指定してください。
	*/
	CdColorProp CdColorPropOf( COLORREF value )const;

	/**
		CdColorProp を COLORREF に変換します。
	@param value [in]
		変換元の値を指定してください。
	@return 
		変換後の値を指定してください。
	*/
	COLORREF COLORREFOf( const CdColorProp& value )const;

	/**
	*	 システムカラーの属性を、
	*	CdColorProp オブジェクトへ変換します。
	* @param fnObject [in]
	* 	GetSysColor() で指定する、表示要素
	*	の定数を指定してください。
	* @return
	* 	 CdColorProp 構造体を返します。
	*/
	CdColorProp CdColorPropOfSysColor( int nIndex ) ;
	
	///@}
	// ********************************
	///	@name Fontを扱う関数群
	// ********************************
	///@{
	
	/**
	*	CdFontPropオブジェクトの内容を、 LOGFONT 構造体へ変換します。
	*
	* 	CdFontProp オブジェクトに設定されている高さ属性が
	* 	PointTextHeight で指定されている場合は、LOGFONTに変換
	* 	する際には、その変換には、フォントの描画を行うHDCが必要です。
	* 	もし、このケースでHDCの指定を省略した場合は、スクリーンDCを
	* 	もとにLOGFONT構造体を作成します。
	* @param aCdFontProp [in]
	* 	フォント属性を指定してください。
	* @param pLOGFONT [out]
	* 	この関数はこの構造体に、属性を書き込みます。
	* @param hDc [in]
	* 	CdFontProp オブジェクトに設定されている高さ属性が
	* 	PointTextHeight で指定されている場合は、LOGFONTに変換
	* 	する際には、その変換には、フォントの描画を行うHDCが必要です。
	* 	ここには、そのHDCを指定してください。
	* 	もし、このケースでHDCの指定を省略した場合は、スクリーンDCを
	* 	もとにLOGFONT構造体を作成します。
	* 	CdFontProp オブジェクトに設定されている高さ属性が
	* 	Logicalunit... で指定されている場合は、このHDCには
	* 	意味がありません。
	*/
	void toLOGFONT( const CdFontProp& aCdFontProp , 
			LOGFONT*	pLOGFONT ,
			HDC hDc = NULL ) ;

	/**
	*	CdFontPropオブジェクトから、 LOGFONT 構造体へ変換します。
	*	引数は、toLOGFONT と同じです
	*
	* @retval 
	* 	作成したLOGFONT構造体を返します。
	*/
	LOGFONT LOGFONTOf( const CdFontProp& aCdFontProp , 
			HDC hDc = NULL ) {
		LOGFONT	aLOGFONT ;
		toLOGFONT( aCdFontProp , &aLOGFONT , hDc ) ;
		return ( aLOGFONT ) ;
	};

	/**
	*	 LOGFONT 構造体の内容を、CdFontPropオブジェクトへ変換します。
	*	ただし、CdFontPropの保有する情報量はLOGFONT構造体よりも少ないため、
	*	変換後のCdFontPropオブジェクトでは、情報が一部失われます。
	* @param aLOGFONT [in]
	* 	LOGFONT構造体を指定してください。
	* @param pCdFontProp [out]
	* 	この関数はこのオブジェクト構造体に、属性を書き込みます。
	*/
	void toCdFontProp( 
			const LOGFONT&	aLOGFONT ,
			CdFontProp* pCdFontProp ) ;

	/**
	*	ストックオブジェクトの属性を、
	*	CdFontPropオブジェクトへ変換します。
	*	ただし、CdFontPropの保有する情報量はLOGFONT構造体よりも少ないため、
	*	変換後のCdFontPropオブジェクトでは、情報が一部失われます。
	* @param fnObject [in]
	* 	GetStockObject() で指定する、ストックフォントオブジェクト
	*	の定数を指定してください。
	* @param pCdFontProp [out]
	* 	この関数はこのオブジェクト構造体に、属性を書き込みます。
	*/
	void toCdFontProp( 
			int fnObject ,
			CdFontProp* pCdFontProp ) ;

	/**
	*	 LOGFONT 構造体の内容を、CdFontPropオブジェクトへ変換します。
	*	引数は、toCdFontProp と同じです
	* @param aLOGFONT [in]
	* 	LOGFONT構造体を指定してください。
	* @return
	* 	 CdFontProp 構造体を返します。
	*/
	CdFontProp CdFontPropOf( 
			const LOGFONT&	aLOGFONT ){
		CdFontProp	rv ;
		toCdFontProp( aLOGFONT , &rv ) ;
		return ( rv ) ;
	};
	/**
	*	 ストックオブジェクトの属性を、
	*	CdFontPropオブジェクトへ変換します。
	*	引数は、toCdFontProp と同じです
	* @param fnObject [in]
	* 	GetStockObject() で指定する、ストックフォントオブジェクト
	*	の定数を指定してください。
	* @return
	* 	 CdFontProp 構造体を返します。
	*/
	CdFontProp CdFontPropOf( 
						int fnObject ){
		CdFontProp	rv ;
		toCdFontProp( fnObject , &rv ) ;
		return ( rv ) ;
	};

	/**
	* 	CdFontPropオブジェクトの属性をもとに、フォントを生成します
	* @param aCdFontProp [in]
	* 	フォント属性を指定してください。
	* @param hDc [in]
	* 	CdFontProp オブジェクトに設定されている高さ属性が
	* 	PointTextHeight で指定されている場合は、LOGFONTに変換
	* 	する際には、その変換には、フォントの描画を行うHDCが必要です。
	* 	ここには、そのHDCを指定してください。
	* 	もし、このケースでHDCの指定を省略した場合は、スクリーンDCを
	* 	もとにLOGFONT構造体を作成します。
	* 	CdFontProp オブジェクトに設定されている高さ属性が
	* 	Logicalunit... で指定されている場合は、このHDCには
	* 	意味がありません。
	* @return
	*	フォントのハンドルを返します。
	*	このハンドルの破棄の責務は、関数呼出元にあります。
	*	関数呼出元は、ハンドルが不要になったら DeleteObject() で
	*	ハンドルを解放しなくてはなりません。
	*/
	HFONT	CreateFont(  const CdFontProp& aCdFontProp , 
			HDC hDc = NULL ) ;

	/**
	* 	CdFontPropオブジェクトの属性とDCをもとに、
	*	指定のテキストを描画した場合の大きさを計算します。
	* @param strTextExtent [in]
	*	この関数は、この文字列を表示できる幅を返します。
	* @param iLinesExtent [in]
	*	この関数は、この行数を表示できる高さを返します。
	* @param aCdDrawTextProp [in]
	* 	フォント属性を指定してください。
	* @param hDc [in]
	* 	CdFontProp オブジェクトに設定されている高さ属性が
	* 	PointTextHeight で指定されている場合は、LOGFONTに変換
	* 	する際には、その変換には、フォントの描画を行うHDCが必要です。
	* 	ここには、そのHDCを指定してください。
	* 	もし、このケースでHDCの指定を省略した場合は、スクリーンDCを
	* 	もとにLOGFONT構造体を作成します。
	* 	CdFontProp オブジェクトに設定されている高さ属性が
	* 	Logicalunit... で指定されている場合は、このHDCには
	* 	意味がありません。
	* @return
	*	フォントのハンドルを返します。
	*	このハンドルの破棄の責務は、関数呼出元にあります。
	*	関数呼出元は、ハンドルが不要になったら DeleteObject() で
	*	ハンドルを解放しなくてはなりません。
	*/
	CdDcdSizeXy	DrawtextCalcrect( 
		const tstring& strExtent ,
		int iLinesExtent ,
		const CdDrawTextProp& aCdDrawTextProp , 
		HDC hDc = NULL ) ;

	///@}
	
	// ********************************
	///	@name Penを扱う関数群
	// ********************************
	
	///@{
	
	/**
	*	CdPenPropオブジェクトの内容を、 LOGPEN 構造体へ変換します。
	*
	* @param aCdPenProp [in]
	* 	ペン属性を指定してください。
	* @param pLOGPEN [out]
	* 	この関数はこの構造体に、属性を書き込みます。
	*/
	void toLOGPEN( const CdPenProp& aCdPenProp , 
			LOGPEN*	pLogPen ) ;

	/**
	*	CdPenPropオブジェクトから、 LOGPEN 構造体へ変換します。
	*	引数は、toLOGPEN と同じです
	*
	* @retval 
	* 	作成したLOGFONT構造体を返します。
	*/
	LOGPEN LOGPENOf( const CdPenProp& aCdPenProp ) {
		LOGPEN	aLOGPEN ;
		toLOGPEN( aCdPenProp , &aLOGPEN ) ;
		return ( aLOGPEN ) ;
	};

	/**
	*	 LOGPEN 構造体の内容を、CdPenPropオブジェクトへ変換します。
	* @param aLOGPEN [in]
	* 	LOGPEN構造体を指定してください。
	* @param pCdPenProp [out]
	* 	この関数はこのオブジェクト構造体に、属性を書き込みます。
	*/
	void toCdPenProp( 
			const LOGPEN&	aLOGPEN ,
			CdPenProp* pCdPenProp ) ;

	/**
	*	ストックオブジェクトの属性を、
	*	CdPenPropオブジェクトへ変換します。
	* @param fnObject [in]
	* 	GetStockObject() で指定する、ストックフォントオブジェクト
	*	の定数を指定してください。
	* @param pCdPenProp [out]
	* 	この関数はこのオブジェクト構造体に、属性を書き込みます。
	*/
	void toCdPenProp( 
			int fnObject ,
			CdPenProp* pCdPenProp ) ;
	
	/**
	*	 LOGPEN 構造体の内容を、CdPenPropオブジェクトへ変換します。
	* @param aLOGPEN [in]
	* 	LOGPEN構造体を指定してください。
	* @return
	* 	 CdPenProp 構造体を返します。
	*/
	CdPenProp CdPenPropOf( 
			const LOGPEN&	aLOGPEN ){
		CdPenProp	rv ;
		toCdPenProp( aLOGPEN , &rv ) ;
		return ( rv ) ;
	};
	/**
	*	ストックオブジェクトの属性を、
	*	CdPenPropオブジェクトへ変換します。
	* @param fnObject [in]
	* 	GetStockObject() で指定する、ストックフォントオブジェクト
	*	の定数を指定してください。
	* @return
	* 	 CdPenProp 構造体を返します。
	*/
	CdPenProp CdPenPropOf( 
						int fnObject ){
		CdPenProp	rv ;
		toCdPenProp( fnObject , &rv ) ;
		return ( rv ) ;
	};

	/**
	* 	CdPenPropオブジェクトの属性をもとに、ペンを生成します
	* @param aCdPenProp [in]
	* 	ペン属性を指定してください。
	* @return
	*	ペンのハンドルを返します。
	*	このハンドルの破棄の責務は、関数呼出元にあります。
	*	関数呼出元は、ハンドルが不要になったら DeleteObject() で
	*	ハンドルを解放しなくてはなりません。
	*/
	HPEN	CreatePen(  const CdPenProp& aCdPenProp ) ;
	
	///@}

	// ********************************
	///	@name Brushを扱う関数群
	// ********************************
	
	///@{
	/**
	*	CdBrushPropオブジェクトの内容を、 LOGBRUSH 構造体へ変換します。
	*
	* @param aCdBrushProp [in]
	* 	ブラシ属性を指定してください。
	* @param pLOGBRUSH [out]
	* 	この関数はこの構造体に、属性を書き込みます。
	*/
	void toLOGBRUSH( const CdBrushProp& aCdBrushProp , 
			LOGBRUSH*	pLogbrush ) ;
	/**
	*	CdBrushPropオブジェクトから、 LOGBRUSH 構造体へ変換します。
	*	引数は、toLOGBRUSH と同じです
	*
	* @retval 
	* 	作成したLOGBRUSH構造体を返します。
	*/
	LOGBRUSH LOGBRUSHOf( const CdBrushProp& aCdBrushProp ) {
		LOGBRUSH	aLOGBRUSH ;
		toLOGBRUSH( aCdBrushProp , &aLOGBRUSH ) ;
		return ( aLOGBRUSH ) ;
	};

	/**
	*	 LOGBRUSH 構造体の内容を、CdBrushPropオブジェクトへ変換します。
	* @param aLOGBRUSH [in]
	* 	LOGBRUSH構造体を指定してください。
	* @param pCdBrushProp [out]
	* 	この関数はこのオブジェクト構造体に、属性を書き込みます。
	*/
	void toCdBrushProp( 
			const LOGBRUSH&	aLOGBRUSH ,
			CdBrushProp* pCdBrushProp ) ;

	/**
	*	ストックオブジェクトの属性を、
	*	CdBrushPropオブジェクトへ変換します。
	* @param fnObject [in]
	* 	GetStockObject() で指定する、ストックフォントオブジェクト
	*	の定数を指定してください。
	* @param pCdBrushProp [out]
	* 	この関数はこのオブジェクト構造体に、属性を書き込みます。
	*/
	void toCdBrushProp( 
			int fnObject ,
			CdBrushProp* pCdBrushProp ) ;
	
	/**
	*	 LOGBRUSH 構造体の内容を、CdBrushPropオブジェクトへ変換します。
	*	引数は、toCdBrushProp と同じです
	* @param aLOGBRUSH [in]
	* 	LOGBRUSH構造体を指定してください。
	* @return
	* 	 CdBrushProp 構造体を返します。
	*/
	CdBrushProp CdBrushPropOf( 
			const LOGBRUSH&	aLOGBRUSH ){
		CdBrushProp	rv ;
		toCdBrushProp( aLOGBRUSH , &rv ) ;
		return ( rv ) ;
	};
	/**
	*	 ストックオブジェクトの属性を
	*	CdBrushPropオブジェクトへ変換します。
	* @param fnObject [in]
	* 	GetStockObject() で指定する、ストックフォントオブジェクト
	*	の定数を指定してください。
	* @return
	* 	 CdBrushProp 構造体を返します。
	*/
	CdBrushProp CdBrushPropOf( 
						int fnObject ){
		CdBrushProp	rv ;
		toCdBrushProp( fnObject , &rv ) ;
		return ( rv ) ;
	};

	/**
	* 	CdBrushPropオブジェクトの属性をもとに、ペンを生成します
	* @param aCdBrushProp [in]
	* 	ペン属性を指定してください。
	* @return
	*	ペンのハンドルを返します。
	*	このハンドルの破棄の責務は、関数呼出元にあります。
	*	関数呼出元は、ハンドルが不要になったら DeleteObject() で
	*	ハンドルを解放しなくてはなりません。
	*/
	HBRUSH	CreateBrush(  const CdBrushProp& aCdBrushProp ) ;
	
	///@}
	// ********************************
	///@name	論理座標とデバイス座標の変換	
	// ********************************
	///@{
	/**
	 *	デバイス座標を論理座標へ変換します
	 * @param value [in] 
	 *	変換前の座標値を指定してください。
	 * @param hdc [in] 
	 *	デバイスコンテキストのハンドルを指定します。 
	 */
	CdDcdPosXy DPtoLP( const CdDcdPosXy& value , HDC hDc ) ;  

	/**
	 *	論理座標をデバイス座標へ変換します
	 * @param value [in] 
	 *	変換前の座標値を指定してください。
	 * @param hdc [in] 
	 *	デバイスコンテキストのハンドルを指定します。 
	 */
	CdDcdPosXy LPtoDP( const CdDcdPosXy& value , HDC hDc ) ;  

	/**
	 *	デバイス座標を論理座標へ変換します
	 * @param value [in] 
	 *	変換前の座標値を指定してください。
	 * @param hdc [in] 
	 *	デバイスコンテキストのハンドルを指定します。 
	 */
	CdDcdSizeXy DPtoLP( const CdDcdSizeXy& value , HDC hDc ) ;  

	/**
	 *	論理座標をデバイス座標へ変換します
	 * @param value [in] 
	 *	変換前の座標値を指定してください。
	 * @param hdc [in] 
	 *	デバイスコンテキストのハンドルを指定します。 
	 */
	CdDcdSizeXy LPtoDP( const CdDcdSizeXy& value , HDC hDc ) ;  


	/**
	 *	デバイス座標を論理座標へ変換します
	 * @param value [in] 
	 *	変換前の座標値を指定してください。
	 * @param hdc [in] 
	 *	デバイスコンテキストのハンドルを指定します。 
	 */
	CdDcdZoneXy DPtoLP( const CdDcdZoneXy& value , HDC hDc ) ;  

	/**
	 *	論理座標をデバイス座標へ変換します
	 * @param value [in] 
	 *	変換前の座標値を指定してください。
	 * @param hdc [in] 
	 *	デバイスコンテキストのハンドルを指定します。 
	 */
	CdDcdZoneXy LPtoDP( const CdDcdZoneXy& value , HDC hDc ) ;  
	///@}
};
// ****************************************************************
//	普通関数
// ****************************************************************
/**
 *	指定のデバイス の HDC の 
 *	GetDeviceCaps() の値のいくつかを記述した
 *	文字列を作成します。
 *	この文字列は可読テキストであり、
 *	デバッグ以外の使い道はありません。
 *
 * @param hDc [in]
 *	対象となるデバイスの HDC を指定してください。
 * @return
 *	文字列を返します。
 *
 *	対象となるデバイスの属性値は、以下のものです。
 *
 *	- TECHNOLOGY
 *	- HORZSIZE
 *	- VERTSIZE
 *	- HORZRES
 *	- VERTRES
 *	- LOGPIXELSX
 *	- LOGPIXELSY
 *	- PHYSICALWIDTH
 *	- PHYSICALHEIGHT
 *	- PHYSICALOFFSETX
 *	- PHYSICALOFFSETY
 */	
std::string	DeviceCapsToString( HDC hDc ) ;


#define  CConverter_WinGdi_h
#endif /*CConverter_WinGdi_h*/


