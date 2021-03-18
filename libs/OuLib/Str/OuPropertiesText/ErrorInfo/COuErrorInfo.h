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
// $Id: COuErrorInfo.h 63 2012-09-01 08:54:26Z okm $
// ****************************************************************
/** @file */
#ifndef  OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfo_h
#define  OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfo_h

#include "str\OuPropertiesText\CDirectory.h"
#include <string>
namespace OuLib{
namespace Str{
namespace OuPropertiesText{
namespace ErrorInfo{

/**
@brief
  OuErrorInfo �́A�G���[�̏ڍ׏���ێ�����P���f�[�^�`���ł��B

  ���̃N���X�́A�����Ƃ���

  - Reason - �G���[�̓��e������������
  - Prop  - �G���[�̕⑫�������� OuPropertiesText 
  
�������܂��B�A���AProp �̓I�v�V�����Ȃ̂ŁA�s�v�ł���Ύg��Ȃ��Ă��܂��܂���

  Reason �ɂ͌����Ƃ��āA���s�����E�^�u�����͊܂܂Ȃ����̂Ƃ��܂��iOuErrorInfoText����̕ϊ����ł��Ȃ��Ȃ邽�߁j

  this �́ANull���(�G���[����ێ����Ă��Ȃ����)���Ƃ邱�Ƃ��ł��܂��B
  ���̏ꍇ�A Reason ���󕶎���EProp.size() �� 0 �ƂȂ�܂��B
 
<H4>
�yOuPropertiesTextErrorInfo�z
</H4>

  OuPropertiesTextErrorInfo �́AOuErrorInfo �̓��e��
  OuPropertiesText ���x�[�X�t�H�[�}�b�g�Ƃ��ĕ\�������f�[�^�`���ł��B

  @see COuErrorInfoContainer


(��)
@code
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

  @see COuErrorInfoContainer

(��)
@code
File Not Found.	FileName=source.txt
@endcode

*/
class COuErrorInfo
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		"Reason" PropertyText �B
		�G���[�̌�����\��������������܂��B���̕�����́A
		���p�p���������Ƃ��܂��B
		�^�u�����E���s�������܂ނ��Ƃ͂ł��܂���
		(�A���A���̃N���X�ł̓^�u�����E���s�����̃`�F�b�N�͍s���܂���)
	*/
	std::string m_strReason ;
	/**
		�G���[�̕⑫�������� OuPropertiesText 
	*/
	CNodeContainer	m_Prop ;
	///@}
public:
	// ********************************
	///@name �萔
	// ********************************
	///@{
	static const char* const DirectoryName_ErrorInfo ;
	static const char* const PropertyTextName_Reason ;
	static const char* const DirectoryName_Prop ;
	///@}
	
public:
	COuErrorInfo()
	{
	};
	COuErrorInfo( const std::string& strReason ) :
		m_strReason( strReason )
	{
	};
	COuErrorInfo( 
		const std::string& strReason , 
		const CNodeContainer& Prop ) :
		m_strReason( strReason ) ,
		m_Prop( Prop ) 
	{
	}
public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	std::string getReason()const{	return m_strReason ;};
	void setReason( const std::string& value )
	{	m_strReason = value ;};
	CNodeContainer*	getProp(){	return &m_Prop ;};
	const CNodeContainer*	getProp()const{	return &m_Prop ;};
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	@return
		���̃R���e�i�̓��e�� OuPropertiesTextErrorInfo �ɕϊ����A
		������i�[���� "ErrorInfo" Directory ��Ԃ��܂��B
		
	*/
	Ou<CDirectory> toOuPropertiesTextErrorInfo()const;

	/**
		OuPropertiesTextErrorInfo ��ێ����Ă���
		"ErrorInfo" Directory �̓��e���Athis �ɔ��f���܂��B
	@param pCNode [in]
		"pCDirectory" Directory ��ێ����Ă���
		CDirectory �̓��e���w�肵�Ă��������B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	pCDirectory �� "Directory" �ł͂���܂���B
		-	-2 ;	//	Directory ��"Reason" PropertyText ������܂���B
	*/
	int fromOuPropertiesTextErrorInfo( 
		Ou<const CDirectory> pCDirectory );

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
	
	@note
		strOuErrorInfoText ���󕶎���̏ꍇ�́A�G���[�ɂ͂Ȃ炸��
		�S�Ă̑������N���A������ԂɂȂ�܂��B
	*/
	int fromOuErrorInfoText( const std::string& strOuErrorInfoText );
	/**	
		this �� Null ��Ԃɂ��܂��B
	*/
	void clear() ;

	/**	
	@return
		this �� Null ��ԂȂ�  true �ł��B
	*/
	bool isNull()const ;
	///@}
};


} //namespace ErrorInfo{
} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{

#endif //OuLib_str_OuPropertiesText_ErrorInfo_COuErrorInfo_h
