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
//$Id: CParentBase.h 348 2016-08-16 17:47:55Z okm $

#ifndef  OuLib_NsMu_CParentBase_h
#define  OuLib_NsMu_CParentBase_h

namespace OuLib{
namespace NsMu{


/** @page parent_child_container 『親子コンテナ』パターン 

　『親子コンテナ』パターンは、設計パターンの一つです。
　オブジェクトが親子関係を持つ『オブジェクトツリー構造』において、子オブジェクトから親オブジェクト(子オブジェクトを保持するコンテナ)へのアクセス手段を提供します。

　ここでの『オブジェクトツリー構造』は、複数のオブジェクトが包含関係を構成してドメインを表現するモデルのことを指します。
　このようなオブジェクトツリー構造には、DOM(Document Object Model)、Windowsのウインドウハンドル、ツリーコントロールのアイテムなどがあります。これらのオブジェクトツリー構造では、子オブジェクトから親オブジェクトへアクセスする手段が普通に提供されています。

　『親子コンテナ』パターンは、この、「子オブジェクトから親オブジェクトへアクセスする手段」を実現するための設計パターンです。

　NsMuでは、以下のクラスを用いて、『親子コンテナ』パターンを実現します。

  - CMuiCopiedParent , CMuiOuParent : 親オブジェクトの具象クラステンプレート
  - CParentBase : 親オブジェクトの基本クラス
  - CChildBase  : 子オブジェクトの基本クラス

*/



/**
@brief
  このクラスは、『親子コンテナ』パターン における親オブジェクト(コンテナ)の基本クラスです。

@ref parent_child_container

　『親子コンテナ』パターンをサポートしているコンテナクラスとして、CMuiCopiedParent、CMuiOuParent があります。これらのクラスは、このクラスを継承しています。『親子コンテナ』パターンの親オブジェクトとして機能するコンテナクラスをにおける親オブジェクト(コンテナ)は、このクラスを継承する必要があります。

　C++のコンテナは、通常はクラステンプレートで実現されます。CMuiCopiedParent、CMuiOuParent も、クラステンプレートです。それに対し、このクラスは、テンプレートパラメータを持ちません。コンテナのテンプレートパラメータに依存しない基本クラスとして機能します。
  このクラスには、属性も操作もありません。

  子オブジェクトが親オブジェクトに追加されたとき、親オブジェクトは、子オブジェクトの CChildBase::setParent() メソッドを呼び出して、親オブジェクトのアドレスを子オブジェクトに登録します。このとき渡される親オブジェクトの型は、CParentBase* です。子オブジェクトは、CParentBase* を、実際の親オブジェクト(コンテナ)の型にダウンキャストすることにより、親オブジェクトのメソッドを呼び出すことができます。
*/
class CParentBase
{
protected:
	virtual ~CParentBase(){};
};



} //namespace NsMu
} //namespace OuLib
#endif //OuLib_NsMu_CParentBase_h
