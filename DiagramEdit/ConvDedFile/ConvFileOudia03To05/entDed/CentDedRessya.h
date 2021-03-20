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


#include <deque>
using namespace std ;


#include "Cont/Ccont_deque.h"
#include "cont/CaContGet_ptref.h"

#include "CentDed.h"
#include "CentDedEkiJikoku.h"
#include "CdDedJikan.h"
#include "CentDedEkiCont.h"


// ****************************************************************
//	CentDedRessya
// ****************************************************************
/**
 * @brief
 *	【概要】  DiagramEdit の、路線上で運行される『列車』１本を表します。
 *	
 *	このクラスのインスタンスは、通常は『路線』（ CentDedRosen ）に
 *	包含されます。
 *	
 *	実際には、
 *	
 *	- 『路線』 (CentDedRosen) が『ダイヤ』 ( CentDedDia ) を
 *	０以上複数包含
 *	- 各『ダイヤ』 ( CentDedDia ) が『列車』 (CentDedRessya ) を
 *	０以上複数包含
 *	
 *	という関係になっています。
 *	
 *	このクラスは、『路線』（ CentDedRosen ）に存在する
 *	『駅』 ( CentDedEki )の数だけ、『駅時刻』(CentDedEkiJikoku）
 *	オブジェクトを保持します。『路線』 ( CentDedRosen )に包含される
 *	すべての『列車』( CentDedRessya )が包含する
 *	『駅時刻』 ( CentDedEkiJikoku ) オブジェクトの数は、
 *	『路線』 ( CentDedRosen )の『駅』 ( CentDedEki ) の数と同じでなくては
 *	なりません。
 *	  この同期をとるため、『列車』 ( CentDedRessya ) に対する
 *	『駅時刻』 ( CentDedEkiJikoku ) オブジェクトの追加・削除の操作は制限
 *	されています。
 *	『駅時刻』の追加・削除の操作は、『路線』オブジェクトに対してのみ
 *	許可するものとします。このクラスが 
 *	『路線』 ( CentDedRosen ) ・『ダイヤ』 ( CentDedDia ) 
 *	を friend クラスに指定しているのはこのためです。
 *	
 *	また、このクラスが保持する、『列車種別Index』属性は、
 *	『路線』( CentDedRosen )が保持する『列車種別』 ( CentDedRessyasyubetsu )
 *	オブジェクトに対応します。
 *	
 *	このオブジェクトは、有効な列車データをもたない『Null状態』を
 *	とることができます。
 *	『Null状態』の列車は、『時刻表ビュー』では空行として表示されます。
 *	
 *	<H4>
 *	【駅Index と 駅Order , 時刻Order】
 *	</H4>
 *	  『路線』 ( CentDedRosen ) オブジェクト内の特定の
 *	『駅』 ( CentDedEki )オブジェクトを指定する方法、及び
 *	『列車』 ( CentDedRessya )オブジェクト内の特定の
 *	『駅時刻』 ( CentDedEkiJikoku ) オブジェクトを指定する方法には、
 *	『駅Index』・『駅Order』の２つがあります。どちらも、
 *	0 以上 ( 駅の数) 未満 の整数で、『駅』を指定します。
 *	
 *	  『駅Index』は、路線の下り列車の始発駅（上り列車の終着駅）が 0 ・ 
 *	下り列車の終着駅（上り列車の始発駅） が ( 駅の数 - 1 ) となります。
 *	
 *	  『駅Oeder』は、列車の方向別のインデクスです。下り列車・上り列車
 *	ともに始発駅が 0 ・ 終着駅が ( 駅の数 - 1 ) と
 *	なります。
 *
 *	  従って、『駅Index』が 0 の駅は、下り列車にとっては『駅Oeder』 も
 *	 0 ですが、上り列車にとっては『駅Order』 は （駅の数 - 1 ）となります。 
 *	
 *	  『路線』 ( CentDedRosen ) クラスでは、原則として
 *	『駅』( CentDedEki ) オブジェクトを指定するのに『駅Index』を使います。
 *	『駅』を保持するコンテナ CentDedRosen::m_CentDedEkiCont の添え字も
 *	『駅Index』になっています。
 *	\n  これとは対照的に、『列車』(クラスでは、原則として
 *	『駅時刻』 ( CentDedEkiJikoku ) オブジェクトを指定するのには
 *	『駅Order』を使います。『駅時刻』 ( CentDedEkiJikoku ) を保持するコンテナ
 *	  CentDedRessya::m_CentDedEkiJikokuCont の添え字も、『駅Order』 
 *	となります。
 *	  どちらのクラスにおいても、『駅Index』と『駅Order』の相互変換を行う
 *	メソッド EkiIndexOfEkiOrder() , EkiOrderOfEkiIndex() を提供しています。
 *	
 *	『時刻Order』は、『列車』オブジェクト内で、特定の時刻
 *	（ある駅の着・発のいずれか）を指定する順序数です。
 *	『時刻Order』は、以下の法則を持ちます。
 *	値の範囲は、0 以上 駅の数*2 未満です。
 *	
 *	- 『駅Order』*2 + 0 ・・・『駅Order』の駅の着時刻(とそれ以降)
 *	を変更します。
 *	- 『駅Order』*2 + 1 ・・・『駅Order』の駅の発時刻(とそれ以降)
 *	を変更します。
 *	
 */
class CentDedRessya
{
// ********************************
//	インナータイプ
// ********************************
 public:
	typedef deque< CentDedEkiJikoku* > CentDedEkiJikokuCont ;
	
// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 *	この列車が『Null状態』なら真、
	 *	有効な列車属性を保持しているのなら偽です。
	 *	
	 *	この属性が真の場合、属性 
	 *	-	m_iRessyasyubetsuIndex,
	 *	-	m_strRessyabangou ;
	 *	-	m_strRessyamei ;
	 *	-	m_strGousuu ;
	 *	-	m_strBikou ;
	 *
	 *	および、
	 *		m_CentDedEkiJikokuCont に格納されている 
	 *	CentDedEkiJikoku は、意味を持ちません。
	 *	
	 *	規定値は true です。
	 *	set...() メソッドで、m_eRessyahoukou 以外の
	 *	いずれかの属性を設定したときには、
	 *	自動的に偽に変わります。
	 *	clear() で、真となります。
	 */
	bool m_bIsNull ;

	/**
	 *	この列車の列車方向を示します。
	 *	
	 *	規定値は Ressyahoukou_Kudari です。
	 *
	 *	コンストラクタで決まります。
	 */
	ERessyahoukou	m_eRessyahoukou ;

	/**
	 *	この列車の『列車種別』を、
	 *	『列車種別Index』で保持します。
	 *	
	 *	規定値は 0 です。
	 */
	int	m_iRessyasyubetsuIndex ;
	
	/**
	 *	この列車の『列車番号』。
	 *	
	 *	規定値は空文字列です。
	 */
	string m_strRessyabangou ;
	
	/**
	 *	この列車の『列車名』。
	 *	
	 *	規定値は空文字列です。
	 */
	string m_strRessyamei ;
	
	/**
	 *	この列車の『号数』。
	 *	
	 *	規定値は空文字列です。
	 */
	string m_strGousuu ;
	
	/**
	 *	この列車の『備考』。
	 *	
	 *	規定値は空文字列です。
	 */
	string m_strBikou ;
	
///@}
// ********************************
///@name 包含
// ********************************
///@{
 private:
	/**
	 *	この列車の各駅の時刻。
	 *	要素数は、『駅』( CentDedEki ) の数に等しくなります。
	 *	添え字は『駅Order』です。
	 *
	 *	このコンテナ内のオブジェクトの生成・破棄の責務はthisにあります。
	 *
	 *	初期状態では、要素数は 0 となります。
	 *
	 *	すべての『駅時刻』が
	 *	『運行なし』(Ekiatsukai_None ),
	 *	の場合、この列車は『Null状態』となります。
	 */
	CentDedEkiJikokuCont	m_CentDedEkiJikokuCont ;

///@}

// --------------------------------
///@name CentDedRosen→CentDedRessyaCont 専用メンバ関数
// --------------------------------
///@{
 protected:
	/**
	 *	『駅』オブジェクトの属性の変更を通知します。
	 *	
	 *	この関数は、『始発駅・終着駅の駅時刻形式変更に伴う、着時刻・発時刻の修正』
	 *	を行わせます。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Order』で指定してください。
	 *	範囲は 0 以上 m_iEkiCount 以下です。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 */
	int onSetCentDedEki( const IfContGet<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder ) ;

	/**
	 *	『駅時刻』オブジェクトを、指定の位置に挿入します。
	 * @param aCentEkiJikoku [in]
	 *	挿入する『駅時刻』オブジェクトを指定してください。
	 *	このオブジェクトの破棄の責務は、クラスユーザーにあります。
	 *	このオブジェクトは、この関数終了後は破棄できます。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Order』で指定してください。
	 *	範囲は 0 以上 getCentEkiJikokuCount() 以下です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	インデクスが不正です。
	 */
	int insertCentDedEkiJikoku( const CentDedEkiJikoku& aCentEkiJikoku , 
		int iEkiOrder = INT_MAX ) ;
	
	/**
	 *	『駅時刻』オブジェクトを、指定の位置から削除します。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Order』で指定してください。
	 *	範囲は 0 以上 getCentEkiJikokuCount() 未満です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	インデクスが不正です。
	 */
	int eraseCentDedEkiJikoku( int iEkiOrder = INT_MAX ) ;

	//	駅時刻の追加・削除のため
	friend class CentDedRessyaCont ;
///@}
	

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	*	この列車をNULL状態に初期化します。
	 * @param iEkiJikokuCount [in]
	 *	この列車が走行する路線の『駅』の数を指定してください。
	 *	このコンストラクタでは、 m_CentDedEkiJikokuCont の要素数を、
	 *	この引数で初期化します。
	 *	格納される CentDedEkiJikoku は、 
	 *	CentDedEkiJikoku::m_eEkiatsukai	が Ekiatsukai_None となります。
	 * @param eRessyahoukou [in]
	 *	この列車の列車方向を示します。
	 */
	CentDedRessya( 
		int iEkiJikokuCount , 
		ERessyahoukou	eRessyahoukou ) ;
private:
	/**
	*	この列車を指定の列車種別で初期化します。
	 * @param iEkiJikokuCount [in]
	 *	この列車が走行する路線の『駅』の数を指定してください。
	 *	このコンストラクタでは、 m_CentDedEkiJikokuCont の要素数を、
	 *	この引数で初期化します。
	 *	格納される CentDedEkiJikoku は、 
	 *	CentDedEkiJikoku::m_eEkiatsukai	が Ekiatsukai_None となります。
	 * @param eRessyahoukou [in]
	 *	この列車の列車方向を示します。
	 * @param iRessyasyubetsuIndex [in]
	 *	この列車の『列車種別』を、
	 *	『列車種別Index』で保持します。
	 *	\n
	 *	規定値は 0 です。
	 */
	CentDedRessya( 
		int iEkiJikokuCount , 
		ERessyahoukou	eRessyahoukou ,
		int	iRessyasyubetsuIndex ) ;
	
public:
	/**
	 *	コピーコンストラクタ。
	 */
	CentDedRessya( const CentDedRessya& value );

	/**
	 *	このクラスへの代入を行いますが、
	 *	this の『列車方向』 ( m_eRessyahoukou ) ・
	 *	『駅時刻』 (CentDedEkiJikoku ) の数は変更しません。
	 *
	 *	this の m_CentDedEkiJikokuCont の数が value の m_CentDedEkiJikokuCount
	 *	より少ない場合は、不足分の this の m_CentDedEkiJikokuCount 要素は
	 *	『運行なし』となります。
	 *
	 *	this の m_CentDedEkiJikokuCont の数が value の m_CentDedEkiJikokuCount
	 *	より多い場合は、過剰分の value の m_CentDedEkiJikokuCount 要素は
	 *	捨てます。
	 */
	CentDedRessya& operator=( const CentDedRessya& value );
 public:
	virtual ~CentDedRessya() ;
		
// ********************************
//	CentDedRessya
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	ERessyahoukou	getRessyahoukou()const ;
	int	getRessyasyubetsuIndex()const ;
	CentDedRessya& setRessyasyubetsuIndex( int value ) ;
	string getRessyabangou()const{
		return m_strRessyabangou ;};
	CentDedRessya& setRessyabangou( const string& value ){
		m_bIsNull = false ;
		m_strRessyabangou = value ; return *this ; } ;
	string getRessyamei()const{
		return m_strRessyamei ;};
	CentDedRessya& setRessyamei( const string& value ){
		m_bIsNull = false ;
		 m_strRessyamei = value ; return *this ; } ;
	string getGousuu()const{
		return m_strGousuu ;};
	CentDedRessya& setGousuu( const string& value ){
		m_bIsNull = false ;
		 m_strGousuu = value ; return *this ; } ;
	string getBikou()const{
		return m_strBikou ;};
	CentDedRessya& setBikou( const string& value ){
		m_bIsNull = false ;
		 m_strBikou = value ; return *this ; } ;
	///@}
	
	// ********************************
	///@name 包含-CentDedEkiJikoku
	// ********************************
	///@{
	
	/**
	 * @return
	 *	『駅時刻』 の数を返します。
	 */
	int getCentDedEkiJikokuCount()const ;
	
	/**
	 *	『駅Order』に対応する、『駅時刻』オブジェクトを取得する
	 *	ことができます。
	 * @param iEkiOrder [in]
	 *	『駅Order』を指定してください。
	 *	範囲は 0 以上 getCentEkiJikokuCount() 未満です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return 
	 *	対応する『駅時刻』オブジェクト
	 */
	CentDedEkiJikoku getCentDedEkiJikoku( int iEkiOrder )const ;

	/**
	 *	『駅Order』に対応する、『駅時刻』オブジェクトを設定する
	 *	ことができます。
	 * @param iEkiOrder [in]
	 *	『駅Order』を指定してください。
	 *	範囲は 0 以上 getCentEkiJikokuCount() 未満です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @param value [in]
	 *	『駅時刻』を指定してください。
	 * @return 
	 *	対応する『駅時刻』オブジェクト
	 */
	CentDedRessya& setCentDedEkiJikoku( int iEkiOrder , 
		const CentDedEkiJikoku& value ) ;

	
	///@}
	// ********************************
	///@name 『駅Order』単位の操作
	// ********************************
	///@{
	/**
	 *	『駅Order(駅方向別Index)』を、『駅Index』に変換します。
	 * @param iEkiOrder [in]
	 *	『駅Order』を指定してください。
	 * @return 
	 *	0以上の『駅Index』を返します。
	 *	引数が不正な場合は、 -1 を返します。
	 */
	int EkiIndexOfEkiOrder( int iEkiOrder )const  ;
	
	/**
	 *	『駅Index』を『駅Order(駅方向別Index)』に変換します。
	 * @param iEkiIndex [in]
	 *	『駅Index』を指定してください。
	 * @return 
	 *	0以上の『駅Order』を返します。
	 *	引数が不正な場合は、 -1 を返します。
	 */
	int EkiOrderOfEkiIndex( int iEkiIndex )const  ;
	
	/**
	 *	『駅Order』に対応する、『駅時刻』オブジェクトを、変更する
	 *	ことができます。
	 *
	 *	このとき、『着時刻』・『発時刻』が変更されたら、
	 *	以後の駅時刻をすべて繰り下げます。
	 *
	 *	（例）
	 *
	 *	  それまでの(thisの)『着時刻』が 10:00 で、
	 *	新しい(value の)『着時刻』が 10:03 の場合は、
	 *	その『駅Order』の『発時刻』と、
	 *	それよりあとの『駅Order』の『着時刻』『発時刻』をすべて、
	 *	３分繰り下げます。
	 *	
	 *	  それまでの(thisの)『着時刻』が IsNull で、
	 *	新しい(value の)『着時刻』が 10:03 の場合は、
	 *	その『駅Order』の『着時刻』だけを 10:03 に更新します。
	 *	その『駅Order』の『発時刻』と、
	 *	それよりあとの『駅Order』の『着時刻』・『発時刻』には影響を
	 *	与えません。
	 *
	 *	  それまでの(thisの)『着時刻』が 10:00 で、
	 *	新しい(value の)『着時刻』が IsNull の場合は、
	 *	その『駅Order』の『着時刻』だけを IsNull に更新します。
	 *	その『駅Order』の『発時刻』と、
	 *	それよりあとの『駅Order』の『着時刻』・『発時刻』には影響を
	 *	与えません。
	 *
	 *	  『発時刻』に関しても、変更された場合は、その差に従って
	 *	それよりあとの『駅Order』の『着時刻』・『発時刻』の繰り上げ/繰り下げを
	 *	行います。
	 *
	 *	
	 *
	 * @param iEkiOrder [in]
	 *	『駅Order』を指定してください。
	 *	範囲は 0 以上 getCentEkiJikokuCount() 未満です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @param value [in]
	 *	『駅時刻』を指定してください。
	 * @return 
	 *	対応する『駅時刻』オブジェクト
	 */
	CentDedRessya& modifyCentDedEkiJikoku( int iEkiOrder , 
		const CentDedEkiJikoku& value ) ;
	
	/**
	 * @return
	 *	この列車の始発駅の『駅Order』を返します。
	 *	すべての『駅時刻』が『運行なし』の場合は、-1 を返します。
	 *	この場合、この列車自体が『運行なし』となります。
	 */
	int getSihatsuEki()const ;

	/**
	 *	この列車の始発駅を設定します。
	 *	『駅Order』が始発駅よりも小さい駅のすべての『駅時刻』は
	 *	属性が Ekiatsukai_None に変わります。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Order』で指定してください。
	 *	範囲は 0 以上 getCentEkiJikokuCount() 未満です。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	『駅Order』が不正です。
	 */
	int setSihatsuEki( int iEkiOrder ) ;
	
	/**
	 * @return
	 *	この列車の終着駅の『駅Order』を返します。
	 *	すべての『駅時刻』が『運行なし』の場合は、-1 を返します。
	 *	この場合、この列車自体が『運行なし』となります。
	 */
	int getSyuuchakuEki()const ;

	/**
	 *	この列車の終着駅を設定します。
	 *	『駅Order』が終着駅よりも大きい駅のすべての『駅時刻』は
	 *	属性が Ekiatsukai_None に変わります。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Order』で指定してください。
	 *	範囲は 0 以上 getCentEkiJikokuCount() 未満です。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	『駅Order』が不正です。
	 */
	int setSyuuchakuEki( int iEkiOrder ) ;
	///@}
	// ********************************
	///@name 『時刻Order』単位の操作
	// ********************************
	///@{
	
	/**
	 *	この列車の、『時刻Order』に対応する時刻を取得します。
	 *	
	 * @param iJikokuOrder [in]
	 *	取得する時刻の『時刻Order』を指定してください。
	 * @return
	 *	対応する時刻を返します。
	 *	パラメータが不正な場合は、 Null状態の時刻を返します。
	 */
	CdDedJikoku getEkiJikoku( int iJikokuOrder )const  ;
	
	/**
	 *	この列車の、『時刻Order』に対応する時刻を変更します。
	 * @attention
	 *	この関数は、指定の駅時刻以降の駅時刻の
	 *	繰り上げ／繰り下げは行いません。
	 * @param aCdDedJikoku [in]
	 *	時刻を指定してください。
	 * @param iJikokuOrder [in]
	 *	変更する時刻の『時刻Order』を指定してください。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	- 	-1 ;	//	パラメータが不正
	 *
	 */
	int setEkiJikoku( const CdDedJikoku& aCdDcdJikoku , int iJikokuOrder ) ;
	
	/**
	 *	この列車の、指定の時刻以降の時刻を変更します。
	 *	指定した駅時刻以降の、非『Null』状態のすべての駅の時刻を、
	 *	繰り上げ／繰り下げます。
	 *	
	 * @param iJikokuOrder [in]
	 *	変更する時刻の『時刻Order』を指定してください。
	 * @param aCdDedJikan [in]
	 *	繰り上げ・繰り下げを行う時間を指定してください。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	- 	-1 ;	//	パラメータが不正
	 *
	 */
	int modifyRessyaJikoku(  
		const CdDedJikan& aCdDedJikan , int iJikokuOrder ) ;
	
	/**
	 *	この列車の、指定の『時刻Order』以前で、
	 *	非『Null』状態の時刻を、
	 *	上に向かって（『時刻Order』0の方に向かって）検索します。
	 *	
	 * @param iJikokuOrder [in]
	 *	検索の起点となる変更する時刻を『時刻Order』で指定してください。
	 * @return
	 *	非Null状態の時刻が見つかった場合は、0 以上の『時刻Order』を取得します。
	 *	見つからなかった場合や、パラメータが不正な場合は、
	 *	-1 を返します。
	 */
	int findrevJikoku( int iJikokuOrder )const ;
	
	
	///@}
	
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
	 * @return
	 *	この列車が『Null状態』なら真です。
	 *
	 *	すべての『駅時刻』が
	 *	『運行なし』(Ekiatsukai_None ),
	 *	の場合、この列車は『Null状態』となります。
	 */
	bool isNull()const ;
	/**
	 *	この列車を『Null状態』とします。
	 */
	void clear() ;
	
	
	
	///@}
};
#endif /*CentDedRessya_h*/
