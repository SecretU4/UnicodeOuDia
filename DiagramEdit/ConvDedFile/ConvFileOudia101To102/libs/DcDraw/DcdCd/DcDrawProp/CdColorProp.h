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
//	CdColorProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdColorProp_h
#define  CdColorProp_h

#include "DcdCd\Pos\DcdType.h"

// ****************************************************************
//	CdColorProp
// ****************************************************************
/**
 @brief
 �y�T�v�z
	�F�̑�����ێ�����P���f�[�^�N���X�ł��B

	CConverter_WinGdi �N���X���g�p����ƁACOLORREF�\���̂Ƃ̊Ԃő��ݕϊ�
	���s�����Ƃ��ł��܂��B
*/
class CdColorProp
{
// ********************************
///@name	����
// ********************************
///@{
 private:
	/**
	*	�F�̐Ԃ̗v�f�ł��B
	*/
	unsigned char m_iRed ;
	
	/**
	*	�F�̗΂̗v�f�ł��B
	*/
	unsigned char m_iGreen ;
	
	/**
	*	�F�̐̗v�f�ł��B
	*/
	unsigned char m_iBlue ;
	
///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	CdColorProp( 
		unsigned char iRed ,
		unsigned char iGreen ,
		unsigned char iBlue ) 
		: m_iRed( iRed ) 
		, m_iGreen( iGreen ) 
		, m_iBlue( iBlue )
	{};
	
	CdColorProp() 
		: m_iRed( 0 ) 
		, m_iGreen( 0 ) 
		, m_iBlue( 0 )
	{};

// ********************************
//	CdColorProp
// ********************************
public:
	// ********************************
	///@name	����
	// ********************************
	///@{
	unsigned char getRed()const{	return m_iRed ;};
	CdColorProp& setRed( unsigned char value ){	m_iRed = value ; return *this ;};
	unsigned char getGreen()const{	return m_iGreen ;};
	CdColorProp& setGreen( unsigned char value ){	m_iGreen = value ; return *this ;};
	unsigned char getBlue()const{	return m_iBlue ;};
	CdColorProp& setBlue( unsigned char value ){	m_iBlue = value ; return *this ;};
	///@}


	/**
	 *	2�̃I�u�W�F�N�g�̊e���������������ǂ����𔻒肵�܂��B
	 * @param value [in]
	 *	��r�̑ΏۂƂȂ�I�u�W�F�N�g���w�肵�Ă��������B
	 * @return 
	 *	value �� *this �Ƃ̊ԂŁA���ׂĂ̑�������������ΐ^�ł��B
	 */
	bool isEqualTo( const CdColorProp& value )const
	{
		return ( 
			m_iRed == value.m_iRed &&  
			m_iGreen == value.m_iGreen &&  
			m_iBlue == value.m_iBlue );
	};
	/**
	 *	isEqualTo() �Ɠ����ł��B
	 */
	bool operator==( const CdColorProp& value )const
	{	return ( isEqualTo( value ) ) ;	};	
	bool operator!=( const CdColorProp& value )const
	{	return ( !isEqualTo( value ) ) ;};	
	/**
	 *	this �� b ���
	 *	�������i�������O�ɂȂ�j�Ȃ�^�ł��B
	 * @param b [in]
	 *	��r�̑ΏۂƂȂ�I�u�W�F�N�g���w�肵�Ă��������B
	 * @return 
	 *	this �� b ���
	 *	�������i�������O�ɂȂ�j�Ȃ�^�ł��B
	 */
	bool  less( const CdColorProp& value )const
	{
		if ( m_iRed != value.m_iRed )
		{
			return ( m_iRed < value.m_iRed ) ;
		}
		else if ( m_iGreen != value.m_iGreen )
		{
			return ( m_iGreen < value.m_iGreen ) ;
		}
		else if ( m_iBlue != value.m_iBlue )
		{
			return ( m_iBlue < value.m_iBlue ) ;
		}
		return ( false ) ;
	};
	/**
	 *	less() �Ɠ����ł��B
	 */
	bool operator<( const CdColorProp& b )const
	{	return less( b );	};
	

};

#endif //CdColorProp_h
