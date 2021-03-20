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
//	$Id: CentDedEkiCont.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CentDedEkiCont_h
#define  CentDedEkiCont_h

#include "Mu/CMuiCopied.h"

#include "CentDed.h"
#include "CentDedEki.h"
#include "CdDedjikokuOrder.h"

// ****************************************************************
//	CentDedEkiCont
// ****************************************************************
/**
 @brief
  『駅』(CentDedEki) オブジェクトのコンテナです。

  	このクラス自体は、 Mui< CentDedEki > インターフェースを
  	サポートします。このインターフェースにより、 CentDedEki オブジェクトを
  	追加・変更・削除することができます。
  
  	  引数なしの getMuPtr() メソッドにより、 Mu< const CentDedEki* >
  	インターフェースを取得することができます。
  	  このインターフェースを使うと、コンテナ内の CentDedEki 
  	オブジェクトに直接アクセスすることができますが、
  	CentDedEki オブジェクトの属性を変更することはできません。
  	属性の変更は、 set() メソッドを使わなくてはなりません。
  
  	  また、列車方向( ERessyahoukou )の引数をとる getMuPtr() 
  	メソッドにより、 列車方向別の
  		Mu< CentDedEkiCont::CdDedEki >
  	インターフェースを取得することができます。
  	この方法で、『駅Order』に対応する駅の情報を取得することもできます。
  	
   @attention
  	this の get() メソッドは、 CentDedEki オブジェクトのコピーを返します。
  	get() メソッドで返されたオブジェクトに対して、
  	CentDedEki オブジェクトを更新するメソッドを呼び出しても、
  	コンテナ内の駅オブジェクトを更新することはできません。
  	コンテナ内の駅オブジェクトのメソッドを呼び出す場合は、
  	getMuPtr() で Mu<const CentDedEki*>* を取得してから、
  	そのインターフェース経由で CentDedEki* を取得し、そのポインタに
  	メソッドを呼び出してください。
  

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
	『駅Index』になっています。@n
	  これとは対照的に、『列車』(クラスでは、原則として
	『駅時刻』 ( CentDedEkiJikoku ) オブジェクトを指定するのには
	『駅Order』を使います。『駅時刻』 ( CentDedEkiJikoku ) を保持するコンテナ
	  CentDedRessya::m_CentDedEkiJikokuCont の添え字も、『駅Order』 
	となります。
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
	

<H4>
【時刻Orderと時刻表Index】
</H4>
	時刻表Indexは、時刻表上で駅Orderに対応する着時刻・発時刻が
	何行目に位置するかを示します。
	この値は各駅の駅時刻形式の影響を受けます。

(例)
  下り列車
	- 駅Order=0 駅時刻形式=発時刻  ; 
		- 着時刻(時刻Order=0) の時刻表Index=なし 
		- 発時刻(時刻Order=1)の時刻表Index=0 
	- 駅Order=1 駅時刻形式=発時刻  ; 
		- 着時刻(時刻Order=2)の時刻表Index=なし 
		- 発時刻(時刻Order=3)の時刻表Index=1 
	- 駅Order=2 駅時刻形式=発着    ; 
		- 着時刻(時刻Order=4)の時刻表Index=2 
		- 発時刻(時刻Order=5)の時刻表Index=3 
	- 駅Order=3 駅時刻形式=下り着時刻 ; 
		- 着時刻(時刻Order=6)の時刻表Index=4 
		- 発時刻(時刻Order=7)の時刻表Index=なし 
	- 駅Order=4 駅時刻形式=上り着時刻 ; 
		- 着時刻の時刻表Index=なし 
		- 発時刻の時刻表Index=5 
	- 駅Order=5(終着駅) 駅時刻形式=発時刻  ; 
		- 着時刻の時刻表Index=6 
		- 発時刻の時刻表Index=なし 


*/
class CentDedEkiCont : public CMuiCopied< CentDedEki >
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	typedef CMuiCopied< CentDedEki >	super ;

	/** 時刻表ビューの駅毎の列の種類を表す列挙です。 */
	enum EEkiColumnType
	{
		EEkiColumnType_Chaku = 0 ,	///<着時刻
		EEkiColumnType_Hatsu = 1 ,	///<発時刻
	};
	// ****************************************************************
	//	CentDedEkiCont::CdDedEki
	// ****************************************************************
	/**
	   @brief
	  	駅の情報を保持する、単純データクラスです。
	  	CentDedEkiCont::getMuPtr() メソッドにより、 
	  	Mu< CentDedEkiCont::CdDedEki > インターフェースを取得すると、
	  	コンテナ内の駅の属性を、この形式で取得することができます。
	  
	  	この単純データクラスで取得する情報は、列車方向{下り,上り}に合わせた
	  	形式になっています。
	  	例えば、駅時刻形式が[下り着時刻]となっている駅があった場合、
	  
	  	その駅の CentDedEkiCont::CdDedEki オブジェクトを下り方向で取得すると
	  		- m_bChakujikokuHyouji = true ;
	  		- m_bHatsujikokuHyouji = false ;
	  
	  	同じ駅の CentDedEkiCont::CdDedEki オブジェクトを上り方向で取得すると
	  		- m_bChakujikokuHyouji = false ;
	  		- m_bHatsujikokuHyouji = true ;
	  
	  	となります。
	 */
	class CdDedEki
	{
	 private:
		// ********************************
		///@name 属性
		// ********************************
		///@{
		/**
		  	駅名
		  
		  	規定値は、空文字列。
		 */
		std::string	m_strEkimei ;
		
		/**
		  	駅時刻形式。
		  	着時刻表示あり。
		 */
		bool m_bChakujikokuHyouji ;
	
		/**
		  	駅時刻形式。
		  	発時刻表示あり。
		 */
		bool m_bHatsujikokuHyouji ;
		
		/**
		  	『駅規模』を表す列挙です。
		  
		  	規定値は、 Ekikibo_Ippan 
		 */
		CentDedEki::EEkikibo	m_eEkikibo ;
	
		/**
		  	この駅の下（終着駅より）に、境界線あり。
		  
		   	この属性が true の駅では、時刻表画面の駅欄の下側に
		  	太い境界線を描画します。
		   	この属性は、駅ビューと時刻表ビューに適用されます。
		 */
		bool m_bKyoukaisen ;

		/**
			ダイヤグラム列車情報表示
		
			この属性が true の駅では、ダイヤグラムビューにおいて、
			列車の列車情報を描画します。

			既定値は false です。
		*/	
		CentDedEki::EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyouji ;

		///@}
	// ********************************
	//	コンストラクタ
	// ********************************
	 public:
		CdDedEki() : 
			m_bChakujikokuHyouji( false ) , 
			m_bHatsujikokuHyouji( false ) ,
			m_eEkikibo( CentDedEki::Ekikibo_Ippan ) ,
			m_bKyoukaisen( false ) , 
			m_eDiagramRessyajouhouHyouji( CentDedEki::DiagramRessyajouhouHyouji_Origin ){};

		CdDedEki(
			const std::string&	strEkimei ,
			bool bChakujikokuHyouji ,
			bool bHatsujikokuHyouji ,
			CentDedEki::EEkikibo	eEkikibo ,
			bool bKyoukaisen , 
			CentDedEki::EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyouji ):
			m_strEkimei( strEkimei ),
			m_bChakujikokuHyouji( bChakujikokuHyouji ) ,
			m_bHatsujikokuHyouji( bHatsujikokuHyouji ) ,
			m_eEkikibo( eEkikibo ) ,
			m_bKyoukaisen( bKyoukaisen ), 
			m_eDiagramRessyajouhouHyouji( eDiagramRessyajouhouHyouji ) {};

	// ********************************
	//	CentDedEkiCont::CdDedEki
	// ********************************
	 public:
		// ********************************
		///@name CentDedEkiCont::CdDedEki-属性
		// ********************************
		///@{
		std::string	getEkimei()const{	return m_strEkimei ;};
		CdDedEki& setEkimei( const std::string& value ){	
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
		CentDedEki::EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyouji()const
		{	return m_eDiagramRessyajouhouHyouji ;};
		CdDedEki& setDiagramRessyajouhouHyouji( CentDedEki::EDiagramRessyajouhouHyouji value )
		{	m_eDiagramRessyajouhouHyouji = value ; return *this ;};

		/**
		   @return 
		  	着発の両方の時刻を表示する駅では真です。
		 */
		bool isHatsuChakuHyouji()const
		{	return m_bChakujikokuHyouji && m_bHatsujikokuHyouji;};
	
		///@}
	};

private:
	// ----------------------------------------------------------------
	//	CentDedEkiCont::ContKudari
	// ----------------------------------------------------------------
	/**
	   @brief
	  	下りの『駅Order』 をインデクスとした、
	  		 Mu< CentDedEkiCont::CdDedEki > 
	  	を作成するためのアダプタです。
	 */
	class ContKudari : public Mu< CdDedEki >
	{
	public:
		// ********************************
		//	Mu< CentDedEkiCont::CdDedEki >
		// ********************************
		/**
		   @return 
		  	コンテナに格納されているデータの個数を返します。 
 		 */
		virtual int  size()const ; 
		/**
		  	コンテナ内の、インデクスで指定された場所に格納されている 
		  	データを返します。 
		   @param iEkiOrder [in] 
		  	下りり方向の『駅Order』を指定してください。 
		  	範囲は０以上 size() 未満です。
		  	 INT_MAX は、末尾を指定したものとみなします。
		 */
		virtual CdDedEki get(int iEkiOrder )const ;
	
		
	} m_xContKudari ;
	friend class ContKudari ;
	// ----------------------------------------------------------------
	//	CentDedEkiCont::ContNobori
	// ----------------------------------------------------------------
	/**
	   @brief
	  	上りの『駅Order』 をインデクスとした、	
	  		 Mu< CentDedEkiCont::CdDedEki > 
	  	を作成するためのアダプタです。
	 */
	class ContNobori : public Mu< CdDedEki >
	{
	public:
		// ********************************
		//	Mu< CentDedEkiCont::CdDedEki >
		// ********************************
		/**
		   @return 
		  	コンテナに格納されているデータの個数を返します。 
 		 */
		virtual int  size()const ; 
		/**
		  	コンテナ内の、インデクスで指定された場所に格納されている 
		  	データを返します。 
		   @param iEkiOrder [in] 
		  	上り方向の『駅Order』を指定してください。 
		  	範囲は０以上 size() 未満です。
		  	 INT_MAX は、末尾を指定したものとみなします。
		 */
		virtual CdDedEki get(int iEkiOrder )const ;
	
	} m_xContNobori ;
	friend class ContNobori ;
	
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{	
	///@}



public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CentDedEkiCont() ;
	CentDedEkiCont( const CentDedEkiCont& value ) ;
	CentDedEkiCont& operator=( const CentDedEkiCont& value ) ;
	virtual ~CentDedEkiCont() ;
	
public:
	// ********************************
	///@name	CMuiCopied<CentDedEki>
	// ********************************
	///@{

	/**
		基本クラスの Mu<CentDedEki*>* getMuPtr() は、
		このクラスのオーバーロード
		Mu<CdDedEki>* getMuPtr( ERessyahoukou eRessyahoukou )
		によって隠蔽されます。
		この隠蔽を解除するため、以下の宣言を行っています。
		これは、以下のコードと等価です。
	@code
	Mu<CentDedEki*>* getMuPtr()
	{	
		return super::getMuPtr() ;
	};
	const Mu<const CentDedEki*>* getMuPtr()const
	{
		return super::getMuPtr() ;
	};
	@endcode
	*/
	super::getMuPtr ;
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
		『駅Order』 をインデクスにして、コンテナ内の駅オブジェクトの
		情報を取得するためのインターフェースを返します。
	
		このインターフェースをつかうと、『駅Order』をインデクスに指定して、
		対応する駅の情報を CentDedEkiCont::CdDedEki 形式で
		取得することができます。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
	 @return 
		コンテナ内の駅オブジェクト CentDedEki オブジェクトの属性を返す
		インターフェースを返します。
	 */
	Mu<CdDedEki>* getMuPtr( ERessyahoukou eRessyahoukou )
	{
		if ( eRessyahoukou == Ressyahoukou_Nobori ){
			return &m_xContNobori ;	
		}
		return &m_xContKudari ;	
	};
	const Mu<CdDedEki>* getMuPtr( ERessyahoukou eRessyahoukou )const
	{
		if ( eRessyahoukou == Ressyahoukou_Nobori ){
			return &m_xContNobori ;	
		}
		return &m_xContKudari ;	
	};
	
	/**
		『駅Order(駅方向別Index)』を、『駅Index』に変換します。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		のいずれかです。
	 @param iEkiOrder [in]
		『駅Order』を指定してください。
	 @return 
		0以上の『駅Index』を返します。
		引数が不正な場合は、 -1 を返します。
	 */
	int EkiIndexOfEkiOrder( ERessyahoukou eRessyahoukou , int iEkiOrder )const ;
	
	/**
		『駅Index』を『駅Order(駅方向別Index)』に変換します。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		のいずれかです。
	 @param iEkiIndex [in]
		『駅Index』を指定してください。
	 @return 
		0以上の『駅Order』を返します。
		引数が不正な場合は、 -1 を返します。
	 */
	int EkiOrderOfEkiIndex( ERessyahoukou eRessyahoukou , int iEkiIndex )const;

	///@}

};



#endif /*CentDedEkiCont_h*/
