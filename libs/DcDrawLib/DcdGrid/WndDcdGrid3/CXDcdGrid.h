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
//	CXDcdGrid.h
//	$Id: CXDcdGrid.h 387 2016-11-20 08:43:33Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdGrid_WndDcdGrid3_CXDcdGrid_h
#define  DcDraw_DcdGrid_WndDcdGrid3_CXDcdGrid_h

#include "DcdGrid\CDcdGrid.h"
#include "WinUtil\CdScrollbarProp.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

// ****************************************************************
//	WndDcdGrid3::CXDcdGrid
// ****************************************************************
/**
@brief
	CWndDcdGrid に包含される、CDcdGrid です。
	
	このクラスは、 CWndDcdGrid  が内部的に生成するために存在します。
	それ以外の利用価値はありません。
	this は、CDcdGrid のオーバライド可能な仮想関数呼び出しを、
	外側の CWndDcdGrid に委譲します。
 */
class CXDcdGrid : public CDcdGrid
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
	@brief　CWndDcdGrid全体の更新の有効/無効

	  スクロール位置の変更時に CWndDcdGrid 全体を更新するか否かを指定します。

	- true: (デフォルト)スクロール位置の変更時に、CWndDcdGrid 全体を更新します( CWndDcdGrid::update())を呼び出し)。
	- false: スクロール位置の変更時にも、 CWndDcdGrid 全体の更新は行いません。

	属性を false から true に変更した場合は、CWndDcdGrid 全体を更新します。

	「スクロール位置の変更時」は、以下のメソッド呼び出しのことを指します。

	- WndDcdGrid3::CXDcdGrid::setXFixafterColumnNumber() , 
	- WndDcdGrid3::CXDcdGrid::setYFixafterColumnNumber(),
	- WndDcdGrid3::CXDcdGrid::setXFixColumnCount(),
	- WndDcdGrid3::CXDcdGrid::setYFixColumnCount() 
	*/
	bool m_bUpdateCWndDcdGrid ;
	///@}
private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/** 
		現在のスクロールバーの属性を保存します。
		初期値は NULLです。
	
		この値は、 update_updateDisplay() 時に、前回値比較を行うのに使います。
		m_CFocus.m_iPos は、m_iXFixafterColumnNumber の前回値となります。

		また、OnPaint() でも、値を更新します。
	
		InvalidateGrid() では、属性を初期値に戻します。
	*/
	WinUtil::CdScrollbarProp	m_CdScrollbarPropX_Sid ;
	/** 
		現在のスクロールバーの属性を保存します。
		初期値は NULLです。
	
		この値は、 update_updateDisplay() 時に、前回値比較を行うのに使います。
		m_CFocus.m_iPos は、m_iXFixafterColumnNumber の前回値となります。

		また、OnPaint() でも、値を更新します。
	
		InvalidateGrid() では、属性を初期値に戻します。
	*/
	WinUtil::CdScrollbarProp	m_CdScrollbarPropY_Sid ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CXDcdGrid( CWndDcdGrid* pCWndDcdGrid ) ;
	virtual ~CXDcdGrid() ;
	// ****************************************************************
	//	CDcdGrid
	// ****************************************************************
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
		外側の、 CWndDcdGrid ( m_pCWndDcdGrid )へ委譲します。
		CWndDcdGrid::OnCreateXColumn() を呼び出します。
	 */
	virtual void OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) ;
	
	/**
	this は、Column が破棄される直前に、この関数を呼び出します。
	破棄される Column に対して、
	 IfDcDraw インターフェースオブジェクトの	
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
		外側の、 CWndDcdGrid ( m_pCWndDcdGrid )へ委譲します。
		CWndDcdGrid::OnDeleteXColumn() を呼び出します。
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
		外側の、 CWndDcdGrid ( m_pCWndDcdGrid )へ委譲します。
		CWndDcdGrid::OnCreateYColumn() を呼び出します。
	 */
	virtual void OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;
	
	/**
	this は、Column が破棄される直前に、この関数を呼び出します。
	破棄される Column に対して、 IfDcDraw インターフェース
	オブジェクトの	
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
		外側の、 CWndDcdGrid ( m_pCWndDcdGrid )へ委譲します。
		CWndDcdGrid::OnDeleteYColumn() を呼び出します。
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
		外側の、 CWndDcdGrid ( m_pCWndDcdGrid )へ委譲します。
		CWndDcdGrid::OnCreateCell() を呼び出します。
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
		外側の、 CWndDcdGrid ( m_pCWndDcdGrid )へ委譲します。
		CWndDcdGrid::OnDeleteCell() を呼び出します。
	 */
	virtual void OnDeleteCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) ;
	///@}
public:
	// ********************************
	///	@name CDcdGrid-Y列・X列の数
	// ********************************
	///@{
	/**
	 @return
		現在のY列の数を返します。初期状態では、０を返します。
	 */
	virtual int		getYColumnCount() ;
	
	/**
	 @param ev [in]
		Y列の数を指定してください。
	 */
	virtual CDcdGrid& setYColumnCount( int ev ) ;
	
	/**
	 @return
		現在のX列の数を返します。初期状態では、０を返します。
	 */
	virtual int		getXColumnCount() ;

	/**
	 @param ev [in]
		X列の数を指定してください。
	 */
	virtual CDcdGrid& setXColumnCount( int ev ) ;

	///@}
public:
	// ********************************
	///	@name CDcdGrid-Y列・X列を挿入/削除
	// ********************************
	///@{
	/**
	  Y列を１つ、指定の位置に追加します。
	 @param iYColumnNumber
		Y列番号を指定してください。
		新しく追加されたY列が、このY列番号になります。
		範囲は 0 以上 getYColumnNumber() 以下で、
		0 なら先頭・getYColumnNumber() なら末尾への追加となります。
		  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	 @param bFixafterColumnNumberChange [in]
		- false	・・・  [FocurCellColumnNumber 変更]  フォーカスセルを、
		ウインドウ内に
		移動します。
		- true ・・・ 	[FixafterColumnNumber 変更]  フォーカスセルが
		ウインドウ上に
		表示されるように、 FixafterColumnNumber を変更します。
	 @return
		成功したら0以上、エラーなら負の数です。
	 -	-2 ;	//	インデクスが不正
	 */
	virtual int insertYColumn( int iYColumnNumber ,
		bool bFixafterColumnNumberChange ) ;

	/**
	  X列を１つ、指定の位置に追加します。
	 @param iXColumnNumber
		X列番号を指定してください。
		新しく追加されたX列が、このX列番号になります。
		範囲は 0 以上 getXColumnNumber() 以下で、
		0 なら先頭・getXColumnNumber() なら末尾への追加となります。
		  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	 @param bFixafterColumnNumberChange [in]
		- false	・・・  [FocurCellColumnNumber 変更]  フォーカスセルを、
		ウインドウ内に
		移動します。
		- true ・・・ 	[FixafterColumnNumber 変更]  フォーカスセルが
		ウインドウ上に
		表示されるように、 FixafterColumnNumber を変更します。
	 @return
		成功したら0以上、エラーなら負の数です。
	 -	-2 ;	//	インデクスが不正
	 */
	virtual int insertXColumn( int iXColumnNumber , 
		bool bFixafterColumnNumberChange ) ;
	
	/**
	  Y列を１つ、削除します。
	 @param iYColumnNumber
		Y列番号を指定してください。
		範囲は 0 以上 getYColumnNumber() 未満です。
		  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	 @return
		成功したら0以上、エラーなら負の数です。
	 -	-2 ;	//	インデクスが不正
	 */
	virtual int eraseYColumn( int iYColumnNumber ) ;
	/**
	  X列を１つ、削除します。
	 @param iXColumnNumber
		X列番号を指定してください。
		範囲は 0 以上 getXColumnNumber() 未満です。
		  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	 @return
		成功したら0以上、エラーなら負の数です。
	 -	-2 ;	//	インデクスが不正
	 */
	virtual int eraseXColumn( int iXColumnNumber ) ;
	///@}
	
public:
	// ********************************
	///	@name	CDcdGrid-スクロール
	// ********************************
	///@{
	virtual int	getXFixColumnCount() ;
	/**
	　スクロール位置の変更時には、CWndDcdGrid 全体を更新します
	 ( CWndDcdGrid::update())を呼び出し)。
	*/
	virtual CDcdGrid& setXFixColumnCount( int ev ) ;
	virtual int	getXFixafterColumnNumber() ;
	/**
	　スクロール位置の変更時には、CWndDcdGrid 全体を更新します
	 ( CWndDcdGrid::update())を呼び出し)。
	*/
	virtual CDcdGrid& setXFixafterColumnNumber( int ev ) ;
	virtual int	getYFixColumnCount() ;
	/**
	　スクロール位置の変更時には、CWndDcdGrid 全体を更新します
	 ( CWndDcdGrid::update())を呼び出し)。
	*/
	virtual CDcdGrid& setYFixColumnCount( int ev ) ;
	virtual int	getYFixafterColumnNumber() ;
	/**
	　スクロール位置の変更時には、CWndDcdGrid 全体を更新します
	 ( CWndDcdGrid::update())を呼び出し)。
	*/
	virtual CDcdGrid& setYFixafterColumnNumber( int ev ) ;
	///@}

	// ****************************************************************
	//	WndDcdGrid3::CXDcdGrid
	// ****************************************************************
protected:
	// ********************************
	///@name CWndDcdGrid からの 操作
	// ********************************
	///@{
	/**
	  属性の妥当性を検証し、値を補正します。
	@return
		何らかの属性の更新を行ったら true 。
	*/
	bool update_adjustProp() ;
	/**
	  属性をもとに、画面を更新します。
	@return
		何らかの画面更新を行ったら true 。
	*/
	bool update_updateScreen() ;

	/**
	  CWndDcdGrid の同一メソッドの委譲を受けます。

	  ウインドウ全域を無効化し、再描画を要求します。
	  このとき、スクロールバーの属性の再設定・
	フォーカスセルの正規化も行います。
	
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
public:
	// ********************************
	///@name WndDcdGrid3::CXDcdGrid 関連
	// ********************************
	///@{
	CWndDcdGrid*	getCWndDcdGrid() {
		return m_pCWndDcdGrid ; } ;
	///@}

	// ********************************
	///@name WndDcdGrid3::CXDcdGrid 属性
	// ********************************
	///@{
	bool getUpdateCWndDcdGrid()const ;
	void setUpdateCWndDcdGrid( bool value ) ;
	///@}

protected:
	// ================================
	///@name CXDcdGrid_ZoneCacheTemp に、createZoneCacheを公開
	// ================================
	friend class CXDcdGrid_ZoneCacheTemp ;
	bool createZoneCache( IfDcdTarget* pIfDcdTarger );
	void destroyZoneCache();
};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif /*DcDraw_DcdGrid_WndDcdGrid3_CXDcdGrid_h*/
