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
//	CDcdFillRectangleTextV.cpp
// ****************************************************************
*/
//#include "stdafx.h"

#include <deque>
using namespace std ;

#include "CDcdFillRectangleTextV.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/CConverter_WinGdi.h"
#include "str/CStrCharSizeMb.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

// ********************************
//	コンストラクタ
// ********************************
CDcdFillRectangleTextV::CDcdFillRectangleTextV( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp  ,
		int						iLinesExtentX  ,
		int						iLinesExtentY  ,
		COLORREF	colorrefText , 
		int						logicalunitFrameWidth   ,
		int						logicalunitFrameHeight   ,
		const CdPenProp&		aCdPenProp ,
		const CdBrushProp& 		aCdBrushProp ,
		const tstring&			strExtent )
	: m_CDcdFillrect( aCdBrushProp ) 
	, m_CDcdRectangle(  aCdPenProp ) 
	, m_CDcdText( "" , CdDrawTextProp( aCdFontProp , CConverter_WinGdi().CdColorPropOf( colorrefText ) ) , strExtent)
	, m_logicalunitFrameWidth( logicalunitFrameWidth )
	, m_logicalunitFrameHeight( logicalunitFrameHeight )
	, m_strText( strText ) 
	, m_iLinesExtentX( iLinesExtentX )
	, m_iLinesExtentY( iLinesExtentY ) 
{
	if ( m_CDcdText.getExtent().empty() ){
		m_CDcdText.setExtent( "国" ) ;
	}
}


CDcdFillRectangleTextV::CDcdFillRectangleTextV( 
		const CdPenProp&		aCdPenProp ,
		int						logicalunitFrameWidth ,
		int						logicalunitFrameHeight ,
		const tstring&			strText ,
		const CdFontProp&	aCdFontProp ,
		int						iLinesExtentX ,
		int						iLinesExtentY ,
		COLORREF	colorrefText , 
		const CdBrushProp& 		aCdBrushProp ,
		const tstring&			strExtent 
	) 
	: m_CDcdFillrect( aCdBrushProp ) 
	, m_CDcdRectangle(  aCdPenProp ) 
	, m_CDcdText( "" , CdDrawTextProp( aCdFontProp , CConverter_WinGdi().CdColorPropOf( colorrefText ) ) , strExtent)
	, m_logicalunitFrameWidth( logicalunitFrameWidth )
	, m_logicalunitFrameHeight( logicalunitFrameHeight )
	, m_strText( strText ) 
	, m_iLinesExtentX( iLinesExtentX )
	, m_iLinesExtentY( iLinesExtentY ) 
{
	if ( m_CDcdText.getExtent().empty() ){
		m_CDcdText.setExtent( "国" ) ;
	}
}

CDcdFillRectangleTextV::CDcdFillRectangleTextV() 
	: m_logicalunitFrameWidth( 0 )
	, m_logicalunitFrameHeight( 0 )
	, m_iLinesExtentX ( 1 ) 
	, m_iLinesExtentY( 1 ) 
{
	if ( m_CDcdText.getExtent().empty() ){
		m_CDcdText.setExtent( "国" ) ;
	}
}
	
CDcdFillRectangleTextV::~CDcdFillRectangleTextV() 
{
}
// ********************************
//	IfDcDraw
// ********************************
bool CDcdFillRectangleTextV::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool	bRv = false ;

	//	背景ブラシ
	{
		if ( m_CDcdFillrect.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}
	//	枠線
	{
		if ( m_CDcdRectangle.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}

	// --------------------------------
	//	テキスト
	// --------------------------------

	//	m_CDcdText は、上下左右中央寄せにします。
	//	これは、半角数字１文字を表示する際に、中央に表示するためです。
	{
		CdDrawTextProp	aCdDrawTextProp = m_CDcdText.getCdDrawTextProp() ;
		aCdDrawTextProp.setCdDrawTextFormat( 
			CdDrawTextFormat(
				 CdDrawTextFormat::H_CENTER , 
				CdDrawTextFormat::V_SINGLELINT_CENTER 
			) 
		) ;
		m_CDcdText.setCdDrawTextProp( aCdDrawTextProp ) ;
	}

	CdDcdZoneXy	aCdDcdZoneXy ;
	{
		aCdDcdZoneXy = pIfDcdTarget->getZone() ;
		aCdDcdZoneXy.setX( CdDcdZone( 
			aCdDcdZoneXy.getX().getPos() + m_logicalunitFrameWidth , 
			aCdDcdZoneXy.getX().getSize() - m_logicalunitFrameWidth * 2 )
			)  ;
		aCdDcdZoneXy.setY( CdDcdZone( 
			aCdDcdZoneXy.getY().getPos() + m_logicalunitFrameHeight , 
			aCdDcdZoneXy.getY().getSize() - m_logicalunitFrameHeight * 2 )
			)  ;
	}
	//aCdDcdZoneXy = テキストを描画する領域です。
	//	IfDcdTargetの領域から、上下左右の枠領域を除いた領域です。

	CdDcdSizeXy	sizeExtent ;
	{	
		bRv = m_CDcdText.getItemSize( pIfDcdTarget , &sizeExtent ) ;
		if ( !bRv ){
			return ( bRv ) ;
		}
		sizeExtent.setX( max( sizeExtent.getX() , sizeExtent.getY() ) ) ;
		sizeExtent.setY( sizeExtent.getX() ) ;
	}
	//sizeExtent = テキスト１文字あたりのサイズ。
	//	ただし、サイズは正方形になるように最適化します。
	//	つまり、X,Yのうち、大きい方の辺に合わせます。

	// ----------------------------------------------------------------
	//	縦書きフォントを生成
	// ----------------------------------------------------------------
	HFONT hfontVertical = NULL ;
	{
		CdFontProp	aCdFontPropV = m_CDcdText.getCdDrawTextProp().getCdFontProp() ;
		string strFacename = aCdFontPropV.getFacename() ;
		if ( !( strFacename.size() >= 1 && strFacename.substr( 0 , 1 ) == "@" ) ){
			strFacename = string( "@" ) + strFacename ;
		}
		aCdFontPropV.setFacename( strFacename ) ;
		aCdFontPropV.setIsEscapementVertical() ;
		hfontVertical = pIfDcdTarget->CreateFont( aCdFontPropV ) ;

		if ( hfontVertical != NULL ){
			string strFacenameSelected  ;
			{
				HFONT hfontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , hfontVertical ) ;
				int iLen = GetTextFace( pIfDcdTarget->getHdc() , 0 , NULL ) ;
				vector<TCHAR>	szFace( iLen + 1 ) ;
				GetTextFace( pIfDcdTarget->getHdc() , (int)szFace.size() , &szFace[0] ) ;
				strFacenameSelected = &szFace[0] ;
				if ( hfontOld != NULL ){
					SelectObject( pIfDcdTarget->getHdc() , hfontOld ) ;
					hfontOld = NULL ;
				}
			}
			//strFacenameSelected = 実際に作成されたフォントの
			//	タイプフェイス名。要求と異なる場合があります。

			if ( strFacenameSelected != aCdFontPropV.getFacename() ){
				hfontVertical = NULL ;
			}
		}
	}
	//hfontVertical = 縦書き用のフォント
	//	ただし、期待通りのフォントが生成できない
	//	（要求したフォントのタイプフェイス名と、
	//	実際に生成したフォントのタイプフェイス名が異なる）場合は
	//	NULL とします。
	//	この場合、縦書きフォントは使用しません。

	// ----------------------------------------------------------------
	//	縦書きフォントが使えない場合のため、
	//	一部の文字を変換（"ー" を "|"に）
	// ----------------------------------------------------------------
	string	strText = m_strText ;
	if ( hfontVertical == NULL ){
		//	"-","－","ｰ","ー" は、縦棒に変更します。 
		CStrCharSizeMb	aCStrCharSizeMb( strText ) ;
		int iBidx = 0 ;
		for ( iBidx = 0 ; iBidx < aCStrCharSizeMb.ByteLength() ;
				iBidx = aCStrCharSizeMb.BidxNextChar( iBidx ) ){
			string strChar = strText.substr( iBidx , aCStrCharSizeMb.CsizeOfBidx( iBidx ) ) ;
			if ( strChar == "-" || strChar == "－" ||
					strChar == "ｰ" || strChar == "ー" ){
				strText.erase( iBidx , aCStrCharSizeMb.CsizeOfBidx( iBidx ) ) ;
				strText.insert( iBidx , "|" ) ;
				aCStrCharSizeMb.scan( strText ) ;
			}
		}
	}
	//strText = 縦書きフォントが使えない場合は、
	//	一部の文字を変換（"ー" を "|"に）しました。

	// --------------------------------
	//	文字を描画するのに必要な
	//	全角ブロック数をカウント
	// --------------------------------
	deque<int> ariBidx ;
	{
		CStrCharSizeMb	aCStrCharSizeMb( strText ) ;
		int iBidx = 0 ;
		for ( iBidx = 0 ; iBidx < aCStrCharSizeMb.ByteLength() ;
				iBidx = aCStrCharSizeMb.BidxNextChar( iBidx ) ){
			ariBidx.push_back( iBidx ) ;
		}
		ariBidx.push_back( iBidx ) ;
	}
	//ariBidx=文字の始まりのインデクスを保持した配列です。
	//	要素数は、文字数＋１（半角文字・全角文字も１と数えます）

	{
		for ( int idx = 0 ; idx < (int)ariBidx.size() - 2 ; idx ++ ){
			if ( ariBidx[idx] + 1 == ariBidx[idx+1] && 
					ariBidx[idx+1] + 1 == ariBidx[idx+2] ){
				//	現在の位置からは、１バイト文字が２つ連続しています。
				//	これは、２バイト文字扱いにします。
				ariBidx.erase( ariBidx.begin() + idx + 1 , ariBidx.begin() + idx + 2 ) ;
			}
		}
	}
	//ariBidx=文字の始まりのインデクスを保持した配列です
	//	(1バイト文字が２つ連続している場合は、２バイトを組にします)。
	//	要素数は、全角文字数＋１
	//	（半角文字２つの組は、全角文字数１と数えます。
	//	半角文字が１つだけある場合は、１と数えます。)

	int iLines = 0 ;	
	int iXOffset = 0 ;
	{
		iLines = ( (int)ariBidx.size() - 1 + m_iLinesExtentY - 1 ) 
			/ m_iLinesExtentY ;
		iXOffset = 
			( aCdDcdZoneXy.getX().getSize() - iLines * sizeExtent.getX() ) 
			/ 2 ;
	}
	//iLines = m_strText を表示するのに必要な、横方向の行数
	//iXOffset = m_strText の描画の、左端の座標。
	//	これは、aCdDcdZoneXy.X.Pos からのオフセットです


	// --------------------------------
	//	全角のブロック単位で、文字を描画
	// --------------------------------
	for ( int idxChar = 0 ; idxChar < (int)ariBidx.size() - 1 ; idxChar ++ ){
		int idxCharY = idxChar % m_iLinesExtentY ;
		int idxCharX = idxChar / m_iLinesExtentY ;
		
		CdDcdZoneXy	zoneChar( 
			CdDcdZone( 
				aCdDcdZoneXy.getX().getPos() + iXOffset + 
				( iLines - 1 - idxCharX ) * sizeExtent.getX() ,
				sizeExtent.getX() ) ,
			CdDcdZone( 
				aCdDcdZoneXy.getY().getPos() + idxCharY * sizeExtent.getY() ,
				sizeExtent.getY() ) 
		) ;
		string strChar = strText.substr( 
			ariBidx[idxChar], 
			ariBidx[idxChar+1] - ariBidx[idxChar] ) ;
		//strChar=今回表示する文字です。
		//	全角文字の場合は１文字となりますが、
		//	半角文字の場合は、半角文字が２つ連続している場合は２文字、
		//	半角文字が１つの場合は１文字となります。

		CStrCharSizeMb	aCStrCharSizeMb( strChar ) ;
		if ( aCStrCharSizeMb.CsizeOfBidx( 0 ) > 1 && hfontVertical != NULL ){
			// --------------------------------
			//	全角文字（１文字）
			// --------------------------------
			CConverter_WinGdi	aConv ;
			
			HFONT hfontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , hfontVertical ) ;
			int iBkModeOld = SetBkMode( pIfDcdTarget->getHdc() , TRANSPARENT ) ;
			COLORREF colTextColorOld = SetTextColor( 
				pIfDcdTarget->getHdc() , 
				aConv.COLORREFOf( m_CDcdText.getCdDrawTextProp().getTextColor() ) ) ;

			TextOut( pIfDcdTarget->getHdc() , 
				zoneChar.getX().getEndPos() + 1 ,	//	この＋１は、実際の画面を見た上で調整した値
				zoneChar.getY().getPos() , 
				strChar.c_str() , 
				(int)strChar.size() ) ;
			
			SetTextColor( pIfDcdTarget->getHdc() , colTextColorOld ) ;
			SetBkMode( pIfDcdTarget->getHdc() , iBkModeOld ) ;
			if ( hfontOld != NULL ){
				SelectObject( pIfDcdTarget->getHdc() , hfontOld ) ;
				hfontOld = NULL ;
			}
			bRv = true ;
		}	else	{
			// --------------------------------
			//	半角文字（１文字か２文字）
			//	これは、通常のフォントで描画します。
			// --------------------------------
		m_CDcdText.setText( strChar ) ;
		
		CaDcdTargetItemPosition	aTarget( pIfDcdTarget ,  zoneChar ) ;
		if ( m_CDcdText.DcDraw( &aTarget ) ) {
			bRv = true ;
		}
	} 
	} 
	
	return ( bRv ) ;
}
	
bool CDcdFillRectangleTextV::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	bool bRv = false ;
	CdDcdSizeXy	sizeExtent ;
	{	
		bRv = m_CDcdText.getItemSize( pIfDcdTarget , &sizeExtent ) ;
		if ( !bRv ){
			return ( bRv ) ;
		}
		sizeExtent.setX( max( sizeExtent.getX() , sizeExtent.getY() ) ) ;
		sizeExtent.setY( sizeExtent.getX() ) ;
	}
	//sizeExtent = テキスト１文字あたりのサイズ。
	//	ただし、サイズは正方形になるように最適化します。
	//	つまり、X,Yのうち、大きい方の辺に合わせます。


	pCdDcdSizeXy->setX( sizeExtent.getX() * m_iLinesExtentX + m_logicalunitFrameWidth * 2 ) ;
	pCdDcdSizeXy->setY( sizeExtent.getY() * m_iLinesExtentY + m_logicalunitFrameHeight * 2 ) ;
	return ( true ) ;
	}
