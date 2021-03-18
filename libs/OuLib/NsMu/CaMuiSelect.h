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
//	CaMuiSelect.h
//	$Id: CaMuiSelect.h 344 2016-08-14 06:31:32Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  Mu_CaMuiSelect_h
#define  Mu_CaMuiSelect_h
#include "./Mu.h"
#include <vector>
#include <algorithm>

/**
  CaMuiSelect の実装アルゴリズムを選択することができます。

<h4>0</h4>

要素の選択状況 CaMuiSelect::m_contSelect に対する
キャッシュはありません。
CaMuiSelect::size()・CaMuiSelect::indexToAdapteeIndex()・
CaMuiSelect::indexFromAdapteeIndex() は、
m_contSelect をスキャンします。

CaMuiSelectTest::run()の実行時間(Debug バージョン)=13秒。

<h4>1</h4>
indexToAdapteeIndex() の結果のキャッシュを、
メンバ変数 CaMuiSelect::m_AdapteeIndexCache に
保持するようになります。
CaMuiSelect::m_AdapteeIndexCache は mutable になります。

CaMuiSelectTest::run()の実行時間(Debug バージョン)=9秒。
*/
#define CaMuiSelect_ALGORITHM	1

namespace OuLib{

#ifndef NO_NSMU
namespace NsMu{
#endif//NO_NSMU


// ****************************************************************
//	CaMuiSelect.h
// ****************************************************************
/**
@brief
  アダプタクラスです。
  コンテナの一部の要素を選択した形の、部分コンテナインターフェースを
作成します。

  このクラスは、操作対象となる他のコンテナ(Adaptee)の要素から、
一部を選択した部分コンテナを提供します。
  クラスユーザーは、このクラスを介して Adaptee コンテナの一部要素を
参照することができます。
  Adapteeコンテナがオブジェクトを保持しており、そのオブジェクトの
ポインタや参照にアクセスできる場合は、Adaptee コンテナの一部要素に
対して、操作を行うこともできます。

  このクラスは、以下のインターフェースをサポートしたコンテナを
Adaptee として操作することができます。
  但し、このうちのすべてをサポートしている必要はありません。

  - Mu<ElementType1>   (必須)
  - Mui<ElementType1>  (任意)
  - const Mu<const ElementType1*>　(任意)
  - Mu<ElementType1*>　(任意)

  Mui<ElementType1> が指定された場合は、Mu<ElementType1> も
指定されたことになります。
  
  	 
  CaMuiSelect は、生成直後は、１つの要素も選択されない状態です。
  インスタンスを生成したら、 setSelect() で、要素を選択してください。

<h3>
【例1】Mu<ElementType1> をサポートしているコンテナ
</h3>

  Mu<string> をサポートするコンテナに、以下の要素が格納されて
いたとします。(string は、std::string のことを指します)
  
  { "zero" , "one" , "two" , "three" , "four" , "five" , 
    "six" , "seven" } ;
  
  このコンテナの Mu<string>インターフェースに対して、
 CaMuiSelect<string> アダプタを設定した後、要素0,4,6を選択することに
より、 CaMuiSelectの Mu<string> インターフェースは、以下の３つの
要素を返します。

  { "zero" , "four" , "six" } ;
  
 
 
<h3>
【例2】Mui<ElementType1> をサポートしているコンテナへの追加
</h3>

  Mui<string> をサポートするコンテナに、以下の要素が格納されて
いたとします。
  
  { "zero" , "one" , "two" , "three" , "four" , "five" , 
    "six" , "seven" } ;

  このコンテナの Mui<string>インターフェースに対して、 
CaMuiSelect<string> アダプタを設定した後、要素0,4,6を選択することに
より、CaMuiSelectの Mui<string> インターフェースは、以下の３つの
要素を返します。

  { "zero" , "four" , "six" } ;

  ここで、CaMuiSelect に insert() メソッドを使い、0番目に要素
 "newzero" を挿入すると、CaMuiSelect は、以下の4つの要素を返すように
なります。

  { "newzero" , "zero" , "four" , "six" } ;

  操作対象コンテナ(m_pAdaptee)の内容は、以下のようになります。

  { "newzero" , "zero" , "one" , "two" , "three" , "four" , 
    "five" , "six" , "seven" } ;
  

  また、CaMuiSelectの要素選択状況は、{0,1,5,7} となります。



<h3>
【例3】Mui<ElementType1> をサポートしているコンテナからの削除
</h3>

  Mui<string> をサポートするコンテナに、以下の要素が格納されていたとします。
  
  { "zero" , "one" , "two" , "three" , "four" , "five" , 
    "six" , "seven" } ;

  このコンテナの Mui<string>インターフェースに対して、 CaMuiSelect<string> 
アダプタを設定した後、要素0,4,6を選択することにより、 CaMuiSelectの 
Mui<string> インターフェースは、以下の３つの要素を返します。

  { "zero" , "four" , "six" } ;

  ここで、CaMuiSelect の erase() メソッドを使い、0番目から2個の要素を
削除すると、CaMuiSelect は、以下の要素を返すようになります。

  {  "six" } ;

  操作対象コンテナ(m_pAdaptee)の内容は、以下のようになります。

  { "one" , "two" , "three" , "five" , "six" , "seven" } ;
  

  また、CaMuiSelectの要素選択状況は、{ 4 } となります。


<h3>
【例4】Mu<ElementType1*> ・ const Mu<const ElementType1*> をサポート
しているコンテナ
</h3>

  Mui<string> をサポートするコンテナに、以下の要素が格納されており、
かつ、このコンテナが Mu<string*> をサポートしていたとします。
  
  { "zero" , "one" , "two" , "three" , "four" , "five" , 
    "six" , "seven" } ;

  このコンテナの Mui<string*> インターフェースに対して、
 CaMuiSelect<string> アダプタを設定した後、要素0,4,6を選択することにより、
 CaMuiSelectの Mui<string> インターフェースは、以下の３つの要素を返します。

  { "zero" , "four" , "six" } ;

  CaMuiSelect の getMuPtr() メソッドで、 Mu<string*> インターフェースを取得する
ことができます。この Mu<string*> インターフェースでも、上記の要素を取得する
ことができます。

  さらに、この Mu<string*> を使うと、格納されている string オブジェクトの
メンバ関数を呼び出したり、メンバ変数を直接操作することができます。
  上記の3つの要素に対して、 string::erase() メソッドを使用して、先頭の1文字を
削除することができます。

  { "ero" , "our" , "ix" } ;

  操作対象コンテナ(m_pAdaptee)の内容は、以下のようになります。

  { "ero" , "one" , "two" , "three" , "our" , "five" , 
    "ix" , "seven" } ;

@note
  CMuiCopied を Adaptee としてこのクラスを使用する場合は、
以下のようなコンストラクタ呼び出しで、インスタンスを生成してください。

@code
	CMuiCopied<CBase> aCont ;

	//	aCont に要素を追加

	CaMuiSelect<CBase>	aSelect( &aCont , aCont.getMuPtr() ) ;
@endcode


@param ElementType1
  	格納する要素の型を指定してください。
  	このクラスは、 Mu< ElementType1 > インターフェースを
  	サポートします。
 */
template < class ElementType1 > class CaMuiSelect : 
	public Mui< ElementType1 > 
{
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		操作対象オブジェクトとなるコンテナ(Adaptee)の、 
		Mu<ElementType1>インターフェースです。
		
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、thisとの関連が保たれている間は、
		生存しなくてはなりません。
		
		m_pAdapteeMui に有効なインターフェースがある場合は、
		このインターフェースも有効になります。
	*/
	Mu<ElementType1>*	m_pAdapteeMu ;

	/**
		操作対象オブジェクトとなるコンテナの、 
		Mui<ElementType1>インターフェースです。

		操作対象がこのインターフェースをサポートしていない場合は、
		NULL とすることもできます。
		但し、このクラスの set(),insert(),erase() メソッドを使用するためには、
		このインターフェースをセットする必要があります。

		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、thisとの関連が保たれている間は、
		生存しなくてはなりません。
		
		また、thisとの関連が有効な間に、thisのメソッド以外の方法で、
		このコンテナの要素数を変えないでください。
		このクラスは、m_pAdaptee の要素数と、this->m_contSelectの 要素数が
		異なると、正しく動作しなくなります。
		もし、m_pAdapteeMui の要素数を、変えた場合は、setAdaptee() で、
		関連を再設定してください。
	*/
	Mui<ElementType1>*	m_pAdapteeMui ;

	/**
		操作対象オブジェクトとなるコンテナ(Adaptee)の、 
		Mu<const ElementType1*> インターフェースです。
		
		操作対象がこのインターフェースをサポートしていない場合は、
		NULL とすることもできます。
		但し、getMuPtr() によるインターフェースを使用する場合は、
		m_pAdapteeMuConstPtr,m_pAdapteeMuPtr のいずれかが
		必要です。

		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、thisとの関連が保たれている間は、
		生存しなくてはなりません。

		m_pAdapteeMuPtr が有効な場合は、このインターフェースの指定がなくても
		Mu<const ElementType1*> インターフェースを使用することができます。
	*/
	Mu<const ElementType1*>* m_pAdapteeMuConstPtr ;
	
	/**
		操作対象オブジェクトとなるコンテナ(Adaptee)の、 
		Mu<ElementType1*> インターフェースです。
		
		操作対象がこのインターフェースをサポートしていない場合は、
		NULL とすることもできます。
		但し、getMuPtr() によるインターフェースで、
		コンテナ内の要素の非constポインタを取得する場合は、
		m_pAdapteeMuPtr が必要です。

		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、thisとの関連が保たれている間は、
		生存しなくてはなりません。
	*/
	Mu<ElementType1*>* m_pAdapteeMuPtr ;
	///@}
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{

	/**
	@brief
		現在選択されている要素への、 Mu<ElementType*> 
		インターフェースを実装します。

	 m_pAdapteeMuPtr に、有効なインターフェースが設定されている
	必要があります。

	*/
	class XMuConstPtr : public Mu<const ElementType1*>
	{
	public:
		// ********************************
		///@name Mu
		// ********************************
		///@{
		/**
		@return
	 		コンテナに格納されているデータの個数を返します。
		 	
	 		選択されているデータの個数を返します。
		@attention
			 CaMuiSelect の m_pAdapteeMuPtr・m_pAdapteeMu のどちらにも
			 有効なインターフェースが設定されていない
			場合、このメソッドは動作しません。
		*/
		virtual int	size()const
		{
			const CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_XMuConstPtr) ) ;

			int iRv = pOuter->size() ;
			return iRv ;
		} ;
		

		/**
 		  コンテナ内の、インデクスで指定された場所に格納されている
 		要素を返します。
		 @param idx [in]
	 		０から始まるインデクスを指定してください。
	 		範囲は０以上 size() 未満です。
			INT_MAX は、末尾を指定したものとみなします。
		 @return
	 		インデクスで指定された要素を返します。
		@attention
			 CaMuiSelect の m_pAdapteeMuPtr・m_pAdapteeMu のどちらにも
			 有効なインターフェースが設定されていない
			場合、このメソッドは動作しません。
		*/
		virtual const ElementType1* get( int idx )const 
		{
			const CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_XMuConstPtr) ) ;

			if ( idx == INT_MAX )
			{
				idx = size() -1 ; 
			}

			const ElementType1* pRv = NULL ;
			int iAdapteeIndex = pOuter->indexToAdapteeIndex( idx ) ;
			if ( iAdapteeIndex >= 0 )
			{
				if ( pOuter->m_pAdapteeMuConstPtr != NULL )
				{
					pRv = pOuter->m_pAdapteeMuConstPtr->get( iAdapteeIndex ) ;
				}
				else if ( pOuter->m_pAdapteeMuPtr != NULL )
				{
					pRv = pOuter->m_pAdapteeMuPtr->get( iAdapteeIndex ) ;
				}
			}
			return ( pRv ) ;
		};
		///@}

	} ;
	friend class XMuConstPtr ;
	XMuConstPtr m_XMuConstPtr ;



	/**
	@brief
		現在選択されている要素への、 Mu<ElementType*> 
		インターフェースを実装します。

	 m_pAdapteeMuPtr に、有効なインターフェースが設定されている
	必要があります。

	*/
	class XMuPtr : public Mu<ElementType1*>
	{
	public:
		// ********************************
		///@name Mu
		// ********************************
		///@{
		/**
		 @return
	 		コンテナに格納されているデータの個数を返します。
		 	
	 		選択されているデータの個数を返します。
		@attention
			 m_pAdapteeMuPtr に、有効なインターフェースが設定されていない
			場合、このメソッドは動作しません。
		*/
		virtual int	size()const
		{
			const CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_XMuPtr) ) ;
			int iRv = pOuter->size() ;
			return iRv ;
		} ;
		

		/**
 		  コンテナ内の、インデクスで指定された場所に格納されている
 		要素を返します。
		 @param idx [in]
	 		０から始まるインデクスを指定してください。
	 		範囲は０以上 size() 未満です。
			INT_MAX は、末尾を指定したものとみなします。
		 @return
	 		インデクスで指定された要素を返します。
		@attention
			 m_pAdapteeMu に、有効なインターフェースが設定されていない
			場合、このメソッドは動作しません。
		*/
		virtual ElementType1* get( int idx )const 
		{
			const CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_XMuPtr) ) ;

			if ( idx == INT_MAX )
			{
				idx = size() -1 ; 
			}



			ElementType1* pRv = NULL ;
			int iAdapteeIndex = pOuter->indexToAdapteeIndex( idx ) ;
			if ( iAdapteeIndex >= 0 )
			{
				pRv = pOuter->m_pAdapteeMuPtr->get( iAdapteeIndex ) ;
			}
			return ( pRv ) ;
		};
		///@}

	} ;
	friend class XMuPtr ;
	XMuPtr m_XMuPtr ;

	///@}

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		操作対象のコンテナ m_pAdaptee の中で、各要素の選択状況。
		true は 選択、false は非選択です。既定値は、 false です。
		この配列の要素数は、 m_pAdaptee->size() と等しくなります。
	*/
	std::vector<bool> m_contSelect ;
	///@}
private:
	#if ( CaMuiSelect_ALGORITHM >= 1 )
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
	@brief
		CaMuiSelect::indexToAdapteeIndex() の結果の
		キャッシュを保持するクラスです。

	  外側の CaMuiSelect の m_contSelectの内容・Adapteeの要素数が
	変更されたときは、this のキャッシュの内容は無効になります。
	  この場合、CaMuiSelect は、 invalidate() を呼び出して、
	キャッシュが無効になったことをthis に知らせなくてはなりません。
	　CaMuiSelect の insert(),erase(),setSelect() が呼び出されたときが、
	 これに該当します。
	*/
	class CAdapteeIndexCache
	{
	public:
		CAdapteeIndexCache() : m_bIsValid( false ){}
	private:
		/**
			- true: this が有効 
		*/
		bool m_bIsValid ;

		/**
			indexToAdapteeIndex() の結果のキャッシュです。
			thisのインデクスを添字、Adapteeのインデクスを要素に持つ
			配列です。
			
			this が無効なときに、getAdapteeIndex() が呼び出されると
			更新されます。
		*/
		std::vector<int> m_contAdapteeIndex ;
	private:
		/**
			this が無効の場合は、
			m_contAdapteeIndex を生成し、有効にします。
			this が有効な場合は、何もしません。
		*/
		void update()
		{
			if ( !m_bIsValid )
			{
				CaMuiSelect* pOuter = (CaMuiSelect*)((char*)this-offsetof(CaMuiSelect, m_AdapteeIndexCache) ) ;

				m_contAdapteeIndex.clear() ;
				for ( int i = 0 ; i < (int)pOuter->m_contSelect.size() ; i ++ )
				{
					if ( pOuter->m_contSelect[i] )
					{
						m_contAdapteeIndex.push_back( i ) ; 
					}
				}

				m_bIsValid = true ;
			}
		}
	public:
		/**
		@return 
			indexToAdapteeIndex() の結果のキャッシュです。
			thisのインデクスを添字、Adapteeのインデクスを要素に持つ
			配列です。

			thisが無効の場合、m_contAdapteeIndex を更新して、
			thisを有効にします。
		*/
		const std::vector<int>& getAdapteeIndex()
		{
			update() ;
			return m_contAdapteeIndex ;
		};
		/**
			キャッシュを無効にします。
		*/
		void invalidate()
		{
			m_bIsValid = false ;
		};

	} ;
	friend class CAdapteeIndexCache ;
	mutable CAdapteeIndexCache m_AdapteeIndexCache ;

	///@}
	#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/



protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
		m_contSelect を、m_pAdaptee の要素数にあわせて初期化します。
		要素の選択状態は、すべて 非選択 となります。
	*/
	void initSelect()
	{
		m_contSelect.resize( (unsigned)( m_pAdapteeMu->size() ) ) ;
		fill( m_contSelect.begin() , m_contSelect.end() , false ) ;
	}

	///@}


	
 public:
	// ********************************
	///@name Mu
	// ********************************
	///@{
	/**
	 @return
	 	コンテナに格納されているデータの個数を返します。
	 	
	 	選択されているデータの個数を返します。
	*/
	virtual int	size()const
	{
#if ( CaMuiSelect_ALGORITHM >= 1 )
		return (int)m_AdapteeIndexCache.getAdapteeIndex().size() ;
#else /*( CaMuiSelect_ALGORITHM >= 1 )*/
		int iRv = 0 ; 

		for ( int idx = 0 ; idx < (int)m_contSelect.size() ; idx ++ )
		{
			if ( m_contSelect[idx] )
			{
				iRv ++ ;
			}
		}
		return iRv ;
#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
	} ;


	

	/**
 	  コンテナ内の、インデクスで指定された場所に格納されている
 	要素を返します。

	@param idx [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 未満です。
		INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	インデクスで指定された要素を返します。
	*/
	virtual ElementType1 get( int idx )const 
	{
		if ( idx == INT_MAX )
		{
			idx = size() -1 ; 
		}

		int iAdapteeIndex = indexToAdapteeIndex( idx ) ;
		if ( iAdapteeIndex >= 0 )
		{
			return ( m_pAdapteeMu->get( iAdapteeIndex ) ) ;
		}
		return ( *( (ElementType1*)NULL ) ) ;
	};
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

	@note
		要素を追加した場合、その要素は最初から選択状態になります。

	@note
		要素0(選択要素が１つもない)のコンテナへ追加を行った場合、
		その要素は、iIndex の指定によって、m_pAdaptee(選択対象コンテナ)の以下の位置に追加されます。
		- 0 : 要素は、m_pAdaptee(選択対象コンテナ)の先頭に追加されます。
		- INT_MAX : 要素は、m_pAdaptee(選択対象コンテナ)の末尾に追加されます。
	@attention
		 m_pAdapteeMui に、有効なインターフェースが設定されていない
		場合、このメソッドは動作しません。
	*/
	virtual int insert( const ElementType1& element , int iIndex = INT_MAX ) 
	{
		int iRv = 0 ; 
		int iContSize = size() ;
		// --------------------------------
		//	パラメータの検証
		// --------------------------------
		if ( iContSize == 0 && iIndex == INT_MAX )
		{
			//	コンテナ要素0(選択要素が１つもない)で、
			//	指定が INT_MAX の場合は、m_pAdaptee(選択対象コンテナ)の
			//	末尾に追加されます。
		}
		else
		{
			if ( iIndex == INT_MAX )
			{
				iIndex =iContSize ;
			}
			if ( !( 0 <= iIndex && iIndex <=iContSize ) )
			{
				iRv = -1 ;	//	引数が不正です。
			}
		}
		

		// --------------------------------
		//	m_pAdaptee への操作
		//	m_contSelect への操作
		// --------------------------------
		if ( iRv >= 0 )
		{ 
			int iAdapteeIndex = -1 ;

			//	選択要素が全くないコンテナへの追加
			if ( iContSize == 0 )	
			{
				if ( iIndex == INT_MAX )
				{
					//	- INT_MAX : 要素は、m_pAdaptee(選択対象コンテナ)の末尾に追加されます。
					iAdapteeIndex = m_pAdapteeMui->size() ;
				}
				else
				{
					//	- 0 : 要素は、m_pAdaptee(選択対象コンテナ)の先頭に追加されます。
					iAdapteeIndex = 0 ; 
				}
			}
			//	選択要素があるコンテナの、末尾要素への追加は、
			//	末尾の次の位置に追加します。
			else if ( iIndex == iContSize )
			{
				iAdapteeIndex =indexToAdapteeIndex( iContSize - 1 ) + 1 ;
			}
			//	その他の位置への追加は、
			//	指定の要素の直前に追加します。
			else
			{
				iAdapteeIndex = indexToAdapteeIndex( iIndex ) ;
			}

			m_pAdapteeMui->insert( element , iAdapteeIndex ) ; 
			m_contSelect.insert( m_contSelect.begin() + iAdapteeIndex , true ) ;

			#if ( CaMuiSelect_ALGORITHM >= 1 )
			//	m_contSelectの内容・Adapteeの要素数が変更されると、
			//	m_AdapteeIndexCache は無効になります。
			//	insert(),erase(),setSelect() 操作がこれにあたります。
			m_AdapteeIndexCache.invalidate() ;
			#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		}


		return ( iRv ) ; 
	}
	
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
	@attention
		 m_pAdapteeMui に、有効なインターフェースが設定されていない
		場合、このメソッドは動作しません。
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) 
	{
		int iRv = 0 ; 
		int iContSize = size() ;
		// --------------------------------
		//	パラメータの検証
		// --------------------------------
		if ( iRv >= 0 )
		{
			if ( iIndex == INT_MAX && iSize == INT_MAX )
			{
				iRv = -1 ;	//	iIndex が不正
			}
		}
		if ( iRv >= 0 )
		{
			if ( iIndex == INT_MAX )
			{
				iIndex = iContSize- iSize ;
			}
			if ( iSize == INT_MAX )
			{
				iSize = iContSize- iIndex ;
			}
			if ( !( 0 <= iIndex && iIndex + iSize <= iContSize ) )
			{
				iRv = -1 ;	//	iIndex が不正
			}
		}
		// --------------------------------
		//	m_pAdaptee への操作
		//	m_contSelect への操作
		// --------------------------------

		if ( iRv >= 0 )
		{ 
			for ( int i = iSize - 1  ; iRv >= 0 && i >= 0  ; i -- )
			{
				int iAdapteeIndex = indexToAdapteeIndex( iIndex+i ) ;
				m_pAdapteeMui->erase( iAdapteeIndex ) ; 
				m_contSelect.erase( m_contSelect.begin() + iAdapteeIndex ) ;
			}


			#if ( CaMuiSelect_ALGORITHM >= 1 )
			//	m_contSelectの内容・Adapteeの要素数が変更されると、
			//	m_AdapteeIndexCache は無効になります。
			//	insert(),erase(),setSelect() 操作がこれにあたります。
			m_AdapteeIndexCache.invalidate() ;
			#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		}
		return ( iRv ) ; 
	}
	
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
	@attention
		 m_pAdapteeMui に、有効なインターフェースが設定されていない
		場合、このメソッドは動作しません。
	*/
	virtual int set( const ElementType1& element , int iIndex ) 
	{
		int iRv = 0 ; 
		int iContSize = size() ;
		// --------------------------------
		//	パラメータの検証
		// --------------------------------
		if ( iRv >= 0 )
		{
			if ( iIndex == INT_MAX )
			{
				iIndex = iContSize- 1 ;
			}
			if ( !( 0 <= iIndex && iIndex < iContSize ) )
			{
				iRv = -1 ;	//	iIndex が不正
			}
		}
		// --------------------------------
		//	m_pAdaptee への操作
		//	m_contSelect への操作
		// --------------------------------

		if ( iRv >= 0 )
		{ 
			{
				int iAdapteeIndex = indexToAdapteeIndex( iIndex ) ;
				m_pAdapteeMui->set( element , iAdapteeIndex ) ; 
			}
		}
		return ( iRv ) ; 
	}
	///@}
	
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
		デフォルトコンストラクタ
	*/
	CaMuiSelect() : 
		m_pAdapteeMu( NULL ) , 
		m_pAdapteeMui( NULL ) , 
		m_pAdapteeMuConstPtr( NULL ) ,  
		m_pAdapteeMuPtr( NULL ) 
	{
	};

	/**
	@param pAdapteeMu [in]
		操作対象オブジェクトとなるコンテナ(Adaptee)の、 
		Mu<ElementType1>インターフェースです。
	*/
	CaMuiSelect( Mu<ElementType1>* pAdapteeMu ) : 
		m_pAdapteeMu( pAdapteeMu ) , 
		m_pAdapteeMui( NULL ) , 
		m_pAdapteeMuConstPtr( NULL ) ,  
		m_pAdapteeMuPtr( NULL ) 
	{
		initSelect() ;
	};
	/**
	@param pAdapteeMui [in]
		操作対象オブジェクトとなるコンテナ(Adaptee)の、 
		Mui<ElementType1>インターフェースです。
	*/
	CaMuiSelect( Mui<ElementType1>* pAdapteeMui ) : 
		m_pAdapteeMu( pAdapteeMui ) ,
		m_pAdapteeMui( pAdapteeMui ) ,
		m_pAdapteeMuConstPtr( NULL ) ,  
		m_pAdapteeMuPtr( NULL ) 
	{
		initSelect() ;
	};
	/**
	@param pAdapteeMu [in]
		操作対象オブジェクトとなるコンテナ(Adaptee)の、 
		Mu<ElementType1>インターフェースです。
	@param pAdapteeMuConstPtr [in]
		操作対象オブジェクトとなるコンテナ(Adaptee)の、 
		const Mu<const ElementType1*>* インターフェースです。
		
	*/
	CaMuiSelect( Mu<ElementType1>* pAdapteeMu , 
		const Mu<const ElementType1*>* pAdapteeMuConstPtr ) : 
		m_pAdapteeMu( pAdapteeMu ) ,
		m_pAdapteeMui( NULL ) , 
		m_pAdapteeMuConstPtr( pAdapteeMuConstPtr ) 
		m_pAdapteeMuPtr( NULL ) 
	{
		initSelect() ;
	};
	/**
	@param pAdapteeMui [in]
		操作対象オブジェクトとなるコンテナ(Adaptee)の、 
		Mui<ElementType1>インターフェースです。
	@param pAdapteeMuPtr [in]
		操作対象オブジェクトとなるコンテナ(Adaptee)の、 
		Mu<ElementType1*>* インターフェースです。
		
	*/
	CaMuiSelect( Mui<ElementType1>* pAdapteeMui , 
		Mu<ElementType1*>* pAdapteeMuPtr ) : 
		m_pAdapteeMu( pAdapteeMui ) ,
		m_pAdapteeMui( pAdapteeMui ) , 
		m_pAdapteeMuConstPtr( NULL ) ,
		m_pAdapteeMuPtr( pAdapteeMuPtr ) 
	{
		initSelect() ;
	};
	
private:
	//	コピーは禁止
	CaMuiSelect( const CaMuiSelect& value )
	{
		assert( false ) ;
	}
	CaMuiSelect& operator=( const CaMuiSelect& value )
	{
		assert( false ) ;
		return *this ;
	}
public:
	// ********************************
	///@name CaMuiSelect-関連
	// ********************************
	///@{
	Mu<ElementType1>*	getAdapteeMu(){	return m_pAdapteeMu ;};
	const Mu<ElementType1>*	getAdapteeMu()const{	return m_pAdapteeMu ;};
	Mui<ElementType1>*	getAdapteeMui(){	return m_pAdapteeMui ;};
	const Mui<ElementType1>*	getAdapteeMui()const{	return m_pAdapteeMui ;};

	const Mu<const ElementType1*>*	getAdapteeMuConstPtr()const{	return m_pAdapteeMuConstPtr ;};
	Mu<ElementType1*>*	getAdapteeMuPtr()const{	return m_pAdapteeMuPtr ;};
	
	/**
	操作対象のコンテナを変更します。
	このとき、すべての要素は非選択となります。
	*/
	CaMuiSelect<ElementType1>& setAdaptee( Mu<ElementType1>* pAdapteeMu ) 
	{
		m_pAdapteeMu =  pAdapteeMu ; 
		m_pAdapteeMui =  NULL ;
		m_pAdapteeMuConstPtr = NULL ;  
		m_pAdapteeMuPtr = NULL ;

		#if ( CaMuiSelect_ALGORITHM >= 1 )
		m_AdapteeIndexCache.invalidate() ; 
		#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/

		initSelect() ;
		return *this ;
	};


	/**
	操作対象のコンテナを変更します。
	このとき、すべての要素は非選択となります。
	*/
	CaMuiSelect<ElementType1>& setAdaptee( Mui<ElementType1>* pAdapteeMui ) 
	{
		m_pAdapteeMu =  pAdapteeMui ;
		m_pAdapteeMui =  pAdapteeMui ;
		m_pAdapteeMuConstPtr = NULL ;  
		m_pAdapteeMuPtr =  NULL ;
		#if ( CaMuiSelect_ALGORITHM >= 1 )
		m_AdapteeIndexCache.invalidate() ; 
		#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		initSelect() ;
		return *this ;
	};

	/**
	操作対象のコンテナを変更します。
	このとき、すべての要素は非選択となります。
	*/
	CaMuiSelect<ElementType1>& setAdaptee( 
			Mu<ElementType1>* pAdapteeMu , 
			const Mu<const ElementType1*>* pAdapteeMuConstPtr ) 
	{
		m_pAdapteeMu = pAdapteeMu ;
		m_pAdapteeMui =  NULL ; 
		m_pAdapteeMuConstPtr = pAdapteeMuConstPtr ; 
		m_pAdapteeMuPtr = NULL ;
		#if ( CaMuiSelect_ALGORITHM >= 1 )
		m_AdapteeIndexCache.invalidate() ; 
		#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		initSelect() ;
		return *this ;
	};
	/**
	操作対象のコンテナを変更します。
	このとき、すべての要素は非選択となります。
	*/
	CaMuiSelect<ElementType1>& setAdaptee(  
		Mui<ElementType1>* pAdapteeMui , 
		Mu<ElementType1*>* pAdapteeMuPtr ) 
	{
		m_pAdapteeMu = pAdapteeMui ;
		m_pAdapteeMui = pAdapteeMui ; 
		m_pAdapteeMuConstPtr =  NULL ;
		m_pAdapteeMuPtr = pAdapteeMuPtr ; 
		#if ( CaMuiSelect_ALGORITHM >= 1 )
		m_AdapteeIndexCache.invalidate() ; 
		#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		initSelect() ;
		return *this ;
	};

	///@}
	// ********************************
	///@name CaMuiSelect-包含
	// ********************************
	///@{
	/**
	@return
		現在選択されている要素への、 Mu<const ElementType*> 
		インターフェースを返します。
		但し、 m_pAdapteeMuConstPtr に、有効なインターフェースが設定
		されている必要があります。
	@attention
		 m_pAdapteeMuPtr・m_pAdapteeMuConstPtr のいずれかに、
		 有効なインターフェースが設定されている必要があります。
	*/
	const Mu<const ElementType1*>* getMuPtr()const 
	{
		if ( m_pAdapteeMuPtr == NULL && m_pAdapteeMuConstPtr == NULL )
		{
			return NULL ;
		}
		return &m_XMuConstPtr ;
	}
	
	/**
	@return
		現在選択されている要素への、 Mu<ElementType*> 
		インターフェースを返します。
		但し、 m_pAdapteeMuPtr に、有効なインターフェースが設定
		されている必要があります。
	@attention
		 m_pAdapteeMu に、
		 有効なインターフェースが設定されている必要があります。
	*/
	Mu<ElementType1*>* getMuPtr() 
	{
		if ( m_pAdapteeMuPtr == NULL )
		{
			return NULL ;
		}
		return &m_XMuPtr ;
	}
	
	///@}
	// ********************************
	///@name CaMuiSelect-属性
	// ********************************
	///@{
	/**
	  要素の選択状態を取得します。
	@param idx [in]
		0から始まるインデクス番号を指定してください。
	@return
		true は 選択、false は非選択です。
	*/
	virtual bool getSelect( int idx )const
	{
		bool bRv = false ;
		if ( 0 <= idx && idx < (int)m_contSelect.size() )
		{
			bRv = m_contSelect[idx] ;
		}
		return bRv ;
	}
	/**
	  要素の選択状態を設定します。
	@param idx
		0から始まるインデクス番号を指定してください。
	@param bSelect
		true は 選択、false は非選択です。
	*/
	virtual CaMuiSelect<ElementType1>& setSelect( int idx , bool bSelect )
	{
		if ( 0 <= idx && idx < (int)m_contSelect.size() )
		{
			 m_contSelect[idx] = bSelect;

			#if ( CaMuiSelect_ALGORITHM >= 1 )

				//	m_contSelectの内容・Adapteeの要素数が変更されると、
				//	m_contAdapteeIndex の内容は無効になります。
				//	この場合は、キャッシュを明示的に無効にする必要があります。
				//	insert(),erase(),setSelect() 操作がこれにあたります。
				m_AdapteeIndexCache.invalidate() ; 

			#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		}

		return *this ;
	}

	/**
	  すべての要素の選択状態を設定します。
	@param bSelect
		true は 選択、false は非選択です。
	*/
	virtual CaMuiSelect<ElementType1>& setSelectAll( bool bSelect )
	{
		for ( int idx = 0 ; idx < (int)m_contSelect.size() ; idx ++ )
		{
			 m_contSelect[idx] = bSelect;

			#if ( CaMuiSelect_ALGORITHM >= 1 )

				//	m_contSelectの内容・Adapteeの要素数が変更されると、
				//	m_contAdapteeIndex の内容は無効になります。
				//	この場合は、キャッシュを明示的に無効にする必要があります。
				//	insert(),erase(),setSelect() 操作がこれにあたります。
				m_AdapteeIndexCache.invalidate() ; 

			#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
		}

		return *this ;
	}


	///@}


	// ********************************
	///@name CaMuiSelect-操作
	// ********************************
	///@{
	/**
	  this のインデクスに対応する要素の、m_pAdapteeMu 内でのインデクスを
	返します。
	@param iThisIndex
		this 上でのインデクスを指定してください。
	@return 
		m_Adaptee 内でのインデクスを返します。
		対応する要素がない場合は、-1 です。

		m_Adaptee が   { "zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" } @n
		m_contSelect が{ true  , false , false , false    , true   , false  , true  , false }  @n
		の場合、  indexToAdapteeIndex(0)=0,indexToAdapteeIndex(1)=4,indexToAdapteeIndex(2)=6 となります。

		
	*/
	int indexToAdapteeIndex( int iThisIndex )const 
	{
#if ( CaMuiSelect_ALGORITHM >= 1 )
		int iRv = -1 ;
		const std::vector<int>& contAdapteeIndex = m_AdapteeIndexCache.getAdapteeIndex() ;
		if ( 0 <= iThisIndex && iThisIndex < (int)contAdapteeIndex.size() )
		{
			iRv = contAdapteeIndex[iThisIndex] ;
		}
		return iRv ;
#else /*( CaMuiSelect_ALGORITHM >= 1 )*/
		int iRv = -1;
		int iSelectedCount = 0 ; 
		if ( 0 <= iThisIndex )
		{
			for ( int iAdapteeIndex = 0 ; iRv == -1 && iAdapteeIndex < (int)m_contSelect.size() ; iAdapteeIndex ++ )
			{
				if ( m_contSelect[iAdapteeIndex] )
				{
					iSelectedCount ++ ;
				}
				if ( iSelectedCount > iThisIndex )
				{
					iRv = iAdapteeIndex ;
				}
			}
		}
		return iRv ;
#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
	}
	/**
	  m_Adaptee 内のインデクスを、に対応する要素の、
	this のインデクスを返します。
	@param iAdapteeIndex
		this 上でのインデクスを指定してください。
	@return 
		m_Adaptee 内でのインデクスを返します。
		対応する要素がない場合は、-1 です。

		m_Adaptee が   { "zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" } @n
		m_contSelect が{ true  , false , false , false    , true   , false  , true  , false }  @n
		の場合、  indexFromAdapteeIndex(0)=0,indexFromAdapteeIndex(4)=2 ,indexFromAdapteeIndex(6)=3 となります。
		その他の引数で呼び出された場合は、戻り値は -1 となります。
	*/
	int indexFromAdapteeIndex( int iAdapteeIndex )const 
	{
#if ( CaMuiSelect_ALGORITHM >= 1 )
		int iRv = -1 ;
		const std::vector<int>& contAdapteeIndex = m_AdapteeIndexCache.getAdapteeIndex() ;
		if ( 0 <= iAdapteeIndex && iAdapteeIndex < (int)m_contSelect.size() && m_contSelect[iAdapteeIndex] )
		{

			//for ( int iThisIndex = 0 ; iRv == -1 && iThisIndex < (int)contAdapteeIndex.size() ; iThisIndex ++ )
			//{
			//	if ( contAdapteeIndex[iThisIndex] == iAdapteeIndex )
			//	{
			//		iRv = iThisIndex ;
			//	}
			//}

			std::vector<int>::const_iterator ite = std::lower_bound( 
				contAdapteeIndex.begin() , 
				contAdapteeIndex.end() ,
				iAdapteeIndex ) ;
			iRv = std::distance( contAdapteeIndex.begin() , ite ) ;

		}
		return iRv ;
#else /*( CaMuiSelect_ALGORITHM >= 1 )*/
		int iRv = -1 ;
		int iSelectedCount = 0 ; 
		if ( 0 <= iAdapteeIndex && iAdapteeIndex < (int)m_contSelect.size() && m_contSelect[iAdapteeIndex] )
		{
			int idx = 0 ;
			for (  idx = 0 ; idx < (int)m_contSelect.size() && idx < iAdapteeIndex ; idx ++ )
			{
				if ( m_contSelect[idx] )
				{
					iSelectedCount ++ ;
				}
			}
			//iSelectedCount = iAdapteeIndex 以前で、true の数。

			iRv = iSelectedCount ;
		}
		return iRv ;
#endif /*( CaMuiSelect_ALGORITHM >= 1 )*/
	}
	///@}
};

#ifndef NO_NSMU
} //namespace NsMu
#endif//NO_NSMU

} //namespace OuLib

#endif /*Mu_CaMuiSelect_h*/


