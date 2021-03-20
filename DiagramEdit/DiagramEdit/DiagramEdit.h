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
// DiagramEdit.h : DIAGRAMEDIT アプリケーションのメイン ヘッダー ファイル
//
/** @file */

#if !defined(AFX_DIAGRAMEDIT_H__BB10ABB1_4C17_48C5_8B0E_831BB25A10EC__INCLUDED_)
#define AFX_DIAGRAMEDIT_H__BB10ABB1_4C17_48C5_8B0E_831BB25A10EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

#include "CMainFrame.h"
#include "CDiagramEditDoc.h"
#include "Print\CdPrintPageProp.h"
#include "ConvJikokuhyouCsv\CconvJikokuhyouCsv.h"
#include "ConvJikokuhyouCsv\CconvJikokuhyouCsv.h"
#include "ViewEki\CEkiDoc.h"
#include "ViewEki\CEkiView.h"
#include "ViewRessyasyubetsu\CRessyasyubetsuDoc.h"
#include "ViewJikokuhyou\CJikokuhyouDoc.h"
#include "ViewJikokuhyou\CJikokuhyouView.h"
#include "ViewJikokuhyou\WndJikokuhyou\CWndJikokuhyou.h"
#include "ViewDiagram\CDedDiagramDoc.h"
#include "ViewDiagram\CWndDiagram.h"
#include "ViewComment\CDedCommentDoc.h"

using namespace Print;
using namespace ViewEki;
using namespace ViewRessyasyubetsu;
using namespace ViewJikokuhyou;
using namespace ViewDiagram;
using namespace ViewComment;
using namespace ConvJikokuhyouCsv;
/////////////////////////////////////////////////////////////////////////////
// CDiagramEditApp:
// このクラスの動作の定義に関しては DiagramEdit.cpp ファイルを参照してください。
//
/**
 @brief DiagramEdit のアプリケーションクラスです。
	CWinApp の派生クラスとなります。

	ルートDoc/View・各種サブDoc/View へのアクセスの手段を提供します。
 */
class CDiagramEditApp : public CHidemdiApp
{
	// ********************************
	///@name	集約
	// ********************************
	///@{
	/**
		『駅』サブ DocView へのポインタです。
		InitInstance() で生成したオブジェクトを指します。
	 */
	CHidemdiSubDoctmpl* m_pdoctmplEki ;
	/**
		『列車種別』サブ DocView へのポインタです。
		InitInstance() で生成したオブジェクトを指します。
	 */
	CHidemdiSubDoctmpl* m_pdoctmplResssyasyubetsu ;

	/**
		『時刻表』サブ DocView へのポインタです。
		InitInstance() で生成したオブジェクトを指します
	 */
	CHidemdiSubDoctmpl* m_pdoctmplJikokuhyou ;

	/**
		『ダイヤグラム』サブ DocView へのポインタです。
		InitInstance() で生成したオブジェクトを指します
	 */
	CHidemdiSubDoctmpl* m_pdoctmplDiagram ;

	/**
		『コメント』サブ DocView へのポインタです。
		InitInstance() で生成したオブジェクトを指します
	 */
	CHidemdiSubDoctmpl* m_pdoctmplComment ;

	///@}
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		  単純データクラスです。
		  印刷ページに関するプロパティを保持します。
	 */
	CdPrintPageProp	m_CdPrintPageProp ;
	
	///@}
private:
	// ================================
	//	下請関数
	// ================================
	/**
		バージョンリソースから、バージョン番号を取得します。
	@param pstrFileVersion [out]
		ルートブロックのバージョン番号を取得します。
		(例："0.05.03" ) 
	@param pstrLegalCopyright [out]
		lang-codepage="041104b0"の "LegalCopyright" を取得します。
	*/
	static void readVersionResource( 
		string* pstrFileVersion , 
		string* pstrLegalCopyright ) ;

 public:
	// ********************************
	///@name CDiagramEditApp-属性
	// ********************************
	///@{
	CdPrintPageProp	getCdPrintPageProp(){
		return m_CdPrintPageProp ; };
	std::string getProgramVer()const ;
	///@}

	// ********************************
	///@name CDiagramEditApp-操作
	// ********************************
	///@{
	/**
	 @return
		メインフレームウインドウオブジェクトへの
		ポインタを返します。
	 */
	CMainFrame*	getCMainFrame() ;

	/**
	 @return
		『路線』ビュー（左側ペイン）を返します。
	 */
	CDlgRosenView*	getCDlgRosenView() ;
	
	/**
		『駅』ドキュメントとビューを開き、編集可能にします。
	@param ppEkiView [out]
		この関数はこのポインタに、CEkiView のアドレスを書き込みます。
		ビューが複数開いている場合は、最初のビューを書き込みます。
		エラーの場合は、NULLを書き込みます。
		不要の場合は、NULLを指定してください。
	@return
		成功したら、『サブドキュメント』オブジェクトを返します。
		エラーならNULLです。
	 */
	CEkiDoc* openCEkiDoc( CEkiView** ppEkiView = NULL ) ;
	
	/**
		『列車種別』ドキュメントとビューを開き、編集可能にします。
	 @return
		成功したら、『サブドキュメント』オブジェクトを返します。
		エラーならNULLです。
	 */
	CRessyasyubetsuDoc* openCRessyasyubetsuDoc() ;

	/**
		『時刻表』ドキュメントとビューを開き、編集可能にします。
	 @param pCentDedDia [in]
		編集対象となるダイヤオブジェクトを
		指定してください。
	 @param eRessyahoukou [in]
		列車方向を指定してください。
		- 下り =Ressyahoukou_Kudari
		- 上り =Ressyahoukou_Nobori 
	@param ppJikokuhyouView [out]
		この関数はこのポインタに、CJikokuhyouView のアドレスを書き込みます。
		ビューが複数開いている場合は、最初のビューを書き込みます。
		エラーの場合は、NULLを書き込みます。
		不要の場合は、NULLを指定してください。
	 @return
		成功したら、『サブドキュメント』オブジェクトを返します。
		エラーなら負の数です。
	 */
	CJikokuhyouDoc* openCJikokuhyouDoc( 
		const CentDedDia* pCentDedDia , 
		ERessyahoukou eRessyahoukou ,
		CJikokuhyouView** ppJikokuhyouView ) ;

	/**
		『ダイヤグラム』ドキュメントとビューを開き、編集可能にします。
	 @param pCentDedDia [in]
		編集対象となるダイヤオブジェクトを
		指定してください。
	 @return
		成功したら、『サブドキュメント』オブジェクトを返します。
		エラーなら負の数です。
	 */
	CDedDiagramDoc* openCDedDiagramDoc( const CentDedDia* pCentDedDia ) ;

	/**
		『コメント』ドキュメントとビューを開き、編集可能にします。
	 @return
		成功したら、『サブドキュメント』オブジェクトを返します。
		エラーなら負の数です。
	 */
	CDedCommentDoc* openCDedCommentDoc() ;


	/**
	 @return
		OuDia ファイル・WinDIAファイル・"*.*" のフィルタ文字列を
		返します。
		この文字列は、 CFileDialog の引数に渡すことができます。
	 */
	virtual CString getCFileDialogFilter() ;

	/**
	 @return
		OuDia ファイル・"*.*" のフィルタ文字列を
		返します。
		この文字列は、 CFileDialog の引数に渡すことができます。
	 */
	virtual CString getCFileDialogOudFilter() ;

	/**
	 @return
		CSVファイル・"*.*" のフィルタ文字列を
		返します。
		この文字列は、 CFileDialog の引数に渡すことができます。
	 */
	virtual CString getCFileDialogFilterCsv() ;

	/**
	@return
		CconvJikokuhyouCsv を生成します。
	*/
	virtual CconvJikokuhyouCsv createCconvJikokuhyouCsv() ;

	///@}
	// ********************************
	///@name CDiagramEditApp-ファイル名
	// ********************************
	///@{
	/**
		ファイルタイトル+拡張子 形式のファイル名から、
		プログラムディレクトリ(.exeファイルと同じ場所のディレクトリ)を
		付与したフルパス名を作成します。
	@param strFilename [in]
		ファイル名を指定してください。(例:"sub.dll" )
	@return
		フルパス名を返します。(例:"c:\program files\oudia\sub.dll" )

		strFilename に空文字列を指定すると、
		戻り値はプログラムディレクトリになります
		(例:"c:\program files\oudia\" )。
	*/
	CString makeProgramDirFilename( const CString& strFilename ) ;

	/**
		ファイルタイトル+拡張子 形式のファイル名から、
		LOCAL_APPDATA ディレクトリ内の \oudia ディレクトリを
		付与したフルパス名を作成します。
	@param strFilename [in]
		ファイル名を指定してください。(例:"profile.ini" )
	@return
		フルパス名を返します。
		(例:"c:\documents and settings\username\local settings\application data\oudia\profile.ini" )

		strFilename に空文字列を指定すると、
		戻り値はプログラムディレクトリになります
		(例:"c:\documents and settings\username\local settings\application data\oudia\" )。
	*/
	CString makeLocalAppdataFilename( const CString& strFilename ) ;

	/**
		トピック名から、HtmlHelp() APIの第3引数に指定するための、
		HTML Help URL を作成します。
	@param strTopic [in]
		トピック名を指定してください。 (例:"/Topic.htm" ) ;
	@return
		Html Help URLを返します。
		(例:"c:\program files\oudia\oudia.chm::/Topic.htm" )。

		strTopicに空文字列を指定すると、.chm ファイルのフルパス名を返します。
		(例:"c:\program files\oudia\oudia.chm" )。
	*/
	CString makeHtmlHelpUrl( const CString& strTopic ) ;

	///@}
	// ********************************
	///@name CDiagramEditApp-.ini ファイル
	// ********************************
	///@{
	/**
	『ダイヤグラム』ウインドウ CWndDiagram の、
	表示設定を PrivateProfile (.ini ファイル) に保存します。

	保存対象は、セクション[AppProp]の、以下のエントリです。

	- "DiagramPosDgr" @n
	 TargetPosの左上に描画される『ダイヤグラム座標』。 
	 カンマ区切りで、X,Y座標を記述します。

	- "DcdPerDgrX" @n
	 『ダイヤグラム座標』の1に対応する、『DcDraw座標(論理座標)』の数

	- "DcdPerDgrY" @n
	 『ダイヤグラム座標』の1に対応する、『DcDraw座標(論理座標)』の数

	- "DiagramVlineMode" @n
		縦罫の間隔のモード。CDcdDiagram::m_arVline[8] の添え字です。

	- "DiagramDisplayRessyabangou" @n 
		 ダイヤ画面列車番号表示
		- 1 ;	//	ダイヤ画面に列車番号を表示する
		- 0 ;	//	ダイヤ画面に列車番号を表示しない
	
	- "DiagramDisplayRessyamei" @n
		 ダイヤ画面列車名表示
		- 1 ;	//	ダイヤ画面に列車名を表示する
		- 0 ;	//	ダイヤ画面に列車名を表示しない

	- "DiagramDisplayRessyasen" @n
		列車線を表示するか否かを指定します。カンマ区切りで、下り,上りを記述します。
		- 1 ;	//	列車線を表示する
		- 0 ;	//	列車線を表示しない

	- "DiagramHideIppanekiEkimei" @n
		一般駅の駅名表示を隠す指定です。
		- 1 ;	//	すべての駅名を表示します。(default)
		- 0 ;	//	一般駅の駅名を表示しません。

	- "DiagramStopMarkDraw" @n
		停車駅表示の有無を指定します。
		- 0: 停車駅明示=OFF。停車駅明示を行いません。
		- 1: 停車駅明示=ON。短時間停車の駅に、停車駅を示す記号(○)を描画します。

	- "DiagramKeepZoneDgrOnSize" @n 
		ウインドウサイズ変更時の動作。
		- false:表示範囲を変更(OuDia Ver.1.00.04 より後)
		- true: 表示範囲を変更しない(OuDia Ver.1.00.04 互換)

	@param pCWndDiagram [in]
		『ダイヤグラム』ウインドウオブジェクトを指定してください。
		この関数は、このオブジェクトの属性を、ファイルに保存します。
	 @return	
		成功したら 0 以上、エラーなら負の数です。
	*/
	virtual int writeCWndDiagramViewProp( const CWndDiagram* pCWndDiagram ) ;

	/**
	『ダイヤグラム』ウインドウ CWndDiagram の、
	表示設定を PrivateProfile (.ini ファイル) から
	読み込みます。
	
	 @param pCWndDiagram [in]
		『ダイヤグラム』ウインドウオブジェクトを指定してください。
		この関数は、このオブジェクトの属性を、ファイルに保存します。
	 @return	
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	DiagramZoneDgr が指定されていません。
		-	-2 ;	//	DiagramVlineMode が指定されていません。
		-	-3 ;	//	DisplayRessyabangou が指定されていません。
		-	-4 ;	//	DisplayRessyamei が指定されていません。
		-	-5 ;	//	DisplayRessyasen が指定されていません。
		-	-6 ;	//	HideIppanekiEkimei が指定されていません。
	*/
	virtual int readCWndDiagramViewProp( CWndDiagram* pCWndDiagram ) ;


	/**
	『ダイヤグラム』ウインドウ CWndJikokuhyou の、
	表示設定を PrivateProfile (.ini ファイル) に保存します。

	保存対象は、セクション[AppProp]の、以下のエントリです。

	- "Jikokuhyou_DisplayTsuukaEkiJikoku" @n
		通過駅の駅時刻表示の有無の指定
		- 1 ; 通過駅の駅時刻を表示します。(default)
		- 0 ; 通過駅の駅時刻を表示せずに、通過マーク "ﾚ" を表示します。
	- "Jikokuhyou_DisplayAllEkiJikoku" @n
		全駅の駅時刻を表示するか否かの指定

		- 1 ; 駅の駅時刻形式(CentDedEki::m_eEkijikokukeisiki )とは無関係に、
			時刻表ビューに全駅の着発時刻を表示します。
		- 0 ; 全駅表示を行いません。
	- "Jikokuhyou_EkijikokuSort" @n
		時刻表ビューの駅時刻での「並べ替え」のモード。 
		既定は、駅扱でのソートです。
		- 0 : 駅扱でのソート
		- 1 : 乗継ソート
	- "Jikokuhyou_ModifyEkiJikoku" @n
		繰上げ・繰り下げの有効・無効を示します。
		- 1: 有効
		- 0: 無効
	
	@param pCWndJikokuhyou [in]
		『時刻表』ウインドウオブジェクトを指定してください。
		この関数は、このオブジェクトの属性を、ファイルに保存します。
	 @return	
		成功したら 0 以上、エラーなら負の数です。
	*/
	virtual int writeCWndJikokuhyouViewProp( 
		const CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	『ダイヤグラム』ウインドウ CWndJikokuhyou の、
	表示設定を PrivateProfile (.ini ファイル) から
	読み込みます。
	
	 @param pCWndJikokuhyou [in]
		『ダイヤグラム』ウインドウオブジェクトを指定してください。
		この関数は、このオブジェクトの属性を、ファイルに保存します。
	 @return	
		成功したら 0 以上、エラーなら負の数です。
	*/
	virtual int readCWndJikokuhyouViewProp( 
		CWndJikokuhyou* pCWndJikokuhyou ) ;

	/**
	『駅』ウインドウ CWndDcdGridEki の、
	表示設定を PrivateProfile (.ini ファイル) に保存します。

	保存対象は、セクション[AppProp]の、以下のエントリです。

	- "EkiProp_AdjustByEkijikokukeisiki" @n
		- 1; 駅のプロパティが変更されたとき、
			すべてのダイヤ・列車の駅時刻を、
			駅時刻形式に正規化します。
		- 0; 駅のプロパティが変更されたときも、
			列車の駅時刻を変更しません。

	@param pCWndDcdGridEki [in]
		『駅』ウインドウオブジェクトを指定してください。
		この関数は、このオブジェクトの属性を、ファイルに保存します。
	 @return	
		成功したら 0 以上、エラーなら負の数です。
	*/
	virtual int writeCWndDcdGridEkiProp( 
		const CWndDcdGridEki* pCWndDcdGridEki ) ;

	/**
		『駅』ウインドウ CWndDcdGridEki の、
		表示設定を PrivateProfile (.ini ファイル) から
		読み込みます。
	
	 @param pCWndDcdGridEki [in]
		『駅』ウインドウオブジェクトを指定してください。
		この関数は、このオブジェクトの属性を、ファイルに保存します。
	 @return	
		成功したら 0 以上、エラーなら負の数です。
	*/
	virtual int readCWndDcdGridEkiProp( 
		CWndDcdGridEki* pCWndDcdGridEki ) ;



	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

public:
	CDiagramEditApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CDiagramEditApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	//{{AFX_MSG(CDiagramEditApp)
	afx_msg void OnAppAbout();
	afx_msg void OnVIEWEki();
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnFILEPrintPageProp();
	afx_msg void OnFileOpen();
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};


/////////////////////////////////////////////////////////////////////////////

/**
 @return 
	アプリケーションオブジェクトを返します。
 */
inline CDiagramEditApp*	getCDiagramEditApp(){
	return (CDiagramEditApp*)AfxGetApp() ; 
};

/**
 @return 
	『ルートドキュメント』オブジェクトを返します。
 */
inline CDiagramEditDoc*	getCDiagramEditDoc(){
	return (CDiagramEditDoc*)getCDiagramEditApp()->pRootDoc() ; 
};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。



#endif // !defined(AFX_DIAGRAMEDIT_H__BB10ABB1_4C17_48C5_8B0E_831BB25A10EC__INCLUDED_)
