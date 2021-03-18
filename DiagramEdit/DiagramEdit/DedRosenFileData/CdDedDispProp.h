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

#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcdCd\DcDrawProp\CdColorProp.h"

#include "entDed\CentDed.h"
#include "entDed\CentDedRessyasyubetsu.h"

namespace DedRosenFileData{
	using namespace DcDrawLib::DcdCd::DcDrawProp;
// ****************************************************************
//	CdDedDispProp
// ****************************************************************
/**
  @brief
 	【概要】  DiagramEdit の表示に関係するプロパティを保持する
 	単純データクラスです。
 */
class CdDedDispProp
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		 時刻表画面・横書きフォント。

		規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
		加えて以下の属性が追加されます。
		- [1]はBold
		- [2]はItaric
		- [3] は Bold | Itaric 
	 */
	CdFontProp	m_arJikokuhyouFont[entDed::CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT] ;

	/**
		 時刻表画面・縦書きフォント。

		規定値は、	CdFontProp( 9 ,"@ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropJikokuhyouVFont ;

	/**
		 ダイヤ画面駅名フォント。
		規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropDiaEkimeiFont ;

	/**
		 ダイヤ画面時刻フォント。
		規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropDiaJikokuFont ;

	/**
		 ダイヤ画面列車フォント。
		規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropDiaRessyaFont ;

	/**
		 コメントビューフォント。
		規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。
	 */
	CdFontProp	m_fontpropViewComment ;

	/**
		 ダイヤ画面文字色。
		規定値は、黒。
	 */
	CdColorProp	m_colorDiaMojiColor ;
	/**
		 ダイヤ画面背景色。
		規定値は、白。
	 */
	CdColorProp	m_colorDiaHaikeiColor ;

	/**
		 ダイヤ画面列車線色。
		規定値は、黒。

	@todo
	 このフィールドは、ファイルフォーマット改訂時に廃止します。
	*/
	CdColorProp	m_colorDiaRessyaColor ;

	/**
		 ダイヤ画面縦横軸色。
		規定値は、黒。
	 */
	CdColorProp	m_colorDiaJikuColor ;

	/**
		駅名欄の幅を保持します。
		単位は、全角での文字数です。
		つまり、駅名欄の幅は、
	
			文字の高さ × m_iEkimeiLength 
		
		となります。
		デフォルト値は 6 とします。最小値は 1・最大値は29(半角なら58) です。
	 */
	int m_iEkimeiLength ;

	/**
		時刻表ビューの、列車欄の幅を保持します。
		単位は、半角での文字数です。

		列車欄の幅は、 文字の高さ×m_iJikokuhyouRessyaWidth / 2 となります。

		規定値は 5 とします。最小値は 4,最大値は8です。
	*/
	int m_iJikokuhyouRessyaWidth ;


	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CdDedDispProp() ;
	
	
public:
	// ********************************
	///@name CdDedDispProp-属性
	// ********************************
	///@{
	/**
	@param idx [in]
		インデクスを指定してください。
		範囲は、 0 以上、 JIKOKUHYOUFONT_COUNT 未満です。
	*/
	CdFontProp	getJikokuhyouFont( int idx )const;

	/**
	@param idx [in]
		インデクスを指定してください。
		範囲は、 0 以上、 JIKOKUHYOUFONT_COUNT 未満です。
	@param value [in]
		フォント属性を指定してください。
	*/
	CdDedDispProp& setJikokuhyouFont( int idx , const CdFontProp& value );

	CdFontProp	getJikokuhyouVFont()const;
	CdDedDispProp& setJikokuhyouVFont( const CdFontProp& value );

	CdFontProp	getDiaEkimeiFont()const;
	CdDedDispProp& setDiaEkimeiFont( const CdFontProp& value );
	CdFontProp	getDiaJikokuFont()const;
	CdDedDispProp& setDiaJikokuFont( const CdFontProp& value );
	CdFontProp	getDiaRessyaFont()const;
	CdDedDispProp& setDiaRessyaFont( const CdFontProp& value );
	CdFontProp	getViewCommentFont()const;
	CdDedDispProp& setViewCommentFont( const CdFontProp& value );
		
	CdColorProp	getDiaMojiColor()const;
	CdDedDispProp& setDiaMojiColor( const CdColorProp& value );
	CdColorProp	getDiaHaikeiColor()const;
	CdDedDispProp& setDiaHaikeiColor( const CdColorProp& value );
	CdColorProp	getDiaRessyaColor()const;
	CdDedDispProp& setDiaRessyaColor( const CdColorProp& value );
	CdColorProp	getDiaJikuColor()const;
	CdDedDispProp& setDiaJikuColor( const CdColorProp& value );
	
	int getEkimeiLength()const;
	CdDedDispProp& setEkimeiLength( int value );
	int getJikokuhyouRessyaWidth()const;
	CdDedDispProp& setJikokuhyouRessyaWidth( int value );
	/**
	 @return
		駅名の幅を取得するための文字列を作成します。
		この関数は、全角文字を m_iEkimeiLength 文字並べた
		文字列（内容は使わない）を返します。
	 */
	std::string createEkimeiExtentString()const ;

	/**
		すべての属性を、
		初期状態（デフォルトコンストラクタで生成した状態）
		にします。
	 */
	void clear() ;
	///@}
};

} //namespace DedRosenFileData

#endif /*CdDedDispProp_h*/


