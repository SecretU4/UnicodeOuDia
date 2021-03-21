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
//	OuBase.h
// ****************************************************************
*/
/** @file */
#ifndef  OuBase_h
#define  OuBase_h
#include <stdlib.h>

#include "NsOu\OuHolderBase.h"

namespace OuLib{

#ifndef NO_NSOU
namespace NsOu{
#endif//NO_NSOU

// ****************************************************************
//	OuBase
// ****************************************************************
/**
 * @brief
 * 【概要】
 * 	  Ouモデルにおける、 Ou の基本クラスです。
 *
 *	  このクラスは、『ホルダーオブジェクト』に対するカウントの＋・－を
 *	責務とします。
 */
class OuBase
{
// ********************************
///@name 関連
// ********************************
///@{
 private:
	/**
	 * 	『ホルダーオブジェクト』です。
	 *
	 * 	コンストラクタ・または代入演算子で決定し、
	 * 	このオブジェクトがホルダーオブジェクトを使用開始したときに
	 * 	AddRef() で、 this を登録します。
	 *
	 * 	このオブジェクトがホルダーオブジェクトの参照を
	 * 	中止したときには Release() を呼び出して、
	 * 	this を登録解除します。
	 */
	OuHolderBase*	m_pHolder ;

// ********************************
//	コンストラクタ・デストラクタ
// ********************************
 public:
	/**
	 *	デフォルトコンストラクタです。
	 *	『ホルダーオブジェクト』は未登録となります。
	 */
	OuBase() : 
		m_pHolder( NULL ) 
	{
	};
	/**
	 * 	  新しいオブジェクトを生成したときのコンストラクタです。
	 * 	  new で生成した OuHolderオブジェクトを登録します。
	 */
	OuBase( OuHolderBase* pHolder ) : 
		m_pHolder( pHolder ) 
	{
		if ( m_pHolder != NULL ){
			m_pHolder->AddRef( this ) ;
		}
	};
	
	OuBase( const OuBase& ev )
	{
		m_pHolder = ev.m_pHolder ;
		if ( m_pHolder != NULL ){
			m_pHolder->AddRef( this ) ;
		}
	};
	
	OuBase& operator=( const OuBase& ev ) 
	{
		if ( m_pHolder != NULL ){
			m_pHolder->Release( this ) ;
		}
		m_pHolder = ev.m_pHolder ;
		if ( m_pHolder != NULL ){
			m_pHolder->AddRef( this ) ;
		}
		
		return ( *this ) ;
	};


	virtual ~OuBase()
	{
		if ( m_pHolder != NULL ){
			m_pHolder->Release( this ) ;
		}
	};
// ********************************
//	OuBase
// ********************************
 public:
	// ********************************
	///@name OuBase-関連
	// ********************************
	///@{

	OuHolderBase* getHolder(){	return m_pHolder ; 	} ;

	///@}
	// ********************************
	///@name OuBase-操作
	// ********************************
	///@{
	
	/**
	 * @return
	 * 	ターゲットオブジェクトを参照しているOuBase（Ou<>を含む）
	 * 	の数を返します。
	 */
	virtual int RefCount() 
	{
		if ( m_pHolder != NULL ){
			return ( m_pHolder->RefCount() ) ;
		}
		return ( 0 ) ;
	};
	

	/**
	 * 	この Ou オブジェクトの
	 * 	ターゲットオブジェクトに対する参照を中止し、
	 * 	初期状態に戻します。
	 */
	virtual void clear() 
	{
		if ( m_pHolder != NULL ){
			m_pHolder->Release( this ) ;
		}
		m_pHolder = NULL ;
	};
	///@}
};

#ifndef NO_NSOU
} //namespace NsOu
#endif//NO_NSOU

} //namespace OuLib

#endif /*OuBase_h*/



