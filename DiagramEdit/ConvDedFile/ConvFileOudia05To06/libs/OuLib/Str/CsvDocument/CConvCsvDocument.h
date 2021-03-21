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
// ****************************************************************
//	$Id: CConvCsvDocument.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
/** @file */
#ifndef  CConvCsvDocument_h
#define  CConvCsvDocument_h
#include "CdCsvDocument.h"
#include <string>

/**
@brief
	CdCsvDocument オブジェクトと、CSVファイル(の内容を格納した文字列)の間の
	文字列の変換を行います。

	基本的には、1行の区切りが '\n' 、 行内のセルの区切りが ',' と
	なります。

	以下の変換を行います。

	- 改行・二重引用符を含むセル→全体を二重引用符で囲みます。
	- 二重引用符内の二重引用符→二重引用符２つにします。
*/
class CConvCsvDocument
{
protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
		セルの内容を、CSV形式の文字列に変換します。

		- 改行・二重引用符を含むセル→全体を二重引用符で囲みます。
		- 二重引用符内の二重引用符→二重引用符２つにします。
	*/
	std::string encodeCell( const CdCsvCell& aCdCsvCell ) ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CConvCsvDocument(void);
	~CConvCsvDocument(void);

public:
	// ********************************
	///@name	CConvCsvDocument
	// ********************************
	///@{
	/**
		CdCsvDocument の内容を、CSVファイル形式の
		テキストに変換します。
	@param pCdCsvDocument [in]
		CdCsvDocument を指定してください。
	@return 
		変換結果のテキストを返します。
	*/
	std::string encode( const CdCsvDocument* pCdCsvDocument ) ;

	/**
		CSV 形式のテキストを解釈し、結果を
		CdCsvDocument オブジェクトに追加します。
	@param pCdCsvDocument [out]
		この関数はこのオブジェクトに、
		strCsvText を解釈した結果を追加します。
	@param strCsvText [in]
		Csv 形式のテキストを指定してください。
	@return 
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	引用符が閉じていません
	*/
	int decode( CdCsvDocument* pCdCsvDocument 
		, const std::string& strCsvText ) ;

	///@}
};
#endif //CConvCsvDocument_h
