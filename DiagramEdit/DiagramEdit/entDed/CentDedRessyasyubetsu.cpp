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
//	CentDedRessyasyubetsu.cpp
// ****************************************************************
*/
/** @file */

#include "stdafx.h"
#include "CentDedRessyasyubetsu.h"
#include "CentDedRessyasyubetsuCont.h"

namespace entDed{


// ****************************************************************
//	CentDedRessyasyubetsu
// ****************************************************************
	// ********************************
	//	コンストラクタ
	// ********************************
CentDedRessyasyubetsu::	CentDedRessyasyubetsu( 
			const std::string& strSyubetsumei ,
			const std::string& strRyakusyou ,
			CdColorProp	colorJikokuhyouMojiColor , 
			CdColorProp	colorDiagramSenColor ,
			ESenStyle	eDiagramSenStyle ,
			bool bDiagramSenIsBold ) :
		m_strSyubetsumei( strSyubetsumei ) ,
		m_strRyakusyou( strRyakusyou ) ,
		m_colorJikokuhyouMojiColor( colorJikokuhyouMojiColor ) , 
		m_iJikokuhyouFontIndex( 0 ) ,
		m_CdDiagramLineStyle( colorDiagramSenColor , eDiagramSenStyle , bDiagramSenIsBold ) ,
		m_eStopMarkDrawType( EStopMarkDrawType_DrawOnStop )
{
};

CentDedRessyasyubetsu::CentDedRessyasyubetsu() :
		m_colorJikokuhyouMojiColor( CdColorProp( 0 , 0 , 0 ) ) , 
		m_iJikokuhyouFontIndex( 0 ) ,
		m_eStopMarkDrawType( EStopMarkDrawType_DrawOnStop )
{
};

CentDedRessyasyubetsu& 
CentDedRessyasyubetsu::operator=( const CentDedRessyasyubetsu& value ) 
{
	//	このオブジェクトが、親オブジェクトCentDedEkiTrackCont の
	//	子である場合で、代入元が CentDedEkiTrackCont::set() でエラーに
	//	なる場合、例外スローになります。
	CentDedRessyasyubetsuCont* pParent 
		= dynamic_cast<CentDedRessyasyubetsuCont*>( getParent() ) ;
	if ( pParent != NULL )
	{
		if ( pParent->setable( value , pParent->getIndex( this ) ) )
		{
			throw( LException() ) ;
		}
	}

	//	メンバーのコピー
	m_strSyubetsumei = value.m_strSyubetsumei ;
	m_strRyakusyou = value.m_strRyakusyou ;
	m_colorJikokuhyouMojiColor  = value.m_colorJikokuhyouMojiColor ;
	m_iJikokuhyouFontIndex  = value.m_iJikokuhyouFontIndex ;
	m_CdDiagramLineStyle  = value.m_CdDiagramLineStyle ;
	m_eStopMarkDrawType  = value.m_eStopMarkDrawType ;
	// --------------------------------
	super::operator=( value ) ;
	return *this ;
}

	// ********************************
	//@name CParentBase-操作
	// ********************************
void CentDedRessyasyubetsu::setParent( CParentBase* pParent ) 
{
	super::setParent( pParent ) ;
	adjust() ;
}



	// ********************************
	//@name CentDedRessyasyubetsu-属性
	// ********************************
CentDedRessyasyubetsu& 
CentDedRessyasyubetsu::setSyubetsumei( const std::string& value )
{
	//	このオブジェクトが、親オブジェクト CentDedRessyasyubetsu 
	//	の子である場合、空文字列への変更はエラーとします。
	CentDedRessyasyubetsuCont* pParent 
		= dynamic_cast<CentDedRessyasyubetsuCont*>( getParent() ) ;
	if ( pParent != NULL )
	{
		if ( value.length() == 0 )
		{
			throw( LException() ) ;
		}
	}

	m_strSyubetsumei = value ; 


	return *this ; 
} ;

CentDedRessyasyubetsu& 
CentDedRessyasyubetsu::setJikokuhyouFontIndex( int value )
{
	//	範囲外なら例外スロー
	if ( !( 0 <= value && value < JIKOKUHYOUFONT_COUNT ) )
	{
		throw( LException() ) ;
	}
	m_iJikokuhyouFontIndex = value ; 


	return *this ;
};

	// ********************************
	//@name CentDedRessyasyubetsu-操作
	// ********************************
void CentDedRessyasyubetsu::adjust() 
{
	
};

} //namespace entDed



