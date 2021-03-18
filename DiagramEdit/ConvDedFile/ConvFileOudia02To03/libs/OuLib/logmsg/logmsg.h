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
* ****************************************************************
*	LogMsg.h
* ****************************************************************
*/
/** @file
* @brief 
*	�y�T�v�z	�f�o�b�O�p�̃��O���������񂾃e�L�X�g�t�@�C����
* 		�������邽�߂̊֐��Q�ł��B
* 
* 	���̊֐��Q�ŏo�͂��郍�O�e�L�X�g�́A���ꂼ��X�Ɂu���x���v��������
* 	���܂��B
* 	���O�e�L�X�g�o�͎��Ƀ��x���w����ȗ������ꍇ�A����́u���x���Q�v���w��
* 	�������̂Ƃ݂Ȃ��܂��B���x���́A�ȉ��̂悤�ȏd�ݕt����z�肵�Ă��܂��B
* 		- ���ʂ̃f�o�b�O���ɂQ
* 		- ���ʂ������O�o�͂��P�i�K���炵���ꍇ�ɂ����Ă��\�����������O�͂P
* 		- ���ʂ�肳��ɍׂ������e�̃��O��K�v�Ƃ���ꍇ�͂R
* 
* �y�g�����z
*
* �P�D   logmsg_setLogLevel() �ŁA���O�̕W�����x�����w�肵�Ă��������B
* 	�O�́A�S�����O�o�͖����B�Q�Ȃ�A���x���Q�ȉ��̃��x���l������
* 	���O�e�L�X�g�i�P�ƂQ�j���o�͂̑ΏۂɂȂ�܂��B
* 	�܂�A�W�����x���̐������傫���قǁA�o�͂���郍�O�͑����Ȃ�܂��B
* 
* 	  ���ʂ́A���O���o�͂������Ƃ��͂Q�E�������Ȃ��Ƃ��͂O���w�肵�Ă��������B
* 
* 	  ���̊֐����Ăяo���܂ł́A�W�����x���͂O�ɐݒ肳��Ă��܂�
* 	�i���O�͏o�͂���܂���j�B
* 
* �Q�D  ���Ƃ́A LogMsg() �ŁA��������w�肵�Ă��������B���̊֐��́A
* 	���x���Q�ŁA���O���o�͂��܂��B
* 	����LogMsg() �̎g�����́Aprintf()�ɏ����܂��B
* 
* 		(��)	LogMsg( "str=%s" , str ) ;
* 
*     ���x���Q�ȊO�̃��x���̃��O���o�͂���ꍇ�́A LogMsgL() ���g���Ă�
* 	�������B��P���������O�̃��x���ɂȂ�܂��B
* 
* 		(��)	LogMsgL( 3 , "str=%s" , str ) ;
* 
* �y���Ӂz
* -	�P�DLOGMSG_DISABLED �}�N����L���ɂ���ƁA���O���o�͂���R�[�h���A���S��
* 	�����ɂȂ�܂��B���s���x�̗v�����������A�v���P�[�V�����̏ꍇ�́A
* 	�����[�X�r���h���ɁA���̃}�N����L���ɂ��Ă��������B
* -	�Q�D LOGMSG_MILLISEC �}�N����L���ɂ���ƁA���O�Ƀ~���b�P�ʂ̎�����
*	���܂��B
* -	�R�D ���O�t�@�C���ւ̏������݂��w���O�̍ő�s���x�𒴂����ꍇ�A
*	LogMsg() �� LogMsgL() �̓��O�t�@�C������ɂ��܂��B
*	���O�̍ő�s���́A�K��l�ł� 5000 �s�ł����A setLogCountLimit() ��
*	�ύX�ł��܂��B\n
*	  �������A�����ł����w�s���x�́A���ۂɂ�
*	�u�v���Z�X�N���J�n�ォ��́ALogMsg() �� LogMsgL() ���Ăяo�����񐔁v�ł��B
*	���̂��߁ACGI�̂悤�ɏ����̋K�͂̏������v���Z�X���J��Ԃ��N������悤��
*	��ʂł́A���O���ő�s�����z���Ă���ɂ���Ȃ����ƂɂȂ�܂��B
*	  ���̂悤�ȏ�ʂł́A���ɏq�ׂ� LOGMSG_BYTELIMIT �}�N����L����
*	���Ă��������B
* -	�S�D LOGMSG_BYTELIMIT �}�N����L���ɂ���ƁALogMsg() �� LogMsgL()��
*	�������݂̂��тɁA���O�t�@�C���̃T�C�Y�i�o�C�g���j�𒲂ׂ܂��B
*	�T�C�Y���w�ő�s���~80�x�o�C�g�ɒB���Ă����ꍇ�A�t�@�C����
*	��ɂ��܂��B
*/
#ifndef  LOGMSG_H
#define  LOGMSG_H
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C"{
#endif /*__cplusplus*/

/**
 *	���݂ł͈Ӗ�������܂���B\n
 *	���Ă� LogMsg �ł́A�t�H�[�}�b�g������ɑ����������A���̌^��
 *	���肳��Ă��܂����i���̂��߁A"%f" �� "%d" �Ŏ������L�^���邱�Ƃ�
 *	�ł��܂���ł����j�B
 */
typedef unsigned long LOGMSGARG ;

/**
* 	���O�̃t�@�C�������w��ł��܂�
* 	�i�f�t�H���g�́A�J�����g�f�B���N�g����"logmsg.log"�ɂȂ��Ă��܂��j�B
* @param lpszLogFilename [in]
* 	�t�@�C�������w�肵�Ă��������B
*/
void logmsg_setFilename( const char* lpszLogFilename );

/**
* 	���O�̕W�����x����ݒ�ł��܂��B
* @param ev [in]
* 	�W�����x�����w�肵�Ă��������B
*/
void logmsg_setLogLevel( int ev ) ;

/**
* @return
* 	���݂̃��O�̕W�����x����Ԃ��܂��B
*/
int logmsg_getLogLevel() ;

/**
* 	���O�̍ő�s����ݒ�ł��܂��B
* @param ev [in]
* 	�ő�s�����w�肵�Ă��������B
*/
void logmsg_setLogCountLimit( int ev ) ;

/**
* @return
* 	���݂̃��O�̍ő�s����Ԃ��܂��B
*/
int logmsg_getLogCountLimit() ;

/**
 * 	vfprintf() �`���ŁA���O�e�L�X�g�̏o�͂�v�����܂��B
 *	
 * @attention
 *	�ʏ�͂��̊֐��ł͂Ȃ��A LogMsg() �� LogMsgL() ���g���Ă��������B
 *	
 * @param iLevel [in]
 * 	���̃��O�e�L�X�g�̃��O���x�����w�肵�Ă��������B
 * 	���̒l���W�����O���x�������傫���ꍇ�́A���̃e�L�X�g��
 * 	�o�͂��܂���B
 * @param fmt [in]
 * 	���̈����́Avprintf() �̑�1�����ɕ킢�܂��B
 *	�t�H�[�}�b�g��������w�肵�Ă��������B
 * @param argptr [in] 
 * 	���̈����́Avprintf() �̑�2�����ɕ킢�܂��B
 *   �������X�g�ւ̃|�C���^���w�肵�Ă��������B
 */
void logmsg_LogMsgV( int iLevel , const char* fmt , va_list	marker ) ;

/**
 * 	���O�e�L�X�g�̏o�͂�v�����܂��B
 * @attention
 *	�ʏ�́A���̊֐��𒼐ڎg��Ȃ��ł��������B
 *	����ɁA�S��������������� LogMsgL() ���g���Ă��������B
 *	
 * @param iLevel [in]
 * 	���̃��O�e�L�X�g�̃��O���x�����w�肵�Ă��������B
 * 	���̒l���W�����O���x�������傫���ꍇ�́A���̃e�L�X�g��
 * 	�o�͂��܂���B
 * @param fmt [in]
 * 	printf �`���̃t�H�[�}�b�g������B���̂��ƂɁA�ό�����
 *	�����邱�Ƃ��ł��܂��B
 */
void logmsg_LogMsgL( int iLevel , const char* fmt , ... ) ;

/**
 * 	���O�e�L�X�g�̏o�͂��A���O���x���Q�ŗv�����܂��B
 * @attention
 *	�ʏ�́A���̊֐��𒼐ڎg��Ȃ��ł��������B
 *	����ɁA�S��������������� LogMsg() ���g���Ă��������B
 * @param iLevel [in]
 * 	���̃��O�e�L�X�g�̃��O���x�����w�肵�Ă��������B
 * 	���̒l���W�����O���x�������傫���ꍇ�́A���̃e�L�X�g��
 * 	�o�͂��܂���B
 * @param fmt [in]
 * 	printf �`���̃t�H�[�}�b�g������B���̂��ƂɁA�ό�����
 *	�����邱�Ƃ��ł��܂��B
 */
void logmsg_LogMsg( const char* fmt , ... ) ;

#ifdef __cplusplus
};
#endif /*__cplusplus*/


// --------------------------------
//	C++�ŗL
// --------------------------------
#ifdef __cplusplus


#ifndef  LOGMSG_DISABLED
/**
 * 	���O�e�L�X�g�̏o�͂�v�����܂��B
 * @param iLevel [in]
 * 	���̃��O�e�L�X�g�̃��O���x�����w�肵�Ă��������B
 * 	���̒l���W�����O���x�������傫���ꍇ�́A���̃e�L�X�g��
 * 	�o�͂��܂���B
 * @param fmt [in]
 * 	printf �`���̃t�H�[�}�b�g������B���̂��ƂɁA�ό�����
 *	�����邱�Ƃ��ł��܂��B
 * @code
	void LogMsgL( int iLevel , 
			const char* szFmt , ... ) 
 * @endcode
 */
#define LogMsgL	logmsg_LogMsgL


/**
 * 	���O�e�L�X�g�̏o�͂��A���O���x���Q�ŗv�����܂��B
 * @param iLevel [in]
 * 	���̃��O�e�L�X�g�̃��O���x�����w�肵�Ă��������B
 * 	���̒l���W�����O���x�������傫���ꍇ�́A���̃e�L�X�g��
 * 	�o�͂��܂���B
 * @param fmt [in]
 * 	printf �`���̃t�H�[�}�b�g������B���̂��ƂɁA�ό�����
 *	�����邱�Ƃ��ł��܂��B
 * @code
	void LogMsg( 
			const char* szFmt , ... ) ;
 * @endcode
 */
#define LogMsg	logmsg_LogMsg

/**
 * 	���O�e�L�X�g�̏o�͂�v�����܂��B
 * @param iLevel [in]
 * 	���̃��O�e�L�X�g�̃��O���x�����w�肵�Ă��������B
 * 	���̒l���W�����O���x�������傫���ꍇ�́A���̃e�L�X�g��
 * 	�o�͂��܂���B
 * @param szLog [in]
 * 	���O�e�L�X�g���w�肵�Ă��������B
 */
inline void logmsg_LogMsgStr( int iLevel , 
			const char* szLog )
{
	LogMsgL( iLevel , szLog ) ;
}


#else  /*LOGMSG_DISABLED*/
inline void LogMsgL( int iLevel , 
			const char* szFmt , ... ){}
inline void LogMsg( const char* szFmt , ... ){}
inline void logmsg_LogMsgStr( int iLevel , 
			const char* szFmt ){}
#endif /*LOGMSG_DISABLED*/



#else /*__cplusplus*/
/*
// --------------------------------
//	C�ŗL
// --------------------------------
//��   C����̃}�N���͉ό����̋@�\���Ȃ����߁A
//	�p�����[�^�͕K���U�w�肵�Ȃ��Ă͂Ȃ�܂���B
//	�p�̂Ȃ����̂ɂ̓_�~�[�̒l���w�肵�Ă��������B
//	(��)�_�~�[���O�Ŏw�肵�Ă��܂��B
//	LogMsg( "name=%s" , name ,0,0,0,0,0 ) ;
// --------------------------------
*/
#ifndef  LOGMSG_DISABLED

#define LogMsgL(iLevel,szFmt,i0,i1,i2,i3,i4,i5)	\
{\
	logmsg_LogMsgL(iLevel,szFmt,i0,i1,i2,i3,i4,i5);	\
}

#define LogMsg(szFmt,i0,i1,i2,i3,i4,i5)	\
{\
	logmsg_LogMsg(szFmt,i0,i1,i2,i3,i4,i5);	\
}

#define logmsg_LogMsgStr(iLevel ,szLog )	\
{											\
	logmsg_LogMsgL(iLevel,szLog);	\
}											


#else  /*LOGMSG_DISABLED*/
#define LogMsgL(iLevel,szFmt,i0,i1,i2,i3,i4,i5)	
#define LogMsg(szFmt,i0,i1,i2,i3,i4,i5)	
#define logmsg_LogMsgStr(iLevel ,szLog )	
#endif /*LOGMSG_DISABLED*/

#endif /*__cplusplus*/

#endif /*LOGMSG_H*/
