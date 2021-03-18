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
/** @file */
//$Id: CentDedEkiTrackCont.cpp 378 2016-11-16 21:10:54Z okm $


#include "stdafx.h"

#include "CentDedEkiTrackCont.h"
#include "CentDedRosen.h"
#include "CentDedEki.h"

namespace entDed{

	// ********************************
	//	コンストラクタ
	// ********************************
CentDedEkiTrackCont::CentDedEkiTrackCont() 
{
	super::insert( CentDedEkiTrack( CentDedEkiTrack::ETrackType_NoboriMain ) ) ;
	super::insert( CentDedEkiTrack( CentDedEkiTrack::ETrackType_KudariMain ) ) ;
}


CentDedEkiTrackCont& CentDedEkiTrackCont::operator=( const CentDedEkiTrackCont& value )
{
	const Mu<const CentDedEkiTrack*>* muSrc = value.getMuPtr() ;
	
	int idxSrc ;
	//	転送元が、上り本線の前。
	//	転送先が Named なら上書き。転送先が 上り本線ならループ終了 
	for ( idxSrc = 0  
		; muSrc->get( idxSrc )->getTrackType() 
			==  CentDedEkiTrack::ETrackType_Named 
		; idxSrc ++ )
	{
		if ( this->get( idxSrc ).getTrackType() ==  CentDedEkiTrack::ETrackType_Named )
		{
			this->set( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
		else
		{
			this->insert( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
	}
	
	//	転送元が、上り本線
	//	転送先が Named なら削除。転送先が 上り本線なら 
	while( this->get( idxSrc ).getTrackType() != CentDedEkiTrack::ETrackType_NoboriMain )
	{
		this->erase( idxSrc ) ;
	}
	
	//	転送元が、上り本線と下り本線の間。
	//	転送先が Named なら上書き。転送先が 下り本線ならループ終了 
	for ( idxSrc ++  
		; muSrc->get( idxSrc )->getTrackType() 
			==  CentDedEkiTrack::ETrackType_Named 
		; idxSrc ++ )
	{
		if ( this->get( idxSrc ).getTrackType() ==  CentDedEkiTrack::ETrackType_Named )
		{
			this->set( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
		else
		{
			this->insert( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
	}
	
	//	転送元が、上り本線
	//	転送先が Named なら削除。転送先が 上り本線なら 
	while( this->get( idxSrc ).getTrackType() != CentDedEkiTrack::ETrackType_KudariMain )
	{
		this->erase( idxSrc ) ;
	}
	
	//	転送元が、下り本線の後ろ
	//	転送先が Named なら上書き。転送先が 下り本線ならループ終了 
	for ( idxSrc ++  
		; idxSrc < muSrc->size()
		; idxSrc ++ )
	{
		if ( this->get( idxSrc ).getTrackType() ==  CentDedEkiTrack::ETrackType_Named )
		{
			this->set( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
		else
		{
			this->insert( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
	}
	
	//	転送先の余りを削除
	this->erase( idxSrc , INT_MAX ) ; 
	
	
	return *this ;
}

// ********************************
//@name Mui
// ********************************
int CentDedEkiTrackCont::insert( const CentDedEkiTrack& element ,  int iIndex) 
{
	int iRv = 0; 
	if ( iIndex == INT_MAX )
	{
		iIndex = size() ;
	}
	
	if ( element.getTrackType() != CentDedEkiTrack::ETrackType_Named )
	{
		iRv = -11 ;	//	本線を追加することは出来ません。
	}
	if ( iRv >= 0 )
	{
		iRv = super::insert( element ,  iIndex ) ;
	}
	//	  このコンテナが CentDedEki の子オブジェクトで、
	//	その CentDedEki が CentDedRosen に包含されている場合、 insert() 
	//	メソッドは、CentDedRosen::onEkiTrackInsert( iEkiIndex , iEkiTrackIndex ) 
	//	に処理を委譲します。
	if ( iRv >= 0 )
	{
		CentDedRosen* pRosen = getRosen() ;
		CentDedEki* pEki = getEki() ;
		if ( pRosen != NULL && pEki != NULL )
		{
			int iEkiIndex = pRosen->getCentDedEkiCont()->getIndex( pEki ) ;
			pRosen->onEkiTrackInsert( iEkiIndex , iIndex ) ; 
		}
	}

	return iRv ;
}
int CentDedEkiTrackCont::erase( int iIndex  , int iSize ) 
{
	int iRv = 0 ;
	if ( iIndex == INT_MAX && iSize != INT_MAX )
	{
		iIndex = (int)size() - iSize ;
	}
	else if ( iIndex != INT_MAX && iSize == INT_MAX )
	{
		iSize = (int)size() - iIndex ;
	}
	if ( !( 0 <= iIndex && iIndex + iSize <= (int)size() ) )
	{
		iRv = -1 ;	//	インデクスが範囲外です。
	}
	// --------------------------------	
	if ( iRv >= 0 )
	{
		for ( int i = 0 ; i < iSize ; i ++ )
		{
			if ( getMuPtr()->get( iIndex + i )->getTrackType() != CentDedEkiTrack::ETrackType_Named )
			{
				iRv = -11 ;	//	本線を削除することは出来ません。
			}
		}
	}
	// --------------------------------	
	if ( iRv >= 0 )
	{
		iRv = super::erase( iIndex , iSize ) ; 
	}
	// --------------------------------	
	//	  このコンテナが CentDedEki の子オブジェクトで、
	//	その CentDedEki が CentDedRosen に包含されている場合、 erase() 
	//	メソッドは、CentDedRosen::onEkiTrackInsert( iEkiIndex , iEkiTrackIndex )
	//	に処理を委譲します。
	if ( iRv >= 0 )
	{
		CentDedRosen* pRosen = getRosen() ;
		CentDedEki* pEki = getEki() ;
		if ( pRosen != NULL && pEki != NULL )
		{
			int iEkiIndex = pRosen->getCentDedEkiCont()->getIndex( pEki ) ;
			for ( int idx = iIndex + iSize - 1 ; idx >= iIndex ; idx-- )
			{
				pRosen->onEkiTrackErase( iEkiIndex , idx ) ; 
			}
		}
	}
	// --------------------------------	
	return iRv ;
}
int CentDedEkiTrackCont::set( const CentDedEkiTrack& element , int iIndex ) 
{
	int iRv = 0 ; 
	if ( iIndex == INT_MAX )
	{
		iIndex = size() - 1 ;
	}

	if ( iRv >= 0 )
	{
		iRv = setable( element , iIndex ) ;
	}
	if ( iRv >= 0 )
	{
		iRv = super::set( element ,  iIndex ) ;
	}
	return iRv ; 
}
	// ********************************
	//@name CentDedEkiTrackCont-関連
	// ********************************

CentDedRosen* CentDedEkiTrackCont::getRosen() 
{
	if ( getEki() == NULL ){	return NULL ;}
	CentDedEkiCont* pEkiCont = dynamic_cast<CentDedEkiCont*>( getEki()->getParent() ) ;
	if ( pEkiCont == NULL ){	return NULL ;}
	return pEkiCont->getRosen() ;
}
const CentDedRosen* CentDedEkiTrackCont::getRosen()const 
{
	if ( getEki() == NULL ){	return NULL ;}
	const CentDedEkiCont* pEkiCont = dynamic_cast<const CentDedEkiCont*>( getEki()->getParent() ) ;
	if ( pEkiCont == NULL ){	return NULL ;}
	return pEkiCont->getRosen() ;
}


	// ********************************
	///@name CentDedEkiTrackCont-操作
	// ********************************
int  CentDedEkiTrackCont::setable(  const CentDedEkiTrack& element , int iIndex ) const
{
	int iRv = 0 ;
	if ( iIndex == INT_MAX )
	{
		iIndex = size() - 1 ;
	}
	if ( iRv >= 0 )
	{
		if ( getMuPtr()->get( iIndex )->getTrackType() != element.getTrackType() )
		{
			iRv = -11 ;	//	番線種別の異なるオブジェクトを上書きすることはできません。
		}
	}

	return iRv ;
}

int  CentDedEkiTrackCont::getIndex( const CentDedEkiTrack* element ) const
{
	const Mu<const CentDedEkiTrack*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;
}

void CentDedEkiTrackCont::adjust() 
{
	Mu<CentDedEkiTrack*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		pMu->get( idx )->adjust() ;
	}
}


int CentDedEkiTrackCont::findRessyaOfEkiTrack( 
		int index , 
		int* piDiaIndex , 
		ERessyahoukou* pRessyahoukou , int* piRessyaIndex ) const
{
	const CentDedRosen* pRosen = getRosen() ;
	const CentDedEki* pEki = getEki() ;
	if ( pRosen != NULL )
	{
		int iEkiIndex = pRosen->getCentDedEkiCont()->getIndex( pEki ) ;
		for ( int iDiaIndex = 0 ; iDiaIndex < pRosen->getCentDedDiaCont()->size() ; iDiaIndex++ )
		{
			const CentDedDia* pDia = pRosen->getCentDedDiaCont()->getMuPtr()->get( iDiaIndex ) ; 
			for ( int iRessyahoukou = Ressyahoukou_Kudari ; 
					iRessyahoukou <= Ressyahoukou_Nobori ; 
					iRessyahoukou ++ ){
				ERessyahoukou	eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
				int iEkiOrder = pRosen->getCentDedEkiCont()->EkiOrderOfEkiIndex( eRessyahoukou , iEkiIndex ) ; 
				const CentDedRessyaCont* pRessyaCont = pDia->getCentDedRessyaCont( eRessyahoukou ) ;
				for ( int iRessyaIndex = 0  ; iRessyaIndex < pRessyaCont->size() ; iRessyaIndex++ )
				{
					const CentDedRessya* pRessya = pRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
					const CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = pRessya->getCentDedEkiJikokuCont()->getMuPtr()->get( iEkiOrder )->getEkiJikokuTrackCont() ;
					for ( int iEkiJikokuTrackIndex = 0 ; iEkiJikokuTrackIndex < pEkiJikokuTrackCont->size() ; iEkiJikokuTrackIndex++ )
					{
						const CentDedEkiJikokuTrack* pEkiJikokuTrack = pEkiJikokuTrackCont->getMuPtr()->get( iEkiJikokuTrackIndex ) ;
						CentDedEkiTrackSelector aTrackSelector = pEkiJikokuTrack->getTrack() ;
						if ( !aTrackSelector.isNull() && aTrackSelector.getiIndex() == index )
						{
							*piDiaIndex = iDiaIndex ;
							*pRessyahoukou = eRessyahoukou ;
							*piRessyaIndex = iRessyaIndex ;
							return 1 ;
						}
					}
				}
			}
		}


	}
	return 0 ;
}



} //namespace entDed


