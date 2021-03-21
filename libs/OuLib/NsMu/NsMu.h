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
//$Id: NsMu.h 355 2016-08-18 16:41:28Z okm $
/**
 @file 
 @brief
	名前空間の関数群・クラス群のすべてをインクルードします。
*/


namespace OuLib{

#ifndef NO_NSMU
/**
@brief
  NsMu は、配列形式のコンテナ(コレクション)のクラス群が属する名前空間です。

  この名前空間の中心になる Mu (Multi object) は、配列形式のコンテナへの抽象インターフェースです。要素を複数保持しているコンテナに、整数インデクスで要素にアクセスする機能を提供します。
  
  NsMu は、この Mu インターフェースをサポートするコンテナクラス群を集約する名前空間です。

  この名前空間のクラスは、作りすぎの傾向があるため、用途に適したクラスが分かりにくくなっています。
  クラス選択のガイドラインは、以下の通りです。これは、利用実績から判明した結果です。
  
<H4>
サイズの小さい(コピーにコストのかからない)データを格納する場合
</H4>

　通常のSTLのコンテナ。または、 CMup_deque,CMup_vector 。

<H4>
サイズの大きいクラスを格納する場合
</H4>
  CMuiCopied 。

<H4>
クラスオブジェクトを格納し、オブジェクトのメソッドを直接呼び出したい場合。但し、基本クラスを格納するコンテナに派生クラスのオブジェクトを格納することはない。
</H4>
  CMuiCopied 。親子コンテナパターンを使用する場合は CMuiCopiedParent 。
  
@ref parent_child_container
  
<H4>
基本クラスを格納するコンテナに派生クラスのオブジェクトを格納し、多態動作を行う場合
</H4>
  CMuiOu 。 親子コンテナパターンを使用する場合は CMuiOuParent 。
  
*/
namespace NsMu{
}
#endif//NO_NSMU


} //namespace OuLib


#include "NsMu\CaMuCast.h"
#include "NsMu\CaMui.h"
#include "NsMu\CaMuiFilter.h"
#include "NsMu\CaMup.h"
#include "NsMu\CaMuPtref.h"
#include "NsMu\CaMuiSelect.h"
#include "NsMu\CaMup_list.h"
#include "NsMu\CaMup_vector.h"
#include "NsMu\CChildBase.h"
#include "NsMu\CConvTable.h"
#include "NsMu\CMuiCopied.h"
#include "NsMu\CMuiCopiedParent.h"
#include "NsMu\CMuiOu.h"
#include "NsMu\CMuiOuParent.h"
#include "NsMu\CMup_deque.h"
#include "NsMu\CMup_list.h"
#include "NsMu\CMup_vector.h"
#include "NsMu\CParentBase.h"
#include "NsMu\Mu.h"
#include "NsMu\Mui.h"
#include "NsMu\Mup.h"

