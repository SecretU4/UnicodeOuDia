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
//	$Id: CXDcdGrid.cpp 387 2016-11-20 08:43:33Z okm $
// ****************************************************************
*/
/** @file */
#include "CWndDcdGrid.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "WinUtil\CconvWinUser.h"
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
//	WndDcdGrid3::CXDcdGrid
// ----------------------------------------------------------------
// ********************************
//	コンストラクタ
// ********************************
CXDcdGrid::CXDcdGrid( CWndDcdGrid* pCWndDcdGrid ) 
	: m_bUpdateCWndDcdGrid( true ) 
	, m_pCWndDcdGrid( pCWndDcdGrid ) 
{
}
CXDcdGrid::~CXDcdGrid() 
{
}
// ********************************
//	CDcdGrid
// ********************************
	// --------------------------------
	//@name 行・列・セルの初期化
	// --------------------------------
void CXDcdGrid::OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	m_pCWndDcdGrid->OnCreateXColumn( iXColumnNumber , 
		pCDcdGridXColumn ) ;
}
	
void CXDcdGrid::OnDeleteXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	m_pCWndDcdGrid->OnDeleteXColumn( iXColumnNumber , 
		pCDcdGridXColumn ) ;
}

void CXDcdGrid::OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
	m_pCWndDcdGrid->OnCreateYColumn( iYColumnNumber , 
		pCDcdGridYColumn ) ;
}

void CXDcdGrid::OnDeleteYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
	m_pCWndDcdGrid->OnDeleteYColumn( iYColumnNumber , 
		pCDcdGridYColumn ) ;
}

void CXDcdGrid::OnCreateCell( 
		int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) 
{
	m_pCWndDcdGrid->OnCreateCell( 
		iXColumnNumber , iYColumnNumber , 
		pCDcdGridCell ) ;
}
	
void CXDcdGrid::OnDeleteCell( 
		int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) 
{
	m_pCWndDcdGrid->OnDeleteCell( 
		iXColumnNumber , iYColumnNumber , 
		pCDcdGridCell ) ;
}
	
	// ********************************
	//	@name Y列・X列の数
	// ********************************
int CXDcdGrid::getYColumnCount() 
{
	return CDcdGrid::getYColumnCount() ;
};
	
CDcdGrid& CXDcdGrid::setYColumnCount( int ev ) 
{
	//LogMsg( "CWndDcdGrid::setYColumnCount()" ) ;

	CDcdGrid::setYColumnCount( ev ) ;
	m_pCWndDcdGrid->InvalidateGrid() ;

	//LogMsg( "CWndDcdGrid::setYColumnCount()=" ) ;

	return *this ;
};
	
int		CXDcdGrid::getXColumnCount() 
{
	return CDcdGrid::getXColumnCount() ;
};

CDcdGrid& CXDcdGrid::setXColumnCount( int ev ) 
{
	CDcdGrid::setXColumnCount( ev ) ;
	m_pCWndDcdGrid->InvalidateGrid() ;

	return *this ;
};

	// ********************************
	//	@name Y列・X列を挿入/削除
	// ********************************
int CXDcdGrid::insertYColumn( int iYColumnNumber , 
		bool bFixafterColumnNumberChange ) 
{
	int iRv = CDcdGrid::insertYColumn( iYColumnNumber ) ;
	//	フォーカス位置・スクロール位置・選択を再設定
	m_pCWndDcdGrid->InvalidateGrid() ;

	if ( iRv >= 0 )
	{

		//	フォーカスセルのある列・またはそれより列Indexの小さい場所に
		//	列が追加された場合は、フォーカスセルを
		//	挿入によってずれた列に追従させます。
		CDcdGridCell* pCell = m_pCWndDcdGrid->getCFocus()->getFocusCell() ;
		int iFocusCellXColumnNumber = getXColumnNumberOfCell( pCell ) ; 
		int iFocusCellYColumnNumber = getYColumnNumberOfCell( pCell ) ; 
		if ( iFocusCellYColumnNumber >= iYColumnNumber )
		{
			iFocusCellYColumnNumber ++ ;
			m_pCWndDcdGrid->getCFocus()->setFocusCell( 
				getCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ) ;
		}
	}
	return ( iRv ) ;
};
int CXDcdGrid::insertXColumn( int iXColumnNumber ,
		bool bFixafterColumnNumberChange ) 
{
	int iRv = CDcdGrid::insertXColumn( iXColumnNumber ) ;
	//	フォーカス位置・スクロール位置・選択を再設定
	m_pCWndDcdGrid->InvalidateGrid() ;

	if ( iRv >= 0 )
	{
		//	フォーカスセルのある列・またはそれより列Indexの小さい場所に
		//	列が追加された場合は、フォーカスセルを
		//	挿入によってずれた列に追従させます。
		CDcdGridCell* pCell = m_pCWndDcdGrid->getCFocus()->getFocusCell() ;
		int iFocusCellXColumnNumber = getXColumnNumberOfCell( pCell ) ; 
		int iFocusCellYColumnNumber = getYColumnNumberOfCell( pCell ) ; 
		if ( iFocusCellXColumnNumber >= iXColumnNumber ){
			iFocusCellXColumnNumber ++ ;
			m_pCWndDcdGrid->getCFocus()->setFocusCell( 
				getCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ) ;
		}
	}
	return ( iRv ) ;
};

int CXDcdGrid::eraseYColumn( int iYColumnNumber ) 
{
	int iRv = CDcdGrid::eraseYColumn( iYColumnNumber ) ;
	//	フォーカス位置・スクロール位置・選択を再設定
	m_pCWndDcdGrid->InvalidateGrid() ;

	if ( iRv >= 0 )
	{

		CDcdGridCell* pCell = m_pCWndDcdGrid->getCFocus()->getFocusCell() ;
		//	セルの数が0になった直後は、この戻り値はNULLになります。

		if ( pCell != NULL )
		{
			//	フォーカスセルのある列より列Indexの小さい場所から
			//	列が削除された場合は、フォーカスセルを
			//	削除によってずれた列に追従させます。
			int iFocusCellXColumnNumber = getXColumnNumberOfCell( pCell ) ; 
			int iFocusCellYColumnNumber = getYColumnNumberOfCell( pCell ) ; 
			if ( iFocusCellYColumnNumber > iYColumnNumber )
			{
				iFocusCellYColumnNumber -- ;
				m_pCWndDcdGrid->getCFocus()->setFocusCell( 
					getCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ) ;
			}
		}
		
	}
	return ( iRv ) ;
};

int CXDcdGrid::eraseXColumn( int iXColumnNumber ) 
{
	int iRv = CDcdGrid::eraseXColumn( iXColumnNumber ) ;
	//	フォーカス位置・スクロール位置・選択を再設定
	m_pCWndDcdGrid->InvalidateGrid() ;

	if ( iRv >= 0 )
	{

		CDcdGridCell* pCell = m_pCWndDcdGrid->getCFocus()->getFocusCell() ;
		//	セルの数が0になった直後は、この戻り値はNULLになります。

		if ( pCell != NULL )
		{
			//	フォーカスセルのある列より列Indexの小さい場所から
			//	列が削除された場合は、フォーカスセルを
			//	削除によってずれた列に追従させます。
			int iFocusCellXColumnNumber = getXColumnNumberOfCell( pCell ) ; 
			int iFocusCellYColumnNumber = getYColumnNumberOfCell( pCell ) ; 
			if ( iFocusCellXColumnNumber > iXColumnNumber )
			{
				iFocusCellXColumnNumber -- ;
				m_pCWndDcdGrid->getCFocus()->setFocusCell( 
					getCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ) ;
			}
		}
	}
	return ( iRv ) ;
};



	// ********************************
	//	@name	スクロール
	// ********************************
int	CXDcdGrid::getXFixColumnCount() 
{
	return CDcdGrid::getXFixColumnCount() ;
}
CDcdGrid& CXDcdGrid::setXFixColumnCount( int ev ) 
{
	CDcdGrid::setXFixColumnCount( ev ) ;
	if ( m_bUpdateCWndDcdGrid )
	{
		m_pCWndDcdGrid->InvalidateGrid() ;
	}
	return *this ;
}
int	CXDcdGrid::getXFixafterColumnNumber() 
{
	return CDcdGrid::getXFixafterColumnNumber() ;
}
CDcdGrid& CXDcdGrid::setXFixafterColumnNumber( int ev ) 
{
	CDcdGrid::setXFixafterColumnNumber( ev ) ;

	//	属性の変更をもとに、ウインドウ表示の更新処理を行います。
	if ( m_bUpdateCWndDcdGrid )
	{
		m_pCWndDcdGrid->update() ;
	}
	return *this ;
}
int	CXDcdGrid::getYFixColumnCount() 
{
	return CDcdGrid::getYFixColumnCount() ;
}
CDcdGrid& CXDcdGrid::setYFixColumnCount( int ev ) 
{
	CDcdGrid::setYFixColumnCount( ev ) ;
	if ( m_bUpdateCWndDcdGrid )
	{
		m_pCWndDcdGrid->InvalidateGrid() ;
	}
	return *this ;
}
int	CXDcdGrid::getYFixafterColumnNumber() 
{
	return CDcdGrid::getYFixafterColumnNumber() ;
}
CDcdGrid& CXDcdGrid::setYFixafterColumnNumber( int ev ) 
{
	CDcdGrid::setYFixafterColumnNumber( ev ) ;
	
	//	属性の変更をもとに、ウインドウ表示の更新処理を行います。
	if ( m_bUpdateCWndDcdGrid )
	{
		m_pCWndDcdGrid->update() ;
	}
	return *this ;
}


bool CXDcdGrid::update_adjustProp() 
{
	bool bRv = false ;

	return bRv ;
}

bool CXDcdGrid::update_updateScreen() 
{
	bool bRv = false ;
	CDcdTargetGetDC	aCDcdTarget( m_pCWndDcdGrid->GetSafeHwnd() ) ;


	// ----------------------------------------------------------------
	//	イベント処理のための仮想関数呼び出し
	// ----------------------------------------------------------------
	if ( getXFixafterColumnNumber() != m_CdScrollbarPropX_Sid.getPos() ) 
	{
		//	イベント処理のための仮想関数
		m_pCWndDcdGrid->OnSetXFixafterColumnNumber( getXFixafterColumnNumber() ) ;
	}
	if ( getYFixafterColumnNumber() != m_CdScrollbarPropY_Sid.getPos() ) 
	{
		//	イベント処理のための仮想関数
		m_pCWndDcdGrid->OnSetYFixafterColumnNumber( getYFixafterColumnNumber() ) ;
	}

	// ----------------------------------------------------------------
	//	X方向クライアント領域スクロール
	// ----------------------------------------------------------------
	if ( !m_CdScrollbarPropX_Sid.isNull() && 
		m_CdScrollbarPropX_Sid.getPos() != 
		getXFixafterColumnNumber() )
	{
		{
			// --------------------------------
			//	スクロールする領域を求める
			// --------------------------------
			CRect	rectScroll ;
			{
				CRect	rectClient ;
				m_pCWndDcdGrid->GetClientRect( &rectClient ) ;
				rectScroll = rectClient ;
				{
					DcdSize sizeFix = getXColumnBorderZone( 
						&aCDcdTarget , getXFixColumnCount() - 1 )
						.getEndPos() ;
					rectScroll.left = sizeFix ;
				}
			}
			//rectScroll = ウインドウ上で、スクロールを行う領域
			//	（固定列部分を除いた領域）

			// --------------------------------
			//	スクロール量を求める
			// --------------------------------
			int iAmount = 0 ;
			CRect	rectScrollSrc ;
			{
				rectScrollSrc = rectScroll ;
				if ( m_CdScrollbarPropX_Sid.getPos() < 
						getXFixafterColumnNumber() ){
					for ( int iColumnNumber = m_CdScrollbarPropX_Sid.getPos() ;
						iColumnNumber < getXFixafterColumnNumber() ;
						iColumnNumber ++ )
					{
						iAmount -= getXColumn( iColumnNumber )->getColumnSize( &aCDcdTarget ) ;
						iAmount -= getXBorder( iColumnNumber )->getColumnBorderSize( &aCDcdTarget ) ;
					}

					rectScrollSrc.left += - iAmount ;
		
				} else if ( getXFixafterColumnNumber() < 
						m_CdScrollbarPropX_Sid.getPos() ){
					for ( int iColumnNumber = m_CdScrollbarPropX_Sid.getPos() - 1 ;
						iColumnNumber >= getXFixafterColumnNumber() ;
						iColumnNumber -- )
					{
						iAmount += getXColumn( iColumnNumber )->getColumnSize( &aCDcdTarget ) ;
						iAmount += getXBorder( iColumnNumber )->getColumnBorderSize( &aCDcdTarget ) ;
					}



					rectScrollSrc.right -= iAmount ;
				}
			}
			//iAmount = スクロール量(負の数は左/上にスクロール)
			//rectScrollSrc = スクロールで移動となる領域です。
			//	rectScroll 領域から、スクロールで非表示になる領域を除いたものです。
			//	ただし、この値が left >= right になった場合、スクロールで移動となる
			//	領域が全くないことを示します。
			//	この場合は、スクロール領域全体を無効化して
			//	再描画を行わせます。

			// --------------------------------
			//	画面をスクロール・または無効化により
			//	更新
			// --------------------------------
			if ( iAmount != 0 )
			{
				if ( rectScrollSrc.left >= rectScrollSrc.right )
				{
					m_pCWndDcdGrid->InvalidateRect( rectScroll ) ;
				}
				else
				{
					//	これは、無効にならない領域があります。
					//m_pCWndDcdGrid->ScrollWindow( iAmount , 0 , &rectScrollSrc ) ;
		
					m_pCWndDcdGrid->ScrollWindow( iAmount , 0 , &rectScroll , &rectScroll ) ;
				}
				bRv = true ;
			}
		}
	}
	// ----------------------------------------------------------------
	//	X方向スクロールバー属性を設定
	// ----------------------------------------------------------------
	{
		WinUtil::CdScrollbarProp	aScrollbarPropX ;

		int iPage = 
			getXColumnNumberMaxInDcdTarget( &aCDcdTarget ) - 
			getXFixafterColumnNumber() + 1 ;

		//	スクロールバを表示する場合、スクロールバーのページ数は、１とします。
		//
		//	ページ幅が、非固定列数より小さい場合は、
		//	スクロールバーの表示が必要です。
		//	この場合はページ幅は1とします。
		if ( iPage < getXColumnCount() - 
				getXFixColumnCount() ){
			//	スクロールバーが必要
			iPage = 1 ;
		}

		aScrollbarPropX.set(
			getXFixColumnCount() ,
			getXColumnCount() - 1 ,
			iPage ,
			getXFixafterColumnNumber() ) ;
		if ( !m_CdScrollbarPropX_Sid.isEqualTo( aScrollbarPropX ) )
		{
			SCROLLINFO	aScrollinfo = 
				WinUtil::CconvWinUser::SCROLLINFOof( aScrollbarPropX ) ;
			m_pCWndDcdGrid->SetScrollInfo( SB_HORZ , &aScrollinfo ) ; 
		
			m_CdScrollbarPropX_Sid = aScrollbarPropX ;
			bRv = true ;
		}

	}
	// ----------------------------------------------------------------
	//	Y方向クライアント領域スクロール
	// ----------------------------------------------------------------
	if ( !m_CdScrollbarPropY_Sid.isNull() &&
		m_CdScrollbarPropY_Sid.getPos() != 
			getYFixafterColumnNumber() )
	{

		{ 
			// --------------------------------
			//	スクロールする領域を求める
			// --------------------------------
			CRect	rectScroll ;
			{
				CRect	rectClient ;
				m_pCWndDcdGrid->GetClientRect( &rectClient ) ;
				rectScroll = rectClient ;
				{
					DcdSize sizeFix = getYColumnBorderZone( 
						&aCDcdTarget , getYFixColumnCount() - 1 )
						.getEndPos() ;
					rectScroll.top = sizeFix ;
				}
			}
			//rectScroll = ウインドウ上で、スクロールを行う領域
			//	（固定列部分を除いた領域）
		
			// --------------------------------
			//	スクロール量を求める
			// --------------------------------
			int iAmount = 0 ;
			CRect	rectScrollSrc ;
			{
				rectScrollSrc = rectScroll ;
				if ( m_CdScrollbarPropY_Sid.getPos() < 
						getYFixafterColumnNumber() ){
					
					for ( int iColumnNumber = m_CdScrollbarPropY_Sid.getPos() ;
						iColumnNumber < getYFixafterColumnNumber() ;
						iColumnNumber ++ )
					{
						iAmount -= getYColumn( iColumnNumber )->getColumnSize( &aCDcdTarget ) ;
						iAmount -= getYBorder( iColumnNumber )->getColumnBorderSize( &aCDcdTarget ) ;
					}
							
					rectScrollSrc.top += - iAmount ;
		
				} else if ( getYFixafterColumnNumber() < 
						m_CdScrollbarPropY_Sid.getPos() ){
					for ( int iColumnNumber = m_CdScrollbarPropY_Sid.getPos() - 1 ;
						iColumnNumber >= getYFixafterColumnNumber() ;
						iColumnNumber -- )
					{
						iAmount += getYColumn( iColumnNumber )->getColumnSize( &aCDcdTarget ) ;
						iAmount += getYBorder( iColumnNumber )->getColumnBorderSize( &aCDcdTarget ) ;
					}

					rectScrollSrc.bottom -= iAmount ;
				}
			}
			//iAmount = スクロール量(負の数は左/上にスクロール)
			//rectScrollSrc = スクロールで移動となる領域です。
			//	rectScroll 領域から、スクロールで非表示になる領域を除いたものです。
			//	ただし、この値が top >= bottom になった場合、スクロールで移動となる
			//	領域が全くないことを示します。
			//	この場合は、スクロール領域全体を無効化して
			//	再描画を行わせます。
		
			// --------------------------------
			//	画面をスクロール・または無効化により
			//	更新
			// --------------------------------
			if ( iAmount != 0 ){
				if ( rectScrollSrc.top >= rectScrollSrc.bottom ){
					m_pCWndDcdGrid->InvalidateRect( rectScroll ) ;
				}	else	{
					//	これは、無効にならない領域があります
					//ScrollWindow( 0 , iAmount , &rectScrollSrc ) ;	
					
					m_pCWndDcdGrid->ScrollWindow(  0 , iAmount , &rectScroll , &rectScroll ) ;
				}
				bRv = true ;
			}
		}
	}
	// ----------------------------------------------------------------
	//	Y方向スクロールバー属性を設定
	// ----------------------------------------------------------------
	{
		WinUtil::CdScrollbarProp	aScrollbarPropY ;

		int iPage = 
			getYColumnNumberMaxInDcdTarget( &aCDcdTarget ) - 
			getYFixafterColumnNumber() + 1 ;

		//	スクロールバを表示する場合、スクロールバーのページ数は、１とします。
		//
		//	ページ幅が、非固定列数より小さい場合は、
		//	スクロールバーの表示が必要です。
		//	この場合はページ幅は1とします。
		if ( iPage < getYColumnCount() - 
				getYFixColumnCount() ){
			//	スクロールバーが必要
			iPage = 1 ;
		}


		aScrollbarPropY.set(
			getYFixColumnCount() ,
			getYColumnCount() - 1 ,
			iPage ,
			getYFixafterColumnNumber() ) ;
		if ( !m_CdScrollbarPropY_Sid.isEqualTo( aScrollbarPropY ) )
		{
			SCROLLINFO	aScrollinfo =
				WinUtil::CconvWinUser::SCROLLINFOof( aScrollbarPropY ) ;
			m_pCWndDcdGrid->SetScrollInfo( SB_VERT , &aScrollinfo ) ; 
		
			m_CdScrollbarPropY_Sid = aScrollbarPropY ;
			bRv = true ;
		}
	}

	return bRv ;
}

void CXDcdGrid::InvalidateGrid( 
		bool bErase ) 
{
	//	完全な再描画のため、すべての前回値をクリアします。
	m_CdScrollbarPropX_Sid.setNull() ;
	m_CdScrollbarPropY_Sid.setNull() ;
}

// ********************************
//@name CXDcdGrid 属性
// ********************************
bool CXDcdGrid::getUpdateCWndDcdGrid()const 
{
	return m_bUpdateCWndDcdGrid ;
}
void CXDcdGrid::setUpdateCWndDcdGrid( bool value ) 
{
	if ( m_bUpdateCWndDcdGrid != value )
	{
		//　属性を false から true に変更した場合は、CWndDcdGrid 全体を更新します。
		if ( value )
		{
			m_pCWndDcdGrid->update() ;
		}

		m_bUpdateCWndDcdGrid = value ;
	}
}
	// ================================
	//@name CXDcdGrid_ZoneCacheTemp に、createZoneCacheを公開
	// ================================
bool CXDcdGrid::createZoneCache( IfDcdTarget* pIfDcdTarger )
{
	LogMsg( "CXDcdGrid::createZoneCache()" ) ;
	return CDcdGrid::createZoneCache( pIfDcdTarger ) ;
};
void CXDcdGrid::destroyZoneCache()
{
	CDcdGrid::destroyZoneCache() ;
	LogMsg( "CXDcdGrid::destroyZoneCache()" ) ;
};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib
