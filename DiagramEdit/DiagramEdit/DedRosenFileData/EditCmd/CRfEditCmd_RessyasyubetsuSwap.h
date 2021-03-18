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
//	CRfEditCmd_RessyasyubetsuSwap.h
//	$Id: CRfEditCmd_RessyasyubetsuSwap.h 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
*/
#ifndef  CRfEditCmd_RessyasyubetsuSwap_h
#define  CRfEditCmd_RessyasyubetsuSwap_h
/** @file */
#include "..\..\entDed\CentDedRessyasyubetsuCont.h"
#include "..\..\entDed\CentDedRosen.h"
#include "DedRosenFileData\EditCmd\CRfEditCmd.h"

namespace DedRosenFileData{ namespace EditCmd{

// ****************************************************************
//	CRfEditCmd_RessyasyubetsuSwap
// ****************************************************************
/**
  @brief
 	  CDedRosenFileData �I�u�W�F�N�g���� �Q�̗�Ԏ��Index�����ւ���
 	����ł��B
 	
 	�Q�́w��Ԏ�ʁx��Index�����ւ��܂��B
 
 	�w��̗�Ԏ��Index�������ׂĂ̗�Ԃ�Index���A
 	����ւ��܂��B
 */
class CRfEditCmd_RessyasyubetsuSwap : 
	public CRfEditCmd
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 	����ւ���Q�́w��Ԏ��Index�x�B
	 	�R���X�g���N�^�Ō��܂�܂��B
	 	INT_MAX �́A�����̗�Ԏ�ʂ��w�肵�����̂Ƃ݂Ȃ��܂��B
	 	m_iRessyasyubetsuIndexA �� m_iRessyasyubetsuIndexB �́A
	 	�قȂ�l�łȂ��Ă͂Ȃ�܂���B
	 */
	int m_iRessyasyubetsuIndexA ;
	int m_iRessyasyubetsuIndexB ;

	///@}
private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	  @param iRessyasyubetsuIndexA , iRessyasyubetsuIndexB [in]
	 	�w��Ԏ��Index�x���w�肵�Ă��������B
	 	�͈͂́A 0 �ȏ� ��Ԏ�ʂ̐������ł��B
	 	INT_MAX �́A�����̗�Ԏ�ʂ��w�肵�����̂Ƃ݂Ȃ��܂��B
	 	iRessyasyubetsuIndexA �� iRessyasyubetsuIndexB �́A
	 	�قȂ�l�łȂ��Ă͂Ȃ�܂���B
	 */
	CRfEditCmd_RessyasyubetsuSwap( 
		int iRessyasyubetsuIndexA ,
		int iRessyasyubetsuIndexB ) ;
	virtual ~CRfEditCmd_RessyasyubetsuSwap() ; 
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
	 	-	-1 ;	//	��Ԏ��Index���s���ł��B
	 
	 	<H4>
	 	�y�I�[�o���C�h�z
	 	</H4>
	 	pCDedRosenFileData �I�u�W�F�N�g�ɑ΂��āA�ҏW��������s���Ă��������B
	 */
	virtual int execute( CDedRosenFileData* pCDedRosenFileData ) ;
	
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
	 	���邽�߂̃R�}���h�I�u�W�F�N�g�𐶐����܂��B
	 	<H4>
	 	�y�I�[�o���C�h�z
	 	</H4>
	 	execute() �Ŏ��s�����ҏW���e�����ɖ߂��悤�ȃI�u�W�F�N�g��
	 	�������ĕԂ��Ă��������B
	 */
	virtual Ou<CRfEditCmd> createUndoCmd()  ;
	
	///@}

public:
	// ********************************
	///@name CRfEditCmd_RessyasyubetsuSwap-����
	// ********************************
	///@{
	int getRessyasyubetsuIndexA()const{	return m_iRessyasyubetsuIndexA ;};
	int getRessyasyubetsuIndexB()const{	return m_iRessyasyubetsuIndexB ;};
	///@}
};


} } // namespace EditCmd namespace DedRosenFileData

#endif /*CRfEditCmd_RessyasyubetsuSwap_h*/
