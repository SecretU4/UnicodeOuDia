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
//	CDedRessyaSoater_Transfer.h
// $Id: CDedRessyaSoater_Transfer.h 241 2016-01-05 06:14:33Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CDedRessyaSoater_Transfer_h
#define  CDedRessyaSoater_Transfer_h

#include "entDed\CentDedRosen.h"
#include "entDgr\CentDedDgrDia.h"
#include "IfProgress.h"

#include "entDed\CDedRessyaSoater.h"

namespace entDgr{

// ****************************************************************
//	CDedRessyaSoater_Transfer
// ****************************************************************
/**
@brief
	�y�T�v�z
	CentDedDia ���̗�Ԃ́w���p���\�[�g�x�������s���N���X�B
	
	�y�g�����z
	
	1.  �R���X�g���N�^�ŃI�u�W�F�N�g�𐶐���A validate() ���Ăяo����
	���������s���Ă��������B
�@�@
�@�@���@this �́A CentDedRessyaDia �ɑΉ����� CentDedDgrDia �I�u�W�F�N�g�ƁA
�@�@�\�[�g�Ώۂ̗�Ԃ̐��莞����ێ����� CentDedRessyaCont �𐶐����܂��B
	
	2.�@sort() ���\�b�h���Ăяo���ƁAthis�́A�w�肳�ꂽ��ԃR���e�i�̂��ׂĂ̗�Ԃ��\�[�g���܂��B

	3.  CentDedDia�̗�ԃR���e�i���̗�Ԃ̓��e���ω�������Athis �̓��e�͖����ɂȂ�܂�
	�@(1�{�̗�Ԃ�1�w�̉w�������ω����������ŁAthis�̓��e�͖����ɂȂ�܂�)�B
	�@���̏ꍇ�́Ainvalidate() ���Ăяo���Ĉ�U this �����������A
	 �ēx validate() ���Ăяo���āAthis�̓��e���X�V���Ȃ��Ă͂Ȃ�܂���B

*/
class CDedRessyaSoater_Transfer : public CDedRessyaSoater
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		�\�[�g�̑ΏۂƂȂ��Ԃ��W�񂷂�H���I�u�W�F�N�g�B
	*/
	const CentDedRosen* m_pDedRosen ;

	/**
		�\�[�g�̑ΏۂƂȂ��Ԃ��W�񂷂�_�C���B
	*/
	const CentDedDia* m_pDedDia ;

	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�\�[�g�Ώۂ� �w����Order�B
	*/
	CdDedJikokuOrder  m_JikokuOrder ;  



	///@}
	// ********************************
	///@name �W��
	// ********************************
	///@{
	/**
		�\�[�g�̑ΏۂƂȂ�_�C���̃I�u�W�F�N�g�B
		validate() �ŁAm_pDedRosen�� m_pDedDia ��
		���e�𔽉f���܂��B
	*/
	CentDedDgrDia m_CentDedDgrDia ;

	///@}

	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		validate() �ŏ��������Ă��� invalidate() �Ŕj������܂ł� true �B
	*/
	bool	m_bIsValid ;
	///@}
protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		�w�肳�ꂽ���ׂẴ\�[�g�O��Ԃɑ΂��āA
		�u�w��̉wOrder�ŁA�\�[�g���Ԃ���\�[�g�O��Ԃɏ抷�����ł���v
		�\�[�g���Ԃ�T���܂��B

		���̂悤�ȑg�ݍ��킹������������A
		�\�[�g�O��Ԃ̗��Index���폜���A
		�\�[�g���Ԃ̌�Ɉړ����܂��B
	@param pEstimateRessyaCont[in]
		�\�[�g�Ώۂ̗�Ԃ�ێ�����R���e�i�B
		���̗�Ԃ́ACentDedDgrDia::createEstimateRessya2()�ɂ����
		���莞�����ǉ����ꂽ��ԂłȂ��Ă͂Ȃ�܂���B
	@param pcontRessyaIndexBeforeSort [in,out] 
		�\�[�g�O��Ԃ̃C���f�N�X�̔z��
	@param pcontRessyaIndexAfterSort[in,out] 
		�\�[�g���Ԃ̃C���f�N�X�̔z��
	@param iEkiOrder[in]
		�抷�w�̉wOrder ���w�肵�Ă��������B
	@param pIfProgress [in]
		�i����Ԃ̒ʒm���󂯂����ꍇ�́A�i����Ԓʒm���󂯎��
		�C���X�^���X�ւ̃|�C���^���w�肵�Ă��������B
		NULL�Ȃ�A���̊֐��͐i����Ԃ̒ʒm���s���܂���B
	@param iMaxTransferSec[in]
		�ő�抷������(�b��)���w�肵�Ă��������B
		INT_MAX���w�肷��ƁA�������ł��B
	@return
		true: �������f���v������܂����B
	*/
	bool sortRessyaIndex_TransferFromSortedRessyaAtEki( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		int iEkiOrder , 
		int iMaxTransferSec , 
		IfProgress* pIfProgress ) ;



	/**
		�w�肳�ꂽ���ׂẴ\�[�g�O��Ԃɑ΂��āA
		�u�w��̉wOrder�ŁA�\�[�g�O��Ԃ���\�[�g���Ԃɏ抷�����ł���v
		�\�[�g���Ԃ�T���܂��B

		���̂悤�ȑg�ݍ��킹������������A
		�\�[�g�O��Ԃ̗��Index���폜���A
		�\�[�g���Ԃ̑O�Ɉړ����܂��B
	@param pEstimateRessyaCont[in]
		�\�[�g�Ώۂ̗�Ԃ�ێ�����R���e�i�B
		���̗�Ԃ́ACentDedDgrDia::createEstimateRessya2()�ɂ����
		���莞�����ǉ����ꂽ��ԂłȂ��Ă͂Ȃ�܂���B
	@param pcontRessyaIndexBeforeSort [in,out] 
		�\�[�g�O��Ԃ̃C���f�N�X�̔z��
	@param pcontRessyaIndexAfterSort[in,out] 
		�\�[�g���Ԃ̃C���f�N�X�̔z��
	@param iEkiOrder[in]
		�抷�w�̉wOrder ���w�肵�Ă��������B
	@param pIfProgress [in]
		�i����Ԃ̒ʒm���󂯂����ꍇ�́A�i����Ԓʒm���󂯎��
		�C���X�^���X�ւ̃|�C���^���w�肵�Ă��������B
		NULL�Ȃ�A���̊֐��͐i����Ԃ̒ʒm���s���܂���B
	@param iMaxTransferSec[in]
		�ő�抷������(�b��)���w�肵�Ă��������B
		INT_MAX���w�肷��ƁA�������ł��B
	@return
		true: �������f���v������܂����B
	*/
	bool sortRessyaIndex_TransferToSortedRessyaAtEki( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		int iEkiOrder , 
		int iMaxTransferSec , 
		IfProgress* pIfProgress ) ;



	/**
		�w�肳�ꂽ���ׂẴ\�[�g�O��Ԃɑ΂��āA
		�u�w��̉wOrder�Ȍ�ŁA�\�[�g���Ԃ���\�[�g�O��Ԃɏ抷�����ł���v
		�\�[�g���Ԃ����ׂĒT���܂��B

		���̂悤�ȑg�ݍ��킹������������A
		�\�[�g�O��Ԃ̗��Index���폜���A
		�\�[�g���Ԃ̌�Ɉړ����܂��B
	@param pEstimateRessyaCont[in]
		�\�[�g�Ώۂ̗�Ԃ�ێ�����R���e�i�B
		���̗�Ԃ́ACentDedDgrDia::createEstimateRessya2()�ɂ����
		���莞�����ǉ����ꂽ��ԂłȂ��Ă͂Ȃ�܂���B
	@param pcontRessyaIndexBeforeSort [in,out] 
		�\�[�g�O��Ԃ̃C���f�N�X�̔z��
	@param pcontRessyaIndexAfterSort[in,out] 
		�\�[�g���Ԃ̃C���f�N�X�̔z��
	@param iEkijikokuOrder[in]
		�\�[�g�̃L�[�ƂȂ�A�wOrder ���w�肵�Ă��������B
	@param pIfProgress [in]
		�i����Ԃ̒ʒm���󂯂����ꍇ�́A�i����Ԓʒm���󂯎��
		�C���X�^���X�ւ̃|�C���^���w�肵�Ă��������B
		NULL�Ȃ�A���̊֐��͐i����Ԃ̒ʒm���s���܂���B
	@return
		true: �������f���v������܂����B
	*/
	bool sortRessyaIndex_TransferFromSortedRessya( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		CdDedJikokuOrder aEkijikokuOrder  , 
		IfProgress* pIfProgress ) ;

	/**
		�w�肳�ꂽ���ׂẴ\�[�g�O��Ԃɑ΂��āA
		�u�w��̉wOrder�ȑO�ŁA�\�[�g�O��Ԃ���\�[�g���Ԃɏ抷�����ł���v
		�\�[�g���Ԃ����ׂĒT���܂��B

		���̂悤�ȑg�ݍ��킹������������A
		�\�[�g�O��Ԃ̗��Index���폜���A
		�\�[�g���Ԃ̑O�Ɉړ����܂��B
	@param pEstimateRessyaCont[in]
		�\�[�g�Ώۂ̗�Ԃ�ێ�����R���e�i�B
		���̗�Ԃ́ACentDedDgrDia::createEstimateRessya2()�ɂ����
		���莞�����ǉ����ꂽ��ԂłȂ��Ă͂Ȃ�܂���B
	@param pcontRessyaIndexBeforeSort [in,out] 
		�\�[�g�O��Ԃ̃C���f�N�X�̔z��
	@param pcontRessyaIndexAfterSort[in,out] 
		�\�[�g���Ԃ̃C���f�N�X�̔z��
	@param iEkijikokuOrder[in]
		�\�[�g�̃L�[�ƂȂ�A�wOrder ���w�肵�Ă��������B
	@param pIfProgress [in]
		�i����Ԃ̒ʒm���󂯂����ꍇ�́A�i����Ԓʒm���󂯎��
		�C���X�^���X�ւ̃|�C���^���w�肵�Ă��������B
		NULL�Ȃ�A���̊֐��͐i����Ԃ̒ʒm���s���܂���B
	@return
		true: �������f���v������܂����B
	*/
	bool sortRessyaIndex_TransferToSortedRessya( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		CdDedJikokuOrder aEkijikokuOrder , 
		IfProgress* pIfProgress ) ;
	///@}

	/**
		�����w��2�̉w�����Ƃ̊Ԃł̏�芷�����Ԃ��v�Z���܂��B
	@param aEkijikokuFrom [in]
		��芷�����̗�Ԃ̉w�������w�肵�Ă��������B
	@param aEkijikokuTo [in]
		��芷����̗�Ԃ̉w�������w�肵�Ă��������B
	@param jikokuKitenJikoku [in]
		�_�C���O�����N�_�������w�肵�Ă��������B
		���̊֐��́A���̎������z�����芷���͕s�\�Ƃ݂Ȃ��܂��B
		(��F���̎�����5:00���w�肳�ꂽ�ꍇ�́A5:00<23:59<0:00<4:59 �Ƃ��Ĕ�r���s���܂�)
	@return
		�����w��2�̉w�����Ƃ̊Ԃł̏�芷������(�b��)��Ԃ��܂��B
		��芷���s�\�ȏꍇ�� -1 ��Ԃ��܂��B

		�ȉ��̏ꍇ�͏�芷���s�\�Ƃ��āA-1��Ԃ��܂��B	
			- �ǂ��炩�̉w�����u��ԁv�łȂ��ꍇ�B
	*/
	static int calcNorikaeSec( 
		const CentDedEkiJikoku& aEkiJikokuFrom , 
		const CentDedEkiJikoku& aEkiJikokuTo ,
		const CdDedJikoku& jikokuKitenJikoku ) ;
protected:
	// ================================
	///@name CDedRessyaSoater::sort �̉����֐�
	// ================================
	///@{
	/**
		�w�肳�ꂽ���Index���\�[�g���܂��B
	@param pRessyaCont [in]
		�\�[�g�Ώۂ̗�ԃR���e�i���w�肵�Ă��������B
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
		sortWithSortedRessyaIndex() �ɓn�����Ƃɂ��A
		��ԃR���e�i���\�[�g���邱�Ƃ��ł��܂��B

	*/
	virtual void sortRessyaIndex( 
		const CentDedRessyaCont* pRessyaCont , 
		Mui<int>* muRessyaIndexOrder , 
		IfProgress* pIfProgress )  ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
�@	@param pDedRosen [in]
		�\�[�g�̑ΏۂƂȂ��Ԃ��W�񂷂�H���I�u�W�F�N�g�B
	@param iDiaIndex [in]
		�\�[�g�̑ΏۂƂȂ��Ԃ��W�񂷂�_�C���B
	@param aCdDedJikokuOrder[in]
		�\�[�g�Ώۂ� �w����Order�B
	*/
	CDedRessyaSoater_Transfer(
		const CentDedRosen* pDedRosen , 
		const CentDedDia* pDedDia ,
		CdDedJikokuOrder  aCdDedJikokuOrder ) ;  

	virtual ~CDedRessyaSoater_Transfer() ;
	
public:
	// ********************************
	///@name CDedRessyaSoater_Transfer-����
	// ********************************
	///@{
	///@}
	// ********************************
	///@name CDedRessyaSoater_Transfer-�W��
	// ********************************
	///@{
	///@}
	// ********************************
	///@name CDedRessyaSoater_Transfer-����-IfValidate
	// ********************************
	///@{
	/**
	 	�@�I�u�W�F�N�g�̏����������s���A�L�������܂��B
	 	�@���������ɂ������ĕK�v�ȃp�����[�^�́A�R���X�g���N�^�Ȃǂ�
	 	�w�肵�Ă���
	 	�K�v������܂��B
	 @return
	 	�@�L�����ɐ���������P�ȏ�A
	 	�@���łɗL�������I�����Ă����ꍇ�͂O�A
	 	�@�G���[�̏ꍇ�͕��̐���Ԃ��܂��B\n
	 	�@���������Ƃ��̂P�ȏ�̒l�̈Ӗ��́A��������N���X�����R�ɒ�`
	 	�ł��܂��B\n
	 	�@���s�����Ƃ��̕��̐��̈Ӗ����A�����N���X����`�ł��܂��B����ɂ��A
	 	���s�̗��R���ƂɈقȂ�G���[�l��Ԃ����Ƃ��ł��܂��B
	 	
	 */
	virtual int validate()  ;
	
	/**
	 	�@�I�u�W�F�N�g�𖳌������܂��B
	 	�@�L�������Ɋm�ۂ������\�[�X���J�����܂��B
	 	  �L����ԂłȂ��I�u�W�F�N�g�ɑ΂��ẮA�Ȃɂ����܂���B
	 */
	virtual void invalidate() ;
	
	/**
	 @return
	 	�@���݃I�u�W�F�N�g���L����Ԃł���ΐ^��Ԃ��܂��B
	 */
	virtual bool isValid() ;
	///@}



};

} //namespace entDgr


#endif /*CDedRessyaSoater_Transfer_h*/
