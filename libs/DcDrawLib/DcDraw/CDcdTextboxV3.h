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
//	CDcdTextboxV3.h
// ****************************************************************
*/
/** @file */
#ifndef  ViewJikokuhyou_WndJikokuhyou_CDcdFillRectangleTextV3_h
#define  ViewJikokuhyou_WndJikokuhyou_CDcdFillRectangleTextV3_h

#include <string>
#include "str\tstring.h"

#include "DcDraw\CDcdFillrect.h"
#include "DcDraw\CDcdRectangle.h"
#include "DcDraw\CDcdText.h"
#include "DcDraw\CVerticalTextElement.h"
#include "DcdCd\DcDrawProp\CdPenProp.h"
#include "NsMu\Mup.h"

namespace DcDrawLib{
namespace DcDraw{

using namespace std ;
using namespace OuLib::NsMu;
using namespace DcDrawLib::DcDraw;
// ****************************************************************
//	CDcdTextboxV3
// ****************************************************************
/**
@brief
   DcDrawモデルにおける、描画アルゴリズムを実装したオブジェクトです。
　文字列を縦書き(時計回りに270℃回転)で描画します。

  日本語を縦書きで読めるように描画するには、フォントの属性として、
  縦書きフォント(タイプフェイス名の先頭が @ )を指定する必要が
  あります。

  このクラスでは、DcDrawで指定された領域の外辺より上下左右に、

	- m_logicalunitFrameWidth 
	- m_logicalunitFrameHeight 

分の枠領域を確保し、その内側に m_strText のテキストを書き込みます。

  このオブジェクトに対して DcDraw() を呼び出すと、以下の処理を行います。

１．  まず、領域全体を、ブラシ属性 m_CdBrushProp で塗りつぶします。

２．  領域の外辺内側に、指定のペン属性 m_CdPenProp で枠線を
描画します。

３．  枠領域の内側に、
テキスト m_strText を描画します。
  
<H4>
【テキストの配置について】
</H4>
　このクラスは、文字を左上から右下に向かって、
 縦書き(時計回りに270℃回転)で描画します。
  但し、フォントの属性が縦書きフォントで、全角文字の間に半角数字１つ・または２つがある場合、
その半角数字は横書きで描画します。
  	
（例）
@code
    11
    月
    23
    日
@endcode
  
<H4>
【このクラスの属性】
</H4>
  このクラスの属性には、このクラスのメンバ変数以外に、以下のものがあります。
  これらの属性は、m_CDcdFillrect , m_CDcdRectangle の属性として実装されます。

<H5>
CdBrushProp	m_CdBrushProp ;
</H5>
塗りつぶしに使用するブラシの属性。

<H5>
CdPenProp	m_CdPenProp
</H5>
枠線を描画するためのペンの属性。
  
<H4>
CDcdTextboxV,CDcdTextboxV2との違い
</H4>
　CDcdTextboxV は、横書きフォントを縦に並べて、縦書き表示を実現していました。
  CDcdTextboxV2 は、縦書きフォントを使用します。半角2桁以下の数字は、常に
横書きを行います。
　CDcdTextboxV3 では、縦書きフォント・横書きフォントのどちらも使用することが
できます。縦書きフォントを指定したときには、半角2桁以下の数字を横書きします。
横書きフォントを指定した場合は、半角2桁以下の数字に対する横書きは行いません。
 */
class CDcdTextboxV3 : public IfDcDraw
{
public:
	// ****************************************************************
	//	CDcdTextboxV3::CStrElementPlace
	// ****************************************************************
	/**
	  	『文字列要素』の描画位置を表す構造体です。
	 */
	class CStrElementPlace
	{
	private:
		// ********************************
		///@name 属性
		// ********************************
		///@{
		/**
		  	描画を行う文字列要素。
		 */
		CVerticalTextElement	m_CStrElement ;
	
		/**
		  	描画開始位置のＹ座標から、テキストの左上のＹ座標までの距離
		  	（論理単位）。
		 */
		int m_logicalunitYOffset ;	
	
		/**
		  	描画するＸ方向の行番号。起点（一番右）は０。
		 */
		int m_iXLineNumber ;

		/**
		  	文字列のＸ方向の幅（論理単位）。
		 */
		int m_iXLineWidth ;
		///@}
	public:
		// ********************************
		//	コンストラクタ
		// ********************************
		/**
		   @param aCStrElement [in]
		  	描画を行う文字列要素。
		   @param logicalunitYOffset [in]
		  	描画開始位置のＹ座標から、テキストの左上のＹ座標までの距離
		  	（論理単位）。
		   @param iXLineNumber [in]
		  	描画するＸ方向の行番号。起点（一番右）は０。
		   @param iXLineWidth [in]
		  	文字列のＸ方向の幅（論理単位）。
		 */
		CStrElementPlace( 
			const CVerticalTextElement&	aCStrElement ,
			int logicalunitYOffset , 
			int iXLineNumber , 
			int iXLineWidth ) :
			m_CStrElement( aCStrElement ) , 
			m_logicalunitYOffset( logicalunitYOffset ) ,
			m_iXLineNumber( iXLineNumber ) , 
			m_iXLineWidth( iXLineWidth ) {};
		CStrElementPlace( ) :
			m_logicalunitYOffset( 0 ) ,
			m_iXLineNumber( 0 ){};
	public:
		// ********************************
		///@name CStrElementPlace-属性
		// ********************************
		///@{
		CVerticalTextElement	getCStrElement()const{ return m_CStrElement ;};
		CStrElementPlace& setCStrElement( 
				const CVerticalTextElement& value ){
			m_CStrElement = value ; return *this ; } ;
		int getYOffset()const{ return m_logicalunitYOffset ;};
		CStrElementPlace& setYOffset( int value ){
			m_logicalunitYOffset = value ;	};
		int getXLineNumber()const{ return m_iXLineNumber ;};
		CStrElementPlace& setXLineNumber( int value ){
			m_iXLineNumber = value ; return *this ; } ;
		int getXLineWidth()const{ return m_iXLineWidth ;};
		CStrElementPlace& setXLineWidth( int value ){
			m_iXLineWidth = value ; return *this ; } ;
		///@}
	};


	
private:
	// ********************************
	///@name	包含
	// ********************************
	///@{
	/**
	  	背景を描画するオブジェクトです。
	  
	  	このオブジェクトの属性 CDcdFillrect::m_CdBrushProp は、
	  	このクラスのメンバ関数経由で操作できます。
	 */
	CDcdFillrect		m_CDcdFillrect ;
	/**
	  	枠線を描画するオブジェクトです。
	  
	  	このオブジェクトの属性 CDcdRectangle::m_CdPenProp は、
	  	このクラスのメンバ関数経由で操作できます。
	 */
	CDcdRectangle		m_CDcdRectangle ;
	
	///@}
private:
	// ********************************
	/// @name 属性
	// ********************************
	///@{
	/**
	  	描画する文字列です。
	 */
	tstring			m_strText ;


	/**
	  	テキストを描画する際のフォントを保持します。
	 */
	CdFontProp	m_CdFontProp ;

	
	/**
	  	この描画部品に表示できる、X方向（横方向）の全角での文字数を保持します。
	  	詳細は、 m_iLinesExtentY の説明を参照してください。

		既定値は1です。
	 */
	int	m_iLinesExtentX ;

	/**
	  	この描画部品に表示できる、Y方向（縦方向）の全角での文字数を保持します。
	  
	  	 getItemSize() は、 以下の値を返します。
	  	-	X = フォントの高さ×m_LinesExtectX 
	  	-	Y = フォントの高さ×m_LinesExtectY 

		既定値は1です。
	*/
	int	m_iLinesExtentY ;

	/**
	  	テキストを描画する場合の文字色です。
	  	デフォルトは黒です。
	 */
	CdColorProp	m_colorrefText ;
	
	/**
	  	テキストの左右の枠領域の太さを、論理単位で保持します。
	  	左側・右側それぞれに、このサイズの幅を確保します。

		既定値は0です。
	 */
	int	m_logicalunitFrameWidth ;

	/**
	  	テキストの上下の枠領域の太さを、論理単位で保持します。
	  	上側・下側それぞれに、このサイズの幅を確保します。

		既定値は0です。
	*/
	int	m_logicalunitFrameHeight ;
	///@}
 protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
	  	フォントの属性を格納した CdFontProp オブジェクトをもとに、
	  	縦書き用のフォントハンドルを生成します。
	  	
	  	この関数は、指定された CdFontProp の  m_iEscapement
	  	を変更したうえで、フォントを生成します。
	  	
	@param pIfDcdTarget [in]
	  	描画対象のデバイスコンテキストを指定してください。
	@param aCdFontProp [in]
	  	描画に使用するフォントを指定してください。
	@return
	  	対応する HFONT を保持する Ou<CGdiHFontHolder> を返します。
	*/
	static Ou<CGdiHFontHolder> CreateVFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aCdFontProp ) ;

	
	/**
	  	フォントの属性を格納した CdFontProp オブジェクトをもとに、
	  	横書き用のフォントハンドルを生成します。
	  	
	  	この関数は、指定された CdFontProp の  m_iEscapement
	  	を変更したうえで、フォントを生成します。
	  	
	@param pIfDcdTarget [in]
	  	描画対象のデバイスコンテキストを指定してください。
	@param aCdFontProp [in]
	  	描画に使用するフォントを指定してください。
	@return
	  	対応する HFONT を保持する Ou<CGdiHFontHolder> を返します。
	*/
	static Ou<CGdiHFontHolder> CreateHFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aCdFontProp )  ;
	
	/**
	  	縦書きの全角文字１つの大きさを計算します。
	   @param pIfDcdTarget [in]
	  	描画対象のデバイスコンテキストを指定してください。
	   @param fontHorizontal [in]
	  	描画に使用するフォントを指定してください。
	  	ここで指定するフォントは、横書きのものでなくてはなりません。
	   @return
	  	縦書きの全角文字１つの大きさを返します。
	 */
	static CdDcdSizeXy calcZenkakuCharExtent(
		IfDcdTarget* pIfDcdTarget , 
		const CdFontProp& aCdFontProp ) ;
	
	
	/**
	  	縦書き文字列中に横書きテキストを描画するための CDcdText オブジェクトを
	  	生成します。
		このオブジェクトは、m_strExtentに "00" 、 m_iLinesExtent に
		1 が設定されています。このため、getExtent() を呼び出すことにより、
		横書きテキストの幅と高さを取得できます。
	   @param aCdFontProp [in]
	  	テキストを描画する際のフォントを保持します。
		この関数は、aCdFontProp の m_iEscapement を無視します。
	   @param colorrefText [in]
	  	テキストを描画する場合の文字色です。

	 */
	static CDcdText createCDcdTextH( 
		const CdFontProp&	aCdFontProp , 
		const CdColorProp& colorrefText ) ;
	
	/**
	  	配列に格納されている『文字列要素』の各要素の描画位置を決めます。
	  	
	  	この関数は、指定された高さの描画領域にテキストを縦書きで配置すると
	  	仮定して、『文字列要素』毎のふさわしい座標を決定します。
	  
	  	この関数が実際の描画を行うわけではありません。この関数は行うのは
	  	描画位置の決定だけです。
	@param pIfDcdTarget [in]
	  	描画対象のデバイスコンテキストを指定してください。
	@param aCdFontProp [in]
	  	描画に使用するフォントを指定してください。
	@param pCStrElementCont [in]
	  	『文字列要素』を格納したコンテナを指定してください。
	@param pCStrElementPlaceCont [out]
	  	この関数はこのコンテナの末尾に、
	  	『文字列要素』ごとの描画位置を格納した CStrElementPlace 
	  	オブジェクトを追加します。
	  	このコンテナがそれまで保持していた要素は破棄します。
	@return
	  	成功したら 0 以上、エラーなら負の数です。
	  	現在のところ、常に 0 です。
	   @attention
	  	pCStrElementCont に格納されている要素の数と、
	  	pCStrElementPlaceCont に追加される要素の数は、同じとは限りません。
	  	この関数が文字列要素の結合を行う場合があるからです。@n
	  	（例） pCStrElementCont に "京"・"都"・"発" という
	  	要素が格納されていた場合、この３文字がもし同じ行に描画できる場合は、
	  	この関数は『文字列要素』を結合して、一つの "京都発" という文字列要素に
	  	します。
	 */
	static int VerticalTextElementToElementPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aCdFontProp ,
		const Mu<CVerticalTextElement>* pCStrElementCont ,
		Mui<CStrElementPlace>* pCStrElementPlaceCont ) ;

	/**
	 	配列に格納されている『文字列要素』の描画位置にしたがって、
	 	文字列を IfDcdTarget 領域内に描画します。
	@param pIfDcdTarget [in]
	 	描画対象を指定してください。
	 	この関数は、この描画領域の左上から、縦書きでテキストを描画します。
	@param aFontProp [in]
	 	描画に使用するフォントを指定してください。
	 	ここで指定するフォントは、横書きのものでなくてはなりません。
	@param colorTextColor [in]
		テキストの文字の色を指定してください。
	@param pCStrElementPlaceCont [in]
	 	『文字列要素』ごとの描画領域を格納したコンテナを指定してください。
	@return
	 	描画を行ったら真・何も描画を行わなかった場合は偽です。
	*/
	static bool DcDrawElementPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aFontProp ,
		const CdColorProp& colorTextColor , 
		const Mu<CStrElementPlace>* pCStrElementPlaceCont ) ;

	///@}
 public:
	// ********************************
	//	コンストラクタ
	// ********************************

	/**
	@param strText [in]
	 	描画する文字列です。
	@param aCdFontProp [in]
	 	テキストを描画する際のフォントを保持します。
	@param bAlwaysUseVFont [in]
		　縦書きフォントを常に使用するか否かを指定します。
	@param iLinesExtentX [in]
	 	この描画部品に表示できる、X方向（横方向）の文字数を保持します。
	@param iLinesExtentY [in]
		この描画部品に表示できる、Y方向（縦方向）の文字数を保持します。
		 getItemSize() は、 以下の値を返します。
		-	X = フォントの高さ×m_LinesExtectX 
		-	Y = フォントの高さ×m_LinesExtectY 
	@param colorrefText [in]
		テキストを描画する場合の文字色です。
	@param logicalunitFrameWidth [in]
		テキストの左右の枠領域の太さを、論理単位で指定してください。
		左側・右側それぞれに、このサイズの幅を確保します。
	@param logicalunitFrameHeight [in]
		テキストの上下の枠領域の太さを、論理単位で指定してください。
		上側・下側それぞれに、このサイズの幅を確保します。
		logicalunitFrameHeight だけを省略した場合は、 logicalunitFrameWidth 
		と同じであるとみなされます。
		logicalunitFrameHeight ・ logicalunitFrameWidth の両方を
		省略した場合は、 ０ とみなします
	@param aCdPenProp [in]
		枠線を描画するためのペンの属性
	@param aCdBrushProp [in]
		塗りつぶしに使用するブラシの属性を指定してください。
		省略したら、NULLBRUSHとみなします。
	@param eHalfCharInTextV [in]
		　縦書き表示のテキストボックス内で、
		半角文字を描画する方法を指定します。
	 */
	CDcdTextboxV3( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp ,
		int						iLinesExtentX ,
		int						iLinesExtentY ,
		const CdColorProp&	colorrefText = CdColorProp( 0 , 0 , 0 ) , 
		int						logicalunitFrameWidth  = 0 ,
		int						logicalunitFrameHeight = 0  ,
		const CdPenProp&		aCdPenProp = CdPenProp() ,
		const CdBrushProp& 		aCdBrushProp = CdBrushProp() ) ;

	CDcdTextboxV3() ;
	
	virtual ~CDcdTextboxV3() ;

 public:
	// ********************************
	///@name	IfDcDraw
	// ********************************
	///@{
	/**
	 	描画を要求します。
	 	この関数は、 pIfDcdTarget に、描画を行います。
	
		【オーバライド】
		  渡された領域に、 m_strText を描画します。
	 @param pIfDcdTarget  [in]
	 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 @return
	 	描画を行った場合は真・この領域への描画ができなかった場合は偽です。
	*/
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	 	このオブジェクトが描画するアイテムの大きさが決まっている場合は、
	 	その大きさを調べることができます。
	 	関数呼び出し元が複数の IfDcDraw オブジェクトを描画する場合には、
	 	関数呼び出し元は、この関数でアイテムの大きさを調べて、
	 	適切なレイアウトを考えてから、DcDraw() を実行することができます。
	
		【オーバライド】
		m_LinesExtentX m_LinesExtentY をもとに計算したテキスト領域のサイズに
		m_logicalunitFrameWidth ,m_logicalunitFrameHeight を加えて、
		領域のサイズを計算します。

 	
	@param pIfDcdTarget [in]
	 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 @param pCdDcdSizeXy [out]
	 	このオブジェクトの描画するアイテムの大きさが決まっている場合は、
	 	この関数はこのアドレスに、そのアイテムのサイズを返します。
	 	このオブジェクトの描画するアイテムの大きさが決まっていない場合は、
	 	この値は不定です。
	 @return
	 	このオブジェクトの描画するアイテムの大きさが決まっていて、
	 	その大きさを *pCDcdSizeXyに書き込んだ場合は真です。
	 	そうでない場合は、偽です。
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
	///@}
// ********************************
//	CDcdTextboxV3
// ********************************
 public:
	// ********************************
	///@name CDcdTextboxV3-属性
	// ********************************
	///@{
	virtual CdBrushProp	getCdBrushProp()
	{	return m_CDcdFillrect.getCdBrushProp()	;	} ;
	virtual CDcdTextboxV3& setCdBrushProp( const CdBrushProp& value )
	{	m_CDcdFillrect.setCdBrushProp( value ) ;	return *this ;}
	virtual CdPenProp	getCdPenProp()
	{	return m_CDcdRectangle.getCdPenProp()	;	} ;
	virtual CDcdTextboxV3& setCdPenProp( const CdPenProp& value )
	{	m_CDcdRectangle.setCdPenProp( value ) ;	return *this ;}

	virtual tstring			getText()
	{	return m_strText ;	} ;
	virtual CDcdTextboxV3& setText( const tstring& value )
	{	m_strText = value ; 	return *this ; } ;

	virtual CdFontProp	getCdFontProp()
	{	return m_CdFontProp ;};
	virtual CDcdTextboxV3& setCdFontProp( 
			const CdFontProp& value )
	{	m_CdFontProp = value ; return *this ; } ;

	virtual int				getLinesExtentX()
	{	return m_iLinesExtentX ; } ;
	virtual CDcdTextboxV3& setLinesExtentX( int value )
	{	m_iLinesExtentX = value ; 	return *this ; } ;
	virtual int				getLinesExtentY()
	{	return m_iLinesExtentY ; } ;
	virtual CDcdTextboxV3& setLinesExtentY( int value )
	{	m_iLinesExtentY = value ; 	return *this ; } ;

	virtual CdColorProp	getTextColor()
	{	return m_colorrefText ;	};
	virtual CDcdTextboxV3& setTextColor( const CdColorProp& value )
	{	m_colorrefText = value ; return *this ; } ;

	virtual int	getFrameWidth()
	{	return m_logicalunitFrameWidth ;};
	virtual CDcdTextboxV3& setFrameWidth( int value )
	{	m_logicalunitFrameWidth = value ;	return *this ; } ;

	virtual int	getFrameHeight(){	return m_logicalunitFrameHeight ;};
	virtual CDcdTextboxV3&  setFrameHeight( int value )
	{	m_logicalunitFrameHeight = value ;	return *this ; } ;
	///@}
		

};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*ViewJikokuhyou_WndJikokuhyou_CDcdTextboxV3_h*/
