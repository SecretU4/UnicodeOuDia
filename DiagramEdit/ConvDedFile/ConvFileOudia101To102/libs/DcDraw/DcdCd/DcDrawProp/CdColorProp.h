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
//	CdColorProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdColorProp_h
#define  CdColorProp_h

#include "DcdCd\Pos\DcdType.h"

// ****************************************************************
//	CdColorProp
// ****************************************************************
/**
 @brief
 【概要】
	色の属性を保持する単純データクラスです。

	CConverter_WinGdi クラスを使用すると、COLORREF構造体との間で相互変換
	を行うことができます。
*/
class CdColorProp
{
// ********************************
///@name	属性
// ********************************
///@{
 private:
	/**
	*	色の赤の要素です。
	*/
	unsigned char m_iRed ;
	
	/**
	*	色の緑の要素です。
	*/
	unsigned char m_iGreen ;
	
	/**
	*	色の青の要素です。
	*/
	unsigned char m_iBlue ;
	
///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	CdColorProp( 
		unsigned char iRed ,
		unsigned char iGreen ,
		unsigned char iBlue ) 
		: m_iRed( iRed ) 
		, m_iGreen( iGreen ) 
		, m_iBlue( iBlue )
	{};
	
	CdColorProp() 
		: m_iRed( 0 ) 
		, m_iGreen( 0 ) 
		, m_iBlue( 0 )
	{};

// ********************************
//	CdColorProp
// ********************************
public:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	unsigned char getRed()const{	return m_iRed ;};
	CdColorProp& setRed( unsigned char value ){	m_iRed = value ; return *this ;};
	unsigned char getGreen()const{	return m_iGreen ;};
	CdColorProp& setGreen( unsigned char value ){	m_iGreen = value ; return *this ;};
	unsigned char getBlue()const{	return m_iBlue ;};
	CdColorProp& setBlue( unsigned char value ){	m_iBlue = value ; return *this ;};
	///@}


	/**
	 *	2つのオブジェクトの各属性が等しいかどうかを判定します。
	 * @param value [in]
	 *	比較の対象となるオブジェクトを指定してください。
	 * @return 
	 *	value と *this との間で、すべての属性が等しければ真です。
	 */
	bool isEqualTo( const CdColorProp& value )const
	{
		return ( 
			m_iRed == value.m_iRed &&  
			m_iGreen == value.m_iGreen &&  
			m_iBlue == value.m_iBlue );
	};
	/**
	 *	isEqualTo() と等価です。
	 */
	bool operator==( const CdColorProp& value )const
	{	return ( isEqualTo( value ) ) ;	};	
	bool operator!=( const CdColorProp& value )const
	{	return ( !isEqualTo( value ) ) ;};	
	/**
	 *	this が b より
	 *	小さい（順序が前になる）なら真です。
	 * @param b [in]
	 *	比較の対象となるオブジェクトを指定してください。
	 * @return 
	 *	this が b より
	 *	小さい（順序が前になる）なら真です。
	 */
	bool  less( const CdColorProp& value )const
	{
		if ( m_iRed != value.m_iRed )
		{
			return ( m_iRed < value.m_iRed ) ;
		}
		else if ( m_iGreen != value.m_iGreen )
		{
			return ( m_iGreen < value.m_iGreen ) ;
		}
		else if ( m_iBlue != value.m_iBlue )
		{
			return ( m_iBlue < value.m_iBlue ) ;
		}
		return ( false ) ;
	};
	/**
	 *	less() と等価です。
	 */
	bool operator<( const CdColorProp& b )const
	{	return less( b );	};
	

};

#endif //CdColorProp_h
