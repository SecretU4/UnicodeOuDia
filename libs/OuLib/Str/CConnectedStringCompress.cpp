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
//	CConnectedStringCompress.cpp
// ****************************************************************
*/
#include "CConnectedStringCompress.h"

#include <deque>
#include "str/stringSplit.h"


namespace OuLib {
namespace Str {

using namespace std ;

// ****************************************************************
//	CConnectedStringCompress
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CConnectedStringCompress::CConnectedStringCompress( 
	char chSubitemSeparater ) :
	m_chSubitemSeparater( chSubitemSeparater ) 
{
}
CConnectedStringCompress::~CConnectedStringCompress()
{
}
// ********************************
//	CConnectedStringCompress
// ********************************
	// ********************************
	//@name CConnectedStringCompress-属性
	// ********************************
char CConnectedStringCompress::getSubitemSeparater()const 
{
	return m_chSubitemSeparater ;
}
CConnectedStringCompress& 
CConnectedStringCompress::setSubitemSeparater( char value ) 
{
	m_chSubitemSeparater = value ;
	return *this ;
}

	// ********************************
	//@name CConnectedStringCompress-操作
	// ********************************
string CConnectedStringCompress::encode( 
	const CdConnectedString2& aCdConnectedString2 ) 
{
	CdConnectedString2	connectstrOut( aCdConnectedString2.getSplit() , 
		aCdConnectedString2.getEqualChar() ) ;

	deque<string>	contstrCurrentSubItem ;
	int iItem ;
	for ( iItem = 0 ; iItem < aCdConnectedString2.size() ; iItem ++ ){
		CdConnectedString2::CdItem	aCdItem = aCdConnectedString2.at( iItem ) ;
		if ( aCdItem.getValue().empty() && 
				!aCdConnectedString2.getEncodeNoValue() ){
			continue ;
		}
		// --------------------------------
		//	『カレントサブアイテム』を移動
		// --------------------------------
		deque<string> contstrSubItem = splitc< deque< string > >( 
			m_chSubitemSeparater , aCdItem.getName() ) ;
		string strName = contstrSubItem.back() ;
		contstrSubItem.pop_back() ;

		while( 1 ){
			int iEquals ;
			for ( iEquals = 0 ; 
				iEquals < (int)contstrCurrentSubItem.size() && 
				iEquals < (int)contstrSubItem.size() && 
				contstrCurrentSubItem[iEquals] == contstrSubItem[iEquals] ;
				iEquals ++ ){
			}
			//iEquals = contstrCurrentSubItem と 
			//	contstrSubItem のうち、先頭側の等しい要素数
			
			if ( iEquals == contstrCurrentSubItem.size() && 
				iEquals == contstrSubItem.size() ){
				break ;
			}
			// --------------------------------
			if ( iEquals == (int)contstrCurrentSubItem.size() && 
				iEquals < (int)contstrSubItem.size() ){
				//	『カレントサブアイテム入場コマンド』
				connectstrOut.insert( 
					CdConnectedString2::CdItem( contstrSubItem[ iEquals ] + 
						m_chSubitemSeparater , "" ) ) ;
				contstrCurrentSubItem.push_back( contstrSubItem[ iEquals ] ) ;
			}	else	{
				//	『カレントサブアイテム退場コマンド』
				connectstrOut.insert( 
					CdConnectedString2::CdItem( 
						string( 1 , m_chSubitemSeparater ) , "" ) ) ;
				contstrCurrentSubItem.pop_back() ;
			}

		}
		// --------------------------------
		//	『アイテム』を出力
		// --------------------------------
		connectstrOut.insert( 
			CdConnectedString2::CdItem( 
						strName , aCdItem.getValue() ) ) ;
		

	}
	// --------------------------------
	//	最後に、カレントサブアイテムを
	//	""とします
	// --------------------------------
	while( contstrCurrentSubItem.size() > 0 ){
				//	『カレントサブアイテム退場コマンド』
				connectstrOut.insert( 
					CdConnectedString2::CdItem( 
						string( 1 , m_chSubitemSeparater ) , "" ) ) ;
				contstrCurrentSubItem.pop_back() ;
	}
	return connectstrOut.encode() ;

}

int CConnectedStringCompress::decode( const string& aStr , 
		CdConnectedString2* pCdConnectedString2 ) 
{
	int iRv = 0 ;
	CdConnectedString2	connectstrIn( pCdConnectedString2->getSplit() , 
		pCdConnectedString2->getEqualChar() ) ;
	connectstrIn.decode( aStr ) ;

	deque<string>	contstrCurrentSubItem ;
	int iItem ;
	for ( iItem = 0 ; iRv >= 0 && iItem < connectstrIn.size() ; iItem ++ ){
		CdConnectedString2::CdItem	aCdItem = connectstrIn.at( iItem ) ;
		string strName = aCdItem.getName() ;

		if ( strName == string( 1 , m_chSubitemSeparater ) ){
			//	『カレントサブアイテム退場コマンド』
			if ( contstrCurrentSubItem.size() == 0 ){
				iRv = -1 ;	
				//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。
			}	else	{
				contstrCurrentSubItem.pop_back() ;
			}

		}	else if ( strName.size() > 1 && 
			strName[ strName.size() - 1 ] == m_chSubitemSeparater ){
			//	『カレントサブアイテム入場コマンド』
			contstrCurrentSubItem.push_back( 
				strName.substr( 0 , strName.size() - 1 ) ) ;
		}	else	{
			string strName = joinc< deque< string > >( 
				m_chSubitemSeparater , contstrCurrentSubItem ) ;
			if ( strName.size() > 0 ){
				strName += 	m_chSubitemSeparater ;
			}
			strName += aCdItem.getName() ;

			pCdConnectedString2->insert( CdConnectedString2::CdItem(
				strName , aCdItem.getValue() ) ) ;
		}


	}

	return ( iRv ) ;
}

} //namespace Str {
} //namespace OuLib {
