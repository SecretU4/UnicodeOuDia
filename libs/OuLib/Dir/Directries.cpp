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


(訳: 

	OuDia - 列車時刻表をもとに、ダイヤグラムを描画するWin32アプリケーシ
ョン。

Copyright (C) 2006-2017 take-okm 

このプログラムはフリーソフトウェアです。あなたはこれを、フリーソフトウェア財
団によって発行されたGNU 一般公衆利用許諾書(バージョン3か、それ以降のバージョ
ンのうちどれか)が定める条件の下で再頒布または改変 することができます。

このプログラムは有用であることを願って頒布されますが、*全くの無保証 *です。
商業可能性の保証や特定目的への適合性は、言外に示されたものも 含め、全く存在
しません。詳しくはGNU 一般公衆利用許諾書をご覧ください。

あなたはこのプログラムと共に、GNU 一般公衆利用許諾書のコピーを一部 受け取っ
ているはずです。もし受け取っていなければ、<http://www.gnu.org/licenses/> を
ご覧ください。

)

  加えて、特別な例外として、take-okm はこのプログラムのコードを 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  あるいは "MFC Version 9.0" と同じライセンスが適用された
  "MFC Version 9.0" の改変されたバージョン)とリンクし、
  リンクされた両者を含む結合著作物を頒布する許可を与えます。
  あなたは "MFC" 以外で使われているすべて
  のコードに関しては全面的にGNU一般公衆利用許諾契約書に従わなければ
  なりません。あなたがこのファイルを改変したならば、あなたはこの例外
  をあなたのバージョンのファイルに引き続き設けることもできますが、そ
  うする義務はありません。もし例外を設けたくなければ、この例外条項を
  あなたのバージョンからは削除してください。)
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
	//例：
	//strSearch="c:\tiny\u*"
	//	最後のファイル名部分は、ワイルドカードの場合もあります。

	int iRv = 0 ;

	CdFilenameStr	fnSearch( strSearch , false ) ;
	//fnSearch = 検索パス文字列です。
	//例："c:\tiny\u*"
	
	// 	　strSearch の末尾に "." ( カレントディレクトリ ) , ".." (親ディレクトリ) を
	//	指定することはできません。この場合は、 -1 を返します。
	if ( fnSearch.DirCount() >= 1 )
	{
		if ( fnSearch.DirAt( fnSearch.DirCount() - 1 ) == "." 
			|| fnSearch.DirAt( fnSearch.DirCount() - 1 ) == ".." )
		{
			iRv = -1 ;	//	パラメータが不正です\n
			//			strSearch の末尾に "."  , ".." を指定することはできません。
		}
	}


	// --------------------------------
	//	指定のディレクトリ内の
	//	ディレクトリを検索
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
						
						//fnFind=みつかったディレクトリ名に、パスを
						//	付与しました。
						//例："c:\tiny\ufo" 
						
						pIfDirCallback->OnNameFound( fnFind ) ;
						iRv ++ ;
					}
				}
			}	while ( FindNextFile( aHandle , &aWin32FindData ) ) ;
			FindClose( aHandle ) ;
		}
	}
	// --------------------------------
	//	サブディレクトリ内の
	//	ディレクトリを検索
	// --------------------------------
	if ( iRv >= 0 && bSubdirectrySearch )
	{
		CdFilenameStr	fnSearchSubdir = fnSearch ;
		fnSearchSubdir.delDirLast().addDirLast( "*" ) ;
		//fnSearchSubdir = サブディレクトリを検索する文字列です。
		//例："c:\tiny\*"
		
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
					
						//fnFind=みつかったディレクトリ名を、末尾の１つ前の
						//	パスに
						//	付与しました。
						//例："c:\tiny\ufo\u*" 
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
	//例：
	//strSearch="c:\tiny\u*"
	//	最後のファイル名部分は、ワイルドカードの場合もあります。


	int iRv = 0 ;

	CdFilenameStr	fnSearch( strSearch , true ) ;
	//fnSearch = 検索パス文字列です。
	//例："c:\tiny\u*"
	
	// --------------------------------
	//	指定のディレクトリ内の
	//	ファイルを検索
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
						
						//fnFind=みつかったディレクトリ名に、パスを
						//	付与しました。
						//例："c:\tiny\ufo" 
						
						pIfDirCallback->OnNameFound( fnFind ) ;
						iRv ++ ;

				}
			}	while ( FindNextFile( aHandle , &aWin32FindData ) ) ;
			FindClose( aHandle ) ;
		}
	}
	// --------------------------------
	//	サブディレクトリ内の
	//	ディレクトリを検索
	// --------------------------------
	if ( bSubdirectrySearch ){
		CdFilenameStr	fnSearchSubdir( fnSearch ) ;
		fnSearchSubdir.setIsValidFilename( false ).addDirLast( "*" ) ;
		//fnSearchSubdir = サブディレクトリを検索する文字列です。
		//例："c:\tiny\*"
		
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
					
						//fnFind=みつかったディレクトリ名を、
						//	末尾の１つ前のパスに
						//	付与しました。
						//例："c:\tiny\ufo\u*" 
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
//@name ディレクトリ作成
// ****************************************************************
int mkdirs( const std::string& strDir ) 
{
	int iRv = 0 ;
	CdFilenameStr	aCdFilenameStr( strDir , false ) ;
	//fnSearch = 検索パス文字列です。
	//例："c:\tiny\u*"

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
			//	ディレクトリが見つかりませんでした。
			int iResult = _mkdir( strDirCurr.c_str() ) ;
			if ( iResult != 0 )
			{
				iRv = -1 ;	//	ディレクトリの作成に失敗しました。
			}
			else
			{
				iRv = 1 ;	//	ディレクトリの作成に成功しました。
			}
			_findclose( fHandle ) ;
		}
	}

	return ( iRv ) ;
}



int rmempdir( const std::string& strDir , FILE* pErrorStream ) 
{ 
	//	処理が成功している間は0以上、エラーなら負の数となります 
	int iRv = 0 ; 

	if ( pErrorStream != NULL )
	{
		fprintf( pErrorStream , "rmempdir(%s)\n" , strDir.c_str() ) ; 
	}

	// -------------------------------- 
	//	strDir のサブディレクトリの削除を試行 
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
								iRv = -3 ;	//	サブディレクトリの削除に失敗しました。 
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
				    //	普通のファイルが見つかりました。 
				    //	このディレクトリは削除できません。 
					if ( iRv >= 0 ) 
				    { 
						if ( pErrorStream != NULL )
						{
							fprintf( pErrorStream , "\tこのディレクトリにはファイルがあります。(%s)\n" , 
								c_file.name ) ; 
						}
						iRv = -2 ;	//	このディレクトリにはファイルがあります。 
					} 
			   } 
		   } while( _findnext( hFile, &c_file ) == 0 ); 
		  _findclose( hFile ); 
	   } 
	} 
	// -------------------------------- 
	//	strDir が空なら、このディレクトリの削除を試行 
	// -------------------------------- 
	if ( iRv >= 0 ) 
	{ 
		if ( _rmdir( strDir.c_str() )!= 0 ) 
		{ 
			if ( pErrorStream != NULL )
			{
				fprintf( pErrorStream , "\tディレクトリ %s の削除に失敗しました。\n" , 
					strDir.c_str() ) ; 
			}
			iRv = -1 ;	//	strDirの削除に失敗しました。 
		} 
		else 
		{ 
			if ( pErrorStream != NULL )
			{
				fprintf( pErrorStream , "\tディレクトリ %s を削除\n" , 
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
