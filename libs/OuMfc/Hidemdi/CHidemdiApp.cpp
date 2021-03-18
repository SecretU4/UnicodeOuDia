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
//	CHidemdiApp.cpp
// ****************************************************************
*/

#include <afxadv.h>
#include "CHidemdiApp.h"

namespace OuMfc{
namespace Hidemdi{


// ****************************************************************
//	CHidemdiApp
// ****************************************************************
//--------------------------------
//	下請関数
//--------------------------------
BOOL CHidemdiApp::RegisterRootDoctmpl
						( CHidemdiRootDoctmpl* prootdoctemplateEv ) 
		//[Attention]
		//	InitInstance() でDoctemplateを生成したときに、
		//	ルートDoctemplateオブジェクトのポインタを、このメソッドで
		//	登録してください。
{
	m_pdoctemplateRoot = prootdoctemplateEv ;
	return ( TRUE ) ;
}


CHidemdiRootDoctmpl*	CHidemdiApp::pRootDoctmpl() 
		//	ルートDoc/Viewのテンプレートへの
		//	ポインタを返します
{
	return ( m_pdoctemplateRoot ) ;
}

CHidemdiRootDoc* CHidemdiApp::pRootDoc() 
		//	ルートDocへのポインタを返します
{
	CDocument*	pRv = NULL ;
	if ( m_pdoctemplateRoot != NULL ){
		POSITION	LPosition = m_pdoctemplateRoot->GetFirstDocPosition() ;
		while( LPosition != NULL ){
			pRv = m_pdoctemplateRoot->GetNextDoc( LPosition ) ;
		}
	}
	//ASSERT( pRv != NULL ) ;
	return ( (CHidemdiRootDoc*)pRv ) ;
}

int CHidemdiApp::RemoveFromRecentFileList( LPCTSTR lpszEFilename ) 
		//	ファイル名を、MRUリストから削除します
		//lpszEFilename
		//	削除するファイル名を返します
		//[r]
		//	削除したエントリの数を返します
{
	int	iRv = 0 ;
	if ( m_pRecentFileList != NULL ){
		int	iLIdx ;
		for ( iLIdx = 0 ; iLIdx < m_pRecentFileList->GetSize() ; iLIdx ++ ){
			if ( (*m_pRecentFileList)[iLIdx] == lpszEFilename ){
				m_pRecentFileList->Remove( iLIdx ) ;
				iLIdx -- ;
				iRv ++ ;
			}
		}
	}
	return ( iRv ) ;
}

//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------

BEGIN_MESSAGE_MAP(CHidemdiApp, CHidemdiApp::super)
	//{{AFX_MSG_MAP(CHidemdiApp)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CHidemdiApp::CHidemdiApp()
{
	m_pdoctemplateRoot = NULL ;
		//[Attention]
		//	InitInstance() でCDocTemplateを登録するときに、
		//	ルートDoc/Viewのテンプレートへの
		//	ポインタを保持してください。
}

BOOL CHidemdiApp::InitInstance()
{
	return ( TRUE ) ;
}


void CHidemdiApp::OnFileNew() 
{
	m_pdoctemplateRoot->OpenDocumentFile( NULL ) ;
}

void CHidemdiApp::OnFileSave() 
{
	CHidemdiRootDoc*	pLRootDoc = pRootDoc() ;
	if ( pLRootDoc != NULL ){
		pLRootDoc->OnCmdMsg( ID_FILE_SAVE , 0 , NULL , NULL ) ;
	}
	
}

void CHidemdiApp::OnFileSaveAs() 
{
	CHidemdiRootDoc*	pLRootDoc = pRootDoc() ;
	if ( pLRootDoc != NULL ){
		pLRootDoc->OnCmdMsg( ID_FILE_SAVE_AS , 0 , NULL , NULL ) ;
	}
			//[Attention]
			//	コマンドハンドラを他のコマンドターゲットに
			//	委譲したい場合は、委譲先オブジェクトに対して、
			//	CCmdTarget::OnCmdMsg() を呼び出してください。
			//
			//virtual BOOL CCmdTarget::OnCmdMsg( UINT nID
			//	, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo );
			//[r]
			//メッセージが処理されたときは 0 以外を返します。それ以外は 0 を
			//	返します。
			//nID
			//   コマンド ID を指定してください。
			//nCode
			//	0を指定してください。
			//pExtra
			//	NULLを指定してください。
			//pHandlerInfo 
			//	NULLを指定してください。
}

void CHidemdiApp::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	CHidemdiRootDoc*	pLRootDoc = pRootDoc() ;
	if ( pLRootDoc != NULL ){
		pCmdUI->DoUpdate( pLRootDoc , FALSE ) ;
			//[Attention]
			//	上書き保存・名前をつけて保存のコマンドは、ルートドキュメントに
			//	委譲します

			//[Attention]
			//	コマンドのOnUpdate...()処理を他のコマンドターゲットに
			//	委譲したい場合は、CCmdUi::DoUpdate() を呼び出してください。
			//
			//BOOL CCmdUI::DoUpdate(CCmdTarget* pTarget
			//					, BOOL bDisableIfNoHndler)
			//	  コマンドのOnUpdate...()メソッドを、
			//	指定のCCmdTargetオブジェクトに対して呼び出します。
			//pTarget
			//	  OnUpdate...()メソッドを呼び出す
			//	CCmdTargetオブジェクトを指定してください。
			//bDisableIfNoHndler
			//	真なら、呼出先のコマンドにOnUpdate...()メソッドがない場合に、
			//	そのコマンドが禁止状態となります。
	}
}

void CHidemdiApp::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	CHidemdiRootDoc*	pLRootDoc = pRootDoc() ;
	if ( pLRootDoc != NULL ){
		pCmdUI->DoUpdate( pLRootDoc , FALSE ) ;
	}
}


BOOL CHidemdiApp::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	CHidemdiRootDoc* pCHidemdiRootDoc = pRootDoc() ;

	if ( pCHidemdiRootDoc != NULL )
	{
		if ( pCHidemdiRootDoc->OnCmdMsg( nID , nCode , pExtra , pHandlerInfo ) )
		{
			return TRUE ;
		}
	}

	return CWinApp::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

} //namespace Hidemdi
} //namespace OuMfc

