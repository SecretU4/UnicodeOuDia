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
// $Id: CdRessyasyubetsuYColSpecCont.h 179 2014-05-05 13:50:33Z okm $
// ****************************************************************
/** @file */
#pragma once
#ifndef ViewRessyasyubetsu_CdRessyasyubetsuYColSpecCont_h
#define ViewRessyasyubetsu_CdRessyasyubetsuYColSpecCont_h

#include "ViewRessyasyubetsu\RessyasyubetsuColSpec\CdRessyasyubetsuYColSpec.h"
#include "entDed\CentDedRessyasyubetsuCont.h"

namespace ViewRessyasyubetsu{ namespace RessyasyubetsuColSpec{
using namespace entDed;
	
/**
@brief
  列車種別ビューの CWndDcdGridRessyasyubetsu において、グリッドY列の
  各列番号と表示内容の相互変換の機能をを提供します。
  

【使い方】

(1)  デフォルトコンストラクタでインスタンスを生成したあとは、 scan() で
変換に必要な情報を読み込ませてください。

(2)  対応表更新後は、ColumnNumberToSpec(),ColumnNumberFromSpec() で、
列番号と表示内容の相互変換ができます。

*/
class CdRessyasyubetsuYColSpecCont
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/** 
		列車種別の数 。
		scan() で決まります。
		既定値は0です。
	*/
	int m_iRessyasyubetsuCount ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
		scan() と等価です。
	@param pCentDedRessyasyubetsuCont
		列車種別コンテナ。
		このオブジェクトは、関数終了後は破棄できます。
	*/
	CdRessyasyubetsuYColSpecCont( 
		const CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont ) ;
	CdRessyasyubetsuYColSpecCont() ;

public:
	// ********************************
	///@name CdRessyasyubetsuYColSpecCont-属性
	// ********************************
	///@{
	int getRessyasyubetsuCount()const;
	///@}
	// ********************************
	///@name CdRessyasyubetsuYColSpecCont-操作
	// ********************************
	///@{
	/**
		コンテナを走査して、 『列番号-表示内容』の
		変換に必要な情報を読み込みます。
		this がそれまで保持していた内容はすべて失われます。 
	@param pCentDedRessyasyubetsuCont
		列車種別コンテナ。
		このオブジェクトは、関数終了後は破棄できます。
	*/
	void scan( 
		const CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont ) ;

	/**
	@return 
		列数を返します。
	*/
	int size() ;

	/**
		列番号から、表示するべき内容を導出します。
	@param iColumnNumber 
		列番号を指定してください。
	@return
		表示すべき内容を返します。
		列番号が正しくない場合は、NULL状態のオブジェクトを返します。

		戻り値の 
		CdRessyasyubetsuYColSpec::m_eColumnType == 
		ColumnType_NewRessyasyubetsu の場合、
		CdRessyasyubetsuYColSpec::m_iRessyasyubetsuIndex は列車種別数と
		等しくなります。
	*/
	CdRessyasyubetsuYColSpec ColumnNumberToSpec( 
		int iColumnNumber ) ;

	/**
		表示内容に対する列番号を導出します。
	@param aCWndJikokuhyou_CdXColSpec 
		表示内容を指定してください。
	@return
		表示すべき内容を返します。
		対応する列番号がない場合(非表示を含む)は、-1を返します。
	*/
	int ColumnNumberFromSpec( 
		const CdRessyasyubetsuYColSpec& aSpec ) ;


	/**
		this を初期化します。
	*/
	void clear() ;
	///@}
};
} } //namespace RessyasyubetsuColSpec namespace ViewRessyasyubetsu

#endif/*ViewRessyasyubetsu_CdRessyasyubetsuYColSpec_h*/
