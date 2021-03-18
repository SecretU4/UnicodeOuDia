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
//	CRfEditCmd.h
// ****************************************************************
*/
/** @file */
#ifndef  CRfEditCmd_h
#define  CRfEditCmd_h

#include "NsOu/Ou.h"
#include "DedRosenFileData\CDedRosenFileData.h"

namespace DedRosenFileData{
namespace EditCmd{
	using namespace OuLib::NsOu;

// ****************************************************************
//	CRfEditCmd
// ****************************************************************
/**
  @brief
  CDedRosenFileData オブジェクトに対する編集コマンドの抽象基本クラスです。

  純粋仮想関数として、 以下の２つがあります。

 - execute (  CDedRosenFileData オブジェクトに対する編集コマンドの実行 )

 - createUndoCmd ( execute() で実行した編集動作を取り消して、  CDedRosenFileData の状態を execute() を実行する直前に戻すための、コマンドオブジェクトを生成)



　このクラスは抽象クラスです。 CDedRosenFileData に対する編集動作の
内容毎に、派生クラスが存在します。
　派生クラスでは、実際の編集動作の内容を属性に保持します。
（例： CRfEditCmd_Ressya は、列車に対する編集操作を
表します。このクラスはメンバ変数として、編集を行う列車のインデクスと、
編集後の列車を保持する CentDedRessya オブジェクトを保持します）。

<H4>
【使い方】
</H4>

１．　編集コマンドの種類に応じた派生クラスのオブジェクトを生成してください。

２．　オブジェクトの属性に、編集動作の内容を指定してください。

３．　CDedRosenFileData オブジェクトを引数に渡して execute() メソッドを
呼び出すと、 this は引数で指定された CDedRosenFileData オブジェクトに
対して、属性で指定されている編集動作を行います。
　また、編集動作に成功した場合、 this は、undo（編集動作の取り消し）を
行うのに必要なデータをメンバ変数に保持します。

４．　execute() を呼び出した直後に createUndoCmd() を呼び出すと、
「 this->execute() で行った編集操作を取り消す （ this->execute() で
編集動作を行った直後の CDedRosenFileData オブジェクトを、
 this->execute() を行う直前の状態にする）」
ための編集コマンドオブジェクト（CRfEditCmd）を生成
することができます。@n
　このメンバ関数が返したオブジェクトの execute() メソッドを呼び出すことにより、
this->execute() 直後の状態の CentDedRosen オブジェクトを、 this->execute() 
直前の状態に戻すことができます。

（例）　
　 CRfEditCmd_Ressya で、インデクス 0 の列車を削除するような動作のオブジェクトを生成し、execute() を実行したとします。
　この次に CRfEditCmd_Ressya に対して createUndoCmd() を呼び出すと、メンバ関数は、インデクス 0 に先ほど削除した列車を追加するような動作のコマンドオブジェクトを生成します。
*/
class CRfEditCmd
{
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CRfEditCmd(){};
	virtual ~CRfEditCmd(){};

public:
	// ********************************
	///@name	CRfEditCmd-操作
	// ********************************
	///@{
	/**
	 	CDedRosenFileData オブジェクトに対して、編集操作を実行します。
	 	　また、編集動作に成功した場合、 this は、undo
	 	（編集動作の取り消し）を行うのに必要なデータを、
	 	メンバ変数に保持します。
	  @param pCDedRosenFileData [in,out]
	 	この関数はこのオブジェクトに対して、編集操作を実行します。
	  @return
	 	成功したら 0 以上、エラーなら負の数です。
	 	<H4>
	 	【オーバライド】
	 	</H4>
	 	pCDedRosenFileData オブジェクトに対して、編集動作を実行してください。
	 */
	virtual int execute( CDedRosenFileData* pCDedRosenFileData ) = 0 ;
	
	/**
	 	「 this->execute() で行った編集操作を取り消す
	 	（ this->execute() で編集動作を行った直後の CDedRosenFileData 
	 	オブジェクトを、 this->execute() を行う直前の状態に
	 	する）」ための編集コマンドオブジェクトを生成します。
	 
	 	このメンバ関数が返したオブジェクトを使って execute() を
	 	呼び出すことにより、 this->execute() 直後の状態の CentDedRosen
	 	 オブジェクトを、 this->execute() 直前の状態に戻すことができます。
	  @return
	 	execute() で行った編集操作を取り消し、
	 	 CDedRosenFileData オブジェクトを execute() を行う直前の状態に
	 	するためのコマンドオブジェクトを生成します。@n
	 	 オブジェクトを生成できない場合は、NULL を返します。
	 	<H4>
	 【オーバライド】
	 	</H4>
	 	execute() で実行した編集内容を元に戻すようなオブジェクトを
	 	生成して返してください。
	 */
	virtual Ou<CRfEditCmd> createUndoCmd() = 0 ;
	
	///@}
};

} } //namespace EditCmd namespace DedRosenFileData

#endif /*CRfEditCmd_h*/

