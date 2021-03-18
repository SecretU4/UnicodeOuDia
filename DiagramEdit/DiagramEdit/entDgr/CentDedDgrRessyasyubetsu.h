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
//	CentDedDgrRessyasyubetsu.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrRessyasyubetsu_h
#define  CentDedDgrRessyasyubetsu_h
#include "DcdCd\DcDrawProp\CdColorProp.h"
#include "DcdCd\DcDrawProp\CdDcdFreeLineProp.h"
#include "entDed\CentDedRessyasyubetsu.h"

namespace entDgr{

// ****************************************************************
//	CentDedDgrRessyasyubetsu
// ****************************************************************
/**
@brief
【概要】
『ダイヤグラムエンティティクラス群』の『列車種別』クラスです。
『ダイヤ』 (CentDedDgrDia) に含まれる『列車種別』１つを表します。

このクラスは、『ダイヤグラムダイヤ』 (CentDedDgrDia) に包含されます。

CentDedDgrDia : CentDedDgrRessyasyubetsu の多重度は、

１：（『列車種別』の数） 

となります。

これは、

（『路線』(CentDedRosen)）：（『列車種別』（CentDedRessyasyubetsu））

の多重度と同じです。

【使い方】

  原則では、このクラスのオブジェクトを生成するのは、
『ダイヤグラムダイヤ』 (CentDedDgrDia) クラスにのメソッドだけです。
クラスユーザーはこのクラスのオブジェクトを直接生成する用事はなく、
『ダイヤグラムダイヤ』 (CentDedDgrDia) クラスによって生成された
オブジェクトの属性を参照するだけです。

 */
class CentDedDgrRessyasyubetsu
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)
	
		規定値は、黒。
	 */
	CdColorProp	m_colorJikokuhyouMojiColor ;

	/**
		列車線(直線)の線の形状属性。
	*/
	CentDedRessyasyubetsu::CdDiagramLineStyle	m_CdDiagramLineStyle ;

	/**
		列車種別毎の、停車駅明示の方法。
		既定値は、 EStopMarkDrawType_DrawOnStop 。
	*/
	CentDedRessyasyubetsu::EStopMarkDrawType m_eStopMarkDrawType ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CentDedDgrRessyasyubetsu() :
	  m_eStopMarkDrawType( CentDedRessyasyubetsu::EStopMarkDrawType_DrawOnStop )
	  {}
	
	CentDedDgrRessyasyubetsu(
		const CdColorProp& colorJikokuhyouMojiColor ,
		CentDedRessyasyubetsu::CdDiagramLineStyle aCdDiagramLineStyle ,
		//const CdDcdFreeLineProp& aLineProp ,
		CentDedRessyasyubetsu::EStopMarkDrawType eStopMarkDrawType ) 
		:
		m_colorJikokuhyouMojiColor( colorJikokuhyouMojiColor ) ,
		m_CdDiagramLineStyle( aCdDiagramLineStyle ) ,
		m_eStopMarkDrawType( eStopMarkDrawType ){}
public:
	// ********************************
	///@name CentDedDgrRessyasyubetsu::属性
	// ********************************
	CdColorProp	getJikokuhyouMojiColor()const
	{	return m_colorJikokuhyouMojiColor ;};
	CentDedRessyasyubetsu::CdDiagramLineStyle	getCdDiagramLineStyle()const
	{	return m_CdDiagramLineStyle ;};
	CentDedRessyasyubetsu::EStopMarkDrawType getStopMarkDrawType()const
	{	return m_eStopMarkDrawType ;};

};

} //namespace entDgr



#endif /*CentDedDgrRessyasyubetsu_h*/


