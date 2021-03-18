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
//	CconvCdDedDispProp.h
// $Id: CconvCdDedDispProp.h 149 2013-02-02 07:17:32Z okm $
// ****************************************************************
*/
#ifndef  CconvCdDedDispProp_h
#define  CconvCdDedDispProp_h
/** @file */
#include "CDedRosenFileData.h"
#include "str\OuPropertiesText\CNodeContainer.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfoContainer.h"

namespace DedRosenFileData{
	using namespace OuLib::Str;
// ****************************************************************
//	CconvCdDedDispProp
// ****************************************************************
/**
@brief
	  CdDedDispProp �I�u�W�F�N�g
	�iDiagramEdit �̕\���Ɋ֌W����v���p�e�B��ێ�����
	�P���f�[�^�N���X�j
	�ƁA���̃f�[�^�`���Ƃ̊Ԃ̑��ݕϊ����s���܂��B
	
	OuPropertiesText::CNodeContainer �I�u�W�F�N�g�Ƃ̊Ԃ̕ϊ����T�|�[�g���Ă��܂��B 

 */
class CconvCdDedDispProp
{
public:
	/**
		OuErrorInfo::m_strReason �Ɏw�肷�邽�߂̃G���[������ł��B
		�u�l���s���v
	@param Name
		�l�̖��O
	@param Value
		�s���ȃp�����[�^�̒l
	*/
	static const char* ERRREASON_InvalidValue(){	return "Invalid value." ;};
	static const char* ERRPROP_Name(){	return "Name" ;};
	static const char* ERRPROP_Value(){	return "Value" ;};
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CconvCdDedDispProp(){};

public:
	// ********************************
	///@name CconvCdDedDispProp-����
	// ********************************
	///@{
	/**
		  OuPropertiesText �I�u�W�F�N�g�ɁA
		  CdDedDispProp �̑�����ǉ����܂��B
	@param aCdDedDispProp [in]
		  CdDedDispProp ���w�肵�Ă��������B
	@param pCNodeContainer [out]
		  ���̊֐��́A���̃I�u�W�F�N�g�ɁAaCentDedEki �̓��e�𔽉f���܂��B
		  pCNodeContainer ������܂ŕێ����Ă����I�u�W�F�N�g�͔j�����܂��B
	@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		  �A���A���݂͕��̐����Ԃ���邱�Ƃ͂���܂���B
	 */
	int toOuPropertiesText( 
			const CdDedDispProp& aCdDedDispProp , 
			OuPropertiesText::CNodeContainer* pCNodeContainer ) ;
	
	/**
		  OuPropertiesText �I�u�W�F�N�g����A
		  toOuPropertiesText() �֐��ɂ���č쐬���ꂽ
		�A�C�e����ǂݍ��݁A CdDedDispProp �I�u�W�F�N�g�ɔ��f���܂��B
		
	@param pCdDedDispProp [out]
		  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	@param pCNodeContainer [in]
		  ������ێ����Ă��� OuPropertiesText �I�u�W�F�N�g���w�肵�Ă��������B
	@param pCOuErrorInfoContainer [out]
		  ���̊֐��̓G���[������������A�G���[�̏������̃I�u�W�F�N�g��
		  �ǉ����܂��B
	@return
		  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-12 ;	//	JikokuhyouFont �̓��e���s���ł��B
		-	-13 ;	//	JikokuhyouVFont �̓��e���s���ł��B
		-	-14 ;	//	HalfWidthCharInTextV �̓��e���s���ł��B
		-	-22 ;	//	DiaEkimeiFont �̓��e���s���ł��B
		-	-32 ;	//	DiaJikokuFont �̓��e���s���ł��B
		-	-82 ;	//	DisplayRessyabangou ���s���ł��B
		-	-92 ;	//	DisplayRessyamei ���s���ł��B
		-	-102 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ���s���ł��B
		-	-112 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ���s���ł��B
	 */
	int fromOuPropertiesText( 
		CdDedDispProp* pCdDedDispProp ,
		const OuPropertiesText::IfNodeContainerConst* pCNodeContainer ,
		OuPropertiesText::ErrorInfo::COuErrorInfoContainer* 
			pCOuErrorInfoContainer ) ;
	///@}
	
	
};

} //namespace DedRosenFileData

#endif /*CconvCdDedDispProp_h*/
