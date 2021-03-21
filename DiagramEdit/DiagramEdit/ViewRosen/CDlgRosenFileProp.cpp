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
// CDlgRosenFileProp.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"

#include "str/CStrCharSizeMb.h"
#include "DcDraw\CConverter_WinGdi.h"

#include "..\DiagramEdit.h"
#include "..\DedRosenFileData\EditCmd\CRfEditCmd_DedRosenFileDataProp.h"
#include "CDlgRosenFileProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRosen{


// ****************************************************************
//	CPropEditorData
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
/**
 @param pCDedRosenFileData [in]
	『路線ファイル』のデータ
 */
CDlgRosenFileProp::CPropEditorData::CPropEditorData( 
	const CDedRosenFileData* pCDedRosenFileData ) :
	m_strRosenName( pCDedRosenFileData->getCentDedRosen()->getName() ) 
	, m_jikokuKitenJikoku( pCDedRosenFileData->getCentDedRosen()->getKitenJikoku() ) 
	, m_iDiagramDgrYZahyouKyoriDefault( pCDedRosenFileData->getCentDedRosen()->getDiagramDgrYZahyouKyoriDefault() ) 
	, m_CdDedDispProp( pCDedRosenFileData->getCdDedDispProp() ) 
{
}

	// ********************************
	//@name UI表示データを取得・設定
	// ********************************
std::string	CDlgRosenFileProp::CPropEditorData::getUIRosenName()const 
{
	return m_strRosenName ;
}
void CDlgRosenFileProp::CPropEditorData::setUIRosenName( 
	const std::string& value ) 
{
	m_strRosenName = value ;
}

CdDedJikoku	CDlgRosenFileProp::CPropEditorData::getUIKitenJikoku()const 
{
	return m_jikokuKitenJikoku ;
}
void CDlgRosenFileProp::CPropEditorData::setUIKitenJikoku( 
	const CdDedJikoku& value ) 
{
	m_jikokuKitenJikoku = value ;
}
int	
CDlgRosenFileProp::CPropEditorData::getUIDiagramDgrYZahyouKyoriDefault()const 
{
	return m_iDiagramDgrYZahyouKyoriDefault ;
}


void CDlgRosenFileProp::CPropEditorData::setUIDiagramDgrYZahyouKyoriDefault( 
	int value ) 
{
	m_iDiagramDgrYZahyouKyoriDefault = value ;
}


CdDedDispProp CDlgRosenFileProp::CPropEditorData::getUIDispProp()const
{
	return m_CdDedDispProp ;
}


void 
CDlgRosenFileProp::CPropEditorData::setUIDispProp(CdDedDispProp& value)
{
	m_CdDedDispProp = value ;
}

	// ********************************
	//@name 編集対象データを適用
	// ********************************
void CDlgRosenFileProp::CPropEditorData::applyTo( CDedRosenFileData* pApplyTo )
{
	pApplyTo->getCentDedRosen()->setName( m_strRosenName ) ;
	pApplyTo->getCentDedRosen()->setKitenJikoku( m_jikokuKitenJikoku ) ;
	pApplyTo->getCentDedRosen()->setDiagramDgrYZahyouKyoriDefault( m_iDiagramDgrYZahyouKyoriDefault ) ;
	pApplyTo->setCdDedDispProp( m_CdDedDispProp ) ;
}

Ou<CRfEditCmd> 
CDlgRosenFileProp::CPropEditorData::createEditCmd  ()
{
	OuNew<CRfEditCmd> pCmd( 
		new CRfEditCmd_DedRosenFileDataProp( 
			m_strRosenName , 
			m_jikokuKitenJikoku , 
			m_iDiagramDgrYZahyouKyoriDefault , 
			m_CdDedDispProp 
		) 
	) ;
	return pCmd ;
}


/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp ダイアログ
void CDlgRosenFileProp::UpdateChildWindowShow()
{
		int	iLCurSel = m_tabMAIN.GetCurSel() ;
	
		switch( iLCurSel ){
		 case 0:
			m_CDlgRosenFileProp_Rosen.ShowWindow( SW_SHOWNORMAL ) ;
			m_CDlgRosenFileProp_FontColor.ShowWindow( SW_HIDE ) ;
			m_CDlgRosenFileProp_Diagram.ShowWindow( SW_HIDE ) ;
			break ;
		 case 1:
			m_CDlgRosenFileProp_Rosen.ShowWindow( SW_HIDE ) ;
			m_CDlgRosenFileProp_FontColor.ShowWindow( SW_SHOWNORMAL ) ;
			m_CDlgRosenFileProp_Diagram.ShowWindow( SW_HIDE ) ;
			break ;
		 case 2:
			m_CDlgRosenFileProp_Rosen.ShowWindow( SW_HIDE ) ;
			m_CDlgRosenFileProp_FontColor.ShowWindow( SW_HIDE ) ;
			m_CDlgRosenFileProp_Diagram.ShowWindow( SW_SHOWNORMAL ) ;
			break ;
		}
	
}

/** 時刻の書式を保持します。 */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	false ,		//	NoColon 
	CdDedJikoku::CConv::EHour_Zero ,	// 時が 00 から 09 の場合、10の位を "0" とします
	CdDedJikoku::CConv::ESecond_NoSecond 	// 秒を常に出力しません。 
	) ;


CDlgRosenFileProp::CPropEditorData* 
CDlgRosenFileProp::getPropEditorData() 
{
	return &m_PropEditorData ;
}

CDlgRosenFileProp::CDlgRosenFileProp(
		const CDedRosenFileData*	pCDedRosenFileData ,
		CWnd* pParent )
	: CDialog(CDlgRosenFileProp::IDD, pParent)
	, m_PropEditorData( pCDedRosenFileData ) 
{
	//{{AFX_DATA_INIT(CDlgRosenFileProp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT

}



void CDlgRosenFileProp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRosenFileProp)
	DDX_Control(pDX, IDC_TAB_MAIN, m_tabMAIN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRosenFileProp, CDialog)
	//{{AFX_MSG_MAP(CDlgRosenFileProp)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, OnSelchangeTabMain)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp メッセージ ハンドラ

BOOL CDlgRosenFileProp::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CWaitCursor	aCursor ;

	//--------------------------------
	//	子ダイアログを生成
	//--------------------------------
	{
		m_CDlgRosenFileProp_Rosen.Create( m_CDlgRosenFileProp_Rosen.IDD , this ) ;
		m_CDlgRosenFileProp_FontColor.Create( m_CDlgRosenFileProp_FontColor.IDD , this ) ;
		m_CDlgRosenFileProp_Diagram.Create( m_CDlgRosenFileProp_Diagram.IDD , this ) ;
	}
	// --------------------------------	
	//	タブにアイテムを追加
	//	(この処理は、子ダイアログ生成後に実行する必要があります。
	//	理由：子ダイアログのコントロールからタブ名を取得するため)
	// --------------------------------	
	{
		CString	aStr ;
		m_CDlgRosenFileProp_Rosen.GetDlgItem( IDC_STATIC_TABNAME )->GetWindowText( aStr ) ;
		TC_ITEM	LTcItem ;
		LTcItem.mask = TCIF_TEXT ;
		LTcItem.pszText = const_cast<char*>( (LPCTSTR)aStr ) ;
		m_tabMAIN.InsertItem( m_tabMAIN.GetItemCount() 
											, &LTcItem ) ;
	}	
	{
		CString	aStr ;
		m_CDlgRosenFileProp_FontColor.GetDlgItem( IDC_STATIC_TABNAME )->GetWindowText( aStr ) ;
		TC_ITEM	LTcItem ;
		LTcItem.mask = TCIF_TEXT ;
		LTcItem.pszText = const_cast<char*>( (LPCTSTR)aStr ) ;
		m_tabMAIN.InsertItem( m_tabMAIN.GetItemCount() 
											, &LTcItem ) ;
	}	
	{
		CString	aStr ;
		m_CDlgRosenFileProp_Diagram.GetDlgItem( IDC_STATIC_TABNAME )->GetWindowText( aStr ) ;
		TC_ITEM	LTcItem ;
		LTcItem.mask = TCIF_TEXT ;
		LTcItem.pszText = const_cast<char*>( (LPCTSTR)aStr ) ;
		m_tabMAIN.InsertItem( m_tabMAIN.GetItemCount() 
											, &LTcItem ) ;
	}	

	//--------------------------------
	//	子ダイアログの位置を決定
	//--------------------------------
	{
		WINDOWPLACEMENT	LWindowplacement ;
		CRect	LRect ;
		m_tabMAIN.GetWindowPlacement( &LWindowplacement ) ;
		LRect = LWindowplacement.rcNormalPosition ;
		m_tabMAIN.AdjustRect( FALSE , &LRect ) ;
		LWindowplacement.rcNormalPosition = LRect ;

		m_CDlgRosenFileProp_Rosen.SetWindowPlacement( &LWindowplacement ) ;
		m_CDlgRosenFileProp_Rosen.SetWindowPos( &m_tabMAIN
			, 0 , 0 , 0 , 0 , SWP_NOMOVE | SWP_NOSIZE ) ;

		m_CDlgRosenFileProp_FontColor.SetWindowPlacement( &LWindowplacement ) ;
		m_CDlgRosenFileProp_FontColor.SetWindowPos( &m_tabMAIN
			, 0 , 0 , 0 , 0 , SWP_NOMOVE | SWP_NOSIZE ) ;

		m_CDlgRosenFileProp_Diagram.SetWindowPlacement( &LWindowplacement ) ;
		m_CDlgRosenFileProp_Diagram.SetWindowPos( &m_tabMAIN
			, 0 , 0 , 0 , 0 , SWP_NOMOVE | SWP_NOSIZE ) ;
	}
	//--------------------------------
	//	編集対象データをUIに反映する
	//--------------------------------
	{
		m_CDlgRosenFileProp_Rosen.updateUI() ;
		m_CDlgRosenFileProp_FontColor.updateUI() ;
		m_CDlgRosenFileProp_Diagram.updateUI() ;
	}
	// --------------------------------
	UpdateChildWindowShow() ;

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgRosenFileProp::OnOK() 
{
	if ( m_CDlgRosenFileProp_Rosen.updatePropEditorData() < 0 )
	{
		m_tabMAIN.SetCurSel( 0 ) ;
		UpdateChildWindowShow() ;
	}
	else if ( m_CDlgRosenFileProp_FontColor.updatePropEditorData() < 0 )
	{
		m_tabMAIN.SetCurSel( 1 ) ;
		UpdateChildWindowShow() ;
	}
	else if ( m_CDlgRosenFileProp_Diagram.updatePropEditorData() < 0 )
	{
		m_tabMAIN.SetCurSel( 2 ) ;
		UpdateChildWindowShow() ;
	}
	else
	{
		CDialog::OnOK();
	}
}

void CDlgRosenFileProp::OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateChildWindowShow() ;
	
	*pResult = 0;
}
} //namespace ViewRosen
