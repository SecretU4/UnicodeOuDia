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
// CDlgDiaList.cpp : インプリメンテーション ファイル
//	$Id: CDlgDiaList.cpp 378 2016-11-16 21:10:54Z okm $

#include "stdafx.h"

#include "NsOu/OuNew.h"
#include "NsMu/CaMui.h"

#include "..\DiagramEdit.h"
#include "..\DedRosenFileData\EditCmd\CRfEditCmd_Dia.h"
#include "..\DedRosenFileData\EditCmd\CRfEditCmd_DiaProp.h"
#include "CDlgDiaList.h"
#include "CDlgDiaProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRosen{
using namespace std ;


/////////////////////////////////////////////////////////////////////////////
// CDlgDiaList ダイアログ

void CDlgDiaList::updateControl() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;

	//	m_listboxDia
	{
		bool bMustUpdate = false ;
		{
			const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

			if ( pCentDedDiaContGet->size() != m_listboxDia.GetCount() ){
				bMustUpdate = true ;
			}	else	{
				int idx ;
				for ( idx = 0 ; !bMustUpdate && idx < m_listboxDia.GetCount() ; idx ++ ){
					const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idx ) ;
					string	strDiaName = pCentDedDia->getName() ;
					CString	strItem ;
					m_listboxDia.GetText( idx , strItem ) ;
					if ( strDiaName != (LPCTSTR)strItem ){
						bMustUpdate = true ;
					}
				}
			}
		}
		//bMustUpdate = リストボックスの更新の必要があるなら真です
		if ( bMustUpdate )
		{	

				int idxSelect = m_listboxDia.GetCurSel() ;

				// --------------------------------
				//	リストボックスの内容を設定
				// --------------------------------
				const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;
				m_listboxDia.ResetContent() ;
				int idx ;
				for ( idx = 0 ; idx < pCentDedDiaContGet->size() ; 
						idx ++ )
				{
					const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idx ) ;
					string	strDiaName = pCentDedDia->getName() ;
					m_listboxDia.AddString( strDiaName.c_str() ) ;
				}
				
				// --------------------------------
				//	リストボックスの選択位置を設定
				// --------------------------------
				if ( 0 <= idxSelect && idxSelect < m_listboxDia.GetCount() ){
					m_listboxDia.SetCurSel( idxSelect ) ;
				}
		}
	}
	//IDC_BUTTON_PROP
	{
		BOOL	bEnable = FALSE ;
		int idxSel = m_listboxDia.GetCurSel() ;
		if ( 0 <= idxSel && idxSel < m_listboxDia.GetCount() ){
			bEnable = TRUE ;
		}
		GetDlgItem( IDC_BUTTON_PROP )->EnableWindow( bEnable ) ;
	}
	//IDC_BUTTON_DELETE
	{
		BOOL	bEnable = FALSE ;
		int idxSel = m_listboxDia.GetCurSel() ;
		if ( 0 <= idxSel && idxSel < m_listboxDia.GetCount() ){
			bEnable = TRUE ;
		}
		GetDlgItem( IDC_BUTTON_DELETE )->EnableWindow( bEnable ) ;
	}
	//IDC_BUTTON_UP
	{
		BOOL	bEnable = FALSE ;
		int idxSel = m_listboxDia.GetCurSel() ;
		if ( 0 < idxSel && idxSel < m_listboxDia.GetCount() ){
			bEnable = TRUE ;
		}
		GetDlgItem( IDC_BUTTON_UP )->EnableWindow( bEnable ) ;
	}
	//IDC_BUTTON_DOWN
	{
		BOOL	bEnable = FALSE ;
		int idxSel = m_listboxDia.GetCurSel() ;
		if ( 0 <= idxSel && idxSel < m_listboxDia.GetCount() - 1 ){
			bEnable = TRUE ;
		}
		GetDlgItem( IDC_BUTTON_DOWN )->EnableWindow( bEnable ) ;
	}
}
void CDlgDiaList::execDlgDiaProp() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

	string	strDiaNamePrev ;
	int idx = m_listboxDia.GetCurSel() ;
	if ( !( 0 <= idx && idx < pCentDedDiaContGet->size() ) ){
		return ;
	}	else	{
		const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idx ) ;
		strDiaNamePrev = pCentDedDia->getName() ;
	}
	//idx = 変更するダイヤのインデクス
	//strDiaNamePrev = 変更するダイヤのプロパティ(名称)

	CDlgDiaProp	aDlg( strDiaNamePrev , this ) ;
	if ( aDlg.DoModal() == IDOK ){
		string strDiaName = aDlg.getName() ;
		
		// --------------------------------
		//	同一名のダイヤは、エラーにします。
		// --------------------------------
		if ( strDiaName != strDiaNamePrev ){ 
			int idxDia = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( strDiaName ) ;
			if ( idxDia >= 0 ){
				CString strError ;
				strError.Format( IDS_ERR_DiaNameDuplex , strDiaName.c_str() ) ;
				MessageBox( strError , NULL , MB_OK | MB_ICONERROR ) ;
				return ;
			}
		}
		// --------------------------------
		//	コマンドオブジェクトを生成・実行
		// --------------------------------
		{
			OuNew<CRfEditCmd>	pCmd( 
				new CRfEditCmd_DiaProp( 
					idx , strDiaName ) ) ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;
			
		}

		// --------------------------------
		//	ダイアログの更新
		// --------------------------------
		updateControl() ;
	}
	
}


// ----------------------------------------------------------------
CDlgDiaList::CDlgDiaList(
		CDiagramEditDoc* pCDiagramEditDoc ,
		CWnd* pParent )
	: CDialog(CDlgDiaList::IDD, pParent)
	, m_pCDiagramEditDoc( pCDiagramEditDoc ) 
{
	//{{AFX_DATA_INIT(CDlgDiaList)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void CDlgDiaList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDiaList)
	DDX_Control(pDX, IDC_LIST_Dia, m_listboxDia);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDiaList, CDialog)
	//{{AFX_MSG_MAP(CDlgDiaList)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_PROP, OnButtonProp)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UP, OnButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, OnButtonDown)
	ON_LBN_SELCHANGE(IDC_LIST_Dia, OnSelchangeLISTDia)
	ON_LBN_DBLCLK(IDC_LIST_Dia, &CDlgDiaList::OnLbnDblclkListDia)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDiaList メッセージ ハンドラ

BOOL CDlgDiaList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	updateControl() ;
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgDiaList::OnOK() 
{
	//Return キーによるクローズは抑止します。	
	//CDialog::OnOK();
}

void CDlgDiaList::OnCancel() 
{
	CDialog::OnCancel();
}

void CDlgDiaList::OnButtonNew() 
{
	const CentDedRosen*	pCentDedRosen = m_pCDiagramEditDoc->
			getCDedRosenFileData()->getCentDedRosen() ;


	CDlgDiaProp	aDlg( "" , this ) ;
	if ( aDlg.DoModal() == IDOK ){
		string strDiaName = aDlg.getName() ;

		// --------------------------------
		//	同一名のダイヤは、エラーにします。
		// --------------------------------
		int idxDia = pCentDedRosen->getCentDedDiaCont()->findCentDedDiaByName( strDiaName ) ;
		if ( idxDia >= 0 ){
			CString strError ;
			strError.Format( IDS_ERR_DiaNameDuplex , strDiaName.c_str() ) ;
			MessageBox( strError , NULL , MB_OK | MB_ICONERROR ) ;
			return ;
		}
		// --------------------------------
		//	コマンドオブジェクトを生成・実行
		// --------------------------------
		{
			CentDedDiaCont	aCentDedDiaCont ;
			aCentDedDiaCont.insert( CentDedDia( strDiaName , 
				pCentDedRosen->getCentDedEkiCont()->getMuPtr()->size()  ) ) ;
			OuNew<CRfEditCmd>	pCmd( 
				new CRfEditCmd_Dia( INT_MAX , 0 , aCentDedDiaCont ) 
				) ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;
		}

		
		// --------------------------------
		//	ダイアログの更新
		// --------------------------------
		//	リストボックスにアイテムを追加
		m_listboxDia.AddString( strDiaName.c_str() ) ;
		m_listboxDia.SetCurSel( m_listboxDia.GetCount() - 1 ) ;

		updateControl() ;
		
	}
	
}

void CDlgDiaList::OnButtonProp() 
{
	execDlgDiaProp() ;	
}

void CDlgDiaList::OnButtonDelete() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

	string	strDiaName ;
	int idx = m_listboxDia.GetCurSel() ;
	if ( !( 0 <= idx && idx < pCentDedDiaContGet->size() ) ){
		return ;
	}	else	{
		const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idx ) ;
		strDiaName = pCentDedDia->getName() ;
	}
	//idx = 変更するダイヤのインデクス

	// --------------------------------
	//	削除の確認
	// --------------------------------
	{
		CString	strMsg ;
		CString	strMsgFormat ;
		CString	strCaption ;
		GetDlgItemText( IDC_STATIC_ERROR_DeleteDiaPrompt , strMsgFormat ) ;
		GetDlgItemText( IDC_STATIC_ERROR_DeleteDiaPrompt2 , strCaption ) ;
		strMsg.Format( strMsgFormat , strDiaName.c_str() ) ;
		int iResult = MessageBox( strMsg , strCaption , MB_OKCANCEL | MB_ICONQUESTION ) ;
		if ( iResult != IDOK ){
			return ;
		}
	}	
		// --------------------------------
		//	コマンドオブジェクトを生成・実行
		// --------------------------------
		{
			CentDedDiaCont	aCentDedDiaCont ;
			OuNew<CRfEditCmd>	pCmd( 
				new CRfEditCmd_Dia( idx , 1 , aCentDedDiaCont ) 
				) ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;
		}
	// --------------------------------
	//	ダイアログの更新
	// --------------------------------
	updateControl() ;
}

void CDlgDiaList::OnButtonUp() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

	string	strDiaName ;
	int idx = m_listboxDia.GetCurSel() ;
	if ( !( 0 < idx && idx < pCentDedDiaContGet->size() ) ){
		return ;
	}
	// --------------------------------
	//	コマンドオブジェクトを生成・実行
	// --------------------------------
	{
		CentDedDiaCont	aCentDedDiaCont;
		aCentDedDiaCont.insert( *pCentDedDiaContGet->get( idx ) ) ; 
		aCentDedDiaCont.insert( *pCentDedDiaContGet->get( idx - 1 ) ) ; 

		OuNew<CRfEditCmd>	pCmd( 
			new CRfEditCmd_Dia( idx - 1  , 2 , aCentDedDiaCont ) 
			) ;
		int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		ASSERT( iResult >= 0 ) ;
	}
	// --------------------------------
	//	ダイアログの更新
	// --------------------------------
	m_listboxDia.SetCurSel( idx - 1 ) ;
	updateControl() ;
}

void CDlgDiaList::OnButtonDown() 
{
	const CentDedRosen* pCentDedRosen =  m_pCDiagramEditDoc->
		getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr() ;

	string	strDiaName ;
	int idx = m_listboxDia.GetCurSel() ;
	if ( !( 0 <= idx && idx < pCentDedDiaContGet->size() - 1 ) ){
		return ;
	}
	// --------------------------------
	//	コマンドオブジェクトを生成・実行
	// --------------------------------
	{
		CentDedDiaCont	aCentDedDiaCont ;
		aCentDedDiaCont.insert( *pCentDedDiaContGet->get( idx + 1 ) ) ; 
		aCentDedDiaCont.insert( *pCentDedDiaContGet->get( idx  ) ) ; 

		OuNew<CRfEditCmd>	pCmd( 
			new CRfEditCmd_Dia( idx , 2 , aCentDedDiaCont ) 
			) ;
		int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		ASSERT( iResult >= 0 ) ;
	}
	// --------------------------------
	//	ダイアログの更新
	// --------------------------------
	m_listboxDia.SetCurSel( idx + 1 ) ;
	updateControl() ;
}

void CDlgDiaList::OnSelchangeLISTDia() 
{
	updateControl() ;
	
}

void CDlgDiaList::OnLbnDblclkListDia()
{
	execDlgDiaProp() ;
}
} //namespace ViewRosen
