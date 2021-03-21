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
//	CentDedRessya.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessya_h
#define  CentDedRessya_h


#include "CentDed.h"
#include "CentDedEkiJikokuCont.h"
#include "CentDedEkiJikoku.h"
#include "CdDedJikan.h"
#include "CentDedEkiCont.h"
#include "CdDedJikokuOrder.h"

namespace entDed{
	using namespace OuLib::NsMu ;
	using namespace std ;

// ****************************************************************
//	CentDedRessya
// ****************************************************************
/**
@brief
   DiagramEdit の、路線上で運行される『列車』１本を表します。
	
このクラスのインスタンスは、通常は『路線』（ CentDedRosen ）に
包含されます。

実際には、

  - 『路線』 (CentDedRosen) が『ダイヤ』 ( CentDedDia ) を
０以上複数包含
  - 各『ダイヤ』 ( CentDedDia ) が『列車』 (CentDedRessya ) を
０以上複数包含

という関係になっています。

このクラスは、『路線』（ CentDedRosen ）に存在する
『駅』 ( CentDedEki )の数だけ、『駅時刻』(CentDedEkiJikoku）
オブジェクトを保持します。『路線』 ( CentDedRosen )に包含される
すべての『列車』( CentDedRessya )が包含する
『駅時刻』 ( CentDedEkiJikoku ) オブジェクトの数は、
『路線』 ( CentDedRosen )の『駅』 ( CentDedEki ) の数と同じでなくては
なりません。

  この同期をとるため、『列車』 ( CentDedRessya ) に対する
『駅時刻』 ( CentDedEkiJikoku ) オブジェクトの追加・削除の操作は制限
されています。

  また、このクラスが保持する、『列車種別Index』属性は、
『路線』( CentDedRosen )が保持する『列車種別』 ( CentDedRessyasyubetsu )
オブジェクトに対応します。

このオブジェクトは、有効な列車データをもたない『Null状態』を
とることができます。
『Null状態』の列車は、『時刻表ビュー』では空行として表示されます。

<H4>
【駅Index と 駅Order , 時刻Order】
</H4>
  『路線』 ( CentDedRosen ) オブジェクト内の特定の
『駅』 ( CentDedEki )オブジェクトを指定する方法、及び
『列車』 ( CentDedRessya )オブジェクト内の特定の
『駅時刻』 ( CentDedEkiJikoku ) オブジェクトを指定する方法には、
『駅Index』・『駅Order』の２つがあります。どちらも、
0 以上 ( 駅の数) 未満 の整数で、『駅』を指定します。

  『駅Index』は、路線の下り列車の始発駅（上り列車の終着駅）が 0 ・ 
下り列車の終着駅（上り列車の始発駅） が ( 駅の数 - 1 ) となります。

  『駅Oeder』は、列車の方向別のインデクスです。下り列車・上り列車
ともに始発駅が 0 ・ 終着駅が ( 駅の数 - 1 ) と
なります。

  従って、『駅Index』が 0 の駅は、下り列車にとっては『駅Oeder』 も
 0 ですが、上り列車にとっては『駅Order』 は （駅の数 - 1 ）となります。 

  『路線』 ( CentDedRosen ) クラスでは、原則として
『駅』( CentDedEki ) オブジェクトを指定するのに『駅Index』を使います。
『駅』を保持するコンテナ CentDedRosen::m_CentDedEkiCont の添え字も
『駅Index』になっています。

  これとは対照的に、『列車』(クラスでは、原則として
『駅時刻』 ( CentDedEkiJikoku ) オブジェクトを指定するのには
『駅Order』を使います。『駅時刻』 ( CentDedEkiJikoku ) を保持するコンテナ
  CentDedEkiJikokuCont のインデクスも、『駅Order』 となります。
  どちらのクラスにおいても、『駅Index』と『駅Order』の相互変換を行う
メソッド EkiIndexOfEkiOrder() , EkiOrderOfEkiIndex() を提供しています。

  『時刻Order』は、『列車』オブジェクト内で、特定の時刻
  （ある駅の着・発のいずれか）を指定する順序数です。
『時刻Order』は、以下の法則を持ちます。
値の範囲は、0 以上 駅の数*2 未満です。

- 『駅Order』*2 + 0 ・・・『駅Order』の駅の着時刻(とそれ以降)
を変更します。
- 『駅Order』*2 + 1 ・・・『駅Order』の駅の発時刻(とそれ以降)
を変更します。


制約
 -------------------------------- 
△列車が路線の一部である場合、列車種別Indexは、CentDedRessyasyubetsuCont(列車種別コンテナ)に対応していなくてはならない



操作のエラー検査・修正
 -------------------------------- 
△列車種別の追加(OnInsertRessyasyubetsu):　列車の列車種別インデクスは、コンテナへの追加に合わせてシフトさせる。

△列車種別の削除(OnEraseRessyasyubetsu):　列車の列車種別インデクスは、コンテナへの追加に合わせてシフトさせる。
　列車の列車種別インデクスが削除対象の場合、インデクスは0にする

△setRessyasyubetsuIndex: 列車が路線(CentDedRosen)の一部である場合で、列車種別Indexが列車種別コンテナ CentDedRessyasyubetsuCont に対応していない場合はエラー。

△setParent:adjustを実行する

△operator= : this が列車コンテナの一部である場合、『列車方向』 ( m_eRessyahoukou )は変更しません。

 制約に合うように属性を修正(adjust)
 -------------------------------- 
△列車が親オブジェクト CentDedRessyaCont の一部である場合、列車方向は、親オブジェクトである列車コンテナの列車方向と同一とします。

△列車種別IndexがCentDedRessyasyubetsuCont(列車種別コンテナ)の範囲外である場合は、列車種別Indexは0とします。

○CentDedEkiJikokuCont(駅時刻コンテナ)に、adjust()を委譲します。

	
*/
class CentDedRessya : public CChildBase
{
	typedef CChildBase	super ;
public:
	// ****************************************************************
	//	インナータイプ
	// ****************************************************************
	/**
	  このクラスに包含される『駅時刻』(CentDedEkiJikokuTrack) オブジェクト
	のコンテナです。
	*/
	class CXEkiJikokuCont : public CentDedEkiJikokuCont
	{
	public:
		// ********************************
		///@name CentDedEkiJikokuCont-関連
		// ********************************
		///@{
		/**
		@return
			このコンテナが CentDedEkiJikoku に包含されている場合は、
			CentDedEkiJikoku のアドレス。
			そうでないならNULL。
		*/
		 virtual CentDedRessya* getRessya() ;
		/**
		@return
			このコンテナが CentDedEkiJikoku に包含されている場合は、
			CentDedEkiJikoku のアドレス。
			そうでないならNULL。
		*/
		virtual const CentDedRessya* getRessya()const ;
		///@}
	};
	/**
		setRessyasyubetsuIndex でスローされる例外。
	*/
	class LException 
	{
	};
	// ****************************************************************
	

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		この列車が『Null状態』なら真、
		有効な列車属性を保持しているのなら偽です。
		
		この属性が真の場合、属性 
		-	m_iRessyasyubetsuIndex,
		-	m_strRessyabangou ;
		-	m_strRessyamei ;
		-	m_strGousuu ;
		-	m_strBikou ;
	
		および、
			m_CentDedEkiJikokuCont に格納されている 
		CentDedEkiJikoku は、意味を持ちません。
		
		規定値は true です。
		set...() メソッドで、m_eRessyahoukou 以外の
		いずれかの属性を設定したときには、
		自動的に偽に変わります。
		clear() で、真となります。
	 */
	bool m_bIsNull ;

	/**
		この列車の列車方向を示します。
		
		規定値は Ressyahoukou_Kudari です。
	
		コンストラクタで決まります。
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
	 */
	std::string m_strRessyabangou ;
	
	/**
		この列車の『列車名』。
		
		規定値は空文字列です。
	 */
	std::string m_strRessyamei ;
	
	/**
		この列車の『号数』。
		
		規定値は空文字列です。
	 */
	std::string m_strGousuu ;
	
	/**
		この列車の『備考』。
		
		規定値は空文字列です。
	 */
	std::string m_strBikou ;
	
	///@}
 private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
		この列車の各駅の時刻。
		要素数は、『駅』( CentDedEki ) の数に等しくなります。
		添え字は『駅Order』です。
	
		初期状態では、要素数は 0 となります。
	
		すべての『駅時刻』が
		『運行なし』(Ekiatsukai_None ),
		の場合、この列車は『Null状態』となります。
	 */
	CXEkiJikokuCont	m_CentDedEkiJikokuCont ;

	///@}

	

 public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
		この列車をNULL状態に初期化します。
	 @param iEkiCount [in]
		この列車が走行する路線の『駅』の数を指定してください。
		このコンストラクタでは、 m_CentDedEkiJikokuCont の要素数を、
		この引数で初期化します。
		格納される CentDedEkiJikoku は、 
		CentDedEkiJikoku::m_eEkiatsukai	が Ekiatsukai_None となります。
	 @param eRessyahoukou [in]
		この列車の列車方向を示します。
	 */
	CentDedRessya( 
		int iEkiCount , 
		ERessyahoukou	eRessyahoukou ) ;

public:
	/**
		このクラスへの代入を行いますが、
		this の『列車方向』 ( m_eRessyahoukou ) ・
		『駅時刻』 (CentDedEkiJikoku ) の数は変更しません。
	
		this の m_CentDedEkiJikokuCont の数が value の m_CentDedEkiJikokuCount
		より少ない場合は、不足分の this の m_CentDedEkiJikokuCount 要素は
		『運行なし』となります。
	
		this の m_CentDedEkiJikokuCont の数が value の m_CentDedEkiJikokuCount
		より多い場合は、過剰分の value の m_CentDedEkiJikokuCount 要素は
		捨てます。
	 */
	CentDedRessya& operator=( const CentDedRessya& value );
public:
	// ********************************
	///@name CParentBase-操作
	// ********************************
	///@{
	/**
	△setParent:adjustを実行する
	*/
	virtual void setParent( CParentBase* pParent );
	///@}

 public:
	// ********************************
	///@name CentDedRessya-属性
	// ********************************
	///@{
	/** 
	@see m_bIsNull
	 @return
		この列車が『Null状態』なら真です。
	 */
	bool isNull()const ;

	/** @see m_bIsNull */
	CentDedRessya& setIsNull( bool value );

	///@see m_eRessyahoukou
	ERessyahoukou	getRessyahoukou()const ;
	///@see m_iRessyasyubetsuIndex
	int	getRessyasyubetsuIndex()const ;

	/**
	@see m_iRessyasyubetsuIndex


	　△setRessyasyubetsuIndex: 列車が路線(CentDedRosen)の一部である場合で、
	列車種別Indexが列車種別コンテナ CentDedRessyasyubetsuCont に対
	応していない場合はエラー。

	@exception LException 
		列車が路線(CentDedRosen)の一部である場合で、
	列車種別Indexが列車種別コンテナ CentDedRessyasyubetsuCont に対
	応していない
	*/
	CentDedRessya& setRessyasyubetsuIndex( int value ) ;

	///@see m_strRessyabangou
	std::string getRessyabangou()const{
		return m_strRessyabangou ;};
	///@see m_strRessyabangou
	CentDedRessya& setRessyabangou( const std::string& value ){
		m_bIsNull = false ;
		m_strRessyabangou = value ; return *this ; } ;
	///@see m_strRessyamei
	std::string getRessyamei()const{
		return m_strRessyamei ;};
	///@see m_strRessyamei
	CentDedRessya& setRessyamei( const std::string& value ){
		m_bIsNull = false ;
		 m_strRessyamei = value ; return *this ; } ;
	///@see m_strGousuu
	std::string getGousuu()const{
		return m_strGousuu ;};
	///@see m_strGousuu
	CentDedRessya& setGousuu( const std::string& value ){
		m_bIsNull = false ;
		 m_strGousuu = value ; return *this ; } ;
	///@see m_strBikou
	std::string getBikou()const{
		return m_strBikou ;};
	///@see m_strBikou
	CentDedRessya& setBikou( const std::string& value ){
		m_bIsNull = false ;
		 m_strBikou = value ; return *this ; } ;
	///@}
	
	// ********************************
	///@name 包含-CentDedEkiJikoku
	// ********************************
	///@{


	/** @see m_CentDedEkiJikokuCont */
	CentDedEkiJikokuCont* getCentDedEkiJikokuCont() 
	{	return &m_CentDedEkiJikokuCont ;}
	/** @see m_CentDedEkiJikokuCont */
	const CentDedEkiJikokuCont*	getCentDedEkiJikokuCont()const 
	{	return &m_CentDedEkiJikokuCont ;}

	
	/**
	 @return
		『駅時刻』 の数を返します。
	 */
	int getCentDedEkiJikokuCount()const ;
	
	/**
		『駅Order』に対応する、『駅時刻』オブジェクトを取得する
		ことができます。
	 @param iEkiOrder [in]
		『駅Order』を指定してください。
		範囲は 0 以上 getCentEkiJikokuCount() 未満です。
		INT_MAX を指定すると、末尾を指定したものとみなします。
	 @return 
		対応する『駅時刻』オブジェクト
	 */
	CentDedEkiJikoku getCentDedEkiJikoku( int iEkiOrder )const ;

	/**
		『駅Order』に対応する、『駅時刻』オブジェクトを設定する
		ことができます。
		  this がNULL列車の場合、このメソッドを呼び出すと
		NULL列車属性は解除されます。
	 @param iEkiOrder [in]
		『駅Order』を指定してください。
		範囲は 0 以上 getCentEkiJikokuCount() 未満です。
		INT_MAX を指定すると、末尾を指定したものとみなします。
	 @param value [in]
		『駅時刻』を指定してください。
	 @return 
		対応する『駅時刻』オブジェクト
	 */
	CentDedRessya& setCentDedEkiJikoku( 
		int iEkiOrder , 
		const CentDedEkiJikoku& value ) ;
	///@}
	// ********************************
	///@name 『駅Order』単位の操作
	// ********************************
	///@{
	/**
		『駅Order(駅方向別Index)』を、『駅Index』に変換します。
	 @param iEkiOrder [in]
		『駅Order』を指定してください。
	 @return 
		0以上の『駅Index』を返します。
		引数が不正な場合は、 -1 を返します。
	 */
	int EkiIndexOfEkiOrder( int iEkiOrder )const  ;
	
	/**
		『駅Index』を『駅Order(駅方向別Index)』に変換します。
	 @param iEkiIndex [in]
		『駅Index』を指定してください。
	 @return 
		0以上の『駅Order』を返します。
		引数が不正な場合は、 -1 を返します。
	 */
	int EkiOrderOfEkiIndex( int iEkiIndex )const  ;
	
	/**
		『駅Order』に対応する、『駅時刻』オブジェクトを、変更する
		ことができます。
	
		このとき、『着時刻』・『発時刻』が変更されたら、
		以後の駅時刻をすべて繰り下げます。
	
		  this がNULL列車の場合、このメソッドを呼び出すと
		NULL列車属性は解除されます。

		（例）
	
		  それまでの(thisの)『着時刻』が 10:00 で、
		新しい(value の)『着時刻』が 10:03 の場合は、
		その『駅Order』の『発時刻』と、
		それよりあとの『駅Order』の『着時刻』『発時刻』をすべて、
		３分繰り下げます。
		
		  それまでの(thisの)『着時刻』が IsNull で、
		新しい(value の)『着時刻』が 10:03 の場合は、
		その『駅Order』の『着時刻』だけを 10:03 に更新します。
		その『駅Order』の『発時刻』と、
		それよりあとの『駅Order』の『着時刻』・『発時刻』には影響を
		与えません。
	
		  それまでの(thisの)『着時刻』が 10:00 で、
		新しい(value の)『着時刻』が IsNull の場合は、
		その『駅Order』の『着時刻』だけを IsNull に更新します。
		その『駅Order』の『発時刻』と、
		それよりあとの『駅Order』の『着時刻』・『発時刻』には影響を
		与えません。
	
		  『発時刻』に関しても、変更された場合は、その差に従って
		それよりあとの『駅Order』の『着時刻』・『発時刻』の繰り上げ/繰り下げを
		行います。
	
	@param pCentDedEkiCont [in]
		駅コンテナを指定してください。
	 @param iEkiOrder [in]
		『駅Order』を指定してください。
		範囲は 0 以上 getCentEkiJikokuCount() 未満です。
		INT_MAX を指定すると、末尾を指定したものとみなします。
	 @param value [in]
		『駅時刻』を指定してください。
	 @return 
		対応する『駅時刻』オブジェクト
	 */
	CentDedRessya& modifyCentDedEkiJikoku( 
		int iEkiOrder , 
		const CentDedEkiJikoku& value ) ;
	
	/**
	 @return
		この列車の始発駅の『駅Order』を返します。
		すべての『駅時刻』が『運行なし』の場合は、-1 を返します。
		この場合、この列車自体が『運行なし』となります。
	 */
	int getSihatsuEki()const ;

	/**
		この列車の始発駅を設定します。
		『駅Order』が始発駅よりも小さい駅のすべての『駅時刻』は
		属性が Ekiatsukai_None に変わります。
	 @param iEkiOrder [in]
		始発駅を『駅Order』で指定してください。
		範囲は 0 以上 getCentEkiJikokuCount() 未満です。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	『駅Order』が不正です。
	 */
	int setSihatsuEki( int iEkiOrder ) ;
	
	/**
	 @return
		この列車の終着駅の『駅Order』を返します。
		すべての『駅時刻』が『運行なし』の場合は、-1 を返します。
		この場合、この列車自体が『運行なし』となります。
	 */
	int getSyuuchakuEki()const ;

	/**
		この列車の終着駅を設定します。
		『駅Order』が終着駅よりも大きい駅のすべての『駅時刻』は
		属性が Ekiatsukai_None に変わります。
	 @param iEkiOrder [in]
		終着駅を『駅Order』で指定してください。
		範囲は 0 以上 getCentEkiJikokuCount() 未満です。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	『駅Order』が不正です。
	 */
	int setSyuuchakuEki( int iEkiOrder ) ;

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
	@return
		この列車が路線上で運行されている区間の、最初の『駅Order』を返します。
		すべての区間を運行していない場合は、-1 を返します。
		「運行されている区間」については、isRunBetweenNextEki() を
		参照してください。

		getSihatsuEki() と似た目的の関数です。
		しかし、始発駅が『経由なし』の場合は、この関数はその駅を
		『運行されている』とはみなしません。
	 */
	int getRunFirstEkiOrder()const ;
	
	/**
	@return
		この列車が路線上で運行されている、最後の『駅Order』を返します。
		すべての区間を運行していない場合は、-1 を返します。
		「運行されている区間」については、isRunBetweenNextEki() を
		参照してください。

		getSyuuchakuEki() と似た目的の関数です。
		しかし、終着駅が『経由なし』の場合は、この関数はその駅を
		『運行されている』とはみなしません。
	 */
	int getRunLastEkiOrder()const ;
	
	/**
		指定の駅 Order の駅時刻を、
		駅時刻形式・始発・終着に合わせて変更します。

		変更内容は、 CentDedEkiJikoku::adjustByEkijikokukeisiki 
		の説明を参照してください。

		this がNULL列車の場合、このメソッドは何もしません。

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
	///@name 『時刻Order』単位の操作
	//*******************************
	///@{
	/**
	    CdDedJikokuOrder を、次の駅時刻に進めます。
	@param aJikokuOrder [in]
		進める対象の、	CdDedJikokuOrder を指定してください。
	@return 
		- aJikokuOrder が着時刻の場合は、同じ駅Orderの発時刻
		- aJikokuOrder が発時刻の場合は、次の駅Orderの着時刻
		- aJikokuOrder の EkiOrder>=this.size() (最後の駅Orderの次) なら、@n
			aJikokuOrder をそのまま返します。
		- aJikokuOrder がNULL状態 なら、aJikokuOrder をそのまま返します。
	@attention
		この関数は、駅時刻形式(着時刻・発時刻を表示するか否か)の属性を受けません
	*/
	CdDedJikokuOrder incJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder )const ;

	/**
	    CdDedJikokuOrder を、前の駅時刻に移動します。
	@param aJikokuOrder [in]
		移動対象の、	CdDedJikokuOrder を指定してください。
	@return 
		- aJikokuOrder が発時刻の場合は、同じ駅Orderの着時刻
		- aJikokuOrder が着時刻の場合は、次の駅Orderの発時刻
		- aJikokuOrder の EkiOrder>=this.size() (最後の駅Orderの次) なら、@n
			最後の駅Orderの発時刻
		- aJikokuOrder の EkiOrder=0 なら、NULL状態
		- aJikokuOrder がNULL状態 なら、aJikokuOrder をそのまま返します。
	@attention
		この関数は、駅時刻形式(着時刻・発時刻を表示するか否か)の属性を受けません
	*/
	CdDedJikokuOrder decJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder )const ;

	
	/**
		この列車の、『時刻Order』に対応する時刻を取得します。
		
	 @param aJikokuOrder [in]
		取得する時刻の『時刻Order』を指定してください。
	 @return
		対応する時刻を返します。
		パラメータが不正な場合は、 Null状態の時刻を返します。

	*/
	CdDedJikoku getEkiJikoku( CdDedJikokuOrder aJikokuOrder )const  ;
	
	/**
		この列車の、『時刻Order』に対応する時刻を変更します。
	 @attention
		この関数は、指定の駅時刻以降の駅時刻の
		繰り上げ／繰り下げは行いません。
	 @param aCdDedJikoku [in]
		時刻を指定してください。
	 @param aJikokuOrder [in]
		変更する時刻の『時刻Order』を指定してください。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		- 	-1 ;	//	パラメータが不正
	 */
	int setEkiJikoku( const CdDedJikoku& aCdDcdJikoku , CdDedJikokuOrder aJikokuOrder ) ;
	
	/**
		この列車の、指定の時刻以降の時刻を変更します。
		指定した駅時刻以降の、非『Null』状態のすべての駅の時刻を、
		繰り上げ／繰り下げます。
		
	@param pCentDedEkiCont [in]
		駅コンテナを指定してください。
	@param aCdDedJikan [in]
		繰り上げ・繰り下げを行う時間を指定してください。
	@param iJikokuOrder [in]
		変更する時刻の『時刻Order』を指定してください。
	@return
		成功したら 0 以上、エラーなら負の数です。
		- 	-1 ;	//	パラメータが不正
	*/
	int modifyRessyaJikoku(  
		const CdDedJikan& aCdDedJikan , 
		const CdDedJikokuOrder& aJikokuOrder) ;
	
	/**
		この列車の、指定の『時刻Order』以前で、
		非『Null』状態の時刻を、
		上に向かって（『時刻Order』0の方に向かって）検索します。
		
	@param pCentDedEkiCont [in]
		駅コンテナを指定してください。
	 @param aJikokuOrder [in]
		検索の起点となる変更する時刻を『時刻Order』で指定してください。
	 @return
		非Null状態の時刻が見つかった場合は、0 以上の『時刻Order』を取得します。
		見つからなかった場合や、パラメータが不正な場合は、
		NULL状態のオブジェクトを返します。
	 */
	CdDedJikokuOrder findrevJikoku( 
		const CdDedJikokuOrder& aJikokuOrder )const ;

	///@}
	
	// ********************************
	///@name CentDedRessya-操作
	// ********************************
	///@{
	/**
		この列車を『Null状態』とします。
	 */
	void clear() ;

	/**
		他の列車の駅時刻を、この列車の駅時刻に上書きします。
	@param aCentDedRessyaSrc [in]
		この関数は、この列車の駅時刻を、thisの駅時刻に上書きします。
		aCentDedRessyaSrc の駅扱が『運行なし』の駅の時刻は、
		this の駅時刻には上書きしません。
		また、着時刻・発時刻がNULLの場合は、
		その駅時刻を this に上書きしません。
	*/
	void pasteEkiJikoku( const CentDedRessya& aCentDedRessyaSrc ) ;

	/**
		この列車と他の列車を直通化します。
	@param aRessyaSihatsu [in]
		始発列車のインデクスを指定してください。
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 ;	//	この列車には駅時刻が指定されていません。
		-	-2 ;	//	始発列車には駅時刻が指定されていません。
		-	-3 ;	//	aRessyaSihatsu との直通化はできません。
			//aRessyaSihatsu の始発駅は、	this の終着駅と同じか、それ以降でなくてはなりません。
	@attention
		aRessyaSihatsu の始発駅は、
		this の終着駅と同じか、それ以降でなくては
		なりません。
		thisの終着駅<aRessyaSihatsu の始発駅なら、
		その間の駅の駅扱は[経由なし]とします。

		始発駅の時刻(直通化した時刻)は、以下のようになります。

		- 駅扱：変わりません。
		- 着時刻：
		  - this列車に着時刻が指定されていた場合：その着時刻
		  - this列車に着時刻がなく、発時刻が指定されていた場合：途中駅止まり列車の発時刻
		  - this列車に着時刻も発時刻も指定されていない場合：着時刻はなし
		- 発時刻
		  - 始発列車に発時刻が指定されていた場合：その発時刻を直通化した列車の発時刻とします。
		  - 始発列車に発時刻がなく、着時刻が指定されていた場合：途中駅始発列車の着時刻を、新しい列車の発時刻とします。
		  - 始発列車に着時刻も発時刻も指定されていない場合：発時刻はなし

		始発駅の列車情報(列車番号・列車名・号数・備考)は以下のようになります。
		
		- this列車が空文字列、始発列車が情報ありの場合、始発列車の情報を受け継ぎます。
		- this列車が情報あり、始発列車が空文字列の場合、this列車の情報を受け継ぎます。
		- this列車も始発列車も情報ありの場合、this列車の情報を受け継ぎます。

	*/
	virtual int direct( 
		const CentDedRessya& aRessyaSihatsu ) ;

	/**
		この列車を指定の駅で分断した、２つの列車を作成します。

	@param iEkiOrder[in]
		分離する駅の駅Orderを指定してください。
	@param pCentDedRessyaSyuuchaku [out]
		この関数はこの列車オブジェクトに、分離した当駅止まり列車の列車の情報を
		上書きします。
		このオブジェクトの 列車方向・駅数は、あらかじめ
		this と同じにする必要があります。
	@param 	pCentDedRessyaSihatsu [out]
		この関数はこの列車オブジェクトに、分離した当駅始発の列車の情報を
		上書きします。
		このオブジェクトの 列車方向・駅数は、あらかじめ
		this と同じにする必要があります。
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 ;	//	指定の駅Orderでは、分断はできません

	*/
	virtual int undirect(
		int iEkiOrder , 
		CentDedRessya* pCentDedRessyaSyuuchaku ,
		CentDedRessya* pCentDedRessyaSihatsu )const ;

	/**
		this の属性が制約に反している場合、制約に合うように、属性を
		修正します。

		△列車が親オブジェクト CentDedRessyaCont の一部である場合、
		列車方向は、親オブジェクトである列車コンテナの列車方向と同一とします。

		△列車種別IndexがCentDedRessyasyubetsuCont(列車種別コンテナ)の
		範囲外である場合は、列車種別Indexは0とします。

		○CentDedEkiJikokuCont(駅時刻コンテナ)に、adjust()を委譲します。


	*/
	void adjust() ;
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
	virtual void onEkiInsert( int iEkiOrder )
	{	m_CentDedEkiJikokuCont.onEkiInsert( iEkiOrder ) ;}

	/**
		m_CentDedEkiCont から CentDedEki が削除された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiOrder
		削除された CentDedEki の駅Order(駅インデクスではありません)。
	*/
	virtual void onEkiErase( int iEkiOrder  )
	{	m_CentDedEkiJikokuCont.onEkiErase( iEkiOrder ) ;}

	/**
		CentDedEkiTrackCont に CentDedEkiTrack が追加された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiOrder
		CentDedEkiTrackCont が追加された CentDedEki の駅Order(駅インデクスではありません)。
	@param iEkiTrackIndex
		追加された CentDedEkiTrack のインデクス。
	*/
	virtual void onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex ) 
	{	m_CentDedEkiJikokuCont.onEkiTrackInsert( iEkiOrder , iEkiTrackIndex ) ;}

	/**
		CentDedEkiTrackCont から CentDedEkiTrack が削除された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiOrder
		CentDedEkiTrackCont が削除された CentDedEki の駅Order(駅インデクスではありません)。
	@param iEkiTrackIndex
		削除された CentDedEkiTrack の先頭のインデクス。
	*/
	virtual void onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex )
	{	m_CentDedEkiJikokuCont.onEkiTrackErase( iEkiOrder , iEkiTrackIndex ) ;}

	/**
		CentDedRessyasyubetsuCont に CentDedRessyasyubetsu が追加された直後、
		CentDedRessyasyubetsuCont から呼び出されます。

	△列車種別の追加(OnInsertRessyasyubetsu):　列車の列車種別インデクスは、コンテナへの追加に合わせてシフトさせる。

	@param iRessyasyubetsuIndex
		追加された CentDedRessyasyubetsu  のインデクス。
	*/
	virtual void onRessyasyubetsuInsert( int iRessyasyubetsuIndex ); 

	/**
		CentDedRessyasyubetsuCont から CentDedRessyasyubetsu が削除された直後、
		CentDedRessyasyubetsuCont から呼び出されます。

		△列車種別の削除(OnEraseRessyasyubetsu):　列車の列車種別インデクスは、コンテナへの追加に合わせてシフトさせる。
　		  列車の列車種別インデクスが削除対象の場合、インデクスは0にする
		
	@param iRessyasyubetsuIndex
		削除された CentDedRessyasyubetsu  のインデクス。
	*/
	virtual void onRessyasyubetsuErase( int iRessyasyubetsuIndex ); 


	///@}
};

} //namespace entDed

#endif /*CentDedRessya_h*/
