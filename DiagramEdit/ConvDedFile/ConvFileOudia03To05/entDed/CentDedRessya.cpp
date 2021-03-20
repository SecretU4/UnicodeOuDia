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

#include "CentDedRessya.h"
#include "CdDedJikan.h"

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif


// ****************************************************************
//	CentDedRessya
// ****************************************************************

// --------------------------------
///@name CentDedRosen→CentDedRessyaCont 専用メンバ関数
// --------------------------------
int CentDedRessya::onSetCentDedEki(const IfContGet<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder) 
{
	int iRv = 0 ;
	
	CentDedEkiCont::CdDedEki	aCdDedEki = pCentDedEkiCont->get( iEkiOrder ) ;

	// --------------------------------
	//	１．　駅時刻形式を（「発着」から）「発時刻のみ」に変更した場合、
	//		着時刻＝時刻あり・発時刻＝時刻なし
	//	の始発駅・終着駅の駅時刻を
	//		着時刻＝時刻なし・発時刻＝時刻あり（それまでの着時刻）
	//	に変更
	if ( !aCdDedEki.getChakujikokuHyouji() && 
				aCdDedEki.getHatsujikokuHyouji() && 
				( iEkiOrder == getSihatsuEki() || iEkiOrder == getSyuuchakuEki() ) ){
		CentDedEkiJikoku	aCentDedEkiJikoku = getCentDedEkiJikoku( iEkiOrder ) ;
		if ( !aCentDedEkiJikoku.getChakujikoku().isNull() && 
			aCentDedEkiJikoku.getHatsujikoku().isNull() ){
			aCentDedEkiJikoku.set( aCentDedEkiJikoku.getEkiatsukai() ,
				CdDedJikoku() , aCentDedEkiJikoku.getChakujikoku() ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikoku ) ;
		}

	}
	


	//	２．　駅時刻形式を（「発時刻のみ」から）「発着」に変更した場合、
	//		着時刻＝時刻なし・発時刻＝時刻あり
	//	の終着駅の時刻を
	//		着時刻＝時刻あり（それまでの発時刻）・発時刻＝時刻なし
	//	に変更
	if ( aCdDedEki.isHatsuChakuHyouji() && 
				iEkiOrder == getSyuuchakuEki() ){
		CentDedEkiJikoku	aCentDedEkiJikoku = getCentDedEkiJikoku( iEkiOrder ) ;
		if ( aCentDedEkiJikoku.getChakujikoku().isNull() && 
			!aCentDedEkiJikoku.getHatsujikoku().isNull() ){
			aCentDedEkiJikoku.set( aCentDedEkiJikoku.getEkiatsukai() ,
				aCentDedEkiJikoku.getHatsujikoku() , CdDedJikoku() ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikoku ) ;
		}

	}


	//	３．　駅時刻形式を（「発着」から）「着時刻のみ」に変更した場合、
	//		着時刻＝時刻なし・発時刻＝時刻あり
	//	の始発駅・終着駅の駅時刻を
	//		着時刻＝時刻あり（それまでの発時刻）・発時刻＝時刻なし
	//	に変更
	if ( aCdDedEki.getChakujikokuHyouji() && 
				!aCdDedEki.getHatsujikokuHyouji() && 
				( iEkiOrder == getSihatsuEki() || iEkiOrder == getSyuuchakuEki() ) ){
		CentDedEkiJikoku	aCentDedEkiJikoku = getCentDedEkiJikoku( iEkiOrder ) ;
		if ( aCentDedEkiJikoku.getChakujikoku().isNull() && 
			!aCentDedEkiJikoku.getHatsujikoku().isNull() ){
			aCentDedEkiJikoku.set( aCentDedEkiJikoku.getEkiatsukai() ,
				aCentDedEkiJikoku.getHatsujikoku() , CdDedJikoku() ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikoku ) ;
		}

	}
	



	//	４．　駅時刻形式を（「着時刻のみ」（下り着時刻・上り着時刻））から「発着」に変更した場合、
	//		着時刻＝時刻あり・発時刻＝時刻なし
	//	の始発駅の駅時刻を
	//		着時刻＝時刻なし・発時刻＝時刻あり（それまでの着時刻）
	//	に変更
	if ( aCdDedEki.isHatsuChakuHyouji() && 
				iEkiOrder == getSihatsuEki() ){
		CentDedEkiJikoku	aCentDedEkiJikoku = getCentDedEkiJikoku( iEkiOrder ) ;
		if ( !aCentDedEkiJikoku.getChakujikoku().isNull() && 
			aCentDedEkiJikoku.getHatsujikoku().isNull() ){
			aCentDedEkiJikoku.set( aCentDedEkiJikoku.getEkiatsukai() ,
				CdDedJikoku() , aCentDedEkiJikoku.getChakujikoku()  ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikoku ) ;
		}

	}


	// --------------------------------
	return ( iRv ) ;
}
int CentDedRessya::insertCentDedEkiJikoku( 
		const CentDedEkiJikoku& aCentEkiJikoku , 
		int iEkiOrder ) 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iRv >= 0 ){
		if ( iEkiOrder == INT_MAX ){
			iEkiOrder = (int)m_CentDedEkiJikokuCont.size()  ;
		}
		if ( !( 0 <= iEkiOrder && iEkiOrder <= (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	インデクスが不正です。
		}
	}
	if ( iRv >= 0 ){
		m_CentDedEkiJikokuCont.insert( 
			m_CentDedEkiJikokuCont.begin() + iEkiOrder , 
			new CentDedEkiJikoku( aCentEkiJikoku ) ) ;		
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedRessya::eraseCentDedEkiJikoku( int iEkiOrder ) 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iRv >= 0 ){
		if ( iEkiOrder == INT_MAX ){
			iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ;
		}
		if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	インデクスが不正です。
		}
	}
	if ( iRv >= 0 ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;		
		m_CentDedEkiJikokuCont.erase( 
			m_CentDedEkiJikokuCont.begin() + iEkiOrder ) ;
		delete pCentDedEkiJikoku ;
	}
	// --------------------------------
	return ( iRv ) ;
}

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
		m_CentDedEkiJikokuCont.push_back( new CentDedEkiJikoku ) ;
	}
}

CentDedRessya::CentDedRessya( 
		int iEkiJikokuCount ,
		ERessyahoukou	eRessyahoukou ,
		int	iRessyasyubetsuIndex ) :
	m_bIsNull( false ) ,
	m_eRessyahoukou( eRessyahoukou ) ,
	m_iRessyasyubetsuIndex( iRessyasyubetsuIndex )
{
	while ( (int)m_CentDedEkiJikokuCont.size() < iEkiJikokuCount ){
		m_CentDedEkiJikokuCont.push_back( new CentDedEkiJikoku ) ;
	}
}


CentDedRessya::CentDedRessya( const CentDedRessya& value ) :
	m_bIsNull( value.m_bIsNull ) ,
	m_eRessyahoukou( value.m_eRessyahoukou ) ,
	m_iRessyasyubetsuIndex( value.m_iRessyasyubetsuIndex ) ,
	m_strRessyabangou( value.m_strRessyabangou ),
	m_strRessyamei( value.m_strRessyamei ),
	m_strGousuu( value.m_strGousuu ),
	m_strBikou( value.m_strBikou )
{
	int iEkiOrder ;
	for ( iEkiOrder = 0 ; 
			iEkiOrder < (int)value.m_CentDedEkiJikokuCont.size() ; iEkiOrder ++ ){
		m_CentDedEkiJikokuCont.push_back( new CentDedEkiJikoku( 
			*value.m_CentDedEkiJikokuCont[iEkiOrder] ) ) ;
	} 
}
CentDedRessya& CentDedRessya::operator=( const CentDedRessya& value )
{
	m_bIsNull = value.m_bIsNull ;
	m_iRessyasyubetsuIndex = value.m_iRessyasyubetsuIndex ;
	m_strRessyabangou = value.m_strRessyabangou ;
	m_strRessyamei = value.m_strRessyamei;
	m_strGousuu = value.m_strGousuu;
	m_strBikou = value.m_strBikou;


	int iEkiOrder ;
	for ( iEkiOrder = 0 ; 
			iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ; iEkiOrder ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[iEkiOrder] ;
		if ( iEkiOrder < (int)value.m_CentDedEkiJikokuCont.size() ){
			*pCentDedEkiJikoku = *value.m_CentDedEkiJikokuCont[iEkiOrder] ;
		}	else	{
			*pCentDedEkiJikoku = CentDedEkiJikoku() ;
		}
	} 
	return *this ;
}

CentDedRessya::~CentDedRessya() 
{
	while ( m_CentDedEkiJikokuCont.size() > 0 ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = m_CentDedEkiJikokuCont.back() ;
		m_CentDedEkiJikokuCont.pop_back() ;
		delete pCentDedEkiJikoku ;
	}
}

// ********************************
//	CentDedRessya
// ********************************
	// ********************************
	//@name 属性
	// ********************************
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
		m_bIsNull = false ;
		m_iRessyasyubetsuIndex = value ; return *this ;
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
		aCentDedEkiJikoku = *m_CentDedEkiJikokuCont[iEkiOrder] ;
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
		*m_CentDedEkiJikokuCont[iEkiOrder] = value ;
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


CentDedRessya& CentDedRessya::modifyCentDedEkiJikoku( int iEkiOrder , 
		const CentDedEkiJikoku& value ) 
{
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ){
		m_bIsNull = false ;
	
		//	変更前の時刻を保存
		CdDedJikoku jikokuChakujikokuPrev = 
				m_CentDedEkiJikokuCont[iEkiOrder]->getChakujikoku() ;
		CdDedJikoku jikokuHatsujikokuPrev = 
				m_CentDedEkiJikokuCont[iEkiOrder]->getHatsujikoku() ;
		CdDedJikoku jikokuChakujikoku = value.getChakujikoku() ;
		CdDedJikoku jikokuHatsujikoku =  value.getHatsujikoku() ;
		
		//	駅時刻の変更
		m_CentDedEkiJikokuCont[iEkiOrder]->set( 
			value.getEkiatsukai() , value.getChakujikoku() , value.getHatsujikoku() ) ;
		//	その後の時刻の繰上げ・繰下げ
		if ( !jikokuHatsujikoku.isNull() && !jikokuHatsujikokuPrev.isNull() ){
			CdDedJikan	aCdDedJikan = jikokuHatsujikoku.subJikoku( 
					jikokuHatsujikokuPrev ) ;
			modifyRessyaJikoku( aCdDedJikan , iEkiOrder * 2 + 2 ) ;
		}	else if ( !jikokuChakujikoku.isNull() && !jikokuChakujikokuPrev.isNull() ){
			CdDedJikan	aCdDedJikan = jikokuChakujikoku.subJikoku( 
					jikokuChakujikokuPrev ) ;
			modifyRessyaJikoku( aCdDedJikan , iEkiOrder * 2 + 1 ) ;
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
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;
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
			m_CentDedEkiJikokuCont[ iEkiOrderCurr ] ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}
	{
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrderCurr ] ;
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
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;
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
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;
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
			m_CentDedEkiJikokuCont[ iEkiOrderCurr ] ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}
	// --------------------------------
	return ( iRv ) ;
}


	// ********************************
	//@name 『時刻Order』単位の操作
	// ********************************


CdDedJikoku CentDedRessya::getEkiJikoku( int iJikokuOrder )const 
{
	CdDedJikoku	aCdDedJikoku ;
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= iJikokuOrder && 
				iJikokuOrder < (int)m_CentDedEkiJikokuCont.size() * 2 ) ){
			iRv = -1 ;	//	パラメータが不正
		}
	}
	if ( iRv >= 0 ){
		int iEkiOrder = iJikokuOrder / 2 ;
		bool bHatsu = ( ( iJikokuOrder % 2 ) != 0 );
		if ( bHatsu ){
			aCdDedJikoku = 
				m_CentDedEkiJikokuCont[ iEkiOrder ]->getHatsujikoku() ;
		}	else	{
			aCdDedJikoku = 
				m_CentDedEkiJikokuCont[ iEkiOrder ]->getChakujikoku() ;
		}
	}
	return ( aCdDedJikoku ) ;
}

int CentDedRessya::setEkiJikoku( 
		const CdDedJikoku& aCdDedJikoku ,
		int iJikokuOrder ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= iJikokuOrder && 
				iJikokuOrder < (int)m_CentDedEkiJikokuCont.size() * 2 ) ){
			iRv = -1 ;	//	パラメータが不正
		}
	}
	if ( iRv >= 0 ){
		int iEkiOrder = iJikokuOrder / 2 ;
		bool bHatsu = ( ( iJikokuOrder % 2 ) != 0 );
		if ( bHatsu ){
			m_CentDedEkiJikokuCont[ iEkiOrder ]->setHatsujikoku(
				aCdDedJikoku ) ;
		}	else	{
			m_CentDedEkiJikokuCont[ iEkiOrder ]->setChakujikoku(
				aCdDedJikoku ) ;
		}
	}
	return ( iRv ) ;
}

int CentDedRessya::modifyRessyaJikoku( 
		const CdDedJikan& aCdDedJikan , int iJikokuOrder ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= iJikokuOrder && 
				iJikokuOrder < (int)m_CentDedEkiJikokuCont.size() * 2 ) ){
			iRv = -1 ;	//	パラメータが不正
		}
	}
	if ( iRv >= 0 ){
		int iJikokuOrderCurr ;
		for ( iJikokuOrderCurr = iJikokuOrder ;
				iJikokuOrderCurr < (int)m_CentDedEkiJikokuCont.size() * 2 ;
				iJikokuOrderCurr ++ ){
			CdDedJikoku aCdDedJikoku = getEkiJikoku( iJikokuOrderCurr ) ;
			if ( !aCdDedJikoku.isNull() ){
				aCdDedJikoku = aCdDedJikoku.addSeconds( 
					aCdDedJikan.getTotalSeconds() ) ;
				setEkiJikoku( aCdDedJikoku , iJikokuOrderCurr ) ;
			}
		}
	}
	return ( iRv ) ;
	
}

int CentDedRessya::findrevJikoku( int iJikokuOrder )const 
{
	int iRv = -1 ;
	
	for ( ; iRv == -1 && iJikokuOrder >= 0 ; iJikokuOrder -- ){
		CdDedJikoku	aCdDedJikoku = getEkiJikoku( iJikokuOrder ) ;
		if ( !aCdDedJikoku.isNull() ){
			iRv = iJikokuOrder ;
		}
	}
	return ( iRv ) ;
}

	
	
	// ********************************
	//@name 操作
	// ********************************
bool CentDedRessya::isNull()const 
{
	return ( m_bIsNull ) ;
}

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
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}

}

