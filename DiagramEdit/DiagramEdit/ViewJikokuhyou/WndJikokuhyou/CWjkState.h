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
//	CWjkState.h
// ****************************************************************
*/
/** @file */
#ifndef  CWjkState_h
#define  CWjkState_h
#include "DcdGrid\CDcdGridCell.h"

#include "entDed\CentDedDia.h"
#include "ViewJikokuhyou\CJikokuhyouDoc.h"

namespace ViewJikokuhyou{ namespace WndJikokuhyou{

using namespace DcDrawLib::DcdGrid;


class CWndJikokuhyou ;	// outer への参照

// ****************************************************************
//	CWjkState
// ****************************************************************
/**
   @brief
   【概要】
     CJikokuhyouの『状態』１つを表す抽象クラスです。
     『状態』毎に派生クラスを作成し、 CWndJikokuhyou への
   ウインドウメッセージハンドラ・メニューコマンドハンドラに対応する処理を
   実装してください。
   
     CWndJikokuhyou オブジェクトは、『状態』の数の CState を集約で
   保持します。また、それら『状態』のうちの一つを『カレント状態』とします。
   
     『カレント状態』は、 CWndJikokuhyou::m_iCurrentStateIndex 
   で表します。
 */	
class CWjkState
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	typedef CWndJikokuhyou outer ;
	
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
	  	  外側の CWndJikokuhyou オブジェクトへのポインタです。
	  	  このオブジェクトは、this が破棄されるまでは生存して
	  	いなくてはなりません。
	  	  コンストラクタで決まります。
	 */
	CWndJikokuhyou*	m_pCWndDcdGrid ;
	///@}

protected:
	// --------------------------------
	///@name	下請関数
	// --------------------------------
	///@{
	/**
	   @return
	  	対応するドキュメントオブジェクトを返します。
	 */
	CJikokuhyouDoc*	GetDocument() ;
	
	/**
	   @return
	  	このグリッドが扱う列車方向を返します。
	 */
	ERessyahoukou getRessyahoukou() ;
	
	
	/**
	   @return
	  	CentDedDia オブジェクトを返します。
	 */
	const CentDedDia*	getCentDedDia();
	
	/**
	   @return
	  	CentDedRessyaCont オブジェクトを返します。
	 */
	const CentDedRessyaCont*	getCentDedRessyaCont();
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CWjkState( CWndJikokuhyou*	pCWndDcdGrid ) ;
	virtual ~CWjkState() ;

public:
	// ********************************
	//	CWjkState
	// ********************************
	// ********************************
	///@name 関連
	// ********************************
	///@{
	CWndJikokuhyou*	getCWndDcdGrid();
	///@}
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
	 @return
		この状態に遷移可能であれば 0 以上です。
		デフォルトでは、0です。
		
		【オーバライド】
		この状態に遷移するための条件を指定してください。
	*/
	virtual int canEnter() ;
	/**
	 	この状態への入場動作を行います。
	 
	 	CWndJikokuhyou は、『カレント状態』をthis に設定した
	 	直後に、この関数を呼び出します。
	 
	 	【オーバライド】
	 	入場動作を実装してください。
	*/
	virtual void onEnter() = 0  ;
	/**
	 	この状態からの退場動作を行います。
	 
	 	CWndJikokuhyou は、『カレント状態』をthis から他に設定する
	 	直前に、この関数を呼び出します。
	 
	 	【オーバライド】
	 	退場動作を実装してください。
	*/
	virtual void onExit() = 0  ;
	///@}
	// ********************************
	///@name CView からの委譲
	// ********************************
	///@{
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) ;
	///@}
	// ********************************
	///@name CWndJikokuhyouからの委譲
	// ********************************
	///@{
	/**
	 	[オーバライド] CWndJikokuhyou::super (CWndDcdGrid)の
	 	実装に委譲します。
	*/
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	/**
	  	[オーバライド] CWndJikokuhyou::super (CWndDcdGrid)の
	  	実装に委譲します。
	 */
	virtual void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	/**
	  	[オーバライド] CWndJikokuhyou::super (CWndDcdGrid)の
	  	実装に委譲します。
	 */
	virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	/**
	  	[オーバライド] CWndJikokuhyou::super (CWndDcdGrid)の
	  	実装に委譲します。
	 */
	virtual void OnWM_IME_STARTCOMPOSITION() ;
	/**
	  	[オーバライド] CWndJikokuhyou::super (CWndDcdGrid)の
	  	実装に委譲します。
	 */
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point) ;
	///@}
	// ********************************
	///@name Viewのコマンドハンドラの委譲
	// ********************************
	///@{
	// --------------------------------
	//	Edit
	/**	
		[編集]-[切り取り]
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
					エラーが発生した場合は、エラーメッセージボックスを表示します
	@return
		成功したら0以上、エラーなら負の数です。
		-	-1 ;	//	このコマンドは選択できません
	
		このクラスでは、常に -1 です。
	*/
	virtual int OnEditCut_Process( BOOL bQueryEnable );

	/**	[編集]-[コピー]	*/
	virtual int OnEditCopy_Process( BOOL bQueryEnable );
	/**	[編集]-[貼り付け]	*/
	virtual int OnEditPaste_Process( BOOL bQueryEnable );
	/**	[編集]-[消去]	*/
	virtual int OnEditClear_Process( BOOL bQueryEnable );
	/**	[編集]-[時刻のみ貼り付け]	*/
	virtual int OnEditPasteEkiJikoku_Process( BOOL bQueryEnable );
	/**	[編集]-[すべて選択]	*/
	virtual int OnEditSelectAll_Process( BOOL bQueryEnable );

	// --------------------------------
	//	Jikokuhyou
	/** [時刻表]-[列車のプロパティ] */
	virtual int OnJikokuhyouRessyaProp_Process( BOOL bQueryEnable );
	/** [時刻表]-[列車を挿入] */
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
		-  -1 ;	//	このコマンドは選択できません(メニューが無効)
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
		-  -1 ;	//	このコマンドは選択できません(メニューが無効)
	*/
	virtual int OnJikokuhyouFocusMoveRight_Process( BOOL bQueryEnable );
	/** [時刻表]-[最小所要時間列車に移動] */
	virtual int OnJikokuhyouEKikanSaisyouSec_Process( BOOL bQueryEnable );
	/** [時刻表]-[並べ替え] */
	virtual int OnJikokuhyouSort_Process( BOOL bQueryEnable );
	/** [時刻表]-[列車番号で一本化] */
	virtual int OnJikokuhyouUnify_Process( BOOL bQueryEnable );
	// [時刻表]-[時刻表ビューのプロパティ] 
	//	は、CWndJikokuhyou で処理します。

	// --------------------------------
	//	Ekijikoku
	/** [駅時刻]-[駅時刻のプロパティ] */
	virtual int OnJikokuhyouEkijikokuProp_Process( BOOL bQueryEnable );
	/** [駅時刻]-[時刻消去] */
	virtual int OnJikokuhyouJikokuSakujo_Process( BOOL bQueryEnable );
	/** [駅時刻]-[通過] */
	virtual int OnJikokuhyouTsuuka_Process( BOOL bQueryEnable );
	/** [駅時刻]-[通過-停車] */
	virtual int OnJikokuhyouTsuukateisya_Process( BOOL bQueryEnable );
	/** [駅時刻]-[経由なし] */
	virtual int OnJikokuhyouKeiyunasi_Process( BOOL bQueryEnable );
	// --------------
	/** [駅時刻]-[当駅始発] */
	virtual int OnJikokuhyouSihatsu_Process( BOOL bQueryEnable );
	/** [駅時刻]-[当駅止り] */
	virtual int OnJikokuhyouSyuuchaku_Process( BOOL bQueryEnable );
	/** [駅時刻]-[直通化] */
	virtual int OnJikokuhyouDirect_Process( BOOL bQueryEnable );
	/** [駅時刻]-[分断] */
	virtual int OnJikokuhyouUndirect_Process( BOOL bQueryEnable );
	// --------------
	/** [駅時刻]-[連続入力] 
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	(bQueryEnable=TRUEの場合)この項目はすでに選択されています
		-	0 ;	//	(bQueryEnable=TRUEの場合)この項目は選択されていません
	*/
	virtual int OnJikokuhyouRenzoku_Process( BOOL bQueryEnable );
	// --------------
	/** [駅時刻]-[駅時刻を挿入] */
	virtual int OnJikokuhyouEkijikokuInsert_Process( BOOL bQueryEnable );
	/** [駅時刻]-[駅時刻を削除] */
	virtual int OnJikokuhyouEkijikokuErase_Process( BOOL bQueryEnable );
	/** [駅時刻]-[駅時刻変更] */
	virtual int OnJikokuhyouModifyEkijikokuCmd_Process( BOOL bQueryEnable );
	/** [駅時刻]-[駅時刻変更の再実行] */
	virtual int OnJikokuhyouModifyEkijikokuCmdRepeat_Process( 
		BOOL bQueryEnable );
	// --------------
	/** [駅時刻]-[連続1分修正]-[-1分し次へ] */
	virtual int OnJikokuhyouEkijikokuDec_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[-1分] */
	virtual int OnJikokuhyouEkijikokuDecNoMove_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[フォーカスを次へ] */
	virtual int OnJikokuhyouEkijikokuNext_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[フォーカスを前へ] */
	virtual int OnJikokuhyouEkijikokuPrev_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[+1分し次へ] */
	virtual int OnJikokuhyouEkijikokuInc_Process( BOOL bQueryEnable );
	/** [駅時刻]-[連続1分修正]-[+1分] */
	virtual int OnJikokuhyouEkijikokuIncNoMove_Process( BOOL bQueryEnable );
	///@}
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{
	/**
	 	[オーバライド] CWndJikokuhyou::super (CWndDcdGrid)の
	 	実装に委譲します。
	*/
	virtual void OnSetFocusCell( CDcdGridCell* pCDcdGridCell ) ;
	/**
		[オーバライド] CWndJikokuhyou::super (CWndDcdGrid)の
		実装に委譲します。
	*/
	virtual void OnSetXFixafterColumnNumber( int iFixafterColumnNumber ) ;
	/**
		[オーバライド] CWndJikokuhyou::super (CWndDcdGrid)の
		実装に委譲します。
	*/
	virtual void OnSetYFixafterColumnNumber( int iFixafterColumnNumber ) ;


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
		  処理はありません。
	
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



#endif //CWjkState_h
