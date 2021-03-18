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
//	CDcdFreeLine.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CDcdFreeLine.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CDcDeviceUnitSizeX.h"
#include "DcdCd\Pos\CLineFunc.h"
using namespace std ;

// ****************************************************************
//	CDcdFreeLine
// ****************************************************************
/**
 *	�����̕��������߂܂��B
 * @param i [in]
 *	���ƂɂȂ鐮�����w�肵�Ă��������B
 * @return
 *	-	i>0 �Ȃ� +1 ;	
 *	-	i==0 �Ȃ� 0 ;	
 *	-	i<0 �Ȃ� -1 ;	
 */
inline int sign( int i )
{
	if ( i > 0 ){	return +1 ; } ;
	if ( i < 0 ){	return -1 ; } ;
	return 0 ;
}



// ********************************
///@name	IfDcDraw
// ********************************
bool CDcdFreeLine::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool	bRv = 0 ;
	CConverter_WinGdi	aConverter ;

	// --------------------------------
	//	m_iLogicalunitWidth ��
	//	0 �Ȃ�A�����`�悵�܂���B
	// --------------------------------
	if ( m_CdLineProp.getLogicalunitWidth() <= 0 ){
		return ( false ) ;
	}


	
	// --------------------------------
	//	�`��̂��߂̘_���y���𐶐�
	//	(�T�C�Y�́A�������W�Ƃ��܂�)
	// --------------------------------
	Ou<CGdiHPenHolder>	pHPenHolder ;
	int iDeviceunitPenWidth = 
			CDcDeviceUnitSizeX( pIfDcdTarget->getHdc() ).
			setLogicalUnitSize( m_CdLineProp.getLogicalunitWidth() ).
			getDeviceUnitSize() ;
	if ( iDeviceunitPenWidth <= 0 ){
		iDeviceunitPenWidth = 1 ;
	}
	{
		CdPenProp	aCdPenProp ;
		aCdPenProp.setLogicalunitWidth( iDeviceunitPenWidth ) ;
			
		aCdPenProp.setColor( m_CdLineProp.getColor() ) ;
		aCdPenProp.setStyle( CdPenProp::SOLID ) ;
		pHPenHolder = pIfDcdTarget->createGdiHPenHolder( aCdPenProp ) ;
	}
	//iDeviceunitPenWidth  = �f�o�C�X���W�n�ł�
	//	�y���̑���


	// --------------------------------
	CdDcdPosXy	posOrg = m_posOrg ;
	CdDcdPosXy	posDst = m_posDst ;
	//posOrg,posDst = �N�_�ƏI�_�̍��W�i�_�����W�j

	// --------------------------------
	//	DcdTarget�͈̔͂ɁA�N�_�ƏI�_��␳
	// --------------------------------
	if ( m_bAdjustForDcdTarget ){
		//X������DcdTarget�͈̔͂Ɏ��߂�
		{
			CdDcdZone	zoneX( posOrg.getX() , posDst.getX() - posOrg.getX() );
			CdDcdZone	zoneXTarget = pIfDcdTarget->getZone().getX() ;
			CdDcdZone	zoneXCrossed = zoneX.CrossZone( zoneXTarget ) ;
			//X���W���A�f�o�C�X�̈���ɐ��K�����܂����B
			if ( zoneXCrossed.getSize() != 0 ){
				CLineFunc	aCLineFunc( m_posOrg , m_posDst ) ;
				
				//	zoneXCrossed ���`��̈�ɂ���A
				//	�������ΐ��ł���ꍇ�́A
				//	�N�_�E�I�_���ꂼ��ɂ����āA
				//	�f�o�C�X�̈���ɐ��K������
				//	X���W����Y���W�����߂܂��B
				//
				//	(zoneXCrossed.Size��0�̏ꍇ�i�����̏ꍇ�j�́A
				//	�Ή���������Y���W�����߂邱�Ƃ��ł��܂���̂ŁA
				//	calcLineYofX() ���Ăяo���Ă͂����܂���)
				if ( zoneX.getPos() != zoneXCrossed.getPos() ){
					posOrg.setX( zoneXCrossed.getPos() ) ;
					posOrg.setY( aCLineFunc.calcYofX( 
						zoneXCrossed.getPos() ) );
				}
				if ( zoneX.getEndPos() != zoneXCrossed.getEndPos() ){
					posDst.setX( zoneXCrossed.getEndPos() ) ;
					posDst.setY( aCLineFunc.calcYofX( 
						zoneXCrossed.getEndPos() ) ) ;
				}
			}
			if ( zoneXCrossed.getSize() == 0 && 
					!zoneXTarget.IsInner( zoneXCrossed.getPos() ) ){
				//	zoneXCrossed ���`��̈�O�ł���ꍇ�́A
				//	�����̕`��͂ł��܂���̂ŁA�U�Ń��^�[�����܂��B
				return ( false ) ;
			}
	
		}
		//Y������DcdTarget�͈̔͂Ɏ��߂�
		{
			CdDcdZone	zoneY( posOrg.getY() , posDst.getY() - posOrg.getY() );
			CdDcdZone	zoneYTarget = pIfDcdTarget->getZone().getY() ;
			CdDcdZone	zoneYCrossed = zoneY.CrossZone( zoneYTarget ) ;
			//Y���W���A�f�o�C�X�̈���ɐ��K�����܂����B
			if ( zoneYCrossed.getSize() != 0 ){
				CLineFunc	aCLineFunc( m_posOrg , m_posDst ) ;

				//	zoneYCrossed ���`��̈�ɂ���A
				//	�������ΐ��ł���ꍇ�́A
				//	�N�_�E�I�_���ꂼ��ɂ����āA
				//	�f�o�C�X�̈���ɐ��K������
				//	Y���W����X���W�����߂܂��B
				//
				//	(zoneYCrossed.Size��0�̏ꍇ�i�������̏ꍇ�j�́A
				//	�Ή���������X���W�����߂邱�Ƃ��ł��܂���̂ŁA
				//	calcLineXofY() ���Ăяo���Ă͂����܂���)
				if ( zoneY.getPos() != zoneYCrossed.getPos() ){
					posOrg.setX( aCLineFunc.calcXofY(
						zoneYCrossed.getPos() ) ) ;
					posOrg.setY( zoneYCrossed.getPos() ) ;
				}
				if ( zoneY.getEndPos() != zoneYCrossed.getEndPos() ){
					posDst.setX( aCLineFunc.calcXofY( 
						zoneYCrossed.getEndPos() ) ) ;
					posDst.setY( zoneYCrossed.getEndPos() ) ;
				}
			}
			if ( zoneYCrossed.getSize() == 0 && 
					!zoneYTarget.IsInner( zoneYCrossed.getPos() ) ){
				//	zoneYCrossed ���`��̈�O�ł���ꍇ�́A
				//	�����̕`��͂ł��܂���̂ŁA�U�Ń��^�[�����܂��B
				return ( false ) ;
			}
		}
		//posOrg,posDst = 
		//	DcdTarget�͈̔͂ɁA�N�_�ƏI�_��␳���܂����B
	}

	// --------------------------------
	//	�f�o�C�X���W�n�ł�
	//	���̍��W�����߂�
	// --------------------------------
	{
		POINT	aPoint = aConverter.POINTOf( posOrg ) ;
		::LPtoDP( pIfDcdTarget->getHdc() , &aPoint , 1 ) ;
		posOrg = aConverter.CdDcdPosXyOf( aPoint ) ;
	}
	{
		POINT	aPoint = aConverter.POINTOf( posDst ) ;
		::LPtoDP( pIfDcdTarget->getHdc() , &aPoint ,1 ) ;
		posDst = aConverter.CdDcdPosXyOf( aPoint ) ;
	}
	//posOrg,posDst = �f�o�C�X���W�ɕϊ����܂����B
	
	// --------------------------------
	//	DC�̑�����ύX
	// --------------------------------
	int idSave = SaveDC(  pIfDcdTarget->getHdc() ) ;
	int iMapModePrev = SetMapMode(  pIfDcdTarget->getHdc() , MM_TEXT ) ;
	//	SetMapMode() �� MM_TEXT ���[�h�Ɉڍs����ƁA
	//	�_���P�ʂƃf�o�C�X�P�ʂ̔�͂P�F�P�ɕύX����܂����A
	//	���W�̌��_�l�͕ύX����܂���B
	//
	//	LPtoDP() �ŕϊ����ꂽ�f�o�C�X���W�́A�f�o�C�X�R���e�L�X�g��
	//	����������_�Ƃ������W��Ԃ��܂��B
	//	���̍��W���g���ĕ`����s�����߂ɂ́A�f�o�C�X�R���e�L�X�g��
	//	�_�����W�̌��_���A�f�o�C�X���W 0,0 (�����)�ɐݒ肵�Ȃ��Ă�
	//	�Ȃ�܂���B
	//��  ���_�̐ݒ�́A�}�b�s���O���[�h�� MM_TEXT �ł����Ă��\�ł��B
	//	�������ASetViewportExtEx() , SetWindowExtEx() �Ƃ̈Ⴂ�ł��B
	SetViewportOrgEx( pIfDcdTarget->getHdc() , 0 , 0 , NULL ) ;

	HPEN	hPenSid = (HPEN)SelectObject( pIfDcdTarget->getHdc() , pHPenHolder->getHPen() ) ;

	// --------------------------------
	//	���̕`��
	// --------------------------------
	int iLongWidth = 0 ;
	bool	bYIsLong = false ;
	{
		int iXWidth = abs( posDst.getX() - posOrg.getX() ) ;	
		int iYWidth = abs( posDst.getY() - posOrg.getY() ) ;	
		//iXWidth, iYWidth = X,Y�̗����W�̍��B
		//	�N�_�E�I�_��������W�̏ꍇ��0
		if ( iXWidth > iYWidth ){
			iLongWidth = iXWidth ;
			bYIsLong = false ;
		}	else	{
			iLongWidth = iYWidth ;
			bYIsLong = true ;
		}
	}
	//iLongWidth = X,Y �̍��W�̍��̂����A�����ق�
	//iShortWidth = X,Y �̍��W�̍��̂����A�Z���ق�
	//	�N�_�E�I�_��������W�̏ꍇ��0
	//bYIsLong = false iLongWidth��X,iShortWidth��Y
	//	true iLongWidth��Y,iShortWidth��X

	
	if ( m_CdLineProp.isSolidLineStyle() ){
		// ********************************
		//	����
		// ********************************
		MoveToEx( pIfDcdTarget->getHdc() , posOrg.getX() , posOrg.getY() , 
			NULL ) ;
		LineTo(pIfDcdTarget->getHdc() , posDst.getX() , posDst.getY() ) ;
	}	else	{
		// ********************************
		//	�j��
		// ********************************
		string	aLINESTYLE = m_CdLineProp.getLinestyle() ;

		int idxStyle = 0 ;
		int iLongCurr ;
		for ( iLongCurr = 0 ; iLongCurr < iLongWidth ; ){
			CLineFunc	aCLineFunc( posOrg , posDst ) ;
			// --------------------------------
			//	�j������
			// --------------------------------
			{
				int iLongDst = iLongCurr + 
					( aLINESTYLE[idxStyle] - '0' ) * iDeviceunitPenWidth ; 
				iLongDst -=  ( iDeviceunitPenWidth - 1 ) ;
				idxStyle ++ ;
				if ( idxStyle >= (int)aLINESTYLE.size() ){
					iLongDst += ( aLINESTYLE[0] - '0' ) ; 
					idxStyle = 1 ;
				}

				if ( iLongDst > iLongWidth ){
					iLongDst = iLongWidth ;
				}
				//iLongDst = 
				//	����`����s�����́AiLongCurr �` iLongDst �͈̔͂ł��B

				
				int iXSrc = 0 ;
				int iYSrc = 0 ;
				int iXDst = 0 ;
				int iYDst = 0 ;
				if ( bYIsLong ){
					iYSrc = posOrg.getY() + 
						iLongCurr  * sign( posDst.getY() -  posOrg.getY() ) ;
					iYDst = posOrg.getY() + 
						iLongDst  * sign( posDst.getY() -  posOrg.getY() ) ;
					iXSrc = aCLineFunc.calcXofY( iYSrc ) ;
					iXDst = aCLineFunc.calcXofY( iYDst ) ;
				}	else	{
					iXSrc = posOrg.getX() + 
						iLongCurr * sign( posDst.getX() -  posOrg.getX() ) ;
					iXDst = posOrg.getX() + 
						iLongDst * sign( posDst.getX() -  posOrg.getX() ) ;
					iYSrc = aCLineFunc.calcYofX( iXSrc ) ;
					iYDst = aCLineFunc.calcYofX( iXDst ) ;
				}	
				MoveToEx( pIfDcdTarget->getHdc() , iXSrc , iYSrc , NULL ) ;
				LineTo(pIfDcdTarget->getHdc() , iXDst, iYDst) ;

				iLongCurr = iLongDst ;
			}
			// --------------------------------
			//	�󔒕���
			// --------------------------------
			{
				int iLongDst = iLongCurr + 
					( aLINESTYLE[idxStyle] - '0' ) * iDeviceunitPenWidth ;
				iLongDst += ( iDeviceunitPenWidth - 1 ) ;
				idxStyle ++ ;
				if ( idxStyle >= (int)aLINESTYLE.size() ){
					idxStyle = 0 ;
				}
				if ( iLongDst > iLongWidth ){
					iLongDst = iLongWidth ;
				}
				iLongCurr = iLongDst ;
			}
		}
		

	}
	// --------------------------------
	//	DC�̑����𕜋A
	// --------------------------------
	SelectObject( pIfDcdTarget->getHdc() , hPenSid ) ;
	hPenSid = NULL ;
	if ( idSave != 0 ){
		RestoreDC( pIfDcdTarget->getHdc() , idSave ) ;
		idSave = 0 ;
	}


	return ( true ) ;
}
bool CDcdFreeLine::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	CdDcdSizeXy	aCdDcdSizeXy ;
	if ( m_posOrg.getX() < m_posDst.getX() ){
		aCdDcdSizeXy.setX( 
			m_posDst.getX() - m_posOrg.getX() + 1 ) ;
	}	else	{
		aCdDcdSizeXy.setX( 
			m_posOrg.getX() - m_posDst.getX() + 1 ) ;
	}
	if ( m_posOrg.getY() < m_posDst.getY() ){
		aCdDcdSizeXy.setY(
			m_posDst.getY() - m_posOrg.getY() + 1 ) ;
	}	else	{
		aCdDcdSizeXy.setY(
			m_posOrg.getY() - m_posDst.getY() + 1 ) ;
	}
	// --------------------------------
	aCdDcdSizeXy.setX( aCdDcdSizeXy.getX() + 
		( m_CdLineProp.getLogicalunitWidth() - 1 ) ) ;
	aCdDcdSizeXy.setY( aCdDcdSizeXy.getY() - 
		( m_CdLineProp.getLogicalunitWidth() - 1 ) ) ;

	// --------------------------------
	*pCdDcdSizeXy = aCdDcdSizeXy ;
	
	return ( true ) ;
}


