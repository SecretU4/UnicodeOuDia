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
//$Id: NsMu.h 355 2016-08-18 16:41:28Z okm $
/**
 @file 
 @brief
	���O��Ԃ̊֐��Q�E�N���X�Q�̂��ׂĂ��C���N���[�h���܂��B
*/


namespace OuLib{

#ifndef NO_NSMU
/**
@brief
  NsMu �́A�z��`���̃R���e�i(�R���N�V����)�̃N���X�Q�������閼�O��Ԃł��B

  ���̖��O��Ԃ̒��S�ɂȂ� Mu (Multi object) �́A�z��`���̃R���e�i�ւ̒��ۃC���^�[�t�F�[�X�ł��B�v�f�𕡐��ێ����Ă���R���e�i�ɁA�����C���f�N�X�ŗv�f�ɃA�N�Z�X����@�\��񋟂��܂��B
  
  NsMu �́A���� Mu �C���^�[�t�F�[�X���T�|�[�g����R���e�i�N���X�Q���W�񂷂閼�O��Ԃł��B

  ���̖��O��Ԃ̃N���X�́A��肷���̌X�������邽�߁A�p�r�ɓK�����N���X��������ɂ����Ȃ��Ă��܂��B
  �N���X�I���̃K�C�h���C���́A�ȉ��̒ʂ�ł��B����́A���p���т��画���������ʂł��B
  
<H4>
�T�C�Y�̏�����(�R�s�[�ɃR�X�g�̂�����Ȃ�)�f�[�^���i�[����ꍇ
</H4>

�@�ʏ��STL�̃R���e�i�B�܂��́A CMup_deque,CMup_vector �B

<H4>
�T�C�Y�̑傫���N���X���i�[����ꍇ
</H4>
  CMuiCopied �B

<H4>
�N���X�I�u�W�F�N�g���i�[���A�I�u�W�F�N�g�̃��\�b�h�𒼐ڌĂяo�������ꍇ�B�A���A��{�N���X���i�[����R���e�i�ɔh���N���X�̃I�u�W�F�N�g���i�[���邱�Ƃ͂Ȃ��B
</H4>
  CMuiCopied �B�e�q�R���e�i�p�^�[�����g�p����ꍇ�� CMuiCopiedParent �B
  
@ref parent_child_container
  
<H4>
��{�N���X���i�[����R���e�i�ɔh���N���X�̃I�u�W�F�N�g���i�[���A���ԓ�����s���ꍇ
</H4>
  CMuiOu �B �e�q�R���e�i�p�^�[�����g�p����ꍇ�� CMuiOuParent �B
  
*/
namespace NsMu{
}
#endif//NO_NSMU


} //namespace OuLib


#include "NsMu\CaMuCast.h"
#include "NsMu\CaMui.h"
#include "NsMu\CaMuiFilter.h"
#include "NsMu\CaMup.h"
#include "NsMu\CaMuPtref.h"
#include "NsMu\CaMuiSelect.h"
#include "NsMu\CaMup_list.h"
#include "NsMu\CaMup_vector.h"
#include "NsMu\CChildBase.h"
#include "NsMu\CConvTable.h"
#include "NsMu\CMuiCopied.h"
#include "NsMu\CMuiCopiedParent.h"
#include "NsMu\CMuiOu.h"
#include "NsMu\CMuiOuParent.h"
#include "NsMu\CMup_deque.h"
#include "NsMu\CMup_list.h"
#include "NsMu\CMup_vector.h"
#include "NsMu\CParentBase.h"
#include "NsMu\Mu.h"
#include "NsMu\Mui.h"
#include "NsMu\Mup.h"

