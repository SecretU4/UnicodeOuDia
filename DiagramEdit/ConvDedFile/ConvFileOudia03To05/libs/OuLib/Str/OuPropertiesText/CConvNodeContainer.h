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
/** @file */
//$Id: CConvNodeContainer.h 10 2012-08-26 09:48:47Z okm $
#pragma once
#include "str\OuPropertiesText\CNodeContainer.h"

namespace OuPropertiesText{


/**
@brief
	CNodeContainer の内容とOuPropertiesText(文字列)の間の変換を行います。

【ErrorInfoString】

  ErrorInfoString は、エラーの原因を示す文字列です。
  この文字列は、 

	- 1つのErrReason 文字列(エラー原因文字列)と、
	- 0個以上のErrProp(エラーサブ属性)
 
 で構成されます。

  ErrReason 文字列は、 ERRREASON_ のうちのいずれかです。

  ErrProp は、 
 
	- 属性名=値
 
 の形式です。属性名は、ERRPROP_ のうちのいずれかです。
   ErrReasonとErrPropの間・ErrProp同士の間は、タブで区切ります。
*/
class CConvNodeContainer  
{
public:
	// ********************************
	///@name	ErrorInfoString
	// ********************************
	///@{
	/**
		文字列がデコードできません。
	@param ERRPROP_Text
		対象となる文字列
	*/
	static const char* const ERRREASON_Undecoded_Text ;
	/**
		ディレクトリが途中で閉じています。
	*/
	static const char* const ERRREASON_ContainerAborted ;
	/**
		ディレクトリが閉じていません
	*/
	static const char* const ERRREASON_ContainerIsNotClosed ;

	/**
		行テキスト
	*/
	static const char* const ERRPROP_Text ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CConvNodeContainer();
	virtual ~CConvNodeContainer();

protected:
	// --------------------------------
	///@name 下請け関数
	// --------------------------------
	///@{
	/**
		Property の Value を、OuPropertiesText用にエスケープします。
			- 改行文字 → "\n" 
			- "\" → "\\" 
	@param strValue [in]
		変換前の文字列を指定してください。
	@return 
		変換後の文字列を返します。
	*/
	string encodePropertyString_escapePropertyValue( 
		const string& strValue ); 

	/**
		OuPropertiesText用にエスケープされたProperty の Value を、変換します。
			- 改行文字 ← "\n" 
			- "\" ← "\\" 
	@param strValue [in]
		変換前の文字列を指定してください。
	@return 
		変換後の文字列を返します。
	*/
	string decodePropertyString_unescapePropertyValue(
			const string& strValue ) ;

	/**
		OuPropertiesText の指定の位置から始まる 
		NodeContainer 1個を解釈し、その内容をもとに CNodeContainer オブジェクトを
		構築します。
	@param strContent [in]
		OuPropertiesText文字列を指定してください。
	@param iPosBegin [in]
		OuPropertiesText文字列の中での位置を、0から始まるインデクスで指定してください。
	@param piPosNext [out]
		この関数は、解釈に成功したら、解釈終了した OuPropertiesText 文字列の位置
		(何文字目までを解釈したか)を書き込みます。
		これは通常、OuPropertiesText の末尾か、Directry終端行の先頭を指します。
		不要ならNULLでもかまいません。
	@param pCNodeContainer [out]
		この関数はこのオブジェクトに、NodeContainer の内容を
		構成します。
	@param pstrErrorInfoString [out]
		この関数は、エラーが発生した場合は、ErrorInfoString を書き込みます。
		不要であればNULLを指定してもかまいません。
	@return
		-	1 ;	//	成功
		-	0 ;	//	すでに iPosBegin がコンテンツの末尾にあります。
		-	-1 ;	//	文字列がデコードできません。	
	*/
	int decodeNodeContainer(
		const string& strContent , 	int iPosBegin  , int* piPosNext , 
			CNodeContainer* pCNodeContainer ,
			string* pstrErrorInfoString ) ;

	/**
		OuPropertiesText の指定の位置から始まる 
		Property 1個を解釈し、その内容をもとに CPropertyString オブジェクトを
		構築します。
	@param strContent [in]
		OuPropertiesText文字列を指定してください。
	@param iPosBegin [in]
		OuPropertiesText文字列の中での位置を、0から始まるインデクスで指定してください。
	@param piPosNext [out]
		この関数は、解釈に成功したら、解釈終了した OuPropertiesText 文字列の位置
		(何文字目までを解釈したか)を書き込みます。
		これは通常、OuPropertiesText の末尾か、Directry終端行の先頭を指します。
		不要ならNULLでもかまいません。
	@param ppCPropertyString [out]
		この関数は、解釈に成功したら、その内容を保持した CPropertyString 
		オブジェクトを生成し、そのオブジェクトへのアドレスを
		このポインタに書き込みます。
	@param pstrErrorInfoString [out]
		この関数は、エラーが発生した場合は、ErrorInfoString を書き込みます。
		不要であればNULLを指定してもかまいません。
	@return
		-	1 ;	//	成功
		-	0 ;	//	すでに iPosBegin がコンテンツの末尾にあります。
	*/
	int decodePropertyString(
		const string& strContent , 	int iPosBegin  , int* piPosNext , 
		Ou<CPropertyString>* ppCPropertyString ,
		string* pstrErrorInfoString ) ;

	/**
		コンテンツの指定の位置から始まる1行の文字列を返します。
	@param strContent [in]
		コンテンツ文字列を指定してください。
	@param iPosBegin [in]
		コンテンツ文字列の中での位置を、0から始まるインデクスで指定してください。
	@param piPosNext [out]
		この関数は、コンテンツ文字列内での、次の行の位置を書き込みます。
		不要ならNULLでもかまいません。
	@param pstrLine [out]
		この関数はこのオブジェクトに、１行分の文字列を返します。
		行末の区切りの '\n' は、この文字列には含めません。
	@return
		-	1 ;	//	成功
		-	0 ;	//	すでに iPosBegin がコンテンツの末尾にあります。
	*/
	int getLine( 
		const string& strContent , 	int iPosBegin  , int* piPosNext , 
		string* pstrLine  ) ;

	///@}
public:
	// ********************************
	///@name	CConvNodeContainer  
	// ********************************
	///@{
	/**
		IfNodeContainerConstの内容を文字列(OuPropertiesText) に変換します。
	@param pIfNodeContainerConst [in]
		変換する CNodeContainer を指定してください。
	@return
		変換後のOuPropertiesTextを返します。
	*/
	virtual string encode( 
		const IfNodeContainerConst* pIfNodeContainerConst ) ;

	/**
		CNodeContainerの内容を文字列(OuPropertiesText) に変換します。
	@param pCNodeContainer [in]
		変換する CNodeContainer を指定してください。
	@return
		変換後のOuPropertiesTextを返します。
	*/
	virtual string encode( 
		const CNodeContainer* pCNodeContainer ) 
	{	return encode( pCNodeContainer->getIfNodeContainerConst() ) ; } ;

	/**
		文字列(OuPropertiesText) の内容をCNodeContainerに反映します。
	@param strContent [in]
		変換する OuPropertiesText。
	@param pCNodeContainer [out]
		この関数は、この CNodeContainer に、OuPropertiesText の
		内容を反映します。
		この関数がそれまで保持していた内容は破棄します。
	@param pstrErrorInfoString [out]
		この関数は、エラーが発生した場合は、ErrorInfoString を書き込みます。
		不要であればNULLを指定してもかまいません。
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 ;	//	ディレクトリが途中で閉じています。
	*/
	virtual int decode(
		const string& strContent , 
		CNodeContainer* pCNodeContainer ,
		string* pstrErrorInfoString = NULL ) ;


	///@}

};

}//namespace OuPropertiesText
