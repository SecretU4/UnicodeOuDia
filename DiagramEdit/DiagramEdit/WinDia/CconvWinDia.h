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
//	CconvWinDia.h
// ****************************************************************
*/
#ifndef  CconvWinDia_h
#define  CconvWinDia_h

/** @file */ 
#include <string>
#include "..\DedRosenFileData\CDedRosenFileData.h"

namespace WinDia{ 
	using namespace DedRosenFileData;
// ****************************************************************
//	CconvWinDia
// ****************************************************************
/**
 *	@brief
 *	【概要】
 *	DiagramEdit のエンティティクラスのオブジェクトの属性データの内容を、
 *	WinDia ファイルに変換する関数を収録しています。
 *	
 *	<H4>
 *	【使い方１－WinDiaファイルの読み込み】
 *	</H4>
 *	
 * １．  WinDiaファイルの内容を、テキストモードで string に
 *	読み込んでください。
 *	これは、 stringFromFile() を使います。
 *
 * ２．  CDedRosenFileData_From_WinDiaFileString() 関数で、
 *	文字列を解釈してください。
 *	この関数は、文字列の内容を CentDedRosen オブジェクトに反映します。
 *	
 *	<H4>
 *	【使い方２－WinDiaファイルに保存】
 *	</H4>
 *	
 * １．  CentDedRosenFileData_To_WinDiaFileString() 関数で、
 *	文字列を生成してください。
 *
 * ２．  １．で生成した文字列を、テキストモードでファイルに
 *	保存してください。
 *	これは、 stringToFile() を使います。
 */
class CconvWinDia
{
// ********************************
//	CconvWinDia
// ********************************
public:

	// ********************************
	//	CDedRosenFileData
	// ********************************
	/**
	 *	  WinDia ファイル形式の文字列 を解釈し、
	 *	 CDedRosenFileData オブジェクトに反映します。
	 *	
	 *	@param pCDedRosenFileData [out]
	 *	  この関数はこのオブジェクトに、属性を反映します。
	 *	@param strWinDiaFileString [in]
	 *	  WinDia ファイル形式の文字列 を指定してください
	 *	(改行文字は、 "\n" でなくてはなりません。
	 *	ファイルをテキストモードで読み込んだ内容を格納してください)。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-21 ;	//	Train00 の番号部分の値が不適切です。
	 */
	int CDedRosenFileData_From_WinDiaFileString(
			CDedRosenFileData* pCDedRosenFileData ,
			const std::string& strWinDiaFileString ) ;

	/**
	 *	 CDedRosenFileData オブジェクトをもとに、
	 *	  WinDia ファイル形式の文字列 を作成します。
	 *	
	 * @param pCDedRosenFileData [in]
	 *	  CDedRosenFileData を指定してください。
	 * @param idxDia [in]
	 *	保存するダイヤのインデクスを指定して下さい。
	 * @param pstrWinDiaFileString [out]
	 *	この関数はこのオブジェクトに
	 *	  WinDia ファイル形式の文字列 を書き込みます。
	 * @return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	- 21 ;	//	WinDIA 形式では、列車種別は24種類までに制限されています。
	 *	- 22 ;	//	略称の長さが半角５文字を超える列車種別があります。
	 *			//	WinDIA 形式に保存するためには、すべての列車種別略称は
	 *			//	全角２文字以内でなくてはなりません。
	 *	- 1 ;	//	idxDia の指定が不正です。
	 */
	int CDedRosenFileData_To_WinDiaFileString( 
			const CDedRosenFileData* pCDedRosenFileData ,
			int idxDia ,
			std::string* pstrWinDiaFileString ) ;
};

} //namespace WinDia
#endif /*convWinDia_h*/
