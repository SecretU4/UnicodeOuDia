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
//	CentDedRessyasyubetsuCont.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CentDedRessyasyubetsuCont.h"
#include "CentDedRosen.h"

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

namespace entDed{

// ****************************************************************
//	CentDedRessyasyubetsuCont
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CentDedRessyasyubetsuCont::CentDedRessyasyubetsuCont() 
{
}
CentDedRessyasyubetsuCont& 
CentDedRessyasyubetsuCont::operator=( const CentDedRessyasyubetsuCont& value ) 
{
	//	△コンテナの代入(operator=):コンテナが路線の一部である場合で、右辺の要素数が0の場合は、
	//	インデクス0番の列車種別を追加して、列車種別の数が0にならないようにする
	if ( value.size() == 0 && getRosen() != NULL )
	{
		insert( CentDedRessyasyubetsu( "00" , "" ) ) ;
		erase( 1 , INT_MAX ) ; 
	}
	else
	{
		super::operator=( value ) ; 
	}
	return *this ;
}

	// ********************************
	///@name Mui
	// ********************************
int CentDedRessyasyubetsuCont::insert( const CentDedRessyasyubetsu& element , int iIndex )
{
	int iRv = 0 ; 
	if ( iIndex == INT_MAX )
	{
		iIndex = size() ;
	}

	//rinji
	//	△列車種別の追加(insert):このコンテナが路線の一部である場合、名前が空の列車種別の追加はエラー
	if ( getRosen() != NULL && element.getSyubetsumei().length() == 0 )
	{
		iRv = -11 ;	//	nameが空の CentDedRessyasyubetsuを上書きするとエラー。
	}
	if ( iRv >= 0 )
	{
		iRv = super::insert( element , iIndex ) ; 
	}
	//	  このコンテナが CentDedRosen に包含されている場合、 insert() 
	//	メソッドは、CentDedRosen::onRessyasyubetsuInsert( iEkiIndex ) 
	//	に処理を委譲します。
	if ( iRv >= 0 )
	{
		CentDedRosen* pRosen = getRosen() ;
		if ( pRosen != NULL )
		{
			pRosen->onRessyasyubetsuInsert( iIndex ) ; 
		}
	}

	return iRv ;
}

int CentDedRessyasyubetsuCont::erase( int iIndex  , int iSize ) 
{
	int iRv = 0 ; 

	if ( iIndex == INT_MAX && iSize != INT_MAX )
	{
		iIndex = size() - iSize ;
	}
	else if ( iIndex != INT_MAX && iSize == INT_MAX )
	{
		iSize = size() - iIndex ;
	}
	// --------------------------------	
	if ( !( 0 <= iIndex && iIndex + iSize <= size() ) )
	{
		iRv = -1 ;	//	インデクスが範囲外です。
	}
	if ( iRv >= 0 )
	{
		if ( size() <= iSize && getRosen() != NULL )
		{
			iRv = -11 ;	//	△列車種別の削除(erase):　列車種別が0個になるような削除はエラー

		}
	}
	if ( iRv >= 0 )
	{
		iRv = super::erase( iIndex , iSize ) ;
	}
	//	  このコンテナが  CentDedRosen に包含されている場合、 erase() 
	//	メソッドは、CentDedRosen::onEkiErase( iEkiIndex )
	//	に処理を委譲します。
	if ( iRv >= 0 )
	{
		CentDedRosen* pRosen = getRosen() ;
		if ( pRosen != NULL )
		{
			for ( int idx = iIndex + iSize - 1 ; idx >= iIndex ; idx-- )
			{
				pRosen->onRessyasyubetsuErase( idx ) ; 
			}
		}
	}

	return iRv ;
}
int CentDedRessyasyubetsuCont::set( const CentDedRessyasyubetsu& element , int iIndex ) 
{
	int iRv = setable( element , iIndex ) ;
	if ( iRv < 0 )
	{
		return iRv ;
	}
	return super::set( element , iIndex ) ;
}

	// ********************************
	//@name CentDedRessyasyubetsuCont-操作
	// ********************************
int CentDedRessyasyubetsuCont::setable(  const CentDedRessyasyubetsu& element , int iIndex )const 
{
	int iRv = 0 ;
	if ( iIndex == INT_MAX )
	{
		iIndex = size() - 1 ;
	}

	if ( element.getSyubetsumei().length() == 0 )
	{
		//○番線の上書き(set): nameが空の CentDedRessyasyubetsuを上書きするとエラー。
		iRv = -11 ;	//	
	}

	return iRv ;
}

int CentDedRessyasyubetsuCont::getIndex( const CentDedRessyasyubetsu* element )const 
{
	const Mu<const CentDedRessyasyubetsu*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;
}

int CentDedRessyasyubetsuCont::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piDiaIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const 
{
	const CentDedRosen* pRosen = getRosen() ;
	if ( pRosen  != NULL )
	{
		return pRosen->getCentDedDiaCont()->isExistRessyaOfRessyasyubetsu(
			iRessyasyubetsuIndex , 
			piDiaIndex , 
			peRessyahoukou , 
			piRessyaIndex ) ;
	}
	return 0 ;
}



} //namespace entDed

