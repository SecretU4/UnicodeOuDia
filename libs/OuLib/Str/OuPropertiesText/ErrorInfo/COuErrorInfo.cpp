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
// $Id: COuErrorInfo.cpp 294 2016-06-11 05:10:03Z okm $
// ****************************************************************
/** @file */

#include "str\OuPropertiesText\ErrorInfo\COuErrorInfo.h"
#include "str\strprintf.h"
#include "str\CdConnectedString2.h"
#include "NsOu\dynamic_castOu.h"
#include "NsOu\OuNew.h"

using namespace std ;
namespace OuLib{
namespace Str{
namespace OuPropertiesText{
namespace ErrorInfo{

	// ********************************
	//@name 定数
	// ********************************
const char* const COuErrorInfo::DirectoryName_ErrorInfo = "ErrorInfo" ;
const char* const COuErrorInfo::PropertyTextName_Reason = "Reason" ;
const char* const COuErrorInfo::DirectoryName_Prop = "Prop" ;

	// ********************************
	//@name 操作
	// ********************************
	
Ou<CDirectory> COuErrorInfo::toOuPropertiesTextErrorInfo()const
{
	int iRv =0 ;
	Ou<CDirectory> pCDirectory ;
	if ( iRv >= 0 )
	{
		pCDirectory = OuNew<CDirectory>( new CDirectory( DirectoryName_ErrorInfo ) ) ;
		CNodeContainer* pCNodeContainer = pCDirectory->getCNodeContainer() ; 
		pCNodeContainer->setValue( PropertyTextName_Reason , m_strReason ) ;
		if ( m_Prop.size() > 0 )
		{
			Ou<CDirectory> pdirProp = OuNew<CDirectory>( new CDirectory( DirectoryName_Prop ) ) ;
			*pdirProp->getCNodeContainer() = m_Prop ; 
			pCNodeContainer->insert( pdirProp ) ;
		}
	}

	return pCDirectory ;
}

int COuErrorInfo::fromOuPropertiesTextErrorInfo( 
		Ou<const CDirectory> pCDirectory )
{
	int iRv = 0 ;

	const IfNodeContainerConst* pCNodeContainer = pCDirectory->getIfNodeContainerConst() ;
	clear() ;

	string strReason ;
	CNodeContainer	aProp ;
	if ( iRv >= 0 )
	{
		if ( pCDirectory->getName() != DirectoryName_ErrorInfo )
		{
			iRv = -1 ;	//	pCDirectory は "Directory" ではありません。
		}
	}
	if ( iRv >= 0 )
	{
		strReason = pCNodeContainer->getValue( PropertyTextName_Reason ) ;
		if ( strReason.empty() )
		{
			iRv = -2 ;	//	Directory に"Reason" PropertyText がありません。
		}
	}
	if ( iRv >= 0 )
	{
		if ( pCNodeContainer->sizeInName( DirectoryName_Prop ) > 0 ) 
		{
			Ou<const CDirectory> pdirProp = dynamic_castOu<const CDirectory>( 
				pCNodeContainer->getInName( DirectoryName_Prop , 0 ) 
			);
			if ( pdirProp != NULL )
			{
				aProp = *Ou<CDirectory>( pdirProp->clone() )->getCNodeContainer() ;
			}
		}
	}
	if ( iRv >= 0 )
	{
		m_strReason = strReason ;
		m_Prop = aProp ;
	}
	return iRv ;
}

std::string COuErrorInfo::toOuErrorInfoText()const 
{
	string strRv ;

	//Reason
	strRv = m_strReason ;

	//Prop
	for ( int idxProp = 0 ; idxProp < m_Prop.size() ; idxProp ++ )
	{
		Ou<CNode>	pCNode = m_Prop.get( idxProp ) ;
		Ou<CPropertyString> pCPropertyString = dynamic_castOu<CPropertyString>( pCNode ) ;
		if ( pCPropertyString != NULL && !pCPropertyString->getName().empty() )
		{
			strRv += '\t' ;
			strRv += pCPropertyString->getName() ;
			if ( !pCPropertyString->getValue().empty() )
			{
				strRv += '=' ;
				strRv += pCPropertyString->getValue() ;
			}
		}
	}
	return strRv ;
}

int COuErrorInfo::fromOuErrorInfoText( 
	const std::string& strOuErrorInfoText ) 
{
	int iRv = 0 ;
	clear() ;
	string strReason ;
	CNodeContainer	aProp ;

	CdConnectedString2 aCdConnectedString2( 
		strOuErrorInfoText , '\t' , '=' ) ;

	//Reason
	if ( iRv >= 0 )
	{
		if ( aCdConnectedString2.size() > 0 )
		{
			CdConnectedString2::CdItem aCdItem = aCdConnectedString2.at( 0 ) ;
			
			strReason = aCdItem.getName() ;
			if ( !aCdItem.getValue().empty() )
			{
				strReason += aCdConnectedString2.getEqualChar() ;
				strReason += aCdItem.getValue() ;
			}
		}
	}

	//Prop
	for ( int idxProp = 1 ; iRv >= 0 && idxProp < aCdConnectedString2.size() ; idxProp ++ )
	{
		CdConnectedString2::CdItem aCdItem = aCdConnectedString2.at( idxProp ) ;
		Ou<CPropertyString> pCPropertyString = OuNew<CPropertyString>( 
			new CPropertyString( aCdItem.getName() , aCdItem.getValue() ) ) ;
		aProp.insert( pCPropertyString ) ;
	}


	if ( iRv >= 0 )
	{
		m_strReason = strReason ;
		m_Prop = aProp ;
	}
	return iRv ;
}

void COuErrorInfo::clear() 
{
	m_strReason.erase() ;
	m_Prop.erase( 0 , INT_MAX ) ;
}

bool COuErrorInfo::isNull()const 
{
	return ( m_strReason.empty() && m_Prop.size() == 0 ) ;
}

} //namespace ErrorInfo{
} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{
