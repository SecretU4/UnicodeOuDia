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
//	CDcdFillrectRop.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdFillrectRop_h
#define  CDcdFillrectRop_h

#include "IfDcDraw.h"
#include "DcdCd\DcDrawProp\CdPenProp.h"
#include "DcdCd\DcDrawProp\CdBrushProp.h"

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CDcdFillrectRop
// ****************************************************************
/**
 @brief
 【概要】
  DcDrawモデルオブジェクトです。領域を塗りつぶします。
  CDcdFillRectとは異なり、ROP(ラスタオペレーション)を適用できます。

  このオブジェクトに対して DcDraw() を呼び出すと、その領域全体を、
属性で指定された色（ハッチパターンも可）で塗ります。

  このクラスでは、ROP(ラスタオペレーション)を指定することにより、
「現在の画面上の描画内容を白黒反転する、といった描画ができます」

@note

  CDcdFillRect には、ROPを適用することができません。
  CDcdRectangle にはROPを適用できますが、CDcdRectangleで領域の塗りつぶしを行うと、
塗りつぶし領域が右1ピクセル・下1ピクセル狭くなります。
  このクラスでは、この２つの問題を解消しています。
  このため、Rectangle() API の引数には1ピクセル右下に広い値を渡します。
  
*/
class CDcdFillrectRop : public IfDcDraw
{
// ********************************
///	@name 属性
// ********************************
///@{
 private:
	/**
	　塗りつぶしに使用するブラシの属性を保持します。
	*/
	CdBrushProp	m_CdBrushProp	;
	/**
		前景モードを R2 定数で指定します。
		既定値は、R2_COPYPEN です。
	*/
	int m_iR2DrawMode	;
	
///@}
	
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	@param aCdBrushProp
		塗りつぶしに使用するブラシの属性を指定してください。
	@param iR2DrawMode [in]
		前景モードを R2 定数で指定してください。
		既定値は、R2_COPYPEN です。
	@see SetROP2()
	*/
	CDcdFillrectRop( 
		const CdBrushProp& aCdBrushProp , 
		int iR2DrawMode )	;
	CDcdFillrectRop() ;
	virtual ~CDcdFillrectRop() ;
	
// ********************************
///@name	IfDcDraw
// ********************************
///@{
 public:
	/**
	 描画を要求します。
	この関数は、 pIfDcdTarget に、描画を行います。
	
	【オーバライド】
	  渡された領域を、ブラシで塗りつぶします。
	 @param pIfDcdTarget  [in]
	 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 @return
	 	描画を行った場合は真・この領域への描画ができなかった場合は偽です。
	*/
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	 このオブジェクトが描画するアイテムの大きさが決まっている場合は、
 	その大きさを調べることができます。
 	関数呼び出し元が複数の IfDcDraw オブジェクトを描画する場合には、
 	関数呼び出し元は、この関数でアイテムの大きさを調べて、
 	適切なレイアウトを考えてから、DcDraw() を実行することができます。

	【オーバライド】
	  このクラスでは、サポートしていません。
	 @param pIfDcdTarget [in]
	 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 @param pCdDcdSizeXy [out]
	 	このオブジェクトの描画するアイテムの大きさが決まっている場合は、
	 	この関数はこのアドレスに、そのアイテムのサイズを返します。
	 	このオブジェクトの描画するアイテムの大きさが決まっていない場合は、
	 	この値は不定です。
	 @return
	 	このオブジェクトの描画するアイテムの大きさが決まっていて、
	 	その大きさを *pCdDcdSizeXyに書き込んだ場合は真です。
	 	そうでない場合は、偽です。

		【オーバライド】  偽を返します。
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
///@}
// ********************************
//	CDcdFillrectRop
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	virtual CdBrushProp	getCdBrushProp(){	return m_CdBrushProp	;	} ;
	virtual CDcdFillrectRop& setCdBrushProp( const CdBrushProp& ev ){
		m_CdBrushProp	= ev ;	return *this ; } ;
	virtual int getR2DrawMode()const{	return m_iR2DrawMode	;};
	virtual CDcdFillrectRop& setR2DrawMode( int value )
	{	m_iR2DrawMode = value ;	return *this 	;};
	///@}
};

} //namespace DcDraw
} //namespace DcDrawLib
#endif /*CDcdFillrectRop_h*/
