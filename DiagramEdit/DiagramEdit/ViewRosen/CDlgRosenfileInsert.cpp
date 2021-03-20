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
// CDlgRosenfileInsert.cpp : 実装ファイル
//

#include "stdafx.h"
#include "..\DiagramEdit.h"
#include "CDlgRosenfileInsert.h"

namespace ViewRosen{

// CDlgRosenfileInsert ダイアログ

IMPLEMENT_DYNAMIC(CDlgRosenfileInsert, CDialog)

CDlgRosenfileInsert::CDlgRosenfileInsert(
		const CentDedEkiCont& aCentDedEkiCont ,
		CWnd* pParent )   // 標準コンストラクタ
	: CDialog(CDlgRosenfileInsert::IDD, pParent)
	, m_CentDedEkiCont( aCentDedEkiCont ) 
	, m_strEDIT_ADD_ROSENFILENAME(_T(""))
	, m_iCOMBO_EKIINDEX_TO_ADD( 0 )
{

}

CDlgRosenfileInsert::~CDlgRosenfileInsert()
{
}

void CDlgRosenfileInsert::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADD_ROSENFILENAME, m_strEDIT_ADD_ROSENFILENAME);
	DDX_CBIndex(pDX, IDC_COMBO_EKIINDEX_TO_ADD, m_iCOMBO_EKIINDEX_TO_ADD);
	DDX_Control(pDX, IDC_COMBO_EKIINDEX_TO_ADD, m_wndCOMBO_EKIINDEX_TO_ADD);
}


BEGIN_MESSAGE_MAP(CDlgRosenfileInsert, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD_ROSENFILENAME, &CDlgRosenfileInsert::OnBnClickedButtonAddRosenfilename)
END_MESSAGE_MAP()


// CDlgRosenfileInsert メッセージ ハンドラ

void CDlgRosenfileInsert::OnBnClickedButtonAddRosenfilename()
{
	CString strFilename ;
	CEdit* pCEdit = (CEdit*)GetDlgItem( IDC_EDIT_ADD_ROSENFILENAME ) ;
	pCEdit->GetWindowText( strFilename ) ;

	CString	strExt ;
	getCDiagramEditApp()->pRootDoctmpl()->GetDocString( strExt , CDocTemplate::filterExt ) ;
	CFileDialog	aDlg( TRUE , strExt ,
		strFilename , 
		OFN_FILEMUSTEXIST,
		getCDiagramEditApp()->getCFileDialogOudFilter() , 
		this ) ;
	if ( aDlg.DoModal() == IDOK )
	{
		pCEdit->SetWindowText( aDlg.GetPathName() ) ;
	}
}

BOOL CDlgRosenfileInsert::OnInitDialog()
{
	CDialog::OnInitDialog();


	//COMBO_EKIINDEX_TO_ADD
	{
		for ( int iEkiIndex = 0 ; iEkiIndex < m_CentDedEkiCont.size() ; iEkiIndex ++ )
		{
			m_wndCOMBO_EKIINDEX_TO_ADD.AddString( 
				tstring( m_CentDedEkiCont.getMuPtr()->get( iEkiIndex )->getEkimei() ).c_str() ) ;
		}
		m_wndCOMBO_EKIINDEX_TO_ADD.SetCurSel( m_CentDedEkiCont.size() - 1 ) ;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 例外 : OCX プロパティ ページは必ず FALSE を返します。
}

void CDlgRosenfileInsert::OnOK()
{
	UpdateData( TRUE ) ;
	int iRv = 0 ;
	// --------------------------------
	if ( iRv >= 0 )
	{
		if ( !( 0 <= m_iCOMBO_EKIINDEX_TO_ADD && 
			m_iCOMBO_EKIINDEX_TO_ADD < m_CentDedEkiCont.size() ) )
		{
			iRv = -11 ;	//	駅Indexが選択されていません。
		}
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		m_strOudFilenameToInsert = m_strEDIT_ADD_ROSENFILENAME ;
		m_iEkiIndexToInsert = m_iCOMBO_EKIINDEX_TO_ADD ;

		CDialog::OnOK();
	}
	else
	{
		CString	strErrorMsg ; 
		switch( iRv )
		{
		case -11:
			GetDlgItem( IDC_STATIC_ERR_EKIINDEX_NOT_SELECTED )->GetWindowText( strErrorMsg ) ;
			break ;
		default:
			strErrorMsg.Format( _T( "Error(%d)" ) , iRv ) ;
		}
		if ( !strErrorMsg.IsEmpty() )
		{
			MessageBox( strErrorMsg , NULL , MB_ICONSTOP ) ;
		}
	}
}
} //namespace ViewRosen
