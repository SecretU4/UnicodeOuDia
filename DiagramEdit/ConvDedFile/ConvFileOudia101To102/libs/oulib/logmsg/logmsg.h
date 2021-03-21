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
* ****************************************************************
*	LogMsg.h
* ****************************************************************
*/
/** @file
* @brief 
*	【概要】	デバッグ用のログを書き込んだテキストファイルを
* 		生成するための関数群です。
* 
* 	この関数群で出力するログテキストは、それぞれ個々に「レベル」を持って
* 	います。
* 	ログテキスト出力時にレベル指定を省略した場合、それは「レベル２」を指定
* 	したものとみなします。レベルは、以下のような重み付けを想定しています。
* 		- 普通のデバッグ情報に２
* 		- 普通よりもログ出力を１段階減らした場合においても表示したいログは１
* 		- 普通よりさらに細かい内容のログを必要とする場合は３
* 
* 【使い方】
*
* １．   logmsg_setLogLevel() で、ログの標準レベルを指定してください。
* 	０は、全くログ出力無し。２なら、レベル２以下のレベル値を持つ
* 	ログテキスト（１と２）が出力の対象になります。
* 	つまり、標準レベルの数字が大きいほど、出力されるログは多くなります。
* 
* 	  普通は、ログを出力したいときは２・したくないときは０を指定してください。
* 
* 	  この関数を呼び出すまでは、標準レベルは０に設定されています
* 	（ログは出力されません）。
* 
* ２．  あとは、 LogMsg() で、文字列を指定してください。この関数は、
* 	レベル２で、ログを出力します。
* 	このLogMsg() の使い方は、printf()に準じます。
* 
* 		(例)	LogMsg( "str=%s" , str ) ;
* 
*     レベル２以外のレベルのログを出力する場合は、 LogMsgL() を使ってく
* 	ださい。第１引数がログのレベルになります。
* 
* 		(例)	LogMsgL( 3 , "str=%s" , str ) ;
* 
* 【注意】
* -	１．LOGMSG_DISABLED マクロを有効にすると、ログを出力するコードが、完全に
* 	無効になります。実行速度の要件が厳しいアプリケーションの場合は、
* 	リリースビルド時に、このマクロを有効にしてください。
* -	２． LOGMSG_MILLISEC マクロを有効にすると、ログにミリ秒単位の時刻が
*	つきます。
* -	３． ログファイルへの書き込みが『ログの最大行数』を超えた場合、
*	LogMsg() や LogMsgL() はログファイルを空にします。
*	ログの最大行数は、規定値では 5000 行ですが、 setLogCountLimit() で
*	変更できます。@n
*	  ただし、ここでいう『行数』は、実際には
*	「プロセス起動開始後からの、LogMsg() や LogMsgL() を呼び出した回数」です。
*	このため、CGIのように処理の規模の小さいプロセスが繰り返し起動するような
*	場面では、ログが最大行数を越えても空にされないことになります。
*	  このような場面では、次に述べる LOGMSG_BYTELIMIT マクロを有効に
*	してください。
* -	４． LOGMSG_BYTELIMIT マクロを有効にすると、LogMsg() や LogMsgL()は
*	書き込みのたびに、ログファイルのサイズ（バイト数）を調べます。
*	サイズが『最大行数×80』バイトに達していた場合、ファイルを
*	空にします。
*/
#ifndef  LOGMSG_H
#define  LOGMSG_H
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C"{
#endif /*__cplusplus*/

/**
* 	ログのファイル名を指定できます
* 	（デフォルトは、カレントディレクトリの"logmsg.log"になっています）。
* @param lpszLogFilename [in]
* 	ファイル名を指定してください。
*/
void logmsg_setFilename( const char* lpszLogFilename );

/**
* 	ログの標準レベルを設定できます。
* @param ev [in]
* 	標準レベルを指定してください。
*/
void logmsg_setLogLevel( int ev ) ;

/**
* @return
* 	現在のログの標準レベルを返します。
*/
int logmsg_getLogLevel() ;

/**
* 	ログの最大行数を設定できます。
* @param ev [in]
* 	最大行数を指定してください。
*/
void logmsg_setLogCountLimit( int ev ) ;

/**
* @return
* 	現在のログの最大行数を返します。
*/
int logmsg_getLogCountLimit() ;

/**
 * 	vfprintf() 形式で、ログテキストの出力を要求します。
 *	
 * @attention
 *	通常はこの関数ではなく、 LogMsg() か LogMsgL() を使ってください。
 *	
 * @param iLevel [in]
 * 	このログテキストのログレベルを指定してください。
 * 	この値が標準ログレベルよりも大きい場合は、このテキストは
 * 	出力しません。
 * @param fmt [in]
 * 	この引数は、vprintf() の第1引数に倣います。
 *	フォーマット文字列を指定してください。
 * @param argptr [in] 
 * 	この引数は、vprintf() の第2引数に倣います。
 *   引数リストへのポインタを指定してください。
 */
void logmsg_LogMsgV( int iLevel , const char* fmt , va_list	marker ) ;

/**
 * 	ログテキストの出力を要求します。
 * @attention
 *	通常は、この関数を直接使わないでください。
 *	代わりに、全く同じ動作をする LogMsgL() を使ってください。
 *	
 * @param iLevel [in]
 * 	このログテキストのログレベルを指定してください。
 * 	この値が標準ログレベルよりも大きい場合は、このテキストは
 * 	出力しません。
 * @param fmt [in]
 * 	printf 形式のフォーマット文字列。このあとに、可変個引数を
 *	続けることができます。
 */
void logmsg_LogMsgL( int iLevel , const char* fmt , ... ) ;

/**
 * 	ログテキストの出力を、ログレベル２で要求します。
 * @attention
 *	通常は、この関数を直接使わないでください。
 *	代わりに、全く同じ動作をする LogMsg() を使ってください。
 * @param iLevel [in]
 * 	このログテキストのログレベルを指定してください。
 * 	この値が標準ログレベルよりも大きい場合は、このテキストは
 * 	出力しません。
 * @param fmt [in]
 * 	printf 形式のフォーマット文字列。このあとに、可変個引数を
 *	続けることができます。
 */
void logmsg_LogMsg( const char* fmt , ... ) ;

#ifdef __cplusplus
};
#endif /*__cplusplus*/


// --------------------------------
//	C++固有
// --------------------------------
#ifdef __cplusplus


#ifndef  LOGMSG_DISABLED
/**
 * 	ログテキストの出力を要求します。
 * @param iLevel [in]
 * 	このログテキストのログレベルを指定してください。
 * 	この値が標準ログレベルよりも大きい場合は、このテキストは
 * 	出力しません。
 * @param fmt [in]
 * 	printf 形式のフォーマット文字列。このあとに、可変個引数を
 *	続けることができます。
 * @code
	void LogMsgL( int iLevel , 
			const char* szFmt , ... ) 
 * @endcode
 */
#define LogMsgL	logmsg_LogMsgL


/**
 * 	ログテキストの出力を、ログレベル２で要求します。
 * @param iLevel [in]
 * 	このログテキストのログレベルを指定してください。
 * 	この値が標準ログレベルよりも大きい場合は、このテキストは
 * 	出力しません。
 * @param fmt [in]
 * 	printf 形式のフォーマット文字列。このあとに、可変個引数を
 *	続けることができます。
 * @code
	void LogMsg( 
			const char* szFmt , ... ) ;
 * @endcode
 */
#define LogMsg	logmsg_LogMsg

/**
 * 	ログテキストの出力を要求します。
 * @param iLevel [in]
 * 	このログテキストのログレベルを指定してください。
 * 	この値が標準ログレベルよりも大きい場合は、このテキストは
 * 	出力しません。
 * @param szLog [in]
 * 	ログテキストを指定してください。
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
//	C固有
// --------------------------------
//※   C言語のマクロは可変個引数の機能がないため、
//	パラメータは必ず６つ指定しなくてはなりません。
//	用のないものにはダミーの値を指定してください。
//	(例)ダミーを０で指定しています。
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
