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
//	CBoxSelect.h
//	$Id: CBoxSelect.h 212 2014-08-02 19:35:30Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdGrid_WndDcdGrid3_CBoxSelect_h
#define  DcDraw_DcdGrid_WndDcdGrid3_CBoxSelect_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>
#include "DcdGrid\WndDcdGrid3\CSelect.h"
#include "DcdGrid\WndDcdGrid3\CPropStack.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{
	
// ****************************************************************
//	WndDcdGrid3::CBoxSelect
// ****************************************************************
/**
@brief
 CWndDcdGrid 上での、ユーザーのBoxSelect(箱型選択操作)にしたがって、
CSelect,CSelectCell の属性を変更します。

このクラスは、 CWndDcdGrid  が内部的に生成するために存在します。
それ以外の利用価値はありません。

 【使い方】

(1) このクラスのオブジェクトは、 WndDcdGrid3::CWndDcdGrid で生成されます。
WndDcdGrid3::CWndDcdGrid::getCBoxSelect() で、オブジェクトにアクセスできます。

(2) 箱型選択を使用するときは、最初に　WndDcdGrid3::CBoxSelect::setIsEnable ()
で、この機能を有効にしてください。

<H3>
BoxSelect(箱型選択操作)	
</H3>
■Ctrl+Spaceキー@n
　→何もしない

■Ctrl+グリッド上でのマウスクリック@n
　→何もしない

■CtrlもShiftも押されない状態で、グリッド上でのマウスクリック@n
  →何もしない

□CtrlもShiftも押されない状態で、
 ドラッグ(MouseMove,タイマスクロール)以外によるフォーカス移動@n
  →アンカーセルは更新。BoxSelect領域はNULL。
              すべてのセルの選択状態を解除
              
□CtrlはON、ShiftはOFFで、ドラッグ以外によるフォーカス移動@n
  →アンカーセルは更新。BoxSelect領域はそのまま。

□Shiftが押された状態で、ドラッグ以外によるフォーカス移動@n
  →アンカーセルは更新せずに、アンカーセルとフォーカスセルの間を
    選択領域とする。

□ドラッグによるフォーカス移動(MouseMove,タイマスクロール)@n
  →アンカーセルは更新せずに、アンカーセルとフォーカスセルの間を
    選択領域とする。

 このクラスは、 CWndDcdGrid  が内部的に生成するために存在します。
	それ以外の利用価値はありません。


*/
class CBoxSelect
{
	friend class CWndDcdGrid ;
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		外側の、 CWndDcdGrid への関連です。
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、 this より長く生存しなくてはなりません。
		コンストラクタで決まります。
	 */
	CWndDcdGrid*	m_pCWndDcdGrid ;

	///@}

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		UI操作による箱型選択の有効・無効を指定します。
		既定値は true です。
	*/
	bool m_bIsEnable ;

	/**
		アンカーセル。箱型選択の始点です。

		ユーザーがShiftキーが押されていない状態でフォーカスセルを移動した場合は、
		このクラスはアンカーセルをフォーカスセルで更新します。

		ColumnNumberPosXy_NULL() なら、
		アンカーセルが不定であることを示します。
		update_adjustProp_updateColumnNumberSelect()で更新されます。
		
		m_ColumnNumberAnchorCell が m_ColumnNumberSelectLimit の
		外側になった場合は、強制的にNULLとなります。
	*/
	CdDcdPosXy	m_ColumnNumberAnchorCell;

	/**
		現在のBoxSelect(箱型選択操作)選択範囲

		選択範囲がない場合、この値は
		ColumnNumberZoneXy_NULL()と等しくなります。
		
		update_adjustProp_updateColumnNumberSelect()で
		導出されます。
		また、メソッドで指定することもできます。
	*/
	CdDcdZoneXy	m_ColumnNumberSelect ;

	///@}
 private:
	// ********************************
	///	@name 集約
	// ********************************
	///@{
	///@}
public:
	// ********************************
	///@name 定数
	// ********************************
	///@{
	/**
	@return
		セルの列番号のNULL値。

		セルの列番号は、
		x,y両方がINT_MINなら、NULLであることを示します。
	*/
	static CdDcdPosXy	ColumnNumberPosXy_NULL()
	{	return CdDcdPosXy( INT_MIN , INT_MIN ) ;};

	/**
	@return
		選択範囲のNULL値。

		m_ColumnNumberSelect がこの値に等しい場合は
		選択範囲がないことを示します。
	*/
	static CdDcdZoneXy	ColumnNumberZoneXy_NULL()
	{	return CdDcdZoneXy( CdDcdZone( 0 , 0 ) , CdDcdZone( 0 , 0 ) );};
	///@}

private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
		フォーカスセルの前回値。
		初期値はNULLを示す値です。
		update_adjustProp() で、カレントのフォーカスセルの値がコピーされます。
	*/
	CdDcdPosXy	m_ColumnNumberFocus_Old ;


	/**
		BoxSelect(箱型選択操作)選択範囲の前回値。
		初期値はNULLを示す値です。
		
		update_updateScreen()で画面を更新したときに、
		m_ColumnNumberSelect の値がコピーされます。
	*/
	CdDcdZoneXy	m_ColumnNumberSelect_Old ;



private:
	// --------------------------------
	///@name update_adjustProp 下請関数
	// --------------------------------
	///@{
	/**
		update_adjustProp()の下請関数です。

	【1.属性の補正】


		対象となるのは、以下の属性です。
		
		- m_ColumnNumberSelect , m_ColumnNumberAnchorCell
	
	(1)	フォーカスセルの移動に従って、
		m_ColumnNumberAnchorCell , m_ColumnNumberSelect を更新します。
		
	(2)	m_ColumnNumberAnchorCell・m_ColumnNumberSelect を正規化します。

	*/
	bool update_adjustProp_updateColumnNumberSelect() ;
	
	/**
		update_adjustProp()の下請関数です。

	【2.属性の変化をCWndDcdGridに通知】

	(3)	選択セルの状態を、CSelectCell に反映します。

	@note
		選択セル CSelectCell への 
		update_adjustProp() の委譲は行いません。@n
		理由：CSelectCellへの update_adjustProp() の
		委譲は、 CSelect の責務です。
	*/
	bool update_adjustProp_updateCSelectCell() ;

	/**
	セル選択変更時の、CPropStack インスタンスを生成します。
	このオブジェクトは、生存期間中は以下の属性を設定します。

	- CSelect::m_bUpdateCWndDcdGrid = false

	 これによって、セル選択変更時の描画を最適化します。
	 (複数のセルの選択を変更する場合は、この属性をfalseにした状態で
	 セルの選択状態を変更してから、この属性をtrueにして
	 画面を再描画するほうが、効率がよくなります。) 
	*/
	Ou<CPropStack> createPropStackForSelectChange() ;

	///@}


protected:
	// --------------------------------
	///@name CWndDcdGrid からの委譲
	// --------------------------------
	///@{
	/**
		update() の下請関数です。
	
		- 属性の補正
		- 属性の変化をCWndDcdGridに通知

		を行います。

	【1.属性の補正】

		対象となるのは、以下の属性です。
		
		- m_ColumnNumberSelect , m_ColumnNumberAnchorCell
	
	(1)	フォーカスセルの移動に従って、
		m_ColumnNumberAnchorCell , m_ColumnNumberSelect を更新します。
		
	(2)	m_ColumnNumberAnchorCell・m_ColumnNumberSelect を正規化します。

	【2.属性の変化をCWndDcdGridに通知】

	(3)	選択セルの状態を、CSelectCell に反映します。

	 @return 
		何らかの値を変化させた場合は真です。
	 */
	bool update_adjustProp() ;

	/**
		update() の下請関数です。

	  	属性の変化を、画面上に反映します。
		対象となるのは、以下の属性です。
		
	 @return 
		何らかの値の変化を画面上に反映させた場合は真です。

		このクラスでは処理はありません(再描画は、CSelect にて行われます)
	 */
	bool update_updateScreen() ;


	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

	 	描画を要求します。
	 	この関数は、 pIfDcdTarget に、描画を行います。

	 @param pIfDcdTarget  [in]
	 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 	CWndDcdGridのクライアント領域の IfDcdTarget を指定してください。
	 @return
	 	描画を行った場合は真・この領域への描画ができなかった場合は偽です。

		このクラスでは処理はありません(再描画は、CSelect にて行われます)
	*/
	virtual bool OnPaint( IfDcdTarget* pIfDcdTarget ) ;


	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

		選択セルを正規化・再設定します。

		このクラスでは処理はありません
	*/
	void OnSize(UINT nType, int cx, int cy);

	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

		このクラスでは、処理はありません。
	*/
	void OnSetFocus(CWnd* pOldWnd);
	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

		このクラスでは、処理はありません。
	*/
	void OnKillFocus(CWnd* pNewWnd);

	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

		ウインドウ全域を無効化し、
		再描画を要求します。
		このとき、選択セルの属性の再設定・正規化も行います。
	
		このクラスでは処理はありません(再描画は、CSelect にて行われます)
	 */
	virtual void InvalidateGrid( ) ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	@param pCWndDcdGrid [in]
		外側の、 CWndDcdGrid への関連です。
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、 this より長く生存しなくてはなりません。
	 */
	CBoxSelect( CWndDcdGrid* pCWndDcdGrid ) ;
	virtual ~CBoxSelect() ;
public:
	// ********************************
	///@name CSelect 関連
	// ********************************
	///@{
	CWndDcdGrid*	getCWndDcdGrid() ;
	///@}


	// ********************************
	///@name CSelect 属性
	// ********************************
	///@{
	bool getIsEnable() ;
	void setIsEnable( bool value ) ;
	CdDcdPosXy	getColumnNumberAnchorCell();
	CdDcdZoneXy	getColumnNumberSelect()const ;
	void setColumnNumberSelect( const CdDcdZoneXy& value ) ;
	///@}
	// ********************************
	///@name CSelect 集約
	// ********************************
	///@{
	///@}
	// ********************************
	///@name CSelect 操作
	// ********************************
	///@{
	/**
		箱型選択を解除します。
	*/
	void clearSelect() ;
	///@}


};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif //DcDraw_DcdGrid_WndDcdGrid3_CSelect_h
