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
/**
@file
@brief
  ConvFileDll を起動して、ファイルの変換を行うコマンドラインツールです。
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
"	指定の ConvFileDll を使って、左側のファイルを右側のファイルに変換します。" "\n"
"@param ConvFileDllFilename" "\n"
"	ConvFileDll のファイル名を指定してください。" "\n"
"@param LeftFilename" "\n"
"	左側(変換元)のファイル名を指定してください。" "\n"
"@param RightFilename" "\n"
"	このコマンドは、変換結果をこのファイル名で保存します。" "\n"
;

/**
@return
	-	0 ;	//	成功
	-	1 ;	//	フォーマットが正しくありません。
	-	101 ;	//	DLLがみつかりません。
	-	11 ;	//	LeftFile が読み込めません。
	-	21 ;	//	RightFile に書き込めません。
*/
int main(int argc, char* argv[])
{
	int iRv = 0 ;
	string	strError ;
	// --------------------------------
	//	引数の解釈
	// --------------------------------
	string	strDllFilename ;
	string	strLeftFilename ;
	string	strRightFilename ;
	if ( iRv >= 0 )
	{
		if ( argc != 4 )
		{
			strError = g_szUsage ;
			iRv = -201 ;	//	パラメータが不正です。
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
	//	DLLのロード
	// --------------------------------
	CConvFileDll	aCConvFileDll( strDllFilename ) ;
	if ( iRv >= 0 )
	{
		int iResult = aCConvFileDll.validate() ;
		if ( iResult < 0 )
		{
			strError = "DLLがみつかりません。" ;
			iRv = -101 ;	//	DLLがみつかりません。
		}
	}
	// --------------------------------
	//	LeftFile の読み込み
	// --------------------------------
	vector<char>	binLeftFile ;
	if ( iRv >= 0 )
	{
		FILE*	pFile = fopen( strLeftFilename.c_str() , "rb" ) ;
		if ( pFile == NULL )
		{
			strError = "LeftFile が読み込めません。" ;
			iRv = -11 ;	//	LeftFile が読み込めません。
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
	//	LeftFile のフォーマットの検証
	// --------------------------------
	if ( iRv >= 0 )
	{
		CaByteBuffer_vector< vector<char> >	aBytebufferLeftFile( &binLeftFile ) ;
		int iResult = aCConvFileDll.getIfConvFile()->isLeftFormat( &aBytebufferLeftFile ) ;
		if ( iResult < 0 )
		{
			strError = "フォーマットが正しくありません。" ;
			iRv = -1 ;	//	フォーマットが正しくありません。
		}
	}
	// --------------------------------
	//	LeftFileをRightFileに変換
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
			strError = "フォーマットが正しくありません。" ;
			iRv = -1 ;	//	フォーマットが正しくありません。
		}
	}
	// --------------------------------
	//	RightFileを書き込み
	// --------------------------------
	if ( iRv >= 0 )
	{
		FILE* pFile = fopen( strRightFilename.c_str() , "wb" ) ;
		if ( pFile == NULL )
		{
			iRv = -21 ;	//	RightFile に書き込めません。
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
					strError = "RightFile に書き込めません。" ;
					iRv = -21 ;	//	RightFile に書き込めません。
				}
			}
			if ( fclose( pFile ) != 0 )
			{
				strError = "RightFile に書き込めません。" ;
				iRv = -21 ;	//	RightFile に書き込めません。
			}
		}
	}
	// --------------------------------
	//	RightFileを書き込み
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
