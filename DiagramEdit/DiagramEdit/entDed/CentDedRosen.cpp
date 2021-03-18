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
//	CentDedRosen.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include <assert.h>

#include "NsMu/CaMui.h" 
#include "CentDedRosen.h"

using namespace std ;


#ifdef _MFC_VER 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

namespace entDed{

const char nameRessyasyubetsuDefault[] = "普通" ; 

// ----------------------------------------------------------------
//	CentDedRosen::CXCentDedEkiCont
// ----------------------------------------------------------------
	// ********************************
	//	コンストラクタ
	// ********************************

	// ********************************
	//	Mui
	// ********************************

int CentDedRosen::CXCentDedEkiCont::insert( const CentDedEki& element , int iIndex )
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX ){
			iIndex = size() ;
		}
		if ( !( 0 <= iIndex && iIndex <= size() ) ){
			iRv = -1 ;
		}
	}	
	if ( iRv >= 0 ){
		iRv = super::insert( element , iIndex ) ;
	}
	return ( iRv ) ;
}
int CentDedRosen::CXCentDedEkiCont::erase( int iIndex  , int iSize ) 
{
	int iRv = 0 ;
	
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX && iSize == INT_MAX ){
			iRv = -1 ;
		}	else if ( iIndex == INT_MAX ){
			iIndex = size() - iSize ;
		}	else if ( iSize == INT_MAX ){
			iSize = size() - iIndex ;
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= size() ) ){
			iRv = -1 ;
		}
	}	
	
	if ( iRv >= 0 ){
		iRv = super::erase( iIndex , iSize ) ;
	}

	return ( iRv ) ;
};
		// ********************************
		//@name CentDedEkiCont-関連
		// ********************************
CentDedRosen*  CentDedRosen::CXCentDedEkiCont::getRosen()
{
	CentDedRosen* pOuter = (CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedEkiCont ) ) ;
	return pOuter ;
}
const CentDedRosen*  CentDedRosen::CXCentDedEkiCont::getRosen()const 
{
	const CentDedRosen* pOuter = (const CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedEkiCont ) ) ;
	return pOuter ;
}

// ----------------------------------------------------------------
//	CentDedRosen::CXCentDedRessyasyubetsuCont
// ----------------------------------------------------------------
	// ********************************
	//	コンストラクタ
	// ********************************
CentDedRosen::CXCentDedRessyasyubetsuCont::	CXCentDedRessyasyubetsuCont() 
{
	//既定の列車種別の追加は、CentDedRosen::CentDedRosen で行います。
}
	// ********************************
	//	Mui
	// ********************************


		// ********************************
		//@name CentDedEkiCont-関連
		// ********************************
CentDedRosen* CentDedRosen::CXCentDedRessyasyubetsuCont::getRosen()
{
	CentDedRosen* pOuter = (CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedRessyasyubetsuCont ) ) ;
	return pOuter ;
}
const CentDedRosen* CentDedRosen::CXCentDedRessyasyubetsuCont:: getRosen()const 
{
	const CentDedRosen* pOuter = (const CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedRessyasyubetsuCont ) ) ;
	return pOuter ;
}

// ----------------------------------------------------------------
//	CentDedRosen::CXCentDedDiaCont
// ----------------------------------------------------------------
		// ********************************
		//	コンストラクタ
		// ********************************

		// ********************************
		//@name CentDedDiaCont-関連
		// ********************************
CentDedRosen* CentDedRosen::CXCentDedDiaCont::getRosen()
{
	CentDedRosen* pOuter = (CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedDiaCont ) ) ;
	return pOuter ;
}
const CentDedRosen* CentDedRosen::CXCentDedDiaCont::getRosen()const 
{
	const CentDedRosen* pOuter = (const CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedDiaCont ) ) ;
	return pOuter ;
}
		

// ****************************************************************
//	CentDedRosen
// ****************************************************************

// ********************************
//	コンストラクタ
// ********************************
CentDedRosen::CentDedRosen() 
	: m_jikokuKitenJikoku( 0 , 0 , 0 ) 
	, m_iDiagramDgrYZahyouKyoriDefault( 60 )
{
	//	デフォルトの『列車種別』の名前を設定します。
	m_CentDedRessyasyubetsuCont.insert( 
		CentDedRessyasyubetsu( nameRessyasyubetsuDefault , ""  ) , 
		INT_MAX ) ;
}
	

CentDedRosen::CentDedRosen( const CentDedRosen& value )
	: m_CentDedRessyasyubetsuCont( value.m_CentDedRessyasyubetsuCont ) 
{
	m_strName = value.m_strName ;
	m_jikokuKitenJikoku = value.m_jikokuKitenJikoku ;
	m_iDiagramDgrYZahyouKyoriDefault = value.m_iDiagramDgrYZahyouKyoriDefault ;
	m_strComment = value.m_strComment ;

	CaMui<CentDedEki>( &m_CentDedEkiCont ).insert( &value.m_CentDedEkiCont , 0 , INT_MAX , 0 ) ;
	m_CentDedDiaCont = value.m_CentDedDiaCont ;
}
	
CentDedRosen& CentDedRosen::operator=( const CentDedRosen& value )
{
	// --------------------------------
	//	それまでの値を破棄
	// --------------------------------

	m_CentDedDiaCont.erase( 0 , INT_MAX ) ;

	//	デフォルト列車のみにします。
	m_CentDedRessyasyubetsuCont.erase( 1 , INT_MAX ) ;
	m_CentDedRessyasyubetsuCont.set( 
		CentDedRessyasyubetsu( nameRessyasyubetsuDefault , ""  ) , 
		INT_MAX ) ;

	m_CentDedEkiCont.erase( 0 , INT_MAX ) ;

	// --------------------------------
	//	値をコピー
	// --------------------------------
	
	m_strName = value.m_strName ;
	m_jikokuKitenJikoku = value.m_jikokuKitenJikoku ;
	m_iDiagramDgrYZahyouKyoriDefault = value.m_iDiagramDgrYZahyouKyoriDefault ;
	m_strComment = value.m_strComment ;
	m_CentDedEkiCont = value.m_CentDedEkiCont ;
	m_CentDedRessyasyubetsuCont = value.m_CentDedRessyasyubetsuCont ;

	m_CentDedDiaCont = value.m_CentDedDiaCont ;

	return ( *this ) ;
}

	
// ********************************
//	CentDedRosen
// ********************************
	// ********************************
	//@name 属性
	// ********************************
	// ********************************
	//@name 包含-CentDedEki
	// ********************************
	
	// ********************************
	//@name 包含-CentDedRessyasyubetsu
	// ********************************

	
	// ********************************
	//@name 包含-CentDedDia
	// ********************************

	// ********************************
	//@name 操作
	// ********************************
void CentDedRosen::insert( 
	const CentDedRosen& rosenToAdd_enter ,
	int iEkiIndexToInsert ) 
{
	CentDedRosen rosenToAdd = rosenToAdd_enter ;
	//○組入れ先駅Index小(起点側)・組入れ先Index大(終点側)を決定
	//	○[組入れ先が始発駅]
	//　　	○組入れ先駅Index小=-1
	//　　	○組入れ先駅Index大=入力された組入れ先の駅Index
	//	○[組入れ先が中間駅]
	//　　	○組入れ先駅Index小=入力された組入れ先の駅Index
	//　　	○組入れ先駅Index大=入力された組入れ先の駅Index
	//	○[組入れ先が終着駅]
	//　　	○組入れ先駅Index小=駅数-1
	//　　	○組入れ先駅Index大=駅数
	int iEkiIndexToInsertMin = -1 ;
	int iEkiIndexToInsertMax = -1 ;
	{
		//○[組入れ先が始発駅]
		if ( iEkiIndexToInsert == 0 )
		{
			iEkiIndexToInsertMin = -1 ;
			iEkiIndexToInsertMax = iEkiIndexToInsert ;
		}
		//○[組入れ先が中間駅]
		//	○組入れ先駅Index小=入力された組入れ先の駅Index
		//	○組入れ先駅Index大=入力された組入れ先の駅Index
		else if ( 0 < iEkiIndexToInsert &&
			iEkiIndexToInsert < getCentDedEkiCont()->size() - 1 )
		{
			iEkiIndexToInsertMin = iEkiIndexToInsert ;
			iEkiIndexToInsertMax = iEkiIndexToInsert ;
		}
		//○[組入れ先が終着駅]
		//	○組入れ先駅Index小=駅数-1
		//	○組入れ先駅Index大=駅数
		else
		{
			iEkiIndexToInsertMin = getCentDedEkiCont()->size() - 1 ;
			iEkiIndexToInsertMax = getCentDedEkiCont()->size() ;
		}
	}
	//○[組入れ先が中間駅]なら、その駅を分割
	if ( 0 < iEkiIndexToInsertMin &&
			iEkiIndexToInsertMax < getCentDedEkiCont()->size() - 1 )
	{
		//　○組入れ先駅Index小=入力された組入れ先の駅Index
		//　│組入れ先駅Index大=入力された組入れ先の駅Index+1
		iEkiIndexToInsertMax = iEkiIndexToInsertMin + 1 ;

		//　○組入れ先駅Index小と同名駅を、組入れ先駅Index+1の位置に追加
		//　│組入れ先駅Index小の駅は下り着時刻
		//　│組入れ先駅Index大の駅は上り着時刻
		{
			CentDedEkiCont* pCentDedEkiCont = getCentDedEkiCont() ;
			CentDedEki*	pDedEkiInsertMin = pCentDedEkiCont->getMuPtr()->get( iEkiIndexToInsertMin ) ;
			pCentDedEkiCont->insert( *pDedEkiInsertMin , iEkiIndexToInsertMax ) ;
			CentDedEki*	pDedEkiInsertMax = pCentDedEkiCont->getMuPtr()->get( iEkiIndexToInsertMax ) ;
			pDedEkiInsertMin->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_KudariChaku ) ;
			pDedEkiInsertMax->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
		}

		//○全ダイヤのループ
		CentDedDiaCont* pCentDedDiaCont = &m_CentDedDiaCont ;
		int idxDia ;
		for ( idxDia = 0 ; idxDia < pCentDedDiaCont->size() ; idxDia ++ )
		{
			CentDedDia* pCentDedDia = pCentDedDiaCont->getMuPtr()->get( idxDia ) ;
			//○下り列車全列車のループ
			//│　○組入れ先駅Order小・組入れ先駅Order大を求める
			{
				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( Ressyahoukou_Kudari ) ;
				int iEkiOrderToInsertMin = -1 ;
				int iEkiOrderToInsertMax = -1 ;
				{
					int iEkiOrder1 = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin ) ;
					int iEkiOrder2 = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax ) ;
					iEkiOrderToInsertMin = min( iEkiOrder1 , iEkiOrder2 ) ;
					iEkiOrderToInsertMax = max( iEkiOrder1 , iEkiOrder2 ) ;
				}

				for ( int idxRessya = 0 ; idxRessya < pCentDedRessyaCont->size() ; idxRessya ++ )
				{
					CentDedRessya* pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( idxRessya ) ;
					CentDedEkiJikoku aEkiJikokuToInserMin = pCentDedRessya->getCentDedEkiJikoku( iEkiOrderToInsertMin ) ;
					CentDedEkiJikoku aEkiJikokuToInserMax = pCentDedRessya->getCentDedEkiJikoku( iEkiOrderToInsertMax ) ;

					//│　○[組入れ先駅Order小が始発駅の列車]
					//│　│組入れ先駅Order大に、組入れ先Order小をコピー
					//│　↓組入れ先駅Order小は、運行なしとする。
					if ( pCentDedRessya->getSihatsuEki() == iEkiOrderToInsertMin )
					{
						aEkiJikokuToInserMax = aEkiJikokuToInserMin ;
						aEkiJikokuToInserMin.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
					}
					//│　○[組入れ先駅Index小が中間駅の列車]
					//│　│　○組入れ先駅Order大に、組入れ先駅Order小の駅時刻をコピー
					else if ( pCentDedRessya->getSihatsuEki() < iEkiOrderToInsertMin && 
						iEkiOrderToInsertMin < pCentDedRessya->getSyuuchakuEki() ) 
					{
						aEkiJikokuToInserMax = aEkiJikokuToInserMin ;
					}
					//│　○[組入れ先駅Order小が終着駅の列車]
					//│　　組入れ先駅Order小は、そのままとする。
					//│　　組入れ先駅Order大は、運行なしとする。
					else if ( pCentDedRessya->getSyuuchakuEki() == iEkiOrderToInsertMin )
					{
						aEkiJikokuToInserMax.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
					}

					pCentDedRessya->setCentDedEkiJikoku( iEkiOrderToInsertMin , aEkiJikokuToInserMin ) ;
					pCentDedRessya->setCentDedEkiJikoku( iEkiOrderToInsertMax , aEkiJikokuToInserMax ) ;
				}
			}

			//○上り列車全列車のループ
			//  　○組入れ先駅Order小・組入れ先駅Order大を求める
			{
				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( Ressyahoukou_Nobori ) ;
				int iEkiOrderToInsertMin = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin ) ;
				int iEkiOrderToInsertMax = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax ) ;
				for ( int idxRessya = 0 ; idxRessya < pCentDedRessyaCont->size() ; idxRessya ++ )
				{
					CentDedRessya* pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( idxRessya ) ;
					CentDedEkiJikoku aEkiJikokuToInserMin = pCentDedRessya->getCentDedEkiJikoku( iEkiOrderToInsertMax ) ;
					CentDedEkiJikoku aEkiJikokuToInserMax = pCentDedRessya->getCentDedEkiJikoku( iEkiOrderToInsertMin ) ;

					//○[組入れ先駅Order大が始発駅の列車]
					//│組入れ先駅Order小は、そのままとする。
					//↓組入れ先駅Order大は、運行なしとする。
					if ( pCentDedRessya->getSihatsuEki() == iEkiOrderToInsertMax )
					{
						aEkiJikokuToInserMax.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
					}
					//○[組入れ先駅Index大が中間駅の列車]
					//│　○組入れ先駅Index小に、組入れ先駅Index大の駅時刻をコピー
					//│　○組入れ先駅Index小の駅時刻を駅時刻形式(着時刻のみ)に合わせて補正
					//│　○(組入れ先駅Index小の発時刻をNULLに変更)
					//│　○組入れ先駅Index大の駅時刻を駅時刻形式(発時刻のみ)に合わせて補正
					//↓　○(組入れ先駅Index大の着時刻をNULLに変更)
					else if ( pCentDedRessya->getSihatsuEki() < iEkiOrderToInsertMax && 
						iEkiOrderToInsertMax < pCentDedRessya->getSyuuchakuEki() ) 
					{
						aEkiJikokuToInserMin = aEkiJikokuToInserMax ;
					}
					//○[組入れ先駅Index大が終着駅の列車]
					//│組入れ先駅Index小に、駅時刻をコピー
					//↓組入れ先駅Index大は、運行なしとする。
					else if ( pCentDedRessya->getSyuuchakuEki() == iEkiOrderToInsertMax )
					{
						aEkiJikokuToInserMin = aEkiJikokuToInserMax ;
						aEkiJikokuToInserMax.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
					}

					pCentDedRessya->setCentDedEkiJikoku( iEkiOrderToInsertMin , aEkiJikokuToInserMin ) ;
					pCentDedRessya->setCentDedEkiJikoku( iEkiOrderToInsertMax , aEkiJikokuToInserMax ) ;
				}
			}
		}
		//○組入れ先駅Index小の駅時刻を駅時刻形式に合わせて補正
		//│　◎駅時刻を駅時刻形式に合わせて補正
		//│　　　○[駅時刻形式に着時刻あり・発時刻なし、
		//│　  　│駅時刻に着時刻なし、発時刻あり]
		//│　  　↓着時刻には発時刻をコピー、発時刻はNULL。
		//│　  　○[駅時刻形式に着時刻なし・発時刻あり
		//│　  　│駅時刻に着時刻あり、発時刻なし]
		//│　  　↓発時刻には着時刻をコピー、着時刻はNULL。
		//│　  　○[駅が始発駅・
		//│　  　│駅時刻形式に着時刻あり・発時刻あり、
		//│　  　│駅時刻に着時刻あり、発時刻なし]
		//│　  　↓発時刻には着時刻をコピー、着時刻はNULL。
		//│　  　○[駅が終着駅・
		//│　  　　駅時刻形式に着時刻あり・発時刻あり
		//│　  　　駅時刻に着時刻なし、発時刻あり]
		//│　  　　着時刻には発時刻をコピー、発時刻はNULL。
		//○組入れ先駅Index大の駅時刻を駅時刻形式に合わせて補正
		adjustByEkijikokukeisiki( iEkiIndexToInsertMin ) ;
		adjustByEkijikokukeisiki( iEkiIndexToInsertMax ) ;
	}
	//○[組入れ先が起点駅]なら、その駅の駅時刻形式は[上り着時刻]とする
	//　　○[組入れ先駅Index小=-1,組入れ先駅Index大=0]
	//　　　　組入れ先駅Index大を上り着時刻とする
	//  　○組入れ先駅Index大の駅時刻を駅時刻形式に合わせて補正
	else if ( iEkiIndexToInsertMin == -1 &&
			iEkiIndexToInsertMax == 0 )
	{
		CentDedEkiCont* pCentDedEkiCont = getCentDedEkiCont() ;
		CentDedEki*	pDedEkiInsert = pCentDedEkiCont->getMuPtr()->get( iEkiIndexToInsertMax ) ;
		pDedEkiInsert->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
		adjustByEkijikokukeisiki( iEkiIndexToInsertMax ) ;
	}
	//○[組入れ先が終点駅]なら、その駅の駅時刻形式は[下り着時刻]とする
	//　　○[組入れ先がIndex小=駅数-1 AND 組入れ先駅Index大=駅数]
	//　　　　組入れ先駅Index小を下り着時刻とする
	//  　○組入れ先駅Index小の駅時刻を駅時刻形式に合わせて補正
	else if ( iEkiIndexToInsertMin == getCentDedEkiCont()->size() - 1 &&
			iEkiIndexToInsertMax == getCentDedEkiCont()->size() ) 
	{
		CentDedEkiCont* pCentDedEkiCont = getCentDedEkiCont() ;
		CentDedEki*	pDedEkiInsert = pCentDedEkiCont->getMuPtr()->get( iEkiIndexToInsertMin ) ;
		pDedEkiInsert->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_KudariChaku ) ;
		adjustByEkijikokukeisiki( iEkiIndexToInsertMin ) ;
	}




	//○駅を追加
	//　　○組入れる路線ファイルの駅をすべて追加する。
	//　　　追加する駅Indexは、組入れ先駅Index小+1。
	//		○[組入れる路線ファイルの起点駅の駅時刻形式が発着以外]
	//		  その駅の駅時刻形式は[上り着時刻]とする
	//		○[組入れる路線ファイルの終点駅の駅時刻形式が発着以外]
	//		  その駅の駅時刻形式は[下り着時刻]とする
	//　　○組入れ先駅Index大に、追加した駅数を加算
	{
		CentDedEkiCont* pCentDedEkiCont = &m_CentDedEkiCont ;
		const CentDedEkiCont* pCentDedEkiContToAdd = rosenToAdd.getCentDedEkiCont() ;
		for ( int idxEki = 0 ; idxEki < pCentDedEkiContToAdd->size() ; idxEki ++ )
		{
			CentDedEki aEki = *pCentDedEkiContToAdd->getMuPtr()->get( idxEki ) ;
			if ( idxEki == 0 && aEki.getEkijikokukeisiki() != CentDedEki::Jikokukeisiki_Hatsuchaku )
			{
				aEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
			}
			else if ( idxEki == pCentDedEkiContToAdd->size() - 1 && 
				aEki.getEkijikokukeisiki() != CentDedEki::Jikokukeisiki_Hatsuchaku )
			{
				aEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_KudariChaku ) ;
			}

			pCentDedEkiCont->insert( 
				aEki ,
				iEkiIndexToInsertMin + 1 + idxEki ) ;


			iEkiIndexToInsertMax ++ ;

		}
	}

	//○[組入れ先が中間駅]なら、組入れ先駅Indexが途中駅となる列車は、
	//　　　　　　　　　　追加された駅の駅時刻を経由なしにする。
	if ( 0 < iEkiIndexToInsertMin &&
			iEkiIndexToInsertMax < getCentDedEkiCont()->size() - 1 )
	{
		//　　○全列車のループ
		//　　　　○下り・上りのループ
		//　　　　  　○組入れ先駅Order小・組入れ先駅Order大を求める
		//　　　　　　○[始発駅が組入れ先駅Order小より前 AND 
		//　　　　　　　終着駅が組入れ先駅Order大より後]
		//　　　　　　　組入れ先駅Order小+1～組入れ先駅Order大-1の駅扱いを
		//　　　　　　　経由なしにする。
		CentDedDiaCont* pCentDedDiaCont = &m_CentDedDiaCont ;
		int idxDia ;
		for ( idxDia = 0 ; idxDia < pCentDedDiaCont->size() ; idxDia ++ )
		{
			CentDedDia* pCentDedDia = pCentDedDiaCont->getMuPtr()->get( idxDia ) ;
			//○下り列車全列車のループ
			//│　○組入れ先駅Order小・組入れ先駅Order大を求める
			for ( int iRessyahoukou = Ressyahoukou_Kudari ;
				iRessyahoukou <= Ressyahoukou_Nobori ;
				iRessyahoukou ++ )
			{
				ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;

				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;
				int iEkiOrderToInsertMin = -1 ;
				int iEkiOrderToInsertMax = -1 ;
				{
					int iEkiOrder1 = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin ) ;
					int iEkiOrder2 = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax ) ;
					iEkiOrderToInsertMin = min( iEkiOrder1 , iEkiOrder2 ) ;
					iEkiOrderToInsertMax = max( iEkiOrder1 , iEkiOrder2 ) ;
				}

				for ( int idxRessya = 0 ; idxRessya < pCentDedRessyaCont->size() ; idxRessya ++ )
				{
					//　　　　　　○[始発駅が組入れ先駅Order小より前 AND 
					//　　　　　　　終着駅が組入れ先駅Order大より後]
					//　　　　　　　組入れ先駅Order小+1～組入れ先駅Order大-1の駅扱いを
					//　　　　　　　経由なしにする。
					CentDedRessya* pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( idxRessya ) ;
					if ( pCentDedRessya->getSihatsuEki() < iEkiOrderToInsertMin && 
						iEkiOrderToInsertMax < pCentDedRessya->getSyuuchakuEki() )
					{

						CentDedEkiJikoku aEkijikokuKeiyunasi( 
							CentDedEkiJikoku::Ekiatsukai_Keiyunasi ,
							CdDedJikoku() , CdDedJikoku() ) ;
						for ( int iEkiOrder = iEkiOrderToInsertMin + 1 ;
							iEkiOrder <= iEkiOrderToInsertMax - 1 ;
							iEkiOrder ++ )
						{
							pCentDedRessya->setCentDedEkiJikoku( iEkiOrder ,aEkijikokuKeiyunasi ) ; 
						}
					}
				}
			}
		}
	}
	//○列車種別のマージ
	//　　○組入れる路線ファイルの列車種別によるループ
	//　　　　○[同名の列車種別が編集中の路線ファイルに存在しない]列車種別を
	//　　　　　編集中の路線ファイルに追加
	//　　　　○列車種別対照表(組入れる路線ファイルの列車種別Index→
	//　　　　　組入れる路線ファイルの列車種別Index の対照表を作成
	deque<int>	arRessyasyubetsuIdx_AddedToThis ;
	{
		CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont = this->getCentDedRessyasyubetsuCont() ;
		const CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuContToAdd = rosenToAdd.getCentDedRessyasyubetsuCont() ;
		

		const Mu<const CentDedRessyasyubetsu*>* muCentDedRessyasyubetsuToAdd =
				pCentDedRessyasyubetsuContToAdd->getMuPtr() ;
		for ( int idxToAdd = 0 ; idxToAdd < muCentDedRessyasyubetsuToAdd->size() ; idxToAdd ++ )
		{
			const CentDedRessyasyubetsu* pCentDedRessyasyubetsuToAdd = 
				muCentDedRessyasyubetsuToAdd->get( idxToAdd ) ;

			Mu<CentDedRessyasyubetsu*>* muCentDedRessyasyubetsuThis =
				pCentDedRessyasyubetsuCont->getMuPtr() ;
			int idxThis = 0 ;
			for ( idxThis = 0 ; idxThis < muCentDedRessyasyubetsuThis->size() ; idxThis ++ )
			{
				const CentDedRessyasyubetsu* pCentDedRessyasyubetsuThis = muCentDedRessyasyubetsuThis->get( idxThis ) ;
				if ( pCentDedRessyasyubetsuThis->getSyubetsumei() == 
					pCentDedRessyasyubetsuToAdd->getSyubetsumei() )
				{
					break ;
				}
			}
			//idxThis = 『追加する路線ファイル』の列車種別[idxToAdd] と同名の
			//	thisの列車種別のインデクス。
			//	なければ、  muCentDedRessyasyubetsuThis->size()

			if ( idxThis == muCentDedRessyasyubetsuThis->size() )
			{
				//	同名の種別がない場合は、
				//	this に追加します。
				pCentDedRessyasyubetsuCont->insert( *pCentDedRessyasyubetsuToAdd ) ;
			}
			arRessyasyubetsuIdx_AddedToThis.push_back( idxThis ) ;
		}

	}
	//arRessyasyubetsuIdx_AddedToThis[追加する路線ファイル』の列車種別インデクス] = 
	//	thisの列車種別インデクス

	//○ダイヤのマージ
	//　　○組入れる路線ファイルのダイヤによるループ
	//　　　　○[同名のダイヤが編集中の路線ファイルに存在しない]空のダイヤを
	//　　　　　編集中の路線ファイルに追加
	//　　　　○ダイヤ対照表(組入れる路線ファイルのダイヤIndex→
	//　　　　　組入れる路線ファイルのダイヤIndex の対照表を作成

	deque<int>	arDiaIdx_AddedToThis ;
	{
		CentDedDiaCont* pCentDedDiaCont = this->getCentDedDiaCont() ;
		const CentDedDiaCont* pCentDedDiaContToAdd = rosenToAdd.getCentDedDiaCont() ;
		
		const Mu<const CentDedDia*>* muCentDedDiaToAdd =
				pCentDedDiaContToAdd->getMuPtr() ;
		for ( int idxToAdd = 0 ; idxToAdd < muCentDedDiaToAdd->size() ; idxToAdd ++ )
		{
			const CentDedDia* pCentDedDiaToAdd = 
				muCentDedDiaToAdd->get( idxToAdd ) ;

			Mu<CentDedDia*>* muCentDedDiaThis =
				pCentDedDiaCont->getMuPtr() ;
			int idxThis = 0 ;
			for ( idxThis = 0 ; idxThis < muCentDedDiaThis->size() ; idxThis ++ )
			{
				const CentDedDia* pCentDedDiaThis = muCentDedDiaThis->get( idxThis ) ;
				if ( pCentDedDiaThis->getName() == 
					pCentDedDiaToAdd->getName() )
				{
					break ;
				}
			}
			//idxThis = 『追加する路線ファイル』のダイヤと同名の
			//	thisのダイヤのインデクス。
			//	なければ、  muCentDedDiaThis->size()

			if ( idxThis == muCentDedDiaThis->size() )
			{
				//	同名のダイヤがない場合は、
				//	this に
				//	列車が空のダイヤを追加します。
				//	（ダイヤオブジェクトを直接追加すると、列車も追加されるため、
				//	うまくいきません) 
				CentDedEkiCont* pCentDedEkiCont = this->getCentDedEkiCont() ;
				CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont = this->getCentDedRessyasyubetsuCont() ;
				CentDedDia	diaNew( pCentDedEkiCont->size() ) ;
				diaNew.setName( pCentDedDiaToAdd->getName() ) ;
				pCentDedDiaCont->insert( diaNew ) ;
			}
			arDiaIdx_AddedToThis.push_back( idxThis ) ;
		}

	}
	//arDiaIdx_AddedToThis[追加する路線ファイル』のダイヤインデクス] = 
	//	thisのダイヤインデクス

	//○組入れる路線ファイルの列車を、編集中の路線ファイルに追加
	//　　○組入れる路線ファイルのダイヤによるループ
	//　　　　○全列車のループ
	//　　　　　　○列車を追加。
	//　　　　　　　追加するダイヤは、ダイヤ対照表にしたがって変換
	//　　　　　　　列車種別Indexは、列車種別対照表に従って変換
	//
	{
		const Mu<const CentDedDia*>* muCentDedDiaToAdd =
			((const CentDedDiaCont*)rosenToAdd.getCentDedDiaCont())->getMuPtr() ;

		for ( int idxDiaToAdd = 0 ; idxDiaToAdd < muCentDedDiaToAdd->size() ; idxDiaToAdd ++ )
		{
			const CentDedDia* pCentDedDiaToAdd = muCentDedDiaToAdd->get( idxDiaToAdd ) ;

			Mu<CentDedDia*>* muCentDedDiaThis =	this->getCentDedDiaCont()->getMuPtr() ;
			CentDedDia* pCentDedDiaThis = muCentDedDiaThis->get( arDiaIdx_AddedToThis[idxDiaToAdd] ) ;
			//pCentDedDiaThis = 列車のコピー先となる CentDedDia ;

			//下り列車→上り列車
			for ( int idxRessyahoukou = (int)Ressyahoukou_Kudari ;
				idxRessyahoukou <= (int)Ressyahoukou_Nobori ;
				idxRessyahoukou ++ )
			{

				ERessyahoukou eRessyahoukou = (ERessyahoukou)idxRessyahoukou ;
				const CentDedRessyaCont* pCentDedRessyaContToAdd = pCentDedDiaToAdd->getCentDedRessyaCont( eRessyahoukou ) ;
				const Mu<const CentDedRessya*>* muCentDedRessyaToAdd = pCentDedRessyaContToAdd->getMuPtr() ;
				CentDedRessyaCont* pCentDedRessyaContThis = pCentDedDiaThis->getCentDedRessyaCont( eRessyahoukou ) ;

				int iEkiOrderToInsert = -1 ;
				if ( eRessyahoukou == Ressyahoukou_Kudari )
				{
					iEkiOrderToInsert = pCentDedRessyaContThis->EkiOrderOfEkiIndex( iEkiIndexToInsertMin + 1 ) ;
				}
				else
				{
					iEkiOrderToInsert = pCentDedRessyaContThis->EkiOrderOfEkiIndex( iEkiIndexToInsertMax - 1 ) ;
				}
				//iEkiOrderToInsert = 組入れる路線ファイルの駅Order0の列車を挿入する、
				//	thisの駅Order

				for ( int idxRessyaToAdd = 0 ; idxRessyaToAdd < muCentDedRessyaToAdd->size() ; idxRessyaToAdd ++ )
				{
					//	現在編集中の路線ファイルに、組入れる路線ファイルの列車を挿入
					//	列車種別・駅時刻は、このあとに修正
					const CentDedRessya* pRessyaToAdd = muCentDedRessyaToAdd->get( idxRessyaToAdd ) ;
					pCentDedRessyaContThis->insert( *pRessyaToAdd ) ;
					CentDedRessya* pRessyaAdded = pCentDedRessyaContThis->getMuPtr()->get( INT_MAX ) ;
					//pRessyaAdded = 組入れる路線ファイルに追加された列車
					//	列車種別・駅時刻は、このあとに修正

					//	列車種別インデクスを、
					//	現在編集中の路線ファイルに合わせて更新。
					pRessyaAdded->setRessyasyubetsuIndex( 
						arRessyasyubetsuIdx_AddedToThis[ pRessyaToAdd->getRessyasyubetsuIndex() ] ) ;

					//	駅時刻を修正
					for ( int iEkiOrder = 0 ; iEkiOrder < pCentDedRessyaContThis->getEkiCount() ; iEkiOrder ++ )
					{
						int iEkiOrderToAdd = iEkiOrder - iEkiOrderToInsert ;
						//iEkiOrderToAdd = thisのiEkiOrderに対応する、
						//	組入れる路線ファイルの駅Order

						if ( 0 <= iEkiOrderToAdd && iEkiOrderToAdd < pCentDedRessyaContToAdd->getEkiCount() )
						{
							//	組入れる路線ファイルの駅Orderに対応する場合は、
							//	組入れる路線ファイルの駅時刻をコピー
							CentDedEkiJikoku aEkiJikokuToAdd = pRessyaToAdd->getCentDedEkiJikoku( iEkiOrderToAdd ) ; 
							pRessyaAdded->setCentDedEkiJikoku( iEkiOrder , aEkiJikokuToAdd ) ; 
						}
						else
						{
							//	組入れる路線ファイルの駅Orderに対応しない駅に対しては、
							//	運行なしを設定
							pRessyaAdded->setCentDedEkiJikoku( iEkiOrder , CentDedEkiJikoku() ) ; 
						}
					}


				}
			}	
		}
	}


	//○[組入れ先駅Index小と組入れ先駅Index小+1で、駅名が同一]駅を併合
	if ( 0 <= iEkiIndexToInsertMin )
	{
		CentDedEkiCont* pCentDedEkiContThis = getCentDedEkiCont() ;
		CentDedEki*	pEkiToInsertMin = pCentDedEkiContThis->getMuPtr()->get( iEkiIndexToInsertMin ) ;
		CentDedEki*	pEkiToInsertMin_1 = pCentDedEkiContThis->getMuPtr()->get( iEkiIndexToInsertMin + 1 ) ;
		if ( pEkiToInsertMin->getEkimei() == pEkiToInsertMin_1->getEkimei() )
		{
			//　　○組入れ先駅Index小の駅時刻形式を発着に変更
			pEkiToInsertMin->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_Hatsuchaku ) ;

			//　　○全ダイヤのループ
			//        ○全下り列車のループ
			//　　　　　　○[組入れ先駅Index小が運行なし]
			//　　　　　　　組入れ先駅Index小+1の駅時刻を組入れ先駅Index小にコピー
			//　　　　○全上り列車のループ
			//　　　　　　○[組入れ先駅Index小が運行なし]
			//　　　　　　　組入れ先駅Index小+1の駅時刻を組入れ先駅Index小にコピー
			CentDedDiaCont* pCentDedDiaCont = this->getCentDedDiaCont() ;
			for ( int idxDia = 0 ; idxDia < pCentDedDiaCont->size() ; idxDia ++ )
			{
				CentDedDia* pDia = pCentDedDiaCont->getMuPtr()->get( idxDia ) ;
				for ( int iRessyahoukou = Ressyahoukou_Kudari ;
					iRessyahoukou <= Ressyahoukou_Nobori ;
					iRessyahoukou ++ )
				{
					ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;

					CentDedRessyaCont* pRessyaCont = pDia->getCentDedRessyaCont( eRessyahoukou ) ;
					int iEkiOrderToInsertMin = pRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin ) ;
					int iEkiOrderToInsertMin_1 = pRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin + 1 ) ;
					for ( int idxRessya = 0 ; idxRessya < pRessyaCont->size() ; idxRessya ++ )
					{
						CentDedRessya* pRessya = pRessyaCont->getMuPtr()->get( idxRessya ) ;
						
						CentDedEkiJikoku aEkijikoku = pRessya->getCentDedEkiJikoku( iEkiOrderToInsertMin ) ;
						if ( aEkijikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None )
						{
							aEkijikoku = pRessya->getCentDedEkiJikoku( iEkiOrderToInsertMin_1 ) ;
							pRessya->setCentDedEkiJikoku( iEkiOrderToInsertMin ,aEkijikoku ) ;
						}
					}
				}
			}
			//　　○組入れ先駅Index小+1の駅を削除
			pCentDedEkiContThis->erase( iEkiIndexToInsertMin + 1 ) ;
			iEkiIndexToInsertMax -- ;
		}
	}

	//○[組入れ先駅Index大と組入れ先駅Index大-1で、駅名が同一]駅を併合
	if ( iEkiIndexToInsertMax < getCentDedEkiCont()->size() - 1 )
	{
		CentDedEkiCont* pCentDedEkiContThis = getCentDedEkiCont() ;
		CentDedEki*	pEkiToInsertMax = pCentDedEkiContThis->getMuPtr()->get( iEkiIndexToInsertMax ) ;
		CentDedEki*	pEkiToInsertMax_1 = pCentDedEkiContThis->getMuPtr()->get( iEkiIndexToInsertMax - 1 ) ;
		if ( pEkiToInsertMax->getEkimei() == pEkiToInsertMax_1->getEkimei() )
		{
			//○組入れ先駅Index大の駅時刻形式を発着に変更
			pEkiToInsertMax->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_Hatsuchaku ) ;
			//○全ダイヤのループ
			//　　○全下り列車のループぴ
			//　　　　○[組入れ先駅Index大が運行なし]
			//　　　　　組入れ先駅Index大-1の駅時刻を組入れ先駅Index大にコピー
			//　　○全上り列車のループぴ
			//　　　　○[組入れ先駅Index大が運行なし]
			//　　　　　組入れ先駅Index大-1の駅時刻を組入れ先駅Index大にコピー
			CentDedDiaCont* pCentDedDiaCont = this->getCentDedDiaCont() ;
			for ( int idxDia = 0 ; idxDia < pCentDedDiaCont->size() ; idxDia ++ )
			{
				CentDedDia* pDia = pCentDedDiaCont->getMuPtr()->get( idxDia ) ;
				for ( int iRessyahoukou = Ressyahoukou_Kudari ;
					iRessyahoukou <= Ressyahoukou_Nobori ;
					iRessyahoukou ++ )
				{
					ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;

					CentDedRessyaCont* pRessyaCont = pDia->getCentDedRessyaCont( eRessyahoukou ) ;
					int iEkiOrderToInsertMax = pRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax ) ;
					int iEkiOrderToInsertMax_1 = pRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax - 1 ) ;
					for ( int idxRessya = 0 ; idxRessya < pRessyaCont->size() ; idxRessya ++ )
					{
						CentDedRessya* pRessya = pRessyaCont->getMuPtr()->get( idxRessya ) ;
						
						CentDedEkiJikoku aEkijikoku = pRessya->getCentDedEkiJikoku( iEkiOrderToInsertMax ) ;
						if ( aEkijikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None )
						{
							aEkijikoku = pRessya->getCentDedEkiJikoku( iEkiOrderToInsertMax_1 ) ;
							pRessya->setCentDedEkiJikoku( iEkiOrderToInsertMax ,aEkijikoku ) ;
						}
					}
				}
			}
			//　　○組入れ先駅Index大-1の駅を削除
			pCentDedEkiContThis->erase( iEkiIndexToInsertMax - 1 ) ;
			iEkiIndexToInsertMax -- ;
		}
	}
	//○、『追加する路線ファイル』のコメントを、『現在編集している路線ファイル』のコメントの末尾に追加。
	{
		string strComment = this->getComment() ;
		strComment += "\n\n" ;
		strComment += rosenToAdd.getComment() ;
		this->setComment( strComment ) ;
	}
}

CentDedRosen CentDedRosen::createSubRosen( 
		int iEkiIndex , int iEkiCount )const 
{
	CentDedRosen rosenNew = *this ;
	/*	
	(1)　新しく生成される路線ファイルは、
	『現在編集している路線ファイル』から、
	指定された範囲以外の駅を削除したものになります。
	*/
	{
		//	『新しく生成される路線ファイル』の終点側の駅を削除
		rosenNew.getCentDedEkiCont()->erase( iEkiIndex + iEkiCount , INT_MAX ) ;
		//	『新しく生成される路線ファイル』の起点側の駅を削除
		rosenNew.getCentDedEkiCont()->erase( 0 , iEkiIndex ) ;
	}
	/*
	(2)　新しく生成される路線が運転区間に含まれない列車は、削除します。
	*/
	{
		Mu<CentDedDia*>* muCentDedDia = rosenNew.getCentDedDiaCont()->getMuPtr() ;

		for ( int idxDia = 0 ; idxDia < muCentDedDia->size() ; idxDia ++ )
		{
			CentDedDia* pCentDedDia = muCentDedDia->get( idxDia ) ;
			//pCentDedDia = 対象となるダイヤ

			//下り列車→上り列車
			for ( int idxRessyahoukou = (int)Ressyahoukou_Kudari ;
				idxRessyahoukou <= (int)Ressyahoukou_Nobori ;
				idxRessyahoukou ++ )
			{
				ERessyahoukou eRessyahoukou = (ERessyahoukou)idxRessyahoukou ;
				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;

				for ( int idxRessya = 0 ; idxRessya < pCentDedRessyaCont->size() ; idxRessya ++ )
				{
					bool bErase = false ;
					CentDedRessya* pRessya = pCentDedRessyaCont->getMuPtr()->get( idxRessya ) ;

					//	列車が運行している区間が一つもない列車は、
					//	削除します。
					if ( !bErase )
					{

						//	列車が運行している区間の最初の駅Orderを
						//	検索します。
						int iEkiOrder = 0 ;
						for ( iEkiOrder = 0 ; 
							iEkiOrder < pRessya->getCentDedEkiJikokuCount() ;
							iEkiOrder ++ )
						{
							if ( pRessya->isRunBetweenNextEki( iEkiOrder ) )
							{
								break ;
							}
						}
						//iEkiOrder = 列車が運行している区間の最初の駅Order
						//	見つからなかった場合は、
						//	pRessya->getCentDedEkiJikokuCount() と等しくなります。
						if ( iEkiOrder == pRessya->getCentDedEkiJikokuCount() )
						{
							bErase = true ;	
						}
					}


					//	列車を削除
					if ( bErase )
					{
						pCentDedRessyaCont->erase( idxRessya ) ;
						idxRessya -- ;
					}
				}
			}

		}
	}


	return rosenNew ;
}

void CentDedRosen::adjustByEkijikokukeisiki( int iEkiIndex ) 
{
	//○全ダイヤのループ
	for ( int idxDia = 0 ; idxDia < m_CentDedDiaCont.size() ; idxDia ++ )
	{
		CentDedDia* pCentDedDia = m_CentDedDiaCont.getMuPtr()->get( idxDia ) ;
		pCentDedDia->adjustByEkijikokukeisiki(
			&m_CentDedEkiCont ,
			iEkiIndex ) ;
	}
}

void CentDedRosen::invert()
{
	//(0)　路線オブジェクトのコピーを作成
	CentDedRosen	aRosenBefore = *this ;


	//(1)　路線ファイルの駅の順序の並び順を逆にします。
	//	最初の状態の路線ファイルのコピーから、駅属性をコピーします。
	{
		for ( int idxEki = 0 ;idxEki < m_CentDedEkiCont.size() ; idxEki ++ )
		{
			CentDedEki	aEki = aRosenBefore.getCentDedEkiCont()->get( 
				m_CentDedEkiCont.size() - idxEki - 1 ) ;

			m_CentDedEkiCont.set( aEki , idxEki ) ;
		}
	}
	//(2)　駅のプロパティは、以下の変換を行います。
	//【補足】
	//	this の駅の属性を変更すると、含まれている列車の着時刻・発時刻は
	//	『始発駅・終着駅の駅時刻形式変更に伴う、着時刻・発時刻の修正』
	//	により、駅時刻が変更されます。
	//	aRosenBefore は、この変更を受ける前の駅時刻を保持します。
	{
		for ( int idxEki = 0 ; idxEki < m_CentDedEkiCont.size() ; idxEki ++ )  
		{
			CentDedEki*	pEki = m_CentDedEkiCont.getMuPtr()->get( idxEki ) ;

			//(2.1)駅名はそのまま

			//(2.2)駅時刻形式
			//	- 下り着時刻→上り着時刻
			//	- 上り着時刻→下り着時刻
			{
				CentDedEki::EEkijikokukeisiki eEkijikokukeisiki = pEki->getEkijikokukeisiki() ;
				if ( eEkijikokukeisiki == CentDedEki::Jikokukeisiki_KudariChaku )
				{
					eEkijikokukeisiki = CentDedEki::Jikokukeisiki_NoboriChaku ;
				}
				else if ( eEkijikokukeisiki == CentDedEki::Jikokukeisiki_NoboriChaku )
				{
					eEkijikokukeisiki = CentDedEki::Jikokukeisiki_KudariChaku ;
				}
				pEki->setEkijikokukeisiki( eEkijikokukeisiki ) ;
			}

			//(2.3)境界線
			//	- 駅の順序を変更後、起点側(駅Indexの小さい側)に1駅シフトする。
			//	- 新しい下り側終点(駅Indexの最も大きい駅)の境界線は無しにする。
			{
				CentDedEki*	pEkiNext = NULL ;
				if ( idxEki + 1 < m_CentDedEkiCont.size() )
				{
					pEkiNext = m_CentDedEkiCont.getMuPtr()->get( idxEki + 1 ) ;
				}

				if ( pEkiNext != NULL )
				{
					pEki->setKyoukaisen( pEkiNext->getKyoukaisen() ) ;
				}
				else
				{
					pEki->setKyoukaisen( false ) ;
				}
			}

			//(2.4)ダイヤグラム列車情報
			//	  下りの内容と上りの内容を入れ替えます。
			{
				CentDedEki::EDiagramRessyajouhouHyouji eRessyajouhouHyoujiKudari = pEki->getDiagramRessyajouhouHyoujiKudari() ;
				CentDedEki::EDiagramRessyajouhouHyouji eRessyajouhouHyoujiNobori = pEki->getDiagramRessyajouhouHyoujiNobori() ;
				pEki->setDiagramRessyajouhouHyoujiKudari( eRessyajouhouHyoujiNobori ) ;
				pEki->setDiagramRessyajouhouHyoujiNobori( eRessyajouhouHyoujiKudari ) ;
			}
		}
	}

	//(3)すべてのダイヤについて、下り列車と上り列車を入れ替えます。
	//	このとき、下り列車を一旦空にしたうえで、
	//	最初の状態(駅の順序の入れ替えを行う前に)の路線オブジェクトのコピーから
	//	列車を挿入します。上りも同様です。
	//【補足】
	//	this の駅の属性を変更すると、含まれている列車の着時刻・発時刻は
	//	『始発駅・終着駅の駅時刻形式変更に伴う、着時刻・発時刻の修正』
	//	により、駅時刻が変更されます。
	//	aRosenBefore は、この変更を受ける前の駅時刻を保持します。
	//	これをコピー元とすることにより、駅時刻の変更を避けることができます。
	{
		for ( int idxDia = 0 ; idxDia < m_CentDedDiaCont.size() ; idxDia ++ )
		{
			CentDedDia* pDia = m_CentDedDiaCont.getMuPtr()->get( idxDia ) ;

			//	下り・上りの列車コンテナにアダプタを付加
			CaMui<CentDedRessya>	aRessyaContKudariAdapter( pDia->getCentDedRessyaCont( Ressyahoukou_Kudari ) ) ;
			CaMui<CentDedRessya>	aRessyaContNoboriAdapter( pDia->getCentDedRessyaCont( Ressyahoukou_Nobori ) ) ;

			//	下り列車コンテナの内容を削除後、
			//	かつての上り列車のコピーを追加
			aRessyaContKudariAdapter.getAdaptee()->erase( 0 , INT_MAX ) ;
			aRessyaContKudariAdapter.insert( 
				aRosenBefore.getCentDedDiaCont()->getMuPtr()->get( idxDia )->getCentDedRessyaCont( Ressyahoukou_Nobori ) );

			//	上り列車コンテナの内容を削除後、
			//	かつての上り列車のコピーを追加
			aRessyaContNoboriAdapter.getAdaptee()->erase( 0 , INT_MAX ) ;
			aRessyaContNoboriAdapter.insert( 
				aRosenBefore.getCentDedDiaCont()->getMuPtr()->get( idxDia )->getCentDedRessyaCont( Ressyahoukou_Kudari ) );

		}
	}


}
int CentDedRosen::swapRessyasyubetsu( int iRessyasyubetsuIndexA ,
		int iRessyasyubetsuIndexB ) 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndexA == INT_MAX ){
			iRessyasyubetsuIndexA = m_CentDedRessyasyubetsuCont.size() - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndexA && 
				iRessyasyubetsuIndexA < m_CentDedRessyasyubetsuCont.size() ) ){
			iRv = -1 ;	//	インデクスが不正

		}
	}
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndexB == INT_MAX ){
			iRessyasyubetsuIndexB = m_CentDedRessyasyubetsuCont.size() - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndexB && 
				iRessyasyubetsuIndexB < m_CentDedRessyasyubetsuCont.size() ) ){
			iRv = -1 ;	//	インデクスが不正

		}
	}
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndexA == iRessyasyubetsuIndexB ){
			iRv = -1 ;	//	インデクスが不正
		}
	}
	// --------------------------------
	//m_CentDedRessyasyubetsuCont の入れ替え
	if ( iRv >= 0 ){
		Mu<CentDedRessyasyubetsu*>*	pIfContGet = m_CentDedRessyasyubetsuCont.getMuPtr() ;
		CentDedRessyasyubetsu	aCentDedRessyasyubetsuA = 
			*pIfContGet->get( iRessyasyubetsuIndexA ) ;
		CentDedRessyasyubetsu	aCentDedRessyasyubetsuB = 
			*pIfContGet->get( iRessyasyubetsuIndexB ) ;
		*pIfContGet->get( iRessyasyubetsuIndexA )  = 
			aCentDedRessyasyubetsuB ; 
		*pIfContGet->get( iRessyasyubetsuIndexB )  = 
			aCentDedRessyasyubetsuA ; 

		// --------------------------------
		//	列車の入れ替え
		// --------------------------------
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iDiaIndex < m_CentDedDiaCont.size() ; iDiaIndex ++ ){
			CentDedDia*	pCentDedDia = m_CentDedDiaCont.getMuPtr()->get( iDiaIndex ) ;
			int iRessyahoukou = 0 ;
			for ( iRessyahoukou = Ressyahoukou_Kudari ; 
					iRessyahoukou <= Ressyahoukou_Nobori ; 
					iRessyahoukou ++ ){
				ERessyahoukou	eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
				
				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;
				Mu< CentDedRessya* >* pCentDedRessyaContGet = pCentDedRessyaCont->getMuPtr() ;

				int iRessyaCount = pCentDedRessyaContGet->size() ;

				int iRessyaIndex ;

				//	iRessyasyubetsuIndexA -> iRessyasyubetsuIndexB
				//	iRessyasyubetsuIndexB -> iRessyasyubetsuIndexA 
				for ( iRessyaIndex = 0 ; 
						iRessyaIndex < iRessyaCount ; 
						iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndexA ){
						iRessyasyubetsuIndexCurr = iRessyasyubetsuIndexB ;	
					}	else if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndexB ){
						iRessyasyubetsuIndexCurr = iRessyasyubetsuIndexA ;
					}
					pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;	
				}
			}
		}
	}

	return ( iRv ) ;
}

void CentDedRosen::clear() 
{
	m_strName.erase() ;
	m_jikokuKitenJikoku.setTime( 0 , 0 , 0 ) ;
	m_strComment.erase() ;

	m_CentDedDiaCont.erase( 0 , INT_MAX ) ;
	m_CentDedRessyasyubetsuCont.erase( 1 , INT_MAX ) ;
	m_CentDedEkiCont.erase( 0 , INT_MAX ) ;

	// --------------------------------
	{
		//	『列車種別』は、少なくとも一つは存在しなくてはなりません。
		m_CentDedRessyasyubetsuCont.set( 
			CentDedRessyasyubetsu( nameRessyasyubetsuDefault , ""  ) , 0 ) ;
	}
};


	// ********************************
	//@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************

void CentDedRosen::onEkiInsert( int iEkiIndex )
{
	m_CentDedDiaCont.onEkiInsert( iEkiIndex ) ;
}
void CentDedRosen::onEkiErase( int iEkiIndex  )
{
	m_CentDedDiaCont.onEkiErase( iEkiIndex ) ;
}


void CentDedRosen::onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex )
{
	m_CentDedDiaCont.onEkiTrackInsert( iEkiIndex , iEkiTrackIndex ) ;
}
void CentDedRosen::onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex )
{
	m_CentDedDiaCont.onEkiTrackErase( iEkiIndex , iEkiTrackIndex ) ;
}
void CentDedRosen::onRessyasyubetsuInsert( int iRessyasyubetsuIndex )
{
	m_CentDedDiaCont.onRessyasyubetsuInsert( iRessyasyubetsuIndex ) ;
}

void CentDedRosen::onRessyasyubetsuErase( int iRessyasyubetsuIndex )
{
	m_CentDedDiaCont.onRessyasyubetsuErase( iRessyasyubetsuIndex ) ;
}



} //namespace entDed
