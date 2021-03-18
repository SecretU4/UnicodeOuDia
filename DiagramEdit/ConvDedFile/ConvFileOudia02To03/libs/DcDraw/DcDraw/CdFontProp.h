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
//	CdFontProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdFontProp_h
#include <string>
using namespace std ;

// ****************************************************************
//	CdFontProp
// ****************************************************************
/**
* @brief
* 【概要】
* 	フォントの属性のデータを保持する、単純データクラスです。
*/
class CdFontProp
{
// ********************************
/// @name	属性
// ********************************
///@{
 private:
	/**
	 * 	フォントの文字の高さです。単位はポイント単位(point*72=twip)です。
	 * 	この値が無効なときは、０になります。
	 *
	 *	デフォルトは0です。
	 * @attention
	 *	LogicalunitTextHeight・LogicalunitCellHeight・PointTextHeight
	 *	は、相互に排他的です。有効になるのは、いずれか１つだけです。
	 */
	int		m_iPointTextHeight ;
	
	/**
	 * 	フォントの文字の高さです。単位は論理単位です。
	 * 	この値が無効なときは、０になります。
	 *
	 *	デフォルトは0です。
	 * @attention
	 *	LogicalunitTextHeight・LogicalunitCellHeight・PointTextHeight
	 *	は、相互に排他的です。有効になるのは、いずれか１つだけです。
	 */
	int		m_iLogicalunitTextHeight ;
	
	/**
	 * 	フォントのセルの高さです。単位は論理単位です。
	 * 	この値が無効なときは、０になります。
	 *
	 *	デフォルトは0です。
	 * @attention
	 *	LogicalunitTextHeight・LogicalunitCellHeight・PointTextHeight
	 *	は、相互に排他的です。有効になるのは、いずれか１つだけです。
	 */
	int		m_iLogicalunitCellHeight ;
	
	/**
	 * 	書体名の文字列です。
	 * (例)"ＭＳ  ゴシック"
	 *
	 *	デフォルトは、空文字列です。最低限設定の必要な属性です。
	 */
	string	m_strFacename ;
	
	/**	
	 *	通常は偽、太字なら真です。	
	 */
	bool	m_bBold ;
	
	/**	
	 *	通常は偽、斜体なら真です。
	 */
	bool	m_bItaric ;
	
	/**	
	 *	通常は偽、下線があれば真です。	
	 */
	bool	m_bUnderine ;
	
	/**	
	 *	通常は偽、打ち消し線あれば真です。	
	 */
	bool	m_bStrikeOut ;

	
	/**
	 *	このフォントで表示される各テキスト行の角度 
	 *	(ページの最下部からの相対角度) を､ 
	 *	10分の1度単位で指定します。
	 *
	 *	既定値は 0 です。
	 *	縦書きフォントを使用する場合は、通常は 2700 とします。
	 */
	int m_iEscapement ;
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 *	ポイント単位の文字の高さと書体名を基本にしたフォント属性を指定する
	 *	コンストラクタです。
	 * @param iPointTextHeight [in]
	 * 	フォントの文字の高さです。単位はポイント単位(point*72=twip)です。
	 * @param strFacename [in]
	 * 	書体名の文字列です。
	 * (例)"ＭＳ  ゴシック"
	 * @param bBold [in]
	 *	通常は偽、太字なら真です。	
	 * @param bItaric [in]
	 *	通常は偽、斜体なら真です。
	 * @param bUnderine [in]
	 *	通常は偽、下線があれば真です。	
	 * @param bStrikeOut [in]
	 *	通常は偽、打ち消し線あれば真です。	
	 */
	CdFontProp( int iPointTextHeight , const string& strFacename ,
		bool bBold = false , bool bItaric = false , 
		bool bUnderine = false , bool bStrikeOut = false ):
		m_iPointTextHeight( iPointTextHeight ) ,
		m_iLogicalunitTextHeight( 0 ) ,
		m_iLogicalunitCellHeight( 0 ) ,
		m_strFacename( strFacename ) ,
		m_bBold( bBold ) ,
		m_bItaric( bItaric ) ,
		m_bUnderine( bUnderine ) ,
		m_bStrikeOut( bStrikeOut ) , 
		m_iEscapement( 0 ) {};
	
	/**
	 *	デフォルトコンストラクタ。
	 *	このコンストラクタでは、有効なフォント属性は設定されません。
	 */
	CdFontProp() : 
		m_iPointTextHeight( 0 ) ,
		m_iLogicalunitTextHeight( 0 ) ,
		m_iLogicalunitCellHeight( 0 ) ,
		m_bBold( false ) ,
		m_bItaric( false ) ,
		m_bUnderine( false ) ,
		m_bStrikeOut( false ) , 
		m_iEscapement( 0 ) {};
	
	virtual ~CdFontProp(){} ;

// ********************************
//	CdFontProp
// ********************************
 public:
	// ********************************
	/// @name	属性
	// ********************************
	///@{
	int getPointTextHeight()const{	
		return m_iPointTextHeight ;};
	CdFontProp& setPointTextHeight( int ev ){
		m_iPointTextHeight = ev ;
		m_iLogicalunitTextHeight = 0 ;
		m_iLogicalunitCellHeight = 0 ;
		return *this ;
	};
	
	int getLogicalunitTextHeight()const{	
		return m_iLogicalunitTextHeight ;};
	CdFontProp& setLogicalunitTextHeight( int ev ){
		m_iPointTextHeight = 0 ;
		m_iLogicalunitTextHeight = ev ;
		m_iLogicalunitCellHeight = 0 ;
		return *this ;
	};
	
	int getLogicalunitCellHeight()const{	
		return m_iLogicalunitCellHeight ;};
	CdFontProp& setLogicalunitCellHeight( int ev ){
		m_iPointTextHeight = 0 ;
		m_iLogicalunitTextHeight = 0 ;
		m_iLogicalunitCellHeight = ev ;
		return *this ;
	};
	
	string	getFacename()const{	return m_strFacename ;	};
	CdFontProp& setFacename( const string& ev ){
		m_strFacename = ev ;	return *this ; } ;
	
	bool	getBold()const{
		return m_bBold ;	};
	CdFontProp& setBold( bool ev ){
		m_bBold = ev ;	return *this ; } ;
	bool	getItaric()const{
		return m_bItaric ;	};
	CdFontProp& setItaric( bool ev ){
		m_bItaric = ev ;	return *this ; } ;
	bool	getUnderine()const{
		return m_bUnderine ;	};
	CdFontProp& setUnderine( bool ev ){
		m_bUnderine = ev ;	return *this ; } ;
	bool	getStrikeOut()const{
		return m_bStrikeOut ;	};
	CdFontProp& setStrikeOut( bool ev ){
		m_bStrikeOut = ev ;	return *this ; } ;
	int getEscapement()const{
		return m_iEscapement ;};
	CdFontProp&  setEscapement( int value ){
		m_iEscapement = value ; return *this ; } ;

	/**
	 *	このフォントで表示される各テキスト行の角度を 
	 *	横書き用に設定します。
	 *	つまり、 m_iEscapement を 0 にします。
	 */
	CdFontProp&  setIsEscapementHolyzontal(){
		m_iEscapement = 0 ; return *this ; } ;

	/**
	 *	このフォントで表示される各テキスト行の角度を 
	 *	縦書き用に設定します。
	 *	つまり、 m_iEscapement を 2700 にします。
	 */
	CdFontProp&  setIsEscapementVertical(){
		m_iEscapement = 2700 ; return *this ; } ;


	/**
	 * @return
	 *	このフォントで表示される各テキスト行の角度が 
	 *	横書き用に設定されていたら
	 *	（ m_iEscapement が 0 なら）真です。
	 */
	bool getIsEscapementHolyzontal()const{
		return m_iEscapement == 0 ; } ;

	/**
	 * @return
	 *	このフォントで表示される各テキスト行の角度が 
	 *	縦書き用に設定されていたら
	 *	（ m_iEscapement が 2700 なら）真です。
	 */
	bool getIsEscapementVertical()const{
		return m_iEscapement == 2700 ; } ;



	/**
	 *	2つのオブジェクトの各属性が等しいかどうかを判定します。
	 * @param value [in]
	 *	比較の対象となるオブジェクトを指定してください。
	 * @return 
	 *	value と *this との間で、すべての属性が等しければ真です。
	 */
	bool isEqualTo( const CdFontProp& value )const{
		return ( 
			m_iPointTextHeight == value.m_iPointTextHeight && 
			m_iLogicalunitTextHeight == value.m_iLogicalunitTextHeight && 
			m_iLogicalunitCellHeight == value.m_iLogicalunitCellHeight && 
			m_strFacename == value.m_strFacename &&
			m_bBold == value.m_bBold && 
			m_bItaric == value.m_bItaric &&
			m_bUnderine == value.m_bUnderine && 
			m_bStrikeOut == value.m_bStrikeOut &&  
			m_iEscapement == value.m_iEscapement ) ;
	} ;
	/**
	 *	isEqualTo() と等価です。
	 */
	bool operator==( const CdFontProp& value )const{
		return ( isEqualTo( value ) ) ;
	};
	bool operator!=( const CdFontProp& value )const{
		return ( !isEqualTo( value ) ) ;
	};

	/**
	 *	this が b より
	 *	小さい（順序が前になる）なら真です。
	 * @param b [in]
	 *	比較の対象となるオブジェクトを指定してください。
	 * @return 
	 *	this が b より
	 *	小さい（順序が前になる）なら真です。
	 */
	bool  less( const CdFontProp& b )const{
			if ( this->m_iPointTextHeight != b.m_iPointTextHeight ){
				return ( this->m_iPointTextHeight < b.m_iPointTextHeight ) ;
			}	else if ( this->m_iLogicalunitTextHeight != 
					b.m_iLogicalunitTextHeight ){
				return ( this->m_iLogicalunitTextHeight < 
					b.m_iLogicalunitTextHeight ) ;
			}	else if ( this->m_iLogicalunitCellHeight != 
					b.m_iLogicalunitCellHeight ){
				return ( this->m_iLogicalunitCellHeight < 
					b.m_iLogicalunitCellHeight ) ;
			}	else if ( this->m_strFacename != b.m_strFacename ){
				return ( this->m_strFacename < b.m_strFacename ) ;
			}	else if ( this->m_bBold != b.m_bBold ){
				return ( this->m_bBold < b.m_bBold ) ;
			}	else if ( this->m_bItaric != b.m_bItaric ){
				return ( this->m_bItaric < b.m_bItaric ) ;
			}	else if ( this->m_bUnderine != b.m_bUnderine ){
				return ( this->m_bUnderine < b.m_bUnderine ) ;
			}	else if ( this->m_bStrikeOut != b.m_bStrikeOut ){
				return ( this->m_bStrikeOut < b.m_bStrikeOut ) ;
			}	else if ( this->m_iEscapement != b.m_iEscapement ){
				return ( this->m_iEscapement < b.m_iEscapement ) ;
			}
			return ( false ) ;		
	};
	/**
	 *	less() と等価です。
	 */
	bool operator<( const CdFontProp& b )const{
		return less( b );
	};
	///@}

};




#define  CdFontProp_h
#endif /*CdFontProp_h*/

