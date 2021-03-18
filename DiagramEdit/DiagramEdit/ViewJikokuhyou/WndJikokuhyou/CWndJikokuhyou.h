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
//	CWndJikokuhyou.h
//	$Id: CWndJikokuhyou.h 368 2016-08-19 11:11:10Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWndJikokuhyou_CWndJikokuhyou_h
#define  CWndJikokuhyou_CWndJikokuhyou_h

#include "NsOu/Ou.h"
#include "NsMu/CMup_vector.h"
#include "NsMu/CaMuCast.h"
#include "DcdGrid/WndDcdGrid3/WndDcdGrid3.h"
#include "CJikokuhyouDoc.h"
#include "..\..\DedRosenFileData\EditCmd\CRfEditCmd_Ressya.h"
#include "..\..\entDed\CentDedRosen.h"
#include "..\..\entDed\CentDedRessya_EkijikokuModifyOperation2.h"
#include "ViewJikokuhyou\WndJikokuhyou\CWjkStateMachine.h"
#include "ViewJikokuhyou\JikokuhyouColSpec\JikokuhyouColSpec.h"

namespace ViewJikokuhyou{ 
namespace WndJikokuhyou{
	
	using namespace DcDrawLib::DcdGrid::WndDcdGrid3;
	using namespace JikokuhyouColSpec;

// ****************************************************************
//	CWndJikokuhyou
// ****************************************************************
/**
@brief
【概要】 CJikokuhyouView で用いる、グリッドウインドウです。

@note
　このウインドウ(WndDcdGrid3)で、WM_IME_STARTCOMPOSITION を処理すると、
問題が発生します。
　IMEをONにした状態で文字キーを押して『列車のプロパティ』ダイアログを
開いたときに、変換候補文字列がダイアログのコントロールに表示されません。
　なお、『駅時刻のプロパティ』ダイアログでは、変換候補文字列がコントロールに
 表示されません。これは、理由は不明です。

 */
class CWndJikokuhyou : public CWndDcdGrid
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	typedef CWndDcdGrid super ;

	friend class CWjkState ;
	friend class CWjkState_Ressyahensyu ;	
		//OnUpdate_setRessya,OnUpdate_All,OnUpdate_setAllRessyaBorder
	friend class CWjkState_Renzoku ;
		//OnUpdate_setRessya,OnUpdate_All,OnUpdate_setAllRessyaBorder

	/** 時刻表ビューのモードを表す列挙です。 */
	enum EStateIdx 
	{
		StateIdx_Ressyahensyu = 0 ,	///< 列車編集モード
		StateIdx_Renzoku ,			///< 連続入力モード
	};

	/** 時刻表ビューの駅時刻での「並べ替え」のモードを表す列挙です。 */
	enum EEkijikokuSort 
	{
		EEkijikokuSort_Ekiatsukai = 0 ,	///< 駅扱でのソート
		EEkijikokuSort_Transfer ,	///< 乗継ソート
	};

	/** 
		createCmd() メソッドで生成するコマンドオブジェクトの種類を指定します。
	*/
	enum ECreateCmd
	{
		/**
		　フォーカス位置に新規列車を挿入するためのコマンドを生成します。

		　時刻表ビュー上で複数選択がOFF・フォーカスセルが既存列車上にある場合: 
		 
		 - m_iIndexDst = フォーカスセルの列車Index、m_iIndexSize = 0
		 - m_CentDedRessyaCont = 空列車(NULLではない。既定の列車(列車種別Index=0))
		 - CaMuiSelect = 当該列車を選択。

		 　時刻表ビュー上で複数選択がOFF・フォーカスセルが新規列車位置にある場合:

		 - m_iIndexDst = 末尾列車Index+1、m_iIndexSize = 0
		 - m_CentDedRessyaCont = 空列車(NULLではない。既定の列車(列車種別Index=0)列車種別Index=0)
		 - CaMuiSelect = 当該列車を選択。

		 　時刻表ビュー上で複数選択ON:

		 - NULLを返します([14/05/18]旧:複数選択OFFの場合と同じ動作)

		　以下のメニューコマンドで使用します。

		 - 貼り付け・列車のプロパティ(※)・列車を挿入・駅時刻のプロパティ(※) @n
		    ※=フォーカス位置が新規アイテムにある場合のみ
		*/
		ECreateCmd_NewItem  , 

		/**
		　フォーカスセル上の1列車を対象としたコマンドを生成します。

		　時刻表ビュー上で複数選択がOFF・フォーカスセルが既存列車上にある場合: 

		 - m_iIndexDst = フォーカスセルの列車Index、m_iIndexSize = 1
		 - m_CentDedRessyaCont = フォーカスセル上の列車1個のコピー
		 - m_CaMuiSelect = フォーカスセル上の列車を選択。

		　時刻表ビュー上で複数選択がOFF・フォーカスセルが新規列車位置にある場合: 

		 - NULLを返します。

		　時刻表ビュー上で複数選択ON

		 - NULLを返します([14/05/18]旧:複数選択OFFの場合と同じ動作)

		　以下のメニューコマンドで使用します。

		  - 時刻のみ貼り付け・連続入力・直通化・分断 @n
		  - 連続入力モードでの 時刻入力,[時刻削除],[通過],[通過-停車],[経由なし]
		  
		*/
		ECreateCmd_Focus , 

		/**
		　既存の単数または複数選択されている列車を対象とした
		コマンドを生成します。

		　時刻表ビュー上で複数選択がOFF・フォーカスセルが既存列車上にある場合: 

		 - m_iIndexDst = フォーカスセルの列車Index、m_iIndexSize = 1
		 - m_CentDedRessyaCont = フォーカスセルのある列車1個のコピー
		 - CaMuiSelect = 当該列車を選択。

		　時刻表ビュー上で複数選択がOFF・フォーカスセルが新規列車位置にある場合: 

		 - NULLを返します。

		　時刻表ビュー上で複数選択ON

		 - m_iIndexDst = 選択されている列車の先頭index
		 - m_iIndexSize = 選択されている列車の末尾index-先頭index+1
		 - m_CentDedRessyaCont = 選択されている列車の先頭indexから
		  末尾indexまでの列車のコピー
		 - CaMuiSelect は、セル選択に合わせて列車を選択。
		
		　以下のメニューコマンドで使用します。

		 - 切り取り・コピー・消去・
		  時刻消去・通過・通過-停車・経由なし・当駅始発・当駅止まり・分断
		  駅時刻の挿入・駅時刻を削除・駅時刻変更・駅時刻変更の再実行・
		  連続1分修正
		  - 列車のプロパティ(※)・駅時刻のプロパティ(※)
		    ※=フォーカス位置が既存アイテムにある場合のみ

		*/
		ECreateCmd_Select , 

		/**
		　全列車を対象としたコマンドを生成します。

		  時刻表ビュー上で複数選択がOFF・フォーカスセルが列車上にある場合: 
		
		 - m_iIndexDst = 0、m_iIndexSize = 列車の数
		 - m_CentDedRessyaCont = 全列車のコピー
		 - m_CaMuiSelect2 は、全列車を選択。

		  時刻表ビュー上で複数選択がOFF・フォーカスセルが新規列車位置にある場合: 
		 
		 - m_iIndexDst = 0、m_iIndexSize = 列車の数
		 - m_CentDedRessyaCont = 全列車のコピー
		 - CaMuiSelect2 は、全列車を選択。

		  時刻表ビュー上で複数選択ON
		
		 - m_iIndexDst = 選択されている列車の先頭index
		 - m_iIndexSize = 選択されている列車の末尾index-先頭index+1
		 - m_CentDedRessyaCont = 選択されている列車の先頭indexから
			末尾indexまでの列車のコピー
		 - m_CaMuiSelect2 は、セルの選択に合わせて列車を選択。

		  以下のメニューコマンドで使用します。
			
		 - 最小所要時間列車に移動・並べ替え・列車番号で一本化
		*/
		ECreateCmd_All ,
	};

private:
	// ********************************
	///@name	集約
	// ********************************
	///@{
	/**
		『状態』オブジェクトへのポインタを保持するコンテナです。
		カレント状態を保持し、状態遷移時の入場・退場動作の呼び出しも行います。
	*/
	CWjkStateMachine	m_StateMachine ;
	///@}

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		貼り付け移動量(秒)です。
	
		初期値は 0 です。
		コマンド ID_Jikokuhyou_ViewProp -> CDlgJikokuhyouViewProp 
		によって設定できます。
	 */
	CdDedJikan m_jikanPasteIdouryou ;
	/**
		通過駅の駅時刻を表示するか否かの指定です。
	
		- true ; 通過駅の駅時刻を表示します。(default)
		- false ; 通過駅の駅時刻を表示せずに、通過マーク "ﾚ" を表示します。
	 */
	bool m_bDisplayTsuukaEkiJikoku ;

	/**
		全駅の駅時刻を表示するか否かの指定

		-true ; 駅の駅時刻形式(CentDedEki::m_eEkijikokukeisiki )とは無関係に、
			時刻表ビューに全駅の着発時刻を表示します。
		-false ; (default)
	*/
	bool m_bDisplayAllEkiJikoku ;

	/** 
		時刻表ビューの駅時刻での「並べ替え」のモード。 
		既定は、駅扱でのソートです。
		最初の OnUpdate() で、 .ini ファイルから読み込みます。
	 */
	EEkijikokuSort	m_eEkijikokuSort ;

	/**
		繰上げ・繰り下げの有効・無効を示します。
		
		既定は、有効です。
		最初の OnUpdate() で、 .ini ファイルから読み込みます。
	 */
	bool	m_bModifyEkijikoku ;

	/**
		『駅時刻変更』の操作の内容を保持します。
		
		set... メソッドで変更できます。
	*/
	CentDedRessya_EkijikokuModifyOperation2	m_EkijikokuModifyOperation2 ;
	///@}
private:
	// --------------------------------
	///@name	内部データ
	// --------------------------------
	///@{
	/**
	 	直前のペースト操作で、クリップボードの列車に適用される移動分です。
	 
	 	初期値は 0 です。
	 	このビューで列車のコピー・切り取りの動作を行った
	 	（クリップボードへの列車の格納を行った）ときに、
		0 になります。
	 	その後の『列車の貼り付け』を行ったときには、
	 	クリップボード内の列車の各駅の時刻に
	 
	 	(m_jikanPasteIdouryou + m_jikanPasteIdouryouPrevValue )
	 
	 	の値を貼り付けて、その後
	 
	 	 m_jikanPasteIdouryouPrevValue += m_jikanPasteIdouryou 
	 
	 	とします。
	 */
	CdDedJikan m_jikanPasteIdouryouPrevValue ;

	/**
	 	この変数が true のときは、
	 	あらゆるビューの更新を、次にビューがアクティブ化されるまで
	 	保留していることを示します。

		初期値は true です。これは、最初の画面の更新は必ず
		OnUpdate_All() で行う必要があるためです。

		通常は false です。
	 	「このビューがアクティブでないときの全更新
		( OnUpdate_All() ）」から、
	 	「ビューがアクティブになるまでの間」だけ true になります。

		この変数が true のときは、
		「ビューがアクティブな状態での OnUpdate_All() 」
		まで、あらゆる更新操作は行われません。
		この場合は、 OnUpdateの下請関数( OnUpdate_SetYColumn() , 
		OnUpdate_setRessya() ,OnUpdate_setAllRessyaBorder() など) 
		は、何も行わずにreturn します。

	 	この値が true のときに、ビューがアクティブ化されたら、
	 	OnUpdate_All() を実行します。
	 
	 */
	bool m_bUpdate_All_Requested ;

	/**
		初期状態は false 。
		初回の OnUpdate() で、　.ini ファイルから
		表示に関する設定を読み込んだら true に変わります。
	*/
	bool m_bReadCWndJikokuhyouDefault ;

	///@}

protected:
	// --------------------------------
	///@name 下請関数
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
	  @attention
	 	この関数を OnCreate() ・及びそれ以前に
	 	呼び出したときは、戻り値はNULLになります。
	 	呼び出し時期に注意してください。
	 */
	const CentDedDia*	getCentDedDia();
	

	/**
	  @return
	 	CentDedRessyaCont オブジェクトを返します。
	  @attention
	 	この関数を OnCreate() ・及びそれ以前に
	 	呼び出したときは、戻り値はNULLになります。
	 	呼び出し時期に注意してください。
	 */
	const CentDedRessyaCont*	getCentDedRessyaCont() ;


	bool getUpdate_All_Requested()const{	return m_bUpdate_All_Requested ;};

	///@}

	// --------------------------------
	///@name updateUI...() ・セルの更新
	///@note CWjkState 派生クラスからも利用します。
	// --------------------------------
	///@{
	/**
	 	関連するドキュメント CJikokuhyouDoc の内容を、このウインドウに完全に
	 	反映します。
	 	このとき、ウインドウの更新再描画も発生します。
	 */
	virtual void  updateUIAll() ;

	/**
	 	関連するドキュメント CJikokuhyouDoc の内容に従って、列車情報の列を更新します。

		Y列の数・左側の項目名列は更新しません。		

	 	- 1. 列車の数に従って、X列数を設定します。
	 	- 2. すべての列車を設定します。
	 	- 3. 各列車の右側の罫線を設定します。
	 */
	virtual void  updateUISetAllRessya() ;
	/**
	セル内の列車を置き換えます。

	Y列の数・左側の項目名列は更新しません。		

	@param iDstRessyaIndex [in]
		　削除・追加対象となる列車の列車Indexを指定してください。
	@param iDstDelCount [in] 
		　削除される(置換によって失われる)列車の数を指定してください。
	@param iInsertCount [in]
		　追加される(置換によって新たに生成･変更された)列車の数を指定してください。
	*/
	void updateUI_ReplaceRessya( 
		int iDstRessyaIndex , 
		int iDstDelCount , 
		int iInsertCount ) ;

	///@}
protected:
	// --------------------------------
	///@name MFCコマンドハンドラ下請関数
	// --------------------------------
	///@{
	/** [ファイル]-[時刻表CSVファイル]-[CSVへエクスポート]
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
				エラーが発生した場合は、エラーメッセージボックスを表示します。
	@return
		0以上は成功、負の数はエラーです。
	*/
	int OnFileExportJikokuhyoucsv_Process( BOOL bQueryEnable ) ;
	
	/** [ファイル]-[時刻表CSVファイル]-[CSVからインポート]
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
				エラーが発生した場合は、エラーメッセージボックスを表示します。
	@return
		0以上は成功、負の数はエラーです。
		-	-1  ;	//	セルの場所が不正
		-	-2 ;	//	Cancelされました。
		-	-11 ;	//	ファイルが見つかりません。
		-	-12 ;	//	CSVの解釈に失敗しました。
		-	-101 ; // 行が少なすぎます。
		-	-102 ; // 列が少なすぎます。
		-	-103 ; // ファイル形式が認識できません
		-	-104 ; // ファイル形式が認識できません
		-	-111 ; // 駅名が見つかりません。
		-	-121 ; // iDiaIndex が不正です。
		-	-122 ; // iRessyaIndex が不正です。 
	*/
	int OnFileImportJikokuhyoucsv_Process( BOOL bQueryEnable ) ; 

	/** [時刻表]-[時刻表ビューのプロパティ]
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
				 エラーが発生した場合は、エラーメッセージボックスを表示します。
	@return
		0以上は成功、エラーなら負の数です。
		-	1 ;	//	ダイアログボックスでの入力が適用されました。
		-	0 ;	//	ダイアログボックスでの入力がキャンセルされました。
	*/
	int OnJikokuhyouViewProp_Process( BOOL bQueryEnable ) ;

	/** [駅時刻]-[ダイヤグラムへ移動]
	@param bQueryEnable [in]
		- TRUE ;	コマンドが現在実行できるか否かの判定だけを行います。@n
					エラーメッセージの表示は行いません。
		- FALSE ;	コマンドを実行します。 @n
				エラーが発生した場合は、エラーメッセージボックスを表示します。
	@return
		0以上は成功、エラーなら負の数です。
		-	-11  ;	//	セルの場所が不正
		-	-2 ;	//	ダイヤグラムビューのオープンに失敗しました
		-	-3 ;	//	ダイヤグラムビューのオープンに失敗しました
	*/
	int OnJikokuhyouDiagramHeIdou_Process( BOOL bQueryEnable ) ; 

	/** [表示]-[通過駅の駅時刻を表示] 
	@return
		0以上は成功、エラーなら負の数です。
		-	1 	(bQueryEnable==TRUEの場合)[全時刻を表示]が有効です。
		-	0 	(bQueryEnable==TRUEの場合)[全時刻を表示]が無効です。
	*/
	int OnVIEWDisplayTsuukaEkiJikoku_Process( BOOL bQueryEnable ) ; 

	/** [表示]-[全時刻を表示] 
	@return
		0以上は成功、エラーなら負の数です。
		-	1 	(bQueryEnable==TRUEの場合)[全時刻を表示]が有効です。
		-	0 	(bQueryEnable==TRUEの場合)[全時刻を表示]が無効です。
	*/
	int OnViewDisplayallekijikoku_Process( BOOL bQueryEnable ) ; 

	/** 貼り付け移動ステータスバー
	@return
		ステータスバーテキストを返します。
		連続入力モードなら、『連続入力モード』を返します。
		それ以外なら、貼り付け移動量の文字列を返します。
	*/
	CString OnUpdateINDICATOR_PasteZoubun_Process() ; 

	///@}

	// ********************************
	//	CDcdGrid
	// ********************************
protected:
	// --------------------------------
	///@name CDcdGrid-行・列・セルの初期化
	// --------------------------------
	///@{
	/**
	 this は、新しい Column が生成された直後に、この関数を呼び出します。
	新しい Column に対して、 IfDcDraw インターフェースオブジェクト
	の生成・登録をはじめとした
	初期化を行います。

	 この関数をオーバライドすることにより、 Column に特有の初期化を
	行うことができます。
	 	
	  @param iXColumnNumber [in]
	 	  新しい Column の列番号です。
	  @param pCDcdGridXColumn [in,out]
	 	  新しく生成された CDcdGridXColumn オブジェクトです。
	 	  この関数はこのオブジェクトに対して、初期化を行うことができます。
	 	
	  [オーバライド]
	 	新しい列・行のサイズ自動計算を禁止します(描画高速化のため)
	 */
	virtual void OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) ;
	
	/**
	　this は、新しい Column が生成された直後に、この関数を呼び出します。
	新しい Column に対して、 IfDcDraw インターフェースオブジェクト
	の生成・登録をはじめとした
	初期化を行います。

	　この関数をオーバライドすることにより、 Column に特有の初期化を
	行うことができます。

	  @param iYColumnNumber [in]
	 	  新しい Column の列番号です。
	  @param pCDcdGridYColumn [in,out]
	 	  新しく生成された CDcdGridYColumn オブジェクトです。
	 	  この関数はこのオブジェクトに対して、初期化を行うことができます。
	 	
	 	
	  [オーバライド]
	 	新しい列・行のサイズ自動計算を禁止します(描画高速化のため)
	 */
	virtual void OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;
	
	///@}
	// ********************************
	//	CWndDcdGrid2
	// ********************************
protected:
	// --------------------------------
	///@name CWndDcdGrid2-イベント処理のための仮想関数
	// --------------------------------
	///@{
	/**
	 this は、フォーカスセルが移動したときに、この仮想関数を呼び出します。
	クラスユーザーは、この仮想関数をオーバライドして、必要な処理を
	実装できます。

	this は、クラスユーザーが setFocusCell() でフォーカスセルを移動した
	ときのほか、キーボードでフォーカスセルを移動したとき・スクロールバーで
	ウインドウをスクロールした結果フォーカスセルが移動したとき・
	ウインドウサイズが変化した結果フォーカスセルが移動したときにも、
	この仮想関数を呼び出します。

	[オーバライド]
	 CWjkState に委譲します。
	  
	   @param pCDcdGridCell [in]
	  	新しいフォーカスセルです。
	 */
	virtual void OnSetFocusCell( CDcdGridCell* pCDcdGridCell ) ;

	/**
	 this は、FixafterColumnNumber が変化したとき
	（スクロール位置が変化したとき）に、この仮想関数を呼び出します。
	クラスユーザーは、この仮想関数をオーバライドして、必要な処理を
	実装できます。

	 this は、クラスユーザーが 
	setXFixafterColumnNumber() で値を設定したときのほか、
	キーボードでフォーカスセルを移動した結果スクロールが発生したとき・
	スクロールバーでウインドウをスクロールしたときにも
	この仮想関数を呼び出します。

	[オーバライド]
	　CWjkState に委譲します。
	  
	   @param iFixafterColumnNumber [in]
	  	新しい FixafterColumnNumber です。
	 */
	virtual void OnSetXFixafterColumnNumber( int iFixafterColumnNumber ) ;

	/**
	 this は、FixafterColumnNumber が変化したとき
	（スクロール位置が変化したとき）に、この仮想関数を呼び出します。
	クラスユーザーは、この仮想関数をオーバライドして、必要な処理を
	実装できます。

	　this は、クラスユーザーが 
	setYFixafterColumnNumber() で値を設定したときのほか、
	キーボードでフォーカスセルを移動した結果スクロールが発生したとき・
	スクロールバーでウインドウをスクロールしたときにも
	この仮想関数を呼び出します。

	[オーバライド]
	　CWjkState に委譲します。
	  
	   @param iFixafterColumnNumber [in]
	  	新しい FixafterColumnNumber です。
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
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CWndJikokuhyou();
	virtual ~CWndJikokuhyou();

public:
	// ********************************
	///@name	CWndJikokuhyou-包含/集約
	// ********************************
	///@{
	CWjkStateMachine* getStateMachine()
	{
		return &m_StateMachine ;
	}
	///@}
public:
	// ********************************
	///@name CWndJikokuhyou-属性
	// ********************************
	///@{


	int getPasteIdouryou()const{ return m_jikanPasteIdouryou ;};

	bool getDisplayTsuukaEkiJikoku()const ;
	/**
	 @return
		- 1 ;	設定を変更して、ウインドウを再描画しました。
		- 0 ;	表示内容は変化しませんでした。
	*/
	int setDisplayTsuukaEkiJikoku( bool value ) ;

	bool getDisplayAllEkiJikoku()const;
	/**
	 @return
		- 1 ;	設定を変更して、ウインドウを再描画しました。
		- 0 ;	表示内容は変化しませんでした。
	*/
	int setDisplayAllEkiJikoku( bool value );

	EEkijikokuSort	getEkijikokuSort()const{	return m_eEkijikokuSort ;};
	void setEkijikokuSort( EEkijikokuSort eEkijikokuSort ){	m_eEkijikokuSort = eEkijikokuSort ;};

	bool getModifyEkijikoku()const{	return m_bModifyEkijikoku ;};
	void setModifyEkijikoku( bool value );

	CentDedRessya_EkijikokuModifyOperation2 getEkijikokuModifyOperation2()const
	{	return m_EkijikokuModifyOperation2 ;}
	void setEkijikokuModifyOperation2( const CentDedRessya_EkijikokuModifyOperation2& value )
	{	m_EkijikokuModifyOperation2 = value ;};

	///@}
public:
	// ********************************
	///@name CJikokuhyouView からの委譲
	// ********************************
	///@{
	/**
	  	親ウインドウの CJikokuhyouView は、OnUpdate() を
	  	このメソッドに委譲してください。
	 */
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	/**
	  	親ウインドウの CJikokuhyouView OnActivateView() を
	  	このメソッドに委譲してください。
	 */
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) ;
	///@}

public:
	// ********************************
	///@name static CWndJikokuhyou-操作
	// ********************************
	///@{
	/**
	 CdYColSpec(Y列の表示内容) を
	CdDedJikokuOrder(駅時刻の要素を特定する値) に変換します。
	@param aYColSpec [in]
		Y列の表示内容を指定してください。
	@return 
		CdDedJikokuOrder(駅時刻の要素を特定する値)を返します。
		aYColSpec が駅時刻でない場合は、NULLを返します。
	*/
	static CdDedJikokuOrder CdDedJikokuOrderOf( 
		const CdYColSpec& aYColSpec ) ;

	/**
	 CdDedJikokuOrder(駅時刻の要素を特定する値) を
	CdYColSpec(Y列の表示内容) 
	に変換します。
	@param aJikokuOrder [in]
		CdDedJikokuOrder(駅時刻の要素を特定する値) を指定してください。
	@return 
		CdYColSpec(Y列の表示内容) を返します。
		aJikokuOrder が正しくない場合は、NULLを返します。
	*/
	static CdYColSpec CdYColSpecOf( 
		const CdDedJikokuOrder& aJikokuOrder ) ;
	///@}
public:
	// ********************************
	///@name CWndJikokuhyou-操作
	// ********************************
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
		この対応表は、 CentDedRessyaCont・CentDedRessya に変更が発生
		したら無効になります。このため、CentDedRessyaCont・CentDedRessya  に
		変更の可能性がある状況では、対応表を再作成する必要があります。	
	*/
	CdXColSpecCont createXColSpecCont() ;


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
		この対応表は、 CentDedEkiCont・CentDedEki に変更が発生
		したら無効になります。このため、 CentDedEkiCont・CentDedEki に変更の
		可能性がある状況では、対応表を再作成する必要があります。	
	*/
	CdYColSpecCont createYColSpecCont() ;

	/**
	@return 
		フォーカスセルの列の表示内容を返します。
	*/
	CdXColSpec getXColSpecOfFocus() ;
	
	/**
	@return 
		フォーカスセルの列の表示内容を返します。
	*/
	CdYColSpec getYColSpecOfFocus() ;
	
	/**
	フォーカスセル移動モード bJikokuhyouFocusToRight に従い、
	フォーカスセルを、次の位置に移動します。
	@param bJikokuhyouFocusToRight [in]
		- false ;	//	フォーカス下移動モード 
		- true ;	//	フォーカス右移動モード
	 @param bNextEkiOrder [in]
		m_bJikokuhyouFocusMoveRight が偽で、現在のフォーカスセルが、
		発着表示の駅時刻の着時刻にある場合の、フォーカスの移動先を
		指定します。
		- true ;	//	フォーカスセルを次の駅Orderに移動します。
		- false ;	//	フォーカスセルを同じ駅の発時刻に移動します。
	 @return 
		成功したら 0 以上、エラーなら負の数です。
	*/
	virtual int moveFocusCellToNext( 
		bool bJikokuhyouFocusToRight , 
		bool bNextEkiOrder ) ;
	
	/**
	フォーカスセル移動モード bJikokuhyouFocusToRight に従い、
	フォーカスセルを、前の位置に移動します。
	@param bJikokuhyouFocusToRight [in]
		- false ;	//	フォーカス下移動モード 
		- true ;	//	フォーカス右移動モード
	@param bNextEkiOrder [in]
		m_bJikokuhyouFocusMoveRight が偽で、現在のフォーカスセルが、
		発着表示の駅時刻の発時刻にある場合の、フォーカスの移動先を
		指定します。
		- true ;	//	フォーカスセルを前の駅Orderに移動します。
		- false ;	//	フォーカスセルを同じ駅の着時刻に移動します。
	 @return 
		成功したら 0 以上、エラーなら負の数です。
	*/
	virtual int moveFocusCellToPrev( 
		bool bJikokuhyouFocusToRight , 
		bool bNextEkiOrder ) ;



	/**
	EditCmd::CRfEditCmd_Ressya オブジェクト内の、選択されたすべての
	列車に対して、 m_CdModifyEkijikokuCmd
	の内容を実行します。

	@param pCmd [in]
		コマンドを適用する列車を格納し、選択したオブジェクトを指定してください。
	@param aCdJikokuOrder [in]
		コマンドを適用する時刻Orderを指定してください。
	@return 
		成功したら 0 以上、エラーなら負の数です。
		-	1 ;	//	列車の追加・またはプロパティの変更を行いました。
		-	-1 ;	//	X列番号が不正です。

		エラーが発生した場合は、フォーカスをエラーの発生した列車に移動します。
		エラーがない場合は、フォーカスは移動しません。
	*/
	int execCdModifyEkijikokuCmd(
		Ou<EditCmd::CRfEditCmd_Ressya> pCmd ,
		CdDedJikokuOrder aCdJikokuOrder ) ;




	/**
	DcdGridでの選択内容に応じた、編集コマンドオブジェクト
	(CRfEditCmd_Ressya)を生成します。
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
	bool createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>* ppCmd );

	/**
	選択範囲の列車を保持する、編集コマンドオブジェクト
	(CRfEditCmd_Ressya)を生成します。
	@param iRessyaIndex [in]
		先頭の列車Index を指定してください。
	@param iRessyaCount [in]
		列車の数を指定してください。
	@param ppCmd [out] 
		生成したコマンドを返します。
		NULL を指定することもできます。この場合、この関数は
		コマンドを生成せずに、コマンドの生成が可能か否かだけを返します。
	@return
		ppCmdが有効なOuである場合は、コマンドの生成に成功したら trueを返します。
		ppCmd=NULL の場合は、コマンドの生成が可能であればtrueを返します。
		コマンドが生成できない場合は false を返します。

		生成されるオブジェクトは、以下の属性になります。
		- m_iIndexDst = 選択されている列車の先頭index
		- m_iIndexSize = iRessyaCount
		- m_CentDedRessyaCont = iRessyaIndexからiRessyaCount までの
			列車のコピー
		- m_CaMuiSelect は、全列車を選択。

	@note
	  以下のメニューコマンドで使用します。
		直通化(直通化対象となる列車Indexまでのコマンドオブジェクトを生成し、
		コマンドを追加します。)
	*/
	bool createCmd( int iRessyaIndex , int iRessyaCount , 
		Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>* ppCmd) ;


	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// アトリビュート
public:

// オペレーション
public:
	//{{AFX_VIRTUAL(CWndJikokuhyou)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CWndJikokuhyou)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnJikokuhyouRessyaProp();
	afx_msg void OnUpdateJikokuhyouRessyaProp(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouRessyaInsert();
	afx_msg void OnUpdateJikokuhyouRessyaInsert(CCmdUI* pCmdUI);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditPasteEkiJikoku();
	afx_msg void OnUpdateEditPasteEkiJikoku(CCmdUI* pCmdUI);
	afx_msg void OnEditSelectAll();
	afx_msg void OnUpdateEditSelectAll(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouTsuuka();
	afx_msg void OnUpdateJikokuhyouTsuuka(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouKeiyunasi();
	afx_msg void OnUpdateJikokuhyouKeiyunasi(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouSihatsu();
	afx_msg void OnUpdateJikokuhyouSihatsu(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouSyuuchaku();
	afx_msg void OnUpdateJikokuhyouSyuuchaku(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouRenzoku();
	afx_msg void OnUpdateJikokuhyouRenzoku(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouViewProp();
	afx_msg void OnJikokuhyouFocusMoveDown();
	afx_msg void OnUpdateJikokuhyouFocusMoveDown(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouFocusMoveRight();
	afx_msg void OnUpdateJikokuhyouFocusMoveRight(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuProp();
	afx_msg void OnUpdateJikokuhyouEkijikokuProp(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuInsert();
	afx_msg void OnUpdateJikokuhyouEkijikokuInsert(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuErase();
	afx_msg void OnUpdateJikokuhyouEkijikokuErase(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouModifyEkijikokuCmd();
	afx_msg void OnUpdateJikokuhyouModifyEkijikokuCmd(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouModifyEkijikokuCmdRepeat();
	afx_msg void OnUpdateJikokuhyouModifyEkijikokuCmdRepeat(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouJikokuSakujo();
	afx_msg void OnUpdateJikokuhyouJikokuSakujo(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuDec();
	afx_msg void OnUpdateJikokuhyouEkijikokuDec(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuNext();
	afx_msg void OnUpdateJikokuhyouEkijikokuNext(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuInc();
	afx_msg void OnUpdateJikokuhyouEkijikokuInc(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEKikanSaisyouSec();
	afx_msg void OnUpdateJikokuhyouEKikanSaisyouSec(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouSort();
	afx_msg void OnUpdateJikokuhyouSort(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouDiagramHeIdou();
	afx_msg void OnUpdateJikokuhyouDiagramHeIdou(CCmdUI* pCmdUI);
	afx_msg void OnVIEWDisplayTsuukaEkiJikoku();
	afx_msg void OnUpdateVIEWDisplayTsuukaEkiJikoku(CCmdUI* pCmdUI);
	afx_msg void OnFileExportJikokuhyoucsv();
	afx_msg void OnFileImportJikokuhyoucsv();
	afx_msg void OnJikokuhyouEkijikokudecnomove();
	afx_msg void OnUpdateJikokuhyouEkijikokudecnomove(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuincnomove();
	afx_msg void OnUpdateJikokuhyouEkijikokuincnomove(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuPrev();
	afx_msg void OnUpdateJikokuhyouEkijikokuPrev(CCmdUI *pCmdUI);
	afx_msg void OnUpdateINDICATOR_PasteZoubun(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouTsuukateisya();
	afx_msg void OnUpdateJikokuhyouTsuukateisya(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouDirect();
	afx_msg void OnUpdateJikokuhyouDirect(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouUndirect();
	afx_msg void OnUpdateJikokuhyouUndirect(CCmdUI *pCmdUI);
	afx_msg void OnViewDisplayallekijikoku();
	afx_msg void OnUpdateViewDisplayallekijikoku(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouUnify();
	afx_msg void OnUpdateJikokuhyouUnify(CCmdUI *pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

} // namespace WndJikokuhyou 
} // namespace ViewJikokuhyou

#endif /*CWndJikokuhyou_CWndJikokuhyou_h*/
