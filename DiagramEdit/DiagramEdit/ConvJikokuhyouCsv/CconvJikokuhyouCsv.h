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
// $Id: CconvJikokuhyouCsv.h 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
#ifndef  CconvJikokuhyouCsv_h
#define  CconvJikokuhyouCsv_h
/** @file */
#include "..\DedRosenFileData\CDedRosenFileData.h"
#include "Str\CsvDocument\CdCsvDocument.h"

namespace ConvJikokuhyouCsv{
using namespace entDed ;
using namespace OuLib::Str::CsvDocument;

/**
@brief
	�����\�`��CSV�t�@�C���Ƃ̊Ԃ̃f�[�^�ϊ����s���܂��B

	CentDedRosen�ƁA�����\�`����CSV�t�@�C���𐶐����܂��B

	���΂ɁACentDedRosen�ɁA�����\�`����CSV�t�@�C���̓��e����荞��
	���Ƃ��ł��܂��B
*/
class CconvJikokuhyouCsv
{
private:
	/// CSV��̌Œ蕶����u����v
	std::string m_nameKudari ;
	/// CSV��̌Œ蕶����u���v
	std::string m_nameNobori ;
	/// CSV��̌Œ蕶����u��Ԕԍ��v
	std::string m_nameRessyabangou ;
	/// CSV��̌Œ蕶����u��Ԏ�ʁv
	std::string m_nameRessyasyubetsu ;
	/// CSV��̌Œ蕶����u��Ԗ��v
	std::string m_nameRessyamei ;
	/// CSV��̌Œ蕶����u�����v
	std::string m_nameGousuu ;
	/// CSV��̌Œ蕶����u���v
	std::string m_nameGou ;
	/// CSV��̌Œ蕶����u���l�v
	std::string m_nameBikou ;
	/// CSV��̌Œ蕶����u���v
	std::string m_nameChaku ;
	/// CSV��̌Œ蕶����u���v
	std::string m_nameHatsu ;
	/// CSV��̌Œ蕶����u���v
	std::string m_nameTsuuka ;
	/// CSV��̌Œ蕶����u||�v
	std::string m_nameKeiyunasi ;
protected:
	// --------------------------------
	///@name	�w�����Z���̕�����̉���
	// --------------------------------
	///@{
	/**
		�w���Ǝ��������ƂɁA������CSV�����ɕ����񉻂��܂��B
		
	@param eEkiatsukai [in]
		�w�����w�肵�Ă��������B
	@param aCdDedJikoku [in]
		�������w�肵�Ă��������B
		
		eEkiatsukai ��
		CentDedEkiJikoku::Ekiatsukai_None,
		CentDedEkiJikoku::Ekiatsukai_Keiyunasi 
		�ł���ꍇ�́AaCdDedJikoku �͕]������܂���B
		
		eEkiatsukai��
		CentDedEkiJikoku::Ekiatsukai_Teisya, 
		�̏ꍇ�́A�ʏ�Ɏ������o�͂��܂��B
		
		eEkiatsukai��
		CentDedEkiJikoku::Ekiatsukai_Tsuuka, 
		�ŁAaCdDedJikoku �� Null �łȂ��ꍇ�́A
		�����̖����� "?" ��t�^���܂��B
	@return
		�ϊ����ꂽ�������Ԃ��܂��B
	*/
	std::string encode_Ekijikoku( 
		CentDedEkiJikoku::EEkiatsukai eEkiatsukai , 
		const CdDedJikoku& aCdDedJikoku ) ;

	/**
		CSV�̉w�����Z���̓��e�����߂��܂��B
		
	@param pEkiatsukai [out]
		���̊֐��͂����ɁA���ߌ��ʂ̉w�����������݂܂��B
	@param pCdDedJikoku [out]
		���̊֐��͂��̃A�h���X�ɁA���ߌ��ʂ̎������������݂܂��B
	@param strEkijikoku [in]
		�w�����̕�������w�肵�Ă��������B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�����̉��߂Ɏ��s���܂����B
	*/
	int  decode_Ekijikoku( 
		CentDedEkiJikoku::EEkiatsukai* pEkiatsukai , 
		CdDedJikoku* pCdDedJikoku , 
		const std::string& strEkijikoku ) ;
	///@}
	// --------------------------------
	///@name encode() �̉����֐�	
	// --------------------------------
	///@{


	/**
		�w�ꗗ�����ƂɁA
		�����\Index-����Order�ΏƔz��𐶐����܂��B
	@param pCentDedEkiCont [in]
		�w�R���e�i���w�肵�Ă��������B
	@param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
	@param pcontiJikokuOrderOfJikokuhyouIndex [out]
		���̊֐��͂��̃R���e�i�ɁA
		�����\Index-����Order�ΏƔz��𐶐����܂��B

		 *pcontiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order>
	
	*/
	void encode_createContJikokuOrderOfJjikokuhyouIndex( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou eRessyahoukou , 
		std::deque<CdDedJikokuOrder>*	pcontiJikokuOrderOfJikokuhyouIndex ) ;

	/**
		CdCsvDocument �ɁANull�łȂ���Ԃ�ǉ����܂��B

		��Ԃ̐ݒ�ɂ������ẮA
		�����\Index-����Order�ΏƔz����w�肷��K�v������܂��B
		���̔z��́A�ȉ��̌`���łȂ��Ă͂Ȃ�܂���B

		 contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order>
	
	  CdCsvDocument �́A�ȉ��̏����𖞂����Ă��Ȃ��Ă͂Ȃ�܂���B
		
		- �ȉ��̗񂪐ݒ肳��Ă���
			- 1�s�� FileType�s
			- 2�s�� DiaName�s
			- ��2.3�� 3�s�� <����,���>
			- ��2.4��4�s�� 
		- �񐔂́A contiJikokuOrderOfJikokuhyouIndex.size() + 10 

	  ���̊֐��́A�sIndex4�ɗ�Ԕԍ���ݒ肵�A
	  �sIndex (9+ contiJikokuOrderOfJikokuhyouIndex.size() ) ��
	���l��ݒ肵�܂��B

	@param pCentDedRessyasyubetsuContGet [in]
		��Ԏ�ʃR���e�i���w�肵�Ă��������B
	@param contiJikokuOrderOfJikokuhyouIndex [in] 
		�����\Index-����Order�ΏƔz����w�肵�Ă��������B
	@param pCentDedRessya [in]
		��Ԃ��w�肵�Ă��������B
	@param pCdCsvDocument [in,out]
		���̊֐��͂���CSV�h�L�������g�ɗ�ԏ���ǉ����܂��B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	���̗�Ԃ�NULL�ł��B
	*/
	int encode_AddRessya( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const std::deque<CdDedJikokuOrder>&	contiJikokuOrderOfJikokuhyouIndex , 
		const CentDedRessya* pCentDedRessya , 
		CdCsvDocument* pCdCsvDocument ) ;

	/**
		CdCsvDocument �ɁANull��Ԃ�ǉ����܂��B

		��Ԃ̐ݒ�ɂ������ẮA
		�����\Index-����Order�ΏƔz����w�肷��K�v������܂��B
		���̔z��́A�ȉ��̌`���łȂ��Ă͂Ȃ�܂���B

		 contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order>
	
	  CdCsvDocument �́A�ȉ��̏����𖞂����Ă��Ȃ��Ă͂Ȃ�܂���B
		
		- �ȉ��̗񂪐ݒ肳��Ă���
			- 1�s�� FileType�s
			- 2�s�� DiaName�s
			- ��2.3�� 3�s�� <����,���>
			- ��2.4��4�s�� 
		- �񐔂́A contiJikokuOrderOfJikokuhyouIndex.size() + 10 

	  ���̊֐��́A�sIndex4�ɗ�Ԕԍ���ݒ肵�A
	  �sIndex (9+ contiJikokuOrderOfJikokuhyouIndex.size() ) �ɔ��l��ݒ肵�܂��B

	@param contiJikokuOrderOfJikokuhyouIndex [in] 
		�����\Index-����Order�ΏƔz����w�肵�Ă��������B
	@param pCdCsvDocument [in,out]
		���̊֐��͂���CSV�h�L�������g�ɗ�ԏ���ǉ����܂��B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	���0
	*/
	int encode_AddRessyaNull( 
		const std::deque<CdDedJikokuOrder>&	contiJikokuOrderOfJikokuhyouIndex , 
		CdCsvDocument* pCdCsvDocument ) ;

	///@}
	// --------------------------------
	///@name decode() �̉����֐�	
	// --------------------------------
	///@{

	/**
		�w�ꗗ��CdCsvDocument�����ƂɁA
		�����\Index-����Order�ΏƔz��𐶐����܂��B
	@param pCentDedEkiCont [in]
		�w�R���e�i���w�肵�Ă��������B
	@param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
	@param pCdCsvDocument [in]
		���̊֐��͂���CSV�h�L�������g�ɗ�ԏ���ǉ����܂��B
	@param pcontiJikokuOrderOfJikokuhyouIndex [out]
		���̊֐��͂��̃R���e�i�ɁA
		�����\Index-����Order�ΏƔz��𐶐����܂��B
	@param pstrErrorInfoString [out]
		�G���[�Ȃ�A�G���[���e�L�X�g��Ԃ��܂��B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�w����������܂���B
		
		 *pcontiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order>
	*/
	int decode_createContJikokuOrderOfJjikokuhyouIndex( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou eRessyahoukou , 
		const CdCsvDocument* pCdCsvDocument , 
		std::deque<int>*	pcontiJikokuOrderOfJikokuhyouIndex ,
		std::string* pstrErrorInfoString ) ;

	/**
		CdCsvDocument �̎w��̗��ǂݍ��݁A
		���̓��e�� CentDedRessya �Ɏw�肵�܂��B

		��Ԃ̐ݒ�ɂ������ẮA
		�����\Index-����Order�ΏƔz����w�肷��K�v������܂��B
		���̔z��́A�ȉ��̌`���łȂ��Ă͂Ȃ�܂���B

		 contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order>
	
	  CdCsvDocument �́A�ȉ��̏����𖞂����Ă��Ȃ��Ă͂Ȃ�܂���B
		
		- �ȉ��̗񂪐ݒ肳��Ă���
			- 1�s�� FileType�s
			- 2�s�� DiaName�s
			- ��2.3�� 3�s�� <����,���>
			- ��2.4��4�s�� 
		- �񐔂́A contiJikokuOrderOfJikokuhyouIndex.size() + 10 

	  ���̊֐��́A�sIndex4�ɗ�Ԕԍ��A
	  �sIndex (9+ contiJikokuOrderOfJikokuhyouIndex.size() ) ��
	���l��������̂Ƃ��ĉ��߂��s���܂��B�B

	@param pCentDedRessyasyubetsuContGet [in]
		��Ԏ�ʃR���e�i���w�肵�Ă��������B
	@param contiJikokuOrderOfJikokuhyouIndex [in] 
		�����\Index-����Order�ΏƔz����w�肵�Ă��������B
	@param pCentDedRessya [out]
		��Ԃ��w�肵�Ă��������B
	@param pCdCsvDocument [in]
		CSV�h�L�������g���w�肵�Ă��������B
	@param iColumnIndex [in]
		pCdCsvDocument �̗� Index ���w�肵�Ă��������B
	@param pstrErrorInfoString [out]
		�G���[�Ȃ�A�G���[���e�L�X�g��Ԃ��܂��B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	int decode_readRessyaColumn( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const std::deque<int>&	contiJikokuOrderOfJikokuhyouIndex , 
		CentDedRessya* pCentDedRessya , 
		const CdCsvDocument* pCdCsvDocument , 
		int iColumnIndex ,
		std::string* pstrErrorInfoString ) ;

	/**
		CdCsvDocument �̎w��̗� Null ��ԁiCSV�ɉ���������Ă��Ȃ��j
		�ł��邩�ۂ��𔻒肵�܂��B

		��Ԃ̐ݒ�ɂ������ẮA
		�����\Index-����Order�ΏƔz����w�肷��K�v������܂��B
		���̔z��́A�ȉ��̌`���łȂ��Ă͂Ȃ�܂���B

		 contiJikokuOrderOfJjikokuhyouIndex[<�����\Index>]=<����Order>
	
	  CdCsvDocument �́A�ȉ��̏����𖞂����Ă��Ȃ��Ă͂Ȃ�܂���B
		
		- �ȉ��̗񂪐ݒ肳��Ă���
			- 1�s�� FileType�s
			- 2�s�� DiaName�s
			- ��2.3�� 3�s�� <����,���>
			- ��2.4��4�s�� 
		- �񐔂́A contiJikokuOrderOfJikokuhyouIndex.size() + 10 

	  ���̊֐��́A�sIndex4�ɗ�Ԕԍ��A
	  �sIndex (9+ contiJikokuOrderOfJikokuhyouIndex.size() ) ��
	���l��������̂Ƃ��ĉ��߂��s���܂��B�B

	@param pCentDedRessyasyubetsuContGet [in]
		��Ԏ�ʃR���e�i���w�肵�Ă��������B
	@param contiJikokuOrderOfJikokuhyouIndex [in] 
		�����\Index-����Order�ΏƔz����w�肵�Ă��������B
	@param pCentDedRessya [out]
		��Ԃ��w�肵�Ă��������B
	@param pCdCsvDocument [in]
		CSV�h�L�������g���w�肵�Ă��������B
	@param iColumnIndex [in]
		pCdCsvDocument �̗� Index ���w�肵�Ă��������B
	@param pstrErrorInfoString [out]
		�G���[�Ȃ�A�G���[���e�L�X�g��Ԃ��܂��B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	���̗��Null��Ԃł��B
		-	0 ;	//	���̗��Null��Ԃł͂���܂���B
	*/
	int decode_isNullRessyaColumn( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const std::deque<int>&	contiJikokuOrderOfJikokuhyouIndex , 
		CentDedRessya* pCentDedRessya , 
		const CdCsvDocument* pCdCsvDocument , 
		int iColumnIndex ,
		std::string* pstrErrorInfoString ) ;

	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CconvJikokuhyouCsv(
		const std::string& nameKudari ,
		const std::string& nameNobori ,
		const std::string& nameRessyabangou ,
		const std::string& nameRessyasyubetsu ,
		const std::string& nameRessyamei ,
		const std::string& nameGousuu ,
		const std::string& nameGou ,
		const std::string& nameBikou ,
		const std::string& nameChaku ,
		const std::string& nameHatsu ,
		const std::string& nameTsuuka ,
		const std::string& nameKeiyunasi ) ;



public:
	// ********************************
	///@name	CconvJikokuhyouCsv
	// ********************************
	///@{
	/**
		�w��̘H���t�@�C���f�[�^�E�_�C���E��ԕ�����
		�����\���ACSV�h�L�������g�ɏo�͂��܂��B

		*pCdCsvDocument ������܂ŕێ����Ă����f�[�^�͔j�����܂��B
	@param aCentDedRosen [in]
		�H�����w�肵�Ă��������B
	@param iDiaIndex [in]
		�_�C���̃C���f�N�X���w�肵�Ă��������B
	@param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
	@param iRessyaIndex [in]
		�o�͂���擪�̗�Ԃ̃C���f�N�X(0�N�_)
		���w�肵�Ă��������B
	@param iRessyaCount [in] 
		�o�͂����Ԃ̖{�����w�肵�Ă��������B
		INT_MAX �́A�����̗�Ԃ܂ł��w�肵�����ƂɂȂ�܂��B
	@param pCdCsvDocument [out]
		���̊֐��͂��� CdCsvDocument �I�u�W�F�N�g�ɁA
		�����\�f�[�^���������݂܂��B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	iDiaIndex ���s���ł��B
		-	-2 ;	//	iRessyaIndex ���s���ł��B
		-	-3 ;	//	iRessyaCount ���s���ł��B
	*/
	int encode( 
		const CentDedRosen& aCentDedRosen , 
		int iDiaIndex , 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIndex , int iRessyaCount , 
		CdCsvDocument* pCdCsvDocument ) ;

	/**
		�����\ CSV �h�L�������g���A
		�w��̘H���t�@�C���f�[�^�E�_�C���E��ԕ����̗�ԃR���e�i��
		�ǉ����܂��B
	@param pCentDedRosen [in]
		���̊֐��͂��̘H���ɁA��Ԃ�ǉ����܂��B
	@param iDiaIndex [in]
		�_�C���̃C���f�N�X���w�肵�Ă��������B
	@param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
	@param iRessyaIndex [in]
		aCdCsvDocument �̎w��̃_�C���E��ԕ����ɂ����āA
		��Ԃ�}������ʒu���w�肵�Ă��������B
		-	0 ;	//	�擪�ɑ}��
		-	INT_MAX ;	//	�����ɑ}��
	@param aCdCsvDocument [out]
		�����\�f�[�^���w�肵�Ă��������B
	@param pstrErrorInfoString [out]
		�G���[�Ȃ�A�G���[���e�L�X�g��Ԃ��܂��B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�s�����Ȃ����܂��B
		-	-2 ;	//	�񂪏��Ȃ����܂��B
		-	-3 ;	//	�t�@�C���`�����F���ł��܂���
		-	-4 ;	//	�t�@�C���`�����F���ł��܂���
		-	-11  ;	//	�w����������܂���B
		-	-21  ;	//	iDiaIndex ���s���ł��B
		-	-22  ;	//	iRessyaIndex ���s���ł��B
	*/
	int decode( 
		CentDedRosen* pCentDedRosen , 
		int iDiaIndex , 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIndex , 
		const CdCsvDocument& aCdCsvDocument , 
		std::string* pstrErrorInfoString ) ;

	///@}
};
} //namespace ConvJikokuhyouCsv

#endif //CconvJikokuhyouCsv_h

