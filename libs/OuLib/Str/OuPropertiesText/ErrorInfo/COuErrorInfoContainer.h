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
// $Id: COuErrorInfoContainer.h 294 2016-06-11 05:10:03Z okm $
// ****************************************************************
/** @file */
#ifndef  OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfoContainer_h
#define  OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfoContainer_h
#include "str\OuPropertiesText\CNodeContainer.h"
#include "NsMu\CMup_deque.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfo.h"

namespace OuLib{
namespace Str{
namespace OuPropertiesText{
namespace ErrorInfo{

/**
@brief
	������ OuErrorInfo ���W�񂷂�R���e�i�ł��B
	
	�W�񂵂Ă��� OuErrorInfo �ƁwOuErrorInfoText�x�̊Ԃ̑��ݕϊ��̋@�\�E
	�wOuPropertiesTextErrorInfo�x �Ƃ̊Ԃ̑��ݕϊ��̋@�\�������܂��B

<H4>
�yOuPropertiesTextErrorInfo�z
</H4>

  OuPropertiesTextErrorInfo �́AOuErrorInfo �̓��e��
  OuPropertiesText ���x�[�X�t�H�[�}�b�g�Ƃ��ĕ\�������f�[�^�`���ł��B
  
  OuPropertiesTextErrorInfo �́A0�ȏ㕡���� "ErrorInfo" Directory ��
�W�񂵂܂��B�P�� "ErrorInfo" Directory �łP�̃G���[����\���܂��B

  "ErrorInfo" Directory �́A�P�� "Reason" PropertyText �ƁA0�܂���1��
"Prop" Directory ���W�񂵂܂��B

  "Prop" Directory �ɂ́A�G���[����⑫���邽�߂̑����f�[�^���L�q���� OuPropertiesText ���W�񂷂邱�Ƃ��ł��܂��B
  
  
(��)
@code
ErrorInfo.
Reason=Receive Timeout.
.
ErrorInfo.
Reason=File Not Found.
Prop.
FileName=source.txt
Server.
Host=FtpServer
Username=FtpUser
.
.
.
@endcode



<H4>
�yOuErrorInfoText�z
</H4>
  OuErrorInfo �̓��e��\���e�L�X�g�ł��BUI�ւ̕\����z�肵�Ă��܂��B

 �P�� OuErrorInfo ��1�s�ɏo�͂���܂��B������OuErrorInfo ��
�W�񂳂�Ă���ꍇ�́A OuErroInfo �̊Ԃ͉��s�ŋ�؂��܂��B

  OuErrorInfoText �́A�ȉ��̌`���ł��B

  - �s���� "Reason" �B
  - "Prop" �ɏW�񂳂��PropertyText ������ꍇ�́A"Reason" �̌�� "Prop" �ɏW�񂳂�� PropertyText (0�ȏ㕡��)���^�u��؂�ŕ��т܂��B
  - ������ OuErrorInfo �̊Ԃ́A���s�ŋ�؂�܂��B
  - �y���Ӂz"Prop"�ɏW�񂳂�� Directory �́A�wOuErrorInfoText�x�ɂ͊܂܂�܂���B

(��)
@code
Receive Timeout.
File Not Found.	FileName=source.txt
@endcode





*/
class COuErrorInfoContainer : public CMup_deque<COuErrorInfo>
{
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	COuErrorInfoContainer( );
	// ********************************
	///@name �W��
	// ********************************
	///@{
	/**
	@return
		"ErrorInfo" �f�B���N�g�����W�񂷂�R���e�i�̓��e��
		�擾�E�ݒ肷�邽�߂̃C���^�[�t�F�[�X�B
	*/
	Mui<COuErrorInfo>* getCOuErrorInfoCont();
	const Mui<COuErrorInfo>* getCOuErrorInfoCont()const;
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	@return
		���̃R���e�i�̓��e�� OuPropertiesTextErrorInfo �ɕϊ����A
		������i�[���� CNodeContainer ��Ԃ��܂��B
		
	*/
	CNodeContainer toOuPropertiesTextErrorInfo()const;

	/**
		OuPropertiesTextErrorInfo ��ێ����Ă���
		OuPropertiesText �̓��e���Athis �ɔ��f���܂��B

		m_contCOuErrorInfoCont ������܂ŕێ����Ă���
		�C���X�^���X�͔j�����܂��B
	@param pCNodeContainer [in]
		OuPropertiesTextErrorInfo ��ێ����Ă���
		OuPropertiesText �̓��e���w�肵�Ă��������B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	int fromOuPropertiesTextErrorInfo( 
		const CNodeContainer* pCNodeContainer );

	/**	
	@return
		�wOuErrorInfoText�x�𐶐����ĕԂ��܂��B
	*/
	std::string toOuErrorInfoText()const ;

	/**	
		�wOuErrorInfoText�x�����߂��A���̃N���X�̑����ɔ��f���܂��B
		���̃N���X������܂ŕێ����Ă����f�[�^�͔j�����܂��B
	@param strOuErrorInfoText [in]
		�wOuErrorInfoText�x���w�肵�܂����B
	@return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	���߂Ɏ��s���܂����B
	*/
	int fromOuErrorInfoText( const std::string& strOuErrorInfoText ) ;
	///@}

};

} //namespace ErrorInfo{
} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{

#endif //OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfoContainer_h
