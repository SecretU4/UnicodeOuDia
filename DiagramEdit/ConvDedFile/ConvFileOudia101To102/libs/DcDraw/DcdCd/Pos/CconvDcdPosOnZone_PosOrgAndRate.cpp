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
//	CconvDcdPosOnZone_PosOrgAndRate.cpp
// $Id: CconvDcdPosOnZone_PosOrgAndRate.cpp 110 2012-09-30 01:24:19Z okm $
// ****************************************************************
*/
#include "stdafx.h"

#include "CconvDcdPosOnZone_PosOrgAndRate.h"

/** @page cconvdcdposonzone_posorgandrate CconvDcdPosOnZone_PosOrgAndRate �ϊ���

�@���W�̕ϊ��ɂ́A���L�̕ϊ���2���g�p���Ă��܂��B

���ϊ���1
  - Zone1��̍��W�� posZone1Pos
  - Zone2��̍��W�� posZone2Pos 
  �Ƃ����ꍇ�A
  
@code
  posZone2Pos = (int)( (double)( posZone1Pos - Zone1Org ) * Zone2PerZone1 ) 
               + Zone2Org 
@endcode

  (��)
  - Zone1Org=*
  - Zone2Org=0
  - Zone2PerZone1=1.5

  - Zone1Org=0
@code
  posZone1Pos  posZone2Pos
  ��������������������������
            0            0
            1      1.5�� 1
            2            3
            3      4.5�� 4
@endcode

  - Zone1Org=1
@code
  posZone1Pos  posZone2Pos
  ��������������������������
            0     -1.5��-1
            1            0
            2      1.5�� 1
            3            3
@endcode

   @ref cconvdcdposonzone_posorgandrate_towindowscroll 
   �w�E�C���h�E�̃X�N���[���ɗp����ꍇ�x�ŋL�������@�ŁA Zone1Org ��ω������ăX�N���[�����s�����@�́A���̕ϊ����ł͎g���܂���B
  ��L�Ŏ������悤�ɁAposZone1Pos=1��posZone1Pos=2�̊Ԃ́AZone2��ł̋����� Zone1Org �ɂ���ĕϓ����Ă��܂��܂��B


���ϊ���2
  - Zone1��̍��W�� posZone1Pos
  - Zone2��̍��W�� posZone2Pos 
  �Ƃ����ꍇ�A
  
@code
  posZone2Pos = (int)( (double)posZone1Pos * Zone2PerZone1 ) 
              - (int)( (double)Zone1Org  * Zone2PerZone1 )
	      + Zone2Org 
@endcode

  (��)
  - Zone1Org=*
  - Zone2Org=0
  - Zone2PerZone1=1.5

  - Zone1Org=0
@code
  posZone1Pos  posZone2Pos
  ��������������������������
            0            0
            1      1.5�� 1
            2            3
            3      4.5�� 4
@endcode

  - Zone1Org=1
@code
  posZone1Pos                posZone2Pos
  ����������������������������������������
            0            0 -1=-1
            1      1.5�� 1 -1= 0
            2            3 -1= 2
            3      4.5�� 4 -1= 3
@endcode


   @ref cconvdcdposonzone_posorgandrate_towindowscroll 
  �w�E�C���h�E�̃X�N���[���ɗp����ꍇ�x�ŋL�������@�ŁA Zone1Org ��ω������ăX�N���[�����s�����@�́A���̕ϊ����ł͗L���ł��B
  posZone1Pos=1��posZone1Pos=2�̊Ԃ́AZone2��ł̋����́AZone1Org �̕ϓ��̉e�����󂯂܂���B
*/

#define Zone1PosToZone2_LOGIC	2	/* 1=�ϊ���1,2=�ϊ���2 */

// ****************************************************************
//	CconvDcdPosOnZone_PosOrgAndRate
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CconvDcdPosOnZone_PosOrgAndRate::CconvDcdPosOnZone_PosOrgAndRate( 
		DcdPos	posZone1Org , 
		DcdPos	posZone2Org ,
		double dZone2PerZone1 ) :
	m_posZone1Org( posZone1Org ) ,	
	m_posZone2Org( posZone2Org ) , 
	m_dZone2PerZone1( dZone2PerZone1 )
{
}

CconvDcdPosOnZone_PosOrgAndRate::CconvDcdPosOnZone_PosOrgAndRate() :
	m_posZone1Org( 0 ) ,	
	m_posZone2Org( 0 ) , 
	m_dZone2PerZone1( 1.0 )
{
}

CconvDcdPosOnZone_PosOrgAndRate::~CconvDcdPosOnZone_PosOrgAndRate() 
{
}

// ********************************
//	CconvDcdPosOnZone_PosOrgAndRate
// ********************************
	
	// ********************************
	//@name ����
	// ********************************
DcdPos CconvDcdPosOnZone_PosOrgAndRate::Zone1PosToZone2( DcdPos posZone1Pos )const 
{
#if( Zone1PosToZone2_LOGIC == 1 )
	DcdPos	iRv = posZone1Pos - m_posZone1Org ;
	iRv = (DcdPos)( (double)iRv * m_dZone2PerZone1 );
	iRv += m_posZone2Org ;
	return ( iRv ) ;
#elif( Zone1PosToZone2_LOGIC == 2 )
	DcdPos posZone2Pos = (int)( (double)posZone1Pos * m_dZone2PerZone1 ) 
          - (int)( (double)m_posZone1Org  * m_dZone2PerZone1 )
	      + m_posZone2Org ;
	return ( posZone2Pos ) ;
#endif/*( Zone1PosToZone2_LOGIC )*/
}

DcdPos CconvDcdPosOnZone_PosOrgAndRate::Zone1PosFromZone2( DcdPos posZone2Pos )const 
{
#if( Zone1PosToZone2_LOGIC == 1 )
	double	dZone1PerZone2 = 0.0 ;
	if ( m_dZone2PerZone1 != 0.0 )
	{
		dZone1PerZone2 = (double)1 / m_dZone2PerZone1 ;
	}
	DcdPos	iRv = posZone2Pos - m_posZone2Org ;
	iRv = (DcdPos)( (double)iRv * dZone1PerZone2 );
	iRv += m_posZone1Org ;
	return ( iRv ) ;
#elif( Zone1PosToZone2_LOGIC == 2 )
	double	dZone1PerZone2 = 0.0 ;
	if ( m_dZone2PerZone1 != 0.0 )
	{
		dZone1PerZone2 = (double)1 / m_dZone2PerZone1 ;
	}
	DcdPos posZone1Pos = (int)( (double)posZone2Pos * dZone1PerZone2 ) 
			- (int)( (double)m_posZone2Org * dZone1PerZone2 )
			+ m_posZone1Org ;

	return ( posZone1Pos ) ;
#endif/*( Zone1PosToZone2_LOGIC )*/
}

CdDcdZone CconvDcdPosOnZone_PosOrgAndRate::Zone1ToZone2(
	const CdDcdZone& value )const 
{
	DcdPos	aPos = Zone1PosToZone2( value.getPos() ) ;
	DcdPos	aEndPos = Zone1PosToZone2( value.getEndPos() ) ;
	return ( CdDcdZone( aPos , aEndPos - aPos ) ) ;
}

CdDcdZone CconvDcdPosOnZone_PosOrgAndRate::Zone1FromZone2( 
	const CdDcdZone& value )const 
{
	DcdPos	aPos = Zone1PosFromZone2( value.getPos() ) ;
	DcdPos	aEndPos = Zone1PosFromZone2( value.getEndPos() ) ;
	return ( CdDcdZone( aPos , aEndPos - aPos ) ) ;
}



