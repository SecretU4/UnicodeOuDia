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
// ****************************************************************
// $Id: CdRessyasyubetsuYColSpecCont.h 179 2014-05-05 13:50:33Z okm $
// ****************************************************************
/** @file */
#pragma once
#ifndef ViewRessyasyubetsu_CdRessyasyubetsuYColSpecCont_h
#define ViewRessyasyubetsu_CdRessyasyubetsuYColSpecCont_h

#include "ViewRessyasyubetsu\RessyasyubetsuColSpec\CdRessyasyubetsuYColSpec.h"
#include "entDed\CentDedRessyasyubetsuCont.h"

namespace ViewRessyasyubetsu{ namespace RessyasyubetsuColSpec{
using namespace entDed;
	
/**
@brief
  ��Ԏ�ʃr���[�� CWndDcdGridRessyasyubetsu �ɂ����āA�O���b�hY���
  �e��ԍ��ƕ\�����e�̑��ݕϊ��̋@�\����񋟂��܂��B
  

�y�g�����z

(1)  �f�t�H���g�R���X�g���N�^�ŃC���X�^���X�𐶐��������Ƃ́A scan() ��
�ϊ��ɕK�v�ȏ���ǂݍ��܂��Ă��������B

(2)  �Ή��\�X�V��́AColumnNumberToSpec(),ColumnNumberFromSpec() �ŁA
��ԍ��ƕ\�����e�̑��ݕϊ����ł��܂��B

*/
class CdRessyasyubetsuYColSpecCont
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/** 
		��Ԏ�ʂ̐� �B
		scan() �Ō��܂�܂��B
		����l��0�ł��B
	*/
	int m_iRessyasyubetsuCount ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		scan() �Ɠ����ł��B
	@param pCentDedRessyasyubetsuCont
		��Ԏ�ʃR���e�i�B
		���̃I�u�W�F�N�g�́A�֐��I����͔j���ł��܂��B
	*/
	CdRessyasyubetsuYColSpecCont( 
		const CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont ) ;
	CdRessyasyubetsuYColSpecCont() ;

public:
	// ********************************
	///@name CdRessyasyubetsuYColSpecCont-����
	// ********************************
	///@{
	int getRessyasyubetsuCount()const;
	///@}
	// ********************************
	///@name CdRessyasyubetsuYColSpecCont-����
	// ********************************
	///@{
	/**
		�R���e�i�𑖍����āA �w��ԍ�-�\�����e�x��
		�ϊ��ɕK�v�ȏ���ǂݍ��݂܂��B
		this ������܂ŕێ����Ă������e�͂��ׂĎ����܂��B 
	@param pCentDedRessyasyubetsuCont
		��Ԏ�ʃR���e�i�B
		���̃I�u�W�F�N�g�́A�֐��I����͔j���ł��܂��B
	*/
	void scan( 
		const CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont ) ;

	/**
	@return 
		�񐔂�Ԃ��܂��B
	*/
	int size() ;

	/**
		��ԍ�����A�\������ׂ����e�𓱏o���܂��B
	@param iColumnNumber 
		��ԍ����w�肵�Ă��������B
	@return
		�\�����ׂ����e��Ԃ��܂��B
		��ԍ����������Ȃ��ꍇ�́ANULL��Ԃ̃I�u�W�F�N�g��Ԃ��܂��B

		�߂�l�� 
		CdRessyasyubetsuYColSpec::m_eColumnType == 
		ColumnType_NewRessyasyubetsu �̏ꍇ�A
		CdRessyasyubetsuYColSpec::m_iRessyasyubetsuIndex �͗�Ԏ�ʐ���
		�������Ȃ�܂��B
	*/
	CdRessyasyubetsuYColSpec ColumnNumberToSpec( 
		int iColumnNumber ) ;

	/**
		�\�����e�ɑ΂����ԍ��𓱏o���܂��B
	@param aCWndJikokuhyou_CdXColSpec 
		�\�����e���w�肵�Ă��������B
	@return
		�\�����ׂ����e��Ԃ��܂��B
		�Ή������ԍ����Ȃ��ꍇ(��\�����܂�)�́A-1��Ԃ��܂��B
	*/
	int ColumnNumberFromSpec( 
		const CdRessyasyubetsuYColSpec& aSpec ) ;


	/**
		this �����������܂��B
	*/
	void clear() ;
	///@}
};
} } //namespace RessyasyubetsuColSpec namespace ViewRessyasyubetsu

#endif/*ViewRessyasyubetsu_CdRessyasyubetsuYColSpec_h*/
