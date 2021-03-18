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
/**
@file
@brief
  ConvFileDll ���N�����āA�t�@�C���̕ϊ����s���R�}���h���C���c�[���ł��B
*/

#include "stdafx.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std ;

#include "CConvFileDll.h"
#include "CaByteBuffer_vector.h"


const char g_szUsage[]=
"ConvFileExec ConvFileDllFilename LeftFilename RightFilename" "\n"
"	�w��� ConvFileDll ���g���āA�����̃t�@�C�����E���̃t�@�C���ɕϊ����܂��B" "\n"
"@param ConvFileDllFilename" "\n"
"	ConvFileDll �̃t�@�C�������w�肵�Ă��������B" "\n"
"@param LeftFilename" "\n"
"	����(�ϊ���)�̃t�@�C�������w�肵�Ă��������B" "\n"
"@param RightFilename" "\n"
"	���̃R�}���h�́A�ϊ����ʂ����̃t�@�C�����ŕۑ����܂��B" "\n"
;

/**
@return
	-	0 ;	//	����
	-	1 ;	//	�t�H�[�}�b�g������������܂���B
	-	101 ;	//	DLL���݂���܂���B
	-	11 ;	//	LeftFile ���ǂݍ��߂܂���B
	-	21 ;	//	RightFile �ɏ������߂܂���B
*/
int main(int argc, char* argv[])
{
	int iRv = 0 ;
	string	strError ;
	// --------------------------------
	//	�����̉���
	// --------------------------------
	string	strDllFilename ;
	string	strLeftFilename ;
	string	strRightFilename ;
	if ( iRv >= 0 )
	{
		if ( argc != 4 )
		{
			strError = g_szUsage ;
			iRv = -201 ;	//	�p�����[�^���s���ł��B
			fprintf( stderr , g_szUsage ) ;
			return ( iRv ) ;
		}
		else
		{
			strDllFilename = argv[1] ;
			strLeftFilename = argv[2] ;
			strRightFilename = argv[3] ;
		}
	}
	// --------------------------------
	//	DLL�̃��[�h
	// --------------------------------
	CConvFileDll	aCConvFileDll( strDllFilename ) ;
	if ( iRv >= 0 )
	{
		int iResult = aCConvFileDll.validate() ;
		if ( iResult < 0 )
		{
			strError = "DLL���݂���܂���B" ;
			iRv = -101 ;	//	DLL���݂���܂���B
		}
	}
	// --------------------------------
	//	LeftFile �̓ǂݍ���
	// --------------------------------
	vector<char>	binLeftFile ;
	if ( iRv >= 0 )
	{
		FILE*	pFile = fopen( strLeftFilename.c_str() , "rb" ) ;
		if ( pFile == NULL )
		{
			strError = "LeftFile ���ǂݍ��߂܂���B" ;
			iRv = -11 ;	//	LeftFile ���ǂݍ��߂܂���B
		}
		else
		{
			struct	stat	aStat ;
			if ( stat( strLeftFilename.c_str() , &aStat ) == 0 )
			{
				binLeftFile.reserve( aStat.st_size ) ;
			}
			int iChar ;
			while( ( iChar = fgetc( pFile ) ) != EOF )
			{
				binLeftFile.push_back( iChar ) ;
			}
			fclose( pFile ) ;
		}
	}
	// --------------------------------
	//	LeftFile �̃t�H�[�}�b�g�̌���
	// --------------------------------
	if ( iRv >= 0 )
	{
		CaByteBuffer_vector< vector<char> >	aBytebufferLeftFile( &binLeftFile ) ;
		int iResult = aCConvFileDll.getIfConvFile()->isLeftFormat( &aBytebufferLeftFile ) ;
		if ( iResult < 0 )
		{
			strError = "�t�H�[�}�b�g������������܂���B" ;
			iRv = -1 ;	//	�t�H�[�}�b�g������������܂���B
		}
	}
	// --------------------------------
	//	LeftFile��RightFile�ɕϊ�
	// --------------------------------
	vector<char>	binRightFile ;
	if ( iRv >= 0 )
	{
		CaByteBuffer_vector< vector<char> >	aBytebufferLeftFile( &binLeftFile ) ;
		CaByteBuffer_vector< vector<char> >	aBytebufferRightFile( &binRightFile ) ;
		int iResult = aCConvFileDll.getIfConvFile()->LeftToRight( 
			&aBytebufferLeftFile , 
			&aBytebufferRightFile , 
			NULL ) ;
		if ( iResult < 0 )
		{
			strError = "�t�H�[�}�b�g������������܂���B" ;
			iRv = -1 ;	//	�t�H�[�}�b�g������������܂���B
		}
	}
	// --------------------------------
	//	RightFile����������
	// --------------------------------
	if ( iRv >= 0 )
	{
		FILE* pFile = fopen( strRightFilename.c_str() , "wb" ) ;
		if ( pFile == NULL )
		{
			iRv = -21 ;	//	RightFile �ɏ������߂܂���B
		}
		else
		{
			size_t	idxRightFile ;
			for ( idxRightFile = 0 ; 
				iRv >= 0 && idxRightFile < binRightFile.size() ;
				idxRightFile ++ )
			{
				if ( fputc( binRightFile[idxRightFile] , pFile ) == EOF )
				{
					strError = "RightFile �ɏ������߂܂���B" ;
					iRv = -21 ;	//	RightFile �ɏ������߂܂���B
				}
			}
			if ( fclose( pFile ) != 0 )
			{
				strError = "RightFile �ɏ������߂܂���B" ;
				iRv = -21 ;	//	RightFile �ɏ������߂܂���B
			}
		}
	}
	// --------------------------------
	//	RightFile����������
	// --------------------------------
	if ( iRv < 0 )
	{
		if ( strError.empty() )
		{
			fprintf( stderr , "Error %d\n" , iRv ) ;
		}
		else
		{
			fprintf( stderr , "%s\n" , strError.c_str() ) ;
		}
	}
	return -iRv;
}
