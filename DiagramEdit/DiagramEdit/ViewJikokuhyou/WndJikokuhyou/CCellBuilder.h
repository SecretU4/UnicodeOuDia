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
//	ViewJikokuhyou\WndJikokuhyou\CCellBuilder.h
//	$Id: CCellBuilder.h 179 2014-05-05 13:50:33Z okm $
// ****************************************************************
*/

/** @file */
#ifndef  ViewJikokuhyou_WndJikokuhyou_CCellBuilder_h
#define  ViewJikokuhyou_WndJikokuhyou_CCellBuilder_h

#include "DedRosenFileData\CDedRosenFileData.h"
#include "ViewJikokuhyou\WndJikokuhyou\CWndJikokuhyou.h"
#include "ViewJikokuhyou\JikokuhyouColSpec\JikokuhyouColSpec.h"

namespace ViewJikokuhyou{
namespace WndJikokuhyou{

using namespace std ;
using namespace DcDrawLib ;
using namespace OuMfc;
using namespace DedRosenFileData;

/**
@brief
	CWndJikokuhyou のセルを構築するクラスです。

【使い方】

　(1)　コンストラクタでオブジェクトを生成してください。
　
　(2)　update() で、CWndJikokuhyou のすべてのセルを更新します。

　(3)　列車のみの更新の場合は、 update() の代わりに replaceRessya()を
使うことができます。

【セルの更新手順】

　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。
　
　(1.1)　CWndDcdGrid の外枠線のDcDrawオブジェクトと、線幅を設定

　(1.2)　列の数を設定します。
　X列数が2未満なら2にします。Y列数は、CdYColSpecCont で導出された列数とします。
　
　(1.3)　X列(ColumnType_Ekimei) の各セルと、すべてのY列の高さ・Y列境界線・Y列境界線の高さ設定

　(1.3.1)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) と、Y列(ColumnType_Ressyabangou)の高さ・Y列境界線・Y列境界線の高さ設定

　(1.3.*.1)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) の結合セルの属性を設定。

　(1.3.*.2)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) のDcDrawオブジェクトの型を設定( CDcdTextbox とする)。

　(1.3.*.3)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) DcDrawオブジェクトに、属性を設定。

　(1.3.*.4)　Y列(ColumnType_Ressyabangou) のセルの高さを設定

　(1.3.*.5)　Y列(ColumnType_Ressyabangou) の境界線のDcDrawオブジェクト に属性を設定。

　(1.3.*.6)　Y列ColumnType_Ressyabangou) の境界線の高さを設定

　(1.3.2)　同様に、セル(ColumnType_Ekimei, ColumnType_Ressyasyubetsu〜 ColumnType_Bikou ) と、Y列(ColumnType_Ressyasyubetsu〜 ColumnType_Bikou)の高さ・Y列境界線・Y列境界線の高さを設定。

　(1.3.3)　X列(ColumnType_Ekimei ) の幅を設定。幅は、駅名列の DcDraw オブジェクトの幅とします。

　(1.3.4)　X列(ColumnType_Ekimei ) の境界線の DcDrawオブジェクトの属性を設定。

　(1.3.5)　X列(ColumnType_Ekimei ) の境界線の幅を設定。

　(1.4)　X列(ColumnType_Chakuhatsu) の各セルを設定

　(1.4.1)　セル(ColumnType_Chakuhatsu, ColumnType_Ekijikoku_Chaku〜 ColumnType_Ekijikoku_Hatsu) を設定。

　(1.4.1.2)　DcDrawオブジェクトの型を設定( CDcdTextbox とする)。

　(1.4.1.3)　DcDrawオブジェクトに、属性を設定。

　(1.4.3)　X列(ColumnType_Chakuhatsu ) の幅を設定。幅は、着発列の DcDraw オブジェクトの幅とします。

　(1.4.4)　X列(ColumnType_Chakuhatsu ) の境界線の DcDrawオブジェクトの属性を設定。

　(1.4.5)　X列(ColumnType_Chakuhatsu ) の境界線の幅を設定。

　(2)　列車情報を設定します。

　(2.1)　X列の数を設定します。CdXColSpecCont で指定された列数とします。
　
　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定
　
　(2.2.1)　セル(ColumnType_Ressya ,ColumnType_Ressyabangou) を設定
　
　(2.2.*.1)　セル(ColumnType_Ressya,ColumnType_Ressyabangou) の結合セルを設定
　
　(2.2.*.2)　セル(ColumnType_Ressya,ColumnType_Ressyabangou) のDcDrawオブジェクトの型を設定( CDcdTextbox とする)。

　(2.2.*.3)　セル(ColumnType_Ressya,ColumnType_Ressyabangou) DcDrawオブジェクトに、属性を設定。

　(2.2.2)　同様に、セル(ColumnType_Ressya, ColumnType_Ressyasyubetsu〜 ColumnType_Bikou ) を設定。

　(2.2.3)　X列(ColumnType_Ressya ) の幅を設定。幅は、駅時刻列の DcDraw オブジェクトの幅とします。

　(2.2.4)　X列(ColumnType_Ressya ) の境界線の DcDrawオブジェクトの属性を設定。

　(2.2.5)　X列(ColumnType_Ressya ) の境界線の幅を設定。
　
　(2.3)　X列(ColumnType_NewRessya )に、列車情報を設定。X列(ColumnType_Ressya )と同様。

*/
class CCellBuilder
{
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		　DiagramEdit のアプリケーションが読み書きする 『路線ファイル』に
		含まれるデータを保持するクラスです。 
		  このオブジェクトは、関連が有効な間は生存しなくてはなりません。
	*/
	const CDedRosenFileData* m_pCDedRosenFileData ; 
	/**
		　列車コンテナを指定してください。
		  このオブジェクトは、関連が有効な間は生存しなくてはなりません。
	*/
	const CentDedRessyaCont* m_pCentDedRessyaCont ; 
	///@}
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
		  時刻表ビューの CWndJikokuhyou の各列番号と表示内容の相互変換の
		機能をを提供します。
	*/
	CdXColSpecCont	m_CdXColSpecCont ;

	/**
		  時刻表ビューの CWndJikokuhyou の各列番号と表示内容の相互変換の
		機能をを提供します。
	*/
	CdYColSpecCont	m_CdYColSpecCont ;

	///@}
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		通過駅の駅時刻を表示するか否かの指定です。
	
		- true ; 通過駅の駅時刻を表示します。(default)
		- false ; 通過駅の駅時刻を表示せずに、通過マーク "ﾚ" を表示します。
	 */
	bool m_bDisplayTsuukaEkiJikoku ;
	///@}

protected:
	// --------------------------------
	///@name セルの描画に使用する定数
	// --------------------------------
	///@{
	/**
	 	各セルのテキストの周囲の余白の幅です。
	 	CDcdTextbox,CDcdTextboxV3 の
	 	logicalunitFrameWidth , logicalunitFrameHeight 属性に使います。
	 */
	static const int RectangleTextFrameWidth = 1 ; 
	///@}
	// --------------------------------
	///@name セルの描画に使用する定数.
	// --------------------------------
	///@{
	/**
	@return 
		列車名の縦書きテキスト領域の大きさを、
		テキスト幅(行数・列数)で返します。
	@note static メンバ関数にすることができます。
	*/
	CdDcdSizeXy	getRessyameiTextExtent()const
	{	return CdDcdSizeXy( 2 , 6 ) ;}

	/**
	@return
		備考の縦書きテキスト領域の大きさを、テキスト幅で保持します。
	@note static メンバ関数にすることができます。
	*/
	CdDcdSizeXy getBikouTextExtent()const
	{	return CdDcdSizeXy( 2 , 12 ) ;}
	/** 
	@return 
		駅時刻を表示形式に変換するオブジェクトを返します。 
	@note static メンバ関数にすることができます。
	*/
	const CdDedJikoku::CConv&	getCdDedJikokuConv()const;
	///@}

	// --------------------------------
	///@name グリッドの罫線の属性
	// --------------------------------
	///@{

	/**
		太い線の罫線を描画する DcDraw オブジェクトを生成して返します。
	@return
	 	罫線の属性を保持したオブジェクトを生成します。
	 	
	@note static メンバ関数にすることができます。
	 */
	CdPenProp  getCdPenPropBoldLine()const
	{
		return CdPenProp( 2 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::SOLID ) ;
	}

	/**
		細い線の罫線を描画する DcDraw オブジェクトを生成して返します。
	@return
	 	罫線の属性を保持したオブジェクトを生成します。
	@note static メンバ関数にすることができます。
	 */
	CdPenProp getCdPenPropNarrowLine()const
	{
		return CdPenProp( 1 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::SOLID ) ;
	}
	/**
	 	『罫線なし』のための DcDraw オブジェクトを生成して返します。
	@return
	 	罫線の属性を保持したオブジェクトを生成します。
	@note static メンバ関数にすることができます。
	 */
	CdPenProp	getCdPenPropNullLine()const
	{
		return CdPenProp( 0 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::NULLPEN ) ;
	}
	///@}


	// --------------------------------
	///@name セルのテキスト描画属性
	// --------------------------------
	///@{

	/**
	 	横書きの項目名を表示するセル( "列車番号" ・ "列車種別" など) の
	 	テキスト描画属性（フォント・色）を保持したオブジェクトを生成します。
	@return
		テキスト描画属性を返します。
	 */
	CdDrawTextProp	getCdDrawTextPropMenutext()const ;

	/**
	 	通常のセル（白背景）の、
	 	テキスト描画属性（フォント・色）を保持したオブジェクトを生成します。
	 	この属性は、駅名に使われます。
	@return
	 	テキスト描画属性（フォント・色）を返します。
	 */
	CdDrawTextProp	getCdDrawTextPropStandard()const ;

	/**
	 	通過列車の駅時刻（グレイの文字）の、
	 	テキスト描画属性（フォント・色）を保持したオブジェクトを生成します。
	@return
	 	テキスト描画属性を返します。
	 */
	CdDrawTextProp	getCdDrawTextPropTsuuka()const ;

	///@}

	// --------------------------------
	///@name セルのブラシ属性
	// --------------------------------
	///@{
	/**
	 	項目名を表示するセル( "列車番号" ・ "列車種別" など) の
	 	ブラシの属性を生成します。
	@return
	 	ブラシの属性を返します。
	 */
	CdBrushProp CCellBuilder::getCdBrushPropMenutext()const;

	/**
	 	通常のセル（白背景）の、
	 	ブラシの属性を保持したオブジェクトを生成します。
	@return
	 	ブラシの属性を返します。
	 */
	CdBrushProp	CCellBuilder::getCdBrushPropStandard()const;
	///@}
	// --------------------------------
	///@name セルの描画に使用する DcDrawオブジェクトのプロトタイプ
	// --------------------------------
	///@{


	/**
	 	項目名を表示するセル( "列車番号" ・ "列車種別" など) の
	 	DcDraw オブジェクトを生成して返します。
	@return
	 	DcDraw オブジェクトを返します。
	 */
	CDcdTextbox createCDcdXColumn0()const;

	/**
	 	縦書きの項目名(列車名・備考) 表示欄に使用する
	 	 DcDraw オブジェクトを生成します。
	@return
	 	DcDraw オブジェクトを返します。
	 */
	CDcdTextboxV3 createCDcdXColumn0V()const;


	/**
	 	駅名部分の DcDraw オブジェクトを生成して
	 	返します。
	@return
	 	DcDraw オブジェクトを返します。
	 */
	CDcdTextbox createCDcdEkimei()const ;

	/**
	 	X列１番の、『発』・『着』部分の DcDraw オブジェクトを生成して
	 	返します。
	@return
		DcDraw オブジェクトを返します。
	*/
	CDcdTextbox createCDcdHatsuchaku()const;

	/**
		グリッド上の列車情報のうち、
		列車種別文字色と、フォント「時刻表ビュー 1」・で描画するセルの
		DcDrawオブジェクトを生成して返します。

		適用箇所は、列車番号・号数・「号」です。
	@param iRessyasyubetsuIndex [in]
		列車種別インデクスを指定してください。
	@return
	 	列車情報の列車種別・駅時刻部分の DcDraw オブジェクトを生成して
	 	返します。
	 */
	CDcdTextbox createCDcdRessyabangou(
		int iRessyasyubetsuIndex )const ;

	/**
		縦書きの列車情報のDcDrawオブジェクトを生成して返します。

		適用箇所は、列車名です。
	@param iRessyasyubetsuIndex [in]
		列車種別インデクスを指定してください。
	@return
	 	DcDraw オブジェクトを返します。
	 */
	CDcdTextboxV3 createCDcdRessyamei(
		int iRessyasyubetsuIndex )const;

	/**
		グリッド上の列車情報のうち、
		列車種別文字色と、列車種別フォントで描画するセルの
		DcDrawオブジェクトを生成して返します。

		適用箇所は、列車種別・駅時刻です。
	@param iRessyasyubetsuIndex [in]
		列車種別インデクスを指定してください。
	@return
	 	列車情報の列車種別・駅時刻部分の DcDraw オブジェクトを生成して
	 	返します。
	 */
	CDcdTextbox createCDcdEkijikoku(
		int iRessyasyubetsuIndex )const;

	///@}

protected:
	// --------------------------------
	///@name update() の下請関数
	// --------------------------------
	///@{
	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_updateWithoutRessya(
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

	  (1.1)　CWndDcdGrid の外枠線のDcDrawオブジェクトと、列幅を設定

	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_01_setGridBorder( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.3.1)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) と、
			Y列(ColumnType_Ressyabangou)の高さ・Y列境界線・Y列境界線の高さ設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_03_01_setEkimei_Ressyabangou( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;


	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.3.2.2)セル(ColumnType_Ekimei, ColumnType_Ressyasyubetsu)
		とY列(ColumnType_Ressyasyubetsu)の高さ・Y列境界線・Y列境界線の高さ設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_03_02_02_setEkimei_Ressyasyubetsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	
	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.3.2.3)セル(ColumnType_Ekimei, ColumnType_Ressyamei)
		とY列(ColumnType_Ressyamei)の高さ・Y列境界線・Y列境界線の高さ設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_03_02_03_setEkimei_Ressyamei( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.3.2.4)セル(ColumnType_Ekimei, ColumnType_Gousuu)
		とY列(ColumnType_Gousuu)の高さ・Y列境界線・Y列境界線の高さ設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_03_02_04_setEkimei_Gousuu( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.3.2.5)セル(ColumnType_Ekimei, ColumnType_Gou)
		とY列(ColumnType_Gou)の高さ・Y列境界線・Y列境界線の高さ設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_03_02_05_setEkimei_Gou( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.3.2.6)セル(ColumnType_Ekimei, ColumnType_Ekijikoku_Chaku)
		とY列(ColumnType_Gou)の高さ・Y列境界線・Y列境界線の高さ設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_03_02_06_setEkimei_Chaku( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.3.2.7)セル(ColumnType_Ekimei, ColumnType_Ekijikoku_Hatsu)
		とY列(ColumnType_Gou)の高さ・Y列境界線・Y列境界線の高さ設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_03_02_07_setEkimei_Hatsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.3.2.8)セル(ColumnType_Ekimei,ColumnType_Bikou)
		とY列(ColumnType_Gou)の高さ・Y列境界線・Y列境界線の高さ設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_03_02_08_setEkimei_Bikou( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.4.1)　セル(ColumnType_Chakuhatsu, ColumnType_Ekijikoku_Chaku) 
		を設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_04_01_06_setChakuhatsu_Chaku( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;


	/**
	　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。

		(1.4.1)　セル(ColumnType_Chakuhatsu, ColumnType_Ekijikoku_Hatsu) 
		を設定
			
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update01_04_01_07_setChakuhatsu_Hatsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;




	/**
	　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定
	　(2.3)　X列(ColumnType_NewRessya )に、列車情報を設定。
		X列(ColumnType_Ressya )と同様。
	
	  セルの再描画要求(CWnd::InvalidateRect())も行います。

	@param iXColumnNumber [in]
		　列車番号を指定するX列番号を指定してください。
	@param pCentDedRessya [in]
		　設定する列車情報を指定して下しa.
		　NULLなら、空列車を指定したことになります。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update02_02_updateRessya( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
		
	
	/**
	　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定

	　(2.2.2.1)　セル(ColumnType_Ressya ,ColumnType_Ressyabangou) を設定
			
	@param iXColumnNumber [in]
		　列車番号を指定するX列番号を指定してください。
	@param pCentDedRessya [in]
		　設定する列車情報を指定して下しa.
		　NULLなら、空列車を指定したことになります。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update02_02_01_setRessya_Ressyabangou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定

		(2.2.2.2)セル(ColumnType_Ressya, ColumnType_Ressyasyubetsu)
		 を設定。
			
	@param iXColumnNumber [in]
		　列車番号を指定するX列番号を指定してください。
	@param pCentDedRessya [in]
		　設定する列車情報を指定して下しa.
		　NULLなら、空列車を指定したことになります。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update02_02_02_02_setRessya_Ressyasyubetsu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定

		(2.2.2.3)セル(ColumnType_Ressya, ColumnType_Ressyamei)
		 を設定。
			
	@param iXColumnNumber [in]
		　列車番号を指定するX列番号を指定してください。
	@param pCentDedRessya [in]
		　設定する列車情報を指定して下しa.
		　NULLなら、空列車を指定したことになります。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update02_02_02_03_setRessya_Ressyamei( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定

		(2.2.2.4)セル(ColumnType_Ressya, ColumnType_Gousuu)
		 を設定。
			
	@param iXColumnNumber [in]
		　列車番号を指定するX列番号を指定してください。
	@param pCentDedRessya [in]
		　設定する列車情報を指定して下しa.
		　NULLなら、空列車を指定したことになります。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update02_02_02_04_setRessya_Gousuu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定

		(2.2.2.5)セル(ColumnType_Ressya, ColumnType_Gou)
		 を設定。
			
	@param iXColumnNumber [in]
		　列車番号を指定するX列番号を指定してください。
	@param pCentDedRessya [in]
		　設定する列車情報を指定して下しa.
		　NULLなら、空列車を指定したことになります。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update02_02_02_05_setRessya_Gou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;


	/**
	　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定

		(2.2.2.6)セル(ColumnType_Ressya,ColumnType_Ekijikoku_Chaku)
		 を設定。
			
	@param iXColumnNumber [in]
		　列車番号を指定するX列番号を指定してください。
	@param pCentDedRessya [in]
		　設定する列車情報を指定して下しa.
		　NULLなら、空列車を指定したことになります。
	@param iEkiOrder [in]
		  駅Orderを指定してください。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update02_02_02_06_setRessya_Chaku( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		int iEkiOrder ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定

		(2.2.2.7)セル(ColumnType_Ressya,ColumnType_Ekijikoku_Hatsu)
		 を設定。
			
	@param iXColumnNumber [in]
		　列車番号を指定するX列番号を指定してください。
	@param pCentDedRessya [in]
		　設定する列車情報を指定して下しa.
		　NULLなら、空列車を指定したことになります。
	@param iEkiOrder [in]
		  駅Orderを指定してください。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update02_02_02_07_setRessya_Hatsu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		int iEkiOrder ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	/**
	　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定

		(2.2.2.8)セル(ColumnType_Ressya,ColumnType_Bikou)
		 を設定。
	@param iXColumnNumber [in]
		　列車番号を指定するX列番号を指定してください。
	@param pCentDedRessya [in]
		　設定する列車情報を指定して下しa.
		　NULLなら、空列車を指定したことになります。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update02_02_02_08_setRessya_Bikou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;
	
	
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	///@{
	/**
	@param pCDedRosenFileData [in]
		　DiagramEdit のアプリケーションが読み書きする 『路線ファイル』に
		含まれるデータを保持するクラスです。 
		  このオブジェクトは、関連が有効な間は生存しなくてはなりません。
	@param pCentDedRessyaCont [in]
		　列車コンテナを指定してください。
		  このオブジェクトは、関連が有効な間は生存しなくてはなりません。
	@param bDisplayTsuukaEkiJikoku [in]
		通過駅の駅時刻を表示するか否かの指定です。
		- true ; 通過駅の駅時刻を表示します。(default)
		- false ; 通過駅の駅時刻を表示せずに、通過マーク "ﾚ" を表示します。
	@param bDisplayAllJikoku [in]
		全時刻表示モードのON/OFFです。
		- true ;[全時刻を表示] モード
	 */
	CCellBuilder( 
		const CDedRosenFileData* pCDedRosenFileData ,
		const CentDedRessyaCont* pCentDedRessyaCont,
		bool bDisplayTsuukaEkiJikoku ,
		bool bDisplayAllJikoku )  ;
public:
	// ********************************
	///@name CCellBuilder-属性
	// ********************************
	///@{
	bool getDisplayTsuukaEkiJikoku()const
	{	return m_bDisplayTsuukaEkiJikoku ;}
	void setDisplayTsuukaEkiJikoku( bool value )
	{	m_bDisplayTsuukaEkiJikoku = value ; }
	///@{
public:
	// ********************************
	///@name	CCellBuilder-操作
	// ********************************
	///@{
	/**
		　すべてのセルを更新します。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void update( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	 	すべての列車情報の列を更新します。

		Y列の数・左側の項目名列は更新しません。		

	 	- 1. 列車の数に従って、X列数を設定します。
	 	- 2. すべての列車を設定します。
	 	- 3. 各列車の右側の罫線を設定します。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウのセルを更新します。
	*/
	void updateAllRessya( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;


	/**
		　セル内の列車を置き換えます。
		  Y列の数・左側の項目名列・指定範囲外の列車列は更新しません。		
	@param iDstRessyaIndex [in]
		　削除・追加対象となる列車の列車Indexを指定してください。
	@param iDstDelCount [in] 
		　削除される(置換によって失われる)列車の数を指定してください。
	@param iInsertCount [in]
		　追加される(置換によって新たに生成･変更された)列車の数を指定して
		ください。
	@param bDisplayAllJikoku [in]
		　- true : 全ての駅時刻を表示します。
	@param pCWndJikokuhyou [out]
		　この関数はこのウインドウにセルを追加します。
	*/
	void replaceRessya( 
		int iDstRessyaIndex , 
		int iDstDelCount , 
		int iInsertCount ,
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	///@}
};


} //namespace ViewJikokuhyou
} //namespace WndJikokuhyou

#endif //ViewJikokuhyou_WndJikokuhyou_CCellBuilder_h
