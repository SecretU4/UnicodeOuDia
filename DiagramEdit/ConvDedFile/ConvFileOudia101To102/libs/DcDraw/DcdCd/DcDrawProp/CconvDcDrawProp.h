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
//$Id: CconvDcDrawProp.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
/** @file */
#pragma once
#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcdCd\DcDrawProp\CdColorProp.h"
#include "DcdCd\DcDrawProp\CdDcdFreeLineProp.h"
#include "str\CdConnectedString2.h"

/**
	DcDrawの単純データの変換機能を提供します。
*/
class CconvDcDrawProp
{
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CconvDcDrawProp(void);
	virtual ~CconvDcDrawProp(void);

public:
	// ********************************
	///@name CdFontProp
	// ********************************
	///@{
	/**
	  	CdFontProp の属性を、 CdConnectedString2 オブジェクトに追加します。
	   @param aCdFontProp [in]
	  	変換対象となる CdFontProp を指定してください。
	   @param pCdConnectedString2 [in,out]
	  	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	  	追加します。
	  	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	  	維持します。
	   @return
	  	成功したら 0 以上、エラーなら負の数です。
	 */
	int CdFontProp_to_CdConnnectedString2( 
		const CdFontProp& aCdFontProp ,
		CdConnectedString2*	pCdConnectedString );

	/**
	  	 CdConnectedString2 オブジェクトから、
	  	 CdFontProp_to_CdConnectedString2() で追加した CdItem を読み取り、
	  	CdFontProp オブジェクトの属性に反映します。
	   @param pCdFontProp [out]
	  	この関数はこのオブジェクトの属性に、文字列の内容を反映します。
	   @param aCdConnectedString [in]
	  	 CdFontProp_to_CdConnectedString2() で追加した CdItem を持つ
	  	 CdConnectedString2 オブジェクトを指定してください。
	   @return
	  	成功したら 0 以上、エラーなら負の数です。
	  	-	-12 ;	//	PointTextHeight の値が不正
	  	-	-22 ;	//	LogicalunitTextHeight の値が不正
	  	-	-32 ;	//	LogicalunitCellHeight の値が不正
	  	-	-42 ;	//	Facename の値が不正
	  	-	-52 ;	//	Bold の値が不正
	  	-	-62 ;	//	Itaric の値が不正
	  	-	-72 ;	//	Underline の値が不正
	  	-	-82 ;	//	StrikeOut の値が不正
	  	-	-92 ;	//	Escapement の値が不正
	 */
	int CdFontProp_from_CdConnectedString2( CdFontProp* pCdFontProp ,
		const CdConnectedString2& aCdConnectedString ) ;


	/**
	  	CdFontProp の属性を、文字列に変換します。
	   @param aCdFontProp [in]
	  	変換対象となる CdFontProp を指定してください。
	   @return
	  	変換結果を返します。
	 */
	std::string CdFontProp_to_string( const CdFontProp& aCdFontProp );

	/**
	  	 CdFontProp_to_string() で作成した文字列を解釈し、
	  	CdFontProp オブジェクトの属性に反映します。
	   @param pCdFontProp [out]
	  	この関数はこのオブジェクトの属性に、文字列の内容を反映します。
	   @param aString [in]
	  	 CdFontProp_to_string() で作成した文字列を指定してください。
	   @return
	  	成功したら 0 以上、エラーなら負の数です。
	  	-	-12 ;	//	PointTextHeight の値が不正
	  	-	-22 ;	//	LogicalunitTextHeight の値が不正
	  	-	-32 ;	//	LogicalunitCellHeight の値が不正
	  	-	-42 ;	//	Facename の値が不正
	  	-	-52 ;	//	Bold の値が不正
	  	-	-62 ;	//	Itaric の値が不正
	  	-	-72 ;	//	Underline の値が不正
	  	-	-82 ;	//	StrikeOut の値が不正
	  	-	-92 ;	//	Escapement の値が不正
	 */
	int CdFontProp_from_string( 
		CdFontProp* pCdFontProp , 
		const std::string& aString  );
	///@}
	// ********************************
	///@name CdColorProp
	// ********************************
	///@{
	/**
		aCdColorProp を文字列に変換します。
	@param aCdColorProp [in]
		変換元の値を指定してください。
	@return
		変換結果を返します。
	*/
	std::string CdColorProp_to_string( const CdColorProp& aCdColorProp );

	/**
		文字列を aCdColorProp に変換します。
	@param aString [in]
		変換元の値を指定してください。
	@return
		変換結果を返します。
	 */
	CdColorProp CdColorProp_from_string( const std::string& aString  );
	///@}
	// ********************************
	///@name CdDcdFreeLineProp
	// ********************************
	///@{
	/**
	  	CdDcdFreeLineProp の属性を、 CdConnectedString2 オブジェクトに追加します。
	@param aCdDcdFreeLineProp [in]
	  	変換対象となる CdDcdFreeLineProp を指定してください。
	@param pCdConnectedString2 [in,out]
	  	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	  	追加します。
	  	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	  	維持します。
	@return
	  	成功したら 0 以上、エラーなら負の数です。

	*/
	int CdDcdFreeLineProp_to_CdConnectedString2( 
		const CdDcdFreeLineProp& aCdDcdFreeLineProp ,
		CdConnectedString2*	pCdConnectedString ) ;

	/**
	  	CdDcdFreeLineProp の属性を、文字列に変換します。
	@param aCdDcdFreeLineProp [in]
	  	変換対象となる CdFontProp を指定してください。
	@return
	  	変換結果を返します。
		失敗した場合は空文字列となります。
	*/
	std::string CdDcdFreeLineProp_to_string( 
		const CdDcdFreeLineProp& aCdDcdFreeLineProp );

	/**
	  	CdDcdFreeLineProp_to_CdConnectedString2 で作成した
		*pCdConnectedString の内容を、
		CdDcdFreeLineProp オブジェクトに反映します。
	@param pCdDcdFreeLineProp [out]
		この関数はこのオブジェクトの属性に、文字列の内容を反映します。
	@param aCdConnectedString [in]
		 CdDcdFreeLineProp_to_CdConnectedString2() で追加した CdItem を持つ
		 CdConnectedString2 オブジェクトを指定してください。
	@return
	  	成功したら 0 以上、エラーなら負の数です。
		-	-11 ;	//	LogicalunitWidth の値が不正です
		-	-12 ;	//	Color の値が不正です

	*/
	int CdDcdFreeLineProp_from_CdConnectedString2( 
		CdDcdFreeLineProp* pCdDcdFreeLineProp ,
		const CdConnectedString2*	pCdConnectedString ) ;

	/**
	  	CdDcdFreeLineProp_to_CdConnectedString2 で作成した
		*pCdConnectedString の内容を、
		CdDcdFreeLineProp オブジェクトに反映します。
	@param pCdDcdFreeLineProp [out]
		この関数はこのオブジェクトの属性に、文字列の内容を反映します。
	@param aString [in]
		 CdDcdFreeLineProp_to_string() で生成した
		 文字列を指定してください。
	@return
	  	成功したら 0 以上、エラーなら負の数です。
		-	-11 ;	//	LogicalunitWidth の値が不正です
		-	-12 ;	//	Color の値が不正です
	*/
	int CdDcdFreeLineProp_from_string( 
		CdDcdFreeLineProp* pCdDcdFreeLineProp ,
		const std::string& aString  );

	///@}

};
