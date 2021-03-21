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
//	CWndDcdGridRessyasyubetsu.h
//	$Id: CWndDcdGridRessyasyubetsu.h 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWndDcdGridRessyasyubetsu_h
#define  CWndDcdGridRessyasyubetsu_h

#include "DcdGrid/WndDcdGrid3/WndDcdGrid3.h"
#include "OuDlg/CKeyinputSenderToModalDlg.h"
#include "DcDraw/CDcdFreeLine.h"

#include "CDcdFreeLine_StyleSample.h"
#include "..\entDed\CconvCentDed.h"
#include "ViewRessyasyubetsu\RessyasyubetsuColSpec\RessyasyubetsuColSpec.h"

namespace ViewRessyasyubetsu{ 

	using namespace RessyasyubetsuColSpec ;
	using namespace DcDrawLib::DcdGrid::WndDcdGrid3 ;
// ****************************************************************
//	CWndDcdGridRessyasyubetsu
// ****************************************************************
/**
@brief
 【概要】 CRessyasyubetsuView で用いる、グリッドウインドウです。
 */
class CWndDcdGridRessyasyubetsu : public CWndDcdGrid
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

		 - [編集]-[上へ],[編集]-[下へ]

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

	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
	 通常は false 。
	このビューがアクティブでないときに 
	全更新（ OnUpdate_All() を呼び出す）が必要になってから、
	ビューがアクティブになるまでの間だけ true になります。

	 この変数が true のときは、
	ビューの更新を、次にビューがアクティブ化されるまで
	保留していることを示します。

	 ビューがアクティブでないときに OnUpdate_All() が
	要求されたら、この変数を true にし、
	OnUpdate_All() は実行しません。

	 この値が true のときに、ビューがアクティブ化されたら、
	OnUpdate_All() を実行します。
	 */
	bool m_bUpdate_All_Requested ;

	///@}
	
protected:
	// --------------------------------
	///@name	下請関数
	// --------------------------------
	///@{


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
	CdRessyasyubetsuXColSpecCont createXColSpecCont();


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
	CdRessyasyubetsuYColSpecCont createYColSpecCont();

	/**
	@return 
		フォーカスセルの列の表示内容を返します。
	*/
	CdRessyasyubetsuXColSpec getXColSpecOfFocus();

	/**
	@return 
		フォーカスセルの列の表示内容を返します。
	*/
	CdRessyasyubetsuYColSpec getYColSpecOfFocus() ;
	
	/**
	DcdGridでの選択内容に応じた、編集コマンドオブジェクト
	(CRfEditCmd_Ressyasyubetsu)を生成します。
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
	bool createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu>* ppCmd );


	///@}
	// --------------------------------
	///@name OnUpdate の下請関数
	// --------------------------------
	///@{
	/**
	 グリッドの 指定のY列に、
	『列車種別』の内容を設定します。
	設定を行ったセルは、更新領域とします。
	@attention
		グリッドの 列車種別番号の X列は更新しません。
		この処理のためには、各Y列に対してこの関数を呼び出した後に、
		グリッド全体に対して
		OnUpdate_setRessyasyubetsuNoXColumn() を
		呼び出す必要があります。
	@param iYColumnNumber [in]
		Y列番号を指定してください。
	@param CentDedRessyasyubetsu [in]
		『列車種別』オブジェクトを指定してください。
	*/
	void OnUpdate_setCentDedRessyasyubetsu_To_Column( 
		int iYColumnNumber , 
		const CentDedRessyasyubetsu& aCentDedRessyasyubetsu ) ;

	/**
	 列車種別番号を更新します。

	 グリッドの 列車種別番号の X列に、
	"0"～"9" の番号を設定します(10個目以降には、空白を設定します)。

	 設定を行ったセルは、更新領域とします。
	@note
		駅属性の中の境界線の太さが変動した場合は、
		Y列番号で指定されたセルだけではなく、
		境界線・およびそれより下のすべてのセルの更新が必要になります。
		これに対応するため、 CWndDcdGridEki では、
		駅の属性の更新のたびにグリッド全域を更新しています。
	*/
	void OnUpdate_setRessyasyubetsuNoXColumn() ;

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
					エラーが発生した場合は、エラーメッセージボックスを表示します
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 :	//	フォーカスセルの位置が不正です。
		-	-2 :	//	列車種別が1であれば、このメニューコマンドは無効
		-	-3 :	//削除しようとしている列車種別の列車が存在します
	*/
	int OnEditCut_Process( BOOL bQueryEnable );
	/**	[編集]-[コピー]	
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 ;	//	フォーカスセルの位置が不正です。
	*/
	int OnEditCopy_Process( BOOL bQueryEnable );
	/**	[編集]-[貼り付け]
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 :	//	フォーカスセルの位置が不正です。
		-	-2 :	//	クリップボードに列車種別のデータがありません
		-	-3 ;	//	クリップボードからのデータ取得に失敗  ;
	*/
	int OnEditPaste_Process( BOOL bQueryEnable );
	/**	[編集]-[消去]
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 :	//	フォーカスセルの位置が不正です。
		-	-2 :	//	列車種別が1であれば、このメニューコマンドは無効
		-	-3 :	//削除しようとしている列車種別の列車が存在します
	*/
	int OnEditClear_Process( BOOL bQueryEnable );
	/**	[編集]-[列車種別を挿入]	*/
	int OnEDITRessyasyubetsuInsert_Process( BOOL bQueryEnable );
	/**	[編集]-[上へ]
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 :	//	フォーカスセルの位置が正当
	*/
	int OnRessyasyubetsuUp_Process( BOOL bQueryEnable );
	/**	[編集]-[下へ]	
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 :	//	フォーカスセルの位置が正当
	*/
	int OnRessyasyubetsuDown_Process( BOOL bQueryEnable );
	/**	[編集]-[列車種別のプロパティ]	*/
	int OnEDITRessyasyubetsuProp_Process( BOOL bQueryEnable );
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CWndDcdGridRessyasyubetsu();
	virtual ~CWndDcdGridRessyasyubetsu();

	// ********************************
	///@name	CDcdGrid
	// ********************************
	///@{
	///@}
protected:
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{

	// --------------------------------
	///@name	イベント処理のための仮想関数
	// --------------------------------
	///@{
	///@}
 public:
	// ********************************
	///@name  CRessyasyubetsuView からの委譲
	// ********************************
	///@{
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	///@}
public:
	// ********************************
	///@name CWndDcdGridRessyasyubetsu-操作
	// ********************************
	///@{
	/**
		現在フォーカスのあるセルに対応して、
		『列車種別』プロパティダイアログを開き、
		列車種別プロパティの編集を行います。
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
	int execRessyasyubetsuPropDlg( bool bInsert/*=false*/ ,BOOL bQueryEnable );
	///@}
	
// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// アトリビュート
public:

// オペレーション
public:
	//{{AFX_VIRTUAL(CWndDcdGridRessyasyubetsu)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CWndDcdGridRessyasyubetsu)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//[編集]
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);
	afx_msg void OnEDITRessyasyubetsuInsert();
	afx_msg void OnUpdateRessyasyubetsuInsert(CCmdUI *pCmdUI);
	afx_msg void OnRessyasyubetsuUp();
	afx_msg void OnUpdateRessyasyubetsuUp(CCmdUI* pCmdUI);
	afx_msg void OnRessyasyubetsuDown();
	afx_msg void OnUpdateRessyasyubetsuDown(CCmdUI* pCmdUI);
	afx_msg void OnEDITRessyasyubetsuProp();
	afx_msg void OnUpdateRessyasyubetsuProp(CCmdUI *pCmdUI);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

} //namespace ViewRessyasyubetsu

#endif /*CWndDcdGridRessyasyubetsu_h*/
