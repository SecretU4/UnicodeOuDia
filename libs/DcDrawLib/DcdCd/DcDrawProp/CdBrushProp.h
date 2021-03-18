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
//	CdBrushProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdBrushProp_h
#define  CdBrushProp_h
#include "CdColorProp.h"

namespace DcDrawLib{
namespace DcdCd{
namespace DcDrawProp{

// ****************************************************************
//	CdBrushProp
// ****************************************************************
/**
* @brief
* �y�T�v�z
*  �u���V�̑�����ێ�����P���f�[�^�N���X�ł��B

*	   CConverter_WinGdi �N���X���g�p����ƁALOGBRUSH�\���̂Ƃ̊Ԃő��ݕϊ�
*	������A�u���V�n���h���𐶐�������ł��܂��B
*/
class CdBrushProp
{
// ********************************
///@name	�C���i�[�^�C�v
// ********************************
///@{
 public:
	enum EStyle
	{
		/** ���F�̃u���V�B 	*/
		SOLID ,

		/** ��������E��ւ� 45 �x�̃n�b�` */
		HATCHED_BDIAGONAL ,
		
		/** �����A�����̊i�q��̃n�b�`	*/
		HATCHED_CROSS ,

		/** 45 �x�̊i�q��̃n�b�`	*/
		HATCHED_DIAGCROSS ,

		/** ���ォ��E���ւ� 45 �x�̃n�b�`	*/
		HATCHED_FDIAGONAL ,

		/** �����̃n�b�`	*/
		HATCHED_HORIZONTAL ,

		/** �����̃n�b�`	*/
		HATCHED_VERTICAL ,

		/** ����̃u���V�B�Ȃɂ��`�悵�܂���B	*/
		NULLBRUSH ,
	};
///@}
// ********************************
///@name	����
// ********************************
///@{
 private:
	/**
	*	�u���V�̐F�ł��B
	*	�f�t�H���g�͍��ł��B
	*/
	CdColorProp m_colorrefColor;
	
	/**	
	*	�`��B�f�t�H���g�́ANULLBRUSH �ł��B
	*/
	EStyle	m_eStyle	;
	
///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	*	�u���V�̐F�ƌ`����w�肵�܂��B
	* @param colorrefColor
	*	�u���V�̐F�ł�
	* @param eStyle	
	*	�`��B�f�t�H���g�́ASOLID �ł��B
	*/
	CdBrushProp( CdColorProp colorrefColor , 
				EStyle	eStyle = SOLID ) 
		: m_colorrefColor( colorrefColor ) 
		, m_eStyle( eStyle ){} ;
	
	CdBrushProp() : 
		m_colorrefColor( CdColorProp( 0 , 0 , 0 ) ) ,
		m_eStyle( NULLBRUSH ) {};
	

// ********************************
//	CdBrushProp
// ********************************
 public:
	// ********************************
	///@name	����
	// ********************************
	///@{
	CdColorProp getColor()const{	return m_colorrefColor ; } ;
	CdBrushProp& setColor( CdColorProp ev ){
		m_colorrefColor = ev ;	return *this ; } ;
	
	EStyle getStyle()const{	return m_eStyle ; } ;
	CdBrushProp& setStyle( EStyle ev ){
		m_eStyle = ev ;	return *this ; } ;

	/**
	 *	2�̃I�u�W�F�N�g�̊e���������������ǂ����𔻒肵�܂��B
	 * @param value [in]
	 *	��r�̑ΏۂƂȂ�I�u�W�F�N�g���w�肵�Ă��������B
	 * @return 
	 *	value �� *this �Ƃ̊ԂŁA���ׂĂ̑�������������ΐ^�ł��B
	 */
	bool isEqualTo( const CdBrushProp& value )const{
		return ( 
			m_colorrefColor == value.m_colorrefColor && 
			m_eStyle == value.m_eStyle );
	};
	/**
	 *	isEqualTo() �Ɠ����ł��B
	 */
	bool operator==( const CdBrushProp& value )const{
		return ( isEqualTo( value ) ) ;
	};	
	bool operator!=( const CdBrushProp& value )const{
		return ( !isEqualTo( value ) ) ;
	};	
	///@}
	/**
	 *	this �� b ���
	 *	�������i�������O�ɂȂ�j�Ȃ�^�ł��B
	 * @param b [in]
	 *	��r�̑ΏۂƂȂ�I�u�W�F�N�g���w�肵�Ă��������B
	 * @return 
	 *	this �� b ���
	 *	�������i�������O�ɂȂ�j�Ȃ�^�ł��B
	 */
	bool  less( const CdBrushProp& value )const{
		if ( m_colorrefColor != value.m_colorrefColor ){
			return ( m_colorrefColor < value.m_colorrefColor ) ; 
		}	else if ( m_eStyle != value.m_eStyle ){
			return ( m_eStyle < value.m_eStyle );
		}
		return ( false ) ;
	};
	/**
	 *	less() �Ɠ����ł��B
	 */
	bool operator<( const CdBrushProp& b )const{
		return less( b );
	};
	

};

} //namespace DcDrawProp
} //namespace DcdCd
} //namespace DcDrawLib

#endif /*CdBrushProp_h*/
