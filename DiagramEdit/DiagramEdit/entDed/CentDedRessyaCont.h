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
//	CentDedRessyaCont.h
// $Id: CentDedRessyaCont.h 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessyaCont_h
#define  CentDedRessyaCont_h

#include "NsMu/CMuiCopiedParent.h"
#include "CentDed.h"
#include "CentDedRessya.h"

namespace entDed{

//前方参照
class CentDedRosen ;
class CentDedDia ;


// ****************************************************************
//	CentDedRessyaCont
// ****************************************************************
/**
@brief
『列車コンテナ』クラス。
同じ路線に属する同じ方向の、0以上複数の『列車』(CentDedRessya) 
オブジェクトを保持するコンテナです。

このクラス自体は、 Mui< CentDedRessya > インターフェースを
サポートします。このインターフェースにより、 CentDedRessya オブジェクトを
追加・削除することができます。

また、 getMuPtr() メソッドにより、
Mu< CentDedRessya* > インターフェースを取得することができます。
このインターフェースにより、コンテナ内の CentDedRessya オブジェクトに
直接アクセス（メソッド呼出）を行うことができます。

制約
 -------------------------------- 
△このコンテナが CentDedRosen の子オブジェクトである場合、
m_iEkiCount と m_iRessyasyubetsuCount は、CentDedRosenに合わせます。

△このコンテナが CentDedDia の子オブジェクトである場合、
m_eRessyahoukou は変更できない(例外スロー)

操作のエラー検査・修正
 -------------------------------- 

△onEkiInsert,onEkiErase : m_iEkiCount を修正する
△onRessyasyubetsuInsert,onRessyasyubetsuErase : m_iRessyasyubetsuCount を修正する

△operator= : このコンテナが CentDedDia の子オブジェクトである場合、
m_iEkiCount,m_iRessyasyubetsuCount,m_eRessyahoukou は変更されず、列車だけが
コピーされます。(コピーされた列車は adjust() により、RessyaContに適合した
駅数・列車種別・方向になります。)



制約に合うように属性を修正(adjust)
 -------------------------------- 
△このコンテナが CentDedRosen の子オブジェクトである場合、
m_iEkiCount と m_iRessyasyubetsuCount は、CentDedRosenに合わせます。


○すべてのCentDedRessya(列車)に、adjust()を委譲する。


 */
class CentDedRessyaCont : public CMuiCopiedParent< CentDedRessya >
{
	typedef CMuiCopiedParent< CentDedRessya > super ;
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	
	/**
		このコンテナに含まれる列車の『駅時刻』の数（ダイヤに含まれる駅の数）。
		既定値は0。
	
		△このコンテナが CentDedRosen の子オブジェクトである場合、
		m_iEkiCount と m_iRessyasyubetsuCount は、CentDedRosenに合わせます。

		CentDedRosenの子でない、独立したインスタンスにおいては、コンストラクタで指定することが
		できます。

		この値は、以下の関数で使われます。
		
		EkiIndexOfEkiOrder,EkiOrderOfEkiIndex,createEmptyCont,createNullRessya 
	
	 */
	int m_iEkiCount ;
	
	/**
		このコンテナに格納される『列車』の列車方向。
		-	下り :	Ressyahoukou_Kudari 
		-	上り : 	Ressyahoukou_Nobori 
		コンストラクタで決まります。
	 */
	ERessyahoukou m_eRessyahoukou ;
	

	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/** 
	 @param eRessyahoukou [in]
		このコンテナに格納される『列車』の列車方向。
		-	下り :	Ressyahoukou_Kudari 
		-	上り : 	Ressyahoukou_Nobori 
	*/
	CentDedRessyaCont( ERessyahoukou m_eRessyahoukou ) ;

	/**
	 @param iEkiCount [in]]
		『列車コンテナ』に含まれる駅の数。
	 @param eRessyahoukou [in]
		このコンテナに格納される『列車』の列車方向。
		-	下り :	Ressyahoukou_Kudari 
		-	上り : 	Ressyahoukou_Nobori 
	 */
	CentDedRessyaCont( 
		int iEkiCount ,
		ERessyahoukou m_eRessyahoukou ) ;

public:
	/**
		このクラスへの代入を行いますが、
		this 『駅』『列車種別』『列車方向』は変更しません。
	 */
	CentDedRessyaCont& operator=( const CentDedRessyaCont& value );
public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素のコピーを追加します。
	 @param element [in]
	 	要素を指定してください。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 以下です。
	 	０は、先頭・size()なら末尾への追加になります。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	0以上は成功、負の数はエラーです
	*/
	virtual int insert( const CentDedRessya& element , int iIndex = INT_MAX ) ;
	
	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素を上書きします。
	 @param element [in]
	 	要素を指定してください。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 未満です。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	0以上は成功、負の数はエラーです
	*/
	virtual int set( const CentDedRessya& element , int iIndex ) ;
	///@}
 public:
	// ********************************
	///@name CentDedRessyaCont-属性
	// ********************************
	///@{
	ERessyahoukou getRessyahoukou()const{	return m_eRessyahoukou ;};
	int getEkiCount()const{	return m_iEkiCount ;};
	///@}

 public:
	// ********************************
	///@name CentDedRessyaCont-関連
	// ********************************
	///@{
	/**
	@return
		このコンテナが CentDedDia に包含されている場合は、
		CentDedDia のアドレス。
		そうでないならNULL。
	*/
	 virtual CentDedDia* getDia(){ return NULL ;}
	/**
	@return
		このコンテナが CentDedRessya に包含されている場合は、
		CentDedRessya のアドレス。
		そうでないならNULL。
	*/
	virtual const CentDedDia* getDia()const{ return NULL ;}

	/**
	@return
		このコンテナが CentDedRosen に包含されている場合は、
		CentDedRosen のアドレス。
		そうでないならNULL。
	*/
	CentDedRosen* getRosen() ;
	/**
	@return
		このコンテナが CentDedRosen に包含されている場合は、
		CentDedRosen のアドレス。
		そうでないならNULL。
	*/
	const CentDedRosen* getRosen()const ;
	///@}
public:
	// ********************************
	///@name CentDedRessyaCont-操作
	// ********************************
	/**
		set() が可能か否かを判断します。

	@param element
		要素を指定してください。 
	@param iIndex
		０から始まるインデクスを指定してください。 範囲は０以上 size() 
		未満です。 但し、INT_MAX は、末尾を指定したものとみなします。 
	@return
		-	0以上: set() が可能。
		-	負の数: set()は、この戻り値で失敗します。
	 */
	virtual int  setable(  const CentDedRessya& element , int iIndex )const ;

	/**
		element がこのコンテナの子である場合は、インデクスを返します。
	@param element
		要素を指定してください。 
	@return
		element がこのコンテナの子である場合は、インデクスを返します。
		そうでない場合は、 -1 です。
	*/
	virtual int  getIndex( const CentDedRessya* element )const ;
	/**
		this の属性が制約に反している場合、制約に合うように、属性を
		修正します。

		○すべてのCentDedRessya(列車)に、adjust()を委譲する。
	*/
	void adjust() ;

	/**
		『駅Order(駅方向別Index)』を、『駅Index』に変換します。
	 @param iEkiOrder [in]
		『駅Order』を指定してください。
	 @return 
		0以上の『駅Index』を返します。
		引数が不正な場合は、 -1 を返します。
	 */
	virtual int EkiIndexOfEkiOrder( int iEkiOrder )const ;
	
	/**
		『駅Index』を『駅Order(駅方向別Index)』に変換します。
	 @param iEkiIndex [in]
		『駅Index』を指定してください。
	 @return 
		0以上の『駅Order』を返します。
		引数が不正な場合は、 -1 を返します。
	 */
	virtual int EkiOrderOfEkiIndex( int iEkiIndex )const ;

	/**
		pCentDedRessyaCont に格納されている列車のうち、
		 iEkiOrder の駅と次の駅の間の駅間最小所要秒数の列車を
		検索し、その所要時間を求めます。
	 @param iEkiOrder [in]
		最小所要秒数を計算する駅の、
		『駅Order』を指定してください。
	 @param pidxRessya [out]
		この関数はここに、駅間最小所要秒数の列車の列車インデクスを
		書き込みます。
		駅間最小所要秒数の列車がみつからない場合、この関数はこの変数に
		-1 を書き込みます。
	 @return
		駅間最小所要秒数を返します。
		駅間最小所要秒数の列車がみつからない場合、この関数は
		既定値の 0 を返します。
		
		  隣り合うＡ駅とＢ駅の間の『駅間最小所要秒数』は、「両駅に停車する
		列車のうち、Ａ駅の発時刻とＢ駅の着時刻が最も短いもの」となります。
		  このとき、Ａ駅の着時刻が指定されていて発時刻が省略されている場合は、
		着時刻＝発時刻とみなします。また、Ｂ駅の着時刻が省略されていて発時刻が
		指定されている場合も、着時刻＝発時刻とみなします。
		
		  両駅に停車する列車がひとつもない場合は、Ａ駅・Ｂ駅を通過する列車に
		指定されている通過時刻をもとに、駅間最小所要秒数を求めます。この場合、
		検索対象となるのは、以下のすべての列車です。
		
			- Ａ駅を通過(通過時刻指定あり)・Ｂ駅を通過(通過時刻指定あり)
			- Ａ駅に停車                  ・Ｂ駅を通過(通過時刻指定あり)
			- Ａ駅を通過(通過時刻指定あり)・Ｂ駅に停車
	 */
	virtual int findEkikanSaisyouSec( 
		int iEkiOrder , 
		int* pidxRessya )const ;

	/**
		指定の列車Index が路線上で運行されている最後の駅
		(getRunLastEkiOrder())の駅時刻よりあとで、
		iEkiOrder を最初の運行駅(getRunFirstEkiOrder())
		とする列車を検索します。
		これは、[直通化]の対象の検索に相当します。
	@param idxRessya [in]
		検索の先頭となる、列車Indexを指定してください。
	@param iEkiOrder [in]
		始発駅の駅Orderを指定してください。
	@return
		対象となる列車の列車Index を返します。
		見つからない場合は、 -1 を返します。


　	  直通化の対象となる途中駅始発列車は、以下の条件を満たした列車です。

　	  - ・フォーカスのある列車(途中駅止まりの列車)と同じ列車種別
　	  - ・フォーカスのある駅が最初の運行区間となる列車
　	  - ・[始発駅の発時刻・終着列車の着時刻の両方が有効な場合は] \n
		始発駅の発時刻が、終着列車の着時刻から12時間以内
　	  - ・時刻表ビュー上で、フォーカスのある列車の右側にある列車

　	  対象となる列車が複数ある場合は、その中でもっとも左側にある列車を直通化の対象とします。
		
	*/
	virtual int findTrainToDirect(
		int idxRessya , 
		int iEkiOrder  ) const ;  

	/**
		指定の駅 Order の駅時刻を、
		駅時刻形式・始発・終着に合わせて変更します。

		変更内容は、 CentDedEkiJikoku::adjustByEkijikokukeisiki 
		の説明を参照してください。

	@see CentDedEkiJikoku::adjustByEkijikokukeisiki 

	@param iEkiOrder [in]
		駅Orderを指定してください。
	@param bChakujikokuHyouji [in]
		駅時刻形式。
		着時刻表示あり。
	@param bHatsujikokuHyouji [in]
		駅時刻形式。
		発時刻表示あり。
	*/
	void adjustByEkijikokukeisiki(
		int iEkiOrder ,
		bool bChakujikokuHyouji , bool bHatsujikokuHyouji ) ;

	///@}

	// ********************************
	///@name CentDedRessyaCont-駅数・列車種別数の変更
	// ********************************
	///@{


	/**
		このコンテナに、指定された『列車種別』の列車があるか否かを調べます。
		属性 m_iEkiCount,m_eRessyahoukou,m_iRessyasyubetsuCount は、
		thisのものを受け継ぎます。
	 @param iRessyasyubetsuIndex [in]
		『列車種別Index』を指定してください。
		範囲は、 0 以上 列車種別の数未満です。
		INT_MAX は、末尾の列車種別を指定したものとみなします。
	 @param piRessyaIndex [out]
		この関数はこの変数に、『列車種別』の列車が見つかった
		列車Index を書き込みます。
		不要なら NULL でもかまいません。
	 @return 
		-	1; //	指定の列車種別の列車が存在します。
		-	0; //	指定の列車種別の列車は存在しません。
		-	-1 ;	//	インデクスが不正
	 */
	int isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piRessyaIndex ) ;
	///@}

	// ********************************
	///@name CentDedRessyaCont-新しいコンテナを生成
	// ********************************
	///@{
	/**
		このコンテナと互換性のある、NULL列車を生成します。

		属性 m_iEkiCount , m_eRessyahoukou , m_iRessyasyubetsuCount は、
		thisのものを受け継ぎます。
	@return
		生成したからコンテナを返します。
	@todo
		当クラス内での、CentDedRessyaコンストラクタ
		CentDedRessya( m_iEkiCount , m_eRessyahoukou )  呼び出しを置き換えます。
	 */
	CentDedRessya createNullRessya() const
	{	return CentDedRessya( m_iEkiCount , m_eRessyahoukou ) ;}

	/**
		this と互換性のある、新たな空コンテナを
		生成します。

		属性 m_iEkiCount , m_eRessyahoukou , m_iRessyasyubetsuCount は、
		thisのものを受け継ぎます。
	@return
		生成したからコンテナを返します。
	@todo
		CentDedRessyaContコンストラクタ
		CentDedRessyaCont( m_iEkiCount , m_eRessyahoukou , m_iRessyasyubetsuCount )
		呼び出しを置き換えます。
	 */
	CentDedRessyaCont createEmptyCont() const
	{
		return CentDedRessyaCont( m_iEkiCount ,
			m_eRessyahoukou ) ;	
	}
	///@}
public:
	// ********************************
	///@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
	///@{
	/**
		m_CentDedEkiCont に CentDedEki が追加された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiOrder
		追加された CentDedEki の駅Order(駅インデクスではありません)。
	*/
	virtual void onEkiInsert( int iEkiOrder );

	/**
		m_CentDedEkiCont から CentDedEki が削除された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiOrder
		削除された CentDedEki の駅Order(駅インデクスではありません)。
	*/
	virtual void onEkiErase( int iEkiOrder  ); 
	/**
		CentDedEkiTrackCont に CentDedEkiTrack が追加された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiOrder
		CentDedEkiTrackCont が追加された CentDedEki の駅Order(駅インデクスではありません)
	@param iEkiTrackIndex
		追加された CentDedEkiTrack のインデクス。
	*/
	virtual void onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex ); 
	/**
		CentDedEkiTrackCont から CentDedEkiTrack が削除された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiOrder
		CentDedEkiTrackCont が削除された CentDedEki 駅Order(駅インデクスではありません)
	@param iEkiTrackIndex
		削除された CentDedEkiTrack の先頭のインデクス。
	*/
	virtual void onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex ); 

	/**
		CentDedRessyasyubetsuCont に CentDedRessyasyubetsu が追加された直後、
		CentDedRessyasyubetsuCont から呼び出されます。
	@param iRessyasyubetsuIndex
		追加された CentDedRessyasyubetsu  のインデクス。
	*/
	virtual void onRessyasyubetsuInsert( int iRessyasyubetsuIndex ); 

	/**
		CentDedRessyasyubetsuCont から CentDedRessyasyubetsu が削除された直後、
		CentDedRessyasyubetsuCont から呼び出されます。
	@param iRessyasyubetsuIndex
		削除された CentDedRessyasyubetsu  のインデクス。
	*/
	virtual void onRessyasyubetsuErase( int iRessyasyubetsuIndex ); 



	///@}
};

} //namespace entDed

#endif /*CentDedRessyaCont_h*/
