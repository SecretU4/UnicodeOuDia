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
//	CKeyinputSenderToModalDlg.h
// ****************************************************************
*/
/** @file */
#ifndef  CKeyinputSenderToModalDlg_h
#define  CKeyinputSenderToModalDlg_h

#include <windows.h>
#include <deque>

namespace OuMfc{
namespace OuDlg{

// ****************************************************************
//	CKeyinputSenderToModalDlg
// ****************************************************************
/**
 @brief
 【概要】  親ウインドウへのキー入力を契機に ModalDialog を開く場合、
 モーダルダイアログの特定のエディットコントロールに、
 キー入力メッセージ（ WM_KEYDOWN , WM_KEYUP ）を転送します。
 
   このクラスを使うと、メインウインドウで文字キーを押したときに
	モーダルダイアログを起動すると同時に、そのダイアログのコントロールに、
	押された文字を設定することができます。
	  たとえば、
 
 -# 親ウインドウ上で "A" と入力すると、
 -# モーダルダイアログボックスが開き、
 -# モーダルダイアログ上の、特定のエディットコントロールにフォーカスが
 設定され、
 -# そのエディットコントロールに "A" が入力されている
 
 ということができます。
 
   このクラスでは、上記の例の
 
 - 親ウインドウを『転送元親ウインドウ』
 - モーダルダイアログを『転送先ダイアログ』
 - モーダルダイアログ上のエディットコンロトールを『転送先コントロール』
 
 と呼称します。
 
 <H4>
 【このクラスの状態】
 </H4>

   このクラスのオブジェクトは、以下のような状態を持ちます。
 
 <H5>
 １．非転送状態
 </H5>
 
   通常の状態です。『転送元ウインドウ』は、
  WM_KEYDOWN ・ WM_KEYUP を、自分自身で処理します。
   『転送元ウインドウ』は、『転送先ダイアログ』を起動する際に、
  CKeyinputSenderToModalDlg オブジェクトの状態を
 『２．転送先コントロール登録待ち』に遷移します。
 
 
 <H5>
 ２．転送中・転送先コントロール登録待ち
 </H5>
 
   『転送元ウインドウ』は、『転送先コントロール』
 （通常は、エディットコントロール）へのメッセージの転送を行っていますが、
 『転送先コントロール』の準備ができていません。このため、転送された
 メッセージは、 CKeyinputSenderToModalDlg に蓄えられています。
 
 
 <H5>
 ３．転送中・転送先コントロール登録済み
 </H5>
 
   『転送元ウインドウ』は、『転送先コントロール』
 （通常は、エディットコントロール）へのメッセージの転送を行っています。
 メッセージは、『転送先コントロール』に到達しています。
 
 
 <H4>
 【使い方】
 </H4>
 
 <H5>
 ◎『転送元ウインドウ』側の準備
 </H5>
 
 １．  『転送元ウインドウ』オブジェクトは、 CKeyinputSenderToModalDlg 
 のオブジェクトを生成し、保持してください。このクラスのオブジェクトは、
 『転送元ウインドウ』が生存している間中は生存させてください。
 
 ２．  『転送元ウインドウ』では、 OnKeyDown() ・ OnKeyUp() 
 をオーバライドしてください。それら関数では、 CKeyinputSenderToModalDlg 
 オブジェクトの CKeyinputSenderToModalDlg::OnKeyDown() ・ 
  CKeyinputSenderToModalDlg::OnKeyUp() ・ 
	への委譲を行ってください。
 
 <H5>
 ◎『転送元ウインドウ』で『転送先ダイアログ』を開くタイミング
 </H5>
	通常、「『転送元ウインドウ』で文字キーを押すことにより
	『転送先ダイアログ』が開き、
	そのキー入力内容が『転送先ダイアログ』のコントロールに反映される」
	という動作になります。『転送元ウインドウ』で文字キーが押されたかどうかの
	判定は、『転送元ウインドウ』の OnKeyDown() で

	CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown()

	を呼び出すことにより判断できます。

 <H5>
 ◎『転送元ウインドウ』から、『転送先ダイアログ』を開く
 </H5>
 
 １．  『転送元ウインドウ』は、『転送先ダイアログ』を開く状況になったら、
  CKeyinputSenderToModalDlg::startSend() を呼び出して、転送を
 開始してください。

   『転送元ウインドウ』の OnKeyDown() で『転送先ダイアログ』を開く場合は、
  CKeyinputSenderToModalDlg::startSend() を呼び出した後で、 
  CKeyinputSenderToModalDlg::OnKeyDown() を呼び出してください。
   この決まりは、 OnKeyUp()  にもあてはまります。
 
 ２．  転送を開始してから、『転送先ダイアログ』を CDialog::DoModal() で
 起動してください。
 
 ３．  CDialog::DoModal() がリターンしたら、 
  CKeyinputSenderToModalDlg::endSend()  を呼び出して、転送を
 終了してください。
 
 
 <H5>
 ◎『転送先ダイアログ』側の処理
 </H5>
 
 １．  『転送先ダイアログ』は、親ウインドウとなる『転送元ウインドウ』が
 保持している CKeyinputSenderToModalDlg オブジェクトに対して、
 メソッド呼出を行う必要があります。このため、『転送先ダイアログ』クラスは、
  CKeyinputSenderToModalDlg ポインタの変数を保持し、コンストラクタで
 初期化するようにしなくてはなりません。
 
 ２．  『転送先ダイアログ』は、OnShowWindow() で、『転送先コントロール』
 にフォーカスを設定してください。これは、 CDialog::GotoDlgCtrl() で
 行います。
   『転送先コントロール』にフォーカスを設定してから、
  CKeyinputSenderToModalDlg::registerCtrl() で、『転送先コントロール』
  を登録してください。これによって、メッセージの転送が始まります。
 
 ３．  『転送先ダイアログ』は、 OnDestroy() で
  CKeyinputSenderToModalDlg::unregisterCtrl() を呼び出し、
 『転送先コントロール』の登録を解除してください。
 
 */
class CKeyinputSenderToModalDlg
{
// ********************************
///@name 関連
// ********************************
 private:
	/**
		初期状態では NULL です。
		登録されている『転送コントロール』がある間は、
		そのコントロールのHWNDとなります。
	 */
	HWND	m_hwndControl ;
	

// --------------------------------
///@name 内部データ
// --------------------------------
 private:
	/**
		初期状態では偽です。
		『転送元ウインドウ』がメッセージ転送中の間だけ真です。
	 */
	bool	m_bIsSend ;

	
	/**
	 @brief
	  CKeyinputSenderToModalDlg で
		転送するメッセージを保持する構造体です。
		PostMessage() 関数の呼出に必要な値を保持します。
	*/
	struct MsgToPost{
		  UINT Msg ;       ///< メッセージ
		  WPARAM wParam ;  ///< メッセージの最初のパラメータ
		  LPARAM lParam ;  ///< メッセージの 2 番目のパラメータ
	};
	/**
		this が「２．転送中・転送先コントロール登録待ち」状態の間は、
		転送先へ転送すべきメッセージを保持します。
		registerControl() によって 『転送先コントロール』が登録されたら、
		this は、ここに保持しているメッセージを送信して、
		このコンテナを空にします。
	
		endSend() で転送が終了した場合は、this はこのコンテナを、
		単に空にします。
	 */
	std::deque< MsgToPost >	m_contmsgToSend ;
	
// ********************************
//	コンストラクタ
// ********************************
 public:
	CKeyinputSenderToModalDlg() ;
	


// ********************************
//	CKeyinputSenderToModalDlg
// ********************************
 public:
	// ********************************
	///@name 『転送元ウインドウ』からの操作
	// ********************************
	///@{
	/**
		  『転送元ウインドウ』は、 OnKeyDown() を必ずオーバライドし、
		このメソッドを呼び出してください。
		引数は、『転送元ウインドウ』の OnKeyDown() で渡されたものを
		指定してください。
	@see CWnd::OnKeyDown()
	@param nChar [in]
		指定されたキーの仮想キー コードを指定します。
	@param nRepCnt [in]
		リピート カウント (ユーザーがキーを押し続けたときに繰り返す
		キー操作の回数) を指定します。
	@param nFlags [in]
		スキャン コード、キー変換コード、直前のキー状態、および
		コンテキスト コードを指定します。
	@return
		この関数がメッセージを転送したら、真です。
		この関数が真を返した場合は、原則として
		『転送元ウインドウ』の基本クラスの処理
		（CWnd::OnKeyDown() ）
		は呼び出さないでください。
	 */
	virtual bool OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags );

	/**
		  『転送元ウインドウ』は、 OnKeyUp() を必ずオーバライドし、
		このメソッドを呼び出してください。
		引数は、『転送元ウインドウ』の OnKeyUp() で渡されたものを
		指定してください。
	@see CWnd::OnKeyUp()
	@param nChar [in]
		指定されたキーの仮想キー コードを指定します。
	@param nRepCnt [in]
		リピート カウント (ユーザーがキーを押し続けたときに繰り返す
		キー操作の回数) を指定します。
	@param nFlags [in]
		スキャン コード、キー変換コード、直前のキー状態、および
		コンテキスト コードを指定します。
	@return
		この関数がメッセージを転送したら、真です。
		この関数が真を返した場合は、原則として 
		『転送元ウインドウ』の基本クラスの処理
		（CWnd::OnKeyUp()  ）
		は呼び出さないでください。

	 */
	virtual bool OnKeyUp( UINT nChar, UINT nRepCnt, UINT nFlags );

	
	/**
		 メッセージ転送を開始します。
		
		 『転送元ウインドウ』は、『転送先ダイアログ』を開く状況になったら、
		 CKeyinputSenderToModalDlg::startSend() を呼び出して、転送を
		開始してください。
	 @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;	//	すでに転送中です。
	*/
	virtual int startSend() ;
	
	/**
		 メッセージ転送中に、メッセージの転送を終了します。
		
		 『転送元ウインドウ』は、『転送先ダイアログ』の
		 CDialog::DoModal() がリターンしたら、
		  CKeyinputSenderToModalDlg::endSend()  を呼び出して、
		転送を終了してください。
	 */
	virtual void endSend() ;
	
	///@}
	// ********************************
	///@name 『転送先ダイアログ』からの操作
	// ********************************
	///@{
	/**
		『転送先ダイアログ』は、『転送先コントロール』にフォーカスを
		設定してから、 CKeyinputSenderToModalDlg::registerCtrl() で、
		『転送先コントロール』 を登録してください。これによって、
		メッセージの転送が始まります。
	  @param hwndControl [in]
		転送先コントロールの HWND を指定してください。
	  @return
		成功したら 0 以上、エラーなら負の数です。
		-	-1 ;
			//	送信中でないか、すでに『転送先コントロール』が
			//	登録済みです
	 */
	virtual int registerCtrl( HWND hwndControl ) ;
	
	/**
		『転送先ダイアログ』は、 OnDestroy() で 
		CKeyinputSenderToModalDlg::unregisterCtrl() を呼び出し、
		『転送先コントロール』の登録を解除してください。
	 */
	virtual void unregisterCtrl() ;
	///@}
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
	 @return
		 メッセージ転送中なら真です。
	 */
	virtual bool isSend() ;
	
	/**
	 @return
		登録されている『転送先コントロール』を返します。
		登録されていないときは、NULLを返します。
	 */
	virtual HWND getControl() ;
	///@}
	// ********************************
	///@name 
	// ********************************
	///@{
	/**
	 @return
		現在押されているキーが、文字キーであれば真です。
		ただし、文字キーが２つ押されている場合は偽となります。
		また、Ctrl,Altが押されている場合も、偽となります。
	 */
	static bool AnyLetterOrDigitKeyIsDown() ;
	///@}
};

} //namespace OuDlg
} //namespace OuMfc

#endif /*CKeyinputSenderToModalDlg_h*/
