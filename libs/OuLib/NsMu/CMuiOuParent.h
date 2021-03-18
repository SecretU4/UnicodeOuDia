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
//$Id: CMuiOuParent.h 348 2016-08-16 17:47:55Z okm $
#ifndef  OuLib_NsMu_CMuiOuParent
#define  OuLib_NsMu_CMuiOuParent

#include "CMuiOu.h"
#include "CParentBase.h"

namespace OuLib{
namespace NsMu{


/**
@brief
�@ElementType �^�̃I�u�W�F�N�g���w�� Ou(�Q�ƃJ�E���^���g�p�����X�}�[�g�|�C���^)��ێ�����R���e�i�ł��B�w�e�q�R���e�i�x�p�^�[���̐e�I�u�W�F�N�g�Ƃ��ċ@�\���܂��B

@ref parent_child_container

�@�q�I�u�W�F�N�g(�R���e�i���̃A�C�e��)����A�e�I�u�W�F�N�g(���g��ێ����Ă���R���e�i)�ɃA�N�Z�X���邱�Ƃ��ł��܂��B

�@���̃N���X�e���v���[�g�́ACMuiOu ����{�N���X�Ƃ��Ă��܂��B

�@�q�I�u�W�F�N�g���e�I�u�W�F�N�g(this)�ɒǉ����ꂽ�Ƃ��A�e�I�u�W�F�N�g�́A�q�I�u�W�F�N�g�� CChildBase::setParent() ���\�b�h���Ăяo���āA�e�I�u�W�F�N�g(this)�̃A�h���X���q�I�u�W�F�N�g�ɓo�^���܂��B���̂Ƃ��n�����e�I�u�W�F�N�g�̌^�́ACParentBase* �ł��B
�@�q�I�u�W�F�N�g�́ACChildBase::getParent() �ŁA�e�I�u�W�F�N�g�̃A�h���X���擾�ł��܂��BCChildBase::getParent() ���Ԃ����� CParentBase* �ł��B�q�I�u�W�F�N�g�́A���̃A�h���X���A���ۂ̐e�I�u�W�F�N�g(�R���e�i)�̌^�Ƀ_�E���L���X�g���邱�Ƃɂ��A�e�I�u�W�F�N�g�̃��\�b�h���Ăяo�����Ƃ��ł��܂��B


@param ElementType
  �i�[����I�u�W�F�N�g�̌^���w�肵�Ă��������B
�@ElementType�́ACChildBase ���p�������^�łȂ��Ă͂Ȃ�܂���B
�@���̃p�����[�^�[�ɂ́AOu�͊܂߂Ȃ��ł��������B
@param ContType
  Ou< ElementType > ��ێ�����STL�R���e�i���w�肵�Ă��������B
  ����ł́Astd::deque �ł����A std::vector ���g�����Ƃ��ł��܂��B
*/
template <
	class ElementType,
	class ContType =std::deque< Ou< ElementType > > >
class CMuiOuParent 
	: public CMuiOu< ElementType , ContType >
 	, public CParentBase

{
public:
	// ********************************
	// �R���X�g���N�^
	// ********************************
	/** �f�t�H���g�R���X�g���N�^ */
	CMuiOuParent(){} ; 

	/** 
		�R�s�[�R���X�g���N�^�B
		value ���� Ou ���w���Ă���I�u�W�F�N�g���A���g�̎q�A�C�e����
		���܂��B
		�S�Ă̎q�A�C�e���ɑ΂��āAsetParent( this ) �����s���܂��B
	*/
	CMuiOuParent( const CMuiOuParent<ElementType,ContType>& value ) 
		: CMuiOu( value ) 
	{
		//	�S�Ă̗v�f�ɑ΂��āAsetParent()���s��
		for ( int idx = 0 ; idx < size() ; idx ++ )
		{
			get( idx )->setParent( this ) ;
		}

		
	}


	/** 
		������Z�q�B
		value ���� Ou ���w���Ă���I�u�W�F�N�g���A���g�̎q�A�C�e����
		���܂��B
		�S�Ă̎q�A�C�e���ɑ΂��āAsetParent( this ) �����s���܂��B
	*/
	CMuiOuParent& operator=( const CMuiOuParent<ElementType,ContType>& value ) 
	{
		CMuiOu::operator=( value ) ; 
		
		//	�S�Ă̗v�f�ɑ΂��āAsetParent()���s��
		for ( int idx = 0 ; idx < size() ; idx ++ )
		{
			get( idx )->setParent( this ) ;
		}

		return *this ;
	};


	/** 
		�f�X�g���N�^
		value ���� Ou ���w���Ă���I�u�W�F�N�g�Ƃ̐e�q�֌W��
		�������܂��B
		�S�Ă̎q�A�C�e���ɑ΂��āAsetParent( NULL ) �����s���܂��B
	*/
	virtual ~CMuiOuParent()
	{
		//	�S�Ă̗v�f�ɑ΂��āAsetParent()���s��
		for ( int idx = 0 ; idx < size() ; idx ++ )
		{
			get( idx )->setParent( NULL ) ;
		}

	} ; 
public:
	// ********************************
	///@name Mui 
	// ********************************
	///@{
	/**
		�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA �v�f�̃R�s�[��ǉ����܂��B
		Ou�̎w���I�u�W�F�N�g���q�A�C�e���Ƃ��܂��B
		�q�A�C�e���ɑ΂��āAsetParent( this ) �����s���܂��B
	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		0 ����n�܂�C���f�N�X���w�肵�Ă��������B 
		�͈͂͂O�ȏ� size() �ȉ��ł��B �O�́A�擪�Esize()�Ȃ疖���ւ�
		�ǉ��ɂȂ�܂��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@return
		0�ȏ�͐����A���̐��̓G���[�ł� 
	*/
	virtual int insert( const Ou<ElementType>& element ,  int iIndex=INT_MAX) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = size() ;
		}
		int iRv = CMuiOu< ElementType , ContType >::insert( element , iIndex ) ;
		get( iIndex )->setParent( this ) ;  
		return iRv ;
	}
	/**
		�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�� �v�f���폜���܂��B 
		�폜���� Ou ���w���Ă���I�u�W�F�N�g�Ƃ̐e�q�֌W��
		�������܂��B
		�폜����q�A�C�e���ɑ΂��āAsetParent( NULL ) �����s���܂��B
	@param iIndex
		�O����n�܂�C���f�N�X���w�肵�Ă��������B �͈͂͂O�ȏ� size() 
		�����ł��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@param iSize
		�폜����v�f�̐����w�肵�Ă��������B �A���AINT_MAX �́A 
		iIndex ���疖���܂ł�\���܂��B 
	@attention
		iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B 
	@return
		0�ȏ�͐����A���̐��̓G���[�ł� 
	*/
	virtual int erase( int iIndex , int  iSize = 1  ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = size() - 1 ;
		}
		if ( iSize == INT_MAX )
		{
			iSize = size() - iIndex ; 
		}
		for ( int i = 0 ; i < iSize ; i ++ )
		{
			get( iIndex + i )->setParent( NULL ) ; 
		}
		return CMuiOu< ElementType , ContType >::erase( iIndex , iSize ) ;
	}
	/**
		�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA �v�f���㏑�����܂��B 
		�㏑������� Ou ���w���Ă���I�u�W�F�N�g�Ƃ̐e�q�֌W��
		�������܂��B
		�V����Ou�̎w���I�u�W�F�N�g���q�A�C�e���Ƃ��܂��B
		�q�A�C�e���ɑ΂��āAsetParent( this ) �����s���܂��B
	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		 �O����n�܂�C���f�N�X���w�肵�Ă��������B 
		 �͈͂͂O�ȏ� size() �����ł��B 
		 �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@return
		0�ȏ�͐����A���̐��̓G���[�ł� 
	*/
	virtual int set( const Ou<ElementType>& element , int iIndex ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = size() - 1 ;
		}
		get( iIndex )->setParent( NULL ) ;  
		int iRv = CMuiOu< ElementType , ContType >::set( element , iIndex ) ;
		get( iIndex )->setParent( this ) ; 
		return iRv ;
	}

};

} //namespace NsMu
} //namespace OuLib



#endif //OuLib_NsMu_CMuiOuParent

