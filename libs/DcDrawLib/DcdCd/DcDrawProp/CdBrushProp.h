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
//	CdBrushProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdBrushProp_h
#define  CdBrushProp_h
#include "CdColorProp.h"

namespace DcDrawLib{
namespace DcdCd{
namespace DcDrawProp{

// ****************************************************************
//	CdBrushProp
// ****************************************************************
/**
* @brief
* 【概要】
*  ブラシの属性を保持する単純データクラスです。

*	   CConverter_WinGdi クラスを使用すると、LOGBRUSH構造体との間で相互変換
*	したり、ブラシハンドルを生成したりできます。
*/
class CdBrushProp
{
// ********************************
///@name	インナータイプ
// ********************************
///@{
 public:
	enum EStyle
	{
		/** 純色のブラシ。 	*/
		SOLID ,

		/** 左下から右上への 45 度のハッチ */
		HATCHED_BDIAGONAL ,
		
		/** 水平、垂直の格子状のハッチ	*/
		HATCHED_CROSS ,

		/** 45 度の格子状のハッチ	*/
		HATCHED_DIAGCROSS ,

		/** 左上から右下への 45 度のハッチ	*/
		HATCHED_FDIAGONAL ,

		/** 水平のハッチ	*/
		HATCHED_HORIZONTAL ,

		/** 垂直のハッチ	*/
		HATCHED_VERTICAL ,

		/** 中空のブラシ。なにも描画しません。	*/
		NULLBRUSH ,
	};
///@}
// ********************************
///@name	属性
// ********************************
///@{
 private:
	/**
	*	ブラシの色です。
	*	デフォルトは黒です。
	*/
	CdColorProp m_colorrefColor;
	
	/**	
	*	形状。デフォルトは、NULLBRUSH です。
	*/
	EStyle	m_eStyle	;
	
///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	*	ブラシの色と形状を指定します。
	* @param colorrefColor
	*	ブラシの色です
	* @param eStyle	
	*	形状。デフォルトは、SOLID です。
	*/
	CdBrushProp( CdColorProp colorrefColor , 
				EStyle	eStyle = SOLID ) 
		: m_colorrefColor( colorrefColor ) 
		, m_eStyle( eStyle ){} ;
	
	CdBrushProp() : 
		m_colorrefColor( CdColorProp( 0 , 0 , 0 ) ) ,
		m_eStyle( NULLBRUSH ) {};
	

// ********************************
//	CdBrushProp
// ********************************
 public:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	CdColorProp getColor()const{	return m_colorrefColor ; } ;
	CdBrushProp& setColor( CdColorProp ev ){
		m_colorrefColor = ev ;	return *this ; } ;
	
	EStyle getStyle()const{	return m_eStyle ; } ;
	CdBrushProp& setStyle( EStyle ev ){
		m_eStyle = ev ;	return *this ; } ;

	/**
	 *	2つのオブジェクトの各属性が等しいかどうかを判定します。
	 * @param value [in]
	 *	比較の対象となるオブジェクトを指定してください。
	 * @return 
	 *	value と *this との間で、すべての属性が等しければ真です。
	 */
	bool isEqualTo( const CdBrushProp& value )const{
		return ( 
			m_colorrefColor == value.m_colorrefColor && 
			m_eStyle == value.m_eStyle );
	};
	/**
	 *	isEqualTo() と等価です。
	 */
	bool operator==( const CdBrushProp& value )const{
		return ( isEqualTo( value ) ) ;
	};	
	bool operator!=( const CdBrushProp& value )const{
		return ( !isEqualTo( value ) ) ;
	};	
	///@}
	/**
	 *	this が b より
	 *	小さい（順序が前になる）なら真です。
	 * @param b [in]
	 *	比較の対象となるオブジェクトを指定してください。
	 * @return 
	 *	this が b より
	 *	小さい（順序が前になる）なら真です。
	 */
	bool  less( const CdBrushProp& value )const{
		if ( m_colorrefColor != value.m_colorrefColor ){
			return ( m_colorrefColor < value.m_colorrefColor ) ; 
		}	else if ( m_eStyle != value.m_eStyle ){
			return ( m_eStyle < value.m_eStyle );
		}
		return ( false ) ;
	};
	/**
	 *	less() と等価です。
	 */
	bool operator<( const CdBrushProp& b )const{
		return less( b );
	};
	

};

} //namespace DcDrawProp
} //namespace DcdCd
} //namespace DcDrawLib

#endif /*CdBrushProp_h*/
