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
//	CCalcCentDedDgrRessyasenOfPoint.h
// $Id: CCalcCentDedDgrRessyasenOfPoint.h 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
*/
#ifndef  CCalcCentDedDgrRessyasenOfPoint_h
#define  CCalcCentDedDgrRessyasenOfPoint_h

/** @file */
#include "entDgr\CEnumRessyasen.h"
#include "ViewDiagram\CDcdDiagram.h"

namespace ViewDiagram{

// ****************************************************************
//	CCalcCentDedDgrRessyasenOfPoint
// ****************************************************************
/**
 @brief
	CDcdDiagram::calcCentDedDgrRessyasenOfPoint() 関数内でのみ
	使用するクラスです。
	描画領域内の、『検索対象点』を通っている列車線を調べます。

	【使い方】
	
	１．  コンストラクタで、オブジェクトを生成してください。
	コンストラクタの引数には、列車線の情報を保持している CDcdDiagram 
	オブジェクトと、描画先の IfDcdTarget オブジェクト・
	『検索対象点』を指定してください。
	
	２．  execute() を呼び出してください。
	 execute() は、『検索対象点』を通る列車線を見つけたら、
	その情報を属性  m_eRessyahoukou , m_iRessyaIdx , m_iRessyasenIdx 
	に書き込みます。

 */
class CCalcCentDedDgrRessyasenOfPoint : public CEnumRessyasen
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	typedef CEnumRessyasen	super ;

private:
	// ********************************
	///@name	関連
	// ********************************
	/**
		DcdGridの描画を行うオブジェクト。 
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、 this の破棄が完了するまで 
		生存しなくてはなりません。
	*/
	CDcdDiagram*	m_pCDcdDiagram ;
	/**
		DcdGridの描画先。 
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、 this の破棄が完了するまで 
		生存しなくてはなりません。
	*/
	IfDcdTarget*	m_pIfDcdTarget ;


private:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	/**
		『検索対象点』(DcDraw座標)
		 execute() は、この座標を通る列車線を見つけたら、
		その情報を
		 m_eRessyahoukou , m_iRessyaIdx , m_iRessyasenIdx 
		に設定します。
	 */
	CdDcdPosXy m_CdDcdPosXy ;
	/**
		検索対象点と列車線の間の距離の最大値(DcDraw座標)。
		
		この関数は、m_CdDcdPosXy と列車線との距離が
		このピクセル数以下であれば、
		「m_CdDcdPosXy を列車線が通っている」とみなします。
		0 なら、列車線が座標位置を完全に通っている場合のみ
		該当列車線とみなします。
	 */
	int m_iMerginPixels ;
	/**
		初期値は不定。
		列車線が見つかった場合は、その列車方向。
	 */
	ERessyahoukou m_eRessyahoukou ;
	/**
		初期値は -1 ;
		列車線が見つかった場合は、その列車Index。
	 */
	int m_iRessyaIdx ;
	/**
		初期値は -1 。
		列車線が見つかった場合は、その列車線Index。
	 */
	int m_iRessyasenIdx ;
	///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 @param pCDcdDiagram [in]
		外側の CDcdDiagram オブジェクトとの関連です。 
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		 このオブジェクトは、 this の破棄が完了するまで 
		生存しなくてはなりません。 
	 @param pIfDcdTarget  [in] 
		描画先。 
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、 this の破棄が完了するまで 
		生存しなくてはなりません。
	 @param aCdDcdPosXy [in]
		調査対象の座標。
		 execute() は、この座標を通る列車線を見つけたら、
		その情報を
		 m_eRessyahoukou , m_iRessyaIdx , m_iRessyasenIdx 
		に設定します。
	 @param iMerginPixels [in]
		検索対象点と列車線の間の距離の最大値。
	 @param bDisplayRessyasenKudari [in]
		下り列車の処理を行うか否かを指定します。
		- true ;	//	下り列車の処理を行う。
		- false ;	//	下り列車の処理を行わない。
	 @param bDisplayRessyasenNobori [in]
		上り列車の処理を行うか否かを指定します。
	 */
	CCalcCentDedDgrRessyasenOfPoint( CDcdDiagram* pCDcdDiagram , 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdPosXy& aCdDcdPosXy , int iMarginPixels ,
		bool bDisplayRessyasenKudari , bool bDisplayRessyasenNobori ) ;

// ********************************
//	CDcdDiagram::CEnumRessyasen
// ********************************
 protected:
	/**
		execute() → onCentDedDgrRessya() の順で呼び出される
		関数です。
	
		execute() は、描画可能領域にある
		『ダイヤグラム列車線』 CentDedDgrRessyasen オブジェクト毎に、
		この関数を呼び出します。
		
	 @param eRessyahoukou [in]
		列車方向です。
	 @param iRessyaIdx [in]
		列車インデクスです。
	 @param aCentDedDgrRessya [in]
		『ダイヤグラム列車』 CentDedDgrRessya オブジェクトを指定します。
	 @param iRessyasenIdx [in]
		列車線インデクスです。
	 @param aCentDedDgrRessyasen [in]
		『ダイヤグラム列車線』 CentDedDgrRessyasen 
		オブジェクトを指定します。
		
	 【オーバライド】
		ダイヤグラム列車線が 検索対象点 を通るかを判定します。
		通っている場合は、その属性を
		 m_eRessyahoukou , m_iRessyaIdx , m_iRessyasenIdx 
		に設定します。
	 */
	virtual void onCentDedDgrRessyasen( 
			ERessyahoukou eRessyahoukou ,
			int iRessyaIdx ,
			const CentDedDgrRessya* pCentDedDgrRessya ,
			int iRessyasenIdx ,
			const CentDedDgrRessyasen* pCentDedDgrRessyasen ) ;
// ********************************
//	CCalcCentDedDgrRessyasenOfPoint
// ********************************
 public:
	// ********************************
	///@name CCalcCentDedDgrRessyasenOfPoint-属性
	// ********************************
	///@{
	ERessyahoukou getRessyahoukou()const{	return m_eRessyahoukou ;};
	int getRessyaIdx()const{ return m_iRessyaIdx ;};
	int getRessyasenIdx()const{ return m_iRessyasenIdx ;};
	///@}

};

} //namespace ViewDiagram

#endif //CCalcCentDedDgrRessyasenOfPoint_h
