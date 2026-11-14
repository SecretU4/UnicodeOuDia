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
//	CVerticalTextElementBuilder.cpp
// ****************************************************************
*/
#include "DcDraw\CVerticalTextElementBuilder.h"
#include "LogMsg\logmsg.h"
#include "Str\Str.h"

namespace DcDrawLib{
namespace DcDraw{
	using namespace OuLib::Str;
	using namespace std ;



bool CVerticalTextElementBuilder::isSpace( const std::wstring& aStr )
{
	const wchar_t* const kyoukai[] = {
		L" " , L"　",
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ )
	{
		if ( aStr == kyoukai[idx] ) return true ;
	}
	return false ;
}

bool CVerticalTextElementBuilder::isDelimiter( const std::wstring& aStr )
{
	const wchar_t* const kyoukai[] = {
		L"," , L"，" ,
		L"." , L"．" ,
		L"。" ,
		L"、" ,
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ )
	{
		if ( aStr == kyoukai[idx] ) return true ;
	}
	return false ;
}

static size_t utf16CharLengthAt( const std::wstring& str , size_t idx )
{
	if ( idx + 1 < str.size() &&
		str[idx] >= 0xd800 && str[idx] <= 0xdbff &&
		str[idx + 1] >= 0xdc00 && str[idx + 1] <= 0xdfff )
	{
		return 2 ;
	}
	return 1 ;
}

static bool isHalfWidthCharacter( wchar_t ch )
{
	return ch <= 0x007f || ( ch >= 0xff61 && ch <= 0xff9f ) ;
}

static bool isAsciiDigitString( const std::wstring& str )
{
	if ( str.empty() || str.size() > 2 ) return false ;
	for ( size_t idx = 0 ; idx < str.size() ; idx ++ )
	{
		if ( str[idx] < L'0' || str[idx] > L'9' ) return false ;
	}
	return true ;
}

void CVerticalTextElementBuilder::scan(
		const std::wstring& aStr ,
		Mui<CVerticalTextElement>* muCVerticalTextElement ,
		bool bTwoDegiLateral )
{
	muCVerticalTextElement->erase( 0 , INT_MAX ) ;

	for ( size_t idx = 0 ; idx < aStr.size() ; )
	{
		const size_t cch = utf16CharLengthAt( aStr , idx ) ;
		const std::wstring strChar = aStr.substr( idx , cch ) ;
		CVerticalTextElement aElementPrev ;
		if ( muCVerticalTextElement->size() > 0 )
		{
			aElementPrev = muCVerticalTextElement->get( INT_MAX ) ;
		}

		if ( isHalfWidthCharacter( aStr[idx] ) )
		{
			std::wstring strCharPrev ;
			if ( !aElementPrev.isNull() && !aElementPrev.getString().empty() )
			{
				strCharPrev = aElementPrev.getString().substr(
					aElementPrev.getString().size() - 1 , 1 ) ;
			}
			if ( !isSpace( strChar ) &&
				!aElementPrev.isNull() &&
				aElementPrev.getType() == CVerticalTextElement::V_HANKAKU &&
				!isDelimiter( strCharPrev ) && !isSpace( strCharPrev ) )
			{
				aElementPrev.setString( aElementPrev.getString() + strChar ) ;
				muCVerticalTextElement->set( aElementPrev , INT_MAX ) ;
			}
			else
			{
				CVerticalTextElement aElement(
					strChar , CVerticalTextElement::V_HANKAKU ) ;
				muCVerticalTextElement->insert( aElement ) ;
			}
		}
		else
		{
			if ( isDelimiter( strChar ) &&
				!aElementPrev.isNull() &&
				aElementPrev.getType() == CVerticalTextElement::V_ZENKAKU )
			{
				aElementPrev.setString( aElementPrev.getString() + strChar ) ;
				muCVerticalTextElement->set( aElementPrev , INT_MAX ) ;
			}
			else
			{
				CVerticalTextElement aElement(
					strChar , CVerticalTextElement::V_ZENKAKU ) ;
				muCVerticalTextElement->insert( aElement ) ;
			}
		}
		idx += cch ;
	}

	if ( bTwoDegiLateral )
	{
		for ( int idx = 0 ; idx < muCVerticalTextElement->size() ; idx ++ )
		{
			CVerticalTextElement aElementPrev ;
			if ( idx > 0 )
			{
				aElementPrev = muCVerticalTextElement->get( idx - 1 ) ;
			}
			CVerticalTextElement aElement = muCVerticalTextElement->get( idx ) ;
			const std::wstring strCurr = aElement.getString() ;
			if ( aElement.getType() == CVerticalTextElement::V_HANKAKU &&
				isAsciiDigitString( strCurr ) )
			{
				if ( aElementPrev.isNull() ||
					!( aElementPrev.getType() == CVerticalTextElement::V_HANKAKU &&
						!isSpace( aElementPrev.getString() ) ) )
				{
					aElement.setType( CVerticalTextElement::H_HANKAKU ) ;
					muCVerticalTextElement->set( aElement , idx ) ;
				}
			}
		}
	}
}

} //namespace DcDraw
} //namespace DcDrawLib





