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
//****************************************************************
//	CdDrawTextFormat.cpp
//****************************************************************
*/
#include "stdafx.h"

#include "CdDrawTextFormat.h"

// ****************************************************************
//	CdDrawTextFormat
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CdDrawTextFormat::CdDrawTextFormat( UINT uiFormat ) : 
	m_uiDrawTextFormat( uiFormat )
{
} ;

CdDrawTextFormat::CdDrawTextFormat( 
		EHolizontal eHolizontal ,
		EVertical eVertical ,
		EClipping eClipping ,
		EEditControl eEditControl ,
		EEllipses eEllipses ,
		int iTabstop ,
		EExternalLeading eExternalLeading ,
		EReading eReading ,
		EPrefix ePrefix )
	: m_uiDrawTextFormat( 0 )
{
	setHorizontal( eHolizontal ) ;
	setVertical( eVertical ) ;
	setClipping( eClipping ) ;
	setEditControl( eEditControl ) ;
	setEllipses( eEllipses ) ;
	setTabStop( iTabstop );
	setExternalLeading( eExternalLeading ) ;
	setReading( eReading ) ;
	setPrefix( ePrefix ) ;

} ;


// ********************************
//	CdDrawTextFormat
// ********************************
const UINT g_HorizontalMASK = 
	( DT_LEFT | DT_CENTER | DT_RIGHT ) ;
CdDrawTextFormat::EHolizontal CdDrawTextFormat::getHorizontal()const
{
	EHolizontal rv = H_LEFT ;
	if ( ( m_uiDrawTextFormat & g_HorizontalMASK ) == 
		( DT_CENTER ) ){
		rv = H_CENTER ;
	}	else if ( ( m_uiDrawTextFormat & g_HorizontalMASK ) == 
		( DT_RIGHT ) ){
		rv = H_RIGHT ;
	}
	return ( rv ) ;
};

CdDrawTextFormat& 
CdDrawTextFormat::setHorizontal( CdDrawTextFormat::EHolizontal ev )
{
	m_uiDrawTextFormat &=~ g_HorizontalMASK ;
	if ( ev == H_CENTER ){
		m_uiDrawTextFormat |=  DT_CENTER ;
	}	else if ( ev == H_RIGHT ){
		m_uiDrawTextFormat |= DT_RIGHT  ;
	}	else	{
		m_uiDrawTextFormat |= DT_LEFT  ;
	}
	return ( *this ) ;
};

const UINT g_VerticalMASK = 
	( DT_SINGLELINE | DT_TOP | DT_VCENTER | DT_BOTTOM | DT_WORDBREAK ) ;

CdDrawTextFormat::EVertical CdDrawTextFormat::getVertical()const
{
	EVertical rv = V_MULTILINE ;
	if ( ( m_uiDrawTextFormat & g_VerticalMASK ) == 
		( DT_SINGLELINE | DT_TOP ) ){
		rv = V_SINGLELINT_TOP ;
	}	else if ( ( m_uiDrawTextFormat & g_VerticalMASK ) == 
		( DT_SINGLELINE | DT_VCENTER ) ){
		rv = V_SINGLELINT_CENTER ;
	}	else if ( ( m_uiDrawTextFormat & g_VerticalMASK ) == 
		( DT_SINGLELINE | DT_BOTTOM ) ){
		rv = V_SINGLELINT_BOTTOM ;
//	}	else if ( ( m_uiDrawTextFormat & g_VerticalMASK ) == 
//		( DT_WORDBREAK | DT_NOFULLWIDTHCHARBREAK ) ){
//		rv = V_NOFULLWIDTHCHARBREAK ;
	}	else if ( ( m_uiDrawTextFormat & g_VerticalMASK ) ==  
		( DT_WORDBREAK ) ){
		rv = V_MULTILINE_WORDBREAK  ;
	}
	return ( rv ) ;
};

CdDrawTextFormat& 
CdDrawTextFormat::setVertical( CdDrawTextFormat::EVertical ev )
{
	m_uiDrawTextFormat &=~g_VerticalMASK ;

	if ( ev == V_SINGLELINT_TOP ){
		m_uiDrawTextFormat |= ( DT_SINGLELINE | DT_TOP ) ;
	}	else if ( ev == V_SINGLELINT_CENTER ){
		m_uiDrawTextFormat |= ( DT_SINGLELINE | DT_VCENTER ) ;
	}	else if ( ev == V_SINGLELINT_BOTTOM ){
		m_uiDrawTextFormat |= ( DT_SINGLELINE | DT_BOTTOM ) ;
	}	else if ( ev == V_MULTILINE_WORDBREAK ){
		m_uiDrawTextFormat |= ( DT_WORDBREAK ) ;
//	}	else if ( ev == V_NOFULLWIDTHCHARBREAK ){
//		m_uiDrawTextFormat |= ( DT_WORDBREAK | DT_NOFULLWIDTHCHARBREAK ) ;
	}
	return ( *this ) ;
};

const UINT g_ClipMASK = ( DT_NOCLIP ) ;

CdDrawTextFormat::EClipping CdDrawTextFormat::getClipping()const
{
	EClipping rv = C_CLIP ;
	if ( ( m_uiDrawTextFormat & g_ClipMASK ) == 
		( DT_NOCLIP ) ){
		rv = C_NOCLIP ;
	}
	return ( rv ) ;
};

CdDrawTextFormat& 
CdDrawTextFormat::setClipping( CdDrawTextFormat::EClipping ev )
{
	m_uiDrawTextFormat &=~ g_ClipMASK ;

	if ( ev == C_NOCLIP ){
		m_uiDrawTextFormat |= ( DT_NOCLIP ) ;
	}
	return ( *this ) ;
};

const UINT g_EditControlMASK = ( DT_EDITCONTROL ) ;

CdDrawTextFormat::EEditControl CdDrawTextFormat::getEditControl()const
{
	EEditControl rv = NOEDITCONTROL ;
	if ( ( m_uiDrawTextFormat & g_EditControlMASK ) == 
		( DT_EDITCONTROL ) ){
		rv = EDITCONTROL ;
	}
	return ( rv ) ;
};

CdDrawTextFormat& 
CdDrawTextFormat::setEditControl( CdDrawTextFormat::EEditControl ev )
{
	m_uiDrawTextFormat &=~ g_EditControlMASK ;

	if ( ev == EDITCONTROL ){
		m_uiDrawTextFormat |= ( DT_EDITCONTROL ) ;
	}
	return ( *this ) ;
};

const UINT g_EllipsesMASK = 
	( DT_END_ELLIPSIS | DT_PATH_ELLIPSIS | DT_WORD_ELLIPSIS ) ;

CdDrawTextFormat::EEllipses CdDrawTextFormat::getEllipses()const
{
	EEllipses rv = NOELLIPSIS ;
	if ( ( m_uiDrawTextFormat & g_EllipsesMASK ) ==
		( DT_END_ELLIPSIS ) ){
		rv = END_ELLIPSIS  ;
	}	else if ( ( m_uiDrawTextFormat & g_EllipsesMASK ) ==
		( DT_PATH_ELLIPSIS ) ){
		rv = PATH_ELLIPSIS   ;
	}	else if ( ( m_uiDrawTextFormat & g_EllipsesMASK ) ==
		( DT_WORD_ELLIPSIS ) ){
		rv = WORD_ELLIPSIS   ;
	}
	return ( rv ) ;
}

CdDrawTextFormat&
CdDrawTextFormat::setEllipses( CdDrawTextFormat::EEllipses ev )
{
	m_uiDrawTextFormat &=~ g_EllipsesMASK ;
	if ( ev == END_ELLIPSIS ){
		m_uiDrawTextFormat |= ( DT_END_ELLIPSIS ) ;
	}	else if ( ev == PATH_ELLIPSIS ){
		m_uiDrawTextFormat |= ( DT_PATH_ELLIPSIS ) ;
	}	else if ( ev == WORD_ELLIPSIS ){
		m_uiDrawTextFormat |= ( DT_WORD_ELLIPSIS ) ;
	}
	return ( *this ) ;
}

const UINT g_TabStopMASK = 
	( DT_EXPANDTABS | DT_TABSTOP | 0x0000FF00 ) ;

int CdDrawTextFormat::getTabStop()const
{
	int iRv = 0 ;
	if ( ( m_uiDrawTextFormat & DT_EXPANDTABS ) == ( DT_EXPANDTABS ) ){
		if ( ( m_uiDrawTextFormat & DT_TABSTOP ) == ( DT_TABSTOP ) ){
			iRv = ( ( m_uiDrawTextFormat & 0x0000FF00 ) >> 8 ) ;
		}	else	{
			iRv = 8 ;
		}
	}	else	{
		iRv = -1 ;
	}
	return ( iRv ) ;
}

CdDrawTextFormat&
CdDrawTextFormat::setTabStop( int ev )
{
	m_uiDrawTextFormat &=~ g_TabStopMASK ;
	if ( ev != 0 ){
		m_uiDrawTextFormat |= ( DT_EXPANDTABS ) ;
		if ( ev > 0 ){
			m_uiDrawTextFormat |= ( DT_TABSTOP ) ;
			m_uiDrawTextFormat |= ( ( ev & 0xff ) << 8 ) ;
		}
	}
	return ( *this ) ;
}

const UINT g_ExternalLeadingMASK = 
	( DT_EXTERNALLEADING ) ;

CdDrawTextFormat::EExternalLeading
CdDrawTextFormat::getExternalLeading()const
{
	EExternalLeading	rv = NOEXTERNALLEADING  ;
	if ( ( m_uiDrawTextFormat & g_ExternalLeadingMASK ) == 
		( DT_EXTERNALLEADING ) ){
		rv = EXTERNALLEADING ;
	}
	return ( rv ) ;
}

CdDrawTextFormat&
CdDrawTextFormat::setExternalLeading( CdDrawTextFormat::EExternalLeading ev )
{
	m_uiDrawTextFormat &=~ g_ExternalLeadingMASK  ;
	if ( ev == EXTERNALLEADING ){
		m_uiDrawTextFormat |= ( DT_EXTERNALLEADING ) ;
	}
	return ( *this ) ;
}

const UINT g_EReadingMASK = 
	( DT_RTLREADING ) ;

CdDrawTextFormat::EReading
CdDrawTextFormat::getReading()const
{
	EReading	rv = R_LEFT  ;
	if ( ( m_uiDrawTextFormat & g_EReadingMASK ) == 
		( DT_RTLREADING ) ){
		rv = R_RIGHT ;
	}
	return ( rv ) ;
}

CdDrawTextFormat&
CdDrawTextFormat::setReading( CdDrawTextFormat::EReading ev )
{
	m_uiDrawTextFormat &=~ g_EReadingMASK  ;
	if ( ev == R_RIGHT ){
		m_uiDrawTextFormat |= ( DT_RTLREADING ) ;
	}
	return ( *this ) ;
}

const UINT g_EPrefixMASK = 
	( DT_NOPREFIX  
//	| DT_HIDEPREFIX		//このフラグが利用可能なWindowsのバージョンは限定されます。Windows 2000/XP
//	| DT_PREFIXONLY		//このフラグが利用可能なWindowsのバージョンは限定されます。Windows 2000/XP
	) ;

CdDrawTextFormat::EPrefix
CdDrawTextFormat::getPrefix()const
{
	EPrefix	rv = NORMAL_PREFIX  ;
	if ( ( m_uiDrawTextFormat & g_EPrefixMASK ) == 
		( DT_NOPREFIX ) ){
		rv = NOPREFIX  ;
//	}	else if ( ( m_uiDrawTextFormat & g_EPrefixMASK ) == 
//		( DT_HIDEPREFIX ) ){
//		rv = HIDEPREFIX   ;
//	}	else if ( ( m_uiDrawTextFormat & g_EPrefixMASK ) == 
//		( DT_PREFIXONLY ) ){
//		rv = PREFIXONLY    ;
	}
	return ( rv ) ;
}

CdDrawTextFormat&
CdDrawTextFormat::setPrefix( CdDrawTextFormat::EPrefix ev )
{
	m_uiDrawTextFormat &=~ g_EPrefixMASK  ;
	if ( ev == NOPREFIX  ){
		m_uiDrawTextFormat |= ( DT_NOPREFIX ) ;
//	}	else if ( ev == HIDEPREFIX ){
//		m_uiDrawTextFormat |= ( DT_HIDEPREFIX ) ;
//	}	else if ( ev == PREFIXONLY ){
//		m_uiDrawTextFormat |= ( DT_PREFIXONLY ) ;
	}
	return ( *this ) ;
}


UINT CdDrawTextFormat::getDrawTextFormat()const 
{
	return ( m_uiDrawTextFormat ) ;
}
CdDrawTextFormat& CdDrawTextFormat::setDrawTextFormat( UINT uiFormat ) 
{
	m_uiDrawTextFormat = uiFormat ;
	return ( *this ) ;
}
