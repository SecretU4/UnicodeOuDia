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
// CWndDiagram.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"

#include "DcdCd\Pos\CconvDcdPosOnZone_PosOrgAndRate.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CDcdTargetOnPaint.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "WinUtil\CconvWinUser.h"
#include "LogMsg\LogMsg.h"

#include "..\DiagramEdit.h"
#include "CWndDiagram.h"
#include "..\ViewJikokuhyou\CJikokuhyouView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewDiagram{

using namespace DcDrawLib::WinUtil;

/////////////////////////////////////////////////////////////////////////////
// CWndDiagram
// ********************************
//	CWndDiagram
// ********************************
// --------------------------------
//@name �����֐�
// --------------------------------
bool CWndDiagram::update_adjustProp() 
{
	bool	bRv = false ;

	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;

	LogMsg( "CWndDiagram::update_adjustProp() Target.GetZone()=X(%d,%d)Y(%d,%d)"  , 
		aTarget.getZone().getX().getPos() , 
		aTarget.getZone().getX().getSize() , 
		aTarget.getZone().getY().getPos() , 
		aTarget.getZone().getY().getSize() ) ;

	// --------------------------------		
	//	m_pCDcdDiagram->m_CconvContentPosToDcdTarget �̒l�𐳋K��
	// --------------------------------		
	{
		CdDcdZoneXy zoneDgrInDcd ;
		CdDcdZoneXy zoneDgr ;
		if ( m_pCDcdDiagram->getCentDedDgrDia() != NULL ){
			zoneDgr = m_pCDcdDiagram->getCentDedDgrDia()->getZone();
		}
		zoneDgrInDcd = m_pCDcdDiagram->getZone_Dgr( &aTarget ) ;
		//zoneDgr = �_�C���O�����̍��W�͈̔�
		//	(X����=(0,24����),Y����=(0,�I�_�̃_�C���O�������W)
		//zoneDgrInDcd = �E�C���h�E�ɕ\������Ă���͈͂�
		//	�_�C���O�������W

		LogMsg( "\t zoneDgr=X(%d,%d)Y(%d,%d)"  , 
			zoneDgr.getX().getPos() , 
			zoneDgr.getX().getSize() , 
			zoneDgr.getY().getPos() , 
			zoneDgr.getY().getSize() ) ;

		LogMsg( "\t zoneDgrInDcd=X(%d,%d)Y(%d,%d)"  , 
			zoneDgrInDcd.getX().getPos() , 
			zoneDgrInDcd.getX().getSize() , 
			zoneDgrInDcd.getY().getPos() , 
			zoneDgrInDcd.getY().getSize() ) ;


		// --------------------------------		
		//	X���W
		// --------------------------------		
		{

			LogMsg( "CWndDiagram::update_adjustProp() "
				"zoneDgrInDcd.getX()=(%d,%d)"  , 
				zoneDgrInDcd.getX().getPos() ,
				zoneDgrInDcd.getX().getSize() ) ;

			//	�R���e���c�̉E(��)�[���A
			//	�^�[�Q�b�g��DcDraw�̉E(��)�[������(��)��
			//	����Ă��āA�E(��)�ɋ󂫂�����ꍇ�́A
			//	��U�R���e���c���E(��)�Ɋ񂹂܂��B
			if ( zoneDgrInDcd.getX().getEndPos() 
					> zoneDgr.getX().getEndPos() ){
				CdDcdZone	aCdDcdZone = zoneDgrInDcd.getX() ;
				aCdDcdZone.setPos( 
					zoneDgr.getX().getEndPos() - zoneDgrInDcd.getX().getSize() ) ;
				zoneDgrInDcd.setX( aCdDcdZone ) ;
			}

			//	�R���e���c��Pos(��(��)�̒[)��
			//	�^�[�Q�b�g��DcDraw��Pos(��(��))�����E(��)��
			//	����Ă��āA��(��)�ɋ󂫂�����ꍇ�́A
			//	�R���e���c����(��)�Ɋ񂹂܂��B
			if ( zoneDgrInDcd.getX().getPos() < zoneDgr.getX().getPos() ){
				CdDcdZone	aCdDcdZone = zoneDgrInDcd.getX() ;
				aCdDcdZone.setPos( zoneDgr.getX().getPos() ) ;
				zoneDgrInDcd.setX( aCdDcdZone ) ;
			}
		}
		// --------------------------------		
		//	Y���W
		// --------------------------------		
		{
			//	�R���e���c�̉E(��)�[���A
			//	�^�[�Q�b�g��DcDraw�̉E(��)�[������(��)��
			//	����Ă��āA�E(��)�ɋ󂫂�����ꍇ�́A
			//	��U�R���e���c���E(��)�Ɋ񂹂܂��B
			if ( zoneDgrInDcd.getY().getEndPos() 
					> zoneDgr.getY().getEndPos() ){
				CdDcdZone	aCdDcdZone = zoneDgrInDcd.getY() ;
				aCdDcdZone.setPos( 
					zoneDgr.getY().getEndPos() - zoneDgrInDcd.getY().getSize() ) ;
				zoneDgrInDcd.setY( aCdDcdZone ) ;
			}

			//	�R���e���c��Pos(��(��)�̒[)��
			//	�^�[�Q�b�g��DcDraw��Pos(��(��))�����E(��)��
			//	����Ă��āA��(��)�ɋ󂫂�����ꍇ�́A
			//	�R���e���c����(��)�Ɋ񂹂܂��B
			if ( zoneDgrInDcd.getY().getPos() < zoneDgr.getY().getPos() ){
				CdDcdZone	aCdDcdZone = zoneDgrInDcd.getY() ;
				aCdDcdZone.setPos( zoneDgr.getY().getPos() ) ;
				zoneDgrInDcd.setY( aCdDcdZone ) ;
			}
		}
		LogMsg( "\t zoneDgrInDcd=X(%d,%d)Y(%d,%d)"  , 
			zoneDgrInDcd.getX().getPos() , 
			zoneDgrInDcd.getX().getSize() , 
			zoneDgrInDcd.getY().getPos() , 
			zoneDgrInDcd.getY().getSize() ) ;
	
		// --------------------------------
		if ( zoneDgrInDcd != m_pCDcdDiagram->getZone_Dgr(  &aTarget  ) ){
			m_pCDcdDiagram->setZone_Dgr(  &aTarget , zoneDgrInDcd ) ;
			bRv = true ;
		}
	}

	return ( bRv ) ;
}

void CWndDiagram::update_updateScreen() 
{
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;

	CdDcdZoneXy zoneDgrInDcd ;
	CdDcdZoneXy zoneDgr ;
	{
		if ( m_pCDcdDiagram->getCentDedDgrDia() != NULL )
		{
			zoneDgr = m_pCDcdDiagram->getCentDedDgrDia()->getZone();
		}

		zoneDgrInDcd = m_pCDcdDiagram->getZone_Dgr( &aTarget ) ;
	}
	//zoneDgr=�_�C���O�������W�̑S�͈̔�
	//zoneDgrInDcd = IfDcdTarget�ɕ`�悷��_�C���O�������W�͈�

	CdDcdZoneXy	zoneDiagramZoneDcd = calcDiagramZoneDcd() ;
	//zoneDiagramZoneDcd = �E�C���h�E��Ń_�C���O�������`�悳���̈�

	// --------------------------------		
	//	�E�C���h�E�X�N���[��
	// --------------------------------	
	//���@���݂�zoneDgrInDcd(IfDcdTarget�ɕ`�悷��_�C���O�������W�͈�)��
	//	Pos(�n�_�ʒu)�ƁA
	//	�O��(���ݕ\����)��zoneDgrInDcd��Pos(�n�_�ʒu)���r���A
	//	���̍������ƂɃE�C���h�E�̃X�N���[�����s���܂��B
	//���w�O��(���ݕ\����)��zoneDgrInDcd��Pos(�n�_�ʒu)�x��
	//	�X�N���[���o�[�̈ʒu����擾���܂��B
	{

		// --------------------------------		
		//	X�����E�C���h�E�X�N���[���s�N�Z�����̌v�Z
		// --------------------------------
		int iXAmount = 0 ;
		if ( m_CdScrollbarPropX.getPos() != 
			zoneDgrInDcd.getX().getPos() )
		{
			int iXPos_DcdPrev = m_pCDcdDiagram->XDgrToDcd( 
				&aTarget , m_CdScrollbarPropX.getPos() ) ;  
			int iXPos_DcdNew  = m_pCDcdDiagram->XDgrToDcd( 
				&aTarget , zoneDgrInDcd.getX().getPos() ) ;  
			iXAmount = iXPos_DcdPrev - iXPos_DcdNew ;
		}
		// --------------------------------		
		//	Y�����E�C���h�E�X�N���[���s�N�Z�����̌v�Z
		// --------------------------------
		int iYAmount = 0 ;
		if ( m_CdScrollbarPropY.getPos() != 
			zoneDgrInDcd.getY().getPos() )
		{
			int iYPos_DcdPrev = m_pCDcdDiagram->YDgrToDcd( 
				&aTarget , m_CdScrollbarPropY.getPos() ) ;  
			int iYPos_DcdNew  = m_pCDcdDiagram->YDgrToDcd( 
				&aTarget , zoneDgrInDcd.getY().getPos() ) ;  
			iYAmount = iYPos_DcdPrev - iYPos_DcdNew ;
		}

		// --------------------------------		
		//	�X�N���[��
		// --------------------------------
		if ( iXAmount != 0 || iYAmount != 0 )
		{
			CConverter_WinGdi	aConverter_WinGdi ;
			//	�_�C���O�����̈�̃X�N���[��
			{
				CdDcdZoneXy	zoneDcdDiagram = 
					m_pCDcdDiagram->calcDiagramZoneDcd( &aTarget ) ; 
				RECT	aRect = aConverter_WinGdi.RECTOf( zoneDcdDiagram );
				ScrollWindow( iXAmount , iYAmount , NULL , &aRect ) ;
			}
			//	�w���̈�̏c�X�N���[��
			{
				CdDcdZoneXy	zoneDcdEkimei = 
					m_pCDcdDiagram->calcEkimeiZoneDcd( &aTarget ) ; 
				RECT	aRect = aConverter_WinGdi.RECTOf( zoneDcdEkimei );
				ScrollWindow( 0 , iYAmount , NULL , &aRect ) ;
			}
			//	�����̈�̉��X�N���[��
			{
				CdDcdZoneXy	zoneDcdJikoku = 
					m_pCDcdDiagram->calcJikokuZoneDcd( &aTarget ) ; 
				RECT	aRect = aConverter_WinGdi.RECTOf( zoneDcdJikoku );
				ScrollWindow( iXAmount , 0 , NULL , &aRect ) ;
			}
		}
	}


	// --------------------------------		
	//	�X�N���[���o�[�����̕ύX
	// --------------------------------	
	{
		// --------------------------------		
		//	X�����̃X�N���[���o�[�����̕ύX
		// --------------------------------	
		CdScrollbarProp	aCdScrollbarPropX_New 
			= m_CdScrollbarPropX  ;
		if ( zoneDiagramZoneDcd.getX().getSize() > 0 )	
		{
			//	�_�C���O�����\���̈悪�E�C���h�E��
			aCdScrollbarPropX_New.setDisableNoScroll( false ) ;
			aCdScrollbarPropX_New.set(
					zoneDgr.getX().getPos() , 
					zoneDgr.getX().getEndPos() ,
					zoneDgrInDcd.getX().getSize() + 1 ,
					zoneDgrInDcd.getX().getPos() ) ;
		}
		else
		{
			//	�_�C���O�����\���̈悪�E�C���h�E��ɂȂ��ꍇ��
			//	�X�N���[���o�[�͔�\���ɂ͂����ɖ����ɂ��܂��B
			//
			//�y���R�z�X�N���[���o�[���_�ł����Ԃ�����邽�߂ł��B
			//�ymemo�z�_�C���O�����r���[�ŁA�X�N���[���o�[���_�ł��錻��
			//	�ȉ��̓��삪�����ł��B
			//(1)�@�N���C�A���g�̈�̃T�C�Y��������
			//�@���_�C���O�����\���̈悪�A�N���C�A���g�̈���ɂȂ�
			//�@���X�N���[���o�[�͔�\��
			//(2)�@���[�U�[���N���C�A���g�̈�̃T�C�Y���A�_�C���O����
			//	�\���̈悪�����\������邭�炢�ɑ傫������
			//�@���_�C���O�����\���̈悪�N���C�A���g�̈�ɂȂ�
			//�@���X�N���[���o�[���\�������
			//(3)�X�N���[���o�[���\�����ꂽ���Ƃɂ��ACWndDiagram��
			//	�N���C�A���g�̈悪�������Ȃ�B
			//�@���_�C���O�����\���̈悪�A�N���C�A���g�̈�O�ɂȂ�
			//	(�X�N���[���o�[�ɉB���)
			//�@���X�N���[���o�[����\���ɂȂ�
			//(4)�X�N���[���o�[����\���ɂȂ������Ƃɂ��ACWndDiagram��
			//	�N���C�A���g�̈悪�傫���Ȃ�
			//�@���_�C���O�����\���̈悪�N���C�A���g�̈�ɂȂ�
			//�@���X�N���[���o�[���\�������
			//(5)�@(3)�`(4)�̌J��Ԃ��ŁA�X�N���[���o�[���_�ł����悤�ɂȂ�B
			//
			//  ���������邽�߂ɁA�ȉ��̂悤�ɂ��܂��B
			//
			//  CWndDiagram �́A�_�C���O�����\���̈悪
			//	�N���C�A���g�̈���ɂȂ��Ƃ��́A�X�N���[���o�[��
			//	�\�������܂܂Ŗ����ɂ���B
			aCdScrollbarPropX_New.setDisableNoScroll( true ) ;
			aCdScrollbarPropX_New.setNull() ;

		}
		if ( !m_CdScrollbarPropX.isEqualTo( aCdScrollbarPropX_New ) )
		{
			m_CdScrollbarPropX = aCdScrollbarPropX_New ;
			SCROLLINFO	aScrollinfo = 
				CconvWinUser::SCROLLINFOof( m_CdScrollbarPropX ) ;

			//	SIF_DISABLENOSCROLL ���g���ăX�N���[���o�[�𖳌��ɂ���ꍇ�́A
			//
			//	EnableScrollBar( (SB_HORZ or SB_VERT), ESB_ENABLE_BOTH ) ;
			//
			//	���Ăяo���Ă���A
			//
			//	SetScrollInfo()���Ăяo���Ă��������B
			//	
			//	EnableScrollBar() ���Ăяo���Ȃ��ƁA
			//	�����ɂȂ����X�N���[���o�[��
			//	�X�N���[���o�[���K�v�ɂȂ����Ƃ��ɂ��L���ɂȂ�܂���B
			EnableScrollBar( SB_HORZ ,  ESB_ENABLE_BOTH ) ;
			SetScrollInfo( SB_HORZ , &aScrollinfo ) ;
		}

		// --------------------------------		
		//	Y�����̃X�N���[���o�[�����̕ύX
		// --------------------------------	
		CdScrollbarProp	aCdScrollbarPropY_New 
			= m_CdScrollbarPropY  ;
		if ( zoneDiagramZoneDcd.getY().getSize() > 0 )	
		{
			//	�_�C���O�����\���̈悪�E�C���h�E��
			aCdScrollbarPropY_New.setDisableNoScroll( false ) ;
			aCdScrollbarPropY_New.set(
					zoneDgr.getY().getPos() , 
					zoneDgr.getY().getEndPos() ,
					zoneDgrInDcd.getY().getSize() + 1 , 
					zoneDgrInDcd.getY().getPos() ) ;
		}
		else
		{
			//	�_�C���O�����\���̈悪�E�C���h�E��ɂȂ��ꍇ��
			//	�X�N���[���o�[�͔�\���ɂ͂����ɖ����ɂ��܂��B
			//
			//�y���R�z�X�N���[���o�[���_�ł����Ԃ�����邽�߂ł��B
			aCdScrollbarPropY_New.setDisableNoScroll( true ) ;
			aCdScrollbarPropY_New.setNull() ;
		}
		if ( !m_CdScrollbarPropY.isEqualTo( aCdScrollbarPropY_New ) )
		{
			m_CdScrollbarPropY = aCdScrollbarPropY_New ;
			SCROLLINFO	aScrollinfo = 
				CconvWinUser::SCROLLINFOof( m_CdScrollbarPropY ) ;
			EnableScrollBar( SB_VERT ,  ESB_ENABLE_BOTH ) ;
			SetScrollInfo( SB_VERT , &aScrollinfo ) ;
		}
	}
}
	// --------------------------------
	//@name MFC���b�Z�[�W�n���h���̉����֐�
	// --------------------------------
int CWndDiagram::OnLButtonDblClk_openJikokuhyouView( CPoint point) 
{
	int iRv = 0 ;


	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;
	ERessyahoukou eRessyahoukou = Ressyahoukou_Kudari ;
	int iRessyaIdx = -1 ;
	int iRessyasenIdx = -1 ;
	{
		int iResult =  m_pCDcdDiagram->calcCentDedDgrRessyasenOfPoint( 
			&aTarget , 
			CdDcdPosXy( point.x , point.y ) , 2 , 
			&eRessyahoukou , 
			&iRessyaIdx , 
			&iRessyasenIdx ) ;
		if ( iResult != 1 )
		{
			iRv = -1 ;	//	point ����Ԑ���ɂ���܂���B
		}
	}
	//eRessyahoukou = point ��ʂ��Ԑ��̕��� 
	//iRessyaIdx = point ��ʂ��Ԃ̗��Index
	//iRessyasenIdx = point �̈ʒu�̗�Ԑ�Index

	const CentDedDia* pCentDedDia = NULL ;
	int iEkiOrder = -1 ;
	if ( iRv >= 0 )
	{
		int iDiaIndex = -1 ;
		// --------------------------------
		iEkiOrder = m_pCDcdDiagram->calcEkiOrderOfPoint( 
			&aTarget , eRessyahoukou , point.y ) ;

		//iEkiOrder = point �̈ʒu�̒��O�̉wOrder
		iDiaIndex = getCDiagramEditDoc()->
			getCDedRosenFileData()->getCentDedRosen()->getCentDedDiaCont()
				->findCentDedDiaByName( 
					m_pCDcdDiagram->getCentDedDgrDia()->getName() ) ;
		if ( iDiaIndex < 0 )
		{
			iRv = -2 ;	//	�_�C���O�����r���[�ɑΉ����� 
						//	CentDedDia ��������܂���B
		}
		else
		{
			pCentDedDia = getCDiagramEditDoc()->
					getCDedRosenFileData()->getCentDedRosen()->getCentDedDiaCont()
					->getMuPtr()->get( iDiaIndex ) ; 
		}
	}
	//pCentDedDia = �H���_�C���I�u�W�F�N�g
	//iEkiOrder = �ړ���̉wOrder

	CJikokuhyouView* pCJikokuhyouView = NULL ;
	if ( iRv >= 0 )
	{
		CJikokuhyouDoc* pCJikokuhyouDoc = NULL ;
		pCJikokuhyouDoc = 
			getCDiagramEditApp()->openCJikokuhyouDoc( 
				pCentDedDia , eRessyahoukou ,
				&pCJikokuhyouView) ; 
		if ( pCJikokuhyouView == NULL )
		{
			iRv = -3 ;	//	�����\�r���[���J���̂Ɏ��s���܂����B
		}
		//pCJikokuhyouDoc = �����\�h�L�������g
		//pCJikokuhyouView = �����\�r���[
	}

	if ( iRv >= 0 )
	{
		//attention
		//	���̍s�͕s�v�ł��iopenCJikokuhyouDoc() �ŃA�N�e�B�u�ɂȂ�j���A
		//	�����Assert()�Ɏ��s���܂��B
		//
		//	CMainFrame* pCMainFrame = (CMainFrame*)AfxGetMainWnd() ;
		//	pCMainFrame->SetActiveView( pCJikokuhyouView ) ;
	
		pCJikokuhyouView->setFocusToRessyaIndex( iRessyaIdx , iEkiOrder ) ;
		iRv = 1 ;	//	�����\�r���[�ֈړ����܂���
	}

	return iRv ;
}

int CWndDiagram::OnLButtonDblClk_openDlgEkiProp( CPoint point)
{
	int iRv = 0 ;

	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;
	CdDcdPosXy	posMouse( point.x , point.y ) ;

	//	point ���w���̈�ɂ��邱�Ƃ��m�F
	if ( iRv >= 0 )
	{
		CdDcdZoneXy	zonexyEkimeiZone = 
			m_pCDcdDiagram->calcEkimeiZoneDcd( &aTarget ) ;
		if ( !zonexyEkimeiZone.IsInner( posMouse ) )
		{
			iRv = -1 ;	//	point ���w���̈�ɂ���܂���B
		}
	}
	//	point �ɑΉ�����wIndex���擾
	int iEkiIndex = -1 ;
	if ( iRv >= 0 )
	{
		iEkiIndex = m_pCDcdDiagram->calcEkiIndexOfPoint( 
			&aTarget , posMouse.getY() ) ;
		if ( iEkiIndex < 0 )
		{
			iRv = -2 ;	//	point �ɑΉ�����w��������܂���B
		}
	}
	//	�wView���J��
	CEkiView* pCEkiView = NULL ;
	if ( iRv >= 0 )
	{
		getCDiagramEditApp()->openCEkiDoc( 
			&pCEkiView ) ;
		if ( pCEkiView == NULL )
		{
			iRv = -3 ;	//	�w�r���[���J���̂Ɏ��s���܂����B
		}
	}
	//	�w�̃v���p�e�B�_�C�A���O���J��
	if ( iRv >= 0 )
	{
		pCEkiView->openCDlgEkiProp( iEkiIndex ) ;
	}
	return iRv ;
}



	// ********************************
	//@name	CDcdDiagrem-�֘A
	// ********************************
CentDedDgrDia* CWndDiagram::getCentDedDgrDia() 
{
	return m_pCDcdDiagram->getCentDedDgrDia() ;
}
CWndDiagram& CWndDiagram::setCentDedDgrDia( CentDedDgrDia* value ) 
{
	if ( m_pCDcdDiagram->getCentDedDgrDia() != value )
	{
		m_pCDcdDiagram->setCentDedDgrDia( value ) ;

		update_adjustProp() ;
		update_updateScreen() ;
	}	
	return *this ;
}
	// ********************************
	//@name CDcdDiagram-����-CdDedDispProp �ɂ͂Ȃ�����
	// ********************************
bool CWndDiagram::getDisplayRessyabangou()const 
{
	return m_pCDcdDiagram->getDisplayRessyabangou() ;
}

int CWndDiagram::setDisplayRessyabangou( bool value ) 
{
	int iRv = 0 ;
	if ( value != m_pCDcdDiagram->getDisplayRessyabangou() ){
		m_pCDcdDiagram->setDisplayRessyabangou( value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;


		iRv = 1 ;
	}
	return ( iRv ) ;
	
}
bool CWndDiagram::getDisplayRessyamei()const 
{
	return m_pCDcdDiagram->getDisplayRessyamei() ;
}
int CWndDiagram::setDisplayRessyamei( bool value ) 
{
	int iRv = 0 ;
	if ( value != m_pCDcdDiagram->getDisplayRessyamei() ){
		m_pCDcdDiagram->setDisplayRessyamei( value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;

		iRv = 1 ;
	}
	return ( iRv ) ;
}

CdDcdPosXy	CWndDiagram::getPosDgr()const 
{
	return m_pCDcdDiagram->getPosDgr() ;
}
int CWndDiagram::setPosDgr( CdDcdPosXy value )
{
	int iRv = 0 ;
	if ( value != m_pCDcdDiagram->getPosDgr() )
	{
		m_pCDcdDiagram->setPosDgr( value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;
		

		iRv = 1 ;
	}
	return iRv ;
}
double CWndDiagram::getDcdPerDgrX()const 
{
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;
	return m_pCDcdDiagram->getDcdPerDgrX(&aTarget) ;
}
int CWndDiagram::setDcdPerDgrX( double value ) 
{
	int iRv = 0 ;
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;
	if ( value != m_pCDcdDiagram->getDcdPerDgrX(&aTarget) )
	{
		m_pCDcdDiagram->setDcdPerDgrX( &aTarget , value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;
		

		iRv = 1 ;
	}
	return iRv ;
}

double CWndDiagram::getDcdPerDgrY()const 
{
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;
	return m_pCDcdDiagram->getDcdPerDgrY(&aTarget) ;
}

int CWndDiagram::setDcdPerDgrY( double value ) 
{
	int iRv = 0 ;
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;
	if ( value != m_pCDcdDiagram->getDcdPerDgrY(&aTarget) )
	{
		m_pCDcdDiagram->setDcdPerDgrY( &aTarget , value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;
		

		iRv = 1 ;
	}
	return iRv ;
}



int	CWndDiagram::getVlineMode()const 
{
	return m_pCDcdDiagram->getVlineMode() ;
	
}
int CWndDiagram::setVlineMode( int value ) 
{
	int iRv = 0 ;
	if ( value != m_pCDcdDiagram->getVlineMode() ){
		m_pCDcdDiagram->setVlineMode( value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;


		iRv = 1 ;
	}
	return ( iRv ) ;
	
}

bool CWndDiagram::getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const 
{
	return m_pCDcdDiagram->getDisplayRessyasen( eRessyahoukou ) ;
}
int CWndDiagram::setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) 
{
	int iRv = 0 ;
	if ( value != m_pCDcdDiagram->getDisplayRessyasen( eRessyahoukou ) ){
		m_pCDcdDiagram->setDisplayRessyasen( eRessyahoukou , value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;

		iRv = 1 ;
	}
	return ( iRv ) ;
	
}

CDcdDiagram::EStopMarkDraw	CWndDiagram::getStopMarkDraw()const
{
	return m_pCDcdDiagram->getStopMarkDraw() ;
};

int CWndDiagram::setStopMarkDraw( CDcdDiagram::EStopMarkDraw	value )
{
	int iRv = 0 ;
	if ( value != m_pCDcdDiagram->getStopMarkDraw() )
	{
		m_pCDcdDiagram->setStopMarkDraw( value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;

		iRv = 1 ;
	}
	return ( iRv ) ;

};

int CWndDiagram::getVlineChoices( Mui<CDcdDiagram::VLINE>* pContVLINE ) 
{
	return m_pCDcdDiagram->getVlineChoices( pContVLINE )  ;
}



	// ********************************
	//@name	CDcdDiagrem-����
	// ********************************
int CWndDiagram::readCdDedDispProp( const CdDedDispProp& value ) 
{
	int iRv = 0 ;
	m_pCDcdDiagram->readCdDedDispProp( value ) ;
	update_adjustProp() ;
	update_updateScreen() ;
	Invalidate() ;
	return ( iRv ) ;
}

CdDcdZoneXy	CWndDiagram::getZone_Dgr()const 
{
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;
	return m_pCDcdDiagram->getZone_Dgr( &aTarget ) ;
}
int CWndDiagram::setZone_Dgr( const CdDcdZoneXy& value ) 
{
	int iRv = 0 ;
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;
	if ( value != m_pCDcdDiagram->getZone_Dgr( &aTarget ) )
	{
		m_pCDcdDiagram->setZone_Dgr(  &aTarget , value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;

		iRv = 1 ;
	}
	return ( iRv ) ;
}

bool CWndDiagram::getKeepZoneDgrOnSize()const
{
	return m_pCDcdDiagram->getKeepZoneDgrOnSize() ;
};
int CWndDiagram::setKeepZoneDgrOnSize( bool value )
{
	int iRv = 0 ;
	if ( value != m_pCDcdDiagram->getKeepZoneDgrOnSize() )
	{
		m_pCDcdDiagram->setKeepZoneDgrOnSize( value ) ;

		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;

		iRv = 1 ;
	}
	return ( iRv ) ;
};

	// ********************************
	//@name	CDcdDiagrem2-����
	// ********************************

bool CWndDiagram::getHideIppanekiEkimei()const 
{
	return m_pCDcdDiagram->getHideIppanekiEkimei() ;
}
int CWndDiagram::setHideIppanekiEkimei( bool value )  
{
	int iRv = 0 ;
	if ( value != m_pCDcdDiagram->getHideIppanekiEkimei() )
	{
		m_pCDcdDiagram->setHideIppanekiEkimei( value ) ;
		update_adjustProp() ;
		update_updateScreen() ;
		Invalidate() ;	

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDiagramViewProp( this ) ;

		iRv = 1 ;
	}
	return ( iRv ) ;
}

	// ********************************
	//@name	CDcdDiagrem2-����
	// ********************************
CdDcdZoneXy CWndDiagram::calcDiagramZoneDcd()const 
{
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;

	CdDcdZoneXy	zoneDiagramZoneDcd = 
		m_pCDcdDiagram->calcDiagramZoneDcd( &aTarget ) ;
	return zoneDiagramZoneDcd ;
}


	// ********************************
	//@name	CWndDiagram-����
	// ********************************

	// ********************************
	//@name	CWndDiagram-���
	// ********************************
CDcdDiagram2* CWndDiagram::getCDcdDiagram() 
{
	return m_pCDcdDiagram ;
}

	// ********************************
	//@name	CWndDiagram-�\�z
	// ********************************
BOOL CWndDiagram::Create( const RECT& rect, CWnd* pParentWnd, UINT nID )
{
	return CreateEx( 0 
		, AfxRegisterWndClass( CS_DBLCLKS //| CS_HREDRAW | CS_VREDRAW 
			, LoadCursor( NULL , IDC_ARROW ) 
			, (HBRUSH)GetStockObject( WHITE_BRUSH ) 
			, NULL ) 
		, "CWndDiagram"	//	���̕����񂪕\������邱�Ƃ͂���܂���
		, WS_CHILD | WS_VSCROLL | WS_HSCROLL | WS_TABSTOP
		, rect
		, pParentWnd
		, nID
		, NULL ) ;
}

BOOL CWndDiagram::Create( CWnd* pParentWnd, UINT nID )
{
	return CreateEx( 0 
		, AfxRegisterWndClass( CS_DBLCLKS //| CS_HREDRAW | CS_VREDRAW 
			, LoadCursor( NULL , IDC_ARROW ) 
			, (HBRUSH)GetStockObject( WHITE_BRUSH ) 
			, NULL ) 
		, "CWndDiagram"	//	���̕����񂪕\������邱�Ƃ͂���܂���
		, WS_CHILD | WS_VSCROLL | WS_HSCROLL | WS_TABSTOP
		, CRect( 0 , 0 , 0 , 0 ) 
		, pParentWnd
		, nID
		, NULL ) ;
}
	// ********************************
	//@name	CWndDiagram-����
	// ********************************

void CWndDiagram::onUpdateCentDedDgrDia() 
{
	if ( !m_bReadCWndDiagramDefault )
	{
		//	�ŏ��Ƀ_�C���O������\������Ƃ��ɂ́A
		//	.ini �t�@�C������A�X�N���[���ʒu��
		//	�r���̐ݒ��ǂݍ���
		getCDiagramEditApp()->readCWndDiagramViewProp( this ) ;

		m_bReadCWndDiagramDefault = true ;
	}

	// --------------------------------		
	update_adjustProp() ;
	update_updateScreen() ;
	Invalidate() ;
}
	
void CWndDiagram::onUpdateCentDedDgrRessya() 
{
	Invalidate() ;
}

// ----------------------------------------------------------------

CWndDiagram::CWndDiagram():
	m_pCDcdDiagram( NULL ) , 
	m_bReadCWndDiagramDefault( false ) 
{
	m_CdScrollbarPropX.setAdjustPosByPage( true ) ;
	m_CdScrollbarPropY.setAdjustPosByPage( true ) ;
}

CWndDiagram::~CWndDiagram()
{
}


BEGIN_MESSAGE_MAP(CWndDiagram, CWnd)
	//{{AFX_MSG_MAP(CWndDiagram)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CWndDiagram ���b�Z�[�W �n���h��

int CWndDiagram::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (super::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_pCDcdDiagram = new CDcdDiagram2() ;
	
	return 0;
}

void CWndDiagram::OnDestroy() 
{
	if ( m_pCDcdDiagram != NULL ){
		delete m_pCDcdDiagram ;
		m_pCDcdDiagram = NULL ;
	}
	
	super::OnDestroy();
	
}

void CWndDiagram::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	CDcdTargetOnPaint	aTarget( GetSafeHwnd() , &dc.m_ps ) ;
	
	if ( m_pCDcdDiagram != NULL ){
		m_pCDcdDiagram->DcDraw( &aTarget ) ;
	}
}

void CWndDiagram::OnSize(UINT nType, int cx, int cy) 
{
	LogMsg( "CWndDiagram::OnSize(%d,%d,%d)" , nType , cx , cy ) ;

	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;

	//memo: CWndDiagram::OnSize()�ł́ASIZE_RESTORED�ȊO�͔������Ȃ�
	//���̃E�C���h�E�ł́A 
	//SIZE_RESTORED�ȊO(SIZE_MAXIMIZED,SIZE_MINIMIZED�Ȃ�)
	//�͔������܂���B
	//�y���R�z
	//���̃E�C���h�E�͎q�E�C���h�E�ł��B�ʒu��T�C�Y�́A
	//�e�E�C���h�E�ł���CDcdDiagramView�ɂ����
	//���䂳��Ă��܂��B
	//�e�E�C���h�E�́A���̎q�E�C���h�E�ɑ΂���
	//�ŏ����E�ő剻���s���܂���B

	if ( ( nType == SIZE_MAXIMIZED      //	�E�B���h�E�͍ő�\������Ă��܂�
	    || nType == SIZE_RESTORED )     //	�E�B���h�E�̓T�C�Y�ύX�����
	    								//	���܂����A
		                                //	�T�C�Y�ύX�̎�ނ� SIZE_MINIMIZED 
		                                //	�ł� SIZE_MAXIMIZED 
										//	�ł�����܂���B
		&& cx > 0 && cy > 0 )
	{
		//	�E�C���h�E���T�C�Y1�ȏ�ŕ\������Ă���ꍇ�B
		//	(�E�C���h�E���ŏ����̏ꍇ�E
		//	�܂��̓T�C�Y��0�ɂȂ����ꍇ�́A�������s���܂���B)

		CdDcdSizeXy	sizeClientSize ; 

		////memo: CWndDiagram::OnSize()�ł� IsWindowVisible() �̌��ʁB
		////	�u�\������Ă���v�̔���ɁA���̃R�[�h��
		////	���ʂ�����܂���(��F����\���E�E�C���h�E�̍ő剻�Ȃ�)
		//if ( !IsWindowVisible() )
		//{
		//	LogMsg( "\tNOT_VISIBLE" ) ;
		//}
		//else 

		{

			CdDcdZoneXy	zoneZone_Dgr = getZone_Dgr() ;

			LogMsg( "CWndDiagram::OnSize(%d,%d)" , cx , cy ) ;
			CdDcdZoneXy	zoneDiagramZoneDcd 
				= getCDcdDiagram()->calcDiagramZoneDcd( &aTarget ) ;
			if ( zoneDiagramZoneDcd.getX().getSize() > 0 &&
				zoneDiagramZoneDcd.getY().getSize() > 0 )
			{
				sizeClientSize.setX( cx ).setY( cy ) ;
			}
			else
			{
				LogMsg( "\tsizeClientSize NOT AVAILABLE" ) ;
			}
		}
		//sizeClientSize = �N���C�A���g�̈�T�C�Y�B
		//	�������A�_�C���O�����r���[�̈�̃T�C�Y�� 
		//	x,y �̂����ꂩ����	0�Ȃ�A����������0�ł��B
		//�y���R�z�_�C���O�����r���[�̈�̃T�C�Y��0�̏ꍇ�́A
		//	getZone_Dgr() �����������삵�Ȃ����߂ł��B

		{
			update_adjustProp() ;

			//�X�N���[���o�[�̓���͈͂��A�V�����E�C���h�E�T�C�Y�ɍ��킹�܂��B
			update_updateScreen() ;

			//memo: CWndDiagram::OnSize() �ł́AInvalidate()�̕K�v��
			//	�E�C���h�E�T�C�Y�ύX���ɁA
			//	�\���̑傫��(�_�C���O�������W1�������DcDraw���W)��
			//	�ύX���Ȃ��̂Ȃ�A
			//	Invalidate() ( �E�C���h�E�̑S�ʍĕ`�� )�͕K�v����܂���B
		}

	}
	// --------------------------------
	super::OnSize(nType, cx, cy);

	LogMsg( "CWndDiagram::OnSize()=" ) ;
}

void CWndDiagram::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;

	CdDcdZoneXy	zoneDiagramZoneDcd = m_pCDcdDiagram->calcDiagramZoneDcd( &aTarget ) ;
	//zoneDiagramZoneDcd = �E�C���h�E��ŁA�_�C���O�������\�������̈�

	//	X�����ł́A�_�C���O���������̓_�C���O�����r���[�ɕ\������܂���B
	if ( zoneDiagramZoneDcd.getX().getSize() <= 0 )
	{
		return ;
	}

	if ( pScrollBar == NULL )
	{
		CdDcdZone	zoneCentDedDgrDia = m_pCDcdDiagram->getCentDedDgrDia()->getZone().getX()  ;
		CdDcdZone	zoneCDcdDiagram = m_pCDcdDiagram->getZone_Dgr( &aTarget ).getX() ;
		CdDcdZone	zoneCDcdDiagramPrev = zoneCDcdDiagram ;


		switch( nSBCode ){
		 case SB_LEFT :	//   ���[�փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCentDedDgrDia.getPos() ) ;
			}
			break ;
		 case SB_RIGHT :	//   �E�[�փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCentDedDgrDia.getEndPos() - 
					zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		 case SB_LINELEFT :		//   ���փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() - 
					m_pCDcdDiagram->getVlinePitch() ) ;
			}
			break ;
		 case SB_LINERIGHT :	//   �E�փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() + 
					m_pCDcdDiagram->getVlinePitch() ) ;
			}
			break ;
		 case SB_PAGELEFT :	// 1 �y�[�W���փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() - 
					zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		 case SB_PAGERIGHT :	//   1 �y�[�W�E�փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() + 
					zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		 case SB_THUMBPOSITION :	//  ��Έʒu�փX�N���[���B���݈ʒu�͈��� nPos �Ŏw�肳��܂��B
			{
				SCROLLINFO	aSCROLLINFO ;
				memset( &aSCROLLINFO , 0 , sizeof(aSCROLLINFO) ) ;
				aSCROLLINFO.cbSize = sizeof(aSCROLLINFO) ;			
				GetScrollInfo( SB_HORZ , &aSCROLLINFO , SIF_ALL ) ;
				int iPos = aSCROLLINFO.nPos ;
				zoneCDcdDiagram.setPos( iPos ) ;
			}
			break ;
		 case SB_THUMBTRACK :	//   �X�N���[�� �{�b�N�X���w��ʒu�փh���b�O���܂��B���݈ʒu�͈��� nPos �Ŏw�肳��܂�
			{
				SCROLLINFO	aSCROLLINFO ;
				memset( &aSCROLLINFO , 0 , sizeof(aSCROLLINFO) ) ;
				aSCROLLINFO.cbSize = sizeof(aSCROLLINFO) ;			
				GetScrollInfo( SB_HORZ , &aSCROLLINFO , SIF_ALL ) ;
				int iPos = aSCROLLINFO.nTrackPos ;
				zoneCDcdDiagram.setPos( iPos ) ;
			}
			break ;

		 case SB_ENDSCROLL :	//   �X�N���[���I���B
			break ;
		}
		if ( zoneCDcdDiagramPrev != zoneCDcdDiagram )
		{
			//memo: CWndDiagram �X�N���[������ setZone_Dgr()�Ăяo��
			//	update_updateScreen() �ɂ��E�C���h�E���X�N���[������A
			//	�X�N���[���Ŗ����ɂȂ�̈�ɑ΂��Ă����ĕ`�悪�ł���悤��
			//	�Ȃ�܂����B
			//	����ɂ��AInvalidate() ���Ăяo���K�v�͂Ȃ��Ȃ�܂����B
			//	CWndDiagram::setZone_Dgr() �͓����� Invalidate() 
			//	���Ăяo�����߁A���̌Ăяo���͔����邱�Ƃɂ��܂����B

			//setZone_Dgr( 
			//	CdDcdZoneXy( zoneCDcdDiagram , getZone_Dgr().getY() ) ) ;
			m_pCDcdDiagram->setZone_Dgr( &aTarget , 
				CdDcdZoneXy( zoneCDcdDiagram , getZone_Dgr().getY() ) ) ;

			update_adjustProp() ;
			update_updateScreen() ;
		}
		return ;
	}
	
	super::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CWndDiagram::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;

	CdDcdZoneXy	zoneDiagramZoneDcd = m_pCDcdDiagram->calcDiagramZoneDcd( &aTarget ) ;
	//zoneDiagramZoneDcd = �E�C���h�E��ŁA�_�C���O�������\�������̈�

	//	Y�����ł́A�_�C���O���������̓_�C���O�����r���[�ɕ\������܂���B
	if ( zoneDiagramZoneDcd.getY().getSize() <= 0 )
	{
		return ;
	}

	if ( pScrollBar == NULL )
	{
		CdDcdZone	zoneCentDedDgrDia = m_pCDcdDiagram->getCentDedDgrDia()->getZone().getY()  ;
		CdDcdZone	zoneCDcdDiagram = m_pCDcdDiagram->getZone_Dgr( &aTarget ).getY() ;
		CdDcdZone	zoneCDcdDiagramPrev = zoneCDcdDiagram ;


		switch( nSBCode ){
		 case SB_TOP :	// ��ԏ�܂ŃX�N���[���B 
			{
				zoneCDcdDiagram.setPos( zoneCentDedDgrDia.getPos() ) ;
			}
			break ;
		 case SB_BOTTOM :	//  ��ԉ��܂ŃX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCentDedDgrDia.getEndPos() - 
					zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		 case SB_LINEUP :	//  1 �s��փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() - 
					m_pCDcdDiagram->getVlinePitch() ) ;
			}
			break ;
		 case SB_LINEDOWN : // 1 �s���փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() + 
					m_pCDcdDiagram->getVlinePitch() ) ;
			}
			break ;
		 case SB_PAGEUP :	//  1 �y�[�W��փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() - 
					zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		 case SB_PAGEDOWN :	//  1 �y�[�W���փX�N���[���B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() + 
					zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		 case SB_THUMBPOSITION :	//  ��Έʒu�փX�N���[���B���݈ʒu�͈��� nPos �Ŏw�肳��܂��B
			{
				SCROLLINFO	aSCROLLINFO ;
				memset( &aSCROLLINFO , 0 , sizeof(aSCROLLINFO) ) ;
				aSCROLLINFO.cbSize = sizeof(aSCROLLINFO) ;			
				GetScrollInfo( SB_VERT , &aSCROLLINFO , SIF_ALL ) ;
				int iPos = aSCROLLINFO.nPos ;
				zoneCDcdDiagram.setPos( iPos ) ;
			}
			break ;
		 case SB_THUMBTRACK :	//   �X�N���[�� �{�b�N�X���w��ʒu�փh���b�O���܂��B���݈ʒu�͈��� nPos �Ŏw�肳��܂�
			{
				SCROLLINFO	aSCROLLINFO ;
				memset( &aSCROLLINFO , 0 , sizeof(aSCROLLINFO) ) ;
				aSCROLLINFO.cbSize = sizeof(aSCROLLINFO) ;			
				GetScrollInfo( SB_VERT , &aSCROLLINFO , SIF_ALL ) ;
				int iPos = aSCROLLINFO.nTrackPos ;
				zoneCDcdDiagram.setPos( iPos ) ;
			}
			break ;

		 case SB_ENDSCROLL :	//   �X�N���[���I���B
			break ;
		}
		if ( zoneCDcdDiagramPrev != zoneCDcdDiagram )
		{
			//memo: CWndDiagram �X�N���[������ setZone_Dgr()�Ăяo��
			//	update_updateScreen() �ɂ��E�C���h�E���X�N���[������A
			//	�X�N���[���Ŗ����ɂȂ�̈�ɑ΂��Ă����ĕ`�悪�ł���悤��
			//	�Ȃ�܂����B
			//	����ɂ��AInvalidate() ���Ăяo���K�v�͂Ȃ��Ȃ�܂����B
			//	CWndDiagram::setZone_Dgr() �͓����� Invalidate() ��
			//	�Ăяo�����߁A���̌Ăяo���͔����邱�Ƃɂ��܂����B

			//setZone_Dgr( 
			//	 CdDcdZoneXy( getZone_Dgr().getX() , zoneCDcdDiagram ) ) ;
			m_pCDcdDiagram->setZone_Dgr( &aTarget , 
				CdDcdZoneXy( getZone_Dgr().getX() , zoneCDcdDiagram )  ) ;

			update_adjustProp() ;
			update_updateScreen() ;
		}
		return ;
	}
	
	
	super::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CWndDiagram::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	bool bRv = false ;
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;



	// --------------------------------
	//	���������̃L�[�{�[�h�ɂ��X�N���[�����ʂ�
	//	�\���͈͂��v�Z
	// --------------------------------
	{
		CdDcdZone	zoneCentDedDgrDia = m_pCDcdDiagram->getCentDedDgrDia()->getZone().getX()  ;
		CdDcdZone	zoneCDcdDiagram = m_pCDcdDiagram->getZone_Dgr( &aTarget ).getX() ;
		CdDcdZone	zoneCDcdDiagramPrev = zoneCDcdDiagram ;
		//zoneCDcdDiagram=���݂̕\���͈�

		switch( nChar ){
		 case VK_LEFT :		//WM_HSCROLL SB_LINELEFT �Ɠ����ł�
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() - 
						m_pCDcdDiagram->getVlinePitch() ) ;
			}
			break ;
		 case VK_RIGHT :	//WM_HSCROLL SB_LINERIGHT �Ɠ����ł�
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() + 
						m_pCDcdDiagram->getVlinePitch() ) ;
			}
			break ;
		 case VK_HOME :	//WM_HSCROLL SB_PAGELEFT �Ɠ����ł��B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() - 
						zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		 case VK_END ://WM_HSCROLL SB_PAGERIGHT �Ɠ����ł��B
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() + 
						zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		}
		//	�\���͈͕ύX�v��������΁A
		//	CDcdDiagram2�ɓ��e�𔽉f���A
		//	�E�C���h�E���X�N���[��
		if ( zoneCDcdDiagramPrev != zoneCDcdDiagram )
		{
			//memo: CWndDiagram �X�N���[������ setZone_Dgr()�Ăяo��
			//	update_updateScreen() �ɂ��E�C���h�E���X�N���[������A
			//	�X�N���[���Ŗ����ɂȂ�̈�ɑ΂��Ă����ĕ`�悪�ł���悤��
			//	�Ȃ�܂����B
			//	����ɂ��AInvalidate() ���Ăяo���K�v�͂Ȃ��Ȃ�܂����B
			//	CWndDiagram::setZone_Dgr() �͓����� Invalidate() ��
			//	�Ăяo�����߁A���̌Ăяo���͔����邱�Ƃɂ��܂����B

			//setZone_Dgr(  
			//	CdDcdZoneXy( zoneCDcdDiagram , getZone_Dgr().getY() ) ) ;
			m_pCDcdDiagram->setZone_Dgr( &aTarget , 
				CdDcdZoneXy( zoneCDcdDiagram , getZone_Dgr().getY() ) ) ;

			update_adjustProp() ;
			update_updateScreen() ;

			bRv = true ;
		}
	}
	// --------------------------------
	//	���������̃L�[�{�[�h�ɂ��X�N���[���ʂ��v�Z
	// --------------------------------
	{
		CdDcdZone	zoneCentDedDgrDia = m_pCDcdDiagram->getCentDedDgrDia()->getZone().getY()  ;
		CdDcdZone	zoneCDcdDiagram = m_pCDcdDiagram->getZone_Dgr( &aTarget ).getY() ;
		CdDcdZone	zoneCDcdDiagramPrev = zoneCDcdDiagram ;
		//zoneCDcdDiagram=���݂̕\���͈�

		switch( nChar ){
		 case VK_UP :	//	WM_VSCROLL SB_LINEUP 
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() - 
					m_pCDcdDiagram->getVlinePitch() ) ;
			}
			break ;
		 case VK_DOWN :	//	WM_VSCROLL SB_LINEDOWN
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() + 
					m_pCDcdDiagram->getVlinePitch() ) ;
			}
			break ;
		 case VK_PRIOR ://	WM_VSCROLL SB_PAGEUP 
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() - 
					zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		 case VK_NEXT :	//	WM_VSCROLL SB_PAGEDOWN
			{
				zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() + 
					zoneCDcdDiagram.getSize() ) ;
			}
			break ;
		}
		//	�\���͈͕ύX�v��������΁A
		//	CDcdDiagram2�ɓ��e�𔽉f���A
		//	�E�C���h�E���X�N���[��
		if ( zoneCDcdDiagramPrev != zoneCDcdDiagram )
		{
			//memo: CWndDiagram �X�N���[������ setZone_Dgr()�Ăяo��
			//	update_updateScreen() �ɂ��E�C���h�E���X�N���[������A
			//	�X�N���[���Ŗ����ɂȂ�̈�ɑ΂��Ă����ĕ`�悪�ł���悤��
			//	�Ȃ�܂����B
			//	����ɂ��AInvalidate() ���Ăяo���K�v�͂Ȃ��Ȃ�܂����B
			//	CWndDiagram::setZone_Dgr() �͓����� Invalidate() ��
			//	�Ăяo�����߁A���̌Ăяo���͔����邱�Ƃɂ��܂����B

			//setZone_Dgr(  
			//	CdDcdZoneXy( getZone_Dgr().getX() , zoneCDcdDiagram) ) ;
			m_pCDcdDiagram->setZone_Dgr( &aTarget , 
				CdDcdZoneXy( getZone_Dgr().getX() , zoneCDcdDiagram ) ) ;

			update_adjustProp() ;
			update_updateScreen() ;

			bRv = true ;
		}
	}
	//zoneCDcdDiagram=�V�����\���͈�

	// --------------------------------
	if ( !bRv )
	{
		super::OnKeyDown(nChar, nRepCnt, nFlags);
	}
}

BOOL CWndDiagram::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	CDcdTargetGetDC	aTarget( GetSafeHwnd() ) ;
	if ( nFlags == 0 )
	{
		int iYMove = zDelta / (-WHEEL_DELTA) ;
		//iYMove = Y�����Ɉړ����鐔�B


		CdDcdZone	zoneCentDedDgrDia = 
			m_pCDcdDiagram->getCentDedDgrDia()->getZone().getY()  ;
		CdDcdZone	zoneCDcdDiagram = 
			m_pCDcdDiagram->getZone_Dgr( &aTarget ).getY() ;
		CdDcdZone	zoneCDcdDiagramPrev = zoneCDcdDiagram ;
		zoneCDcdDiagram.setPos( zoneCDcdDiagram.getPos() + 
					m_pCDcdDiagram->getVlinePitch() * iYMove ) ;
		if ( zoneCDcdDiagramPrev != zoneCDcdDiagram )
		{
			//memo: CWndDiagram �X�N���[������ setZone_Dgr()�Ăяo��
			//	update_updateScreen() �ɂ��E�C���h�E���X�N���[������A
			//	�X�N���[���Ŗ����ɂȂ�̈�ɑ΂��Ă����ĕ`�悪�ł���悤��
			//	�Ȃ�܂����B
			//	����ɂ��AInvalidate() ���Ăяo���K�v�͂Ȃ��Ȃ�܂����B
			//	CWndDiagram::setZone_Dgr() �͓����� Invalidate() ��
			//	�Ăяo�����߁A
			//	���̌Ăяo���͔����邱�Ƃɂ��܂����B
			
			//setZone_Dgr( 
			//	CdDcdZoneXy( getZone_Dgr().getX() , zoneCDcdDiagram ) ) ;
			m_pCDcdDiagram->setZone_Dgr( &aTarget , 
				CdDcdZoneXy( getZone_Dgr().getX() , zoneCDcdDiagram )  ) ;

			update_adjustProp() ;
			update_updateScreen() ;

			
		}


		return ( TRUE ) ;
	}	
	return super::OnMouseWheel(nFlags, zDelta, pt);
}

void CWndDiagram::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	int iRv = 0 ;
	CWaitCursor	aCursor ;

	//	�����\�r���[�ւ̈ړ������s
	{
		int iResult = OnLButtonDblClk_openJikokuhyouView( point ); 
		if ( iResult >= 1 )
		{
			iRv = 1 ;
		}
	}
	//	�����\�r���[���J���Ȃ��ꍇ�́A
	//	�w�̃v���p�e�B�_�C�A���O�̃I�[�v�������s
	if ( iRv <= 0 )	
	{
		int iResult = OnLButtonDblClk_openDlgEkiProp( point ) ;
		if ( iResult >= 1 )
		{
			iRv = 1 ;
		}
		
	}
	//	�ǂ̃r���[���J���Ȃ��ꍇ�́A
	//	�f�t�H���g����
	if ( iRv <= 0 )
	{
		CWnd::OnLButtonDblClk(nFlags, point);
	}
}

void CWndDiagram::OnContextMenu(CWnd* pWnd, CPoint point)
{
	//	�_�C���O�����r���[�̃R���e�L�X�g���j���[�́A
	//	���݂̂Ƃ���\�����܂���B
	{
		super::OnContextMenu(pWnd, point);
	}
}
} //namespace ViewDiagram
