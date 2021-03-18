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
// ****************************************************************
// $Id: CconvJikokuhyouCsv.cpp 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
#include "stdafx.h"
#include "CconvJikokuhyouCsv.h"
#include "str\strprintf.h"
#include "..\ViewJikokuhyou\JikokuhyouColSpec\CdYColSpecCont.h"

namespace ConvJikokuhyouCsv{

using namespace std ;
using namespace OuLib ;
using namespace OuLib::Str ;

using ViewJikokuhyou::JikokuhyouColSpec::CdYColSpecCont;
using ViewJikokuhyou::JikokuhyouColSpec::CdYColSpec;

/**
	FileTypeの 名前
*/
const char* const nameFileType = "FileType" ;

/**
	FileType の値
*/
const char* const nameFileTypeValue = "OuDia.JikokuhyouCsv.1" ;

const int CSVROWINDEX_Ressyabangou = 4 ;
const int CSVROWINDEX_Ressyasyubetsu = 5 ;
const int CSVROWINDEX_Ressyamei = 6 ;
const int CSVROWINDEX_Gousuu = 7 ;
const int CSVROWINDEX_Gou = 8 ;
const int CSVROWINDEX_Ekijikoku0 = 9 ;
const int CSVCOLUMNINDEX_Ressya0 = 2 ;

/** 時刻の書式を保持します。 */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	true ,		//	NoColon 
	// 時が 00 から 09 の場合、10の位の "0" を削除します。
	CdDedJikoku::CConv::EHour_ZeroToNone ,	
	CdDedJikoku::CConv::ESecond_NoSecond 	// 秒を常に出力しません。 
	) ;

	// --------------------------------
	//@name	駅時刻セルの文字列の解釈
	// --------------------------------
string CconvJikokuhyouCsv::encode_Ekijikoku( 
		CentDedEkiJikoku::EEkiatsukai eEkiatsukai , 
		const CdDedJikoku& aCdDedJikoku ) 
{
	string strValue ;
			switch( eEkiatsukai )
			{
			case CentDedEkiJikoku::Ekiatsukai_None :
				{
				}
				break ;
			case CentDedEkiJikoku::Ekiatsukai_Teisya:
				{
					strValue = g_CdDedJikokuConv.encode( aCdDedJikoku ) ;
				}
				break ;
			case CentDedEkiJikoku::Ekiatsukai_Tsuuka:
				{
					if ( aCdDedJikoku.isNull() )
					{
						strValue = m_nameTsuuka ;
					}
					else
					{
						strValue = "" ;
						strValue += g_CdDedJikokuConv.encode( aCdDedJikoku ) ;
						strValue += "?" ;
						
					}
				}
				break ;
			case CentDedEkiJikoku::Ekiatsukai_Keiyunasi:
				{
					strValue = m_nameKeiyunasi ;
				}
				break ;
			}

	return strValue ;
}

int  CconvJikokuhyouCsv::decode_Ekijikoku( 
		CentDedEkiJikoku::EEkiatsukai* pEkiatsukai , 
		CdDedJikoku* pCdDedJikoku , 
		const string& strEkijikoku ) 
{
	int iRv = 0 ;
	CentDedEkiJikoku::EEkiatsukai eEkiatsukai 
		= CentDedEkiJikoku::Ekiatsukai_None ;
	CdDedJikoku aCdDedJikoku ;

	if ( strEkijikoku == "" )
	{
		//	運行なし
	}
	else if ( strEkijikoku == m_nameTsuuka )
	{
		//	通過
		eEkiatsukai = CentDedEkiJikoku::Ekiatsukai_Tsuuka ;
	}
	else if ( strEkijikoku == m_nameKeiyunasi )
	{
		//	経由なし
		eEkiatsukai = CentDedEkiJikoku::Ekiatsukai_Keiyunasi ;
	}
	else if ( strEkijikoku.size() >= 1 
		&& strEkijikoku[ strEkijikoku.size() - 1 ] == '?' )
	{
		//	通過時刻あり
		eEkiatsukai = CentDedEkiJikoku::Ekiatsukai_Tsuuka ;
		int iResult = aCdDedJikoku.decode( 
			strEkijikoku.substr( 0 , strEkijikoku.size() - 1 ) ) ;
		if ( iResult < 0 )
		{
			iRv = -1 ;	//	時刻の解釈に失敗しました。
		}
	}
	else 
	{
		//	停車・時刻
		eEkiatsukai = CentDedEkiJikoku::Ekiatsukai_Teisya ;
		int iResult = aCdDedJikoku.decode( strEkijikoku ) ;
		if ( iResult < 0 )
		{
			iRv = -1 ;	//	時刻の解釈に失敗しました。
		}
	}
	// --------------------------------
	if ( pEkiatsukai != NULL )
	{
		*pEkiatsukai = eEkiatsukai ;
	}
	if ( pCdDedJikoku != NULL )
	{
		*pCdDedJikoku = aCdDedJikoku ;
	}
	return iRv ;
}

	// --------------------------------
	//@name encode() の下請関数	
	// --------------------------------
void CconvJikokuhyouCsv::encode_createContJikokuOrderOfJjikokuhyouIndex( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou eRessyahoukou , 
		deque<CdDedJikokuOrder>*	pcontiJikokuOrderOfJikokuhyouIndex ) 
{
	CdYColSpecCont aCdYColSpecCont(
		pCentDedEkiCont , eRessyahoukou , false ) ;
	int iColumnCount = aCdYColSpecCont.getColumnNumber_Ekijikoku_end() - 
		aCdYColSpecCont.getColumnNumber_Ekijikoku_begin() ;
	for ( int iJikokuhyouIndex = 0 ; iJikokuhyouIndex < iColumnCount ; iJikokuhyouIndex ++ )
	{
		CdYColSpec	aCdYColSpec = 
			aCdYColSpecCont.ColumnNumberToSpec( 
				aCdYColSpecCont.getColumnNumber_Ekijikoku_begin() 
				+ iJikokuhyouIndex ) ;
		int iEkiOrder = aCdYColSpec.getEkiOrder() ;
		CdDedJikokuOrder::EEkiJikokuItem	aEEkijikokuItem = CdDedJikokuOrder::EkiJikokuItem_Chaku ;
		if ( aCdYColSpec.getColumnType() 
			== CdYColSpec::ColumnType_Ekijikoku_Hatsu )
		{
			aEEkijikokuItem = CdDedJikokuOrder::EkiJikokuItem_Hatsu ;
		}
		
		pcontiJikokuOrderOfJikokuhyouIndex->push_back( 
			CdDedJikokuOrder( iEkiOrder , aEEkijikokuItem ) ) ;
	}
}


int CconvJikokuhyouCsv::encode_AddRessya( 
		const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet , 
		const deque<CdDedJikokuOrder>&	contiJikokuOrderOfJikokuhyouIndex , 
		const CentDedRessya* pCentDedRessya , 
		CdCsvDocument* pCdCsvDocument ) 
{
	int iRv = 0 ;

	if ( iRv >= 0 )
	{
		if ( pCentDedRessya->isNull() )
		{
			iRv = -1 ;	//	pCentDedRessya は Null です。
		}
	}
	// --------------------------------
	const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedRessyasyubetsu 	= pCentDedRessyasyubetsuContGet
			->get( pCentDedRessya->getRessyasyubetsuIndex() ) ;
	}
	//pCentDedRessysyubetsu = 列車種別オブジェクト

	//＜2.5＞5行目 <列車番号>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ressyabangou ) ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedRessya->getRessyabangou() ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyabangou ) ;
	}

	//＜2.6＞6行目 <列車種別>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get(CSVROWINDEX_Ressyasyubetsu ) ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedRessyasyubetsu->getRyakusyou() ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyasyubetsu ) ;
	}

	//＜2.7＞7行目 <列車名>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ressyamei ) ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedRessya->getRessyamei() ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyamei ) ;
	}

	//＜2.8＞8行目 <号数>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Gousuu ) ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedRessya->getGousuu() ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Gousuu ) ;
	}
	//＜2.9＞9行目 <号表示>
	if ( iRv >= 0 )
	{
		string	strValue ;
		if ( !pCentDedRessya->getGousuu().empty() )
		{
			strValue = m_nameGou ;
		}
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Gou ) ;
		aRow.getCellCont()->insert( CdCsvCell( strValue ) ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Gou ) ;
	}

	//＜2.10＞10行目～ 駅時刻
	
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order> の法則を持ちます。
	//	要素の数は、時刻表の列数です。

	if ( iRv >= 0 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			CdDedJikokuOrder iJikokuOrder = contiJikokuOrderOfJikokuhyouIndex[iJikokuhyouIndex] ;
			int iEkiOrder = iJikokuOrder.getEkiOrder() ;
			int iHatsu = 0 ;
			if ( iJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
			{
				iHatsu = 1 ;
			}



			CentDedEkiJikoku aCentDedEkiJikoku 
				= pCentDedRessya->getCentDedEkiJikoku(iEkiOrder) ;
			CdDedJikoku aCdDedJikoku ;
			if ( iHatsu == 0 )
			{
				aCdDedJikoku = aCentDedEkiJikoku.getChakujikoku() ;
			}
			else
			{
				aCdDedJikoku = aCentDedEkiJikoku.getHatsujikoku() ;
			}

			string	strValue = encode_Ekijikoku( 
				aCentDedEkiJikoku.getEkiatsukai() , 
				aCdDedJikoku ) ;
			//strValue = 駅時刻を文字列化しました(通過記号などの場合もあります)


			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;
			aRow.getCellCont()->insert( CdCsvCell( strValue ) ) ;
			pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;

		}
	}
	//＜2.11＞[列1="備考" AND 列2=""]の列　備考列
	if ( iRv >= 0 )
	{
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size() ) ;
			aRow.getCellCont()->insert( CdCsvCell( pCentDedRessya->getBikou() ) ) ;
			pCdCsvDocument->getRowCont()->set( aRow , 
				CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size() ) ;
	}
	return iRv ;
}

int CconvJikokuhyouCsv::encode_AddRessyaNull( 
		const deque<CdDedJikokuOrder>&	contiJikokuOrderOfJikokuhyouIndex , 
		CdCsvDocument* pCdCsvDocument ) 
{
	int iRv = 0 ;
	// --------------------------------

	//＜2.5＞5行目 <列車番号>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ressyabangou ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyabangou ) ;
	}

	//＜2.6＞6行目 <列車種別>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get(CSVROWINDEX_Ressyasyubetsu ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyasyubetsu ) ;
	}

	//＜2.7＞7行目 <列車名>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ressyamei ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ressyamei ) ;
	}

	//＜2.8＞8行目 <号数>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Gousuu ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Gousuu ) ;
	}
	//＜2.9＞9行目 <号表示>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Gou ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Gou ) ;
	}

	//＜2.10＞10行目～ 駅時刻
	
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order> の法則を持ちます。
	//	要素の数は、時刻表の列数です。

	if ( iRv >= 0 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;
			aRow.getCellCont()->insert( CdCsvCell(  ) ) ;
			pCdCsvDocument->getRowCont()->set( aRow , CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;

		}
	}
	//＜2.11＞[列1="備考" AND 列2=""]の列　備考列
	if ( iRv >= 0 )
	{
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size() ) ;
			aRow.getCellCont()->insert( CdCsvCell() ) ;
			pCdCsvDocument->getRowCont()->set( aRow , 
				CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size() ) ;
	}
	return iRv ;
}


	// --------------------------------
	//@name decode() の下請関数	
	// --------------------------------
int CconvJikokuhyouCsv::decode_createContJikokuOrderOfJjikokuhyouIndex( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou eRessyahoukou , 
		const CdCsvDocument* pCdCsvDocument , 
		deque<int>*	pcontiJikokuOrderOfJikokuhyouIndex , 
		string* pstrErrorInfoString ) 
{
	int iRv = 0 ;
	const Mu<CentDedEkiCont::CdDedEki>* pCdDedEkiContGet = 
		pCentDedEkiCont->getMuPtr(eRessyahoukou ) ;
	string	strErrorInfoString ;

	if ( iRv >= 0 )
	{
		pcontiJikokuOrderOfJikokuhyouIndex->clear() ;
	}
	if ( iRv >= 0 )
	{
		int iJikokuOrder = 0 ;
		for ( int iJikokuhyouInex = 0 ; 
			iRv >= 0 && iJikokuhyouInex < pCdCsvDocument->getRowCont()->size() - CSVROWINDEX_Ekijikoku0 ;	
			iJikokuhyouInex ++ )
		{
			CdCsvRow aCdCsvRow = pCdCsvDocument->getRowCont()->get( iJikokuhyouInex + CSVROWINDEX_Ekijikoku0 ) ;
			string	strEkimei = aCdCsvRow.getCellCont()->get( 0 ).getData() ;
			string	strChakuHatsu = aCdCsvRow.getCellCont()->get( 1 ).getData() ;
			
			if ( strEkimei == m_nameBikou && 
				strChakuHatsu.empty() )
			{
				//備考行がみつかりました。
				break ;
			}
			
			bool bIsJikokuOrderFound = false ;
			for ( ; 
				!bIsJikokuOrderFound && iJikokuOrder < pCdDedEkiContGet->size() * 2 ; 
				iJikokuOrder ++ )
			{
				int	iEkiOrder = iJikokuOrder / 2 ;
				int iHatsu = iJikokuOrder % 2 ;
				if ( strEkimei == pCdDedEkiContGet->get( iEkiOrder ).getEkimei() )
				{
					if ( ( iHatsu == 0 && strChakuHatsu == m_nameChaku ) || 
						( iHatsu == 1 && strChakuHatsu == m_nameHatsu ) )
					{
						pcontiJikokuOrderOfJikokuhyouIndex->push_back( iJikokuOrder ) ;
						bIsJikokuOrderFound = true ;
					}
				}
			}
			if ( !bIsJikokuOrderFound )
			{
				/**
					駅名が見つかりません。
				@param EkiMei
					駅名
				@param Chakuhatsu
					着発
				*/
				const char* const ERRREASON_EkimeiNotFound = "Ekimei is Not Found." ;
				const char* const ERRREASON_PROP_Ekimei = "Ekimei" ;
				const char* const ERRREASON_PROP_Chakuhatsu = "Chakuhatsu" ;
							
				
				strErrorInfoString = ERRREASON_EkimeiNotFound ;
				strErrorInfoString += strprintf( "\t%s=%s" , 
					ERRREASON_PROP_Ekimei , strEkimei.c_str() ) ;
				strErrorInfoString += strprintf( "\t%s=%s" , 
					ERRREASON_PROP_Chakuhatsu , strChakuHatsu.c_str()  ) ;
				iRv = -1 ;	//	駅名が見つかりません。
			}
		}
	}
	// --------------------------------
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}

int CconvJikokuhyouCsv::decode_readRessyaColumn( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const deque<int>&	contiJikokuOrderOfJikokuhyouIndex , 
		CentDedRessya* pCentDedRessya , 
		const CdCsvDocument* pCdCsvDocument , 
		int iColumnIndex ,
		string* pstrErrorInfoString ) 
{
	int iRv = 0 ;
	string	strErrorInfoString ;
	// --------------------------------
	//	列車種別Indexを決定
	// --------------------------------
	// --------------------------------
	//＜2.5＞5行目 <列車番号>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()
			->get( CSVROWINDEX_Ressyabangou ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		pCentDedRessya->setRessyabangou( aCell.getData() ) ;
	}
	
	//＜2.6＞6行目 <列車種別>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get(CSVROWINDEX_Ressyasyubetsu ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		
		int iRessyasyubetsuIndex = -1 ;
		if ( iRv >= 0 )
		{
			for ( int idx = 0 ;
				iRv >= 0 && 
				iRessyasyubetsuIndex == -1 && 
					idx < pCentDedRessyasyubetsuContGet->size() ;
				idx ++ )
			{
				const CentDedRessyasyubetsu* pCentDedRessyasyubetsu 
					= pCentDedRessyasyubetsuContGet->get( idx ) ;
				if ( pCentDedRessyasyubetsu->getRyakusyou() == 
					strValue )
				{
					iRessyasyubetsuIndex = idx ;
				}
			}
			if ( iRessyasyubetsuIndex == -1 )
			{
				/**
					列車種別が見つかりません。
				@param Ressyasyubetsu
					列車種別
				*/
				const char* const ERRREASON_RessyasyubetsuNotFound = "Ressyasyubetsu is Not Found." ;
				const char* const ERRREASON_PROP_Ressyasyubetsu = "Ressyasyubetsu" ;
				strErrorInfoString = ERRREASON_RessyasyubetsuNotFound ; 
				strErrorInfoString += strprintf( "\t%s=%s" , 
					ERRREASON_PROP_Ressyasyubetsu , strValue.c_str() ) ;
				iRv = -1 ;	//	列車種別が見つかりません。
			}
		}
		//iRessyasyubetsuIndex = 列車種別Index ;
		if ( iRv >= 0 )
		{
			pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndex ) ;
		}

	}

	//＜2.7＞7行目 <列車名>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Ressyamei ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		pCentDedRessya->setRessyamei( strValue  ) ;
	}

	//＜2.8＞8行目 <号数>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Gousuu ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		pCentDedRessya->setGousuu( strValue  ) ;
	}
	//＜2.10＞10行目～ 駅時刻
	
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order> の法則を持ちます。
	//	要素の数は、時刻表の列数です。

	if ( iRv >= 0 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iRv >= 0 && 
				iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			int iJikokuOrder = 
				contiJikokuOrderOfJikokuhyouIndex[iJikokuhyouIndex] ;
			int iEkiOrder = iJikokuOrder / 2 ;
			int iHatsu = iJikokuOrder % 2 ;
			
			CentDedEkiJikoku aCentDedEkiJikoku 
				= pCentDedRessya->getCentDedEkiJikoku(iEkiOrder) ;
			
			
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;
			CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
			string strValue = aCell.getData() ;
			
			
			CentDedEkiJikoku::EEkiatsukai eEkiatsukai = 
				CentDedEkiJikoku::Ekiatsukai_None ;
			CdDedJikoku	aCdDedJikoku ;
			
			int iResult = decode_Ekijikoku( 
				&eEkiatsukai , 
				&aCdDedJikoku , 
				strValue ) ;
			if ( iResult < 0 )
			{
				/**
					時刻を解釈できません。
				@param Jikoku
					時刻
				*/
				const char* const ERRREASON_Illegal_Jikoku_Format = "Illegal Jikoku format." ;
				const char* const ERRREASON_PROP_Jikoku = "Jikoku" ;
				strErrorInfoString = ERRREASON_Illegal_Jikoku_Format ; 
				strErrorInfoString += strprintf( "\t%s=%s" , 
					ERRREASON_PROP_Jikoku , strValue.c_str() ) ;
				
				iRv = -21 ;	//	時刻を解釈できません。
			}
			else
			{
				if ( iHatsu == 0 )
				{
					aCentDedEkiJikoku.setEkiatsukai( eEkiatsukai ) ;
					aCentDedEkiJikoku.setChakujikoku( aCdDedJikoku ) ;
				}
				else
				{
					//	発時刻は、駅扱の変更を行いません。
					if ( aCentDedEkiJikoku.getEkiatsukai() == 
						CentDedEkiJikoku::Ekiatsukai_None )
					{
						aCentDedEkiJikoku.setEkiatsukai( eEkiatsukai ) ;
					}
					aCentDedEkiJikoku.setHatsujikoku( aCdDedJikoku ) ;
				}
			}
			if ( iRv >= 0 )
			{
				pCentDedRessya->setCentDedEkiJikoku( iEkiOrder , 
					aCentDedEkiJikoku ) ;
			}
		}
	}
	//＜2.11＞[列1="備考" AND 列2=""]の列　備考列
	if ( iRv >= 0 &&  
			CSVROWINDEX_Ekijikoku0 + (int)contiJikokuOrderOfJikokuhyouIndex.size() 
				< (int)pCdCsvDocument->getRowCont()->size() )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size());
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		pCentDedRessya->setBikou( strValue  ) ;
	}
	// --------------------------------
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}


int CconvJikokuhyouCsv::decode_isNullRessyaColumn( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const deque<int>&	contiJikokuOrderOfJikokuhyouIndex , 
		CentDedRessya* pCentDedRessya , 
		const CdCsvDocument* pCdCsvDocument , 
		int iColumnIndex ,
		string* pstrErrorInfoString ) 
{
	int iRv = 1 ;
	string	strErrorInfoString ;
	// --------------------------------
	//	列車種別Indexを決定
	// --------------------------------
	//＜2.5＞5行目 <列車番号>
	if ( iRv == 1 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()
			->get( CSVROWINDEX_Ressyabangou ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	この列はNull列車ではありません。
		}
	}
	
	//＜2.6＞6行目 <列車種別>
	if ( iRv == 1 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get(CSVROWINDEX_Ressyasyubetsu ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	この列はNull列車ではありません。
		}
	}

	//＜2.7＞7行目 <列車名>
	if ( iRv == 1 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Ressyamei ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	この列はNull列車ではありません。
		}
	}

	//＜2.8＞8行目 <号数>
	if ( iRv == 1 )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Gousuu ) ;
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	この列はNull列車ではありません。
		}
	}
	//＜2.10＞10行目～ 駅時刻
	
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order> の法則を持ちます。
	//	要素の数は、時刻表の列数です。

	if ( iRv == 1 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iRv == 1 && 
				iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			int iJikokuOrder = 
				contiJikokuOrderOfJikokuhyouIndex[iJikokuhyouIndex] ;
			int iEkiOrder = iJikokuOrder / 2 ;
			int iHatsu = iJikokuOrder % 2 ;
			
			CentDedEkiJikoku aCentDedEkiJikoku 
				= pCentDedRessya->getCentDedEkiJikoku(iEkiOrder) ;
			
			
			CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
				CSVROWINDEX_Ekijikoku0 + iJikokuhyouIndex ) ;
			CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
			string strValue = aCell.getData() ;
			if ( !strValue.empty() )
			{
				iRv = 0 ;	//	この列はNull列車ではありません。
			}
		}
	}
	//＜2.11＞[列1="備考" AND 列2=""]の列　備考列
	if ( iRv == 1 && (int)pCdCsvDocument->getRowCont()->size() >
			CSVROWINDEX_Ekijikoku0 + (int)contiJikokuOrderOfJikokuhyouIndex.size() )
	{
		CdCsvRow	aRow = pCdCsvDocument->getRowCont()->get( 
			CSVROWINDEX_Ekijikoku0 + contiJikokuOrderOfJikokuhyouIndex.size());
		CdCsvCell	aCell = aRow.getCellCont()->get( iColumnIndex ) ;
		string strValue = aCell.getData() ;
		if ( !strValue.empty() )
		{
			iRv = 0 ;	//	この列はNull列車ではありません。
		}
	}
	// --------------------------------
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}


	// ********************************
	//	コンストラクタ
	// ********************************
CconvJikokuhyouCsv::CconvJikokuhyouCsv(
		const std::string& nameKudari ,
		const std::string& nameNobori ,
		const std::string& nameRessyabangou ,
		const std::string& nameRessyasyubetsu ,
		const std::string& nameRessyamei ,
		const std::string& nameGousuu ,
		const std::string& nameGou ,
		const std::string& nameBikou ,
		const std::string& nameChaku ,
		const std::string& nameHatsu ,
		const std::string& nameTsuuka ,
		const std::string& nameKeiyunasi ) :
	m_nameKudari( nameKudari ) , 
	m_nameNobori( nameNobori ) ,
	m_nameRessyabangou( nameRessyabangou ),
	m_nameRessyasyubetsu( nameRessyasyubetsu ),
	m_nameRessyamei( nameRessyamei ),
	m_nameGousuu( nameGousuu ),
	m_nameGou( nameGou ),
	m_nameBikou( nameBikou ) ,
	m_nameChaku( nameChaku ) ,
	m_nameHatsu( nameHatsu ) ,
	m_nameTsuuka( nameTsuuka ) ,
	m_nameKeiyunasi( nameKeiyunasi )
{
}


	// ********************************
	//@name	CconvJikokuhyouCsv
	// ********************************
int CconvJikokuhyouCsv::encode( 
		const CentDedRosen& aCentDedRosen , 
		int iDiaIndex , 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIndex , int iRessyaCount , 
		CdCsvDocument* pCdCsvDocument ) 
{
	int iRv = 0 ;
	
	const CentDedEkiCont* pCentDedEkiCont = NULL ;
	const Mu<CentDedEkiCont::CdDedEki>* pCdDedEkiCont = NULL ;
	const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet = NULL ;
	const CentDedDia* pCentDedDia = NULL ;
	const Mu<const CentDedRessya*>* pCentDedRessyaCont = NULL ;

	// --------------------------------
	//	オブジェクトCdCsvDocument をクリア
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCentDedEkiCont = aCentDedRosen.getCentDedEkiCont() ;
		pCdDedEkiCont = aCentDedRosen.getCentDedEkiCont()
			->getMuPtr( eRessyahoukou ) ;
		pCentDedRessyasyubetsuContGet = aCentDedRosen.getCentDedRessyasyubetsuCont()->getMuPtr() ; 
		pCentDedDia = aCentDedRosen.getCentDedDiaCont()->getMuPtr()->get( iDiaIndex ) ;
		if ( pCentDedDia == NULL )
		{
			iRv = -1 ;	//	iDiaIndex が不正です。
		}
	}
	if ( iRv >= 0 )
	{
		pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( eRessyahoukou )->getMuPtr() ;
	}
	//pCentDedRessyaCont = 列車のコンテナ
	if ( iRv >= 0 )
	{
		if ( !( 0 <= iRessyaIndex && iRessyaIndex < pCentDedRessyaCont->size() ) 
			&& iRessyaIndex != 0 )
		{
			iRv = -2 ;	//	iRessyaIndex が不正です。
		}
	}
	if ( iRv >= 0 )
	{
		if ( iRessyaCount == INT_MAX )
		{
			iRessyaCount = pCentDedRessyaCont->size() - iRessyaIndex ;
		}
		if ( !( 0 <= iRessyaIndex + iRessyaCount && 
			iRessyaIndex + iRessyaCount <= pCentDedRessyaCont->size() ) )
		{
			iRv = -3 ;	//	iRessyaCount が不正です。
		}
	}

	// --------------------------------
	//	CdCsvDocument をクリア
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCdCsvDocument->getRowCont()->erase( 0 , INT_MAX ) ;
	}

	// --------------------------------
	//	ヘッダ列
	// --------------------------------
	//	1行目 FileType行
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( nameFileType ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( nameFileTypeValue ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}	
	//	2行目 DiaName行
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( pCentDedDia->getName() ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}	
	//＜2.3＞ 3行目 <下り,上り>
	if ( iRv >= 0 )
	{
		string strValue ;
		if ( eRessyahoukou == Ressyahoukou_Kudari )
		{
			strValue = m_nameKudari ;
		}
		else
		{
			strValue = m_nameNobori ;
		}
		
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( strValue ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}
	//＜2.4＞4行目 
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	// --------------------------------
	//	時刻表部分の左側2列
	// --------------------------------
	//＜2.5＞5行目 <列車番号>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameRessyabangou ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	//＜2.6＞6行目 <列車種別>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameRessyasyubetsu ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	//＜2.7＞7行目 <列車名>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameRessyamei ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	//＜2.8＞8行目 <号数>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameGousuu ) ) ;
		aRow.getCellCont()->insert( CdCsvCell( ) ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}
	//＜2.9＞9行目 <号表示>
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}

	//＜2.10＞10行目～ 駅時刻
	
	//	このコンテナは、  contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order>
	deque<CdDedJikokuOrder>	contiJikokuOrderOfJikokuhyouIndex ;
	if ( iRv >= 0 )
	{
		encode_createContJikokuOrderOfJjikokuhyouIndex( 
			pCentDedEkiCont ,
			eRessyahoukou , 
			&contiJikokuOrderOfJikokuhyouIndex ) ;
	}
	//contiJikokuOrderOfJikokuhyouIndex = 
	//	 contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order> の法則を持ちます。
	//	要素の数は、時刻表の列数です。

	if ( iRv >= 0 )
	{
		for ( int iJikokuhyouIndex = 0 ; 
			iJikokuhyouIndex < (int)contiJikokuOrderOfJikokuhyouIndex.size() ;
			iJikokuhyouIndex ++ )
		{
			CdDedJikokuOrder iJikokuOrder = contiJikokuOrderOfJikokuhyouIndex[iJikokuhyouIndex] ;
			int iEkiOrder = iJikokuOrder.getEkiOrder() ;
			int iHatsu = 0 ;
			if ( iJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
			{
				iHatsu = 1 ;
			}
			CentDedEkiCont::CdDedEki aCdDedEki = pCdDedEkiCont->get( iEkiOrder ) ;

			string	strEkimei = aCdDedEki.getEkimei() ;
			string	strChakuHatsu ;
			if ( iHatsu == 0 )
			{
				strChakuHatsu = m_nameChaku ;
			}
			else
			{
				strChakuHatsu = m_nameHatsu ;
			}

			CdCsvRow	aRow ;
			aRow.getCellCont()->insert( CdCsvCell( strEkimei ) ) ;
			aRow.getCellCont()->insert( CdCsvCell( strChakuHatsu ) ) ;
			pCdCsvDocument->getRowCont()->insert( aRow ) ;
		}
	}
	//＜2.11＞[列1="備考" AND 列2=""]の列　備考列
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow ;
		aRow.getCellCont()->insert( CdCsvCell( m_nameBikou ) ) ;
		aRow.getCellCont()->insert( CdCsvCell() ) ;
		pCdCsvDocument->getRowCont()->insert( aRow ) ;
	}
	// --------------------------------
	//	列車を出力(時刻表部分の3列目以降)
	// --------------------------------
	for ( int idxRessya = iRessyaIndex ; 
		iRv >= 0 && idxRessya < iRessyaIndex + iRessyaCount ; 
		idxRessya ++ )
	{
		const CentDedRessya* pCentDedRessya = pCentDedRessyaCont->get( idxRessya ) ; 

		if ( pCentDedRessya->isNull() )
		{
			iRv = encode_AddRessyaNull( 
					contiJikokuOrderOfJikokuhyouIndex , 
					pCdCsvDocument ) ; 
		}
		else
		{
			iRv = encode_AddRessya( 
					pCentDedRessyasyubetsuContGet , 
					contiJikokuOrderOfJikokuhyouIndex , 
					pCentDedRessya , 
					pCdCsvDocument ) ; 
		}
	}
	
	return iRv ;
}

int CconvJikokuhyouCsv::decode( 
		CentDedRosen* pCentDedRosen , 
		int iDiaIndex , 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIndex , 
		const CdCsvDocument& argCdCsvDocument , 
		string* pstrErrorInfoString ) 
{
	int iRv = 0 ;
	string	strErrorInfoString ;
	CdCsvDocument aCdCsvDocument = argCdCsvDocument ;
	const Mu<CentDedEkiCont::CdDedEki>* pCdDedEkiCont = NULL ;
	const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet = NULL ;
	CentDedDia* pCentDedDia = NULL ;
	CentDedRessyaCont* pCentDedRessyaCont = NULL ;
	// --------------------------------
	//	
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCdDedEkiCont = pCentDedRosen->getCentDedEkiCont()
			->getMuPtr( eRessyahoukou ) ;
		pCentDedRessyasyubetsuContGet = static_cast<const CentDedRosen*>(pCentDedRosen)
			->getCentDedRessyasyubetsuCont()->getMuPtr() ; 

		pCentDedDia= pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( iDiaIndex ) ;
		if ( pCentDedDia == NULL )
		{
			iRv = -21  ;	//	iDiaIndex が不正です。
		}
	}
	if ( iRv >= 0 )
	{
		pCentDedRessyaCont= pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;
	}
	// --------------------------------
	//	
	// --------------------------------
	if ( iRv >= 0 )
	{
		if ( iRessyaIndex == INT_MAX )
		{
			iRessyaIndex = pCentDedRessyaCont->size() ;
		}
		if ( !( 0 <= iRessyaIndex && iRessyaIndex <= pCentDedRessyaCont->size() ) )
		{
			iRv = -22  ;	//	iRessyaIndex が不正です。
		}
	}
	// --------------------------------
	//	CSVの列数を最適化します。
	// --------------------------------
	int iColumnCount = 0 ;
	if ( iRv >= 0 )
	{
		aCdCsvDocument.adjustColumnCount() ;
		if ( aCdCsvDocument.getRowCont()->size() < CSVROWINDEX_Ekijikoku0 )
		{
			/*
				行が少なすぎます。

			@param RowCount
				行数
			*/
			const char* const ERRREASON_TooFewRows = "Too Few Rows." ;
			const char* const ERRREASON_PROP_RowCount = "RowCount=" ;
						
			
			strErrorInfoString = strprintf( "%s\t%s=%d" , 
				ERRREASON_TooFewRows , 
				ERRREASON_PROP_RowCount , aCdCsvDocument.getRowCont()->size() ) ;
			iRv = -1 ;	//	行が少なすぎます。
		}
		else 
		{
			iColumnCount = aCdCsvDocument.getRowCont()->get( 0 ).getCellCont()->size() ;
			if ( iColumnCount < 2 )
			{
				/*
					列が少なすぎます。
				@param ColumnCount
					列数
				*/
				const char* const ERRREASON_TooFewColumns = "Too Few Columns." ;
				const char* const ERRREASON_PROP_ColumnCount = "ColumnCount=" ;
				strErrorInfoString = strprintf( "%s\t%s=%d" , 
					ERRREASON_TooFewColumns , 
					ERRREASON_PROP_ColumnCount , aCdCsvDocument.getRowCont()->get( 0 ).getCellCont()->size() ) ;
				iRv = -2 ;	//	列が少なすぎます。
			}
		}
	}
	// --------------------------------
	//	FileType を検証
	// --------------------------------
	if ( iRv >= 0 )
	{
		CdCsvRow	aRow = aCdCsvDocument.getRowCont()->get( 0 ) ;
		CdCsvCell	aCell0 = aRow.getCellCont()->get( 0 ) ;
		CdCsvCell	aCell1 = aRow.getCellCont()->get( 1 ) ;

		/**
			ファイル形式が認識できません。
		@param FileType
				ファイル形式
		*/
		const char* const ERRREASON_FileTypeMismatch = "File Type Mismatch." ;
		const char* const ERRREASON_PROP_FileType = "FileType=" ;

		if ( aCell0.getData() != nameFileType )
		{
			strErrorInfoString = strprintf( "%s" , 
				ERRREASON_FileTypeMismatch ) ;
			iRv = -3 ;	//	ファイル形式が認識できません
		}
		else if ( aCell1.getData() != nameFileTypeValue )
		{
			strErrorInfoString = strprintf( "%s\t%s=%s" , 
				ERRREASON_FileTypeMismatch , 
				ERRREASON_PROP_FileType , aCell1.getData().c_str() ) ;
			iRv = -4 ;	//	ファイル形式が認識できません
		}
	}
	
	// --------------------------------
	//	時刻列と駅名の対照テーブルを作成
	// --------------------------------
	//	このコンテナは、  contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order>
	deque<int>	contiJikokuOrderOfJikokuhyouIndex ;
	if ( iRv >= 0 )
	{
		int iResult = decode_createContJikokuOrderOfJjikokuhyouIndex( 
			pCentDedRosen->getCentDedEkiCont() ,
			eRessyahoukou , 
			&aCdCsvDocument , 
			&contiJikokuOrderOfJikokuhyouIndex ,
			&strErrorInfoString ) ;
		//iResult = 
		//	-	-1 ;	//	駅名が見つかりません。
		if ( iResult < 0 )
		{

			iRv = -11  ;	//	駅名が見つかりません。
		}
	}

	// --------------------------------
	//	列車を出力(時刻表部分の3列目以降)
	// --------------------------------
	if ( iRv >= 0 )
	{
		for ( int iColumnIndex = CSVCOLUMNINDEX_Ressya0 ; 
			iRv >= 0 && iColumnIndex <  iColumnCount   ;
			iColumnIndex ++ )
		{
			CentDedRessya	aCentDedRessya( pCentDedRessyaCont->createNullRessya() );
			if ( iRv >= 0 )
			{
				int iResult = decode_isNullRessyaColumn( 
					pCentDedRessyasyubetsuContGet ,
					contiJikokuOrderOfJikokuhyouIndex , 
					&aCentDedRessya , 
					&aCdCsvDocument , 
					iColumnIndex ,
					&strErrorInfoString ) ;
				if ( iResult < 0 )
				{
						iRv = -21 ;
				}
				else if ( iResult == 1 )
				{
					//	Null列車
					aCentDedRessya.clear() ;
				}
				else
				{
					int iResult = decode_readRessyaColumn( 
						pCentDedRessyasyubetsuContGet ,
						contiJikokuOrderOfJikokuhyouIndex , 
						&aCentDedRessya , 
						&aCdCsvDocument , 
						iColumnIndex ,
						&strErrorInfoString ) ;
					if ( iResult < 0 )
					{
						iRv = -11 ;
					}
				}
			}
			if ( iRv >= 0 )
			{
				pCentDedRessyaCont->insert( aCentDedRessya , iRessyaIndex ) ;
				iRessyaIndex ++ ;
			}
		}
	}
	// --------------------------------
	// --------------------------------
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}

} //namespace ConvJikokuhyouCsv

