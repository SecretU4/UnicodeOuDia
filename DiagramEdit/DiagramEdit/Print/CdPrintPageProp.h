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
//	CdPrintPageProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdPrintPageProp_h
#define  CdPrintPageProp_h

#include <string>

namespace Print{

// ****************************************************************
//	CdPrintPageProp
// ****************************************************************
/**
 *	@brief
 *	【概要】  単純データクラスです。
 *	  印刷ページに関するプロパティを保持します。
 *	
 *	  属性として、
 *	- 余白（上下左右）
 *	を保持します。
 */
class CdPrintPageProp
{
// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 *	ページの余白（左）
	 *	単位は mm 。
	 */
	double m_dMarginLeftMm ;
	/**
	 *	ページの余白（上）
	 *	単位は mm 。
	 */
	double m_dMarginTopMm ;
	/**
	 *	ページの余白（右）
	 *	単位は mm 。
	 */
	double m_dMarginRightMm ;
	/**
	 *	ページの余白（下）
	 *	単位は mm 。
	 */
	double m_dMarginBottomMm ;
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param dMarginLeftMm [in]
	 *	ページの余白（左）
	 *	単位は mm 。
	 * @param dMarginTopMm [in]
	 *	ページの余白（上）
	 *	単位は mm 。
	 * @param dMarginRightMm [in]
	 *	ページの余白（右）
	 *	単位は mm 。
	 * @param dMarginBottomMm [in]
	 *	ページの余白（下）
	 *	単位は mm 。
	 */
	CdPrintPageProp( 
		double dMarginLeftMm ,
		double dMarginTopMm ,
		double dMarginRightMm ,
		double dMarginBottomMm ) :
		m_dMarginLeftMm( dMarginLeftMm ),
		m_dMarginTopMm( dMarginTopMm ),
		m_dMarginRightMm( dMarginRightMm ),
		m_dMarginBottomMm( dMarginBottomMm ){};

	CdPrintPageProp( ) :
		m_dMarginLeftMm( 0 ),
		m_dMarginTopMm( 0 ),
		m_dMarginRightMm( 0 ),
		m_dMarginBottomMm( 0 ){};

// ********************************
//	CdPrintPageProp
// ********************************
 public:
	// ********************************
	///@name CdPrintPageProp-属性
	// ********************************
	///@{
	double getMarginLeftMm()const{ return m_dMarginLeftMm ;};
	CdPrintPageProp& setMarginLeftMm( double value ){
		m_dMarginLeftMm = value ; return *this ; } ;
	double getMarginTopMm()const{ return m_dMarginTopMm ;};
	CdPrintPageProp& setMarginTopMm( double value ){
		m_dMarginTopMm = value ; return *this ; } ;
	double getMarginRightMm()const{ 
		return m_dMarginRightMm ;};
	CdPrintPageProp& setMarginRightMm( double value ){
		m_dMarginRightMm = value ; return *this ; } ;
	double getMarginBottomMm()const{
		return m_dMarginBottomMm ;};
	CdPrintPageProp& setMarginBottomMm( double value ){
		m_dMarginBottomMm = value ; return *this ; } ;
	///@}
	// ********************************
	///@name CdPrintPageProp-操作
	// ********************************
	///@{
	/**
	 * @return
	 *	このオブジェクトが保持している属性を文字列化します。
	 */
	std::string encode() ;
	/**
	 *	encode() で生成した文字列を解釈して、thisの属性に反映します。
	 * @param value [in]
	 *	encode() で生成した文字列を指定してください。
	 * @return 
	 *	成功したら 0 以上、エラーなら負の数です。
	 */
	int decode( const std::string& value ) ;
		
	/**
	 *	このオブジェクトの属性を、デフォルトコンストラクタで
	 *	生成した状態に戻します。
	 */
	void clear(){	*this = CdPrintPageProp() ;};
		
};

} //namespace Print

#endif /*CdPrintPageProp_h*/
