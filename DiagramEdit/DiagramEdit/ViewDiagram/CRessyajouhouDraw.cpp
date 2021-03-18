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
//	CRessyajouhouDraw.cpp
//	$Id: CRessyajouhouDraw.cpp 367 2016-08-19 10:14:24Z okm $
// ****************************************************************
/** @file */
#include "stdafx.h"
#include <math.h>

#include "DcDraw\CDcdText.h"
#include "DcDraw\CConverter_Wingdi.h"

#include "CRessyajouhouDraw.h"

namespace ViewDiagram{

using namespace std ;

// ****************************************************************
///	円周率
const double Pi = 3.14159265 ;

/**
 	角度の単位を、度からラジアンへ変換します。
 
 	180 度 = 1π ラジアン
  @param value [in]
 	変換対象の値。
  @return
 	変換後の値。
*/
static double DegToRad( double value )
{
	return value * Pi / 180 ;
}

/**
 	角度の単位を、ラジアンから度へ変換します。
 
 	180 度 = 1π ラジアン
  @param value [in]
 	変換対象の値。
  @return
 	変換後の値。
*/
static double RadToDeg( double value )
{
	return value * 180 / Pi ;
}
	// ********************************
	//	コンストラクタ
	// ********************************
CRessyajouhouDraw::CRessyajouhouDraw( CDcdDiagram* pCDcdDiagram , 
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

void CRessyajouhouDraw::onCentDedDgrEkiJikoku( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ,
		int iEkiOrder , 
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku ) 
{
	if ( iEkiOrder == pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() )
	{
		//	列車線終点には、テキストの描画を行いません
		return ;
	}
	if ( !pCentDedDgrEkiJikoku->getShouldRessyajouhouDraw() )
	{
		//	この駅時刻の位置には、テキストの描画を行いません。
		return ;
	}
	// --------------------------------
	//	テキストの色を選択
	// --------------------------------
	CdColorProp	colorText ;
	{
		int idxRessyasyubetsu = pCentDedDgrRessya->getRessyasyubetsuIndex() ;
		if ( 0 <= idxRessyasyubetsu && 
			idxRessyasyubetsu < getCentDedDgrDia()->getMuCentDedDgrRessyasyubetsu()->size() )
		{
			const CentDedDgrRessyasyubetsu* pCentDedDgrRessyasyubetsu = 
				getCentDedDgrDia()->getMuCentDedDgrRessyasyubetsu()->get( idxRessyasyubetsu ) ;
			colorText = pCentDedDgrRessyasyubetsu->getJikokuhyouMojiColor() ;
		}
	}
	//colorText = テキストの色

	// --------------------------------
	//	列車情報テキストの内容を作成し
	//	大きさを計測
	// --------------------------------
	string	strRessyajouhou ;
	if ( m_pCDcdDiagram->getDisplayRessyabangou() )
	{
		if ( !pCentDedDgrRessya->getRessyabangou().empty() )
		{
			if ( !strRessyajouhou.empty() )
			{
				strRessyajouhou += ' ' ;
			}
			strRessyajouhou += pCentDedDgrRessya->getRessyabangou() ;
		}
	}
	if (  m_pCDcdDiagram->getDisplayRessyamei() )
	{
		if ( !pCentDedDgrRessya->getRessyamei().empty() )
		{
			if ( !strRessyajouhou.empty() )
			{
				strRessyajouhou += ' ' ;
			}
			strRessyajouhou += pCentDedDgrRessya->getRessyamei() ;
		}
		if ( !pCentDedDgrRessya->getGousuu().empty() )
		{
			if ( !strRessyajouhou.empty() )
			{
				strRessyajouhou += ' ' ;
			}
			strRessyajouhou += pCentDedDgrRessya->getGousuu() ;
			CString	aStr ;
			aStr.LoadString( IDS_WORD_GOUSUU2 ) ;
			strRessyajouhou += (LPCTSTR)aStr ;
		}
	}
	if ( strRessyajouhou.empty() )
	{
		return ;
	}
	//strRessyajouhou = 表示する列車情報の文字列
	CdDcdSizeXy	sizexyText_Dcd ;
	{
		CDcdText	dcdText( strRessyajouhou , 
			m_pCDcdDiagram->getDiaRessyaFont() ) ;
		dcdText.getItemSize( m_pIfDcdTarget , &sizexyText_Dcd ) ;
	}
	//sizexyText_Dcd = 列車情報テキストの幅と高さ
	//	（水平に描画した場合の寸法です）

	// --------------------------------
	//	列車情報の描画される直線を算出
	// --------------------------------
	CdDcdPosXy	posRessyasen_Pos1_Dcd ;
	CdDcdPosXy	posRessyasen_Pos2_Dcd ;
	{
		CdDcdPosXy	posDgrPosRessyasenKiten = 
			getCentDedDgrDia()->calcDgrPosRessyasenKiten( 
				pCentDedDgrRessya , 
				pCentDedDgrRessyasen ) ;
		CdDcdPosXy	posDgrPosRessyasenSyuuten = 
			getCentDedDgrDia()->calcDgrPosRessyasenSyuuten( 
				pCentDedDgrRessya , 
				pCentDedDgrRessyasen ) ;
		//posDgrPosRessyasenKiten,posDgrPosRessyasenSyuuten = 
		//	『ダイヤグラムエンティティ列車線』の起点と終点の座標
		//	単位は、『ダイヤグラムエンティティ座標系』

		posRessyasen_Pos1_Dcd = m_pCDcdDiagram->DgrToDcd( 
			m_pIfDcdTarget , 
			posDgrPosRessyasenKiten ) ;
		posRessyasen_Pos2_Dcd = m_pCDcdDiagram->DgrToDcd( 
			m_pIfDcdTarget , 
			posDgrPosRessyasenSyuuten ) ;
	}
	//posRessyasen_Pos1_Dcd,posRessyasen_Pos2_Dcd = 
	//	『ダイヤグラムエンティティ列車線』の起点と終点の座標
	//	単位は、 IfDcdTarget の座標

	// --------------------------------
	//	列車情報の描画される駅の列車線上での位置を算出
	// --------------------------------
	int iX_Dcd = 0 ;
	int iY_Dcd = 0 ;
	{
		int iY_Dgr = 0 ;
		int iX_Dgr = 0 ;
		iY_Dgr = getCentDedDgrDia()->getDgrYPosOfEki( 
			pCentDedDgrRessya->getRessyahoukou() , iEkiOrder ) ;
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
	//	テキストの位置と角度を計算
	// --------------------------------
	CdDcdPosXy	posText_Dcd ;
	int iDeg = 0 ;
	{
		double d = sizexyText_Dcd.getY() + 2 ;
		if ( pCentDedDgrRessya->getRessyahoukou() == 
			Ressyahoukou_Kudari )
		{
			double a = posRessyasen_Pos2_Dcd.getX() - 
				posRessyasen_Pos1_Dcd.getX() ;
			double b =  posRessyasen_Pos2_Dcd.getY() - 
				posRessyasen_Pos1_Dcd.getY() ;
			double a_b =  a / b ;
			int c = (int)( RadToDeg( atan( a_b ) ) ) ;
			int e = (int)( d / cos( DegToRad( c ) ) ) ;
			posText_Dcd = CdDcdPosXy( iX_Dcd + e , iY_Dcd ) ;
			iDeg = 270 + c ;
		}
		else
		{
			double a = posRessyasen_Pos2_Dcd.getX() - 
				posRessyasen_Pos1_Dcd.getX() ;
			double b =  posRessyasen_Pos1_Dcd.getY() - 
				posRessyasen_Pos2_Dcd.getY() ;
			double a_b =  a / b ;
			int c = (int)( RadToDeg( atan( a_b ) ) ) ;
			int e = (int)( d * cos( DegToRad( c ) ) ) ;
			int f = (int)( d * sin( DegToRad( c ) ) ) ;
			posText_Dcd = CdDcdPosXy( iX_Dcd - e , iY_Dcd - f ) ;
			iDeg = 90 -c ;
		}
	}
	//posText_Dcd = テキストの左上座標
	//iDeg = テキストの角度（単位は度）

	// --------------------------------
	//	テキストの描画
	// --------------------------------
	{
		//	フォントの属性
		//	角度指定を追加します。
		CdFontProp	aCdFontProp = m_pCDcdDiagram->getDiaRessyaFont() ;
		aCdFontProp.setEscapement( iDeg * 10 ) ;

		//	フォントの生成
		Ou<CGdiHFontHolder>	pHFontHolder = m_pIfDcdTarget->createGdiHFontHolder(
			aCdFontProp ) ;
		
		// --------------------------------
		//	フォント・色・背景モードの選択
		HFONT	hFontPrev = NULL ;
		hFontPrev = (HFONT)SelectObject( m_pIfDcdTarget->getHdc() , 
			pHFontHolder->getHFont() ) ;

		CConverter_WinGdi	aCConverter_WinGdi ;
		COLORREF	colorTextPrev = SetTextColor( 
			m_pIfDcdTarget->getHdc() , 
			aCConverter_WinGdi.COLORREFOf( colorText ) ) ;
		int iBkModePrev = SetBkMode( m_pIfDcdTarget->getHdc() , 
			TRANSPARENT ) ;
		// --------------------------------
		TextOut( m_pIfDcdTarget->getHdc() , 
			posText_Dcd.getX() , posText_Dcd.getY() ,
			strRessyajouhou.c_str() , strRessyajouhou.size() ) ;

		// --------------------------------
		//	フォント・色・背景モードの選択を解除
		{
			SetBkMode( m_pIfDcdTarget->getHdc() , iBkModePrev ) ;
			SetTextColor( m_pIfDcdTarget->getHdc() , colorTextPrev ) ;
		}
		if ( hFontPrev != NULL ){
			SelectObject( m_pIfDcdTarget->getHdc() , hFontPrev ) ;
			hFontPrev = NULL ;
		}
		// --------------------------------
		//	フォントを破棄
		if ( pHFontHolder != NULL )
		{
			pHFontHolder = Ou<CGdiHFontHolder>() ;
		}
	}
}

} //namespace ViewDiagram
