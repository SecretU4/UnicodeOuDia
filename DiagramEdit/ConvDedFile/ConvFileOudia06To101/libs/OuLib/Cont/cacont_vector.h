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
//	CaCont_vector.h
// ****************************************************************
*/
/** @file */
#ifndef  CaCont_vector_h
#define  CaCont_vector_h
#include <stddef.h>
#include <assert.h>
#include ".\IfValueCont.h"


// ****************************************************************
//	CaCont_vector
// ****************************************************************
/**
 * @brief
 * 【概要】
 *   IfValueCont インターフェースで、STLのランダムアクセスコンテナ
 *	（ランダムアクセス反復子をサポートする
 * コンテナ。std::vector か std::deque）を操作する、アダプタクラスです。
 *	
 *   このクラスのオブジェクトは、操作対象となる一つのコンテナと関連を
 *	持ちます。
 * 
 * 	  コンテナ内の要素の型は、デフォルトコンストラクタと = が
 *	利用可能である必要があります。
 * 
 * 【使い方】
 * 
 * １．  通常は、あらかじめ操作対象オブジェクト（Adaptee）
 * （原則は STLランダムアクセスコンテナ（std::vector か std::deque ））
 *	 を生成してください。
 *
 *	２．  このクラスのテンプレート引数には、操作対象オブジェクトの型を
 *	指定してください。また、コンストラクタでは、操作対象オブジェクト
 *	へのポインタを指定してください。
 * 
@code
	std::vector<int>	aVector ;
	CaCont_vector< std::vector<int>	>	aCont( &aVector )  ;
@endcode

 * ※  このクラスに、操作対象オブジェクトを生成させることもできます。
 * この場合は、コンストラクタの引数に NULL を指定してください。
 * 
@code
	CaCont_vector< std::vector<int>	> aCont( NULL ) ;
@endcode
 * ３．  これ以後は、 IfCont インターフェースのメソッドを利用して、
 * コンテナを操作することができます。
 *
 * <H4>
 *	【コンテナ内の要素のインスタンスについて】
 * </H4>
 *	 コンテナのサイズを変更するメソッドを呼び出した場合、
 *	コンテナ内のインスタンスの再割り当てが発生します。
 *  再割り当てが発生すると、getp() で取得したポインタは無効になります。
 *
 *
 * @param ContType
 *	操作対象のコンテナの型を指定してください。
 *	この型は、格納する要素の型をテンプレートパラメータに指定した
 *	 std::vector か std::deque でなくてはなりません。
 *	格納する要素の型をテンプレートパラメータに指定した
 */
template< class ContType >
class CaCont_vector : public IfValueCont< typename ContType::value_type >
{
// ********************************
//	インナータイプ
// ********************************
 public:
	/**
	 *	操作対象のコンテナの型
	 */
	typedef ContType	cont_type ;

// ********************************
///@name 関連
// ********************************
///@{
 private:	
	/**
	 *   操作対象の、STLランダムアクセスコンテナです。
	 *
	 *	操作対象を指定せずにこのクラスのオブジェクトを生成した場合、
	 *	コンストラクタは、操作対象コンテナを生成します。この場合、
	 *  内部要素 m_bIsDeleteObligatory は true となります。
	 *
	 *  このオブジェクトの破棄の責務は、内部データ m_bIsDeleteObligatory が
	 *	 false の場合はクラスユーザー・ true の場合は this にあります。
	 *	
	 *	操作対象は、この関連が有効な間は生存しなくてはなりません。
	 */
	ContType*	m_pAdaptee ;
	
///@}
// --------------------------------
///@name 内部データ
// --------------------------------
///@{
 private:
	/**
	 * @see m_pAdaptee
	 */
	bool	m_bIsDeleteObligatory ;
///@}

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 * @param pContType [in]
	 *   操作対象の、STLランダムアクセスコンテナです。
	 *	このオブジェクトの破棄の責務は、クラスユーザーにあります。
	 *	操作対象は、この関連が有効な間は生存しなくてはなりません。\n
	 */
	CaCont_vector( ContType* pContType )
		: m_pAdaptee( pContType )
		, m_bIsDeleteObligatory( false ){};
	
	/**
	 *   このコンストラクタは、
	 *	操作対象の STLランダムアクセスコンテナ m_pAdaptee 
	 *	を、このクラスで生成します。
	 */
	CaCont_vector()
		: m_pAdaptee( new ContType  )
		, m_bIsDeleteObligatory( true ){};
	
	/**
	 *  コピーコンストラクタは、
	 *	操作対象の STLランダムアクセスコンテナ m_pAdaptee 
	 *	を、このクラスで生成します。
	 */
	CaCont_vector( const CaCont_vector& element )
		: m_pAdaptee( new ContType )
		, m_bIsDeleteObligatory( true )
	{
		*m_pAdaptee = *element.m_pAdaptee ;
	};
	
	CaCont_vector& operator=( const CaCont_vector& element )
	{
		*m_pAdaptee = *element.m_pAdaptee ;
		return *this ; 
	};
	
	virtual ~CaCont_vector()
	{
		if ( m_bIsDeleteObligatory ){
			delete m_pAdaptee ;
			m_bIsDeleteObligatory = false ;
			m_pAdaptee = NULL ;
		}
	};
	
	
// ********************************
///@name	IfContGet
// ********************************
///@{
 public:
	/**
	 * @return
	 * 	コンテナに格納されている要素の個数を返します。
	 */
	virtual int	size()const
	{
		assert( 0 <= m_pAdaptee->size() && m_pAdaptee->size() <= INT_MAX ) ; 
		return (int)m_pAdaptee->size() ; 
	} ;
	
	// --------------------------------

	/**
	 * 	コンテナ内の、インデクスで指定された場所に格納されている
	 * 	要素を返します。
	 * @param iIndex [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 未満です。
	 *	但し、INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	インデクスで指定された要素を返します。
	 *
	 *	インデクスが不正な場合の動作は未定義です。
	 */
	virtual value_type get( int iIndex )const
	{
		if ( iIndex == INT_MAX ){
			assert( 0 <= m_pAdaptee->size() && m_pAdaptee->size() <= INT_MAX ) ; 
			iIndex = (int)m_pAdaptee->size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_pAdaptee->size() ) ){
			return *( (value_type*)NULL ) ; 
		}
		return (*m_pAdaptee)[iIndex] ;
	} ;
	
	// --------------------------------
// ********************************
///@name	IfCont
// ********************************
///@{
 public:
	
	/**
	 * 	コンテナ内の、インデクスで指定された場所に、
	 * 	要素をセット（上書き）します。
	 * @param element [in]
	 * 	要素を指定してください。
	 * @param iIndex [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 未満です。
	 *	INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	0以上は成功、負の数はエラーです
	 *	-	-1 ;	//	iIndexが不正
	 */
	virtual int set( const value_type& element , int iIndex ) 
	{
		if ( iIndex == INT_MAX ){
			assert( 0 <= m_pAdaptee->size() && m_pAdaptee->size() <= INT_MAX ) ; 
			iIndex = (int)m_pAdaptee->size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_pAdaptee->size() ) ){
			return -1 ;	//	iIndexが不正
		}
		(*m_pAdaptee)[iIndex] = element ;
		return ( 0 ) ;
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
	 *	INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	0以上は成功、負の数はエラーです
	 *	-	-1 ;	//	iIndexが不正
	 */
	virtual int insert( const value_type& element , int iIndex = INT_MAX ) 
	{
		if ( iIndex == INT_MAX ){
			assert( 0 <= m_pAdaptee->size() && m_pAdaptee->size() <= INT_MAX ) ; 
			iIndex = (int)m_pAdaptee->size() ; 
		}
		if ( !( 0 <= iIndex && iIndex <= (int)m_pAdaptee->size() ) ){
			return -1 ;	//	iIndexが不正
		}
		m_pAdaptee->insert( m_pAdaptee->begin() + iIndex , element ) ;
		return ( 0 ) ;
	};
	
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
	 */
	virtual int erase( int iIndex , int iSize = 1 ) 
	{
		assert( 0 <= m_pAdaptee->size() && m_pAdaptee->size() <= INT_MAX ) ; 

		if ( iIndex == INT_MAX && iSize == INT_MAX ){
			return -1 ;	//	iIndexが不正
		}
		if ( iIndex == INT_MAX ){
			iIndex = (int)m_pAdaptee->size() - iSize ; 
		}
		if ( iSize == INT_MAX ){
			iSize = (int)m_pAdaptee->size() - iIndex ; 
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= (int)m_pAdaptee->size() ) ){
			return -1 ;	//	iIndexが不正
		}
		// --------------------------------
		m_pAdaptee->erase( 
			m_pAdaptee->begin() + iIndex , 
			m_pAdaptee->begin() + iIndex + iSize ) ;
		return ( 0 ) ;
	};
///@}
// ********************************
///@name IfValueCont
// ********************************
///@{
 public:
	/**
	 * 	コンテナ内の、インデクスで指定された場所に格納されている要素への
	 * 	非 const なポインタを取得することができます。
	 * @param iIndex [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 以下です。
	 * 	０は、先頭・size()なら末尾への追加になります。
	 *	INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	コンテナ内の、インデクスで指定された場所に格納されている要素への
	 * 	非 const なポインタを返します。
	 * 	iSize が範囲外の場合は、 NULL を返します。
	 */
	virtual value_type* getp( int iIndex ) 
	{
		assert( 0 <= m_pAdaptee->size() && m_pAdaptee->size() <= INT_MAX ) ; 

		if ( iIndex == INT_MAX ){
			iIndex = (int)m_pAdaptee->size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_pAdaptee->size() ) ){
			return NULL ; 
		}
		return &(*m_pAdaptee)[iIndex] ;
	};
///@}
// ********************************
// CaCont_vector
// ********************************
 public:
	// ********************************
	///@name CaCont_vector-関連
	// ********************************
	///@{
	ContType*	getAdaptee(){	return m_pAdaptee ;};
	const ContType*	getAdaptee()const{	return m_pAdaptee ;};
	CaCont_vector& setAdaptee( ContType*	pAdaptee )
	{
		if ( m_bIsDeleteObligatory && pAdaptee != NULL ){
			delete m_pAdaptee ;
			m_bIsDeleteObligatory = false ;
			m_pAdaptee = pAdaptee ;
		}	else if ( !m_bIsDeleteObligatory && pAdaptee == NULL ){
			m_bIsDeleteObligatory = true ;
			m_pAdaptee = new ContType ;
		}	else	{
			m_pAdaptee = pAdaptee ;
		}
		return *this ;
	};
	
	///@}
	// --------------------------------

};

#endif /*CaCont_vector_h*/
