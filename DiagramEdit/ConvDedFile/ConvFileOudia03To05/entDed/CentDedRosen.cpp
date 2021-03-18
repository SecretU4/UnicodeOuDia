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
//	CentDedRosen.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include <assert.h>

#include "Cont/CaCont.h" 
#include "CentDedRosen.h"


const char nameRessyasyubetsuDefault[] = "普通" ; 

// ----------------------------------------------------------------
//	CentDedRosen::CXCentDedEkiCont
// ----------------------------------------------------------------
	// ********************************
	//	コンストラクタ
	// ********************************
CentDedRosen::CXCentDedEkiCont::CXCentDedEkiCont( CentDedRosen* pCentDedRosen ) :
	m_pCentDedRosen( pCentDedRosen ) 
{
	CentDedDiaCont* pCentDedDiaCont = &m_pCentDedRosen->m_CentDedDiaCont ;
	assert( pCentDedDiaCont->getRessyasyubetsuCount() == 0 ) ;
}


CentDedRosen::CXCentDedEkiCont::~CXCentDedEkiCont() 
{
}
		
	// ********************************
	//	IfCont
	// ********************************
int CentDedRosen::CXCentDedEkiCont::set (const CentDedEki& element, int iIndex) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX ){
			iIndex = size() - 1 ;
		}
		if ( !( 0 <= iIndex && iIndex < size() ) ){
			iRv = -1 ;
		}
	}	
	if ( iRv >= 0 ){
		iRv = super::set( element , iIndex ) ;
	}
	if ( iRv >= 0 ){
		m_pCentDedRosen->m_CentDedDiaCont.onSetCentDedEki( this , iIndex ) ;
	}
	return ( iRv ) ;
}


int CentDedRosen::CXCentDedEkiCont::insert( const CentDedEki& element , int iIndex )
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX ){
			iIndex = size() ;
		}
		if ( !( 0 <= iIndex && iIndex <= size() ) ){
			iRv = -1 ;
		}
	}	
	if ( iRv >= 0 ){
		iRv = super::insert( element , iIndex ) ;
	}
	if ( iRv >= 0 ){
		m_pCentDedRosen->m_CentDedDiaCont.insertCentDedEkiJikoku( iIndex ) ;
	}
	return ( iRv ) ;
}
int CentDedRosen::CXCentDedEkiCont::erase( int iIndex  , int iSize ) 
{
	int iRv = 0 ;
	
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX && iSize == INT_MAX ){
			iRv = -1 ;
		}	else if ( iIndex == INT_MAX ){
			iIndex = size() - iSize ;
		}	else if ( iSize == INT_MAX ){
			iSize = size() - iIndex ;
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= size() ) ){
			iRv = -1 ;
		}
	}	
	
	if ( iRv >= 0 ){
		iRv = super::erase( iIndex , iSize ) ;
	}
	if ( iRv >= 0 ){
		int cnt ;
		for ( cnt = 0 ; cnt < iSize ; cnt ++ ){ 
			m_pCentDedRosen->m_CentDedDiaCont.eraseCentDedEkiJikoku( iIndex + iSize - 1 - cnt ) ;
		}
	}
	return ( iRv ) ;
};

// ----------------------------------------------------------------
//	CentDedRosen::CXCentDedRessyasyubetsuCont
// ----------------------------------------------------------------
	// ********************************
	//	コンストラクタ
	// ********************************
CentDedRosen::CXCentDedRessyasyubetsuCont::
CXCentDedRessyasyubetsuCont( CentDedRosen* pCentDedRosen ) :
	m_pCentDedRosen( pCentDedRosen ) 
{
	CentDedDiaCont* pCentDedDiaCont = &m_pCentDedRosen->m_CentDedDiaCont ;
	assert( pCentDedDiaCont->getRessyasyubetsuCount() == 0 ) ;
}

CentDedRosen::CXCentDedRessyasyubetsuCont::~CXCentDedRessyasyubetsuCont() 
{
}
		
	// ********************************
	//	IfCont
	// ********************************
int CentDedRosen::CXCentDedRessyasyubetsuCont::
	insert( const CentDedRessyasyubetsu& element , int iIndex )
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX ){
			iIndex = size() ;
		}
		if ( !( 0 <= iIndex && iIndex <= size() ) ){
			iRv = -1 ;
		}
	}	
	if ( iRv >= 0 ){
		iRv = super::insert( element , iIndex ) ;
	}
	if ( iRv >= 0 ){
		m_pCentDedRosen->m_CentDedDiaCont.insertRessyasyubetsuIndex( iIndex ) ;
	}
	return ( iRv ) ;
}
int CentDedRosen::CXCentDedRessyasyubetsuCont::erase( int iIndex  , int iSize )
{
	int iRv = 0 ;
	
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX && iSize == INT_MAX ){
			iRv = -1 ;
		}	else if ( iIndex == INT_MAX ){
			iIndex = size() - iSize ;
		}	else if ( iSize == INT_MAX ){
			iSize = size() - iIndex ;
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= size() ) ){
			iRv = -1 ;
		}
	}	
	
	if ( iRv >= 0 ){
		int cnt ;
		for ( cnt = 0 ; iRv >= 0 && cnt < iSize ; cnt ++ ){ 
			if ( iRv >= 0 ){
				iRv = m_pCentDedRosen->m_CentDedDiaCont.eraseRessyasyubetsuIndex( iIndex + iSize - 1 - cnt ) ;
			}
			if ( iRv >= 0 ){
				super::erase( iIndex + iSize - 1 - cnt ) ;
			}
		}

	}
	return ( iRv ) ;
};


// ****************************************************************
//	CentDedRosen
// ****************************************************************

// ********************************
//	コンストラクタ
// ********************************
CentDedRosen::CentDedRosen() 
	: m_pCentDedEkiCont( NULL )
	, m_pCentDedRessyasyubetsuCont( NULL ) 
	, m_jikokuKitenJikoku( 0 , 0 , 0 ) 
	, m_iDiagramDgrYZahyouKyoriDefault( 60 )
	, m_CentDedDiaCont( 0 , 0 ) 
{
	m_pCentDedEkiCont = new CXCentDedEkiCont( this ) ;
	m_pCentDedRessyasyubetsuCont = new CXCentDedRessyasyubetsuCont( this ) ;

	//	『列車種別』は、少なくとも一つは存在しなくてはなりません。
	m_pCentDedRessyasyubetsuCont->insert( CentDedRessyasyubetsu( nameRessyasyubetsuDefault , ""  ) , INT_MAX ) ;
}
	

CentDedRosen::CentDedRosen( const CentDedRosen& value )
	: m_pCentDedEkiCont( NULL )
	, m_pCentDedRessyasyubetsuCont( NULL ) 
	, m_CentDedDiaCont( 0 , 0 ) 
{
	m_strName = value.m_strName ;
	m_jikokuKitenJikoku = value.m_jikokuKitenJikoku ;
	m_iDiagramDgrYZahyouKyoriDefault = value.m_iDiagramDgrYZahyouKyoriDefault ;
	m_strComment = value.m_strComment ;

	m_pCentDedEkiCont = new CXCentDedEkiCont( this ) ;
	m_pCentDedRessyasyubetsuCont = new CXCentDedRessyasyubetsuCont( this ) ;
	
	CaCont<CentDedEki>( m_pCentDedEkiCont ).insert( value.m_pCentDedEkiCont , 0 , INT_MAX , 0 ) ;
	CaCont<CentDedRessyasyubetsu>( m_pCentDedRessyasyubetsuCont ).insert( value.m_pCentDedRessyasyubetsuCont , 0 , INT_MAX , 0 ) ;
	m_CentDedDiaCont = value.m_CentDedDiaCont ;
}
	
CentDedRosen& CentDedRosen::operator=( const CentDedRosen& value )
{
	// --------------------------------
	//	それまでの値を破棄
	// --------------------------------

	//	clear() は、包含オブジェクトを削除した後、
	//	CentDedRessyasyubetsuCont をひとつ追加するため、
	//	デストラクタで呼び出すのには不適当です。
	m_CentDedDiaCont.erase( 0 , INT_MAX ) ;
	m_pCentDedRessyasyubetsuCont->erase( 0 , INT_MAX ) ;
	m_pCentDedEkiCont->erase( 0 , INT_MAX ) ;

	// --------------------------------
	//	値をコピー
	// --------------------------------
	
	m_strName = value.m_strName ;
	m_jikokuKitenJikoku = value.m_jikokuKitenJikoku ;
	m_iDiagramDgrYZahyouKyoriDefault = value.m_iDiagramDgrYZahyouKyoriDefault ;
	m_strComment = value.m_strComment ;

	CaCont<CentDedEki>( m_pCentDedEkiCont ).insert( value.m_pCentDedEkiCont , 0 , INT_MAX , 0 ) ;
	CaCont<CentDedRessyasyubetsu>( m_pCentDedRessyasyubetsuCont ).insert( value.m_pCentDedRessyasyubetsuCont , 0 , INT_MAX , 0 ) ;
	m_CentDedDiaCont = value.m_CentDedDiaCont ;

	return ( *this ) ;
}

CentDedRosen::~CentDedRosen() 
{
	//	clear() は、包含オブジェクトを削除した後、
	//	CentDedRessyasyubetsuCont をひとつ追加するため、
	//	デストラクタで呼び出すのには不適当です。
	
	
	m_CentDedDiaCont.erase( 0 , m_CentDedDiaCont.size() ) ;
	m_pCentDedRessyasyubetsuCont->erase( 0 , INT_MAX ) ;
	m_pCentDedEkiCont->erase( 0 , INT_MAX ) ;
	
	delete m_pCentDedRessyasyubetsuCont ;
	delete m_pCentDedEkiCont ;
}

	
// ********************************
//	CentDedRosen
// ********************************
	// ********************************
	//@name 属性
	// ********************************
	// ********************************
	//@name 包含-CentDedEki
	// ********************************
	
	// ********************************
	//@name 包含-CentDedRessyasyubetsu
	// ********************************
int CentDedRosen::swapRessyasyubetsu( int iRessyasyubetsuIndexA ,
		int iRessyasyubetsuIndexB ) 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndexA == INT_MAX ){
			iRessyasyubetsuIndexA = m_pCentDedRessyasyubetsuCont->size() - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndexA && 
				iRessyasyubetsuIndexA < m_pCentDedRessyasyubetsuCont->size() ) ){
			iRv = -1 ;	//	インデクスが不正

		}
	}
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndexB == INT_MAX ){
			iRessyasyubetsuIndexB = m_pCentDedRessyasyubetsuCont->size() - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndexB && 
				iRessyasyubetsuIndexB < m_pCentDedRessyasyubetsuCont->size() ) ){
			iRv = -1 ;	//	インデクスが不正

		}
	}
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndexA == iRessyasyubetsuIndexB ){
			iRv = -1 ;	//	インデクスが不正
		}
	}
	// --------------------------------
	//m_CentDedRessyasyubetsuCont の入れ替え
	if ( iRv >= 0 ){
		IfContGet<CentDedRessyasyubetsu*>*	pIfContGet = m_pCentDedRessyasyubetsuCont->getIfContGet() ;
		CentDedRessyasyubetsu	aCentDedRessyasyubetsuA = 
			*pIfContGet->get( iRessyasyubetsuIndexA ) ;
		CentDedRessyasyubetsu	aCentDedRessyasyubetsuB = 
			*pIfContGet->get( iRessyasyubetsuIndexB ) ;
		*pIfContGet->get( iRessyasyubetsuIndexA )  = 
			aCentDedRessyasyubetsuB ; 
		*pIfContGet->get( iRessyasyubetsuIndexB )  = 
			aCentDedRessyasyubetsuA ; 

		// --------------------------------
		//	列車の入れ替え
		// --------------------------------
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iDiaIndex < m_CentDedDiaCont.size() ; iDiaIndex ++ ){
			CentDedDia*	pCentDedDia = m_CentDedDiaCont.getIfContGet()->get( iDiaIndex ) ;
			int iRessyahoukou = 0 ;
			for ( iRessyahoukou = Ressyahoukou_Kudari ; 
					iRessyahoukou <= Ressyahoukou_Nobori ; 
					iRessyahoukou ++ ){
				ERessyahoukou	eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
				
				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getpCentDedRessyaCont( eRessyahoukou ) ;
				IfContGet< CentDedRessya* >* pCentDedRessyaContGet = pCentDedRessyaCont->getIfContGet() ;

				int iRessyaCount = pCentDedRessyaContGet->size() ;

				int iRessyaIndex ;
				//	iRessyasyubetsuIndexA -> -1 (仮の値)
				//	iRessyasyubetsuIndexB -> iRessyasyubetsuIndexA (仮の値)
				for ( iRessyaIndex = 0 ; 
						iRessyaIndex < iRessyaCount ; 
						iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndexA ){
						iRessyasyubetsuIndexCurr = -1 ;	//	仮の値
					}	else if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndexB ){
						iRessyasyubetsuIndexCurr = iRessyasyubetsuIndexA ;
					}
					pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;	
				}
				//	-1 (仮の値) ->iRessyasyubetsuIndexA 
				for ( iRessyaIndex = 0 ; 
						iRessyaIndex < iRessyaCount ; 
						iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					if ( iRessyasyubetsuIndexCurr == -1 ){	//	仮の値
						iRessyasyubetsuIndexCurr = iRessyasyubetsuIndexB ;
					}
					pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;	
				}
			}
		}
	}

	return ( iRv ) ;
}
	
	// ********************************
	//@name 包含-CentDedDia
	// ********************************

	// ********************************
	//@name 操作
	// ********************************
void CentDedRosen::clear() 
{
	m_strName.erase() ;
	m_jikokuKitenJikoku.setTime( 0 , 0 , 0 ) ;
	m_strComment.erase() ;

	m_CentDedDiaCont.erase( 0 , INT_MAX ) ;
	m_pCentDedRessyasyubetsuCont->erase( 1 , INT_MAX ) ;
	m_pCentDedEkiCont->erase( 0 , INT_MAX ) ;

	// --------------------------------
	{
		//	『列車種別』は、少なくとも一つは存在しなくてはなりません。
		m_pCentDedRessyasyubetsuCont->set( 
			CentDedRessyasyubetsu( nameRessyasyubetsuDefault , ""  ) , 0 ) ;
	}
};
