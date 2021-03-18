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
/** @file */
// $Id: CConvTable.h 355 2016-08-18 16:41:28Z okm $
#ifndef OuLib_NsMu_CConvTable_h
#define OuLib_NsMu_CConvTable_h

#include <map>

namespace OuLib{
namespace NsMu{


/**
@brief
  �Q�̒l�̕ϊ��\����������N���X�ł��B

  ���̃N���X�́A�Q�̒l�̃y�A���̃e�[�u����ێ����A���̒l���L�[�ɉE�̒l�������E�܂��͂��̋t���s���܂��B
  
  ���̃N���X�ł́A�y�A��2�̒l�����ꂼ��Aleft,right �ƌĂт܂��B

<H4>
�y�g�����z
</H4>

1. ���̃N���X�̃C���X�^���X�𐶐����Ă��������B
  �e���v���[�g�����ɂ́Aleft�Aright �̌^���w�肵�Ă��������B

2. add() �ŁA�l�̃y�A��o�^���Ă��������B

3. rightFrom() �ŁAleft �ɑΉ����� right �̒l���擾�ł��܂��B�܂��AleftFrom() �ŁAright �ɑΉ����� left ���擾�ł��܂��B

  rightFrom() �́A���o�^�� left ���w�肳�ꂽ�ꍇ�A m_bRightDefaultEnable ���U�Ȃ�΁ALException �� throw ���܂��B
  m_bRightDefaultEnable ���^�Ȃ�ALException �� throw�����ArightFrom() �̖߂�l�Ƃ��� m_RightDefault ��Ԃ��܂��B
  ���̐U�镑���́A leftFrom() �����l�ł��B

  left �ɓ���̒l��2�ȏ�o�^�����ꍇ�ArightFrom() �̖߂�l���ǂ���̒l�ɂȂ�̂��͖���`�ł��B���̐U�镑���́A leftFrom() �����l�ł��B

@param TYPE_LEFT
	left �̌^���w�肵�Ă��������B
@param TYPE_RIGHT
	right �̌^���w�肵�Ă��������B

*/
template <class TYPE_LEFT , class TYPE_RIGHT >
class CConvTable
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	/**
		�Ή�����l��������Ȃ��ꍇ�ɃX���[������O�ł��B
	*/
	class LException
	{
	};
private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	/** left �� right �̃y�A���i�[����R���e�i�ł��B */
	std::map<TYPE_LEFT,TYPE_RIGHT>	m_Map ;
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	- false: left ��Ԃ��֐��ɂ����āA�l��������Ȃ��ꍇ�� LException �� 
		throw ���܂��B
	- true: left ��Ԃ��֐��ɂ����āA�l��������Ȃ��ꍇ�� LException �� 
		throw ������ m_LeftDefault ��Ԃ��܂��B
	*/
	bool m_bLeftDefaultEnable ;
	/** @see m_bLeftDefaultEnable */
	TYPE_LEFT	m_LeftDefault ;
	/**
	- false: right ��Ԃ��֐��ɂ����āA�l��������Ȃ��ꍇ�� LException �� 
		throw ���܂��B
	- true: right ��Ԃ��֐��ɂ����āA�l��������Ȃ��ꍇ�� LException �� 
		throw ������ m_RightDefault ��Ԃ��܂��B
	*/
	bool m_bRightDefaultEnable ;
	/** @see m_bRightDefaultEnable */
	TYPE_RIGHT	m_RightDefault ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CConvTable()
		: m_bLeftDefaultEnable( false ) 
		, m_bRightDefaultEnable( false ) 
	{
	}

public:
	// ********************************
	///@name	CConvTable - ����
	// ********************************
	///@{
	void setLeftDefaultEnable( bool value ){	m_bLeftDefaultEnable = value ;}
	bool getLeftDefaultEnable()const{	return m_bLeftDefaultEnable ;}
	/** m_LeftDefault ��ݒ肵�܂��Bm_bLeftDefaultEnable ��true �ɂȂ�܂��B*/
	CConvTable& setLeftDefault( const TYPE_LEFT& value )
	{
		m_LeftDefault = value ;
		m_bLeftDefaultEnable = true ;
		return *this ;
	}
	TYPE_LEFT getLeftDefault()const{	return m_LeftDefault ;}

	void setRightDefaultEnable( bool value ){	m_bRightDefaultEnable = value ;}
	bool getRightDefaultEnable()const{	return m_bRightDefaultEnable  ;}
	/** 
		m_RightDefault ��ݒ肵�܂��Bm_bRightDefaultEnable ��true �ɂȂ�܂��B
	*/
	CConvTable& setRightDefault( const TYPE_RIGHT& value )
	{
		m_RightDefault = value ;
		m_bRightDefaultEnable = true ;
		return *this ;
	}
	TYPE_RIGHT getRightDefault()const{	return m_LeftDefault ;}
	///@}
public:
	// ********************************
	///@name	CConvTable - ����
	// ********************************
	///@{
	/**
	@return
		�o�^���ꂽ�l�̃y�A�̐���Ԃ��܂��B
	*/
	int size(){	return m_Map.size() ;}
	/**
		�l�̃y�A��ǉ����܂��B
	@param left
		left �̒l
	@param rigth 
		rigth �̒l
	*/
	CConvTable& add( const TYPE_LEFT& left , const TYPE_RIGHT& right )
	{
		m_Map[left] = right ;	return *this ;
	}
	/**
		�w�肳�ꂽ left �̒l�ɑΉ����� rigth ��Ԃ��܂��B
	@param left
		left ���w�肵�Ă��������B
	@return 
		�Ή����� right �̒l��Ԃ��܂��B

		left ��ϊ��ł��Ȃ��ꍇ�̋����́A m_bRightDefaultEnable ��
		�����������������B

	@see m_bRightDefaultEnable
	*/
	TYPE_RIGHT rightFrom( const TYPE_LEFT& left )const
	{
		TYPE_RIGHT	rv = m_RightDefault ;
		std::map< TYPE_LEFT , TYPE_RIGHT >::const_iterator ite = m_Map.find( left ) ;
		if ( ite != m_Map.end() )
		{
			rv = ite->second ;
		}
		else if ( !m_bRightDefaultEnable )
		{
			throw( LException() ) ;
		}
		return rv ;
	}
	/**
		�w�肳�ꂽ right �̒l�ɑΉ����� left ��Ԃ��܂��B
	@param left
		right ���w�肵�Ă��������B
	@return 
		�Ή����� left �̒l��Ԃ��܂��B

		right ��ϊ��ł��Ȃ��ꍇ�̋����́A m_bLeftDefaultEnable ��
		�����������������B

	@see m_bLeftDefaultEnable
	*/
	TYPE_LEFT leftFrom( const TYPE_RIGHT& right )const 
	{
		TYPE_LEFT rv = m_LeftDefault ;
		std::map< TYPE_LEFT , TYPE_RIGHT >::const_iterator ite ;
		for ( ite = m_Map.begin() ; ite != m_Map.end() ; ite ++ )
		{
			if ( ite->second == right )
			{
				rv = ite->first ;
				break ;
			}
		}
		if ( ite == m_Map.end() )
		{
			if ( !m_bLeftDefaultEnable )
			{
				throw( LException() ) ;
			}
		}
		return rv ;
	}
	
	const std::map<TYPE_LEFT,TYPE_RIGHT>& getMap()const{  return m_Map ;}
	///@}
};

} //namespace NsMu
} //namespace OuLib


#endif //OuLib_NsMu_CConvTable_h
