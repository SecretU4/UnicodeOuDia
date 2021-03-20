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
//	CentDedDgrEkiJikoku.h
//	$Id: CentDedDgrEkijikoku.h 241 2016-01-05 06:14:33Z okm $
// ****************************************************************
*/
/** @file */
#ifndef CentDedDgrEkiJikoku_h
#define CentDedDgrEkiJikoku_h
#include "entDed\CentDedEkiJikoku.h"

namespace entDgr{
	using namespace entDed;
// ****************************************************************
//	CentDedDgrEkiJikoku
// ****************************************************************
/**
@brief 
  ダイヤグラム上における、列車の各駅での駅時刻を表します。
  
  このクラスは、 CentDedDgrRessya に集約されます。

  CentDedDgrRessya : CentDedDgrEkiJikoku の多重度は、1 : 駅数 です。
*/
class CentDedDgrEkiJikoku
{
private:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	/**
		駅扱。
	 */
	CentDedEkiJikoku::EEkiatsukai	m_eEkiatsukai ;
	
	/**
		着時刻に対応するダイヤグラムX座標。
		負の数・24:00:00 以上を表すこともあります。

		但し、 INT_MIN はNULL(指定なし)を表します。
	
		m_eEkiatsukai が
		運行なし ( Ekiatsukai_None ),
		経由なし ( Ekiatsukai_Keiyunasi ) の場合は、
		この値は意味を持ちません。
	 */
	int m_iDgrXPosChaku ;
	
	/**
		発時刻に対応するダイヤグラムX座標。

		但し、 INT_MIN はNULL(指定なし)を表します。
	
		m_eEkiatsukai が
		運行なし ( Ekiatsukai_None ),
		経由なし ( Ekiatsukai_Keiyunasi ) の場合は、
		この値は意味を持ちません。
	 */
	int m_iDgrXPosHatsu ;
	
	
	/**
		ダイヤグラム列車線のX座標

		この駅時刻がダイヤグラム列車線の中間になる場合は、
		ダイヤグラム列車線と、この駅(のY座標・横軸)との交点の
		ダイヤグラムX座標を保持します。
		そうでない場合は、INT_MIN です。
		INT_MIN はNULL(指定なし)を表します。

		負の数・24:00:00 以上を表すこともあります。
		
		
		この駅時刻がダイヤグラム列車線の端点にある場合も、
		この値は NULL になります。

		m_eEkiatsukai が
		運行なし ( Ekiatsukai_None ),
		経由なし ( Ekiatsukai_Keiyunasi ) の場合は、
		この値は意味を持ちません。
		
		(例）
		
		前駅からの駅間最小所要分数が以下のとおりの路線があったとします。

		@code
		-------------------
		駅Order0 発 
		駅Order1 発 01
		駅Order2 着 01
		-------------------
		@endcode

		ここに以下のような列車が設定され、列車線が駅Order0-駅Order2に
		設定された場合、

		@code
		-------------------
		駅Order0 発 10:00
		駅Order1 発 10:01
		駅Order2 着 10:03
		-------------------
		@endcode

		駅Order1の m_iDgrXPosRessyasen は、 10:01:30
		(10:00〜10:03を結ぶ直線と 駅Order1 の交点)
		になります。
		
	 */
	int m_iDgrXPosRessyasen ;


	/**
		この駅時刻の位置に列車情報(列車番号・列車名・号数)を
		描画する必要があるなら true 。

		既定は false ですが、 CentDedDgrRessya::readCentDedRessya() 
		によって設定されます。
	*/
	bool m_bShouldRessyajouhouDraw ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CentDedDgrEkiJikoku() :
		m_eEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ),
		m_iDgrXPosChaku( INT_MIN ) ,
		m_iDgrXPosHatsu( INT_MIN ) ,
		m_iDgrXPosRessyasen( INT_MIN ) ,
		m_bShouldRessyajouhouDraw( false )
	{
	}
	
	CentDedDgrEkiJikoku( 
		CentDedEkiJikoku::EEkiatsukai eEkiatsukai , 
		int iDgrXPosChaku ,
		int iDgrXPosHatsu ,
		int iDgrXPosRessyasen = INT_MIN ) :
		m_eEkiatsukai( eEkiatsukai ),
		m_iDgrXPosChaku( iDgrXPosChaku ) ,
		m_iDgrXPosHatsu( iDgrXPosHatsu ) ,
		m_iDgrXPosRessyasen( iDgrXPosRessyasen ),
		m_bShouldRessyajouhouDraw( false )
	{
	}

public:
	// ********************************
	///@name CentDedDgrEkiJikoku-属性
	// ********************************
	///@{
	CentDedEkiJikoku::EEkiatsukai getEkiatsukai()const 
	{	return 	m_eEkiatsukai ;};
	
	/**
		着時刻の X座標 です。
	@param bHatsuIfNull [in]
		-	false ;	//	着時刻がNULLなら NULL(INT_MIX) を返します。
		-	true  ;	//	着時刻がNULLなら 発時刻(INT_MIX) を返します。
	*/
	int getDgrXPosChaku( bool bHatsuIfNull = false )const
	{
		int iRv = m_iDgrXPosChaku ;
		if ( iRv == INT_MIN && bHatsuIfNull )
		{
			iRv = m_iDgrXPosHatsu ;
		}
		return iRv ;
	};
	void setDgrXPosChaku( int value )
	{	m_iDgrXPosChaku = value ;};

	/**
		発時刻の X座標 です。
	@param bChakuIfNull [in]
		-	false ;	//	発時刻がNULLなら NULL(INT_MIX) を返します。
		-	true  ;	//	発時刻がNULLなら 発時刻(INT_MIX) を返します。
	*/
	int getDgrXPosHatsu( bool bChakuIfNull = false )const
	{
		int iRv = m_iDgrXPosHatsu ;
		if ( iRv == INT_MIN && bChakuIfNull )
		{
			iRv = m_iDgrXPosChaku ;
		}
		return iRv ;
	};
	void setDgrXPosHatsu( int value )
	{	m_iDgrXPosHatsu = value ;};

	int getDgrXPosRessyasen()const
	{	return m_iDgrXPosRessyasen ;};
	void setDgrXPosRessyasen( int value )
	{	m_iDgrXPosRessyasen = value ; };

	bool getShouldRessyajouhouDraw()const
	{	return m_bShouldRessyajouhouDraw ;};
	void setShouldRessyajouhouDraw( bool value )
	{	m_bShouldRessyajouhouDraw = value ;};

	///@}
	// ********************************
	///@name CentDedDgrEkiJikoku-操作
	// ********************************
	///@{
	/**
		すべての『ダイヤグラム駅時刻』オブジェクトの
		『ダイヤグラムエンティティX座標』を加算・減算します(NULLを示す INT_MIN は除く。
	 @param iSeconds [in]
		加算・減算する値（秒数・『ダイヤグラムエンティティX座標』）	
		を指定して下さい。
	 */
	virtual void modifyDgrXPos( int iSeconds ) 
	{
		if ( m_iDgrXPosChaku != INT_MIN )
		{
			m_iDgrXPosChaku += iSeconds ;
		}
		if ( m_iDgrXPosHatsu != INT_MIN )
		{
			m_iDgrXPosHatsu += iSeconds ;
		}
		if ( m_iDgrXPosRessyasen != INT_MIN )
		{
			m_iDgrXPosRessyasen += iSeconds ;
		}
	}
	///@}
};


} //namespace entDgr

#endif /*CentDedDgrEkiJikoku_h*/


