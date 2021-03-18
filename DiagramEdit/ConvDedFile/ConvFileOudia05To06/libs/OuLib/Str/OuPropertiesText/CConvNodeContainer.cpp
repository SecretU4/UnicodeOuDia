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
//$Id: CConvNodeContainer.cpp 10 2012-08-26 09:48:47Z okm $
#include "str\OuPropertiesText\CConvNodeContainer.h"
#include "str\OuPropertiesText\CDirectory.h"
#include "Ou\dynamic_castOu.h"
#include "Ou\OuNew.h"
#include "str\strprintf.h"
using namespace OuLib ;

namespace OuPropertiesText{


/**
	文字列がデコードできません。
@param ERRSUBPROP_Text
	対象となる文字列
*/
const char* const CConvNodeContainer::ERRREASON_Undecoded_Text = "Undecoded Text.";
/**
	ディレクトリが途中で閉じています。
*/
const char* const CConvNodeContainer::ERRREASON_ContainerAborted = "Container Aborted." ;
/**
	ディレクトリが閉じていません
*/
const char* const CConvNodeContainer::ERRREASON_ContainerIsNotClosed = "Container Is Not Closed." ;

/**
	行テキスト
*/
const char* const CConvNodeContainer::ERRPROP_Text = "Text" ;

	// ********************************
	//	コンストラクタ
	// ********************************

CConvNodeContainer::CConvNodeContainer  (void)
{
}

CConvNodeContainer::~CConvNodeContainer  (void)
{
}
	// --------------------------------
	//@name 下請け関数
	// --------------------------------

int CConvNodeContainer::decodeNodeContainer(
		const string& strContent , 	int iPosBegin  , int* piPosNext , 
		CNodeContainer* pCNodeContainer ,
		string* pstrErrorInfoString ) 
{
	int iRv = 1 ;
	string strLine ;
	string strErrorInfoString ;
	int iPosNext = iPosBegin ;


	pCNodeContainer->erase( 0 , INT_MAX ) ;

	if ( iPosBegin >= (int)strContent.size() )
	{
		iRv = 0 ;	//	すでに iPosBegin がコンテンツの末尾にあります。
	}
	if ( iRv >= 1 )
	{
		
		for ( ;
			iRv >= 0 && 
			1 == getLine( 
				strContent , iPosBegin , &iPosNext , 
				&strLine  ) ;
			iPosBegin = iPosNext )
		{
			if ( strLine == "" )
			{
				continue ;
			}
			else if ( strLine == "." )
			{
				//	ディレクトリ終了記号
				//	iPosNext は、"." の行の前に移します。
				iPosNext = iPosBegin ;
				break ;	//	NodeContainer の末尾
			}
			bool bIsParsed = false ;
			if ( !bIsParsed )
			{
				if ( strLine.find( '=' ) == string::npos && 
					strLine[ strLine.size() - 1 ] == '.' )
				{
					string strName = strLine.substr( 0 , strLine.size() -1 ) ;

					//iPosBegin= 次の行に移動
					iPosBegin = iPosNext ;
					OuNew<CDirectory>	pCDirectory( new CDirectory( strName ) ) ; 
					int iResult = decodeNodeContainer(
						strContent , iPosBegin , &iPosNext , 
						pCDirectory->getCNodeContainer() , 
						&strErrorInfoString ) ;
					if ( iResult == 0 )
					{
						//	ディレクトリが閉じていません
						if ( !strErrorInfoString.empty() ){	strErrorInfoString += "\n" ; };
						strErrorInfoString += ERRREASON_ContainerIsNotClosed ;
						iRv = -2 ;							//	ディレクトリが閉じていません
					}
					else if ( iResult < 0 )
					{
						//	文字列がデコードできません。
						if ( !strErrorInfoString.empty() ){	strErrorInfoString += "\n" ; };
						strErrorInfoString += strprintf( "%s\t%s=%s" , 
							ERRREASON_Undecoded_Text , 
							ERRPROP_Text , strLine.c_str() ) ;
						iRv = -1 ;	//	文字列がデコードできません。	
					}
					else
					{
						pCNodeContainer->insert( pCDirectory ) ;
						//	iPosNext = ディレクトリ終了記号の次の行に移動
						iPosBegin = iPosNext ;
						getLine( 
							strContent , iPosBegin , &iPosNext , 
							&strLine  ) ;
					}
					bIsParsed = true ;
				}
			}
			if ( !bIsParsed )
			{
				Ou<CPropertyString>	pCPropertyString ;
				if ( 1 == CConvNodeContainer::decodePropertyString(
					strContent , iPosBegin  , &iPosNext , 
					&pCPropertyString ,
					&strErrorInfoString ) )
				{
					pCNodeContainer->insert( pCPropertyString ) ;
					bIsParsed = true ;
				}
			}
			if ( !bIsParsed )
			{
				//	文字列がデコードできません。
				if ( !strErrorInfoString.empty() ){	strErrorInfoString += "\n" ; };
				strErrorInfoString += strprintf( "%s\t%s=%s" , 
					ERRREASON_Undecoded_Text , 
					ERRPROP_Text , strLine.c_str() ) ;
				iRv = -1 ;	//	文字列がデコードできません。	
			}
		}
	}
	// --------------------------------
	if ( piPosNext != NULL )
	{
		*piPosNext = iPosNext ;
	}
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}


string CConvNodeContainer::encodePropertyString_escapePropertyValue(
		const string& strValue ) 
{
	string strRv ;
	strRv.reserve( strRv.length() ) ;
	for ( string::const_iterator ite = strValue.begin() ;
		ite != strValue.end() ;
		ite ++ )
	{
		if ( *ite == '.' )
		{
			//	'.' はエスケープの対象からはずしました。
			strRv += "." ;
		}
		else if ( *ite == '\n' )
		{
			strRv += "\\n" ;
		}
		else if ( *ite == '\\' )
		{
			strRv += "\\\\" ;
		}
		else
		{
			strRv += *ite ;
		}

	}
	return strRv ;
}

string CConvNodeContainer::decodePropertyString_unescapePropertyValue(
		const string& strValue ) 
{
	string strRv ;
	strRv.reserve( strRv.length() ) ;
	for ( string::const_iterator ite = strValue.begin() ;
		ite != strValue.end() ;
		ite ++ )
	{
		if ( ite + 1 != strValue.end() && *ite == '\\' )
		{
			ite ++ ;
			if ( *ite == '.' )
			{
				//	'.' はエスケープの対象からはずしました。
				strRv += '\\' ;
				strRv += '.' ;
			}
			else if ( *ite == 'n' ) 
			{
				strRv += '\n' ;
			}
			else if ( *ite == '\\' )
			{
				strRv += '\\' ;
			}
			else
			{
				strRv += '\\' ;
				strRv += *ite ;
			}
		}
		else
		{
			strRv += *ite ;
		}

	}
	return strRv ;
}


int CConvNodeContainer::decodePropertyString(
		const string& strContent , 	int iPosBegin  , int* piPosNext , 
		Ou<CPropertyString>* ppCPropertyString ,
		string* pstrErrorInfoString ) 
{
	int iRv = 1 ;
	string strLine ;
	string strErrorInfoString ;
	int iPosNext = iPosBegin ;
	Ou<CPropertyString> pCPropertyString ;

		if ( 1 == getLine( 
			strContent , iPosBegin , &iPosNext , 
			&strLine  ) )
		{
			string	strName ;
			string	strValue ;
			string::size_type	pos = strLine.find( '=' ) ;
			if ( pos == string::npos )
			{
				strName = strLine ;
			}
			else
			{
				strName = strLine.substr( 0 , pos ) ;
				strValue = decodePropertyString_unescapePropertyValue( strLine.substr( pos + 1 ) ) ;
			}
			pCPropertyString = OuNew<CPropertyString>( new CPropertyString( strName , strValue  ) ) ;
		}
		else
		{
			iRv = 0 ;	//	すでに iPosBegin がコンテンツの末尾にあります。
		}
	// --------------------------------
	if ( piPosNext != NULL )
	{
		*piPosNext = iPosNext ;
	}
	if ( ppCPropertyString != NULL )
	{
		*ppCPropertyString = pCPropertyString ;
	}
	if ( pstrErrorInfoString != NULL )
	{
		*pstrErrorInfoString = strErrorInfoString ;
	}
	return iRv ;
}


int CConvNodeContainer::getLine( 
		const string& strContent , 	int iPosBegin  , int* piPosNext , 
		string* pstrLine  ) 
{
	int iRv = 1 ;
	string strLine ;
	int iPosNext = iPosBegin ;

	if ( iPosBegin >= (int)strContent.size() )
	{
		iRv = 0 ;	//	すでに iPosBegin がコンテンツの末尾にあります。
	}
	if ( iRv >= 1 )
	{

		for ( iPosNext = iPosBegin ; 
			iPosNext < (int)strContent.size() && strContent[iPosNext] != '\n' ; 
			iPosNext ++ )
		{
		}
		strLine = strContent.substr( iPosBegin , iPosNext - iPosBegin ) ;
		if ( strContent[iPosNext] == '\n' )
		{
			iPosNext ++ ;
		}
	}
	// --------------------------------
	if ( piPosNext != NULL )
	{
		*piPosNext = iPosNext ;
	}
	if ( pstrLine != NULL )
	{
		*pstrLine = strLine ;
	}
	return iRv ;
}

	// ********************************
	//@name	CConvNodeContainer  
	// ********************************

string CConvNodeContainer::encode( 
		const IfNodeContainerConst* pCNodeContainer ) 
{
	int iRv = 0 ;
	string strContent ;

	if ( iRv >= 0 )
	{
		for ( int iIndex = 0 ; iIndex < pCNodeContainer->size() ; iIndex ++ )
		{
			bool bProcessed = false ;
			string	strContentLine ;
			Ou<const CNode>	pCNode = pCNodeContainer->get( iIndex ) ;
			if ( !bProcessed )
			{
				Ou<const CPropertyString> pCPropertyString ;
				if ( ( pCPropertyString = dynamic_castOu<const CPropertyString>( pCNode ) ) != NULL )
				{
					strContentLine = pCPropertyString->getName() + "=" + 
						encodePropertyString_escapePropertyValue( pCPropertyString->getValue() ) ; 
					bProcessed = true ;
				}
			}
			if ( !bProcessed )
			{
				Ou<const CDirectory> pCDirectory ;
				if ( ( pCDirectory = dynamic_castOu<const CDirectory>( pCNode ) ) != NULL )
				{
					string strNodeContainer = encode( pCDirectory->getIfNodeContainerConst() ) ;
					strContentLine = pCDirectory->getName() + ".\n" + 
						strNodeContainer + 
						"." ; 
					bProcessed = true ;
				}
			}
			strContent += ( strContentLine + "\n" ) ;
		}
	}
	return strContent ;
}


int CConvNodeContainer::decode(
		const string& strContent , 
		CNodeContainer* pCNodeContainer ,
		string* pstrErrorInfoString ) 
{
	int iRv = 0 ;
	string strErrorInfoString ;
	if ( iRv >= 0 )
	{
		int iPosNext = 0 ; 
		int iResult = decodeNodeContainer(
				strContent , 0  , &iPosNext , 
				pCNodeContainer ,
				pstrErrorInfoString ) ;
		if ( iResult > 0 )
		{
			if ( iPosNext < (int)strContent.size() )
			{
				//	ディレクトリが途中で閉じています。
				if ( !strErrorInfoString.empty() ){	strErrorInfoString += "\n" ; };
				strErrorInfoString = ERRREASON_ContainerAborted ;
				iRv = -1 ;	//	ディレクトリが途中で閉じています。
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



} //namespace OuPropertiesText
