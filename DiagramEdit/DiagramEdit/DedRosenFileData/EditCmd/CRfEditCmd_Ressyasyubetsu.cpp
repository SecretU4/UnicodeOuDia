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
/*
// ****************************************************************
//	CRfEditCmd_Ressyasyubetsu.cpp
// $Id: CRfEditCmd_Ressyasyubetsu.cpp 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
#include "stdafx.h"
#include "NsMu/CaMui.h"
#include "NsOu/OuNew.h"
#include "CRfEditCmd_Ressyasyubetsu.h"

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif



namespace DedRosenFileData{ namespace EditCmd{

// ****************************************************************
//	CRfEditCmd_Ressyasyubetsu
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CRfEditCmd_Ressyasyubetsu::
	CRfEditCmd_Ressyasyubetsu( 
		int iIndexDst ,
		int iSizeDst ,
		const CentDedRessyasyubetsuCont& aCentDedRessyasyubetsuContSrc ) :
	m_iIndexDst( iIndexDst ) ,
	m_iSizeDst( iSizeDst ) ,
	m_CentDedRessyasyubetsuContSrc( aCentDedRessyasyubetsuContSrc ) ,
	m_CaMuiSelect( &m_CentDedRessyasyubetsuContSrc , m_CentDedRessyasyubetsuContSrc.getMuPtr() ) ,
	m_pCentDedRessyasyubetsuContOld( NULL ) ,
	m_pCentDedRosen( NULL ) 
{
	m_CaMuiSelect.setSelectAll( true ) ;
}

CRfEditCmd_Ressyasyubetsu::
	CRfEditCmd_Ressyasyubetsu( 
		const CDedRosenFileData& aCDedRosenFileData ,
		int iIndexDst , 
		int iSizeDst ) : 
	m_iIndexDst( iIndexDst ) ,
	m_iSizeDst( iSizeDst ) ,
	m_CentDedRessyasyubetsuContSrc() ,
	m_CaMuiSelect( &m_CentDedRessyasyubetsuContSrc , m_CentDedRessyasyubetsuContSrc.getMuPtr() ) ,
	m_pCentDedRessyasyubetsuContOld( NULL ) ,
	m_pCentDedRosen( NULL ) 
{
	const CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont 
		= aCDedRosenFileData.getCentDedRosen()->getCentDedRessyasyubetsuCont() ; 

	CaMui<CentDedRessyasyubetsu> aMui( &m_CaMuiSelect ) ;
	aMui.insert( pCentDedRessyasyubetsuCont , iIndexDst , iSizeDst ) ;

	m_CaMuiSelect.setSelectAll( true ) ;
}		



CRfEditCmd_Ressyasyubetsu::
	~CRfEditCmd_Ressyasyubetsu() 
{
	if ( m_pCentDedRessyasyubetsuContOld != NULL )
	{
		delete m_pCentDedRessyasyubetsuContOld ;
		m_pCentDedRessyasyubetsuContOld = NULL ;
	}
	if ( m_pCentDedRosen !=  NULL ) 
	{
		delete m_pCentDedRosen ;
		m_pCentDedRosen = NULL ;
	}
}
// ********************************
//@name	CRfEditCmd-操作
// ********************************
int 
CRfEditCmd_Ressyasyubetsu::
	execute( CDedRosenFileData* pCDedRosenFileData ) 
{
	int iRv = 0 ;
	// --------------------------------
	CentDedRosen*	pCentDedRosen = pCDedRosenFileData->getCentDedRosen() ;
	CentDedRessyasyubetsuCont*	pCentDedRessyasyubetsuCont = 
		pCentDedRosen->getCentDedRessyasyubetsuCont() ;
	if ( iRv >= 0 ){
		if ( m_iIndexDst == INT_MAX && m_iSizeDst == INT_MAX ){
			iRv = -1 ;	//	m_iIndexDst の値が不正です。
		}	else	{
			if ( m_iIndexDst == INT_MAX ){
				m_iIndexDst = pCentDedRessyasyubetsuCont->size()  - m_iSizeDst ;
			}	else if ( m_iSizeDst == INT_MAX ){
				m_iSizeDst = pCentDedRessyasyubetsuCont->size() - m_iIndexDst ;
			}
			if ( !( 0 <= m_iIndexDst && 
				m_iIndexDst + m_iSizeDst <= 
					pCentDedRessyasyubetsuCont->size() ) ){
				iRv = -1 ;	//	m_iIndexDst の値が不正です。
			}
		}
	}
	// --------------------------------
	//	削除データを保存
	// --------------------------------
	if ( iRv >= 0 ){
		if ( m_pCentDedRessyasyubetsuContOld != NULL ){
			delete m_pCentDedRessyasyubetsuContOld ;
			m_pCentDedRessyasyubetsuContOld = NULL ;
		}
		if ( m_pCentDedRosen != NULL ){
			delete m_pCentDedRosen ;
			m_pCentDedRosen = NULL ;
		}
		//	要素を置換え・または追加を行った場合
		if ( m_iSizeDst <= m_CentDedRessyasyubetsuContSrc.size() ){
			m_pCentDedRessyasyubetsuContOld = new CentDedRessyasyubetsuCont() ;
			CaMui<CentDedRessyasyubetsu>	aCaCont( m_pCentDedRessyasyubetsuContOld ) ;
			aCaCont.insert( 
				pCentDedRessyasyubetsuCont , 
				m_iIndexDst , 
				m_iSizeDst , 0 ) ;
		}
		//	要素の削除の場合は、路線全体を保存する必要があります
		//	(削除された列車種別を持つ列車が復旧できなくなるため)
		else
		{
			m_pCentDedRosen = new CentDedRosen( *pCentDedRosen ) ; 
		}
	}
	// --------------------------------
	//	減少分の要素の削除
	// --------------------------------
	if ( iRv >= 0 ){
		int iGensyouSize = m_iSizeDst - m_CentDedRessyasyubetsuContSrc.size() ;
		if ( iGensyouSize > 0 ){
			int iResult = pCentDedRessyasyubetsuCont->erase( 
				m_iIndexDst + m_iSizeDst - iGensyouSize , 
				iGensyouSize
			) ;
			if ( iResult < 0 ){
				iRv = -11 ;	//	要素の削除に失敗しました。
			}
		}
	}
	// --------------------------------
	//	要素の置き換え
	// --------------------------------
	int iOkikaeSize = 0 ;
	if ( iRv >= 0 ){
		iOkikaeSize = 
			min( m_iSizeDst , m_CentDedRessyasyubetsuContSrc.size() ) ;
		for ( int cnt = 0 ; iRv >= 0 && cnt < iOkikaeSize ; cnt ++ ){
			int iResult = pCentDedRessyasyubetsuCont->set( 
				m_CentDedRessyasyubetsuContSrc.get( cnt ) , 
				m_iIndexDst + cnt )  ;
			if ( iResult < 0 ){
				iRv = -13 ;	//	要素の置き換えに失敗しました。
			}
		}
	}
	// --------------------------------
	//	増加分の要素の追加
	// --------------------------------
	if ( iRv >= 0 ){
		int iZoukaSize = m_CentDedRessyasyubetsuContSrc.size() - m_iSizeDst ;
		if ( iZoukaSize > 0 ){
			for ( int cnt = 0 ; iRv >= 0 && cnt < iZoukaSize ; cnt ++ ){
				int iResult = pCentDedRessyasyubetsuCont->insert(
					m_CentDedRessyasyubetsuContSrc.get( iOkikaeSize + cnt ) ,
					m_iIndexDst + iOkikaeSize + cnt ) ; 
				if ( iResult < 0 ){
					iRv = -12 ;	//	要素の追加に失敗しました。
				}
			}
		}

	}
	return ( iRv ) ;
}
	
Ou<CRfEditCmd> CRfEditCmd_Ressyasyubetsu::
	createUndoCmd() 
{
	if ( m_pCentDedRessyasyubetsuContOld != NULL ){
		OuNew<CRfEditCmd>	pCmd( 
			new CRfEditCmd_Ressyasyubetsu( 
				m_iIndexDst ,
				m_CentDedRessyasyubetsuContSrc.size() ,
				*m_pCentDedRessyasyubetsuContOld  ) ) ;
		delete m_pCentDedRessyasyubetsuContOld ;
		m_pCentDedRessyasyubetsuContOld = NULL ;
		return pCmd ;
	}
	if ( m_pCentDedRosen != NULL ){
		OuNew<CRfEditCmd>	pCmd( 
			new CRfEditCmd_Rosen( 
				*m_pCentDedRosen  ) ) ;
		delete m_pCentDedRosen ;
		m_pCentDedRosen = NULL ;
		return pCmd ;
	}
	return ( Ou<CRfEditCmd>() ) ;
}
	
} } // namespace EditCmd namespace DedRosenFileData
