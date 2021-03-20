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
#include "DcDraw\CconvDcDrawProp.h"

const char namePointTextHeight[] = "PointTextHeight" ; 
const char nameLogicalunitTextHeight[] = "LogicalunitTextHeight" ; 
const char nameLogicalunitCellHeight[] = "LogicalunitCellHeight" ;
const char nameFacename[] = "Facename" ; 
const char nameBold[] = "Bold" ; 
const char nameItaric[] = "Itaric" ; 
const char nameUnderline[] = "Underline" ; 
const char nameStrikeOut[] = "StrikeOut" ; 
const char nameEscapement[] = "Escapement" ; 


	// ********************************
	//	コンストラクタ
	// ********************************
CconvDcDrawProp::CconvDcDrawProp(void)
{
}

CconvDcDrawProp::~CconvDcDrawProp(void)
{
}

	// ********************************
	//@name CdFontProp
	// ********************************
int CconvDcDrawProp::CdFontProp_to_CdConnnectedString2( 
	const CdFontProp& aCdFontProp ,
	CdConnectedString2*	pCdConnectedString )
{
	int iRv = 0 ;


	//1.PointTextHeight 
	if ( iRv >= 0 )
	{
		int iValue = aCdFontProp.getPointTextHeight() ;
		if ( iValue != 0 )
		{
			char	szLs[32] ;
			sprintf( szLs , "%d" , iValue ) ;
			pCdConnectedString->setItem( namePointTextHeight , szLs ) ;
		}
	}
	//2.LogicalunitTextHeight 
	if ( iRv >= 0 )
	{
		int iValue = aCdFontProp.getLogicalunitTextHeight() ;
		if ( iValue != 0 )
		{
			char	szLs[32] ;
			sprintf( szLs , "%d" , iValue ) ;
			pCdConnectedString->setItem( nameLogicalunitTextHeight , szLs ) ;
		}
	}
	//3.LogicalunitCellHeight 
	if ( iRv >= 0 ){
		int iValue = aCdFontProp.getLogicalunitCellHeight() ;
		if ( iValue != 0 )
		{
			char	szLs[32] ;
			sprintf( szLs , "%d" , iValue ) ;
			pCdConnectedString->setItem( nameLogicalunitCellHeight , szLs ) ;
		}
	}
	//4.Facename 
	if ( iRv >= 0 )
	{
		string strValue = aCdFontProp.getFacename() ;
		pCdConnectedString->setItem( nameFacename , strValue ) ;
	}
	//5.Bold 
	if ( iRv >= 0 )
	{
		bool bValue = aCdFontProp.getBold() ;
		if ( bValue )
		{
			pCdConnectedString->setItem( nameBold , bValue ? "1" : "0"  ) ;
		}
	}
	//6.Itaric 
	if ( iRv >= 0 )
	{
		bool bValue = aCdFontProp.getItaric() ;
		if ( bValue )
		{
			pCdConnectedString->setItem( nameItaric , bValue ? "1" : "0"  ) ;
		}
	}
	//7.Underline 
	if ( iRv >= 0 )
	{
		bool bValue = aCdFontProp.getUnderline() ;
		if ( bValue )
		{
			pCdConnectedString->setItem( nameUnderline , bValue ? "1" : "0"  ) ;
		}
	}
	//8.StrikeOut 
	if ( iRv >= 0 )
	{
		bool bValue = aCdFontProp.getStrikeOut() ;
		if ( bValue )
		{
			pCdConnectedString->setItem( nameStrikeOut , bValue ? "1" : "0"  ) ;
		}
	}
	//9.Escapement
	if ( iRv >= 0 )
	{
		int iValue = aCdFontProp.getEscapement() ;
		if ( iValue != 0 )
		{
			char	szLs[32] ;
			sprintf( szLs , "%d" , iValue ) ;
			pCdConnectedString->setItem( nameEscapement , szLs ) ;
		}
	}
	
	return ( iRv ) ;
}


int CconvDcDrawProp::CdFontProp_from_CdConnectedString2( 
	CdFontProp* pCdFontProp ,
	const CdConnectedString2& aCdConnectedString )
{
	int	iRv = 0 ;

	CdFontProp	aCdFontProp ;

	//1.PointTextHeight 
	if ( iRv >= 0 )
	{
		string strValue = aCdConnectedString.getValue( namePointTextHeight ) ;
		if ( !strValue.empty() )
		{
			int iValue = atoi( strValue.c_str() ) ;
			if ( !( 0 <= iValue ) )
			{
				iRv = -12 ;	//	PointTextHeight の値が不正
			}
			else if ( 0 < iValue )
			{
				aCdFontProp.setPointTextHeight( iValue ) ;
			}
		}
	}
	//2.LogicalunitTextHeight 
	if ( iRv >= 0 )
	{
		string strValue = aCdConnectedString.getValue( 
			nameLogicalunitTextHeight ) ;
		if ( !strValue.empty() )
		{
			int iValue = atoi( strValue.c_str() ) ;
			if ( !( 0 <= iValue ) )
			{
				iRv = -22 ;	//	LogicalunitTextHeight の値が不正
			}
			else if ( 0 < iValue )
			{
				aCdFontProp.setLogicalunitTextHeight( iValue ) ;
			}
		}
	}
	//3.LogicalunitCellHeight 
	if ( iRv >= 0 )
	{
		string strValue = aCdConnectedString.getValue( 
			nameLogicalunitCellHeight ) ;
		if ( !strValue.empty() )
		{
			int iValue = atoi( strValue.c_str() ) ;
			if ( !( 0 <= iValue ) )
			{
				iRv = -32 ;	//	LogicalunitCellHeight の値が不正
			}
			else if ( 0 < iValue )
			{
				aCdFontProp.setLogicalunitCellHeight( iValue ) ;
			}
		}
	}
	//4.Facename 
	if ( iRv >= 0 )
	{
		string strValue = aCdConnectedString.getValue( 
			nameFacename ) ;
		if ( strValue.length() == 0 )
		{
			iRv = -42 ;	//	Facename の値が不正
		}
		else
		{
			aCdFontProp.setFacename( strValue ) ;
		}
	}
	//5.Bold 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( 
			nameBold ) ;
		if ( !strValue.empty() )
		{
			int iValue = atoi( strValue.c_str() ) ;
			if ( !( 0 <=  iValue && iValue <= 1 ) )
			{
				iRv = -52 ;	//	Bold の値が不正
			}
			else
			{
				aCdFontProp.setBold( iValue == 1 ) ;
			}
		}
	}
	//6.Itaric 
	if ( iRv >= 0 )
	{
		string strValue = aCdConnectedString.getValue( 
			nameItaric ) ;
		if ( !strValue.empty() )
		{
			int iValue = atoi( strValue.c_str() ) ;
			if ( !( 0 <=  iValue && iValue <= 1 ) )
			{
				iRv = -62 ;	//	Itaric の値が不正
			}
			else
			{
				aCdFontProp.setItaric( iValue == 1 ) ;
			}
		}
	}
	//7.Underline 
	if ( iRv >= 0 )
	{
		string strValue = aCdConnectedString.getValue( 
			nameUnderline ) ;
		if ( !strValue.empty() )
		{
			int iValue = atoi( strValue.c_str() ) ;
			if ( !( 0 <=  iValue && iValue <= 1 ) )
			{
				iRv = -72 ;	//	Underline の値が不正
			}
			else
			{
				aCdFontProp.setUnderline( iValue == 1 ) ;
			}
		}
	}
	//8.StrikeOut 
	if ( iRv >= 0 )
	{
		string strValue = aCdConnectedString.getValue( 
			nameStrikeOut ) ;
		if ( !strValue.empty() )
		{
			int iValue = atoi( strValue.c_str() ) ;
			if ( !( 0 <=  iValue && iValue <= 1 ) )
			{
				iRv = -82 ;	//	StrikeOut の値が不正
			}
			else
			{
				aCdFontProp.setStrikeOut( iValue == 1 ) ;
			}
		}
	}
	//9.Escapement
	if ( iRv >= 0 )
	{
		string strValue = aCdConnectedString.getValue( 
			nameEscapement ) ;
		if ( !strValue.empty() )
		{
			int iValue = atoi( strValue.c_str() ) ;
			if ( !( 0 <= iValue ) )
			{
				iRv = -92 ;	//	Escapement の値が不正
			}
			else if ( 0 < iValue )
			{
				aCdFontProp.setEscapement( iValue ) ;
			}
		}
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		*pCdFontProp = aCdFontProp ;
	}

	return ( iRv ) ;
}

string CconvDcDrawProp::CdFontProp_to_string( const CdFontProp& aCdFontProp )
{
	int iRv = 0 ;
	CdConnectedString2	aCdConnectedString2 ;
	if ( iRv >= 0 ){
		iRv = CdFontProp_to_CdConnnectedString2( aCdFontProp ,
			&aCdConnectedString2 );
	}
	if ( iRv >= 0 ){
		return ( aCdConnectedString2 ) ;
	}
	return ( "" ) ;
}



int CconvDcDrawProp::CdFontProp_from_string( 
	CdFontProp* pCdFontProp , 
	const string& aString  )
{
	int	iRv = 0 ;
	CdConnectedString2	aCdConnectedString( aString )  ;
	if ( iRv >= 0 ){
		iRv = CdFontProp_from_CdConnectedString2( pCdFontProp ,
			aCdConnectedString );
	}
	return ( iRv ) ;
}
	// ********************************
	//@name CdColorProp
	// ********************************

string CconvDcDrawProp::CdColorProp_to_string( const CdColorProp& aCdColorProp )
{
	unsigned long iColorref = 
		((unsigned long)aCdColorProp.getRed() << 0 )|
		((unsigned long)aCdColorProp.getGreen() << 8 ) | 
		((unsigned long)aCdColorProp.getBlue() << 16 ) ; 

	char	szLs[32] ;
	sprintf( szLs , "%08X" , iColorref ) ;
	
	return szLs ;
}

CdColorProp CconvDcDrawProp::CdColorProp_from_string( const string& aString  )
{
	unsigned long dwColor = strtoul( aString.c_str() , NULL , 16 ) ;
	CdColorProp	aCdColorProp( 
		(unsigned char)(( dwColor >>  0 ) & 0xff) , 
		(unsigned char)(( dwColor >>  8 ) & 0xff) , 
		(unsigned char)(( dwColor >> 16 ) & 0xff) ) ;
	return aCdColorProp ;
}
