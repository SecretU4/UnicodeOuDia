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
//	DcdCd\Pos\CdDcdZoneXy.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDcdZoneXy_h
#define  CdDcdZoneXy_h

#include "./CdDcdZone.h"
#include "./CdDcdPosXy.h"
#include "./CdDcdSizeXy.h"


// ****************************************************************
//	CdDcdZoneXy.h
// ****************************************************************
/**
 @brief
 �y�T�v�z
	   XY ���W��̋�`�͈͂�\���P���f�[�^�N���X�ł��B
*/
class CdDcdZoneXy
{
private:
	// ********************************
	///@name	����
	// ********************************
	///@{
	///	X�͈̔͂ł��B
	CdDcdZone	m_zoneX ;
	///	Y�͈̔͂ł��B
	CdDcdZone	m_zoneY ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CdDcdZoneXy(){} ;
	
	/**
	 @param tX [in]
	 	 X ���W�̒l���w�肵�Ă��������B
	 @param tY [in]
	 	 Y ���W�̒l���w�肵�Ă��������B
	*/
	CdDcdZoneXy( const CdDcdZone& tX , const CdDcdZone& tY ) : 
		m_zoneX( tX ) , m_zoneY( tY ) {};

	/**
	 	�w��̈ʒu����P�͈̔͂�\���I�u�W�F�N�g�𐶐����܂�
	 @param posX [in]
	 	X���W�̒l���w�肵�Ă��������B
	 @param posY [in]
	 	Y���W�̒l���w�肵�Ă��������B
	*/
	CdDcdZoneXy( DcdPos posX , DcdPos posY ) : 
		m_zoneX( posX , 1 ) , m_zoneY( posY , 1 ) {};

	/**
	 	�N�_�ʒu�ƃT�C�Y���w�肵�āA�I�u�W�F�N�g�𐶐����܂��B
	 @param posXy [in]
	 	�N�_���w�肵�Ă��������B
	 @param sizeXy [in]
	 	Y���W�̒l���w�肵�Ă��������B
	*/
	CdDcdZoneXy( const CdDcdPosXy& posXy ,
				const CdDcdSizeXy& sizeXy ) : 
		m_zoneX( posXy.getX() , sizeXy.getX() ) , 
		m_zoneY( posXy.getY() , sizeXy.getY() ) {};

	/**
	 	�N�_�ʒu����P�͈̔͂�\���I�u�W�F�N�g�𐶐����܂��B
	 @param posXy [in]
	 	�N�_���w�肵�Ă��������B
	 @param sizeXy [in]
	 	Y���W�̒l���w�肵�Ă��������B
	*/
	CdDcdZoneXy( const CdDcdPosXy& posXy ) : 
		m_zoneX( posXy.getX() , 1 ) , 
		m_zoneY( posXy.getY() , 1 ) {};

 public:
	// ********************************
	///@name	CdDcdZoneXy-����
	// ********************************
	///@{
	CdDcdZone getX()const{	return ( m_zoneX ) ;	};
	CdDcdZoneXy&  setX( const CdDcdZone& ev ){	
		m_zoneX = ev ;	return ( *this ) ;	};
	CdDcdZone getY()const{	return ( m_zoneY ) ;	};
	CdDcdZoneXy&  setY( const CdDcdZone ev ){	
		m_zoneY = ev ;	return ( *this ) ;	};
	/**
	 @return
	 	�N�_�̈ʒu��Ԃ��܂��B
	*/
	CdDcdPosXy	getPos()const{
		return ( CdDcdPosXy( m_zoneX.getPos() , m_zoneY.getPos() ) ) ;
	};
		
	/**
	 	�N�_��ݒ肵�܂��B
	 @param posXy [in]
	 	�N�_���w�肵�Ă��������B
	*/
	CdDcdZoneXy&	setPos( const CdDcdPosXy posXy ){
		m_zoneX.setPos( posXy.getX() ) ;
		m_zoneY.setPos( posXy.getX() ) ;
		return *this ;
	};
		
	/**
	 @return
	 	�̈�̃T�C�Y��Ԃ��܂��B
	*/
	CdDcdSizeXy	getSize()const{
		return ( CdDcdSizeXy( m_zoneX.getSize() , m_zoneY.getSize() ) ) ;
	};
		
	/**
	 	�T�C�Y��ݒ肵�܂��B
	 @param sizeXy [in]
	 	�T�C�Y���w�肵�Ă��������B
	*/
	CdDcdZoneXy&	setSize( const CdDcdSizeXy sizeXy ){
		m_zoneX.setSize( sizeXy.getX() ) ;
		m_zoneY.setSize( sizeXy.getY() ) ;
		return *this ;
	};
		
	/**
	 @return
	   �͈͂̏I�_�ʒu�̎��̈ʒu��Ԃ��܂��B
	 	���̈ʒu�́A�͈͂ɂ͊܂܂�܂���B
	*/
	CdDcdPosXy	getEndPos()const{
		return ( CdDcdPosXy( m_zoneX.getEndPos() , m_zoneY.getEndPos() ) ) ;
	};
	
	///@}

	// ********************************
	///@name	CdDcdZoneXy-����
	// ********************************
	///@{
	
	/**
	 	  �͈͂̑傫����\���l�̕������A���̐��E�܂��͕��̐��ɕύX���܂��B
	 	  ���̏ꍇ�ł��A���W�͈͕͂ς��܂���B
	 	(��) Pos = 1,Size=5�̃I�u�W�F�N�g�ɁA ev=-1 �ł��̃��\�b�h���Ăяo����
	 	Pos = 5 ,Size=-5 �ɂȂ�܂��B
	 @param ev [in]
	 	�����𐳂̐��ɂ���Ȃ�P�E���̐��ɂ���Ȃ�|�P���w�肵�Ă��������B
	*/
	CdDcdZoneXy& setSizeSign( int ev = 1 ){
		m_zoneX.setSizeSign( ev ) ;
		m_zoneY.setSizeSign( ev ) ;
		return *this ;
	};
	
	/**
	 	����CdDcdZoneXy�Ƃ̔�r���s���܂��B
	 @param ev [in]
	 	��r�Ώۂ��w�肵�Ă��������B
	 @return
	 	���ׂĂ̑����������ł���ΐ^�ł��B
	*/
	bool IsEqualTo( const CdDcdZoneXy& ev )const{
		return ( m_zoneX.IsEqualTo( ev.m_zoneX ) 
						&& m_zoneY.IsEqualTo( ev.m_zoneY ) ) ;
	};
	
	/**
	 	���͈̔͂ƁA�w�肳�ꂽ�ʂ͈̔͂Ƃ̊ԂŁA�������Ă���͈͂�
	 	���߂܂��B
	 @param ev [in]
	 	���������߂�ΏۂɂȂ� CdDcdZone �I�u�W�F�N�g���w�肵�Ă��������B
	 @return
	 	���͈̔͂ƁAev �Ƃ��������Ă���̈��Ԃ��܂��B
		x,y���ꂼ��ɂ��āA�����̈�����߂܂��B
	
	   - this �� ev �̂����ꂩ�� Size ���O�ł���΁A�N�_��this�Ɠ����A
	 	  �T�C�Y���O�̃I�u�W�F�N�g��Ԃ��܂��B
	   - this��ev�̕������قȂ�ꍇ�́Aev�̕��̕����𔽓]���āA
	 	  �����͈͂����߂܂��B���̏ꍇ�A�߂�l�̕�����
	 	  this�Ɠ��������ɂȂ�܂��B
	   - this �� ev �Ɍ������Ă���̈悪�Ȃ��ꍇ�́A�N�_��this�Ɠ����A
	 	  �T�C�Y���O�̃I�u�W�F�N�g��Ԃ��܂��B
	*/
	CdDcdZoneXy CrossZone( const CdDcdZoneXy& ev )const{
		return ( CdDcdZoneXy( m_zoneX.CrossZone( ev.getX() ) , 
							  m_zoneY.CrossZone( ev.getY() ) ) ) ; 
	};
	/**
	  	���͈̔͂ƁA�w�肳�ꂽ�ʂ͈̔͂��܂ށA
		�ł��������͈͂����߂܂��B
	 @param ev [in]
	  	��܂����߂�ΏۂɂȂ� CdDcdZoneXy �I�u�W�F�N�g���w�肵�Ă��������B
	 @return
	  	���͈̔͂ƁAev ���܂���̈��Ԃ��܂��B
	    - this��ev�̕������قȂ�ꍇ�́Aev�̕��̕����𔽓]���āA
	  	�����͈͂����߂܂��B���̏ꍇ�A�߂�l�̕�����
	  	this�Ɠ��������ɂȂ�܂��B
	*/
	CdDcdZoneXy ZoneOr( const CdDcdZoneXy& ev )const{
		return ( CdDcdZoneXy( m_zoneX.ZoneOr( ev.getX() ) , 
							  m_zoneY.ZoneOr( ev.getY() ) ) ) ; 
	};
	
	/**
	 	�w��̈ʒu�����͈̔͂Ɋ܂܂�Ă��邩�ǂ����𔻒f���܂��B
	 @param ev [in]
	 	���肷��ʒu���w�肵�Ă��������B
	 @return
	 	�ʒu�����͈̔͂Ɋ܂܂�Ă���ΐ^�ł��B
	*/
	bool IsInner( const CdDcdPosXy& ev )const{	
		return ( m_zoneX.IsInner( ev.getX() ) 
			  && m_zoneY.IsInner( ev.getY() )  ) ;
	};
	
	/**
	 	�w��̋�`�̈悪���͈̔͂Ɋ܂܂�Ă��邩�ǂ����𔻒f���܂��B
	 @param ev [in]
	 	���肷��ʒu���w�肵�Ă��������B
	 @return
	 	�ʒu�����͈̔͂Ɋ܂܂�Ă���ΐ^�ł��B
	*/
	bool IsInner( const CdDcdZoneXy& ev )const{	
		return ( m_zoneX.IsInner( ev.getX() ) 
			  && m_zoneY.IsInner( ev.getY() )  ) ;
	};
	
	///@}

	// ********************************
	///@name	���Z�q	
	// ********************************
	///@{
	bool operator ==( const CdDcdZoneXy& ev )const{	
		return (  IsEqualTo( ev ) ) ; 
	};
	bool operator !=( const CdDcdZoneXy& ev )const{
		return ( !IsEqualTo( ev ) ) ; 
	};
	///@}
	
};


#endif /*CdDcdZoneXy_h*/

