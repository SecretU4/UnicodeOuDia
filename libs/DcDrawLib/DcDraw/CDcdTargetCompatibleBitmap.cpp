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
//	CDcdTargetCompatibleBitmap.cpp
// ****************************************************************
*/
#include "CDcdTargetCompatibleBitmap.h"
#include "CConverter_WinGdi.h"

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CDcdTargetCompatibleBitmap
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CDcdTargetCompatibleBitmap::CDcdTargetCompatibleBitmap( 
	const CdDcdSizeXy& aCdDcdSizeXy , HDC hDc ) 
{
	m_hDc = NULL ;
	m_hBitmap = NULL ;
	m_hBitmapSid = NULL ;
	resetSize( aCdDcdSizeXy , hDc ) ;
}
CDcdTargetCompatibleBitmap::CDcdTargetCompatibleBitmap() 
{
	m_hDc = NULL ;
	m_hBitmap = NULL ;
	m_hBitmapSid = NULL ;
}

CDcdTargetCompatibleBitmap::~CDcdTargetCompatibleBitmap() 
{
	resetSize( CdDcdSizeXy( 0 , 0 )  , NULL ) ;
}
	
	
// ********************************
//	IfDcdTarget
// ********************************
HDC	CDcdTargetCompatibleBitmap::getHdc() 
{
	return ( m_hDc ) ;
}

CdDcdZoneXy CDcdTargetCompatibleBitmap::getZone() 
{
	return ( CdDcdZoneXy( CdDcdPosXy( 0 , 0 ) , m_CdDcdSizeXy ) ) ;
}
	
CdDcdZoneXy CDcdTargetCompatibleBitmap::getDrawableZone() 
{
	return ( CdDcdZoneXy( CdDcdPosXy( 0 , 0 ) , m_CdDcdSizeXy ) ) ;
}


Ou<CGdiHFontHolder>	CDcdTargetCompatibleBitmap::createGdiHFontHolder(  const CdFontProp& aCdFontProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHFontHolder( aCdFontProp , m_hDc ) ;
}
	
Ou<CGdiHPenHolder> CDcdTargetCompatibleBitmap::createGdiHPenHolder(  const CdPenProp& aCdPenProp )
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHPenHolder( aCdPenProp  ) ;
}

Ou<CGdiHBrushHolder> CDcdTargetCompatibleBitmap::createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) 
{
	CConverter_WinGdi	aConv ;
	return aConv.createGdiHBrushHolder( aCdBrushProp  ) ;
}

// ********************************
//	CDcdTargetCompatibleBitmap
// ********************************
CdDcdSizeXy CDcdTargetCompatibleBitmap::getSize() 
{
	return ( m_CdDcdSizeXy ) ;
}
	
int CDcdTargetCompatibleBitmap::resetSize( 
		const CdDcdSizeXy& aCdDcdSizeXy , HDC hDc ) 
{
	int	iRv = 0 ;
	// ********************************
	//	������DC�EBITMAP��j��
	// ********************************
	if ( iRv == 0 ){
		m_CdDcdSizeXy.setX( 0 ).setY( 0 ) ;

		if ( m_hBitmapSid != NULL ){
			SelectObject( m_hDc , m_hBitmapSid ) ;
			m_hBitmapSid = NULL ;
		}	
		if ( m_hBitmap != NULL ){
			DeleteObject( m_hBitmap ) ;
			m_hBitmap = NULL ;
		}
		if ( m_hDc != NULL ){
			DeleteDC( m_hDc ) ;
			m_hDc = NULL ;
		}
	}
	// ********************************
	//	�V����DC�EBITMAP���쐬
	// ********************************
	if ( aCdDcdSizeXy.getX() > 0 && aCdDcdSizeXy.getY() > 0 ){
		bool	bhDcDeleteObligatory = false ;
		if ( hDc == NULL ){
			hDc = GetDC( NULL ) ;
			bhDcDeleteObligatory = true ;
		}

		if ( iRv == 0 ){
			m_hDc = CreateCompatibleDC( hDc ) ;
			if ( m_hDc == NULL ){
				iRv = -1 ;	//	DC�̍쐬�Ɏ��s���܂���
			}
		}	
		if ( iRv == 0 ){
			m_hBitmap = CreateCompatibleBitmap( hDc , aCdDcdSizeXy.getX() , aCdDcdSizeXy.getY() ) ;
			if ( m_hBitmap == NULL ){
				iRv = -2 ;	//	BITMAP�̍쐬�Ɏ��s���܂���
			}
			
		}
		if ( iRv == 0 ){
			m_hBitmapSid = (HBITMAP)SelectObject( m_hDc , m_hBitmap ) ;
		}
		if ( iRv == 0 ){
			m_CdDcdSizeXy = aCdDcdSizeXy ;
		}	
		// --------------------------------
		if ( bhDcDeleteObligatory ){
			ReleaseDC( NULL , hDc ) ;
			hDc = NULL ;
		}
	}	
	
	return ( iRv ) ;
}

} //namespace DcDraw
} //namespace DcDrawLib





