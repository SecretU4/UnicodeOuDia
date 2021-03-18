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
//	./CdDcdZone.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDcdZone_h
#define  CdDcdZone_h

#include "./DcdType.h"

// ****************************************************************
//	CdDcdZone.h
// ****************************************************************
/**
 @brief 
 【概要】
 	  １次元の座標空間上の、範囲を表す単純データクラスです。
 	  起点位置座標と、その範囲の大きさを表します。
*/
class CdDcdZone
{
public:
	// --------------------------------
	///@name	下請関数
	// --------------------------------
	///@{
	/**
	 	値の符号を表す値を返します。
	 @param ev [in]
	 	符号を検証する値を指定してください。
	 @return
	 	値が	@n
	 		０なら０、		@n
	 		正の数なら１	@n
	 		負の数なら－１	@n
	 	を返します。
	*/
	static int Sign( int ev ){
		if ( ev > 0 ){	return ( 1 ) ;}
		else if ( ev < 0 ){	return ( -1 ) ;}
		return ( 0 ) ;
	};
	///@}
private:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	///	起点位置です。
	DcdPos m_iPos ;
	
	///  範囲の大きさです。
	DcdSize m_iSize ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CdDcdZone() : m_iPos( 0 ) , m_iSize( 0 ) {} ;
	
	/**
	 	起点位置から１の範囲を表すオブジェクトを生成します
	 @param iPos [in]
	 	起点位置を指定してください。
	*/
	CdDcdZone( DcdPos iPos ) 
		: m_iPos( iPos ) , m_iSize( 1 ) {} ;
	
	/**
	 @param iPos [in]
	 	起点位置を指定してください。
	 @param iSize ; [in]
	   範囲の大きさです。
	*/
	CdDcdZone( DcdPos iPos , DcdSize iSize ) 
		: m_iPos( iPos ) , m_iSize( iSize ) {} ;
	
 public:
	// ********************************
	///@name	CdDcdZone-属性
	// ********************************
	///@{
	DcdPos getPos()const{	return ( m_iPos ) ;	};
	CdDcdZone& setPos( DcdPos ev ){	m_iPos = ev ;	return ( *this ) ;	};
	DcdSize getSize()const{	return ( m_iSize ) ;};
	CdDcdZone& setSize( DcdSize ev ){	m_iSize = ev ;	return ( *this ) ;	};
	
	/**
	  @return
	    範囲の終点位置の次の位置を返します。
	  	この位置は、範囲には含まれません。
	*/
	DcdPos getEndPos()const{	return m_iPos + m_iSize ; } ;
	
	/**
	    範囲の終点位置の次の位置を指定します。
	  	 この位置は、範囲には含まれません。
	 	
	 	この関数は、 value をもとに、m_iSize を決定します。
	 	m_iPos には、影響を与えません。
	*/
	CdDcdZone& setEndPos( DcdPos value ){
		m_iSize = value - m_iPos ; return *this ; } ;
	
	/**
	    範囲の起点位置と終点位置を設定します。
	  @param posBegin [in]
	 	起点位置を指定してください。
	  @param posEnd [in]
	  	 終点位置を指定してください。
	 	この位置は、範囲には含まれません。
	*/
	CdDcdZone& setBeginEndPos( DcdPos posBegin , DcdPos posEnd ){
		m_iPos = posBegin ;
		m_iSize = posEnd - posBegin ; 
		return *this ;
	};
		
	
	///@}
	
	// ********************************
	///@name	CdDcdZone-操作
	// ********************************
	///@{
	
	/**
	 @return
	 	  範囲の大きさの符号をあらわす数を返します。
	 		範囲が０なら０、
	 		正の数なら１
	 		負の数なら－１
	 	を返します。
	*/
	int getSizeSign()const{	return ( Sign( getSize() ) ) ;	};
	
	/**
	 	  範囲の大きさを表す値の符号を、正の数・または負の数に変更します。
	 	  この場合でも、座標範囲は変わりません。
	 	(例) Pos = 1,Size=5のオブジェクトに、 ev=-1 でこのメソッドを呼び出すと
	 	Pos = 5 ,Size=-5 になります。
	 @param ev [in]
	 	符号を正の数にするなら１・負の数にするなら－１を指定してください。
	*/
	CdDcdZone& setSizeSign( int ev = 1 ){
		if ( getSizeSign() == -Sign( ev ) ){
			//	符号を反転します。
			m_iPos = m_iPos + m_iSize - getSizeSign() ;
			m_iSize = -m_iSize ;
		}
		return ( *this ) ;
	};
	
	
	/**
	 	他のCdDcdZoneとの比較を行います。
	 @param ev [in]
	 	比較対象を指定してください。
	 @return
	 	すべての属性が同じであれば真です。
	*/
	bool IsEqualTo( const CdDcdZone& ev )const{	
		return ( m_iPos == ev.m_iPos && m_iSize == ev.m_iSize );
	};
	
	/**
	  	この範囲と、指定された別の範囲との間で、交差している範囲を
	  	求めます。
	  @param ev [in]
	  	交差を求める対象になる CdDcdZone オブジェクトを指定してください。
	  @return
	  	この範囲と、ev とが交差している領域を返します。
	    - this か ev のいずれかの Size が０であれば、起点がthisと同じ、
	  	サイズが０のオブジェクトを返します。
	    - thisとevの符号が異なる場合は、evの方の符号を反転して、
	  	交差範囲を求めます。この場合、戻り値の符号は
	  	thisと同じ方向になります。
	    - this と ev に交差している領域がない場合は、起点がthisと同じ、
	  	サイズが０のオブジェクトを返します。
	 */
	CdDcdZone CrossZone( const CdDcdZone& ev )const{
		//	this か ev のいずれかの Size が０であれば、起点がthisと同じ、
		//	サイズが０のオブジェクトを返します。
		if ( getSizeSign() == 0 || ev.getSizeSign() == 0 ){
			return ( CdDcdZone( m_iPos , 0 ) ) ;
		}	
		
		//	サイズの符号が異なる場合は、引数の方の符号を反転します。
		CdDcdZone	aZone( ev ) ;
		if ( getSizeSign() == -aZone.getSizeSign() ){
			aZone.setSizeSign( -aZone.getSizeSign() ) ;
		}
		
		//	符号が正方向の場合
		if ( getSizeSign() == 1 )
		{
			DcdPos	aPos = m_iPos ;
			if ( m_iPos < aZone.m_iPos ){
				aPos = aZone.m_iPos ;
			}
			DcdPos	aEndPos = getEndPos() ;
			if ( getEndPos() > aZone.getEndPos() ){
				aEndPos = aZone.getEndPos() ;
			}
			if ( aPos <= aEndPos ){
				return ( CdDcdZone( aPos , aEndPos - aPos ) ) ;
			}
			return ( CdDcdZone( m_iPos , 0 ) ) ;
		}
		
		//	符号が負方向の場合
			DcdPos	aPos = m_iPos ;
			if ( m_iPos > aZone.m_iPos ){
				aPos = aZone.m_iPos ;
			}
			DcdPos	aEndPos = getEndPos() ;
			if ( getEndPos() < aZone.getEndPos() ){
				aEndPos = aZone.getEndPos() ;
			}
			if ( aPos >= aEndPos ){
				return ( CdDcdZone( aPos , aEndPos - aPos ) ) ;
			}
			return ( CdDcdZone( m_iPos , 0 ) ) ;
	};
	
	/**
	  	この範囲と、指定された別の範囲を含む、
		最も小さい範囲を求めます。
	  @param ev [in]
	  	包含を求める対象になる CdDcdZone オブジェクトを指定してください。
	  @return
	  	この範囲と、ev を包含する領域を返します。
	    - thisとevの符号が異なる場合は、evの方の符号を反転して、
	  	交差範囲を求めます。この場合、戻り値の符号は
	  	thisと同じ方向になります。
	 */
	CdDcdZone ZoneOr( const CdDcdZone& ev )const{
		CdDcdZone	zoneRv ;

		//	サイズの符号が異なる場合は、引数の方の符号を反転します。
		CdDcdZone	aZone( ev ) ;
		if ( getSizeSign() == -aZone.getSizeSign() ){
			aZone.setSizeSign( -aZone.getSizeSign() ) ;
		}


		//	符号が0か正方向の場合
		if ( getSizeSign() >= 0 )
		{
			//	aPos は、m_iPosの0に近いほうとします。
			DcdPos	aPos = m_iPos ;
			if ( m_iPos > aZone.m_iPos ){
				aPos = aZone.m_iPos ;
			}
			//	aEndPos は、getEndPos() の0から遠い方。
			DcdPos	aEndPos = getEndPos() ;
			if ( getEndPos() < aZone.getEndPos() ){
				aEndPos = aZone.getEndPos() ;
			}

			zoneRv.setBeginEndPos( aPos , aEndPos ) ;
		}
		//	符号が負方向の場合
		else
		{
			//	aPos は、m_iPosの0に近いほうとします。
			DcdPos	aPos = m_iPos ;
			if ( m_iPos < aZone.m_iPos ){
				aPos = aZone.m_iPos ;
			}
			//	aEndPos は、getEndPos() の0から遠い方。
			DcdPos	aEndPos = getEndPos() ;
			if ( getEndPos() > aZone.getEndPos() ){
				aEndPos = aZone.getEndPos() ;
			}

			zoneRv.setBeginEndPos( aPos , aEndPos ) ;
		}
		return ( zoneRv ) ;
	};



	/**
	 	指定の位置がこの範囲に含まれているかどうかを判断します。
	 @param ev [in]
	 	判定する位置を指定してください。
	 @return
	 	位置がこの範囲に含まれていれば真です。
	*/
	bool IsInner( DcdPos ev )const{	
		if ( getSizeSign() == -1 ){
			return ( m_iPos >= ev && ev > getEndPos() ) ;
		}
		return ( m_iPos <= ev && ev < getEndPos() ) ;
	};
	
	/**
	 	指定の範囲がこの範囲に含まれているかどうかを判断します。
	 @param ev [in]
	 	判定する位置を指定してください。
	 @return
	 	位置がこの範囲に含まれていれば真です。
	*/
	bool IsInner( CdDcdZone& ev )const{	
		CdDcdZone	aZone( ev ) ;
		aZone.setSizeSign( getSizeSign() ) ;
		if ( CrossZone( aZone ).IsEqualTo( aZone ) ){
			return ( true ) ;
		}
		return ( false ) ;
	};
	///@}
	// ********************************
	///@name	演算子	
	// ********************************
	///@{
	/// IsEqualTo() として動作します。
	bool operator ==( const CdDcdZone& ev )const{	
		return (  IsEqualTo( ev ) ) ; 
	};
	/// IsEqualTo() として動作します。
	bool operator !=( const CdDcdZone& ev )const{
		return ( !IsEqualTo( ev ) ) ; 
	};
	///@}
	
};


#endif /*CdDcdZone_h*/
