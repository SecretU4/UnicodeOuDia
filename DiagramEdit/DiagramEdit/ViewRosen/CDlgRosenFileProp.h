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
#if !defined(AFX_CDLGROSENFILEPROP_H__A77A598D_541C_4EF8_B8EA_587920B81B1E__INCLUDED_)
#define AFX_CDLGROSENFILEPROP_H__A77A598D_541C_4EF8_B8EA_587920B81B1E__INCLUDED_
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgRosenFileProp.h : ヘッダー ファイル
//

#include <string>

#include "..\DedRosenFileData\CdDedDispProp.h"
#include "CDlgRosenFileProp_Rosen.h"
#include "CDlgRosenFileProp_FontColor.h"
#include "CDlgRosenFileProp_Diagram.h"

namespace ViewRosen{

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp ダイアログ

/**
@brief
 	『路線ファイルのプロパティ』ダイアログ。
 	
 	  ダイアログがOKボタンで終了したときは、 getPropEditorData() で、
 	 m_PropEditorData にアクセスし、入力結果を取得してください。
 	  thisは、ダイアログがOKボタン終了したとき、ダイアログへの入力結果を
 	 m_PropEditorData オブジェクトに格納します。
 */
class CDlgRosenFileProp : public CDialog
{
public:
	// ****************************************************************
	//	CPropEditorData
	// ****************************************************************
	/**
	@brief
		『路線ファイルのプロパティ』ダイアログの、
		編集対象データを保持するクラスです。
		
		編集対象データは、このダイアログで編集可能なデータのコピーです。

		このクラスは、以下の責務を持ちます。
		
		-	CDedRosenFileData・もしくはその一部から、編集対象データを生成
		-	編集対象データから、UI表示データを生成
		-	UI表示データをもとに、編集対象データを更新
		-	編集対象データを、CRosenFileData・もしくはその一部に適用します。
		-	編集対象データから、 CEditCmd_ オブジェクトを生成する。

	 	ダイアログボックスは、起動時に、初期表示のUI表示データを、
	 	このオブジェクトから取得します。
	 	また、OKボタンで終了されるときに、
	 	入力結果のUI表示データを、このオブジェクトに格納します。
	*/
	class CPropEditorData
	{
	private:
		// ********************************
		///@name	属性
		// ********************************
		///@{
		/**
		 	路線名。
		 */
		std::string	m_strRosenName ;

		/**
			ダイヤの起点時刻です。
		*/
		CdDedJikoku	m_jikokuKitenJikoku ;
		
		/**
			ダイヤグラムの既定の駅間幅。

			列車設定のない駅間の、ダイヤグラムビュー上での
			縦方向の幅を『ダイヤグラムエンティティY座標』単位(秒)で指定します。
		
			既定値は 60 です。
		*/
		int	m_iDiagramDgrYZahyouKyoriDefault ;
		

		/**
			DiagramEdit の表示に関係するプロパティを保持する
			単純データクラスです。
		*/
		CdDedDispProp	m_CdDedDispProp ;
		///@}
	public:
		// ********************************
		//	コンストラクタ
		// ********************************
		/**
		 @param pCDedRosenFileData [in]
			『路線ファイル』のデータ
		 */
		CPropEditorData( const CDedRosenFileData* pCDedRosenFileData ) ;

	public:
		// ********************************
		///@name UI表示データを取得・設定
		// ********************************
		///@{
		/**
		@return
		 	路線名のUI表示データ
		 */
		std::string	getUIRosenName()const ;
		/**
		@param value [in]
		 	路線名のUI表示データ
		 */
		void setUIRosenName( const std::string& value ) ;

		/**
		@return
			ダイヤの起点時刻のUI表示データ
		*/
		CdDedJikoku	getUIKitenJikoku()const ;
		/**
		@param value [in]
			ダイヤの起点時刻のUI表示データ
		*/
		void setUIKitenJikoku( const CdDedJikoku& value ) ;
		
		/**
		@return
			ダイヤグラムの既定の駅間幅。UI表示データ。
		*/
		int	getUIDiagramDgrYZahyouKyoriDefault()const ;

		/**
		@param value [in]
			ダイヤグラムの既定の駅間幅。UI表示データ。
		*/
		void setUIDiagramDgrYZahyouKyoriDefault( int value ) ;
		

		/**
		@return
			DiagramEdit の表示属性。UI表示データ。
		*/
		CdDedDispProp	getUIDispProp()const ;
		/**
		@return
			DiagramEdit の表示属性。UI表示データ。
		*/
		void setUIDispProp(CdDedDispProp& value ) ;

	public:
		// ********************************
		///@name 編集対象データを適用
		// ********************************
		///@{
		/**
			編集対象データを、路線ファイルデータに適用します。
		@param pApplyTo [in]
			編集対象データの適用先を指定してください。
		*/
		void applyTo( CDedRosenFileData* pApplyTo ) ;
		
		/**
			編集対象データをもとに、
			路線ファイルデータの更新コマンドを生成します。
		*/
		Ou<CRfEditCmd> createEditCmd  ();
		///@}
	};


private:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	///@}
private:
	// ********************************
	///@name	包含
	// ********************************
	///@{
	/**
		編集対象データを保持します。
	*/
	CPropEditorData	m_PropEditorData ;

	/** 『路線』ページ */
	CDlgRosenFileProp_Rosen	m_CDlgRosenFileProp_Rosen ;

	/** 『フォント・色』ページ */
	CDlgRosenFileProp_FontColor	m_CDlgRosenFileProp_FontColor ;

	/** 『ダイヤグラム』ページ */
	CDlgRosenFileProp_Diagram	m_CDlgRosenFileProp_Diagram ;
	///@}

	// --------------------------------
	///@name	CDlgRosenFileProp-下請関数
	// --------------------------------
	///@{
	/**
		タブコントロールの操作に従って、
		子ダイアログの表示・非表示状態を
		更新します。
	*/
	void CDlgRosenFileProp::UpdateChildWindowShow() ;
	///@}
// ********************************
//	CDlgRosenFileProp
// ********************************
 public:
	// ********************************
	///@name	CDlgRosenFileProp-属性
	// ********************************
	///@{
	///@}
	// ********************************
	///@name	CDlgRosenFileProp-包含
	// ********************************
	///@{
	/**
		編集対象データを保持します。
	*/
	CPropEditorData* getPropEditorData() ;
	///@}

// ----------------------------------------------------------------
// コンストラクション
public:
	/**
	 @param pCDedRosenFileData [in]
		『路線ファイル』のデータ
	 @param pParent [in]
		親ウインドウを指定してください。
	 */
	CDlgRosenFileProp(
		const CDedRosenFileData*	pCDedRosenFileData ,
		CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CDlgRosenFileProp)
	enum { IDD = IDD_RosenFileProp };
	CTabCtrl	m_tabMAIN;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CDlgRosenFileProp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CDlgRosenFileProp)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace ViewRosen

#endif // !defined(AFX_CDLGROSENFILEPROP_H__A77A598D_541C_4EF8_B8EA_587920B81B1E__INCLUDED_)
