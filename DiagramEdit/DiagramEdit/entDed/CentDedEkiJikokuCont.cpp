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
//$Id: CentDedEkiJikokuCont.cpp 378 2016-11-16 21:10:54Z okm $
/** @file */
#include "stdafx.h"
#include "CentDedEkiJikokuCont.h"
#include "CentDedRosen.h"
#include "CentDedRessya.h"

namespace entDed{

	// ********************************
	//	コンストラクタ
	// ********************************
CentDedEkiJikokuCont::CentDedEkiJikokuCont() 
{
}
CentDedEkiJikokuCont& CentDedEkiJikokuCont::operator=( const CentDedEkiJikokuCont& value ) 
{
	CentDedRosen* pRosen = getRosen() ;

	//△operator=: this が路線の一部である場合は、駅時刻の数は変更しません
	if ( pRosen != NULL )
	{
		int i ; 
		for ( i = 0 ;i < this->size() && i < value.size() ; i ++ )
		{
			this->set( value.get( i ) , i ) ; 
		}
		//	右辺の方が要素が少ない場合は、左辺の残り要素は空で埋めます。
		for ( ; i < this->size() ; i++ )
		{
			this->set( CentDedEkiJikoku() , i ) ; 
		}
	}
	else
	{
		super::operator =( value ) ;
	}
	return *this ;
}


	// ********************************
	///@name Mui
	// ********************************
int CentDedEkiJikokuCont::insert( const CentDedEkiJikoku& element , int iIndex )
{
	CentDedRosen* pRosen = getRosen() ;

	//	列車が路線の一部である場合はエラー。
	//	(もともと駅数と駅時刻の数が一致していない場合は、エラーにしないほうが
	//	よいかもしれません。)
	if ( pRosen != NULL && pRosen->getCentDedEkiCont()->size() == size() )
	{
		return -11 ;	//	列車が路線の一部である場合、駅時刻の追加はできません。
	}

	return super::insert( element , iIndex ) ;
}
	
int CentDedEkiJikokuCont::erase( int iIndex  , int iSize ) 
{
	CentDedRosen* pRosen = getRosen() ;

	//	列車が路線の一部である場合はエラー。
	if ( pRosen != NULL && pRosen->getCentDedEkiCont()->size()  == size() )
	{
		return -11 ;	//	列車が路線の一部である場合、駅時刻の削除はできません。
	}
	return super::erase( iIndex , iSize ) ;
}
	
int CentDedEkiJikokuCont::set( const CentDedEkiJikoku& element , int iIndex )
{
	return super::set( element , iIndex ) ;
}


	// ********************************
	//@name CentDedEkiJikokuCont-関連
	// ********************************
CentDedRosen* CentDedEkiJikokuCont::getRosen()
{
	CentDedRessya* pRessya = getRessya() ;
	if ( pRessya == NULL ){	return NULL ;}
	CentDedRessyaCont* pDiaCont = dynamic_cast<CentDedRessyaCont*>( pRessya->getParent() ) ;
	if ( pDiaCont == NULL ){	return NULL ;}
	return pDiaCont->getRosen() ;
}
const CentDedRosen* CentDedEkiJikokuCont::getRosen()const
{
	const CentDedRessya* pRessya = getRessya() ;
	if ( pRessya == NULL ){	return NULL ;}
	const CentDedRessyaCont* pDiaCont = dynamic_cast<const CentDedRessyaCont*>( pRessya->getParent() ) ;
	if ( pDiaCont == NULL ){	return NULL ;}
	return pDiaCont->getRosen() ;
}

	// ********************************
	//@name CentDedEkiJikokuTrackCont-操作
	// ********************************
int CentDedEkiJikokuCont::setable(  const CentDedEkiJikoku& element , int iIndex )const 
{
	const CentDedRosen* pCentDedRosen = getRosen() ;
	if ( pCentDedRosen != NULL )
	{
	}
	return 0 ; 
}

int CentDedEkiJikokuCont::getIndex( const CentDedEkiJikoku* element )const
{
	const Mu<const CentDedEkiJikoku*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;
}
void CentDedEkiJikokuCont::adjust()
{
	//△駅時刻(CentDedEkiJikoku)の要素数が駅コンテナ(CentDedEkiCont)
	//と異なる場合は、駅時刻を追加・削除します。
	CentDedRosen* pCentDedRosen = getRosen() ;
	if ( pCentDedRosen != NULL )
	{
		CentDedEkiCont* pCentDedEkiCont = pCentDedRosen->getCentDedEkiCont() ;
		//	駅時刻が少ない場合は追加
		while ( size() < pCentDedEkiCont->size() )
		{
			insert( CentDedEkiJikoku() ) ; 
		}
		//	駅時刻が多い場合は削除
		while( size() >  pCentDedEkiCont->size() )
		{
			erase( INT_MAX ) ;
		}

	}

	// --------------------------------
	Mu<CentDedEkiJikoku*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		pMu->get( idx )->adjust() ;
	}
}

	// ********************************
	//@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
void CentDedEkiJikokuCont::onEkiInsert( int iEkiOrder )
{
	super::insert( CentDedEkiJikoku() , iEkiOrder ) ;
}

void CentDedEkiJikokuCont::onEkiErase( int iEkiOrder  )
{
	super::erase( iEkiOrder ) ;
}

void CentDedEkiJikokuCont::onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex )
{
	getMuPtr()->get( iEkiOrder )->onEkiTrackInsert(  iEkiTrackIndex ) ;
}
void CentDedEkiJikokuCont::onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex )
{
	getMuPtr()->get( iEkiOrder )->onEkiTrackErase( iEkiTrackIndex ) ;
}



}; //namespace entDed

