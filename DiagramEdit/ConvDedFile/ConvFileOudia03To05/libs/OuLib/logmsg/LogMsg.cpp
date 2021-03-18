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
//	LogMsg.cpp
// ****************************************************************
*/

#include <time.h>
#include <stdio.h>
#include <string.h>

#ifdef  LOGMSG_MILLISEC
#include <sys/types.h>
#include <sys/timeb.h>
#ifdef   _MSC_VER
#define	ftime	_ftime
#define	timeb	_timeb
#endif /*_MSC_VER*/
#endif /*LOGMSG_MILLISEC*/


#ifdef  LOGMSG_BYTELIMIT
#include <sys/types.h> 
#include <sys/stat.h> 
#ifdef   _MSC_VER
#define	stat	_stat
#else  /*_MSC_VER*/
#include <unistd.h> 
#endif  /*_MSC_VER*/
#endif /*LOGMSG_BYTELIMIT*/


#include "LogMsg.h"

static char g_szLogFilename[256] = "logMsg.log" ;

/**
 * 	���݂̃��O�̕W�����x���ł��B
 * 	�f�t�H���g�͂O�ł��B
 * 	logmsg_setLogLevel() �ŁA�ύX�ł��܂��B
 */
static int  g_iLogLevel = 0 ;

/**
 * 	���݂̃��O�̍s���ł�
 * 	logmsg_LogMsgStr() �֐��́A
 *  ���O��ǉ����閈�ɁA���̒l���X�V���܂��B
 */
static int	g_iLogCount = 0 ;

/**
 * 	���O�̍ő�s���B
 * 	LogMsg() �� LogMsgL() �́A
 *  ���O�̍s�������̒l�ɒB���Ă�����A
 * 	���O�t�@�C������ɂ��܂��B
 */
static int g_iLogCountLimit = 5000 ;

void logmsg_setFilename( const char* lpszLogFilename )
{
	strncpy( g_szLogFilename , lpszLogFilename , 
		sizeof(g_szLogFilename) / sizeof(g_szLogFilename[0]) ) ;
	g_szLogFilename
		[ sizeof(g_szLogFilename) / sizeof(g_szLogFilename[0]) - 1 ] = '\0' ;
}

void logmsg_setLogLevel( int ev )
{
	g_iLogLevel = ev ;
}

int logmsg_getLogLevel()
{
	return ( g_iLogLevel ) ;
}
void logmsg_setLogCountLimit( int ev ) 
{
	g_iLogCountLimit = ev ;
}
int logmsg_getLogCountLimit() 
{
	return ( g_iLogCountLimit ) ;
}


void logmsg_LogMsgV( int iLevel , const char* fmt , va_list	marker ) 
{
	if ( iLevel <= g_iLogLevel ){
		if ( g_iLogCount >= g_iLogCountLimit ){
			//	�s���� g_iLogCountLimit �ɒB���Ă�����A�����̓��e��
			//	�j�����܂��B
			FILE*	pFile = fopen( g_szLogFilename , "wt" ) ;
		
			if ( pFile != NULL ){
				fclose( pFile ) ;
				g_iLogCount = 0 ;
			}
		}
#ifdef  LOGMSG_BYTELIMIT
		{
			struct stat	aStat ;
			if ( stat( g_szLogFilename , &aStat ) == 0 ){
				if ( aStat.st_size >= g_iLogCountLimit * 80 ){
					//	�T�C�Y���w�ő�s���~80�x�o�C�g�ɒB���Ă����ꍇ�A
					//	�����̓��e��j�����܂��B
					FILE*	pFile = fopen( g_szLogFilename , "wt" ) ;
		
					if ( pFile != NULL ){
						fclose( pFile ) ;
						g_iLogCount = 0 ;
					}
				}
			}
		}
#endif /*LOGMSG_BYTELIMIT*/
		{
			//	���O���t�@�C���ɒǉ����܂��B
	
			FILE*	pFile = fopen( g_szLogFilename , "a+" ) ;
			if ( pFile != NULL ){
#ifdef  LOGMSG_MILLISEC
				struct timeb aTimeb ;
				ftime( &aTimeb ) ;
				struct tm Localtime = *localtime( &aTimeb.time );
				fprintf( pFile , "[%02d:%02d:%02d]" , 
							Localtime.tm_hour , 
							Localtime.tm_min ,
							Localtime.tm_sec ) ; 
				fprintf( pFile , "[%03d]" , 
							aTimeb.millitm ) ;
#else /*LOGMSG_MILLISEC*/
				time_t	aTime = time( NULL ) ;
				struct tm Localtime = *localtime( &aTime );
				fprintf( pFile , "[%02d:%02d:%02d]" , 
							Localtime.tm_hour , 
							Localtime.tm_min ,
							Localtime.tm_sec ) ;
#endif /*LOGMSG_MILLISEC*/
				vfprintf( pFile , fmt , marker ) ;
				fputc( '\n' , pFile ) ; 
				fclose( pFile ) ;
				g_iLogCount ++ ;
			}
		}
	}
	
}

void logmsg_LogMsgL( int iLevel , const char* fmt , ... ) 
{
	va_list	marker ;	
	va_start( marker, fmt );   
	logmsg_LogMsgV(  iLevel ,  fmt , marker )  ;
}

void logmsg_LogMsg( const char* fmt , ... ) 
{
	va_list	marker ;	
	va_start( marker, fmt );   
	logmsg_LogMsgV( 2 ,  fmt , marker )  ;
}

