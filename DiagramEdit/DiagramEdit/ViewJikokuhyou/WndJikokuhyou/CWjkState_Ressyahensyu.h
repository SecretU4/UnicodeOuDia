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
//	CWjkState_Ressyahensyu.h
// $Id: CWjkState_Ressyahensyu.h 241 2016-01-05 06:14:33Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWjkState_Ressyahensyu_h
#define  CWjkState_Ressyahensyu_h

#include "CWjkState.h"
#include "OuDlg/CKeyinputSenderToModalDlg.h"
#include "DedRosenFileData\EditCmd\EditCmd.h"

namespace ViewJikokuhyou{ namespace WndJikokuhyou{
	using namespace OuMfc::OuDlg;
	using namespace DedRosenFileData::EditCmd;
// ****************************************************************
//	CWjkState_Ressyahensyu
// ****************************************************************
/**
  @brief
 	『時刻表』グリッドウインドウの『状態』の一つです。
 	『列車編集モード』を実装します。
*/
class CWjkState_Ressyahensyu : 
	public CWjkState
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	typedef CWjkState	super ;

private:
	// ********************************
	///@name	包含/集約
	// ********************************
	///@{
	/**
	   親ウインドウへのキー入力を契機に ModalDialog を開く場合、
	  モーダルダイアログの特定のエディットコントロールに、
	  キー入力メッセージ（ WM_KEYDOWN , WM_KEYUP ）を転送します。
	 */
	CKeyinputSenderToModalDlg	m_CKeyinputSenderToModalDlg ;
	///@}

private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
	 	- false ;	//	[フォーカスセル下移動]
	 	- true ;	//	[フォーカスセル右移動]
	 	
	 初期値は false ですが、ユーザーのメニュー操作で変わります。
	 */
	bool m_bJikokuhyouFocusMoveRight ;
	///@}

private:
	// --------------------------------
	///@name OnUpdate下請関数
	// --------------------------------
	///@{
	/**
	OnUpdate() の下請関数です。
	ビューを完全に更新します。
	OnUpdate() で pHint が NULL の場合の処理を行います。
	 */
	void OnUpdate_All() ;


	/**
	OnUpdate() の下請関数です。
	OnUpdate() で pHint が 
	CRfEditCmd_Ressya オブジェクトの場合の処理を行います。

	CRfEditCmd_Ressya をもとに、
	ビューを部分的に更新します。
	 */
	void OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) ;
	///@}

protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
	 	現在フォーカスのあるセルに対応して、
	 	『列車』・『駅時刻』いずれかの
	 	プロパティダイアログを開き、
	 	プロパティの編集を行います。
	 
	 	execCDlgRessyaProp() ・
	 	execCDlgEkijikokuProp() のいずれかに委譲します。
	 
	  @param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	 @return
	  @param bInsert [in]
	 	- true ;	フォーカスのあるセルの位置に、
	 	新しい列車を挿入します。 
	 	- false ;	フォーカスのあるセルの位置の、
	 	列車のプロパティを更新します。
	 	(フォーカスセルが、一番右の空白の列にある場合は、
	 	末尾への挿入として動作します)
	 @return
	 	-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
	 	-	0 ;	//	ダイアログがキャンセルで終了したため、
	 			//	変更は発生しませんでした。
	 	-	-1 ;	//	X列番号が不正です。
	 	-	-2 ;	//	Y列番号が不正です。

	 */
	int execJikokuhyouPropDlg( bool bInsert , BOOL bQueryEnable  ) ;
	
	/**
	 	現在フォーカスのあるセルのX列番号に対応して
	 	『列車』プロパティダイアログを開き、
	 	プロパティの編集を行います。
	 @param bInsert [in]
	 	- true ;	フォーカスのあるセルの位置に、
	 	新しい列車を挿入します。 
	 	- false ;	フォーカスのあるセルの位置の、
	 	列車のプロパティを更新します。
	 	(フォーカスセルが、一番右の空白の列にある場合は、
	 	末尾への挿入として動作します)
	 @param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	 @return
	 @return
	 	-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
	 	-	0 ;	//	ダイアログがキャンセルで終了したため、@n
	 				変更は発生しませんでした。
	 	-	-1 ;	//	X列番号が不正です。
	*/
	int execCDlgRessyaProp( bool bInsert , BOOL bQueryEnable ) ;
	
	/**
	 	現在フォーカスのあるセルのX列・Y列番号に対応して
	 	『駅』プロパティダイアログを開き、
	 	プロパティの編集を行います。
	  @param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	 @return
	  @return
	*/
	int execCDlgEkiProp( BOOL bQueryEnable ) ;

	/**
	 	現在フォーカスのあるセルのX列・Y列番号に対応して
	 	『駅時刻』プロパティダイアログを開き、
	 	プロパティの編集を行います。
	@param bInsert [in]
	 	- true ;	フォーカスのあるセルの位置に、
	 	新しい列車を挿入します。 
	 	- false ;	フォーカスのあるセルの位置の、
	 	列車のプロパティを更新します。
	 	(フォーカスセルが、一番右の空白の列にある場合は、
	 	末尾への挿入として動作します)
	  @param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	 @return
	  @return
	 	-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
	 	-	0 ;	//	ダイアログがキャンセルで終了したため、@n
	 				変更は発生しませんでした。
	 	-	-1 ;	//	X列番号が不正です。
	 	-	-2 ;	//	Y列番号が不正です。
	 */
	int execCDlgEkijikokuProp( bool bInsert , BOOL bQueryEnable ) ;


	/**
	フォーカスセル移動モード m_bJikokuhyouFocusMoveRight に従い、
	フォーカスセルを、次の位置に移動します。

	@param bNextEkiOrder [in]
	 	m_bJikokuhyouFocusMoveRight が偽で、現在のフォーカスセルが、
	 	発着表示の駅時刻の着時刻にある場合の、フォーカスの移動先を
	 	指定します。
	 	- true ;	//	フォーカスセルを次の駅Orderに移動します。
	 	- false ;	//	フォーカスセルを同じ駅の発時刻に移動します。
	@return 
	 	成功したら 0 以上、エラーなら負の数です。
	*/
	virtual int moveFocusCellToNext( bool bNextEkiOrder ) ;
	
	/**
	フォーカスセル移動モード m_bJikokuhyouFocusMoveRight に従い、
	フォーカスセルを、前の位置に移動します。

	@param bNextEkiOrder [in]
	 	m_bJikokuhyouFocusMoveRight が偽で、現在のフォーカスセルが、
	 	発着表示の駅時刻の発時刻にある場合の、フォーカスの移動先を
	 	指定します。
	 	- true ;	//	フォーカスセルを前の駅Orderに移動します。
	 	- false ;	//	フォーカスセルを同じ駅の着時刻に移動します。
	@return 
	 	成功したら 0 以上、エラーなら負の数です。
	 */
	virtual int moveFocusCellToPrev( bool bNextEkiOrder ) ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CWjkState_Ressyahensyu( 
		CWndJikokuhyou*	pCWndDcdGrid );
	virtual ~CWjkState_Ressyahensyu() ;

protected:
	// ********************************
	//	CWjkState
	// ********************************
	// ********************************
	///@name CWjkState-操作
	// ********************************
	///@{
	/**
	 *	この状態への入場動作を行います。
	 *
	 *	CWndJikokuhyou は、『カレント状態』をthis に設定した
	 *	直後に、この関数を呼び出します。
	 *
	 *	【オーバライド】
	 *	入場動作を実装してください。
	 */
	virtual void onEnter() ;
	/**
	 *	この状態からの退場動作を行います。
	 *
	 *	CWndJikokuhyou は、『カレント状態』をthis から他に設定する
	 *	直前に、この関数を呼び出します。
	 *
	 *	【オーバライド】
	 *	退場動作を実装してください。
	 */
	virtual void onExit() ;
	///@}
	// ********************************
	///@name CView からの委譲
	// ********************************
	///@{
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	///@}
	// ********************************
	///@name メッセージハンドラ・コマンドハンドラ-CWnd
	// ********************************
	///@{
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	virtual void OnWM_IME_STARTCOMPOSITION() ;

	// --------------------------------

	/**	
		[編集]-[切り取り]
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 ;	//	現在のフォーカスセルでは、実行できません
	*/
	virtual int OnEditCut_Process( BOOL bQueryEnable );

	/**	[編集]-[コピー]	
	@return
		iRv = -1 ;	//	現在のフォーカスセルでは、実行できません
	*/
	virtual int OnEditCopy_Process( BOOL bQueryEnable );
	/**	[編集]-[貼り付け]	
	@return
		-	-1 ;	//	現在のフォーカスセルでは、実行できません
		-	-2 ;	//	クリップボードにデータがありません。
	*/
	virtual int OnEditPaste_Process( BOOL bQueryEnable );
	/**	[編集]-[消去]
	@return
		-	-1 ;	//	現在のフォーカスセルでは、実行できません
	*/
	virtual int OnEditClear_Process( BOOL bQueryEnable );
	/**	[編集]-[時刻のみ貼り付け]
	@return
		-	-1 ;	//	現在のフォーカスセルでは、実行できません
		-	-2 ;	//	クリップボードにデータがありません。
	*/
	virtual int OnEditPasteEkiJikoku_Process( BOOL bQueryEnable );
	/**	[編集]-[すべて選択]	
		列車選択モード(CWjkState_Ressyasentaku ) 
		に委譲します。
	*/
	virtual int OnEditSelectAll_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [時刻表]-[列車のプロパティ] */
	virtual int OnJikokuhyouRessyaProp_Process( BOOL bQueryEnable );
	/** [時刻表]-[列車を挿入] 
		空行を挿入する
	@return
		-	-1 ;	//	X列番号が不正です。
	*/
	virtual int OnJikokuhyouRessyaInsert_Process( BOOL bQueryEnable );
	/** [時刻表]-[フォーカス下移動] 
	 @param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否か・選択されているかの@n
					判定だけを行います。エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	(bQueryEnable=TRUEの場合)この項目はすでに選択されています
		-	0 ;	//	(bQueryEnable=TRUEの場合)この項目は選択されていません
	*/
	virtual int OnJikokuhyouFocusMoveDown_Process( BOOL bQueryEnable );
	/** [時刻表]-[フォーカス右移動] 
	 @param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否か・選択されているかの@n
					判定だけを行います。エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	(bQueryEnable=TRUEの場合)この項目はすでに選択されています
		-	0 ;	//	(bQueryEnable=TRUEの場合)この項目は選択されていません
	*/
	virtual int OnJikokuhyouFocusMoveRight_Process( BOOL bQueryEnable );
	/** [時刻表]-[最小所要時間列車に移動] 
	 	フォーカスセルを、現在フォーカスセルのある駅と次の駅の間を
	 	走る最小所要秒数の列車に移動します。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1  ;	セルの場所が不正
		-	-2 ;	フォーカスセルが終着駅にある場合は、@n
					この機能は実行できません。
		-	-21 ;	駅間最小所要秒数列車が決定できません。@n
					時刻が%s駅と%s駅の両方に設定された列車が１本もありません。
	*/
	virtual int OnJikokuhyouEKikanSaisyouSec_Process( BOOL bQueryEnable );

	/** [時刻表]-[並べ替え] 
		この関数は、On...() コマンドハンドラ・OnUpdate...() コマンドハンドラの
		実処理を行います。

		フォーカスのある駅時刻で列車をソートします。
		フォーカスが列車種別・列車名・号数にある場合は、
		列車種別・列車名・号数でソートします。
	*/
	virtual int OnJikokuhyouSort_Process( BOOL bQueryEnable );

	/** [時刻表]-[列車番号で一本化] 
		この関数は、On...() コマンドハンドラ・OnUpdate...() コマンドハンドラの
		実処理を行います。

		全列車を列車番号で一本化します。
	*/
	virtual int OnJikokuhyouUnify_Process( BOOL bQueryEnable );

	// --------------------------------
	/** [駅時刻]-[駅時刻のプロパティ] 
	 @return
	 	-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
	 	-	0 ;	//	ダイアログがキャンセルで終了したため、@n
	 				変更は発生しませんでした。
	 	-	-1 ;	//	X列番号が不正です。
	 	-	-2 ;	//	Y列番号が不正です。
	*/
	virtual int OnJikokuhyouEkijikokuProp_Process( BOOL bQueryEnable );

	/** [駅時刻]-[時刻消去] 
	 	フォーカスセルの位置の『時刻Order』を 『Null時刻』に変更します。
		この結果、着時刻も発時刻も『NULL時刻』になった場合は、
		駅扱を『運行なし』にします。


	 	ドキュメントに反映し、
	 	UpdateAllSubDocview() で、ドキュメントの反映を行います。
	 
		フォーカスを次の位置に移動します。
	@return
		-	-11  ;	//	セルの場所が不正
		-	-1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
	*/
	virtual int OnJikokuhyouJikokuSakujo_Process( BOOL bQueryEnable );

	/** [駅時刻]-[通過] 
		フォーカスセルの位置の『駅時刻』を『通過』に変更します。
		駅時刻は着時刻・発時刻ともNULLにします。

		ドキュメントに反映し、
		UpdateAllSubDocview() で、ドキュメントの反映を行います。

		フォーカスを次の位置に移動します。

	@return
		-	-11  ;	//	セルの場所が不正
		-	-1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
	*/
	virtual int OnJikokuhyouTsuuka_Process( BOOL bQueryEnable );
	
	/** [駅時刻]-[通過-停車] 
		フォーカスセルの位置の『駅時刻』が『停車』『運行なし』
		『経由なし』なら、
		『通過』に変更します。駅時刻は変更しません。

		フォーカスセルの位置が『通過』なら、
		『停車』に変更します。駅時刻は変更しません。

		ドキュメントに反映し、
		UpdateAllSubDocview() で、ドキュメントの反映を行います。

		フォーカスを次の位置に移動します。
	@return
		-	-11  //	セルの場所が不正
		-	-1 	//	セルの位置が、特定の列車の特定の時刻の場所ではない
	*/
	virtual int  OnJikokuhyouTsuukateisya_Process( BOOL bQueryEnable );

	/** [駅時刻]-[経由なし] 
		フォーカスセルの位置の『駅時刻』を『経由なし』に変更します。

		ドキュメントに反映し、
		UpdateAllSubDocview() で、ドキュメントの反映を行います。
		フォーカスを次の位置に移動します。
	@return
		-	-11  //	セルの場所が不正
		-	-1 	//	セルの位置が、特定の列車の特定の時刻の場所ではない
	*/
	virtual int OnJikokuhyouKeiyunasi_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [駅時刻]-[当駅始発] 
	@return 
		成功したら0以上、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
		-	-1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
	*/
	virtual int OnJikokuhyouSihatsu_Process( BOOL bQueryEnable );
	/** [駅時刻]-[当駅止り] 
		-	-11  ;	//	セルの場所が不正
		-	-1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
	*/
	virtual int OnJikokuhyouSyuuchaku_Process( BOOL bQueryEnable );

	/** [駅時刻]-[直通化] 
		途中駅止まりの列車と、その途中駅始発の列車を直通化します。
		ドキュメントに反映し、
		UpdateAllSubDocview() で、ドキュメントの反映を行います。
		フォーカスを次の位置に移動します。

	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	@return 
		成功したら0以上、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
		-	-12 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
		-	-13;	//	セルの位置が、終着駅より上
		-	-14 ;	//	対応する始発列車が見つかりません。
					
	［１］フォーカスが、列車の終着駅よりも上の駅にある場合は、
		この機能は使用できません。

	［２］直通化の対象になる途中駅始発列車
	  直通化の対象となる途中駅始発列車は、以下の条件を満たした列車です。

	  ・フォーカスのある列車(途中駅止まりの列車)と同じ列車種別
	  ・フォーカスのある駅を始発駅とする列車
	  ・始発駅の発時刻が、終着列車の着時刻から12時間以内
	  ・時刻表ビュー上で、フォーカスのある列車の右側にある列車

	  対象となる列車が複数ある場合は、その中でもっとも左側にある列車を
	  直通化の対象とします。

	［３］　直通化を行った結果作成される新しい列車の、直通化した駅の
	駅時刻は、以下のようになります。

	- 駅扱：途中駅止まりの列車と同じ。
	- 着時刻
		- 途中駅止まりの列車に着時刻が指定されていた場合：
			その着時刻
		- 途中駅止まりの列車に着時刻がなく、発時刻が指定されていた場合：
			途中駅止まり列車の発時刻
		- 途中駅止まりの列車に着時刻も発時刻も指定されていない場合：
			着時刻はなし
	- 発時刻
		- 途中駅始発列車に発時刻が指定されていた場合：
			その発時刻を直通化した列車の発時刻とします。
		- 途中駅始発列車に発時刻がなく、着時刻が指定されていた場合：
			途中駅始発列車の着時刻を、新しい列車の発時刻とします。
		- 途中駅始発列車に着時刻も発時刻も指定されていない場合：
			発時刻はなし
	*/
	virtual int OnJikokuhyouDirect_Process( BOOL bQueryEnable );

	/** [駅時刻]-[分断] 
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します	@return 
		成功したら0以上、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
		-	-12 ;	//	セルの位置が特定の列車の特定の時刻の場所ではない。
		-	-21 ;	//	その列車の始発駅・終着駅では分断はできません。
		-	-22 ;	//	駅時刻に着時刻も発時刻も指定されていない駅では、この機能は使用できません
		-	-31 ;	//	指定の駅Orderでは、分断はできません
	*/
	virtual int OnJikokuhyouUndirect_Process(BOOL bQueryEnable );

	// --------------------------------
	/** [駅時刻]-[連続入力] 
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	(bQueryEnable=TRUEの場合)この項目はすでに選択されています
		-	0 ;	//	(bQueryEnable=TRUEの場合)この項目は選択されていません
		-	-1 ;	//	現在、このコマンドは選択できません
	*/
	virtual int OnJikokuhyouRenzoku_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [駅時刻]-[駅時刻を挿入] 
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
		-	-1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
		-	-2 ;	//	一番下の駅では、この操作はできません。
	*/
	virtual int OnJikokuhyouEkijikokuInsert_Process( BOOL bQueryEnable );
	/** [駅時刻]-[駅時刻を削除] 
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
		-	-1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
		-	-2 ;	//	一番下の駅では、この操作はできません。
	*/
	virtual int OnJikokuhyouEkijikokuErase_Process( BOOL bQueryEnable );
	/** 
		[駅時刻]-[駅時刻変更] 

		『駅時刻変更』ダイアログを表示し、入力内容を
		m_EkijikokuModifyOperation に保存します。
		また、
		m_EkijikokuModifyOperation の内容にしたがって、
		フォーカス位置の駅時刻を変更します。
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
				エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
				エラーが発生した場合は、エラーメッセージボックスを表示します。
	@return
		-	0 :	成功
		-	-1 :	現在は実行できません。(エラーメッセージは表示しません)
	*/
	virtual int OnJikokuhyouModifyEkijikokuCmd_Process( BOOL bQueryEnable );

	/**
		[駅時刻]-[駅時刻変更の再実行]

		前回の『駅時刻変更』ダイアログで設定された
		m_EkijikokuModifyOperation の内容にしたがって、
		フォーカス位置の駅時刻を変更します。
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
				エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
				エラーが発生した場合は、エラーメッセージボックスを表示します。
	@return
		-	0 :	成功
		-	-1 :	現在は実行できません。(エラーメッセージは表示しません)
	*/
	virtual int OnJikokuhyouModifyEkijikokuCmdRepeat_Process( 
		BOOL bQueryEnable );
	// --------------------------------
	/** [駅時刻]-[連続1分修正]-[-1分し次へ] 
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
		-	-1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
	*/
	virtual int OnJikokuhyouEkijikokuDec_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[-1分] 
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
		-	-1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
	*/
	virtual int OnJikokuhyouEkijikokuDecNoMove_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[フォーカスを次へ] 
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
	*/
	virtual int OnJikokuhyouEkijikokuNext_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[フォーカスを前へ] 
	@return
		成功したら 0 以上、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
	*/
	virtual int OnJikokuhyouEkijikokuPrev_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[+1分し次へ] 
	@return
		成功したら 0 以上、エラーなら負の数です。
			iRv = -11  ;	//	セルの場所が不正
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
	*/
	virtual int OnJikokuhyouEkijikokuInc_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[+1分] 
	@return
		成功したら 0 以上、エラーなら負の数です。
			iRv = -11  ;	//	セルの場所が不正
			iRv = -1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない
	*/
	virtual int OnJikokuhyouEkijikokuIncNoMove_Process( BOOL bQueryEnable );
	// --------------------------------

	///@}
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{
	/**
	 	Shift キーが押されていれば、カレント状態を『列車選択モード』に
	 	遷移させます。
	 	
	 	Shift キーが押されていない場合は、
	 	『列車選択モード』の OnSetFocusCell() に委譲します
	 */
	virtual void OnSetFocusCell( CDcdGridCell* pCDcdGridCell ) ;

	/**
	  this は、WndDcdGrid3::CSelectCell::m_bIsSelected が
	  変化したときに、この仮想関数を呼び出します。
	  クラスユーザーは、この仮想関数をオーバライドして、必要な処理を
	実装できます。
	  
	  this は、クラスユーザーが 
	CWndDcdGrid::CSelect::setColumnNumberSelect() で
	値を設定したときのほか、
	キーボードで選択セルを変更したときにも
	この仮想関数を呼び出します。
	
	[オーバライド]
	  選択列車数が0以上になったら選択モードに遷移します。
	
	@param iXColumnNumber [in]
		X列番号を指定します。
	@param iYColumnNumber [in]
		X列番号を指定します。
	@param bIsSelected [in]
		新しい選択状態。
	 */
	virtual void OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) ;

	///@}
};

} } // namespace WndJikokuhyou namespace ViewJikokuhyou

#endif /*CWjkState_Ressyahensyu_h*/
