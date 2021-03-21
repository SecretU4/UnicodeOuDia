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
//	CDcdTextboxV3.cpp
// ****************************************************************
*/
#include <deque>
#include "str\CStrCharSizeMb.h"
#include "NsMu\CMup_deque.h"
#include "logmsg\logmsg.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CVerticalTextElement.h"
#include "DcDraw\CVerticalTextElementBuilder.h"
#include "CDcdTextboxV3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcDraw{
	using namespace OuLib::Str ;
// ****************************************************************
//	CDcdTextboxV3
// ****************************************************************
// --------------------------------
//@name 下請関数
// --------------------------------

Ou<CGdiHFontHolder> CDcdTextboxV3::CreateVFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ) 
{
	Ou<CGdiHFontHolder> pfontVertical ;
	{
		CdFontProp	aCdFontPropV = fontHorizontal ;
		aCdFontPropV.setIsEscapementVertical() ;
		pfontVertical = pIfDcdTarget->createGdiHFontHolder( aCdFontPropV ) ;
	}
	return ( pfontVertical ) ;
}

Ou<CGdiHFontHolder> CDcdTextboxV3::CreateHFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ) 
{
	Ou<CGdiHFontHolder> pfontVertical ;
	{
		CdFontProp	aCdFontPropV = fontHorizontal ;
		aCdFontPropV.setIsEscapementHolyzontal() ;
		pfontVertical = pIfDcdTarget->createGdiHFontHolder( aCdFontPropV ) ;
	}
	return ( pfontVertical ) ;
}


CdDcdSizeXy CDcdTextboxV3::calcZenkakuCharExtent(
		IfDcdTarget* pIfDcdTarget , const CdFontProp& aCdFontProp ) 
{
	CdDcdSizeXy	sizeExtent ;
	{
		Ou<CGdiHFontHolder> pFontHolder = pIfDcdTarget->createGdiHFontHolder( aCdFontProp ) ;
		// --------------------------------
		HFONT hFontOld = (HFONT)SelectObject( 
			pIfDcdTarget->getHdc() , 
			pFontHolder->getHFont() ) ;
		TEXTMETRIC	aTEXTMETRIC ;
		GetTextMetrics( pIfDcdTarget->getHdc() , &aTEXTMETRIC ) ;

		//	TEXTMETRIC::tmMaxCharWidth は、Windows7大きすぎ(日本語には)
		//	Windows7とWindows10とでは、GetTextMetrics() 関数によって得られる 
		//	TEXTMETRIC::tmMaxCharWidth
		//	(https://msdn.microsoft.com/en-us/library/windows/desktop/dd145132(v=vs.85).aspx) 
		//	の値が異なります。
		//	"＠ＭＳ ゴシック" の9ポイントのフォントの場合、TEXTMETRIC::tmMaxCharWidth の値は、
		//	Windows7では 13、Windows10 では 24 となります。
		//	Windows10 の24は余りにも大きすぎます。このため、文字のサイズは
		//	TEXTMETRIC.tmHeight だけをもとに決めることにしました。
		
		//// 以前のコード
		//	sizeExtent.setX( aTEXTMETRIC.tmHeight ) ;
		//	sizeExtent.setY( aTEXTMETRIC.tmMaxCharWidth ) ;
		//	sizeExtent.setX( max( sizeExtent.getX() , sizeExtent.getY() ) ) ;
		//	sizeExtent.setY( sizeExtent.getX() ) ;

		sizeExtent.setX( aTEXTMETRIC.tmHeight ).setY( aTEXTMETRIC.tmHeight ) ;

		// --------------------------------
		if ( hFontOld != NULL ){
			SelectObject( pIfDcdTarget->getHdc() , hFontOld ) ;
		}
	}
	return sizeExtent ;
}


CDcdText CDcdTextboxV3::createCDcdTextH( 
		const CdFontProp&	aCdFontPropArg , 
		const CdColorProp& colorrefText ) 
{
	CdFontProp	aCdFontProp = aCdFontPropArg ;
	aCdFontProp.setIsEscapementHolyzontal() ;

	CDcdText	aCDcdText( 
		"" , 
		CdDrawTextProp( aCdFontProp , colorrefText ) , 
		"00" ) ;
	//	aCDcdText は、上下左右中央寄せにします。
	//	これは、半角数字１文字を表示する際に、中央に表示するためです。
	{
		CdDrawTextProp	aCdDrawTextProp = aCDcdText.getCdDrawTextProp() ;
		aCdDrawTextProp.setCdDrawTextFormat( 
			CdDrawTextFormat(
				 CdDrawTextFormat::H_CENTER , 
				CdDrawTextFormat::V_SINGLELINT_CENTER 
			) 
		) ;
		aCDcdText.setCdDrawTextProp( aCdDrawTextProp ) ;
	}
	return aCDcdText ;
}


int CDcdTextboxV3::VerticalTextElementToElementPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aCdFontProp ,
		const Mu<CVerticalTextElement>* pCStrElementCont ,
		Mui<CStrElementPlace>* pCStrElementPlaceCont ) 
{
	int iRv = 0 ;
	
	// --------------------------------
	CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;
	pCStrElementPlaceCont->erase( 0 , INT_MAX ) ;
	// --------------------------------
	//	フォントを作成
	// --------------------------------
	Ou<CGdiHFontHolder> fontVertical ; 
	Ou<CGdiHFontHolder> fontHolyzontal ; 
	{
		fontVertical = CreateVFont( 
			pIfDcdTarget , aCdFontProp ) ;
		fontHolyzontal = CreateHFont( 
			pIfDcdTarget , aCdFontProp ) ;
	}
	CDcdText aCDcdText( createCDcdTextH( 
				aCdFontProp , CdColorProp( 0 , 0 , 0 ) ) ) ;
	//aCDcdText = 横書きテキスト用の、DcDrawオブジェクト
	// --------------------------------
	int logicalunitYOffset = 0 ;	//現在の、DcDraw領域上部からのY座標
	int iXLineNumber = 0 ;			//現在の、X方向の行番号
	
	int idxMojiretsuyousoCont ;
	for ( idxMojiretsuyousoCont = 0 ; 
			idxMojiretsuyousoCont < pCStrElementCont->size() ;){
		CVerticalTextElement	aCStrElement = 
			pCStrElementCont->get( idxMojiretsuyousoCont ) ;

		//	縦書き(半角・全角)
		if ( aCStrElement.getType() == CVerticalTextElement::V_ZENKAKU || 
				aCStrElement.getType() == CVerticalTextElement::V_HANKAKU )
		{
			HFONT hFontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , 
				fontVertical->getHFont() ) ;
			// --------------------------------
			//	部分文字列の結合を行うために、
			//	同じ種類の連続した『部分文字列』の
			//	終端を探します。
			//	但し、行に表示できない場合は、
			//	結合を打ち切ります。
			// --------------------------------
			string strMojiretsu ;
			int idxMojiretsuyousoEnd = idxMojiretsuyousoCont ;
			int logicalunitYSize = 0 ;
			int iXLineWidth = 0 ;
			for ( idxMojiretsuyousoEnd = idxMojiretsuyousoCont ;
				idxMojiretsuyousoEnd < pCStrElementCont->size() ;
				idxMojiretsuyousoEnd ++ ){
				CVerticalTextElement	aCStrElementEnd = 
					pCStrElementCont->get( idxMojiretsuyousoEnd ) ;

				
				if ( aCStrElementEnd.getType() != 
						aCStrElement.getType() )
				{
					//	今回の『部分文字列』は、 idxMojiretsuyousoCont の位置の
					//	『部分文字列』とは種類が異なります。
					break ;
				}


				string aString = strMojiretsu + 
					aCStrElementEnd.getString() ;
				SIZE	aSize ;
				GetTextExtentPoint32( 
					pIfDcdTarget->getHdc() , 
					aString.c_str() , 
					(int)aString.size() , 
					&aSize ) ;
				//
				if ( logicalunitYOffset + aSize.cx <= 
						zonexyTarget.getY().getSize() || 
					( logicalunitYOffset == 0 && strMojiretsu.size() == 0 ) ){
					//	今回の文字は、この行（iXLineNumber の行）に
					//	表示できます。
					//
					//	※　行の先頭には必ず１つ『部分文字列』を
					//	存在させる必要があります。
					strMojiretsu = aString ;
					logicalunitYSize = aSize.cx ;
					iXLineWidth = aSize.cy ;
				}	else	{
					break ;
				}
			}
			//idxMojiretsuyousoEnd = 結合される『部分文字列』の次のインデクス
			//	『部分文字列』を現在の行（iXLineNumber）に一つも描画できない
			//	場合は、
			//	idxMojiretsuyousoCont == idxMojiretsuyousoEnd となります。
			//strMojiretsu = 結合された結果の文字列
			//logicalunitYSize = 結合された結果の文字列の、Y方向のサイズ
			//	（論理単位）


			if ( idxMojiretsuyousoCont == idxMojiretsuyousoEnd )
			{
				//	1文字も表示できなかった場合は、
				//	次の行への表示を試みます。
				logicalunitYOffset = 0 ;
				iXLineNumber ++ ;
				continue ;
			}
			//	結合結果をもとに、CStrElementPlace オブジェクトを生成し、
			//	コンテナに格納します。
			CStrElementPlace aCStrElementPlace( 
				CVerticalTextElement( strMojiretsu , aCStrElement.getType() ) ,
				logicalunitYOffset , iXLineNumber , iXLineWidth ) ;
			pCStrElementPlaceCont->insert( aCStrElementPlace ) ;
			
			//現在の、DcDraw領域上部からのY座標を、先に進める
			logicalunitYOffset += logicalunitYSize ;

			idxMojiretsuyousoCont = idxMojiretsuyousoEnd ;
			// --------------------------------
			SelectObject( pIfDcdTarget->getHdc() , hFontOld ) ;
			hFontOld = NULL ;
		}
		//	横書き文字列
		else if ( aCStrElement.getType() == 
				CVerticalTextElement::H_HANKAKU )
		{
			// --------------------------------
			//	同じ種類の連続した『部分文字列』の
			//	結合は行いません。
			// --------------------------------
			string strMojiretsu ;
			int idxMojiretsuyousoEnd = idxMojiretsuyousoCont ;
			int logicalunitYSize = 0 ;
			int iXLineWidth = 0 ;
			{
				CVerticalTextElement	aCStrElementEnd = 
					pCStrElementCont->get( idxMojiretsuyousoEnd ) ;
				
				string aString = strMojiretsu + 
					aCStrElementEnd.getString() ;
				aCDcdText.setText( aString ) ;
				CdDcdSizeXy aCdDcdSizeXy ;
				aCDcdText.getItemSize( pIfDcdTarget , &aCdDcdSizeXy ) ;

				if ( logicalunitYOffset + aCdDcdSizeXy.getY() <= 
						zonexyTarget.getY().getSize() || 
					( logicalunitYOffset == 0 && strMojiretsu.size() == 0 ) )
				{
					//	今回の文字は、この行（iXLineNumber の行）に
					//	表示できます。
					//
					//	※　行の先頭には必ず１つ『部分文字列』を
					//	存在させる必要があります。
					strMojiretsu = aString ;
					logicalunitYSize = aCdDcdSizeXy.getY() ;
					iXLineWidth = aCdDcdSizeXy.getX() ;
					idxMojiretsuyousoEnd ++ ;
				}
			}
			//idxMojiretsuyousoEnd = 結合される『部分文字列』の次のインデクス
			//	『部分文字列』を現在の行（iXLineNumber）に一つも描画できない
			//	場合は、
			//	idxMojiretsuyousoCont == idxMojiretsuyousoEnd となります。
			//strMojiretsu = 結合された結果の文字列
			//logicalunitYSize = 結合された結果の文字列の、Y方向のサイズ
			//	（論理単位）

			if ( idxMojiretsuyousoCont == idxMojiretsuyousoEnd )
			{
				//	1文字も表示できなかった場合は、
				//	次の行への表示を試みます。
				logicalunitYOffset = 0 ;
				iXLineNumber ++ ;
				continue ;
			}
			CStrElementPlace aCStrElementPlace( 
				CVerticalTextElement( strMojiretsu , aCStrElement.getType() ) ,
				logicalunitYOffset , iXLineNumber , iXLineWidth ) ;
			pCStrElementPlaceCont->insert( aCStrElementPlace ) ;

			//現在の、DcDraw領域上部からのY座標を、先に進める
			logicalunitYOffset += logicalunitYSize ;

			idxMojiretsuyousoCont = idxMojiretsuyousoEnd ;
		}
	}
	
	//debug
	{
		CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;
		LogMsgL(3, "CDcdTextboxV3::MojiretsuyousoToMojiretsuyousoPlace"
			"(X.Pos=%d X.Size=%d Y.Pos=%d Y.Size=%d)" , 
			zonexyTarget.getX().getPos() , 
			zonexyTarget.getX().getSize() , 
			zonexyTarget.getY().getPos() , 
			zonexyTarget.getY().getSize() ) ;
		int idx ;
		for ( idx = 0 ; idx < pCStrElementPlaceCont->size() ; idx ++ ){
			CStrElementPlace aCStrElementPlace = 
				pCStrElementPlaceCont->get( idx ) ;
			LogMsgL(3, "\t[%d] \"%s\" %d iY=%d iX=%d iXLineWidth=%d" ,
				idx , 
				aCStrElementPlace.getCStrElement().getString().c_str() ,
				aCStrElementPlace.getCStrElement().getType() ,
				aCStrElementPlace.getYOffset() ,
				aCStrElementPlace.getXLineNumber() , 
				aCStrElementPlace.getXLineWidth() ) ;

		}
	}
	
	
	
	// --------------------------------
	return ( iRv ) ;
}

bool CDcdTextboxV3::DcDrawElementPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aFontProp ,
		const CdColorProp&  colorTextColor , 
		const Mu<CStrElementPlace>* pCStrElementPlaceCont ) 
{
	bool bRv = false ;

	// --------------------------------
	CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;

	// --------------------------------
	//	フォントを作成
	// --------------------------------
	Ou<CGdiHFontHolder>  pfontVertical = CreateVFont( 
		pIfDcdTarget , 
		aFontProp ) ; 
	CdDcdSizeXy	sizeExtent = calcZenkakuCharExtent( pIfDcdTarget , aFontProp) ;
	//hFontVertical = 縦書きのフォント
	//sizeExtent = テキスト全角ボックス１文字あたりのサイズ。
	//	ただし、サイズは正方形になるように最適化します。
	//	つまり、X,Yのうち、大きい方の辺に合わせます。
	
	CDcdText aCDcdText( createCDcdTextH( 
				aFontProp , colorTextColor ) ) ;
	//aCDcdText = 横書きテキスト用の、DcDrawオブジェクト
	// --------------------------------
	int iLines = 1 ;
	if ( pCStrElementPlaceCont->size() > 0 ){
		iLines = pCStrElementPlaceCont->get( INT_MAX ).getXLineNumber() 
			+ 1 ;
	}
	//iLines = X方向の行数

	int iXOffset = 0 ;
	{
		iXOffset = 
			( zonexyTarget.getX().getSize() - iLines * sizeExtent.getX() ) 
			/ 2 ;
	}
	//iXOffset = m_strText の描画の、左端の座標。
	//	これは、zonexyTarget.X.Pos からのオフセットです

	// --------------------------------
	//	文字を描画
	// --------------------------------
	for ( int idxCStrElementPlaceCont = 0 ;
			idxCStrElementPlaceCont < pCStrElementPlaceCont->size() ;
			idxCStrElementPlaceCont ++ ){
		CStrElementPlace	aCStrElementPlace = 
			pCStrElementPlaceCont->get( idxCStrElementPlaceCont ) ;
		CVerticalTextElement	aCStrElement = 
			aCStrElementPlace.getCStrElement() ;
		
		int iXPos = zonexyTarget.getX().getPos() + iXOffset + 
				( iLines - 1 - aCStrElementPlace.getXLineNumber() ) 
				* sizeExtent.getX() ;
		int iYPos = zonexyTarget.getY().getPos() + 
				aCStrElementPlace.getYOffset() ;
		string strChar = aCStrElement.getString() ;
		
		if ( aCStrElement.getType() == CVerticalTextElement::V_ZENKAKU || 
				aCStrElement.getType() == CVerticalTextElement::V_HANKAKU )
		{
			// --------------------------------
			//	縦書きフォント
			// --------------------------------
			HFONT hfontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , 
				pfontVertical->getHFont() ) ;
			int iBkModeOld = SetBkMode( pIfDcdTarget->getHdc() , 
				TRANSPARENT ) ;
			CConverter_WinGdi	aConv ;
			COLORREF colTextColorOld = SetTextColor( 
				pIfDcdTarget->getHdc() , 
				aConv.COLORREFOf( colorTextColor ) ) ;
			// --------------------------------
			TextOut( pIfDcdTarget->getHdc() , 
				//	下の＋１は、実際の画面を見た上で調整した値
				iXPos + sizeExtent.getX() + 1 
					- ( sizeExtent.getX() - aCStrElementPlace.getXLineWidth() ) / 2 ,
				iYPos , 
				strChar.c_str() , 
				(int)strChar.size() ) ;
			// --------------------------------
			SetTextColor( pIfDcdTarget->getHdc() , colTextColorOld ) ;
			SetBkMode( pIfDcdTarget->getHdc() , iBkModeOld ) ;
			if ( hfontOld != NULL ){
				SelectObject( pIfDcdTarget->getHdc() , hfontOld ) ;
				hfontOld = NULL ;
			}
			bRv = true ;
		}	else if ( aCStrElement.getType() == 
				CVerticalTextElement::H_HANKAKU ){
			// --------------------------------
			//	横書きフォント
			// --------------------------------
			CdDcdZoneXy	zoneChar( 
				CdDcdZone( iXPos, sizeExtent.getX() ) , 
				CdDcdZone( iYPos , sizeExtent.getY() ) ) ;
			aCDcdText.setText( strChar ) ;
			CaDcdTargetItemPosition	aTarget( pIfDcdTarget ,  zoneChar ) ;
			if ( aCDcdText.DcDraw( &aTarget ) ) {
				bRv = true ;
			}
		}
	}


	return ( bRv ) ;
}


// ********************************
//	コンストラクタ
// ********************************

CDcdTextboxV3::CDcdTextboxV3( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp  ,
		int						iLinesExtentX  ,
		int						iLinesExtentY  ,
		const CdColorProp&	colorrefText , 
		int						logicalunitFrameWidth   ,
		int						logicalunitFrameHeight   ,
		const CdPenProp&		aCdPenProp ,
		const CdBrushProp& 		aCdBrushProp ) 
	: m_CDcdFillrect( aCdBrushProp ) 
	, m_CDcdRectangle(  aCdPenProp ) 
	, m_strText( strText ) 
	, m_CdFontProp( aCdFontProp ) 
	, m_iLinesExtentX( iLinesExtentX )
	, m_iLinesExtentY( iLinesExtentY ) 
	, m_colorrefText( colorrefText ) 
	, m_logicalunitFrameWidth( logicalunitFrameWidth )
	, m_logicalunitFrameHeight( logicalunitFrameHeight )
{
}



CDcdTextboxV3::CDcdTextboxV3() 
	: m_iLinesExtentX ( 1 ) 
	, m_iLinesExtentY( 1 ) 
	, m_colorrefText( CdColorProp( 0 , 0 , 0 ) ) 
	, m_logicalunitFrameWidth( 0 )
	, m_logicalunitFrameHeight( 0 )
{
}
	
CDcdTextboxV3::~CDcdTextboxV3() 
{
}
// ********************************
//	IfDcDraw
// ********************************
bool CDcdTextboxV3::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool	bRv = false ;

	// --------------------------------
	//	背景ブラシの描画
	// --------------------------------
	{
		if ( m_CDcdFillrect.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}
	// --------------------------------
	//	枠線の描画
	// --------------------------------
	{
		if ( m_CDcdRectangle.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}

	// ********************************
	//	テキストの描画
	// ********************************
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

	{
		CaDcdTargetItemPosition aCaDcdTargetItemPosition( 
			pIfDcdTarget , 
			aCdDcdZoneXy ) ;
		CMup_deque<CVerticalTextElement> aCStrElementCont ;

		CVerticalTextElementBuilder::scan( m_strText , &aCStrElementCont ,m_CdFontProp.isVerticalFacename()) ;

		CMup_deque<CStrElementPlace> aCStrElementPlaceCont ;
		VerticalTextElementToElementPlace( 
			&aCaDcdTargetItemPosition , 
			m_CdFontProp , 
			&aCStrElementCont , 
			&aCStrElementPlaceCont ) ;

		bRv = DcDrawElementPlace( 
			&aCaDcdTargetItemPosition , 
			m_CdFontProp , 
			m_colorrefText , 
			&aCStrElementPlaceCont ) ;
	}
	return ( bRv ) ;
}

	
bool CDcdTextboxV3::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	bool bRv = false ;

	CdDcdSizeXy	sizeExtent = calcZenkakuCharExtent( pIfDcdTarget , m_CdFontProp ) ;

	pCdDcdSizeXy->setX( sizeExtent.getX() * m_iLinesExtentX + m_logicalunitFrameWidth * 2 ) ;
	pCdDcdSizeXy->setY( sizeExtent.getY() * m_iLinesExtentY + m_logicalunitFrameHeight * 2 ) ;
	return ( true ) ;
}

} //namespace DcDraw
} //namespace DcDrawLib

