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
//	CDcdFillRectangleTextV2.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdFillRectangleTextV2_h
#define  CDcdFillRectangleTextV2_h

#include <string>
using namespace std ;

#include "str/tstring.h"

#include "DcDraw/CDcdFillrect.h"
#include "DcDraw/CDcdRectangle.h"
#include "DcDraw/CDcdText.h"
#include "DcDraw/CdPenProp.h"
#include "Cont/IfValueCont.h"


// ****************************************************************
//	CDcdFillRectangleTextV2
// ****************************************************************
/**
 * @brief
 * 【概要】
 * 	   DcDrawモデルにおける、描画アルゴリズムを実装したオブジェクトです。
 *	  縦書きの日本語を縦書きフォント・横書きフォント混在で描画します。
 *	  背景色つき・枠つきです。
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
 *	３．  枠領域の内側に、
 *	テキスト m_strText を描画します。
 *
 *	<H4>
 * 【テキストの配置について】
 *	</H4>
 *	  このクラスは、テキストを縦書きフォントを使って描画します。
 *	このため、半角文字は回転して描画されます。
 *	  但し、全角文字の間に半角数字１つ・または２つがある場合、
 *	その半角数字は横書きで描画します。
 *	
 *	（例）
@code
    11
    月
    23
    日
@endcode
 *
 *	<H4>
 * 【このクラスの属性】
 *	</H4>
 *	  このクラスの属性は、実際にはこのクラスが包含するオブジェクト
 *	m_CDcdFillrect , m_CDcdRectangle , m_CDcdText の属性となります。
 *
 * <H5>
 *	CdBrushProp	m_CdBrushProp ;
 * </H5>
 *	塗りつぶしに使用するブラシの属性。
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
 *	CdFontProp	m_CdFontProp ;
 *	</H5>
 *	テキストを描画する際のフォントを保持します。
 *	このオブジェクトの属性 m_strFacename には、横書きフォントの名前
 *	（先頭に "@" をつけない）を指定してください。
 *
 *	<H5>
 *	COLORREF	m_colorrefText ;
 *	</H5>
 *	テキストを描画する場合の文字色です。
 *	デフォルトは黒です。
 *
 *	
 * <H5>
 *	int	m_iLinesExtentX ;
 * </H5>
 *	この描画部品に表示できる、X方向（横方向）の文字数を保持します。
 *	詳細は、 m_iLinesExtentY の説明を参照してください。
 *
 * <H5>
 *	int	m_iLinesExtentY ;
 * </H5>
 *	この描画部品に表示できる、Y方向（縦方向）の文字数を保持します。
 *
 *	 getItemSize() は、 以下の値を返します。
 *	-	X方向が m_strExtent のX方向のサイズ×m_LinesExtectX 
 *	-	Y方向が m_strExtent のY方向のサイズ×m_LinesExtectY 
 *
 */
class CDcdFillRectangleTextV2 : public IfDcDraw
{
// --------------------------------
//	インナータイプ
// --------------------------------
 public:
	// ----------------------------------------------------------------
	//	CDcdFillRectangleTextV2::CMojiretsuyouso
	// ----------------------------------------------------------------
	/**
	 *	『文字列要素』一つを表す単純データクラスです。
	 */
	class CMojiretsuyouso
	{
	// ********************************
	//	インナータイプ
	// ********************************
	 public:
		/**
		 *	『文字列要素』の種類
		 */
		enum EType
		{
			/**
			 *	縦書きフォントを使って描画する、連続した全角文字
			 */
			V_ZENKAKU ,	
			/**
			 *  縦書きフォントを使って描画する、連続した半角文字
			 */
			V_HANKAKU ,
			/**
			 *	横書きフォントを使って描画する、１・２文字の半角数字
			 *	（この前後に半角文字がないこと）
			 */
			H_HANKAKU , 
		};
	// ********************************
	///@name 属性
	// ********************************
	///@{
	 private:
		/**
		 *	文字列要素に含まれる部分文字列。
		 */
		string m_strBubunMojiretsu ;
		
		/**
		 *	『文字列要素』の種類
		 */
		EType	m_eType ;
		
	///@}
	// ********************************
	//	コンストラクタ
	// ********************************
	 public:
		/**
		 * @param strBubunMojiretsu [in]
		 *	文字列要素に含まれる部分文字列。
		 * @param eType [in]
		 *	『文字列要素』の種類
		 */
		CMojiretsuyouso( 
			const string& strBubunMojiretsu ,
			EType	eType ) :
			m_strBubunMojiretsu( strBubunMojiretsu ) ,
			m_eType( eType ){};

		CMojiretsuyouso() :
			m_eType( V_ZENKAKU ){};
	// ********************************
	///@name 属性
	// ********************************
	///@{
	 public:
		string getBubunMojiretsu()const{ return m_strBubunMojiretsu ;};
		CMojiretsuyouso& setBubunMojiretsu( const string& value ){
			 m_strBubunMojiretsu = value ; return *this ; } ;
		EType	getType()const{ return m_eType ;};
		CMojiretsuyouso& setType( EType	value ){
			m_eType = value ; return *this ; } ;
	///@}
	};
	// ----------------------------------------------------------------
	//	CDcdFillRectangleTextV2::CMojiretsuyousoPlace
	// ----------------------------------------------------------------
	/**
	 *	『文字列要素』の描画位置を表す構造体です。
	 */
	class CMojiretsuyousoPlace
	{
	// ********************************
	///@name 属性
	// ********************************
	///@{
	 private:
		/**
		 *	描画を行う文字列要素。
		 */
		CMojiretsuyouso	m_CMojiretsuyouso ;
	
		/**
		 *	描画開始位置のＹ座標から、テキストの左上のＹ座標までの距離
		 *	（論理単位）。
		 */
		int m_logicalunitYOffset ;	
	
		/**
		 *	描画するＸ方向の行番号。起点（一番右）は０。
		 */
		int m_iXLineNumber ;

		/**
		 *	文字列のＸ方向の幅（論理単位）。
		 */
		int m_iXLineWidth ;
	// ********************************
	//	コンストラクタ
	// ********************************
	 public:
		/**
		 * @param aCMojiretsuyouso [in]
		 *	描画を行う文字列要素。
		 * @param logicalunitYOffset [in]
		 *	描画開始位置のＹ座標から、テキストの左上のＹ座標までの距離
		 *	（論理単位）。
		 * @param iXLineNumber [in]
		 *	描画するＸ方向の行番号。起点（一番右）は０。
		 * @param iXLineWidth [in]
		 *	文字列のＸ方向の幅（論理単位）。
		 */
		CMojiretsuyousoPlace( 
			const CMojiretsuyouso&	aCMojiretsuyouso ,
			int logicalunitYOffset , 
			int iXLineNumber , 
			int iXLineWidth ) :
			m_CMojiretsuyouso( aCMojiretsuyouso ) , 
			m_logicalunitYOffset( logicalunitYOffset ) ,
			m_iXLineNumber( iXLineNumber ) , 
			m_iXLineWidth( iXLineWidth ) {};
		CMojiretsuyousoPlace( ) :
			m_logicalunitYOffset( 0 ) ,
			m_iXLineNumber( 0 ){};
	// ********************************
	///@name 属性
	// ********************************
	///@{
	 public:
		CMojiretsuyouso	getCMojiretsuyouso()const{ return m_CMojiretsuyouso ;};
		CMojiretsuyousoPlace& setCMojiretsuyouso( 
				const CMojiretsuyouso& value ){
			m_CMojiretsuyouso = value ; return *this ; } ;
		int getYOffset()const{ return m_logicalunitYOffset ;};
		CMojiretsuyousoPlace& setYOffset( int value ){
			m_logicalunitYOffset = value ;	};
		int getXLineNumber()const{ return m_iXLineNumber ;};
		CMojiretsuyousoPlace& setXLineNumber( int value ){
			m_iXLineNumber = value ; return *this ; } ;
		int getXLineWidth()const{ return m_iXLineWidth ;};
		CMojiretsuyousoPlace& setXLineWidth( int value ){
			m_iXLineWidth = value ; return *this ; } ;
	};
	
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
	
///@}
// ********************************
/// @name 属性
// ********************************
///@{
 private:
	/**
	 *	描画する文字列です。
	 */
	tstring			m_strText ;

	/**
	 *	テキストを描画する際のフォントを保持します。
	 */
	CdFontProp	m_CdFontProp ;
	
	/**
	 *	この描画部品に表示できる、X方向（横方向）の全角での文字数を保持します。
	 *	詳細は、 m_iLinesExtentY の説明を参照してください。
	 */
	int	m_iLinesExtentX ;

	/**
	 *	この描画部品に表示できる、Y方向（縦方向）の全角での文字数を保持します。
	 *
	 *	 getItemSize() は、 以下の値を返します。
	 *	-	X = フォントの高さ×m_LinesExtectX 
	 *	-	Y = フォントの高さ×m_LinesExtectY 
	 */
	int	m_iLinesExtentY ;

	/**
	 *	テキストを描画する場合の文字色です。
	 *	デフォルトは黒です。
	 */
	CdColorProp	m_colorrefText ;
	
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
// --------------------------------
///@name 下請関数
// --------------------------------
///@{
 public:
	/**
	 *	横書きフォントの属性を格納した CdFontProp オブジェクトをもとに、
	 *	縦書きのフォントハンドルを生成します。
	 *	
	 *	この関数は、指定された CdFontProp の m_strFacename ・ m_iEscapement
	 *	を変更したうえで、フォントを生成します。
	 *	
	 * @param pIfDcdTarget [in]
	 *	描画対象のデバイスコンテキストを指定してください。
	 * @param fontHorizontal [in]
	 *	描画に使用するフォントを指定してください。
	 *	ここで指定するフォントは、横書きのものでなくてはなりません。
	 * @return
	 *	対応する HFONT を返します。
	 *	この HFONT の破棄の責務は、 pIfDcdTarget にあります。
	 *	関数呼出元は、この HFONT を DeleteObject() しないでください。
	 */
	static HFONT CreateVFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ) ;
	
	/**
	 *	縦書きの全角文字１つの大きさを計算します。
	 * @param pIfDcdTarget [in]
	 *	描画対象のデバイスコンテキストを指定してください。
	 * @param fontHorizontal [in]
	 *	描画に使用するフォントを指定してください。
	 *	ここで指定するフォントは、横書きのものでなくてはなりません。
	 * @return
	 *	縦書きの全角文字１つの大きさを返します。
	 */
	static CdDcdSizeXy calcZenkakuCharExtent(
		IfDcdTarget* pIfDcdTarget , const CdFontProp& aCdFontProp ) ;
	
	
	/**
	 *	縦書き文字列中に横書きテキストを描画するための CDcdText オブジェクトを
	 *	生成します。
	 * @param aCdFontProp [in]
	 *	テキストを描画する際のフォントを保持します。
	 * @param colorrefText [in]
	 *	テキストを描画する場合の文字色です。
	 */
	static CDcdText createCDcdTextH( 
		const CdFontProp&	aCdFontProp , 
		CdColorProp colorrefText ) ;
	
	/**
	 *	文字列を解釈して、『文字列要素』の集合を作成し、コンテナに追加します。
	 * @param aStr [in]
	 *	解釈する文字列を指定してください。
	 * @param pCMojiretsuyousoCont [out]
	 *	この関数はこのコンテナの末尾に、 aStr を解釈した文字列要素を
	 *	追加します。	
	 *	このコンテナがそれまで保持していた要素は破棄します。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	現在のところ、常に 0 です。
	 *
	 *
	 *	（１）　文字列を『文字列要素』に分割
	 *	
	 *	　文字列を、改行不可能な構成要素に分割します。この文書では、
	 *	これ以降この「改行不可能な構成要素」ひとつを『文字列要素』と呼びます。
	 *	
	 *	　『文字列要素』は、以下の３つの種類に区分されます。
	 *	
	 *		[V_ZENKAKU]  縦書きフォントを使って描画する、連続した全角文字
	 *		[V_HANKAKU]  縦書きフォントを使って描画する、連続した半角文字
	 *		[H_HANKAKU]  横書きフォントを使って描画する、１・２文字の半角数字
	 *			（この前後に半角文字がないこと）
	 *	
	 *	
	 *	　（例）
	 *		文字列 "京都発12／28〜1／5は、900発に変更" は、
	 *		以下の『文字列要素』に分割します。
	 *		- "京"	[V_ZENKAKU]
	 *		- "都"	[V_ZENKAKU]
	 *		- "発"	[V_ZENKAKU]
	 *		- "12" 		[H_HANKAKU]
	 *		- "／" 		[V_ZENKAKU]
	 *		- "28" 		[H_HANKAKU]
	 *		- "〜"		[V_ZENKAKU]
	 *		- "1"			[H_HANKAKU]
	 *		- "／"		[V_ZENKAKU]
	 *		- "5" 		[H_HANKAKU]
	 *		- "は、"		[V_ZENKAKU]
	 *		- "900"		[V_HANKAKU]
	 *		- "発"	[V_ZENKAKU]
	 *		- "に"	[V_ZENKAKU]
	 *		- "変"	[V_ZENKAKU]
	 *		- "更"	[V_ZENKAKU]
	 *	
	 *	　句読点の前では改行しないほうが望ましいです。このため、句読点は
	 *	前の文字の『文字列要素』の一部とします。
	 *	　連続した半角英数字の途中では改行しないほうが望ましいです。このため、
	 *	連続した半角英数字は、一つの『文字列要素』に格納するものとします。
	 *	ただし、空白や記号類が出現した場合は、そこで『文字列要素』は
	 *	終わるものとします。
	 */
	static int StringToMojiretsuyouso( 
		const string& aStr , 
		IfValueCont<CMojiretsuyouso>* pCMojiretsuyousoCont ) ;

	/**
	 *	配列に格納されている『文字列要素』の各要素の描画位置を決めます。
	 *	
	 *	この関数は、指定された高さの描画領域にテキストを縦書きで配置すると
	 *	仮定して、『文字列要素』毎のふさわしい座標を決定します。
	 *
	 *	この関数が実際の描画を行うわけではありません。この関数は行うのは
	 *	描画位置の決定だけです。
	 * @param pIfDcdTarget [in]
	 *	描画対象のデバイスコンテキストを指定してください。
	 * @param fontHorizontal [in]
	 *	描画に使用するフォントを指定してください。
	 *	ここで指定するフォントは、横書きのものでなくてはなりません。
	 * @param pCMojiretsuyousoCont [in]
	 *	『文字列要素』を格納したコンテナを指定してください。
	 * @param pCMojiretsuyousoPlaceCont [out]
	 *	この関数はこのコンテナの末尾に、
	 *	『文字列要素』ごとの描画位置を格納した CMojiretsuyousoPlace 
	 *	オブジェクトを追加します。
	 *	このコンテナがそれまで保持していた要素は破棄します。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	現在のところ、常に 0 です。
	 * @attention
	 *	pCMojiretsuyousoCont に格納されている要素の数と、
	 *	pCMojiretsuyousoPlaceCont に追加される要素の数は、同じとは限りません。
	 *	この関数が文字列要素の結合を行う場合があるからです。
	 *	\n（例） pCMojiretsuyousoCont に "京"・"都"・"発" という
	 *	要素が格納されていた場合、この３文字がもし同じ行に描画できる場合は、
	 *	この関数は『文字列要素』を結合して、一つの "京都発" という文字列要素に
	 *	します。
	 */
	static int MojiretsuyousoToMojiretsuyousoPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ,
		IfContGet<CMojiretsuyouso>* pCMojiretsuyousoCont ,
		IfCont<CMojiretsuyousoPlace>* pCMojiretsuyousoPlaceCont ) ;

	/**
	 *	配列に格納されている『文字列要素』の描画位置にしたがって、
	 *	文字列を IfDcdTarget 領域内に描画します。
	 *
	 * @param pIfDcdTarget [in]
	 *	描画対象を指定してください。
	 *	この関数は、この描画領域の左上から、縦書きでテキストを描画します。
	 * @param fontHorizontal [in]
	 *	描画に使用するフォントを指定してください。
	 *	ここで指定するフォントは、横書きのものでなくてはなりません。
	 * @param colorTextColor [in]
	 *	テキストの文字の色を指定してください。
	 * @param pCMojiretsuyousoPlaceCont [out]
	 *	『文字列要素』ごとの描画領域を格納したコンテナを指定してください。
	 * @return
	 *	描画を行ったら真・何も描画を行わなかった場合は偽です。
	 */
	static bool DcDrawMojiretsuyousoPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ,
		CdColorProp colorTextColor , 
		IfContGet<CMojiretsuyousoPlace>* pCMojiretsuyousoPlaceCont ) ;

///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param strText [in]
	 *	描画する文字列です。
	 * @param aCdFontProp [in]
	 *	テキストを描画する際のフォントを保持します。
	 * @param iLinesExtentX [in]
	 *	この描画部品に表示できる、X方向（横方向）の文字数を保持します。
	 * @param iLinesExtentY [in]
	 *	この描画部品に表示できる、Y方向（縦方向）の文字数を保持します。
	 *	 getItemSize() は、 以下の値を返します。
	 *	-	X = フォントの高さ×m_LinesExtectX 
	 *	-	Y = フォントの高さ×m_LinesExtectY 
	 * @param colorrefText [in]
	 *	テキストを描画する場合の文字色です。
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
	CDcdFillRectangleTextV2( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp ,
		int						iLinesExtentX ,
		int						iLinesExtentY ,
		CdColorProp	colorrefText = CdColorProp( 0 , 0 , 0 ) , 
		int						logicalunitFrameWidth  = 0 ,
		int						logicalunitFrameHeight = 0  ,
		const CdPenProp&		aCdPenProp = CdPenProp() ,
		const CdBrushProp& 		aCdBrushProp = CdBrushProp() ) ;

	CDcdFillRectangleTextV2() ;
	
	virtual ~CDcdFillRectangleTextV2() ;

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
	*	m_LinesExtentX m_LinesExtentY をもとに計算したテキスト領域のサイズに
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
//	CDcdFillRectangleTextV2
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	virtual CdBrushProp	getCdBrushProp(){	
		return m_CDcdFillrect.getCdBrushProp()	;	} ;
	virtual CDcdFillRectangleTextV2& setCdBrushProp( const CdBrushProp& value ){
		m_CDcdFillrect.setCdBrushProp( value ) ;	return *this ;}
	virtual CdPenProp	getCdPenProp(){	
		return m_CDcdRectangle.getCdPenProp()	;	} ;
	virtual CDcdFillRectangleTextV2& setCdPenProp( const CdPenProp& value ){
		m_CDcdRectangle.setCdPenProp( value ) ;	return *this ;}

	virtual tstring			getText(){	
		return m_strText ;	} ;
	virtual CDcdFillRectangleTextV2& setText( const tstring& value ){	
		m_strText = value ; 	return *this ; } ;

	virtual CdFontProp	getCdFontProp(){
		return m_CdFontProp ;};
	virtual CDcdFillRectangleTextV2& setCdFontProp( 
			const CdFontProp& value ){
		m_CdFontProp = value ; return *this ; } ;

	virtual int				getLinesExtentX(){
		return m_iLinesExtentX ; } ;
	virtual CDcdFillRectangleTextV2& setLinesExtentX( int value ){
		m_iLinesExtentX = value ; 	return *this ; } ;
	virtual int				getLinesExtentY(){
		return m_iLinesExtentY ; } ;
	virtual CDcdFillRectangleTextV2& setLinesExtentY( int value ){
		m_iLinesExtentY = value ; 	return *this ; } ;

	virtual CdColorProp	getTextColor(){	
		return m_colorrefText ;	};
	virtual CDcdFillRectangleTextV2& setTextColor( CdColorProp value ){
		m_colorrefText = value ; return *this ; } ;

	virtual int	getFrameWidth(){	return m_logicalunitFrameWidth ;};
	virtual CDcdFillRectangleTextV2& setFrameWidth( int value ){
		m_logicalunitFrameWidth = value ;	return *this ; } ;

	virtual int	getFrameHeight(){	return m_logicalunitFrameHeight ;};
	virtual CDcdFillRectangleTextV2&  setFrameHeight( int value ){
		m_logicalunitFrameHeight = value ;	return *this ; } ;
	///@}
};


#endif /*CDcdFillRectangleTextV2_h*/
