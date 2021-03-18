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
//	CEnumRessyasen.cpp
// $Id: CEnumRessyasen.cpp 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
*/
#include "stdafx.h"
#include "CEnumRessyasen.h"

namespace entDgr{
	
// ****************************************************************
//	CEnumRessyasen
// ****************************************************************
	//*******************************
	//	コンストラクタ
	//*******************************
CEnumRessyasen::CEnumRessyasen( 
		const CentDedDgrDia* pCentDedDgrDia ,
		const CdDcdZoneXy& zonexyDgrZone ,
		bool bDisplayRessyasenKudari ,
		bool bDisplayRessyasenNobori ) :
	m_pCentDedDgrDia( pCentDedDgrDia ) ,
	m_zonexyDgrZone( zonexyDgrZone ) ,
	m_bDisplayRessyasenKudari( bDisplayRessyasenKudari ) ,
	m_bDisplayRessyasenNobori( bDisplayRessyasenNobori )
{
}
CEnumRessyasen::~CEnumRessyasen() 
{
}

	// --------------------------------
	//@name CEnumRessyasen
	// --------------------------------
void CEnumRessyasen::onCentDedDgrRessya( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ) 
{
	//	対象となる描画領域を、
	//	『ダイヤグラムエンティティ座標系』で保持します。
	//	これは、今回描画を行う範囲を表しています。
	CdDcdZoneXy	zonexyDgrZone = m_zonexyDgrZone ;

	const Mu<const CentDedDgrRessyasen*>* pMuCentDedDgrRessyasen = 
		pCentDedDgrRessya->getCentDedDgrRessyasenCont() ;
	for ( int iRessyasenIdx = 0 ; 
			iRessyasenIdx < pMuCentDedDgrRessyasen->size() ;
			iRessyasenIdx ++ )
	{
		// --------------------------------
		//	列車線毎の処理
		// --------------------------------
		const CentDedDgrRessyasen*	pCentDedDgrRessyasen = 	
			pMuCentDedDgrRessyasen->get( iRessyasenIdx ) ;
		// --------------------------------
		//	列車線を囲む矩形領域を求める
		// --------------------------------
		CdDcdZoneXy	zonexyDgrRessyasen ;
		CdDcdPosXy	posRessyasenKiten ;
		CdDcdPosXy	posRessyasenSyuuten ; 
		{
			posRessyasenKiten = 
				m_pCentDedDgrDia->calcDgrPosRessyasenKiten( 
				pCentDedDgrRessya , pCentDedDgrRessyasen ) ;
			posRessyasenSyuuten = 
				m_pCentDedDgrDia->calcDgrPosRessyasenSyuuten( 
				pCentDedDgrRessya , pCentDedDgrRessyasen ) ;

			CdDcdZone	zoneDgrX ;
			zoneDgrX.setBeginEndPos( 
				posRessyasenKiten.getX() , 
				posRessyasenSyuuten.getX() ) ;
			CdDcdZone	zoneDgrY ;
			zoneDgrY.setBeginEndPos( 
				posRessyasenKiten.getY() ,
				posRessyasenSyuuten.getY() ) ;

			if ( !( zoneDgrX.getSize() == 0 && zoneDgrY.getSize() == 0 ) )
			{
				if ( zoneDgrX.getSize() == 0 )
				{
					//	始点と終点のX座標が同一の場合(垂直線)は、例外的に幅を1とします
					//	(0としてしまうと、線が描画されません)
					zoneDgrX.setSize( 1 ) ;
				}
				if ( zoneDgrY.getSize() == 0 )
				{
					//	始点と終点のY座標が同一の場合(水平線)は、例外的に幅を1とします
					//	(0としてしまうと、線が描画されません)
					zoneDgrY.setSize( 1 ) ;
				}
			}

			zonexyDgrRessyasen.setX( zoneDgrX ).setY( zoneDgrY ) ;

		}


		CdDcdZoneXy	zonexyDgrRessyasenOnDgrZone = zonexyDgrZone.CrossZone( zonexyDgrRessyasen ) ;
		//zonexyDgrRessyasenOnDgrZone
		//	列車線と描画領域の、交差領域
		//	この値のサイズが0なら、この列車線は描画可能な領域にはありません。

		if ( zonexyDgrRessyasenOnDgrZone.getX().getSize() > 0 && 
			zonexyDgrRessyasenOnDgrZone.getY().getSize() > 0 )
		{
			//	この列車線は、描画可能な駅間にあります。
			onCentDedDgrRessyasen( 
				eRessyahoukou ,
				iRessyaIdx ,
				pCentDedDgrRessya ,
				iRessyasenIdx ,
				pCentDedDgrRessyasen ) ;
		}
	}
}

void CEnumRessyasen::onCentDedDgrRessyasen( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ) 
{
	int iEkiOrderRessyasenKiten = pCentDedDgrRessyasen->getRessyasenKitenEkiOrder() ;
	int iEkiOrderRessyasenSyuuten = pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() ;

	const Mu<const CentDedDgrEkiJikoku*>* pMuCentDedDgrEkiJikoku = 
		pCentDedDgrRessya->getMuCentDedDgrEkiJikoku() ;
	


	for ( int iEkiOrder = iEkiOrderRessyasenKiten ;
		iEkiOrder <= iEkiOrderRessyasenSyuuten ;
		iEkiOrder ++ )
	{
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku = 
			pCentDedDgrRessya->getMuCentDedDgrEkiJikoku()->get( iEkiOrder ) ;
		onCentDedDgrEkiJikoku( 
			eRessyahoukou , 
			iRessyaIdx , 
			pCentDedDgrRessya ,
			iRessyasenIdx ,
			pCentDedDgrRessyasen ,
			iEkiOrder ,
			pCentDedDgrEkiJikoku ) ;
	}


}
void CEnumRessyasen::onCentDedDgrEkiJikoku( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ,
		int iEkiOrder , 
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku ) 
{
}

	// ********************************
	//@name CEnumRessyasen-関連
	// ********************************
const CentDedDgrDia*	CEnumRessyasen::getCentDedDgrDia()
{	
		return m_pCentDedDgrDia ; 
} ;
	// ********************************
	//@name CEnumRessyasen-属性
	// ********************************
CdDcdZoneXy	CEnumRessyasen::getDgrZone()
{
	return m_zonexyDgrZone ;
};

bool CEnumRessyasen::getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const 
{
	bool bRv = false ;
	if ( eRessyahoukou == Ressyahoukou_Kudari ){
		bRv = m_bDisplayRessyasenKudari ;
	}	else if ( eRessyahoukou == Ressyahoukou_Nobori ) {
		bRv = m_bDisplayRessyasenNobori ;
	}
	return ( bRv ) ;
}
	// ********************************
	//@name CEnumRessyasen-操作
	// ********************************
void CEnumRessyasen::execute() 
{
	//	対象となる描画領域を、
	//	『ダイヤグラムエンティティ座標系』で保持します。
	//	これは、今回描画を行う範囲を表しています。
	CdDcdZoneXy	zonexyDgrZone = m_zonexyDgrZone ;


	for ( int iRessyahoukou = Ressyahoukou_Kudari ;
		iRessyahoukou <= Ressyahoukou_Nobori ;
		iRessyahoukou ++ )
	{
		// --------------------------------
		//	列車方向の処理を実行するか否かの判定
		// --------------------------------
		ERessyahoukou	eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
		if ( !getDisplayRessyasen( eRessyahoukou ) ) 
		{
			//	この方向の処理は行いません。
			continue ;
		}
		// --------------------------------
		//	列車方向毎の処理
		// --------------------------------
		const Mu<const CentDedDgrRessya*>*	pMuCentDedDgrRessya = 
			m_pCentDedDgrDia->getCentDedDgrRessyaCont( eRessyahoukou );
		for ( int iRessyaIdx = 0 ; 
				iRessyaIdx < pMuCentDedDgrRessya->size() ;
				 iRessyaIdx ++ )
		{
			// --------------------------------
			//	列車毎の処理
			// --------------------------------
			const CentDedDgrRessya* pCentDedDgrRessya = 
				pMuCentDedDgrRessya->get( iRessyaIdx ) ;
			if ( pCentDedDgrRessya->getIsNull() || 
				pCentDedDgrRessya->getCentDedDgrRessyasenCont()->size() <= 0 )
			{
				//	NULL列車・列車線の全くない列車は対象外
				continue ;
			}
			// --------------------------------

			CentDedDgrRessya	aCentDedDgrRessya( *pCentDedDgrRessya ) ;
			//	列車の最大のDgrX座標＜ダイヤグラムの
			//	左端のDgrX座標になるまで、
			//	列車全体のDgrX座標を24時間ずつ減算する。
			//
			//	この処理は、列車がダイヤグラム左端を
			//	跨いでいる場合に、必要です。
			//	たとえば、ダイヤグラムの左端が 00:00:00
			//	になっているダイヤの場合、
			//	23:00 から 01:00 に向かって走っている列車は
			//	-01:00→01:00 
			//	 23:00→25:00
			//	の２箇所に列車線を描画しなくてはなりません。
			//	このループでは、一旦列車の時刻を
			//	-25:00→-23:00 
			//	にします。
			while ( !( aCentDedDgrRessya.getDgrXZone().getEndPos() < 
				zonexyDgrZone.getX().getPos() ) )
			{
				aCentDedDgrRessya.modifyDgrXPos( - CdDedJikoku::TOTALSECONDS_A_DAY ) ;
			}

			//	ここで、24時間加算します。これにより、列車時刻は
			//	-01:00→01:00 
			//	となります。
			aCentDedDgrRessya.modifyDgrXPos( + CdDedJikoku::TOTALSECONDS_A_DAY ) ;

			
			for ( ; aCentDedDgrRessya.getDgrXZone().getPos() < 
					zonexyDgrZone.getX().getEndPos() ;
				aCentDedDgrRessya.modifyDgrXPos( + CdDedJikoku::TOTALSECONDS_A_DAY ) )
			{
				// --------------------------------
				//	列車の表示位置（２４時間間隔）毎の処理
				// --------------------------------
				CdDcdZone	zoneDgrXCross = zonexyDgrZone.getX().CrossZone(
					aCentDedDgrRessya.getDgrXZone() ) ;
				if ( zoneDgrXCross.getSize() > 0 )
				{
					//	この列車は、対象となる描画領域内にあります。
					onCentDedDgrRessya( 
						eRessyahoukou ,
						iRessyaIdx ,
						&aCentDedDgrRessya ) ;
				}
			}
		}
	}
};

} //namespace entDgr
