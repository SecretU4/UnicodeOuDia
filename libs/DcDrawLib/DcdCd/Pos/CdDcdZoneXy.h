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
//	DcdCd\Pos\CdDcdZoneXy.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDcdZoneXy_h
#define  CdDcdZoneXy_h

#include "./CdDcdZone.h"
#include "./CdDcdPosXy.h"
#include "./CdDcdSizeXy.h"

namespace DcDrawLib{
namespace DcdCd{
namespace Pos{


// ****************************************************************
//	CdDcdZoneXy.h
// ****************************************************************
/**
 @brief
 【概要】
	   XY 座標上の矩形範囲を表す単純データクラスです。
*/
class CdDcdZoneXy
{
private:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	///	Xの範囲です。
	CdDcdZone	m_zoneX ;
	///	Yの範囲です。
	CdDcdZone	m_zoneY ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CdDcdZoneXy(){} ;
	
	/**
	 @param tX [in]
	 	 X 座標の値を指定してください。
	 @param tY [in]
	 	 Y 座標の値を指定してください。
	*/
	CdDcdZoneXy( const CdDcdZone& tX , const CdDcdZone& tY ) : 
		m_zoneX( tX ) , m_zoneY( tY ) {};

	/**
	 	指定の位置から１の範囲を表すオブジェクトを生成します
	 @param posX [in]
	 	X座標の値を指定してください。
	 @param posY [in]
	 	Y座標の値を指定してください。
	*/
	CdDcdZoneXy( DcdPos posX , DcdPos posY ) : 
		m_zoneX( posX , 1 ) , m_zoneY( posY , 1 ) {};

	/**
	 	起点位置とサイズを指定して、オブジェクトを生成します。
	 @param posXy [in]
	 	起点を指定してください。
	 @param sizeXy [in]
	 	Y座標の値を指定してください。
	*/
	CdDcdZoneXy( const CdDcdPosXy& posXy ,
				const CdDcdSizeXy& sizeXy ) : 
		m_zoneX( posXy.getX() , sizeXy.getX() ) , 
		m_zoneY( posXy.getY() , sizeXy.getY() ) {};

	/**
	 	起点位置から１の範囲を表すオブジェクトを生成します。
	 @param posXy [in]
	 	起点を指定してください。
	 @param sizeXy [in]
	 	Y座標の値を指定してください。
	*/
	CdDcdZoneXy( const CdDcdPosXy& posXy ) : 
		m_zoneX( posXy.getX() , 1 ) , 
		m_zoneY( posXy.getY() , 1 ) {};

 public:
	// ********************************
	///@name	CdDcdZoneXy-属性
	// ********************************
	///@{
	CdDcdZone getX()const{	return ( m_zoneX ) ;	};
	CdDcdZoneXy&  setX( const CdDcdZone& ev ){	
		m_zoneX = ev ;	return ( *this ) ;	};
	CdDcdZone getY()const{	return ( m_zoneY ) ;	};
	CdDcdZoneXy&  setY( const CdDcdZone ev ){	
		m_zoneY = ev ;	return ( *this ) ;	};
	/**
	 @return
	 	起点の位置を返します。
	*/
	CdDcdPosXy	getPos()const{
		return ( CdDcdPosXy( m_zoneX.getPos() , m_zoneY.getPos() ) ) ;
	};
		
	/**
	 	起点を設定します。
	 @param posXy [in]
	 	起点を指定してください。
	*/
	CdDcdZoneXy&	setPos( const CdDcdPosXy posXy ){
		m_zoneX.setPos( posXy.getX() ) ;
		m_zoneY.setPos( posXy.getX() ) ;
		return *this ;
	};
		
	/**
	 @return
	 	領域のサイズを返します。
	*/
	CdDcdSizeXy	getSize()const{
		return ( CdDcdSizeXy( m_zoneX.getSize() , m_zoneY.getSize() ) ) ;
	};
		
	/**
	 	サイズを設定します。
	 @param sizeXy [in]
	 	サイズを指定してください。
	*/
	CdDcdZoneXy&	setSize( const CdDcdSizeXy sizeXy ){
		m_zoneX.setSize( sizeXy.getX() ) ;
		m_zoneY.setSize( sizeXy.getY() ) ;
		return *this ;
	};
		
	/**
	 @return
	   範囲の終点位置の次の位置を返します。
	 	この位置は、範囲には含まれません。
	*/
	CdDcdPosXy	getEndPos()const{
		return ( CdDcdPosXy( m_zoneX.getEndPos() , m_zoneY.getEndPos() ) ) ;
	};
	
	///@}

	// ********************************
	///@name	CdDcdZoneXy-操作
	// ********************************
	///@{
	
	/**
	 	  範囲の大きさを表す値の符号を、正の数・または負の数に変更します。
	 	  この場合でも、座標範囲は変わりません。
	 	(例) Pos = 1,Size=5のオブジェクトに、 ev=-1 でこのメソッドを呼び出すと
	 	Pos = 5 ,Size=-5 になります。
	 @param ev [in]
	 	符号を正の数にするなら１・負の数にするなら−１を指定してください。
	*/
	CdDcdZoneXy& setSizeSign( int ev = 1 ){
		m_zoneX.setSizeSign( ev ) ;
		m_zoneY.setSizeSign( ev ) ;
		return *this ;
	};
	
	/**
	 	他のCdDcdZoneXyとの比較を行います。
	 @param ev [in]
	 	比較対象を指定してください。
	 @return
	 	すべての属性が同じであれば真です。
	*/
	bool IsEqualTo( const CdDcdZoneXy& ev )const{
		return ( m_zoneX.IsEqualTo( ev.m_zoneX ) 
						&& m_zoneY.IsEqualTo( ev.m_zoneY ) ) ;
	};
	
	/**
	 	この範囲と、指定された別の範囲との間で、交差している範囲を
	 	求めます。
	 @param ev [in]
	 	交差を求める対象になる CdDcdZone オブジェクトを指定してください。
	 @return
	 	この範囲と、ev とが交差している領域を返します。
		x,yそれぞれについて、交差領域を求めます。
	
	   - this か ev のいずれかの Size が０であれば、起点がthisと同じ、
	 	  サイズが０のオブジェクトを返します。
	   - thisとevの符号が異なる場合は、evの方の符号を反転して、
	 	  交差範囲を求めます。この場合、戻り値の符号は
	 	  thisと同じ方向になります。
	   - this と ev に交差している領域がない場合は、起点がthisと同じ、
	 	  サイズが０のオブジェクトを返します。
	*/
	CdDcdZoneXy CrossZone( const CdDcdZoneXy& ev )const{
		return ( CdDcdZoneXy( m_zoneX.CrossZone( ev.getX() ) , 
							  m_zoneY.CrossZone( ev.getY() ) ) ) ; 
	};
	/**
	  	この範囲と、指定された別の範囲を含む、
		最も小さい範囲を求めます。
	 @param ev [in]
	  	包含を求める対象になる CdDcdZoneXy オブジェクトを指定してください。
	 @return
	  	この範囲と、ev を包含する領域を返します。
	    - thisとevの符号が異なる場合は、evの方の符号を反転して、
	  	交差範囲を求めます。この場合、戻り値の符号は
	  	thisと同じ方向になります。
	*/
	CdDcdZoneXy ZoneOr( const CdDcdZoneXy& ev )const{
		return ( CdDcdZoneXy( m_zoneX.ZoneOr( ev.getX() ) , 
							  m_zoneY.ZoneOr( ev.getY() ) ) ) ; 
	};
	
	/**
	 	指定の位置がこの範囲に含まれているかどうかを判断します。
	 @param ev [in]
	 	判定する位置を指定してください。
	 @return
	 	位置がこの範囲に含まれていれば真です。
	*/
	bool IsInner( const CdDcdPosXy& ev )const{	
		return ( m_zoneX.IsInner( ev.getX() ) 
			  && m_zoneY.IsInner( ev.getY() )  ) ;
	};
	
	/**
	 	指定の矩形領域がこの範囲に含まれているかどうかを判断します。
	 @param ev [in]
	 	判定する位置を指定してください。
	 @return
	 	位置がこの範囲に含まれていれば真です。
	*/
	bool IsInner( const CdDcdZoneXy& ev )const{	
		return ( m_zoneX.IsInner( ev.getX() ) 
			  && m_zoneY.IsInner( ev.getY() )  ) ;
	};
	
	///@}

	// ********************************
	///@name	演算子	
	// ********************************
	///@{
	bool operator ==( const CdDcdZoneXy& ev )const{	
		return (  IsEqualTo( ev ) ) ; 
	};
	bool operator !=( const CdDcdZoneXy& ev )const{
		return ( !IsEqualTo( ev ) ) ; 
	};
	///@}
	
};

} //namespace Pos
} //namespace DcdCd
} //namespace DcDrawLib

#endif /*CdDcdZoneXy_h*/

