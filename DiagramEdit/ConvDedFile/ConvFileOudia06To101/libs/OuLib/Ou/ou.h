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
//	Ou.h
// ****************************************************************
*/
/** @file */
#ifndef  Ou_h
#define  Ou_h
#include "Ou\OuBase.h"
#include "Ou\OuHolder.h"

// ****************************************************************
//	Ou< TargetType >
// ****************************************************************
/**
 * @brief
 * 【概要】
 * 	  TargetType 型のオブジェクトを参照する
 *	スマートポインタです。
 *
 *
 *	<H4>
 * 【 Ou モデル】
 *	</H4>
 * 	  "Ou< TargetType >" は、TargetType 型のオブジェクトを参照する、
 * 	スマートポインタです。
 *
 * 	  "Ou< TargetType >" が指している TargetType 型のオブジェクトのことを、
 * 	『（Ou の）ターゲットオブジェクト』と呼称します。
 *	  Ou は、『ターゲットオブジェクト』の参照を終了するときに、
 *	自動的に『ターゲットオブジェクト』の後始末（削除）
 *	を行う仕組みを持っています。
 *
 *	 「『ターゲットオブジェクト』の参照を終了するとき」は、具体的には
 *
 *	-	Ou自身が破棄されるとき（デストラクタ）
 *	-	Ouに、他の『ターゲットオブジェクト』への参照(Ou)を開始するとき（代入）
 *	-	Ou.clear() を呼び出したとき。
 *	
 *	といった場合を指します。
 *
 *	  『ターゲットオブジェクト』が、複数の Ou から参照される場合があります。
 *	  Ou ではこの場合、『ターゲットオブジェクト』を参照している Ou の
 *	数をカウントし、これが 0 になったときに、『ターゲットオブジェクト』の
 *	後始末（削除）を行います。
 *	\nこの管理をおこなうため、Ouでは『ターゲットオブジェクト』１つにつき１つの
 *	『ホルダーオブジェクト( "OuHolder< TargetType >" ) 』を生成・管理します。
 *
 *	『ホルダーオブジェクト』は、
 *
 *	- 『ターゲットオブジェクト』へのポインタ
 *	- 『ターゲットオブジェクト』を参照している Ou の数（参照カウンタ)
 *
 *	を保持しています。『ホルダーオブジェクト』は、参照カウンタが０になった
 *	ときに、自分自身（『ホルダーオブジェクト』）と『ターゲットオブジェクト』
 *	を削除します。
 * 
 * 	  Ou は、ターゲットオブジェクトの後始末の方法毎に、派生クラスを持ってい
 * 	ます。標準の派生クラスとしては
 * 
 * 	- 1.  new で生成されたオブジェクトを保持する "OuNew< TargetType >"
 *	 (ターゲットオブジェクトを delete で削除する)
 * 	- 2.  静的な寿命を持つオブジェクトを保持する "OuStatic< TargetType >"
 *	（ターゲットオブジェクトの削除は行わない）
 * 
 * 	がありますが、これ以外の破棄方法を持つクラスを独自に作成することも可能
 * 	です。
 * 
 * <H4>
 * 【使い方】
 * </H4>
 * 
 * １．  新しいターゲットオブジェクトを Ou で管理する場合は、そのターゲット
 * 	オブジェクトの破棄方法ごとに定義された派生クラスのオブジェクトを生成し、
 * 	その引数としてターゲットオブジェクトを指定してください。
 * 
 * ２．  既存の Ou オブジェクト（または、Ouの派生クラスのオブジェクト）が
 * 	参照しているターゲットオブジェクトを参照する、新たな Ou を生成する場合
 * 	は、Ou オブジェクトを生成し、それに対してコピーコンストラクタ・代入演算子
 * 	を使ってください。
 */
template< class TargetType1 > 
class Ou : public OuBase
{
// ********************************
//	クラス内定義
// ********************************
 public:
	typedef OuBase	super ;
	typedef TargetType1 TargetType ;


// ********************************
///@name 関連
// ********************************
///@{
 private:
	/**
	 * 	ターゲットオブジェクトへのポインタです。
	 * 	コンストラクタ・代入演算子で決定します。
	 */
	TargetType*		m_pTarget ;

///@}
// ********************************
//	コンストラクタ・デストラクタ
// ********************************
 public:
	/**
	 * 	  デフォルトコンストラクタです。
	 * 	  ターゲットオブジェクトはNULLとなります。
	 */
	Ou() : 
		m_pTarget( NULL ) 
	{
	};
	/**
	 * 	  新しいターゲットオブジェクトを参照させるときのコンストラクタです。
	 * 	  new で生成した OuHolderオブジェクトを登録します。
	 * @param pHolder [in]
	 * 	新しいターゲットオブジェクトを保持している、 OuHolder オブジェクト
	 * 	を指定してください。
	 */
	template< class TargetTypeSrc >
	Ou( OuHolder<TargetTypeSrc>* pHolder ) 
		: super( pHolder ) 
	{
		m_pTarget = static_cast<TargetType*>( pHolder->getTarget() ) ;
	};
	
	
	/**
	 * 	変換コンストラクタ
	 * 	既存の Ou オブジェクト（または、Ouの派生クラスのオブジェクト）が
	 * 	参照しているターゲットオブジェクトを参照します。
	 * @param ev [in]
	 * 	既存の Ou  オブジェクトを指定してください。
	 */
	template< class TargetTypeSrc >
	Ou( Ou<TargetTypeSrc>& ev )
		: super( ev ) 
	{
		m_pTarget = static_cast<TargetType*>( ev.getTarget() ) ;
	};
	
	/**
	 * 	代入演算子です。
	 * 	既存の Ou オブジェクト（または、Ouの派生クラスのオブジェクト）が
	 * 	参照しているターゲットオブジェクトを参照します。
	 * 	このとき、それまでこの Ou オブジェクトが参照していたターゲット
	 * 	オブジェクトに対しては、参照カウンタを減らし、必要なら削除を行います。
	 * @param ev [in]
	 * 	既存の Ou  オブジェクトを指定してください。
	 */
	template< class TargetTypeSrc >
	Ou& operator=( Ou<TargetTypeSrc>& ev ) 
	{
		super::operator=( ev ) ;
		m_pTarget = static_cast<TargetType*>( ev.getTarget() ) ;
		
		return ( *this ) ;
	};


	/**
	 * 	コピーコンストラクタ
	 * 	既存の Ou オブジェクト（または、Ouの派生クラスのオブジェクト）が
	 * 	参照しているターゲットオブジェクトを参照します。
	 * @param ev [in]
	 * 	既存の Ou  オブジェクトを指定してください。
	 */
	Ou( const Ou& ev )
		: super( ev ) 
	{
		m_pTarget = ev.m_pTarget   ;
	};
	
	/**
	 * 	代入演算子です。
	 * 	既存の Ou オブジェクト（または、Ouの派生クラスのオブジェクト）が
	 * 	参照しているターゲットオブジェクトを参照します。
	 * 	このとき、それまでこの Ou オブジェクトが参照していたターゲット
	 * 	オブジェクトに対しては、参照カウンタを減らし、必要なら削除を行います。
	 * @param ev [in]
	 * 	既存の Ou  オブジェクトを指定してください。
	 */
	Ou& operator=( const Ou& ev ) 
	{
		super::operator=( ev ) ;
		m_pTarget = ev.m_pTarget ;
		
		return ( *this ) ;
	};

	//	デストラクタ
	virtual ~Ou()
	{
	};

// ********************************
//	"Ou< TargetType >"
// ********************************
 public:
	// ********************************
	///@name "Ou< TargetType >"-関連
	// ********************************
	///@{
	TargetType* getTarget(){	return ( m_pTarget ) ; 	} ;
	const TargetType* getTarget()const{	return ( m_pTarget ) ; 	} ;
	///@}
	// ********************************
	///@name "Ou< TargetType >"-演算子
	// ********************************
	///@{

	/**
	 * 	  ターゲットオブジェクトへのキャスト演算子です。
	 * 	  これにより、Ouオブジェクトを普通のポインタの代わりに
	 * 	関数の引数として渡すことができます。
	 */
	operator  TargetType*(){	return ( getTarget() ) ; } ;
	operator  const TargetType*()const{	return ( getTarget() ) ; } ;
	
	/**
	 * 	  "->"演算子
	 * 	ターゲットオブジェクトのポインタを返します。
	 * 	  これにより、Ouオブジェクトに "->" をつけて、ターゲットオブジェクトの
	 * 	メンバにアクセスできます。
	 */
	TargetType* operator->(){	return ( getTarget() ) ; } ;
	const TargetType* operator->()const{	return ( getTarget() ) ; } ;
	
	/**
	 * 	  "*"演算子
	 * 	  これにより、 Ou オブジェクトに "*" をつけて、ターゲットオブジェクト
	 * 	の実体を表すことができます。
	 */
	TargetType& operator*(){	return ( *getTarget() ) ; } ;
	const TargetType& operator*()const{	return ( *getTarget() ) ; } ;
	
	/**
	 * 	  比較演算子
	 * 	  ターゲットオブジェクトのポインタと、通常のポインタの比較を
	 * 	行います。
	 * 	  比較対象には NULL を指定することもできます。
	 * @param ev [in]
	 * 	比較対象のポインタを指定してください。
	 * @return
	 * 	- (operator==)対象となるオブジェクトのポインタが同じであれば真です
	 * 	- (operator!=)対象となるオブジェクトのポインタが異なれば真です
	 */
	bool operator==( TargetType* ev )const
	{
		return ( m_pTarget == ev ) ;
	};	
	/**
	 *	@see operator==( TargetType* ev ) を参照してください。
	 */
	bool operator!=( TargetType* ev )const
	{
		return ( m_pTarget != ev ) ;
	};	

	/**
	 * 	  比較演算子
	 * 	  this と、指定のOuオブジェクトとの間で、ターゲットオブジェクトの
	 * 	ポインタの比較を行います。
	 * @param ev [in]
	 * 	比較対象の Ou オブジェクトを指定してください。
	 * @return
	 * 	- (operator==)対象となるオブジェクトのポインタが同じであれば真です
	 * 	- (operator!=)対象となるオブジェクトのポインタが異なれば真です
	 */
	template< class TargetTypeSrc >
	bool operator==( Ou<TargetTypeSrc>& ev )const
	{
		return ( m_pTarget == ev.getTarget() ) ;
	};	
	/**
	 *	@see operator!=() を参照してください。
	 */
	template< class TargetTypeSrc >
	bool operator!=( Ou<TargetTypeSrc>& ev )const
	{
		return ( m_pTarget != ev.getTarget() ) ;
	};	

	///@}
	// ********************************
	///@name "Ou< TargetType >"-操作
	// ********************************
	///@{
	/**
	 * @return
	 *	ターゲットオブジェクトがNULLなら、真を返します。
	 */
	virtual bool isNull() const
	{
		return ( m_pTarget == NULL ) ;
	};

	/**
	 * 	この Ou オブジェクトの
	 * 	ターゲットオブジェクトに対する参照を中止し、
	 * 	初期状態に戻します。
	 */
	virtual void clear() 
	{
		super::clear() ;
		m_pTarget = NULL ;
	};
	///@}

};




#endif /*Ou_h*/
