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
//$Id: CParentBase.h 348 2016-08-16 17:47:55Z okm $

#ifndef  OuLib_NsMu_CParentBase_h
#define  OuLib_NsMu_CParentBase_h

namespace OuLib{
namespace NsMu{


/** @page parent_child_container �w�e�q�R���e�i�x�p�^�[�� 

�@�w�e�q�R���e�i�x�p�^�[���́A�݌v�p�^�[���̈�ł��B
�@�I�u�W�F�N�g���e�q�֌W�����w�I�u�W�F�N�g�c���[�\���x�ɂ����āA�q�I�u�W�F�N�g����e�I�u�W�F�N�g(�q�I�u�W�F�N�g��ێ�����R���e�i)�ւ̃A�N�Z�X��i��񋟂��܂��B

�@�����ł́w�I�u�W�F�N�g�c���[�\���x�́A�����̃I�u�W�F�N�g����܊֌W���\�����ăh���C����\�����郂�f���̂��Ƃ��w���܂��B
�@���̂悤�ȃI�u�W�F�N�g�c���[�\���ɂ́ADOM(Document Object Model)�AWindows�̃E�C���h�E�n���h���A�c���[�R���g���[���̃A�C�e���Ȃǂ�����܂��B�����̃I�u�W�F�N�g�c���[�\���ł́A�q�I�u�W�F�N�g����e�I�u�W�F�N�g�փA�N�Z�X�����i�����ʂɒ񋟂���Ă��܂��B

�@�w�e�q�R���e�i�x�p�^�[���́A���́A�u�q�I�u�W�F�N�g����e�I�u�W�F�N�g�փA�N�Z�X�����i�v���������邽�߂̐݌v�p�^�[���ł��B

�@NsMu�ł́A�ȉ��̃N���X��p���āA�w�e�q�R���e�i�x�p�^�[�����������܂��B

  - CMuiCopiedParent , CMuiOuParent : �e�I�u�W�F�N�g�̋�ۃN���X�e���v���[�g
  - CParentBase : �e�I�u�W�F�N�g�̊�{�N���X
  - CChildBase  : �q�I�u�W�F�N�g�̊�{�N���X

*/



/**
@brief
  ���̃N���X�́A�w�e�q�R���e�i�x�p�^�[�� �ɂ�����e�I�u�W�F�N�g(�R���e�i)�̊�{�N���X�ł��B

@ref parent_child_container

�@�w�e�q�R���e�i�x�p�^�[�����T�|�[�g���Ă���R���e�i�N���X�Ƃ��āACMuiCopiedParent�ACMuiOuParent ������܂��B�����̃N���X�́A���̃N���X���p�����Ă��܂��B�w�e�q�R���e�i�x�p�^�[���̐e�I�u�W�F�N�g�Ƃ��ċ@�\����R���e�i�N���X���ɂ�����e�I�u�W�F�N�g(�R���e�i)�́A���̃N���X���p������K�v������܂��B

�@C++�̃R���e�i�́A�ʏ�̓N���X�e���v���[�g�Ŏ�������܂��BCMuiCopiedParent�ACMuiOuParent ���A�N���X�e���v���[�g�ł��B����ɑ΂��A���̃N���X�́A�e���v���[�g�p�����[�^�������܂���B�R���e�i�̃e���v���[�g�p�����[�^�Ɉˑ����Ȃ���{�N���X�Ƃ��ċ@�\���܂��B
  ���̃N���X�ɂ́A���������������܂���B

  �q�I�u�W�F�N�g���e�I�u�W�F�N�g�ɒǉ����ꂽ�Ƃ��A�e�I�u�W�F�N�g�́A�q�I�u�W�F�N�g�� CChildBase::setParent() ���\�b�h���Ăяo���āA�e�I�u�W�F�N�g�̃A�h���X���q�I�u�W�F�N�g�ɓo�^���܂��B���̂Ƃ��n�����e�I�u�W�F�N�g�̌^�́ACParentBase* �ł��B�q�I�u�W�F�N�g�́ACParentBase* ���A���ۂ̐e�I�u�W�F�N�g(�R���e�i)�̌^�Ƀ_�E���L���X�g���邱�Ƃɂ��A�e�I�u�W�F�N�g�̃��\�b�h���Ăяo�����Ƃ��ł��܂��B
*/
class CParentBase
{
protected:
	virtual ~CParentBase(){};
};



} //namespace NsMu
} //namespace OuLib
#endif //OuLib_NsMu_CParentBase_h
