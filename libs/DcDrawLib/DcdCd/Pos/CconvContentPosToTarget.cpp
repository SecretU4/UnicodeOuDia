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
// $Id: CconvContentPosToTarget.cpp 313 2016-06-11 13:20:04Z okm $
// ****************************************************************
*/
#include <STDDEF.H>
#include "DcdCd\Pos\CconvContentPosToTarget.h"
#include "DcdCd\Pos\CconvDcdPosOnZone_PosOrgAndRate.h"
#include "DcdCd\Pos\CconvDcdPosOnZone_DcdZone.h"

namespace DcDrawLib{
namespace DcdCd{
namespace Pos{


// ****************************************************************
//	CconvContentPosToTarget
// ****************************************************************
	// --------------------------------
	//@name �����֐�
	// --------------------------------
DcdSize CconvContentPosToTarget::TargetPosPerContentToContentSize( 
	double dTargetPosPerContent , 
	const CdDcdZone* pTargetZone ) 
{
	DcdSize	iRv = 0 ;
	if ( pTargetZone->getSize() != 0 && 
		m_dTargetPosPerContent != (double)0 )
	{
		iRv =  (DcdSize)( (double)pTargetZone->getSize() / m_dTargetPosPerContent ) ; 
	}

	return( iRv ) ;
}

double CconvContentPosToTarget::TargetPosPerContentFromContentSize( 
	DcdSize iContentSize , 
	const CdDcdZone* pTargetZone ) 
{
	double	dRv = 0 ;
	if ( pTargetZone->getSize() != 0 && m_iContentSize != 0 )
	{
		dRv = (double)pTargetZone->getSize() / (double)m_iContentSize ;
	}
	return dRv ;
}


void CconvContentPosToTarget::
	synchronizeProp( const CdDcdZone* pTargetZone ) 
{
	// --------------------------------
	//	(1)�����ݒ莞�̓���
	// --------------------------------
	//�@TargetZone ���w�肷�鑀��ɂ����āATargetZone.Size��0�̏ꍇ�A
	//	TargetZone ��NULL���w�肳�ꂽ�ꍇ�́A
	//	���������͍s���܂���B
	if ( pTargetZone != NULL && 
		pTargetZone->getSize() != 0 )
	{
		if ( m_eSynchronizeState == ESynchronizeState_TargetPosPerContent )
		{
			//	m_dTargetPosPerContent �������ݒ蓯���҂��B

			m_dTargetPosPerContent = TargetPosPerContentFromContentSize(
				m_iContentSize , pTargetZone );
			
			//	�v���p�e�B�̑����ݒ蓯��������
			m_eSynchronizeState = ESynchronizeState_None ;

			//	�v���p�e�B�̃L���b�V���p�ɑ������X�V
			m_iTargetSize_Prev = pTargetZone->getSize() ;
		}
		else if ( m_eSynchronizeState == ESynchronizeState_ContentSize )
		{
			// m_iContentSize �������ݒ蓯���҂��B
			m_iContentSize = TargetPosPerContentToContentSize(
				m_dTargetPosPerContent , pTargetZone ) ;

			//	�v���p�e�B�̑����ݒ蓯��������
			m_eSynchronizeState = ESynchronizeState_None ;

			//	�v���p�e�B�̃L���b�V���p�ɑ������X�V
			m_iTargetSize_Prev = pTargetZone->getSize() ;
		}
	}


	// --------------------------------
	//	(2)�����擾���̓���
	// --------------------------------

	if ( pTargetZone != NULL )
	{
		if ( m_iTargetSize_Prev == pTargetZone->getSize() )	
		{
			//	�w�肳�ꂽ TargetZone �� Size ���O��Ɠ����Ȃ�A	
			//	�����̓��� SynchronizeProp ���s���܂���B
			//	������A�w�v���p�e�B�̃L���b�V���x
			//	PropCache �ƌď̂��܂��B
		}
		else
		{
			if ( pTargetZone->getSize() == 0 )
			{
				//�@ PosAndRate ���[�h�ł́w�����̓����x�̍ۂɁA
				//	TargetZone.Size=0��
				//	�w�肳�ꂽ�ꍇ�́AContentSize �͍X�V�����A
				//	�O�l���p�����܂��B 
			}
			else
			{
				if ( m_eMode == EModePosAndRate )
				{
					//	���̃N���X�� PosAndRate ���[�h�ł́A
					//	���[�U�[��TargetZone��
					//	�w�肷�鑀����s�����тɁA���� ContentSize ��
					//	�X�V���܂��BContentSize �́A
					//	TargetZone ��Size ���ω����閈�ɁA�l���ω����܂��B
					m_iContentSize = TargetPosPerContentToContentSize(
						m_dTargetPosPerContent , pTargetZone ) ;
				}
				else
				{
					//	Zone ���[�h�ł����l�ɁATargetPosPerContent ���w��A
					//	�擾���邱��
					//	���ł��܂��B���̃N���X�̃��[�U�[��TargetZone��
					//	�w�肷�鑀����s�����сA
					//	TargetPosPerContent���X�V���܂��B
					m_dTargetPosPerContent = TargetPosPerContentFromContentSize(
						m_iContentSize , pTargetZone );
				}
			}
			//	�v���p�e�B�̃L���b�V���p�ɑ������X�V
			m_iTargetSize_Prev = pTargetZone->getSize() ;
		}
	}
}

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CconvContentPosToTarget::CconvContentPosToTarget() :
	m_eMode( EModePosAndRate ) , 
	m_iContentPos( 0 ) ,
	m_dTargetPosPerContent( 1 ) ,
	m_iContentSize( 1 ),
	m_eSynchronizeState( ESynchronizeState_None ) ,
	m_iTargetSize_Prev( 0 ) {}
	
CconvContentPosToTarget::CconvContentPosToTarget( 
	EMode	eMode ) :
	m_eMode( eMode ) , 
	m_iContentPos( 0 ) ,
	m_dTargetPosPerContent( 1 ) ,
	m_iContentSize( 1 ) ,
	m_eSynchronizeState( ESynchronizeState_None ) ,
	m_iTargetSize_Prev( 0 ) {}

CconvContentPosToTarget::CconvContentPosToTarget( 
		DcdPos	iContentPos ,
		double dTargetPosPerContent ) :
	m_eMode( EModePosAndRate ) , 
	m_iContentPos( iContentPos ) ,
	m_dTargetPosPerContent( dTargetPosPerContent ) ,
	m_iContentSize( 1 ) , 
	m_eSynchronizeState( ESynchronizeState_ContentSize ) ,
	m_iTargetSize_Prev( 0 ) {}

CconvContentPosToTarget::CconvContentPosToTarget( 
		const CdDcdZone& zoneContent ) :
	m_eMode( EModeZone ) , 
	m_iContentPos( zoneContent.getPos() ) ,
	m_dTargetPosPerContent( 1 ) ,
	m_iContentSize( zoneContent.getSize() ) ,
	m_eSynchronizeState( ESynchronizeState_TargetPosPerContent ) ,
	m_iTargetSize_Prev( 0 ) {}


	// ********************************
	//@name CconvContentPosToTarget-����
	// ********************************
CconvContentPosToTarget::EMode	CconvContentPosToTarget::getMode()const 
{
	return m_eMode ;
}
void CconvContentPosToTarget::setMode( EMode	value ) 
{
	m_eMode = value ;
}

DcdPos	CconvContentPosToTarget::getContentPos()const 
{
	return m_iContentPos ;
}
void CconvContentPosToTarget::setContentPos( DcdPos value ) 
{
	m_iContentPos = value ;
}

double CconvContentPosToTarget::getTargetPosPerContent()const 
{
	return m_dTargetPosPerContent ;
}
DcdSize	CconvContentPosToTarget::getContentSize()const 
{
	return m_iContentSize ;
}


	// ********************************
	//@name CconvContentPosToTarget-TargetPosPerContent,ContentSize �̎擾�E�ݒ�
	// ********************************

double CconvContentPosToTarget::getTargetPosPerContent( 
	const CdDcdZone* pTargetZone ) 
{
	//	�v���p�e�B�̓���
	synchronizeProp( pTargetZone ) ;

	return m_dTargetPosPerContent ;
}

void CconvContentPosToTarget::setTargetPosPerContent( 
	double value , const CdDcdZone* pTargetZone ) 
{
	m_dTargetPosPerContent = value ;

	/// m_iContentSize �������ݒ蓯���҂��B
	m_eSynchronizeState = ESynchronizeState_ContentSize ;

	//	�v���p�e�B�̓���
	synchronizeProp( pTargetZone ) ;
}

DcdSize CconvContentPosToTarget::getContentSize( 
	const CdDcdZone* pTargetZone ) 
{
	//	�v���p�e�B�̓���
	synchronizeProp( pTargetZone ) ;

	return m_iContentSize ;
}

void CconvContentPosToTarget::setContentSize( 
	DcdSize value , const CdDcdZone* pTargetZone ) 
{
	m_iContentSize = value ;

	// m_dTargetPosPerContent �������ݒ蓯���҂��B
	m_eSynchronizeState = ESynchronizeState_TargetPosPerContent ;

	//	�v���p�e�B�̓���
	synchronizeProp( pTargetZone ) ;
}

void CconvContentPosToTarget::setContentPosAndRate( 
		DcdPos posContentPos , 
		double dTargetPosPerContent ,
		const CdDcdZone* pTargetZone ) 
{
	setContentPos( posContentPos ) ;
	setTargetPosPerContent( dTargetPosPerContent , pTargetZone ) ;

	//	�v���p�e�B�̓���
	synchronizeProp( pTargetZone ) ;
}


CdDcdZone CconvContentPosToTarget::getContentZone( 
	const CdDcdZone* pTargetZone ) 
{
	//	�v���p�e�B�̓���
	synchronizeProp( pTargetZone ) ;

	return CdDcdZone( getContentPos() , getContentSize( pTargetZone ) ) ;
}
void CconvContentPosToTarget::setContentZone( 
	const CdDcdZone& zoneContent , 
	const CdDcdZone* pTargetZone ) 
{
	setContentPos( zoneContent.getPos() ) ;
	setContentSize( zoneContent.getSize() , pTargetZone ) ;

	//	�v���p�e�B�̓���
	synchronizeProp( pTargetZone ) ;
}
	// ********************************
	//@name CconvContentPosToTarget-���W�ϊ�
	// ********************************


DcdPos	CconvContentPosToTarget::ContentPosToTarget( 
		DcdPos posContent , const CdDcdZone& aTargetZone ) 
{
	DcdPos posRv =  0 ;

	//	�v���p�e�B�̓���
	synchronizeProp( &aTargetZone ) ;

	if ( m_eMode == EModePosAndRate )
	{
		CconvDcdPosOnZone_PosOrgAndRate	aConv( 
			m_iContentPos , aTargetZone.getPos() , m_dTargetPosPerContent ) ;
		posRv  =aConv.Zone1PosToZone2( posContent ) ;
	}
	else if ( m_eMode == EModeZone )
	{
		CconvDcdPosOnZone_DcdZone	aConv( 
			CdDcdZone( m_iContentPos , m_iContentSize ),
			aTargetZone ) ;
		posRv  = aConv.Zone1PosToZone2( posContent ) ;
	}
	return posRv;
}

CdDcdZone CconvContentPosToTarget::ContentZoneToTarget( 
		const CdDcdZone& zoneContent , const CdDcdZone& aTargetZone ) 
{
	CdDcdZone	zoneRv  ; 

	//	�v���p�e�B�̓���
	synchronizeProp( &aTargetZone ) ;

	if ( m_eMode == EModePosAndRate )
	{
		CconvDcdPosOnZone_PosOrgAndRate	aConv( 
			m_iContentPos , aTargetZone.getPos() , m_dTargetPosPerContent ) ;
		zoneRv = aConv.Zone1ToZone2( zoneContent ) ;
	}
	else if ( m_eMode == EModeZone )
	{
		CconvDcdPosOnZone_DcdZone	aConv( 
			CdDcdZone( m_iContentPos , m_iContentSize ),
			aTargetZone ) ;
		zoneRv = aConv.Zone1ToZone2( zoneContent ) ;
	}
	return zoneRv ;
}

DcdPos CconvContentPosToTarget::ContentPosFromTarget( 
		DcdPos posTarget , const CdDcdZone& aTargetZone ) 
{
	DcdPos posRv =  0 ;

	//	�v���p�e�B�̓���
	synchronizeProp( &aTargetZone ) ;

	if ( m_eMode == EModePosAndRate )
	{
		CconvDcdPosOnZone_PosOrgAndRate	aConv( 
			m_iContentPos , aTargetZone.getPos() , m_dTargetPosPerContent ) ;
		posRv  = aConv.Zone1PosFromZone2( posTarget ) ;
	}
	else if ( m_eMode == EModeZone )
	{
		CconvDcdPosOnZone_DcdZone	aConv( 
			CdDcdZone( m_iContentPos , m_iContentSize ),
			aTargetZone ) ;
		posRv  = aConv.Zone1PosFromZone2( posTarget ) ;
	}
	return posRv;
}

CdDcdZone CconvContentPosToTarget::ContentZoneFromTarget( 
		const CdDcdZone& zoneTarget , const CdDcdZone& aTargetZone ) 
{
	CdDcdZone	zoneRv  ; 

	//	�v���p�e�B�̓���
	synchronizeProp( &aTargetZone ) ;


	if ( m_eMode == EModePosAndRate )
	{
		CconvDcdPosOnZone_PosOrgAndRate	aConv( 
			m_iContentPos , aTargetZone.getPos() , m_dTargetPosPerContent ) ;
		zoneRv =  aConv.Zone1FromZone2( zoneTarget ) ;
	}
	else if ( m_eMode == EModeZone )
	{
		CconvDcdPosOnZone_DcdZone	aConv( 
			CdDcdZone( m_iContentPos , m_iContentSize ),
			aTargetZone ) ;
		zoneRv =  aConv.Zone1FromZone2( zoneTarget ) ;
	}
	return zoneRv ;
}

} //namespace Pos
} //namespace DcdCd
} //namespace DcDrawLib
