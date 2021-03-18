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
//	CSelect.cpp
//$Id: CSelect.cpp 324 2016-06-12 03:03:55Z okm $
// ****************************************************************
*/
/** @file */
#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CPropStack.h"
#include "DcdGrid\WndDcdGrid3\CXDcdGrid_ZoneCacheTemp.h"

#include "NsOu\OuNew.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CDcdFillrectRop.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "LogMsg\LogMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

// ----------------------------------------------------------------
//	WndDcdGrid3::CSelect
// ----------------------------------------------------------------
	// --------------------------------
	//@name 下請関数
	// --------------------------------

int CSelect::insertYColumn_insertColumnCell( int iYColumnNumber ) 
{
	int iRv = 0 ;

	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iRv >= 0 ){
		if ( iYColumnNumber == INT_MAX ){
			iYColumnNumber = pCDcdGrid->getYColumnCount() ;
		}
		if ( !( 0 <= iYColumnNumber && iYColumnNumber <= pCDcdGrid->getYColumnCount() ) ){
			iRv = -2 ;	//	インデクスが不正です	
		}
	}
	if ( iRv >= 0 ){
		//	Cellオブジェクト
		m_CSelectCellCont.insert( 
			m_CSelectCellCont.begin() + iYColumnNumber ,
			new CSelectYColumnCellCont ) ;
		int iXColumnNumber ;
		for ( iXColumnNumber = 0 ; 
				iXColumnNumber < pCDcdGrid->getXColumnCount() ; 
				iXColumnNumber ++ ){
			CSelectCell*	pCSelectCell = new CSelectCell( this , m_CSelectCellCont[ iYColumnNumber ] ) ;
			
			m_CSelectCellCont[ iYColumnNumber ]->push_back( pCSelectCell );
		}
		
	}
	return ( iRv ) ;
}

int CSelect::insertXColumn_insertColumnCell( int iXColumnNumber ) 
{
	int	iRv = 0 ;
	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iRv >= 0 ){
		if ( iXColumnNumber == INT_MAX ){
			iXColumnNumber = pCDcdGrid->getXColumnCount() ;
		}
		if ( !( 0 <= iXColumnNumber && 
				iXColumnNumber <= pCDcdGrid->getXColumnCount() ) ){
			iRv = -2 ;	//	インデクスが不正です	
		}
	}
	if ( iRv >= 0 ){
		int iYColumnNumber ;
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < pCDcdGrid->getYColumnCount() ; 
				iYColumnNumber ++ ){
			CSelectCell*	pCSelectCell = new CSelectCell( this , m_CSelectCellCont[iYColumnNumber] ) ;
			m_CSelectCellCont[iYColumnNumber]->insert( 
				m_CSelectCellCont[iYColumnNumber]->begin() + iXColumnNumber ,
				pCSelectCell ) ;
			
		}
	}
	return ( iRv ) ;
}
	
int CSelect::eraseYColumn_eraseColumnCell( int iYColumnNumber ) 
{
	int iRv = 0 ;
	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iRv >= 0 ){
		if ( iYColumnNumber == INT_MAX ){
			iYColumnNumber = pCDcdGrid->getYColumnCount() - 1 ;
		}
		if ( !( 0 <= iYColumnNumber && 
				iYColumnNumber < pCDcdGrid->getYColumnCount() ) ){
			iRv = -2 ;	//	インデクスが不正です	
		}
	}
	if ( iRv >= 0 ){
		int iXColumnNumber ;
		for ( iXColumnNumber = pCDcdGrid->getXColumnCount() - 1  ; 
				iXColumnNumber >= 0  ; 
				iXColumnNumber -- ){
			CSelectCell*	pCSelectCell = 
				m_CSelectCellCont[ iYColumnNumber ]->back();
			
			m_CSelectCellCont[ iYColumnNumber ]->pop_back();
			
			delete pCSelectCell ;
			pCSelectCell = NULL ;
		}
		CSelectYColumnCellCont* pCSelectYColumnCellCont = m_CSelectCellCont[iYColumnNumber] ;
		delete pCSelectYColumnCellCont ;
		pCSelectYColumnCellCont = NULL ;

		m_CSelectCellCont.erase( 
			m_CSelectCellCont.begin() + iYColumnNumber ) ;
	}
	return ( iRv ) ;
}

int CSelect::eraseXColumn_eraseColumnCell( int iXColumnNumber ) 
{
	int iRv = 0 ;
	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iRv >= 0 ){
		if ( iXColumnNumber == INT_MAX ){
			iXColumnNumber = pCDcdGrid->getXColumnCount() - 1 ;
		}
		if ( !( 0 <= iXColumnNumber && 
				iXColumnNumber < pCDcdGrid->getXColumnCount() ) ){
			iRv = -2 ;	//	インデクスが不正です	
		}
	}
	if ( iRv >= 0 ){
		int iYColumnNumber ;
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < pCDcdGrid->getYColumnCount() ; 
				iYColumnNumber ++ ){
			CSelectCell*	pCSelectCell = 
				(*m_CSelectCellCont[iYColumnNumber])[iXColumnNumber] ;

			m_CSelectCellCont[iYColumnNumber]->erase( 
				m_CSelectCellCont[iYColumnNumber]->begin() + iXColumnNumber ) ;
			
			delete pCSelectCell ;
			pCSelectCell = NULL ;
		}
	}
	return ( iRv ) ;
}

Ou<CPropStack> CSelect::createPropStackForSelectChange() 
{
	OuNew<CPropStack> pPropStack( new CPropStack( getCWndDcdGrid() ) ) ;
	pPropStack->CSelect_setUpdateCWndDcdGrid( false ) ;
	return pPropStack ;

}

	// --------------------------------
	//@name CWndDcdGrid::CDcdGrid からの委譲
	// --------------------------------
void CSelect::OnCreateXColumn( int iXColumnNumber )
{
	insertXColumn_insertColumnCell( iXColumnNumber ) ;
}	
		
void CSelect::OnDeleteXColumn( int iXColumnNumber ) 
{
	eraseXColumn_eraseColumnCell( iXColumnNumber ) ;
}

void CSelect::OnCreateYColumn( int iYColumnNumber ) 
{
	insertYColumn_insertColumnCell( iYColumnNumber ) ;
}
void CSelect::OnDeleteYColumn( int iYColumnNumber ) 
{
	eraseYColumn_eraseColumnCell( iYColumnNumber ) ;
}

	// --------------------------------
	//@name CWndDcdGrid からの委譲
	// --------------------------------
bool CSelect::update_adjustProp() 
{
	bool bRv = false ;

	LogMsg( "CSelect::update_adjustProp() " ) ;

	if ( m_eSelectMode_Prev == SelectMode_NONE
		&& m_eSelectMode == SelectMode_NONE )
	{
		//	m_eSelectMode が SelectMode_NONE である間は、
		//	update_adjustProp()・update_updateScreen()・OnPaint()は
		//	何もせずにリターンします。
	}	
	else
	{
		CSelect* pCSelect = m_pCWndDcdGrid->getCSelect() ;
		CdDcdZoneXy	zonexyColumnNumberLimit = 
			pCSelect->getColumnNumberSelectLimitRegularized() ;
		//zonexyColumnNumberLimit = セル選択可能範囲

		//	セル選択変更時の描画を最適化します。
		Ou<CPropStack> pPropStack = createPropStackForSelectChange() ;

		// --------------------------------
		//	X列モード・Y列モードによる、CSelectCell::m_bIsSelected の正規化。
		// --------------------------------
		//1.1.m_eSelectMode が SelectMode_NONE の場合、
		//すべてのセルを非選択にします。
		if ( m_pCWndDcdGrid->getCSelect()->getSelectMode() 
			== CSelect::SelectMode_NONE )
		{
			//	すべてのセルの選択を解除します。
			clearSelect() ;
		}
		//	  1.2. m_eSelectMode が SelectMode_XColumn の場合、
		//		同じX列番号(縦方向)のセルの選択状況をすべて同一にします。
		//
		else if ( m_pCWndDcdGrid->getCSelect()->getSelectMode() 
			== CSelect::SelectMode_XColumn )
		{

			for ( int iXColumnNumber = zonexyColumnNumberLimit.getX().getPos() ;
				iXColumnNumber < zonexyColumnNumberLimit.getX().getEndPos() ;
				iXColumnNumber ++ )
			{
				//	セル選択状況が確定したら true です。
				bool bColumnSelectIsFixed = false ;
				bool bColumnSelect = false ;

				//		1.2.1.いずれかのセルの CSelectCell::m_bIsSelected がtrueに
				//		変更されていたら、
				//		すべてのセルをtrueにします。
				//
				//		1.2.2.いずれかのセルの CSelectCell::m_bIsSelected が
				//		falseに変更されていたら、
				//		すべてのセルをfalseにします。
				for ( int iYColumnNumber = zonexyColumnNumberLimit.getY().getPos() ;
					!bColumnSelectIsFixed && 
						iYColumnNumber < zonexyColumnNumberLimit.getY().getEndPos() ;
					iYColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					if ( pCSelectCell->getIsSelected_Prev() != 
						pCSelectCell->getIsSelected() )
					{
						//	セルの選択状況が変更されています。
						//	その列のすべてのセルの選択状況を確定します。
						bColumnSelectIsFixed = true ;
						bColumnSelect = pCSelectCell->getIsSelected() ;
					}
				}
				//		1.2.3.セルの選択状況が変更されていない場合は、
				//		全てのセルの選択状況を、m_ColumnNumberSelectLimit.getY().getPos() の
				//		選択状況と同じにします。
				//		
				if ( !bColumnSelectIsFixed )	//	セルの選択状況が変更されていない
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , zonexyColumnNumberLimit.getY().getPos() ) ;
					if ( pCSelectCell != NULL )	//	Y列数が0の場合は、pCSelectCellはNULLになります。
					{
						bColumnSelectIsFixed = true ;
						bColumnSelect = pCSelectCell->getIsSelected() ;
					}
				}

				for ( int iYColumnNumber = zonexyColumnNumberLimit.getY().getPos() ;
						iYColumnNumber < zonexyColumnNumberLimit.getY().getEndPos() ;
					iYColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					if ( pCSelectCell->getIsSelected() != bColumnSelect )
					{
						pCSelectCell->setIsSelected( bColumnSelect ) ;
						bRv = true ;
					}
				}
			}
		}
		//	1.3.m_eSelectMode が SelectMode_YColumn の場合、
		//	同じY列番号(横方向)のセルの選択状況をすべて同一にします。
		else if ( m_pCWndDcdGrid->getCSelect()->getSelectMode() 
			== CSelect::SelectMode_YColumn )
		{
			for ( int iYColumnNumber = zonexyColumnNumberLimit.getY().getPos() ;
				iYColumnNumber < zonexyColumnNumberLimit.getY().getEndPos() ;
				iYColumnNumber ++ )
			{
				//	セル選択状況が確定したら true です。
				bool bColumnSelectIsFixed = false ;
				bool bColumnSelect = false ;

				//		1.1.いずれかのセルの CSelectCell::m_bIsSelected がtrueに
				//		変更されていたら、
				//		すべてのセルをtrueにします。
				//
				//		1.2.いずれかのセルの CSelectCell::m_bIsSelected がfalseに変更されていたら、
				//		すべてのセルをfalseにします。
				for ( int iXColumnNumber = zonexyColumnNumberLimit.getX().getPos() ;
					!bColumnSelectIsFixed && 
						iXColumnNumber < zonexyColumnNumberLimit.getX().getEndPos() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					if ( pCSelectCell->getIsSelected_Prev() != 
						pCSelectCell->getIsSelected() )
					{
						//	セルの選択状況が変更されています。
						//	その列のすべてのセルの選択状況を確定します。
						bColumnSelectIsFixed = true ;
						bColumnSelect = pCSelectCell->getIsSelected() ;
					}
				}
				//		1.3.セルの選択状況が変更されていない場合は、
				//		全てのセルの選択状況を、m_ColumnNumberSelectLimit.getY().getPos() の
				//		選択状況と同じにします。
				//		
				if ( !bColumnSelectIsFixed )	//	セルの選択状況が変更されていない
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						zonexyColumnNumberLimit.getX().getPos() , iYColumnNumber ) ;
					if ( pCSelectCell != NULL )	//	X列数が0の場合は、pCSelectCellはNULLになります。
					{
						bColumnSelectIsFixed = true ;
						bColumnSelect = pCSelectCell->getIsSelected() ;
					}
				}

				for ( int iXColumnNumber = zonexyColumnNumberLimit.getX().getPos() ;
						iXColumnNumber < zonexyColumnNumberLimit.getX().getEndPos() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					if ( pCSelectCell->getIsSelected() != bColumnSelect )
					{
						pCSelectCell->setIsSelected( bColumnSelect ) ;
						bRv = true ;
					}
				}
			}
		}
			
		// --------------------------------
		//	ColumnNumberSelectLimitによる、CSelectCell::m_bIsSelected の正規化。
		// --------------------------------
		//	  2. m_ColumnNumberSelectLimit 以外の領域が選択されていた場合は
		//	    その選択を解除します。
		{
			CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

			for ( int iYColumnNumber = 0 ;
				iYColumnNumber < pCXDcdGrid->getYColumnCount() ;
				iYColumnNumber ++ )
			{
				for ( int iXColumnNumber = 0 ;
						iXColumnNumber < pCXDcdGrid->getXColumnCount() ;
					iXColumnNumber ++ )
				{
					if ( !zonexyColumnNumberLimit.IsInner( 
						CdDcdPosXy( iXColumnNumber , iYColumnNumber ) ) )
					{
						//	m_ColumnNumberSelectLimit 以外の領域です。
						//	このセルは、すべて選択解除にします。
						CSelectCell* pCSelectCell = pCSelect->getCell( 
							iXColumnNumber , iYColumnNumber ) ;
						if ( pCSelectCell->getIsSelected() )
						{
							pCSelectCell->setIsSelected( false ) ;
							bRv = true ;
						}
					}
				}
			}
		}
		// --------------------------------
		//	m_iSelectedCellCount の更新
		// --------------------------------
		{
			m_iSelectedCellCount = 0 ;
			for ( int iYColumnNumber = 0 ; 
				iYColumnNumber < (int)m_CSelectCellCont.size() ; 
				iYColumnNumber ++ )
			{
				CSelectYColumnCellCont* pCSelectYColumnCellCont = 
					m_CSelectCellCont[iYColumnNumber] ;
				for ( int iXColumnNumber = 0 ; 
					iXColumnNumber < (int)pCSelectYColumnCellCont->size() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelectYColumnCellCont->at( iXColumnNumber ) ;
					if ( pCSelectCell->getIsSelected() )
					{
						m_iSelectedCellCount ++ ;
					}
				}
			}

		}
		// --------------------------------
		//	CSelectCell に委譲
		// --------------------------------
		{
			for ( int iYColumnNumber = 0 ; 
				iYColumnNumber < (int)m_CSelectCellCont.size() ; 
				iYColumnNumber ++ )
			{
				CSelectYColumnCellCont* pCSelectYColumnCellCont = 
					m_CSelectCellCont[iYColumnNumber] ;
				for ( int iXColumnNumber = 0 ; 
					iXColumnNumber < (int)pCSelectYColumnCellCont->size() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelectYColumnCellCont->at( iXColumnNumber ) ;
					bRv |= pCSelectCell->update_adjustProp() ;
				}
			}
		}

	}

	LogMsg( "CSelect::update_adjustProp()=%d ",bRv  ) ;

	return bRv ;
}

bool CSelect::update_updateScreen() 
{
	bool bRv = false ;


	if ( m_eSelectMode_Prev == SelectMode_NONE
		&& m_eSelectMode == SelectMode_NONE )
	{
		//	m_eSelectMode が SelectMode_NONE である間は、
		//	update_adjustProp()・update_updateScreen()・OnPaint()は
		//	何もせずにリターンします。
	}	
	else
	{
		//	ZoneCache を生成
		//	(CSelect::getZoneOfCellSelection()による
		//	サイズ取得が早くなります)

		CDcdTargetGetDC	aTarget( getCWndDcdGrid()->GetSafeHwnd() ) ;
		CXDcdGrid_ZoneCacheTemp aZoneCacheTemp( 
				getCWndDcdGrid()->getCXDcdGrid() , 
				&aTarget ) ;

		// --------------------------------
		//	CSelectCell に委譲
		// --------------------------------
		{
			CDcdTargetGetDC	aTarget( m_pCWndDcdGrid->GetSafeHwnd() ) ;

			for ( int iYColumnNumber = 0 ; 
				iYColumnNumber < (int)m_CSelectCellCont.size() ; 
				iYColumnNumber ++ )
			{
				CSelectYColumnCellCont* pCSelectYColumnCellCont = 
					m_CSelectCellCont[iYColumnNumber] ;
				for ( int iXColumnNumber = 0 ; 
					iXColumnNumber < (int)pCSelectYColumnCellCont->size() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelectYColumnCellCont->at( iXColumnNumber ) ;
					bRv |= pCSelectCell->update_updateScreen( &aTarget ) ;
				}
			}
		}
	}
	// --------------------------------
	//	前回値を更新
	// --------------------------------
	m_eSelectMode_Prev = m_eSelectMode ;

	// --------------------------------
	return bRv ;
}

bool CSelect::OnPaint( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;
	LogMsg( "CSelect::OnPaint()" ) ; 

	if ( m_eSelectMode == SelectMode_NONE )
	{
		//	m_eSelectMode が SelectMode_NONE である間は、
		//	update_adjustProp()・update_updateScreen()・OnPaint()は
		//	何もせずにリターンします。
	}	
	else
	{
		//	ZoneCache を生成
		//	(CSelect::getZoneOfCellSelection()による
		//	サイズ取得が早くなります)
		CXDcdGrid_ZoneCacheTemp	aZoneCacheTemp( 
			m_pCWndDcdGrid->getCXDcdGrid() , 
			pIfDcdTarget ) ;

		// --------------------------------
		//	CSelectCell が選択状態なら描画
		// --------------------------------
		{
			CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
			
			for ( int iYColumnNumber = 0 ; 
				iYColumnNumber < (int)m_CSelectCellCont.size() ; 
				iYColumnNumber ++ )
			{
				CSelectYColumnCellCont* pCSelectYColumnCellCont = 
					m_CSelectCellCont[iYColumnNumber] ;
				for ( int iXColumnNumber = 0 ; 
					iXColumnNumber < (int)pCSelectYColumnCellCont->size() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelectYColumnCellCont->at( iXColumnNumber ) ;
					if ( pCSelectCell->getIsSelected() )
					{
						CdDcdZoneXy	zoneCell = getZoneOfCellSelection(
							pIfDcdTarget , 
							iXColumnNumber , iYColumnNumber , m_bIncludeRbBorder ) ;

						if ( !( zoneCell.getX().getSize() > 0 && 
								zoneCell.getY().getSize() > 0 ) ){
							//	セルのサイズが０の場合は、
							//	後続の処理は行いません
							continue ;
						}

						CaDcdTargetItemPosition	aCDcdTargetItemPosition( 
							pIfDcdTarget ,
							zoneCell ) ;
						
						if ( aCDcdTargetItemPosition.isDrawable() )
						{
							m_pIfDcDrawSelect->DcDraw( &aCDcdTargetItemPosition ) ;
							
							bRv = true ;
						}

					}
				}
			}
		}
	}
	LogMsg( "CSelect::OnPaint()=" ) ; 

	return bRv ;
}


void CSelect::OnSize(UINT nType, int cx, int cy)
{
	if ( cx == 0 || cy == 0 ){
		//	この２つのうちのいずれかが0の場合、それは
		//	Create() でサイズを指定せずにウインドウを
		//	生成したものと思われます。
		//	この場合は、ユーザーには何も見えないわけですから、
		//	フォーカスセルの位置の最適化などはおこなう
		//	必要がありません。
		//
		//	また、この大きさのときに adjustProp() を
		//	行うと、フォーカス位置は無条件に (0,0) に
		//	移動してしまいます。このため、
		//	adjustProp() はしない方が
		//	よいでしょう。
		return ;
	}

}

void CSelect::OnSetFocus(CWnd* pOldWnd)
{
}

void CSelect::OnKillFocus(CWnd* pNewWnd)
{
}

void CSelect::InvalidateGrid( ) 
{
	//	このクラスの画面描画はすべてOnPaintで行われます。
	//	InvalidateGridでは、特別な処理は不要です。

}


	// ********************************
	//	コンストラクタ
	// ********************************
CSelect::CSelect( CWndDcdGrid* pCWndDcdGrid ) 
	: m_pCWndDcdGrid( pCWndDcdGrid )
	, m_bIncludeRbBorder( true ) 
	, m_eSelectMode( SelectMode_NONE ) 
	, m_ColumnNumberSelectLimit( CdDcdZone( 0 , INT_MAX ) , CdDcdZone( 0 , INT_MAX ) )
	, m_bUpdateCWndDcdGrid( true ) 
	, m_eSelectMode_Prev( SelectMode_NONE ) 
	, m_iSelectedCellCount( 0 ) 
{
	m_pIfDcDrawSelect = OuNew<CDcdFillrectRop>( new CDcdFillrectRop( 
		CdBrushProp( CdColorProp( 0 , 0 , 0 ) , CdBrushProp::SOLID ) ,
		R2_NOTXORPEN 
		) ) ;
	
}

CSelect::~CSelect() 
{
	//	CSelectCell オブジェクトを破棄します。
	while( m_CSelectCellCont.size() > 0 )
	{
		CSelectYColumnCellCont* pCSelectYColumnCellCont = m_CSelectCellCont.back() ;
		while( pCSelectYColumnCellCont->size() > 0 )
		{
			CSelectCell* pCSelectCell = pCSelectYColumnCellCont->back() ;
			delete pCSelectCell ;	pCSelectCell = NULL ;
			pCSelectYColumnCellCont->pop_back() ;
		}
		delete pCSelectYColumnCellCont ; pCSelectYColumnCellCont = NULL ;
		m_CSelectCellCont.pop_back() ;
	}
}

// ********************************
//@name 関連
// ********************************
CWndDcdGrid*	CSelect::getCWndDcdGrid()
{
	return m_pCWndDcdGrid ;
}
Ou<IfDcDraw>	CSelect::getIfDcDrawSelect() 
{
	return m_pIfDcDrawSelect ;
}
void CSelect::setIfDcDrawSelect( Ou<IfDcDraw> value ) 
{
	m_pIfDcDrawSelect = value ;
}



	// ********************************
	//@name 属性
	// ********************************	
bool CSelect::getIncludeRbBorder()const 
{
	return m_bIncludeRbBorder ;
}
void CSelect::setIncludeRbBorder( bool ev )  
{
	m_bIncludeRbBorder = ev ;
}
CSelect::ESelectMode	CSelect::getSelectMode()const 
{
	return m_eSelectMode ;
}
void CSelect::setSelectMode( ESelectMode	value ) 
{
	m_eSelectMode = value ;
	m_pCWndDcdGrid->update() ;
}

CdDcdZoneXy	CSelect::getColumnNumberSelectLimit()const 
{
	return m_ColumnNumberSelectLimit ;
}
void CSelect::setColumnNumberSelectLimit( const CdDcdZoneXy& value ) 
{
	m_ColumnNumberSelectLimit = value ;
	m_pCWndDcdGrid->update() ;
}

CdDcdZoneXy	CSelect::getColumnNumberSelectLimitRegularized()const 
{
	CdDcdZoneXy	zonexyRv = m_ColumnNumberSelectLimit ;
	CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	//	X列
	{
		CdDcdZone	aZone = zonexyRv.getX() ;
		if ( aZone.getEndPos() > pCXDcdGrid->getXColumnCount() )
		{
			aZone.setEndPos( pCXDcdGrid->getXColumnCount() ) ;
			zonexyRv.setX( aZone ) ;
		}
	}
	//	Y列
	{
		CdDcdZone	aZone = zonexyRv.getY() ;
		if ( aZone.getEndPos() > pCXDcdGrid->getYColumnCount() )
		{
			aZone.setEndPos( pCXDcdGrid->getYColumnCount() ) ;
			zonexyRv.setY( aZone ) ;
		}
	}
	return zonexyRv ;
}

bool CSelect::getUpdateCWndDcdGrid()const 
{
	return m_bUpdateCWndDcdGrid ;
}

void CSelect::setUpdateCWndDcdGrid( bool ev ) 
{
	if ( m_bUpdateCWndDcdGrid != ev )
	{
		//　属性を false から true に変更した場合は、CWndDcdGrid 全体を更新します。
		if ( ev )
		{
			m_pCWndDcdGrid->update() ;
		}
		m_bUpdateCWndDcdGrid = ev ;
	}
}



	// ********************************
	//@name CWndDcdGrid::CSelect 集約
	// ********************************
CSelectCell* 
CSelect::getCell( int iXColumnNumber , int iYColumnNumber )
{
	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iXColumnNumber == INT_MAX ){
		iXColumnNumber = pCDcdGrid->getXColumnCount() - 1 ;
	}
	if ( iYColumnNumber == INT_MAX ){
		iYColumnNumber = pCDcdGrid->getYColumnCount() - 1 ;
	}
	if ( 0 <= iXColumnNumber && iXColumnNumber < pCDcdGrid->getXColumnCount() && 
		0 <= iYColumnNumber && iYColumnNumber < pCDcdGrid->getYColumnCount() ){
		return ( (*m_CSelectCellCont[iYColumnNumber])[iXColumnNumber] ) ;
	}
	return ( NULL ) ;
}


int CSelect::getXColumnNumberOfCell( 
		CSelectCell* pCSelectCell ) 
{
	int iXColumnNumber = INT_MIN ;
	// --------------------------------
	if ( pCSelectCell != NULL )
	{
		for ( int idx = 0 ; 
				iXColumnNumber == INT_MIN && idx < (int)pCSelectCell->m_pCont->size() ; 
				idx ++ )
		{
			if ( pCSelectCell->m_pCont->at(idx) == pCSelectCell )
			{
				iXColumnNumber = idx ;
			}
		}
		
	}
	return iXColumnNumber ;
}
int CSelect::getYColumnNumberOfCell( 
	CSelectCell* pCSelectCell ) 
{
	int iYColumnNumber = INT_MIN ;
	// --------------------------------
	if ( pCSelectCell != NULL )
	{
		for ( int idx = 0 ; 
				iYColumnNumber == INT_MIN && idx < (int)m_CSelectCellCont.size() ; 
				idx ++ )
		{
			if ( m_CSelectCellCont[idx] == pCSelectCell->m_pCont )
			{
				iYColumnNumber = idx ;
			}
		}
		
	}
	// --------------------------------
	return iYColumnNumber ;
}

	// ********************************
	//@name CSelect 操作
	// ********************************

CdDcdZoneXy CSelect::getZoneOfCellSelection(
	IfDcdTarget* pIfDcdTarget , 
	int iXColumnNumber , int iYColumnNumber , bool bIncludeRbBorder ) 
{
	CdDcdZoneXy	aZoneXy ;
	CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	CDcdGridCell* pCell = pCXDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;

	if ( pCell->getAttachTo() == NULL )	//	結合セルではない
	{
		aZoneXy = pCXDcdGrid->getCellZone( pIfDcdTarget , iXColumnNumber , iYColumnNumber ) ;
		
		//X方向の(左の)罫線
		{

			if ( bIncludeRbBorder && 
				iXColumnNumber + pCell->getXAttachCellCount() < pCXDcdGrid->getXColumnCount() )
			{
				//	範囲に罫線を含める(グリッド全体の罫線は除く)
				CdDcdZone	zoneCurrent = aZoneXy.getX() ;

				CdDcdZone	zoneBorder = pCXDcdGrid->getXColumnBorderZone( 
					pIfDcdTarget , 
					iXColumnNumber + pCell->getXAttachCellCount() - 1 ) ;

				zoneCurrent.setEndPos( zoneBorder.getEndPos() ) ;
				aZoneXy.setX( zoneCurrent ) ;
			}
		}
		//Y方向の(下の)罫線
		{
			if ( bIncludeRbBorder && 
				iYColumnNumber + pCell->getYAttachCellCount() < pCXDcdGrid->getYColumnCount() )
			{
				//	範囲に罫線を含める(グリッド全体の罫線は除く)
				CdDcdZone	zoneCurrent = aZoneXy.getY() ;

				CdDcdZone	zoneBorder = pCXDcdGrid->getYColumnBorderZone( 
					pIfDcdTarget , 
					iYColumnNumber + pCell->getYAttachCellCount() - 1 ) ;

				zoneCurrent.setEndPos( zoneBorder.getEndPos() ) ;
				aZoneXy.setY( zoneCurrent ) ;
			}
		}
	}
	return aZoneXy ;

}

void CSelect::selectAll() 
{
	{
		//	セル選択変更時の描画を最適化します。
		Ou<CPropStack> pPropStack = createPropStackForSelectChange() ;


		CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
		CSelect* pCSelect = m_pCWndDcdGrid->getCSelect() ;
		CdDcdZoneXy	zonexyColumnNumberSelectLimit = pCSelect->getColumnNumberSelectLimitRegularized() ;

		for ( int iYColumnNumber = zonexyColumnNumberSelectLimit.getY().getPos() ;
			iYColumnNumber < zonexyColumnNumberSelectLimit.getY().getEndPos()  ;
			iYColumnNumber ++ )
		{
			for ( int iXColumnNumber = zonexyColumnNumberSelectLimit.getX().getPos() ;
				iXColumnNumber < zonexyColumnNumberSelectLimit.getX().getEndPos() ;
				iXColumnNumber ++ )
			{
				//	m_ColumnNumberSelectLimit 以内の領域です。
				//	このセルは、すべて選択します。
				CSelectCell* pCSelectCell = pCSelect->getCell( 
					iXColumnNumber , iYColumnNumber ) ;
				pCSelectCell->setIsSelected( true ) ;
			}
		}
	}
}

void  CSelect::clearSelect() 
{
	{
		//	セル選択変更時の描画を最適化します。
		Ou<CPropStack> pPropStack = createPropStackForSelectChange() ;



		CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
		CSelect* pCSelect = m_pCWndDcdGrid->getCSelect() ;

		for ( int iYColumnNumber = 0 ;
			iYColumnNumber < pCXDcdGrid->getYColumnCount() ;
			iYColumnNumber ++ )
		{
			for ( int iXColumnNumber = 0 ;
					iXColumnNumber < pCXDcdGrid->getXColumnCount() ;
				iXColumnNumber ++ )
			{
				//	すべてのセルを選択解除にします。
				CSelectCell* pCSelectCell = pCSelect->getCell( 
					iXColumnNumber , iYColumnNumber ) ;
				pCSelectCell->setIsSelected( false ) ;
			}
		}
	}
}

int CSelect::getSelectedCellCount()const 
{
	return m_iSelectedCellCount ;
}

int CSelect::getSelectedXColumnCount()const 
{
	int iRv = 0 ;
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_XColumn && 
		zonexyColumnNumberSelectLimit.getX().getSize() > 0 )
	{
		iRv = m_iSelectedCellCount 
			/ zonexyColumnNumberSelectLimit.getY().getSize() ;
	}
	return iRv ;
}

int CSelect::getSelectedYColumnCount()const 
{
	int iRv = 0 ;
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_YColumn && 
		zonexyColumnNumberSelectLimit.getY().getSize() > 0 )
	{
		iRv = m_iSelectedCellCount 
			/ zonexyColumnNumberSelectLimit.getX().getSize() ;
	}
	return iRv ;
}

bool CSelect::getXColumnNumberSelected( int iColumnNumber ) 
{
	bool bRv = false ;
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_XColumn  )
	{
		CSelectCell* pCell = getCell( iColumnNumber , 
			zonexyColumnNumberSelectLimit.getY().getPos() );
		if ( pCell != NULL )
		{
			bRv = pCell->getIsSelected() ;
		}
	}
	return bRv ;
}

void CSelect::setXColumnNumberSelected( int iColumnNumber , bool bIsSelected ) 
{
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_XColumn  )
	{
		CSelectCell* pCell = getCell( iColumnNumber , 
			zonexyColumnNumberSelectLimit.getY().getPos() );
		if ( pCell != NULL )
		{
			pCell->setIsSelected( bIsSelected ) ;
		}
	}
}


bool CSelect::getYColumnNumberSelected( int iColumnNumber ) 
{
	bool bRv = false ;

	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_YColumn  )
	{
		CSelectCell* pCell = getCell(  
			zonexyColumnNumberSelectLimit.getX().getPos() ,
			iColumnNumber );
		if ( pCell != NULL )
		{
			bRv = pCell->getIsSelected() ;
		}
	}
	return bRv ;
	
}



void CSelect::setYColumnNumberSelected( int iColumnNumber , bool bIsSelected ) 
{
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_YColumn  )
	{
		CSelectCell* pCell = getCell(  
			zonexyColumnNumberSelectLimit.getX().getPos() ,
			iColumnNumber );
		if ( pCell != NULL )
		{
			pCell->setIsSelected( bIsSelected ) ;
		}
	}
}



} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib
