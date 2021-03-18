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
//$Id: CMuiCopiedParent.h 369 2016-08-20 13:40:07Z okm $
#ifndef  OuLib_NsMu_CMuiCopiedParent_h
#define  OuLib_NsMu_CMuiCopiedParent_h

#include "CMuiCopied.h"
#include "CParentBase.h"
#include "CChildBase.h"

#include <limits.h>
#include <deque>

namespace OuLib{
namespace NsMu{



/**
@brief
�@ElementType�N���X�̃I�u�W�F�N�g��ێ�����R���e�i�ł��B�w�e�q�R���e�i�x�p�^�[���̐e�I�u�W�F�N�g�Ƃ��ċ@�\���܂��B

@ref parent_child_container

�@�q�I�u�W�F�N�g(�R���e�i���̃A�C�e��)����A�e�I�u�W�F�N�g(���g��ێ����Ă���R���e�i)�ɃA�N�Z�X���邱�Ƃ��ł��܂��B

�@���̃N���X�e���v���[�g�́ACMuiCopied ����{�N���X�Ƃ��Ă��܂��B

�@�q�I�u�W�F�N�g���e�I�u�W�F�N�g(this)�ɒǉ����ꂽ�Ƃ��A�e�I�u�W�F�N�g�́A�q�I�u�W�F�N�g�� CChildBase::setParent() ���\�b�h���Ăяo���āA�e�I�u�W�F�N�g(this)�̃A�h���X���q�I�u�W�F�N�g�ɓo�^���܂��B���̂Ƃ��n�����e�I�u�W�F�N�g�̌^�́ACParentBase* �ł��B
�@�q�I�u�W�F�N�g�́ACChildBase::getParent() �ŁA�e�I�u�W�F�N�g�̃A�h���X���擾�ł��܂��BCChildBase::getParent() ���Ԃ����� CParentBase* �ł��B�q�I�u�W�F�N�g�́A���̃A�h���X���A���ۂ̐e�I�u�W�F�N�g(�R���e�i)�̌^�Ƀ_�E���L���X�g���邱�Ƃɂ��A�e�I�u�W�F�N�g�̃��\�b�h���Ăяo�����Ƃ��ł��܂��B

�@
@param ElementType
  �i�[����I�u�W�F�N�g�̌^���w�肵�Ă��������B
�@ElementType�́ACChildBase ���p�������^�łȂ��Ă͂Ȃ�܂���B
@param ContType
  ElementType* ��ێ�����STL�R���e�i���w�肵�Ă��������B
  ����ł́Astd::deque �ł����A std::vector ���g�����Ƃ��ł��܂��B
*/
template <
	class ElementType,
	class ContType =std::deque< ElementType* > >
class CMuiCopiedParent 
	: public CMuiCopied< ElementType , ContType > 
	, public CParentBase
{
public:
	// ********************************
	// �R���X�g���N�^
	// ********************************
	/** �f�t�H���g�R���X�g���N�^ */
	CMuiCopiedParent(){} ; 
	
	/** 
		�R�s�[�R���X�g���N�^�B
		value �Ɋi�[����Ă���I�u�W�F�N�g�̃R�s�[���A���g�̎q�A�C�e����
		���܂��B
		�S�Ă̎q�A�C�e���ɑ΂��āAsetParent( this ) �����s���܂��B
	*/
	CMuiCopiedParent( const CMuiCopiedParent<ElementType,ContType>& value )
		: CMuiCopied( value ) 
	{
		//	�S�Ă̗v�f�ɑ΂��āAsetParent()���s��
		for ( int idx = 0 ; idx < value.size() ; idx ++ )
		{
			getMuPtr()->get( idx )->setParent( this ) ;
		}
	};

	/** 
		������Z�q�B
		value �Ɋi�[����Ă���I�u�W�F�N�g�̃R�s�[���A���g�̎q�A�C�e����
		���܂��B
		�S�Ă̎q�A�C�e���ɑ΂��āAsetParent( this ) �����s���܂��B
	*/
	CMuiCopiedParent& operator=( 
		const CMuiCopiedParent<ElementType,ContType>& value ) 
	{
		CMuiCopied::operator=( value ) ; 
		
		//	�S�Ă̗v�f�ɑ΂��āAsetParent()���s��
		for ( int idx = 0 ; idx < value.size() ; idx ++ )
		{
			getMuPtr()->get( idx )->setParent( this ) ;
		}

		return *this ;
	};
	// ********************************
	///@name Mu
	// ********************************

	///@{

	/**
		�R���e�i���̎q�A�C�e���̃R�s�[���擾���܂��B
		���̊֐����Ԃ��R�s�[�́Athis �̎q�A�C�e���ł͂���܂���B
		�R�s�[�� CChildItem::m_pParent ��NULL�ł��B
	@param iIndex
		0 ����n�܂�C���f�N�X���w�肵�Ă��������B �͈͂� 0 �ȏ� size() 
		�����ł��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	*/
	virtual ElementType  get (int iIndex) const
	{
		ElementType value 
			= CMuiCopied< ElementType , ContType >::get( iIndex ) ;
		value.setParent( NULL ) ; 
		return value ;
	}
	///@}
	// ********************************
	///@name Mui
	// ********************************
	///@{

	/**
		�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA �v�f�̃R�s�[��
		�ǉ����܂��B 
		�ǉ����ꂽ�R�s�[�� CChildItem::m_pParent �ɂ́Athis ��o�^���܂��B
	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		0 ����n�܂�C���f�N�X���w�肵�Ă��������B 
		�͈͂͂O�ȏ� size() �ȉ��ł��B �O�́A�擪�Esize()�Ȃ疖���ւ�
		�ǉ��ɂȂ�܂��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	*/
	virtual int insert( const ElementType& element ,  int iIndex=INT_MAX) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = size() ;
		}
		CMuiCopied< ElementType , ContType >::insert( element , iIndex ) ;
		getMuPtr()->get( iIndex )->setParent( this ) ;  

		return 0 ; 
	}
	/**
		�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA �v�f���㏑�����܂��B 
		�㏑����̗v�f�� CChildItem::m_pParent �ɂ́Athis ��o�^���܂��B
	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		�O����n�܂�C���f�N�X���w�肵�Ă��������B �͈͂͂O�ȏ� size() 
		�����ł��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	*/
	virtual int set( const ElementType& element , int iIndex ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = size() - 1 ;
		}
		CMuiCopied< ElementType , ContType >::set( 
			element , iIndex ) ;
		getMuPtr()->get( iIndex )->setParent( this ) ;  
		return 0 ; 
	}
	///@}
};


} //namespace NsMu
} //namespace OuLib
#endif //OuLib_NsMu_CMuiCopiedParent_h
