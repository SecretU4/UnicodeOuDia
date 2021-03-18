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
//	CDcdTextbox.cpp
// ****************************************************************
*/
#include "CDcdTextbox.h"
#include "CaDcdTargetItemPosition.h"

namespace DcDrawLib{
namespace DcDraw{

// ********************************
//	�R���X�g���N�^
// ********************************
CDcdTextbox::CDcdTextbox( 
		const tstring&			strText  ,
		const CdDrawTextProp&	aCdDrawTextProp  ,
		const tstring&			strExtent  ,
		int						iLinesExtent  ,
		int						logicalunitFrameWidth   ,
		int						logicalunitFrameHeight   ,
		const CdPenProp&		aCdPenProp ,
		const CdBrushProp& 		aCdBrushProp )
	: m_CDcdFillrect( aCdBrushProp ) 
	, m_CDcdRectangle(  aCdPenProp ) 
	, m_CDcdText( strText , aCdDrawTextProp , strExtent , iLinesExtent )
	, m_logicalunitFrameWidth( logicalunitFrameWidth )
	, m_logicalunitFrameHeight( logicalunitFrameHeight )
{
}


CDcdTextbox::CDcdTextbox( 
		const CdPenProp&		aCdPenProp ,
		int						logicalunitFrameWidth ,
		int						logicalunitFrameHeight ,
		const tstring&			strText ,
		const CdDrawTextProp&	aCdDrawTextProp ,
		const tstring&			strExtent ,
		int				iLinesExtent ,
		const CdBrushProp& 		aCdBrushProp 
	) 
	: m_CDcdFillrect( aCdBrushProp ) 
	, m_CDcdRectangle(  aCdPenProp ) 
	, m_CDcdText( strText , aCdDrawTextProp , strExtent , iLinesExtent )
	, m_logicalunitFrameWidth( logicalunitFrameWidth )
	, m_logicalunitFrameHeight( logicalunitFrameHeight )
{
}

CDcdTextbox::CDcdTextbox() 
	: m_logicalunitFrameWidth( 0 )
	, m_logicalunitFrameHeight( 0 )
{
}
	
CDcdTextbox::~CDcdTextbox() 
{
}

// ********************************
//	IfDcDraw
// ********************************
bool CDcdTextbox::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool	bRv = false ;

	{
		if ( m_CDcdFillrect.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}
	{
		if ( m_CDcdRectangle.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}


	{
		CdDcdZoneXy	aCdDcdZoneXy( pIfDcdTarget->getZone() ) ;
		aCdDcdZoneXy.setX( CdDcdZone( 
			aCdDcdZoneXy.getX().getPos() + m_logicalunitFrameWidth , 
			aCdDcdZoneXy.getX().getSize() - m_logicalunitFrameWidth * 2 )
			)  ;
		aCdDcdZoneXy.setY( CdDcdZone( 
			aCdDcdZoneXy.getY().getPos() + m_logicalunitFrameHeight , 
			aCdDcdZoneXy.getY().getSize() - m_logicalunitFrameHeight * 2 )
			)  ;
		CaDcdTargetItemPosition	aTarget( pIfDcdTarget ,  aCdDcdZoneXy ) ;
		if ( m_CDcdText.DcDraw( &aTarget ) ) {
			bRv = true ;
		}
	}
	return ( bRv ) ;
}
	
bool CDcdTextbox::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	bool	bRv = m_CDcdText.getItemSize( pIfDcdTarget , pCdDcdSizeXy ) ;
	if ( !bRv ){
		return ( false ) ;
	}
	pCdDcdSizeXy->setX( pCdDcdSizeXy->getX() + m_logicalunitFrameWidth * 2 ) ;
	pCdDcdSizeXy->setY( pCdDcdSizeXy->getY() + m_logicalunitFrameHeight * 2 ) ;
	return ( true ) ;
}

} //namespace DcDraw
} //namespace DcDrawLib
