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
// CConvFileDll.cpp: CConvFileDll クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CConvFileDll.h"

namespace ConvFile{

using namespace std ;

	// ********************************
	//	コンストラクタ・デストラクタ
	// ********************************
CConvFileDll::CConvFileDll( const string&	strDllFilename )
	: m_strDllFilename( strDllFilename ) 
	, m_hModule( NULL ) 
	, ConvFile2Dll_getIfConvFile( NULL )
{

}

CConvFileDll::~CConvFileDll()
{
	invalidate() ;
}
	// ********************************
	//@name IfValidate
	// ********************************
	///@{
	/**
	 * 	　オブジェクトの準備処理を行い、有効化します。
	 * 	　準備処理にあたって必要なパラメータは、コンストラクタなどで
	 * 	指定している
	 * 	必要があります。
	 * @return
	 * 	　有効化に成功したら１以上、
	 * 	　すでに有効化が終了していた場合は０、
	 * 	　エラーの場合は負の数を返します。\n
	 * 	　成功したときの１以上の値の意味は、実装するクラスが自由に定義
	 * 	できます。\n
	 * 	　失敗したときの負の数の意味も、実装クラスが定義できます。これにより、
	 * 	失敗の理由ごとに異なるエラー値を返すことができます。
	 *	-	-1 ;	//	DLLがロードできません。
	 * 	
	 */
int CConvFileDll::validate() 
{
	if ( isValid() )
	{
		return ( 0 ) ;
	}
	// --------------------------------
	int iRv = 1 ;
	if ( iRv >= 0 )
	{
		m_hModule = LoadLibrary( m_strDllFilename.c_str() ) ;
		if ( m_hModule == NULL )
		{
			iRv = -1 ;	//	DLLがロードできません。
		}
	}
	if ( iRv >= 0 )
	{
		ConvFile2Dll_getIfConvFile = 
			(ConvFile2Dll_getIfConvFile_FUNCPTR)GetProcAddress( m_hModule , ConvFile2Dll_getIfConvFile_FUNCNAME ) ;
	}
	return ( iRv ) ;
}
	
	/**
	 * 	　オブジェクトを無効化します。
	 * 	　有効化時に確保したリソースを開放します。
	 * 	  有効状態でないオブジェクトに対しては、なにもしません。
	 */
void CConvFileDll::invalidate() 
{
	if ( m_hModule != NULL )
	{
		ConvFile2Dll_getIfConvFile = NULL ;
		FreeLibrary( m_hModule ) ;
		m_hModule = NULL ;
	}
}
	
	/**
	 * @return
	 * 	　現在オブジェクトが有効状態であれば真を返します。
	 */
bool CConvFileDll::isValid() 
{
	return ( m_hModule != NULL ) ;
}
	
	// ********************************
	///@name	CConvFile2Dll
	// ********************************
IfConvFile* CConvFileDll::getIfConvFile() 
{
	return (IfConvFile*)ConvFile2Dll_getIfConvFile() ;
}
} //namespace ConvFile
