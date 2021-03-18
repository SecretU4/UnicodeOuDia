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
// CDlgEkijikokuProp.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"

#include "str\CStrCharSizeMb.h"
#include "str\strLf.h"
#include "LogMsg\LogMsg.h"

#include "..\DiagramEdit.h"
#include "CDlgEkijikokuProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

using namespace std ;


// ================================================================
//	CDlgEkijikokuProp::CPropEditUiInternal
// ================================================================

void CDlgEkijikokuProp::CPropEditUiInternal::UiDataToUi( const UIDATA* pUiData ) 
{
	CDlgEkijikokuProp* pOuter = (CDlgEkijikokuProp*)( (BYTE*)this - offsetof( CDlgEkijikokuProp , m_PropEditUiInternal ) ) ;

	// --------------------------------
	//	DDXを用いた、UiControlへの設定
	// --------------------------------
	{
		//IDC_RADIO_Ekiatsukai
		{
			pOuter->m_iRADIO_Ekiatsukai = pUiData->iEkiatsukai ;
		}

		// --------------------------------
		pOuter->UpdateData( FALSE ) ;
	}
	// --------------------------------
	//	DDXを用いない、UiControlへの設定
	//	これらは、DDXによる値設定の後で
	//	行わなくてはなりません。
	// --------------------------------
	//IDC_EDIT_Chakujikoku
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Chakujikoku ) ) ;
		pControl->SetWindowText( pUiData->strChakujikoku.c_str() ) ;
		pControl->EnableWindow( pUiData->bChakujikokuIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
	//IDC_EDIT_Hatsujikoku
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Hatsujikoku ) ) ;
		pControl->SetWindowText( pUiData->strHatsujikoku.c_str() ) ;
		pControl->EnableWindow( pUiData->bHatsujikokuIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
	//IDC_CHECK_MODIFYHATSUJIKOKU
	{
		CButton* pControl = (CButton*)( pOuter->GetDlgItem( IDC_CHECK_MODIFYHATSUJIKOKU ) ) ;
		pControl->SetCheck( pUiData->bModifyHatsujikoku ? BST_CHECKED : BST_UNCHECKED ) ; 
	}

}
void  CDlgEkijikokuProp::CPropEditUiInternal::UiDataFromUi( UIDATA* pUiData )  
{
	int iRv = 0 ; 
	CDlgEkijikokuProp* pOuter = (CDlgEkijikokuProp*)( (BYTE*)this - offsetof( CDlgEkijikokuProp , m_PropEditUiInternal ) ) ;

	if ( iRv >= 0 )
	{
		if ( !pOuter->UpdateData( TRUE ) )
		{
			iRv = -1 ;	//	入力エラーあり
		}
	}

	if ( iRv >= 0 )
	{
		//IDC_RADIO_Ekiatsukai
		{
			pUiData->iEkiatsukai = pOuter->m_iRADIO_Ekiatsukai ;
		}
		//IDC_EDIT_Chakujikoku
		{
			CString strText ;
			CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Chakujikoku ) ) ;
			pControl->GetWindowText( strText ) ;
			pUiData->strChakujikoku = (LPCTSTR)strText ;
		}
		//IDC_EDIT_Hatsujikoku
		{
			CString strText ;
			CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Hatsujikoku ) ) ;
			pControl->GetWindowText( strText ) ;
			pUiData->strHatsujikoku = (LPCTSTR)strText ;
		}
		//IDC_CHECK_MODIFYHATSUJIKOKU
		{
			CButton* pControl = (CButton*)( pOuter->GetDlgItem( IDC_CHECK_MODIFYHATSUJIKOKU ) ) ;
			pUiData->bModifyHatsujikoku = ( pControl->GetCheck() == BST_CHECKED ) ; 
		}
	}	
}

void CDlgEkijikokuProp::CPropEditUiInternal::SetFocus( int iOffsetofUiDataMember ) 
{
	CDlgEkijikokuProp* pOuter = (CDlgEkijikokuProp*)( (BYTE*)this - offsetof( CDlgEkijikokuProp , m_PropEditUiInternal ) ) ;
	CWnd* pControl = NULL ;

	//IDC_RADIO_Ekiatsukai
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iEkiatsukai ) )
		{
			pControl = pOuter->GetDlgItem( IDC_RADIO_Ekiatsukai ) ;
		}
	}
	//IDC_EDIT_Chakujikoku
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , strChakujikoku ) )
		{
			pControl = pOuter->GetDlgItem( IDC_EDIT_Chakujikoku )  ;
		}
	}
	//IDC_EDIT_Hatsujikoku
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , strHatsujikoku ) )
		{
			pControl = pOuter->GetDlgItem( IDC_EDIT_Hatsujikoku )  ;
		}
	}
	//IDC_CHECK_MODIFYHATSUJIKOKU
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , bModifyHatsujikoku ) )
		{
			pControl = pOuter->GetDlgItem( IDC_CHECK_MODIFYHATSUJIKOKU ) ;
		}

	}

	if ( pControl != NULL )
	{
		pOuter->GotoDlgCtrl( pControl ) ; 
	}
}
		
void CDlgEkijikokuProp::CPropEditUiInternal::ShowError( 
			const std::string& strErrorReason ,
			const std::string& strInfo )  
{
	CDlgEkijikokuProp* pOuter = (CDlgEkijikokuProp*)( (BYTE*)this - offsetof( CDlgEkijikokuProp , m_PropEditUiInternal ) ) ;
	CString strErrorMsg = strErrorReason.c_str() ;

	if ( strErrorReason == ERRMSG_INVALID_CHAKUJIKOKU )
	{
		pOuter->GetDlgItem( IDC_ERROR_ChakujikokuFormat )->GetWindowText( strErrorMsg )  ;
	}
	else if ( strErrorReason == ERRMSG_INVALID_HATSUJIKOKU )
	{
		pOuter->GetDlgItem( IDC_ERROR_HatsujikokuFormat )->GetWindowText( strErrorMsg )  ;
	}
	pOuter->MessageBox( strErrorMsg , NULL , MB_OK | MB_ICONEXCLAMATION ) ;
}
		// ********************************
		//	コンストラクタ
		// ********************************
CDlgEkijikokuProp::CPropEditUiInternal::CPropEditUiInternal( 
			bool bNewItem , 
			Mu<CentDedRessya*>* pTarget , 
			bool* pbModifyHatsujikoku ,
			int iEkiOrder ) 
	: CPropEditUi_EkiJikoku( 
			bNewItem , pTarget , 
			pbModifyHatsujikoku ,
			iEkiOrder ) 
{
}


/////////////////////////////////////////////////////////////////////////////
// CDlgEkijikokuProp ダイアログ


// ----------------------------------------------------------------
CDlgEkijikokuProp::CDlgEkijikokuProp(
		Mu<CentDedRessya*>* pMuRessya ,
		bool* pbJikokuModify ,
		int iEkiOrder ,
		int iFocusItem ,
		CKeyinputSenderToModalDlg*	pCKeyinputSenderToModalDlg ,
		CWnd* pParent  ) 
	: CDialog(CDlgEkijikokuProp::IDD, pParent)
	, m_PropEditUiInternal( false , pMuRessya , pbJikokuModify , iEkiOrder )
	, m_iFocusItem( iFocusItem )
	, m_pCKeyinputSenderToModalDlg( pCKeyinputSenderToModalDlg )
	, m_bCHECK_MODIFYHATSUJIKOKU(FALSE)
{
	//{{AFX_DATA_INIT(CDlgEkijikokuProp)
	m_iRADIO_Ekiatsukai = -1;
	//}}AFX_DATA_INIT
}


void CDlgEkijikokuProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEkijikokuProp)
	DDX_Radio(pDX, IDC_RADIO_Ekiatsukai, m_iRADIO_Ekiatsukai);
	//}}AFX_DATA_MAP
	DDX_Check(pDX, IDC_CHECK_MODIFYHATSUJIKOKU, m_bCHECK_MODIFYHATSUJIKOKU);
}


BEGIN_MESSAGE_MAP(CDlgEkijikokuProp, CDialog)
	//{{AFX_MSG_MAP(CDlgEkijikokuProp)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_RADIO_Ekiatsukai, OnRADIOEkiatsukai)
	ON_BN_CLICKED(IDC_RADIO_Ekiatsukai2, OnRADIOEkiatsukai2)
	ON_BN_CLICKED(IDC_RADIO_Ekiatsukai3, OnRADIOEkiatsukai3)
	ON_BN_CLICKED(IDC_RADIO_Ekiatsukai4, OnRADIOEkiatsukai4)
	ON_EN_KILLFOCUS(IDC_EDIT_Chakujikoku, OnKillfocusEDITChakujikoku)
	ON_EN_KILLFOCUS(IDC_EDIT_Hatsujikoku, OnKillfocusEDITHatsujikoku)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CHECK_MODIFYHATSUJIKOKU, &CDlgEkijikokuProp::OnBnClickedCheckModifyhatsujikoku)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEkijikokuProp メッセージ ハンドラ

BOOL CDlgEkijikokuProp::OnInitDialog() 
{
	LogMsg( "CDlgEkijikokuProp::OnInitDialog()" ) ;

	CDialog::OnInitDialog();
	LogMsg( "CDlgEkijikokuProp::OnInitDialog()1 " ) ;
	
	m_PropEditUiInternal.StartEdit() ;

	LogMsg( "CDlgEkijikokuProp::OnInitDialog()= " ) ;
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgEkijikokuProp::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	LogMsg( "CDlgEkijikokuProp::OnShowWindow() " ) ;
	CDialog::OnShowWindow(bShow, nStatus);
	LogMsg( "CDlgEkijikokuProp::OnShowWindow()1 " ) ;
	
	if ( bShow ){
		CWnd* pControl = NULL ;
		switch( m_iFocusItem ){
		 case 0	:	//	駅扱
			pControl = GetDlgItem( IDC_RADIO_Ekiatsukai ) ;
			break ;
		 case 1	:	//	着時刻
			pControl = GetDlgItem( IDC_EDIT_Chakujikoku ) ;
			break ;
		 case 2	:	//	発時刻
			pControl = GetDlgItem( IDC_EDIT_Hatsujikoku ) ;
			break ;
		}
		if ( pControl != NULL ){
			GotoDlgCtrl( pControl ) ;
			if ( m_pCKeyinputSenderToModalDlg != NULL ){
				m_pCKeyinputSenderToModalDlg->registerCtrl( 
					pControl->GetSafeHwnd() ) ;
			}
		}
	}
	LogMsg( "CDlgEkijikokuProp::OnShowWindow()= " ) ;
	
	
}

void CDlgEkijikokuProp::OnOK() 
{
	int iRv = 0 ;

	int iResult = m_PropEditUiInternal.EndEdit() ;
	if ( iResult >= 0 )
	{
		CDialog::OnOK();
	}
}


void CDlgEkijikokuProp::OnRADIOEkiatsukai() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgEkijikokuProp::OnRADIOEkiatsukai2() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgEkijikokuProp::OnRADIOEkiatsukai3() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgEkijikokuProp::OnRADIOEkiatsukai4() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgEkijikokuProp::OnKillfocusEDITChakujikoku() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgEkijikokuProp::OnKillfocusEDITHatsujikoku() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgEkijikokuProp::OnBnClickedCheckModifyhatsujikoku()
{
	m_PropEditUiInternal.OnUiChanged() ;
}


} //namespace ViewJikokuhyou
