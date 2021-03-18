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
//	vectorToFile.h
// ****************************************************************
*/
/** @file 
	@brief
 �y�T�v�z
 	vector<char> �̓��e���t�@�C���֏����o��
 	�t�@�C���̓��e�� vector<char> �ւ̓ǂݍ���
 	���s�������֐��ł��B
*/
#ifndef  vectorToFile_h
#define  vectorToFile_h

#include <vector>
#include <string>

namespace OuLib {
namespace Str {

// ****************************************************************

/**
 	�t�@�C���ɁAaVector �Ɋi�[����Ă���f�[�^���������݂܂��B
 	Win32�̏ꍇ�́A�o�C�i�����[�h�ł̏������݂ƂȂ�܂��B
@param aVector [in]
 	���̊֐��́A���̔z��̓��e���t�@�C���ɏ������݂܂��B
@param strFilename [in]
 	�������ݐ�̃t�@�C�������w�肵�Ă��������B
 	�֐����s�O�Ƀt�@�C�������݂��Ă���ꍇ�́A�����̓��e��j�����܂��B
@return
 	0:����
 	���̐��̓G���[�ł��B
 	- -1:	�t�@�C�����I�[�v���ł��܂���B
 	- -2 ;	//	�������݂Ɏ��s���܂����B
*/
int vectorToFile( const std::vector<char>& aVector , 
					const std::string& strFilename )  ;

/**
 	�t�@�C���̓��e���ApVector �Ɋi�[���܂��B
 	Win32�̏ꍇ�́A�o�C�i�����[�h�ł̓ǂݍ��݂ƂȂ�܂��B
@param pVector [out]
 	���̊֐��́A���̔z��ɁA�t�@�C���̓��e���������݂܂��B
 	�z��ɂ��łɃf�[�^������ꍇ�́A�����̓��e��j�����܂��B
@param strFilename [in]
 	�ǂݍ��ރt�@�C�������w�肵�Ă��������B
@return
 	0:����
 	���̐��̓G���[�ł��B
 	- -1:	�t�@�C�����I�[�v���ł��܂���B
 	- -2 ;	 	�ǂݍ��݂Ɏ��s���܂����B
*/
int vectorFromFile( std::vector<char>* pVector , 
					const std::string& strFilename ) ;

/**
 	�t�@�C���ɁAaString �Ɋi�[����Ă���f�[�^���������݂܂��B
 	Win32�̏ꍇ�́A�e�L�X�g���[�h�ł̏������݂ƂȂ�܂��B
@param aString [in]
 	���̊֐��́A���̕�����̓��e���t�@�C���ɏ������݂܂��B
@param strFilename [in]
 	�������ݐ�̃t�@�C�������w�肵�Ă��������B
 	�֐����s�O�Ƀt�@�C�������݂��Ă���ꍇ�́A�����̓��e��j�����܂��B
@return
 	0:����
 	���̐��̓G���[�ł��B
 	- -1:	�t�@�C�����I�[�v���ł��܂���B
 	- -2 ;	//	�������݂Ɏ��s���܂����B
*/
int stringToFile( const std::string& aString ,
					const std::string& strFilename )  ;

/**
 	�t�@�C���̓��e���ApString �Ɋi�[���܂��B
 	Win32�̏ꍇ�́A�e�L�X�g���[�h�ł̓ǂݍ��݂ƂȂ�܂��B
@param pString [out]
 	���̊֐��́A���̕�����ɁA�t�@�C���̓��e���������݂܂��B
 	�����񂪋�łȂ��ꍇ�́A�����̓��e��j�����܂��B
@param strFilename [in]
 	�ǂݍ��ރt�@�C�������w�肵�Ă��������B
@return
 	0:����
 	���̐��̓G���[�ł��B
 	- -1:	�t�@�C�����I�[�v���ł��܂���B
 	- -2 ;	�ǂݍ��݂Ɏ��s���܂����B
 	- -3 ;	�t�@�C���ɂ� "\0" ���܂܂�܂�(�o�C�i���t�@�C���ł����
			�v���܂�)�B
			���̏ꍇ�ApString �ɂ́A "\0" �̒��O�܂ł̃f�[�^���i�[�����
			���܂��B
*/
int stringFromFile( std::string* pString , 
					const std::string& strFilename ) ;

} //namespace Str {
} //namespace OuLib {

#endif /*vectorToFile_h*/


