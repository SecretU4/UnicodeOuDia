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
// ****************************************************************
//	CentDedRessya_EkijikokuModifyOperation2.cpp
// ****************************************************************
#include "stdafx.h"

#include "CentDedRessya_EkijikokuModifyOperation2.h"

// ****************************************************************
//	CentDedRessya_EkijikokuModifyOperation2
// ****************************************************************
// ********************************
//	CentDedRessya_EkijikokuModifyOperation2-操作
// ********************************
int CentDedRessya_EkijikokuModifyOperation2::
	execute( CentDedRessya* pCentDedRessya , CdDedJikokuOrder aJikokuOrder ) 
{
	int iRv = 0 ;
	
	// --------------------------------
	CentDedRessya	aCentDedRessya( *pCentDedRessya ) ;
	if ( aJikokuOrder.getEkiOrder() == INT_MAX )
	{
		aJikokuOrder.setEkiOrder( pCentDedRessya->getCentDedEkiJikokuCount() - 1 , CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ;
	}
	if ( !( 0 <= aJikokuOrder.getEkiOrder() && 
		aJikokuOrder.getEkiOrder() < pCentDedRessya->getCentDedEkiJikokuCount() ) )
	{
		iRv = -1 ;	//	aJikokuOrder が範囲外です。
	}
	//aCentDedRessya = 操作対象となる列車
	//aJikokuOrder = 時刻Order

	// --------------------------------
	//	１．新しい駅扱を決定
	// --------------------------------
	if ( iRv >= 0 )
	{
		if ( getSetEkiatsukai() )
		{

			CentDedEkiJikoku aCentDedEkiJikoku = aCentDedRessya.getCentDedEkiJikoku( aJikokuOrder.getEkiOrder() ) ;
			CentDedEkiJikoku::EEkiatsukai eEkiatsukai = getEkiatsukai() ;
			if ( eEkiatsukai == CentDedEkiJikoku::Ekiatsukai_Teisya &&
				aCentDedEkiJikoku.getChakujikoku().isNull() && 
				aCentDedEkiJikoku.getHatsujikoku().isNull() )
			{
				//	着時刻・発時刻ともに設定されていない駅時刻を
				//	停車に変更することはできません。
				iRv = -15 ;	

				// --------------------------------
				//	以下の場合の特例措置
				//		駅時刻変更動作内容.駅扱=停車に変更
				//		駅時刻変更動作内容.駅時刻=駅時刻のコピー
				//		駅時刻変更動作内容.駅時刻のコピー元=時刻設定あり
				//		駅時刻変更対象.駅時刻適用対象駅時刻=着・発ともに時刻設定なし
				//	駅扱を停車に変更してから、
				// --------------------------------
				if ( iRv == -15 )
				{
					CdDedJikoku aCdDedJikokuSrc = 
						aCentDedRessya.getEkiJikoku( m_iJikokuOrderCopySrc ) ;
					if ( m_eOperation == OperationCopy && 
						!aCdDedJikokuSrc.isNull() )
					{
						{
							//駅扱の変更
							aCentDedEkiJikoku.setEkiatsukai( eEkiatsukai ) ;
							aCentDedRessya.setCentDedEkiJikoku( aJikokuOrder.getEkiOrder() , aCentDedEkiJikoku ) ;
							iRv = 0 ;
						}
					}
				}
			}
			else
			{
				//駅扱の変更
				aCentDedEkiJikoku.setEkiatsukai( eEkiatsukai ) ;
				aCentDedRessya.setCentDedEkiJikoku( aJikokuOrder.getEkiOrder() , aCentDedEkiJikoku ) ;
			}
		}


	}
	//aCentDedRessya = 駅扱が変更されました。
	
	// --------------------------------
	//	２．時刻の変更
	// --------------------------------
	if ( iRv >= 0 )
	{
		if ( m_eOperation == OperationModify )
		{
			CdDedJikan	aCdDedJikan( m_iSeconds * 60 ) ;
			aCentDedRessya.modifyRessyaJikoku( 
				aCdDedJikan , 
				aJikokuOrder ) ;
		}
		else if ( m_eOperation == OperationCopy )
		{
			CdDedJikoku aCdDedJikokuSrc = 
				aCentDedRessya.getEkiJikoku( m_iJikokuOrderCopySrc ) ;
			CdDedJikoku aCdDedJikokuDst = 
				aCentDedRessya.getEkiJikoku( aJikokuOrder ) ;

			//	時刻は、単純に代入します。
			{
				CentDedEkiJikoku aCentDedEkiJikoku = 
					aCentDedRessya.getCentDedEkiJikoku( aJikokuOrder.getEkiOrder() ) ;
				aCdDedJikokuSrc.addSeconds( m_iSeconds * 60 ) ;
				if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku)
				{
					aCentDedEkiJikoku.setChakujikoku( aCdDedJikokuSrc ) ;
				}
				else
				{
					aCentDedEkiJikoku.setHatsujikoku( aCdDedJikokuSrc ) ;
				}
				aCentDedRessya.setCentDedEkiJikoku( 
					aJikokuOrder.getEkiOrder() , aCentDedEkiJikoku  ) ;
			}
		}
		else if ( m_eOperation == OperationToNull )
		{
			//	NULL を設定
			aCentDedRessya.setEkiJikoku( CdDedJikoku()  , aJikokuOrder ) ;
		}
	}
	//aCentDedRessya = 駅時刻が変更されました。



	


	// --------------------------------
	//	駅扱・着時刻・発時刻を変更
	// --------------------------------
	if ( iRv >= 0 )
	{
		*pCentDedRessya = aCentDedRessya ;
	}	
	return ( iRv ) ;
}
