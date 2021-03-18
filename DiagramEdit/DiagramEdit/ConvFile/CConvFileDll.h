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
// CConvFileDll.h: CConvFileDll �N���X�̃C���^�[�t�F�C�X
//
//////////////////////////////////////////////////////////////////////
/** @file */
//$Id: CConvFileDll.h 261 2016-01-23 03:59:53Z okm $


#if !defined(AFX_CCONVFILEDLL_H__162E52FE_B36F_46AC_970A_5F0CD20B7F20__INCLUDED_)
#define AFX_CCONVFILEDLL_H__162E52FE_B36F_46AC_970A_5F0CD20B7F20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
#include <vector>

#include "..\..\ConvDedFile\interface\IfByteBuffer.h"
#include "..\..\ConvDedFile\interface\IfConvFile.h"
#include "..\..\ConvDedFile\interface\ConvFile2Dll.h"

namespace ConvFile{


/**
  ���̃N���X�́A ConvFileDll ���g�����t�H�[�}�b�g�ϊ����s�����b�p�[�N���X�ł��B

�y�g�����z

�@1.�@�C���X�^���X�𐶐����Ă��������B
 �R���X�g���N�^�����ɂ́ADLL�t�@�C���̃t�@�C�������w�肵�Ă��������B

�@2.�@validate() ���Ăяo���āA�C���X�^���X��L�������Ă��������B
 �@validate()���\�b�h�́AConvFileDll �����[�h���܂��B

  3.  getIfConvFile() �ŁAConvFileDll �� IfConvFile �C���^�[�t�F�[�X��
�擾���邱�Ƃ��ł��܂��BIfConvFile���\�b�h���g���āA�t�@�C���t�H�[�}�b�g��
�ϊ����s�����Ƃ��ł��܂��B

*/
class CConvFileDll  
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		���̃N���X�����p����ConvFileDll�̃t�@�C�����B
		�R���X�g���N�^�Ō��܂�܂��B
	*/
	std::string	m_strDllFilename ;

	///@}
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
		�ʏ��NULL�B
		validate() ���� invalidate() �܂ł́ADLL�̃n���h��������܂��B
	*/
	HMODULE	m_hModule ;

	/**
		�ʏ��NULL�B
		validate() ���� invalidate() �܂ł́A
		DLL�֐���API�ƂȂ�܂��B
	*/
	ConvFile2Dll_getIfConvFile_FUNCPTR	ConvFile2Dll_getIfConvFile ;

	///@}
public:
	// ********************************
	//	�R���X�g���N�^�E�f�X�g���N�^
	// ********************************
	CConvFileDll( const std::string&	strDllFilename );
	virtual ~CConvFileDll();

	// ********************************
	///@name ����
	// ********************************
	///@{
	std::string	getDllFilename()const
	{	return m_strDllFilename ;};
	///@}

	// ********************************
	///@name IfValidate
	// ********************************
	///@{
	/**
	 * 	�@�I�u�W�F�N�g�̏����������s���A�L�������܂��B
	 * 	�@���������ɂ������ĕK�v�ȃp�����[�^�́A�R���X�g���N�^�Ȃǂ�
	 * 	�w�肵�Ă���
	 * 	�K�v������܂��B
	 * @return
	 * 	�@�L�����ɐ���������P�ȏ�A
	 * 	�@���łɗL�������I�����Ă����ꍇ�͂O�A
	 * 	�@�G���[�̏ꍇ�͕��̐���Ԃ��܂��B\n
	 * 	�@���������Ƃ��̂P�ȏ�̒l�̈Ӗ��́A��������N���X�����R�ɒ�`
	 * 	�ł��܂��B\n
	 * 	�@���s�����Ƃ��̕��̐��̈Ӗ����A�����N���X����`�ł��܂��B����ɂ��A
	 * 	���s�̗��R���ƂɈقȂ�G���[�l��Ԃ����Ƃ��ł��܂��B
	 *	-	-1 ;	//	DLL�����[�h�ł��܂���B
	 * 	
	 */
	virtual int validate() ;
	
	/**
	 * 	�@�I�u�W�F�N�g�𖳌������܂��B
	 * 	�@�L�������Ɋm�ۂ������\�[�X���J�����܂��B
	 * 	  �L����ԂłȂ��I�u�W�F�N�g�ɑ΂��ẮA�Ȃɂ����܂���B
	 */
	virtual void invalidate() ;
	
	/**
	 * @return
	 * 	�@���݃I�u�W�F�N�g���L����Ԃł���ΐ^��Ԃ��܂��B
	 */
	virtual bool isValid() ;
	///@}
	// ********************************
	///@name	CConvFile2Dll
	// ********************************
	///@{
	/**
	 * @return
	 * 	�@IfConvFile �C���^�[�t�F�[�X��Ԃ��܂��B
	 */
	IfConvFile* getIfConvFile() ;

	///@}	
};
} //namespace ConvFile

#endif // !defined(AFX_CCONVFILEDLL_H__162E52FE_B36F_46AC_970A_5F0CD20B7F20__INCLUDED_)
