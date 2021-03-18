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
//	CentDedDiaCont.h
// ****************************************************************
*/
#ifndef  CentDedDiaCont_h
#define  CentDedDiaCont_h
/** @file */

#include "NsMu/CMuiCopiedParent.h"
#include "CentDedDia.h"

namespace entDed{

//�O���Q��
class CentDedRosen ;



// ****************************************************************
//	CentDedDiaCont
// ****************************************************************
/**
@brief
  CentDedDia �I�u�W�F�N�g�̃R���e�i�N���X�ł��B

���̃N���X���̂́A Mui< CentDedDia > �C���^�[�t�F�[�X��
�T�|�[�g���܂��B���̃C���^�[�t�F�[�X�ɂ��A CentDedDia �I�u�W�F�N�g��
�ǉ��E�폜���邱�Ƃ��ł��܂��B

�܂��A getMuPtr() ���\�b�h�ɂ��A
Mui< CentDedDia* > �C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
���̃C���^�[�t�F�[�X�ɂ��A�R���e�i���� CentDedDia �I�u�W�F�N�g��
���ڃA�N�Z�X�i���\�b�h�ďo�j���s�����Ƃ��ł��܂��B

	
����
 -------------------------------- 
���_�C���R���e�i�ɁA�������O�̃_�C�������������Ă͂Ȃ�Ȃ��B

���_�C���R���e�i�ɁA�󕶎���̃_�C���������Ă͂Ȃ�Ȃ��B



����̃G���[�����E�C��
 -------------------------------- 
���_�C���̒ǉ�(insert):�������O�̃_�C�������łɂ���ꍇ�̓G���[�B
�@�󕶎���̃_�C���̒ǉ��̓G���[�B

���_�C���̏㏑��(set):�������O�̃_�C�������ɂ���ꍇ�̓G���[�B
�@�󕶎���̃_�C���̏㏑���̓G���[�B


����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 
�����ׂĂ�CentDedDia(�_�C��)�ɁAadjust()���Ϗ�����B



*/
class CentDedDiaCont : public CMuiCopiedParent< CentDedDia >
{
	typedef CMuiCopiedParent< CentDedDia >	super ;

public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	�v�f��ǉ����܂��B

	<H4>
	�y�I�[�o���C�h�z
	</H4>
	���_�C���̒ǉ�(insert):�������O�̃_�C�������łɂ���ꍇ�̓G���[�B
	�@�󕶎���̃_�C���̒ǉ��̓G���[�B

	
	@param element [in]
		�v�f���w�肵�Ă��������B
	@param iIndex [in]
		�O����n�܂�C���f�N�X���w�肵�Ă��������B
		�͈͂͂O�ȏ� size() �ȉ��ł��B
		�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	@return
		0�ȏ�͐����A���̐��̓G���[�ł�
		-	-1 ;	//	�C���f�N�X���s���ł��B
		-	-2 ;	//	element �ɂ̓_�C�������w�肳��Ă��܂���B
		-	-3 ;	//	���łɓ����̃_�C�������݂��܂��B
	 */
	virtual int insert( const CentDedDia& element , int iIndex = INT_MAX ) ;

	/**
		�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
		�v�f���㏑�����܂��B
	<H4>
	�y�I�[�o���C�h�z
	</H4>
	���_�C���̏㏑��(set):�������O�̃_�C�������ɂ���ꍇ�̓G���[�B
	�@�󕶎���̃_�C���̏㏑���̓G���[�B
	
	@param element [in]
		�v�f���w�肵�Ă��������B
	@param iIndex [in]
		�O����n�܂�C���f�N�X���w�肵�Ă��������B
		�͈͂͂O�ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	@return
		0�ȏ�͐����A���̐��̓G���[�ł�
		-	-1 ;	//	iIndex ���s���ł��B
		-	-2 ;	//	element �ɂ̓_�C�������w�肳��Ă��܂���B
		-	-3 ;	//	���łɓ����̃_�C�������݂��܂��B
	*/
	virtual int set( const CentDedDia& element , int iIndex ) ;

	///@}
	

 public:
	// ********************************
	///@name CentDedDiaCont-�֘A
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
	virtual const CentDedRosen* getRosen()const { return NULL ;}
	
	///@}
	// ********************************
	///@name CentDedDiaCont-����
	// ********************************
	///@{
	/**
		set() ���\���ۂ��𔻒f���܂��B

	���_�C���̏㏑��(set):�������O�̃_�C�������ɂ���ꍇ�̓G���[�B
	�@�󕶎���̃_�C���̏㏑���̓G���[�B


	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		�O����n�܂�C���f�N�X���w�肵�Ă��������B �͈͂͂O�ȏ� size() 
		�����ł��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@return
		-	0�ȏ�: set() ���\�B
		-	���̐�: set()�́A���̖߂�l�Ŏ��s���܂��B
		-	-2 ;	//	element �ɂ̓_�C�������w�肳��Ă��܂���B
		-	-3 ;	//	���łɓ����̃_�C�������݂��܂��B
	 */
	virtual int  setable(  const CentDedDia& element , int iIndex )const ;

	/**
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
	@param element
		�v�f���w�肵�Ă��������B 
	@return
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
		�����łȂ��ꍇ�́A -1 �ł��B
	*/
	virtual int  getIndex( const CentDedDia* element )const ;
	/**
		this �̑���������ɔ����Ă���ꍇ�A����ɍ����悤�ɁA������
		�C�����܂��B

		�����̃R���e�i�� CentDedRosen �̎q�I�u�W�F�N�g�ł���ꍇ�A
		m_iEkiCount �� m_iRessyasyubetsuCount �́ACentDedRosen�ɍ��킹�܂��B

		�����ׂĂ�CentDedRessya(���)�ɁAadjust()���Ϗ�����B
	*/
	void adjust() ;

	/**
		�w��̃_�C����������
		�w�_�C���x ( CentDedDia ) �I�u�W�F�N�g�́A
		�C���f�N�X�𒲂ׂ܂��B
	 @param strName [in]
		�w�_�C�����x���w�肵�Ă��������B
	 @return 
		���������� 0 �ȏ�̃C���f�N�X�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�I�u�W�F�N�g���݂���܂���B
	*/
	int findCentDedDiaByName( const std::string& strName )const ;
	///@}
	// ********************************
	///@name CentDedDiaCont-���� �w���E��Ԏ�ʐ��̕ύX
	// ********************************
	///@{



	/**
		���̃R���e�i�ɁA�w�肳�ꂽ�w��Ԏ�ʁx�̗�Ԃ����邩�ۂ��𒲂ׂ܂��B
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
		int* piRessyaIndex ) const;

	///@}
public:
	// ********************************
	///@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
	///@{
	/**
		m_CentDedEkiCont �� CentDedEki ���ǉ����ꂽ����A
		m_CentDedEkiCont ����Ăяo����܂��B
	@param iEkiIndex
		�ǉ����ꂽ CentDedEki �̃C���f�N�X�B
	*/
	virtual void onEkiInsert( int iEkiIndex ); 
	/**
		m_CentDedEkiCont ���� CentDedEki ���폜���ꂽ����A
		m_CentDedEkiCont ����Ăяo����܂��B
	@param iEkiIndex
		�폜���ꂽ CentDedEki �̃C���f�N�X�B
	*/
	virtual void onEkiErase( int iEkiIndex  ); 
	/**
		CentDedEkiTrackCont �� CentDedEkiTrack ���ǉ����ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiIndex
		CentDedEkiTrackCont ���ǉ����ꂽ CentDedEki �̉wIndex�B
	@param iEkiTrackIndex
		�ǉ����ꂽ CentDedEkiTrack �̃C���f�N�X�B
	*/
	virtual void onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex ); 
	/**
		CentDedEkiTrackCont ���� CentDedEkiTrack ���폜���ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiIndex
		CentDedEkiTrackCont ���폜���ꂽ CentDedEki �̉wIndex�B
	@param iEkiTrackIndex
		�폜���ꂽ CentDedEkiTrack �̐擪�̃C���f�N�X�B
	*/
	virtual void onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex ); 

	/**
		CentDedRessyasyubetsuCont �� CentDedRessyasyubetsu ���ǉ����ꂽ����A
		CentDedRessyasyubetsuCont ����Ăяo����܂��B
	@param iRessyasyubetsuIndex
		�ǉ����ꂽ CentDedRessyasyubetsu  �̃C���f�N�X�B
	*/
	virtual void onRessyasyubetsuInsert( int iRessyasyubetsuIndex ); 

	/**
		CentDedRessyasyubetsuCont ���� CentDedRessyasyubetsu ���폜���ꂽ����A
		CentDedRessyasyubetsuCont ����Ăяo����܂��B
	@param iRessyasyubetsuIndex
		�폜���ꂽ CentDedRessyasyubetsu  �̃C���f�N�X�B
	*/
	virtual void onRessyasyubetsuErase( int iRessyasyubetsuIndex ); 



	///@}
	
};

} //namespace entDed





#endif /*CentDedDiaCont_h*/
