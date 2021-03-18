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
//	OuBase.h
// ****************************************************************
*/
/** @file */
#ifndef  OuBase_h
#define  OuBase_h
#include <stdlib.h>

#include "Ou\OuHolderBase.h"

// ****************************************************************
//	OuBase
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 * 	  Ou���f���ɂ�����A Ou �̊�{�N���X�ł��B
 *
 *	  ���̃N���X�́A�w�z���_�[�I�u�W�F�N�g�x�ɑ΂���J�E���g�́{�E�|��
 *	�Ӗ��Ƃ��܂��B
 */
class OuBase
{
// ********************************
///@name �֘A
// ********************************
///@{
 private:
	/**
	 * 	�w�z���_�[�I�u�W�F�N�g�x�ł��B
	 *
	 * 	�R���X�g���N�^�E�܂��͑�����Z�q�Ō��肵�A
	 * 	���̃I�u�W�F�N�g���z���_�[�I�u�W�F�N�g���g�p�J�n�����Ƃ���
	 * 	AddRef() �ŁA this ��o�^���܂��B
	 *
	 * 	���̃I�u�W�F�N�g���z���_�[�I�u�W�F�N�g�̎Q�Ƃ�
	 * 	���~�����Ƃ��ɂ� Release() ���Ăяo���āA
	 * 	this ��o�^�������܂��B
	 */
	OuHolderBase*	m_pHolder ;

// ********************************
//	�R���X�g���N�^�E�f�X�g���N�^
// ********************************
 public:
	/**
	 *	�f�t�H���g�R���X�g���N�^�ł��B
	 *	�w�z���_�[�I�u�W�F�N�g�x�͖��o�^�ƂȂ�܂��B
	 */
	OuBase() : 
		m_pHolder( NULL ) 
	{
	};
	/**
	 * 	  �V�����I�u�W�F�N�g�𐶐������Ƃ��̃R���X�g���N�^�ł��B
	 * 	  new �Ő������� OuHolder�I�u�W�F�N�g��o�^���܂��B
	 */
	OuBase( OuHolderBase* pHolder ) : 
		m_pHolder( pHolder ) 
	{
		if ( m_pHolder != NULL ){
			m_pHolder->AddRef( this ) ;
		}
	};
	
	OuBase( const OuBase& ev )
	{
		m_pHolder = ev.m_pHolder ;
		if ( m_pHolder != NULL ){
			m_pHolder->AddRef( this ) ;
		}
	};
	
	OuBase& operator=( const OuBase& ev ) 
	{
		if ( m_pHolder != NULL ){
			m_pHolder->Release( this ) ;
		}
		m_pHolder = ev.m_pHolder ;
		if ( m_pHolder != NULL ){
			m_pHolder->AddRef( this ) ;
		}
		
		return ( *this ) ;
	};


	virtual ~OuBase()
	{
		if ( m_pHolder != NULL ){
			m_pHolder->Release( this ) ;
		}
	};
// ********************************
//	OuBase
// ********************************
 public:
	// ********************************
	///@name OuBase-�֘A
	// ********************************
	///@{

	OuHolderBase* getHolder(){	return m_pHolder ; 	} ;

	///@}
	// ********************************
	///@name OuBase-����
	// ********************************
	///@{
	
	/**
	 * @return
	 * 	�^�[�Q�b�g�I�u�W�F�N�g���Q�Ƃ��Ă���OuBase�iOu<>���܂ށj
	 * 	�̐���Ԃ��܂��B
	 */
	virtual int RefCount() 
	{
		if ( m_pHolder != NULL ){
			return ( m_pHolder->RefCount() ) ;
		}
		return ( 0 ) ;
	};
	

	/**
	 * 	���� Ou �I�u�W�F�N�g��
	 * 	�^�[�Q�b�g�I�u�W�F�N�g�ɑ΂���Q�Ƃ𒆎~���A
	 * 	������Ԃɖ߂��܂��B
	 */
	virtual void clear() 
	{
		if ( m_pHolder != NULL ){
			m_pHolder->Release( this ) ;
		}
		m_pHolder = NULL ;
	};
	///@}
};

#endif /*OuBase_h*/



