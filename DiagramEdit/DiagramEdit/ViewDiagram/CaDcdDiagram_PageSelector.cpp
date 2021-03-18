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
//	CaDcdDiagram_PageSelector.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CaDcdDiagram_PageSelector.h"

namespace ViewDiagram{

/**
  ����(�␳�Ώےl)���A�����P�ʂ̔{���}��(�덷���e�l) �Ȃ�A
  �Ŋ�̑����P�ʂ̔{�����x�̒l�ɕ␳���܂��B

(��)iUnit=5,iAllowedDifference=1 �̏ꍇ�Avalue�ɑ΂��錋�ʂ͈ȉ��̂Ƃ���ł��B

�@- value=3 �Ȃ� return=3
�@- value=4 �Ȃ� return=5
�@- value=5 �Ȃ� return=5
�@- value=6 �Ȃ� return=5
�@- value=7 �Ȃ� return=7


@param value [in]
	�␳�Ώےl���w�肵�Ă��������B�͈͂�0�ȏ�ł��B
@param iUnit [in]
	�����P�ʂ��w�肵�Ă��������B�͈͂�1�ȏ�ł��B
@param iAllowedDifference [in]
	�덷���e�l
@return
	�␳���ꂽ�l��Ԃ��܂��B
*/
static int adjustForNearestUnit( int value , int iUnit , int iAllowedDifference ) 
{
	int iMod = value % iUnit ;

	if ( iMod == 0 )
	{
	}
	//�␳�P�F(���ݒl%�����P��)��(�덷���e�l) �Ȃ�A
	//�@���ݒl=���ݒl-(���ݒl%�����P��)
	//
	//(��)
	//�@�����P��=1800
	//�@���ݒl=1801
	//�@(�덷���e�l)=1
	//�̏ꍇ
	//�@(1801%1800)=1 (���ݒl%�����P��)
	//�@1801-(1801%1800)=1800
	//
	else if ( iMod <= iAllowedDifference )
	{
		value = value - iMod ; 
	}

	//�␳�Q�F(���ݒl%�����P��)��(�����P��-�덷���e�l) �Ȃ�A
	//�@���ݒl=���ݒl+(�����P��-(���ݒl%�����P��))
	//
	//(��)
	//�@�����P��=1800
	//�@���ݒl=3599
	//�@(�덷���e�l)=1
	//�̏ꍇ
	//�@(3599%1800)=1799 (���ݒl%�����P��)
	//�@3599+(1800-(3599%1800))=3600
	else if ( iMod >= ( iUnit - iAllowedDifference ) )
	{
		value = value + ( iUnit - iMod ) ; 
	}
	return value ;
}

// ****************************************************************
//	CaDcdDiagram_PageSelector
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CaDcdDiagram_PageSelector::CaDcdDiagram_PageSelector( 
		CDcdDiagram2*	pCDcdDiagram2 ,
		const CdDcdSizeXy&	sizePage_Dgr ) 
{
	m_pCDcdDiagram2 = pCDcdDiagram2 ;
	m_sizePage_Dgr = sizePage_Dgr ;
	m_iXPage = 0 ;
	m_iYPage = 0 ;

	m_CconvContentPosToDcdTargetPrev = 
		*m_pCDcdDiagram2->getCconvContentPosToDcdTarget() ;
}


	
CaDcdDiagram_PageSelector::~CaDcdDiagram_PageSelector() 
{
	*m_pCDcdDiagram2->getCconvContentPosToDcdTarget() =
		m_CconvContentPosToDcdTargetPrev ;
}

// ********************************
//@name 	IfDcDraw
// ********************************
bool CaDcdDiagram_PageSelector::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	zonexyZone_Dgr = m_pCDcdDiagram2->getZone_Dgr( pIfDcdTarget ) ;
	//zonexyZone_Dgr=�`����s�� �_�C���O�������W�͈̔�
	
	// --------------------------------
	//	�_�C���O�����S�̗̂̈�(�_�C���O�������W)���擾
	// --------------------------------
	CdDcdZoneXy	zonexyCentDcdDgrDia = 
		m_pCDcdDiagram2->getCentDedDgrDia()->getZone() ;
	if ( m_sizePage_Dgr.getX() > 0 )
	{
		zonexyCentDcdDgrDia.setX( 
			CdDcdZone( zonexyCentDcdDgrDia.getX().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getX().getSize() , m_sizePage_Dgr.getX() , 1 ) ) ) ;
	}
	if ( m_sizePage_Dgr.getY() > 0 )
	{
		zonexyCentDcdDgrDia.setY( 
			CdDcdZone( zonexyCentDcdDgrDia.getY().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getY().getSize() , m_sizePage_Dgr.getY() , 1 ) ) ) ;
	}
	//zonexyCentDcdDgrDia = �_�C���O�����S�̗̂̈�(�_�C���O�������W)
	//	�������A�����P�y�[�W�̃T�C�Y(�_�C���O�������W)�ɋ߂��ꍇ�́A
	//	1�y�[�W�̃T�C�Y�Ɠ����ɂ��܂��B
	//	���݂ł́A�Ӗ����Ȃ��Ȃ��Ă���悤�ł��B

	// --------------------------------


	zonexyZone_Dgr.setX( CdDcdZone( 
		zonexyCentDcdDgrDia.getX().getPos() + m_sizePage_Dgr.getX() * m_iXPage , 
		m_sizePage_Dgr.getX() ) )  ;
	zonexyZone_Dgr.setY( CdDcdZone( 
		zonexyCentDcdDgrDia.getY().getPos() + m_sizePage_Dgr.getY() * m_iYPage , 
		m_sizePage_Dgr.getY() ) )  ;
	m_pCDcdDiagram2->setZone_Dgr( pIfDcdTarget , zonexyZone_Dgr ) ;

	return m_pCDcdDiagram2->DcDraw( pIfDcdTarget ) ;
}
bool CaDcdDiagram_PageSelector::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	CdDcdZoneXy	zonexyZone_Dgr = m_pCDcdDiagram2->getZone_Dgr( pIfDcdTarget ) ;
	//zonexyZone_Dgr=�`����s�� �_�C���O�������W�͈̔�
	//	(1�y�[�W�ɕ`�悷��_�C���O�����͈̔�)

	// --------------------------------
	//	�_�C���O�����S�̗̂̈�(�_�C���O�������W)���擾
	// --------------------------------
	CdDcdZoneXy	zonexyCentDcdDgrDia = 
		m_pCDcdDiagram2->getCentDedDgrDia()->getZone() ;
	if ( m_sizePage_Dgr.getX() > 0 )
	{
		zonexyCentDcdDgrDia.setX( 
			CdDcdZone( zonexyCentDcdDgrDia.getX().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getX().getSize() , m_sizePage_Dgr.getX() , 1 ) ) ) ;
	}
	if ( m_sizePage_Dgr.getY() > 0 )
	{
		zonexyCentDcdDgrDia.setY( 
			CdDcdZone( zonexyCentDcdDgrDia.getY().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getY().getSize() , m_sizePage_Dgr.getY() , 1 ) ) ) ;
	}
	//zonexyCentDcdDgrDia = �_�C���O�����S�̗̂̈�(�_�C���O�������W)
	//	�������A�����P�y�[�W�̃T�C�Y(�_�C���O�������W)�ɋ߂��ꍇ�́A
	//	1�y�[�W�̃T�C�Y�Ɠ����ɂ��܂��B
	//	���݂ł́A�Ӗ����Ȃ��Ȃ��Ă���悤�ł��B

	
	// --------------------------------

	zonexyZone_Dgr.setX( CdDcdZone( 
		zonexyCentDcdDgrDia.getX().getPos() + m_sizePage_Dgr.getX() * m_iXPage , 
		m_sizePage_Dgr.getX() ) )  ;
	zonexyZone_Dgr.setY( CdDcdZone( 
		zonexyCentDcdDgrDia.getY().getPos() + m_sizePage_Dgr.getY() * m_iYPage , 
		m_sizePage_Dgr.getY() ) )  ;

	m_pCDcdDiagram2->setZone_Dgr( pIfDcdTarget , zonexyZone_Dgr ) ;

	return m_pCDcdDiagram2->getItemSize( pIfDcdTarget , pCdDcdSizeXy ) ;
}

// ********************************
//	CaDcdDiagram_PageSelector
// ********************************


int CaDcdDiagram_PageSelector::getXPageCount() 
{
	int iRv = 0 ;

	// --------------------------------
	//	�_�C���O�����S�̗̂̈�(�_�C���O�������W)���擾
	// --------------------------------
	CdDcdZoneXy	zonexyCentDcdDgrDia = 
		m_pCDcdDiagram2->getCentDedDgrDia()->getZone() ;
	if ( m_sizePage_Dgr.getX() > 0 )
	{
		zonexyCentDcdDgrDia.setX( 
			CdDcdZone( zonexyCentDcdDgrDia.getX().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getX().getSize() , m_sizePage_Dgr.getX() , 1 ) ) ) ;
	}
	if ( m_sizePage_Dgr.getY() > 0 )
	{
		zonexyCentDcdDgrDia.setY( 
			CdDcdZone( zonexyCentDcdDgrDia.getY().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getY().getSize() , m_sizePage_Dgr.getY() , 1 ) ) ) ;
	}
	//zonexyCentDcdDgrDia = �_�C���O�����S�̗̂̈�(�_�C���O�������W)
	//	�������A�����P�y�[�W�̃T�C�Y(�_�C���O�������W)�ɋ߂��ꍇ�́A
	//	1�y�[�W�̃T�C�Y�Ɠ����ɂ��܂��B
	//
	//�y���R�z�����\������Ȃ��y�[�W���������Ȃ��悤�ɂ��邽�߂ł��B
	//
	//�y��z
	//�@�E�C���h�E�T�C�Y���_�C���O�����S�̂̃T�C�Y��
	//	�킸����(�P�s�N�Z��)����Ȃ��ꍇ�B
	//		zonexyCentDcdDgrDia.m_Y.m_Size =10800
	//		m_sizePage_Dgr.m_Y.m_Size      =10799
	//	Y�����ɕK�v�ȃy�[�W���Q�ƌv�Z����Ă��܂��A
	//	2�y�[�W�ڂ͌����ڏ�󔒂ɂȂ��Ă��܂��܂��B
	//
	//	�����ł́A
	//		zonexyCentDcdDgrDia.m_Y.m_Size �� 10799 
	//	�ɕ␳���邱�Ƃɂ��AY�����ɕK�v�ȃy�[�W��
	//	�P�ƌv�Z�����邱�Ƃ��ł��܂��B
	
	// --------------------------------

	if ( m_sizePage_Dgr.getX() > 0 )
	{
		iRv = zonexyCentDcdDgrDia.getX().getSize() ;

		iRv += ( m_sizePage_Dgr.getX() - 1 ) ;
		iRv /= m_sizePage_Dgr.getX() ;
	}

	return ( iRv ) ;
	
}

int CaDcdDiagram_PageSelector::getYPageCount() 
{
	int iRv = 0 ;

	// --------------------------------
	//	�_�C���O�����S�̗̂̈�(�_�C���O�������W)���擾
	// --------------------------------
	CdDcdZoneXy	zonexyCentDcdDgrDia = 
		m_pCDcdDiagram2->getCentDedDgrDia()->getZone() ;
	if ( m_sizePage_Dgr.getX() > 0 )
	{
		zonexyCentDcdDgrDia.setX( 
			CdDcdZone( zonexyCentDcdDgrDia.getX().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getX().getSize() , m_sizePage_Dgr.getX() , 1 ) ) ) ;
	}
	if ( m_sizePage_Dgr.getY() > 0 )
	{
		zonexyCentDcdDgrDia.setY( 
			CdDcdZone( zonexyCentDcdDgrDia.getY().getPos() , 
				adjustForNearestUnit( zonexyCentDcdDgrDia.getY().getSize() , m_sizePage_Dgr.getY() , 1 ) ) ) ;
	}
	//zonexyCentDcdDgrDia = �_�C���O�����S�̗̂̈�(�_�C���O�������W)
	//	�������A�����P�y�[�W�̃T�C�Y(�_�C���O�������W)�ɋ߂��ꍇ�́A
	//	1�y�[�W�̃T�C�Y�Ɠ����ɂ��܂��B
	//�y���R�z�����\������Ȃ��y�[�W���������Ȃ��悤�ɂ��邽�߂ł��B
	//	getXPageCount()���Q�Ƃ��Ă��������B

	// --------------------------------


	if ( m_sizePage_Dgr.getY() > 0 )
	{
		iRv = zonexyCentDcdDgrDia.getY().getSize() ;

		iRv += ( m_sizePage_Dgr.getY() - 1 ) ;
		iRv /= m_sizePage_Dgr.getY() ;
	}
	return ( iRv ) ;
}

int CaDcdDiagram_PageSelector::getPageCount() 
{
	return getXPageCount() * getYPageCount() ;
}
	
	
int CaDcdDiagram_PageSelector::getXPage() 
{
	return m_iXPage ;
}

CaDcdDiagram_PageSelector& 
	CaDcdDiagram_PageSelector::setXPage( int value ) 
{
	if ( value == INT_MAX ){
		value = getXPageCount() - 1 ;
	}
	if ( value >= getXPageCount() - 1 ){
		value = getXPageCount() - 1 ;
	}
	if ( value < 0 ){
		value = 0 ;
	}
	m_iXPage = value ;
	return *this ;
}

int CaDcdDiagram_PageSelector::getYPage() 
{
	return m_iYPage ;
}

CaDcdDiagram_PageSelector& 
	CaDcdDiagram_PageSelector::setYPage( int value ) 
{
	if ( value == INT_MAX ){
		value = getYPageCount() - 1 ;
	}
	if ( value >= getYPageCount() - 1 ){
		value = getYPageCount() - 1 ;
	}
	if ( value < 0 ){
		value = 0 ;
	}
	m_iYPage = value ;
	return *this ;

}
int CaDcdDiagram_PageSelector::getPage() 
{
	return m_iXPage + m_iYPage * getXPageCount() ;
}


CaDcdDiagram_PageSelector& 
	CaDcdDiagram_PageSelector::setPage( int value ) 
{
	if ( value == INT_MAX ){
		value = getPageCount() - 1 ;
	}
	if ( value >= getPageCount() - 1 ){
		value = getPageCount() - 1 ;
	}
	if ( value < 0 ){
		value = 0 ;
	}
	int iXPage = value % getXPageCount() ;
	int iYPage = value / getXPageCount() ;
	setXPage( iXPage );
	setYPage( iYPage ) ;
	return *this ;
}
} //namespace ViewDiagram
