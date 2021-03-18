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
//	CconvCdPrintPageProp.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CconvCdPrintPageProp.h"
#include "DcDraw/CDcDeviceUnitSizeX.h"
#include "DcDraw/CDcDeviceUnitSizeY.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace Print{

// ****************************************************************
//	CconvCdPrintPageProp
// ****************************************************************
CdDcdZoneXy CconvCdPrintPageProp::calcZoneInnerMargin( 
		const CdPrintPageProp& aCdPrintPageProp , HDC hDc ) 
{
	int iXMarginFromPhysicalOffset1 = 0 ;
	int iXMarginFromPhysicalOffset2 = 0 ;
	int iXRes = 0 ;
	{
		int iPhysicalPageSize = 0 ;
		int iPhysicalOffset1 = 0 ;
		int iPhysicalOffset2 = 0 ; 
		getPhysicalXPageSize( hDc , 
			&iPhysicalPageSize ,
			&iPhysicalOffset1 ,
			&iXRes ,
			&iPhysicalOffset2 ) ; 


		CDcDeviceUnitSizeX	aDeviceUnit( hDc ) ;

		aDeviceUnit.setMmSize( aCdPrintPageProp.getMarginLeftMm() ) ;
		iXMarginFromPhysicalOffset1 = aDeviceUnit.getDeviceUnitSize() - iPhysicalOffset1 ;
		if ( iXMarginFromPhysicalOffset1 < 0 ){
			iXMarginFromPhysicalOffset1 = 0 ;
		}
		aDeviceUnit.setMmSize( aCdPrintPageProp.getMarginRightMm() ) ;
		iXMarginFromPhysicalOffset2 = aDeviceUnit.getDeviceUnitSize() - iPhysicalOffset2 ;
		if ( iXMarginFromPhysicalOffset2 < 0 ){
			iXMarginFromPhysicalOffset2 = 0 ;
		}
	}
	int iYMarginFromPhysicalOffset1 = 0 ;
	int iYMarginFromPhysicalOffset2 = 0 ;
	int iYRes = 0 ;
	{
		int iPhysicalPageSize = 0 ;
		int iPhysicalOffset1 = 0 ;
		int iPhysicalOffset2 = 0 ; 
		getPhysicalYPageSize( hDc , 
			&iPhysicalPageSize ,
			&iPhysicalOffset1 ,
			&iYRes ,
			&iPhysicalOffset2 ) ; 


		CDcDeviceUnitSizeY	aDeviceUnit( hDc ) ;

		aDeviceUnit.setMmSize( aCdPrintPageProp.getMarginTopMm() ) ;
		iYMarginFromPhysicalOffset1 = aDeviceUnit.getDeviceUnitSize() - iPhysicalOffset1 ;
		if ( iYMarginFromPhysicalOffset1 < 0 ){
			iYMarginFromPhysicalOffset1 = 0 ;
		}
		aDeviceUnit.setMmSize( aCdPrintPageProp.getMarginBottomMm() ) ;
		iYMarginFromPhysicalOffset2 = aDeviceUnit.getDeviceUnitSize() - iPhysicalOffset2 ;
		if ( iYMarginFromPhysicalOffset2 < 0 ){
			iYMarginFromPhysicalOffset2 = 0 ;
		}
	}
	
	CdDcdZoneXy	zonexyInneraMargin( 
		CdDcdZone( iXMarginFromPhysicalOffset1 , 
			iXRes - iXMarginFromPhysicalOffset1 - iXMarginFromPhysicalOffset2 ) ,
		CdDcdZone( iYMarginFromPhysicalOffset1 , 
			iYRes - iYMarginFromPhysicalOffset1 - iYMarginFromPhysicalOffset2 ) ) ;
	
	return ( zonexyInneraMargin ) ;		
}


void CconvCdPrintPageProp::getPhysicalXPageSize( HDC hDc , 
		int* piPhysicalPageSize ,
		int* piPhysicalOffset1 ,
		int* piRes ,
		int* piPhysicalOffset2 ) 
{
	int iPhysicalPageSize = 0 ;
	int iPhysicalOffset1 = 0 ;
	int iRes = 0 ;
	int iPhysicalOffset2 = 0 ; 
	// --------------------------------
	iPhysicalPageSize = GetDeviceCaps( hDc , PHYSICALWIDTH ) ;
	iPhysicalOffset1 = GetDeviceCaps( hDc , PHYSICALOFFSETX ) ;
	iRes = GetDeviceCaps( hDc , HORZRES ) ;
	iPhysicalOffset2 = iPhysicalPageSize - iPhysicalOffset1 - iRes ;
	// --------------------------------
	if ( piPhysicalPageSize != NULL ){
		*piPhysicalPageSize = iPhysicalPageSize ;
	}
	if ( piPhysicalOffset1 != NULL ){
		*piPhysicalOffset1 = iPhysicalOffset1 ;
	}
	if ( piRes != NULL ){
		*piRes = iRes ;
	}
	if ( piPhysicalOffset2 != 0 ){ 
		*piPhysicalOffset2 = iPhysicalOffset2 ;
	} 
}

void CconvCdPrintPageProp::getPhysicalYPageSize( HDC hDc , 
		int* piPhysicalPageSize ,
		int* piPhysicalOffset1 ,
		int* piRes ,
		int* piPhysicalOffset2 ) 
{
	int iPhysicalPageSize = 0 ;
	int iPhysicalOffset1 = 0 ;
	int iRes = 0 ;
	int iPhysicalOffset2 = 0 ; 
	// --------------------------------
	iPhysicalPageSize = GetDeviceCaps( hDc , PHYSICALHEIGHT ) ;
	iPhysicalOffset1 = GetDeviceCaps( hDc , PHYSICALOFFSETY ) ;
	iRes = GetDeviceCaps( hDc , VERTRES ) ;
	iPhysicalOffset2 = iPhysicalPageSize - iPhysicalOffset1 - iRes ;
	// --------------------------------
	if ( piPhysicalPageSize != NULL ){
		*piPhysicalPageSize = iPhysicalPageSize ;
	}
	if ( piPhysicalOffset1 != NULL ){
		*piPhysicalOffset1 = iPhysicalOffset1 ;
	}
	if ( piRes != NULL ){
		*piRes = iRes ;
	}
	if ( piPhysicalOffset2 != 0 ){ 
		*piPhysicalOffset2 = iPhysicalOffset2 ;
	} 
}

} //namespace Print


