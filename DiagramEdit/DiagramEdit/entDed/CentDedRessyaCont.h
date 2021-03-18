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
//	CentDedRessyaCont.h
// $Id: CentDedRessyaCont.h 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessyaCont_h
#define  CentDedRessyaCont_h

#include "NsMu/CMuiCopiedParent.h"
#include "CentDed.h"
#include "CentDedRessya.h"

namespace entDed{

//�O���Q��
class CentDedRosen ;
class CentDedDia ;


// ****************************************************************
//	CentDedRessyaCont
// ****************************************************************
/**
@brief
�w��ԃR���e�i�x�N���X�B
�����H���ɑ����铯�������́A0�ȏ㕡���́w��ԁx(CentDedRessya) 
�I�u�W�F�N�g��ێ�����R���e�i�ł��B

���̃N���X���̂́A Mui< CentDedRessya > �C���^�[�t�F�[�X��
�T�|�[�g���܂��B���̃C���^�[�t�F�[�X�ɂ��A CentDedRessya �I�u�W�F�N�g��
�ǉ��E�폜���邱�Ƃ��ł��܂��B

�܂��A getMuPtr() ���\�b�h�ɂ��A
Mu< CentDedRessya* > �C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
���̃C���^�[�t�F�[�X�ɂ��A�R���e�i���� CentDedRessya �I�u�W�F�N�g��
���ڃA�N�Z�X�i���\�b�h�ďo�j���s�����Ƃ��ł��܂��B

����
 -------------------------------- 
�����̃R���e�i�� CentDedRosen �̎q�I�u�W�F�N�g�ł���ꍇ�A
m_iEkiCount �� m_iRessyasyubetsuCount �́ACentDedRosen�ɍ��킹�܂��B

�����̃R���e�i�� CentDedDia �̎q�I�u�W�F�N�g�ł���ꍇ�A
m_eRessyahoukou �͕ύX�ł��Ȃ�(��O�X���[)

����̃G���[�����E�C��
 -------------------------------- 

��onEkiInsert,onEkiErase : m_iEkiCount ���C������
��onRessyasyubetsuInsert,onRessyasyubetsuErase : m_iRessyasyubetsuCount ���C������

��operator= : ���̃R���e�i�� CentDedDia �̎q�I�u�W�F�N�g�ł���ꍇ�A
m_iEkiCount,m_iRessyasyubetsuCount,m_eRessyahoukou �͕ύX���ꂸ�A��Ԃ�����
�R�s�[����܂��B(�R�s�[���ꂽ��Ԃ� adjust() �ɂ��ARessyaCont�ɓK������
�w���E��Ԏ�ʁE�����ɂȂ�܂��B)



����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 
�����̃R���e�i�� CentDedRosen �̎q�I�u�W�F�N�g�ł���ꍇ�A
m_iEkiCount �� m_iRessyasyubetsuCount �́ACentDedRosen�ɍ��킹�܂��B


�����ׂĂ�CentDedRessya(���)�ɁAadjust()���Ϗ�����B


 */
class CentDedRessyaCont : public CMuiCopiedParent< CentDedRessya >
{
	typedef CMuiCopiedParent< CentDedRessya > super ;
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	
	/**
		���̃R���e�i�Ɋ܂܂���Ԃ́w�w�����x�̐��i�_�C���Ɋ܂܂��w�̐��j�B
		����l��0�B
	
		�����̃R���e�i�� CentDedRosen �̎q�I�u�W�F�N�g�ł���ꍇ�A
		m_iEkiCount �� m_iRessyasyubetsuCount �́ACentDedRosen�ɍ��킹�܂��B

		CentDedRosen�̎q�łȂ��A�Ɨ������C���X�^���X�ɂ����ẮA�R���X�g���N�^�Ŏw�肷�邱�Ƃ�
		�ł��܂��B

		���̒l�́A�ȉ��̊֐��Ŏg���܂��B
		
		EkiIndexOfEkiOrder,EkiOrderOfEkiIndex,createEmptyCont,createNullRessya 
	
	 */
	int m_iEkiCount ;
	
	/**
		���̃R���e�i�Ɋi�[�����w��ԁx�̗�ԕ����B
		-	���� :	Ressyahoukou_Kudari 
		-	��� : 	Ressyahoukou_Nobori 
		�R���X�g���N�^�Ō��܂�܂��B
	 */
	ERessyahoukou m_eRessyahoukou ;
	

	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/** 
	 @param eRessyahoukou [in]
		���̃R���e�i�Ɋi�[�����w��ԁx�̗�ԕ����B
		-	���� :	Ressyahoukou_Kudari 
		-	��� : 	Ressyahoukou_Nobori 
	*/
	CentDedRessyaCont( ERessyahoukou m_eRessyahoukou ) ;

	/**
	 @param iEkiCount [in]]
		�w��ԃR���e�i�x�Ɋ܂܂��w�̐��B
	 @param eRessyahoukou [in]
		���̃R���e�i�Ɋi�[�����w��ԁx�̗�ԕ����B
		-	���� :	Ressyahoukou_Kudari 
		-	��� : 	Ressyahoukou_Nobori 
	 */
	CentDedRessyaCont( 
		int iEkiCount ,
		ERessyahoukou m_eRessyahoukou ) ;

public:
	/**
		���̃N���X�ւ̑�����s���܂����A
		this �w�w�x�w��Ԏ�ʁx�w��ԕ����x�͕ύX���܂���B
	 */
	CentDedRessyaCont& operator=( const CentDedRessyaCont& value );
public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f�̃R�s�[��ǉ����܂��B
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
	virtual int insert( const CentDedRessya& element , int iIndex = INT_MAX ) ;
	
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
	*/
	virtual int set( const CentDedRessya& element , int iIndex ) ;
	///@}
 public:
	// ********************************
	///@name CentDedRessyaCont-����
	// ********************************
	///@{
	ERessyahoukou getRessyahoukou()const{	return m_eRessyahoukou ;};
	int getEkiCount()const{	return m_iEkiCount ;};
	///@}

 public:
	// ********************************
	///@name CentDedRessyaCont-�֘A
	// ********************************
	///@{
	/**
	@return
		���̃R���e�i�� CentDedDia �ɕ�܂���Ă���ꍇ�́A
		CentDedDia �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	 virtual CentDedDia* getDia(){ return NULL ;}
	/**
	@return
		���̃R���e�i�� CentDedRessya �ɕ�܂���Ă���ꍇ�́A
		CentDedRessya �̃A�h���X�B
		�����łȂ��Ȃ�NULL�B
	*/
	virtual const CentDedDia* getDia()const{ return NULL ;}

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
	///@name CentDedRessyaCont-����
	// ********************************
	/**
		set() ���\���ۂ��𔻒f���܂��B

	@param element
		�v�f���w�肵�Ă��������B 
	@param iIndex
		�O����n�܂�C���f�N�X���w�肵�Ă��������B �͈͂͂O�ȏ� size() 
		�����ł��B �A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B 
	@return
		-	0�ȏ�: set() ���\�B
		-	���̐�: set()�́A���̖߂�l�Ŏ��s���܂��B
	 */
	virtual int  setable(  const CentDedRessya& element , int iIndex )const ;

	/**
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
	@param element
		�v�f���w�肵�Ă��������B 
	@return
		element �����̃R���e�i�̎q�ł���ꍇ�́A�C���f�N�X��Ԃ��܂��B
		�����łȂ��ꍇ�́A -1 �ł��B
	*/
	virtual int  getIndex( const CentDedRessya* element )const ;
	/**
		this �̑���������ɔ����Ă���ꍇ�A����ɍ����悤�ɁA������
		�C�����܂��B

		�����ׂĂ�CentDedRessya(���)�ɁAadjust()���Ϗ�����B
	*/
	void adjust() ;

	/**
		�w�wOrder(�w������Index)�x���A�w�wIndex�x�ɕϊ����܂��B
	 @param iEkiOrder [in]
		�w�wOrder�x���w�肵�Ă��������B
	 @return 
		0�ȏ�́w�wIndex�x��Ԃ��܂��B
		�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	virtual int EkiIndexOfEkiOrder( int iEkiOrder )const ;
	
	/**
		�w�wIndex�x���w�wOrder(�w������Index)�x�ɕϊ����܂��B
	 @param iEkiIndex [in]
		�w�wIndex�x���w�肵�Ă��������B
	 @return 
		0�ȏ�́w�wOrder�x��Ԃ��܂��B
		�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	virtual int EkiOrderOfEkiIndex( int iEkiIndex )const ;

	/**
		pCentDedRessyaCont �Ɋi�[����Ă����Ԃ̂����A
		 iEkiOrder �̉w�Ǝ��̉w�̊Ԃ̉w�ԍŏ����v�b���̗�Ԃ�
		�������A���̏��v���Ԃ����߂܂��B
	 @param iEkiOrder [in]
		�ŏ����v�b�����v�Z����w�́A
		�w�wOrder�x���w�肵�Ă��������B
	 @param pidxRessya [out]
		���̊֐��͂����ɁA�w�ԍŏ����v�b���̗�Ԃ̗�ԃC���f�N�X��
		�������݂܂��B
		�w�ԍŏ����v�b���̗�Ԃ��݂���Ȃ��ꍇ�A���̊֐��͂��̕ϐ���
		-1 ���������݂܂��B
	 @return
		�w�ԍŏ����v�b����Ԃ��܂��B
		�w�ԍŏ����v�b���̗�Ԃ��݂���Ȃ��ꍇ�A���̊֐���
		����l�� 0 ��Ԃ��܂��B
		
		  �ׂ荇���`�w�Ƃa�w�̊Ԃ́w�w�ԍŏ����v�b���x�́A�u���w�ɒ�Ԃ���
		��Ԃ̂����A�`�w�̔������Ƃa�w�̒��������ł��Z�����́v�ƂȂ�܂��B
		  ���̂Ƃ��A�`�w�̒��������w�肳��Ă��Ĕ��������ȗ�����Ă���ꍇ�́A
		���������������Ƃ݂Ȃ��܂��B�܂��A�a�w�̒��������ȗ�����Ă��Ĕ�������
		�w�肳��Ă���ꍇ���A���������������Ƃ݂Ȃ��܂��B
		
		  ���w�ɒ�Ԃ����Ԃ��ЂƂ��Ȃ��ꍇ�́A�`�w�E�a�w��ʉ߂����Ԃ�
		�w�肳��Ă���ʉߎ��������ƂɁA�w�ԍŏ����v�b�������߂܂��B���̏ꍇ�A
		�����ΏۂƂȂ�̂́A�ȉ��̂��ׂĂ̗�Ԃł��B
		
			- �`�w��ʉ�(�ʉߎ����w�肠��)�E�a�w��ʉ�(�ʉߎ����w�肠��)
			- �`�w�ɒ��                  �E�a�w��ʉ�(�ʉߎ����w�肠��)
			- �`�w��ʉ�(�ʉߎ����w�肠��)�E�a�w�ɒ��
	 */
	virtual int findEkikanSaisyouSec( 
		int iEkiOrder , 
		int* pidxRessya )const ;

	/**
		�w��̗��Index ���H����ŉ^�s����Ă���Ō�̉w
		(getRunLastEkiOrder())�̉w������肠�ƂŁA
		iEkiOrder ���ŏ��̉^�s�w(getRunFirstEkiOrder())
		�Ƃ����Ԃ��������܂��B
		����́A[���ʉ�]�̑Ώۂ̌����ɑ������܂��B
	@param idxRessya [in]
		�����̐擪�ƂȂ�A���Index���w�肵�Ă��������B
	@param iEkiOrder [in]
		�n���w�̉wOrder���w�肵�Ă��������B
	@return
		�ΏۂƂȂ��Ԃ̗��Index ��Ԃ��܂��B
		������Ȃ��ꍇ�́A -1 ��Ԃ��܂��B


�@	  ���ʉ��̑ΏۂƂȂ�r���w�n����Ԃ́A�ȉ��̏����𖞂�������Ԃł��B

�@	  - �E�t�H�[�J�X�̂�����(�r���w�~�܂�̗��)�Ɠ�����Ԏ��
�@	  - �E�t�H�[�J�X�̂���w���ŏ��̉^�s��ԂƂȂ���
�@	  - �E[�n���w�̔������E�I����Ԃ̒������̗������L���ȏꍇ��] \n
		�n���w�̔��������A�I����Ԃ̒���������12���Ԉȓ�
�@	  - �E�����\�r���[��ŁA�t�H�[�J�X�̂����Ԃ̉E���ɂ�����

�@	  �ΏۂƂȂ��Ԃ���������ꍇ�́A���̒��ł����Ƃ������ɂ����Ԃ𒼒ʉ��̑ΏۂƂ��܂��B
		
	*/
	virtual int findTrainToDirect(
		int idxRessya , 
		int iEkiOrder  ) const ;  

	/**
		�w��̉w Order �̉w�������A
		�w�����`���E�n���E�I���ɍ��킹�ĕύX���܂��B

		�ύX���e�́A CentDedEkiJikoku::adjustByEkijikokukeisiki 
		�̐������Q�Ƃ��Ă��������B

	@see CentDedEkiJikoku::adjustByEkijikokukeisiki 

	@param iEkiOrder [in]
		�wOrder���w�肵�Ă��������B
	@param bChakujikokuHyouji [in]
		�w�����`���B
		�������\������B
	@param bHatsujikokuHyouji [in]
		�w�����`���B
		�������\������B
	*/
	void adjustByEkijikokukeisiki(
		int iEkiOrder ,
		bool bChakujikokuHyouji , bool bHatsujikokuHyouji ) ;

	///@}

	// ********************************
	///@name CentDedRessyaCont-�w���E��Ԏ�ʐ��̕ύX
	// ********************************
	///@{


	/**
		���̃R���e�i�ɁA�w�肳�ꂽ�w��Ԏ�ʁx�̗�Ԃ����邩�ۂ��𒲂ׂ܂��B
		���� m_iEkiCount,m_eRessyahoukou,m_iRessyasyubetsuCount �́A
		this�̂��̂��󂯌p���܂��B
	 @param iRessyasyubetsuIndex [in]
		�w��Ԏ��Index�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ� ��Ԏ�ʂ̐������ł��B
		INT_MAX �́A�����̗�Ԏ�ʂ��w�肵�����̂Ƃ݂Ȃ��܂��B
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
		int* piRessyaIndex ) ;
	///@}

	// ********************************
	///@name CentDedRessyaCont-�V�����R���e�i�𐶐�
	// ********************************
	///@{
	/**
		���̃R���e�i�ƌ݊����̂���ANULL��Ԃ𐶐����܂��B

		���� m_iEkiCount , m_eRessyahoukou , m_iRessyasyubetsuCount �́A
		this�̂��̂��󂯌p���܂��B
	@return
		������������R���e�i��Ԃ��܂��B
	@todo
		���N���X���ł́ACentDedRessya�R���X�g���N�^
		CentDedRessya( m_iEkiCount , m_eRessyahoukou )  �Ăяo����u�������܂��B
	 */
	CentDedRessya createNullRessya() const
	{	return CentDedRessya( m_iEkiCount , m_eRessyahoukou ) ;}

	/**
		this �ƌ݊����̂���A�V���ȋ�R���e�i��
		�������܂��B

		���� m_iEkiCount , m_eRessyahoukou , m_iRessyasyubetsuCount �́A
		this�̂��̂��󂯌p���܂��B
	@return
		������������R���e�i��Ԃ��܂��B
	@todo
		CentDedRessyaCont�R���X�g���N�^
		CentDedRessyaCont( m_iEkiCount , m_eRessyahoukou , m_iRessyasyubetsuCount )
		�Ăяo����u�������܂��B
	 */
	CentDedRessyaCont createEmptyCont() const
	{
		return CentDedRessyaCont( m_iEkiCount ,
			m_eRessyahoukou ) ;	
	}
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
		CentDedEkiTrackCont ���ǉ����ꂽ CentDedEki �̉wOrder(�w�C���f�N�X�ł͂���܂���)
	@param iEkiTrackIndex
		�ǉ����ꂽ CentDedEkiTrack �̃C���f�N�X�B
	*/
	virtual void onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex ); 
	/**
		CentDedEkiTrackCont ���� CentDedEkiTrack ���폜���ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiOrder
		CentDedEkiTrackCont ���폜���ꂽ CentDedEki �wOrder(�w�C���f�N�X�ł͂���܂���)
	@param iEkiTrackIndex
		�폜���ꂽ CentDedEkiTrack �̐擪�̃C���f�N�X�B
	*/
	virtual void onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex ); 

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

#endif /*CentDedRessyaCont_h*/
