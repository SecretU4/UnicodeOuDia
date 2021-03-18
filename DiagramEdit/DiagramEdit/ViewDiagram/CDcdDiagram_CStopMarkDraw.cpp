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
// ****************************************************************
//	CDcdDiagram_CStopMarkDraw.cpp
//	$Id: CDcdDiagram_CStopMarkDraw.cpp 367 2016-08-19 10:14:24Z okm $
// ****************************************************************
/** @file */
#include "stdafx.h"
#include <math.h>

#include "CDcdDiagram_CStopMarkDraw.h"

namespace ViewDiagram{

// ********************************
//	コンストラクタ
// ********************************
CDcdDiagram_CStopMarkDraw::CDcdDiagram_CStopMarkDraw( CDcdDiagram* pCDcdDiagram , 
			IfDcdTarget* pIfDcdTarget , 
			bool bDisplayRessyasenKudari ,
			bool bDisplayRessyasenNobori ) :
	super( 
		pCDcdDiagram->getCentDedDgrDia() , 
		pCDcdDiagram->DgrFromDcd( pIfDcdTarget , pIfDcdTarget->getZone() ) , 
		bDisplayRessyasenKudari , 
		bDisplayRessyasenNobori ) ,
	m_pCDcdDiagram( pCDcdDiagram ) ,
	m_pIfDcdTarget( pIfDcdTarget ) 
{
};

// ********************************
//	CDcdDiagram::CEnumRessyasen
// ********************************
void CDcdDiagram_CStopMarkDraw::onCentDedDgrEkiJikoku( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ,
		int iEkiOrder , 
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku ) 
{
	if ( m_pCDcdDiagram->getStopMarkDraw() != 
		CDcdDiagram::EStopMarkDraw_DrawOnBriefStop )
	{
		//	現在のモードでは、停車マークの描画を行いません。
		return ;
	}
	if ( iEkiOrder == pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() )
	{
		//	列車線終点には、テキストの描画を行いません
		return ;
	}
	// --------------------------------
	//	この列車種別で描画を行うか否かを判定
	// --------------------------------
	CentDedRessyasyubetsu::EStopMarkDrawType	eStopMarkDrawType = 
		CentDedRessyasyubetsu::EStopMarkDrawType_DrawOnStop ;
	{
		int idxRessyasyubetsu = pCentDedDgrRessya->getRessyasyubetsuIndex() ;
		if ( 0 <= idxRessyasyubetsu && 
			idxRessyasyubetsu < getCentDedDgrDia()->getMuCentDedDgrRessyasyubetsu()->size() )
		{
			const CentDedDgrRessyasyubetsu* pCentDedDgrRessyasyubetsu = 
				getCentDedDgrDia()->getMuCentDedDgrRessyasyubetsu()->get( idxRessyasyubetsu ) ;
			eStopMarkDrawType = pCentDedDgrRessyasyubetsu->getStopMarkDrawType() ;
		}
	}
	//eStopMarkDrawType = 停車駅描画モード


	// --------------------------------
	//	停車マークを描画する位置を算出
	// --------------------------------
	int iX_Dcd = 0 ;
	int iY_Dcd = 0 ;
	{
		int iY_Dgr = getCentDedDgrDia()->getDgrYPosOfEki( 
			pCentDedDgrRessya->getRessyahoukou() , iEkiOrder ) ;
		int iX_Dgr = 0 ;
		int iResult = pCentDedDgrRessya->getDgrXPosOfEkiOrder( 
			iEkiOrder , &iX_Dgr ) ;
		if ( iResult < 0 ){
			return ;
		}
		//iX_Dgr,iY_Dgr = 列車情報を表示する駅の発時刻の座標
		//	単位は、『ダイヤグラムエンティティ座標系』

		iX_Dcd = m_pCDcdDiagram->XDgrToDcd( m_pIfDcdTarget , iX_Dgr  ) ;
		iY_Dcd = m_pCDcdDiagram->YDgrToDcd( m_pIfDcdTarget , iY_Dgr  ) ;
	}
	//iX_Dcd,iY_Dcd = 列車情報を表示する駅の発時刻の座標
	//	単位は、 IfDcdTarget の座標系

	// --------------------------------
	//	停車時間を算出
	// --------------------------------
	int iStopSeconds = 0 ;
	{
		if ( pCentDedDgrEkiJikoku->getDgrXPosChaku() != INT_MIN && 
			pCentDedDgrEkiJikoku->getDgrXPosHatsu() != INT_MIN )
		{
			iStopSeconds = pCentDedDgrEkiJikoku->getDgrXPosHatsu() - 
				pCentDedDgrEkiJikoku->getDgrXPosChaku() ;
		}
	}

	// --------------------------------
	//	当駅が始発駅でも終着駅でもない
	//	列車種別が停車駅を明示 AND 当駅が短時間停車(60秒未満)
	//	であれば、停車マークを描画
	// --------------------------------
	if ( pCentDedDgrRessya->getSihatsuEki() < iEkiOrder &&
		iEkiOrder < pCentDedDgrRessya->getSyuuchakuEki() && 
		eStopMarkDrawType == 
			CentDedRessyasyubetsu::EStopMarkDrawType_DrawOnStop && 
		pCentDedDgrEkiJikoku->getEkiatsukai() == 
			CentDedEkiJikoku::Ekiatsukai_Teisya && 
		iStopSeconds < 60 )
	{
		//// --------------------------------
		////	停車マークの描画(△)
		//// --------------------------------
		//{
		//	// --------------------------------
		//	//	三角形の３辺を算出
		//	// --------------------------------
		//	CdDcdPosXy	posRessyasen_Pos1_Dcd ;
		//	CdDcdPosXy	posRessyasen_Pos2_Dcd ;
		//	{
		//		CdDcdPosXy	posRessyasen_Pos1_Dgr( 
		//		pCentDedDgrRessyasen->getRessyasenKitenJikoku() ,
		//		getCentDedDgrDia()->getYZahyouOfEki( 
		//		pCentDedDgrRessya->getRessyahoukou() , 
		//		pCentDedDgrRessyasen->getRessyasenKitenEkiOrder() ) 
		//		) ;
		//		CdDcdPosXy	posRessyasen_Pos2_Dgr( 
		//		pCentDedDgrRessyasen->getRessyasenSyuutenJikoku() ,
		//		getCentDedDgrDia()->getYZahyouOfEki( 
		//		pCentDedDgrRessya->getRessyahoukou() , 
		//		pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() ) 
		//		) ;
		//		//posRessyasen_Pos1_Dgr,posRessyasen_Pos2_Dgr = 
		//		//	『ダイヤグラムエンティティ列車線』の起点と終点の座標
		//		//	単位は、『ダイヤグラムエンティティ座標系』

		//		posRessyasen_Pos1_Dcd = m_pCDcdDiagram->DgrToDcd( m_pIfDcdTarget , 
		//		posRessyasen_Pos1_Dgr ) ;
		//		posRessyasen_Pos2_Dcd = m_pCDcdDiagram->DgrToDcd( m_pIfDcdTarget , 
		//		posRessyasen_Pos2_Dgr ) ;
		//	}
		//	//posRessyasen_Pos1_Dgr,posRessyasen_Pos2_Dgr = 
		//	//	『ダイヤグラムエンティティ列車線』の起点と終点の座標
		//	//	単位は、 IfDcdTarget の座標


		//	CdDcdPosXy	posTriangle_Dcd[3] ;
		//	{
		//		//	三角形の大きさ。
		//		//	単位は、DCの論理座標。
		//		//	この値は、
		//		//		発時刻から二等辺三角形の頂点までの長さ。
		//		//		二等辺三角形の底辺
		//		//	に、適用されます。
		//		//	発時刻から二等辺三角形の底辺までの長さは、 
		//		//	dTriangleSize / 2 とします。
		//		const double dTriangleSize = 6 ;

		//		if ( pCentDedDgrRessya->getRessyahoukou() == 
		//			Ressyahoukou_Kudari )
		//		{
		//			double dRessyasen_x_len = posRessyasen_Pos2_Dcd.getX() - 
		//			posRessyasen_Pos1_Dcd.getX() ;
		//			double dRessyasen_y_len =  posRessyasen_Pos2_Dcd.getY() - 
		//			posRessyasen_Pos1_Dcd.getY() ;
		//			double dRessyasen =  dRessyasen_x_len / dRessyasen_y_len ;

		//			//int iRessyasen_deg = (int)( RadToDeg( atan( dRessyasen ) ) ) ;
		//			//double e_x_len = ( dTriangleSize * sin( DegToRad( iRessyasen_deg ) ) ) ;
		//			//double e_y_len = ( dTriangleSize * cos( DegToRad( iRessyasen_deg ) ) ) ;

		//			double dRessyasen_rad = atan( dRessyasen ) ;
		//			double e_x_len = ( dTriangleSize * sin( dRessyasen_rad ) ) ;
		//			double e_y_len = ( dTriangleSize * cos( dRessyasen_rad ) ) ;


		//			//	三角形の頂点を求めます。
		//			//	最後の +0.5 は、小数点以下の端数を四捨五入するためのものです。
		//			posTriangle_Dcd[0].setX( (DcdPos)( iX_Dcd + e_x_len                       + 0.5 ) ) ;
		//			posTriangle_Dcd[0].setY( (DcdPos)( iY_Dcd + e_y_len                       + 0.5 ) ) ;
		//			posTriangle_Dcd[1].setX( (DcdPos)( iX_Dcd - e_x_len * 0.5 + e_y_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[1].setY( (DcdPos)( iY_Dcd - e_y_len * 0.5 - e_x_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[2].setX( (DcdPos)( iX_Dcd - e_x_len * 0.5 - e_y_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[2].setY( (DcdPos)( iY_Dcd - e_y_len * 0.5 + e_x_len * 0.5 + 0.5 ) ) ;

		//		}
		//		else
		//		{
		//			double dRessyasen_x_len = posRessyasen_Pos2_Dcd.getX() - 
		//			posRessyasen_Pos1_Dcd.getX() ;
		//			double dRessyasen_y_len =  posRessyasen_Pos1_Dcd.getY() - 
		//			posRessyasen_Pos2_Dcd.getY() ;
		//			double dRessyasen =  dRessyasen_x_len / dRessyasen_y_len ;

		//			//int iRessyasen_deg = (int)( RadToDeg( atan( dRessyasen ) ) ) ;
		//			//double e_x_len = ( dTriangleSize * sin( DegToRad( iRessyasen_deg ) ) ) ;
		//			//double e_y_len = ( dTriangleSize * cos( DegToRad( iRessyasen_deg ) ) ) ;
		//			double dRessyasen_rad = atan( dRessyasen ) ;
		//			double e_x_len = ( dTriangleSize * sin( dRessyasen_rad ) ) ;
		//			double e_y_len = ( dTriangleSize * cos( dRessyasen_rad ) ) ;

		//			//	三角形の頂点を求めます。
		//			//	最後の +0.5 は、小数点以下の端数を四捨五入するためのものです。
		//			posTriangle_Dcd[0].setX( (DcdPos)( iX_Dcd + e_x_len                       + 0.5 ) ) ;
		//			posTriangle_Dcd[0].setY( (DcdPos)( iY_Dcd - e_y_len                       + 0.5 ) ) ;
		//			posTriangle_Dcd[1].setX( (DcdPos)( iX_Dcd - e_x_len * 0.5 + e_y_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[1].setY( (DcdPos)( iY_Dcd + e_y_len * 0.5 + e_x_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[2].setX( (DcdPos)( iX_Dcd - e_x_len * 0.5 - e_y_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[2].setY( (DcdPos)( iY_Dcd + e_y_len * 0.5 - e_x_len * 0.5 + 0.5 ) ) ;
		//		}
		//	}
		//	//posTriangle = ３角形の３点
		//	// --------------------------------
		//	CdPenProp	aCdPenProp( 1 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::SOLID ) ;
		//	HPEN hPen = m_pIfDcdTarget->CreatePen( aCdPenProp ) ;
		//	HPEN hPenPrev = (HPEN)SelectObject( m_pIfDcdTarget->getHdc() , hPen ) ;

		//	CdBrushProp	aCdBrushProp( CdColorProp( 0 , 0 , 0 ) , CdBrushProp::NULLBRUSH ) ;
		//	HBRUSH hBrush = m_pIfDcdTarget->CreateBrush( aCdBrushProp ) ;
		//	HBRUSH hBrushPrev = (HBRUSH)SelectObject( m_pIfDcdTarget->getHdc() , hBrush ) ;


		//	POINT pointTriangle[3] ;
		//	CConverter_WinGdi aConv ;
		//	pointTriangle[0] = aConv.POINTOf( posTriangle_Dcd[0] ) ;
		//	pointTriangle[1] = aConv.POINTOf( posTriangle_Dcd[1] ) ;
		//	pointTriangle[2] = aConv.POINTOf( posTriangle_Dcd[2] ) ;

		//	Polygon( 
		//		m_pIfDcdTarget->getHdc() , 
		//		pointTriangle , 
		//		3 //	３角形
		//		) ;
		//	// --------------------------------
		//	//	GDIオブジェクトの選択を解除
		//	if ( hPenPrev != NULL )
		//	{
		//		SelectObject( m_pIfDcdTarget->getHdc() , hPenPrev ) ;
		//		hPenPrev = NULL ;
		//	}
		//	if ( hBrushPrev != NULL )
		//	{
		//		SelectObject( m_pIfDcdTarget->getHdc() , hBrushPrev ) ;
		//		hBrushPrev = NULL ;
		//	}
		//}

		// --------------------------------
		//	停車マークの描画(○)
		// --------------------------------
		{
			CdPenProp	aCdPenProp( 1 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::SOLID ) ;
			Ou<CGdiHPenHolder>	pHPenHolder = m_pIfDcdTarget->createGdiHPenHolder( aCdPenProp ) ;
			HPEN hPenPrev = (HPEN)SelectObject( m_pIfDcdTarget->getHdc() , pHPenHolder->getHPen() ) ;

			CdBrushProp	aCdBrushProp( CdColorProp( 0 , 0 , 0 ) , CdBrushProp::NULLBRUSH ) ;
			Ou<CGdiHBrushHolder> pHBrushHolder = m_pIfDcdTarget->createGdiHBrushHolder( aCdBrushProp ) ;
			HBRUSH hBrushPrev = (HBRUSH)SelectObject( m_pIfDcdTarget->getHdc() , pHBrushHolder->getHBrush() ) ;

			Ellipse( 
				m_pIfDcdTarget->getHdc() , 
				iX_Dcd - 2 , 
				iY_Dcd - 2 , 
				iX_Dcd + 3 , 
				iY_Dcd + 3 ) ;
			// --------------------------------
			//	GDIオブジェクトの選択を解除
			if ( hPenPrev != NULL )
			{
				SelectObject( m_pIfDcdTarget->getHdc() , hPenPrev ) ;
				hPenPrev = NULL ;
			}
			if ( hBrushPrev != NULL )
			{
				SelectObject( m_pIfDcdTarget->getHdc() , hBrushPrev ) ;
				hBrushPrev = NULL ;
			}
		}

	}
}
} //namespace ViewDiagram
