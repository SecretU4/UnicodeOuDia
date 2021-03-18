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
//	CentDedDgrDia.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include "CentDedDgrEki.h"
#include "CentDedDgrRessya.h"
#include "CentDedDgrDia.h"
#include "DcdCd\Pos\CLineFunc.h"
#include "logmsg/LogMsg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


namespace entDgr{
using namespace std ;

// ****************************************************************
//	CentDedDgrDia
// ****************************************************************
// --------------------------------
//@name readCentDedRosen() の下請関数
// --------------------------------
CentDedDgrEki::EDiagramRessyajouhouHyouji 
CentDedDgrDia::CentDedEki_to_CentDedDgrEki_EDiagramRessyajouhouHyouji( 
	CentDedEki::EDiagramRessyajouhouHyouji eValue )
{
	CentDedDgrEki::EDiagramRessyajouhouHyouji eRessyajouhouHyouji = 
		CentDedDgrEki::DiagramRessyajouhouHyouji_Origin ;
	switch( eValue )
	{
	case CentDedEki::DiagramRessyajouhouHyouji_Anytime:
		eRessyajouhouHyouji = CentDedDgrEki::DiagramRessyajouhouHyouji_Anytime ;
		break ;
	case CentDedEki::DiagramRessyajouhouHyouji_Not:
		eRessyajouhouHyouji = CentDedDgrEki::DiagramRessyajouhouHyouji_Not ;
		break ;
	}
	return eRessyajouhouHyouji ;
}

	/*
		readCentDedRosen() の下請関数です。
		(1)CentDedDgrDiaの属性を設定
	*/
void CentDedDgrDia::readCentDedRosen_01_updateCentDedDgrDiaProp(
		const CentDedRosen* pCentDedRosen ,
		const CentDedDia* pCentDedDia ) 
{
	m_strName = pCentDedDia->getName() ;
	m_iDgrXPosMin = pCentDedRosen->getKitenJikoku().getTotalSeconds() ;
	m_iDgrYSizeEkikanDefault = pCentDedRosen->getDiagramDgrYZahyouKyoriDefault() ;
}

void CentDedDgrDia::readCentDedRosen_02_updateEkiCont( 
		const Mu< const CentDedEki* >* pCentDedEkiCont , 
		const CentDedDia* pCentDedDia ) 
{
	LogMsg( "CentDedDgrDia::readCentDedRosen_updateEkiCont()" ); 

	int iRv = 0 ;
	// --------------------------------
	//	それまでの
	//	『ダイヤグラム駅』
	//	『ダイヤグラム列車』
	//	オブジェクトは破棄します。
	// --------------------------------
	if ( iRv >= 0 )
	{
		m_CentDedDgrEkiCont.erase( 0 , INT_MAX ) ;
		m_CentDedDgrRessyaCont[0].erase( 0 , INT_MAX ) ;
		m_CentDedDgrRessyaCont[1].erase( 0 , INT_MAX ) ;
	}

	// --------------------------------
	//	各駅の『ダイヤグラム駅』
	//	オブジェクトを生成
	// --------------------------------
	int iEkiIndex = 0 ;
	for ( iEkiIndex = 0 ; 
			iRv >= 0 && iEkiIndex < pCentDedEkiCont->size() ;
			iEkiIndex ++ )
	{
		LogMsg( "\tEkiIndex[%d]%s" ,
			iEkiIndex , 
			pCentDedEkiCont->get( iEkiIndex )->getEkimei().c_str() ) ;
		// --------------------------------
		//	下り列車の検索(終点は除く)
		// --------------------------------
		int iEkikanSaisyouSecKudari = 0 ;
		{
			const CentDedRessyaCont* pCentDedRessyaCont = 
					pCentDedDia->getCentDedRessyaCont( Ressyahoukou_Kudari ) ;
			int iEkiOrder = pCentDedRessyaCont->EkiOrderOfEkiIndex(	iEkiIndex ) ;
			if ( 0 <= iEkiOrder && iEkiOrder < pCentDedEkiCont->size() - 1 )
			{
				iEkikanSaisyouSecKudari = 
					pCentDedRessyaCont->findEkikanSaisyouSec( 
						iEkiOrder , NULL ) ;
			}
		}
		// --------------------------------
		//	上り列車の検索(終点は除く)
		// --------------------------------
		int iEkikanSaisyouSecNobori = 0 ;

		{
			const CentDedRessyaCont* pCentDedRessyaCont = 
					pCentDedDia->getCentDedRessyaCont( Ressyahoukou_Nobori ) ;
			int iEkiOrder = pCentDedRessyaCont->EkiOrderOfEkiIndex(	iEkiIndex ) - 1 ;
			if ( 0 <= iEkiOrder && iEkiOrder < pCentDedEkiCont->size() - 1 )
			{
				iEkikanSaisyouSecNobori = 
					pCentDedRessyaCont->findEkikanSaisyouSec( 
						iEkiOrder , NULL ) ;
			}
		}

		// --------------------------------
		LogMsg( "\tiEkikanSaisyouSecKudari=%d iEkikanSaisyouSecNobori=%d" , 
			iEkikanSaisyouSecKudari , iEkikanSaisyouSecNobori ) ;

		const CentDedEki* pCentDedEki = pCentDedEkiCont->get( iEkiIndex ) ;

		CentDedDgrEki	aCentDedDgrEki( 
			pCentDedEki->getEkimei() , 
			pCentDedEki->getEkikibo() == 
				CentDedEki::Ekikibo_Syuyou , 
			iEkikanSaisyouSecKudari , iEkikanSaisyouSecNobori , 
			m_iDgrYSizeEkikanDefault ,
			CentDedEki_to_CentDedDgrEki_EDiagramRessyajouhouHyouji( 
				pCentDedEki->getDiagramRessyajouhouHyoujiKudari() ) , 
			CentDedEki_to_CentDedDgrEki_EDiagramRessyajouhouHyouji(
				pCentDedEki->getDiagramRessyajouhouHyoujiNobori() ) 
		) ;
		
		m_CentDedDgrEkiCont.insert( aCentDedDgrEki ) ;


	}

	
	LogMsg( "CentDedDgrDia::readCentDedRosen_updateEkiCont()="  )  ;
	
}

void CentDedDgrDia::readCentDedRosen_03_updateMuRessyasyubetsu( 
		const Mu< const CentDedRessyasyubetsu* >* pMuRessyasyubetsu ) 
{
	// --------------------------------
	//	『列車種別』オブジェクトを破棄
	// --------------------------------
	m_MuCentDedDgrRessyasyubetsu.erase( 0 , INT_MAX ) ;

	// --------------------------------
	//	『列車種別』オブジェクトを
	//	生成
	// --------------------------------
	for ( int idx = 0 ; idx < pMuRessyasyubetsu->size() ; idx ++ )
	{
		const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = 
			pMuRessyasyubetsu->get( idx ) ;
		CentDedDgrRessyasyubetsu	aCentDedDgrRessyasyubetsu( 
			pCentDedRessyasyubetsu->getJikokuhyouMojiColor() ,
			pCentDedRessyasyubetsu->getCdDiagramLineStyle() ,
			pCentDedRessyasyubetsu->getStopMarkDrawType() ) ;
		m_MuCentDedDgrRessyasyubetsu.insert( aCentDedDgrRessyasyubetsu ) ;
	}
}

void CentDedDgrDia::readCentDedRosen_04_updateRessyaCont( 
		const CentDedRosen* pCentDedRosen , 
		const CentDedDia* pCentDedDia ) 
{
	LogMsg( "CentDedDgrDia::readCentDedRosen_updateRessyaCont()" )  ;


	// --------------------------------
	//	各列車の『ダイヤグラム列車』オブジェクトを
	//	生成
	// --------------------------------
	for ( int iRessyahoukou = Ressyahoukou_Kudari ;
			iRessyahoukou <= Ressyahoukou_Nobori ; 
			iRessyahoukou ++ )
	
	{
		ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
	
		const CentDedRessyaCont* pCentDedRessyaCont = 
			pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;
		const Mu<const CentDedRessya*>* pCentDedRessyaContGet = 
			pCentDedDia->getCentDedRessyaCont( eRessyahoukou )->getMuPtr() ;

		Mui< CentDedDgrRessya >*	pCentDedDgrRessyaCont = 
			getCentDedDgrRessyaCont( eRessyahoukou ) ;
		
		// --------------------------------
		//	列車を一旦クリア
		// --------------------------------
		pCentDedDgrRessyaCont->erase( 0 , INT_MAX );
		
		// --------------------------------
		//	列車オブジェクトを生成・追加
		// --------------------------------
		for ( int iRessyaIdx = 0 ; 
				iRessyaIdx < pCentDedRessyaContGet->size() ;
				iRessyaIdx ++ )
		{
			const CentDedRessya* pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIdx ) ;
			CentDedDgrRessya	aCentDedDgrRessya( 
				pCentDedRosen , this , pCentDedRessya ) ;
							
			pCentDedDgrRessyaCont->insert( aCentDedDgrRessya ) ;
		}
		
	}

	LogMsg( "CentDedDgrDia::readCentDedRosen_updateRessyaCont()=" )  ;
}


// ********************************
//	コンストラクタ
// ********************************
CentDedDgrDia::CentDedDgrDia() :
	m_iDgrXPosMin( 0 ) ,
	m_iDgrYSizeEkikanDefault( 60 )
{
}
CentDedDgrDia::~CentDedDgrDia() 
{
}
	
// ********************************
//	CentDedDgrDia
// ********************************


	// ********************************
	//@name 属性
	// ********************************
string	CentDedDgrDia::getName()const
{
	return m_strName ;
};
int CentDedDgrDia::getDgrXPosMin()const 
{
	return m_iDgrXPosMin ;
}
CentDedDgrDia& CentDedDgrDia::setDgrXPosMin( int value ) 
{
	m_iDgrXPosMin = value ;
	return *this ; 
}

int CentDedDgrDia::getDgrYSizeEkikanDefault()const
{
	return m_iDgrYSizeEkikanDefault ;
};

	// ********************************
	//@name 包含
	// ********************************
CentDedDgrEkiCont*	CentDedDgrDia::getCentDedDgrEkiCont()
{
	return &m_CentDedDgrEkiCont ;
}
const CentDedDgrEkiCont* CentDedDgrDia::getCentDedDgrEkiCont()const
{
	return &m_CentDedDgrEkiCont ;
}

Mui< CentDedDgrRessyasyubetsu >*	
CentDedDgrDia::getMuCentDedDgrRessyasyubetsu()
{
	return &m_MuCentDedDgrRessyasyubetsu ;
};

const Mu< const CentDedDgrRessyasyubetsu* >*
CentDedDgrDia::getMuCentDedDgrRessyasyubetsu()const
{
	return m_MuCentDedDgrRessyasyubetsu.getMuPtr() ;
};

Mui< CentDedDgrRessya >*	CentDedDgrDia::getCentDedDgrRessyaCont( 
		 ERessyahoukou eRessyahoukou ) 
{
	Mui< CentDedDgrRessya >*	pRv = NULL ;
	if ( eRessyahoukou == Ressyahoukou_Kudari ){
		pRv = &m_CentDedDgrRessyaCont[0] ;
	}	else	{
		pRv = &m_CentDedDgrRessyaCont[1] ;
	}
	return ( pRv ) ;
}


const Mu< const CentDedDgrRessya* >*	
	CentDedDgrDia::getCentDedDgrRessyaCont( 
		 ERessyahoukou eRessyahoukou )const 
{
	const Mu< const CentDedDgrRessya* >*	pRv = NULL ;
	if ( eRessyahoukou == Ressyahoukou_Kudari ){
		pRv = m_CentDedDgrRessyaCont[0].getMuPtr() ;
	}	else	{
		pRv = m_CentDedDgrRessyaCont[1].getMuPtr() ;
	}
	return ( pRv ) ;
}


	// ********************************
	//@name 操作
	// ********************************
void CentDedDgrDia::readCentDedRosen( 
		const CentDedRosen* pCentDedRosen , 
		const CentDedDia* pCentDedDia ) 
{
	int iRv = 0 ;
	
	//	(1)CentDedDgrDiaの属性を設定
	if ( iRv >= 0 )
	{
		readCentDedRosen_01_updateCentDedDgrDiaProp( 
			pCentDedRosen , 
			pCentDedDia ) ;
	}
	//(2)CentDedDgrEkiを生成
	//　CentDedDgrEkiの以下の属性を、CentDedEkiの属性から生成。
	if ( iRv >= 0 )
	{
		readCentDedRosen_02_updateEkiCont( 
			pCentDedRosen->getCentDedEkiCont()->getMuPtr() ,
			pCentDedDia ) ;
	}
	//	(3)CentDedDgrRessyasyubetsuを生成
	if ( iRv >= 0 ) 
	{
		readCentDedRosen_03_updateMuRessyasyubetsu( 
			pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ) ;
	}
	//	(4)CentDedDgrRessya,CentDedDgrEkiJikokuを生成
	if ( iRv >= 0 )
	{
		readCentDedRosen_04_updateRessyaCont( 
			pCentDedRosen , 
			pCentDedDia ) ;
	}
	
}

int CentDedDgrDia::EkiIndexOfEkiOrder( 
		ERessyahoukou eRessyahoukou , int iEkiOrder )const 
{
	int iEkiIndex = iEkiOrder ;
	if ( eRessyahoukou == Ressyahoukou_Nobori ){
		iEkiIndex = m_CentDedDgrEkiCont.size() - 1 - iEkiOrder ;
	}
	return ( iEkiIndex ) ;
}

int CentDedDgrDia::EkiOrderOfEkiIndex(  ERessyahoukou eRessyahoukou , 
		int iEkiIndex )const 
{
	int iEkiOrder = iEkiIndex ;
	if ( eRessyahoukou == Ressyahoukou_Nobori ){
		iEkiOrder = m_CentDedDgrEkiCont.size() - 1 - iEkiIndex ;
	}
	return ( iEkiOrder ) ;
}

CdDcdZoneXy	CentDedDgrDia::getZone()const 
{
	int iYSize = getDgrYPosOfEki( INT_MAX )  ;
	if ( iYSize < 0 ){
		iYSize = 0 ;
	}
	return ( CdDcdZoneXy( 
		CdDcdZone( m_iDgrXPosMin , CdDedJikoku::TOTALSECONDS_A_DAY ) ,
		CdDcdZone( 0 , iYSize )  ) ) ;
}



int CentDedDgrDia::getDgrYPosOfEki( int iEkiIndex )const 
{
	//todo:駅幅の仕様が追加されたら、駅幅の和を加算する必要があります。

	return getDgrYSizeEkikan( 
			Ressyahoukou_Kudari , 
			0 ,
			iEkiIndex ) ; 
}

int CentDedDgrDia::getDgrYPosOfEki( ERessyahoukou eRessyahoukou , 
		int iEkiOrder )const 
{
	return getDgrYPosOfEki( 
		EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrder ) ) ; 

}

int CentDedDgrDia::getDgrYSizeEkikan( 
			ERessyahoukou eRessyahoukou , 
			int iEkiOrderOrg ,
			int iEkiOrderDst )const 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iEkiOrderOrg == INT_MAX ){
		iEkiOrderOrg = m_CentDedDgrEkiCont.size() - 1 ;
	}
	if ( iEkiOrderDst == INT_MAX ){
		iEkiOrderDst = m_CentDedDgrEkiCont.size() - 1 ;
	}
	// --------------------------------
	if ( !( 0 <= iEkiOrderOrg && iEkiOrderOrg < m_CentDedDgrEkiCont.size() ) ){
		return ( -1 ) ;	//		『駅Order』が不正
	}
	if ( !( 0 <= iEkiOrderDst && iEkiOrderDst < m_CentDedDgrEkiCont.size() ) ){
		return ( -1 ) ;	//		『駅Order』が不正
	}
	int iEkiIndexOrg = EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrderOrg ) ;
	int iEkiIndexDst = EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrderDst ) ;
	if ( iEkiIndexOrg > iEkiIndexDst ){
		int i = iEkiIndexOrg ;	iEkiIndexOrg = iEkiIndexDst ; iEkiIndexDst = i ;
	}
	// --------------------------------	
	const Mu<CentDedDgrEki>* pCentDedDgrEkiCont = getCentDedDgrEkiCont() ;

	int idx ;
	for ( idx = iEkiIndexOrg ; idx < iEkiIndexDst ; idx ++ ){
		iRv += pCentDedDgrEkiCont->get( idx ).getDgrYZahyouKyori() ;
	}

	return ( iRv ) ;
}


int CentDedDgrDia::getEkikanSaisyouSec( 
			ERessyahoukou eRessyahoukou , 
			int iEkiOrderOrg ,
			int iEkiOrderDst )const 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iEkiOrderOrg == INT_MAX ){
		iEkiOrderOrg = m_CentDedDgrEkiCont.size() - 1 ;
	}
	if ( iEkiOrderDst == INT_MAX ){
		iEkiOrderDst = m_CentDedDgrEkiCont.size() - 1 ;
	}
	// --------------------------------
	if ( !( 0 <= iEkiOrderOrg && iEkiOrderOrg < m_CentDedDgrEkiCont.size() ) ){
		return ( -1 ) ;	//		『駅Order』が不正
	}
	if ( !( 0 <= iEkiOrderDst && iEkiOrderDst < m_CentDedDgrEkiCont.size() ) ){
		return ( -1 ) ;	//		『駅Order』が不正
	}
	int iEkiIndexOrg = EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrderOrg ) ;
	int iEkiIndexDst = EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrderDst ) ;
	if ( iEkiIndexOrg > iEkiIndexDst ){
		int i = iEkiIndexOrg ;	iEkiIndexOrg = iEkiIndexDst ; iEkiIndexDst = i ;
	}
	// --------------------------------	
	const Mu<CentDedDgrEki>* pCentDedDgrEkiCont = getCentDedDgrEkiCont() ;

	int idx ;
	for ( idx = iEkiIndexOrg ; idx < iEkiIndexDst ; idx ++ ){
		if ( eRessyahoukou == Ressyahoukou_Kudari ){
			iRv += pCentDedDgrEkiCont->get( idx ).getEkikanSaisyouSecKudari() ;
		}	else if ( eRessyahoukou == Ressyahoukou_Nobori ){
			iRv += pCentDedDgrEkiCont->get( idx ).getEkikanSaisyouSecNobori() ;
		}
	}

	return ( iRv ) ;
}


CdDcdPosXy CentDedDgrDia::calcDgrPosRessyasenKiten( 
		const CentDedDgrRessya* pCentDedDgrRessya , 
		const CentDedDgrRessyasen* pCentDedDgrRessyasen )const 
{
	int iEkiOrderRessyasenKiten = pCentDedDgrRessyasen->getRessyasenKitenEkiOrder() ;
	CentDedDgrEkiJikoku	aEkiJikokuKiten = 
		*pCentDedDgrRessya->getMuCentDedDgrEkiJikoku()->get( iEkiOrderRessyasenKiten ) ;
	int iDgrXPosKiten = aEkiJikokuKiten.getDgrXPosHatsu( true ) ;
	int iDgrYPosKiten = this->getDgrYPosOfEki( 
			pCentDedDgrRessya->getRessyahoukou() , 
			iEkiOrderRessyasenKiten ) ;
	return CdDcdPosXy( iDgrXPosKiten , iDgrYPosKiten ) ;
}

CdDcdPosXy CentDedDgrDia::calcDgrPosRessyasenSyuuten( 
		const CentDedDgrRessya* pCentDedDgrRessya , 
		const CentDedDgrRessyasen* pCentDedDgrRessyasen )const 
{
	int iEkiOrderRessyasenSyuuten = pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() ;
	CentDedDgrEkiJikoku	aEkiJikokuSyuuten = 
		*pCentDedDgrRessya->getMuCentDedDgrEkiJikoku()->get( iEkiOrderRessyasenSyuuten ) ;
	int iDgrXPosSyuuten = aEkiJikokuSyuuten.getDgrXPosChaku( true ) ;
	int iDgrYPosSyuuten =this->getDgrYPosOfEki( 
			pCentDedDgrRessya->getRessyahoukou() , 
			iEkiOrderRessyasenSyuuten ) ;
	return CdDcdPosXy( iDgrXPosSyuuten , iDgrYPosSyuuten ) ;
}


void CentDedDgrDia::createEstimateRessya( 
		const CentDedDgrRessya* pCentDedDgrRessya ,
		CentDedRessya* pCentDedRessya )const 
{


	CentDedRessya	aCentDedRessya( 
		m_CentDedDgrEkiCont.size() ,
		pCentDedDgrRessya->getRessyahoukou() ) ;

	// --------------------------------
	//	属性の設定
	// --------------------------------
	{
		aCentDedRessya.setRessyabangou( 
			pCentDedDgrRessya->getRessyabangou() ) ;
		aCentDedRessya.setRessyamei( 
			pCentDedDgrRessya->getRessyamei() ) ;
		aCentDedRessya.setGousuu( 
			pCentDedDgrRessya->getGousuu() ) ;

	}
	// --------------------------------
	//	駅時刻の設定
	// --------------------------------
	{
		const Mu<const CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku = pCentDedDgrRessya->getMuCentDedDgrEkiJikoku() ;
		for ( int iEkiOrder = 0 ; 
			iEkiOrder < pMuCentDedDgrEkiJikoku->size() ; 
			iEkiOrder ++ )
		{
			CentDedDgrEkiJikoku	aCentDedDgrEkiJikoku = *pMuCentDedDgrEkiJikoku->get( iEkiOrder ) ;

			CentDedEkiJikoku	aEkiJikoku = aCentDedRessya.getCentDedEkiJikoku( iEkiOrder ) ;

			// --------------------------------
			//	駅扱を設定
			// --------------------------------
			aEkiJikoku.setEkiatsukai( aCentDedDgrEkiJikoku.getEkiatsukai() ) ;
			
			// --------------------------------
			//	この駅を端点とする列車線を検索
			// --------------------------------
			int idxRessyasenChaku = INT_MIN ;
			int idxRessyasenHatsu = INT_MIN ;
			const Mu<const CentDedDgrRessyasen*>* pMuRessyasen = pCentDedDgrRessya->getCentDedDgrRessyasenCont() ;
			for ( int idxRessyasen = 0 ; 
				idxRessyasen < pMuRessyasen->size() ; 
				idxRessyasen ++ )
			{
				const CentDedDgrRessyasen*	pCentDedDgrRessyasen = pMuRessyasen->get( idxRessyasen ) ;
				if ( pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() == iEkiOrder )
				{
					idxRessyasenChaku = idxRessyasen ;
				}
				if ( pCentDedDgrRessyasen->getRessyasenKitenEkiOrder() == iEkiOrder )
				{
					idxRessyasenHatsu = idxRessyasen ;
				}
			}
			//idxRessyasenChaku = 
			//	この駅Orderが列車線終点なら、その列車線Order、そうでないならINT_MIN 
			//idxRessyasenHatsu = 
			//	この駅Orderが列車線起点なら、その列車線Order、そうでないならINT_MIN 

			// --------------------------------
			//	駅時刻を設定
			// --------------------------------
			if ( idxRessyasenChaku != INT_MIN && aCentDedDgrEkiJikoku.getDgrXPosChaku( true ) != INT_MIN )
			{
				//	列車線の終点なら、着時刻DgrXPosをもとに着時刻を設定
				aEkiJikoku.setChakujikoku( CdDedJikoku( aCentDedDgrEkiJikoku.getDgrXPosChaku( true ) ) ) ;
			}
			if ( idxRessyasenHatsu != INT_MIN && aCentDedDgrEkiJikoku.getDgrXPosHatsu( true ) != INT_MIN )
			{
				//	列車線の起点なら、発時刻DgrXPosをもとに発時刻を設定
				aEkiJikoku.setHatsujikoku( CdDedJikoku( aCentDedDgrEkiJikoku.getDgrXPosHatsu( true ) ) ) ;
			}
			if ( idxRessyasenChaku == INT_MIN && 
				idxRessyasenHatsu == INT_MIN && 
				aCentDedDgrEkiJikoku.getDgrXPosRessyasen() != INT_MIN )
			{
				//	列車線起点・終点でない && 駅時刻に DgrXPosRessyasen がある場合は、
				//	DgrXPosRessyasen を着・発に設定
				aEkiJikoku.setChakujikoku( CdDedJikoku( aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ) ;
				aEkiJikoku.setHatsujikoku( CdDedJikoku( aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ) ;
			}

			aCentDedRessya.setCentDedEkiJikoku( iEkiOrder , aEkiJikoku ) ;
		}
	}
	// --------------------------------
		
	if ( pCentDedRessya != NULL )
	{
		*pCentDedRessya = aCentDedRessya ;
	}
}

void CentDedDgrDia::createEstimateRessya2( 
		const CentDedDgrRessya* pCentDedDgrRessya ,
		CentDedRessya* pCentDedRessya )const
{
	// --------------------------------
	CentDedRessya	aCentDedRessya( 
		m_CentDedDgrEkiCont.size() ,
		pCentDedDgrRessya->getRessyahoukou() ) ;
	if ( pCentDedRessya == NULL )
	{
		pCentDedRessya = &aCentDedRessya ;
	}
	// --------------------------------
	{
		//	推定時刻つき列車オブジェクトを生成
		createEstimateRessya(
			pCentDedDgrRessya ,
			pCentDedRessya ) ;
	}
	{
		//	駅情報にアクセスする Mu を生成
		const Mu< CentDedDgrEkiCont::CdDedDgrEki >* muEki =	getCentDedDgrEkiCont()->getMuPtr( pCentDedRessya->getRessyahoukou())  ;


		// --------------------------------
		//	支線分岐駅の場合は、同名駅に
		//	同一駅時刻をコピーする
		//	(支線内列車のソートの精度を上げるため)
		// --------------------------------

		//	全同名駅に、駅時刻をコピーします。
		//
		//	この仕様は、A-B-C|B-D形式の支線つき路線の
		//	TransferSort(乗継ソート)の精度を上げるためのものです。
		//	B-D間列車のB駅の駅時刻を
		//	A-B-Cの間の B にも設定することにより、乗継ソートの
		//	精度が高まります。
		{
			for ( int iEkiOrderSrc = 0 ; iEkiOrderSrc < muEki->size() ; iEkiOrderSrc ++ )
			{
				CentDedDgrEkiCont::CdDedDgrEki	aEkiSrc = muEki->get(iEkiOrderSrc) ;

				CentDedEkiJikoku	aEkiJikokuSrc = 
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrderSrc ) ;
				if ( aEkiJikokuSrc.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya ||
					aEkiJikokuSrc.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka )
				{
					for ( int iEkiOrder = 0 ; 
						iEkiOrder <  muEki->size() ;
						iEkiOrder ++ )
					{
						if ( iEkiOrderSrc != iEkiOrder )
						{
							CentDedDgrEkiCont::CdDedDgrEki aEki = muEki->get(iEkiOrder) ;

							if ( aEkiSrc.getEkimei() == aEki.getEkimei() )
							{
								CentDedEkiJikoku	aEkiJikoku = 
									pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
								if ( aEkiJikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None ||
									aEkiJikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
								{
									pCentDedRessya->setCentDedEkiJikoku( iEkiOrder , aEkiJikokuSrc ) ;
								}
							}
						}
					}
				}
			}
		}

	}


}
} //namespace entDgr
