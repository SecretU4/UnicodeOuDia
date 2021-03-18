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


(訳: 

	OuDia - 列車時刻表をもとに、ダイヤグラムを描画するWin32アプリケーシ
ョン。

Copyright (C) 2006-2017 take-okm 

このプログラムはフリーソフトウェアです。あなたはこれを、フリーソフトウェア財
団によって発行されたGNU 一般公衆利用許諾書(バージョン3か、それ以降のバージョ
ンのうちどれか)が定める条件の下で再頒布または改変 することができます。

このプログラムは有用であることを願って頒布されますが、*全くの無保証 *です。
商業可能性の保証や特定目的への適合性は、言外に示されたものも 含め、全く存在
しません。詳しくはGNU 一般公衆利用許諾書をご覧ください。

あなたはこのプログラムと共に、GNU 一般公衆利用許諾書のコピーを一部 受け取っ
ているはずです。もし受け取っていなければ、<http://www.gnu.org/licenses/> を
ご覧ください。

)

  加えて、特別な例外として、take-okm はこのプログラムのコードを 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  あるいは "MFC Version 9.0" と同じライセンスが適用された
  "MFC Version 9.0" の改変されたバージョン)とリンクし、
  リンクされた両者を含む結合著作物を頒布する許可を与えます。
  あなたは "MFC" 以外で使われているすべて
  のコードに関しては全面的にGNU一般公衆利用許諾契約書に従わなければ
  なりません。あなたがこのファイルを改変したならば、あなたはこの例外
  をあなたのバージョンのファイルに引き続き設けることもできますが、そ
  うする義務はありません。もし例外を設けたくなければ、この例外条項を
  あなたのバージョンからは削除してください。)
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
 * 	現在のログの標準レベルです。
 * 	デフォルトは０です。
 * 	logmsg_setLogLevel() で、変更できます。
 */
static int  g_iLogLevel = 0 ;

/**
 * 	現在のログの行数です
 * 	logmsg_LogMsgStr() 関数は、
 *  ログを追加する毎に、この値も更新します。
 */
static int	g_iLogCount = 0 ;

/**
 * 	ログの最大行数。
 * 	LogMsg() や LogMsgL() は、
 *  ログの行数がこの値に達していたら、
 * 	ログファイルを空にします。
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
			//	行数が g_iLogCountLimit に達していたら、既存の内容を
			//	破棄します。
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
					//	サイズが『最大行数×80』バイトに達していた場合、
					//	既存の内容を破棄します。
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
			//	ログをファイルに追加します。
	
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

