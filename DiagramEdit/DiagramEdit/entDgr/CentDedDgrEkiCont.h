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
//	CentDedDgrEkiCont.h
//	$Id: CentDedDgrEkiCont.h 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrEkiCont_h
#define  CentDedDgrEkiCont_h

#include "NsMu\CMuiCopied.h"
#include "entDed\CentDed.h"
#include "CentDedDgrEki.h"

namespace entDgr{
	using namespace entDed;
	using namespace OuLib::NsMu;

// ****************************************************************
//	CentDedDgrEkiCont
// ****************************************************************
/**
 @brief
	ダイヤグラムの『駅』(CentDedEki) オブジェクトのコンテナです。

	このクラス自体は、 Mui< CentDedDgrEki > インターフェースを
	サポートします。このインターフェースにより、 CentDedDgrEki オブジェクトを
	追加・変更・削除することができます。

	  引数なしの getMuPtr() メソッドにより、 Mu< const CentDedDgrEki* >
	インターフェースを取得することができます。
	  このインターフェースを使うと、コンテナ内の CentDedDgrEki 
	オブジェクトに直接アクセスすることができますが、
	CentDedEki オブジェクトの属性を変更することはできません。
	属性の変更は、 set() メソッドを使わなくてはなりません。

  	また、列車方向( ERessyahoukou )の引数をとる getMuPtr() 
  	メソッドにより、 列車方向別の
  		Mu< CentDedDgrEkiCont::CdDedDgrEki >
  	インターフェースを取得することができます。
  	この方法で、『駅Order』に対応する駅の情報を取得することもできます。
  	
   @attention
  	this の get() メソッドは、 CentDedDgrEki オブジェクトのコピーを返します。
  	get() メソッドで返されたオブジェクトに対して、
  	CentDedEki オブジェクトを更新するメソッドを呼び出しても、
  	コンテナ内の駅オブジェクトを更新することはできません。
  	コンテナ内の駅オブジェクトのメソッドを呼び出す場合は、
  	getMuPtr() で Mu<const CentDedDgrEki*>* を取得してから、
  	そのインターフェース経由で CentDedDgrEki* を取得し、そのポインタに
  	メソッドを呼び出してください。
*/
class CentDedDgrEkiCont : public CMuiCopied< CentDedDgrEki >
{
public:
	typedef CMuiCopied< CentDedDgrEki >	super ;
	// ****************************************************************
	//	CentDedDgrEkiCont::CdDedDgrEki
	// ****************************************************************
	/**
	   @brief
	  	駅の情報を保持する、単純データクラスです。
	  	CentDedDgrEkiCont::getMuPtr() メソッドにより、 
	  	Mu< CentDedDgrEkiCont::CdDedDgrEki > インターフェースを取得すると、
	  	コンテナ内の駅の属性を、この形式で取得することができます。
	  
	  	この単純データクラスで取得する情報は、列車方向{下り,上り}に合わせた
	  	形式になっています。
	  
	  	となります。
	 */
	class CdDedDgrEki
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
		 	主要駅なら真です。
		 */
		bool  m_bIsSyuyoueki ;
	
		/**
			この駅から次の駅Orderまでの
		 	最小所要秒数です。
	 
		 	終点駅では、この値は 0 です。
	 
		 	また、この駅間での駅間最小所要秒数が計算不能（データなし）の場合は、
		 	 0 です。
		 */
		int m_iEkikanSaisyouSec ;

		/**
			ダイヤグラムの既定の駅間幅。

			列車設定のない駅間の、ダイヤグラムビュー上での
			縦方向の幅を『ダイヤグラムエンティティY座標』単位(秒)で指定します。
	
			既定値は 60 です。
		*/
		int	m_iDgrYSizeEkikanDefault ;

		/**
			ダイヤグラム列車情報表示
	
			既定値は DiagramRessyajouhouHyouji_Origin です。
		*/
		CentDedDgrEki::EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyouji ;

		/**
			この駅のY座標の高さ。
			当面は、0です。
			将来のための予約されています。
		*/
		int m_iDgrYSize ;

		/**
			前の駅Orderからこの駅Orderまでの
		 	『ダイヤグラムエンティティY座標』での距離。
	 
		 	終点駅では、この値は 0 です。
		*/
		int m_iDgrYSizeEkikan ;
		///@}
	// ********************************
	//	コンストラクタ
	// ********************************
	 public:
		CdDedDgrEki() : 
			m_bIsSyuyoueki( false ) , 
			m_iEkikanSaisyouSec( 0 ) ,
			m_iDgrYSizeEkikanDefault( 0 ) ,
			m_eDiagramRessyajouhouHyouji( CentDedDgrEki::DiagramRessyajouhouHyouji_Origin ) ,
			m_iDgrYSize( 0 ) ,
			m_iDgrYSizeEkikan( 0 ) 
		{} ;

		CdDedDgrEki(
			const std::string& strEkimei ,
			bool  bIsSyuyoueki ,
			int iEkikanSaisyouSec ,
			int	iDgrYSizeEkikanDefault ,
			CentDedDgrEki::EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyouji ,
			int iDgrYSize ,
			int iDgrYSizeEkikan ) :
			m_strEkimei( strEkimei ) ,
			m_bIsSyuyoueki( bIsSyuyoueki ) ,
			m_iEkikanSaisyouSec( iEkikanSaisyouSec ) ,
			m_iDgrYSizeEkikanDefault( iDgrYSizeEkikanDefault ),
			m_eDiagramRessyajouhouHyouji( eDiagramRessyajouhouHyouji ) ,
			m_iDgrYSize( iDgrYSize ) ,
			m_iDgrYSizeEkikan( iDgrYSizeEkikan ) 
		{}



	// ********************************
	//	CentDedDgrEkiCont::CdDedDgrEki
	// ********************************
	 public:
		// ********************************
		///@name CentDedDgrEkiCont::CdDedDgrEki::属性
		// ********************************
		///@{
		std::string	getEkimei()const{	return m_strEkimei ;};
		bool  getIsSyuyoueki()const{	return m_bIsSyuyoueki ;};
		int getEkikanSaisyouSec()const{	return m_iEkikanSaisyouSec ;};
		int	getDgrYSizeEkikanDefault()const{	return m_iDgrYSizeEkikanDefault ;};
		CentDedDgrEki::EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyouji()const
		{	return m_eDiagramRessyajouhouHyouji ;};
		int getDgrYSize()const{	return m_iDgrYSize ;};
		int getDgrYSizeEkikan()const{	return m_iDgrYSizeEkikan ;};
		///@}
	};

private:
	// ----------------------------------------------------------------
	//	CentDedDgrEkiCont::ContKudari
	// ----------------------------------------------------------------
	/**
	   @brief
	  	下りの『駅Order』 をインデクスとした、
	  		 Mu< CentDedDgrEkiCont::CdDedDgrEki > 
	  	を作成するためのアダプタです。
	 */
	class ContKudari : public Mu< CdDedDgrEki >
	{
	public:
		// ********************************
		//	Mu< CentDedDgrEkiCont::CdDedDgrEki >
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
		virtual CdDedDgrEki get(int iEkiOrder )const ;
	
		
	} m_xContKudari ;
	friend class ContKudari ;
	// ----------------------------------------------------------------
	//	CentDedDgrEkiCont::ContNobori
	// ----------------------------------------------------------------
	/**
	   @brief
	  	上りの『駅Order』 をインデクスとした、	
	  		 Mu< CentDedDgrEkiCont::CdDedDgrEki > 
	  	を作成するためのアダプタです。
	 */
	class ContNobori : public Mu< CdDedDgrEki >
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
		virtual CdDedDgrEki get(int iEkiOrder )const ;
	
	} m_xContNobori ;
	friend class ContNobori ;
	
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{	
	///@}

// ********************************
//	コンストラクタ
// ********************************
public:
	CentDedDgrEkiCont() ;
	CentDedDgrEkiCont( const CentDedDgrEkiCont& value ) ;
	CentDedDgrEkiCont& operator=( const CentDedDgrEkiCont& value ) ;
	virtual ~CentDedDgrEkiCont() ;

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
	Mu<CdDedDgrEki>* getMuPtr( ERessyahoukou eRessyahoukou )
	{
		if ( eRessyahoukou == Ressyahoukou_Nobori ){
			return &m_xContNobori ;	
		}
		return &m_xContKudari ;	
	};
	const Mu<CdDedDgrEki>* getMuPtr( ERessyahoukou eRessyahoukou )const
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
	int EkiOrderOfEkiIndex(  ERessyahoukou eRessyahoukou , int iEkiIndex )const ;
	///@}
};


} //namespace entDgr

#endif /*CentDedDgrEkiCont_h*/
