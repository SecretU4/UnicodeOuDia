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
/**
@file
@brief
  このファイルは、ConvFileDllのAPIを定義します。
  
  ConvFileDll は、ファイルフォーマットの変換をオンメモリで行うDLLです。
  ConvFileDll は、通常は ConvFileLeftToRight の形式の
ファイル名を持ちます。Left,Rightは、いずれもファイルフォーマットの名称を表します。
  ConvFileDll は、LeftFileFormat から　RightFileFormat へのフォーマットの変換の機能を
提供します。

*/
//$Id: ConvFileDll.h 10 2012-08-26 09:48:47Z okm $
#ifndef  ConvFileDll_h
#define  ConvFileDll_h
#include <windows.h>
#include <tchar.h>

/**
  Left FileFormat のファイルフォーマットを、Right FileFormat に変換します。
  
@param binLeftFile [in]
  Left FileFormat のバイナリデータ(ファイルの内容を読み込んだメモリ領域)を
指定してください。
@param iLeftFileBytes [in]
  binLeftFile のバイト数を指定してください。
@param pbinRightFile [out]
  この関数は、ファイルの変換に成功したら、変換後のデータを格納した
メモリ領域の先頭アドレスを、ここに設定します。
  関数呼出元は、このデータの使用後は、 ConvFile_MemFree でメモリ領域を
解放しなくてはなりません。
@param piRightFileBytes [out]
  この関数は、ファイルの変換に成功したら、変換後のデータのバイト数を
ここに設定します。
@return 
  成功したら 0 以上、エラーなら負の数です。
	-	0 ;	//	変換に成功しました。
	-	-1 ; // 変換元のフォーマットが不正です。
  
@atteintion
  この関数は、pbinRightFile に NULLを指定した場合でも、
変換を行い、変更の結果を戻り値で返します。

*/
typedef int (*ConvFile_leftToRight_FUNCPTR)(
	const CHAR* binLeftFile , 
	DWORD iLeftFileBytes ,
	CHAR** pbinRightFile , 
	DWORD* piRightFileBytes ) ;
#define ConvFile_leftToRight_FUNCNAME _T( "ConvFile_leftToRight" ) 

/**
  Left FileFormat が正しいフォーマットか否かを判定します。
  
  この関数は、簡単な検査でフォーマットを検証します。
  
@param binLeftFile [in]
  Left FileFormat のバイナリデータ(ファイルの内容を読み込んだメモリ領域)を
指定してください。
@param iLeftFileBytes [in]
  binLeftFile のバイト数を指定してください。
@return 
  成功したら 0 以上、エラーなら負の数です。
	-	0 ;	//	変換に成功しました。
	-	-1 ; // 変換元のフォーマットが不正です。
*/
typedef int (*ConvFile_isLeft_FUNCPTR)(
	const CHAR* binLeftFile , 
	DWORD iLeftFileBytes ) ;
#define ConvFile_isLeft_FUNCNAME _T( "ConvFile_isLeft" ) 

/**
  このDLLが返したメモリ領域を解放します。
@param binMem [in]
  解放するメモリ領域を指定してください。
  NULLの場合は、何も行いません。
*/
typedef void (*ConvFile_MemFree_FUNCPTR)(
	CHAR* binMem ) ;
#define ConvFile_MemFree_FUNCNAME _T( "ConvFile_MemFree" ) 

#endif //ConvFileDll_h
