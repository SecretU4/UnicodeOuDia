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
//	CGdiCache.h
// ****************************************************************
*/
/** @file */
#ifndef  CGdiCache_h
#define  CGdiCache_h

#include <windows.h>
#include <map>
#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcdCd\DcDrawProp\CdPenProp.h"
#include "DcdCd\DcDrawProp\CdBrushProp.h"

// ****************************************************************
//	CGdiCache
// ****************************************************************
/**
 * @brief
 *	GDIオブジェクトの属性と、ハンドルの対照表を保持します。
 *	対照表にエントリがない場合は、GDIオブジェクトのハンドルを生成して、
 *	対照表に追加します。
 *
 *	対照表に追加したエントリのGDIオブジェクトのハンドルの破棄の責務は、
 *	this にあります。
 *
 * 【使い方】
 *
 *	１．  コンストラクタでオブジェクトを生成してください。
 *
 *	２．  CreateFont() を使うと、指定された属性 CdFontProp に対応する
 *	フォントハンドルを生成して返します。同時に、属性とハンドルを対照表
 *	 m_HFONTMap に登録します。
 *	  次に同じ属性で CreateFont() が呼び出された場合は、前回の
 *	フォントハンドルを返します。
 *	
 *	３．  デストラクタでは、対照表 m_HFONTMap に登録されている
 *	フォントハンドルをすべて解放します。
 */
class CGdiCache
{
// ********************************
//	インナータイプ
// ********************************
 public:

	typedef std::map< CdFontProp , HFONT >	HFONTMap ;
	typedef std::map< CdPenProp , HPEN >	HPENMap ;
	typedef std::map< CdBrushProp , HBRUSH >	HBRUSHMap ;

// ********************************
///@name 集約
// ********************************
///@{
 private:
	/**
	 *	フォント属性とフォントハンドルの対照表です。
	 *	HFONT の破棄の責務は this にあります。
	 */
	HFONTMap	m_HFONTMap ;
	/**
	 *	ペン属性とペンハンドルの対照表です。
	 *	HPEN の破棄の責務は this にあります。
	 */
	HPENMap	m_HPENMap ;
	/**
	 *	ブラシ属性とブラシハンドルの対照表です。
	 *	HBRUSH の破棄の責務は this にあります。
	 */
	HBRUSHMap	m_HBRUSHMap ;
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	CGdiCache() ;
	virtual ~CGdiCache() ;

// ********************************
//	CGdiCache
// ********************************
 public:
	/**
	 * 	CdFontPropオブジェクトの属性をもとに、フォントを生成します
	 * @param aCdFontProp [in]
	 * 	フォント属性を指定してください。
	 * @param hDc [in]
	 * 	CdFontProp オブジェクトに設定されている高さ属性が
	 * 	PointTextHeight で指定されている場合は、LOGFONTに変換
	 * 	する際には、その変換には、フォントの描画を行うHDCが必要です。
	 * 	ここには、そのHDCを指定してください。
	 * 	もし、このケースでHDCに NULL を指定した場合は、スクリーンDCを
	 * 	もとにLOGFONT構造体を作成します。
	 * 	CdFontProp オブジェクトに設定されている高さ属性が
	 * 	Logicalunit... で指定されている場合は、このHDCには
	 * 	意味がありません。
	 * @return
	 *	フォントのハンドルを返します。
	 *	このハンドルの破棄の責務は、thisにあります。
	 *	関数呼出元は、ハンドルを解放してはいけません。
	 */
	virtual HFONT	CreateFont(  const CdFontProp& aCdFontProp , 
			HDC hDc ) ;
	
	/**
	 * 	CdPenPropオブジェクトの属性をもとに、ペンを生成します
	 * @param aCdPenProp [in]
	 * 	ペン属性を指定してください。
	 * @return
	 *	ペンのハンドルを返します。
	 *	このハンドルの破棄の責務は、thisにあります。
	 *	関数呼出元は、ハンドルを解放してはいけません。
	 */
	virtual HPEN	CreatePen(  const CdPenProp& aCdPenProp ) ;

	/**
	 * 	CdBrushPropオブジェクトの属性をもとに、ペンを生成します
	 * @param aCdBrushProp [in]
	 * 	ペン属性を指定してください。
	 * @return
	 *	ペンのハンドルを返します。
	 *	このハンドルの破棄の責務は、thisにあります。
	 *	関数呼出元は、ハンドルを解放してはいけません。
	 */
	virtual HBRUSH	CreateBrush(  const CdBrushProp& aCdBrushProp ) ;
};
#endif /*CGdiCache_h*/

