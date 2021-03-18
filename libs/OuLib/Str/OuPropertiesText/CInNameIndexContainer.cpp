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
/** @file */
//$Id: CInNameIndexContainer.cpp 286 2016-06-05 08:57:24Z okm $

#include "CInNameIndexContainer.h"

#include <deque>
#include <string>
#include <map>

namespace OuLib{
namespace Str{
namespace OuPropertiesText{


	// ********************************
	//	コンストラクタ
	// ********************************
CInNameIndexContainer::CInNameIndexContainer():
	m_iNodeCount( 0 ) 
{
}
CInNameIndexContainer::~CInNameIndexContainer()
{
}
	// ********************************
	//@name	Mu
	// ********************************
int	CInNameIndexContainer::size()const 
{
	return m_iNodeCount ;
}
	// ********************************
	//@name	Mui
	// ********************************
int CInNameIndexContainer::insert( const std::string& element , int iIndex ) 
{
	if ( iIndex == INT_MAX )
	{
		iIndex = m_iNodeCount ;
	}
	if ( !( 0 <= iIndex && iIndex <= m_iNodeCount ) ) 
	{
		return -1 ;
	}

	// --------------------------------
	// iIndex 以上の値を持つ Index はすべて加算
	// --------------------------------

	int iAddCount = m_iNodeCount - iIndex ;
	//iAddCount = iIndex以上の値を持つ m_NameIndexCont[][] の数
	//	この値は、 iIndex以上の値を見つけるたびに減算します。
	//	0になったら、この処理は中断します。

	for ( NameIndexCont::iterator ite = m_NameIndexCont.begin() ;
		0 < iAddCount && ite != m_NameIndexCont.end() ;
		ite ++ ) 
	{
		InNameIndexCont&	aInNameIndexCont = ite->second ;
		int idxInNameIndex ;
		for ( idxInNameIndex = 0 ;
			idxInNameIndex < (int)aInNameIndexCont.size() ;
			idxInNameIndex ++ ) 
		{
			if ( aInNameIndexCont[idxInNameIndex] >= iIndex )
			{
				aInNameIndexCont[idxInNameIndex] ++ ;
				iAddCount -- ;
			}
		}
	}

	// --------------------------------
	// iIndex を挿入
	// --------------------------------
	{
		NameIndexCont::iterator ite = m_NameIndexCont.find( element ) ;
		if ( ite == m_NameIndexCont.end() )
		{
			m_NameIndexCont[element] = InNameIndexCont() ;
		}
		InNameIndexCont&	aInNameIndexCont = m_NameIndexCont[element] ;
		int idxInNameIndex = -1 ;
		int idxLeft = 0 ;
		int idxRight = (int)aInNameIndexCont.size() - 1 ;
		while ( idxInNameIndex == -1 && idxLeft <= idxRight )
		{
			int iCentral = ( idxLeft + idxRight ) / 2 ;
			if ( aInNameIndexCont[iCentral] == iIndex )
			{
				idxInNameIndex = iCentral ;
			}
			else if ( iIndex <  aInNameIndexCont[iCentral] )
			{
				idxRight = iCentral - 1 ;
			}
			else if ( aInNameIndexCont[iCentral]  < iIndex )
			{
				idxLeft = iCentral + 1 ;
			}
		}
		//  3   5    7
		//	と並んでいる時に 4 を検索すると、
		//  L   C    R
		//  LCR
		//	となり、次は、
		//  CR  L
		//	となります。この場合は、挿入すべき位置はLの場所です
		//
		//  3   5    7
		//	と並んでいる時に 2 を検索すると、
		//  L   C    R
		//  LCR
		//	となり、次は、
		//R CL
		//	となります。この場合でも、挿入すべき位置はLの場所です
		//
		//  3   5    7
		//	と並んでいる時に 9 を検索すると、
		//  L   C    R
		//          LCR
		//	となり、次は、
		//          RC    L
		//	となります。この場合でも、挿入すべき位置はLの場所です
		//
		//
		if ( idxRight < idxLeft )
		{
			//	挿入位置を決定
			idxInNameIndex = idxLeft ;
		}
		aInNameIndexCont.insert( 
			aInNameIndexCont.begin() + idxInNameIndex , 
			iIndex ) ;
		m_iNodeCount ++ ;
	}

	return 0 ;
}
	
int CInNameIndexContainer::erase( int iIndex  , int iSize ) 
{
	if ( iIndex == INT_MAX && iSize == INT_MAX )
	{
		return -1 ;
	}
	if ( iIndex == INT_MAX )
	{
		iIndex = m_iNodeCount - iSize ;
	}
	if ( iSize == INT_MAX )
	{
		iSize = m_iNodeCount - iIndex ;
	}
	if ( !( 0 <= iIndex && iIndex+iSize <= m_iNodeCount ) ) 
	{
		return -1 ;
	}


	//iIndex 以上、iIndex + iSize 未満の値を削除
	//iIndex + iSize 以上の値は、 iSize を減算
	{
		for ( NameIndexCont::iterator ite = m_NameIndexCont.begin() ;
			ite != m_NameIndexCont.end() ;
			ite ++ ) 
		{
			InNameIndexCont&	aInNameIndexCont = ite->second ;
			int idxInNameIndex ;
			for ( idxInNameIndex = 0 ;
				idxInNameIndex < (int)aInNameIndexCont.size() ;
				idxInNameIndex ++ ) 
			{
				if ( iIndex <= aInNameIndexCont[idxInNameIndex] && 
					aInNameIndexCont[idxInNameIndex] < iIndex + iSize )
				{
					aInNameIndexCont.erase( 
						aInNameIndexCont.begin() + idxInNameIndex ) ;
					m_iNodeCount --;
					idxInNameIndex -- ;
				}
				else if ( iIndex + iSize <= aInNameIndexCont[idxInNameIndex] )
				{
					aInNameIndexCont[idxInNameIndex] -= iSize ;
				}
			}
		}
	}
	//	空のコンテナを削除
	{
		for ( NameIndexCont::iterator ite = m_NameIndexCont.begin() ;
			ite != m_NameIndexCont.end() ; ) 
		{
			InNameIndexCont&	aInNameIndexCont = ite->second ;
			if ( aInNameIndexCont.size() == 0 )
			{
				ite = m_NameIndexCont.erase( ite ) ;
			}
			else
			{
				ite ++ ;
			}
		}
	}
	return 0 ;
}
	// ********************************
	//@name	CNodeContainer-InNameIndexでのアクセス
	// ********************************
int	CInNameIndexContainer::sizeInName( const std::string& element )const 
{
	int iRv = 0 ;

	// iIndex を挿入
	{
		NameIndexCont::const_iterator ite = m_NameIndexCont.find( element ) ;
		if ( ite == m_NameIndexCont.end() )
		{
		}
		else
		{
			const InNameIndexCont&	aInNameIndexCont = ite->second ;
			iRv = (int)aInNameIndexCont.size() ;
		}
	}

	return iRv ;
}

int CInNameIndexContainer::indexOfInNameIndex( 
		const std::string& element ,
		int iInNameIndex )const 
{
	int iRv = 0 ;
	// iIndex を挿入
	{
		NameIndexCont::const_iterator ite = m_NameIndexCont.find( element ) ;
		if ( ite == m_NameIndexCont.end() )
		{
			iRv = -1 ;	//	インデクスが不正です。
		}
		else
		{
			const InNameIndexCont&	aInNameIndexCont = ite->second ;
			if ( iInNameIndex == INT_MAX )
			{
				iInNameIndex = (int)aInNameIndexCont.size() - 1 ;
			}
			
			if ( !( 0 <= iInNameIndex && iInNameIndex < (int)aInNameIndexCont.size() ) )
			{
				iRv = -1 ;	//	インデクスが不正です。
			}
			else
			{
				iRv = aInNameIndexCont[iInNameIndex] ;
			}
		}
	}
	return iRv ;

}
int CInNameIndexContainer::indexToInNameIndex( 
		const std::string& element ,
		int iIndex )const 
{
	if ( iIndex == INT_MAX )
	{
		iIndex = m_iNodeCount - 1 ;
	}
	if ( !( 0 <= iIndex && iIndex < m_iNodeCount ) ) 
	{
		return -1 ;
	}



	int iRv = 0 ;
	// iIndex を検索
	{
		
		NameIndexCont::const_iterator ite = m_NameIndexCont.find( element ) ;
		if ( ite == m_NameIndexCont.end() )
		{
			iRv = -1 ;
		}
		else
		{
			const InNameIndexCont&	aInNameIndexCont = ite->second ;

			int idxInNameIndex = -1 ;
			int idxLeft = 0 ;
			int idxRight = (int)aInNameIndexCont.size() - 1 ;
			while ( idxInNameIndex == -1 && idxLeft <= idxRight )
			{
				int iCentral = ( idxLeft + idxRight ) / 2 ;
				if ( aInNameIndexCont[iCentral] == iIndex )
				{
					idxInNameIndex = iCentral ;
				}
				else if ( iIndex <  aInNameIndexCont[iCentral] )
				{
					idxRight = iCentral - 1 ;
				}
				else if ( aInNameIndexCont[iCentral]  < iIndex )
				{
					idxLeft = iCentral + 1 ;
				}
			}
			iRv = idxInNameIndex ;
		}
	}

	return iRv ;



}


} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{
