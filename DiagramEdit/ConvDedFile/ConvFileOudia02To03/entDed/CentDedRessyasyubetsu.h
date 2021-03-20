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
//	CentDedRessyasyubetsu.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessyasyubetsu_h
#define  CentDedRessyasyubetsu_h

#include <string>
using namespace std ;

#include <windows.h>

// ****************************************************************
//	CentDedRessyasyubetsu
// ****************************************************************
/**
 * @brief
 *	【概要】  DiagramEdit の、路線上で運行される列車の『列車種別』
 *	１種類を表します。
 *	
 *	  属性として、『種別名』と、その列車種別を表示する時刻表ビュー・
 *	ダイヤグラムビューでの描画色・線スタイルを保持します。
 */
class CentDedRessyasyubetsu
{
// ********************************
//	インナータイプ
// ********************************
 public:
	/**
	 *	線(直線)の形状を表す列挙です。
	 */
	enum ESenStyle
	{
		/** 実線 */
		SenStyle_Jissen = 0 ,
		/** 破線 */
		SenStyle_Hasen ,
		/** 点線 */
		SenStyle_Tensen ,
		/** 一点鎖線 */
		SenStyle_Ittensasen ,
	};
	
// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 *	種別名。
	 *
	 *	規定値は、空文字列。
	 *
	 *	この値が空文字列の場合、このオブジェクトは無効です。
	 */
	string	m_strSyubetsumei ;
	
	/**
	 *	略称（種別名の略称）。
	 *
	 *	規定値は、空文字列。
	 */
	string	m_strRyakusyou ;
	
	/**
	 *	時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)
	 *
	 *	規定値は、黒。
	 */
	COLORREF	m_colorJikokuhyouMojiColor ;
	
	/**
	 *	ダイヤグラムの線色。
	 *
	 *	規定値は、黒。
	 */
	COLORREF	m_colorDiagramSenColor ;

	/**
	 *	ダイヤグラムの線スタイル。
	 *
	 *	規定値は、 SenStyle_Jissen
	 */
	ESenStyle	m_eDiagramSenStyle ;
	
	/**
	 *	ダイヤグラムの線の太さ。
	 *
	 *	ダイヤグラムの線が太線であれば true。
	 *	細線なら false です。
	 *
	 *	規定値は、 false です。
	 */
	bool m_bDiagramSenIsBold ;
///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param strSyubetsumei [in]
	 *	種別名。
	 * @param strRyakusyou [in]
	 *	略称（種別名の略称）。
	 * @param colorJikokuhyouMojiColor [in]
	 *	時刻表文字色。
	 * @param colorDiagramSenColor [in] 
	 *	ダイヤグラムの線色。
	 * @param eDiagramSenStyle [in]
	 *	ダイヤグラムの線スタイル。
	 * @param bDiagramSenIsBold [in]
	 *	ダイヤグラムの線の太さ。
	 *	ダイヤグラムの線が太線であれば true。
	 *	細線なら false です。
	 */
	CentDedRessyasyubetsu( 
			const string& strSyubetsumei ,
			const string& strRyakusyou ,
			COLORREF	colorJikokuhyouMojiColor = RGB( 0 , 0 ,0 ), 
			COLORREF	colorDiagramSenColor = RGB( 0 , 0 , 0 ),
			ESenStyle	eDiagramSenStyle = SenStyle_Jissen ,
			bool bDiagramSenIsBold = false ) :
		m_strSyubetsumei( strSyubetsumei ) ,
		m_strRyakusyou( strRyakusyou ) ,
		m_colorJikokuhyouMojiColor( colorJikokuhyouMojiColor ) , 
		m_colorDiagramSenColor( colorDiagramSenColor ) ,
		m_eDiagramSenStyle( eDiagramSenStyle ) ,
		m_bDiagramSenIsBold( bDiagramSenIsBold ){};

	CentDedRessyasyubetsu() :
		m_colorJikokuhyouMojiColor( RGB( 0 , 0 , 0 ) ) , 
		m_colorDiagramSenColor( RGB( 0 , 0 , 0  ) ) ,
		m_eDiagramSenStyle( SenStyle_Jissen ) ,
		m_bDiagramSenIsBold( false ){};



// ********************************
//	CentDedRessyasyubetsu
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	string	getSyubetsumei()const{	return 	m_strSyubetsumei ;};
	CentDedRessyasyubetsu& setSyubetsumei( const string& value ){
		m_strSyubetsumei = value ; return *this ; } ;

	string	getRyakusyou()const{	return m_strRyakusyou ;};
	CentDedRessyasyubetsu& setRyakusyou( const string& value ){
		m_strRyakusyou = value ; return *this ; } ;
	
	COLORREF	getJikokuhyouMojiColor()const{
		return m_colorJikokuhyouMojiColor ;};
	CentDedRessyasyubetsu& setJikokuhyouMojiColor( COLORREF	value ){
		m_colorJikokuhyouMojiColor = value ; return *this ; } ;
	COLORREF	getDiagramSenColor()const{
		return 	m_colorDiagramSenColor ;};
	CentDedRessyasyubetsu& setDiagramSenColor( COLORREF	value ){
		m_colorDiagramSenColor = value ; return *this ; } ;

	ESenStyle	getDiagramSenStyle()const{	return m_eDiagramSenStyle ;};
	CentDedRessyasyubetsu& setDiagramSenStyle( ESenStyle value ){
		m_eDiagramSenStyle = value ; return *this ;};
	bool getDiagramSenIsBold()const{ return m_bDiagramSenIsBold ; };
	CentDedRessyasyubetsu& setDiagramSenIsBold( bool value ){
		m_bDiagramSenIsBold = value ; return *this ;};


	///@}

	// ********************************
	///@name 操作
	// ********************************
	///@{

	///@}
};


#endif /*CentDedRessyasyubetsu_h*/


