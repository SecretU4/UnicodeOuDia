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
//	CconvCdDedDispProp.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "str/strToInt.h"

#include "CconvCdDedDispProp.h"

// --------------------------------
//	下請関数
// --------------------------------
const char namePointTextHeight[] = "PointTextHeight" ; 
const char nameLogicalunitTextHeight[] = "LogicalunitTextHeight" ; 
const char nameLogicalunitCellHeight[] = "LogicalunitCellHeight" ;
const char nameFacename[] = "Facename" ; 
const char nameBold[] = "Bold" ; 
const char nameItaric[] = "Itaric" ; 
const char nameUnderine[] = "Underine" ; 
const char nameStrikeOut[] = "StrikeOut" ; 



/**
 *	CdFontProp の属性を、 CdConnectedString2 オブジェクトに追加します。
 * @param aCdFontProp [in]
 *	変換対象となる CdFontProp を指定してください。
 * @param pCdConnectedString2 [in,out]
 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
 *	追加します。
 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
 *	維持します。
 * @return
 *	成功したら 0 以上、エラーなら負の数です。
 */
static int CdFontProp_to_CdConnnectedString2( const CdFontProp& aCdFontProp ,
	CdConnectedString2*	pCdConnectedString )
{
	int iRv = 0 ;


	//1.PointTextHeight 
	if ( iRv >= 0 ){
		int iValue = aCdFontProp.getPointTextHeight() ;
		char	szLs[32] ;
		sprintf( szLs , "%d" , iValue ) ;
		pCdConnectedString->setItem( namePointTextHeight , szLs ) ;
	}
	//2.LogicalunitTextHeight 
	if ( iRv >= 0 ){
		int iValue = aCdFontProp.getLogicalunitTextHeight() ;
		char	szLs[32] ;
		sprintf( szLs , "%d" , iValue ) ;
		pCdConnectedString->setItem( nameLogicalunitTextHeight , szLs ) ;
	}
	//3.LogicalunitCellHeight 
	if ( iRv >= 0 ){
		int iValue = aCdFontProp.getLogicalunitCellHeight() ;
		char	szLs[32] ;
		sprintf( szLs , "%d" , iValue ) ;
		pCdConnectedString->setItem( nameLogicalunitCellHeight , szLs ) ;
	}
	//4.Facename 
	if ( iRv >= 0 ){
		string strValue = aCdFontProp.getFacename() ;
		pCdConnectedString->setItem( nameFacename , strValue ) ;
	}
	//5.Bold 
	if ( iRv >= 0 ){
		bool bValue = aCdFontProp.getBold() ;
		pCdConnectedString->setItem( nameBold , bValue ? "1" : "0"  ) ;
	}
	//6.Itaric 
	if ( iRv >= 0 ){
		bool bValue = aCdFontProp.getItaric() ;
		pCdConnectedString->setItem( nameItaric , bValue ? "1" : "0"  ) ;
	}
	//7.Underine 
	if ( iRv >= 0 ){
		bool bValue = aCdFontProp.getUnderine() ;
		pCdConnectedString->setItem( nameUnderine , bValue ? "1" : "0"  ) ;
	}
	//8.StrikeOut 
	if ( iRv >= 0 ){
		bool bValue = aCdFontProp.getStrikeOut() ;
		pCdConnectedString->setItem( nameStrikeOut , bValue ? "1" : "0"  ) ;
	}
	
	return ( iRv ) ;
}

/**
 *	 CdConnectedString2 オブジェクトから、
 *	 CdFontProp_to_CdConnectedString2() で追加した CdItem を読み取り、
 *	CdFontProp オブジェクトの属性に反映します。
 * @param pCdFontProp [out]
 *	この関数はこのオブジェクトの属性に、文字列の内容を反映します。
 * @param aCdConnectedString [in]
 *	 CdFontProp_to_CdConnectedString2() で追加した CdItem を持つ
 *	 CdConnectedString2 オブジェクトを指定してください。
 * @return
 *	成功したら 0 以上、エラーなら負の数です。
 *	-	-12 ;	//	PointTextHeight の値が不正
 *	-	-22 ;	//	LogicalunitTextHeight の値が不正
 *	-	-32 ;	//	LogicalunitCellHeight の値が不正
 *	-	-42 ;	//	Facename の値が不正
 *	-	-52 ;	//	Bold の値が不正
 *	-	-62 ;	//	Itaric の値が不正
 *	-	-72 ;	//	Underine の値が不正
 *	-	-82 ;	//	StrikeOut の値が不正
 */
static int CdFontProp_from_CdConnectedString2( CdFontProp* pCdFontProp ,
	const CdConnectedString2& aCdConnectedString )
{
	int	iRv = 0 ;

	CdFontProp	aCdFontProp ;

	//1.PointTextHeight 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( namePointTextHeight ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <= iValue ) ){
			iRv = -12 ;	//	PointTextHeight の値が不正
		}	else if ( 0 < iValue )	{
			aCdFontProp.setPointTextHeight( iValue ) ;
		}
	}
	//2.LogicalunitTextHeight 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( 
			nameLogicalunitTextHeight ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <= iValue ) ){
			iRv = -22 ;	//	LogicalunitTextHeight の値が不正
		}	else if ( 0 < iValue )	{
			aCdFontProp.setLogicalunitTextHeight( iValue ) ;
		}
	}
	//3.LogicalunitCellHeight 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( 
			nameLogicalunitCellHeight ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <= iValue ) ){
			iRv = -32 ;	//	LogicalunitCellHeight の値が不正
		}	else if ( 0 < iValue )	{
			aCdFontProp.setLogicalunitCellHeight( iValue ) ;
		}
	}
	//4.Facename 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( 
			nameFacename ) ;
		if ( strValue.length() == 0 ){
			iRv = -42 ;	//	Facename の値が不正
		}	else	{
			aCdFontProp.setFacename( strValue ) ;
		}
	}
	//5.Bold 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( 
			nameBold ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <=  iValue && iValue <= 1 ) ){
			iRv = -52 ;	//	Bold の値が不正
		}	else	{
			aCdFontProp.setBold( iValue == 1 ) ;
		}
	}
	//6.Itaric 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( 
			nameItaric ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <=  iValue && iValue <= 1 ) ){
			iRv = -62 ;	//	Itaric の値が不正
		}	else	{
			aCdFontProp.setItaric( iValue == 1 ) ;
		}
	}
	//7.Underine 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( 
			nameUnderine ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <=  iValue && iValue <= 1 ) ){
			iRv = -72 ;	//	Underine の値が不正
		}	else	{
			aCdFontProp.setUnderine( iValue == 1 ) ;
		}
	}
	//8.StrikeOut 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( 
			nameStrikeOut ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <=  iValue && iValue <= 1 ) ){
			iRv = -82 ;	//	StrikeOut の値が不正
		}	else	{
			aCdFontProp.setStrikeOut( iValue == 1 ) ;
		}
	}
	// --------------------------------
	if ( iRv >= 0 ){
		*pCdFontProp = aCdFontProp ;
	}

	return ( iRv ) ;
}


/**
 *	CdFontProp の属性を、文字列に変換します。
 * @param aCdFontProp [in]
 *	変換対象となる CdFontProp を指定してください。
 * @return
 *	変換結果を返します。
 */
static string CdFontProp_to_string( const CdFontProp& aCdFontProp )
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


/**
 *	 CdFontProp_to_string() で作成した文字列を解釈し、
 *	CdFontProp オブジェクトの属性に反映します。
 * @param pCdFontProp [out]
 *	この関数はこのオブジェクトの属性に、文字列の内容を反映します。
 * @param aString [in]
 *	 CdFontProp_to_string() で作成した文字列を指定してください。
 * @return
 *	成功したら 0 以上、エラーなら負の数です。
 *	-	-12 ;	//	PointTextHeight の値が不正
 *	-	-22 ;	//	LogicalunitTextHeight の値が不正
 *	-	-32 ;	//	LogicalunitCellHeight の値が不正
 *	-	-42 ;	//	Facename の値が不正
 *	-	-52 ;	//	Bold の値が不正
 *	-	-62 ;	//	Itaric の値が不正
 *	-	-72 ;	//	Underine の値が不正
 *	-	-82 ;	//	StrikeOut の値が不正
 */
static int CdFontProp_from_string( CdFontProp* pCdFontProp , const string& aString  )
{
	int	iRv = 0 ;
	CdConnectedString2	aCdConnectedString( aString )  ;
	if ( iRv >= 0 ){
		iRv = CdFontProp_from_CdConnectedString2( pCdFontProp ,
			aCdConnectedString );
	}
	return ( iRv ) ;
}

// ****************************************************************
//	CconvCdDedDispProp
// ****************************************************************
const char nameJikokuhyouFont[]="JikokuhyouFont" ;
const char nameDiaEkimeiFont[]="DiaEkimeiFont" ;
const char nameDiaJikokuFont[]="DiaJikokuFont" ;
const char nameDiaRessyaFont[]="DiaRessyaFont" ;
const char nameCommentFont[]="CommentFont" ;
const char nameDiaMojiColor[]="DiaMojiColor" ;
const char nameDiaHaikeiColor[]="DiaHaikeiColor" ;
const char nameDiaRessyaColor[]="DiaRessyaColor" ;
const char nameDiaJikuColor[]="DiaJikuColor" ;
const char nameEkimeiLength[] = "EkimeiLength" ;
const char nameDisplayRessyabangou[]="DisplayRessyabangou" ;
const char nameDisplayRessyamei[]="DisplayRessyamei" ;
const char nameDiaRessyajouhouHyoujiEkiOrderKudari[]="DiaRessyajouhouHyoujiEkiOrderKudari" ;
const char nameDiaRessyajouhouHyoujiEkiOrderNobori[]="DiaRessyajouhouHyoujiEkiOrderNobori" ;



int CconvCdDedDispProp::toCdConnectedString( 
		const CdDedDispProp& aCdDedDispProp , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;

	//1.JikokuhyouFont
	if ( iRv >= 0 ){
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getJikokuhyouFont() ) ;
		pCdConnectedString->setItem( nameJikokuhyouFont , strValue ) ;
	}
	//2.DiaEkimeiFont
	if ( iRv >= 0 ){
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getDiaEkimeiFont() ) ;
		pCdConnectedString->setItem( nameDiaEkimeiFont , strValue ) ;
	}
	//3.DiaJikokuFont
	if ( iRv >= 0 ){
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getDiaJikokuFont() ) ;
		pCdConnectedString->setItem( nameDiaJikokuFont , strValue ) ;
	}
	//4.DiaRessyaFont
	if ( iRv >= 0 ){
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getDiaRessyaFont() ) ;
		pCdConnectedString->setItem( nameDiaRessyaFont , strValue ) ;
	}
	//5.CommentFont
	if ( iRv >= 0 ){
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getViewCommentFont() ) ;
		pCdConnectedString->setItem( nameCommentFont , strValue ) ;
	}
	//6.DiaMojiColor
	if ( iRv >= 0 ){
		COLORREF	dwColor = aCdDedDispProp.getDiaMojiColor() ;
		char	szLs[32] ;
		sprintf( szLs , "%08X" , dwColor ) ;
		pCdConnectedString->setItem( nameDiaMojiColor , szLs ) ;
	}
	//7.DiaHaikeiColor
	if ( iRv >= 0 ){
		COLORREF	dwColor = aCdDedDispProp.getDiaHaikeiColor() ;
		char	szLs[32] ;
		sprintf( szLs , "%08X" , dwColor ) ;
		pCdConnectedString->setItem( nameDiaHaikeiColor , szLs ) ;
	}
	//8.DiaRessyaColor
	if ( iRv >= 0 ){
		COLORREF	dwColor = aCdDedDispProp.getDiaRessyaColor() ;
		char	szLs[32] ;
		sprintf( szLs , "%08X" , dwColor ) ;
		pCdConnectedString->setItem( nameDiaRessyaColor , szLs ) ;
	}
	//9.DiaJikuColor
	if ( iRv >= 0 ){
		COLORREF	dwColor = aCdDedDispProp.getDiaJikuColor() ;
		char	szLs[32] ;
		sprintf( szLs , "%08X" , dwColor ) ;
		pCdConnectedString->setItem( nameDiaJikuColor , szLs ) ;
	}
	//10.EkimeiLength
	if ( iRv >= 0 ){
		pCdConnectedString->setItem( nameEkimeiLength , 
			OuLib::stringOf( aCdDedDispProp.getEkimeiLength() ) ) ;
	}
	//11.DiaRessyajouhouHyoujiEkiOrderKudari
	if ( iRv >= 0 ){
		int iValue = aCdDedDispProp.getDiaRessyajouhouHyoujiEkiOrder( Ressyahoukou_Kudari ) ;
		char	szLs[32] ;
		sprintf( szLs , "%d" , iValue ) ;
		pCdConnectedString->setItem( nameDiaRessyajouhouHyoujiEkiOrderKudari , szLs  ) ;
	}
	//12.DiaRessyajouhouHyoujiEkiOrderNobori
	if ( iRv >= 0 ){
		int iValue = aCdDedDispProp.getDiaRessyajouhouHyoujiEkiOrder( Ressyahoukou_Nobori ) ;
		char	szLs[32] ;
		sprintf( szLs , "%d" , iValue ) ;
		pCdConnectedString->setItem( nameDiaRessyajouhouHyoujiEkiOrderNobori , szLs  ) ;
	}

	return ( iRv ) ;
}

int CconvCdDedDispProp::fromCdConnectedString( 
		CdDedDispProp* pCdDedDispProp ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;
	
	CdDedDispProp aCdDedDispProp ;	

	// --------------------------------
	//1.JikokuhyouFont
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameJikokuhyouFont ) ;
		CdFontProp	aCdFontProp ;
		int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
		if ( iResult < 0 ){
			iRv = -12 ;	//	JikokuhyouFont の内容が不正です。
		}	else	{
			aCdDedDispProp.setJikokuhyouFont( aCdFontProp ) ;
		}		
	}
	//2.DiaEkimeiFont
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaEkimeiFont ) ;
		CdFontProp	aCdFontProp ;
		int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
		if ( iResult < 0 ){
			iRv = -22 ;	//	DiaEkimeiFont の内容が不正です。
		}	else	{
			aCdDedDispProp.setDiaEkimeiFont( aCdFontProp ) ;
		}		
	}
	//3.DiaJikokuFont
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaJikokuFont ) ;
		CdFontProp	aCdFontProp ;
		int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
		if ( iResult < 0 ){
			iRv = -32 ;	//	DiaJikokuFont の内容が不正です。
		}	else	{
			aCdDedDispProp.setDiaJikokuFont( aCdFontProp ) ;
		}		
	}
	//4.DiaRessyaFont
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaRessyaFont ) ;
		
		//	この属性は、あとから追加したため、空の場合でもエラーにはしません
		if ( !strValue.empty() ){
			CdFontProp	aCdFontProp ;
			int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
			if ( iResult < 0 ){
				iRv = -32 ;	//	DiaRessyaFont の内容が不正です。
			}	else	{
				aCdDedDispProp.setDiaRessyaFont( aCdFontProp ) ;
			}
		}
	}
	//5.CommentFont
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameCommentFont ) ;
		CdFontProp	aCdFontProp ;
		int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
		if ( iResult < 0 ){
			iRv = -32 ;	//	CommentFont の内容が不正です。
		}	else	{
			aCdDedDispProp.setViewCommentFont( aCdFontProp ) ;
		}		
	}
	//6.DiaMojiColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaMojiColor ) ;
		unsigned long dwColor = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCdDedDispProp.setDiaMojiColor( dwColor ) ;
	}
	//7.DiaHaikeiColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaHaikeiColor ) ;
		unsigned long dwColor = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCdDedDispProp.setDiaHaikeiColor( dwColor ) ;
	}
	//8.DiaRessyaColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaRessyaColor ) ;
		unsigned long dwColor = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCdDedDispProp.setDiaRessyaColor( dwColor ) ;
	}
	//9.DiaJikuColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaJikuColor ) ;
		unsigned long dwColor = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCdDedDispProp.setDiaJikuColor( dwColor ) ;
	}
	//10.EkimeiLength
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameEkimeiLength ) ;
		if ( !strValue.empty() ){
			int iValue = OuLib::intOf( strValue ) ;
			if ( iValue > 0 ){
				aCdDedDispProp.setEkimeiLength( iValue ) ;
			}
		}	
	}
	//11.DiaRessyajouhouHyoujiEkiOrderKudari
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaRessyajouhouHyoujiEkiOrderKudari ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <= iValue ) ){
			iRv = -102 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari が不正です。
		}	else	{
			aCdDedDispProp.setDiaRessyajouhouHyoujiEkiOrder( Ressyahoukou_Kudari , iValue ) ;
		}
	}
	//12.DiaRessyajouhouHyoujiEkiOrderNobori
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaRessyajouhouHyoujiEkiOrderNobori ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <= iValue ) ){
			iRv = -112 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori が不正です。
		}	else	{
			aCdDedDispProp.setDiaRessyajouhouHyoujiEkiOrder( Ressyahoukou_Nobori , iValue ) ;
		}
	}
	// --------------------------------
	if ( iRv >= 0 ){
		*pCdDedDispProp = aCdDedDispProp ;	
	}

	return ( iRv ) ;
}
