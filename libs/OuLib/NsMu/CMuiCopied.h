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
// ****************************************************************
// $Id: CMuiCopied.h 379 2016-11-16 21:20:43Z okm $
// ****************************************************************
/** @file */
#ifndef Mu_CMuiCopied_h
#define Mu_CMuiCopied_h

#include <deque>
#include "./Mui.h"

namespace OuLib{

#ifndef NO_NSMU
namespace NsMu{
#endif//NO_NSMU

// ****************************************************************
// CMuiCopied
// ****************************************************************
/**
@brief
　ElementType クラスのオブジェクトを保持するコンテナです。

　あるクラスの複数のオブジェクトを配列形式のコンテナで保持し、
そのコンテナ内のオブジェクトに対してメソッドを呼び出すような場面において、
利便性を示します。

　このコンテナは、要素追加時(insert(),set())に、指定されたオブジェクト
のコピーをnew演算子とコピーコンストラクタで生成し、そのアドレスを
コンテナに保持します。コンテナに保持するのはオブジェクトの実体ではなく
ポインタですので、コンテナの中間への要素の追加・削除は高速で行われます。
　また、コンテナ内のオブジェクトは、コンテナから削除されるまで、アドレスが変化しません。

　getMuPtr() メソッドを使うことにより、コンテナ内のオブジェクトのアドレスを
取得することができます。これによって、コンテナ内のオブジェクトのメソッドを呼び出して、
その状態を変化させることができます。

　このコンテナは ElementType クラスの派生クラスのオブジェクトを保持することはできません。
　このようまことを行う場合は、CMup_deque に Ou を格納するほうが便利です。

@param ElementType
	コンテナに格納する要素の型を指定してください。
@param ContType
	ElementType* を保持するSTLコンテナを指定してください。
	規定では std::deque ですが、 std::vector を使うこともできます。
*/
template < class ElementType , class ContType =std::deque<ElementType*> >
class CMuiCopied : public Mui<ElementType>
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	/**
		このクラスが独自にthrow する例外です。以下の場合に発生します。
		- operator= が失敗
	*/
	class LException
	{
	};


	// ****************************************************************
private:
	// ********************************
	///@name 集約
	// ********************************
	///@{
	/**
		ElementType を new で生成したインスタンスを保持するコンテナです。
		このコンテナが保持するインスタンスの破棄の責務は this にあります。
	*/
	ContType	m_Cont ;
	///@}

private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
	 @brief
		CMuiCopied::getMuPtr() メソッドが返す
		Mu< ElementType* > インターフェースを
		実装したクラスです。
	 */
	class XMuPtr : public Mu< ElementType* >
	{
	public:
		virtual int	size()const
		{
			CMuiCopied* pOuter = (CMuiCopied*)((char*)this - offsetof(CMuiCopied,m_xMuPtr) ) ;
			return (int)( pOuter->m_Cont.size() ); 
		} ;
		virtual ElementType* get( int idx )const 
		{
			CMuiCopied* pOuter = (CMuiCopied*)((char*)this - offsetof(CMuiCopied,m_xMuPtr) ) ;
			if ( idx == INT_MAX )
			{
				idx = (int)( pOuter->m_Cont.size() - 1 );
			}
			ElementType*	pRv = pOuter->m_Cont[idx] ;
			return ( pRv ) ;
		};
	}	m_xMuPtr ;
	friend class XMuPtr ;

	/**
	 @brief
		CMuiCopied::getMuPtr()const メソッドが返す
		Mu< const ElementType* > インターフェースを
		実装したクラスです。
	 */
	class XMuConstPtr : public Mu< const ElementType* >
	{
	public:
		virtual int	size()const
		{
			CMuiCopied* pOuter = (CMuiCopied*)((char*)this - offsetof(CMuiCopied,m_xMuConstPtr) ) ;
			return (int)( pOuter->m_Cont.size() ); 
		} ;
		virtual const ElementType* get( int idx )const 
		{
			CMuiCopied* pOuter = (CMuiCopied*)((char*)this - offsetof(CMuiCopied,m_xMuConstPtr) ) ;
			if ( idx == INT_MAX )
			{
				idx = (int)( pOuter->m_Cont.size() ) - 1 ;
			}
			ElementType*	pRv = pOuter->m_Cont[idx] ;
			return ( pRv ) ;
		};
	}	m_xMuConstPtr ;
	friend class XMuConstPtr ;


	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	  空コンテナを生成します。
	*/
	CMuiCopied(){} ; 
	/**
	  コピーコンストラクタ
	*/
	CMuiCopied( const CMuiCopied<ElementType,ContType>& value )
	{
		//	要素を複製
		for ( int idx = 0 ; idx < value.size() ; idx ++ )
		{
			m_Cont.push_back( new ElementType( *value.getMuPtr()->get( idx ) ) ) ;
		}
	};

	/**
	  代入演算子
	@exception LException
		代入が失敗したときに throw されます。
	*/
	CMuiCopied& operator=( const CMuiCopied<ElementType,ContType>& value ) 
	{

		// set(),insert(),erase() の組み合わせで実現
		{
			const Mu<const ElementType*>* muValue = value.getMuPtr() ;
			int i ; 
			//	置き換え
			for ( i = 0 ; i < size() && i < muValue->size()  ; i ++ )
			{
				int iResult = set( *muValue->get( i )  , i ) ; 
				if ( iResult < 0 )
				{
					throw( LException() ) ;
				}
			}
			//  挿入
			for (  ; i < value.size()  ; i ++ )
			{
				int iResult = insert( *muValue->get( i ) ) ; 
				if ( iResult < 0 )
				{
					throw( LException() ) ;
				}
			}
			// 削除
			while(  size() > value.size() )
			{
				int iResult = erase( INT_MAX ) ;
				if ( iResult < 0 )
				{
					throw( LException() ) ;
				}
			}
		}
		return *this ;
	};
	virtual ~CMuiCopied()
	{
		//	すべての要素を破棄
		while ( m_Cont.size() > 0 )
		{
			ElementType* p = m_Cont.back() ;
			delete p ;
			m_Cont.pop_back() ;
		}
	} ; 
public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	
	/**
	 @return
	 	コンテナに格納されている要素の個数を返します。
	*/
	virtual int	size()const{	return (int)m_Cont.size() ;};
	/**
	 	コンテナ内の、インデクスで指定された場所に格納されている
	 	要素のコピーを返します。
	 @param iIndex [in]
	 	0 から始まるインデクスを指定してください。
	 	範囲は 0 以上 size() 未満です。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	インデクスで指定された要素を返します。
	*/
	virtual ElementType get( int iIndex )const
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_Cont.size() - 1 ;
		}
		ElementType* p = m_Cont[iIndex] ;
		return *p ;
	};
	///@}
public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素のコピーを追加します。
	 @param element [in]
	 	要素を指定してください。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 以下です。
	 	０は、先頭・size()なら末尾への追加になります。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	0以上は成功、負の数はエラーです
	*/
	virtual int insert( const ElementType& element , int iIndex = INT_MAX ) 
	{
		int iRv = 0 ;
		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_Cont.size() ;
		}
		// --------------------------------	
		if ( !( 0 <= iIndex && iIndex <= (int)m_Cont.size() ) )
		{
			iRv = -1 ;	//	インデクスが範囲外です。
		}
		else
		{
			m_Cont.insert( 
				m_Cont.begin() + iIndex , 
				new ElementType( element ) ) ;
		}
		// --------------------------------	
		return iRv ;
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
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) 
	{
		int iRv = 0 ;
		if ( iIndex == INT_MAX && iSize != INT_MAX )
		{
			iIndex = (int)m_Cont.size() - iSize ;
		}
		else if ( iIndex != INT_MAX && iSize == INT_MAX )
		{
			iSize = (int)m_Cont.size() - iIndex ;
		}
		// --------------------------------	
		if ( !( 0 <= iIndex && iIndex + iSize <= (int)m_Cont.size() ) )
		{
			iRv = -1 ;	//	インデクスが範囲外です。
		}
		else
		{
			//	指定の要素を破棄
			while ( iSize > 0 )
			{
				iSize -- ;
				ElementType* p = m_Cont[iIndex+iSize] ;
				delete p ;
				m_Cont.erase( m_Cont.begin() + iIndex + iSize );
			}
		}
		// --------------------------------	
		return iRv ;
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
	*/
	virtual int set( const ElementType& element , int iIndex ) 
	{
		int iRv = 0 ;
		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_Cont.size() - 1 ;
		}
		// --------------------------------	
		if ( !( 0 <= iIndex && iIndex < (int)m_Cont.size() ) )
		{
			iRv = -1 ;	//	インデクスが範囲外です。
		}
		else
		{
			//	指定の要素を代入で更新
			ElementType* p = m_Cont[iIndex] ;
			delete p ;
			m_Cont[iIndex] = new ElementType( element ) ;
		}
		// --------------------------------	
		return iRv ;
	}
	///@}
public:
	// ********************************
	///@name CMuiCopied
	// ********************************
	///@{
	/**
		コンテナ内のインスタンスにアクセスできる 
		 Mu<ElementType*> 
		 インターフェースを返します。
	*/
	virtual Mu<ElementType*>* getMuPtr()
	{	return &m_xMuPtr ;};
	
	/**
		コンテナ内のインスタンスにアクセスできる 
		Mu<const ElementType*>
		インターフェースを返します。
	*/
	virtual const Mu<const ElementType*>* getMuPtr()const 
	{	return &m_xMuConstPtr ;};
	
	
	///@}
};

#ifndef NO_NSMU
} //namespace NsMu
#endif//NO_NSMU

} //namespace OuLib


#endif //Mu_CMuiCopied_h

