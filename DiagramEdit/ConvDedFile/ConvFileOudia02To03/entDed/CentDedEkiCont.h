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
//	CentDedEkiCont.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedEkiCont_h
#define  CentDedEkiCont_h

#include "Cont/CCont_deque.h"
#include "Cont/CaValueCont.h"
#include "CentDed.h"
#include "CentDedEki.h"

// ****************************************************************
//	CentDedEkiCont
// ****************************************************************
/**
 * @brief
 *  『駅』(CentDedEki) オブジェクトのコンテナです。
 *
 *	このクラス自体は、 IfCont< CentDedEki > インターフェースを
 *	サポートします。このインターフェースにより、 CentDedEki オブジェクトを
 *	追加・変更・削除することができます。
 *
 *	  引数なしの getIfContGet() メソッドにより、 IfContGet< const CentDedEki* >
 *	インターフェースを取得することができます。
 *	  このインターフェースを使うと、コンテナ内の CentDedEki 
 *	オブジェクトに直接アクセスすることができますが、
 *	CentDedEki オブジェクトの属性を変更することはできません。
 *	属性の変更は、 set() メソッドを使わなくてはなりません。
 *
 *	  また、列車方向( ERessyahoukou )の引数をとる getIfContGet() 
 *	メソッドにより、 列車方向別の
 *		IfContGet< CentDedEkiCont::CdDedEki >
 *	インターフェースを取得することができます。
 *	この方法で、『駅Order』に対応する駅の情報を取得することもできます。
 *	
 * @attention
 *	this の get() メソッドは、 CentDedEki オブジェクトのコピーを返します。
 *	get() メソッドで返されたオブジェクトに対して、
 *	CentDedEki オブジェクトを更新するメソッドを呼び出しても、
 *	コンテナ内の駅オブジェクトを更新することはできません。\n
 *	コンテナ内の駅オブジェクトのメソッドを呼び出す場合は、
 *	getIfContGet() で IfContGet<const CentDedEki*>* を取得してから、
 *	そのインターフェース経由で CentDedEki* を取得し、そのポインタに
 *	メソッドを呼び出してください。
 *
 *	<H4>
 *	【駅Index と 駅Order 】
 *	</H4>
 *	  コンテナ内の特定の『駅』 ( CentDedEki )オブジェクト
 *	を指定する方法には、
 *	『駅Index』・『駅Order』の２つがあります。どちらも、
 *	0 以上 ( 駅の数) 未満 の整数で、『駅』を指定します。
 *	
 *	  『駅Index』は、路線の下り列車の始発駅（上り列車の終着駅）が 0 ・ 
 *	下り列車の終着駅（上り列車の始発駅） が ( 駅の数 - 1 ) となります。
 *	
 *	  『駅Order』は、列車の方向別のインデクスです。下り列車・上り列車
 *	ともに始発駅が 0 ・ 終着駅が ( 駅の数 - 1 ) と
 *	なります。
 *
 *	  従って、『駅Index』が 0 の駅は、下り列車にとっては『駅Order』 も
 *	 0 ですが、上り列車にとっては『駅Order』 は （駅の数 - 1 ）となります。 
 *	
 *	  このクラスでは、『駅Index』をコンテナ内の要素の Index 
 *	とします。このコンテナの CentDedEki オブジェクトの順番は、
 *	  下り列車の始発駅から順番になっていなくてはなりません。
 *	\n  ただし、 getIfContGet( ERessyahoukou eRessyahoukou ) メソッドは、
 *	『駅Order』をインデクスとしたインターフェースを返します。
 */
class CentDedEkiCont : public IfCont< CentDedEki >
{
// ********************************
//	インナータイプ
// ********************************
public:
	// ****************************************************************
	//	CentDedEkiCont::CdDedEki
	// ****************************************************************
	/**
	 * @brief
	 *	駅の情報を保持する、単純データクラスです。
	 *	CentDedEkiCont::getIfContGet() メソッドにより、 
	 *	IfContGet< CentDedEkiCont::CdDedEki > インターフェースを取得すると、
	 *	コンテナ内の駅の属性を、この形式で取得することができます。
	 *
	 *	この単純データクラスで取得する情報は、列車方向{下り,上り}に合わせた
	 *	形式になっています。
	 *	例えば、駅時刻形式が[下り着時刻]となっている駅があった場合、
	 *
	 *	その駅の CentDedEkiCont::CdDedEki オブジェクトを下り方向で取得すると
	 *		- m_bChakujikokuHyouji = true ;
	 *		- m_bHatsujikokuHyouji = false ;
	 *
	 *	同じ駅の CentDedEkiCont::CdDedEki オブジェクトを上り方向で取得すると
	 *		- m_bChakujikokuHyouji = false ;
	 *		- m_bHatsujikokuHyouji = true ;
	 *
	 *	となります。
	 */
	class CdDedEki
	{
	// ********************************
	///@name 属性
	// ********************************
	///@{
	 private:
		/**
		 *	駅名
		 *
		 *	規定値は、空文字列。
		 */
		string	m_strEkimei ;
		
		/**
		 *	駅時刻形式。
		 *	着時刻表示あり。
		 */
		bool m_bChakujikokuHyouji ;
	
		/**
		 *	駅時刻形式。
		 *	発時刻表示あり。
		 */
		bool m_bHatsujikokuHyouji ;
		
		/**
		 *	『駅規模』を表す列挙です。
		 *
		 *	規定値は、 Ekikibo_Ippan 
		 */
		CentDedEki::EEkikibo	m_eEkikibo ;
	
		/**
		 *	この駅の下（終着駅より）に、境界線あり。
		 *
		 * 	この属性が true の駅では、時刻表画面の駅欄の下側に
		 *	太い境界線を描画します。
		 * 	この属性は、駅ビューと時刻表ビューに適用されます。
		 */
		bool m_bKyoukaisen ;
	///@}
	// ********************************
	//	コンストラクタ
	// ********************************
	 public:
		CdDedEki() : 
			m_bChakujikokuHyouji( false ) , 
			m_bHatsujikokuHyouji( false ) ,
			m_eEkikibo( CentDedEki::Ekikibo_Ippan ) ,
			m_bKyoukaisen( false ){};

		CdDedEki(
			const string&	strEkimei ,
			bool bChakujikokuHyouji ,
			bool bHatsujikokuHyouji ,
			CentDedEki::EEkikibo	eEkikibo ,
			bool bKyoukaisen ):
			m_strEkimei( strEkimei ),
			m_bChakujikokuHyouji( bChakujikokuHyouji ) ,
			m_bHatsujikokuHyouji( bHatsujikokuHyouji ) ,
			m_eEkikibo( eEkikibo ) ,
			m_bKyoukaisen( bKyoukaisen ) {};

	// ********************************
	//	CentDedEkiCont::CdDedEki
	// ********************************
	 public:
		// ********************************
		///@name CentDedEkiCont::CdDedEki-属性
		// ********************************
		///@{
		string	getEkimei()const{	return m_strEkimei ;};
		CdDedEki& setEkimei( const string& value ){	
			m_strEkimei = value ;return *this ; } ;
		bool getChakujikokuHyouji()const{	return m_bChakujikokuHyouji ;};
		CdDedEki& setChakujikokuHyouji( bool value ){	
			m_bChakujikokuHyouji = value ; return *this ; } ;
		bool getHatsujikokuHyouji()const{ return m_bHatsujikokuHyouji ;};
		CdDedEki& setHatsujikokuHyouji( bool value ){
			m_bHatsujikokuHyouji = value ; return *this ; } ;
		CentDedEki::EEkikibo	getEkikibo()const{ return m_eEkikibo ;};
		CdDedEki& setEkikibo( CentDedEki::EEkikibo value ){
			m_eEkikibo = value ; return *this ; } ;
		bool getKyoukaisen()const{ return m_bKyoukaisen ;};
		CdDedEki& setKyoukaisen( bool value ){
			m_bKyoukaisen = value ; return *this ; } ;

		/**
		 * @return 
		 *	着発の両方の時刻を表示する駅では真です。
		 */
		bool isHatsuChakuHyouji()const{
			return m_bChakujikokuHyouji && m_bHatsujikokuHyouji;};
	
		///@}
	};

private:
	// ----------------------------------------------------------------
	//	CentDedEkiCont::ContKudari
	// ----------------------------------------------------------------
	/**
	 * @brief
	 *	下りの『駅Order』 をインデクスとした、
	 *		 IfContGet< CentDedEkiCont::CdDedEki > 
	 *	を作成するためのアダプタです。
	 */
	class ContKudari : public IfContGet< CdDedEki >
	{
	// ********************************
	//	IfContGet< CentDedEkiCont::CdDedEki >
	// ********************************
		/**
		 * @return 
		 *	コンテナに格納されているデータの個数を返します。 
 		 */
		virtual int  size()const ; 
		/**
		 *	コンテナ内の、インデクスで指定された場所に格納されている 
		 *	データを返します。 
		 * @param iEkiOrder [in] 
		 *	下りり方向の『駅Order』を指定してください。 
		 *	範囲は０以上 size() 未満です。
		 *	 INT_MAX は、末尾を指定したものとみなします。
		 */
		virtual CdDedEki get(int iEkiOrder )const ;
	
		
	} m_xContKudari ;
	friend class ContKudari ;
	// ----------------------------------------------------------------
	//	CentDedEkiCont::ContNobori
	// ----------------------------------------------------------------
	/**
	 * @brief
	 *	上りの『駅Order』 をインデクスとした、	
	 *		 IfContGet< CentDedEkiCont::CdDedEki > 
	 *	を作成するためのアダプタです。
	 */
	class ContNobori : public IfContGet< CdDedEki >
	{
	// ********************************
	//	IfContGet< CentDedEkiCont::CdDedEki >
	// ********************************
	 public:
		/**
		 * @return 
		 *	コンテナに格納されているデータの個数を返します。 
 		 */
		virtual int  size()const ; 
		/**
		 *	コンテナ内の、インデクスで指定された場所に格納されている 
		 *	データを返します。 
		 * @param iEkiOrder [in] 
		 *	上り方向の『駅Order』を指定してください。 
		 *	範囲は０以上 size() 未満です。
		 *	 INT_MAX は、末尾を指定したものとみなします。
		 */
		virtual CdDedEki get(int iEkiOrder )const ;
	
	} m_xContNobori ;
	friend class ContNobori ;
	
// ********************************
///@name 包含
// ********************************
private:
	
	/**
	 *	『駅Index』 をインデクスとして、 CentDedEki を保持するコンテナ。
	 */
	CCont_deque< CentDedEki >	m_CentDedEkiCont ;
	
	/**
	 *	『駅Index』 をインデクスとした、 IfContGet< const CentDedEki* > を
	 *	作成するためのアダプタです。
	 */
	CaValueCont< CentDedEki >*	m_pCaValueCont ;



// ********************************
//	コンストラクタ
// ********************************
public:
	CentDedEkiCont() ;
	CentDedEkiCont( const CentDedEkiCont& value ) ;
	CentDedEkiCont& operator=( const CentDedEkiCont& value ) ;
	virtual ~CentDedEkiCont() ;
	
// ********************************
///@name	IfContGet<CentDedEki>
// ********************************
///@{
 public:
	virtual int  size () const{	return m_CentDedEkiCont.size() ; };
	virtual CentDedEki  get (int iIndex) const{ return m_CentDedEkiCont.get( iIndex ) ; } ;
///@}
// ********************************
///@name	IfCont<CentDedEki>
// ********************************
///@{
 public:
	virtual int  set (const CentDedEki& element, int iIndex){
		return m_CentDedEkiCont.set( element , iIndex ) ;};
	virtual int  insert (const CentDedEki& element, int iIndex =INT_MAX){
		return m_CentDedEkiCont.insert( element , iIndex ) ;};
	virtual int  erase (int iIndex, int iSize=1){
		return m_CentDedEkiCont.erase( iIndex , iSize ) ;};
	
///@}
// ********************************
//	CentDedEkiCont
// ********************************
 public:
	// ********************************
	///@name CentDedEkiCont-操作
	// ********************************
	///@{
	/**
	 *	『駅Index』 をインデクスにして、コンテナ内の駅オブジェクトに
	 *	アクセスすることのできる IfContGet<CentDedEki*> インターフェースを
	 *	取得することができます。
	 * @return 
	 *	コンテナ内の要素のオブジェクトに
	 *	アクセスするための IfContGet<CentDedEki*>* を返します。
	 *
	 */
	IfContGet<const CentDedEki*>* getIfContGet()
	{
		return m_pCaValueCont->getIfContGetConstPtr() ;	
	};
	const IfContGet<const CentDedEki*>* getIfContGet()const
	{
		return m_pCaValueCont->getIfContGetConstPtr() ;
	};
	
	/**
	 *	『駅Order』 をインデクスにして、コンテナ内の駅オブジェクトの
	 *	情報を取得するためのインターフェースを返します。
	 *
	 *	このインターフェースをつかうと、『駅Order』をインデクスに指定して、
	 *	対応する駅の情報を CentDedEkiCont::CdDedEki 形式で
	 *	取得することができます。
	 * @param eRessyahoukou [in]
	 *	列車方向を指定してください。
	 * @return 
	 *	コンテナ内の駅オブジェクト CentDedEki オブジェクトの属性を返す
	 *	インターフェースを返します。
	 */
	IfContGet<CdDedEki>* getIfContGet( ERessyahoukou eRessyahoukou )
	{
		if ( eRessyahoukou == Ressyahoukou_Nobori ){
			return &m_xContNobori ;	
		}
		return &m_xContKudari ;	
	};
	const IfContGet<CdDedEki>* getIfContGet( ERessyahoukou eRessyahoukou )const
	{
		if ( eRessyahoukou == Ressyahoukou_Nobori ){
			return &m_xContNobori ;	
		}
		return &m_xContKudari ;	
	};
	
	//yotei haisi
	/**
	 *	指定の『駅Order』の駅における、着時刻表示・発時刻表示の
	 *	有無を調べることができます。
	 * @param eRessyahoukou [in]
	 *	列車方向を指定してください。
	 *	- Ressyahoukou_Kudari
	 *	- Ressyahoukou_Nobori
	 *	のいずれかです。
	 * @param iEkiOrder [in]
	 *	『駅Order』を指定してください。
	 *	INT_MAX は、末尾の駅を指定したものとみなします。
	 * @param piChaku [out]
	 *	この関数は、指定の駅が着時刻を表示すべきであれば 1 、
	 *	そうでないなら0を書き込みます。
	 * @param piHatsu [out]
	 *	この関数は、指定の駅が発時刻を表示すべきであれば 1 、
	 *	そうでないなら0を書き込みます。
	 */
	void getEkijikokukeisiki( ERessyahoukou eRessyahoukou , int iEkiOrder ,
		int* piChaku , int* piHatsu )const ;
	
	
	/**
	 *	『駅Order(駅方向別Index)』を、『駅Index』に変換します。
	 * @param eRessyahoukou [in]
	 *	列車方向を指定してください。
	 *	- Ressyahoukou_Kudari
	 *	- Ressyahoukou_Nobori
	 *	のいずれかです。
	 * @param iEkiOrder [in]
	 *	『駅Order』を指定してください。
	 * @return 
	 *	0以上の『駅Index』を返します。
	 *	引数が不正な場合は、 -1 を返します。
	 */
	int EkiIndexOfEkiOrder( ERessyahoukou eRessyahoukou , int iEkiOrder )const ;
	
	/**
	 *	『駅Index』を『駅Order(駅方向別Index)』に変換します。
	 * @param eRessyahoukou [in]
	 *	列車方向を指定してください。
	 *	- Ressyahoukou_Kudari
	 *	- Ressyahoukou_Nobori
	 *	のいずれかです。
	 * @param iEkiIndex [in]
	 *	『駅Index』を指定してください。
	 * @return 
	 *	0以上の『駅Order』を返します。
	 *	引数が不正な場合は、 -1 を返します。
	 */
	int EkiOrderOfEkiIndex(  ERessyahoukou eRessyahoukou , int iEkiIndex )const ;
};



#endif /*CentDedEkiCont_h*/
