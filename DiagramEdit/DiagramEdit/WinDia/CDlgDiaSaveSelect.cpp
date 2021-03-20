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
// CDlgDiaSaveSelect.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"

#include "NsMu/CaMui.h"

#include "..\diagramedit.h"
#include "CDlgDiaSaveSelect.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace WinDia{ 
using namespace std ;

/////////////////////////////////////////////////////////////////////////////
// CDlgDiaSaveSelect ダイアログ


CDlgDiaSaveSelect::CDlgDiaSaveSelect(
		const Mu< string >& contstrDia , 	
		CWnd* pParent )
	: CDialog(CDlgDiaSaveSelect::IDD, pParent),
	m_iDiaIndex( -1 ) 
{
	CaMui<string>( &m_contstrDia ).insert( &contstrDia ) ;
	//{{AFX_DATA_INIT(CDlgDiaSaveSelect)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
	
}


void CDlgDiaSaveSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDiaSaveSelect)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDiaSaveSelect, CDialog)
	//{{AFX_MSG_MAP(CDlgDiaSaveSelect)
	ON_LBN_SELCHANGE(IDC_LIST_Dia, OnSelchangeLISTDia)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDiaSaveSelect メッセージ ハンドラ

BOOL CDlgDiaSaveSelect::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	{
		CListBox* pCListBox = (CListBox*)GetDlgItem( IDC_LIST_Dia ) ;
		for ( int idx = 0 ; idx < m_contstrDia.size() ; idx ++ ){
			pCListBox->AddString( m_contstrDia.get( idx ).c_str() ) ;
		}
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgDiaSaveSelect::OnOK() 
{
	{
		CListBox* pCListBox = (CListBox*)GetDlgItem( IDC_LIST_Dia ) ;
		m_iDiaIndex = pCListBox->GetCurSel( ) ;
	}
	
	CDialog::OnOK();
}

void CDlgDiaSaveSelect::OnSelchangeLISTDia() 
{
	{
		CListBox* pCListBox = (CListBox*)GetDlgItem( IDC_LIST_Dia ) ;
		m_iDiaIndex = pCListBox->GetCurSel( ) ;
		GetDlgItem( IDOK )->EnableWindow( m_iDiaIndex >= 0 ) ;
	}

	
}
} //namespace WinDia
