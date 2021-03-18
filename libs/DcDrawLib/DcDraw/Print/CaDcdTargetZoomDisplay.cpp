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
//	CaDcdTargetZoomDisplay.cpp
// ****************************************************************
*/
#include "CaDcdTargetZoomDisplay.h"
#include "DcDraw/CConverter_WinGdi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcDraw{
namespace Print{


// ****************************************************************
//	CaDcdTargetZoomDisplay
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CaDcdTargetZoomDisplay::CaDcdTargetZoomDisplay( 
		IfDcdTarget* pTarget ,
		HDC	hPrinterHdc ) :
	m_pTarget( pTarget ),
	m_hPrinterHdc( hPrinterHdc ) ,
	m_iSaveDcId( 0 ) 
{
	CConverter_WinGdi	aConverter ;

	// --------------------------------
	//	DC�̏�Ԃ�Ҕ�
	// --------------------------------
	m_iSaveDcId = SaveDC( m_pTarget->getHdc() ) ;

	// --------------------------------
	HDC	hDcTarget = m_pTarget->getHdc() ;
	HDC	hDcPrinter = m_hPrinterHdc ;

	//hDcTarget = �v�����^/����v���r���[�E�C���h�E��DC
	//hDcPrinter = �v�����^��DC�ł��B
	//	����́A�X�P�[���l�����߂�̂Ɏg���܂��B

	// --------------------------------
	//	�`���DC����
	//	�`�悪�ł���̈���擾
	// --------------------------------
	CdDcdZoneXy	zoneLogical ;
	CdDcdZoneXy	zoneDevice ;
	{
		zoneLogical = m_pTarget->getZone() ;
		zoneDevice = aConverter.LPtoDP( zoneLogical , hDcTarget ) ;
	}		
	//zoneLogical = �`���DC��ł́A�`��̈�(�_�����W)
	//zoneDevice = �`���DC��ł́A�`��̈�(�f�o�C�X���W)
	
	// --------------------------------
	//	�^�[�Q�b�g��DC�̍��W�n��ύX
	// --------------------------------
	{
		CdDcdZoneXy	zoneZoomLogical ;
		CdDcdZoneXy	zoneZoomDevice ;

	
		int iMapMode = GetMapMode( hDcTarget ) ;
		if ( iMapMode == MM_TEXT ){
			zoneZoomDevice.setX( CdDcdZone( 0 , GetDeviceCaps( hDcTarget , HORZRES ) ) )
				.setY( CdDcdZone( 0 , GetDeviceCaps( hDcTarget , VERTRES ) ) ) ;
			zoneZoomLogical = zoneZoomDevice ;
			
		}	else	{

			{
				POINT	aPOINT ;
				SIZE	aSIZE ;
				GetWindowExtEx( hDcTarget , &aSIZE ) ;
				GetWindowOrgEx( hDcTarget , &aPOINT ) ;
				zoneZoomLogical.setX( CdDcdZone( aPOINT.x , aSIZE.cx ) ) 
					.setY( CdDcdZone( aPOINT.y , aSIZE.cy ) ) ;
			}
			{
				POINT	aPOINT ;
				SIZE	aSIZE ;
				GetViewportExtEx( hDcTarget , &aSIZE ) ;
				GetViewportOrgEx( hDcTarget , &aPOINT ) ;
				zoneZoomDevice.setX( CdDcdZone( aPOINT.x , aSIZE.cx ) )
					.setY( CdDcdZone( aPOINT.y , aSIZE.cy ) ) ;
			}
			//zoneZoomLogical = �`���DC�̘_�����W�ɂ�����A
			//	���_�l�Ƒ傫���B
			//zoneZoomDevice =  �`���DC�̃f�o�C�X���W�ɂ�����A
			//	���_�l�Ƒ傫���B
			//
			//	�f�o�C�X���W�ɂ�����A
			//	(zoneZoomDeveice.X.Pos,zoneZoomDeveice.Y.Pos) 
			//	�̈ʒu�ɁA�_�����W
			//	(zoneLogical.X.Pos,zoneLogical.Y.Pos)
			//	�����蓖�Ă��Ă��܂��B
			//
			//	�f�o�C�X���W�ɂ�����A
			//	(zoneZoomDeveice.X.Size,zoneZoomDeveice.Y.Size) 
			//	�̑傫�����A�_�����W
			//	(zoneLogical.X.Pos,zoneLogical.Y.Pos)
			//	�̑傫���ɑ������܂��B
			//	
			//	���̒i�K�ł́A
			//
			//	Logical.Size : Device.Size �́A
			//
			//	�v�����^�̂P�y�[�W�̃s�N�Z�����F 
			//		�`���DC�̃s�N�Z����
			//
			//	�ƂȂ�܂��B
		}

		// --------------------------------
		//	�Y�[���v�Z
		//	zoneZoomDevice  zoneZoomLogical �̂����A
		//	�傫�����̒l��ύX���܂��B
		// --------------------------------
		if ( zoneZoomDevice.getX().getSize() < zoneZoomLogical.getX().getSize() ){
			//	�_�����W�̑���ύX
			//	����́A�_�����W�����������Ē������܂��B
			//
			//	�v�����^�v���r���[�̏ꍇ�́A
			//	�f�o�C�X���W�ł̕�  < �_�����W�i�v�����^�̂P�h�b�g����Ƃ������W�j�ł̕�
			//	�ƂȂ�܂��B

			HDC	hdcDisplay = GetDC( NULL ) ;

			int iX = zoneZoomLogical.getX().getSize() ;
			iX *= GetDeviceCaps( hdcDisplay , LOGPIXELSX ) ; 
			iX /= GetDeviceCaps( hDcPrinter , LOGPIXELSX ) ; 

			int iY = zoneZoomLogical.getY().getSize() ;
			iY *= GetDeviceCaps( hdcDisplay , LOGPIXELSY ) ; 
			iY /= GetDeviceCaps( hDcPrinter , LOGPIXELSY ) ; 

			zoneZoomLogical.setSize( CdDcdSizeXy( iX , iY ) ) ;

			ReleaseDC( NULL , hdcDisplay ) ;
		}	else	{
			//	�_�����W�̑���ύX
			//	����́A�f�o�C�X���W��傫�����Ē������܂��B
			//
			//	�v�����^�ւ̈���̏ꍇ�́A
			//	�f�o�C�X���W�ł̕�  > �_�����W
			//	�ƂȂ�܂��B
			
			HDC	hdcDisplay = GetDC( NULL ) ;

			int iX = zoneZoomDevice.getX().getSize() ;
			iX *= GetDeviceCaps( hDcPrinter , LOGPIXELSX ) ; 
			iX /= GetDeviceCaps( hdcDisplay , LOGPIXELSX ) ; 

			int iY = zoneZoomDevice.getY().getSize() ;
			iY *= GetDeviceCaps( hDcPrinter , LOGPIXELSY ) ; 
			iY /= GetDeviceCaps( hdcDisplay , LOGPIXELSY ) ; 

			zoneZoomDevice.setSize( CdDcdSizeXy( iX , iY ) ) ;

			ReleaseDC( NULL , hdcDisplay ) ;

			
		}
		//zoneLogical = 
		//	�_�����W�̑傫�����A CdDcdTargetPrinter �ł̌v�Z����
		//	���킹�Ċ��Z���܂��B
		//	
		//	����́A
		//
		//	�v�����^�̘_���C���`������̃s�N�Z����:
		//		�f�B�X�v���C�̘_���C���`������̃s�N�Z����
		//
		//	�ɏ������v�Z�ƂȂ�܂��B

		// --------------------------------
		{
			//	�^�[�Q�b�gDC�̃}�b�v���[�h�i���W�n�j��ύX
			SetMapMode( hDcTarget , MM_ANISOTROPIC);
		    SetWindowExtEx( hDcTarget , 
				zoneZoomLogical.getX().getSize() , 
				zoneZoomLogical.getY().getSize() , 
				NULL );  
		    SetViewportExtEx( hDcTarget , 
				zoneZoomDevice.getX().getSize() , 
				zoneZoomDevice.getY().getSize() , 
				NULL );  
		}

	}
	// --------------------------------
	//	�v���r���[�E�C���h�E����
	//	�`�悪�ł���̈���A
	//	DC�ɐݒ肵���X�P�[���ɏ]���čČv�Z
	// --------------------------------
	{
		zoneLogical = aConverter.DPtoLP( zoneDevice  , hDcTarget ) ;
	}		
	//zoneLogical = �v���r���[�E�C���h�E���ŕ`��̂ł���̈�(�_�����W)
	//zoneDevice = �v���r���[�E�C���h�E���ŕ`��̂ł���̈�(�f�o�C�X���W)

	// --------------------------------
	m_zonexyZone = zoneLogical ;

	
}

CaDcdTargetZoomDisplay::~CaDcdTargetZoomDisplay() 
{
	if ( m_iSaveDcId != 0 ){
		RestoreDC( m_pTarget->getHdc() , m_iSaveDcId ) ;
		m_iSaveDcId = 0 ;
	}
}

// ********************************
//@name	IfDcdTarget
// ********************************
HDC	CaDcdTargetZoomDisplay::getHdc() 
{
	return ( m_pTarget->getHdc() ) ;
}

CdDcdZoneXy CaDcdTargetZoomDisplay::getZone() 
{
	return ( m_zonexyZone ) ;
}

CdDcdZoneXy CaDcdTargetZoomDisplay::getDrawableZone() 
{
	return ( m_zonexyZone ) ;
}

// ********************************
//	CaDcdTargetZoomDisplay_h
// ********************************
	// ********************************
	//@name �֘A
	// ********************************

} //namespace Print
} //namespace DcDraw
} //namespace DcDrawLib
