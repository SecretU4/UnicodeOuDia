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
//	CDcdFreeLine_StyleSample.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CDcdFreeLine_StyleSample.h"
#include "DcDraw\CDcdFillrect.h"
#include "DcDraw\CConverter_WinGdi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRessyasyubetsu{ 

// ****************************************************************
//	CDcdFreeLine_StyleSample
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CDcdFreeLine_StyleSample::
	CDcdFreeLine_StyleSample( const CdDcdFreeLineProp& aCdLineProp )
	: m_CdLineProp( aCdLineProp ) 
{
}
CDcdFreeLine_StyleSample::CDcdFreeLine_StyleSample() 
{
}

// ********************************
//@name	IfDcDraw
// ********************************
bool CDcdFreeLine_StyleSample::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	zoneTarget = pIfDcdTarget->getZone() ;
	
	// --------------------------------
	//	�w�i�̕`��
	// --------------------------------
	CDcdFillrect aCDcdFillrect( CConverter_WinGdi().CdBrushPropOf( WHITE_BRUSH ) ) ;
	aCDcdFillrect.DcDraw( pIfDcdTarget ) ;

	// --------------------------------
	//	���̕`��
	// --------------------------------
	CdDcdPosXy	posOrg( 
		zoneTarget.getX().getPos() + m_CdLineProp.getLogicalunitWidth() / 2 + 1 ,
		zoneTarget.getY().getPos() + zoneTarget.getY().getSize() / 2 
	) ; 
	CdDcdPosXy	posDst( 
		zoneTarget.getX().getEndPos() - ( m_CdLineProp.getLogicalunitWidth() + 1 ) / 2 - 1 ,
		zoneTarget.getY().getPos() + zoneTarget.getY().getSize() / 2 
	) ; 
	
	CDcdFreeLine	aCDcdFreeLine( posOrg , posDst ,  m_CdLineProp ) ;
	bool bRv = aCDcdFreeLine.DcDraw( pIfDcdTarget ) ;
	return ( bRv ) ;
}
	
bool CDcdFreeLine_StyleSample::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	pCdDcdSizeXy->setX( m_CdLineProp.getLogicalunitWidth() ) ;
	pCdDcdSizeXy->setY( m_CdLineProp.getLogicalunitWidth() ) ;
	return ( true ) ;
}
// ********************************
//	CDcdFreeLine_StyleSample
// ********************************
	// ********************************
	//@name ����
	// ********************************
CdDcdFreeLineProp CDcdFreeLine_StyleSample::getCdLineProp()const 
{
	return m_CdLineProp ;
}
CDcdFreeLine_StyleSample& CDcdFreeLine_StyleSample::setCdLineProp( 
		const CdDcdFreeLineProp& value )
{
	m_CdLineProp = value ;
	return *this ;
};

} //namespace ViewRessyasyubetsu
