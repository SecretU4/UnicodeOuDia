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
// ViewRosen\CDlgRosenCreateSubRosen.cpp : 実装ファイル
//

#include "stdafx.h"

#include "str\strToWstr.h"
#include "str\tstring.h"

#include "..\DiagramEdit.h"
#include "CDlgRosenCreateSubRosen.h"

namespace ViewRosen{
using namespace OuLib ;

// CDlgRosenCreateSubRosen ダイアログ

IMPLEMENT_DYNAMIC(CDlgRosenCreateSubRosen, CDialog)

CDlgRosenCreateSubRosen::CDlgRosenCreateSubRosen(
	const CentDedEkiCont&	aCentDedEkiCont , 
	CWnd* pParent )
	: CDialog(CDlgRosenCreateSubRosen::IDD, pParent)
{
	const Mu<const CentDedEki*>* muCentDedEki = aCentDedEkiCont.getMuPtr() ;
	for ( int iEkiIndex = 0 ; iEkiIndex < muCentDedEki->size() ; iEkiIndex ++ )
	{
		m_arstrEkimei.push_back( muCentDedEki->get( iEkiIndex )->getEkimei() ) ;
	}
}

CDlgRosenCreateSubRosen::~CDlgRosenCreateSubRosen()
{
}

void CDlgRosenCreateSubRosen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SIHATSU_EKIINDEX, m_wndCOMBO_SIHATSU_EKIINDEX);
	DDX_Control(pDX, IDC_COMBO_SYUUCHAKU_EKIINDEX, m_wndCOMBO_SYUUCHAKU_EKIINDEX);
}


BEGIN_MESSAGE_MAP(CDlgRosenCreateSubRosen, CDialog)
END_MESSAGE_MAP()


// CDlgRosenCreateSubRosen メッセージ ハンドラ

BOOL CDlgRosenCreateSubRosen::OnInitDialog()
{
	CDialog::OnInitDialog();

	int iRv = 0 ;

	//IDC_COMBO_SIHATSU_EKIINDEX
	//IDC_COMBO_SYUUCHAKU_EKIINDEX
	if ( iRv >= 0 )
	{
		if ( m_arstrEkimei.size() < 3 )
		{
			iRv = -11 ;	//	3駅未満の路線では使用できません。
		}
		else
		{
			for ( int iEkiIndex = 0 ; iEkiIndex < (int)m_arstrEkimei.size() ; iEkiIndex ++ )
			{
				m_wndCOMBO_SIHATSU_EKIINDEX.AddString( 
					tstringOf( m_arstrEkimei[ iEkiIndex ] ).c_str() ) ;
				m_wndCOMBO_SYUUCHAKU_EKIINDEX.AddString( 
					tstringOf( m_arstrEkimei[ iEkiIndex ] ).c_str() ) ;
			}
			m_wndCOMBO_SIHATSU_EKIINDEX.SetCurSel( 0 ) ;
			m_wndCOMBO_SYUUCHAKU_EKIINDEX.SetCurSel( m_wndCOMBO_SYUUCHAKU_EKIINDEX.GetCount() - 1 ) ;
		}
	}
	// --------------------------------
	CString strErrorMsg ;
	if ( iRv < 0 )
	{
		switch( iRv )
		{
		case -11 :	//	3駅未満の路線では使用できません。
			GetDlgItem( IDC_ERR_EKI_TOO_FEW )->GetWindowText( strErrorMsg ) ;
			break ;
		default:
			strErrorMsg.Format( _T( "Error (%d)" ) , iRv ) ;
			break ;
		}
	}
	if ( !strErrorMsg.IsEmpty() )
	{
		MessageBox( strErrorMsg , NULL , MB_ICONSTOP );
		EndDialog( IDCANCEL ) ;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 例外 : OCX プロパティ ページは必ず FALSE を返します。
}

void CDlgRosenCreateSubRosen::OnOK()
{
	int iRv = 0 ;
	if ( iRv >= 0 )
	{
		m_iSihatsuEkiIndex = m_wndCOMBO_SIHATSU_EKIINDEX.GetCurSel() ;
		if ( m_iSihatsuEkiIndex < 0 )
		{
			m_iSihatsuEkiIndex = 0 ;
		}
		m_iSyuuchakuEkiIndex = m_wndCOMBO_SYUUCHAKU_EKIINDEX.GetCurSel() ;
		if ( m_iSyuuchakuEkiIndex < 0 )
		{
			m_iSyuuchakuEkiIndex = m_wndCOMBO_SYUUCHAKU_EKIINDEX.GetCount() - 1 ;
		}
		if ( !( m_iSihatsuEkiIndex < m_iSyuuchakuEkiIndex ) )
		{
			iRv = -12 ;	//	始発駅より終着駅を後にしてください。
		}
	}
	// --------------------------------
	if ( iRv < 0 )
	{
		CString strErrorMsg ;
		switch( iRv )
		{
		case -12 :	//	3駅未満の路線では使用できません。
			GetDlgItem( IDC_ERR_EKIINDEX_ORDER )->GetWindowText( strErrorMsg ) ;
			break ;
		default:
			strErrorMsg.Format( _T( "Error (%d)" ) , iRv ) ;
			break ;
		}
		if ( !strErrorMsg.IsEmpty() )
		{
			MessageBox( strErrorMsg , NULL , MB_ICONSTOP );
		}
	}
	else
	{
		CDialog::OnOK();
	}
}
} //namespace ViewRosen
