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
//	CentDedRessyasyubetsuCont.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessyasyubetsuCont_h
#define  CentDedRessyasyubetsuCont_h

#include "NsMu/CMuiCopiedParent.h"

#include "CentDed.h"
#include "CentDedRessyasyubetsu.h"

namespace entDed{
	using namespace OuLib::NsMu;


//	�O���Q�Ɛ錾
class CentDedRosen ;

// ****************************************************************
//	CentDedRessyasyubetsuCont
// ****************************************************************
/**
@brief
 �w��Ԏ�ʁx( CentDedRessyasyubetsu ) �I�u�W�F�N�g�̃R���e�i�ł��B

  ���̃N���X���̂́A Mui< CentDedRessyasyubetsu > �C���^�[�t�F�[�X��
�T�|�[�g���܂��B���̃C���^�[�t�F�[�X�ɂ��A
CentDedRessyasyubetsu �I�u�W�F�N�g��
�ǉ��E�폜���邱�Ƃ��ł��܂��B

  getMuPtr() ���\�b�h�ɂ��A Mu< CentDedRessyasyubetsu* > 
�C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
  ���̃C���^�[�t�F�[�X���g���ƁA�R���e�i���� CentDedRessyasyubetsu 
�I�u�W�F�N�g�ɒ��ڃA�N�Z�X���邱�Ƃ��ł��܂��B
	
@attention
  this �� get() ���\�b�h�́A CentDedRessyasyubetsu �I�u�W�F�N�g��
�R�s�[��Ԃ��܂��B
  get() ���\�b�h�ŕԂ��ꂽ�I�u�W�F�N�g�ɑ΂��āA
CentDedRessyasyubetsu �I�u�W�F�N�g���X�V���郁�\�b�h���Ăяo���Ă��A
�R���e�i���̗�Ԏ�ʃI�u�W�F�N�g���X�V���邱�Ƃ͂ł��܂���B\n
�R���e�i���̗�Ԏ�ʃI�u�W�F�N�g�̃��\�b�h���Ăяo���ꍇ�́A
getMuPtr() �� Mu<CentDedRessyasyubetsu*>* ���擾���Ă���A
���̃C���^�[�t�F�[�X�o�R�� CentDedRessyasyubetsu* ���擾���A���̃|�C���^��
���\�b�h���Ăяo���Ă��������B

����
 -------------------------------- 
���H���̈ꕔ�ł���ꍇ�́A�Œ�P�́w��Ԏ�ʁx���K�v�B(����́A�H���̃R���X�g���N�^�Ŏ��{)

���R���e�i���́w��Ԏ�ʁx�́A����1�ȏ�̖��O�������Ȃ��Ă͂Ȃ�Ȃ�

(��)��Ԃ̗�Ԏ�ʃC���f�N�X�́ACentDedRessyasyuebtsu �͈͓̔��łȂ��Ă͂Ȃ�Ȃ�

����̃G���[�����E�C��
 -------------------------------- 

rinji
����Ԏ�ʂ̒ǉ�(insert):���̃R���e�i���H���̈ꕔ�ł���ꍇ�A���O����̗�Ԏ�ʂ̒ǉ��̓G���[

(��)��Ԏ�ʂ̒ǉ�(insert):�@��Ԃ̗�Ԏ�ʃC���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B

����Ԏ�ʂ̍폜(erase):�@��Ԏ�ʂ�0�ɂȂ�悤�ȍ폜�̓G���[

(��)��Ԏ�ʂ̍폜(erase):�@��Ԃ̗�Ԏ�ʃC���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B
�@��Ԃ̗�Ԏ�ʃC���f�N�X���폜�Ώۂ̏ꍇ�A�C���f�N�X��0�ɂ���

���Ԑ��̏㏑��(set): name����� CentDedRessyasyubetsu���㏑������ƃG���[�B

���R���e�i�̑��(operator=):�R���e�i���H���̈ꕔ�ł���ꍇ�ŁA�E�ӂ̗v�f����0�̏ꍇ�́A
�C���f�N�X0�Ԃ̗�Ԏ�ʂ�ǉ����āA��Ԏ�ʂ̐���0�ɂȂ�Ȃ��悤�ɂ���


���폜�Ώۂ̗�Ԏ�ʂ̃C���f�N�X������Ԃ̌���(findRessyaOfRessyasyubetsu):
�폜�Ώۂ̗�Ԏ�ʕ\����Ԏ�ʃC���f�N�X������ԃI�u�W�F�N�g����������


����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 

�����ׂĂ�CentDedRessyasyubetsu(��Ԏ��)�ɁAadjust()���Ϗ�����B




 */
class CentDedRessyasyubetsuCont : public CMuiCopiedParent< CentDedRessyasyubetsu >
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	typedef CMuiCopiedParent< CentDedRessyasyubetsu >	super ;

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	���R���e�i�̐���(�R���X�g���N�^): �C���f�N�X0�Ԃ̗�Ԏ�ʂ�ݒ肷��B
	*/
	CentDedRessyasyubetsuCont() ;
	
	/**
	���R���e�i�̑��(operator=):�R���e�i���H���̈ꕔ�ł���ꍇ�ŁA�E�ӂ̗v�f����0�̏ꍇ�́A
	�C���f�N�X0�Ԃ̗�Ԏ�ʂ�ǉ����āA��Ԏ�ʂ̐���0�ɂȂ�Ȃ��悤�ɂ���
	*/
	CentDedRessyasyubetsuCont& operator=( const CentDedRessyasyubetsuCont& value ) ;

public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f��ǉ����܂��B

	rinji
	����Ԏ�ʂ̒ǉ�(insert):���̃R���e�i���H���̈ꕔ�ł���ꍇ�A���O����̗�Ԏ�ʂ̒ǉ��̓G���[

	(��)��Ԏ�ʂ̒ǉ�(insert):�@��Ԃ̗�Ԏ�ʃC���f�N�X�́A
	�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B


	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �ȉ��ł��B
	 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int insert( const CentDedRessyasyubetsu& element , int iIndex = INT_MAX );
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
	 	�v�f���폜���܂��B

	����Ԏ�ʂ̍폜(erase):�@��Ԏ�ʂ�0�ɂȂ�悤�ȍ폜�̓G���[
	
	(��)��Ԏ�ʂ̍폜(erase):�@��Ԃ̗�Ԏ�ʃC���f�N�X�́A
	�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B
	  ��Ԃ̗�Ԏ�ʃC���f�N�X���폜�Ώۂ̏ꍇ�A�C���f�N�X��0�ɂ���

	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
	 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @param iSize [in]
	 	�폜����v�f�̐����w�肵�Ă��������B
	 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
	 @attention
		iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) ;
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f���㏑�����܂��B

	���Ԑ��̏㏑��(set): name����� CentDedRessyasyubetsu���㏑������ƃG���[�B
		
	@param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
		-	-11; //���Ԑ��̏㏑��(set): name����� CentDedRessyasyubetsu���㏑������ƃG���[�B
	*/
	virtual int set( const CentDedRessyasyubetsu& element , int iIndex ) ;
	///@}

 public:
	// ********************************
	///@name CentDedRessyasyubetsuCont-�֘A
	// ********************************
	///@{
	/**
	@return
		���̃R���e�i�� CentDedRosen �ɕ�܂���Ă���ꍇ�́A
		CentDedRosen �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	 virtual CentDedRosen* getRosen(){ return NULL ;}
	/**
	@return
		���̃R���e�i�� CentDedRosen �ɕ�܂���Ă���ꍇ�́A
		CentDedRosen �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	virtual const CentDedRosen* getRosen()const{ return NULL ;}
	///@}
 public:
	// ********************************
	///@name CentDedRessyasyubetsuCont-����
	// ********************************
	///@{

	/**
		set() ���\���ۂ��𔻒f���܂��B

	���Ԑ��̏㏑��(set): name����� CentDedRessyasyubetsu���㏑������ƃG���[�B
	
	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		�O����n�܂�C���f�N�X���w�肵�Ă��������B �͈͂͂O�ȏ� size() 
		�����ł��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@return
		-	0�ȏ�: set() ���\�B
		-	���̐�: set()�́A���̖߂�l�Ŏ��s���܂��B
		-	-11; //���Ԑ��̏㏑��(set): name����� CentDedRessyasyubetsu���㏑������ƃG���[�B
	 */
	virtual int  setable(  const CentDedRessyasyubetsu& element , int iIndex )const ;

	/**
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
	@param element
		�v�f���w�肵�Ă��������B 
	@return
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
		�����łȂ��ꍇ�́A -1 �ł��B
	*/
	virtual int  getIndex( const CentDedRessyasyubetsu* element )const ;

	/**
	  Rosen �ɁA�w�肳�ꂽ�w��Ԏ�ʁx�̗�Ԃ����邩�ۂ��𒲂ׂ܂��B
	@param iRessyasyubetsuIndex [in]
		�w��Ԏ��Index�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ� ��Ԏ�ʂ̐������ł��B
		INT_MAX �́A�����̗�Ԏ�ʂ��w�肵�����̂Ƃ݂Ȃ��܂��B
	 @param piDiaIndex [out]
		���̊֐��͂��̕ϐ��ɁA�w��Ԏ�ʁx�̗�Ԃ���������
		�_�C���̃C���f�N�X���������݂܂��B
		�s�v�Ȃ� NULL �ł����܂��܂���B
	@param peRessyahoukou [out]
		���̊֐��͂��̕ϐ��ɁA�w��Ԏ�ʁx�̗�Ԃ���������
		�_�C���̗�ԕ������������݂܂��B
		�s�v�Ȃ� NULL �ł����܂��܂���B
	@param piRessyaIndex [out]
		���̊֐��͂��̕ϐ��ɁA�w��Ԏ�ʁx�̗�Ԃ���������
		���Index ���������݂܂��B
		�s�v�Ȃ� NULL �ł����܂��܂���B
	@return 
		-	1; //	�w��̗�Ԏ�ʂ̗�Ԃ����݂��܂��B
		-	0; //	�w��̗�Ԏ�ʂ̗�Ԃ͑��݂��܂���B
		-	-1 ;	//	�C���f�N�X���s��
	 */
	int isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piDiaIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const ;
	///@}
};


} //namespace entDed

#endif /*CentDedRessyasyubetsuCont_h*/
