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
//$Id: CentDedEkiTrackCont.h 378 2016-11-16 21:10:54Z okm $

#ifndef  entDed_CentDedEkiTrackCont_h
#define  entDed_CentDedEkiTrackCont_h

#include "NsMu\CMuiCopiedParent.h"
#include "CentDedEkiTrack.h"
#include "CentDed.h"


namespace entDed{

//	�O���Q��
class CentDedEki ;
class CentDedRosen ;

/**
@brief
  �w�́w�Ԑ��x�̃R���e�i�ł��B
  
  ���̃R���e�i�� CentDedEki �̎q�I�u�W�F�N�g�ŁA
���� CentDedEki �� CentDedRosen �ɕ�܂���Ă���ꍇ�A insert() 
���\�b�h�́ACentDedRosen::onEkiTrackInsert( iEkiIndex , iEkiTrackIndex ) 
�ɏ������Ϗ����܂��Berase() �����l�ł��B
  

����
 -------------------------------- 

����Ɂw���{���x�E�w����{���x���P���K�v�B

���w���{���x�E�w����{���x�̒ǉ��E�폜�͋֎~�B

(��)�w���������I�u�W�F�N�g�̔Ԑ��w��q���C���f�N�X�̏ꍇ�A�C���f�N�X�� CentDedEkiTrackCont �͈͓̔��łȂ��Ă͂Ȃ�Ȃ��B


����̃G���[�����E�C��
 -------------------------------- 

���R���e�i�̐���(�R���X�g���N�^): �w���{���x�w����{���x��ݒ肷��B

���Ԑ��̒ǉ�(insert):�w�{���x�̒ǉ��̓G���[

(��)�Ԑ��̒ǉ�(insert):�w���������I�u�W�F�N�g�̔Ԑ��w��q�̎w��������C���f�N�X�̏ꍇ�A�C���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B

���Ԑ��̍폜(erase):�w�{���x�̍폜�̓G���[

(��)�Ԑ��̍폜(erase):�w���������I�u�W�F�N�g�̔Ԑ��w��q�̎w��������C���f�N�X�̏ꍇ�A�C���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B
�@�w���������I�u�W�F�N�g�̔Ԑ��w��q�̎w��������C���f�N�X�ŁA���̃C���f�N�X���폜�Ώۂ̂��̂ł���ꍇ�A�w�{���x�ɕύX����

���Ԑ��̏㏑��(set): �Ԑ���ʂ̈قȂ� CentDedEkiTrack ���㏑������ƃG���[

���R���e�i�̑��(operator=):insert,erase,set���g�p���āA�{���̒ǉ��֎~�E�폜�֎~�E�㏑���֎~�̐���������

���폜�Ώۂ̔Ԑ��̃C���f�N�X�����w���������̌���(findRessyaOfEkiTrack):�폜�Ώۂ̔Ԑ���\���Ԑ��C���f�N�X�����w���������I�u�W�F�N�g����������

����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 

�����ׂĂ�CentDedEkiTrack(�Ԑ�)�ɁAadjust()���Ϗ�����B


*/
class CentDedEkiTrackCont : public CMuiCopiedParent<CentDedEkiTrack>
{
	typedef  CMuiCopiedParent<CentDedEkiTrack>	super ;
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		CentDedEki �ɕ�܂���Ȃ��ACentDedEkiTrackCont �𐶐����܂��B
		CentDedEkiTrack �́A���{���Ɖ���{���̂Q����Ȃ�܂��B

		���R���e�i�̐���(�R���X�g���N�^): �w���{���x�w����{���x��ݒ肷��B
	*/
	CentDedEkiTrackCont() ;
	
	/** 
	@todo
		����́A�ʂ� insert(),erase()�ɕύX���܂��B 
	*/
	CentDedEkiTrackCont& operator=( const CentDedEkiTrackCont& value );

public:
	// ********************************
	///@name Mui
	// ********************************
	///@{

	/**
		�Ԑ��I�u�W�F�N�g��ǉ����܂��B
		�A���A�{����ǉ����邱�Ƃ͂ł��܂���B
	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		0 ����n�܂�C���f�N�X���w�肵�Ă��������B 
		�͈͂͂O�ȏ� size() �ȉ��ł��B �O�́A�擪�Esize()�Ȃ疖���ւ�
		�ǉ��ɂȂ�܂��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@return
		0�ȏ�͐����A���̐��̓G���[�ł��B
		-	-1 ;	//	�C���f�N�X���͈͊O�ł��B
		-	-11 ;	//	�{����ǉ����邱�Ƃ͏o���܂���B

	*/
	virtual int insert( const CentDedEkiTrack& element ,  int iIndex=INT_MAX) ;
	/**
	 	�Ԑ��I�u�W�F�N�g���폜���܂��B
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
		-	-1 ;	//	�C���f�N�X���͈͊O�ł��B
		-	-11 ;	//	�{�����폜���邱�Ƃ͏o���܂���B
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) ;

	/**
		�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA �v�f���㏑�����܂��B 
		�㏑����̗v�f�� CChildItem::m_pParent �ɂ́Athis ��o�^���܂��B

		�Ԑ���ʂ̈قȂ�I�u�W�F�N�g���㏑�����邱�Ƃ͂ł��܂���B		

	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		�O����n�܂�C���f�N�X���w�肵�Ă��������B �͈͂͂O�ȏ� size() 
		�����ł��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11 ;	//	�Ԑ���ʂ̈قȂ�I�u�W�F�N�g���㏑�����邱�Ƃ͂ł��܂���B
	*/
	virtual int set( const CentDedEkiTrack& element , int iIndex ) ;
	///@}

public:
	// ********************************
	///@name CentDedEkiTrackCont-�֘A
	// ********************************
	///@{
	/**
	@return
		���̃R���e�i�� CentDedEki �ɕ�܂���Ă���ꍇ�́A
		CentDedEki �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	virtual CentDedEki* getEki(){ return NULL ;}
	/**
	@return
		���̃R���e�i�� CentDedEki �ɕ�܂���Ă���ꍇ�́A
		CentDedEki �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	virtual const CentDedEki* getEki()const{ return NULL ;}

	/**
	@return
		���̃R���e�i�� CentDedRosen �ɕ�܂���Ă���ꍇ�́A
		CentDedRosen �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	CentDedRosen* getRosen() ;
	/**
	@return
		���̃R���e�i�� CentDedRosen �ɕ�܂���Ă���ꍇ�́A
		CentDedRosen �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	const CentDedRosen* getRosen()const ;
	///@}
public:
	// ********************************
	///@name CentDedEkiTrackCont-����
	// ********************************
	///@{
	/**
		set() ���\���ۂ��𔻒f���܂��B

		�Ԑ���ʂ̈قȂ�I�u�W�F�N�g���㏑�����邱�Ƃ͂ł��܂���B		
	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		�O����n�܂�C���f�N�X���w�肵�Ă��������B �͈͂͂O�ȏ� size() 
		�����ł��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@return
		-	0�ȏ�: set() ���\�B
		-	���̐�: set()�́A���̖߂�l�Ŏ��s���܂��B
		-	-11 ;	//	�Ԑ���ʂ̈قȂ�I�u�W�F�N�g���㏑�����邱�Ƃ͂ł��܂���B
	 */
	virtual int  setable(  const CentDedEkiTrack& element , int iIndex )const ;

	/**
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
	@param element
		�v�f���w�肵�Ă��������B 
	@return
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
		�����łȂ��ꍇ�́A -1 �ł��B
	*/
	virtual int  getIndex( const CentDedEkiTrack* element )const ;

	/**
		this �̑���������ɔ����Ă���ꍇ�A����ɍ����悤�ɁA������
		�C�����܂��B

	�����ׂĂ�CentDedEkiTrack(�Ԑ�)�ɁAadjust()���Ϗ�����B

	*/
	void adjust() ;


	/**
		���̔Ԑ��C���f�N�X������Ԃ��������܂��B

	@param index 
		�Ԑ��̃C���f�N�X���w�肵�Ă��������B
	@param piDiaIndex [out]
		���̔Ԑ�������Ԃ�����ꍇ�A�֐��̓_�C��index ���������݂܂��B
	@param pRessyahoukou [out]
		���̔Ԑ�������Ԃ�����ꍇ�A�֐��͗�ԕ������������݂܂��B
	@param piRessyaIndex [out]
		���̔Ԑ�������Ԃ�����ꍇ�A�֐��͗�� Index ���������݂܂��B
	@return
		-	1: ���̔Ԑ�������Ԃ�����܂��B
		-	0: ���̔Ԑ�������Ԃ�����܂���B
	*/
	
	int findRessyaOfEkiTrack( 
		int index , 
		int* piDiaIndex , 
		ERessyahoukou* pRessyahoukou , int* piRessyaIndex )const ;

};

} //namespace entDed


#endif //entDed_CentDedEkiTrackCont_h



