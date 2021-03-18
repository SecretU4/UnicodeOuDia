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
//	CconvCDedRosenFileData.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include "NsOu\OuNew.h"
#include "NsOu\dynamic_castOu.h"
#include "str\CdConnectedString2.h"
#include "str\strToInt.h"
#include "str\CConnectedStringCompress.h"
#include "str\OuPropertiesText\CConvNodeContainer.h"
#include "str\OuPropertiesText\CDirectory.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfoContainer.h"
#include "logmsg\LogMsg.h"

#include "CconvCdDedDispProp.h"
#include "CconvCDedRosenFileData.h"
#include "..\entDed\CconvCentDed.h"


/*delete 遅いので抑止
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
*/

namespace DedRosenFileData{
	using namespace std ;
	using namespace OuLib::NsOu ;
	using namespace OuLib::Str::OuPropertiesText;
	using namespace OuLib::Str::OuPropertiesText::ErrorInfo;
// ****************************************************************
//	CconvCDedRosenFileData
// ****************************************************************
const char nameFileType[]="FileType" ;
const char nameRosen[]="Rosen" ;
const char nameDispProp[]="DispProp" ;

int CconvCDedRosenFileData::CDedRosenFileData_to_OuPropertiesText( 
			const CDedRosenFileData* pCDedRosenFileData , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) 
{
	LogMsg( "CDedRosenFileData_to_CdConnectedString()" ) ;
	int iRv = 0 ;

	//	FileType
	if ( iRv >= 0 )
	{
		pCNodeContainer->setValue( nameFileType , getFileType() ) ;

	}
	//1.Rosen
	if ( iRv >= 0 ){
		Ou<CDirectory> pCDirectory = OuNew<CDirectory>( 
			new CDirectory( nameRosen ) ) ;
		CconvCentDed aConv ;
		int iResult = aConv.CentDedRosen_To_OuPropertiesText( 
			pCDedRosenFileData->getCentDedRosen() ,
			pCDirectory->getCNodeContainer() ) ;
		//	-	-22 ;	//	Ekijikokukeisiki の値が不正です。
		//	-	-32 ;	//	Ekikibo の値が不正です。
		//	-	-111 ;	//	Syubetsumei が指定されていません。
		//	-	-152 ;	//	DiagramSenStyle の値が不正です。
		//	-	-212 ;	//	DiagramEkiatsukai の値が不正です。
		if ( iResult < 0 )
		{
			//	-	-22 ;	//	Ekijikokukeisiki の値が不正です。
			//	-	-32 ;	//	Ekikibo の値が不正です。
			//	-	-111 ;	//	Syubetsumei が指定されていません。
			//	-	-152 ;	//	DiagramSenStyle の値が不正です。
			//	-	-212 ;	//	DiagramEkiatsukai の値が不正です。
			iRv = iResult ;
		}
		else
		{
			pCNodeContainer->insert( pCDirectory ) ;
		}
	}
	//2.DispProp
	LogMsg( "CDedRosenFileData_to_CdConnectedString()1" ) ;
	if ( iRv >= 0 )
	{
		Ou<CDirectory> pCDirectory = OuNew<CDirectory>( 
			new CDirectory( nameDispProp ) ) ;
		CconvCdDedDispProp	aCconvCdDedDispProp ;
		int iResult = aCconvCdDedDispProp.toOuPropertiesText( 
			pCDedRosenFileData->getCdDedDispProp() ,
			pCDirectory->getCNodeContainer() ) ;
		//	現在は負の数が返されることはありません。
		if ( iResult < 0 )
		{
			assert( false ) ;
		}
		else
		{
			pCNodeContainer->insert( pCDirectory ) ;
		}
	}


	LogMsg( "CDedRosenFileData_to_CdConnectedString()=%d" , iRv ) ;
	return ( iRv ) ;
}

int CconvCDedRosenFileData::CDedRosenFileData_from_OuPropertiesText( 
			CDedRosenFileData* pCDedRosenFileData ,
			const OuPropertiesText::CNodeContainer* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) 
{
	int iRv = 0 ;
	COuErrorInfoContainer	aCOuErrorInfoContainer ;
	if ( pCOuErrorInfoContainer == NULL )
	{
		pCOuErrorInfoContainer = &aCOuErrorInfoContainer ;
	}
	// --------------------------------

	if ( iRv >= 0 )
	{
		int iResult = isEncodeAbleFormat( pCNodeContainer ) ;
		if ( iResult < 0 )
		{
			COuErrorInfo aCOuErrorInfo( ERRREASON_FileTypeIsInvalid() ) ;
			aCOuErrorInfo.getProp()->setValue( 
				ERRPROP_FileType() , pCNodeContainer->getValue( nameFileType ) ) ;
			pCOuErrorInfoContainer->insert( aCOuErrorInfo ) ;
			iRv = -1 ;	//	FileType が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		pCDedRosenFileData->clear() ;
	}
	
	//1.Rosen

	if ( iRv >= 0 )
	{
		Ou<const CDirectory> pCDirectory = dynamic_castOu<const CDirectory>( 
			pCNodeContainer->getInName( nameRosen , 0 ) ) ;
		if ( pCDirectory == NULL )
		{
			COuErrorInfo aCOuErrorInfo( ERRREASON_RosenDirectoryIsNotFound() ) ;
			pCOuErrorInfoContainer->insert( aCOuErrorInfo ) ;
			iRv = -2 ;	//	Rosen Directoryが見つかりません。
		}
		else
		{
			CentDedRosen	aCentDedRosen ;
			CconvCentDed aCconvCentDed ;
			int iResult = aCconvCentDed.CentDedRosen_From_OuPropertiesText( 
				&aCentDedRosen ,
				pCDirectory->getIfNodeContainerConst() ,
				pCOuErrorInfoContainer ) ;
			//-	-22 ;	//	Ekijikokukeisiki の値が不正です。
			//-	-32 ;	//	Ekikibo の値が不正です。
			//-	-41 ;	//	DiagramRessyajouhouHyoujiKudari の値が不正です。
			//-	-42 ;	//	DiagramRessyajouhouHyoujiNobori の値が不正です。
			//-	-101 ;	//	Eki がディレクトリではありません。
			//-	-111 ;	//	Syubetsumei が指定されていません。
			//-	-152 ;	//	DiagramSenStyle の値が不正です。
			//-	-201 ;	//	Ressyasyubetsu がディレクトリではありません。
			//-	-211 ;	//	DiaName が指定されていません。
			//-	-212 ;	//	RessyaContが見つかりません。
			//-	-352 ;	//	起点時刻の設定が不適切です。
			if ( iResult < 0 )
			{
				//-	-22 ;	//	Ekijikokukeisiki の値が不正です。
				//-	-32 ;	//	Ekikibo の値が不正です。
				//-	-41 ;	//	DiagramRessyajouhouHyoujiKudari の値が不正です。
				//-	-42 ;	//	DiagramRessyajouhouHyoujiNobori の値が不正です。
				//-	-101 ;	//	Eki がディレクトリではありません。
				//-	-111 ;	//	Syubetsumei が指定されていません。
				//-	-152 ;	//	DiagramSenStyle の値が不正です。
				//-	-201 ;	//	Ressyasyubetsu がディレクトリではありません。
				//-	-211 ;	//	DiaName が指定されていません。
				//-	-212 ;	//	RessyaContが見つかりません。
				//-	-352 ;	//	起点時刻の設定が不適切です。
				iRv = iResult ;
			}
			else
			{
				*pCDedRosenFileData->getCentDedRosen() = aCentDedRosen ;
			}
		}
	}
	//2.DispProp
	if ( iRv >= 0 )
	{
		Ou<const CDirectory> pCDirectory = dynamic_castOu<const CDirectory>( 
			pCNodeContainer->getInName( nameDispProp , 0 ) ) ;
		if ( pCDirectory == NULL )
		{
			COuErrorInfo aCOuErrorInfo( ERRREASON_DispPropnDirectoryIsNotFound() ) ;
			pCOuErrorInfoContainer->insert( aCOuErrorInfo ) ;
			iRv = -3 ;	//	DispProp Directoryが見つかりません。
		}
		else
		{
			CconvCdDedDispProp	aCconvCdDedDispProp ;
			CdDedDispProp	aCdDedDispProp ;
			int iResult = aCconvCdDedDispProp.fromOuPropertiesText( 
				&aCdDedDispProp ,
				pCDirectory->getIfNodeContainerConst() , 
				pCOuErrorInfoContainer ) ;
			//-	-12 ;	//	JikokuhyouFont の内容が不正です。
			//-	-22 ;	//	DiaEkimeiFont の内容が不正です。
			//-	-32 ;	//	DiaJikokuFont の内容が不正です。
			//-	-82 ;	//	DisplayRessyabangou が不正です。
			//-	-92 ;	//	DisplayRessyamei が不正です。
			//-	-102 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari が不正です。
			//-	-112 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori が不正です。
			if ( iResult < 0 )
			{
				//-	-512 ;	//	JikokuhyouFont の内容が不正です。
				//-	-522 ;	//	DiaEkimeiFont の内容が不正です。
				//-	-532 ;	//	DiaJikokuFont の内容が不正です。
				//-	-582 ;	//	DisplayRessyabangou が不正です。
				//-	-592 ;	//	DisplayRessyamei が不正です。
				//-	-602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari が不正です。
				//-	-612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori が不正です。
				iRv = -500 ;	//	DispProp の内容が不正
			}
			else
			{
				pCDedRosenFileData->setCdDedDispProp( aCdDedDispProp ) ;
			}
		}
	}
	return ( iRv ) ;
}

int CconvCDedRosenFileData::isEncodeAbleFormat( 
			const OuPropertiesText::CNodeContainer* pCNodeContainer ) 
{
	int iRv = 0 ;
	string strFileType = pCNodeContainer->getValue( nameFileType ) ;
	if ( strFileType != getFileType() )
	{
		iRv = -1 ;	//	FileType が正しくありません。
	}
	return iRv ;
}

int CconvCDedRosenFileData::CDedRosenFileData_to_string( 
		const CDedRosenFileData& aCDedRosenFileData , 
		string* pString ) 
{
	LogMsg( "CDedRosenFileData_to_string()" ) ;

	int iRv = 0 ;
	string	strRv ;
	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		int iResult = CDedRosenFileData_to_OuPropertiesText( 
			&aCDedRosenFileData , 
			&aCNodeContainer ) ;
		//iResult = 
		//-	-22 ;	//	Ekijikokukeisiki の値が不正です。
		//-	-32 ;	//	Ekikibo の値が不正です。
		//-	-111 ;	//	Syubetsumei が指定されていません。
		//-	-152 ;	//	DiagramSenStyle の値が不正です。
		//-	-212 ;	//	DiagramEkiatsukai の値が不正です。
		if ( iResult < 0 )
		{
			iRv = iResult ;
		}
	}
	
	LogMsg( "CDedRosenFileData_to_string()1" ) ;

	if ( iRv >= 0 )
	{
		CConvNodeContainer	aConv  ;
		strRv = aConv.encode( &aCNodeContainer ) ;
	}

	if ( iRv >= 0 )
	{
		if ( pString != NULL ){
			*pString = strRv ;
		}
	}

	LogMsg( "CDedRosenFileData_to_string()=%d" , iRv ) ;
	return ( iRv ) ;
}


int CconvCDedRosenFileData::CDedRosenFileData_from_string( 
			CDedRosenFileData* pCDedRosenFileData ,
			const string& aString ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) 
{
	LogMsg( "CDedRosenFileData_from_string()" ) ;

	int iRv = 0 ;
	string	strRv ;

	LogMsg( "CDedRosenFileData_from_string()1" ) ;

	pCDedRosenFileData->clear() ;
	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		string strErrorInfostring ;
		CConvNodeContainer	aConv ;
		int iResult = aConv.decode( aString , &aCNodeContainer , &strErrorInfostring ) ;
		//	-	-1 ;	//	ディレクトリが途中で閉じています。
		if ( iResult < 0 )
		{
			iRv = -1 ;	//	ディレクトリが途中で閉じています。	
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = CDedRosenFileData_from_OuPropertiesText( 
			pCDedRosenFileData , 
			&aCNodeContainer , 
			pCOuErrorInfoContainer ) ;
		//iResult = 
		//-	-1 ;	//	FileType が正しくありません。
		//-	-2 ;	//	Rosen Directoryが見つかりません。
		//-	-22 ;	//	Ekijikokukeisiki の値が不正です。
		//-	-32 ;	//	Ekikibo の値が不正です。
		//-	-41 ;	//	DiagramRessyajouhouHyoujiKudari の値が不正です。
		//-	-42 ;	//	DiagramRessyajouhouHyoujiNobori の値が不正です。
		//-	-101 ;	//	Eki がディレクトリではありません。
		//-	-111 ;	//	Syubetsumei が指定されていません。
		//-	-152 ;	//	DiagramSenStyle の値が不正です。
		//-	-201 ;	//	Ressyasyubetsu がディレクトリではありません。
		//-	-211 ;	//	DiaName が指定されていません。
		//-	-212 ;	//	RessyaContが見つかりません。
		//-	-352 ;	//	起点時刻の設定が不適切です。
		//-	-3 ;	//	DispProp Directoryが見つかりません。
		//-	-512 ;	//	JikokuhyouFont の内容が不正です。
		//-	-522 ;	//	DiaEkimeiFont の内容が不正です。
		//-	-532 ;	//	DiaJikokuFont の内容が不正です。
		//-	-582 ;	//	DisplayRessyabangou が不正です。
		//-	-592 ;	//	DisplayRessyamei が不正です。
		//-	-602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari が不正です。
		//-	-612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori が不正です。
		if ( iResult < 0 )
		{
			//-	-1001 ;	//	FileType が正しくありません。
			//-	-1002 ;	//	Rosen Directoryが見つかりません。
			//-	-1022 ;	//	Ekijikokukeisiki の値が不正です。
			//-	-1032 ;	//	Ekikibo の値が不正です。
			//-	-1041 ;	//	DiagramRessyajouhouHyoujiKudari の値が不正です。
			//-	-1042 ;	//	DiagramRessyajouhouHyoujiNobori の値が不正です。
			//-	-1101 ;	//	Eki がディレクトリではありません。
			//-	-1111 ;	//	Syubetsumei が指定されていません。
			//-	-1152 ;	//	DiagramSenStyle の値が不正です。
			//-	-1201 ;	//	Ressyasyubetsu がディレクトリではありません。
			//-	-1211 ;	//	DiaName が指定されていません。
			//-	-1212 ;	//	RessyaContが見つかりません。
			//-	-1352 ;	//	起点時刻の設定が不適切です。
			//-	-1003 ;	//	DispProp Directoryが見つかりません。
			//-	-1512 ;	//	JikokuhyouFont の内容が不正です。
			//-	-1522 ;	//	DiaEkimeiFont の内容が不正です。
			//-	-1532 ;	//	DiaJikokuFont の内容が不正です。
			//-	-1582 ;	//	DisplayRessyabangou が不正です。
			//-	-1592 ;	//	DisplayRessyamei が不正です。
			//-	-1602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari が不正です。
			//-	-1612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori が不正です。
			iRv = iResult - 1000 ;
		}
	}
	LogMsg( "CDedRosenFileData_from_string()=%d" , iRv ) ;
	return ( iRv ) ;
}

int CconvCDedRosenFileData::isEncodeAbleFormat( 
			const string& strOudFile  ) 
{
	LogMsg( "isEncodeAbleFormat()" ) ;

	int iRv = 0 ;
	string	strRv ;

	LogMsg( "CDedRosenFileData_from_string()1" ) ;

	CNodeContainer aCNodeContainer ;
	if ( iRv >= 0 )
	{
		string strErrorInfostring ;
		CConvNodeContainer	aConv ;
		int iResult = aConv.decode( strOudFile , &aCNodeContainer , &strErrorInfostring ) ;
		//	-	-1 ;	//	ディレクトリが途中で閉じています。
		if ( iResult < 0 )
		{
			iRv = -1 ;	//	ディレクトリが途中で閉じています。	
		}
	}
	if ( iRv >= 0 )
	{
		int iResult = isEncodeAbleFormat( &aCNodeContainer ) ;
		//-	-1 ;	//	FileType が正しくありません。
		if ( iResult < 0 )
		{
			//-	-1001 ;	//	FileType が正しくありません。
			iRv = iResult -1000 ;	//	FileType が正しくありません。
		}
	}

	return ( iRv ) ;

}

} //namespace DedRosenFileData

