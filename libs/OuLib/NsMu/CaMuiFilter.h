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
//	CaMuiFilter.h
// ****************************************************************
*/
/** @file */
#ifndef  CaContFiler_h
#define  CaContFiler_h
#include <stddef.h>
#include "./Mui.h"

namespace OuLib{

#ifndef NO_NSMU
namespace NsMu{
#endif//NO_NSMU

// ****************************************************************
//	CaMuiFilter
// ****************************************************************
/**
@brief
  �A�_�v�^�N���X�ł��B
  "Mui<ElementType2>" �C���^�[�t�F�[�X���T�|�[�g����
�R���e�i�ɑ΂��āA ElementType1 �^�̒l��ϊ�������Őݒ�E
�擾���邱�Ƃ��ł��܂��B

  ���̃N���X�͒��ۃN���X�ł���A "Mui<ElementType1>" 
�C���^�[�t�F�[�X���T�|�[�g���܂��B����ΏۃI�u�W�F�N�g�́A 
"Mui<ElementType2>" �C���^�[�t�F�[�X���T�|�[�g���܂��B
�܂��A�I�[�o���C�h�\�ȉ��z�֐��Ƃ���
 onSet() �E onGet() �E onErase() ������܂��B

  ���̃N���X�ɑ΂��� insert() �� set() ���Ăяo���ƁA
���\�b�h�� onSet() ���Ăяo���āA�����ɓn���ꂽ
 ElementType1 �^�̒l�� ElementType2 �Ɍ^�ϊ����Ă���A
����ΏۃR���e�i m_pAdaptee �ɒǉ����܂��B

  ���l�ɁAget() ���Ăяo���ƁA���\�b�h�͒l�𑀍�ΏۃR���e�i
 m_pAdaptee ����擾������AonGet() �� ElementType2 ����
 ElementType1 �ɕϊ����Ă���Ăяo�����ɕԂ��܂��B

  �܂��Aerase() ���Ăяo���ƁA���\�b�h�͍폜����
�v�f�������ɂ��āAonErase() ���Ăяo���܂��B

   onSet() �� onGet() �́A�K���I�[�o���C�h���āA
ElementType1 �\ ElementType2 �̃f�[�^�ϊ����s��������
�������Ă��������B
   onErase() �́A�ʏ�I�[�o���C�h����K�v�͂���܂���B�A���A
�u onSet() �� m_pAdapett �ɒǉ������v�f�� m_pAdaptee ����
��菜���Ƃ��Ɍ㏈�����K�v�v�Ƃ����ꍇ�ɂ́A onSet() ��
���̌㏈�����������Ă��������B�Ⴆ��
 �uonSet() �ł̓I�u�W�F�N�g�� new �Ő������A�����
 m_pAdaptee  �ɒǉ�����v
�Ƃ����ꍇ�́A
�u onErase() �ŁAnew �Ő��������I�u�W�F�N�g�� delete ����v
���Ƃ��ł��܂��B

  	<H4>
  	�y�g�����z
  	</H4>
  	
  	�P�D  ���̃N���X�̔h���N���X���쐬���Ă��������B���̂Ƃ��A
  	 onSet() �� onGet() ���I�[�o���C�h���āA�^�ϊ��̏���������
  	���Ă��������B
  	
  	�Q�D  ���炩���߁A����ΏۃI�u�W�F�N�g�𐶐����Ă��������B
  	
  	�R�D  ���̃N���X�̃I�u�W�F�N�g�𐶐����Ă��������B
  	�R���X�g���N�^�̈����ɂ́A����ΏۃI�u�W�F�N�g���w�肵��
  	���������B
  	
  	@attention
  	 <b> ����ΏۃI�u�W�F�N�g�i "Mui<ElementType2>"
  	 �C���^�[�t�F�[�X���T�|�[�g����R���e�i�I�u�W�F�N�g�j�́A
  	��łȂ��Ă͂Ȃ�܂���B</b>
  	
  	�S�D  ���̂��Ƃ́A���̃N���X�̑S�Ẵ��\�b�h�����p�\�ł��B
  	
  	@attention
  	 <b>�����Ƃ��āA this �� ����ΏۃI�u�W�F�N�g m_pAdaptee ��
  	�֘A���L���ȊԂ́A m_pAdaptee �� "Mui<ElementType2>" 
  	���\�b�h�𒼐ڌĂяo���Ȃ��ł��������B</b>
  	  ���ɁA onErase() �ŗv�f�ɑ΂���㏈�����s���Ă���ꍇ�́A
  	 this ���o�R������ m_pAdaptee �ɑ΂��ėv�f�̒ǉ��E�폜��
  	�s���Ă��܂��ƁA�s���ȓ���ɂȂ�܂��B\n 
	m_pAdaptee �� "Mu<ElementType2>" ���\�b�h
  	( size() �E get() )�́A���ڌĂяo���Ă����܂��܂���B
  	
  	�T�D  this �́A�f�X�g���N�^�ł͂��ׂĂ̗v�f��j�����܂��B
  	
  	
  	@param ElementType1
  	  ���̃N���X�̃��\�b�h�Ŏ擾�E�ݒ肷��v�f�̌^���w�肵��
  	���������B
  	@param ElementType2
  	  ����ΏۃI�u�W�F�N�g m_pAdaptee ���i�[���Ă���v�f�̌^��
  	�w�肵�Ă��������B
  	
 */
template < class ElementType1 , class ElementType2 > class CaMuiFilter :
	public Mui< ElementType1 > 
{
public:
	/**
	  	ElementType2 �̕ʖ��ł��B
	  	m_pAdaptee �̗v�f�̌^�ł��B
	 */
	typedef ElementType2	adaptee_value_type ;

private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
	  	����ΏۃI�u�W�F�N�g�ƂȂ�A�R���e�i�ł��B
	  	���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
	  	���̃I�u�W�F�N�g�́Athis�Ƃ̊֘A���ۂ���Ă���Ԃ́A
	  	�������Ȃ��Ă͂Ȃ�܂���B
	  
	  	�܂��A���̃R���e�i�́A������Ԃł͋�łȂ��Ă͂Ȃ�܂���B
	  	���R�́A���̃N���X�̓f�X�g���N�^�ł��ׂĂ̗v�f��j�����邩��ł��B
	  
	  	<b>�����Ƃ��āA this �� ����ΏۃI�u�W�F�N�g m_pAdaptee ��
	  	�֘A���L���ȊԂ́A
	  	 m_pAdaptee �� "Mui<ElementType2>" ���\�b�h�𒼐�
	  	�Ăяo���Ȃ��ł��������B</b>
	  	  ���ɁA onErase() �ŗv�f�ɑ΂���㏈�����s���Ă���ꍇ�́A
	  	 this ���o�R������ m_pAdaptee �ɑ΂��ėv�f�̒ǉ��E�폜��
	  	�s���Ă��܂��ƁA�s���ȓ���ɂȂ�܂��B\n 
		m_pAdaptee �� "Mu<ElementType2>" ���\�b�h
	  	( size() �E get() )�́A���ڌĂяo���Ă����܂��܂���B
	 */
	Mui<ElementType2>*	m_pAdaptee ;
	///@}

protected:
	// --------------------------------
	///@name �I�[�o���C�h�\�ȉ��z�֐�
	// --------------------------------
	///@{
	/**
	  	  this �́A����Ώۂ̃R���e�i m_pAdaptee �ɑ΂��ėv�f��ǉ�
	  	����Ƃ��ɁA���̊֐����Ăяo���āA  ElementType1 �̒l value ���A
	  	 ElementType2 �ɕϊ����܂��B
	  
	  	onSet() �Ăяo���ƁA onErase() �Ăяo���͑΂ɂȂ��Ă��܂��B
	  	 onSet() �ł���l��Ԃ����ꍇ�A���̗v�f�� m_pAdaptee ����
	  	��菜�����Ƃ��ɁA�K�� onSet() �ŕԂ����l�������Ƃ���
	  	 onErase() ���Ăяo����܂��B
	  	
	  	@param value [in] (const ElementType1&)
	  	  �ϊ�����ׂ��l���w�肵�Ă��������B
	  	
	  	@param piResult [out]
	  	  ���̊֐��́A�l value �̕ϊ��ɐ��������Ƃ��͂��̒l�� 0 �ȏ�A
	  	���s�����Ƃ��͕��̐��ɂ��܂��B
	  	\n�֐��I����ɂ��̒l�����̐��ł���ꍇ�A this �͗v�f��
	  	�R���e�i�Ɋi�[���܂���B���̏ꍇ�Aset() �E insert() ��
	  	���s�ƂȂ�A *piResult �� set() �E insert() �̖߂�l�ƂȂ�܂��B
	  	
	  	@return (ElementType2)
	  	  value ��ϊ��������ʂ�Ԃ��܂��B�A���A�ϊ��Ɏ��s���A
	  	 *piResult �����̐��ł���ꍇ�́A���̖߂�l�ɂ͈Ӗ�������܂���B
	  
	  	
	  	<H4>
	  	�y�I�[�o���C�h�z
	  	</H4>
	  	  ElementType1 �̒l���A ElementType2 �ɕϊ����鏈��������
	  	���Ă��������B�ϊ����ʂ̒l�͖߂�l�Ƃ��Ă��������B
	  	
	  	  �ϊ��Ɏ��s�����ꍇ�́A *piResult �ɕ��̐���ݒ肵��
	  	���������B
	  	  *piResult �����̏ꍇ�A this �͗v�f���R���e�i�Ɋi�[
	  	���܂���B���̏ꍇ�Aset() �E insert() �͎��s�ƂȂ�A
	  	 *piResult �� set() �E insert() �̖߂�l�ƂȂ�܂��B
	  	  *piResult �����̏ꍇ�A���̊֐��̖߂�l�͕]������܂���̂ŁA
	  	���ł����܂��܂���B
	 */
	virtual adaptee_value_type onSet( const value_type& value , int* piResult ) = 0 ;
	
	/**
	  	  get() ���\�b�h�́A����Ώۂ̃R���e�i m_pAdaptee ����擾��������
	  	���̊֐����Ăяo���āA  ElementType2 �̒l value ���A
	  	 ElementType1 �ɕϊ����܂��B
	  	
	  	@param value [in] (const ElementType2&)
	  	  �ϊ�����ׂ��l���w�肵�Ă��������B
	  	
	  	@return (ElementType1)
	  	  value ��ϊ��������ʂ�Ԃ��܂��B
	  	
	  	<H4>
	  	�y�I�[�o���C�h�z
	  	</H4>
	  	  ElementType2 �̒l���A ElementType1 �ɕϊ����鏈��������
	  	���Ă��������B�ϊ����ʂ̒l�͖߂�l�Ƃ��Ă��������B
	 */
	virtual value_type onGet( const adaptee_value_type& value )const = 0 ;
	
	/**
	  	  this �́A����Ώۂ̃R���e�i m_pAdaptee ����v�f����菜�����O�ɁA
	  	���̊֐����Ăяo���܂��B
	  
	  
	  	onSet() �Ăяo���ƁA onErase() �Ăяo���͑΂ɂȂ��Ă��܂��B
	  	 onSet() �ł���l��Ԃ����ꍇ�A���̗v�f�� m_pAdaptee ����
	  	��菜�����Ƃ��ɁA�K�� onSet() �ŕԂ����l�������Ƃ���
	  	 onErase() ���Ăяo����܂��B
	  	
	  	@param value [in] (const ElementType2&)
	  	  ����Ώۂ̃R���e�i m_pAdaptee �����菜���v�f���w�肵�Ă��������B
	  
	  	<H4>
	  	�y�I�[�o���C�h�z
	  	</H4>
	  	  �����͂���܂���B
	  	  ����Ώۂ̃R���e�i m_pAdaptee �����菜���v�f�ɑ΂���
	  	�㏈�����K�v�ȏꍇ�́A���̃����o�֐����I�[�o���C�h���āA
	  	�㏈�����������Ă��������B
	 */
	virtual void onErase( const adaptee_value_type& value ){} ;
	///@}


public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	   @param pAdaptee [in]
	  	����ΏۃI�u�W�F�N�g�ƂȂ�A�R���e�i�ł��B
	  	���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
	  	���̃I�u�W�F�N�g�́Athis�Ƃ̊֘A���ۂ���Ă���Ԃ́A
	  	�������Ȃ��Ă͂Ȃ�܂���B
	 */
	CaMuiFilter( Mui<ElementType2>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ){};
private:
	///	�R�s�[�͋֎~
	CaMuiFilter( const CaMuiFilter& value )
	{
		assert( false ) ;
	}
	///	�R�s�[�͋֎~
	CaMuiFilter& operator=( const CaMuiFilter& value )
	{
		assert( false ) ;
		return *this ;
	}
public:
	/**
	   @attention
	  	�f�X�g���N�^�ł́A�R���e�i�̑S�Ă̗v�f��j�����܂��B
	 */
	virtual ~CaMuiFilter()
	{
		//	�f�X�g���N�^�ł́A�h���N���X�� onErase() ���Ăяo����܂���B
		//	���̂��߁A�����ŗv�f���폜���Ă��A�v�f�ɑ΂���
		//	onErase() �͌Ăяo���ꂸ�A�Ӗ��͂���܂���B
		//erase( 0 , INT_MAX ) ;
	};
	
public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	/**
	   @return
	   	�R���e�i�Ɋi�[����Ă���f�[�^�̌���Ԃ��܂��B
	 */
	virtual int	size()const{	return m_pAdaptee->size() ; } ;
	
	/**
	   	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���
	   	�v�f��Ԃ��܂��B
	   @param idx [in]
	   	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	   	�͈͂͂O�ȏ� size() �����ł��B
	  	INT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	   	�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
	  
	   <H4>
	   �y�I�[�o���C�h�z
	   </H4>
	  	m_pAdaptee ���̗v�f�� onGet() �ŕϊ��������̂�Ԃ��܂��B
	 */
	virtual ElementType1 get( int idx )const 
	{
		return onGet( m_pAdaptee->get( idx ) ) ;
	};
	///@}
public:
	// ********************************
	///@name	Mui
	// ********************************
	///@{
	
	/**
	   	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	   	�v�f���㏑�����܂��B
	   @param element [in]
	   	�v�f���w�肵�Ă��������B
	   @param iIndex [in]
	   	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	   	�͈͂͂O�ȏ� size() �����ł��B
	  	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	   	0�ȏ�͐����A���̐��̓G���[�ł�
	  	-	-1 ;	//	iIndex ���s���ł��B
	  
	   <H4>
	   �y�I�[�o���C�h�z
	   </H4>
	  	�P�D�V�����v�f�� onSet() �� ElementType2 �ɕϊ����܂��B
	  
	  	�Q�Dm_pAdaptee ���̊����̗v�f�������ɂ��� onErase() ��
	  	�Ăяo���Č㏈���������܂��B
	  
	  	�R�Dm_pAdaptee ���̗v�f���A�P�D�ŕϊ������l�ɒu�������܂��B
	 */
	virtual int set( const ElementType1& element , int iIndex ) 
	{
		// --------------------------------
		if ( iIndex == INT_MAX )
		{
			iIndex = m_pAdaptee->size() - 1 ;
		}
		if ( !( 0 <= iIndex && iIndex < m_pAdaptee->size() ) )
		{
			return -1 ;	//	iIndex ���s���ł��B
		}
		
		// --------------------------------
		int iRv = 0 ;

		ElementType2 elmOld = m_pAdaptee->get( iIndex ) ;
		onErase( elmOld ) ;

		ElementType2 elmNew = onSet( element , &iRv ) ;
		iRv = m_pAdaptee->set( elmNew , iIndex ) ;
		if ( iRv < 0 )
		{
			onErase( elmNew ) ;
		}
		return ( iRv ) ;
	};

	/**
	   	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	   	�v�f��ǉ����܂��B
	   @param element [in]
	   	�v�f���w�肵�Ă��������B
	   @param iIndex [in]
	   	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	   	�͈͂͂O�ȏ� size() �ȉ��ł��B
	   	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
	  	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	   	0�ȏ�͐����A���̐��̓G���[�ł�
	  
	   <H4>
	   �y�I�[�o���C�h�z
	   </H4>
	  	�v�f�� onSet() �� ElementType2 �ɕϊ����Ă���A
	  	m_pAdaptee �ɒǉ����܂��B
	 */
	virtual int insert( const ElementType1& element , int iIndex = INT_MAX ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = m_pAdaptee->size() ;
		}
		if ( !( 0 <= iIndex && iIndex <= m_pAdaptee->size() ) )
		{
			return -1 ;	//	iIndex ���s���ł��B
		}
		// --------------------------------
		int iRv = 0 ;
		ElementType2 elmNew = onSet( element , &iRv ) ;
		iRv = m_pAdaptee->insert( elmNew , iIndex ) ;
		if ( iRv < 0 )
		{
			onErase( elmNew ) ;
		}
		return ( iRv ) ;
		
	}
	
	/**
	   	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
	   	�v�f���폜���܂��B
	   @param iIndex [in]
	   	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	   	�͈͂͂O�ȏ� size() �����ł��B
	   	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	   @param iSize [in]
	   	�폜����v�f�̐����w�肵�Ă��������B
	   	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
	   @attention
	  	iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
	   @return
	   	0�ȏ�͐����A���̐��̓G���[�ł�
	  	-	-1 ;	//	iIndex ���s��
	  
	   <H4>
	   �y�I�[�o���C�h�z
	   </H4>
	  	�폜����v�f�������ɂ��āAonErase() ���Ăяo���Ă���A
	  	m_pAdaptee ����v�f���폜���܂��B
	 */
	virtual int erase( int iIndex , int iSize = 1 ) 
	{
		if ( m_pAdaptee == NULL )
		{
			return 0 ;
		}
		if ( iIndex == INT_MAX && iSize == INT_MAX )
		{
			return -1 ;	//	iIndex ���s��
		}
		if ( iIndex == INT_MAX )
		{
			iIndex = m_pAdaptee->size() - iSize ;
		}
		if ( iSize == INT_MAX )
		{
			iSize = m_pAdaptee->size() - iIndex ;
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= m_pAdaptee->size() ) )
		{
			return -1 ;	//	iIndex ���s���ł��B
		}
		// --------------------------------
		for ( int cnt = 0 ; cnt < iSize ; cnt ++ )
		{
			ElementType2 elmOld = m_pAdaptee->get( iIndex + iSize - 1 - cnt ) ;
			onErase( elmOld ) ;
		}
		return m_pAdaptee->erase( iIndex , iSize ) ;
	} ;
	
	
	///@}
public:
	// ********************************
	///@name CaMuiFilter-�֘A
	// ********************************
	///@{
	Mui<ElementType2>*	getAdaptee(){	return m_pAdaptee ;};
	const Mui<ElementType2>*	getAdaptee()const{	return m_pAdaptee ;};
	/**
	  	���̃��\�b�h�� m_pAdaptee ��u���������ꍇ�A this �� 
	  	erase( 0 , INT_MAX ) 
	 	�ŁA�R���e�i���ێ����Ă����v�f��j�����܂��B
	 */
	CaMuiFilter<ElementType1,ElementType2>& setAdaptee( 
			Mui<ElementType2>*	value )
	{
		erase( 0 , INT_MAX ) ;
		m_pAdaptee = value ;
		return *this ;
	};
	///@}
	

};

#ifndef NO_NSMU
} //namespace NsMu
#endif//NO_NSMU

} //namespace OuLib



#endif /*CaContFiler_h*/
