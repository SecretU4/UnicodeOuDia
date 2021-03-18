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
// CDlgRosenView.cpp : インプリメンテーション ファイル
//	$Id: CDlgRosenView.cpp 295 2016-06-11 05:14:13Z okm $

#include "stdafx.h"

#include <deque>

#include "NsOu/dynamic_castOu.h"
#include "TreeCtrl\CaTreeCtrl.h"

#include "..\DiagramEdit.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "CDlgRosenView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRosen{

using namespace std ;
using OuMfc::TreeCtrl::CaTreeCtrl ;

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenView ダイアログ
// --------------------------------
//@name	下請関数
// --------------------------------
int CDlgRosenView::onEnterItem( HTREEITEM aItem  , int iAction ) 
{
	int iRv = 0 ;

	CaTreeCtrl::Itemlocation	aItemPos ;
	if ( aItem != NULL )
	{
		CaTreeCtrl	aCaTreeCtrl( &m_treeROSEN ) ;
		aCaTreeCtrl.HTREEITEM_to_Itemlocation( aItem , &aItemPos ) ;
	}
	//	路線
	if ( aItemPos.size() == 1 && 
			aItemPos[0] == 0 && 
			iAction != 1 )
	{
		//	『路線ファイルのプロパティ』
		//	ダイアログ（モーダル）を起動します。
		getCDiagramEditApp()->getCMainFrame()->execCDlgRosenFileProp() ;

		iRv = 1 ;
	}
	//	駅
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 0 &&
			iAction != 2 )
	{
		//	『駅』ビューを開きます。
		getCDiagramEditApp()->openCEkiDoc() ;

		iRv = 1 ;
	}
	//	列車種別
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 1 &&
			iAction != 2 )
	{
		//	『列車種別』ビューを開きます。
		getCDiagramEditApp()->openCRessyasyubetsuDoc() ;

		iRv = 1 ;
	}
	//	ダイヤ
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 &&
			iAction != 1 )
	{
		//	『ダイヤ一覧』ダイアログ(モーダル)を開きます。
		getCDiagramEditApp()->getCMainFrame()->execCDlgDiaList() ;

		iRv = 1 ;
	}
	//	時刻表＜下り＞
	if ( aItemPos.size() == 4 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 && 
			aItemPos[3] == 0 &&
			iAction != 2 )
	{
		//	『時刻表』ビューを開きます。
		const CentDedDia*	pCentDedDia = getCDiagramEditDoc()->getCDedRosenFileData()->
			getCentDedRosen()->getCentDedDiaCont()->getMuPtr()->get( aItemPos[2] ) ;
		if ( pCentDedDia != NULL )
		{
			getCDiagramEditApp()->openCJikokuhyouDoc( 
				pCentDedDia , 
				Ressyahoukou_Kudari , 
				NULL ) ;
		} 
		iRv = 1 ;
	}
	//	時刻表＜上り＞
	if ( aItemPos.size() == 4 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 &&
			aItemPos[3] == 1 &&
			iAction != 2 )
	{
		//	『時刻表』ビューを開きます。
		const CentDedDia*	pCentDedDia = getCDiagramEditDoc()->getCDedRosenFileData()->
			getCentDedRosen()->getCentDedDiaCont()->getMuPtr()->get( aItemPos[2] ) ;
		if ( pCentDedDia != NULL ){
			getCDiagramEditApp()->openCJikokuhyouDoc( 
				pCentDedDia , 
				Ressyahoukou_Nobori , 
				NULL ) ;
		} 
		iRv = 1 ;
	}
	//	ダイヤグラム
	if ( aItemPos.size() == 4 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 2 && 
			aItemPos[3] == 2 &&
			iAction != 2 )
	{
		//	『ダイヤグラム』ビューを開きます。
		const CentDedDia*	pCentDedDia = getCDiagramEditDoc()->getCDedRosenFileData()->
			getCentDedRosen()->getCentDedDiaCont()->getMuPtr()->get( aItemPos[2] ) ;
		if ( pCentDedDia != NULL ){
			getCDiagramEditApp()->openCDedDiagramDoc( pCentDedDia ) ;
		} 
		iRv = 1 ;
	}
	//	コメント
	if ( aItemPos.size() == 2 && 
			aItemPos[0] == 0 && 
			aItemPos[1] == 3 &&
			iAction != 2 )
	{
		//	『コメント』ビューを開きます。
		{
			getCDiagramEditApp()->openCDedCommentDoc() ;
		} 
		iRv = 1 ;
	}
	return ( iRv ) ;
}

	// ********************************
	//@name	CWnd
	// ********************************
BOOL CDlgRosenView::PreTranslateMessage(MSG* pMsg)
{

	// -------------------------------- 
	//        ダイアログ(上のコントロール)にフォーカスがある状態で 
	// アクセラレータによるメニューコマンドへのアクセスを 
	//        行うためには、メインフレームウインドウに PreTranslateMessage() を 
	//        委譲しなくてはなりません。 
	if ( WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST ) 
	{ 
		if ( AfxGetMainWnd()->PreTranslateMessage( pMsg ) ) 
		{ 
			return TRUE ; 
		} 
	} 
	// -------------------------------- 
	return CDialog::PreTranslateMessage(pMsg); 
}

// ********************************
//	CDlgRosenView
// ********************************
	// ********************************
	//@name 操作
	// ********************************
void CDlgRosenView::UpdateROSEN( const CentDedRosen* pCentDedRosen ) 
{
	// --------------------------------
	//	現在の選択アイテムを取得
	// --------------------------------
	CaTreeCtrl::Itemlocation	aItemPos ;
	{
		HTREEITEM	hItem = m_treeROSEN.GetSelectedItem() ;
		if ( hItem != NULL ){
			CaTreeCtrl	aCaTreeCtrl( &m_treeROSEN ) ;
			aCaTreeCtrl.HTREEITEM_to_Itemlocation( hItem , &aItemPos ) ;
		}
	}


	// --------------------------------
	//	一旦、全アイテムを破棄
	// --------------------------------
	m_treeROSEN.DeleteAllItems() ;

	// --------------------------------
	//	□路線  ピクトグラムの列車
	// --------------------------------
	HTREEITEM itemRosen = NULL ;
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_ROSEN ) ;
		
		string	strRosenName = pCentDedRosen->getName() ;
		if ( strRosenName.size() > 0 ){
			strItem = strRosenName.c_str() ;
		}

		int nImage = 0 ;
		int nSelectedImage = 0 ;

		itemRosen = m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , TVI_ROOT , TVI_LAST ) ;
		m_treeROSEN.SetItemState( itemRosen , TVIS_EXPANDED  ,  TVIS_EXPANDED  ) ;
	}

	// --------------------------------
	//	□駅  地図記号の駅
	// --------------------------------
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_EKI ) ;
		int nImage = 1 ;
		int nSelectedImage = 1 ;

		m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , itemRosen , TVI_LAST ) ;
	}
	// --------------------------------
	//	□列車種別  国鉄形式のサボ
	// --------------------------------
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_RESSYASYUBETSU ) ;
		int nImage = 2 ;
		int nSelectedImage = 2 ;

		m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , itemRosen , TVI_LAST ) ;
	}
	// --------------------------------
	//	□ダイヤ      駅時刻表をかたどったアイコン
	// --------------------------------
	HTREEITEM itemDia = NULL ;
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_DIA ) ;
		int nImage = 3 ;
		int nSelectedImage = 3 ;

		itemDia = m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , itemRosen , TVI_LAST ) ;
		m_treeROSEN.SetItemState( itemDia , TVIS_EXPANDED ,  TVIS_EXPANDED ) ;

	}
	//itemDia = □『ダイヤ』アイテム

	// --------------------------------
	//	□(ダイヤ名)  駅時刻表をかたどったアイコン
	// --------------------------------
	{
		int nImage = 4 ;
		int nSelectedImage = 4 ;
		
		const CentDedRosen*	pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedDia*>* pCentDedDiaContGet = pCentDedRosen->getCentDedDiaCont()->getMuPtr();

		int idxDia ;
		for ( idxDia = 0 ; idxDia < pCentDedDiaContGet->size() ; idxDia ++ ){
			const CentDedDia*	pCentDedDia = pCentDedDiaContGet->get( idxDia ) ;
			string	strDiaName = pCentDedDia->getName() ;

			HTREEITEM itemDiaName = m_treeROSEN.InsertItem( strDiaName.c_str() , 
				nImage , nSelectedImage , itemDia , TVI_LAST ) ;
			m_treeROSEN.SetItemState( itemDiaName , TVIS_EXPANDED ,  TVIS_EXPANDED ) ;

			// --------------------------------
			//	□下り時刻表/上り時刻表  矢印
			// --------------------------------
			{
				CString	strItem ;
				strItem.LoadString( IDS_WORD_KUDARIJIKOKUHYOU ) ;
				int nImage = 5 ;
				int nSelectedImage = 5 ;

				m_treeROSEN.InsertItem( strItem , 
					nImage , nSelectedImage , itemDiaName , TVI_LAST ) ;
			}
			{
				CString	strItem ;
				strItem.LoadString( IDS_WORD_NOBORIJIKOKUHYOU ) ;
				int nImage = 6 ;
				int nSelectedImage = 6 ;

				m_treeROSEN.InsertItem( strItem , 
					nImage , nSelectedImage , itemDiaName , TVI_LAST ) ;
			}
			// --------------------------------
			//	□ダイヤグラム  ダイヤグラムの図柄
			// --------------------------------
			{
				CString	strItem ;
				strItem.LoadString( IDS_WORD_DIAGRAM ) ;
				int nImage = 7 ;
				int nSelectedImage = 7 ;

				m_treeROSEN.InsertItem( strItem , 
					nImage , nSelectedImage , itemDiaName , TVI_LAST ) ;
			}
			
		}
	}
	// --------------------------------
	//	□コメント(0,3)
	// --------------------------------
	{
		CString	strItem ;
		strItem.LoadString( IDS_WORD_COMMENT ) ;
		int nImage = 8 ;
		int nSelectedImage = 8 ;

		itemDia = m_treeROSEN.InsertItem( strItem , nImage , nSelectedImage , itemRosen , TVI_LAST ) ;
		m_treeROSEN.SetItemState( itemDia , TVIS_EXPANDED ,  TVIS_EXPANDED ) ;

	}


	// --------------------------------
	//	アイテムを選択
	// --------------------------------
	if ( aItemPos.size() > 0 ){
		HTREEITEM	hItem = NULL ;
		{
			CaTreeCtrl	aCaTreeCtrl( &m_treeROSEN ) ;
			hItem = aCaTreeCtrl.HTREEITEM_from_Itemlocation( &aItemPos ) ;
		}
		
		
		if ( hItem != NULL ){
			m_treeROSEN.Select( hItem , TVGN_CARET ) ;
		}
	}
}

void CDlgRosenView::OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint ) 
{
	// --------------------------------
	//	路線Viewを更新
	// --------------------------------
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC ){
		return ;
	}
	// --------------------------------
	//pHint= 
	//	pHintが CRfEditCmdHolder オブジェクトなら、
	//	対応する編集コマンド CRfEditCmd を保持しています。
	//	この場合、this は CRfEditCmd の内容に最適化した
	//	更新を行います。
	//	NULLなら、全更新が要求されています。


	// --------------------------------
	//	CRfEditCmd に最適化された更新
	// --------------------------------
	Ou<CRfEditCmd> pCmd ;
	if ( pHint != NULL && pHint->IsKindOf( RUNTIME_CLASS( CRfEditCmdHolder ) ) ){
		CRfEditCmdHolder* pCHolder = (CRfEditCmdHolder*)pHint ;
		pCmd = pCHolder->getCmd() ;
	}
	if ( pCmd != NULL ){
		if ( 
			dynamic_castOu<CRfEditCmd_Comment>( pCmd ) ||
			dynamic_castOu<CRfEditCmd_Eki>( pCmd ) ||
			dynamic_castOu<CRfEditCmd_Ressya>( pCmd ) ||
			dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd ) ||
			dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd ) 
		){
			//	このビューは、以下の状況では更新は不要です。
			//		コメントの編集
			//		駅の編集
			//		列車の編集
			//		列車の直通化
			//		列車種別の編集
			//		列車種別の入替
		}
		else
		{
			//	全更新を行わせます。
			//CRfEditCmd_DedRosenFileDataProp
			//	路線名の変更を反映する必要があります。
			//CDedRosenFileData_Dia
			//	ダイヤの追加・削除
			//CDedRosenFileData_DiaProp
			//	ダイヤ名の変更
			//CRfEditCmd_Rosen
			//	路線オブジェクトの全置換え
			//CRfEditCmd_RosenFileData
			//	路線ファイルデータの全置換え
			pHint = NULL ;
		}
	}

	//	全更新を行います。
	if ( pHint == NULL ){
			getCDiagramEditApp()->getCDlgRosenView()->UpdateROSEN( 
				getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ) ;
	}
}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

CDlgRosenView::CDlgRosenView(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRosenView::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRosenView)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void CDlgRosenView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRosenView)
	DDX_Control(pDX, IDC_TREE_ROSEN, m_treeROSEN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRosenView, CDialog)
	//{{AFX_MSG_MAP(CDlgRosenView)
	ON_WM_SIZE()
	ON_NOTIFY(NM_CLICK, IDC_TREE_ROSEN, OnClickTreeRosen)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_ROSEN, OnDblclkTreeRosen)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_MENUITEM_OPEN, &CDlgRosenView::OnMenuitemOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenView メッセージ ハンドラ

BOOL CDlgRosenView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// --------------------------------
	m_imagelistROSEN.Create( IDB_TREE_ROSEN , 16 , 16 , RGB( 255 , 255 , 255 ) ) ;
	m_treeROSEN.SetImageList( &m_imagelistROSEN , TVSIL_NORMAL   ) ;


	// --------------------------------
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgRosenView::OnSize(UINT nType, int cx, int cy) 
{
	//CDialog::OnSize(nType, cx, cy);
	

	if ( GetDlgItem( IDC_TREE_ROSEN ) == NULL ){
		return ;
	}
	// --------------------------------
	//	各ウインドウの現在の位置を取得
	// --------------------------------
	CRect	rectThis ;
	{
		GetClientRect( &rectThis  ) ;
	}
	CRect	rectIDC_TREE_ROSEN ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		GetDlgItem( IDC_TREE_ROSEN ) ->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectIDC_TREE_ROSEN = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	// --------------------------------
	//	各ウインドウの新しい位置を算定
	// --------------------------------
	CRect	rectIDC_TREE_ROSENNew  ;
	{
		rectIDC_TREE_ROSENNew = rectIDC_TREE_ROSEN ;
		rectIDC_TREE_ROSENNew.right = rectThis.right ; 
		if ( rectIDC_TREE_ROSENNew.right < rectIDC_TREE_ROSENNew.left ){
			rectIDC_TREE_ROSENNew.right = rectIDC_TREE_ROSENNew.left ;
		}
		rectIDC_TREE_ROSENNew.bottom = rectThis.bottom ; 
		if ( rectIDC_TREE_ROSENNew.bottom < rectIDC_TREE_ROSENNew.top ){
			rectIDC_TREE_ROSENNew.bottom = rectIDC_TREE_ROSENNew.top ;
		}
	}
	// --------------------------------
	//	各ウインドウの新しい位置を設定
	// --------------------------------
	GetDlgItem( IDC_TREE_ROSEN )->SetWindowPos( NULL , 
		rectIDC_TREE_ROSENNew.left , 
		rectIDC_TREE_ROSENNew.top , 
		rectIDC_TREE_ROSENNew.Width() , 
		rectIDC_TREE_ROSENNew.Height() , 
		SWP_NOZORDER ) ;   
	
}

void CDlgRosenView::OnOK() 
{
	// 子ダイアログの場合は、OnOK()・OnCancel()
	//	は、オーバライドして、
	//	CDlalog::OnOK()の呼出は抑止しなくては
	//	なりません。
	//
	//CDialog::OnOK();

	//	OnOK() には、リターンキーの操作を実装します。

	// --------------------------------
	int iRv = 0 ;
	HTREEITEM	aItem = NULL ;
	{
		aItem = m_treeROSEN.GetSelectedItem() ;
	}
	{
		iRv = onEnterItem( aItem , 0 ) ;
	}
	// --------------------------------
	
}

void CDlgRosenView::OnCancel() 
{
	// 子ダイアログの場合は、OnOK()・OnCancel()
	//	は、何もしないようにオーバライドしなくてはなりません。
	//
	//CDialog::OnCancel();
}

void CDlgRosenView::OnClickTreeRosen(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	//	NM_DBLCLK (tree view)
	//	Return nonzero to prevent the default processing, 
	//	or zero to allow the default processing.
	//
	//	0 ;	//	標準の処理を行います。
	//	1 ;	//	標準の処理を行いません。
	*pResult = 0 ;

	// --------------------------------
	int iRv = 0 ;
	HTREEITEM	aItem = NULL ;
	{
		CPoint	aPoint ;
		GetCursorPos( &aPoint ) ;
		m_treeROSEN.ScreenToClient( &aPoint ) ;
		UINT iFlags = 0 ;	
		aItem = m_treeROSEN.HitTest( aPoint , &iFlags ) ;

		// --------------------------------
		/*
		//	Treeコントロールのイベントの内容
		LogMsg( "CDlgRosenView::OnClickTreeRosen()" ) ;
		if ( iFlags & TVHT_ABOVE ){
			LogMsg( "\tTVHT_ABOVE" ) ;
		}
		if ( iFlags & TVHT_BELOW ){
			LogMsg( "\tTVHT_BELOW" ) ;
		}
		if ( iFlags & TVHT_NOWHERE ){
			//	下の、アイテムのない領域
			LogMsg( "\tTVHT_NOWHERE" ) ;
		}
		if ( iFlags & TVHT_ONITEM ){
			//	アイテムのアイコン
			//	アイテムのラベル
			LogMsg( "\tTVHT_ONITEM" ) ;
		}
		if ( iFlags & TVHT_ONITEMBUTTON ){
			//	[+][-]ボタン
			LogMsg( "\tTVHT_ONITEMBUTTON" ) ;
		}
		if ( iFlags & TVHT_ONITEMICON ){
			//	アイテムのアイコン
			LogMsg( "\tTVHT_ONITEMICON" ) ;
		}
		if ( iFlags & TVHT_ONITEMINDENT ){
			LogMsg( "\tTVHT_ONITEMINDENT" ) ;
		}
		if ( iFlags & TVHT_ONITEMLABEL ){
			//	アイテムのラベル
			LogMsg( "\tTVHT_ONITEMLABEL" ) ;
		}
		if ( iFlags & TVHT_ONITEMRIGHT ){
			//	アイテムの右側
			LogMsg( "\tTVHT_ONITEMRIGHT" ) ;
		}
		if ( iFlags & TVHT_ONITEMSTATEICON ){
			LogMsg( "\tTVHT_ONITEMSTATEICON" ) ;
		}
		if ( iFlags & TVHT_TOLEFT ){
			LogMsg( "\tTVHT_TOLEFT" ) ;
		}
		if ( iFlags & TVHT_TORIGHT ){
			LogMsg( "\tTVHT_TORIGHT" ) ;
		}
		*/
		// --------------------------------
		if ( ( iFlags & TVHT_ONITEM ) )
		{
			iRv = onEnterItem( aItem , 1 ) ;
			if ( iRv == 1 )
			{
				//	*pResult を 1 にすると、クリックされたアイテムが
				//	選択状態アイテムになりません。
				//
				//	*pResult = 1 ;
			}
		}
	}
}

void CDlgRosenView::OnDblclkTreeRosen(NMHDR* pNMHDR, LRESULT* pResult) 
{
	//	NM_DBLCLK (tree view)
	//	Return nonzero to prevent the default processing, 
	//	or zero to allow the default processing.
	//
	//	0 ;	//	標準の処理を行います。
	//	1 ;	//	標準の処理を行いません。
	*pResult = 0 ;

	// --------------------------------
	int iRv = 0 ;
	HTREEITEM	aItem = NULL ;
	{
		CPoint	aPoint ;
		GetCursorPos( &aPoint ) ;
		m_treeROSEN.ScreenToClient( &aPoint ) ;
		UINT iFlags = 0 ;	
		aItem = m_treeROSEN.HitTest( aPoint , &iFlags ) ;

		// --------------------------------
		if ( ( iFlags & TVHT_ONITEM ) ){
			iRv = onEnterItem( aItem , 2 ) ;
			if ( iRv == 1 ){
				//	*pResult を 0 にすると、ダブルクリックされたアイテムの
				//	子アイテムが展開されます。
				*pResult = 1 ;
			}
		}
	}
}

void CDlgRosenView::OnMenuitemOpen()
{
	if ( m_treeROSEN.getItemContextMenu() != NULL )
	{
		onEnterItem( m_treeROSEN.getItemContextMenu() , 1 ) ;
	}
}
} //namespace ViewRosen
