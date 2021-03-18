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
namespace OuLib {

// ****************************************************************


//	ファイルに、aVector に格納されているデータを書き込みます。
//	Win32の場合は、バイナリモードでの書き込みとなります。
//[in]aVector
//	この関数は、この配列の内容をファイルに書き込みます。
//[in]strFilename
//	書き込み先のファイル名を指定してください。
//	関数実行前にファイルが存在している場合は、既存の内容を破棄します。
//[retval]
//	0:成功
//	負の数はエラーです。
//	-1:	ファイルがオープンできません。
//	-2 ;	//	書き込みに失敗しました。
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
			int	iReadBytes = 0 ;
			iReadBytes = fwrite( &aVector.front() , 1 , 
								aVector.size() , pFile ) ;
			if ( iReadBytes != aVector.size() ){
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



//	ファイルの内容を、pVector に格納します。
//	Win32の場合は、バイナリモードでの読み込みとなります。
//[out]pVector
//	この関数は、この配列に、ファイルの内容を書き込みます。
//	配列にすでにデータがある場合は、既存の内容を破棄します。
//[in]strFilename
//	読み込むファイル名を指定してください。
//[retval]
//	0:成功
//	負の数はエラーです。
//	-1:	ファイルがオープンできません。
//	-2 ;	//	読み込みに失敗しました。
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





//	ファイルに、aString に格納されているデータを書き込みます。
//	Win32の場合は、テキストモードでの書き込みとなります。
//[in]aString
//	この関数は、この文字列の内容をファイルに書き込みます。
//[in]strFilename
//	書き込み先のファイル名を指定してください。
//	関数実行前にファイルが存在している場合は、既存の内容を破棄します。
//[retval]
//	0:成功
//	負の数はエラーです。
//	-1:	ファイルがオープンできません。
//	-2 ;	//	書き込みに失敗しました。
int stringToFile( const std::string& aString , 
					const std::string& strFilename ) 
{
	int	iRv = 0 ;
	if ( strFilename.empty() )
	{
		iRv = -1 ;	//	ファイルオープンエラー
	}
	if ( iRv >= 0 ){
		FILE*	pFile = fopen( strFilename.c_str() , "wt" ) ;
		
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



//	ファイルの内容を、pVector に格納します。
//	Win32の場合は、バイナリモードでの読み込みとなります。
//[out]pVector
//	この関数は、この配列に、ファイルの内容を書き込みます。
//	配列にすでにデータがある場合は、既存の内容を破棄します。
//[in]strFilename
//	読み込むファイル名を指定してください。
//[retval]
//	0:成功
//	負の数はエラーです。
//	-1:	ファイルがオープンできません。
//	-2 ;	//	読み込みに失敗しました。
//	-3 ;	//	ファイルには'\0' が含まれます。
#include <sys/types.h>
#include <sys/stat.h>

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
		
		
		FILE*	pFile = fopen( strFilename.c_str() , "rt" ) ;
		
		if ( pFile != NULL ){
			char	szLs[1024+1] ;
			int	iReadBytes = 0 ;
			do{
				iReadBytes = fread( szLs , 1 , sizeof(szLs) - 1 , pFile ) ;
				if ( iReadBytes > 0 ){
					szLs[iReadBytes] = '\0' ;
					int idx ;
					for ( idx = 0 ; szLs[idx] != '\0' ; idx ++ ){} ;
					if ( idx != iReadBytes ){
						iRv = -3 ;	//	ファイルには'\0' が含まれます。
					}	else	{
						*pString += szLs ;
					}
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




};
