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
//	CVerticalTextElementBuilder.h
// ****************************************************************
*/
/** @file */
#ifndef  DcDrawLib_DcDraw_CVerticalTextElementBuilder_h
#define  DcDrawLib_DcDraw_CVerticalTextElementBuilder_h

#include "DcDraw\CVerticalTextElement.h"
#include "NsMu\Mui.h"

namespace DcDrawLib{
namespace DcDraw{
	using namespace OuLib::NsMu ;
	using namespace std ;

/**
@brief
	テキストを解釈して、縦書き時のテキスト構成をする要素を表す、単純データクラスです。
	
	CVerticalTextElementBuilder::scan() メソッドは、文字列を解析し、
	解析結果を CVerticalTextElement のコンテナとして構成します。
*/
class CVerticalTextElementBuilder
{
protected:
	// ================================
	///@name 下請関数
	// ================================
	///@{
	/**
		文字が空白(全角・半角)か否かを判断します。
	@param aStr [in]
		判断を行う文字を指定してください。
	@return
		- true: aStr は 空白(全角・半角)です。
	*/
	static bool isSpace( const string& aStr );

	/**
		文字が句読点類( , . 、。)か否かを判断します。
	@param aStr [in]
		判断を行う文字を指定してください。
	@return
		- true: aStr は 句読点です。
	*/
	static bool isDelimiter( const string& aStr );
	///@}
public:
	// ********************************
	///@name CVerticalTextElementBuilder-操作
	// ********************************
	///@{
	/**
	  	文字列を解釈して、『文字列要素』の集合を作成し、コンテナに追加します。
	@param aStr [in]
	  	解釈する文字列を指定してください。
	@param pCStrElementCont [out]
	  	この関数はこのコンテナの末尾に、 aStr を解釈した文字列要素を
	  	追加します。	
	  	このコンテナがそれまで保持していた要素は破棄します。
	@param bTwoDegiLateral [in]
		- true: 2文字の半角数字を、 [H_HANKAKU] とします。
		- false: 2文字の半角数字を、[V_HANKAKU] とします。
	  
	  
	  	（１）　文字列を『文字列要素』に分割
	  	
	  	　文字列を、改行不可能な構成要素に分割します。この文書では、
	  	これ以降この「改行不可能な構成要素」ひとつを『文字列要素』と呼びます。
	  	
	  	　『文字列要素』は、以下の３つの種類に区分されます。
	  	
	  		- [V_ZENKAKU]  縦書きフォントを使って描画する、連続した全角文字
	  		- [V_HANKAKU]  縦書きフォントを使って描画する、連続した半角文字
	  		- [H_HANKAKU]  横書きフォントを使って描画する、１・２文字の半角数字
	  			（この前後に半角文字がないこと）
	  	
	  	
	  	　（例）bTwoDegiLateral=true の場合
	  		文字列 "京都発12／28〜1／5は、900発に変更" は、
	  		以下の『文字列要素』に分割します。
	  		- "京"	[V_ZENKAKU]
	  		- "都"	[V_ZENKAKU]
	  		- "発"	[V_ZENKAKU]
	  		- "12" 		[H_HANKAKU]
	  		- "／" 		[V_ZENKAKU]
	  		- "28" 		[H_HANKAKU]
	  		- "〜"		[V_ZENKAKU]
	  		- "1"			[H_HANKAKU]
	  		- "／"		[V_ZENKAKU]
	  		- "5" 		[H_HANKAKU]
	  		- "は、"		[V_ZENKAKU]
	  		- "900"		[V_HANKAKU]
	  		- "発"	[V_ZENKAKU]
	  		- "に"	[V_ZENKAKU]
	  		- "変"	[V_ZENKAKU]
	  		- "更"	[V_ZENKAKU]
	  	
	  	　句読点の前では改行しないほうが望ましいです。このため、句読点は
	  	前の文字の『文字列要素』の一部とします。
	  	　連続した半角英数字の途中では改行しないほうが望ましいです。このため、
	  	連続した半角英数字は、一つの『文字列要素』に格納するものとします。
	  	ただし、空白や記号類が出現した場合は、そこで『文字列要素』は
	  	終わるものとします。
	 */
	static void scan( 
		const std::string& aStr , 
		Mui<CVerticalTextElement>* muCVerticalTextElement ,
		bool bTwoDegiLateral = true ) ;

	///@}
};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*DcDrawLib_DcDraw_CVerticalTextElementBuilder_h*/



