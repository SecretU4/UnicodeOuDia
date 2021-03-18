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
//	CconvCentDed_01.h
// ****************************************************************
*/
#ifndef  convCentDed_h
#define  convCentDed_h

/** @file */

#include "CentDedEki.h"
#include "CentDedRessyasyubetsu.h"
#include "CentDedEkiJikoku.h"
#include "CentDedRessya.h"
#include "CentDedRessyaCont.h"
#include "CentDedDia.h"
#include "CentDedRosen.h"
#include "str/CdConnectedString2.h"
#include "DcDraw/CDcdFreeLine.h"

// ****************************************************************
//	CconvCentDed_01
// ****************************************************************
/**
 *	@brief
 *	  DiagramEdit のエンティティクラスのオブジェクトの属性データの内容を、
 *	他のデータ形式に変換する関数を収録しています。
 *
 *	   CdConnectedString2 オブジェクトとの間の変換をサポートしています。
 *	
 */
class CconvCentDed_01
{
// ********************************
//	CconvCentDed_01
// ********************************
 public:

	// ********************************
	//	CentDedEki
	// ********************************
	
	/**
	 *	  CdConnectedString オブジェクトに、
	 *	  CentDedEki の属性を追加します。
	 *	@param aCentDedEki [in]
	 *	  CentDedEki を指定してください。
	 *	@param pCdConnectedString [in,out]
	 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	 *	追加します。
	 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	 *	維持します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-11 ;	//	Ekimei が指定されていません。
	 *	-	-22 ;	//	Ekijikokukeisiki の値が不正です。
	 *	-	-32 ;	//	Ekikibo の値が不正です。
	 */
	int CentDedEki_To_CdConnectedString( 
			const CentDedEki& aCentDedEki , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString オブジェクトから、
	 *	  CentDedEki_To_CdConnectedString() 関数によって作成された
	 *	アイテムを読み込み、 CentDedEki オブジェクトに反映します。
	 *	
	 *	@param pCentDedEki [out]
	 *	  この関数はこのオブジェクトに、属性を反映します。
	 *	@param aCdConnectedString [in]
	 *	  属性を保持している CdConnectedString オブジェクトを指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-11 ;	//	Ekimei が指定されていません。
	 *	-	-22 ;	//	Ekijikokukeisiki の値が不正です。
	 *	-	-32 ;	//	Ekikibo の値が不正です。
	 */
	int CentDedEki_From_CdConnectedString( 
			CentDedEki* pCentDedEki ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	// ********************************
	//	CentDedRessyasyubetsu
	// ********************************
	
	/**
	 *	  CdConnectedString オブジェクトに、
	 *	  CentDedRessyasyubetsu の属性を追加します。
	 *	@param aCentDedRessyasyubetsu [in]
	 *	  CentDedRessyasyubetsu を指定してください。
	 *	@param pCdConnectedString [in,out]
	 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	 *	追加します。
	 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	 *	維持します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-11 ;	//	Ekimei が指定されていません。
	 *	-	-22 ;	//	Ekijikokukeisiki の値が不正です。
	 *	-	-32 ;	//	Ekikibo の値が不正です。
	 */
	int CentDedRessyasyubetsu_To_CdConnectedString( 
			const CentDedRessyasyubetsu& aCentDedRessyasyubetsu , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString オブジェクトから、
	 *	  CentDedRessyasyubetsu_To_CdConnectedString() 関数によって作成された
	 *	アイテムを読み込み、 CentDedRessyasyubetsu オブジェクトに反映します。
	 *	
	 *	@param pCentDedRessyasyubetsu [out]
	 *	  この関数はこのオブジェクトに、属性を反映します。
	 *	@param aCdConnectedString [in]
	 *	  属性を保持している CdConnectedString オブジェクトを指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-11 ;	//	Ekimei が指定されていません。
	 *	-	-22 ;	//	Ekijikokukeisiki の値が不正です。
	 *	-	-32 ;	//	Ekikibo の値が不正です。
	 */
	int CentDedRessyasyubetsu_From_CdConnectedString( 
			CentDedRessyasyubetsu* pCentDedRessyasyubetsu ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	/**
	 *	CentDedRessyasyubetsu::ESenStyle の値と、
	 *	「太線」を示す bool 属性をもとに、
	 *	CDcdFreeLine::CdLineProp オブジェクトに属性を
	 *	設定します。
	 * @param aCOLORREF [in] 
	 *	線の色を指定してください。
	 * @param eSenStyle [in]
	 *	線の形状を指定してください。
	 * @param bIsBold [in]
	 *	太線なら true , そうでないなら false を指定してください。
	 * @param pCdLineProp [out]
	 *	この関数はこのオブジェクトに、
	 *	属性を設定します。
	 */
	void CentDedRessyasyubetsu_to_CDcdFreeLineProp(
		COLORREF aCOLORREF ,
		CentDedRessyasyubetsu::ESenStyle eSenStyle , 
		bool bIsBold , 
		CDcdFreeLine::CdLineProp* pCdLineProp )	;
	
	// ********************************
	//	CentDedEkiJikoku
	// ********************************
	
	/**
	 *	  CdConnectedString オブジェクトに、
	 *	  CentDedEkiJikoku の属性を追加します。
	 *	@param aCentDedEkiJikoku [in]
	 *	  CentDedEkiJikoku を指定してください。
	 *	@param pCdConnectedString [in,out]
	 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	 *	追加します。
	 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	 *	維持します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-12 ;	//	DiagramEkiatsukai の値が不正です。
	 */
	int CentDedEkiJikoku_To_CdConnectedString( 
			const CentDedEkiJikoku& aCentDedEkiJikoku , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString オブジェクトから、
	 *	  CentDedEkiJikoku_To_CdConnectedString() 関数によって作成された
	 *	アイテムを読み込み、 CentDedEkiJikoku オブジェクトに反映します。
	 *	
	 *	@param pCentDedEkiJikoku [out]
	 *	  この関数はこのオブジェクトに、属性を反映します。
	 *	@param aCdConnectedString [in]
	 *	  属性を保持している CdConnectedString オブジェクトを指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-12 ;	//	DiagramEkiatsukai の値が不正です。
	 */
	int CentDedEkiJikoku_From_CdConnectedString( 
			CentDedEkiJikoku* pCentDedEkiJikoku ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	// ********************************
	//	CentDedRessya
	// ********************************
	
	/**
	 *	  CdConnectedString オブジェクトに、
	 *	  CentDedRessya の属性を追加します。
	 *	@param pCentDedRessya [in]
	 *	  CentDedRessya を指定してください。
	 *	@param pCdConnectedString [in,out]
	 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	 *	追加します。
	 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	 *	維持します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-12 ;	//	DiagramEkiatsukai の値が不正です。
	 */
	int CentDedRessya_To_CdConnectedString( 
			const CentDedRessya* pCentDedRessya , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString オブジェクトから、
	 *	  CentDedRessya_To_CdConnectedString() 関数によって作成された
	 *	アイテムを読み込み、 CentDedRessya オブジェクトに反映します。
	 *	
	 *	  ただし、
	 *
	 *		- 列車方向
	 *		- オブジェクトが包含する 『駅時刻』 の数
	 *
	 *	は、変更しません。この値は、関数呼出元によって設定されている
	 *	必要があります。
	 *	@param pCentDedRessya [in,out]
	 *	  この関数はこのオブジェクトに、列車の属性を反映します。
	 *	\n ただし、オブジェクトの属性『列車方向』と
	 *	包含する 『駅時刻』 の数は変更しません。
	 *	この値は、関数呼出元によって設定されている必要があります。
	 *	@param aCdConnectedString [in]
	 *	  属性を保持している CdConnectedString オブジェクトを指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-12 ;	//	DiagramEkiatsukai の値が不正です。
	 */
	int CentDedRessya_From_CdConnectedString( 
			CentDedRessya* pCentDedRessya ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	
	// ********************************
	//	CentDedRessyaCont
	// ********************************
	
	/**
	 *	  CdConnectedString オブジェクトに、
	 *	  CentDedRessyaCont の属性を追加します。
	 *	@param pCentDedRessyaCont [in]
	 *	  CentDedRessya を指定してください。
	 *	@param pCdConnectedString [in,out]
	 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	 *	追加します。
	 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	 *	維持します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-12 ;	//	DiagramEkiatsukai の値が不正です。
	 */
	int CentDedRessyaCont_To_CdConnectedString( 
			const CentDedRessyaCont* pCentDedRessyaCont , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString オブジェクトから、
	 *	  CentDedRessya_To_CdConnectedString() 関数によって作成された
	 *	アイテムを読み込み、 CentDedRessya オブジェクトに反映します。
	 *	
	 *	@param pCentDedRessya [in,out]
	 *	  この関数はこのコンテナの末尾に、
	 *	aCdConnectedString オブジェクトに保存されている属性のオブジェクトを
	 *	追加します。
	 *	\n ただし、追加されるオブジェクトの 『駅時刻』 の数は、
	 *	m_iEkiCount に決まっています。 aCdConectedString に保存されている
	 *	列車がこれより多い『駅時刻』を保持していた場合は、終着駅寄りの時刻が
	 *	切捨てとなります。
	 *	@param aCdConnectedString [in]
	 *	  属性を保持している CdConnectedString オブジェクトを指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-12 ;	//	DiagramEkiatsukai の値が不正です。
	 */
	int CentDedRessyaCont_From_CdConnectedString( 
			CentDedRessyaCont* pCentDedRessyaCont ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	
	// ********************************
	//	CentDedDia
	// ********************************
	
	/**
	 *	  CdConnectedString オブジェクトに、
	 *	  CentDedDia の属性を追加します。
	 *	@param pCentDedDia [in]
	 *	  CentDedDia を指定してください。
	 *	@param pCdConnectedString [in,out]
	 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	 *	追加します。
	 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	 *	維持します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-12 ;	//	DiagramEkiatsukai の値が不正です。
	 */
	int CentDedDia_To_CdConnectedString( 
			const CentDedDia* pCentDedDia , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString オブジェクトから、
	 *	  CentDedDia_To_CdConnectedString() 関数によって作成された
	 *	アイテムを読み込み、 CentDedDia オブジェクトに反映します。
	 *	
	 *	@param pCentDedDia [out]
	 *	  この関数はこのオブジェクトに、属性を反映します。
	 *	@param aCdConnectedString [in]
	 *	  属性を保持している CdConnectedString オブジェクトを指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-12 ;	//	DiagramEkiatsukai の値が不正です。
	 */
	int CentDedDia_From_CdConnectedString( 
			CentDedDia* pCentDedDia ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	// ********************************
	//	CentDedRosen
	// ********************************
	
	/**
	 *	  CdConnectedString オブジェクトに、
	 *	  CentDedRosen の属性を追加します。
	 *	@param pCentDedRosen [in]
	 *	  CentDedRosen を指定してください。
	 *	@param pCdConnectedString [in,out]
	 *	  この関数は、このオブジェクトに、 CdConnectedString2::CdItem を
	 *	追加します。
	 *	  このオブジェクトがそれまで保持していた CdConnectedString2::CdItem は
	 *	維持します。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 */
	int CentDedRosen_To_CdConnectedString( 
			const CentDedRosen* pCentDedRosen , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString オブジェクトから、
	 *	  CentDedRosen_To_CdConnectedString() 関数によって作成された
	 *	アイテムを読み込み、 CentDedRosen オブジェクトに反映します。
	 *	
	 *	@param pCentDedRosen [out]
	 *	  この関数はこのオブジェクトに、属性を反映します。
	 *	@param aCdConnectedString [in]
	 *	  属性を保持している CdConnectedString オブジェクトを指定してください。
	 *	@return
	 *	  成功したら 0 以上、エラーなら負の数です。
	 *	-	-2 ;	//	『列車種別』は、少なくとも一つは
	 *				//	存在しなくてはなりません。
	 *	-	-52 ;	//	起点時刻の設定が不適切です。
	 */
	int CentDedRosen_From_CdConnectedString( 
			CentDedRosen* pCentDedRosen ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	
};	
#endif /*convCentDed_h*/
	
