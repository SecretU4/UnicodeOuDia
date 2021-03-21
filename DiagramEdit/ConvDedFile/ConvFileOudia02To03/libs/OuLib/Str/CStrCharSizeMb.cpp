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
//	CStrCharSizeMb.cpp
// ****************************************************************
*/
#include <mbstring.h>
#include "CStrCharSizeMb.h"



// ****************************************************************
//	CStrCharSizeMb
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CStrCharSizeMb::CStrCharSizeMb() 
{
	m_ariBidx.push_back( 0 ) ;
}
	
CStrCharSizeMb::CStrCharSizeMb( const std::string& ev ) 
{
	scan( ev ) ;
}
	
// ********************************
//	CStrCharSizeMb
// ********************************
CStrCharSizeMb& CStrCharSizeMb::scan( const std::string& ev ) 
{
	m_ariBidx.clear() ;

	int idx ;
	for ( idx = 0 ; idx < ev.length() ; ){
		m_ariBidx.push_back( idx ) ;
		unsigned char	ch = (unsigned char)ev[idx] ;
		int iSize = _mbclen( &ch ) ;
		idx += iSize ;
	}

	m_ariBidx.push_back( idx ) ;
	return *this ;

}
	
int CStrCharSizeMb::ByteLength()const 
{
	return ( m_ariBidx.back() ) ;
}
	
int CStrCharSizeMb::CharLength()const 
{
	return ( m_ariBidx.size() - 1 ) ;
}
	
int CStrCharSizeMb::CidxOfBidx( int iBidx , int* piOffset )const 
{
	if ( piOffset != NULL ){
		*piOffset = 0 ;
	}
	
	
	if ( iBidx < 0 ){
		return ( -1 ) ;
	}	else if ( iBidx >= ByteLength() ){
		return ( CharLength() );
	}
	
	//シーケンシャルサーチ
	//{
	//	int	idx  ;
	//	for ( idx = 0 ; idx < m_ariBidx.size() ; idx ++ ){
	//		if ( m_ariBidx[idx] == iBidx ){
	//			return ( idx ) ; 
	//		}
	//	}
	//}

	//バイナリサーチ
	int idx = -1 ; 
	int idxBegin = 0 ; 
	int idxEnd = m_ariBidx.size() - 1 ;
	while ( idxBegin <= idxEnd ){
		idx = ( idxBegin + idxEnd ) / 2 ;
		if ( m_ariBidx[idx] == iBidx ){
			break ;
		}	else if ( iBidx < m_ariBidx[idx] ){
			idxEnd = idx - 1 ;
		}	else	{
			idxBegin = idx + 1 ;
		}
	}
	if ( !( idxBegin <= idxEnd ) ){
		//	バイナリサーチで結果が見つからなかった場合、
		//	idxEndは、検索対象より小さい、最寄の値のインデクスを指しています。
		idx = idxEnd ;	
	}
	if ( piOffset != NULL ){
		*piOffset = iBidx - m_ariBidx[idx] ;
	}

	return ( idx ) ;
}
int CStrCharSizeMb::BidxOfCidx( int iCidx )const 
{
	if ( iCidx < 0 ){
		return ( -1 ) ;
	}	else if ( iCidx >= CharLength() ){
		return ( ByteLength() );
	}
	
	return ( m_ariBidx[ iCidx ] ) ;
}
	
int CStrCharSizeMb::CsizeOfBidx( int iBidx )const 
{
	if ( iBidx < 0 ){
		//iBidx が負の数: 0を返します。
		return ( 0 ) ;	
	}	else if ( iBidx >= ByteLength() ){
		//iBidx がByteLength() 以上 : 0を返します。
		return ( 0 );
	}
	
	int iOffset = 0 ;
	int iCidx = CidxOfBidx( iBidx , &iOffset ) ;
	if ( iOffset != 0 ){
		//iBidx が文字の２バイト目: 0を返します。
		return ( 0 ) ;
	}
	return ( CsizeOfCidx( iCidx ) ) ;
}

int CStrCharSizeMb::CsizeOfCidx( int iCidx )const 
{
	if ( iCidx < 0 ){
		return ( 0 ) ;	//	iCidx が負の数/CharLength() 以上 : 0を返します。
	}	else if ( iCidx >= CharLength() ){
		return ( 0 );	//	iCidx が負の数/CharLength() 以上 : 0を返します。
	}
	
	return ( m_ariBidx[ iCidx + 1 ] - m_ariBidx[ iCidx ] ) ;
}
	
int CStrCharSizeMb::BidxNextChar( int iBidx , int iCharOffset )const 
{
	int iCidx = CidxOfBidx( iBidx ) ;
	//if ( iCidx == -2 ){
	//	return ( -2 ) ;	//	iBidx が文字の２バイト目を指している : -2 を返します。
	//}
	
	iCidx += iCharOffset ;
	return ( BidxOfCidx( iCidx ) ) ;
	
}

int CStrCharSizeMb::CidxLast()const 
{
	return ( CharLength() - 1 ) ;
}
	
int CStrCharSizeMb::BidxLast()const 
{
	return ( BidxOfCidx( CharLength() - 1 ) ) ;
}



static const char* const hantozen_table[] = {
	"ｶﾞ" , "ガ" , 
	"ｷﾞ" , "ギ" ,
	"ｸﾞ" , "グ" ,
	"ｹﾞ" , "ゲ" ,
	"ｺﾞ" , "ゴ" ,
	"ｻﾞ" , "ザ" ,
	"ｼﾞ" , "ジ" ,
	"ｽﾞ" , "ズ" , 
	"ｾﾞ" , "ゼ" ,
	"ｿﾞ" , "ゾ" ,
	"ﾀﾞ" , "ダ" ,
	"ﾁﾞ" , "ヂ" ,
	"ﾂﾞ" , "ヅ" ,
	"ﾃﾞ" , "デ" ,
	"ﾄﾞ" , "ド" ,
	"ﾊﾞ" , "バ" ,
	"ﾊﾟ" , "パ" ,
	"ﾋﾟ" , "ピ" ,
	"ﾌﾞ" , "ブ" ,
	"ﾌﾟ" , "プ" , 
	"ﾍﾞ" , "ベ" ,
	"ﾍﾟ" , "ペ" ,
	"ﾎﾞ" , "ボ" ,
	"ﾎﾟ" , "ポ" ,
};

std::string CStrCharSizeMb::strToSingleByte( const std::string& strEv , 
						int* piResult ) 
{
	int iResult = 0 ;
	std::string	strRv ;
	bool bDakutenChange = true ;
	
	// --------------------------------
	CStrCharSizeMb	aCStrCharSizeMb( strEv ) ;
	int iBidx ;
	for ( iBidx = 0 ; iBidx < aCStrCharSizeMb.ByteLength() ; 
				iBidx = aCStrCharSizeMb.BidxNextChar( iBidx ) ){
		if ( aCStrCharSizeMb.CsizeOfBidx( iBidx ) == 1 ){
			strRv += strEv[iBidx] ;
		}	else	{
			unsigned short ch = 0 ;
			ch |= (unsigned char)strEv[iBidx] ;
			ch <<= 8 ;
			ch |= (unsigned char)strEv[iBidx+1] ;
			
			//	変換表による変換
			int idxTbl ; 
			for ( idxTbl = 1 ; 
				idxTbl < sizeof(hantozen_table) / sizeof(hantozen_table[0]) ;
				idxTbl += 2 ){
				unsigned short chTbl = 0 ;
				chTbl |= (unsigned char)hantozen_table[idxTbl][0] ;
				chTbl <<= 8 ;
				chTbl |= (unsigned char)hantozen_table[idxTbl][1] ;

				if ( ch == chTbl ){
					strRv += hantozen_table[idxTbl - 1 ] ;
					break ;
				}
			}
			if ( idxTbl < sizeof(hantozen_table) / sizeof(hantozen_table[0]) ){
				continue ;
			}
			
			// --------------------------------
			//	関数による変換
			unsigned short ch2 = _mbctombb( ch ) ;
			if ( ch == ch2 ){
				strRv += (char)( ( ch2 >> 8 ) & 0xff ) ;
				strRv += (char)( ( ch2 >> 0 ) & 0xff ) ;
				iResult = -1 ;
			}	else	{
				strRv += (char)( ( ch2 >> 0 ) & 0xff ) ;
				if ( iResult == 0 ){
					iResult = 1 ;
				}
			}
		}
	}
	
	
	// --------------------------------
	if ( piResult != NULL ){
		*piResult = iResult ;
	}
	return ( strRv ) ;
}

std::string CStrCharSizeMb::strToDoubleByte( const std::string& strEv , 
						int* piResult ) 
{
	int iResult = 0 ;
	std::string	strRv ;
	bool bDakutenChange = true ;
	
	// --------------------------------
	CStrCharSizeMb	aCStrCharSizeMb( strEv ) ;
	int iBidx ;
	for ( iBidx = 0 ; iBidx < aCStrCharSizeMb.ByteLength() ; 
				iBidx = aCStrCharSizeMb.BidxNextChar( iBidx ) ){
		if ( aCStrCharSizeMb.CsizeOfBidx( iBidx ) == 2 ){
			strRv += strEv[iBidx] ;
			strRv += strEv[iBidx+1] ;
		}	else	{
			unsigned short ch = (unsigned char)strEv[iBidx];
			
			//	変換表による変換
			if ( bDakutenChange ){
				char b0 = strEv[iBidx] ;
				char b1 = 0 ;
				if ( iBidx < aCStrCharSizeMb.ByteLength() - 1 ){
					b1 = strEv[iBidx+1] ;
				}
				int idxTbl ; 
				for ( idxTbl = 0 ; 
					idxTbl < sizeof(hantozen_table)/sizeof(hantozen_table[0]) ;
					idxTbl += 2 ){
					if ( b0 == hantozen_table[idxTbl][0] && 
							b1 == hantozen_table[idxTbl][1] ){
						strRv += hantozen_table[idxTbl+1][0] ; 
						strRv += hantozen_table[idxTbl+1][1] ;
						if ( b1 != '\0' ){
							//	変換元文字列を２文字使ったため、
							//	iBidx は２文字目に移しておきます。
							iBidx ++ ;
						}
						break ;
					}
				}
				if ( idxTbl<sizeof(hantozen_table)/sizeof(hantozen_table[0] )){
					if ( iResult == 0 ){
						iResult = 1 ;
					}
					continue ;
				}
			}
			// --------------------------------
			//	関数による変換
			unsigned short ch2 = _mbbtombc( ch ) ;
			if ( ch == ch2 ){
				strRv += (char)( ( ch2 >> 0 ) & 0xff ) ;
				iResult = -1 ;
			}	else	{
				strRv += (char)( ( ch2 >> 8 ) & 0xff ) ;
				strRv += (char)( ( ch2 >> 0 ) & 0xff ) ;
				if ( iResult == 0 ){
					iResult = 1 ;
				}
			}
		}
	}
	
	
	// --------------------------------
	if ( piResult != NULL ){
		*piResult = iResult ;
	}
	return ( strRv ) ;
}
