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
//	CentDedDgrRessya.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrRessya_h
#define  CentDedDgrRessya_h

#include "NsMu\CMuiCopied.h"
#include "DcDraw\CDcdFreeLine.h"

#include "..\entDed\CentDedRosen.h"
#include "CentDedDgrEkiCont.h"
#include "CentDedDgrEkiJikoku.h"
#include "CentDedDgrRessyasen.h"
#include "CentDedDgrRessyasenCont.h"

namespace entDgr{

using namespace DcDrawLib::DcdCd::Pos;

class CentDedDgrDia ;

// ****************************************************************
//	CentDedDgrRessya
// ****************************************************************
/**
	@brief
	【概要】
	『ダイヤグラムエンティティクラス群』の『ダイヤグラム列車』クラスです。
	『列車』
	
	このクラスは、
	 - 『ダイヤグラム列車線』(CentDedDgrRessyasen)
	
	オブジェクトを包含します。

	【使い方】
	
	１．  コンストラクタでオブジェクトを生成した後、
	 readCentDedRessya() メソッドで、 『列車』 CentDedRessya オブジェクトの
	内容を読み取ってください。
	  この関数は、『列車』 CentDedRessya に包含されている各駅の
	『駅時刻』 CentDedEkiJikoku を読み取って、
	対応する『列車線』 CentDedDgrRessyasen オブジェクトを
	生成し、コンテナに格納します。

	２．  『ダイヤグラム列車線』の

	- 列車線起点駅の駅Order
	- 列車線終点駅の駅Order

	から、 CentDedDgrDia::getYZahyouOfEki() 関数を使うことにより、

  - 列車線起点駅の『ダイヤグラムエンティティY座標』
  - 列車線終点駅の『ダイヤグラムエンティティY座標』

	を求めることができます。
	こうして決定した起点駅のX,Y 座標から終点駅のX,Y座標までの直線が、
	その列車の列車線になります。
 */
class CentDedDgrRessya
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		この列車が『Null状態』なら真、
		有効な列車属性を保持しているのなら偽です。
		
		この属性が真の場合、他の全ての属性・
		および、集約オブジェクトは、意味を持ちません。
		
		コンストラクタか readCentDedRessya() で CentDedRessya をもとに
		決まります。
	 */
	bool m_bIsNull ;

	/**
		この列車の列車方向を示します。
		
		規定値は Ressyahoukou_Kudari です。
		
		コンストラクタか readCentDedRessya() で CentDedRessya をもとに
		決まります。
	 */
	ERessyahoukou	m_eRessyahoukou ;

	/**
		この列車の『列車種別』を、
		『列車種別Index』で保持します。
		
		規定値は 0 です。
	*/
	int	m_iRessyasyubetsuIndex ;
	
	
	/**
		この列車の『列車番号』。
		
		規定値は空文字列です。
		
		コンストラクタか readCentDedRessya() で CentDedRessya をもとに
		決まります。
	 */
	std::string m_strRessyabangou ;
	
	/**
		この列車の『列車名』。
		
		規定値は空文字列です。
		
		コンストラクタか readCentDedRessya() で CentDedRessya をもとに
		決まります。
	 */
	std::string m_strRessyamei ;
	
	/**
		この列車の『号数』。
		
		規定値は空文字列です。
		
		コンストラクタか readCentDedRessya() で CentDedRessya をもとに
		決まります。
	 */
	std::string m_strGousuu ;
	
	/**
		すべての列車線を含む、『ダイヤグラムエンティティX座標』の範囲。
		この列車がNULLなら、Pos=0,Size=0 になります。

		起点と終点とで『ダイヤグラムエンティティX座標』が同じの場合は、
		例外的にサイズが1になります。
	*/
	CdDcdZone	m_DgrXZone ;
	///@}
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		この列車を包含する『ダイヤグラムダイヤ』への関連。
		
		この関連は、m_pCentDedDgrRessyasenCont から、
		Mu< CdDedDgrEki >　にアクセスするために必要になります。

		コンストラクタで決まります。
	*/
	const CentDedDgrDia*	m_pCentDedDgrDia ;	

	///@}
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
		この列車の各駅の駅時刻。
		コンストラクタか readCentDedRessya() で決まります。
	 */
	CMuiCopied< CentDedDgrEkiJikoku > m_MuCentDedDgrEkiJikoku ;
	/**
		この列車の列車線。
		コンストラクタか readCentDedRessya() で決まります。
	 */
	CentDedDgrRessyasenCont*	m_pCentDedDgrRessyasenCont ;

	///@}

private:
	// --------------------------------
	///@name readCentDedRessya() の下請関数
	// --------------------------------
	///@{
	/**
		readCentDedRessya() の下請関数

		(01)CentDedDgrRessyaの属性のうち、CentDedRessya のみで決定する属性を設定
	*/
	void readCentDedRessya_01_readProp( const CentDedRessya* pCentDedRessya ) ;
	/**
		readCentDedRessya() の下請関数

		(02)CentDedDgrEkiJikoku を生成し、 CentDedEkiJikoku で決まる属性を決定。
	*/
	void readCentDedRessya_02_CreateCentDedEkiJikoku( 
		const CentDedRessya* pCentDedRessya ) ;

	/**
		readCentDedRessya() の下請関数

		(03)CentDedDgrRessyaの以下の属性を、CentDedDgrEkiJikokuの属性をもとに生成。

		CdDcdZone	m_zoneDgrXZahyou
	*/
	void readCentDedRessya_03_updateDgrXZone() ;

	/**
		readCentDedRessya() の下請関数

		(04)CentDedDgrEkijikokuの以下の属性を、CentDedDgrEki の属性をもとに決定。
		m_bShouldRessyajouhouDraw //列車情報をこの駅の場所に描画するなら真です。

			列車情報描画の条件は、列車線の存在する駅間における、
			以下のいずれかの条件を満たす駅間。
			
			(1)   [この列車の列車情報がまだ1箇所も描画されていない]場合は、
				列車情報描画が「表示しない」以外の駅間。
			(2)  列車情報描画が「常に表示」の駅間
			
		この条件に合う列車情報描画位置がない場合は、
		最初の列車線位置に描画します(「表示しない」であっても)。
	*/
	void readCentDedRessya_04_updateShouldRessyajouhouDraw(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) ;

	/**
		readCentDedRessya() の下請関数

		(05)経由なしの前後の着発時刻を補う
		
		- 連続した経由なしの直前に着時刻がない AND 
			経由なしの直後に着時刻がある場合は、直前の着時刻を補います。
		- 連続した経由なしの直前に発時刻がない AND 
			経由なしの直後に発時刻がある場合は、直前の発時刻を補います。

		- 連続した経由なしの直前に着時刻がある AND 
			経由なしの直後に着時刻がない場合は、直後の着時刻を補います。
		- 連続した経由なしの直前に発時刻がある AND 
			経由なしの直後に発時刻がない場合は、直後の発時刻を補います。

	*/
	void readCentDedRessya_05_complementKeiyunasiSide() ;

	/**
		readCentDedRessya() の下請関数

		(06_01)長時間停車を解決
			(長時間停車の着時刻=なし・発時刻=あり の駅に、着時刻を補う)

		以下の駅時刻の並びを探します。
		- (1)発時刻=あり、駅扱={停車,通過}のいずれか
		- (2)「着時刻=なし、発時刻=なし、駅扱={通過,経由なし}のいずれか」の
			0個以上の並び
		- (3)着時刻=なし、発時刻=あり AND 列車の終着駅でない
		
		(1)の発時刻+(1)～(3)間の駅間最小所要秒数＜(3)の発時刻-60秒なら、@n
		(3)の着時刻=(1)の発時刻+(1)～(3)間の駅間最小所要秒数
		とします。
	*/
	void readCentDedRessya_06_complementLongStop_01(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) ;

	/**
		readCentDedRessya() の下請関数

		(06_02)長時間停車を解決
			(長時間停車の着時刻=あり・発時刻=なし の駅に、発時刻を補う)

		以下の駅時刻の並びを探します。

		- (1)着時刻=あり、発時刻=なし
		- (2)「着時刻=なし、発時刻=なし、駅扱={通過,経由なし}のいずれか」の
			0個以上の並び
		- (3)着時刻=あり、駅扱={停車,通過}のいずれか

		(1)の着時刻＜(3)の着時刻-(1)～(3)間の駅間最小所要秒数-60秒なら、@n
		(1)の発時刻=(3)の着時刻-(1)～(3)間の駅間最小所要秒数
		とします。
	*/
	void readCentDedRessya_06_complementLongStop_02(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) ;

	/**
	(08)CentDedDgrRessyasenのコンテナを生成し、
	  CentDedDgrEkijikoku::m_iDgrXPosOnRessyasen
	を修正
	*/
	void readCentDedRessya_08_updateRessyasenCont(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) ;

	///@}

	// --------------------------------
	///@name readCentDedRessya_08_updateRessyasenCont() の下請関数
	// --------------------------------
	///@{

	/**
		readCentDedRessya_08_updateRessyasenCont() の下請関数です。
	
	(01)『列車線起点駅Order』を探します。

	 @param pCentDedRessya [in]
		対象となる列車オブジェクトを指定して下さい。
	 @param iEkiOrder [in]
		この関数は、この『駅Order』以降で、
		『列車線起点駅Order』を探します。
	 @param piRessyasenKitenEkiOrder [out]
		この関数は、成功したら、
		『列車線起点駅Order』をこの変数に書き込みます。
	 @return
		成功したら、0以上、エラーなら負の数です。
		-	0 ;	//	『列車線起点駅Order』がみつかりました。
		-	-1 ;	//	iEkiOrder 以降で、列車線起点駅がありません。
	
	
		『列車線起点駅Order』の条件は、
		「着時刻・発時刻のいずれかが指定されている AND 
		次の『駅Order』の駅扱が『停車』か『通過』」
	*/
	int updateRessyasenCont_01_calcRessyasenKiten( 
		int iEkiOrder ,
		int* piRessyasenKitenEkiOrder ) ;

	/**
		readCentDedRessya_08_updateRessyasenCont() の下請関数です。
	
		(02)『列車線起点駅Order』に対応する『列車線終点駅Order』を検索します。
	
	　	  (1)　『列車線終点駅Order』の条件は、
		「着時刻・発時刻の両方が指定されている」 OR
		「 次の駅の駅扱いが『運行なし』 」 OR
		「「『駅Order』が、その列車におけるの終着駅」 
	　	  対象駅がみつからなければ、列車線終点駅Orderの決定は失敗となります
		  (経由なしの直前は、列車線の終点にはなりません
		  　(この時点での列車線起点と終点は、経由なしをまたぐことがあります。)

	　	  (2)　この時点で、『列車線終点駅Order』に着時刻も発時刻も
		設定されていない場合は、
		始発駅方向に向かって、着時刻・発時刻のいずれかが指定されている
		駅を検索します。
　		  この結果『列車線終点駅Order』に相当する駅がない場合は、
		列車線終点駅Orderの決定は失敗となります。

	 @param iRessyasenKitenEkiOrder [in]
		『列車線起点駅Order』を指定して下さい。
	 @param piRessyasenSyuutenEkiOrder [out]
		この関数は、成功したら、
		『列車線終点駅Order』をこの変数に書き込みます。
	 @return
		成功したら、0以上、エラーなら負の数です。
		-	0 ;	//	『列車線終点駅Order』がみつかりました。
		-	-1 ;	//	列車線終点駅がありません。
					//	この区間に関しては、列車線を作成できません。
	 */
	int updateRessyasenCont_02_calcRessyasenSyuuten( 
		int iRessyasenKitenEkiOrder ,
		int* piRessyasenSyuutenEkiOrder ) ;
	
	/**
		readCentDedRessya_08_updateRessyasenCont() の下請関数です。
	
		(04)『ダイヤグラム列車線』オブジェクト内の
		『列車線起点駅Order』と『列車線終点駅Order』の間の
		途中駅で、
	
		「着時刻・発時刻のいずれかが指定されている主要駅」OR
	
		「通過駅で、
		着時刻か発時刻のいずれかが指定されている」 
	
		 があれば、
		それを『列車線終点駅Order』にします。
	
	 @param pMuCdDedDgrEki [in]
		『ダイヤグラム駅』情報へのインターフェースを指定して下さい。
	 @param iRessyasenKitenEkiOrder [in]
		『列車線起点駅Order』を指定して下さい。
	 @param piRessyasenSyuutenEkiOrder [in,out]
		『列車線終点駅Order』を指定してください。
		この関数は、成功したら、この値を上書き修正します。
	 @return
		成功したら、0以上、エラーなら負の数です。
		-	0 ;	//	『列車線終点駅Order』の補正の必要はありませんでした。
		-	1 ;	//	『列車線終点駅Order』の補正を行いました。
	 */
	int updateRessyasenCont_04_adjustRessyasenSyuuten4( 
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iRessyasenKitenEkiOrder ,
		int* piRessyasenSyuutenEkiOrder ) ;


	/**
		readCentDedRessya_08_updateRessyasenCont() の下請関数です。
	
		(05)『列車線コンテナ CentDedDgrRessyasenCont 』の末尾の
		『列車線 CentDedDgrRessyasen』の途中駅の中で、
		列車線の位置(CentDedDgrEkiJikoku::m_iDgrXPosRessyasen)と
		着時刻・発時刻(CentDedDgrEkiJikoku::m_iDgrXPosChaku,m_iDgrXPosHatsu)の
		差が60 秒以上ある場合は、その駅を『列車線終点駅Order』とします。
	 @param pCentDedDgrRessyasen [in,out]
		『列車線終点駅Order』を指定してください。
		この関数は、成功したら、この値を上書き修正します。
	 @return
		成功したら、0以上、エラーなら負の数です。
		-	0 ;	//	『列車線終点駅Order』の補正の必要はありませんでした。
		-	1 ;	//	『列車線終点駅Order』の補正を行いました。
	 */
	int updateRessyasenCont_05_adjustRessyasenSyuuten5( 
		int* piRessyasenSyuutenEkiOrder ) ;

	/**
		readCentDedRessya_08_updateRessyasenCont()の下請関数です。

		(06)コンテナ末尾の列車線が途中に「経由なし」を含む場合、
		その列車線を「経由なし」までに短縮します。

		- (1)「経由なし」直前の駅・直後の駅の着・発時刻を「列車線駅時刻」
			に置き換えます。
		- (2)列車線は「経由なし」直前までに短縮します。
		- (3)列車線終点を「経由なし」の直前とします。
		
	
	 @param pCentDedDgrRessyasen [in,out]
		『列車線終点駅Order』を指定してください。
		この関数は、成功したら、この値を上書き修正します。
	 @return
		成功したら、0以上、エラーなら負の数です。
		-	0 ;	//	『列車線』『駅時刻』『終点駅Order』の補正の必要は
			ありませんでした。
		-	1 ;	//	『列車線』『駅時刻』『終点駅Order』の補正を行いました。
	*/
	int updateRessyasenCont_06_reduceToKeiyunasi( 
		int* piRessyasenSyuutenEkiOrder ) ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
		readCentDedRessya() を行います。
	 @param pCentDedRosen [in]
		CentDedRessya オブジェクトを包含している
		CentDedRosen オブジェクトを指定してください。
		このオブジェクトは、列車種別に関する属性
		- m_CdLineProp
		- m_CdDrawTextProp 
		を決定するのに使います。
	 @param pCentDedDgrDia [in]
		this を包含している『ダイヤグラム駅』オブジェクトの
		『ダイヤ』オブジェクトを指定してください。
		このオブジェクトは、駅間の概算所要時分を求めるのに使います。
	 @param pCentDedRessya [in]
		対象となる列車オブジェクトを指定してください。
	*/
	CentDedDgrRessya( 
		const CentDedRosen* pCentDedRosen ,
		const CentDedDgrDia* pCentDedDgrDia ,
		const CentDedRessya* pCentDedRessya ) ; 
	
	/** 
		NULL の列車を生成します。
	 @param pCentDedDgrDia [in]
		this を包含している『ダイヤグラム駅』オブジェクトの
		『ダイヤ』オブジェクトを指定してください。
		このオブジェクトは、駅間の概算所要時分を求めるのに使います。
	*/
	CentDedDgrRessya( 
		const CentDedDgrDia* pCentDedDgrDia ) ;

	/**
		コピーコンストラクタで指定できるのは、
		同じ m_pCentDedDgrDia を持つ列車に限定されます。
	*/
	CentDedDgrRessya( const CentDedDgrRessya& value ) ;
private:
	CentDedDgrRessya& operator=( const CentDedDgrRessya& value );
public:
	virtual ~CentDedDgrRessya() ;
	
// ********************************
//	CentDedDgrRessya
// ********************************
	// ********************************
	///@name CentDedDgrRessya-属性
	// ********************************
	///@{
	bool getIsNull()const ;
	ERessyahoukou	getRessyahoukou()const ;
	CentDedDgrRessya& setRessyahoukou( ERessyahoukou value ) ;
	int	getRessyasyubetsuIndex()const ;
	void setRessyasyubetsuIndex( int value ) ;

	std::string getRessyabangou()const ;
	CentDedDgrRessya& setRessyabangou( const std::string& value ) ;
	std::string getRessyamei()const ;
	CentDedDgrRessya& setRessyamei( const std::string& value ) ;
	std::string getGousuu()const ;
	CentDedDgrRessya& setGousuu( const std::string& value ) ;
	CdDcdZone	getDgrXZone()const ;
	///@}
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		この列車を包含する『ダイヤグラムダイヤ』への関連。
		
		m_pCentDedDgrRessyasenCont が
		CentDedEkiCont への関連を必要とします。

		コンストラクタで決まります。
	*/
	const CentDedDgrDia*	getCentDedDgrDia()const
	{ return m_pCentDedDgrDia ;}	

	///@}
	
	// ********************************
	///@name CentDedDgrRessya-包含
	// ********************************
	///@{
	Mu< CentDedDgrEkiJikoku* >* getMuCentDedDgrEkiJikoku() ;
	const Mu< const CentDedDgrEkiJikoku* >* getMuCentDedDgrEkiJikoku()const ;
	Mu< CentDedDgrRessyasen* >* getCentDedDgrRessyasenCont() ;
	const Mu< const CentDedDgrRessyasen* >* getCentDedDgrRessyasenCont()const ;
	///@}
	// ********************************
	///@name CentDedDgrRessya-操作
	// ********************************
	///@{
	/**
		すべての属性・包含オブジェクトをクリアします。
		この列車は、 NULL となります。
	*/
	void clear() ;


	/**
		CentDedRessya オブジェクトの内容をもとに、
		this の属性・及び 『ダイヤグラム列車線』 (CentDedDgrRessyasen)
		オブジェクトを生成します。
	 @param pCentDedRosen [in]
		CentDedRessya オブジェクトを包含している
		CentDedRosen オブジェクトを指定してください。
		このオブジェクトは、列車種別に関する属性
		- m_CdLineProp
		- m_CdDrawTextProp 
		を決定するのに使います。
	 @param pCentDedDgrDia [in]
		this を包含している『ダイヤグラム駅』オブジェクトの
		『ダイヤ』オブジェクトを指定してください。
		このオブジェクトは、駅間の概算所要時分を求めるのに使います。
	 @param pCentDedRessya [in]
		対象となる列車オブジェクトを指定してください。
	 */
	virtual int readCentDedRessya(
		const CentDedRosen* pCentDedRosen ,
		const CentDedDgrDia* pCentDedDgrDia ,
		const CentDedRessya* pCentDedRessya ) ; 

	/**
	 @return
		この列車の始発駅の『駅Order』を返します。
		すべての『駅時刻』が『運行なし』の場合は、-1 を返します。
		この場合、この列車自体が『運行なし』となります。
	 */
	int getSihatsuEki()const ;

	/**
	 @return
		この列車の終着駅の『駅Order』を返します。
		すべての『駅時刻』が『運行なし』の場合は、-1 を返します。
		この場合、この列車自体が『運行なし』となります。
	 */
	int getSyuuchakuEki()const ;

	/**
		列車が指定の 『駅Order』と、次の『駅Order』の間を
		運行しているか否かを調べます。

		「指定の 『駅Order』と、次の『駅Order』の間を
		運行している」は、
		指定の 『駅Order』と、次の『駅Order』の両方が
		『停車』または『通過』の場合が、これに該当します。
		ダイヤグラムビューでは、この列車のこの駅間には列車線が
		描画されます。

	@param iEkiOrder [in]
		対象となる駅間の起点側の『駅Order』を指定してください。
		範囲は、0以上、(駅の数-1)未満です。
	@return
		列車が iEkiOrder と次の駅の間を運行しているなら true です。
		そうでない場合は、 false です。
		引数が範囲外の場合も、false です。
	@attention
		どちらかの駅・または両方の駅が『経由なし』の場合は、
		「駅の間を運行している」とはみなしません。
		この場合、このメソッドの戻り値は偽となります。
	*/
	bool isRunBetweenNextEki( int iEkiOrder )const ;

	/**
		指定の２つの駅間の間の、駅間最小所要秒数を算出します。
		運行なし・経由なしの駅間(ダイヤグラム列車線の描画されない駅間)の
		所要秒数は含みません。
	@param pMuCdDedDgrEki [in]
		駅の情報のマルチオブジェクトを指定してください。
	@param iEkiOrderBefore [in]
		始発駅寄りの駅Orderを指定してください。
	@param iEkiOrderAfter [in]
		終着駅寄りの駅Orderを指定してください。
	@return
		最小所要秒数の和を返します。
	*/
	int calcEkikanSaisyouSec(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iEkiOrderBefore ,
		int iEkiOrderAfter )const ; 

	/**
		指定の２つの駅の駅間の、DgrY座標幅を算出します。
		運行なし・経由なしの駅間(ダイヤグラム列車線の描画されない駅間)・
		駅のDgrY座標サイズ(列車線が描画されない領域)は
		含みません。
	@param pMuCdDedDgrEki [in]
		駅の情報のマルチオブジェクトを指定してください。
	@param iEkiOrderBefore [in]
		始発駅寄りの駅Orderを指定してください。
	@param iEkiOrderAfter [in]
		終着駅寄りの駅Orderを指定してください。
	@return
		最小所要秒数の和を返します。
	*/
	int calcDgrYEkikanSize(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iEkiOrderBefore ,
		int iEkiOrderAfter )const ; 


	/**
		すべての『ダイヤグラム駅時刻』オブジェクトの
		『ダイヤグラムエンティティX座標』を加算・減算します(NULLを示す INT_MIN は除く。
	 @param iSeconds [in]
		加算・減算する値（秒数・『ダイヤグラムエンティティX座標』）	
		を指定して下さい。
	 */
	virtual void modifyDgrXPos(	int iSeconds ) ; 

	
	/**
		『列車線』オブジェクトをもとにして、
		『時刻Order』に対応する	『ダイヤグラムエンティティX座標』を取得します。
	 @param aCdDcdJikokuOrder [in]
		『時刻Order』を指定して下さい。
	 @param piDgrXPos [out] 
		この関数は、成功したら、
		『時刻Order』に対応する、『ダイヤグラムエンティティX座標』を
		このアドレスに書き込みます（負の数の場合があります）。
	 @return 
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	列車が指定の『時刻Order』を含む
		『列車線』オブジェクトを所持していません。
	
		指定の『時刻Order』が奇数(発時刻)で、それが『ダイヤグラム列車線』の
		起点になっている場合・・・
		『ダイヤグラム列車線』の起点の駅時刻
	
		指定の『時刻Order』が『ダイヤグラム列車線』の
		中間点になっている場合・・・
		その『時刻Order』を『駅Order』に変換し、列車線上の座標をもとに
		概算した時刻。
	
		指定の『時刻Order』が偶数で、それが『ダイヤグラム列車線』の
		終点になっている場合・・・
		『ダイヤグラム列車線』の終点の駅時刻
	
	@todo
		戻り値の仕様を変更します。piDgrXPosを戻り値にし、引数は減らします。
	*/
	virtual int getDgrXPosOfJikokuOrder(
		CdDedJikokuOrder aCdDedJikokuOrder , 
		int* piDgrXPos )const ; 

	/**
		『列車線』オブジェクトをもとにして、
		『駅Order』に対応する、発時刻の
		『ダイヤグラムエンティティX座標』を取得します。
	 @param iEkiOrder [in]
		『駅Order』を指定して下さい。
	 @param piDgrXPos [out] 
		この関数は、成功したら、
		『駅Order』に対応する、『ダイヤグラムエンティティX座標』を
		このアドレスに書き込みます（負の数の場合があります）。
	 @return 
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	列車が指定の『駅Order』を含む
		『列車線』オブジェクトを所持していません。
	
		この関数は、ダイヤグラム上に『列車情報』を
		描画する際、テキストの位置を決めるのに使うことを
		想定しています。
		この関数が返す値は、以下のルールに則ります。
	
		指定の『駅Order』が『ダイヤグラム列車線』の
		起点になっている場合・・・
		『ダイヤグラム列車線』の起点の駅時刻
	
		指定の『駅Order』が『ダイヤグラム列車線』の
		中間点になっている場合・・・
		その『駅Order』をもとに、概算した時刻
	
		指定の『駅Order』が『ダイヤグラム列車線』の
		起点にはなっていないが、終点にはなっている場合・・・
		『ダイヤグラム列車線』の終点の駅時刻
	*/
	virtual int getDgrXPosOfEkiOrder(
		int iEkiOrder , 
		int* piDgrXPos )const ; 


	///@}

};

} //namespace entDgr
#endif /*CentDedDgrRessya_h*/


