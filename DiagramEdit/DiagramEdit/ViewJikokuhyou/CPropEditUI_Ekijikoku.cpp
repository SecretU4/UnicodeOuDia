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
//	$Id: CPropEditUI_Ekijikoku.cpp 357 2016-08-18 16:59:16Z okm $
// ****************************************************************

/** @file */

#include "stdafx.h"
#include "NsMu\CConvTable.h"
#include "CPropEditUi_EkiJikoku.h"
#include "str\CStrCharSizeMb.h"
#include "str\strLf.h"

namespace ViewJikokuhyou{
	using namespace OuLib::Str;

		
/** ダイアログボックスへの時刻の書式を保持します。 */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	true ,		//	NoColon 
	CdDedJikoku::CConv::EHour_ZeroToNone ,		//	HourZeroToNone 
	CdDedJikoku::CConv::ESecond_NotIfZero ) ;	//	NoSecond


/**
	時刻のUI形式を解釈して、時刻に変換します。
	エディットコントロールの内容が2桁数字の場合は、
	前の駅時刻Orderをもとに、時を補完します。
@param strUIJikoku [in]
	UI形式の時刻を指定してください。
@param jikokuRevOrder [in]
	直前の『駅時刻』。
	この値は、strControlが分のみ(数字2桁)の場合、時を補完するのに使います。
	『NULL状態』の場合、時の補完は行われません。
@param pCdDedJikoku [out]
	この関数は、文字列の解釈に成功したら、文字列の内容を変換した時刻を
	ここに書き込みます。
@return
	成功したら 0 以上。時刻への変換ができなければ負の数です。
	-	-1 ;	//	項目数が不足しています。
	-	-2 ;	//	時・分・秒の表記が不正です。
*/
static int	getJikokuFromUI( 
	const string& strUIJikoku , 
	const CdDedJikoku& jikokuRevOrder , 
	CdDedJikoku* pCdDedJikoku ) 
{
	int	iRv = 0 ;
	CdDedJikoku	aCdDedJikoku ;
	string	strControl = CStrCharSizeMb::strToSingleByte( 
		OuLib::Str::strTrim( strUIJikoku ) ) ;

	int iResult = aCdDedJikoku.decode( strControl ) ;
	if ( iResult < 0 )
	{
		iRv = iResult ;
		//	文字列が解釈できません。
	}
	//iRv = 
	//-	-1 ;	//	項目数が不足しています。
	//-	-2 ;	//	時・分・秒の表記が不正です。

	//	着時刻が2桁で、前の駅時刻がある場合は、
	//	着時刻に時を補完
	if ( iRv == -1 && 
		 !jikokuRevOrder.isNull() && 
		strControl.size() == 2 && 
		isdigit( strControl[0] ) && 
		isdigit( strControl[1] ) )
	{
		int iMin = atoi( strControl.c_str() ) ;
		if ( 0 <= iMin && iMin < 60 )
		{
			aCdDedJikoku.setTime( jikokuRevOrder.getHour() , iMin ) ;
			CdDedJikan	jikanSub = aCdDedJikoku.subJikoku( 
				jikokuRevOrder ) ;
			if ( jikanSub.getTotalSeconds() < 0 )
			{
				aCdDedJikoku = aCdDedJikoku.getTotalSeconds() + 60*60 ;
			}
			//aCdDedJikoku = 現在入力された2桁の文字列に、
			//	jikokuRevOrder 以後となる時を補完

			iRv = 0 ;	//	時刻補完に成功しました。 
		}
	}

	// --------------------------------
	if ( pCdDedJikoku != NULL )
	{
		*pCdDedJikoku = aCdDedJikoku ;
	}
	return iRv ;
}

	// ********************************
	//@name エラーメッセージ
	// ********************************
const char* const CPropEditUi_EkiJikoku::ERRMSG_INVALID_CHAKUJIKOKU = "Invalid ChakuJikoku.";
const char* const CPropEditUi_EkiJikoku::ERRMSG_INVALID_HATSUJIKOKU = "Invalid HatsuJikoku.";




	// ================================
	//@name 下請関数
	// ================================


const CConvTable<CentDedEkiJikoku::EEkiatsukai,int>& getEkiatsukaiConvTable()
{
	static CConvTable<CentDedEkiJikoku::EEkiatsukai,int>	aTable ;
	if ( aTable.size() == 0 )
	{
		aTable.add( CentDedEkiJikoku::Ekiatsukai_None     , 0 ) ;//	運行なし
		aTable.add( CentDedEkiJikoku::Ekiatsukai_Teisya   , 1 ) ;//	停車
		aTable.add( CentDedEkiJikoku::Ekiatsukai_Tsuuka   , 2 ) ;//	通過
		aTable.add( CentDedEkiJikoku::Ekiatsukai_Keiyunasi, 3 ) ;// 経由なし
	}
	return aTable ;
}

	// ================================
	//@name UiData - Target間のデータ転送
	// ================================

	

void CPropEditUi_EkiJikoku::UiDataFromTarget( UIDATA* pUiData ) 
{
	CdDedJikoku::CConv	aJikokuConv( g_CdDedJikokuConv ) ;
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		CentDedRessya* pRessya = m_pTarget->get( i ) ;
		CentDedEkiJikoku aEkiJikoku 
			= pRessya->getCentDedEkiJikoku( m_iEkiOrder ) ;

		/*	 駅扱 
			 -	 0: 運行なし
			 -	 1: 停車
			 -	 2: 通過
			 -	 3: 経由なし
			 -	-1: 選択なし
		*/
		if ( i == 0 )
		{
			pUiData->iEkiatsukai = getEkiatsukaiConvTable().rightFrom( 
				aEkiJikoku.getEkiatsukai() ) ;
		}
		else if ( pUiData->iEkiatsukai != getEkiatsukaiConvTable().rightFrom( 
			aEkiJikoku.getEkiatsukai() ) )
		{
			pUiData->iEkiatsukai = -1 ;
		}

		/* 着時刻	*/
		if ( i == 0 )
		{
			//	単一選択時、
			//	駅扱が通過・停車なら、有効・Targetを反映
			//　　経由なしなら有効･空
			//　　運行なしなら有効･空
			if ( pUiData->iEkiatsukai == 1		// 停車
				|| pUiData->iEkiatsukai ==2 )	// 通過
			{
				pUiData->strChakujikoku = aJikokuConv.encode( 
					aEkiJikoku.getChakujikoku() ) ;
			}
			pUiData->bChakujikokuIsEnable = true ;
		}
		else 
		{
			//複数選択時は、着時刻は空・無効
			pUiData->strChakujikoku = "" ;
			pUiData->bChakujikokuIsEnable = false ;
		}

		/* 発時刻	*/
		if ( i == 0 )
		{
			//	単一選択時、
			//	駅扱が通過・停車なら、有効・Targetを反映
			//　　経由なしなら有効･空
			//　　運行なしなら有効･空
			if ( pUiData->iEkiatsukai == 1		// 停車
				|| pUiData->iEkiatsukai ==2 )	// 通過
			{
				pUiData->strHatsujikoku 
					= aJikokuConv.encode( aEkiJikoku.getHatsujikoku() ) ;
			}
			pUiData->bHatsujikokuIsEnable = true ;
		}
		else
		{
			//複数選択時は、発時刻は空・無効
			pUiData->strHatsujikoku = "" ;
			pUiData->bHatsujikokuIsEnable = false ;
		}
	}
	// --------------------------------

	//	 時刻の繰上げ・繰り下げのON/OFF。
	pUiData->bModifyHatsujikoku = *m_pbModifyHatsujikoku ;

}
void CPropEditUi_EkiJikoku::AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
{
	//	駅扱
	if ( bStartEdit || pUiDataPrev->iEkiatsukai != pUiData->iEkiatsukai )
	{
	}
	
	//	駅扱に関係する正規化
	{
		//◇[単一選択時]
		if ( m_pTarget->size() == 1 )
		{
			//　○【駅扱】駅扱が運行なし・経由なしで、
			//	着時刻か発時刻が変更されたら、駅扱は停車にする
			{
				if ( ( pUiData->iEkiatsukai == 0 || pUiData->iEkiatsukai == 3 )
					&& !bStartEdit
					&& ( pUiDataPrev->strChakujikoku != pUiData->strChakujikoku
					 || pUiDataPrev->strHatsujikoku != pUiData->strHatsujikoku)
				 )
				{
					pUiData->iEkiatsukai = 1 ;	
				}
			}
			//　○【着時刻・発時刻】駅扱が運行なし・経由なしに変更されたら、
			//	着時刻・発時刻は無効にする
			//　○【着時刻・発時刻】駅扱が停車・通過に変更されたら、着
			//	時刻・発時刻は有効にする。
			{
				if ( !bStartEdit 
					&& pUiDataPrev->iEkiatsukai !=  pUiData->iEkiatsukai )
				{
					if ( pUiData->iEkiatsukai == 0 
						|| pUiData->iEkiatsukai == 3 )
					{
						pUiData->bChakujikokuIsEnable = false ;
						pUiData->bHatsujikokuIsEnable = false ;
					}
					else 
					{
						pUiData->bChakujikokuIsEnable = true ;
						pUiData->bHatsujikokuIsEnable = true ;
					}
				}
			}
		}
		//◇［複数選択時]
		else if ( m_pTarget->size() > 1 )
		{
			//　○【着時刻・発時刻】着時刻・発時刻は無効・空
			pUiData->bChakujikokuIsEnable = false ;
			pUiData->bHatsujikokuIsEnable = false ;
		}
	}


	//	直前の時刻Orderの駅時刻を取得
	//	この値は、時が省略されて分のみが入力されたときに、
	//	時を補完するのに使います。
	CdDedJikoku jikokuRevOrder ;
	if ( pUiData->bChakujikokuIsEnable )
	{
		CentDedRessya* pRessya = m_pTarget->get( 0 ) ;
		CdDedJikokuOrder aJikokuOrderRev = pRessya->findrevJikoku( 
			CdDedJikokuOrder( m_iEkiOrder - 1 , 
				CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ) ;
		if ( !aJikokuOrderRev.getIsNull() )
		{
			jikokuRevOrder = pRessya->getEkiJikoku( aJikokuOrderRev ) ;
		}
	}
	//jikokuRevOrder = 直前の時刻Orderの駅時刻

	/*  着時刻	*/
	if ( bStartEdit || pUiDataPrev->strChakujikoku != pUiData->strChakujikoku )
	{
		//　○【着時刻】着時刻が変更されたら、
		//　　(1)文字列を半角に変換
		//　　(2)着時刻に2桁入力なら、時を補完します。
		if ( pUiData->bChakujikokuIsEnable )
		{
			CdDedJikoku aJikoku ;
			int iResult = getJikokuFromUI( 
				pUiData->strChakujikoku , 
				jikokuRevOrder , 
				&aJikoku ) ;
			if ( iResult >= 0 )
			{
				pUiData->strChakujikoku = g_CdDedJikokuConv.encode( aJikoku ) ;
			}
		}
	}
	
	//	直前の時刻Orderを着時刻で更新。
	//	この値は、時が省略されて分のみが入力されたときに、
	//	時を補完するのに使います。
	{
		CdDedJikoku aJikoku( pUiData->strChakujikoku ) ;
		if ( !aJikoku.isNull() )
		{
			jikokuRevOrder = aJikoku ;
		}
	}
		//jikokuRevOrder = 直前の時刻Orderの駅時刻。
		//	但し、着時刻の入力があれば、着時刻。

	/* 発時刻	*/
	if ( bStartEdit || pUiDataPrev->strHatsujikoku != pUiData->strHatsujikoku )
	{
		//　○【発時刻】発時刻が変更されたら、
		//　　(1)文字列を半角に変換
		//　　(2)着時刻に2桁入力なら、時を補完します。
		if ( pUiData->bHatsujikokuIsEnable )
		{
			CdDedJikoku aJikoku ;
			int iResult = getJikokuFromUI( 
				pUiData->strHatsujikoku , 
				jikokuRevOrder , 
				&aJikoku ) ;
			if ( iResult >= 0 )
			{
				pUiData->strHatsujikoku = g_CdDedJikokuConv.encode( aJikoku ) ;
			}
		}
	}
	//　○【発時刻】着時刻が変更され、『時刻の繰上げ・繰り下げ』=『有効』で、
	//		発時刻が入力済みなら、発時刻の繰上げ・繰り下げを行います。　
	if ( !bStartEdit 
		&& pUiDataPrev->strChakujikoku != pUiData->strChakujikoku )
	{
		if ( pUiData->bModifyHatsujikoku )
		{
			//	着時刻の前回値・現在値・発時刻の入力を取得
			CdDedJikoku	jikokuChakuPrev( pUiDataPrev->strChakujikoku ) ;
			CdDedJikoku	jikokuChaku( pUiData->strChakujikoku ) ;
			CdDedJikoku jikokuHatsu( pUiData->strHatsujikoku ) ;
			if ( !jikokuChakuPrev.isNull() 
				&& !jikokuChaku.isNull()
				&& !jikokuHatsu.isNull() )
			{
				jikokuHatsu.addSeconds( jikokuChaku.subJikoku( jikokuChakuPrev ) );
				pUiData->strHatsujikoku = g_CdDedJikokuConv.encode( jikokuHatsu ) ;
			}
		}
	}
}	

int CPropEditUi_EkiJikoku::CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	//	駅扱
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iEkiatsukai != pUiData->iEkiatsukai )
		{
		}
	}
	//	着時刻
	if ( iRv >= 0 )
	{
		if ( bNewItem 
			|| pUiDataStartEdit->strChakujikoku != pUiData->strChakujikoku )
		{
			//　○【着時刻】着時刻が空文字列でないなら、
			//	値の時刻への変換を試みて、不正ならエラー表示
			CdDedJikoku aJikoku ;
			int iResult = aJikoku.decode( pUiData->strChakujikoku ) ;
			if ( iResult < 0 )
			{
				iRv =  -11 ;
			}
		}
	}
	//	発時刻
	if ( iRv >= 0 )
	{
		if ( bNewItem 
			|| pUiDataStartEdit->strHatsujikoku != pUiData->strHatsujikoku )
		{

			//　○【発時刻】発時刻が空文字列でないなら、
			//	値の時刻への変換を試みて、不正ならエラー表示
			CdDedJikoku aJikoku ;
			int iResult = aJikoku.decode( pUiData->strHatsujikoku ) ;
			if ( iResult < 0 )
			{
				iRv = -12 ;
			}
		}
	}
	// --------------------------------
	//	エラーメッセージを表示します
	// --------------------------------
	if ( iRv < 0 )
	{
		switch( iRv )
		{
		case -11 :
			ShowError( ERRMSG_INVALID_CHAKUJIKOKU ) ;
			SetFocus( offsetof( UIDATA , strChakujikoku )) ;
			break ;
		case -12 :
			ShowError( ERRMSG_INVALID_HATSUJIKOKU ) ;
			SetFocus( offsetof( UIDATA , strHatsujikoku ) );
			break ;
		}
	}
	return iRv ;
}

int CPropEditUi_EkiJikoku::UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{

	int iRv = 0 ; 
	for ( int i = 0 ; iRv >= 0 && i < m_pTarget->size() ; i ++ )
	{
		CentDedRessya* pRessya = m_pTarget->get( i ) ; 
		CentDedEkiJikoku aEkiJikoku 
			= pRessya->getCentDedEkiJikoku( m_iEkiOrder ) ;
		
		if ( bNewItem 
			|| pUiDataStartEdit->iEkiatsukai != pUiData->iEkiatsukai )
		{
			aEkiJikoku.setEkiatsukai( 
				getEkiatsukaiConvTable().leftFrom(  pUiData->iEkiatsukai ) ) ;
		}
		// strChakujikoku
		if ( bNewItem 
			|| pUiDataStartEdit->strChakujikoku != pUiData->strChakujikoku )
		{
			if ( pUiData->bChakujikokuIsEnable )
			{
				CdDedJikoku	aJikoku ;
				int iResult = aJikoku.decode( pUiData->strChakujikoku ) ;
				if ( iResult >= 0 )
				{
					aEkiJikoku.setChakujikoku( aJikoku ) ;
				}
			}
		}
		// strHatsujikoku
		if ( bNewItem 
			|| pUiDataStartEdit->strHatsujikoku != pUiData->strHatsujikoku )
		{
			if ( pUiData->bHatsujikokuIsEnable )
			{
				CdDedJikoku	aJikoku ;
				int iResult = aJikoku.decode( pUiData->strHatsujikoku ) ;
				if ( iResult >= 0 )
				{
					aEkiJikoku.setHatsujikoku( aJikoku ) ;
				}
			}
		}
		// --------------------------------
		//	列車に駅時刻を書き込む(繰上げ・繰り下げの場合もあります)
		if ( pUiData->bModifyHatsujikoku )
		{
			pRessya->modifyCentDedEkiJikoku( m_iEkiOrder , aEkiJikoku ) ;
		}
		else
		{
			pRessya->setCentDedEkiJikoku( m_iEkiOrder , aEkiJikoku ) ;
		}
	}
	
	if (  bNewItem || pUiDataStartEdit->bModifyHatsujikoku != pUiData->bModifyHatsujikoku  )
	{
		*m_pbModifyHatsujikoku = pUiData->bModifyHatsujikoku ;
	}
	return iRv ;
}	



	// ********************************
	//	コンストラクタ
	// ********************************
CPropEditUi_EkiJikoku::CPropEditUi_EkiJikoku( 
		bool bNewItem , 
		Mu<CentDedRessya*>* pTarget , 
		bool* pbModifyHatsujikoku ,
		int iEkiOrder ) 
		: CPropEditUi2( bNewItem ) 
		, m_pTarget( pTarget ) 
		, m_pbModifyHatsujikoku( pbModifyHatsujikoku )
		, m_iEkiOrder( iEkiOrder )
{
}



} //namespace ViewJikokuhyou

