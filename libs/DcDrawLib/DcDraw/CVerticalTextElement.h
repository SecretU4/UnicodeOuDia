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
//	CVerticalTextElement.h
// ****************************************************************
*/
/** @file */
#ifndef  DcDrawLib_DcDraw_CVerticalTextElement_h
#define  DcDrawLib_DcDraw_CVerticalTextElement_h
#include <string>

namespace DcDrawLib{
namespace DcDraw{

/**
@brief
	縦書きテキストを構成する要素を表す、単純データクラスです。
	
	CVerticalTextElementBuilder::scan() メソッドは、文字列を解析し、
	解析結果を CVerticalTextElement のコンテナとして構成します。

	このクラスは NULL 状態を持ちます。
	m_strString が空文字列のときに、NULL状態となります。
*/
class CVerticalTextElement
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	/**
	  	『文字列要素』の種類
	 */
	enum EType
	{
		/**
		  	縦書きフォントを使って描画する、連続した全角文字
		 */
		V_ZENKAKU ,	
		/**
		    縦書きフォントを使って描画する、連続した半角文字
		 */
		V_HANKAKU ,
		/**
		  	横書きフォントを使って描画する、１・２文字の半角数字
		  	（この前後に半角文字がないこと）
		 */
		H_HANKAKU , 
	};
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	  	文字列要素に含まれる部分文字列。
	 */
	 std::string m_strString ;
	
	/**
	  	『文字列要素』の種類
	 */
	EType	m_eType ;
	
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	   @param strBubunMojiretsu [in]
	  	文字列要素に含まれる部分文字列。
	   @param eType [in]
	  	『文字列要素』の種類
	 */
	CVerticalTextElement( 
		const std::string& strBubunMojiretsu ,
		EType	eType ) :
		m_strString( strBubunMojiretsu ) ,
		m_eType( eType ){};

	CVerticalTextElement() :
		m_eType( V_ZENKAKU ){};
public:
	// ********************************
	///@name CVerticalTextElement-属性
	// ********************************
	///@{
	std::string getString()const{ return m_strString ;};
	CVerticalTextElement& setString( const std::string& value )
	{	m_strString = value ;	return *this ; };
	EType	getType()const{ return m_eType ;};
	CVerticalTextElement& setType( EType value )
	{ m_eType = value ;	return *this ; };

	/**
	@return
		this がNull状態なら、trueを返します。
	*/
	bool isNull()const{	return m_strString.empty() ;};

	///@}
};


} //namespace DcDraw
} //namespace DcDrawLib


#endif /*DcDrawLib_DcDraw_CVerticalTextElement_h*/
