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
//	CDcdGridCell.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdGridCell_h
#define  CDcdGridCell_h
#include <deque>


#include "DcDraw/IfDcDraw.h"
#include "NsOu/Ou.h"

namespace DcDrawLib{
namespace DcdGrid{
	using namespace OuLib::NsOu;
	using namespace DcDraw;

// ****************************************************************
//	CDcdGridCell
// ****************************************************************
/**
 @brief
 【概要】
	DcdGrid のセルオブジェクトです。

	IfDcDraw オブジェクトと関連を持ち､ その IfDcDraw オブジェクトを使って
	セルの中身を描画します。

	CDcdGrid は、通常は CDcdTextbox オブジェクトを生成して、
	this と関連する IfDcDraw オブジェクトとして登録します｡

 */
class CDcdGridCell
{
	friend class CDcdGrid ;

	typedef	std::deque< CDcdGridCell* > CDcdGridYColumnCellCont ;
private:
	// ********************************
	/// @name 	CDcdGrid に関係する属性/関連
	// ********************************
	///@{
	/**
		このオブジェクトを保持するグリッドオブジェクトへのポインタです。
		コンストラクタで決まります。
		破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、thisよりも長く生存しなくてはなりません。

		この関連は、	m_iYAttachCellCount , m_iXAttachCellCount が変更された時に
		他のすべてのセルの属性を更新するのに使います。
	*/
	CDcdGrid*	m_pCDcdGrid ;
	/**
		このオブジェクトを集約しているコンテナです。
		このコンテナには、同じY列にある CDcdGridCell オブジェクトが格納されています。

		この関連は、CDcdGrid が、getColumnNumberOfCell() を行う時に参照します。
		コンストラクタで決まります。
	*/
	CDcdGridYColumnCellCont* m_pCont ;

	/**
		通常はNULLです。
		このセルが結合セルの一番左上以外に位置している場合は、
		このセルが結合している最も左上にあるものを指します。
		この関連は、 CDcdGrid が設定します。
	 */
	CDcdGridCell*	m_pcellAttachTo ;

	///@}
 private:
	// ********************************
	/// @name CDcdGridCell 固有の関連
	// ********************************
	///@{
	
	/**
		this に対する現在の描画オブジェクトを指すポインタです。
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、この関連が有効な間は生存しなくてはなりません。
	
		通常は、 CDcdGrid::OnCreateCell() がインスタンスを生成・登録し、
		 CDcdGrid::OnDeleteCell() がインスタンスを登録解除・破棄します。
		
		デフォルトの  CDcdGrid::OnCreateCell() の実装は、
		CDcdTextbox インスタンスを生成・登録します。
		このときの属性は、
	
			- フォントはストックオブジェクトの DEFAULT_GUI_FONT 
			- テキスト配置は 
				CdDrawTextFormat::H_LEFT | 
				CdDrawTextFormat::V_SINGLELINT_CENTER
			- 背景色は 白
			- テキストの上下・左右の枠領域の太さは論理単位で１
	
		となります。
	 */
	Ou<IfDcDraw>			m_pIfDcDraw ;
	
	///@}
private:
	// ********************************
	/// @name CDcdGridCell 固有の属性
	// ********************************
	///@{
	/**
		このセルがY方向に結合しているセルの数。
	
		- このセルが結合セルの左上のセルの場合は、
		結合しているセルのY方向の数です。
		- このセルが単独のセルの場合は1。
		- このセルが結合セルの左上以外であれば、この値は意味を持ちません。
	
		初期値は1。メソッドで変更できます。
	 */
	int	m_iYAttachCellCount ;

	/**
		このセルがX方向に結合しているセルの数。
	
		- このセルが結合セルの左上のセルの場合は、
		結合しているセルのX方向の数です。
		- このセルが単独のセルの場合は1。
		- このセルが結合セルの左上以外であれば、この値は意味を持ちません。
	
		初期値は1。メソッドで変更できます。
	 */
	int	m_iXAttachCellCount ;


	///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 @param [in] pCDcdGrid 
		このオブジェクトを保持するグリッドオブジェクトへのポインタです。
	 @param [in] pCDcdGridYColumnCellCont 
		CDcdGrid において、このオブジェクトを集約するコンテナへのポインタです。
	 */
	CDcdGridCell( CDcdGrid*	pCDcdGrid , 
		CDcdGridYColumnCellCont* pCDcdGridYColumnCellCont  ) ;
	
 private:
	CDcdGridCell( const CDcdGridCell& ev ){} ;
	void operator=( CDcdGridCell& ev ) {};

// ********************************
//	CDcdGridCell
// ********************************
public:
	// ********************************
	/// @name 	CDcdGrid に関係する属性/関連
	// ********************************
	///@{
	CDcdGrid*	getCDcdGrid() ;


	/**
		通常はNULLです。
		このセルが結合セルの一番左上以外に位置している場合は、
		このセルが結合している最も左上にあるものを指します。
		この関連は、 CDcdGrid が設定します。
	 */
	virtual CDcdGridCell*	getAttachTo() ;

	///@}
	// ********************************
	/// @name 	包含/属性
	// ********************************
	///@{
	///@}

	// ********************************
	/// @name	CDcdGridCell 固有の関連
	// ********************************
	///@{
	virtual Ou<IfDcDraw> getIfDcDraw() ;
	virtual void setIfDcDraw( Ou<IfDcDraw> value ) ;


	///@}
	// ********************************
	/// @name CDcdGridCell 固有の属性
	// ********************************
	///@{

	///@see m_iYAttachCellCount
	virtual int	getYAttachCellCount() ;
	
	///@see m_iXAttachCellCount
	virtual int	getXAttachCellCount() ;

	/**
		結合セルの数を設定します。
		結合の左上に位置するセルに、この値を設定してください。
	
		ただし、セルの数がグリッドの範囲を越えている場合は、正規化を
		行います。
	 @param iXAttachCellCount [in]
		X方向に結合するセルの数を指定してください。
	 @param iYAttachCellCount [in]
		Y方向に結合するセルの数を指定してください。
	 @return
		成功すれば０以上、エラーなら負の数です。
		-	0 ;	//	結合セルの数に変更はありません。
		-	1 ;	//	結合セルの数が変更されました。
		-	-1 ;	//	値の範囲が不正です
	 */
	int	setAttachCellCount( 
		int iXAttachCellCount , 
		int iYAttachCellCount ) ;


	///@}
};

} //namespace DcdGrid
} //namespace DcDrawLib

#endif /*CDcdGridCell_h*/
