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
//	CaDcdDiagram_PageSelector.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CaDcdDiagram_PageSelector.h"

namespace ViewDiagram{

/**
  整数(補正対象値)が、増減単位の倍数±α(誤差許容値) なら、
  最寄の増減単位の倍数丁度の値に補正します。

(例)iUnit=5,iAllowedDifference=1 の場合、valueに対する結果は以下のとおりです。

　- value=3 なら return=3
　- value=4 なら return=5
　- value=5 なら return=5
　- value=6 なら return=5
　- value=7 なら return=7


@param value [in]
	補正対象値を指定してください。範囲は0以上です。
@param iUnit [in]
	増減単位を指定してください。範囲は1以上です。
@param iAllowedDifference [in]
	誤差許容値
@return
	補正された値を返します。
*/
static int adjustForNearestUnit( int value , int iUnit , int iAllowedDifference ) 
{
	int iMod = value % iUnit ;

	if ( iMod == 0 )
	{
	}
	//補正１：(現在値%増減単位)≦(誤差許容値) なら、
	//　現在値=現在値-(現在値%増減単位)
	//
	//(例)
	//　増減単位=1800
	//　現在値=1801
	//　(誤差許容値)=1
	//の場合
	//　(1801%1800)=1 (現在値%増減単位)
	//　1801-(1801%1800)=1800
	//
	else if ( iMod <= iAllowedDifference )
	{
		value = value - iMod ; 
	}

	//補正２：(現在値%増減単位)≧(増減単位-誤差許容値) なら、
	//　現在値=現在値+(増減単位-(現在値%増減単位))
	//
	//(例)
	//　増減単位=1800
	//　現在値=3599
	//　(誤差許容値)=1
	//の場合
	//　(3599%1800)=1799 (現在値%増減単位)
	//　3599+(1800-(3599%1800))=3600
	else if ( iMod >= ( iUnit - iAllowedDifference ) )
	{
		value = value + ( iUnit - iMod ) ; 
	}
	return value ;
}

// ****************************************************************
//	CaDcdDiagram_PageSelector
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CaDcdDiagram_PageSelector::CaDcdDiagram_PageSelector( 
		CDcdDiagram2*	pCDcdDiagram2 ,
		const CdDcdSizeXy&	sizePage_Dgr ) 
{
	m_pCDcdDiagram2 = pCDcdDiagram2 ;
	m_sizePage_Dgr = sizePage_Dgr ;
	m_iXPage = 0 ;
	m_iYPage = 0 ;

	m_CconvContentPosToDcdTargetPrev = 
		*m_pCDcdDiagram2->getCconvContentPosToDcdTarget() ;
}


	
CaDcdDiagram_PageSelector::~CaDcdDiagram_PageSelector() 
{
	*m_pCDcdDiagram2->getCconvContentPosToDcdTarget() =
		m_CconvContentPosToDcdTargetPrev ;
}

// ********************************
//@name 	IfDcDraw
// ********************************
bool CaDcdDiagram_PageSelector::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	zonexyZone_Dgr = m_pCDcdDiagram2->getZone_Dgr( pIfDcdTarget ) ;
	//zonexyZone_Dgr=描画を行う ダイヤグラム座標の範囲
	
	// --------------------------------
	//	ダイヤグラム全体の領域(ダイヤグラム座標)を取得
	// --------------------------------
	CdDcdZoneXy	zonexyCentDcdDgrDia = 
		m_pCDcdDiagram2->getCentDedDgrDia()->getZone() ;
	if ( m_sizePage_Dgr.getX() > 0 )
	{
		zonexyCentDcdDgrDia.setX( 
			CdDcdZone( zonexyCentDcdDgrDia.getX().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getX().getSize() , m_sizePage_Dgr.getX() , 1 ) ) ) ;
	}
	if ( m_sizePage_Dgr.getY() > 0 )
	{
		zonexyCentDcdDgrDia.setY( 
			CdDcdZone( zonexyCentDcdDgrDia.getY().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getY().getSize() , m_sizePage_Dgr.getY() , 1 ) ) ) ;
	}
	//zonexyCentDcdDgrDia = ダイヤグラム全体の領域(ダイヤグラム座標)
	//	ただし、幅が１ページのサイズ(ダイヤグラム座標)に近い場合は、
	//	1ページのサイズと同じにします。
	//	現在では、意味がなくなっているようです。

	// --------------------------------


	zonexyZone_Dgr.setX( CdDcdZone( 
		zonexyCentDcdDgrDia.getX().getPos() + m_sizePage_Dgr.getX() * m_iXPage , 
		m_sizePage_Dgr.getX() ) )  ;
	zonexyZone_Dgr.setY( CdDcdZone( 
		zonexyCentDcdDgrDia.getY().getPos() + m_sizePage_Dgr.getY() * m_iYPage , 
		m_sizePage_Dgr.getY() ) )  ;
	m_pCDcdDiagram2->setZone_Dgr( pIfDcdTarget , zonexyZone_Dgr ) ;

	return m_pCDcdDiagram2->DcDraw( pIfDcdTarget ) ;
}
bool CaDcdDiagram_PageSelector::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	CdDcdZoneXy	zonexyZone_Dgr = m_pCDcdDiagram2->getZone_Dgr( pIfDcdTarget ) ;
	//zonexyZone_Dgr=描画を行う ダイヤグラム座標の範囲
	//	(1ページに描画するダイヤグラムの範囲)

	// --------------------------------
	//	ダイヤグラム全体の領域(ダイヤグラム座標)を取得
	// --------------------------------
	CdDcdZoneXy	zonexyCentDcdDgrDia = 
		m_pCDcdDiagram2->getCentDedDgrDia()->getZone() ;
	if ( m_sizePage_Dgr.getX() > 0 )
	{
		zonexyCentDcdDgrDia.setX( 
			CdDcdZone( zonexyCentDcdDgrDia.getX().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getX().getSize() , m_sizePage_Dgr.getX() , 1 ) ) ) ;
	}
	if ( m_sizePage_Dgr.getY() > 0 )
	{
		zonexyCentDcdDgrDia.setY( 
			CdDcdZone( zonexyCentDcdDgrDia.getY().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getY().getSize() , m_sizePage_Dgr.getY() , 1 ) ) ) ;
	}
	//zonexyCentDcdDgrDia = ダイヤグラム全体の領域(ダイヤグラム座標)
	//	ただし、幅が１ページのサイズ(ダイヤグラム座標)に近い場合は、
	//	1ページのサイズと同じにします。
	//	現在では、意味がなくなっているようです。

	
	// --------------------------------

	zonexyZone_Dgr.setX( CdDcdZone( 
		zonexyCentDcdDgrDia.getX().getPos() + m_sizePage_Dgr.getX() * m_iXPage , 
		m_sizePage_Dgr.getX() ) )  ;
	zonexyZone_Dgr.setY( CdDcdZone( 
		zonexyCentDcdDgrDia.getY().getPos() + m_sizePage_Dgr.getY() * m_iYPage , 
		m_sizePage_Dgr.getY() ) )  ;

	m_pCDcdDiagram2->setZone_Dgr( pIfDcdTarget , zonexyZone_Dgr ) ;

	return m_pCDcdDiagram2->getItemSize( pIfDcdTarget , pCdDcdSizeXy ) ;
}

// ********************************
//	CaDcdDiagram_PageSelector
// ********************************


int CaDcdDiagram_PageSelector::getXPageCount() 
{
	int iRv = 0 ;

	// --------------------------------
	//	ダイヤグラム全体の領域(ダイヤグラム座標)を取得
	// --------------------------------
	CdDcdZoneXy	zonexyCentDcdDgrDia = 
		m_pCDcdDiagram2->getCentDedDgrDia()->getZone() ;
	if ( m_sizePage_Dgr.getX() > 0 )
	{
		zonexyCentDcdDgrDia.setX( 
			CdDcdZone( zonexyCentDcdDgrDia.getX().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getX().getSize() , m_sizePage_Dgr.getX() , 1 ) ) ) ;
	}
	if ( m_sizePage_Dgr.getY() > 0 )
	{
		zonexyCentDcdDgrDia.setY( 
			CdDcdZone( zonexyCentDcdDgrDia.getY().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getY().getSize() , m_sizePage_Dgr.getY() , 1 ) ) ) ;
	}
	//zonexyCentDcdDgrDia = ダイヤグラム全体の領域(ダイヤグラム座標)
	//	ただし、幅が１ページのサイズ(ダイヤグラム座標)に近い場合は、
	//	1ページのサイズと同じにします。
	//
	//【理由】何も表示されないページが発生しないようにするためです。
	//
	//【例】
	//　ウインドウサイズがダイヤグラム全体のサイズに
	//	わずかに(１ピクセル)足りない場合。
	//		zonexyCentDcdDgrDia.m_Y.m_Size =10800
	//		m_sizePage_Dgr.m_Y.m_Size      =10799
	//	Y方向に必要なページが２と計算されてしまい、
	//	2ページ目は見た目上空白になってしまいます。
	//
	//	ここでは、
	//		zonexyCentDcdDgrDia.m_Y.m_Size を 10799 
	//	に補正することにより、Y方向に必要なページを
	//	１と計算させることができます。
	
	// --------------------------------

	if ( m_sizePage_Dgr.getX() > 0 )
	{
		iRv = zonexyCentDcdDgrDia.getX().getSize() ;

		iRv += ( m_sizePage_Dgr.getX() - 1 ) ;
		iRv /= m_sizePage_Dgr.getX() ;
	}

	return ( iRv ) ;
	
}

int CaDcdDiagram_PageSelector::getYPageCount() 
{
	int iRv = 0 ;

	// --------------------------------
	//	ダイヤグラム全体の領域(ダイヤグラム座標)を取得
	// --------------------------------
	CdDcdZoneXy	zonexyCentDcdDgrDia = 
		m_pCDcdDiagram2->getCentDedDgrDia()->getZone() ;
	if ( m_sizePage_Dgr.getX() > 0 )
	{
		zonexyCentDcdDgrDia.setX( 
			CdDcdZone( zonexyCentDcdDgrDia.getX().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getX().getSize() , m_sizePage_Dgr.getX() , 1 ) ) ) ;
	}
	if ( m_sizePage_Dgr.getY() > 0 )
	{
		zonexyCentDcdDgrDia.setY( 
			CdDcdZone( zonexyCentDcdDgrDia.getY().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getY().getSize() , m_sizePage_Dgr.getY() , 1 ) ) ) ;
	}
	//zonexyCentDcdDgrDia = ダイヤグラム全体の領域(ダイヤグラム座標)
	//	ただし、幅が１ページのサイズ(ダイヤグラム座標)に近い場合は、
	//	1ページのサイズと同じにします。
	//【理由】何も表示されないページが発生しないようにするためです。
	//	getXPageCount()を参照してください。

	// --------------------------------


	if ( m_sizePage_Dgr.getY() > 0 )
	{
		iRv = zonexyCentDcdDgrDia.getY().getSize() ;

		iRv += ( m_sizePage_Dgr.getY() - 1 ) ;
		iRv /= m_sizePage_Dgr.getY() ;
	}
	return ( iRv ) ;
}

int CaDcdDiagram_PageSelector::getPageCount() 
{
	return getXPageCount() * getYPageCount() ;
}
	
	
int CaDcdDiagram_PageSelector::getXPage() 
{
	return m_iXPage ;
}

CaDcdDiagram_PageSelector& 
	CaDcdDiagram_PageSelector::setXPage( int value ) 
{
	if ( value == INT_MAX ){
		value = getXPageCount() - 1 ;
	}
	if ( value >= getXPageCount() - 1 ){
		value = getXPageCount() - 1 ;
	}
	if ( value < 0 ){
		value = 0 ;
	}
	m_iXPage = value ;
	return *this ;
}

int CaDcdDiagram_PageSelector::getYPage() 
{
	return m_iYPage ;
}

CaDcdDiagram_PageSelector& 
	CaDcdDiagram_PageSelector::setYPage( int value ) 
{
	if ( value == INT_MAX ){
		value = getYPageCount() - 1 ;
	}
	if ( value >= getYPageCount() - 1 ){
		value = getYPageCount() - 1 ;
	}
	if ( value < 0 ){
		value = 0 ;
	}
	m_iYPage = value ;
	return *this ;

}
int CaDcdDiagram_PageSelector::getPage() 
{
	return m_iXPage + m_iYPage * getXPageCount() ;
}


CaDcdDiagram_PageSelector& 
	CaDcdDiagram_PageSelector::setPage( int value ) 
{
	if ( value == INT_MAX ){
		value = getPageCount() - 1 ;
	}
	if ( value >= getPageCount() - 1 ){
		value = getPageCount() - 1 ;
	}
	if ( value < 0 ){
		value = 0 ;
	}
	int iXPage = value % getXPageCount() ;
	int iYPage = value / getXPageCount() ;
	setXPage( iXPage );
	setYPage( iYPage ) ;
	return *this ;
}
} //namespace ViewDiagram
