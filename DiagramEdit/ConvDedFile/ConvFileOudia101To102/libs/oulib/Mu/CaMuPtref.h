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
//	CaMuPtref.h
//	$Id: CaMuPtref.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  Mu_CaMuPtref_h
#define  Mu_CaMuPtref_h
#include "./Mu.h"
// ****************************************************************
//	CaMuPtref.h
// ****************************************************************
/**
 @brief
 【概要】
   アダプタクラスです。
	ポインタ型を要素にするコンテナオブジェクトを操作対象とし、
	操作対象の "Mu< PtrType >"  インターフェースを、
	値・または参照型を要素とする "Mu< ValueType > 
	インターフェースに変換します。
 
   このクラスの用途は、主に以下のような場合です
 （ CBase は、コンテナに格納するクラスの例です）。
 
 ◎  オブジェクトのポインタが格納されている 、
  Mu< CBase* > インターフェースをサポートしたコンテナを
 他のオブジェクトに操作させる場合、他のオブジェクトには
  "Mu< CBase >" を渡したい。
 
@code
	CaCont_vector< vector< CBase* > >	aCaCont_vector_ptr ;
	CaMuPtref< CBase , CBase* > aCaMuPtref( &aCaCont_vector_ptr ) ;
	//aCaMuPtref = Mu< CBase > をサポートしています。
	//	このインターフェースにより、aCaCont_vector_ptr が保持している
	//	ポインタ要素の参照先の値を参照することができます
	//	（値なので変更は不可）。
@endcode
 
 ◎  オブジェクトのポインタが格納されている 、
  Mu< CBase* > インターフェースをサポートしたコンテナを
 他のオブジェクトに操作させる場合、他のオブジェクトには
  "Mu< const CBase& >" を渡したい。
 
@code
	CaCont_vector< vector< CBase* > >	aCaCont_vector_ptr ;
	CaMuPtref< const CBase& , CBase* > aCaMuPtref( &aCaCont_vector_ptr ) ;
	//aCaMuPtref = Mu< const CBase& > をサポートしています。
	//	このインターフェースにより、aCaCont_vector_ptr が保持している
	//	ポインタ要素のオブジェクトのconst参照を取得することができます。
	//	（constなので変更は不可）。
@endcode
 
 @param ValueType
	変換後の要素の型を指定してください。
	この型は、値型・もしくは参照型を指定してください。
	このクラスは、 "Mu< DataType1 >" インターフェースを
	サポートします。
 @param PtrType
	操作対象オブジェクト m_pAdaptee が格納している要素の型を
	指定してください。
	この型は、ポインタ型でなくてはなりまん。
 */
template < class ValueType  , class PtrType > class CaMuPtref : 
	public Mu< ValueType > 
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
	Mu<PtrType>*	m_pAdaptee ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CaMuPtref( Mu<PtrType>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ){};
private:
	///	コピーは禁止
	CaMuPtref( const CaMuPtref& value )
	{
		assert( false ) ;
	}
	///	コピーは禁止
	CaMuPtref& operator=( const CaMuPtref& value )
	{
		assert( false ) ;
		return *this ;
	}
public:
	
	
public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	/**
	 @return
	 	コンテナに格納されている要素の個数を返します。
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
	virtual ValueType get( int idx )const 
	{
		ValueType	pRv = 
			static_cast<ValueType>( *( m_pAdaptee->get( idx ) ) ) ;
		return ( pRv ) ;
	};
	
	///@}
public:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	Mu<PtrType>*	getAdaptee(){	return m_pAdaptee ;};
	const Mu<PtrType>*	getAdaptee()const{	return m_pAdaptee ;};
	CaMuPtref<ValueType,PtrType>& setAdaptee( Mu<PtrType>*	value )
	{
		m_pAdaptee = value ; 	return *this ;
	};
	///@}
};

#endif /*Mu_CaMuPtref_h*/


