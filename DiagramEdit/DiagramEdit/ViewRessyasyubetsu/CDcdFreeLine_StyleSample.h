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
//	CDcdFreeLine_StyleSample.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdFreeLine_StyleSample_h
#define  CDcdFreeLine_StyleSample_h

#include "DcDraw/CDcdFreeLine.h"

namespace ViewRessyasyubetsu{ 
	using namespace DcDrawLib::DcDraw;
	using namespace DcDrawLib::DcdCd::DcDrawProp;
// ****************************************************************
//	CDcdFreeLine_StyleSample
// ****************************************************************
/**
 * @brief
 * 【概要】
 * 領域内の中央に、左端から右端までの間を結ぶ線を引きます。
 * 線のスタイルの見本を グリッドに表示するのに使います。
 */
class CDcdFreeLine_StyleSample : public IfDcDraw
{
// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 *	線の描画属性。
	 */
	CdDcdFreeLineProp	m_CdLineProp ;
///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param aCdLineProp [in]
	 *	線の描画属性を指定してください。
	 */
	CDcdFreeLine_StyleSample( const CdDcdFreeLineProp& aCdLineProp );
	CDcdFreeLine_StyleSample() ;

// ********************************
///@name	IfDcDraw
// ********************************
///@{
 public:
	/**
	 * 	描画を要求します。
	 * 	この関数は、 pIfDcdTarget に、描画を行います。
	 * @param pIfDcdTarget  [in]
	 * 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 * @return
	 * 	描画を行った場合は真・この領域への描画ができなかった場合は偽です。
	 */
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	 * 	このオブジェクトが描画するアイテムの大きさが決まっている場合は、
	 * 	その大きさを調べることができます。
	 * 	関数呼び出し元が複数の IfDcDraw オブジェクトを描画する場合には、
	 * 	関数呼び出し元は、この関数でアイテムの大きさを調べて、
	 * 	適切なレイアウトを考えてから、DcDraw() を実行することができます。
	 * @param pIfDcdTarget [in]
	 * 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 * @param pCdDcdSizeXy [out]
	 * 	このオブジェクトの描画するアイテムの大きさが決まっている場合は、
	 * 	この関数はこのアドレスに、そのアイテムのサイズを返します。
	 * 	このオブジェクトの描画するアイテムの大きさが決まっていない場合は、
	 * 	この値は不定です。
	 * @return
	 * 	このオブジェクトの描画するアイテムの大きさが決まっていて、
	 * 	その大きさを *pCdDcdSizeXyに書き込んだ場合は真です。
	 * 	そうでない場合は、偽です。
	 *
	 * [オーバライド]
	 *	  X,Yとも、線の太さとなります。
	 */
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
///@}
// ********************************
//	CDcdFreeLine_StyleSample
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	CdDcdFreeLineProp getCdLineProp()const ;
	CDcdFreeLine_StyleSample& setCdLineProp( 
		const CdDcdFreeLineProp& value );
	///@}
};
} //namespace ViewRessyasyubetsu

#endif /*CDcdFreeLine_StyleSample_h*/
