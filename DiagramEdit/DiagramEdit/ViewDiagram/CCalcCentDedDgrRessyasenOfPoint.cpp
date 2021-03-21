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
//	CCalcCentDedDgrRessyasenOfPoint.cpp
// $Id: CCalcCentDedDgrRessyasenOfPoint.cpp 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "DcdCd\Pos\CLineFunc.h"
#include "LogMsg\LogMsg.h"

#include "CCalcCentDedDgrRessyasenOfPoint.h"

namespace ViewDiagram{

CCalcCentDedDgrRessyasenOfPoint::CCalcCentDedDgrRessyasenOfPoint(
		CDcdDiagram* pCDcdDiagram , 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdPosXy& aCdDcdPosXy , int iMarginPixels ,
		bool bDisplayRessyasenKudari , bool bDisplayRessyasenNobori ) : 
	super( pCDcdDiagram->getCentDedDgrDia() , 
		pCDcdDiagram->DgrFromDcd( pIfDcdTarget , pIfDcdTarget->getZone() ) , 
		bDisplayRessyasenKudari , 
		bDisplayRessyasenNobori ) , 
	m_pCDcdDiagram( pCDcdDiagram ) ,
	m_pIfDcdTarget( pIfDcdTarget ) ,
	m_CdDcdPosXy( aCdDcdPosXy ) ,
	m_iMerginPixels( iMarginPixels ) ,
	m_eRessyahoukou( Ressyahoukou_Kudari ) ,
	m_iRessyaIdx( -1 ) ,
	m_iRessyasenIdx( -1 )
{
};

void CCalcCentDedDgrRessyasenOfPoint::onCentDedDgrRessyasen( 
			ERessyahoukou eRessyahoukou ,
			int iRessyaIdx ,
			const CentDedDgrRessya* pCentDedDgrRessya ,
			int iRessyasenIdx ,
			const CentDedDgrRessyasen* pCentDedDgrRessyasen ) 
{
	//	列車線が見つかっている場合は、
	//	この後の処理は行わずにリターン
	if ( m_iRessyaIdx != -1 )
	{
		return ;
	}	
	// --------------------------------
	CdDcdPosXy	posDgrPosRessyasenKiten = 
		getCentDedDgrDia()->calcDgrPosRessyasenKiten( 
			pCentDedDgrRessya , 
			pCentDedDgrRessyasen ) ;
	CdDcdPosXy	posDgrPosRessyasenSyuuten = 
		getCentDedDgrDia()->calcDgrPosRessyasenSyuuten( 
			pCentDedDgrRessya , 
			pCentDedDgrRessyasen ) ;
	//posDgrPosRessyasenKiten,posDgrPosRessyasenSyuuten = 
	//	この列車線の起点と終点の座標を、
	//	Dgr座標系で表します。

	CLineFunc aCLineFunc( 
		m_pCDcdDiagram->DgrToDcd( m_pIfDcdTarget , 
			posDgrPosRessyasenKiten )  , 
		m_pCDcdDiagram->DgrToDcd( m_pIfDcdTarget , 
			posDgrPosRessyasenSyuuten ) ) ;
	//aCLineFunc = 
	//	この列車線の起点から終点までを結ぶ直線を、
	//	DcDraw 座標系で表します。

	LogMsg( "CCalcCentDedDgrRessyasenOfPoint::onCentDedDgrRessyasen("
		"eRessyahoukou=%d ,iRessyaIdx=%d ,,iRessyasenIdx =%d,)"  ,
		eRessyahoukou ,
		iRessyaIdx ,
		iRessyasenIdx  ) ; 
	LogMsg( "\taCLineFunc.Pos1=%d,%d , Pos2=%d,%d   m_CdDcdPosXy=%d,%d" , 
		aCLineFunc.getPos1().getX() , 
		aCLineFunc.getPos1().getY() , 
		aCLineFunc.getPos2().getX() , 
		aCLineFunc.getPos2().getY() ,
		m_CdDcdPosXy.getX() , m_CdDcdPosXy.getY() ) ;

	// --------------------------------
	//	「『検索対象点』が、列車線の始点・終点を包含する長方形の
	//	範囲内にあるか」を判定
	// --------------------------------
	{
		CdDcdZone	zoneDcdXBoundRessyasen ;
		{
			zoneDcdXBoundRessyasen.setBeginEndPos( 
				aCLineFunc.getPos1().getX() ,
				aCLineFunc.getPos2().getX() ) ;
			//	サイズが0の場合は、1に最適化します。
			//	始点と終点のX座標が等しい場合(垂直線)
			//	が該当します。
			if ( zoneDcdXBoundRessyasen.getSize() == 0 )
			{
				zoneDcdXBoundRessyasen.setSize( 1 ) ;
			}
		}
		//zoneDcdXBoundRessyasen = 
		//	列車線の起点から終点までのX座標の領域です。
		//	Dcd座標系で表します。
		//	サイズが0の場合は、1に最適化します。

		CdDcdZone	zoneDcdYBoundRessyasen ;
		{
			zoneDcdYBoundRessyasen.setBeginEndPos( 
				aCLineFunc.getPos1().getY() ,
				aCLineFunc.getPos2().getY() ) ;

			//	サイズが0の場合は、1に最適化します。
			//	始点と終点のY座標が等しい場合(水平線)場合
			//	が該当します。
			if ( zoneDcdYBoundRessyasen.getSize() == 0 )
			{
				zoneDcdYBoundRessyasen.setSize( 1 ) ;
			}
		}
		//zoneDcdYBoundRessyasen = 
		//	列車線の起点から終点までのY座標の領域です。
		//	Dcd座標系で表します。
		//	サイズが0の場合は、1に最適化します。

		CdDcdZoneXy	zonexyDcdBoundRessyasen( 
			zoneDcdXBoundRessyasen ,
			zoneDcdYBoundRessyasen ) ;
		//zonexyDcdBoundRessyasen = 
		//	列車線の起点から終点までを囲む長方形の領域です。
		//	X,Yとも、サイズが0の場合は、1に最適化します。
		//理由：
		//	列車線が垂直線の場合、普通に計算すると、
		//	zonexyDcdBoundRessyasenの XのSize は、0になります。
		//	しかし、zonexyDcdBoundRessyasenの X または Y の Size が
		//	0 だと、 zonexyDcdBoundRessyasen.IsInner() の結果は常に
		//	false になり、範囲内の判定が正しくできません。
		//	これを避けるために、X,YのSizeは、0 の場合は 1に最適化します。

		if ( !zonexyDcdBoundRessyasen.IsInner( m_CdDcdPosXy ) )
		{
			//	『検索対象点』が、列車線の始点・終点を包含する長方形の
			//	範囲内にありません。
			return ;
		}
	}
	// --------------------------------
	//	検索対象点が、列車線の線上にあることを判定
	// --------------------------------
	if ( abs( aCLineFunc.getPos1().getX() - aCLineFunc.getPos2().getX() ) >
		abs( aCLineFunc.getPos1().getY() - aCLineFunc.getPos2().getY() ) )
	{
		//	Xの方が長い列車線
		int iY = aCLineFunc.calcYofX( m_CdDcdPosXy.getX() ) ;
		if ( abs( iY - m_CdDcdPosXy.getY() ) <= m_iMerginPixels )
		{
			LogMsg( "\tfind iY=%d" , iY ) ;
			m_eRessyahoukou = eRessyahoukou ;
			m_iRessyaIdx = iRessyaIdx ;
			m_iRessyasenIdx = iRessyasenIdx ;
		}
	}
	else
	{
		//	Yの方が長い列車線
		int iX = aCLineFunc.calcXofY( m_CdDcdPosXy.getY() ) ;
		if ( abs( iX - m_CdDcdPosXy.getX() ) <= m_iMerginPixels )
		{
			LogMsg( "\tfind iX=%d" , iX ) ;
			m_eRessyahoukou = eRessyahoukou ;
			m_iRessyaIdx = iRessyaIdx ;
			m_iRessyasenIdx = iRessyasenIdx ;
		}
	} 
	//m_eRessyahoukou,m_iRessyaIdx,m_iRessyasenIdx = 
	//	検索対象点を通る列車線が見つかった場合は、
	//	その列車線を示す属性となります。
};
} //namespace ViewDiagram
