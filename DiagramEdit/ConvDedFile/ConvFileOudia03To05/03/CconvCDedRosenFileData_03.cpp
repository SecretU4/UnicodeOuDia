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
//	CconvCDedRosenFileData_03.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "CconvCDedRosenFileData_03.h"
#include "CconvCentDed_03.h"
#include "str/CdConnectedString2.h"
#include "str/strToInt.h"
#include "str\CConnectedStringCompress.h"
#include "logmsg/LogMsg.h"

#include "CconvCdDedDispProp_03.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// ****************************************************************
//	CconvCDedRosenFileData_03
// ****************************************************************
const char nameFileType[]="FileType" ;
const char nameRosen[]="Rosen" ;
const char nameDispProp[]="DispProp" ;

int CconvCDedRosenFileData_03::CDedRosenFileData_to_CdConnectedString( 
		const CDedRosenFileData& aCDedRosenFileData , 
		CdConnectedString2* pCdConnectedString ) 
{
	LogMsg( "CDedRosenFileData_to_CdConnectedString()" ) ;
	int iRv = 0 ;
	//	FileType
	if ( iRv >= 0 )
	{
		pCdConnectedString->setItem( nameFileType , getFileType() ) ;
	}
	//1.Rosen
	if ( iRv >= 0 ){
		CdConnectedString2	connectstrRosen ;
		CconvCentDed_03 aCconvCentDed_03 ;
		int iResult = aCconvCentDed_03.CentDedRosen_To_CdConnectedString( 
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
		CconvCdDedDispProp_03	aCconvCdDedDispProp_03 ;
		CdConnectedString2	connectstrDispProp ;
		int iResult = aCconvCdDedDispProp_03.toCdConnectedString( 
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

int CconvCDedRosenFileData_03::CDedRosenFileData_from_CdConnectedString( 
		CDedRosenFileData* pCDedRosenFileData ,
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;

	if ( iRv >= 0 )
	{
		int iResult = isEncodeAbleFormat( aCdConnectedString ) ;
		if ( iResult < 0 )
		{
			iRv = -1 ;	//	FileType ������������܂���B
		}
	}
	if ( iRv >= 0 ){
		pCDedRosenFileData->clear() ;
	}
	
	//1.Rosen

	if ( iRv >= 0 ){
		CdConnectedString2	connectstrRosen ;
		aCdConnectedString.getSubitem( 
				string( nameRosen ) + '.' , &connectstrRosen ) ;
		CentDedRosen	aCentDedRosen ;
		CconvCentDed_03 aCconvCentDed_03 ;
		int iResult = aCconvCentDed_03.CentDedRosen_From_CdConnectedString( 
			&aCentDedRosen ,connectstrRosen ) ;
		if ( iResult < 0 ){
			iRv = -11 ;	//	Rosen �̓��e���s��
		}	else	{
			*pCDedRosenFileData->getCentDedRosen() = aCentDedRosen ;
		}
	}
	//2.DispProp
	if ( iRv >= 0 ){
		CconvCdDedDispProp_03	aCconvCdDedDispProp_03 ;
		CdConnectedString2	connectstrDispProp ;
		aCdConnectedString.getSubitem( 
				string( nameDispProp ) + '.' , &connectstrDispProp ) ;
		CdDedDispProp	aCdDedDispProp ;
		
		int iResult = aCconvCdDedDispProp_03.fromCdConnectedString( 
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

int CconvCDedRosenFileData_03::isEncodeAbleFormat( 
			const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;
	string strFileType = aCdConnectedString.getValue( nameFileType ) ;
	if ( strFileType != getFileType() )
	{
		iRv = -1 ;	//	FileType ������������܂���B
	}
	return iRv ;
}

int CconvCDedRosenFileData_03::CDedRosenFileData_to_string( 
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

	if ( iRv >= 0 )
	{
		CConnectedStringCompress	aCompress( '.' ) ;
		strRv = aCompress.encode( aCdConnectedString2 )  ;
	}

	if ( iRv >= 0 ){
		if ( pString != NULL ){
			*pString = strRv ;
		}
	}

	LogMsg( "CDedRosenFileData_to_string()=%d" , iRv ) ;
	return ( iRv ) ;
}


int CconvCDedRosenFileData_03::CDedRosenFileData_from_string( 
		CDedRosenFileData* pCDedRosenFileData ,
		const string& strOudFile ) 
{
	LogMsg( "CDedRosenFileData_from_string()" ) ;

	int iRv = 0 ;
	string	strRv ;
	CdConnectedString2	aCdConnectedString( '\n' , '=' , false ) ;

	LogMsg( "CDedRosenFileData_from_string()1" ) ;

	pCDedRosenFileData->clear() ;
	if ( iRv >= 0 )
	{
		CConnectedStringCompress	aCompress( '.' ) ;
		int iResult = aCompress.decode( strOudFile , &aCdConnectedString )  ;
		//	-	-1 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B
		if ( iResult < 0 )
		{
			iRv = -101 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = CDedRosenFileData_from_CdConnectedString( 
			pCDedRosenFileData , aCdConnectedString ) ;
		//iResult = 
		//		-	-1 ;	//	FileType ������������܂���B
		//		-	-11 ;	//	Rosen �̓��e���s��
		//		-	-21 ;	//	DispProp �̓��e���s��
		if ( iResult < 0 ){
			iRv = iResult ;
		}
	}
	LogMsg( "CDedRosenFileData_from_string()=%d" , iRv ) ;
	return ( iRv ) ;
}

int CconvCDedRosenFileData_03::isEncodeAbleFormat( 
			const string& strOudFile  ) 
{
	int iRv = 0 ;
	CdConnectedString2	aCdConnectedString( '\n' , '=' , false ) ;
	if ( iRv >= 0 )
	{
		CConnectedStringCompress	aCompress( '.' ) ;
		int iResult = aCompress.decode( strOudFile , &aCdConnectedString ) ;
		//	-	-1 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B
		if ( iResult < 0 )
		{
			iRv = -101 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = isEncodeAbleFormat( aCdConnectedString ) ;
		//-	0 ;	//	���߉\�ł��B
		//-	-1 ;	//	FileType ������������܂���B
		if ( iResult < 0 )
		{
			iRv = iResult ;
		}
	}
	return ( iRv ) ;

}


