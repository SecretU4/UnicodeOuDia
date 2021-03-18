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
// ****************************************************************
// $Id: CconvJikokuhyouCsv.cpp 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
#include "stdafx.h"
#include "CconvJikokuhyouCsv.h"
#include "str\strprintf.h"
#include "..\ViewJikokuhyou\JikokuhyouColSpec\CdYColSpecCont.h"

namespace ConvJikokuhyouCsv{

using namespace std ;
using namespace OuLib ;
using namespace OuLib::Str ;

using ViewJikokuhyou::JikokuhyouColSpec::CdYColSpecCont;
using ViewJikokuhyou::JikokuhyouColSpec::CdYColSpec;

/**
	FileType�� ���O
*/
const char* const nameFileType = "FileType" ;

/**
	FileType �̒l
*/
const char* const nameFileTypeValue = "OuDia.JikokuhyouCsv.1" ;

const int CSVROWINDEX_Ressyabangou = 4 ;
const int CSVROWINDEX_Ressyasyubetsu = 5 ;
const int CSVROWINDEX_Ressyamei = 6 ;
const int CSVROWINDEX_Gousuu = 7 ;
const int CSVROWINDEX_Gou = 8 ;
const int CSVROWINDEX_Ekijikoku0 = 9 ;
const int CSVCOLUMNINDEX_Ressya0 = 2 ;

/** �����̏�����ێ����܂��B */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	true ,		//	NoColon 
	// ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" ���폜���܂��B
	CdDedJikoku::CConv::EHour_ZeroToNone ,	
	CdDedJikoku::CConv::ESecond_NoSecond 	// �b����ɏo�͂��܂���B 
	) ;

	// --------------------------------
	//@name	�w�����Z���̕�����̉���
	// --------------------------------
string CconvJikokuhyouCsv::encode_Ekijikoku( 
		CentDedEkiJikoku::EEkiatsukai eEkiatsukai , 
		const CdDedJikoku& aCdDedJikoku ) 
{
	string strValue ;
			switch( eEkiatsukai )
			{
			case CentDedEkiJikoku::Ekiatsukai_None :
				{
				}
				break ;
			case CentDedEkiJikoku::Ekiatsukai_Teisya:
				{
					strValue = g_CdDedJikokuConv.encode( aCdDedJikoku ) ;
				}
				break ;
			case CentDedEkiJikoku::Ekiatsukai_Tsuuka:
				{
					if ( aCdDedJikoku.isNull() )
					{
						strValue = m_nameTsuuka ;
					}
					else
					{
						strValue = "" ;
						strValue += g_CdDedJikokuConv.encode( aCdDedJikoku ) ;
						strValue += "?" ;
						
					}
				}
				break ;
			case CentDedEkiJikoku::Ekiatsukai_Keiyunasi:
				{
					strValue = m_nameKeiyunasi ;
				}
				break ;
			}

	return strValue ;
}

int  CconvJikokuhyouCsv::decode_Ekijikoku( 
		CentDedEkiJikoku::EEkiatsukai* pEkiatsukai , 
		CdDedJikoku* pCdDedJikoku , 
		const string& strEkijikoku ) 
{
	int iRv = 0 ;
	CentDedEkiJikoku::EEkiatsukai eEkiatsukai 
		= CentDedEkiJikoku::Ekiatsukai_None ;
	CdDedJikoku aCdDedJikoku ;

	if ( strEkijikoku == "" )
	{
		//	�^�s�Ȃ�
	}
	else if ( strEkijikoku == m_nameTsuuka )
	{
		//	�ʉ�
		eEkiatsukai = CentDedEkiJikoku::Ekiatsukai_Tsuuka ;
	}
	else if ( strEkijikoku == m_nameKeiyunasi )
	{
		//	�o�R�Ȃ�
		eEkiatsukai = CentDedEkiJikoku::Ekiatsukai_Keiyunasi ;
	}
	else if ( strEkijikoku.size() >= 1 
		&& strEkijikoku[ strEkijikoku.size() - 1 ] == '?' )
	{
		//	�ʉߎ�������
		eEkiatsukai = CentDedEkiJikoku::Ekiatsukai_Tsuuka ;
		int iResult = aCdDedJikoku.decode( 
			strEkijikoku.substr( 0 , strEkijikoku.size() - 1 ) ) ;
		if ( iResult < 0 )
		{
			iRv = -1 ;	//	�����̉��߂Ɏ��s���܂����B
		}
	}
	else 
	{
		//	��ԁE����
		eEkiatsukai = CentDedEkiJikoku::Ekiatsukai_Teisya ;
		int iResult = aCdDedJikoku.decode( strEkijikoku ) ;
		if ( iResult < 0 )
		{
			iRv = -1 ;	//	�����̉��߂Ɏ��s���܂����B
		}
	}
	// --------------------------------
	if ( pEkiatsukai != NULL )
	{
		*pEkiatsukai = eEkiatsukai ;
	}
	if ( pCdDedJikoku != NULL )
	{
		*pCdDedJikoku = aCdDedJikoku ;
	}
	return iRv ;
}

	// --------------------------------
	//@name encode() �̉����֐�	
	// --------------------------------
void CconvJikokuhyouCsv::encode_createContJikokuOrderOfJjikokuhyouIndex( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou eRessyahoukou , 
		deque<CdDedJikokuOrder>*	pcontiJikokuOrderOfJikokuhyouIndex ) 
{
	CdYColSpecCont aCdYColSpecCont(
		pCentDedEkiCont , eRessyahoukou , false ) ;
	int iColumnCount = aCdYColSpecCont.getColumnNumber_Ekijikoku_end() - 
		aCdYColSpecCont.getColumnNumber_Ekijikoku_begin() ;
	for ( int iJikokuhyouIndex = 0 ; iJikokuhyouIndex < iColumnCount ; iJikokuhyouIndex ++ )
	{
		CdYColSpec	aCdYColSpec = 
			aCdYColSpecCont.ColumnNumberToSpec( 
				aCdYColSpecCont.getColumnNumber_Ekijikoku_begin() 
				+ iJikokuhyouIndex ) ;
		int iEkiOrder = aCdYColSpec.getEkiOrder() ;
		CdDedJikokuOrder::EEkiJikokuItem	aEEkijikokuItem = CdDedJikokuOrder::EkiJikokuItem_Chaku ;
		if ( aCdYColSpec.getColumnType() 
			== CdYColSpec::ColumnType_Ekijikoku_Hatsu )
		{
			aEEkijikokuItem = CdDedJikokuOrder::EkiJikokuItem_Hatsu ;
		}
		
		pcontiJikokuOrderOfJikokuhyouIndex->push_back( 
			CdDedJikokuOrder( iEkiOrder , aEEkijikokuItem ) ) ;
	}
}


int CconvJikokuhyouCsv::encode_AddRessya( 
		const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet , 
		const deque<CdDedJikokuOrder>&	contiJikokuOrderOfJikokuhyouIndex , 
		const CentDedRessya* pCentDedRessya , 
		CdCsvDocument* pCdCsvDocument ) 
{
	int iRv = 0 ;

	if ( iRv >= 0 )
	{
		if ( pCentDedRessya->isNull() )
		{
			iRv = -1 ;	//	pCentDedRessya �� Null �ł��B
		}
	}
	// --------------------------------
	const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedRessyasyubetsu 	= pCentDedRessyasyubetsuContGet
			->get( pCentDedRessya->getRessyasyubetsuIndex() ) ;
	}
	//pCentDedRessysyubetsu = ��Ԏ�ʃI�u�W�F�N�g

	//��2.5��5�s�� <��Ԕԍ�>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ressyabangou ) ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedRessya->getRessyabangou() ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyabangou ) ;
	}

	//��2.6��6�s�� <��Ԏ��>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get(CSVROWINDEX_Ressyasyubetsu ) ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedRessyasyubetsu->getRyakusyou() ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyasyubetsu ) ;
	}

	//��2.7��7�s�� <��Ԗ�>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ressyamei ) ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedRessya->getRessyamei() ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyamei ) ;
	}

	//��2.8��8�s�� <����>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Gousuu ) ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedRessya->getGousuu() ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Gousuu ) ;
	}
	//��2.9��9�s�� <���\��>
	if ( iRv >= 0 )
	{
		string	strValue ;
		if ( !pCentDedRessya->getGousuu().empty() )
		{
			strValue = m_nameGou ;
		}
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Gou ) ;
		aRow.getCellCont()->insert( CdCsvCell( strValue ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Gou ) ;
	}

	//��2.10��10�s�ځ` �w����
	
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order> �̖@���������܂��B
	//	�v�f�̐��́A�����\�̗񐔂ł��B

	if ( iRv >= 0 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			CdDedJikokuOrder iJikokuOrder = contiJikokuOrderOfJikokuhyouIndex[iJikokuhyouIndex] ;
			int iEkiOrder = iJikokuOrder.getEkiOrder() ;
			int iHatsu = 0 ;
			if ( iJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
			{
				iHatsu = 1 ;
			}



			CentDedEkiJikoku aCentDedEkiJikoku 
				= pCentDedRessya->getCentDedEkiJikoku(iEkiOrder) ;
			CdDedJikoku aCdDedJikoku ;
			if ( iHatsu == 0 )
			{
				aCdDedJikoku = aCentDedEkiJikoku.getChakujikoku() ;
			}
			else
			{
				aCdDedJikoku = aCentDedEkiJikoku.getHatsujikoku() ;
			}

			string	strValue = encode_Ekijikoku( 
				aCentDedEkiJikoku.getEkiatsukai() , 
				aCdDedJikoku ) ;
			//strValue = �w�����𕶎��񉻂��܂���(�ʉߋL���Ȃǂ̏ꍇ������܂�)


			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;
			aRow.getCellCont()->insert( CdCsvCell( strValue ) ) ;
			pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;

		}
	}
	//��2.11��[��1="���l" AND ��2=""]�̗�@���l��
	if ( iRv >= 0 )
	{
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size() ) ;
			aRow.getCellCont()->insert( CdCsvCell( pCentDedRessya->getBikou() ) ) ;
			pCdCsvDocument->getRowCont()->set( aRow , 
				CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size() ) ;
	}
	return iRv ;
}

int CconvJikokuhyouCsv::encode_AddRessyaNull( 
		const deque<CdDedJikokuOrder>&	contiJikokuOrderOfJikokuhyouIndex , 
		CdCsvDocument* pCdCsvDocument ) 
{
	int iRv = 0 ;
	// --------------------------------

	//��2.5��5�s�� <��Ԕԍ�>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ressyabangou ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyabangou ) ;
	}

	//��2.6��6�s�� <��Ԏ��>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get(CSVROWINDEX_Ressyasyubetsu ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyasyubetsu ) ;
	}

	//��2.7��7�s�� <��Ԗ�>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ressyamei ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyamei ) ;
	}

	//��2.8��8�s�� <����>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Gousuu ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Gousuu ) ;
	}
	//��2.9��9�s�� <���\��>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Gou ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Gou ) ;
	}

	//��2.10��10�s�ځ` �w����
	
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order> �̖@���������܂��B
	//	�v�f�̐��́A�����\�̗񐔂ł��B

	if ( iRv >= 0 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;
			aRow.getCellCont()->insert( CdCsvCell(  ) ) ;
			pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;

		}
	}
	//��2.11��[��1="���l" AND ��2=""]�̗�@���l��
	if ( iRv >= 0 )
	{
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size() ) ;
			aRow.getCellCont()->insert( CdCsvCell() ) ;
			pCdCsvDocument->getRowCont()->set( aRow , 
				CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size() ) ;
	}
	return iRv ;
}


	// --------------------------------
	//@name decode() �̉����֐�	
	// --------------------------------
int CconvJikokuhyouCsv::decode_createContJikokuOrderOfJjikokuhyouIndex( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou eRessyahoukou , 
		const CdCsvDocument* pCdCsvDocument , 
		deque<int>*	pcontiJikokuOrderOfJikokuhyouIndex , 
		string* pstrErrorInfoString ) 
{
	int iRv = 0 ;
	const Mu<CentDedEkiCont::CdDedEki>* pCdDedEkiContGet = 
		pCentDedEkiCont->getMuPtr(eRessyahoukou ) ;
	string	strErrorInfoString ;

	if ( iRv >= 0 )
	{
		pcontiJikokuOrderOfJikokuhyouIndex->clear() ;
	}
	if ( iRv >= 0 )
	{
		int iJikokuOrder = 0 ;
		for ( int iJikokuhyouInex = 0 ; 
			iRv >= 0 && iJikokuhyouInex < pCdCsvDocument->getRowCont()->size() - CSVROWINDEX_Ekijikoku0 ;	
			iJikokuhyouInex ++ )
		{
			CdCsvRow aCdCsvRow = pCdCsvDocument->getRowCont()->get( iJikokuhyouInex + CSVROWINDEX_Ekijikoku0 ) ;
			string	strEkimei = aCdCsvRow.getCellCont()->get( 0 ).getData() ;
			string	strChakuHatsu = aCdCsvRow.getCellCont()->get( 1 ).getData() ;
			
			if ( strEkimei == m_nameBikou && 
				strChakuHatsu.empty() )
			{
				//���l�s���݂���܂����B
				break ;
			}
			
			bool bIsJikokuOrderFound = false ;
			for ( ; 
				!bIsJikokuOrderFound && iJikokuOrder < pCdDedEkiContGet->size() * 2 ; 
				iJikokuOrder ++ )
			{
				int	iEkiOrder = iJikokuOrder / 2 ;
				int iHatsu = iJikokuOrder % 2 ;
				if ( strEkimei == pCdDedEkiContGet->get( iEkiOrder ).getEkimei() )
				{
					if ( ( iHatsu == 0 && strChakuHatsu == m_nameChaku ) || 
						( iHatsu == 1 && strChakuHatsu == m_nameHatsu ) )
					{
						pcontiJikokuOrderOfJikokuhyouIndex->push_back( iJikokuOrder ) ;
						bIsJikokuOrderFound = true ;
					}
				}
			}
			if ( !bIsJikokuOrderFound )
			{
				/**
					�w����������܂���B
				@param EkiMei
					�w��
				@param Chakuhatsu
					����
				*/
				const char* const ERRREASON_EkimeiNotFound = "Ekimei is Not Found." ;
				const char* const ERRREASON_PROP_Ekimei = "Ekimei" ;
				const char* const ERRREASON_PROP_Chakuhatsu = "Chakuhatsu" ;
							
				
				strErrorInfoString = ERRREASON_EkimeiNotFound ;
				strErrorInfoString += strprintf( "\t%s=%s" , 
					ERRREASON_PROP_Ekimei , strEkimei.c_str() ) ;
				strErrorInfoString += strprintf( "\t%s=%s" , 
					ERRREASON_PROP_Chakuhatsu , strChakuHatsu.c_str()  ) ;
				iRv = -1 ;	//	�w����������܂���B
			}
		}
	}
	// --------------------------------
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}

int CconvJikokuhyouCsv::decode_readRessyaColumn( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const deque<int>&	contiJikokuOrderOfJikokuhyouIndex , 
		CentDedRessya* pCentDedRessya , 
		const CdCsvDocument* pCdCsvDocument , 
		int iColumnIndex ,
		string* pstrErrorInfoString ) 
{
	int iRv = 0 ;
	string	strErrorInfoString ;
	// --------------------------------
	//	��Ԏ��Index������
	// --------------------------------
	// --------------------------------
	//��2.5��5�s�� <��Ԕԍ�>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()
			->get( CSVROWINDEX_Ressyabangou ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		pCentDedRessya->setRessyabangou( aCell.getData() ) ;
	}
	
	//��2.6��6�s�� <��Ԏ��>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get(CSVROWINDEX_Ressyasyubetsu ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		
		int iRessyasyubetsuIndex = -1 ;
		if ( iRv >= 0 )
		{
			for ( int idx = 0 ;
				iRv >= 0 && 
				iRessyasyubetsuIndex == -1 && 
					idx < pCentDedRessyasyubetsuContGet->size() ;
				idx ++ )
			{
				const CentDedRessyasyubetsu* pCentDedRessyasyubetsu 
					= pCentDedRessyasyubetsuContGet->get( idx ) ;
				if ( pCentDedRessyasyubetsu->getRyakusyou() == 
					strValue )
				{
					iRessyasyubetsuIndex = idx ;
				}
			}
			if ( iRessyasyubetsuIndex == -1 )
			{
				/**
					��Ԏ�ʂ�������܂���B
				@param Ressyasyubetsu
					��Ԏ��
				*/
				const char* const ERRREASON_RessyasyubetsuNotFound = "Ressyasyubetsu is Not Found." ;
				const char* const ERRREASON_PROP_Ressyasyubetsu = "Ressyasyubetsu" ;
				strErrorInfoString = ERRREASON_RessyasyubetsuNotFound ; 
				strErrorInfoString += strprintf( "\t%s=%s" , 
					ERRREASON_PROP_Ressyasyubetsu , strValue.c_str() ) ;
				iRv = -1 ;	//	��Ԏ�ʂ�������܂���B
			}
		}
		//iRessyasyubetsuIndex = ��Ԏ��Index ;
		if ( iRv >= 0 )
		{
			pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndex ) ;
		}

	}

	//��2.7��7�s�� <��Ԗ�>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Ressyamei ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		pCentDedRessya->setRessyamei( strValue  ) ;
	}

	//��2.8��8�s�� <����>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Gousuu ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		pCentDedRessya->setGousuu( strValue  ) ;
	}
	//��2.10��10�s�ځ` �w����
	
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order> �̖@���������܂��B
	//	�v�f�̐��́A�����\�̗񐔂ł��B

	if ( iRv >= 0 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iRv >= 0 && 
				iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			int iJikokuOrder = 
				contiJikokuOrderOfJikokuhyouIndex[iJikokuhyouIndex] ;
			int iEkiOrder = iJikokuOrder / 2 ;
			int iHatsu = iJikokuOrder % 2 ;
			
			CentDedEkiJikoku aCentDedEkiJikoku 
				= pCentDedRessya->getCentDedEkiJikoku(iEkiOrder) ;
			
			
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;
			CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
			string strValue = aCell.getData() ;
			
			
			CentDedEkiJikoku::EEkiatsukai eEkiatsukai = 
				CentDedEkiJikoku::Ekiatsukai_None ;
			CdDedJikoku	aCdDedJikoku ;
			
			int iResult = decode_Ekijikoku( 
				&eEkiatsukai , 
				&aCdDedJikoku , 
				strValue ) ;
			if ( iResult < 0 )
			{
				/**
					���������߂ł��܂���B
				@param Jikoku
					����
				*/
				const char* const ERRREASON_Illegal_Jikoku_Format = "Illegal Jikoku format." ;
				const char* const ERRREASON_PROP_Jikoku = "Jikoku" ;
				strErrorInfoString = ERRREASON_Illegal_Jikoku_Format ; 
				strErrorInfoString += strprintf( "\t%s=%s" , 
					ERRREASON_PROP_Jikoku , strValue.c_str() ) ;
				
				iRv = -21 ;	//	���������߂ł��܂���B
			}
			else
			{
				if ( iHatsu == 0 )
				{
					aCentDedEkiJikoku.setEkiatsukai( eEkiatsukai ) ;
					aCentDedEkiJikoku.setChakujikoku( aCdDedJikoku ) ;
				}
				else
				{
					//	�������́A�w���̕ύX���s���܂���B
					if ( aCentDedEkiJikoku.getEkiatsukai() == 
						CentDedEkiJikoku::Ekiatsukai_None )
					{
						aCentDedEkiJikoku.setEkiatsukai( eEkiatsukai ) ;
					}
					aCentDedEkiJikoku.setHatsujikoku( aCdDedJikoku ) ;
				}
			}
			if ( iRv >= 0 )
			{
				pCentDedRessya->setCentDedEkiJikoku( iEkiOrder , 
					aCentDedEkiJikoku ) ;
			}
		}
	}
	//��2.11��[��1="���l" AND ��2=""]�̗�@���l��
	if ( iRv >= 0 &&  
			CSVROWINDEX_Ekijikoku0 + (int)contiJikokuOrderOfJikokuhyouIndex.size() 
				< (int)pCdCsvDocument->getRowCont()->size() )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size());
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		pCentDedRessya->setBikou( strValue  ) ;
	}
	// --------------------------------
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}


int CconvJikokuhyouCsv::decode_isNullRessyaColumn( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const deque<int>&	contiJikokuOrderOfJikokuhyouIndex , 
		CentDedRessya* pCentDedRessya , 
		const CdCsvDocument* pCdCsvDocument , 
		int iColumnIndex ,
		string* pstrErrorInfoString ) 
{
	int iRv = 1 ;
	string	strErrorInfoString ;
	// --------------------------------
	//	��Ԏ��Index������
	// --------------------------------
	//��2.5��5�s�� <��Ԕԍ�>
	if ( iRv == 1 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()
			->get( CSVROWINDEX_Ressyabangou ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	���̗��Null��Ԃł͂���܂���B
		}
	}
	
	//��2.6��6�s�� <��Ԏ��>
	if ( iRv == 1 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get(CSVROWINDEX_Ressyasyubetsu ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	���̗��Null��Ԃł͂���܂���B
		}
	}

	//��2.7��7�s�� <��Ԗ�>
	if ( iRv == 1 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Ressyamei ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	���̗��Null��Ԃł͂���܂���B
		}
	}

	//��2.8��8�s�� <����>
	if ( iRv == 1 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Gousuu ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	���̗��Null��Ԃł͂���܂���B
		}
	}
	//��2.10��10�s�ځ` �w����
	
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order> �̖@���������܂��B
	//	�v�f�̐��́A�����\�̗񐔂ł��B

	if ( iRv == 1 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iRv == 1 && 
				iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			int iJikokuOrder = 
				contiJikokuOrderOfJikokuhyouIndex[iJikokuhyouIndex] ;
			int iEkiOrder = iJikokuOrder / 2 ;
			int iHatsu = iJikokuOrder % 2 ;
			
			CentDedEkiJikoku aCentDedEkiJikoku 
				= pCentDedRessya->getCentDedEkiJikoku(iEkiOrder) ;
			
			
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;
			CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
			string strValue = aCell.getData() ;
			if ( !strValue.empty() )
			{
				iRv = 0 ;	//	���̗��Null��Ԃł͂���܂���B
			}
		}
	}
	//��2.11��[��1="���l" AND ��2=""]�̗�@���l��
	if ( iRv == 1 && (int)pCdCsvDocument->getRowCont()->size() >
			CSVROWINDEX_Ekijikoku0 + (int)contiJikokuOrderOfJikokuhyouIndex.size() )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size());
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	���̗��Null��Ԃł͂���܂���B
		}
	}
	// --------------------------------
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}


	// ********************************
	//	�R���X�g���N�^
	// ********************************
CconvJikokuhyouCsv::CconvJikokuhyouCsv(
		const std::string& nameKudari ,
		const std::string& nameNobori ,
		const std::string& nameRessyabangou ,
		const std::string& nameRessyasyubetsu ,
		const std::string& nameRessyamei ,
		const std::string& nameGousuu ,
		const std::string& nameGou ,
		const std::string& nameBikou ,
		const std::string& nameChaku ,
		const std::string& nameHatsu ,
		const std::string& nameTsuuka ,
		const std::string& nameKeiyunasi ) :
	m_nameKudari( nameKudari ) , 
	m_nameNobori( nameNobori ) ,
	m_nameRessyabangou( nameRessyabangou ),
	m_nameRessyasyubetsu( nameRessyasyubetsu ),
	m_nameRessyamei( nameRessyamei ),
	m_nameGousuu( nameGousuu ),
	m_nameGou( nameGou ),
	m_nameBikou( nameBikou ) ,
	m_nameChaku( nameChaku ) ,
	m_nameHatsu( nameHatsu ) ,
	m_nameTsuuka( nameTsuuka ) ,
	m_nameKeiyunasi( nameKeiyunasi )
{
}


	// ********************************
	//@name	CconvJikokuhyouCsv
	// ********************************
int CconvJikokuhyouCsv::encode( 
		const CentDedRosen& aCentDedRosen , 
		int iDiaIndex , 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIndex , int iRessyaCount , 
		CdCsvDocument* pCdCsvDocument ) 
{
	int iRv = 0 ;
	
	const CentDedEkiCont* pCentDedEkiCont = NULL ;
	const Mu<CentDedEkiCont::CdDedEki>* pCdDedEkiCont = NULL ;
	const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet = NULL ;
	const CentDedDia* pCentDedDia = NULL ;
	const Mu<const CentDedRessya*>* pCentDedRessyaCont = NULL ;

	// --------------------------------
	//	�I�u�W�F�N�gCdCsvDocument ���N���A
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCentDedEkiCont = aCentDedRosen.getCentDedEkiCont() ;
		pCdDedEkiCont = aCentDedRosen.getCentDedEkiCont()
			->getMuPtr( eRessyahoukou ) ;
		pCentDedRessyasyubetsuContGet = aCentDedRosen.getCentDedRessyasyubetsuCont()->getMuPtr() ; 
		pCentDedDia = aCentDedRosen.getCentDedDiaCont()->getMuPtr()->get( iDiaIndex ) ;
		if ( pCentDedDia == NULL )
		{
			iRv = -1 ;	//	iDiaIndex ���s���ł��B
		}
	}
	if ( iRv >= 0 )
	{
		pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( eRessyahoukou )->getMuPtr() ;
	}
	//pCentDedRessyaCont = ��Ԃ̃R���e�i
	if ( iRv >= 0 )
	{
		if ( !( 0 <= iRessyaIndex && iRessyaIndex < pCentDedRessyaCont->size() ) 
			&& iRessyaIndex != 0 )
		{
			iRv = -2 ;	//	iRessyaIndex ���s���ł��B
		}
	}
	if ( iRv >= 0 )
	{
		if ( iRessyaCount == INT_MAX )
		{
			iRessyaCount = pCentDedRessyaCont->size() - iRessyaIndex ;
		}
		if ( !( 0 <= iRessyaIndex + iRessyaCount && 
			iRessyaIndex + iRessyaCount <= pCentDedRessyaCont->size() ) )
		{
			iRv = -3 ;	//	iRessyaCount ���s���ł��B
		}
	}

	// --------------------------------
	//	CdCsvDocument ���N���A
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCdCsvDocument->getRowCont()->erase( 0 , INT_MAX ) ;
	}

	// --------------------------------
	//	�w�b�_��
	// --------------------------------
	//	1�s�� FileType�s
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( nameFileType ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( nameFileTypeValue ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}	
	//	2�s�� DiaName�s
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedDia->getName() ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}	
	//��2.3�� 3�s�� <����,���>
	if ( iRv >= 0 )
	{
		string strValue ;
		if ( eRessyahoukou == Ressyahoukou_Kudari )
		{
			strValue = m_nameKudari ;
		}
		else
		{
			strValue = m_nameNobori ;
		}
		
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( strValue ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}
	//��2.4��4�s�� 
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	// --------------------------------
	//	�����\�����̍���2��
	// --------------------------------
	//��2.5��5�s�� <��Ԕԍ�>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameRessyabangou ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	//��2.6��6�s�� <��Ԏ��>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameRessyasyubetsu ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	//��2.7��7�s�� <��Ԗ�>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameRessyamei ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	//��2.8��8�s�� <����>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameGousuu ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}
	//��2.9��9�s�� <���\��>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	//��2.10��10�s�ځ` �w����
	
	//	���̃R���e�i�́A  contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order>
	deque<CdDedJikokuOrder>	contiJikokuOrderOfJikokuhyouIndex ;
	if ( iRv >= 0 )
	{
		encode_createContJikokuOrderOfJjikokuhyouIndex( 
			pCentDedEkiCont ,
			eRessyahoukou , 
			&contiJikokuOrderOfJikokuhyouIndex ) ;
	}
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order> �̖@���������܂��B
	//	�v�f�̐��́A�����\�̗񐔂ł��B

	if ( iRv >= 0 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			CdDedJikokuOrder iJikokuOrder = contiJikokuOrderOfJikokuhyouIndex[iJikokuhyouIndex] ;
			int iEkiOrder = iJikokuOrder.getEkiOrder() ;
			int iHatsu = 0 ;
			if ( iJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
			{
				iHatsu = 1 ;
			}
			CentDedEkiCont::CdDedEki aCdDedEki = pCdDedEkiCont->get( iEkiOrder ) ;

			string	strEkimei = aCdDedEki.getEkimei() ;
			string	strChakuHatsu ;
			if ( iHatsu == 0 )
			{
				strChakuHatsu = m_nameChaku ;
			}
			else
			{
				strChakuHatsu = m_nameHatsu ;
			}

			CdCsvRow	aRow ;
			aRow.getCellCont()->insert( CdCsvCell( strEkimei ) ) ;
			aRow.getCellCont()->insert( CdCsvCell( strChakuHatsu ) ) ;
			pCdCsvDocument->getRowCont()->insert( aRow ) ;
		}
	}
	//��2.11��[��1="���l" AND ��2=""]�̗�@���l��
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameBikou ) ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}
	// --------------------------------
	//	��Ԃ��o��(�����\������3��ڈȍ~)
	// --------------------------------
	for ( int idxRessya = iRessyaIndex ; 
		iRv >= 0 && idxRessya < iRessyaIndex + iRessyaCount ; 
		idxRessya ++ )
	{
		const CentDedRessya* pCentDedRessya = pCentDedRessyaCont->get( idxRessya ) ; 

		if ( pCentDedRessya->isNull() )
		{
			iRv = encode_AddRessyaNull( 
					contiJikokuOrderOfJikokuhyouIndex , 
					pCdCsvDocument ) ; 
		}
		else
		{
			iRv = encode_AddRessya( 
					pCentDedRessyasyubetsuContGet , 
					contiJikokuOrderOfJikokuhyouIndex , 
					pCentDedRessya , 
					pCdCsvDocument ) ; 
		}
	}
	
	return iRv ;
}

int CconvJikokuhyouCsv::decode( 
		CentDedRosen* pCentDedRosen , 
		int iDiaIndex , 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIndex , 
		const CdCsvDocument& argCdCsvDocument , 
		string* pstrErrorInfoString ) 
{
	int iRv = 0 ;
	string	strErrorInfoString ;
	CdCsvDocument aCdCsvDocument = argCdCsvDocument ;
	const Mu<CentDedEkiCont::CdDedEki>* pCdDedEkiCont = NULL ;
	const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet = NULL ;
	CentDedDia* pCentDedDia = NULL ;
	CentDedRessyaCont* pCentDedRessyaCont = NULL ;
	// --------------------------------
	//	
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCdDedEkiCont = pCentDedRosen->getCentDedEkiCont()
			->getMuPtr( eRessyahoukou ) ;
		pCentDedRessyasyubetsuContGet = static_cast<const CentDedRosen*>(pCentDedRosen)
			->getCentDedRessyasyubetsuCont()->getMuPtr() ; 

		pCentDedDia= pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( iDiaIndex ) ;
		if ( pCentDedDia == NULL )
		{
			iRv = -21  ;	//	iDiaIndex ���s���ł��B
		}
	}
	if ( iRv >= 0 )
	{
		pCentDedRessyaCont= pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;
	}
	// --------------------------------
	//	
	// --------------------------------
	if ( iRv >= 0 )
	{
		if ( iRessyaIndex == INT_MAX )
		{
			iRessyaIndex = pCentDedRessyaCont->size() ;
		}
		if ( !( 0 <= iRessyaIndex && iRessyaIndex <= pCentDedRessyaCont->size() ) )
		{
			iRv = -22  ;	//	iRessyaIndex ���s���ł��B
		}
	}
	// --------------------------------
	//	CSV�̗񐔂��œK�����܂��B
	// --------------------------------
	int iColumnCount = 0 ;
	if ( iRv >= 0 )
	{
		aCdCsvDocument.adjustColumnCount() ;
		if ( aCdCsvDocument.getRowCont()->size() < CSVROWINDEX_Ekijikoku0 )
		{
			/*
				�s�����Ȃ����܂��B

			@param RowCount
				�s��
			*/
			const char* const ERRREASON_TooFewRows = "Too Few Rows." ;
			const char* const ERRREASON_PROP_RowCount = "RowCount=" ;
						
			
			strErrorInfoString = strprintf( "%s\t%s=%d" , 
				ERRREASON_TooFewRows , 
				ERRREASON_PROP_RowCount , aCdCsvDocument.getRowCont()->size() ) ;
			iRv = -1 ;	//	�s�����Ȃ����܂��B
		}
		else 
		{
			iColumnCount = aCdCsvDocument.getRowCont()->get( 0 ).getCellCont()->size() ;
			if ( iColumnCount < 2 )
			{
				/*
					�񂪏��Ȃ����܂��B
				@param ColumnCount
					��
				*/
				const char* const ERRREASON_TooFewColumns = "Too Few Columns." ;
				const char* const ERRREASON_PROP_ColumnCount = "ColumnCount=" ;
				strErrorInfoString = strprintf( "%s\t%s=%d" , 
					ERRREASON_TooFewColumns , 
					ERRREASON_PROP_ColumnCount , aCdCsvDocument.getRowCont()->get( 0 ).getCellCont()->size() ) ;
				iRv = -2 ;	//	�񂪏��Ȃ����܂��B
			}
		}
	}
	// --------------------------------
	//	FileType ������
	// --------------------------------
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = aCdCsvDocument.getRowCont()->get( 0 ) ;
		CdCsvCell	aCell0 = aRow.getCellCont()->get( 0 ) ;
		CdCsvCell	aCell1 = aRow.getCellCont()->get( 1 ) ;

		/**
			�t�@�C���`�����F���ł��܂���B
		@param FileType
				�t�@�C���`��
		*/
		const char* const ERRREASON_FileTypeMismatch = "File Type Mismatch." ;
		const char* const ERRREASON_PROP_FileType = "FileType=" ;

		if ( aCell0.getData() != nameFileType )
		{
			strErrorInfoString = strprintf( "%s" , 
				ERRREASON_FileTypeMismatch ) ;
			iRv = -3 ;	//	�t�@�C���`�����F���ł��܂���
		}
		else if ( aCell1.getData() != nameFileTypeValue )
		{
			strErrorInfoString = strprintf( "%s\t%s=%s" , 
				ERRREASON_FileTypeMismatch , 
				ERRREASON_PROP_FileType , aCell1.getData().c_str() ) ;
			iRv = -4 ;	//	�t�@�C���`�����F���ł��܂���
		}
	}
	
	// --------------------------------
	//	������Ɖw���̑Ώƃe�[�u�����쐬
	// --------------------------------
	//	���̃R���e�i�́A  contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order>
	deque<int>	contiJikokuOrderOfJikokuhyouIndex ;
	if ( iRv >= 0 )
	{
		int iResult = decode_createContJikokuOrderOfJjikokuhyouIndex( 
			pCentDedRosen->getCentDedEkiCont() ,
			eRessyahoukou , 
			&aCdCsvDocument , 
			&contiJikokuOrderOfJikokuhyouIndex ,
			&strErrorInfoString ) ;
		//iResult = 
		//	-	-1 ;	//	�w����������܂���B
		if ( iResult < 0 )
		{

			iRv = -11  ;	//	�w����������܂���B
		}
	}

	// --------------------------------
	//	��Ԃ��o��(�����\������3��ڈȍ~)
	// --------------------------------
	if ( iRv >= 0 )
	{
		for ( int iColumnIndex = CSVCOLUMNINDEX_Ressya0 ; 
			iRv >= 0 && iColumnIndex <  iColumnCount   ;
			iColumnIndex ++ )
		{
			CentDedRessya	aCentDedRessya( pCentDedRessyaCont->createNullRessya() );
			if ( iRv >= 0 )
			{
				int iResult = decode_isNullRessyaColumn( 
					pCentDedRessyasyubetsuContGet ,
					contiJikokuOrderOfJikokuhyouIndex , 
					&aCentDedRessya , 
					&aCdCsvDocument , 
					iColumnIndex ,
					&strErrorInfoString ) ;
				if ( iResult < 0 )
				{
						iRv = -21 ;
				}
				else if ( iResult == 1 )
				{
					//	Null���
					aCentDedRessya.clear() ;
				}
				else
				{
					int iResult = decode_readRessyaColumn( 
						pCentDedRessyasyubetsuContGet ,
						contiJikokuOrderOfJikokuhyouIndex , 
						&aCentDedRessya , 
						&aCdCsvDocument , 
						iColumnIndex ,
						&strErrorInfoString ) ;
					if ( iResult < 0 )
					{
						iRv = -11 ;
					}
				}
			}
			if ( iRv >= 0 )
			{
				pCentDedRessyaCont->insert( aCentDedRessya , iRessyaIndex ) ;
				iRessyaIndex ++ ;
			}
		}
	}
	// --------------------------------
	// --------------------------------
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}

} //namespace ConvJikokuhyouCsv

