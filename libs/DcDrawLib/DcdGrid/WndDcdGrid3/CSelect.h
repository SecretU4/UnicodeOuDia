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
//	CSelect.h
//$Id: CSelect.h 296 2016-06-11 05:40:21Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdGrid_WndDcdGrid3_CSelect_h
#define  DcDraw_DcdGrid_WndDcdGrid3_CSelect_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>
#include "NsOu\Ou.h"
#include "DcDraw\IfDcDraw.h"
#include "DcdGrid\WndDcdGrid3\CSelectCell.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{
	
class CPropStack ;

// ****************************************************************
//	WndDcdGrid3::CSelect
// ****************************************************************
/**
@brief
	CWndDcdGrid のCellSelect(セル選択)をクラス化したものです。

 WndDcdGrid3::CWndDcdGrid 上のすべてのセル選択状態を保持するクラスです。
 セル１つの選択状態を保持する CSelectCell を、セルの数だけ集約します。
 
 このクラスは、 CWndDcdGrid  が内部的に生成するために存在します。
それ以外の利用価値はありません。

 【使い方】

(1) このクラスのオブジェクトは、 WndDcdGrid3::CWndDcdGrid で生成されます。
WndDcdGrid3::CWndDcdGrid::getCSelect() で、オブジェクトにアクセスできます。

(2) 　WndDcdGrid3::CSelect::getCell() メソッドで、セルの選択状況を
表す WndDcdGrid3::CSelectCell オブジェクトを取得することができます。
 WndDcdGrid3::CSelectCell::setIsSelected() メソッドを用いることにより、
セルを選択状態にすることができます。

*/
class CSelect
{
	friend class CWndDcdGrid ;
public:
	// ****************************************************************
	//	CWndDcdGrid::CSelect::ESelectMode
	// ****************************************************************
	/**
		CWndDcdGridのセル選択のモードを表します。
	*/
	enum ESelectMode
	{ 
		/// (デフォルト)選択は不可能です。(CSelectCell::m_bIsSelected は無効)
		SelectMode_NONE , 	
		/// X列・Y列両方の選択が可能です。
		SelectMode_XY , 
		/// X列の選択のみ可能です。Y列は常時全域選択となります。
		SelectMode_XColumn , 
		/// Y列の選択のみ可能です。X列は常時全域選択となります。
		SelectMode_YColumn ,
	};
protected:
	// --------------------------------
	//	インナータイプ
	// --------------------------------
	typedef	std::deque< CSelectCell* > CSelectYColumnCellCont ;
	typedef	std::deque< CSelectYColumnCellCont* > CSelectCellCont ;
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
		選択セルに対して、選択マークを描画する
		DcDraw オブジェクトです。
	 */
	Ou<IfDcDraw>	m_pIfDcDrawSelect ;
	///@}

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		選択マークの描画領域に罫線を含めるか否かの指定です。
		- true: 選択マークの描画領域に、セルの右側、下側の罫線を含めます。
			一番左・下の罫線(グリッド全体の左・下の罫線)は範囲に含めません。
		- false: 選択マークの描画領域に、セルの右側、下側の罫線を含めません。

		既定値は true です。
	*/
	bool m_bIncludeRbBorder ;

	/**
		CWndDcdGridのセル選択のモードを表します。
		既定値は、 SelectMode_NONE です。
	*/
	ESelectMode	m_eSelectMode ;

	/**
		選択可能制限範囲。
		単位はセル番号です。

		この属性は、セルの数より大きい値をとることができます。@n
		(m_ColumnNumberSelectLimit.getX().getEndPos()
			>CDcdGrid::getXColumnCount()
		になることができます。Y列も同様です。)

		選択可能な範囲。デフォルトは、X,Yとも 
		Posが 0 、SizeがINT_MAXとなります。
	*/
	CdDcdZoneXy	m_ColumnNumberSelectLimit ;

	/**
	@brief CWndDcdGrid全体の更新の有効/無効

	  セル選択の変更時に CWndDcdGrid 全体を更新するか否かを指定します。

	  - true: (デフォルト)セル選択(CSelectCell::m_bIsSelected)の変更時に、
	  	CWndDcdGrid 全体を更新します( CWndDcdGrid::update())を呼び出し)。
	  - false: セル選択(CSelectCell::m_bIsSelected)の変更時にも、 
	  	CWndDcdGrid 全体の更新は行いません。

	  属性を false から true に変更した場合は、CWndDcdGrid 全体を更新します。

	  「セル選択の変更時」は、
	  	CSelectCell::m_bIsSelected の変化時を指します。
	*/
	bool m_bUpdateCWndDcdGrid ;

	///@}
 private:
	// ********************************
	///	@name 集約
	// ********************************
	///@{
	/**
	  	セルオブジェクトを保持するコンテナです。
	  	
	  	このコンテナの要素数は、YColumn の数に等しくなります。
	  	このコンテナの各要素は、 XColumn 分の CDcdGridCell を保持する
	  	コンテナです。
	  	
	  	したがって、
	  
	  	m_CDcdGridCellCont[Y列番号][X列番号]
	  
	  	の形式で、対応する CDcdGridCell オブジェクトにアクセスができます。
	  
	  	コンテナ内のオブジェクトの破棄の責務は、thisにあります。
	 */
	CSelectCellCont 	m_CSelectCellCont ;
	///@}
public:
	// ********************************
	///@name 定数
	// ********************************
	///@{
	///@}

private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
		CWndDcdGridのセル選択のモードの前回値。
		update_updateScreen() で更新されます。
		
		この属性は、m_eSelectMode が SelectMode_NONE のときに、
		このクラスの処理を軽量化するために使用します。
		
		m_eSelectMode が SelectMode_NONE に変更された場合は、
		全ての選択セルを解除します。
		
		m_eSelectMode が SelectMode_NONE である間は、
		update_adjustProp()・update_updateScreen()・OnPaint()は
		何もせずにリターンします。
		
	*/
	ESelectMode	m_eSelectMode_Prev ;

	/**
		選択されているセルの数。
		update_adjustProp() で更新されます。
	*/
	int	m_iSelectedCellCount ;

	///@}

protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{


	/**
	  setYColumnCount() と insertYColumn() の下請関数です。

	  Y列を１つ、指定の位置に追加します。
	  この関数は、 
	    m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	    m_CDcdGridCellCont
	の増減だけを行います。
	adjustProp() は行いません。

	@param iYColumnNumber [in]
		  Y列番号を指定してください。
		新しく追加されたY列が、このY列番号になります。
		範囲は 0 以上 getYColumnNumber() 以下で、
		0 なら先頭・getYColumnNumber() なら末尾への追加となります。
		  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	@return
		成功したら0以上、エラーなら負の数です。
		-	-2 ;	//	インデクスが不正
	 */
	int insertYColumn_insertColumnCell( int iYColumnNumber ) ;

	/**
	  setXColumnCount() と insertXColumn() の下請関数です。

	  X列を１つ、指定の位置に追加します。
	  この関数は、 
	    m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	    m_CDcdGridCellCont
	の増減だけを行います。
	  adjustProp() は行いません。

	@param iXColumnNumber [in]
		X列番号を指定してください。
		新しく追加されたX列が、このX列番号になります。
		範囲は 0 以上 getXColumnNumber() 以下で、
		0 なら先頭・getXColumnNumber() なら末尾への追加となります。
		  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	@return
		成功したら0以上、エラーなら負の数です。
		-	-2 ;	//	インデクスが不正
	 */
	int insertXColumn_insertColumnCell( int iXColumnNumber ) ;
	
	/**
  	setYColumnCount() と eraseYColumn() の下請関数です。
  
  	Y列を１つ、削除します。
  	この関数は、 
  	m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
  	m_CDcdGridCellCont
  	の増減だけを行います。
  	adjustProp() は行いません。

	@param iYColumnNumber [in]
  		Y列番号を指定してください。
  		範囲は 0 以上 getYColumnNumber() 未満です。
  		  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	@return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	int eraseYColumn_eraseColumnCell( int iYColumnNumber ) ;

	/**
	setXColumnCount() と eraseXColumn() の下請関数です。

	X列を１つ、削除します。
	この関数は、 
	m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	m_CDcdGridCellCont
	の増減だけを行います。
	adjustProp() は行いません。

	@param iXColumnNumber [in]
	  	X列番号を指定してください。
	  	範囲は 0 以上 getXColumnNumber() 未満です。
	  	  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	@return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	int eraseXColumn_eraseColumnCell( int iXColumnNumber ) ;

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
	///@name WndDcdGrid3::CDcdGrid からの委譲
	// --------------------------------
	///@{
	/**
  	  this は、新しい Column が生成された直後に、この関数を呼び出します。
  	  新しい Column に対して、 IfDcDraw インターフェースオブジェクト
  	の生成・登録をはじめとした初期化を行います。
  
  	この関数をオーバライドすることにより、 Column に特有の初期化を
  	行うことができます。
  	
	@param iXColumnNumber [in]
	  	  新しい Column の列番号です。
	@param pCDcdGridXColumn [in,out]
	  	  新しく生成された CDcdGridXColumn オブジェクトです。
	  	  この関数はこのオブジェクトに対して、初期化を行うことができます。
	  	
	[オーバライド]
		 CSelectCell オブジェクトの追加・削除を行います。
	 */
	virtual void OnCreateXColumn( int iXColumnNumber ) ;
	
	/**
	  this は、Column が破棄される直前に、この関数を呼び出します。
	  破棄される Column に対して、 IfDcDraw インターフェースオブジェクトの
	登録解除・破棄をはじめとした後始末を行います。

	この関数をオーバライドすることにより、 Column に特有の後始末を
	行うことができます。
	  	
	@param iXColumnNumber [in]
	  	  破棄される Column の列番号です。
	  	
	[オーバライド]
	   CSelectCell オブジェクトの追加・削除を行います。
	 */
	virtual void OnDeleteXColumn( int iXColumnNumber ) ;

	/**
	  this は、新しい Column が生成された直後に、この関数を呼び出します。
	  新しい Column に対して、 IfDcDraw インターフェースオブジェクト
	の生成・登録をはじめとした初期化を行います。

	  この関数をオーバライドすることにより、 Column に特有の初期化を
	行うことができます。
	  	
	@param iYColumnNumber [in]
	  新しい Column の列番号です。

	[オーバライド]
	   CSelectCell オブジェクトの追加・削除を行います。
	 */
	virtual void OnCreateYColumn( int iYColumnNumber ) ;
	
	/**
	  this は、Column が破棄される直前に、この関数を呼び出します。
	  破棄される Column に対して、 IfDcDraw インターフェースオブジェクトの
	登録解除・破棄をはじめとした後始末を行います。

	    この関数をオーバライドすることにより、 Column に特有の後始末を
	行うことができます。

	@param iYColumnNumber [in]
		破棄される Column の列番号です。

	[オーバライド]
	   CSelectCell オブジェクトの追加・削除を行います。
	 */
	virtual void OnDeleteYColumn( int iYColumnNumber ) ;

	///@}
protected:
	// --------------------------------
	///@name CWndDcdGrid からの委譲
	// --------------------------------
	///@{
	/**
		CWndDcdGrid::update() の下請関数です。
	
		- 属性の補正
		- CSelectCell への委譲

		を行います。

	【1.属性の補正】

	1.ColumnNumberSelectLimitによる、CSelectCell::m_bIsSelected の正規化。

	1.1.m_eSelectMode が SelectMode_NONE の場合、
	すべてのセルを非選択にします。

	1.2.m_eSelectMode が SelectMode_XColumn の場合、
	同じX列番号(縦方向)のセルの選択状況をすべて同一にします。

	1.2.1.いずれかのセルの CSelectCell::m_bIsSelected がtrueに変更されていたら、
	すべてのセルをtrueにします。

	1.2.2.いずれかのセルの CSelectCell::m_bIsSelected がfalseに変更されていたら、
	すべてのセルをfalseにします。

	1.2,3.セルの選択状況が変更されていない場合は、
	全てのセルの選択状況を、m_ColumnNumberSelectLimit.getY().getPos() の
	選択状況と同じにします。

	1.3. m_eSelectMode が SelectMode_YColumn の場合、
	同じY列番号(横方向)のセルの選択状況をすべて同一にします。
	正規化の方法は、 SelectMode_XColumn と同様です。

	2.ColumnNumberSelectLimitによる、CSelectCell::m_bIsSelected の正規化。

	2.1.m_ColumnNumberSelectLimit 以外の領域が選択されていた場合は
	その選択を解除します。
	
	 @return 
		正規化の結果、何らかの値を変化させた場合は真です。
	 */
	bool update_adjustProp() ;

	/**
	CWndDcdGrid::update() の下請関数です。
	属性の変化を、画面上に反映します。

	CSelectCell::update_updateScreen() への委譲を行います。

	CSelectCell::update_updateScreen() は、m_bIsSelected が
	変更されたら、セルの領域を無効化し、更新を指示します。
		
	@return 
		何らかの値の変化を画面上に反映させた場合は真です。
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
	*/
	virtual bool OnPaint( IfDcdTarget* pIfDcdTarget ) ;

	/**
		CWndDcdGrid の同一メソッドの委譲を受けます。

		このクラスでは、処理はありません。
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

		処理はありません
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
	CSelect( CWndDcdGrid* pCWndDcdGrid ) ;
	virtual ~CSelect() ;
public:
	// ********************************
	///@name CSelect 関連
	// ********************************
	///@{
	CWndDcdGrid*	getCWndDcdGrid() ;
	Ou<IfDcDraw>	getIfDcDrawSelect() ;
	void setIfDcDrawSelect( Ou<IfDcDraw> value ) ;
	///@}


	// ********************************
	///@name CSelect 属性
	// ********************************
	///@{
	bool getIncludeRbBorder()const ;
	void setIncludeRbBorder( bool ev )  ;
	ESelectMode	getSelectMode()const ;
	void setSelectMode( ESelectMode	value ) ;
	CdDcdZoneXy	getColumnNumberSelectLimit()const ;
	void setColumnNumberSelectLimit( const CdDcdZoneXy& value ) ;

	/**
	@return
		選択可能制限範囲。単位はセル番号です。
		戻り値は、列数以内に正規化されます。
		(戻り値の
		CdDcdZoneXy::getX().getEndPos() は、
		CDcdGrid::getXColumnCount() 以下に正規化します。
	*/
	CdDcdZoneXy	getColumnNumberSelectLimitRegularized()const ;
 
	bool getUpdateCWndDcdGrid()const ;
	void setUpdateCWndDcdGrid( bool ev ) ;

	///@}
	// ********************************
	///@name CSelect 集約
	// ********************************
	///@{
	/**
	  	  指定されたY列・X列番号の、セルオブジェクト CSelectCell のポインタを
	  	取得することができます。このポインタを使って、セルに対する操作を
	  	行うことができます。
	   @param iXColumnNumber [in] 
	  	 X列番号を指定してください。範囲は、0以上 getXColumnCount() 未満です。
	   @param iYColumnNumber [in] 
	  	 Y列番号を指定してください。範囲は、0以上 getYColumnCount() 未満です。
	   @return
	  	  対応するセルオブジェクトを返します。
	  	  インデクスが不正な場合は、NULLを返します。
	  
	  	  返されたオブジェクトの破棄の責務は、thisにあります。
	  	  該当するX列が CDcdGrid の別のメソッドによって削除されると、返された
	  	ポインタは無効になります。
	  	   thisが破棄されたときにも、返されたポインタは無効になります。
	 */
	virtual CSelectCell*	getCell( int iXColumnNumber , int iYColumnNumber );
 

	/**
		指定の CSelectCell オブジェクトの、列番号を返します。
	@param pCSelectCell [in]
		CDcdGridCell オブジェクトを指定してください。
	@return
		X列番号を返します。
		オブジェクトが CDcdGrid オブジェクトに集約されていない場合は、
		INT_MIN です。
	*/
	virtual int getXColumnNumberOfCell( 
		CSelectCell* pCSelectCell ) ;
	/**
		指定の CSelectCell オブジェクトの、列番号を返します。
	@param pCSelectCell [in]
		CDcdGridCell オブジェクトを指定してください。
	@return
		Y列番号を返します。
		オブジェクトが CDcdGrid オブジェクトに集約されていない場合は、
		INT_MIN です。
	*/
	virtual int getYColumnNumberOfCell( 
		CSelectCell* pCSelectCell ) ;
	///@}
	// ********************************
	///@name CSelect 操作
	// ********************************
	///@{
	

	/**
	指定のセルの選択表示を行う範囲を、
	論理単位(通常はピクセル。クライアント座標)で返します。

	@param pIfDcdTarget [in]
		描画対象を指定してください。
	@param iXColumnNumber [in]
		セルの列番号を指定してください。
	@param iYColumnNumber [in]
		セルの列番号を指定してください。
	@param bIncludeRbBorder [in]
		true なら、範囲に、セルの右側、下側の罫線を含めます。
	@return 
		セルの選択表示の範囲を返します。
	@attention
		一番左・下の罫線(グリッド全体の左・下の罫線)は範囲に含めません。
	*/
	virtual CdDcdZoneXy getZoneOfCellSelection(
		IfDcdTarget* pIfDcdTarget , 
		int iXColumnNumber , int iYColumnNumber , bool bIncludeRbBorder ) ;

	/**
		全てのセルを選択します。
	*/
	virtual void selectAll() ;
	/**
		全てのセルの選択を解除します。
	*/
	virtual void clearSelect() ;

	/**
	@return 
		選択されているセルの数を返します。
	*/
	int getSelectedCellCount()const ;

	/**
	@return 
		m_eSelectMode が SelectMode_XColumn の場合、
		選択されている列の数を返します。

		m_eSelectMode が SelectMode_XColumn 以外の場合は0です。
	*/
	int getSelectedXColumnCount()const ;

	/**
	@return 
		m_eSelectMode が SelectMode_YColumn の場合、
		選択されている列の数を返します。

		m_eSelectMode が SelectMode_YColumn 以外の場合は0です。
	*/
	int getSelectedYColumnCount()const ;

	/**
	  m_eSelectMode が SelectMode_XColumn の場合、
	指定の列 Index の選択状態を取得します。

	@param iColumnNumber [in]
	  	 X列番号を指定してください。範囲は、0以上 getXColumnCount() 未満です。
	@return 
		列が選択されていれば true 。

		m_eSelectMode が SelectMode_XColumn 以外の場合、
		このメソッドは無効です。
	*/
	bool getXColumnNumberSelected( int iColumnNumber ) ;

	/**
	  m_eSelectMode が SelectMode_XColumn の場合、
	指定の列 Index の選択状態を設定します。
	  このメソッドにより、指定された列のセルの 
	CSelectCell::m_bIsSelected 属性が変わります

	@param iColumnNumber [in]
	  	 X列番号を指定してください。範囲は、0以上 getXColumnCount() 未満です。
	@param bIsSelected [in]
		選択する場合は true 、 選択解除する場合は false 。

		m_eSelectMode が SelectMode_XColumn 以外の場合、
		このメソッドは無効です。
	*/
	void setXColumnNumberSelected( int iColumnNumber , bool bIsSelected ) ;

	/**
	  m_eSelectMode が SelectMode_XColumn , SelectMode_YColumn の場合、
	指定の列 Index の選択状態を取得します。

	@param iColumnNumber [in]
	  	 Y列番号を指定してください。範囲は、0以上 getYColumnCount() 未満です。
	@return 
		列が選択されていれば true 。

		m_eSelectMode が SelectMode_YColumn 以外の場合、
		このメソッドは無効です。
	*/
	bool getYColumnNumberSelected( int iColumnNumber ) ;

	/**
	  m_eSelectMode が SelectMode_YColumn の場合、
	  指定の列 Index の選択状態を設定します。
	  このメソッドにより、指定された列のセルの 
	CSelectCell::m_bIsSelected 属性が変わります

	@param iColumnNumber [in]
	  	Y列番号を指定してください。範囲は、0以上 getYColumnCount() 未満です。
	@param bIsSelected [in]
		選択する場合は true 、 選択解除する場合は false 。

		m_eSelectMode が SelectMode_YColumn 以外の場合、
		このメソッドは無効です。
	*/
	void setYColumnNumberSelected( int iColumnNumber , bool bIsSelected ) ;

	///@}


};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif //DcDraw_DcdGrid_WndDcdGrid3_CSelect_h
