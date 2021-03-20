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
//	CaMuCast.h
//	$Id: CaMuCast.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  Mu_CaMuCast_h
#define  Mu_CaMuCast_h
#include "./Mu.h"
// ****************************************************************
//	CaMuCast.h
// ****************************************************************
/**
   @brief
   【概要】
     アダプタクラスです。
  	"Mu< ElementType2 >" 型のコンテナオブジェクトを操作対象とし、
  	操作対象の Mu< ElementType2 >" インターフェースを、
  	Mu< ElementType1 >" インターフェースに変換します。
  
  	このクラスの get() メソッドは、操作対象 ( m_pAdaptee ) に格納されている
  	ElementType2 型の要素を、 static_cast<ElementType1> で変換してから
  	返します。
   
     このクラスの用途は、主に以下のような場合です
   （ CBase は、コンテナに格納するクラスの例です）。
   
   ◎  オブジェクトのポインタが格納されている 、
    Mu< CBase* > インターフェースをサポートしたコンテナを
   他のオブジェクトに操作させる場合、他のオブジェクトには
    "Mu< const CBase* >" を渡したい（他のオブジェクトからは、
    CBase を変更させたくない）。
   
@code
	CaCont_vector< vector< CBase* > >	aCaCont_vector_ptr ;
	CaMuCast< const CBase* , CBase* > aCaMuCast( &aCaCont_vector_ptr ) ;
	//aCaMuCast = Mu< const CBase* > をサポートしています。
	//	このインターフェースにより、
	//	コンテナ内のオブジェクトを変更不可能な形で参照することができます。
@endcode
   
     ※  この例では、普通のポインタを使っていますが、同じことを Ou で
   行うことも可能です
  
   ◎  int が格納されている（ Mu< int > インターフェースを
  	サポートした）コンテナを
   他のオブジェクトに参照させる場合、参照する側のオブジェクトに
    "Mu< long > " を渡したい。
   
   
   @param ElementType1
  	キャスト先の要素の型を指定してください。
  	このクラスは、 "Mu< ElementType1 >" インターフェースを
  	サポートします。
   @param ElementType2
  	操作対象オブジェクト m_pAdaptee が格納している要素の型を
  	指定してください。
 */
template < class ElementType1 , class ElementType2 > class CaMuCast : 
	public Mu< ElementType1 > 
{
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		操作対象オブジェクトとなる、コンテナです。
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、thisとの関連が保たれている間は、
		生存しなくてはなりません。
	*/
	Mu<ElementType2>*	m_pAdaptee ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CaMuCast( Mu<ElementType2>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ){};
	
private:
	//	コピーは禁止
	CaMuCast( const CaMuCast& value )
	{
		assert( false ) ;
	}
	CaMuCast& operator=( const CaMuCast& value )
	{
		assert( false ) ;
		return *this ;
	}
	
 public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	/**
	 @return
	 	コンテナに格納されているデータの個数を返します。
	*/
	virtual int	size()const{	return m_pAdaptee->size() ; } ;
	
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
		ElementType1 pRv = static_cast<ElementType1>( m_pAdaptee->get( idx ) ) ;
		return ( pRv ) ;
	};
	///@}
	
public:
	// ********************************
	///@name CaMuCast-関連
	// ********************************
	///@{
	Mu<ElementType2>*	getAdaptee(){	return m_pAdaptee ;};
	const Mu<ElementType2>*	getAdaptee()const{	return m_pAdaptee ;};
	CaMuCast<ElementType1,ElementType2>& setAdaptee( Mu<ElementType2>*	value )
	{
		m_pAdaptee = value ; 	return *this ;
	};
	///@}
};

#endif /*Mu_CaMuCast_h*/


