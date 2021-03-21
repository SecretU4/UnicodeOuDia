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
//	CDcdFillRectangleTextV2.cpp
// ****************************************************************
*/
//#include "stdafx.h"

#include <deque>
using namespace std ;

#include "CDcdFillRectangleTextV2.h"

#include "str/CStrCharSizeMb.h"
#include "Cont/CCont_deque.h"
#include "logmsg/logmsg.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/CConverter_WinGdi.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

// ****************************************************************
//	CDcdFillRectangleTextV2
// ****************************************************************
// --------------------------------
//@name 下請関数
// --------------------------------
HFONT CDcdFillRectangleTextV2::CreateVFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ) 
{
	HFONT hfontVertical =NULL ;
	{
		CdFontProp	aCdFontPropV = fontHorizontal ;
		string strFacename = aCdFontPropV.getFacename() ;
		if ( !( strFacename.size() >= 1 && strFacename.substr( 0 , 1 ) 
				== "@" ) ){
			strFacename = string( "@" ) + strFacename ;
		}
		aCdFontPropV.setFacename( strFacename ) ;
		aCdFontPropV.setIsEscapementVertical() ;
		hfontVertical = pIfDcdTarget->CreateFont( aCdFontPropV ) ;
	}
	return ( hfontVertical ) ;
}
CdDcdSizeXy CDcdFillRectangleTextV2::calcZenkakuCharExtent(
		IfDcdTarget* pIfDcdTarget , const CdFontProp& aCdFontProp ) 
{
	CdDcdSizeXy	sizeExtent ;
	{
		HFONT hFont = pIfDcdTarget->CreateFont( aCdFontProp ) ;
		// --------------------------------
		HFONT hFontOld = (HFONT)SelectObject( 
			pIfDcdTarget->getHdc() , 
			hFont ) ;
		TEXTMETRIC	aTEXTMETRIC ;
		GetTextMetrics( pIfDcdTarget->getHdc() , &aTEXTMETRIC ) ;
		sizeExtent.setX( aTEXTMETRIC.tmHeight ) ;
		sizeExtent.setY( aTEXTMETRIC.tmMaxCharWidth ) ;

		sizeExtent.setX( max( sizeExtent.getX() , sizeExtent.getY() ) ) ;
		sizeExtent.setY( sizeExtent.getX() ) ;

		// --------------------------------
		if ( hFontOld != NULL ){
			SelectObject( pIfDcdTarget->getHdc() , hFontOld ) ;
		}
	}
	return sizeExtent ;
}


CDcdText CDcdFillRectangleTextV2::createCDcdTextH( 
		const CdFontProp&	aCdFontProp , 
		CdColorProp colorrefText ) 
{
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

static bool isSpace( const string& aStr )
{
	static char* kyoukai[] = {
		" " , "　" ,
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ ){
		if ( aStr == kyoukai[idx] ) {
			return true ;
		}
	}
	return ( false ) ;
}

static bool isKyoukai( const string& aStr )
{
	static char* kyoukai[] = {
		"," , "，" ,
		"." , "．" ,
		      "。" , 
		      "、" , 
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ ){
		if ( aStr == kyoukai[idx] ) {
			return true ;
		}
	}
	return ( false ) ;
}

int CDcdFillRectangleTextV2::StringToMojiretsuyouso( 
		const string& aStr , 
		IfValueCont<CMojiretsuyouso>* pCMojiretsuyousoCont ) 
{
	int iRv = 0 ;
	
	//	このコンテナがそれまで保持していた要素は破棄します。
	pCMojiretsuyousoCont->erase( 0 , INT_MAX ) ;

	CStrCharSizeMb	aCStrCharSizeMb( aStr ) ;
	for ( int bidx = 0 ; 
			bidx < aCStrCharSizeMb.ByteLength() ; 
			bidx = aCStrCharSizeMb.BidxNextChar( bidx ) ){
		string strChar = aStr.substr( bidx , 
			aCStrCharSizeMb.CsizeOfBidx( bidx ) ) ;
		CMojiretsuyouso*	pCMojiretsuyousoPrev = pCMojiretsuyousoCont->getp( INT_MAX ) ;
		//strChar = 今回の文字。
		//aCMojiretsuyousoPrev = 直前の文字列要素

		if ( aCStrCharSizeMb.CsizeOfBidx( bidx ) == 1 ){
			//	今回の文字は空白以外の１バイト文字で、
			//	( 直前の文字列要素が V_HANKAKU 、
			//	かつ、直前の文字列要素が区切り文字や空白で終わっていない
			//	) 
			//	場合は、直前の文字列要素に文字を追加します。
			//
			//	今回の文字は１バイト文字である場合は、文字列要素を追加します。

			string strCharPrev ;
			if ( pCMojiretsuyousoPrev != NULL ){
				strCharPrev = pCMojiretsuyousoPrev->getBubunMojiretsu().substr( 
					pCMojiretsuyousoPrev->getBubunMojiretsu().size() - 1 , 1 ) ;
			}
			//strCharPrev = 直前の文字列要素の末尾の文字

			if ( !isSpace( strChar ) && 
				pCMojiretsuyousoPrev != NULL && 
				pCMojiretsuyousoPrev->getType() == CMojiretsuyouso::V_HANKAKU &&
				!isKyoukai( strCharPrev ) && !isSpace( strCharPrev ) ){
				pCMojiretsuyousoPrev->setBubunMojiretsu( 
					pCMojiretsuyousoPrev->getBubunMojiretsu() + strChar ) ;
			}	else	{
				CMojiretsuyouso	aCMojiretsuyouso ;

				aCMojiretsuyouso.setBubunMojiretsu( strChar ) ;
				aCMojiretsuyouso.setType( CMojiretsuyouso::V_HANKAKU ) ;

				pCMojiretsuyousoCont->insert( aCMojiretsuyouso ) ;
			}
		}	else if ( aCStrCharSizeMb.CsizeOfBidx( bidx ) == 2 ){
			//	今回の文字は２バイトの区切り文字で、
			//	( 直前の文字列要素が V_ZENKAKU 
			//	) 
			//	場合は、直前の文字列要素に文字を追加します。
			//
			//	今回の文字は２バイト文字である場合は、文字列要素を追加します。
			if ( isKyoukai( strChar ) && 
				pCMojiretsuyousoPrev != NULL && 
				pCMojiretsuyousoPrev->getType() == CMojiretsuyouso::V_ZENKAKU ){
				pCMojiretsuyousoPrev->setBubunMojiretsu( 
					pCMojiretsuyousoPrev->getBubunMojiretsu() + strChar ) ;
			}	else	{
				CMojiretsuyouso	aCMojiretsuyouso ;
				aCMojiretsuyouso.setBubunMojiretsu( strChar ) ;
				aCMojiretsuyouso.setType( CMojiretsuyouso::V_ZENKAKU ) ;
				pCMojiretsuyousoCont->insert( aCMojiretsuyouso ) ;

			}
		}

	}
	//pCMojiretsuyousoCont = 文字列を V_ZENKAKU と V_HANKAKU の２つの
	//	要素に分割しました。
	//	V_ZENKAKU は、原則として全角文字１つです。
	//	但し、[全角文字][全角区切り文字]
	//	は、[全角文字+全角区切り文字]の１つの要素になっています。
	//	V_HANKAKU は、連続した半角文字を１つの要素とします。

	// --------------------------------	
	int idxMojiretsuyouso ;
	for ( idxMojiretsuyouso = 0 ; 
			idxMojiretsuyouso < pCMojiretsuyousoCont->size() ;
			idxMojiretsuyouso ++ ){
		//	今回の文字列要素が半角英数字１文字か２文字 
		//	AND 
		//	( 
		//		( 前の文字列要素が存在しない)
		//		OR
		//		( 前の文字列要素が（空白以外の半角文字列の要素）でない)
		//	) 
		CMojiretsuyouso* pCMojiretsuyousoPrev = pCMojiretsuyousoCont->getp( idxMojiretsuyouso - 1 ) ;
		CMojiretsuyouso* pCMojiretsuyouso = pCMojiretsuyousoCont->getp( idxMojiretsuyouso ) ;
		string strCurr = pCMojiretsuyouso->getBubunMojiretsu() ;
		if ( pCMojiretsuyouso->getType() == CMojiretsuyouso::V_HANKAKU ){
			if ( 
				( strCurr.size() == 1 && isdigit( strCurr[0] ) ) || 
				( strCurr.size() == 2 && isdigit( strCurr[0] ) && isdigit( strCurr[1] ) ) 
			){

			if ( pCMojiretsuyousoPrev == NULL || 
				!(  
					pCMojiretsuyousoPrev->getType() == CMojiretsuyouso::V_HANKAKU && 
					!isSpace( pCMojiretsuyousoPrev->getBubunMojiretsu() ) 
				) 
			){
				pCMojiretsuyouso->setType( CMojiretsuyouso::H_HANKAKU ) ;
			}
			}
				
		}

	}
	

	// --------------------------------	
	return ( iRv ) ;
}

int CDcdFillRectangleTextV2::MojiretsuyousoToMojiretsuyousoPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ,
		IfContGet<CMojiretsuyouso>* pCMojiretsuyousoCont ,
		IfCont<CMojiretsuyousoPlace>* pCMojiretsuyousoPlaceCont ) 
{
	int iRv = 0 ;
	
	// --------------------------------
	CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;
	pCMojiretsuyousoPlaceCont->erase( 0 , INT_MAX ) ;
	// --------------------------------
	//	フォントを作成
	// --------------------------------
	HFONT hfontVertical = CreateVFont( pIfDcdTarget , fontHorizontal ) ;
	//hFontVertical = 縦書きのフォント
	
	CDcdText aCDcdText( createCDcdTextH( 
				fontHorizontal , CdColorProp( 0 , 0 , 0 ) ) ) ;
	//aCDcdText = 横書きテキスト用の、DcDrawオブジェクト
	

	// --------------------------------
	int logicalunitYOffset = 0 ;
	int iXLineNumber = 0 ;
	
	int idxMojiretsuyousoCont ;
	for ( idxMojiretsuyousoCont = 0 ; 
			idxMojiretsuyousoCont < pCMojiretsuyousoCont->size() ;){
		CMojiretsuyouso	aCMojiretsuyouso = 
			pCMojiretsuyousoCont->get( idxMojiretsuyousoCont ) ;
		if ( aCMojiretsuyouso.getType() == CMojiretsuyouso::V_ZENKAKU || 
				aCMojiretsuyouso.getType() == CMojiretsuyouso::V_HANKAKU ){
			HFONT hFontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , 
				hfontVertical ) ;
			// --------------------------------
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
				idxMojiretsuyousoEnd < pCMojiretsuyousoCont->size() ;
				idxMojiretsuyousoEnd ++ ){
				CMojiretsuyouso	aCMojiretsuyousoEnd = 
					pCMojiretsuyousoCont->get( idxMojiretsuyousoEnd ) ;

				
				if ( aCMojiretsuyousoEnd.getType() != 
						aCMojiretsuyouso.getType() ){
					//	今回の『部分文字列』は、 idxMojiretsuyousoCont の位置の
					//	『部分文字列』とは種類が異なります。
					break ;
				}


				string aString = strMojiretsu + 
					aCMojiretsuyousoEnd.getBubunMojiretsu() ;
				SIZE	aSize ;
				GetTextExtentPoint32( 
					pIfDcdTarget->getHdc() , 
					aString.c_str() , 
					(int)aString.size() , 
					&aSize ) ;
				
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
			//
			//	また、この状況で、logicalunitYOffset が 0 の場合は、
			//	現在の行に何も描画できなかったことになります。
			//strMojiretsu = 結合された結果の文字列
			//logicalunitYSize = 結合された結果の文字列の、Y方向のサイズ
			//	（論理単位）
			if ( idxMojiretsuyousoCont == idxMojiretsuyousoEnd ){
				logicalunitYOffset = 0 ;
				iXLineNumber ++ ;
				continue ;
			}
			CMojiretsuyousoPlace aCMojiretsuyousoPlace( 
				CMojiretsuyouso( strMojiretsu , aCMojiretsuyouso.getType() ) ,
				logicalunitYOffset , iXLineNumber , iXLineWidth ) ;
			pCMojiretsuyousoPlaceCont->insert( aCMojiretsuyousoPlace ) ;

			logicalunitYOffset += logicalunitYSize ;
			idxMojiretsuyousoCont = idxMojiretsuyousoEnd ;
			// --------------------------------
			SelectObject( pIfDcdTarget->getHdc() , hFontOld ) ;
			hFontOld = NULL ;
		}	else if ( aCMojiretsuyouso.getType() == 
				CMojiretsuyouso::H_HANKAKU ){
			// --------------------------------
			//	同じ種類の連続した『部分文字列』の
			//	結合は行いません。
			// --------------------------------
			string strMojiretsu ;
			int idxMojiretsuyousoEnd = idxMojiretsuyousoCont ;
			int logicalunitYSize = 0 ;
			int iXLineWidth = 0 ;
			{
				CMojiretsuyouso	aCMojiretsuyousoEnd = 
					pCMojiretsuyousoCont->get( idxMojiretsuyousoEnd ) ;
				
				string aString = strMojiretsu + 
					aCMojiretsuyousoEnd.getBubunMojiretsu() ;
				aCDcdText.setText( aString ) ;
				CdDcdSizeXy aCdDcdSizeXy ;
				aCDcdText.getItemSize( pIfDcdTarget , &aCdDcdSizeXy ) ;

				if ( logicalunitYOffset + aCdDcdSizeXy.getY() <= 
						zonexyTarget.getY().getSize() || 
					( logicalunitYOffset == 0 && strMojiretsu.size() == 0 ) ){
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
			//
			//	また、この状況で、logicalunitYOffset が 0 の場合は、
			//	現在の行に何も描画できなかったことになります。
			//strMojiretsu = 結合された結果の文字列
			//logicalunitYSize = 結合された結果の文字列の、Y方向のサイズ
			//	（論理単位）
			if ( idxMojiretsuyousoCont == idxMojiretsuyousoEnd ){
				logicalunitYOffset = 0 ;
				iXLineNumber ++ ;
				continue ;
			}
			CMojiretsuyousoPlace aCMojiretsuyousoPlace( 
				CMojiretsuyouso( strMojiretsu , aCMojiretsuyouso.getType() ) ,
				logicalunitYOffset , iXLineNumber , iXLineWidth ) ;
			pCMojiretsuyousoPlaceCont->insert( aCMojiretsuyousoPlace ) ;

			logicalunitYOffset += logicalunitYSize ;
			idxMojiretsuyousoCont = idxMojiretsuyousoEnd ;
		}
	}
	
	//rinji
	{
		CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;
		LogMsgL(3, "CDcdFillRectangleTextV2::MojiretsuyousoToMojiretsuyousoPlace"
			"(X.Pos=%d X.Size=%d Y.Pos=%d Y.Size=%d)" , 
			zonexyTarget.getX().getPos() , 
			zonexyTarget.getX().getSize() , 
			zonexyTarget.getY().getPos() , 
			zonexyTarget.getY().getSize() ) ;
		int idx ;
		for ( idx = 0 ; idx < pCMojiretsuyousoPlaceCont->size() ; idx ++ ){
			CMojiretsuyousoPlace aCMojiretsuyousoPlace = 
				pCMojiretsuyousoPlaceCont->get( idx ) ;
			LogMsgL(3, "\t[%d] \"%s\" %d iY=%d iX=%d iXLineWidth=%d" ,
				idx , 
				aCMojiretsuyousoPlace.getCMojiretsuyouso().getBubunMojiretsu().c_str() ,
				aCMojiretsuyousoPlace.getCMojiretsuyouso().getType() ,
				aCMojiretsuyousoPlace.getYOffset() ,
				aCMojiretsuyousoPlace.getXLineNumber() , 
				aCMojiretsuyousoPlace.getXLineWidth() ) ;

		}
	}
	
	
	
	// --------------------------------
	return ( iRv ) ;
}

bool CDcdFillRectangleTextV2::DcDrawMojiretsuyousoPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ,
		CdColorProp colorTextColor , 
		IfContGet<CMojiretsuyousoPlace>* pCMojiretsuyousoPlaceCont ) 
{
	bool bRv = false ;

	// --------------------------------
	CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;

	// --------------------------------
	//	フォントを作成
	// --------------------------------
	HFONT hfontVertical = CreateVFont( pIfDcdTarget , fontHorizontal ) ;
	CdDcdSizeXy	sizeExtent = calcZenkakuCharExtent( pIfDcdTarget , fontHorizontal) ;
	//hFontVertical = 縦書きのフォント
	//sizeExtent = テキスト全角ボックス１文字あたりのサイズ。
	//	ただし、サイズは正方形になるように最適化します。
	//	つまり、X,Yのうち、大きい方の辺に合わせます。

	CDcdText aCDcdText( createCDcdTextH( 
				fontHorizontal , colorTextColor ) ) ;
	//aCDcdText = 横書きテキスト用の、DcDrawオブジェクト
	// --------------------------------
	int iLines = 1 ;
	if ( pCMojiretsuyousoPlaceCont->size() > 0 ){
		iLines = pCMojiretsuyousoPlaceCont->get( INT_MAX ).getXLineNumber() 
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
	for ( int idxCMojiretsuyousoPlaceCont = 0 ;
			idxCMojiretsuyousoPlaceCont < pCMojiretsuyousoPlaceCont->size() ;
			idxCMojiretsuyousoPlaceCont ++ ){
		CMojiretsuyousoPlace	aCMojiretsuyousoPlace = 
			pCMojiretsuyousoPlaceCont->get( idxCMojiretsuyousoPlaceCont ) ;
		CMojiretsuyouso	aCMojiretsuyouso = 
			aCMojiretsuyousoPlace.getCMojiretsuyouso() ;
		
		int iXPos = zonexyTarget.getX().getPos() + iXOffset + 
				( iLines - 1 - aCMojiretsuyousoPlace.getXLineNumber() ) 
				* sizeExtent.getX() ;
		int iYPos = zonexyTarget.getY().getPos() + 
				aCMojiretsuyousoPlace.getYOffset() ;
		string strChar = aCMojiretsuyouso.getBubunMojiretsu() ;
		
		if ( aCMojiretsuyouso.getType() == CMojiretsuyouso::V_ZENKAKU || 
				aCMojiretsuyouso.getType() == CMojiretsuyouso::V_HANKAKU )
		{
			// --------------------------------
			//	縦書きフォント
			// --------------------------------
			HFONT hfontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , 
				hfontVertical ) ;
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
					- ( sizeExtent.getX() - aCMojiretsuyousoPlace.getXLineWidth() ) / 2 ,
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
		}	else if ( aCMojiretsuyouso.getType() == 
				CMojiretsuyouso::H_HANKAKU ){
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
CDcdFillRectangleTextV2::CDcdFillRectangleTextV2( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp  ,
		int						iLinesExtentX  ,
		int						iLinesExtentY  ,
		CdColorProp	colorrefText , 
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



CDcdFillRectangleTextV2::CDcdFillRectangleTextV2() 
	: m_iLinesExtentX ( 1 ) 
	, m_iLinesExtentY( 1 ) 
	, m_colorrefText( CdColorProp( 0 , 0 , 0 ) ) 
	, m_logicalunitFrameWidth( 0 )
	, m_logicalunitFrameHeight( 0 )
{
}
	
CDcdFillRectangleTextV2::~CDcdFillRectangleTextV2() 
{
}
// ********************************
//	IfDcDraw
// ********************************
bool CDcdFillRectangleTextV2::DcDraw( IfDcdTarget* pIfDcdTarget ) 
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
		CCont_deque<CMojiretsuyouso> aCMojiretsuyousoCont ;
		StringToMojiretsuyouso( m_strText , &aCMojiretsuyousoCont ) ;
		CCont_deque<CMojiretsuyousoPlace> aCMojiretsuyousoPlaceCont ;
		MojiretsuyousoToMojiretsuyousoPlace( &aCaDcdTargetItemPosition , m_CdFontProp , 
			&aCMojiretsuyousoCont , &aCMojiretsuyousoPlaceCont ) ;
		bRv = DcDrawMojiretsuyousoPlace( &aCaDcdTargetItemPosition , m_CdFontProp , 
			m_colorrefText , &aCMojiretsuyousoPlaceCont ) ;
	}
	return ( bRv ) ;
}
	

	
bool CDcdFillRectangleTextV2::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	bool bRv = false ;

	CdDcdSizeXy	sizeExtent = calcZenkakuCharExtent( pIfDcdTarget , m_CdFontProp ) ;

	pCdDcdSizeXy->setX( sizeExtent.getX() * m_iLinesExtentX + m_logicalunitFrameWidth * 2 ) ;
	pCdDcdSizeXy->setY( sizeExtent.getY() * m_iLinesExtentY + m_logicalunitFrameHeight * 2 ) ;
	return ( true ) ;
}
