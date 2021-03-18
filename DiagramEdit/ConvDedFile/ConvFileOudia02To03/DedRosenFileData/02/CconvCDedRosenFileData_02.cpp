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
//	CconvCDedRosenFileData_02.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

/*rinji	�x�����邽�ߗ}���B
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
*/

#include "CconvCDedRosenFileData_02.h"
#include "CconvCentDed_02.h"
#include "str/CdConnectedString2.h"
#include "str/strToInt.h"
#include "logmsg/LogMsg.h"

// --------------------------------
//	�����֐�
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
 *	CdFontProp �̑������A CdConnectedString2 �I�u�W�F�N�g�ɒǉ����܂��B
 * @param aCdFontProp [in]
 *	�ϊ��ΏۂƂȂ� CdFontProp ���w�肵�Ă��������B
 * @param pCdConnectedString2 [in,out]
 *	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
 *	�ǉ����܂��B
 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
 *	�ێ����܂��B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
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
 *	 CdConnectedString2 �I�u�W�F�N�g����A
 *	 CdFontProp_to_CdConnectedString2() �Œǉ����� CdItem ��ǂݎ��A
 *	CdFontProp �I�u�W�F�N�g�̑����ɔ��f���܂��B
 * @param pCdFontProp [out]
 *	���̊֐��͂��̃I�u�W�F�N�g�̑����ɁA������̓��e�𔽉f���܂��B
 * @param aCdConnectedString [in]
 *	 CdFontProp_to_CdConnectedString2() �Œǉ����� CdItem ������
 *	 CdConnectedString2 �I�u�W�F�N�g���w�肵�Ă��������B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	-12 ;	//	PointTextHeight �̒l���s��
 *	-	-22 ;	//	LogicalunitTextHeight �̒l���s��
 *	-	-32 ;	//	LogicalunitCellHeight �̒l���s��
 *	-	-42 ;	//	Facename �̒l���s��
 *	-	-52 ;	//	Bold �̒l���s��
 *	-	-62 ;	//	Itaric �̒l���s��
 *	-	-72 ;	//	Underine �̒l���s��
 *	-	-82 ;	//	StrikeOut �̒l���s��
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
			iRv = -12 ;	//	PointTextHeight �̒l���s��
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
			iRv = -22 ;	//	LogicalunitTextHeight �̒l���s��
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
			iRv = -32 ;	//	LogicalunitCellHeight �̒l���s��
		}	else if ( 0 < iValue )	{
			aCdFontProp.setLogicalunitCellHeight( iValue ) ;
		}
	}
	//4.Facename 
	if ( iRv >= 0 ){
		string strValue = aCdConnectedString.getValue( 
			nameFacename ) ;
		if ( strValue.length() == 0 ){
			iRv = -42 ;	//	Facename �̒l���s��
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
			iRv = -52 ;	//	Bold �̒l���s��
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
			iRv = -62 ;	//	Itaric �̒l���s��
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
			iRv = -72 ;	//	Underine �̒l���s��
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
			iRv = -82 ;	//	StrikeOut �̒l���s��
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
 *	CdFontProp �̑������A������ɕϊ����܂��B
 * @param aCdFontProp [in]
 *	�ϊ��ΏۂƂȂ� CdFontProp ���w�肵�Ă��������B
 * @return
 *	�ϊ����ʂ�Ԃ��܂��B
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
 *	 CdFontProp_to_string() �ō쐬��������������߂��A
 *	CdFontProp �I�u�W�F�N�g�̑����ɔ��f���܂��B
 * @param pCdFontProp [out]
 *	���̊֐��͂��̃I�u�W�F�N�g�̑����ɁA������̓��e�𔽉f���܂��B
 * @param aString [in]
 *	 CdFontProp_to_string() �ō쐬������������w�肵�Ă��������B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	-12 ;	//	PointTextHeight �̒l���s��
 *	-	-22 ;	//	LogicalunitTextHeight �̒l���s��
 *	-	-32 ;	//	LogicalunitCellHeight �̒l���s��
 *	-	-42 ;	//	Facename �̒l���s��
 *	-	-52 ;	//	Bold �̒l���s��
 *	-	-62 ;	//	Itaric �̒l���s��
 *	-	-72 ;	//	Underine �̒l���s��
 *	-	-82 ;	//	StrikeOut �̒l���s��
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
//	CconvCDedRosenFileData_02
// ****************************************************************
// ********************************
//	CdDedDispProp
// ********************************
const char nameJikokuhyouFont[]="JikokuhyouFont" ;
const char nameDiaEkimeiFont[]="DiaEkimeiFont" ;
const char nameDiaJikokuFont[]="DiaJikokuFont" ;
const char nameDiaMojiColor[]="DiaMojiColor" ;
const char nameDiaHaikeiColor[]="DiaHaikeiColor" ;
const char nameDiaRessyaColor[]="DiaRessyaColor" ;
const char nameDiaJikuColor[]="DiaJikuColor" ;
const char nameEkimeiLength[] = "EkimeiLength" ;
const char nameDisplayRessyabangou[]="DisplayRessyabangou" ;
const char nameDisplayRessyamei[]="DisplayRessyamei" ;
const char nameDiaRessyajouhouHyoujiEkiOrderKudari[]="DiaRessyajouhouHyoujiEkiOrderKudari" ;
const char nameDiaRessyajouhouHyoujiEkiOrderNobori[]="DiaRessyajouhouHyoujiEkiOrderNobori" ;



int CconvCDedRosenFileData_02::CdDedDispProp_to_CdConnectedString( 
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
	//4.DiaMojiColor
	if ( iRv >= 0 ){
		COLORREF	dwColor = aCdDedDispProp.getDiaMojiColor() ;
		char	szLs[32] ;
		sprintf( szLs , "%08X" , dwColor ) ;
		pCdConnectedString->setItem( nameDiaMojiColor , szLs ) ;
	}
	//5.DiaHaikeiColor
	if ( iRv >= 0 ){
		COLORREF	dwColor = aCdDedDispProp.getDiaHaikeiColor() ;
		char	szLs[32] ;
		sprintf( szLs , "%08X" , dwColor ) ;
		pCdConnectedString->setItem( nameDiaHaikeiColor , szLs ) ;
	}
	//6.DiaRessyaColor
	if ( iRv >= 0 ){
		COLORREF	dwColor = aCdDedDispProp.getDiaRessyaColor() ;
		char	szLs[32] ;
		sprintf( szLs , "%08X" , dwColor ) ;
		pCdConnectedString->setItem( nameDiaRessyaColor , szLs ) ;
	}
	//7.DiaJikuColor
	if ( iRv >= 0 ){
		COLORREF	dwColor = aCdDedDispProp.getDiaJikuColor() ;
		char	szLs[32] ;
		sprintf( szLs , "%08X" , dwColor ) ;
		pCdConnectedString->setItem( nameDiaJikuColor , szLs ) ;
	}
	//8.EkimeiLength
	if ( iRv >= 0 ){
		pCdConnectedString->setItem( nameEkimeiLength , 
			OuLib::stringOf( aCdDedDispProp.getEkimeiLength() ) ) ;
	}
	//10.DiaRessyajouhouHyoujiEkiOrderKudari
	if ( iRv >= 0 ){
		int iValue = aCdDedDispProp.getDiaRessyajouhouHyoujiEkiOrder( Ressyahoukou_Kudari ) ;
		char	szLs[32] ;
		sprintf( szLs , "%d" , iValue ) ;
		pCdConnectedString->setItem( nameDiaRessyajouhouHyoujiEkiOrderKudari , szLs  ) ;
	}
	//11.DiaRessyajouhouHyoujiEkiOrderNobori
	if ( iRv >= 0 ){
		int iValue = aCdDedDispProp.getDiaRessyajouhouHyoujiEkiOrder( Ressyahoukou_Nobori ) ;
		char	szLs[32] ;
		sprintf( szLs , "%d" , iValue ) ;
		pCdConnectedString->setItem( nameDiaRessyajouhouHyoujiEkiOrderNobori , szLs  ) ;
	}

	return ( iRv ) ;
}

int CconvCDedRosenFileData_02::CdDedDispProp_from_CdConnectedString( 
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
			iRv = -12 ;	//	JikokuhyouFont �̓��e���s���ł��B
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
			iRv = -22 ;	//	DiaEkimeiFont �̓��e���s���ł��B
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
			iRv = -32 ;	//	DiaJikokuFont �̓��e���s���ł��B
		}	else	{
			aCdDedDispProp.setDiaJikokuFont( aCdFontProp ) ;
		}		
	}
	//4.DiaMojiColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaMojiColor ) ;
		unsigned long dwColor = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCdDedDispProp.setDiaMojiColor( dwColor ) ;
	}
	//5.DiaHaikeiColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaHaikeiColor ) ;
		unsigned long dwColor = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCdDedDispProp.setDiaHaikeiColor( dwColor ) ;
	}
	//6.DiaRessyaColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaRessyaColor ) ;
		unsigned long dwColor = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCdDedDispProp.setDiaRessyaColor( dwColor ) ;
	}
	//7.DiaJikuColor
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaJikuColor ) ;
		unsigned long dwColor = strtoul( strValue.c_str() , NULL , 16 ) ;
		aCdDedDispProp.setDiaJikuColor( dwColor ) ;
	}
	//8.EkimeiLength
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameEkimeiLength ) ;
		if ( !strValue.empty() ){
			int iValue = OuLib::intOf( strValue ) ;
			if ( iValue > 0 ){
				aCdDedDispProp.setEkimeiLength( iValue ) ;
			}
		}	
	}
	//10.DiaRessyajouhouHyoujiEkiOrderKudari
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaRessyajouhouHyoujiEkiOrderKudari ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <= iValue ) ){
			iRv = -102 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
		}	else	{
			aCdDedDispProp.setDiaRessyajouhouHyoujiEkiOrder( Ressyahoukou_Kudari , iValue ) ;
		}
	}
	//11.DiaRessyajouhouHyoujiEkiOrderNobori
	if ( iRv >= 0 ){
		string	strValue = aCdConnectedString.getValue( nameDiaRessyajouhouHyoujiEkiOrderNobori ) ;
		int iValue = atoi( strValue.c_str() ) ;
		if ( !( 0 <= iValue ) ){
			iRv = -112 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B
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



// ********************************
//	CDedRosenFileData
// ********************************
const char nameRosen[]="Rosen" ;
const char nameDispProp[]="DispProp" ;


int CconvCDedRosenFileData_02::CDedRosenFileData_to_CdConnectedString( 
		const CDedRosenFileData& aCDedRosenFileData , 
		CdConnectedString2* pCdConnectedString ) 
{
	LogMsg( "CDedRosenFileData_to_CdConnectedString()" ) ;
	int iRv = 0 ;
	//1.Rosen
	if ( iRv >= 0 ){
		CdConnectedString2	connectstrRosen ;
		CconvCentDed_02 aCconvCentDed_02 ;
		int iResult = aCconvCentDed_02.CentDedRosen_To_CdConnectedString( 
			aCDedRosenFileData.getCentDedRosen() ,
			&connectstrRosen ) ;
		if ( iResult < 0 ){
			iRv = -11 ;	//	Rosen �̓��e���s��
		}	else	{
			pCdConnectedString->setSubitem( 
				string( nameRosen ) + '.' , connectstrRosen ) ;
		}
	}
	//2.DispProp
	LogMsg( "CDedRosenFileData_to_CdConnectedString()1" ) ;
	if ( iRv >= 0 ){
		CdConnectedString2	connectstrDispProp ;
		int iResult = CdDedDispProp_to_CdConnectedString( 
			aCDedRosenFileData.getCdDedDispProp() ,
			&connectstrDispProp ) ;
		if ( iResult < 0 ){
			iRv = -21 ;	//	DispProp �̓��e���s��
		}	else	{
			pCdConnectedString->setSubitem( 
				string( nameDispProp ) + '.' , connectstrDispProp ) ;
		}
	}


	LogMsg( "CDedRosenFileData_to_CdConnectedString()=%d" , iRv ) ;
	return ( iRv ) ;
}

int CconvCDedRosenFileData_02::CDedRosenFileData_from_CdConnectedString( 
		CDedRosenFileData* pCDedRosenFileData ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;

	if ( iRv >= 0 ){
		pCDedRosenFileData->clear() ;
	}
	
	//1.Rosen

	if ( iRv >= 0 ){
		CdConnectedString2	connectstrRosen ;
		aCdConnectedString.getSubitem( 
				string( nameRosen ) + '.' , &connectstrRosen ) ;
		CentDedRosen	aCentDedRosen ;
		CconvCentDed_02 aCconvCentDed_02 ;
		int iResult = aCconvCentDed_02.CentDedRosen_From_CdConnectedString( 
			&aCentDedRosen ,connectstrRosen ) ;
		if ( iResult < 0 ){
			iRv = -11 ;	//	Rosen �̓��e���s��
		}	else	{
			*pCDedRosenFileData->getCentDedRosen() = aCentDedRosen ;
		}
	}
	//2.DispProp
	if ( iRv >= 0 ){
		CdConnectedString2	connectstrDispProp ;
		aCdConnectedString.getSubitem( 
				string( nameDispProp ) + '.' , &connectstrDispProp ) ;
		CdDedDispProp	aCdDedDispProp ;
		
		int iResult = CdDedDispProp_from_CdConnectedString( 
			&aCdDedDispProp ,
			connectstrDispProp ) ;
		if ( iResult < 0 ){
			iRv = -21 ;	//	DispProp �̓��e���s��
		}	else	{
			pCDedRosenFileData->setCdDedDispProp( aCdDedDispProp ) ;
		}
	}

	return ( iRv ) ;
}

int CconvCDedRosenFileData_02::CDedRosenFileData_to_string( 
		const CDedRosenFileData& aCDedRosenFileData , 
		string* pString ) 
{
	LogMsg( "CDedRosenFileData_to_string()" ) ;

	int iRv = 0 ;
	string	strRv ;
	CdConnectedString2	aCdConnectedString2( '\n' , '=' , false ) ;
	if ( iRv >= 0 ){
		int iResult = CDedRosenFileData_to_CdConnectedString( 
			aCDedRosenFileData , &aCdConnectedString2 ) ;
		//iResult = 
		//	-11 ;	//	Rosen �̓��e���s��
		//	-21 ;	//	DispProp �̓��e���s��
		if ( iResult < 0 ){
			iRv = iResult ;
		}
	}
	
	LogMsg( "CDedRosenFileData_to_string()1" ) ;
	if ( iRv >= 0 ){
		strRv = aCdConnectedString2.encode() ;
	}
	if ( iRv >= 0 ){
		if ( pString != NULL ){
			*pString = strRv ;
		}
	}

	LogMsg( "CDedRosenFileData_to_string()=%d" , iRv ) ;
	return ( iRv ) ;
}


int CconvCDedRosenFileData_02::CDedRosenFileData_from_string( 
		CDedRosenFileData* pCDedRosenFileData ,
		const string& aString ) 
{
	LogMsg( "CDedRosenFileData_from_string()" ) ;

	int iRv = 0 ;
	string	strRv ;
	CdConnectedString2	aCdConnectedString2( aString , '\n' ) ;

	LogMsg( "CDedRosenFileData_from_string()1" ) ;

	pCDedRosenFileData->clear() ;
	if ( iRv >= 0 ){
		int iResult = CDedRosenFileData_from_CdConnectedString( 
			pCDedRosenFileData , aCdConnectedString2 ) ;
		//iResult = 
		//	-11 ;	//	Rosen �̓��e���s��
		//	-21 ;	//	DispProp �̓��e���s��
		if ( iResult < 0 ){
			iRv = iResult ;
		}
	}
	LogMsg( "CDedRosenFileData_from_string()=%d" , iRv ) ;
	return ( iRv ) ;
}


