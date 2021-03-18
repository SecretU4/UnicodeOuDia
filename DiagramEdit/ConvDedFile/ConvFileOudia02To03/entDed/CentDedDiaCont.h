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
//	CentDedDiaCont.h
// ****************************************************************
*/
#ifndef  CentDedDiaCont_h
#define  CentDedDiaCont_h
/** @file */

#include "Cont/CaContFilter.h"
#include "CentDedDia.h"

class CentDedEkiCont ;

// ****************************************************************
//	CentDedDiaCont
// ****************************************************************
/**
 * @brief
 *	CentDedDia オブジェクトのコンテナクラスです。
 *	
 *	このクラス自体は、 IfCont< CentDedDia > インターフェースを
 *	サポートします。このインターフェースにより、 CentDedDia オブジェクトを
 *	追加・削除することができます。
 *
 *	また、 getIfContGet() メソッドにより、
 *	IfCont< CentDedDia* > インターフェースを取得することができます。
 *	このインターフェースにより、コンテナ内の CentDedDia オブジェクトに
 *	直接アクセス（メソッド呼出）を行うことができます。
 *
 * @attention
 *	this の get() メソッドは、ダイヤオブジェクトのコピーを返します。
 *	get() メソッドで返されたオブジェクトに対して、
 *	CentDedDia オブジェクトを更新するメソッドを呼び出しても、
 *	コンテナ内のダイヤオブジェクトを更新することはできません。\n
 *	コンテナ内のダイヤオブジェクトのメソッドを呼び出す場合は、
 *	getIfContGet() で IfContGet<CentDedDia*>* を取得してから、
 *	そのインターフェース経由で CentDedDia* を取得し、そのポインタに
 *	メソッドを呼び出してください。
 *	
 *	このコンテナの set() ・ insert() は、指定された CentDedDia オブジェクト
 *	をコピーコンストラクタでコピーした上で、コンテナに保持します。
 *	set()・ insert() で指定したオブジェクトは、関数終了後は破棄しても
 *	かまいません。
 *
 *	このオブジェクトが保持する CentDedDia は、『駅の数』がすべて
 *	同じでなくてはなりません。
 *	
 * @attention
 *	 CentDedDia::m_strName 属性は、限定子となります。
 *	コンテナ内に同じ CentDedDia::m_strName を持つオブジェクトを
 *	複数格納することはできません。
 */
class CentDedDiaCont : public CaContFilter< CentDedDia , CentDedDia* >
{
// ********************************
//	インナータイプ
// ********************************
public:
	typedef CaContFilter< CentDedDia , CentDedDia* >	super ;
// ********************************
///@name 属性
// ********************************
///@{
private:
	/**
	 *	このコンテナに含まれる列車の『駅時刻』の数（ダイヤに含まれる駅の数）。
	 *
	 *	この値は、列車が属している CentDedRosen オブジェクトの
	 *	 CentDedEki の数に等しくなります。
	 *
	 *	この値は、コンテナに要素 (  CentDedDia ) オブジェクトを追加
	 *	する場合に必要になります。
	 */
	int m_iEkiCount ;
	
	/**
	 *	このコンテナに含まれる列車の『列車種別』の数。
	 *
	 *	この値は、列車が属している CentDedRosen オブジェクトの
	 *	 CentDedRessyasyubetsu の数に等しくなります。
	 *
	 *	この値は、コンテナに要素 ( CentDedDia ) オブジェクトを追加
	 *	する場合に必要になります。
	 */
	int m_iRessyasyubetsuCount ;
	
///@}

// --------------------------------
///@name CaContFilter-オーバライド可能な仮想関数
// --------------------------------
///@{
 protected:
	/**
	 *	  this は、操作対象のコンテナ m_pAdaptee に対して要素を追加
	 *	するときに、この関数を呼び出して、  ElementType1 の値 value を、
	 *	 ElementType2 に変換します。
	 *
	 *	onSet() 呼び出しと、 onErase() 呼び出しは対になっています。
	 *	 onSet() である値を返した場合、その要素が m_pAdaptee から
	 *	取り除かれるときに、必ず onSet() で返した値を引数として
	 *	 onErase() が呼び出されます。
	 *	
	 *	@param value [in] (const ElementType1&)
	 *	  変換するべき値を指定してください。
	 *	
	 *	@param piResult [out]
	 *	  この関数は、値 value の変換に成功したときはこの値を 0 以上、
	 *	失敗したときは負の数にします。
	 *	\n関数終了後にこの値が負の数である場合、 this は要素を
	 *	コンテナに格納しません。この場合、set() ・ insert() は
	 *	失敗となり、 *piResult が set() ・ insert() の戻り値となります。
	 *	
	 *	@return (ElementType2)
	 *	  value を変換した結果を返します。但し、変換に失敗し、
	 *	 *piResult が負の数である場合は、この戻り値には意味がありません。
	 *
	 *	
	 *	<H4>
	 *	【オーバライド】
	 *	</H4>
	 *	value のコピーを new で生成して、そのポインタを返します。
	 *	但し、コピー後のインスタンスの駅数は、 this の  m_iEkiCount に
	 *	合わせます。
	 */
	virtual adaptee_value_type onSet( const value_type& value , int* piResult ) ;
	
	/**
	 *	  get() メソッドは、操作対象のコンテナ m_pAdaptee から取得したあと
	 *	この関数を呼び出して、  ElementType2 の値 value を、
	 *	 ElementType1 に変換します。
	 *	
	 *	@param value [in] (const ElementType2&)
	 *	  変換するべき値を指定してください。
	 *	
	 *	@return (ElementType1)
	 *	  value を変換した結果を返します。
	 *	
	 *	<H4>
	 *	【オーバライド】
	 *	</H4>
	 *	  ElementType2 の値を、 ElementType1 に変換する処理を実装
	 *	してください。変換結果の値は戻り値としてください。
	 */
	virtual value_type onGet( const adaptee_value_type& value )const ;
	
	/**
	 *	  this は、操作対象のコンテナ m_pAdaptee から要素を取り除く直前に、
	 *	この関数を呼び出します。
	 *
	 *
	 *	onSet() 呼び出しと、 onErase() 呼び出しは対になっています。
	 *	 onSet() である値を返した場合、その要素が m_pAdaptee から
	 *	取り除かれるときに、必ず onSet() で返した値を引数として
	 *	 onErase() が呼び出されます。
	 *	
	 *	@param value [in] (const ElementType2&)
	 *	  操作対象のコンテナ m_pAdaptee から取り除く要素を指定してください。
	 *
	 *	<H4>
	 *	【オーバライド】
	 *	</H4>
	 *	  要素を delete します。
	 */
	virtual void onErase( const adaptee_value_type& value ) ;
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param iEkiCount [in]]
	 *	駅の数。\n
	 * @param iRessyasyubetsuCount [in]
	 *	このコンテナに含まれる列車の『列車種別』の数。
	 *	この値は、列車が属している CentDedRosen オブジェクトの
	 *	 CentDedRessyasyubetsu の数に等しくなります。
	 */
	CentDedDiaCont( int iEkiCount , int iRessyasyubetsuCount ) ;

	CentDedDiaCont( const CentDedDiaCont& value );
	
	/**
	 *	このクラスへの代入を行いますが、
	 *	this の『駅』の数 ( m_iEkiCount ) は変更しません。
	 *
	 *	this が包含する『列車』( CentDedRessya )  のコピーには、
	 *	CentDedRessya& operator=( const CentDedRessya& value ) 
	 *	を使います。
	 */
	CentDedDiaCont& operator=( const CentDedDiaCont& value );

	virtual ~CentDedDiaCont();
// ********************************
///@name IfCont
// ********************************
///@{
 public:
	/**
	 * 	コンテナ内の、インデクスで指定された場所に、
	 * 	要素を上書きします。
	 * <H4>
	 * 【オーバライド】
	 * </H4>
	 *	element のコピーを new で生成してから、それを
	 *	操作対象コンテナ m_pAdaptee に格納します。
	 *	\n m_pAdaptee に、同名のダイヤオブジェクトが存在する場合は、
	 *	メソッドは失敗します。
	 *
	 * @param element [in]
	 * 	要素を指定してください。
	 * @param iIndex [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 未満です。
	 *	但し、INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	0以上は成功、負の数はエラーです
	 *	-	-1 ;	//	iIndex が不正です。
	 *	-	-2 ;	//	element にはダイヤ名が指定されていません。
	 *	-	-3 ;	//	すでに同名のダイヤが存在します。
	 */
	virtual int set( const CentDedDia& element , int iIndex ) ;

	/**
	 * 	コンテナ内の、インデクスで指定された場所に、
	 * 	要素を追加します。
	 * <H4>
	 * 【オーバライド】
	 * </H4>
	 *	element のコピーを new で生成してから、それを
	 *	操作対象コンテナ m_pAdaptee に格納します。
	 *	\n m_pAdaptee に、同名のダイヤオブジェクトが存在する場合は、
	 *	メソッドは失敗します。
	 *
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
	 *	-	-1 ;	//	インデクスが不正です。
	 *	-	-2 ;	//	element にはダイヤ名が指定されていません。
	 *	-	-3 ;	//	すでに同名のダイヤが存在します。
	 */
	virtual int insert( const CentDedDia& element , int iIndex = INT_MAX ) ;
///@}
	
// ********************************
//	CentDedDiaCont
// ********************************
 public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	virtual int getEkiCount()const ;
	virtual int getRessyasyubetsuCount()const ;
	///@}
	// ********************************
	///@name CentDedDiaCont-操作
	// ********************************
	///@{
	/**
	 * @return 
	 *	コンテナ内のダイヤオブジェクト CentDedDia へのポインタに
	 *	アクセスするための IfContGet<CentDedDia*>* を返します。
	 */
	IfContGet<CentDedDia*>* getIfContGet(){	return getAdaptee() ;	};
	const IfContGet<CentDedDia*>* getIfContGet()const{	return getAdaptee() ;	};

	/**
	 *	指定のダイヤ名を持つ
	 *	『ダイヤ』 ( CentDedDia ) オブジェクトの、
	 *	インデクスを調べます。
	 * @param strName [in]
	 *	『ダイヤ名』を指定してください。
	 * @return 
	 *	成功したら 0 以上のインデクス、エラーなら負の数です。
	 *	-	-1 ;	//	オブジェクトがみつかりません。
	 */
	int findCentDedDiaByName( const string& strName )const ;
	///@}
	// ********************************
	///@name CentDedDiaCont-操作 駅の増減
	// ********************************
	///@{
	/**
	 *	このコンテナに含まれるすべての
	 *	『ダイヤ』 ( CentDedDia )に対し、
	 *	『駅』オブジェクトの属性の変更を通知します。
	 *	
	 *	この関数は、『始発駅・終着駅の駅時刻形式変更に伴う、着時刻・発時刻の修正』
	 *	を行わせます。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Index』で指定してください。
	 *	範囲は 0 以上 m_iEkiCount 以下です。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 */
	int onSetCentDedEki( const CentDedEkiCont* pCentDedEkiCont , int iEkiIndex ) ;

	/**
	 *	このコンテナに含まれるすべての
	 *	『ダイヤ』 ( CentDedDia )に対し、
	 *	『駅時刻』オブジェクトを、指定の位置に挿入します。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Index』で指定してください。
	 *	範囲は 0 以上 m_iEkiCount 以下です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 */
	int insertCentDedEkiJikoku(	int iEkiIndex = INT_MAX ) ;
	
	/**
	 *	この『ダイヤコンテナ』に含まれるすべての
	 *	『ダイヤ』 ( CentDedDia )に対し、
	 *	『駅時刻』オブジェクトを、指定の位置から削除します。
	 * @param iEkiOrder [in]
	 *	オブジェクトを挿入する位置を『駅Index』で指定してください。
	 *	範囲は 0 以上 m_iEkiCount 未満です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	インデクスが不正です。
	 */
	int eraseCentDedEkiJikoku( int iEkiIndex = INT_MAX ) ;

	/**
	 *	『列車種別』の追加に伴い、
	 *	この『列車コンテナ』に含まれるすべての
	 *	『列車』 ( CentDedRessya ) の『列車種別Index』を修正します。
	 *
	 *	この『列車コンテナ』に含まれるすべての
	 *	『列車』 ( CentDedRessya ) のうち、
	 *	引数 iRessyasyubetsuIndex 以上の 『列車種別Index』を持つ
	 *	『列車』 ( CentDedRessya ) の『列車種別Index』を 1 加算します。
	 *
	 *	また、同時に this の m_iRessyasyubetsuCount も 1 加算します。
	 *
	 * @param iRessyasyubetsuIndex [in]
	 *	列車種別の追加位置を指定してください。
	 *	範囲は 0 以上 m_iRessyasyubetsuCount 以下です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	インデクスが不正です。
	 */
	int insertRessyasyubetsuIndex( int iRessyasyubetsuIndex = INT_MAX ) ;
	
	/**
	 *	『列車種別』の削除に伴い、
	 *	この『列車コンテナ』に含まれるすべての
	 *	『列車』 ( CentDedRessya ) の『列車種別Index』を修正します。
	 *
	 *	この『列車コンテナ』に含まれるすべての
	 *	『列車』 ( CentDedRessya ) のうち、
	 *	引数 iRessyasyubetsuIndex より大きい 『列車種別Index』を持つ
	 *	『列車』 ( CentDedRessya ) の『列車種別Index』を 1 減算します。
	 *
	 *	また、同時に this の m_iRessyasyubetsuCount も 1 加算します。
	 *
	 * @param iRessyasyubetsuIndex [in]
	 *	削除する列車種別Indexを指定してください。
	 *	範囲は 0 以上 m_iRessyasyubetsuCount 未満です。
	 *	INT_MAX を指定すると、末尾を指定したものとみなします。
	 * @return
	 *	成功したら 0 以上、エラーなら負の数です。
	 *	-	-1 ;	//	インデクスが不正です。
	 *	-	-3 ;	//	『列車種別』が iRessyasyubtsuIndex の列車が存在します。
	 */
	int eraseRessyasyubetsuIndex( int iRessyasyubetsuIndex  = INT_MAX ) ;

	/**
	 *	このコンテナに、指定された『列車種別』の列車があるか否かを調べます。
	 * @param iRessyasyubetsuIndex [in]
	 *	『列車種別Index』を指定してください。
	 *	範囲は、 0 以上 列車種別の数未満です。
	 *	INT_MAX は、末尾の列車種別を指定したものとみなします。
	 * @param piDiaIndex [out]
	 *	この関数はこの変数に、『列車種別』の列車が見つかった
	 *	ダイヤのインデクスを書き込みます。
	 *	不要なら NULL でもかまいません。
	 * @param peRessyahoukou [out]
	 *	この関数はこの変数に、『列車種別』の列車が見つかった
	 *	ダイヤの列車方向を書き込みます。
	 *	不要なら NULL でもかまいません。
	 * @param piRessyaIndex [out]
	 *	この関数はこの変数に、『列車種別』の列車が見つかった
	 *	列車Index を書き込みます。
	 *	不要なら NULL でもかまいません。
	 * @return 
	 *	-	1; //	指定の列車種別の列車が存在します。
	 *	-	0; //	指定の列車種別の列車は存在しません。
	 *	-	-1 ;	//	インデクスが不正
	 */
	int isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piDiaIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) ;

	///@}

	
};






#endif /*CentDedDiaCont_h*/
