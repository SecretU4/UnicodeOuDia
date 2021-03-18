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
//	CMup_vector.h
// ****************************************************************
*/
/** @file */
#ifndef  NsMu_CMup_vector_h
#define  NsMu_CMup_vector_h

#include "NsMu/CaMup_vector.h"
#include <vector>

namespace OuLib{

#ifndef NO_NSMU
namespace NsMu{
#endif//NO_NSMU

// ****************************************************************
//	CMup_vector
// ****************************************************************
/**
 @brief
   STLの std::vector コンテナを包含するコンテナクラスです。
   Mup インターフェースを介した操作を提供します。
 
	コンテナの要素の操作は、 Mup インターフェースメソッドを
	使うことにより実現できます。
	また、 包含している std::vector を直接操作することもできます。
	（getAdaptee() メソッドを使います）。
 
 @see メンバ関数の説明は、 CaMup_vector をご覧ください。
 <H4>
	【コンテナ内の要素のインスタンスについて】
 </H4>
	 コンテナのサイズを変更するメソッドを呼び出した場合、
	コンテナ内のインスタンスの再割り当てが発生します。
  再割り当てが発生すると、getp() で取得したポインタは無効になります。


 @param ElementType
	格納するデータの型を指定してください。
@param ContType
	格納するデータ型 ElementType を保持する std::vector か
	std::deque を指定してください。
*/
template< class ElementType , class ContType = std::vector<ElementType> >
class CMup_vector : public Mup< ElementType >
{
public:

private:	
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		操作対象の、STLランダムアクセスコンテナです。
	
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		操作対象は、この関連が有効な間は生存しなくてはなりません。
	*/
	ContType	m_Adaptee ;
	
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	
public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	/**
	 @return
	 	コンテナに格納されている要素の個数を返します。
	*/
	virtual int	size()const
	{
		return (int)m_Adaptee.size() ; 
	} ;
	
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
		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_Adaptee.size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_Adaptee.size() ) )
		{
			return *( (value_type*)NULL ) ; 
		}
		return m_Adaptee[iIndex] ;
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
			iIndex = (int)m_Adaptee.size() ; 
		}
		if ( !( 0 <= iIndex && iIndex <= (int)m_Adaptee.size() ) )
		{
			return -1 ;	//	iIndexが不正
		}
		m_Adaptee.insert( m_Adaptee.begin() + iIndex , element ) ;
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
	virtual int erase( int iIndex  , int iSize = 1 ) 
	{
		if ( iIndex == INT_MAX && iSize == INT_MAX )
		{
			return -1 ;	//	iIndexが不正
		}
		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_Adaptee.size() - iSize ; 
		}
		if ( iSize == INT_MAX )
		{
			iSize = (int)m_Adaptee.size() - iIndex ; 
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= (int)m_Adaptee.size() ) )
		{
			return -1 ;	//	iIndexが不正
		}
		// --------------------------------
		m_Adaptee.erase( 
			m_Adaptee.begin() + iIndex , 
			m_Adaptee.begin() + iIndex + iSize ) ;
		return ( 0 ) ;
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
		-	-1 ;	//	iIndexが不正
	*/
	virtual int set( const value_type& element , int iIndex ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_Adaptee.size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_Adaptee.size() ) )
		{
			return -1 ;	//	iIndexが不正
		}
		m_Adaptee[iIndex] = element ;
		return ( 0 ) ;
	}
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
			iIndex = (int)m_Adaptee.size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_Adaptee.size() ) )
		{
			return NULL ; 
		}
		return &m_Adaptee[iIndex] ;
	}
	///@}

public:
	// ********************************
	///@name CaMup_vector-関連
	// ********************************
	///@{
	ContType*	getAdaptee(){	return &m_Adaptee ;};
	const ContType*	getAdaptee()const{	return &m_Adaptee ;};
	
	///@}

};

#ifndef NO_NSMU
} //namespace NsMu
#endif//NO_NSMU

} //namespace OuLib

#endif /*NsMu_CMup_vector_h*/
