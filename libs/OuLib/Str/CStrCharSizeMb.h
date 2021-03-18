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
//	CStrCharSizeMb.h
// ****************************************************************
*/

/** @file CStrCharSizeMb.h */

#ifndef  CStrCharSizeMb_h
#define  CStrCharSizeMb_h
#include <string>
#include <vector>

namespace OuLib{
namespace Str{

// ****************************************************************
//	CStrCharSizeMb
// ****************************************************************
/**
 *	@brief 
 *	 【概要】
 *		与えられたマルチバイト文字列の各文字が何バイトであるかを調べ、
 *		テーブルに保持します。
 *		そのテーブルを使い、バイト単位のインデクスと文字単位のインデクスの
 *		変換・指定の文字のバイト数の調査などのサービスを提供します。
 *	
 *	１．	バイト単位のインデクス(string や char* の[]の添字)と
 *		文字単位のインデクス（2バイト文字も１バイト文字も１文字と数えたとすれば
 *		先頭から何文字目になるか）の相互変換
 *
 *	２．  指定のインデクス（バイト単位インデクス・文字単位インデクス両方を
 *		サポート）の文字は何バイト文字かを調べる
 *
 *	３．  バイト単位インデクスを、次の文字に進める（１バイト文字なら＋１、２
 *		バイト文字なら＋２）。
 *		これにより、文字列内の文字をサーチするループが実現できます。
 *
 *	  このクラスでは、メンバ関数名などに、以下の略語を使用しています。
 *	
 *	-	Bidx...  文字列内の文字の、先頭からのバイト単位のインデクス（０起点）。
 *		    （例："京都a市" の "市" は 5 となります。）
 *	-	Cidx...  文字列内の文字の、先頭からの文字単位のインデクス（０起点）。
 *			2バイト文字も１バイト文字も１文字と数えます
 *		    （例："京都a市" の "市" は 3 となります。）
 *	-	Csize...  文字列内の文字の、バイト数。
 *		    （例："京都a市" の "市" は 2 となります。）
 *	
 *	
 *	【使い方】
 *	
 *	１．  コンストラクタか scan() で、文字列を指定してください。
 *		this は、その文字列の各文字のバイト数を解析し、テーブルを作成します。
 *		これ以後、このテーブルは次の scan() まで有効です。
 *	
 *	２．  あとは、すべてのメンバ関数が使用可能です。
 *
 * @b 文字単位で表示を行う例
 * @code
 	string	aStr( "京都a市" ) ; 
	CStrCharSizeMb	aStrCharSize( aStr ) ;
 	{
 		for ( int idx = 0 ; idx < aStrCharSize.ByteLength() ; ){
 			cout << aStr.substr( idx , aStrCharSize.CsizeOfBidx( idx ) ) << " " ;
 			idx = aStrCharSize.BidxNextChar( idx ) ;
 		}
 		cout << endl ;
	}
 @endcode
*/
class CStrCharSizeMb
{
// ********************************
///@name	属性
// ********************************
///@{
 private:
	/**
	 * @brief 文字列の各文字のバイト数にもとずいたテーブルです
	 *
	 *	コンストラクタ・または最近の scan() で指定された文字列の各文字の
	 *	Bidx を保持します。
	 *	配列の要素数は、（文字列の文字数（２バイト文字も１と数えて）＋１）
	 *	となり、末尾には、 '\0' の Bidx がつきます。
	 *	初期状態は [0] に 0 だけが設定された状態です。
	 *
	 *	例："京都a市" を scan() に渡すと、配列は	
	 *	-	[0]=0	//	京	
	 *	-	[1]=2	//	都	
	 *	-	[2]=4	//	a	
	 *	-	[3]=5	//	市
	 *	-	[4]=7	//	"\0"
	 *
	 *	となります。
	 */
	std::vector<int>	m_ariBidx ;
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 */
	CStrCharSizeMb() ;
	
	/**
	 * @param ev [in]
	 *	この文字列を scan() に渡し、テーブルを構成します。
	 */
	CStrCharSizeMb( const std::string& ev ) ;
	
// ********************************
//	CStrCharSizeMb
// ********************************
 public:
	/**
	 * @param ev [in]
	 *	この文字列をスキャンして、テーブルを構成します。
	 *	それまでのテーブルの内容は破棄します。
	 */
	CStrCharSizeMb& scan( const std::string& ev ) ;
	
	/**
	 * @return
	 * 	スキャンした文字列の、バイト単位での長さを返します。
	 * 	    （例："京都a市" なら 7 となります。）
	 */
	int ByteLength()const ;
	
	/**
	 * @return
	 * 	スキャンした文字列の、文字単位での長さを返します。
	 * 	    （例："京都a市" なら 4 となります。）
	 */
	int CharLength()const ;
	
	/**
	 * 	バイト単位のインデクスから文字単位のインデクスに変換します
	 * @param iBidx [in]
	 * 	バイト単位のインデクスを指定してください。
	 * @param piOffset [out]
	 * 	この関数は、iBidx の、文字の先頭からのオフセットを書き込みます。
	 *	この値が0であれば、iBidx は文字の先頭バイトを指すインデクスです。
	 *	1なら、 iBidx は文字の2バイト目を指していることを意味します。
	 *	不要であれば、NULLを指定してもかまいません。
	 * @return
	 * 	文字単位のインデクスを返します。
	 * 	- iBidx が負の数	: -1を返します。
	 *		この場合、*piOffsetは0です。
	 * 	- iBidx が ByteLength() 以上 : CharLength() を返します。
	 *		この場合、*piOffsetは0です。
	 * 	- iBidx が文字の1バイト目以外を指している場合でも、その文字の
	 *		文字単位のインデクスを返します。
	 *	
	 * 	（例："京都a市" )
	 *	iBidx に 5('市') を指定すると、戻り値は 3 ・*piOffsetは0となります。
	 * 	6('市'の２バイト目)を指定すると、戻り値は 3 ・*piOffsetは1となります。
	 */
	int CidxOfBidx( int iBidx , int* piOffset = NULL )const ;
	
	/**
	 * 	文字単位のインデクスからバイト単位のインデクスに変換します
	 * @param iCidx [in]
	 * 	文字単位のインデクスを指定してください。
	 * @return 
	 * 	バイト単位のインデクスを返します。
	 * 	    （例："京都a市" なら iCidx に 3('市') を指定すると、戻り値は 5 と
	 * 		なります。）
	 * 	- iCidx が負の数	: -1を返します。
	 * 	- iCidx が CharLength() 以上 : ByteLength() を返します。
	 */
	int BidxOfCidx( int iCidx )const ;
	
	/**
	 * 	バイト単位のインデクスで指定された文字のバイト数を調べます。
	 * @param iBidx [in]
	 * 	バイト単位のインデクスを指定してください。
	 * @return
	 * 	文字のバイト数を返します。
	 * 	    （例："京都a市" なら iBidx に 5('市') を指定すると、戻り値は 2 と
	 * 		なります。6を指定すると0を返します。）
	 * 	- iBidx が負の数/文字の２バイト目/ByteLength() 以上 : 0を返します。
	 */
	int CsizeOfBidx( int iBidx )const ;
	
	/**
	 * 	文字単位のインデクスで指定された文字のバイト数を調べます。
	 * @param iCidx [in]
	 * 	文字単位のインデクスを指定してください。
	 * @return
	 * 	文字のバイト数を返します。
	 * 	    （例："京都a市" なら iCidx に 3('市') を指定すると、戻り値は 2 と
	 * 		なります。）
	 * 	- iCidx が負の数/CharLength() 以上 : 0を返します。
	 */
	int CsizeOfCidx( int iCidx )const ;
	
	/**
	 * 	バイト単位のインデクスで指定された文字の１文字後ろの文字の、
	 * 	バイト単位インデクスを調べます。
	 * 	引数の指定により、２文字以上後ろ・あるいは前の文字のインデクスを
	 * 	求めることもできます。
	 * @param iBidx [in]
	 * 	バイト単位のインデクスを指定してください。
	 * @param iCharOffset [in]
	 * 	文字単位でのオフセットを指定してください。
	 * 	+1 なら、iBidx の 1文字後ろ、 -1 なら１文字前を指定したことに
	 * 	なります。
	 * @return
	 * 	iCharOffset 文字だけ移動した先の文字の、
	 * 	バイト単位のインデクスを返します。
	 * 	    （例："京都a市" なら iBidx に 2('都') ,iCharOffset に 1 を
	 * 		指定すると、戻り値は 4 'a' となります。）
	 * 	- 移動先が先頭文字より前になる: -1を返します。
	 * 	- 移動先が文字列末尾に達する : ByteLength() を返します。
	 */
	int BidxNextChar( int iBidx , int iCharOffset = 1 )const ;

	/**
	 * 	最後の文字の、文字単位のインデクスを返します。
	 * @return
	 * 	文字単位のインデクスを返します。
	 * 	    （例："京都a市" なら  3 となります。）
	 * 	空文字列の場合は-1を返します。
	 */
	int CidxLast()const ;
	
	/**
	 * 	最後の文字の、バイト単位のインデクスを返します。
	 * @return
	 * 	バイト単位のインデクスを返します
	 * 	    （例："京都a市" なら  5 となります。）。
	 * 	空文字列の場合は-1を返します。
	 */
	int BidxLast()const ;

	/**
	 * 	半角文字・全角文字が混在した文字列のなかの
	 *	全角文字を、半角文字に変換します。
	 * @param strEv [in]
	 *  変換元文字列
	 * @param piResult [out]
	 *	この関数は、成功したら 0 以上、エラーなら負の数を書き込みます。
	 *	不要なら NULL でもかまいません。
	 *  - 1 ;	//	変換に成功しました。
	 *  - 0 ;	//	変換の必要な全角文字は、ひとつもありませんでした。
	 *	- -1 ;	//	半角に変換できない全角文字がありました。
	 *
	 * @return
	 * 	変換後の文字列
	 *
	 * @attention  
	 *	この関数は、変換元文字列に、半角文字に変換不可能な全角文字が
	 *	含まれていた場合( *piResult == -1 の場合)、
	 *	文字列中の変換可能な全角文字をすべて変換し、変換不可能な全角文字は
	 *	そのまま残した文字列を返します。
	 * @attention  
	 *	濁点つきのカタカナは、半角カタカナ＋半角濁点の組み合わせとします。
	 *	(例) 
	 *	"ガ" → "ｶﾞ" となります。
	 */
	static std::string strToSingleByte( const std::string& strEv , 
						int* piResult = NULL ) ;

	/**
	 * 	半角文字・全角文字が混在した文字列の
	 *	半角文字を、全角文字に変換します。
	 * @param strEv [in]
	 *  変換元文字列
	 * @param piResult [out]
	 *	この関数は、成功したら 0 以上、エラーなら負の数を書き込みます。
	 *	不要なら NULL でもかまいません。
	 *  - 1 ;	//	変換に成功しました。
	 *  - 0 ;	//	変換の必要な全角文字は、ひとつもありませんでした。
	 *	- -1 ;	//	全角に変換できない半角文字がありました。
	 *
	 * @return
	 * 	変換後の文字列
	 *
	 * @attention  
	 *	この関数は、変換元文字列に、全角に変換不可能な半角文字が
	 *	含まれていた場合( *piResult == -1 の場合)、
	 *	文字列中の変換可能な半角文字をすべて変換し、変換不可能な半角文字は
	 *	そのまま残した文字列を返します。
	 * @attention  
	 *	半角カタカナ＋半角濁点の組み合わせは、１つの全角文字とします。\n
	 *	(例) 
	 *	"ｶﾞ" → "ガ" となります( "カ゛" ) にはなりません。
	 */
	static std::string strToDoubleByte( const std::string& strEv , 
						int* piResult = NULL ) ;


};

} //namespace Str{
} //namespace OuLib{



#endif /*CStrCharSizeMb_h*/
