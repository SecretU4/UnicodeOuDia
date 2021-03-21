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
//	CdScrollbarProp.h
// $Id: CdScrollbarProp.h 327 2016-06-12 04:20:29Z okm $
// ****************************************************************
*/
/** @file */
#ifndef WinUtil_CdScrollbarProp_h
#define WinUtil_CdScrollbarProp_h


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


namespace DcDrawLib{ namespace WinUtil{

// ****************************************************************
//	CdScrollbarProp
// ****************************************************************
/**
@brief
	単純データクラスです。
	スクロールバー属性を保持します。

	このクラスは、有効な値を持たない NULL 状態を持つことができます。

	this は属性に対して、常に以下の補正を行います。

	- m_iMax >= m_iMin 
	- m_iPage <= m_iMax - m_iMin + 1  
	- m_iPage >= 1 
	- m_iPos <= m_iMax 
	- m_iPos <= m_iMax - m_iPage + 1   (m_bAdjustPosByPage=trueの場合のみ)
	- m_iPos >= m_iMin


*/
class CdScrollbarProp
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		スクロールバーの最小の位置。
		NULL状態になったときには、この値は 0 に初期化されます。
	*/
	int m_iMin ;
	/**
		スクロールバーの最大の位置。
		NULL状態になったときには、この値は 0 に初期化されます。
	*/
	int m_iMax ;
	/**
		現在表示中のページ数。
		NULL状態になったときには、この値は 1 に初期化されます。

		m_iMin = 0 で m_iMax が 5 で m_iPage が 1 の場合は、
		スクロールバーの位置は 0から5までの値をとります。

		m_iMin = 0 で m_iMax が 5 で m_iPage が 2 の場合は、
		スクロールバーの位置は 0から4までの値をとります。

		m_iMin = 0 で m_iMax が 5 で m_iPage が 6 の場合は、
		スクロールバーは非表示(またはDisable)となります。
	*/
	int m_iPage ;
	/**
		スクロールバーの位置。
		NULL状態になったときには、この値は 0 に初期化されます。
	*/
    int m_iPos; 

	/**
		this がNULL状態なら true です。
	*/
	bool m_bIsNull ;

	/**
		- true: スクロールバーの使用が不要な場合は、スクロールバーを無効にします。
		- false:(既定値)スクロールバーの操作が不要な場合は、スクロールバーを非表示にします。

		この値は、 setNull() でも変化しません。
	@attention
		これに相当するフラグ SIF_DISABLENOSCROLL と
		スクロールバー不要な位置情報を指定して
		SetScrollInfo() を呼び出すと、スクロールバーが無効に
		なります。
		しかし、その後に  SIF_DISABLENOSCROLL 無し・
		スクロールバー必要な位置情報を指定して
		SetScrollInfo() を呼び出しても、
		スクロールバーは無効から有効にはなりません。
		これを回避するためには、
		@code
		EnableScrollBar( (SB_HORZ or SB_VERT), ESB_ENABLE_BOTH ) ;
		@endcode
		を呼び出してから、
		SetScrollInfo()を呼び出してください。
	*/
	bool m_bDisableNoScroll ;

	/**
		ページ数を考慮した正規化を行うか否かを示します。

		ページ数を考慮した正規化をは、以下を指します。

		- m_iPos <= m_iMax - m_iPage + 1  

		この値は、 setNull() でも変化しません。
		既定値は true です。
	*/
	bool m_bAdjustPosByPage ;


	///@}
protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
		属性を補正します。
	*/
	void adjustProp() 
	{
		if ( !m_bIsNull )
		{
			if ( !( m_iMax >= m_iMin ) )
			{
				m_iMax = m_iMin ;
			}
			if ( !( m_iPage <= m_iMax - m_iMin + 1 ) )
			{
				m_iPage = m_iMax - m_iMin + 1 ;
			}
			if ( !( m_iPage >= 1 ) )
			{
				m_iPage = 1 ;
			}

			if ( !( m_iPos <= m_iMax ) )
			{
				m_iPos = m_iMax ;
			}

			if ( m_bAdjustPosByPage )
			{
				if ( !( m_iPos <= m_iMax - m_iPage + 1 ) )
				{
					m_iPos = m_iMax - m_iPage + 1 ;
				}
			}
			if ( !( m_iPos >= m_iMin ) )
			{
				m_iPos = m_iMin ;
			}
		}
	};
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
		this をNULL状態に初期化します。
	*/
	CdScrollbarProp()
		: m_iMin( 0 ) 
		, m_iMax( 0 ) 
		, m_iPage( 1 ) 
		, m_iPos( 0 )
		, m_bIsNull( true ) 
		, m_bDisableNoScroll( false ) 
		, m_bAdjustPosByPage( true ) 
	{} ;
	CdScrollbarProp(
		int iMin , 
		int iMax , 
		int iPage , 
		int iPos )
		: m_iMin( iMin ) 
		, m_iMax( iMax ) 
		, m_iPage( iPage ) 
		, m_iPos( iPos )
		, m_bIsNull( false ) 
		, m_bDisableNoScroll( false ) 
		, m_bAdjustPosByPage( true ) 
	{
		adjustProp() ;
	} ;
	CdScrollbarProp(
		int iMin , 
		int iMax , 
		int iPage , 
		int iPos , 
		bool bDisableNoScroll ,
		bool bAdjustPosByPage )
		: m_iMin( iMin ) 
		, m_iMax( iMax ) 
		, m_iPage( iPage ) 
		, m_iPos( iPos )
		, m_bIsNull( false ) 
		, m_bDisableNoScroll( bDisableNoScroll ) 
		, m_bAdjustPosByPage( bAdjustPosByPage ) 
	{
		adjustProp() ;
	} ;

public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	int getMin()const{	return m_iMin ;};
	int getMax()const{	return m_iMax ;};
	void setMinMax( int iMin , int iMax )
	{
		m_bIsNull = false ;
		m_iMin = iMin ;
		m_iMax = iMax ;
		adjustProp() ;
	};
	int getPage()const{	return m_iPage ;};
	void setPage( int value )
	{
		m_bIsNull = false ; 
		m_iPage = value ;
		adjustProp() ;
	};
	int getPos()const{	return m_iPos;}; 
	void setPos( int value )
	{
		m_bIsNull = false ; 
		m_iPos = value ;
		adjustProp() ;
	}; 

	bool getDisableNoScroll()const{	return m_bDisableNoScroll;};
	void setDisableNoScroll( bool value )
	{
		m_bIsNull = false ; 
		m_bDisableNoScroll = value ;
	}

	bool getAdjustPosByPage()const{	return m_bAdjustPosByPage ;};
	void setAdjustPosByPage( bool value )
	{
		m_bAdjustPosByPage = value ;
		adjustProp() ;
	}
	/** 
	@return
		-true : this が NULL 。
		-false: this が NULLでない 。
	*/
	bool isNull()const
	{
		return ( m_bIsNull ) ;
	};
	void setNull()
	{
		m_iMin = 0 ;
		m_iMax = 0 ;
		m_iPage = 1 ;
		m_iPos = 0 ;
		m_bIsNull = true ;
	};
	/**
		すべての属性を設定し、this を 非NULLとします。
	@param iMin [in]
	@param iMax [in]
	@param iPage [in]
	@param iPos [in]
	*/
	void set( int iMin , int iMax , int iPage , int iPos )
	{
		m_iMin = iMin ;
		m_iMax = iMax ;
		m_iPage = iPage ;
		m_iPos = iPos ;
		m_bIsNull = false ;
		adjustProp() ;
	};
	///@}
public:
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
		２つの CdScrollbarProp を比較します。
	@param value [in]
		比較対象となる CdScrollbarProp を指定してください。
	@return
		- true : CdScrollbarProp が等しい。双方がNULL。
	*/
	bool isEqualTo( const CdScrollbarProp& value )const
	{
		if ( m_bIsNull && value.m_bIsNull )
		{
			return true ;
		}
		return ( m_iMin == value.m_iMin
			&& m_iMax == value.m_iMax
			&& m_iPage == value.m_iPage
			&& m_iPos == value.m_iPos 
			&& m_bDisableNoScroll == value.m_bDisableNoScroll  
			&& m_bAdjustPosByPage == value.m_bAdjustPosByPage ) ;
	};
	///@}
};

} } //namespace DcDrawLib{ namespace WinUtil{ 

#endif //WinUtil_CdScrollbarProp_h
