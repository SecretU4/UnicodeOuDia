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
//	CconvDcdPosOnZone_PosOrgAndRate.cpp
// $Id: CconvDcdPosOnZone_PosOrgAndRate.cpp 313 2016-06-11 13:20:04Z okm $
// ****************************************************************
*/
/** @file */
#include "CconvDcdPosOnZone_PosOrgAndRate.h"


/** @page cconvdcdposonzone_posorgandrate CconvDcdPosOnZone_PosOrgAndRate 変換式

　座標の変換には、下記の変換式2を使用しています。

◎変換式1
  - Zone1上の座標を posZone1Pos
  - Zone2上の座標を posZone2Pos 
  とした場合、
  
@code
  posZone2Pos = (int)( (double)( posZone1Pos - Zone1Org ) * Zone2PerZone1 ) 
               + Zone2Org 
@endcode

  (例)
  - Zone1Org=*
  - Zone2Org=0
  - Zone2PerZone1=1.5

  - Zone1Org=0
@code
  posZone1Pos  posZone2Pos
  ─────────────
            0            0
            1      1.5→ 1
            2            3
            3      4.5→ 4
@endcode

  - Zone1Org=1
@code
  posZone1Pos  posZone2Pos
  ─────────────
            0     -1.5→-1
            1            0
            2      1.5→ 1
            3            3
@endcode

   @ref cconvdcdposonzone_posorgandrate_towindowscroll には、
   この変換式は使えません。
  上記で示したように、posZone1Pos=1とposZone1Pos=2の間の、Zone2上での距離が 
  Zone1Org によって変動してしまいます。


◎変換式2
  - Zone1上の座標を posZone1Pos
  - Zone2上の座標を posZone2Pos 
  とした場合、
  
@code
  posZone2Pos = (int)( (double)posZone1Pos * Zone2PerZone1 ) 
              - (int)( (double)Zone1Org  * Zone2PerZone1 )
	      + Zone2Org 
@endcode

  (例)
  - Zone1Org=*
  - Zone2Org=0
  - Zone2PerZone1=1.5

  - Zone1Org=0
@code
  posZone1Pos  posZone2Pos
  ─────────────
            0            0
            1      1.5→ 1
            2            3
            3      4.5→ 4
@endcode

  - Zone1Org=1
@code
  posZone1Pos                posZone2Pos
  ────────────────────
            0            0 -1=-1
            1      1.5→ 1 -1= 0
            2            3 -1= 2
            3      4.5→ 4 -1= 3
@endcode


   @ref cconvdcdposonzone_posorgandrate_towindowscroll には、
   この変換式が有効です。
  posZone1Pos=1とposZone1Pos=2の間の、Zone2上での距離は、
  Zone1Org の変動の影響を受けません。
*/

namespace DcDrawLib{
namespace DcdCd{
namespace Pos{


// ****************************************************************
//	CconvDcdPosOnZone_PosOrgAndRate
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CconvDcdPosOnZone_PosOrgAndRate::CconvDcdPosOnZone_PosOrgAndRate( 
		DcdPos	posZone1Org , 
		DcdPos	posZone2Org ,
		double dZone2PerZone1 ) :
	m_posZone1Org( posZone1Org ) ,	
	m_posZone2Org( posZone2Org ) , 
	m_dZone2PerZone1( dZone2PerZone1 )
{
}

CconvDcdPosOnZone_PosOrgAndRate::CconvDcdPosOnZone_PosOrgAndRate() :
	m_posZone1Org( 0 ) ,	
	m_posZone2Org( 0 ) , 
	m_dZone2PerZone1( 1.0 )
{
}

CconvDcdPosOnZone_PosOrgAndRate::~CconvDcdPosOnZone_PosOrgAndRate() 
{
}

// ********************************
//	CconvDcdPosOnZone_PosOrgAndRate
// ********************************
	
	// ********************************
	//@name 操作
	// ********************************
DcdPos CconvDcdPosOnZone_PosOrgAndRate::Zone1PosToZone2( DcdPos posZone1Pos )const 
{
	DcdPos posZone2Pos = (int)( (double)posZone1Pos * m_dZone2PerZone1 ) 
          - (int)( (double)m_posZone1Org  * m_dZone2PerZone1 )
	      + m_posZone2Org ;
	return ( posZone2Pos ) ;
}

DcdPos CconvDcdPosOnZone_PosOrgAndRate::Zone1PosFromZone2( DcdPos posZone2Pos )const 
{
	double	dZone1PerZone2 = 0.0 ;
	if ( m_dZone2PerZone1 != 0.0 )
	{
		dZone1PerZone2 = (double)1 / m_dZone2PerZone1 ;
	}
	DcdPos posZone1Pos = (int)( (double)posZone2Pos * dZone1PerZone2 ) 
			- (int)( (double)m_posZone2Org * dZone1PerZone2 )
			+ m_posZone1Org ;

	return ( posZone1Pos ) ;
}


} //namespace Pos
} //namespace DcdCd
} //namespace DcDrawLib


