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
//	str\strToWstr.cpp
//	$Id: strToWstr.cpp 343 2016-08-07 12:13:10Z okm $
// ****************************************************************
*/

#include "str\strToWstr.h"
#include <windows.h>
#include <vector>


namespace OuLib {
namespace Str {

// ****************************************************************
//	TCHARとマルチバイト・ワイド文字の変換
// ****************************************************************
std::string stringOf( std::string strEs ) 
{
	return ( strEs ) ;
}

std::string stringOf( std::wstring strEs )
{
	std::string strUtf8 ;
	if ( !utf8Of( strEs , &strUtf8 ) )
	{
		return std::string() ;
	}
	return strUtf8 ;
}


std::string stringOf( const void* lpvEStr , int iESize ) 
{
	if ( IsTextUnicode( (CONST LPVOID)lpvEStr , iESize , NULL ) ){
		return( stringOf( (LPCWSTR)lpvEStr ) );
	}
	return ( stringOf( (LPCSTR)lpvEStr ) ) ;
}

std::wstring wstringOf( std::string strEs )
{
	std::wstring strWide ;
	if ( !wstringFromUtf8( strEs , &strWide ) )
	{
		return std::wstring() ;
	}
	return strWide ;
}
std::wstring wstringOf( std::wstring strEs ) 
{
	return ( strEs ) ;
}

// UTF-8 conversion helpers. These are deliberately separate from stringOf()
// and wstringOf(), which now use UTF-8 independently of the system code page.
bool utf8Of( const std::wstring& strEs , std::string* pstrUtf8 )
{
	if ( pstrUtf8 == NULL )
	{
		return false ;
	}
	pstrUtf8->clear() ;
	if ( strEs.empty() )
	{
		return true ;
	}
	if ( strEs.size() > 0x7fffffff )
	{
		return false ;
	}
	int iBytes = WideCharToMultiByte( CP_UTF8 , WC_ERR_INVALID_CHARS ,
		strEs.data() , (int)strEs.size() , NULL , 0 , NULL , NULL ) ;
	if ( iBytes <= 0 )
	{
		return false ;
	}
	std::vector<char> szUtf8( iBytes ) ;
	if ( WideCharToMultiByte( CP_UTF8 , WC_ERR_INVALID_CHARS ,
		strEs.data() , (int)strEs.size() , &szUtf8[0] , iBytes ,
		NULL , NULL ) != iBytes )
	{
		return false ;
	}
	pstrUtf8->assign( &szUtf8[0] , iBytes ) ;
	return true ;
}

bool wstringFromUtf8( const std::string& strUtf8 , std::wstring* pstrEs )
{
	if ( pstrEs == NULL )
	{
		return false ;
	}
	pstrEs->clear() ;
	if ( strUtf8.empty() )
	{
		return true ;
	}
	if ( strUtf8.size() > 0x7fffffff )
	{
		return false ;
	}
	int iChars = MultiByteToWideChar( CP_UTF8 , MB_ERR_INVALID_CHARS ,
		strUtf8.data() , (int)strUtf8.size() , NULL , 0 ) ;
	if ( iChars <= 0 )
	{
		return false ;
	}
	std::vector<wchar_t> szWide( iChars ) ;
	if ( MultiByteToWideChar( CP_UTF8 , MB_ERR_INVALID_CHARS ,
		strUtf8.data() , (int)strUtf8.size() , &szWide[0] , iChars ) != iChars )
	{
		return false ;
	}
	pstrEs->assign( &szWide[0] , iChars ) ;
	return true ;
}

std::wstring wstringOf( const void* lpvEStr , int iESize ) 
	//	ワイドかマルチバイトか分からない文字列をワイド文字列に変換します
{
	if ( IsTextUnicode( (CONST LPVOID)lpvEStr , iESize , NULL ) ){
		return( wstringOf( (LPCWSTR)lpvEStr ) );
	}
	return ( wstringOf( (LPCSTR)lpvEStr ) ) ;
}

} //namespace Str 
} //namespace OuLib 

