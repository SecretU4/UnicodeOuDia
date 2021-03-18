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
//	CaDcdGrid_PageSelector.cpp
//	$Id: CaDcdGrid_PageSelector.cpp 324 2016-06-12 03:03:55Z okm $
// ****************************************************************
*/
#include "DcdGrid\CaDcdGrid_PageSelector.h"
#include "DcDraw\CaDcdTargetClip.h"
using namespace std ;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcdGrid{

// ****************************************************************
//	CaDcdGrid_PageSelector
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CaDcdGrid_PageSelector::CaDcdGrid_PageSelector( 
		CDcdGrid*	pCDcdGrid ,
		IfDcdTarget* pIfDcdTarget ) :
	m_pCDcdGrid( pCDcdGrid ) ,
	m_pIfDcdTarget( pIfDcdTarget ) ,
	m_iXPage( 0 ) ,
	m_iYPage( 0 ) 
{
	m_iYFixafterColumnNumberSid = m_pCDcdGrid->getYFixafterColumnNumber() ;
	m_iXFixafterColumnNumberSid = m_pCDcdGrid->getXFixafterColumnNumber() ;
	

	{
		int iYFixafterColumnNumber ;
		for ( iYFixafterColumnNumber = pCDcdGrid->getYFixColumnCount() ;
				iYFixafterColumnNumber < pCDcdGrid->getYColumnCount() ;
				iYFixafterColumnNumber = pCDcdGrid->calcYFixafterColumnNumberPagemove( 
					pIfDcdTarget , iYFixafterColumnNumber , true ) ){
			pCDcdGrid->setYFixafterColumnNumber( iYFixafterColumnNumber ) ;
			m_contiYFixafterColumnNumber.push_back( iYFixafterColumnNumber ) ;
		}
	}
	{
		int iXFixafterColumnNumber ;
		for ( iXFixafterColumnNumber = pCDcdGrid->getXFixColumnCount() ;
				iXFixafterColumnNumber < pCDcdGrid->getXColumnCount() ;
				iXFixafterColumnNumber = pCDcdGrid->calcXFixafterColumnNumberPagemove( 
					pIfDcdTarget , iXFixafterColumnNumber , true ) ){
			pCDcdGrid->setXFixafterColumnNumber( iXFixafterColumnNumber ) ;
			m_contiXFixafterColumnNumber.push_back( iXFixafterColumnNumber ) ;
		}
	}
	//contiYFixafterColumnNumber , contiXFixafterColumnNumber =
	//	�v�����^�̈�����s���ꍇ�́A�y�[�W���� FixafterColumnNumber ��
	//	�ێ����Ă��܂��B
	//	  �K�v�ȃy�[�W���́A
	//	contiYFixafterColumnNumber.size() *  contiXFixafterColumnNumber.size() 
	//	�ƂȂ�܂��B

	pCDcdGrid->setYFixafterColumnNumber( m_iYFixafterColumnNumberSid ) ;
	pCDcdGrid->setXFixafterColumnNumber( m_iXFixafterColumnNumberSid ) ;

}


	
CaDcdGrid_PageSelector::~CaDcdGrid_PageSelector() 
{
	m_pCDcdGrid->setXFixafterColumnNumber( m_iXFixafterColumnNumberSid ) ;
	m_pCDcdGrid->setYFixafterColumnNumber( m_iYFixafterColumnNumberSid ) ;
}


// ********************************
//	CaDcdGrid_PageSelector
// ********************************
	// ********************************
	//@name �֘A
	// ********************************
CDcdGrid*	CaDcdGrid_PageSelector::getCDcdGrid() 
{
	return ( m_pCDcdGrid ) ;
	
}
IfDcdTarget* CaDcdGrid_PageSelector::getIfDcdTarget() 
{
	return ( m_pIfDcdTarget ) ;
}
	
	// ********************************
	//@name ����
	// ********************************
void CaDcdGrid_PageSelector::getYFixafterColumnNumber( deque<int>* pvalue ) 
{
	*pvalue = m_contiYFixafterColumnNumber ;
}
void CaDcdGrid_PageSelector::getXFixafterColumnNumber( deque<int>* pvalue ) 
{
	*pvalue = m_contiXFixafterColumnNumber ;
}

int CaDcdGrid_PageSelector::getXPageCount() 
{
	return ( m_contiXFixafterColumnNumber.size() ) ;
}

int CaDcdGrid_PageSelector::getYPageCount() 
{
	return ( m_contiYFixafterColumnNumber.size() ) ;
}

int CaDcdGrid_PageSelector::getXPage() 
{
	return ( m_iXPage ) ;
}

CaDcdGrid_PageSelector& CaDcdGrid_PageSelector::setXPage( int value ) 
{
	int iRv = 0 ;
	
	if ( iRv >= 0 ){
		if ( value == INT_MAX ){
			value = getXPageCount() - 1 ;
		}
		if (  value < 0 ){
			value = 0 ;
		}
		if ( value >= getXPageCount() ) {
			value = getXPageCount() - 1 ;
		}
		m_iXPage = value ;
	}
	
	if ( iRv >= 0 ){
		int iXFixafterColumnNumber = m_contiXFixafterColumnNumber[ m_iXPage ] ;
		m_pCDcdGrid->setXFixafterColumnNumber( iXFixafterColumnNumber ) ;
	}
	return ( *this ) ;
}

int CaDcdGrid_PageSelector::getYPage() 
{
	return ( m_iYPage ) ;
}


CaDcdGrid_PageSelector& CaDcdGrid_PageSelector::setYPage( int value ) 
{
	int iRv = 0 ;
	
	if ( iRv >= 0 ){
		if ( value == INT_MAX ){
			value = getYPageCount() - 1 ;
		}
		if (  value < 0 ){
			value = 0 ;
		}
		if ( value >= getYPageCount() ) {
			value = getYPageCount() - 1 ;
		}
		m_iYPage = value ;
	}
	if ( iRv >= 0 ){
		int iYFixafterColumnNumber = m_contiYFixafterColumnNumber[ m_iYPage ] ;
		m_pCDcdGrid->setYFixafterColumnNumber( iYFixafterColumnNumber ) ;
	}
	return ( *this ) ;
}

int CaDcdGrid_PageSelector::getPageCount() 
{
	return ( m_contiYFixafterColumnNumber.size() * 
			m_contiXFixafterColumnNumber.size() ) ;
}


int CaDcdGrid_PageSelector::getPage() 
{
	return ( m_iYPage * m_contiXFixafterColumnNumber.size() + m_iXPage ) ;
}

CaDcdGrid_PageSelector& CaDcdGrid_PageSelector::setPage( int value ) 
{
	if ( value == INT_MAX ){
		value = getPageCount() - 1 ;
	}
	if ( value >= getPageCount() ){
		value = getPageCount() - 1 ;
	}
	if ( value < 0 ){
		value = 0 ;
	}
	
	int iYPage = value / m_contiXFixafterColumnNumber.size() ;
	int iXPage = value % m_contiXFixafterColumnNumber.size() ;
	
	setYPage( iYPage ) ;
	setXPage( iXPage ) ;
	
	return *this ;
}



	// ********************************
	//@name ����
	// ********************************
bool CaDcdGrid_PageSelector::DcDraw() 
{
	bool bRv = 0 ;
	
	
	int iXColumnNumberTail = m_pCDcdGrid->getXColumnCount() - 1 ;
	if ( m_iXPage < (int)m_contiXFixafterColumnNumber.size() - 1 ){
		iXColumnNumberTail = m_contiXFixafterColumnNumber[ m_iXPage + 1 ] - 1 ;
	}
	int iYColumnNumberTail = m_pCDcdGrid->getYColumnCount() - 1 ;
	if ( m_iYPage < (int)m_contiYFixafterColumnNumber.size() - 1 ){
		iYColumnNumberTail = m_contiYFixafterColumnNumber[ m_iYPage + 1 ] - 1 ;
	}
	//iXColumnNumberTail =
	//	���S�ɕ\���ł��Ă���ł��E�̗�ԍ�
	//iYColumnNUmberTail = 
	//	���S�ɕ\���ł��Ă���ł����̗�ԍ�
	
	CdDcdZone	zoneXColumnNumberTail ; 
	CdDcdZone	zoneYColumnNumberTail ; 
	zoneXColumnNumberTail = 
		m_pCDcdGrid->getXColumnBorderZone( m_pIfDcdTarget , iXColumnNumberTail ) ;
	zoneYColumnNumberTail = 
		m_pCDcdGrid->getYColumnBorderZone( m_pIfDcdTarget , iYColumnNumberTail ) ;
	//zoneXColumnNumberTail = ���S�ɕ\���ł��Ă���ł��E�̗�̌r���ʒu
	//zoneYColumnNumberTail = ���S�ɕ\���ł��Ă���ł����̗�̌r���ʒu
	
	CdDcdZoneXy	zonexyClip = m_pIfDcdTarget->getZone() ;
	{
		CdDcdZone	zoneClip = zonexyClip.getX() ;
		zoneClip.setSize( 
			zoneXColumnNumberTail.getEndPos() - zoneClip.getPos() ) ;
		zonexyClip.setX( zoneClip ) ;
	}
	{
		CdDcdZone	zoneClip = zonexyClip.getY() ;
		zoneClip.setSize( 
			zoneYColumnNumberTail.getEndPos() - zoneClip.getPos() ) ;
		zonexyClip.setY( zoneClip ) ;
	}
	//zonexyClip = �N���b�s���O�̈�Ƃ��܂��B
	
	CaDcdTargetClip	aCaDcdTargetClip( m_pIfDcdTarget , zonexyClip ) ;
	aCaDcdTargetClip.validate() ;
	bRv = m_pCDcdGrid->DcDraw( &aCaDcdTargetClip ) ;
	
	return ( bRv ) ;
};

} //namespace DcdGrid
} //namespace DcDrawLib
