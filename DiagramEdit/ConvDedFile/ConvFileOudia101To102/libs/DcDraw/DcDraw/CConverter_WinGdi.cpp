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
//	CConverter_WinGdi.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include <string.h>
#include <tchar.h>
#include "CConverter_WinGdi.h"
#include "CDcDeviceUnitSizeY.h"
#include "CdDrawTextFormat2.h"
#include "DcdCd\DcDrawProp\CdDrawTextProp.h"
#include "DcdCd\DcDrawProp\CdColorProp.h"
#include "Ou/OuNew.h"

using namespace std ;

// ****************************************************************
//	CConverter_WinGdi
// ****************************************************************
	// ********************************
	//	@name 座標を扱う関数群
	// ********************************
void CConverter_WinGdi::toCdDcdPosXy( const POINT& aPOINT , CdDcdPosXy* pCdDcdPosXy ) 
{
	pCdDcdPosXy->setX( aPOINT.x ) ;
	pCdDcdPosXy->setY( aPOINT.y ) ;
}

void CConverter_WinGdi::toPOINT( const CdDcdPosXy& aCdDcdPosXy , POINT* pPOINT ) 
{
	pPOINT->x = aCdDcdPosXy.getX() ;
	pPOINT->y = aCdDcdPosXy.getY() ;
}
	
void CConverter_WinGdi::toCdDcdZoneXy( const RECT& aRECT , CdDcdZoneXy* pCdDcdZoneXy ) 
{
	pCdDcdZoneXy->setX( CdDcdZone( aRECT.left , aRECT.right - aRECT.left ) ) ;
	pCdDcdZoneXy->setY( CdDcdZone( aRECT.top , aRECT.bottom - aRECT.top ) ) ;
}	

void CConverter_WinGdi::toRECT( const CdDcdZoneXy& aCdDcdZoneXy , RECT* pRECT ) 
{
	pRECT->left = aCdDcdZoneXy.getX().getPos() ;
	pRECT->right = aCdDcdZoneXy.getX().getEndPos() ;
	pRECT->top = aCdDcdZoneXy.getY().getPos() ;
	pRECT->bottom = aCdDcdZoneXy.getY().getEndPos() ;
}

	// ********************************
	//	@name Colorを扱う関数群
	// ********************************
CdColorProp CConverter_WinGdi::CdColorPropOf( COLORREF value )const
{
	return CdColorProp( GetRValue( value ) , GetGValue( value ) , GetBValue( value ) ) ;
}

COLORREF CConverter_WinGdi::COLORREFOf( const CdColorProp& value )const
{
	return RGB( value.getRed() , value.getGreen() , value.getBlue() ) ;
}
CdColorProp CConverter_WinGdi::CdColorPropOfSysColor( int nIndex ) 
{
	return CdColorPropOf( GetSysColor( nIndex ) ) ;
}

// ********************************
//	Font
// ********************************
void CConverter_WinGdi::toLOGFONT( const CdFontProp& aCdFontProp , 
			LOGFONT*	pLOGFONT ,
			HDC hDc  ) 
{
	memset( pLOGFONT , 0 , sizeof(*pLOGFONT) ) ;
	
	// --------------------------------
	//	高さの属性(pLOGFONT->lfHeight)を設定
	// --------------------------------
	if ( aCdFontProp.getPointTextHeight() > 0 )
	{
		//	フォントの高さがポイント単位で指定されている場合

		HDC	hDcReleaseObligatory = NULL ;
		if ( hDc == NULL ){
			hDcReleaseObligatory = GetDC( NULL ) ;
			hDc = hDcReleaseObligatory ;
		}
		//hDc = ポイント単位からデバイス単位に変換するためのDC。
		//	引数でDCが指定されていなかった場合は、
		//	スクリーンDCとなります。

		// --------------------------------	
		int iDp = CDcDeviceUnitSizeY( hDc ).
						setPointSize( aCdFontProp.getPointTextHeight() ).
						getDeviceUnitSize() ;
		//iDp=ポイント単位の高さを、デバイス単位に変換しました。

		CdDcdSizeXy aSize = CConverter_WinGdi().DPtoLP( CdDcdSizeXy( 0 , iDp ) ,hDc ) ;
		//aSize.Y =デバイス単位の高さを、論理単位にしました。

		pLOGFONT->lfHeight = -abs( aSize.getY() ) ;
		//テキストの高さとして、論理単位の高さを指定。

		// --------------------------------		
		if ( hDcReleaseObligatory != NULL ){
			ReleaseDC( NULL , hDcReleaseObligatory ) ;
			hDcReleaseObligatory = NULL ;
		}
	}
	else if ( aCdFontProp.getLogicalunitTextHeight() > 0 )
	{
		pLOGFONT->lfHeight = -aCdFontProp.getLogicalunitTextHeight() ;
	}
	else
	{
		pLOGFONT->lfHeight = aCdFontProp.getLogicalunitCellHeight() ;
	}

	// --------------------------------
	//	高さ以外の属性を設定
	// --------------------------------
//note
//	lfCharSet = SHIFTJIS_CHARSET としてフォントを生成すると、
//	生成されるフォントは、日本語の表示できるフォントに限定されます。
//	pLOGFONT->lfCharSet = SHIFTJIS_CHARSET;

	pLOGFONT->lfCharSet = DEFAULT_CHARSET;

	if ( aCdFontProp.getFacename().empty() )
	{
		_tcscpy( pLOGFONT->lfFaceName , 
			CdFontPropOf( DEFAULT_GUI_FONT ) .getFacename().c_str() ) ;
	}
	else
	{
		_tcscpy( pLOGFONT->lfFaceName , aCdFontProp.getFacename().c_str() ) ;
	}

	if ( aCdFontProp.getBold() )
	{
		pLOGFONT->lfWeight = FW_BOLD ;
	}
	if ( aCdFontProp.getItaric() )
	{
		pLOGFONT->lfItalic = TRUE ;
	}
	if ( aCdFontProp.getUnderline() )
	{
		pLOGFONT->lfUnderline = TRUE ;
	}
	if ( aCdFontProp.getStrikeOut() )
	{
		pLOGFONT->lfStrikeOut = TRUE ;
	}
	//	角度を指定
	pLOGFONT->lfEscapement = aCdFontProp.getEscapement() ;
}

void CConverter_WinGdi::toCdFontProp( 
			const LOGFONT&	aLOGFONT ,
			CdFontProp* pCdFontProp ) 
{
	*pCdFontProp = CdFontProp() ;	
	
	if ( aLOGFONT.lfHeight >= 0 ) {
		pCdFontProp->setLogicalunitCellHeight( aLOGFONT.lfHeight ) ;
	}	else if ( aLOGFONT.lfHeight < 0 ){
		pCdFontProp->setLogicalunitTextHeight( - aLOGFONT.lfHeight ) ;
	}
	if ( aLOGFONT.lfFaceName[0] != '\0' ){
		pCdFontProp->setFacename( aLOGFONT.lfFaceName ) ;
	}
	if ( aLOGFONT.lfWeight >= FW_BOLD ){
		pCdFontProp->setBold( true ) ;
	}
	if ( aLOGFONT.lfItalic ){
		pCdFontProp->setItaric( true ) ;
	}
	if ( aLOGFONT.lfUnderline ){
		pCdFontProp->setUnderline( true ) ;
	}
	if ( aLOGFONT.lfStrikeOut ){
		pCdFontProp->setStrikeOut( true ) ;
	}
	pCdFontProp->setEscapement( aLOGFONT.lfEscapement ) ;
}

void CConverter_WinGdi::toCdFontProp( 
			int fnObject ,
			CdFontProp* pCdFontProp ) 
{
	int	iRv = 0 ;
	
	HFONT	hFont = NULL ;
	if ( iRv >= 0 ){
		hFont = (HFONT)GetStockObject( fnObject ) ;
		if ( hFont == NULL ){
			iRv = -1 ;	//	fnObjectは不正です
		}
	} 
	LOGFONT	aLOGFONT ;
	if ( iRv >= 0 ){
		int iResult = GetObject( hFont , sizeof(aLOGFONT) , &aLOGFONT ) ;
		if ( iResult == 0 ){
			iRv = -2 ;	//	GetObjectに失敗
		}
	}
	if ( iRv >= 0 ){
		toCdFontProp( aLOGFONT , pCdFontProp ) ;
	}
}

HFONT	CConverter_WinGdi::CreateFont(  const CdFontProp& aCdFontProp , 
			HDC hDc ) 
{
	HFONT	hRv = NULL ;
	LOGFONT	aLOGFONT ;
	toLOGFONT( aCdFontProp , &aLOGFONT , hDc ) ;
	hRv = CreateFontIndirect( &aLOGFONT ) ;
	return ( hRv ) ;
}

Ou<CGdiHFontHolder>	CConverter_WinGdi::createGdiHFontHolder( 
		const CdFontProp& aCdFontProp , 
		HDC hDc ) 
{
	Ou<CGdiHFontHolder>	pHolder ;
	HFONT	hFont = CreateFont( aCdFontProp , hDc ) ;
	if ( hFont != NULL )
	{
		pHolder = OuNew<CGdiHFontHolder>( new CGdiHFontHolder( 
			aCdFontProp , hFont	) ) ;
	}
	return pHolder ;
}

CdDcdSizeXy	CConverter_WinGdi::DrawtextCalcrect( 
		const tstring& strExtent ,
		int iLinesExtent ,
		const CdDrawTextProp& aCdDrawTextProp , 
		HDC hDc  )
{
	int		iRv = 0 ;
	bool	bRv = false ;
	CConverter_WinGdi	aConverter ;
	CdDcdSizeXy	aCdDcdSizeXy ;
	// --------------------------------
	HDC	hDcReleaseObligatory = NULL ;
	if ( hDc == NULL ){
		hDcReleaseObligatory = GetDC( NULL ) ;
		hDc = hDcReleaseObligatory ;
	}

	// --------------------------------
	//	フォントの生成
	// --------------------------------
	HFONT	hFont = NULL ;
	if ( iRv >= 0 ){
		hFont = aConverter.CreateFont( aCdDrawTextProp.getCdFontProp() , 
									hDc ) ;
		if ( hFont == NULL ){
			iRv = -1 ;	//	フォントの作成に失敗しました。
		}
	}
	//--------------------------------
	//	GDIオブジェクトの選択
	//--------------------------------
	bool	bSelectTool = false ;
	COLORREF	colorrefLTextSid = 0xffffffff;
	COLORREF	colorrefLBackSid = 0xffffffff;
	HFONT		hFontSid = NULL ;

	if ( iRv >= 0 ){
		bSelectTool = true ;
		hFontSid = (HFONT)SelectObject( hDc , hFont ) ;

		colorrefLTextSid = SetTextColor( hDc , 
							COLORREFOf(	aCdDrawTextProp.getTextColor() ) ) ;
		colorrefLBackSid = SetBkColor( hDc , 	
							COLORREFOf(	aCdDrawTextProp.getBackColor() ) ) ;
	
	}
	
	if ( iRv >= 0 ){
		//--------------------------------
		//	テキストの横幅の計算
		//--------------------------------
		{
			tstring	strLs ;
			strLs += strExtent ;
			CdDrawTextFormat2	aFlag( aCdDrawTextProp.getCdDrawTextFormat() ) ;
			aFlag.setCalcrect( CdDrawTextFormat2::CALCRECT )
				.setVertical( CdDrawTextFormat::V_SINGLELINT_TOP )
				.setEllipses( CdDrawTextFormat::NOELLIPSIS )  ;
			//aFlag = 指定のフォーマットを単一行・
			//	省略記号なし・サイズ計算に修正しました

			RECT	aRect ;
			memset( &aRect , 0 , sizeof(aRect) ) ;
			DrawText( hDc , 
					strLs.c_str() , -1 , &aRect , aFlag ) ;
				//LRect.right = テキスト m_strExtent の幅
			aCdDcdSizeXy.setX( aRect.right - aRect.left ) ;
		}
		//--------------------------------
		//	テキストの高さの計算
		//--------------------------------
		{
			tstring	strLs ;
			int	iLi ;
			for ( iLi = 0 ; iLi < iLinesExtent ; iLi ++ ){
				if ( iLi > 0 ){
					strLs += TEXT( '\n' ) ;
				}
				strLs += strExtent.c_str() ;
			}
				//strLs = m_strExtentを指定の行数分だけ縦に並べた文字列
			
			CdDrawTextFormat2	aFlag( aCdDrawTextProp.getCdDrawTextFormat() ) ;
			aFlag.setCalcrect( CdDrawTextFormat2::CALCRECT )
				.setVertical( CdDrawTextFormat::V_MULTILINE )
				.setEllipses( CdDrawTextFormat::NOELLIPSIS )  ;
			//aFlag = 指定のフォーマットを複数行・
			//	省略記号なし・サイズ計算に修正しました

			RECT	aRect ;
			memset( &aRect , 0 , sizeof(aRect) ) ;
			DrawText( hDc , 
				strLs.c_str() , -1 , &aRect , aFlag ) ;
			//LRect.bottom = テキスト m_strExtent の高さ
			
			aCdDcdSizeXy.setY( aRect.bottom - aRect.top ) ;
		}		
	}
	//--------------------------------
	if ( bSelectTool ){

		SetTextColor( hDc , colorrefLTextSid ) ;
		colorrefLTextSid = 0xffffffff ;
		SetBkColor( hDc , colorrefLBackSid ) ;
		colorrefLBackSid = 0xffffffff;

		SelectObject( hDc , hFontSid ) ;
		hFontSid = NULL ;
	}
	if ( hFont != NULL ){
		DeleteObject( hFont ) ;
		hFont = NULL ;
	}
	// --------------------------------		
	if ( hDcReleaseObligatory != NULL ){
		ReleaseDC( NULL , hDcReleaseObligatory ) ;
		hDcReleaseObligatory = NULL ;
	}
	return ( aCdDcdSizeXy ) ;	
} 

// ********************************
//	Pen
// ********************************

const struct
{
	CdPenProp::EStyle	eStyle ;
	UINT	lopnStyle ;
}	g_arStyle[] = {
	{ CdPenProp::DASH   			, PS_DASH	} , 
	{ CdPenProp::DOT 				, PS_DOT 	} , 
	{ CdPenProp::DASHDOT 			, PS_DASHDOT } , 
	{ CdPenProp::DASHDOTDOT			, PS_DASHDOTDOT } , 
	{ CdPenProp::NULLPEN 			, PS_NULL } , 
	{ CdPenProp::SOLID_INSIDEFRAME	, PS_INSIDEFRAME } , 
	{ CdPenProp::SOLID				, PS_SOLID	} ,		//	default
};



void CConverter_WinGdi::toLOGPEN( const CdPenProp& aCdPenProp , 
		LOGPEN*	pLogPen ) 
{
	int idx ;
	for ( idx = 0 ; 
		idx < sizeof(g_arStyle) / sizeof(g_arStyle[0]) - 1 &&	
			g_arStyle[idx].eStyle != aCdPenProp.getStyle() ;
		idx ++ ){} ;
	pLogPen->lopnStyle = g_arStyle[idx].lopnStyle ;

	pLogPen->lopnWidth.x = aCdPenProp.getLogicalunitWidth() ;
	pLogPen->lopnWidth.y = 0 ;
	pLogPen->lopnColor = COLORREFOf( aCdPenProp.getColor() );
}



void CConverter_WinGdi::toCdPenProp( 
		const LOGPEN&	aLOGPEN ,
		CdPenProp* pCdPenProp ) 
{
	int idx ;
	for ( idx = 0 ; 
		idx < sizeof(g_arStyle) / sizeof(g_arStyle[0]) - 1 &&	
			g_arStyle[idx].lopnStyle != aLOGPEN.lopnStyle ;
		idx ++ ){} ;
	pCdPenProp->setStyle( g_arStyle[idx].eStyle ) ;
	if ( aLOGPEN.lopnWidth.x > 0 ){
		pCdPenProp->setLogicalunitWidth( aLOGPEN.lopnWidth.x ) ;
	}	else	{
		pCdPenProp->setIsDevicewidth1( true ) ;
	}
	pCdPenProp->setColor( CdColorPropOf( aLOGPEN.lopnColor ) ) ;
}


void CConverter_WinGdi::toCdPenProp( 
		int fnObject ,
		CdPenProp* pCdPenProp ) 
{
	int	iRv = 0 ;
	
	HGDIOBJ	hGdiobj = NULL ;
	if ( iRv >= 0 ){
		hGdiobj = GetStockObject( fnObject ) ;
		if ( hGdiobj == NULL ){
			iRv = -1 ;	//	fnObjectは不正です
		}
	} 
	LOGPEN	aStruct ;
	if ( iRv >= 0 ){
		int iResult = GetObject( hGdiobj , sizeof(aStruct) , &aStruct ) ;
		if ( iResult == 0 ){
			iRv = -2 ;	//	GetObjectに失敗
		}
	}
	if ( iRv >= 0 ){
		toCdPenProp( aStruct , pCdPenProp ) ;
	}
}

HPEN CConverter_WinGdi::CreatePen(  const CdPenProp& aCdPenProp ) 
{
	HPEN	hRv = NULL ;
	LOGPEN	aLOGPEN ;
	toLOGPEN( aCdPenProp , &aLOGPEN ) ;
	hRv = CreatePenIndirect( &aLOGPEN ) ;
	return ( hRv ) ;
}

Ou<CGdiHPenHolder> CConverter_WinGdi::createGdiHPenHolder(  const CdPenProp& aCdPenProp ) 
{
	Ou<CGdiHPenHolder>	pHolder ;
	HPEN	hPen = CreatePen( aCdPenProp  ) ;
	if ( hPen != NULL )
	{
		pHolder = OuNew<CGdiHPenHolder>( new CGdiHPenHolder( 
			aCdPenProp , hPen	) ) ;
	}
	return pHolder ;
}



// ********************************
///	@name Brushを扱う関数群
// ********************************
const struct
{
	CdBrushProp::EStyle	eStyle ;
	UINT	lbStyle ;
	LONG	lbHatch ;
}	g_arBrushStyle[] = {
	{ CdBrushProp::HATCHED_BDIAGONAL ,	BS_HATCHED , 	HS_BDIAGONAL } ,
	{ CdBrushProp::HATCHED_CROSS ,		BS_HATCHED , 	HS_CROSS } ,
	{ CdBrushProp::HATCHED_DIAGCROSS ,	BS_HATCHED , 	HS_DIAGCROSS } ,
	{ CdBrushProp::HATCHED_FDIAGONAL ,	BS_HATCHED , 	HS_FDIAGONAL } ,
	{ CdBrushProp::HATCHED_HORIZONTAL ,	BS_HATCHED , 	HS_HORIZONTAL } ,
	{ CdBrushProp::HATCHED_VERTICAL ,	BS_HATCHED , 	HS_VERTICAL } ,
	{ CdBrushProp::NULLBRUSH ,			BS_NULL , 	0 } ,
	{ CdBrushProp::SOLID ,				BS_SOLID , 		0 } ,
};

void CConverter_WinGdi::toLOGBRUSH( const CdBrushProp& aCdBrushProp , 
			LOGBRUSH*	pLogbrush ) 
{
	int idx ;
	for ( idx = 0 ; 
		idx < sizeof(g_arBrushStyle) / sizeof(g_arBrushStyle[0]) - 1 &&	
			g_arBrushStyle[idx].eStyle != aCdBrushProp.getStyle() ;
		idx ++ ){} ;
	pLogbrush->lbStyle = g_arBrushStyle[idx].lbStyle ;
	pLogbrush->lbHatch = g_arBrushStyle[idx].lbHatch ;
	pLogbrush->lbColor = COLORREFOf( aCdBrushProp.getColor() );
}

void CConverter_WinGdi::toCdBrushProp( 
			const LOGBRUSH&	aLOGBRUSH ,
			CdBrushProp* pCdBrushProp ) 
{
	int idx ;
	for ( idx = 0 ; 
		idx < sizeof(g_arBrushStyle) / sizeof(g_arBrushStyle[0]) - 1 &&	
			!( g_arBrushStyle[idx].lbStyle == aLOGBRUSH.lbStyle
			&& g_arBrushStyle[idx].lbHatch == aLOGBRUSH.lbHatch ) 
		; idx ++ ){} ;
	pCdBrushProp->setStyle( g_arBrushStyle[idx].eStyle ) ;
	pCdBrushProp->setColor( CdColorPropOf( aLOGBRUSH.lbColor ) ) ;
}

void CConverter_WinGdi::toCdBrushProp( 
			int fnObject ,
			CdBrushProp* pCdBrushProp ) 
{
	int	iRv = 0 ;
	
	HGDIOBJ	hGdiobj = NULL ;
	if ( iRv >= 0 ){
		hGdiobj = GetStockObject( fnObject ) ;
		if ( hGdiobj == NULL ){
			iRv = -1 ;	//	fnObjectは不正です
		}
	} 
	LOGBRUSH	aStruct ;
	if ( iRv >= 0 ){
		int iResult = GetObject( hGdiobj , sizeof(aStruct) , &aStruct ) ;
		if ( iResult == 0 ){
			iRv = -2 ;	//	GetObjectに失敗
		}
	}
	if ( iRv >= 0 ){
		toCdBrushProp( aStruct , pCdBrushProp ) ;
	}
}

HBRUSH CConverter_WinGdi::CreateBrush(  const CdBrushProp& aCdBrushProp ) 
{
	HBRUSH	hRv = NULL ;
	LOGBRUSH	aLOGBRUSH ;
	toLOGBRUSH( aCdBrushProp , &aLOGBRUSH ) ;
	hRv = CreateBrushIndirect( &aLOGBRUSH ) ;
	return ( hRv ) ;
}
Ou<CGdiHBrushHolder> CConverter_WinGdi::createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) 
{
	Ou<CGdiHBrushHolder>	pHolder ;
	HBRUSH	hBrush = CreateBrush( aCdBrushProp ) ;
	if ( hBrush != NULL )
	{
		pHolder = OuNew<CGdiHBrushHolder>( new CGdiHBrushHolder( 
			aCdBrushProp , hBrush	) ) ;
	}
	return pHolder ;
}


	// ********************************
	//@name	論理座標とデバイス座標の変換	
	// ********************************
	///@{
CdDcdPosXy CConverter_WinGdi::DPtoLP( const CdDcdPosXy& value , HDC hDc )
{
	POINT	aPoint[1] ;
	aPoint[0].x = value.getX() ;
	aPoint[0].y = value.getY() ;
	::DPtoLP( hDc , aPoint , sizeof(aPoint) / sizeof(aPoint[0]) ) ;
	return CdDcdPosXy( aPoint[0].x , aPoint[0].y ) ;
}

CdDcdPosXy CConverter_WinGdi::LPtoDP( const CdDcdPosXy& value , HDC hDc ) 
{
	POINT	aPoint[1] ;
	aPoint[0].x = value.getX() ;
	aPoint[0].y = value.getY() ;
	::LPtoDP( hDc , aPoint , sizeof(aPoint) / sizeof(aPoint[0]) ) ;
	return CdDcdPosXy( aPoint[0].x , aPoint[0].y ) ;
}

CdDcdSizeXy CConverter_WinGdi::DPtoLP( const CdDcdSizeXy& value , HDC hDc ) 
{
	POINT	aPoint[2] ;
	aPoint[0].x = 0 ;
	aPoint[0].y = 0 ;
	aPoint[1].x = value.getX() ;
	aPoint[1].y = value.getY() ;
	::DPtoLP( hDc , aPoint , sizeof(aPoint) / sizeof(aPoint[0]) ) ;
	return CdDcdSizeXy( abs( aPoint[1].x - aPoint[0].x ) , 
		abs( aPoint[1].y - aPoint[0].y ) ) ;
}

CdDcdSizeXy CConverter_WinGdi::LPtoDP( const CdDcdSizeXy& value , HDC hDc ) 
{
	POINT	aPoint[2] ;
	aPoint[0].x = 0 ;
	aPoint[0].y = 0 ;
	aPoint[1].x = value.getX() ;
	aPoint[1].y = value.getY() ;
	::LPtoDP( hDc , aPoint , sizeof(aPoint) / sizeof(aPoint[0]) ) ;
	return CdDcdSizeXy( abs( aPoint[1].x - aPoint[0].x ) , 
		abs( aPoint[1].y - aPoint[0].y ) ) ;
}


CdDcdZoneXy CConverter_WinGdi::DPtoLP( const CdDcdZoneXy& value , HDC hDc ) 
{
	POINT	aPoint[2] ;
	aPoint[0].x = value.getX().getPos() ;
	aPoint[0].y = value.getY().getPos() ;
	aPoint[1].x = value.getX().getEndPos() ;
	aPoint[1].y = value.getY().getEndPos() ;
	::DPtoLP( hDc , aPoint , sizeof(aPoint) / sizeof(aPoint[0]) ) ;
	return CdDcdZoneXy( CdDcdZone( aPoint[0].x , aPoint[1].x - aPoint[0].x ) ,
		CdDcdZone( aPoint[0].y , aPoint[1].y - aPoint[0].y ) ) ;
}

CdDcdZoneXy CConverter_WinGdi::LPtoDP( const CdDcdZoneXy& value , HDC hDc ) 
{
	POINT	aPoint[2] ;
	aPoint[0].x = value.getX().getPos() ;
	aPoint[0].y = value.getY().getPos() ;
	aPoint[1].x = value.getX().getEndPos() ;
	aPoint[1].y = value.getY().getEndPos() ;
	::LPtoDP( hDc , aPoint , sizeof(aPoint) / sizeof(aPoint[0]) ) ;
	return CdDcdZoneXy( CdDcdZone( aPoint[0].x , aPoint[1].x - aPoint[0].x ) ,
		CdDcdZone( aPoint[0].y , aPoint[1].y - aPoint[0].y ) ) ;
}


// ****************************************************************
//	普通関数
// ****************************************************************
std::string	DeviceCapsToString( HDC hDc )
{
	std::string	strRv ;
	// --------------------------------
	//	TECHNOLOGY
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , TECHNOLOGY ) ;
		strRv = "TECHNOLOGY=" ;
		switch ( iValue ) {
		 case DT_PLOTTER :	//ベクタプロッタ 
			strRv += "DT_PLOTTER" ;
			break ;
		 case DT_RASDISPLAY :	//ラスタディスプレイ 
			strRv += "DT_RASDISPLAY" ;
			break ;
		 case DT_RASPRINTER :	//ラスタプリンタ 
			strRv += "DT_RASPRINTER" ;
			break ;
		 case DT_RASCAMERA :	//ラスタカメラ 
			strRv += "DT_RASCAMERA" ;
			break ;
		 case DT_CHARSTREAM :	//文字ストリーム 
			strRv += "DT_CHARSTREAM" ;
			break ;
		 case DT_METAFILE :	//メタファイル 
			strRv += "DT_METAFILE" ;
			break ;
		 case DT_DISPFILE :	//ディスプレイファイル
			strRv += "DT_DISPFILE" ;
			break ;
		} 
		strRv += "\n" ;
	}
	// --------------------------------
	//	HORZSIZE
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , HORZSIZE ) ;
		char	szLs[32] ;
		sprintf( szLs , "HORZSIZE=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	// --------------------------------
	//	VERTSIZE
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , VERTSIZE ) ;
		char	szLs[32] ;
		sprintf( szLs , "VERTSIZE=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	// --------------------------------
	//	HORZRES
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , HORZRES ) ;
		char	szLs[32] ;
		sprintf( szLs , "HORZRES=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	// --------------------------------
	//	VERTRES
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , VERTRES ) ;
		char	szLs[32] ;
		sprintf( szLs , "VERTRES=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	// --------------------------------
	//	LOGPIXELSX
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , LOGPIXELSX ) ;
		char	szLs[32] ;
		sprintf( szLs , "LOGPIXELSX=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	// --------------------------------
	//	LOGPIXELSY
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , LOGPIXELSY ) ;
		char	szLs[32] ;
		sprintf( szLs , "LOGPIXELSY=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	// --------------------------------
	//	PHYSICALWIDTH
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , PHYSICALWIDTH ) ;
		char	szLs[32] ;
		sprintf( szLs , "PHYSICALWIDTH=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	// --------------------------------
	//	PHYSICALHEIGHT
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , PHYSICALHEIGHT ) ;
		char	szLs[32] ;
		sprintf( szLs , "PHYSICALHEIGHT=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	// --------------------------------
	//	PHYSICALOFFSETX
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , PHYSICALOFFSETX ) ;
		char	szLs[32] ;
		sprintf( szLs , "PHYSICALOFFSETX=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	// --------------------------------
	//	PHYSICALOFFSETY
	// --------------------------------
	{
		int iValue = GetDeviceCaps( hDc , PHYSICALOFFSETY ) ;
		char	szLs[32] ;
		sprintf( szLs , "PHYSICALOFFSETY=%d\n" , iValue ) ;
		strRv += szLs ;
	}
	return ( strRv ) ;
}


