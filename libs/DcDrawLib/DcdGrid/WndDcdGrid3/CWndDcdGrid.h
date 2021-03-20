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
//	CWndDcdGrid.h
// ****************************************************************
*/
/** @file */
#ifndef DcDraw_DcdGrid_WndDcdGrid3_CWndDcdGrid_H
#define DcDraw_DcdGrid_WndDcdGrid3_CWndDcdGrid_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>
#include "DcdGrid\WndDcdGrid3\CXDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CFocus.h"
#include "DcdGrid\WndDcdGrid3\CSelect.h"
#include "DcdGrid\WndDcdGrid3\CSelectCell.h"
#include "DcdGrid\WndDcdGrid3\CBoxSelect.h"
#include "DcdGrid\WndDcdGrid3\CRandomSelect.h"
#include "NsOu/Ou.h"
#include "DcdGrid\CDcdGrid.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

class CPropStack ;

// ****************************************************************
//	CWndDcdGrid
// ****************************************************************
/**
@brief
　クライアント領域にCDcdGrid によるグリッドを表示するウインドウです。

　CWndDcdGrid は、キーボード操作によるフォーカスセルの操作、セル範囲の選択の機能も提供します。

　このクラスは、以下のクラスのオブジェクトを集約します。これらは、互いに協調動作します。

- WndDcdGrid3::CXDcdGrid(基本クラス：CDcdGrid)@n
  グリッドに描画するコンテンツ@n
  スクロール位置は、このオブジェクトの属性です。
- WndDcdGrid3::CFocus@n
  フォーカスセル。
- WndDcdGrid3::CSelect@n
  選択セル。
- WndDcdGrid3::CBoxSelect @n
  CWndDcdGrid 上での、ユーザーのBoxSelect(箱型選択操作)にしたがって、
  CSelect,CSelectCell の属性を変更します。
- WndDcdGrid3::CRandomSelect @n
  CWndDcdGrid 上での、ユーザーのRandomSelect(個別のセル選択操作)に
  したがって、CSelect,CSelectCell の属性を変更します。

＜1＞このクラスの責務

◎ウインドウの生成・破棄

◎集約するオブジェクトを生成・破棄

　このクラスが集約する WndDcdGrid3::CXDcdGrid,WndDcdGrid3::CFocus,
 WndDcdGrid3::CSelect,WndDcdGrid3::CBoxSelect,WndDcdGrid3::CRandomSelect
の生成・破棄を行います。

◎ウインドウへのUI操作への応答

◎集約するオブジェクトに対して更新要求を委譲

　CWndDcdGrid::update() から、各集約オブジェクトに対して、
 update_adjustProp() , update_updateScreen() を委譲します。
　集約オブジェクトは、属性が変更されたときには、 CWndDcdGrid::update() 
 を呼び出すことにより、他の集約オブジェクトに更新を依頼します。
 (例：フォーカスセルが移動されたときに、フォーカスセルが
 画面内に収まるようにスクロール）


＜2＞使い方

＜2.1＞構築

(1)ウインドウを生成

　CWndDcdGrid は、子ウインドウとして動作します。
　以下の手順でウインドウを生成・表示することができます。

(1.1)　親ウインドウの OnCreate() で CWndDcdGrid::Create() 
でウインドウを生成。

(1.2)　CWndDcdGrid::ShowWindow() でウインドウを表示後、
CWndDcdGrid::UpdateWindow() でクライアント領域を更新

＜2.2＞親ウインドウに必要な処理

＜2.2.1＞親ウインドウのOnSize

　CWndDcdGrid　親ウインドウのOnSize() では、CWndDcdGridの位置・サイズを調節してください。
@code
void CMainWnd::OnSize(UINT nType, int cx, int cy) 
{
	
	if ( nType == SIZE_MAXIMIZED   //ウィンドウは最大表示されます。
		|| nType == SIZE_RESTORED  // ウィンドウはサイズ変更されますが、SIZE_MINIMIZED と SIZE_MAXIMIZED は適用されません。
	){
		m_pCWndDcdGrid->MoveWindow( 0 , 0 , cx , cy , TRUE ) ;
	}	else	{
		super::OnSize(nType, cx, cy);
	}
}
@endcode

＜2.2.2＞親ウインドウのOnSetFocus

　親ウインドウが CWndDcdGrid 以外の子ウインドウを持たない場合は、 CWndDcdGrid() にフォーカスを移動してください。

@code
void CMainWnd::OnSetFocus(CWnd* pOldWnd) 
{
	//super::OnSetFocus(pOldWnd);
	
	CWnd*	pControl = GetNextDlgTabItem( (CWnd*)NULL , FALSE ) ;
	pControl->SetFocus() ;
}
@endcode

＜2.3＞グリッドへのコンテンツの表示

(1)WndDcdGrid3::CXDcdGrid オブジェクトへのポインタを取得

　CWndDcdGrid::getCXDcdGrid() で、WndDcdGrid3::CXDcdGrid
 オブジェクトへのポインタを取得してください。
　これ以後は、こののポインタを使って、グリッドにコンテンツを指定します。

(2)X列・Y列の数を設定

　X列・Y列の数を指定してください。

 - WndDcdGrid3::CXDcdGrid::setXColumnCount(),
 - WndDcdGrid3::CXDcdGrid::setYColumnCount())。

　以下のメソッドを使って、X列・Y列を１つずつ追加・削除することもできます。

 - WndDcdGrid3::CXDcdGrid::insertXColumn(),
 - WndDcdGrid3::CXDcdGrid::eraseXColumn()
 - WndDcdGrid3::CXDcdGrid::insertYColumn(),
 - WndDcdGrid3::CXDcdGrid::eraseYColumn()


(3)各X列・Y列の幅・各罫線の太さを設定(自動設定の場合は除く)

　X列・Y列の幅・各罫線の太さを自動設定にしない場合は、太さを設定してください。

　X列・Y列の幅・各罫線の太さは、以下の属性によって変更できます。

 - CDcdGridXColumn::m_iColumnSize,
 - CDcdGridYColumn::m_iColumnSize,
 - CDcdGridXBorder::m_iColumnBorderSize,
 - CDcdGridYBorder::m_iColumnBorderSize

　X列・Y列の幅・各罫線の太さの自動設定のON/OFFは、以下の属性によって変更できます。

 - CDcdGridXColumn::m_bAutoColumnSize
 - CDcdGridYColumn::m_bAutoColumnSize
 - CDcdGridXBorder::m_bAutoColumnBorderSize
 - CDcdGridYBorder::m_bAutoColumnBorderSize

 @attention
	CDcdGridXColumn,CDcdGridYColumn は、デフォルトでは
	m_bAutoColumnSize,m_bAutoColumnBorderSize が真になっています。
	この属性が真だと、グリッドの描画に時間がかかります。


(4)各罫線・各セルの IfDcDraw オブジェクトに属性を設定

　詳細は、 CDcdGrid の説明を参照してください。

(5)ウインドウのクライアント領域の更新要求

　グリッドの WndDcdGrid3::CXDcdGrid ・
 もしくは WndDcdGrid3::CXDcdGridの集約オブジェクト に対して、
 グリッドの描画形状を変更するような操作を行った場合は、
 CWndDcdGrid::InvalidateGrid() を呼び出して、CWndDcdGrid の
 クライアント領域の更新を要求してください。
   これにより、描画形状の変更内容がウインドウのクライアント領域に反映されます。

　「WndDcdGrid3::CXDcdGridの集約オブジェクト」は、以下のものを指します。

- CDcdGridXColumn ,
- CDcdGridYColumn , 
- CDcdGridXBorder と、それに集約されている IfDcDraw オブジェクト , 
- CDcdGridYBorder と、それに集約されている IfDcDraw オブジェクト , 
- CDcdGridCell と、それに集約されている IfDcDraw オブジェクト , 

  但し、１つのセルのサイズを変えずに表示内容だけを変更する場合は、
  CWndDcdGrid::InvalidateGrid() の代わりに CWndDcdGrid::InvalidateCell()
  を呼び出しても同じ効果があります。
  こちらのほうが、画面更新にかかる時間が短くなり、
  ちらつきを減らすことができます。


＜2.4＞フォーカスセルの移動

(1)WndDcdGrid3::CFocus オブジェクトへのポインタを取得

　CWndDcdGrid::getCFocus() で、WndDcdGrid3::CFocus 
 オブジェクトへのポインタを取得してください。
　これ以後は、こののポインタを使って、フォーカスを操作することができます。

(2)フォーカスを移動

　WndDcdGrid3::CFocus::setFocusCell() で、フォーカスセルを移動することができます。

　このメソッドは、以下の属性の影響を受けます。必要なら、以下の属性を設定してください。

- WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange
- WndDcdGrid3::CSelect::m_bKeepAnchor



＜2.5＞スクロール

(1)WndDcdGrid3::CXDcdGrid オブジェクトへのポインタを取得

　CWndDcdGrid::getCXDcdGrid() で、WndDcdGrid3::CXDcdGrid 
 オブジェクトへのポインタを取得してください。
　これ以後は、こののポインタを使って、グリッドのスクロール位置を
 取得・設定できます。

(2)スクロールの属性を設定

  WndDcdGrid3::CXDcdGrid の以下のメソッドで、スクロールの属性を設定してください。

  - WndDcdGrid3::CXDcdGrid::setXFixafterColumnNumber() , 
  - WndDcdGrid3::CXDcdGrid::setYFixafterColumnNumber(),
  - WndDcdGrid3::CXDcdGrid::setXFixColumnCount(),
  - WndDcdGrid3::CXDcdGrid::setYFixColumnCount() 
	

【補足】これらのメソッドは、ウインドウのクライアント領域を更新します。
これらのメソッドを呼び出したあとは、 CWndDcdGrid::InvalidateGrid() を
呼び出す必要はありません。

　これらのメソッドは、以下の属性の影響を受けます。必要なら、以下の属性を
設定してください。

- WndDcdGrid3::CXDcdGrid::m_bUpdateCWndDcdGrid
- WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange

＜2.6＞セル選択

(1)WndDcdGrid3::CSelect オブジェクトへのポインタを取得

　CWndDcdGrid::getCSelect() で、WndDcdGrid3::CSelect オブジェクトへの
 ポインタを取得してください。
 　これ以後は、こののポインタを使って、選択セルを操作することができます。

(2)セル選択のモードと範囲を設定
　
　以下の属性を設定してください。

- WndDcdGrid3::CSelect::m_eSelectMode  (セル選択のモード)
- WndDcdGrid3::CSelect::m_ColumnNumberSelectLimit  (セル選択の範囲)


(3)セル選択状態の設定

　WndDcdGrid3::CSelect::getCell() メソッドで、セルの選択状況を
表す WndDcdGrid3::CSelectCell オブジェクトを取得することができます。
 WndDcdGrid3::CSelectCell::setIsSelected() メソッドを用いることにより、
セルを選択状態にすることができます。

(4)セル選択を解除

  CWndDcdGrid::clearSelect() を呼び出すことにより、BoxSelect,RandomSelect 
双方の選択を解除できます。


＜2.7＞グリッドのウインドウ以外への描画(例：印刷)

　WndDcdGrid3::CXDcdGrid は、IfDcDraw インターフェースをサポートしています。
 このため、CWndDcdGrid だけでなく、任意の DC(IfDcdTarger オブジェクト)に
 グリッドを描画することができます。
 これにより、CWndDcdGrid のクライアント領域に表示しているグリッドを
 プリンタに印刷することもできます。

　ただし、ウインドウ以外の IfDcdTarget にグリッドを描画する間は、
 以下の属性を一時的に変更することをお勧めします。
-  WndDcdGrid3::CXDcdGrid::m_bUpdateCWndDcdGrid = false 
-  WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange = false 

	【理由】
	  例えばプリンタにグリッド全体を印刷する場合は、スクロール位置を
	 変更しながら複数回印刷を行う必要があります。このとき、これら属性が
	 true のままでは、印刷位置を指定するためにスクロール位置を変更したときに、
	 ウインドウのスクロールバー位置も不要に変更されます。

 　この処理は、CPropStack を使うと便利です。以下は、印刷処理の例です。
@code
void CDelivedGrid::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	//	印刷用紙の IfDcdTarget オブジェクトを生成
	CDcdTargetMfcPrintInfo	aCDcdTargetMfcPrintInfo( pDC, pInfo ) ;

	//	スクロールと再描画を抑止します。
	CPropStack	aPropStack( this ) ;
	aPropStack.CDcdGrid_setUpdateCWndDcdGrid( false )
		.CFocus_setFixafterColumnNumberChange( false );

	//	this に、pCWndDcdGridスクロール位置を設定
	this->getCXDcdGrid ()->setYFixafterColumnNumber( page )

	//	IfDcdTargetに描画
	this->getCXDcdGrid ()->DcDraw( &aCDcdTargetMfcPrintInfo ) ;
}
@endcode

*/
class CWndDcdGrid : public CWnd 
{
	friend class CXDcdGrid ;	//update() の呼び出しを許可
	friend class CFocus ;	//update() の呼び出しを許可
	friend class CSelect ;	//update() の呼び出しを許可
	friend class CSelectCell ;	//update() の呼び出しを許可
	friend class CBoxSelect ;	//update() の呼び出しを許可
public:
	// ********************************
	//	インナータイプ
	// ********************************


public:
	typedef CWnd super ;

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		「領域外ドラッグスクロール」のタイマ時間間隔。
		単位はミリ秒です。
		既定値は、100msです。
	*/
	UINT m_iOutsideDrag_TimeMs ;
	///@}
	// ********************************
	///@name 状態
	// ********************************
	///@{
	/**
		通常はfalseです。

		このウインドウで左ボタンクリックされてから、
		ボタンが離されるまで・
		もしくはウインドウがフォーカスを失うまでの間だけtrueです。

		
		ウインドウがフォーカスを得た時点で既に
		マウス左ボタンが押し下げられていた場合は、falseです。
	*/
	bool m_bLButtonIsDown ;
	/**
		マウスの左ボタンがこのウインドウ上で最後に押し下げられた
		時の、マウスカーソルの座標を保持します。
		単位は、ウインドウのクライアント座標(デバイス座標)です。
	*/
	CdDcdPosXy	m_posxyCursorPosOnLButtonDown ;
	///@}
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
		このウインドウに描画を行う CDcdGrid オブジェクトです。
		コンストラクタで生成・デストラクタで破棄します。
	 */
	CXDcdGrid*	m_pCDcdGrid ;
	
	/**
		CWndDcdGrid のフォーカス・スクロールの制御をクラス化したものです。
		コンストラクタで生成・デストラクタで破棄します。
	 */
	CFocus*	m_pCFocus ;
	
	/**
		CWndDcdGrid のセル選択の制御をクラス化したものです。
		コンストラクタで生成・デストラクタで破棄します。
	 */
	CSelect*	m_pCSelect ;

	/**
		CWndDcdGrid 上での、ユーザーのBoxSelect(箱型選択操作)にしたがって、
		CSelect,CSelectCell の属性を変更します。
	 */
	CBoxSelect*	m_pCBoxSelect ;
	/**
		CWndDcdGrid 上での、ユーザーのRandomSelect(個別のセル選択操作)に
		したがって、CSelect,CSelectCell の属性を変更します。
	 */
	CRandomSelect*	m_pCRandomSelect ;
	///@}
private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
	-	true ;	タイマスクロールのタイマがON。
	*/
	bool m_bOutsideDrag_TimerOn ;

	/**
	  通常は false 。
	  this は、update() の呼び出しを抑制したい場合は true とします。
	
	-true: update() の呼び出しを禁止しています。
		この間の(集約している CXDcdGrid,CFocusScroll,CSelect からの)
		update() 呼び出しはすべて、何もせずに return します。

		update() の再入を避けるために用いられます。
	*/
	bool m_bDisable_UpdateAll ;


	///@}

protected:
	// --------------------------------
	///@name	下請関数
	// --------------------------------
	///@{
	/**
	属性の変更をもとに、ウインドウ表示の更新処理を行います。
	WndDcdGrid3::CWndDcdGrid のすべての包含オブジェクトの更新も行います。

	このクラスの update() は、集約オブジェクトからも呼び出されます。

	@attention	この関数は、同じオブジェクトに対する再入を禁止しています。
		再入呼び出しは、何もせずに false を返して return します。

	@return 
		正規化の結果、何らかの値を変化させた場合は真です。
	 */
	virtual bool update( ) ; 

	/**
	フォーカスセル移動時の、CPropStack インスタンスを生成します。
	このオブジェクトは、生存期間中は以下の属性を設定します。

	- WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange = true

	 UI操作によるフォーカスセル移動時に、
	 スクロール位置が追従するようにします。
	*/
	Ou<CPropStack> createPropStackForMovingFocusCell() ;

	/**
	スクロール時の、CPropStack インスタンスを生成します。
	このオブジェクトは、生存期間中は以下の属性を設定します。

	- WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange = false

	 UI操作によるスクロールバー位置の変更に、
	 フォーカスセルが追従するようにします。
	*/
	Ou<CPropStack> createPropStackForScroll() ;

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CWndDcdGrid();
	virtual ~CWndDcdGrid();

// ********************************
//	CDcdGrid
// ********************************
protected:
	// --------------------------------
	///@name CDcdGrid-行・列・セルの初期化
	// --------------------------------
	///@{
	/**
	this は、新しい Column が生成された直後に、この関数を呼び出します。
	新しい Column に対して、 IfDcDraw インターフェースオブジェクト
	の生成・登録をはじめとした
	初期化を行います。

	この関数をオーバライドすることにより、 Column に特有の初期化を
	行うことができます。
		
	@param iXColumnNumber [in]
		  新しい Column の列番号です。
	@param pCDcdGridXColumn [in,out]
		  新しく生成された CDcdGridXColumn オブジェクトです。
		  この関数はこのオブジェクトに対して、初期化を行うことができます。
		
	 [オーバライド]
		包含している CXDcdGrid オブジェクト( m_pCDcdGrid ) に対して、
		CDcdGrid::OnCreateXColumn() を呼び出します。
	 */
	virtual void OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) ;
	
	/**
	this は、Column が破棄される直前に、この関数を呼び出します。
	破棄される Column に対して、 IfDcDraw インターフェースオブジェクトの
	登録解除・破棄をはじめとした
	後始末を行います。

	この関数をオーバライドすることにより、 Column に特有の後始末を
	行うことができます。
		
	@param iXColumnNumber [in]
		  破棄される Column の列番号です。
	@param pCDcdGridXColumn [in,out]
		  破棄される CDcdGridXColumn オブジェクトです。
		  この関数はこのオブジェクトに対して、後始末を行うことができます。
		
		
	 [オーバライド]
		包含している CXDcdGrid オブジェクト( m_pCDcdGrid ) に対して、
		CDcdGrid::OnDeleteXColumn() を呼び出します。
	 */
	virtual void OnDeleteXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) ;

	/**
	this は、新しい Column が生成された直後に、この関数を呼び出します。
	新しい Column に対して、 IfDcDraw インターフェースオブジェクト
	の生成・登録をはじめとした
	初期化を行います。

	この関数をオーバライドすることにより、 Column に特有の初期化を
	行うことができます。
		
	@param iYColumnNumber [in]
		  新しい Column の列番号です。
	@param pCDcdGridYColumn [in,out]
		  新しく生成された CDcdGridYColumn オブジェクトです。
		  この関数はこのオブジェクトに対して、初期化を行うことができます。
		
		
	 [オーバライド]
		包含している CXDcdGrid オブジェクト( m_pCDcdGrid ) に対して、
		CDcdGrid::OnCreateYColumn() を呼び出します。
	 */
	virtual void OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;
	
	/**
	this は、Column が破棄される直前に、この関数を呼び出します。
	破棄される Column に対して、 IfDcDraw インターフェースオブジェクトの
	登録解除・破棄をはじめとした
	後始末を行います。

	この関数をオーバライドすることにより、 Column に特有の後始末を
	行うことができます。
		
	@param iYColumnNumber [in]
		  破棄される Column の列番号です。
	@param pCDcdGridYColumn [in,out]
		  破棄される CDcdGridYColumn オブジェクトです。
		  この関数はこのオブジェクトに対して、後始末を行うことができます。
		
		
	[オーバライド]
		包含している CXDcdGrid オブジェクト( m_pCDcdGrid ) に対して、
		CDcdGrid::OnDeleteYColumn() を呼び出します。
	 */
	virtual void OnDeleteYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;

	/**
	this は、新しい Cell が生成された直後に、この関数を呼び出します。
	新しい Cell に対して、 IfDcDraw インターフェースオブジェクト
	の生成・登録をはじめとした
	初期化を行います。

	この関数をオーバライドすることにより、 Cell に特有の初期化を
	行うことができます。
		
	@param iXColumnNumber [in]
		  新しい Cell のX列番号です。
	@param iYColumnNumber [in]
		  新しい Cell のY列番号です。
	@param pCDcdGridCell [in,out]
		  新しく生成された CDcdGridCell オブジェクトです。
		  この関数はこのオブジェクトに対して、初期化を行うことができます。
		
		
	[オーバライド]
		包含している CXDcdGrid オブジェクト( m_pCDcdGrid ) に対して、
		CDcdGrid::OnCreateCell() を呼び出します。
	 */
	virtual void OnCreateCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) ;
	
	/**
	this は、Cell が破棄される直前に、この関数を呼び出します。
	破棄される Cell に対して、 IfDcDraw インターフェースオブジェクトの
	登録解除・破棄をはじめとした
	後始末を行います。

	この関数をオーバライドすることにより、 Cell に特有の後始末を
	行うことができます。
		
	@param iXColumnNumber [in]
		  破棄される Cell のX列番号です。
	@param iYColumnNumber [in]
		  破棄される Cell のY列番号です。
	@param pCDcdGridCell [in,out]
		  破棄される CDcdGridCell オブジェクトです。
		  この関数はこのオブジェクトに対して、後始末を行うことができます。
		
		
	[オーバライド]
		包含している CXDcdGrid オブジェクト( m_pCDcdGrid ) に対して、
		CDcdGrid::OnDeleteCell() を呼び出します。
	 */
	virtual void OnDeleteCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) ;
	///@}
public:
	// ********************************
	///	@name CDcdGrid-Y列・X列の位置
	// ********************************
	///@{
	/**
	ウインドウのクライアント領域内での、
	Y列の位置を返します。

	@param iYColumnNumber [in]
		Y列番号を指定してください。
	@return
		Y列の範囲を返します。
	 */
	virtual CdDcdZone	getYColumnZone( 
			int iYColumnNumber ) ;
		
	/**
	ウインドウのクライアント領域内での、
	X列の位置を返します。

	@param iXColumnNumber [in]
		X列番号を指定してください。
	@return
		X列の範囲を返します。
	
	@attention
		この関数は、createZoneCacheの影響を受けます。
		これらの関数 を連続して呼び出す場合は、
		前もって createZoneCache() を呼び出すと、
		パフォーマンスが改善されます。
	 */
	virtual CdDcdZone	getXColumnZone( 
			int iXColumnNumber ) ;
	
	/**
	ウインドウのクライアント領域内での、
	Y列の下側の境界線の位置を返します。

	@param iYColumnNumber [in]
		Y列番号を指定してください。範囲は-1以上 getYColumnCount() 未満です。
	@return
		Y列の境界線の範囲を返します。
	 */
	virtual CdDcdZone	getYColumnBorderZone( 
			int iYColumnNumber ) ;

	/**
	ウインドウのクライアント領域内での、
	X列の右側の境界線の位置を返します。

	@param iXColumnNumber [in]
		X列番号を指定してください。範囲は-1以上 getXColumnCount() 未満です。
	@return
		X列の境界線の範囲を返します。
	 */
	virtual CdDcdZone	getXColumnBorderZone( 
			int iXColumnNumber ) ;
	/**
	ウインドウのクライアント領域内での、
	セルの位置を返します。

	@param iXColumnNumber [in]
		X列番号を指定してください。範囲は0以上 getXColumnCount() 未満です。
	@param iYColumnNumber [in]
		Y列番号を指定してください。範囲は0以上 getYColumnCount() 未満です。
	@return
		セルの位置を返します。
	 */
	virtual CdDcdZoneXy	getCellZone( 
		int iXColumnNumber , int iYColumnNumber ) ;

	/**
	ウインドウのクライアント領域内での、
	Y座標に対応する、Y列番号を調べます。
	
	@param iPos [in]
		Y座標を指定してください。
	@param pbIsBorder [out]
		この関数は、 iPos が境界線上にある場合は true 、
		 iPos が列の範囲にあるなら false です。
	@return
	 	Y列番号を返します。
	 
	 	- Y列番号 = -1 , *pbIsBorder=false : グリッドの上の外側です。
	 	- Y列番号 = -1 , *pbIsBorder=true : グリッドの上の境界線です。
	 	- Y列番号 = 0 以上 getYColumnCount()未満 , *pbIsBorder = false : 
	 		グリッドのY列範囲です。
	 	- Y列番号 = 0 以上 getYColumnCount()未満 , *pbIsBorder = true : 
	 		グリッドのY列下側の境界線の範囲です。
	 	- Y列番号 = getYColumnCount() , *pbIsBorder = false : 
	 		グリッドの下の外側です。
	 */
	virtual int getYColumnNumberOfPos( 
		int iPos , bool* pbIsBorder ) ;
	/**
	ウインドウのクライアント領域内での、
	X座標に対応する、X列番号を調べます。
	
	@param iPos [in]
		X座標を指定してください。
	@param pbIsBorder [out]
		この関数は、 iPos が境界線上にある場合は true 、
		 iPos が列の範囲にあるなら false です。
	@return
		X列番号を返します。
	
		- X列番号 = -1 , *pbIsBorder=false : グリッドの左の外側です。
		- X列番号 = -1 , *pbIsBorder=true : グリッドの左の境界線です。
		- X列番号 = 0 以上 getXColumnCount()未満 ,pbIsBorder = false : 
			グリッドのX列範囲です。
		- X列番号 = 0 以上 getXColumnCount()未満 , *pbIsBorder = true : 
			グリッドのX列右側の境界線の範囲です。
		- X列番号 = getXColumnCount() ,pbIsBorder = false : 
			グリッドの右の外側です。
	
	@attention
		この関数は、createZoneCacneの影響を受けます。
		これらの関数 を連続して呼び出す場合は、
		前もって createZoneCache() を呼び出すと、
		パフォーマンスが改善されます。
	 */
	virtual int getXColumnNumberOfPos( 
		int iPos , bool* pbIsBorder ) ;
	
	/**
	ウインドウのクライアント領域内での、
	X,Y 座標に対応する、セルを調べます。

	@param aCdDcdPosXy [in]
		XY座標を指定してください。
	@return
		セルオブジェクトを返します。
		指定の座標がセルの範囲に位置していない場合は、NULLを返します。
	 */
	virtual CDcdGridCell* getCellOfPos( 
		const CdDcdPosXy& aCdDcdPosXy ) ;

	///@}
public:
	// ********************************
	///	@name	CDcdGrid-スクロール
	// ********************************
	///@{

	/**
	指定のマウスカーソル位置での「領域外ドラッグスクロール」
	の可否と、可能であればスクロールの方向を算出します。

	@param pos [in]
		マウスカーソルの座標を、クライアント座標で指定してください。
		この関数は、
		「マウスがドラッグされてこの座標にある場合に、スクロールが必要か」
		を判定します。
	@return 
		X,Yそれぞれについて、「グリッド外でのマウスドラッグによるスクロール」
		の可否を返します。

	@note
		戻り値の意味は、Xの場合は以下のようになります。
		-	 0 ;「領域外ドラッグスクロール」は不要
		-	-1 ;カーソルは、領域外(左)(Y座標なら上)です。@n
			左へ(Yなら下へ)の「領域外ドラッグスクロール」を@n
			行うことができます。
		-	+1 ;カーソルは、領域外(右)(Y座標なら下)です。@n
			右へ(Yなら下へ)の「領域外ドラッグスクロール」を@n
			行うことができます。
	*/
	CdDcdSizeXy calcIncreaseOnOutsideDrag( const POINT& pos ) ;

	///@}
public:
	// ********************************
	///	@name	CDcdGrid-セルの結合
	// ********************************
	///@{

	/**
	ウインドウのクライアント領域内での、
	Y列の位置を返しますが、スクロール機能によって非表示になっている
	Y列（ YFixafterColumnNumber 未満）の位置も返します。この場合、
	このY列の位置は、固定Y列に重なったり、グリッドの一番上よりも上に
	なることがあります。

	@param iYColumnNumber [in]
		Y列番号を指定してください。
	@return
		Y列の範囲を返します。
	 */
	virtual CdDcdZone	getYColumnZoneOverlap( 
			int iYColumnNumber ) ;
	/**
	ウインドウのクライアント領域内での、
	X列の位置を返しますが、スクロール機能によって非表示になっている
	X列（ XFixafterColumnNumber 未満）の位置も返します。この場合、
	このX列の位置は、固定X列に重なったり、グリッドの一番左よりも左に
	なることがあります。
	
	@param iXColumnNumber [in]
		X列番号を指定してください。
	@return
		X列の範囲を返します。
	 */
	virtual CdDcdZone	getXColumnZoneOverlap( 
			int iXColumnNumber ) ;

	/**
	ウインドウのクライアント領域内での、
	セルの位置を返しますが、スクロール機能によって非表示になっている
	セルの位置も返します。この場合、
	このセルの位置は、固定Y列・X列に重なったり、
	グリッドの一番左よりも左・一番上よりも上に
	なることがあります。
	
	@param iXColumnNumber [in]
		X列番号を指定してください。
	@param iYColumnNumber [in]
		Y列番号を指定してください。
	@return
		セルの範囲を返します。
	 */
	virtual CdDcdZoneXy	getCellZoneOverlap( 
		int iXColumnNumber , int iYColumnNumber ) ;
	
	///@}
protected:
	// ********************************
	//	CWndDcdGrid
	// ********************************

	// --------------------------------
	///@name	CWndDcdGrid-イベント処理のための仮想関数
	// --------------------------------
	///@{
	/**
	  this は、フォーカスセルが移動したときに、この仮想関数を呼び出します。
	  クラスユーザーは、この仮想関数をオーバライドして、必要な処理を
	実装できます。
	  
	  this は、クラスユーザーが setFocusCell() でフォーカスセルを移動した
	ときのほか、キーボードでフォーカスセルを移動したとき・スクロールバーで
	ウインドウをスクロールした結果フォーカスセルが移動したとき・
	ウインドウサイズが変化した結果フォーカスセルが移動したときにも、
	この仮想関数を呼び出します。

	[オーバライド]
	  処理はありません。
	
	@param pCDcdGridCell [in]
		新しいフォーカスセルです。
	 */
	virtual void OnSetFocusCell( CDcdGridCell* pCDcdGridCell ) ;

	/**
	  this は、FixafterColumnNumber が変化したとき
	（スクロール位置が変化したとき）に、この仮想関数を呼び出します。
	  クラスユーザーは、この仮想関数をオーバライドして、必要な処理を
	実装できます。
	  
	  this は、クラスユーザーが 
	setXFixafterColumnNumber() で値を設定したときのほか、
	キーボードでフォーカスセルを移動した結果スクロールが発生したとき・
	スクロールバーでウインドウをスクロールしたときにも
	この仮想関数を呼び出します。

	[オーバライド]
	  処理はありません。
	
	@param iFixafterColumnNumber [in]
		新しい FixafterColumnNumber です。
	 */
	virtual void OnSetXFixafterColumnNumber( int iFixafterColumnNumber ) ;

	/**
	  this は、FixafterColumnNumber が変化したとき
	（スクロール位置が変化したとき）に、この仮想関数を呼び出します。
	  クラスユーザーは、この仮想関数をオーバライドして、必要な処理を
	実装できます。
	  
	  this は、クラスユーザーが 
	setYFixafterColumnNumber() で値を設定したときのほか、
	キーボードでフォーカスセルを移動した結果スクロールが発生したとき・
	スクロールバーでウインドウをスクロールしたときにも
	この仮想関数を呼び出します。

	[オーバライド]
	  処理はありません。
	
	 @param iFixafterColumnNumber [in]
		新しい FixafterColumnNumber です。
	 */
	virtual void OnSetYFixafterColumnNumber( int iFixafterColumnNumber ) ;

	/**
	  this は、WndDcdGrid3::CSelectCell::m_bIsSelected が
	  変化したときに、この仮想関数を呼び出します。
	  クラスユーザーは、この仮想関数をオーバライドして、必要な処理を
	実装できます。
	  
	  this は、クラスユーザーが 
	CWndDcdGrid::CSelect::setColumnNumberSelect() で
	値を設定したときのほか、
	キーボードで選択セルを変更したときにも
	この仮想関数を呼び出します。
	
	[オーバライド]
		  処理はありません。
	
	@param iXColumnNumber [in]
		X列番号を指定します。
	@param iYColumnNumber [in]
		X列番号を指定します。
	@param bIsSelected [in]
		新しい選択状態。
	 */
	virtual void OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) ;

	///@}


public:
	// ********************************
	///@name CWndDcdGrid-属性
	// ********************************
	///@{
	UINT getOutsideDrag_TimeMs()const{	return m_iOutsideDrag_TimeMs ;};
	void setOutsideDrag_TimeMs( UINT value )
	{	m_iOutsideDrag_TimeMs = value ;};
	///@}
	// ********************************
	///@name 状態
	// ********************************
	///@{
	virtual bool getLButtonIsDown()const{	return m_bLButtonIsDown ;};
	virtual CdDcdPosXy	getCursorPosOnLButtonDown()const
	{	return m_posxyCursorPosOnLButtonDown ;};

	/**
	@return
		このウインドウのDcdGrid上からの
		マウスのドラッグが行われている間だけ true です。
	*/
	virtual bool isDragging()const
	{	return m_bOutsideDrag_TimerOn ;};
	///@}

public:
	// ********************************
	///@name CWndDcdGrid-包含
	// ********************************
	///@{
	CXDcdGrid*	getCXDcdGrid() ;
	CFocus*	getCFocus() ;
	CSelect*	getCSelect() ;
	CBoxSelect*	getCBoxSelect() ;
	CRandomSelect*	getCRandomSelect() ; 
	///@}
public:
	// ********************************
	///@name CWndDcdGrid-構築
	// ********************************
	///@{
	/**
	  ウインドウのHWNDを生成します。

	@param rect [in]
		ウインドウのサイズと位置を指定します。
		CRect オブジェクトまたは RECT 構造体を指定できます。
	@param pParentWnd [in]
		コントロールの親ウィンドウ (CDialogの場合が多い) を指定します。
		NULL は指定できません。
	@param nID [in]
		コントロールの ID を指定します。
	 */
	BOOL Create( const RECT& rect, CWnd* pParentWnd, UINT nID = 0 );

	/**
	サイズ０で、ウインドウのHWNDを生成します。
	親ウインドウのサイズをもとに位置を決定する場合には、
	こちらを使うことができます。
	
	@param pParentWnd [in]
		コントロールの親ウィンドウ (CDialogの場合が多い) を指定します。
		NULL は指定できません。
	@param nID [in]
		コントロールの ID を指定します。
	 */
	BOOL Create( CWnd* pParentWnd, UINT nID  = 0 );
	///@}
public:
	// ********************************
	///@name CWndDcdGrid-操作
	// ********************************
	///@{
	/**
	@return
		SHIFTキーが押されていたらtrue 
	*/
	static bool isShiftPressed() ;

	/**
	@return
		Ctrlキーが押されていたらtrue 
	*/
	static bool isCtrlPressed() ;

	/**
		すべてのセルを選択します。

	@note
		BoxSelect は、解除状態にします。
		BoxSelectで全セルを選択すると、選択後に
		RandomSelectで一部セルの選択を解除することができなくなります。
		これを回避するためです。
	*/
	virtual void selectAll() ;


	/**
		セル選択を解除します。

		BoxSelect の選択も解除状態にします。
	*/
	virtual void clearSelect() ;



public:
	// ********************************
	///@name CWndDcdGrid-ウインドウ更新
	// ********************************
	///@{
	/**
	ウインドウ上の、
	X列の右側の境界線の描画位置を無効化し、
	再描画を要求します。

	@param iXColumnNumber [in]
		X列番号を指定してください。範囲は-1以上 getXColumnCount() 未満です。
	@param bErase [in]
		更新リージョン内の背景を消去するかどうかを指定します。
		(ウインドウの背景色を活かした描画を行っている場合は、
		true にする必要があります。
		NULL PEN や NULL BRUSHを使用して描画を行っている場合が、これに該当します)。
	@return
		成功したら0以上、エラーなら負の数です。
		-	0 ;	//	再描画領域はありません。
		-	1 ;	//	再描画の要求を行いました。
	@attention
		境界線の描画位置を含む領域を
		CWnd::Invalidate() や、CWnd::InvalidateRect() などで、
		無効化した場合は、改めてこの関数を呼び出さなくても、
		セルは次の WM_PAINT で再描画されます。
	 */	 
	virtual int InvalidateXColumnBorder( int iXColumnNumber ,
		bool bErase = true ) ;
	/**
	ウインドウ上の、
	Y列の下側の境界線の描画位置を無効化し、
	再描画を要求します。

	@param iYColumnNumber [in]
		Y列番号を指定してください。範囲は-1以上 getYColumnCount() 未満です。
	@param bErase [in]
		更新リージョン内の背景を消去するかどうかを指定します。
		(ウインドウの背景色を活かした描画を行っている場合は、
		true にする必要があります。
		NULL PEN や NULL BRUSHを使用して描画を行っている場合が、これに該当します)。
	@return
		成功したら0以上、エラーなら負の数です。
		-	0 ;	//	再描画領域はありません。
		-	1 ;	//	再描画の要求を行いました。
	@attention
		セルの描画位置を含む領域を
		CWnd::Invalidate() や、CWnd::InvalidateRect() などで、
		無効化した場合・あるいはグリッドウインドウ全体を 
		CWndDcdGrid::Invalidate() や CWnd::Invalidate() で無効化
		した場合は、改めてこの関数を呼び出さなくても、
		セルは次の WM_PAINT で再描画されます。
	 */	 
	virtual int InvalidateYColumnBorder( int iYColumnNumber ,
		bool bErase = true ) ;
	/**
	ウインドウ上の指定のセルの描画位置を無効化し、
	再描画を要求します。

	@param iXColumnNumber [in] 
		 X列番号を指定してください。範囲は、0以上 getXColumnCount() 未満です。
	@param iYColumnNumber [in] 
		 Y列番号を指定してください。範囲は、0以上 getYColumnCount() 未満です。
	@param bErase [in]
		更新リージョン内の背景を消去するかどうかを指定します。
		(ウインドウの背景色を活かした描画を行っている場合は、
		true にする必要があります。
		NULL PEN や NULL BRUSHを使用して描画を行っている場合が、これに該当します)。
	@return
		成功したら0以上、エラーなら負の数です。
		-	0 ;	//	再描画領域はありません。
		-	1 ;	//	再描画の要求を行いました。
	@attention
		セルの描画位置を含む領域を
		CWnd::Invalidate() や、CWnd::InvalidateRect() などで、
		無効化した場合・あるいはグリッドウインドウ全体を 
		CWndDcdGrid::Invalidate() や CWnd::Invalidate() で無効化
		した場合は、改めてこの関数を呼び出さなくても、
		セルは次の WM_PAINT で再描画されます。
	 */	 
	virtual int InvalidateCell( int iXColumnNumber , int iYColumnNumber ,
		bool bErase = true ) ;

	/**
	ウインドウ全域を無効化し、
	再描画を要求します。
	このとき、スクロールバーの属性の再設定・
	フォーカスセルの正規化も行います。

	Column の ColumnSize・ColumnBorderSize の幅を変更した場合は、
	この関数を呼び出して、再描画を行ってください。
	（Column の AutoColumnSize ・AutoColumnBorderSize 属性が
	有効な場合で、 IfDcDraw を置き換えて CDcdGrid の大きさを変更した場合も
	これに含みます）。
	
	@param bErase [in]
		更新リージョン内の背景を消去するかどうかを指定します。
		(ウインドウの背景色を活かした描画を行っている場合は、
		true にする必要があります。
		NULL PEN や NULL BRUSHを使用して描画を行っている場合が、これに該当します)。
	
	@attention
		CWnd::Invalidate() では、スクロールバーやフォーカスセルの
		最適化は行われません。
		グリッド全体の再描画を行う場合は、 CWnd::Invalidate() の代わりに
		この関数を呼び出さなくてはなりません。
	 */
	virtual void InvalidateGrid( 
		bool bErase = true ) ;
	///@}
	
// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(CWndDcdGrid)
	//}}AFX_VIRTUAL

// インプリメンテーション

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CWndDcdGrid)
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif //DcDraw_DcdGrid_WndDcdGrid3_CWndDcdGrid_H

