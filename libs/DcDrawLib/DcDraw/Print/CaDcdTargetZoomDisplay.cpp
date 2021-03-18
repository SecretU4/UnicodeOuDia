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
//	CaDcdTargetZoomDisplay.cpp
// ****************************************************************
*/
#include "CaDcdTargetZoomDisplay.h"
#include "DcDraw/CConverter_WinGdi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcDraw{
namespace Print{


// ****************************************************************
//	CaDcdTargetZoomDisplay
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CaDcdTargetZoomDisplay::CaDcdTargetZoomDisplay( 
		IfDcdTarget* pTarget ,
		HDC	hPrinterHdc ) :
	m_pTarget( pTarget ),
	m_hPrinterHdc( hPrinterHdc ) ,
	m_iSaveDcId( 0 ) 
{
	CConverter_WinGdi	aConverter ;

	// --------------------------------
	//	DCの状態を待避
	// --------------------------------
	m_iSaveDcId = SaveDC( m_pTarget->getHdc() ) ;

	// --------------------------------
	HDC	hDcTarget = m_pTarget->getHdc() ;
	HDC	hDcPrinter = m_hPrinterHdc ;

	//hDcTarget = プリンタ/印刷プレビューウインドウのDC
	//hDcPrinter = プリンタのDCです。
	//	これは、スケール値を求めるのに使います。

	// --------------------------------
	//	描画先DC中で
	//	描画ができる領域を取得
	// --------------------------------
	CdDcdZoneXy	zoneLogical ;
	CdDcdZoneXy	zoneDevice ;
	{
		zoneLogical = m_pTarget->getZone() ;
		zoneDevice = aConverter.LPtoDP( zoneLogical , hDcTarget ) ;
	}		
	//zoneLogical = 描画先DC上での、描画領域(論理座標)
	//zoneDevice = 描画先DC上での、描画領域(デバイス座標)
	
	// --------------------------------
	//	ターゲットのDCの座標系を変更
	// --------------------------------
	{
		CdDcdZoneXy	zoneZoomLogical ;
		CdDcdZoneXy	zoneZoomDevice ;

	
		int iMapMode = GetMapMode( hDcTarget ) ;
		if ( iMapMode == MM_TEXT ){
			zoneZoomDevice.setX( CdDcdZone( 0 , GetDeviceCaps( hDcTarget , HORZRES ) ) )
				.setY( CdDcdZone( 0 , GetDeviceCaps( hDcTarget , VERTRES ) ) ) ;
			zoneZoomLogical = zoneZoomDevice ;
			
		}	else	{

			{
				POINT	aPOINT ;
				SIZE	aSIZE ;
				GetWindowExtEx( hDcTarget , &aSIZE ) ;
				GetWindowOrgEx( hDcTarget , &aPOINT ) ;
				zoneZoomLogical.setX( CdDcdZone( aPOINT.x , aSIZE.cx ) ) 
					.setY( CdDcdZone( aPOINT.y , aSIZE.cy ) ) ;
			}
			{
				POINT	aPOINT ;
				SIZE	aSIZE ;
				GetViewportExtEx( hDcTarget , &aSIZE ) ;
				GetViewportOrgEx( hDcTarget , &aPOINT ) ;
				zoneZoomDevice.setX( CdDcdZone( aPOINT.x , aSIZE.cx ) )
					.setY( CdDcdZone( aPOINT.y , aSIZE.cy ) ) ;
			}
			//zoneZoomLogical = 描画先DCの論理座標における、
			//	原点値と大きさ。
			//zoneZoomDevice =  描画先DCのデバイス座標における、
			//	原点値と大きさ。
			//
			//	デバイス座標における、
			//	(zoneZoomDeveice.X.Pos,zoneZoomDeveice.Y.Pos) 
			//	の位置に、論理座標
			//	(zoneLogical.X.Pos,zoneLogical.Y.Pos)
			//	が割り当てられています。
			//
			//	デバイス座標における、
			//	(zoneZoomDeveice.X.Size,zoneZoomDeveice.Y.Size) 
			//	の大きさが、論理座標
			//	(zoneLogical.X.Pos,zoneLogical.Y.Pos)
			//	の大きさに相当します。
			//	
			//	この段階では、
			//
			//	Logical.Size : Device.Size は、
			//
			//	プリンタの１ページのピクセル数： 
			//		描画先DCのピクセル数
			//
			//	となります。
		}

		// --------------------------------
		//	ズーム計算
		//	zoneZoomDevice  zoneZoomLogical のうち、
		//	大きい方の値を変更します。
		// --------------------------------
		if ( zoneZoomDevice.getX().getSize() < zoneZoomLogical.getX().getSize() ){
			//	論理座標の側を変更
			//	これは、論理座標を小さくして調整します。
			//
			//	プリンタプレビューの場合は、
			//	デバイス座標での幅  < 論理座標（プリンタの１ドットを基準とした座標）での幅
			//	となります。

			HDC	hdcDisplay = GetDC( NULL ) ;

			int iX = zoneZoomLogical.getX().getSize() ;
			iX *= GetDeviceCaps( hdcDisplay , LOGPIXELSX ) ; 
			iX /= GetDeviceCaps( hDcPrinter , LOGPIXELSX ) ; 

			int iY = zoneZoomLogical.getY().getSize() ;
			iY *= GetDeviceCaps( hdcDisplay , LOGPIXELSY ) ; 
			iY /= GetDeviceCaps( hDcPrinter , LOGPIXELSY ) ; 

			zoneZoomLogical.setSize( CdDcdSizeXy( iX , iY ) ) ;

			ReleaseDC( NULL , hdcDisplay ) ;
		}	else	{
			//	論理座標の側を変更
			//	これは、デバイス座標を大きくして調整します。
			//
			//	プリンタへの印刷の場合は、
			//	デバイス座標での幅  > 論理座標
			//	となります。
			
			HDC	hdcDisplay = GetDC( NULL ) ;

			int iX = zoneZoomDevice.getX().getSize() ;
			iX *= GetDeviceCaps( hDcPrinter , LOGPIXELSX ) ; 
			iX /= GetDeviceCaps( hdcDisplay , LOGPIXELSX ) ; 

			int iY = zoneZoomDevice.getY().getSize() ;
			iY *= GetDeviceCaps( hDcPrinter , LOGPIXELSY ) ; 
			iY /= GetDeviceCaps( hdcDisplay , LOGPIXELSY ) ; 

			zoneZoomDevice.setSize( CdDcdSizeXy( iX , iY ) ) ;

			ReleaseDC( NULL , hdcDisplay ) ;

			
		}
		//zoneLogical = 
		//	論理座標の大きさを、 CdDcdTargetPrinter での計算式に
		//	合わせて換算します。
		//	
		//	これは、
		//
		//	プリンタの論理インチあたりのピクセル数:
		//		ディスプレイの論理インチあたりのピクセル数
		//
		//	に準じた計算となります。

		// --------------------------------
		{
			//	ターゲットDCのマップモード（座標系）を変更
			SetMapMode( hDcTarget , MM_ANISOTROPIC);
		    SetWindowExtEx( hDcTarget , 
				zoneZoomLogical.getX().getSize() , 
				zoneZoomLogical.getY().getSize() , 
				NULL );  
		    SetViewportExtEx( hDcTarget , 
				zoneZoomDevice.getX().getSize() , 
				zoneZoomDevice.getY().getSize() , 
				NULL );  
		}

	}
	// --------------------------------
	//	プレビューウインドウ中で
	//	描画ができる領域を、
	//	DCに設定したスケールに従って再計算
	// --------------------------------
	{
		zoneLogical = aConverter.DPtoLP( zoneDevice  , hDcTarget ) ;
	}		
	//zoneLogical = プレビューウインドウ中で描画のできる領域(論理座標)
	//zoneDevice = プレビューウインドウ中で描画のできる領域(デバイス座標)

	// --------------------------------
	m_zonexyZone = zoneLogical ;

	
}

CaDcdTargetZoomDisplay::~CaDcdTargetZoomDisplay() 
{
	if ( m_iSaveDcId != 0 ){
		RestoreDC( m_pTarget->getHdc() , m_iSaveDcId ) ;
		m_iSaveDcId = 0 ;
	}
}

// ********************************
//@name	IfDcdTarget
// ********************************
HDC	CaDcdTargetZoomDisplay::getHdc() 
{
	return ( m_pTarget->getHdc() ) ;
}

CdDcdZoneXy CaDcdTargetZoomDisplay::getZone() 
{
	return ( m_zonexyZone ) ;
}

CdDcdZoneXy CaDcdTargetZoomDisplay::getDrawableZone() 
{
	return ( m_zonexyZone ) ;
}

// ********************************
//	CaDcdTargetZoomDisplay_h
// ********************************
	// ********************************
	//@name 関連
	// ********************************

} //namespace Print
} //namespace DcDraw
} //namespace DcDrawLib
