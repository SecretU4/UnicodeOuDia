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
//	CaMup.h
// ****************************************************************
*/
/** @file */
#ifndef  CaMup_h
#define  CaMup_h

#include "./Mup.h"

namespace OuLib{

#ifndef NO_NSMU
namespace NsMu{
#endif//NO_NSMU

// ****************************************************************
//	CaMup
// ****************************************************************
/**
 @brief
   アダプタクラスです。値を保持するコンテナ 
	"Mup< ElementType >" を操作対象とし、コンテナ内の
	要素へのポインタ・参照を返す "Mu" インターフェースに変換します。
 
 (※  ポインタを保持するコンテナには、このアダプタは使えません)
 
   このアダプタクラスを使うと、以下のインターフェースを取得する
	ことができます。対応するメソッドを呼び出してください。

 	- "Mu< ElementType* >" ・・・ getMuPtr()
 	- "Mu< const ElementType* >" ・・・ getMuConstPtr() 
 	- "Mu< ElementType& >" ・・・ getMuConstRef()
 	- "Mu< const ElementType& >" ・・・ getMuConstRef() 
 
 @param ElementType
	操作対象オブジェクトが格納しているデータの型を指定してください。
	操作対象オブジェクトは、 "Mup<ElementType>" インターフェースを
	サポートします。
	このデータ型は、値型を想定しています
	（ポインタ・参照を格納するコンテナを操作対象にする意味はありません）。
 */
template < class ElementType > class CaMup 
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
	Mup<ElementType>*	m_pAdaptee ;
	///@}

private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	// ********************************
	//	"Mu< ElementType* >" ・・・ getMuPtr()
	// ********************************
	/**
	 @brief
		CaMup::getMuPtr() メソッドが返すインターフェースを
		実装したクラスです。
	 */
	class XMuPtr : public Mu< ElementType* >
	{
	public:
		virtual int	size()const
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuPtr) ) ;
			return pOuter->m_pAdaptee->size() ; 
		} ;
		virtual ElementType* get( int idx )const 
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuPtr) ) ;
			ElementType*	pRv = pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xMuPtr ;
	friend class XMuPtr ;
	//*******************************
	// 	"Mu< const ElementType* >" ・・・ getMuConstPtr() 
	//*******************************
	/**
	 @brief
		CaMup::getMuConstPtr() メソッドが返すインターフェースを
		実装したクラスです。
	 */
	class XMuConstPtr : public Mu< const ElementType* >
	{
	public:
		virtual int	size()const
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuConstPtr) ) ;
			return pOuter->m_pAdaptee->size() ; 
		} ;
		virtual const ElementType* get( int idx )const 
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuConstPtr) ) ;
			ElementType*	pRv = pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xMuConstPtr ;
	friend class XMuConstPtr ;

	// ********************************
	// 	"Mu< ElementType& >" ・・・ getMuRef()
	// ********************************
	/**
	 @brief
		CaMup::getMuRef() メソッドが返すインターフェースを
		実装したクラスです。
	 */
	class XMuRef : public Mu< ElementType& >
	{
	 public:
		virtual int	size()const
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuRef) ) ;
			return pOuter->m_pAdaptee->size() ; 
		} ;
		virtual ElementType& get( int idx )const 
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuRef) ) ;
			ElementType&	pRv = *pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xMuRef ;
	friend class XMuRef ;
	// ********************************
	// 	"Mu< const ElementType& >" ・・・ getMuConstRef() 
	// ********************************
	/**
	 @brief
		CaMup::getMuConstRef() メソッドが返すインターフェースを
		実装したクラスです。
	 */
	class XMuConstRef : public Mu< const ElementType& >
	{
	 public:
		virtual int	size()const
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuConstRef) ) ;
			return pOuter->m_pAdaptee->size() ; 
		} ;
		virtual const ElementType& get( int idx )const 
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuConstRef) ) ;
			ElementType&	pRv = *pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xMuConstRef ;
	friend class XMuConstRef ;

	///@}
// ********************************
//	コンストラクタ
// ********************************
public:
	CaMup() : 
		m_pAdaptee( NULL ) {};
	CaMup( Mup<ElementType>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ) {};
private:
	CaMup( const CaMup<ElementType>& ){};
	CaMup& operator=( const CaMup<ElementType>& ){ return *this ;};

public:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	Mup<ElementType>*	getAdaptee(){	return m_pAdaptee ;};
	const Mup<ElementType>*	getAdaptee()const{	return m_pAdaptee ;};
	CaMup& setAdaptee( Mup<ElementType>*	value )
	{	m_pAdaptee = value ; 	return *this ;	};
	///@}
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
	@return 
		ElementType にアクセスするための Muインターフェース。
	*/
	Mu< ElementType* >* getMuPtr()
	{	return &m_xMuPtr ;};
	/**
	@return 
		ElementType にアクセスするための Muインターフェース。
	*/
	const Mu< ElementType* >* getMuPtr()const 
	{	return &m_xMuPtr ;};
	/**
	@return 
		ElementType にアクセスするための Muインターフェース。
	*/
	Mu< const ElementType* >*  getMuConstPtr()
	{	return &m_xMuConstPtr ;};
	/**
	@return 
		ElementType にアクセスするための Muインターフェース。
	*/
	const Mu< const ElementType* >*  getMuConstPtr()const 
	{	return &m_xMuConstPtr ;};
	/**
	@return 
		ElementType にアクセスするための Muインターフェース。
	*/
	Mu< ElementType& >* getMuRef()
	{	return m_xMuRef ;};
	/**
	@return 
		ElementType にアクセスするための Muインターフェース。
	*/
	const Mu< ElementType& >* getMuRef()const 
	{	return m_xMuRef ;};
	/**
	@return 
		ElementType にアクセスするための Muインターフェース。
	*/
	Mu< const ElementType& >* getMuConstRef()
	{	return &m_xMuConstRef ;};
	/**
	@return 
		ElementType にアクセスするための Muインターフェース。
	*/
	const Mu< const ElementType& >* getMuConstRef()const 
	{	return &m_xMuConstRef ;};
	///@}
};

#ifndef NO_NSMU
} //namespace NsMu
#endif//NO_NSMU

} //namespace OuLib

#endif /*CaMup_h*/
