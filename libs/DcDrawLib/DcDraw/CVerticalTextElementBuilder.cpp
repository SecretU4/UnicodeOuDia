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



bool CVerticalTextElementBuilder::isSpace( const string& aStr )
{
	const char* const kyoukai[] = {
		" " , "　" ,
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ ){
		if ( aStr == kyoukai[idx] ) {
			return true ;
		}
	}
	return ( false ) ;
}

bool CVerticalTextElementBuilder::isDelimiter( const string& aStr )
{
	const char* const kyoukai[] = {
		"," , "，" ,
		"." , "．" ,
		      "。" , 
		      "、" , 
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ ){
		if ( aStr == kyoukai[idx] ) {
			return true ;
		}
	}
	return ( false ) ;
}


	// ********************************
	//@name CVerticalTextElementBuilder-操作
	// ********************************
void CVerticalTextElementBuilder::scan( 
		const std::string& aStr , 
		Mui<CVerticalTextElement>* muCVerticalTextElement ,
		bool bTwoDegiLateral  ) 
{
	int iRv = 0 ;

	//	このコンテナがそれまで保持していた要素は破棄します。
	muCVerticalTextElement->erase( 0 , INT_MAX ) ;

	CStrCharSizeMb	aCStrCharSizeMb( aStr ) ;
	for ( int bidx = 0 ; 
			bidx < aCStrCharSizeMb.ByteLength() ; 
			bidx = aCStrCharSizeMb.BidxNextChar( bidx ) )
	{
		LogMsgL( 3 , "CDcdTextboxV3::StringToMojiretsuyouso"
			"bidx=%d CsizeOfBidx=%d" , bidx , aCStrCharSizeMb.CsizeOfBidx( bidx ) ) ;

		string strChar = aStr.substr( bidx , 
			aCStrCharSizeMb.CsizeOfBidx( bidx ) ) ;
		CVerticalTextElement	aElementPrev ;
		if ( muCVerticalTextElement->size() > 0 )
		{
			aElementPrev = muCVerticalTextElement->get( INT_MAX ) ;
		}
		//strChar = 今回の文字。
		//aElementPrev = 直前の文字列要素

		if ( aCStrCharSizeMb.CsizeOfBidx( bidx ) == 1 )
		{
			//	今回の文字は１バイト文字

			string strCharPrev ;
			if ( !aElementPrev.isNull() ){
				strCharPrev = aElementPrev.getString().substr( 
					aElementPrev.getString().size() - 1 , 1 ) ;
			}
			//strCharPrev = 直前の文字列要素の末尾の文字

			if ( !isSpace( strChar ) && 
				!aElementPrev.isNull() && 
				aElementPrev.getType() == aElementPrev.V_HANKAKU &&
				!isDelimiter( strCharPrev ) && !isSpace( strCharPrev ) )
			{
				//	今回の文字は空白以外の１バイト文字で、
				//	( 直前の文字列要素が V_HANKAKU 、
				//	かつ、直前の文字列要素が区切り文字や空白で終わっていない
				//	) 
				//	場合は、直前の文字列要素に文字を追加します。
				//
				aElementPrev.setString( aElementPrev.getString() + strChar );
				muCVerticalTextElement->set( aElementPrev , INT_MAX ) ;
			}
			else
			{
				//	文字列要素を追加します。
				CVerticalTextElement	aElement( strChar , CVerticalTextElement::V_HANKAKU ) ;

				muCVerticalTextElement->insert( aElement ) ;
			}
		}
		else if ( aCStrCharSizeMb.CsizeOfBidx( bidx ) == 2 )
		{
			//	今回の文字は２バイト文字である場合は、文字列要素を追加します。

			//	今回の文字は２バイトの区切り文字で、
			//	( 直前の文字列要素が V_ZENKAKU 
			//	) 
			//	場合は、直前の文字列要素に文字を追加します。
			//
			if ( isDelimiter( strChar ) && 
				!aElementPrev.isNull() && 
				aElementPrev.getType() == CVerticalTextElement::V_ZENKAKU )
			{
				aElementPrev.setString( aElementPrev.getString() + strChar );
				muCVerticalTextElement->set( aElementPrev , INT_MAX ) ;

			}
			else
			{
				//	新しい文字列要素を追加します。
				CVerticalTextElement aElement( strChar , CVerticalTextElement::V_ZENKAKU ) ;
				muCVerticalTextElement->insert( aElement ) ;

			}
		}

	}
	//muCVerticalTextElement = 文字列を V_ZENKAKU と V_HANKAKU の２つの
	//	要素に分割しました。
	//	V_ZENKAKU は、原則として全角文字１つです。
	//	但し、[全角文字][全角区切り文字]
	//	は、[全角文字+全角区切り文字]の１つの要素になっています。
	//	V_HANKAKU は、連続した半角文字を１つの要素とします。

	// --------------------------------
	//	2桁以下の半角数字を横書きにする
	// --------------------------------
	if ( bTwoDegiLateral  )
	{
		// --------------------------------	
		int idxMojiretsuyouso ;
		for ( idxMojiretsuyouso = 0 ; 
				idxMojiretsuyouso < muCVerticalTextElement->size() ;
				idxMojiretsuyouso ++ )
		{
			//	今回の文字列要素が半角英数字１文字か２文字 
			//	AND 
			//	( 
			//		( 前の文字列要素が存在しない)
			//		OR
			//		( 前の文字列要素が（空白以外の半角文字列の要素）でない)
			//	) 
			//	
			//	の場合は、水平方向に半角英数字を1文字・2文字で並べます。
			CVerticalTextElement aElementPrev ;
			if ( idxMojiretsuyouso > 0 )
			{
				aElementPrev = muCVerticalTextElement->get( idxMojiretsuyouso - 1 ) ;
			}
			CVerticalTextElement aElement = muCVerticalTextElement->get( idxMojiretsuyouso ) ;
			string strCurr = aElement.getString() ;
			if ( aElement.getType() == CVerticalTextElement::V_HANKAKU )
			{
				if ( 
					( strCurr.size() == 1 && isdigit( (unsigned char)strCurr[0] ) ) || 
					( strCurr.size() == 2 && isdigit( (unsigned char)strCurr[0] ) && isdigit( (unsigned char)strCurr[1] ) ) 
				){

					if ( aElementPrev.isNull() || 
						!(  
							aElementPrev.getType() == CVerticalTextElement::V_HANKAKU && 
							!isSpace( aElementPrev.getString() ) 
						) 
					){
						aElement.setType( CVerticalTextElement::H_HANKAKU ) ;
						muCVerticalTextElement->set( aElement , idxMojiretsuyouso ) ;
					}
				}
					
			}

		}
	}	

};

} //namespace DcDraw
} //namespace DcDrawLib





