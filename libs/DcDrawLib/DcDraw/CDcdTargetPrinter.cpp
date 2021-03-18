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
// ****************************************************************
//	CDcdTargetPrinter.cpp
// ****************************************************************
*/
#include "CDcdTargetPrinter.h"
#include "DcDraw/CConverter_WinGdi.h"
#include "logmsg/LogMsg.h"

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CDcdTargetPrinter
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CDcdTargetPrinter::CDcdTargetPrinter( HDC hDc ) 
{
	m_hDc = hDc ;

	CdDcdZoneXy	zonePixel ;
	CdDcdZoneXy	zoneLogical ;
	{	
		zonePixel.setX( CdDcdZone( 0 , GetDeviceCaps( hDc , HORZRES ) ) ).
				setY( CdDcdZone( 0, GetDeviceCaps( hDc , VERTRES ) ) );
		zoneLogical = zonePixel ;
		{
			HDC	hdcDisplay = ::GetDC( NULL ) ;

			int iX = zoneLogical.getX().getSize() ;
			iX *= GetDeviceCaps( hdcDisplay , LOGPIXELSX ) ; 
			iX /= GetDeviceCaps( hDc , LOGPIXELSX ) ; 

			int iY = zoneLogical.getY().getSize() ;
			iY *= GetDeviceCaps( hdcDisplay , LOGPIXELSY ) ; 
			iY /= GetDeviceCaps( hDc , LOGPIXELSY ) ; 

			zoneLogical.setX( CdDcdZone( 0 , iX ) ).
				setY( CdDcdZone( 0 , iY ) );
			::ReleaseDC( NULL , hdcDisplay ) ;
		}
		{
			SetMapMode( hDc , MM_ANISOTROPIC);
		    SetWindowExtEx( hDc , 
				zoneLogical.getX().getSize() , 
				zoneLogical.getY().getSize() , 
				NULL );   // ���̘_���T�C�Y�̎w��
		    SetWindowOrgEx( hDc , 
				zoneLogical.getX().getPos() , 
				zoneLogical.getY().getPos() , 
				NULL );   // ���̘_���T�C�Y�̎w��
		    SetViewportExtEx( hDc , 
				zonePixel.getX().getSize() , 
				zonePixel.getY().getSize() , 
				NULL );   //�f�o�C�X�T�C�Y�ő��̃T�C�Y�̎w��
		    SetViewportOrgEx( hDc , 
				zonePixel.getX().getPos() , 
				zonePixel.getY().getPos() ,
				NULL  );	//�f�o�C�X�T�C�Y�Ō��_�̎w��

			LogMsg( "PrinterDC\n%s\n" , DeviceCapsToString( hDc ).c_str() ) ;
	
		}
	}

	m_zonePixel = zonePixel ;
	m_zoneLogical = zoneLogical ;
}
	
CDcdTargetPrinter::~CDcdTargetPrinter() 
{
}

// ********************************
//@name	IfDcdTarget
// ********************************
HDC	CDcdTargetPrinter::getHdc() 
{
	return ( m_hDc ) ;
}
	
CdDcdZoneXy CDcdTargetPrinter::getZone() 
{
	return ( m_zoneLogical ) ;
}
	
CdDcdZoneXy CDcdTargetPrinter::getDrawableZone() 
{
	return ( m_zoneLogical ) ;
}



Ou<CGdiHFontHolder>	CDcdTargetPrinter::createGdiHFontHolder(  const CdFontProp& aCdFontProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHFontHolder( aCdFontProp , m_hDc ) ;
}
	
Ou<CGdiHPenHolder> CDcdTargetPrinter::createGdiHPenHolder(  const CdPenProp& aCdPenProp )
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHPenHolder( aCdPenProp ) ;
}

Ou<CGdiHBrushHolder> CDcdTargetPrinter::createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHBrushHolder( aCdBrushProp ) ;
}
} //namespace DcDraw
} //namespace DcDrawLib
