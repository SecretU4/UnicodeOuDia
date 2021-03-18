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
//****************************************************************
//	CdDrawTextProp.h
//****************************************************************
*/
/** @file */
#ifndef  CdDrawTextProp_h
#define  CdDrawTextProp_h
#include "CdColorProp.h"
#include "CdFontProp.h"
#include "CdDrawTextFormat.h"

//****************************************************************
//	CdDrawTextProp
//****************************************************************
/**
 * @brief
 * �y�T�v�z
 * 	�e�L�X�g��`�悷��ۂ̑�����ێ�����A�P���f�[�^�N���X�ł��B
 * 
 */
class CdDrawTextProp
{
// ********************************
/// @name	����
// ********************************
///@{
 private:
	/** 
	 *	�t�H���g���� 
	 *	�f�t�H���g�ł́A�����l�ƂȂ�܂��B�ݒ�K�{�̑����ł��B
	 */
	CdFontProp	m_CdFontProp ;

	/**	
	 *	�e�L�X�g��`�悷��ꍇ�̕����F�ł��B
	 *	�f�t�H���g�͍��ł��B
	 */
	CdColorProp	m_colorrefText ;
	
	/**
	 * 	�e�L�X�g�̔w�i��h�邩�ۂ��������܂�
	 * 	�^�Ȃ�w�i��h��܂��B
	 *
	 *	�f�t�H���g�͋U�ł��B
	 */
	bool		m_bIsOpaque ;

	/**
	 * 	�e�L�X�g��`�悷��ꍇ�́A�w�i�F�ł��B
	 * 	m_bIsOpaque ���^�̏ꍇ�ɂ����A�L���ł��B
	 */
	CdColorProp	m_colorrefBack ;
	
	/**
	 *	�e�L�X�g�`�掞�̑�����\���t���O
	 */
	CdDrawTextFormat	m_CdDrawTextFormat ;
///@}
	
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * 	�e�L�X�g�̔w�i�F���ŁA������ݒ肷��R���X�g���N�^�ł��B
	 * @param aCdFontProp [in]
	 * �t�H���g���� 
	 * @param colorrefText [in]
	 *	�e�L�X�g��`�悷��ꍇ�̕����F�ł��B
	 * @param colorrefBack [in]
	 * 	�e�L�X�g��`�悷��ꍇ�́A�w�i�F�ł��B
	 * @param aCdDrawTextFormat [in]
	 *	�e�L�X�g�`�掞�̑�����\���t���O
	 */
	CdDrawTextProp( 
			const CdFontProp& aCdFontProp ,
			CdColorProp	colorrefText ,
			CdColorProp	colorrefBack ,
			CdDrawTextFormat	aCdDrawTextFormat = CdDrawTextFormat() ) :
		m_CdFontProp( aCdFontProp ) ,
		m_colorrefText( colorrefText ) ,
		m_bIsOpaque( true ) ,
		m_colorrefBack( m_colorrefBack ) ,
		m_CdDrawTextFormat( aCdDrawTextFormat ) {};

	/**
	 * 	�e�L�X�g�̔w�i�F�Ȃ��i�����j�́A������ݒ肷��R���X�g���N�^�ł��B
	 * @param aCdFontProp [in]
	 * �t�H���g���� 
	 * @param colorrefText [in]
	 *	�e�L�X�g��`�悷��ꍇ�̕����F�ł��B
	 * @param aCdDrawTextFormat [in]
	 *	�e�L�X�g�`�掞�̑�����\���t���O
	 */
	CdDrawTextProp( 
			const CdFontProp& aCdFontProp ,
			CdColorProp	colorrefText = CdColorProp( 0 , 0 , 0 ) ,
			CdDrawTextFormat	aCdDrawTextFormat = CdDrawTextFormat() ) :
		m_CdFontProp( aCdFontProp ) ,
		m_colorrefText( colorrefText ) ,
		m_bIsOpaque( false ) ,
		m_colorrefBack( CdColorProp( 255 , 255 , 255 ) ) ,
		m_CdDrawTextFormat( aCdDrawTextFormat ) {};

	/**
	 *	�f�t�H���g�R���X�g���N�^�ł��B
	 * 	�e�L�X�g�̔w�i�F�Ȃ��i�����j�ł��B
	 */
	CdDrawTextProp() :
		m_colorrefText( CdColorProp( 0 , 0 , 0 ) ) ,
		m_bIsOpaque( false ) ,
		m_colorrefBack( CdColorProp( 255 , 255 , 255 ) ) {};


// ********************************
//	CdDrawTextProp
// ********************************
 public:
	// ********************************
	/// @name	����
	// ********************************
	///@{
	CdFontProp	getCdFontProp()const{
		return 	m_CdFontProp ;	};
	CdDrawTextProp& setCdFontProp( const CdFontProp& ev ){
		m_CdFontProp = ev ;	return *this ; };

	CdColorProp	getTextColor()const{	
		return m_colorrefText ;	};
	CdDrawTextProp& setTextColor( CdColorProp ev ){
		m_colorrefText = ev	; return *this ; } ;
	
	bool		getIsOpaque()const{
		return 	m_bIsOpaque ;	};
	CdDrawTextProp& setIsOpaque( bool ev ){
		m_bIsOpaque = ev ;	return *this ; } ;

	CdColorProp	getBackColor()const{
		return m_colorrefBack ;	};
	CdDrawTextProp& setBackColor( CdColorProp	ev ){
		m_colorrefBack = ev ;	
		m_bIsOpaque = false ;
		return *this ; } ;
	
	CdDrawTextFormat	getCdDrawTextFormat()const{
		return m_CdDrawTextFormat ;	};
	CdDrawTextProp& setCdDrawTextFormat( const CdDrawTextFormat& ev ){
		m_CdDrawTextFormat = ev ;	return *this ; } ;
	///@}
};


#endif /*CdDrawTextProp_h*/
