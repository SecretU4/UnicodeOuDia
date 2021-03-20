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
// $Id: CentDedRessyaCont.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessyaCont_h
#define  CentDedRessyaCont_h

#include "Mu/CMuiCopied.h"

#include "CentDed.h"
#include "CentDedRessya.h"

// ****************************************************************
//	CentDedRessyaCont
// ****************************************************************
/**
 @brief
	【概要】
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

 @attention
	this の get() メソッドは、CentDedRessya オブジェクトのコピーを返します。
	get() メソッドで返されたオブジェクトに対して、
	CentDedRessya オブジェクトを更新するメソッドを呼び出しても、
	コンテナ内の CentDedRessya オブジェクトを更新することはできません。\n
	コンテナ内の CentDedRessya オブジェクトのメソッドを呼び出す場合は、
	getMuPtr() で Mu<CentDedRessya*>* を取得してから、
	そのインターフェース経由で CentDedRessya* を取得し、そのポインタに
	メソッドを呼び出してください。
	
	このコンテナの set() ・ insert() は、指定された CentDedRessya オブジェクト
	をコピーコンストラクタでコピーした上で、コンテナに保持します。
	set()・ insert() で指定したオブジェクトは、関数終了後は破棄しても
	かまいません。

	このオブジェクトが保持する CentDedRessya は、
	『列車方向』 (CentDedRessya::m_eRessyahoukou) ・
	『駅の数』 ( CentDedRessya::m_CentDedEkiJikokuCont.size() )
	がすべて同じになります。
	また、『列車種別Index』  (CentDedRessya::m_iRessyasyubetsuIndex ) は、
	this の属性 『列車種別数』 ( m_iRessyasyubetsuCount )未満に
	制限されます。
	set() , insert() は、指定された CentDedRessya の
	『列車方向』 (CentDedRessya::m_eRessyahoukou) ・
	『駅の数』 ( CentDedRessya::m_CentDedEkiJikokuCont.size() ) ・
	『列車種別Index』  (CentDedRessya::m_iRessyasyubetsuIndex ) 
	を修正したうえで、コンテナに保存します。
 */
class CentDedRessyaCont : public CMuiCopied< CentDedRessya >
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	typedef CMuiCopied< CentDedRessya > super ;
	
public:
	// ********************************
	///@name 集約
	// ********************************
	///@{
	///@}
	// ********************************
	///@name 属性
	// ********************************
	///@{
	
	/**
		このコンテナに含まれる列車の『駅時刻』の数（ダイヤに含まれる駅の数）。
	
		この値は、列車が属している CentDedRosen オブジェクトの
		 CentDedEki の数に等しくなります。
	
		この値は、コンテナに『列車』 ( CentDedRessya ) オブジェクトを追加
		する場合に必要になります。
	 */
	int m_iEkiCount ;
	
	/**
	 @param eRessyahoukou [in]
		このコンテナに格納される『列車』の列車方向。
		-	下り :	Ressyahoukou_Kudari 
		-	上り : 	Ressyahoukou_Nobori 
		コンストラクタで決まります。
	
		この値は、コンテナに『列車』 ( CentDedRessya ) オブジェクトを追加
		する場合に必要になります。
	 */
	ERessyahoukou m_eRessyahoukou ;
	
	/**
		このコンテナに含まれる列車の『列車種別数』。
	
		この値は、列車が属している CentDedRosen オブジェクトの
		CentDedRessyasyubetsu の数に等しくなります。
	
		この値は、コンテナに『列車』 ( CentDedRessya ) オブジェクトを追加
		する場合に必要になります。
	 */
	int m_iRessyasyubetsuCount ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	 @param iEkiCount [in]]
		『列車コンテナ』に含まれる駅の数。\n
	 @param eRessyahoukou [in]
		このコンテナに格納される『列車』の列車方向。
		-	下り :	Ressyahoukou_Kudari 
		-	上り : 	Ressyahoukou_Nobori 
	 @param iRessyasyubetsuCount [in]
		このコンテナに含まれる列車の『列車種別数』。
	
		この値は、列車が属している CentDedRosen オブジェクトの
		CentDedRessyasyubetsu の数に等しくなります。
	
		この値は、コンテナに『列車』 ( CentDedRessya ) オブジェクトを追加
		する場合に必要になります。
	 */
	CentDedRessyaCont( 
		int iEkiCount ,
		ERessyahoukou m_eRessyahoukou ,
		int iRessyasyubetsuCount 
	) ;


	CentDedRessyaCont( const CentDedRessyaCont& value );
	
	/**
		このクラスへの代入を行いますが、
		this の『駅』の数 ( m_iEkiCount ) は変更しません。
	
		this が包含する『列車』( CentDedRessya )  のコピーには、
		CentDedRessya& operator=( const CentDedRessya& value ) 
		を使います。
	 */
	CentDedRessyaCont& operator=( const CentDedRessyaCont& value );

	virtual ~CentDedRessyaCont();

public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	///@}
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
	virtual int insert( const CentDedRessya& element , int iIndex = INT_MAX ) 
	{
		if ( element.getCentDedEkiJikokuCount() == m_iEkiCount && 
			element.getRessyahoukou() ==  m_eRessyahoukou && 
			element.getRessyasyubetsuIndex() < m_iRessyasyubetsuCount )
		{
			return super::insert( element , iIndex ) ;
		}
		// --------------------------------
		CentDedRessya aCentDedRessya = CentDedRessya( m_iEkiCount , m_eRessyahoukou ) ;
		aCentDedRessya = element ;

		//	挿入される列車の種別Indexが規定以上なら、０に変更
		if ( aCentDedRessya.getRessyasyubetsuIndex() >= m_iRessyasyubetsuCount ){
			aCentDedRessya.setRessyasyubetsuIndex( m_iRessyasyubetsuCount - 1 ) ;
		}
		return super::insert( aCentDedRessya , iIndex ) ;
	}
	
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
	virtual int set( const CentDedRessya& element , int iIndex ) 
	{
		if ( element.getCentDedEkiJikokuCount() == m_iEkiCount && 
			element.getRessyahoukou() ==  m_eRessyahoukou && 
			element.getRessyasyubetsuIndex() < m_iRessyasyubetsuCount )
		{
			return super::set( element , iIndex ) ;
		}
		// --------------------------------
		CentDedRessya aCentDedRessya = CentDedRessya( m_iEkiCount , m_eRessyahoukou ) ;
		aCentDedRessya = element ;

		//	挿入される列車の種別Indexが規定以上なら、０に変更
		if ( aCentDedRessya.getRessyasyubetsuIndex() >= m_iRessyasyubetsuCount ){
			aCentDedRessya.setRessyasyubetsuIndex( m_iRessyasyubetsuCount - 1 ) ;
		}
		return super::set( aCentDedRessya , iIndex ) ;
	}
	///@}
	// ********************************
	///@name CentDedRessyaCont-属性
	// ********************************
	///@{
	ERessyahoukou getRessyahoukou()const{	return m_eRessyahoukou ;};
	int getEkiCount()const{	return m_iEkiCount ;};
	int getRessyasyubetsuCount()const{	return m_iRessyasyubetsuCount ;};

	///@}
	// ********************************
	///@name CentDedRessyaCont-操作
	// ********************************
	///@{

	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	空の列車を追加します。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 以下です。
	 	０は、先頭・size()なら末尾への追加になります。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	0以上は成功、負の数はエラーです
	 */
	virtual int insertBlank( int iIndex = INT_MAX ) ;
	
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
		このコンテナに含まれるすべての
		『ダイヤ』 ( CentDedDia )に対し、
		『駅』オブジェクトの属性の変更を通知します。

		処理内容は。CentDedRessya::onSetCentDedEki() の説明を参照してください。

	@see CentDedRessya::onSetCentDedEki() 
	@param iEkiOrder [in]
		オブジェクトを挿入する位置を『駅Order』で指定してください。
		範囲は 0 以上 m_iEkiCount 以下です。
	@return
		成功したら 0 以上、エラーなら負の数です。
	 */
	int onSetCentDedEki( const Mu<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder ) ;

	/**
		この『列車コンテナ』に含まれるすべての
		『列車』 ( CentDedRessya )に対し、
		『駅時刻』オブジェクトを、指定の位置に挿入します。
	 @param iEkiOrder [in]
		オブジェクトを挿入する位置を『駅Order』で指定してください。
		範囲は 0 以上 m_iEkiCount 以下です。
		INT_MAX を指定すると、末尾を指定したものとみなします。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	インデクスが不正です。
	 */
	int insertCentDedEkiJikoku(	int iEkiOrder = INT_MAX ) ;
	
	/**
		この『列車コンテナ』に含まれるすべての『列車』 ( CentDedRessya )に
		対し、
		『駅時刻』オブジェクトを、指定の位置から削除します。
	 @param iEkiOrder [in]
		オブジェクトを挿入する位置を『駅Order』で指定してください。
		範囲は 0 以上 m_iEkiCount 未満です。
		INT_MAX を指定すると、末尾を指定したものとみなします。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	インデクスが不正です。
	 */
	int eraseCentDedEkiJikoku( int iEkiOrder = INT_MAX ) ;

	/**
		『列車種別』の追加に伴い、
		この『列車コンテナ』に含まれるすべての
		『列車』 ( CentDedRessya ) の『列車種別Index』を修正します。
	
		この『列車コンテナ』に含まれるすべての
		『列車』 ( CentDedRessya ) のうち、
		引数 iRessyasyubetsuIndex 以上の 『列車種別Index』を持つ
		『列車』 ( CentDedRessya ) の『列車種別Index』を 1 加算します。
	
		また、同時に this の m_iRessyasyubetsuCount も 1 加算します。
	
	 @param iRessyasyubetsuIndex [in]
		列車種別の追加位置を指定してください。
		範囲は 0 以上 m_iRessyasyubetsuCount 以下です。
		INT_MAX を指定すると、末尾を指定したものとみなします。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	インデクスが不正です。
	 */
	int insertRessyasyubetsuIndex( int iRessyasyubetsuIndex = INT_MAX ) ;
	
	/**
		『列車種別』の削除に伴い、
		この『列車コンテナ』に含まれるすべての
		『列車』 ( CentDedRessya ) の『列車種別Index』を修正します。
	
		この『列車コンテナ』に含まれるすべての
		『列車』 ( CentDedRessya ) のうち、
		引数 iRessyasyubetsuIndex より大きい 『列車種別Index』を持つ
		『列車』 ( CentDedRessya ) の『列車種別Index』を 1 減算します。
	
		また、同時に this の m_iRessyasyubetsuCount も 1 加算します。
	
	 @param iRessyasyubetsuIndex [in]
		削除する列車種別Indexを指定してください。
		範囲は 0 以上 m_iRessyasyubetsuCount 未満です。
		INT_MAX を指定すると、末尾を指定したものとみなします。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	インデクスが不正です。
		-	-3 ;	//	『列車種別』が iRessyasyubtsuIndex の列車が存在します。
	 */
	int eraseRessyasyubetsuIndex( int iRessyasyubetsuIndex  = INT_MAX ) ;

	/**
		このコンテナに、指定された『列車種別』の列車があるか否かを調べます。
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
};


#endif /*CentDedRessyaCont_h*/
