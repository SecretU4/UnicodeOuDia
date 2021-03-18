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
//	CaDcdGrid_PageSelector.h
// ****************************************************************
*/
/** @file */
#ifndef  CaDcdGrid_PageSelector_h
#define  CaDcdGrid_PageSelector_h

#include "DcdGrid\CDcdGrid.h"
#include "DcDraw\IfDcdTarget.h"

namespace DcDrawLib{
namespace DcdGrid{

// ****************************************************************
//	CaDcdGrid_PageSelector
// ****************************************************************
/**
   @brief
   【概要】
     CDcdGrid のアダプタとなるクラスです。
     MFC の DocView モデルにおける印刷／印刷プレビューを行う際、
     指定の印刷ページ番号に合わせて、CDcdGrid の属性を一時的に
   変更します。
   
   【使い方】
   
   １．  あらかじめ、 印刷するプリンタのDC／印刷プレビュー画面のDC
  	に接続する IfDcdTarget オブジェクトを生成してください。
      CDcdTargetPrinter か、 CDcdTargetMfcPrintInfo オブジェクトを
  	生成することになります。
   
   ※   CDcdTargetPrinter ・ CDcdTargetMfcPrintPreview オブジェクトを
   対象とする CaDcdTargetItemPosition を作成し、それを指定することも
   できます。
   
   ２．  このクラスのオブジェクトを生成してください。コンストラクタでは、
  	印刷を行う CDcdGrid オブジェクトと、描画先となる IfDcdTarget 
  	オブジェクトを指定しなくてはなりません。
   
   ※  このクラスのコンストラクタは、対象となる CDcdGrid と IfDcdTarget 
   をもとにして、各ページごとの X,Y の
    FixafterCOlumnNumber( スクロール位置 ) を計算し、内部のコンテナ
    contiYFixafterColumnNumber ・ contiXFixafterColumnNumber に保存します。
   
   ３．  setXPage() , setYPage() ・または setPage() で
  	ページ番号を指定してください。
  	 this はページ番号に合わせて、 CDcdGrid の FixafterColumnNumber を
  	移動します。
   
   @attention
  	MFC ではページ番号の値は 1 起点で表現していますが、
  	このクラスではページ番号は 0 起点で表現します。
   
   ４．  DcDraw() を呼び出すと、そのページの描画を行うことができます。
   
   ５．  デストラクタは、 this が変更した CDcdGrid の属性を戻します。

   ６．　このクラスを使って印刷したあとは、ウインドウに CDcdGrid の
   再描画を行ってください。

	@b【理由】@n
	　印刷終了後にウインドウ上のグリッドの表示が崩れる現象を
	 解消するためです。@n
	  このクラスは、印刷中はグリッドのスクロール位置を一時的に変更します。
	  このときに m_pCWndDcdGrid に再描画が発生すると、画面には一時的に
	位置の変更されたグリッドが描画されるため、画面が崩れます。
 */
class CaDcdGrid_PageSelector
{
// ********************************
///@name 関連
// ********************************
///@{
 private:
	/**
	  	印刷を行う CDcdGrid オブジェクトです。
	  	このオブジェクトの破棄の責務はクラスユーザーにあります。
	  	このオブジェクトは this より長く生存しなくてはなりません。
	  	コンストラクタで決まります。
	 */
	CDcdGrid*	m_pCDcdGrid ;
	
	/**
	  	印刷／印刷プレビュー画面の IfDcdTarget オブジェクト。
	  	このオブジェクトの破棄の責務はクラスユーザーにあります。
	  	このオブジェクトは this より長く生存しなくてはなりません。
	  	コンストラクタで決まります。
	 */
	 IfDcdTarget* m_pIfDcdTarget ;
	
///@}
// ********************************
///@name 属性
// ********************************
///@{
 private:
	/**
	   	プリンタの印刷を行う場合の、ページ毎の FixafterColumnNumber を
	   	保持しています。
	   	  必要なページ数は、
	   	contiYFixafterColumnNumber.size() *  contiXFixafterColumnNumber.size() 
	   	となります。
	 */
	std::deque<int>	m_contiYFixafterColumnNumber ;
	
	/**
	   @see m_contiYFixafterColumnNumber
	 */
	std::deque<int>	m_contiXFixafterColumnNumber ;
	
	/**
	  	X方向のページ番号。この値は、 0 以上 getXPageCount() 未満です。
	   @attention
	  	MFC ではページ番号の値は 1 起点で表現していますが、
	  	このクラスではページ番号は 0 起点で表現します。
	  	
	  	初期値は 0 ですが、メソッドで変更できます。
	 */
	int m_iXPage ;
	
	/**
	  	Y方向のページ番号。この値は、 0 以上 getYPageCount() 未満です。
	   @attention
	  	MFC ではページ番号の値は 1 起点で表現していますが、
	  	このクラスではページ番号は 0 起点で表現します。
	  	
	  	初期値は 0 ですが、メソッドで変更できます。
	 */
	int m_iYPage ;
	
///@}
// --------------------------------
///@name 内部データ
// --------------------------------
///@{
 private:
	/**
	  	コンストラクタの時点での、 m_pCDcdGrid の FixafterColumnNumber を
	  	保持します。
	  	この値は、デストラクタで  m_pCDcdGrid に復帰します。
	 */
	int m_iYFixafterColumnNumberSid ;

	/**
	   @see iYFixafterColumnNumberSid
	 */
	int m_iXFixafterColumnNumberSid ;
	
///@}
// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	   @param pCDcdGrid [in]
	  	印刷を行う CDcdGrid オブジェクトです。
	  	このオブジェクトの破棄の責務はクラスユーザーにあります。
	  	このオブジェクトは this より長く生存しなくてはなりません。
	  	コンストラクタで決まります。
	   @param pIfDcdTarget [in]
	  	印刷／印刷プレビュー画面の IfDcdTarget オブジェクト。
	  	このオブジェクトの破棄の責務はクラスユーザーにあります。
	  	このオブジェクトは this より長く生存しなくてはなりません。
	  	コンストラクタで決まります。
	 */
	
	CaDcdGrid_PageSelector( 
		CDcdGrid*	pCDcdGrid ,
		IfDcdTarget* pIfDcdTarget ) ;
	
	virtual ~CaDcdGrid_PageSelector() ;


// ********************************
//	CaDcdGrid_PageSelector
// ********************************
 public:
	// ********************************
	///@name CaDcdGrid_PageSelector 関連
	// ********************************
	///@{
	virtual CDcdGrid*	getCDcdGrid() ;
	virtual IfDcdTarget* getIfDcdTarget() ;
	
	///@}
	// ********************************
	///@name CaDcdGrid_PageSelector 属性
	// ********************************
	///@{
	virtual void getYFixafterColumnNumber( std::deque<int>* pvalue ) ;
	virtual void getXFixafterColumnNumber( std::deque<int>* pvalue ) ;

	/**
	  @return 
	  	Grid の印刷に必要なページの、X方向の数を返します。
	 */
	virtual int getXPageCount() ;

	/**
	   @return 
	  	Grid の印刷に必要なページの、Y方向の数を返します。
	 */
	virtual int getYPageCount() ;

	virtual int getXPage() ;

	/**
	  	X方向のページ番号を移動します。
	  	この関数は、ページ番号に
	   合わせて、 CDcdGrid の FixafterColumnNumber を移動します。
	   @param value [in]
	  	ページ番号を指定してください。
	  	この値は、 0 以上 getXPageCount() 未満です。
	  	INT_MAX は、最後のページを指定したものとみなします。
	 */
	virtual CaDcdGrid_PageSelector& setXPage( int value ) ;

	virtual int getYPage() ;

	/**
	  	X方向のページ番号を移動します。
	  	この関数は、ページ番号に
	   合わせて、 CDcdGrid の FixafterColumnNumber を移動します。
	   @param value [in]
	  	ページ番号を指定してください。
	  	この値は、 0 以上 getYPageCount() 未満です。
	  	INT_MAX は、最後のページを指定したものとみなします。
	   @attention
	  	MFC ではページ番号の値は 1 起点で表現していますが、
	  	このクラスではページ番号は 0 起点で表現します。
	 */
	virtual CaDcdGrid_PageSelector& setYPage( int value ) ;


	/**
	   @return 
	  	Grid の印刷に必要なページの数を返します。
	  	このページ数は、X 方向・Y方向のページ数の積です。
	 */
	virtual int getPageCount() ;

	/**
	   @return
	  	現在表示しているページ番号です。
	  	このページ番号は、『積算ページ番号』です。
	  
	  	<H4>
	  	【積算ページ番号】
	  	</H4>
	  	『積算ページ番号』は、左上のページのページ番号を０とし、
	  	以後は横書き文書順にページ番号を加算したものです。
	  
	  	たとえば、X方向のページ数が３、Y方向のページ数が４のグリッドの場合、
	  
	  	- X方向ページ番号=0,Y方向ページ番号=0 の積算ページ番号 = 0 
	  	- X方向ページ番号=1,Y方向ページ番号=0 の積算ページ番号 = 1 
	  	- X方向ページ番号=2,Y方向ページ番号=0 の積算ページ番号 = 2 
	  	- X方向ページ番号=0,Y方向ページ番号=1 の積算ページ番号 = 3 
	  	- X方向ページ番号=1,Y方向ページ番号=1 の積算ページ番号 = 4 
	  
	  	となります。
	  
	  	値の範囲は、 0 以上 getPageCont() 未満です。
	   @attention
	  	MFC ではページ番号の値は 1 起点で表現していますが、
	  	このクラスではページ番号は 0 起点で表現します。
	 */
	virtual int getPage() ;


	/**
	  	『積算ページ番号』を指定します。
	  	@param iPage [in]
	  	『積算ページ番号』を指定してください。
	  	値の範囲は、 0 以上 getPageCont() 未満です。
	  	但し、INT_MAX を指定すると、最終ページを指定したことになります。
	 */
	virtual CaDcdGrid_PageSelector& setPage( int value ) ;
	
	///@}
	// ********************************
	///@name CaDcdGrid_PageSelector 操作
	// ********************************
	///@{
	/**
	  	CDcdGrid の、m_iPage で指定されているページを、
	  	IfDcdTarget に出力します。
	   @return
	  	描画を行った場合は真・この領域への描画ができなかった場合は偽です。 
	 */
	virtual bool DcDraw() ;
	///@}
};


} //namespace DcdGrid
} //namespace DcDrawLib




#endif /*CaDcdGrid_PageSelector_h*/
