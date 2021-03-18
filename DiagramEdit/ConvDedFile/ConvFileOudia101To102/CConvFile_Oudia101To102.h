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
// $Id: CConvFile_Oudia101To102.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
#ifndef  CConvFile_Oudia101To102_h
#define  CConvFile_Oudia101To102_h
/** @file */

#include "IfConvFile.h"

#include "Str\OuPropertiesText\CConvNodeContainer.h"
#include "Str\OuPropertiesText\CDirectory.h"
#include "DcdCd\DcDrawProp\CdFontProp.h"

namespace ConvFile_Oudia101To102{

using namespace std ;
using namespace OuPropertiesText ;

/**
@brief
	OuDiaファイル Ver.1.01 を Ver.1.02 に変換します。

	変換内容は、以下のとおりです。

@code
□FileType
	  "OuDia.1.01"→"OuDia.1.02" に変換します。
□Rosen.Eki[0].Ekijikokukeisiki
	　"Jikokukeisiki_Hatsu"→"Jikokukeisiki_NoboriChaku" に変更
□Rosen.Eki[末尾].Ekijikokukeisiki
	　"Jikokukeisiki_Hatsu"→"Jikokukeisiki_KudariChaku" に変更
□DispProp.JikokuhyouVFont
	　DispProp.JikokuhyouFont[0] のフェイス名の先頭に "@" を付与して 
	CreateFont() を行います。
	　生成されたフォントの属性を、この値にセットします。
□FileTypeAppComment
	"ConvFileOudia101To102 Ver 0.01"
@endcode



*/
class CConvFile_Oudia101To102 : public IfConvFile
{
private:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
		.oud ファイルのルートノードコンテナから、
		Rosen.Eki[0] のノードコンテナを取得します。
	@param pCNodeContainer [in]
		.oud ファイルのルートノードコンテナを指定してください。
	@return
		ノードコンテナのポインタを返します。
	*/
	Ou<CDirectory> getEki0FromOudFile( 
		CNodeContainer* pCNodeContainer ) ;

	/**
		.oud ファイルのルートノードコンテナから、
		Rosen.Eki[末尾] のノードコンテナを取得します。
	@param pCNodeContainer [in]
		.oud ファイルのルートノードコンテナを指定してください。
	@return
		ノードコンテナのポインタを返します。
	*/
	Ou<CDirectory> getEkiLastFromOudFile( 
		CNodeContainer* pCNodeContainer ) ;

	/**
		.oud ファイルのルートノードコンテナから、
		DispProp.JikokuhyouFont[0] を取得します。
	@param pCNodeContainer [in]
		.oud ファイルのルートノードコンテナを指定してください。
	@return
		ノードの値を返します。
		ノードが見つからなければ、空文字列を返します。
	*/
	string readJikokuhou0FontFromOudFile( 
		const IfNodeContainerConst* pCNodeContainer ) ;

	/**
		.oud ファイルの
		DispProp.JikokuhyouVFont ノードに、文字列を設定します。
	@param pCNodeContainer [in]
		.oud ファイルのルートノードコンテナを指定してください。
	@param strValue [in]
		設定する文字列を指定してください。
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 ;	//	"DispProp" ノードがありません
	*/
	int writeJikokuhouVFontToOudFile( 
		const CNodeContainer* pCNodeContainer ,
		const string& strValue ) ;

	/**
		横書きフォントの フォントプロパティから、
		縦書きフォントのフォントプロパティを生成します。
	@param aCdFontProp [in]
		横書きフォントのプロパティを指定してください。
	@return
		縦書きフォントのプロパティを返します。
		通常は、横書きフォントのプロパティのフェイス名に
		@@ を付与して生成したフォントのプロパティです。
	*/
	CdFontProp createVFontPropFromHFont( 
		const CdFontProp& aCdFontProp ) ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CConvFile_Oudia101To102();
	virtual ~CConvFile_Oudia101To102();
public:
	// ********************************
	///@name IfConvFile
	// ********************************
	///@{
	/**
		LeftFormat から RightFormat への変換を行います。

	@param pLeftFormat [in]
		LeftFormat のデータを指定してください。
	@param pRightFormat [out]
		この関数は変換が成功したら、
		このバッファに、RightFormat のデータを書き込みます。
	@param pErrorInfoString [out] 
		この関数は変換が失敗したら、
		このバッファにエラーの内容を示す文字列を
		書き込みます。
		但し、すべての ConvFile クラスがこの機能をサポートしているわけでは
		ありません。
	@return  
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	FileType が正しくありません。
		-	-11 ;	//	ファイルが正しいフォーマットではありません。
	*/
	virtual int LeftToRight( 
		const IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pRightFormat , 
		IfByteBuffer* pErrorInfoString ) ; 

	/**
		LeftFormat が変換可能なフォーマットであるか否かを
		判定します。
		
		この関数は LeftFormat のデータの特徴に対して簡単な検査を
		行います。
		この関数が成功しても、 LeftToRight() が成功するとは
		限りません。

	【実装】

　	  .oud ファイル の Oudia.5 では、 [FileType] に、"OuDia.5" が記述されています。
		
	@param pLeftFormat [in]
		LeftFormat のデータを指定してください。
	@return  
		成功したら 0 以上、エラーなら負の数です。
		-	0 以上 ;	//	変換可能なフォーマットです。
		-	-1 ;	//	FileType が正しくありません。
		-	-11 ;	//	ファイルが正しいフォーマットではありません。
	*/
	virtual int isLeftFormat( 
		const IfByteBuffer* pLeftFormat)  ; 

	/**
	@return 
		- true ;	//	RightToLeft(),isRightFormat() メソッドをサポートしています。
		- false ;	//	RightToLeft(),isRightFormat() メソッドをサポートしていません。
	*/
	virtual bool RightToLeftIsSupported() ; 

	/**
		RightFormat から LeftFormat への変換を行います。
	@param pRightFormat [in]
		RightFormat のデータを指定してください。
	@param pLeftFormat [out]
		この関数は変換が成功したら、
		このバッファに、LeftFormat のデータを書き込みます。
	@param pErrorInfoString [out] 
		この関数は変換が失敗したら、
		このバッファにエラーの内容を示す文字列を
		書き込みます。
		但し、すべての ConvFile クラスがこの機能をサポートしているわけでは
		ありません。
		不要であればNULLでもかまいません。
	@return  
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	pLeftFormat は正しい LeftFormat ではありません。
		-	-2 ;	//	このメソッドはサポートされていません。
	*/
	virtual int RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) ; 

	/**
		RightFormat が変換可能なフォーマットであるか否かを
		判定します。
		
		この関数は RightFormat のデータの特徴に対して簡単な検査を
		行います。
		この関数が成功しても、 LeftFromRight() が成功するとは
		限りません。
	@param pRightFormat [in]
		RightFormat のデータを指定してください。
	@return  
		成功したら 0 以上、エラーなら負の数です。
		-	0 以上 ;	//	変換可能なフォーマットです。
		-	-1 ;	//	pRightFormat は正しい RightFormat ではありません。
		-	-2 ;	//	このメソッドはサポートされていません。
	*/
	virtual int isRightFormat( 
		const IfByteBuffer* pRightFormat ) ; 
	///@}

};


} //namespace ConvFile_Oudia101To102



#endif //CConvFile_Oudia101To102_h


