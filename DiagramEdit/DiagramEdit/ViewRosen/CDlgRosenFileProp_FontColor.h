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
#if !defined(AFX_CDLGROSENFILEPROP_FONTCOLOR_H__25C7879F_3AA8_41A9_9B19_3A1AFBB4F97E__INCLUDED_)
#define AFX_CDLGROSENFILEPROP_FONTCOLOR_H__25C7879F_3AA8_41A9_9B19_3A1AFBB4F97E__INCLUDED_
// CDlgRosenFileProp_FontColor.h : ヘッダー ファイル
//	$Id: CDlgRosenFileProp_FontColor.h 179 2014-05-05 13:50:33Z okm $
//
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DcDraw/CDcdTextbox.h"
#include "DcDraw/CDcdRectangle.h"
#include "DcDraw/CDcdTextboxV3.h"

namespace ViewRosen{
	using namespace DcDrawLib ;	

class CDlgRosenFileProp ;

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp_FontColor ダイアログ

/**
  @brief
 	『路線ファイルのプロパティ』ダイアログの
 	『フォント・色』ページを実装する、モードレスダイアログです。
*/
class CDlgRosenFileProp_FontColor : public CDialog
{
private:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	/**
	 	フォント。
	 	規定値は、	CdFontProp( 9 ,"ＭＳ ゴシック"  ) 。

		- 0～CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT	時刻表画面フォント
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+0 時刻表画面・縦書きフォント
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+1	ダイヤ画面駅名フォント。
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+2 ダイヤ画面時刻フォント。
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+3 ダイヤ画面列車フォント。
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+4 コメントビューフォント。
	 */
	CdFontProp	m_arFontProp[entDed::CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+5] ;


	/**
	 	ダイヤ画面文字色。
	 	規定値は、黒。

		- 0	ダイヤ画面文字色。
		- 1	ダイヤ画面縦横軸色。
	*/
	COLORREF	m_arColor[2] ;
	///@}

private:
	// --------------------------------
	//	内部データ
	// --------------------------------
	/**
	 	フォントのサンプルを描画する DcDraw オブジェクト
	 	OnInitDialog() で生成・OnDestroy() で破棄します。
	*/
	CDcdTextbox*	m_pdcdrawFont ;

	/**
	 	フォントのサンプルを描画する DcDraw オブジェクト
	 	OnInitDialog() で生成・OnDestroy() で破棄します。
	*/
	DcDraw::CDcdTextboxV3*	m_pdcdrawFontV ;

	/**
	 	色のサンプルを描画する DcDraw オブジェクト
	 	OnInitDialog() で生成・OnDestroy() で破棄します。
	*/
	CDcdRectangle*	m_pdcdrawColor ;
protected:
	// --------------------------------
	//	下請関数
	// --------------------------------
	CDlgRosenFileProp* GetParent() ;
	/**
	 	UIの状態を更新する(例:コントロールの有効・無効、入力値の正規化)
	 */
	virtual void updateUIState() ;

	/**
	@return 
		リストコントロールで縦書きフォントが選択されていたら true です。
	*/
	bool VerticalFontIsChoosed() ;

 public:
	// ********************************
	//	CDlgRosenFileProp_FontColor
	// ********************************
	/**
		編集対象データをUIに反映する 
	*/
	void updateUI() ;

	/**
　　　	UIの現在の入力内容を取得し、編集対象データに反映させる
	@return 
	 	成功したら  0 以上、エラーなら負の数です。

		-	-1 ;	エラーが発生し、メッセージボックスが表示されました。
	*/
	int updatePropEditorData();


// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// コンストラクション
public:
	CDlgRosenFileProp_FontColor(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CDlgRosenFileProp_FontColor)
	enum { IDD = IDD_RosenFileProp_FontColor };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CDlgRosenFileProp_FontColor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CDlgRosenFileProp_FontColor)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeListFont();
	afx_msg void OnSelchangeListColor();
	afx_msg void OnButtonFontChange();
	afx_msg void OnButtonColorChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

} //namespace ViewRosen

#endif // !defined(AFX_CDLGROSENFILEPROP_FONTCOLOR_H__25C7879F_3AA8_41A9_9B19_3A1AFBB4F97E__INCLUDED_)
