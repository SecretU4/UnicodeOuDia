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
//	CDedRessyaSoater_Transfer.h
// $Id: CDedRessyaSoater_Transfer.h 241 2016-01-05 06:14:33Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CDedRessyaSoater_Transfer_h
#define  CDedRessyaSoater_Transfer_h

#include "entDed\CentDedRosen.h"
#include "entDgr\CentDedDgrDia.h"
#include "IfProgress.h"

#include "entDed\CDedRessyaSoater.h"

namespace entDgr{

// ****************************************************************
//	CDedRessyaSoater_Transfer
// ****************************************************************
/**
@brief
	【概要】
	CentDedDia 内の列車の『乗り継ぎソート』処理を行うクラス。
	
	【使い方】
	
	1.  コンストラクタでオブジェクトを生成後、 validate() を呼び出して
	初期化を行ってください。
　　
　　※　this は、 CentDedRessyaDia に対応する CentDedDgrDia オブジェクトと、
　　ソート対象の列車の推定時刻を保持した CentDedRessyaCont を生成します。
	
	2.　sort() メソッドを呼び出すと、thisは、指定された列車コンテナのすべての列車をソートします。

	3.  CentDedDiaの列車コンテナ内の列車の内容が変化したら、this の内容は無効になります
	　(1本の列車の1駅の駅時刻が変化しただけで、thisの内容は無効になります)。
	　この場合は、invalidate() を呼び出して一旦 this を初期化し、
	 再度 validate() を呼び出して、thisの内容を更新しなくてはなりません。

*/
class CDedRessyaSoater_Transfer : public CDedRessyaSoater
{
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		ソートの対象となる列車を集約する路線オブジェクト。
	*/
	const CentDedRosen* m_pDedRosen ;

	/**
		ソートの対象となる列車を集約するダイヤ。
	*/
	const CentDedDia* m_pDedDia ;

	///@}
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		ソート対象の 駅時刻Order。
	*/
	CdDedJikokuOrder  m_JikokuOrder ;  



	///@}
	// ********************************
	///@name 集約
	// ********************************
	///@{
	/**
		ソートの対象となるダイヤのオブジェクト。
		validate() で、m_pDedRosenと m_pDedDia の
		内容を反映します。
	*/
	CentDedDgrDia m_CentDedDgrDia ;

	///@}

	// ********************************
	///@name 状態
	// ********************************
	///@{
	/**
		validate() で初期化してから invalidate() で破棄するまでは true 。
	*/
	bool	m_bIsValid ;
	///@}
protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
		指定されたすべてのソート前列車に対して、
		「指定の駅Orderで、ソート後列車からソート前列車に乗換えができる」
		ソート後列車を探します。

		そのような組み合わせが見つかったら、
		ソート前列車の列車Indexを削除し、
		ソート後列車の後に移動します。
	@param pEstimateRessyaCont[in]
		ソート対象の列車を保持するコンテナ。
		この列車は、CentDedDgrDia::createEstimateRessya2()によって
		推定時刻が追加された列車でなくてはなりません。
	@param pcontRessyaIndexBeforeSort [in,out] 
		ソート前列車のインデクスの配列
	@param pcontRessyaIndexAfterSort[in,out] 
		ソート後列車のインデクスの配列
	@param iEkiOrder[in]
		乗換駅の駅Order を指定してください。
	@param pIfProgress [in]
		進捗状態の通知を受けたい場合は、進捗状態通知を受け取る
		インスタンスへのポインタを指定してください。
		NULLなら、この関数は進捗状態の通知を行いません。
	@param iMaxTransferSec[in]
		最大乗換え時間(秒数)を指定してください。
		INT_MAXを指定すると、無制限です。
	@return
		true: 処理中断が要求されました。
	*/
	bool sortRessyaIndex_TransferFromSortedRessyaAtEki( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		int iEkiOrder , 
		int iMaxTransferSec , 
		IfProgress* pIfProgress ) ;



	/**
		指定されたすべてのソート前列車に対して、
		「指定の駅Orderで、ソート前列車からソート後列車に乗換えができる」
		ソート後列車を探します。

		そのような組み合わせが見つかったら、
		ソート前列車の列車Indexを削除し、
		ソート後列車の前に移動します。
	@param pEstimateRessyaCont[in]
		ソート対象の列車を保持するコンテナ。
		この列車は、CentDedDgrDia::createEstimateRessya2()によって
		推定時刻が追加された列車でなくてはなりません。
	@param pcontRessyaIndexBeforeSort [in,out] 
		ソート前列車のインデクスの配列
	@param pcontRessyaIndexAfterSort[in,out] 
		ソート後列車のインデクスの配列
	@param iEkiOrder[in]
		乗換駅の駅Order を指定してください。
	@param pIfProgress [in]
		進捗状態の通知を受けたい場合は、進捗状態通知を受け取る
		インスタンスへのポインタを指定してください。
		NULLなら、この関数は進捗状態の通知を行いません。
	@param iMaxTransferSec[in]
		最大乗換え時間(秒数)を指定してください。
		INT_MAXを指定すると、無制限です。
	@return
		true: 処理中断が要求されました。
	*/
	bool sortRessyaIndex_TransferToSortedRessyaAtEki( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		int iEkiOrder , 
		int iMaxTransferSec , 
		IfProgress* pIfProgress ) ;



	/**
		指定されたすべてのソート前列車に対して、
		「指定の駅Order以後で、ソート後列車からソート前列車に乗換えができる」
		ソート後列車をすべて探します。

		そのような組み合わせが見つかったら、
		ソート前列車の列車Indexを削除し、
		ソート後列車の後に移動します。
	@param pEstimateRessyaCont[in]
		ソート対象の列車を保持するコンテナ。
		この列車は、CentDedDgrDia::createEstimateRessya2()によって
		推定時刻が追加された列車でなくてはなりません。
	@param pcontRessyaIndexBeforeSort [in,out] 
		ソート前列車のインデクスの配列
	@param pcontRessyaIndexAfterSort[in,out] 
		ソート後列車のインデクスの配列
	@param iEkijikokuOrder[in]
		ソートのキーとなる、駅Order を指定してください。
	@param pIfProgress [in]
		進捗状態の通知を受けたい場合は、進捗状態通知を受け取る
		インスタンスへのポインタを指定してください。
		NULLなら、この関数は進捗状態の通知を行いません。
	@return
		true: 処理中断が要求されました。
	*/
	bool sortRessyaIndex_TransferFromSortedRessya( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		CdDedJikokuOrder aEkijikokuOrder  , 
		IfProgress* pIfProgress ) ;

	/**
		指定されたすべてのソート前列車に対して、
		「指定の駅Order以前で、ソート前列車からソート後列車に乗換えができる」
		ソート後列車をすべて探します。

		そのような組み合わせが見つかったら、
		ソート前列車の列車Indexを削除し、
		ソート後列車の前に移動します。
	@param pEstimateRessyaCont[in]
		ソート対象の列車を保持するコンテナ。
		この列車は、CentDedDgrDia::createEstimateRessya2()によって
		推定時刻が追加された列車でなくてはなりません。
	@param pcontRessyaIndexBeforeSort [in,out] 
		ソート前列車のインデクスの配列
	@param pcontRessyaIndexAfterSort[in,out] 
		ソート後列車のインデクスの配列
	@param iEkijikokuOrder[in]
		ソートのキーとなる、駅Order を指定してください。
	@param pIfProgress [in]
		進捗状態の通知を受けたい場合は、進捗状態通知を受け取る
		インスタンスへのポインタを指定してください。
		NULLなら、この関数は進捗状態の通知を行いません。
	@return
		true: 処理中断が要求されました。
	*/
	bool sortRessyaIndex_TransferToSortedRessya( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		CdDedJikokuOrder aEkijikokuOrder , 
		IfProgress* pIfProgress ) ;
	///@}

	/**
		同じ駅の2つの駅時刻との間での乗り換え時間を計算します。
	@param aEkijikokuFrom [in]
		乗り換え元の列車の駅時刻を指定してください。
	@param aEkijikokuTo [in]
		乗り換え先の列車の駅時刻を指定してください。
	@param jikokuKitenJikoku [in]
		ダイヤグラム起点時刻を指定してください。
		この関数は、この時刻を越える乗り換えは不可能とみなします。
		(例：この時刻に5:00が指定された場合は、5:00<23:59<0:00<4:59 として比較を行います)
	@return
		同じ駅の2つの駅時刻との間での乗り換え時間(秒数)を返します。
		乗り換え不可能な場合は -1 を返します。

		以下の場合は乗り換え不可能として、-1を返します。	
			- どちらかの駅扱が「停車」でない場合。
	*/
	static int calcNorikaeSec( 
		const CentDedEkiJikoku& aEkiJikokuFrom , 
		const CentDedEkiJikoku& aEkiJikokuTo ,
		const CdDedJikoku& jikokuKitenJikoku ) ;
protected:
	// ================================
	///@name CDedRessyaSoater::sort の下請関数
	// ================================
	///@{
	/**
		指定された列車Indexをソートします。
	@param pRessyaCont [in]
		ソート対象の列車コンテナを指定してください。
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
		sortWithSortedRessyaIndex() に渡すことにより、
		列車コンテナをソートすることができます。

	*/
	virtual void sortRessyaIndex( 
		const CentDedRessyaCont* pRessyaCont , 
		Mui<int>* muRessyaIndexOrder , 
		IfProgress* pIfProgress )  ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
　	@param pDedRosen [in]
		ソートの対象となる列車を集約する路線オブジェクト。
	@param iDiaIndex [in]
		ソートの対象となる列車を集約するダイヤ。
	@param aCdDedJikokuOrder[in]
		ソート対象の 駅時刻Order。
	*/
	CDedRessyaSoater_Transfer(
		const CentDedRosen* pDedRosen , 
		const CentDedDia* pDedDia ,
		CdDedJikokuOrder  aCdDedJikokuOrder ) ;  

	virtual ~CDedRessyaSoater_Transfer() ;
	
public:
	// ********************************
	///@name CDedRessyaSoater_Transfer-属性
	// ********************************
	///@{
	///@}
	// ********************************
	///@name CDedRessyaSoater_Transfer-集約
	// ********************************
	///@{
	///@}
	// ********************************
	///@name CDedRessyaSoater_Transfer-操作-IfValidate
	// ********************************
	///@{
	/**
	 	　オブジェクトの準備処理を行い、有効化します。
	 	　準備処理にあたって必要なパラメータは、コンストラクタなどで
	 	指定している
	 	必要があります。
	 @return
	 	　有効化に成功したら１以上、
	 	　すでに有効化が終了していた場合は０、
	 	　エラーの場合は負の数を返します。\n
	 	　成功したときの１以上の値の意味は、実装するクラスが自由に定義
	 	できます。\n
	 	　失敗したときの負の数の意味も、実装クラスが定義できます。これにより、
	 	失敗の理由ごとに異なるエラー値を返すことができます。
	 	
	 */
	virtual int validate()  ;
	
	/**
	 	　オブジェクトを無効化します。
	 	　有効化時に確保したリソースを開放します。
	 	  有効状態でないオブジェクトに対しては、なにもしません。
	 */
	virtual void invalidate() ;
	
	/**
	 @return
	 	　現在オブジェクトが有効状態であれば真を返します。
	 */
	virtual bool isValid() ;
	///@}



};

} //namespace entDgr


#endif /*CDedRessyaSoater_Transfer_h*/
