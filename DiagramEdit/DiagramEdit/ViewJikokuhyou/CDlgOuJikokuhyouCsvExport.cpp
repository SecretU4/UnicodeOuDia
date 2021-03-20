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
// CDlgOuJikokuhyouCsvExport.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "MfcUtil\MfcUtil.h"
#include "str\CsvDocument\CdCsvDocument.h"
#include "str\CsvDocument\CconvCsvDocument.h"
#include "str\strtoint.h"
#include "str\vectorToFile.h"

#include "..\diagramedit.h"
#include "..\resource.h"
#include "CDlgOuJikokuhyouCsvExport.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{
using namespace std ;

/////////////////////////////////////////////////////////////////////////////
// CDlgOuJikokuhyouCsvExport ダイアログ


CDlgOuJikokuhyouCsvExport::CDlgOuJikokuhyouCsvExport(
 	const CentDedRosen* pCentDedRosen ,
	int  iDiaIndex ,
	ERessyahoukou  eRessyahoukou ,
	CWnd* pParent )
	: CDialog(CDlgOuJikokuhyouCsvExport::IDD, pParent)
 	, m_pCentDedRosen( pCentDedRosen )
	, m_iDiaIndex( iDiaIndex ) 
	, m_eRessyahoukou( eRessyahoukou )
{
	//{{AFX_DATA_INIT(CDlgOuJikokuhyouCsvExport)
	//}}AFX_DATA_INIT
}


void CDlgOuJikokuhyouCsvExport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOuJikokuhyouCsvExport)
	DDX_Control(pDX, IDC_EDIT_RESSYACOUNT, m_wndEDIT_RESSYACOUNT);
	DDX_Control(pDX, IDC_EDIT_RESSYAINDEX, m_wndEDIT_RESSYAINDEX);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOuJikokuhyouCsvExport, CDialog)
	//{{AFX_MSG_MAP(CDlgOuJikokuhyouCsvExport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOuJikokuhyouCsvExport メッセージ ハンドラ

BOOL CDlgOuJikokuhyouCsvExport::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// --------------------------------
	int iRv = 0 ;
	const CentDedDia* pCentDedDia = NULL ;
	const Mu<const CentDedRessya*>* pCentDedRessyaContGet = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedDia = m_pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( m_iDiaIndex ) ;
		if ( pCentDedDia == NULL )
		{
			iRv = -11 ;	//	m_iDiaIndex が不正です。
		}
	}
	if 	( iRv >= 0 )
	{
		pCentDedRessyaContGet = pCentDedDia->getCentDedRessyaCont( m_eRessyahoukou )->getMuPtr() ;
	}
	//pCentDedRessyaContGet = 対象となる列車コンテナ
	
	
	// --------------------------------
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CDlgOuJikokuhyouCsvExport::OnOK() 
{
	int iRv = 0 ;
	CString	strError ;
	// --------------------------------
	const CentDedDia* pCentDedDia = NULL ;
	const Mu<const CentDedRessya*>* pCentDedRessyaContGet = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedDia = m_pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( m_iDiaIndex ) ;
		if ( pCentDedDia == NULL )
		{
			iRv = -11 ;	//	m_iDiaIndex が不正です。
		}
	}
	if 	( iRv >= 0 )
	{
		pCentDedRessyaContGet = pCentDedDia->getCentDedRessyaCont( m_eRessyahoukou )->getMuPtr() ;
	}
	//pCentDedRessyaContGet = 対象となる列車コンテナ
	
	
	// --------------------------------
	//	入力値の取得
	// --------------------------------
	int iRessyaIndex = 0 ;
	int iRessyaCount = 0 ;
	if ( iRv >= 0 )
	{
		CString aString ;
		GetDlgItemText( IDC_EDIT_RESSYAINDEX , aString ) ;
		BOOL bTrans = FALSE ;
		if ( !aString.IsEmpty() )
		{
			iRessyaIndex = (int)GetDlgItemInt( IDC_EDIT_RESSYAINDEX , &bTrans , FALSE ) - 1 ;
			if ( !bTrans || !( 0 <= iRessyaIndex && iRessyaIndex < pCentDedRessyaContGet->size() ) )
			{
				GetDlgItemText( IDC_TEXT_INPUTERROR , strError ) ;
				GotoDlgCtrl( GetDlgItem( IDC_EDIT_RESSYAINDEX ) ) ;
				iRv = -1 ;	//	入力エラーあり
			}
		}
		else
		{
			iRessyaIndex = 0 ;
		}
	}
	if ( iRv >= 0 )
	{
		CString aString ;
		GetDlgItemText( IDC_EDIT_RESSYACOUNT , aString ) ;
		BOOL bTrans = FALSE ;
		if ( !aString.IsEmpty() )
		{
			iRessyaCount = (int)GetDlgItemInt( IDC_EDIT_RESSYACOUNT , &bTrans , FALSE ) ;
			if ( !bTrans )
			{
				GetDlgItemText( IDC_TEXT_INPUTERROR , strError ) ;
				GotoDlgCtrl( GetDlgItem( IDC_EDIT_RESSYACOUNT ) ) ;
				iRv = -1 ;	//	入力エラーあり
			}
		}
		else
		{
			iRessyaCount = pCentDedRessyaContGet->size() - iRessyaIndex  ;
		}
	}
	if ( iRessyaCount > pCentDedRessyaContGet->size() - iRessyaIndex ) 
	{
		iRessyaCount = pCentDedRessyaContGet->size() - iRessyaIndex ;
	}
	//iRessyaIndex,iRessyaCount = 列車本数。
	
	// --------------------------------
	//	出力ファイル名入力値の取得
	// --------------------------------
	if ( iRv >= 0 )
	{
		CFileDialog aDlg( 
			FALSE , 
			_T( "csv" ) , 
			m_strCsvFilename , 
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
			getCDiagramEditApp()->getCFileDialogFilterCsv(), 
			this );
		if ( aDlg.DoModal() != IDOK )
		{
			iRv = -2 ;	//	Cancelされました。
		}
		else
		{
			m_strCsvFilename = aDlg.GetPathName() ;
		}
	}
	//m_strCsvFilename = 指定されたCSVファイル名
	// --------------------------------
	//	CSVファイルの出力
	// --------------------------------
	CWaitCursor aCursor ;
	if ( iRv >= 0 )
	{
		CconvJikokuhyouCsv	aConv( getCDiagramEditApp()->createCconvJikokuhyouCsv() ) ;
		CdCsvDocument	aCdCsvDocument ;
		int iResult = aConv.encode(
			*m_pCentDedRosen , 
			m_iDiaIndex , 
			m_eRessyahoukou , 
			iRessyaIndex , 
			iRessyaCount , 
			&aCdCsvDocument ) ;
		//iResult = 
		//	-1 ; // iDiaIndex が不正です。
		//	-2 ; // iRessyaIndex が不正です。
		//	-3 ; // iRessyaCount が不正です。 
		if ( iResult < 0 )
		{
			GetDlgItemText( IDC_TEXT_ENCODE_ERROR , strError ) ;
			//strError="CSVへの変換に失敗しました。"

			strError.Format( _T( "%s(%d)" ) , CString( strError ), iResult ) ; 
			iRv = iResult - 10 ;
			//	-11 ; // iDiaIndex が不正です。
			//	-12 ; // iRessyaIndex が不正です。
			//	-13 ; // iRessyaCount が不正です。 
		}
		else
		{
			string strCsvDocument ;
			CConvCsvDocument	aCConvCsvDocument ;
			strCsvDocument = aCConvCsvDocument.encode( &aCdCsvDocument ) ;
			int iResult = stringToFile( strCsvDocument , (LPCSTR)m_strCsvFilename ) ;
			if ( iResult < 0 )
			{
				GetDlgItemText( IDC_TEXT_FILE_SAVE_FAILED , strError ) ;
				//strError="ファイルへの保存に失敗しました。"

				iRv = -21 ; // ファイルへの保存に失敗しました。

			}
		}
	}
	// --------------------------------
	//	列車の範囲を指定してCSVへエクスポート
	//	した場合は、次の列車範囲をコントロールに設定
	// --------------------------------
	if ( iRv >= 0 )
	{
		if ( iRessyaIndex + iRessyaCount <  pCentDedRessyaContGet->size() )
		{
			iRessyaIndex += iRessyaCount ;
			SetDlgItemText( IDC_EDIT_RESSYAINDEX , stringOf( iRessyaIndex + 1 ).c_str() ) ;
			SetDlgItemText( IDC_EDIT_RESSYACOUNT , stringOf( iRessyaCount ).c_str() ) ;
		}
	}
	// --------------------------------

	if ( iRv < 0 )
	{
		if ( !strError.IsEmpty() )
		{
			MessageBox( strError , NULL , MB_ICONEXCLAMATION ) ;
		}
	}
	//CDialog::OnOK();
}

} //namespace ViewJikokuhyou
