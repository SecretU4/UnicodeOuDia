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
//	CconvCentDed.h
// $Id: CconvCentDed.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
#ifndef  CconvCentDed_h
#define  CconvCentDed_h

/** @file */

#include "str\OuPropertiesText\CNodeContainer.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfoContainer.h"
#include "str\CEnumToString.h"
#include "DcdCd\DcDrawProp\CdDcdFreeLineProp.h"
#include "DcdCd\DcDrawProp\CdColorProp.h"

#include "CentDedEki.h"
#include "CentDedRessyasyubetsu.h"
#include "CentDedEkiJikoku.h"
#include "CentDedRessya.h"
#include "CentDedRessyaCont.h"
#include "CentDedDia.h"
#include "CentDedRosen.h"


// ****************************************************************
//	CconvCentDed
// ****************************************************************
/**
	@brief
	  DiagramEdit �̃G���e�B�e�B�N���X�̃I�u�W�F�N�g�̑����f�[�^�̓��e���A
	���̃f�[�^�`���ɕϊ�����֐������^���Ă��܂��B

	OuPropertiesText::CNodeContainer �I�u�W�F�N�g�Ƃ̊Ԃ̕ϊ����T�|�[�g���Ă��܂��B 
	
*/
class CconvCentDed
{
public:
	// ********************************
	///@name COuErrorInfo::m_strReason , m_Prop �� Name
	// ********************************
	///@{
	
	/**
		"Ekimei" ������������܂���B
		@param Ekimei
			�w�肳��Ă���w��
	*/
	static const char* ERRREASON_EkimeiIsInvalid(){	return "Ekimei is invalid." ;};
	/**
		"Ekijikokukeisiki" ������������܂���B
		@param Ekijikokukeisiki
			�w�肳��Ă���w�����`��
	*/
	static const char* ERRREASON_EkijikokukeisikiIsInvalid(){	return "Ekijikokukeisiki is invalid." ;};

	/**
		"Ekikibo" ������������܂���B
		@param Ekikibo
			�w�肳��Ă���w�K��
	*/
	static const char* ERRREASON_EkikiboIsInvalid(){	return "Ekikibo is invalid." ;};

	/**
		"DiagramRessyajouhouHyouji" ������������܂���B
		@param DiagramRessyajouhouHyoujiKudari
			�w�肳��Ă�����e
		@param DiagramRessyajouhouHyoujiNobori
			�w�肳��Ă�����e
	*/
	static const char* ERRREASON_DiagramRessyajouhouHyoujiIsInvalid(){	return "DiagramRessyajouhouHyouji is invalid." ;};

	/**
		"Eki" ���f�B���N�g���ł͂���܂���B
		@param Index
			�ΏۂƂȂ� Eki �̔ԍ�(0�N�_)���w�肵�Ă��������B
	*/
	static const char* ERRREASON_EkiIsNotDirectory(){	return "Eki Is Not Directory." ;};
	static const char* ERRPROP_Index(){	return "Index" ;};

	/**
		"Syubetsumei" ������������܂���B
		@param Syubetsumei
			�w�肳��Ă����ʖ�
	*/
	static const char* ERRREASON_SyubetsumeiIsInvalid(){	return "Syubetsumei is invalid." ;};
	/**
		"DiagramSenStyle" ������������܂���B
		@param DiagramSenStyle
			�w�肳��Ă���l
	*/
	static const char* ERRREASON_DiagramSenStyleIsInvalid(){	return "DiagramSenStyle is invalid." ;};

	/**
		"Ressyasyubetsu" ���f�B���N�g���ł͂���܂���B
		@param Index
			�ΏۂƂȂ� Ressyasyubetsu �̔ԍ�(0�N�_)���w�肵�Ă��������B
	*/
	static const char* ERRREASON_RessyasyubetsuIsNotDirectory(){	return "Ressyasyubetsu is invalid." ;};

	/**
		"DiaName" ������������܂���B
	*/
	static const char* ERRREASON_DiaNameInvalid(){	return "DiaName is invalid." ;};

	/**
		"RessyaCont" ��������܂���B
		@param Ressyahoukou
			������Ȃ�����RessyaCont�̗�ԕ����B "Kudari" �� "Nobori" �̂����ꂩ�ł��B
	*/
	static const char* ERRREASON_ResyaContIsNotExist(){	return "Ressyahoukou is Not Exist." ;};

	static const char* ERRPROP_Ressyahoukou(){	return "Ressyahoukou" ;};

	/**
		�N�_�������s���ł��B
	@param Jikoku
		�w�肳�ꂽ����
	*/
	static const char* ERRREASON_KitenjikokuIsInvalid(){	return "Kitenjikoku Is Invelid." ;};

	static const char* ERRPROP_Jikoku(){	return "Jikoku" ;};

	/**
		�_�C���O�����̊���̉w�ԕ����s���ł��B
	@param Value
		�ݒ肳��Ă���l
	*/
	static const char* ERRREASON_DiagramDgrYZahyouKyoriDefaultIsInvalid(){	return "DiagramDgrYZahyouKyoriDefault Is Invelid." ;};

	static const char* ERRPROP_Value(){	return "Value" ;};
	/**
		�l�̌`��������������܂���B
	@param Name
		���ږ�
	@param Value
		�ݒ肳��Ă���l
	*/
	static const char* ERRREASON_InvalidValueFormat(){	return "Invalid Value Format." ;};

	static const char* ERRPROP_Name(){	return "Name" ;};



	///@}
 public:

	// ********************************
	//	CentDedEki
	// ********************************
	/**
	@return
		CentDedEki::EEkijikokukeisiki �ƕ�����̊Ԃ̃R���o�[�^�I�u�W�F�N�g��Ԃ��܂��B
	*/
	static const CEnumToString< CentDedEki::EEkijikokukeisiki >& getEEkijikokukeisikiToString();

	/**
	@return
		CentDedEki::EEkikibo �ƕ�����̊Ԃ̃R���o�[�^�I�u�W�F�N�g��Ԃ��܂��B
	*/
	static const CEnumToString< CentDedEki::EEkikibo >& getEEkikiboToString();

	/**
	@return
		CentDedEki::EDiagramRessyajouhouHyouji �ƕ�����̊Ԃ̃R���o�[�^�I�u�W�F�N�g��Ԃ��܂��B
	*/
	static const CEnumToString< CentDedEki::EDiagramRessyajouhouHyouji >& 
		getEDiagramRessyajouhouHyoujiToString() ;

	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedEki �̑�����ǉ����܂��B
		@param aCentDedEki [in]
		  CentDedEki ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁAaCentDedEki �̓��e��ǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
			-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			-	-32 ;	//	Ekikibo �̒l���s���ł��B
	 */
	int CentDedEki_To_OuPropertiesText( 
			const CentDedEki& aCentDedEki , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedEki_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedEki �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCentDedEki [out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [in,out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
			-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			-	-32 ;	//	Ekikibo �̒l���s���ł��B
			-	-41 ;	//	DiagramRessyajouhouHyoujiKudari �̒l���s���ł��B
			-	-42 ;	//	DiagramRessyajouhouHyoujiNobori �̒l���s���ł��B
	 */
	int CentDedEki_From_OuPropertiesText( 
			CentDedEki* pCentDedEki ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;
	
	// ********************************
	//	CentDedEkiCont
	// ********************************
	
	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedEkiCont �̑�����ǉ����܂��B

		  ���̊֐��́A CentDedEki �I�u�W�F�N�g�� "Eki" Directory �Ƃ��Ēǉ����܂��B
		@param aCentDedEkiCont [in]
		  CentDedEkiCont ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁAaCentDedEkiCont �̓��e��ǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
			-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			-	-32 ;	//	Ekikibo �̒l���s���ł��B
	 */
	int CentDedEkiCont_To_OuPropertiesText( 
			const CentDedEkiCont& aCentDedEkiCont , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedEki_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedEki �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCentDedEkiCont [in,out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA������ǉ����܂��B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [in,out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
			-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			-	-32 ;	//	Ekikibo �̒l���s���ł��B
			-	-41 ;	//	DiagramRessyajouhouHyoujiKudari �̒l���s���ł��B
			-	-42 ;	//	DiagramRessyajouhouHyoujiNobori �̒l���s���ł��B
			-	-101 ;	//	Eki ���f�B���N�g���ł͂���܂���B
	 */
	int CentDedEkiCont_From_OuPropertiesText( 
			CentDedEkiCont* aCentDedEkiCont ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;
	
	// ********************************
	//	CentDedRessyasyubetsu
	// ********************************
	/**
	@return
		CentDedRessyasyubetsu::ESenStyle �� ������Ƃ̊Ԃ̃R���o�[�^�I�u�W�F�N�g��
		�Ԃ��܂��B
	*/
	static const CEnumToString< CentDedRessyasyubetsu::ESenStyle >& 
		getESenStyleToString();
	static const CEnumToString< CentDedRessyasyubetsu::EStopMarkDrawType >& 
		getEStopMarkDrawTypeToString() ;

	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedRessyasyubetsu::CdDiagramLineStyle �̑�����ǉ����܂��B
		@param aCdDiagramLineStyle [in]
		  CentDedRessyasyubetsu::CdDiagramLineStyle ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁA���e��ǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		  ���݂̂Ƃ���A 0 �����Ԃ��܂���B
	 */
	int CdDiagramLineStyle_To_OuPropertiesText( 
			const CentDedRessyasyubetsu::CdDiagramLineStyle& aCdDiagramLineStyle , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;

	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedRessyasyubetsu_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedRessyasyubetsu �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCdDiagramLineStyle [out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [in,out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-52 ;	//	DiagramSenStyle �̒l���s���ł��B
	 */
	int CdDiagramLineStyle_From_OuPropertiesText( 
			CentDedRessyasyubetsu::CdDiagramLineStyle* pCdDiagramLineStyle ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;

	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedRessyasyubetsu �̑�����ǉ����܂��B
		@param aCentDedRessyasyubetsu [in]
		  CentDedRessyasyubetsu ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁACDedRosenFileData �̓��e��ǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			-	-52 ;	//	DiagramSenStyle �̒l���s���ł��B
	 */
	int CentDedRessyasyubetsu_To_OuPropertiesText( 
			const CentDedRessyasyubetsu& aCentDedRessyasyubetsu , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedRessyasyubetsu_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedRessyasyubetsu �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCentDedRessyasyubetsu [out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [in,out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			-	-52 ;	//	DiagramSenStyle �̒l���s���ł��B
			-	-101 ;	//	�l�̌`��������������܂���B
	 */
	int CentDedRessyasyubetsu_From_OuPropertiesText( 
			CentDedRessyasyubetsu* pCentDedRessyasyubetsu ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;
	
	/**
		CentDedRessyasyubetsu::ESenStyle �̒l�ƁA
		�u�����v������ bool ���������ƂɁA
		CDcdFreeLine::CdLineProp �I�u�W�F�N�g�ɑ�����
		�ݒ肵�܂��B
	 @param aCOLORREF [in] 
		���̐F���w�肵�Ă��������B
	 @param eSenStyle [in]
		���̌`����w�肵�Ă��������B
	 @param bIsBold [in]
		�����Ȃ� true , �����łȂ��Ȃ� false ���w�肵�Ă��������B
	 @param pCdLineProp [out]
		���̊֐��͂��̃I�u�W�F�N�g�ɁA
		������ݒ肵�܂��B

		//yotei ������ CentDedRessyasyubetsu::CdDiagramLineStyle �ɕύX
	 */
	void CentDedRessyasyubetsu_to_CDcdFreeLineProp(
		CdColorProp aCOLORREF ,
		CentDedRessyasyubetsu::ESenStyle eSenStyle , 
		bool bIsBold , 
		CdDcdFreeLineProp* pCdLineProp )	;

	// ********************************
	//	CentDedRessyasyubetsuCont
	// ********************************
	
	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedRessyasyubetsuCont �̓��e��ǉ����܂��B
		  ���̊֐��́A CentDedRessyasyubetsu �I�u�W�F�N�g�� 
		  "Ressyasyubetsu" Directory �Ƃ��Ēǉ����܂��B
		@param aCentDedRessyasyubetsuCont [in]
		  CentDedRessyasyubetsuCont ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁACDedRosenFileData �̓��e��ǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			-	-52 ;	//	DiagramSenStyle �̒l���s���ł��B
	 */
	int CentDedRessyasyubetsuCont_To_OuPropertiesText( 
			const CentDedRessyasyubetsuCont& aCentDedRessyasyubetsuCont , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedRessyasyubetsuCont_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedRessyasyubetsu �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCentDedRessyasyubetsuCont [in,out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA������ǉ����܂��B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [in,out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			-	-52 ;	//	DiagramSenStyle �̒l���s���ł��B
			-	-101 ;	//	Ressyasyubetsu ���f�B���N�g���ł͂���܂���B
	 */
	int CentDedRessyasyubetsuCont_From_OuPropertiesText( 
			CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;

	
	// ********************************
	//	CentDedEkiJikoku
	// ********************************
	/**
		CentDedEkijikoku �̑����𕶎���ɕϊ����܂��B
	@param pCentDedEkijikoku[in]
		�ϊ����s���I�u�W�F�N�g���w�肵�Ă��������B
	@return
		�ϊ����ʂ�Ԃ��܂��B
	*/
	std::string CentDedEkiJikoku_To_string( 
		const CentDedEkiJikoku* pCentDedEkijikoku ) ;

	/**
		CentDedEkijikoku_To_string() �Ő���������������A
		CentDedEkijikoku �̑����ɔ��f���܂��B
	@param pCentDedEkijikoku[out]
		���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	@param strValue[in]
		������ێ����镶������w�肵�Ă��������B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		- ���݂̂Ƃ���A�G���[�͂���܂���B
		
	*/
	int CentDedEkiJikoku_From_string( 
			CentDedEkiJikoku* pCentDedEkijikoku , 
			const std::string strValue ) ;
	
	// ********************************
	//	CentDedRessya
	// ********************************
	/**
	@return
		ERessyahoukou �ƕ�����Ƃ̊Ԃ̃R���o�[�^�I�u�W�F�N�g��Ԃ��܂��B
	*/
	static const CEnumToString<ERessyahoukou>& getERessyahoukouToString() ;

	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedRessya �̑�����ǉ����܂��B
		@param pCentDedRessya [in]
		  CentDedRessya ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CentDedRessya �̓��e��ǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-12 ;	//	Ressyahoukou �̒l���s���ł��B
	 */
	int CentDedRessya_To_OuPropertiesText( 
			const CentDedRessya* pCentDedRessya , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedRessya_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedRessya �I�u�W�F�N�g�ɔ��f���܂��B
		
		  �������A
	
			- ��ԕ���
			- �I�u�W�F�N�g����܂��� �w�w�����x �̐�
	
		�́A�ύX���܂���B���̒l�́A�֐��ďo���ɂ���Đݒ肳��Ă���
		�K�v������܂��B
		@param pCentDedRessya [in,out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA��Ԃ̑����𔽉f���܂��B
			�������A�I�u�W�F�N�g�̑����w��ԕ����x��
			��܂��� �w�w�����x �̐��͕ύX���܂���B
			���̒l�́A�֐��ďo���ɂ���Đݒ肳��Ă���K�v������܂��B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			- ���݂̂Ƃ���A�G���[�͂���܂���B
	 */
	int CentDedRessya_From_OuPropertiesText( 
			CentDedRessya* pCentDedRessya ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;
	
	
	// ********************************
	//	CentDedRessyaCont
	// ********************************
	
	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedRessyaCont �̑�����ǉ����܂��B
		@param pCentDedRessyaCont [in]
		  CentDedRessya ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CDedRosenFileData �̓��e��ǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-12 ;	//	Ressyahoukou �̒l���s���ł��B
	 */
	int CentDedRessyaCont_To_OuPropertiesText( 
			const CentDedRessyaCont* pCentDedRessyaCont , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedRessya_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedRessyaCont �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCentDedRessyaCont [in,out]
			���̊֐��͂��̃R���e�i�̖����ɁA
			OuPropertiesText �I�u�W�F�N�g�ɕۑ�����Ă��鑮���̃I�u�W�F�N�g��
			�ǉ����܂��B\n
			�������A�ǉ������I�u�W�F�N�g�� �w�w�����x �̐��́A
			m_iEkiCount �Ɍ��܂��Ă��܂��B aCdConectedString �ɕۑ�����Ă���
			��Ԃ������葽���w�w�����x��ێ����Ă����ꍇ�́A�I���w���̎�����
			�؎̂ĂƂȂ�܂��B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			- ���݂̂Ƃ���A�G���[�͂���܂���B
	 */
	int CentDedRessyaCont_From_OuPropertiesText( 
			CentDedRessyaCont* pCentDedRessyaCont ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;
	
	
	// ********************************
	//	CentDedDia
	// ********************************
	
	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedDia �̑�����ǉ����܂��B
		@param pCentDedDia [in]
		  CentDedDia ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁA pCentDedDia �̓��e��ǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedDia_To_OuPropertiesText( 
			const CentDedDia* pCentDedDia , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedDia_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedDia �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCentDedDia [in,out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
		  ���̃I�u�W�F�N�g�ɂ́A���炩���� �w�w�̐��x�E�w��Ԏ�ʐ��x
		���ݒ肳��Ă��Ȃ��Ă͂Ȃ�܂���B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11 ;	//	DiaName ���w�肳��Ă��܂���B
		-	-12 ;	//	RessyaCont��������܂���B
	 */
	int CentDedDia_From_OuPropertiesText( 
			CentDedDia* pCentDedDia ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;
	
	// ********************************
	//	CentDedDiaCont
	// ********************************
	
	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedDiaCont �̑�����ǉ����܂��B
		@param pCentDedDiaCont [in]
		  CentDedDiaCont ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CDedRosenFileData �̓��e��ǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedDiaCont_To_OuPropertiesText( 
			const CentDedDiaCont* pCentDedDiaCont , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedDiaCont_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedDiaCont �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCentDedDiaCont [in,out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
		  ���̃I�u�W�F�N�g�ɂ́A���炩���� �w�w�̐��x�E�w��Ԏ�ʐ��x
		���ݒ肳��Ă��Ȃ��Ă͂Ȃ�܂���B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11 ;	//	DiaName ���w�肳��Ă��܂���B
		-	-12 ;	//	RessyaCont��������܂���B
	 */
	int CentDedDiaCont_From_OuPropertiesText( 
			CentDedDiaCont* pCentDedDiaCont ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;
	
	// ********************************
	//	CentDedRosen
	// ********************************
	
	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CentDedRosen �̑�����ǉ����܂��B
		@param pCentDedRosen [in]
		  CentDedRosen ���w�肵�Ă��������B
		@param pCNodeContainer [in,out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CDedRosenFileData �̓��e�𔽉f���܂��B
		  pCNodeContainer ������܂ŕێ����Ă����I�u�W�F�N�g�͔j�����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
			-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			-	-32 ;	//	Ekikibo �̒l���s���ł��B
			-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
			-	-212 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedRosen_To_OuPropertiesText( 
			const CentDedRosen* pCentDedRosen , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CentDedRosen_To_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CentDedRosen �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCentDedRosen [out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
			-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			-	-32 ;	//	Ekikibo �̒l���s���ł��B
			-	-41 ;	//	DiagramRessyajouhouHyoujiKudari �̒l���s���ł��B
			-	-42 ;	//	DiagramRessyajouhouHyoujiNobori �̒l���s���ł��B
			-	-101 ;	//	Eki ���f�B���N�g���ł͂���܂���B
			-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
			-	-201 ;	//	Ressyasyubetsu ���f�B���N�g���ł͂���܂���B
			-	-211 ;	//	DiaName ���w�肳��Ă��܂���B
			-	-212 ;	//	RessyaCont��������܂���B
			-	-352 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
			-	-353 ;	//	�_�C���O�����̊���̉w�ԕ����s���ł��B
	 */
	int CentDedRosen_From_OuPropertiesText( 
			CentDedRosen* pCentDedRosen ,
			const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;
	
	
	
};	
#endif /*CconvCentDed_h*/
	
