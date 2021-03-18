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
//	CDcdTextbox.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdTextbox_h
#define  CDcdTextbox_h
#include <string>
#include "str/tstring.h"

#include "DcDraw\CDcdFillrect.h"
#include "DcDraw\CDcdRectangle.h"
#include "DcDraw\CDcdText.h"
#include "DcdCd\DcDrawProp\CdPenProp.h"

#include <string>

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CDcdTextbox
// ****************************************************************
/**
 * @brief
 * 【概要】
 * 	   DcDrawモデルにおける、背景色つき・枠つきでテキストの描画を行う
 *	アイテムです。
 *
 *	  このクラスでは、DcDrawで指定された領域の外辺より上下左右に、
 *
 *		- m_logicalunitFrameWidth 
 *		- m_logicalunitFrameHeight 
 *	
 *	分の枠領域を確保し、その内側に m_strText のテキストを書き込みます。
 *
 *	  このオブジェクトに対して DcDraw() を呼び出すと、以下の処理を行います。
 *
 *	１．  まず、領域全体を、ブラシ属性 m_CdBrushProp で塗りつぶします。
 *
 *	２．  領域の外辺内側に、指定のペン属性 m_CdPenProp で枠線を
 *	描画します。
 *
 *	３．  枠領域の内側に、属性 m_CdDrawTextProp で、
 *	テキスト m_strText を描画します。
 *
 *	<H4>
 * 【このクラスの属性】
 *	</H4>
 *	  このクラスの属性は、実際にはこのクラスが包含するオブジェクト
 *	m_CDcdFillrect , m_CDcdRectangle , m_CDcdText の属性となります。
 *
 *	<H5>
 *	CdPenProp	m_CdPenProp
 *	</H5>
 *	枠線を描画するためのペンの属性。
 *
 *	<H5>
 *	int	m_logicalunitFrameWidth ;
 *	</H5>
 *	テキストの左右の枠領域の太さを、論理単位で保持します。
 *	左側・右側それぞれに、このサイズの幅を確保します。
 *
 *	<H5>
 *	int	m_logicalunitFrameHeight ;
 *	</H5>
 *	テキストの上下の枠領域の太さを、論理単位で保持します。
 *	上側・下側それぞれに、このサイズの幅を確保します。
 *
 *	<H5>
 *	tstring			m_strText ;
 *	</H5>
 *	描画する文字列です。
 *
 *	<H5>
 *	CdDrawTextProp	m_CdDrawTextProp ;
 *	</H5>
 *	テキストを描画する際の属性を保持します。
 *
 *	<H5>
 *	tstring			m_strExtent;
 *	</H5>
 *	この描画部品の大きさの目安となる
 *	文字列です
 *	getItemSize() は、この文字列を表示できる幅を返します。
 *	省略したら、strTextと同じとみなします。
 *
 * <H5>
 *	int	m_iLinesExtent ;
 * </H5>
 *	この描画部品の大きさの行数です getItemSize() は、
 *	この行数を表示できる高さを返します。 
 *	getItemSize() を使わないのであれば、この属性は使いません。
 *	デフォルトは１です。 
 *
 * <H5>
 *	CdBrushProp	m_CdBrushProp ;
 * </H5>
 *	塗りつぶしに使用するブラシの属性。
 *
 * @note
 *	CDcdRectangleTextとCDcdTextbox の違いは、ペンの属性が
 *	SOLIDでない場合に明らかになります。
 *	このとき、 CDcdRectangleText では、枠線の描画されない部分はDCの背景色と
 *	なりますが、 CDcdTextbox の場合は、枠線の描画されない部分を
 *	透過モードとします（つまり、背景ブラシが反映されます）。
 */
class CDcdTextbox : public IfDcDraw
{
// --------------------------------
///@name	包含
// --------------------------------
///@{
 private:
	/**
	 *	背景を描画するオブジェクトです。
	 *
	 *	このオブジェクトの属性 CDcdFillrect::m_CdBrushProp は、
	 *	このクラスのメンバ関数経由で操作できます。
	 */
	CDcdFillrect		m_CDcdFillrect ;
	/**
	 *	枠線を描画するオブジェクトです。
	 *
	 *	このオブジェクトの属性 CDcdRectangle::m_CdPenProp は、
	 *	このクラスのメンバ関数経由で操作できます。
	 */
	CDcdRectangle		m_CDcdRectangle ;
	
	/**
	 *	テキストを描画するオブジェクトです。
	 *
	 *	このオブジェクトの属性 
	 *	CDcdText::m_strText ,
	 *	CDcdText::m_CdDrawTextProp ,
	 *	CDcdText::m_strExtent ,
	 *	CDcdText::m_iLinesExtent 
	 *	は、このクラスのメンバ関数経由で操作できます。
	 */
	CDcdText			m_CDcdText ;
///@}
// ********************************
/// @name 属性
// ********************************
///@{
 private:
	/**
	*	テキストの左右の枠領域の太さを、論理単位で保持します。
	*	左側・右側それぞれに、このサイズの幅を確保します。
	*/
	int	m_logicalunitFrameWidth ;

	/**
	*	テキストの上下の枠領域の太さを、論理単位で保持します。
	*	上側・下側それぞれに、このサイズの幅を確保します。
	*/
	int	m_logicalunitFrameHeight ;
	
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
	* @param strExtent [in]
	*	この描画部品の大きさの目安となる
	*	文字列です
	*	getItemSize() は、この文字列を表示できる幅を返します。
	*	省略したら、strTextと同じとみなします。
	* @param iLinesExtent [in]
	*	この描画部品の大きさの行数です
	*	getItemSize() は、この行数を表示できる高さを返します。
	*	省略したら、１とみなします。
	* @param logicalunitFrameWidth [in]
	*	テキストの左右の枠領域の太さを、論理単位で指定してください。
	*	左側・右側それぞれに、このサイズの幅を確保します。
	* @param logicalunitFrameHeight [in]
	*	テキストの上下の枠領域の太さを、論理単位で指定してください。
	*	上側・下側それぞれに、このサイズの幅を確保します。
	*	logicalunitFrameHeight だけを省略した場合は、 logicalunitFrameWidth 
	*	と同じであるとみなされます。
	*	logicalunitFrameHeight ・ logicalunitFrameWidth の両方を
	*	省略した場合は、 ０ とみなします
	* @param aCdPenProp [in]
	*	枠線を描画するためのペンの属性
	* @param aCdBrushProp [in]
	*	塗りつぶしに使用するブラシの属性を指定してください。
	*	省略したら、NULLBRUSHとみなします。
	*/
	CDcdTextbox( 
		const tstring&			strText  ,
		const CdDrawTextProp&	aCdDrawTextProp ,
		const tstring&			strExtent = TEXT( "" ) ,
		int						iLinesExtent = 1 ,
		int						logicalunitFrameWidth  = 0 ,
		int						logicalunitFrameHeight = 0  ,
		const CdPenProp&		aCdPenProp = CdPenProp() ,
		const CdBrushProp& 		aCdBrushProp = CdBrushProp() );

	/**
	*	上のコンストラクタとは、引数の順序だけが異なります。
	* @param aCdPenProp [in]
	*	枠線を描画するためのペンの属性
	* @param logicalunitFrameWidth [in]
	*	テキストの左右の枠領域の太さを、論理単位で指定してください。
	*	左側・右側それぞれに、このサイズの幅を確保します。
	* @param logicalunitFrameHeight [in]
	*	テキストの上下の枠領域の太さを、論理単位で指定してください。
	*	上側・下側それぞれに、このサイズの幅を確保します。
	*	logicalunitFrameHeight だけを省略した場合は、 logicalunitFrameWidth 
	*	と同じであるとみなされます。
	*	logicalunitFrameHeight ・ logicalunitFrameWidth の両方を
	*	省略した場合は、 ０ とみなします
	* @param strText [in]
	*	描画する文字列です。
	* @param aCdDrawTextProp [in]
	*	テキストを描画する際の属性を保持します。
	* @param strExtent [in]
	*	この描画部品の大きさの目安となる
	*	文字列です
	*	getItemSize() は、この文字列を表示できる幅を返します。
	*	省略したら、strTextと同じとみなします。
	* @param iLinesExtent [in]
	*	この描画部品の大きさの行数です
	*	getItemSize() は、この行数を表示できる高さを返します。
	*	省略したら、１とみなします。
	* @param aCdBrushProp [in]
	*	塗りつぶしに使用するブラシの属性を指定してください。
	*	省略したら、NULLBRUSHとみなします。
	*/
	CDcdTextbox( 
		const CdPenProp&		aCdPenProp ,
		int						logicalunitFrameWidth  = 0 ,
		int						logicalunitFrameHeight = 0  ,
		const tstring&			strText = TEXT( "" ) ,
		const CdDrawTextProp&	aCdDrawTextProp = CdDrawTextProp() ,
		const tstring&			strExtent = TEXT( "" ) ,
		int						iLinesExtent = 1 ,
		const CdBrushProp& 		aCdBrushProp = CdBrushProp() );



	CDcdTextbox() ;
	
	virtual ~CDcdTextbox() ;

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
	*	  Extent と LinesExtent をもとに計算したテキスト領域のサイズに
	*	m_logicalunitFrameWidth ,m_logicalunitFrameHeight を加えて、
	*	領域のサイズを計算します。
	* @param pIfDcdTarget [in]
	* 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	* @param pCdDcdSizeXy [out]
	* 	このオブジェクトの描画するアイテムの大きさが決まっている場合は、
	* 	この関数はこのアドレスに、そのアイテムのサイズを返します。
	* 	このオブジェクトの描画するアイテムの大きさが決まっていない場合は、
	* 	この値は不定です。
	* @return
	* 	このオブジェクトの描画するアイテムの大きさが決まっていて、
	* 	その大きさを *pCDcdSizeXyに書き込んだ場合は真です。
	* 	そうでない場合は、偽です。
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
///@}
// ********************************
//	CDcdTextbox
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	 * @return
	 *	枠線に使うペンの属性。
	 */
	virtual CdPenProp	getCdPenProp(){	
		return m_CDcdRectangle.getCdPenProp()	;	} ;
	virtual CDcdTextbox& setCdPenProp( const CdPenProp& ev ){
		m_CDcdRectangle.setCdPenProp( ev ) ;	return *this ;}

	virtual int	getFrameWidth(){	return m_logicalunitFrameWidth ;};
	virtual CDcdTextbox& setFrameWidth( int ev ){
		m_logicalunitFrameWidth = ev ;	return *this ; } ;

	virtual int	getFrameHeight(){	return m_logicalunitFrameHeight ;};
	virtual CDcdTextbox&  setFrameHeight( int ev ){
		m_logicalunitFrameHeight = ev ;	return *this ; } ;
	
	/**
	 * @return
	 *	描画する文字列です。
	 */
	virtual tstring			getText(){	
		return m_CDcdText.getText() ;	} ;
	virtual CDcdTextbox& setText( const tstring& ev ){	
		m_CDcdText.setText( ev ) ; 	return *this ; } ;
	/**
	 * @return
	 *	テキストを描画する際の属性を保持します。
	 */
	virtual CdDrawTextProp	getCdDrawTextProp(){
		return m_CDcdText.getCdDrawTextProp() ;};
	virtual CDcdTextbox& setCdDrawTextProp( 
			const CdDrawTextProp& ev ){
		m_CDcdText.setCdDrawTextProp( ev ) ; 	return *this ; } ;
	/**
	 * @return
	 *	この描画部品の大きさの目安となる
	 *	文字列です
	 *	getItemSize() は、この文字列を表示できる幅を返します。
	 *	getItemSize() を使わないのであれば、この属性は使いません。
	 */
	virtual tstring			getExtent(){
		return m_CDcdText.getExtent() ; } ;
	virtual CDcdTextbox&  setExtent( const tstring& ev ){
		m_CDcdText.setExtent( ev ) ;	return *this ; };
	/**
	 * @return
	 *	この描画部品の大きさの行数です
	 *	getItemSize() は、この行数を表示できる高さを返します。
	 *	getItemSize() を使わないのであれば、この属性は使いません。
	 */
	virtual int				getLinesExtent(){
		return m_CDcdText.getLinesExtent() ; } ;
	virtual CDcdTextbox& setLinesExtent( int ev ){
		m_CDcdText.setLinesExtent( ev ) ; 	return *this ; } ;

	/**
	 * @return
	 *	塗りつぶしに使用するブラシの属性。
	 */
	virtual CdBrushProp	getCdBrushProp(){	
		return m_CDcdFillrect.getCdBrushProp()	;	} ;
	virtual CDcdTextbox& setCdBrushProp( const CdBrushProp& ev ){
		m_CDcdFillrect.setCdBrushProp( ev ) ;	return *this ;}
	///@}
	
	
};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*CDcdTextbox_h*/
