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
//	CentDedDgrRessya.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include "CentDedDgrRessya.h"
#include "logmsg/LogMsg.h"
#include "CentDedDgrDia.h"

using namespace std ;

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif //_CONSOLE

namespace entDgr{

/** 時刻の書式を保持します。 */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	true ,		//	NoColon 
	// 時が 00 から 09 の場合、10の位の "0" を削除します。
	CdDedJikoku::CConv::EHour_ZeroToNone ,	
	CdDedJikoku::CConv::ESecond_NoSecond 	// 秒を常に出力しません。 
	) ;
// ****************************************************************
//	CentDedDgrRessya
// ****************************************************************
	// --------------------------------
	//@name readCentDedRessya() の下請関数
	// --------------------------------
	/*
		readCentDedRessya() の下請関数
		(01)CentDedDgrRessyaの属性のうち、CentDedRessya のみで決定する属性を設定
	*/
void CentDedDgrRessya::readCentDedRessya_01_readProp( const CentDedRessya* pCentDedRessya ) 
{
	m_bIsNull = pCentDedRessya->isNull() ;
	m_eRessyahoukou = pCentDedRessya->getRessyahoukou() ;
	m_iRessyasyubetsuIndex = pCentDedRessya->getRessyasyubetsuIndex() ;
	m_strRessyabangou = pCentDedRessya->getRessyabangou() ;
	m_strRessyamei = pCentDedRessya->getRessyamei() ;
	m_strGousuu = pCentDedRessya->getGousuu() ;

	m_DgrXZone = CdDcdZone() ;
}
	/*
		readCentDedRessya() の下請関数
		(02)CentDedDgrEkiJikoku を生成し、 CentDedEkiJikoku で決まる属性を決定。
	*/
void CentDedDgrRessya::readCentDedRessya_02_CreateCentDedEkiJikoku( 
		const CentDedRessya* pCentDedRessya ) 
{
	//	直前の駅の駅時刻。
	CdDedJikoku	aCdDedJikokuLastStation ;


	//	直前の駅の駅時刻でのX座標。aCdDedJikokuLastStation がNULLの場合は
	//	無効です。
	//	最初の「NULLでない駅時刻」を見つかった場合は、その駅時刻から導出された
	//	X座標になります。
	//	2箇所目以降の「NULLでない駅時刻」以降は、
	//	前の駅時刻からの経過時間を加算します。
	//
	//	iXZahyouLastStation = iXZahyouLastStation 
	//		+ ( その駅の駅時刻 - aCdDedJikokuLastStation ) 
	//
	//	これにより、24:00をまたがって走る列車では、
	//	24:00以降の駅時刻に対応する X座標は 24:00 相当(24*60*60=86400) 以上
	//	になります。
	int	iXZahyouLastStation = 0 ;

	for ( int iEkiOrder = 0 ; 
		iEkiOrder < pCentDedRessya->getCentDedEkiJikokuCount() ; 
		iEkiOrder ++ )
	{
		CentDedEkiJikoku aCentDedEkiJikoku 
			= pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;

		//	駅時刻から、X座標を計算	
		int iDgrXZahyou[2] = { INT_MIN , INT_MIN } ;
		for ( int iChakuHatsu = 0 ; iChakuHatsu < 2 ; iChakuHatsu ++ )
		{
			int iX = INT_MIN ;
			CdDedJikokuOrder::EEkiJikokuItem eEkiJikokuItem = CdDedJikokuOrder::EkiJikokuItem_Chaku ;
			if ( iChakuHatsu == 1 )
			{
				eEkiJikokuItem = CdDedJikokuOrder::EkiJikokuItem_Hatsu ; 
			}


			CdDedJikokuOrder	aCdDedJikokuOrder ;
			aCdDedJikokuOrder.setEkiOrder( iEkiOrder , 
				eEkiJikokuItem ) ;
			CdDedJikoku	aCdDedJikoku 
				= pCentDedRessya->getEkiJikoku( aCdDedJikokuOrder ) ;

			if ( aCdDedJikoku.isNull() )
			{
				//	NULL 時刻なら、処理なし
			}
			else if ( aCdDedJikokuLastStation.isNull() )
			{
				//	1回目以降の、非NULL時刻
				iX = aCdDedJikoku.getTotalSeconds() ;	//	最初の、非NULL時刻
			}
			else
			{
				//	2回目以降の、非NULL時刻
				CdDedJikan	aCdDedJikan 
					= aCdDedJikoku.subJikoku( aCdDedJikokuLastStation ) ;
				iX = iXZahyouLastStation + aCdDedJikan.getTotalSeconds() ;
			}
			// --------------------------------
			if ( iX != INT_MIN )
			{
				aCdDedJikokuLastStation = aCdDedJikoku ;
				iXZahyouLastStation = iX ;
			}
			iDgrXZahyou[iChakuHatsu] = iX ;
		}

		CentDedDgrEkiJikoku	aCentDedDgrEkiJikoku( 
			aCentDedEkiJikoku.getEkiatsukai() ,
			iDgrXZahyou[0] ,
			iDgrXZahyou[1] ) ;
		
		m_MuCentDedDgrEkiJikoku.insert( aCentDedDgrEkiJikoku ) ;
	}
}

void CentDedDgrRessya::readCentDedRessya_03_updateDgrXZone() 
{
	int iDgrXMin = INT_MIN ;
	int iDgrXMax = INT_MIN ;
	for ( int idx = 0 ; idx < m_MuCentDedDgrEkiJikoku.size() ; idx ++ )
	{
		CentDedDgrEkiJikoku	aCentDedDgrEkiJikoku 
			= m_MuCentDedDgrEkiJikoku.get( idx ) ;
		if ( aCentDedDgrEkiJikoku.getDgrXPosChaku() != INT_MIN )
		{
			if ( iDgrXMin == INT_MIN || 
				iDgrXMin > aCentDedDgrEkiJikoku.getDgrXPosChaku() )
			{
				iDgrXMin = aCentDedDgrEkiJikoku.getDgrXPosChaku() ;
			}
			if ( iDgrXMax == INT_MIN || 
				iDgrXMax < aCentDedDgrEkiJikoku.getDgrXPosChaku() )
			{
				iDgrXMax = aCentDedDgrEkiJikoku.getDgrXPosChaku() ;
			}
		}

		if ( aCentDedDgrEkiJikoku.getDgrXPosHatsu() != INT_MIN )
		{
			if ( iDgrXMin == INT_MIN || 
				iDgrXMin > aCentDedDgrEkiJikoku.getDgrXPosHatsu() )
			{
				iDgrXMin = aCentDedDgrEkiJikoku.getDgrXPosHatsu() ;
			}
			if ( iDgrXMax == INT_MIN || 
				iDgrXMax < aCentDedDgrEkiJikoku.getDgrXPosHatsu() )
			{
				iDgrXMax = aCentDedDgrEkiJikoku.getDgrXPosHatsu() ;
			}
		}
	}
	if ( iDgrXMin != INT_MIN && iDgrXMax != INT_MIN )
	{
		m_DgrXZone.setBeginEndPos( iDgrXMin , iDgrXMax ) ;

		//	iDgrXMinとiDgrXMaxが同一の場合は、例外的にサイズは1とします
		if ( m_DgrXZone.getSize() == 0 )
		{
			m_DgrXZone.setSize( 1 ) ;
		}
	}
}

void CentDedDgrRessya::readCentDedRessya_04_updateShouldRessyajouhouDraw(
	const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) 
{
	bool	bFirstRessyajouhouHyoujiIsSet = false ;
	for ( int iEkiOrder = 0 ;
		iEkiOrder < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrder ++ )
	{
		bool	bShouldRessyajouhouDraw = false ;

		CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;

		CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki = 
			pMuCdDedDgrEki->get( iEkiOrder ) ;

		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			//	列車線の存在する駅間、
			CentDedDgrEki::EDiagramRessyajouhouHyouji	
				eDiagramRessyajouhouHyouji = 
					aCdDedDgrEki.getDiagramRessyajouhouHyouji() ;

			//	(1)  [この列車の列車情報がまだ1箇所も描画されていない]
			//		列車情報描画が「表示しない」以外の駅間。
			if ( !bFirstRessyajouhouHyoujiIsSet && 
				eDiagramRessyajouhouHyouji !=
				CentDedDgrEki::DiagramRessyajouhouHyouji_Not ) 
			{
				bShouldRessyajouhouDraw = true ;
			}

			//	(2)  列車情報描画が「常に表示」の駅間
			if ( eDiagramRessyajouhouHyouji ==
				CentDedDgrEki::DiagramRessyajouhouHyouji_Anytime )
			{
				bShouldRessyajouhouDraw = true ;

			}

		}

		pCentDedDgrEkiJikoku->setShouldRessyajouhouDraw( 
			bShouldRessyajouhouDraw ) ;
		if ( bShouldRessyajouhouDraw )
		{
			bFirstRessyajouhouHyoujiIsSet = true ;
		}

	}

	//	1箇所も列車情報描画位置がない場合は、
	//	最初の列車線位置に描画します。
	for ( int iEkiOrder = 0 ;
		!bFirstRessyajouhouHyoujiIsSet 
			&& iEkiOrder < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrder ++ )
	{
		bool	bShouldRessyajouhouDraw = false ;

		CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;

		CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki = 
			pMuCdDedDgrEki->get( iEkiOrder ) ;

		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			//	列車線の存在する駅間、
				bShouldRessyajouhouDraw = true ;
		}

		pCentDedDgrEkiJikoku->setShouldRessyajouhouDraw( 
			bShouldRessyajouhouDraw ) ;
		if ( bShouldRessyajouhouDraw )
		{
			bFirstRessyajouhouHyoujiIsSet = true ;
		}

	}

}


//	(05)経由なしの前後の着発時刻を補う
void CentDedDgrRessya::readCentDedRessya_05_complementKeiyunasiSide() 
{
	for ( int iEkiOrderBefore = 0 ; 
		iEkiOrderBefore < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrderBefore ++ )
	{
		// --------------------------------
		//	iEkiOrderBefore 以降で、以下の駅時刻の並びを探します。
		//	(1)駅扱={停車,通過}のいずれか
		//	(2)「駅扱={経由なし}」の1個以上の並び
		//	(3)駅扱={停車,通過}のいずれか
		// --------------------------------
		//	(1)駅扱={停車,通過}のいずれか の駅を探す
		CentDedDgrEkiJikoku	ekijikokuBefore = 
			m_MuCentDedDgrEkiJikoku.get( iEkiOrderBefore ) ;
		if ( !(  
			( ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Teisya || 
			  ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
		) )
		{
			continue ;
		}
		//iEkiOrderBefore,ekijikokuBefore = (1)駅扱={停車,通過}のいずれか

		int iEkiOrderAfter = INT_MIN ;
		CentDedDgrEkiJikoku	ekijikokuAfter ;
		for ( iEkiOrderAfter = iEkiOrderBefore + 1  ;
				iEkiOrderAfter < m_MuCentDedDgrEkiJikoku.size() ;
				iEkiOrderAfter ++ )
		{
			ekijikokuAfter = 
				m_MuCentDedDgrEkiJikoku.get( iEkiOrderAfter ) ;
			if ( ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				//	(2)「駅扱={経由なし}」
				//		の並び
				continue ;
			}
			else if ( ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Teisya || 
			  ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
			{
				//	(3)駅扱={停車,通過}のいずれか
				break ;
			}
			else
			{
				//	条件にあてはまらない駅時刻
				//(例：着時刻ありの駅・運行なしの駅)
				iEkiOrderAfter = INT_MIN ;
				break ;
			}
		}
		if ( iEkiOrderAfter == INT_MIN 
			|| iEkiOrderAfter == m_MuCentDedDgrEkiJikoku.size() )
		{
			//	条件を満たす駅が見つかりません
			continue ;
		}
		//iEkiOrderAfter,ekijikokuAfter = (3)駅扱={停車,通過}のいずれか
		if ( iEkiOrderBefore + 1 == iEkiOrderAfter )
		{
			//	(2)「駅扱={経由なし}」が含まれていません。
			continue ;
		}

		//- 連続した経由なしの直前に着時刻がない 
		//		AND 経由なしの直後に着時刻がある場合
		//	直前の着時刻を補います。
		if ( ekijikokuBefore.getDgrXPosChaku() == INT_MIN && 
			ekijikokuAfter.getDgrXPosChaku() != INT_MIN )
		{
			ekijikokuBefore.setDgrXPosChaku( ekijikokuAfter.getDgrXPosChaku());
		}
		
		//- 連続した経由なしの直前に発時刻がない 
		//		AND 経由なしの直後に発時刻がある場合
		//	直前の発時刻を補います。
		if ( ekijikokuBefore.getDgrXPosHatsu() == INT_MIN && 
			ekijikokuAfter.getDgrXPosHatsu() != INT_MIN )
		{
			ekijikokuBefore.setDgrXPosHatsu( ekijikokuAfter.getDgrXPosHatsu() ) ;
		}

		//- 連続した経由なしの直前に着時刻がある 
		//		AND 経由なしの直後に着時刻がない場合は、
		//	直後の着時刻を補います。
		if ( ekijikokuBefore.getDgrXPosChaku() != INT_MIN && 
			ekijikokuAfter.getDgrXPosChaku() == INT_MIN )
		{
			ekijikokuAfter.setDgrXPosChaku(ekijikokuBefore.getDgrXPosChaku() );
		}
		//- 連続した経由なしの直前に発時刻がある 
		//		AND 経由なしの直後に発時刻がない場合は、
		//	直後の発時刻を補います。
		if ( ekijikokuBefore.getDgrXPosHatsu() != INT_MIN && 
			ekijikokuAfter.getDgrXPosHatsu() == INT_MIN )
		{
			ekijikokuAfter.setDgrXPosHatsu(ekijikokuBefore.getDgrXPosHatsu());
		}


		m_MuCentDedDgrEkiJikoku.set( 
			ekijikokuBefore ,
			iEkiOrderBefore ) ;
		m_MuCentDedDgrEkiJikoku.set( 
			ekijikokuAfter ,
			iEkiOrderAfter ) ;
		// --------------------------------
		//	次の検索開始位置を決める
		// --------------------------------
		{
			//	(1)駅扱={停車,通過}のいずれか
			//	(3)駅扱={停車,通過}のいずれか
			//	の両方が見つかった場合は、
			//	次の検索は (3)駅扱={停車,通過}のいずれか
			//	から始めます。
			iEkiOrderBefore = iEkiOrderAfter - 1;
		}
	}
}

void CentDedDgrRessya::readCentDedRessya_06_complementLongStop_01(
	const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) 
{
	// --------------------------------
	//	長時間停車の着時刻を補う
	// --------------------------------
	for ( int iEkiOrderBefore = 0 ; 
		iEkiOrderBefore < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrderBefore ++ )
	{
		// --------------------------------
		//	iEkiOrderBefore 以降で、以下の駅時刻の並びを探します。
		//	(1)(着時刻=あり or 発時刻=あり) AND 駅扱={停車,通過}のいずれか
		//	(2)「着時刻=なし、発時刻=なし、駅扱={通過,経由なし}のいずれか」
		//		の0個以上の並び
		//	(3)着時刻=なし、発時刻=あり AND 列車の終着駅でない
		// --------------------------------
		//	(1)(着時刻=あり or 発時刻=あり) AND 駅扱={停車,通過}のいずれか
		//	の駅を探す
		CentDedDgrEkiJikoku	ekijikokuBefore = 
			m_MuCentDedDgrEkiJikoku.get( iEkiOrderBefore ) ;
		if ( !( 
			( ekijikokuBefore.getDgrXPosChaku() != INT_MIN || 
			  ekijikokuBefore.getDgrXPosHatsu() != INT_MIN ) && 
			( ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Teisya || 
			  ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
		) )
		{
			continue ;
		}
		//iEkiOrderBefore,ekijikokuBefore = 
		//	(1)(着時刻=あり or 発時刻=あり) AND 駅扱={停車,通過}のいずれか

		int iEkiOrderAfter = INT_MIN ;
		CentDedDgrEkiJikoku	ekijikokuAfter ;
		for ( iEkiOrderAfter = iEkiOrderBefore + 1  ;
				iEkiOrderAfter < m_MuCentDedDgrEkiJikoku.size() ;
				iEkiOrderAfter ++ )
		{

			ekijikokuAfter = 
				m_MuCentDedDgrEkiJikoku.get( iEkiOrderAfter ) ;
			if ( ekijikokuAfter.getDgrXPosChaku() == INT_MIN && 
				ekijikokuAfter.getDgrXPosHatsu() == INT_MIN && 
				( ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Teisya || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Tsuuka || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Keiyunasi ) )
			{
				//	(2)「着時刻=なし、発時刻=なし、駅扱={停車,通過,経由なし}の
				//		いずれか」の0個以上の並び
				continue ;
			}
			else if ( ekijikokuAfter.getDgrXPosChaku() == INT_MIN && 
				ekijikokuAfter.getDgrXPosHatsu() != INT_MIN &&
				iEkiOrderAfter < getSyuuchakuEki() )
			{
				//	(3)着時刻=なし、発時刻=あり AND 列車の終着駅でない
				break ;
			}
			else
			{
				//	条件にあてはまらない駅時刻
				//(例：着時刻ありの駅・運行なしの駅)
				iEkiOrderAfter = INT_MIN ;
				break ;
			}
		}
		if ( iEkiOrderAfter == INT_MIN 
			|| iEkiOrderAfter == m_MuCentDedDgrEkiJikoku.size() )
		{
			//	条件を満たす駅が見つかりません
			continue ;
		}
		//iEkiOrderAfter,ekijikokuAfter = 
		//	(3)着時刻=なし、発時刻=あり AND 列車の終着駅でない

		// --------------------------------
		//	(1)の発時刻{なければ着時刻}+(1)〜(3)間の駅間最小所要秒数
		//		＜(3)の発時刻-60秒なら、
		//	(3)の着時刻=(1)の発時刻+(1)〜(3)間の駅間最小所要秒数
		//	とします。
		// --------------------------------

		int iDgrXPos = ekijikokuBefore.getDgrXPosHatsu() ;
		if ( iDgrXPos == INT_MIN )
		{
			iDgrXPos = ekijikokuBefore.getDgrXPosChaku() ;
		}
		iDgrXPos += calcEkikanSaisyouSec( 
			pMuCdDedDgrEki ,
			iEkiOrderBefore ,
			iEkiOrderAfter ) ; 
		//iDgrXPos = (1)の発時刻(なければ着時刻)+(1)〜(3)間の駅間最小所要秒数

		if ( iDgrXPos < ekijikokuAfter.getDgrXPosHatsu() - 60 )
		{
			//	(1)の発時刻(なければ着時刻)+(1)〜(3)間の駅間最小所要秒数
			//		＜(3)の発時刻-60秒なら、
			//	(3)の着時刻=(1)の発時刻+(1)〜(3)間の駅間最小所要秒数
			//	とします。
			ekijikokuAfter.setDgrXPosChaku( iDgrXPos ) ;
			m_MuCentDedDgrEkiJikoku.set( ekijikokuAfter ,iEkiOrderAfter ) ;
		}
		// --------------------------------
		//	次の検索開始位置を決める
		// --------------------------------
		{
			//	(1)(着時刻=あり or 発時刻=あり) AND 駅扱={停車,通過}のいずれか
			//	(3)着時刻=なし、発時刻=あり
			//	の両方が見つかった場合は、
			//	次の検索は (3)着時刻=なし、発時刻=あり
			//	から始めます。
			iEkiOrderBefore = iEkiOrderAfter - 1;
		}
	}
}

	//	(06_02)長時間停車を解決
	//		(長時間停車の着時刻=あり・発時刻=なし の駅に、発時刻を補う)
void CentDedDgrRessya::readCentDedRessya_06_complementLongStop_02( 
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) 
{
	// --------------------------------
	//	長時間停車の着時刻を補う
	// --------------------------------
	for ( int iEkiOrderBefore = 0 ; 
		iEkiOrderBefore < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrderBefore ++ )
	{
		// --------------------------------
		//	iEkiOrderBefore 以降で、以下の駅時刻の並びを探します。
		//	(1)着時刻=あり、発時刻=なし
		//	(2)「着時刻=なし、発時刻=なし、駅扱={通過,経由なし}のいずれか」
		//		の0個以上の並び
		//	(3)着時刻=あり、駅扱={停車,通過}のいずれか
		// --------------------------------
		//	(1)着時刻=あり、発時刻=なし
		//	の駅を探す
		CentDedDgrEkiJikoku	ekijikokuBefore = 
			m_MuCentDedDgrEkiJikoku.get( iEkiOrderBefore ) ;
		if ( !( 
			ekijikokuBefore.getDgrXPosChaku() != INT_MIN && 
			ekijikokuBefore.getDgrXPosHatsu() == INT_MIN 
		) )
		{
			continue ;
		}
		//iEkiOrderBefore,ekijikokuBefore = (1)着時刻=あり、発時刻=なし

		int iEkiOrderAfter = INT_MIN ;
		CentDedDgrEkiJikoku	ekijikokuAfter ;
		for ( iEkiOrderAfter = iEkiOrderBefore + 1  ;
				iEkiOrderAfter < m_MuCentDedDgrEkiJikoku.size() ;
				iEkiOrderAfter ++ )
		{
			ekijikokuAfter = 
				m_MuCentDedDgrEkiJikoku.get( iEkiOrderAfter ) ;
			if ( ekijikokuAfter.getDgrXPosChaku() == INT_MIN && 
				ekijikokuAfter.getDgrXPosHatsu() == INT_MIN && 
				( ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Teisya || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Tsuuka || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Keiyunasi ) )
			{
				//	(2)「着時刻=なし、発時刻=なし、
				//		駅扱={停車,通過,経由なし}のいずれか」
				//		の0個以上の並び
				continue ;
			}
			else if ( ekijikokuAfter.getDgrXPosChaku() != INT_MIN && 
				( ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Teisya || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Tsuuka ) )
			{
				//	(3)着時刻=あり、駅扱={停車,通過}のいずれか
				break ;
			}
			else
			{
				//	条件にあてはまらない駅時刻
				//(例：着時刻ありの駅・運行なしの駅)
				iEkiOrderAfter = INT_MIN ;
				break ;
			}
		}
		if ( iEkiOrderAfter == INT_MIN 
			|| iEkiOrderAfter == m_MuCentDedDgrEkiJikoku.size() )
		{
			//	条件を満たす駅が見つかりません
			continue ;
		}
		//iEkiOrderAfter,ekijikokuAfter = (3)着時刻=あり、
		//		駅扱={停車,通過}のいずれか

		// --------------------------------
		//	(1)の着時刻＜(3)の着時刻-(1)〜(3)間の駅間最小所要秒数-60秒なら、
		//	(1)の発時刻=(3)の着時刻-(1)〜(3)間の駅間最小所要秒数
		//	とします。
		// --------------------------------
		int iDgrXPos = ekijikokuAfter.getDgrXPosChaku() ;
		iDgrXPos -= calcEkikanSaisyouSec( 
			pMuCdDedDgrEki ,
			iEkiOrderBefore ,
			iEkiOrderAfter ) ; 
		//iDgrXPos = (3)の着時刻-(1)〜(3)間の駅間最小所要秒数

		if ( ekijikokuBefore.getDgrXPosChaku() < iDgrXPos - 60 )
		{
			//	(1)の着時刻＜(3)の着時刻-(1)〜(3)間の駅間最小所要秒数-60秒なら、
			//	(1)の発時刻=(3)の着時刻-(1)〜(3)間の駅間最小所要秒数
			//	とします。
			ekijikokuBefore.setDgrXPosHatsu( iDgrXPos ) ;
			m_MuCentDedDgrEkiJikoku.set( ekijikokuBefore ,iEkiOrderBefore ) ;
		}
		// --------------------------------
		//	次の検索開始位置を決める
		// --------------------------------
		{
			//	(1)発時刻=あり、駅扱={停車,通過}のいずれか
			//	(3)着時刻=なし、発時刻=あり
			//	の両方が見つかった場合は、
			//	次の検索は (3)着時刻=なし、発時刻=あり
			//	から始めます。
			iEkiOrderBefore = iEkiOrderAfter - 1;
		}
	}
}

	//(08)CentDedDgrRessyasenのコンテナを生成し、
	//  CentDedDgrEkijikoku::m_iDgrXPosOnRessyasen
	//を修正
void CentDedDgrRessya::readCentDedRessya_08_updateRessyasenCont(
	const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) 
{
	m_pCentDedDgrRessyasenCont->erase( 0 , INT_MAX ) ;

	Mu<CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku 
		= this->getMuCentDedDgrEkiJikoku() ;

	int iRessyasenKitenEkiOrder = 0 ;
	int iResult = 0 ;
	//(01)
	//『列車線起点駅Order』を探します。
	while ( ( iResult = updateRessyasenCont_01_calcRessyasenKiten( 
			iRessyasenKitenEkiOrder , 
			&iRessyasenKitenEkiOrder ) ) >= 0 )
	{
		//iRessyasenKitenEkiOrder = 『列車線起点駅Order』


		// --------------------------------
		int iRessyasenSyuutenEkiOrder = INT_MIN ;

		//(02)『列車線起点駅Order』に対応する『列車線終点駅Order』を検索します。
		//	
		//	  (1)　『列車線終点駅Order』の条件は、
		//「着時刻・発時刻の両方が指定されている」 OR
		//「 次の駅の駅扱いが『運行なし』 」 OR
		//「「『駅Order』が、その列車におけるの終着駅」 
		//	  対象駅がみつからなければ、列車線終点駅Orderの決定は失敗となります
		//  (経由なしの直前は、列車線の終点にはなりません
		//  　(この時点での列車線起点と終点は、経由なしをまたぐことがあります。)
		//
		//	  (2)　この時点で、『列車線終点駅Order』に着時刻も発時刻も
		//設定されていない場合は、
		//始発駅方向に向かって、着時刻・発時刻のいずれかが指定されている
		//駅を検索します。
		//	  この結果『列車線終点駅Order』に相当する駅がない場合は、
		//列車線終点駅Orderの決定は失敗となります。
		{
			int iResult = updateRessyasenCont_02_calcRessyasenSyuuten(
				iRessyasenKitenEkiOrder , 
				&iRessyasenSyuutenEkiOrder ) ;

			//iResult = 
			//	-	0 ;	//	『列車線終点駅Order』がみつかりました。
			//	-	-1 ;	//	列車線終点駅がありません。
			//				//	この区間に関しては、列車線を作成できません。
			if ( iResult == -1 )
			{
				iRessyasenKitenEkiOrder ++ ;
				continue ;
			}
			//iRessyasenSyuutenEkiOrder = 『列車線終点駅Order』（補正前）
		}
		//(04)
		//	『ダイヤグラム列車線』オブジェクト内の
		//	『列車線起点駅Order』と『列車線終点駅Order』の間の
		//	途中駅で、着時刻・発時刻のいずれかが指定されている主要駅があれば、
		//	それを
		//	『列車線終点駅Order』と『列車線終点時刻』にします。
		updateRessyasenCont_04_adjustRessyasenSyuuten4( 
			pMuCdDedDgrEki ,
			iRessyasenKitenEkiOrder ,
			&iRessyasenSyuutenEkiOrder ) ;
		LogMsgL(3, "updateRessyasenCont_adjustRessyasenSyuuten4()4"
			" Kiten=%d Syuuten=%d" ,
			iRessyasenKitenEkiOrder ,iRessyasenSyuutenEkiOrder ) ;

		// --------------------------------
		{
			bool	bRetryRequested = false ;
			do{
				bRetryRequested = false ;

				//	『列車線起点』と『列車線終点』の間に、列車線を生成
				CentDedDgrRessyasen	aRessyasen(
					iRessyasenKitenEkiOrder ,iRessyasenSyuutenEkiOrder ) ;
				m_pCentDedDgrRessyasenCont->insert( aRessyasen ) ;

				//(05)
				//『列車線コンテナ CentDedDgrRessyasenCont 』の末尾の
				//『列車線 CentDedDgrRessyasen』の途中駅の中で、
				//列車線の位置(CentDedDgrEkiJikoku::m_iDgrXPosRessyasen)と
				//着時刻・発時刻
				//(CentDedDgrEkiJikoku::m_iDgrXPosChaku,m_iDgrXPosHatsu)の
				//差が60 秒以上ある場合は、その駅を『列車線終点駅Order』と
				//	します。
				{
					int iResult=updateRessyasenCont_05_adjustRessyasenSyuuten5(
						&iRessyasenSyuutenEkiOrder ) ;
					//iResult = 
					//-	0 ;	//	『列車線終点駅Order』の補正の必要はありません
					//		//	でした。
					//-	1 ;	//	『列車線終点駅Order』の補正を行いました。
					if ( iResult == 1 )
					{
						//iRessyasenSyuutenEkiOrder = 
						//	『列車線終点駅Order』は修正されました。

						//	末尾の列車線を削除
						m_pCentDedDgrRessyasenCont->erase( INT_MAX ) ;

						bRetryRequested = true ;
					}
				}
			}	while ( bRetryRequested ) ;
		}


		//(06)	コンテナ末尾の列車線が途中に「経由なし」を含む場合、
		//	その列車線を「経由なし」までに短縮します。
		//	(1)「経由なし」直前の駅・直後の駅の着・発時刻を「列車線駅時刻」に
		//	置き換えます。
		//	(2)列車線は「経由なし」直前までに短縮します。
		//	(3)列車線終点を「経由なし」の直前とします。
		{
			int iResult = updateRessyasenCont_06_reduceToKeiyunasi( 
						&iRessyasenSyuutenEkiOrder ) ;
		}
		//	列車線起点駅は、直前の終点駅とします。
		iRessyasenKitenEkiOrder = iRessyasenSyuutenEkiOrder ;

	}
}

int CentDedDgrRessya::updateRessyasenCont_01_calcRessyasenKiten( 
		int iEkiOrder ,
		int* piRessyasenKitenEkiOrder ) 
{
	//	『列車線起点駅Order』の条件は、
	//	「着時刻・発時刻のいずれかが指定されている AND 
	//	次の『駅Order』の駅扱が『停車』か『通過』」
	Mu<CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku 
		= this->getMuCentDedDgrEkiJikoku() ;

	for ( ; iEkiOrder < pMuCentDedDgrEkiJikoku->size() - 1 ; 
			iEkiOrder ++ )
	{
		CentDedDgrEkiJikoku*	pEkiJikokuCurr = 
			pMuCentDedDgrEkiJikoku->get( iEkiOrder ) ;
		CentDedDgrEkiJikoku*	pEkiJikokuNext = 
			pMuCentDedDgrEkiJikoku->get( iEkiOrder + 1 ) ;
 
		int iDgrXPosHatsu = pEkiJikokuCurr->getDgrXPosHatsu( true ) ;
		if ( iDgrXPosHatsu != INT_MIN && 
			( pEkiJikokuNext->getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Teisya ||
			  pEkiJikokuNext->getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka ) ){
			*piRessyasenKitenEkiOrder = iEkiOrder ;
			return ( 0 ) ;
		} 
	}	
	return -1 ;	//	iEkiOrder 以降で、列車線起点駅がありません。
}

int CentDedDgrRessya::updateRessyasenCont_02_calcRessyasenSyuuten( 
		int iRessyasenKitenEkiOrder ,
		int* piRessyasenSyuutenEkiOrder ) 
{
	int iRv = 0 ;
	Mu<CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku 
		= this->getMuCentDedDgrEkiJikoku() ;

	int iSyuuchakuEki = getSyuuchakuEki()  ;
	int iRessyasenSyuutenEkiOrder = -1 ;

	//	  (1)　『列車線終点駅Order』の条件は、
	//「着時刻・発時刻の両方が指定されている」 OR
	//「 次の駅の駅扱いが『運行なし』 」 OR
	//「「『駅Order』が、その列車におけるの終着駅」 
	//	  対象駅がみつからなければ、列車線終点駅Orderの決定は失敗となります
	//  (経由なしの直前は、列車線の終点にはなりません
	//  　(この時点での列車線起点と終点は、経由なしをまたぐことがあります。)

	if ( iRv >= 0 )
	{
		for ( int iEkiOrder = iRessyasenKitenEkiOrder + 1 ; 
			iRessyasenSyuutenEkiOrder < 0 && 
				iEkiOrder <= iSyuuchakuEki ;
			iEkiOrder ++ )
		{
			CentDedDgrEkiJikoku	aEkiJikokuCurr = 
				*pMuCentDedDgrEkiJikoku->get( iEkiOrder ) ;
			CentDedDgrEkiJikoku	aEkiJikokuNext ;
			if ( iEkiOrder + 1 < pMuCentDedDgrEkiJikoku->size() )
			{
				aEkiJikokuNext = 
					*pMuCentDedDgrEkiJikoku->get( iEkiOrder + 1 ) ;
			}
			//aEkijikokuCurr = iEkiOrder の駅時刻
			//aEkiJikokuNext = iEkiOder の次の駅の駅時刻。
			//	iEkiOrderが終着駅の場合は、NULLとなります。


			int jikokuChaku = aEkiJikokuCurr.getDgrXPosChaku( false ) ;
			int	jikokuHatsu = aEkiJikokuCurr.getDgrXPosHatsu( false ) ;
			if ( jikokuChaku != INT_MIN && jikokuHatsu != INT_MIN )
			{
				//「着時刻・発時刻の両方が指定されている」 
				iRessyasenSyuutenEkiOrder = iEkiOrder ;
			}
			else if ( aEkiJikokuNext.getEkiatsukai() == 
						CentDedEkiJikoku::Ekiatsukai_None ) 
			{
				//	「次の駅の駅扱いが『運行なし』」  
				iRessyasenSyuutenEkiOrder = iEkiOrder ;
			}
			else if ( iEkiOrder == iSyuuchakuEki )
			{
				//	「「『駅Order』が、その列車におけるの終着駅」 
				iRessyasenSyuutenEkiOrder = iEkiOrder ;
			}
		}
		if ( iRessyasenSyuutenEkiOrder < 0 )
		{
			iRv = -1 ;	//	列車線終点が決定できません。(通常は発生しません)
		}
	}
	// iRessyasenSyuutenEkiOrder = 仮決定した列車線終点駅Order

	//	(2)　この時点で、『列車線終点駅Order』に着時刻も発時刻も
	//	設定されていない場合は、
	//	始発駅方向に向かって、着時刻・発時刻のいずれかが指定されている
	//	駅を検索します。
	//	  この結果『列車線終点駅Order』に相当する駅がない場合は、
	//	列車線終点駅Orderの決定は失敗となります。
	if ( iRv >= 0 )
	{
		for ( ; iRessyasenSyuutenEkiOrder > iRessyasenKitenEkiOrder ; 
			iRessyasenSyuutenEkiOrder -- )
		{
			CentDedDgrEkiJikoku	aEkiJikokuCurr = 
				*pMuCentDedDgrEkiJikoku->get( iRessyasenSyuutenEkiOrder ) ;
			int jikokuChaku = aEkiJikokuCurr.getDgrXPosChaku( false ) ;
			int	jikokuHatsu = aEkiJikokuCurr.getDgrXPosHatsu( false ) ;
			if ( jikokuChaku != INT_MIN || jikokuHatsu != INT_MIN )
			{
				//「着時刻・発時刻のどちらかが指定されている」 
				break ;
			}
		}
		if ( iRessyasenSyuutenEkiOrder == iRessyasenKitenEkiOrder )
		{
			iRv = -1 ;	//	列車線終点が決定できません。
		}
		//iRessyasenSyuutenEkiOrder = 
		//	着時刻・発時刻のいずれかが指定された、『列車線終点駅Order』
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		*piRessyasenSyuutenEkiOrder = iRessyasenSyuutenEkiOrder ;
	}
	return ( iRv ) ;
}

int CentDedDgrRessya::updateRessyasenCont_04_adjustRessyasenSyuuten4( 
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iRessyasenKitenEkiOrder ,
		int* piRessyasenSyuutenEkiOrder ) 
{
	int iRessyasenSyuutenEkiOrder = *piRessyasenSyuutenEkiOrder ;
	// --------------------------------
	//	『主要駅』を探します。
	// --------------------------------
	Mu<CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku 
		= this->getMuCentDedDgrEkiJikoku() ;
	for ( int iEkiOrder = iRessyasenKitenEkiOrder + 1 ;
		iEkiOrder < iRessyasenSyuutenEkiOrder ; 
		iEkiOrder ++ )
	{
		CentDedDgrEkiCont::CdDedDgrEki aCdDedDgrEki = 
			pMuCdDedDgrEki->get( iEkiOrder ) ;
		CentDedDgrEkiJikoku aCentDedDgrEkiJikoku = 
			*pMuCentDedDgrEkiJikoku->get( iEkiOrder ) ;
		int jikokuToueki = aCentDedDgrEkiJikoku.getDgrXPosChaku( true ) ;

		if ( jikokuToueki != INT_MIN && 
			aCdDedDgrEki.getIsSyuyoueki() )
		{
			//	『列車線起点駅Order』と『列車線終点駅Order』の間の
			//	途中駅で、着時刻・発時刻のいずれかが指定されている主要駅
			//	があれば、それを
			//	『列車線終点駅Order』とします。
			*piRessyasenSyuutenEkiOrder = iEkiOrder ;
			return 	1 ;	//	『列車線終点駅Order』の補正を行いました。
		}
		if ( aCentDedDgrEkiJikoku.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka && 
			( jikokuToueki != INT_MIN  ) )
		{
			//「通過駅で、
			//着時刻か発時刻のいずれかが指定されている」 
			*piRessyasenSyuutenEkiOrder = iEkiOrder ;
			return 	1 ;	//	『列車線終点駅Order』の補正を行いました。
		}


	}
	return 0 ;
}


int CentDedDgrRessya::updateRessyasenCont_05_adjustRessyasenSyuuten5( 
		int* piRessyasenSyuutenEkiOrder ) 
{
	int iRv = 0 ;
	CentDedDgrRessyasen aCentDedDgrRessyasen 
		= m_pCentDedDgrRessyasenCont->get( INT_MAX ) ;

	for ( int iEkiOrder = *piRessyasenSyuutenEkiOrder - 1 ;
		iRv==0 && iEkiOrder > aCentDedDgrRessyasen.getRessyasenKitenEkiOrder();
		iEkiOrder -- )
	{
		CentDedDgrEkiJikoku	aEkiJikoku = m_MuCentDedDgrEkiJikoku.get( 
			iEkiOrder ) ;

		//列車線の位置(CentDedDgrEkiJikoku::m_iDgrXPosRessyasen)と
		//着時刻・発時刻(CentDedDgrEkiJikoku::m_iDgrXPosChaku,m_iDgrXPosHatsu)の
		//差が60 秒以上ある
		//場合は、その駅を『列車線終点駅Order』とします。
		int iDgrXPosChakuHatsu = aEkiJikoku.getDgrXPosHatsu( true ) ;
		int iDgrXPosRessyasen = aEkiJikoku.getDgrXPosRessyasen() ;
		if ( iDgrXPosChakuHatsu != INT_MIN && 
			abs( iDgrXPosChakuHatsu - iDgrXPosRessyasen ) >= 60 )
		{
			*piRessyasenSyuutenEkiOrder = iEkiOrder ;
			iRv = 1 ;	//	『列車線終点駅Order』の補正を行いました。
		}
	}
	return iRv ;
}



int CentDedDgrRessya::updateRessyasenCont_06_reduceToKeiyunasi( 
		int* piRessyasenSyuutenEkiOrder ) 
{
	int iRv = 0 ;
	CentDedDgrRessyasen aCentDedDgrRessyasen = m_pCentDedDgrRessyasenCont->get(
		INT_MAX ) ;
	// --------------------------------
	//	列車線内に含まれる、
	//	経由なしの始点と終点を検索
	// --------------------------------
	int iEkiOrderBeforeKeiyunasi = INT_MIN ;
	int iEkiOrderAfterKeiyunasi = INT_MIN ;
	for ( int iEkiOrder = aCentDedDgrRessyasen.getRessyasenKitenEkiOrder()+1 ;
		iEkiOrderBeforeKeiyunasi == INT_MIN 
			&& iEkiOrder < *piRessyasenSyuutenEkiOrder ;
		iEkiOrder ++ )
	{
		CentDedDgrEkiJikoku	aEkiJikokuNext = m_MuCentDedDgrEkiJikoku.get( 
			iEkiOrder + 1 ) ;

		if ( aEkiJikokuNext.getEkiatsukai() 
			== CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
		{
			iEkiOrderBeforeKeiyunasi = iEkiOrder ;
		}
	}
	if ( iEkiOrderBeforeKeiyunasi != INT_MIN )
	{
		int iEkiOrder = 0 ;
		for ( iEkiOrder = iEkiOrderBeforeKeiyunasi + 1 ;
			iEkiOrderAfterKeiyunasi == INT_MIN 
				&& iEkiOrder < *piRessyasenSyuutenEkiOrder ;
			iEkiOrder ++ )
		{
			CentDedDgrEkiJikoku	aEkiJikoku = m_MuCentDedDgrEkiJikoku.get( 
				iEkiOrder ) ;

			//駅扱が『経由なし』の終端地点を探します。
			if ( aEkiJikoku.getEkiatsukai() 
				!= CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				iEkiOrderAfterKeiyunasi = iEkiOrder ;
			}
		}
		//iEkiOrderAfterKeiyunasi = iEkiOrderBeforeKeiyunasi 以後で最初の
		//	「駅扱が『経由なし』以外の駅」の駅Order。
		//	但し、これが「列車線終点駅Orderの場合」は、INT_MINとなります。
	}

	//iEkiOrderBeforeKeiyunasi = 『経由なし』直前の駅Order
	//iEkiOrderAfterKeiyunasi = 『経由なし』直後の駅Order
	//	但し、「『経由なし』直後の駅Order」が
	//	「列車線終点駅Orderの場合」は、INT_MINとなります。

	if ( iEkiOrderBeforeKeiyunasi != INT_MIN ) 
	{
		//	『経由なし』直前の駅Orderの
		//	発着時刻を、列車線上の時刻に変更します
		CentDedDgrEkiJikoku aCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.get( iEkiOrderBeforeKeiyunasi ) ;
		aCentDedDgrEkiJikoku.setDgrXPosChaku( 
			aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ;
		aCentDedDgrEkiJikoku.setDgrXPosHatsu( 
			aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ;
		m_MuCentDedDgrEkiJikoku.set( 
			aCentDedDgrEkiJikoku , iEkiOrderBeforeKeiyunasi ) ;

		if ( iEkiOrderAfterKeiyunasi != INT_MIN )
		{
			//	『経由なし』直後の駅Orderの
			//	発着時刻を、列車線上の時刻に変更します
			CentDedDgrEkiJikoku aCentDedDgrEkiJikoku = 
				m_MuCentDedDgrEkiJikoku.get( iEkiOrderAfterKeiyunasi ) ;
			aCentDedDgrEkiJikoku.setDgrXPosChaku( 
				aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ;
			aCentDedDgrEkiJikoku.setDgrXPosHatsu( 
				aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ;
			m_MuCentDedDgrEkiJikoku.set( 
				aCentDedDgrEkiJikoku , iEkiOrderAfterKeiyunasi ) ;
		}

		//	末尾の列車線を置きかえます。
		m_pCentDedDgrRessyasenCont->erase( INT_MAX ) ;
		aCentDedDgrRessyasen.setSyuuten( iEkiOrderBeforeKeiyunasi ) ;
		m_pCentDedDgrRessyasenCont->insert( aCentDedDgrRessyasen ) ;

		//駅扱が『経由なし』の駅時刻がある場合は、
		//その直前を『列車線終点駅Order』とします。
		*piRessyasenSyuutenEkiOrder = iEkiOrderBeforeKeiyunasi ;

		iRv = 1 ;
	}
	return iRv ;
}

// --------------------------------
//@name 下請関数
// --------------------------------



// ********************************
//	コンストラクタ
// ********************************
CentDedDgrRessya::CentDedDgrRessya( 
		const CentDedRosen* pCentDedRosen ,
		const CentDedDgrDia* pCentDedDgrDia ,
		const CentDedRessya* pCentDedRessya ) 
	: m_bIsNull( true ) 
	, m_eRessyahoukou( pCentDedRessya->getRessyahoukou() ) 
	, m_iRessyasyubetsuIndex( 0 )
	, m_pCentDedDgrDia( pCentDedDgrDia ) 
	, m_pCentDedDgrRessyasenCont( NULL ) 
{
	m_pCentDedDgrRessyasenCont = new CentDedDgrRessyasenCont(
		this ) ;

	readCentDedRessya( pCentDedRosen ,
		pCentDedDgrDia ,
		pCentDedRessya ) ; 

}
	
CentDedDgrRessya::CentDedDgrRessya( 
	const CentDedDgrDia* pCentDedDgrDia )
	: m_bIsNull( true ) 
	, m_eRessyahoukou( Ressyahoukou_Kudari ) 
	, m_iRessyasyubetsuIndex( 0 )
	, m_pCentDedDgrDia( pCentDedDgrDia ) 
	, m_pCentDedDgrRessyasenCont( NULL ) 
{
	m_pCentDedDgrRessyasenCont = new CentDedDgrRessyasenCont(
		this ) ;
}

CentDedDgrRessya::CentDedDgrRessya( const CentDedDgrRessya& value )
	: m_bIsNull( value.m_bIsNull ) 
	, m_eRessyahoukou( value.m_eRessyahoukou ) 
	, m_iRessyasyubetsuIndex( value.m_iRessyasyubetsuIndex )
	, m_strRessyabangou( value.m_strRessyabangou ) 
	, m_strRessyamei( value.m_strRessyamei ) 
	, m_strGousuu( value.m_strGousuu ) 
	, m_DgrXZone( value.m_DgrXZone ) 
	, m_pCentDedDgrDia( value.m_pCentDedDgrDia ) 
	, m_MuCentDedDgrEkiJikoku( value.m_MuCentDedDgrEkiJikoku )
	, m_pCentDedDgrRessyasenCont( NULL ) 
{
	m_pCentDedDgrRessyasenCont = new CentDedDgrRessyasenCont(
		this ) ;

	*m_pCentDedDgrRessyasenCont = *value.m_pCentDedDgrRessyasenCont ;
}


CentDedDgrRessya& CentDedDgrRessya::operator=( const CentDedDgrRessya& value )
{
	m_bIsNull = value.m_bIsNull ;
	m_eRessyahoukou = value.m_eRessyahoukou ;
	m_iRessyasyubetsuIndex = value.m_iRessyasyubetsuIndex ;
	m_strRessyabangou = value.m_strRessyabangou ;
	m_strRessyamei = value.m_strRessyamei ;
	m_strGousuu = value.m_strGousuu ;
	m_DgrXZone = value.m_DgrXZone ;
	m_MuCentDedDgrEkiJikoku = value.m_MuCentDedDgrEkiJikoku ;
	*m_pCentDedDgrRessyasenCont = *value.m_pCentDedDgrRessyasenCont ;

	return *this ;
}

CentDedDgrRessya::~CentDedDgrRessya() 
{
	delete m_pCentDedDgrRessyasenCont ;	m_pCentDedDgrRessyasenCont = NULL ;
}
	
// ********************************
//	CentDedDgrRessya
// ********************************
	// ********************************
	//@name 属性
	// ********************************
bool CentDedDgrRessya::getIsNull()const
{
	return m_bIsNull ;
}
ERessyahoukou	CentDedDgrRessya::getRessyahoukou()const 
{
	return m_eRessyahoukou ;
}
CentDedDgrRessya& CentDedDgrRessya::setRessyahoukou( ERessyahoukou value ) 
{
	m_eRessyahoukou = value ;
	return *this ;
}

int	CentDedDgrRessya::getRessyasyubetsuIndex()const
{
	return m_iRessyasyubetsuIndex ;
};
void CentDedDgrRessya::setRessyasyubetsuIndex( int value )
{
	m_iRessyasyubetsuIndex = value ; 
};


string CentDedDgrRessya::getRessyabangou()const
{
		return m_strRessyabangou ;
};
CentDedDgrRessya& CentDedDgrRessya::setRessyabangou( const string& value )
{
		m_bIsNull = false ;
		m_strRessyabangou = value ; 
		return *this ; 
} ;
string CentDedDgrRessya::getRessyamei()const
{
		return m_strRessyamei ;
};
CentDedDgrRessya& CentDedDgrRessya::setRessyamei( const string& value )
{
		m_bIsNull = false ;
		 m_strRessyamei = value ; 
		return *this ; 
} ;
string CentDedDgrRessya::getGousuu()const
{
		return m_strGousuu ;
};
CentDedDgrRessya& CentDedDgrRessya::setGousuu( const string& value )
{
		m_bIsNull = false ;
		 m_strGousuu = value ; 
		return *this ; 
} ;
CdDcdZone	CentDedDgrRessya::getDgrXZone()const
{
	return m_DgrXZone ;
};

	// ********************************
	//@name 包含
	// ********************************
Mu< CentDedDgrEkiJikoku* >* 
CentDedDgrRessya::getMuCentDedDgrEkiJikoku() 
{
	return m_MuCentDedDgrEkiJikoku.getMuPtr() ;
}
const Mu< const CentDedDgrEkiJikoku* >* 
CentDedDgrRessya::getMuCentDedDgrEkiJikoku()const 
{
	return m_MuCentDedDgrEkiJikoku.getMuPtr() ;
}

Mu< CentDedDgrRessyasen* >* CentDedDgrRessya::
	getCentDedDgrRessyasenCont()
{
	return m_pCentDedDgrRessyasenCont->getMuPtr() ;
}
const Mu< const CentDedDgrRessyasen* >* CentDedDgrRessya::
	getCentDedDgrRessyasenCont()const 
{
	return ((const CentDedDgrRessyasenCont*)m_pCentDedDgrRessyasenCont)->getMuPtr() ;
}


	// ********************************
	//@name 操作
	// ********************************
void CentDedDgrRessya::clear()
{
	m_bIsNull = NULL ;
	m_eRessyahoukou = Ressyahoukou_Kudari ;
	m_iRessyasyubetsuIndex = 0 ;
	m_strRessyabangou.erase() ;
	m_strRessyamei.erase() ;
	m_strGousuu.erase() ;
	m_DgrXZone.setPos( 0 ).setSize( 0 ) ;
	m_MuCentDedDgrEkiJikoku.erase( 0 , INT_MAX ) ;
	m_pCentDedDgrRessyasenCont->erase( 0 , INT_MAX ) ;
}
int CentDedDgrRessya::readCentDedRessya(
		const CentDedRosen* pCentDedRosen ,
		const CentDedDgrDia* pCentDedDgrDia ,
		const CentDedRessya* pCentDedRessya ) 
{
	int iRv = 0 ;
	//	包含するオブジェクトを全てクリアし、NULL状態にします
	clear() ;

	//(01)CentDedDgrRessyaの属性のうち、CentDedRessya のみで決定する属性を設定
	readCentDedRessya_01_readProp( pCentDedRessya ) ;

	//(02)CentDedDgrEkiJikoku を生成し、 CentDedEkiJikoku で決まる属性を決定。
	readCentDedRessya_02_CreateCentDedEkiJikoku( pCentDedRessya ) ;

	//(03)CentDedDgrRessyaの以下の属性を、CentDedDgrEkiJikokuの属性を
	//	もとに生成。
	//	CdDcdZone	m_zoneDgrXZahyou
	readCentDedRessya_03_updateDgrXZone() ;

	//(04)CentDedDgrEkijikokuの以下の属性を、CentDedDgrEki の属性をもとに決定。
	//	m_bShouldRessyajouhouDraw //列車情報をこの駅の場所に描画するなら真です。
	readCentDedRessya_04_updateShouldRessyajouhouDraw(
		pCentDedDgrDia->getCentDedDgrEkiCont()->getMuPtr( m_eRessyahoukou ) ) ;

	//	(05)経由なしの前後の着発時刻を補う
	readCentDedRessya_05_complementKeiyunasiSide() ; 

	//	(06_01)長時間停車を解決
	//		(長時間停車の着時刻=なし・発時刻=あり の駅に、着時刻を補う)
	readCentDedRessya_06_complementLongStop_01( 
		pCentDedDgrDia->getCentDedDgrEkiCont()->getMuPtr( m_eRessyahoukou ) ) ;

	//	(06_02)長時間停車を解決
	//		(長時間停車の着時刻=あり・発時刻=なし の駅に、発時刻を補う)
	readCentDedRessya_06_complementLongStop_02( 
		pCentDedDgrDia->getCentDedDgrEkiCont()->getMuPtr( m_eRessyahoukou ) ) ;

	//(08)CentDedDgrRessyasenのコンテナを生成し、
	//  CentDedDgrEkijikoku::m_iDgrXPosOnRessyasen
	//を修正
	readCentDedRessya_08_updateRessyasenCont( 
		pCentDedDgrDia->getCentDedDgrEkiCont()->getMuPtr( m_eRessyahoukou ) ) ;
	
	return ( iRv ) ;
}

int CentDedDgrRessya::getSihatsuEki()const 
{
	int	iRv = -1 ;
	// --------------------------------
	int iEkiOrder = 0 ;
	for ( iEkiOrder = 0 ; 
			iRv == -1 && 
			iEkiOrder < (int)m_MuCentDedDgrEkiJikoku.size() ; 
			iEkiOrder ++ )
	{
		const CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;
		if ( pCentDedDgrEkiJikoku->getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None )
		{
			iRv = iEkiOrder ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedDgrRessya::getSyuuchakuEki()const 
{
	int	iRv = -1 ;
	// --------------------------------
	int iEkiOrder = 0 ;
	for ( iEkiOrder = (int)m_MuCentDedDgrEkiJikoku.size() - 1 ; 
			iRv == -1 && 
			iEkiOrder >= 0 ; 
			iEkiOrder -- )
	{
		const CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;
		if ( pCentDedDgrEkiJikoku->getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None )
		{
			iRv = iEkiOrder ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

bool CentDedDgrRessya::isRunBetweenNextEki( int iEkiOrder )const 
{
	bool bRv = false ;
	if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_MuCentDedDgrEkiJikoku.size() - 1 ) )
	{
		bRv = false ;	//	『駅Index』が不正です。
	}
	else
	{
		const CentDedDgrEkiJikoku* pEkijikoku 
			= m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;
		const CentDedDgrEkiJikoku* pEkijikokuNext 
			= m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder + 1 ) ;
		if ( 
			( pEkijikoku->getEkiatsukai()
					==CentDedEkiJikoku::Ekiatsukai_Teisya
				|| pEkijikoku->getEkiatsukai() 
					== CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
			&& ( pEkijikokuNext->getEkiatsukai() 
					== CentDedEkiJikoku::Ekiatsukai_Teisya 
				|| pEkijikokuNext->getEkiatsukai() 
					== CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
		)
		{
			bRv = true ;
		}

	}
	return bRv ;
}

int CentDedDgrRessya::calcEkikanSaisyouSec(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iEkiOrderBefore ,
		int iEkiOrderAfter )const 
{
	int iRv = 0 ;
	for ( int iEkiOrder = iEkiOrderBefore ;
		iEkiOrder < iEkiOrderAfter ;
		iEkiOrder ++ )
	{
		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki = 
				pMuCdDedDgrEki->get( iEkiOrder ) ;
			iRv += aCdDedDgrEki.getEkikanSaisyouSec() ;
		}
	}
	return iRv ;
}

int CentDedDgrRessya::calcDgrYEkikanSize(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iEkiOrderBefore ,
		int iEkiOrderAfter )const 
{
	int iRv = 0 ;
	for ( int iEkiOrder = iEkiOrderBefore ;
		iEkiOrder < iEkiOrderAfter ;
		iEkiOrder ++ )
	{
		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki = 
				pMuCdDedDgrEki->get( iEkiOrder ) ;
			iRv += aCdDedDgrEki.getDgrYSizeEkikan() ;
		}
	}
	return iRv ;
}


void CentDedDgrRessya::modifyDgrXPos( int iSeconds ) 
{
	int idx ;
	for ( idx = 0 ; idx < m_MuCentDedDgrEkiJikoku.size() ; idx ++ )
	{
		CentDedDgrEkiJikoku	aCentDedDgrEkiJikoku 
			= m_MuCentDedDgrEkiJikoku.get( idx ) ;
		aCentDedDgrEkiJikoku.modifyDgrXPos( iSeconds ) ;
		m_MuCentDedDgrEkiJikoku.set( aCentDedDgrEkiJikoku , idx ) ;
	}
	{
		m_DgrXZone.setPos( m_DgrXZone.getPos() + iSeconds ) ;
	}
}

int CentDedDgrRessya::getDgrXPosOfJikokuOrder(
		CdDedJikokuOrder aCdDedJikokuOrder , 
		int* piDgrXPos )const 
{
	int iRv = 0 ;
	int iDgrXPos = INT_MIN ;

	const Mu<const CentDedDgrEkiJikoku*>* muCentDedDgrEkiJikoku = this->getMuCentDedDgrEkiJikoku() ;

	const CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = muCentDedDgrEkiJikoku->get( aCdDedJikokuOrder.getEkiOrder() ) ;
	if ( !( pCentDedDgrEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya || 
		pCentDedDgrEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka ) )
	{
		iRv = -1 ;	//	この駅の座標を取得できません。
	}
	else if ( pCentDedDgrEkiJikoku->getDgrXPosRessyasen() != INT_MIN )
	{
		//	この駅に列車線X座標がある(列車線の途中)なら、
		//	そのX座標を採用
		iDgrXPos = pCentDedDgrEkiJikoku->getDgrXPosRessyasen() ;
	}
	else if ( aCdDedJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku)
	{
		//	指定の駅時刻Orderが着時刻
		//	着時刻の座標を取得(なければ発)
		iDgrXPos = pCentDedDgrEkiJikoku->getDgrXPosChaku( true ) ;
		if ( iDgrXPos == INT_MIN )
		{
			iRv = -1 ;	//	この駅の座標を取得できません。
		}
	}
	else
	{
		//	指定の駅時刻Orderが発時刻
		//	発時刻の座標を取得(なければ着)
		iDgrXPos = pCentDedDgrEkiJikoku->getDgrXPosHatsu( true ) ;
		if ( iDgrXPos == INT_MIN )
		{
			iRv = -1 ;	//	この駅の座標を取得できません。
		}
	}
	// --------------------------------
	if ( piDgrXPos != NULL )
	{
		*piDgrXPos = iDgrXPos ;
	}
	return iRv ;
}


int CentDedDgrRessya::getDgrXPosOfEkiOrder(
		int iEkiOrder , 
		int* piDgrXPos )const 
{
	int iDgrXPos = 0 ;
	int iRv = -1 ;
	if ( iRv == -1 )
	{
		iRv = this->getDgrXPosOfJikokuOrder( 
			CdDedJikokuOrder( iEkiOrder , CdDedJikokuOrder::EkiJikokuItem_Hatsu )  , 
			&iDgrXPos ) ;

	}
	if ( iRv == -1 )
	{
		//	駅Orderの着時刻の座標を取得
		iRv = this->getDgrXPosOfJikokuOrder( 
			CdDedJikokuOrder( iEkiOrder , CdDedJikokuOrder::EkiJikokuItem_Chaku ) , 
			&iDgrXPos ) ;

	}
	// --------------------------------
	if ( piDgrXPos != NULL ){
		*piDgrXPos = iDgrXPos ;
	}
	return ( iRv ) ;

	// ----------------------------------------------------------------
}

} //namespace entDgr
