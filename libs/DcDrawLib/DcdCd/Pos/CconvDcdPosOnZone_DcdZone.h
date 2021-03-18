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
//	CconvDcdPosOnZone_DcdZone.h
// ****************************************************************
*/
/** @file */
#ifndef  CconvDcdPosOnZone_DcdZone_h
#define  CconvDcdPosOnZone_DcdZone_h
#include "DcdCd\Pos\CdDcdZone.h"
#include "DcdCd\Pos\CconvDcdPosOnZone.h"

namespace DcDrawLib{
namespace DcdCd{
namespace Pos{


// ****************************************************************
//	CconvDcdPosOnZone_DcdZone
// ****************************************************************
/**
 @brief
	【概要】
	  ２つの一次元座標系の間で、座標を変換します。
	
	  このクラスは、座標系 Zone1 上の座標値を、 Zone2 上の座標値に
	変換することができます。
	
	  座標系 Zone1 と Zone2 は、 CdDcdZone 型の属性 m_Zone1,m_Zone2 として
	表します。
	  m_Zone1,m_Zone2 は、同じ『基準範囲』を 
	座標系 Zone1 ・ 座標系 Zone2 で表した座標値です。
	
	  （例）
	
	  座標系が、
	
	-	m_Zone1 = { Pos=0 , Size=10 }
	-	m_Zone2 = { Pos=0 , Size=20 }
	
	である場合、これは、
	  「座標系 Zone1 での範囲 { Pos=0 , Size=10 } は、
	座標系 Zone2 では { Pos=0 , Size=20 } となる」ことを意味します。
	
	  この状態で、
	
	  Zone1上の位置 5 を Zone2 に変換すると、 10 となります。
	
	  また、Zone1 上の範囲(CdDcdZone){ Pos= 3 , Size=5 } を、
	Zone2 に変換すると、{ Pos=6 , Size=10 } となります。
	
 */
class CconvDcdPosOnZone_DcdZone : public CconvDcdPosOnZone
{
 private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		座標系 Zone1 での、『基準範囲』の座標値。
	 */
	CdDcdZone	m_Zone1 ;
	
	/**
		座標系 Zone2 での、『基準範囲』の座標値。
	 */
	CdDcdZone	m_Zone2 ;
	
	///@}
 public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	 @param aZone1 [in]
		座標系 Zone1 での、『基準範囲』の座標値。\n
		Size には、 0 を指定しないでください（ゼロ割り算になります）。
	 @param aZone2 [in]
		座標系 Zone2 での、『基準範囲』の座標値。\n
		Size には、 0 を指定しないでください（ゼロ割り算になります）。
	 */
	CconvDcdPosOnZone_DcdZone( 
		const CdDcdZone& aZone1 ,
		const CdDcdZone& aZone2 ) ;

	/**
	 このコンストラクタは、 m_Zone1 , m_Zone2 とも、
		Pos=0 , Size=1 に初期化します。
	 */
	CconvDcdPosOnZone_DcdZone() ;

	virtual ~CconvDcdPosOnZone_DcdZone() ;

 public:
	// ********************************
	///@name CconvDcdPosOnZone_DcdZone-属性
	// ********************************
	///@{
	CdDcdZone	getZone1()const ;
	CconvDcdPosOnZone_DcdZone& setZone1( const CdDcdZone& value ) ;
	CdDcdZone	getZone2()const ;
	CconvDcdPosOnZone_DcdZone& setZone2( const CdDcdZone& value ) ;
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
		m_Zone1.getSize()=0の場合は、m_posZone2Org になります。
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
		m_Zone2.getSize()=0の場合は、m_posZone1Org になります。
	 */
	virtual DcdPos Zone1PosFromZone2( DcdPos value )const ;


	///@}
	
	
};

} //namespace Pos
} //namespace DcdCd
} //namespace DcDrawLib




#endif /*CconvDcdPosOnZone_DcdZone_h*/
