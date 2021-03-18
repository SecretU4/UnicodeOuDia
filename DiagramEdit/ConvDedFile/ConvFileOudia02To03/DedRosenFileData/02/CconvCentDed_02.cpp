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


(��: 

	OuDia - ��Ԏ����\�����ƂɁA�_�C���O������`�悷��Win32�A�v���P�[�V
�����B

Copyright (C) 2006-2017 take-okm 

���̃v���O�����̓t���[�\�t�g�E�F�A�ł��B���Ȃ��͂�����A�t���[�\�t�g�E�F�A��
�c�ɂ���Ĕ��s���ꂽGNU ��ʌ��O���p������(�o�[�W����3���A����ȍ~�̃o�[�W��
���̂����ǂꂩ)����߂�����̉��ōĔЕz�܂��͉��� ���邱�Ƃ��ł��܂��B

���̃v���O�����͗L�p�ł��邱�Ƃ�����ĔЕz����܂����A*�S���̖��ۏ� *�ł��B
���Ɖ\���̕ۏ؂����ړI�ւ̓K�����́A���O�Ɏ����ꂽ���̂� �܂߁A�S������
���܂���B�ڂ�����GNU ��ʌ��O���p���������������������B

���Ȃ��͂��̃v���O�����Ƌ��ɁAGNU ��ʌ��O���p�������̃R�s�[���ꕔ �󂯎��
�Ă���͂��ł��B�����󂯎���Ă��Ȃ���΁A<http://www.gnu.org/licenses/> ��
�������������B

)

  �����āA���ʂȗ�O�Ƃ��āAtake-okm �͂��̃v���O�����̃R�[�h�� 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  ���邢�� "MFC Version 9.0" �Ɠ������C�Z���X���K�p���ꂽ
  "MFC Version 9.0" �̉��ς��ꂽ�o�[�W����)�ƃ����N���A
  �����N���ꂽ���҂��܂ތ������앨��Еz���鋖��^���܂��B
  ���Ȃ��� "MFC" �ȊO�Ŏg���Ă��邷�ׂ�
  �̃R�[�h�Ɋւ��Ă͑S�ʓI��GNU��ʌ��O���p�����_�񏑂ɏ]��Ȃ����
  �Ȃ�܂���B���Ȃ������̃t�@�C�������ς����Ȃ�΁A���Ȃ��͂��̗�O
  �����Ȃ��̃o�[�W�����̃t�@�C���Ɉ��������݂��邱�Ƃ��ł��܂����A��
  ������`���͂���܂���B������O��݂������Ȃ���΁A���̗�O������
  ���Ȃ��̃o�[�W��������͍폜���Ă��������B)
*/
/*
// ****************************************************************
//	CconvCentDed_02.cpp
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

#include "CconvCentDed_02.h"
#include "str/strToInt.h"
#include "str/stringsplit.h"

/** �z�� a �̗v�f����Ԃ��܂��B */
#define arrayof(a) (sizeof(a)/sizeof(a[0]))

// ********************************
//	CentDedEki
// ********************************
const char nameEkimei[] = "Ekimei" ;
const char nameEkijikokukeisiki[] = "Ekijikokukeisiki" ;
const char nameEkikibo[] = "Ekikibo" ;
const char nameKyoukaisen[] = "Kyoukaisen" ;

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


int CconvCentDed_02::CentDedEki_To_CdConnectedString( 
		const CentDedEki& aCentDedEki , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;
	// --------------------------------	
	//1.Ekimei
	if ( iRv >= 0 ){
		if ( aCentDedEki.getEkimei().empty() ){
			iRv = -11 ;	//	Ekimei ���w�肳��Ă��܂���B
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
			iRv = -22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
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
			iRv = -32 ;	//	Ekikibo �̒l���s���ł��B
		}	else	{
			pCdConnectedString->setItem( nameEkikibo , 
				arEkikibo_name[idx].name ) ;
		}
	}
	//4.Kyoukaisen
	if ( iRv >= 0 ){
		pCdConnectedString->setItem( nameKyoukaisen , 
			aCentDedEki.getKyoukaisen() ? "1" : "" ) ;
	}
	// --------------------------------	
	return ( iRv ) ;
}


int CconvCentDed_02::CentDedEki_From_CdConnectedString( 
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
			iRv = -11 ;	//	Ekimei ���w�肳��Ă��܂���B
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
			iRv = -22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
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
			iRv = -32 ;	//	Ekikibo �̒l���s���ł��B
		}	else	{
			aCentDedEki.setEkikibo( arEkikibo_name[idx].value ) ;
		}
	}
	//4.Kyoukaisen
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameKyoukaisen ) ; 
		aCentDedEki.setKyoukaisen( atoi( strValue.c_str() ) == 1 ) ;
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



int CconvCentDed_02::CentDedRessyasyubetsu_To_CdConnectedString( 
		const CentDedRessyasyubetsu& aCentDedRessyasyubetsu , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;

	// --------------------------------	
	//1.Syubetsumei
	if ( iRv >= 0 ){
		if ( aCentDedRessyasyubetsu.getSyubetsumei().empty() ){
			iRv = -11 ;	//	Syubetsumei ���w�肳��Ă��܂���B
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
			iRv = -52 ;	//	DiagramSenStyle �̒l���s���ł��B
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

int CconvCentDed_02::CentDedRessyasyubetsu_From_CdConnectedString( 
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
			iRv = -11 ;	//	Syubetsumei ���w�肳��Ă��܂���B
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
			iRv = -52 ;	//	DiagramSenStyle �̒l���s���ł��B
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

void CconvCentDed_02::CentDedRessyasyubetsu_to_CDcdFreeLineProp(
	COLORREF aCOLORREF ,
	CentDedRessyasyubetsu::ESenStyle eSenStyle , 
	bool bIsBold , 
	CDcdFreeLine::CdLineProp* pCdLineProp )	
{
		pCdLineProp->setColor( aCOLORREF ) ;
		switch( eSenStyle ){
		 // ���� 
		 case CentDedRessyasyubetsu::SenStyle_Jissen :
			pCdLineProp->setLinestyle( LINESTYLE_SOLID ) ;
			break ;
		 // �j��
		 case CentDedRessyasyubetsu::SenStyle_Hasen :
			pCdLineProp->setLinestyle( LINESTYLE_DASH ) ;
			break ;
		 // �_��
		 case CentDedRessyasyubetsu::SenStyle_Tensen :
			pCdLineProp->setLinestyle( LINESTYLE_DOT ) ;
			break ;
		 // ��_����
		 case CentDedRessyasyubetsu::SenStyle_Ittensasen :
			pCdLineProp->setLinestyle( LINESTYLE_DASH_DOT ) ;
			break ;
		}
		pCdLineProp->setLogicalunitWidth( bIsBold ? 2 : 1 ) ;

}


// ********************************
//	CentDedRessya
// ********************************

const char nameRessyahoukou[]="Houkou" ;
const char nameRessyasyubetsuIndex[]="Syubetsu" ;
const char nameEkiJikoku3[]="EkiJikoku" ;
const char nameRessyabangou[]="Ressyabangou" ;
const char nameRessyamei[]="Ressyamei" ;
const char nameGousuu[]="Gousuu" ;
const char nameBikou[]="Bikou" ;

const static struct {
	ERessyahoukou	value ; 
	const char* name ;
}	arERessyahoukou_name[] = {
	{ Ressyahoukou_Kudari , "Kudari" },
	{ Ressyahoukou_Nobori , "Nobori" },
};




int CconvCentDed_02::CentDedRessya_To_CdConnectedString( 
		const CentDedRessya* pCentDedRessya , 
		CdConnectedString2* pCdConnectedString ) 
{
	int iRv = 0 ;
	// --------------------------------
	//0.IsNull
	bool bIsNull = false ;
	if ( iRv >= 0 ){
		bIsNull = pCentDedRessya->isNull() ;
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
				iRv = -12 ;	//	Ressyahoukou �̒l���s���ł��B
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

		//3.EkiJikoku3
		if ( iRv >= 0 ){
			vector<string>	contstrEkijikoku ;
			int iEkiOrder ;
			for ( iEkiOrder = 0 ; 
					iEkiOrder <= pCentDedRessya->getSyuuchakuEki() ; 
					iEkiOrder ++ ){
				//CdConnectedString2	connectedstrEkijikoku ;
				CentDedEkiJikoku	aCentDedEkiJikoku = 
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
				
				string	strEkiatsukai ;
				string strChaku ;
				string strHatsu ;
				//	�w��
				if ( aCentDedEkiJikoku.getEkiatsukai() != CentDedEkiJikoku::Ekiatsukai_None ){
					strEkiatsukai = OuLib::stringOf( 
						(int)aCentDedEkiJikoku.getEkiatsukai() ) ;
				}
				//	������
				if ( !aCentDedEkiJikoku.getChakujikoku().isNull() ){
					strChaku = aCentDedEkiJikoku.getChakujikoku().encode(
						CdDedJikoku::Format_NoColon |
						CdDedJikoku::Format_HourZeroToNone |
						CdDedJikoku::Format_NoSecond ) ;
				}
				//	������
				if ( !aCentDedEkiJikoku.getHatsujikoku().isNull() ){
					strHatsu = aCentDedEkiJikoku.getHatsujikoku().encode(
						CdDedJikoku::Format_NoColon |
						CdDedJikoku::Format_HourZeroToNone |
						CdDedJikoku::Format_NoSecond ) ;
				}

				string	strEkijikoku ;
				strEkijikoku.reserve( 32 ) ;
				if ( !strEkiatsukai.empty() ){
					strEkijikoku += strEkiatsukai ;
					if ( !strChaku.empty() || !strHatsu.empty() ){
						strEkijikoku += ';' ;
						if ( !strChaku.empty() ){
							strEkijikoku += strChaku ;
							strEkijikoku += '/' ;
						}
						strEkijikoku += strHatsu ;
					}
				}

				contstrEkijikoku.push_back( strEkijikoku ) ;
			}
			string strEkijikoku2 = OuLib::joinc( ',' , contstrEkijikoku ) ;
			pCdConnectedString->setItem( string( nameEkiJikoku3 ) ,
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

int CconvCentDed_02::CentDedRessya_From_CdConnectedString( 
		CentDedRessya* pCentDedRessya ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;

	// --------------------------------
	//0.RessyasyubetsuIndex ;
	bool	bIsNull = false ;
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( 
			nameRessyasyubetsuIndex ) ;
		if ( strValue.empty() ){
			pCentDedRessya->clear() ;
			bIsNull = true ;
		}	else	{
			int iValue = atoi( strValue.c_str() ) ;
			pCentDedRessya->setRessyasyubetsuIndex( iValue ) ;
		}
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
				iRv = -12 ;	//	Ressyahoukou �̒l���s���ł��B
			}
		}


		
		//3.EkiJikoku3
		if ( iRv >= 0 ){
			string strEkijikoku2 = aCdConnectedString.getValue( 
				nameEkiJikoku3 ) ;
			if ( !strEkijikoku2.empty() ){
				deque<string>	contstrEkijikoku = OuLib::splitc< deque< string > >( 
					',' , strEkijikoku2 ) ;
					
				int iEkiOrder ;
				for ( iEkiOrder = 0 ; 
					iEkiOrder < contstrEkijikoku.size() && 
					iEkiOrder < pCentDedRessya->getCentDedEkiJikokuCount() ; 
					iEkiOrder ++ ){
					string strEkijikoku = contstrEkijikoku[iEkiOrder] ;

					string	strEkiatsukai ;
					string strChaku ;
					string strHatsu ;

					string::size_type pos = 0 ;
					pos = strEkijikoku.find( ';' ) ;
					if ( pos != string::npos ){
						strEkiatsukai = strEkijikoku.substr( 0 , pos ) ;
						strEkijikoku.erase( 0 , pos + 1 ) ;
						
						pos = strEkijikoku.find( '/' ) ;
						if ( pos != string::npos ){
							strChaku = strEkijikoku.substr( 0 , pos ) ;
							strEkijikoku.erase( 0 , pos + 1 ) ;
						}
						strHatsu = strEkijikoku ;
					}	else	{
						strEkiatsukai = strEkijikoku ;
					}
					//strEkiatsukai = �w���E�󕶎���́w�^�s�Ȃ��x�B"1"�`"3" ;
					//strChaku = ������
					//strHatsu = ������
					
					int iEkiatsukai = 0 ;
					if ( !strEkiatsukai.empty() ){
						iEkiatsukai = atoi( strEkiatsukai.c_str() ) ;
					}
					if ( !( 0 <= iEkiatsukai && iEkiatsukai < 4 ) ){
						iEkiatsukai = 0 ;
					}
					CdDedJikoku jikokuChaku( strChaku ) ;
					CdDedJikoku jikokuHatsu( strHatsu ) ;
					CentDedEkiJikoku	aCentDedEkiJikoku( 
						(CentDedEkiJikoku::EEkiatsukai)iEkiatsukai , 
						jikokuChaku , jikokuHatsu ) ;
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
const char nameRessyaCont[]="RessyaCont" ;

int CconvCentDed_02::CentDedRessyaCont_To_CdConnectedString( 
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
		

		int idxRessya ;
		for ( idxRessya = 0 ; idxRessya < pCentDedRessyaCont->size() ; 
				idxRessya ++ ){
			CdConnectedString2	connectedstrRessya ;
			CentDedRessya*	pCentDedRessya = 
				pCentDedRessyaCont->getIfContGet()->get( idxRessya );
			CentDedRessya_To_CdConnectedString( pCentDedRessya , 
				&connectedstrRessya ) ;
			pCdConnectedString->setSubitem( 
				string( nameRessyaCont ) + "[" + 
					OuLib::stringOf( idxRessya ) + "]." , 
				connectedstrRessya ) ; 
		}
	
	return ( iRv ) ;
}

int CconvCentDed_02::CentDedRessyaCont_From_CdConnectedString( 
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
			iRv = -32 ;	//	Ressya[][] �̒l���s���ł��B
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
const char nameRessya[]="Ressya" ;

int CconvCentDed_02::CentDedDia_To_CdConnectedString( 
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

int CconvCentDed_02::CentDedDia_From_CdConnectedString( 
		CentDedDia* pCentDedDia ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;
	
	//1.DiaName
	string	strDiaName ;
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaName ) ;
		if ( strValue.length() == 0 ){
			iRv = -11 ;	//	DiaName ���w�肳��Ă��܂���B
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
			iRv = -22 ;	//	EkiCount �̒l���s���ł��B
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
const char nameDia[] = "Dia" ;
const char nameKitenJikoku[] = "KitenJikoku" ;
int CconvCentDed_02::CentDedRosen_To_CdConnectedString( 
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
		const IfContGet<const CentDedEki*>* pCentDedEkiContGet = pCentDedRosen->getCentDedEkiContGet() ;
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
		const IfContGet<CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet = pCentDedRosen->getCentDedRessyasyubetsuContGet() ;
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
		const IfContGet<CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaContGet() ;
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

int CconvCentDed_02::CentDedRosen_From_CdConnectedString( 
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
				iRv = -2 ;	//	�w��Ԏ�ʁx�́A���Ȃ��Ƃ����
							//	���݂��Ȃ��Ă͂Ȃ�܂���B
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
				//CentDedRessyasyubetsu* pCentDedRessyasyubetsu = pCentDedRosen->getCentDedRessyasyubetsu( iRessyasyubetsuIndex ) ;
				//*pCentDedRessyasyubetsu = aCentDedRessyasyubetsu ;
				pCentDedRessyasyubetsuCont->set( aCentDedRessyasyubetsu , iRessyasyubetsuIndex ) ;
			}	else	{
				pCentDedRessyasyubetsuCont->insert( aCentDedRessyasyubetsu ) ;
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
				iRv = -52 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
			}
		}
		if ( iRv >= 0 ){
			pCentDedRosen->setKitenJikoku( aCdDedJikoku ) ;
		}
	}


	return ( iRv ) ;
}



