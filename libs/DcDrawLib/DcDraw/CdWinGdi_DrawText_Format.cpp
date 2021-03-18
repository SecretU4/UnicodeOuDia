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


(��: 

	OuDia - ��Ԏ����\�����ƂɁA�_�C���O������`�悷��Win32�A�v���P�[�V
�����B

Copyright (C) 2006-2017 take-okm 

���̃v���O�����̓t���[�\�t�g�E�F�A�ł��B���Ȃ��͂�����A�t���[�\�t�g�E�F�A��
�c�ɂ���Ĕ��s���ꂽGNU ��ʌ��O���p������(�o�[�W����3���A����ȍ~�̃o�[�W��
���̂����ǂꂩ)����߂�����̉��ōĔЕz�܂��͉��� ���邱�Ƃ��ł��܂��B

���̃v���O�����͗L�p�ł��邱�Ƃ�����ĔЕz����܂����A*�S���̖��ۏ� *�ł��B
���Ɖ\���̕ۏ؂����ړI�ւ̓K�����́A���O�Ɏ����ꂽ���̂� �܂߁A�S������
���܂���B�ڂ�����GNU ��ʌ��O���p���������������������B

���Ȃ��͂��̃v���O�����Ƌ��ɁAGNU ��ʌ��O���p�������̃R�s�[���ꕔ �󂯎��
�Ă���͂��ł��B�����󂯎���Ă��Ȃ���΁A<http://www.gnu.org/licenses/> ��
�������������B

)

  �����āA���ʂȗ�O�Ƃ��āAtake-okm �͂��̃v���O�����̃R�[�h�� 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  ���邢�� "MFC Version 9.0" �Ɠ������C�Z���X���K�p���ꂽ
  "MFC Version 9.0" �̉��ς��ꂽ�o�[�W����)�ƃ����N���A
  �����N���ꂽ���҂��܂ތ������앨��Еz���鋖��^���܂��B
  ���Ȃ��� "MFC" �ȊO�Ŏg���Ă��邷�ׂ�
  �̃R�[�h�Ɋւ��Ă͑S�ʓI��GNU��ʌ��O���p�����_�񏑂ɏ]��Ȃ����
  �Ȃ�܂���B���Ȃ������̃t�@�C�������ς����Ȃ�΁A���Ȃ��͂��̗�O
  �����Ȃ��̃o�[�W�����̃t�@�C���Ɉ��������݂��邱�Ƃ��ł��܂����A��
  ������`���͂���܂���B������O��݂������Ȃ���΁A���̗�O������
  ���Ȃ��̃o�[�W��������͍폜���Ă��������B)
*/
/*
//****************************************************************
//	CdWinGdi_DrawText_Format.cpp
//****************************************************************
*/
#include "CdWinGdi_DrawText_Format.h"

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CdWinGdi_DrawText_Format
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CdWinGdi_DrawText_Format::CdWinGdi_DrawText_Format( UINT uiFormat ) : 
	m_uiDrawTextFormat( uiFormat )
{
} ;

CdWinGdi_DrawText_Format::CdWinGdi_DrawText_Format( 
		EHolizontal eHolizontal ,
		EVertical eVertical ,
		EClipping eClipping ,
		EEditControl eEditControl ,
		EEllipses eEllipses ,
		int iTabstop ,
		EExternalLeading eExternalLeading ,
		EReading eReading ,
		EPrefix ePrefix ,
		ECalcrect eCalcrect ,
		EModifystring eModifystring  )
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
	setCalcrect( eCalcrect );
	setModifystring( eModifystring ) ;
} ;


// ********************************
//	CdWinGdi_DrawText_Format
// ********************************
const UINT g_HorizontalMASK = 
	( DT_LEFT | DT_CENTER | DT_RIGHT ) ;
CdWinGdi_DrawText_Format::EHolizontal 
CdWinGdi_DrawText_Format::getHorizontal()const
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

CdWinGdi_DrawText_Format& 
CdWinGdi_DrawText_Format::setHorizontal( 
	CdWinGdi_DrawText_Format::EHolizontal ev )
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

CdWinGdi_DrawText_Format::EVertical 
CdWinGdi_DrawText_Format::getVertical()const
{
	EVertical rv = V_MULTILINE ;
	if ( ( m_uiDrawTextFormat & g_VerticalMASK ) == 
		( DT_SINGLELINE | DT_TOP ) ){
		rv = V_SINGLELINE_TOP ;
	}	else if ( ( m_uiDrawTextFormat & g_VerticalMASK ) == 
		( DT_SINGLELINE | DT_VCENTER ) ){
		rv = V_SINGLELINE_CENTER ;
	}	else if ( ( m_uiDrawTextFormat & g_VerticalMASK ) == 
		( DT_SINGLELINE | DT_BOTTOM ) ){
		rv = V_SINGLELINE_BOTTOM ;
//	}	else if ( ( m_uiDrawTextFormat & g_VerticalMASK ) == 
//		( DT_WORDBREAK | DT_NOFULLWIDTHCHARBREAK ) ){
//		rv = V_NOFULLWIDTHCHARBREAK ;
	}	else if ( ( m_uiDrawTextFormat & g_VerticalMASK ) ==  
		( DT_WORDBREAK ) ){
		rv = V_MULTILINE_WORDBREAK  ;
	}
	return ( rv ) ;
};

CdWinGdi_DrawText_Format& 
CdWinGdi_DrawText_Format::setVertical( 
	CdWinGdi_DrawText_Format::EVertical ev )
{
	m_uiDrawTextFormat &=~g_VerticalMASK ;

	if ( ev == V_SINGLELINE_TOP ){
		m_uiDrawTextFormat |= ( DT_SINGLELINE | DT_TOP ) ;
	}	else if ( ev == V_SINGLELINE_CENTER ){
		m_uiDrawTextFormat |= ( DT_SINGLELINE | DT_VCENTER ) ;
	}	else if ( ev == V_SINGLELINE_BOTTOM ){
		m_uiDrawTextFormat |= ( DT_SINGLELINE | DT_BOTTOM ) ;
	}	else if ( ev == V_MULTILINE_WORDBREAK ){
		m_uiDrawTextFormat |= ( DT_WORDBREAK ) ;
//	}	else if ( ev == V_NOFULLWIDTHCHARBREAK ){
//		m_uiDrawTextFormat |= ( DT_WORDBREAK | DT_NOFULLWIDTHCHARBREAK ) ;
	}
	return ( *this ) ;
};

const UINT g_ClipMASK = ( DT_NOCLIP ) ;

CdWinGdi_DrawText_Format::EClipping 
CdWinGdi_DrawText_Format::getClipping()const
{
	EClipping rv = C_CLIP ;
	if ( ( m_uiDrawTextFormat & g_ClipMASK ) == 
		( DT_NOCLIP ) ){
		rv = C_NOCLIP ;
	}
	return ( rv ) ;
};

CdWinGdi_DrawText_Format& 
CdWinGdi_DrawText_Format::setClipping( 
	CdWinGdi_DrawText_Format::EClipping ev )
{
	m_uiDrawTextFormat &=~ g_ClipMASK ;

	if ( ev == C_NOCLIP ){
		m_uiDrawTextFormat |= ( DT_NOCLIP ) ;
	}
	return ( *this ) ;
};

const UINT g_EditControlMASK = ( DT_EDITCONTROL ) ;

CdWinGdi_DrawText_Format::EEditControl 
CdWinGdi_DrawText_Format::getEditControl()const
{
	EEditControl rv = NOEDITCONTROL ;
	if ( ( m_uiDrawTextFormat & g_EditControlMASK ) == 
		( DT_EDITCONTROL ) ){
		rv = EDITCONTROL ;
	}
	return ( rv ) ;
};

CdWinGdi_DrawText_Format& 
CdWinGdi_DrawText_Format::setEditControl( 
	CdWinGdi_DrawText_Format::EEditControl ev )
{
	m_uiDrawTextFormat &=~ g_EditControlMASK ;

	if ( ev == EDITCONTROL ){
		m_uiDrawTextFormat |= ( DT_EDITCONTROL ) ;
	}
	return ( *this ) ;
};

const UINT g_EllipsesMASK = 
	( DT_END_ELLIPSIS | DT_PATH_ELLIPSIS | DT_WORD_ELLIPSIS ) ;

CdWinGdi_DrawText_Format::EEllipses 
CdWinGdi_DrawText_Format::getEllipses()const
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

CdWinGdi_DrawText_Format&
CdWinGdi_DrawText_Format::setEllipses( 
	CdWinGdi_DrawText_Format::EEllipses ev )
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

int CdWinGdi_DrawText_Format::getTabStop()const
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

CdWinGdi_DrawText_Format&
CdWinGdi_DrawText_Format::setTabStop( int ev )
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

CdWinGdi_DrawText_Format::EExternalLeading
CdWinGdi_DrawText_Format::getExternalLeading()const
{
	EExternalLeading	rv = NOEXTERNALLEADING  ;
	if ( ( m_uiDrawTextFormat & g_ExternalLeadingMASK ) == 
		( DT_EXTERNALLEADING ) ){
		rv = EXTERNALLEADING ;
	}
	return ( rv ) ;
}

CdWinGdi_DrawText_Format&
CdWinGdi_DrawText_Format::setExternalLeading( 
	CdWinGdi_DrawText_Format::EExternalLeading ev )
{
	m_uiDrawTextFormat &=~ g_ExternalLeadingMASK  ;
	if ( ev == EXTERNALLEADING ){
		m_uiDrawTextFormat |= ( DT_EXTERNALLEADING ) ;
	}
	return ( *this ) ;
}

const UINT g_EReadingMASK = 
	( DT_RTLREADING ) ;

CdWinGdi_DrawText_Format::EReading
CdWinGdi_DrawText_Format::getReading()const
{
	EReading	rv = R_LEFT  ;
	if ( ( m_uiDrawTextFormat & g_EReadingMASK ) == 
		( DT_RTLREADING ) ){
		rv = R_RIGHT ;
	}
	return ( rv ) ;
}

CdWinGdi_DrawText_Format&
CdWinGdi_DrawText_Format::setReading( 
	CdWinGdi_DrawText_Format::EReading ev )
{
	m_uiDrawTextFormat &=~ g_EReadingMASK  ;
	if ( ev == R_RIGHT ){
		m_uiDrawTextFormat |= ( DT_RTLREADING ) ;
	}
	return ( *this ) ;
}

const UINT g_EPrefixMASK = 
	( DT_NOPREFIX  
	| DT_HIDEPREFIX		//���̃t���O�����p�\��Windows��
						//	�o�[�W�����͌��肳��܂��BWindows 2000/XP
	| DT_PREFIXONLY		//���̃t���O�����p�\��Windows��
						//�o�[�W�����͌��肳��܂��BWindows 2000/XP
	) ;

CdWinGdi_DrawText_Format::EPrefix
CdWinGdi_DrawText_Format::getPrefix()const
{
	EPrefix	rv = NORMAL_PREFIX  ;
	if ( ( m_uiDrawTextFormat & g_EPrefixMASK ) == 
		( DT_NOPREFIX ) ){
		rv = NOPREFIX  ;
	}	else if ( ( m_uiDrawTextFormat & g_EPrefixMASK ) == 
		( DT_HIDEPREFIX ) ){
		rv = HIDEPREFIX   ;
	}	else if ( ( m_uiDrawTextFormat & g_EPrefixMASK ) == 
		( DT_PREFIXONLY ) ){
		rv = PREFIXONLY    ;
	}
	return ( rv ) ;
}

CdWinGdi_DrawText_Format&
CdWinGdi_DrawText_Format::setPrefix( CdWinGdi_DrawText_Format::EPrefix ev )
{
	m_uiDrawTextFormat &=~ g_EPrefixMASK  ;
	if ( ev == NOPREFIX  ){
		m_uiDrawTextFormat |= ( DT_NOPREFIX ) ;
	}	else if ( ev == HIDEPREFIX ){
		m_uiDrawTextFormat |= ( DT_HIDEPREFIX ) ;
	}	else if ( ev == PREFIXONLY ){
		m_uiDrawTextFormat |= ( DT_PREFIXONLY ) ;
	}
	return ( *this ) ;
}



const UINT g_ECalcrectMASK = 
	( DT_CALCRECT | DT_INTERNAL ) ;

CdWinGdi_DrawText_Format::ECalcrect
CdWinGdi_DrawText_Format::getCalcrect()const
{
	ECalcrect	rv = NOCALCRECT ;
	if ( ( getFormat() & g_ECalcrectMASK ) == 
		( DT_CALCRECT ) ){
		rv = CALCRECT   ;
	}	else if ( ( getFormat() & g_ECalcrectMASK ) == 
		( DT_CALCRECT | DT_INTERNAL ) ){
		rv = CALCRECT_INTERNAL    ;
	}
	return ( rv ) ;
}

CdWinGdi_DrawText_Format&
CdWinGdi_DrawText_Format::setCalcrect( 
	CdWinGdi_DrawText_Format::ECalcrect ev )
{
	setFormat( getFormat() &~ g_ECalcrectMASK ) ;
	if ( ev == CALCRECT ){
		setFormat( getFormat() | ( DT_CALCRECT ) );
	}	else if ( ev == CALCRECT_INTERNAL ){
		setFormat( getFormat() | ( DT_CALCRECT | DT_INTERNAL ) ) ;
	}
	return ( *this ) ;
}

const UINT g_EModifystringMASK = 
	( DT_MODIFYSTRING ) ;

CdWinGdi_DrawText_Format::EModifystring
CdWinGdi_DrawText_Format::getModifystring()const
{
	EModifystring	rv = NOMODIFYSTEING ;
	if ( ( getFormat() & g_EModifystringMASK ) == 
		( DT_MODIFYSTRING ) ){
		rv = MODIFYSTRING    ;
	}
	return ( rv ) ;
}

CdWinGdi_DrawText_Format&
CdWinGdi_DrawText_Format::setModifystring( 
	CdWinGdi_DrawText_Format::EModifystring ev )
{
	setFormat( getFormat() &~ g_EModifystringMASK ) ;
	if ( ev == MODIFYSTRING ){
		setFormat( getFormat() | ( DT_MODIFYSTRING ) ) ;
	}
	return ( *this ) ;
}


UINT CdWinGdi_DrawText_Format::getFormat()const 
{
	return ( m_uiDrawTextFormat ) ;
}
CdWinGdi_DrawText_Format& 
CdWinGdi_DrawText_Format::setFormat( UINT uiFormat ) 
{
	m_uiDrawTextFormat = uiFormat ;
	return ( *this ) ;
}

} //namespace DcDraw
} //namespace DcDrawLib


