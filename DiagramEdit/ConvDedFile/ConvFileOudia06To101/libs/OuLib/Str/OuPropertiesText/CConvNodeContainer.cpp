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
//$Id: CConvNodeContainer.cpp 10 2012-08-26 09:48:47Z okm $
#include "str\OuPropertiesText\CConvNodeContainer.h"
#include "str\OuPropertiesText\CDirectory.h"
#include "Ou\dynamic_castOu.h"
#include "Ou\OuNew.h"
#include "str\strprintf.h"
using namespace OuLib ;

namespace OuPropertiesText{


/**
	�����񂪃f�R�[�h�ł��܂���B
@param ERRSUBPROP_Text
	�ΏۂƂȂ镶����
*/
const char* const CConvNodeContainer::ERRREASON_Undecoded_Text = "Undecoded Text.";
/**
	�f�B���N�g�����r���ŕ��Ă��܂��B
*/
const char* const CConvNodeContainer::ERRREASON_ContainerAborted = "Container Aborted." ;
/**
	�f�B���N�g�������Ă��܂���
*/
const char* const CConvNodeContainer::ERRREASON_ContainerIsNotClosed = "Container Is Not Closed." ;

/**
	�s�e�L�X�g
*/
const char* const CConvNodeContainer::ERRPROP_Text = "Text" ;

	// ********************************
	//	�R���X�g���N�^
	// ********************************

CConvNodeContainer::CConvNodeContainer  (void)
{
}

CConvNodeContainer::~CConvNodeContainer  (void)
{
}
	// --------------------------------
	//@name �������֐�
	// --------------------------------

int CConvNodeContainer::decodeNodeContainer(
		const string& strContent , 	int iPosBegin  , int* piPosNext , 
		CNodeContainer* pCNodeContainer ,
		string* pstrErrorInfoString ) 
{
	int iRv = 1 ;
	string strLine ;
	string strErrorInfoString ;
	int iPosNext = iPosBegin ;


	pCNodeContainer->erase( 0 , INT_MAX ) ;

	if ( iPosBegin >= (int)strContent.size() )
	{
		iRv = 0 ;	//	���ł� iPosBegin ���R���e���c�̖����ɂ���܂��B
	}
	if ( iRv >= 1 )
	{
		
		for ( ;
			iRv >= 0 && 
			1 == getLine( 
				strContent , iPosBegin , &iPosNext , 
				&strLine  ) ;
			iPosBegin = iPosNext )
		{
			if ( strLine == "" )
			{
				continue ;
			}
			else if ( strLine == "." )
			{
				//	�f�B���N�g���I���L��
				//	iPosNext �́A"." �̍s�̑O�Ɉڂ��܂��B
				iPosNext = iPosBegin ;
				break ;	//	NodeContainer �̖���
			}
			bool bIsParsed = false ;
			if ( !bIsParsed )
			{
				if ( strLine.find( '=' ) == string::npos && 
					strLine[ strLine.size() - 1 ] == '.' )
				{
					string strName = strLine.substr( 0 , strLine.size() -1 ) ;

					//iPosBegin= ���̍s�Ɉړ�
					iPosBegin = iPosNext ;
					OuNew<CDirectory>	pCDirectory( new CDirectory( strName ) ) ; 
					int iResult = decodeNodeContainer(
						strContent , iPosBegin , &iPosNext , 
						pCDirectory->getCNodeContainer() , 
						&strErrorInfoString ) ;
					if ( iResult == 0 )
					{
						//	�f�B���N�g�������Ă��܂���
						if ( !strErrorInfoString.empty() ){	strErrorInfoString += "\n" ; };
						strErrorInfoString += ERRREASON_ContainerIsNotClosed ;
						iRv = -2 ;							//	�f�B���N�g�������Ă��܂���
					}
					else if ( iResult < 0 )
					{
						//	�����񂪃f�R�[�h�ł��܂���B
						if ( !strErrorInfoString.empty() ){	strErrorInfoString += "\n" ; };
						strErrorInfoString += strprintf( "%s\t%s=%s" , 
							ERRREASON_Undecoded_Text , 
							ERRPROP_Text , strLine.c_str() ) ;
						iRv = -1 ;	//	�����񂪃f�R�[�h�ł��܂���B	
					}
					else
					{
						pCNodeContainer->insert( pCDirectory ) ;
						//	iPosNext = �f�B���N�g���I���L���̎��̍s�Ɉړ�
						iPosBegin = iPosNext ;
						getLine( 
							strContent , iPosBegin , &iPosNext , 
							&strLine  ) ;
					}
					bIsParsed = true ;
				}
			}
			if ( !bIsParsed )
			{
				Ou<CPropertyString>	pCPropertyString ;
				if ( 1 == CConvNodeContainer::decodePropertyString(
					strContent , iPosBegin  , &iPosNext , 
					&pCPropertyString ,
					&strErrorInfoString ) )
				{
					pCNodeContainer->insert( pCPropertyString ) ;
					bIsParsed = true ;
				}
			}
			if ( !bIsParsed )
			{
				//	�����񂪃f�R�[�h�ł��܂���B
				if ( !strErrorInfoString.empty() ){	strErrorInfoString += "\n" ; };
				strErrorInfoString += strprintf( "%s\t%s=%s" , 
					ERRREASON_Undecoded_Text , 
					ERRPROP_Text , strLine.c_str() ) ;
				iRv = -1 ;	//	�����񂪃f�R�[�h�ł��܂���B	
			}
		}
	}
	// --------------------------------
	if ( piPosNext != NULL )
	{
		*piPosNext = iPosNext ;
	}
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}


string CConvNodeContainer::encodePropertyString_escapePropertyValue(
		const string& strValue ) 
{
	string strRv ;
	strRv.reserve( strRv.length() ) ;
	for ( string::const_iterator ite = strValue.begin() ;
		ite != strValue.end() ;
		ite ++ )
	{
		if ( *ite == '.' )
		{
			//	'.' �̓G�X�P�[�v�̑Ώۂ���͂����܂����B
			strRv += "." ;
		}
		else if ( *ite == '\n' )
		{
			strRv += "\\n" ;
		}
		else if ( *ite == '\\' )
		{
			strRv += "\\\\" ;
		}
		else
		{
			strRv += *ite ;
		}

	}
	return strRv ;
}

string CConvNodeContainer::decodePropertyString_unescapePropertyValue(
		const string& strValue ) 
{
	string strRv ;
	strRv.reserve( strRv.length() ) ;
	for ( string::const_iterator ite = strValue.begin() ;
		ite != strValue.end() ;
		ite ++ )
	{
		if ( ite + 1 != strValue.end() && *ite == '\\' )
		{
			ite ++ ;
			if ( *ite == '.' )
			{
				//	'.' �̓G�X�P�[�v�̑Ώۂ���͂����܂����B
				strRv += '\\' ;
				strRv += '.' ;
			}
			else if ( *ite == 'n' ) 
			{
				strRv += '\n' ;
			}
			else if ( *ite == '\\' )
			{
				strRv += '\\' ;
			}
			else
			{
				strRv += '\\' ;
				strRv += *ite ;
			}
		}
		else
		{
			strRv += *ite ;
		}

	}
	return strRv ;
}


int CConvNodeContainer::decodePropertyString(
		const string& strContent , 	int iPosBegin  , int* piPosNext , 
		Ou<CPropertyString>* ppCPropertyString ,
		string* pstrErrorInfoString ) 
{
	int iRv = 1 ;
	string strLine ;
	string strErrorInfoString ;
	int iPosNext = iPosBegin ;
	Ou<CPropertyString> pCPropertyString ;

		if ( 1 == getLine( 
			strContent , iPosBegin , &iPosNext , 
			&strLine  ) )
		{
			string	strName ;
			string	strValue ;
			string::size_type	pos = strLine.find( '=' ) ;
			if ( pos == string::npos )
			{
				strName = strLine ;
			}
			else
			{
				strName = strLine.substr( 0 , pos ) ;
				strValue = decodePropertyString_unescapePropertyValue( strLine.substr( pos + 1 ) ) ;
			}
			pCPropertyString = OuNew<CPropertyString>( new CPropertyString( strName , strValue  ) ) ;
		}
		else
		{
			iRv = 0 ;	//	���ł� iPosBegin ���R���e���c�̖����ɂ���܂��B
		}
	// --------------------------------
	if ( piPosNext != NULL )
	{
		*piPosNext = iPosNext ;
	}
	if ( ppCPropertyString != NULL )
	{
		*ppCPropertyString = pCPropertyString ;
	}
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}


int CConvNodeContainer::getLine( 
		const string& strContent , 	int iPosBegin  , int* piPosNext , 
		string* pstrLine  ) 
{
	int iRv = 1 ;
	string strLine ;
	int iPosNext = iPosBegin ;

	if ( iPosBegin >= (int)strContent.size() )
	{
		iRv = 0 ;	//	���ł� iPosBegin ���R���e���c�̖����ɂ���܂��B
	}
	if ( iRv >= 1 )
	{

		for ( iPosNext = iPosBegin ; 
			iPosNext < (int)strContent.size() && strContent[iPosNext] != '\n' ; 
			iPosNext ++ )
		{
		}
		strLine = strContent.substr( iPosBegin , iPosNext - iPosBegin ) ;
		if ( strContent[iPosNext] == '\n' )
		{
			iPosNext ++ ;
		}
	}
	// --------------------------------
	if ( piPosNext != NULL )
	{
		*piPosNext = iPosNext ;
	}
	if ( pstrLine != NULL )
	{
		*pstrLine = strLine ;
	}
	return iRv ;
}

	// ********************************
	//@name	CConvNodeContainer  
	// ********************************

string CConvNodeContainer::encode( 
		const IfNodeContainerConst* pCNodeContainer ) 
{
	int iRv = 0 ;
	string strContent ;

	if ( iRv >= 0 )
	{
		for ( int iIndex = 0 ; iIndex < pCNodeContainer->size() ; iIndex ++ )
		{
			bool bProcessed = false ;
			string	strContentLine ;
			Ou<const CNode>	pCNode = pCNodeContainer->get( iIndex ) ;
			if ( !bProcessed )
			{
				Ou<const CPropertyString> pCPropertyString ;
				if ( ( pCPropertyString = dynamic_castOu<const CPropertyString>( pCNode ) ) != NULL )
				{
					strContentLine = pCPropertyString->getName() + "=" + 
						encodePropertyString_escapePropertyValue( pCPropertyString->getValue() ) ; 
					bProcessed = true ;
				}
			}
			if ( !bProcessed )
			{
				Ou<const CDirectory> pCDirectory ;
				if ( ( pCDirectory = dynamic_castOu<const CDirectory>( pCNode ) ) != NULL )
				{
					string strNodeContainer = encode( pCDirectory->getIfNodeContainerConst() ) ;
					strContentLine = pCDirectory->getName() + ".\n" + 
						strNodeContainer + 
						"." ; 
					bProcessed = true ;
				}
			}
			strContent += ( strContentLine + "\n" ) ;
		}
	}
	return strContent ;
}


int CConvNodeContainer::decode(
		const string& strContent , 
		CNodeContainer* pCNodeContainer ,
		string* pstrErrorInfoString ) 
{
	int iRv = 0 ;
	string strErrorInfoString ;
	if ( iRv >= 0 )
	{
		int iPosNext = 0 ; 
		int iResult = decodeNodeContainer(
				strContent , 0  , &iPosNext , 
				pCNodeContainer ,
				pstrErrorInfoString ) ;
		if ( iResult > 0 )
		{
			if ( iPosNext < (int)strContent.size() )
			{
				//	�f�B���N�g�����r���ŕ��Ă��܂��B
				if ( !strErrorInfoString.empty() ){	strErrorInfoString += "\n" ; };
				strErrorInfoString = ERRREASON_ContainerAborted ;
				iRv = -1 ;	//	�f�B���N�g�����r���ŕ��Ă��܂��B
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



} //namespace OuPropertiesText
