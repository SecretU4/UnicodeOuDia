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
//	CdDedDispProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDedDispProp_h
#define  CdDedDispProp_h

#include "DcDraw/CdFontProp.h"

// ****************************************************************
//	CdDedDispProp
// ****************************************************************
/**
 * @brief
 *	【概要】  DiagramEdit の表示に関係するプロパティを保持する
 *	単純データクラスです。
 */
class CdDedDispProp
{
// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 *	 時刻表画面フォント。
	 *	規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropJikokuhyouFont ;

	/**
	 *	 ダイヤ画面駅名フォント。
	 *	規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropDiaEkimeiFont ;

	/**
	 *	 ダイヤ画面時刻フォント。
	 *	規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropDiaJikokuFont ;

	/**
	 *	 ダイヤ画面列車フォント。
	 *	規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropDiaRessyaFont ;

	/**
	 *	 コメントビューフォント。
	 *	規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropViewComment ;

	/**
	 *	 ダイヤ画面文字色。
	 *	規定値は、黒。
	 */
	COLORREF	m_colorDiaMojiColor ;
	/**
	 *	 ダイヤ画面背景色。
	 *	規定値は、白。
	 */
	COLORREF	m_colorDiaHaikeiColor ;
	/**
	 *	 ダイヤ画面列車線色。
	 *	規定値は、黒。
	 */
	COLORREF	m_colorDiaRessyaColor ;
	/**
	 *	 ダイヤ画面縦横軸色。
	 *	規定値は、黒。
	 */
	COLORREF	m_colorDiaJikuColor ;

	/**
	 *	駅名欄の幅を保持します。
	 *	単位は、全角での文字数です。
	 *	つまり、駅名欄の幅は、
	 *
	 *		文字の高さ × m_iEkimeiLength 
	 *	
	 *	となります。
	 *	デフォルト値は 6 とします。最小値は 1 です。
	 */
	int m_iEkimeiLength ;

	/**
	 *	 ダイヤ画面列車情報表示位置:『駅Order』
	 *	下り列車( Ressyahoukou_Kudari )の、
	 *	列車情報を表示する位置を、『駅Order』で指定します。
	 *
	 *	但し、この値が『駅』 ( CentDedEki ) の数以上の場合は、
	 *	( 『駅』の数  - 1 ) が指定されているものとみなします。
	 *	
	 *	規定値は 0 です。
	 *	
	 * @attention
	 *	『駅Order』については、 CentDedRessya を参照してください。
	 */
	int m_iDiaRessyajouhouHyoujiEkiOrderKudari ;
	/**
	 *	上り列車( Ressyahoukou_Nobori )の、
	 *	列車情報を表示する位置を、『駅Order』で指定します。
	 * @see m_iDiaRessyajouhouHyoujiEkiOrderKudari 
	 */
	int m_iDiaRessyajouhouHyoujiEkiOrderNobori ;

///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	CdDedDispProp() :
		m_fontpropJikokuhyouFont( 9 ,"ＭＳ ゴシック"  ) ,
		m_fontpropDiaEkimeiFont( 9 ,"ＭＳ ゴシック"  ) ,
		m_fontpropDiaJikokuFont( 9 ,"ＭＳ ゴシック"  ) ,
		m_fontpropDiaRessyaFont( 9 ,"ＭＳ ゴシック"  ) ,
		m_fontpropViewComment( 9 ,"ＭＳ ゴシック"  ) ,
		m_colorDiaMojiColor( RGB( 0 , 0 , 0 ) ) ,
		m_colorDiaHaikeiColor( RGB( 255 , 255 , 255 ) ) ,
		m_colorDiaRessyaColor( RGB( 0 , 0 , 0 ) ) ,
		m_colorDiaJikuColor( RGB(192 , 192 , 192 ) ) ,
		m_iEkimeiLength( 6 ) ,
		m_iDiaRessyajouhouHyoujiEkiOrderKudari( 0 ) ,
		m_iDiaRessyajouhouHyoujiEkiOrderNobori( 0 ) {};
	
	
// ********************************
//	CdDedDispProp
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	CdFontProp	getJikokuhyouFont()const{
		return 	m_fontpropJikokuhyouFont ;};
	CdDedDispProp& setJikokuhyouFont( const CdFontProp& value ){
		m_fontpropJikokuhyouFont = value ; return *this ;};
	CdFontProp	getDiaEkimeiFont()const{
		return 	m_fontpropDiaEkimeiFont ;};
	CdDedDispProp& setDiaEkimeiFont( const CdFontProp& value ){
		m_fontpropDiaEkimeiFont = value ; return *this ;};
	CdFontProp	getDiaJikokuFont()const{
		return 	m_fontpropDiaJikokuFont ;};
	CdDedDispProp& setDiaJikokuFont( const CdFontProp& value ){
		m_fontpropDiaJikokuFont = value ; return *this ;};
	CdFontProp	getDiaRessyaFont()const{
		return 	m_fontpropDiaRessyaFont ;};
	CdDedDispProp& setDiaRessyaFont( const CdFontProp& value ){
		m_fontpropDiaRessyaFont = value ; return *this ;
	};
	CdFontProp	getViewCommentFont()const{	return m_fontpropViewComment ;};
	CdDedDispProp& setViewCommentFont( const CdFontProp& value ){
		m_fontpropViewComment = value ; return *this ; 
	};


		
	COLORREF	getDiaMojiColor()const{
		return m_colorDiaMojiColor ;};
	CdDedDispProp& setDiaMojiColor( COLORREF value ){
		m_colorDiaMojiColor = value ; return *this ;};
	COLORREF	getDiaHaikeiColor()const{
		return m_colorDiaHaikeiColor ;};
	CdDedDispProp& setDiaHaikeiColor( COLORREF value ){
		m_colorDiaHaikeiColor = value ; return *this ;};
	COLORREF	getDiaRessyaColor()const{
		return m_colorDiaRessyaColor ;};
	CdDedDispProp& setDiaRessyaColor( COLORREF value ){
		m_colorDiaRessyaColor = value ; return *this ;};
	COLORREF	getDiaJikuColor()const{
		return m_colorDiaJikuColor ;};
	CdDedDispProp& setDiaJikuColor( COLORREF value ){
		m_colorDiaJikuColor = value ; return *this ;};

	int getEkimeiLength()const{ return m_iEkimeiLength ;};
	CdDedDispProp& setEkimeiLength( int value ){
		m_iEkimeiLength = value ;
		if ( m_iEkimeiLength < 1 ){
			m_iEkimeiLength = 1 ;
		}
		if ( m_iEkimeiLength > 20 ){
			m_iEkimeiLength = 20 ;
		}
		return *this ;
	};

	/**
	 * @return
	 *	駅名の幅を取得するための文字列を作成します。
	 *	この関数は、全角文字を m_iEkimeiLength 文字並べた
	 *	文字列（内容は使わない）を返します。
	 */
	string createEkimeiExtentString()const 
	{
		string	strRv ;
		for ( int idx = 0 ; idx < m_iEkimeiLength ; idx ++ ){
			strRv += "岡" ;
		}
		return strRv ;
	};
	

	
	int getDiaRessyajouhouHyoujiEkiOrder( ERessyahoukou eRessyahoukou )const{
		if ( eRessyahoukou == Ressyahoukou_Kudari ){
			return m_iDiaRessyajouhouHyoujiEkiOrderKudari ;
		}
		return m_iDiaRessyajouhouHyoujiEkiOrderNobori ;
	};
	CdDedDispProp& setDiaRessyajouhouHyoujiEkiOrder( 
		 ERessyahoukou eRessyahoukou , int value ){
		if ( eRessyahoukou == Ressyahoukou_Kudari ){
			m_iDiaRessyajouhouHyoujiEkiOrderKudari = value ;
		}	else	{
			m_iDiaRessyajouhouHyoujiEkiOrderNobori = value ;
		}
		return *this ;
	};

	/**
	 *	すべての属性を、
	 *	初期状態（デフォルトコンストラクタで生成した状態）
	 *	にします。
	 */
	void clear(){	*this = CdDedDispProp() ; } ;
	///@}
};
#endif /*CdDedDispProp_h*/


