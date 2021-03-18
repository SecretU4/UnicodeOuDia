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
//	CconvDcdPosOnZone_PosOrgAndRate.h
// $Id: CconvDcdPosOnZone_PosOrgAndRate.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CconvDcdPosOnZone_PosOrgAndRate_h
#define  CconvDcdPosOnZone_PosOrgAndRate_h
#include "DcdCd\Pos\CdDcdZone.h"
#include "DcdCd\Pos\CconvDcdPosOnZone.h"
// ****************************************************************
//	CconvDcdPosOnZone_PosOrgAndRate
// ****************************************************************
/**
 @brief
	【概要】
	  ２つの一次元座標系の間で、座標を変換します。
	
	  このクラスは、座標系 Zone1 上の座標値を、 Zone2 上の座標値に
	変換することができます。
	
	  座標系 Zone1 と Zone2 は、
	  
      - m_posZone1Org ：DcdPos	Zone1の始点
      - m_posZone2Org ：DcdPos	Zone2の始点
      - m_dZone2PerZone1 ：double Zone1での座標1に対応する、Zone2での座標
	 
	で表します。

  （例1）座標系が、
	-	m_posZone1Org = 0 
	-	m_posZone2Org = 0 
	-	m_dZone2PerZone1 = 2

	である場合、これは、
	  「座標系 Zone1 の位置 0 はZone2 の位置 0 となる。
	  その位置を基準として、Zone1の距離1が、Zone2の距離 m_dZone2PerZone1 となる」
	ことを意味します。
	
	  この状態で、
	
	  Zone1上の位置 5 を Zone2 に変換すると、 10 となります。
	
	  また、Zone1 上の範囲(CdDcdZone){ Pos= 3 , Size=5 } を、
	Zone2 に変換すると、{ Pos=6 , Size=10 } となります。
	
  （例2）座標系が、
	-	m_posZone1Org = 5 
	-	m_posZone2Org = 0 
	-	m_dZone2PerZone1 = 2

	である場合、これは、
	  「座標系 Zone1 の位置 0 はZone2 の位置 0 となる。
	  その位置を基準として、Zone1の距離1が、Zone2の距離 m_dZone2PerZone1 となる」
	ことを意味します。
	
	  この状態で、
	
	  Zone1上の位置 5 を Zone2 に変換すると、 0 となります。
	
	  また、Zone1 上の範囲(CdDcdZone){ Pos= 3 , Size=5 } を、
	Zone2 に変換すると、{ Pos=-4 , Size=10 } となります。

@ref cconvdcdposonzone_posorgandrate_towindowscroll

@ref cconvdcdposonzone_posorgandrate 
 
 */
class CconvDcdPosOnZone_PosOrgAndRate : public CconvDcdPosOnZone
{
 private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		座標系 Zone1 の始点。既定値=0
	 */
	DcdPos	m_posZone1Org ;
	
	/**
		座標系 Zone2の始点。既定値=0
	 */
	DcdPos	m_posZone2Org ;

	/**
    	 Zone1での座標1に対応する、Zone2での座標。
		0 を指定した場合の動作は、個別のメソッドの説明を参照してください。
		既定値=1
	*/
	double m_dZone2PerZone1 ;
	///@}
 public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	@param posZone1Org [in]
		座標系 Zone1 の始点。
	@param posZone2Org [in]
		座標系 Zone2の始点
	@param dZone2PerZone1 [in]
    	 Zone1での座標1に対応する、Zone2での座標
		0 を指定しないでください（ゼロ割り算になります）。
	*/
	CconvDcdPosOnZone_PosOrgAndRate( 
		DcdPos	posZone1Org , 
		DcdPos	posZone2Org ,
		double dZone2PerZone1 ) ;

	/**
	 このコンストラクタは、属性を既定値に初期化します。
	 */
	CconvDcdPosOnZone_PosOrgAndRate() ;

	virtual ~CconvDcdPosOnZone_PosOrgAndRate() ;

 public:
	// ********************************
	///@name CconvDcdPosOnZone_PosOrgAndRate-属性
	// ********************************
	///@{
	/**
		座標系 Zone1 の始点。既定値=0
	 */
	DcdPos	getZone1Org()const{	return m_posZone1Org ;};
	void setZone1Org( DcdPos value )
	{	m_posZone1Org = value ;};
	DcdPos	getZone2Org()const{	return m_posZone2Org ;};
	void setZone2Org( DcdPos value )
	{	m_posZone2Org = value ;};
	double getZone2PerZone1()const{	return m_dZone2PerZone1 ;};
	void setZone2PerZone1( double value )
	{	m_dZone2PerZone1 = value ;};
	///@}
	
	// ********************************
	///@name CconvDcdPosOnZone-操作
	// ********************************
	///@{
	/**
		Zone1 の座標系
		での位置を、
		Zone2 の座標系
		に変換します。
	 @param value [in]
		変換前の値を指定して下さい。
	 @return
		変換後の値を返します。
		
		m_dZone2PerZone1=0の場合は、m_posZone2Org になります。
	 */
	virtual DcdPos Zone1PosToZone2( DcdPos value )const ;
	
	/**
		Zone2 の座標系
		での位置を、
		Zone1 の座標系
		に変換します。
	 @param value [in]
		変換前の値を指定して下さい。
	 @return
		変換後の値を返します。
		m_dZone2PerZone1=0の場合は、m_posZone1Org になります。
	 */
	virtual DcdPos Zone1PosFromZone2( DcdPos value )const ;

	/**
		Zone1 の座標系
		での範囲を、
		Zone2 の座標系
		に変換します。
	 @param value [in]
		変換前の値を指定して下さい。
	 @return
		変換後の値を返します。
		m_dZone2PerZone1=0の場合は、CdDcdZone(m_posZone1Org,0) になります。
	 */
	virtual CdDcdZone Zone1ToZone2( const CdDcdZone& value )const ;
	
	/**
		Zone2 の座標系
		での範囲を、
		Zone1 の座標系
		に変換します。
	 @param value [in]
		変換前の値を指定して下さい。
	 @return
		変換後の値を返します。
		m_dZone2PerZone1=0の場合は、CdDcdZone(m_posZone2Org,0) になります。
	 */
	virtual CdDcdZone Zone1FromZone2( const CdDcdZone& value )const ;
	///@}
	
	
};


/**
@page cconvdcdposonzone_posorgandrate_towindowscroll CconvDcdPosOnZone_PosOrgAndRate を使ったスクロール可能ウインドウへの座標変換

　CconvDcdPosOnZone_PosOrgAndRate を使って、ドキュメント全体の座標を、
スクロール可能なウインドウの上の座標に変換することができます。

	- Zone1=ドキュメント全体の座標系
	- Zone2=ウインドウ上の座標系

(1)　以下のように属性を設定してください。

	- Zone1Org=ウインドウ上で左上に表示する、ドキュメントの座標。
	- Zone2PerZone1=ウインドウ上での表示倍率。2なら、ドキュメントの1の長さを、
		ウインドウの2ドットに表示します。
	- Zone2Org=ウインドウの左上の座標。

(2)Zone1PosToZone2,Zone1ToZone2 で、ドキュメント座標をウインドウ上の座標に
変換できます。

*/


#endif /*CconvDcdPosOnZone_PosOrgAndRate_h*/
