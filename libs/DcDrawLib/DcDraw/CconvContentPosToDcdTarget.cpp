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
//	CconvContentPosToDcdTarget.cpp
// ****************************************************************
*/
#include "DcDraw\CconvContentPosToDcdTarget.h"

namespace DcDrawLib{
namespace DcDraw{

	// ********************************
	//	 �����N���X
	// ********************************
	// ****************************************************************
	//	CaConvX
	// ****************************************************************
CdDcdZone CconvContentPosToDcdTarget::CaConvX::calcCdDcdZone( 
	IfDcdTarget* pIfDcdTarget ) 
{
	CconvContentPosToDcdTarget* pOuter = (CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convX) ) ;

	CdDcdZone	zoneRv ;
	if ( pIfDcdTarget != NULL )
	{
		zoneRv = pOuter->calcMarginAppliedZone( pIfDcdTarget ).getX() ;
	}
	return zoneRv ;
}
		// ********************************
		//	�R���X�g���N�^
		// ********************************
CconvContentPosToDcdTarget::CaConvX::CaConvX(
	DcdSize sizeDcdMargin )
	:CaContentPosToDcdTarget_Dim( 
		sizeDcdMargin )
{
}
		// ********************************
		///@name CconvContentPosToTargetDim-�֘A
		// ********************************
CconvContentPosToTarget* 
CconvContentPosToDcdTarget::CaConvX::getCconvContentPosToTarget() 
{
	CconvContentPosToDcdTarget* pOuter = (CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convX) ) ;
	return pOuter->m_CconvContentPosToTargetXy.getX() ;
}
const CconvContentPosToTarget* 
CconvContentPosToDcdTarget::CaConvX::getCconvContentPosToTarget()const  
{
	const CconvContentPosToDcdTarget* pOuter = (const CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convX) ) ;
	return pOuter->m_CconvContentPosToTargetXy.getX() ;
}
	// ****************************************************************
	//	CaConvY
	// ****************************************************************
CdDcdZone CconvContentPosToDcdTarget::CaConvY::calcCdDcdZone( IfDcdTarget* pIfDcdTarget ) 
{
	CconvContentPosToDcdTarget* pOuter = (CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convY) ) ;

	CdDcdZone	zoneRv ;
	if ( pIfDcdTarget != NULL )
	{
		zoneRv = pOuter->calcMarginAppliedZone( pIfDcdTarget ).getY() ;
	}
	return zoneRv ;
}

		// ********************************
		//	�R���X�g���N�^
		// ********************************
CconvContentPosToDcdTarget::CaConvY::CaConvY(
	DcdSize sizeDcdMargin )
	:CaContentPosToDcdTarget_Dim( 
		sizeDcdMargin )
{
}
		// ********************************
		///@name CconvContentPosToTargetDim-�֘A
		// ********************************
CconvContentPosToTarget* 
CconvContentPosToDcdTarget::CaConvY::getCconvContentPosToTarget() 
{
	CconvContentPosToDcdTarget* pOuter = (CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convY) ) ;
	return pOuter->m_CconvContentPosToTargetXy.getY() ;
}
const CconvContentPosToTarget* 
CconvContentPosToDcdTarget::CaConvY::getCconvContentPosToTarget()const  
{
	const CconvContentPosToDcdTarget* pOuter = (const CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convY) ) ;
	return pOuter->m_CconvContentPosToTargetXy.getY() ;
}

// ****************************************************************
//	CconvContentPosToDcdTarget
// ****************************************************************
	// --------------------------------
	//@name �����֐�
	// --------------------------------
CdDcdZoneXy CconvContentPosToDcdTarget::calcMarginAppliedZone( 
	IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	aCdDcdZoneXy = pIfDcdTarget->getZone() ;
	{
		CdDcdZone	zone = aCdDcdZoneXy.getX() ;
		if ( zone.getSize() >  m_convX.getDcdMargin() ){
			zone.setSize( zone.getSize() -  m_convX.getDcdMargin()  ) ;
		} else if ( zone.getSize() < - m_convX.getDcdMargin()  ){
			zone.setSize( zone.getSize() +  m_convX.getDcdMargin()  ) ;
		} else {
			zone.setSize( 0 ) ;
		}
		aCdDcdZoneXy.setX( zone ) ;
	}
	{
		CdDcdZone	zone = aCdDcdZoneXy.getY() ;
		if ( zone.getSize() >  m_convY.getDcdMargin()  ){
			zone.setSize( zone.getSize() - m_convY.getDcdMargin()   ) ;
		} else if ( zone.getSize() < -m_convY.getDcdMargin()   ){
			zone.setSize( zone.getSize() + m_convY.getDcdMargin()   ) ;
		} else {
			zone.setSize( 0 ) ;
		}
		aCdDcdZoneXy.setY( zone ) ;
	}
	return aCdDcdZoneXy ;
}
	///@}
	// ********************************
	//	�R���X�g���N�^
	// ********************************
CconvContentPosToDcdTarget::CconvContentPosToDcdTarget( 
	CconvContentPosToTarget::EMode	eMode ,
	DcdSize	sizeDcdMarginXRight ,
	DcdSize	sizeDcdMarginYBottom )
	: m_CconvContentPosToTargetXy( eMode ) 
	, m_convX( sizeDcdMarginXRight )   
	, m_convY( sizeDcdMarginYBottom )   
{
}

CconvContentPosToDcdTarget::CconvContentPosToDcdTarget( 
		DcdPos	iContentPosX ,
		double dTargetPosPerContentX ,
		DcdPos	iContentPosY ,
		double dTargetPosPerContentY ,
		DcdSize	sizeDcdMarginXRight ,
		DcdSize	sizeDcdMarginYBottom ) 
	: m_CconvContentPosToTargetXy( 
		iContentPosX ,
		dTargetPosPerContentX ,
		iContentPosY ,
		dTargetPosPerContentY ) 
	, m_convX( sizeDcdMarginXRight )  
	, m_convY( sizeDcdMarginYBottom )   
{
}

CconvContentPosToDcdTarget::CconvContentPosToDcdTarget( 
		const CdDcdZoneXy&	zonexyContent ,
		DcdSize	sizeDcdMarginXRight ,
		DcdSize	sizeDcdMarginYBottom ) 
	: m_CconvContentPosToTargetXy( zonexyContent ) 
	, m_convX( sizeDcdMarginXRight )  
	, m_convY( sizeDcdMarginYBottom )   
{
}

CconvContentPosToDcdTarget::CconvContentPosToDcdTarget() 
	: m_convX( 0 )  
	, m_convY( 0 )   
{
}

CconvContentPosToDcdTarget::~CconvContentPosToDcdTarget() 
{
}


	// ********************************
	//@name CconvContentPosToDcdTarget-�W��
	// ********************************

	// ********************************
	//@name CconvContentPosToDcdTarget-����
	// ********************************
DcdSize	CconvContentPosToDcdTarget::getDcdMarginXRight()const 
{
	return m_convX.getDcdMargin() ;
}
void CconvContentPosToDcdTarget::setDcdMarginXRight( DcdSize value ) 
{
	return m_convX.setDcdMargin(value) ;
}
DcdSize	CconvContentPosToDcdTarget::getDcdMarginYBottom()const 
{
	return m_convY.getDcdMargin() ;
}
void CconvContentPosToDcdTarget::setDcdMarginYBottom( DcdSize value ) 
{
	return m_convY.setDcdMargin(value) ;
}

	// ********************************
	//@name CconvContentPosToDcdTarget-����
	// ********************************
CconvContentPosToTarget::EMode	
CconvContentPosToDcdTarget::getMode()const 
{
	return m_CconvContentPosToTargetXy.getMode() ;
}

void CconvContentPosToDcdTarget::setMode( 
	CconvContentPosToTarget::EMode	value ) 
{
	m_CconvContentPosToTargetXy.setMode( value ) ;
}

CdDcdPosXy CconvContentPosToDcdTarget::getContentPos()const 
{
	return CdDcdPosXy( 
		m_CconvContentPosToTargetXy.getX()->getContentPos() ,
		m_CconvContentPosToTargetXy.getY()->getContentPos() );
}

void CconvContentPosToDcdTarget::setContentPos( const CdDcdPosXy& value ) 
{
	m_CconvContentPosToTargetXy.getX()->setContentPos( value.getX() ) ;
	m_CconvContentPosToTargetXy.getY()->setContentPos( value.getY() ) ;
}


void CconvContentPosToDcdTarget::setContentPosAndRate( 
		const CdDcdPosXy& posContentPos , 
		double dTargetPosPerContentX , 
		double dTargetPosPerContentY , 
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	aTargetZone ;
	CdDcdZoneXy* pTargetZone = NULL ;
	if ( pIfDcdTarget != NULL )
	{
		aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
		pTargetZone = &aTargetZone ;
	}

	m_CconvContentPosToTargetXy.setContentPosAndRate( 
		posContentPos , 
		dTargetPosPerContentX , 
		dTargetPosPerContentY , 
		pTargetZone ) ;
}

CdDcdZoneXy CconvContentPosToDcdTarget::getContentZone( 
	IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	aTargetZone ;
	CdDcdZoneXy* pTargetZone = NULL ;
	if ( pIfDcdTarget != NULL )
	{
		aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
		pTargetZone = &aTargetZone ;
	}
	// --------------------------------
	return m_CconvContentPosToTargetXy.getContentZone( 
		pTargetZone ) ;
}

void CconvContentPosToDcdTarget::setContentZone( 
	const CdDcdZoneXy& zoneContent , 
	IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	aTargetZone ;
	CdDcdZoneXy* pTargetZone = NULL ;
	if ( pIfDcdTarget != NULL )
	{
		aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
		pTargetZone = &aTargetZone ;
	}
	// --------------------------------
	m_CconvContentPosToTargetXy.setContentZone( 
		zoneContent , 
		pTargetZone ) ;
}
	// ********************************
	//@name CconvContentPosToDcdTarget-���W�ϊ�
	// ********************************
CdDcdPosXy CconvContentPosToDcdTarget::ContentPosToTarget( 
		const CdDcdPosXy& value ,
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
	return m_CconvContentPosToTargetXy.ContentPosToTarget( 
		value , aTargetZone ) ;
}
CdDcdPosXy CconvContentPosToDcdTarget::ContentPosFromTarget( 
		const CdDcdPosXy& value ,
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
	return m_CconvContentPosToTargetXy.ContentPosFromTarget(
		value , aTargetZone ) ;

}

CdDcdZoneXy CconvContentPosToDcdTarget::ContentZoneToTarget( 
		const CdDcdZoneXy& value ,
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
	return m_CconvContentPosToTargetXy.ContentZoneToTarget( 
		value , aTargetZone ) ;
}

CdDcdZoneXy CconvContentPosToDcdTarget::ContentZoneFromTarget( 
		const CdDcdZoneXy& value ,
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
	return m_CconvContentPosToTargetXy.ContentZoneFromTarget(
		value , aTargetZone ) ;

}

} //namespace DcDraw
} //namespace DcDrawLib
