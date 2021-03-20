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
//	CconvCentDed_01.cpp
// ****************************************************************
*/
#include "stdafx.h"

/*
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
*/

#include "CconvCentDed_01.h"
#include "str/strToInt.h"
#include "str/stringSplit.h"

/** 配列 a の要素数を返します。 */
#define arrayof(a) (sizeof(a)/sizeof(a[0]))

// ********************************
//	CentDedEki
// ********************************
const char nameEkimei[] = "Ekimei" ;
const char nameEkijikokukeisiki[] = "Ekijikokukeisiki" ;
const char nameEkikibo[] = "Ekikibo" ;

const struct {
	CentDedEki::EEkijikokukeisiki	value ; 
	const char* name ;
}	arEkijikokukeisiki_name[] = {
	{	CentDedEki::Jikokukeisiki_Hatsu , "Jikokukeisiki_Hatsu" },
	{	CentDedEki::Jikokukeisiki_Hatsuchaku , "Jikokukeisiki_Hatsuchaku" },
	{	CentDedEki::Jikokukeisiki_KudariChaku , "Jikokukeisiki_KudariChaku" },
	{	CentDedEki::Jikokukeisiki_NoboriChaku , "Jikokukeisiki_NoboriChaku" },
};	


const struct {
	CentDedEki::EEkikibo	value ; 
	const char* name ;
}	arEkikibo_name[] = {
	{	CentDedEki::Ekikibo_Ippan , "Ekikibo_Ippan" },
	{	CentDedEki::Ekikibo_Syuyou , "Ekikibo_Syuyou" },
};	


int CconvCentDed_01::CentDedEki_To_CdConnectedString( 
		const CentDedEki& aCentDedEki , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;
	// --------------------------------	
	//1.Ekimei
	if ( iRv >= 0 ){
		if ( aCentDedEki.getEkimei().empty() ){
			iRv = -11 ;	//	Ekimei が指定されていません。
		}	else	{
			pCdConnectedString->setItem( nameEkimei , 
				aCentDedEki.getEkimei() ) ;
		}
	}
	//2.Ekijikokukeisiki
	if ( iRv >= 0 ){
		int idx ;
		for ( idx = 0 ; 
			idx < arrayof(arEkijikokukeisiki_name)  ; 
			idx ++ ){
			if ( aCentDedEki.getEkijikokukeisiki() == 
					arEkijikokukeisiki_name[idx].value ){
				break ;
			} 
		}
		if ( idx == arrayof( arEkijikokukeisiki_name )  ){
			iRv = -22 ;	//	Ekijikokukeisiki の値が不正です。
		}	else	{
			pCdConnectedString->setItem( nameEkijikokukeisiki , 
				arEkijikokukeisiki_name[idx].name ) ;
		}
	}

	//3.Ekikibo
	if ( iRv >= 0 ){
		int idx ;
		for ( idx = 0 ; 
			idx < arrayof(arEkikibo_name)  ; 
			idx ++ ){
			if ( aCentDedEki.getEkikibo() == 
					arEkikibo_name[idx].value ){
				break ;
			} 
		}
		if ( idx == arrayof( arEkijikokukeisiki_name )  ){
			iRv = -32 ;	//	Ekikibo の値が不正です。
		}	else	{
			pCdConnectedString->setItem( nameEkikibo , 
				arEkikibo_name[idx].name ) ;
		}
	}
	// --------------------------------	
	return ( iRv ) ;
}


int CconvCentDed_01::CentDedEki_From_CdConnectedString( 
		CentDedEki* pCentDedEki ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;
	
	CentDedEki	aCentDedEki ; 
	// --------------------------------	
	//1.Ekimei
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( nameEkimei ) ;
		if ( strValue.empty() ){
			iRv = -11 ;	//	Ekimei が指定されていません。
		}	else	{
			aCentDedEki.setEkimei( strValue ) ;
		}
	}

	//2.Ekijikokukeisiki
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameEkijikokukeisiki );
		int idx ;
		for ( idx = 0 ;
			idx < arrayof(arEkijikokukeisiki_name) ;
			idx ++ ){
			if ( strValue == 
					arEkijikokukeisiki_name[idx].name ){
				break ;
			} 
		}
		if ( idx == arrayof(arEkijikokukeisiki_name) ){
			iRv = -22 ;	//	Ekijikokukeisiki の値が不正です。
		}	else	{
			aCentDedEki.setEkijikokukeisiki( 
				arEkijikokukeisiki_name[idx].value ) ;
		}
	}

	//3.Ekikibo
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameEkikibo );
		int idx ;
		for ( idx = 0 ; 
			idx < arrayof(arEkikibo_name) ;
			idx ++ ){
			if ( strValue == 
					arEkikibo_name[idx].name ){
				break ;
			} 
		}
		if ( idx == arrayof(arEkikibo_name) ){
			iRv = -32 ;	//	Ekikibo の値が不正です。
		}	else	{
			aCentDedEki.setEkikibo( arEkikibo_name[idx].value ) ;
		}
	}

	// --------------------------------
	if ( iRv >= 0 ){
		*pCentDedEki = aCentDedEki ;
	}
	return ( iRv ) ;
}

// ********************************
//	CentDedRessyasyubetsu
// ********************************

const char nameSyubetsumei[]="Syubetsumei" ;
const char nameRyakusyou[]="Ryakusyou" ;
const char nameJikokuhyouMojiColor[]="JikokuhyouMojiColor" ;
const char nameDiagramSenColor[]="DiagramSenColor" ;
const char nameDiagramSenStyle[]="DiagramSenStyle" ;
const char nameDiagramSenIsBold[]="DiagramSenIsBold" ;

const struct {
	CentDedRessyasyubetsu::ESenStyle	value ; 
	const char* name ;
}	arESenStyle_name[] = {
	{ CentDedRessyasyubetsu::SenStyle_Jissen , "SenStyle_Jissen"} ,
	{ CentDedRessyasyubetsu::SenStyle_Hasen , "SenStyle_Hasen"} ,
	{ CentDedRessyasyubetsu::SenStyle_Tensen , "SenStyle_Tensen"} ,
	{ CentDedRessyasyubetsu::SenStyle_Ittensasen , "SenStyle_Ittensasen"} ,
};	



int CconvCentDed_01::CentDedRessyasyubetsu_To_CdConnectedString( 
		const CentDedRessyasyubetsu& aCentDedRessyasyubetsu , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;

	// --------------------------------	
	//1.Syubetsumei
	if ( iRv >= 0 ){
		if ( aCentDedRessyasyubetsu.getSyubetsumei().empty() ){
			iRv = -11 ;	//	Syubetsumei が指定されていません。
		}	else	{
			pCdConnectedString->setItem( nameSyubetsumei , 
				aCentDedRessyasyubetsu.getSyubetsumei() ) ;
		}
	}


	//2.Ryakusyou
	if ( iRv >= 0 ){
		if ( aCentDedRessyasyubetsu.getRyakusyou().empty() ){

		}	else	{
			pCdConnectedString->setItem( nameRyakusyou , 
				aCentDedRessyasyubetsu.getRyakusyou() ) ;
		}
	}

	//3.JikokuhyouMojiColor
	if ( iRv >= 0 ){
		unsigned long iValue = aCentDedRessyasyubetsu.getJikokuhyouMojiColor();
		char	szLs[32] ;
		sprintf( szLs , "%08X" , iValue ) ;
		string	strValue = szLs ;
		pCdConnectedString->setItem( nameJikokuhyouMojiColor , strValue ) ;
	}

	//4.DiagramSenColor
	if ( iRv >= 0 ){
		unsigned long iValue = aCentDedRessyasyubetsu.getDiagramSenColor();
		char	szLs[32] ;
		sprintf( szLs , "%08X" , iValue ) ;
		string	strValue = szLs ;
		pCdConnectedString->setItem( nameDiagramSenColor , strValue ) ;
	}

	//5.DiagramSenStyle
	if ( iRv >= 0 ){
		int idx ;
		for ( idx = 0 ; 
			idx < arrayof(arESenStyle_name) && 
			aCentDedRessyasyubetsu.getDiagramSenStyle() != 
				arESenStyle_name[idx].value ; idx ++ ){};
		if ( idx == arrayof(arESenStyle_name) ){
			iRv = -52 ;	//	DiagramSenStyle の値が不正です。
		}	else	{
			pCdConnectedString->setItem( nameDiagramSenStyle , 
				arESenStyle_name[idx].name ) ;
		}
	}

	//6.DiagramSenIsBold
	if ( iRv >= 0 ){
		bool bValue = aCentDedRessyasyubetsu.getDiagramSenIsBold();
		string	strValue = "0" ;
		if ( bValue ){	strValue = "1" ; } ;
		
		pCdConnectedString->setItem( nameDiagramSenIsBold , strValue ) ;
	}

	return ( iRv ) ;
}

int CconvCentDed_01::CentDedRessyasyubetsu_From_CdConnectedString( 
		CentDedRessyasyubetsu* pCentDedRessyasyubetsu ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;

	CentDedRessyasyubetsu aCentDedRessyasyubetsu ;

	// --------------------------------	
	//1.Syubetsumei
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameSyubetsumei ) ;
		if ( strValue.empty() ){
			iRv = -11 ;	//	Syubetsumei が指定されていません。
		}	else	{
			aCentDedRessyasyubetsu.setSyubetsumei( strValue ) ;
		}
	}
	
	//2.Ryakusyou
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameRyakusyou ) ;
		if ( strValue.empty() ){
		}	else	{
			aCentDedRessyasyubetsu.setRyakusyou( strValue ) ;
		}
	}
	
	//3.JikokuhyouMojiColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( 
			nameJikokuhyouMojiColor ) ;
		unsigned long iValue = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCentDedRessyasyubetsu.setJikokuhyouMojiColor( iValue ) ;
	}
	
	//4.DiagramSenColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( 
			nameDiagramSenColor ) ;
		unsigned long iValue = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCentDedRessyasyubetsu.setDiagramSenColor( iValue ) ;
	}
	
	//5.DiagramSenStyle
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( 
			nameDiagramSenStyle ) ;
		int idx ;
		for ( idx = 0 ; 
			idx < arrayof(arESenStyle_name) && 
			strValue != arESenStyle_name[idx].name ; idx ++ ){};
		if ( idx == arrayof(arESenStyle_name) ){
			iRv = -52 ;	//	DiagramSenStyle の値が不正です。
		}	else	{
			aCentDedRessyasyubetsu.setDiagramSenStyle( 
				arESenStyle_name[idx].value ) ;
		}
	}

	//6.DiagramSenIsBold
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( 
			nameDiagramSenIsBold ) ;
		unsigned long iValue = strtoul( strValue.c_str() , NULL , 10 ) ;
		aCentDedRessyasyubetsu.setDiagramSenIsBold( iValue != 0 ) ;
	}
	
	// --------------------------------
	if ( iRv >= 0 ){
		*pCentDedRessyasyubetsu = aCentDedRessyasyubetsu ;
	}

	return ( iRv ) ;
}

void CconvCentDed_01::CentDedRessyasyubetsu_to_CDcdFreeLineProp(
	COLORREF aCOLORREF ,
	CentDedRessyasyubetsu::ESenStyle eSenStyle , 
	bool bIsBold , 
	CDcdFreeLine::CdLineProp* pCdLineProp )	
{
		pCdLineProp->setColor( aCOLORREF ) ;
		switch( eSenStyle ){
		 // 実線 
		 case CentDedRessyasyubetsu::SenStyle_Jissen :
			pCdLineProp->setLinestyle( LINESTYLE_SOLID ) ;
			break ;
		 // 破線
		 case CentDedRessyasyubetsu::SenStyle_Hasen :
			pCdLineProp->setLinestyle( LINESTYLE_DASH ) ;
			break ;
		 // 点線
		 case CentDedRessyasyubetsu::SenStyle_Tensen :
			pCdLineProp->setLinestyle( LINESTYLE_DOT ) ;
			break ;
		 // 一点鎖線
		 case CentDedRessyasyubetsu::SenStyle_Ittensasen :
			pCdLineProp->setLinestyle( LINESTYLE_DASH_DOT ) ;
			break ;
		}
		pCdLineProp->setLogicalunitWidth( bIsBold ? 2 : 1 ) ;

}

// ********************************
//	CentDedEkiJikoku
// ********************************
const char nameEkiatsukai[]="Ea" ;
const char nameChakujikoku[]="Ar" ;
const char nameHatsujikoku[]="Dp" ;


const struct {
	CentDedEkiJikoku::EEkiatsukai	value ; 
	const char* name ;
}	arEEkiatsukai_name[] = {
	{ CentDedEkiJikoku::Ekiatsukai_None , "no" },
	{ CentDedEkiJikoku::Ekiatsukai_Teisya , "st" },
	{ CentDedEkiJikoku::Ekiatsukai_Tsuuka , "ps" },
	{ CentDedEkiJikoku::Ekiatsukai_Keiyunasi , "rt" },
};

int CconvCentDed_01::CentDedEkiJikoku_To_CdConnectedString( 
		const CentDedEkiJikoku& aCentDedEkiJikoku , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;

	//1.Ekiatsukai
	if ( iRv >= 0 ){
		int idx ;
		for ( idx = 0 ; 
			idx < arrayof(arEEkiatsukai_name) && 
			aCentDedEkiJikoku.getEkiatsukai() != 
				arEEkiatsukai_name[idx].value ; idx ++ ){};
		if ( idx == arrayof(arEEkiatsukai_name) ){
			iRv = -12 ;	//	DiagramEkiatsukai の値が不正です。
		}	else	{
			pCdConnectedString->setItem( nameEkiatsukai , 
				arEEkiatsukai_name[idx].name ) ;
		}
	}

	//2.Chakujikoku
	if ( iRv >= 0 ){
		string	strValue = aCentDedEkiJikoku.getChakujikoku().encode() ;
		if ( !strValue.empty() ){	//Null状態の時刻の項目は、出力しません
			pCdConnectedString->setItem( nameChakujikoku , strValue ) ;
		}
	}
	
	//3.Hatsujikoku
	if ( iRv >= 0 ){
		string	strValue = aCentDedEkiJikoku.getHatsujikoku().encode() ;
		if ( !strValue.empty() ){	//Null状態の時刻の項目は、出力しません
			pCdConnectedString->setItem( nameHatsujikoku , strValue ) ;
		}
	}
	
	return ( iRv ) ;
}

int CconvCentDed_01::CentDedEkiJikoku_From_CdConnectedString( 
		CentDedEkiJikoku* pCentDedEkiJikoku ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;
	CentDedEkiJikoku aCentDedEkiJikoku ;
	// --------------------------------
	//1.Ekiatsukai
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( 
			nameEkiatsukai ) ;
		int idx ;
		for ( idx = 0 ; 
			idx < arrayof(arEEkiatsukai_name) && 
			strValue != 
				arEEkiatsukai_name[idx].name ; idx ++ ){};
		if ( idx == arrayof(arEEkiatsukai_name) ){
			iRv = -12 ;	//	DiagramEkiatsukai の値が不正です。
		}	else	{
			aCentDedEkiJikoku.setEkiatsukai( 
				arEEkiatsukai_name[idx].value ) ;
		}
	}

	//2.Chakujikoku
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( 
			nameChakujikoku ) ;
		CdDedJikoku	jikokuValue ;
		int iResult = jikokuValue.decode( strValue ) ;
		aCentDedEkiJikoku.setChakujikoku( jikokuValue ) ;
	}
	
	//3.Hatsujikoku
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( 
			nameHatsujikoku ) ;
		CdDedJikoku	jikokuValue ;
		int iResult = jikokuValue.decode( strValue ) ;
		aCentDedEkiJikoku.setHatsujikoku( jikokuValue ) ;
	}
	// --------------------------------
	if ( iRv >= 0 ){
		*pCentDedEkiJikoku = aCentDedEkiJikoku ;
	}
	return ( iRv ) ;
}


// ********************************
//	CentDedRessya
// ********************************

const char nameIsNull[]="Nul" ;
const char nameRessyahoukou[]="Hk" ;
const char nameRessyasyubetsuIndex[]="Sy" ;
const char nameEkiJikoku[]="Ej" ;
const char nameEkiJikoku2[]="EkiJikoku2" ;
const char nameRessyabangou[]="No" ;
const char nameRessyamei[]="Nm" ;
const char nameGousuu[]="Gs" ;
const char nameBikou[]="Bk" ;

const static struct {
	ERessyahoukou	value ; 
	const char* name ;
}	arERessyahoukou_name[] = {
	{ Ressyahoukou_Kudari , "kd" },
	{ Ressyahoukou_Nobori , "nb" },
};




int CconvCentDed_01::CentDedRessya_To_CdConnectedString( 
		const CentDedRessya* pCentDedRessya , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;
	// --------------------------------
	//0.IsNull
	bool bIsNull = false ;
	if ( iRv >= 0 ){
		bool bIsNull = pCentDedRessya->isNull() ;
		pCdConnectedString->setItem( nameIsNull , 
				bIsNull ? "1" : "0" ) ;
	}

	if ( !bIsNull ){
		//1.Ressyahoukou
		if ( iRv >= 0 ){
			int idx ;
			for ( idx = 0 ; 
				idx < arrayof(arERessyahoukou_name) && 
				pCentDedRessya->getRessyahoukou() != 
					arERessyahoukou_name[idx].value ; idx ++ ){};
			if ( idx == arrayof(arERessyahoukou_name) ){
				iRv = -12 ;	//	Ressyahoukou の値が不正です。
			}	else	{
				pCdConnectedString->setItem( nameRessyahoukou , 
					arERessyahoukou_name[idx].name ) ;
			}
		}
		//2.RessyasyubetsuIndex ;
		if ( iRv >= 0 ){
			unsigned int iValue = pCentDedRessya->getRessyasyubetsuIndex();
			char	szLs[32] ;
			sprintf( szLs , "%d" , iValue ) ;
			string	strValue = szLs ;
			pCdConnectedString->setItem( nameRessyasyubetsuIndex , strValue ) ;
		}

		//3.EkiJikoku2
		if ( iRv >= 0 ){
			vector<string>	contstrEkijikoku ;
			int iEkiOrder ;
			for ( iEkiOrder = 0 ; 
					iEkiOrder < pCentDedRessya->getCentDedEkiJikokuCount() ; 
					iEkiOrder ++ ){
				string	strEkijikoku ;
				strEkijikoku.reserve( 32 ) ; ;
				//CdConnectedString2	connectedstrEkijikoku ;
				CentDedEkiJikoku	aCentDedEkiJikoku = 
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
				
				//	駅扱
				strEkijikoku += OuLib::stringOf( 
					(int)aCentDedEkiJikoku.getEkiatsukai() ) ;
				strEkijikoku += "/" ;
				//	着時刻
				strEkijikoku += aCentDedEkiJikoku.getChakujikoku().encode(
					CdDedJikoku::Format_NoColon |
					CdDedJikoku::Format_HourZeroToNone |
					CdDedJikoku::Format_NoSecond ) ;
				strEkijikoku += "/" ;
				//	発時刻
				strEkijikoku += aCentDedEkiJikoku.getHatsujikoku().encode(
					CdDedJikoku::Format_NoColon |
					CdDedJikoku::Format_HourZeroToNone |
					CdDedJikoku::Format_NoSecond ) ;

				contstrEkijikoku.push_back( strEkijikoku ) ;
			}
			string strEkijikoku2 = OuLib::joinc( ',' , contstrEkijikoku ) ;
			pCdConnectedString->setItem( string( nameEkiJikoku2 ) ,
						strEkijikoku2 ) ; 
		}

		//4."Ressyabangou" ;
		if ( iRv >= 0 ){
			pCdConnectedString->setItem( nameRessyabangou , 
				pCentDedRessya->getRessyabangou() ) ;
		}
		//5."Ressyamei" ;
		if ( iRv >= 0 ){
			pCdConnectedString->setItem( nameRessyamei , 
				pCentDedRessya->getRessyamei() ) ;
		}
		//6."Gousuu" ;
		if ( iRv >= 0 ){
			pCdConnectedString->setItem( nameGousuu , 
				pCentDedRessya->getGousuu() ) ;
		}
		//7."Bikou" ;
		if ( iRv >= 0 ){
			pCdConnectedString->setItem( nameBikou , 
				pCentDedRessya->getBikou() ) ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CconvCentDed_01::CentDedRessya_From_CdConnectedString( 
		CentDedRessya* pCentDedRessya ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;

	// --------------------------------
	//0.isNull
	bool	bIsNull = false ;
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameIsNull ) ;
		bIsNull = ( atoi( strValue.c_str() ) != 0 ) ; 
		pCentDedRessya->clear() ;
	}

	if ( !bIsNull ){
		//1.Ressyahoukou
		if ( iRv >= 0 ){
			string	strValue = aCdConnectedString.getValue( nameRessyahoukou );
			int idx ;
			for ( idx = 0 ; 
				idx < arrayof(arERessyahoukou_name) && 
				strValue != 
					arERessyahoukou_name[idx].name ; idx ++ ){};
			if ( idx == arrayof(arERessyahoukou_name) ){
				iRv = -12 ;	//	Ressyahoukou の値が不正です。
			}
		}

		//2.RessyasyubetsuIndex ;
		if ( iRv >= 0 ){
			string	strValue = aCdConnectedString.getValue( 
				nameRessyasyubetsuIndex ) ;
			int iValue = atoi( strValue.c_str() ) ;
			pCentDedRessya->setRessyasyubetsuIndex( iValue ) ;
		}

		
		//3.EkiJikoku2
		bool bEkijikokuFound = false ;
		if ( iRv >= 0 ){
			string strEkijikoku2 = aCdConnectedString.getValue( 
				nameEkiJikoku2 ) ;
			if ( !strEkijikoku2.empty() ){
				bEkijikokuFound = true ;
				deque<string>	contstrEkijikoku = OuLib::splitc< deque< string > >( 
					',' , strEkijikoku2 ) ;
					
				int iEkiOrder ;
				for ( iEkiOrder = 0 ; 
					iEkiOrder < pCentDedRessya->getCentDedEkiJikokuCount() ; 
					iEkiOrder ++ ){
					deque< string >	strEkijikoku ;
					strEkijikoku = OuLib::splitc< deque< string > >( '/' , 
						contstrEkijikoku[iEkiOrder] ) ;
					if ( strEkijikoku.size() != 3 ){
						continue ;
					}
					int iEkiatsukai = atoi( strEkijikoku[0].c_str() ) ;
					CdDedJikoku jikokuChaku( strEkijikoku[1] ) ;
					CdDedJikoku jikokuHatsu( strEkijikoku[2] ) ;
					if ( !( 0 <= iEkiatsukai && iEkiatsukai < 4 ) ){
						iEkiatsukai = 0 ;
					}
					CentDedEkiJikoku	aCentDedEkiJikoku( 
						(CentDedEkiJikoku::EEkiatsukai)iEkiatsukai , 
						jikokuChaku , jikokuHatsu ) ;
					pCentDedRessya->setCentDedEkiJikoku( iEkiOrder , 
						aCentDedEkiJikoku ) ;
				}
			}
		}
		//3.EkiJikoku[]
		if ( iRv >= 0 && !bEkijikokuFound ){
			int iEkiJikokuCount = 0 ;
			{
				string	strValue = aCdConnectedString.getValue( 
					string( nameEkiJikoku ) + "[]" ) ;
				iEkiJikokuCount = atoi( strValue.c_str() ) ;
			}
			
			int iEkiOrder ;
			for ( iEkiOrder = 0 ; iEkiOrder < iEkiJikokuCount ; 
				iEkiOrder ++ ){
				CdConnectedString2	connectedstrEkijikoku ;
				aCdConnectedString.getSubitem( string( nameEkiJikoku ) + 
					"[" + OuLib::stringOf( iEkiOrder ) + "]." ,
					 &connectedstrEkijikoku ) ; 

				//EKiatsukai_Noneの行を出力しないように変更
				if ( connectedstrEkijikoku.size() > 0 ){

					CentDedEkiJikoku	aCentDedEkiJikoku ;
					CentDedEkiJikoku_From_CdConnectedString( 
						&aCentDedEkiJikoku , connectedstrEkijikoku ) ;

					pCentDedRessya->setCentDedEkiJikoku( iEkiOrder , 
						aCentDedEkiJikoku ) ;
				}
			}
		}
		
		//4."Ressyabangou" ;
		if ( iRv >= 0 ){
			string	strValue = aCdConnectedString.getValue( nameRessyabangou ) ;
			pCentDedRessya->setRessyabangou( strValue ) ;
		}
		//5."Ressyamei" ;
		if ( iRv >= 0 ){
			string	strValue = aCdConnectedString.getValue( nameRessyamei ) ;
			pCentDedRessya->setRessyamei( strValue ) ;
		}
		//6."Gousuu" ;
		if ( iRv >= 0 ){
			string	strValue = aCdConnectedString.getValue( nameGousuu ) ;
			pCentDedRessya->setGousuu( strValue ) ;
		}
		//7."Bikou" ;
		if ( iRv >= 0 ){
			string	strValue = aCdConnectedString.getValue( nameBikou ) ;
			pCentDedRessya->setBikou( strValue ) ;
		}
	}
	return ( iRv ) ;
}


// ********************************
//	CentDedRessyaCont
// ********************************
const char nameRessyaCont[]="Rs" ;

int CconvCentDed_01::CentDedRessyaCont_To_CdConnectedString( 
		const CentDedRessyaCont* pCentDedRessyaCont , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;
	
		{
			int iValue = pCentDedRessyaCont->size() ;
			char	szLs[32] ;
			sprintf( szLs , "%d" , iValue ) ;
			pCdConnectedString->setItem( 
				string( nameRessyaCont ) + "[]" , 
				szLs ) ;
		}

		const IfContGet<CentDedRessya*>*	pIfContGet = pCentDedRessyaCont->getIfContGet() ;
		int idxRessya ;
		for ( idxRessya = 0 ; idxRessya < pIfContGet->size() ; 
				idxRessya ++ ){
			CdConnectedString2	connectedstrRessya ;
			CentDedRessya*	pCentDedRessya = 
				pIfContGet->get( idxRessya );
			CentDedRessya_To_CdConnectedString( pCentDedRessya , 
				&connectedstrRessya ) ;
			pCdConnectedString->setSubitem( 
				string( nameRessyaCont ) + "[" + 
					OuLib::stringOf( idxRessya ) + "]." , 
				connectedstrRessya ) ; 
		}
	
	return ( iRv ) ;
}

int CconvCentDed_01::CentDedRessyaCont_From_CdConnectedString( 
		CentDedRessyaCont* pCentDedRessyaCont ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;

	int iRessyaCount = 0 ;
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( 
			string( nameRessyaCont ) + "[]" ) ;
		iRessyaCount = atoi( strValue.c_str() ) ;
		if ( iRessyaCount < 0 ){
			iRv = -32 ;	//	Ressya[][] の値が不正です。
		}
	}

	if ( iRv >= 0 ){
		int idxRessya ;
		for ( idxRessya = 0 ; iRv >= 0 && 
				idxRessya < iRessyaCount ; 
				idxRessya ++ ){
			CdConnectedString2	connectedstrRessya ;
			aCdConnectedString.getSubitem( 
				string( nameRessyaCont ) + "[" + 
					OuLib::stringOf( idxRessya ) + "]." , 
				&connectedstrRessya ) ;

			CentDedRessya	aCentDedRessya( 
				pCentDedRessyaCont->getEkiCount() , 
				pCentDedRessyaCont->getRessyahoukou() ) ;
			
			CentDedRessya_From_CdConnectedString( &aCentDedRessya , 
				connectedstrRessya ) ;
			pCentDedRessyaCont->insert( aCentDedRessya );
		}
	}
	return ( iRv ) ;
}



// ********************************
//	CentDedDia
// ********************************

const char nameDiaName[]="DiaName" ;
const char nameEkiCount[]="EkiCount" ;
const char nameRessya[]="Rc" ;

int CconvCentDed_01::CentDedDia_To_CdConnectedString( 
		const CentDedDia* pCentDedDia , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;

	//1.DiaName
	if ( iRv >= 0 ){
		pCdConnectedString->setItem( nameDiaName , 
			pCentDedDia->getName() ) ;
	}
	//2.EkiCount
	if ( iRv >= 0 ){
		int iValue = pCentDedDia->getEkiCount();
		char	szLs[32] ;
		sprintf( szLs , "%d" , iValue ) ;
		string	strValue = szLs ;
		pCdConnectedString->setItem( nameEkiCount , strValue ) ;
		
	}
	//3.Ressya[Ressyahoukou_Kudari].RessyaCont[]
	//  Ressya[Ressyahoukou_Nobori].RessyaCont[]
	if ( iRv >= 0 ){
		int iRessyahoukou = 0 ; 
		for ( iRessyahoukou = Ressyahoukou_Kudari ; 
				iRessyahoukou <= Ressyahoukou_Nobori ; 
				iRessyahoukou ++ ){
			ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
			string	strRessyahoukou = 
						arERessyahoukou_name[iRessyahoukou].name ;
			
			CdConnectedString2	aCdConnectedString ;
			CentDedRessyaCont_To_CdConnectedString( 
				pCentDedDia->getpCentDedRessyaCont( (ERessyahoukou)iRessyahoukou ) , 
				&aCdConnectedString );
				
			{
				pCdConnectedString->setSubitem(  
					string( nameRessya ) + "[" + strRessyahoukou + "]." , 
					aCdConnectedString ) ;
			}
			
		}
	}
	
	return ( iRv ) ;
}

int CconvCentDed_01::CentDedDia_From_CdConnectedString( 
		CentDedDia* pCentDedDia ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;
	
	//1.DiaName
	string	strDiaName ;
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaName ) ;
		if ( strValue.length() == 0 ){
			iRv = -11 ;	//	DiaName が指定されていません。
		}	else	{
			strDiaName = strValue ;
			pCentDedDia->setName( strDiaName ) ;
		}
	}
	//2.EkiCount
	int iEkiCount = 0 ;
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameEkiCount ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( iValue < 0 ){
			iRv = -22 ;	//	EkiCount の値が不正です。
		}	else	{
			iEkiCount = iValue ;
		}
	}

	//3.Ressya[Ressyahoukou_Kudari][]
	//  Ressya[Ressyahoukou_Nobori][]
	if ( iRv >= 0 ){
		int iRessyahoukou = 0 ; 
		for ( iRessyahoukou = Ressyahoukou_Kudari ; 
				iRessyahoukou <= Ressyahoukou_Nobori ; 
				iRessyahoukou ++ ){
			ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
			string	strRessyahoukou = 
						arERessyahoukou_name[iRessyahoukou].name ;
			
			CdConnectedString2	connectstrSubitem ;
			{
				aCdConnectedString.getSubitem(  
					string( nameRessya ) + "[" + strRessyahoukou + "]." , 
					&connectstrSubitem ) ;
			}
			CentDedRessyaCont	aCentDedRessyaCont( 
				iEkiCount , 
				(ERessyahoukou)iRessyahoukou , 
				pCentDedDia->getRessyasyubetsuCount() ) ;
			CentDedRessyaCont_From_CdConnectedString(
				&aCentDedRessyaCont , 
				connectstrSubitem );
			*pCentDedDia->getpCentDedRessyaCont( (ERessyahoukou)iRessyahoukou ) = aCentDedRessyaCont ; 


		}
	}
	return ( iRv ) ;
}


// ********************************
//	CentDedRosen
// ********************************
const char nameRosenmei[] = "Rosenmei" ;
const char nameEki[] = "Eki" ;
const char nameRessyasyubetsu[] = "Ressyasyubetsu" ;
const char nameDia[] = "Di" ;
const char nameKitenJikoku[] = "KitenJikoku" ;

int CconvCentDed_01::CentDedRosen_To_CdConnectedString( 
		const CentDedRosen* pCentDedRosen , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;

	//1.Rosenmei
	if ( iRv >= 0 ){
		pCdConnectedString->setItem( nameRosenmei , 
			pCentDedRosen->getName() ) ;
	}
	//2.Eki[]
	if ( iRv >= 0 ){
		const IfContGet<const CentDedEki*>*	pCentDedEkiContGet = pCentDedRosen->getCentDedEkiContGet() ;
		int iEkiCount = 0 ;
		{
			int iValue = pCentDedEkiContGet->size() ;
			iEkiCount = iValue ;
			char	szLs[32] ;
			sprintf( szLs , "%d" , iValue ) ;
			pCdConnectedString->setItem( string( nameEki ) + "[]" , 
				szLs ) ;
		}
		
		int iEkiIndex ;
		for ( iEkiIndex = 0 ; iEkiIndex < iEkiCount ; 
			iEkiIndex ++ ){
			CdConnectedString2	connectedstrEki ;
			const CentDedEki*	pCentDedEki = pCentDedEkiContGet->get( iEkiIndex ) ;
			CentDedEki_To_CdConnectedString( *pCentDedEki , &connectedstrEki ) ;
			
			pCdConnectedString->setSubitem( string( nameEki ) + 
				"[" + OuLib::stringOf( iEkiIndex ) + "]." , connectedstrEki ) ; 
		}
	}
	

	//3.Ressyasyubetsu[]
	if ( iRv >= 0 ){
		const IfContGet<CentDedRessyasyubetsu*>*	pCentDedRessyasyubetsuContGet = 
			pCentDedRosen->getCentDedRessyasyubetsuContGet() ;
		int iRessyasyubetsuCount = 0 ;
		{
			int iValue = pCentDedRessyasyubetsuContGet->size() ;
			iRessyasyubetsuCount = iValue ;
			char	szLs[32] ;
			sprintf( szLs , "%d" , iValue ) ;
			pCdConnectedString->setItem( string( nameRessyasyubetsu ) + "[]" , 
				szLs ) ;
		}
		
		int iRessyasyubetsuIndex ;
		for ( iRessyasyubetsuIndex = 0 ; iRessyasyubetsuIndex < iRessyasyubetsuCount ; 
			iRessyasyubetsuIndex ++ ){
			CdConnectedString2	connectedstrRessyasyubetsu ;
			CentDedRessyasyubetsu*	pCentDedRessyasyubetsu = pCentDedRessyasyubetsuContGet->get( iRessyasyubetsuIndex ) ;
			CentDedRessyasyubetsu_To_CdConnectedString( *pCentDedRessyasyubetsu , &connectedstrRessyasyubetsu ) ;
			
			pCdConnectedString->setSubitem( string( nameRessyasyubetsu ) + 
				"[" + OuLib::stringOf( iRessyasyubetsuIndex ) + "]." , connectedstrRessyasyubetsu ) ; 
		}
	}
	
	//4.Dia[]
	if ( iRv >= 0 ){
		const IfContGet<CentDedDia*>*	pCentDedDiaContGet = 
			pCentDedRosen->getCentDedDiaContGet() ;
		int iDiaCount = 0 ;
		{
			int iValue = pCentDedDiaContGet->size() ;
			iDiaCount = iValue ;
			char	szLs[32] ;
			sprintf( szLs , "%d" , iValue ) ;
			pCdConnectedString->setItem( string( nameDia ) + "[]" , 
				szLs ) ;
		}
		
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iDiaIndex < iDiaCount ; 
			iDiaIndex ++ ){
			CdConnectedString2	connectedstrDia ;
			CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( iDiaIndex ) ;
			CentDedDia_To_CdConnectedString( pCentDedDia , &connectedstrDia ) ;
			
			pCdConnectedString->setSubitem( string( nameDia ) + 
				"[" + OuLib::stringOf( iDiaIndex ) + "]." , connectedstrDia ) ; 
		}
	}
	//5.KitenJikoku
	if ( iRv >= 0 ){
		pCdConnectedString->setItem( nameKitenJikoku , 
			pCentDedRosen->getKitenJikoku().encode() ) ;
		
	}

	return ( iRv ) ;
}

int CconvCentDed_01::CentDedRosen_From_CdConnectedString( 
		CentDedRosen* pCentDedRosen ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;

	pCentDedRosen->clear() ;

	//1.Rosenmei
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameRosenmei ) ;
		pCentDedRosen->setName( strValue ) ;
	}
	//2.Eki[]
	int iEkiCount = 0 ;
	if ( iRv >= 0 ){
		CentDedEkiCont* pCentDedEkiCont = pCentDedRosen->getCentDedEkiCont() ;
		{
			string	strValue = aCdConnectedString.getValue( string( nameEki ) + "[]" ) ;
			iEkiCount = atoi( strValue.c_str() ) ;
		}
		
		int iEkiIndex ;
		for ( iEkiIndex = 0 ; iEkiIndex < iEkiCount ; 
			iEkiIndex ++ ){
			CdConnectedString2	connectedstrEki ;
			aCdConnectedString.getSubitem( string( nameEki ) + 
				"[" + OuLib::stringOf( iEkiIndex ) + "]." , &connectedstrEki ) ; 

			CentDedEki	aCentDedEki ;
			CentDedEki_From_CdConnectedString( &aCentDedEki , connectedstrEki ) ;
			pCentDedEkiCont->insert( aCentDedEki ) ;
			
		}
	}
	

	//3.Ressyasyubetsu[]
	int iRessyasyubetsuCount = 0 ;
	if ( iRv >= 0 ){
		CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont = pCentDedRosen->getCentDedRessyasyubetsuCont() ;
		{
			string strValue = aCdConnectedString.getValue( string( nameRessyasyubetsu ) + "[]" ) ;
			iRessyasyubetsuCount = atoi( strValue.c_str() ) ;
			if ( iRessyasyubetsuCount < 1 ){
				iRv = -2 ;	//	『列車種別』は、少なくとも一つは
							//	存在しなくてはなりません。
			}
		}
		
		int iRessyasyubetsuIndex ;
		for ( iRessyasyubetsuIndex = 0 ; iRessyasyubetsuIndex < iRessyasyubetsuCount ; 
			iRessyasyubetsuIndex ++ ){

			CdConnectedString2	connectedstrRessyasyubetsu ;
			aCdConnectedString.getSubitem( string( nameRessyasyubetsu ) + 
				"[" + OuLib::stringOf( iRessyasyubetsuIndex ) + "]." , &connectedstrRessyasyubetsu ) ; 

			CentDedRessyasyubetsu	aCentDedRessyasyubetsu ;
			CentDedRessyasyubetsu_From_CdConnectedString( &aCentDedRessyasyubetsu , connectedstrRessyasyubetsu ) ;
			if ( iRessyasyubetsuIndex == 0 ){
				//CentDedRessyasyubetsu* pCentDedRessyasyubetsu = pCentDedRessyasyubetsuCont->getCentDedRessyasyubetsu( iRessyasyubetsuIndex ) ;
				//*pCentDedRessyasyubetsu = aCentDedRessyasyubetsu ;
				pCentDedRessyasyubetsuCont->set( aCentDedRessyasyubetsu , iRessyasyubetsuIndex ) ;
			}	else	{
				pCentDedRessyasyubetsuCont->insert(  aCentDedRessyasyubetsu ) ;
			}		
		}
	}
	
	//4.Dia[]
	if ( iRv >= 0 ){
		CentDedDiaCont* pCentDedDiaCont = pCentDedRosen->getCentDedDiaCont() ;
		int iDiaCount = 0 ;
		{
			string strValue = aCdConnectedString.getValue( string( nameDia ) + "[]" ) ;
			iDiaCount = atoi( strValue.c_str() ) ;
		}
		
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iDiaIndex < iDiaCount ; 
			iDiaIndex ++ ){
			CdConnectedString2	connectedstrDia ;
			aCdConnectedString.getSubitem( string( nameDia ) + 
				"[" + OuLib::stringOf( iDiaIndex ) + "]." , &connectedstrDia ) ; 

			CentDedDia	aCentDedDia( iEkiCount , iRessyasyubetsuCount ) ;
			CentDedDia_From_CdConnectedString( &aCentDedDia , connectedstrDia ) ;
			pCentDedDiaCont->insert( aCentDedDia ) ;
			
		}
	}
	//5.KitenJikoku
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameKitenJikoku ) ;
		CdDedJikoku	aCdDedJikoku ;
		if ( !strValue.empty() ){
			if ( aCdDedJikoku.decode( strValue ) < 0 ){
				iRv = -52 ;	//	起点時刻の設定が不適切です。
			}
		}
		if ( iRv >= 0 ){
			pCentDedRosen->setKitenJikoku( aCdDedJikoku ) ;
		}
	}


	return ( iRv ) ;
}



