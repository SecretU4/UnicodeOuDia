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
//	./CdDeviceUnitSize.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDeviceUnitSize_h
#define  CdDeviceUnitSize_h

#include <windows.h>

#include "DcdCd\Pos\DcdType.h"

// ****************************************************************
//	CdDeviceUnitSize
// ****************************************************************
/**
 * @brief
 * 【概要】
 * 	デバイス単位（ピクセル数）でのサイズを保持します。
 *
 *	このクラスは、DPI（インチ当たりのピクセル数）の値をもとに、
 *
 *		デバイス単位－物理単位
 *
 *	の変換を行います。
 *	  物理単位は、以下のものをサポートします。
 *
 *	- ポイント(1インチ=72ポイント)
 *	- Twip(１インチ=72*20 Twip)
 *	- 1/1000 インチ
 *	- インチ（実数）
 *	- μm(1/1000 mm)(１インチ＝25.4mm)
 *	- ｍｍ（実数）(１インチ＝25.4mm)
 *	
 *	派生クラスとなる CdDeviceUnitSizeX ・ CdDeviceUnitSizeY では、
 *	デバイス単位－論理単位 の変換もできるようになります。@n
 *	物理単位－論理単位の変換は、
 *
 *		物理単位－デバイス単位－論理単位
 *		
 *	のように、一旦デバイス単位を経由すれば可能です。
 *
 * 【使い方】
 *
 * １．  コンストラクタでは、DPIを指定してください。
 *
 * ２．  これ以後は、単純データクラスと同様の使い方ができます。
 *
 *	通常は、派生クラスとなる CdDeviceUnitSizeX ・ CdDeviceUnitSizeY を
 *	使います。
 */
class CdDeviceUnitSize
{
// ********************************
/// @name 属性
// ********************************
///@{
 private:
	/**
	 *	DPI の値（１インチあたりのピクセル数）です。
	 *
	 *	これは通常、DCをもとに
	 *	( GetDeviceCaps(LOGPIXELSX) , GetDeviceCaps(LOGPIXELSY) )
	 *	決定します。
	 *	コンストラクタで決まります。
	 * @attention
	 *	この値を 0 にしていると、当然ゼロ割り算になります。
	 */
	int m_iDpi ;

	/**
	 * 	デバイス単位でのサイズです。
	 */
	DcdSize	m_sizeDeviceUnitSize ;
///@}
	
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param iDpi [in]
	 *	DPI の値です。@n
	 *	これは通常、DCをもとに
	 *	( GetDeviceCaps(LOGPIXELSX) , GetDeviceCaps(LOGPIXELSY) )
	 *	決定します。
	 * @param sizeDeviceUnitSize [in]
	 * 	デバイス単位でのサイズです。
	 */
	CdDeviceUnitSize( 
		int iDpi ,
		DcdSize	sizeDeviceUnitSize = 0 ) :
		m_iDpi( iDpi ) ,
		m_sizeDeviceUnitSize( sizeDeviceUnitSize ){};
	
	virtual ~CdDeviceUnitSize(){};

// ********************************
//	CdDeviceUnitSize
// ********************************
 public:
	
	// ********************************
	///@name CdDeviceUnitSize-属性
	// ********************************
	///@{
	int getDpi()const{	return m_iDpi ;};
	CdDeviceUnitSize& setDpi( int value ){	m_iDpi = value ; return *this ; } ;
	DcdSize	getDeviceUnitSize()const{	return m_sizeDeviceUnitSize ;	} ;
	CdDeviceUnitSize& setDeviceUnitSize( DcdSize value ){
		m_sizeDeviceUnitSize = value ;	return *this ;	} ;
	
	/** setDeviceUnitSize() と等価です */
	CdDeviceUnitSize& operator=( DcdSize value ){
		return setDeviceUnitSize( value ) ; } ;
	/** getDeviceUnitSize() と等価です */
	operator DcdSize()const{	return getDeviceUnitSize() ; } ;
	///@}

	// ********************************
	///@name CdDeviceUnitSize-操作
	// ********************************
	///@{
	/**
	 * @return
	 * 	ポイント単位で、サイズを取得します
	 */
	DcdSize	getPointSize()const{
		return MulDiv( m_sizeDeviceUnitSize , 72 , m_iDpi ) ;
	};
	/**
	 * 	ポイント単位で、サイズを設定します
	 * @param value [in]
	 *	ポイント単位でのサイズを指定してください。
	 */
	CdDeviceUnitSize& setPointSize( DcdSize	value ){
		m_sizeDeviceUnitSize = MulDiv( value , m_iDpi ,72 ) ;	
		return *this ; } ;
	
	
	/**
	 * @return
	 * 	Twip単位で、サイズを取得します
	 */
	DcdSize	getTwipSize()const{
		return MulDiv( m_sizeDeviceUnitSize , 72*20 , m_iDpi ) ;
	};
	/**
	 * 	Twip 単位で、サイズを設定します
	 * @param ev [in]
	 *	Twip単位でのサイズを指定してください。
	 */
	CdDeviceUnitSize& setTwipSize( DcdSize	value ){
		m_sizeDeviceUnitSize = MulDiv( value , m_iDpi , 72*20 ) ;
		return *this ; } ;
	
	/**
	 * @return
	 * 	1/1000 インチ単位で、サイズを取得します
	 */
	DcdSize	getMilliInchSize()const{
		return MulDiv( m_sizeDeviceUnitSize , 1000 , m_iDpi ) ;
	};
	/**
	 * 	1/1000 インチ 単位で、サイズを設定します
	 * @param ev [in]
	 *	1/1000 インチ単位でのサイズを指定してください。
	 */
	CdDeviceUnitSize& setMilliInchSize( DcdSize	value ){
		m_sizeDeviceUnitSize = MulDiv( value , m_iDpi , 1000 ) ;
		return *this ; } ;
	
	
	/**
	 * @return
	 * 	μｍ単位で、サイズを取得します
	 */
	DcdSize	getMicroMetersSize()const{
		return MulDiv( m_sizeDeviceUnitSize , 25400 , m_iDpi ) ;
	};
	/**
	 * 	μｍ 単位で、サイズを設定します
	 * @param ev [in]
	 *	μｍ 単位でのサイズを指定してください。
	 */
	CdDeviceUnitSize& setMicroMetersSize( DcdSize	value ){
		m_sizeDeviceUnitSize = MulDiv( value , m_iDpi , 25400 ) ;
		return *this ; } ;
	
	/**
	 * @return
	 * 	インチ単位（実数）で、サイズを取得します
	 */
	double	getInchSize()const{
		return (double)m_sizeDeviceUnitSize * 1 / m_iDpi ;
	};
	/**
	 * 	インチ 単位(実数)で、サイズを設定します
	 * @param ev [in]
	 *	インチ単位でのサイズを指定してください。
	 */
	CdDeviceUnitSize& setInchSize( double value ){
		m_sizeDeviceUnitSize = (DcdSize)( value * m_iDpi / 1 ) ;
		return *this ; } ;
	
	
	/**
	 * @return
	 * 	ｍｍ単位（実数）で、サイズを取得します
	 */
	double	getMmSize()const{
		return (double)m_sizeDeviceUnitSize * 25.4 / m_iDpi ;
	};
	/**
	 * 	ｍｍ 単位（実数）で、サイズを設定します
	 * @param ev [in]
	 *	ｍｍ 単位でのサイズを指定してください。
	 */
	CdDeviceUnitSize& setMmSize( double	value ){
		m_sizeDeviceUnitSize = (DcdSize)( value * m_iDpi / 25.4 ) ;
		return *this ; } ;
	
	
	///@}
};

#endif /*CdDeviceUnitSize_h*/
