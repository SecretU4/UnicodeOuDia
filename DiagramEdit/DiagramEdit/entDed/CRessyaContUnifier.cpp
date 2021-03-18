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
//	entDed\CRessyaContUnifier.cpp
// $Id: CRessyaContUnifier.cpp 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include <vector>
#include "CRessyaContUnifier.h"

namespace entDed{
	using std::string ;

// ****************************************************************
//	CRessyaContUnifier
// ****************************************************************
	// ********************************
	//@name CRessyaContUnifier-static 操作
	// ********************************
void CRessyaContUnifier::unify( 
		Mui<CentDedRessya>* pMuiRessya ,
		int iRessyaIndex ,
		int iRessyaIndex2 ) 
{
	CentDedRessya	aRessya = pMuiRessya->get( iRessyaIndex ) ;
	CentDedRessya	aRessya2 = pMuiRessya->get( iRessyaIndex2 ) ;
	// ================================	
	//	駅時刻を結合
	// ================================	
	for ( int iEkiOrder = 0 ; iEkiOrder < aRessya.getCentDedEkiJikokuCount() ; iEkiOrder ++ )
	{
		CentDedEkiJikoku	aJikoku = aRessya.getCentDedEkiJikoku( iEkiOrder ) ;
		CentDedEkiJikoku	aJikoku2 = aRessya2.getCentDedEkiJikoku( iEkiOrder ) ;
		//	iRessyaIndex2 が停車・通過なら、駅扱はコピーします。
		//	駅時刻は、NULL以外の場合はコピーします。
		if ( aJikoku2.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya ||
			aJikoku2.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka )
		{
			aJikoku.setEkiatsukai( aJikoku2.getEkiatsukai() ) ;
			if ( !aJikoku2.getChakujikoku().isNull() )
			{
				aJikoku.setChakujikoku( aJikoku2.getChakujikoku() ) ;
			}
			if ( !aJikoku2.getHatsujikoku().isNull() )
			{
				aJikoku.setHatsujikoku( aJikoku2.getHatsujikoku() ) ;
			}

			aRessya.setCentDedEkiJikoku( iEkiOrder , aJikoku ) ;
		}
	}
	// ================================	
	//	運行なし・経由なし を再配置。
	//	始発駅～終着駅の運行なしは経由なしに
	//	始発駅以前・終着駅以後の経由なしは運行なしに、変更します
	// ================================	
	int iRunFirstEkiOrder = aRessya.getRunFirstEkiOrder() ;
	int iRunLastEkiOrder = aRessya.getRunLastEkiOrder() ;
	for ( int iEkiOrder = 0 ; iEkiOrder < aRessya.getCentDedEkiJikokuCount() ; iEkiOrder ++ )
	{
		CentDedEkiJikoku aEkiJikoku = aRessya.getCentDedEkiJikoku( iEkiOrder ) ;

		//	始発駅～終着駅の運行なしは経由なしに変更
		if ( iRunFirstEkiOrder <= iEkiOrder && 
			iEkiOrder <= iRunLastEkiOrder )
		{
			if ( aEkiJikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None )
			{
				aEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Keiyunasi );
			}
		}
		//	始発駅以前・終着駅以後の経由なしは運行なしに、変更します
		else 
		{
			if ( aEkiJikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				aEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None );
			}
		}

		aRessya.setCentDedEkiJikoku( iEkiOrder , aEkiJikoku ) ;
	}
	// ================================	
	//	1番目の列車に駅時刻を設定
	//	2番目の列車は削除
	// ================================	
	pMuiRessya->set( aRessya , iRessyaIndex ) ;
	pMuiRessya->erase( iRessyaIndex2 ) ;
}

	// ********************************
	//	コンストラクタ・デストラクタ
	// ********************************
CRessyaContUnifier::CRessyaContUnifier()
{
}
CRessyaContUnifier::~CRessyaContUnifier() 
{
}

	// ********************************
	//@name 操作
	// ********************************
void CRessyaContUnifier::unify( 
		Mui<CentDedRessya>* pMuiRessya ,
		IfProgress* pIfProgress ) 
{
	int iRv = 0 ; 

	// 列車番号のキャッシュを作成する
	//	これは、pMuiRessya->get()が遅い(より詳しくは、CentDedRessyaのコピーコンストラクタが遅い)
	//	ためです。
	vector<string>	arstrRessyabangou ;
	arstrRessyabangou.reserve( pMuiRessya->size() ) ;
	for ( int iRessyaIndex = 0 ; iRessyaIndex < pMuiRessya->size() ; iRessyaIndex ++ )
	{
		arstrRessyabangou.push_back( pMuiRessya->get( iRessyaIndex ).getRessyabangou() ) ;
	}

	//	列車番号の同じものを一本化
	for ( int iRessyaIndex = 0 ; 
		iRv == 0 && iRessyaIndex < pMuiRessya->size() - 1 ; 
		iRessyaIndex ++ )
	{
		string	strRessyabangou = arstrRessyabangou[iRessyaIndex] ;

		//	列車番号が空文字列でない場合にだけ、一本化を行います
		if ( strRessyabangou.length() > 0 )
		{
			//	一本化対象の列車を検索
			for ( int iRessyaIndex2 = iRessyaIndex + 1 ;
				iRessyaIndex2 <  pMuiRessya->size() ;
				iRessyaIndex2 ++ )
			{
				//	列車番号が同一なら、一本化を行います。
				if ( strRessyabangou == arstrRessyabangou[iRessyaIndex2] )
				{
					unify( pMuiRessya , iRessyaIndex , iRessyaIndex2 ) ;

					//キャッシュの更新
					arstrRessyabangou.erase( arstrRessyabangou.begin() + iRessyaIndex2 ) ;

					iRessyaIndex2 -- ;
				}
			}
		}


		// ================================
		//	処理進捗表示
		// ================================
		if ( pIfProgress != NULL )
		{
			int iProgressResult = pIfProgress->onNotifyProgress( 
				iRessyaIndex , pMuiRessya->size() ) ;
			if ( iProgressResult != 0 )
			{
				iRv = iProgressResult ;
			}
		}
	}
	/*
	//	列車番号の同じものを一本化
	for ( int iRessyaIndex = 0 ; 
		iRv == 0 && iRessyaIndex < pMuiRessya->size() - 1 ; 
		iRessyaIndex ++ )
	{
		CentDedRessya	aRessya = pMuiRessya->get( iRessyaIndex ) ;
		//TODO:Muからconst CentDedRessya* を取得するように変更
		string	strRessyabangou = aRessya.getRessyabangou() ;

		//	列車番号が空文字列でない場合にだけ、一本化を行います
		if ( strRessyabangou.length() > 0 )
		{
			CentDedRessya	aRessya2( aRessya.getCentDedEkiJikokuCount() , 
				aRessya.getRessyahoukou() ) ;
			
			int iRessyaIndex2 ;
			// ================================
			//	一本化対象の列車を検索
			// ================================
			for ( iRessyaIndex2 = iRessyaIndex + 1 ;
				iRessyaIndex2 <  pMuiRessya->size() ;
				iRessyaIndex2 ++ )
			{
				aRessya2 = pMuiRessya->get( iRessyaIndex2 ) ;
				//TODO:Muからconst CentDedRessya* を取得するように変更

				// ================================
				//	列車番号が同一なら、一本化を行います。
				// ================================
				if ( strRessyabangou == aRessya2.getRessyabangou() )
				{
					unify( pMuiRessya , iRessyaIndex , iRessyaIndex2 ) ;
					iRessyaIndex2 -- ;
				}
			}
		}


		// ================================
		//	処理進捗表示
		// ================================
		if ( pIfProgress != NULL )
		{
			int iProgressResult = pIfProgress->onNotifyProgress( 
				iRessyaIndex , pMuiRessya->size() ) ;
			if ( iProgressResult != 0 )
			{
				iRv = iProgressResult ;
			}
		}
	}
	*/
}

} //namespace entDed


