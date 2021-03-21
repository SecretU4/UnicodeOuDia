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
//	CConnectedStringCompress.h
// ****************************************************************
*/
/** @file */
#ifndef  CConnectedStringCompress_h
#define  CConnectedStringCompress_h

#include <string>
#include "str/CdConnectedString2.h"

namespace OuLib{
namespace Str{

// ****************************************************************
//	CConnectedStringCompress
// ****************************************************************
/**
@brief
【概要】
  CdConnectedString2 オブジェクトが保持している内容を、文字列に変換します。このとき、『項目名』の『サブアイテム』部分を圧縮します。変換した文字列を解釈する機能も持ちます。

  このクラスは、 CdConnectesString2 の内容を、文字列に変換します。この点は、 CdConnectedString::encode() と同じですが、『項目名』の『サブアイテム』が重複している場合は、重複している『サブアイテム』の記述を省略することにより、文字列のサイズを減らします。
特に、『サブアイテム』の数が多く、入れ子のレベルが深い場合、サイズの削減効果が大きくなります。

  このクラスが使用できる CdConnectedString2 には、以下の条件があります。


１．  すべての『項目名』は、共通の『サブアイテム階層区切り文字』（『サブアイテム』の階層のを区切る、１バイトの文字）を持たなくてはなりません。

<H5>
（例）
</H5>
  以下は、『サブアイテム階層区切り文字』を "." とした『項目名』の例です
（アイテム間の区切り文字=改行・項目と値の間の区切り文字="="）。

@code
Itemname0=Value0
Subitem1.Itemname1=Value1
Subitem1.Subitem2.Itemname2=Value2
Subitem1.Subitem2.Itemname3=Value3
Subitem1.Subitem3.Itemname4=Value4
@endcode

【このクラスが生成する文字列】

  文字列の作成においては、『カレントサブアイテム』の概念を取り入れます。
  サブアイテムに属するアイテムを文字列化する際は、

１．  『カレントサブアイテム』を、出力するサブアイテムに入場させて、

２．  サブアイテム名を取り除いた項目名と値を書き込む。

３．  サブアイテムに属する項目名・値をすべて書き込んだら、『カレントサブアイテム』は、そのサブアイテムから退場する。

という順序をとります。

  『カレントサブアイテム』の入場は、スタックの形をとります。たとえば、

１．  『カレントサブアイテム』を "Subitem1" に入場させる。

２．  『カレントサブアイテム』を "Subitem2"
 （ "Subitem1" の下の "Subitem2" ）に入場させる。

３．  『カレントサブアイテム』を退場させる（"Subitem2" からの退場）。

  このときの『カレントサブアイテム』は、"Subitem1" となります。


  『カレントサブアイテム』を、サブアイテムに入場させる際は、文字列として『カレントサブアイテム入場コマンド』を出力します。
  これは、以下の形式となります。

  <B>
  サブアイテム名＋『サブアイテム階層区切り文字』＋『アイテム間の区切り文字』
  </B>

<H5>
（例）
</H5>
（サブアイテム階層区切り文字="." ・アイテム間の区切り文字=改行・項目と値の間の区切り文字="="）
@code
Subitem1.
@endcode

  『カレントサブアイテム』を、サブアイテムから退場させる際は、文字列として『カレントサブアイテム退場コマンド』を出力します。
  これは、以下の形式となります。

  <B>
  『サブアイテム階層区切り文字』＋『アイテム間の区切り文字』
  </B>

<H5>
（例）
</H5>
（サブアイテム階層区切り文字="." ・アイテム間の区切り文字=改行・項目と値の間の区切り文字="="）
@code
.
@endcode

<H5>
（例）
</H5>

  以下のようなアイテムを出力する場合を想定します。(151バイト)（サブアイテム階層区切り文字="." ・アイテム間の区切り文字=改行・項目と値の間の区切り文字="="）

@code
Itemname0=Value0
Subitem1.Itemname1=Value1
Subitem1.Subitem2.Itemname2=Value2
Subitem1.Subitem2.Itemname3=Value3
Subitem1.Subitem3.Itemname4=Value4
@endcode

このときの出力内容は、以下のようになります( カッコで囲まれている部分は、説明のコメントです。実際の文字列には含まれません)。

@code
（カレントサブアイテム＝""）
Itemname0=Value0
Subitem1.
（カレントサブアイテム＝"Subitem1."）
Itemname1=Value1
Subitem2.
（カレントサブアイテム＝"Subitem1.Subitem2."）
Itemname2=Value2
Itemname3=Value3
.
（カレントサブアイテム＝"Subitem1."）
Subitem3.
（カレントサブアイテム＝"Subitem1.Subitem3."）
Itemname4=Value4
@endcode

コメントを除いた最終結果は、以下のようなものです（124バイト）。

@code
Itemname0=Value0
Subitem1.
Itemname1=Value1
Subitem2.
Itemname2=Value2
Itemname3=Value3
.
Subitem3.
Itemname4=Value4
@endcode



【使い方１- CdConnectedString2 に格納されている内容を文字列化】

１．  コンストラクタでは、

  - サブアイテム階層区切り文字(既定値=".")

を指定してください。

２．  文字列化するアイテムを保持している CdConnectedString2 オブジェクトの

 - CdConnectedString2::m_chSplit にアイテム間の区切り文字・
 - CdConnectedString2::m_chEqualChar に『項目と値の間の区切り文字』
 - CdConnectedString2::m_bEncodeNoValue

を指定してください。

３．  encode() を呼び出すことにより、文字列を作成することができます。


【使い方２- encode() で作成した文字列を解釈】

１．  コンストラクタでは、

  - サブアイテム階層区切り文字(既定値=".")

を指定してください。

２．  文字列を解釈した内容を格納する CdConnectedString2 オブジェクトの

 - CdConnectedString2::m_chSplit にアイテム間の区切り文字・
 - CdConnectedString2::m_chEqualChar に『項目と値の間の区切り文字』

を指定してください。

３．  decode() を呼び出してください。この関数は、文字列を解釈して、 CdConnectedString2 に格納します。
*/
class CConnectedStringCompress
{
// ********************************
///@name 属性
// ********************************
 private:
	/**
	 *	サブアイテム階層区切り文字(既定値=".")
	 */
	char		m_chSubitemSeparater ;
	
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param chSubitemSeparater [in]
	 *	サブアイテム階層区切り文字(既定値=".") 
	 */
	CConnectedStringCompress( 
		char chSubitemSeparater = '.' );
	virtual ~CConnectedStringCompress();
	
	
// ********************************
//	CConnectedStringCompress
// ********************************
 public:
	// ********************************
	///@name CConnectedStringCompress-属性
	// ********************************
	virtual char getSubitemSeparater()const ;
	virtual CConnectedStringCompress& setSubitemSeparater( char value ) ;
	// ********************************
	///@name CConnectedStringCompress-操作
	// ********************************
	/**
	 *	CdConnectedString2 に格納されている内容を文字列化します。
	 *
	 *	文字列化する前に aCdConnectedString2 に
	 *
	 *	- CdConnectedString2::m_chSplit
	 *	- CdConnectedString2::m_chEqualChar
	 *	- CdConnectedString2::m_bEncodeNoValue
	 *
	 *	を設定していなくてはなりません。
	 * @param aCdConnectedString2 [in]
	 *	文字列化するアイテムを保持しているオブジェクトを指定してください。
	 * @return
	 *	文字列化した内容を返します。
	 */
	virtual std::string encode( const CdConnectedString2& aCdConnectedString2 ) ;

	/**
	 *	encode() で作成した文字列を解釈し、その内容を
	 *	 CdConnectedString2 に格納します。
	 *
	 *	関数実行前に、 pCdConnectedString2 に
	 *
	 *	- CdConnectedString2::m_chSplit
	 *	- CdConnectedString2::m_chEqualChar
	 *
	 *	を設定していなくてはなりません。
	 * @param aStr [in]
	 *	解釈する文字列を指定してください。
	 * @param pCdConnectedString2 [out]
	 *	この関数はこのオブジェクトに、解釈した内容を追加します。
	 *	このオブジェクトがそれまで保持していたデータは維持します。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。
	 */
	virtual int decode( const std::string& aStr , 
		CdConnectedString2* pCdConnectedString2 ) ;
};

} //namespace Str{
} //namespace OuLib{

#endif /*CConnectedStringCompress_h*/



