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
// CaConvFile_Oudia02To03.cpp: CaConvFile_Oudia02To03 クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <string>
using std::string ;

#include "str\strLf.h"
#include "str\CdConnectedString2.h"
#include "str\CConnectedStringCompress.h"

#include "CaConvFile_Oudia02To03.h"
#include "CDedRosenFileData.h"
#include "CconvCDedRosenFileData_01.h"
#include "CconvCDedRosenFileData_02.h"
#include "CDedRosenFileData.h"
#include "CconvCDedRosenFileData.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////
static const char nameFileType[] = "FileType" ;
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia02To03 Ver 0.03" ;

CaConvFile_Oudia02To03::CaConvFile_Oudia02To03()
{

}

CaConvFile_Oudia02To03::~CaConvFile_Oudia02To03()
{

}

	// ********************************
	//@name IfConvFile
	// ********************************
int CaConvFile_Oudia02To03::LeftToRight( 
		const IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pRightFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	int iRv = 0 ;
	bool	bFormatFound = false ;
	string 	strErrorInfoString ;

	// --------------------------------
	//	文字列への変換
	// --------------------------------
	string 	strSrcFileContent ;
	string strFileType ;
	string strFileTypeAppComment ;
	if ( iRv >= 0 )
	{
		strSrcFileContent.resize( pLeftFormat->size() )  ;
		for ( int idxBytes = 0 ; idxBytes < pLeftFormat->size() ; idxBytes ++ )
		{
			pLeftFormat->read( 
				&strSrcFileContent[idxBytes],
				idxBytes , 
				1 ) ;
		}
		
		//	改行コードは '\r\n' から '\n' に変換
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
	//	文字列から路線ファイルデータへの変換
	// ================================
	CDedRosenFileData	aCDedRosenFileData ;
	// --------------------------------
	//	Ver.01 の SrcFile から路線ファイルデータを作成
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
				iRv = -1 ;	//	変換前のファイルは、このコマンドでの変換ができません。
			}
		}
	}

	// --------------------------------
	//	Ver.02 の SrcFile から路線ファイルデータを作成
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
				iRv = -1 ;	//	変換前のファイルは、このコマンドでの変換ができません。
			}
		}
	}
	// --------------------------------
	if ( iRv >= 0 && !bFormatFound )
	{
				iRv = -1 ;	//	変換前のファイルは、このコマンドでの変換ができません。
	}
	// ================================
	//	路線ファイルデータから Ver.3 のファイルを作成
	// ================================
	string strDstFile ;
	{
		CdConnectedString2	aCdConnectedString2( '\n' , '=' , false )  ;
		if ( iRv >= 0 )
		{
			CconvCDedRosenFileData	aCconvCDedRosenFileData ;

			//	CdConnectedString2 に
			//	FileType と FileTypeAppComment を付与
			aCdConnectedString2.setItem( nameFileType , CconvCDedRosenFileData().getFileType() );
			aCdConnectedString2.setItem( nameFileTypeAppComment , valueFileTypeAppComment );

			int iResult = aCconvCDedRosenFileData.CDedRosenFileData_to_CdConnectedString( 
				aCDedRosenFileData , &aCdConnectedString2 ) ;
			if ( iResult < 0 )
			{
				iRv = -3 ;	//	変換後のファイルの作成に失敗しました。
			}
		}
		// --------------------------------
		//	CdConnectedString2 の内容を
		//	文字列に格納
		// --------------------------------
		if ( iRv >= 0 )
		{

			//	CConnectedStringCompress による圧縮
			CConnectedStringCompress	aCompress( '.' ) ;
			strDstFile = aCompress.encode( aCdConnectedString2 ) ;
			
		}
	}
	//strDstFile=変換後の文字列

	// ================================
	//	文字列を呼出元に返す。
	// ================================
	if ( iRv >= 0 )
	{
		//	改行コードは '\n' から '\r\n' に変換
		strDstFile = OuLib::strCrlfOf( strDstFile ) ;

		pRightFormat->size_reset( strDstFile.size() ) ;
		pRightFormat->write( strDstFile.c_str() , 0 , strDstFile.size() ) ;
	
	}
	if ( pErrorInfoString != NULL && strErrorInfoString.size() > 0 )
	{
		pErrorInfoString->size_reset( strErrorInfoString.size() ) ;
		pErrorInfoString->write( strErrorInfoString.c_str() , 0 , strErrorInfoString.size() ) ;
	}
	// --------------------------------
	return iRv ;
}

int CaConvFile_Oudia02To03::isLeftFormat( 
		const IfByteBuffer* pLeftFormat)  
{
	int iRv = 0 ;
	bool	bFormatFound = false ;

	// --------------------------------
	//	文字列への変換
	// --------------------------------
	string 	strSrcFileContent ;
	string strFileType ;
	string strFileTypeAppComment ;
	if ( iRv >= 0 )
	{
		strSrcFileContent.resize( pLeftFormat->size() )  ;
		for ( int idxBytes = 0 ; idxBytes < pLeftFormat->size() ; idxBytes ++ )
		{
			pLeftFormat->read( 
				&strSrcFileContent[idxBytes],
				idxBytes , 
				1 ) ;
		}
		
		//	改行コードは '\r\n' から '\n' に変換
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
	//	文字列から路線ファイルデータへの変換
	// ================================
	CDedRosenFileData	aCDedRosenFileData ;
	// --------------------------------
	//	Ver.01 の SrcFile から路線ファイルデータを作成
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
	//	Ver.02 の SrcFile から路線ファイルデータを作成
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
				iRv = -1 ;	//	変換前のファイルは、このコマンドでの変換ができません。
	}
	return ( iRv ) ;
}
bool CaConvFile_Oudia02To03::RightToLeftIsSupported() 
{
	return false ;	//	このメソッドはサポートされていません。
}
int CaConvFile_Oudia02To03::RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
}

int CaConvFile_Oudia02To03::isRightFormat( 
		const IfByteBuffer* pRightFormat ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
}
