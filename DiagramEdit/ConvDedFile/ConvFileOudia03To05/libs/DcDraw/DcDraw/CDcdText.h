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
//	CDcdText.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdText_h
#define  CDcdText_h

#include <string>
using namespace std ;

#include "str/tstring.h"

#include "./IfDcDraw.h"
#include "CdDrawTextProp.h"

// ****************************************************************
//	CDcdText
// ****************************************************************
/**
* @brief
* 【概要】
* 	   DcDrawモデルにおける、テキストの描画を行うアイテムです。
*
*	  このオブジェクトに対して DcDraw() を呼び出すと、指定された領域に
*	属性 m_strText のテキストを書き込みます。
*/
class CDcdText : public IfDcDraw
{
// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	*	描画する文字列です。
	*	デフォルトでは空文字列です。
	*/
	tstring			m_strText ;
	
	/**
	*	テキストを描画する際の属性を保持します。
	*	デフォルトでは、DEFAULT_GUI_FONT を単一行で描画します。
	*/
	CdDrawTextProp	m_CdDrawTextProp ;
	
	/**
	*	この描画部品の大きさの目安となる
	*	文字列です。
	*	getItemSize() は、この文字列を表示できる幅を返します。
	*	getItemSize() を使わないのであれば、この属性は使いません。
	*
	*	デフォルトは空文字列です。この場合、getItemSize() は、
	*	m_strText を描画するのに必要なサイズを返します。
	*/
	tstring			m_strExtent ;
	
	/**
	*	この描画部品の大きさの行数です
	*	getItemSize() は、この行数を表示できる高さを返します。
	*	getItemSize() を使わないのであれば、この属性は使いません。
	*
	*	デフォルトは１です。
	*/
	int				m_iLinesExtent ;
	
///@}

	
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	* @param strText [in]
	*	描画する文字列です。
	* @param aCdDrawTextProp [in]
	*	テキストを描画する際の属性を保持します。
	*	デフォルトでは、DEFAULT_GUI_FONT を単一行で描画します。
	* @param strExtent [in]
	*	この描画部品の大きさの目安となる
	*	文字列です
	*	デフォルトは空文字列です。この場合、getItemSize() は、
	*	strText を描画するのに必要なサイズを返します。
	* @param iLinesExtent [in]
	*	この描画部品の大きさの行数です
	*	getItemSize() は、この行数を表示できる高さを返します。
	*	デフォルトは１です。
	*/
	CDcdText( 
		const tstring&			strText,
		const CdDrawTextProp&	aCdDrawTextProp ,
		const tstring&			strExtent = TEXT("") ,
		int						iLinesExtent = 1 
	) ;
	
	CDcdText() ;
	
	virtual ~CDcdText() ;
	
// ********************************
///@name	IfDcDraw
// ********************************
///@{
 public:
	/**
	* 	描画を要求します。
	* 	この関数は、 pIfDcdTarget に、描画を行います。
	*
	*	【オーバライド】
	*	  渡された領域に、 m_strText を描画します。
	* @param pIfDcdTarget  [in]
	* 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	* @return
	* 	描画を行った場合は真・この領域への描画ができなかった場合は偽です。
	*/
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	* 	このオブジェクトが描画するアイテムの大きさが決まっている場合は、
	* 	その大きさを調べることができます。
	* 	関数呼び出し元が複数の IfDcDraw オブジェクトを描画する場合には、
	* 	関数呼び出し元は、この関数でアイテムの大きさを調べて、
	* 	適切なレイアウトを考えてから、DcDraw() を実行することができます。
	*
	*	【オーバライド】
	*	  m_strExtent と m_lineExtent をもとに、領域のサイズを計算します。
	* @param pIfDcdTarget [in]
	* 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	* @param pCdDcdSizeXy [out]
	* 	このオブジェクトの描画するアイテムの大きさが決まっている場合は、
	* 	この関数はこのアドレスに、そのアイテムのサイズを返します。
	* 	このオブジェクトの描画するアイテムの大きさが決まっていない場合は、
	* 	この値は不定です。
	* @return
	* 	このオブジェクトの描画するアイテムの大きさが決まっていて、
	* 	その大きさを *pCdDcdSizeXyに書き込んだ場合は真です。
	* 	そうでない場合は、偽です。
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
///@}
// ********************************
//	CDcdText
// ********************************
 public:
	// ********************************
	///	@name 属性
	// ********************************
	///@{
	virtual tstring			getText(){	return m_strText ;	} ;
	virtual CDcdText& setText( const tstring& ev ){	
		m_strText = ev ;	return *this ; } ;
	virtual CdDrawTextProp	getCdDrawTextProp(){	return m_CdDrawTextProp ;};
	virtual CDcdText& setCdDrawTextProp( const CdDrawTextProp& ev ){
		m_CdDrawTextProp = ev ;	return *this ; } ;
	virtual tstring			getExtent(){	return m_strExtent ;	} ;
	virtual CDcdText& setExtent( const tstring& ev ){
		m_strExtent = ev ;	return *this ;	};
	virtual int				getLinesExtent(){	return m_iLinesExtent ;	} ;
	virtual CDcdText& setLinesExtent( int ev ){
		m_iLinesExtent = ev ;	return *this ; } ;
	///@}
};
#endif /*CDcdText_h*/
