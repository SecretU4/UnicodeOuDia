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
//	strLf.h
// ****************************************************************
*/
/** @file 
*	@brief
* 【概要】
* 	文字列の簡単な加工を行う関数群を収録しています。
*
*	以下のような関数群が含まれます。
*	- 改行文字を "\r\n" と "\n" との間で変換する関数群。
*	- 先頭末尾の空白類を除去する関数
*	- 半角・全角混在文字列を、半角のみ・全角のみに変換する関数
*/

#ifndef  strLf_h
#define  strLf_h
#include <string>

#ifndef  NO_OuLib_NAMESPACE
/** @namespace
*/
namespace OuLib{
#endif /*NO_OuLib_NAMESPACE*/

/**
* 	文字列中の、 "\r\n" を "\n" に変換します。
* 	文字列中の、 "\n" に対しては、何もしません。
* @param strEv [in]
* 	変換元文字列
* @return
* 	変換後の文字列
*/
std::string strLfOf( const std::string& strEv ) ;

/**
* 	文字列中の、 "\n" を "\r\n" に変換します。
* 	文字列中の、 "\r\n" に対しては、何もしません。
* @param strEv [in]
* 	変換元文字列
* @return
* 	変換後の文字列
*/
std::string strCrlfOf( const std::string& strEv ) ;

/**
* 	文字列中の左側・あるいは右側の、連続した空白類の文字を削除します。
* @param strEv [in]
* 	変換元文字列
* @param bLeft [in]
* 	真なら、左側の空白類を削除します。
* @param bRight [in]
* 	真なら、右側の空白類を削除します。
* @param strSpaces [in]
* 	空白類とみなす文字を並べた文字列を指定してください。
*   この関数は、この文字列に含まれている文字を、空白とみなします。
*   デフォルトでは、半角スペースと "\r" "\n" "\t" です 
*	２バイト文字を含めることはできません。
* @return
* 	削除後の文字列
* @attention  
*   この関数は処理に際して、２バイト文字に対する考慮を特に行っていません。
*	このため、 strEv に２バイト文字を含む文字列を指定し、
*	strSpaces に２バイト文字の第２バイトになりえる文字を含めた場合( '\\' など)
*	正しく処理されません。
*/
std::string strTrim( const std::string& strEv , 
						bool bLeft = true , 
						bool bRight = true , 
						const std::string& strSpaces = " \r\n\t" ) ;


#ifndef  NO_OuLib_NAMESPACE
};
#endif /*NO_OuLib_NAMESPACE*/

#endif /*strLf_h*/
