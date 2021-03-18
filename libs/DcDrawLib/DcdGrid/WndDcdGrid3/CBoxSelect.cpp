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
//	CBoxSelect.cpp
//	$Id: CBoxSelect.cpp 324 2016-06-12 03:03:55Z okm $
// ****************************************************************
*/
/** @file */
#include "DcdGrid\WndDcdGrid3\CBoxSelect.h"
#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CPropStack.h"
#include "DcdGrid\CDcdGridCell.h"
#include "logmsg\logmsg.h"
#include "NsOu\OuNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

	// --------------------------------
	///@name update_adjustProp 下請関数
	// --------------------------------
bool CBoxSelect::update_adjustProp_updateColumnNumberSelect() 
{
	bool bRv = false ;

	//	変更対象の値のキャッシュ
	CdDcdZoneXy	zonexyColumnNumberSelectNew = m_ColumnNumberSelect ;
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
	//□Shiftが押された状態で、ドラッグ以外によるフォーカス移動
	//	  →BoxSelect アンカーセルは更新せずに、
	//		アンカーセルとフォーカスセルの間を選択領域とする。
	//□ドラッグによるフォーカス移動(MouseMove,タイマスクロール)
	//	  →BoxSelect　アンカーセルは更新せずに、
	//		アンカーセルとフォーカスセルの間を選択領域とする。
	// --------------------------------
	if ( aColumnNumberFocus != CFocus::ColumnNumberPosXy_NULL() && 
		zonexyColumnNumberSelectLimit.IsInner( aColumnNumberFocus ) &&
		posxyColumnNumberAnchorCellNew != ColumnNumberPosXy_NULL() )
	{	//	フォーカスセルがNULL以外で選択可能領域。
		//	アンカーセルがNULL以外。
		bool bBoxSelecting = false ;
		if ( m_pCWndDcdGrid->isShiftPressed() && 
			!m_pCWndDcdGrid->isDragging() && 
			m_ColumnNumberFocus_Old != aColumnNumberFocus ) 
		{	//□Shiftが押された状態で、ドラッグ以外によるフォーカス移動
			//	  →BoxSelect アンカーセルは更新せずに、
			//		アンカーセルとフォーカスセルの間を選択領域とする。
			bBoxSelecting = true ;
		}
		else if ( m_pCWndDcdGrid->isDragging() && 
			m_ColumnNumberFocus_Old != aColumnNumberFocus ) 
		{	//□ドラッグによるフォーカス移動(MouseMove,タイマスクロール)
			//	  →BoxSelect　アンカーセルは更新せずに、
			//		アンカーセルとフォーカスセルの間を選択領域とする。
			bBoxSelecting = true ;
		}
		if ( bBoxSelecting )
		{

			//		アンカーセルとフォーカスセルの間を選択領域とする。
			//  　○[FocusCellが m_ColumnNumberSelectLimitの範囲内]

			//X
			{
				int iPosMin = min( aColumnNumberFocus.getX() , posxyColumnNumberAnchorCellNew.getX() ) ;
				int iPosMax = max( aColumnNumberFocus.getX() , posxyColumnNumberAnchorCellNew.getX() ) ;
				zonexyColumnNumberSelectNew.setX( CdDcdZone( iPosMin , iPosMax - iPosMin + 1 ) ) ;
			}
			//Y
			{
				int iPosMin = min( aColumnNumberFocus.getY() , posxyColumnNumberAnchorCellNew.getY() ) ;
				int iPosMax = max( aColumnNumberFocus.getY() , posxyColumnNumberAnchorCellNew.getY() ) ;
				zonexyColumnNumberSelectNew.setY( CdDcdZone( iPosMin , iPosMax - iPosMin + 1 ) ) ;
			}
			//bRvの更新は、この関数の末尾で行います。
		}
	}
	
	// --------------------------------
	//□CtrlもShiftも押されない状態で、ドラッグ(MouseMove,タイマスクロール)以外によるフォーカス移動
	//　→BoxSelect アンカーセルは更新。BoxSelect領域はNULL。
	//              すべてのセルの選択状態を解除
	// --------------------------------
	if ( m_ColumnNumberFocus_Old != aColumnNumberFocus )
	{
		//	CRandomSelect::update_adjustProp_updateColumnNumberSelect()と
		//	CBoxSelect::update_adjustProp_updateColumnNumberSelect() に
		//	同様の条件があります。
		if ( !m_pCWndDcdGrid->isCtrlPressed() && 
			!m_pCWndDcdGrid->isShiftPressed() && 
			!m_pCWndDcdGrid->isDragging() && 
			m_ColumnNumberFocus_Old != aColumnNumberFocus ) 
		{
			//□CtrlもShiftも押されない状態で、
			//ドラッグ(MouseMove,タイマスクロール)以外によるフォーカス移動

			//アンカーセルは更新。BoxSelect領域はNULL。
			posxyColumnNumberAnchorCellNew = aColumnNumberFocus ;
			zonexyColumnNumberSelectNew =  ColumnNumberZoneXy_NULL();

			// すべてのセルの選択状態を解除
			bClearSelectRequired = true ;

			//bRvの更新は、この関数の末尾で行います。
		}
	}
	// --------------------------------
	//□CtrlはON、ShiftはOFFで、ドラッグ以外によるフォーカス移動
	//　→BoxSelect アンカーセルは更新。BoxSelect領域はそのまま。
	// --------------------------------
	if ( aColumnNumberFocus != CFocus::ColumnNumberPosXy_NULL() && 
		zonexyColumnNumberSelectLimit.IsInner( aColumnNumberFocus ) )
	{	//	フォーカスセルがNULL以外で選択可能領域。
		//	アンカーセルがNULL以外。

		if ( m_pCWndDcdGrid->isCtrlPressed() && 
			!m_pCWndDcdGrid->isShiftPressed() && 
			!m_pCWndDcdGrid->isDragging() && 
			m_ColumnNumberFocus_Old != aColumnNumberFocus ) 
		{	//□CtrlもShiftも押されない状態で、
			//ドラッグ(MouseMove,タイマスクロール)以外によるフォーカス移動

			//アンカーセルは更新。BoxSelect領域はそのまま。
			posxyColumnNumberAnchorCellNew = aColumnNumberFocus ;
		}
	}

	// ----------------------------------------------------------------
	//	posxyColumnNumberAnchorCellNew・m_ColumnNumberSelect を正規化します。
	// ----------------------------------------------------------------
	// --------------------------------
	//	選択セルを、制限で補正
	// --------------------------------


	//	選択セルは、選択可能制限範囲内にする。
	//○[m_ColumnNumberSelect!=NULL]
	//　○m_ColumnNumberSelect は、 m_ColumnNumberSelectLimit の範囲内にする。
	//　○[SelectMode=SelectMode_XColumn]
	//     m_ColumnNumberSelect.Y = m_ColumnNumberSelectLimit.Y
	//　○[SelectMode=SelectMode_YColumn]
	//     m_ColumnNumberSelect.X = m_ColumnNumberSelectLimit.X
	if ( zonexyColumnNumberSelectNew != ColumnNumberZoneXy_NULL() ) 
	{
		//　○m_ColumnNumberSelect は、 m_ColumnNumberSelectLimit の範囲内にする。
		zonexyColumnNumberSelectNew = 
			zonexyColumnNumberSelectLimit.CrossZone( zonexyColumnNumberSelectNew ) ;


		//　○[SelectMode=SelectMode_XColumn]
		//     m_ColumnNumberSelect.Y = m_ColumnNumberSelectLimit.Y
		if ( pCSelect->getSelectMode() == CSelect::SelectMode_XColumn )
		{
			zonexyColumnNumberSelectNew.setY( zonexyColumnNumberSelectLimit.getY() ) ;
		}
		//　○[SelectMode=SelectMode_YColumn]
		//     m_ColumnNumberSelect.X = m_ColumnNumberSelectLimit.X
		if ( pCSelect->getSelectMode() == CSelect::SelectMode_YColumn )
		{
			zonexyColumnNumberSelectNew.setX( zonexyColumnNumberSelectLimit.getX() ) ;
		}

	}
	// ----------------------------------------------------------------
	//	属性の更新
	// ----------------------------------------------------------------
	if ( m_ColumnNumberSelect != zonexyColumnNumberSelectNew )
	{
		m_ColumnNumberSelect = zonexyColumnNumberSelectNew ;
		bRv = true ;
	}
	if ( m_ColumnNumberAnchorCell != posxyColumnNumberAnchorCellNew )
	{
		m_ColumnNumberAnchorCell = posxyColumnNumberAnchorCellNew ;
		bRv = true ;
	}
	if ( bClearSelectRequired ){	// すべてのセルの選択状態を解除
		m_pCWndDcdGrid->getCSelect()->clearSelect() ;
		bRv = true ;
	}
	// --------------------------------
	//	前回値の更新
	// --------------------------------
	m_ColumnNumberFocus_Old = aColumnNumberFocus ;
	// --------------------------------
	
	LogMsg( "CBoxSelect::update_adjustProp_updateColumnNumberSelect\n"
		"\tm_ColumnNumberSelect.x=(%d,%d) y=(%d,%d)\n" ,
		m_ColumnNumberSelect.getX().getPos() , 
		m_ColumnNumberSelect.getX().getSize() , 
		m_ColumnNumberSelect.getY().getPos() , 
		m_ColumnNumberSelect.getY().getSize() ) ; 

	return bRv ;	
}

bool CBoxSelect::update_adjustProp_updateCSelectCell()
{
	bool bRv = false ;
	
	CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	CSelect* pCSelect = m_pCWndDcdGrid->getCSelect() ;

	{
		Ou<CPropStack> pPropStack = createPropStackForSelectChange() ;

		// --------------------------------
		//	セルの選択状況の変化を
		//	CSelectCell に反映します
		// --------------------------------
		for ( int iYColumnNumber = 0 ; 
			iYColumnNumber < pCXDcdGrid->getYColumnCount() ; 
			iYColumnNumber ++ )
		{
			for ( int iXColumnNumber = 0 ; 
				iXColumnNumber < pCXDcdGrid->getXColumnCount() ; 
				iXColumnNumber ++ )
			{
				
				bool bSelected = m_ColumnNumberSelect.IsInner( 
					CdDcdPosXy( iXColumnNumber , iYColumnNumber ) ) ;
				bool bSelectedOld =  m_ColumnNumberSelect_Old.IsInner( 
					CdDcdPosXy( iXColumnNumber , iYColumnNumber ) ) ;

				if ( bSelectedOld != bSelected )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					pCSelectCell->setIsSelected( bSelected ) ;
					bRv = true ;
				}
			}
		}
	}
	return bRv ;
}

Ou<CPropStack> CBoxSelect::createPropStackForSelectChange() 
{
	OuNew<CPropStack> pPropStack( new CPropStack( getCWndDcdGrid() ) ) ;
	pPropStack->CSelect_setUpdateCWndDcdGrid( false ) ;
	return pPropStack ;

}



	// --------------------------------
	//@name CWndDcdGrid からの委譲
	// --------------------------------
bool CBoxSelect::update_adjustProp() 
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
		//	セル選択をクリアする
		m_ColumnNumberAnchorCell = ColumnNumberPosXy_NULL() ;
		m_ColumnNumberSelect = ColumnNumberZoneXy_NULL() ;
	}

	return bRv ;	
}
bool CBoxSelect::update_updateScreen() 
{
	//	このクラスでは処理はありません(再描画は、CSelect にて行われます)
	m_ColumnNumberSelect_Old = m_ColumnNumberSelect ;
	return false ;
}


bool CBoxSelect::OnPaint( IfDcdTarget* pIfDcdTarget ) 
{
	//	このクラスでは処理はありません(再描画は、CSelect にて行われます)
	return false ;
}

void CBoxSelect::InvalidateGrid( ) 
{
	//	このクラスでは処理はありません(再描画は、CSelect にて行われます)
}
void CBoxSelect::OnSize(UINT nType, int cx, int cy)
{
	//	このクラスでは、処理はありません。
}
void CBoxSelect::OnSetFocus(CWnd* pOldWnd)
{
	//	このクラスでは、処理はありません。
}

void CBoxSelect::OnKillFocus(CWnd* pNewWnd)
{
	//	このクラスでは、処理はありません。
}

	// ********************************
	//	コンストラクタ
	// ********************************
CBoxSelect::CBoxSelect( CWndDcdGrid* pCWndDcdGrid ) 
	: m_pCWndDcdGrid( pCWndDcdGrid ) 
	, m_bIsEnable( true ) 
	, m_ColumnNumberAnchorCell( ColumnNumberPosXy_NULL()  ) 
	, m_ColumnNumberSelect( ColumnNumberZoneXy_NULL() )
	, m_ColumnNumberFocus_Old( ColumnNumberPosXy_NULL() ) 
	, m_ColumnNumberSelect_Old( ColumnNumberZoneXy_NULL() )
{
}


CBoxSelect::~CBoxSelect() 
{
}
	// ********************************
	//@name CSelect 関連
	// ********************************
CWndDcdGrid* CBoxSelect::getCWndDcdGrid() 
{
	return m_pCWndDcdGrid ;
}

	// ********************************
	//@name CSelect 属性
	// ********************************
bool CBoxSelect::getIsEnable()
{
	return m_bIsEnable ;
}
void CBoxSelect::setIsEnable( bool value ) 
{
	m_bIsEnable = value ;
}
CdDcdPosXy	CBoxSelect::getColumnNumberAnchorCell()
{
	return m_ColumnNumberAnchorCell ;
}
CdDcdZoneXy	CBoxSelect::getColumnNumberSelect()const 
{
	return m_ColumnNumberSelect ;
}
void CBoxSelect::setColumnNumberSelect( const CdDcdZoneXy& value ) 
{
	m_ColumnNumberSelect = value ;
	m_pCWndDcdGrid->update() ;
}

	// ********************************
	//@name CSelect 集約
	// ********************************
	// ********************************
	//@name CSelect 操作
	// ********************************
void CBoxSelect::clearSelect() 
{
	m_ColumnNumberSelect = ColumnNumberZoneXy_NULL() ;
	m_pCWndDcdGrid->update() ;
}


} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib


