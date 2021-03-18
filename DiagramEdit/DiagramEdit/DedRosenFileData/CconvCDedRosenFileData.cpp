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
//	CconvCDedRosenFileData.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include "NsOu\OuNew.h"
#include "NsOu\dynamic_castOu.h"
#include "str\CdConnectedString2.h"
#include "str\strToInt.h"
#include "str\CConnectedStringCompress.h"
#include "str\OuPropertiesText\CConvNodeContainer.h"
#include "str\OuPropertiesText\CDirectory.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfoContainer.h"
#include "logmsg\LogMsg.h"

#include "CconvCdDedDispProp.h"
#include "CconvCDedRosenFileData.h"
#include "..\entDed\CconvCentDed.h"


/*delete �x���̂ŗ}�~
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
*/

namespace DedRosenFileData{
	using namespace std ;
	using namespace OuLib::NsOu ;
	using namespace OuLib::Str::OuPropertiesText;
	using namespace OuLib::Str::OuPropertiesText::ErrorInfo;
// ****************************************************************
//	CconvCDedRosenFileData
// ****************************************************************
const char nameFileType[]="FileType" ;
const char nameRosen[]="Rosen" ;
const char nameDispProp[]="DispProp" ;

int CconvCDedRosenFileData::CDedRosenFileData_to_OuPropertiesText( 
			const CDedRosenFileData* pCDedRosenFileData , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) 
{
	LogMsg( "CDedRosenFileData_to_CdConnectedString()" ) ;
	int iRv = 0 ;

	//	FileType
	if ( iRv >= 0 )
	{
		pCNodeContainer->setValue( nameFileType , getFileType() ) ;

	}
	//1.Rosen
	if ( iRv >= 0 ){
		Ou<CDirectory> pCDirectory = OuNew<CDirectory>( 
			new CDirectory( nameRosen ) ) ;
		CconvCentDed aConv ;
		int iResult = aConv.CentDedRosen_To_OuPropertiesText( 
			pCDedRosenFileData->getCentDedRosen() ,
			pCDirectory->getCNodeContainer() ) ;
		//	-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
		//	-	-32 ;	//	Ekikibo �̒l���s���ł��B
		//	-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
		//	-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
		//	-	-212 ;	//	DiagramEkiatsukai �̒l���s���ł��B
		if ( iResult < 0 )
		{
			//	-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			//	-	-32 ;	//	Ekikibo �̒l���s���ł��B
			//	-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			//	-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
			//	-	-212 ;	//	DiagramEkiatsukai �̒l���s���ł��B
			iRv = iResult ;
		}
		else
		{
			pCNodeContainer->insert( pCDirectory ) ;
		}
	}
	//2.DispProp
	LogMsg( "CDedRosenFileData_to_CdConnectedString()1" ) ;
	if ( iRv >= 0 )
	{
		Ou<CDirectory> pCDirectory = OuNew<CDirectory>( 
			new CDirectory( nameDispProp ) ) ;
		CconvCdDedDispProp	aCconvCdDedDispProp ;
		int iResult = aCconvCdDedDispProp.toOuPropertiesText( 
			pCDedRosenFileData->getCdDedDispProp() ,
			pCDirectory->getCNodeContainer() ) ;
		//	���݂͕��̐����Ԃ���邱�Ƃ͂���܂���B
		if ( iResult < 0 )
		{
			assert( false ) ;
		}
		else
		{
			pCNodeContainer->insert( pCDirectory ) ;
		}
	}


	LogMsg( "CDedRosenFileData_to_CdConnectedString()=%d" , iRv ) ;
	return ( iRv ) ;
}

int CconvCDedRosenFileData::CDedRosenFileData_from_OuPropertiesText( 
			CDedRosenFileData* pCDedRosenFileData ,
			const OuPropertiesText::CNodeContainer* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) 
{
	int iRv = 0 ;
	COuErrorInfoContainer	aCOuErrorInfoContainer ;
	if ( pCOuErrorInfoContainer == NULL )
	{
		pCOuErrorInfoContainer = &aCOuErrorInfoContainer ;
	}
	// --------------------------------

	if ( iRv >= 0 )
	{
		int iResult = isEncodeAbleFormat( pCNodeContainer ) ;
		if ( iResult < 0 )
		{
			COuErrorInfo aCOuErrorInfo( ERRREASON_FileTypeIsInvalid() ) ;
			aCOuErrorInfo.getProp()->setValue( 
				ERRPROP_FileType() , pCNodeContainer->getValue( nameFileType ) ) ;
			pCOuErrorInfoContainer->insert( aCOuErrorInfo ) ;
			iRv = -1 ;	//	FileType ������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		pCDedRosenFileData->clear() ;
	}
	
	//1.Rosen

	if ( iRv >= 0 )
	{
		Ou<const CDirectory> pCDirectory = dynamic_castOu<const CDirectory>( 
			pCNodeContainer->getInName( nameRosen , 0 ) ) ;
		if ( pCDirectory == NULL )
		{
			COuErrorInfo aCOuErrorInfo( ERRREASON_RosenDirectoryIsNotFound() ) ;
			pCOuErrorInfoContainer->insert( aCOuErrorInfo ) ;
			iRv = -2 ;	//	Rosen Directory��������܂���B
		}
		else
		{
			CentDedRosen	aCentDedRosen ;
			CconvCentDed aCconvCentDed ;
			int iResult = aCconvCentDed.CentDedRosen_From_OuPropertiesText( 
				&aCentDedRosen ,
				pCDirectory->getIfNodeContainerConst() ,
				pCOuErrorInfoContainer ) ;
			//-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			//-	-32 ;	//	Ekikibo �̒l���s���ł��B
			//-	-41 ;	//	DiagramRessyajouhouHyoujiKudari �̒l���s���ł��B
			//-	-42 ;	//	DiagramRessyajouhouHyoujiNobori �̒l���s���ł��B
			//-	-101 ;	//	Eki ���f�B���N�g���ł͂���܂���B
			//-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			//-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
			//-	-201 ;	//	Ressyasyubetsu ���f�B���N�g���ł͂���܂���B
			//-	-211 ;	//	DiaName ���w�肳��Ă��܂���B
			//-	-212 ;	//	RessyaCont��������܂���B
			//-	-352 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
			if ( iResult < 0 )
			{
				//-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
				//-	-32 ;	//	Ekikibo �̒l���s���ł��B
				//-	-41 ;	//	DiagramRessyajouhouHyoujiKudari �̒l���s���ł��B
				//-	-42 ;	//	DiagramRessyajouhouHyoujiNobori �̒l���s���ł��B
				//-	-101 ;	//	Eki ���f�B���N�g���ł͂���܂���B
				//-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
				//-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
				//-	-201 ;	//	Ressyasyubetsu ���f�B���N�g���ł͂���܂���B
				//-	-211 ;	//	DiaName ���w�肳��Ă��܂���B
				//-	-212 ;	//	RessyaCont��������܂���B
				//-	-352 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
				iRv = iResult ;
			}
			else
			{
				*pCDedRosenFileData->getCentDedRosen() = aCentDedRosen ;
			}
		}
	}
	//2.DispProp
	if ( iRv >= 0 )
	{
		Ou<const CDirectory> pCDirectory = dynamic_castOu<const CDirectory>( 
			pCNodeContainer->getInName( nameDispProp , 0 ) ) ;
		if ( pCDirectory == NULL )
		{
			COuErrorInfo aCOuErrorInfo( ERRREASON_DispPropnDirectoryIsNotFound() ) ;
			pCOuErrorInfoContainer->insert( aCOuErrorInfo ) ;
			iRv = -3 ;	//	DispProp Directory��������܂���B
		}
		else
		{
			CconvCdDedDispProp	aCconvCdDedDispProp ;
			CdDedDispProp	aCdDedDispProp ;
			int iResult = aCconvCdDedDispProp.fromOuPropertiesText( 
				&aCdDedDispProp ,
				pCDirectory->getIfNodeContainerConst() , 
				pCOuErrorInfoContainer ) ;
			//-	-12 ;	//	JikokuhyouFont �̓��e���s���ł��B
			//-	-22 ;	//	DiaEkimeiFont �̓��e���s���ł��B
			//-	-32 ;	//	DiaJikokuFont �̓��e���s���ł��B
			//-	-82 ;	//	DisplayRessyabangou ���s���ł��B
			//-	-92 ;	//	DisplayRessyamei ���s���ł��B
			//-	-102 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
			//-	-112 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B
			if ( iResult < 0 )
			{
				//-	-512 ;	//	JikokuhyouFont �̓��e���s���ł��B
				//-	-522 ;	//	DiaEkimeiFont �̓��e���s���ł��B
				//-	-532 ;	//	DiaJikokuFont �̓��e���s���ł��B
				//-	-582 ;	//	DisplayRessyabangou ���s���ł��B
				//-	-592 ;	//	DisplayRessyamei ���s���ł��B
				//-	-602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
				//-	-612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B
				iRv = -500 ;	//	DispProp �̓��e���s��
			}
			else
			{
				pCDedRosenFileData->setCdDedDispProp( aCdDedDispProp ) ;
			}
		}
	}
	return ( iRv ) ;
}

int CconvCDedRosenFileData::isEncodeAbleFormat( 
			const OuPropertiesText::CNodeContainer* pCNodeContainer ) 
{
	int iRv = 0 ;
	string strFileType = pCNodeContainer->getValue( nameFileType ) ;
	if ( strFileType != getFileType() )
	{
		iRv = -1 ;	//	FileType ������������܂���B
	}
	return iRv ;
}

int CconvCDedRosenFileData::CDedRosenFileData_to_string( 
		const CDedRosenFileData& aCDedRosenFileData , 
		string* pString ) 
{
	LogMsg( "CDedRosenFileData_to_string()" ) ;

	int iRv = 0 ;
	string	strRv ;
	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		int iResult = CDedRosenFileData_to_OuPropertiesText( 
			&aCDedRosenFileData , 
			&aCNodeContainer ) ;
		//iResult = 
		//-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
		//-	-32 ;	//	Ekikibo �̒l���s���ł��B
		//-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
		//-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
		//-	-212 ;	//	DiagramEkiatsukai �̒l���s���ł��B
		if ( iResult < 0 )
		{
			iRv = iResult ;
		}
	}
	
	LogMsg( "CDedRosenFileData_to_string()1" ) ;

	if ( iRv >= 0 )
	{
		CConvNodeContainer	aConv  ;
		strRv = aConv.encode( &aCNodeContainer ) ;
	}

	if ( iRv >= 0 )
	{
		if ( pString != NULL ){
			*pString = strRv ;
		}
	}

	LogMsg( "CDedRosenFileData_to_string()=%d" , iRv ) ;
	return ( iRv ) ;
}


int CconvCDedRosenFileData::CDedRosenFileData_from_string( 
			CDedRosenFileData* pCDedRosenFileData ,
			const string& aString ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) 
{
	LogMsg( "CDedRosenFileData_from_string()" ) ;

	int iRv = 0 ;
	string	strRv ;

	LogMsg( "CDedRosenFileData_from_string()1" ) ;

	pCDedRosenFileData->clear() ;
	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		string strErrorInfostring ;
		CConvNodeContainer	aConv ;
		int iResult = aConv.decode( aString , &aCNodeContainer , &strErrorInfostring ) ;
		//	-	-1 ;	//	�f�B���N�g�����r���ŕ��Ă��܂��B
		if ( iResult < 0 )
		{
			iRv = -1 ;	//	�f�B���N�g�����r���ŕ��Ă��܂��B	
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = CDedRosenFileData_from_OuPropertiesText( 
			pCDedRosenFileData , 
			&aCNodeContainer , 
			pCOuErrorInfoContainer ) ;
		//iResult = 
		//-	-1 ;	//	FileType ������������܂���B
		//-	-2 ;	//	Rosen Directory��������܂���B
		//-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
		//-	-32 ;	//	Ekikibo �̒l���s���ł��B
		//-	-41 ;	//	DiagramRessyajouhouHyoujiKudari �̒l���s���ł��B
		//-	-42 ;	//	DiagramRessyajouhouHyoujiNobori �̒l���s���ł��B
		//-	-101 ;	//	Eki ���f�B���N�g���ł͂���܂���B
		//-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
		//-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
		//-	-201 ;	//	Ressyasyubetsu ���f�B���N�g���ł͂���܂���B
		//-	-211 ;	//	DiaName ���w�肳��Ă��܂���B
		//-	-212 ;	//	RessyaCont��������܂���B
		//-	-352 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
		//-	-3 ;	//	DispProp Directory��������܂���B
		//-	-512 ;	//	JikokuhyouFont �̓��e���s���ł��B
		//-	-522 ;	//	DiaEkimeiFont �̓��e���s���ł��B
		//-	-532 ;	//	DiaJikokuFont �̓��e���s���ł��B
		//-	-582 ;	//	DisplayRessyabangou ���s���ł��B
		//-	-592 ;	//	DisplayRessyamei ���s���ł��B
		//-	-602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
		//-	-612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B
		if ( iResult < 0 )
		{
			//-	-1001 ;	//	FileType ������������܂���B
			//-	-1002 ;	//	Rosen Directory��������܂���B
			//-	-1022 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			//-	-1032 ;	//	Ekikibo �̒l���s���ł��B
			//-	-1041 ;	//	DiagramRessyajouhouHyoujiKudari �̒l���s���ł��B
			//-	-1042 ;	//	DiagramRessyajouhouHyoujiNobori �̒l���s���ł��B
			//-	-1101 ;	//	Eki ���f�B���N�g���ł͂���܂���B
			//-	-1111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			//-	-1152 ;	//	DiagramSenStyle �̒l���s���ł��B
			//-	-1201 ;	//	Ressyasyubetsu ���f�B���N�g���ł͂���܂���B
			//-	-1211 ;	//	DiaName ���w�肳��Ă��܂���B
			//-	-1212 ;	//	RessyaCont��������܂���B
			//-	-1352 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
			//-	-1003 ;	//	DispProp Directory��������܂���B
			//-	-1512 ;	//	JikokuhyouFont �̓��e���s���ł��B
			//-	-1522 ;	//	DiaEkimeiFont �̓��e���s���ł��B
			//-	-1532 ;	//	DiaJikokuFont �̓��e���s���ł��B
			//-	-1582 ;	//	DisplayRessyabangou ���s���ł��B
			//-	-1592 ;	//	DisplayRessyamei ���s���ł��B
			//-	-1602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
			//-	-1612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B
			iRv = iResult - 1000 ;
		}
	}
	LogMsg( "CDedRosenFileData_from_string()=%d" , iRv ) ;
	return ( iRv ) ;
}

int CconvCDedRosenFileData::isEncodeAbleFormat( 
			const string& strOudFile  ) 
{
	LogMsg( "isEncodeAbleFormat()" ) ;

	int iRv = 0 ;
	string	strRv ;

	LogMsg( "CDedRosenFileData_from_string()1" ) ;

	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		string strErrorInfostring ;
		CConvNodeContainer	aConv ;
		int iResult = aConv.decode( strOudFile , &aCNodeContainer , &strErrorInfostring ) ;
		//	-	-1 ;	//	�f�B���N�g�����r���ŕ��Ă��܂��B
		if ( iResult < 0 )
		{
			iRv = -1 ;	//	�f�B���N�g�����r���ŕ��Ă��܂��B	
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = isEncodeAbleFormat( &aCNodeContainer ) ;
		//-	-1 ;	//	FileType ������������܂���B
		if ( iResult < 0 )
		{
			//-	-1001 ;	//	FileType ������������܂���B
			iRv = iResult -1000 ;	//	FileType ������������܂���B
		}
	}

	return ( iRv ) ;

}

} //namespace DedRosenFileData

