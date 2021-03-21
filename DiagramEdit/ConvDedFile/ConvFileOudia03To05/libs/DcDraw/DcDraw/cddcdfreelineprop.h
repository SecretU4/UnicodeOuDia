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
// ****************************************************************
//	CdDcdFreeLineProp
//	$Id: cddcdfreelineprop.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
#ifndef  CdDcdFreeLineProp_h
#define  CdDcdFreeLineProp_h

#include <string>
using namespace std ;

#include "DcDraw\CdColorProp.h"

	// ****************************************************************
	//	CdDcdFreeLineProp
	// ****************************************************************
	/**
	 * @brief 
	 * 【概要】
	 *   単純データクラスです。
	 *   CDcdFreeLine クラスによる線の描画の、属性を保持します。
	 * 
	 *   属性として
	 * 
	 * - 太さ
	 * - 形状(実線・破線など)
	 * - 色
	 * 
	 * を保持します。
	 */
	class CdDcdFreeLineProp
	{
	
	// ********************************
	///@name 属性
	// ********************************
	///@{
	 private:
		/** 
		 *	論理単位で太さを表す属性です 。
		 *
		 *	デフォルトでは1です。
		 *
		 *	0 なら、何も描画しません。
		 */
		int			m_iLogicalunitWidth ;
	
		/**
		 *	ペンの色です。
		 *
		 *	デフォルトは黒です
		 */
		CdColorProp	m_colorrefColor ;
	
		/**
		 *   線の形状（点線・破線など）を指定します。
		 *
		 *	このクラスでは、点線・破線の指定は、文字列で表現します。
		 *	この文字列は、 "1" ～ "9" までの半角数字だけで構成します。
		 *	文字列内の文字は１文字ずつ意味を持ち、左から順に
		 *	「１番目の破線の長さ」・「１番目の空白の長さ」・
		 *	「２番目の破線の長さ」・「２番目の空白の長さ」の順で、破線の
		 *	構成要素を指定しています。
		 *	
		 *	空文字列の場合は、実線を表します。
		 *	
		 *	デフォルトでは実線となります。
		 */
		string	m_strLinestyle ;

	///@}
	// ********************************
	//	コンストラクタ
	// ********************************
	 public:
		/** 
		 * @param iLogicalunitWidth [in]
		 *	論理単位で太さを表す属性です 。
		 * @param colorrefColor [in]
		 *	ペンの色です。
		 *	デフォルトは黒です
		 * @param aLinestyle [in]
		 *	形状。
		 */
		CdDcdFreeLineProp( 
			int			iLogicalunitWidth ,
			CdColorProp	colorrefColor ,
			const string& aLinestyle ) :
			m_iLogicalunitWidth( iLogicalunitWidth ) ,
			m_colorrefColor( colorrefColor ) ,
			m_strLinestyle( aLinestyle ){};

		/** 
		 * @param iLogicalunitWidth [in]
		 *	論理単位で太さを表す属性です 。
		 * @param colorrefColor [in]
		 *	ペンの色です。
		 *	デフォルトは黒です
		 */
		CdDcdFreeLineProp( 
			int			iLogicalunitWidth ,
			CdColorProp	colorrefColor = CdColorProp( 0 ,0 , 0) ) :
			m_iLogicalunitWidth( iLogicalunitWidth ) ,
			m_colorrefColor( colorrefColor )
		{
		};

		CdDcdFreeLineProp() :
			m_iLogicalunitWidth( 1 ) ,
			m_colorrefColor( CdColorProp( 0 ,0 , 0 ) )
		{
		};


	// ********************************
	//	CdDcdFreeLineProp
	// ********************************
	 public:
		// ********************************
		///@name 属性
		// ********************************
		///@{
		int	getLogicalunitWidth()const{	
			return m_iLogicalunitWidth ;};
		CdDcdFreeLineProp& setLogicalunitWidth( int value ){
			m_iLogicalunitWidth = value ; return *this ;};
	
		CdColorProp	getColor()const{	return m_colorrefColor ;};
		CdDcdFreeLineProp& setColor( CdColorProp value )
		{	m_colorrefColor = value ; return *this ; } ;
		
		string getLinestyle()const{
			return m_strLinestyle ;};
		CdDcdFreeLineProp& setLinestyle( const string& value ){
			m_strLinestyle = value ; return *this ; };
		
		
		/**
		 *	m_Linestyle を、「実線」の形状に設定します。
		 */
		CdDcdFreeLineProp& setSolidLineStyle(){
			m_strLinestyle.erase() ;
			return *this ; } ;

		bool isSolidLineStyle(){
			return ( m_strLinestyle.empty() ) ;} ;
		
		/**
		 *	すべての属性を初期状態にします。
		 */
		void clear(){	*this = CdDcdFreeLineProp() ; } ;
		///@}
	};
const char LINESTYLE_SOLID[] = "" ;
const char LINESTYLE_DOT[] = "11" ;
const char LINESTYLE_DOT2[]= "22" ;
const char LINESTYLE_DASH[]= "31" ;
const char LINESTYLE_DASH_DOT[]= "3111" ;
const char LINESTYLE_DASH_DOT_DOT[]= "311111" ;

#endif //CdDcdFreeLineProp_h
