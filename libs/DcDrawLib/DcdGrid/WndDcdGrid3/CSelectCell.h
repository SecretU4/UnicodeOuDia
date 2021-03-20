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
//$Id: CSelectCell.h 212 2014-08-02 19:35:30Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdGrid_WndDcdGrid3_CSelectCell_h
#define  DcDraw_DcdGrid_WndDcdGrid3_CSelectCell_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DcDraw\IfDcdTarget.h"
#include <deque>

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

	using namespace DcDraw;

class CSelect ;

// ----------------------------------------------------------------
//	WndDcdGrid3::CSelectCell
// ----------------------------------------------------------------
/**
@brief
	CWndDcdGridののCellSelect(セル選択)における、
		セル１つの状態を示します。
*/
class CSelectCell
{ 
public:
	friend class CSelect ;
	typedef CSelect outer ;
	typedef	std::deque< CSelectCell* > CSelectYColumnCellCont ;
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		this を包含する、CSelect への関連。
		このオブジェクトは、関連が有効な間は生存しなくてはなりません。
	*/
	CSelect*	m_pOuter ;
	/**
		this を集約しているコンテナです。
		このコンテナには、同じY列にある CSelectCell オブジェクトが格納されています。

		この関連は、CSelect が、getColumnNumberOfCell() を行う時に参照します。
		コンストラクタで決まります。
	*/
	CSelectYColumnCellCont*	m_pCont ;
	///@}
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		セルの選択状態。
		選択されていたら true。
		既定値はfalse。
	*/
	bool m_bIsSelected ;

	/**
		m_bIsSelected の前回値。
		最近の adjust_updateScreen() の時点における値を保持します。
	*/
	bool m_bIsSelected_Prev ;

	///@}
protected:
	// --------------------------------
	///@name CWndDcdGrid からの委譲
	// --------------------------------
	///@{
	/**
	update() の下請関数です。
	属性の補正を行います。
	
	[オーバライド]　処理はありません。
	
	 @return 
		正規化の結果、何らかの値を変化させた場合は真です。
	 */
	bool update_adjustProp() ;

	/**
	update() の下請関数です。
	属性の変化を、画面上に反映します。
	
	[オーバライド]　
		属性が変化したら、
		invalidateGrid() で、セルの再描画を行います。
		対象となるのは、以下の属性です。

		- m_bSelected	

	@param pIfDcdTarget [in]
		描画対象を指定してください。
	@return 
		何らかの値の変化を画面上に反映させた場合は真です。
	 */
	bool update_updateScreen( IfDcdTarget* pIfDcdTarget ) ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CSelectCell(
		CSelect* pOuter , 
		CSelectYColumnCellCont* pCont ) ;
public:
	// ********************************
	///@name CSelectCell 属性
	// ********************************
	///@{
	bool getIsSelected()const ;

	/**
	m_bIsSelected を変更します。

	CSelect::m_bUpdateCWndDcdGrid が true で、
	属性が変更された場合は、
	CWndDcdGrid::update() を呼び出して、
	変更を CWndDcdGrid に集約されている
	全てのオブジェクトに反映します。

	@attention
		CSelect::m_bUpdateCWndDcdGrid が true の場合、
		この関数は、処理時間が長くなります。
		(理由：CWndDcdGrid::update() は処理時間が長くなるためです。)@n
		多数の CSelectCell オブジェクトに対して連続して
		CSelectCell::setIsSelected() を呼び出す場合は、@n
		(1)CSelect::m_bUpdateCWndDcdGrid を falseにしておく@n 
		(2)CSelectCell::setIsSelected() を、対象のすべてのセルに対して実行@n 
		(3)CSelect::m_bUpdateCWndDcdGrid を true にもどす@n 
		という方法をとることにより、処理時間の短縮が期待できます。

	@param value [in]
		m_bIsSelected に設定する値を指定してください。
		
	*/
	void setIsSelected( bool value ) ;

	bool getIsSelected_Prev()const ;
	///@}
};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif //DcDraw_DcdGrid_WndDcdGrid3_CSelectCell_h
