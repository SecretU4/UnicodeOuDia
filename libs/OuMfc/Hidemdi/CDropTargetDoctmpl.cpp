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
//	CDropTargetDoctmpl.cpp
// ****************************************************************
*/
#include "CDropTargetDoctmpl.h"

namespace OuMfc{
namespace Hidemdi{

// ****************************************************************
//	CDropTargetDoctmpl
// ****************************************************************
int CDropTargetDoctmpl::HdropToFilenames( HDROP pdropgmemEHdrop 
								, CStringArray* pastrExt ) 
		//	このドロップターゲットに到着したHDROPハンドルから、
		//	拡張子を取り出します。
		//hgmemEHdrop
		//	ドロップターゲットに到着したHDROPハンドルを指定してください。
		//pastrExt
		//	この関数は、この文字列配列に、ドロップされたﾌｧｲﾙの一覧を
		//	格納します。
		//	必要ないならNULLでかまいません。
		//[r]
		//	ﾌｧｲﾙの数を返します
{
	CStringArray	LArray ;
	if ( pastrExt == NULL ){
		pastrExt = &LArray ;
	}

	int	iLDropNof = DragQueryFile( pdropgmemEHdrop 
										, 0xffffffff , NULL, 0 ) ;
	int	iLi ;
	for ( iLi = 0 ; iLi < iLDropNof ; iLi ++ ){
		int	iLFilenameSz = DragQueryFile( pdropgmemEHdrop 
												, iLi , NULL, 0 ) + 1 ;
		TCHAR* lpszFilename = new TCHAR[ iLFilenameSz ] ;
		DragQueryFile( pdropgmemEHdrop , iLi , lpszFilename , iLFilenameSz ) ;
			//	lpszFilename = ドロップされたファイル（レコード）の名称です

		pastrExt->Add( lpszFilename ) ;		

		delete[] lpszFilename ;
		
	}
	return ( iLDropNof ) ;	
}

int CDropTargetDoctmpl::FilenamesNoExtRemove
			( const CStringArray& astrEExt , CStringArray* pastrFilename ) 
{
	int	iRv = 0 ;
	
	int	idxLFilename ;
	for ( idxLFilename = 0 
			; idxLFilename < pastrFilename->GetSize()
			; idxLFilename ++ ){
		int	idxLExt ;
		for ( idxLExt = 0 
				; idxLExt < astrEExt.GetSize()
				; idxLExt ++ ){
			if ( (*pastrFilename)[idxLFilename].GetLength() > astrEExt[idxLExt].GetLength() ){
				if ( (*pastrFilename)[idxLFilename].
						Right( astrEExt[idxLExt].GetLength() ).
						CompareNoCase( astrEExt[idxLExt] ) == 0 ){
					break ;
				}
			}
		}
		if ( idxLExt == astrEExt.GetSize() ){
			pastrFilename->RemoveAt( idxLFilename ) ;
			idxLFilename -- ;
			iRv ++ ;
		}
		 
	}
	return ( iRv ) ;
}
// ********************************
//	コンストラクタ
// ********************************
CDropTargetDoctmpl::CDropTargetDoctmpl( BOOL bEAcceptSingle ) 
		//bEAcceptSingle ;
		//	ﾌｧｲﾙ１つだけのドロップを受け付けます（SDIで使います）
{
	m_bAcceptSingle = bEAcceptSingle ;
		//	ﾌｧｲﾙ１つだけのドロップを受け付けます（SDIで使います）
	
}

CDropTargetDoctmpl::~CDropTargetDoctmpl() 
{
}
	
// ********************************
//	COleDropTarget
// ********************************
DROPEFFECT CDropTargetDoctmpl::OnDragEnter( CWnd* pWnd
						, COleDataObject* pDataObject
						, DWORD dwKeyState, CPoint point )
		//【オーバライド】
		//	CWinAppに対して、このアプリケーションがサポートしている拡張子を
		//	問い合わせて、その結果を m_astrExt に保存します。
		//	ドラッグされているのが、アプリケーションでサポートしている拡張子
		//	であった場合は、このドロップターゲットへのコピーを受け付けます
{
	m_astrExt.RemoveAll() ;
	


	POSITION	LPosition = AfxGetApp()->GetFirstDocTemplatePosition() ;
	while( LPosition != NULL ){
		CDocTemplate*	pLTemplate = AfxGetApp()->GetNextDocTemplate( LPosition ) ;
		CString	strLExt ;
		pLTemplate->GetDocString( strLExt , CDocTemplate::filterExt ) ;
		if ( strLExt.GetLength() >= 2 && strLExt[0] == _T( '.' ) ){
			m_astrExt.Add( strLExt ) ;
		}
	}
	
	
	return ( OnDragOver( pWnd, pDataObject , dwKeyState, point ) ) ;
}

DROPEFFECT CDropTargetDoctmpl::OnDragOver( CWnd* pWnd, COleDataObject* pDataObject
										, DWORD dwKeyState, CPoint point )
		//【オーバライド】
		//	ドラッグされているのが、アプリケーションでサポートしている拡張子
		//	であった場合は、このドロップターゲットへのコピーを受け付けます
{
	if ( pDataObject->IsDataAvailable( CF_HDROP ) ){
		HGLOBAL	hLGlobal = pDataObject->GetGlobalData( CF_HDROP ) ;
		CStringArray	astrLFilename ;
		HdropToFilenames( (HDROP)hLGlobal , &astrLFilename ) ;
		GlobalFree( hLGlobal ) ;
		if ( m_bAcceptSingle && astrLFilename.GetSize() != 1 ){
			return ( DROPEFFECT_NONE ) ;
		}
		FilenamesNoExtRemove( m_astrExt , &astrLFilename ) ;
		if ( astrLFilename.GetSize() > 0 ) {
 			return ( DROPEFFECT_COPY ) ; 
		}
	}
	return ( DROPEFFECT_NONE ) ; 
}

void CDropTargetDoctmpl::OnDragLeave( CWnd* pWnd ) 
		//【オーバライド】
		//	特に処理はありません
{
}
	
BOOL CDropTargetDoctmpl::OnDrop( CWnd* pWnd, COleDataObject* pDataObject
									, DROPEFFECT dropEffect, CPoint point )
		//【オーバライド】
		//	ドラッグされているのが、アプリケーションでサポートしている拡張子
		//	であった場合は、そのファイル名を配列に格納して、DropProc() を
		//	呼び出します
{
	BOOL	bRv = FALSE ;
	
	if ( dropEffect == DROPEFFECT_COPY 
			&& pDataObject->IsDataAvailable( CF_HDROP ) ){
		HGLOBAL	hLGlobal = pDataObject->GetGlobalData( CF_HDROP ) ;
		CStringArray	astrLFilename ;
		HdropToFilenames( (HDROP)hLGlobal , &astrLFilename ) ;
		GlobalFree( hLGlobal ) ;
		if ( m_bAcceptSingle && astrLFilename.GetSize() != 1 ){
			return ( FALSE ) ;
		}
		FilenamesNoExtRemove( m_astrExt , &astrLFilename ) ;
		if ( astrLFilename.GetSize() > 0 ) {
 			return ( OnFiledrop( pWnd 
				, astrLFilename
				, dropEffect, point ) ) ;
 		}
	}
	return ( DROPEFFECT_NONE ) ; 
}


// ********************************
//	COleDropTarget
// ********************************
BOOL CDropTargetDoctmpl::OnFiledrop( CWnd* pWnd 
				, const CStringArray& astrEFilename
				, DROPEFFECT dropEffect, CPoint point ) 
		//pWnd
		//	カーソルが現在あるウィンドウへのポインタ
		//astrEFilename
		//	ドロップされるデータを持っているデータ オブジェクトへのポインタ。
		//dropEffect
		//	ユーザーが選択するドロップ操作の結果。次の値の 1 つ以上を
		//	組み合わせたものです。 
		//		DROPEFFECT_COPY   コピー操作が行われます。
		//		DROPEFFECT_MOVE   移動操作が行われます。
		//		DROPEFFECT_LINK   ドロップされたデータと元のデータが
		//			リンクされます。
		//		DROPEFFECT_SCROLL   ドラッグ スクロール操作がターゲット内で
		//			発生するところか、発生しています。 
		//point
		//	画面上におけるカーソルの位置をピクセル単位で指定します。
		//[r]
		//	ドロップが成功した場合は 0 以外を返します。
		//	それ以外の場合は 0 を返します。
{
	BOOL	bRv = TRUE ;
	int	idxLFilename ;
	for ( idxLFilename = 0 
			; bRv && idxLFilename < astrEFilename.GetSize()
			; idxLFilename ++ ){
		CDocument*	pLDocument = AfxGetApp()
			->OpenDocumentFile( astrEFilename[idxLFilename] ) ;
	}
	return ( bRv ) ;
}

} //namespace Hidemdi
} //namespace OuMfc

