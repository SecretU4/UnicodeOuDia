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
//	vectorToFile.cpp
// ****************************************************************
//【概要】
//	vector<char> の内容をファイルへ書き出し
//	ファイルの内容の vector<char> への読み込み
//	を行う下請関数です。
*/
#include "vectorToFile.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <windows.h>
#include <algorithm>
#include "strToWstr.h"

namespace OuLib{
namespace Str{

// ****************************************************************

int vectorToFile( const std::vector<char>& aVector , 
					const std::string& strFilename ) 
{
	int	iRv = 0 ;
	if ( strFilename.empty() )
	{
		iRv = -1 ;	//	ファイルオープンエラー
	}
	if ( iRv >= 0 )
	
	{
		FILE*	pFile = fopen( strFilename.c_str() , "wb" ) ;
		
		if ( pFile != NULL ){
			if ( !aVector.empty() )
			{
				size_t iWrittenBytes = fwrite( &aVector[0] , 1 ,
					aVector.size() , pFile ) ;
				if ( iWrittenBytes != aVector.size() ){
					iRv = -2 ;	//	書き込みに失敗しました。
				}
			}
			if ( fclose( pFile ) != 0 ){
				if ( iRv >= 0 ){
					iRv = -2 ;	//	書き込みに失敗しました。
				}
			}
		}	else	{
			iRv = -1 ;	//	ファイルオープンエラー
		}
	}
	return ( iRv ) ;
}


int vectorFromFile( std::vector<char>* pVector , 
					const std::string& strFilename ) 
{
	int	iRv = 0 ;
	
	if ( strFilename.empty() )
	{
		iRv = -1 ;	//	ファイルオープンエラー
	}
	
	
	if ( iRv >= 0 ){
		pVector->clear() ;
	}
	if ( iRv >= 0 ){
		
		
		FILE*	pFile = fopen( strFilename.c_str() , "rb" ) ;
		
		if ( pFile != NULL ){
			char	szLs[1024] ;
			int	iReadBytes = 0 ;
			do{
				iReadBytes = fread( szLs , 1 , sizeof(szLs) , pFile ) ;
				if ( iReadBytes > 0 ){
					pVector->insert( pVector->end() , szLs , 
													szLs + iReadBytes ) ;
				}	else if ( iReadBytes < 0 ){
					iRv = -2 ;	//	読み込みに失敗しました。
				}
			}	while ( iReadBytes > 0 && iRv >= 0 ) ;
			if ( fclose( pFile ) != 0 ){
				if ( iRv >= 0 ){
					iRv = -2 ;	//	読み込みに失敗しました。
				}
			}
		}	else	{
			iRv = -1 ;	//	ファイルオープンエラー
		}

	}
	return ( iRv ) ;
}



int stringToFile( const std::string& aString , 
					const std::string& strFilename ) 
{
	int	iRv = 0 ;
	if ( strFilename.empty() )
	{
		iRv = -1 ;	//	ファイルオープンエラー
	}
	if ( iRv >= 0 ){
		FILE*	pFile = fopen( strFilename.c_str() , "wb" ) ;
		
		if ( pFile != NULL ){
			int	iReadBytes = 0 ;
			iReadBytes = fwrite( aString.c_str() , 1 , 
								aString.size() , pFile ) ;
			if ( iReadBytes != aString.size() ){
				iRv = -2 ;	//	書き込みに失敗しました。
			}
			if ( fclose( pFile ) != 0 ){
				if ( iRv >= 0 ){
					iRv = -2 ;	//	書き込みに失敗しました。
				}
			}
		}	else	{
			iRv = -1 ;	//	ファイルオープンエラー
		}
	}
	return ( iRv ) ;
}



int stringFromFile( std::string* pString , 
					const std::string& strFilename ) 
{
	int	iRv = 0 ;
	
	if ( strFilename.empty() )
	{
		iRv = -1 ;	//	ファイルオープンエラー
	}

	
	if ( iRv >= 0 ){
		pString->erase() ;
	}
	// --------------------------------
	//	ファイルサイズを先読みして、
	//	string にメモリ確保
	// --------------------------------
	if ( iRv >= 0 ){
		long lSize = 0 ;
		struct _stat aStat ;
		if ( _stat( strFilename.c_str() , &aStat ) == 0 ){
			lSize = aStat.st_size ;
			if ( lSize > 0 ){
				pString->reserve( lSize ) ;
			}
		}

		
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		
		
		FILE*	pFile = fopen( strFilename.c_str() , "rb" ) ;
		
		if ( pFile != NULL ){
			char	szLs[1024] ;
			size_t iReadBytes = 0 ;
			do{
				iReadBytes = fread( szLs , 1 , sizeof(szLs) , pFile ) ;
				if ( iReadBytes > 0 ){
					if ( std::find( szLs , szLs + iReadBytes , '\0' )
						!= szLs + iReadBytes ){
						iRv = -3 ;	//	ファイルには'\0' が含まれます。
					}	else	{
						pString->append( szLs , iReadBytes ) ;
					}
				}
			}	while ( iReadBytes > 0 && iRv >= 0 ) ;
			if ( ferror( pFile ) != 0 && iRv >= 0 ){
				iRv = -2 ;	//	読み込みに失敗しました。
			}
			if ( fclose( pFile ) != 0 ){
				if ( iRv >= 0 ){
					iRv = -2 ;	//	読み込みに失敗しました。
				}
			}
		}	else	{
			iRv = -1 ;	//	ファイルオープンエラー
		}

	}
	return ( iRv ) ;
}


/*
 * UTF-8 text-file boundary helpers.
 * New files are UTF-8 with BOM. Existing files without a UTF-8 BOM are
 * interpreted as legacy Windows Japanese code page 932.
 */
int stringToFile( const std::string& aString ,
	const std::wstring& strFilename )
{
	if ( strFilename.empty() ) return -1 ;
	FILE* pFile = _wfopen( strFilename.c_str() , L"wb" ) ;
	if ( pFile == NULL ) return -1 ;
	int iRv = 0 ;
	if ( !aString.empty() &&
		fwrite( aString.data() , 1 , aString.size() , pFile ) != aString.size() )
		iRv = -2 ;
	if ( fclose( pFile ) != 0 && iRv >= 0 ) iRv = -2 ;
	return iRv ;
}

int stringFromFile( std::string* pString ,
	const std::wstring& strFilename )
{
	if ( pString == NULL || strFilename.empty() ) return -1 ;
	FILE* pFile = _wfopen( strFilename.c_str() , L"rb" ) ;
	if ( pFile == NULL ) return -1 ;
	pString->clear() ;
	char buffer[4096] ;
	size_t count = 0 ;
	while ( ( count = fread( buffer , 1 , sizeof(buffer) , pFile ) ) > 0 )
		pString->append( buffer , count ) ;
	const bool readError = ferror( pFile ) != 0 ;
	const bool closeError = fclose( pFile ) != 0 ;
	return ( readError || closeError ) ? -2 : 0 ;
}

int stringToFileUtf8( const std::string& aString ,
	const std::wstring& strFilename )
{
	std::wstring validated ;
	if ( !wstringFromUtf8( aString , &validated ) ) return -3 ;
	if ( strFilename.empty() ) return -1 ;
	FILE* pFile = _wfopen( strFilename.c_str() , L"wb" ) ;
	if ( pFile == NULL ) return -1 ;
	int iRv = 0 ;
	const unsigned char bom[3] = { 0xef , 0xbb , 0xbf } ;
	if ( fwrite( bom , 1 , 3 , pFile ) != 3 ) iRv = -2 ;
	if ( iRv >= 0 && !aString.empty() &&
		fwrite( aString.data() , 1 , aString.size() , pFile ) != aString.size() )
		iRv = -2 ;
	if ( fclose( pFile ) != 0 && iRv >= 0 ) iRv = -2 ;
	return iRv ;
}

int stringFromFileUtf8( std::string* pString ,
	const std::wstring& strFilename )
{
	if ( pString == NULL || strFilename.empty() ) return -1 ;
	FILE* pFile = _wfopen( strFilename.c_str() , L"rb" ) ;
	if ( pFile == NULL ) return -1 ;
	std::vector<char> bytes ;
	char buffer[4096] ;
	size_t count = 0 ;
	while ( ( count = fread( buffer , 1 , sizeof(buffer) , pFile ) ) > 0 )
		bytes.insert( bytes.end() , buffer , buffer + count ) ;
	const bool readError = ferror( pFile ) != 0 ;
	const bool closeError = fclose( pFile ) != 0 ;
	if ( readError || closeError ) return -2 ;
	if ( std::find( bytes.begin() , bytes.end() , '\0' ) != bytes.end() )
		return -3 ;
	std::string raw ;
	if ( !bytes.empty() ) raw.assign( &bytes[0] , bytes.size() ) ;
	const bool hasUtf8Bom = raw.size() >= 3 &&
		(unsigned char)raw[0] == 0xef &&
		(unsigned char)raw[1] == 0xbb &&
		(unsigned char)raw[2] == 0xbf ;
	if ( hasUtf8Bom ) raw.erase( 0 , 3 ) ;
	std::wstring wide ;
	if ( hasUtf8Bom && wstringFromUtf8( raw , &wide ) )
	{
		*pString = raw ;
		return 0 ;
	}
	if ( hasUtf8Bom ) return -3 ;
	if ( raw.empty() )
	{
		pString->clear() ;
		return 0 ;
	}
	if ( raw.size() > 0x7fffffff ) return -3 ;
	int cch = MultiByteToWideChar( 932 , 0 , raw.data() ,
		(int)raw.size() , NULL , 0 ) ;
	if ( cch <= 0 ) return -3 ;
	std::vector<wchar_t> legacy( cch ) ;
	if ( MultiByteToWideChar( 932 , 0 , raw.data() , (int)raw.size() ,
		&legacy[0] , cch ) != cch ) return -3 ;
	wide.assign( &legacy[0] , cch ) ;
	if ( wide.find( (wchar_t)0xfffd ) != std::wstring::npos ) return -3 ;
	return utf8Of( wide , pString ) ? 0 : -3 ;
}



} //namespace Str{
} //namespace OuLib{
