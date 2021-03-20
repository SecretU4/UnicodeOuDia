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
// CDlgEkiProp.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"

#include "..\DiagramEdit.h"
#include "CDlgEkiProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


namespace ViewEki{


// ================================================================
//	CDlgEkiProp::CPropEditUiInternal
// ================================================================
	// ================================
	//@name CPropEditUi - UiData - UiControl 間のデータ転送
	// ================================
void CDlgEkiProp::CPropEditUiInternal::UiDataToUi( const UIDATA* pUiData ) 
{
	CDlgEkiProp* pOuter = (CDlgEkiProp*)( (char*)this - offsetof( CDlgEkiProp , m_PropEditUiInternal ) ) ;

	// --------------------------------
	//	DDXを用いた、UiControlへの設定
	// --------------------------------
	{
		// 駅時刻形式
		{
			pOuter->m_iRADIO_Jikokukeisiki = pUiData->iEkijikokukeisiki ;
		}
		// 駅規模 
		{
			pOuter->m_iRADIO_Ekikibo = pUiData->iEkikibo ;
		}
		// --------------------------------
		pOuter->UpdateData( FALSE ) ;
	}
	// --------------------------------
	//	DDXを用いない、UiControlへの設定
	//	これらは、DDXによる値設定の後で
	//	行わなくてはなりません。
	// --------------------------------
	// 駅名 
	{
		CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ekimei ) ;
		pEdit->SetWindowText( pUiData->strEkimei.c_str() ) ;
		pEdit->SetSel( 0 , -1 ) ;
	}	
	// 境界線あり 
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_Kyoukaisen ) ;
		int nCheck = BST_INDETERMINATE ;
		switch( pUiData->iKyoukaisen )
		{
		case 1: // 境界線あり
			nCheck = BST_CHECKED ;
			break ;
		case 0: //なし
			nCheck = BST_UNCHECKED ;
			break ;
		}
		pButton->SetCheck( nCheck ) ;
	}

	//ダイヤグラム列車情報表示（下り）
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiKudari ) ;
		pComboBox->SetCurSel( pUiData->iDiagramRessyajouhouHyoujiKudari ) ;
	}
	// ダイヤグラム列車情報表示（上り） 
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiNobori ) ;
		pComboBox->SetCurSel( pUiData->iDiagramRessyajouhouHyoujiNobori ) ;
	}

	//[駅時刻を駅時刻形式で正規化]の設定です。
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_AdjustByEkijikokukeisiki ) ;
		int nCheck = ( pUiData->bAdjustByEkijikokukeisiki ? BST_CHECKED : BST_UNCHECKED );
		pButton->SetCheck( nCheck ) ;	
	}
}

void CDlgEkiProp::CPropEditUiInternal::UiDataFromUi( UIDATA* pUiData ) 
{
	CDlgEkiProp* pOuter = (CDlgEkiProp*)( (char*)this - offsetof( CDlgEkiProp , m_PropEditUiInternal ) ) ;
	int iRv = 0 ;
	
	// --------------------------------
	//	DDXを用いた、UiControlへの設定
	// --------------------------------
	if ( !pOuter->UpdateData( TRUE ) )
	{
		iRv = -1 ;	//	UpdateData でエラーが発生しました。
	}

	if ( iRv >= 0 )
	{
		// 駅時刻形式
		{
			pUiData->iEkijikokukeisiki = pOuter->m_iRADIO_Jikokukeisiki ;
		}
		// 駅規模 
		{
			pUiData->iEkikibo = pOuter->m_iRADIO_Ekikibo ;
		}
	}
	// --------------------------------
	//	DDXを用いない、UiControlへの設定
	//	これらは、DDXによる値設定の後で
	//	行わなくてはなりません。
	// --------------------------------
	// 駅名 
	{
		CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ekimei ) ;
		CString aString ;
		pEdit->GetWindowText( aString ) ;
		pUiData->strEkimei = (LPCTSTR)aString ;
	}
	// 境界線あり 
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_Kyoukaisen ) ;
		int nCheck = pButton->GetCheck() ;
		switch( nCheck )
		{
		case BST_CHECKED: 
			pUiData->iKyoukaisen = 1 ; 
			break ;
		case BST_UNCHECKED:
			pUiData->iKyoukaisen = 0 ; 
			break ;
		}

		//	チェックボックスは、中間状態への変更を認めません。
		//	ユーザーによって中間状態へ変更された場合は、
		//	チェックなし状態に変更します。
		if ( pUiData->iKyoukaisen != -1 && nCheck == BST_INDETERMINATE )
		{
			pUiData->iKyoukaisen = 0 ;
		}
	}

	//ダイヤグラム列車情報表示（下り）
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiKudari ) ;
		int iSel = pComboBox->GetCurSel(  ) ;
		if ( iSel != CB_ERR )
		{
			pUiData->iDiagramRessyajouhouHyoujiKudari = iSel ;
		}
	}
	// ダイヤグラム列車情報表示（上り） 
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiNobori ) ;
		int iSel = pComboBox->GetCurSel(  ) ;
		if ( iSel != CB_ERR )
		{
			pUiData->iDiagramRessyajouhouHyoujiNobori = iSel ;
		}
	}

	//[駅時刻を駅時刻形式で正規化]の設定です。
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_AdjustByEkijikokukeisiki ) ;
		int nCheck =  pButton->GetCheck() ; 
		switch( nCheck )
		{
		case BST_CHECKED: 
			pUiData->bAdjustByEkijikokukeisiki = true  ; 
			break ;
		case BST_UNCHECKED:
			pUiData->bAdjustByEkijikokukeisiki = false  ; 
			break ;
		}
	}
}

void CDlgEkiProp::CPropEditUiInternal::ShowError( 
			const std::string& strErrorReason ,
			const std::string& strInfo ) 
{
	CDlgEkiProp* pOuter = (CDlgEkiProp*)( (char*)this - offsetof( CDlgEkiProp , m_PropEditUiInternal ) ) ;

	CString strErrorMsg = strErrorReason.c_str() ;

	if ( strErrorReason == ERRMSG_EKIMEI_TOO_LONG )
	{
		pOuter->GetDlgItem( IDC_ERR_EkimeiNo )->GetWindowText( strErrorMsg )  ;
	}
	pOuter->MessageBox( strErrorMsg , NULL , MB_OK | MB_ICONEXCLAMATION ) ;

}

void CDlgEkiProp::CPropEditUiInternal::SetFocus( int iOffsetofUiDataMember ) 
{
	CDlgEkiProp* pOuter = (CDlgEkiProp*)( (char*)this - offsetof( CDlgEkiProp , m_PropEditUiInternal ) ) ;
	CWnd* pControl = NULL ;
	
	// 駅時刻形式
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iEkijikokukeisiki ) )
		{
			pControl = pOuter->GetDlgItem( IDC_RADIO_Jikokukeisiki ) ;
		}
	}
	// 駅規模 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iEkikibo ) )
		{
			pControl = pOuter->GetDlgItem( IDC_RADIO_Ekikibo ) ;
		}
	}
	// --------------------------------
	// 駅名 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , strEkimei ) )
		{
			pControl = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ekimei ) ;
		}
	}	
	// 境界線あり 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iKyoukaisen ) )
		{
			pControl = (CButton*)pOuter->GetDlgItem( IDC_CHECK_Kyoukaisen ) ;
		}
	}

	//ダイヤグラム列車情報表示（下り）
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iDiagramRessyajouhouHyoujiKudari ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiKudari ) ;
		}
	}
	// ダイヤグラム列車情報表示（上り） 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iDiagramRessyajouhouHyoujiNobori ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramRessyajouhouHyoujiNobori ) ;
		}
	}

	//[駅時刻を駅時刻形式で正規化]の設定です。
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , bAdjustByEkijikokukeisiki ) )
		{
			pControl = (CButton*)pOuter->GetDlgItem( IDC_CHECK_Kyoukaisen ) ;
		}
	}
	// --------------------------------
	if ( pControl != NULL )
	{
		pOuter->GotoDlgCtrl( pControl ) ; 
	}
}	

	// ********************************
	//	コンストラクタ
	// ********************************
CDlgEkiProp::CPropEditUiInternal::CPropEditUiInternal(
	bool bNewItem , 
	Mu<CentDedEki*>* pTarget ,
	bool* pbAdjustBuEkijikokukeisiki )
	: CPropEditUi_Eki( bNewItem , pTarget , pbAdjustBuEkijikokukeisiki ) 
{
}

/////////////////////////////////////////////////////////////////////////////
// CDlgEkiProp ダイアログ

	// --------------------------------
	//@name 下請関数
	// --------------------------------

	// ********************************
	//@name 属性
	// ********************************
// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
CDlgEkiProp::CDlgEkiProp(
		Mu<CentDedEki*>* pTarget ,
		bool* pbAdjustBuEkijikokukeisiki , 
		int iFocusItem ,
		CKeyinputSenderToModalDlg*	pCKeyinputSenderToModalDlg ,
		CWnd* pParent )
	: CDialog(CDlgEkiProp::IDD, pParent)
	, m_PropEditUiInternal( false , pTarget , pbAdjustBuEkijikokukeisiki ) 
	, m_iFocusItem( iFocusItem ) 
	, m_pCKeyinputSenderToModalDlg(	pCKeyinputSenderToModalDlg ) 
{
	//{{AFX_DATA_INIT(CDlgEkiProp)
	m_iRADIO_Jikokukeisiki = -1;
	m_iRADIO_Ekikibo = -1;
	//}}AFX_DATA_INIT
}


void CDlgEkiProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEkiProp)
	DDX_Radio(pDX, IDC_RADIO_Jikokukeisiki, m_iRADIO_Jikokukeisiki);
	DDX_Radio(pDX, IDC_RADIO_Ekikibo, m_iRADIO_Ekikibo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEkiProp, CDialog)
	//{{AFX_MSG_MAP(CDlgEkiProp)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
	ON_EN_KILLFOCUS(IDC_EDIT_Ekimei, &CDlgEkiProp::OnEnKillfocusEditEkimei)
	ON_BN_CLICKED(IDC_CHECK_Kyoukaisen, &CDlgEkiProp::OnBnClickedCheckKyoukaisen)
	ON_BN_CLICKED(IDC_RADIO_Jikokukeisiki, &CDlgEkiProp::OnBnClickedRadioJikokukeisiki)
	ON_BN_CLICKED(IDC_RADIO_Jikokukeisiki2, &CDlgEkiProp::OnBnClickedRadioJikokukeisiki2)
	ON_BN_CLICKED(IDC_RADIO_Jikokukeisiki3, &CDlgEkiProp::OnBnClickedRadioJikokukeisiki3)
	ON_BN_CLICKED(IDC_RADIO_Jikokukeisiki4, &CDlgEkiProp::OnBnClickedRadioJikokukeisiki4)
	ON_BN_CLICKED(IDC_RADIO_Ekikibo, &CDlgEkiProp::OnBnClickedRadioEkikibo)
	ON_BN_CLICKED(IDC_RADIO_Ekikibo2, &CDlgEkiProp::OnBnClickedRadioEkikibo2)
	ON_CBN_SELCHANGE(IDC_COMBO_DiagramRessyajouhouHyoujiKudari, &CDlgEkiProp::OnCbnSelchangeComboDiagramressyajouhouhyoujikudari)
	ON_CBN_SELCHANGE(IDC_COMBO_DiagramRessyajouhouHyoujiNobori, &CDlgEkiProp::OnCbnSelchangeComboDiagramressyajouhouhyoujinobori)
	ON_BN_CLICKED(IDC_CHECK_AdjustByEkijikokukeisiki, &CDlgEkiProp::OnBnClickedCheckAdjustbyekijikokukeisiki)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEkiProp メッセージ ハンドラ

BOOL CDlgEkiProp::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//	編集を開始
	m_PropEditUiInternal.StartEdit() ;
	
	// --------------------------------
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgEkiProp::OnOK() 
{
	int iResult = m_PropEditUiInternal.EndEdit() ;
	if ( iResult >= 0 )
	{
		CDialog::OnOK();
	}

}

void CDlgEkiProp::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	
	
	if ( bShow )
	{
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		//駅名
		if ( m_iFocusItem == 0 ){
			CEdit*	pControl = (CEdit*)GetDlgItem( IDC_EDIT_Ekimei );
			GotoDlgCtrl( pControl ) ;
			if ( m_pCKeyinputSenderToModalDlg != NULL ){
				m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
			}
		}
		//駅時刻形式
		if ( m_iFocusItem == 1 ){
			CWnd*	pControl = GetDlgItem( IDC_RADIO_Jikokukeisiki );
			GotoDlgCtrl( pControl ) ;
			if ( m_pCKeyinputSenderToModalDlg != NULL ){
				m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
			}
		}
		//駅規模
		if ( m_iFocusItem == 2 ){
			CWnd*	pControl = GetDlgItem( IDC_RADIO_Ekikibo );
			GotoDlgCtrl( pControl ) ;
			if ( m_pCKeyinputSenderToModalDlg != NULL ){
				m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
			}
		}
		
		m_iFocusItem = -1 ;
	}	
	
}

void CDlgEkiProp::OnEnKillfocusEditEkimei()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedCheckKyoukaisen()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioJikokukeisiki()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioJikokukeisiki2()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioJikokukeisiki3()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioJikokukeisiki4()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioEkikibo()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedRadioEkikibo2()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnCbnSelchangeComboDiagramressyajouhouhyoujikudari()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnCbnSelchangeComboDiagramressyajouhouhyoujinobori()
{
	m_PropEditUiInternal.OnUiChanged();
}

void CDlgEkiProp::OnBnClickedCheckAdjustbyekijikokukeisiki()
{
	m_PropEditUiInternal.OnUiChanged();
}

} //namespace ViewEki
