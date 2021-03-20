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
// CDiagramEditDoc.h : CDiagramEditDoc クラスの宣言およびインターフェイスの定義をします。
//	$Id: CDiagramEditDoc.h 295 2016-06-11 05:14:13Z okm $
/////////////////////////////////////////////////////////////////////////////
/** @file */
#if !defined(AFX_CDIAGRAMEDITDOC_H__A4879B96_62E6_4298_B7DB_8F991F72EC7F__INCLUDED_)
#define AFX_CDIAGRAMEDITDOC_H__A4879B96_62E6_4298_B7DB_8F991F72EC7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NsMu/CMup_deque.h"
#include "NsOu/Ou.h"
#include "Hidemdi\Hidemdi.h"
#include "DedRosenFileData\CDedRosenFileData.h"
#include "DedRosenFileData\EditCmd\CRfEditCmd.h"

using namespace OuLib::NsOu;
using namespace DedRosenFileData;
using namespace DedRosenFileData::EditCmd;

/** oud ファイル内の FiltTypeAppComment 項目名 */
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;

/**
@brief
【概要】  DiagramEdit のルートドキュメントクラスです。
MFC の CDocument を継承します。

このクラスは、 .oud ファイルの内容を保持する
CDedRosenFileData の
インスタンスを集約しています( m_CDedRosenFileData )。

m_CDedRosenFileData が保持している路線ファイルのデータを参照するには、
CDiagramEditDoc::getCDedRosenFileData() で const CDedRosenFileData* を取得し、
 そのポインタで	CDedRosenFileData のメソッドにアクセスしてください。

CDiagramEditDoc::getCDedRosenFileData() で取得できるポインタは const* です。
このため、 m_CDedRosenFileData 、さらにはそれらに集約される各種オブジェクトの
状態を変えることはできません。

m_CDedRosenFileData の内容を変更するためには、
変更内容に応じた CRfEditCmd 派生クラスオブジェクトを生成し、
そのインスタンスへの Ou(スマートポインタ) を引数にして executeEditCmd() を
呼び出してください。
*/ 
class CDiagramEditDoc : public CHidemdiRootDoc
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	typedef CHidemdiRootDoc	super ;
private:
	// ********************************
	///@name 包含
	// ********************************
	///@{
	/**
	【概要】  DiagramEdit のアプリケーションが読み書きする
	『路線ファイル』に含まれるデータを保持するクラスです。
	 */
	CDedRosenFileData	m_CDedRosenFileData ;
	///@}
private:
	// --------------------------------
	///@name Undo,Redo関係内部データ 
	// --------------------------------
	///@{
	/**
	 	Undo のための情報を保持するキューです。
	 
	 	executeEditCmd() は、 CRfEditCmd オブジェクトを
	 	このキューの末尾に追加します。
	 
	 	Undo を実行する場合は、
	 
	 	１．  m_contUndo の末尾の CRfEditCmd オブジェクト
	 	の createUndoCmd() で生成したコマンドを execute() する。
	 
	 	２．  m_contUndo の末尾の CHint_CDedRosenFileData オブジェクトを
	 	捨てる。
	 */
	CMup_deque< Ou< CRfEditCmd > > m_contUndo ;
	
	/**
		Redo のための情報を保持するキューです。
	
		undo() は、 CRfEditCmd オブジェクトを
		このキューの末尾に追加します。

		executeEditCmd() は、このコンテナを空にします。
	
		Redo を実行する場合は、
	
		１．  m_contRedo の末尾の CRfEditCmd オブジェクト
		のコマンドを execute() する。
	
		２．  そのコマンドを m_contRedo の末尾からは削除し、
		m_contUndo の末尾に追加する。
	
		３．  m_contRedo の末尾の CHint_CDedRosenFileData オブジェクトを
		捨てる。
	*/
	CMup_deque< Ou< CRfEditCmd > > m_contRedo ;

	/**
　　現在のドキュメントの、
	『変更フラグ』OFFの状態から実行された変更/Undoの回数 
	を示します。 

	◎基本操作 

　	   ModifyCountFromSave は、ドキュメントが新規作成されたあと、または保存されたときに 0 にリセットされます。 
　	  その後 
			変更動作/REDOが行われたときに1加算 
			UNDOが行われたときに1減算 
	が行われます。 
　	  『変更フラグ』はこの値に同期させるものとします。アプリケーションは、以下の規則に従って、『変更フラグ』を制御します。 
			ModifyCountFromSave == 0 のとき・・・『変更フラグ』はOFF 
			ModifyCountFromSave != 0 のとき・・・『変更フラグ』はON 

	◎例外操作−１ 

	　ModifyCountFromSave が INT_MAX に達したら、その後は変更・UNDO・REDOが行われても値は変わりません。この状態は、「いかなるUNDO・REDOを行っても、ドキュメントの状態を『変更フラグOFF』に戻すことはできない」ことを示します。 

	◎例外操作−2 

　	  ModifyCountFromSave が負のときに新しい変更が行われた場合(UNDO,REDO以外の編集操作が行われた場合)は、ModifyCountFromSaveは INT_MAX とします。 

　	  この例外操作が適用される場合の一例は、 

　	  「ドキュメントをファイルに保存したあと、UNDOを行い、その後編集操作を行った」 

	というものです。以下の例では、6.の操作がこの場合にあたります。 

	@code
	// -------------------------------- 
	1.初期状態 
		ドキュメント　"" 
		UNDOスタック 
		ModifyCountFromSave=0 

	2.1回目の編集  　"ABC" 
		ドキュメント  "ABC" に更新 
		UNDOスタック    "" 
		ModifyCountFromSave=1 

	3.2回目の編集　"ABCDEF" 
		ドキュメント  "ABCDEF"  に更新 
		UNDOスタック    "","ABC" 
		ModifyCountFromSave=2 

	4.ドキュメントをファイルに保存　 
		ドキュメント  "ABCDEF"  に更新 
		UNDOスタック    "","ABC" 
		ModifyCountFromSave=0 

	5.Undo 
		ドキュメント  "ABC" 
		UNDOスタック    "" 
		REDOスタック    "ABCDEF" 
		ModifyCountFromSave=-1 

	6.編集 "ABCGHI" 
		ドキュメント  "ABCGHI" 
		UNDOスタック    "" "ABC" 
		REDOスタック     
		ModifyCountFromSave=INT_MAX 
	// -------------------------------- 
	@endcode

　	  6.の編集に際して ModifyCountFromSave を原則どおり +1 すると、 ModifyCountFromSave は 0となり、ドキュメントは『変更フラグOFF』になってしまいます。これは正しくありません。 

	*/
	int m_iModifyCountFromDoc ;	
	///@}

protected:
	// --------------------------------
	///@name	下請関数-ファイルを開く・保存
	// --------------------------------
	///@{
	/**
	 	OnOpenDocument() の下請関数です。
	 	WinDia 形式のファイルを読み込んで、m_CDedRosenFileData に
	 	反映します。
	  @param lpszPathName [in]
	  	読み込むファイル名を指定して下さい。
	 	このファイル名は、 WinDia 形式でなくてはなりません。
	  @return
	 	成功したら TRUE ・ エラーなら FALSE です。
	 
	 	この関数は、エラーの場合はメッセージボックスを表示します。
	 */
	virtual BOOL OnOpenDocument_WinDia( LPCTSTR lpszPathName ) ;
	
	/**
	 	OnSaveDocument() の下請関数です。
	 	ドキュメントの内容を、WinDia 形式のファイルに保存します。
	  @param lpszPathName [in]
	  	保存するファイル名を指定して下さい。
	  @return
	 	成功したら TRUE ・ エラーなら FALSE です。
	 
	 	この関数は、エラーの場合はメッセージボックスを表示します。
	 */
	virtual BOOL OnSaveDocument_WinDia( LPCTSTR lpszPathName ) ;
	
	/**
		
	@param lpszDllFilename [in]
		ファイル変換DLLのファイル名を指定してください。
	@param pbinFileContent [in,out]
		変換を行うファイルコンテンツを指定してください。
		この関数はこのバイナリデータを変換し、変換結果を上書きします。
	@param pstrError [out]
		この関数は、変換でエラーが発生したら、エラーメッセージを
		ここに書き込みます。
		このメッセージは、すぐにメッセージボックスで表示可能な形式です。
	@return 
		-	0 : 処理に成功しました。
		-	-1 : このDLLがサポートするファイル形式ではありませんでした。
		-	-101: DLLがみつかりませんでした。
		-	-102: ファイルの変換に失敗しました。
	@attention
　	  戻り値が -1 の場合は、 *pstrError にはエラーメッセージが格納されません。
	*/
	int OnOpenDocument_ConvFile( 
		LPCTSTR lpszDllFilename , 
		std::vector< char >* pbinFileContent , 
		CString* pstrError ) ;
	///@}


public:
	// ********************************
	//	CHidemdiRootDoc
	// ********************************
	/**
	  	すべてのサブDocviewと、ルートDocviewに対して、
	 	UpdateAllViews()を実行します
	   @param pSender
	  	ドキュメントを変更したビューへのポインタ。
	  すべてのビューを更新するときには NULL を指定します。
	   @param lHint
	  	変更に関する情報を指定します。
	  	ただし、((LPARAM)-1)が指定された場合は、すべてのDocviewに対して、
	  	内容をルートドキュメントに反映し、必要ならばルートDocに対して
	  	SetModifiedFlag()を実行させます。
	   @param pHint
	  	変更に関する情報が格納されているオブジェクトへのポインタ。
	 
	  [オーバライド]
	 	UpdateAllSubDocviews() では、CJikokuhyouDoc オブジェクトに対応する
	 	CentDedDia オブジェクトがあるかどうかを検証します。
	 	対応する CentDedDia が削除されている場合は、
	 	CJikokuhyouDoc オブジェクトを削除します。
	 */
	virtual void UpdateAllSubDocviews( CView* pSender , LPARAM lHint = 0 , CObject* pHint = NULL );

// ********************************
//	CDiagramEditDoc
// ********************************
public:
	// ********************************
	///@name CDiagramEditDoc-包含
	// ********************************
	///@{
	const CDedRosenFileData*	getCDedRosenFileData()const ;
	///@}
	// ********************************
	///@name クリップボード操作
	// ********************************
	///@{
	/**
	@return
		CentDedEki オブジェクトの内容を保持する
		クリップボードフォーマット値を返します。
	*/
	static UINT getCF_CentDedEki() ;


	/**
	 指定された CentDedEki オブジェクトの内容を、
	クリップボードに保存します。
	@param pMuCentDedEki [in]
		駅オブジェクトを指定してください。
	@return 
		成功したら 0 以上、エラーなら負の数です。	
		-	-1 ;	//	CentDedEki の内容が不正です。
		-	-11 ;	//	クリップボードへのデータ設定が失敗
	*/
	static int CentDedEki_To_Cliboard( const Mu<CentDedEki>* pMuCentDedEki ) ;
	/**
	　クリップボードに、 CentDedEki オブジェクトの
	内容が格納されていたら、それを取得します。
	@param pCentDedEki [out]
		この関数は成功したら、この駅オブジェクトに
		クリップボードの内容を追加します。
	@return 
		成功したら 0 以上、エラーなら負の数です。	
			-	-1 ;	//	クリップボードには有効なデータはありません。
			-	-2 ;	//	クリップボードからの読み込みに失敗しました。	
			-	-3 ;	//	クリップボードの内容が不正です。
			-	-4 ;	//	CentDedEki の内容が不正です。
	*/
	static int CentDedEki_From_Cliboard( 
		Mui<CentDedEki>* pCentDedEki ) ;



	/**
	 @return 
		クリップボードに、 CentDedEki オブジェクトの
		内容が格納されていたら、真を返します。
	 */
	static bool CentDedEki_IsClipboardFormatAvailable() ;

	/**
	@return
		CentDedRessyasyubetsu オブジェクトの内容を保持する
		クリップボードフォーマット値を返します。
	 */
	static UINT getCF_CentDedRessyasyubetsu() ;

	/**
	 指定された CentDedRessyasyubetsu オブジェクトの内容を、
	クリップボードに保存します。
	@param pMuCentDedRessyasyubetsu [in]
		列車種別を保持したコンテナを指定してください。
	@return 
		成功したら 0 以上、エラーなら負の数です。	
			-	-1 ;	//	CentDedRessyasyubetsu の内容が不正です。
			-	-11 ;	//	クリップボードへのデータ設定が失敗
	 */
	static int CentDedRessyasyubetsu_To_Cliboard( 
		const Mu<CentDedRessyasyubetsu>* pMuCentDedRessyasyubetsu ) ;

	/**
	 クリップボードに、 CentDedRessyasyubetsu オブジェクトの
	内容が格納されていたら、それを取得します。

	@param pMuCentDedRessyasyubetsu [out]
		この関数は成功したら、このコンテナに、
		列車種別を追加します。

	@return 
		成功したら 0 以上、エラーなら負の数です。	
			-	-1 ;	//	クリップボードには有効なデータはありません。
			-	-2 ;	//	クリップボードからの読み込みに失敗しました。	
			-	-3 ;	//	クリップボードの内容が不正です。
			-	-4 ;	//	CentDedRessyasyubetsu の内容が不正です。
	 */
	static int CentDedRessyasyubetsu_From_Cliboard( 
		Mui<CentDedRessyasyubetsu>* pMuCentDedRessyasyubetsu ) ;



	/**
	  @return 
	 	クリップボードに、 CentDedRessyasyubetsu オブジェクトの
	 	内容が格納されていたら、真を返します。
	 */
	static bool CentDedRessyasyubetsu_IsClipboardFormatAvailable() ;

	/**
	  @return
	 	CentDedRessyaCont オブジェクトの内容を保持する
	 	クリップボードフォーマット値を返します。
	 */
	static UINT getCF_CentDedRessyaCont() ;

	/**
	指定された CentDedRessyaCont オブジェクトの内容を、
	クリップボードに保存します。
	 @param aCentDedRessyaCont [in]
		駅オブジェクトを指定してください。
	 @return 
		成功したら 0 以上、エラーなら負の数です。	
			-	-1 ;	//	aCentDedRessyaCont の内容が不正です。
			-	-11 ;	//	クリップボードへのデータ設定が失敗
	 */
	static int CentDedRessyaCont_To_Cliboard( 
		const CentDedRessyaCont& aCentDedRessyaCont ) ;

	/**
	クリップボードに、 CentDedRessyaCont オブジェクトの
	内容が格納されていたら、それを取得し、
	pCentDedRessyaCont に追加します。
	 @param pCentDedRessyaCont [in,out]
		この関数は成功したら、この CentDedRessyaCont コンテナの末尾に
		クリップボードに格納されている列車を追加します。
		このコンテナにそれまで格納されていた列車は、維持します。
		pCentDedRessyaCont に対してはあらかじめ、
		『列車方向』 m_eRessyaHoukou と
		『駅時刻数』 m_iEkiCount が
		正しく設定されていなくてはなりません。
	 @return 
		成功したら 0 以上、エラーなら負の数です。	
			-	-1 ;	//	クリップボードには有効なデータはありません。
			-	-2 ;	//	クリップボードからの読み込みに失敗しました。	
			-	-3 ;	//	クリップボードの内容が不正です。
			-	-4 ;	//	CentDedRessyaCont の内容が不正です。
	 */
	static int CentDedRessyaCont_From_Cliboard( 
		CentDedRessyaCont* pCentDedRessyaCont ) ;

	/**
	  @return 
	 	クリップボードに、 CentDedRessyaCont オブジェクトの
	 	内容が格納されていたら、真を返します。
	 */
	static bool CentDedRessyaCont_IsClipboardFormatAvailable() ;

	///@}
public:
	// ********************************
	///@name CDiagramEditDoc-操作
	// ********************************
	///@{
	/**
	 	ドキュメントの更新を行います。
	 
	 	この関数は、詳細には以下のことを行います。
	 	
	 	- １．  コマンドオブジェクト pCmd の指定に従って、ドキュメント
	 	m_CDedRosenFileData を更新します。
	 	- ２．　更新フラグの設定 SetModifiedFlag( TRUE ) を行います。
	 	- ３．  UpdateAllSubDocviews() で、すべての View に更新を行わせます。
	 	このとき、  pHint 引数に pCmd を渡します。各 View は、pCmd の内容を
	 	もとに、画面更新の処理を行います。
	 	- ４．  pCmd は、 m_contUndo に保存します。この値は、undo() の際に
	 	使います。
	 */
	virtual int executeEditCmd( Ou< CRfEditCmd > pCmd ) ;
	
	/**
	 @return
		ルート Document に対する
		Undo が可能なら真です。
	*/
	virtual bool canUndo() ; 

	/**
	ルート Document に対する
	Undo を実行し、それをすべてのビューに伝達します。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	undo 情報がありません。
		-	-2 ;	//	undo の実行に失敗
	*/
	virtual int undo() ; 

	/**
	 @return
		ルート Document に対する
		Redo が可能なら真です。
	*/
	virtual bool canRedo() ; 

	/**
	ルート Document に対する
	Redo を実行し、それをすべてのビューに伝達します。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	redo 情報がありません。
		-	-2 ;	//	redo の実行に失敗
	 */
	virtual int redo() ; 

	///@}
	
// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
protected: // シリアライズ機能のみから作成します。
	CDiagramEditDoc();
	DECLARE_DYNCREATE(CDiagramEditDoc)

// アトリビュート
public:

// オペレーション
public:

//オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CDiagramEditDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU = TRUE);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CDiagramEditDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	DECLARE_MESSAGE_MAP()

	//{{AFX_MSG(CDiagramEditDoc)
	afx_msg void OnFileSaveAs();
	//	[ファイル]
	afx_msg void OnUpdateFileSaveAs(CCmdUI *pCmdUI);

	//	[編集]
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditRedo(CCmdUI *pCmdUI);
	afx_msg void OnEditRedo();
	//}}AFX_MSG
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CDIAGRAMEDITDOC_H__A4879B96_62E6_4298_B7DB_8F991F72EC7F__INCLUDED_)
