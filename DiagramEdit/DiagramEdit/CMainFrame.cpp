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
// CMainFrame.cpp : CMainFrame クラスの動作の定義を行います。
//	$Id: CMainFrame.cpp 295 2016-06-11 05:14:13Z okm $
/** @file */

#include "stdafx.h"

#include "NsOu/OuNew.h"
#include "str/vectorToFile.h"
#include "str/strToWstr.h"
#include "str/tstring.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfoContainer.h"
#include "str\OuPropertiesText\CConvNodeContainer.h"


#include "DiagramEdit.h"
#include "CMainFrame.h"
#include "DedRosenFileData\EditCmd\EditCmd.h"
#include "DedRosenFileData\CconvCDedRosenFileData.h"
#include "ViewRosen\CDlgRosenFileProp.h"
#include "ViewRosen\CDlgDiaList.h"
#include "ViewRosen\CDlgRosenCreateSubRosen.h"
#include "ViewRosen\CDlgRosenfileInsert.h"

using namespace std ;
using namespace OuLib::Str ;
using namespace OuLib::Str::OuPropertiesText ;
using namespace OuLib::Str::OuPropertiesText::ErrorInfo ;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame
// --------------------------------
//	CFrameWnd
// --------------------------------
void CMainFrame::RecalcLayout( BOOL bNotify )
{
	CWndSplitBarV::CMDIFrameWnd_RecalcLayout( this , 
		&m_CDlgRosenView , &m_CWndSplitBarV , bNotify ) ;
}
void CMainFrame::OnSetPreviewMode( BOOL bPreview, CPrintPreviewState* pModeStuff )
{
	m_CDlgRosenView.EnableWindow( !bPreview ) ;
	super::OnSetPreviewMode(  bPreview, pModeStuff ) ;
}
	// --------------------------------
	//@name メニューコマンドの下請関数
	// --------------------------------
//	[ファイル]-[路線ファイルの組入れ]
int CMainFrame::OnFileRosenFileInsert_Process( BOOL bQueryEnable ) 
{
	int iRv = 0; 
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	const CDedRosenFileData* pRosenFileDataCurrent = getCDiagramEditDoc()->getCDedRosenFileData() ;
	if ( iRv >= 0 )
	{
		//	駅が2つ未満なら、このコマンドは使用できません。
		const CentDedEkiCont* pEkiCont = pRosenFileDataCurrent->getCentDedRosen()->getCentDedEkiCont() ;
		if ( pEkiCont->size() < 2 )
		{
			iRv = -21 ;	//	駅が2つ未満なら、このコマンドは使用できません。
		}
	}

	if ( bQueryEnable || iRv < 0 )
	{
		return iRv ;
	}
	// ****************************************************************
	//	コマンドの実行
	// ****************************************************************
	CString strErrorMsgSub ;

	//(2)[路線ファイルの組入れ]ダイアログ
	CString strOudFilename ;
	int iEkiIndexToInsert = -1 ;
	{
		const CentDedEkiCont* pCentDedEkiCont = pRosenFileDataCurrent->getCentDedRosen()->getCentDedEkiCont() ;
		CDlgRosenfileInsert	aDlg( *pCentDedEkiCont , this ) ;
		int iResult = aDlg.DoModal() ;
		if ( iResult != IDOK )
		{
			iRv = -1 ;	//	ユーザーによるキャンセル
		}
		else
		{
			iEkiIndexToInsert = aDlg.getEkiIndexToInsert() ;
			strOudFilename = aDlg.getOudFilenameToInsert() ;
		}
	}
	//strOudFilename = ファイルダイアログで指定された .oud ファイル名
	//iEkiIndexToInsert = 組入れ先駅Index
	
	// --------------------------------
	//	.oudファイルを読み込み
	//	CDedRosenFileData を生成
	// --------------------------------
	CDedRosenFileData	rosenfiledataAdd ;
	if ( iRv >= 0 )
	{
		string strFileContent ;
		if ( iRv >= 0 )
		{
			int iResult = stringFromFile( 
				&strFileContent , 
				stringOf( (LPCTSTR)strOudFilename ) ) ;
			if ( iResult < 0 )
			{
				iRv = -11 ;	//	ファイルがみつかりません。
			}
		}
		if ( iRv >= 0 )
		{
			CconvCDedRosenFileData	aConv ;
			COuErrorInfoContainer	aCOuErrorInfoContainer ;
			int iResult = aConv.CDedRosenFileData_from_string( 
				&rosenfiledataAdd , 
				strFileContent , 
				&aCOuErrorInfoContainer ) ;
			if ( iResult < 0 )
			{
				strErrorMsgSub = aCOuErrorInfoContainer.toOuErrorInfoText().c_str() ;
				iRv = -12 ;	//	ファイルの形式が不正です。
			}
		}
	}
	//rosenfiledataAdd = 追加する .oud のデータを保持しています。

	// --------------------------------
	//	rosenfiledataCurrent の路線の末尾に
	//	rosenfiledataAdd の路線を追加
	// --------------------------------
	CDedRosenFileData rosenfiledataCurrent = *getCDiagramEditDoc()->getCDedRosenFileData() ;
	if ( iRv >= 0 )
	{
		CentDedRosen* prosenCurrent = rosenfiledataCurrent.getCentDedRosen() ;
		CentDedRosen* prosenAdd = rosenfiledataAdd.getCentDedRosen() ; 
		prosenCurrent->insert( *prosenAdd , iEkiIndexToInsert ) ;

		Ou< CRfEditCmd > pCmd = OuNew< CRfEditCmd >( new
			CRfEditCmd_Rosen( *prosenCurrent ) ) ;
		getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
	}
	// ****************************************************************
	//	エラーメッセージ
	// ****************************************************************
	CString strErrorMsg ;
	if ( iRv < 0 )
	{
		switch( iRv )
		{
		case -1 :	//	キャンセル
			break ;
		case -11 :	//	ファイルがみつかりません。
			strErrorMsg.Format( IDS_ERR_FILENOTFOUND , strOudFilename ) ;
		case -12 :	//	ファイルの形式が不正です。
			strErrorMsg.Format( IDS_ERR_FILEFORMAT , strOudFilename ) ;
		default:
			strErrorMsg.Format( _T( "Error(%d)" ) , iRv ) ;
			break ;
		}
		if ( !strErrorMsgSub.IsEmpty() )
		{

			strErrorMsg += _T( "\n" ) ;
			strErrorMsg += strErrorMsgSub ;
		}
	}
	if ( !strErrorMsg.IsEmpty() )
	{
		MessageBox( strErrorMsg , NULL , MB_ICONSTOP ) ;
	}
	return iRv ;
}

//[ファイル]-[路線ファイルの切り出し]
int CMainFrame::OnFileRosenCreateSubRosen_Process( BOOL bQueryEnable ) 
{
	int iRv = 0;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	{
		int iEkiCount = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont()->size() ;
		if ( iEkiCount < 3 )
		{
			iRv = -31 ;	//	3駅未満の路線では、使用できません。
		}
	}
	if ( bQueryEnable || iRv < 0 )
	{
		return iRv ;
	}
	// ****************************************************************
	//	コマンドの実行
	// ****************************************************************
	CString strErrorMsgSub ;
	CDedRosenFileData rosenfiledataCurrent = *getCDiagramEditDoc()->getCDedRosenFileData() ;

	//(2)[一部駅間の路線ファイルを作成]ダイアログ
	int iEkiIndex = 0 ;
	int iEkiCount = 0 ;
	if ( iRv >= 0 )
	{
		const CentDedEkiCont& aCentDedEkiCont = *rosenfiledataCurrent.getCentDedRosen()->getCentDedEkiCont() ;
		CDlgRosenCreateSubRosen	aDlg( aCentDedEkiCont , this ) ;
		int iResult = aDlg.DoModal() ;
		if ( iResult != IDOK )
		{
			iRv = -1 ;	//	ユーザーによるキャンセル
		}
		else
		{
			iEkiIndex = aDlg.getSihatsuEkiIndex() ;
			iEkiCount = aDlg.getSyuuchakuEkiIndex() + 1 - iEkiIndex ;
		}
	}
	//iEkiIndex = 新しい路線ファイルの、始発駅Index
	//iEkiCount = 新しい路線ファイルの駅数


	//　名前をつけて保存ダイアログ
	CString strNewOudFilename ;
	if ( iRv >= 0 )
	{
		CString	strExt ;
		getCDiagramEditApp()->pRootDoctmpl()->GetDocString( strExt , CDocTemplate::filterExt ) ;
		CFileDialog	aDlg( FALSE , strExt , NULL ,
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST,
			getCDiagramEditApp()->getCFileDialogOudFilter() , this ) ;
		int iResult = aDlg.DoModal() ;
		if ( iResult != IDOK )
		{
			iRv = -1 ;	//	ユーザーによるキャンセル
		}
		else
		{
			strNewOudFilename = aDlg.GetPathName() ;
		}
	}
	//strNewOudFilename = 新しい路線ファイル名

	// --------------------------------
	//	rosenfiledataCurrent の路線から、
	//	一部区間の路線
	//	rosenfiledataSub を生成
	// --------------------------------
	CDedRosenFileData	rosenfiledataSub ;
	if ( iRv >= 0 )
	{
		rosenfiledataSub = rosenfiledataCurrent ;
		*rosenfiledataSub.getCentDedRosen() = 
			rosenfiledataCurrent.getCentDedRosen()->createSubRosen( iEkiIndex , iEkiCount ) ;
	}
	// --------------------------------
	//	CDedRosenFileData を
	//	.oudファイルに保存
	// --------------------------------
	OuPropertiesText::CNodeContainer	aCNodeContainer ;  
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData aConv ;
		int iResult = aConv.CDedRosenFileData_to_OuPropertiesText( 
			&rosenfiledataSub , 
			&aCNodeContainer ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	路線データの変換に失敗しました。
		}
	}
	// --------------------------------
	//	FileTypeAppComment を付与
	// --------------------------------
	if ( iRv >= 0 )
	{
		string strFileTypeAppComment ;
		strFileTypeAppComment += AfxGetAppName() ;
		strFileTypeAppComment += " Ver. " ;
		strFileTypeAppComment += getCDiagramEditApp()->getProgramVer() ;
		aCNodeContainer.setValue( nameFileTypeAppComment , strFileTypeAppComment );
	}
	// --------------------------------
	//	ファイルに保存
	// --------------------------------
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer aConv ;
		string strOudContent = aConv.encode( &aCNodeContainer ) ;
		int iResult = stringToFile( 
			strOudContent , 
			stringOf( (LPCTSTR)strNewOudFilename ) ) ;
		//iResult 
		//	-1: ファイルがオープンできません。
		//	-2 ; // 書き込みに失敗しました。 
		if ( iResult < 0 )
		{
			iRv = iResult - 20 ;
		}
		//iRv
		//	-21: ファイルがオープンできません。
		//	-22 ; // 書き込みに失敗しました。 
		
	}
	// ****************************************************************
	//	エラーメッセージ
	// ****************************************************************
	CString strErrorMsg ;
	if ( iRv < 0 )
	{
		switch( iRv )
		{
		case -21:	//	ファイルがオープンできません。
			strErrorMsg.Format( IDS_ERR_FILECREATE , (LPCTSTR)strNewOudFilename ) ;
			break ;
		case -22: // 書き込みに失敗しました。 
			strErrorMsg.Format( IDS_ERR_FILEWRITE , (LPCTSTR)strNewOudFilename ) ;
			break ;
		case -1: // ユーザーによるキャンセル
			break ;
		default:
			strErrorMsg.Format( _T( "Error(%d)" ) , iRv ) ;
			break ;
		}
		if ( !strErrorMsgSub.IsEmpty() )
		{

			strErrorMsg += _T( "\n" ) ;
			strErrorMsg += strErrorMsgSub ;
		}
	}
	if ( !strErrorMsg.IsEmpty() )
	{
		MessageBox( strErrorMsg , NULL , MB_ICONSTOP ) ;
	}
	return iRv ;

}

// ********************************
//	CMainFrame
// ********************************
	// ********************************
	//@name	操作
	// ********************************
	/**
	 *	『路線ファイルのプロパティ』ダイアログを開きます。
	 *
	 *	ダイアログが『OK』で閉じられたら、路線ファイルの
	 *	プロパティを『ルートドキュメント』 CDiagramEditDoc 
	 *	に反映します。
	 * @return
	 *	0 以上は成功、エラーなら負の数です。 
	 *	-	1 ;	//	『OK』が押されて、入力内容が
	 *		『ルートドキュメント』に反映しました。
	 *	-	0 ;	//	『Cancel』が押されました。
	 *	
	 */
int CMainFrame::execCDlgRosenFileProp() 
{
	int iRv = 0 ;
	
	// --------------------------------
	//	ビューの編集内容をルートドキュメントに反映
	//	（特に、コメントビュー）
	// --------------------------------
	getCDiagramEditDoc()->UpdateAllSubDocviews( NULL , LHINT_SUBVIEW_TO_ROOTDOC ) ;
	
	// --------------------------------
	const CDedRosenFileData*	pCDedRosenFileData = getCDiagramEditDoc()->getCDedRosenFileData() ;

	CDlgRosenFileProp	aPps( 
		pCDedRosenFileData , 
		this ) ;
	int iResult = aPps.DoModal() ;
	if ( iResult == IDOK ){
		// --------------------------------
		//	コマンドオブジェクトの生成・実行
		// --------------------------------
		{
			Ou<CRfEditCmd> pCmd = aPps.getPropEditorData()->createEditCmd() ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;

		}

		iRv = 1 ;
	}
	return ( iRv ) ;
}
int CMainFrame::execCDlgDiaList() 
{
	int iRv = 0 ;

	CDlgDiaList	aDlg( getCDiagramEditDoc() , &m_CDlgRosenView ) ;
	aDlg.DoModal() ;
	
	return iRv ;
}

CView* CMainFrame::getMDIChildActiveView() 
{
	CView *pView = NULL ;
	{
		CMDIFrameWnd *pFrame = this ;
		CMDIChildWnd *pChild = pFrame->MDIGetActive();
		if ( pChild != NULL ){
			pView = pChild->GetActiveView();
		}
	}
	return pView ;
}

// ----------------------------------------------------------------



IMPLEMENT_DYNAMIC(CMainFrame, CHidemdiMainfrm)

BEGIN_MESSAGE_MAP(CMainFrame, CHidemdiMainfrm)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_ROSEN_FILE_PROP, OnRosenFileProp)
	ON_COMMAND(ID_WINDOW_ROSEN_VIEW, OnWindowRosenView)
	ON_COMMAND(ID_ROSEN_DIALIST, OnRosenDialist)
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_PasteZoubun, OnUpdateINDICATOR_PasteZoubun)
	ON_COMMAND(ID_FILE_ROSEN_FILE_INSERT, &CMainFrame::OnFileRosenfileInsert)
	ON_UPDATE_COMMAND_UI(ID_FILE_ROSEN_FILE_INSERT, &CMainFrame::OnUpdateFileRosenfileInsert)
	ON_COMMAND(ID_FILE_ROSEN_CREATE_SUB_ROSEN, &CMainFrame::OnFileRosenCreateSubRosen)
	ON_UPDATE_COMMAND_UI(ID_FILE_ROSEN_CREATE_SUB_ROSEN, &CMainFrame::OnUpdateFileRosenCreateSubRosen)
//	ON_COMMAND(ID_MENUITEM_OPEN, &CMainFrame::OnMenuitemOpen)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ステータス ライン インジケータ
	ID_INDICATOR_PasteZoubun , //	貼り付け移動量
	ID_INDICATOR_KANA,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの構築/消滅

CMainFrame::CMainFrame()
{
	// TODO: この位置にメンバの初期化処理コードを追加してください。
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CHidemdiMainfrm::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // 作成に失敗
	}

	//attention Diagramツールバーは、MainFrameに統合
	//
	//	if (!m_wndToolBarDiagram.CreateEx(this, TBSTYLE_FLAT, 
	//		WS_CHILD | WS_VISIBLE | CBRS_TOP
	//		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//		!m_wndToolBarDiagram.LoadToolBar(IDR_DOCVIEW_Diagram))
	//	{
	//		TRACE0("Failed to create toolbar\n");
	//		return -1;      // 作成に失敗
	//	}



	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // 作成に失敗
	}

	// TODO: ツール バーをドッキング可能にしない場合は以下の３行を削除
	//       してください。
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//attention Diagramツールバーは、MainFrameに統合
	//	m_wndToolBarDiagram.EnableDocking(CBRS_ALIGN_ANY) ;
	//	DockControlBar(&m_wndToolBarDiagram);


	// ----------------------------------------------------------------
	// --------------------------------
	//	左側ペイン	
	// --------------------------------
	{
		m_CDlgRosenView.Create( m_CDlgRosenView.IDD , this ) ;
		m_CDlgRosenView.ShowWindow( SW_SHOW ) ;
	}

	// --------------------------------
	//	左側ペインとの間のスプリットバー	
	// --------------------------------
	{
		m_CWndSplitBarV.Create( this , &m_CDlgRosenView , 0 ) ;
	}



	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CHidemdiMainfrm::PreCreateWindow(cs) )
		return FALSE;
	// TODO: この位置で CREATESTRUCT cs を修正して、Window クラスやスタイルを
	//       修正してください。

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの診断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CHidemdiMainfrm::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CHidemdiMainfrm::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame メッセージ ハンドラ


void CMainFrame::OnRosenFileProp() 
{
	execCDlgRosenFileProp() ;
}


/**
 *	[ウインドウ]→[ペインの切り替え]
 *	メニューコマンドの応答関数です。
 */
void CMainFrame::OnWindowRosenView() 
{
	if ( ::IsChild( m_CDlgRosenView.GetSafeHwnd() , ::GetFocus() ) ){
		//	左ペインにフォーカスがあるとき
		//	MDIChildウインドウにフォーカスを移動します。
		CMDIChildWnd* pActive = MDIGetActive() ;
		if ( pActive != NULL ){
			pActive->SetFocus() ;
		}
	}	else	{
		//	左ペインにフォーカスがないとき
		//	左ペインにフォーカスを移動します。
		m_CDlgRosenView.SetFocus() ;
	}
}
/**
 *	『貼り付け移動量』ステータスバーへのテキストを設定します。
 *
 * [オーバライド]
 *	空文字列を設定します。
 *
 * @note
 *	CJikokuhyouView がアクティブなときは、
 *	CJikokuhyouView::OnUpdateINDICATOR_PasteZoubun()
 *	で設定されます。
 */
void CMainFrame::OnUpdateINDICATOR_PasteZoubun(CCmdUI *pCmdUI)
{
    pCmdUI->Enable( FALSE ); 
    pCmdUI->SetText( "" ); 

}

void CMainFrame::OnRosenDialist() 
{
	execCDlgDiaList() ;	
}


//	[ファイル]-[路線ファイルの組入れ]
void CMainFrame::OnFileRosenfileInsert()
{
	OnFileRosenFileInsert_Process( FALSE ) ;
}

void CMainFrame::OnUpdateFileRosenfileInsert(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnFileRosenFileInsert_Process( TRUE ) >= 0 ) ;
}

//	[ファイル]-[路線ファイルの切り出し]
void CMainFrame::OnFileRosenCreateSubRosen()
{
	OnFileRosenCreateSubRosen_Process( FALSE ) ;
}

void CMainFrame::OnUpdateFileRosenCreateSubRosen(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnFileRosenCreateSubRosen_Process( TRUE ) >= 0 ) ;
}

