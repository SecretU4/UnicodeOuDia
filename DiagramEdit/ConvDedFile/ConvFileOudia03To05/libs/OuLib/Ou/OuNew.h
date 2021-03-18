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
//	OuNew.h
// ****************************************************************
*/
/** @file */
#ifndef  OuNew_h
#define  OuNew_h
#include "Ou\Ou.h"
#include "Ou\OuHolder.h"

// ****************************************************************
//	OuHolderNew< TargetType1 >
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 * 	  new �� ���������^�[�Q�b�g�I�u�W�F�N�g��ێ�����z���_�[�I�u�W�F�N�g
 * 	�ł��B
 *
 * 	  ���̃N���X�𒼐ڎg�p���邱�Ƃ͂���܂���BOuNew �N���X�̓�����
 * 	�g���܂��B
 */
template< class TargetType1 > 
class OuHolderNew : public OuHolder< TargetType1 >
{
// ********************************
//	�N���X����`
// ********************************
 public:
	typedef OuHolder<TargetType1> super ;


// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * 	  �^�[�Q�b�g�I�u�W�F�N�g�̃|�C���^��
	 * 	�n���ď��������܂��B
	 */
	OuHolderNew( TargetType* p ) : super( p ) 
	{
	};
	
	/**
	 *	  �^�[�Q�b�g�I�u�W�F�N�g�̌�n�����s���܂��B
	 */
	virtual ~OuHolderNew() 
	{
		delete getTarget() ;
	};
	

};



// ****************************************************************
//	OuNew< ClassType >
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 * 	  new �Ő��������^�[�Q�b�g�I�u�W�F�N�g���Q�Ƃ��� Ou �I�u�W�F�N�g��
 * 	�������܂��B
 */
template< class TargetType1 > 
class OuNew : public Ou< TargetType1 >
{
// ********************************
//	�N���X����`
// ********************************
 public:
	typedef Ou<TargetType1>	super ;
	
// ********************************
//	�R���X�g���N�^�E�f�X�g���N�^
// ********************************
 public:
	/**
	 * [in]ev
	 * 	  �V�����^�[�Q�b�g�I�u�W�F�N�g���w�肵�Ă��������B
	 * 	  ���̃I�u�W�F�N�g�́Anew �Ő����������̂łȂ��Ă͂Ȃ�܂���B
	 */
	OuNew( TargetType* ev ) 
		: super( new OuHolderNew<TargetType>( ev ) ) 
	{
	};
// --------------------------------
//	�R�s�[�֎~
// --------------------------------
 private:
	OuNew( const OuNew& ev ){};
	OuNew& operator=( const OuNew& ev ){};
};


#endif /*OuNew_h*/
