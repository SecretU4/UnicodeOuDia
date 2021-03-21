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
//	$Id: CPropEditUi_Ressya.cpp 357 2016-08-18 16:59:16Z okm $
// ****************************************************************

#include "stdafx.h"
#include "CPropEditUi_Ressya.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

	// ********************************
	//@name エラーメッセージ
	// ********************************
	// 列車種別が範囲外です。
const char* const CPropEditUi_Ressya::ERRMSG_INVALID_RESSYASYUBETSU = "Invalid Ressyasyubetsu." ;



	// ================================
	//@name オーバーライトの必要なメソッド1-Targetに依存する処理
	// ================================
void CPropEditUi_Ressya::UiDataFromTarget( UIDATA* pUiData ) 
{
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		CentDedRessya* pRessya = m_pTarget->get( i ) ;

		/* 列車がNullか否かを指定するチェックボックスです。 */
		if ( i == 0 )
		{
			pUiData->iIsNull = (int)pRessya->isNull() ;
		}
		else if ( pUiData->iIsNull != (int)pRessya->isNull() )
		{
			pUiData->iIsNull = -1 ;	// 中間
		}

		/* 列車番号 */
		if ( i == 0 )
		{
			pUiData->strRessyabangou = pRessya->getRessyabangou() ;
		}
		else if ( pUiData->strRessyabangou != pRessya->getRessyabangou() )
		{
			pUiData->strRessyabangou = "" ;
		}

		/* strRessyabangou の編集の有効・無効。true なら有効です */
		pUiData->bRessyabangouIsEnable =  ( pUiData->iIsNull != 1 ) ;

		//target が複数の場合は、列車番号は無効です。
		if ( i > 0 ){	pUiData->bRessyabangouIsEnable = false ;}

		/* 列車種別のIndex */
		if ( i == 0 )
		{
			pUiData->iRessyasyubetsuIndex = pRessya->getRessyasyubetsuIndex() ;
		}
		else if ( pUiData->iRessyasyubetsuIndex != pRessya->getRessyasyubetsuIndex() )
		{
			pUiData->iRessyasyubetsuIndex = -1 ;	//	選択なし
		}

		/** iRessyasyubetsuIndex の編集の有効・無効。true なら有効です */
		pUiData->bRessyasyubetsuIndexIsEnable =  ( pUiData->iIsNull != 1 ) ;

		/** 列車名 */
		if ( i == 0 )
		{
			pUiData->strRessyamei = pRessya->getRessyamei() ;
		}
		else if ( pUiData->strRessyamei != pRessya->getRessyamei() )
		{
			pUiData->strRessyamei = "" ;
		}

		/** strRessyamei の編集の有効・無効。true なら有効です */
		pUiData->bRessyameiIsEnable =  ( pUiData->iIsNull != 1 ) ;

		
		/** 号数 */
		if ( i == 0 )
		{
			pUiData->strGousuu = pRessya->getGousuu() ;
		}
		else if ( pUiData->strGousuu != pRessya->getGousuu() )
		{
			pUiData->strGousuu = "" ;
		}
		/** strGousuu の編集の有効・無効。true なら有効です */
		pUiData->bGousuuIsEnable =  ( pUiData->iIsNull != 1 ) ;

		/** 備考 */
		if ( i == 0 )
		{
			pUiData->strBikou = pRessya->getBikou() ;
		}
		else if ( pUiData->strBikou != pRessya->getBikou() )
		{
			pUiData->strBikou = "" ;
		}
		/** strBikou の編集の有効・無効。true なら有効です */
		pUiData->bBikouIsEnable =  ( pUiData->iIsNull != 1 ) ; 

		

		//UiDataFromTarget( &aUiData , pRessya ) ;
		//if ( i == 0 )
		//{
		//	m_UiData = aUiData ;
		//}
		//else
		//{
		//	if ( m_UiData.iIsNull >= 0 
		//		&&  m_UiData.iIsNull != aUiData.iIsNull )
		//	{
		//		m_UiData.iIsNull = -1 ;
		//	}
		//	if ( m_UiData.strRessyabangou.length() > 0 
		//		&& m_UiData.strRessyabangou != aUiData.strRessyabangou )
		//	{
		//		m_UiData.strRessyabangou.erase() ;
		//	}
		//	if ( m_UiData.iRessyasyubetsuIndex >= 0 
		//		&& m_UiData.iRessyasyubetsuIndex != aUiData.iRessyasyubetsuIndex )
		//	{
		//		m_UiData.iRessyasyubetsuIndex = -1 ; 
		//	}
		//	if ( m_UiData.strRessyamei.length() >= 0 
		//		&& m_UiData.strRessyamei != aUiData.strRessyamei )
		//	{
		//		m_UiData.strRessyamei.erase() ;
		//	}
		//	if ( m_UiData.strGousuu.length() >= 0 
		//		&& m_UiData.strGousuu != aUiData.strGousuu )
		//	{
		//		m_UiData.strGousuu.erase() ;
		//	}
		//	if ( m_UiData.strBikou.length() >= 0 
		//		&& m_UiData.strBikou != aUiData.strBikou )
		//	{
		//		m_UiData.strBikou.erase() ;
		//	}
		//}
	}
}

void CPropEditUi_Ressya::AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
{
	int iRv = 0 ; 

	/* 列車がNullか否かを指定するチェックボックス。 */
	if ( bStartEdit || pUiDataPrev->iIsNull != pUiData->iIsNull)
	{
		//	空行(NULL)である場合は、
		//	他の項目をすべて無効にします。
		//	空行でない場合は他の項目は有効にしますが、
		//	ターゲットが複数の場合は列車番号は無効にします。
		if ( pUiData->iIsNull == 1 )	//	列車が空行の場合は、他の入力項目は無効
		{
			pUiData->bRessyabangouIsEnable = false ;
			pUiData->bRessyasyubetsuIndexIsEnable = false ;
			pUiData->bRessyameiIsEnable = false ;
			pUiData->bGousuuIsEnable = false ;
			pUiData->bBikouIsEnable = false ;
		}
		else
		{
			if ( m_pTarget->size() > 1 )
			{
				pUiData->bRessyabangouIsEnable = false ;
			}
			else
			{
				pUiData->bRessyabangouIsEnable = true ;
			}
			pUiData->bRessyasyubetsuIndexIsEnable = true ;
			pUiData->bRessyameiIsEnable = true ;
			pUiData->bGousuuIsEnable = true ;
			pUiData->bBikouIsEnable = true ;
		}
	}
	/* 列車番号 */
	if ( bStartEdit || pUiDataPrev->strRessyabangou != pUiData->strRessyabangou)
	{
		//	修正なし。
	}
	/* 列車種別のIndex */
	if ( bStartEdit || pUiDataPrev->iRessyasyubetsuIndex != pUiData->iRessyasyubetsuIndex)
	{
		/*
		//	範囲外の値を正規化
		if ( m_iRessyasyubetsuCount <= pUiData->iRessyasyubetsuIndex   )
		{
			pUiData->iRessyasyubetsuIndex = m_iRessyasyubetsuCount - 1 ;
		}
		if ( pUiData->iRessyasyubetsuIndex < ( m_pTarget->size() > 1 ? -1 : 0 ) )
		{
			pUiData->iRessyasyubetsuIndex = 0 ; 
		}
		*/
		//	ここでの正規化を行わずに、CheckUiData() でエラーを出します。
	}
	/* 列車名 */
	if ( bStartEdit || pUiDataPrev->strRessyamei != pUiData->strRessyamei)
	{
		//	修正なし。
	}

	/* 号数 */
	if ( bStartEdit || pUiDataPrev->strGousuu != pUiData->strGousuu)
	{
		//	修正なし。
	}

	/* 備考 */
	if ( bStartEdit || pUiDataPrev->strBikou != pUiData->strBikou)
	{
		//	修正なし。
	}

}

int CPropEditUi_Ressya::CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	
	/* 列車がNullか否かを指定するチェックボックス。 */
	if ( bNewItem || pUiDataStartEdit->iIsNull != pUiData->iIsNull)
	{
		//	エラーチェックなし
	}

	/* 列車種別のIndex */
	if ( bNewItem || pUiDataStartEdit->iRessyasyubetsuIndex != pUiData->iRessyasyubetsuIndex)
	{
		int iIndexLowerBound = 0 ;
		if ( m_pTarget->size() > 1 ){	iIndexLowerBound = -1 ;}
		if ( !( iIndexLowerBound <= pUiData->iRessyasyubetsuIndex 
			&& pUiData->iRessyasyubetsuIndex < m_iRessyasyubetsuCount ) )
		{
			iRv = -1 ;
			ShowError( ERRMSG_INVALID_RESSYASYUBETSU ) ;
			SetFocus( offsetof( UIDATA , iRessyasyubetsuIndex ) ) ;
		}
	}

	/* 列車名 */
	if ( bNewItem || pUiDataStartEdit->strRessyamei != pUiData->strRessyamei)
	{
		//	エラーチェックなし
	}

	/* 号数 */
	if ( bNewItem || pUiDataStartEdit->strGousuu != pUiData->strGousuu)
	{
		//	エラーチェックなし
	}

	/* 備考 */
	if ( bNewItem || pUiDataStartEdit->strBikou != pUiData->strBikou)
	{
		//	エラーチェックなし
	}
	return iRv ;
}

int CPropEditUi_Ressya::UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		CentDedRessya* pRessya = m_pTarget->get( i ) ;


		//	iIsNull が変化した場合
		if ( bNewItem || pUiDataStartEdit->iIsNull != pUiData->iIsNull )
		{
			pRessya->setIsNull( pUiData->iIsNull == 1 ) ;
		}

		//	iIsNull以外に変更が加えられた場合は、
		//	変更を列車に反映します。
		//	但し、Nullの列車には変更を加えません
		//	(属性を設定することにより、NULL状態の列車が非NULLに変化するためです)。
		if ( !pRessya->isNull() )
		{
			if ( bNewItem || pUiDataStartEdit->strRessyabangou != pUiData->strRessyabangou  )
			{
				pRessya->setRessyabangou( pUiData->strRessyabangou ) ;
			}
			if ( bNewItem || pUiDataStartEdit->iRessyasyubetsuIndex != pUiData->iRessyasyubetsuIndex  )
			{
				pRessya->setRessyasyubetsuIndex(  pUiData->iRessyasyubetsuIndex ) ;
			}
			if ( bNewItem || pUiDataStartEdit->strRessyamei != pUiData->strRessyamei  )
			{
				pRessya->setRessyamei(  pUiData->strRessyamei ) ;
			}
			if ( bNewItem || pUiDataStartEdit->strGousuu != pUiData->strGousuu  )
			{
				pRessya->setGousuu(  pUiData->strGousuu ) ;
			}
			if ( bNewItem || pUiDataStartEdit->strBikou != pUiData->strBikou  )
			{
				pRessya->setBikou(  pUiData->strBikou ) ;
			}
		}

	}
	return iRv ;
}
	
	// ********************************
	//	コンストラクタ
	// ********************************
CPropEditUi_Ressya::CPropEditUi_Ressya( 
    bool bNewItem , 
	Mu<CentDedRessya*>* pTarget ,
	int iRessyasyubetsuCount 
	) 
	: CPropEditUi2( bNewItem )
	, m_pTarget( pTarget ) 
	, m_iRessyasyubetsuCount( iRessyasyubetsuCount ) 
{
}
	
	

} //namespace ViewJikokuhyou

