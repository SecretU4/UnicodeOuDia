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
//	CFocus.h
//$Id: CFocus.h 296 2016-06-11 05:40:21Z okm $
// ****************************************************************
*/
/** @file 

*/
#if !defined(DcDraw_DcdGrid_WndDcdGrid3_CFocus_h)
#define DcDraw_DcdGrid_WndDcdGrid3_CFocus_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
@file
このヘッダファイルを単体でインクルードすることはできません。
代わりに、 CWndDcdGrid.h をインクルードしてください。

このヘッダファイルは、CWndDcdGrid.h の末尾でインクルードしています。
このため、このクラスから CWndDcdGrid.h をインクルードすることはできません。
*/

#include <afxwin.h>
#include "NsOu\Ou.h"
#include "DcDraw\IfDcDraw.h"
#include "DcdGrid\CDcdGridCell.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

// ----------------------------------------------------------------
//	WndDcdGrid3::CFocus
// ----------------------------------------------------------------
/**
 @brief
	CWndDcdGrid のフォーカス・スクロールの制御をクラス化したものです。
	
	このクラスは、 CWndDcdGrid  が内部的に生成するために存在します。
	それ以外の利用価値はありません。
 */
class CFocus
{
	friend class CWndDcdGrid ;
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
	/**
		フォーカスセルに対して、フォーカスマークを描画する
		DcDraw オブジェクトです。
	
		通常は、this の CreateDcDrawFocusCell() 仮想関数が、
		CDcdRectangle オブジェクトを生成・登録します。
		また、 DeleteDcDrawFocusCell() 仮想関数が、
		このオブジェクトを登録解除・破棄します。
		
	 */
	Ou<IfDcDraw>	m_pIfDcDrawFocusCell ;
	///@}
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		FocusCell の XColumnNumber
		
		 CDcdGridWnd ウインドウは、グリッドウインドウのすべてのCellの
		うちのひとつを FocusCell として指定します。FocusCellは点線の
		枠線で示されます。
		(Cellがひとつもない場合は、値は０としますが、
		この値は意味を持ちません)
	
		  FocusCellのColumnNumber は、必ずウインドウ内
		（IfDcdTarget オブジェクトの領域内）に存在します。
		Scrolloutされているセル・ウインドウの外側にあるセルが
		FocusCellになることはありません。
		  また、AttachedCell（被結合セル）がFocusCellになることはありません。
		
		  この条件を満たすため、FocusCell と、CDcdGridの
		 FixafterColumnNumber は、常に正規化されます。
		(この正規化は、 adjustProp() で行います)。
	 */
	int	m_iFocusCellXColumnNumber ;

	/**
		FocusCell の YColumnNumber
		
		 CDcdGridWnd ウインドウは、グリッドウインドウのすべてのCellの
		うちのひとつを FocusCell として指定します。FocusCellは点線の
		枠線で示されます。
		(Cellがひとつもない場合は、値は０としますが、
		この値は意味を持ちません)
	
		  FocusCellのColumnNumber は、必ずウインドウ内
		（IfDcdTarget オブジェクトの領域内）に存在します。
		Scrolloutされているセル・ウインドウの外側にあるセルが
		FocusCellになることはありません。
		  また、AttachedCell（被結合セル）がFocusCellになることはありません。
		
		  この条件を満たすため、FocusCell と、CDcdGridの
		 FixafterColumnNumber は、常に正規化されます。
		(この正規化は、 adjustProp() で行います)。
	 */
	int	m_iFocusCellYColumnNumber ; 


	/**
	  フォーカスセルがウインドウ外になる場合の、
	  フォーカスセルとスクロール位置の調停方法を指定します。

		- false; フォーカスセルをウインドウ内に移動させる。
		- true; (デフォルト)フォーカスセルがウインドウ内になるように@n
		スクロール位置を変更する。
	*/
	bool m_bFixafterColumnNumberChange ;

	/**
		- false: (デフォルト)ウインドウにフォーカスがないときは、@n
			フォーカスマークを消去します。
		- true: ウインドウにフォーカスがないときにも、@n
			フォーカスマークを消去しません。
	 */
	bool	m_bIsFocusmarkShowEvery ;
	///@}
private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/** 
		属性値を保存します。
	
		初期値は -1 （無効値）です。
	
		この値は、 update_updateDisplay() 時に、前回値比較を行うのに使います。
		前回値比較を行った後は、値を更新します。
	
		また、OnPaint() でも、値を更新します。
	 */
	int	m_iFocusCellXColumnNumber_Sid ;
	/** 
		属性値を保存します。
	
		初期値は -1 （無効値）です。
	
		この値は、 update_updateDisplay() 時に、前回値比較を行うのに使います。
		前回値比較を行った後は、値を更新します。
	
		また、OnPaint() でも、値を更新します。
	 */
	int m_iFocusCellYColumnNumber_Sid ;
	///@}

protected:
	// --------------------------------
	///@name	WndDcdGrid3-フォーカス-下請関数
	// --------------------------------
	///@{
	/**
		this は、OnCreate() からこの関数を呼び出します。
	
		m_pIfDcDrawFocusCell の生成・登録を行います。
	 */
	virtual void CreateDcDrawFocusCell() ;
	/**
		this は、OnDestroy() からこの関数を呼び出します。
	
		CWndDcdGrid に対して、 m_pIfDcDrawFocusCell 
		の登録解除・破棄を行います。
	 */	
	virtual void DeleteDcDrawFocusCell() ;
	///@}
protected:
	// --------------------------------
	///@name CWndDcdGrid からの委譲
	// --------------------------------
	///@{
	/**
	- 属性の補正
	- 属性の変化をCWndDcdGridに通知

	を行います。

	【1.属性の補正】

	  対象となるのは、以下の属性です。
		
	- m_iFocusCellXColumnNumber 
	- m_iFocusCellYColumnNumber 
	- m_pCDcdGrid->m_iXFixafterColumnNumber
	- m_pCDcdGrid->m_iYFixafterColumnNumber

	  正規化に際して、m_iFocurCellXColumnNumber と m_pCDcdGrid->m_iXFixafterColumnNumber 
	の値が競合した場合、どちらを変更するかを、フラグで選択できます。

	- [FocurCellColumnNumber 変更]  フォーカスセルを、ウインドウ内に
	移動します。
	スクロール位置を変更したときは、こちらを使用します。
	- [FixafterColumnNumber 変更]  フォーカスセルが
	ウインドウ上に
	表示されるように、 FixafterColumnNumber を変更します。
	フォーカス位置を変更したときは、こちらを使用します。
		

	１．FocusCell が被結合セルになった場合・・・FocusCellは	結合セルに移動します。

	２．FocusCellColumnNumber が ウインドウの範囲
		（IfDcdTarget::getZone()の領域)に収まっていない場合・・・

	- [FixafterColumnNumber 変更]
	FocusCellColumnNumber を、画面上の一番右下の ColumnNumber にします。
	- [FocurCellColumnNumber 変更]
	FocusCellColumnNumber がウインドウの範囲に収まるまで、
	FixafterColumnNumberを加算します。
	この結果となる FixafterColumnNumber を、
	 FixafterColumnNumberMaxForColumn と呼びます。
		
	３． FocusCellColumnNumber が ColumnScrollout になった場合・・・
		- [FixafterColumnNumber 変更]
		FocusCellColumnNumber を FixafterColumnNumber と同じにします。
		- [FocurCellColumnNumber 変更]
		スクロール位置を正規化して、フォーカスセルが表示されるようにします。
		FixafterColumnNumberを、FocusCellのColumnNumberと同じにします。

	４．FocusCell が0以上 ColumnCount未満でない場合・・・FocusCellは
		内側の値にします。
		
	５．FocusCell が被結合セルになった場合・・・FocusCellは
		結合セルに移動します。

	【2.属性の変化をCWndDcdGridに通知】

	  属性が変化した場合は、CWndDcdGrid に対して、以下のメソッドを
	呼び出します。、

	- CWndDcdGrid::OnSetFocusCell()
	- CWndDcdGrid::OnSetXFixafterColumnNumber()
	- CWndDcdGrid::OnSetYFixafterColumnNumber()

	 @return 
		正規化の結果、何らかの値を変化させた場合は真です。
	 */
	bool update_adjustProp() ;

	/**
	  update() の下請関数です。

	  属性の変化を、画面上に反映します。
	  対象となるのは、以下の属性です。

	- m_iFocusCellXColumnNumber 
	- m_iFocusCellYColumnNumber 
	- m_pCDcdGrid->m_iXFixafterColumnNumber
	- m_pCDcdGrid->m_iYFixafterColumnNumber

	  この変化を察知するために、this は以下の属性に前回値を保持しています。

	- m_iFocusCellXColumnNumber_Sid
	- m_iFocusCellYColumnNumber_Sid
	- m_CdScrollbarPropX_Sid
	- m_CdScrollbarPropY_Sid

	m_iFocusCellColumnNumber・・・変更前と変更後のセルを無効化し、
	再描画を行わせます。

	FixafterColumnNumber・・・ウインドウ上のGridをスクロールします。
	また、スクロールバー属性を変更します。


	@return 
		何らかの値の変化を画面上に反映させた場合は真です。
	 */
	bool update_updateScreen() ;
	/**
	  CWndDcdGrid の同一メソッドの委譲を受けます。
  	  pIfDcdTarget に、描画を行います。

	【オーバライド】
	  m_pIfDcDrawFocusCell で、フォーカスマークを描画します。

	@param pIfDcdTarget  [in]
	 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 	CWndDcdGridのクライアント領域の IfDcdTarget を指定してください。
	@return
	 	描画を行った場合は真・この領域への描画ができなかった場合は偽です。
	*/
	virtual bool OnPaint( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

		スクロール・フォーカスを正規化・再設定します。
	*/
	void OnSize(UINT nType, int cx, int cy);

	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

		フォーカスセルの位置を更新します。
	*/
	void OnSetFocus(CWnd* pOldWnd);
	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

		フォーカスセルの位置を更新します。
	*/
	void OnKillFocus(CWnd* pNewWnd);

	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

		ウインドウ全域を無効化し、
		再描画を要求します。
		このとき、スクロールバーの属性の再設定・
		フォーカスセルの正規化も行います。
	 */
	virtual void InvalidateGrid() ;
	///@}


public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CFocus( CWndDcdGrid* pCWndDcdGrid ) ;
	virtual ~CFocus() ;
public:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	virtual Ou<IfDcDraw>	getIfDcDrawFocusCell() ;
	virtual void setIfDcDrawFocusCell( Ou<IfDcDraw> value ) ;
	///@}
public:
	// ********************************
	///@name CWndDcdGrid::CFocus 属性
	// ********************************
	///@{
	/**
	@return
		フォーカスセルの列番号を返します。
		フォーカスセル位置が不定の場合は、
		ColumnNumberPosXy_NULL() を返します。
	*/
	CdDcdPosXy	getFocusCellColumnNumber() ;

	/**
	@return
		フォーカスセルの列番号を指定します。
	*/
	void setFocusCellColumnNumber( const CdDcdPosXy& value ) ;

	/**
	 @return
		フォーカスセルの位置を返します。
	 */
	CDcdGridCell*	getFocusCell() ;

	/**
	 @param value [in]
		フォーカスセルを指定します。
	 */
	void setFocusCell( 
		CDcdGridCell* value ) ;


	bool	getFixafterColumnNumberChange()  ;
	void setFixafterColumnNumberChange( bool value ) ;

	bool	getIsFocusmarkShowEvery()  ;
	void setIsFocusmarkShowEvery( bool value ) ;

	///@}
};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif // !defined(DcDraw_DcdGrid_WndDcdGrid3_CFocus_h)

