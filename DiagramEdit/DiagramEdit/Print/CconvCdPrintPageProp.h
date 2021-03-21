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
//	CconvCdPrintPageProp.h
// ****************************************************************
*/
/** @file */

#ifndef  CconvCdPrintPageProp_h
#define  CconvCdPrintPageProp_h

#include "DcdCd\Pos\CdDcdZoneXy.h"

#include "CdPrintPageProp.h"
#include <windows.h>

namespace Print{
	using namespace DcDrawLib::DcdCd::Pos;
	using namespace DcDrawLib::DcDraw;

// ****************************************************************
//	CconvCdPrintPageProp
// ****************************************************************
/**
 *	@brief
 *	CdPrintPageProp オブジェクトの属性を、他の形式に変換する動作を提供します。
 */
class CconvCdPrintPageProp
{
 public:
	/**
	 *	CdPrintPageProp の現在の余白
	 *	(m_dMarginLeftMm ,  m_dMarginTopMm , 
	 *	m_dMarginRightMm , m_dMarginBottomMm )の属性をもとに、
	 *	プリンタの物理座標から余白を除いた座標領域を求めます。
	 *
	 * @param aCdPrintPageProp [in]
	 *	余白の設定を保持している CdPrintPageProp オブジェクトを
	 *	指定してください。
	 * @param hDc [in]
	 *	プリンタのDCを指定してください。
	 * @return 
	 *	プリンタのデバイス座標から、余白を除いた座標領域
	 *	を返します。
	 *
	 *	X方向の余白が大きすぎる場合	(m_dMarginLeftMm +m_dMarginRightMm が
	 *	プリンタの横方向の用紙の大きさを上回る場合）は、
	 *	戻り値の CdDcdZone::getX().getSize() の値が負の数になります。
	 *	この場合は、何らかのエラー処理をすべきです。
	 *
	 *	同様に、Y方向の余白が大きすぎる場合は、
	 *	戻り値の CdDcdZone::getY().getSize() の値が負の数になります。
	 *
	 *	左方向の余白が、プリンタの左側の印字不可能領域の幅より小さい場合は、
	 *	実際の余白は印字不可能領域の幅となります。この動作は、右・上・下
	 *	の余白にもあてはまります。
	 */
	CdDcdZoneXy calcZoneInnerMargin( 
		const CdPrintPageProp& aCdPrintPageProp , HDC hDc ) ;
	
	
	/**
	 *	プリンタDC での、
	 *	X方向の各サイズを、デバイス単位で取得します。
	 *	Win32 の GetDeviceCaps() のラッパーであるといえます。
	 * @param hDc [in]
	 *	プリンタのDCを指定してください。
	 * @param piPhysicalPageSize [out]
	 *	この関数は、
	 *	両端の印字不可能領域を含めた、
	 *	物理的なページ（プリンタの用紙）の大きさ
	 *	を、このアドレスに書き込みます。不要であれば NULL を指定しても
	 *	かまいません。
	 * @param piPhysicalOffset1 [out]
	 *	この関数は、
	 *	座標の小さい側（左側）の印字不可能領域の大きさ
	 *	を、このアドレスに書き込みます。不要であれば NULL を指定しても
	 *	かまいません。
	 * @param piRes [out]
	 *	この関数は、
	 *	印字可能領域の大きさ
	 *	を、このアドレスに書き込みます。不要であれば NULL を指定しても
	 *	かまいません。
	 * @param piPhysicalOffset2 [out]
	 *	この関数は、
	 *	座標の大きい側（右側）の印字不可能領域の大きさ
	 *	を、このアドレスに書き込みます。不要であれば NULL を指定しても
	 *	かまいません。
	 */
	static void getPhysicalXPageSize( HDC hDc , 
		int* piPhysicalPageSize ,
		int* piPhysicalOffset1 ,
		int* piRes ,
		int* piPhysicalOffset2 ) ;

	/**
	 *	プリンタDC での、
	 *	Y方向の各サイズを、デバイス単位で取得します。
	 *	Win32 の GetDeviceCaps() のラッパーであるといえます。
	 * @param hDc [in]
	 *	プリンタのDCを指定してください。
	 * @param piPhysicalPageSize [out]
	 *	この関数は、
	 *	両端の印字不可能領域を含めた、
	 *	物理的なページ（プリンタの用紙）の大きさ
	 *	を、このアドレスに書き込みます。不要であれば NULL を指定しても
	 *	かまいません。
	 * @param piPhysicalOffset1 [out]
	 *	この関数は、
	 *	座標の小さい側（上側）の印字不可能領域の大きさ
	 *	を、このアドレスに書き込みます。不要であれば NULL を指定しても
	 *	かまいません。
	 * @param piRes [out]
	 *	この関数は、
	 *	印字可能領域の大きさ
	 *	を、このアドレスに書き込みます。不要であれば NULL を指定しても
	 *	かまいません。
	 * @param piPhysicalOffset2 [out]
	 *	この関数は、
	 *	座標の大きい側（下側）の印字不可能領域の大きさ
	 *	を、このアドレスに書き込みます。不要であれば NULL を指定しても
	 *	かまいません。
	 */
	static void getPhysicalYPageSize( HDC hDc , 
		int* piPhysicalPageSize ,
		int* piPhysicalOffset1 ,
		int* piRes ,
		int* piPhysicalOffset2 ) ;
};

} //namespace Print

#endif /*CconvCdPrintPageProp_h*/
