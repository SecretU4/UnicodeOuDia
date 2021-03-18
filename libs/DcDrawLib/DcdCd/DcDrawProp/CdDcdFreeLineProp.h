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
// ****************************************************************
//	CdDcdFreeLineProp
//	$Id: CdDcdFreeLineProp.h 314 2016-06-11 13:48:18Z okm $
// ****************************************************************
#ifndef  CdDcdFreeLineProp_h
#define  CdDcdFreeLineProp_h

#include <string>
#include "DcdCd\DcDrawProp\CdColorProp.h"

namespace DcDrawLib{
namespace DcdCd{
namespace DcDrawProp{

// ****************************************************************
//	CdDcdFreeLineProp
// ****************************************************************
/**
 @brief 
 �y�T�v�z
   �P���f�[�^�N���X�ł��B
   CDcdFreeLine �N���X�ɂ����̕`��́A������ێ����܂��B
 
   �����Ƃ���
 
 - ����
 - �`��(�����E�j���Ȃ�)
 - �F
 
 ��ێ����܂��B
 */
class CdDcdFreeLineProp
{

// ********************************
///@name ����
// ********************************
///@{
 private:
	/** 
		�_���P�ʂő�����\�������ł� �B
		
		�f�t�H���g�ł�1�ł��B
	
		0 �Ȃ�A�����`�悵�܂���B
	 */
	int			m_iLogicalunitWidth ;

	/**
		�y���̐F�ł��B
	
		�f�t�H���g�͍��ł�
	 */
	CdColorProp	m_colorrefColor ;

	/**
	   ���̌`��i�_���E�j���Ȃǁj���w�肵�܂��B
	
		���̃N���X�ł́A�_���E�j���̎w��́A������ŕ\�����܂��B
		���̕�����́A "1" �` "9" �܂ł̔��p���������ō\�����܂��B
		��������̕����͂P�������Ӗ��������A�����珇��
		�u�P�Ԗڂ̔j���̒����v�E�u�P�Ԗڂ̋󔒂̒����v�E
		�u�Q�Ԗڂ̔j���̒����v�E�u�Q�Ԗڂ̋󔒂̒����v�̏��ŁA�j����
		�\���v�f���w�肵�Ă��܂��B
		
		�󕶎���̏ꍇ�́A������\���܂��B
		
		�f�t�H���g�ł͎����ƂȂ�܂��B
	 */
	std::string	m_strLinestyle ;

///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/** 
	 @param iLogicalunitWidth [in]
		�_���P�ʂő�����\�������ł� �B
	 @param colorrefColor [in]
		�y���̐F�ł��B
		�f�t�H���g�͍��ł�
	 @param aLinestyle [in]
		�`��B
	 */
	CdDcdFreeLineProp( 
		int			iLogicalunitWidth ,
		CdColorProp	colorrefColor ,
		const std::string& aLinestyle ) :
		m_iLogicalunitWidth( iLogicalunitWidth ) ,
		m_colorrefColor( colorrefColor ) ,
		m_strLinestyle( aLinestyle ){};

	/** 
	 @param iLogicalunitWidth [in]
		�_���P�ʂő�����\�������ł� �B
	 @param colorrefColor [in]
		�y���̐F�ł��B
		�f�t�H���g�͍��ł�
	 */
	CdDcdFreeLineProp( 
		int			iLogicalunitWidth ,
		CdColorProp	colorrefColor = CdColorProp( 0 ,0 , 0) ) :
		m_iLogicalunitWidth( iLogicalunitWidth ) ,
		m_colorrefColor( colorrefColor )
	{
	};

	CdDcdFreeLineProp() :
		m_iLogicalunitWidth( 1 ) ,
		m_colorrefColor( CdColorProp( 0 ,0 , 0 ) )
	{
	};


// ********************************
//	CdDcdFreeLineProp
// ********************************
 public:
	// ********************************
	///@name CdDcdFreeLineProp::����
	// ********************************
	///@{
	int	getLogicalunitWidth()const
	{	return m_iLogicalunitWidth ;};
	CdDcdFreeLineProp& setLogicalunitWidth( int value )
	{	m_iLogicalunitWidth = value ; return *this ;};

	CdColorProp	getColor()const{	return m_colorrefColor ;};
	CdDcdFreeLineProp& setColor( CdColorProp value )
	{	m_colorrefColor = value ; return *this ; } ;
	
	std::string getLinestyle()const{	return m_strLinestyle ;};
	CdDcdFreeLineProp& setLinestyle( const std::string& value )
	{	m_strLinestyle = value ; return *this ; };
	
	
	/**
		m_Linestyle ���A�u�����v�̌`��ɐݒ肵�܂��B
	 */
	CdDcdFreeLineProp& setSolidLineStyle()
	{	m_strLinestyle.erase() ;	return *this ;	} ;

	bool isSolidLineStyle()
	{	return ( m_strLinestyle.empty() ) ;} ;
	
	/**
		���ׂĂ̑�����������Ԃɂ��܂��B
	 */
	void clear(){	*this = CdDcdFreeLineProp() ; } ;
	///@}

	/**
		2�̃I�u�W�F�N�g�̊e���������������ǂ����𔻒肵�܂��B
	 @param value [in]
		��r�̑ΏۂƂȂ�I�u�W�F�N�g���w�肵�Ă��������B
	 @return 
		value �� *this �Ƃ̊ԂŁA���ׂĂ̑�������������ΐ^�ł��B
	 */
	bool isEqualTo( const CdDcdFreeLineProp& value )const
	{
		return ( 
			m_iLogicalunitWidth == value.m_iLogicalunitWidth &&  
			m_colorrefColor == value.m_colorrefColor &&  
			m_strLinestyle == value.m_strLinestyle );
	};
	/**
		isEqualTo() �Ɠ����ł��B
	 */
	bool operator==( const CdDcdFreeLineProp& value )const
	{	return ( isEqualTo( value ) ) ;	};	
	bool operator!=( const CdDcdFreeLineProp& value )const
	{	return ( !isEqualTo( value ) ) ;};	
};
const char LINESTYLE_SOLID[] = "" ;
const char LINESTYLE_DOT[] = "11" ;
const char LINESTYLE_DOT2[]= "22" ;
const char LINESTYLE_DASH[]= "31" ;
const char LINESTYLE_DASH_DOT[]= "3111" ;
const char LINESTYLE_DASH_DOT_DOT[]= "311111" ;

} //namespace DcDrawProp
} //namespace DcdCd
} //namespace DcDrawLib

#endif //CdDcdFreeLineProp_h
