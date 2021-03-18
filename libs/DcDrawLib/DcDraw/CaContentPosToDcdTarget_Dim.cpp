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
// $Id: CaContentPosToDcdTarget_Dim.cpp 321 2016-06-12 01:42:37Z okm $
// ****************************************************************
*/

#include "DcDraw\CaContentPosToDcdTarget_Dim.h"

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CaContentPosToDcdTarget_Dim
// ****************************************************************
	// ********************************
	//	�R���X�g���N�^
	// ********************************
CaContentPosToDcdTarget_Dim::CaContentPosToDcdTarget_Dim(
		DcdSize sizeDcdMargin )
	: m_sizeDcdMargin( sizeDcdMargin )
{
}



	// ********************************
	//@name CconvContentPosToDcdTarget-����
	// ********************************
CconvContentPosToTarget::EMode	
CaContentPosToDcdTarget_Dim::getMode()const 
{
	return getCconvContentPosToTarget()->getMode() ;
}
void CaContentPosToDcdTarget_Dim::setMode( 
	CconvContentPosToTarget::EMode	value ) 
{
	getCconvContentPosToTarget()->setMode( value ) ;
}

DcdPos	CaContentPosToDcdTarget_Dim::getContentPos()const 
{
	return getCconvContentPosToTarget()->getContentPos() ;
}
void CaContentPosToDcdTarget_Dim::setContentPos( DcdPos value ) 
{
	getCconvContentPosToTarget()->setContentPos( value ) ;
}

double CaContentPosToDcdTarget_Dim::getTargetPosPerContent()const 
{
	return getCconvContentPosToTarget()->getTargetPosPerContent() ;
}

DcdSize	CaContentPosToDcdTarget_Dim::getContentSize()const 
{
	return getCconvContentPosToTarget()->getContentSize() ;
}
	
	// ********************************
	//@name TargetPosPerContent-TargetPosPerContent,ContentSize �擾�E�ݒ�
	// ********************************
double CaContentPosToDcdTarget_Dim::getTargetPosPerContent( 
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone* pZone = NULL ;
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
		pZone = &aZone ;
	}
	return getCconvContentPosToTarget()->getTargetPosPerContent(pZone) ;
}

void CaContentPosToDcdTarget_Dim::setTargetPosPerContent( double value , 
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone* pZone = NULL ;
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
		pZone = &aZone ;
	}
	return getCconvContentPosToTarget()->setTargetPosPerContent(value , pZone) ;
}

DcdSize CaContentPosToDcdTarget_Dim::getContentSize( 
	IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone* pZone = NULL ;
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
		pZone = &aZone ;
	}
	return getCconvContentPosToTarget()->getContentSize( pZone) ;
}

void CaContentPosToDcdTarget_Dim::setContentSize( 
	DcdSize value , IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone* pZone = NULL ;
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
		pZone = &aZone ;
	}
	getCconvContentPosToTarget()->setContentSize( value , pZone) ;
}

void CaContentPosToDcdTarget_Dim::setContentPosAndRate( 
		DcdPos posContentPos , 
		double dTargetPosPerContent ,
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone* pZone = NULL ;
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
		pZone = &aZone ;
	}
	getCconvContentPosToTarget()->setContentPosAndRate( posContentPos , dTargetPosPerContent , pZone) ;
}

CdDcdZone CaContentPosToDcdTarget_Dim::getContentZone( 
	IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone* pZone = NULL ;
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
		pZone = &aZone ;
	}
	return getCconvContentPosToTarget()->getContentZone( pZone) ;
}

void CaContentPosToDcdTarget_Dim::setContentZone( 
	const CdDcdZone& zoneContent , 
	IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone* pZone = NULL ;
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
		pZone = &aZone ;
	}
	return getCconvContentPosToTarget()->setContentZone( zoneContent , pZone) ;
}


	// ********************************
	//@name CconvContentPosToTarget-���W�ϊ�
	// ********************************
DcdPos	CaContentPosToDcdTarget_Dim::ContentPosToTarget( 
		DcdPos posContent , IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
	}
	return getCconvContentPosToTarget()->ContentPosToTarget( posContent , aZone) ;
}

CdDcdZone	CaContentPosToDcdTarget_Dim::ContentZoneToTarget( 
		const CdDcdZone& zoneContent , IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
	}
	return getCconvContentPosToTarget()->ContentZoneToTarget( zoneContent , aZone) ;
}

DcdPos	CaContentPosToDcdTarget_Dim::ContentPosFromTarget( 
		DcdPos posTarget , IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
	}
	return getCconvContentPosToTarget()->ContentPosFromTarget( posTarget , aZone) ;
}

CdDcdZone	CaContentPosToDcdTarget_Dim::ContentZoneFromTarget( 
		const CdDcdZone& zoneTarget , IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZone aZone  ;
	if ( pIfDcdTarget != NULL )
	{
		aZone = calcCdDcdZone( pIfDcdTarget ) ;
	}
	return getCconvContentPosToTarget()->ContentZoneFromTarget( zoneTarget , aZone) ;
}
	// ********************************
	//@name CconvContentPosToTarget_Dim-�֘A
	// ********************************

CconvContentPosToTarget* 
CaContentPosToDcdTarget_Dim::getCconvContentPosToTarget() 
{
	return getCconvContentPosToTarget() ;
}

	// ********************************
	//@name CaContentPosToDcdTarget_Dim-����
	// ********************************
DcdSize CaContentPosToDcdTarget_Dim::getDcdMargin()const 
{
	return m_sizeDcdMargin ;
}
void CaContentPosToDcdTarget_Dim::setDcdMargin(DcdSize value ) 
{
	m_sizeDcdMargin = value ;
}

} //namespace DcDraw
} //namespace DcDrawLib
