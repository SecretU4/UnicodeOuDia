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
//	CDcdGridYColumn.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdGridYColumn_h
#define  CDcdGridYColumn_h
#include "DcDraw/IfDcDraw.h"
#include "DcdGrid/CDcdGridYBorder.h"
#include "NsOu/Ou.h"

namespace DcDrawLib{
namespace DcdGrid{

// ****************************************************************
//	CDcdGridYColumn
// ****************************************************************
/**
 @brief
 【概要】
	DcdGrid のY列オブジェクトです。
	IfDcDraw オブジェクトと関連を持ち､ その IfDcDraw オブジェクトを使って
	Y列の下側の境界線を描画します。

	CDcdGrid は、通常は CDcdLine オブジェクトを生成して、
	this と関連する IfDcDraw オブジェクトとして登録します｡
 */
class CDcdGridYColumn
{
	friend class CDcdGrid ;
private:
	// ********************************
	/// @name 	CDcdGrid に関係する属性/関連
	// ********************************
	///@{
	/**
		このオブジェクトを保持するグリッドオブジェクトへのポインタです。
		コンストラクタで決まります。
		破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、thisよりも長く生存しなくてはなりません。
	*/
	CDcdGrid*	m_pCDcdGrid ;

	///@}	

private:
	// ********************************
	///	@name 集約
	// ********************************
	///@{
	/**
		Y列の下側の境界線に関する属性を保持します。
	*/
	CDcdGridYBorder	m_CDcdGridYBorder ;
	///@}
private:
	// ********************************
	///	@name CDcdGridYColumn 固有の属性
	// ********************************
	///@{

	/**
		論理サイズで、列のサイズを保持します。
		ただし、 m_bAutoColumnSize が真なら、この値は無効です。
		デフォルトでは１です。
	 */
	DcdSize	m_iColumnSize ;
	
	/**
		真なら、Y列番号０のセルの IfDcDraw オブジェクトの getItemSize() が返す
		サイズをもとに、列のサイズを決定します。
		デフォルトでは真です。
	 @attention
		ただし、この値が真の場合、描画は遅くなります
		(特に、CDcdTextbox::getItemSize() に
		時間がかかるせいです）。@n
		とくに、列の数が多い場合はかなり遅くなることが
		ありますので、
		列の数が多い場合は、 
		CDcdGridYColumn の
		m_bAutoColumnSize を偽にしたうえで、
		m_iColumnSize に明示的に値を設定することをお勧めします。
	 */
	bool	m_bAutoColumnSize ;
	
	
	///@}


// ********************************
//	コンストラクタ
// ********************************
public:
	/**
	 * @param [in] pCDcdGrid 
	 *	このオブジェクトを保持するグリッドオブジェクトへのポインタです。
	 */
	CDcdGridYColumn( CDcdGrid*	pCDcdGrid ) ;
	
 private:
	CDcdGridYColumn( const CDcdGridYColumn& ev ){} ;
	void operator=( CDcdGridYColumn& ev ) {};

// ****************************************************************
//	CDcdGridYColumn
// ****************************************************************
public:
	// ********************************
	/// @name	関連
	// ********************************
	///@{
	///@}

	// ********************************
	/// @name	集約
	// ********************************
	///@{
	CDcdGridYBorder*	getCDcdGridYBorder(){
		return &m_CDcdGridYBorder ;};
	///@}

	// ********************************
	/// @name	属性
	// ********************************
	///@{
	CDcdGridYColumn& setColumnSize( DcdSize ev ){
		m_bAutoColumnSize = false ;
		m_iColumnSize = ev ;	return *this ; } ;
	bool getAutoColumnSize(){
		return m_bAutoColumnSize ; } ;
	CDcdGridYColumn& setAutoColumnSize( bool ev ){
		m_bAutoColumnSize = ev ;	return *this ; } ;
	

	
	///@}
	
	// ********************************
	/// @name	操作
	// ********************************
	///@{
	
	/**
		論理サイズで、列のサイズを返します。
	 @param pIfDcdTarget [in]
		描画対象となるターゲットを指定してください。
	 @return
		Y列のサイズを返します。
	 */
	virtual DcdSize	getColumnSize( IfDcdTarget* pIfDcdTarget ) ;
	
	
	///@}

};

} //namespace DcdGrid
} //namespace DcDrawLib
#endif /*CDcdGridYColumn_h*/
