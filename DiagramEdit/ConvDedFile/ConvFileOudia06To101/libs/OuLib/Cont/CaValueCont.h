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
//	CaValueCont.h
// ****************************************************************
*/
/** @file */
#ifndef  CaValueCont_h
#define  CaValueCont_h

#include "./IfValueCont.h"
// ****************************************************************
//	CaValueCont
// ****************************************************************
/**
 * @brief
 * 【概要】
 *   アダプタクラスです。値を保持するコンテナ 
 *	"IfValueCont< ElementType >" を操作対象とし、コンテナ内の
 *	要素へのポインタ・参照を返す "IfContGet" インターフェースに変換します。
 * 
 * (※  ポインタを保持するコンテナには、このアダプタは使えません)
 * 
 *   このアダプタクラスを使うと、以下のインターフェースを取得する
 *	ことができます。対応するメソッドを呼び出してください。
 *
 * 	- "IfContGet< ElementType* >" ・・・ getIfContGetPtr()
 * 	- "IfContGet< const ElementType* >" ・・・ getIfContGetConstPtr() 
 * 	- "IfContGet< ElementType& >" ・・・ getIfContGetRef()
 * 	- "IfContGet< const ElementType& >" ・・・ getIfContGetConstRef() 
 * 
 * @param ElementType
 *	操作対象オブジェクトが格納しているデータの型を指定してください。
 *	操作対象オブジェクトは、 "IfCont<ElementType*>" インターフェースを
 *	サポートします。
 *	このデータ型は、値型でなくてはなりません（ポインタ・参照は使用できません）
 */
template < class ElementType > class CaValueCont 
{
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
	 */
	IfValueCont<ElementType>*	m_pAdaptee ;
///@}

// ********************************
///@name 包含
// ********************************
///@{
 private:
	// ********************************
	//	"IfContGet< ElementType* >" ・・・ getIfContGetPtr()
	// ********************************
	/**
	 * @brief
	 *	CaValueCont::getIfContGetPtr() メソッドが返すインターフェースを
	 *	実装したクラスです。
	 */
	class XIfContGetPtr : public IfContGet< ElementType* >
	{
	 public:
		virtual int	size()const{
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetPtr) ) ;
			return pOuter->m_pAdaptee->size() ; } ;
		virtual ElementType* get( int idx )const {
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetPtr) ) ;
			ElementType*	pRv = pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xIfContGetPtr ;
	friend class XIfContGetPtr ;
	// ********************************
	// 	"IfContGet< const ElementType* >" ・・・ getIfContGetConstPtr() 
	// ********************************
	/**
	 * @brief
	 *	CaValueCont::getIfContGetConstPtr() メソッドが返すインターフェースを
	 *	実装したクラスです。
	 */
	class XIfContGetConstPtr : public IfContGet< const ElementType* >
	{
	 public:
		virtual int	size()const{
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetConstPtr) ) ;
			return pOuter->m_pAdaptee->size() ; } ;
		virtual const ElementType* get( int idx )const {
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetConstPtr) ) ;
			ElementType*	pRv = pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xIfContGetConstPtr ;
	friend class XIfContGetConstPtr ;

	// ********************************
	// 	"IfContGet< ElementType& >" ・・・ getIfContGetRef()
	// ********************************
	/**
	 * @brief
	 *	CaValueCont::getIfContGetRef() メソッドが返すインターフェースを
	 *	実装したクラスです。
	 */
	class XIfContGetRef : public IfContGet< ElementType& >
	{
	 public:
		virtual int	size()const{
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetRef) ) ;
			return pOuter->m_pAdaptee->size() ; } ;
		virtual ElementType& get( int idx )const {
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetRef) ) ;
			ElementType&	pRv = *pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xIfContGetRef ;
	friend class XIfContGetRef ;
	// ********************************
	// 	"IfContGet< const ElementType& >" ・・・ getIfContGetConstRef() 
	// ********************************
	/**
	 * @brief
	 *	CaValueCont::getIfContGetConstRef() メソッドが返すインターフェースを
	 *	実装したクラスです。
	 */
	class XIfContGetConstRef : public IfContGet< const ElementType& >
	{
	 public:
		virtual int	size()const{
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetConstRef) ) ;
			return pOuter->m_pAdaptee->size() ; } ;
		virtual const ElementType& get( int idx )const {
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetConstRef) ) ;
			ElementType&	pRv = *pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xIfContGetConstRef ;
	friend class XIfContGetConstRef ;

///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	CaValueCont( IfValueCont<ElementType>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ) {};
 private:
	CaValueCont( const CaValueCont<ElementType>& ){};
	CaValueCont& operator=( const CaValueCont<ElementType>& ){ return *this ;};

// ********************************
//	CaValueCont
// ********************************
 public:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	IfValueCont<ElementType>*	getAdaptee(){	return m_pAdaptee ;};
	const IfValueCont<ElementType>*	getAdaptee()const{	return m_pAdaptee ;};
	CaValueCont& setAdaptee( IfValueCont<ElementType>*	value )
	{
		m_pAdaptee = value ; 	return *this ;
	};
	///@}
	// ********************************
	///@name 包含
	// ********************************
	///@{
	IfContGet< ElementType* >* getIfContGetPtr(){
		return &m_xIfContGetPtr ;};
	IfContGet< const ElementType* >*  getIfContGetConstPtr(){
		return &m_xIfContGetConstPtr ;};
	IfContGet< ElementType& >* getIfContGetRef(){
		return m_xIfContGetRef ;};
	IfContGet< const ElementType& >* getIfContGetConstRef(){
		return &m_xIfContGetConstRef ;};

	const IfContGet< ElementType* >* getIfContGetPtr()const {
		return &m_xIfContGetPtr ;};
	const IfContGet< const ElementType* >*  getIfContGetConstPtr()const {
		return &m_xIfContGetConstPtr ;};
	const IfContGet< ElementType& >* getIfContGetRef()const {
		return m_xIfContGetRef ;};
	const IfContGet< const ElementType& >* getIfContGetConstRef()const {
		return &m_xIfContGetConstRef ;};
	///@}
};

#endif /*CaValueCont_h*/
