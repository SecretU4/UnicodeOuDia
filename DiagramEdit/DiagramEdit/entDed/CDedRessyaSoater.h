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
//	CDedRessyaSoater.h
// $Id: CDedRessyaSoater.h 141 2012-10-20 08:03:25Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CDedRessyaSoater_h
#define  CDedRessyaSoater_h
#include "entDed\CentDedRosen.h"
#include "IfProgress.h"

namespace entDed{

// ****************************************************************
//	CDedRessyaSoater
// ****************************************************************
/**
@brief
【概要】
	CentDedRessyaDia 内の列車のソート処理を行うクラス。
	
	このクラスは抽象クラスです。
	派生クラスでオーバライドを行い、ソートアルゴリズムを実装する必要があります。
	
【オーバライド】

	1.  sortRessyaIndex() のオーバライドを行ってください。
	　この関数では、列車インデクスを保持するコンテナのソートを行ってください。
	　(列車インデクスコンテナに格納されたソート結果に従って
	 列車 CentDedRessya のソートを行うのは、 sortRessyaIndex() の呼び出し元である sort() の
	 責務です。)
	 (列車オブジェクト CentDedRessya ではなく、列車インデクス int をソートする
	 仕様になっているのは、パフォーマンス向上のためです。CentDedRessya のコピーには
	 時間がかかるためです。)
	
【使い方】
	
	1.  コンストラクタでオブジェクトを生成してください。
	
	2.　sort() メソッドを呼び出すと、thisは、指定された列車コンテナのすべての列車をソートします。
*/
class CDedRessyaSoater
{
protected:
	// --------------------------------
	///@name sort の下請関数(templateパターン)
	// --------------------------------
	///@{
	/**
		ソートを行う列車Indexを保持したコンテナに、
		連番の列車Indexを格納します。
	@param iRessyaIndex [in]
		先頭の列車Indexを指定してください。
	@param iRessyaCount [in]
		列車の数を指定してください。
	@param muRessyaIndexOrder [out]
		この関数はこのコンテナに、
		iRessyaIndex ～ iRessyaIndex + iRessyaCount - 1 の
		整数を連番で格納します。
		このコンテナがそれまで保持していたデータは破棄されます。

	*/
	static void makeRessyaIndex( 
		int iRessyaIndex , int iRessyaCount , 
		Mui<int>* muRessyaIndexOrder ) ;


	/**
		指定された列車Indexをソートします。
	@param pRessyaCont [in]
		ソート対象の列車を保持した列車のコンテナを指定してください。
	@param muRessyaIndexOrder [in,out]
		ソートを行う列車Indexを保持したコンテナを指定してください。
		(例：列車Index0～4をソートしたい場合は、
		{0,1,2,3,4} の5つの要素を持つコンテナを指定してください。
		この関数はこの配列を、駅時刻Order順の早い列車Index順にソートします。
	@param pIfProgress [in]
		進捗状態の通知を受けたい場合は、進捗状態通知を受け取る
		インスタンスへのポインタを指定してください。
		NULLなら、この関数は進捗状態の通知を行いません。
	@note 
		この関数で得たソート結果を
		sortRessyaByRessyaIndexOrder() に渡すことにより、
		列車コンテナをソートすることができます。

	【オーバライド】
	　派生クラスでは、この関数をオーバライドして、
	 列車インデクスを保持するコンテナのソートを行ってください。
	　(列車インデクスコンテナに格納されたソート結果に従って
	 列車 CentDedRessya のソートを行うのは、 sortRessyaIndex() の呼び出し元である sort() の
	 責務です。)
	*/
	virtual void sortRessyaIndex( 
		const CentDedRessyaCont* pRessyaCont , 
		Mui<int>* muRessyaIndexOrder , 
		IfProgress* pIfProgress ) = 0 ;


	/**
		列車 index (int)を保持したコンテナに従って、
		列車コンテナの列車の並び順を、
		入れ替えます。
	@param muRessyaIndexOrder [in]
		列車Indexを保持したコンテナを指定してください。
	@param pRessyaCont [in,out]
		並べ替えの対象となる列車コンテナを指定してください。
		この関数はこの配列を、muRessyaIndexOrder の順に
		並べ替えます。
	*/
	static void sortRessyaByRessyaIndexOrder( 
		const Mu<int>* muRessyaIndexOrder,
		CentDedRessyaCont* pRessyaCont ) ;
	///@}

public:
	// ********************************
	//	コンストラクタ・デストラクタ
	// ********************************
	virtual ~CDedRessyaSoater(){} ;

public:
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
		指定された列車コンテナ内の列車を、属性で指定された条件でソートします。
	@param pRessyaCont [in,out]
		並べ替えの対象となる列車コンテナを指定してください。
	@param pIfProgress [in]
		進捗状態の通知を受けたい場合は、進捗状態通知を受け取る
		インスタンスへのポインタを指定してください。
		NULLなら、この関数は進捗状態の通知を行いません。
	*/
	virtual void sort( 
		CentDedRessyaCont* pRessyaCont ,
		IfProgress* pIfProgress ) ;
	///@}

};

} //namespace entDed

#endif /*CDedRessyaSoater_h*/
