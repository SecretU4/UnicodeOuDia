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
//****************************************************************
//	CdDrawTextProp.h
//****************************************************************
*/
/** @file */
#ifndef  CdDrawTextProp_h
#define  CdDrawTextProp_h
#include "DcdCd\DcDrawProp\CdColorProp.h"
#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcDraw\CdDrawTextFormat.h"

//****************************************************************
//	CdDrawTextProp
//****************************************************************
/**
 * @brief
 * 【概要】
 * 	テキストを描画する際の属性を保持する、単純データクラスです。
 * 
 */
class CdDrawTextProp
{
// ********************************
/// @name	属性
// ********************************
///@{
 private:
	/** 
	 *	フォント属性 
	 *	デフォルトでは、無効値となります。設定必須の属性です。
	 */
	CdFontProp	m_CdFontProp ;

	/**	
	 *	テキストを描画する場合の文字色です。
	 *	デフォルトは黒です。
	 */
	CdColorProp	m_colorrefText ;
	
	/**
	 * 	テキストの背景を塗るか否かを示します
	 * 	真なら背景を塗ります。
	 *
	 *	デフォルトは偽です。
	 */
	bool		m_bIsOpaque ;

	/**
	 * 	テキストを描画する場合の、背景色です。
	 * 	m_bIsOpaque が真の場合にだけ、有効です。
	 */
	CdColorProp	m_colorrefBack ;
	
	/**
	 *	テキスト描画時の属性を表すフラグ
	 */
	CdDrawTextFormat	m_CdDrawTextFormat ;
///@}
	
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * 	テキストの背景色つきで、属性を設定するコンストラクタです。
	 * @param aCdFontProp [in]
	 * フォント属性 
	 * @param colorrefText [in]
	 *	テキストを描画する場合の文字色です。
	 * @param colorrefBack [in]
	 * 	テキストを描画する場合の、背景色です。
	 * @param aCdDrawTextFormat [in]
	 *	テキスト描画時の属性を表すフラグ
	 */
	CdDrawTextProp( 
			const CdFontProp& aCdFontProp ,
			CdColorProp	colorrefText ,
			CdColorProp	colorrefBack ,
			CdDrawTextFormat	aCdDrawTextFormat = CdDrawTextFormat() ) :
		m_CdFontProp( aCdFontProp ) ,
		m_colorrefText( colorrefText ) ,
		m_bIsOpaque( true ) ,
		m_colorrefBack( m_colorrefBack ) ,
		m_CdDrawTextFormat( aCdDrawTextFormat ) {};

	/**
	 * 	テキストの背景色なし（透明）の、属性を設定するコンストラクタです。
	 * @param aCdFontProp [in]
	 * フォント属性 
	 * @param colorrefText [in]
	 *	テキストを描画する場合の文字色です。
	 * @param aCdDrawTextFormat [in]
	 *	テキスト描画時の属性を表すフラグ
	 */
	CdDrawTextProp( 
			const CdFontProp& aCdFontProp ,
			CdColorProp	colorrefText = CdColorProp( 0 , 0 , 0 ) ,
			CdDrawTextFormat	aCdDrawTextFormat = CdDrawTextFormat() ) :
		m_CdFontProp( aCdFontProp ) ,
		m_colorrefText( colorrefText ) ,
		m_bIsOpaque( false ) ,
		m_colorrefBack( CdColorProp( 255 , 255 , 255 ) ) ,
		m_CdDrawTextFormat( aCdDrawTextFormat ) {};

	/**
	 *	デフォルトコンストラクタです。
	 * 	テキストの背景色なし（透明）です。
	 */
	CdDrawTextProp() :
		m_colorrefText( CdColorProp( 0 , 0 , 0 ) ) ,
		m_bIsOpaque( false ) ,
		m_colorrefBack( CdColorProp( 255 , 255 , 255 ) ) {};


// ********************************
//	CdDrawTextProp
// ********************************
 public:
	// ********************************
	/// @name	属性
	// ********************************
	///@{
	CdFontProp	getCdFontProp()const{
		return 	m_CdFontProp ;	};
	CdDrawTextProp& setCdFontProp( const CdFontProp& ev ){
		m_CdFontProp = ev ;	return *this ; };

	CdColorProp	getTextColor()const{	
		return m_colorrefText ;	};
	CdDrawTextProp& setTextColor( CdColorProp ev ){
		m_colorrefText = ev	; return *this ; } ;
	
	bool		getIsOpaque()const{
		return 	m_bIsOpaque ;	};
	CdDrawTextProp& setIsOpaque( bool ev ){
		m_bIsOpaque = ev ;	return *this ; } ;

	CdColorProp	getBackColor()const{
		return m_colorrefBack ;	};
	CdDrawTextProp& setBackColor( CdColorProp	ev ){
		m_colorrefBack = ev ;	
		m_bIsOpaque = false ;
		return *this ; } ;
	
	CdDrawTextFormat	getCdDrawTextFormat()const{
		return m_CdDrawTextFormat ;	};
	CdDrawTextProp& setCdDrawTextFormat( const CdDrawTextFormat& ev ){
		m_CdDrawTextFormat = ev ;	return *this ; } ;
	///@}
};


#endif /*CdDrawTextProp_h*/
