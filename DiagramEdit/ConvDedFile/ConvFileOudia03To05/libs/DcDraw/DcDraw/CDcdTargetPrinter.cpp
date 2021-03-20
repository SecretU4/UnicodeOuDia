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
//	CDcdTargetPrinter.cpp
// ****************************************************************
*/
//#include "stdafx.h"
#include "CDcdTargetPrinter.h"
#include "DcDraw/CConverter_WinGdi.h"
#include "logmsg/LogMsg.h"

// ****************************************************************
//	CDcdTargetPrinter
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CDcdTargetPrinter::CDcdTargetPrinter( HDC hDc ) 
{
	m_hDc = hDc ;

	CdDcdZoneXy	zonePixel ;
	CdDcdZoneXy	zoneLogical ;
	{	
		zonePixel.setX( CdDcdZone( 0 , GetDeviceCaps( hDc , HORZRES ) ) ).
				setY( CdDcdZone( 0, GetDeviceCaps( hDc , VERTRES ) ) );
		zoneLogical = zonePixel ;
		{
			HDC	hdcDisplay = ::GetDC( NULL ) ;

			int iX = zoneLogical.getX().getSize() ;
			iX *= GetDeviceCaps( hdcDisplay , LOGPIXELSX ) ; 
			iX /= GetDeviceCaps( hDc , LOGPIXELSX ) ; 

			int iY = zoneLogical.getY().getSize() ;
			iY *= GetDeviceCaps( hdcDisplay , LOGPIXELSY ) ; 
			iY /= GetDeviceCaps( hDc , LOGPIXELSY ) ; 

			zoneLogical.setX( CdDcdZone( 0 , iX ) ).
				setY( CdDcdZone( 0 , iY ) );
			::ReleaseDC( NULL , hdcDisplay ) ;
		}
		{
			SetMapMode( hDc , MM_ANISOTROPIC);
		    SetWindowExtEx( hDc , 
				zoneLogical.getX().getSize() , 
				zoneLogical.getY().getSize() , 
				NULL );   // 窓の論理サイズの指定
		    SetWindowOrgEx( hDc , 
				zoneLogical.getX().getPos() , 
				zoneLogical.getY().getPos() , 
				NULL );   // 窓の論理サイズの指定
		    SetViewportExtEx( hDc , 
				zonePixel.getX().getSize() , 
				zonePixel.getY().getSize() , 
				NULL );   //デバイスサイズで窓のサイズの指定
		    SetViewportOrgEx( hDc , 
				zonePixel.getX().getPos() , 
				zonePixel.getY().getPos() ,
				NULL  );	//デバイスサイズで原点の指定

			LogMsg( "PrinterDC\n%s\n" , DeviceCapsToString( hDc ).c_str() ) ;
	
		}
	}

	m_zonePixel = zonePixel ;
	m_zoneLogical = zoneLogical ;
}
	
CDcdTargetPrinter::~CDcdTargetPrinter() 
{
}

// ********************************
//@name	IfDcdTarget
// ********************************
HDC	CDcdTargetPrinter::getHdc() 
{
	return ( m_hDc ) ;
}
	
CdDcdZoneXy CDcdTargetPrinter::getZone() 
{
	return ( m_zoneLogical ) ;
}
	
CdDcdZoneXy CDcdTargetPrinter::getDrawableZone() 
{
	return ( m_zoneLogical ) ;
}

