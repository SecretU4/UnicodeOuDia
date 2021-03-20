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
//$Id: CentDedEkiJikokuTrackCont.cpp 378 2016-11-16 21:10:54Z okm $
/** @file */

#include "stdafx.h"
#include "CentDedEkiJikokuCont.h"
#include "CentDedEkiJikokuTrackCont.h"
#include "CentDedRosen.h"


namespace entDed{
	
// ****************************************************************
//	CentDedEkiJikokuTrackCont
// ****************************************************************

	// ********************************
	//	コンストラクタ
	// ********************************
CentDedEkiJikokuTrackCont::CentDedEkiJikokuTrackCont() 
{
	//○コンテナの生成(コンストラクタ):番線指定子は『本線』 列車方向に応じた『NULL要素2個を設定する。
	super::insert( CentDedEkiJikokuTrack() ) ; 
	super::insert( CentDedEkiJikokuTrack() ) ; 
}
CentDedEkiJikokuTrackCont::CentDedEkiJikokuTrackCont(const CentDedEkiJikokuTrackCont& value ) 
: super( value ) 
{
}
CentDedEkiJikokuTrackCont& CentDedEkiJikokuTrackCont::operator=(const CentDedEkiJikokuTrackCont& value ) 
{
	super::operator=( value ) ;
	return *this ;
}
	// ********************************
	//@name Mui
	// ********************************
int CentDedEkiJikokuTrackCont::insert( const CentDedEkiJikokuTrack& element , int iIndex )
{
	//○insert,erase は、エラー(要素数が固定のため)
	return -1 ;
}
int CentDedEkiJikokuTrackCont::erase( int iIndex  , int iSize ) 
{
	//○insert,erase は、エラー(要素数が固定のため)
	return -1 ;
}
int CentDedEkiJikokuTrackCont::set( const CentDedEkiJikokuTrack& element , int iIndex ) 
{
	int iResult = setable( element , iIndex ) ;
	if ( iResult < 0 ){	
		return  iResult ;
	}
	return super::set(element , iIndex )  ;
}

	// ********************************
	//@name CentDedEkiJikokuTrackCont-関連
	// ********************************
CentDedRosen* CentDedEkiJikokuTrackCont::getRosen() 
{
	CentDedRosen* pRosen = NULL ;
	CentDedEkiJikoku* pEkiJikoku = getEkiJikoku() ;
	if ( pEkiJikoku == NULL ){	return NULL ;}
	CentDedEkiJikokuCont* pEkiJikokuCont = dynamic_cast<CentDedEkiJikokuCont*>( pEkiJikoku->getParent() ) ;
	if ( pEkiJikokuCont == NULL ){	return NULL ;}
	pRosen = pEkiJikokuCont->getRosen() ;
	return pRosen ;
}
const CentDedRosen* CentDedEkiJikokuTrackCont::getRosen()const
{
	const CentDedRosen* pRosen = NULL ;
	const CentDedEkiJikoku* pEkiJikoku = getEkiJikoku() ;
	if ( pEkiJikoku == NULL ){	return NULL ;}
	const CentDedEkiJikokuCont* pEkiJikokuCont = dynamic_cast<const CentDedEkiJikokuCont*>( pEkiJikoku->getParent() ) ;
	if ( pEkiJikokuCont == NULL ){	return NULL ;}
	pRosen=  pEkiJikokuCont->getRosen() ;
	return pRosen ;
}

const CentDedEki* CentDedEkiJikokuTrackCont::getEki()const 
{
	const CentDedRosen* pRosen = getRosen() ;
	if ( pRosen == NULL ){ return NULL ;}

	//	駅オブジェクトを取得します。
	//	この配列のインデクスは『駅Order』なので、『駅Index』に変換します。
	//	(このために、駅Orderと列車方向が必要です)
	const CentDedEki* pEki = NULL ;
	{
		//	この入線時刻の駅Orderと列車方向を取得します。
		ERessyahoukou eRessyahoukou ;
		int iEkiOrder ;
		{
			const CentDedEkiJikokuCont* pEkiJikokuCont = static_cast<const CentDedEkiJikokuCont*>( this->getEkiJikoku()->getParent() );
			iEkiOrder = pEkiJikokuCont->getIndex( this->getEkiJikoku() ) ;
			eRessyahoukou = pEkiJikokuCont->getRessya()->getRessyahoukou() ;
		}

		pEki = pRosen->getCentDedEkiCont()->getMuPtr()->get( 
				pRosen->getCentDedEkiCont()->EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrder ) ) ;
	}
	return pEki ;
}


	// ********************************
	//@name CentDedEkiJikokuTrackCont-操作
	// ********************************
int  CentDedEkiJikokuTrackCont::setable(  const CentDedEkiJikokuTrack& element , int iIndex )const 
{

	//△set  CentDedEkiJikokuTrack が路線(CentDedRosen)の一部である場合で、
	//番線指定子が『番線コンテナ』CentDedEkiTrackCont の要素に対応していない場合は、エラーとする。
	const CentDedEki* pEki = getEki() ;
	if ( pEki != NULL )
	{
		const CentDedEkiTrackCont* pEkTrackCont = pEki->getEkiTrackCont() ;

		if ( !element.getTrack().isNull() && element.getTrack().getiIndex() >= pEkTrackCont->size() )
		{
			return -11 ;	//	番線のIndexが、CentDedEkiTrackContの要素に対応していません
		}
	}

	//△set  CentDedEkiJikokuTrackCont が駅時刻の一部である場合で、
	//駅時刻が運行なし・経由なしの場合、
	//NULL以外の番線・NULL以外の入線時刻を持つ入線の設定はエラーとする。
	const CentDedEkiJikoku* pEkiJikoku = getEkiJikoku() ;
	if (pEkiJikoku  != NULL )
	{
		if ( pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None
			|| pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
		{
			if ( !element.getTrack().isNull() )
			{
				return -12 ;	//	駅時刻が運行なし・経由なしの場合、NULL以外の番線の設定はできません
			}
			if ( !element.getNyusenJikoku().isNull() )
			{
				return -13 ;	//	駅時刻が運行なし・経由なしの場合、NULL以外の入線時刻の設定はできません
			}
		}

	}

	return 0 ; 
}

int  CentDedEkiJikokuTrackCont::getIndex( const CentDedEkiJikokuTrack* element )const 
{
	const Mu<const CentDedEkiJikokuTrack*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;
}
void CentDedEkiJikokuTrackCont::adjust() 
{
	Mu<CentDedEkiJikokuTrack*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		pMu->get( idx )->adjust() ;
	}
}

	// ********************************
	//@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
void CentDedEkiJikokuTrackCont::onEkiTrackInsert(  int iEkiTrackIndex )
{
	Mu<CentDedEkiJikokuTrack*>* muEkiJikokuTrack = getMuPtr() ;
	for ( int i = 0 ; i < muEkiJikokuTrack->size() ; i ++ )
	{
		muEkiJikokuTrack->get( i )->onEkiTrackInsert( iEkiTrackIndex ) ;
	}
}
void CentDedEkiJikokuTrackCont::onEkiTrackErase( int iEkiTrackIndex )
{
	Mu<CentDedEkiJikokuTrack*>* muEkiJikokuTrack = getMuPtr() ;
	for ( int i = 0 ; i < muEkiJikokuTrack->size() ; i ++ )
	{
		muEkiJikokuTrack->get( i )->onEkiTrackErase( iEkiTrackIndex ) ;
	}
}


}//namespace entDed


