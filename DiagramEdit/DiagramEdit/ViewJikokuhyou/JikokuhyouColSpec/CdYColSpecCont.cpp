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
// $Id: CdYColSpecCont.cpp 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
#pragma once
#include "stdafx.h"
#include "CdYColSpecCont.h"

namespace ViewJikokuhyou{ namespace JikokuhyouColSpec{

	// ********************************
	//	コンストラクタ
	// ********************************
CdYColSpecCont::CdYColSpecCont( 
	const CentDedEkiCont* pCentDedEkiCont , 
	ERessyahoukou eRessyahoukou ,
	bool bDisplayAllJikoku ) 
	: m_eRessyahoukou( eRessyahoukou ) 
	, m_bDisplayAllJikoku( false )
	, m_iColumnNumber_Ekijikoku_begin( 0 ) 
	, m_iColumnNumber_Ekijikoku_end( 0 ) 
{
	scan( pCentDedEkiCont , eRessyahoukou , bDisplayAllJikoku ) ; 
}

CdYColSpecCont::CdYColSpecCont( ) 
	: m_eRessyahoukou( Ressyahoukou_Kudari ) 
	, m_bDisplayAllJikoku( false )
{
}

	// ********************************
	//@name CdYColSpec-関連
	// ********************************

	// ********************************
	//@name 属性
	// ********************************
ERessyahoukou	CdYColSpecCont::getRessyahoukou()const 
{
	return m_eRessyahoukou ;
}
bool CdYColSpecCont::getDisplayAllJikoku()const 
{
	return m_bDisplayAllJikoku ;
}

int CdYColSpecCont::getColumnNumber_Ekijikoku_begin()const
{
	return m_iColumnNumber_Ekijikoku_begin ;
}
int CdYColSpecCont::getColumnNumber_Ekijikoku_end()const 
{
	return m_iColumnNumber_Ekijikoku_end ;
}

	// ********************************
	//@name CdYColSpec-操作
	// ********************************
void CdYColSpecCont::scan( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou	eRessyahoukou ,
		bool bDisplayAllJikoku ) 
{
	// --------------------------------
	//	既存データの削除
	// --------------------------------
	clear() ;

	// --------------------------------
	//	『列番号-表示内容』の対応表を構築
	// --------------------------------
	//	列車番号
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Ressyabangou ) ) ;
	//	列車種別 
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Ressyasyubetsu ) ) ;
	//	列車名
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Ressyamei ) ) ;
	//	号数 
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Gousuu ) ) ;
	//	「号」表示 
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Gou ) ) ;

	//	駅時刻の先頭列の列番号。
	m_iColumnNumber_Ekijikoku_begin = m_contColumnSpec.size()  ;

	//	駅時刻
	{
		const Mu<CentDedEkiCont::CdDedEki>* muEki = 
			pCentDedEkiCont->getMuPtr( eRessyahoukou ) ;

		for( int iEkiOrder = 0 ; 
			iEkiOrder < muEki->size() ; iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki	aEki = muEki->get( iEkiOrder ) ;

			//	着時刻表示あり または[全時刻を表示] モードなら、着時刻列を追加
			if ( aEki.getChakujikokuHyouji() || bDisplayAllJikoku )
			{
				m_contColumnSpec.insert( 
					CdYColSpec( CdYColSpec::ColumnType_Ekijikoku_Chaku , iEkiOrder ) ) ;
			}
			//	発時刻表示あり または[全時刻を表示] モードなら、発時刻列を追加
			if ( aEki.getHatsujikokuHyouji() || bDisplayAllJikoku )
			{
				m_contColumnSpec.insert( 
					CdYColSpec( CdYColSpec::ColumnType_Ekijikoku_Hatsu , iEkiOrder ) ) ;
			}
		}
	}
	/* 		駅時刻列の 終端(の次) の 列番号。*/
	m_iColumnNumber_Ekijikoku_end = m_contColumnSpec.size()  ;
	/**	備考 */
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Bikou ) ) ;
}



int CdYColSpecCont::size() 
{
	return m_contColumnSpec.size() ;
}

CdYColSpec CdYColSpecCont::ColumnNumberToSpec( int iYColumnNumber ) 
{
	CdYColSpec	aRv ;

	if ( 0 <= iYColumnNumber && iYColumnNumber < m_contColumnSpec.size() )
	{
		aRv = m_contColumnSpec.get( iYColumnNumber ) ;
	}

	return aRv ;
}




int CdYColSpecCont::ColumnNumberFromSpec( 
		const CdYColSpec& aCdYColumnSpec ,
		bool bResolveSameStation ) 
{
	int iRv = -1 ;
	// --------------------------------
	//	表示内容の一致する列を検索
	// --------------------------------
	for ( int iColumnNumber = 0 ; 
		iRv == -1 && iColumnNumber < m_contColumnSpec.size() ; 
		iColumnNumber ++ )
	{
		if ( m_contColumnSpec.get( iColumnNumber ) == aCdYColumnSpec )
		{
			iRv = iColumnNumber ;
		}
	}
	// --------------------------------
	//	対応する表示項目が非表示である場合、代わりの列番号を返します。
	// --------------------------------
	if ( iRv == -1 && bResolveSameStation )
	{
		//- aCdYColumnSpec が、ColumnType_Ressyabangou(列車番号)～ColumnType_Gou(「号」表示) 
		//までなら、ColumnType_Ressyabangou～ColumnType_Gou のうちのいずれかが見つかった
		//最初の列番号を返します。
		if ( aCdYColumnSpec.isRessyaProp() )
		{
			for ( int iColumnNumber = 0 ; 
				iRv == -1 && iColumnNumber < m_contColumnSpec.size() ; 
				iColumnNumber ++ )
			{
				if ( m_contColumnSpec.get( iColumnNumber ).isRessyaProp() )
				{
					iRv = iColumnNumber ;
				}
			}
		}
		//- aCdYColumnSpec が	ColumnType_Ekijikoku_Chaku(着時刻)ならば、
		//同じ駅Orderの ColumnType_Ekijikoku_Hatsu(発時刻)を返します。その列も非表示なら、
		//駅OrderがaCdYColumnSpec 未満で、ColumnType_Ekijikoku_Chaku か 
		//ColumnType_Ekijikoku_Hatsu の列のうち、一番大きい列番号を返します。
		//- aCdYColumnSpec が	ColumnType_Ekijikoku_Hatsu(発時刻)の場合も、
		//ColumnType_Ekijikoku_Chaku の場合と同様です。
		else if ( aCdYColumnSpec.isEkiJikoku() )
		{
			for ( int iColumnNumber = m_contColumnSpec.size() - 1 ;
				iRv == -1 && iColumnNumber >= 0 ;
				iColumnNumber -- )
			{
				CdYColSpec	aColumnSpecCurr = m_contColumnSpec.get( iColumnNumber ) ;
				if ( aColumnSpecCurr.isEkiJikoku() && 
					aColumnSpecCurr.getEkiOrder() <= aCdYColumnSpec.getEkiOrder() )
				{
					iRv = iColumnNumber ;
				}
			}
		}
		else if ( aCdYColumnSpec.getColumnType() == CdYColSpec::ColumnType_Bikou )
		{
			for ( int iColumnNumber = m_contColumnSpec.size() - 1 ;
				iRv == -1 && iColumnNumber >= 0 ;
				iColumnNumber -- )
			{
				CdYColSpec	aColumnSpecCurr = m_contColumnSpec.get( iColumnNumber ) ;
				if ( aColumnSpecCurr.getColumnType() != CdYColSpec::ColumnType_Bikou )
				{
					iRv = iColumnNumber ;
				}
			}
		}
	}

	return iRv ;
}

void CdYColSpecCont::clear() 
{
	m_eRessyahoukou = Ressyahoukou_Kudari ;
	m_bDisplayAllJikoku = false ;
	m_contColumnSpec.erase( 0 , INT_MAX ) ;
}
} } //namespace JikokuhyouColSpec namespace ViewJikokuhyou

