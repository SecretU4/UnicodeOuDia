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
//	$Id: CPropEditUi_Eki.cpp 357 2016-08-18 16:59:16Z okm $
// ****************************************************************

/** @file */
#include "stdafx.h"
#include "CPropEditUi_Eki.h"

namespace ViewEki {


	// ********************************
	//@name エラーメッセージ
	// ********************************
	/// 駅名が長すぎます
const char* const CPropEditUi_Eki::ERRMSG_EKIMEI_TOO_LONG = "Ekimei is too long(Limit is 58 characters)." ;
	

//	// ================================
//	//@name 下請関数
//	// ================================
//
//void CPropEditUi_Eki::UiDataFromTarget( 
//		UIDATA* pUiData , 
//		const CentDedEki* pTarget ) 
//{
//	// 駅名 
//	pUiData->strEkimei = pTarget->getEkimei() ;
//
//	// 駅時刻形式 
//	pUiData->iEkijikokukeisiki = (int)pTarget->getEkijikokukeisiki() ;
//	
//	// 駅規模 
//	pUiData->iEkikibo = (int)pTarget->getEkikibo() ;
//
//	// 境界線あり 
//	pUiData->iKyoukaisen = (int)pTarget->getKyoukaisen() ;
//
//	// ダイヤグラム列車情報表示（下り） 
//	pUiData->iDiagramRessyajouhouHyoujiKudari = (int)pTarget->getDiagramRessyajouhouHyoujiKudari() ;
//
//	// ダイヤグラム列車情報表示（上り） 
//	pUiData->iDiagramRessyajouhouHyoujiNobori = (int)pTarget->getDiagramRessyajouhouHyoujiNobori() ;
//
//}
//
//int CPropEditUi_Eki::UiDataToTarget( 
//		const UIDATA& aUiDataPrev , 
//		const UIDATA& aUiDataModified , 
//		CentDedEki* pTarget  ) 
//{
//	int iRv = 0 ;
//	// 駅名 
//	if ( iRv >= 0 
//		&& aUiDataPrev.strEkimei != pUiData->strEkimei )
//	{
//		pTarget->setEkimei( pUiData->strEkimei ) ;
//	}
//
//	// 駅時刻形式 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iEkijikokukeisiki 
//			!= aUiDataModified.iEkijikokukeisiki )
//	{
//		pTarget->setEkijikokukeisiki( 
//			(CentDedEki::EEkijikokukeisiki)aUiDataModified.iEkijikokukeisiki ) ;
//	}
//	// 駅規模 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iEkikibo != aUiDataModified.iEkikibo )
//	{
//		pTarget->setEkikibo( (CentDedEki::EEkikibo)aUiDataModified.iEkikibo ) ;
//	}
//
//	// 境界線あり 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iKyoukaisen 
//			!= aUiDataModified.iKyoukaisen )
//	{
//		pTarget->setKyoukaisen( aUiDataModified.iKyoukaisen != 0 );
//	}
//
//	// ダイヤグラム列車情報表示（下り） 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iDiagramRessyajouhouHyoujiKudari
//			!= aUiDataModified.iDiagramRessyajouhouHyoujiKudari )
//	{
//		pTarget->setDiagramRessyajouhouHyoujiKudari(
//			(CentDedEki::EDiagramRessyajouhouHyouji)aUiDataModified.iDiagramRessyajouhouHyoujiKudari ) ;
//	}
//
//	// ダイヤグラム列車情報表示（上り） 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iDiagramRessyajouhouHyoujiNobori 
//			!= aUiDataModified.iDiagramRessyajouhouHyoujiNobori )
//	{
//		pTarget->setDiagramRessyajouhouHyoujiNobori(
//			(CentDedEki::EDiagramRessyajouhouHyouji)aUiDataModified.iDiagramRessyajouhouHyoujiNobori ) ;
//	}
//
//	return iRv ;
//}
	// ================================
	//	オーバーライトの必要なメソッド1-Targetに依存する処理
	// ================================
void CPropEditUi_Eki::UiDataFromTarget( UIDATA* pUiData ) 
{
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		const CentDedEki* pTarget = m_pTarget->get( i ) ; 
		// 駅名 
		if ( i == 0 )
		{
			pUiData->strEkimei = pTarget->getEkimei() ;
		}
		else if ( pUiData->strEkimei != pTarget->getEkimei() )
		{
			pUiData->strEkimei = "" ;
		}

		// 駅時刻形式 
		if ( i == 0 )
		{
			pUiData->iEkijikokukeisiki = (int)pTarget->getEkijikokukeisiki() ;
		}
		else if ( pUiData->iEkijikokukeisiki != (int)pTarget->getEkijikokukeisiki() )
		{
			pUiData->iEkijikokukeisiki = -1 ;	//-1 : 不定
		}
		// 駅規模 
		if ( i == 0 )
		{
			pUiData->iEkikibo = (int)pTarget->getEkikibo() ;
		}
		else if ( pUiData->iEkikibo != (int)pTarget->getEkikibo() )
		{
			pUiData->iEkikibo = -1 ;	//	不定
		}
		// 境界線あり 
		if ( i == 0 )
		{
			pUiData->iKyoukaisen = (int)pTarget->getKyoukaisen() ;
		}
		else if ( pUiData->iKyoukaisen != (int)pTarget->getKyoukaisen() )
		{
			pUiData->iKyoukaisen = -1 ;	// 不定
		}
		// ダイヤグラム列車情報表示（下り）
		if ( i == 0 )
		{
			pUiData->iDiagramRessyajouhouHyoujiKudari = (int)pTarget->getDiagramRessyajouhouHyoujiKudari() ;
		}
		else if ( pUiData->iDiagramRessyajouhouHyoujiKudari != (int)pTarget->getDiagramRessyajouhouHyoujiKudari() )
		{
			pUiData->iDiagramRessyajouhouHyoujiKudari = -1 ;	//-1: 不定
		}
		// ダイヤグラム列車情報表示（上り） 
		if ( i == 0 )
		{
			pUiData->iDiagramRessyajouhouHyoujiNobori = (int)pTarget->getDiagramRessyajouhouHyoujiNobori() ;
		}
		else if ( pUiData->iDiagramRessyajouhouHyoujiNobori != (int)pTarget->getDiagramRessyajouhouHyoujiNobori() )
		{
			pUiData->iDiagramRessyajouhouHyoujiNobori = -1 ;	// 不定
		}
	}

	// [駅時刻を駅時刻形式で正規化]の設定
	pUiData->bAdjustByEkijikokukeisiki = *m_pbAdjustByEkijikokukeisiki ;
}
	
void CPropEditUi_Eki::AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
{
	/* 駅名 */
	if ( bStartEdit || pUiDataPrev->strEkimei != pUiData->strEkimei)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}
	/* 駅時刻形式 */
	if ( bStartEdit || pUiDataPrev->iEkijikokukeisiki != pUiData->iEkijikokukeisiki)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}
	/* 駅規模 */
	if ( bStartEdit || pUiDataPrev->iEkikibo != pUiData->iEkikibo)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}

	/* 境界線あり */
	if ( bStartEdit || pUiDataPrev->iKyoukaisen != pUiData->iKyoukaisen)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}

	/* ダイヤグラム列車情報表示（下り） */
	if ( bStartEdit || pUiDataPrev->iDiagramRessyajouhouHyoujiKudari != pUiData->iDiagramRessyajouhouHyoujiKudari)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}

	/* ダイヤグラム列車情報表示（上り） */
	if ( bStartEdit || pUiDataPrev->iDiagramRessyajouhouHyoujiNobori != pUiData->iDiagramRessyajouhouHyoujiNobori)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}

	/*	[駅時刻を駅時刻形式で正規化]の設定です。*/
	if ( bStartEdit || pUiDataPrev->bAdjustByEkijikokukeisiki != pUiData->bAdjustByEkijikokukeisiki)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}

}

int CPropEditUi_Eki::CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	/* 駅名 */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->strEkimei != pUiData->strEkimei)
		{
			if ( pUiData->strEkimei.length() > 58 )
			{
				ShowError( ERRMSG_EKIMEI_TOO_LONG ) ;
				SetFocus( offsetof( UIDATA , strEkimei )) ;
				iRv = -1 ;	//	駅名が長すぎます。
			}
		}
	}
	/* 駅時刻形式 */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iEkijikokukeisiki != pUiData->iEkijikokukeisiki)
		{
			// pUiData->メンバー名 のエラーチェックを行うコード。
		}
	}
	/* 駅規模 */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iEkikibo != pUiData->iEkikibo)
		{
			// pUiData->メンバー名 のエラーチェックを行うコード。
		}
	}
	/* 境界線あり */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iKyoukaisen != pUiData->iKyoukaisen)
		{
			// pUiData->メンバー名 のエラーチェックを行うコード。
		}
	}
	/* ダイヤグラム列車情報表示（下り） */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iDiagramRessyajouhouHyoujiKudari != pUiData->iDiagramRessyajouhouHyoujiKudari)
		{
			// pUiData->メンバー名 のエラーチェックを行うコード。
		}
	}
	/* ダイヤグラム列車情報表示（上り） */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iDiagramRessyajouhouHyoujiNobori != pUiData->iDiagramRessyajouhouHyoujiNobori)
		{
			// pUiData->メンバー名 のエラーチェックを行うコード。
		}
	}
	/*	[駅時刻を駅時刻形式で正規化]の設定です。*/
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->bAdjustByEkijikokukeisiki != pUiData->bAdjustByEkijikokukeisiki)
		{
			// pUiData->メンバー名 のエラーチェックを行うコード。
		}
	}
	return iRv ;
}




int CPropEditUi_Eki::UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ;
	for ( int i = 0 ; iRv >= 0 && i < m_pTarget->size() ; i ++ )
	{
		CentDedEki* pTarget= m_pTarget->get( i ) ; 
		/* 駅名 */
		if ( bNewItem || pUiDataStartEdit->strEkimei != pUiData->strEkimei)
		{
			pTarget->setEkimei( pUiData->strEkimei ) ;
		}
		/* 駅時刻形式 */
		if ( bNewItem || pUiDataStartEdit->iEkijikokukeisiki != pUiData->iEkijikokukeisiki)
		{
			pTarget->setEkijikokukeisiki( 
				(CentDedEki::EEkijikokukeisiki)pUiData->iEkijikokukeisiki ) ;
		}
		/* 駅規模 */
		if ( bNewItem || pUiDataStartEdit->iEkikibo != pUiData->iEkikibo)
		{
			pTarget->setEkikibo( (CentDedEki::EEkikibo)pUiData->iEkikibo ) ;
		}
		/* 境界線あり */
		if ( bNewItem || pUiDataStartEdit->iKyoukaisen != pUiData->iKyoukaisen)
		{
			pTarget->setKyoukaisen( pUiData->iKyoukaisen != 0 );
		}
		/* ダイヤグラム列車情報表示（下り） */
		if ( bNewItem || pUiDataStartEdit->iDiagramRessyajouhouHyoujiKudari != pUiData->iDiagramRessyajouhouHyoujiKudari)
		{
			pTarget->setDiagramRessyajouhouHyoujiKudari(
				(CentDedEki::EDiagramRessyajouhouHyouji)pUiData->iDiagramRessyajouhouHyoujiKudari ) ;
		}
		/* ダイヤグラム列車情報表示（上り） */
		if ( bNewItem || pUiDataStartEdit->iDiagramRessyajouhouHyoujiNobori != pUiData->iDiagramRessyajouhouHyoujiNobori)
		{
			pTarget->setDiagramRessyajouhouHyoujiNobori(
				(CentDedEki::EDiagramRessyajouhouHyouji)pUiData->iDiagramRessyajouhouHyoujiNobori ) ;
		}
	}
	/*	[駅時刻を駅時刻形式で正規化]の設定です。*/
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->bAdjustByEkijikokukeisiki != pUiData->bAdjustByEkijikokukeisiki)
		{
			// [駅時刻を駅時刻形式で正規化]の設定
			*m_pbAdjustByEkijikokukeisiki = pUiData->bAdjustByEkijikokukeisiki ;
		}
	}
	return iRv ;
}


	// ********************************
	//	コンストラクタ
	// ********************************
CPropEditUi_Eki::CPropEditUi_Eki( 
	bool bNewItem , 
	Mu<CentDedEki*>* pTarget ,
	bool* pbAdjustByEkijikokukeisiki )
	: CPropEditUi2( bNewItem ) 
	, m_pTarget( pTarget ) 
	, m_pbAdjustByEkijikokukeisiki( pbAdjustByEkijikokukeisiki ) 
{	
};

} //namespace ViewEki 



