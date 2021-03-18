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
// CDedCommentView.cpp : インプリメンテーション ファイル
// $Id: CDedCommentView.cpp 295 2016-06-11 05:14:13Z okm $

#include "stdafx.h"

#include "NsOu/OuNew.h"
#include "NsOu/dynamic_castOu.h"
#include "str/strLf.h"
#include "str/strToInt.h"
#include "LogMsg\LogMsg.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDrawMfc/CDcdTargetMfcPrintInfo.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/print/CaDcdTargetZoomDisplay.h"

#include "..\DiagramEdit.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "..\Print\CconvCdPrintPageProp.h"
#include "CDedCommentView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewComment{

using namespace std ;
/////////////////////////////////////////////////////////////////////////////
// CDedCommentView

void CDedCommentView::OnUpdate_All() 
{

	LogMsg( "CDedCommentView::OnUpdate_All() Viewの更新" ) ;

	CDiagramEditDoc* pRootDoc = getCDiagramEditDoc() ;

	//	フォントが変更されていたら、フォントを設定
	CdFontProp	aCdFontProp = pRootDoc->getCDedRosenFileData()->getCdDedDispProp().getViewCommentFont() ;
	if ( m_CdFontProp != aCdFontProp ){
		if ( m_CFont.GetSafeHandle() != NULL ){
			m_CFont.DeleteObject() ;
		}

		CDC* pDc = GetEditCtrl().GetDC() ;
		CConverter_WinGdi	aConv ;
		m_CFont.CreateFontIndirect( &aConv.LOGFONTOf( aCdFontProp , pDc->GetSafeHdc() ) ) ;
		
		GetEditCtrl().SetFont( &m_CFont ) ;
		// --------------------------------
		if ( pDc != NULL ){
			GetEditCtrl().ReleaseDC( pDc ) ;
			pDc = NULL ;
		}
		m_CdFontProp = aCdFontProp ;
	}
	
	//	テキストを更新	
	string strLs = pRootDoc->getCDedRosenFileData()->getCentDedRosen()->getComment() ;
	{
		int iLineNum = GetEditCtrl().GetFirstVisibleLine() ;
		int iStartChar , iEndChar ;
		GetEditCtrl().GetSel( iStartChar , iEndChar ) ;
		GetEditCtrl().SetWindowText( strCrlfOf( strLs ).c_str() ) ;
		if ( iStartChar > GetEditCtrl().GetWindowTextLength() ){
			iStartChar = GetEditCtrl().GetWindowTextLength() ;
		}
		if ( iEndChar > GetEditCtrl().GetWindowTextLength() ){
			iEndChar = GetEditCtrl().GetWindowTextLength() ;
		}
		GetEditCtrl().LineScroll( iLineNum ) ;
		GetEditCtrl().SetSel( iStartChar , iStartChar , FALSE ) ;
	}

	// --------------------------------
	m_bUpdate_All_Requested = false ;

	LogMsg( "CDedCommentView::OnUpdate_All()=" ) ;

}

void CDedCommentView::OnUpdate_Comment( Ou<CRfEditCmd_Comment> pCommand )
{
	CView *pView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	
	if ( this != pView )
	{
		LogMsg( "CDedCommentView::OnUpdate_Comment() "
			"他のビューによる更新をthis に反映します。" ) ;

		int iLineNum = GetEditCtrl().GetFirstVisibleLine() ;
		int iStartChar , iEndChar ;
		GetEditCtrl().GetSel( iStartChar , iEndChar ) ;
		GetEditCtrl().SetWindowText( strCrlfOf( pCommand->getComment() ).c_str() ) ;
		if ( iStartChar > GetEditCtrl().GetWindowTextLength() ){
			iStartChar = GetEditCtrl().GetWindowTextLength() ;
		}
		if ( iEndChar > GetEditCtrl().GetWindowTextLength() ){
			iEndChar = GetEditCtrl().GetWindowTextLength() ;
		}
		GetEditCtrl().SetSel( iStartChar , iStartChar ) ;
		GetEditCtrl().LineScroll( iLineNum ) ;

	}
	else
	{
		LogMsg( "CDedCommentView::OnUpdate_Comment() "
			"thisによる更新なので、このビューには反映しません。" ) ;
	}

}

IMPLEMENT_DYNCREATE(CDedCommentView, CEditView)

CDedCommentView::CDedCommentView(): 
	m_bUpdate_All_Requested( false ) ,
	m_bIsChanged( false )
{
}

CDedCommentView::~CDedCommentView()
{
}


BEGIN_MESSAGE_MAP(CDedCommentView, CDedCommentView::super)
	//{{AFX_MSG_MAP(CDedCommentView)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_WM_DESTROY()
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDedCommentView 描画

void CDedCommentView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
}

/////////////////////////////////////////////////////////////////////////////
// CDedCommentView 診断

#ifdef _DEBUG
void CDedCommentView::AssertValid() const
{
	super::AssertValid();
}

void CDedCommentView::Dump(CDumpContext& dc) const
{
	super::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDedCommentView メッセージ ハンドラ

void CDedCommentView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if ( lHint ==  LHINT_SUBVIEW_TO_ROOTDOC  )
	{
		//[Attention]
		//	(lHint== LHINT_SUBVIEW_TO_ROOTDOC )の場合は、
		//	ビューの内容をルートDocに反映して
		//	ください。
		if ( m_bIsChanged )
		{
			// --------------------------------
			//	コマンドの生成・実行
			// --------------------------------
			CString	strLs ;
			GetEditCtrl().GetWindowText( strLs ) ;
			OuNew<CRfEditCmd> pCmd( 
				new CRfEditCmd_Comment( strLfOf( (LPCTSTR)strLs ) ) ) ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;
			
			// --------------------------------
			m_bIsChanged = false ;
		}
	}	else	{
		//[Attention]
		//	(lHint!= LHINT_SUBVIEW_TO_ROOTDOC )の場合は、
		//	ルートDocの内容をビューに
		//	反映してください。

		//pHint= 
		//	pHintが CRfEditCmdHolder オブジェクトなら、
		//	対応する編集コマンド CRfEditCmd を保持しています。
		//	この場合、this は CRfEditCmd の内容に最適化した
		//	更新を行います。
		//	NULLなら、全更新が要求されています。
		if ( m_bUpdate_All_Requested )
		{
			//	全更新が保留されている場合は、
			//	その後はコマンドによる最適化された単体のいかなる更新要求に対しても、全更新を行います。
			pHint = NULL ;
		}

		Ou<CRfEditCmd> pCmd ;
		if ( pHint != NULL && pHint->IsKindOf( RUNTIME_CLASS( CRfEditCmdHolder ) ) ){
			CRfEditCmdHolder* pCHolder = (CRfEditCmdHolder*)pHint ;
			pCmd = pCHolder->getCmd() ;
		}
		if ( pCmd != NULL ){
			if ( 
				dynamic_castOu<CRfEditCmd_Comment>( pCmd ) 
			) {
				//	コメントが変更されたら、それを設定します。
				//	但し、このビューがアクティブな場合は、この更新は行いません。
				Ou<CRfEditCmd_Comment>	pCommand = 
					dynamic_castOu<CRfEditCmd_Comment>( pCmd ) ;
				OnUpdate_Comment( pCommand ) ;
			}	else if ( 
				dynamic_castOu<CRfEditCmd_Dia>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_Eki>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_Ressya>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd ) 
			){
				//	このビューは、
				//		ダイヤの変更
				//		ダイヤのプロパティの変更
				//		駅の変更
				//		列車の変更
				//		列車の直通化
				//		列車種別の変更
				//		列車種別の入替
				//	の場合は、更新を行いません。
			}
			else
			{
				//	全更新扱い
				//CRfEditCmd_DedRosenFileDataProp
				//	フォントが更新される場合がありますので、全更新が必要です
				//CRfEditCmd_Rosen
				//CRfEditCmd_RosenFileData
				//	CentDedRosen を包含するオブジェクトの置換え。
				pHint = NULL ;
			}
		}
		
		//	最適化された更新がない場合は、
		//	全更新要求
		if ( pHint == NULL ){
			if ( getCDiagramEditApp()->getCMainFrame()->getMDIChildActiveView() != this ){
				//	他のビューから、更新が要求されました。
				//	ビューの更新は、このビューがアクティブになるまで
				//	保留します。
				LogMsg( "CDedCommentView::OnUpdate() Viewの更新を保留" ) ;
				m_bUpdate_All_Requested = true ;
				return ;
			}
			//	ビューの全更新
			OnUpdate_All() ;
		}
	}
}

void CDedCommentView::OnChange() 
{
	// TODO: これが RICHEDIT コントロールの場合、コントロールは、 lParam マスク
	// 内での論理和の ENM_CHANGE フラグ付きで CRichEditCrtl().SetEventMask()
	// メッセージをコントロールへ送るために CEditView::OnInitDialog() 関数をオーバー
	// ライドしない限りこの通知を送りません。
	
	getCDiagramEditDoc()->SetModifiedFlag( TRUE ) ;
	m_bIsChanged = true ;
	
}

void CDedCommentView::OnFilePrintPreview() 
{
	//	プレビューを有効にします。
	super::OnFilePrintPreview() ;
}

void CDedCommentView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	if ( !bActivate ){
		//[Attention]
		//	このビューが非アクティブになったときには、
		//	OnUpdate(lHint=LHINT_SUBVIEW_TO_ROOTDOC)を呼び出して、
		//	このビューの内容を
		//	ルートDocに反映させたうえで、さらにルートDocの内容を
		//	すべてのサブDoc/Viewに反映させてください。


		// --------------------------------
		//	『路線』ドキュメントの更新
		// --------------------------------
		OnUpdate( this , LHINT_SUBVIEW_TO_ROOTDOC , NULL ) ;


	}
	if ( m_bUpdate_All_Requested && bActivate ){
		//	ビューの更新が保留されている状態で、
		//	ビューがアクティブになったときは、
		//	ビューの更新を行わせます。
		OnUpdate_All() ;
	}
	
	
	super::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

void CDedCommentView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	if ( m_bUpdate_All_Requested ){
		//	ビューの更新が保留されている場合は、
		//	ビューの更新を行わせます。
		OnUpdate_All() ;
	}
	
	super::OnBeginPrinting(pDC, pInfo);
}

void CDedCommentView::OnDestroy() 
{
	CFont	aCFont ;
	aCFont.CreateStockObject( SYSTEM_FONT ) ;
	GetEditCtrl().SetFont( &aCFont ) ;

	super::OnDestroy();
}


BOOL CDedCommentView::PreCreateWindow(CREATESTRUCT& cs) 
{
	
	BOOL bRv = super::PreCreateWindow(cs);

	//	水平スクロールバーを削除し、
	//	テキストを右端で折り返すように変更
	if ( bRv ){
		cs.style &=~( WS_HSCROLL ) ;
		cs.style &=~( ES_AUTOHSCROLL ) ;
	}
	return ( bRv ) ;
}


CdDrawTextProp	CDedCommentView::getCdDrawTextPropStandard()
{ 
	const CDedRosenFileData* pCDedRosenFileData = 
		getCDiagramEditDoc()->getCDedRosenFileData() ;
	CdDedDispProp aCdDedDispProp = pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		m_CdFontProp ,
		CdColorProp( 0 , 0 , 0 ) ) ;
}



void CDedCommentView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	super::OnPrint( pDC , pInfo ) ;
	return ;


	//	以下のコードは、ページ番号を
	//	表示しようとしたものですが、
	//	ASSERTになってしまいます。
	//	このため、当面は動作させません。
/*
	//attention
	//	このクラスは、ページごとの開始位置を
	//	キャッシュしています（CEditView::m_aPageStart）。
	//	ところが、マップモードを
	//	変更している場合、プレビュー表示中にウインドウサイズを
	//	変更すると、キャッシュと実際の表示が食い違って
	//	しまい、ASSERTになってしまいます。
	//	以下の３関数を実行することにより、キャッシュをクリアできる
	//	ことが分かりました。
	//	
	//	OnPrepareDC からは この関数が呼び出されます。
	//	OnPrepareDCから呼び出された場合は、
	//	この区間の実行は避けるべきです。
	//	b は、OnPrepareDCが実行中であることを示すフラグです。
	static bool b = false ;
	if ( !b ){
		b = true ;

		//attention
		//	以下を実行すると、プリンタDCが壊れます。
		//	理由は不明です。
		//
		//	CPrintInfo	aCPrintInfo = *pInfo ;
		
		super::OnEndPrinting( pDC, pInfo ) ;
		super::OnBeginPrinting( pDC, pInfo ) ;
		super::OnPrepareDC( pDC, pInfo ) ;

		b = false ;

		//attention
		//	これをやると、プリンタDCが壊れます。
		//	理由は謎です。
		//
		//	*pInfo = aCPrintInfo ;
	}



	LogMsg( "CDedCommentView::OnPrint() " ) ;
	LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;

	// --------------------------------
	//	描画面を作成
	// --------------------------------
	CDcdTargetMfcPrintInfo	aCDcdTargetMfcPrintInfo( pDC, pInfo ) ;

	LogMsg( "CDedCommentView::OnPrint()1" ) ;

	// --------------------------------
	//	余白を除いた領域を作成
	// --------------------------------
	CaDcdTargetItemPosition	aTargetInnerMargin( &aCDcdTargetMfcPrintInfo , 
		CdDcdZoneXy() ) ;
	{
		LogMsg( DeviceCapsToString( 
			aCDcdTargetMfcPrintInfo.getPrinterHdc() ).c_str() ) ;
	
		CconvCdPrintPageProp aCconvCdPrintPageProp ;
		CdDcdZoneXy	zonexyInneraMargin = 
			aCconvCdPrintPageProp.calcZoneInnerMargin( 
				getCDiagramEditApp()->getCdPrintPageProp() , 
				aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
		if ( zonexyInneraMargin.getX().getSize() <= 0 ){
			zonexyInneraMargin.setX( 
				aCDcdTargetMfcPrintInfo.getZone().getX() ) ;
		}
		if ( zonexyInneraMargin.getY().getSize() <= 0 ){
			zonexyInneraMargin.setY( 
				aCDcdTargetMfcPrintInfo.getZone().getY() ) ;
		}

		aTargetInnerMargin.setZone( zonexyInneraMargin ) ;

	}

	//aTargetInnerMargin = 余白部分を除いた描画領域。
	//	単位はプリンタのピクセルです。


	LogMsg( "CDedCommentView::OnPrint()2" ) ;

	// --------------------------------
	//	論理座標を設定
	// --------------------------------
	CaDcdTargetZoomDisplay	aCaDcdTargetZoomDisplay( 
		&aTargetInnerMargin , 
		aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
	//aCaDcdTargetZoomDisplay = 余白部分を除いた描画領域。
	//	単位は、画面上の１ピクセル相当になりました。
	IfDcdTarget*	pTarget =  &aCaDcdTargetZoomDisplay ;
	
	//pTarget = 描画を行う領域。
	//	単位は、画面上の１ピクセル相当になりました。

	LogMsg( "CDedCommentView::OnPrint()3" ) ;
	// --------------------------------
	//	ページ番号のDcDrawオブジェクト部品を作成
	// --------------------------------
	
	//memo: キャプションの印刷は行わないことにしました。
	//	Ou<CDcdText>	pdcdCaption ;
	//	{
	//		const CentDedRosen* pCentDedRosen = 
	//			getCDiagramEditDoc()->getCDedRosenFileData()
	//				->getCentDedRosen() ;
	//			CJikokuhyouDoc* pCJikokuhyouDoc = 
	//				(CJikokuhyouDoc*)GetDocument() ;
	//		
	//			string	strText ;
	//			//	路線名
	//			if ( !pCentDedRosen->getName().empty() ){
	//				strText += pCentDedRosen->getName() ;
	//				strText += " " ;
	//			}
	//		
	//			pdcdCaption = OuNew<CDcdText>( new CDcdText( 
	//				strText , getCdDrawTextPropStandard() ) ) ;
	//		}

	Ou<CDcdText>	pdcdPage ;
	{
		CdDrawTextProp	aProp = getCdDrawTextPropStandard() ;
		CdDrawTextFormat	aFormat = aProp.getCdDrawTextFormat() ;
		aFormat.setHorizontal( aFormat.H_CENTER ) ;
		aProp.setCdDrawTextFormat( aFormat ) ;
		pdcdPage = OuNew<CDcdText>( new CDcdText( "" ,aProp , "99" ) ) ;
	}
	//pdcdPage = ページ番号のDcDrawオブジェクト
	
	// --------------------------------
	//	ページ番号の部品・
	//	CEditView テキストのレイアウトを決める	
	// --------------------------------
	
	//memo: キャプションの印刷は行わないことにしました。
	//	Ou<CaDcdTargetItemPosition>	pTargetCaption ;

	Ou<CaDcdTargetItemPosition>	pTargetEditView ;
	Ou<CaDcdTargetItemPosition>	pTargetPage ;
	{
		CdDcdZoneXy	zoneEditView = pTarget->getZone() ;
		//zoneEditView=余白部分を除いた描画領域。
		//	ここからページ番号を除いたものが、
		//	最終的にエディットビューに記された内容を
		//	印刷する領域です。


		//memo: キャプションの印刷は行わないことにしました。
		//	pdcdCaption->getItemSize( pTarget , &aSize ) ;
		//	CdDcdZoneXy zoneCaption( zoneEditView.getX() , 
		//		CdDcdZone( zoneEditView.getY().getPos() , aSize.getY() ) ) ;
		//	zoneEditView.setY( CdDcdZone().setBeginEndPos( 
		//		zoneCaption.getY().getEndPos() + aSize.getY() , 
		//		zoneEditView.getY().getEndPos() ) ) ;
		//	//zoneCaption = 全領域の上部を、キャプション用に割り当てています。
		//	//zoneEditView = 全領域から、上部のキャプション領域を除いた
		//	//	領域です。
		//	
		//	pTargetCaption = OuNew<CaDcdTargetItemPosition>( 
		//		new CaDcdTargetItemPosition( pTarget , zoneCaption ) ) ;

		// --------------------------------
		//	ページ番号の領域 IfDcdTarget
		// --------------------------------
		{
			CdDcdSizeXy	aSize ;
			pdcdPage->getItemSize( pTarget , &aSize ) ;
			CdDcdZoneXy zonePage( zoneEditView.getX() , 
				CdDcdZone( zoneEditView.getY().getEndPos() - aSize.getY() ,
				aSize.getY() ) ) ;
			//zonePage = 全領域の下部を、ページ用に割り当てています。
			pTargetPage = OuNew<CaDcdTargetItemPosition>(
				new CaDcdTargetItemPosition( pTarget , zonePage ) ) ;
			//pTargetPage=ページ用のIfDcdTarget

			zoneEditView.setY( CdDcdZone().setBeginEndPos( 
				zoneEditView.getY().getPos() , //zoneCaption.getY().getEndPos() , 
				zonePage.getY().getPos() - aSize.getY()) ) ;
			//zoneEditView = 上部のキャプションに続いて、下部のページ領域も除いた領域です。
		}

		// --------------------------------
		//	コンテンツ領域 IfDcdTarget
		// --------------------------------
		pTargetEditView = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( pTarget , zoneEditView ) ) ;
	}
	// --------------------------------
	//	CEditView上のテキストを描画
	// --------------------------------
	int iPage = 0 ;
	{
		CRect	rectDrawSid = pInfo->m_rectDraw ;

		// --------------------------------
		//	プリンタ用のフォントを設定
		//	（この関数内でDCのマップモードを変更しています。
		//	CEdit のデフォルトのフォントは、この変更を考慮していないため、
		//	プリンタ用のフォントを新しいマップモードに
		//	合わせたものに変更する必要があります）
		// --------------------------------
		Ou<CGdiHFontHolder>	pHFontHolder ;
		CFont	aCFont ;
		CFont*	pFontSid = NULL ;
		{
			pHFontHolder = pTargetEditView->createGdiHFontHolder( getCdDrawTextPropStandard().getCdFontProp() ) ;
			aCFont.Attach( pHFontHolder->getHFont() ) ;
			pFontSid = GetPrinterFont() ;
			SetPrinterFont( &aCFont ) ;
		}
		// --------------------------------
		//	pInfo->m_rectDraw を、
		//	ページを除いた領域に修正します。
		// --------------------------------
		CConverter_WinGdi	aConv ;
		pInfo->m_rectDraw = aConv.RECTOf( pTargetEditView->getZone() ) ;
		// --------------------------------
		//	印刷処理
		// --------------------------------
		super::OnPrint(pDC, pInfo);
		// --------------------------------
		//	pInfo->m_rectDraw を復帰
		// --------------------------------
		pInfo->m_rectDraw = rectDrawSid ;

		// --------------------------------
		//	プリンタ用のフォントを戻す
		// --------------------------------
		{
			SetPrinterFont( pFontSid ) ;
			pFontSid = NULL ;
			aCFont.Detach() ;
		}


		// --------------------------------
		iPage = pInfo->m_nCurPage - 1 ;
	}
	//iPage = ページ番号(0起点)
	LogMsg( "CDedCommentView::OnPrint()6" ) ;
	// --------------------------------
	//	ページ番号のテキストを作成
	// --------------------------------
	{
		//ページ番号も決定
		{
			string	strPage = OuLib::stringOf( iPage + 1) ;
			pdcdPage->setText( strPage ) ;
		}
	}

	LogMsg( "CDedCommentView::OnPrint()7" ) ;
	// --------------------------------
	//	ページ番号を描画
	// --------------------------------
	{
		//memo: キャプションの印刷は行わないことにしました。
		//
		//	pdcdCaption->DcDraw( pTargetCaption ) ;

		pdcdPage->DcDraw( pTargetPage ) ;
	}
*/
}
} //namespace ViewComment
