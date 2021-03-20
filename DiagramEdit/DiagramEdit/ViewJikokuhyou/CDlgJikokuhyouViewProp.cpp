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
// CDlgJikokuhyouViewProp.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"

#include "str/tstring.h"
#include "str/strToWstr.h"
#include "str/CStrCharSizeMb.h"

#include "..\DiagramEdit.h"
#include "CDlgJikokuhyouViewProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

/////////////////////////////////////////////////////////////////////////////
// CDlgJikokuhyouViewProp ダイアログ


CDlgJikokuhyouViewProp::CDlgJikokuhyouViewProp(
		const CdDedJikan& jikanPasteIdouryou , 
		enum CWndJikokuhyou::EEkijikokuSort eEkijikokuSort ,
		CWnd* pParent )
	: CDialog(CDlgJikokuhyouViewProp::IDD, pParent)
	, m_jikanPasteIdouryou( jikanPasteIdouryou ) 
	, m_eEkijikokuSort( eEkijikokuSort ) 
	, m_iEDIT_PasteZoubun(0)
	, m_iRADIO_EKIJIKOKUSORT(0)
{
	//{{AFX_DATA_INIT(CDlgJikokuhyouViewProp)
	//}}AFX_DATA_INIT

	m_iEDIT_PasteZoubun = jikanPasteIdouryou.getTotalSeconds() / 60 ;
	m_iRADIO_EKIJIKOKUSORT = (int)m_eEkijikokuSort ;
}


void CDlgJikokuhyouViewProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgJikokuhyouViewProp)
	DDX_Text(pDX, IDC_EDIT_PasteZoubun, m_iEDIT_PasteZoubun);
	//}}AFX_DATA_MAP
	DDX_Radio(pDX, IDC_RADIO_EKIJIKOUSORT_0, m_iRADIO_EKIJIKOKUSORT);
}


BEGIN_MESSAGE_MAP(CDlgJikokuhyouViewProp, CDialog)
	//{{AFX_MSG_MAP(CDlgJikokuhyouViewProp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgJikokuhyouViewProp メッセージ ハンドラ

void CDlgJikokuhyouViewProp::OnOK() 
{
	int iRv = 0 ;
	// --------------------------------
	//	UpdateData()の前処理
	// --------------------------------
	//IDC_EDIT_PasteZoubun 
	{
		//	空文字列なら、0を補います。
		CWnd* pCWnd = GetDlgItem( IDC_EDIT_PasteZoubun ) ;
		CString	strLs ;
		pCWnd->GetWindowText( strLs ) ;
		strLs = tstringOf( 
			CStrCharSizeMb::strToSingleByte( (LPCTSTR)strLs ) ).c_str();
		if ( strLs.IsEmpty() )
		{
			strLs = _T( "0" ) ;
		}
		pCWnd->SetWindowText( strLs ) ;
	}

	if ( !UpdateData() )
	{
		iRv = -1 ;	//	UpdateData()に失敗しました。(エラー表示済み)
	}
	
	// --------------------------------
	//	コントロールの値を取り込み
	// --------------------------------
	if ( iRv >= 0 )
	{
		m_jikanPasteIdouryou = m_iEDIT_PasteZoubun * 60 ;	
		{
			switch( m_iRADIO_EKIJIKOKUSORT )
			{
			case 0:
				m_eEkijikokuSort = CWndJikokuhyou::EEkijikokuSort_Ekiatsukai ;
				break ;
			case 1:
				m_eEkijikokuSort = CWndJikokuhyou::EEkijikokuSort_Transfer ;
				break ;
			}
		}
	}

	// --------------------------------
	if ( iRv >= 0 )
	{
		//	エラーがなければダイアログを終了
		CDialog::OnOK();
	}
	else
	{
		CString strErrorMsg ;
		switch( iRv )
		{
		case -1:	//	UpdateData()に失敗しました。(エラー表示済み)
			//	この場合は、エラーメッセージは表示しません。
			break ;
		default:
			strErrorMsg.Format( _T( "Error=%d" ) , iRv ) ;
			break ;
		}
		if ( strErrorMsg.GetLength() > 0 )
		{
			MessageBox( strErrorMsg , NULL , MB_ICONERROR ) ; 
		}
	}
}
} //namespace ViewJikokuhyou
