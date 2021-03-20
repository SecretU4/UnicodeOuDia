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
// ****************************************************************
//	$Id: CRosenViewTreeCtrl.h 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
#ifndef  ViewRosen_CRosenViewTreeCtrl_h
#define  ViewRosen_CRosenViewTreeCtrl_h

#pragma once
#include "TreeCtrl\CTreeCtrlContextMenu.h"

namespace ViewRosen{
	using namespace OuMfc::TreeCtrl;
/**
@brief
	路線ビューのツリーコントロールに、コンテキストメニューを提供します。
*/
class CRosenViewTreeCtrl : public CTreeCtrlContextMenu
{
private:
	/**
		通常はNULL。
		コンテキストメニュー表示中は、そのコンテキストメニューに
		対応したアイテムとなります。
	*/
	HTREEITEM	m_itemContextMenu ;
protected:
	/**
		OnContextMenu() の下請け関数です。

		オーバライドして、アイテムに対応する
		コンテキストメニューの CMenu オブジェクトを生成し、
		CMenu::TrackPopupMenu() でコンテキストメニューを
		起動してください。
	@param pWnd[in]
		ユーザーによってマウスの右ボタンがクリックされた
		ウィンドウのハンドルです。
	@param htItem[in]
		コンテキストメニューに対応したアイテムを指定します。
	@param x [in]
		コンテキストメニューを表示する位置を、Screen座標で指定します。
		この値は、CMenu::TrackPopupMenu()の引数 x に
		渡してください。
	@param y [in]
		コンテキストメニューを表示する位置を、
		Screen座標で指定します。
		この値は、CMenu::TrackPopupMenu()の引数 y に
		渡してください。
	@return
		コンテキストメニューを表示した場合は TRUE を、
		コンテキストメニュー

		
		引数 x , y は、ユーザーがマウスでコンテキストメニューを
		要求したときは、
		この値は、マウスカーソルの位置です。
		ユーザーがキー操作でコンテキストメニューを
		呼び出したときは、アイテム htItem の左下座標です。
	*/
	virtual BOOL OnContextMenu_TrackPopupMenu( 
		CWnd* pWnd, 
		HTREEITEM htItem ,
		int x , int y )  ;
public:
	HTREEITEM	getItemContextMenu(){	return m_itemContextMenu ;}
	// --------------------------------
	DECLARE_DYNAMIC(CRosenViewTreeCtrl)

public:
	CRosenViewTreeCtrl();
	virtual ~CRosenViewTreeCtrl();

protected:
	DECLARE_MESSAGE_MAP()
};

} //namespace ViewRosen
#endif //ViewRosen_CRosenViewTreeCtrl_h

