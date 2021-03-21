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
//	CDedRessyaSoater_Ressyasyubetsu.cpp
// $Id: CDedRessyaSoater_Ressyasyubetsu.cpp 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include <algorithm>

#include "str\strtoint.h"
#include "NsMu\CMup_vector.h"
#include "NsMu\CaMui.h"
#include "CDedRessyaSoater_Ressyasyubetsu.h"

namespace entDed{

// ****************************************************************
//	CdRessyaForSort_Ressya
// ****************************************************************
	/**
		Mu<CentDedRessyaCont*> 内の列車(のIndex)を、
		列車種別で比較する関数オブジェクトです。
	*/
	class CentDedRessyaIdxCompare_Ressyasyubetsu
	{
		// ********************************
		///@name 関連
		// ********************************
		///@{
		/**
			列車コンテナ。
		*/
		const Mu<const CentDedRessya*>* m_pCentDedRessyaCont  ; 

		///@}
	public:
		CentDedRessyaIdxCompare_Ressyasyubetsu(  
			const Mu<const CentDedRessya*>* pCentDedRessyaCont ) 
			: m_pCentDedRessyaCont( pCentDedRessyaCont ) 
		{
		};
		/**
		@return
			*m_pCentDedRessyaCont->get(idxleft ) < *m_pCentDedRessyaCont->get(idxright ) 
			なら真です。

		@note
		  比較基準は、
			- NULLでないものとNULLのものとでは、NULLでないものが先。
			- 列車種別Indexの小さいほうが先。
			- 列車名が辞書順で早い方が先。
			- 号数の長さが短い方が先。
			- 号数が辞書順で早い方が先。
			- 列車番号の長さが短い方が先。
			- 列車番号が辞書順で早い方が先。
			- 列車Indexの小さい方が先。
		*/
		bool operator()( 
			int idxleft , 
			int idxright )
		{
			const CentDedRessya& left  = *m_pCentDedRessyaCont->get(idxleft ) ;
			const CentDedRessya& right = *m_pCentDedRessyaCont->get(idxright ) ;
			// --------------------------------
			//	片方がNULLの場合の比較
			//	- NULLでないものとNULLのものとでは、NULLでないものが先。
			// --------------------------------
			if ( !left.isNull() && right.isNull() )
			{
				//	leftはNULLで、rightは非NULL
				return true ;
			}
			else if ( left.isNull() && !right.isNull() )
			{
				//	leftは非NULLで、rightはNULL
				return false ;
			}
			// --------------------------------
			//	- 列車種別Indexの小さいほうが先。
			// --------------------------------
			if ( left.getRessyasyubetsuIndex() < right.getRessyasyubetsuIndex() )
			{
				return true ;
			}
			else if ( left.getRessyasyubetsuIndex() > right.getRessyasyubetsuIndex() )
			{
				return false ;
			}

			// --------------------------------
			//	- 列車名が辞書順で早い方が先。
			// --------------------------------
			if ( left.getRessyamei() < right.getRessyamei() )
			{
				return true ;
			}
			else if ( left.getRessyamei() > right.getRessyamei() )
			{
				return false ;
			}

			//// --------------------------------
			////	- 号数を整数化した場合に早い方が先。
			//// --------------------------------
			//{
			//	int iLeftGousuu = OuLib::intOf( left.getGousuu() ) ;
			//	int iRightGousuu = OuLib::intOf( right.getGousuu() ) ;
			//	if ( iLeftGousuu < iRightGousuu )
			//	{
			//		return true ;
			//	}
			//	else if ( iLeftGousuu > iRightGousuu )
			//	{
			//		return false ;
			//	}
			//}

			// --------------------------------
			//	- 号数の長さが短い方が先。
			// --------------------------------
			{
				if ( left.getGousuu().length()  < right.getGousuu().length() )
				{
					return true ;
				}
				else if ( left.getGousuu().length() > right.getGousuu().length() )
				{
					return false ;
				}
			}
			// --------------------------------
			//	- 号数が辞書順で早い方が先。
			// --------------------------------
			{
				if ( left.getGousuu()  < right.getGousuu() )
				{
					return true ;
				}
				else if ( left.getGousuu() > right.getGousuu() )
				{
					return false ;
				}
			}
			// --------------------------------
			//	- 列車番号の長さが短い方が先。
			// --------------------------------
			{
				if ( left.getRessyabangou().length()  < right.getRessyabangou().length() )
				{
					return true ;
				}
				else if ( left.getRessyabangou().length() > right.getRessyabangou().length() )
				{
					return false ;
				}
			}
			// --------------------------------
			//	- 列車番号が辞書順で早い方が先。
			// --------------------------------
			{
				if ( left.getRessyabangou()  < right.getRessyabangou() )
				{
					return true ;
				}
				else if ( left.getRessyabangou() > right.getRessyabangou() )
				{
					return false ;
				}
			}
			// --------------------------------
			//	- 列車Indexの小さいほうが先。
			// --------------------------------
			if ( idxleft < idxright )
			{
				return true ;
			}
			return false ;
		}
	};



// ****************************************************************
//	CDedRessyaSoater_Ressyasyubetsu
// ****************************************************************
	// ********************************
	//@name 集約
	// ********************************

	// ********************************
	//@name 状態
	// ********************************
	// --------------------------------
	//@name 下請関数
	// --------------------------------
	// ********************************
	//	コンストラクタ
	// ********************************
CDedRessyaSoater_Ressyasyubetsu::CDedRessyaSoater_Ressyasyubetsu() 
{
}

CDedRessyaSoater_Ressyasyubetsu::~CDedRessyaSoater_Ressyasyubetsu() 
{
}
	
	// --------------------------------
	//@name sort の下請関数(templateパターン)
	// --------------------------------
void CDedRessyaSoater_Ressyasyubetsu::sortRessyaIndex( 
		const CentDedRessyaCont* pRessyaCont , 
		Mui<int>* muRessyaIndexOrder , 
		IfProgress* pIfProgress ) 
{
	bool bAbort = false ;

	const Mu<const CentDedRessya*>* pCentDedRessyaCont = pRessyaCont->getMuPtr() ; 
	//pCentDedRessyaCont = CentDedRessyaCont オブジェクトへのポインタを保持する
	//	コンテナです。

	// --------------------------------
	//	ソート用駅時刻のコンテナの内容に従い、
	//	インデクスをソート
	// --------------------------------
	{
		//	ソートは std::sort を使うため、
		//	インデクスコンテナを std::vector に一旦コピーする
		CMup_vector<int>	contiRessyaIndexOrder ;
		CaMui<int>( &contiRessyaIndexOrder ).insert( muRessyaIndexOrder , 0 , INT_MAX ) ;

		//	std::vector の内容をソート
		std::sort( 
			contiRessyaIndexOrder.getAdaptee()->begin() ,
			contiRessyaIndexOrder.getAdaptee()->end() ,
			CentDedRessyaIdxCompare_Ressyasyubetsu::
				CentDedRessyaIdxCompare_Ressyasyubetsu( 
					pCentDedRessyaCont ) ) ;


		//	ソート結果を、元のコンテナに戻す
		muRessyaIndexOrder->erase( 0 , INT_MAX ) ;
		CaMui<int>( muRessyaIndexOrder ).insert( &contiRessyaIndexOrder , 0 , INT_MAX ) ;
	}

}

} //namespace entDed


