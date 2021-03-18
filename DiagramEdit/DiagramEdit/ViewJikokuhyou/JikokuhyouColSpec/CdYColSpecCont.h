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
// $Id: CdYColSpecCont.h 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
/** @file */
#pragma once

#ifndef ViewJikokuhyou_CdYColSpecCont_h
#define ViewJikokuhyou_CdYColSpecCont_h

#include "NsMu\CMup_vector.h"

#include "ViewJikokuhyou\JikokuhyouColSpec\CdYColSpec.h"
#include "entDed\CentDedEkiCont.h"


namespace ViewJikokuhyou{ namespace JikokuhyouColSpec{
	using namespace entDed ;
/**
@brief
  �����\�r���[�� CWndJikokuhyou �̊e��ԍ��ƕ\�����e�̑��ݕϊ���
  �@�\��񋟂��܂��B
  
  ���̃N���X�́A�����ɑS�Ă�Y��ɂ��Ă� �w��ԍ�-�\�����e�x�̑Ή��\��
�ێ����܂��B ���̑Ή��\�́A CentDedEkiCont�ECentDedEki �ɕύX������
�����疳���ɂȂ�܂��B���̂��߁A CentDedEkiCont�ECentDedEki �ɕύX��
�\��������󋵂ł́A�Ή��\���X�V����K�v������܂��B

�y�g�����z

(1)  �f�t�H���g�R���X�g���N�^�ŃC���X�^���X�𐶐��������Ƃ́A scan() ��
�w��ԍ�-�\�����e�x�̑Ή��\���X�V���Ă��������B

(2)  �Ή��\�X�V��́AColumnNumberToSpec(),ColumnNumberFromSpec() �ŁA
��ԍ��ƕ\�����e�̑��ݕϊ����ł��܂��B

*/
class CdYColSpecCont
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	///@}

	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		��ԕ���
	*/
	ERessyahoukou	m_eRessyahoukou ;

	/**
		- true ;[�S������\��] ���[�h
	*/
	bool m_bDisplayAllJikoku ;
	
	/**
		�w�����̐擪��̗�ԍ��Bscan() �Ō��܂�܂��B
		�w����0�̏ꍇ�́A�w���ǉ�������ԍ��ɂȂ�܂��B
	*/
	int m_iColumnNumber_Ekijikoku_begin ;

	/**
		�w������� �I�[(�̎�) �� ��ԍ��B
		scan() �Ō��܂�܂��B
	*/
	int m_iColumnNumber_Ekijikoku_end ;

	///@}

	// ********************************
	///@name �W��
	// ********************************
	///@{
	/**
		�w��ԍ�-�\�����e�x�̑Ή��\�B
		�C���f�N�X����ԍ��ɑ������܂��B
		�v�f���������\�r���[��Y�񐔂ɑ������܂��B
	*/
	CMup_vector<CdYColSpec>	m_contColumnSpec ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		scan() �Ɠ����ł��B
	@param pCentDedEkiCont
		�w�R���e�i�B
		���̃I�u�W�F�N�g�́A�֐��I����͔j���ł��܂��B
	@param eRessyahoukou 
		��ԕ���
	@param bDisplayAllJikoku 
		- true ;[�S������\��] ���[�h
	*/
	CdYColSpecCont( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou	eRessyahoukou ,
		bool bDisplayAllJikoku ) ;
	CdYColSpecCont() ;
 
public:
	// ********************************
	///@name CdYColSpec-�֘A
	// ********************************
	///@{
	///@}
	// ********************************
	///@name CdYColSpec-����
	// ********************************
	///@{
	ERessyahoukou	getRessyahoukou()const ;
	bool getDisplayAllJikoku()const ;
	int getColumnNumber_Ekijikoku_begin()const ;
	int getColumnNumber_Ekijikoku_end()const ;


	///@}
	// ********************************
	///@name CdYColSpecCont-����
	// ********************************
	///@{
	/**
		�w�R���e�i�𑖍����āA �w��ԍ�-�\�����e�x�̑Ή��\���X�V���܂��B
		this ������܂ŕێ����Ă������e�͂��ׂĎ����܂��B 
	@param pCentDedEkiCont
		�w�R���e�i�B
		���̃I�u�W�F�N�g�́A�֐��I����͔j���ł��܂��B
	@param eRessyahoukou 
		��ԕ���
	@param bDisplayAllJikoku 
		- true ;[�S������\��] ���[�h
	*/
	void scan( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou	eRessyahoukou ,
		bool bDisplayAllJikoku ) ;


	/**
	@return 
		�񐔂�Ԃ��܂��B
	*/
	int size() ;

	/**
		��ԍ�����A�\������ׂ����e�𓱏o���܂��B
	@param iYColumnNumber 
		��ԍ����w�肵�Ă��������B
	@return
		�\�����ׂ����e��Ԃ��܂��B
		��ԍ����������Ȃ��ꍇ�́ANULL��Ԃ̃I�u�W�F�N�g��Ԃ��܂��B
	*/
	CdYColSpec ColumnNumberToSpec( 
		int iYColumnNumber ) ;

	/**
		�\�����e�ɑ΂����ԍ��𓱏o���܂��B
	@param aCdYColSpec 
		�\�����e���w�肵�Ă��������B
	@param bResolveSameStation
		- true ; �Ή�����\�����ڂ���\���ł���ꍇ�A����̗�ԍ���Ԃ��܂��B
		- false ;	�Ή�����\�����ڂ���\���ł���ꍇ�A-1��Ԃ��܂��B
	@return
		�\�����ׂ����e��Ԃ��܂��B
		�Ή������ԍ����Ȃ��ꍇ(��\�����܂�)�́A-1��Ԃ��܂��B

	 �Ή�����\�����ڂ���\���ŁA bResolveSameStation �� true �̏ꍇ�A
	 �ȉ��̂悤�ɓ��삵�܂��B

		- aCdYColSpec ���AColumnType_Ressyabangou
		(��Ԕԍ�)�`ColumnType_Gou(�u���v�\��) �܂łȂ�A
		ColumnType_Ressyabangou�`ColumnType_Gou �̂����̂����ꂩ����������
		�ŏ��̗�ԍ���Ԃ��܂��B
		- aCdYColSpec ��	ColumnType_Ekijikoku_Chaku
		(������)�Ȃ�΁A�����wOrder�� ColumnType_Ekijikoku_Hatsu(������)
		��Ԃ��܂��B���̗����\���Ȃ�A
		�wOrder�� aCdYColSpec �����ŁA
		ColumnType_Ekijikoku_Chaku �� 
		ColumnType_Ekijikoku_Hatsu �̗�̂����A��ԑ傫����ԍ���Ԃ��܂��B
		- aCdYColSpec ��	
		ColumnType_Ekijikoku_Hatsu(������)�̏ꍇ���A
		ColumnType_Ekijikoku_Chaku �̏ꍇ�Ɠ��l�ł��B
		- aCdYColSpec ��	
		ColumnType_Bikou(���l)�̏ꍇ�A��ԉ��̗��Ԃ��܂��B

	*/
	int ColumnNumberFromSpec( 
		const CdYColSpec& 
			aCdYColSpec ,
		bool bResolveSameStation ) ;

	/**
		�w��ԍ�-�\�����e�x�̑Ή��\���폜���܂��B
	*/
	void clear() ;
	///@}
};

} } //namespace JikokuhyouColSpec namespace ViewJikokuhyou

#endif/* ViewJikokuhyou_CdYColSpecCont_h*/
