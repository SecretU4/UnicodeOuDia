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
//	CDcdTargetCompatibleBitmap.cpp
// ****************************************************************
*/
#include "CDcdTargetCompatibleBitmap.h"
#include "CConverter_WinGdi.h"

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CDcdTargetCompatibleBitmap
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CDcdTargetCompatibleBitmap::CDcdTargetCompatibleBitmap( 
	const CdDcdSizeXy& aCdDcdSizeXy , HDC hDc ) 
{
	m_hDc = NULL ;
	m_hBitmap = NULL ;
	m_hBitmapSid = NULL ;
	resetSize( aCdDcdSizeXy , hDc ) ;
}
CDcdTargetCompatibleBitmap::CDcdTargetCompatibleBitmap() 
{
	m_hDc = NULL ;
	m_hBitmap = NULL ;
	m_hBitmapSid = NULL ;
}

CDcdTargetCompatibleBitmap::~CDcdTargetCompatibleBitmap() 
{
	resetSize( CdDcdSizeXy( 0 , 0 )  , NULL ) ;
}
	
	
// ********************************
//	IfDcdTarget
// ********************************
HDC	CDcdTargetCompatibleBitmap::getHdc() 
{
	return ( m_hDc ) ;
}

CdDcdZoneXy CDcdTargetCompatibleBitmap::getZone() 
{
	return ( CdDcdZoneXy( CdDcdPosXy( 0 , 0 ) , m_CdDcdSizeXy ) ) ;
}
	
CdDcdZoneXy CDcdTargetCompatibleBitmap::getDrawableZone() 
{
	return ( CdDcdZoneXy( CdDcdPosXy( 0 , 0 ) , m_CdDcdSizeXy ) ) ;
}


Ou<CGdiHFontHolder>	CDcdTargetCompatibleBitmap::createGdiHFontHolder(  const CdFontProp& aCdFontProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHFontHolder( aCdFontProp , m_hDc ) ;
}
	
Ou<CGdiHPenHolder> CDcdTargetCompatibleBitmap::createGdiHPenHolder(  const CdPenProp& aCdPenProp )
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHPenHolder( aCdPenProp  ) ;
}

Ou<CGdiHBrushHolder> CDcdTargetCompatibleBitmap::createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHBrushHolder( aCdBrushProp  ) ;
}

// ********************************
//	CDcdTargetCompatibleBitmap
// ********************************
CdDcdSizeXy CDcdTargetCompatibleBitmap::getSize() 
{
	return ( m_CdDcdSizeXy ) ;
}
	
int CDcdTargetCompatibleBitmap::resetSize( 
		const CdDcdSizeXy& aCdDcdSizeXy , HDC hDc ) 
{
	int	iRv = 0 ;
	// ********************************
	//	既存のDC・BITMAPを破棄
	// ********************************
	if ( iRv == 0 ){
		m_CdDcdSizeXy.setX( 0 ).setY( 0 ) ;

		if ( m_hBitmapSid != NULL ){
			SelectObject( m_hDc , m_hBitmapSid ) ;
			m_hBitmapSid = NULL ;
		}	
		if ( m_hBitmap != NULL ){
			DeleteObject( m_hBitmap ) ;
			m_hBitmap = NULL ;
		}
		if ( m_hDc != NULL ){
			DeleteDC( m_hDc ) ;
			m_hDc = NULL ;
		}
	}
	// ********************************
	//	新しいDC・BITMAPを作成
	// ********************************
	if ( aCdDcdSizeXy.getX() > 0 && aCdDcdSizeXy.getY() > 0 ){
		bool	bhDcDeleteObligatory = false ;
		if ( hDc == NULL ){
			hDc = GetDC( NULL ) ;
			bhDcDeleteObligatory = true ;
		}

		if ( iRv == 0 ){
			m_hDc = CreateCompatibleDC( hDc ) ;
			if ( m_hDc == NULL ){
				iRv = -1 ;	//	DCの作成に失敗しました
			}
		}	
		if ( iRv == 0 ){
			m_hBitmap = CreateCompatibleBitmap( hDc , aCdDcdSizeXy.getX() , aCdDcdSizeXy.getY() ) ;
			if ( m_hBitmap == NULL ){
				iRv = -2 ;	//	BITMAPの作成に失敗しました
			}
			
		}
		if ( iRv == 0 ){
			m_hBitmapSid = (HBITMAP)SelectObject( m_hDc , m_hBitmap ) ;
		}
		if ( iRv == 0 ){
			m_CdDcdSizeXy = aCdDcdSizeXy ;
		}	
		// --------------------------------
		if ( bhDcDeleteObligatory ){
			ReleaseDC( NULL , hDc ) ;
			hDc = NULL ;
		}
	}	
	
	return ( iRv ) ;
}

} //namespace DcDraw
} //namespace DcDrawLib





