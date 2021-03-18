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
//	WndDcdGrid_CFocus.cpp
// ****************************************************************
*/
/** @file */
#include "CWndDcdGrid.h"

#include "NsOu\OuNew.h"
#include "DcDraw\CDcdRectangle.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CaDcdTargetItemPosition.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

// ****************************************************************
//	WndDcdGrid3::CFocus
// ****************************************************************
	// --------------------------------
	//@name	CWndDcdGrid-フォーカス
	// --------------------------------
void CFocus::CreateDcDrawFocusCell() 
{
	OuNew<CDcdRectangle>	pCDcdRectangle( new CDcdRectangle( 
				CdPenProp( 1 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::DOT ) ) ) ;
	setIfDcDrawFocusCell( pCDcdRectangle ) ;
}
void CFocus::DeleteDcDrawFocusCell() 
{
	setIfDcDrawFocusCell( Ou<IfDcDraw>() ) ;
}


// --------------------------------
//@name CWndDcdGrid からの委譲
// --------------------------------
bool CFocus::update_adjustProp() 
{
	bool bRv = false ;

	CXDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	CDcdTargetGetDC	aCDcdTarget( m_pCWndDcdGrid->GetSafeHwnd() ) ;

	int	iFocusCellXColumnNumber = m_iFocusCellXColumnNumber ;
	int iFocusCellYColumnNumber = m_iFocusCellYColumnNumber ;
	int iXFixafterColumnNumber = m_pCDcdGrid->getXFixafterColumnNumber() ;
	int iYFixafterColumnNumber = m_pCDcdGrid->getYFixafterColumnNumber() ;

	// --------------------------------
	//	【1.属性の補正】
	// --------------------------------

	//  １．FocusCell が被結合セルになった場合・・・FocusCellは
	//	結合セルに移動します。
	{
		CDcdGridCell*	pCell = m_pCDcdGrid->getCell( 
			iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ;
		if ( pCell != NULL ){
			if ( pCell->getAttachTo() != NULL ){
				pCell = pCell->getAttachTo() ;
				iFocusCellXColumnNumber = m_pCDcdGrid->getXColumnNumberOfCell( pCell ) ;
				iFocusCellYColumnNumber = m_pCDcdGrid->getYColumnNumberOfCell( pCell ) ;

			}
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 0" ) ;

	//	２．FocusCellColumnNumber が ウインドウの範囲
	//	（IfDcdTarget::getZone()の領域)に収まっていない場合・・・
	//	[FixafterColumnNumber 変更]
	//	FocusCellColumnNumber を、画面上の一番右下の ColumnNumber にします。
	//	[FocusCellColumnNumber 変更]
	//	FocusCellColumnNumber がウインドウの範囲に収まるまで、
	//	FixafterColumnNumberを加算します。
	//	この結果となる FixafterColumnNumber を、
	//	 FixafterColumnNumberMaxForColumn と呼びます。
	{
		int iColumnNumberMaxInDcdTarget = 
				m_pCDcdGrid->getXColumnNumberMaxInDcdTarget( &aCDcdTarget ) ;
		if ( iFocusCellXColumnNumber > iColumnNumberMaxInDcdTarget ){
			//LogMsg( "CWndDcdGrid::adjustProp() 01" ) ;
			if ( !m_bFixafterColumnNumberChange ){
				iFocusCellXColumnNumber = m_pCDcdGrid->
					getXColumnNumberMaxInDcdTarget( &aCDcdTarget )  ;
				if ( iFocusCellXColumnNumber < 0 ){
					iFocusCellXColumnNumber = 0 ;
				}
			}	else	{
				int iXFixafterColumnNumberMinForColumn = m_pCDcdGrid->
					calcXFixafterColumnNumberMinForColumn( &aCDcdTarget , 
						iFocusCellXColumnNumber ) ;

				iXFixafterColumnNumber = iXFixafterColumnNumberMinForColumn ;

				//bRvの更新は、この関数の末尾で行います。
			}
			//LogMsg( "CWndDcdGrid::adjustProp() 02" ) ;
		}
	}
	{
		int iColumnNumberMaxInDcdTarget = 
				m_pCDcdGrid->getYColumnNumberMaxInDcdTarget( &aCDcdTarget ) ;
		if ( iFocusCellYColumnNumber > iColumnNumberMaxInDcdTarget ){
			//LogMsg( "CWndDcdGrid::adjustProp() 03" ) ;
			if ( !m_bFixafterColumnNumberChange ){
				iFocusCellYColumnNumber = m_pCDcdGrid->
					getYColumnNumberMaxInDcdTarget( &aCDcdTarget )  ;
				if ( iFocusCellYColumnNumber < 0 ){
					iFocusCellYColumnNumber = 0 ;
				}
			}	else	{
				int iYFixafterColumnNumberMinForColumn = m_pCDcdGrid->
					calcYFixafterColumnNumberMinForColumn( &aCDcdTarget , 
						iFocusCellYColumnNumber ) ;

				iYFixafterColumnNumber = iYFixafterColumnNumberMinForColumn ;

				//bRvの更新は、この関数の末尾で行います。
			}
			//LogMsg( "CWndDcdGrid::adjustProp() 04" ) ;
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 1" ) ;


	//	３． FocusCellColumnNumber が ColumnScrollout になった場合・・・
	//	[FixafterColumnNumber 変更]
	//	FocusCellColumnNumber を FixafterColumnNumber と同じにします。
	//	[FocurCellColumnNumber 変更]
	//	スクロール位置を正規化して、フォーカスセルが表示されるようにします。
	//	FixafterColumnNumberを、FocusCellのColumnNumberと同じにします。
	{
		if ( m_pCDcdGrid->getXFixColumnCount() <= iFocusCellXColumnNumber && 
				iFocusCellXColumnNumber < iXFixafterColumnNumber ){
			
			if ( !m_bFixafterColumnNumberChange ){
				iFocusCellXColumnNumber = iXFixafterColumnNumber ;
			}	else	{
				iXFixafterColumnNumber = iFocusCellXColumnNumber ;
				//bRvの更新は、この関数の末尾で行います。
			}
		}
		if ( m_pCDcdGrid->getYFixColumnCount() <= iFocusCellYColumnNumber && 
				iFocusCellYColumnNumber < iYFixafterColumnNumber ){
			
			if ( !m_bFixafterColumnNumberChange ){
				iFocusCellYColumnNumber = iYFixafterColumnNumber ;
			}	else	{
				iYFixafterColumnNumber =  iFocusCellYColumnNumber ;
				//bRvの更新は、この関数の末尾で行います。
			}
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 2" ) ;

	//  ４．FocusCell が0以上 ColumnCount未満でない場合・・・FocusCellは
	//	内側の値にします。
	{
		if ( iFocusCellXColumnNumber >= m_pCDcdGrid->getXColumnCount() ){
			iFocusCellXColumnNumber = m_pCDcdGrid->getXColumnCount() - 1 ;
		}
		if ( iFocusCellXColumnNumber < 0 ){
			iFocusCellXColumnNumber = 0 ;
		}
		if ( iFocusCellYColumnNumber >= m_pCDcdGrid->getYColumnCount() ){
			iFocusCellYColumnNumber = m_pCDcdGrid->getYColumnCount() - 1 ;
		}
		if ( iFocusCellYColumnNumber < 0 ){
			iFocusCellYColumnNumber = 0 ;
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 3" ) ;

	//  ５．FocusCell が被結合セルになった場合・・・FocusCellは
	//	結合セルに移動します。
	{
		CDcdGridCell*	pCell = m_pCDcdGrid->getCell( 
			iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ;
		if ( pCell != NULL ){
			if ( pCell->getAttachTo() != NULL ){
				pCell = pCell->getAttachTo() ;
				iFocusCellXColumnNumber = m_pCDcdGrid->getXColumnNumberOfCell( pCell ) ;
				iFocusCellYColumnNumber = m_pCDcdGrid->getYColumnNumberOfCell( pCell ) ;
			}
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 4" ) ;
	//LogMsg( "CWndDcdGrid::adjustProp() =" ) ;

	// ----------------------------------------------------------------
	//	【2.属性の変化をCWndDcdGridに通知】
	// ----------------------------------------------------------------
	if ( m_iFocusCellXColumnNumber != iFocusCellXColumnNumber || 
		m_iFocusCellYColumnNumber != iFocusCellYColumnNumber )
	{
		m_iFocusCellXColumnNumber = iFocusCellXColumnNumber ; 
		m_iFocusCellYColumnNumber = iFocusCellYColumnNumber ;
		bRv = true ;
	}


	if ( m_pCDcdGrid->getXFixafterColumnNumber() != iXFixafterColumnNumber )
	{
		m_pCDcdGrid->setXFixafterColumnNumber( iXFixafterColumnNumber ) ;
		bRv = true ;
	}
	if ( m_pCDcdGrid->getYFixafterColumnNumber() != iYFixafterColumnNumber )
	{
		m_pCDcdGrid->setYFixafterColumnNumber( iYFixafterColumnNumber ) ;
		bRv = true ;
	}

	return ( bRv ) ;
}

bool CFocus::update_updateScreen() 
{
	bool	bRv = true ;
	CXDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	CDcdTargetGetDC	aCDcdTarget( m_pCWndDcdGrid->GetSafeHwnd() ) ;
	
	// --------------------------------
	//	【2.属性の変化をCWndDcdGridに通知】
	// --------------------------------
	if ( m_iFocusCellXColumnNumber_Sid != m_iFocusCellXColumnNumber ||
			m_iFocusCellYColumnNumber_Sid != m_iFocusCellYColumnNumber )
	{
		// --------------------------------
		//	イベント処理のための仮想関数
		// --------------------------------
		CDcdGridCell*	pCDcdGridCell = m_pCDcdGrid->getCell( 
				m_iFocusCellXColumnNumber , m_iFocusCellYColumnNumber ) ;
		if ( pCDcdGridCell != NULL )
		{
			m_pCWndDcdGrid->OnSetFocusCell( pCDcdGridCell ) ;
		}
	}
	// ----------------------------------------------------------------
	//	フォーカスセル移動時は、
	//	フォーカスセルの旧位置と新位置を再描画
	// ----------------------------------------------------------------
	if ( m_iFocusCellXColumnNumber_Sid != m_iFocusCellXColumnNumber ||
			m_iFocusCellYColumnNumber_Sid != m_iFocusCellYColumnNumber )
	{
		m_pCWndDcdGrid->InvalidateCell( m_iFocusCellXColumnNumber_Sid , 
			m_iFocusCellYColumnNumber_Sid ) ;
		m_pCWndDcdGrid->InvalidateCell( m_iFocusCellXColumnNumber , 
			m_iFocusCellYColumnNumber ) ;
		
		// --------------------------------
		m_iFocusCellXColumnNumber_Sid = m_iFocusCellXColumnNumber ;
		m_iFocusCellYColumnNumber_Sid = m_iFocusCellYColumnNumber ;
		bRv = true ;
	}
	return ( bRv ) ;
}
bool CFocus::OnPaint( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;
	CXDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	// --------------------------------	
	//	フォーカスマーク
	// --------------------------------	
	if ( m_pIfDcDrawFocusCell != NULL ){
		if ( m_bIsFocusmarkShowEvery || 
			CWnd::GetFocus() == m_pCWndDcdGrid ) {

			CdDcdZoneXy	zoneFocusCell = m_pCDcdGrid->getCellZone( 
				pIfDcdTarget ,
				m_iFocusCellXColumnNumber , m_iFocusCellYColumnNumber ) ;
	
			CaDcdTargetItemPosition	aCDcdTargetItemPosition( pIfDcdTarget ,
				zoneFocusCell ) ;
			if ( aCDcdTargetItemPosition.isDrawable() ){
				m_pIfDcDrawFocusCell->DcDraw( &aCDcdTargetItemPosition ) ;
				
				bRv = true ;
			}
		}
	}
	

	return bRv ;
}
	
void CFocus::OnSize(UINT nType, int cx, int cy)
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
	//	この場合のフォーカス移動は、
	//	m_iXFixafterColumnNumber_Sid,m_iYFixafterColumnNumber_Sidによって
	//	再描画されるため、クリアする必要はありません。
	//m_iFocusCellXColumnNumber_Sid = -1 ;
	//m_iFocusCellYColumnNumber_Sid = -1 ;

}

void CFocus::OnSetFocus(CWnd* pOldWnd)
{
	CDcdGridCell* pCell = getFocusCell() ;
	int iFocusCellXColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getXColumnNumberOfCell( pCell ) ; 
	int iFocusCellYColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ; 
	m_pCWndDcdGrid->InvalidateCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ;
}
void CFocus::OnKillFocus(CWnd* pNewWnd)
{
	CDcdGridCell* pCell = getFocusCell() ;
	int iFocusCellXColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getXColumnNumberOfCell( pCell ) ; 
	int iFocusCellYColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ; 
	m_pCWndDcdGrid->InvalidateCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ;
}

void CFocus::InvalidateGrid()
{
	//	このクラスの画面描画はすべてOnPaintで行われます。
	//	InvalidateGridでは、特別な処理は不要です。


}

	// ********************************
	//	コンストラクタ
	// ********************************
CFocus::CFocus( CWndDcdGrid* pCWndDcdGrid ) 
	: m_pCWndDcdGrid( pCWndDcdGrid )
	, m_iFocusCellXColumnNumber( 0 )
	, m_iFocusCellYColumnNumber( 0 )
	, m_bFixafterColumnNumberChange( true )
	, m_bIsFocusmarkShowEvery( false )
	, m_iFocusCellXColumnNumber_Sid( -1 )
	, m_iFocusCellYColumnNumber_Sid( -1 )
{

	CreateDcDrawFocusCell() ;
}

CFocus::~CFocus() 
{
	DeleteDcDrawFocusCell() ;
}
	// ********************************
	//@name 関連
	// ********************************
Ou<IfDcDraw>	CFocus::getIfDcDrawFocusCell() 
{
	return ( m_pIfDcDrawFocusCell ) ;
}
void CFocus::setIfDcDrawFocusCell( Ou<IfDcDraw> value ) 
{
	m_pIfDcDrawFocusCell = value ;
}
	// ********************************
	///@name CWndDcdGrid-フォーカス
	// ********************************

CdDcdPosXy	CFocus::getFocusCellColumnNumber() 
{
	CdDcdPosXy	posXy( ColumnNumberPosXy_NULL() ) ;
	CXDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if( 0 <= m_iFocusCellXColumnNumber && 
		m_iFocusCellXColumnNumber < pCDcdGrid->getXColumnCount() && 
		0 <= m_iFocusCellYColumnNumber && 
		m_iFocusCellYColumnNumber < pCDcdGrid->getYColumnCount() )
	{
		posXy.setX( m_iFocusCellXColumnNumber ) ;
		posXy.setY( m_iFocusCellYColumnNumber ) ;
	}
	return posXy ;
}

void CFocus::setFocusCellColumnNumber( const CdDcdPosXy& value ) 
{
	if ( m_iFocusCellXColumnNumber == value.getX() &&
		m_iFocusCellYColumnNumber == value.getY() )
	{
		return ;
	}
	m_iFocusCellXColumnNumber = value.getX() ;
	m_iFocusCellYColumnNumber = value.getY() ;

	//	属性の変更をもとに、ウインドウ表示の更新処理を行います。
	m_pCWndDcdGrid->update() ;
}

CDcdGridCell*	CFocus::getFocusCell() 
{
	CDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	return ( m_pCDcdGrid->getCell( 
		m_iFocusCellXColumnNumber , m_iFocusCellYColumnNumber ) ) ;
}


void CFocus::setFocusCell( CDcdGridCell* value ) 
{
	if ( value == NULL ){
		return ;
	}

	CXDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	int iXColumnNumber = m_pCDcdGrid->getXColumnNumberOfCell( value ) ;
	int iYColumnNumber = m_pCDcdGrid->getYColumnNumberOfCell( value )  ;

	if ( m_iFocusCellXColumnNumber == iXColumnNumber &&
		m_iFocusCellYColumnNumber == iYColumnNumber )
	{
		return ;
	}
	m_iFocusCellXColumnNumber = iXColumnNumber ;
	m_iFocusCellYColumnNumber = iYColumnNumber ;

	//	属性の変更をもとに、ウインドウ表示の更新処理を行います。
	m_pCWndDcdGrid->update() ;
}


bool	CFocus::getFixafterColumnNumberChange()
{
	return m_bFixafterColumnNumberChange ;
}
void CFocus::setFixafterColumnNumberChange( bool value ) 
{
	m_bFixafterColumnNumberChange = value ;
}

bool	CFocus::getIsFocusmarkShowEvery()
{
	return m_bIsFocusmarkShowEvery ;
}
void CFocus::setIsFocusmarkShowEvery( bool value ) 
{
	if ( m_bIsFocusmarkShowEvery != value ){
		m_bIsFocusmarkShowEvery = value ;
		m_pCWndDcdGrid->InvalidateCell( 
			m_iFocusCellXColumnNumber , m_iFocusCellYColumnNumber ) ;
	}
}

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib
