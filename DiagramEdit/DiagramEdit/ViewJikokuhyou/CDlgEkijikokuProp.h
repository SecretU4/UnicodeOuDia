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
#if !defined(AFX_CDLGEKIJIKOKUPROP_H__F033F2C5_255F_4846_89E1_F38C96E91D17__INCLUDED_)
#define AFX_CDLGEKIJIKOKUPROP_H__F033F2C5_255F_4846_89E1_F38C96E91D17__INCLUDED_/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgEkijikokuProp.h : ヘッダー ファイル
//

#include "..\entDed\CentDedEkiJikoku.h"
#include "OuDlg/CKeyinputSenderToModalDlg.h"
#include "entDed/CdDedJikan.h"
#include "ViewJikokuhyou\CPropEditUI_Ekijikoku.h"

#include "resource.h"

namespace ViewJikokuhyou{
	using namespace OuMfc::OuDlg;

/////////////////////////////////////////////////////////////////////////////
// CDlgEkijikokuProp ダイアログ

/**
  @brief
 	『駅時刻のプロパティ』ダイアログです。
 */
class CDlgEkijikokuProp : public CDialog
{
 private:
	// ================================================================
	//	CDlgEkijikokuProp::CPropEditUiInternal
	// ================================================================
	/**
	@brief 
		時刻表のプロパティ編集を行うクラスです。
	*/
	class CPropEditUiInternal : public CPropEditUi_EkiJikoku
	{
	protected:
		// ================================
		/** @name オーバーライトの必要なメソッド2-UIに依存する処理
			UiData と Ui との間のデータ交換のためのメソッドです。
			このグループのメソッドは、 Ui の環境(Windows,MFCなど)
			に依存する処理だけを実装します。
		*/
		// ================================
		///@{
		/**
			UiDataの内容をUiに反映します。
			
			CPropEditUi2::StartEdit(),CPropEditUi2::OnUiChanged(),
			CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
			から呼び出されます。
			
			クラスユーザーは、この関数をオーバーライドして、
			UiDataのメンバの内容をUiに表示する処理を実装してください。
		@param pUiData [in]
			UiData のオブジェクト。
		*/
		virtual void UiDataToUi( const UIDATA* pUiData ) ;
		
		
		/**
			Uiの入力内容をUiDataに反映します。
			
			CPropEditUi2::OnUiChanged(),
			CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
			から呼び出されます。
			
			クラスユーザーは、この関数をオーバーライドして、
			Ui への変更内容をUiData に反映する処理を実装してください。
		@param pUiData [out]
			UiData のオブジェクト。
		*/
		virtual void UiDataFromUi( UIDATA* pUiData )  ;
		
		/**
			画面上にエラーメッセージを表示します。

			クラスユーザーは、この関数をオーバーライドして、
			エラーメッセージを表示する処理を実装してください。
			
			MFCアプリケーションでは、通常は、メッセージボックスを表示します。
		@param strErrorReason [in]
			エラーの内容を示す文字列
		@param strInfo [in]
			エラーの補助情報を示す文字列。不要であれば、空文字列を
			指定してください。
		*/
		virtual void ShowError( 
			const std::string& strErrorReason ,
			const std::string& strInfo = "" )  ;
		
		/**
			Ui 上の特定のコントロールに、フォーカスを設定します。

			クラスユーザーは、この関数をオーバーライドして、
			指定されたコントロールにフォーカスを設定する処理を実装してください。
			
		@param iOffsetofUiDataMember [in]
			フォーカスを設定する編集項目を指定してください。
			UiData内の対象となるデータメンバの、構造体の先頭アドレスからの
			オフセットを指定してください。

		例:フォーカスを、UiDataのメンバ strNumber を入力するコントロールに設定
			する場合は、以下のようにしてください。
		@code
			SetFocus( offsetof(UIDATA,strNumber ) ) ;
		@endcode
		*/
		virtual void SetFocus( int iOffsetofUiDataMember ) ;
		///@}
	public:
		// ********************************
		//	コンストラクタ
		// ********************************
		/**
		@param bNewItem
			-true: 新規オブジェクトに対する、プロパティの編集
			-false: 既存オブジェクトに対する、プロパティの編集
		@param pTarget [in,out]
		 編集対象。コンストラクタで決まります。
		 列車を格納したコンテナです。
		@param pbModifyHatsujikoku [in,out]
		 時刻の繰上げ・繰り下げのON/OFFを保持する変数へのポインタ。
		@param iEkiOrder [in]
			編集対象の駅時刻の駅Orderです。
		*/
		CPropEditUiInternal( 
			bool bNewItem , 
			Mu<CentDedRessya*>* pTarget , 
			bool* pbModifyHatsujikoku ,
			int iEkiOrder ) ; 

		
	} m_PropEditUiInternal ;
	friend class CPropEditUiInternal ;


	// ********************************
	///@name 関連
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
	CKeyinputSenderToModalDlg*	m_pCKeyinputSenderToModalDlg ;
	///@}


private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	
	
	/**
	 	最初にフォーカスを設定する項目を保持します。
	 	コンストラクタで決まります。
	 	- 0	;	//	駅扱
	 	- 1	;	//	着時刻
	 	- 2	;	//	発時刻
	 
	 	OnShowWindow() でフォーカスを設定します。
	 	フォーカス設定後は、 -1 に変わります。
	 */
	int m_iFocusItem ;

	///@}

// ********************************
//	CDlgEkiProp
// ********************************
 public:
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	///@}

	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------

// コンストラクション
public:
	/** 
	@param pMuRessya[in,out]
		　編集対象の列車へのポインタ。
		　これらの CentDedRessya は、関連が有効な間は
		生存しなくてはなりません。
		　この列車は、updateFromUI() にて更新されます。
	@param bJikokuModify [in,out]
		　編集対象。
		  「時刻の繰上げ・繰り下げ」の有効・無効を示す値。
		　この値は、関連が有効な間は生存しなくてはなりません。
	@param iEkiOrder [in] 
		対象の駅Order。
	@param iFocusItem [in]
		最初にフォーカスを設定する項目を保持します。
		- 0	;	//	駅扱
		- 1	;	//	着時刻
		- 2	;	//	発時刻
	@param pCKeyinputSenderToModalDlg [in]
	   親ウインドウへのキー入力を契機に ModalDialog を開く場合、
	  モーダルダイアログの特定のエディットコントロールに、
	  キー入力メッセージ（ WM_KEYDOWN , WM_KEYUP ）を転送します。
	 	このオブジェクトの破棄の責務は、クラスユーザー（『転送元ウインドウ』）
	 	にあります。
	 	このオブジェクトは、 this より長く生存しなくてはなりません。
	 	不要であれば NULL でもかまいません。
	@param pParent [in]
	 	親ウインドウオブジェクトを指定してください。
	 */
	CDlgEkijikokuProp(
		Mu<CentDedRessya*>* pMuRessya ,
		bool* pbJikokuModify ,
		int iEkiOrder ,
		int iFocusItem ,
		CKeyinputSenderToModalDlg*	pCKeyinputSenderToModalDlg ,
		CWnd* pParent  ) ;

// ダイアログ データ
	//{{AFX_DATA(CDlgEkijikokuProp)
	enum { IDD = IDD_EkijikokuProp };
	int		m_iRADIO_Ekiatsukai;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CDlgEkijikokuProp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CDlgEkijikokuProp)
	virtual BOOL OnInitDialog();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnOK();
	afx_msg void OnRADIOEkiatsukai();
	afx_msg void OnRADIOEkiatsukai2();
	afx_msg void OnRADIOEkiatsukai3();
	afx_msg void OnRADIOEkiatsukai4();
	afx_msg void OnKillfocusEDITChakujikoku();
	afx_msg void OnKillfocusEDITHatsujikoku();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bCHECK_MODIFYHATSUJIKOKU;
public:
	afx_msg void OnBnClickedCheckModifyhatsujikoku();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace ViewJikokuhyou

#endif // !defined(AFX_CDLGEKIJIKOKUPROP_H__F033F2C5_255F_4846_89E1_F38C96E91D17__INCLUDED_)
