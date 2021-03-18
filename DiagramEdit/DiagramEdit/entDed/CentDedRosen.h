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

#include "CentDed.h"
#include "CentDedEkiCont.h"
#include "CentDedRessyasyubetsuCont.h"
#include "CentDedDiaCont.h"
#include "NsMu/CaMup_vector.h"

namespace entDed{

// ****************************************************************
//	CentDedRosen
// ****************************************************************
/**
@brief
  DiagramEdit の、『路線』１つを表します。
  このクラスは、 DiagramEdit のエンティティクラス CentDed... の
ルートとなるクラスです。以下のクラスのオブジェクトを包含します。
	
	- 『駅』 ( CentDedEki ) ： 0 以上複数のオブジェクトを包含します。
	- 『列車種別』 ( CentDedRessyasyubetsu ) ： 1 以上複数のオブジェクトを
	包含します。
	- 『ダイヤ』 ( CentDedDia ) ： 0 以上複数のオブジェクトを包含します。
	『ダイヤ』 ( CentDedDia ) は、『列車』 ( CentDedRessya ) を０以上複数
	包含しています。さらに、『列車』は、『駅時刻』 ( CentDedEkiJikoku ) を
	『駅』の数だけ包含しています。

  this に包含される CentDedDia は、 CentDedDia::m_strName が一意でなくては
なりません。同名の CentDedDia を insertCentDedDia() で登録しようとすると、
エラーとなります。

  『駅』オブジェクトを追加・削除した場合、this は包含している
すべての『列車』 ( CentDedRessya ) に対して、
『駅時刻』 ( CentDedEkiJikoku )オブジェクトの追加・削除を行います。

  『列車種別』オブジェクトを削除した場合、 this は包含しているすべての
『列車』オブジェクトのうち、削除された『列車種別Index』を持つ『列車』
に対して、『列車種別Index』を0(既定の列車種別)に変更します。

  『駅Index』は、路線の下り列車の始発駅（上り列車の終着駅）が 0 ・ 
下り列車の終着駅（上り列車の始発駅） が ( 駅の数 - 1 ) となります。

制約
 -------------------------------- 

○　ダイヤの起点時刻(m_jikokuKitenJikoku) は、NULLを指定することはできません。


操作のエラー検査・修正
 -------------------------------- 


制約に合うように属性を修正(adjust)
 -------------------------------- 



*/
class CentDedRosen
{

protected:
	// ********************************
	//	インナータイプ
	// ********************************
	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedEkiCont
	// ----------------------------------------------------------------
	/**
	@brief
	  『路線』オブジェクトに包含される、
		『駅』(CentDedEki) オブジェクトのコンテナです。
	
	  『駅』オブジェクトを追加・削除した場合、
		this は関連する『路線』が包含している
		すべての『列車』 ( CentDedRessya ) に対して、
		『駅時刻』 ( CentDedEkiJikoku )オブジェクトの追加・削除を行います。
		
	 */
	class CXCentDedEkiCont : public CentDedEkiCont
	{
	public:
		// ********************************
		//	インナータイプ
		// ********************************
		typedef CentDedEkiCont	super ;
	public:
		// ********************************
		//	コンストラクタ
		// ********************************


	public:
		// ********************************
		///@name	Mui
		// ********************************
		///@{
		/**
		 	コンテナ内の、インデクスで指定された場所に、
		 	要素を追加します。
		 @param element [in]
		 	要素を指定してください。
		 @param iIndex [in]
		 	０から始まるインデクスを指定してください。
		 	範囲は０以上 size() 以下です。
		 	０は、先頭・size()なら末尾への追加になります。
			但し、INT_MAX は、末尾を指定したものとみなします。
		 @return
		 	0以上は成功、負の数はエラーです
		
			<H4>
			【オーバライド】
			</H4>
			CentDedEki オブジェクトを追加するのに加えて、
			m_pCentDedRosen が包含している全ての列車に対して、
			駅時刻の追加を行います。
		 */
		virtual int insert( const CentDedEki& element , int iIndex = INT_MAX );
		/**
		 	コンテナ内の、インデクスで指定された場所の
		 	要素を削除します。
		 @param iIndex [in]
		 	０から始まるインデクスを指定してください。
		 	範囲は０以上 size() 未満です。
		 	但し、INT_MAX は、末尾を指定したものとみなします。
		 @param iSize [in]
		 	削除する要素の数を指定してください。
		 	但し、INT_MAX は、 iIndex から末尾までを表します。
		 @attention
			iIndex と iSize の両方を INT_MAX にすることはできません。
		 @return
		 	0以上は成功、負の数はエラーです
		
			<H4>
			【オーバライド】
			</H4>
			CentDedEki オブジェクトを削除するのに加えて、
			m_pCentDedRosen が包含している全ての列車に対して、
			駅時刻の削除を行います。
		 */
		virtual int erase( int iIndex  , int iSize = 1 ) ;
		///@}
		// ********************************
		///@name CentDedEkiCont-関連
		// ********************************
		///@{
		/**
		@return
			外側の CentDedRosen オブジェクトを返します。
		*/
		CentDedRosen* getRosen();
		/**
		@return
			外側の CentDedRosen オブジェクトを返します。
		*/
		const CentDedRosen* getRosen()const ;
		///@}
	} ;
	friend class CXCentDedEkiCont ;

	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedRessyasyubetsuCont
	// ----------------------------------------------------------------
	/**
	@brief
	  『路線』オブジェクトに包含される、
		『列車種別』(CentDedRessyasyubetsu) オブジェクトのコンテナです。
		
		通常の列車種別コンテナに加えて、以下のような特性が存在します。
		
		
	１．  『列車種別』オブジェクトを追加・削除した場合、
		this は関連する『路線』が包含している
		すべての『列車』 ( CentDedRessya ) に対して、
		『列車種別Index』 ( CentDedRessya::m_iRessyasyubetsuIndex )
		の修正を行います。
	
	２．  『列車種別』オブジェクトを削除した場合、その列車種別を持つ列車
	の列車種別インデクスは、0に変更する。
	 */
	class CXCentDedRessyasyubetsuCont : public CentDedRessyasyubetsuCont
	{
	public:
		// ********************************
		//	インナータイプ
		// ********************************
		typedef CentDedRessyasyubetsuCont	super ;
	public:
		// ********************************
		//	コンストラクタ
		// ********************************
		CXCentDedRessyasyubetsuCont() ;
	public:
		// ********************************
		///@name	Mui
		// ********************************
		///@{
		/*kyuusi
		 	コンテナ内の、インデクスで指定された場所に、
		 	要素を追加します。
		 @param element [in]
		 	要素を指定してください。
		 @param iIndex [in]
		 	０から始まるインデクスを指定してください。
		 	範囲は０以上 size() 以下です。
		 	０は、先頭・size()なら末尾への追加になります。
			但し、INT_MAX は、末尾を指定したものとみなします。
		 @return
		 	0以上は成功、負の数はエラーです
			-	-1 ;	//	iIndex が不正です。
			-	-11 ;	//	nameが空の CentDedRessyasyubetsuを上書きするとエラー。		
			<H4>
			【オーバライド】
			</H4>
			CentDedRessyasyubetsu オブジェクトを追加するのに加えて、
			すべての『列車』 ( CentDedRessya ) に対して、
			『列車種別Index』 ( CentDedRessya::m_iRessyasyubetsuIndex )
			の修正を行います。
		virtual int insert( const CentDedRessyasyubetsu& element , int iIndex = INT_MAX );
		 */
		/*kyuusi
		 	コンテナ内の、インデクスで指定された場所の
		 	要素を削除します。
		 @param iIndex [in]
		 	０から始まるインデクスを指定してください。
		 	範囲は０以上 size() 未満です。
		 	但し、INT_MAX は、末尾を指定したものとみなします。
		 @param iSize [in]
		 	削除する要素の数を指定してください。
		 	但し、INT_MAX は、 iIndex から末尾までを表します。
		 @attention
			iIndex と iSize の両方を INT_MAX にすることはできません。
		 @return
		 	0以上は成功、負の数はエラーです
			-	-1 ;	//	iIndex が不正です。
			-	-11 ;	//	削除対象の列車種別の列車が存在します。
		
			<H4>
			【オーバライド】
			</H4>
			CentDedRessyasyubetsu オブジェクトを削除するのに加えて、
			すべての『列車』 ( CentDedRessya ) に対して、
			『列車種別Index』 ( CentDedRessya::m_iRessyasyubetsuIndex )
			の修正を行います。
		virtual int erase( int iIndex  , int iSize = 1 ) ;
		 */
		///@}

		// ********************************
		///@name CentDedRessyasyubetsuCont-関連
		// ********************************
		///@{
		/**
		@return
			外側の CentDedRosen オブジェクトを返します。
		*/
		virtual CentDedRosen* getRosen();
		/**
		@return
			外側の CentDedRosen オブジェクトを返します。
		*/
		virtual const CentDedRosen* getRosen()const ;
		///@}
	};
	friend class CXCentDedRessyasyubetsuCont ;

	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedDiaCont
	// ----------------------------------------------------------------
	/**
	@brief
	  『路線』オブジェクトに包含される、
		『ダイヤ』(CentDedDia) オブジェクトのコンテナです。
		
	 */
	class CXCentDedDiaCont : public CentDedDiaCont
	{
		typedef CentDedDiaCont super ;
	 public:
		// ********************************
		//	コンストラクタ
		// ********************************

	 public:
		// ********************************
		///@name CentDedDiaCont-関連
		// ********************************
		///@{
		/**
		@return
			このコンテナが CentDedRosen に包含されている場合は、
			CentDedRosen のアドレス。
			そうでないならNULL。
		*/
		virtual CentDedRosen* getRosen();
		/**
		@return
			このコンテナが CentDedRosen に包含されている場合は、
			CentDedRosen のアドレス。
			そうでないならNULL。
		*/
		virtual const CentDedRosen* getRosen()const ;
		
		///@}
	};
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		路線の名称です。
		（例） "近鉄大阪線" など
	 */
	std::string	m_strName ;
	
	/**
		ダイヤの起点時刻です。
		この時刻は、ダイヤグラムの左端の時刻となります。
	
		既定値は 00:00:00 です。
	 @attention
		この値は、 Null 状態にしないでください。
	 */
	CdDedJikoku	m_jikokuKitenJikoku ;
	
	/**
		ダイヤグラムの既定の駅間幅。

		列車設定のない駅間の、ダイヤグラムビュー上での
		縦方向の幅を『ダイヤグラムエンティティY座標』単位(秒)で指定します。
	
		既定値は 60 です。
	*/
	int	m_iDiagramDgrYZahyouKyoriDefault ;
	
	/**
		コメント。
		CDedCommentDoc,CDedCommentView で編集します。
	 */
	std::string	m_strComment ;
	
	///@}
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{

	/**
		この『路線』にある『駅』 ( CentDedEki ) を保持します。
	
		このコンテナ内の CentDedEki オブジェクトの
		生成・破棄の責務はthisにあります。
	
		初期状態では、要素数は 0 となります。
	 */
	CXCentDedEkiCont	m_CentDedEkiCont ;
	
	/**
		この『路線』にある『列車種別』 ( CentDedRessyasyubetsu ) を保持します。
	
		このコンテナ内の CentDedRessyasyubetsu オブジェクトの
		生成・破棄の責務はthisにあります。
	
		初期状態では、要素数は 1 となります。
		『列車種別』は、少なくとも一つは存在しなくてはなりません。
	 */
	CXCentDedRessyasyubetsuCont	m_CentDedRessyasyubetsuCont ;
	
	/**
		この『路線』にある『ダイヤ』 ( CentDedDia ) を保持します。
	
		このコンテナ内の CentDedDia オブジェクトの
		生成・破棄の責務はthisにあります。
	
	 @attention
		this は、 CentDedDia::m_strName を限定子として扱います。
		このコンテナ内の CentDedDia は、 CentDedDia::m_strName が
		一意でなくてはなりません。
	
		初期状態では、要素数は 0 となります。
	 */
	CXCentDedDiaCont	m_CentDedDiaCont ;
	///@}
	
 public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
		初期状態では、列車種別の要素数は 1 となります。
		『列車種別』は、少なくとも一つは存在しなくてはなりません。
	 */
	CentDedRosen() ;
	
	CentDedRosen( const CentDedRosen& value );
	CentDedRosen& operator=( const CentDedRosen& value );


	
// ********************************
//	CentDedRosen
// ********************************
 public:
	// ********************************
	///@name CentDedRosen-属性
	// ********************************
	///@{
	/** @see m_strName */
	std::string	getName()const{	return m_strName ;};
	/** @see m_strName */
	CentDedRosen& setName( const std::string& value )
	{	m_strName =value ; return *this ; } ;
	/** @see m_jikokuKitenJikoku */
	CdDedJikoku	getKitenJikoku()const{	return m_jikokuKitenJikoku ;};
	/** @see m_jikokuKitenJikoku */
	CentDedRosen& setKitenJikoku( const CdDedJikoku& value )
	{	m_jikokuKitenJikoku = value ; return *this ; } ;
	/** @see m_iDiagramDgrYZahyouKyoriDefault */
	int	getDiagramDgrYZahyouKyoriDefault()const
	{	return m_iDiagramDgrYZahyouKyoriDefault ;};
	/** @see m_iDiagramDgrYZahyouKyoriDefault */
	CentDedRosen& setDiagramDgrYZahyouKyoriDefault( int value )
	{	m_iDiagramDgrYZahyouKyoriDefault = value ; return *this ;};
	/** @see m_strComment */
	std::string	getComment()const{return m_strComment ;};
	/** @see m_strComment */
	CentDedRosen& setComment( const std::string& value )
	{	m_strComment = value ;	return *this ; 	} ;
	///@}
	
	// ********************************
	///@name CentDedRosen-包含
	// ********************************
	///@{
	/**
	 @return 
		『駅』 ( CentDedEki ) オブジェクトのコンテナへの
		インターフェースを返します。
		このインターフェースは、 CentDedEki オブジェクトを路線に
		追加・削除するためのインターフェースです。
	@attention
		このコンテナに対して、代入演算子を使用してはいけません。
		必ず、コンテナのメソッドを使って要素の追加・削除を行ってください。
		他の CentDedEkiCont の内容をCentDedRosen にコピーする場合は、
		CaMui::insert() を使用することもできます。
	@code
		CaMui<CentDedEki>	aCaCont( aCentDedRosen().getCentDedEkiCont() ) ; 
		aCaCont.insert( &aCentDedEkiCont ) ;
	@endcode
	*/
	CentDedEkiCont* getCentDedEkiCont(){	return &m_CentDedEkiCont ; } ;
	/** @see m_CentDedEkiCont */
	const CentDedEkiCont* getCentDedEkiCont()const{	return &m_CentDedEkiCont ; } ;

	/**
	@return 
		『列車種別』 ( CentDedRessyasyubetsu ) オブジェクトのコンテナへの
		インターフェースを返します。
		このインターフェースは、 CentDedRessyasyubetsu オブジェクトを路線に
		追加・削除するためのインターフェースです。
	@attention
		このコンテナに対して、代入演算子を使用してはいけません。
		必ず、コンテナのメソッドを使って要素の追加・削除を行ってください。
		他の CentDedRessyasyubetsuCont の内容をCentDedRosen にコピーする場合は、
		CaMui::insert() を使用することもできます。
	@code
			CaMui<CentDedRessyasyubetsu>	aCaCont( pCentDedRosen->getCentDedRessyasyubetsuCont() ) ; 
			aCaCont.insert( &aCentDedRessyasyubetsuCont ) ;
	@endcode
	 */
	CentDedRessyasyubetsuCont* getCentDedRessyasyubetsuCont()
	{
		return &m_CentDedRessyasyubetsuCont ; 
	} ;
	/** @see m_CentDedRessyasyubetsuCont */
	const CentDedRessyasyubetsuCont* getCentDedRessyasyubetsuCont()const
	{
		return &m_CentDedRessyasyubetsuCont ; 
	} ;
	
	/**
	 @return 
		『ダイヤ』 ( CentDedDia ) オブジェクトのコンテナへの
		インターフェースを返します。
		このインターフェースは、 CentDedDia オブジェクトを路線に
		追加・削除するためのインターフェースです。
	@attention
		このコンテナに対して、代入演算子を使用してはいけません。
		必ず、コンテナのメソッドを使って要素の追加・削除を行ってください。
		他の CentDedRessyasyubetsuCont の内容をCentDedRosen にコピーする場合は、
		CaMui::insert() を使用することもできます。
	@code
			CaMui<CentDedDia>	aCaCont( pCentDedRosen->getCentDedDiaCont() ) ; 
			aCaCont.insert( &aCentDedDia ) ;
	@endcode
	 */
	CentDedDiaCont* getCentDedDiaCont(){	return &m_CentDedDiaCont ;};
	/** @see m_CentDedDiaCont */
	const CentDedDiaCont* getCentDedDiaCont()const{	return &m_CentDedDiaCont ;};

	///@}
	
	// ********************************
	///@name CentDedRosen-操作
	// ********************************
	///@{
	/**
		この路線ファイルに、他の路線ファイルを組入れます。
	@param rosenToAdd [in]
		追加する路線を指定してください。
	@param iEkiIndexToInsert [in]
		路線ファイルを組入れる駅Indexを指定してください。

	(1)　OuDiaは、『追加する路線ファイル』のすべての駅を、
	『現在編集している路線ファイル』の『組入れ先』に追加します。

	(1.1)　『現在編集している路線ファイル』の組入れ先駅と
	『追加する路線ファイル』の起点・駅が同じである場合、
	OuDiaはこの2駅を同一駅とみなします。
	  『追加する路線ファイル』の終点についても、同様です。

	(2)　OuDiaは、『追加する路線ファイル』のすべての列車種別を
	『現在編集している路線ファイル』に追加します。
	  但し、同名の列車種別が『現在編集している路線ファイル』に
	  すでに存在している場合は、OuDiaはその列車種別を追加しません。

	(3)　OuDiaは、『追加する路線ファイル』のすべてのダイヤを
	『現在編集している路線ファイル』に追加します。
	  但し、同名のダイヤが『現在編集している路線ファイル』に
	  すでに存在している場合は、OuDiaはそのダイヤを追加しません。

	(4)　OuDiaは、『追加する路線ファイル』のすべての
	ダイヤのすべての列車を、『現在編集している路線ファイル』の、
	同名のダイヤに追加します。

	(5)　OuDiaは、『追加する路線ファイル』のコメントを、
	『現在編集している路線ファイル』のコメントの末尾に追加します。
	*/
	void insert( const CentDedRosen& rosenToAdd , int iEkiIndexToInsert ) ;

	/**
		この路線の一部駅間の路線を作成します。
	@param iEkiIndex [in]
		作成する路線の起点駅とする駅Indexを指定してください。
	@param iEkiCount [in]
		作成する路線の駅数を指定してください。
	@return
		生成された路線を返します。

	(1)　新しく生成される路線ファイルは、
	『現在編集している路線ファイル』から、
	指定された範囲以外の駅を削除したものになります。

	(2)　新しく生成される路線が運転区間に含まれない列車は、削除します。
	*/
	CentDedRosen createSubRosen( 
		int iEkiIndex , int iEkiCount )const ;

	/**
		全ダイヤ・全列車の、指定の駅Indexの駅時刻を、
		駅時刻形式・始発・終着に合わせて変更します。

		変更内容は、 CentDedEkiJikoku::adjustByEkijikokukeisiki()
		を参照してください。

	@see CentDedEkiJikoku::adjustByEkijikokukeisiki 

	@param iEkiIndex [in]
		駅Indexを指定してください。
	*/
	void adjustByEkijikokukeisiki( int iEkiIndex ) ;

	/**
	路線ファイルを反転します。

	(1)　路線ファイルの駅の順序の並び順を逆にします。

	(2)　駅のプロパティは、以下の変換を行います。

	(2.1)駅名はそのまま

	(2.2)駅時刻形式
		- 下り着時刻→上り着時刻
		- 上り着時刻→下り着時刻

	(2.3)境界線
		- 駅の順序を変更後、起点側(駅Indexの小さい側)に1駅シフトする。
		- 新しい下り側終点(駅Indexの最も大きい駅)の境界線は無しにする。

	(2.4)ダイヤグラム列車情報
	  下りの内容と上りの内容を入れ替えます。

	(3)路線ファイルに含まれるすべての列車の駅時刻の並び順を逆にします。
	*/
	void invert();

	/**
		２つの『列車種別』のIndexを入れ替えます。
	
		指定の列車種別Indexを持つすべての列車のIndexも、
		入れ替わります。
		
	 @param iRessyasyubetsuIndexA , iRessyasyubetsuIndexB [in]
		『列車種別Index』を指定してください。
		範囲は、 0 以上 列車種別の数未満です。
		INT_MAX は、末尾の列車種別を指定したものとみなします。
		iRessyasyubetsuIndexA と iRessyasyubetsuIndexB は、
		異なる値でなくてはなりません。
	 @return 
		成功したら 0 以上、エラーなら負の数です。
		-1 ;	//	列車種別Indexが不正です。
	 */
	int swapRessyasyubetsu( int iRessyasyubetsuIndexA ,
		int iRessyasyubetsuIndexB ) ;
	

	/**
		すべての属性を破棄します。
	 */
	void clear() ;
	///@}
public:
	// ********************************
	///@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
	///@{
	/**
		m_CentDedEkiCont に CentDedEki が追加された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiIndex
		追加された CentDedEki のインデクス。
	*/
	virtual void onEkiInsert( int iEkiIndex ); 
	/**
		m_CentDedEkiCont から CentDedEki が削除された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiIndex
		削除された CentDedEki のインデクス。
	*/
	virtual void onEkiErase( int iEkiIndex  ); 
	/**
		CentDedEkiTrackCont に CentDedEkiTrack が追加された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiIndex
		CentDedEkiTrackCont が追加された CentDedEki の駅Index。
	@param iEkiTrackIndex
		追加された CentDedEkiTrack のインデクス。
	*/
	virtual void onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex ); 
	/**
		CentDedEkiTrackCont から CentDedEkiTrack が削除された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiIndex
		CentDedEkiTrackCont が削除された CentDedEki の駅Index。
	@param iEkiTrackIndex
		削除された CentDedEkiTrack の先頭のインデクス。
	*/
	virtual void onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex ); 

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




#endif /*CentDedRosen_h*/
