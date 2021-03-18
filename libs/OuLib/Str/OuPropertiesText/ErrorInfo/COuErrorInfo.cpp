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
// $Id: COuErrorInfo.cpp 294 2016-06-11 05:10:03Z okm $
// ****************************************************************
/** @file */

#include "str\OuPropertiesText\ErrorInfo\COuErrorInfo.h"
#include "str\strprintf.h"
#include "str\CdConnectedString2.h"
#include "NsOu\dynamic_castOu.h"
#include "NsOu\OuNew.h"

using namespace std ;
namespace OuLib{
namespace Str{
namespace OuPropertiesText{
namespace ErrorInfo{

	// ********************************
	//@name �萔
	// ********************************
const char* const COuErrorInfo::DirectoryName_ErrorInfo = "ErrorInfo" ;
const char* const COuErrorInfo::PropertyTextName_Reason = "Reason" ;
const char* const COuErrorInfo::DirectoryName_Prop = "Prop" ;

	// ********************************
	//@name ����
	// ********************************
	
Ou<CDirectory> COuErrorInfo::toOuPropertiesTextErrorInfo()const
{
	int iRv =0 ;
	Ou<CDirectory> pCDirectory ;
	if ( iRv >= 0 )
	{
		pCDirectory = OuNew<CDirectory>( new CDirectory( DirectoryName_ErrorInfo ) ) ;
		CNodeContainer* pCNodeContainer = pCDirectory->getCNodeContainer() ; 
		pCNodeContainer->setValue( PropertyTextName_Reason , m_strReason ) ;
		if ( m_Prop.size() > 0 )
		{
			Ou<CDirectory> pdirProp = OuNew<CDirectory>( new CDirectory( DirectoryName_Prop ) ) ;
			*pdirProp->getCNodeContainer() = m_Prop ; 
			pCNodeContainer->insert( pdirProp ) ;
		}
	}

	return pCDirectory ;
}

int COuErrorInfo::fromOuPropertiesTextErrorInfo( 
		Ou<const CDirectory> pCDirectory )
{
	int iRv = 0 ;

	const IfNodeContainerConst* pCNodeContainer = pCDirectory->getIfNodeContainerConst() ;
	clear() ;

	string strReason ;
	CNodeContainer	aProp ;
	if ( iRv >= 0 )
	{
		if ( pCDirectory->getName() != DirectoryName_ErrorInfo )
		{
			iRv = -1 ;	//	pCDirectory �� "Directory" �ł͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		strReason = pCNodeContainer->getValue( PropertyTextName_Reason ) ;
		if ( strReason.empty() )
		{
			iRv = -2 ;	//	Directory ��"Reason" PropertyText ������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		if ( pCNodeContainer->sizeInName( DirectoryName_Prop ) > 0 ) 
		{
			Ou<const CDirectory> pdirProp = dynamic_castOu<const CDirectory>( 
				pCNodeContainer->getInName( DirectoryName_Prop , 0 ) 
			);
			if ( pdirProp != NULL )
			{
				aProp = *Ou<CDirectory>( pdirProp->clone() )->getCNodeContainer() ;
			}
		}
	}
	if ( iRv >= 0 )
	{
		m_strReason = strReason ;
		m_Prop = aProp ;
	}
	return iRv ;
}

std::string COuErrorInfo::toOuErrorInfoText()const 
{
	string strRv ;

	//Reason
	strRv = m_strReason ;

	//Prop
	for ( int idxProp = 0 ; idxProp < m_Prop.size() ; idxProp ++ )
	{
		Ou<CNode>	pCNode = m_Prop.get( idxProp ) ;
		Ou<CPropertyString> pCPropertyString = dynamic_castOu<CPropertyString>( pCNode ) ;
		if ( pCPropertyString != NULL && !pCPropertyString->getName().empty() )
		{
			strRv += '\t' ;
			strRv += pCPropertyString->getName() ;
			if ( !pCPropertyString->getValue().empty() )
			{
				strRv += '=' ;
				strRv += pCPropertyString->getValue() ;
			}
		}
	}
	return strRv ;
}

int COuErrorInfo::fromOuErrorInfoText( 
	const std::string& strOuErrorInfoText ) 
{
	int iRv = 0 ;
	clear() ;
	string strReason ;
	CNodeContainer	aProp ;

	CdConnectedString2 aCdConnectedString2( 
		strOuErrorInfoText , '\t' , '=' ) ;

	//Reason
	if ( iRv >= 0 )
	{
		if ( aCdConnectedString2.size() > 0 )
		{
			CdConnectedString2::CdItem aCdItem = aCdConnectedString2.at( 0 ) ;
			
			strReason = aCdItem.getName() ;
			if ( !aCdItem.getValue().empty() )
			{
				strReason += aCdConnectedString2.getEqualChar() ;
				strReason += aCdItem.getValue() ;
			}
		}
	}

	//Prop
	for ( int idxProp = 1 ; iRv >= 0 && idxProp < aCdConnectedString2.size() ; idxProp ++ )
	{
		CdConnectedString2::CdItem aCdItem = aCdConnectedString2.at( idxProp ) ;
		Ou<CPropertyString> pCPropertyString = OuNew<CPropertyString>( 
			new CPropertyString( aCdItem.getName() , aCdItem.getValue() ) ) ;
		aProp.insert( pCPropertyString ) ;
	}


	if ( iRv >= 0 )
	{
		m_strReason = strReason ;
		m_Prop = aProp ;
	}
	return iRv ;
}

void COuErrorInfo::clear() 
{
	m_strReason.erase() ;
	m_Prop.erase( 0 , INT_MAX ) ;
}

bool COuErrorInfo::isNull()const 
{
	return ( m_strReason.empty() && m_Prop.size() == 0 ) ;
}

} //namespace ErrorInfo{
} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{
