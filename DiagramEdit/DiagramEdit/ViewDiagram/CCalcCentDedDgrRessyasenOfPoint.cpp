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
//	CCalcCentDedDgrRessyasenOfPoint.cpp
// $Id: CCalcCentDedDgrRessyasenOfPoint.cpp 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "DcdCd\Pos\CLineFunc.h"
#include "LogMsg\LogMsg.h"

#include "CCalcCentDedDgrRessyasenOfPoint.h"

namespace ViewDiagram{

CCalcCentDedDgrRessyasenOfPoint::CCalcCentDedDgrRessyasenOfPoint(
		CDcdDiagram* pCDcdDiagram , 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdPosXy& aCdDcdPosXy , int iMarginPixels ,
		bool bDisplayRessyasenKudari , bool bDisplayRessyasenNobori ) : 
	super( pCDcdDiagram->getCentDedDgrDia() , 
		pCDcdDiagram->DgrFromDcd( pIfDcdTarget , pIfDcdTarget->getZone() ) , 
		bDisplayRessyasenKudari , 
		bDisplayRessyasenNobori ) , 
	m_pCDcdDiagram( pCDcdDiagram ) ,
	m_pIfDcdTarget( pIfDcdTarget ) ,
	m_CdDcdPosXy( aCdDcdPosXy ) ,
	m_iMerginPixels( iMarginPixels ) ,
	m_eRessyahoukou( Ressyahoukou_Kudari ) ,
	m_iRessyaIdx( -1 ) ,
	m_iRessyasenIdx( -1 )
{
};

void CCalcCentDedDgrRessyasenOfPoint::onCentDedDgrRessyasen( 
			ERessyahoukou eRessyahoukou ,
			int iRessyaIdx ,
			const CentDedDgrRessya* pCentDedDgrRessya ,
			int iRessyasenIdx ,
			const CentDedDgrRessyasen* pCentDedDgrRessyasen ) 
{
	//	��Ԑ����������Ă���ꍇ�́A
	//	���̌�̏����͍s�킸�Ƀ��^�[��
	if ( m_iRessyaIdx != -1 )
	{
		return ;
	}	
	// --------------------------------
	CdDcdPosXy	posDgrPosRessyasenKiten = 
		getCentDedDgrDia()->calcDgrPosRessyasenKiten( 
			pCentDedDgrRessya , 
			pCentDedDgrRessyasen ) ;
	CdDcdPosXy	posDgrPosRessyasenSyuuten = 
		getCentDedDgrDia()->calcDgrPosRessyasenSyuuten( 
			pCentDedDgrRessya , 
			pCentDedDgrRessyasen ) ;
	//posDgrPosRessyasenKiten,posDgrPosRessyasenSyuuten = 
	//	���̗�Ԑ��̋N�_�ƏI�_�̍��W���A
	//	Dgr���W�n�ŕ\���܂��B

	CLineFunc aCLineFunc( 
		m_pCDcdDiagram->DgrToDcd( m_pIfDcdTarget , 
			posDgrPosRessyasenKiten )  , 
		m_pCDcdDiagram->DgrToDcd( m_pIfDcdTarget , 
			posDgrPosRessyasenSyuuten ) ) ;
	//aCLineFunc = 
	//	���̗�Ԑ��̋N�_����I�_�܂ł����Ԓ������A
	//	DcDraw ���W�n�ŕ\���܂��B

	LogMsg( "CCalcCentDedDgrRessyasenOfPoint::onCentDedDgrRessyasen("
		"eRessyahoukou=%d ,iRessyaIdx=%d ,,iRessyasenIdx =%d,)"  ,
		eRessyahoukou ,
		iRessyaIdx ,
		iRessyasenIdx  ) ; 
	LogMsg( "\taCLineFunc.Pos1=%d,%d , Pos2=%d,%d   m_CdDcdPosXy=%d,%d" , 
		aCLineFunc.getPos1().getX() , 
		aCLineFunc.getPos1().getY() , 
		aCLineFunc.getPos2().getX() , 
		aCLineFunc.getPos2().getY() ,
		m_CdDcdPosXy.getX() , m_CdDcdPosXy.getY() ) ;

	// --------------------------------
	//	�u�w�����Ώۓ_�x���A��Ԑ��̎n�_�E�I�_���܂��钷���`��
	//	�͈͓��ɂ��邩�v�𔻒�
	// --------------------------------
	{
		CdDcdZone	zoneDcdXBoundRessyasen ;
		{
			zoneDcdXBoundRessyasen.setBeginEndPos( 
				aCLineFunc.getPos1().getX() ,
				aCLineFunc.getPos2().getX() ) ;
			//	�T�C�Y��0�̏ꍇ�́A1�ɍœK�����܂��B
			//	�n�_�ƏI�_��X���W���������ꍇ(������)
			//	���Y�����܂��B
			if ( zoneDcdXBoundRessyasen.getSize() == 0 )
			{
				zoneDcdXBoundRessyasen.setSize( 1 ) ;
			}
		}
		//zoneDcdXBoundRessyasen = 
		//	��Ԑ��̋N�_����I�_�܂ł�X���W�̗̈�ł��B
		//	Dcd���W�n�ŕ\���܂��B
		//	�T�C�Y��0�̏ꍇ�́A1�ɍœK�����܂��B

		CdDcdZone	zoneDcdYBoundRessyasen ;
		{
			zoneDcdYBoundRessyasen.setBeginEndPos( 
				aCLineFunc.getPos1().getY() ,
				aCLineFunc.getPos2().getY() ) ;

			//	�T�C�Y��0�̏ꍇ�́A1�ɍœK�����܂��B
			//	�n�_�ƏI�_��Y���W���������ꍇ(������)�ꍇ
			//	���Y�����܂��B
			if ( zoneDcdYBoundRessyasen.getSize() == 0 )
			{
				zoneDcdYBoundRessyasen.setSize( 1 ) ;
			}
		}
		//zoneDcdYBoundRessyasen = 
		//	��Ԑ��̋N�_����I�_�܂ł�Y���W�̗̈�ł��B
		//	Dcd���W�n�ŕ\���܂��B
		//	�T�C�Y��0�̏ꍇ�́A1�ɍœK�����܂��B

		CdDcdZoneXy	zonexyDcdBoundRessyasen( 
			zoneDcdXBoundRessyasen ,
			zoneDcdYBoundRessyasen ) ;
		//zonexyDcdBoundRessyasen = 
		//	��Ԑ��̋N�_����I�_�܂ł��͂ޒ����`�̗̈�ł��B
		//	X,Y�Ƃ��A�T�C�Y��0�̏ꍇ�́A1�ɍœK�����܂��B
		//���R�F
		//	��Ԑ����������̏ꍇ�A���ʂɌv�Z����ƁA
		//	zonexyDcdBoundRessyasen�� X��Size �́A0�ɂȂ�܂��B
		//	�������AzonexyDcdBoundRessyasen�� X �܂��� Y �� Size ��
		//	0 ���ƁA zonexyDcdBoundRessyasen.IsInner() �̌��ʂ͏��
		//	false �ɂȂ�A�͈͓��̔��肪�������ł��܂���B
		//	���������邽�߂ɁAX,Y��Size�́A0 �̏ꍇ�� 1�ɍœK�����܂��B

		if ( !zonexyDcdBoundRessyasen.IsInner( m_CdDcdPosXy ) )
		{
			//	�w�����Ώۓ_�x���A��Ԑ��̎n�_�E�I�_���܂��钷���`��
			//	�͈͓��ɂ���܂���B
			return ;
		}
	}
	// --------------------------------
	//	�����Ώۓ_���A��Ԑ��̐���ɂ��邱�Ƃ𔻒�
	// --------------------------------
	if ( abs( aCLineFunc.getPos1().getX() - aCLineFunc.getPos2().getX() ) >
		abs( aCLineFunc.getPos1().getY() - aCLineFunc.getPos2().getY() ) )
	{
		//	X�̕���������Ԑ�
		int iY = aCLineFunc.calcYofX( m_CdDcdPosXy.getX() ) ;
		if ( abs( iY - m_CdDcdPosXy.getY() ) <= m_iMerginPixels )
		{
			LogMsg( "\tfind iY=%d" , iY ) ;
			m_eRessyahoukou = eRessyahoukou ;
			m_iRessyaIdx = iRessyaIdx ;
			m_iRessyasenIdx = iRessyasenIdx ;
		}
	}
	else
	{
		//	Y�̕���������Ԑ�
		int iX = aCLineFunc.calcXofY( m_CdDcdPosXy.getY() ) ;
		if ( abs( iX - m_CdDcdPosXy.getX() ) <= m_iMerginPixels )
		{
			LogMsg( "\tfind iX=%d" , iX ) ;
			m_eRessyahoukou = eRessyahoukou ;
			m_iRessyaIdx = iRessyaIdx ;
			m_iRessyasenIdx = iRessyasenIdx ;
		}
	} 
	//m_eRessyahoukou,m_iRessyaIdx,m_iRessyasenIdx = 
	//	�����Ώۓ_��ʂ��Ԑ������������ꍇ�́A
	//	���̗�Ԑ������������ƂȂ�܂��B
};
} //namespace ViewDiagram
