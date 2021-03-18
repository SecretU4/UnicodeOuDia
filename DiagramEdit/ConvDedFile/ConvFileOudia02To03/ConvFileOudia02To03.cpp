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
// ConvFileOudia02To03.cpp : DLL �A�v���P�[�V�����p�̃G���g�� �|�C���g���`���܂��B
//
#include "stdafx.h"
#include "ConvFile2Dll.h"
#include "ConvFileOudia02To03.h"


// ****************************************************************
//	DLL API
// ****************************************************************
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}


#include "CaConvFile_Oudia02To03.h"
static CaConvFile_Oudia02To03	g_StaticObj ;


CONVFILEOUDIA02TO03_API void* ConvFile2Dll_getIfConvFile( void ) 
{
	return &g_StaticObj ;
}



//kyuusi
#if 0
#include "ConvFileDll.h"
#include "ConvFileOudia02To03.h"
#include "str\strLf.h"


// ----------------------------------------------------------------
//	�����֐�
// ----------------------------------------------------------------

// ----------------------------------------------------------------
//	DLL�ŗL
// ----------------------------------------------------------------
/**
  �֐��ďo���ɕԂ����߂̃��������m�ۂ��܂��B
@param iBytes [in]
  �m�ۂ���o�C�g�����w�肵�Ă��������B
@return
  �m�ۂ����������̈�̃A�h���X��Ԃ��܂��B
  ���s������NULL��Ԃ��܂��B
*/
static CHAR* ConvFile_MemAlloc( DWORD iBytes )
{
	return new char [iBytes] ;
}


// ****************************************************************
//	DLL API
// ****************************************************************
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

#include <string>
using namespace std ;

#include "CDedRosenFileData.h"
#include "CconvCDedRosenFileData_01.h"
#include "CconvCDedRosenFileData_02.h"
#include "CconvCDedRosenFileData.h"
#include "str\CConnectedStringCompress.h"
#include "str\vectorToFile.h"

static const char nameFileType[] = "FileType" ;
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia02To03 Ver 0.01" ;

CONVFILEOUDIA02TO03_API int ConvFile_leftToRight(
	const CHAR* binLeftFile , 
	DWORD iLeftFileBytes ,
	CHAR** pbinRightFile , 
	DWORD* piRightFileBytes ) 
{
	int iRv = 0 ;
	bool	bFormatFound = false ;

	// --------------------------------
	//	������ւ̕ϊ�
	// --------------------------------
	string 	strSrcFileContent ;
	string strFileType ;
	string strFileTypeAppComment ;
	if ( iRv >= 0 )
	{
		strSrcFileContent.reserve( iLeftFileBytes )  ;
		strSrcFileContent.insert( 
			strSrcFileContent.begin() , 
			binLeftFile , 
			binLeftFile+iLeftFileBytes ) ;
		//	���s�R�[�h�� '\r\n' ���� '\n' �ɕϊ�
		strSrcFileContent = OuLib::strLfOf( strSrcFileContent ) ;
	}
	if ( iRv >= 0 )
	{
		CdConnectedString2	aCdConnectedString2( '\n' , '=' )  ;
		aCdConnectedString2.decode( strSrcFileContent ) ;
		strFileType = aCdConnectedString2.getValue( nameFileType );
		strFileTypeAppComment = aCdConnectedString2.getValue( nameFileTypeAppComment );
	}
	// ================================
	//	�����񂩂�H���t�@�C���f�[�^�ւ̕ϊ�
	// ================================
	CDedRosenFileData	aCDedRosenFileData ;
	// --------------------------------
	//	Ver.01 �� SrcFile ����H���t�@�C���f�[�^���쐬
	// --------------------------------
	if ( iRv >= 0 && !bFormatFound )
	{
		CconvCDedRosenFileData_01	aCconvCDedRosenFileData_01 ;
		if ( aCconvCDedRosenFileData_01.isEncodeAbleFormat( strSrcFileContent ) )
		{
			bFormatFound = true ;
			int iResult = aCconvCDedRosenFileData_01.CDedRosenFileData_from_string( 
				&aCDedRosenFileData , strSrcFileContent ) ;
			if ( iResult < 0 )
			{
				iRv = -1 ;	//	�ϊ��O�̃t�@�C���́A���̃R�}���h�ł̕ϊ����ł��܂���B
			}
		}
	}

	// --------------------------------
	//	Ver.02 �� SrcFile ����H���t�@�C���f�[�^���쐬
	// --------------------------------
	if ( iRv >= 0 && !bFormatFound )
	{

		CconvCDedRosenFileData_02	aCconvCDedRosenFileData_02 ;
		if ( aCconvCDedRosenFileData_02.getFileType() == strFileType )
		{
			bFormatFound = true ;
			CConnectedStringCompress	aCompress( '.' ) ;
			CdConnectedString2	aCdConnectedString2( '\n' , '=' )  ;
			aCompress.decode( strSrcFileContent , &aCdConnectedString2 ) ;

			int iResult = aCconvCDedRosenFileData_02.CDedRosenFileData_from_CdConnectedString( 
				&aCDedRosenFileData , aCdConnectedString2 ) ;
			if ( iResult < 0 )
			{
				iRv = -1 ;	//	�ϊ��O�̃t�@�C���́A���̃R�}���h�ł̕ϊ����ł��܂���B
			}
		}
	}
	// --------------------------------
	if ( iRv >= 0 && !bFormatFound )
	{
				iRv = -1 ;	//	�ϊ��O�̃t�@�C���́A���̃R�}���h�ł̕ϊ����ł��܂���B
	}
	// ================================
	//	�H���t�@�C���f�[�^���� Ver.3 �̃t�@�C�����쐬
	// ================================
	string strDstFile ;
	{
		CdConnectedString2	aCdConnectedString2( '\n' , '=' , false )  ;
		if ( iRv >= 0 )
		{
			CconvCDedRosenFileData	aCconvCDedRosenFileData ;

			//	CdConnectedString2 ��
			//	FileType �� FileTypeAppComment ��t�^
			aCdConnectedString2.setItem( nameFileType , CconvCDedRosenFileData().getFileType() );
			aCdConnectedString2.setItem( nameFileTypeAppComment , valueFileTypeAppComment );

			int iResult = aCconvCDedRosenFileData.CDedRosenFileData_to_CdConnectedString( 
				aCDedRosenFileData , &aCdConnectedString2 ) ;
			if ( iResult < 0 )
			{
				iRv = -3 ;	//	�ϊ���̃t�@�C���̍쐬�Ɏ��s���܂����B
			}
		}
		// --------------------------------
		//	CdConnectedString2 �̓��e��
		//	������Ɋi�[
		// --------------------------------
		if ( iRv >= 0 )
		{

			//	CConnectedStringCompress �ɂ�鈳�k
			CConnectedStringCompress	aCompress( '.' ) ;
			strDstFile = aCompress.encode( aCdConnectedString2 ) ;
			
		}
	}
	//strDstFile=�ϊ���̕�����

	// ================================
	//	��������ďo���ɕԂ��B
	// ================================
	if ( iRv >= 0 )
	{
		//	���s�R�[�h�� '\n' ���� '\r\n' �ɕϊ�
		strDstFile = OuLib::strCrlfOf( strDstFile ) ;

		if ( pbinRightFile != NULL )
		{
			*pbinRightFile = ConvFile_MemAlloc( strDstFile.size() ) ;
			memcpy( *pbinRightFile , strDstFile.c_str() , strDstFile.size() ) ;
		}
		if ( piRightFileBytes != NULL )
		{
			*piRightFileBytes = strDstFile.size() ;
		}
	}


	
	return ( iRv ) ;
}

CONVFILEOUDIA02TO03_API int ConvFile_isLeft(
	const CHAR* binLeftFile , 
	DWORD iLeftFileBytes ) 
{
	int iRv = 0 ;
	bool	bFormatFound = false ;

	// --------------------------------
	//	������ւ̕ϊ�
	// --------------------------------
	string 	strSrcFileContent ;
	string strFileType ;
	string strFileTypeAppComment ;
	if ( iRv >= 0 )
	{
		strSrcFileContent.reserve( iLeftFileBytes )  ;
		strSrcFileContent.insert( 
			strSrcFileContent.begin() , 
			binLeftFile , 
			binLeftFile+iLeftFileBytes ) ;
		//	���s�R�[�h�� '\r\n' ���� '\n' �ɕϊ�
		strSrcFileContent = OuLib::strLfOf( strSrcFileContent ) ;
	}
	if ( iRv >= 0 )
	{
		CdConnectedString2	aCdConnectedString2( '\n' , '=' )  ;
		aCdConnectedString2.decode( strSrcFileContent ) ;
		strFileType = aCdConnectedString2.getValue( nameFileType );
		strFileTypeAppComment = aCdConnectedString2.getValue( nameFileTypeAppComment );
	}
	// ================================
	//	�����񂩂�H���t�@�C���f�[�^�ւ̕ϊ�
	// ================================
	CDedRosenFileData	aCDedRosenFileData ;
	// --------------------------------
	//	Ver.01 �� SrcFile ����H���t�@�C���f�[�^���쐬
	// --------------------------------
	if ( iRv >= 0 && !bFormatFound )
	{
		CconvCDedRosenFileData_01	aCconvCDedRosenFileData_01 ;
		if ( aCconvCDedRosenFileData_01.isEncodeAbleFormat( strSrcFileContent ) )
		{
			bFormatFound = true ;
		}
	}

	// --------------------------------
	//	Ver.02 �� SrcFile ����H���t�@�C���f�[�^���쐬
	// --------------------------------
	if ( iRv >= 0 && !bFormatFound )
	{

		CconvCDedRosenFileData_02	aCconvCDedRosenFileData_02 ;
		if ( aCconvCDedRosenFileData_02.getFileType() == strFileType )
		{
			bFormatFound = true ;
		}

	}
	// --------------------------------
	if ( iRv >= 0 && !bFormatFound )
	{
				iRv = -1 ;	//	�ϊ��O�̃t�@�C���́A���̃R�}���h�ł̕ϊ����ł��܂���B
	}
	return ( iRv ) ;
}

CONVFILEOUDIA02TO03_API void ConvFile_MemFree(
	CHAR* binMem ) 
{
	delete[] binMem ;
}

#endif
