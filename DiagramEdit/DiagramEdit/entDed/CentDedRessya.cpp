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
//	CentDedRessya.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include "CentDedRosen.h"
#include "CentDedRessya.h"
#include "CentDedRessyaCont.h"
#include "CentDedRessyasyubetsuCont.h"
#include "CdDedJikan.h"

#ifdef _MFC_VER 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

namespace entDed{



// ****************************************************************
//	CentDedRessya::CXEkiJikokuCont
// ****************************************************************
CentDedRessya* CentDedRessya::CXEkiJikokuCont::getRessya() 
{
	CentDedRessya* pOuter = (CentDedRessya*)( ((char*)this) - offsetof( CentDedRessya , m_CentDedEkiJikokuCont ) ) ;
	return pOuter ;
}

const CentDedRessya* CentDedRessya::CXEkiJikokuCont::getRessya()const
{
	const CentDedRessya* pOuter = (const CentDedRessya*)( ((char*)this) - offsetof( CentDedRessya , m_CentDedEkiJikokuCont ) ) ;
	return pOuter ;
}
// ****************************************************************


// ****************************************************************
//	CentDedRessya
// ****************************************************************


// ********************************
//	コンストラクタ
// ********************************
CentDedRessya::CentDedRessya( 
		int iEkiJikokuCount ,
		ERessyahoukou	eRessyahoukou ) :
	m_bIsNull( true ) ,
	m_eRessyahoukou( eRessyahoukou ) ,
	m_iRessyasyubetsuIndex( 0 )
{
	while ( (int)m_CentDedEkiJikokuCont.size() < iEkiJikokuCount ){
		m_CentDedEkiJikokuCont.insert( CentDedEkiJikoku() ) ;
	}
}

CentDedRessya& CentDedRessya::operator=( const CentDedRessya& value )
{
	super::operator=( value ) ; 
	// --------------------------------
	CentDedRessyaCont* pRessyaCont = dynamic_cast<CentDedRessyaCont*>( getParent() ) ;

	m_bIsNull = value.m_bIsNull ;

	//this が列車コンテナの一部である場合、『列車方向』 ( m_eRessyahoukou ) は変更しません。
	if ( pRessyaCont == NULL )
	{
		m_eRessyahoukou = value.m_eRessyahoukou ;
	}

	m_iRessyasyubetsuIndex = value.m_iRessyasyubetsuIndex ;
	m_strRessyabangou = value.m_strRessyabangou ;
	m_strRessyamei = value.m_strRessyamei;
	m_strGousuu = value.m_strGousuu;
	m_strBikou = value.m_strBikou;
	m_CentDedEkiJikokuCont =  value.m_CentDedEkiJikokuCont ;
	return *this ;
}

	// ********************************
	//@name CParentBase-操作
	// ********************************
void CentDedRessya::setParent( CParentBase* pParent )
{
	super::setParent( pParent ) ; 
	adjust() ;
}



	// ********************************
	//@name CentDedRessya-属性
	// ********************************
bool CentDedRessya::isNull()const 
{
	return ( m_bIsNull ) ;
}
CentDedRessya& CentDedRessya::setIsNull( bool value )
{
	m_bIsNull = value ;
	if ( value )
	{
		clear() ;
	}
	return *this ;
}

ERessyahoukou	CentDedRessya::getRessyahoukou()const
{
		return m_eRessyahoukou ;
};

int	CentDedRessya::getRessyasyubetsuIndex()const
{
		return m_iRessyasyubetsuIndex ; 
};
CentDedRessya& CentDedRessya::setRessyasyubetsuIndex( int value )
{
	//	列車が路線(CentDedRosen)の一部である場合は
	//	Rosenへのポインタを取得します。
	CentDedRosen* pRosen = NULL ;
	{
		CentDedRessyaCont* pRessyaCont = dynamic_cast<CentDedRessyaCont*>( getParent() ) ;
		if ( pRessyaCont != NULL ){	pRosen = pRessyaCont->getRosen() ;}
	}

	//△setRessyasyubetsuIndex: 列車が路線(CentDedRosen)の一部である場合で、
	//	列車種別Indexが列車種別コンテナ CentDedRessyasyubetsuCont に
	//	対応していない場合はエラー。
	if ( pRosen != NULL )
	{
		CentDedRessyasyubetsuCont* pRessyasyubetsuCont = pRosen->getCentDedRessyasyubetsuCont() ;
		if ( !( 0 <= value && value < pRessyasyubetsuCont->size() ) )
		{
			throw LException() ;
		}
	}
	// --------------------------------
	//	属性の更新
	m_bIsNull = false ;
	m_iRessyasyubetsuIndex = value ; 
	return *this ;
};
	
	// ********************************
	//@name 包含-CentDedEkiJikoku
	// ********************************

int CentDedRessya::getCentDedEkiJikokuCount()const 
{
	return ( (int)m_CentDedEkiJikokuCont.size() ) ;
}

CentDedEkiJikoku CentDedRessya::
getCentDedEkiJikoku( int iEkiOrder )const 
{
	CentDedEkiJikoku	aCentDedEkiJikoku ;
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( ( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ) ){

		aCentDedEkiJikoku = m_CentDedEkiJikokuCont.get( iEkiOrder ) ;
	}
	return ( aCentDedEkiJikoku ) ;
}


CentDedRessya& CentDedRessya::
setCentDedEkiJikoku( int iEkiOrder , const CentDedEkiJikoku& value ) 
{
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ){
		m_bIsNull = false ;
		m_CentDedEkiJikokuCont.set( value , iEkiOrder ) ;
	}
	return *this ;
}
	// ********************************
	//@name 『駅Order』単位の操作
	// ********************************
int CentDedRessya::EkiIndexOfEkiOrder( int iEkiOrder )const  
{
	int iRv = iEkiOrder ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = (int)m_CentDedEkiJikokuCont.size() - 1 - iEkiOrder ;
	}
	return ( iRv ) ;
}

int CentDedRessya::EkiOrderOfEkiIndex( int iEkiIndex ) const
{
	int iRv = iEkiIndex ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = (int)m_CentDedEkiJikokuCont.size() - 1 - iEkiIndex ;
	}
	return ( iRv ) ;
}


CentDedRessya& CentDedRessya::modifyCentDedEkiJikoku( 
	int iEkiOrder , 
	const CentDedEkiJikoku& value ) 
{
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ){
		m_bIsNull = false ;
	
		//	変更前の時刻を保存
		CdDedJikoku jikokuChakujikokuPrev = 
			m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrder )->getChakujikoku() ;
		CdDedJikoku jikokuHatsujikokuPrev = 
			m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrder )->getHatsujikoku() ;

		CdDedJikoku jikokuChakujikoku = value.getChakujikoku() ;
		CdDedJikoku jikokuHatsujikoku =  value.getHatsujikoku() ;
		
		//	駅時刻の変更
		m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrder )->set( 
			value.getEkiatsukai() , value.getChakujikoku() , value.getHatsujikoku() ) ;


		//	その後の時刻の繰上げ・繰下げ
		if ( !jikokuHatsujikoku.isNull() && !jikokuHatsujikokuPrev.isNull() )
		{
			//	発時刻が変更前・変更後も入力されている場合は、
			//	発時刻の入力前・入力後の差分を求めて、
			//	次の駅以降から繰下げを行います。
			CdDedJikan	aCdDedJikan = jikokuHatsujikoku.subJikoku( 
					jikokuHatsujikokuPrev ) ;
			modifyRessyaJikoku( 
				aCdDedJikan , 
				CdDedJikokuOrder( iEkiOrder + 1 , CdDedJikokuOrder::EkiJikokuItem_Chaku ) ) ;
		}
		else if ( !jikokuChakujikoku.isNull() && !jikokuChakujikokuPrev.isNull() )
		{
			//	発時刻による繰上げ・繰下げはできないが、
			//	着時刻が変更前・変更後も入力されている場合は、
			//	着時刻の差分を求めて、
			//	その駅の発時刻以降から繰下げを行います。
			CdDedJikan	aCdDedJikan = jikokuChakujikoku.subJikoku( 
					jikokuChakujikokuPrev ) ;
			modifyRessyaJikoku(
				aCdDedJikan , 
				CdDedJikokuOrder( iEkiOrder , CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ) ;
		}
	}
	return *this ;
}

int CentDedRessya::getSihatsuEki() const
{
	int	iRv = -1 ;
	// --------------------------------
	int iEkiOrder = 0 ;
	for ( iEkiOrder = 0 ; 
			iRv == -1 && 
			iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ; 
			iEkiOrder ++ ){
		const CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrder ) ;
		if ( pCentDedEkiJikoku->getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None ){
			iRv = iEkiOrder ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedRessya::setSihatsuEki( int iEkiOrder ) 
{
	int	iRv = 0 ;

	if ( iRv >= 0 ){
		if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	『駅Index』が不正です。
		}
	}

	// --------------------------------
	int iEkiOrderCurr = 0 ;
	for ( iEkiOrderCurr = 0 ; 
			iEkiOrderCurr < iEkiOrder; 
			iEkiOrderCurr ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrderCurr ) ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}
	{
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrderCurr ) ;
		if ( !pCentDedEkiJikoku->getHatsujikoku().isNull() ){
			//	発時刻が設定されている場合だけ
			//	着時刻を消去します。
			//	（発時刻が設定されていない場合に着時刻を
			//	消去してしまうと、その駅の駅時刻は
			//	運行なし Ekiatsukai_None になってしまうためです）
			pCentDedEkiJikoku->setChakujikoku( CdDedJikoku() ) ;
	
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedRessya::getSyuuchakuEki() const
{
	int	iRv = -1 ;
	// --------------------------------
	int iEkiOrder = 0 ;
	for ( iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ; 
			iRv == -1 && 
			iEkiOrder >= 0 ; 
			iEkiOrder -- )
	{
		const CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrder ) ;
		if ( pCentDedEkiJikoku->getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None )
		{
			iRv = iEkiOrder ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedRessya::setSyuuchakuEki( int iEkiOrder ) 
{
	int	iRv = 0 ;

	if ( iRv >= 0 ){
		if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	『駅Index』が不正です。
		}
	}

	// --------------------------------
	{
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrder ) ;
		if ( !pCentDedEkiJikoku->getChakujikoku().isNull() ){
			//	着時刻が設定されている場合だけ
			//	発時刻を消去します。
			//	（着時刻が設定されていない場合に発時刻を
			//	消去してしまうと、その駅の駅時刻は
			//	運行なし Ekiatsukai_None になってしまうためです）
			pCentDedEkiJikoku->setHatsujikoku( CdDedJikoku() ) ;

		}
	}
	int iEkiOrderCurr = 0 ;
	for ( iEkiOrderCurr = iEkiOrder + 1  ; 
			iEkiOrderCurr < (int)m_CentDedEkiJikokuCont.size() ; 
			iEkiOrderCurr ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrderCurr ) ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}
	// --------------------------------
	return ( iRv ) ;
}

bool CentDedRessya::isRunBetweenNextEki( int iEkiOrder )const 
{
	bool bRv = false ;
	if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() - 1 ) )
	{
		bRv = false ;	//	『駅Index』が不正です。
	}
	else
	{
		const CentDedEkiJikoku* pEkijikoku = m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrder ) ;
		const CentDedEkiJikoku* pEkijikokuNext = m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrder + 1 ) ;
		if ( 
			( pEkijikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya 
				|| pEkijikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
			&& ( pEkijikokuNext->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya 
				|| pEkijikokuNext->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
		)
		{
			bRv = true ;
		}

	}
	return bRv ;
}

int CentDedRessya::getRunFirstEkiOrder()const 
{
	int iRv = -1 ;
	for ( int iEkiOrder = 0 ; 
		iRv == -1 && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() - 1 ; 
		iEkiOrder ++ )
	{
		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			iRv = iEkiOrder ;
		}
	}
	return iRv ;
}
	
int CentDedRessya::getRunLastEkiOrder()const 
{
	int iRv = -1 ;
	for ( int iEkiOrder = (int)( m_CentDedEkiJikokuCont.size() ) - 2 ; 
		iRv == -1 && iEkiOrder >= 0 ; 
		iEkiOrder -- )
	{
		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			iRv = iEkiOrder + 1 ;
		}
	}
	return iRv ;
}

void CentDedRessya::adjustByEkijikokukeisiki(
		int iEkiOrder ,
		bool bChakujikokuHyouji , bool bHatsujikokuHyouji ) 
{
	if ( !m_bIsNull )
	{
		bool bSihatsuEki = ( getSihatsuEki() == iEkiOrder ) ;
		bool bSyuuchakuEki = ( getSyuuchakuEki() == iEkiOrder ) ;

		CentDedEkiJikoku aEkiJikoku = getCentDedEkiJikoku(iEkiOrder) ;
		aEkiJikoku.adjustByEkijikokukeisiki( 
			bChakujikokuHyouji , bHatsujikokuHyouji,
			bSihatsuEki , bSyuuchakuEki ) ;
		setCentDedEkiJikoku( iEkiOrder , aEkiJikoku ) ;
	}
}


	// ********************************
	//@name 『時刻Order』単位の操作
	// ********************************
CdDedJikokuOrder CentDedRessya::incJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder )const 
{
	CdDedJikokuOrder jikokuOrderRv = aJikokuOrder ;


	//	- aJikokuOrder の EkiOrder>=this.size() (最後の駅Orderの次) なら、@n
	//		aJikokuOrder をそのまま返します。
	//	- aJikokuOrder がNULL状態 なら、aJikokuOrder をそのまま返します。
	if ( !aJikokuOrder.getIsNull() && 
		aJikokuOrder.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() )
	{
		//	- aJikokuOrder が着時刻の場合は、同じ駅Orderの発時刻
		if ( jikokuOrderRv.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku )
		{
			jikokuOrderRv.setEkiOrder( jikokuOrderRv.getEkiOrder() , 
				CdDedJikokuOrder::EkiJikokuItem_Hatsu );
		}
		else if ( jikokuOrderRv.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
		{
			//- aJikokuOrder が発時刻の場合は、次の駅Orderの着時刻
			jikokuOrderRv.setEkiOrder( jikokuOrderRv.getEkiOrder() + 1 , 
				CdDedJikokuOrder::EkiJikokuItem_Chaku );
		}
	}
	return jikokuOrderRv ;
}

CdDedJikokuOrder CentDedRessya::decJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder )const 
{
	CdDedJikokuOrder jikokuOrderRv = aJikokuOrder ;

	//	- aJikokuOrder がNULL状態 なら、aJikokuOrder をそのまま返します。
	if ( !aJikokuOrder.getIsNull() )
	{ 
		//- aJikokuOrder の EkiOrder>=this.size() (最後の駅Orderの次) なら、@n
		//	最後の駅Orderの発時刻
		if ( aJikokuOrder.getEkiOrder() >= (int)m_CentDedEkiJikokuCont.size() )
		{
			jikokuOrderRv.setEkiOrder( (int)m_CentDedEkiJikokuCont.size() - 1, 
				CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ;
		}
		//- aJikokuOrder が発時刻の場合は、同じ駅Orderの着時刻
		else if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
		{
			jikokuOrderRv.setEkiOrder( aJikokuOrder.getEkiOrder() , 
				CdDedJikokuOrder::EkiJikokuItem_Chaku ) ; 
		}
		//- aJikokuOrder が着時刻の場合は、次の駅Orderの発時刻
		//- aJikokuOrder が EkiOrder=0 の着なら、NULL状態
		else if (  aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku )
		{
			jikokuOrderRv.setEkiOrder( aJikokuOrder.getEkiOrder() - 1 , 
				CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ; 
		}
	}
	return jikokuOrderRv ;
}



CdDedJikoku CentDedRessya::getEkiJikoku( CdDedJikokuOrder aJikokuOrder )const 
{
	CdDedJikoku	aCdDedJikoku ;
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= aJikokuOrder.getEkiOrder() && 
				aJikokuOrder.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	パラメータが不正
		}
	}
	if ( iRv >= 0 ){
		if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu ){
			aCdDedJikoku = 
				m_CentDedEkiJikokuCont.getMuPtr()->get( aJikokuOrder.getEkiOrder() )->getHatsujikoku() ;
		}	else	{
			aCdDedJikoku = 
				m_CentDedEkiJikokuCont.getMuPtr()->get( aJikokuOrder.getEkiOrder() )->getChakujikoku() ;
		}
	}
	return ( aCdDedJikoku ) ;
}

int CentDedRessya::setEkiJikoku( 
		const CdDedJikoku& aCdDedJikoku ,
		CdDedJikokuOrder aJikokuOrder ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= aJikokuOrder.getEkiOrder() && 
				aJikokuOrder.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	パラメータが不正
		}
	}
	if ( iRv >= 0 ){
		if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu ){
			m_CentDedEkiJikokuCont.getMuPtr()->get( aJikokuOrder.getEkiOrder() )->setHatsujikoku(
				aCdDedJikoku ) ;
		}	else	{
			m_CentDedEkiJikokuCont.getMuPtr()->get( aJikokuOrder.getEkiOrder() )->setChakujikoku(
				aCdDedJikoku ) ;
		}
	}
	return ( iRv ) ;
}

int CentDedRessya::modifyRessyaJikoku( 
	const CdDedJikan& aCdDedJikan , 
	const CdDedJikokuOrder& aJikokuOrder ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= aJikokuOrder.getEkiOrder() && 
				aJikokuOrder.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	パラメータが不正
		}
	}
	if ( iRv >= 0 ){
		CdDedJikokuOrder iJikokuOrderCurr ;
		for ( iJikokuOrderCurr = aJikokuOrder ;
			iJikokuOrderCurr.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() ;
			iJikokuOrderCurr = incJikokuOrder( iJikokuOrderCurr ) )
		{
			CdDedJikoku aCdDedJikoku = getEkiJikoku( iJikokuOrderCurr ) ;
			if ( !aCdDedJikoku.isNull() )
			{
				aCdDedJikoku = aCdDedJikoku.addSeconds( 
					aCdDedJikan.getTotalSeconds() ) ;
				setEkiJikoku( aCdDedJikoku , iJikokuOrderCurr ) ;
			}
		}
	}
	return ( iRv ) ;
	
}

CdDedJikokuOrder CentDedRessya::findrevJikoku( 
	const CdDedJikokuOrder& jikokuOrder )const 
{
	CdDedJikokuOrder aJikokuOrder = jikokuOrder ;
	CdDedJikokuOrder iRv  ;
	
	for ( ; 
		iRv.getIsNull() && aJikokuOrder.getEkiOrder() >= 0 ; 
		aJikokuOrder = decJikokuOrder(  aJikokuOrder ) )
	{
		CdDedJikoku	aCdDedJikoku = getEkiJikoku( aJikokuOrder ) ;
		if ( !aCdDedJikoku.isNull() )
		{
			iRv = aJikokuOrder ;
		}
	}
	return ( iRv ) ;
}
	
	
	// ********************************
	//@name 操作
	// ********************************



void CentDedRessya::clear() 
{
	m_bIsNull = true ;
	m_iRessyasyubetsuIndex = 0 ;
	m_strRessyabangou.erase() ;
	m_strRessyamei.erase() ;
	m_strGousuu.erase() ;
	m_strBikou.erase() ;	

	for ( int iEkiOrder = 0 ; 
			iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ; 
			iEkiOrder ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont.getMuPtr()->get( iEkiOrder ) ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}

}

void CentDedRessya::pasteEkiJikoku( const CentDedRessya& aCentDedRessyaSrc ) 
{
	
	int iEkiOrder = 0 ;
	for ( iEkiOrder = 0 ; 
		iEkiOrder < (int)m_CentDedEkiJikokuCont.size()  ; 
			iEkiOrder ++ )
	{
		CentDedEkiJikoku aCentDedEkiJikokuSrc = 
			aCentDedRessyaSrc.getCentDedEkiJikoku( iEkiOrder ) ;
		if ( aCentDedEkiJikokuSrc.getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None  )
		{
			CentDedEkiJikoku* pCentDedEkiJikokuDst = m_CentDedEkiJikokuCont.getMuPtr()->get(iEkiOrder) ;
			pCentDedEkiJikokuDst->setEkiatsukai( aCentDedEkiJikokuSrc.getEkiatsukai() ) ;
			
			if ( !aCentDedEkiJikokuSrc.getChakujikoku().isNull() )
			{
				pCentDedEkiJikokuDst->setChakujikoku( aCentDedEkiJikokuSrc.getChakujikoku() ) ;
			}
			if ( !aCentDedEkiJikokuSrc.getHatsujikoku().isNull() )
			{
				pCentDedEkiJikokuDst->setHatsujikoku( aCentDedEkiJikokuSrc.getHatsujikoku() ) ;
			}
			
		}
	}
}

int CentDedRessya::direct( 
		const CentDedRessya& aRessyaSihatsu ) 
{
	int iRv = 0 ;

	int iEkiOrderSyuuchaku = -1 ;
	int iEkiOrderSihatsu = -1 ;

	//	this列車の終着駅・始発列車の始発駅の取得
	if ( iRv >= 0 )
	{
		iEkiOrderSyuuchaku = getRunLastEkiOrder() ;
		iEkiOrderSihatsu = aRessyaSihatsu.getRunFirstEkiOrder() ;
		if ( iEkiOrderSyuuchaku == -1 )
		{
			iRv = -1 ;	//	この列車には駅時刻が指定されていません。
		}
		else if ( iEkiOrderSihatsu == -1 )
		{
			iRv = -2 ;	//	始発列車には駅時刻が指定されていません。
		}
		else if ( !( iEkiOrderSyuuchaku <= iEkiOrderSihatsu ) )
		{
			iRv = -3 ;	//	aRessyaSihatsu との直通化はできません。
			//aRessyaSihatsu の始発駅は、	this の終着駅と同じか、それ以降でなくてはなりません。
		}
	}
	//iEkiOrderSyuuchaku = this列車の終着駅の駅Order
	//iEkiOrderSihatsu = aRessyaSihatsu の始発駅の駅Order

	//	終着駅〜始発駅までの間は、経由なしとします。
	if ( iRv <= 0 )
	{
		for ( int iEkiOrder = iEkiOrderSyuuchaku + 1 ;
			iEkiOrder < iEkiOrderSihatsu ;
			iEkiOrder ++ )
		{
			setCentDedEkiJikoku( 
				iEkiOrder , 
				CentDedEkiJikoku( CentDedEkiJikoku::Ekiatsukai_Keiyunasi , CdDedJikoku() , CdDedJikoku() ) 
				);
		}
	}

	//	始発列車の始発駅
	//
	//始発駅の時刻(直通化した時刻)は、以下のようになります。
	//- 駅扱：変わりません。
	//- 着時刻：
	//  - this列車に着時刻が指定されていた場合：その着時刻
	//  - this列車に着時刻がなく、発時刻が指定されていた場合：途中駅止まり列車の発時刻
	//  - this列車に着時刻も発時刻も指定されていない場合：着時刻はなし
	//- 発時刻
	//  - 始発列車に発時刻が指定されていた場合：その発時刻を直通化した列車の発時刻とします。
	//  - 始発列車に発時刻がなく、着時刻が指定されていた場合：途中駅始発列車の着時刻を、新しい列車の発時刻とします。
	//  - 始発列車に着時刻も発時刻も指定されていない場合：発時刻はなし
	if ( iRv <= 0 )
	{
		CentDedEkiJikoku	aCentDedEkiJikokuSyuuchaku = getCentDedEkiJikoku( iEkiOrderSihatsu ) ;
		CentDedEkiJikoku	aCentDedEkiJikokuSihatsu = aRessyaSihatsu.getCentDedEkiJikoku( iEkiOrderSihatsu ) ;

		CentDedEkiJikoku	aCentDedEkiJikokuNew = aCentDedEkiJikokuSyuuchaku ;
		//- 着時刻：
		if ( !aCentDedEkiJikokuSyuuchaku.getChakujikoku().isNull() )
		{
			//　途中駅止まりの列車に着時刻が指定されていた場合：その着時刻
			aCentDedEkiJikokuNew.setChakujikoku( aCentDedEkiJikokuSyuuchaku.getChakujikoku() ) ;
		}
		else if ( !aCentDedEkiJikokuSyuuchaku.getHatsujikoku().isNull() )
		{
			//　途中駅止まりの列車に着時刻がなく、発時刻が指定されていた場合：途中駅止まり列車の発時刻
			aCentDedEkiJikokuNew.setChakujikoku( aCentDedEkiJikokuSyuuchaku.getHatsujikoku() ) ;
		}
		else
		{
			//　途中駅止まりの列車に着時刻も発時刻も指定されていない場合：着時刻はなし
			aCentDedEkiJikokuNew.setChakujikoku( CdDedJikoku() ) ;
		}


		//- 発時刻
		if ( !( aCentDedEkiJikokuSihatsu.getHatsujikoku().isNull() ) )
		{
			//  - 始発列車に発時刻が指定されていた場合：その発時刻を直通化した列車の発時刻とします。
			aCentDedEkiJikokuNew.setHatsujikoku( aCentDedEkiJikokuSihatsu.getHatsujikoku() ) ;
		}
		else if ( !( aCentDedEkiJikokuSihatsu.getChakujikoku().isNull() ) )
		{
			//  - 始発列車に発時刻がなく、着時刻が指定されていた場合：途中駅始発列車の着時刻を、新しい列車の発時刻とします。
			aCentDedEkiJikokuNew.setHatsujikoku( aCentDedEkiJikokuSihatsu.getChakujikoku() ) ;
		}
		else
		{
			//  - 始発列車に着時刻も発時刻も指定されていない場合：発時刻はなし
			aCentDedEkiJikokuNew.setHatsujikoku( CdDedJikoku() ) ;
		}
		setCentDedEkiJikoku( iEkiOrderSihatsu , aCentDedEkiJikokuNew ) ;
	}

	//	始発駅より後の駅の駅時刻
	if ( iRv <= 0 )
	{
		for ( int iEkiOrder = iEkiOrderSihatsu + 1 ; 
			iEkiOrder < (int)m_CentDedEkiJikokuCont.size()  ; 
				iEkiOrder ++ )
		{
			CentDedEkiJikoku	aCentDedEkiJikokuSihatsu = aRessyaSihatsu.getCentDedEkiJikoku( iEkiOrder ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikokuSihatsu ) ;
		}
	}

	//始発駅の列車情報(列車番号・列車名・号数・備考)は以下のようになります。
	//
	//- this列車が空文字列、始発列車が情報ありの場合、始発列車の情報を受け継ぎます。
	//- this列車が情報あり、始発列車が空文字列の場合、this列車の情報を受け継ぎます。
	//- this列車も始発列車も情報ありの場合、this列車の情報を受け継ぎます。
	if ( iRv <= 0 )
	{
		if ( m_strRessyabangou.length() == 0 && aRessyaSihatsu.getRessyabangou().length() > 0 )
		{
			m_strRessyabangou = aRessyaSihatsu.getRessyabangou() ;
		}
		if ( m_strRessyamei.length() == 0 && aRessyaSihatsu.getRessyamei().length() > 0 )
		{
			m_strRessyamei = aRessyaSihatsu.getRessyamei() ;
		}
		if ( m_strGousuu.length() == 0 && aRessyaSihatsu.getGousuu().length() > 0 )
		{
			m_strGousuu = aRessyaSihatsu.getGousuu() ;
		}
		if ( m_strBikou.length() == 0 && aRessyaSihatsu.getBikou().length() > 0 )
		{
			m_strBikou = aRessyaSihatsu.getBikou() ;
		}

	}	

	return iRv ;
}

int CentDedRessya::undirect(
		int iEkiOrder , 
		CentDedRessya* pCentDedRessyaSyuuchaku ,
		CentDedRessya* pCentDedRessyaSihatsu )const 
{
	int iRv = 0 ;


	//○途中駅止まり列車の終着駅Orderを決定
	//│([終着駅Orderの駅と終着駅Order-1の駅の間に列車運行がない]
	//│の条件が偽の間は、終着駅Order--する。
	//↓終着駅Orderが0ならエラー)
	//◇[終着駅Order==0]→エラー
	int iEkiOrderSyuuchaku = -1 ;
	if ( iRv >= 0 )
	{
		for ( iEkiOrderSyuuchaku = iEkiOrder ;
			iEkiOrderSyuuchaku > 0 && !isRunBetweenNextEki( iEkiOrderSyuuchaku - 1 ) ;
			iEkiOrderSyuuchaku -- )
		{
		}
		if ( iEkiOrderSyuuchaku == 0 )
		{
			iRv = -1 ;	//	指定の駅Orderでは、分断はできません
		}
	}

	//○途中駅始発列車の始発駅Indexを決定
	//│([始発駅Orderの駅と始発駅Order+1の駅の間に列車運行がない]
	//↓の条件が偽の間は、始発駅rOder++する。)
	//◇[始発駅Order==駅数-1]→エラー
	int iEkiOrderSihatsu = -1 ;
	if ( iRv >= 0 )
	{
		for ( iEkiOrderSihatsu = iEkiOrder ;
			iEkiOrderSihatsu < (int)m_CentDedEkiJikokuCont.size() - 1 && 
				!isRunBetweenNextEki( iEkiOrderSihatsu ) ;
			iEkiOrderSihatsu ++ )
		{
		}
		if ( iEkiOrderSihatsu == m_CentDedEkiJikokuCont.size() - 1 )
		{
			iRv = -1 ;	//	指定の駅Orderでは、分断はできません
		}
	}
	//○分断する列車のコピーを2つ作成。
	//↓これを途中駅止まり列車・途中駅始発列車とする。
	//○途中駅止まり列車の方を、終着駅Orderで当駅どまりにする
	//○途中駅始発列車の方を、始発駅Orderで当駅始発にする
	if ( iRv >= 0 )
	{
		*pCentDedRessyaSyuuchaku = *this ;
		pCentDedRessyaSyuuchaku->setSyuuchakuEki( iEkiOrderSyuuchaku ) ;
		*pCentDedRessyaSihatsu = *this ;
		pCentDedRessyaSihatsu->setSihatsuEki( iEkiOrderSihatsu ) ;
	}	

	return iRv ;
}

void CentDedRessya::adjust() 
{
	CentDedRessyaCont* pCentDedRessyaCont 
		= pCentDedRessyaCont = dynamic_cast<CentDedRessyaCont*>( getParent() ) ;
	CentDedRosen* pCentDedRosen = NULL ;
	if ( pCentDedRessyaCont != NULL )
	{
		pCentDedRosen = pCentDedRessyaCont->getRosen() ;
	}

	//△列車が親オブジェクト CentDedRessyaCont の一部である場合、
	//列車方向は、親オブジェクトである列車コンテナの列車方向と同一とします。
	if ( pCentDedRessyaCont != NULL )
	{
		m_eRessyahoukou = pCentDedRessyaCont->getRessyahoukou() ;	
	}

	//△列車種別IndexがCentDedRessyasyubetsuCont(列車種別コンテナ)の
	//範囲外である場合は、列車種別Indexは0とします。
	
	
	if ( pCentDedRosen != NULL )
	{
		CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont = pCentDedRosen->getCentDedRessyasyubetsuCont() ;

		if ( !( 0 <= m_iRessyasyubetsuIndex 
			&& m_iRessyasyubetsuIndex < pCentDedRessyasyubetsuCont->size() 
		) )
		{
			m_iRessyasyubetsuIndex = 0 ;
		}
	}
	//○CentDedEkiJikokuCont(駅時刻コンテナ)に、adjust()を委譲します。
	m_CentDedEkiJikokuCont.adjust() ;
}
	// ********************************
	//@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************

void CentDedRessya::onRessyasyubetsuInsert( int iRessyasyubetsuIndex )
{
	//△列車種別の追加(OnInsertRessyasyubetsu):　列車の列車種別インデクスは、コンテナへの追加に合わせてシフトさせる。
		
	if ( iRessyasyubetsuIndex <= m_iRessyasyubetsuIndex )
	{
		m_iRessyasyubetsuIndex ++ ;
	}
}

void CentDedRessya::onRessyasyubetsuErase( int iRessyasyubetsuIndex )
{
	//△列車種別の削除(OnEraseRessyasyubetsu):　列車の列車種別インデクスは、コンテナへの追加に合わせてシフトさせる。
	if ( iRessyasyubetsuIndex < m_iRessyasyubetsuIndex )
	{
		m_iRessyasyubetsuIndex -- ;
	}
	//  列車の列車種別インデクスが削除対象の場合、インデクスは0にする
	else if ( iRessyasyubetsuIndex == m_iRessyasyubetsuIndex )
	{
		m_iRessyasyubetsuIndex = 0 ;
	}
}


} //namespace entDed
