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
//	CentDedDiaCont.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include "CentDedRosen.h"
#include "CentDedDiaCont.h"
#include "NsMu/CaMui.h"
using namespace std ;

#ifdef _MFC_VER 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif


namespace entDed{

// ****************************************************************
//	CentDedDiaCont
// ****************************************************************

// ********************************
//	コンストラクタ
// ********************************


// ********************************
//@name Mui
// ********************************

int CentDedDiaCont::insert( const CentDedDia& element , int iIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( element.getName().empty() ){
			iRv = -2 ;	//	element にはダイヤ名が指定されていません。
		}
	}
	if ( iRv >= 0 ){
		int iIndexFind = findCentDedDiaByName( element.getName() ) ;
		if ( iIndexFind >= 0 ){
			iRv = -3 ;	//	すでに同名のダイヤが存在します。
		}
	}
	if ( iRv >= 0 ){
		iRv = super::insert( element , iIndex ) ;
	}
	return iRv ;
}
int CentDedDiaCont::set( const CentDedDia& element , int iIndex ) 
{
	if ( iIndex == INT_MAX )
	{
		iIndex = size() - 1 ;
	}
	int iRv = setable( element , iIndex ) ;
	if ( iRv >= 0 ){
		iRv = super::insert( element , iIndex ) ;
	}
	return iRv ;
};
// ********************************
//	CentDedDiaCont
// ********************************
	// ********************************
	//@name CentDedDiaCont-操作
	// ********************************
int CentDedDiaCont::setable(  const CentDedDia& element , int iIndex )const 
{
	int idx ;
	if ( element.getName().length() == 0 ) 
	{
		return -2 ;	//	element にはダイヤ名が指定されていません。
	}
	for ( idx = 0 ; idx < size() ; idx ++ )
	{
		const CentDedDia* pDiaExist = getMuPtr()->get( idx ) ; 
		//	異なるインデクスに、同じ名前のダイヤがあれば、エラーです
		if ( idx != iIndex && element.getName() == pDiaExist->getName() )
		{
			return -3 ;	//	すでに同名のダイヤが存在します。
		}
	}
	return 0 ;
}

int  CentDedDiaCont::getIndex( const CentDedDia* element )const 
{
	const Mu<const CentDedDia*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;

}

void CentDedDiaCont::adjust() 
{
	Mu<CentDedDia*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		pMu->get( idx )->adjust() ;
	}
}




int CentDedDiaCont::findCentDedDiaByName( const string& strName )const 
{
	const Mu< const CentDedDia* >* pIfContGet = getMuPtr() ;
	int iRv = -1 ;
	for ( int idx = 0 ; iRv == -1 && idx < pIfContGet->size() ; idx ++ ){
		if ( strName == pIfContGet->get( idx )->getName() ){
			iRv = idx ;
		}
	}
	return ( iRv ) ;
}
	// ********************************
	//@name CentDedDiaCont-操作 駅の増減
	// ********************************

int CentDedDiaCont::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piDiaIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const
{
	int iRv = 0 ;
	int iDiaIndexFound = -1 ;
	ERessyahoukou eRessyahoukouFound = Ressyahoukou_Kudari ;
	int iRessyaIndexFound = -1 ;
	// --------------------------------
	if ( iRv >= 0 ){

		const Mu<const CentDedDia*>* pIfContGet = getMuPtr() ; 
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iRv == 0 && iDiaIndex < pIfContGet->size() ; iDiaIndex ++ ){
			const CentDedDia*	pCentDedDia = pIfContGet->get( iDiaIndex ) ;
			iRv = pCentDedDia->isExistRessyaOfRessyasyubetsu(  
					iRessyasyubetsuIndex , 
					&eRessyahoukouFound , 
					&iRessyaIndexFound )  ;
			if ( iRv == 1 ){
				iDiaIndexFound = iDiaIndex ;
			}
		}
	}
	// --------------------------------
	if ( piDiaIndex != NULL ){
		*piDiaIndex = iDiaIndexFound ;
	}
	if ( peRessyahoukou != NULL ){
		*peRessyahoukou = eRessyahoukouFound ;
	}
	if ( piRessyaIndex != NULL ){
		*piRessyaIndex = iRessyaIndexFound ;
	}

	return ( iRv ) ;
	
}
	// ********************************
	//@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
void CentDedDiaCont::onEkiInsert( int iEkiIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onEkiInsert( iEkiIndex ) ;
	}
}

void CentDedDiaCont::onEkiErase( int iEkiIndex  )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onEkiErase( iEkiIndex ) ;
	}
}
void CentDedDiaCont:: onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onEkiTrackInsert( iEkiIndex , iEkiTrackIndex ) ;
	}
}
void CentDedDiaCont::onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onEkiTrackErase( iEkiIndex , iEkiTrackIndex ) ;
	}
}
void CentDedDiaCont::onRessyasyubetsuInsert( int iRessyasyubetsuIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onRessyasyubetsuInsert( iRessyasyubetsuIndex ) ;
	}
}
void CentDedDiaCont::onRessyasyubetsuErase( int iRessyasyubetsuIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onRessyasyubetsuErase( iRessyasyubetsuIndex ) ;
	}
}



	///@}
} //namespace entDed

