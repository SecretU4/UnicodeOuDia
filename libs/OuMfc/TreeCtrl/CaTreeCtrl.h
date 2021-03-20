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
//	CaTreeCtrl.h
// ****************************************************************
*/
#ifndef  CaTreeCtrl_h
#define  CaTreeCtrl_h

#include <afxcmn.h>
#include <deque>
namespace OuMfc{
namespace TreeCtrl{

// ****************************************************************
//	CaTreeCtrl
// ****************************************************************
/**
@brief
【概要】
  CTreeCtrl のアダプタクラスです。

  このクラスは、 CTreeCtrl との関連を持ちます。関連する CTreeCtrl への、追加の操作を提供します。
　追加の操作としては、以下のものがあります。

 - HTREEITEM と、『アイテムロケーション』との間の変換
 - ある HTREEITEM の子アイテムを列挙

  <H4>
【使い方】
  </H4>

　１．  このクラスのオブジェクトを生成する前に、CTreeCtrl オブジェクトが生成されていなくてはなりません。なおかつ、その CTreeCtrl は、 HWND が生成されていなくてはなりません

　２．  このクラスのオブジェクトを生成してください。コンストラクタでは、操作する CTreeCtrl オブジェクトを指定してください。

　３．　このあとは、すべてのメソッドが利用できます。

  <H4>
【アイテムロケーション】
  </H4>

　『アイテムロケーション』は、ツリーコントロールのアイテムの位置を示す値です。この値は、 std::deque<int> 型で
 表します。このクラスには、アイテムロケーションの型を表すtypedef として、 Itemlocation を定義しています。

  階層内でのアイテムの位置は、一番上のアイテムを 0 としたインデクスで指定します。
  １番目の階層内でのインデクスがコンテナのインデクス 0 の要素・
２番目（子アイテム）は インデクスが 1 ・
さらなる子アイテムのインデクスは 2 ・ 3 ・・・に格納されます。
『アイテムロケーション』のコンテナの要素数は、そのアイテムの階層の深さを表します。
  
  （例）
	@code
	+-- このアイテムの『アイテムロケーション』 [0]=0
	+-- このアイテムの『アイテムロケーション』 [0]=1
	  +-- このアイテムの『アイテムロケーション』 [0]=1 [1]=0
	  +-- このアイテムの『アイテムロケーション』 [0]=1 [1]=1
		+-- このアイテムの『アイテムロケーション』 [0]=1 [1]=1  [2]=0
	@endcode
 
 */
class CaTreeCtrl
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	/**
	 	『アイテムロケーション』のデータ型。
	 */
	typedef std::deque<int> Itemlocation ;

private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
	 	this が操作する CTreeCtrl オブジェクト。
		このオブジェクトの破棄の責務はクラスユーザーにあります。
		このオブジェクトは、this が破棄されるまで生存しなくてはなりません。
	 	コンストラクタで決まります。
	 */
	CTreeCtrl* m_pCTreeCtrl ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	///@{
	/**
	  @param pCTreeCtrl [in]
	 	this が操作する CTreeCtrl オブジェクト。
	 */
	CaTreeCtrl( CTreeCtrl* pCTreeCtrl ) ;
	///@}

public:
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
	  	HTREEITEM に対応する『アイテムロケーション』を作成します。
	  @param HTREEITEM [in]
	 	『アイテムロケーション』を取得する HTREEITEM を指定してください。
	  @param pItemlocation [out]
	 	この関数はこのコンテナに、『アイテムロケーション』を書き込みます。
	 	このコンテナがそれまで保持していた要素は破棄します。
	  @return 
	 	成功したら 0 以上、エラーなら負の数です。
	 	-  -1 ;	//	aHTREEITEM が不正です。

	  @b 使用例
	  @code
		CMup_deque<int>	aItemlocation ;
		CaTreeCtrl	aCaTreeCtrl( &m_CTreeCtrl ) ;
		aCaTreeCtrl.HTREEITEM_to_Itemlocation( aHTREEITEM , &aItermlocation ) ;
	  @endcode
	 */
	int HTREEITEM_to_Itemlocation( HTREEITEM aHTREEITEM , 
		Itemlocation* pItemlocation ) ;
	
	/**
	  	『アイテムロケーション』に対応するHTREEITEM を調べます。
	  @param pItemlocation [in]
	 	『アイテムロケーション』を指定してください。
	  @return 
	 	成功したら pItemlocation に対応する HTREEITEM 、エラーなら NULL です。
	 
	 */
	HTREEITEM HTREEITEM_from_Itemlocation( 
		const Itemlocation* pItemlocation ) ;
	///@}
};


} //namespace TreeCtrl
} //namespace OuMfc




#endif /*CaTreeCtrl_h*/
