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
//	�����֐�
// --------------------------------


/**
 	CdFontProp �̑������A������ɕϊ����܂��B
  @param aCdFontProp [in]
 	�ϊ��ΏۂƂȂ� CdFontProp ���w�肵�Ă��������B
  @return
 	�ϊ����ʂ�Ԃ��܂��B
 */
static string CdFontProp_to_string( const CdFontProp& aCdFontProp )
{
	CconvDcDrawProp	aConv ;
	return aConv.CdFontProp_to_string( aCdFontProp ) ;
}


/**
 	 CdFontProp_to_string() �ō쐬��������������߂��A
 	CdFontProp �I�u�W�F�N�g�̑����ɔ��f���܂��B
  @param pCdFontProp [out]
 	���̊֐��͂��̃I�u�W�F�N�g�̑����ɁA������̓��e�𔽉f���܂��B
  @param aString [in]
 	 CdFontProp_to_string() �ō쐬������������w�肵�Ă��������B
  @return
 	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 	-	-12 ;	//	PointTextHeight �̒l���s��
 	-	-22 ;	//	LogicalunitTextHeight �̒l���s��
 	-	-32 ;	//	LogicalunitCellHeight �̒l���s��
 	-	-42 ;	//	Facename �̒l���s��
 	-	-52 ;	//	Bold �̒l���s��
 	-	-62 ;	//	Itaric �̒l���s��
 	-	-72 ;	//	Underine �̒l���s��
 	-	-82 ;	//	StrikeOut �̒l���s��
 */
static int CdFontProp_from_string( CdFontProp* pCdFontProp , const string& aString  )
{
	CconvDcDrawProp	aConv ;
	return aConv.CdFontProp_from_string( pCdFontProp , aString ) ;
}

/**
	aCdColorProp �𕶎���ɕϊ����܂��B
@param aCdColorProp [in]
	�ϊ����̒l���w�肵�Ă��������B
@return
	�ϊ����ʂ�Ԃ��܂��B
*/
static string CdColorProp_to_string( const CdColorProp& aCdColorProp )
{

	CconvDcDrawProp	aConv ;
	return aConv.CdColorProp_to_string( aCdColorProp ) ;
}


/**
	������� aCdColorProp �ɕϊ����܂��B
@param aString [in]
	�ϊ����̒l���w�肵�Ă��������B
@return
	�ϊ����ʂ�Ԃ��܂��B
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
		//	�f�t�H���g�l�̏ꍇ�́A�o�͂͂��܂���B
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
	//	��������Ȃ��ꍇ�A�w��̂Ȃ��v�f�͐ݒ�����܂���B
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
				iRv = -12 ;	//	JikokuhyouFont �̓��e���s���ł��B
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
				iRv = -13 ;	//	JikokuhyouVFont �̓��e���s���ł��B
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
			iRv = -22 ;	//	DiaEkimeiFont �̓��e���s���ł��B
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
			iRv = -32 ;	//	DiaJikokuFont �̓��e���s���ł��B
		}	else	{
			aCdDedDispProp.setDiaJikokuFont( aCdFontProp ) ;
		}		
	}
	//4.DiaRessyaFont
	if ( iRv >= 0 ){
		string	strValue = pCNodeContainer->getValue( nameDiaRessyaFont ) ;
		
		//	���̑����́A���Ƃ���ǉ��������߁A��̏ꍇ�ł��G���[�ɂ͂��܂���
		if ( !strValue.empty() ){
			CdFontProp	aCdFontProp ;
			int iResult = CdFontProp_from_string( &aCdFontProp , strValue ) ;
			if ( iResult < 0 ){
				COuErrorInfo aCOuErrorInfo( ERRREASON_InvalidValue() ) ;
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Name() , nameDiaRessyaFont ) ; 
				aCOuErrorInfo.getProp()->setValue( ERRPROP_Value() , strValue ) ; 
				iRv = -32 ;	//	DiaRessyaFont �̓��e���s���ł��B
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
			iRv = -32 ;	//	CommentFont �̓��e���s���ł��B
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
