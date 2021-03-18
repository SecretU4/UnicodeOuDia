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
//	entDed\CRessyaContUnifier.h
// $Id: CRessyaContUnifier.h 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  entDed_CRessyaContUnifier_h
#define  entDed_CRessyaContUnifier_h
#include "NsMu\Mui.h"
#include "entDed\CentDedRessya.h"
#include "IfProgress.h"

namespace entDed{


// ****************************************************************
//	CRessyaContUnifier
// ****************************************************************
/**
@brief
	CentDedRessyaDia ���̗�Ԃ��A��Ԕԍ��ň�{�����鏈�����s���܂��B
	
�y�g�����z
	
	1.  �R���X�g���N�^�ŃI�u�W�F�N�g�𐶐����Ă��������B
	
	2.�@unify() ���\�b�h���Ăяo���ƁAthis�́A�w�肳�ꂽ��ԃR���e�i�̂��ׂĂ̗�Ԃ��A��Ԕԍ��ň�{�����܂��B
*/
class CRessyaContUnifier
{
public:
	// ********************************
	///@name CRessyaContUnifier-static ����
	// ********************************
	///@{
	/**
		�@�w�肳�ꂽ��ԃR���e�i���́A�Q�̗�Ԃ���{�����܂��B
	@param pMuiRessya [in,out]
		�@���בւ��̑ΏۂƂȂ��ԃR���e�i���w�肵�Ă�������
	@param iRessyaIndex [in]
		�@��{���̑ΏۂƂȂ��Ԃ̃C���f�N�X���w�肵�Ă��������B
	@param iRessyaIndex2 [in]
		�@��{���̑ΏۂƂȂ��Ԃ̃C���f�N�X���w�肵�Ă��������B
		�@���̊֐��́A iRessyaIndex2 �̗�Ԃ̉w�������A
		iRessyaIndex �ɃR�s�[���܂��B
		�@iResysaIndex2 �̗�Ԃ͍폜���܂��B
	*/
	static void unify( 
		Mui<CentDedRessya>* pMuiRessya ,
		int iRessyaIndex ,
		int iRessyaIndex2 ) ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^�E�f�X�g���N�^
	// ********************************
	CRessyaContUnifier();
	virtual ~CRessyaContUnifier() ;

public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�@�w�肳�ꂽ��ԃR���e�i���̗�Ԃ��A�����Ŏw�肳�ꂽ������
		�\�[�g���܂��B
	@param pMuiRessya [in,out]
		�@���בւ��̑ΏۂƂȂ��ԃR���e�i���w�肵�Ă�������
		( CentDedRessyaCont ���w��ł��܂�)�B
	@param pIfProgress [in]
		�i����Ԃ̒ʒm���󂯂����ꍇ�́A�i����Ԓʒm���󂯎��
		�C���X�^���X�ւ̃|�C���^���w�肵�Ă��������B
		NULL�Ȃ�A���̊֐��͐i����Ԃ̒ʒm���s���܂���B
	@return
		-	0:	�������p�����܂��B
		-	���̐� : ���������f����܂����B
	*/
	virtual void unify( 
		Mui<CentDedRessya>* pMuiRessya ,
		IfProgress* pIfProgress ) ;
	///@}

};

} //namespace entDed

#endif /*entDed_CRessyaContUnifier_h*/

