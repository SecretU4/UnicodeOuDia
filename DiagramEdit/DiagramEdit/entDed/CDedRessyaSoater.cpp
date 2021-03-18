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
//	CDedRessyaSoater.cpp
//	$Id: CDedRessyaSoater.cpp 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include <vector>
#include "NsMu\CMup_vector.h"
#include "CDedRessyaSoater.h"

namespace entDed{


	// --------------------------------
	//@name sort の下請関数(templateパターン)
	// --------------------------------
void CDedRessyaSoater::makeRessyaIndex( 
		int iRessyaIndex , int iRessyaCount , 
		Mui<int>* muRessyaIndexOrder ) 
{
	muRessyaIndexOrder->erase( 0 , INT_MAX ) ;
	for ( int idx = 0 ; idx < iRessyaCount ; idx ++ )
	{
		muRessyaIndexOrder->insert( iRessyaIndex + idx ) ; 
	}
}




void CDedRessyaSoater::sortRessyaByRessyaIndexOrder( 
		const Mu<int>* muRessyaIndexOrder,
		CentDedRessyaCont* pRessyaCont ) 
{
	std::vector<int>	contiRessyaIndexOrder ;
	contiRessyaIndexOrder.resize( muRessyaIndexOrder->size() ) ;
	for ( int idx = 0 ; idx < muRessyaIndexOrder->size() ; idx ++ )
	{
		contiRessyaIndexOrder[idx] = muRessyaIndexOrder->get( idx ) ;
	}
	//contiRessyaIndexOrder=muRessyaIndexOrder の複製。書き込み可能。

	for ( int idxBeforeSort = 0 ; 
		idxBeforeSort < (int)contiRessyaIndexOrder.size() - 1 ; 
		idxBeforeSort ++ )
	{
		int idxMin = idxBeforeSort ;

		for ( int idxCompare = idxMin + 1 ; 
			idxCompare < (int)contiRessyaIndexOrder.size() ;
			idxCompare ++ )
		{
			if ( contiRessyaIndexOrder[idxMin] > 
				contiRessyaIndexOrder[idxCompare] )
			{
				idxMin = idxCompare ;
			}
		}
		//idxMin = contRessyaIndexOrder[idxBeforeSort以降]の中で、
		//	最小の値を持つインデクス
		//contRessyaIndexOrder[idxBeforeSort],
		//contRessyaIndexOrder[idxMin] = 入れ替えの必要のある列車Index

		// --------------------------------
		//	pRessyaCont の内容を入れ替え	
		// --------------------------------
		{
			CentDedRessya	aRessya1 = pRessyaCont->get( contiRessyaIndexOrder[idxBeforeSort] ) ;
			CentDedRessya	aRessya2 = pRessyaCont->get( contiRessyaIndexOrder[idxMin] ) ;
			pRessyaCont->set( aRessya2 , contiRessyaIndexOrder[idxBeforeSort] ) ;
			pRessyaCont->set( aRessya1 , contiRessyaIndexOrder[idxMin] ) ;
		}
		// --------------------------------
		//	contiRessyaIndexOrder の内容を入れ替え	
		// --------------------------------
		{
			int i1 = contiRessyaIndexOrder[idxBeforeSort] ;
			int i2 = contiRessyaIndexOrder[idxMin] ;
			contiRessyaIndexOrder[idxBeforeSort] = i2 ;
			contiRessyaIndexOrder[idxMin] = i1 ;
		}
	}
}





	// ********************************
	//@name 操作
	// ********************************
void CDedRessyaSoater::sort( 
		CentDedRessyaCont* pRessyaCont ,
		IfProgress* pIfProgress ) 
{
	// --------------------------------
	//	ソートを行う列車Indexを保持したコンテナに、
	//	連番の列車Indexを格納します。
	CMup_vector<int>	muRessyaIndexOrder ;	
	makeRessyaIndex( 0 , pRessyaCont->size() , &muRessyaIndexOrder ) ;

	// --------------------------------
	//	指定された列車Indexの列車を、
	//	指定された駅時刻Orderでソートします。
	sortRessyaIndex( 
		pRessyaCont ,
		&muRessyaIndexOrder ,
		pIfProgress ) ;

	// --------------------------------
	//	列車 index (int)を保持したコンテナに従って、
	//	列車コンテナの列車の並び順を、
	//	入れ替えます。
	sortRessyaByRessyaIndexOrder( 
		&muRessyaIndexOrder , 
		pRessyaCont ) ;
}

} //namespace entDed
