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
//	CdPenProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdPenProp_h
#define  CdPenProp_h
#include "CdColorProp.h"

// ****************************************************************
//	CdPenProp
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 *	   �y���̑�����ێ�����P���f�[�^�N���X�ł��B
 *
 *	   CConverter_WinGdi �N���X���g�p����ƁALOGPEN�\���̂Ƃ̊Ԃő��ݕϊ�
 *	���ł��܂��B
 */
class CdPenProp
{
// ********************************
///@name �C���i�[�^�C�v
// ********************************
///@{
 public:
	enum EStyle
	{
		/**	
		 *	�����̃y��	
		 */
		SOLID ,	
		/** 
		 *	�j���̃y���B
		 *	���̑������w�肳���ƁA�y���̕��͘_���P�ʂłP�Ɍ��肳��A
		 *	m_iWidth �͖����ɂȂ�܂�
		 */
		DASH ,
		/**
		 *	 �_���̃y���B
		 *	���̑������w�肳���ƁA�y���̕��͘_���P�ʂłP�Ɍ��肳��A
		 *	m_iWidth �͖����ɂȂ�܂�
		 */
		DOT ,
		/** 
		 *	��_�����̃y���B
		 *	���̑������w�肳���ƁA�y���̕��͘_���P�ʂłP�Ɍ��肳��A
		 *	m_iWidth �͖����ɂȂ�܂�
		 */
		DASHDOT ,
		/** 
		 *	��_�����̃y���B
		 *	���̑������w�肳���ƁA�y���̕��͘_���P�ʂłP�Ɍ��肳��A
		 *	m_iWidth �͖����ɂȂ�܂�
		 */
		DASHDOTDOT ,
		/**
		 *	 �k���̃y���B
		 *	�����`�悵�܂���
		 */
		NULLPEN ,
		/**	
		 *	�O�ڂ��鋫�E�l�p�`���w�肷�� GDI �֐� (Ellipse�ARectangle�A
		 *	RoundRect�APie�AChord �����o�֐��Ȃ�) �ɂ��쐬���������}�`��
		 *	�g���ɒ�����`�悷�邽�߂̃y���B�`��͎����ł�	
		 */
		SOLID_INSIDEFRAME ,	
	};
///@}
// ********************************
///@name	����
// ********************************
///@{
 private:
	/** 
	 *	���̑������^�Ȃ�A�y���̑����̓f�o�C�X�P�ʂŖ������ɂP�ɂȂ�܂� 
	 *
	 *	�f�t�H���g�ł͋U�ł�
	 */
	bool		m_bIsDevicewidth1 ;
	
	/** 
	 *	�_���P�ʂő�����\�������ł� �B
	 *
	 *	m_bIsDevicewidth1 ���^�̏ꍇ�A���̒l�͋����I�ɂO�ƂȂ�܂��B
	 *	
	 *	m_bIsDevicewidth1 ���U�ŁAm_eStyle �� SOLID �� SOLID_INSIDEFRAME ��
	 *	�ǂ���ł��Ȃ��ꍇ�́A���̒l�͋����I�ɂP�ƂȂ�܂��B
	 *	
	 *	m_bIsDevicewidth1 ���U�ŁAm_eStyle �� SOLID �� SOLID_INSIDEFRAME ��
	 *	�ꍇ�ɂ́A���̒l�͂P�ȏ�̔C�ӂ̒l�ɂȂ�܂��B
	 *
	 *	�f�t�H���g�ł�1�ł��B
	 */
	int			m_iLogicalunitWidth ;
	
	/**
	 *	�y���̐F�ł��B
	 *
	 *	�f�t�H���g�͍��ł�
	 */
	CdColorProp	m_colorrefColor ;

	/**	
	 *	�`��B
	 *
	 *	�f�t�H���g�� NULLPEN �ł��B
	 */
	EStyle	m_eStyle	;
///@}	
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/** 
	 *	������_���P�ʂŎw�肷��y�����w�肵�܂��B
	 * @param iLogicalunitWidth [in]
	 *	�_���P�ʂő�����\�������ł� 
	 *	m_bIsDevicewidth1 ���^�̏ꍇ�A���̒l�͋����I�ɂO�ƂȂ�܂��B
	 *	m_bIsDevicewidth1 ���U�ŁAm_eStyle �� SOLID �� SOLID_INSIDEFRAME ��
	 *	�ǂ���ł��Ȃ��ꍇ�́A���̒l�͋����I�ɂP�ƂȂ�܂��B
	 *	m_bIsDevicewidth1 ���U�ŁAm_eStyle �� SOLID �� SOLID_INSIDEFRAME ��
	 *	�ꍇ�ɂ́A���̒l�͂P�ȏ�̔C�ӂ̒l�ɂȂ�܂��B
	 * @param aColorref [in]
	 *	�y���̐F�ł�
	 * @param eStyle [in]
	 *	�y���̌`����w�肵�Ă��������B
	 */
	CdPenProp( int iLogicalunitWidth , 
				CdColorProp aColorref = CdColorProp( 0 , 0 , 0 ) , 
				EStyle eStyle = SOLID ) :
		m_bIsDevicewidth1( false ) ,
		m_iLogicalunitWidth( iLogicalunitWidth ) , 
		m_colorrefColor( aColorref ) ,
		m_eStyle( eStyle ) 
		{};
	
	/** 
	 *	�f�t�H���g�R���X�g���N�^�BNULLPEN �ɏ���������܂��B
	 *		- ����
	 *		- �����͘_���P�ʂłP
	 *		- �F�͍�
	 *
	 *	���`���܂��B
	 */
	CdPenProp() : 
		m_bIsDevicewidth1( false ) ,
		m_iLogicalunitWidth( 1 ) , 
		m_colorrefColor( CdColorProp( 0 , 0 , 0 ) ) ,
		m_eStyle( NULLPEN ) 
		{};
	
	
// ********************************
//	CdPenProp
// ********************************
 public:
	// ********************************
	///@name	����
	// ********************************
	///@{
	bool isDevicewidth1()const{	return m_bIsDevicewidth1 ; } ;
	CdPenProp& setIsDevicewidth1( bool ev ){
		m_bIsDevicewidth1 = ev ; return *this ;} ;
	
	/** 
	 *	������Ԃ��܂��B
	 * @return
	 *	- �������Ƀf�o�C�X�P�ʂP�ł���΁A�O
	 *	- NULLPEN �Ȃ�A�O
	 *	- �����łȂ��ꍇ�́A�P
	 *	- �����łȂ��ꍇ�́A�_���P�ʂł̑���
	 */
	int getLogicalunitWidth()const{
		if ( m_bIsDevicewidth1 ){	return ( 0 ) ; } ;

		if ( m_eStyle == NULLPEN ){
			return ( 0 ) ; 
		}
		if ( !( m_eStyle == SOLID || m_eStyle == SOLID_INSIDEFRAME ) ){
			return ( 1 ) ; 
		}

		if ( m_iLogicalunitWidth < 1 ){
			return ( 1 ) ;
		}
		return ( m_iLogicalunitWidth ) ;
	};
	/** 
	 *	������_���P�ʂŐݒ肵�܂��B
	 *	�������A m_eStyle �� SOLID , �܂��� SOLID_INSIDEFRAME �ȊO��
	 *	�ꍇ�A�܂��� m_bIsDevicewidth1 ���^�̏ꍇ�́A
	 *	���̃����o�֐��Ŏw�肵���l�͌��ʂ������܂���B
	 */
	CdPenProp& setLogicalunitWidth( int ev ){
		m_iLogicalunitWidth = ev ;
		return *this ;
	};
	
	CdColorProp getColor()const{	return m_colorrefColor ; } ;
	CdPenProp& setColor( CdColorProp ev ){
		m_colorrefColor = ev ;	return *this ; } ;
	
	EStyle getStyle()const{	return m_eStyle ; } ;
	CdPenProp& setStyle( EStyle ev ){
		m_eStyle = ev ;	return *this ; } ;
	
	/**
	 *	2�̃I�u�W�F�N�g�̊e���������������ǂ����𔻒肵�܂��B
	 * @param value [in]
	 *	��r�̑ΏۂƂȂ�I�u�W�F�N�g���w�肵�Ă��������B
	 * @return 
	 *	value �� *this �Ƃ̊ԂŁA���ׂĂ̑�������������ΐ^�ł��B
	 */
	bool isEqualTo( const CdPenProp& value )const{
		return ( 
			m_bIsDevicewidth1 == value.m_bIsDevicewidth1 &&
			m_iLogicalunitWidth == value.m_iLogicalunitWidth &&
			m_colorrefColor == value.m_colorrefColor &&
			m_eStyle == value.m_eStyle )	;
	};
	/**
	 *	isEqualTo() �Ɠ����ł��B
	 */
	bool operator==( const CdPenProp& value )const{
		return ( isEqualTo( value ) ) ;
	};
	bool operator!=( const CdPenProp& value )const{
		return ( !isEqualTo( value ) ) ;
	};

	/**
	 *	this �� b ���
	 *	�������i�������O�ɂȂ�j�Ȃ�^�ł��B
	 * @param b [in]
	 *	��r�̑ΏۂƂȂ�I�u�W�F�N�g���w�肵�Ă��������B
	 * @return 
	 *	this �� b ���
	 *	�������i�������O�ɂȂ�j�Ȃ�^�ł��B
	 */
	bool  less( const CdPenProp& value)const{
		if ( m_bIsDevicewidth1 != value.m_bIsDevicewidth1 ){
			return ( m_bIsDevicewidth1 < value.m_bIsDevicewidth1 ) ;
		}	else if ( m_iLogicalunitWidth != value.m_iLogicalunitWidth ){
			return ( m_iLogicalunitWidth < value.m_iLogicalunitWidth ) ;
		}	else if ( m_colorrefColor != value.m_colorrefColor ){
			return ( m_colorrefColor < value.m_colorrefColor ) ;
		}	else if ( m_eStyle != value.m_eStyle ){
			return ( m_eStyle < value.m_eStyle ) ;
		}
		return ( false ) ;
	};
	/**
	 *	less() �Ɠ����ł��B
	 */
	bool operator<( const CdPenProp& b )const{
		return less( b );
	};
	///@}
	
};

#endif /*CdPenProp_h*/
