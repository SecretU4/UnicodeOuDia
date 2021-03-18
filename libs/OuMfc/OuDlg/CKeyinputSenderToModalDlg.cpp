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
//	CKeyinputSenderToModalDlg.cpp
// ****************************************************************
*/
#include "CKeyinputSenderToModalDlg.h"

namespace OuMfc{
namespace OuDlg{

// ****************************************************************
//	CKeyinputSenderToModalDlg
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CKeyinputSenderToModalDlg::CKeyinputSenderToModalDlg() :
		m_hwndControl( NULL ) ,
		m_bIsSend( false ) 
{
}

// ********************************
//	CKeyinputSenderToModalDlg
// ********************************
	// ********************************
	//@name 『転送元ウインドウ』からの操作
	// ********************************
bool CKeyinputSenderToModalDlg::
	OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	bool bRv = false ;
	if ( m_bIsSend ){
		bRv = true ;
		MsgToPost	aMsg ;
		aMsg.Msg = WM_KEYDOWN ;
		aMsg.wParam = nChar ;
		aMsg.lParam = MAKELONG( nRepCnt , nFlags )  ;
		if ( m_hwndControl == NULL ){
			m_contmsgToSend.push_back( aMsg ) ;
		}	else	{
			PostMessage( m_hwndControl , aMsg.Msg , aMsg.wParam , 
				aMsg.lParam ) ;
		}
	}
	return bRv ;
}

bool CKeyinputSenderToModalDlg::
	OnKeyUp( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	bool bRv = false ;
	if ( m_bIsSend ){
		bRv = true ;
		MsgToPost	aMsg ;
		aMsg.Msg = WM_KEYUP ;
		aMsg.wParam = nChar ;
		aMsg.lParam = MAKELONG( nRepCnt , nFlags )  ;
		if ( m_hwndControl == NULL ){
			m_contmsgToSend.push_back( aMsg ) ;
		}	else	{
			PostMessage( m_hwndControl , aMsg.Msg , aMsg.wParam , 
				aMsg.lParam ) ;
		}
	}
	return bRv ;
}


int CKeyinputSenderToModalDlg::startSend() 
{
	int iRv = 0 ;
	if ( iRv >=0 ){
		if ( m_bIsSend ){
			iRv = -1 ;	//	すでに転送中です。
		}
	}
	if ( iRv >=0 ){
		m_bIsSend = true ;
	}
	return ( iRv ) ;
}

void CKeyinputSenderToModalDlg::endSend() 
{
	m_bIsSend = false ;
	m_hwndControl = NULL ;
	m_contmsgToSend.clear() ;
}
	// ********************************
	//@name 『転送先ダイアログ』からの操作
	// ********************************
int CKeyinputSenderToModalDlg::registerCtrl( HWND hwndControl ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( m_bIsSend && m_hwndControl == NULL ) ){
			//	送信中でないか、すでに『転送先コントロール』が
			//	登録済みです
			iRv = -1 ;
		}
	}
	if ( iRv >= 0 ){
		m_hwndControl = hwndControl ;
		while ( m_contmsgToSend.size() > 0 ){
			MsgToPost	aMsg = m_contmsgToSend.front() ;
			m_contmsgToSend.pop_front() ;
			PostMessage( m_hwndControl , aMsg.Msg , aMsg.wParam , 
				aMsg.lParam ) ;
		}
	}
	return ( iRv ) ;
}
void CKeyinputSenderToModalDlg::unregisterCtrl() 
{
	m_hwndControl = NULL ;
}
	// ********************************
	//@name 操作
	// ********************************
bool CKeyinputSenderToModalDlg::isSend() 
{
	return ( m_bIsSend ) ;
}
HWND CKeyinputSenderToModalDlg::getControl() 
{
	return ( m_hwndControl ) ;
}

	// ********************************
	///@name 
	// ********************************
bool CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown()
{
	//	アクセラレータキーによる
	//	メニューコマンド起動を妨害しないように、
	//	ALTキーやCTRLキーが押されているときは、
	//	ダイアログ起動を避けています。
	//	ただし、実際にはアクセラレータキーの機構は
	//	ウインドウの OnKeyDown() よりも優先されるため、
	//	この判定は厳密には必要ありません。

	//ALT
	{
		SHORT	iResult = GetKeyState( VK_MENU ) ;
		if ( iResult < 0 ){
			return false ;
		}
	}
	//CTRL
	{
		SHORT	iResult = GetKeyState( VK_CONTROL ) ;
		if ( iResult < 0 ){
			return false ;
		}
	}

	// --------------------------------
	int iCount = 0 ;
	//	アルファベットキー上の数字
	int iKeycode ;
	for ( iKeycode = '0' ; iKeycode <= '9' ; iKeycode ++ ){
		SHORT	iResult = GetKeyState( iKeycode ) ;
		if ( iResult < 0 ){
			iCount ++ ;
		}
	}
	//	アルファベットキー(大文字・小文字いずれの場合も、
	//	こちらの条件に該当します)
	for ( iKeycode = 'A' ; iKeycode <= 'Z' ; iKeycode ++ ){
		SHORT	iResult = GetKeyState( iKeycode ) ;
		if ( iResult < 0 ){
			iCount ++ ;
		}
	}
	//	テンキーは 0x60～0x69までです
	for ( iKeycode = 0x60 ; iKeycode <= 0x69 ; iKeycode ++ ){
		SHORT	iResult = GetKeyState( iKeycode ) ;
		if ( iResult < 0 ){
			iCount ++ ;
		}
	}

	return ( iCount == 1 );
}

} //namespace OuDlg
} //namespace OuMfc
