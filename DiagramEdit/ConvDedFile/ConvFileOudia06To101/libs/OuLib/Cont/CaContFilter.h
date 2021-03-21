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
//	CaContFilter.h
// ****************************************************************
*/
/** @file */
#ifndef  CaContFiler_h
#define  CaContFiler_h
#include <stddef.h>
#include "./IfCont.h"
// ****************************************************************
//	CaContFilter
// ****************************************************************
/**
 * @brief
 *	  アダプタクラスです。
 *	  "IfCont<ElementType2>" インターフェースをサポートする
 *	コンテナに対して、 ElementType1 型の値を変換した上で設定・
 *	取得することができます。
 *	
 *	  このクラスは抽象クラスであり、 "IfCont<ElementType1>" 
 *	インターフェースをサポートします。操作対象オブジェクトは、 
 *	"IfCont<ElementType2>" インターフェースをサポートします。
 *	また、オーバライド可能な仮想関数として
 *	 onSet() ・ onGet() ・ onErase() があります。
 *	
 *	  このクラスに対して insert() や set() を呼び出すと、
 *	メソッドは onSet() を呼び出して、引数に渡された
 *	 ElementType1 型の値を ElementType2 に型変換してから、
 *	操作対象コンテナ m_pAdaptee に追加します。
 *	
 *	  同様に、get() を呼び出すと、メソッドは値を操作対象コンテナ
 *	 m_pAdaptee から取得した後、onGet() で ElementType2 から
 *	 ElementType1 に変換してから呼び出し元に返します。
 *	
 *	  また、erase() を呼び出すと、メソッドは削除する
 *	要素を引数にして、onErase() を呼び出します。
 *	
 *	   onSet() と onGet() は、必ずオーバライドして、
 *	ElementType1 ― ElementType2 のデータ変換を行う処理を
 *	実装してください。
 *	   onErase() は、通常オーバライドする必要はありません。但し、
 *	「 onSet() で m_pAdapett に追加した要素を m_pAdaptee から
 *	取り除くときに後処理が必要」という場合には、 onSet() に
 *	その後処理を実装してください。例えば
 *	 「onSet() ではオブジェクトを new で生成し、それを
 *	 m_pAdaptee  に追加する」
 *	という場合は、
 *	「 onErase() で、new で生成したオブジェクトを delete する」
 *	ことができます。
 *	
 *	<H4>
 *	【使い方】
 *	</H4>
 *	
 *	１．  このクラスの派生クラスを作成してください。このとき、
 *	 onSet() と onGet() をオーバライドして、型変換の処理を実装
 *	してください。
 *	
 *	２．  あらかじめ、操作対象オブジェクトを生成してください。
 *	
 *	３．  このクラスのオブジェクトを生成してください。
 *	コンストラクタの引数には、操作対象オブジェクトを指定して
 *	ください。
 *	
 *	@attention
 *	 <b> 操作対象オブジェクト（ "IfContGet<ElementType2>"
 *	 インターフェースをサポートするコンテナオブジェクト）は、
 *	空でなくてはなりません。</b>
 *	
 *	４．  このあとは、このクラスの全てのメソッドが利用可能です。
 *	
 *	@attention
 *	 <b>原則として、 this と 操作対象オブジェクト m_pAdaptee の
 *	関連が有効な間は、 m_pAdaptee の "IfCont<ElementType2>" 
 *	メソッドを直接呼び出さないでください。</b>
 *	  特に、 onErase() で要素に対する後処理を行っている場合は、
 *	 this を経由せずに m_pAdaptee に対して要素の追加・削除を
 *	行ってしまうと、不正な動作になります。
 *	\n m_pAdaptee の "IfContGet<ElementType2>" メソッド
 *	( size() ・ get() )は、直接呼び出してもかまいません。
 *	
 *	５．  this は、デストラクタではすべての要素を破棄します。
 *	
 *	
 *	@param ElementType1
 *	  このクラスのメソッドで取得・設定する要素の型を指定して
 *	ください。
 *	@param ElementType2
 *	  操作対象オブジェクト m_pAdaptee が格納している要素の型を
 *	指定してください。
 *	
 */
template < class ElementType1 , class ElementType2 > class CaContFilter :
	public IfCont< ElementType1 > 
{
// ********************************
//関連
// ********************************
public:
	/**
	 *	ElementType2 の別名です。
	 *	m_pAdaptee の要素の型です。
	 */
	typedef ElementType2	adaptee_value_type ;
// ********************************
///@name 関連
// ********************************
///@{
 private:
	/**
	 *	操作対象オブジェクトとなる、コンテナです。
	 *	このオブジェクトの破棄の責務は、クラスユーザーにあります。
	 *	このオブジェクトは、thisとの関連が保たれている間は、
	 *	生存しなくてはなりません。
	 *
	 *	また、このコンテナは、初期状態では空でなくてはなりません。
	 *	理由は、このクラスはデストラクタですべての要素を破棄するからです。
	 *
	 *	<b>原則として、 this と 操作対象オブジェクト m_pAdaptee の
	 *	関連が有効な間は、
	 *	 m_pAdaptee の "IfCont<ElementType2>" メソッドを直接
	 *	呼び出さないでください。</b>
	 *	  特に、 onErase() で要素に対する後処理を行っている場合は、
	 *	 this を経由せずに m_pAdaptee に対して要素の追加・削除を
	 *	行ってしまうと、不正な動作になります。
	 *	\n m_pAdaptee の "IfContGet<ElementType2>" メソッド
	 *	( size() ・ get() )は、直接呼び出してもかまいません。
	 */
	IfCont<ElementType2>*	m_pAdaptee ;
///@}

// --------------------------------
///@name オーバライド可能な仮想関数
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
	 *	  ElementType1 の値を、 ElementType2 に変換する処理を実装
	 *	してください。変換結果の値は戻り値としてください。
	 *	
	 *	  変換に失敗した場合は、 *piResult に負の数を設定して
	 *	ください。
	 *	  *piResult が負の場合、 this は要素をコンテナに格納
	 *	しません。この場合、set() ・ insert() は失敗となり、
	 *	 *piResult が set() ・ insert() の戻り値となります。
	 *	  *piResult が負の場合、この関数の戻り値は評価されませんので、
	 *	何でもかまいません。
	 */
	virtual adaptee_value_type onSet( const value_type& value , int* piResult ) = 0 ;
	
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
	virtual value_type onGet( const adaptee_value_type& value )const = 0 ;
	
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
	 *	  処理はありません。
	 *	  操作対象のコンテナ m_pAdaptee から取り除く要素に対して
	 *	後処理が必要な場合は、このメンバ関数をオーバライドして、
	 *	後処理を実装してください。
	 */
	virtual void onErase( const adaptee_value_type& value ){} ;
///@}


// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param pAdaptee [in]
	 *	操作対象オブジェクトとなる、コンテナです。
	 *	このオブジェクトの破棄の責務は、クラスユーザーにあります。
	 *	このオブジェクトは、thisとの関連が保たれている間は、
	 *	生存しなくてはなりません。
	 */
	CaContFilter( IfCont<ElementType2>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ){};
	/**
	 * @attention
	 *	デストラクタでは、コンテナの全ての要素を破棄します。
	 */
	virtual ~CaContFilter()
	{
		erase( 0 , INT_MAX ) ;
	};
	
// ********************************
///@name	IfContGet
// ********************************
///@{
 public:
	/**
	 * @return
	 * 	コンテナに格納されているデータの個数を返します。
	 */
	virtual int	size()const{	return m_pAdaptee->size() ; } ;
	
	/**
	 * 	コンテナ内の、インデクスで指定された場所に格納されている
	 * 	要素を返します。
	 * @param idx [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 未満です。
	 *	INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	インデクスで指定された要素を返します。
	 *
	 * <H4>
	 * 【オーバライド】
	 * </H4>
	 *	m_pAdaptee 内の要素を onGet() で変換したものを返します。
	 */
	virtual ElementType1 get( int idx )const 
	{
		return onGet( m_pAdaptee->get( idx ) ) ;
	};
///@}
// ********************************
///@name	IfCont
// ********************************
///@{
 public:
	
	/**
	 * 	コンテナ内の、インデクスで指定された場所に、
	 * 	要素を上書きします。
	 * @param element [in]
	 * 	要素を指定してください。
	 * @param iIndex [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 未満です。
	 *	但し、INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	0以上は成功、負の数はエラーです
	 *	-	-1 ;	//	iIndex が不正です。
	 *
	 * <H4>
	 * 【オーバライド】
	 * </H4>
	 *	１．新しい要素を onSet() で ElementType2 に変換します。
	 *
	 *	２．m_pAdaptee 内の既存の要素を引数にして onErase() を
	 *	呼び出して後処理をさせます。
	 *
	 *	３．m_pAdaptee 内の要素を、１．で変換した値に置き換えます。
	 */
	virtual int set( const ElementType1& element , int iIndex ) 
	{
		// --------------------------------
		if ( iIndex == INT_MAX ){
			iIndex = m_pAdaptee->size() - 1 ;
		}
		if ( !( 0 <= iIndex && iIndex < m_pAdaptee->size() ) ){
			return -1 ;	//	iIndex が不正です。
		}
		
		// --------------------------------
		int iRv = 0 ;
		ElementType2 elmNew = onSet( element , &iRv ) ;
		if ( iRv >= 0 ){
			ElementType2 elmOld = m_pAdaptee->get( iIndex ) ;
			onErase( elmOld ) ;
			iRv = m_pAdaptee->set( elmNew , iIndex ) ;
			if ( iRv < 0 ){
				onErase( elmNew ) ;
			}
		}
		return ( iRv ) ;
	};

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
	 * <H4>
	 * 【オーバライド】
	 * </H4>
	 *	要素を onSet() で ElementType2 に変換してから、
	 *	m_pAdaptee に追加します。
	 */
	virtual int insert( const ElementType1& element , int iIndex = INT_MAX ) 
	{
		if ( iIndex == INT_MAX ){
			iIndex = m_pAdaptee->size() ;
		}
		if ( !( 0 <= iIndex && iIndex <= m_pAdaptee->size() ) ){
			return -1 ;	//	iIndex が不正です。
		}
		// --------------------------------
		int iRv = 0 ;
		ElementType2 elmNew = onSet( element , &iRv ) ;
		if ( iRv >= 0 ){
			iRv = m_pAdaptee->insert( elmNew , iIndex ) ;
			if ( iRv < 0 ){
				onErase( elmNew ) ;
			}
		}
		return ( iRv ) ;
		
	}
	
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
	 *	-	-1 ;	//	iIndex が不正
	 *
	 * <H4>
	 * 【オーバライド】
	 * </H4>
	 *	削除する要素を引数にして、onErase() を呼び出してから、
	 *	m_pAdaptee から要素を削除します。
	 */
	virtual int erase( int iIndex , int iSize = 1 ) 
	{
		if ( m_pAdaptee == NULL ){
			return 0 ;
		}
		if ( iIndex == INT_MAX && iSize == INT_MAX ){
			return -1 ;	//	iIndex が不正
		}
		if ( iIndex == INT_MAX ){
			iIndex = m_pAdaptee->size() - iSize ;
		}
		if ( iSize == INT_MAX ){
			iSize = m_pAdaptee->size() - iIndex ;
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= m_pAdaptee->size() ) ){
			return -1 ;	//	iIndex が不正です。
		}
		// --------------------------------
		for ( int cnt = 0 ; cnt < iSize ; cnt ++ ){
			ElementType2 elmOld = m_pAdaptee->get( iIndex + iSize - 1 - cnt ) ;
			onErase( elmOld ) ;
		}
		return m_pAdaptee->erase( iIndex , iSize ) ;
		
		
		
	} ;
	
	
///@}
// ********************************
//	CaContFilter
// ********************************
 public:
	// ********************************
	///@name CaContFilter-関連
	// ********************************
	///@{
	IfCont<ElementType2>*	getAdaptee(){	return m_pAdaptee ;};
	const IfCont<ElementType2>*	getAdaptee()const{	return m_pAdaptee ;};
	/**
	 *	このメソッドで m_pAdaptee を置き換えた場合、 this は 
	 *	erase( 0 , INT_MAX ) 
	 *	で、コンテナが保持していた要素を破棄します。
	 */
	CaContFilter<ElementType1,ElementType2>& setAdaptee( 
			IfCont<ElementType2>*	value )
	{
		erase( 0 , INT_MAX ) ;
		m_pAdaptee = value ; 	return *this ;
	};
	///@}
	

};




#endif /*CaContFiler_h*/
