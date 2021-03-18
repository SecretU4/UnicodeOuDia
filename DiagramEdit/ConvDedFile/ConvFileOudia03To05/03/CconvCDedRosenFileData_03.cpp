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
			iRv = -11 ;	//	Rosen の内容が不正
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
			iRv = -21 ;	//	DispProp の内容が不正
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
			iRv = -1 ;	//	FileType が正しくありません。
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
			iRv = -11 ;	//	Rosen の内容が不正
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
			iRv = -21 ;	//	DispProp の内容が不正
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
		iRv = -1 ;	//	FileType が正しくありません。
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
		//	-11 ;	//	Rosen の内容が不正
		//	-21 ;	//	DispProp の内容が不正
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
		//	-	-1 ;	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。
		if ( iResult < 0 )
		{
			iRv = -101 ;	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。	
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = CDedRosenFileData_from_CdConnectedString( 
			pCDedRosenFileData , aCdConnectedString ) ;
		//iResult = 
		//		-	-1 ;	//	FileType が正しくありません。
		//		-	-11 ;	//	Rosen の内容が不正
		//		-	-21 ;	//	DispProp の内容が不正
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
		//	-	-1 ;	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。
		if ( iResult < 0 )
		{
			iRv = -101 ;	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。	
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = isEncodeAbleFormat( aCdConnectedString ) ;
		//-	0 ;	//	解釈可能です。
		//-	-1 ;	//	FileType が正しくありません。
		if ( iResult < 0 )
		{
			iRv = iResult ;
		}
	}
	return ( iRv ) ;

}


