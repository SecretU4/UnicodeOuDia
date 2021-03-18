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
//	CDcdDiagram.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "DcDraw/CaDcdTargetClip.h"
#include "DcdCd/Pos/CLineFunc.h"
#include "DcdCd/Pos/CconvDcdPosOnZone_PosOrgAndRate.h"
#include "LogMsg\LogMsg.h"

#include "CDcdDiagram.h"
#include "..\resource.h"

#include "CCalcCentDedDgrRessyasenOfPoint.h"
#include "CRessyajouhouDraw.h"
#include "CRessyasenDraw.h"
#include "CDcdDiagram_CStopMarkDraw.h"

namespace ViewDiagram{

// ****************************************************************
//	CDcdDiagram
// ****************************************************************
/**
	�_�C���O�����r���[�́AEndPos��\�����邽�߂�
	�E�E�����̗]�T�̈���A
	DcDraw���W�n�Ŏw�肵�܂��B
	
	���̒l��0�̏ꍇ��
	�I���w(�_�C���O�������W��X.EndPos)�ƁA
	����̍Ō�̎���(�_�C���O�������W��Y.EndPos)
	���A��ʊO�ɂȂ�A�\������܂���B
*/
const int DIAGRAM_SIZE_MARGIN_DCD=2 ;

	// ********************************
	//@name �萔
	// ********************************
/**
*	�_�C���O������
*	�c�r�̊Ԋu�̑I������ێ�����e�[�u���ł��B
*/
const CDcdDiagram::VLINE	CDcdDiagram::m_arVline[8] =
{
	{  1 * 60  ,  5 * 60  , 30 * 60  } ,
	{  2 * 60  , 10 * 60  , 60 * 60  } ,
	{  5 * 60  , 10 * 60  , 60 * 60  } ,
	{ 10 * 60  , 30 * 60  , 60 * 60  } ,
	{ 15 * 60  , 15 * 60  , 60 * 60  } ,
	{ 20 * 60  , 20 * 60  , 60 * 60  } ,
	{ 30 * 60  , 30 * 60  , 60 * 60  } ,
	{ 60 * 60  , 60 * 60  , 60 * 60  } ,
};


// --------------------------------
//@name �����֐�
// --------------------------------
void CDcdDiagram::adjustProp() 
{
	// --------------------------------
	//DcdPerDgrX,DcdPerDgrY �̒l���K��
	// --------------------------------

	CconvContentPosToDcdTarget::CaConvX* pConvX = 
		m_CconvContentPosToDcdTarget.getX() ;
	// m_dwDcdPerDgrX<0.0001 �Ȃ�A0.0001
	// m_dwDcdPerDgrX �́A10�Ő���
	if ( pConvX->getTargetPosPerContent() < 0.0001 )
	{
		pConvX->setTargetPosPerContent( 0.0001 , NULL ) ;
	}
	else if ( pConvX->getTargetPosPerContent() > 10 )
	{
		pConvX->setTargetPosPerContent( 10 , NULL ) ;
	}

	CconvContentPosToDcdTarget::CaConvY* pConvY = 
		m_CconvContentPosToDcdTarget.getY() ;
	if ( pConvY->getTargetPosPerContent() < 0.0001 )
	{
		pConvY->setTargetPosPerContent( 0.0001 , NULL ) ;
	}
	else if ( pConvY->getTargetPosPerContent() > 10 )
	{
		pConvY->setTargetPosPerContent( 10 , NULL ) ;
	}
}

// ********************************
//	�R���X�g���N�^
// ********************************
CDcdDiagram::CDcdDiagram( 
		CentDedDgrDia*	pCentDedDgrDia , 
		const CdDedDispProp& aCdDedDispProp ) :
	m_pCentDedDgrDia( NULL ) ,
	m_fontpropDiaRessyaFont( 9 ,"�l�r �S�V�b�N"  ) ,
	m_colorDiaHaikeiColor( CdColorProp( 255 , 255 , 255 ) ) ,
	m_colorDiaJikuColor( CdColorProp( 0 , 0 , 0 ) ) ,
	m_bDisplayRessyabangou( true ) ,
	m_bDisplayRessyamei( true ) ,
	m_CconvContentPosToDcdTarget( 
		0 , DEFAULT_DCD_PER_DGR_X() , 0 , DEFAULT_DCD_PER_DGR_Y() ,
		DIAGRAM_SIZE_MARGIN_DCD , DIAGRAM_SIZE_MARGIN_DCD ) ,
	m_idxVlineMode( 1 ) ,
	m_bDisplayRessyasenKudari( true ) ,
	m_bDisplayRessyasenNobori( true ) ,
	m_eStopMarkDraw( EStopMarkDraw_Nothing ) 
{
	setCentDedDgrDia( pCentDedDgrDia ) ;
	readCdDedDispProp( aCdDedDispProp ) ;

	adjustProp() ;
}

CDcdDiagram::CDcdDiagram() :
	m_pCentDedDgrDia( NULL ) ,
	m_fontpropDiaRessyaFont( 9 ,"�l�r �S�V�b�N"  ) ,
	m_colorDiaHaikeiColor( CdColorProp( 255 , 255 , 255 ) ) ,
	m_colorDiaJikuColor( CdColorProp( 0 , 0 , 0 ) ) ,
	m_bDisplayRessyabangou( true ) ,
	m_bDisplayRessyamei( true ) ,
	m_CconvContentPosToDcdTarget( 
		0 , DEFAULT_DCD_PER_DGR_X() , 0 , DEFAULT_DCD_PER_DGR_Y() ,
		DIAGRAM_SIZE_MARGIN_DCD , DIAGRAM_SIZE_MARGIN_DCD ) ,
	m_idxVlineMode( 1 ) , 
	m_bDisplayRessyasenKudari( true ) ,
	m_bDisplayRessyasenNobori( true ) ,
	m_eStopMarkDraw( EStopMarkDraw_Nothing ) 
{
}

CDcdDiagram::~CDcdDiagram() 
{
}
	
// ********************************
//@name IfDcDraw
// ********************************
bool CDcdDiagram::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;

	CdDcdFreeLineProp	linepropDot( 1 , m_colorDiaJikuColor , LINESTYLE_DOT2 ) ;
	CdDcdFreeLineProp	linepropNormal( 1 , m_colorDiaJikuColor ) ;
	CdDcdFreeLineProp	linepropBold( 2 , m_colorDiaJikuColor ) ;

	// --------------------------------
	//	DcdTarget�̗̈��
	//	�N���b�s���O���s���܂��B			
	// --------------------------------
	CaDcdTargetClip*	pTargetClip = NULL ;
	{
		CdDcdZoneXy	zonexyCentDedDgrDia = getCentDedDgrDia()->getZone() ;
		//zonexyCentDedDgrDia = �_�C���O�����͈̔͂��A
		//	�w�_�C���O�����G���e�B�e�B���W�n�x�ŕێ����܂��B
		//	X���W��24���ԕ��AY���W�͋N�_����I�_�܂ł�\���܂��B
		
		CdDcdZoneXy	zonexyDcd_CentDedDgrDia = 
			DgrToDcd( pIfDcdTarget , zonexyCentDedDgrDia ) ;
		//zonexyDcd_CentDedDgrDia = 
		//	�_�C���O�����͈̔͂��A�wDcDraw���W�n�x�ŕێ����܂��B
		//	�A���A���̒l���N���b�v�̈�ɂ���ƁA
		//	EndPos�̓N���b�v�̈�Ɋ܂܂�܂���B
		zonexyDcd_CentDedDgrDia.setX( 
			CdDcdZone( 
				zonexyDcd_CentDedDgrDia.getX().getPos() ,
				zonexyDcd_CentDedDgrDia.getX().getSize() 
					+ DIAGRAM_SIZE_MARGIN_DCD ) ) ;
		zonexyDcd_CentDedDgrDia.setY( 
			CdDcdZone( 
				zonexyDcd_CentDedDgrDia.getY().getPos() ,
				zonexyDcd_CentDedDgrDia.getY().getSize() 
					+ DIAGRAM_SIZE_MARGIN_DCD ) ) ;
		//zonexyDcd_CentDedDgrDia = �_�C���O�����͈̔͂�
		//	�wDcDraw���W�n�x�ŕێ����܂��B
		
		//�N���b�v�̈�́A
		//	IfDcdTarget�̗̈��
		//	�_�C���O�����͈̔͂̌����̈�ł��B
		CdDcdZoneXy	zonexyClip = 
			pIfDcdTarget->getZone().CrossZone( zonexyDcd_CentDedDgrDia ) ;

		pTargetClip = new CaDcdTargetClip( pIfDcdTarget , zonexyClip ) ;
		pTargetClip->validate() ;
	}
	// --------------------------------
	//	�`����s���̈�̌v�Z	
	// --------------------------------
	CdDcdZoneXy	zonexyCentDedDgrDia = m_pCentDedDgrDia->getZone() ;
	//zonexyCentDedDgrDia = �_�C���O�����͈̔͂��A
	//	�w�_�C���O�����G���e�B�e�B���W�n�x�ŕێ����܂��B
	//	X���W��24���ԕ��AY���W�͋N�_����I�_�܂ł�\���܂��B
	// --------------------------------
	//	�c�r����`�悵�܂��B
	// --------------------------------
	{

		//	�c�r���́A�_�C���O�����N�_�����̎��́A�c�r���`�掞������J�n
		//	(4:01��2���ڂȂ�4:02�A1���ڂȂ�4:01�A10���ڂȂ�4:10)
		DcdPos posDgrXVlineOrg = zonexyCentDedDgrDia.getX().getPos() ;
		{
			int iMod = zonexyCentDedDgrDia.getX().getPos() % getVlinePitch() ; 
			if ( iMod > 0 )
			{
				posDgrXVlineOrg += getVlinePitch()  - iMod ;
			}
		}
		//posDgrXVlineOrg = �����\���̊J�n�ʒu
		//	�_�C���O�����N�_�����̎��̐�������J�n(4:59�Ȃ�5:00�A5:00�Ȃ�5:00)

		for ( DcdPos posDgrX = posDgrXVlineOrg ; 
				posDgrX <= zonexyCentDedDgrDia.getX().getEndPos() ; 
				posDgrX += getVlinePitch() )
		{
			//posDgrX = �_�C���O�����G���e�B�e�B���W�ł́A
			//	�c�r���̈ʒu
			CDcdFreeLine	aCDcdFreeLine ;
			if ( posDgrX % getVlineBoldPitch() == 0 )
			{
				aCDcdFreeLine.setCdLineProp( linepropBold ) ;
			}
			else if ( posDgrX % getVlineMiddlePitch() == 0 )
			{
				aCDcdFreeLine.setCdLineProp( linepropNormal ) ;
			}
			else
			{
				aCDcdFreeLine.setCdLineProp( linepropDot ) ;
			}
			//	���W���ADgr��Dcd�ɕϊ�
			DcdPos posDcdX = XDgrToDcd( pTargetClip , posDgrX ) ;
			CdDcdZone	zoneDcdY = 
				YDgrToDcd( pTargetClip , zonexyCentDedDgrDia.getY() ) ;
			if ( pTargetClip->getZone().getX().getPos() - 1 <= posDcdX &&
				posDcdX < pTargetClip->getZone().getX().getEndPos() + 1 )
			{
				aCDcdFreeLine.setOrg( CdDcdPosXy( 
					posDcdX , 
					zoneDcdY.getPos() ) ) ;
				aCDcdFreeLine.setDst( CdDcdPosXy( 
					posDcdX , 
					zoneDcdY.getEndPos() ) ) ;
				aCDcdFreeLine.DcDraw( pTargetClip ) ;

				bRv = true ;
			}
		}
	}
	// --------------------------------
	//	���r����`�悵�܂��B
	// --------------------------------
	{
		const Mu<CentDedDgrEki>* pCentDedDgrEkiCont = 
			m_pCentDedDgrDia->getCentDedDgrEkiCont() ;
		for ( int iEkiIndex = 0 ; 
				iEkiIndex < pCentDedDgrEkiCont->size() ; 
				iEkiIndex ++ )
		{
			CentDedDgrEki	aCentDedDgrEki = 
				pCentDedDgrEkiCont->get( iEkiIndex ) ;
			DcdPos posDgrY = m_pCentDedDgrDia->getDgrYPosOfEki( iEkiIndex ) ;
			CDcdFreeLine	aCDcdFreeLine ;
			if ( aCentDedDgrEki.getIsSyuyoueki() )
			{
				aCDcdFreeLine.setCdLineProp( linepropBold ) ;
			}
			else
			{
				aCDcdFreeLine.setCdLineProp( linepropNormal ) ;
			}
			//	���W���ADgr��Dcd�ɕϊ�
			DcdPos	posDcdY = YDgrToDcd( pTargetClip , posDgrY ) ;
			CdDcdZone	zoneDcdX = 
				XDgrToDcd( pTargetClip , zonexyCentDedDgrDia.getX() ) ;
			if ( pTargetClip->getZone().getY().getPos() - 1 <= posDcdY &&
				 posDcdY < pTargetClip->getZone().getY().getEndPos() + 1 )
			{
				aCDcdFreeLine.setOrg( CdDcdPosXy( 
					zoneDcdX.getPos() , 
					posDcdY ) ) ;
				aCDcdFreeLine.setDst( CdDcdPosXy( 
					zoneDcdX.getEndPos() , 
					posDcdY ) ) ;
				aCDcdFreeLine.DcDraw( pTargetClip ) ;
			}
		}
		
		
	}
	// --------------------------------
	//	��Ԑ���`�悵�܂��B
	// --------------------------------
	{
		CRessyasenDraw	aCRessyasenDraw( this , pTargetClip , 
			m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori ) ;
		aCRessyasenDraw.execute() ;
	}
	// --------------------------------
	//	��ԏ���`�悵�܂��B
	// --------------------------------
	{
		CRessyajouhouDraw	aCRessyajouhouDraw( this , pTargetClip ,
			m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori ) ;
		aCRessyajouhouDraw.execute() ;
	}

	// --------------------------------
	//	��ԋL����`�悵�܂��B
	// --------------------------------
	{
		CDcdDiagram_CStopMarkDraw	aCDcdDiagram_CStopMarkDraw( 
			this , pTargetClip ,
			m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori ) ;
		aCDcdDiagram_CStopMarkDraw.execute() ;
	}
	// --------------------------------
	if ( pTargetClip != NULL )
	{
		delete pTargetClip ;
		pTargetClip = NULL ;
	}
	return ( bRv ) ;
}
bool CDcdDiagram::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	bool bRv = false ;
	*pCdDcdSizeXy = CdDcdSizeXy() ;
	return ( bRv ) ;
}
	
// ********************************
//	CdDedDispProp
// ********************************
	// ********************************
	//@name CDcdDiagram-�֘A
	// ********************************
CentDedDgrDia*	CDcdDiagram::getCentDedDgrDia()
{
	return m_pCentDedDgrDia ;
};
CDcdDiagram& CDcdDiagram::setCentDedDgrDia( CentDedDgrDia* value )
{
	if ( m_pCentDedDgrDia != value )
	{
		m_pCentDedDgrDia = value ; 
		if ( m_pCentDedDgrDia != NULL )
		{
			m_CconvContentPosToDcdTarget.setContentPosAndRate( 
				CdDcdPosXy( 
					m_pCentDedDgrDia->getZone().getX().getPos() , 
					m_pCentDedDgrDia->getZone().getY().getPos() ) ,
				DEFAULT_DCD_PER_DGR_X() ,
				DEFAULT_DCD_PER_DGR_Y() , 
				NULL ) ;
				
		}
		else
		{
			// --------------------------------
			//	m_zonexyZone_Dgr �Ƀf�t�H���g�l��ݒ�
			// --------------------------------
			m_CconvContentPosToDcdTarget.setContentPosAndRate( 
				CdDcdPosXy() ,
				DEFAULT_DCD_PER_DGR_X() ,
				DEFAULT_DCD_PER_DGR_Y() ,
				NULL ) ;

		}
	}
	
	// --------------------------------
	
	return *this ; 
} ;

	// ********************************
	//@name CDcdDiagram-����-CdDedDispProp ����ǂݍ��݉\
	// ********************************
CdFontProp	CDcdDiagram::getDiaRessyaFont()const{
		return 	m_fontpropDiaRessyaFont ;};
CDcdDiagram& CDcdDiagram::setDiaRessyaFont( const CdFontProp& value ){
		m_fontpropDiaRessyaFont = value ; return *this ;};
CdColorProp	CDcdDiagram::getDiaHaikeiColor()const{
		return m_colorDiaHaikeiColor ;};
CDcdDiagram& CDcdDiagram::setDiaHaikeiColor( CdColorProp value ){
		m_colorDiaHaikeiColor = value ; return *this ;};
CdColorProp	CDcdDiagram::getDiaJikuColor()const{
		return m_colorDiaJikuColor ;};
CDcdDiagram& CDcdDiagram::setDiaJikuColor( CdColorProp value ){
		m_colorDiaJikuColor = value ; return *this ;};

	// ********************************
	//@name CDcdDiagram-����-CdDedDispProp �ɂ͂Ȃ�����
	// ********************************
bool	CDcdDiagram::getDisplayRessyabangou()const{
		return m_bDisplayRessyabangou ;};
CDcdDiagram& CDcdDiagram::setDisplayRessyabangou( bool value ){
		m_bDisplayRessyabangou = value ; return *this ;};
bool	CDcdDiagram::getDisplayRessyamei()const{
		return m_bDisplayRessyamei ;};
CDcdDiagram& CDcdDiagram::setDisplayRessyamei( bool value )
{
		m_bDisplayRessyamei = value ; 
		return *this ;
};

CdDcdPosXy	CDcdDiagram::getPosDgr()const 
{
	return CdDcdPosXy( 
		m_CconvContentPosToDcdTarget.getContentPos() ) ; 
}
void	CDcdDiagram::setPosDgr(CdDcdPosXy posPosDgr ) 
{
	m_CconvContentPosToDcdTarget.setContentPos( posPosDgr ) ;

	adjustProp() ;
}
double CDcdDiagram::getDcdPerDgrX( IfDcdTarget* pIfDcdTarget ) 
{
	return m_CconvContentPosToDcdTarget.getX()
		->getTargetPosPerContent( pIfDcdTarget ) ;
}
void CDcdDiagram::setDcdPerDgrX( IfDcdTarget* pIfDcdTarget , double dDcdPerDgr ) 
{
	m_CconvContentPosToDcdTarget.getX()->setTargetPosPerContent(
		dDcdPerDgr , pIfDcdTarget ) ;
	adjustProp() ;
}

double CDcdDiagram::getDcdPerDgrY(IfDcdTarget* pIfDcdTarget) 
{
	return m_CconvContentPosToDcdTarget.getY()
		->getTargetPosPerContent(pIfDcdTarget) ;
}

void CDcdDiagram::setDcdPerDgrY( 
	IfDcdTarget* pIfDcdTarget , 
	double dDcdPerDgr ) 
{
	m_CconvContentPosToDcdTarget.getY()->setTargetPosPerContent(
		dDcdPerDgr , pIfDcdTarget ) ;
	adjustProp() ;
}

	

int	CDcdDiagram::getVlineMode()const{	return m_idxVlineMode ;};
CDcdDiagram& CDcdDiagram::setVlineMode( int value )
{
	if ( value >= sizeof(m_arVline) / sizeof(m_arVline[0]) ){
		value = sizeof(m_arVline) / sizeof(m_arVline[0]) - 1 ;
	}
	if ( value < 0 ){
		value = 0 ;
	}
	m_idxVlineMode = value ; 
	return *this ; 
} ;

bool CDcdDiagram::getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const 
{
	bool bRv = false ;
	if ( eRessyahoukou == Ressyahoukou_Kudari ){
		bRv = m_bDisplayRessyasenKudari ;
	}	else if ( eRessyahoukou == Ressyahoukou_Nobori ) {
		bRv = m_bDisplayRessyasenNobori ;
	}
	return ( bRv ) ;
}
CDcdDiagram& CDcdDiagram::setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) 
{
	if ( eRessyahoukou == Ressyahoukou_Kudari ){
		m_bDisplayRessyasenKudari = value ;
	}	else if ( eRessyahoukou == Ressyahoukou_Nobori ) {
		m_bDisplayRessyasenNobori = value ;
	}
	return ( *this ) ;
}


int CDcdDiagram::getVlinePitch()const 
{
	return ( m_arVline[m_idxVlineMode].m_iVlinePitch ) ;
}
int CDcdDiagram::getVlineMiddlePitch()const 
{
	return ( m_arVline[m_idxVlineMode].m_iVlineMiddlePitch ) ;
}
int CDcdDiagram::getVlineBoldPitch()const 
{
	return ( m_arVline[m_idxVlineMode].m_iVlineBoldPitch ) ;
}

int CDcdDiagram::
	getVlineChoices( Mui<VLINE>* pContVLINE )const 
{
	if ( pContVLINE != NULL ){
		pContVLINE->erase( 0 , INT_MAX ) ;
		for ( int idx = 0 ; idx < sizeof(m_arVline) / sizeof(m_arVline[0]) ; 
				idx ++ ){
			pContVLINE->insert( m_arVline[idx] ) ;
		}
	}
	return sizeof(m_arVline) / sizeof(m_arVline[0]) ;
}

	// ********************************
	//@name CDcdDiagram-����
	// ********************************

CDcdDiagram& CDcdDiagram::readCdDedDispProp( const CdDedDispProp& value ) 
{
	m_fontpropDiaRessyaFont = value.getDiaRessyaFont();
	m_colorDiaHaikeiColor = value.getDiaHaikeiColor() ;
	m_colorDiaJikuColor = value.getDiaJikuColor() ;
	return *this ;
}

CdDcdZoneXy	CDcdDiagram::getZone_Dgr( IfDcdTarget* pIfDcdTarget )
{
	return m_CconvContentPosToDcdTarget.getContentZone(pIfDcdTarget) ;
};

void CDcdDiagram::setZone_Dgr( 
	IfDcdTarget* pIfDcdTarget , 
	const CdDcdZoneXy& value )
{
	m_CconvContentPosToDcdTarget.setContentZone(value , pIfDcdTarget) ;

	adjustProp() ;

} ;

bool CDcdDiagram::getKeepZoneDgrOnSize()const
{
	return ( m_CconvContentPosToDcdTarget.getMode() == 
		CconvContentPosToTarget::EModeZone ) ;
}		

void CDcdDiagram::setKeepZoneDgrOnSize( bool bRv )
{
	CconvContentPosToTarget::EMode	eMode = 
		CconvContentPosToTarget::EModePosAndRate ;
	if ( bRv )
	{
		eMode = CconvContentPosToTarget::EModeZone ;
	}
	m_CconvContentPosToDcdTarget.setMode( eMode ) ;
}		



int CDcdDiagram::calcCentDedDgrRessyasenOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdPosXy& aCdDcdPosXy ,  
		int iMerginPixels ,
		ERessyahoukou *pERessyahoukou , 
		int *piRessyaIdx , 
		int *piRessyasenIdx ) 
{
	LogMsg( "CDcdDiagram::calcCentDedDgrRessyasenOfPoint(,(%d,%d)) " ,
		aCdDcdPosXy.getX() , aCdDcdPosXy.getY() ) ;
 

	int iRv = 0 ;
	if ( pIfDcdTarget->getZone().IsInner( aCdDcdPosXy ) ){
		CCalcCentDedDgrRessyasenOfPoint aEnum( this , pIfDcdTarget ,
			aCdDcdPosXy , iMerginPixels , 
			getDisplayRessyasen( Ressyahoukou_Kudari ) , 
			getDisplayRessyasen( Ressyahoukou_Nobori ) ) ;
		aEnum.execute() ;
		if ( aEnum.getRessyaIdx() >= 0 && aEnum.getRessyasenIdx() >= 0 ){
			*pERessyahoukou = aEnum.getRessyahoukou() ; 
			*piRessyaIdx = aEnum.getRessyaIdx() ; 
			*piRessyasenIdx = aEnum.getRessyasenIdx() ; 

			LogMsg( "\tERessyahoukou=%d iRessyaIdx=%d iRessyasenIdx=%d" , 
				*pERessyahoukou ,
				*piRessyaIdx ,
				*piRessyasenIdx ) ;

			iRv = 1 ;
		}
	}
	LogMsg( "CDcdDiagram::calcCentDedDgrRessyasenOfPoint()=%d " ,iRv ) ;
	return ( iRv ) ;
}


int CDcdDiagram::calcEkiOrderOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		ERessyahoukou eRessyahoukou ,
		DcdPos posY_Dcd )  
{
	int iEkiOrder = -1 ;
	if ( pIfDcdTarget->getZone().getY().IsInner( posY_Dcd ) ){
		const Mu<CentDedDgrEki>* pCentDedDgrEkiCont 
			= getCentDedDgrDia()->getCentDedDgrEkiCont() ;
		CentDedDgrDia* pCentDedDgrDia = getCentDedDgrDia() ;
		for ( iEkiOrder = pCentDedDgrEkiCont->size() - 1 ; 
				iEkiOrder >= 0 ; 
				iEkiOrder -- ){
			int iY_Dgr = pCentDedDgrDia->getDgrYPosOfEki( 
				eRessyahoukou , iEkiOrder ) ;
			int iY_Dcd = YDgrToDcd( pIfDcdTarget , iY_Dgr ) ;
			if ( eRessyahoukou == Ressyahoukou_Kudari ){
				if ( iY_Dcd <= posY_Dcd ){
					break ;
				}
			}	else	{
				if ( iY_Dcd >= posY_Dcd ){
					break ;
				}
			}
		}
	}
	return ( iEkiOrder ) ;
}


	// ********************************
	//@name CDcdDiagram-�_�C���O�������W�ƁAIfDcdTarget ��̍��W��ϊ�
	// ********************************
DcdPos CDcdDiagram::XDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	return m_CconvContentPosToDcdTarget.getX()->ContentPosToTarget(
		posSrc , pIfDcdTarget ) ;
}

DcdPos CDcdDiagram::YDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	return m_CconvContentPosToDcdTarget.getY()->ContentPosToTarget(
		posSrc , pIfDcdTarget ) ;
}

DcdPos CDcdDiagram::XDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	return m_CconvContentPosToDcdTarget.getX()->ContentPosFromTarget(
		posSrc , pIfDcdTarget ) ;
}

DcdPos CDcdDiagram::YDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	return m_CconvContentPosToDcdTarget.getY()->ContentPosFromTarget(
		posSrc , pIfDcdTarget ) ;
}

CdDcdZone CDcdDiagram::XDgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	return m_CconvContentPosToDcdTarget.getX()->ContentZoneToTarget(
		zoneSrc , pIfDcdTarget ) ;

}

CdDcdZone CDcdDiagram::YDgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	return m_CconvContentPosToDcdTarget.getY()->ContentZoneToTarget(
		zoneSrc , pIfDcdTarget ) ;
}

CdDcdZone CDcdDiagram::XDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	return m_CconvContentPosToDcdTarget.getX()->ContentZoneFromTarget(
		zoneSrc , pIfDcdTarget ) ;
}

CdDcdZone CDcdDiagram::YDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	return m_CconvContentPosToDcdTarget.getY()->ContentZoneFromTarget(
		zoneSrc , pIfDcdTarget ) ;
}



CdDcdPosXy CDcdDiagram::DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) 
{
	return m_CconvContentPosToDcdTarget.ContentPosToTarget( 
		posSrc , 
		pIfDcdTarget ) ;
}
CdDcdPosXy CDcdDiagram::DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) 
{
	return m_CconvContentPosToDcdTarget.ContentPosFromTarget( 
		posSrc , 
		pIfDcdTarget ) ;
}


CdDcdZoneXy CDcdDiagram::DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) 
{
	return m_CconvContentPosToDcdTarget.ContentZoneToTarget( 
		zoneSrc , 
		pIfDcdTarget ) ;
}

CdDcdZoneXy CDcdDiagram::DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) 
{
	return m_CconvContentPosToDcdTarget.ContentZoneFromTarget( 
		zoneSrc , 
		pIfDcdTarget ) ;
}
} //namespace ViewDiagram
