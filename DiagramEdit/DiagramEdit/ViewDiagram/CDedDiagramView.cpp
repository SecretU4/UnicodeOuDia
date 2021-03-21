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
// cdeddiagramview.cpp : インプリメンテーション ファイル
//	$Id: CDedDiagramView.cpp 295 2016-06-11 05:14:13Z okm $

#include "stdafx.h"

#include "NsMu/CaMuPtref.h"
#include "NsOu/dynamic_castOu.h"
#include "NsOu/OuNew.h"
#include "LogMsg\LogMsg.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDrawMfc/CDcdTargetMfcPrintInfo.h"
#include "DcDraw/print/CaDcdTargetZoomDisplay.h"
#include "str/strToInt.h"

#include "..\diagramedit.h"
#include "..\entDed\CentDedRosen.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "..\Print\CconvCdPrintPageProp.h"
#include "CaDcdDiagram_PageSelector.h"
#include "cdeddiagramview.h"
#include "CDlgDiagramViewProp.h"

namespace ViewDiagram{

using namespace std ;
using namespace DcDrawLib::DcDraw::Print;
using namespace DcDrawLib::DcDrawMfc;

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView
/**
	ダイヤグラム座標の許容誤差値
*/
const int ALLOWED_DIFFERENCE = 1 ;

// --------------------------------
//@name OnUpdate下請関数
// --------------------------------
void CDedDiagramView::OnUpdate_All() 
{
	CWaitCursor	aCWaitCursor ;

	LogMsg( "CDedDiagramView::OnUpdate_All()" ) ; 
	// --------------------------------
	//	『ダイヤグラム駅』オブジェクトを生成
	// --------------------------------
	const CentDedRosen* pCentDedRosen = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;

	if ( m_pCentDedDgrDia == NULL ){
		m_pCentDedDgrDia = new CentDedDgrDia ;
		LogMsg( "CDedDiagramView::OnUpdate_All()1" ) ; 
		m_pCentDedDgrDia->readCentDedRosen( pCentDedRosen , getCentDedDia() ) ; 
		LogMsg( "CDedDiagramView::OnUpdate_All()2" ) ; 
		m_pCWndDiagram->setCentDedDgrDia( m_pCentDedDgrDia ) ;
	}	else	{
		LogMsg( "CDedDiagramView::OnUpdate_All()3" ) ; 
		m_pCentDedDgrDia->readCentDedRosen( pCentDedRosen , getCentDedDia() ) ; 
		LogMsg( "CDedDiagramView::OnUpdate_All()4" ) ; 
	}
	// --------------------------------
	CdDedDispProp	aCdDedDispProp = getCDiagramEditDoc()->getCDedRosenFileData()->getCdDedDispProp() ;
	m_pCWndDiagram->readCdDedDispProp( aCdDedDispProp ) ;
	LogMsg( "CDedDiagramView::OnUpdate_All()5" ) ; 
	
	// --------------------------------
	m_pCWndDiagram->onUpdateCentDedDgrDia() ;

	LogMsg( "CDedDiagramView::OnUpdate_All()=" ) ; 

	m_bUpdate_All_Requested = false ;
}


void CDedDiagramView::OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) 
{
	int iDiaIndex = GetDocument()->getDiaIndex() ;
	if ( !( pCommand->getDiaIndex() == iDiaIndex ) ){
		return ;
	}

	ERessyahoukou	eRessyahoukou = pCommand->getRessyahoukou() ;
	const CentDedRessyaCont*	pCentDedRessyaContSrc = 
		pCommand->getCentDedRessyaContSrc() ;
	// --------------------------------
	//	減少分の要素の削除
	// --------------------------------
	int iGensyouSize = pCommand->getSizeDst() - pCentDedRessyaContSrc->size() ;
	if ( iGensyouSize > 0 ){
		for ( int cnt = 0 ; cnt < iGensyouSize ; cnt ++ ){
			m_pCentDedDgrDia->getCentDedDgrRessyaCont( eRessyahoukou )->erase( 
				pCommand->getIndexDst() + 
				pCommand->getSizeDst() - iGensyouSize ) ;
		}
	}
	// --------------------------------
	//	要素の置換
	// --------------------------------
	int iOkikaeSize = 0 ;
	iOkikaeSize = min( pCommand->getSizeDst() , pCentDedRessyaContSrc->size() ) ;
	{
		for ( int cnt = 0 ; cnt < iOkikaeSize ; cnt ++ )
		{
			int idxRessya = pCommand->getIndexDst() + cnt ;
			const CentDedRosen*	pCentDedRosen = 
				getCDiagramEditDoc()->getCDedRosenFileData()->
				getCentDedRosen() ;
			const Mu<const CentDedRessya*>* pCentDedRessyaContGet = 
				getCentDedDia()->getCentDedRessyaCont( eRessyahoukou )->getMuPtr() ;

			const CentDedRessya* pCentDedRessya = pCentDedRessyaContGet->get( 
				idxRessya )  ;
			CentDedDgrRessya	aCentDedDgrRessya( pCentDedRosen , 
				m_pCentDedDgrDia , 
				pCentDedRessya ) ;

			m_pCentDedDgrDia->getCentDedDgrRessyaCont( eRessyahoukou )->set(
				aCentDedDgrRessya , idxRessya ) ;
			
		}
	}
	// --------------------------------
	//	増加分の要素の追加
	// --------------------------------
	int iZoukaSize = pCentDedRessyaContSrc->size() - pCommand->getSizeDst() ;
	if ( iZoukaSize > 0 ){
		for ( int cnt = 0 ; cnt < iZoukaSize ; cnt ++ ){
			int idxRessya = pCommand->getIndexDst() + iOkikaeSize + cnt ;

			const CentDedRosen*	pCentDedRosen = 
				getCDiagramEditDoc()->getCDedRosenFileData()->
				getCentDedRosen() ;
			const Mu<const CentDedRessya*>* pCentDedRessyaContGet = 
				getCentDedDia()->getCentDedRessyaCont( eRessyahoukou )->getMuPtr() ;

			const CentDedRessya* pCentDedRessya = pCentDedRessyaContGet->get( 
				idxRessya )  ;
			CentDedDgrRessya	aCentDedDgrRessya( pCentDedRosen , 
				m_pCentDedDgrDia , 
				pCentDedRessya ) ;

			m_pCentDedDgrDia->getCentDedDgrRessyaCont( eRessyahoukou )->insert(
				aCentDedDgrRessya , idxRessya ) ;
		}
	}

	m_pCWndDiagram->onUpdateCentDedDgrRessya() ;

}


/**
  整数(補正対象値)が、増減単位の倍数±α(誤差許容値) なら、
  最寄の増減単位の倍数丁度の値に補正します。

(例)iUnit=5,iAllowedDifference=1 の場合、valueに対する結果は以下のとおりです。

　- value=3 なら return=3
　- value=4 なら return=5
　- value=5 なら return=5
　- value=6 なら return=5
　- value=7 なら return=7


　この関数は、以下のために使います。

	「CDcdDiagram::getZone_Dgr()で取得した(描画範囲の幅(ダイヤグラム座標系))が
	増減単位の倍数±α(誤差許容値)なら、(描画範囲の幅(ダイヤグラム座標系))を
	最寄の増減単位の倍数丁度の値に補正する」

@param value [in]
	補正対象値を指定してください。範囲は0以上です。
@param iUnit [in]
	増減単位を指定してください。範囲は1以上です。
@param iAllowedDifference [in]
	誤差許容値
@return
	補正された値を返します。
*/
static int adjustForNearestUnit( int value , int iUnit , int iAllowedDifference ) 
{

	//補正１：(現在値%増減単位)≦(誤差許容値) なら、
	//　現在値=現在値-(現在値%増減単位)
	//
	//(例)
	//　増減単位=1800
	//　現在値=1801
	//　(誤差許容値)=1
	//の場合
	//　(1801%1800)=1 (現在値%増減単位)
	//　1801-(1801%1800)=1800
	//
	if ( value % iUnit <= iAllowedDifference )
	{
		value = value - ( value % iUnit ) ; 
	}

	//補正２：(現在値%増減単位)≧(増減単位-誤差許容値) なら、
	//　現在値=現在値+(増減単位-(現在値%増減単位))
	//
	//(例)
	//　増減単位=1800
	//　現在値=3599
	//　(誤差許容値)=1
	//の場合
	//　(3599%1800)=1799 (現在値%増減単位)
	//　3599+(1800-(3599%1800))=3600
	else if ( ( value % iUnit ) >= ( iUnit - iAllowedDifference ) )
	{
		value = value + ( iUnit - ( value % iUnit ) ) ; 
	}
	return value ;
}



	// --------------------------------
	//@param メッセージ マップ関数の下請関数
	// --------------------------------
int CDedDiagramView::OnDiagramXDgrSizeInc_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;	

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	//	横軸方向縮小
	CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getX() ;

	//	ウインドウへの表示範囲の増減単位を算出
	//	
	//	ダイヤグラム全体が画面内に収まっていない場合:30分
	//	ダイヤグラム全体が画面内に収まっている場合  :12時間
	int iUnit = 30*60 ;
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() >= 
				m_pCentDedDgrDia->getZone().getX().getSize() )
		{
			iUnit = m_pCentDedDgrDia->getZone().getX().getSize() / 2 ;
		}
		if ( iUnit == 0 )
		{
			iUnit = 1 ;	//	あとの割り算に備えて、0 は 1 にしておきます。
		}
	}
		//iUnit = ウインドウへの表示範囲の増減単位(ダイヤグラムエンティティX座標)

	//	描画範囲の幅(ダイヤグラム座標系)が増減単位の倍数に近い場合は、
	//	増減単位の倍数丁度の値に補正する
	//	これは、CDcdDiagram に対して setZone_Dgr() で設定した
	//	『描画を行う領域の範囲(ダイヤグラムエンティティ座標系)』と 
	//	getZone_Dgr() で取得した値が一致しない場合があるためです。
	zoneCWndDiagram_Dgr.setSize( 
		adjustForNearestUnit( 
			zoneCWndDiagram_Dgr.getSize() , iUnit , ALLOWED_DIFFERENCE ) ) ;

	if ( iRv >= 0 )
	{
		//	ウインドウ上にダイヤグラムが表示されていない場合は、
		//	X方向の表示範囲は変更できません。
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getX().getSize() <= 0 )
		{
			iRv = -2 ;	//	ダイヤグラムは表示されていません。
		}
	}
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getEndPos() >= 
			m_pCentDedDgrDia->getZone().getX().getEndPos() )
		{
			//	これ以上表示範囲を広げることはできません。
			iRv = -1 ;	//現在は実行できません(エラーメッセージは表示しません)
		}
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		DcdSize	iDcdSize = zoneCWndDiagram_Dgr.getSize() ;
		int iMod = iDcdSize % (iUnit) ;
		if ( iMod == 0 ){
			iDcdSize += (iUnit) ;
		}	else	{
			iDcdSize += ( (iUnit) - iMod ) ;
		}
		zoneCWndDiagram_Dgr.setSize( iDcdSize ) ;

		LogMsg( "\t" "zoneCWndDiagram_Dgr=%d,%d" , 
			zoneCWndDiagram_Dgr.getPos() , zoneCWndDiagram_Dgr.getSize() ) ;

		zonexyCWndDiagram_Dgr.setX( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;
		// --------------------------------
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	現在は実行できません。(エラーメッセージは表示しません)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	LogMsg( "CDedDiagramView::OnDiagramXDgrSizeInc_Process()=%d" , iRv ) ;
	return iRv ;
}
int CDedDiagramView::OnDiagramXDgrSizeDec_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;	
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	// 
	CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getX() ;

	//	ウインドウへの表示範囲の増減単位を算出
	//	
	//	ダイヤグラム全体が画面内に収まっていない場合:30分
	//	ダイヤグラム全体が画面内に収まっている場合  :12時間
	int iUnit = 30*60 ;
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() 
				> m_pCentDedDgrDia->getZone().getX().getSize() )
		{
			iUnit = m_pCentDedDgrDia->getZone().getX().getSize() / 2 ;
		}
		if ( iUnit == 0 )
		{
			iRv = -2 ;	//	ダイヤグラムは表示されていません。
		}
	}
		//iUnit=ウインドウへの表示範囲の増減単位(ダイヤグラムエンティティX座標)


	//	描画範囲の幅(ダイヤグラム座標系)が増減単位の倍数に近い場合は、
	//	増減単位の倍数丁度の値に補正する
	//	これは、CDcdDiagram に対して setZone_Dgr() で設定した
	//	『描画を行う領域の範囲(ダイヤグラムエンティティ座標系)』と 
	//	getZone_Dgr() で取得した値が一致しない場合があるためです。
	zoneCWndDiagram_Dgr.setSize( 
		adjustForNearestUnit( 
			zoneCWndDiagram_Dgr.getSize() , iUnit , ALLOWED_DIFFERENCE ) ) ;

	if ( iRv >= 0 )
	{
		//	ウインドウ上にダイヤグラムが表示されていない場合は、
		//	X方向の表示範囲は変更できません。
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getX().getSize() <= 0 )
		{
			iRv = -2 ;	//	ダイヤグラムは表示されていません。
		}
	}
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() <= (iUnit) )
		{
			//	これ以上表示範囲を広げることはできません。
			iRv = -1 ;	//現在は実行できません(エラーメッセージは表示しません)
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		DcdSize	iDcdSize = zoneCWndDiagram_Dgr.getSize() ;
		int iMod = iDcdSize % (iUnit) ;
		if ( iMod == 0 ){
			iDcdSize -= (iUnit) ;
		}	else	{
			iDcdSize -= iMod  ;
		}
		zoneCWndDiagram_Dgr.setSize( iDcdSize ) ;

		LogMsg( "\t" "zoneCWndDiagram_Dgr=%d,%d" , 
			zoneCWndDiagram_Dgr.getPos() , zoneCWndDiagram_Dgr.getSize() ) ;

		zonexyCWndDiagram_Dgr.setX( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	現在は実行できません。(エラーメッセージは表示しません)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
	}
	LogMsg( "CDedDiagramView::OnDiagramXDgrSizeDec_Process()=%d" , iRv ) ;
	return iRv ;
}
int CDedDiagramView::OnDiagramYDgrSizeInc_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;	
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	
	//	縦軸方向縮小
	// 
	//	縦軸方向縮小は、表示範囲を１段階増やします。

	CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getY() ;

	//	ウインドウへの表示範囲の増減単位を算出
	//	
	//	ダイヤグラム全体が画面内に収まっていない場合:
	//		ダイヤグラム全体のサイズの1/10
	//	ダイヤグラム全体が画面内に収まっている場合  :
	//		ダイヤグラム全体のサイズの1/2
	int iUnit = m_pCentDedDgrDia->getZone().getY().getSize() / 10 ;
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() 
				>= m_pCentDedDgrDia->getZone().getY().getSize() )
		{
			iUnit = m_pCentDedDgrDia->getZone().getY().getSize() / 2 ;
		}
		if ( iUnit == 0 ){
			iUnit = 1 ;	//	あとの割り算に備えて、0 は 1 にしておきます。
		}
	}
		//iUnit=ウインドウへの表示範囲の増減単位(ダイヤグラムエンティティY座標)


	//	描画範囲の幅(ダイヤグラム座標系)が増減単位の倍数に近い場合は、
	//	増減単位の倍数丁度の値に補正する
	//	これは、CDcdDiagram に対して setZone_Dgr() で設定した
	//	『描画を行う領域の範囲(ダイヤグラムエンティティ座標系)』と 
	//	getZone_Dgr() で取得した値が一致しない場合があるためです。
	zoneCWndDiagram_Dgr.setSize( 
		adjustForNearestUnit( 
			zoneCWndDiagram_Dgr.getSize() , iUnit , ALLOWED_DIFFERENCE ) ) ;

	if ( iRv >= 0 )
	{
		//	ウインドウ上にダイヤグラムが表示されていない場合は、
		//	Y方向の表示範囲は変更できません。
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getY().getSize() <= 0 )
		{
			iRv = -2 ;	//	ダイヤグラムは表示されていません。
		}
	}
	if ( iRv >= 0 )
	{
		//	範囲は、『ダイヤグラムエンティティY座標』のサイズの10倍値以下です。
		if ( zoneCWndDiagram_Dgr.getSize() 
				>= m_pCentDedDgrDia->getZone().getY().getSize() * 10 )
		{
			//	これ以上表示範囲を広げることはできません。
			iRv = -1 ;	//現在は実行できません(エラーメッセージは表示しません)
		}
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		DcdSize	iDcdSize = zoneCWndDiagram_Dgr.getSize() ;
		int iMod = iDcdSize % iUnit ;
		if ( iMod == 0 ){
			iDcdSize += iUnit ;
		}	else	{
			iDcdSize += ( iUnit - iMod ) ;
		}
		zoneCWndDiagram_Dgr.setSize( iDcdSize ) ;
		zonexyCWndDiagram_Dgr.setY( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;
		// --------------------------------
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 ://	現在は実行できません。(エラーメッセージは表示しません)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnDiagramYDgrSizeDec_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getY() ;

	//	ウインドウへの表示範囲の増減単位を算出
	//	
	//	ダイヤグラム全体が画面内に収まっていない場合:
	//		ダイヤグラム全体のサイズの1/10
	//	ダイヤグラム全体が画面内に収まっている場合  :
	//		ダイヤグラム全体のサイズの1/2
	int iUnit = m_pCentDedDgrDia->getZone().getY().getSize() / 10 ;
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() 
				> m_pCentDedDgrDia->getZone().getY().getSize() )
		{
			iUnit = m_pCentDedDgrDia->getZone().getY().getSize() / 2 ;
		}
		if ( iUnit == 0 ){
			iUnit = 1 ;	//	あとの割り算に備えて、0 は 1 にしておきます。
		}
		//	範囲は、『ダイヤグラムエンティティY座標』のサイズの10倍値以下です。

	}

	//	描画範囲の幅(ダイヤグラム座標系)が増減単位の倍数に近い場合は、
	//	増減単位の倍数丁度の値に補正する
	//	これは、CDcdDiagram に対して setZone_Dgr() で設定した
	//	『描画を行う領域の範囲(ダイヤグラムエンティティ座標系)』と 
	//	getZone_Dgr() で取得した値が一致しない場合があるためです。
	zoneCWndDiagram_Dgr.setSize( 
		adjustForNearestUnit( 
			zoneCWndDiagram_Dgr.getSize() , iUnit , ALLOWED_DIFFERENCE ) ) ;

	if ( iRv >= 0 )
	{
		//	ウインドウ上にダイヤグラムが表示されていない場合は、
		//	Y方向の表示範囲は変更できません。
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getY().getSize() <= 0 )
		{
			iRv = -2 ;	//	ダイヤグラムは表示されていません。
		}
	}
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() <= (iUnit) ){
			//	これ以上表示範囲を広げることはできません。
			iRv = -1 ;	//現在は実行できません(エラーメッセージは表示しません)
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		DcdSize	iDcdSize = zoneCWndDiagram_Dgr.getSize() ;
		int iMod = iDcdSize % (iUnit) ;
		if ( iMod == 0 ){
			iDcdSize -= (iUnit) ;
		}	else	{
			iDcdSize -= iMod  ;
		}
		zoneCWndDiagram_Dgr.setSize( iDcdSize ) ;

		LogMsg( "\t" "zoneCWndDiagram_Dgr=%d,%d" , 
			zoneCWndDiagram_Dgr.getPos() , zoneCWndDiagram_Dgr.getSize() ) ;

		zonexyCWndDiagram_Dgr.setY( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;
		
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	現在は実行できません。(エラーメッセージは表示しません)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
	}
	LogMsg( "CDedDiagramView::OnDiagramYDgrSizeDec_Process()=%d" , iRv ) ;
	return iRv ;
}
int CDedDiagramView::OnDiagramYDgrSizeReset_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;	
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		//	ウインドウ上にダイヤグラムが表示されていない場合は、
		//	Y方向の表示範囲は変更できません。
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getY().getSize() <= 0 )
		{
			iRv = -2 ;	//	ダイヤグラムは表示されていません。
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
		CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getY() ;

		zoneCWndDiagram_Dgr = m_pCentDedDgrDia->getZone().getY() ;

		zonexyCWndDiagram_Dgr.setY( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;

		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	現在は実行できません。(エラーメッセージは表示しません)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramMemoriDown_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	int idxVlineMode = m_pCWndDiagram->getVlineMode() ;
	bool	bRv = true ;	
	if ( idxVlineMode <= 0 ){
		iRv = -1 ;	//	コマンドを無効
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		m_pCWndDiagram->setVlineMode( idxVlineMode - 1 ) ;

		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnDiagramMemoriUp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	int idxVlineMode = m_pCWndDiagram->getVlineMode() ;
	if ( idxVlineMode + 1 >= m_pCWndDiagram->getVlineChoices( NULL ) ){
		iRv = -1 ;	//	コマンドを無効
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		m_pCWndDiagram->setVlineMode( idxVlineMode + 1 ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramRessyabangou_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( m_pCWndDiagram->getDisplayRessyabangou() )
	{
		iRv = 1 ;
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		m_pCWndDiagram->setDisplayRessyabangou( 
			!m_pCWndDiagram->getDisplayRessyabangou() ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnUpdateDiagramRessyamei_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( m_pCWndDiagram->getDisplayRessyamei() )
	{
		iRv = 1 ;
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		m_pCWndDiagram->setDisplayRessyamei( 
			!m_pCWndDiagram->getDisplayRessyamei() ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramRessyasenKudari_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( m_pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Kudari ) )
	{
		iRv = 1 ;
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		m_pCWndDiagram->setDisplayRessyasen( Ressyahoukou_Kudari , 
			!m_pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Kudari ) ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramRessyasenNobori_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( m_pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Nobori ) )
	{
		iRv = 1 ;
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		m_pCWndDiagram->setDisplayRessyasen( Ressyahoukou_Nobori , 
			!m_pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Nobori ) ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnDiagramHideIppanekiEkimei_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( m_pCWndDiagram->getHideIppanekiEkimei() )
	{
		iRv = 1 ;	
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		m_pCWndDiagram->setHideIppanekiEkimei( 
			!m_pCWndDiagram->getHideIppanekiEkimei() ) ;	
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnDiagramStopmarkdraw_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( m_pCWndDiagram->getStopMarkDraw() == 
			CDcdDiagram::EStopMarkDraw_DrawOnBriefStop ) 
	{
		iRv = 1 ;
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		CDcdDiagram::EStopMarkDraw eStopMarkDraw 
			= CDcdDiagram::EStopMarkDraw_Nothing ;
		if ( m_pCWndDiagram->getStopMarkDraw() == 
			CDcdDiagram::EStopMarkDraw_Nothing )
		{
			eStopMarkDraw =CDcdDiagram::EStopMarkDraw_DrawOnBriefStop ;
		}
		m_pCWndDiagram->setStopMarkDraw( eStopMarkDraw ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnViewUpdate_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドを実行
		// ****************************************************************
		//	ビューを全更新します。
		OnUpdate( NULL , 0 , NULL ) ;
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramViewProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		//	ウインドウ内で、ダイヤグラムを描画する領域の大きさを求めます。
		//	単位は、 IfDcdTarget 上の座標です。
		CdDcdZoneXy	zoneDiagramZoneDcd = m_pCWndDiagram->calcDiagramZoneDcd() ;

		CDlgDiagramViewProp aDlg( 
			m_pCentDedDgrDia->getZone() ,
			//	ウインドウのX方向幅が、ダイヤグラムが表示可能な大きさであるか
			//	否かを指定
			zoneDiagramZoneDcd.getX().getSize() > 0 ,
			//	ウインドウのY方向幅が、ダイヤグラムが表示可能な大きさであるか
			//	否かを指定
			zoneDiagramZoneDcd.getY().getSize() > 0 ,
			m_pCWndDiagram->getZone_Dgr() ,
			m_pCWndDiagram->getVlineMode() ,
			this ) ;
		if ( aDlg.DoModal() == IDOK ){
			m_pCWndDiagram->setZone_Dgr( aDlg.getCWndDiagramZone_Dgr() );
			m_pCWndDiagram->setVlineMode( aDlg.getVlineMode() ) ;
		}	
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}


// ********************************
//	CDedDiagramView
// ********************************
	// ********************************
	//@name CDedDiagramView-操作
	// ********************************
int CDedDiagramView::setZone_Dgr( 
		const CdDedJikoku& aCdDedJikoku ,
		int iEkiIndex , bool bEkiIndexIsBottom ) 
{
	CdDcdZoneXy	zonexyZone_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	
	//X座標を変更
	if ( !aCdDedJikoku.isNull() ){
		CdDcdZone	aCdDcdZone = zonexyZone_Dgr.getX() ;
		aCdDcdZone.setPos( aCdDedJikoku.getTotalSeconds() ) ;
		zonexyZone_Dgr.setX( aCdDcdZone ) ;
	}
	//Y座標を変更
	if ( 0 <= iEkiIndex && iEkiIndex < getCentDedDia()->getEkiCount() ){
		CdDcdZone	aCdDcdZone = zonexyZone_Dgr.getY() ;
		int iYZahyou = m_pCentDedDgrDia->getDgrYPosOfEki( iEkiIndex ) ;
		if ( bEkiIndexIsBottom ){
			iYZahyou = iYZahyou - aCdDcdZone.getSize() ;
		}
		aCdDcdZone.setPos( iYZahyou ) ;
		zonexyZone_Dgr.setY( aCdDcdZone ) ;
	}
		
	return m_pCWndDiagram->setZone_Dgr( zonexyZone_Dgr ) ;
}

// ----------------------------------------------------------------
IMPLEMENT_DYNCREATE(CDedDiagramView, CView)

CDedDiagramView::CDedDiagramView()
	: m_pCentDedDgrDia( NULL )
	, m_pCWndDiagram( NULL ) 
	, m_bUpdate_All_Requested( false ) 
{
}

CDedDiagramView::~CDedDiagramView()
{
	if ( m_pCentDedDgrDia != NULL ){
		delete m_pCentDedDgrDia ;
		m_pCentDedDgrDia = NULL ;
	}
}


BEGIN_MESSAGE_MAP(CDedDiagramView, CView)
	//{{AFX_MSG_MAP(CDedDiagramView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_Diagram_ViewProp, OnDiagramViewProp)
	ON_COMMAND(ID_Diagram_XDgrSize_Inc, OnDiagramXDgrSizeInc)
	ON_UPDATE_COMMAND_UI(ID_Diagram_XDgrSize_Inc, OnUpdateDiagramXDgrSizeInc)
	ON_COMMAND(ID_Diagram_XDgrSize_Dec, OnDiagramXDgrSizeDec)
	ON_UPDATE_COMMAND_UI(ID_Diagram_XDgrSize_Dec, OnUpdateDiagramXDgrSizeDec)
	ON_COMMAND(ID_Diagram_YDgrSize_Inc, OnDiagramYDgrSizeInc)
	ON_UPDATE_COMMAND_UI(ID_Diagram_YDgrSize_Inc, OnUpdateDiagramYDgrSizeInc)
	ON_COMMAND(ID_Diagram_YDgrSize_Dec, OnDiagramYDgrSizeDec)
	ON_UPDATE_COMMAND_UI(ID_Diagram_YDgrSize_Dec, OnUpdateDiagramYDgrSizeDec)
	ON_COMMAND(ID_Diagram_Memori_Down, OnDiagramMemoriDown)
	ON_UPDATE_COMMAND_UI(ID_Diagram_Memori_Down, OnUpdateDiagramMemoriDown)
	ON_COMMAND(ID_Diagram_Memori_Up, OnDiagramMemoriUp)
	ON_UPDATE_COMMAND_UI(ID_Diagram_Memori_Up, OnUpdateDiagramMemoriUp)
	ON_COMMAND(ID_Diagram_Ressyabangou, OnDiagramRessyabangou)
	ON_UPDATE_COMMAND_UI(ID_Diagram_Ressyabangou, OnUpdateDiagramRessyabangou)
	ON_COMMAND(ID_Diagram_Ressyamei, OnDiagramRessyamei)
	ON_UPDATE_COMMAND_UI(ID_Diagram_Ressyamei, OnUpdateDiagramRessyamei)
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_Diagram_YDgrSize_Reset, OnDiagramYDgrSizeReset)
	ON_UPDATE_COMMAND_UI(ID_Diagram_YDgrSize_Reset, OnUpdateDiagramYDgrSizeReset)
	ON_COMMAND(ID_Diagram_RessyasenKudari, OnDiagramRessyasenKudari)
	ON_UPDATE_COMMAND_UI(ID_Diagram_RessyasenKudari, OnUpdateDiagramRessyasenKudari)
	ON_COMMAND(ID_Diagram_RessyasenNobori, OnDiagramRessyasenNobori)
	ON_UPDATE_COMMAND_UI(ID_Diagram_RessyasenNobori, OnUpdateDiagramRessyasenNobori)
	ON_COMMAND(ID_Diagram_HideIppanekiEkimei, OnDiagramHideIppanekiEkimei)
	ON_UPDATE_COMMAND_UI(ID_Diagram_HideIppanekiEkimei, OnUpdateDiagramHideIppanekiEkimei)
	ON_COMMAND(ID_VIEW_UPDATE, OnViewUpdate)
	//}}AFX_MSG_MAP
	// 標準印刷コマンド
	ON_COMMAND(ID_Diagram_StopMarkDraw, &CDedDiagramView::OnDiagramStopmarkdraw)
	ON_UPDATE_COMMAND_UI(ID_Diagram_StopMarkDraw, &CDedDiagramView::OnUpdateDiagramStopmarkdraw)
	ON_COMMAND(ID_FILE_PRINT, &CDedDiagramView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDedDiagramView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView 描画

void CDedDiagramView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
}

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView 診断

#ifdef _DEBUG
void CDedDiagramView::AssertValid() const
{
	CView::AssertValid();
}

void CDedDiagramView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView メッセージ ハンドラ



void CDedDiagramView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
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

	if ( m_bUpdate_All_Requested )
	{
		//	全更新が保留されている場合は、
		//	その後はコマンドによる最適化された単体のいかなる
		//	更新要求に対しても、全更新を行います。
		//memo:CDedDiagramViewの全更新
		//	これを行わないと、
		//	(1)ダイヤグラムビューを開いた状態にする
		//	(2)駅を追加
		//		( m_bUpdate_All_Requested =true となりますが、
		//		ビューがアクティブでないため、
		//		CentDedDgrDia::m_CentDedDgrEkiCont の
		//		更新が行われません。
		//	(3)その駅に運行する列車を入力する
		//		編集コマンドは CRfEditCmd_Ressya 
		//		なので、列車の更新が行われます。
		//		しかし、CentDedDgrDia::m_CentDedDgrEkiCont が
		//		更新されていないため、アプリケーションエラーになります。
		//		
		pHint = NULL ;
	}


	// --------------------------------
	//	CRfEditCmd に最適化された更新
	// --------------------------------
	Ou<CRfEditCmd> pCmd ;
	if ( pHint != NULL && pHint->IsKindOf( 
		RUNTIME_CLASS( CRfEditCmdHolder ) ) )
	{
		CRfEditCmdHolder* pHolder = 
			(CRfEditCmdHolder*)pHint ;
		pCmd = pHolder->getCmd() ; 
	}
	//pCmd = (pCmdがNULLでない場合は)対応する編集コマンド

	if ( pCmd != NULL )
	{
		if ( dynamic_castOu<CRfEditCmd_Comment>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Dia>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd ) ) 
		{
			//	このビューは、
			//		コメントの変更
			//		ダイヤの変更
			//		ダイヤのプロパティの変更
			//		列車種別の入替
			//	の場合は、更新を行いません。
		}
		else if ( dynamic_castOu<CRfEditCmd_Ressya>( pCmd ) )
		{
			//	列車の変更
			Ou<CRfEditCmd_Ressya>	pCommand = 
				dynamic_castOu<CRfEditCmd_Ressya>( pCmd );
			OnUpdate_CentDedRessya( pCommand ) ;
		}
		else
		{
			//CRfEditCmd_Eki
			//	駅の変更は、全更新が必要です。
			//CRfEditCmd_Ressyasyubetsu
			//	列車種別の変更は、全更新が必要です。
			//CRfEditCmd_DedRosenFileDataProp
			//	  路線ファイルのプロパティの変更は、
			//	フォントの変化を伴うため、全更新が必要です。
			//CRfEditCmd_Rosen
			//CRfEditCmd_RosenFileData
			//	駅を包含するオブジェクトです。これが更新された場合は、
			//	全更新が必要です。

			pHint = NULL ;	//	全更新の要求
		}
	}

	if ( pHint == NULL )	//	全更新
	{
		// --------------------------------		
		//	全要素を更新
		// --------------------------------
		CView *pView = getCDiagramEditApp()->getCMainFrame()->
			getMDIChildActiveView() ;
		if ( this == pView ){
			OnUpdate_All() ;
		}	else	{
			LogMsg( "CDedDiagramView::OnUpdate()" 
				"m_bUpdate_All_Requested=true" ) ;
			m_bUpdate_All_Requested = true ;
		}
	}

}

int CDedDiagramView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// --------------------------------
	m_pCWndDiagram = new CWndDiagram() ;
	m_pCWndDiagram->Create( this ) ;
	m_pCWndDiagram->ShowWindow( SW_SHOW ) ;

	return 0;
}

void CDedDiagramView::OnDestroy() 
{
	//	ダイヤグラムビューの属性を .ini ファイルに書き込み。
	getCDiagramEditApp()->writeCWndDiagramViewProp( m_pCWndDiagram ) ;

	m_pCWndDiagram->setCentDedDgrDia( NULL ) ;
	if ( m_pCWndDiagram != NULL ){
		m_pCWndDiagram->DestroyWindow() ;
		delete m_pCWndDiagram ;
		m_pCWndDiagram = NULL ;
	}

	CView::OnDestroy();
	

	
}

void CDedDiagramView::OnSize(UINT nType, int cx, int cy) 
{
	if ( nType == SIZE_MAXIMIZED	//ウィンドウは最大表示されます。
		|| nType == SIZE_RESTORED 	// ウィンドウはサイズ変更されますが、
									//	SIZE_MINIMIZED と SIZE_MAXIMIZED は
									//	適用されません。
	){
		//memo:CDedDiagramView::OnSize()
		//	この関数を使うと、リサイズ時にウインドウの全領域が無効になります。
		m_pCWndDiagram->MoveWindow( 0 , 0 , cx , cy , TRUE ) ; 

		////memo:CDedDiagramView::OnSize()
		////	この関数を使っても、リサイズ時にウインドウの
		////	全領域が無効になります
		//m_pCWndDiagram->SetWindowPos( 
		//	NULL , 
		//	0 , 0 , 
		//	cx , cy , 
		//	SWP_NOACTIVATE	//	ウィンドウをアクティブにしません。
		//	                //	このフラグが設定されていないと、
		//	                //	ウィンドウはアクティブになり、
		//	                //	最上位または非最上位のウィンドウ 
		//	                //	グループのいずれかの先頭に移動されます 
		//	                //(パラメータ pWndInsertAfter の設定に依存します)。
		//	| SWP_NOZORDER	//  現在の順序を保持します 
		//	                //	(pWndInsertAfter を無視します)。
		//	| SWP_NOMOVE ) ;// 現在位置を保持します 
		//	                //(x パラメータと y パラメータを無視します)。

		////memo:CDedDiagramView::OnSize()
		////	この関数を使っても、リサイズ時にウインドウの
		////	全領域が無効になります。
		//m_pCWndDiagram->MoveWindow( 0 , 0 , cx , cy , FALSE ) ; 

		return ;
	}
	
	
	CView::OnSize(nType, cx, cy);
}


void CDedDiagramView::OnDiagramViewProp() 
{
	OnDiagramViewProp_Process( FALSE );
}

void CDedDiagramView::OnDiagramXDgrSizeInc() 
{
	OnDiagramXDgrSizeInc_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramXDgrSizeInc(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramXDgrSizeInc_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramXDgrSizeDec() 
{
	OnDiagramXDgrSizeDec_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramXDgrSizeDec(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramXDgrSizeDec_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramYDgrSizeInc() 
{
	OnDiagramYDgrSizeInc_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramYDgrSizeInc(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramYDgrSizeInc_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramYDgrSizeDec() 
{
	OnDiagramYDgrSizeDec_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramYDgrSizeDec(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramYDgrSizeDec_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramYDgrSizeReset() 
{
	OnDiagramYDgrSizeReset_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramYDgrSizeReset(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramYDgrSizeReset_Process( TRUE ) >= 0 );
}


void CDedDiagramView::OnDiagramMemoriDown() 
{
	OnDiagramMemoriDown_Process( FALSE ) ;
}
void CDedDiagramView::OnUpdateDiagramMemoriDown(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnDiagramMemoriDown_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramMemoriUp() 
{
	OnDiagramMemoriUp_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramMemoriUp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnDiagramMemoriUp_Process( TRUE ) >= 0 );
}


void CDedDiagramView::OnDiagramRessyabangou() 
{
	OnDiagramRessyabangou_Process( FALSE ) ;
}
void CDedDiagramView::OnUpdateDiagramRessyabangou(CCmdUI* pCmdUI) 
{
	int iResult = OnDiagramRessyabangou_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
	
}

void CDedDiagramView::OnDiagramRessyamei() 
{
	OnUpdateDiagramRessyamei_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramRessyamei(CCmdUI* pCmdUI) 
{
	int iResult = OnUpdateDiagramRessyamei_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}


void CDedDiagramView::OnDiagramRessyasenKudari() 
{
	OnDiagramRessyasenKudari_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramRessyasenKudari(CCmdUI* pCmdUI) 
{
	int iResult = OnDiagramRessyasenKudari_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}

void CDedDiagramView::OnDiagramRessyasenNobori() 
{
	OnDiagramRessyasenNobori_Process( FALSE );
}

void CDedDiagramView::OnUpdateDiagramRessyasenNobori(CCmdUI* pCmdUI) 
{
	int iResult = OnDiagramRessyasenNobori_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}


void CDedDiagramView::OnDiagramHideIppanekiEkimei() 
{
	OnDiagramHideIppanekiEkimei_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramHideIppanekiEkimei(CCmdUI* pCmdUI) 
{
	int iResult = OnDiagramHideIppanekiEkimei_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}

void CDedDiagramView::OnDiagramStopmarkdraw()
{
	OnDiagramStopmarkdraw_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramStopmarkdraw(CCmdUI *pCmdUI)
{
	int iResult = OnDiagramStopmarkdraw_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}

void CDedDiagramView::OnViewUpdate() 
{
	OnViewUpdate_Process( FALSE );
}



BOOL CDedDiagramView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	BOOL bRv = TRUE ;

	// デフォルトの印刷準備
	CaDcdDiagram_PageSelector	aPageSelector( 
		m_pCWndDiagram->getCDcdDiagram() , 
		m_sizePrintSize_Dgr ) ;
	if ( bRv )
	{
		if ( aPageSelector.getPageCount() == 0 )
		{
			//	印刷するページがありません。
			bRv = FALSE ;
		}
	}
	if ( bRv )
	{
		//	ウインドウ上にダイヤグラムが表示されていない場合は、
		//	印刷は行いません。
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getX().getSize() <= 0 ||
			m_pCWndDiagram->calcDiagramZoneDcd().getY().getSize() <= 0 )
		{
			//	印刷するページがありません。
			bRv = FALSE ;
		}
	}
	// --------------------------------

	if ( bRv )
	{
		pInfo->SetMinPage( 1 ) ;
		pInfo->SetMaxPage( aPageSelector.getPageCount()  ) ;

		bRv = DoPreparePrinting(pInfo);
	}
	
	return bRv ;
}

void CDedDiagramView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	//	この時点では、 
	//	pInfo->m_rectDraw
	//	の値は決定していません。

	if ( m_bUpdate_All_Requested ){
		OnUpdate_All() ;
	}


	CView::OnBeginPrinting(pDC, pInfo);
}

void CDedDiagramView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	//	この時点では、 
	//	pInfo->m_rectDraw
	//	の値は決定していません。

	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	
	CView::OnPrepareDC(pDC, pInfo);
}


static CdDrawTextProp	getCdDrawTextPropStandard()
{ 
	const CDedRosenFileData* pCDedRosenFileData = 
		getCDiagramEditDoc()->getCDedRosenFileData() ;
	CdDedDispProp aCdDedDispProp = pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		aCdDedDispProp.getDiaJikokuFont() ,
		CdColorProp( 0 , 0 , 0 ) ) ;
}


void CDedDiagramView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	LogMsg( "CDedDiagramView::OnPrint() " ) ;
	LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;

	// --------------------------------
	//	描画面を作成
	// --------------------------------
	CDcdTargetMfcPrintInfo	aCDcdTargetMfcPrintInfo( pDC, pInfo ) ;

	LogMsg( "CDedDiagramView::OnPrint()1" ) ;
	
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

	LogMsg( "CDedDiagramView::OnPrint()2" ) ;
	// --------------------------------
	//	論理座標を設定
	// --------------------------------
	CaDcdTargetZoomDisplay	aCaDcdTargetZoomDisplay( 
		&aTargetInnerMargin , 
		aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
	//aCaDcdTargetZoomDisplay = 余白部分を除いた描画領域。
	//	単位は、画面上の１ピクセル相当になりました。

	LogMsg( "CDedDiagramView::OnPrint()3" ) ;
	
	// --------------------------------
	//	キャプションとページ番号の部品を作成
	// --------------------------------
	Ou<CDcdText>	pdcdCaption ;
	Ou<CDcdText>	pdcdPage ;
	{
		const CentDedRosen* pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		CJikokuhyouDoc* pCJikokuhyouDoc = (CJikokuhyouDoc*)GetDocument() ;

		string	strText ;
		//	路線名
		if ( !pCentDedRosen->getName().empty() ){
			strText += pCentDedRosen->getName() ;
			strText += " " ;
		}
		//	ダイヤ名
		if ( !pCJikokuhyouDoc->getDiaName().empty() ){
			strText += pCJikokuhyouDoc->getDiaName() ;
			strText += " " ;
		}
		pdcdCaption = OuNew<CDcdText>( new CDcdText( 
			strText , getCdDrawTextPropStandard() ) ) ;
	}
	// --------------------------------
	{
		CdDrawTextProp	aProp = getCdDrawTextPropStandard() ;
		CdDrawTextFormat	aFormat = aProp.getCdDrawTextFormat() ;
		aFormat.setHorizontal( aFormat.H_CENTER ) ;
		aProp.setCdDrawTextFormat( aFormat ) ;
		pdcdPage = OuNew<CDcdText>( new CDcdText( "" ,aProp , "99" ) ) ;
	}

	LogMsg( "CDedDiagramView::OnPrint()4" ) ;
	// --------------------------------
	//	キャプションとページ番号の部品・
	//	グリッドのレイアウトを決める	
	// --------------------------------
	Ou<IfDcdTarget>	pTargetCaption ;
	Ou<IfDcdTarget>	pTargetGrid ;
	Ou<IfDcdTarget>	pTargetPage ;
	{
		CdDcdZoneXy	zoneGrid = aCaDcdTargetZoomDisplay.getZone() ;
		CdDcdSizeXy	aSize ;

		pdcdCaption->getItemSize( &aCaDcdTargetZoomDisplay , &aSize ) ;
		CdDcdZoneXy zoneCaption( zoneGrid.getX() , 
			CdDcdZone( zoneGrid.getY().getPos() , aSize.getY() ) ) ;
		zoneGrid.setY( CdDcdZone().setBeginEndPos( 
			zoneCaption.getY().getEndPos() , zoneGrid.getY().getEndPos() ) ) ;
		//zoneCaption = 全領域の上部を、キャプション用に割り当てています。
		//zoneGrid = 全領域から、上部のキャプション領域を除いた領域です。

		pdcdPage->getItemSize( &aCaDcdTargetZoomDisplay , &aSize ) ;
		CdDcdZoneXy zonePage( zoneGrid.getX() , 
			CdDcdZone( zoneGrid.getY().getEndPos() - aSize.getY() , 
				aSize.getY() ) ) ;
		zoneGrid.setY( CdDcdZone().setBeginEndPos( 
			zoneCaption.getY().getEndPos() , zonePage.getY().getPos() ) ) ;
		//zonePage = 全領域の下部を、ページ用に割り当てています。
		//zoneGrid = 上部のキャプションに続いて、下部のページ領域も除いた
		//			領域です。


		pTargetCaption = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( 
				&aCaDcdTargetZoomDisplay , zoneCaption ) ) ;
		pTargetGrid = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( 
				&aCaDcdTargetZoomDisplay , zoneGrid ) ) ;
		pTargetPage = OuNew<CaDcdTargetItemPosition>(
			new CaDcdTargetItemPosition( 
				&aCaDcdTargetZoomDisplay , zonePage ) ) ;
	}
	// --------------------------------
	//	ダイヤグラムを描画
	// --------------------------------
	int iPage = 0 ;
	int iXPage = 0 ;
	{
		CDcdDiagram2*	pCDcdDiagram2 = m_pCWndDiagram->getCDcdDiagram() ;
		CaDcdDiagram_PageSelector	aPageSelector( 
			pCDcdDiagram2 , 
			m_sizePrintSize_Dgr ) ;
		aPageSelector.setPage( pInfo->m_nCurPage - 1 ) ;
		aPageSelector.DcDraw( pTargetGrid ) ;

		if ( (int)pInfo->m_nCurPage >= aPageSelector.getPageCount() ){
			//最終ページを印刷したら、印刷ループを終わります。
			pInfo->m_bContinuePrinting = false ;
		}	else	{
			pInfo->m_bContinuePrinting = true ;
		}


		iPage = aPageSelector.getPage() ;
		iXPage = aPageSelector.getXPage() ;
	}

	LogMsg( "CDedDiagramView::OnPrint()5" ) ;
	LogMsg( "CDedDiagramView::OnPrint()6" ) ;
	// --------------------------------
	//	キャプションとページ番号のテキストを作成
	// --------------------------------
	{
		//キャプションにページを追加
		{
			string	strCaption = pdcdCaption->getText() ;
			CString	strSono ;
			strSono.Format( IDS_WORD_Sono , iXPage + 1 ) ;
			strCaption += (LPCTSTR)strSono ;
			strCaption += " " ;
			pdcdCaption->setText( strCaption ) ;
		}
		//ページ番号も決定
		{
			string	strPage = stringOf( iPage + 1) ;
			pdcdPage->setText( strPage ) ;
		}
	}

	LogMsg( "CDedDiagramView::OnPrint()7" ) ;
	// --------------------------------
	//	キャプションとページ番号を描画
	// --------------------------------
	{
			pdcdCaption->DcDraw( pTargetCaption ) ;
			pdcdPage->DcDraw( pTargetPage ) ;
	}
	// --------------------------------
	
	//CView::OnPrint(pDC, pInfo);
}

void CDedDiagramView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{

	//	印刷終了後に画面表示が崩れる問題を回避。
	//
	//	このクラスは、印刷中はスクロール位置を
	//	一時的に変更します。
	//	このときに m_pCWndDiagram に再描画が発生すると、
	//	画面には一時的に位置の変更されたコンテンツが
	//	描画されるため、画面が崩れます。
	m_pCWndDiagram->Invalidate() ;
	
	CView::OnEndPrinting(pDC, pInfo);
}

void CDedDiagramView::OnSetFocus(CWnd* pOldWnd) 
{
	//CView::OnSetFocus(pOldWnd);
	CWnd*	pControl = GetNextDlgTabItem( (CWnd*)NULL , FALSE ) ;
	pControl->SetFocus() ;
	
}


void CDedDiagramView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	LogMsg( "CDedDiagramView::OnActivateView(%d,,)" , bActivate ) ;
	
	if ( bActivate && m_bUpdate_All_Requested ){
		OnUpdate_All() ;
	}
	
	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}



void CDedDiagramView::OnFilePrint()
{
	//	印刷時に、１ページに印刷するダイヤグラムの範囲を保存
	m_sizePrintSize_Dgr = m_pCWndDiagram->getZone_Dgr().getSize() ;

	CView::OnFilePrint() ;
}

void CDedDiagramView::OnFilePrintPreview()
{
	//	印刷時に、１ページに印刷するダイヤグラムの範囲を保存
	m_sizePrintSize_Dgr = m_pCWndDiagram->getZone_Dgr().getSize() ;

	CView::OnFilePrintPreview() ;
}
} // namespace ViewDiagram
