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
//	CconvCDedRosenFileData_02.h
// ****************************************************************
*/
#ifndef  CconvCDedRosenFileData_02_h
#define  CconvCDedRosenFileData_02_h
/** @file */
#include "CDedRosenFileData.h"
#include "str/CdConnectedString2.h"

// ****************************************************************
//	CconvCDedRosenFileData_02
// ****************************************************************
/**
 *	@brief
 *	  『路線ファイル』データ ( CDedRosenFileData ) の内容を、他の
 *	データ形式に変換する関数を収録しています。
 *	
 *	 『路線ファイル』データと  CdConnectedString2 オブジェクトとの間の
 *	変換をサポートしています。 
 *	
 *	<H4>
 *	【路線ファイル (.ded) 】
 *	</H4>
 *	  『路線ファイル』は、路線ファイルデータクラスを
 *	 CDedRosenFileData_To_string() で文字列に変換し、その文字列全体を
 *	保存したテキストファイルです。
 *	
 *	   CDedRosenFileData_To_string() 関数は、
 *	   CDedRosenFileData オブジェクトが保持するデータを
 *	以下の手順で文字列に変換します。
 *	
 *	  １．   CdConnectedString2 オブジェクトを生成してください。このとき、
 *	アイテム間の区切り文字( CdConnectedString2::m_chSplit ) は "\n" 、
 *	項目と値の間の区切り文字( CdConnectedString2::m_chEqualChar ) は
 *	 "=" としてください。
 *	
 *	  ２．  CDedRosenFileData オブジェクトの内容を、
 *	 CDedRosenFileData_to_CdConnectedString() で、CdConnectedString2 に
 *	追加してください。
 *	
 *	  ３．  CdConnectedString2::encode() によって得られる文字列が、
 *	『路線ファイル』形式の文字列です。これをファイルに保存することにより、
 *	 『路線ファイル』となります。
 */
class CconvCDedRosenFileData_02
{
// ********************************
//	CconvCDedRosenFileData_02
// ********************************
 public:
	// ********************************
	//	CdDedDispProp
	// ********************************
	/**
	 * @return
	 *	CdDedDispProp_to_CdConnectedString() の内容を
	 *	ファイルに保存する際に追加するアイテム "FileType" の値です。
	 *
	 * @attention 
	 *	このクラスの CdDedDispProp_to_CdConnectedString() 関数が
	 *	 "FileType" アイテムを付与するわけではありません。
	 *	 "FileType" アイテムを付与する（判定する）のは、
	 *	関数呼出元の責務です。
	 */
	string getFileType(){	return "OuDia.2" ; } ;
	
	
	/**
	 *	  CdConnectedString オブジェクトに、
	 *	  CdDedDispProp の属性を追加します。
	 *	@param aCdDedDispProp [in]
	 *	  CdDedDispProp を指定してください。
	 *	@param pCdConnectedString [in,out]
	 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	 *	追加します。
	 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	 *	維持します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	  現在のところ、戻り値は常に 0 です。
	 */
	int CdDedDispProp_to_CdConnectedString( 
			const CdDedDispProp& aCdDedDispProp , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString オブジェクトから、
	 *	  CdDedDispProp_To_CdConnectedString() 関数によって作成された
	 *	アイテムを読み込み、 CdDedDispProp オブジェクトに反映します。
	 *	
	 *	@param pCdDedDispProp [out]
	 *	  この関数はこのオブジェクトに、属性を反映します。
	 *	@param aCdConnectedString [in]
	 *	  属性を保持している CdConnectedString オブジェクトを指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-12 ;	//	JikokuhyouFont の内容が不正です。
	 *	-	-22 ;	//	DiaEkimeiFont の内容が不正です。
	 *	-	-32 ;	//	DiaJikokuFont の内容が不正です。
	 *	-	-82 ;	//	DisplayRessyabangou が不正です。
	 *	-	-92 ;	//	DisplayRessyamei が不正です。
	 *	-	-102 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari が不正です。
	 *	-	-112 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori が不正です。
	 */
	int CdDedDispProp_from_CdConnectedString( 
			CdDedDispProp* pCdDedDispProp ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	
	
	// ********************************
	//	CDedRosenFileData
	// ********************************
	/**
	 *	  CdConnectedString オブジェクトに、
	 *	  CDedRosenFileData の属性を追加します。
	 *	@param aCDedRosenFileData [in]
	 *	  CDedRosenFileData を指定してください。
	 *	@param pCdConnectedString [in,out]
	 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	 *	追加します。
	 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	 *	維持します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-11 ;	//	Rosen の内容が不正
	 *	-	-21 ;	//	DispProp の内容が不正
	 */
	int CDedRosenFileData_to_CdConnectedString( 
			const CDedRosenFileData& aCDedRosenFileData , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString オブジェクトから、
	 *	  CDedRosenFileData_To_CdConnectedString() 関数によって作成された
	 *	アイテムを読み込み、 CDedRosenFileData オブジェクトに反映します。
	 *	
	 *	@param pCDedRosenFileData [out]
	 *	  この関数はこのオブジェクトに、属性を反映します。
	 *	@param aCdConnectedString [in]
	 *	  属性を保持している CdConnectedString オブジェクトを指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 */
	int CDedRosenFileData_from_CdConnectedString( 
			CDedRosenFileData* pCDedRosenFileData ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	
	/**
	 *	  CDedRosenFileData の保持するデータから、
	 *	『路線ファイル』(.ded) 形式の文字列を作成します。
	 *
	 *	@param aCDedRosenFileData [in]
	 *	  CDedRosenFileData を指定してください。
	 *	@param pString [out]
	 *	  この関数は、この文字列オブジェクトに、
	 *	『路線ファイル』(.ded) 形式の文字列を設定します。
	 *	  このオブジェクトがそれまで保持していた文字列は破棄します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-11 ;	//	Rosen の内容が不正
	 *	-	-21 ;	//	DispProp の内容が不正
	 */
	int CDedRosenFileData_to_string( 
			const CDedRosenFileData& aCDedRosenFileData , 
			string* pString ) ;
	
	/**
	 *	  CDedRosenFileData_to_string() で生成した
	 *	『路線ファイル』(.ded) 形式の文字列を解釈し、
	 *	 CDedRosenFileData オブジェクトに反映します。
	 *	
	 *	@param pCDedRosenFileData [out]
	 *	  この関数はこのオブジェクトに、属性を反映します。
	 *	@param aString [in]
	 *	  CDedRosenFileData_to_string() で生成した
	 *	『路線ファイル』(.ded) 形式の文字列を指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-11 ;	//	Rosen の内容が不正
	 *	-	-21 ;	//	DispProp の内容が不正
	 */
	int CDedRosenFileData_from_string( 
			CDedRosenFileData* pCDedRosenFileData ,
			const string& aString ) ;
};
#endif /*CconvCDedRosenFileData_02_h*/
