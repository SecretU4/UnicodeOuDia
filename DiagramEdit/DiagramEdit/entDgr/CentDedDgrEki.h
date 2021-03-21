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
//	CentDedDgrEki.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrEki_h
#define  CentDedDgrEki_h


#include <string>

namespace entDgr{

// ****************************************************************
//	CentDedDgrEki
// ****************************************************************
/**
@brief
【概要】
『ダイヤグラムエンティティクラス群』の『ダイヤグラム駅』クラスです。
『ダイヤ』 (CentDedDgrDia) に含まれる『駅』１つを表します。

このクラスは、『ダイヤグラムダイヤ』 (CentDedDgrDia) に包含されます。

CentDedDgrDia : CentDedDgrEki の多重度は、

１：（『駅』の数） 

となります。

これは、

（『路線』(CentDedRosen)）：（『駅』（CentDedEki））

の多重度と同じです。

このクラスの属性として、『次駅までの駅間最小秒数』があります。
『次駅までの駅間最小秒数』から、『ダイヤグラムエンティティY座標』を導出します。

【使い方】

  原則では、このクラスのオブジェクトを生成するのは、
『ダイヤグラムダイヤ』 (CentDedDgrDia) クラスにのメソッドだけです。
クラスユーザーはこのクラスのオブジェクトを直接生成する用事はなく、
『ダイヤグラムダイヤ』 (CentDedDgrDia) クラスによって生成された
オブジェクトの属性を参照するだけです。


 */
class CentDedDgrEki
{
public:
	/**
		ダイヤグラム列車情報表示
	*/
	enum EDiagramRessyajouhouHyouji
	{
		/**
			始発駅の場合には表示(既定値)
		*/
		DiagramRessyajouhouHyouji_Origin ,
		/**
			常に表示する。
		*/
		DiagramRessyajouhouHyouji_Anytime ,
		/**
			表示しない。
		*/
		DiagramRessyajouhouHyouji_Not ,
	};

private:	
	// ********************************
	///@name	属性
	// ********************************
	///@{
	/**
	 	駅名。
	 */
	std::string  m_strEkimei ;
	
	/**
	 	主要駅なら真です。
	 */
	bool  m_bIsSyuyoueki ;
	
	/**
	 	下り列車の駅間最小秒数。
	 
	 	この属性は、この駅と次の駅Indexまでの間の、
		下り列車の最小所要秒数です。
	 
	 	この値は、『ダイヤグラムY座標』での、駅間幅として
	 	使います。『ダイヤグラム』での駅間幅（Y座標）は、
	 	m_iEkikanSaisyouSecKudari,m_iEkikanSaisyouSecNoboriのうち
	 	小さいほうの値となります。
	 
	 	下り列車から見ての終点駅では、この値は 0 です。
	 
	 	また、この駅間での駅間最小所要秒数が計算不能（データなし）の場合は、
	 	 0 です。
	 */
	int m_iEkikanSaisyouSecKudari ;
	/**
	 	上り列車の駅間最小秒数。
	 
	 	この属性は、この駅と次の駅Indexまでの間の、
		上り列車の最小所要秒数です。
	 
	 	下り列車から見ての終点駅では、この値は 0 です。
	 
	 	また、この駅間での駅間最小所要秒数が計算不能（データなし）の場合は、
	 	 0 です。
	 */
	int m_iEkikanSaisyouSecNobori ;

	/**
		ダイヤグラムの既定の駅間幅。

		列車設定のない駅間の、ダイヤグラムビュー上での
		縦方向の幅を『ダイヤグラムエンティティY座標』単位(秒)で指定します。
	
		既定値は 60 です。
	*/
	int	m_iDgrYSizeEkikanDefault ;

	/**
		ダイヤグラム列車情報表示（下り）
	
		既定値は DiagramRessyajouhouHyouji_Origin です。
	*/	
	EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyoujiKudari ;
	
	/**
		ダイヤグラム列車情報表示（上り）
	
		既定値は DiagramRessyajouhouHyouji_Origin です。
	*/
	EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyoujiNobori ;

	/**
		この駅のY座標の高さ。
		当面は、0です。
	*/
	int m_iDgrYSize ;
	///@}	

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 @param strEkimei [in]
		駅名。
	 @param bIsSyuyoueki [in]
		主要駅なら真
	 @param iEkikanSaisyouSecKudari [in]
		下り列車の駅間最小秒数。
	 @param iEkikanSaisyouSecNobori [in]
		上り列車の駅間最小秒数。
	 @param iDiagramDgrYZahyouKyoriDefault [in]
		ダイヤグラムの既定の駅間幅。
	 @param eDiagramRessyajouhouHyoujiKudari [in]
		ダイヤグラム列車情報表示（下り）
	 @param eDiagramRessyajouhouHyoujiNobori [in]
		ダイヤグラム列車情報表示（上り）
	*/
	CentDedDgrEki( const std::string&  strEkimei ,
		bool bIsSyuyoueki , 
		int iEkikanSaisyouSecKudari ,
		int iEkikanSaisyouSecNobori , 
		int	iDiagramDgrYZahyouKyoriDefault , 
		EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyoujiKudari ,
		EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyoujiNobori 
		) ;
	

	CentDedDgrEki() ;
	
	virtual ~CentDedDgrEki();
	
// ********************************
//	CentDedDgrEki
// ********************************
 public:
	// ********************************
	///@name	CentDedDgrEki-属性
	// ********************************
	///@{
	std::string  getEkimei()const{ return m_strEkimei ;};
	bool getIsSyuyoueki()const{	return m_bIsSyuyoueki ; } ;
	int getEkikanSaisyouSecKudari()const
	{	return m_iEkikanSaisyouSecKudari ; };
	int getEkikanSaisyouSecNobori()const
	{	return m_iEkikanSaisyouSecNobori ; };
	int	getDgrYSizeEkikanDefault()const
	{	return m_iDgrYSizeEkikanDefault ;};

	EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyoujiKudari()const
	{	return m_eDiagramRessyajouhouHyoujiKudari ;};
	EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyoujiNobori()const
	{	return m_eDiagramRessyajouhouHyoujiNobori ;};
	int getDgrYSize()const{	return m_iDgrYSize ;};
	///@}
	// ********************************
	///@name	CentDedDgrEki-操作
	// ********************************
	///@{
	/**
	  @return
	 	この駅から下り方向の次の駅（『駅Index』が次の駅）までの、
	 	『ダイヤグラムエンティティY座標』での距離を返します。
	 
	 	  この値は、『下り列車の駅間最小秒数』と『上り列車の駅間最小秒数』の
	 	うちの小さいほうです。
	 
	 	  但し、『下り列車の駅間最小秒数』が 0 以下・『上り列車の駅間最小秒数』
	 	が 1 以上の場合は、この値は『上り列車の駅間最小秒数』となります。
	 	反対に、『上り列車の駅間最小秒数』が 0 以下・
	 	『下り列車の駅間最小秒数』が 1 以上の場合は、この値は
	 	『下り列車の駅間最小秒数』となります。
	 
	 	  この値の最小値は60です。
	 */
	int getDgrYZahyouKyori()const ;
	///@}

};

} //namespace entDgr
#endif /*CentDedDgrEki_h*/
