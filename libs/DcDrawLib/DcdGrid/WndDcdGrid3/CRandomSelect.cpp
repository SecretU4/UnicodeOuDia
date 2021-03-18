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
//	CRandomSelect.cpp
//	$Id: CRandomSelect.cpp 324 2016-06-12 03:03:55Z okm $
// ****************************************************************
*/
/** @file */

#include "DcdGrid\WndDcdGrid3\CRandomSelect.h"
#include "DcdGrid\WndDcdGrid3\CFocus.h"
#include "DcdGrid\WndDcdGrid3\CXDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

	// --------------------------------
	//@name 下請関数
	// --------------------------------
CSelectCell* CRandomSelect::getFocusSelectCell() 
{
	CSelectCell* pCell = NULL ;

	CdDcdPosXy	xyFocusCellColumnNumber =
		m_pCWndDcdGrid->getCFocus()->getFocusCellColumnNumber() ;
	if ( xyFocusCellColumnNumber != CFocus::ColumnNumberPosXy_NULL() )
	{
		pCell = m_pCWndDcdGrid->getCSelect()->getCell( 
			xyFocusCellColumnNumber.getX() ,
			xyFocusCellColumnNumber.getY() ) ;
	}
	return pCell ;
}

	// --------------------------------
	//@name update_adjustProp 下請関数
	// --------------------------------
bool CRandomSelect::update_adjustProp_updateColumnNumberSelect() 
{
	bool bRv = false ;

	//	変更対象の値のキャッシュ
	CdDcdPosXy posxyColumnNumberAnchorCellNew = m_ColumnNumberAnchorCell ;

	//	初期値はfalse。
	//	すべてのセルの選択状態を解除する必要があると判断された時点で true 。
	bool bClearSelectRequired = false ;

	CdDcdPosXy	aColumnNumberFocus = 
		m_pCWndDcdGrid->getCFocus()->getFocusCellColumnNumber() ;
	//aColumnNumberFocus = フォーカスセルの列番号

	// ----------------------------------------------------------------
	//	アンカーセルの正規化(アンカーセルがグリッドの範囲外なら、
	//	NULL に修正
	// ----------------------------------------------------------------
	if ( posxyColumnNumberAnchorCellNew != ColumnNumberPosXy_NULL() )
	{
		if ( !( 
			0 <= m_ColumnNumberAnchorCell.getX() && 
			m_ColumnNumberAnchorCell.getX() < m_pCWndDcdGrid->getCXDcdGrid()->getXColumnCount() &&
			0 <= m_ColumnNumberAnchorCell.getY() && 
			m_ColumnNumberAnchorCell.getY() < m_pCWndDcdGrid->getCXDcdGrid()->getYColumnCount() ) )
		{
			posxyColumnNumberAnchorCellNew = ColumnNumberPosXy_NULL() ;
		}
	}

	// ----------------------------------------------------------------
	//	フォーカスセルの移動に従って
	//	m_ColumnNumberSelect,m_ColumnNumberAnchorCell を更新します。
	// ----------------------------------------------------------------

	CSelect*	pCSelect = m_pCWndDcdGrid->getCSelect() ;
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		pCSelect->getColumnNumberSelectLimitRegularized() ;
	//zonexyColumnNumberSelectLimit = 選択可能なセルの列番号の範囲。

	// --------------------------------
	//□CtrlもShiftも押されない状態で、ドラッグ(MouseMove,タイマスクロール)以外によるフォーカス移動
	//　→ アンカーセルは更新。すべてのセルの選択状態を解除。
	// --------------------------------

	if ( m_ColumnNumberFocus_Old != aColumnNumberFocus )
	{	//	フォーカスセルが移動
		if ( !m_pCWndDcdGrid->isCtrlPressed() && 
			!m_pCWndDcdGrid->isShiftPressed() && 
			!m_pCWndDcdGrid->isDragging() )
		{	//□CtrlもShiftも押されない状態で、
			//	ドラッグ(MouseMove,タイマスクロール)以外によるフォーカス移動
			
			//アンカーセルは更新。
			posxyColumnNumberAnchorCellNew = aColumnNumberFocus ;

			// すべてのセルの選択状態を解除
			bClearSelectRequired = true ;
		}
		// --------------------------------
	}
	
	// --------------------------------
	//	□Ctrlが押された状態で、ドラッグ以外によるフォーカス移動
	//	　→アンカーセルの選択状態を選択にする。
	//	　　アンカーセルをNULLにする。(RandomSelectのアンカーセルは、
	//	　　RandomSelectによる初回の選択トグルが行われた後に、
	//	　　1回だけ選択状態にします。)
	// --------------------------------
	if ( m_ColumnNumberFocus_Old != aColumnNumberFocus )
	{	//	フォーカスセルが移動
		if ( m_pCWndDcdGrid->isCtrlPressed() && 
			!m_pCWndDcdGrid->isDragging() )
		{
				//	→アンカーセルの選択状態を選択にする。
				{
					CSelectCell* pCell = NULL ;
					if ( m_ColumnNumberAnchorCell != CFocus::ColumnNumberPosXy_NULL() )
					{
						pCell = m_pCWndDcdGrid->getCSelect()->getCell( 
							m_ColumnNumberAnchorCell.getX() ,
							m_ColumnNumberAnchorCell.getY() ) ;
						if ( pCell != NULL )
						{
							pCell->setIsSelected( true ) ;
						}
						m_ColumnNumberAnchorCell = CFocus::ColumnNumberPosXy_NULL() ;
					}
				}
		}
	}



	// ----------------------------------------------------------------
	//	属性の更新
	// ----------------------------------------------------------------
	if ( m_ColumnNumberAnchorCell != posxyColumnNumberAnchorCellNew )
	{
		m_ColumnNumberAnchorCell = posxyColumnNumberAnchorCellNew ;
		bRv = true ;
	}
	if ( bClearSelectRequired )		// すべてのセルの選択状態を解除
	{
		m_pCWndDcdGrid->getCSelect()->clearSelect() ;
		bRv = true ;
	}

	// --------------------------------
	//	前回値を更新
	// --------------------------------
	m_ColumnNumberFocus_Old = aColumnNumberFocus ;

	return bRv ;	
}

bool CRandomSelect::update_adjustProp_updateCSelectCell() 
{
	//	セル選択状態の更新は、 OnLButtonDown(),OnKeyDown() で行うため、
	//	ここでは処理はありません。
	return false ;
}

	// --------------------------------
	//@name CWndDcdGrid からの委譲
	// --------------------------------
bool CRandomSelect::update_adjustProp() 
{
	bool	bRv = false ;
	if ( m_bIsEnable )
	{
		//	フォーカスセルの移動に従って、
		//	m_ColumnNumberAnchorCell , m_ColumnNumberSelect を更新します。
		//	
		//	m_ColumnNumberAnchorCell・m_ColumnNumberSelect を正規化します。
		bRv |= update_adjustProp_updateColumnNumberSelect() ;

		//	選択セルの状態を、CSelectCell に反映する
		bRv |= update_adjustProp_updateCSelectCell() ;
	}
	else
	{
		m_ColumnNumberAnchorCell = ColumnNumberPosXy_NULL() ;
	}

	return bRv ;	
}

bool CRandomSelect::update_updateScreen() 
{
	bool bRv = false ;
	//	このクラスでは処理はありません(再描画は、CSelect にて行われます)
	return bRv ;
}
bool CRandomSelect::OnPaint( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;
	//	このクラスでは処理はありません(再描画は、CSelect にて行われます)
	return bRv ;
}

void CRandomSelect::OnSize(UINT nType, int cx, int cy)
{
	//	このクラスでは処理はありません
}

void CRandomSelect::OnSetFocus(CWnd* pOldWnd)
{
	//	このクラスでは、処理はありません。
}

void CRandomSelect::OnKillFocus(CWnd* pNewWnd)
{
	//	このクラスでは、処理はありません。
}




void CRandomSelect::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//	CWndDcdGrid の同一メソッドの委譲を受けます。

	//□Ctrl+グリッド上でのマウスクリック@n
	//	　→アンカーセルの選択状態を選択にする。
	//	　→ フォーカスセルの選択状態をトグルする
	if ( m_bIsEnable )	//	ランダム選択が有効
	{
		CdDcdPosXy	posCursorPos( point.x , point.y ) ;
		CDcdGridCell* pCell = 
			m_pCWndDcdGrid->getCellOfPos( posCursorPos ) ;
		if ( pCell != NULL )
		{
			//	マウスがセル上にある状態でクリック
			if ( m_pCWndDcdGrid->isCtrlPressed() )	//	Ctrl押し下げ
			{
				//	Ctrl+グリッド上でのマウスクリック

				//	→ フォーカスセルの選択状態をトグルする
				{
					CSelectCell* pCSelectCell = getFocusSelectCell() ;
					if ( pCSelectCell != NULL )
					{
						pCSelectCell->setIsSelected( 
							!pCSelectCell->getIsSelected() ) ;
					}
				}

				//	→アンカーセルの選択状態を選択にする。
				//note:
				//	この処理は、「フォーカスセルの選択状態をトグルする」よりも後に
				//	行う必要があります。
				//	順序が逆の場合は、
				//		ランダムセル選択のない状態で、Ctrl+Spaceを押す
				//		ランダムセル選択のない状態で、Ctrlを押しながらフォーカスセルをクリック
				//	のいずれかを実行したときに、フォーカスセルが非選択状態になります。
				{
					CSelectCell* pCell = NULL ;
					if ( m_ColumnNumberAnchorCell != CFocus::ColumnNumberPosXy_NULL() )
					{
						pCell = m_pCWndDcdGrid->getCSelect()->getCell( 
							m_ColumnNumberAnchorCell.getX() ,
							m_ColumnNumberAnchorCell.getY() ) ;
						m_ColumnNumberAnchorCell = CFocus::ColumnNumberPosXy_NULL() ;
						pCell->setIsSelected( true ) ;
					}
				}

			}
		}
	}
	
}


void CRandomSelect::OnLButtonUp(UINT nFlags, CPoint point) 
{
	//	CWndDcdGrid の同一メソッドの委譲を受けます。
	//
	//	このクラスでは、処理はありません。
}

void CRandomSelect::OnMouseMove(UINT nFlags, CPoint point) 
{
	//	CWndDcdGrid の同一メソッドの委譲を受けます。
	//
	//	このクラスでは、処理はありません。
}

void CRandomSelect::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	//	CWndDcdGrid の同一メソッドの委譲を受けます。
	//
	//□Ctrl+Spaceキー@n
	//　→フォーカスセルの選択状態をトグルする
	if ( m_bIsEnable )	//	ランダム選択が有効
	{
		if ( m_pCWndDcdGrid->isCtrlPressed() && 
			nChar == VK_SPACE )
		{
				//	Ctrl+Spaceキー
				
				//	→ フォーカスセルの選択状態をトグルする
				{
					CSelectCell* pCSelectCell = getFocusSelectCell() ;
					if ( pCSelectCell != NULL )
					{
						pCSelectCell->setIsSelected( 
							!pCSelectCell->getIsSelected() ) ;
					}
				}
				//	→アンカーセルの選択状態を選択にする。
				//note:
				//	この処理は、「フォーカスセルの選択状態をトグルする」よりも後に
				//	行う必要があります。
				//	順序が逆の場合は、
				//		ランダムセル選択のない状態で、Ctrl+Spaceを押す
				//		ランダムセル選択のない状態で、Ctrlを押しながらフォーカスセルをクリック
				//	のいずれかを実行したときに、フォーカスセルが非選択状態になります。
				{
					CSelectCell* pCell = NULL ;
					if ( m_ColumnNumberAnchorCell != CFocus::ColumnNumberPosXy_NULL() )
					{
						pCell = m_pCWndDcdGrid->getCSelect()->getCell( 
							m_ColumnNumberAnchorCell.getX() ,
							m_ColumnNumberAnchorCell.getY() ) ;
						m_ColumnNumberAnchorCell = CFocus::ColumnNumberPosXy_NULL() ;
						pCell->setIsSelected( true ) ;
					}
				}

		}
	}
}

void CRandomSelect::InvalidateGrid( ) 
{
	//	このクラスでは処理はありません(再描画は、CSelect にて行われます)
}

	// ********************************
	//	コンストラクタ
	// ********************************
CRandomSelect::CRandomSelect( CWndDcdGrid* pCWndDcdGrid ) 
	: m_pCWndDcdGrid( pCWndDcdGrid )
	, m_bIsEnable( true ) 
	, m_ColumnNumberFocus_Old( ColumnNumberPosXy_NULL() ) 
{
}
CRandomSelect::~CRandomSelect() 
{
}

	// ********************************
	//@name CSelect 関連
	// ********************************
CWndDcdGrid* CRandomSelect::getCWndDcdGrid() 
{
	return m_pCWndDcdGrid ;
}

	// ********************************
	//@name CSelect 属性
	// ********************************
bool CRandomSelect::getIsEnable() 
{
	return m_bIsEnable ;
}
void CRandomSelect::setIsEnable( bool value ) 
{
	m_bIsEnable = value ;
}
CdDcdPosXy	CRandomSelect::getColumnNumberAnchorCell()
{
	return m_ColumnNumberAnchorCell;
}


} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib
