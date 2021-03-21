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
//	CaMup_list.h
// ****************************************************************
*/
/** @file */
#ifndef  Mu_CaMup_list_h
#define  Mu_CaMup_list_h

#include <assert.h>
#include <list>
#include <deque>
#include "./Mup.h"

namespace OuLib{

#ifndef NO_NSMU
namespace NsMu{
#endif//NO_NSMU

// ****************************************************************
//	CaMup_list
// ****************************************************************
/**
@brief
   Mu,Mui,Mup インターフェースで、STLのリストコンテナ
（ std::list ）を操作する、アダプタクラスです。
	
   このクラスのオブジェクトは、操作対象となる一つのコンテナと関連を
	持ちます。

   このクラスでは、操作対象オブジェクトであるリストコンテナ内の
 各要素に対する、反復子の配列を内部的に ( m_IteCont に ) 保持します。
 
   this と操作対象オブジェクトとの間の関連を設定すると
 ( コンストラクタ・ setAdaptee() )、 this は m_pAdaptee をスキャンし、
	各要素に対する反復子を取得して、配列に保存します。
 
   Mup< ElementType >  インターフェースを使って要素にアクセスする場合は、
 この配列に保存されている反復子を使います。これにより、リストコンテナが
 本来苦手とするランダムアクセスが迅速にできるようにしています。
 
   Mui<DataType>  インターフェースを使って、コンテナ内の要素を
 増減するような操作を行った場合、this は内部的に保持している反復子の
 配列も一緒に更新します。
 
   this と関連を持っている操作対象オブジェクトのコンテナの要素数を
 直接変更した場合（ Mui インターフェースメソッド以外の方法でコンテナを
 操作した場合）は、ターゲットオブジェクトであるリストコンテナと、
  this が保持している反復子の配列( m_IteCont ) との同期が失われます。
 このときは、 scan() メソッドを使って、反復子の配列を再構築しなくては
 なりません。
 
 【使い方】
 
１．  通常は、あらかじめ操作対象オブジェクト（Adaptee）
 （原則は STL双方向アクセスコンテナ
	（std::list , std::map , std::set など））） を生成
 してください。

２．  このクラスのテンプレート引数には、操作対象オブジェクトの型を
	指定してください。また、コンストラクタでは、操作対象オブジェクト
	へのポインタを指定してください。
 
@code
	std::list< CBase >	aList( NULL ) ;
	CaMup_list< std::list< CBase > >	aCont( &aList )  ;
@endcode

	(あとから setAdaptee() で操作対象を設定することもできます)。

 ３．  これ以後は、 Mup インターフェースのメソッドを利用して、
 コンテナを操作することができます。

 <H4>
	【コンテナ内のデータのインスタンスについて】
 </H4>
	 コンテナのサイズを変更するメソッドを呼び出した場合でも、
	コンテナ内のインスタンスの再割り当ては起こりません。
   getp() で取得したポインタは、コンテナからその要素を削除するまで
	有効です。


 @param ContType
	操作対象のコンテナの型を指定してください。
	この型は、格納するデータの型をテンプレートパラメータに指定した
	双方向アクセスコンテナ（std::list , std::map , std::set など）））
 でなくてはなりません。
*/
template< class ContType >
class CaMup_list : public Mup< typename ContType::value_type >
{
 public:
	/**
		操作対象のコンテナの型
	*/
	typedef ContType	cont_type ;

	/**
		反復子を保持するコンテナの型
	*/
	typedef std::deque< typename ContType::iterator >	IteCont ;

private:	
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
	   操作対象の、STL双方向アクセスコンテナです。
	
	  このオブジェクトの破棄の責務は、クラスユーザー・ true の場合は this にあります。
		
		操作対象は、この関連が有効な間は生存しなくてはなりません。
	*/
	ContType*	m_pAdaptee ;
	
	///@}
private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
	 *	  ターゲットオブジェクトであるリストコンテナ内の各要素に対する、
	 *	反復子の配列を保持するコンテナです。
	 */
	IteCont	m_IteCont ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	 @param pContType [in]
	   ターゲットの、STLランダムアクセスコンテナです。
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		ターゲットは、この関連が有効な間は生存しなくてはなりません。\n
	*/
	CaMup_list( ContType* pContType )
		: m_pAdaptee( pContType )
	{
		scan() ;
	};
	
	/**
	 *   このコンストラクタは、
	 *	操作対象の STLランダムアクセスコンテナ m_pAdaptee 
	 *	を、このクラスで生成します。
	 */
	CaMup_list()
		: m_pAdaptee( NULL )
	{
	};
	
private:
	/**
		このクラスのコピーは不可能です。
	 */
	CaMup_list( const CaMup_list& value )
		: m_pAdaptee( NULL )
	{
		assert( false ) ;
	};
	
	/**
		このクラスのコピーは不可能です。
	*/
	CaMup_list& operator=( const CaMup_list& value )
	{
		*m_pAdaptee = *value.m_pAdaptee ;
		scan() ;
	};
	
public:
	virtual ~CaMup_list()
	{
	};
	
	
public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	
	/**
	 @return
	 	コンテナに格納されているデータの個数を返します。
	*/
	virtual int	size()const
	{
		if ( m_pAdaptee == NULL )
		{
			return 0 ;
		}
		return m_pAdaptee->size() ; 
	} ;
	
	// --------------------------------

	/**
	 	コンテナ内の、インデクスで指定された場所に格納されている
	 	要素を返します。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 未満です。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	インデクスで指定された要素を返します。
	
		インデクスが不正な場合の動作は未定義です。
	 */
	virtual value_type get( int iIndex )const 
	{
		if ( m_pAdaptee == NULL )
		{
			return *( (value_type*)NULL ) ;
		}
		if ( iIndex == INT_MAX )
		{
			iIndex = m_pAdaptee->size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_pAdaptee->size() ) )
		{
			return *( (value_type*)NULL ) ; 
		}
		return *m_IteCont[iIndex] ;
	} ;
	
	///@}
public:
	// ********************************
	///@name Mui
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
		-	-1 ;	//	iIndexが不正
	*/
	virtual int insert( const value_type& element , int iIndex = INT_MAX ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = m_pAdaptee->size() ; 
		}
		if ( !( 0 <= iIndex && iIndex <= (int)m_pAdaptee->size() ) )
		{
			return -1 ;	//	iIndexが不正
		}
		{
			ContType::iterator ite = m_pAdaptee->insert( 
				m_IteCont[iIndex] , 
				element ) ;
			m_IteCont.insert( m_IteCont.begin() + iIndex , ite ) ;
		}
		return ( 0 ) ;
	};
	
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
		-	-1 ;	//	iIndexが不正
	 */
	virtual int erase( int iIndex , int iSize = 1 ) 
	{
		if ( iIndex == INT_MAX && iSize == INT_MAX )
		{
			return -1 ;	//	iIndexが不正
		}
		if ( iIndex == INT_MAX )
		{
			iIndex = m_pAdaptee->size() - iSize ; 
		}
		if ( iSize == INT_MAX )
		{
			iSize = m_pAdaptee->size() - iIndex ; 
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= (int)m_pAdaptee->size() ) )
		{
			return -1 ;	//	iIndexが不正
		}
		// --------------------------------
		m_pAdaptee->erase( m_IteCont[iIndex] , m_IteCont[ iIndex + iSize ] ) ;
		m_IteCont.erase( m_IteCont.begin() + iIndex , 
			m_IteCont.begin() + iIndex + iSize ) ;
		return ( 0 ) ;
	};
	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素を上書きします。
	 @param element [in]
	 	要素を指定してください。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 未満です。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	0以上は成功、負の数はエラーです
		-	-1 ;	//	iIndexが不正
	 */
	virtual int set( const value_type& element , int iIndex ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = m_pAdaptee->size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_pAdaptee->size() ) )
		{
			return -1 ;	//	iIndexが不正
		}
		*m_IteCont[iIndex] = element ;
		return ( 0 ) ;
	};
	
	///@}
public:
	// ********************************
	///@name	Mup
	// ********************************
	///@{
	/**
	 	コンテナ内の、インデクスで指定された場所に格納されている要素への
	 	非 const なポインタを取得することができます。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 以下です。
	 	０は、先頭・size()なら末尾への追加になります。
		INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	コンテナ内の、インデクスで指定された場所に格納されている要素への
	 	非 const なポインタを返します。
	 	iSize が範囲外の場合は、 NULL を返します。
	*/
	virtual value_type* getp( int iIndex ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = m_pAdaptee->size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_pAdaptee->size() ) )
		{
			return NULL ; 
		}
		return &( *m_IteCont[iIndex] ) ;
	};
	///@}
 public:
	// ********************************
	///@name CaMup_list-関連
	// ********************************
	///@{
	ContType*	getAdaptee(){	return m_pAdaptee ;};
	const ContType*	getAdaptee()const{	return m_pAdaptee ;};
	void setAdaptee( ContType*	pAdaptee )
	{
		m_pAdaptee = pAdaptee ;
		scan() ;
	};
	
	// ********************************
	///@name CaMup_list-操作
	// ********************************
	/**
		 this と関連をもっているターゲットオブジェクトのコンテナの、
		各要素の反復子を保持しているコンテナ m_IteCont を再構築します。
	
	   this と関連をもっているターゲットオブジェクトのコンテナの要素数を
	 直接変更した場合（ Mui インターフェースメソッド以外の方法でコンテナを
	 操作した場合）は、ターゲットオブジェクトであるリストコンテナと、this が
	 保持している反復子の配列( m_IteCont ) との同期が失われます。
	 このときは、 scan() メソッドを使って、反復子の配列を再構築しなくては
	 なりません。
	*/
	void scan() 
	{
		m_IteCont.clear() ;
		if ( m_pAdaptee != NULL )
		{
			ContType::iterator	ite ;
			for ( ite = m_pAdaptee->begin() ; ite != m_pAdaptee->end() ; ite ++ )
			{
				m_IteCont.push_back( ite ) ;
			}
			m_IteCont.push_back( m_pAdaptee->end() ) ;
		}
	};
};

#ifndef NO_NSMU
} //namespace NsMu
#endif//NO_NSMU

} //namespace OuLib

#endif /*Mu_CaMup_list_h*/
