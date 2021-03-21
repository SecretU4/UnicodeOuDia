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
//$Id: CNodeContainer.cpp 294 2016-06-11 05:10:03Z okm $

#include "NsOu\dynamic_castOu.h"
#include "NsOu\OuNew.h"
#include "CNodeContainer.h"

namespace OuLib{
namespace Str{
namespace OuPropertiesText{

using namespace std ;

// ----------------------------------------------------------------
//	CNodeContainer::CaConst
// ----------------------------------------------------------------
// ********************************
//@name	IfNodeContainerConst-Propertyの取得
// ********************************
string CNodeContainer::CaConst::getValue( const string& strName )const 
{
	const CNodeContainer* pOuter = (const CNodeContainer*)(
		(char*)this - offsetof( CNodeContainer , m_CaConst ) ) ;
	return pOuter->getValue( strName ) ;
}
// ********************************
//@name	Mu
// ********************************
int	CNodeContainer::CaConst::size()const 
{
	const CNodeContainer* pOuter = (const CNodeContainer*)(
		(char*)this - offsetof( CNodeContainer , m_CaConst ) ) ;
	return pOuter->size() ;
}
Ou<const CNode> CNodeContainer::CaConst::get( int iIndex )const 
{
	const CNodeContainer* pOuter = (const CNodeContainer*)(
		(char*)this - offsetof( CNodeContainer , m_CaConst ) ) ;
	return pOuter->get( iIndex ) ;
}
// ********************************
//@name	CNodeContainer-InNameIndexでのアクセス
// ********************************
int	CNodeContainer::CaConst::sizeInName( const string& strName )const 
{
	const CNodeContainer* pOuter = (const CNodeContainer*)(
		(char*)this - offsetof( CNodeContainer , m_CaConst ) ) ;
	return pOuter->sizeInName( strName ) ;
}
Ou<const CNode> CNodeContainer::CaConst::getInName( 
	const string& strName , 
	int iInNameIndex )const 
{
	const CNodeContainer* pOuter = (const CNodeContainer*)(
		(char*)this - offsetof( CNodeContainer , m_CaConst ) ) ;
	return pOuter->getInName( strName , iInNameIndex ) ;
}
		
int CNodeContainer::CaConst::indexOfInNameIndex( 
			const string& strName ,
			int iInNameIndex )const 
{
	const CNodeContainer* pOuter = (const CNodeContainer*)(
		(char*)this - offsetof( CNodeContainer , m_CaConst ) ) ;
	return pOuter->indexOfInNameIndex( strName , iInNameIndex ) ;
}

int CNodeContainer::CaConst::indexToInNameIndex( 
			int iIndex )const 
{
	const CNodeContainer* pOuter = (const CNodeContainer*)(
		(char*)this - offsetof( CNodeContainer , m_CaConst ) ) ;
	return pOuter->indexToInNameIndex( iIndex ) ;
}


// ****************************************************************
//	CNodeContainer
// ****************************************************************
	// --------------------------------
	//@name	下請関数
	// --------------------------------
Ou<CPropertyString> CNodeContainer::getCPropertyString( const string& strName )const 
{
	Ou<CPropertyString>	pCPropertyString ;
	int iInNameIndex ;
	int iSizeInName = sizeInName( strName ) ;
	for ( iInNameIndex = 0 ; iInNameIndex < iSizeInName ; iInNameIndex ++ )
	{
		Ou<CNode> pCNode = m_contCNode[ indexOfInNameIndex( strName , iInNameIndex ) ] ;
		pCPropertyString = dynamic_castOu< CPropertyString >( pCNode ) ;
		if ( pCPropertyString != NULL )
		{
			break ;
		}
	}
	return pCPropertyString ;
}
	// ********************************
	//	コンストラクタ
	// ********************************

CNodeContainer::CNodeContainer()
{
}

CNodeContainer::~CNodeContainer()
{
}
CNodeContainer::CNodeContainer( const CNodeContainer& value )
	: m_CInNameIndexContainer( value.m_CInNameIndexContainer ) 
{
	//modify container
	m_contCNode.resize( value.size() ) ;
	int idx ;
	for (idx = 0 ; idx < value.size() ; idx ++ )
	{
		m_contCNode[idx] = value.get( idx )->clone() ;
	}
}
CNodeContainer& CNodeContainer::operator=( const CNodeContainer& value )
{
	//modify container
	m_contCNode.resize( value.size() ) ;
	int idx ;
	for (idx = 0 ; idx < value.size() ; idx ++ )
	{
		m_contCNode[idx] = value.get( idx )->clone() ;
	}

	m_CInNameIndexContainer = value.m_CInNameIndexContainer ; 
	return *this ;
}
	// ********************************
	//@name	集約
	// ********************************
const IfNodeContainerConst* CNodeContainer::getIfNodeContainerConst()const 
{
	return &m_CaConst ;
}


	// ********************************
	//@name	CNodeContainer-Propertyの取得･設定
	// ********************************
void CNodeContainer::setValue( const string& strName , 
		const string& strValue ) 
{
	Ou<CPropertyString> pCPropertyString = getCPropertyString( strName ) ;
	if ( pCPropertyString == NULL )
	{
		pCPropertyString = OuNew<CPropertyString>( new CPropertyString( strName , strValue ) ) ; 

		//modify container
		m_contCNode.push_back( pCPropertyString ) ;

		m_CInNameIndexContainer.insert( pCPropertyString->getName() ) ;

	}
	else
	{
		pCPropertyString->setValue( strValue ) ;
	}
}

string CNodeContainer::getValue( const string& strName )const 
{
	string	strValue ;
	Ou<CPropertyString> pCPropertyString = getCPropertyString( strName ) ;
	if ( pCPropertyString != NULL )
	{
		strValue = pCPropertyString->getValue() ;
	}
	return ( strValue ) ;
}

	// ********************************
	//@name	Mu
	// ********************************
int	CNodeContainer::size()const 
{
	return (int)m_contCNode.size() ;
}
CNodeContainer::ElementType 
CNodeContainer::get( int iIndex )const 
{
	return m_contCNode[iIndex] ;
}
	
	// ********************************
	//@name	Mui
	// ********************************
int CNodeContainer::set( const CNodeContainer::ElementType& element , int iIndex ) 
{
	if ( iIndex == INT_MAX )
	{
		iIndex = (int)m_contCNode.size() - 1 ;
	}
	if ( !( 0 <= iIndex && iIndex < (int)m_contCNode.size() ) ) 
	{
		return -1 ;
	}

	//modify container
	m_contCNode[iIndex] = element->clone() ;

	m_CInNameIndexContainer.erase( iIndex ) ;
	m_CInNameIndexContainer.insert( element->getName() , iIndex ) ;

	return 0 ;
}

int CNodeContainer::insert( const CNodeContainer::ElementType& element , int iIndex  ) 
{
	if ( iIndex == INT_MAX )
	{
		iIndex = (int)m_contCNode.size() ;
	}
	if ( !( 0 <= iIndex && iIndex <= (int)m_contCNode.size() ) ) 
	{
		return -1 ;
	}

	//modify container
	m_contCNode.insert( m_contCNode.begin() + iIndex , 
		element->clone() ) ;

	m_CInNameIndexContainer.insert( element->getName() , iIndex ) ;

	return 0 ;
}
int CNodeContainer::erase( int iIndex  , int iSize  ) 
{
	if ( iIndex == INT_MAX && iSize == INT_MAX )
	{
		return -1 ;
	}
	if ( iIndex == INT_MAX )
	{
		iIndex = (int)m_contCNode.size() - iSize ;
	}
	if ( iSize == INT_MAX )
	{
		iSize = (int)m_contCNode.size() - iIndex ;
	}
	if ( !( 0 <= iIndex && iIndex+iSize <= (int)m_contCNode.size() ) ) 
	{
		return -1 ;
	}

	//modify container
	m_contCNode.erase( 
		m_contCNode.begin() + iIndex ,
		m_contCNode.begin() + iIndex + iSize ) ;

	m_CInNameIndexContainer.erase( iIndex , iSize ) ;

	return 0 ;
}
	

int	CNodeContainer::sizeInName( const string& strName )const 
{
	return m_CInNameIndexContainer.sizeInName( strName ) ;

}
CNodeContainer::ElementType 
CNodeContainer::getInName( const string& strName , int iInNameIndex )const
{
	int iIndex = indexOfInNameIndex( strName , iInNameIndex ) ;
	if ( !( 0 <= iIndex && iIndex < (int)m_contCNode.size() ) )
	{
		return Ou<CNode>() ;
	}
	return m_contCNode[iIndex] ;
}
int CNodeContainer::setInName( 
		const ElementType& element , 
		int iInNameIndex ) 
{
	int iIndex = indexOfInNameIndex( element->getName() , iInNameIndex ) ;
	if ( !( 0 <= iIndex && iIndex < (int)m_contCNode.size() ) )
	{
		return -1 ;
	}

	//modify container
	m_contCNode[iIndex] = element->clone() ;

	m_CInNameIndexContainer.erase( iIndex ) ;
	m_CInNameIndexContainer.insert( element->getName() , iIndex ) ;
	return 0 ;
}

int CNodeContainer::insertInName( 
		const ElementType& element , 
		int iInNameIndex ) 
{
	if ( iInNameIndex == INT_MAX )
	{
		iInNameIndex = sizeInName( element->getName() ) ;
	}
	if ( !( 0 <= iInNameIndex && iInNameIndex <= sizeInName( element->getName() ) ) )
	{
		return -1 ;
	}
	// --------------------------------
	int iIndex = indexOfInNameIndex( element->getName() , iInNameIndex ) ;
	if ( iIndex < 0 )
	{
		if ( 0 == sizeInName( element->getName() ) )
		{
			iIndex = (int)m_contCNode.size()  ;
		}
		else
		{
			iIndex = indexOfInNameIndex( 
				element->getName() , 
				sizeInName( element->getName() ) - 1 ) + 1 ;
		}
	}

	//modify container
	m_contCNode.insert( 
		m_contCNode.begin() + iIndex , element->clone() ) ;

	m_CInNameIndexContainer.insert( element->getName() , iIndex ) ;

	return 0 ;
}
int CNodeContainer::eraseInName( const string& strName , 
		int  iInNameIndex  , int iSize ) 
{
	if ( iInNameIndex == INT_MAX && iSize == INT_MAX )
	{
		return -1 ;
	}
	if ( iInNameIndex == INT_MAX )
	{
		iInNameIndex = sizeInName( strName ) - iSize ;
	}
	if ( iSize == INT_MAX )
	{
		iSize = sizeInName( strName ) - iInNameIndex ;
	}
	if ( !( 0 <= iInNameIndex && iInNameIndex+iSize <= sizeInName( strName ) ) ) 
	{
		return -1 ;
	}
	// --------------------------------
	for ( iSize-- ; iSize >= 0 ; iSize -- )
	{
		int iIndex = indexOfInNameIndex( strName , iInNameIndex + iSize ) ;
		
		//modify container
		m_contCNode.erase( 
			m_contCNode.begin() + iIndex ) ;

		m_CInNameIndexContainer.erase( iIndex ) ;
	}
	return 0 ;
}

int CNodeContainer::indexOfInNameIndex( 
		const string& strName ,
		int iInNameIndex )const 
{
	int iInNameIndexCurr = -1 ;
	if ( !( 0 <= iInNameIndex && iInNameIndex < sizeInName( strName ) ) )
	{
		return -1 ;
	}
	return m_CInNameIndexContainer.indexOfInNameIndex( strName , iInNameIndex ) ;

}
int CNodeContainer::indexToInNameIndex( 
		int iIndex )const 
{
	int iInNameIndexCurr = 0 ;
	if ( !( 0 <= iIndex && iIndex < (int)m_contCNode.size() ) )
	{
		return -1 ;
	}
	// --------------------------------
	return m_CInNameIndexContainer.indexToInNameIndex( 
		m_contCNode[iIndex]->getName() , 
		iIndex ) ;
}


} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{
