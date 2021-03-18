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
//$Id: CentDedEkiJikokuCont.h 378 2016-11-16 21:10:54Z okm $
/** @file */
#ifndef  entDed_CentDedEkiJikokuCont_h
#define  entDed_CentDedEkiJikokuCont_h

#include "NsMu\CMuiCopiedParent.h"
#include "CentDedEkiJikoku.h"

namespace entDed{

//	�O���Q�Ɛ錾
class CentDedRessya ;
class CentDedEkiJikoku ;
	

/**
@brief
  �w�w�����x�I�u�W�F�N�g�̃R���e�i�ł��B


����
 -------------------------------- 

����Ԃ��H���̈ꕔ�ł���ꍇ�A�v�f���͉w�̐��Ɉ�v���Ă��Ȃ��Ă͂Ȃ�Ȃ�

����̃G���[�����E�C��
 -------------------------------- 

��operator=: this ���H���̈ꕔ�ł���ꍇ�́A�w�����̐��͕ύX���܂���

���w�����̒ǉ�(insert)�F�@��Ԃ��H���̈ꕔ�ł���ꍇ�̓G���[�B

���w�����̍폜(erase):�@��Ԃ��H���̈ꕔ�ł���ꍇ�̓G���[�B


���w�̒ǉ�(OnInsertEki):�@��Ԃ̉w�����́A�w�̒ǉ��ɍ��킹�ăV�t�g������B

���w�̍폜(OnEraseEki):�@��Ԃ̉w�����́A�w�̍폜�ɍ��킹�ăV�t�g������B



����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 

���w����(CentDedEkiJikoku)�̗v�f�����w�R���e�i(CentDedEkiCont)�ƈقȂ�ꍇ�́A�w������ǉ��E�폜���܂��B

��CentDedEkiJikoku(�w����)�ɁAadjust()���Ϗ����܂��B


*/
class CentDedEkiJikokuCont : public CMuiCopiedParent< CentDedEkiJikoku >
{
public:
	typedef  public CMuiCopiedParent< CentDedEkiJikoku > super ;
	
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		�v�f��0�ŏ��������܂��B
	*/
	CentDedEkiJikokuCont() ;

	/**
	��operator=: this ���H���̈ꕔ�ł���ꍇ�́A�w�����̐��͕ύX���܂���
	*/
	CentDedEkiJikokuCont& operator=( const CentDedEkiJikokuCont& value ) ;

public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f��ǉ����܂��B

		���w�����̒ǉ�(insert)�F�@��Ԃ��H���̈ꕔ�ł���ꍇ�̓G���[�B

	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �ȉ��ł��B
	 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
		-	-11 ;	//	��Ԃ��H���̈ꕔ�ł���ꍇ�A�w�����̒ǉ��͂ł��܂���B
	*/
	virtual int insert( const CentDedEkiJikoku& element , int iIndex = INT_MAX );
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
	 	�v�f���폜���܂��B

		���w�����̍폜(erase):�@��Ԃ��H���̈ꕔ�ł���ꍇ�̓G���[�B

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
		-	-11 ;	//	��Ԃ��H���̈ꕔ�ł���ꍇ�A�w�����̍폜�͂ł��܂���B
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) ;
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f���㏑�����܂��B

	@param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
		-	-11; //�Ԑ��w��q���w�Ԑ��R���e�i�xCentDedEkiTrackCont �̗v�f�ɑΉ����Ă��܂���
	*/
	virtual int set( const CentDedEkiJikoku& element , int iIndex ) ;
	///@}

 public:
	// ********************************
	///@name CentDedEkiJikokuCont-�֘A
	// ********************************
	///@{
	/**
	@return
		���̃R���e�i�� CentDedRessya �ɕ�܂���Ă���ꍇ�́A
		CentDedRessya �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	 virtual CentDedRessya* getRessya(){ return NULL ;}
	/**
	@return
		���̃R���e�i�� CentDedRessya �ɕ�܂���Ă���ꍇ�́A
		CentDedRessya �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	virtual const CentDedRessya* getRessya()const{ return NULL ;}

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
	///@name CentDedEkiJikokuCont-����
	// ********************************
	///@{

	/**
		set() ���\���ۂ��𔻒f���܂��B
		���̃N���X�ł́A���0��Ԃ��܂��B

	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		�O����n�܂�C���f�N�X���w�肵�Ă��������B �͈͂͂O�ȏ� size() 
		�����ł��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@return
		-	0�ȏ�: set() ���\�B
		-	���̐�: set()�́A���̖߂�l�Ŏ��s���܂��B
	 */
	virtual int  setable(  const CentDedEkiJikoku& element , int iIndex )const ;

	/**
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
	@param element
		�v�f���w�肵�Ă��������B 
	@return
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
		�����łȂ��ꍇ�́A -1 �ł��B
	*/
	virtual int  getIndex( const CentDedEkiJikoku* element )const ;
	/**
		this �̑���������ɔ����Ă���ꍇ�A����ɍ����悤�ɁA������
		�C�����܂��B


		���w����(CentDedEkiJikoku)�̗v�f�����w�R���e�i(CentDedEkiCont)�ƈقȂ�ꍇ�́A�w������ǉ��E�폜���܂��B

		��CentDedEkiJikoku(�w����)�ɁAadjust()���Ϗ����܂��B


	*/
	void adjust() ;
	///@}
public:
	// ********************************
	///@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
	///@{
	/**
		m_CentDedEkiCont �� CentDedEki ���ǉ����ꂽ����A
		m_CentDedEkiCont ����Ăяo����܂��B
	@param iEkiOrder
		�ǉ����ꂽ CentDedEki �̉wOrder(�w�C���f�N�X�ł͂���܂���)�B
	*/
	virtual void onEkiInsert( int iEkiOrder );

	/**
		m_CentDedEkiCont ���� CentDedEki ���폜���ꂽ����A
		m_CentDedEkiCont ����Ăяo����܂��B
	@param iEkiOrder
		�폜���ꂽ CentDedEki �̉wOrder(�w�C���f�N�X�ł͂���܂���)�B
	*/
	virtual void onEkiErase( int iEkiOrder  ); 
	/**
		CentDedEkiTrackCont �� CentDedEkiTrack ���ǉ����ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiOrder
		CentDedEkiTrackCont ���ǉ����ꂽ CentDedEki �̉wOrder(�w�C���f�N�X�ł͂���܂���)�B
	@param iEkiTrackIndex
		�ǉ����ꂽ CentDedEkiTrack �̃C���f�N�X�B
	*/
	virtual void onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex ); 
	/**
		CentDedEkiTrackCont ���� CentDedEkiTrack ���폜���ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiOrder
		CentDedEkiTrackCont ���폜���ꂽ CentDedEki �̉wOrder(�w�C���f�N�X�ł͂���܂���)�B
	@param iEkiTrackIndex
		�폜���ꂽ CentDedEkiTrack �̐擪�̃C���f�N�X�B
	*/
	virtual void onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex ); 

	///@}

};

} //namespace entDed


#endif //entDed_CentDedEkiJikokuCont_h
