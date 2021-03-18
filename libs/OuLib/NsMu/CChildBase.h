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
//$Id: CChildBase.h 380 2016-11-16 21:21:09Z okm $
#ifndef  OuLib_NsMu_CChildBase_h
#define  OuLib_NsMu_CChildBase_h
#include <stddef.h>
#include "CParentBase.h"

namespace OuLib{
namespace NsMu{


/**
@brief
  ���̃N���X�́A�w�e�q�R���e�i�x�p�^�[�� �ɂ�����q�I�u�W�F�N�g�̊�{�N���X�ł��B

@ref parent_child_container

 �w�e�q�R���e�i�x�p�^�[���ɂ�����q�I�u�W�F�N�g�̃N���X�́A���̃N���X���p������K�v������܂��B
 �w�e�q�R���e�i�x�p�^�[�����T�|�[�g���Ă���R���e�i�N���X�Ƃ��āACMuiCopiedParent�ACMuiOuParent ������܂����A�����̃e���v���[�g�p�����[�^ ElementType �Ɏw�肷��N���X�́ACParentBase �N���X���p�����Ă��Ȃ��Ă͂Ȃ�܂���B

�@ m_pParent �́A�����l��NULL�ł��B
�@this�� �e�I�u�W�F�N�g�ɒǉ����ꂽ�Ƃ��A�e�I�u�W�F�N�g�́A CChildBase::setParent() ���\�b�h���Ăяo���āA�e�I�u�W�F�N�g�̃A�h���X���q�I�u�W�F�N�g��  CChildBase::m_pParent �ɓo�^���܂��B

�@ CChildBase::m_pParent �̌^�́A�́A CParentBase* �ł��B�q�I�u�W�F�N�g�́A CChildBase::m_pParent ���A���ۂ̐e�I�u�W�F�N�g(�R���e�i)�̌^�Ƀ_�E���L���X�g���邱�Ƃɂ��A�e�I�u�W�F�N�g�̃��\�b�h���Ăяo�����Ƃ��ł��܂��B

@note
�@ m_pParent ��CMuiCopiedParentBase �^�ł͂Ȃ��A���ۂ̐e�I�u�W�F�N�g�̌^�ɂ���΁A�q�I�u�W�F�N�g�ł̓_�E���L���X�g�����Ȃ��Ă悭�Ȃ�܂��B����́ACChildBase���N���X�e���v���[�g�Ƃ��A�e���v���[�g�p�����[�^�Őe�I�u�W�F�N�g�̌^���w�肷�邱�Ƃɂ������ł������ɂ��v���܂��B@n
�@�������A�ڂ����l����ƁA���̐݌v�ɂ͖���������܂��B����́A�ȉ��̂悤�ȏz�ˑ��ɂȂ邽�߂ł��B
 - �q�I�u�W�F�N�g�́ACChildBase�Ɉˑ�����( ElementType �́ACChildBase���p������)
 - �e�I�u�W�F�N�g�́A�q�I�u�W�F�N�g�Ɉˑ�����( �e�I�u�W�F�N�g(�R���e�i)�́A�q�I�u�W�F�N�g�̌^���e���v���[�g�����ŗv������)
 - CChildBase�́A�e�I�u�W�F�N�g�Ɉˑ�����(CChaildBase�́A�e�I�u�W�F�N�g�̌^���e���v���[�g�����ŗv������)

*/
class CChildBase
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		�e�I�u�W�F�N�g(�R���e�i)�ւ̊֘A�ł��B
		�����l��NULL�ł��B

		this�� �e�I�u�W�F�N�g�ɒǉ����ꂽ�Ƃ��A�e�I�u�W�F�N�g�́A
		CChildBase::setParent() ���\�b�h���Ăяo���āA
		�e�I�u�W�F�N�g�̃A�h���X��o�^���܂��B

		this ���R���e�i����폜���ꂽ�Ƃ��ɂ́A
		�e�I�u�W�F�N�g�́ANULL��o�^���܂��B
	*/
	CParentBase* m_pParent ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/** �f�t�H���g�R���X�g���N�^�Bm_pParent ��NULL�ɏ��������܂� */
	CChildBase() : m_pParent( NULL ){}

	/**
		�R�s�[�R���X�g���N�^�ł́A m_pParent �̓R�s�[���܂���B
		�R���e�i���̎q�A�C�e���̃R�s�[�𐶐������ꍇ�A�R�s�[��
		�R���e�i���̎q�A�C�e���ł͂Ȃ�����ł��B
	*/
	CChildBase( const CChildBase& value ) : m_pParent( NULL ){}

	/**
		������Z�q�ł́A m_pParent �̓R�s�[���܂���B

		�e�I�u�W�F�N�g�����q�I�u�W�F�N�g�ɑ΂��đ�����Z�q��
		�g�p�����ꍇ�A�q�I�u�W�F�N�g�̒ʏ�̑����͏㏑������܂����A
		���̏ꍇ�ł��A�u�q�I�u�W�F�N�g�ł���v�Ƃ���������
		�ς��Ȃ����߂ł��B

		�t�ɁA�e�I�u�W�F�N�g�����q�I�u�W�F�N�g�������Z�q��
		���ӂɒu���āA�e�������Ȃ��I�u�W�F�N�g�ɑ������R�s�[
		�����ꍇ�ł��A�E�ӂ̃I�u�W�F�N�g�͐e�������Ȃ��܂܂ł��B
	*/
	CChildBase& operator=( const CChildBase& value )
	{
		return *this ;
	}

public:
	// ********************************
	///@name CParentBase-����
	// ********************************
	///@{
	/** @see m_pParent */
	virtual void setParent( CParentBase* pParent )
	{
		m_pParent = pParent ;
	}
	/** @see m_pParent */
	virtual CParentBase* getParent()const
	{
		 return m_pParent ;
	}
	///@}
};


} //namespace NsMu
} //namespace OuLib
#endif //OuLib_NsMu_CChildBase_h
