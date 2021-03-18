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
// cdlgmodifyekijikokuoperation2.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "..\diagramedit.h"
#include "cdlgmodifyekijikokuoperation2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

/////////////////////////////////////////////////////////////////////////////
// CDlgModifyEkijikokuOperation2 ダイアログ
// --------------------------------
//@name 下請関数
// --------------------------------
bool CDlgModifyEkijikokuOperation2::updateControl() 
{
	bool bRv = false ;
	{
		CWnd* pCWnd = GetDlgItem( IDC_RADIO_Ekiatsukai ) ;
		BOOL bCurrentState = pCWnd->IsWindowEnabled() ;
		CButton* pCChekcbox = (CButton*)GetDlgItem(IDC_CHECK_EkiatsukaiModify) ;
		BOOL bState = ( pCChekcbox->GetCheck() == 1 );

		if ( ( bState && !bCurrentState ) ||
			( !bState && bCurrentState ) )
		{
			GetDlgItem( IDC_RADIO_Ekiatsukai )->EnableWindow( bState ) ;
			GetDlgItem( IDC_RADIO_Ekiatsukai1 )->EnableWindow( bState ) ;
			GetDlgItem( IDC_RADIO_Ekiatsukai2 )->EnableWindow( bState ) ;
			GetDlgItem( IDC_RADIO_Ekiatsukai3 )->EnableWindow( bState ) ;
			bRv = true ;
		}
	}
	{
		CButton* pCWnd = (CButton*)GetDlgItem( IDC_RADIO_EkijikokuOperation1 ) ;
		BOOL bCurrentState = GetDlgItem( IDC_EDIT_Seconds1 )->IsWindowEnabled() ;
		BOOL bState = ( ( pCWnd->GetCheck() & 3 ) == 1 ) ;
		if ( ( bState && !bCurrentState ) ||
			( !bState && bCurrentState ) ){
			GetDlgItem( IDC_EDIT_Seconds1 )->EnableWindow( bState ) ;
			bRv = true ;
		}
	}
	{
		CButton* pCWnd = (CButton*)GetDlgItem( IDC_RADIO_EkijikokuOperation2 ) ;
		BOOL bState = ( ( pCWnd->GetCheck() & 3 ) == 1 ) ;

		{
			BOOL bCurrentState = GetDlgItem( IDC_COMBO_JikokuOrderCopySrc )->IsWindowEnabled() ;

			if ( ( bState && !bCurrentState ) ||
				( !bState && bCurrentState ) ){
				GetDlgItem( IDC_COMBO_JikokuOrderCopySrc )->EnableWindow( bState ) ;
				bRv = true ;
			}
		}
		{
			BOOL bCurrentState = GetDlgItem( IDC_EDIT_Seconds2 )->IsWindowEnabled() ;
			if ( ( bState && !bCurrentState ) ||
				( !bState && bCurrentState ) ){
				GetDlgItem( IDC_EDIT_Seconds2 )->EnableWindow( bState ) ;
				bRv = true ;
			}
		}
	}
	return bRv ;
}

int CDlgModifyEkijikokuOperation2::COMBO_JikokuOuderCopySrcFromJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder ) 
{
	int iRv = -1 ;
	if ( !aJikokuOrder.getIsNull() )
	{
		iRv = aJikokuOrder.getEkiOrder() * 2 ;
		if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
		{
			iRv ++ ;
		}
	}
	return iRv ;
}

CdDedJikokuOrder 
CDlgModifyEkijikokuOperation2::COMBO_JikokuOuderCopySrcToJikokuOrder( 
		int iComboIndex ) 
{
	CdDedJikokuOrder	aRv ;
	if ( 0 <= iComboIndex && iComboIndex < (int)m_contstrEkimei.size() * 2 )
	{
		CdDedJikokuOrder::EEkiJikokuItem eEkiJikokuItem = CdDedJikokuOrder::EkiJikokuItem_Chaku ;
		if ( iComboIndex % 2 == 1 )
		{
			eEkiJikokuItem = CdDedJikokuOrder::EkiJikokuItem_Hatsu ;
		}
		aRv.setEkiOrder( iComboIndex / 2 , eEkiJikokuItem ) ;
	}
	return aRv ;
}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

CDlgModifyEkijikokuOperation2::CDlgModifyEkijikokuOperation2(
 	CentDedRessya_EkijikokuModifyOperation2& aEkijikokuModifyOperation2 ,
	const Mu<CentDedEkiCont::CdDedEki>* pCentDedEkiContGet , 
	CWnd* pParent )
	: CDialog(CDlgModifyEkijikokuOperation2::IDD, pParent)
	, m_EkijikokuModifyOperation2( aEkijikokuModifyOperation2 ) 
{
	//{{AFX_DATA_INIT(CDlgModifyEkijikokuOperation2)
	m_iRADIO_Ekiatsukai = aEkijikokuModifyOperation2.getEkiatsukai() ;
	m_bCHECK_EkiatsukaiModify = aEkijikokuModifyOperation2.getSetEkiatsukai() ;
	m_iRADIO_EkijikokuOperation = aEkijikokuModifyOperation2.getOperation() ;
	m_iCOMBO_JikokuOuderCopySrc = -1 ;
	m_iEDIT_Seconds1 = aEkijikokuModifyOperation2.getSeconds();
	m_iEDIT_Seconds2 = aEkijikokuModifyOperation2.getSeconds();
	//}}AFX_DATA_INIT

	CdDedJikokuOrder	aJikokuOrderCopySrc = aEkijikokuModifyOperation2.getJikokuOrderCopySrc() ;
	m_iCOMBO_JikokuOuderCopySrc = aJikokuOrderCopySrc.getEkiOrder()*2 ;
	if ( aJikokuOrderCopySrc.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu ){
		m_iCOMBO_JikokuOuderCopySrc ;
	}


	{
		int idxEki ;
		for ( idxEki = 0 ; idxEki < pCentDedEkiContGet->size() ; idxEki ++ )
		{
			m_contstrEkimei.push_back( pCentDedEkiContGet->get( idxEki ).getEkimei() ) ;
		}
	}
}


void CDlgModifyEkijikokuOperation2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgModifyEkijikokuOperation2)
	DDX_Radio(pDX, IDC_RADIO_Ekiatsukai, m_iRADIO_Ekiatsukai);
	DDX_Check(pDX, IDC_CHECK_EkiatsukaiModify, m_bCHECK_EkiatsukaiModify);
	DDX_Radio(pDX, IDC_RADIO_EkijikokuOperation, m_iRADIO_EkijikokuOperation);
	DDX_CBIndex(pDX, IDC_COMBO_JikokuOrderCopySrc, m_iCOMBO_JikokuOuderCopySrc);
	DDX_Text(pDX, IDC_EDIT_Seconds1, m_iEDIT_Seconds1);
	DDX_Text(pDX, IDC_EDIT_Seconds2, m_iEDIT_Seconds2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgModifyEkijikokuOperation2, CDialog)
	//{{AFX_MSG_MAP(CDlgModifyEkijikokuOperation2)
	ON_BN_CLICKED(IDC_RADIO_EkijikokuOperation, OnRADIOEkijikokuOperation)
	ON_BN_CLICKED(IDC_RADIO_EkijikokuOperation1, OnRADIOEkijikokuOperation1)
	ON_BN_CLICKED(IDC_RADIO_EkijikokuOperation3, OnRADIOEkijikokuOperation3)
	ON_BN_CLICKED(IDC_RADIO_EkijikokuOperation2, OnRADIOEkijikokuOperation2)
	ON_BN_CLICKED(IDC_CHECK_EkiatsukaiModify, OnCHECKEkiatsukaiModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgModifyEkijikokuOperation2 メッセージ ハンドラ

BOOL CDlgModifyEkijikokuOperation2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	{
		CComboBox*	pCComnoBox = (CComboBox*)GetDlgItem( IDC_COMBO_JikokuOrderCopySrc ) ;
		CString	strChaku ;
		CString	strHatsu ;
		strChaku.LoadString( IDS_WORD_Chaku ) ;
		strHatsu.LoadString( IDS_WORD_Hatsu ) ;
		int idxEki ;
		for ( idxEki = 0 ; idxEki < (int)m_contstrEkimei.size() ; idxEki ++ )
		{
			CString	strItem ;
			strItem = m_contstrEkimei[idxEki].c_str() ;
			pCComnoBox->AddString( strItem + strChaku ) ;
			pCComnoBox->AddString( strItem + strHatsu ) ;
		}
		pCComnoBox->SetCurSel( 
			COMBO_JikokuOuderCopySrcFromJikokuOrder( 
				m_EkijikokuModifyOperation2.getJikokuOrderCopySrc() ) );
	}
	updateControl() ;
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgModifyEkijikokuOperation2::OnRADIOEkijikokuOperation() 
{
	updateControl() ;
	
}

void CDlgModifyEkijikokuOperation2::OnRADIOEkijikokuOperation1() 
{
	updateControl() ;
	
}

void CDlgModifyEkijikokuOperation2::OnRADIOEkijikokuOperation3() 
{
	updateControl() ;
	
}

void CDlgModifyEkijikokuOperation2::OnRADIOEkijikokuOperation2() 
{
	updateControl() ;
	
}

void CDlgModifyEkijikokuOperation2::OnOK() 
{
	int iRv = 0 ;
	if ( iRv >= 0 )
	{
		if ( !UpdateData() )
		{
			iRv = -1 ;	//	値が不正です。
		}
		else
		{
			m_EkijikokuModifyOperation2.setSetEkiatsukai( m_bCHECK_EkiatsukaiModify != FALSE ) ;
			m_EkijikokuModifyOperation2.setEkiatsukai( 
				(CentDedEkiJikoku::EEkiatsukai)m_iRADIO_Ekiatsukai ) ;
			m_EkijikokuModifyOperation2.setOperation( 
				(CentDedRessya_EkijikokuModifyOperation2::EOperation)m_iRADIO_EkijikokuOperation ) ;
			if ( m_EkijikokuModifyOperation2.getOperation() == 
				CentDedRessya_EkijikokuModifyOperation2::OperationModify )
			{
				m_EkijikokuModifyOperation2.setSeconds( m_iEDIT_Seconds1 ) ;
			}
			else if ( m_EkijikokuModifyOperation2.getOperation() == 
				CentDedRessya_EkijikokuModifyOperation2::OperationCopy )
			{
				m_EkijikokuModifyOperation2.setJikokuOrderCopySrc( 
					COMBO_JikokuOuderCopySrcToJikokuOrder( m_iCOMBO_JikokuOuderCopySrc ) ) ;
				m_EkijikokuModifyOperation2.setSeconds( m_iEDIT_Seconds2 ) ;
			}
		}
	}

	if ( iRv >= 0 )
	{
		CDialog::OnOK();
	}
}

void CDlgModifyEkijikokuOperation2::OnCHECKEkiatsukaiModify() 
{
	updateControl() ;
	
}
} //namespace ViewJikokuhyou

