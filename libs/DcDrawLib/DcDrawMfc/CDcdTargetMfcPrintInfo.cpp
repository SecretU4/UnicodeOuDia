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
//	CDcdTargetMfcPrintInfo.cpp
// ****************************************************************
*/

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

#include <sstream>
#include <string>


#include "CDcdTargetMfcPrintInfo.h"
#include "logmsg/LogMsg.h"
#include "DcDraw/CDcDeviceUnitSizeY.h"
#include "DcDraw\CConverter_WinGdi.h"

namespace DcDrawLib{
namespace DcDrawMfc{

using namespace std ;

// ****************************************************************
//	CDcdTargetMfcPrintInfo
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CDcdTargetMfcPrintInfo::CDcdTargetMfcPrintInfo( 
		CDC*			pCDC ,
		const CPrintInfo*	pCPrintInfo ) :
	m_pCDC( pCDC ) ,
	m_pCPrintInfo( pCPrintInfo )
{
	{
		RECT	aRECT = m_pCPrintInfo->m_rectDraw ;
	
		m_zonexyZone = CdDcdZoneXy( 
			CdDcdZone( aRECT.left , aRECT.right - aRECT.left ) ,
			CdDcdZone( aRECT.top , aRECT.bottom - aRECT.top ) ) ;
	}
}
	
CDcdTargetMfcPrintInfo::~CDcdTargetMfcPrintInfo() 
{
}

// ********************************
//@name	IfDcdTarget
// ********************************
HDC	CDcdTargetMfcPrintInfo::getHdc() 
{
	return m_pCDC->GetSafeHdc() ;
}
CdDcdZoneXy CDcdTargetMfcPrintInfo::getZone() 
{
	return m_zonexyZone ;
}
CdDcdZoneXy CDcdTargetMfcPrintInfo::getDrawableZone() 
{
	return m_zonexyZone ;
}

Ou<CGdiHFontHolder>	CDcdTargetMfcPrintInfo::createGdiHFontHolder(  const CdFontProp& paramCdFontProp ) 
{
	CConverter_WinGdi	aConv ;

	CdFontProp	aCdFontProp( paramCdFontProp ) ;
	if ( isPreview() && aCdFontProp.getPointTextHeight() > 0 ){
		//	描画対象が印刷プレビューで、
		//	フォントをポイントサイズで作成する場合、これを
		//	プレビューウインドウのDC（座標にズームが指定されている）ではなく
		//	画面DC（ズームのない座標系）で、論理単位に換算するようにしました
		//	（こうしないと、プレビュー画面でのフォントの大きさが
		//	正しくありません）

		HDC hDcScreen = GetDC( NULL ) ;
		
		int iDp = CDcDeviceUnitSizeY( hDcScreen ).
						setPointSize( aCdFontProp.getPointTextHeight() ).
						getDeviceUnitSize() ;
		aCdFontProp.setLogicalunitTextHeight( iDp ) ;

		ReleaseDC( NULL , hDcScreen ) ;

	}
	return aConv.createGdiHFontHolder( aCdFontProp , getHdc() ) ;
}
	
Ou<CGdiHPenHolder> CDcdTargetMfcPrintInfo::createGdiHPenHolder(  const CdPenProp& aCdPenProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHPenHolder( aCdPenProp ) ;
}

Ou<CGdiHBrushHolder> CDcdTargetMfcPrintInfo::createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHBrushHolder( aCdBrushProp ) ;
}

	
// ********************************
//	CDcdTargetMfcPrintInfo
// ********************************
	// ********************************
	//@name 関連
	// ********************************
HDC CDcdTargetMfcPrintInfo::getPrinterHdc() 
{
	return ( m_pCDC->m_hAttribDC ) ;
}
	// ********************************
	//@name 操作
	// ********************************
bool CDcdTargetMfcPrintInfo::isPreview() 
{
	return ( m_pCPrintInfo->m_bPreview != FALSE ) ;
}
	// ********************************
	//@name デバッグ用関数
	// ********************************
string CDcdTargetMfcPrintInfo::stringOf( CPrintInfo* pInfo ) 
{

	string	strRv ;
	{
		stringstream	sstrLs ;

		sstrLs << "\t m_bDocObject=" << pInfo->m_bDocObject << endl ;
		// 印刷するドキュメントが DocObject であるかどうかを示すフラグを保持します。 
		sstrLs << "\t m_dwFlags=" << pInfo->m_dwFlags << endl ;
		//	DocObject 印刷操作を指定します。 
		sstrLs << "\t m_nOffsetPage=" << pInfo->m_nOffsetPage << endl ;
		//	結合されている DocObject 印刷ジョブ内での特定の DocObject の先頭ページのオフセットを指定します。 
		//m_pPD [印刷] ダイアログ ボックスで使われる CPrintDialog オブジェクトのポインタを保持します。 
		sstrLs << "\t m_bDirect=" << pInfo->m_bDirect << endl ;
		//ドキュメントが ([印刷] ダイアログ ボックスを表示せずに) 直接印刷されるかどうかを示すフラグを保持します。 
		sstrLs << "\t m_bPreview=" << pInfo->m_bPreview << endl ;
		//	ドキュメントがプレビューされているかどうかを示すフラグを保持します。 
		sstrLs << "\t m_bContinuePrinting=" << pInfo->m_bContinuePrinting << endl ;
		//	フレームワークが印刷用ループを続けるかどうかを示すフラグを保持します。 
		sstrLs << "\t m_nCurPage=" << pInfo->m_nCurPage << endl ;
		//	現在印刷されているページ番号を示します。 
		sstrLs << "\t m_nNumPreviewPages=" << pInfo->m_nNumPreviewPages << endl ;
		//	プレビュー用ウィンドウに表示されているページの数を示します。1、または 2 です。 
		sstrLs << "\t m_lpUserData=" << pInfo->m_lpUserData << endl ;
		//	独自に用意した構造体へのポインタを保持します。 
		sstrLs << "\t m_rectDraw=" << 
			 pInfo->m_rectDraw.left << " " <<  pInfo->m_rectDraw.top << " " <<  
			 pInfo->m_rectDraw.right << " " <<   pInfo->m_rectDraw.bottom << endl  ; 
		//	現在使用可能なページ領域として定義されている長方形領域を示します。 
		sstrLs << "\t m_strPageDesc=" << (LPCTSTR)pInfo->m_strPageDesc << endl ;
		//	ページ番号の表示フォーマットを指定する文字列を保持します。 

		strRv = sstrLs.str() ;
	}
	return ( strRv ) ;
};

} //namespace DcDrawMfc
} //namespace DcDrawLib
