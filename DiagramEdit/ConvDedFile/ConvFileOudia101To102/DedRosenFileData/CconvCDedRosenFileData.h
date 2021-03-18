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
/*��
// ****************************************************************
//	CconvCDedRosenFileData.h
// ****************************************************************
*/
#ifndef  CconvCDedRosenFileData_h
#define  CconvCDedRosenFileData_h
/** @file */
#include "CconvCdDedDispProp.h"
#include "str\OuPropertiesText\CNodeContainer.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfoContainer.h"

// ****************************************************************
//	CconvCDedRosenFileData
// ****************************************************************
/**
	@brief
	  �w�H���t�@�C���x�f�[�^ ( CDedRosenFileData ) �̓��e���A����
	�f�[�^�`���ɕϊ�����֐������^���Ă��܂��B
	
	 �w�H���t�@�C���x�f�[�^��  OuPropertiesText::CNodeContainer �I�u�W�F�N�g�Ƃ̊Ԃ�
	�ϊ����T�|�[�g���Ă��܂��B 
	
	<H4>
	�y�H���t�@�C�� (.ded) �z
	</H4>
	  �w�H���t�@�C���x�́A�H���t�@�C���f�[�^�N���X��
	 CDedRosenFileData_To_string() �ŕ�����ɕϊ����A���̕�����S�̂�
	�ۑ������e�L�X�g�t�@�C���ł��B
	
	   CDedRosenFileData_To_string() �֐��́A
	   CDedRosenFileData �I�u�W�F�N�g���ێ�����f�[�^��
	�ȉ��̎菇�ŕ�����ɕϊ����܂��B
	  ���̕�������t�@�C���ɕۑ����邱�Ƃɂ��A
	 �w�H���t�@�C���x�ƂȂ�܂��B
*/
class CconvCDedRosenFileData
{
public:
	// ********************************
	///@name COuErrorInfo::m_strReason , m_Prop 
	// ********************************
	/**
		FileType ���s���ł��B
	@param FileType
		FileType
	*/
	static const char* ERRREASON_FileTypeIsInvalid(){	return "FileType Is Invalid." ;};
	static const char* ERRPROP_FileType(){	return "FileType" ;};
	/**
		Rosen Directory ��������܂���B
	*/
	static const char* ERRREASON_RosenDirectoryIsNotFound(){	return "Rosen Directory is not found." ;};
	/**
		DispProp Directory ��������܂���B
	*/
	static const char* ERRREASON_DispPropnDirectoryIsNotFound(){	return "DispProp Directory is not found." ;};
public:
	// ********************************
	//	CdDedDispProp
	// ********************************
	/**
	 @return
		PropertyText�A�C�e�� "FileType" �̒l�ł��B
	*/
	static std::string getFileType(){	return "OuDia.1.02" ; } ;
	
	
	
	// ********************************
	///@name	OuPropertiesText �ւ̕ϊ�
	// ********************************
	///@{
	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CDedRosenFileData �̑�����ǉ����܂��B
		@param aCDedRosenFileData [in]
		  CDedRosenFileData ���w�肵�Ă��������B
		  pCNodeContainer �ɂ́A"FileType" PropertyString ���܂݂܂��B
		@param pCNodeContainer [out]
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
	int CDedRosenFileData_to_OuPropertiesText( 
			const CDedRosenFileData* pCDedRosenFileData , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  CDedRosenFileData_to_OuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CDedRosenFileData �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCDedRosenFileData [out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
		  ���̃I�u�W�F�N�g������܂ŕێ����Ă����f�[�^�͔j�����܂��B
		@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
		@param pCOuErrorInfoContainer [out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		  �s�v�ł����NULL���w�肵�Ă��������B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-1 ;	//	FileType ������������܂���B
			-	-2 ;	//	Rosen Directory��������܂���B
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
			-	-3 ;	//	DispProp Directory��������܂���B
			-	-512 ;	//	JikokuhyouFont �̓��e���s���ł��B
			-	-522 ;	//	DiaEkimeiFont �̓��e���s���ł��B
			-	-532 ;	//	DiaJikokuFont �̓��e���s���ł��B
			-	-582 ;	//	DisplayRessyabangou ���s���ł��B
			-	-592 ;	//	DisplayRessyamei ���s���ł��B
			-	-602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
			-	-612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B
	*/
	int CDedRosenFileData_from_OuPropertiesText( 
			CDedRosenFileData* pCDedRosenFileData ,
			const OuPropertiesText::CNodeContainer* pCNodeContainer ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g��
		���̃N���X�ŉ��߉\�ȃt�H�[�}�b�g���ۂ��𔻒肵�܂��B
	@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
	@return
		-	0 ;	//	���߉\�ł��B
		-	-1 ;	//	FileType ������������܂���B
		
	@note
		FileType �̒l�𔻒肵�܂��B
	*/
	int isEncodeAbleFormat( 
			const OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	
	///@}
	// ********************************
	///@name �H���t�@�C���`��������ւ̕ϊ�
	// ********************************
	///@{
	/**
		  CDedRosenFileData �̕ێ�����f�[�^����A
		�w�H���t�@�C���x(.ded) �`���̕�������쐬���܂��B
	
		@param aCDedRosenFileData [in]
		  CDedRosenFileData ���w�肵�Ă��������B
		@param pString [out]
		  ���̊֐��́A���̕�����I�u�W�F�N�g�ɁA
		�w�H���t�@�C���x(.ded) �`���̕������ݒ肵�܂��B
		  ���̃I�u�W�F�N�g������܂ŕێ����Ă���������͔j�����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
		-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
		-	-32 ;	//	Ekikibo �̒l���s���ł��B
		-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
		-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
		-	-212 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	*/
	int CDedRosenFileData_to_string( 
			const CDedRosenFileData& aCDedRosenFileData , 
			std::string* pString  ) ;
	
	/**
		  CDedRosenFileData_to_string() �Ő�������
		�w�H���t�@�C���x(.ded) �`���̕���������߂��A
		 CDedRosenFileData �I�u�W�F�N�g�ɔ��f���܂��B
		
		@param pCDedRosenFileData [out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
		  ���̃I�u�W�F�N�g������܂ŕێ����Ă����f�[�^�͔j�����܂��B
		@param aString [in]
		  CDedRosenFileData_to_string() �Ő�������
		�w�H���t�@�C���x(.oud) �`���̕�������w�肵�Ă��������B
		@param pCOuErrorInfoContainer [in]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g�ɒǉ����܂��B
		@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			-	-1 ;	//	�f�B���N�g�����r���ŕ��Ă��܂��B	
			-	-1001 ;	//	FileType ������������܂���B
			-	-1002 ;	//	Rosen Directory��������܂���B
			-	-1011 ;	//	Ekimei ���w�肳��Ă��܂���B
			-	-1022 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			-	-1032 ;	//	Ekikibo �̒l���s���ł��B
			-	-1101 ;	//	Eki ���f�B���N�g���ł͂���܂���B
			-	-1111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			-	-1152 ;	//	DiagramSenStyle �̒l���s���ł��B
			-	-1201 ;	//	Ressyasyubetsu ���f�B���N�g���ł͂���܂���B
			-	-1211 ;	//	DiaName ���w�肳��Ă��܂���B
			-	-1212 ;	//	RessyaCont��������܂���B
			-	-1352 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
			-	-1003 ;	//	DispProp Directory��������܂���B
			-	-1512 ;	//	JikokuhyouFont �̓��e���s���ł��B
			-	-1522 ;	//	DiaEkimeiFont �̓��e���s���ł��B
			-	-1532 ;	//	DiaJikokuFont �̓��e���s���ł��B
			-	-1582 ;	//	DisplayRessyabangou ���s���ł��B
			-	-1592 ;	//	DisplayRessyamei ���s���ł��B
			-	-1602 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
			-	-1612 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B
	*/
	int CDedRosenFileData_from_string( 
			CDedRosenFileData* pCDedRosenFileData ,
			const std::string& aString ,
			OuPropertiesText::ErrorInfo::COuErrorInfoContainer* pCOuErrorInfoContainer ) ;

	/**
		�t�@�C���̓��e���i�[����������
		���̃N���X�ŉ��߉\�ȃt�H�[�}�b�g���ۂ��𔻒肵�܂��B
	@param aString [in]
		  CDedRosenFileData_to_string() �Ő�������
		�w�H���t�@�C���x(.oud) �`���̕�������w�肵�Ă��������B
	@return
		-	0 ;	//	���߉\�ł��B
		-	-1 ;	//	FileType ������������܂���B
		-	-1001 ;	//	FileType ������������܂���B
	@note
		FileType �̒l�𔻒肵�܂��B
	*/
	int isEncodeAbleFormat( 
			const std::string& aString  ) ;
	///@}	
};
#endif /*CconvCDedRosenFileData_h*/
