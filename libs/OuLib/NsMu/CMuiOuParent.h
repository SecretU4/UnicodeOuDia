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
/** @file */
//$Id: CMuiOuParent.h 348 2016-08-16 17:47:55Z okm $
#ifndef  OuLib_NsMu_CMuiOuParent
#define  OuLib_NsMu_CMuiOuParent

#include "CMuiOu.h"
#include "CParentBase.h"

namespace OuLib{
namespace NsMu{


/**
@brief
　ElementType 型のオブジェクトを指す Ou(参照カウンタを使用したスマートポインタ)を保持するコンテナです。『親子コンテナ』パターンの親オブジェクトとして機能します。

@ref parent_child_container

　子オブジェクト(コンテナ内のアイテム)から、親オブジェクト(自身を保持しているコンテナ)にアクセスすることができます。

　このクラステンプレートは、CMuiOu を基本クラスとしています。

　子オブジェクトが親オブジェクト(this)に追加されたとき、親オブジェクトは、子オブジェクトの CChildBase::setParent() メソッドを呼び出して、親オブジェクト(this)のアドレスを子オブジェクトに登録します。このとき渡される親オブジェクトの型は、CParentBase* です。
　子オブジェクトは、CChildBase::getParent() で、親オブジェクトのアドレスを取得できます。CChildBase::getParent() が返す方は CParentBase* です。子オブジェクトは、このアドレスを、実際の親オブジェクト(コンテナ)の型にダウンキャストすることにより、親オブジェクトのメソッドを呼び出すことができます。


@param ElementType
  格納するオブジェクトの型を指定してください。
　ElementTypeは、CChildBase を継承した型でなくてはなりません。
　このパラメーターには、Ouは含めないでください。
@param ContType
  Ou< ElementType > を保持するSTLコンテナを指定してください。
  既定では、std::deque ですが、 std::vector を使うこともできます。
*/
template <
	class ElementType,
	class ContType =std::deque< Ou< ElementType > > >
class CMuiOuParent 
	: public CMuiOu< ElementType , ContType >
 	, public CParentBase

{
public:
	// ********************************
	// コンストラクタ
	// ********************************
	/** デフォルトコンストラクタ */
	CMuiOuParent(){} ; 

	/** 
		コピーコンストラクタ。
		value 内の Ou が指しているオブジェクトを、自身の子アイテムと
		します。
		全ての子アイテムに対して、setParent( this ) を実行します。
	*/
	CMuiOuParent( const CMuiOuParent<ElementType,ContType>& value ) 
		: CMuiOu( value ) 
	{
		//	全ての要素に対して、setParent()を行う
		for ( int idx = 0 ; idx < size() ; idx ++ )
		{
			get( idx )->setParent( this ) ;
		}

		
	}


	/** 
		代入演算子。
		value 内の Ou が指しているオブジェクトを、自身の子アイテムと
		します。
		全ての子アイテムに対して、setParent( this ) を実行します。
	*/
	CMuiOuParent& operator=( const CMuiOuParent<ElementType,ContType>& value ) 
	{
		CMuiOu::operator=( value ) ; 
		
		//	全ての要素に対して、setParent()を行う
		for ( int idx = 0 ; idx < size() ; idx ++ )
		{
			get( idx )->setParent( this ) ;
		}

		return *this ;
	};


	/** 
		デストラクタ
		value 内の Ou が指しているオブジェクトとの親子関係を
		解除します。
		全ての子アイテムに対して、setParent( NULL ) を実行します。
	*/
	virtual ~CMuiOuParent()
	{
		//	全ての要素に対して、setParent()を行う
		for ( int idx = 0 ; idx < size() ; idx ++ )
		{
			get( idx )->setParent( NULL ) ;
		}

	} ; 
public:
	// ********************************
	///@name Mui 
	// ********************************
	///@{
	/**
		コンテナ内の、インデクスで指定された場所に、 要素のコピーを追加します。
		Ouの指すオブジェクトを子アイテムとします。
		子アイテムに対して、setParent( this ) を実行します。
	@param element
		要素を指定してください。 
	@param iIndex
		0 から始まるインデクスを指定してください。 
		範囲は０以上 size() 以下です。 ０は、先頭・size()なら末尾への
		追加になります。 但し、INT_MAX は、末尾を指定したものとみなします。 
	@return
		0以上は成功、負の数はエラーです 
	*/
	virtual int insert( const Ou<ElementType>& element ,  int iIndex=INT_MAX) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = size() ;
		}
		int iRv = CMuiOu< ElementType , ContType >::insert( element , iIndex ) ;
		get( iIndex )->setParent( this ) ;  
		return iRv ;
	}
	/**
		コンテナ内の、インデクスで指定された場所の 要素を削除します。 
		削除する Ou が指しているオブジェクトとの親子関係を
		解除します。
		削除する子アイテムに対して、setParent( NULL ) を実行します。
	@param iIndex
		０から始まるインデクスを指定してください。 範囲は０以上 size() 
		未満です。 但し、INT_MAX は、末尾を指定したものとみなします。 
	@param iSize
		削除する要素の数を指定してください。 但し、INT_MAX は、 
		iIndex から末尾までを表します。 
	@attention
		iIndex と iSize の両方を INT_MAX にすることはできません。 
	@return
		0以上は成功、負の数はエラーです 
	*/
	virtual int erase( int iIndex , int  iSize = 1  ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = size() - 1 ;
		}
		if ( iSize == INT_MAX )
		{
			iSize = size() - iIndex ; 
		}
		for ( int i = 0 ; i < iSize ; i ++ )
		{
			get( iIndex + i )->setParent( NULL ) ; 
		}
		return CMuiOu< ElementType , ContType >::erase( iIndex , iSize ) ;
	}
	/**
		コンテナ内の、インデクスで指定された場所に、 要素を上書きします。 
		上書きされる Ou が指しているオブジェクトとの親子関係を
		解除します。
		新たなOuの指すオブジェクトを子アイテムとします。
		子アイテムに対して、setParent( this ) を実行します。
	@param element
		要素を指定してください。 
	@param iIndex
		 ０から始まるインデクスを指定してください。 
		 範囲は０以上 size() 未満です。 
		 但し、INT_MAX は、末尾を指定したものとみなします。 
	@return
		0以上は成功、負の数はエラーです 
	*/
	virtual int set( const Ou<ElementType>& element , int iIndex ) 
	{
		if ( iIndex == INT_MAX )
		{
			iIndex = size() - 1 ;
		}
		get( iIndex )->setParent( NULL ) ;  
		int iRv = CMuiOu< ElementType , ContType >::set( element , iIndex ) ;
		get( iIndex )->setParent( this ) ; 
		return iRv ;
	}

};

} //namespace NsMu
} //namespace OuLib



#endif //OuLib_NsMu_CMuiOuParent

