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

/**
@file
@brief
  OuDia Ver2 �̃t�@�C���`����Ver.3 �ɕϊ����� ConvFileDll �ł��B
  OuDia Ver1 �̃t�@�C���� Ver.3 �ɕϊ����邱�Ƃ��ł��܂��B
*/
//$Id: ConvFileOudia02To03.h 10 2012-08-26 09:48:47Z okm $
#ifndef  ConvFileOudia02To03_h
#define  ConvFileOudia02To03_h
#include "ConvFile2Dll.h"

#ifdef CONVFILEOUDIA02TO03_EXPORTS
#define CONVFILEOUDIA02TO03_API __declspec(dllexport)
#else
#define CONVFILEOUDIA02TO03_API __declspec(dllimport)
#endif

#ifdef   __cplusplus
extern "C"{
#endif //__cplusplus

/**
  DLL �̐ÓI�I�u�W�F�N�g�� IfConvFile �C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
  
�@���̃I�u�W�F�N�g�́A DLL �� FreeLibrary() ����܂ŗL���ł��B

@return 
  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	-	0 ;	//	�ϊ��ɐ������܂����B
	-	-1 ; // �ϊ����̃t�H�[�}�b�g���s���ł��B

*/
CONVFILEOUDIA02TO03_API void* ConvFile2Dll_getIfConvFile( void ) ;

//kyuusi
#if 0
/**
  Left FileFormat �̃t�@�C���t�H�[�}�b�g���ARight FileFormat �ɕϊ����܂��B
  
@param binLeftFile [in]
  Left FileFormat �̃o�C�i���f�[�^(�t�@�C���̓��e��ǂݍ��񂾃������̈�)��
�w�肵�Ă��������B
@param iLeftFileBytes [in]
  binLeftFile �̃o�C�g�����w�肵�Ă��������B
@param pbinRightFile [out]
  ���̊֐��́A�t�@�C���̕ϊ��ɐ���������A�ϊ���̃f�[�^���i�[����
�������̈�̐擪�A�h���X���A�����ɐݒ肵�܂��B
  �֐��ďo���́A���̃f�[�^�̎g�p��́A ConvFile_MemFree �Ń������̈��
������Ȃ��Ă͂Ȃ�܂���B
@param piRightFileBytes [out]
  ���̊֐��́A�t�@�C���̕ϊ��ɐ���������A�ϊ���̃f�[�^�̃o�C�g����
�����ɐݒ肵�܂��B
@return 
  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	-	0 ;	//	�ϊ��ɐ������܂����B
	-	-1 ; // �ϊ����̃t�H�[�}�b�g���s���ł��B
  
@atteintion
  ���̊֐��́ApbinRightFile �� NULL���w�肵���ꍇ�ł��A
�ϊ����s���A�ύX�̌��ʂ�߂�l�ŕԂ��܂��B

*/
CONVFILEOUDIA02TO03_API int ConvFile_leftToRight(
	const CHAR* binLeftFile , 
	DWORD iLeftFileBytes ,
	CHAR** pbinRightFile , 
	DWORD* piRightFileBytes ) ;

/**
  Left FileFormat ���������t�H�[�}�b�g���ۂ��𔻒肵�܂��B
  
  ���̊֐��́A�ȒP�Ȍ����Ńt�H�[�}�b�g�����؂��܂��B
  
@param binLeftFile [in]
  Left FileFormat �̃o�C�i���f�[�^(�t�@�C���̓��e��ǂݍ��񂾃������̈�)��
�w�肵�Ă��������B
@param iLeftFileBytes [in]
  binLeftFile �̃o�C�g�����w�肵�Ă��������B
@return 
  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	-	0 ;	//	�ϊ��ɐ������܂����B
	-	-1 ; // �ϊ����̃t�H�[�}�b�g���s���ł��B
*/
CONVFILEOUDIA02TO03_API int ConvFile_isLeft(
	const CHAR* binLeftFile , 
	DWORD iLeftFileBytes ) ;

/**
  ����DLL���Ԃ����������̈��������܂��B
@param binMem [in]
  ������郁�����̈���w�肵�Ă��������B
  NULL�̏ꍇ�́A�����s���܂���B
*/
CONVFILEOUDIA02TO03_API void ConvFile_MemFree(
	CHAR* binMem ) ;
#endif 

#ifdef   __cplusplus
}
#endif //__cplusplus
#endif //ConvFileOudia02To03_h
