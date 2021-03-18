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
//	$Id: CPropEditUi_Ressyasyubetsu.cpp 399 2016-11-26 08:45:03Z okm $
// ****************************************************************

/** @file */
#include "stdafx.h"
#include "CPropEditUi_Ressyasyubetsu.h"

namespace ViewRessyasyubetsu {

// ****************************************************************
//	CPropEditUi_Ressyasyubetsu
// ****************************************************************
	// 種別名が指定されていません
const char* const CPropEditUi_Ressyasyubetsu::ERRMSG_SYUBETUSMEI_EMPTY = "Ressyasyubetsumei is empty." ;

	// 略称が長すぎます
const char* const CPropEditUi_Ressyasyubetsu::ERRMSG_RYAKUSYOULENGTH = "Ryakusyou is too long(Limit is 6 characters)." ;


	// ================================
	//  オーバーライトの必要なメソッド1-Targetに依存する処理
	// ================================
void CPropEditUi_Ressyasyubetsu::UiDataFromTarget( UIDATA* pUiData ) 
{
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		const CentDedRessyasyubetsu* pTarget = m_pTarget->get( i ) ; 

		/* 列車種別名 */
		if ( i == 0 )
		{
			pUiData->strSyubetsumei = pTarget->getSyubetsumei() ;
		}
		else if ( pUiData->strSyubetsumei != pTarget->getSyubetsumei() )
		{
			pUiData->strSyubetsumei = "" ;
		}
	
		/* 列車種別名の有効・無効 は、対象外 */
	
		/** 略称（種別名の略称） */
		if ( i == 0 )
		{
			pUiData->strRyakusyou = pTarget->getRyakusyou();
		}
		else if ( pUiData->strRyakusyou != pTarget->getRyakusyou() )
		{
			pUiData->strRyakusyou = "" ;
		}
	
		/*	時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)	*/
		if ( i == 0 )
		{
			pUiData->colorJikokuhyouMojiColor = pTarget->getJikokuhyouMojiColor() ;
		}
		else if ( pUiData->colorJikokuhyouMojiColor != pTarget->getJikokuhyouMojiColor() )
		{
			pUiData->colorJikokuhyouMojiColor.setIsNull( true ) ; 
		}
		/* 時刻表ビューで、この列車種別の時刻を表示するための時刻表フォント */
		if ( i == 0 )
		{
			pUiData->iJikokuhyouFontIndex= pTarget->getJikokuhyouFontIndex() ;
		}
		else if ( pUiData->iJikokuhyouFontIndex != pTarget->getJikokuhyouFontIndex() )
		{
			pUiData->iJikokuhyouFontIndex = -1 ;
		}

		/* ダイヤグラム線の色 */
		if ( i == 0 )
		{
			pUiData->colorDiagramSenColor = pTarget->getDiagramSenColor() ;
		}
		else if ( pUiData->colorDiagramSenColor != pTarget->getDiagramSenColor()  )
		{
			pUiData->colorDiagramSenColor.setIsNull( true )  ;
		}
	
		/* ダイヤグラム線の線スタイル	*/
		if ( i == 0 )
		{
			pUiData->iDiagramSenStyle = (int)pTarget->getDiagramSenStyle() ;
		}
		else if ( pUiData->iDiagramSenStyle = (int)pTarget->getDiagramSenStyle() )
		{
			pUiData->iDiagramSenStyle = -1 ;	// 不定
		}
		/* ダイヤグラム線の線スタイルが太線か否かを指定します。*/
		if( i == 0 )
		{
			pUiData->iDiagramSenIsBold = (int)pTarget->getDiagramSenIsBold() ;
		} 
		else if ( pUiData->iDiagramSenIsBold != (int)pTarget->getDiagramSenIsBold() )
		{
			pUiData->iDiagramSenIsBold = -1 ;	// 不定	
		}

		/*  停車駅明示の方法 */
		if ( i == 0 )
		{
			pUiData->iStopMarkDrawType = (int)pTarget->getStopMarkDrawType() ;
		}
		else if ( pUiData->iStopMarkDrawType != (int)pTarget->getStopMarkDrawType() )
		{
			pUiData->iStopMarkDrawType = -1 ;
		}
	}
}



void CPropEditUi_Ressyasyubetsu::AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
{
	/* 列車種別名 */
	if ( bStartEdit || pUiDataPrev->strSyubetsumei != pUiData->strSyubetsumei)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}
	
	/* 列車種別名の有効・無効 */
	if ( bStartEdit || pUiDataPrev->bSyubetsumeiIsEnable != pUiData->bSyubetsumeiIsEnable)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}
	
	/* 略称（種別名の略称） */
	if ( bStartEdit || pUiDataPrev->strRyakusyou != pUiData->strRyakusyou)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}
	/* 時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)	*/
	if ( bStartEdit || pUiDataPrev->colorJikokuhyouMojiColor != pUiData->colorJikokuhyouMojiColor)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}

	/* 時刻表ビューで、この列車種別の時刻を表示するための時刻表フォント */
	if ( bStartEdit || pUiDataPrev->iJikokuhyouFontIndex != pUiData->iJikokuhyouFontIndex)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}

	/* ダイヤグラム線の色 */
	if ( bStartEdit || pUiDataPrev->colorDiagramSenColor != pUiData->colorDiagramSenColor)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}
	
	/* ダイヤグラム線の線スタイル*/	
	if ( bStartEdit || pUiDataPrev->iDiagramSenStyle != pUiData->iDiagramSenStyle)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}

	/* ダイヤグラム線の線スタイルが太線か否かを指定します。*/
	if ( bStartEdit || pUiDataPrev->iDiagramSenIsBold != pUiData->iDiagramSenIsBold)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}
	
	/*	 停車駅明示の方法 */
	if ( bStartEdit || pUiDataPrev->iStopMarkDrawType != pUiData->iStopMarkDrawType)
	{
		// pUiData->メンバー名 の正規化を行うコード。
	}
}


int CPropEditUi_Ressyasyubetsu::CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ;


	/* 列車種別名 */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->strSyubetsumei != pUiData->strSyubetsumei)
		{
			if ( pUiData->strSyubetsumei.length() == 0 )
			{
				iRv = -1 ;      //  種別名が指定されていません
				ShowError( ERRMSG_SYUBETUSMEI_EMPTY ) ;
				SetFocus( offsetof( UIDATA , strSyubetsumei )) ;
			}
		}
	}
		
	/* 列車種別名の有効・無効 */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->bSyubetsumeiIsEnable != pUiData->bSyubetsumeiIsEnable)
		{
			// pUiData->メンバー名 の正規化を行うコード。
		}
	}
		
	/* 略称（種別名の略称） */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->strRyakusyou != pUiData->strRyakusyou)
		{
			if ( pUiData->strRyakusyou.length() > 6 )
			{
				iRv = -2 ;      //  略称が長すぎます(略称は6文字まで(半角)です)
				ShowError( ERRMSG_RYAKUSYOULENGTH ) ;
				SetFocus( offsetof( UIDATA , strRyakusyou )) ;
			}
		}
	}
	/* 時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)	*/
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->colorJikokuhyouMojiColor != pUiData->colorJikokuhyouMojiColor)
		{
			// pUiData->メンバー名 の正規化を行うコード。
		}
	}

	/* 時刻表ビューで、この列車種別の時刻を表示するための時刻表フォント */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iJikokuhyouFontIndex != pUiData->iJikokuhyouFontIndex)
		{
			// pUiData->メンバー名 の正規化を行うコード。
		}
	}

	/* ダイヤグラム線の色 */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->colorDiagramSenColor != pUiData->colorDiagramSenColor)
		{
			// pUiData->メンバー名 の正規化を行うコード。
		}
	}
		
	/* ダイヤグラム線の線スタイル*/	
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iDiagramSenStyle != pUiData->iDiagramSenStyle)
		{
			// pUiData->メンバー名 の正規化を行うコード。
		}
	}

	/* ダイヤグラム線の線スタイルが太線か否かを指定します。*/
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iDiagramSenIsBold != pUiData->iDiagramSenIsBold)
		{
			// pUiData->メンバー名 の正規化を行うコード。
		}
	}
		
	/*	 停車駅明示の方法 */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iStopMarkDrawType != pUiData->iStopMarkDrawType)
		{
			// pUiData->メンバー名 の正規化を行うコード。
		}
	}


	return iRv ;
}
int CPropEditUi_Ressyasyubetsu::UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	for ( int i = 0 ; iRv >= 0 && i < m_pTarget->size() ; i ++ )
	{
		CentDedRessyasyubetsu* pTarget = m_pTarget->get( i ) ; 

		/* 列車種別名 */
		if ( bNewItem || pUiDataStartEdit->strSyubetsumei != pUiData->strSyubetsumei)
		{
			pTarget->setSyubetsumei( pUiData->strSyubetsumei ) ;
		}
		
		/* 略称（種別名の略称） */
		if ( bNewItem || pUiDataStartEdit->strRyakusyou != pUiData->strRyakusyou)
		{
			pTarget->setRyakusyou( pUiData->strRyakusyou ) ;
		}
		/* 時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)	*/
		if ( bNewItem || pUiDataStartEdit->colorJikokuhyouMojiColor != pUiData->colorJikokuhyouMojiColor)
		{
			pTarget->setJikokuhyouMojiColor( pUiData->colorJikokuhyouMojiColor ) ;
		}

		/* 時刻表ビューで、この列車種別の時刻を表示するための時刻表フォント */
		if ( bNewItem || pUiDataStartEdit->iJikokuhyouFontIndex != pUiData->iJikokuhyouFontIndex)
		{
			pTarget->setJikokuhyouFontIndex( pUiData->iJikokuhyouFontIndex ) ;
		}

		/* ダイヤグラム線の色 */
		if ( bNewItem || pUiDataStartEdit->colorDiagramSenColor != pUiData->colorDiagramSenColor)
		{
			pTarget->setDiagramSenColor( pUiData->colorDiagramSenColor ) ;
		}
		
		/* ダイヤグラム線の線スタイル*/	
		if ( bNewItem || pUiDataStartEdit->iDiagramSenStyle != pUiData->iDiagramSenStyle)
		{
			pTarget->setDiagramSenStyle( (CentDedRessyasyubetsu::ESenStyle)pUiData->iDiagramSenStyle ) ;
		}

		/* ダイヤグラム線の線スタイルが太線か否かを指定します。*/
		if ( bNewItem || pUiDataStartEdit->iDiagramSenIsBold != pUiData->iDiagramSenIsBold)
		{
			pTarget->setDiagramSenIsBold( pUiData->iDiagramSenIsBold == 1 ) ;
		}
		
		/*	 停車駅明示の方法 */
		if ( bNewItem || pUiDataStartEdit->iStopMarkDrawType != pUiData->iStopMarkDrawType)
		{
			pTarget->setStopMarkDrawType( (CentDedRessyasyubetsu::EStopMarkDrawType)pUiData->iStopMarkDrawType ) ;
		}
	}
	return iRv ;
}



	// ********************************
	//	コンストラクタ
	// ********************************
CPropEditUi_Ressyasyubetsu::CPropEditUi_Ressyasyubetsu(
	bool bNewItem , 
	Mu<CentDedRessyasyubetsu*>* pTarget )
	: CPropEditUi2( bNewItem )
	, m_pTarget( pTarget ) 
{
	
}

} //namespace ViewRessyasyubetsu 



