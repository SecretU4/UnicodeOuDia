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
//$Id: CConvNodeContainer.h 63 2012-09-01 08:54:26Z okm $
#pragma once
#include "str\OuPropertiesText\CNodeContainer.h"

namespace OuLib{
namespace Str{
namespace OuPropertiesText{


/**
@brief
	CNodeContainer �̓��e��OuPropertiesText(������)�̊Ԃ̕ϊ����s���܂��B

�yErrorInfoString�z

  ErrorInfoString �́A�G���[�̌���������������ł��B
  ���̕�����́A 

	- 1��ErrReason ������(�G���[����������)�ƁA
	- 0�ȏ��ErrProp(�G���[�T�u����)
 
 �ō\������܂��B

  ErrReason ������́A ERRREASON_ �̂����̂����ꂩ�ł��B

  ErrProp �́A 
 
	- ������=�l
 
 �̌`���ł��B�������́AERRPROP_ �̂����̂����ꂩ�ł��B
   ErrReason��ErrProp�̊ԁEErrProp���m�̊Ԃ́A�^�u�ŋ�؂�܂��B
*/
class CConvNodeContainer  
{
public:
	// ********************************
	///@name	ErrorInfoString
	// ********************************
	///@{
	/**
		�����񂪃f�R�[�h�ł��܂���B
	@param ERRPROP_Text
		�ΏۂƂȂ镶����
	*/
	static const char* const ERRREASON_Undecoded_Text ;
	/**
		�f�B���N�g�����r���ŕ��Ă��܂��B
	*/
	static const char* const ERRREASON_ContainerAborted ;
	/**
		�f�B���N�g�������Ă��܂���
	*/
	static const char* const ERRREASON_ContainerIsNotClosed ;

	/**
		�s�e�L�X�g
	*/
	static const char* const ERRPROP_Text ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CConvNodeContainer();
	virtual ~CConvNodeContainer();

protected:
	// --------------------------------
	///@name �������֐�
	// --------------------------------
	///@{
	/**
		Property �� Value ���AOuPropertiesText�p�ɃG�X�P�[�v���܂��B
			- ���s���� �� "\n" 
			- "\" �� "\\" 
	@param strValue [in]
		�ϊ��O�̕�������w�肵�Ă��������B
	@return 
		�ϊ���̕������Ԃ��܂��B
	*/
	std::string encodePropertyString_escapePropertyValue( 
		const std::string& strValue ); 

	/**
		OuPropertiesText�p�ɃG�X�P�[�v���ꂽProperty �� Value ���A�ϊ����܂��B
			- ���s���� �� "\n" 
			- "\" �� "\\" 
	@param strValue [in]
		�ϊ��O�̕�������w�肵�Ă��������B
	@return 
		�ϊ���̕������Ԃ��܂��B
	*/
	std::string decodePropertyString_unescapePropertyValue(
			const std::string& strValue ) ;

	/**
		OuPropertiesText �̎w��̈ʒu����n�܂� 
		NodeContainer 1�����߂��A���̓��e�����Ƃ� CNodeContainer �I�u�W�F�N�g��
		�\�z���܂��B
	@param strContent [in]
		OuPropertiesText��������w�肵�Ă��������B
	@param iPosBegin [in]
		OuPropertiesText������̒��ł̈ʒu���A0����n�܂�C���f�N�X�Ŏw�肵�Ă��������B
	@param piPosNext [out]
		���̊֐��́A���߂ɐ���������A���ߏI������ OuPropertiesText ������̈ʒu
		(�������ڂ܂ł����߂�����)���������݂܂��B
		����͒ʏ�AOuPropertiesText �̖������ADirectry�I�[�s�̐擪���w���܂��B
		�s�v�Ȃ�NULL�ł����܂��܂���B
	@param pCNodeContainer [out]
		���̊֐��͂��̃I�u�W�F�N�g�ɁANodeContainer �̓��e��
		�\�����܂��B
	@param pstrErrorInfoString [out]
		���̊֐��́A�G���[�����������ꍇ�́AErrorInfoString ���������݂܂��B
		�s�v�ł����NULL���w�肵�Ă����܂��܂���B
	@return
		-	1 ;	//	����
		-	0 ;	//	���ł� iPosBegin ���R���e���c�̖����ɂ���܂��B
		-	-1 ;	//	�����񂪃f�R�[�h�ł��܂���B	
	*/
	int decodeNodeContainer(
		const std::string& strContent , 	int iPosBegin  , int* piPosNext , 
			CNodeContainer* pCNodeContainer ,
			std::string* pstrErrorInfoString ) ;

	/**
		OuPropertiesText �̎w��̈ʒu����n�܂� 
		Property 1�����߂��A���̓��e�����Ƃ� CPropertyString �I�u�W�F�N�g��
		�\�z���܂��B
	@param strContent [in]
		OuPropertiesText��������w�肵�Ă��������B
	@param iPosBegin [in]
		OuPropertiesText������̒��ł̈ʒu���A0����n�܂�C���f�N�X�Ŏw�肵�Ă��������B
	@param piPosNext [out]
		���̊֐��́A���߂ɐ���������A���ߏI������ OuPropertiesText ������̈ʒu
		(�������ڂ܂ł����߂�����)���������݂܂��B
		����͒ʏ�AOuPropertiesText �̖������ADirectry�I�[�s�̐擪���w���܂��B
		�s�v�Ȃ�NULL�ł����܂��܂���B
	@param ppCPropertyString [out]
		���̊֐��́A���߂ɐ���������A���̓��e��ێ����� CPropertyString 
		�I�u�W�F�N�g�𐶐����A���̃I�u�W�F�N�g�ւ̃A�h���X��
		���̃|�C���^�ɏ������݂܂��B
	@param pstrErrorInfoString [out]
		���̊֐��́A�G���[�����������ꍇ�́AErrorInfoString ���������݂܂��B
		�s�v�ł����NULL���w�肵�Ă����܂��܂���B
	@return
		-	1 ;	//	����
		-	0 ;	//	���ł� iPosBegin ���R���e���c�̖����ɂ���܂��B
	*/
	int decodePropertyString(
		const std::string& strContent , 	int iPosBegin  , int* piPosNext , 
		Ou<CPropertyString>* ppCPropertyString ,
		std::string* pstrErrorInfoString ) ;

	/**
		�R���e���c�̎w��̈ʒu����n�܂�1�s�̕������Ԃ��܂��B
	@param strContent [in]
		�R���e���c��������w�肵�Ă��������B
	@param iPosBegin [in]
		�R���e���c������̒��ł̈ʒu���A0����n�܂�C���f�N�X�Ŏw�肵�Ă��������B
	@param piPosNext [out]
		���̊֐��́A�R���e���c��������ł́A���̍s�̈ʒu���������݂܂��B
		�s�v�Ȃ�NULL�ł����܂��܂���B
	@param pstrLine [out]
		���̊֐��͂��̃I�u�W�F�N�g�ɁA�P�s���̕������Ԃ��܂��B
		�s���̋�؂�� '\n' �́A���̕�����ɂ͊܂߂܂���B
	@return
		-	1 ;	//	����
		-	0 ;	//	���ł� iPosBegin ���R���e���c�̖����ɂ���܂��B
	*/
	int getLine( 
		const std::string& strContent , 
		int iPosBegin  , int* piPosNext , 
		std::string* pstrLine  ) ;

	///@}
public:
	// ********************************
	///@name	CConvNodeContainer  
	// ********************************
	///@{
	/**
		IfNodeContainerConst�̓��e�𕶎���(OuPropertiesText) �ɕϊ����܂��B
	@param pIfNodeContainerConst [in]
		�ϊ����� CNodeContainer ���w�肵�Ă��������B
	@return
		�ϊ����OuPropertiesText��Ԃ��܂��B
	*/
	virtual std::string encode( 
		const IfNodeContainerConst* pIfNodeContainerConst ) ;

	/**
		CNodeContainer�̓��e�𕶎���(OuPropertiesText) �ɕϊ����܂��B
	@param pCNodeContainer [in]
		�ϊ����� CNodeContainer ���w�肵�Ă��������B
	@return
		�ϊ����OuPropertiesText��Ԃ��܂��B
	*/
	virtual std::string encode( 
		const CNodeContainer* pCNodeContainer ) 
	{	return encode( pCNodeContainer->getIfNodeContainerConst() ) ; } ;

	/**
		������(OuPropertiesText) �̓��e��CNodeContainer�ɔ��f���܂��B
	@param strContent [in]
		�ϊ����� OuPropertiesText�B
	@param pCNodeContainer [out]
		���̊֐��́A���� CNodeContainer �ɁAOuPropertiesText ��
		���e�𔽉f���܂��B
		���̊֐�������܂ŕێ����Ă������e�͔j�����܂��B
	@param pstrErrorInfoString [out]
		���̊֐��́A�G���[�����������ꍇ�́AErrorInfoString ���������݂܂��B
		�s�v�ł����NULL���w�肵�Ă����܂��܂���B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�f�B���N�g�����r���ŕ��Ă��܂��B
	*/
	virtual int decode(
		const std::string& strContent , 
		CNodeContainer* pCNodeContainer ,
		std::string* pstrErrorInfoString = NULL ) ;


	///@}

};

} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{
