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
// CDlgRessyasyubetsuProp.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"

#include "MfcUtil\MfcUtil.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CDcdTargetOnPaint.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "LogMsg\LogMsg.h"

#include "..\DiagramEdit.h"
#include "..\entDed\CconvCentDed.h"
#include "CDlgRessyasyubetsuProp.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRessyasyubetsu{ 
using namespace std ;
using namespace OuMfc;


// ================================================================
//	CDlgRessyasyubetsuProp::CPropEditUiInternal
// ================================================================
		// ================================
		// オーバーライトの必要なメソッド2-UIに依存する処理
		// ================================
void CDlgRessyasyubetsuProp::CPropEditUiInternal::
UiDataToUi( const UIDATA* pUiData ) 
{
	CDlgRessyasyubetsuProp* pOuter = (CDlgRessyasyubetsuProp*)( (char*)this - offsetof( CDlgRessyasyubetsuProp , m_PropEditUiInternal ) ) ;

	// --------------------------------
	//	DDXを用いた、UiControlへの設定
	// --------------------------------
	{
		//	ここで、DDX変数に設定

		pOuter->UpdateData( FALSE ) ;
	}
	// --------------------------------
	//	DDXを用いない、UiControlへの設定
	//	これらは、DDXによる値設定の後で
	//	行わなくてはなりません。
	// --------------------------------

	// 列車種別名 
	{
		CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Syubetsumei ) ;
		pEdit->EnableWindow(  pUiData->bSyubetsumeiIsEnable ? TRUE : FALSE ) ;
		pEdit->SetWindowText( pUiData->strSyubetsumei.c_str() ) ;
		pEdit->SetSel( 0 , -1 ) ;
	}
	// 略称（種別名の略称）
	{
		CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ryakusyou ) ;
		pEdit->SetWindowText( pUiData->strRyakusyou.c_str() ) ;
		pEdit->SetSel( 0 , -1 ) ;
	}
	
	//	時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)
	{
		//	この項目は、コントロールには記憶されません。
	}
	//時刻表ビューで、この列車種別の時刻を表示するための時刻表フォント
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_JikokuhyouFontIndex ) ;
		pComboBox->SetCurSel( pUiData->iJikokuhyouFontIndex ) ;
	}

	// ダイヤグラム線の色
	{
		//	この項目は、コントロールには記憶されません。
	}

	// ダイヤグラム線の線スタイル	
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramSenStyle ) ;
		pComboBox->SetCurSel( pUiData->iDiagramSenStyle ) ;
	}

	// ダイヤグラム線の線スタイルが太線か否かを指定します。
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_DiagramSenStyleIsBold ) ;
		int nCheck = BST_INDETERMINATE ;
		switch( pUiData->iDiagramSenIsBold )
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
	
	// 停車駅明示の方法
	{
		CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_StopMarkDrawType ) ;
		pComboBox->SetCurSel( pUiData->iStopMarkDrawType ) ;
	}


	// --------------------------------	
	//	DcDraw への設定
	// --------------------------------	
	//	文字色の設定
	{
		pOuter->m_pdcdJikokuhyouMojiColor->setCdBrushProp( 
			pUiData->colorJikokuhyouMojiColor ) ;
		CRect	aRect = MfcUtil::GetDlgControlRect( pOuter , IDC_STATIC_JikokuhyouMojiColor ) ;
		pOuter->InvalidateRect( &aRect ) ;
	}
	//	時刻表フォント(文字色と時刻表フォント)
	{
		CdDrawTextProp	aCdDrawTextProp = pOuter->m_pdcdJikokuhyouFont->getCdDrawTextProp() ;
		aCdDrawTextProp.setTextColor( pUiData->colorJikokuhyouMojiColor ) ;
		
		// --------------------------------
		//	時刻表フォントが設定されている場合は、
		//	正しいサンプルが表示できます。
		if ( pUiData->iJikokuhyouFontIndex >= 0 )
		{
			aCdDrawTextProp.setCdFontProp( pOuter->m_fontpropJikokuhyouFont[pUiData->iJikokuhyouFontIndex] );
		}
		//	時刻表フォントが設定されていない場合は、
		//	正しいサンプルが表示できません。
		else
		{
			//	時刻表フォントのサンプルが表示できません。
			//	このときは、デフォルトフォントで表示します。
			CConverter_WinGdi	aConv ;
			aCdDrawTextProp.setCdFontProp( aConv.CdFontPropOf( DEFAULT_GUI_FONT ) );
		}
		// --------------------------------
		pOuter->m_pdcdJikokuhyouFont->setCdDrawTextProp( aCdDrawTextProp ) ;
		
			
		CRect	aRect = MfcUtil::GetDlgControlRect( pOuter , IDC_STATIC_JikokuhyouFont ) ;
		pOuter->InvalidateRect( &aRect ) ;
	}
	//	ダイヤグラム線
	// (ダイヤグラム線の色・線スタイル・太線)
	{
		CdDcdFreeLineProp	aCdLineProp ;
		//	線スタイル・太線がどちらも設定されている場合は、
		//	正しいサンプルが表示できます。
		if ( pUiData->iDiagramSenStyle >= 0 && pUiData->iDiagramSenIsBold  >= 0 )
		{
			CconvCentDed aCconvCentDed ;
			aCconvCentDed.CentDedRessyasyubetsu_to_CDcdFreeLineProp( 
				CentDedRessyasyubetsu::CdDiagramLineStyle( 
					pUiData->colorDiagramSenColor ,
					(CentDedRessyasyubetsu::ESenStyle)pUiData->iDiagramSenStyle , 
					pUiData->iDiagramSenIsBold == 1 ) ,
				&aCdLineProp ) ;
		}
		//	線スタイル・太線のいずれかが不定の場合は、
		//	サンプルが表示できません
		else
		{
			//	サンプルが表示できません。
			//	この場合は、線を表示しません(白線なので、見えません)
			aCdLineProp = CdDcdFreeLineProp().setColor( CdColorProp( 255 , 255 , 255 ) ) ;
			
		}
		pOuter->m_pdcdDiagramSen->setCdLineProp( aCdLineProp ) ;
		CRect	aRect = MfcUtil::GetDlgControlRect( pOuter , IDC_STATIC_DiagramSen ) ;
		pOuter->InvalidateRect( &aRect ) ;
	}
}


void CDlgRessyasyubetsuProp::CPropEditUiInternal::UiDataFromUi( UIDATA* pUiData ) 
{
	CDlgRessyasyubetsuProp* pOuter = (CDlgRessyasyubetsuProp*)( (char*)this - offsetof( CDlgRessyasyubetsuProp , m_PropEditUiInternal ) ) ;
	int iRv = 0 ;
	// --------------------------------
	//	DDXを用いた、UiControlへの設定
	// --------------------------------
	if ( !pOuter->UpdateData( TRUE ) )
	{
		iRv = -1 ;	//	UpdateData でエラーが発生しました。
	}
	// --------------------------------
	//	DDXを用いない、UiControlへの設定
	//	これらは、DDXによる値設定の後で
	//	行わなくてはなりません。
	// --------------------------------

	// 列車種別名 
	if ( iRv >= 0 )
	{
		{
			CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Syubetsumei ) ;
			CString aString ;
			pEdit->GetWindowText( aString ) ;
			pUiData->strSyubetsumei = (LPCTSTR)aString ;
		}
	}
	// 略称（種別名の略称）
	if ( iRv >= 0 )
	{
		{
			CEdit* pEdit = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ryakusyou ) ;
			CString aString ;
			pEdit->GetWindowText( aString ) ;
			pUiData->strRyakusyou = (LPCTSTR)aString ;
		}
	}
	
	//	時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)
	if ( iRv >= 0 )
	{
		//	この項目は、コントロールには記憶されません。
	}
	//時刻表ビューで、この列車種別の時刻を表示するための時刻表フォント
	if ( iRv >= 0 )
	{
		{
			CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_JikokuhyouFontIndex ) ;
			int iSel = pComboBox->GetCurSel(  ) ;
			if ( iSel != CB_ERR )
			{
				pUiData->iJikokuhyouFontIndex = iSel ;
			}
		}
	}

	// ダイヤグラム線の色
	if ( iRv >= 0 )
	{
		//	この項目は、コントロールには記憶されません。
	}

	// ダイヤグラム線の線スタイル	
	if ( iRv >= 0 )
	{
		{
			CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramSenStyle ) ;
			int iSel = pComboBox->GetCurSel(  ) ;
			if ( iSel != CB_ERR )
			{
				pUiData->iDiagramSenStyle = iSel ;
			}
		}
	}

	// ダイヤグラム線の線スタイルが太線か否かを指定します。
	if ( iRv >= 0 )
	{
		CButton* pButton = (CButton*)pOuter->GetDlgItem( IDC_CHECK_DiagramSenStyleIsBold ) ;
		int nCheck =  pButton->GetCheck() ; 
		switch( nCheck )
		{
		case BST_CHECKED: // 境界線あり
			pUiData->iDiagramSenIsBold = 1 ;
			break ;
		case BST_UNCHECKED: //なし
			pUiData->iDiagramSenIsBold = 0 ;
			break ;
		}

		//	チェックボックスは、中間状態への変更を認めません。
		//	ユーザーによって中間状態以外→中間状態へ変更された場合は、
		//	チェックなし状態に変更します。
		if ( pUiData->iDiagramSenIsBold != -1 && nCheck == BST_INDETERMINATE )
		{
			pUiData->iDiagramSenIsBold = 0 ;
		}
	}
	
	// 停車駅明示の方法
	if ( iRv >= 0 )
	{
		{
			CComboBox* pComboBox = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_StopMarkDrawType ) ;
			int iSel = pComboBox->GetCurSel(  ) ;
			if ( iSel != CB_ERR )
			{
				pUiData->iStopMarkDrawType = iSel ;
			}
		}
	}
}		
void CDlgRessyasyubetsuProp::CPropEditUiInternal::ShowError( 
			const std::string& strErrorReason ,
			const std::string& strInfo )  

{
	CDlgRessyasyubetsuProp* pOuter = (CDlgRessyasyubetsuProp*)( (char*)this - offsetof( CDlgRessyasyubetsuProp , m_PropEditUiInternal ) ) ;
	CString strErrorMsg = strErrorReason.c_str() ;
	if ( strErrorReason == ERRMSG_SYUBETUSMEI_EMPTY )
	{
		pOuter->GetDlgItem( IDC_ERROR_SyubetsumeiEmpty )->GetWindowText( strErrorMsg )  ;
	}
	else if ( strErrorReason == ERRMSG_RYAKUSYOULENGTH )
	{
		pOuter->GetDlgItem( IDC_ERROR_RyakusyouLength )->GetWindowText( strErrorMsg )  ;
	}
	pOuter->MessageBox( strErrorMsg , NULL , MB_OK | MB_ICONEXCLAMATION ) ;

}


void CDlgRessyasyubetsuProp::CPropEditUiInternal::
	SetFocus( int iOffsetofUiDataMember )
{
	CDlgRessyasyubetsuProp* pOuter = (CDlgRessyasyubetsuProp*)( (char*)this - offsetof( CDlgRessyasyubetsuProp , m_PropEditUiInternal ) ) ;
	CWnd* pControl = NULL ;

	// 列車種別名 
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , strSyubetsumei ) )
		{
			pControl = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Syubetsumei ) ;
		}
	}
	// 略称（種別名の略称）
	{
		if (iOffsetofUiDataMember == offsetof( UIDATA , strRyakusyou ) )
		{
			pControl = (CEdit*)pOuter->GetDlgItem( IDC_EDIT_Ryakusyou ) ;
		}
	}
	
	//	時刻表文字色(ダイヤグラムの列車情報の文字色を兼ねます)
	{
		//	この項目は、コントロールには記憶されません。
	}
	//時刻表ビューで、この列車種別の時刻を表示するための時刻表フォント
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iJikokuhyouFontIndex ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_JikokuhyouFontIndex ) ;
		}
	}

	// ダイヤグラム線の色
	{
		//	この項目は、コントロールには記憶されません。
	}

	// ダイヤグラム線の線スタイル	
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iDiagramSenStyle ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_DiagramSenStyle ) ;
		}
	}

	// ダイヤグラム線の線スタイルが太線か否かを指定します。
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iDiagramSenIsBold ) )
		{
			pControl = (CButton*)pOuter->GetDlgItem( IDC_CHECK_DiagramSenStyleIsBold ) ;
		}
	}
	
	// 停車駅明示の方法
	{
		if ( iOffsetofUiDataMember == offsetof( UIDATA , iStopMarkDrawType ) )
		{
			pControl = (CComboBox*)pOuter->GetDlgItem( IDC_COMBO_StopMarkDrawType ) ;
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
CDlgRessyasyubetsuProp::CPropEditUiInternal::
CPropEditUiInternal( bool bNewItem , Mu<CentDedRessyasyubetsu*>* pTarget )
	: CPropEditUi_Ressyasyubetsu( bNewItem ,pTarget  ) 
{
}



/////////////////////////////////////////////////////////////////////////////
// CDlgRessyasyubetsuProp ダイアログ


// ----------------------------------------------------------------

CDlgRessyasyubetsuProp::CDlgRessyasyubetsuProp(
		bool bNewItem , 
		Mu<CentDedRessyasyubetsu*>* pTarget,
		const CdDedDispProp&	aCdDedDispProp ,
		int iFocusItem , 
		CKeyinputSenderToModalDlg* pCKeyinputSenderToModalDlg , 
		CWnd* pParent )
	: CDialog(CDlgRessyasyubetsuProp::IDD, pParent)
	, m_PropEditUiInternal( bNewItem , pTarget ) 
	, m_iFocusItem( iFocusItem ) 
	, m_pCKeyinputSenderToModalDlg( pCKeyinputSenderToModalDlg )
	, m_pdcdJikokuhyouMojiColor( NULL ) 
	, m_pdcdJikokuhyouFont( NULL )
	, m_pdcdDiagramSen( NULL ) 
{
	for ( int idx = 0 ; idx < CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT ; idx ++ )
	{
		m_fontpropJikokuhyouFont[idx] = aCdDedDispProp.getJikokuhyouFont(idx) ;
	}


	//{{AFX_DATA_INIT(CDlgRessyasyubetsuProp)
	//}}AFX_DATA_INIT

	// --------------------------------
	//	DcDraw(ダイアログ上に描画を行うオブジェクト)の生成
	// --------------------------------
	CConverter_WinGdi aCConverter_WinGdi ;
	m_pdcdJikokuhyouMojiColor = new CDcdRectangle( 
		CdPenProp( 1 ) ) ;
	m_pdcdJikokuhyouFont = new CDcdTextbox( 
		CdPenProp( 1 ) , 2 , 2 , 
		TEXT( "1000" ) , 
		CdDrawTextProp( 
			aCConverter_WinGdi.CdFontPropOf( DEFAULT_GUI_FONT ) , 
			CdColorProp( 0 , 0 , 0 ) , 
			CdDrawTextFormat (
				CdDrawTextFormat::H_CENTER, 
				CdDrawTextFormat::V_SINGLELINT_CENTER 
			) 
		) ,
		TEXT( "" ) , 
		1 , 
		CdColorProp( 255 , 255 , 255 ) 
	) ;
	m_pdcdDiagramSen = new CDcdFreeLine_StyleSample() ;

}

CDlgRessyasyubetsuProp::~CDlgRessyasyubetsuProp()
{
	delete m_pdcdDiagramSen ;
	delete m_pdcdJikokuhyouFont ;
	delete m_pdcdJikokuhyouMojiColor ; 

}

void CDlgRessyasyubetsuProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRessyasyubetsuProp)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRessyasyubetsuProp, CDialog)
	//{{AFX_MSG_MAP(CDlgRessyasyubetsuProp)
	ON_WM_SHOWWINDOW()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHECK_DiagramSenStyleIsBold, OnCHECKDiagramSenStyleIsBold)
	ON_BN_CLICKED(IDC_BUTTON_JikokuhyouMojiColor, OnBUTTONJikokuhyouMojiColor)
	ON_BN_CLICKED(IDC_BUTTON_DiagramSeniColor, OnBUTTONDiagramSeniColor)
	ON_CBN_SELCHANGE(IDC_COMBO_DiagramSenStyle, OnSelchangeCOMBODiagramSenStyle)
	ON_CBN_SELCHANGE(IDC_COMBO_JikokuhyouFontIndex, &CDlgRessyasyubetsuProp::OnCbnSelchangeComboJikokuhyoufontindex)
	//}}AFX_MSG_MAP
	ON_EN_KILLFOCUS(IDC_EDIT_Syubetsumei, &CDlgRessyasyubetsuProp::OnEnKillfocusEditSyubetsumei)
	ON_EN_KILLFOCUS(IDC_EDIT_Ryakusyou, &CDlgRessyasyubetsuProp::OnEnKillfocusEditRyakusyou)
	ON_CBN_SELCHANGE(IDC_COMBO_StopMarkDrawType, &CDlgRessyasyubetsuProp::OnCbnSelchangeComboStopmarkdrawtype)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRessyasyubetsuProp メッセージ ハンドラ

BOOL CDlgRessyasyubetsuProp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//	編集を開始
	m_PropEditUiInternal.StartEdit() ;

	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgRessyasyubetsuProp::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	if ( bShow )
	{
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		switch( m_iFocusItem )
		{
		 //列車種別名
		 case 0 :
			{
				CWnd*	pControl = GetDlgItem( IDC_EDIT_Syubetsumei );
				GotoDlgCtrl( pControl ) ;
				if ( m_pCKeyinputSenderToModalDlg != NULL )
				{
					m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
				}
			}
			break ;
		 //略称
		 case 1 :
			{
				CWnd*	pControl = GetDlgItem( IDC_EDIT_Ryakusyou );
				GotoDlgCtrl( pControl ) ;
				if ( m_pCKeyinputSenderToModalDlg != NULL )
				{
					m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
				}
			}
			break ;
	
		 //線スタイル
		 case 2 :
			{
				CWnd*	pControl = GetDlgItem( IDC_BUTTON_DiagramSeniColor );
				GotoDlgCtrl( pControl ) ;
				if ( m_pCKeyinputSenderToModalDlg != NULL )
				{
					m_pCKeyinputSenderToModalDlg->registerCtrl( pControl->GetSafeHwnd() ) ;
				}
			}
			break ;
		}		
	}
	
}

void CDlgRessyasyubetsuProp::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	CDcdTargetOnPaint	aCDcdTargetOnPaint( GetSafeHwnd() , &dc.m_ps ) ; 
	
	{
		//時刻表文字色
		CConverter_WinGdi	aConverter ;

		CRect	aRect = MfcUtil::GetDlgControlRect( this , IDC_STATIC_JikokuhyouMojiColor ) ;
		CdDcdZoneXy	aCdDcdZoneXy = aConverter.CdDcdZoneXyOf( aRect ) ;
		CaDcdTargetItemPosition	aTarget( &aCDcdTargetOnPaint , aCdDcdZoneXy ) ;
		m_pdcdJikokuhyouMojiColor->DcDraw( &aTarget ) ;
	}
	{
		//時刻表フォント
		CConverter_WinGdi	aConverter ;

		CRect	aRect = MfcUtil::GetDlgControlRect( this , IDC_STATIC_JikokuhyouFont ) ;
		CdDcdZoneXy	aCdDcdZoneXy = aConverter.CdDcdZoneXyOf( aRect ) ;
		CaDcdTargetItemPosition	aTarget( &aCDcdTargetOnPaint , aCdDcdZoneXy ) ;
		m_pdcdJikokuhyouFont->DcDraw( &aTarget ) ;
	}
	{
		//ダイヤグラム線スタイル
		CConverter_WinGdi	aConverter ;

		CRect	aRect = MfcUtil::GetDlgControlRect( this , IDC_STATIC_DiagramSen ) ;
		CdDcdZoneXy	aCdDcdZoneXy = aConverter.CdDcdZoneXyOf( aRect ) ;
		CaDcdTargetItemPosition	aTarget( &aCDcdTargetOnPaint , aCdDcdZoneXy ) ;
		m_pdcdDiagramSen->DcDraw( &aTarget ) ;
	}
}




void CDlgRessyasyubetsuProp::OnOK() 
{
	int iResult = m_PropEditUiInternal.EndEdit() ;
	if ( iResult >= 0 )
	{
		CDialog::OnOK();
	}

}

void CDlgRessyasyubetsuProp::OnCHECKDiagramSenStyleIsBold() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyasyubetsuProp::OnBUTTONJikokuhyouMojiColor() 
{
	CConverter_WinGdi aConverter ;
	CColorDialog	aCColorDialog( 
		aConverter.COLORREFOf( m_PropEditUiInternal.GetUiData()->colorJikokuhyouMojiColor), 
		0 , 
		this ) ;
	if ( aCColorDialog.DoModal() == IDOK )
	{ 
		m_PropEditUiInternal.GetUiData()->colorJikokuhyouMojiColor  
			= aConverter.CdColorPropOf( aCColorDialog.GetColor() ) ;
		m_PropEditUiInternal.OnUiDataChanged() ;
	}
	
}

void CDlgRessyasyubetsuProp::OnBUTTONDiagramSeniColor() 
{
	CConverter_WinGdi aConverter ;
	CColorDialog	aCColorDialog( 
		aConverter.COLORREFOf( m_PropEditUiInternal.GetUiData()->colorDiagramSenColor ) , 
		0 , this ) ;
	if ( aCColorDialog.DoModal() == IDOK )
	{ 
		m_PropEditUiInternal.GetUiData()->colorDiagramSenColor 
			= aConverter.CdColorPropOf( aCColorDialog.GetColor() ) ;
		m_PropEditUiInternal.OnUiDataChanged() ;

	}
	
}

void CDlgRessyasyubetsuProp::OnSelchangeCOMBODiagramSenStyle() 
{
	m_PropEditUiInternal.OnUiChanged() ;
}
void CDlgRessyasyubetsuProp::OnCbnSelchangeComboJikokuhyoufontindex()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyasyubetsuProp::OnEnKillfocusEditSyubetsumei()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyasyubetsuProp::OnEnKillfocusEditRyakusyou()
{
	m_PropEditUiInternal.OnUiChanged() ;
}

void CDlgRessyasyubetsuProp::OnCbnSelchangeComboStopmarkdrawtype()
{
	m_PropEditUiInternal.OnUiChanged() ;
}


} //namespace ViewRessyasyubetsu
