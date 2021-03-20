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
// CDlgRessyaProp.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"

#include "str\strtoint.h"

#include "..\DiagramEdit.h"
#include "CDlgRessyaProp.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

using namespace std ;


// ================================================================
//	CDlgRessyaProp::CPropEditUiInternal
// ================================================================

		// ================================
		//@name UIとのインターフェース
		// ================================
void CDlgRessyaProp::CPropEditUiInternal::UiDataToUi( const UIDATA* pUiData ) 
{
	CDlgRessyaProp* pOuter = (CDlgRessyaProp*)( (BYTE*)this - offsetof( CDlgRessyaProp , m_PropEditUiInternal ) ) ;
	CWnd* pFocus = CWnd::GetFocus() ;

	// --------------------------------
	//	DDXを用いた、UiControlへの設定
	// --------------------------------
	{
		// --------------------------------
		pOuter->UpdateData( FALSE ) ;
	}
	// --------------------------------
	//	DDXを用いない、UiControlへの設定
	//	これらは、DDXによる値設定の後で
	//	行わなくてはなりません。
	// --------------------------------
	//iIsNull
	{
		CButton* pControl = (CButton*)( pOuter->GetDlgItem( IDC_CHECK_IsNull ) ) ;
		int nCheck = BST_UNCHECKED ;
		switch( pUiData->iIsNull )
		{
		case 1:
			nCheck = BST_CHECKED ;
			break ;
		case -1:
			nCheck = BST_INDETERMINATE ;
			break ;
		}
		pControl->SetCheck( nCheck ) ;
	}
	//strRessyabangou,bRessyabangouIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Ressyabangou ) ) ;
		pControl->SetWindowText( pUiData->strRessyabangou.c_str() ) ;
		pControl->EnableWindow( pUiData->bRessyabangouIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
	//iRessyasyubetsuIndex,bRessyasyubetsuIndexIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ) ;
		pControl->SetCurSel( pUiData->iRessyasyubetsuIndex ) ;
		pControl->EnableWindow( pUiData->bRessyasyubetsuIndexIsEnable ) ;
	}
	//strRessyamei,bRessyameiIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Ressyamei ) ) ;
		pControl->SetWindowText( pUiData->strRessyamei.c_str() ) ;
		pControl->EnableWindow( pUiData->bRessyameiIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
	//strGousuu,bGousuuIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Gousuu ) ) ;
		pControl->SetWindowText( pUiData->strGousuu.c_str() ) ;
		pControl->EnableWindow( pUiData->bGousuuIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
	//strBikou,bBikouIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Bikou ) ) ;
		pControl->SetWindowText( pUiData->strBikou.c_str() ) ;
		pControl->EnableWindow( pUiData->bBikouIsEnable ) ;
		pControl->SetSel( 0 , -1 ) ;
	}
}



void CDlgRessyaProp::CPropEditUiInternal::UiDataFromUi( UIDATA* pUiData )  
{
	int iRv = 0 ; 

	CDlgRessyaProp* pOuter = (CDlgRessyaProp*)( (BYTE*)this - offsetof( CDlgRessyaProp , m_PropEditUiInternal ) ) ;

	//iIsNull
	{
		CButton* pControl = (CButton*)( pOuter->GetDlgItem( IDC_CHECK_IsNull ) ) ;
		int nCheck = pControl->GetCheck() ;
		pUiData->iIsNull = 0 ; 
		switch( nCheck )
		{
		case BST_CHECKED:
			pUiData->iIsNull = 1 ;
			break ;
		case BST_UNCHECKED:
			pUiData->iIsNull = 0 ;
			break ;
		}
		//	チェックボックスは、中間状態への変更を認めません。
		//	ユーザーによって中間状態へ変更された場合は、
		//	チェックなし状態に変更します。
		if ( pUiData->iIsNull == -1 && nCheck == BST_INDETERMINATE )
		{
			pUiData->iIsNull = 0 ;
		}
	}
	//strRessyabangou,bRessyabangouIsEnable
	{
		CEdit* pControl = (CEdit*)( pOuter->GetDlgItem( IDC_EDIT_Ressyabangou ) ) ;
		CString strText ;
		pControl->GetWindowText( strText ) ;
		pUiData->strRessyabangou = strText ;
	}
	//iRessyasyubetsuIndex,bRessyasyubetsuIndexIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ) ;
		int iIndex = pControl->GetCurSel() ;
		if ( iIndex == CB_ERR )
		{
			iIndex = -1 ;
		}
		pUiData->iRessyasyubetsuIndex = iIndex ;
	}
	//strRessyamei,bRessyameiIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_EDIT_Ressyamei ) ) ;
		CString strText ;
		pControl->GetWindowText( strText ) ;
		pUiData->strRessyamei = strText ;
	}
	//strGousuu,bGousuuIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_EDIT_Gousuu ) ) ;
		CString strText ;
		pControl->GetWindowText( strText ) ;
		pUiData->strGousuu = strText ;
	}
	//strBikou,bBikouIsEnable
	{
		CComboBox* pControl = (CComboBox*)( pOuter->GetDlgItem( IDC_EDIT_Bikou ) ) ;
		CString strText ;
		pControl->GetWindowText( strText ) ;
		pUiData->strBikou = strText ;
	}
}
		
void CDlgRessyaProp::CPropEditUiInternal::ShowError( 
			const std::string& strErrorReason ,
			const std::string& strInfo )  
{
	CDlgRessyaProp* pOuter = (CDlgRessyaProp*)( (BYTE*)this - offsetof( CDlgRessyaProp , m_PropEditUiInternal ) ) ;
	CString strErrorMsg = strErrorReason.c_str() ;

	pOuter->MessageBox( strErrorMsg , NULL , MB_OK | MB_ICONEXCLAMATION ) ;
}


void CDlgRessyaProp::CPropEditUiInternal::SetFocus( int iOffsetofUiDataMember )  
{
	int iResult = 0 ; 

	//	NULL列車の場合は、フォーカス位置は『空行』に移動します
	if ( GetUiData()->iIsNull == 1 )	//	ON
	{
		iOffsetofUiDataMember = offsetof(UIDATA , iIsNull ) ;
	}
	// --------------------------------



	CDlgRessyaProp* pOuter = (CDlgRessyaProp*)( (BYTE*)this - offsetof( CDlgRessyaProp , m_PropEditUiInternal ) ) ;
	CWnd* pWnd = NULL ;
	//iIsNull
	if ( iOffsetofUiDataMember == offsetof(UIDATA , iIsNull ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_CHECK_IsNull ) ) ;
	}
	//strRessyabangou,bRessyabangouIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , strRessyabangou ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_EDIT_Ressyabangou ) ) ;
	}
	//iRessyasyubetsuIndex,bRessyasyubetsuIndexIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , iRessyasyubetsuIndex ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ) ;
	}
	//strRessyamei,bRessyameiIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , strRessyamei ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_EDIT_Ressyamei ) ) ;
	}
	//strGousuu,bGousuuIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , strGousuu ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_EDIT_Gousuu ) ) ;
	}
	//strBikou,bBikouIsEnable
	if ( iOffsetofUiDataMember == offsetof(UIDATA , strBikou ) )
	{
		pWnd = ( pOuter->GetDlgItem( IDC_EDIT_Bikou ) ) ;
	}

	if ( pWnd != NULL )
	{
		pOuter->GotoDlgCtrl( pWnd ) ;
	}
}
		// ********************************
		//	コンストラクタ
		// ********************************
CDlgRessyaProp::CPropEditUiInternal::CPropEditUiInternal(
	bool bNewItem , 
	Mu<CentDedRessya*>* pTarget , 
	int iRessyasyubetsu ) 
	: CPropEditUi_Ressya( bNewItem , pTarget , iRessyasyubetsu ) 		
{
}
		


/////////////////////////////////////////////////////////////////////////////
// CDlgRessyaProp ダイアログ
// --------------------------------
//@name 下請関数
// --------------------------------
int CDlgRessyaProp::FirstFocusItemArgConvert( int iFocusItem ) 
{
	int iFirstFocusItemOffset = -1 ;

	switch( iFocusItem )
	{
	case 0:	//	空行
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , iIsNull ) ;
		break ;
	case 1:	//	列車番号
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , strRessyabangou ) ;
		break ;
	case 2:	//	列車種別
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , iRessyasyubetsuIndex ) ;
		break ;
	case 3:	//	列車名
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , strRessyamei ) ;
		break ;
	case 4:	//	号数
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , strGousuu ) ;
		break ;
	case 5:	//	備考
		iFirstFocusItemOffset = offsetof( CPropEditUiInternal::UIDATA , strBikou ) ;
		break ;
	}
	return iFirstFocusItemOffset ;

}

// ********************************
//	CDlgRessyaProp
// ********************************
	// ********************************
	//@name 属性
	// ********************************

// ----------------------------------------------------------------



CDlgRessyaProp::CDlgRessyaProp(
	   bool bNewEdit ,
		Mu<CentDedRessya*>* pTarget ,
		int iFocusItem ,
		CKeyinputSenderToModalDlg*	pCKeyinputSenderToModalDlg ,
		CWnd* pParent )
	: CDialog(CDlgRessyaProp::IDD, pParent)
	, m_iFocusItem( iFocusItem ) 
	, m_PropEditUiInternal( bNewEdit ,  pTarget , getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont()->size() ) 
	, m_pCKeyinputSenderToModalDlg(	pCKeyinputSenderToModalDlg ) 
{
	//{{AFX_DATA_INIT(CDlgRessyaProp)
	//}}AFX_DATA_INIT
}


void CDlgRessyaProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRessyaProp)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRessyaProp, CDialog)
	//{{AFX_MSG_MAP(CDlgRessyaProp)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_CHECK_IsNull, OnCHECKIsNull)
	//}}AFX_MSG_MAP
	ON_EN_KILLFOCUS(IDC_EDIT_Ressyabangou, &CDlgRessyaProp::OnEnKillfocusEditRessyabangou)
	ON_CBN_SELCHANGE(IDC_COMBO_Ressyasyubetsu, &CDlgRessyaProp::OnCbnSelchangeComboRessyasyubetsu)
	ON_EN_KILLFOCUS(IDC_EDIT_Ressyamei, &CDlgRessyaProp::OnEnKillfocusEditRessyamei)
	ON_EN_KILLFOCUS(IDC_EDIT_Gousuu, &CDlgRessyaProp::OnEnKillfocusEditGousuu)
	ON_EN_KILLFOCUS(IDC_EDIT_Bikou, &CDlgRessyaProp::OnEnKillfocusEditBikou)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRessyaProp メッセージ ハンドラ

BOOL CDlgRessyaProp::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//IDC_COMBO_Ressyasyubetsu
	{
		const CentDedRosen* pCentDedRosen = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu = 
			pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;
		
		CComboBox*	pCComboBox = (CComboBox*)GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ;
		for ( int idxRessyasyubetsu = 0 ; 
			idxRessyasyubetsu < pMuCentDedRessyasyubetsu->size() ; 
			idxRessyasyubetsu ++ )
		{
			const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = 
				pMuCentDedRessyasyubetsu->get( idxRessyasyubetsu ) ;

			string	strSyubetsumei = pCentDedRessyasyubetsu->getSyubetsumei() ;
			
			// 『列車のプロパティ』ダイアログの『列車種別』の
			//	ドロップダウンリストの項目の先頭10個に、
			//	"0. " 〜 "9. " までの数字を追加
			//	(例:　"普通"→"0. 普通" ) 
			if ( idxRessyasyubetsu < 10 )
			{
				strSyubetsumei = stringOf( idxRessyasyubetsu ) 
					+ ". " 
					+ strSyubetsumei ;
			}

			pCComboBox->AddString( strSyubetsumei.c_str() ) ;
		}
	}

	m_PropEditUiInternal.StartEdit() ;

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgRessyaProp::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	if ( bShow )
	{
		//	編集開始時のフォーカス位置を設定します。
		//	この処理は、 OnInitDialog() ではできません。
		//	OnShowWindow() で、ダイアログボックスが表示されたときに
		//	行う必要があります。

		CWnd*	pControl = NULL ;

		//	列車が空行以外
		if ( m_PropEditUiInternal.GetUiData()->iIsNull != 1 ) 
		{
			switch( m_iFocusItem ){
			 case 0	:	//	空行
				pControl = GetDlgItem( IDC_CHECK_IsNull ) ;
				break ;
			 case 1	:	//	列車番号
				pControl = GetDlgItem( IDC_EDIT_Ressyabangou ) ;
				break ;
			 case 2	:	//	列車種別
				pControl = GetDlgItem( IDC_COMBO_Ressyasyubetsu ) ;
				break ;
			 case 3	:	//	列車名
				pControl = GetDlgItem( IDC_EDIT_Ressyamei ) ;
				break ;
			 case 4	:	//	号数
				pControl = GetDlgItem( IDC_EDIT_Gousuu ) ;
				break ;
			 case 5	:	//	備考
				pControl = GetDlgItem( IDC_EDIT_Bikou ) ;
				break ;
			}
		}
		else
		{
				//	列車がNull状態の場合は、
				//	『空行』以外のコントロールはすべて
				//	無効になるため、
				//	『空行』コントロールにフォーカスをおきます。
				pControl = GetDlgItem( IDC_CHECK_IsNull ) ;
		}
		if ( pControl != NULL )
		{
			GotoDlgCtrl( pControl ) ;
			if ( m_pCKeyinputSenderToModalDlg != NULL ){
				m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
			}
		}
		
	}
}

void CDlgRessyaProp::OnOK() 
{
	int iResult = m_PropEditUiInternal.EndEdit() ;
	if ( iResult >= 0 )
	{
		CDialog::OnOK();
	}
}

void CDlgRessyaProp::OnCHECKIsNull() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}


void CDlgRessyaProp::OnEnKillfocusEditRessyabangou()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyaProp::OnCbnSelchangeComboRessyasyubetsu()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyaProp::OnEnKillfocusEditRessyamei()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyaProp::OnEnKillfocusEditGousuu()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyaProp::OnEnKillfocusEditBikou()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

} //namespace ViewJikokuhyou
