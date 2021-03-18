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
//	CDcdDiagram2.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "str\StrToInt.h"
#include "DcDraw\CDcdText.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CDcdLine.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDraw\CaDcdTargetClip.h"
#include "DcdCd\DcDrawProp/CdPenProp.h"
#include "LogMsg\LogMsg.h"

#include "CDcdDiagram2.h"
#include "..\DiagramEdit.h"

namespace ViewDiagram{

using namespace std ;
using namespace OuLib::Str;
// ****************************************************************
//	CDcdDiagram2
// ****************************************************************
	// --------------------------------
	//@name �����֐�
	// --------------------------------
CdDcdFreeLineProp	CDcdDiagram2::getCdLinePropNormal()const
{
	return CdDcdFreeLineProp( 1 , m_pCDcdDiagram->getDiaJikuColor() ) ;
};

CdDcdFreeLineProp	CDcdDiagram2::getCdLinePropBold()const
{
	return CdDcdFreeLineProp( 2 , m_pCDcdDiagram->getDiaJikuColor() ) ;
};	

CDcdText	CDcdDiagram2::getCDcdTextJikoku()const
{
	return CDcdText( "" , 
		CdDrawTextProp( m_fontpropDiaJikokuFont , m_colorDiaMojiColor ) ,
		"00" ) ;
};

CDcdText	CDcdDiagram2::getCDcdTextEkimei()const
{
	string strExtent ;
	for ( int idx = 0 ; idx < m_iEkimeiLength ; idx ++ ){
		strExtent += "��" ;
	}
	//strExtent = �H���t�@�C���f�[�^�ɕۑ�����Ă���l�����Ƃɂ��āA
	//	�쐬�����A�����񕝂̊������ł��B

	return CDcdText( "" , 
		CdDrawTextProp( m_fontpropDiaEkimeiFont , m_colorDiaMojiColor ) ,
		strExtent ) ;
};

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CDcdDiagram2::CDcdDiagram2( 
		CentDedDgrDia*	pCentDedDgrDia , 
		const CdDedDispProp& aCdDedDispProp ) 
	: m_fontpropDiaEkimeiFont( 9 ,"�l�r �S�V�b�N"  )
	, m_fontpropDiaJikokuFont( 9 ,"�l�r �S�V�b�N"  )
	, m_colorDiaMojiColor( CdColorProp( 0 , 0 , 0 ) ) 
	, m_iEkimeiLength( 6 )
	, m_bHideIppanekiEkimei( false ) 
{
	m_pCDcdDiagram = new CDcdDiagram( 
		pCentDedDgrDia , 
		aCdDedDispProp ) ;
	m_fontpropDiaEkimeiFont = aCdDedDispProp.getDiaEkimeiFont() ;
	m_fontpropDiaJikokuFont = aCdDedDispProp.getDiaJikokuFont() ;
	m_colorDiaMojiColor = aCdDedDispProp.getDiaMojiColor() ;
}


CDcdDiagram2::CDcdDiagram2() 
	: m_fontpropDiaEkimeiFont( 9 ,"�l�r �S�V�b�N"  )
	, m_fontpropDiaJikokuFont( 9 ,"�l�r �S�V�b�N"  )
	, m_colorDiaMojiColor( CdColorProp( 0 , 0 , 0 ) ) 
	, m_iEkimeiLength( 6 )
	, m_bHideIppanekiEkimei( false ) 
{
	m_pCDcdDiagram = new CDcdDiagram() ;
}
CDcdDiagram2::~CDcdDiagram2() 
{
	if ( m_pCDcdDiagram != NULL ){
		delete m_pCDcdDiagram ;
		m_pCDcdDiagram = NULL ;
	}
}
	
	// ********************************
	//@name IfDcDraw
	// ********************************

bool CDcdDiagram2::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;
	CentDedDgrDia* pCentDedDgrDia = m_pCDcdDiagram->getCentDedDgrDia() ;

	// --------------------------------
	//	�_�C���O�����̊e�\���v�f�̃T�C�Y���v�Z
	// --------------------------------
	CdDcdFreeLineProp	linepropNormal( getCdLinePropNormal() ) ;
	CdDcdFreeLineProp	linepropBold( getCdLinePropBold() ) ;

	CDcdText	dcdtextJikoku( getCDcdTextJikoku() ) ;
	CdDcdSizeXy	sizeJikoku ;
	dcdtextJikoku.getItemSize( pIfDcdTarget , &sizeJikoku ) ;
	//dcdtextJikoku = �����e�L�X�g�`����s��DcDraw�I�u�W�F�N�g�𐶐����܂����B
	//sizeJikoku = �����e�L�X�g�`����s��DcDraw�I�u�W�F�N�g�̃T�C�Y(�_�����W)

	CDcdText	dcdtextEkimei( getCDcdTextEkimei() ) ;
	CdDcdSizeXy	sizeEkimei ;
	dcdtextEkimei.getItemSize( pIfDcdTarget , &sizeEkimei ) ;
	//dcdtextEkimei = �w���e�L�X�g�̕`����s��DcDraw�I�u�W�F�N�g�𐶐����܂����B
	//sizeEkimei = �w���e�L�X�g�̕`����s��DcDraw�I�u�W�F�N�g�̃T�C�Y(�_�����W)

	CdDcdZoneXy	zonexyDiagram = calcDiagramZoneDcd( pIfDcdTarget );
	//zonexyDiagram = �_�C���O�����̕`����s���̈�i�_�����W�j
	// --------------------------------
	CaDcdTargetItemPosition	targetDiagram( pIfDcdTarget , zonexyDiagram ) ;
		//targetDiagram = �_�C���O�����̕`����s���̈��DcDraw�I�u�W�F�N�g
	

	// --------------------------------
	//	�`����s���̈�̌v�Z	
	// --------------------------------
	CdDcdZoneXy	zonexyCentDedDgrDia = getCentDedDgrDia()->getZone() ;
	//zonexyCentDedDgrDia = �_�C���O�����͈̔͂��A
	//	�w�_�C���O�����G���e�B�e�B���W�n�x�ŕێ����܂��B
	//	X���W��24���ԕ��AY���W�͋N�_����I�_�܂ł�\���܂��B

	// --------------------------------
	//	���̕`��
	// --------------------------------
	{
		CdDcdZoneXy	zonexyJikokuDcd = calcJikokuZoneDcd( pIfDcdTarget );
		//zonexyEkimeiDcd = ���\��������DcDraw���W�ɂ��͈�

		CaDcdTargetItemPosition	targetitemposJikoku( pIfDcdTarget , zonexyJikokuDcd ) ;
		CaDcdTargetClip targetJikoku( &targetitemposJikoku , zonexyJikokuDcd ) ;

		//	�����\���́A�_�C���O�����N�_�����̎��̐�������J�n(4:59�Ȃ�5:00�A5:00�Ȃ�5:00)
		DcdPos posDgrXJikokuhyoujiOrg = zonexyCentDedDgrDia.getX().getPos() ;
		{
			int iMod = zonexyCentDedDgrDia.getX().getPos() % ( 60 * 60 ); 
			if ( iMod > 0 )
			{
				posDgrXJikokuhyoujiOrg += ( 60 * 60 ) - iMod ;
			}
		}
		//posDgrXJikokuhyoujiOrg = �����\���̊J�n�ʒu
		//	�_�C���O�����N�_�����̎��̐�������J�n(4:59�Ȃ�5:00�A5:00�Ȃ�5:00)

		for ( DcdPos posDgrX = posDgrXJikokuhyoujiOrg; 
				posDgrX <= zonexyCentDedDgrDia.getX().getEndPos() ; 
				posDgrX += 60 * 60 )
		{
			//posDgrX = �_�C���O�����G���e�B�e�B���W�ł́A
			//	�����\���̈ʒu

			//	�����̃e�L�X�g��ݒ�
			dcdtextJikoku.setText( 
				stringOf( CdDedJikoku( posDgrX ).getHour() ) ) ;

			//	���W���ADgr��Dcd�ɕϊ�
			DcdPos posDcdX = XDgrToDcd( pIfDcdTarget , posDgrX ) ;
			{
				CdDcdZoneXy	zonexyDcdZoneXy( 
					CdDcdZone( posDcdX , sizeJikoku.getX() ) ,
					zonexyJikokuDcd.getY() ) ;
				CaDcdTargetItemPosition	aTarget( &targetJikoku , zonexyDcdZoneXy ) ;
				if ( aTarget.isDrawable() )
				{
					dcdtextJikoku.DcDraw( &aTarget ) ;
					bRv = true ;
				}
			}
		}
	}
	// --------------------------------
	//	�w�����̌r��
	//	�w���E�̌r��
	// --------------------------------
	{

		CdDcdZoneXy	zonexyEkimeiDcd = calcEkimeiZoneDcd( pIfDcdTarget );
		//zonexyEkimeiDcd = �w���\��������DcDraw���W�ɂ��͈�

		CaDcdTargetItemPosition	targetitemposEkimei( pIfDcdTarget , zonexyEkimeiDcd ) ;
		CaDcdTargetClip targetEkimei( &targetitemposEkimei , zonexyEkimeiDcd ) ;

		// --------------------------------
		//CDcdLine ���g�����r���`��
		// --------------------------------
		{

			CdDcdZone	zoneDcdY ;
			{
				CdDcdZone	zoneDgrY ;
				{
					const Mu<CentDedDgrEki>*	pCentDedDgrEkiCont = 
						pCentDedDgrDia->getCentDedDgrEkiCont() ;
					zoneDgrY.setBeginEndPos( 
						pCentDedDgrDia->getDgrYPosOfEki( 0 ) ,
						pCentDedDgrDia->getDgrYPosOfEki( 
							pCentDedDgrEkiCont->size() - 1  ) );
				}
				//zoneDgrY = �n���w�E�I���w�̃_�C���O�������W�ɂ��Y���W�͈�
				zoneDcdY = YDgrToDcd( &targetEkimei , zoneDgrY ) ;
				//zoneDcdY = �n���w�E�I���w��DcDrawe���W�ɂ��Y���W�͈�

				zoneDcdY = zonexyEkimeiDcd.getY().CrossZone( zoneDcdY ) ;
				//zoneDcdY =	�c����`�悷��͈͂� DcDraw���W
			}
			//zoneDcdY =	�c����`�悷��͈͂� DcDraw���W



			CDcdLine	aCDcdLine( 
				CdPenProp( 
					linepropBold.getLogicalunitWidth() , 
					linepropBold.getColor() ) ) ;
			{
				CaDcdTargetItemPosition	aTargetItemPosition( 
					&targetEkimei ,
					CdDcdZoneXy( 
						CdDcdZone( 
							zonexyEkimeiDcd.getX().getPos() , 
							linepropBold.getLogicalunitWidth() ) ,
						zoneDcdY 
					) ) ;
				if ( aTargetItemPosition.isDrawable() )
				{
					aCDcdLine.DcDraw( &aTargetItemPosition ) ;
					bRv = true ;
				}
			}
			{
				CaDcdTargetItemPosition	aTargetItemPosition( 
					&targetEkimei ,
					CdDcdZoneXy( 
						CdDcdZone( 
							zonexyEkimeiDcd.getX().getEndPos() - linepropBold.getLogicalunitWidth(), 
							linepropBold.getLogicalunitWidth() ) ,
						zoneDcdY 
					) ) ;
				if ( aTargetItemPosition.isDrawable() )
				{
					aCDcdLine.DcDraw( &aTargetItemPosition ) ;
					bRv = true ;
				}
			}
		}
	}
	// --------------------------------
	//	���r���E�w���̕`��
	// --------------------------------
	{
		CdDcdZoneXy	zonexyEkimeiDcd = calcEkimeiZoneDcd( pIfDcdTarget );
		//zonexyEkimeiDcd = �w���\��������DcDraw���W�ɂ��Y���W�͈�

		CaDcdTargetItemPosition	targetitemposEkimei( pIfDcdTarget , zonexyEkimeiDcd ) ;
		CaDcdTargetClip targetEkimei( &targetitemposEkimei , zonexyEkimeiDcd ) ;


		const Mu<CentDedDgrEki>* pCentDedDgrEkiCont = 
			getCentDedDgrDia()->getCentDedDgrEkiCont() ;
		// --------------------------------
		//	�w�����̌r��
		// --------------------------------
		for ( int iEkiIndex = 0 ; 
				iEkiIndex < pCentDedDgrEkiCont->size() ; 
				iEkiIndex ++ )
		{
			CentDedDgrEki	aCentDedDgrEki = 
				pCentDedDgrEkiCont->get( iEkiIndex ) ;
			DcdPos posDgrY = getCentDedDgrDia()->getDgrYPosOfEki( iEkiIndex ) ;
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
			DcdPos	posDcdY = YDgrToDcd( pIfDcdTarget , posDgrY ) ;
			CdDcdZone	zoneDcdX = zonexyEkimeiDcd.getX() ;
			
			//	���r���`��
			if ( targetEkimei.getZone().getY().getPos() - 1 <= posDcdY &&
				 posDcdY < targetEkimei.getZone().getY().getEndPos() + 1 )
			{
				aCDcdFreeLine.setOrg( CdDcdPosXy( 
					zoneDcdX.getPos() , 
					posDcdY ) ) ;
				aCDcdFreeLine.setDst( CdDcdPosXy( 
					zoneDcdX.getEndPos() , 
					posDcdY ) ) ;
				aCDcdFreeLine.DcDraw( &targetEkimei ) ;
			}
		}
		// --------------------------------
		//	�w��
		// --------------------------------
		for ( int iEkiIndex = 0 ; 
				iEkiIndex < pCentDedDgrEkiCont->size() ; 
				iEkiIndex ++ )
		{
			CentDedDgrEki	aCentDedDgrEki = 
				pCentDedDgrEkiCont->get( iEkiIndex ) ;
			DcdPos posDgrY = getCentDedDgrDia()->getDgrYPosOfEki( iEkiIndex ) ;
			dcdtextEkimei.setText( aCentDedDgrEki.getEkimei() ) ;

			//	�w����`��
			if ( aCentDedDgrEki.getIsSyuyoueki() ||
				iEkiIndex == 0 ||
				iEkiIndex == pCentDedDgrEkiCont->size() - 1 ||
				!m_bHideIppanekiEkimei  )
			{
				//	�n���w�E�I���w�E��v�w�E���邢��
				//	�u��ʉw�̉w���\�����B���w��v���U�̏ꍇ��
				//	�w����`�悵�܂��B
				//	(�u��ʉw�̉w���\�����B���w��v ���^�̏ꍇ�A
				//	�n���w�E�I���w�ȊO�̈�ʉw��
				//	�w����`�悵�܂���B)



				//	���W���ADgr��Dcd�ɕϊ�
				DcdPos	posDcdY = YDgrToDcd( &targetEkimei , posDgrY ) ;
				{
					CdDcdZoneXy	zonexyTextEkimei( 
						CdDcdZone( 
							zonexyEkimeiDcd.getX().getPos() + 
								linepropBold.getLogicalunitWidth() ,
							zonexyEkimeiDcd.getX().getSize() - 
								linepropBold.getLogicalunitWidth() ) ,
						CdDcdZone( 
							posDcdY - sizeEkimei.getY() , 
							sizeEkimei.getY() ) 
					) ;
					CaDcdTargetItemPosition	aTarget( &targetEkimei , zonexyTextEkimei ) ;
					if ( aTarget.isDrawable() )
					{
						dcdtextEkimei.DcDraw( &aTarget ) ;
						bRv = true ;
					}
				}
			}
		}
	}

	// --------------------------------
	//	�_�C���̕`��
	// --------------------------------
	{
		bRv |= m_pCDcdDiagram->DcDraw( &targetDiagram ) ;
	}
	return ( bRv ) ;
}
	
bool CDcdDiagram2::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	return ( false ) ;
}
	
// ********************************
//	CDcdDiagram
// ********************************
	// ********************************
	//@name CDcdDiagram-�֘A
	// ********************************
CentDedDgrDia*	CDcdDiagram2::getCentDedDgrDia() 
{
	return m_pCDcdDiagram->getCentDedDgrDia() ;
}
CDcdDiagram2& CDcdDiagram2::setCentDedDgrDia( CentDedDgrDia* value ) 
{
	m_pCDcdDiagram->setCentDedDgrDia( value ) ; 
	return *this ;
}
	// ********************************
	//@name CDcdDiagram-����-CdDedDispProp ����ǂݍ��݉\
	// ********************************
CdFontProp	CDcdDiagram2::getDiaRessyaFont()const 
{
	return m_pCDcdDiagram->getDiaRessyaFont() ;
}
CDcdDiagram2& CDcdDiagram2::setDiaRessyaFont( const CdFontProp& value ) 
{
	m_pCDcdDiagram->setDiaRessyaFont( value ) ;
	return *this ;
}
CdColorProp	CDcdDiagram2::getDiaHaikeiColor()const 
{
	return m_pCDcdDiagram->getDiaHaikeiColor() ;
}
CDcdDiagram2& CDcdDiagram2::setDiaHaikeiColor( CdColorProp value ) 
{
	m_pCDcdDiagram->setDiaHaikeiColor( value ) ;
	return *this ;
}

CdColorProp	CDcdDiagram2::getDiaJikuColor()const 
{
	return m_pCDcdDiagram->getDiaJikuColor() ;
}
CDcdDiagram2& CDcdDiagram2::setDiaJikuColor( CdColorProp value ) 
{
	m_pCDcdDiagram->setDiaJikuColor( value ) ;
	return *this ;
}
	// ********************************
	//@name CDcdDiagram-����-CdDedDispProp �ɂ͂Ȃ�����
	// ********************************
bool	CDcdDiagram2::getDisplayRessyabangou()const 
{
	return m_pCDcdDiagram->getDisplayRessyabangou() ;
}
CDcdDiagram2& CDcdDiagram2::setDisplayRessyabangou( bool value ) 
{
	m_pCDcdDiagram->setDisplayRessyabangou( value ) ;
	return *this ;
}
bool	CDcdDiagram2::getDisplayRessyamei()const 
{
	return m_pCDcdDiagram->getDisplayRessyamei() ;
}
CDcdDiagram2& CDcdDiagram2::setDisplayRessyamei( bool value ) 
{
	m_pCDcdDiagram->setDisplayRessyamei( value ) ;
	return *this ;
}

double CDcdDiagram2::getDcdPerDgrX( IfDcdTarget* pIfDcdTarget ) 
{
	return m_pCDcdDiagram->getDcdPerDgrX( pIfDcdTarget ) ;
}

void CDcdDiagram2::setDcdPerDgrX(  IfDcdTarget* pIfDcdTarget , double dDcdPerDgr ) 
{
	m_pCDcdDiagram->setDcdPerDgrX( pIfDcdTarget , dDcdPerDgr ) ;
}

double CDcdDiagram2::getDcdPerDgrY( IfDcdTarget* pIfDcdTarget ) 
{
	return m_pCDcdDiagram->getDcdPerDgrY( pIfDcdTarget ) ;
}

void CDcdDiagram2::setDcdPerDgrY( IfDcdTarget* pIfDcdTarget , double dDcdPerDgr ) 
{
	m_pCDcdDiagram->setDcdPerDgrY( pIfDcdTarget , dDcdPerDgr ) ;
}

int	CDcdDiagram2::getVlineMode()const 
{
	return m_pCDcdDiagram->getVlineMode() ;
}

CDcdDiagram2& CDcdDiagram2::setVlineMode( int value ) 
{
	m_pCDcdDiagram->setVlineMode( value ) ;
	return *this ;
}

bool CDcdDiagram2::getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const 
{
	return m_pCDcdDiagram->getDisplayRessyasen( eRessyahoukou ) ;
}
CDcdDiagram2& CDcdDiagram2::setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) 
{
	m_pCDcdDiagram->setDisplayRessyasen( eRessyahoukou , value ) ;
	return *this ;
}

int CDcdDiagram2::getVlinePitch()const 
{
	return m_pCDcdDiagram->getVlinePitch() ;
}

int CDcdDiagram2::getVlineMiddlePitch()const 
{
	return m_pCDcdDiagram->getVlineMiddlePitch() ;
}

int CDcdDiagram2::getVlineBoldPitch()const 
{
	return m_pCDcdDiagram->getVlineBoldPitch() ;
}

int CDcdDiagram2::getVlineChoices( 
		Mui<CDcdDiagram::VLINE>* pContVLINE )const 
{
	return m_pCDcdDiagram->getVlineChoices( pContVLINE ) ;
}

	// ********************************
	//@name CDcdDiagram-����
	// ********************************

CDcdDiagram2& CDcdDiagram2::readCdDedDispProp( const CdDedDispProp& value ) 
{
	m_pCDcdDiagram->readCdDedDispProp( value ) ;
	m_fontpropDiaEkimeiFont = value.getDiaEkimeiFont() ;
	m_fontpropDiaJikokuFont = value.getDiaJikokuFont() ;
	m_colorDiaMojiColor = value.getDiaMojiColor() ;
	m_iEkimeiLength = value.getEkimeiLength() ;
	return *this ;
}


CdDcdZoneXy	CDcdDiagram2::getZone_Dgr( IfDcdTarget* pIfDcdTarget )const 
{
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		calcDiagramZoneDcd( pIfDcdTarget ) ) ;

	return m_pCDcdDiagram->getZone_Dgr( &aTarget ) ;
}
CDcdDiagram2& CDcdDiagram2::setZone_Dgr( 
	IfDcdTarget* pIfDcdTarget , const CdDcdZoneXy& value ) 
{
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		calcDiagramZoneDcd( pIfDcdTarget ) ) ;

	m_pCDcdDiagram->setZone_Dgr( &aTarget , value ) ;

	return *this ;
}


int CDcdDiagram2::calcCentDedDgrRessyasenOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdPosXy& aCdDcdPosXy ,  
		int iMerginPixels ,
		ERessyahoukou *pERessyahoukou , 
		int *piRessyaIdx , 
		int *piRessyasenIdx ) 
{
	LogMsg( "CDcdDiagram2::calcCentDedDgrRessyasenOfPoint(,(%d,%d)) " ,
		aCdDcdPosXy.getX() , aCdDcdPosXy.getY() ) ;
 
	CdDcdZoneXy	zonexyDiagram = calcDiagramZoneDcd( pIfDcdTarget ) ;
	if ( zonexyDiagram.getX().getSize() <= 0 || zonexyDiagram.getY().getSize() <= 0 ){
		return 0 ;
	}

	CaDcdTargetItemPosition	targetDiagram( pIfDcdTarget , zonexyDiagram ) ;
	//targetDiagram = �_�C���O�����̕`����s���̈�
	//zonexyDiagram = �_�C���O�����̕`����s���̈�

	return m_pCDcdDiagram->calcCentDedDgrRessyasenOfPoint( 
		&targetDiagram ,
		aCdDcdPosXy ,  
		iMerginPixels , 
		pERessyahoukou , 
		piRessyaIdx , 
		piRessyasenIdx ) ;
}
int CDcdDiagram2::calcEkiOrderOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		ERessyahoukou eRessyahoukou ,
		DcdPos posY_Dcd )  
{
	CdDcdZoneXy	zonexyDiagram = calcDiagramZoneDcd( pIfDcdTarget ) ;
	if ( zonexyDiagram.getX().getSize() <= 0 || zonexyDiagram.getY().getSize() <= 0 ){
		return -1 ;
	}

	CaDcdTargetItemPosition	targetDiagram( pIfDcdTarget , zonexyDiagram ) ;
	//targetDiagram = �_�C���O�����̕`����s���̈�
	//zonexyDiagram = �_�C���O�����̕`����s���̈�

	return m_pCDcdDiagram->calcEkiOrderOfPoint( 
		&targetDiagram ,
		eRessyahoukou ,  
		posY_Dcd ) ;
}

int CDcdDiagram2::calcEkiIndexOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		DcdPos posY_Dcd ) 
{
	int iRv = -1 ;

	for ( int iEkiIndex = 0 ; 
		iRv == -1 && 
		iEkiIndex < getCentDedDgrDia()->getCentDedDgrEkiCont()->size() ;
		iEkiIndex ++ )
	{
		DcdPos	posDgrYPosOfEki = 
			getCentDedDgrDia()->getDgrYPosOfEki( iEkiIndex ) ;
		DcdPos	posDcdYPosOfEki = YDgrToDcd( pIfDcdTarget , posDgrYPosOfEki ) ;
		if ( posY_Dcd <= posDcdYPosOfEki )
		{
			iRv = iEkiIndex ;
		}
	}

	return iRv ;
}

	// ********************************
	//@name CDcdDiagram-�_�C���O�������W�ƁAIfDcdTarget ��̍��W��ϊ�
	// ********************************
DcdPos CDcdDiagram2::XDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrToDcd( &aTarget , posSrc ) ;
}

DcdPos CDcdDiagram2::YDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->YDgrToDcd( &aTarget , posSrc ) ;
}

DcdPos CDcdDiagram2::XDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrFromDcd( &aTarget , posSrc ) ;
}

DcdPos CDcdDiagram2::YDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->YDgrFromDcd( &aTarget , posSrc ) ;
}

CdDcdZone CDcdDiagram2::XDgrToDcd( IfDcdTarget* pIfDcdTarget ,
		const CdDcdZone& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrToDcd( &aTarget , zoneSrc ) ;
}

CdDcdZone CDcdDiagram2::YDgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->YDgrToDcd( &aTarget , zoneSrc ) ;
}

CdDcdZone CDcdDiagram2::XDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrFromDcd( &aTarget , zoneSrc ) ;
}

CdDcdZone CDcdDiagram2::YDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrFromDcd( &aTarget , zoneSrc ) ;
}

CdDcdPosXy CDcdDiagram2::DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->DgrToDcd( &aTarget , posSrc ) ;
}

CdDcdPosXy CDcdDiagram2::DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->DgrFromDcd( &aTarget , posSrc ) ;
}


CdDcdZoneXy CDcdDiagram2::DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->DgrToDcd( &aTarget , zoneSrc ) ;
}

CdDcdZoneXy CDcdDiagram2::DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->DgrFromDcd( &aTarget , zoneSrc ) ;
};



	// ********************************
	//@name CDcdDiagram2-����
	// ********************************
CdFontProp	CDcdDiagram2::getDiaEkimeiFont()const 
{
	return m_fontpropDiaEkimeiFont ;
}
CDcdDiagram2& CDcdDiagram2::setDiaEkimeiFont( const CdFontProp& value ) 
{
	m_fontpropDiaEkimeiFont = value ;
	return *this ;
}
CdFontProp	CDcdDiagram2::getDiaJikokuFont()const 
{
	return m_fontpropDiaJikokuFont ;
}
CDcdDiagram2& CDcdDiagram2::setDiaJikokuFont( const CdFontProp& value ) 
{
	m_fontpropDiaJikokuFont = value ;
	return *this ;
}
CdColorProp	CDcdDiagram2::getDiaMojiColor()const 
{
	return m_colorDiaMojiColor ;
}
CDcdDiagram2& CDcdDiagram2::setDiaMojiColor( CdColorProp value ) 
{
	m_colorDiaMojiColor = value ;
	return *this ;
}
CDcdDiagram2& CDcdDiagram2::setEkimeiLength( int value ) 
{
	m_iEkimeiLength = value ;
	return *this ;
}

bool CDcdDiagram2::getHideIppanekiEkimei()const 
{
	return m_bHideIppanekiEkimei ;
}
CDcdDiagram2& CDcdDiagram2::setHideIppanekiEkimei( bool value )  
{
	m_bHideIppanekiEkimei = value ;
	return *this ;
}

	
	// ********************************
	//@name CDcdDiagram2-����
	// ********************************

CdDcdZoneXy CDcdDiagram2::calcDiagramZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const 
{
	// --------------------------------
	//	�w���\���E�����̗̈�
	// --------------------------------
	CdDcdZoneXy	zonexyEkimei = calcEkimeiZoneDcd( pIfDcdTarget ) ;
	CdDcdZoneXy	zonexyJikoku = calcJikokuZoneDcd( pIfDcdTarget ) ;
	
	// --------------------------------
	CdDcdZoneXy	zonexyDiagram ;
	zonexyDiagram.setX( zonexyJikoku.getX() ) ;
	zonexyDiagram.setY( CdDcdZone( 
		pIfDcdTarget->getZone().getY().getPos()  + zonexyJikoku.getY().getSize() , 
		pIfDcdTarget->getZone().getY().getSize() - zonexyJikoku.getY().getSize() 
	) ) ;
	if ( zonexyDiagram.getX().getSize() < 0 )
	{
		zonexyDiagram.setX( CdDcdZone( zonexyDiagram.getX().getPos() , 0 ) ) ;
	}
	if ( zonexyDiagram.getY().getSize() < 0 )
	{
		zonexyDiagram.setY( CdDcdZone( zonexyDiagram.getY().getPos() , 0 ) ) ;
	}

	return zonexyDiagram ;
}

CdDcdZoneXy CDcdDiagram2::calcEkimeiZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const 
{
	// --------------------------------
	//	�w���\���̕�
	// --------------------------------
	DcdSize	sizeEkimeiX = 0 ;
	{
		CdDcdFreeLineProp	linepropBold( getCdLinePropBold() ) ;

		// --------------------------------
		//	�e�L�X�g�̍��̑���
		sizeEkimeiX += linepropBold.getLogicalunitWidth() ;

		// --------------------------------
		//	�e�L�X�g�̕�
		CdDcdSizeXy	sizeTextEkimei ;
		CDcdText	dcdtextEkimei( getCDcdTextEkimei() ) ;
		dcdtextEkimei.getItemSize( pIfDcdTarget , &sizeTextEkimei ) ;
		//dcdtextEkimei = �w���̕`����s�� DcDraw �I�u�W�F�N�g
		//sizeTextEkimei = �w���̕`����s�� DcDraw �I�u�W�F�N�g�̑傫��

		sizeEkimeiX += sizeTextEkimei.getX() ;

		// --------------------------------
		//	�e�L�X�g�̉E�̑���
		sizeEkimeiX += linepropBold.getLogicalunitWidth() ;
	}
	//sizeEkimeiX = �w�����̕�

	// --------------------------------
	CdDcdZoneXy	zonexyEki ;
	zonexyEki.setX( CdDcdZone( 
		pIfDcdTarget->getZone().getX().getPos() ,
		sizeEkimeiX ) ) ; 
	zonexyEki.setY( CdDcdZone( 
		pIfDcdTarget->getZone().getY().getPos() , 
		pIfDcdTarget->getZone().getY().getSize() ) ) ;

	if ( zonexyEki.getX().getSize() < 0 )
	{
		zonexyEki.setX( CdDcdZone( zonexyEki.getX().getPos() , 0 ) ) ;
	}
	if ( zonexyEki.getY().getSize() < 0 )
	{
		zonexyEki.setY( CdDcdZone( zonexyEki.getY().getPos() , 0 ) ) ;
	}


	return zonexyEki ;
}
	
CdDcdZoneXy CDcdDiagram2::calcJikokuZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const 
{
	// --------------------------------
	//	�����\���̍���
	// --------------------------------
	DcdSize	sizeJikokuY = 0 ;
	{
		CDcdText	dcdtextJikoku( getCDcdTextJikoku() ) ;
		CdDcdSizeXy	sizeTextJikoku ;
		dcdtextJikoku.getItemSize( pIfDcdTarget , &sizeTextJikoku ) ;

		//dcdtextJikoku = ���̕`����s�� DcDraw �I�u�W�F�N�g
		//sizeTextJikoku = ���̕`����s�� DcDraw �I�u�W�F�N�g�̑傫��

		sizeJikokuY = sizeTextJikoku.getY() ;
	}
	//sizeJikokuY=�����\���̍���

	// --------------------------------
	//	�w���\���̕�
	// --------------------------------
	CdDcdZoneXy	zonexyEkimei = calcEkimeiZoneDcd( pIfDcdTarget ) ;

	// --------------------------------
	CdDcdZoneXy	zonexyJikoku ;
	zonexyJikoku.setX( CdDcdZone( 
		pIfDcdTarget->getZone().getX().getPos()  + zonexyEkimei.getX().getSize() ,
		pIfDcdTarget->getZone().getX().getSize() - zonexyEkimei.getX().getSize() ) ) ; 
	zonexyJikoku.setY( CdDcdZone( 
		pIfDcdTarget->getZone().getY().getPos() , 
		sizeJikokuY ) ) ;

	if ( zonexyJikoku.getX().getSize() < 0 )
	{
		zonexyJikoku.setX( CdDcdZone( zonexyJikoku.getX().getPos() , 0 ) ) ;
	}
	if ( zonexyJikoku.getY().getSize() < 0 )
	{
		zonexyJikoku.setY( CdDcdZone( zonexyJikoku.getY().getPos() , 0 ) ) ;
	}


	return zonexyJikoku ;
}

} //namespace ViewDiagram



