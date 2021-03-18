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
//	CRfEditCmd.h
// ****************************************************************
*/
/** @file */
#ifndef  CRfEditCmd_h
#define  CRfEditCmd_h

#include "NsOu/Ou.h"
#include "DedRosenFileData\CDedRosenFileData.h"

namespace DedRosenFileData{
namespace EditCmd{
	using namespace OuLib::NsOu;

// ****************************************************************
//	CRfEditCmd
// ****************************************************************
/**
  @brief
  CDedRosenFileData �I�u�W�F�N�g�ɑ΂���ҏW�R�}���h�̒��ۊ�{�N���X�ł��B

  �������z�֐��Ƃ��āA �ȉ��̂Q������܂��B

 - execute (  CDedRosenFileData �I�u�W�F�N�g�ɑ΂���ҏW�R�}���h�̎��s )

 - createUndoCmd ( execute() �Ŏ��s�����ҏW������������āA  CDedRosenFileData �̏�Ԃ� execute() �����s���钼�O�ɖ߂����߂́A�R�}���h�I�u�W�F�N�g�𐶐�)



�@���̃N���X�͒��ۃN���X�ł��B CDedRosenFileData �ɑ΂���ҏW�����
���e���ɁA�h���N���X�����݂��܂��B
�@�h���N���X�ł́A���ۂ̕ҏW����̓��e�𑮐��ɕێ����܂��B
�i��F CRfEditCmd_Ressya �́A��Ԃɑ΂���ҏW�����
�\���܂��B���̃N���X�̓����o�ϐ��Ƃ��āA�ҏW���s����Ԃ̃C���f�N�X�ƁA
�ҏW��̗�Ԃ�ێ����� CentDedRessya �I�u�W�F�N�g��ێ����܂��j�B

<H4>
�y�g�����z
</H4>

�P�D�@�ҏW�R�}���h�̎�ނɉ������h���N���X�̃I�u�W�F�N�g�𐶐����Ă��������B

�Q�D�@�I�u�W�F�N�g�̑����ɁA�ҏW����̓��e���w�肵�Ă��������B

�R�D�@CDedRosenFileData �I�u�W�F�N�g�������ɓn���� execute() ���\�b�h��
�Ăяo���ƁA this �͈����Ŏw�肳�ꂽ CDedRosenFileData �I�u�W�F�N�g��
�΂��āA�����Ŏw�肳��Ă���ҏW������s���܂��B
�@�܂��A�ҏW����ɐ��������ꍇ�A this �́Aundo�i�ҏW����̎������j��
�s���̂ɕK�v�ȃf�[�^�������o�ϐ��ɕێ����܂��B

�S�D�@execute() ���Ăяo��������� createUndoCmd() ���Ăяo���ƁA
�u this->execute() �ōs�����ҏW����������� �i this->execute() ��
�ҏW������s��������� CDedRosenFileData �I�u�W�F�N�g���A
 this->execute() ���s�����O�̏�Ԃɂ���j�v
���߂̕ҏW�R�}���h�I�u�W�F�N�g�iCRfEditCmd�j�𐶐�
���邱�Ƃ��ł��܂��B@n
�@���̃����o�֐����Ԃ����I�u�W�F�N�g�� execute() ���\�b�h���Ăяo�����Ƃɂ��A
this->execute() ����̏�Ԃ� CentDedRosen �I�u�W�F�N�g���A this->execute() 
���O�̏�Ԃɖ߂����Ƃ��ł��܂��B

�i��j�@
�@ CRfEditCmd_Ressya �ŁA�C���f�N�X 0 �̗�Ԃ��폜����悤�ȓ���̃I�u�W�F�N�g�𐶐����Aexecute() �����s�����Ƃ��܂��B
�@���̎��� CRfEditCmd_Ressya �ɑ΂��� createUndoCmd() ���Ăяo���ƁA�����o�֐��́A�C���f�N�X 0 �ɐ�قǍ폜������Ԃ�ǉ�����悤�ȓ���̃R�}���h�I�u�W�F�N�g�𐶐����܂��B
*/
class CRfEditCmd
{
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CRfEditCmd(){};
	virtual ~CRfEditCmd(){};

public:
	// ********************************
	///@name	CRfEditCmd-����
	// ********************************
	///@{
	/**
	 	CDedRosenFileData �I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���܂��B
	 	�@�܂��A�ҏW����ɐ��������ꍇ�A this �́Aundo
	 	�i�ҏW����̎������j���s���̂ɕK�v�ȃf�[�^���A
	 	�����o�ϐ��ɕێ����܂��B
	  @param pCDedRosenFileData [in,out]
	 	���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���܂��B
	  @return
	 	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 	<H4>
	 	�y�I�[�o���C�h�z
	 	</H4>
	 	pCDedRosenFileData �I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���Ă��������B
	 */
	virtual int execute( CDedRosenFileData* pCDedRosenFileData ) = 0 ;
	
	/**
	 	�u this->execute() �ōs�����ҏW�����������
	 	�i this->execute() �ŕҏW������s��������� CDedRosenFileData 
	 	�I�u�W�F�N�g���A this->execute() ���s�����O�̏�Ԃ�
	 	����j�v���߂̕ҏW�R�}���h�I�u�W�F�N�g�𐶐����܂��B
	 
	 	���̃����o�֐����Ԃ����I�u�W�F�N�g���g���� execute() ��
	 	�Ăяo�����Ƃɂ��A this->execute() ����̏�Ԃ� CentDedRosen
	 	 �I�u�W�F�N�g���A this->execute() ���O�̏�Ԃɖ߂����Ƃ��ł��܂��B
	  @return
	 	execute() �ōs�����ҏW������������A
	 	 CDedRosenFileData �I�u�W�F�N�g�� execute() ���s�����O�̏�Ԃ�
	 	���邽�߂̃R�}���h�I�u�W�F�N�g�𐶐����܂��B@n
	 	 �I�u�W�F�N�g�𐶐��ł��Ȃ��ꍇ�́ANULL ��Ԃ��܂��B
	 	<H4>
	 �y�I�[�o���C�h�z
	 	</H4>
	 	execute() �Ŏ��s�����ҏW���e�����ɖ߂��悤�ȃI�u�W�F�N�g��
	 	�������ĕԂ��Ă��������B
	 */
	virtual Ou<CRfEditCmd> createUndoCmd() = 0 ;
	
	///@}
};

} } //namespace EditCmd namespace DedRosenFileData

#endif /*CRfEditCmd_h*/

