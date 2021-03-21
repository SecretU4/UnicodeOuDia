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
//	CDropTargetDoctmpl.h
// ****************************************************************
*/
/** @file */
#ifndef  CDropTargetDoctmpl_h
#define  CDropTargetDoctmpl_h

#include <afxwin.h>
#include <afxole.h>

namespace OuMfc{
namespace Hidemdi{

// ****************************************************************
//	CDropTargetDoctmpl
// ****************************************************************
/** @brief 
* 【概要】
* 	 CF_HDROP 形式で、あらかじめ指定されたDoctemplateに登録されている
* 	拡張子を持つファイルだけのドロップを受け入れます。
*
* 【使い方】
*
* １．	このオブジェクトを、メインフレームウインドウオブジェクトの
* 	メンバ変数として宣言してください。
*
* ２．  メインフレームウインドウの OnCreate() で、このオブジェクトの
* 	Register() メソッドを呼び出して、メインフレームウインドウオブジェクトを
* 	このオブジェクトに登録してください。
*
* ３．  メインフレームウインドウの OnDestroy() で、このオブジェクトの
* 	Revoke() メソッドを呼び出してください。
*
* ４．  アプリケーションクラス（CWinApp派生クラス）の InitInstance() で、
* 	AfxOleInit() を呼び出してください。
*
* 【注意】
* １．  OLEドラッグ＆ドロップをサポートするメインフレームウインドウでは、
* 	DragAcceptFiles() 呼出を行わないでください。また、WS_EX_ACCEPTFILES
* 	属性も指定しないでください。
*/
class CDropTargetDoctmpl : public COleDropTarget
{
// ********************************
//	従属型
// ********************************
 public:
	typedef COleDropTarget	super ;

//--------------------------------
//	データメンバ
//--------------------------------
 private:
	/**
	* 	このドロップターゲットがサポートする拡張子を保持します
	* 	文字列は、".txt" の形式です
	*/
	CStringArray	m_astrExt ;
	
	/**
	*	ﾌｧｲﾙ１つだけのドロップを受け付けます（SDIで使います）
	*	コンストラクタで決まります。
	*/
	BOOL					m_bAcceptSingle ;
	
//--------------------------------
//	下請関数
//--------------------------------
 public:
	/**
	* 	このドロップターゲットに到着したHDROPハンドルから、
	* 	含まれているファイル名を取り出して、CStringArrayに書き込みます。
	* @param hgmemEHdrop [in]
	* 	ドロップターゲットに到着したHDROPハンドルを指定してください。
	* @param pastrFilename [out]
	* 	この関数は、この文字列配列に、ドロップされたﾌｧｲﾙの一覧を
	* 	格納します。
	* 	必要ないならNULLでかまいません。
	* @return
	* 	ﾌｧｲﾙの数を返します
	*/
	static int HdropToFilenames( HDROP pdropgmemEHdrop 
								, CStringArray* pastrFilename ) ;

	/**
	* 	ファイル名を格納したCStringArrayの各要素のうち、
	*	拡張子の不適切なものを除去します。
	* @param astrEExt [in]
	* 	拡張子群を格納した文字列配列を指定してください。
	*	拡張子は、 ".exe"
	* @param pastrFilename [in,out]
	* 	この関数は、この文字列配列に格納されているファイル名から、
	* 	拡張子の不適切な要素を削除します
	* 	NULLを指定することはできません
	*  @return
	* 	削除したﾌｧｲﾙの数を返します
	*/
	static int FilenamesNoExtRemove
			( const CStringArray& astrEExt , CStringArray* pastrFilename ) ;

// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	* @param bEAcceptSingle [in]
	*	ﾌｧｲﾙ１つだけのドロップを受け付けます（SDIで使います）
	*/
	CDropTargetDoctmpl( BOOL bEAcceptSingle ) ;
	virtual ~CDropTargetDoctmpl() ;
	
// ********************************
//	COleDropTarget
// ********************************
 public:
	/**
	* 【オーバライド】
	* 	CWinAppに対して、このアプリケーションがサポートしている拡張子を
	* 	問い合わせて、その結果を m_astrExt に保存します。
	* 	ドラッグされているのが、アプリケーションでサポートしている拡張子
	* 	であった場合は、このドロップターゲットへのコピーを受け付けます
	*/
	virtual DROPEFFECT OnDragEnter( CWnd* pWnd, COleDataObject* pDataObject
										, DWORD dwKeyState, CPoint point );

	/**
	* 【オーバライド】
	* 	ドラッグされているのが、アプリケーションでサポートしている拡張子
	* 	であった場合は、このドロップターゲットへのコピーを受け付けます
	*/
	virtual DROPEFFECT OnDragOver( CWnd* pWnd, COleDataObject* pDataObject
										, DWORD dwKeyState, CPoint point );
	
	/**
	* 【オーバライド】
	* 	特に処理はありません
	*/
	virtual void OnDragLeave( CWnd* pWnd ) ;
	
	/**
	* 【オーバライド】
	* 	ドラッグされているのが、アプリケーションでサポートしている拡張子
	* 	であった場合は、そのファイル名を配列に格納して、DropProc() を
	* 	呼び出します
	*/
	virtual BOOL OnDrop( CWnd* pWnd, COleDataObject* pDataObject
									, DROPEFFECT dropEffect, CPoint point );
	
	
// ********************************
//	COleDropTarget
// ********************************
 public:
	/**
	* @param pWnd [in]
	* 	カーソルが現在あるウィンドウへのポインタ
	* @param astrEFilename [in]
	* 	ドロップされるデータを持っているデータ オブジェクトへのポインタ。
	* @param dropEffect [in]
	* 	ユーザーが選択するドロップ操作の結果。次の値の 1 つ以上を
	* 	組み合わせたものです。 
	* 		- DROPEFFECT_COPY   コピー操作が行われます。
	* 		- DROPEFFECT_MOVE   移動操作が行われます。
	* 		- DROPEFFECT_LINK   ドロップされたデータと元のデータが
	* 			リンクされます。
	* 		- DROPEFFECT_SCROLL   ドラッグ スクロール操作がターゲット内で
	* 			発生するところか、発生しています。 
	* @param point [in]
	* 	画面上におけるカーソルの位置をピクセル単位で指定します。
	* @return
	* 	ドロップが成功した場合は 0 以外を返します。
	* 	それ以外の場合は 0 を返します。
	*/
	virtual BOOL OnFiledrop( CWnd* pWnd , const CStringArray& astrEFilename
								, DROPEFFECT dropEffect, CPoint point ) ;

};

} //namespace Hidemdi
} //namespace OuMfc

#endif /*CDropTargetDoctmpl_h*/


