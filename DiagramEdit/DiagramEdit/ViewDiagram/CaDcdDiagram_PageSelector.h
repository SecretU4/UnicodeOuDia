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
//	CaDcdDiagram_PageSelector.h
// ****************************************************************
*/
/** @file */
#ifndef  CaDcdDiagram_PageSelector_h
#define  CaDcdDiagram_PageSelector_h

#include "CDcdDiagram2.h"

namespace ViewDiagram{

// ****************************************************************
//	CaDcdDiagram_PageSelector
// ****************************************************************
/**
   @brief
   【概要】
     CDcdDiagram2 のアダプタとなるクラスです。
  
     ダイヤグラムの印刷に必要なページ数を調べます。
  また、指定の印刷ページ番号に合わせて、CDcdDiagtram2 の属性を一時的に
  変更します。
   
   <H4>
   【使い方】
   </H4>
   
   １．  このクラスのオブジェクトを生成してください。コンストラクタでは、
  	印刷を行う CDcdDiagram2 オブジェクトを指定しなくてはなりません。

    ※ オブジェクト生成後、getPageCount() が0なら、印刷できるページはありません。
  	
   ２．  setXPage() , setYPage() ・または setPage() で
  	ページ番号を指定してください。
  	 this はページ番号に合わせて、 CDcdDiagram2::Zone_Dgr を一時的に
  	移動します。
   
   @attention
  	MFC ではページ番号の値は 1 起点で表現していますが、
  	このクラスではページ番号は 0 起点で表現します。
   
   ３．  DcDraw() を呼び出すと、そのページの描画を行うことができます。
  	引数には、 印刷するプリンタのDC／印刷プレビュー画面のDC
  	に接続する IfDcdTarget オブジェクトを指定してください。
      CDcdTargetPrinter か、 CDcdTargetMfcPrintInfo オブジェクトを
  	指定することになります。
   
   ４．  デストラクタは、 this が変更した CDcdGrid の属性を戻します。
   
 */
class CaDcdDiagram_PageSelector : public IfDcDraw
{
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	/**
		印刷を行う CDcdDiagram2 オブジェクトです。
	  	このオブジェクトの破棄の責務はクラスユーザーにあります。
	  	このオブジェクトは this より長く生存しなくてはなりません。
	  	コンストラクタで決まります。
	  
	  	このクラスのページ数は、
	  	 m_pCDcdDiagram2->getZone_Dgr().getSize()
	  	を１ページとして計算します。
	 */
	CDcdDiagram2*	m_pCDcdDiagram2 ;
	///@}
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	  	１ページあたりのダイアグラムの印刷範囲を、
	  	『ダイヤグラムエンティティ座標系』で指定します。
	  
	  	コンストラクタで決まります。

		この値のXが0なら、getXPageCount() は0になります。
		この値のYが0なら、getYPageCount() は0になります。
		この場合、 getPageCount() の戻り値は 0 になります。
		 getPageCount() が 0の場合、 ダイヤグラムの印刷はできません。
	 */
	CdDcdSizeXy	m_sizePage_Dgr ;

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
private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
		コンストラクタの時点での、 
		ダイヤグラムの表示状態(位置・表示範囲・拡大率)を
		保存します。
		この値は、デストラクタで  m_pCDcdDiagram2 に復帰します。
	*/
	CconvContentPosToDcdTarget	m_CconvContentPosToDcdTargetPrev ;

	///@}
 public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	 @param pCDcdDiagram2 [in]
		印刷を行う CDcdDiagram2 オブジェクトです。
		このオブジェクトの破棄の責務はクラスユーザーにあります。
		このオブジェクトは this より長く生存しなくてはなりません。
	@param sizePage_Dgr [in]
		１ページあたりのダイアグラムの印刷範囲を、
		『ダイヤグラムエンティティ座標系』で指定してください。
	*/
	
	CaDcdDiagram_PageSelector( 
		CDcdDiagram2*	pCDcdDiagram2 ,
		const CdDcdSizeXy&	sizePage_Dgr ) ;
	
	virtual ~CaDcdDiagram_PageSelector() ;

public:
	// ********************************
	///@name 	IfDcDraw
	// ********************************
	///@{
	/**
	   	描画を要求します。
	   	この関数は、 pIfDcdTarget に、描画を行います。
	   @param pIfDcdTarget  [in]
	   	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	   @return
	   	描画を行った場合は真・この領域への描画ができなかった場合は偽です。
	  	<H4>
	  	【オーバライド】
	  	</H4>
	  	現在のページ番号（ m_iXPage ・m_iYPage ) のダイヤグラムを
	  	描画します。
	 */
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	   	このオブジェクトが描画するアイテムの大きさが決まっている場合は、
	   	その大きさを調べることができます。
	   	関数呼び出し元が複数の IfDcDraw オブジェクトを描画する場合には、
	   	関数呼び出し元は、この関数でアイテムの大きさを調べて、
	   	適切なレイアウトを考えてから、DcDraw() を実行することができます。
	   @param pIfDcdTarget [in]
	   	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	   @param pCdDcdSizeXy [out]
	   	このオブジェクトの描画するアイテムの大きさが決まっている場合は、
	   	この関数はこのアドレスに、そのアイテムのサイズを返します。
	   	このオブジェクトの描画するアイテムの大きさが決まっていない場合は、
	   	この値は不定です。
	   @return
	   	このオブジェクトの描画するアイテムの大きさが決まっていて、
	   	その大きさを *pCdDcdSizeXyに書き込んだ場合は真です。
	   	そうでない場合は、偽です。
	  	<H4>
	  	【オーバライド】
	  	</H4>
	  	このメソッドはサポートされません。 false を返します。
	 */
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
	
	///@}
public:
	// ********************************
	///@name CaDcdDiagram_PageSelector.関連
	// ********************************
	///@{
	CDcdDiagram2* getCDcdDiagram2(){	return m_pCDcdDiagram2 ;};
	
	///@}
	// ********************************
	///@name CaDcdDiagram_PageSelector.属性
	// ********************************
	///@{
	CdDcdSizeXy	getPage_Dgr(){	return m_sizePage_Dgr ;};

	/**
	   @return 
	  	CDcdDiagram2 の印刷に必要なページの、X方向の数を返します。
		印刷できない場合は、 0 を返します。
	 */
	virtual int getXPageCount() ;

	/**
	   @return 
	  	CDcdDiagram2 の印刷に必要なページの、Y方向の数を返します。
		印刷できない場合は、 0 を返します。
	 */
	virtual int getYPageCount() ;

	/**
	   @return 
	  	CDcdDiagram2 の印刷に必要なページの数を返します。
	  	このページ数は、X 方向・Y方向のページ数の積です。
		印刷できない場合は、 0 を返します。
	 */
	virtual int getPageCount() ;
	
	virtual int getXPage() ;

	/**
	  	X方向のページ番号を移動します。
	  	この関数は、ページ番号に
	   合わせて、 CDcdDiagram2 の Zone_Dgr を移動します。
	   @param value [in]
	  	ページ番号を指定してください。
	  	この値は、 0 以上 getXPageCount() 未満です。
	  	INT_MAX は、最後のページを指定したものとみなします。
	 */
	virtual CaDcdDiagram_PageSelector& setXPage( int value ) ;

	virtual int getYPage() ;

	/**
	  	X方向のページ番号を移動します。
	  	この関数は、ページ番号に
	   合わせて、 CDcdDiagram2 の Zone_Dgr を移動します。
	   @param value [in]
	  	ページ番号を指定してください。
	  	この値は、 0 以上 getYPageCount() 未満です。
	  	INT_MAX は、最後のページを指定したものとみなします。
	   @attention
	  	MFC ではページ番号の値は 1 起点で表現していますが、
	  	このクラスではページ番号は 0 起点で表現します。
	 */
	virtual CaDcdDiagram_PageSelector& setYPage( int value ) ;
	
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
	virtual CaDcdDiagram_PageSelector& setPage( int value ) ;
	
	///@}
	
};

} //namespace ViewDiagram


#endif /*CaDcdDiagram_PageSelector_h*/
