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
//	CWjkState_Renzoku.h
//	$Id: CWjkState_Renzoku.h 368 2016-08-19 11:11:10Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWjkState_Renzoku_h
#define  CWjkState_Renzoku_h

#include <string>
#include "CWndJikokuhyou.h"
#include "CWjkState.h"
#include "OuDlg/CKeyinputSenderToModalDlg.h"
#include "DedRosenFileData\EditCmd\EditCmd.h"

namespace ViewJikokuhyou{ namespace WndJikokuhyou{
	using namespace DedRosenFileData::EditCmd;
// ****************************************************************
//	CWjkState_Renzoku
// ****************************************************************
/**
 * @brief
 *	『時刻表』グリッドウインドウの『状態』の一つです。
 *	『連続入力モード』を実装します。
 */
class CWjkState_Renzoku : 
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
	///@}

private:
	// --------------------------------
	///	@name 内部データ
	// --------------------------------
	///@{
	/**
		現在連続入力中のセルの、X列番号・Y列番号です。
	
		モード開始時（OnEnter）と、新しいセルへの連続入力開始時に、
		フォーカスセルの値を設定します。
	
		OnKeyDown() : 
		セルに数字２桁の入力が完了したときには、
		その文字列を取得し、駅時刻を更新します。
		その後、startEditCell() で、フォーカスセルを１つ下に移動します。
	
		OnSetFocusCell() : 
		フォーカスセルがこの値と異なるセルに移動した場合は、
		『連続入力モード』->『列車編集モード』
		に遷移します。
	*/
	int m_iXColumnNumberFocus ;

	/**
		入力中の分。
	*/
	std::string m_strMinutes ;
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

	このような更新が発生した場合は、
	『連続入力モード』->『列車編集モード』
	に遷移します。
	OnUpdate() は、『列車編集モード』に委譲します。
	*/
	void OnUpdate_All() ;


	/**
	OnUpdate() の下請関数です。
	OnUpdate() で pHint が 
	CRfEditCmd_Ressya オブジェクトの場合の処理を行います。
 	*/
	void OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) ;
	
	
	///@}
 private:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
	属性の正規化を行います。

	- ○[フォーカスセルが編集中列車の着発時刻ではない]Ressyahensyuに遷移
	- ○[フォーカス位置の駅時刻Ourder以前に、駅時刻の入力された駅が一つもない]Ressyahensyuに遷移
	*/
	bool update_adjustProp() ;

	/**
		属性に応じて、画面表示を更新します。

		- 1. 編集中列を、駅時刻で更新
		- 2. 編集中の駅時刻Orderに対して、「直前の駅時刻の時+編集中の分」を設定

	@param bOnExit
		- false : onExit()以外の動作を行います。
			「2. 編集中の駅時刻Orderに対して、「直前の駅時刻の時+編集中の分」を設定」
			の処理も行います。
		- true:   onExit() 時の動作を行います。
			「2. 編集中の駅時刻Orderに対して、「直前の駅時刻の時+編集中の分」を設定」
			の処理は行いません。
	*/
	bool update_updateScreen(bool bOnExit=false) ;

	/**
		属性の正規化と、画面表示更新を行います。
	*/
	bool update() ;

	/**
	連続入力モードにおける、カレントセルの次のセルを計算します。
	対象は、駅時刻のセルに限定されます。
	@param pcellCurrent [in]
		カレントセルを指定してください。
	@param iSign [in]
		移動方向を指定してください。
		-	+1 ;	//	駅Orderが増加するほうに移動します。
		-	-1 ;	//	駅Orderが減少するほうに移動します。
	@return
		次のセルが決定できれば、そのセルのオブジェクトを返します。
		決定できない場合は、NULLを返します。
	*/
	CDcdGridCell* calcCellToNext( CDcdGridCell* pcellCurrent , int iSign ) ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CWjkState_Renzoku( 
		CWndJikokuhyou*	pCWndDcdGrid );
	virtual ~CWjkState_Renzoku() ;

protected:
	// ********************************
	//	CWjkState
	// ********************************
	// ********************************
	///@name CWjkState-操作
	// ********************************
	///@{
	/**
	 @return
		この状態に遷移可能であれば 0 以上です。
		-	-1 ;	//	セルの位置が、特定の列車の特定の時刻の場所ではない。
		-	-2 ;	//	セルの位置より前に、駅時刻が設定されていない
	
	【オーバライド】

	以下の条件の１つでも満たしている場合は、列車選択モードは
	開始できません。

	- セルの位置が、特定の列車の特定の時刻の場所ではない。
	- セルの位置より前に、駅時刻が設定されていない
	- セルの位置が、駅時刻の最下段のセル
	
	*/
	virtual int canEnter() ;

	/**
		この状態への入場動作を行います。
	
		CWndJikokuhyou は、『カレント状態』をthis に設定した
		直後に、この関数を呼び出します。
	
		【オーバライド】
	
		m_iXColumnNumberFocus をフォーカスセルで変更します。

		m_strMinutes は空文字列とします。

		そのうえで、表示を更新します。

		以下の条件の１つでも満たしている場合は、列車選択モードは
		開始できません。
	
		- セルの位置が、特定の列車の特定の時刻の場所ではない。
		- セルの位置より前に、駅時刻が設定されていない
		- セルの位置が、駅時刻の最下段のセル
	
		この場合は、直ちに『列車編集モード』に遷移します。
	*/
	virtual void onEnter() ;
	/**
		この状態からの退場動作を行います。
	
		CWndJikokuhyou は、『カレント状態』をthis から他に設定する
		直前に、この関数を呼び出します。
	
		【オーバライド】
	
		m_iXColumnNumberFocus に対応する列を更新します。
	*/
	virtual void onExit() ;
	///@}
	// ********************************
	///@name CView からの委譲
	// ********************************
	///@{
	/**
		pHint が CHint_CentDedRessya で、なおかつ
		pCHint_CentDedRessya.m_eOperation == OperationUpdate の場合は、
		列の再設定を行います。
		その後、フォーカスセルの位置に、
		時の初期設定を行います。
	
		その他の場合は、
		『連続入力モード』->『列車編集モード』
		に遷移します。OnUpdate() は新しいモードに委譲します。
	*/
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	///@}
	// ********************************
	///@name メッセージハンドラ・コマンドハンドラ-CWnd
	// ********************************
	///@{

	/**
		"0"～"9" ,BackSpace : 現在入力中のセルの文字列を更新し、
		文字列をセルに設定します。
	
		文字数が４文字になった（時刻入力が完成）場合は、分の部分を取得し、
		時刻に変換します。
		この時刻が、その列車の直前の時刻よりも小さい（前の）場合は、
		１時間を加算します。
	
		求めた時刻を、ドキュメントに反映し、
		UpdateAllSubDocview() で、ドキュメントの反映を行います。
		このときの pHint は、
		CHint_CentDedRessya オブジェクト
		( m_eOperation == OperationUpdate ) とします。
	
		startFocusCell() で、フォーカスを次の位置に移動します。
		次のフォーカス位置が『駅時刻』でないのなら、
		モードは
		『連続入力モード』->『列車編集モード』
		に遷移します。
	
		"BS" :
	
		[分を1文字入力している]
		分の１文字を削除して、
		文字列をセルに設定します。
		
		[分を０文字入力している]
		startFocusCell() で、フォーカスを前の位置に移動します。
		次のフォーカス位置が『駅時刻』でないのなら、
		モードは
		『連続入力モード』->『列車編集モード』
		に遷移します。
	
		"ESC" : 
		モードを
		『連続入力モード』->『列車編集モード』
		に遷移します。
	*/
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	/**
	*/
	virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	// --------------------------------

	/**[駅時刻]-[時刻消去]
		フォーカスセルの位置の『時刻Order』を 『Null時刻』に変更します。
		ドキュメントに反映し、
		UpdateAllSubDocview() で、ドキュメントの反映を行います。
		このときの pHint は、
		CHint_CentDedRessya オブジェクト
		( m_eOperation == OperationUpdate ) とします。
	
		calcCellToNext() で、フォーカスを次の位置に移動します。
		次のフォーカス位置が『駅時刻』でないのなら、
		モードは
		『連続入力モード』->『列車編集モード』
		に遷移します。
	@return	
		-	-1 ;	//	フォーカスセルが、列車の位置ではありません。
		-	-2 ;	//	フォーカスセルが、駅時刻の位置ではありません。
	*/
	virtual int OnJikokuhyouJikokuSakujo_Process( BOOL bQueryEnable );

	/** [駅時刻]-[通過] 
	フォーカスセルの位置の『駅時刻』を『通過』に変更します。
	駅時刻は着時刻・発時刻ともNULLにします。

	ドキュメントに反映し、
	UpdateAllSubDocview() で、ドキュメントの反映を行います。

	フォーカスを次の位置に移動します。

	次のフォーカス位置が『駅時刻』でないのなら、
	モードは
	『連続入力モード』->『列車編集モード』
	に遷移します。
	*/
	virtual int OnJikokuhyouTsuuka_Process( BOOL bQueryEnable );

	/** [駅時刻]-[通過-停車] 
	この関数は、On...() コマンドハンドラ・OnUpdate...() コマンドハンドラの
	実処理を行います。

	フォーカスセルの位置の『駅時刻』が『停車』『運行なし』『経由なし』なら、
	『通過』に変更します。駅時刻は変更しません。

	フォーカスセルの位置が『通過』で、駅時刻に着時刻・発時刻のいずれかがあるなら、
	『停車』に変更します。駅時刻は変更しません。

	ドキュメントに反映し、
	UpdateAllSubDocview() で、ドキュメントの反映を行います。

	フォーカスを次の位置に移動します。

	次のフォーカス位置が『駅時刻』でないのなら、
	モードは
	『連続入力モード』->『列車編集モード』
	に遷移します。

	*/
	virtual int OnJikokuhyouTsuukateisya_Process( BOOL bQueryEnable );

	/** [駅時刻]-[経由なし] 
	 フォーカスセルの位置の『駅時刻』を『経由なし』に変更します。
	ドキュメントに反映し、
	UpdateAllSubDocview() で、ドキュメントの反映を行います。
	このときの pHint は、
	CHint_CentDedRessya オブジェクト
	( m_eOperation == OperationUpdate ) とします。

	startFocusCell() で、フォーカスを次の位置に移動します。
	次のフォーカス位置が『駅時刻』でないのなら、
	モードは
	『連続入力モード』->『列車編集モード』
	に遷移します。
	@return
		-	-1 ;	//	フォーカスセルが、列車の位置ではありません。
		-	-2 ;	//	フォーカスセルが、駅時刻の位置ではありません。
	*/
	virtual int OnJikokuhyouKeiyunasi_Process( BOOL bQueryEnable );

	// --------------------------------
	/** [駅時刻]-[連続入力] 
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	(bQueryEnable=TRUEの場合)この項目はすでに選択されています
		-	0 ;	//	(bQueryEnable=TRUEの場合)この項目は選択されていません
		-	-1 ;	//	現在、このコマンドは選択できません
	*/
	virtual int OnJikokuhyouRenzoku_Process( BOOL bQueryEnable );
	///@}
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{
	/**
		フォーカスセルの位置が、連続入力中のセル以外になった場合は、
		『連続入力モード』->『列車編集モード』
		に遷移します。
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
		処理はありません
	
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

#endif /*CWjkState_Renzoku_h*/
