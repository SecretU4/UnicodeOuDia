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
// ****************************************************************
//$Id: CdDedJikokuOrder.h 373 2016-08-20 21:59:57Z okm $
// ****************************************************************
/** @file */


#ifndef CdDedJikokuOrder_h
#define CdDedJikokuOrder_h

namespace entDed{

// ****************************************************************
//	CdDedJikokuOrder
// ****************************************************************

/**
@brief
    CdDedJikokuOrder は、駅時刻の要素を特定する値です。

これは、時刻表の各列に表示すべき内容の種類を示す値でもあります。
以下の属性からなります。

 - 駅Order
 - 表示内容{着・発}

このクラスは、NULL状態を持つことができます。
*/
class CdDedJikokuOrder
{
public:
	/** 駅時刻の要素を表す列挙です。 */
	enum EEkiJikokuItem
	{
		EkiJikokuItem_Chaku = 0 ,	///<着時刻
		EkiJikokuItem_Hatsu = 1 ,	///<発時刻
	};
private:
	/**
		時刻Order。
		この値が負の数の場合は、NULL状態となります。
	*/
	int m_iEkiOrder ;
	/**
		駅時刻の要素
	*/
	EEkiJikokuItem m_eEkiJikokuItem  ;
public:
	/**
		NULL 状態で初期化します。
	*/
	CdDedJikokuOrder() 
		: m_iEkiOrder( -1 )
		, m_eEkiJikokuItem( EkiJikokuItem_Chaku ){};

	/** 
	@param iEkiOrder [in]
		駅Order 
	@param eEkiJikokuItem [in]
		駅時刻の要素
	*/
	CdDedJikokuOrder( int iEkiOrder , EEkiJikokuItem eEkiJikokuItem ) 
		: m_iEkiOrder( iEkiOrder ) 
		, m_eEkiJikokuItem( eEkiJikokuItem ) 
	{};


	bool getIsNull()const{	return m_iEkiOrder < 0 ;};
	void setIsNull()
	{	
		m_iEkiOrder = -1 ; 
		m_eEkiJikokuItem = EkiJikokuItem_Chaku ;
	};

	int getEkiOrder()const{	return m_iEkiOrder ;};
	EEkiJikokuItem getEkiJikokuItem()const{	return m_eEkiJikokuItem ;};

	/** 
	@param iEkiOrder [in]
		駅Order 
	@param eEkiJikokuItem [in]
		駅時刻の要素を表す列挙
	*/
	void setEkiOrder( int iEkiOrder , EEkiJikokuItem eEkiJikokuItem )
	{
		m_iEkiOrder = iEkiOrder ;
		m_eEkiJikokuItem = eEkiJikokuItem ;
	};

	/**
		EEkiJikokuItem の着・発を反転します。
	@param eEkiJikokuItem [in]
		反転したい EkiJikokuItem を指定してください。
	@return
		- eEkiJikokuItem が EkiJikokuItem_Chaku なら、EkiJikokuItem_Hatsu。
		- eEkiJikokuItem が EkiJikokuItem_Hatsu なら、EkiJikokuItem_Chaku。
		- それ以外の場合は、eEkiJikokuItem をそのまま返します。
	*/
	static EEkiJikokuItem EkiJikokuItemInvert( 
		EEkiJikokuItem eEkiJikokuItem )
	{
		EEkiJikokuItem	eRv = eEkiJikokuItem ;
		if ( eRv == EkiJikokuItem_Chaku )
		{
			eRv = EkiJikokuItem_Hatsu ;
		}
		else if ( eRv == EkiJikokuItem_Hatsu )
		{
			eRv = EkiJikokuItem_Chaku ;
		}
		return eRv ;
	}

	/**
		m_eEkiJikokuItem の着・発を反転します。

		- m_eEkiJikokuItem が EkiJikokuItem_Chaku なら、EkiJikokuItem_Hatsu。
		- m_eEkiJikokuItem が EkiJikokuItem_Hatsu なら、EkiJikokuItem_Chaku。
		- それ以外の場合は、eEkiJikokuItem をそのまま返します。
	*/
	void EkiJikokuItemInvert( void )
	{
		m_eEkiJikokuItem = EkiJikokuItemInvert( m_eEkiJikokuItem ) ;
	}

	bool isEqualTo( const CdDedJikokuOrder& value )const
	{
		return ( m_iEkiOrder == value.m_iEkiOrder && 
				m_eEkiJikokuItem == value.m_eEkiJikokuItem ) 
			|| ( getIsNull() && value.getIsNull() );
	};

	bool operator==(  const CdDedJikokuOrder& value )const
	{	return isEqualTo( value ) ;	}
	bool operator!=(  const CdDedJikokuOrder& value )const
	{	return !isEqualTo( value ) ;	}
};

} //namespace entDed

#endif /*CdDedJikokuOrder_h*/
