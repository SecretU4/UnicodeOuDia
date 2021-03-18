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
//	CEnumRessyasen.h
// $Id: CEnumRessyasen.h 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
*/
#ifndef  CEnumRessyasen_h
#define  CEnumRessyasen_h
#include "entDgr\CentDedDgrDia.h"

namespace entDgr{

// ****************************************************************
//	CEnumRessyasen
// ****************************************************************
/**
@brief
	指定された『ダイヤグラムエンティティ座標』と交差するすべての列車線を
	列挙します。


	このクラスは、 CDcdDiagram のヘルパークラスです。
	『ダイヤグラム列車線』毎のループ処理を行う場合の、ループの
	エンジンとなります（ループ条件は結構複雑だからです）。

	『ダイヤグラムダイヤ』オブジェクトに包含されている
	『ダイヤグラム列車』 CentDedRessya・
	『ダイヤグラム列車線』 CentDedRessyasen・
	『ダイヤグラム駅時刻』 CentDedEkiJikoku
	オブジェクトのうち、
	指定された描画領域 CdDcdZoneXy の
	一部を通過する可能性のあるオブジェクトを列挙します。

【使い方】

	１．  このクラスの派生クラスを定義し、
	仮想関数 onCentDedDgrRessyasen() で
	『ダイヤグラム列車線』 CentDedDgrRessyasen 毎の処理、
	onCentDedDgrEkijikoku() で『ダイヤグラム駅時刻』CentDedDgrEkiJikoku ごとの
	処理を記述してください。

	２．  派生クラスのインスタンスを生成してください。
	コンストラクタでは、
	『ダイヤグラムダイヤ』オブジェクトと、描画先となる
	IfDcdTarget オブジェクトへのポインタを指定して下さい。

	３．  execute() を呼び出すと、このクラスは
	描画可能領域にある『ダイヤグラム列車線』毎に、
	仮想関数 onCentDedDgrRessyasen() を呼び出します。
*/
class CEnumRessyasen
{
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		『ダイヤグラムダイヤ』との関連です。

		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、 this の破棄が完了するまで
		生存しなくてはなりません。
		コンストラクタで決まります。
	 */
	const CentDedDgrDia*	m_pCentDedDgrDia ;
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		対象となる描画領域を、
		『ダイヤグラムエンティティ座標系』で保持します。
		これは、今回描画を行う範囲を表しています。
	
		コンストラクタで決まります。
	 */
	CdDcdZoneXy	m_zonexyDgrZone ;

	/**
		下り列車の処理を行うか否かを指定します。
		- true ;	//	下り列車の処理を行う。
		- false ;	//	上り列車の処理を行う。
		
		既定値は true 
	 */
	bool m_bDisplayRessyasenKudari ;
	/**
		上り列車の処理を行うか否かを指定します。
	 @see m_bDisplayRessyasenKudari
	 */
	bool m_bDisplayRessyasenNobori ;
	///@}
public:
	//*******************************
	//	コンストラクタ
	//*******************************
	/**
	 @param pCentDedDgrDia [in]
		『ダイヤグラムダイヤ』との関連です。
		このオブジェクトの破棄の責務は、クラスユーザーにあります。
		このオブジェクトは、 this の破棄が完了するまで
		生存しなくてはなりません。
	 @param zonexyDgrZone [in]
		対象となる描画領域を、
		『ダイヤグラムエンティティ座標系』で指定してください。
	 @param bDisplayRessyasenKudari [in]
		下り列車の処理を行うか否かを指定します。
		- true ;	//	下り列車の処理を行う。
		- false ;	//	下り列車の処理を行わない。
	 @param bDisplayRessyasenNobori [in]
		上り列車の処理を行うか否かを指定します。
	 */
	CEnumRessyasen( 
		const CentDedDgrDia* pCentDedDgrDia ,
		const CdDcdZoneXy& zonexyDgrZone ,
		bool bDisplayRessyasenKudari ,
		bool bDisplayRessyasenNobori ) ;
	virtual ~CEnumRessyasen() ;

protected:
	// --------------------------------
	///@name CEnumRessyasen
	// --------------------------------
	///@{
	/**
		execute() から呼び出される関数です。
	
		execute() は、描画可能領域にある
		『ダイヤグラム列車』 CentDedDgrRessya オブジェクト毎に、
		この関数を呼び出します。
		
	 @param eRessyahoukou [in]
		列車方向です。
	 @param iRessyaIdx [in]
		列車インデクスです。
	 @param pCentDedDgrRessya [in]
		『ダイヤグラム列車』 CentDedDgrRessya オブジェクトを指定します。
		
	 【オーバライド】
		このクラスは、『ダイヤグラム列車』 CentDedDgrRessya に
		包含されている 『ダイヤグラム列車線』 CentDedDgrRessyasen 
		オブジェクトのうち、描画可能領域にあるものを列挙し、
		onCentDedDgrRessyasen() を呼び出します。
	
	 */
	virtual void onCentDedDgrRessya( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ) ;

	/**
		execute() -> onCentDedDgrRessya() -> onCentDedDgrRessyasen() 
	 の順で呼び出される	関数です。
	
		execute() は、描画可能領域にある
		『ダイヤグラム列車線』 CentDedDgrRessyasen オブジェクト毎に、
		この関数を呼び出します。
		
	 @param eRessyahoukou [in]
		列車方向です。
	 @param iRessyaIdx [in]
		列車インデクスです。
	 @param aCentDedDgrRessya [in]
		『ダイヤグラム列車』 CentDedDgrRessya オブジェクトを指定します。
	 @param iRessyasenIdx [in]
		列車線インデクスです。
	 @param pCentDedDgrRessya [in]
		『ダイヤグラム列車線』 CentDedDgrRessyasen 
		オブジェクトを指定します。
		
	 【オーバライド】
		このクラスは、『ダイヤグラム列車線』CentDedDgrRessyasen の
		範囲内の『ダイヤグラム駅時刻』CentDedDgrEkiJikoku 
		オブジェクトを列挙 し、 onCentDedDgrEkiJikoku() を呼び出します。
		オーバライドして、
		『ダイヤグラム列車線』 CentDedDgrRessyasen オブジェクト毎の
		処理を記述してください。
	*/
	virtual void onCentDedDgrRessyasen( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ) ;
	/**
		execute() -> onCentDedDgrRessya() -> onCentDedDgrRessyasen() -> onCentDedDgrRessyasenEki()
	 の順で呼び出される	関数です。
	
		execute() は、描画可能領域にある
		『ダイヤグラム列車線の駅』 CentDedDgrRessyasenEki オブジェクト毎に、
		この関数を呼び出します。
		
	 @param eRessyahoukou [in]
		列車方向です。
	 @param iRessyaIdx [in]
		列車インデクスです。
	 @param aCentDedDgrRessya [in]
		『ダイヤグラム列車』 CentDedDgrRessya オブジェクトを指定します。
	 @param iRessyasenIdx [in]
		列車線インデクスです。
	 @param pCentDedDgrRessya [in]
		『ダイヤグラム列車線』 CentDedDgrRessyasen 
		オブジェクトを指定します。
	 @param iRessyasenEkiIdx [in]
		列車線の駅インデクスです。
	 @param pCentDedDgrRessya [in]
		『ダイヤグラム列車線の駅』 pCentDedDgrRessyasenEki 
		オブジェクトを指定します。
		
	 【オーバライド】
		オーバライドして、
		『ダイヤグラム列車線の駅』 CentDedDgrRessyasenEki オブジェクト毎の
		処理を記述してください。
	*/
	virtual void onCentDedDgrEkiJikoku( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ,
		int iEkiOrder , 
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku ) ;

	///@}

public:
	// ********************************
	///@name CEnumRessyasen-関連
	// ********************************
	///@{
	const CentDedDgrDia*	getCentDedDgrDia() ;
	///@}
	// ********************************
	///@name CEnumRessyasen-属性
	// ********************************
	///@{
	CdDcdZoneXy	getDgrZone() ;

	/**
		m_bDisplayRessyasenKudari , m_bDisplayRessyasenNobori 
		の値を取得します。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari ;	//	下り列車 (m_bDisplayRessyasenKudari)
		- Ressyahoukou_Nobori ; //	上り列車 (m_bDisplayRessyasenNobori)
	 @return 
		- true ;	//	列車を処理する
		- false ;	//	列車を処理しない。
	 */
	bool getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const ;
	///@}
	// ********************************
	///@name CEnumRessyasen-操作
	// ********************************
	///@{
	/**
		描画可能領域にある『ダイヤグラム列車線』毎に、
		仮想関数 onCentDedDgrRessyasen() を呼び出します。
	 */
	virtual void execute() ;
	///@}
};

} //namespace entDgr

#endif /*CEnumRessyasen_h*/

