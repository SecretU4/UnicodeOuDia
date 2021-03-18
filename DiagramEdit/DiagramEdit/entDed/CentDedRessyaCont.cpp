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
//	$Id: CentDedRessyaCont.cpp 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
*/
/** @file*/

#include "stdafx.h"
#include <algorithm>
#include "NsMu\CMup_deque.h"
#include "NsMu\CaMui.h"
#include "str\strtoint.h"
#include "logmsg\LogMsg.h"
#include "CentDedRosen.h"
#include "CentDedDiaCont.h"
#include "CentDedRessyaCont.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace entDed{
	using namespace std ;
	using namespace OuLib::Str ;
// ****************************************************************
//	CentDedRessyaCont
// ****************************************************************

// ********************************
//	コンストラクタ
// ********************************
CentDedRessyaCont::CentDedRessyaCont(
	ERessyahoukou eRessyahoukou )
	:
	 m_iEkiCount( 0 ) 
	, m_eRessyahoukou( eRessyahoukou )
{
}

CentDedRessyaCont::CentDedRessyaCont( 
		int iEkiCount ,
		ERessyahoukou eRessyahoukou )
	:
	 m_iEkiCount( iEkiCount ) 
	, m_eRessyahoukou( eRessyahoukou )
{
}


CentDedRessyaCont& CentDedRessyaCont::operator=( const CentDedRessyaCont& value )
{
	//	このコンテナが CentDedDia の子オブジェクトである場合、
	//	m_iEkiCount,m_iRessyasyubetsuCount,m_eRessyahoukou は変更されず、列車だけが
	//	コピーされます。
	//	CentDedDiaの子でない場合は、全属性をコピーします。
	if ( getDia() == NULL )
	{
		m_iEkiCount = value.m_iEkiCount ; 
		m_eRessyahoukou = value.m_eRessyahoukou ; 
	}

	//列車のコピー
	super::operator =( value ) ;

	return *this ;
}

	// ********************************
	//@name Mui
	// ********************************

int CentDedRessyaCont::insert( const CentDedRessya& element , int iIndex ) 
{
	return super::insert( element , iIndex ) ;

}

int CentDedRessyaCont::set( const CentDedRessya& element , int iIndex ) 
{
	return super::set( element , iIndex ) ;
}

	// ********************************
	//@name CentDedRessyaCont-関連
	// ********************************
CentDedRosen* CentDedRessyaCont::getRosen() 
{
	CentDedDia* pDia = getDia() ;
	if ( pDia == NULL ){	return NULL ;}
	CentDedDiaCont* pDiaCont = dynamic_cast<CentDedDiaCont*>( pDia->getParent() ) ;
	if ( pDiaCont == NULL ){	return NULL ;}
	return pDiaCont->getRosen() ;
}

const CentDedRosen* CentDedRessyaCont::getRosen()const 
{
	const CentDedDia* pDia = getDia() ;
	if ( pDia == NULL ){	return NULL ;}
	const CentDedDiaCont* pDiaCont = dynamic_cast<const CentDedDiaCont*>( pDia->getParent() ) ;
	if ( pDiaCont == NULL ){	return NULL ;}
	return pDiaCont->getRosen() ;
}


	// ********************************
	//@name CentDedRessyaCont-操作
	// ********************************
int CentDedRessyaCont::setable(  const CentDedRessya& element , int iIndex )const 
{
	return 0 ;
}

int  CentDedRessyaCont::getIndex( const CentDedRessya* element )const 
{
	const Mu<const CentDedRessya*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;

}

void CentDedRessyaCont::adjust() 
{
	CentDedRosen* pRosen = getRosen() ;
	if ( pRosen!= NULL )
	{
		m_iEkiCount = pRosen->getCentDedEkiCont()->size() ;
	}

	Mu<CentDedRessya*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		pMu->get( idx )->adjust() ;
	}
}





int CentDedRessyaCont::EkiIndexOfEkiOrder( int iEkiOrder )const 
{
	int iRv = iEkiOrder ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_iEkiCount - 1 - iEkiOrder ;
	}
	return ( iRv ) ;
}

int CentDedRessyaCont::EkiOrderOfEkiIndex( int iEkiIndex )const 
{
	int iRv = iEkiIndex ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_iEkiCount - 1 - iEkiIndex ;
	}
	return ( iRv ) ;
}

int CentDedRessyaCont::findEkikanSaisyouSec( 
		int iEkiOrder , 
		int* pidxRessya )const 
{
	// --------------------------------
			int iSaisyouSyouSecTeisya = -1 ;
			//iSaisyouSyouSecTeisya = 
			//	iEkiiIndex ・ iEkiIndex + 1 の両駅に停車する列車のうちの、
			//	最小駅間所要秒数 
			int iSaisyouSyouSec = -1 ;
			//iSaisyouSyouSec = 
			//	iEkiiIndex ・ iEkiIndex + 1 の最小駅間所要秒数
			//	片方・または両駅が通過駅の列車を含みます。

			int iSaisyouSyouSecTeisyaRessyaIdx = -1 ;
			//iSaisyouSyouSecTeisyaRessyaIdx = 
			//	iSaisyouSyouSecTeisya に対応する列車Index 
			int iSaisyouSyouSecRessyaIdx = -1 ;
			//iSaisyouSyouSecRessyaIdx = 
			//	iSaisyouSyouSec に対応する列車Index 
			
			const Mu<const CentDedRessya*>* pCentDedRessyaContGet =
				this->getMuPtr() ;
			if ( 0 <= iEkiOrder && iEkiOrder < this->getEkiCount() - 1 ){
				int iRessyaIndex = 0 ;
				for ( iRessyaIndex = 0 ; 
						iRessyaIndex < this->size() ; 
						iRessyaIndex ++ ){
					const CentDedRessya* pCentDedRessya = 
						pCentDedRessyaContGet->get( iRessyaIndex ) ;
					CentDedEkiJikoku aEkiJikokuCurr = 
						pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
					CentDedEkiJikoku aEkiJikokuNext = 
						pCentDedRessya->getCentDedEkiJikoku( iEkiOrder + 1 ) ;

					CdDedJikoku	jikokuHatsu = 
						aEkiJikokuCurr.getHatsujikoku( true ) ;
					CdDedJikoku	jikokuChaku = 
						aEkiJikokuNext.getChakujikoku( true ) ;
					if ( !jikokuHatsu.isNull() && !jikokuChaku.isNull() ){
						int iSyoyouSec = jikokuChaku.subJikoku( jikokuHatsu ) ;
						if ( iSaisyouSyouSec == -1 || 
								iSaisyouSyouSec > iSyoyouSec ){
							iSaisyouSyouSec = iSyoyouSec ;
							iSaisyouSyouSecRessyaIdx = iRessyaIndex ;
						}
						
						if ( aEkiJikokuCurr.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Teisya && 
							aEkiJikokuNext.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Teisya ){
							if ( iSaisyouSyouSecTeisya == -1 || 
									iSaisyouSyouSecTeisya > iSyoyouSec ){
								iSaisyouSyouSecTeisya = iSyoyouSec ;
								iSaisyouSyouSecTeisyaRessyaIdx = iRessyaIndex ;
							}
						} 
					}
					
				}
			}
			LogMsg( "CentDedRessyaCont::findEkikanSaisyouSec( iEkiOrder=%d )"
				" iSaisyouSyoyouSecTeisya=%d RessyaIdx=%d "
				" iSaisyouSyoyouSec=%d RessyaIdx=%d" , 
				iEkiOrder , 
				iSaisyouSyouSecTeisya ,
				iSaisyouSyouSecTeisyaRessyaIdx , 
				iSaisyouSyouSec ,
				iSaisyouSyouSecRessyaIdx ) ; 

			if ( iSaisyouSyouSecTeisya >= 0 ){
				iSaisyouSyouSec = iSaisyouSyouSecTeisya ;
				iSaisyouSyouSecRessyaIdx = iSaisyouSyouSecTeisyaRessyaIdx ;
			}
			if ( iSaisyouSyouSec < 0 ){
					iSaisyouSyouSec = 0 ;
			}
			// --------------------------------
			if ( pidxRessya != NULL ){
				*pidxRessya = iSaisyouSyouSecRessyaIdx ;
			}
			return ( iSaisyouSyouSec ) ;

}




int CentDedRessyaCont::findTrainToDirect(
		int idxRessya , 
		int iEkiOrder  )const 
{
	const CentDedRessya* pCentDedRessyaSyuuchaku = getMuPtr()->get( idxRessya ) ;
	CdDedJikoku jikokuSyuuchaku ;
	{
		int iEkiOrderSyuuchaku = pCentDedRessyaSyuuchaku->getRunLastEkiOrder() ;
		jikokuSyuuchaku = pCentDedRessyaSyuuchaku->getCentDedEkiJikoku( iEkiOrderSyuuchaku ).getChakujikoku( true ) ;
	}
	//jikokuSyuuchaku = this列車の終着駅の着時刻（NULLの場合もあります）

	int iRv = -1 ;
	for ( idxRessya ++ ; iRv == -1 && idxRessya  < getMuPtr()->size() ; idxRessya ++ )
	{
		const CentDedRessya* pCentDedRessyaSihatsu = getMuPtr()->get( idxRessya ) ;
		//	  - ・フォーカスのある列車(途中駅止まりの列車)と同じ列車種別
		if ( pCentDedRessyaSyuuchaku->getRessyasyubetsuIndex() == 
			pCentDedRessyaSihatsu->getRessyasyubetsuIndex() )
		{
			//	  - ・フォーカスのある駅を始発駅とする列車
			if ( iEkiOrder == pCentDedRessyaSihatsu->getRunFirstEkiOrder() )
			{
				//	  - ・終着列車の着時刻も始発駅の発時刻も指定されている場合は、
				//	  - ・始発駅の発時刻が、終着列車の着時刻から12時間以内
				//	  - ・終着列車の着時刻・始発駅の発時刻のどちらかが欠けている場合は、
				//		無条件に直通化の対象となります。
				CdDedJikoku jikokuSihatsu = pCentDedRessyaSihatsu->getCentDedEkiJikoku( iEkiOrder ).getHatsujikoku( true ) ;
				if ( !jikokuSyuuchaku.isNull() && !jikokuSihatsu.isNull() )
				{
					CdDedJikan aJikan = jikokuSihatsu.subJikoku( jikokuSyuuchaku ) ;
					if ( CdDedJikan() <= aJikan )
					{
						iRv = idxRessya ;
					} 
				}
				else
				{
					//	  - ・始発駅の発時刻が、終着列車の着時刻から12時間以内
					iRv = idxRessya ;
				}
			}
		}
	}
	return iRv ;
}

void CentDedRessyaCont::adjustByEkijikokukeisiki(
		int iEkiOrder ,
		bool bChakujikokuHyouji , bool bHatsujikokuHyouji ) 
{
	for ( int idxRessya = 0 ; idxRessya < size() ; idxRessya ++ )
	{
		CentDedRessya* pRessya = getMuPtr()->get( idxRessya ) ;
		pRessya->adjustByEkijikokukeisiki( 
			iEkiOrder ,
			bChakujikokuHyouji , bHatsujikokuHyouji ) ;
	}
}

	// ********************************
	//@name CentDedRessyaCont-駅数・列車種別数の変更
	// ********************************


int CentDedRessyaCont::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piRessyaIndex ) 
{
	int iRv = 0 ;
	Mu< CentDedRessya* >* pCentDedRessyaContGet = getMuPtr() ;
	int iRessyaIndexFound = -1 ;
	if ( iRv >= 0 ){
	
				Mu< CentDedRessya* >* pCentDedRessyaContGet = getMuPtr() ;
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

	// ********************************
	//@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
void CentDedRessyaCont::onEkiInsert( int iEkiOrder )
{
	m_iEkiCount ++ ;
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onEkiInsert( iEkiOrder ) ;
	}
}

void CentDedRessyaCont::onEkiErase( int iEkiOrder  )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onEkiErase( iEkiOrder ) ;
	}
	m_iEkiCount -- ;
}
void CentDedRessyaCont::onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onEkiTrackInsert( iEkiOrder , iEkiTrackIndex ) ;
	}
}
void CentDedRessyaCont::onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onEkiTrackErase( iEkiOrder , iEkiTrackIndex ) ;
	}
}
void CentDedRessyaCont::onRessyasyubetsuInsert( int iRessyasyubetsuIndex )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onRessyasyubetsuInsert( iRessyasyubetsuIndex ) ;
	}
}
void CentDedRessyaCont::onRessyasyubetsuErase( int iRessyasyubetsuIndex )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onRessyasyubetsuErase( iRessyasyubetsuIndex ) ;
	}

}



} //namespace entDed
