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
//$Id: CChildBase.h 380 2016-11-16 21:21:09Z okm $
#ifndef  OuLib_NsMu_CChildBase_h
#define  OuLib_NsMu_CChildBase_h
#include <stddef.h>
#include "CParentBase.h"

namespace OuLib{
namespace NsMu{


/**
@brief
  このクラスは、『親子コンテナ』パターン における子オブジェクトの基本クラスです。

@ref parent_child_container

 『親子コンテナ』パターンにおける子オブジェクトのクラスは、このクラスを継承する必要があります。
 『親子コンテナ』パターンをサポートしているコンテナクラスとして、CMuiCopiedParent、CMuiOuParent がありますが、これらのテンプレートパラメータ ElementType に指定するクラスは、CParentBase クラスを継承していなくてはなりません。

　 m_pParent は、初期値はNULLです。
　thisが 親オブジェクトに追加されたとき、親オブジェクトは、 CChildBase::setParent() メソッドを呼び出して、親オブジェクトのアドレスを子オブジェクトの  CChildBase::m_pParent に登録します。

　 CChildBase::m_pParent の型は、は、 CParentBase* です。子オブジェクトは、 CChildBase::m_pParent を、実際の親オブジェクト(コンテナ)の型にダウンキャストすることにより、親オブジェクトのメソッドを呼び出すことができます。

@note
　 m_pParent をCMuiCopiedParentBase 型ではなく、実際の親オブジェクトの型にすれば、子オブジェクトではダウンキャストをしなくてよくなります。これは、CChildBaseをクラステンプレートとし、テンプレートパラメータで親オブジェクトの型を指定することにより実現できそうにも思われます。@n
　しかし、詳しく考えると、この設計には無理があります。それは、以下のような循環依存になるためです。
 - 子オブジェクトは、CChildBaseに依存する( ElementType は、CChildBaseを継承する)
 - 親オブジェクトは、子オブジェクトに依存する( 親オブジェクト(コンテナ)は、子オブジェクトの型をテンプレート引数で要求する)
 - CChildBaseは、親オブジェクトに依存する(CChaildBaseは、親オブジェクトの型をテンプレート引数で要求する)

*/
class CChildBase
{
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		親オブジェクト(コンテナ)への関連です。
		初期値はNULLです。

		thisが 親オブジェクトに追加されたとき、親オブジェクトは、
		CChildBase::setParent() メソッドを呼び出して、
		親オブジェクトのアドレスを登録します。

		this がコンテナから削除されたときには、
		親オブジェクトは、NULLを登録します。
	*/
	CParentBase* m_pParent ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/** デフォルトコンストラクタ。m_pParent はNULLに初期化します */
	CChildBase() : m_pParent( NULL ){}

	/**
		コピーコンストラクタでは、 m_pParent はコピーしません。
		コンテナ内の子アイテムのコピーを生成した場合、コピーは
		コンテナ内の子アイテムではないからです。
	*/
	CChildBase( const CChildBase& value ) : m_pParent( NULL ){}

	/**
		代入演算子では、 m_pParent はコピーしません。

		親オブジェクトを持つ子オブジェクトに対して代入演算子を
		使用した場合、子オブジェクトの通常の属性は上書きされますが、
		その場合でも、「子オブジェクトである」という事実は
		変わらないためです。

		逆に、親オブジェクトを持つ子オブジェクトを代入演算子の
		左辺に置いて、親を持たないオブジェクトに属性をコピー
		した場合でも、右辺のオブジェクトは親を持たないままです。
	*/
	CChildBase& operator=( const CChildBase& value )
	{
		return *this ;
	}

public:
	// ********************************
	///@name CParentBase-操作
	// ********************************
	///@{
	/** @see m_pParent */
	virtual void setParent( CParentBase* pParent )
	{
		m_pParent = pParent ;
	}
	/** @see m_pParent */
	virtual CParentBase* getParent()const
	{
		 return m_pParent ;
	}
	///@}
};


} //namespace NsMu
} //namespace OuLib
#endif //OuLib_NsMu_CChildBase_h
