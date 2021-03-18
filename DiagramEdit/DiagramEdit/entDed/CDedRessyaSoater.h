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
//	CDedRessyaSoater.h
// $Id: CDedRessyaSoater.h 141 2012-10-20 08:03:25Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CDedRessyaSoater_h
#define  CDedRessyaSoater_h
#include "entDed\CentDedRosen.h"
#include "IfProgress.h"

namespace entDed{

// ****************************************************************
//	CDedRessyaSoater
// ****************************************************************
/**
@brief
�y�T�v�z
	CentDedRessyaDia ���̗�Ԃ̃\�[�g�������s���N���X�B
	
	���̃N���X�͒��ۃN���X�ł��B
	�h���N���X�ŃI�[�o���C�h���s���A�\�[�g�A���S���Y������������K�v������܂��B
	
�y�I�[�o���C�h�z

	1.  sortRessyaIndex() �̃I�[�o���C�h���s���Ă��������B
	�@���̊֐��ł́A��ԃC���f�N�X��ێ�����R���e�i�̃\�[�g���s���Ă��������B
	�@(��ԃC���f�N�X�R���e�i�Ɋi�[���ꂽ�\�[�g���ʂɏ]����
	 ��� CentDedRessya �̃\�[�g���s���̂́A sortRessyaIndex() �̌Ăяo�����ł��� sort() ��
	 �Ӗ��ł��B)
	 (��ԃI�u�W�F�N�g CentDedRessya �ł͂Ȃ��A��ԃC���f�N�X int ���\�[�g����
	 �d�l�ɂȂ��Ă���̂́A�p�t�H�[�}���X����̂��߂ł��BCentDedRessya �̃R�s�[�ɂ�
	 ���Ԃ������邽�߂ł��B)
	
�y�g�����z
	
	1.  �R���X�g���N�^�ŃI�u�W�F�N�g�𐶐����Ă��������B
	
	2.�@sort() ���\�b�h���Ăяo���ƁAthis�́A�w�肳�ꂽ��ԃR���e�i�̂��ׂĂ̗�Ԃ��\�[�g���܂��B
*/
class CDedRessyaSoater
{
protected:
	// --------------------------------
	///@name sort �̉����֐�(template�p�^�[��)
	// --------------------------------
	///@{
	/**
		�\�[�g���s�����Index��ێ������R���e�i�ɁA
		�A�Ԃ̗��Index���i�[���܂��B
	@param iRessyaIndex [in]
		�擪�̗��Index���w�肵�Ă��������B
	@param iRessyaCount [in]
		��Ԃ̐����w�肵�Ă��������B
	@param muRessyaIndexOrder [out]
		���̊֐��͂��̃R���e�i�ɁA
		iRessyaIndex �` iRessyaIndex + iRessyaCount - 1 ��
		������A�ԂŊi�[���܂��B
		���̃R���e�i������܂ŕێ����Ă����f�[�^�͔j������܂��B

	*/
	static void makeRessyaIndex( 
		int iRessyaIndex , int iRessyaCount , 
		Mui<int>* muRessyaIndexOrder ) ;


	/**
		�w�肳�ꂽ���Index���\�[�g���܂��B
	@param pRessyaCont [in]
		�\�[�g�Ώۂ̗�Ԃ�ێ�������Ԃ̃R���e�i���w�肵�Ă��������B
	@param muRessyaIndexOrder [in,out]
		�\�[�g���s�����Index��ێ������R���e�i���w�肵�Ă��������B
		(��F���Index0�`4���\�[�g�������ꍇ�́A
		{0,1,2,3,4} ��5�̗v�f�����R���e�i���w�肵�Ă��������B
		���̊֐��͂��̔z����A�w����Order���̑������Index���Ƀ\�[�g���܂��B
	@param pIfProgress [in]
		�i����Ԃ̒ʒm���󂯂����ꍇ�́A�i����Ԓʒm���󂯎��
		�C���X�^���X�ւ̃|�C���^���w�肵�Ă��������B
		NULL�Ȃ�A���̊֐��͐i����Ԃ̒ʒm���s���܂���B
	@note 
		���̊֐��œ����\�[�g���ʂ�
		sortRessyaByRessyaIndexOrder() �ɓn�����Ƃɂ��A
		��ԃR���e�i���\�[�g���邱�Ƃ��ł��܂��B

	�y�I�[�o���C�h�z
	�@�h���N���X�ł́A���̊֐����I�[�o���C�h���āA
	 ��ԃC���f�N�X��ێ�����R���e�i�̃\�[�g���s���Ă��������B
	�@(��ԃC���f�N�X�R���e�i�Ɋi�[���ꂽ�\�[�g���ʂɏ]����
	 ��� CentDedRessya �̃\�[�g���s���̂́A sortRessyaIndex() �̌Ăяo�����ł��� sort() ��
	 �Ӗ��ł��B)
	*/
	virtual void sortRessyaIndex( 
		const CentDedRessyaCont* pRessyaCont , 
		Mui<int>* muRessyaIndexOrder , 
		IfProgress* pIfProgress ) = 0 ;


	/**
		��� index (int)��ێ������R���e�i�ɏ]���āA
		��ԃR���e�i�̗�Ԃ̕��я����A
		����ւ��܂��B
	@param muRessyaIndexOrder [in]
		���Index��ێ������R���e�i���w�肵�Ă��������B
	@param pRessyaCont [in,out]
		���בւ��̑ΏۂƂȂ��ԃR���e�i���w�肵�Ă��������B
		���̊֐��͂��̔z����AmuRessyaIndexOrder �̏���
		���בւ��܂��B
	*/
	static void sortRessyaByRessyaIndexOrder( 
		const Mu<int>* muRessyaIndexOrder,
		CentDedRessyaCont* pRessyaCont ) ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^�E�f�X�g���N�^
	// ********************************
	virtual ~CDedRessyaSoater(){} ;

public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�w�肳�ꂽ��ԃR���e�i���̗�Ԃ��A�����Ŏw�肳�ꂽ�����Ń\�[�g���܂��B
	@param pRessyaCont [in,out]
		���בւ��̑ΏۂƂȂ��ԃR���e�i���w�肵�Ă��������B
	@param pIfProgress [in]
		�i����Ԃ̒ʒm���󂯂����ꍇ�́A�i����Ԓʒm���󂯎��
		�C���X�^���X�ւ̃|�C���^���w�肵�Ă��������B
		NULL�Ȃ�A���̊֐��͐i����Ԃ̒ʒm���s���܂���B
	*/
	virtual void sort( 
		CentDedRessyaCont* pRessyaCont ,
		IfProgress* pIfProgress ) ;
	///@}

};

} //namespace entDed

#endif /*CDedRessyaSoater_h*/
