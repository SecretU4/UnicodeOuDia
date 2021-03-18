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
//	CdDedDispProp.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include "..\DedRosenFileData\CdDedDispProp.h"

namespace DedRosenFileData{

// ****************************************************************
//	CdDedDispProp
// ****************************************************************

	// ********************************
	//	コンストラクタ
	// ********************************
CdDedDispProp::CdDedDispProp() :
		m_fontpropJikokuhyouVFont( 9 , "@ＭＳ ゴシック" ) ,
		m_fontpropDiaEkimeiFont( 9 ,"ＭＳ ゴシック"  ) ,
		m_fontpropDiaJikokuFont( 9 ,"ＭＳ ゴシック"  ) ,
		m_fontpropDiaRessyaFont( 9 ,"ＭＳ ゴシック"  ) ,
		m_fontpropViewComment( 9 ,"ＭＳ ゴシック"  ) ,
		m_colorDiaMojiColor( CdColorProp( 0 , 0 , 0 ) ) ,
		m_colorDiaHaikeiColor( CdColorProp( 255 , 255 , 255 ) ) ,
		m_colorDiaRessyaColor( CdColorProp( 0 , 0 , 0 ) ) ,
		m_colorDiaJikuColor( CdColorProp(192 , 192 , 192 ) ) ,
		m_iEkimeiLength( 6 ) ,
		m_iJikokuhyouRessyaWidth( 5 ) 
{
	for ( int idx = 0 ; 
		idx < sizeof(m_arJikokuhyouFont) / sizeof(m_arJikokuhyouFont[0]) ;
		idx ++ )
	{
		m_arJikokuhyouFont[idx].setPointTextHeight( 9 )
			.setFacename("ＭＳ ゴシック" ) ;
		if ( idx == 1 )
		{
			m_arJikokuhyouFont[idx].setBold( true ) ;
		}
		else if ( idx == 2 )
		{
			m_arJikokuhyouFont[idx].setItaric( true ) ;
		}
		else if ( idx == 3 )
		{
			m_arJikokuhyouFont[idx].setBold( true ).setItaric( true ) ;
		}

	}
};
	
	
// ********************************
//@name CdDedDispProp-属性
// ********************************
CdFontProp	CdDedDispProp::getJikokuhyouFont(int idx )const
{
	return 	m_arJikokuhyouFont[idx] ;
};
CdDedDispProp& CdDedDispProp::setJikokuhyouFont( 
	int idx , 
	const CdFontProp& value )
{
	m_arJikokuhyouFont[idx] = value ; 
	return *this ;
};

CdFontProp	CdDedDispProp::getJikokuhyouVFont()const
{	return m_fontpropJikokuhyouVFont ;}
CdDedDispProp& CdDedDispProp::setJikokuhyouVFont( const CdFontProp& value )
{	 m_fontpropJikokuhyouVFont = value ; return *this ;}


CdFontProp	CdDedDispProp::getDiaEkimeiFont()const
{
	return 	m_fontpropDiaEkimeiFont ;
};
CdDedDispProp& CdDedDispProp::setDiaEkimeiFont( const CdFontProp& value )
{
	m_fontpropDiaEkimeiFont = value ; return *this ;
};
CdFontProp	CdDedDispProp::getDiaJikokuFont()const
{
	return 	m_fontpropDiaJikokuFont ;
};
CdDedDispProp& CdDedDispProp::setDiaJikokuFont( const CdFontProp& value )
{
	m_fontpropDiaJikokuFont = value ; return *this ;
};
CdFontProp	CdDedDispProp::getDiaRessyaFont()const
{
	return 	m_fontpropDiaRessyaFont ;
};
CdDedDispProp& CdDedDispProp::setDiaRessyaFont( const CdFontProp& value )
{
	m_fontpropDiaRessyaFont = value ; return *this ;
};
CdFontProp	CdDedDispProp::getViewCommentFont()const
{	return m_fontpropViewComment ;};
CdDedDispProp& CdDedDispProp::setViewCommentFont( const CdFontProp& value )
{
	m_fontpropViewComment = value ; return *this ; 
};
		
		
CdColorProp	CdDedDispProp::getDiaMojiColor()const
{
	return m_colorDiaMojiColor ;
};
CdDedDispProp& CdDedDispProp::setDiaMojiColor( const CdColorProp& value )
{
	m_colorDiaMojiColor = value ; return *this ;
};
CdColorProp	CdDedDispProp::getDiaHaikeiColor()const
{
	return m_colorDiaHaikeiColor ;
};
CdDedDispProp& CdDedDispProp::setDiaHaikeiColor( const CdColorProp& value )
{
	m_colorDiaHaikeiColor = value ; return *this ;
};
CdColorProp	CdDedDispProp::getDiaRessyaColor()const
{
	return m_colorDiaRessyaColor ;
};
CdDedDispProp& CdDedDispProp::setDiaRessyaColor( const CdColorProp& value )
{
	m_colorDiaRessyaColor = value ; return *this ;
};
CdColorProp	CdDedDispProp::getDiaJikuColor()const
{
	return m_colorDiaJikuColor ;
};
CdDedDispProp& CdDedDispProp::setDiaJikuColor( const CdColorProp& value )
{
	m_colorDiaJikuColor = value ; return *this ;
};

int CdDedDispProp::getEkimeiLength()const
{ return m_iEkimeiLength ;};
CdDedDispProp& CdDedDispProp::setEkimeiLength( int value )
{
	m_iEkimeiLength = value ;
	if ( m_iEkimeiLength < 1 ){
		m_iEkimeiLength = 1 ;
	}
	if ( m_iEkimeiLength > 29 ){
		m_iEkimeiLength = 29 ;
	}
	return *this ;
};

int CdDedDispProp::getJikokuhyouRessyaWidth()const
{	return m_iJikokuhyouRessyaWidth ; };
CdDedDispProp& CdDedDispProp::setJikokuhyouRessyaWidth( int value )
{	
	m_iJikokuhyouRessyaWidth = value ;	
	if ( m_iJikokuhyouRessyaWidth < 4 )
	{
		m_iJikokuhyouRessyaWidth = 4 ;
	}
	if ( m_iJikokuhyouRessyaWidth > 8 )
	{
		m_iJikokuhyouRessyaWidth = 8 ;
	}
	return *this ;
};

std::string CdDedDispProp::createEkimeiExtentString()const 
{
	std::string	strRv ;
	for ( int idx = 0 ; idx < m_iEkimeiLength ; idx ++ )
	{
		strRv += "国" ;
	}
	return strRv ;
};


void CdDedDispProp::clear()
{
	*this = CdDedDispProp() ; 
} ;

} //namespace DedRosenFileData
