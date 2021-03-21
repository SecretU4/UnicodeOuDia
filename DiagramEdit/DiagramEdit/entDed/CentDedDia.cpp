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
//	CentDedDia.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CentDedDia.h"
#include "CentDedDiaCont.h"

using namespace std ;

#ifdef _MFC_VER 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif


namespace entDed{

// ****************************************************************
//	CentDedDia
// ****************************************************************

// ********************************
//	コンストラクタ
// ********************************
CentDedDia::CentDedDia(const string& strName  )
: m_strName( strName ) 
{
	m_CentDedRessyaCont[0] = new CXRessyaCont( 
		this , 
		Ressyahoukou_Kudari ) ;
	m_CentDedRessyaCont[1] = new CXRessyaCont( 
		this , 
		Ressyahoukou_Nobori ) ;
}

CentDedDia::CentDedDia( 
		int iEkiCount ) 
{
	m_CentDedRessyaCont[0] = new CXRessyaCont( 
		this , 
		iEkiCount , Ressyahoukou_Kudari ) ;
	m_CentDedRessyaCont[1] = new CXRessyaCont( 
		this , 
		iEkiCount , Ressyahoukou_Nobori ) ;
}

CentDedDia::CentDedDia( 
		const string& strName ,
		int iEkiCount ) :
	m_strName( strName ) 
{
	m_CentDedRessyaCont[0] = new CXRessyaCont( 
		this , 
		iEkiCount , Ressyahoukou_Kudari ) ;
	m_CentDedRessyaCont[1] = new CXRessyaCont( 
		this , 
		iEkiCount , Ressyahoukou_Nobori ) ;
}


CentDedDia::CentDedDia( const CentDedDia& value ) :
	m_strName( value.m_strName ) 
{
	m_CentDedRessyaCont[0] = new CXRessyaCont( this , *value.m_CentDedRessyaCont[0] ) ;
	m_CentDedRessyaCont[1] = new CXRessyaCont( this , *value.m_CentDedRessyaCont[1] ) ;
}

CentDedDia& CentDedDia::operator=( const CentDedDia& value )
{
	super::operator=( value ) ; 
	// --------------------------------
	CentDedDiaCont* pDiaCont = dynamic_cast<CentDedDiaCont*>( getParent() ) ;
	if ( pDiaCont != NULL )
	{
		/*
		△上書き(operator=): このオブジェクトが親オブジェクト CentDedDiaCont の子である場合で、代入元のダイヤ名が空文字列である場合、もしくは同じ名前のダイヤが CentDedDiaCont にある場合は例外スロー。
	　	  (代入元が、CentDedDiaCont::set()に渡すとエラーになるようなオブジェクトである場合は、代入は例外スローとします)
		*/
		int iResult = pDiaCont->setable( value , pDiaCont->getIndex( this ) ) ;
		if( iResult < 0 )
		{
			throw LException() ;
		}
	}

	// --------------------------------
	m_strName = value.m_strName ;
	*m_CentDedRessyaCont[0] = *value.m_CentDedRessyaCont[0] ;	
	*m_CentDedRessyaCont[1] = *value.m_CentDedRessyaCont[1] ;	
	
	return *this ;
}
		
CentDedDia::~CentDedDia()
{
	delete m_CentDedRessyaCont[0] ;
	delete m_CentDedRessyaCont[1] ;

}

	// ********************************
	//@name CChildBase-操作
	// ********************************
void CentDedDia::setParent( CParentBase* pParent )
{
	super::setParent( pParent ) ; 
	adjust() ;
}
	// ********************************
	//@name CentDedDia-属性
	// ********************************
void CentDedDia::setName( const std::string& value )
{
	//	△上書き(operator=): このオブジェクトが親オブジェクト CentDedDiaCont の子である場合で、
	//	ダイヤ名が空文字列である場合は例外スロー。
	if ( value.length() == 0 )
	{
		throw LException() ;
	}
	// --------------------------------
	CentDedDiaCont* pDiaCont = dynamic_cast<CentDedDiaCont*>( getParent() ) ;
	if ( pDiaCont != NULL )
	{
		/*
		△上書き(operator=): このオブジェクトが親オブジェクト CentDedDiaCont の子である場合で、
			もしくは同じ名前のダイヤが CentDedDiaCont にある場合は例外スロー。
		*/
		int iResult = pDiaCont->findCentDedDiaByName( value ) ;
		if( iResult >= 0 && iResult != pDiaCont->getIndex( this ) )
		{
			throw LException() ;
		}
	}
	// --------------------------------
	m_strName = value ; 
}





	// ********************************
	//@name CentDedDia-操作
	// ********************************
void CentDedDia::adjustByEkijikokukeisiki(
		const CentDedEkiCont* pCentDedEkiCont ,
		int iEkiIndex )
{
	int iRv = 0 ;

	//		INT_MAX は、末尾を指定したことになります。
	if ( iRv >= 0 )
	{
		if ( iEkiIndex == INT_MAX )
		{
			iEkiIndex = pCentDedEkiCont->size() - 1 ;
		}
		if ( !( 0 <= iEkiIndex && iEkiIndex < pCentDedEkiCont->size() ) )
		{
			iRv = -1 ;	//	iEkiIndex が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		for ( int iRessyahoukou = Ressyahoukou_Kudari ;
			iRessyahoukou <= Ressyahoukou_Nobori ;
			iRessyahoukou ++ )
		{
			ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;

			int iEkiOrder = pCentDedEkiCont->EkiOrderOfEkiIndex( eRessyahoukou , iEkiIndex ) ;
			CentDedEkiCont::CdDedEki aDedEki = pCentDedEkiCont->getMuPtr( eRessyahoukou )->get( iEkiOrder ) ;

			CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont( eRessyahoukou ) ;

			pCentDedRessyaCont->adjustByEkijikokukeisiki( iEkiOrder , 
				aDedEki.getChakujikokuHyouji() , 
				aDedEki.getHatsujikokuHyouji() ) ;

		}
	}
}

void CentDedDia::adjust()
{
	int iRessyahoukou = 0 ; 
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
			iRessyahoukou <= Ressyahoukou_Nobori ; 
			iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->adjust() ;
	}
}


	// ********************************
	//@name CentDedDia-駅数・列車種別数の変更
	// ********************************

int CentDedDia::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const
{
	int iRv = 0 ;
	ERessyahoukou eRessyahoukouFound = Ressyahoukou_Kudari ;
	int iRessyaIndexFound = -1 ;
	// --------------------------------
	if ( iRv >= 0 ){
			int iRessyahoukou = 0 ;
			for ( iRessyahoukou = Ressyahoukou_Kudari ; 
					iRv == 0 && iRessyahoukou <= Ressyahoukou_Nobori ; 
					iRessyahoukou ++ ){
				ERessyahoukou	eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
				
				iRv = m_CentDedRessyaCont[iRessyahoukou]->
					isExistRessyaOfRessyasyubetsu( 
						iRessyasyubetsuIndex , &iRessyaIndexFound ) ;
				if ( iRv == 1 ){
					eRessyahoukouFound = eRessyahoukou ;
				}
			}
	}
	// --------------------------------
	if ( peRessyahoukou != NULL ){
		*peRessyahoukou = eRessyahoukouFound ;
	}
	if ( piRessyaIndex != NULL ){
		*piRessyaIndex = iRessyaIndexFound ;
	}

	return ( iRv ) ;
}
	// ********************************
	//@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
void CentDedDia::onEkiInsert( int iEkiIndex )
{
	int iRessyahoukou = 0 ; 
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
			iRessyahoukou <= Ressyahoukou_Nobori ; 
			iRessyahoukou ++ ){
		if ( iRessyahoukou == Ressyahoukou_Kudari ){ 
			m_CentDedRessyaCont[iRessyahoukou]->onEkiInsert( 
				m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( 
					iEkiIndex ) 
			) ;
		}	else if ( iRessyahoukou == Ressyahoukou_Nobori ){ 
			m_CentDedRessyaCont[iRessyahoukou]->onEkiInsert( 
				m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( 
					iEkiIndex ) + 1 
			) ;
			//	この +1 の意味・・・
			//	４駅の路線に、始発駅である駅Index0を追加する場合、
			//	上りのコンテナの駅Order 4(末尾)  に追加しなくてはなりません。 
		}
	}
}

void CentDedDia::onEkiErase( int iEkiIndex  )
{
	int iRessyahoukou = 0 ; 
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
			iRessyahoukou <= Ressyahoukou_Nobori ; 
			iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onEkiErase( 
			m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( iEkiIndex ) ) ;
	}
}

void CentDedDia::onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex )
{
	int iRessyahoukou = 0 ;
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
		iRessyahoukou <= Ressyahoukou_Nobori ; iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onEkiTrackInsert( 
			m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( iEkiIndex ) , iEkiTrackIndex ) ;
	}
}

void CentDedDia::onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex )
{
	int iRessyahoukou = 0 ;
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
		iRessyahoukou <= Ressyahoukou_Nobori ; iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onEkiTrackErase( 
			m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( iEkiIndex ) , iEkiTrackIndex ) ;
	}
}

void CentDedDia::onRessyasyubetsuInsert( int iRessyasyubetsuIndex )
{
	int iRessyahoukou = 0 ;
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
		iRessyahoukou <= Ressyahoukou_Nobori ; iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onRessyasyubetsuInsert( iRessyasyubetsuIndex ) ;
	}
}

void CentDedDia::onRessyasyubetsuErase( int iRessyasyubetsuIndex )
{
	int iRessyahoukou = 0 ;
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
		iRessyahoukou <= Ressyahoukou_Nobori ; iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onRessyasyubetsuErase( iRessyasyubetsuIndex ) ;
	}
}



} //namespace entDed
