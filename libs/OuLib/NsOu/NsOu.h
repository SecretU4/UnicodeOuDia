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
//$Id: NsOu.h 351 2016-08-16 19:55:36Z okm $
/**
 @file 
 @brief
	���O��Ԃ̊֐��Q�E�N���X�Q�̂��ׂĂ��C���N���[�h���܂��B
*/



namespace OuLib{

#ifndef NO_NSOU
/**
@brief
Ou �Ɋ֘A����N���X�������閼�O��Ԃł��B
Ou �́A�I�u�W�F�N�g�̎����Ǘ����s���X�}�[�g�|�C���^�ł��B

@ref page_oumodel

*/
namespace NsOu{
}


/** @page page_oumodel Ou���f�� 
 Ou< TargetType > �́ATargetType �^�̃I�u�W�F�N�g���Q�Ƃ���A
�X�}�[�g�|�C���^�ł��B

  Ou< TargetType > ���w���Ă��� TargetType �^�̃I�u�W�F�N�g�̂��Ƃ��A
�w�iOu �́j�^�[�Q�b�g�I�u�W�F�N�g�x�ƌď̂��܂��B
  Ou �́A�w�^�[�Q�b�g�I�u�W�F�N�g�x�̎Q�Ƃ��I������Ƃ��ɁA
�����I�Ɂw�^�[�Q�b�g�I�u�W�F�N�g�x�̌�n���i�폜�j
���s���d�g�݂������Ă��܂��B

 �u�w�^�[�Q�b�g�I�u�W�F�N�g�x�̎Q�Ƃ��I������Ƃ��v�́A��̓I�ɂ�

 -	Ou���g���j�������Ƃ��i�f�X�g���N�^�j
 -	Ou�ɁA���́w�^�[�Q�b�g�I�u�W�F�N�g�x�ւ̎Q��(Ou)���J�n����Ƃ��i����j
 -	Ou.clear() ���Ăяo�����Ƃ��B

�Ƃ������ꍇ���w���܂��B

  �w�^�[�Q�b�g�I�u�W�F�N�g�x���A������ Ou ����Q�Ƃ����ꍇ������܂��B
  Ou �ł͂��̏ꍇ�A�w�^�[�Q�b�g�I�u�W�F�N�g�x���Q�Ƃ��Ă��� Ou ��
�����J�E���g���A���ꂪ 0 �ɂȂ����Ƃ��ɁA�w�^�[�Q�b�g�I�u�W�F�N�g�x��
��n���i�폜�j���s���܂��B 

  ���̊Ǘ��������Ȃ����߁AOu�ł́w�^�[�Q�b�g�I�u�W�F�N�g�x�P�ɂ��P��
�w�z���_�[�I�u�W�F�N�g( OuHolder< TargetType > ) �x�𐶐��E�Ǘ����܂��B

�w�z���_�[�I�u�W�F�N�g�x�́A

 - �w�^�[�Q�b�g�I�u�W�F�N�g�x�ւ̃|�C���^
 - �w�^�[�Q�b�g�I�u�W�F�N�g�x���Q�Ƃ��Ă��� Ou �̐��i�Q�ƃJ�E���^)

��ێ����Ă��܂��B�w�z���_�[�I�u�W�F�N�g�x�́A�Q�ƃJ�E���^���O�ɂȂ���
�Ƃ��ɁA�������g�i�w�z���_�[�I�u�W�F�N�g�x�j�Ɓw�^�[�Q�b�g�I�u�W�F�N�g�x
���폜���܂��B

  Ou �́A�^�[�Q�b�g�I�u�W�F�N�g�̌�n���̕��@���ɁA�h���N���X�������Ă�
�܂��B�W���̔h���N���X�Ƃ��Ă�

 - 1.  new �Ő������ꂽ�I�u�W�F�N�g��ێ�����  OuNew 
 (�^�[�Q�b�g�I�u�W�F�N�g�� delete �ō폜����)
 - 2.  �ÓI�Ȏ��������I�u�W�F�N�g��ێ����� OuStatic 
�i�^�[�Q�b�g�I�u�W�F�N�g�̍폜�͍s��Ȃ��j

������܂����A����ȊO�̔j�����@�����N���X��Ǝ��ɍ쐬���邱�Ƃ��\
�ł��B

<H4>
�g����
</H4>
  new �ŃI�u�W�F�N�g�𐶐�����Ƃ��ɂ́Anew�Ő��������I�u�W�F�N�g�̃A�h���X���A OuNew �̃R���X�g���N�^�ɓn���Ă��������B
  ����Ȍ�́AOuNew �X�}�[�g�|�C���^�� -> ���Z�q���g���āA�I�u�W�F�N�g�̃����o�[�ɃA�N�Z�X���邱�Ƃ��o���܂��B

@code
	OuNew<CBase>	pBase( new CBase ) ;
	pBase->AgeSet( 30 ) ;
@endcode

  �I�u�W�F�N�g�ւ̐V���ȎQ�Ƃ𐶐�����ꍇ�́A Ou �𐶐����A Ou �ɃX�}�[�g�|�C���^�������Ă��������B

@code
	Ou<CBase>	pBase2 = pBase ;
@endcode


  �֐��̈������g���āA�I�u�W�F�N�g�ւ̃X�}�[�g�|�C���^���֐��ɓn�������ꍇ�́A
 Ou �������ɂ��Ă��������B

@code
void func( Ou<CBase> arg )
{
	arg->AgeSet( 31 ) ;
}
@endcode

  �֐��̖߂�l���g���āA�I�u�W�F�N�g�̃X�}�[�g�|�C���^��n�������ꍇ�́A Ou ��߂�l�ɂ��Ă��������B

@code
Ou< CBase > BaseCreateFunc()
{
	OuNew< CBase >	pBase( new CBase() ) ;
	return ( pBase ) ;
}

	Ou<CBase> pBase = BaseCreateFunc() ;

@endcode


*/

#endif //NO_NSOU


} //namespace OuLib


#include "NsOu\dynamic_castOu.h"
#include "NsOu\Ou.h"
#include "NsOu\OuBase.h"
#include "NsOu\OuHolder.h"
#include "NsOu\OuHolderBase.h"
#include "NsOu\OuNew.h"
#include "NsOu\OuStatic.h"

