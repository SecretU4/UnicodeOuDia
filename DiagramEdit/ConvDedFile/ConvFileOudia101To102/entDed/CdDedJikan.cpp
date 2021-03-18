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
//	CdDedJikan.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include <deque>
using namespace std ;

#include "CdDedJikan.h"
#include "str/stringSplit.h"
#include "str/strprintf.h"


#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif


// ****************************************************************
//	CdDedJikan::CConv
// ****************************************************************
CdDedJikan::CConv::CConv() 
	: m_bNoSecond( false )
	, m_bPlusDisplay( false ) 
	, m_bPlusToSpace( false ) 
{
};

CdDedJikan::CConv::CConv( 
			bool bNoSecond ,
			bool bPlusDisplay ,
			bool bPlusToSpace  ) 
	: m_bNoSecond( bNoSecond )
	, m_bPlusDisplay( bPlusDisplay ) 
	, m_bPlusToSpace( bPlusToSpace ) 
{
}

std::string CdDedJikan::CConv::encode( const CdDedJikan& aJikan )const 
{
	string	strRv ;
	{
		//  符号
		if ( m_bPlusDisplay )
		{
			strRv += "- +"[ sign( aJikan.getTotalSeconds() ) + 1 ] ;
		} 
		else if ( m_bPlusToSpace )
		{
			strRv += "-  "[ sign( aJikan.getTotalSeconds() ) + 1 ] ;
		}
		else
		{
			if ( aJikan.getTotalSeconds() < 0 )
			{
				strRv += "- +"[ sign( aJikan.getTotalSeconds() ) + 1 ] ;
			}
		}

		//	時
		{
			//char	szLs[16] ;
			//sprintf( szLs , "%d" , aJikan.getHour() ) ;
			//strRv += szLs ;
			strRv += OuLib::strprintf( "%d" , aJikan.getHour() ) ;
		}
		//	時のつぎのコロン
		{
			strRv += ":" ;
		}
		//	分
		{
			//char	szLs[16] ;
			//sprintf( szLs , "%02d" , aJikan.getMinute() ) ;
			//strRv += szLs ;
			strRv += OuLib::strprintf( "%02d" , aJikan.getMinute() ) ;
		}
		if ( !m_bNoSecond )
		{
			//	分のつぎのコロン
			{
				strRv += ":" ;
			}
			//	秒
			{
				//char	szLs[16] ;
				//sprintf( szLs , "%02d" , aJikan.getSecond() ) ;
				//strRv += szLs ;
				strRv += OuLib::strprintf( "%02d" , aJikan.getSecond()  ) ;
			}
		}
	}
	return ( strRv ) ;

};



// ****************************************************************
//	CdDedJikan
// ****************************************************************

// ********************************
//	コンストラクタ
// ********************************
	
CdDedJikan::CdDedJikan( int iSign , int iHour , int iMinute , int iSecond ) :
	m_iTotalSeconds( 
		sign( iSign ) * ( iHour * 60 * 60 + iMinute * 60 + iSecond ) ) 
{
}
CdDedJikan::CdDedJikan( const string& strTime ) 
	: m_iTotalSeconds( 0 )
{
	decode( strTime ) ;
}

// ********************************
//	CdDedJikan
// ********************************
	// ********************************
	//@name 属性
	// ********************************
	
CdDedJikan& CdDedJikan::setTime( int iSign , int iHour , int iMinute , int iSecond ) 
{
	m_iTotalSeconds = 
		sign( iSign ) * ( iHour * 60 * 60 + iMinute * 60 + iSecond ) ; 
	return ( *this ) ;
}
	
	
	// ********************************
	//@name 操作
	// ********************************
int CdDedJikan::compare( const CdDedJikan& value )const 
{
	if ( m_iTotalSeconds > value.m_iTotalSeconds ){
		return ( 1 ) ;
	}	else if ( m_iTotalSeconds < value.m_iTotalSeconds ){
		return ( -1 ) ;
	}
	return ( 0 ) ;
}
	
CdDedJikan& CdDedJikan::addSeconds( int value ) 
{
		m_iTotalSeconds += value ;

	return *this ;
}

int CdDedJikan::subJikan( const CdDedJikan& value )const
{
	int iRv = 0 ; 

		iRv = m_iTotalSeconds - value.m_iTotalSeconds ;

	return ( iRv ) ;
}

int CdDedJikan::decode( const string& value ) 
{
	int	iRv = 0 ;
	
	deque<string>	contstrValue = 
		OuLib::splitc< deque<string> >( ':' , value ) ;
	//contstrValue = strValue を ":" で区切ります。
	//	（例） 
	//	strValue = "13:15:45" の場合、
	//		contstrValue[0]="13"
	//		contstrValue[1]="15"
	//		contstrValue[2]="45"
	//	strValue = "-9:15" の場合、
	//		contstrValue[0]="-9"
	//		contstrValue[1]="15"
	

	//	秒がない場合は追加
	if ( contstrValue.size() == 2 ){
		contstrValue.push_back( "00" ) ;
	}
	//strValue = "13:15:45","9:15:00"
	//

	if ( contstrValue.size() != 3 ){
		//	contstrValue が、時・分・秒でない場合は、不正です。
		m_iTotalSeconds = 0 ;
		iRv = -1 ;	//	項目数が不足しています。
		return ( iRv ) ;
	}
	// --------------------------------
	int iSign = 0 ;
	int iHour = -1 ;
	int iMinute = -1 ;
	int iSecond = -1 ;


	//	+ 符号を追加します。
	{
		string	strLs = contstrValue[0] ;

		if (  strLs.length() > 0 ){
			if ( strLs[0] == ' ' ){
				strLs[0] = '+' ;
			}	else if ( strLs[0] != '+' && strLs[0] != '-' ){
				strLs = string( "+" ) + strLs ;
			}
		}
		contstrValue[0] = strLs ;
	}



	//strValue = "13:15:45","09:15:00"

	{
		//	符号・時
		{
			string	strLs = contstrValue[0] ;
			if ( strLs.length() > 0 ){
				if ( strLs[0] == '+' ){
					iSign = 1 ;
				}	else if ( strLs[0] == '-' ){
					iSign = -1 ;
				}
				strLs.erase( 0 , 1 ) ;
				if ( strLs.find_first_not_of( "0123456789" ) == string::npos ){
					iHour = atoi( strLs.c_str() ) ;
				}
			}
		}
		//	分
		{
			string	strLs = contstrValue[1] ;
			if ( strLs.length() > 0 ){
				if ( strLs.find_first_not_of( "0123456789" ) == string::npos ){
					iMinute = atoi( strLs.c_str() ) ;
				}
			}
		}
		//	秒
		{
			string	strLs = contstrValue[2] ;
			if ( strLs.length() > 0 ){
				if ( strLs.find_first_not_of( "0123456789" ) == string::npos ){
					iSecond = atoi( strLs.c_str() ) ;
				}
			}
		}
	}
	
	if ( iHour >= 0 && iMinute >= 0 && iSecond >= 0 ){
		setTime( iSign , iHour , iMinute , iSecond ) ;
	}	else	{
		m_iTotalSeconds = 0 ;
		iRv = -2 ;	//	時・分・秒の表記が不正です。
	}
	
	return ( iRv ) ;
}

