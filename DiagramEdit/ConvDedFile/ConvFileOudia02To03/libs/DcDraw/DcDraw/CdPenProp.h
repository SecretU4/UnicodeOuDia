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
//	CdPenProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdPenProp_h
#define  CdPenProp_h
#include <windows.h>

// ****************************************************************
//	CdPenProp
// ****************************************************************
/**
 * @brief
 * 【概要】
 *	   ペンの属性を保持する単純データクラスです。
 *
 *	   CConverter_WinGdi クラスを使用すると、LOGPEN構造体との間で相互変換
 *	ができます。
 */
class CdPenProp
{
// ********************************
///@name インナータイプ
// ********************************
///@{
 public:
	enum EStyle
	{
		/**	
		 *	実線のペン	
		 */
		SOLID ,	
		/** 
		 *	破線のペン。
		 *	この属性が指定されると、ペンの幅は論理単位で１に限定され、
		 *	m_iWidth は無効になります
		 */
		DASH ,
		/**
		 *	 点線のペン。
		 *	この属性が指定されると、ペンの幅は論理単位で１に限定され、
		 *	m_iWidth は無効になります
		 */
		DOT ,
		/** 
		 *	一点鎖線のペン。
		 *	この属性が指定されると、ペンの幅は論理単位で１に限定され、
		 *	m_iWidth は無効になります
		 */
		DASHDOT ,
		/** 
		 *	二点鎖線のペン。
		 *	この属性が指定されると、ペンの幅は論理単位で１に限定され、
		 *	m_iWidth は無効になります
		 */
		DASHDOTDOT ,
		/**
		 *	 ヌルのペン。
		 *	何も描画しません
		 */
		NULLPEN ,
		/**	
		 *	外接する境界四角形を指定する GDI 関数 (Ellipse、Rectangle、
		 *	RoundRect、Pie、Chord メンバ関数など) により作成される閉じた図形の
		 *	枠内に直線を描画するためのペン。形状は実線です	
		 */
		SOLID_INSIDEFRAME ,	
	};
///@}
// ********************************
///@name	属性
// ********************************
///@{
 private:
	/** 
	 *	この属性が真なら、ペンの太さはデバイス単位で無条件に１になります 
	 *
	 *	デフォルトでは偽です
	 */
	bool		m_bIsDevicewidth1 ;
	
	/** 
	 *	論理単位で太さを表す属性です 。
	 *
	 *	m_bIsDevicewidth1 が真の場合、この値は強制的に０となります。
	 *	\n m_bIsDevicewidth1 が偽で、m_eStyle が SOLID か SOLID_INSIDEFRAME の
	 *	どちらでもない場合は、この値は強制的に１となります。
	 *	\n m_bIsDevicewidth1 が偽で、m_eStyle が SOLID か SOLID_INSIDEFRAME の
	 *	場合には、この値は１以上の任意の値になります。
	 *
	 *	デフォルトでは1です。
	 */
	int			m_iLogicalunitWidth ;
	
	/**
	 *	ペンの色です。
	 *
	 *	デフォルトは黒です
	 */
	COLORREF	m_colorrefColor ;

	/**	
	 *	形状。
	 *
	 *	デフォルトは NULLPEN です。
	 */
	EStyle	m_eStyle	;
///@}	
// ********************************
//	コンストラクタ
// ********************************
 public:
	/** 
	 *	太さを論理単位で指定するペンを指定します。
	 * @param iLogicalunitWidth [in]
	 *	論理単位で太さを表す属性です 
	 *	m_bIsDevicewidth1 が真の場合、この値は強制的に０となります。
	 *	m_bIsDevicewidth1 が偽で、m_eStyle が SOLID か SOLID_INSIDEFRAME の
	 *	どちらでもない場合は、この値は強制的に１となります。
	 *	m_bIsDevicewidth1 が偽で、m_eStyle が SOLID か SOLID_INSIDEFRAME の
	 *	場合には、この値は１以上の任意の値になります。
	 * @param aColorref [in]
	 *	ペンの色です
	 * @param eStyle [in]
	 *	ペンの形状を指定してください。
	 */
	CdPenProp( int iLogicalunitWidth , 
				COLORREF aColorref = RGB( 0 , 0 , 0 ) , 
				EStyle eStyle = SOLID ) :
		m_bIsDevicewidth1( false ) ,
		m_iLogicalunitWidth( iLogicalunitWidth ) , 
		m_colorrefColor( aColorref ) ,
		m_eStyle( eStyle ) 
		{};
	
	/** 
	 *	デフォルトコンストラクタ。NULLPEN に初期化されます。
	 *		- 実線
	 *		- 太さは論理単位で１
	 *		- 色は黒
	 *
	 *	を定義します。
	 */
	CdPenProp() : 
		m_bIsDevicewidth1( false ) ,
		m_iLogicalunitWidth( 1 ) , 
		m_colorrefColor( RGB( 0 , 0 , 0 ) ) ,
		m_eStyle( NULLPEN ) 
		{};
	
	
// ********************************
//	CdPenProp
// ********************************
 public:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	bool isDevicewidth1()const{	return m_bIsDevicewidth1 ; } ;
	CdPenProp& setIsDevicewidth1( bool ev ){
		m_bIsDevicewidth1 = ev ; return *this ;} ;
	
	/** 
	 *	太さを返します。
	 * @return
	 *	- 無条件にデバイス単位１であれば、０
	 *	- NULLPEN なら、０
	 *	- 実線でない場合は、１
	 *	- そうでない場合は、論理単位での太さ
	 */
	int getLogicalunitWidth()const{
		if ( m_bIsDevicewidth1 ){	return ( 0 ) ; } ;

		if ( m_eStyle == NULLPEN ){
			return ( 0 ) ; 
		}
		if ( !( m_eStyle == SOLID || m_eStyle == SOLID_INSIDEFRAME ) ){
			return ( 1 ) ; 
		}

		if ( m_iLogicalunitWidth < 1 ){
			return ( 1 ) ;
		}
		return ( m_iLogicalunitWidth ) ;
	};
	/** 
	 *	太さを論理単位で設定します。
	 *	ただし、 m_eStyle が SOLID , または SOLID_INSIDEFRAME 以外の
	 *	場合、または m_bIsDevicewidth1 が真の場合は、
	 *	このメンバ関数で指定した値は効果をもちません。
	 */
	CdPenProp& setLogicalunitWidth( int ev ){
		m_iLogicalunitWidth = ev ;
		return *this ;
	};
	
	COLORREF getColor()const{	return m_colorrefColor ; } ;
	CdPenProp& setColor( COLORREF ev ){
		m_colorrefColor = ev ;	return *this ; } ;
	
	EStyle getStyle()const{	return m_eStyle ; } ;
	CdPenProp& setStyle( EStyle ev ){
		m_eStyle = ev ;	return *this ; } ;
	
	/**
	 *	2つのオブジェクトの各属性が等しいかどうかを判定します。
	 * @param value [in]
	 *	比較の対象となるオブジェクトを指定してください。
	 * @return 
	 *	value と *this との間で、すべての属性が等しければ真です。
	 */
	bool isEqualTo( const CdPenProp& value )const{
		return ( 
			m_bIsDevicewidth1 == value.m_bIsDevicewidth1 &&
			m_iLogicalunitWidth == value.m_iLogicalunitWidth &&
			m_colorrefColor == value.m_colorrefColor &&
			m_eStyle == value.m_eStyle )	;
	};
	/**
	 *	isEqualTo() と等価です。
	 */
	bool operator==( const CdPenProp& value )const{
		return ( isEqualTo( value ) ) ;
	};
	bool operator!=( const CdPenProp& value )const{
		return ( !isEqualTo( value ) ) ;
	};

	/**
	 *	this が b より
	 *	小さい（順序が前になる）なら真です。
	 * @param b [in]
	 *	比較の対象となるオブジェクトを指定してください。
	 * @return 
	 *	this が b より
	 *	小さい（順序が前になる）なら真です。
	 */
	bool  less( const CdPenProp& value)const{
		if ( m_bIsDevicewidth1 != value.m_bIsDevicewidth1 ){
			return ( m_bIsDevicewidth1 < value.m_bIsDevicewidth1 ) ;
		}	else if ( m_iLogicalunitWidth != value.m_iLogicalunitWidth ){
			return ( m_iLogicalunitWidth < value.m_iLogicalunitWidth ) ;
		}	else if ( m_colorrefColor != value.m_colorrefColor ){
			return ( m_colorrefColor < value.m_colorrefColor ) ;
		}	else if ( m_eStyle != value.m_eStyle ){
			return ( m_eStyle < value.m_eStyle ) ;
		}
		return ( false ) ;
	};
	/**
	 *	less() と等価です。
	 */
	bool operator<( const CdPenProp& b )const{
		return less( b );
	};
	///@}
	
};

#endif /*CdPenProp_h*/
