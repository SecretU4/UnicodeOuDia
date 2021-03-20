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
//	CDedRessyaSoater_Ressyasyubetsu.h
// $Id: CDedRessyaSoater_Ressyasyubetsu.h 141 2012-10-20 08:03:25Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CDedRessyaSoater_Ressyasyubetsu_h
#define  CDedRessyaSoater_Ressyasyubetsu_h

#include "entDed\CDedRessyaSoater.h"

namespace entDed{

// ****************************************************************
//	CDedRessyaSoater_Ressyasyubetsu
// ****************************************************************
/**
@brief
	【概要】
	CentDedRessyaCont 内の列車を、列車種別・列車名・号数に従って並べ替えます。

	
	【使い方】
	
	1.  コンストラクタでオブジェクトを生成してください。
	
	2.　sort() メソッドを呼び出すと、thisは、指定された列車コンテナのすべての列車をソートします。

	比較基準は、以下のとおりです。
			- NULLでないものとNULLのものとでは、NULLでないものが先。
			- 列車種別Indexの小さいほうが先。
			- 列車名が辞書順で早い方が先。
			- 号数の長さが短い方が先。
			- 号数が辞書順で早い方が先。
			- 列車番号の長さが短い方が先。
			- 列車番号が辞書順で早い方が先。
			- 列車Indexの小さい方が先。

*/
class CDedRessyaSoater_Ressyasyubetsu : public CDedRessyaSoater
{
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	*/
	CDedRessyaSoater_Ressyasyubetsu() ; 

	virtual ~CDedRessyaSoater_Ressyasyubetsu() ;
	
protected:
	// --------------------------------
	///@name sort の下請関数(templateパターン)
	// --------------------------------
	///@{
	/**
		指定された列車Indexの列車を、
	@param pRessyaCont [in]
		ソート対象の列車コンテナを指定してください。
	@param muRessyaIndexOrder [in,out]
		ソートを行う列車Indexを保持したコンテナを指定してください。
		(例：列車Index0〜4をソートしたい場合は、
		{0,1,2,3,4} の5つの要素を持つコンテナを指定してください。
		この関数はこの配列を、駅時刻Order順の早い列車Index順にソートします。
	@param pIfProgress [in]
		進捗状態の通知を受けたい場合は、進捗状態通知を受け取る
		インスタンスへのポインタを指定してください。
		NULLなら、この関数は進捗状態の通知を行いません。
	@note 
		この関数で得たソート結果を
		sortWithSortedRessyaIndex() に渡すことにより、
		列車コンテナをソートすることができます。
	*/
	virtual void sortRessyaIndex( 
		const CentDedRessyaCont* pRessyaCont , 
		Mui<int>* muRessyaIndexOrder , 
		IfProgress* pIfProgress ) ;

	///@}

};

} //namespace entDed


#endif /*CDedRessyaSoater_Ressyasyubetsu_h*/
