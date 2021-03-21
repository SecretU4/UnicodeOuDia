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
//	CconvDcdPosOnZone_DcdZone.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include "CconvDcdPosOnZone_DcdZone.h"

// ****************************************************************
//	CconvDcdPosOnZone_DcdZone
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CconvDcdPosOnZone_DcdZone::CconvDcdPosOnZone_DcdZone( 
		const CdDcdZone& aZone1 ,
		const CdDcdZone& aZone2 ) :
	m_Zone1( aZone1 ) ,	
	m_Zone2( aZone2 )
{
}

CconvDcdPosOnZone_DcdZone::CconvDcdPosOnZone_DcdZone() :
	m_Zone1( 0 , 1 ) ,	
	m_Zone2( 0 , 1 )
{
}

CconvDcdPosOnZone_DcdZone::~CconvDcdPosOnZone_DcdZone() 
{
}

// ********************************
//	CconvDcdPosOnZone_DcdZone
// ********************************
	// ********************************
	//@name 属性
	// ********************************
CdDcdZone	CconvDcdPosOnZone_DcdZone::getZone1()const 
{
	return m_Zone1 ;	
}
CconvDcdPosOnZone_DcdZone& CconvDcdPosOnZone_DcdZone::setZone1( 
	const CdDcdZone& value ) 
{
	m_Zone1 = value ;
	return *this ;	
}
CdDcdZone	CconvDcdPosOnZone_DcdZone::getZone2()const 
{
	return m_Zone2 ;	
}
CconvDcdPosOnZone_DcdZone& CconvDcdPosOnZone_DcdZone::setZone2( 
	const CdDcdZone& value ) 
{
	m_Zone2 = value ;
	return *this ;	
}
	
	// ********************************
	//@name 操作
	// ********************************
DcdPos CconvDcdPosOnZone_DcdZone::Zone1PosToZone2( DcdPos value )const 
{
	DcdPos	iRv = value - m_Zone1.getPos() ;
	iRv *= m_Zone2.getSize() ;
	if ( m_Zone1.getSize() == 0 ){
		iRv = 0 ;
	}	else	{
		iRv /= m_Zone1.getSize() ;
	}
	iRv += m_Zone2.getPos() ;
	return ( iRv ) ;
}

DcdPos CconvDcdPosOnZone_DcdZone::Zone1PosFromZone2( DcdPos value )const 
{
	DcdPos	iRv = value - m_Zone2.getPos() ;
	iRv *= m_Zone1.getSize() ;
	if ( m_Zone2.getSize() == 0 ){
		iRv = 0 ;
	}	else	{
		iRv /= m_Zone2.getSize() ;
	}
	iRv += m_Zone1.getPos() ;
	return ( iRv ) ;
}

CdDcdZone CconvDcdPosOnZone_DcdZone::Zone1ToZone2(
	const CdDcdZone& value )const 
{
	DcdPos	aPos = Zone1PosToZone2( value.getPos() ) ;
	DcdPos	aEndPos = Zone1PosToZone2( value.getEndPos() ) ;
	return ( CdDcdZone( aPos , aEndPos - aPos ) ) ;
}

CdDcdZone CconvDcdPosOnZone_DcdZone::Zone1FromZone2( 
	const CdDcdZone& value )const 
{
	DcdPos	aPos = Zone1PosFromZone2( value.getPos() ) ;
	DcdPos	aEndPos = Zone1PosFromZone2( value.getEndPos() ) ;
	return ( CdDcdZone( aPos , aEndPos - aPos ) ) ;
}



