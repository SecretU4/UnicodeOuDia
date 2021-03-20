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
//	CentDedRessyaCont.cpp
// ****************************************************************
*/
#include "stdafx.h"

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

#include "Cont/CCont_deque.h"
#include "Cont/CaCont.h"
#include "CentDedRessyaCont.h"

// ****************************************************************
//	CentDedRessyaCont
// ****************************************************************
// --------------------------------
//@name CaContFilter-オーバライド可能な仮想関数
// --------------------------------
CentDedRessyaCont::adaptee_value_type 
CentDedRessyaCont::onSet( const value_type& value , int* piResult ) 
{
	CentDedRessya* pCentDedRessya = new CentDedRessya( m_iEkiCount , m_eRessyahoukou ) ;
	*pCentDedRessya = value ;

	//	挿入される列車の種別Indexが規定以上なら、０に変更
	if ( pCentDedRessya->getRessyasyubetsuIndex() >= m_iRessyasyubetsuCount ){
		pCentDedRessya->setRessyasyubetsuIndex( m_iRessyasyubetsuCount - 1 ) ;
	}

	return ( pCentDedRessya ) ;
}	
CentDedRessyaCont::value_type 
CentDedRessyaCont::onGet( const adaptee_value_type& value )const 
{
	return ( *value ) ;
}
void CentDedRessyaCont::onErase( const adaptee_value_type& value ) 
{
	delete value ;
}


// ********************************
//	コンストラクタ
// ********************************
CentDedRessyaCont::CentDedRessyaCont( 
		int iEkiCount ,
		ERessyahoukou eRessyahoukou , 
		int iRessyasyubetsuCount )
	: super( new CCont_deque< CentDedRessya* > ) 
	, m_iEkiCount( iEkiCount ) 
	, m_eRessyahoukou( eRessyahoukou )
	, m_iRessyasyubetsuCount( iRessyasyubetsuCount ) 
{
}


CentDedRessyaCont::CentDedRessyaCont( const CentDedRessyaCont& value )
	: super( new CCont_deque< CentDedRessya* > ) 
	, m_iEkiCount( value.m_iEkiCount ) 
	, m_eRessyahoukou( value.m_eRessyahoukou ) 
	, m_iRessyasyubetsuCount( value.m_iRessyasyubetsuCount ) 
{
	//	value の列車を、thisにコピーしています。
	CaCont< CentDedRessya >	aCaCont_this( this ) ;
	aCaCont_this.insert( &value ) ;

}
	
CentDedRessyaCont& CentDedRessyaCont::operator=( const CentDedRessyaCont& value )
{
	//	保持している列車を、すべて破棄します。
	erase( 0 , INT_MAX ) ;
	//	value の列車を、thisにコピーしています。
	CaCont< CentDedRessya >	aCaCont_this( this ) ;
	aCaCont_this.insert( &value ) ;

	return *this ;
}

CentDedRessyaCont::~CentDedRessyaCont()
{
	erase( 0 , INT_MAX ) ;
	
	IfCont< CentDedRessya* >* pAdaptee = getAdaptee() ;
	setAdaptee( NULL ) ;
	delete pAdaptee ;
/*
	//	『列車』オブジェクトを削除します。
	{
		while ( m_CentDedRessyaCont.size() > 0 ){
			CentDedRessya*	pCentDedRessya = m_CentDedRessyaCont.back() ;
			m_CentDedRessyaCont.pop_back() ;
			delete pCentDedRessya ;
		}
	}
*/
}

// ********************************
//	CentDedRessyaCont
// ********************************
int CentDedRessyaCont::insertBlank( int iIndex )
{
	return ( super::insert( CentDedRessya( m_iEkiCount , m_eRessyahoukou ) , iIndex ) ) ;
}
	

int CentDedRessyaCont::EkiIndexOfEkiOrder( int iEkiOrder ) 
{
	int iRv = iEkiOrder ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_iEkiCount - 1 - iEkiOrder ;
	}
	return ( iRv ) ;
}

int CentDedRessyaCont::EkiOrderOfEkiIndex( int iEkiIndex ) 
{
	int iRv = iEkiIndex ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_iEkiCount - 1 - iEkiIndex ;
	}
	return ( iRv ) ;
}


// --------------------------------
//@name CentDedRessya 内の 
//	CentDedEkiJikoku を増減
// --------------------------------
int CentDedRessyaCont::onSetCentDedEki( const IfContGet<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder ) 
{
	int iRv = 0 ;

	IfContGet<CentDedRessya*>*	pIfContGet = getIfContGet() ;
	if ( iRv >= 0 ){
		int idxRessya = 0 ;
		for ( idxRessya = 0 ; 
				idxRessya < pIfContGet->size() ;
				idxRessya ++ ){
			CentDedRessya*	pCentDedRessya = pIfContGet->get( idxRessya ) ;

			iRv = pCentDedRessya->onSetCentDedEki( 
					pCentDedEkiCont , 
					iEkiOrder ) ;
				//-1 ; // インデクスが不正です。 
		}
	}
	return ( iRv ) ;
}

int CentDedRessyaCont::insertCentDedEkiJikoku(	int iEkiOrder ) 
{
	int iRv = 0 ;

	IfContGet<CentDedRessya*>*	pIfContGet = getIfContGet() ;
	if ( iRv >= 0 ){
		m_iEkiCount ++ ;
		int idxRessya = 0 ;
		for ( idxRessya = 0 ; 
				idxRessya < pIfContGet->size() ;
				idxRessya ++ ){
			CentDedRessya*	pCentDedRessya = pIfContGet->get( idxRessya ) ;

			iRv = pCentDedRessya->insertCentDedEkiJikoku( 
					CentDedEkiJikoku() , 
					iEkiOrder ) ;
				//-1 ; // インデクスが不正です。 
		}
	}
	return ( iRv ) ;
}
	
int CentDedRessyaCont::eraseCentDedEkiJikoku( int iEkiOrder ) 
{
	int iRv = 0 ;
	IfContGet<CentDedRessya*>*	pIfContGet = getIfContGet() ;
	if ( iRv >= 0 ){
		m_iEkiCount -- ;

		int idxRessya = 0 ;
		for ( idxRessya = 0 ; 
				idxRessya < pIfContGet->size() ;
				idxRessya ++ ){
			CentDedRessya*	pCentDedRessya = pIfContGet->get( idxRessya ) ;
			iRv = pCentDedRessya->eraseCentDedEkiJikoku( iEkiOrder ) ;
			//-1 ; // インデクスが不正です。 
		}
	}
	return ( iRv ) ;
}
int CentDedRessyaCont::insertRessyasyubetsuIndex( int iRessyasyubetsuIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndex == INT_MAX ){
			iRessyasyubetsuIndex = m_iRessyasyubetsuCount ;
		}
		if ( !( 0 <= iRessyasyubetsuIndex && 
				iRessyasyubetsuIndex <= m_iRessyasyubetsuCount ) ){
			iRv = -1 ;	//	インデクスが不正
		}
	}
	// --------------------------------
	if ( iRv >= 0 ){
				IfContGet< CentDedRessya* >* pCentDedRessyaContGet = getIfContGet() ;
	
				int iRessyaCount = pCentDedRessyaContGet->size() ;
				int iRessyaIndex ;
				for ( iRessyaIndex = 0 ; iRessyaIndex < iRessyaCount ; iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					if ( iRessyasyubetsuIndexCurr >= iRessyasyubetsuIndex ){
						iRessyasyubetsuIndexCurr ++ ;
						pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;
					} 
				}
				m_iRessyasyubetsuCount ++ ;
	}
	return ( iRv ) ;
	
	
}
	
int CentDedRessyaCont::eraseRessyasyubetsuIndex( int iRessyasyubetsuIndex ) 
{
	int iRv = 0 ;

	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndex == INT_MAX ){
			iRessyasyubetsuIndex = m_iRessyasyubetsuCount - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndex && 
				iRessyasyubetsuIndex < m_iRessyasyubetsuCount ) ){
			iRv = -1 ;	//	インデクスが不正
		}
	}
	if ( iRv >= 0 ){
		if ( isExistRessyaOfRessyasyubetsu( 
			iRessyasyubetsuIndex , NULL ) > 0 ){
			iRv = -3 ;	//	『列車種別』が iRessyasyubtsuIndex の列車が存在します。
		}
	}
	// --------------------------------
	if ( iRv >= 0 ){
				IfContGet< CentDedRessya* >* pCentDedRessyaContGet = getIfContGet() ;
				int iRessyaCount = pCentDedRessyaContGet->size() ;

				int iRessyaIndex ;
				for ( iRessyaIndex = 0 ; iRessyaIndex < iRessyaCount ; iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					if ( iRessyasyubetsuIndexCurr > iRessyasyubetsuIndex ){
						iRessyasyubetsuIndexCurr -- ;
						pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;
					}	else if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndex ){
						iRessyasyubetsuIndexCurr = 0 ;
						pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;
					} 
				}
				
				m_iRessyasyubetsuCount -- ;
	}
	return ( iRv ) ;
	
}

int CentDedRessyaCont::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piRessyaIndex ) 
{
	int iRv = 0 ;
	IfContGet< CentDedRessya* >* pCentDedRessyaContGet = getIfContGet() ;

	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndex == INT_MAX ){
			iRessyasyubetsuIndex = m_iRessyasyubetsuCount - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndex && 
				iRessyasyubetsuIndex < m_iRessyasyubetsuCount ) ){
			iRv = -1 ;	//	インデクスが不正
		}
	}
	
	int iRessyaIndexFound = -1 ;
	if ( iRv >= 0 ){
	
				IfContGet< CentDedRessya* >* pCentDedRessyaContGet = getIfContGet() ;
				int iRessyaCount = pCentDedRessyaContGet->size() ;

				int iRessyaIndex ;
				for ( iRessyaIndex = 0 ; 
						iRv == 0 && iRessyaIndex < iRessyaCount ; 
						iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					// --------------------------------
					if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndex ){
						iRessyaIndexFound = iRessyaIndex ;
						iRv = 1 ;	//	指定の列車種別の列車が存在します。
					}
				}
	}
	// --------------------------------
	if ( iRv == 1 ){
		if ( piRessyaIndex != NULL ){
			*piRessyaIndex = iRessyaIndexFound ;
		}
	}
	
	return ( iRv ) ;
}

