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
//	dir\Directries.cpp
// ****************************************************************
*/

#include "Directries.h"
#include "str\strToWstr.h"
#include "str\tstring.h"
#include "str\CdFilenameStr.h"
#include <windows.h>
#include <io.h>
#include <direct.h>
using namespace std ;

namespace OuLib{
using namespace Str ;
namespace Dir{

int findDir( const string& strSearch , 
						bool bSubdirectrySearch ,
						IfDirCallback* pIfDirCallback ) 
{
	//��F
	//strSearch="c:\tiny\u*"
	//	�Ō�̃t�@�C���������́A���C���h�J�[�h�̏ꍇ������܂��B

	int iRv = 0 ;

	CdFilenameStr	fnSearch( strSearch , false ) ;
	//fnSearch = �����p�X������ł��B
	//��F"c:\tiny\u*"
	
	// 	�@strSearch �̖����� "." ( �J�����g�f�B���N�g�� ) , ".." (�e�f�B���N�g��) ��
	//	�w�肷�邱�Ƃ͂ł��܂���B���̏ꍇ�́A -1 ��Ԃ��܂��B
	if ( fnSearch.DirCount() >= 1 )
	{
		if ( fnSearch.DirAt( fnSearch.DirCount() - 1 ) == "." 
			|| fnSearch.DirAt( fnSearch.DirCount() - 1 ) == ".." )
		{
			iRv = -1 ;	//	�p�����[�^���s���ł�\n
			//			strSearch �̖����� "."  , ".." ���w�肷�邱�Ƃ͂ł��܂���B
		}
	}


	// --------------------------------
	//	�w��̃f�B���N�g������
	//	�f�B���N�g��������
	// --------------------------------
	if ( iRv >= 0 )
	{
		tstring	tstrSearch = tstringOf( fnSearch ) ;
		WIN32_FIND_DATA	aWin32FindData ;
		HANDLE	aHandle = FindFirstFile( tstrSearch.c_str() , 
										&aWin32FindData ) ;
		if ( aHandle != INVALID_HANDLE_VALUE ){
			do{
				if ( aWin32FindData.dwFileAttributes & 
											FILE_ATTRIBUTE_DIRECTORY ){
					tstring	strName = aWin32FindData.cFileName ;
					if ( strName != TEXT( "." ) && strName != TEXT( ".." ) ){
						CdFilenameStr	fnFind( fnSearch ) ;
						fnFind.delDirLast().addDirLast( stringOf( strName ) ) ;
						
						//fnFind=�݂������f�B���N�g�����ɁA�p�X��
						//	�t�^���܂����B
						//��F"c:\tiny\ufo" 
						
						pIfDirCallback->OnNameFound( fnFind ) ;
						iRv ++ ;
					}
				}
			}	while ( FindNextFile( aHandle , &aWin32FindData ) ) ;
			FindClose( aHandle ) ;
		}
	}
	// --------------------------------
	//	�T�u�f�B���N�g������
	//	�f�B���N�g��������
	// --------------------------------
	if ( iRv >= 0 && bSubdirectrySearch )
	{
		CdFilenameStr	fnSearchSubdir = fnSearch ;
		fnSearchSubdir.delDirLast().addDirLast( "*" ) ;
		//fnSearchSubdir = �T�u�f�B���N�g�����������镶����ł��B
		//��F"c:\tiny\*"
		
		tstring	tstrSearchSubdir = tstringOf( fnSearchSubdir ) ;
		
		WIN32_FIND_DATA	aWin32FindData ;
		HANDLE	aHandle = FindFirstFile( tstrSearchSubdir.c_str()  
										, &aWin32FindData ) ;
		if ( aHandle != INVALID_HANDLE_VALUE ){
			do{
				if ( aWin32FindData.dwFileAttributes & 
											FILE_ATTRIBUTE_DIRECTORY ){
					tstring	strName = aWin32FindData.cFileName ;
					if ( strName != TEXT( "." ) && strName != TEXT( ".." ) ){
						CdFilenameStr	fnFind = fnSearch ;
						fnFind.addDirAt( fnFind.DirCount() - 1 , 
											stringOf( strName ) ) ;
					
						//fnFind=�݂������f�B���N�g�������A�����̂P�O��
						//	�p�X��
						//	�t�^���܂����B
						//��F"c:\tiny\ufo\u*" 
						string	strFind = stringOf( fnFind );
						
						iRv += findDir( strFind , bSubdirectrySearch , 
							pIfDirCallback ) ;
					}
				}
			}	while ( FindNextFile( aHandle , &aWin32FindData ) ) ;
			FindClose( aHandle ) ;
		}
	}

	return ( iRv ) ;
}

int findFile( const string& strSearch , 
						bool bSubdirectrySearch ,
						IfDirCallback* pIfDirCallback ) 
{
	//��F
	//strSearch="c:\tiny\u*"
	//	�Ō�̃t�@�C���������́A���C���h�J�[�h�̏ꍇ������܂��B


	int iRv = 0 ;

	CdFilenameStr	fnSearch( strSearch , true ) ;
	//fnSearch = �����p�X������ł��B
	//��F"c:\tiny\u*"
	
	// --------------------------------
	//	�w��̃f�B���N�g������
	//	�t�@�C��������
	// --------------------------------
	{
		tstring	tstrSearch = tstringOf( fnSearch ) ;
		WIN32_FIND_DATA	aWin32FindData ;
		HANDLE	aHandle = FindFirstFile( tstrSearch.c_str() , 
										&aWin32FindData ) ;
		if ( aHandle != INVALID_HANDLE_VALUE ){
			do{
				if ( !( aWin32FindData.dwFileAttributes & 
											FILE_ATTRIBUTE_DIRECTORY ) ){
					tstring	strName = aWin32FindData.cFileName ;

						CdFilenameStr	fnFind( fnSearch ) ;
						fnFind.setFilename( stringOf( strName ) ) ;
						
						//fnFind=�݂������f�B���N�g�����ɁA�p�X��
						//	�t�^���܂����B
						//��F"c:\tiny\ufo" 
						
						pIfDirCallback->OnNameFound( fnFind ) ;
						iRv ++ ;

				}
			}	while ( FindNextFile( aHandle , &aWin32FindData ) ) ;
			FindClose( aHandle ) ;
		}
	}
	// --------------------------------
	//	�T�u�f�B���N�g������
	//	�f�B���N�g��������
	// --------------------------------
	if ( bSubdirectrySearch ){
		CdFilenameStr	fnSearchSubdir( fnSearch ) ;
		fnSearchSubdir.setIsValidFilename( false ).addDirLast( "*" ) ;
		//fnSearchSubdir = �T�u�f�B���N�g�����������镶����ł��B
		//��F"c:\tiny\*"
		
		tstring	tstrSearchSubdir = tstringOf( fnSearchSubdir ) ;
		
		WIN32_FIND_DATA	aWin32FindData ;
		HANDLE	aHandle = FindFirstFile( tstrSearchSubdir.c_str()  
										, &aWin32FindData ) ;
		if ( aHandle != INVALID_HANDLE_VALUE ){
			do{
				if (  aWin32FindData.dwFileAttributes & 
											FILE_ATTRIBUTE_DIRECTORY ){
					tstring	strName = aWin32FindData.cFileName ;
					if ( strName != TEXT( "." ) && strName != TEXT( ".." ) ){

						CdFilenameStr	fnFind = fnSearch ;
						fnFind.addDirLast( stringOf( strName ) ) ;
					
						//fnFind=�݂������f�B���N�g�������A
						//	�����̂P�O�̃p�X��
						//	�t�^���܂����B
						//��F"c:\tiny\ufo\u*" 
						string	strFind = stringOf( fnFind );

						iRv += findFile( 
							strFind , bSubdirectrySearch ,
							pIfDirCallback ) ;
					}
				}
			}	while ( FindNextFile( aHandle , &aWin32FindData ) ) ;
			FindClose( aHandle ) ;
		}
	}


	return ( iRv ) ;
}
// ****************************************************************
//@name �f�B���N�g���쐬
// ****************************************************************
int mkdirs( const std::string& strDir ) 
{
	int iRv = 0 ;
	CdFilenameStr	aCdFilenameStr( strDir , false ) ;
	//fnSearch = �����p�X������ł��B
	//��F"c:\tiny\u*"

	CdFilenameStr	aCdFilenameStrCurr = aCdFilenameStr ;
	aCdFilenameStrCurr.setDirs( CdFilenameStr::ContstrDir() ) ;

	for ( int iDirCount = 1 ; 
		iRv >= 0 && iDirCount <= aCdFilenameStr.DirCount() ;  
		iDirCount ++ )
	{
		aCdFilenameStrCurr.addDirLast( aCdFilenameStr.DirAt( iDirCount - 1 ) ) ;
		std::string strDirCurr = aCdFilenameStrCurr.FullpathFilename() ;


		struct _finddata_t aFinddata ;
		intptr_t fHandle = _findfirst(
			strDirCurr.c_str() , 
			&aFinddata ) ;
		if ( fHandle == -1 )
		{
			//	�f�B���N�g����������܂���ł����B
			int iResult = _mkdir( strDirCurr.c_str() ) ;
			if ( iResult != 0 )
			{
				iRv = -1 ;	//	�f�B���N�g���̍쐬�Ɏ��s���܂����B
			}
			else
			{
				iRv = 1 ;	//	�f�B���N�g���̍쐬�ɐ������܂����B
			}
			_findclose( fHandle ) ;
		}
	}

	return ( iRv ) ;
}



int rmempdir( const std::string& strDir , FILE* pErrorStream ) 
{ 
	//	�������������Ă���Ԃ�0�ȏ�A�G���[�Ȃ畉�̐��ƂȂ�܂� 
	int iRv = 0 ; 

	if ( pErrorStream != NULL )
	{
		fprintf( pErrorStream , "rmempdir(%s)\n" , strDir.c_str() ) ; 
	}

	// -------------------------------- 
	//	strDir �̃T�u�f�B���N�g���̍폜�����s 
	// -------------------------------- 
	if ( iRv >= 0 ) 
	{ 
	   struct _finddata_t c_file; 
	   intptr_t hFile; 

	   // Find first .c file in current directory 
	   if( (hFile = _findfirst( ( strDir + "\\*" ).c_str() , 
		   &c_file )) == -1L ) 
	   { 
	   } 
	   else 
	   { 
		   do { 
			   if ( c_file.attrib & _A_SUBDIR ) 
			   { 
				   string strFound = c_file.name ; 
				   if ( strFound != "." && strFound != ".." ) 
				   { 
					    int iResult = rmempdir( strDir + "\\" + strFound , pErrorStream ) ; 
						if ( iRv >= 0 ) 
					    { 
							if ( iResult == -1 ) 
							{ 
								iRv = -3 ;	//	�T�u�f�B���N�g���̍폜�Ɏ��s���܂����B 
							} 
							else 
							{ 
								iRv = iResult ; 
							} 
					    } 
				   } 
			   } 
			   else 
			   { 
				    //	���ʂ̃t�@�C����������܂����B 
				    //	���̃f�B���N�g���͍폜�ł��܂���B 
					if ( iRv >= 0 ) 
				    { 
						if ( pErrorStream != NULL )
						{
							fprintf( pErrorStream , "\t���̃f�B���N�g���ɂ̓t�@�C��������܂��B(%s)\n" , 
								c_file.name ) ; 
						}
						iRv = -2 ;	//	���̃f�B���N�g���ɂ̓t�@�C��������܂��B 
					} 
			   } 
		   } while( _findnext( hFile, &c_file ) == 0 ); 
		  _findclose( hFile ); 
	   } 
	} 
	// -------------------------------- 
	//	strDir ����Ȃ�A���̃f�B���N�g���̍폜�����s 
	// -------------------------------- 
	if ( iRv >= 0 ) 
	{ 
		if ( _rmdir( strDir.c_str() )!= 0 ) 
		{ 
			if ( pErrorStream != NULL )
			{
				fprintf( pErrorStream , "\t�f�B���N�g�� %s �̍폜�Ɏ��s���܂����B\n" , 
					strDir.c_str() ) ; 
			}
			iRv = -1 ;	//	strDir�̍폜�Ɏ��s���܂����B 
		} 
		else 
		{ 
			if ( pErrorStream != NULL )
			{
				fprintf( pErrorStream , "\t�f�B���N�g�� %s ���폜\n" , 
					strDir.c_str()  ) ; 
			}
		} 
	} 

	if ( pErrorStream != NULL )
	{
		fprintf( pErrorStream , "rmempdir(%s)=%d\n" , strDir.c_str() , iRv ) ; 
	}
	return ( iRv ) ; 
} 


} //namespace Dir{
} //namespace OuLib{
