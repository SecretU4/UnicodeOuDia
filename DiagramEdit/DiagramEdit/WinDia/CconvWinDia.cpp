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
//	CconvWinDia.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include "CconvWinDia.h"
#include "str/strToInt.h"
#include "str/strLf.h"
#include "str/stringSplit.h"
#include "str/CStrCharSizeMb.h"
#include "str/strprintf.h"

#include "NsMu/CMup_deque.h"
#include "NsMu/CaMui.h"


namespace WinDia{ 

using namespace OuLib ;
using namespace std ;

/** �����̏�����ێ����܂��B */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	true ,		//	NoColon 
	CdDedJikoku::CConv::EHour_ZeroToNone ,	// ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" ���폜���܂��B
	CdDedJikoku::CConv::ESecond_NoSecond 	// �b����ɏo�͂��܂���B 
	) ;

// --------------------------------
//	WinDIA �f�t�H���g
// --------------------------------
const CdColorProp	g_WinDIAColor[] = {
	CdColorProp(  0,  0,255) ,	//  ��
	CdColorProp(  0,255,  0) ,	//  ��
	CdColorProp(  0,  0,132) ,	//  �Â���
	CdColorProp(  0,130,  0) ,	//  �Â���
	CdColorProp(  0,255,255) ,	//  
	CdColorProp(255,  0,  0) ,	//  ��
	CdColorProp(  0,130,132) ,	//  
	CdColorProp(132,  0,  0) ,	//  
	CdColorProp(255,  0,255) ,	//  
	CdColorProp(255,255,  0) ,	//  ��
	CdColorProp(132,  0,132) ,	//  
	CdColorProp(132,130,  0) ,	//  
	CdColorProp(  0,  0,  0) ,	//  ��
	CdColorProp(132,130,132) ,	//
	CdColorProp(198,195,198) ,	//
	CdColorProp(255,255,255)  	//  ��
};

const CentDedRessyasyubetsu g_WinDiaRessyasyubetsu[] = {
	CentDedRessyasyubetsu( "����"     , "" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	// 0
	CentDedRessyasyubetsu( "����"     , "����" ,
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	// 1
	CentDedRessyasyubetsu( "���ʉ���" , "����" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	// 2
	CentDedRessyasyubetsu( "�V����"   , "�V��" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	// 3
	CentDedRessyasyubetsu( "�ʋΉ���" , "�ʉ�" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	// 4
	CentDedRessyasyubetsu( "���}"     , "���}" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , true  ) ,	// 5
	CentDedRessyasyubetsu( "�}�s"     , "�}�s" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , true  ) ,	// 6
	CentDedRessyasyubetsu( "�����}�s" , "���}" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , true  ) ,	// 7
	CentDedRessyasyubetsu( "���}"     , "���}" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , true  ) ,	// 8
	CentDedRessyasyubetsu( "�������}" , "����" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , true  ) ,	// 9
	CentDedRessyasyubetsu( "�ʋΏ��}" , "�ʏ�" ,
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , true  ) ,	//10
	CentDedRessyasyubetsu( "�ʋ΋}�s" , "�ʋ}" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , true  ) ,	//11
	CentDedRessyasyubetsu( "��ԉ���" , "���" ,
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	//12
	CentDedRessyasyubetsu( "��ԋ}�s" , "��}" ,
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , true  ) ,	//13
	CentDedRessyasyubetsu( "��"     , "��" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Ittensasen , false ) ,	//14
	CentDedRessyasyubetsu( "�ݕ�"     , "�ݕ�" ,
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Hasen , false ) ,	//15
	CentDedRessyasyubetsu( "�}�s�ݕ�" , "�}��" ,
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Hasen , true ) ,	//16

	CentDedRessyasyubetsu( ""     , "" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	//17
	CentDedRessyasyubetsu( ""     , "" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	//18
	CentDedRessyasyubetsu( ""     , "" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	//19
	CentDedRessyasyubetsu( ""     , "" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	//20
	CentDedRessyasyubetsu( ""     , "" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	//21
	CentDedRessyasyubetsu( ""     , "" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	//22
	CentDedRessyasyubetsu( ""     , "" , 
		g_WinDIAColor[12] , g_WinDIAColor[12] ,
		CentDedRessyasyubetsu::SenStyle_Jissen , false ) ,	//23
};
// --------------------------------
//	�����֐�
// --------------------------------
/**
 *	�w��̐F�Ɉ�ԋ߂� WinDIA �F�ԍ����擾���܂��B
 * @param aCdColorProp [in]
 *	�Ώۂ̐F���w�肵�ĉ������B
 * @return
 *	aCdColorProp �Ɉ�ԋ߂� WinDIA �F�ԍ����擾���܂��B�͈͂� 0 �` 15 �ł��B
 */
static int getNearestWinDIAColorNumber( const CdColorProp& aCdColorProp ) 
{
	int idxMin = 0 ;
	unsigned long valueMin = 0 ;
	
	for ( int idx = 0 ; idx < sizeof(g_WinDIAColor) / sizeof(g_WinDIAColor[0]) ;
			idx ++ ){
		unsigned long valueTotal = 0 ;
		unsigned long value ;
		value = aCdColorProp.getRed() - g_WinDIAColor[idx].getRed() ;
		value *= value ;
		valueTotal += value ;
		value = aCdColorProp.getGreen() - g_WinDIAColor[idx].getGreen() ;
		value *= value ;
		valueTotal += value ;
		value = aCdColorProp.getBlue() - g_WinDIAColor[idx].getBlue() ;
		value *= value ;
		valueTotal += value ;
		
		if ( idx == 0 || valueMin > valueTotal ){
			valueMin = valueTotal ;
			idxMin = idx ;
		}
	}
	return ( idxMin ) ;
}
// --------------------------------
//	������𕪊�
// --------------------------------
/**
 *	��������P�s���Ƃɕ������A�R���e�i�Ɋi�[���܂��B
 *
 *	������ "\" �̍s�ɂ��ẮA���̍s�Ƃ̌������s���܂��B
 * @param pContStr [out]
 *	���̊֐��́A���̃R���e�i�̖����ɁA�P�s���̕������ǉ����܂��B
 *	�R���e�i������܂ŕێ����Ă����f�[�^�͈ێ����܂��B
 * @param aString [in]
 *	�������镶������w�肵�ĉ������B
 */
static void ContStrFromString( 
	Mui< string >* pContStr ,
	const string& aString )
{
	deque< string >	contstr = splitc< deque< string > >( '\n' , 
		aString ) ;

	CaMup_vector< deque< string > > aSrc( &contstr )  ;
	CaMui<string>	aDst( pContStr ) ;
	aDst.insert( &aSrc ) ;

	//pContStr = aString �̓��e���P�s���Ƃɂ����z��
	
	// --------------------------------
	//	������ '\' �̍s�́A���̍s�ƌ���
	// --------------------------------

	string	strCurr ;
	string	strNext ;
	for ( int idx = 0 ; idx < pContStr->size() - 1 ; idx ++ ){
		strCurr = pContStr->get( idx ) ;
		CStrCharSizeMb	aCStrCharSizeMb( strCurr ) ;
		
		char	chStrCurrLast = '\0' ;
		int iCurrCharLast = aCStrCharSizeMb.CharLength() - 1 ;
		//iCurrCharLast = strCurr �̈�ԍŌ�̕����́A
		//	�����C���f�N�X�i�Q�o�C�g�������P�Ɛ������C���f�N�X�j
		//	-1 �Ȃ�AstrCurr�͋󕶎���ł��B
		if ( iCurrCharLast >= 0 ){
			if ( aCStrCharSizeMb.CsizeOfCidx( iCurrCharLast ) == 1 ){
				chStrCurrLast = strCurr[ aCStrCharSizeMb.BidxOfCidx( iCurrCharLast ) ] ;
			}
		}
		//chStrCurrLast = strCurr �̖����̕����B
		//	�A���A�����̕������Q�o�C�g�����ł���ꍇ�́A '\0' �ƂȂ�܂��B

		strNext = pContStr->get( idx + 1 ) ;
		if ( chStrCurrLast == '\\' && strNext.size() > 0 ){
			strCurr.erase( strCurr.size() - 1 ) ;
			strNext = strTrim( strNext , true , false ) ;
			strCurr += strNext ;
			pContStr->set( strCurr , idx ) ;
			pContStr->erase( idx + 1 ) ;
			idx -- ;
		}
	}
}

/**
	������R���e�i���P�s�Ƃ��āA�ЂƂ̕�����Ɍ������܂��B

	200�����𒴂���s�ɂ��ẮA�J���}�̈ʒu�� "\\\n\t\t" ��}�����āA���s��ǉ����܂��B

	������ "\" �̍s�ɂ��ẮA���̍s�Ƃ̌������s���܂��B
 @param pContStr [in]
	������R���e�i���w�肵�ĉ������B
 @return
	���������������Ԃ��܂��B
*/
static string ContStrToString( 
	Mu< string >* pContStr )
{

	string strRv ;

	for ( int idx = 0 ; idx < pContStr->size() ; idx ++ )
	{
		string strElement = pContStr->get( idx ) ;

		// --------------------------------
		//	strElement ��200�����ƂɁA
		//	"\\\n\t\t" ��}������ strElement2 �ɃR�s�[
		// --------------------------------
		string strElement2 ;
		while( strElement.size() > 0 )
		{
			if ( !strElement2.empty() )
			{
				strElement2 += "\\\n\t\t" ;
			}

			if ( strElement.size() > 200 )
			{
				CStrCharSizeMb	aCStrCharSizeMb( strElement ) ;
				int iBidxComma = 0 ;
				for ( iBidxComma = 200 ; 
					iBidxComma > 0 ;
					iBidxComma = aCStrCharSizeMb.BidxNextChar( iBidxComma , -1 ) )
				{
					if ( aCStrCharSizeMb.CsizeOfBidx( iBidxComma ) == 1 && 
						strElement[iBidxComma] == ',' )
					{
						break ;
					}
				}
				//iBidxComma = 200�o�C�g�ڂ��O�ŁA200�o�C�g�ڂɈ�ԋ߂� ',' ��
				//	�o�C�g�C���f�N�X
				if ( iBidxComma == 0 )
				{
					//	�J���}��������܂���ł����B
					strElement2 += strElement ;
					strElement = "" ;
				}
				else
				{
					iBidxComma = aCStrCharSizeMb.BidxNextChar( iBidxComma , 1 ) ;
					//iBidxComma = 200�o�C�g�ڂ��O�ŁA
					//	200�o�C�g�ڂɈ�ԋ߂� ',' �̎��̕���
					
					strElement2 += strElement.substr( 0 , iBidxComma ) ;

					strElement.erase( 0 , iBidxComma ) ;
				}
			}
			else
			{
				strElement2 += strElement ;
				strElement = "" ;
			}
			//strElement = strLine �����폜���܂����B

		}
		// --------------------------------
		strRv += strElement2 ;
		strRv += "\n" ;
	}
	return ( strRv ) ;
}



// --------------------------------
//	WinDia�t�@�C���̃Z�N�V����	
// --------------------------------
/**
 *	  WinDia �t�@�C���`���̕����� ����A�Z�N�V�������擾���܂��B
 *	
 *	@param pstrcontWinDiaFileContStr [in]
 *	  WinDia �t�@�C���`���̕����� ���P�s����؂��Ċi�[����
 *	������R���e�i���w�肵�ĉ������B
 *	@param strSection [in]
 *		�Z�N�V���������w�肵�ĉ������B
 *	@param pstrcontSection [in,out]
 *	  ���̊֐��͂��̃R���e�i�̖����ɁA�Z�N�V�����̓����ɂ��镶�����
 *	�ǉ����܂��B\n
 *	  ���̃R���e�i�ɂ���܂ł������v�f�͈ێ����܂��B
 *	@return
 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	���݂̂Ƃ���́A 0 �݂̂ł��B
 */
static int WinDiaFile_getSection(
		Mu< string >* pstrcontWinDiaFileContStr ,
		const string& strSection , 
		Mui< string >* pstrcontSection ) 
{
	int idx ;
	int iRv = 0 ;
	string	aSection = string( "[" ) + strSection + "]" ;
	bool	bIsInSection = false ;
	for ( idx = 0 ; idx < pstrcontWinDiaFileContStr->size() ; idx ++ ){
		string	strLine = pstrcontWinDiaFileContStr->get( idx ) ;
		if ( !bIsInSection ){
			//	�Z�N�V�����̊J�n�̌������s���Ă��܂��B
			if ( aSection == strLine ){
				bIsInSection = true ;
				continue ;
			}
		}	else	{
			//	�Z�N�V�����̓��e���擾���Ă��܂��B
			if ( strLine.empty() || ( strLine[0] == '[' && 
					strLine[ strLine.size() - 1 ] == ']' ) ){
				bIsInSection = false ;
			}	else	{
				pstrcontSection->insert( strLine ) ;
			}
		}
	}
	return ( iRv ) ;
}


/**
 *	  �Z�N�V�������A������R���e�i�ɒǉ����܂��B
 *	WinDia �t�@�C���`���ɑΉ������L�����A�Z�N�V�����̑O��ɒǉ����܂��B
 *	
 *	@param pstrcontWinDiaFileContStr [in,out]
 *	  ���̊֐��͂��̃R���e�i�̖����ɁA�Z�N�V�����̕������ǉ����܂��B
 *	�R���e�i������܂ŕێ����Ă����v�f�͈ێ����܂��B
 *	@param strSection [in]
 *		�Z�N�V���������w�肵�ĉ������B
 *	@param pstrcontSection [in]
 *	  �Z�N�V�����̓����ɔz�u���镶����̃R���e�i���w�肵�ĉ������B
 *	@return
 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	���݂̂Ƃ���́A 0 �݂̂ł��B
 */
static int WinDiaFile_setSection(
		Mui< string >* pstrcontWinDiaFileContStr ,
		const string& strSection , 
		Mu< string >* pstrcontSection ) 
{
	int iRv = 0 ;
	
	string	aSection = string( "[" ) + strSection + "]" ;
	pstrcontWinDiaFileContStr->insert( aSection ) ;
	for ( int idx = 0 ; idx < pstrcontSection->size() ; idx ++ ){
		pstrcontWinDiaFileContStr->insert( pstrcontSection->get( idx ) ) ;
	}
	pstrcontWinDiaFileContStr->insert( "" ) ;
	
	return ( iRv ) ;
}

// --------------------------------
//	[WinDia]
// --------------------------------
/**
 *	[WinDIA] �Z�N�V�����̊e�s�̓��e��ێ����Ă���
 *	������R���e�i�̓��e��ǂݍ���ŁA
 *	CentDedRosen �I�u�W�F�N�g�̑����ɔ��f���܂��B
 *	[WinDIA] �Z�N�V�����Ɋ֌W�̂Ȃ������́A���̂܂܈ێ����܂��B
 * @param pCentDedRosen [in,out]
 *	���̊֐��͂��̃I�u�W�F�N�g�ɁA�������������݂܂��B
 * @param pstrcontSection [in]
 *	WinDIA �Z�N�V�����̓��e��ێ����Ă��镶����R���e�i���w�肵�ĉ������B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	���݂� 0 �����Ԃ��܂���B
 */
static int CentDedRosen_readWinDIASection( CentDedRosen* pCentDedRosen , 
		Mu< string >* pstrcontSection ) 
{
	int iRv = 0 ;
	// --------------------------------
	if ( pstrcontSection->size() > 0 ){
		pCentDedRosen->setName( pstrcontSection->get( 0 ) ) ;
	}
	// --------------------------------
	return ( iRv ) ;
}
	
/**
 *	CentDedRosen �I�u�W�F�N�g�̑��������ƂɁA
 *	[WinDIA] �Z�N�V�����̍s�𐶐����A������R���e�i�ɒǉ����܂��B
 * @param pCentDedRosen [in]
 *	CentDedRosen �I�u�W�F�N�g���w�肵�ĉ������B
 * @param pstrcontSection [in.out]
 *	���̊֐��͂��̃I�u�W�F�N�g�ɁA�s��ǉ����܂��B
 *	�R���e�i������܂ŕێ����Ă���������͈ێ����܂��B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	���݂� 0 �����Ԃ��܂���B
 */
static int CentDedRosen_writeWinDIASection( 
		const CentDedRosen* pCentDedRosen , 
		Mui< string >* pstrcontSection ) 
{
	int iRv = 0 ;
	// --------------------------------
	{
		pstrcontSection->insert( pCentDedRosen->getName() ) ;
	}
	// --------------------------------
	return ( iRv ) ;
}

// --------------------------------
//	[�w]
// --------------------------------
/**
 *	[�w] �Z�N�V�����̊e�s�̓��e��ێ����Ă���
 *	������R���e�i�̓��e��ǂݍ���ŁA�w�w�x CentDedEki 
 *	�I�u�W�F�N�g�𐶐����A
 *	CentDedRosen �I�u�W�F�N�g�́A�wIndex�̖����ɒǉ����܂��B
 *	CentDedRosen �I�u�W�F�N�g������܂ŕێ����Ă���
 *	�w�w�x �I�u�W�F�N�g�͈ێ����܂��B
 *	[�w] �Z�N�V�����Ɋ֌W�̂Ȃ������́A���̂܂܈ێ����܂��B
 * @param pCentDedRosen [in,out]
 *	���̊֐��͂��̃I�u�W�F�N�g�ɁA�w�w�x CentDedEki �I�u�W�F�N�g��
 *	�ǉ����܂��B
 * @param pstrcontSection [in]
 *	[�w] �Z�N�V�����̓��e��ێ����Ă��镶����R���e�i���w�肵�ĉ������B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	���݂� 0 �����Ԃ��܂���B
 */
static int CentDedRosen_readEkiSection( CentDedRosen* pCentDedRosen , 
		Mu< string >* pstrcontSection ) 
{
	int iRv = 0 ;
	// --------------------------------
	CentDedEkiCont* pCentDedEkiCont = pCentDedRosen->getCentDedEkiCont() ;

	for ( int iEkiIndex = 0 ; 
			iRv >= 0 && iEkiIndex < pstrcontSection->size() ;
			iEkiIndex ++ ){
		string	strLine = pstrcontSection->get( iEkiIndex ) ;
		string	strEkiZokusei ;
		string	strEkimei ;
		string::size_type pos = strLine.find( ',' ) ;
		if ( pos != string::npos ){
			strEkiZokusei = strLine.substr( 0 , pos ) ;
			strEkimei = strLine.substr( pos + 1 ) ;
		}	else	{
			strEkimei = strLine ;
		}
		CentDedEki::EEkijikokukeisiki	eEkijikokukeisiki = 
			CentDedEki::Jikokukeisiki_Hatsu ;
		if ( strEkiZokusei.find( 'b' ) != string::npos ){
			eEkijikokukeisiki = CentDedEki::Jikokukeisiki_Hatsuchaku ;
		}	else if ( strEkiZokusei.find( 'd' ) != string::npos ){
			eEkijikokukeisiki = CentDedEki::Jikokukeisiki_KudariChaku ;
		}	else if ( strEkiZokusei.find( 'u' ) != string::npos ){
			eEkijikokukeisiki = CentDedEki::Jikokukeisiki_NoboriChaku ;
		}
		CentDedEki::EEkikibo	eEkikibo = CentDedEki::Ekikibo_Ippan ;
		if ( strEkiZokusei.find( 'p' ) != string::npos ){
			eEkikibo = CentDedEki::Ekikibo_Syuyou ;
		}		

		CentDedEki aCentDedEki( strEkimei , 
			eEkijikokukeisiki ,
			eEkikibo , false ) ;
		pCentDedEkiCont->insert( aCentDedEki ) ;
	}
	// --------------------------------
	return ( iRv ) ;
}


/**
 *	CentDedRosen �I�u�W�F�N�g����܂��Ă���
 *	 �w�w�x CentDedEki �I�u�W�F�N�g�̑��������ɁA
 *	[�w] �Z�N�V�����̍s�𐶐����܂��B
 * @param pCentDedRosen [in]
 *	�������ݑΏۂƂȂ� CentDedRosen �I�u�W�F�N�g���w�肵�ĉ������B
 * @param pstrcontSection [in,out]
 *	���̊֐��͂��̕�����R���e�i�ɁA�s��ǉ����܂��B
 *	�R���e�i������܂ŕێ����Ă���������͈ێ����܂��B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	���݂� 0 �����Ԃ��܂���B
 */
static int CentDedRosen_writeEkiSection( 
		const CentDedRosen* pCentDedRosen , 
		Mui< string >* pstrcontSection ) 
{
	int iRv = 0 ;
	// --------------------------------
	const Mu<const CentDedEki*>*	pCentDedEkiContGet = 
		pCentDedRosen->getCentDedEkiCont()->getMuPtr() ;

	for ( int iEkiIndex = 0 ; 
			iRv >= 0 && iEkiIndex < pCentDedEkiContGet->size() ;
			iEkiIndex ++ ){
		const CentDedEki* pCentDedEki = pCentDedEkiContGet->get( iEkiIndex ) ;

		string	strEkiZokusei ;
		string	strEkimei ;

		CentDedEki::EEkijikokukeisiki	eEkijikokukeisiki = 
			pCentDedEki->getEkijikokukeisiki() ;
		CentDedEki::EEkikibo	eEkikibo = pCentDedEki->getEkikibo() ;
		
		if ( eEkikibo == CentDedEki::Ekikibo_Syuyou ){
			strEkiZokusei += 'p' ;
		}
		switch( eEkijikokukeisiki ){
		 case CentDedEki::Jikokukeisiki_Hatsu :
			break ;
		 case CentDedEki::Jikokukeisiki_Hatsuchaku :
			strEkiZokusei += 'b' ;
			break ;
		 case CentDedEki::Jikokukeisiki_KudariChaku :
			strEkiZokusei += 'd' ;
			break ;
		 case CentDedEki::Jikokukeisiki_NoboriChaku :
			strEkiZokusei += 'u' ;
			break ;
		}
		
		strEkimei = pCentDedEki->getEkimei() ;
		
		string	strLine = strEkiZokusei + ',' + strEkimei ;
		
		pstrcontSection->insert( strLine ) ;
	}
	return ( iRv ) ;
}


// --------------------------------
//	[����]
// --------------------------------
/**
 *	[����] �Z�N�V�����̊e�s�̓��e��ێ����Ă���
 *	������R���e�i�̓��e��ǂݍ���ŁA�w��Ԏ�ʁx CentDedRessyasyubetsu 
 *	�I�u�W�F�N�g�𐶐����A
 *	CentDedRosen �I�u�W�F�N�g�̖����ɒǉ����܂��B
 *
 *	CentDedRosen �I�u�W�F�N�g������܂ŕێ����Ă���
 *	�w��Ԏ�ʁx �I�u�W�F�N�g�͈ێ����܂��B
 *	[����] �Z�N�V�����Ɋ֌W�̂Ȃ������́A���̂܂܈ێ����܂��B
 *
 *	�܂��A�w��Ԏ�ʁx�I�u�W�F�N�g���P�V�ɖ����Ȃ��ꍇ�́A
 *	WinDIA �̃f�t�H���g�̗�Ԏ�ʂ�ǉ����܂��B
 * @param pCentDedRosen [in,out]
 *	���̊֐��͂��̃I�u�W�F�N�g�ɁA�w��Ԏ�ʁx CentDedRessyasyubetsu 
 *	�I�u�W�F�N�g��
 *	�ǉ����܂��B
 * @param pstrcontSection [in]
 *	[����] �Z�N�V�����̓��e��ێ����Ă��镶����R���e�i���w�肵�ĉ������B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	-1 ;	//	Train00 �̔ԍ������̒l���s�K�؂ł��B
 */
static int CentDedRosen_readSensyuSection( CentDedRosen* pCentDedRosen , 
		Mu< string >* pstrcontSection ) 
{
	int iRv = 0 ;

	CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont = 
		pCentDedRosen->getCentDedRessyasyubetsuCont() ;
	
	// --------------------------------
	//	�f�t�H���g��Ԏ�ʂ�ݒ�
	// --------------------------------
	if ( iRv >= 0 ){
		for ( int iRessyasyubetsuIdx = 
				pCentDedRessyasyubetsuCont->size() ;
			iRessyasyubetsuIdx < sizeof(g_WinDiaRessyasyubetsu) / 
				sizeof(g_WinDiaRessyasyubetsu[0]) ; 
			iRessyasyubetsuIdx ++ ){
			pCentDedRessyasyubetsuCont->insert( g_WinDiaRessyasyubetsu[iRessyasyubetsuIdx] ) ;
		}
	}

	// --------------------------------
	//	LINES=
	// --------------------------------
	string	strLINES ;
	if ( iRv >= 0 ){
		if ( pstrcontSection->size() > 0 ){
			string	aString = pstrcontSection->get( 0 ) ;
			if ( aString.substr( 0 , 6 ) == "LINES=" ) {
				strLINES = aString.substr( 6 ) ;
			}
		}
		//strLINES = "LINES=" �s�́A�l����
		if ( strLINES.length() > 0 ){
			deque<string>	contstr = splitc< deque< string > >( ',' , strLINES ) ;
			for ( int iRessyasyubetsuIdx = 0 ; 
					iRessyasyubetsuIdx <  (int)contstr.size() && 
					iRessyasyubetsuIdx < 
						pCentDedRessyasyubetsuCont->size() ;
					iRessyasyubetsuIdx ++ ){
				CentDedRessyasyubetsu* pCentDedRessyasyubetsu = 
					pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr()->get( iRessyasyubetsuIdx ) ;
				// --------------------------------
				unsigned int iValue = atoi( contstr[iRessyasyubetsuIdx].c_str() ) ;
				CentDedRessyasyubetsu::ESenStyle eSenStyle = 
					CentDedRessyasyubetsu::SenStyle_Jissen ;
				bool	bIsBold = false ;
				CdColorProp	aCOLORREF = pCentDedRessyasyubetsu->
					getDiagramSenColor() ;
				int iColorNum = -1 ;
				switch( ( iValue >> 0 ) & 0x3 ) {
				 case 0 :
					eSenStyle = CentDedRessyasyubetsu::SenStyle_Jissen ;
					break ;
				 case 1 :
					eSenStyle = CentDedRessyasyubetsu::SenStyle_Hasen ;
					break ;
				 case 2 :
					eSenStyle = CentDedRessyasyubetsu::SenStyle_Tensen ;
					break ;
				 case 3 :
					eSenStyle = CentDedRessyasyubetsu::SenStyle_Ittensasen ;
					break ;
				} 
				if ( ( ( iValue >> 7 ) & 0x1 ) > 0 ){
					bIsBold = true ;
				}
				if ( ( ( iValue >> 6 ) & 0x1 ) > 0 ){
					iColorNum = ( ( iValue >> 2 ) & 0x0f ) ;
					aCOLORREF = g_WinDIAColor[ iColorNum ] ;
				}
				
				pCentDedRessyasyubetsu->setDiagramSenStyle( eSenStyle ) ;
				pCentDedRessyasyubetsu->setDiagramSenIsBold( bIsBold ) ;
				pCentDedRessyasyubetsu->setDiagramSenColor( aCOLORREF ) ;			
				pCentDedRessyasyubetsu->setJikokuhyouMojiColor( aCOLORREF ) ;			
			}
		}
	}
	
	// --------------------------------
	//	Train00=
	// --------------------------------
	for ( int idxLine = 1 ; 
			iRv >= 0 && idxLine < pstrcontSection->size() ;
			idxLine ++ ){
		string	strLine = pstrcontSection->get( idxLine ) ;
		//strLine = Train00 �s�S��
		//	(��:"Train02=�i�Ґ�������,�i�j")


		int iRessyasyubetsuIdx = 0 ;
		string	strSyubetsumei ;
		string	strRyakusyou ;
		{
			string::size_type pos = strLine.find( '=' ) ;
			if ( pos == string::npos ){
				continue ;
			}
			string strRessyasyubetsIdx = strLine.substr( 0 , pos ) ;
			//strRessyasyubetsIdx =	"Train00" �̕���
			//	(��:"Train02")

			strRessyasyubetsIdx.erase( 0 , 5 ) ;	
			//strRessyasyubetsIdx =	"Train" �̕������폜�� 
			//	"00" �̕����������c���܂����B
			//	(��:"02")
			iRessyasyubetsuIdx = atoi( strRessyasyubetsIdx.c_str() ) ;
			//iRessyasyubetsuIdx = �L�q����Ă����Ԏ��Index
			//	(��:2)

			string strSyubetsumeiRyakusyou = strLine.substr( pos + 1 ) ;

			pos = strSyubetsumeiRyakusyou.find( ',' ) ;
			if ( pos == string::npos ){
				strSyubetsumei = strSyubetsumeiRyakusyou ;
			}	else	{
				strSyubetsumei = strSyubetsumeiRyakusyou.substr( 0 , pos ) ;
				strRyakusyou = strSyubetsumeiRyakusyou.substr( pos + 1 ) ;
			}
			//strSyubetsumei = ��ʖ�
			//	(��:"�i�Ґ�������")
			//strRyakusyou = ����
			//	(��:"�i�j")
		}
		CentDedRessyasyubetsu* pCentDedRessyasyubetsu = 
				pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr()->get( iRessyasyubetsuIdx ) ;
		if ( pCentDedRessyasyubetsu == NULL ){
			iRv = -1 ;	//	Train00 �̔ԍ������̒l���s�K�؂ł��B
		}	else	{
			pCentDedRessyasyubetsu->setSyubetsumei( strSyubetsumei ) ;
			pCentDedRessyasyubetsu->setRyakusyou( strRyakusyou ) ;
		}
	}

	// --------------------------------
	//	��Ԏ�ʖ�����̗�Ԏ��(idx 17�ȏ�)�͍폜���܂��B
	// --------------------------------
	if ( iRv >= 0 ){
		for ( int idxRessyasyubetsu = pCentDedRessyasyubetsuCont->size() - 1 ;
				idxRessyasyubetsu >= 0 ;
				idxRessyasyubetsu -- ){
			CentDedRessyasyubetsu* pCentDedRessyasyubetsu = 
				pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr()->get( idxRessyasyubetsu ) ;
			if ( pCentDedRessyasyubetsu->getSyubetsumei().empty() ){
				pCentDedRessyasyubetsuCont->erase( idxRessyasyubetsu ) ;
			}	else	{
				break ;
			}
		}
	}
	return ( iRv ) ;
}


/**
 *	CentDedRosen �I�u�W�F�N�g����܂��Ă���
 *	�w��Ԏ�ʁx CentDedRessyasyubetsu �I�u�W�F�N�g�����ƂɁA
 *	[����] �Z�N�V�����̍s�𐶐����܂��B
 * @param pCentDedRosen [in]
 *	�w��Ԏ�ʁx CentDedRessyasyubetsu �I�u�W�F�N�g���܂��Ă���
 *	CentDedRosen �I�u�W�F�N�g���w�肵�ĉ������B
 * @param pstrcontSection [in,out]
 *	���̊֐��͂��̕�����R���e�i�ɁA�s��ǉ����܂��B
 *	�R���e�i������܂ŕێ����Ă���������͈ێ����܂��B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	-1 ;	//	WinDIA �`���ł́A��Ԏ�ʂ�24��ނ܂łɐ�������Ă��܂��B
 *	-	-2 ;	//	���̂̒��������p�T�����𒴂����Ԏ�ʂ�����܂��B
 */
static int CentDedRosen_writeSensyuSection( const CentDedRosen* pCentDedRosen , 
		Mui< string >* pstrcontSection ) 
{
	int iRv = 0 ;

	const Mu<const CentDedRessyasyubetsu*>*	pCentDedRessyasyubetsuContGet = pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;
	// --------------------------------
	//	�K�[�h����
	// --------------------------------
	if ( iRv >= 0 ){
		if ( pCentDedRessyasyubetsuContGet->size() > 
			sizeof(g_WinDiaRessyasyubetsu)/sizeof(g_WinDiaRessyasyubetsu[0]) ){
			iRv = -1 ;	
				//	WinDIA �`���ł́A��Ԏ�ʂ�24��ނ܂łɐ�������Ă��܂��B
		}
	}
	// --------------------------------
	//	LINES=
	// --------------------------------
	string	strLINES ;
	if ( iRv >= 0 ){
		int idxRessyasyubetsu = 0 ;
		for ( idxRessyasyubetsu = 0 ; iRv >= 0 && 
				idxRessyasyubetsu <  
					pCentDedRessyasyubetsuContGet->size() ;
				idxRessyasyubetsu  ++ ){
			const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = 
				pCentDedRessyasyubetsuContGet->get( idxRessyasyubetsu ) ;
			CentDedRessyasyubetsu::ESenStyle eSenStyle = 
				pCentDedRessyasyubetsu->getDiagramSenStyle() ;
			bool bIsBold = pCentDedRessyasyubetsu->getDiagramSenIsBold() ;
			CdColorProp aCOLORREF = pCentDedRessyasyubetsu->getDiagramSenColor() ;


			unsigned int iValue = 0 ;
			
			iValue |= ( 1 << 6 ) ;
			
			switch( eSenStyle ){
 			 case CentDedRessyasyubetsu::SenStyle_Jissen :
				iValue |= ( 0 << 0 ) ;
				break ;
			 case CentDedRessyasyubetsu::SenStyle_Hasen :
				iValue |= ( 1 << 0 ) ;
				break ;
			 case CentDedRessyasyubetsu::SenStyle_Tensen :
				iValue |= ( 2 << 0 ) ;
				break ;
			 case CentDedRessyasyubetsu::SenStyle_Ittensasen :
				iValue |= ( 3 << 0 ) ;
				break ;
			}
			if ( bIsBold ){
				iValue |= ( 1 << 7 ) ;
			}
			int iColorNum = getNearestWinDIAColorNumber( aCOLORREF ) ;
			{
				iValue |= ( (unsigned int)iColorNum << 2 ) ;
			}
			// --------------------------------
			if ( !strLINES.empty() ){
				strLINES += ',' ;
			}
			strLINES += stringOf( (int)iValue ) ;
		}
		for ( ; iRv >= 0 && 
				idxRessyasyubetsu <  24 ; idxRessyasyubetsu  ++ ){
			if ( !strLINES.empty() ){
				strLINES += ',' ;
			}
		}
		strLINES = string( "LINES=" + strLINES ) ;
		pstrcontSection->insert( strLINES ) ;
	}
	// --------------------------------
	//	Train00=
	// --------------------------------
	if ( iRv >= 0 ){
		int idxRessyasyubetsu = 0 ;
		for ( idxRessyasyubetsu = 0 ; iRv >= 0 && 
				idxRessyasyubetsu <  
					pCentDedRessyasyubetsuContGet->size() ;
				idxRessyasyubetsu  ++ ){
			const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = 
				pCentDedRessyasyubetsuContGet->get( idxRessyasyubetsu ) ;
			string	strSyubetsumei = pCentDedRessyasyubetsu->getSyubetsumei() ;
			string	strRyakusyou = pCentDedRessyasyubetsu->getRyakusyou() ;

			if ( strRyakusyou.length() > 4 ){
				iRv = -2 ;	//	���̂̒��������p�T�����𒴂����Ԏ�ʂ�����܂��B
			}	else	{
				string	strLs = strprintf( "Train%02d=" , idxRessyasyubetsu ) ;
				strLs += strSyubetsumei + "," + strRyakusyou ;
				pstrcontSection->insert( strLs ) ;
			}
		}
	}
	return ( iRv ) ;
}

// --------------------------------
//	[����][���]
// --------------------------------
/**
 *	[����]��[���] �Z�N�V�����̊e�s�̓��e��ێ����Ă���
 *	������R���e�i�̓��e��ǂݍ���ŁA�w��ԁx CentDedRessya 
 *	�I�u�W�F�N�g�𐶐����A
 *	CentDedRessyaCont �I�u�W�F�N�g�̖����ɒǉ����܂��B
 *	CentDedRessyaCont �I�u�W�F�N�g������܂ŕێ����Ă���
 *	�w��ԁx CentDedressya �I�u�W�F�N�g�͈ێ����܂��B
 *	[����][���] �Z�N�V�����Ɋ֌W�̂Ȃ������́A���̂܂܈ێ����܂��B
 *
 *	���̊֐��̎��s�O�ɁA CentDedRessyaCont ��
 *
 *	- CentDedRessyaCont::m_iEkiCount 
 *	- CentDedRessyaCont::m_eRessyahoukou 
 *
 *	�������ݒ肳��Ă��Ȃ��Ă͂Ȃ�܂���B
 *
 * @param pCentDedRessyaCont [in,out]
 *	���̊֐��͂��̃I�u�W�F�N�g�ɁA�w��ԁx CentDedRessya
 *	�I�u�W�F�N�g��
 *	�ǉ����܂��B
 * @param pstrcontSection [in]
 *	[����] [���]�Z�N�V�����̓��e��ێ����Ă��镶����R���e�i���w�肵�ĉ������B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	���݂� 0 �����Ԃ��܂���B
 */
static int CentDedRosen_readKudariNoboriSection( 
		CentDedRessyaCont* pCentDedRessyaCont ,
		Mu< string >* pstrcontSection ) 
{
	int iRv = 0 ;
	
	for ( int idxLine = 0 ; iRv >= 0 && 
		idxLine < pstrcontSection->size() ; idxLine ++ ){
		
		string	strLine = pstrcontSection->get( idxLine ) ;
		deque<string>	contstrItem = splitc< deque<string>	>( ',' , strLine );
		if ( contstrItem.size() < 
			deque<string>::size_type( 4 + pCentDedRessyaCont->getEkiCount() ) )
		{
			iRv = -1 ;	//	�w���������Ȃ����܂��B
			continue ;
		}

		// --------------------------------
		CentDedRessya aCentDedRessya( pCentDedRessyaCont->createNullRessya() ) ;

		// --------------------------------
		//	��Ԏ�ʁE��Ԕԍ��E��Ԗ��E����
		// --------------------------------
		if ( iRv >= 0 ){
			string	strRessyasyubetsu = contstrItem[0] ;

			//	��Ԏ�ʔԍ��ɑ����āA()�ŐF�ԍ����w�肵�Ă���ꍇ�A
			//	����͍폜�i�����j���܂��B
			string::size_type	pos = strRessyasyubetsu.find( '(' ) ;
			if ( pos != string::npos ){
				strRessyasyubetsu.erase( pos , string::npos ) ;
			}

			int iRessyasyubetsuIdx = atoi( strRessyasyubetsu.c_str() ) ;
			string	strRessyabangou = contstrItem[1] ;
			string	strRessyamei = contstrItem[2] ;
			string	strGousuu = contstrItem[3] ;
			
			aCentDedRessya.setRessyasyubetsuIndex( iRessyasyubetsuIdx ) ;
			aCentDedRessya.setRessyabangou( strRessyabangou ) ;
			aCentDedRessya.setRessyamei( strRessyamei ) ;
			aCentDedRessya.setGousuu( strGousuu ) ;
		}
		// --------------------------------
		//	�w����
		// --------------------------------
		if ( iRv >= 0 ){
			for ( int iEkiIndex = 0 ; iRv >= 0 && 
					iEkiIndex < aCentDedRessya.getCentDedEkiJikokuCount() && 
					iEkiIndex < (int)contstrItem.size() - 4 ; iEkiIndex ++ ){
				string	strItem = contstrItem[iEkiIndex+4] ;
				
				string	strChaku ;
				string	strHatsu ;
				bool bChakuQ = false ;
				bool bHatsuQ = false ;
				bool bTsuuka = false ;
					
				string::size_type	pos = strItem.find( '/' ) ;
				if ( pos == string::npos ){
					strHatsu = strItem ;
				}	else	{
					strChaku = strItem.substr( 0 , pos ) ;
					strHatsu = strItem.substr( pos + 1 ) ;
				}
				if ( strChaku.size() >= 1 && strChaku[ strChaku.size() - 1 ] == '?' ){
					bChakuQ = true ;
					strChaku.erase( strChaku.size() - 1 ) ;
				}
				if ( strHatsu.size() >= 1 && strHatsu[ strHatsu.size() - 1 ] == '?' ){
					bHatsuQ = true ;
					strHatsu.erase( strHatsu.size() - 1 ) ;
				}
				if ( strChaku == "-" || strHatsu == "-" ){
					bTsuuka = true ;
				} 
				//strChaku = �������B "900" �̌`���B�w�肪�Ȃ��ꍇ�͋󕶎���B
				//strHatsu = �������B "900" �̌`���B�w�肪�Ȃ��ꍇ�͋󕶎���B
				//bChakuQ = �����������莞�� "?" �Ȃ�^�B
				//bHatsuQ = �����������莞�� "?" �Ȃ�^�B
				//bTsuuka = �ʉ߂Ȃ�^�B

				CdDedJikoku	jikokuChaku( strChaku ) ;
				CdDedJikoku	jikokuHatsu( strHatsu ) ;
				//jikokuChaku = �������B �w�肪�Ȃ��ꍇ�� Null ��ԁB
				//jikokuHatsu = �������B �w�肪�Ȃ��ꍇ�� Null ��ԁB

				CentDedEkiJikoku aCentDedEkiJikoku = aCentDedRessya.getCentDedEkiJikoku(
					aCentDedRessya.EkiOrderOfEkiIndex( iEkiIndex ) ) ;
				if ( ( !jikokuChaku.isNull() && !bChakuQ ) || 
						( !jikokuHatsu.isNull() && !bHatsuQ ) ){
					//	�w���͒��
					aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Teisya ) ;
					aCentDedEkiJikoku.setChakujikoku( jikokuChaku ) ;
					aCentDedEkiJikoku.setHatsujikoku( jikokuHatsu ) ;
				}	else if ( !jikokuChaku.isNull() || !jikokuHatsu.isNull() || bTsuuka ){
					//	�w���͒ʉ�
					aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Tsuuka ) ;
					aCentDedEkiJikoku.setChakujikoku( jikokuChaku ) ;
					aCentDedEkiJikoku.setHatsujikoku( jikokuHatsu ) ;
				}
				aCentDedRessya.setCentDedEkiJikoku( 
				 	aCentDedRessya.EkiOrderOfEkiIndex( iEkiIndex ) , aCentDedEkiJikoku ) ;
			}
		}
		// --------------------------------
		//	���l
		// --------------------------------
		if ( iRv >= 0 ){
			if ( (int)contstrItem.size() >= 4 + aCentDedRessya.getCentDedEkiJikokuCount() + 1 ){
				string	strBikou = contstrItem[4 + aCentDedRessya.getCentDedEkiJikokuCount() ] ;
				if ( strBikou.size() > 0 && strBikou[0] == '%' ){
					strBikou.erase( 0 , 1 ) ;
				}
				aCentDedRessya.setBikou( strBikou ) ;
			}
		}
		// --------------------------------
		if ( iRv >= 0 ){
			pCentDedRessyaCont->insert( aCentDedRessya ) ;
		}		
	}
	return ( iRv ) ;
}


/**
 *	CentDedRessyaCont �I�u�W�F�N�g�Ɋi�[����Ă���
 *	�w��ԁx CentDedRessya �I�u�W�F�N�g��ǂݍ���ŁA
 *	[����]��[���] �Z�N�V�����̍s�𐶐����܂��B
 *
 * @param pCentDedRessyaCont [in]
 *	�w��ԁx CentDedRessya	�I�u�W�F�N�g���i�[����Ă��� CentDedRessyaCont
 *	���w�肵�ĉ������B
 * @param pstrcontSection [in]
 *	���̊֐��͂��̕�����R���e�i�ɁA�s��ǉ����܂��B
 *	�R���e�i������܂ŕێ����Ă���������͈ێ����܂��B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	���݂� 0 �����Ԃ��܂���B
 */
static int CentDedRosen_writeKudariNoboriSection( 
		const CentDedRessyaCont* pCentDedRessyaCont ,
		Mui< string >* pstrcontSection ) 
{
	int iRv = 0 ;
	
	// --------------------------------
	const Mu<const CentDedRessya*>*	pCentDedRessyaContGet = pCentDedRessyaCont->getMuPtr() ;
	for ( int idxRessya = 0 ; iRv >= 0 && 
			idxRessya < pCentDedRessyaContGet->size() ;
			idxRessya ++ ){
		const CentDedRessya* pCentDedRessya = pCentDedRessyaContGet->get( idxRessya );
		string	strLine ;
		
		// --------------------------------
		//	��Ԏ�ʁE��Ԕԍ��E��Ԗ��E����
		// --------------------------------
		if ( pCentDedRessya->getRessyasyubetsuIndex() > 0 ){
			strLine += stringOf( pCentDedRessya->getRessyasyubetsuIndex() ) ;
		}
		strLine += ',' ;
		strLine += pCentDedRessya->getRessyabangou() ;
		strLine += ',' ;
		strLine += pCentDedRessya->getRessyamei() ;
		strLine += ',' ;
		strLine += pCentDedRessya->getGousuu() ;
		// --------------------------------
		//	�w����
		// --------------------------------
		if ( iRv >= 0 ){
			for ( int iEkiIndex = 0 ; iRv >= 0 && 
					iEkiIndex < pCentDedRessya->getCentDedEkiJikokuCount() ;
					iEkiIndex ++ ){
				string	strItem ;
				// --------------------------------
				CentDedEkiJikoku aCentDedEkiJikoku =
					 pCentDedRessya->getCentDedEkiJikoku(
						pCentDedRessya->EkiOrderOfEkiIndex( iEkiIndex ) ) ;
				
				if ( aCentDedEkiJikoku.getEkiatsukai() == 
						CentDedEkiJikoku::Ekiatsukai_Teisya ){
					//	���
					if ( !aCentDedEkiJikoku.getChakujikoku().isNull() ){
						string str = g_CdDedJikokuConv.encode( aCentDedEkiJikoku.getChakujikoku() ) ;
						strItem += ( str + '/' ) ;
					}
					if ( !aCentDedEkiJikoku.getHatsujikoku().isNull() ){
						string str = g_CdDedJikokuConv.encode( aCentDedEkiJikoku.getHatsujikoku() ) ;
						strItem += ( str ) ;
					}
				}	if ( aCentDedEkiJikoku.getEkiatsukai() == 
						CentDedEkiJikoku::Ekiatsukai_Tsuuka ){
					//	�ʉ�
					if ( !aCentDedEkiJikoku.getChakujikoku().isNull() ){
						string str = g_CdDedJikokuConv.encode( aCentDedEkiJikoku.getChakujikoku() ) ;
						strItem += ( str + '?' + '/' ) ;
					}
					if ( !aCentDedEkiJikoku.getHatsujikoku().isNull() ){
						string str = g_CdDedJikokuConv.encode( aCentDedEkiJikoku.getHatsujikoku() ) ;
						strItem += ( str + '?' ) ;
					}
					if ( strItem.empty() ){
						//	�����w��Ȃ��̒ʉ�
						strItem = "-" ;
					}
				}	if ( aCentDedEkiJikoku.getEkiatsukai() == 
						CentDedEkiJikoku::Ekiatsukai_Keiyunasi){
					//	�o�R�Ȃ�

					//	(�ʉ߂Ƃ݂Ȃ��܂��j
					strItem = "-" ;
				}
				// --------------------------------
				strLine += ',' ;
				strLine += strItem ;
			}
		}
		// --------------------------------
		//	���l
		// --------------------------------
		if ( iRv >= 0 ){
			string strBikou = pCentDedRessya->getBikou() ;
			if ( !strBikou.empty() ){
				strLine += ",%" ;
				strLine += strBikou ; 
			}
		}
		pstrcontSection->insert( strLine ) ;
	}
	
	
	// --------------------------------
	return ( iRv ) ;
}

/**
 *	CentDedRosen �I�u�W�F�N�g�Ɋi�[����Ă��邷�ׂĂ̗�Ԃ̂����A
 *	�I���w�̉w�����`����[������]�̗�Ԃ̏I���w��������
 *	�������ɕ␳���܂��i�I�������������\�r���[�ɕ\�������邽�߁j�B
 *
 * @param pCentDedRosen [in]
 *	���̊֐��́A���́w�H���x CentDedRosen	�I�u�W�F�N�g���̗�Ԃ�
 *	�␳���܂��B
 * @return
 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
 *	-	���݂� 0 �����Ԃ��܂���B
 */
static int CentDedRosen_SyuuchakuekiEkijikokuHosei( 
	CentDedRosen* pCentDedRosen )
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		CentDedEkiCont* pCentDedEkiCont = pCentDedRosen->getCentDedEkiCont() ;
		Mu<CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

		//	�_�C�����̃��[�v
		for ( int iDiaIndex = 0 ; iRv >= 0 && iDiaIndex < pCentDedDiaContGet->size() ; iDiaIndex ++ ){
			CentDedDia* pCentDedDia = pCentDedDiaContGet->get( iDiaIndex ) ;

			//	��ԕ������̃��[�v
			for ( int iRessyahoukou = Ressyahoukou_Kudari ;
					iRv >= 0 && iRessyahoukou <= Ressyahoukou_Nobori ;
					iRessyahoukou ++ ){
				Mu<CentDedRessya*>* pCentDedRessyaContGet = 
					pCentDedDia->getCentDedRessyaCont( (ERessyahoukou)iRessyahoukou )->getMuPtr() ;

				//	��Ԗ��̃��[�v
				for ( int iRessyaIndex = 0 ; iRv >= 0 && iRessyaIndex < pCentDedRessyaContGet->size() ; iRessyaIndex ++ ){
					CentDedRessya* pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					int iSyuuchakuEkiOrder = pCentDedRessya->getSyuuchakuEki() ;


					//iSyuuchakuEkiOrder = ���̗�Ԃ̏I���w�̉wOrder
					//	�������S�����͂���Ă��Ȃ���Ԃ̏ꍇ�� -1 �ɂȂ�܂��B
					if ( iSyuuchakuEkiOrder >= 0 )
					{

						int iChaku = 0 ;
						int iHatsu = 0 ;
						
						const Mu<CentDedEkiCont::CdDedEki>* pCdDedEkiCont = pCentDedEkiCont->getMuPtr( (ERessyahoukou)iRessyahoukou ) ;
						CentDedEkiCont::CdDedEki aCdDedEki = pCdDedEkiCont->get( iSyuuchakuEkiOrder ) ;
						if ( aCdDedEki.getChakujikokuHyouji() )
						{
							iChaku = 1 ;
						}
						if ( aCdDedEki.getHatsujikokuHyouji() )
						{
							iHatsu = 1 ;
						}
						
						//�@�ȉ��̏����𖞂������
						//
						//		�I���w�̉w�����`�����A�u��������\�����Ȃ��v�u��������\������v
						//		�I���w�̉w�����̒��������ݒ肠��E���������ݒ�Ȃ�
						//
						//	�ɑ΂��āA�ȉ��̏������s��
						//
						//	�I���w�̉w�����̒������𔭎����ɐݒ�B�������͋󗓂ɂ���B

						CentDedEkiJikoku	aCentDedEkiJikoku = pCentDedRessya->getCentDedEkiJikoku( iSyuuchakuEkiOrder ) ;
						if ( iChaku == 0 && iHatsu == 1 && 
								!aCentDedEkiJikoku.getChakujikoku().isNull() && 
								aCentDedEkiJikoku.getHatsujikoku().isNull() ){
							aCentDedEkiJikoku.setHatsujikoku( aCentDedEkiJikoku.getChakujikoku() ) ;
							aCentDedEkiJikoku.setChakujikoku( CdDedJikoku() ) ;
							pCentDedRessya->setCentDedEkiJikoku( iSyuuchakuEkiOrder , aCentDedEkiJikoku ) ;
						}

					}
				}
			}
				
		}
	}
	return ( iRv ) ;
}





// ********************************
//	CDedRosenFileData
// ********************************

int CconvWinDia::CDedRosenFileData_From_WinDiaFileString(
		CDedRosenFileData* pCDedRosenFileData ,
		const string& strWinDiaFileString ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	CDedRosenFileData ��������
	// --------------------------------
	CentDedRosen* pCentDedRosen = NULL ;
	if ( iRv >= 0 ){
		*pCDedRosenFileData = CDedRosenFileData() ;
		pCentDedRosen = pCDedRosenFileData->getCentDedRosen() ;

		pCentDedRosen->getCentDedDiaCont()->insert( 
			CentDedDia( "�_�C��"  ) ) ;
	}
	// --------------------------------
	//	��������s���Ƃɕ���
	// --------------------------------
	CMup_deque< string >	contstrWinDiaFile ;
	if ( iRv >= 0 ){
		ContStrFromString( 
			&contstrWinDiaFile ,
			strWinDiaFileString ) ;
	}
	//contstrWinDiaFile = WinDia ��������A�s���Ƃɕ������܂����B
	 

	// --------------------------------
	//	[WinDIA]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionWinDia ;
		WinDiaFile_getSection(
			&contstrWinDiaFile , 
			"WinDIA" , 
			&contstrSectionWinDia ) ;
		int iResult = CentDedRosen_readWinDIASection( 
				pCDedRosenFileData->getCentDedRosen() ,
				&contstrSectionWinDia ) ;
		if ( iResult < 0 ){
			iRv = iResult ;
		}
	}
	// --------------------------------
	//	[�w]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionEki ;
		WinDiaFile_getSection(
				&contstrWinDiaFile , 
				"�w" , 
				&contstrSectionEki ) ;
		int iResult = CentDedRosen_readEkiSection( 
				pCDedRosenFileData->getCentDedRosen() ,
				&contstrSectionEki ) ;
		if ( iResult < 0 ){
			iRv = iResult - 10 ;
		}	
	}
	// --------------------------------
	//	[����]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionSensyu ;
		WinDiaFile_getSection(
				&contstrWinDiaFile , 
			"����" , 
			&contstrSectionSensyu ) ;
		int iResult = CentDedRosen_readSensyuSection( 	
				pCDedRosenFileData->getCentDedRosen() ,
				&contstrSectionSensyu ) ;
		//iResult = 
		//	-1 ;	//	Train00 �̔ԍ������̒l���s�K�؂ł��B
		if ( iResult < 0 ){
			iRv = iResult - 20 ;
			//iRv = 
			//	-21 ;	//	Train00 �̔ԍ������̒l���s�K�؂ł��B
		}	
	}
	// --------------------------------
	//	[����]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionKudari ;
		WinDiaFile_getSection(
			&contstrWinDiaFile , 
			"����" , 
			&contstrSectionKudari ) ;
		CentDedRessyaCont* pCentDedRessyaCont = 
			pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( 0 )->
			getCentDedRessyaCont( Ressyahoukou_Kudari ) ;
		int iResult = CentDedRosen_readKudariNoboriSection( 
			pCentDedRessyaCont ,
			&contstrSectionKudari ) ; 
		if ( iResult < 0 ){
			iRv = iResult - 30 ;
		}	
	}
	// --------------------------------
	//	[���]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionNobori ;
		WinDiaFile_getSection(
			&contstrWinDiaFile , 
			"���" , 
			&contstrSectionNobori ) ;
		CentDedRessyaCont* pCentDedRessyaCont = 
			pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( 0 )->
			getCentDedRessyaCont( Ressyahoukou_Nobori ) ;
		int iResult = CentDedRosen_readKudariNoboriSection( 
			pCentDedRessyaCont ,
			&contstrSectionNobori ) ; 
		if ( iResult < 0 ){
			iRv = iResult -40 ;
		}	
	}
	// --------------------------------
	//	[����]�E[���]�Z�N�V����
	//	�I���w�̉w�����`����[������]�̗�Ԃ̏I���w��������
	//	�������ɕ␳����i�I�������������\�r���[�ɕ\�������邽�߁j
	// --------------------------------
	if ( iRv >= 0 ){
		int iResult = CentDedRosen_SyuuchakuekiEkijikokuHosei( pCentDedRosen );
		if ( iResult < 0 ){
			iRv = iResult -50 ;
		}	
	}
	
	
	// --------------------------------
	return iRv ;
}

int CconvWinDia::CDedRosenFileData_To_WinDiaFileString( 
		const CDedRosenFileData* pCDedRosenFileData ,
		int idxDia ,
		string* pstrWinDiaFileString ) 
{
	int iRv = 0 ;

	
	// --------------------------------
	CMup_deque< string >	contstrWinDiaFile ;
	const CentDedRosen* pCentDedRosen = NULL ;
	if ( iRv >= 0 ){
		pCentDedRosen = pCDedRosenFileData->getCentDedRosen() ;
	}	 
	// --------------------------------
	//	�K�[�h����
	// --------------------------------
	if ( iRv >= 0 ){
		if ( !( 0 <= idxDia && 
				idxDia < pCentDedRosen->getCentDedDiaCont()->getMuPtr()->size() ) ){
			iRv = -1 ;	//	idxDia �̎w�肪�s���ł��B
		}
	}

	// --------------------------------
	//	[WinDIA]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionWinDia ;
		int iResult = CentDedRosen_writeWinDIASection( 
				pCDedRosenFileData->getCentDedRosen() ,
				&contstrSectionWinDia ) ;
		if ( iResult < 0 ){
			iRv = iResult ;
		}	else	{
			WinDiaFile_setSection(
				&contstrWinDiaFile , 
				"WinDIA" , 
				&contstrSectionWinDia ) ;
		}
	}
	// --------------------------------
	//	[�w]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionEki ;
		int iResult = CentDedRosen_writeEkiSection( 
				pCDedRosenFileData->getCentDedRosen() ,
				&contstrSectionEki ) ;
		if ( iResult < 0 ){
			iRv = iResult - 10 ;
		}	else	{
			WinDiaFile_setSection(
					&contstrWinDiaFile , 
					"�w" , 
					&contstrSectionEki ) ;
		}
	}
	// --------------------------------
	//	[����]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionSensyu ;
		int iResult = CentDedRosen_writeSensyuSection( 	
				pCDedRosenFileData->getCentDedRosen() ,
				&contstrSectionSensyu ) ;
		//iResult = 
		//	-1 ;	//	WinDIA �`���ł́A��Ԏ�ʂ�24��ނ܂łɐ�������Ă��܂��B
		//	-2 ;	//	���̂̒��������p�T�����𒴂����Ԏ�ʂ�����܂��B
		if ( iResult < 0 ){
			iRv = iResult - 20 ;
		}	else	{	
			WinDiaFile_setSection(
				&contstrWinDiaFile , 
				"����" , 
				&contstrSectionSensyu ) ;
		}
	}
	// --------------------------------
	//	[����]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionKudari ;
		const CentDedRessyaCont* pCentDedRessyaCont = 
			pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( idxDia )->
			getCentDedRessyaCont( Ressyahoukou_Kudari ) ;
		int iResult = CentDedRosen_writeKudariNoboriSection( 
			pCentDedRessyaCont ,
			&contstrSectionKudari ) ; 
		//	-	���݂� 0 �����Ԃ��܂���B
		if ( iResult < 0 ){
			iRv = iResult - 30 ;
		}	else	{
			WinDiaFile_setSection(
				&contstrWinDiaFile , 
				"����" , 
				&contstrSectionKudari ) ;
		}
	}
	// --------------------------------
	//	[���]�Z�N�V����
	// --------------------------------
	if ( iRv >= 0 ){
		CMup_deque< string >	contstrSectionNobori ;
		const CentDedRessyaCont* pCentDedRessyaCont = 
			pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( idxDia )->
			getCentDedRessyaCont( Ressyahoukou_Nobori ) ;
		int iResult = CentDedRosen_writeKudariNoboriSection( 
			pCentDedRessyaCont ,
			&contstrSectionNobori ) ; 
		//	-	���݂� 0 �����Ԃ��܂���B
		if ( iResult < 0 ){
			iRv = iResult - 40 ;
		}	else	{
			WinDiaFile_setSection(
				&contstrWinDiaFile , 
				"���" , 
				&contstrSectionNobori ) ;
		}
	}
	//contstrWinDiaFile = WinDia �����񂷂ׂĊi�[���܂����B
	
	// --------------------------------
	//	�s���Ƃɕ������ꂽ�R���e�i���A������Ɍ���
	// --------------------------------
	if ( iRv >= 0 ){
		*pstrWinDiaFileString = ContStrToString( &contstrWinDiaFile ) ;
	}
	return iRv ;
}



} //namespace WinDia
