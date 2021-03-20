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
//	strLf.cpp
// ****************************************************************
*/
#include "str\strLf.h"

namespace OuLib{


//	文字列中の、"\r\n" を "\n" に変換します。
//	文字列中の、"\n" に対しては、何もしません。
//[in]strEv 
//	変換元文字列
//[retval]
//	変換後の文字列
std::string strLfOf( const std::string& strEv ) 
{
	std::string	strRv ;
	std::string::const_iterator	iteSrc = strEv.begin() ;

	//	領域を予約
	strRv.reserve( strEv.size() ) ;
	
	for ( ; iteSrc != strEv.end() ; iteSrc ++ ){
		if ( *iteSrc == '\r' && 
				iteSrc + 1 != strEv.end() && 
				*( iteSrc + 1 ) == '\n' ){
			//	"\r\n" をみつけました。
			strRv += '\n' ;
			iteSrc ++ ;
		}	else if ( *iteSrc == '\n' ){
			//	"\n" をみつけました。
			strRv += '\n' ;
		}	else	{
			//	その他の文字列
			strRv += *iteSrc ;
		}
	}
	return ( strRv ) ;
}

//	文字列中の、"\n" を "\r\n" に変換します。
//	文字列中の、"\r\n" に対しては、何もしません。
//[in]strEv 
//	変換元文字列
//[retval]
//	変換後の文字列
std::string strCrlfOf( const std::string& strEv ) 
{
	std::string	strRv ;
	std::string::const_iterator	iteSrc = strEv.begin() ;

	//	1行を平均20文字程度と仮定して、領域を予約
	strRv.reserve( strEv.size() * 21 / 20 ) ;

	for ( ; iteSrc != strEv.end() ; iteSrc ++ ){
		if ( *iteSrc == '\r' && 
				iteSrc + 1 != strEv.end() && 
				*( iteSrc + 1 ) == '\n' ){
			//	"\r\n" をみつけました。
			strRv += "\r\n" ;
			iteSrc ++ ;
		}	else if ( *iteSrc == '\n' ){
			//	"\n" をみつけました。
			strRv += "\r\n" ;
		}	else	{
			//	その他の文字列
			strRv += *iteSrc ;
		}
	}
	return ( strRv ) ;
}

/*
* 	文字列中の左側・あるいは右側の、連続した空白類の文字を削除します。
* @param strEv [in]
* 	変換元文字列
* @param bLeft [in]
* 	真なら、左側の空白類を削除します。
* @param bRight [in]
* 	真なら、右側の空白類を削除します。
* @param strSpaces [in]
* 	空白類とみなす文字を並べた文字列を指定してください。
*   この関数は、この文字列に含まれていない文字は、空白とはみなしません。
* @return
* 	削除後の文字列
*/
std::string strTrim( const std::string& strEv , 
						bool bLeft , 
						bool bRight , 
						const std::string& strSpaces ) 
{
	std::string	strRv = strEv ;
	
	//	Left
	if ( bLeft ){
		std::string::size_type	pos = strRv.find_first_not_of( strSpaces ) ;
		if ( pos != std::string::npos ){
			strRv = strRv.substr( pos ) ;
		}
	}
	
	//	right
	if ( bRight ){
		std::string::size_type	pos = strRv.find_last_not_of( strSpaces ) ;
		if ( pos != std::string::npos ){
			strRv = strRv.substr( 0 , pos + 1 ) ;
		}
	}
	return ( strRv ) ;
}




} ;
