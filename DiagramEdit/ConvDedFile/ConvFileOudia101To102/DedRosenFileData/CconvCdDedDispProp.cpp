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
#include "CconvCdDedDispProp.h"
#include "Ou\OuNew.h"
#include "Ou\dynamic_castOu.h"
#include "str\strToInt.h"
#include "str\CdConnectedString2.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfo.h"
#include "DcdCd\DcDrawProp\CdColorProp.h"
#include "DcdCd\DcDrawProp\CconvDcDrawProp.h"


using namespace std ;
using namespace OuPropertiesText ;
using namespace OuPropertiesText::ErrorInfo ;
// --------------------------------
//	下請関数
// --------------------------------


/**
 	CdFontProp の属性を、文字列に変換します。
  @param aCdFontProp [in]
 	変換対象となる CdFontProp を指定してください。
  @return
 	変換結果を返します。
 */
static string CdFontProp_to_string( const CdFontProp& aCdFontProp )
{
	CconvDcDrawProp	aConv ;
	return aConv.CdFontProp_to_string( aCdFontProp ) ;
}


/**
 	 CdFontProp_to_string() で作成した文字列を解釈し、
 	CdFontProp オブジェクトの属性に反映します。
  @param pCdFontProp [out]
 	この関数はこのオブジェクトの属性に、文字列の内容を反映します。
  @param aString [in]
 	 CdFontProp_to_string() で作成した文字列を指定してください。
  @return
 	成功したら 0 以上、エラーなら負の数です。
 	-	-12 ;	//	PointTextHeight の値が不正
 	-	-22 ;	//	LogicalunitTextHeight の値が不正
 	-	-32 ;	//	LogicalunitCellHeight の値が不正
 	-	-42 ;	//	Facename の値が不正
 	-	-52 ;	//	Bold の値が不正
 	-	-62 ;	//	Itaric の値が不正
 	-	-72 ;	//	Underine の値が不正
 	-	-82 ;	//	StrikeOut の値が不正
 */
static int CdFontProp_from_string( CdFontProp* pCdFontProp , const string& aString  )
{
	CconvDcDrawProp	aConv ;
	return aConv.CdFontProp_from_string( pCdFontProp , aString ) ;
}

/**
	aCdColorProp を文字列に変換します。
@param aCdColorProp [in]
	変換元の値を指定してください。
@return
	変換結果を返します。
*/
static string CdColorProp_to_string( const CdColorProp& aCdColorProp )
{

	CconvDcDrawProp	aConv ;
	return aConv.CdColorProp_to_string( aCdColorProp ) ;
}


/**
	文字列を aCdColorProp に変換します。
@param aString [in]
	変換元の値を指定してください。
@return
	変換結果を返します。
 */
static CdColorProp CdColorProp_from_string( const string& aString  )
{
	CconvDcDrawProp	aConv ;
	return aConv.CdColorProp_from_string( aString ) ;
}



// ****************************************************************
//	CconvCdDedDispProp
// ****************************************************************
const char nameJikokuhyouFont[]="JikokuhyouFont" ;
const char nameJikokuhyouVFont[]="JikokuhyouVFont" ;
const char nameDiaEkimeiFont[]="DiaEkimeiFont" ;
const char nameDiaJikokuFont[]="DiaJikokuFont" ;
const char nameDiaRessyaFont[]="DiaRessyaFont" ;
const char nameCommentFont[]="CommentFont" ;
const char nameDiaMojiColor[]="DiaMojiColor" ;
const char nameDiaHaikeiColor[]="DiaHaikeiColor" ;
const char nameDiaRessyaColor[]="DiaRessyaColor" ;
const char nameDiaJikuColor[]="DiaJikuColor" ;
const char nameEkimeiLength[] = "EkimeiLength" ;
const char nameJikokuhyouRessyaWidth[] = "JikokuhyouRessyaWidth" ;
const char nameDiaRessyajouhouHyoujiEkiOrderKudari[]="DiaRessyajouhouHyoujiEkiOrderKudari" ;
const char nameDiaRessyajouhouHyoujiEkiOrderNobori[]="DiaRessyajouhouHyoujiEkiOrderNobori" ;

int CconvCdDedDispProp::toOuPropertiesText( 
			const CdDedDispProp& aCdDedDispProp , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) 
{
	int iRv = 0 ;

	//1.JikokuhyouFont
	for ( int idx = 0 ; iRv >= 0 && idx < CdDedDispProp::JIKOKUHYOUFONT_COUNT ; idx ++ )
	{
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getJikokuhyouFont(idx) ) ;
		pCNodeContainer->insertInName(
			OuNew< OuPropertiesText::CNode >( 
				new OuPropertiesText::CPropertyString( nameJikokuhyouFont , strValue ) ) ) ;
	}

	//JikokuhyouVFont
	{
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getJikokuhyouVFont() ) ;
		pCNodeContainer->setValue( nameJikokuhyouVFont , strValue ) ;
	}

	//2.DiaEkimeiFont
	if ( iRv >= 0 ){
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getDiaEkimeiFont() ) ;
		pCNodeContainer->setValue( nameDiaEkimeiFont , strValue ) ;
	}
	//3.DiaJikokuFont
	if ( iRv >= 0 ){
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getDiaJikokuFont() ) ;
		pCNodeContainer->setValue( nameDiaJikokuFont , strValue ) ;
	}
	//4.DiaRessyaFont
	if ( iRv >= 0 ){
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getDiaRessyaFont() ) ;
		pCNodeContainer->setValue( nameDiaRessyaFont , strValue ) ;
	}
	//5.CommentFont
	if ( iRv >= 0 ){
		string	strValue = CdFontProp_to_string( aCdDedDispProp.getViewCommentFont() ) ;
		pCNodeContainer->setValue( nameCommentFont , strValue ) ;
	}
	//6.DiaMojiColor
	if ( iRv >= 0 )
	{
		pCNodeContainer->setValue( 
			nameDiaMojiColor , 
			CdColorProp_to_string( aCdDedDispProp.getDiaMojiColor() ) );
	}
	//7.DiaHaikeiColor
	if ( iRv >= 0 )
	{
		pCNodeContainer->setValue( nameDiaHaikeiColor , 
			CdColorProp_to_string( aCdDedDispProp.getDiaHaikeiColor() ) ) ;
	}
	//8.DiaRessyaColor
	if ( iRv >= 0 )
	{
		pCNodeContainer->setValue( 
			nameDiaRessyaColor , 
			CdColorProp_to_string( aCdDedDispProp.getDiaRessyaColor() ) ) ;
	}
	//9.DiaJikuColor
	if ( iRv >= 0 ){
		pCNodeContainer->setValue( 
			nameDiaJikuColor , 
			CdColorProp_to_string( aCdDedDispProp.getDiaJikuColor() ) ) ;
	}
	//10.EkimeiLength
	if ( iRv >= 0 ){
		pCNodeContainer->setValue( nameEkimeiLength , 
			OuLib::stringOf( aCdDedDispProp.getEkimeiLength() ) ) ;
	}

	//11.JikokuhyouRessyaWidth
	if ( iRv >= 0 )
	{
		//	デフォルト値の場合は、出力はしません。
		pCNodeContainer->setValue( nameJikokuhyouRessyaWidth , 
			OuLib::stringOf( aCdDedDispProp.getJikokuhyouRessyaWidth() ) ) ;
	}

	return ( iRv ) ;
}

int CconvCdDedDispProp::fromOuPropertiesText( 
			CdDedDispProp* pCdDedDispProp ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) 
{
	int iRv = 0 ;
	
	CdDedDispProp aCdDedDispProp ;	

	// --------------------------------
	//1.JikokuhyouFont
	//	数が足りない場合、指定のない要素は設定をしません。
	for ( int idx = 0 ; iRv >= 0 && idx < CdDedDispProp::JIKOKUHYOUFONT_COUNT ; idx ++ )
	{

		Ou< const OuPropertiesText::CNode > pNode = pCNodeContainer->getInName(
			nameJikokuhyouFont , idx ) ;
		Ou< const OuPropertiesText::CPropertyString > pPropertyString = 
			dynamic_castOu< const OuPropertiesText::CPropertyString >( pNode ) ;

		if ( pPropertyString != NULL )
		{

			string	strValue = pPropertyString->getValue() ;
			CdFontProp	aCdFontProp ;
			int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
			if ( iResult < 0 ){
				COuErrorInfo aCOuErrorInfo( ERRREASON_InvalidValue() ) ;
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Name() , nameJikokuhyouFont ) ; 
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Value() , strValue ) ; 
				iRv = -12 ;	//	JikokuhyouFont の内容が不正です。
			}	else	{
				aCdDedDispProp.setJikokuhyouFont( idx , aCdFontProp ) ;
			}		
		}
	}

	//JikokuhyouVFont
	{
		string	strValue = pCNodeContainer->getValue(	nameJikokuhyouVFont ) ; 
		if ( strValue.length() > 0 )
		{
			CdFontProp	aCdFontProp ;
			int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
			if ( iResult < 0 ){
				COuErrorInfo aCOuErrorInfo( ERRREASON_InvalidValue() ) ;
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Name() , nameJikokuhyouVFont ) ; 
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Value() , strValue ) ; 
				iRv = -13 ;	//	JikokuhyouVFont の内容が不正です。
			}	else	{
				aCdDedDispProp.setJikokuhyouVFont( aCdFontProp ) ;
			}
		}
	}
	//2.DiaEkimeiFont
	if ( iRv >= 0 ){
		string	strValue = pCNodeContainer->getValue( nameDiaEkimeiFont ) ;
		CdFontProp	aCdFontProp ;
		int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
		if ( iResult < 0 ){
			COuErrorInfo aCOuErrorInfo( ERRREASON_InvalidValue() ) ;
			aCOuErrorInfo.getProp()->setValue( ERRPROP_Name() , nameDiaEkimeiFont ) ; 
			aCOuErrorInfo.getProp()->setValue( ERRPROP_Value() , strValue ) ; 
			iRv = -22 ;	//	DiaEkimeiFont の内容が不正です。
		}	else	{
			aCdDedDispProp.setDiaEkimeiFont( aCdFontProp ) ;
		}		
	}
	//3.DiaJikokuFont
	if ( iRv >= 0 ){
		string	strValue = pCNodeContainer->getValue( nameDiaJikokuFont ) ;
		CdFontProp	aCdFontProp ;
		int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
		if ( iResult < 0 ){
			COuErrorInfo aCOuErrorInfo( ERRREASON_InvalidValue() ) ;
			aCOuErrorInfo.getProp()->setValue( ERRPROP_Name() , nameDiaJikokuFont ) ; 
			aCOuErrorInfo.getProp()->setValue( ERRPROP_Value() , strValue ) ; 
			iRv = -32 ;	//	DiaJikokuFont の内容が不正です。
		}	else	{
			aCdDedDispProp.setDiaJikokuFont( aCdFontProp ) ;
		}		
	}
	//4.DiaRessyaFont
	if ( iRv >= 0 ){
		string	strValue = pCNodeContainer->getValue( nameDiaRessyaFont ) ;
		
		//	この属性は、あとから追加したため、空の場合でもエラーにはしません
		if ( !strValue.empty() ){
			CdFontProp	aCdFontProp ;
			int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
			if ( iResult < 0 ){
				COuErrorInfo aCOuErrorInfo( ERRREASON_InvalidValue() ) ;
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Name() , nameDiaRessyaFont ) ; 
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Value() , strValue ) ; 
				iRv = -32 ;	//	DiaRessyaFont の内容が不正です。
			}	else	{
				aCdDedDispProp.setDiaRessyaFont( aCdFontProp ) ;
			}
		}
	}
	//5.CommentFont
	if ( iRv >= 0 ){
		string	strValue = pCNodeContainer->getValue( nameCommentFont ) ;
		CdFontProp	aCdFontProp ;
		int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
		if ( iResult < 0 ){
				COuErrorInfo aCOuErrorInfo( ERRREASON_InvalidValue() ) ;
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Name() , nameCommentFont ) ; 
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Value() , strValue ) ; 
			iRv = -32 ;	//	CommentFont の内容が不正です。
		}	else	{
			aCdDedDispProp.setViewCommentFont( aCdFontProp ) ;
		}		
	}
	//6.DiaMojiColor
	if ( iRv >= 0 )
	{
		string	strValue = pCNodeContainer->getValue( nameDiaMojiColor ) ;
		aCdDedDispProp.setDiaMojiColor( 
			CdColorProp_from_string( strValue ) ) ;
	}
	//7.DiaHaikeiColor
	if ( iRv >= 0 )
	{
		string	strValue = pCNodeContainer->getValue( nameDiaHaikeiColor ) ;
		aCdDedDispProp.setDiaHaikeiColor( 
			CdColorProp_from_string( strValue ) ) ;
	}
	//8.DiaRessyaColor
	if ( iRv >= 0 )
	{
		string	strValue = pCNodeContainer->getValue( nameDiaRessyaColor ) ;
		aCdDedDispProp.setDiaRessyaColor( 
			CdColorProp_from_string( strValue ) ) ;
	}
	//9.DiaJikuColor
	if ( iRv >= 0 )
	{
		string	strValue = pCNodeContainer->getValue( nameDiaJikuColor ) ;
		aCdDedDispProp.setDiaJikuColor( 
			CdColorProp_from_string( strValue ) ) ;
	}
	//10.EkimeiLength
	if ( iRv >= 0 ){
		string	strValue = pCNodeContainer->getValue( nameEkimeiLength ) ;
		if ( !strValue.empty() ){
			int iValue = OuLib::intOf( strValue ) ;
			if ( iValue > 0 ){
				aCdDedDispProp.setEkimeiLength( iValue ) ;
			}
		}	
	}
	//11.EkimeiLength
	if ( iRv >= 0 )
	{
		string	strValue = pCNodeContainer->getValue( nameJikokuhyouRessyaWidth ) ;
		if ( !strValue.empty() )
		{
			int iValue = OuLib::intOf( strValue ) ;
			if ( iValue > 0 )
			{
				aCdDedDispProp.setJikokuhyouRessyaWidth( iValue ) ;
			}
		}	
	}
	// --------------------------------
	if ( iRv >= 0 ){
		*pCdDedDispProp = aCdDedDispProp ;	
	}

	return ( iRv ) ;
}
