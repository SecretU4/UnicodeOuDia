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
//	CDcdFreeLine.cpp
// ****************************************************************
*/
#include "CDcdFreeLine.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CDcDeviceUnitSizeX.h"
#include "DcdCd\Pos\CLineFunc.h"

namespace DcDrawLib{
namespace DcDraw{

using namespace std ;

// ****************************************************************
//	CDcdFreeLine
// ****************************************************************
/**
 *	整数の符号を求めます。
 * @param i [in]
 *	もとになる整数を指定してください。
 * @return
 *	-	i>0 なら +1 ;	
 *	-	i==0 なら 0 ;	
 *	-	i<0 なら -1 ;	
 */
inline int sign( int i )
{
	if ( i > 0 ){	return +1 ; } ;
	if ( i < 0 ){	return -1 ; } ;
	return 0 ;
}



// ********************************
///@name	IfDcDraw
// ********************************
bool CDcdFreeLine::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool	bRv = 0 ;
	CConverter_WinGdi	aConverter ;

	// --------------------------------
	//	m_iLogicalunitWidth が
	//	0 なら、何も描画しません。
	// --------------------------------
	if ( m_CdLineProp.getLogicalunitWidth() <= 0 ){
		return ( false ) ;
	}


	
	// --------------------------------
	//	描画のための論理ペンを生成
	//	(サイズは、物理座標とします)
	// --------------------------------
	Ou<CGdiHPenHolder>	pHPenHolder ;
	int iDeviceunitPenWidth = 
			CDcDeviceUnitSizeX( pIfDcdTarget->getHdc() ).
			setLogicalUnitSize( m_CdLineProp.getLogicalunitWidth() ).
			getDeviceUnitSize() ;
	if ( iDeviceunitPenWidth <= 0 ){
		iDeviceunitPenWidth = 1 ;
	}
	{
		CdPenProp	aCdPenProp ;
		aCdPenProp.setLogicalunitWidth( iDeviceunitPenWidth ) ;
			
		aCdPenProp.setColor( m_CdLineProp.getColor() ) ;
		aCdPenProp.setStyle( CdPenProp::SOLID ) ;
		pHPenHolder = pIfDcdTarget->createGdiHPenHolder( aCdPenProp ) ;
	}
	//iDeviceunitPenWidth  = デバイス座標系での
	//	ペンの太さ


	// --------------------------------
	CdDcdPosXy	posOrg = m_posOrg ;
	CdDcdPosXy	posDst = m_posDst ;
	//posOrg,posDst = 起点と終点の座標（論理座標）

	// --------------------------------
	//	DcdTargetの範囲に、起点と終点を補正
	// --------------------------------
	if ( m_bAdjustForDcdTarget ){
		//X方向をDcdTargetの範囲に収める
		{
			CdDcdZone	zoneX( posOrg.getX() , posDst.getX() - posOrg.getX() );
			CdDcdZone	zoneXTarget = pIfDcdTarget->getZone().getX() ;
			CdDcdZone	zoneXCrossed = zoneX.CrossZone( zoneXTarget ) ;
			//X座標を、デバイス領域内に正規化しました。
			if ( zoneXCrossed.getSize() != 0 ){
				CLineFunc	aCLineFunc( m_posOrg , m_posDst ) ;
				
				//	zoneXCrossed が描画領域にあり、
				//	しかも斜線である場合は、
				//	起点・終点それぞれにおいて、
				//	デバイス領域内に正規化した
				//	X座標からY座標を求めます。
				//
				//	(zoneXCrossed.Sizeが0の場合（垂線の場合）は、
				//	対応する特定のY座標を求めることができませんので、
				//	calcLineYofX() を呼び出してはいけません)
				if ( zoneX.getPos() != zoneXCrossed.getPos() ){
					posOrg.setX( zoneXCrossed.getPos() ) ;
					posOrg.setY( aCLineFunc.calcYofX( 
						zoneXCrossed.getPos() ) );
				}
				if ( zoneX.getEndPos() != zoneXCrossed.getEndPos() ){
					posDst.setX( zoneXCrossed.getEndPos() ) ;
					posDst.setY( aCLineFunc.calcYofX( 
						zoneXCrossed.getEndPos() ) ) ;
				}
			}
			if ( zoneXCrossed.getSize() == 0 && 
					!zoneXTarget.IsInner( zoneXCrossed.getPos() ) ){
				//	zoneXCrossed が描画領域外である場合は、
				//	直線の描画はできませんので、偽でリターンします。
				return ( false ) ;
			}
	
		}
		//Y方向をDcdTargetの範囲に収める
		{
			CdDcdZone	zoneY( posOrg.getY() , posDst.getY() - posOrg.getY() );
			CdDcdZone	zoneYTarget = pIfDcdTarget->getZone().getY() ;
			CdDcdZone	zoneYCrossed = zoneY.CrossZone( zoneYTarget ) ;
			//Y座標を、デバイス領域内に正規化しました。
			if ( zoneYCrossed.getSize() != 0 ){
				CLineFunc	aCLineFunc( m_posOrg , m_posDst ) ;

				//	zoneYCrossed が描画領域にあり、
				//	しかも斜線である場合は、
				//	起点・終点それぞれにおいて、
				//	デバイス領域内に正規化した
				//	Y座標からX座標を求めます。
				//
				//	(zoneYCrossed.Sizeが0の場合（水平線の場合）は、
				//	対応する特定のX座標を求めることができませんので、
				//	calcLineXofY() を呼び出してはいけません)
				if ( zoneY.getPos() != zoneYCrossed.getPos() ){
					posOrg.setX( aCLineFunc.calcXofY(
						zoneYCrossed.getPos() ) ) ;
					posOrg.setY( zoneYCrossed.getPos() ) ;
				}
				if ( zoneY.getEndPos() != zoneYCrossed.getEndPos() ){
					posDst.setX( aCLineFunc.calcXofY( 
						zoneYCrossed.getEndPos() ) ) ;
					posDst.setY( zoneYCrossed.getEndPos() ) ;
				}
			}
			if ( zoneYCrossed.getSize() == 0 && 
					!zoneYTarget.IsInner( zoneYCrossed.getPos() ) ){
				//	zoneYCrossed が描画領域外である場合は、
				//	直線の描画はできませんので、偽でリターンします。
				return ( false ) ;
			}
		}
		//posOrg,posDst = 
		//	DcdTargetの範囲に、起点と終点を補正しました。
	}

	// --------------------------------
	//	デバイス座標系での
	//	線の座標を求める
	// --------------------------------
	{
		POINT	aPoint = aConverter.POINTOf( posOrg ) ;
		::LPtoDP( pIfDcdTarget->getHdc() , &aPoint , 1 ) ;
		posOrg = aConverter.CdDcdPosXyOf( aPoint ) ;
	}
	{
		POINT	aPoint = aConverter.POINTOf( posDst ) ;
		::LPtoDP( pIfDcdTarget->getHdc() , &aPoint ,1 ) ;
		posDst = aConverter.CdDcdPosXyOf( aPoint ) ;
	}
	//posOrg,posDst = デバイス座標に変換しました。
	
	// --------------------------------
	//	DCの属性を変更
	// --------------------------------
	int idSave = SaveDC(  pIfDcdTarget->getHdc() ) ;
	int iMapModePrev = SetMapMode(  pIfDcdTarget->getHdc() , MM_TEXT ) ;
	//	SetMapMode() で MM_TEXT モードに移行すると、
	//	論理単位とデバイス単位の比は１：１に変更されますが、
	//	座標の原点値は変更されません。
	//
	//	LPtoDP() で変換されたデバイス座標は、デバイスコンテキストの
	//	左上隅を原点とした座標を返します。
	//	この座標を使って描画を行うためには、デバイスコンテキストの
	//	論理座標の原点も、デバイス座標 0,0 (左上隅)に設定しなくては
	//	なりません。
	//※  原点の設定は、マッピングモードが MM_TEXT であっても可能です。
	//	ここが、SetViewportExtEx() , SetWindowExtEx() との違いです。
	SetViewportOrgEx( pIfDcdTarget->getHdc() , 0 , 0 , NULL ) ;

	HPEN	hPenSid = (HPEN)SelectObject( pIfDcdTarget->getHdc() , pHPenHolder->getHPen() ) ;

	// --------------------------------
	//	線の描画
	// --------------------------------
	int iLongWidth = 0 ;
	bool	bYIsLong = false ;
	{
		int iXWidth = abs( posDst.getX() - posOrg.getX() ) ;	
		int iYWidth = abs( posDst.getY() - posOrg.getY() ) ;	
		//iXWidth, iYWidth = X,Yの両座標の差。
		//	起点・終点が同一座標の場合は0
		if ( iXWidth > iYWidth ){
			iLongWidth = iXWidth ;
			bYIsLong = false ;
		}	else	{
			iLongWidth = iYWidth ;
			bYIsLong = true ;
		}
	}
	//iLongWidth = X,Y の座標の差のうち、長いほう
	//iShortWidth = X,Y の座標の差のうち、短いほう
	//	起点・終点が同一座標の場合は0
	//bYIsLong = false iLongWidthがX,iShortWidthがY
	//	true iLongWidthがY,iShortWidthがX

	
	if ( m_CdLineProp.isSolidLineStyle() ){
		// ********************************
		//	実線
		// ********************************
		MoveToEx( pIfDcdTarget->getHdc() , posOrg.getX() , posOrg.getY() , 
			NULL ) ;
		LineTo(pIfDcdTarget->getHdc() , posDst.getX() , posDst.getY() ) ;
	}	else	{
		// ********************************
		//	破線
		// ********************************
		string	aLINESTYLE = m_CdLineProp.getLinestyle() ;

		int idxStyle = 0 ;
		int iLongCurr ;
		for ( iLongCurr = 0 ; iLongCurr < iLongWidth ; ){
			CLineFunc	aCLineFunc( posOrg , posDst ) ;
			// --------------------------------
			//	破線部分
			// --------------------------------
			{
				int iLongDst = iLongCurr + 
					( aLINESTYLE[idxStyle] - '0' ) * iDeviceunitPenWidth ; 
				iLongDst -=  ( iDeviceunitPenWidth - 1 ) ;
				idxStyle ++ ;
				if ( idxStyle >= (int)aLINESTYLE.size() ){
					iLongDst += ( aLINESTYLE[0] - '0' ) ; 
					idxStyle = 1 ;
				}

				if ( iLongDst > iLongWidth ){
					iLongDst = iLongWidth ;
				}
				//iLongDst = 
				//	今回描画を行う線は、iLongCurr ～ iLongDst の範囲です。

				
				int iXSrc = 0 ;
				int iYSrc = 0 ;
				int iXDst = 0 ;
				int iYDst = 0 ;
				if ( bYIsLong ){
					iYSrc = posOrg.getY() + 
						iLongCurr  * sign( posDst.getY() -  posOrg.getY() ) ;
					iYDst = posOrg.getY() + 
						iLongDst  * sign( posDst.getY() -  posOrg.getY() ) ;
					iXSrc = aCLineFunc.calcXofY( iYSrc ) ;
					iXDst = aCLineFunc.calcXofY( iYDst ) ;
				}	else	{
					iXSrc = posOrg.getX() + 
						iLongCurr * sign( posDst.getX() -  posOrg.getX() ) ;
					iXDst = posOrg.getX() + 
						iLongDst * sign( posDst.getX() -  posOrg.getX() ) ;
					iYSrc = aCLineFunc.calcYofX( iXSrc ) ;
					iYDst = aCLineFunc.calcYofX( iXDst ) ;
				}	
				MoveToEx( pIfDcdTarget->getHdc() , iXSrc , iYSrc , NULL ) ;
				LineTo(pIfDcdTarget->getHdc() , iXDst, iYDst) ;

				iLongCurr = iLongDst ;
			}
			// --------------------------------
			//	空白部分
			// --------------------------------
			{
				int iLongDst = iLongCurr + 
					( aLINESTYLE[idxStyle] - '0' ) * iDeviceunitPenWidth ;
				iLongDst += ( iDeviceunitPenWidth - 1 ) ;
				idxStyle ++ ;
				if ( idxStyle >= (int)aLINESTYLE.size() ){
					idxStyle = 0 ;
				}
				if ( iLongDst > iLongWidth ){
					iLongDst = iLongWidth ;
				}
				iLongCurr = iLongDst ;
			}
		}
		

	}
	// --------------------------------
	//	DCの属性を復帰
	// --------------------------------
	SelectObject( pIfDcdTarget->getHdc() , hPenSid ) ;
	hPenSid = NULL ;
	if ( idSave != 0 ){
		RestoreDC( pIfDcdTarget->getHdc() , idSave ) ;
		idSave = 0 ;
	}


	return ( true ) ;
}
bool CDcdFreeLine::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	CdDcdSizeXy	aCdDcdSizeXy ;
	if ( m_posOrg.getX() < m_posDst.getX() ){
		aCdDcdSizeXy.setX( 
			m_posDst.getX() - m_posOrg.getX() + 1 ) ;
	}	else	{
		aCdDcdSizeXy.setX( 
			m_posOrg.getX() - m_posDst.getX() + 1 ) ;
	}
	if ( m_posOrg.getY() < m_posDst.getY() ){
		aCdDcdSizeXy.setY(
			m_posDst.getY() - m_posOrg.getY() + 1 ) ;
	}	else	{
		aCdDcdSizeXy.setY(
			m_posOrg.getY() - m_posDst.getY() + 1 ) ;
	}
	// --------------------------------
	aCdDcdSizeXy.setX( aCdDcdSizeXy.getX() + 
		( m_CdLineProp.getLogicalunitWidth() - 1 ) ) ;
	aCdDcdSizeXy.setY( aCdDcdSizeXy.getY() - 
		( m_CdLineProp.getLogicalunitWidth() - 1 ) ) ;

	// --------------------------------
	*pCdDcdSizeXy = aCdDcdSizeXy ;
	
	return ( true ) ;
}

} //namespace DcDraw
} //namespace DcDrawLib

