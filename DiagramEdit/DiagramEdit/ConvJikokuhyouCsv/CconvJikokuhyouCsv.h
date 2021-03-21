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
// $Id: CconvJikokuhyouCsv.h 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
#ifndef  CconvJikokuhyouCsv_h
#define  CconvJikokuhyouCsv_h
/** @file */
#include "..\DedRosenFileData\CDedRosenFileData.h"
#include "Str\CsvDocument\CdCsvDocument.h"

namespace ConvJikokuhyouCsv{
using namespace entDed ;
using namespace OuLib::Str::CsvDocument;

/**
@brief
	時刻表形式CSVファイルとの間のデータ変換を行います。

	CentDedRosenと、時刻表形式のCSVファイルを生成します。

	反対に、CentDedRosenに、時刻表形式のCSVファイルの内容を取り込む
	こともできます。
*/
class CconvJikokuhyouCsv
{
private:
	/// CSV上の固定文字列「下り」
	std::string m_nameKudari ;
	/// CSV上の固定文字列「上り」
	std::string m_nameNobori ;
	/// CSV上の固定文字列「列車番号」
	std::string m_nameRessyabangou ;
	/// CSV上の固定文字列「列車種別」
	std::string m_nameRessyasyubetsu ;
	/// CSV上の固定文字列「列車名」
	std::string m_nameRessyamei ;
	/// CSV上の固定文字列「号数」
	std::string m_nameGousuu ;
	/// CSV上の固定文字列「号」
	std::string m_nameGou ;
	/// CSV上の固定文字列「備考」
	std::string m_nameBikou ;
	/// CSV上の固定文字列「着」
	std::string m_nameChaku ;
	/// CSV上の固定文字列「発」
	std::string m_nameHatsu ;
	/// CSV上の固定文字列「レ」
	std::string m_nameTsuuka ;
	/// CSV上の固定文字列「||」
	std::string m_nameKeiyunasi ;
protected:
	// --------------------------------
	///@name	駅時刻セルの文字列の解釈
	// --------------------------------
	///@{
	/**
		駅扱と時刻をもとに、時刻をCSV向けに文字列化します。
		
	@param eEkiatsukai [in]
		駅扱を指定してください。
	@param aCdDedJikoku [in]
		時刻を指定してください。
		
		eEkiatsukai が
		CentDedEkiJikoku::Ekiatsukai_None,
		CentDedEkiJikoku::Ekiatsukai_Keiyunasi 
		である場合は、aCdDedJikoku は評価されません。
		
		eEkiatsukaiが
		CentDedEkiJikoku::Ekiatsukai_Teisya, 
		の場合は、通常に時刻を出力します。
		
		eEkiatsukaiが
		CentDedEkiJikoku::Ekiatsukai_Tsuuka, 
		で、aCdDedJikoku が Null でない場合は、
		時刻の末尾に "?" を付与します。
	@return
		変換された文字列を返します。
	*/
	std::string encode_Ekijikoku( 
		CentDedEkiJikoku::EEkiatsukai eEkiatsukai , 
		const CdDedJikoku& aCdDedJikoku ) ;

	/**
		CSVの駅時刻セルの内容を解釈します。
		
	@param pEkiatsukai [out]
		この関数はここに、解釈結果の駅扱を書き込みます。
	@param pCdDedJikoku [out]
		この関数はこのアドレスに、解釈結果の時刻を書き込みます。
	@param strEkijikoku [in]
		駅時刻の文字列を指定してください。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	時刻の解釈に失敗しました。
	*/
	int  decode_Ekijikoku( 
		CentDedEkiJikoku::EEkiatsukai* pEkiatsukai , 
		CdDedJikoku* pCdDedJikoku , 
		const std::string& strEkijikoku ) ;
	///@}
	// --------------------------------
	///@name encode() の下請関数	
	// --------------------------------
	///@{


	/**
		駅一覧をもとに、
		時刻表Index-時刻Order対照配列を生成します。
	@param pCentDedEkiCont [in]
		駅コンテナを指定してください。
	@param eRessyahoukou [in]
		列車方向を指定してください。
	@param pcontiJikokuOrderOfJikokuhyouIndex [out]
		この関数はこのコンテナに、
		時刻表Index-時刻Order対照配列を生成します。

		 *pcontiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order>
	
	*/
	void encode_createContJikokuOrderOfJjikokuhyouIndex( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou eRessyahoukou , 
		std::deque<CdDedJikokuOrder>*	pcontiJikokuOrderOfJikokuhyouIndex ) ;

	/**
		CdCsvDocument に、Nullでない列車を追加します。

		列車の設定にあたっては、
		時刻表Index-時刻Order対照配列を指定する必要があります。
		この配列は、以下の形式でなくてはなりません。

		 contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order>
	
	  CdCsvDocument は、以下の条件を満たしていなくてはなりません。
		
		- 以下の列が設定されている
			- 1行目 FileType行
			- 2行目 DiaName行
			- ＜2.3＞ 3行目 <下り,上り>
			- ＜2.4＞4行目 
		- 列数は、 contiJikokuOrderOfJikokuhyouIndex.size() + 10 

	  この関数は、行Index4に列車番号を設定し、
	  行Index (9+ contiJikokuOrderOfJikokuhyouIndex.size() ) に
	備考を設定します。

	@param pCentDedRessyasyubetsuContGet [in]
		列車種別コンテナを指定してください。
	@param contiJikokuOrderOfJikokuhyouIndex [in] 
		時刻表Index-時刻Order対照配列を指定してください。
	@param pCentDedRessya [in]
		列車を指定してください。
	@param pCdCsvDocument [in,out]
		この関数はこのCSVドキュメントに列車情報を追加します。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	この列車はNULLです。
	*/
	int encode_AddRessya( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const std::deque<CdDedJikokuOrder>&	contiJikokuOrderOfJikokuhyouIndex , 
		const CentDedRessya* pCentDedRessya , 
		CdCsvDocument* pCdCsvDocument ) ;

	/**
		CdCsvDocument に、Null列車を追加します。

		列車の設定にあたっては、
		時刻表Index-時刻Order対照配列を指定する必要があります。
		この配列は、以下の形式でなくてはなりません。

		 contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order>
	
	  CdCsvDocument は、以下の条件を満たしていなくてはなりません。
		
		- 以下の列が設定されている
			- 1行目 FileType行
			- 2行目 DiaName行
			- ＜2.3＞ 3行目 <下り,上り>
			- ＜2.4＞4行目 
		- 列数は、 contiJikokuOrderOfJikokuhyouIndex.size() + 10 

	  この関数は、行Index4に列車番号を設定し、
	  行Index (9+ contiJikokuOrderOfJikokuhyouIndex.size() ) に備考を設定します。

	@param contiJikokuOrderOfJikokuhyouIndex [in] 
		時刻表Index-時刻Order対照配列を指定してください。
	@param pCdCsvDocument [in,out]
		この関数はこのCSVドキュメントに列車情報を追加します。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	常に0
	*/
	int encode_AddRessyaNull( 
		const std::deque<CdDedJikokuOrder>&	contiJikokuOrderOfJikokuhyouIndex , 
		CdCsvDocument* pCdCsvDocument ) ;

	///@}
	// --------------------------------
	///@name decode() の下請関数	
	// --------------------------------
	///@{

	/**
		駅一覧とCdCsvDocumentをもとに、
		時刻表Index-時刻Order対照配列を生成します。
	@param pCentDedEkiCont [in]
		駅コンテナを指定してください。
	@param eRessyahoukou [in]
		列車方向を指定してください。
	@param pCdCsvDocument [in]
		この関数はこのCSVドキュメントに列車情報を追加します。
	@param pcontiJikokuOrderOfJikokuhyouIndex [out]
		この関数はこのコンテナに、
		時刻表Index-時刻Order対照配列を生成します。
	@param pstrErrorInfoString [out]
		エラーなら、エラー情報テキストを返します。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	駅名が見つかりません。
		
		 *pcontiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order>
	*/
	int decode_createContJikokuOrderOfJjikokuhyouIndex( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou eRessyahoukou , 
		const CdCsvDocument* pCdCsvDocument , 
		std::deque<int>*	pcontiJikokuOrderOfJikokuhyouIndex ,
		std::string* pstrErrorInfoString ) ;

	/**
		CdCsvDocument の指定の列を読み込み、
		その内容を CentDedRessya に指定します。

		列車の設定にあたっては、
		時刻表Index-時刻Order対照配列を指定する必要があります。
		この配列は、以下の形式でなくてはなりません。

		 contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order>
	
	  CdCsvDocument は、以下の条件を満たしていなくてはなりません。
		
		- 以下の列が設定されている
			- 1行目 FileType行
			- 2行目 DiaName行
			- ＜2.3＞ 3行目 <下り,上り>
			- ＜2.4＞4行目 
		- 列数は、 contiJikokuOrderOfJikokuhyouIndex.size() + 10 

	  この関数は、行Index4に列車番号、
	  行Index (9+ contiJikokuOrderOfJikokuhyouIndex.size() ) に
	備考があるものとして解釈を行います。。

	@param pCentDedRessyasyubetsuContGet [in]
		列車種別コンテナを指定してください。
	@param contiJikokuOrderOfJikokuhyouIndex [in] 
		時刻表Index-時刻Order対照配列を指定してください。
	@param pCentDedRessya [out]
		列車を指定してください。
	@param pCdCsvDocument [in]
		CSVドキュメントを指定してください。
	@param iColumnIndex [in]
		pCdCsvDocument の列 Index を指定してください。
	@param pstrErrorInfoString [out]
		エラーなら、エラー情報テキストを返します。
	@return
		成功したら 0 以上、エラーなら負の数です。
	*/
	int decode_readRessyaColumn( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const std::deque<int>&	contiJikokuOrderOfJikokuhyouIndex , 
		CentDedRessya* pCentDedRessya , 
		const CdCsvDocument* pCdCsvDocument , 
		int iColumnIndex ,
		std::string* pstrErrorInfoString ) ;

	/**
		CdCsvDocument の指定の列が Null 列車（CSVに何も書かれていない）
		であるか否かを判定します。

		列車の設定にあたっては、
		時刻表Index-時刻Order対照配列を指定する必要があります。
		この配列は、以下の形式でなくてはなりません。

		 contiJikokuOrderOfJjikokuhyouIndex[<時刻表Index>]=<時刻Order>
	
	  CdCsvDocument は、以下の条件を満たしていなくてはなりません。
		
		- 以下の列が設定されている
			- 1行目 FileType行
			- 2行目 DiaName行
			- ＜2.3＞ 3行目 <下り,上り>
			- ＜2.4＞4行目 
		- 列数は、 contiJikokuOrderOfJikokuhyouIndex.size() + 10 

	  この関数は、行Index4に列車番号、
	  行Index (9+ contiJikokuOrderOfJikokuhyouIndex.size() ) に
	備考があるものとして解釈を行います。。

	@param pCentDedRessyasyubetsuContGet [in]
		列車種別コンテナを指定してください。
	@param contiJikokuOrderOfJikokuhyouIndex [in] 
		時刻表Index-時刻Order対照配列を指定してください。
	@param pCentDedRessya [out]
		列車を指定してください。
	@param pCdCsvDocument [in]
		CSVドキュメントを指定してください。
	@param iColumnIndex [in]
		pCdCsvDocument の列 Index を指定してください。
	@param pstrErrorInfoString [out]
		エラーなら、エラー情報テキストを返します。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	この列はNull列車です。
		-	0 ;	//	この列はNull列車ではありません。
	*/
	int decode_isNullRessyaColumn( 
		const Mu<const CentDedRessyasyubetsu*>* 
			pCentDedRessyasyubetsuContGet , 
		const std::deque<int>&	contiJikokuOrderOfJikokuhyouIndex , 
		CentDedRessya* pCentDedRessya , 
		const CdCsvDocument* pCdCsvDocument , 
		int iColumnIndex ,
		std::string* pstrErrorInfoString ) ;

	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CconvJikokuhyouCsv(
		const std::string& nameKudari ,
		const std::string& nameNobori ,
		const std::string& nameRessyabangou ,
		const std::string& nameRessyasyubetsu ,
		const std::string& nameRessyamei ,
		const std::string& nameGousuu ,
		const std::string& nameGou ,
		const std::string& nameBikou ,
		const std::string& nameChaku ,
		const std::string& nameHatsu ,
		const std::string& nameTsuuka ,
		const std::string& nameKeiyunasi ) ;



public:
	// ********************************
	///@name	CconvJikokuhyouCsv
	// ********************************
	///@{
	/**
		指定の路線ファイルデータ・ダイヤ・列車方向の
		時刻表を、CSVドキュメントに出力します。

		*pCdCsvDocument がそれまで保持していたデータは破棄します。
	@param aCentDedRosen [in]
		路線を指定してください。
	@param iDiaIndex [in]
		ダイヤのインデクスを指定してください。
	@param eRessyahoukou [in]
		列車方向を指定してください。
	@param iRessyaIndex [in]
		出力する先頭の列車のインデクス(0起点)
		を指定してください。
	@param iRessyaCount [in] 
		出力する列車の本数を指定してください。
		INT_MAX は、末尾の列車までを指定したことになります。
	@param pCdCsvDocument [out]
		この関数はこの CdCsvDocument オブジェクトに、
		時刻表データを書き込みます。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	iDiaIndex が不正です。
		-	-2 ;	//	iRessyaIndex が不正です。
		-	-3 ;	//	iRessyaCount が不正です。
	*/
	int encode( 
		const CentDedRosen& aCentDedRosen , 
		int iDiaIndex , 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIndex , int iRessyaCount , 
		CdCsvDocument* pCdCsvDocument ) ;

	/**
		時刻表 CSV ドキュメントを、
		指定の路線ファイルデータ・ダイヤ・列車方向の列車コンテナに
		追加します。
	@param pCentDedRosen [in]
		この関数はこの路線に、列車を追加します。
	@param iDiaIndex [in]
		ダイヤのインデクスを指定してください。
	@param eRessyahoukou [in]
		列車方向を指定してください。
	@param iRessyaIndex [in]
		aCdCsvDocument の指定のダイヤ・列車方向において、
		列車を挿入する位置を指定してください。
		-	0 ;	//	先頭に挿入
		-	INT_MAX ;	//	末尾に挿入
	@param aCdCsvDocument [out]
		時刻表データを指定してください。
	@param pstrErrorInfoString [out]
		エラーなら、エラー情報テキストを返します。
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	行が少なすぎます。
		-	-2 ;	//	列が少なすぎます。
		-	-3 ;	//	ファイル形式が認識できません
		-	-4 ;	//	ファイル形式が認識できません
		-	-11  ;	//	駅名が見つかりません。
		-	-21  ;	//	iDiaIndex が不正です。
		-	-22  ;	//	iRessyaIndex が不正です。
	*/
	int decode( 
		CentDedRosen* pCentDedRosen , 
		int iDiaIndex , 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIndex , 
		const CdCsvDocument& aCdCsvDocument , 
		std::string* pstrErrorInfoString ) ;

	///@}
};
} //namespace ConvJikokuhyouCsv

#endif //CconvJikokuhyouCsv_h

