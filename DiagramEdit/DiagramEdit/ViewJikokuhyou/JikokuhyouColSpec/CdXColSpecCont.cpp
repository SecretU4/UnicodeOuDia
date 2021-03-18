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
// $Id: CdXColSpecCont.cpp 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
#pragma once

#include "stdafx.h"
#include "CdXColSpecCont.h"

namespace ViewJikokuhyou{ namespace JikokuhyouColSpec{


	// ********************************
	//	コンストラクタ
	// ********************************
CdXColSpecCont::CdXColSpecCont( 
		const CentDedRessyaCont* pCentDedRessyaCont ) 
	: m_eRessyahoukou( pCentDedRessyaCont->getRessyahoukou() ) 
	, m_iRessyaCount( 0 )
	, m_iColumnNumber_Ressya_begin( 0 ) 
	, m_iColumnNumber_Ressya_end( 0 ) 
{
	scan( pCentDedRessyaCont ) ;
}

CdXColSpecCont::CdXColSpecCont() 
	:m_eRessyahoukou( Ressyahoukou_Kudari) 
	, m_iRessyaCount( 0 ) 
	, m_iColumnNumber_Ressya_begin( 0 ) 
	, m_iColumnNumber_Ressya_end( 0 ) 
{
}



	// ********************************
	//@name 属性
	// ********************************
ERessyahoukou	CdXColSpecCont::getRessyahoukou()const 
{
	return m_eRessyahoukou ;
}
int CdXColSpecCont::getColumnNumber_Ressya_begin()const 
{
	return m_iColumnNumber_Ressya_begin ;
}
int CdXColSpecCont::
getColumnNumber_Ressya_end()const 
{
	return m_iColumnNumber_Ressya_end ;
}
	// ********************************
	//@name CdXColSpecCont-操作
	// ********************************
void CdXColSpecCont::scan( 
		const CentDedRessyaCont* pCentDedRessyaCont ) 
{

	m_eRessyahoukou = pCentDedRessyaCont->getRessyahoukou() ;
	m_iRessyaCount = pCentDedRessyaCont->size() ;

	//駅名
	m_contColumnSpec.insert( CdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ) ;
	//着発
	m_contColumnSpec.insert( CdXColSpec( 
		CdXColSpec::ColumnType_Chakuhatsu ) ) ;

	//	列車の先頭列の列番号
	m_iColumnNumber_Ressya_begin = m_contColumnSpec.size() ;

	//列車 は追加しません

	
	//	列車の終端列の次位の X列番号
	m_iColumnNumber_Ressya_end = m_iColumnNumber_Ressya_begin + m_iRessyaCount ;

	//新規列車追加位置
	m_contColumnSpec.insert( CdXColSpec( 
		CdXColSpec::ColumnType_NewRessya , 
		m_iRessyaCount ) ) ;
}


int CdXColSpecCont::size() 
{
	return m_contColumnSpec.size() + m_iRessyaCount ;
}

CdXColSpec CdXColSpecCont::ColumnNumberToSpec( 
		int iXColumnNumber ) 
{
	CdXColSpec	aRv ;
	if ( iXColumnNumber < 2 )
	{
		aRv = m_contColumnSpec.get( iXColumnNumber ) ;
	}
	else if ( 2 <= iXColumnNumber && 
		iXColumnNumber < 2 + m_iRessyaCount )
	{
		//	列車列
		aRv = CdXColSpec( CdXColSpec::ColumnType_Ressya , 
			iXColumnNumber -2 ) ;
	}
	else
	{
		//	列車列以降
		iXColumnNumber -= ( m_iRessyaCount ) ;
		if ( 0 <= iXColumnNumber && iXColumnNumber < m_contColumnSpec.size() )
		{
			aRv = m_contColumnSpec.get( iXColumnNumber ) ;
		}
	}
	return aRv ;
}

int CdXColSpecCont::ColumnNumberFromSpec( 
		const CdXColSpec& aCdXColSpec ) 
{
	int iRv = -1 ;
	{
		for ( int iColumnNumber = 0 ; 
			iRv == -1 && iColumnNumber < m_contColumnSpec.size() ;
			iColumnNumber ++ )
		{
			if ( aCdXColSpec == m_contColumnSpec.get( iColumnNumber ) )
			{
				iRv = iColumnNumber ;
			}
		}
		if ( aCdXColSpec.getColumnType() == CdXColSpec::ColumnType_NewRessya )
		{
			iRv += m_iRessyaCount ;
		}
	}
	if ( iRv == -1 && 
		aCdXColSpec.getColumnType() == 
			CdXColSpec::ColumnType_Ressya )
	{
		if ( 0 <= aCdXColSpec.getRessyaIndex() && 
			aCdXColSpec.getRessyaIndex() < m_iRessyaCount )
		{
			iRv = aCdXColSpec.getRessyaIndex() + 2 ;
		}
	}
	return iRv ;
}


void CdXColSpecCont::clear() 
{
	*this = CdXColSpecCont() ;
}

} } //namespace JikokuhyouColSpec namespace ViewJikokuhyou

