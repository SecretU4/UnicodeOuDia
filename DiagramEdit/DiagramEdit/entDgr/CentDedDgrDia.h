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
//	CentDedDgrDia.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrDia_h
#define  CentDedDgrDia_h

#include "CentDedDgrEki.h"
#include "CentDedDgrEkiCont.h"
#include "CentDedDgrRessya.h"
#include "CentDedDgrRessyasyubetsu.h"
#include "NsMu/CMuiCopied.h"

namespace entDgr{

// ****************************************************************
//	CentDedDgrDia
// ****************************************************************
/**
@brief
【概要】
『ダイヤグラムエンティティクラス群』の『ダイヤグラムダイヤ』クラスです。
『ダイヤ』 １つを表します。『ダイヤグラムエンティティクラス群』の
ルートコンテナとして位置します。

このクラスは、
 - 『ダイヤグラム駅』(CentDedDgrEki)オブジェクト
 - 『ダイヤグラム列車種別』(CentDedDgrRessyastybetsu)オブジェクト
 - 『ダイヤグラム列車』(CentDedDgrRessya)オブジェクト

オブジェクトを包含します。
  『ダイヤグラム列車』オブジェクトは、下り・上りどちらの列車も
保持します。

<H4>
【使い方１・・・『路線』 (CentDedRosen) の情報を完全に反映する】
</H4>
 
 １．  コンストラクタでオブジェクトを生成してください。
 
 ２．  readCentDedRosen() 関数を呼び出してください。この関数は、
	『路線』 (CentDedRosen) オブジェクトに含まれる
	『駅』 (CentDedEki) ・『ダイヤ』 (CentDedDia) ・
	『列車種別』 (CentDedResstasyubetsu) ・
	『列車』 (CentDedRessya) オブジェクトをもとに、
	『ダイヤグラム駅』 (CentDedDgrEki) ・
	『ダイヤグラム列車種別』 (CentDedDgrResstastyvetsu) ・
	『ダイヤグラム列車』 (CentDedDgrRessya) オブジェクトを生成します。
 
 ３．  これで、ダイヤグラムの列車線を描画する情報がすべて揃ったことに
 なります。
 
   this の getDgrYPosOfEki() メソッドで、各駅のY座標を取得することが
 できます。
 
　『ダイヤグラム列車』 CentDedDgrRessya オブジェクトは、

	- 駅数分の『ダイヤグラム駅時刻』 CentDedDgrEkiJikoku オブジェクト
	- 0以上の『ダイヤグラム列車線』 CentDedDgrRessyasen オブジェクト

を包含しています。
 
　 『ダイヤグラム列車線』 CentDedDgrRessyasen オブジェクトの属性として、
 
 	- CentDedDgrRessyasen::m_iRessyasenKitenEkiOrder ・・・
    列車線起点駅Order。 『駅Order』で表します。
 	- CentDedDgrRessyasen::m_iRessyasenSyuutenEkiOrder ・・・
    列車線終点駅Order。 『駅Order』で表します。
 
 があります。

  以下の2点を結ぶ直線が、列車線となります。
  
- 【始点】
	- X座標：　列車線起点駅Orderの駅時刻の、発時刻相当のX座標
　	  (CentDedDgrEkiJikoku::m_iDgrXPosHatsu)
	- Y座標：　列車線起点駅のY座標(CentDedDgrDia::getDgrYPosOfEki() で求めることができます)

- 【終点】
	- X座標：　列車線終点駅Orderの駅時刻の、着時刻相当のX座標
　	  (CentDedDgrEkiJikoku::m_iDgrXPosChaku)
	- Y座標：　列車線終点駅のY座標(CentDedDgrDia::getDgrYPosOfEki() で求めることができます)

 列車線は折れ線ですので、
 一つの列車につき、折れ線の角の数＋１だけ、
 『ダイヤグラム列車線』 CentDedDgrRessyasen オブジェクトが存在します。
 
 詳細は、『ダイヤグラムエンティティ座標系』の説明をご覧ください。
 
<H4>
【使い方２・・・『列車』 (CentDedRessya) を変更する場合】
</H4>
 
   ある『列車』 (CentDedRessya) の属性・及び包含している
	『駅時刻』 (CentDedEkiJikoku) が変更された場合は、
 『ダイヤグラムダイヤ』 (CentDedDgrDia) オブジェクトに包含されている 
 『ダイヤグラム列車』 (CentDedDgrRessya) オブジェクトに対して、
  CentDedDgrRessya::readCentDedRessya() メソッドを呼び出してください。
 
 
<H4>
『ダイヤグラムエンティティ座標』
</H4>
 
   『ダイヤグラムエンティティクラス群』は、『ダイヤグラム』の列車線の
 座標を計算する能力を持っています。
 
   この座標計算は、『ダイヤグラムエンティティクラス群』特有の座標系を
 使って行います。
   以後、この座標系を『ダイヤグラムエンティティ座標系』と表記します。
 また、『ダイヤグラムエンティティ座標系』の 
 X座標を『ダイヤグラムエンティティX座標』(DgrX)・
 Y座標を『ダイヤグラムエンティティY座標』(DgrY)と表記します。
   
   通常のダイヤグラムでは、X方向の座標は時刻・Y方向の座標は路線の
 起点からの道のりを表します。
   『ダイヤグラムエンティティX座標』は、通常のダイヤグラムと同様、
 時刻を表します。値の単位は秒で、午前０時からの経過秒数を表します。
 　この値は、24*60*60 (24:00:00) 以上になる場合があります。
  
   『ダイヤグラムエンティティY座標』は、『駅間最小所要秒数』
 を基本とした値を使います。
   この値は、「その路線の（下り列車の）起点からの、最速の各駅停車の
 所要秒数」を秒単位で表したものとなります。
 
   実際に『ダイヤグラムビュー』にダイヤグラムを描画する際は、
 『ダイヤグラムエンティティ座標系』の値を、ビューのウインドウ座標系に
 変換する必要があります。この処理は、
 『ダイヤグラムエンティティクラス群』にはありませんので、
 クラスユーザーの側で行う必要があります(例: CDcdDiagram クラス)。
 
   『ダイヤグラムエンティティクラス群』では、Y座標の計算根拠となる
 『駅間最小秒数』を計算する際、『路線エンティティクラス群』の
 『ダイヤ』 (CentDedDia)に含まれるすべての『列車』の駅時刻を参照して、
 最小秒数を求めます( readCentDedRosen_02_updateEkiCont() )。
*/
class CentDedDgrDia
{
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		ダイヤの名称です。
	
		（例） "平日ダイヤ" など
	
		readCentDedRosen() で、決まります。
	 */
	std::string	m_strName ;

	/**
		ダイヤグラムの左端の『ダイヤグラムエンティティX座標』です。
	
		デフォルトでは  0 です。この場合、
		ダイヤグラムの左端は 00:00:00 となります。
	 */
	int m_iDgrXPosMin ;

	/**
	ダイヤグラムの既定の駅間幅。

	列車設定のない駅間の、ダイヤグラムビュー上での
	縦方向の幅を『ダイヤグラムエンティティY座標』単位(秒)で指定します。

	既定値は 60 です。
	*/
	int	m_iDgrYSizeEkikanDefault ;

	///@}
	
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
		『ダイヤグラム駅』オブジェクトを保持します。
	
		インデクスは、『駅Index』であり、下りの始発が0となります。
		下り列車の『駅Order』と同じです
	 */
	CentDedDgrEkiCont	m_CentDedDgrEkiCont ;

	/**
		『ダイヤグラム列車種別駅』オブジェクトを保持します。
	
		インデクスは、『駅Index』であり、下りの始発が0となります。
		下り列車の『駅Order』と同じです
	 */
	CMuiCopied< CentDedDgrRessyasyubetsu >	m_MuCentDedDgrRessyasyubetsu ;

	
	/**
		『ダイヤグラム列車』オブジェクトを保持します。
	
		m_CentDedDgrRessyaCont の添え字は、
	
		- [0] が下り列車 Ressyahoukou_Kudari
		- [1] が上り列車 Ressyahoukou_Nobori
	
		となります。
	
		m_CentDedDgrRessyaCont[] のインデクスは、『列車Index』です。
	*/
	CMuiCopied< CentDedDgrRessya >	m_CentDedDgrRessyaCont[2] ;
	///@}

private:
	// --------------------------------
	///@name readCentDedRosen() の下請関数
	// --------------------------------
	///@{
	/**
		CentDedEki::EDiagramRessyajouhouHyouji を
		CentDedDgrEki::EDiagramRessyajouhouHyouji に
		変換します。
	*/
	CentDedDgrEki::EDiagramRessyajouhouHyouji 
		CentDedEki_to_CentDedDgrEki_EDiagramRessyajouhouHyouji( 
			CentDedEki::EDiagramRessyajouhouHyouji  eValue ) ;

	/**
		readCentDedRosen() の下請関数です。	(1)CentDedDgrDiaの属性を設定

		　CentDedDgrDiaの以下の属性を、CentDedRosen,CentDedDia から決定

		//	ダイヤの名称です。
		std::string	m_strName ;	

		//	ダイヤグラムの左端の『ダイヤグラムエンティティX座標』です。
		int m_iXZahyouMin ;

		//	ダイヤグラムの既定の駅間幅。
		int	m_iDiagramDgrYZahyouKyoriDefault ;
	*/
	void readCentDedRosen_01_updateCentDedDgrDiaProp(
		const CentDedRosen* pCentDedRosen ,
		const CentDedDia* pCentDedDia ) ;

	/**
		readCentDedRosen() の下請関数です。	(2)CentDedDgrEkiを生成
	
		『路線エンティティクラス群』の『駅』オブジェクトと
		『ダイヤ』オブジェクトを参照して、『ダイヤグラム駅』オブジェクトを
		生成し、 m_CentDedDgrEkiCont コンテナに格納します。
		  
		   m_CentDedDgrEkiCont がそれまで保持していたオブジェクトは破棄します。
		
		  また、 m_CentDedDgrRessyaCont 内のすべての
		『ダイヤグラム列車』オブジェクトも破棄します。
	
		このとき、すべての列車を検索して、
		『駅間最小所要秒数』 CentDedDgrEki::m_iEkikanSaisyouSec を
		決定します。
	 @param pCentDedEkiCont [in]
		『路線エンティティクラス群』の『駅』オブジェクトのコンテナを
		指定してください。
		このコンテナのインデクスは、『駅Index』（下り列車の『駅Order』）
		でなくてはなりません。
	 @param pCentDedDia [in]
		対象となる『ダイヤ』オブジェクトを指定してください。
	 */
	void readCentDedRosen_02_updateEkiCont( 
		const Mu< const CentDedEki* >* pCentDedEkiCont , 
		const CentDedDia* pCentDedDia ) ;
	
	/**
		readCentDedRosen() の下請関数です。
		(3)CentDedDgrRessyasyubetsuを生成
	
		『路線エンティティクラス群』の『列車種別』オブジェクト
		を参照して、『ダイヤグラム列車種別』オブジェクトを
		生成し、 m_MuCentDedDgrRessyasyubetsu コンテナに格納します。
		  
	   m_MuCentDedDgrRessyasyubetsu がそれまで保持していたオブジェクトは破棄します。
		
	 @param pMuRessyasyubetsu [in]
		『路線エンティティクラス群』の『列車種別』オブジェクトのコンテナを
		指定してください。
	 */
	void readCentDedRosen_03_updateMuRessyasyubetsu( 
		const Mu< const CentDedRessyasyubetsu* >* pMuRessyasyubetsu ) ;
	
	/**
		readCentDedRosen() の下請関数です。
		(4)CentDedDgrRessya,CentDedDgrEkiJikokuを生成
	
		『路線エンティティクラス群』の
		『ダイヤ』オブジェクトを参照して、上り・下りすべての列車の
		『ダイヤグラム列車』オブジェクトを
		生成し、 m_CentDedDgrRessyaCont コンテナに格納します。
		これによって、
		『ダイヤグラム駅時刻』CentDedDgrEkiJikoku ・
		『ダイヤグラム列車線』CentDedDgrRessyasen 
		オブジェクトも生成します。
	
		   m_CentDedDgrRessyaCont がそれまで保持していたオブジェクトは
		破棄します。

		CentDedDgrRessyaの以下の属性を、CentDedRessya の属性から生成。
			- m_bIsNull 
			- m_eRessyahoukou 
			- m_iRessyasyubetsuIndex 
			- m_strRessyabangou 
			- m_strRessyamei 
			- m_strGousuu 
			- //m_strBikou 

		CentDedDgrEkiJikokuの以下の属性を、CentDedEkiJikokuの属性をもとに生成。
			- m_eEkiatsukai //駅扱
			- int	m_iDgrXZahyouChaku // INT_MINはNULL値を示します。
			- int	m_iDgrXZahyouHatsu // INT_MINはNULL値を示します。

		CentDedDgrRessyaの以下の属性を、CentDedDgrEkiJikokuの属性をもとに生成。
			- int	m_iDgrXZahyouMin
			- int	m_iDgrXZahyouMax

	 @param pCentDedRosen [in]
		対象となる『ダイヤ』を包含する路線オブジェクトを指定してください。
	 @param pCentDedDia [in]
		対象となる『ダイヤ』オブジェクトを指定してください。
	 */
	void readCentDedRosen_04_updateRessyaCont( 
		const CentDedRosen* pCentDedRosen , 
		const CentDedDia* pCentDedDia ) ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CentDedDgrDia() ;
	virtual ~CentDedDgrDia() ;
	
	
 public:
	// ********************************
	///@name	CentDedDgrDia-下請関数
	// ********************************
	///@{
	///@}

 public:
	// ********************************
	///@name CentDedDgrDia-属性
	// ********************************
	///@{
	virtual std::string	getName()const;
	virtual int getDgrXPosMin()const ;
	virtual CentDedDgrDia& setDgrXPosMin( int value ) ;
	virtual int getDgrYSizeEkikanDefault()const;
	///@}

	// ********************************
	///@name CentDedDgrDia-包含
	// ********************************
	///@{
	CentDedDgrEkiCont*	getCentDedDgrEkiCont();
	const CentDedDgrEkiCont*	getCentDedDgrEkiCont()const;
	
	Mui< CentDedDgrRessyasyubetsu >*	getMuCentDedDgrRessyasyubetsu() ;
	const Mu< const CentDedDgrRessyasyubetsu* >*	getMuCentDedDgrRessyasyubetsu()const ;


	/**
		『ダイヤグラム列車』オブジェクトを保持するコンテナへの
		インターフェースを取得することができます。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		-	下り :	Ressyahoukou_Kudari 
		-	上り : 	Ressyahoukou_Nobori 	
	 @return
		コンテナへのインターフェースを返します。
	
		このコンテナのインデクスは、『列車Index』です。
	 */
	virtual Mui< CentDedDgrRessya >*	getCentDedDgrRessyaCont( 
		 ERessyahoukou eRessyahoukou ) ;

	/**
		『ダイヤグラム列車』オブジェクトを保持するコンテナへの
		インターフェースを取得することができます。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		-	下り :	Ressyahoukou_Kudari 
		-	上り : 	Ressyahoukou_Nobori 	
	 @return
		コンテナへのインターフェースを返します。
	
		このコンテナのインデクスは、『列車Index』です。
	 */
	virtual const Mu< const CentDedDgrRessya* >*	getCentDedDgrRessyaCont( 
		 ERessyahoukou eRessyahoukou )const ;
	///@}

	// ********************************
	///@name CentDedDgrDia-操作
	// ********************************
	///@{
	/**
		『路線』 (CentDedRosen) オブジェクトに含まれる
		『駅』 (CentDedEki) ・『ダイヤ』 (CentDedDia) ・
		『列車』 (CentDedRessya) オブジェクトをもとに、
		『ダイヤグラム駅』 (CentDedDgrEki) ・
		『ダイヤグラム列車』 (CentDedDgrRessya) オブジェクトを生成します。
	
		   m_CentDedDgrRessyaCont がそれまで保持していたオブジェクトは
		破棄します。
		
	 @param pCentDedRosen [in]
		読み取る『路線』オブジェクトを指定して下さい。
	 @param pCentDedDia [in]
		対象となる『ダイヤ』オブジェクトを指定してください。
	 */
	virtual void readCentDedRosen( 
		const CentDedRosen* pCentDedRosen , 
		const CentDedDia* pCentDedDia ) ;
	
	
	/**
		『駅Order(駅方向別Index)』を、『駅Index』に変換します。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		のいずれかです。
	 @param iEkiOrder [in]
		『駅Order』を指定してください。
	 @return 
		0以上の『駅Index』を返します。
		引数が不正な場合は、 -1 を返します。
	 */
	virtual int EkiIndexOfEkiOrder( ERessyahoukou eRessyahoukou , 
		int iEkiOrder )const ;
	
	/**
		『駅Index』を『駅Order(駅方向別Index)』に変換します。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		のいずれかです。
	 @param iEkiIndex [in]
		『駅Index』を指定してください。
	 @return 
		0以上の『駅Order』を返します。
		引数が不正な場合は、 -1 を返します。
	 */
	virtual int EkiOrderOfEkiIndex(  ERessyahoukou eRessyahoukou , 
		int iEkiIndex )const ;
	
	/**
	 @return
		『ダイヤグラムエンティティ座標系』の範囲を返します。
	
		『ダイヤグラムエンティティX座標』の範囲は、 
		Pos が m_iXZahyouMin  , Size は 24*60*60 までです。
		これは、「ダイヤグラムは左端の時刻が m_iXZahyouMin となっており、
		横に２４時間分の長さを持っている」ことを示します。
	
	   『ダイヤグラムエンティティY座標』の値の範囲は、Pos が 0 ・ Size は
		起点から終点までの各駅間の『駅間最小秒数』と、
		全部の駅の『駅の幅』を合計したものとなります。
	 */
	virtual CdDcdZoneXy	getZone()const ;

	/**
		『駅Index』に対応する、『ダイヤグラムエンティティY座標』の値を
		求めます。
	 @param iEkiIndex [in]
		『駅Index』を指定してください。
		範囲は、 0 以上、m_CentDedDgrEkiCont.size() 未満です。
		INT_MAXは、末尾（下り列車の終着駅）を指定したことになります。
		これは、『ダイヤグラムエンティティY座標』の最大値となります。
	 @return
		『駅Index』に対応する『ダイヤグラムエンティティY座標』を返します。
		値は 0 以上です。
		『駅Index』が不正な場合は、 -1 を返します。
	
	 */
	virtual int getDgrYPosOfEki( int iEkiIndex )const ;
	
	/**
		『駅Order』に対応する、『ダイヤグラムエンティティY座標』の値を
		求めます。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		のいずれかです。
	 @param iEkiOrder [in]
		『駅Order』を指定してください。
		範囲は、 0 以上、m_CentDedDgrEkiCont.size() 未満です。
		INT_MAXは、末尾（終着駅）を指定したことになります。
		これは、『ダイヤグラムエンティティY座標』の最大値となります。
	 @return
		『駅Order』に対応する『ダイヤグラムエンティティY座標』を返します。
		値は 0 以上です。
		『駅Order』が不正な場合は、 -1 を返します。
	
	 */
	virtual int getDgrYPosOfEki( ERessyahoukou eRessyahoukou , 
		int iEkiOrder )const ;

	/**
		２つの駅の間の『ダイヤグラムエンティティY座標』による
		『駅間幅』の合計を求めます。
		この値は、各駅の駅幅は含めません。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		のいずれかです。
	 @param iEkiOrderOrg [in]
		起点側の『駅Order』を指定してください。
		範囲は、 0 以上、m_CentDedDgrEkiCont.size() 未満です。
		INT_MAXは、末尾（終着駅）を指定したことになります。
	 @param iEkiOrderDst [in]
		終点側の『駅Order』を指定してください。
		範囲は、 0 以上、m_CentDedDgrEkiCont.size() 未満です。
		INT_MAXは、末尾（終着駅）を指定したことになります。
	 @return
		『ダイヤグラムエンティティY座標』上での距離を返します。
		値は 0 以上です。
		パラメータが不正な場合は、 -1 を返します。
	 */
	virtual int getDgrYSizeEkikan( 
			ERessyahoukou eRessyahoukou , 
			int iEkiOrderOrg ,
			int iEkiOrderDst )const ;
	
	
	/**
		２つの駅の間の『駅間最小秒数』の和を
		求めます。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		のいずれかです。
	 @param iEkiOrderOrg [in]
		起点側の『駅Order』を指定してください。
		範囲は、 0 以上、m_CentDedDgrEkiCont.size() 未満です。
		INT_MAXは、末尾（終着駅）を指定したことになります。
	 @param iEkiOrderDst [in]
		『駅Order』を指定してください。
		範囲は、 0 以上、m_CentDedDgrEkiCont.size() 未満です。
		INT_MAXは、末尾（終着駅）を指定したことになります。
	 @return
		『駅Order』に対応する『駅間最小秒数』の値を返します。
		値は 0 以上です。
		パラメータが不正な場合は、 -1 を返します。
	
	 */
	virtual int getEkikanSaisyouSec( 
			ERessyahoukou eRessyahoukou , 
			int iEkiOrderOrg ,
			int iEkiOrderDst )const ;
	
	

	/**
		列車線の始点の
		『ダイヤグラムエンティティ座標』を算出します。
	@param pCentDedDgrRessya [in]
		列車線を包含する列車オブジェクトを指定してください。
	@param pCentDedDgrRessya [in]
		列車線オブジェクトを指定してください。
	@return
		列車線の始点のダイヤグラムエンティティ座標です。
	*/
	virtual CdDcdPosXy	calcDgrPosRessyasenKiten( 
		const CentDedDgrRessya* pCentDedDgrRessya , 
		const CentDedDgrRessyasen* pCentDedDgrRessyasen )const ;

	/**
		列車線の終点の
		『ダイヤグラムエンティティ座標』を算出します。
	@param pCentDedDgrRessya [in]
		列車線を包含する列車オブジェクトを指定してください。
	@param pCentDedDgrRessya [in]
		列車線オブジェクトを指定してください。
	@return
		列車線の始点のダイヤグラムエンティティ座標です。
	*/
	virtual CdDcdPosXy	calcDgrPosRessyasenSyuuten( 
		const CentDedDgrRessya* pCentDedDgrRessya , 
		const CentDedDgrRessyasen* pCentDedDgrRessyasen )const ;

	/**
		ダイヤグラム列車オブジェクトから、
		『推定時刻列車オブジェクト』を生成します。
	
	『推定時刻列車オブジェクト』

		すべての通過駅・停車駅の駅時刻として、
		列車線オブジェクトに準じた時刻が設定されます。

		列車線起点の駅時刻は、その駅の発時刻となります。
		列車線中間の駅時刻は、着・発とも列車線と駅線の交点の時刻となります。
		列車線終点の駅時刻は、その駅の着時刻となります。

	@param pCentDedDgrRessya [in]
		対象となる列車オブジェクトを指定してください。
	@param pCentDedRessya [out]
		この関数は、この列車オブジェクトに、『推定時刻』を書き込みます。

	@return
		常に 0 です。
	*/
	virtual void createEstimateRessya( 
		const CentDedDgrRessya* pCentDedDgrRessya ,
		CentDedRessya* pCentDedRessya )const ;

	/**
		ダイヤグラム列車オブジェクトから、
		『推定時刻列車オブジェクト』を生成します。
	
	『推定時刻列車オブジェクト』

		すべての通過駅・停車駅の駅時刻として、
		列車線オブジェクトに準じた時刻が設定されます。

		列車線起点の駅時刻は、その駅の発時刻となります。
		列車線中間の駅時刻は、着・発とも列車線と駅線の交点の時刻となります。
		列車線終点の駅時刻は、その駅の着時刻となります。

	@note createEstimateRessya() との違いは、経由なし区間にある同一駅名に、
		同一時刻を設定することです。

	@param pCentDedDgrRessya [in]
		対象となる列車オブジェクトを指定してください。
	@param pCentDedRessya [out]
		この関数は、この列車オブジェクトに、『推定時刻』を書き込みます。

	@return
		常に 0 です。
	*/
	virtual void createEstimateRessya2( 
		const CentDedDgrRessya* pCentDedDgrRessya ,
		CentDedRessya* pCentDedRessya )const ;

	///@}

};

} //namespace entDgr

#endif /*CentDedDgrDia_h*/
