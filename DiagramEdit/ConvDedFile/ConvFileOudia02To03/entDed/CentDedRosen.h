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
//	CentDedRosen.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRosen_h
#define  CentDedRosen_h

#include <deque>
using namespace std ;

#include "CentDed.h"
#include "CentDedEkiCont.h"
#include "CentDedRessyasyubetsuCont.h"
#include "CentDedDiaCont.h"
#include "Cont/CaCont_vector.h"

// ****************************************************************
//	CentDedRosen
// ****************************************************************
/**
 *	@brief
 *	【概要】  DiagramEdit の、『路線』１つを表します。
 *	  このクラスは、 DiagramEdit のエンティティクラス CentDed... の
 *	ルートとなるクラスです。以下のクラスのオブジェクトを包含します。
 *	
 *	- 『駅』 ( CentDedEki ) ： 0 以上複数のオブジェクトを包含します。
 *
 *	- 『列車種別』 ( CentDedRessyasyubetsu ) ： 1 以上複数のオブジェクトを
 *	包含します。
 *
 *	- 『ダイヤ』 ( CentDedDia ) ： 0 以上複数のオブジェクトを包含します。
 *	『ダイヤ』 ( CentDedDia ) は、『列車』 ( CentDedRessya ) を０以上複数
 *	包含しています。さらに、『列車』は、『駅時刻』 ( CentDedEkiJikoku ) を
 *	『駅』の数だけ包含しています。
 *
 *	\n this に包含される CentDedDia は、 CentDedDia::m_strName が一意でなくては
 *	なりません。同名の CentDedDia を insertCentDedDia() で登録しようとすると、
 *	エラーとなります。
 *
 *  『駅』オブジェクトを追加・削除した場合、this は包含している
 *	すべての『列車』 ( CentDedRessya ) に対して、
 *	『駅時刻』 ( CentDedEkiJikoku )オブジェクトの追加・削除を行います。
 *	
 *	  『列車種別』オブジェクトを削除した場合、 this は包含しているすべての
 *	『列車』オブジェクトのうち、削除された『列車種別Index』を持つ『列車』
 *	に対して、『列車種別Index』を0(既定の列車種別)に変更します。
 *
 *
 *	  『駅Index』は、路線の下り列車の始発駅（上り列車の終着駅）が 0 ・ 
 *	下り列車の終着駅（上り列車の始発駅） が ( 駅の数 - 1 ) となります。
 * @see CentDedRessya
 *	【駅Index と 駅Order】 を参照してください。
 */
class CentDedRosen
{
// ********************************
//	インナータイプ
// ********************************
public:

protected:
	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedEkiCont
	// ----------------------------------------------------------------
	/**
	 *	@brief
	 *  『路線』オブジェクトに包含される、
	 *	『駅』(CentDedEki) オブジェクトのコンテナです。
	 *
	 *  『駅』オブジェクトを追加・削除した場合、
	 *	this は関連する『路線』が包含している
	 *	すべての『列車』 ( CentDedRessya ) に対して、
	 *	『駅時刻』 ( CentDedEkiJikoku )オブジェクトの追加・削除を行います。
	 *	
	 */
	class CXCentDedEkiCont : public CentDedEkiCont
	{
	// ********************************
	//	インナータイプ
	// ********************************
	public:
		typedef CentDedEkiCont	super ;
	// ********************************
	///@name 関連
	// ********************************
	///@{
	 private:
		/**
		 *	『路線』オブジェクトとの関連です。
		 *
		 *	このオブジェクトの破棄の責務は、クラスユーザーにあります。
		 *	このオブジェクトは、thisの破棄後まで生存しなくてはなりません。
		 */
		CentDedRosen*	m_pCentDedRosen ;
	///@}
	// ********************************
	//	コンストラクタ
	// ********************************
	 public:
		/**
		 * @param pCentDedRosen [in]
		 *	『路線』オブジェクトとの関連です。
		 *	\nこのオブジェクトの破棄の責務は、クラスユーザーにあります。
		 *	このオブジェクトは、thisの破棄後まで生存しなくてはなりません。
		 *
		 * @attention
		 *	このコンストラクタは、
		 *	pCentDedRosen に含まれる全ての列車の駅数を、 this の駅数と
		 *	同じに調整します。
		 */
		CXCentDedEkiCont( CentDedRosen* pCentDedRosen ) ;

	 private:
		CXCentDedEkiCont( const CXCentDedEkiCont& value ){} ;
		CXCentDedEkiCont& operator=( const CXCentDedEkiCont& value ){} ;
	 public:
		virtual ~CXCentDedEkiCont() ;
		
	// ********************************
	//	IfCont
	// ********************************
	 public:
		/**
		 * 	コンテナ内の、インデクスで指定された場所の
		 *	要素を置き換えます。
		 * @param element [in]
		 * 	要素を指定してください。
		 * @param iIndex [in]
		 * 	０から始まるインデクスを指定してください。
		 * 	範囲は０以上 size() 以下です。
		 * 	０は、先頭・size()なら末尾への追加になります。
		 *	但し、INT_MAX は、末尾を指定したものとみなします。
		 * @return
		 * 	0以上は成功、負の数はエラーです
		 *
		 *	<H4>
		 *	【オーバライド】
		 *	</H4>
		 *	CentDedEki オブジェクトを追加するのに加えて、
		 *	m_pCentDedRosen が包含している全ての列車のうち、
		 *	iIndex の駅を始発・終着とする列車の駅時刻を
		 *	補正します。
		 */
	 	virtual int  set (const CentDedEki& element, int iIndex) ;

		/**
		 * 	コンテナ内の、インデクスで指定された場所に、
		 * 	要素を追加します。
		 * @param element [in]
		 * 	要素を指定してください。
		 * @param iIndex [in]
		 * 	０から始まるインデクスを指定してください。
		 * 	範囲は０以上 size() 以下です。
		 * 	０は、先頭・size()なら末尾への追加になります。
		 *	但し、INT_MAX は、末尾を指定したものとみなします。
		 * @return
		 * 	0以上は成功、負の数はエラーです
		 *
		 *	<H4>
		 *	【オーバライド】
		 *	</H4>
		 *	CentDedEki オブジェクトを追加するのに加えて、
		 *	m_pCentDedRosen が包含している全ての列車に対して、
		 *	駅時刻の追加を行います。
		 */
		virtual int insert( const CentDedEki& element , int iIndex = INT_MAX );
		/**
		 * 	コンテナ内の、インデクスで指定された場所の
		 * 	要素を削除します。
		 * @param iIndex [in]
		 * 	０から始まるインデクスを指定してください。
		 * 	範囲は０以上 size() 未満です。
		 * 	但し、INT_MAX は、末尾を指定したものとみなします。
		 * @param iSize [in]
		 * 	削除する要素の数を指定してください。
		 * 	但し、INT_MAX は、 iIndex から末尾までを表します。
		 * @attention
		 *	iIndex と iSize の両方を INT_MAX にすることはできません。
		 * @return
		 * 	0以上は成功、負の数はエラーです
		 *
		 *	<H4>
		 *	【オーバライド】
		 *	</H4>
		 *	CentDedEki オブジェクトを削除するのに加えて、
		 *	m_pCentDedRosen が包含している全ての列車に対して、
		 *	駅時刻の削除を行います。
		 */
		virtual int erase( int iIndex  , int iSize = 1 ) ;
	};
	friend class CXCentDedEkiCont ;

	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedRessyasyubetsuCont
	// ----------------------------------------------------------------
	/**
	 *	@brief
	 *  『路線』オブジェクトに包含される、
	 *	『列車種別』(CentDedRessyasyubetsu) オブジェクトのコンテナです。
	 *	
	 *	通常の列車種別コンテナに加えて、以下のような特性が存在します。
	 *	
	 *	
	 * １．  『列車種別』オブジェクトを追加・削除した場合、
	 *	this は関連する『路線』が包含している
	 *	すべての『列車』 ( CentDedRessya ) に対して、
	 *	『列車種別Index』 ( CentDedRessya::m_iRessyasyubetsuIndex )
	 *	の修正を行います。
	 *
	 *	２．  対応する列車が m_pCentDedRosen 内に存在する場合、
	 *	その列車種別を削除することはできません。
	 *	  通常、『列車種別』のコンテナを置き換える場合は、 
	 *	m_pCentDedRosen から、すべての列車を削除しておく必要があります。
	 */
	class CXCentDedRessyasyubetsuCont : public CentDedRessyasyubetsuCont
	{
	// ********************************
	//	インナータイプ
	// ********************************
	public:
		typedef CentDedRessyasyubetsuCont	super ;
	// ********************************
	///@name 関連
	// ********************************
	///@{
	 private:
		/**
		 *	『路線』オブジェクトとの関連です。
		 *
		 *	このオブジェクトの破棄の責務は、クラスユーザーにあります。
		 *	このオブジェクトは、thisの破棄後まで生存しなくてはなりません。
		 */
		CentDedRosen*	m_pCentDedRosen ;
	///@}
	// ********************************
	//	コンストラクタ
	// ********************************
	 public:
		/**
		 * @param pCentDedRosen [in]
		 *	『路線』オブジェクトとの関連です。
		 *	\nこのオブジェクトの破棄の責務は、クラスユーザーにあります。
		 *	このオブジェクトは、thisの破棄後まで生存しなくてはなりません。
		 *
		 */
		CXCentDedRessyasyubetsuCont( CentDedRosen* pCentDedRosen ) ;

	 private:
		CXCentDedRessyasyubetsuCont( const CXCentDedRessyasyubetsuCont& value ){} ;
		CXCentDedRessyasyubetsuCont& operator=( const CXCentDedRessyasyubetsuCont& value ){} ;
	 public:
		virtual ~CXCentDedRessyasyubetsuCont() ;
		
	// ********************************
	//	IfCont
	// ********************************
	 public:
		/**
		 * 	コンテナ内の、インデクスで指定された場所に、
		 * 	要素を追加します。
		 * @param element [in]
		 * 	要素を指定してください。
		 * @param iIndex [in]
		 * 	０から始まるインデクスを指定してください。
		 * 	範囲は０以上 size() 以下です。
		 * 	０は、先頭・size()なら末尾への追加になります。
		 *	但し、INT_MAX は、末尾を指定したものとみなします。
		 * @return
		 * 	0以上は成功、負の数はエラーです
		 *	-	-1 ;	//	iIndex が不正です。
		 *
		 *	<H4>
		 *	【オーバライド】
		 *	</H4>
		 *	CentDedRessyasyubetsu オブジェクトを追加するのに加えて、
		 *	すべての『列車』 ( CentDedRessya ) に対して、
		 *	『列車種別Index』 ( CentDedRessya::m_iRessyasyubetsuIndex )
		 *	の修正を行います。
		 */
		virtual int insert( const CentDedRessyasyubetsu& element , int iIndex = INT_MAX );
		/**
		 * 	コンテナ内の、インデクスで指定された場所の
		 * 	要素を削除します。
		 * @param iIndex [in]
		 * 	０から始まるインデクスを指定してください。
		 * 	範囲は０以上 size() 未満です。
		 * 	但し、INT_MAX は、末尾を指定したものとみなします。
		 * @param iSize [in]
		 * 	削除する要素の数を指定してください。
		 * 	但し、INT_MAX は、 iIndex から末尾までを表します。
		 * @attention
		 *	iIndex と iSize の両方を INT_MAX にすることはできません。
		 * @return
		 * 	0以上は成功、負の数はエラーです
		 *	-	-1 ;	//	iIndex が不正です。
		 *	-	-11 ;	//	削除対象の列車種別の列車が存在します。
		 *
		 *	<H4>
		 *	【オーバライド】
		 *	</H4>
		 *	CentDedRessyasyubetsu オブジェクトを削除するのに加えて、
		 *	すべての『列車』 ( CentDedRessya ) に対して、
		 *	『列車種別Index』 ( CentDedRessya::m_iRessyasyubetsuIndex )
		 *	の修正を行います。
		 */
		virtual int erase( int iIndex  , int iSize = 1 ) ;

	};
	friend class CXCentDedRessyasyubetsuCont ;



// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	 *	路線の名称です。
	 *	（例） "近鉄大阪線" など
	 */
	string	m_strName ;
	
	/**
	 *	ダイヤの起点時刻です。
	 *	この時刻は、ダイヤグラムの左端の時刻となります。
	 *
	 *	既定値は 00:00:00 です。
	 * @attention
	 *	この値は、 Null 状態にしないでください。
	 */
	CdDedJikoku	m_jikokuKitenJikoku ;
	
	/**
	 *	コメント。
	 *	CDedCommentDoc,CDedCommentView で編集します。
	 */
	string	m_strComment ;
	
///@}
// ********************************
///@name 包含
// ********************************
///@{
 private:
	/**
	 *	この『路線』にある『駅』 ( CentDedEki ) を保持します。
	 *
	 *	このコンテナ内の CentDedEki オブジェクトの
	 *	生成・破棄の責務はthisにあります。
	 *
	 *	初期状態では、要素数は 0 となります。
	 */
	CXCentDedEkiCont*	m_pCentDedEkiCont ;
	
	/**
	 *	この『路線』にある『列車種別』 ( CentDedRessyasyubetsu ) を保持します。
	 *
	 *	このコンテナ内の CentDedRessyasyubetsu オブジェクトの
	 *	生成・破棄の責務はthisにあります。
	 *
	 *	初期状態では、要素数は 1 となります。
	 *	『列車種別』は、少なくとも一つは存在しなくてはなりません。
	 */
	CXCentDedRessyasyubetsuCont*	m_pCentDedRessyasyubetsuCont ;
	
	/**
	 *	この『路線』にある『ダイヤ』 ( CentDedDia ) を保持します。
	 *
	 *	このコンテナ内の CentDedDia オブジェクトの
	 *	生成・破棄の責務はthisにあります。
	 *
	 *
	 * @attention
	 *	this は、 CentDedDia::m_strName を限定子として扱います。
	 *	\n このコンテナ内の CentDedDia は、 CentDedDia::m_strName が
	 *	一意でなくてはなりません。
	 *
	 *	初期状態では、要素数は 0 となります。
	 */
	CentDedDiaCont	m_CentDedDiaCont ;
	
///@}
	
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param strName [in]
	 *	路線の名称です。	\n
	 *	（例） "近鉄大阪線" など
	 */
	CentDedRosen() ;
	
	CentDedRosen( const CentDedRosen& value );
	CentDedRosen& operator=( const CentDedRosen& value );

	virtual ~CentDedRosen() ;

	
// ********************************
//	CentDedRosen
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	string	getName()const{	return m_strName ;};
	CentDedRosen& setName( const string& value ){
		m_strName = value ; return *this ; } ;
	CdDedJikoku	getKitenJikoku()const{	return m_jikokuKitenJikoku ;};
	CentDedRosen& setKitenJikoku( const CdDedJikoku& value ){
		m_jikokuKitenJikoku = value ; return *this ; 
	} ;
	string	getComment()const{return m_strComment ;};
	CentDedRosen& setComment( const string& value ){
		m_strComment = value ;	return *this ; 
	} ;
	///@}
	
	// ********************************
	///@name 包含-CentDedEki
	// ********************************
	///@{
	/**
	 * @return 
	 *	『駅』 ( CentDedEki ) オブジェクトのコンテナへの
	 *	インターフェースを返します。
	 *	このインターフェースは、 CentDedEki オブジェクトを路線に
	 *	追加・削除するためのインターフェースです。
	 */
	CentDedEkiCont* getCentDedEkiCont(){	return m_pCentDedEkiCont ; } ;
	const CentDedEkiCont* getCentDedEkiCont()const{	return m_pCentDedEkiCont ; } ;
	
	/**
	 *	『駅Index』 をインデクスにして、コンテナ内の駅オブジェクトに
	 *	アクセスすることのできる IfContGet<CentDedEki*> インターフェースを
	 *	取得することができます。
	 * @return 
	 *	コンテナ内の要素のオブジェクトに
	 *	アクセスするための IfContGet<CentDedEki*>* を返します。
	 *
	 *	このインターフェースの
	 */
	IfContGet<const CentDedEki*>* getCentDedEkiContGet()
	{
		return m_pCentDedEkiCont->getIfContGet() ;
	};
	const IfContGet<const CentDedEki*>* getCentDedEkiContGet()const
	{
		return m_pCentDedEkiCont->getIfContGet() ;
	};
	
	/**
	 *	『駅Order』 をインデクスにして、コンテナ内の駅オブジェクトの情報が取得できる
	 *	 IfContGet<CentDedEkiCont::CdDedEki> インターフェースを
	 *	取得することができます。
	 * @param eRessyahoukou [in]
	 *	列車方向を指定してください。
	 * @return 
	 *	コンテナ内の駅オブジェクト CentDedEki へのポインタに
	 *	アクセスするための IfContGet<CentDedEki*>* を返します。
	 */
	IfContGet<CentDedEkiCont::CdDedEki>* getCentDedEkiContGet( ERessyahoukou eRessyahoukou )
	{
		return m_pCentDedEkiCont->getIfContGet( eRessyahoukou ) ;
	};
	const IfContGet<CentDedEkiCont::CdDedEki>* getCentDedEkiContGet( ERessyahoukou eRessyahoukou )const
	{
		return m_pCentDedEkiCont->getIfContGet( eRessyahoukou ) ;
	};
	
	///@}
	
	// ********************************
	///@name 包含-CentDedRessyasyubetsu
	// ********************************
	///@{
	/**
	 * @return 
	 *	『列車種別』 ( CentDedRessyasyubetsu ) オブジェクトのコンテナへの
	 *	インターフェースを返します。
	 *	このインターフェースは、 CentDedRessyasyubetsu オブジェクトを路線に
	 *	追加・削除するためのインターフェースです。
	 */
	CentDedRessyasyubetsuCont* getCentDedRessyasyubetsuCont()
	{
		return m_pCentDedRessyasyubetsuCont ; 
	} ;
	const CentDedRessyasyubetsuCont* getCentDedRessyasyubetsuCont()const
	{
		return m_pCentDedRessyasyubetsuCont ; 
	} ;
	
	/**
	 *	『列車種別Index』 をインデクスにして、
	 *	コンテナ内の列車種別オブジェクトに
	 *	アクセスすることのできる IfContGet<CentDedRessyasyubetsu*> 
	 *	インターフェースを取得することができます。
	 * @return 
	 *	コンテナ内の要素のオブジェクトに
	 *	アクセスするための IfContGet<CentDedRessyasyubetsu*>* を返します。
	 *
	 *	このインターフェースの
	 */
	IfContGet<CentDedRessyasyubetsu*>* getCentDedRessyasyubetsuContGet()
	{
		return m_pCentDedRessyasyubetsuCont->getIfContGet() ;
	};
	const IfContGet<CentDedRessyasyubetsu*>* 
		getCentDedRessyasyubetsuContGet()const
	{
		return m_pCentDedRessyasyubetsuCont->getIfContGet() ;
	};

	
	/**
	 *	２つの『列車種別』のIndexを入れ替えます。
	 *
	 *	指定の列車種別Indexを持つすべての列車のIndexも、
	 *	入れ替わります。
	 *	
	 * @param iRessyasyubetsuIndexA , iRessyasyubetsuIndexB [in]
	 *	『列車種別Index』を指定してください。
	 *	範囲は、 0 以上 列車種別の数未満です。
	 *	INT_MAX は、末尾の列車種別を指定したものとみなします。
	 *	iRessyasyubetsuIndexA と iRessyasyubetsuIndexB は、
	 *	異なる値でなくてはなりません。
	 * @return 
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-1 ;	//	列車種別Indexが不正です。
	 */
	int swapRessyasyubetsu( int iRessyasyubetsuIndexA ,
		int iRessyasyubetsuIndexB ) ;
	
	///@}
	// ********************************
	///@name 包含-CentDedDia
	// ********************************
	///@{
	/**
	 * @return 
	 *	『ダイヤ』 ( CentDedDia ) オブジェクトのコンテナへの
	 *	インターフェースを返します。
	 *	このインターフェースは、 CentDedDia オブジェクトを路線に
	 *	追加・削除するためのインターフェースです。
	 */
	CentDedDiaCont* getCentDedDiaCont(){	return &m_CentDedDiaCont ;};
	const CentDedDiaCont* getCentDedDiaCont()const{	return &m_CentDedDiaCont ;};

	/**
	 * @return 
	 *	『ダイヤ』 ( CentDedDia ) オブジェクトのコンテナへの
	 *	インターフェースを返します。
	 *	このインターフェースは、 CentDedDia オブジェクトへのポインタに
	 *	アクセスするためのインターフェースです。
	 */
	IfContGet<CentDedDia*>* getCentDedDiaContGet()
	{
		return m_CentDedDiaCont.getIfContGet() ;
	};
	const IfContGet<CentDedDia*>* getCentDedDiaContGet()const
	{
		return m_CentDedDiaCont.getIfContGet() ;
	};
	///@}
	
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
	 *	すべての属性を破棄します。
	 */
	void clear() ;
	///@}
};





#endif /*CentDedRosen_h*/
