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
//	CconvCdPrintPageProp.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CconvCdPrintPageProp.h"
#include "DcDraw/CDcDeviceUnitSizeX.h"
#include "DcDraw/CDcDeviceUnitSizeY.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace Print{

// ****************************************************************
//	CconvCdPrintPageProp
// ****************************************************************
CdDcdZoneXy CconvCdPrintPageProp::calcZoneInnerMargin( 
		const CdPrintPageProp& aCdPrintPageProp , HDC hDc ) 
{
	int iXMarginFromPhysicalOffset1 = 0 ;
	int iXMarginFromPhysicalOffset2 = 0 ;
	int iXRes = 0 ;
	{
		int iPhysicalPageSize = 0 ;
		int iPhysicalOffset1 = 0 ;
		int iPhysicalOffset2 = 0 ; 
		getPhysicalXPageSize( hDc , 
			&iPhysicalPageSize ,
			&iPhysicalOffset1 ,
			&iXRes ,
			&iPhysicalOffset2 ) ; 


		CDcDeviceUnitSizeX	aDeviceUnit( hDc ) ;

		aDeviceUnit.setMmSize( aCdPrintPageProp.getMarginLeftMm() ) ;
		iXMarginFromPhysicalOffset1 = aDeviceUnit.getDeviceUnitSize() - iPhysicalOffset1 ;
		if ( iXMarginFromPhysicalOffset1 < 0 ){
			iXMarginFromPhysicalOffset1 = 0 ;
		}
		aDeviceUnit.setMmSize( aCdPrintPageProp.getMarginRightMm() ) ;
		iXMarginFromPhysicalOffset2 = aDeviceUnit.getDeviceUnitSize() - iPhysicalOffset2 ;
		if ( iXMarginFromPhysicalOffset2 < 0 ){
			iXMarginFromPhysicalOffset2 = 0 ;
		}
	}
	int iYMarginFromPhysicalOffset1 = 0 ;
	int iYMarginFromPhysicalOffset2 = 0 ;
	int iYRes = 0 ;
	{
		int iPhysicalPageSize = 0 ;
		int iPhysicalOffset1 = 0 ;
		int iPhysicalOffset2 = 0 ; 
		getPhysicalYPageSize( hDc , 
			&iPhysicalPageSize ,
			&iPhysicalOffset1 ,
			&iYRes ,
			&iPhysicalOffset2 ) ; 


		CDcDeviceUnitSizeY	aDeviceUnit( hDc ) ;

		aDeviceUnit.setMmSize( aCdPrintPageProp.getMarginTopMm() ) ;
		iYMarginFromPhysicalOffset1 = aDeviceUnit.getDeviceUnitSize() - iPhysicalOffset1 ;
		if ( iYMarginFromPhysicalOffset1 < 0 ){
			iYMarginFromPhysicalOffset1 = 0 ;
		}
		aDeviceUnit.setMmSize( aCdPrintPageProp.getMarginBottomMm() ) ;
		iYMarginFromPhysicalOffset2 = aDeviceUnit.getDeviceUnitSize() - iPhysicalOffset2 ;
		if ( iYMarginFromPhysicalOffset2 < 0 ){
			iYMarginFromPhysicalOffset2 = 0 ;
		}
	}
	
	CdDcdZoneXy	zonexyInneraMargin( 
		CdDcdZone( iXMarginFromPhysicalOffset1 , 
			iXRes - iXMarginFromPhysicalOffset1 - iXMarginFromPhysicalOffset2 ) ,
		CdDcdZone( iYMarginFromPhysicalOffset1 , 
			iYRes - iYMarginFromPhysicalOffset1 - iYMarginFromPhysicalOffset2 ) ) ;
	
	return ( zonexyInneraMargin ) ;		
}


void CconvCdPrintPageProp::getPhysicalXPageSize( HDC hDc , 
		int* piPhysicalPageSize ,
		int* piPhysicalOffset1 ,
		int* piRes ,
		int* piPhysicalOffset2 ) 
{
	int iPhysicalPageSize = 0 ;
	int iPhysicalOffset1 = 0 ;
	int iRes = 0 ;
	int iPhysicalOffset2 = 0 ; 
	// --------------------------------
	iPhysicalPageSize = GetDeviceCaps( hDc , PHYSICALWIDTH ) ;
	iPhysicalOffset1 = GetDeviceCaps( hDc , PHYSICALOFFSETX ) ;
	iRes = GetDeviceCaps( hDc , HORZRES ) ;
	iPhysicalOffset2 = iPhysicalPageSize - iPhysicalOffset1 - iRes ;
	// --------------------------------
	if ( piPhysicalPageSize != NULL ){
		*piPhysicalPageSize = iPhysicalPageSize ;
	}
	if ( piPhysicalOffset1 != NULL ){
		*piPhysicalOffset1 = iPhysicalOffset1 ;
	}
	if ( piRes != NULL ){
		*piRes = iRes ;
	}
	if ( piPhysicalOffset2 != 0 ){ 
		*piPhysicalOffset2 = iPhysicalOffset2 ;
	} 
}

void CconvCdPrintPageProp::getPhysicalYPageSize( HDC hDc , 
		int* piPhysicalPageSize ,
		int* piPhysicalOffset1 ,
		int* piRes ,
		int* piPhysicalOffset2 ) 
{
	int iPhysicalPageSize = 0 ;
	int iPhysicalOffset1 = 0 ;
	int iRes = 0 ;
	int iPhysicalOffset2 = 0 ; 
	// --------------------------------
	iPhysicalPageSize = GetDeviceCaps( hDc , PHYSICALHEIGHT ) ;
	iPhysicalOffset1 = GetDeviceCaps( hDc , PHYSICALOFFSETY ) ;
	iRes = GetDeviceCaps( hDc , VERTRES ) ;
	iPhysicalOffset2 = iPhysicalPageSize - iPhysicalOffset1 - iRes ;
	// --------------------------------
	if ( piPhysicalPageSize != NULL ){
		*piPhysicalPageSize = iPhysicalPageSize ;
	}
	if ( piPhysicalOffset1 != NULL ){
		*piPhysicalOffset1 = iPhysicalOffset1 ;
	}
	if ( piRes != NULL ){
		*piRes = iRes ;
	}
	if ( piPhysicalOffset2 != 0 ){ 
		*piPhysicalOffset2 = iPhysicalOffset2 ;
	} 
}

} //namespace Print


