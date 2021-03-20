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
//	CDcdText.cpp
// ****************************************************************
*/
#include "./CDcdText.h"
#include "./CConverter_WinGdi.h"
#include "./CdDrawTextFormat2.h"
// ****************************************************************
//	CDcdText
// ****************************************************************
CDcdText::CDcdText( 
		const tstring&			strText,
		const CdDrawTextProp&	aCdDrawTextProp = CdDrawTextProp() ,
		const tstring&			strExtent ,
		int						iLinesExtent
	) :
	m_strText( strText ) ,
	m_CdDrawTextProp( aCdDrawTextProp ) ,
	m_strExtent( strExtent ) ,
	m_iLinesExtent( iLinesExtent ) 
{
	if ( m_CdDrawTextProp.getCdFontProp().getPointTextHeight() == 0 && 
		m_CdDrawTextProp.getCdFontProp().getLogicalunitTextHeight() == 0 && 
		m_CdDrawTextProp.getCdFontProp().getLogicalunitCellHeight() == 0 ){
		m_CdDrawTextProp.setCdFontProp( 
			CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
	}
}

	
CDcdText::CDcdText() :
	m_iLinesExtent( 1 ) 
{
}
	
CDcdText::~CDcdText() 
{
}
	
// ********************************
//	IfDcDraw
// ********************************
bool CDcdText::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	int		iRv = 0 ;
	bool	bRv = false ;
	
	// --------------------------------
	//	フォントの生成
	// --------------------------------

	HFONT	hFont = NULL ;

	if ( iRv >= 0 && hFont == NULL ){
		hFont = pIfDcdTarget->CreateFont( m_CdDrawTextProp.getCdFontProp() ) ;

		if ( hFont == NULL ){
			iRv = -1 ;	//	フォントの作成に失敗しました。	\n
		}
	}
	// --------------------------------
	bool	bSelectTool = false ;
	COLORREF	colorrefLTextSid = 0xffffffff;
	COLORREF	colorrefLBackSid = 0xffffffff;
	int			iLBkModeSid = -1 ;
	HFONT		hFontSid = NULL ;
	if ( iRv >= 0 ){
		bSelectTool = true ;
		hFontSid = (HFONT)SelectObject( pIfDcdTarget->getHdc() , hFont ) ;

		CConverter_WinGdi	aConv ;
		colorrefLTextSid = SetTextColor( 
			pIfDcdTarget->getHdc() , 
			aConv.COLORREFOf( m_CdDrawTextProp.getTextColor() ) ) ;
		colorrefLBackSid = SetBkColor( 
			pIfDcdTarget->getHdc() , 	
			aConv.COLORREFOf( m_CdDrawTextProp.getBackColor() ) ) ;
		int	iLBkMode = TRANSPARENT ;
		if ( m_CdDrawTextProp.getIsOpaque() ){
			iLBkMode = OPAQUE ;
		}
		iLBkModeSid = SetBkMode( pIfDcdTarget->getHdc() , iLBkMode ) ;
	}
	
	if ( iRv >= 0 ){
		RECT	aRect ;
		aRect.left = pIfDcdTarget->getZone().getX().getPos() ;
		aRect.right = pIfDcdTarget->getZone().getX().getEndPos() ;
		aRect.top = pIfDcdTarget->getZone().getY().getPos() ;
		aRect.bottom = pIfDcdTarget->getZone().getY().getEndPos() ;
		DrawText( pIfDcdTarget->getHdc() , m_strText.c_str() , -1 
				, &aRect , m_CdDrawTextProp.getCdDrawTextFormat() ) ;
		bRv = true ;
	}
	//--------------------------------
	if ( bSelectTool ){
		SetBkMode( pIfDcdTarget->getHdc() , iLBkModeSid  ) ;
		iLBkModeSid = -1 ;
		SetTextColor( pIfDcdTarget->getHdc() , colorrefLTextSid ) ;
		colorrefLTextSid = 0xffffffff ;
		SetBkColor( pIfDcdTarget->getHdc() , colorrefLBackSid ) ;
		colorrefLBackSid = 0xffffffff;
		SelectObject( pIfDcdTarget->getHdc() , hFontSid ) ;
		hFontSid = NULL ;
	}

	return ( bRv ) ;
}
	
bool CDcdText::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	int		iRv = 0 ;
	bool	bRv = false ;
	// --------------------------------
	//	フォントの生成
	// --------------------------------
	HFONT	hFont = NULL ;
	if ( iRv >= 0 ){
		hFont = pIfDcdTarget->CreateFont( m_CdDrawTextProp.getCdFontProp() ) ;
		if ( hFont == NULL ){
			iRv = -1 ;	//	フォントの作成に失敗しました。	\n
		}
	}
	//--------------------------------
	//	GDIオブジェクトの選択
	//--------------------------------
	bool	bSelectTool = false ;
	COLORREF	colorrefLTextSid = 0xffffffff;
	COLORREF	colorrefLBackSid = 0xffffffff;
	HFONT		hFontSid = NULL ;
	if ( iRv >= 0 )
	{
		bSelectTool = true ;
		hFontSid = (HFONT)SelectObject( pIfDcdTarget->getHdc() , hFont ) ;

		CConverter_WinGdi	aConv ;
		colorrefLTextSid = SetTextColor( 
			pIfDcdTarget->getHdc() , 
			aConv.COLORREFOf( m_CdDrawTextProp.getTextColor() ) ) ;
		colorrefLBackSid = SetBkColor( 
			pIfDcdTarget->getHdc() , 	
			aConv.COLORREFOf( m_CdDrawTextProp.getBackColor() ) ) ;
	}
	//--------------------------------
	
	string strExtent ;
	if ( iRv >= 0 ){
		strExtent = m_strExtent ;
		if ( strExtent.empty() ){
			strExtent = m_strText ;
		}
	}
	//strExtent = テキストの幅の計算の基準となる文字列。

	if ( iRv >= 0 ){
		//--------------------------------
		//	テキストの横幅の計算
		//--------------------------------
		{
			tstring	strLs ;
			strLs += strExtent ;
			CdDrawTextFormat2	aFlag( m_CdDrawTextProp.getCdDrawTextFormat() ) ;
			aFlag.setCalcrect( CdDrawTextFormat2::CALCRECT )
				.setVertical( CdDrawTextFormat::V_SINGLELINT_TOP )
				.setEllipses( CdDrawTextFormat::NOELLIPSIS )  ;
			//aFlag = 指定のフォーマットを単一行・
			//	省略記号なし・サイズ計算に修正しました

			RECT	aRect ;
			memset( &aRect , 0 , sizeof(aRect) ) ;
			DrawText(  pIfDcdTarget->getHdc() , 
					strLs.c_str() , -1 , &aRect , aFlag ) ;
				//LRect.right = テキスト m_strExtent の幅
			pCdDcdSizeXy->setX( aRect.right - aRect.left ) ;
		}
		//--------------------------------
		//	テキストの高さの計算
		//--------------------------------
		{
			tstring	strLs ;
			int	iLi ;
			for ( iLi = 0 ; iLi < m_iLinesExtent ; iLi ++ ){
				if ( iLi > 0 ){
					strLs += TEXT( '\n' ) ;
				}
				strLs += strExtent.c_str() ;
			}
				//strLs = m_strExtentを指定の行数分だけ縦に並べた文字列
			
			CdDrawTextFormat2	aFlag( m_CdDrawTextProp.getCdDrawTextFormat() ) ;
			aFlag.setCalcrect( CdDrawTextFormat2::CALCRECT )
				.setVertical( CdDrawTextFormat::V_MULTILINE )
				.setEllipses( CdDrawTextFormat::NOELLIPSIS )  ;
			//aFlag = 指定のフォーマットを複数行・
			//	省略記号なし・サイズ計算に修正しました

			RECT	aRect ;
			memset( &aRect , 0 , sizeof(aRect) ) ;
			DrawText( pIfDcdTarget->getHdc() , 
				strLs.c_str() , -1 , &aRect , aFlag ) ;
			//LRect.bottom = テキスト m_strExtent の高さ
			
			pCdDcdSizeXy->setY( aRect.bottom - aRect.top ) ;
		}		
	}
	//--------------------------------
	if ( bSelectTool ){
		SetTextColor( pIfDcdTarget->getHdc() , colorrefLTextSid ) ;
		colorrefLTextSid = 0xffffffff ;
		SetBkColor( pIfDcdTarget->getHdc() , colorrefLBackSid ) ;
		colorrefLBackSid = 0xffffffff;
		SelectObject( pIfDcdTarget->getHdc() , hFontSid ) ;
		hFontSid = NULL ;
	}
	return ( iRv >= 0 ) ;

}

