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
//	CWndDcdGridEki.h
//	$Id: CWndDcdGridEki.h 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWndDcdGridEki_h
#define  CWndDcdGridEki_h

#include "DcDraw\CDcdTextbox.h"
#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"
#include "OuDlg\CKeyinputSenderToModalDlg.h"
#include "str\stringSplit.h"
#include "LogMsg\LogMsg.h"

#include "..\entDed\CentDedEki.h"
#include "..\DedRosenFileData\EditCmd\CRfEditCmd_Eki.h"
#include "EkiColSpec\CdEkiYColSpecCont.h"
#include "EkiColSpec\CdEkiXColSpecCont.h"

namespace ViewEki{

	using namespace OuMfc::OuDlg;
	using namespace DcDrawLib::DcDraw;
	using namespace DcDrawLib::DcdGrid::WndDcdGrid3;
	using namespace entDed ;
	using namespace EkiColSpec ;

// ****************************************************************
//	CWndDcdGridEki
// ****************************************************************
/**
	@brief
	【概要】 CEkiView で用いる、グリッドウインドウです。
 */
class CWndDcdGridEki : public CWndDcdGrid
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	typedef CWndDcdGrid super ;

	/** 
		createCmd() メソッドで生成するコマンドオブジェクトの種類を指定します。
	*/
	enum ECreateCmd
	{
		/**
		　ビューのフォーカス位置に新規アイテムを挿入するためのコマンドを生成します。

		　ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 
		 
		 - m_iIndexDst = フォーカスセルのアイテムIndex、m_iIndexSize = 0
		 - m_CentDedEkiCont = 新規作成時のアイテムの既定値
		 - CaMuiSelect = 当該アイテムを選択。

		 　ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合:

		 - m_iIndexDst = 末尾アイテムIndex+1、m_iIndexSize = 0
		 - m_CentDedEkiCont = 新規作成時のアイテムの既定値
		 - CaMuiSelect = 当該アイテムを選択。

		 　ビュー上で複数選択ON:

		 - NULLを返します([14/05/18]旧:複数選択OFFの場合と同じ動作)

		　以下のメニューコマンドで使用します。

		 - 貼り付け・アイテムのプロパティ(※)・アイテムを挿入 @n
		    ※=フォーカス位置が新規アイテムにある場合のみ
		*/
		ECreateCmd_NewItem , 

		/**
		　フォーカスセル上のアイテム1つを対象としたコマンドを生成します。

		　ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 

		 - m_iIndexDst = フォーカスセルのアイテムIndex、m_iIndexSize = 1
		 - m_CentDedRessyaCont = フォーカスセル上のアイテム1個のコピー
		 - m_CaMuiSelect = フォーカスセル上のアイテムを選択。

		　ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合: 

		 - NULLを返します。

		　ビュー上で複数選択ON

		 - NULLを返します([14/05/18]旧:複数選択OFFの場合と同じ動作)

		　以下のメニューコマンドで使用します。


		*/
		ECreateCmd_Focus , 

		/**
		　既存の単数または複数選択されているアイテムを対象とした
		コマンドを生成します。

		　ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 

		 - m_iIndexDst = フォーカスセルのアイテムIndex、m_iIndexSize = 1
		 - m_CentDedRessyaCont = フォーカスセルのあるアイテム1個のコピー
		 - CaMuiSelect = 当該列車を選択。

		　ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合: 

		 - NULLを返します。

		　ビュー上で複数選択ON

		 - m_iIndexDst = 選択されているアイテムの先頭index
		 - m_iIndexSize = 選択されているアイテムの末尾index-先頭index+1
		 - m_CentDedRessyaCont = 選択されているアイテムの先頭indexから
		  末尾indexまでのアイテムのコピー
		 - CaMuiSelect は、セル選択に合わせてアイテムを選択。
		
		　以下のメニューコマンドで使用します。

		 - 切り取り・コピー・消去・
		  - アイテムのプロパティ(※) @n
		    ※=フォーカス位置が既存アイテムにある場合のみ
		*/
		ECreateCmd_Select , 

		/**
		　全アイテムを対象としたコマンドを生成します。

		  ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 
		
		 - m_iIndexDst = 0、m_iIndexSize = アイテムの数
		 - m_CentDedRessyaCont = 全アイテムのコピー
		 - m_CaMuiSelect は、全アイテムを選択。

		  ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合: 
		 
		 - m_iIndexDst = 0、m_iIndexSize = アイテムの数
		 - m_CentDedRessyaCont = 全アイテムのコピー
		 - CaMuiSelect は、全アイテムを選択。

		  ビュー上で複数選択ON
		
		 - m_iIndexDst = 選択されているアイテムの先頭index
		 - m_iIndexSize = 選択されているアイテムの末尾index-先頭index+1
		 - m_CentDedRessyaCont = 選択されているアイテムの先頭indexから
			末尾indexまでのアイテムのコピー
		 - m_CaMuiSelect は、セルの選択に合わせてアイテムを選択。

		  以下のメニューコマンドで使用します。
			
		 - (対象なし)
		*/
		ECreateCmd_All ,
	};
private:
	// ********************************
	///@name	包含
	// ********************************
	///@{
	/**
	  親ウインドウへのキー入力を契機に ModalDialog を開く場合、
	 モーダルダイアログの特定のエディットコントロールに、
	 キー入力メッセージ（ WM_KEYDOWN , WM_KEYUP ）を転送します。
	
		このオブジェクトの破棄の責務は、クラスユーザー（『転送元ウインドウ』）
		にあります。
		このオブジェクトは、 this より長く生存しなくてはなりません。
		不要であれば NULL でもかまいません。
		コンストラクタで決まります。
	 */
	CKeyinputSenderToModalDlg	m_CKeyinputSenderToModalDlg ;
	///@}
	// ********************************
	///@name	属性
	// ********************************
	///@{
	/**
		trueなら、駅のプロパティが変更されたとき、
		すべてのダイヤ・列車の駅時刻を、
		駅時刻形式に正規化します。

		[駅のプロパティ]ダイアログで変更できます。

		既定は true です。
		この属性は、 .iniファイルに保存されます。
	*/
	bool m_bAdjustByEkijikokukeisiki ;
	///@}
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
		この変数が true のときは、
		ビューの更新を、次にビューがアクティブ化されるまで
		保留しています。
		
		通常は false 。
		「ビューがアクティブでないときの全更新要求（ OnUpdate_All() ）」
		から、
		「ビューがアクティブになったとき」までは true になります。
		
		ビューがアクティブなときに OnUpdate_All() が呼び出されて
		ビューの全更新が行われたら、 falseになります。
		
		ビューが非アクティブなときに OnUpdate_All() が呼び出されたら
		true になります。
		
		この値が true の場合は、OnUpdate_All() 以外の部分更新は
		全て行われません。
		
		初期値は true です。
		理由： OnUpdate_All()によるビューの更新が一度も行われていない
		場合は、ビューの部分的な更新はできないためです。
	 */
	bool m_bWaitForActivate  ;

	/**
		初期値はfalse、初回の OnUpdate() が終了したら true になります。
	*/
	bool m_bInitialUpdateComplete ;
	///@}
 public:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
	 @return
		駅名列に合わせた属性を持つ CDcdTextbox オブジェクトを
		返します。
	 */
	CDcdTextbox	getCDcdEkimei()const ;

	/**
	 @return
		駅時刻形式
		の列に合わせた属性を持つ CDcdTextbox オブジェクトを
		返します。
	 */
	CDcdTextbox	getCDcdEkijikokukeisiki()const ;

	/**
	 @return
		駅時刻形式
		の列に合わせた属性を持つ CDcdTextbox オブジェクトを
		返します。
	 */
	CDcdTextbox	getCDcdEkikibo()const ;

	/**
	 @return
		駅の列の下の罫線に使用するペンの属性を返します。\n
		駅の属性に『境界線』が設定されていない場合は、
		駅の下の罫線に、このペンを使います。
	 */
	CdPenProp getCdPenPropNormal()const{	return CdPenProp( 1 ) ; } ; 
	/**
	 @return
		駅の列の下の罫線に使用するペンの属性を返します。\n
		駅の属性に『境界線』が設定されている場合は、
		駅の下の罫線に、このペンを使います。
	 */
	CdPenProp getCdPenPropBold()const{	return CdPenProp( 2 ) ; } ; 


	/**
		全てのX列についての 『列番号-表示内容』の対応表を生成します。
		生成された CdXColSpecCont() から
		CdXColSpec オブジェクトを
		取得することにより、各列毎に必要な表示内容を取得することができます。
	@return 
		全てのX列についての 『列番号-表示内容』の対応表である
		 CdXColSpecCont オブジェクトを返します。
		
	@attention
	 	この関数を OnCreate() ・及びそれ以前に
	 	呼び出したときは、戻り値はNULL状態になります。
	 	呼び出し時期に注意してください。

	@attention
		この対応表は、 CentDedEkiCont に変更が発生
		したら無効になります。このため、CentDedEkiCont  に
		変更の可能性がある状況では、対応表を再作成する必要があります。	
	*/
	CdEkiXColSpecCont createXColSpecCont();


	/**
		全てのY列についての 『列番号-表示内容』の対応表を生成します。
		生成された CdYColSpecCont() から
		CdYColSpec オブジェクトを
		取得することにより、各列毎に必要な表示内容を取得することができます。
	@return 
		全てのY列についての 『列番号-表示内容』の対応表である
		 CdYColSpecCont オブジェクトを返します。
		
	@attention
	 	この関数を OnCreate() ・及びそれ以前に
	 	呼び出したときは、戻り値はNULL状態になります。
	 	呼び出し時期に注意してください。

	@attention
		この対応表は、 CentDedEkiCont に変更が発生
		したら無効になります。このため、CentDedEkiCont  に
		変更の可能性がある状況では、対応表を再作成する必要があります。	
	*/
	CdEkiYColSpecCont createYColSpecCont();

	/**
	@return 
		フォーカスセルの列の表示内容を返します。
	*/
	CdEkiXColSpec getXColSpecOfFocus();

	/**
	@return 
		フォーカスセルの列の表示内容を返します。
	*/
	CdEkiYColSpec getYColSpecOfFocus() ;

	
	/**
	DcdGridでの選択内容に応じた、編集コマンドオブジェクト
	(CRfEditCmd_Eki)を生成します。
	@param eCreateCmd [in]
		生成するコマンドの種類を指定してください。
	@param ppCmd [out] 
		生成したコマンドを返します。
		NULL を指定することもできます。この場合、この関数は
		コマンドを生成せずに、コマンドの生成が可能か否かだけを返します。
	@return
		ppCmdが有効なOuである場合は、コマンドの生成に成功したら trueを返します。
		ppCmd=NULL の場合は、コマンドの生成が可能であればtrueを返します。
		コマンドが生成できない場合は false を返します。
		フォーカスセルや選択セルが列車の位置にない場合は、falseとなります。
	*/
	bool createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Eki>* ppCmd );

	///@}
protected:
	// --------------------------------
	///@name OnUpdate の下請関数
	// --------------------------------
	///@{
	/**
		グリッドの Y列番号で指定された列に、
		『駅』の内容を設定します。

		グリッド全体を更新領域とします( InvalidateGrid() )。
	 @note
		駅属性の中の境界線の太さが変動した場合は、
		Y列番号で指定されたセルだけではなく、
		境界線・およびそれより下のすべてのセルの更新が必要になります。
		これに対応するため、 CWndDcdGridEki では、
		駅の属性の更新のたびにグリッド全域を更新しています。
	 @param iYColumnNumber [in]
		Y列番号を指定してください。
	 @param aCentDedEki [in]
		『駅』オブジェクトを指定してください。
	*/
	void OnUpdate_setCentDedEki_To_Column( int iYColumnNumber , 
			const CentDedEki& aCentDedEki ) ;

	/**
		OnUpdate() の下請関数です。
		関連するドキュメントの内容を、このウインドウに完全に
		反映します。
	
		OnUpdate() で pHint が NULL の際の動作です。
		
		このとき、ウインドウの更新再描画も発生します。
	 */
	virtual void  OnUpdate_All() ;
	///@}
	
protected:
	// --------------------------------
	///@name メニューコマンドの下請関数
	// --------------------------------
	///@{
	/**	
		[編集]-[切り取り]
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	@return
		成功したら0以上、エラーなら負の数です。
	*/
	int OnEditCut_Process( BOOL bQueryEnable );
	/**	
		[編集]-[コピー]
	*/
	int OnEditCopy_Process( BOOL bQueryEnable );
	/**	
		[編集]-[貼り付け]
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 ;	//	フォーカスセルの位置が不正です。
		-	-2 ;	//	クリップボードに駅のデータがありません
		-	-3 ;	//	クリップボードからのデータ取得に失敗  ;
	*/
	int OnEditPaste_Process( BOOL bQueryEnable );

	/**	
		[編集]-[消去]
	*/
	int OnEditClear_Process( BOOL bQueryEnable );

	/**	
		[編集]-[駅を挿入]
	@return
		成功したら0以上、エラーなら負の数です。
	*/
	int  OnEDITEkiInsert_Process( BOOL bQueryEnable );

	/**	
		[編集]-[駅の反転]
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 :	現在は実行できません。(エラーメッセージは表示しません)
		-	-2以下:	エラー
	*/
	int  OnEditEkiInvert_Process( BOOL bQueryEnable );

	/**	
		[編集]-[駅のプロパティ]
	@return
		成功したら0以上、エラーなら負の数です。
	*/
	int  OnEDITEkiProp_Process( BOOL bQueryEnable );

	///@}

 public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CWndDcdGridEki();
	virtual ~CWndDcdGridEki();

 protected:
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{
	///@}
 public:
	// ********************************
	///@name CWndDcdGridEki-属性
	// ********************************
	///@{
	bool getAdjustByEkijikokukeisiki()const ;
	int setAdjustByEkijikokukeisiki( bool value ) ;
	///@}
public:
	// ********************************
	///@name CEkiView からの委譲
	// ********************************
	///@{
	/**
		ViewのOnUpdateが委譲されます。
	*/
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	/**
		ViewのOnActivateViewが委譲されます。
	*/
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) ;
	///@}

public:
	// ********************************
	///@name CWndDcdGridEki-操作
	// ********************************
	///@{



	/**
		現在フォーカスのあるセルに対応して、
		『駅』プロパティダイアログを開き、
		駅プロパティの編集を行います。
	@param bInsert [in]
		- true ;	フォーカスのあるセルの位置に、
		新しい駅を挿入します。 
		- false ;	フォーカスのあるセルの位置の、
		駅のプロパティを更新します。
		(フォーカスセルが、一番下の空白の列にある場合は、
		末尾への挿入として動作します)
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 ;	//	フォーカスセルの位置が不正です。
		-	-2 ;	//	ダイアログボックスで Cancel されました。
	*/
	int execEkiPropDlg( bool bInsert , BOOL bQueryEnable ) ;
	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// アトリビュート
public:

// オペレーション
public:
	//{{AFX_VIRTUAL(CWndDcdGridEki)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CWndDcdGridEki)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//[編集]
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);
	afx_msg void OnEDITEkiInsert();
	afx_msg void OnUpdateEditEkiinsert(CCmdUI *pCmdUI);
	afx_msg void OnEDITEkiProp();
	afx_msg void OnUpdateEditEkiprop(CCmdUI *pCmdUI);
	afx_msg void OnEditEkiInvert();
	afx_msg void OnUpdateEditEkiInvert(CCmdUI *pCmdUI);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
};

} //namespace ViewEki

#endif /*CWndDcdGridEki_h*/
