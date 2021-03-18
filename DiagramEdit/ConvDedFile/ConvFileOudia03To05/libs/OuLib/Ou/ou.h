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
//	Ou.h
// ****************************************************************
*/
/** @file */
#ifndef  Ou_h
#define  Ou_h
#include "Ou\OuBase.h"
#include "Ou\OuHolder.h"

// ****************************************************************
//	Ou< TargetType >
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 * 	  TargetType �^�̃I�u�W�F�N�g���Q�Ƃ���
 *	�X�}�[�g�|�C���^�ł��B
 *
 *
 *	<H4>
 * �y Ou ���f���z
 *	</H4>
 * 	  "Ou< TargetType >" �́ATargetType �^�̃I�u�W�F�N�g���Q�Ƃ���A
 * 	�X�}�[�g�|�C���^�ł��B
 *
 * 	  "Ou< TargetType >" ���w���Ă��� TargetType �^�̃I�u�W�F�N�g�̂��Ƃ��A
 * 	�w�iOu �́j�^�[�Q�b�g�I�u�W�F�N�g�x�ƌď̂��܂��B
 *	  Ou �́A�w�^�[�Q�b�g�I�u�W�F�N�g�x�̎Q�Ƃ��I������Ƃ��ɁA
 *	�����I�Ɂw�^�[�Q�b�g�I�u�W�F�N�g�x�̌�n���i�폜�j
 *	���s���d�g�݂������Ă��܂��B
 *
 *	 �u�w�^�[�Q�b�g�I�u�W�F�N�g�x�̎Q�Ƃ��I������Ƃ��v�́A��̓I�ɂ�
 *
 *	-	Ou���g���j�������Ƃ��i�f�X�g���N�^�j
 *	-	Ou�ɁA���́w�^�[�Q�b�g�I�u�W�F�N�g�x�ւ̎Q��(Ou)���J�n����Ƃ��i����j
 *	-	Ou.clear() ���Ăяo�����Ƃ��B
 *	
 *	�Ƃ������ꍇ���w���܂��B
 *
 *	  �w�^�[�Q�b�g�I�u�W�F�N�g�x���A������ Ou ����Q�Ƃ����ꍇ������܂��B
 *	  Ou �ł͂��̏ꍇ�A�w�^�[�Q�b�g�I�u�W�F�N�g�x���Q�Ƃ��Ă��� Ou ��
 *	�����J�E���g���A���ꂪ 0 �ɂȂ����Ƃ��ɁA�w�^�[�Q�b�g�I�u�W�F�N�g�x��
 *	��n���i�폜�j���s���܂��B
 *	\n���̊Ǘ��������Ȃ����߁AOu�ł́w�^�[�Q�b�g�I�u�W�F�N�g�x�P�ɂ��P��
 *	�w�z���_�[�I�u�W�F�N�g( "OuHolder< TargetType >" ) �x�𐶐��E�Ǘ����܂��B
 *
 *	�w�z���_�[�I�u�W�F�N�g�x�́A
 *
 *	- �w�^�[�Q�b�g�I�u�W�F�N�g�x�ւ̃|�C���^
 *	- �w�^�[�Q�b�g�I�u�W�F�N�g�x���Q�Ƃ��Ă��� Ou �̐��i�Q�ƃJ�E���^)
 *
 *	��ێ����Ă��܂��B�w�z���_�[�I�u�W�F�N�g�x�́A�Q�ƃJ�E���^���O�ɂȂ���
 *	�Ƃ��ɁA�������g�i�w�z���_�[�I�u�W�F�N�g�x�j�Ɓw�^�[�Q�b�g�I�u�W�F�N�g�x
 *	���폜���܂��B
 * 
 * 	  Ou �́A�^�[�Q�b�g�I�u�W�F�N�g�̌�n���̕��@���ɁA�h���N���X�������Ă�
 * 	�܂��B�W���̔h���N���X�Ƃ��Ă�
 * 
 * 	- 1.  new �Ő������ꂽ�I�u�W�F�N�g��ێ����� "OuNew< TargetType >"
 *	 (�^�[�Q�b�g�I�u�W�F�N�g�� delete �ō폜����)
 * 	- 2.  �ÓI�Ȏ��������I�u�W�F�N�g��ێ����� "OuStatic< TargetType >"
 *	�i�^�[�Q�b�g�I�u�W�F�N�g�̍폜�͍s��Ȃ��j
 * 
 * 	������܂����A����ȊO�̔j�����@�����N���X��Ǝ��ɍ쐬���邱�Ƃ��\
 * 	�ł��B
 * 
 * <H4>
 * �y�g�����z
 * </H4>
 * 
 * �P�D  �V�����^�[�Q�b�g�I�u�W�F�N�g�� Ou �ŊǗ�����ꍇ�́A���̃^�[�Q�b�g
 * 	�I�u�W�F�N�g�̔j�����@���Ƃɒ�`���ꂽ�h���N���X�̃I�u�W�F�N�g�𐶐����A
 * 	���̈����Ƃ��ă^�[�Q�b�g�I�u�W�F�N�g���w�肵�Ă��������B
 * 
 * �Q�D  ������ Ou �I�u�W�F�N�g�i�܂��́AOu�̔h���N���X�̃I�u�W�F�N�g�j��
 * 	�Q�Ƃ��Ă���^�[�Q�b�g�I�u�W�F�N�g���Q�Ƃ���A�V���� Ou �𐶐�����ꍇ
 * 	�́AOu �I�u�W�F�N�g�𐶐����A����ɑ΂��ăR�s�[�R���X�g���N�^�E������Z�q
 * 	���g���Ă��������B
 */
template< class TargetType1 > 
class Ou : public OuBase
{
// ********************************
//	�N���X����`
// ********************************
 public:
	typedef OuBase	super ;
	typedef TargetType1 TargetType ;


// ********************************
///@name �֘A
// ********************************
///@{
 private:
	/**
	 * 	�^�[�Q�b�g�I�u�W�F�N�g�ւ̃|�C���^�ł��B
	 * 	�R���X�g���N�^�E������Z�q�Ō��肵�܂��B
	 */
	TargetType*		m_pTarget ;

///@}
// ********************************
//	�R���X�g���N�^�E�f�X�g���N�^
// ********************************
 public:
	/**
	 * 	  �f�t�H���g�R���X�g���N�^�ł��B
	 * 	  �^�[�Q�b�g�I�u�W�F�N�g��NULL�ƂȂ�܂��B
	 */
	Ou() : 
		m_pTarget( NULL ) 
	{
	};
	/**
	 * 	  �V�����^�[�Q�b�g�I�u�W�F�N�g���Q�Ƃ�����Ƃ��̃R���X�g���N�^�ł��B
	 * 	  new �Ő������� OuHolder�I�u�W�F�N�g��o�^���܂��B
	 * @param pHolder [in]
	 * 	�V�����^�[�Q�b�g�I�u�W�F�N�g��ێ����Ă���A OuHolder �I�u�W�F�N�g
	 * 	���w�肵�Ă��������B
	 */
	template< class TargetTypeSrc >
	Ou( OuHolder<TargetTypeSrc>* pHolder ) 
		: super( pHolder ) 
	{
		m_pTarget = static_cast<TargetType*>( pHolder->getTarget() ) ;
	};
	
	
	/**
	 * 	�ϊ��R���X�g���N�^
	 * 	������ Ou �I�u�W�F�N�g�i�܂��́AOu�̔h���N���X�̃I�u�W�F�N�g�j��
	 * 	�Q�Ƃ��Ă���^�[�Q�b�g�I�u�W�F�N�g���Q�Ƃ��܂��B
	 * @param ev [in]
	 * 	������ Ou  �I�u�W�F�N�g���w�肵�Ă��������B
	 */
	template< class TargetTypeSrc >
	Ou( Ou<TargetTypeSrc>& ev )
		: super( ev ) 
	{
		m_pTarget = static_cast<TargetType*>( ev.getTarget() ) ;
	};
	
	/**
	 * 	������Z�q�ł��B
	 * 	������ Ou �I�u�W�F�N�g�i�܂��́AOu�̔h���N���X�̃I�u�W�F�N�g�j��
	 * 	�Q�Ƃ��Ă���^�[�Q�b�g�I�u�W�F�N�g���Q�Ƃ��܂��B
	 * 	���̂Ƃ��A����܂ł��� Ou �I�u�W�F�N�g���Q�Ƃ��Ă����^�[�Q�b�g
	 * 	�I�u�W�F�N�g�ɑ΂��ẮA�Q�ƃJ�E���^�����炵�A�K�v�Ȃ�폜���s���܂��B
	 * @param ev [in]
	 * 	������ Ou  �I�u�W�F�N�g���w�肵�Ă��������B
	 */
	template< class TargetTypeSrc >
	Ou& operator=( Ou<TargetTypeSrc>& ev ) 
	{
		super::operator=( ev ) ;
		m_pTarget = static_cast<TargetType*>( ev.getTarget() ) ;
		
		return ( *this ) ;
	};


	/**
	 * 	�R�s�[�R���X�g���N�^
	 * 	������ Ou �I�u�W�F�N�g�i�܂��́AOu�̔h���N���X�̃I�u�W�F�N�g�j��
	 * 	�Q�Ƃ��Ă���^�[�Q�b�g�I�u�W�F�N�g���Q�Ƃ��܂��B
	 * @param ev [in]
	 * 	������ Ou  �I�u�W�F�N�g���w�肵�Ă��������B
	 */
	Ou( const Ou& ev )
		: super( ev ) 
	{
		m_pTarget = ev.m_pTarget   ;
	};
	
	/**
	 * 	������Z�q�ł��B
	 * 	������ Ou �I�u�W�F�N�g�i�܂��́AOu�̔h���N���X�̃I�u�W�F�N�g�j��
	 * 	�Q�Ƃ��Ă���^�[�Q�b�g�I�u�W�F�N�g���Q�Ƃ��܂��B
	 * 	���̂Ƃ��A����܂ł��� Ou �I�u�W�F�N�g���Q�Ƃ��Ă����^�[�Q�b�g
	 * 	�I�u�W�F�N�g�ɑ΂��ẮA�Q�ƃJ�E���^�����炵�A�K�v�Ȃ�폜���s���܂��B
	 * @param ev [in]
	 * 	������ Ou  �I�u�W�F�N�g���w�肵�Ă��������B
	 */
	Ou& operator=( const Ou& ev ) 
	{
		super::operator=( ev ) ;
		m_pTarget = ev.m_pTarget ;
		
		return ( *this ) ;
	};

	//	�f�X�g���N�^
	virtual ~Ou()
	{
	};

// ********************************
//	"Ou< TargetType >"
// ********************************
 public:
	// ********************************
	///@name "Ou< TargetType >"-�֘A
	// ********************************
	///@{
	TargetType* getTarget(){	return ( m_pTarget ) ; 	} ;
	const TargetType* getTarget()const{	return ( m_pTarget ) ; 	} ;
	///@}
	// ********************************
	///@name "Ou< TargetType >"-���Z�q
	// ********************************
	///@{

	/**
	 * 	  �^�[�Q�b�g�I�u�W�F�N�g�ւ̃L���X�g���Z�q�ł��B
	 * 	  ����ɂ��AOu�I�u�W�F�N�g�𕁒ʂ̃|�C���^�̑����
	 * 	�֐��̈����Ƃ��ēn�����Ƃ��ł��܂��B
	 */
	operator  TargetType*(){	return ( getTarget() ) ; } ;
	operator  const TargetType*()const{	return ( getTarget() ) ; } ;
	
	/**
	 * 	  "->"���Z�q
	 * 	�^�[�Q�b�g�I�u�W�F�N�g�̃|�C���^��Ԃ��܂��B
	 * 	  ����ɂ��AOu�I�u�W�F�N�g�� "->" �����āA�^�[�Q�b�g�I�u�W�F�N�g��
	 * 	�����o�ɃA�N�Z�X�ł��܂��B
	 */
	TargetType* operator->(){	return ( getTarget() ) ; } ;
	const TargetType* operator->()const{	return ( getTarget() ) ; } ;
	
	/**
	 * 	  "*"���Z�q
	 * 	  ����ɂ��A Ou �I�u�W�F�N�g�� "*" �����āA�^�[�Q�b�g�I�u�W�F�N�g
	 * 	�̎��̂�\�����Ƃ��ł��܂��B
	 */
	TargetType& operator*(){	return ( *getTarget() ) ; } ;
	const TargetType& operator*()const{	return ( *getTarget() ) ; } ;
	
	/**
	 * 	  ��r���Z�q
	 * 	  �^�[�Q�b�g�I�u�W�F�N�g�̃|�C���^�ƁA�ʏ�̃|�C���^�̔�r��
	 * 	�s���܂��B
	 * 	  ��r�Ώۂɂ� NULL ���w�肷�邱�Ƃ��ł��܂��B
	 * @param ev [in]
	 * 	��r�Ώۂ̃|�C���^���w�肵�Ă��������B
	 * @return
	 * 	- (operator==)�ΏۂƂȂ�I�u�W�F�N�g�̃|�C���^�������ł���ΐ^�ł�
	 * 	- (operator!=)�ΏۂƂȂ�I�u�W�F�N�g�̃|�C���^���قȂ�ΐ^�ł�
	 */
	bool operator==( TargetType* ev )const
	{
		return ( m_pTarget == ev ) ;
	};	
	/**
	 *	@see operator==( TargetType* ev ) ���Q�Ƃ��Ă��������B
	 */
	bool operator!=( TargetType* ev )const
	{
		return ( m_pTarget != ev ) ;
	};	

	/**
	 * 	  ��r���Z�q
	 * 	  this �ƁA�w���Ou�I�u�W�F�N�g�Ƃ̊ԂŁA�^�[�Q�b�g�I�u�W�F�N�g��
	 * 	�|�C���^�̔�r���s���܂��B
	 * @param ev [in]
	 * 	��r�Ώۂ� Ou �I�u�W�F�N�g���w�肵�Ă��������B
	 * @return
	 * 	- (operator==)�ΏۂƂȂ�I�u�W�F�N�g�̃|�C���^�������ł���ΐ^�ł�
	 * 	- (operator!=)�ΏۂƂȂ�I�u�W�F�N�g�̃|�C���^���قȂ�ΐ^�ł�
	 */
	template< class TargetTypeSrc >
	bool operator==( Ou<TargetTypeSrc>& ev )const
	{
		return ( m_pTarget == ev.getTarget() ) ;
	};	
	/**
	 *	@see operator!=() ���Q�Ƃ��Ă��������B
	 */
	template< class TargetTypeSrc >
	bool operator!=( Ou<TargetTypeSrc>& ev )const
	{
		return ( m_pTarget != ev.getTarget() ) ;
	};	

	///@}
	// ********************************
	///@name "Ou< TargetType >"-����
	// ********************************
	///@{
	/**
	 * @return
	 *	�^�[�Q�b�g�I�u�W�F�N�g��NULL�Ȃ�A�^��Ԃ��܂��B
	 */
	virtual bool isNull() const
	{
		return ( m_pTarget == NULL ) ;
	};

	/**
	 * 	���� Ou �I�u�W�F�N�g��
	 * 	�^�[�Q�b�g�I�u�W�F�N�g�ɑ΂���Q�Ƃ𒆎~���A
	 * 	������Ԃɖ߂��܂��B
	 */
	virtual void clear() 
	{
		super::clear() ;
		m_pTarget = NULL ;
	};
	///@}

};




#endif /*Ou_h*/
