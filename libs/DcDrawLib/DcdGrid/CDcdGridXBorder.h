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
/** @file CDcdGridXBorder.h */
//$Id: CDcdGridXBorder.h 296 2016-06-11 05:40:21Z okm $
//////////////////////////////////////////////////////////////////////

#ifndef CDcdGridXBorder_h
#define CDcdGridXBorder_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DcDraw/IfDcDraw.h"
#include "NsOu/Ou.h"


namespace DcDrawLib{
namespace DcdGrid{
	using namespace OuLib::NsOu;
	using namespace DcDraw;

// ****************************************************************
//	CDcdGridXBorder
// ****************************************************************
/**
@brief
【概要】
	DcdGrid のX列の間の罫線(縦罫線)のオブジェクトです。
	IfDcDraw オブジェクトと関連を持ち､ その IfDcDraw オブジェクトを使って
	DcdGridのX列の境界線を描画します。

	CDcdGrid は、通常は CDcdLine オブジェクトを生成して、
	this と関連する IfDcDraw オブジェクトとして登録します｡

*/
class CDcdGridXBorder  
{
private:
	// ********************************
	/// @name 	CDcdGrid に関係する属性/関連
	// ********************************
	///@{

	/**
		this に対する現在の描画オブジェクトを指すポインタです。
	
		このオブジェクトの破棄の責務はクラスユーザーにあります。
		このオブジェクトは、この関連が有効な間は、
		生存していなくてはなりません。
	
		通常は、 CDcdGrid::OnCreateXColumn() がインスタンスを生成・登録し、
		 CDcdGrid::OnDeleteXColumn() がインスタンスを登録解除・破棄します。
		
		デフォルトの  CDcdGrid::OnCreateXColumn() の実装は、
		CDcdLine インスタンスを生成・登録します。
		このときの属性は、太さ１の黒の実線
		となります。
	 */
	Ou<IfDcDraw>			m_pIfDcDraw ;
	/**
		論理サイズで、列の外側（右/下）の境界のサイズを保持します。
		ただし、 m_bAutoColumnBorderSize が真なら、この値は無効です。
		デフォルトでは１です。
	 */
	DcdSize	m_iColumnBorderSize ;
	
	/**
		- true ;	m_pIfDcDraw の getItemSize() が返す @n
			サイズをもとに、列の外側（右/下）の境界のサイズを決定します。
	*/
	bool	m_bAutoColumnBorderSize ;

	///@}	

	// ********************************
	//	コンストラクタ
	// ********************************
public:
	/**
	 @param [in] pCDcdGrid 
		このオブジェクトを保持するグリッドオブジェクトへのポインタです。
	 */
	CDcdGridXBorder();
	virtual ~CDcdGridXBorder(){};
private:
	CDcdGridXBorder( const CDcdGridXBorder& ev ){} ;
	void operator=( CDcdGridXBorder& ev ) {};

public:
	// ********************************
	/// @name	CDcdGridXBorder 関連
	// ********************************
	///@{
	virtual Ou<IfDcDraw> getIfDcDraw() ;
	virtual void setIfDcDraw( Ou<IfDcDraw> value ) ;
	///@}

	// ********************************
	/// @name	CDcdGridXBorder 属性
	// ********************************
	///@{

	CDcdGridXBorder& setColumnBorderSize( DcdSize ev ){
		m_bAutoColumnBorderSize = false ;
		m_iColumnBorderSize = ev ;	return *this ; } ;
	bool	getAutoColumnBorderSize(){
		return m_bAutoColumnBorderSize ;	} ;

	CDcdGridXBorder& setAutoColumnBorderSize( bool ev ){
		m_bAutoColumnBorderSize = ev ;	return *this ; } ;
	///@}
	// ********************************
	/// @name	操作
	// ********************************
	///@{
	/**
		論理サイズで、境界のサイズを返します。
	 @param pIfDcdTarget [in]
		描画対象となるターゲットを指定してください。
	 @return
		境界のサイズを返します。
	 */
	virtual DcdSize	getColumnBorderSize( IfDcdTarget* pIfDcdTarget ) ;
	///@}
};

} //namespace DcdGrid
} //namespace DcDrawLib
#endif // CDcdGridXBorder_h
