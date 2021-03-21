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
//	CaTreeCtrl.cpp
// ****************************************************************
*/
#include "TreeCtrl\CaTreeCtrl.h"

namespace OuMfc{
namespace TreeCtrl{

// ****************************************************************
//	CaTreeCtrl
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CaTreeCtrl::CaTreeCtrl( CTreeCtrl* pCTreeCtrl ) : 
		m_pCTreeCtrl( pCTreeCtrl )
{
};

// ********************************
//@name 操作
// ********************************
int CaTreeCtrl::HTREEITEM_to_Itemlocation( HTREEITEM aHTREEITEM , 
		Itemlocation* pItemlocation ) 
{
	int iRv = 0 ;
	pItemlocation->clear() ;
	
	//	『アイテム位置指定子』の要素を追加します。
	pItemlocation->push_front( 0 ) ;

	while ( iRv >= 0 && aHTREEITEM != TVI_ROOT ){
		//	『前の兄弟アイテム』に移動
		HTREEITEM	htreeitemNew = m_pCTreeCtrl->GetNextItem( 
			aHTREEITEM , TVGN_PREVIOUS ) ;
		if ( htreeitemNew != NULL ){
			( *pItemlocation)[0]++ ;
			aHTREEITEM = htreeitemNew ;
		}	else	{
			//	『親アイテム』に移動
			htreeitemNew = m_pCTreeCtrl->GetNextItem( 
				aHTREEITEM , TVGN_PARENT ) ;
			//	aHTREEITEM が第一階層の場合、 htreeitemnNew は
			//	NULL になります（TVI_ROOTにはならない点に注意が必要です）
			if ( htreeitemNew != NULL ){
				pItemlocation->push_front( 0 ) ;
				aHTREEITEM = htreeitemNew ;
			}	else	{
				break ;
			}
		}
	}
	return ( iRv ) ;
}
	
HTREEITEM CaTreeCtrl::HTREEITEM_from_Itemlocation( 
		const Itemlocation* pItemlocation ) 
{
	HTREEITEM	hRv = NULL ;
	int iRv = 0 ;
	
	HTREEITEM	hCurr = TVI_ROOT ;

	int idxItemlocation = 0 ;
	for ( idxItemlocation = 0 ; 
			iRv >= 0 && idxItemlocation < (int)pItemlocation->size() ; 
			idxItemlocation ++ ){
		//	hCurr = 『子アイテム』に移動しました。
		hCurr = m_pCTreeCtrl->GetNextItem( hCurr , TVGN_CHILD ) ;
		if ( hCurr == NULL ){
			iRv = -1 ;	//	対応するアイテムが見つかりません。
		}	else	{ 
			int iPos ;
			for ( iPos = (*pItemlocation)[idxItemlocation] ; iPos > 0 ; 
					iPos -- ){
				hCurr = m_pCTreeCtrl->GetNextItem( hCurr , TVGN_NEXT ) ;
				if ( hCurr == NULL ){
					iRv = -1 ;	//	対応するアイテムが見つかりません。
				}
			}
		}
	}			
	if ( iRv >= 0 ){
		hRv = hCurr ;
	}
	return ( hRv ) ;
}
} //namespace TreeCtrl
} //namespace OuMfc
