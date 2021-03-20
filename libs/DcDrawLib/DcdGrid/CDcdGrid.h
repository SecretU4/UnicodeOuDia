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
//	CDcdGrid.h
// ****************************************************************
*/
/** @file */

#ifndef  CDcdGrid_h
#define  CDcdGrid_h
#include <limits.h>

#include <deque>

#include "DcDraw/IfDcDraw.h"
#include "DcDraw/CaDcdTargetClip.h"

#include "DcdGrid/CDcdGridYColumn.h"
#include "DcdGrid/CDcdGridXColumn.h"
#include "DcdGrid/CDcdGridCell.h"

namespace DcDrawLib{
namespace DcdGrid{

// ****************************************************************
//	CDcdGrid
// ****************************************************************
/**
@brief
 グリッドを描画するクラスです。
  
  任意の数のY列・X列を作成し、セルにテキストを配置することができます。
  テキストを配置したあと、 DcDraw() メソッドを使って、任意のDC
(IfDcdTargetオブジェクト)に対してグリッドの描画を行うことができます。

使い方−グリッドを形成してセルにテキストを描画
 ================================================================

１．  setYColumnCount() ・ setXColumnCount() を使い、グリッドのY列数・
X列数を指定してください。

２．  各Y列・X列のサイズ（高さ・幅）を設定してください。Y列番号・X列番号を
指定して（左上から0起点の整数） getYColumn() ・ getXColumn() を
呼び出すことにより、Y列・X列を表す CDcdGridYColumn ・ CDcdGridXColumn オブジェクトの
ポインタを取得することができます。
各Y列・X列のサイズは、これらオブジェクトに対して
 CDcdGridXColumn::setColumnSize() , CDcdGridYColumn::setColumnSize() 
で設定してください。単位は、論理単位です。

３．  Y列番号・X列番号を指定して getCell() を呼び出すことにより、セルを表す
 CDcdGridCell オブジェクトのポインタを取得することができます。
CDcdGridCell は、セルの中身を描画する IfDcDraw オブジェクトと
関連を持っており、
関連する IfDcDraw オブジェクトを使って描画を行います。
  this は、デフォルトでは CDcdGridCell オブジェクトの
 IfDcDraw オブジェクトとして、 CDcdTextbox オブジェクトを生成して
登録します｡このため、 CDcdTextbox オブジェクトの m_strText 属性に
テキストを設定すると、 CDcdGrid はセルの中にテキストを描画します。

(例) セル番号 (1,0) に、文字列 "0000" をセットしています。
@code
Ou<CDcdTextbox>(pCDcdGrid->getCell( 1 , 0 )->getIfDcDraw())->setText( "0000" )  ;	
@endcode

４．  getItemSize() を呼び出すことにより、このグリッドの大きさを
論理単位で取得することができます。また、 DcDraw() で任意のDCにグリッドを
描画させることができます。

@attention
CDcdGridXColumn , CDcdGridYColumn は、デフォルトでは
 m_bAutoColumnSize , m_bAutoColumnBorderSize が真になっています。
この属性が真だと、グリッドの描画に時間がかかります。
列の数が多い場合は、 CDcdGridXColumn ,  CDcdGridYColumn の
m_bAutoColumnSize,m_bAutoColumnBorderSize を偽にしたうえで、
m_iColumnSize,m_iColumnBorderSize に明示的に
値を設定することをお勧めします。
 */
class CDcdGrid : public IfDcDraw
{
private:
	// --------------------------------
	//	インナータイプ
	// --------------------------------
	typedef	std::deque<CDcdGridYColumn*>	CDcdGridYColumnCont ;
	typedef	std::deque<CDcdGridXColumn*>	CDcdGridXColumnCont ;
	typedef	std::deque< CDcdGridCell* > CDcdGridYColumnCellCont ;
	typedef	std::deque< CDcdGridYColumnCellCont* > CDcdGridCellCont ;
	friend class CDcdGridYColumn ;
	friend class CDcdGridXColumn ;
	friend class CDcdGridCell ;
	
	
	
 private:
	// ********************************
	///	@name 集約
	// ********************************
	///@{

	/**
		Y列の先頭(上端)の罫線を表すオブジェクトです。
	*/
	CDcdGridYBorder	m_CDcdGridYBorderTop ;

	/**
	  	Y列オブジェクトを保持するコンテナです。要素数は、常に  Y列数 
	  	です。
	  
	  	先頭の要素(添え字0)はY列番号0、
	  	2番目（添え字1）がY列番号1、
	  	3番目(添え字2)がY列番号2・・・となります。
	  
	  	  コンストラクタでは、空となります。
	  	その後は、
	  		setYColumnCount() 
	  	が、コンテナに対してY列オブジェクトの追加・削除を行います。
	  
	  	コンテナ内のオブジェクトの破棄の責務は、thisにあります。
	 */
	CDcdGridYColumnCont		m_CDcdGridYColumnCont ;


	/**
		Y列の末尾(下端)の罫線を表すオブジェクトです。
	*/
	CDcdGridYBorder	m_CDcdGridYBorderBottom ;

	/**
		X列の先頭(左端)の罫線を表すオブジェクトです。
	*/
	CDcdGridXBorder	m_CDcdGridXBorderTop ;

	/**
	  	X列オブジェクトを保持するコンテナです。要素数は、常に  X列数 
	  	です。
	  
	  	先頭の要素(添え字0)はX列番号0、
	  	2番目（添え字1）がX列番号1、
	  	3番目(添え字2)がX列番号2・・・となります。
	  
	  	  コンストラクタでは、空となります。
	  	その後は、
	  		setYColumnCount() 
	  	が、コンテナに対してX列オブジェクトの追加・削除をX列います。
	  
	  	コンテナ内のオブジェクトの破棄の責務は、thisにあります。
	 */
	CDcdGridXColumnCont 	m_CDcdGridXColumnCont ;

	/**
		X列の末尾(右端)の罫線を表すオブジェクトです。
	*/
	CDcdGridXBorder	m_CDcdGridXBorderBottom ;

	
	/**
	  	セルオブジェクトを保持するコンテナです。
	  	
	  	このコンテナの要素数は、YColumn の数に等しくなります。
	  	このコンテナの各要素は、 XColumn 分の CDcdGridCell を保持する
	  	コンテナです。
	  	
	  	したがって、
	  
	  	m_CDcdGridCellCont[Y列番号][X列番号]
	  
	  	の形式で、対応する CDcdGridCell オブジェクトにアクセスができます。
	  
	  	コンテナ内のオブジェクトの破棄の責務は、thisにあります。
	 */
	CDcdGridCellCont 	m_CDcdGridCellCont ;
	///@}
	// ********************************
	/// @name 属性
	// ********************************
	///@{

	/**
	  	スクロール機能における、固定Y列
	  	（スクロールの対象から除外されるY列）の数です。
	  
	  	範囲は、0以上 Y列数以下です。
	  	Y列数が変化したとき、thisはこの属性をこの範囲に正規化します。
	  	
	  	初期値は0です。
	 */
	int	m_iYFixColumnCount ;

	/**
	  	スクロール機能において、一番上側に位置するY列番号です。
	  	ただし、固定Y列の数が１以上である場合、この値は固定Y列の下隣のY列番号
	  	となります。
	  	
	  	例えば、m_iYFixColumnCount が1で、この値が2の場合、
	  	DcDraw() での描画結果は、上からY列番号0・Y列番号2の順です。
	  	
	  	範囲は、m_iFixRiwCount 以上 Y列数未満です。
	  	Y列数が変化したとき、および m_iYFixColumnCount が変化したときに、
	  	thisはこの属性をこの範囲に正規化します。
	  	
	  	初期値は0です。
	 */
	int	m_iYFixafterColumnNumber ;

	/**
	  	スクロール機能における、固定X列
	  	（スクロールの対象から除外されるX列）の数です。
	  
	  	範囲は、0以上 X列数以下です。
	  	X列数が変化したとき、thisはこの属性をこの範囲に正規化します。
	  	
	  	初期値は0です。
	 */
	int	m_iXFixColumnCount ;
	
	/**
	  	スクロール機能において、一番左側に位置するX列番号です。
	  	ただし、固定X列の数が１以上である場合、この値は固定X列の右隣のX列番号
	  	となります。
	  	
	  	例えば、m_iXFixColumnCount が1で、この値が2の場合、
	  	DcDraw() での描画結果は、左からX列番号0・X列番号2の順です。
	  	
	  	範囲は、m_iXFixColumnCount 以上 X列数未満です。
	  	X列数が変化したとき、および m_iXFixColumnCount が変化したときに、
	  	thisはこの属性をこの範囲に正規化します。
	  	
	  	初期値は0です。
	 */
	int	m_iXFixafterColumnNumber ;

	///@}
private:
	// --------------------------------
	///@name	内部データ( createZoneCache() )
	// --------------------------------
	///@{
	/**
	  	通常は要素０です。
	  	createZoneCache() から destroyZoneCache() までの期間は
	  	getXColumnBorderZone() の結果を保持します。
	  	添え字は、列番号＋１となります。
	 */
	std::deque< CdDcdZone >	m_zonecontXColumnBorderZoneCache ;
	/**
	  	通常は要素０です。
	  	createZoneCache() から destroyZoneCache() までの期間は
	  	getXColumnZone() の結果を保持します。
	  	添え字は、列番号となります。
	 */
	std::deque< CdDcdZone >	m_zonecontXColumnZoneCache ;

	/**
	  	通常は要素０です。
	  	createZoneCache() から destroyZoneCache() までの期間は
	  	getXColumnZoneOverlap() の結果を保持します。
	  	添え字は、列番号となります。
	 */
	std::deque< CdDcdZone >	m_zonecontXColumnZoneOverlapCache ;

	/**
	  	通常は要素０です。
	  	createZoneCache() から destroyZoneCache() までの期間は
	  	getYColumnBorderZone() の結果を保持します。
	  	添え字は、列番号＋１となります。
	 */
	std::deque< CdDcdZone >	m_zonecontYColumnBorderZoneCache ;
	/**
	  	通常は要素０です。
	  	createZoneCache() から destroyZoneCache() までの期間は
	  	getYColumnZone() の結果を保持します。
	  	添え字は、列番号となります。
	 */
	std::deque< CdDcdZone >	m_zonecontYColumnZoneCache ;
	/**
	  	通常は要素０です。
	  	createZoneCache() から destroyZoneCache() までの期間は
	  	getYColumnZoneOverlap() の結果を保持します。
	  	添え字は、列番号となります。
	 */
	std::deque< CdDcdZone >	m_zonecontYColumnZoneOverlapCache ;
	///@}


protected:
	// --------------------------------
	///@name	下請関数
	// --------------------------------
	///@{
	/**
	  	指定のX列の範囲の大きさを求めます。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iXColumnNumberSrc [in]
	  	起点のX列番号を指定してください。
	  	bSrcIsBorder が真の場合だけ、-1が指定できます。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @param bSrcIsBorder [in]
	  	起点のX列番号が、そのX列番号の境界部分を指定しているなら真
	   @param iXColumnNumberDst [in]
	  	終点のX列番号を指定してください。
	  	bDstIsBorder が真の場合だけ、-1が指定できます。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @param bDstIsBorder [in]
	  	終点のX列番号が、そのX列番号の境界部分を指定しているなら真
	   @return
	  	サイズを返します。
	  
	  	（例）
	  
	  	列番号-1の境界線から、列番号2の列までの範囲を求める場合は、
	  	( iXColumnNumberSrc ,bSrcIsBorder ,
	  		iXColumnNumberDst ,bDstIsBorder) = ( -1 , true , 2 , false )
	  	となります
	 */
	int getXColumnsSize( 	IfDcdTarget* pIfDcdTarget ,
			int iXColumnNumberSrc , bool bSrcIsBorder ,
			int iXColumnNumberDst , bool bDstIsBorder) ;

	/**
	  	指定のY列の範囲の大きさを求めます。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iYColumnNumberSrc [in]
	  	起点のY列番号を指定してください。
	  	bSrcIsBorder が真の場合だけ、-1が指定できます。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @param bSrcIsBorder [in]
	  	起点のY列番号が、そのY列番号の境界部分を指定しているなら真
	   @param iYColumnNumberDst [in]
	  	終点のY列番号を指定してください。
	  	bDstIsBorder が真の場合だけ、-1が指定できます。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @param bDstIsBorder [in]
	  	終点のY列番号が、そのY列番号の境界部分を指定しているなら真
	   @return
	  	サイズを返します。
	  
	  	（例）
	  
	  	列番号-1の境界線から、列番号2の列までの範囲を求める場合は、
	  	( iYColumnNumberSrc ,bSrcIsBorder ,
	  		iYColumnNumberDst ,bDstIsBorder) = ( -1 , true , 2 , false )
	  	となります
	 */
	int getYColumnsSize( 	IfDcdTarget* pIfDcdTarget ,
			int iYColumnNumberSrc , bool bSrcIsBorder ,
			int iYColumnNumberDst , bool bDstIsBorder) ;

	/**
	  	setYColumnCount() と insertYColumn() の下請関数です。
	  
	  	Y列を１つ、指定の位置に追加します。
	  	この関数は、 
	  	m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	  	m_CDcdGridCellCont
	  	の増減だけを行います。
	  	adjustProp() は行いません。
	   @param iYColumnNumber
	  	Y列番号を指定してください。
	  	新しく追加されたY列が、このY列番号になります。
	  	範囲は 0 以上 getYColumnNumber() 以下で、
	  	0 なら先頭・getYColumnNumber() なら末尾への追加となります。
	  	  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	   @return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	int insertYColumn_insertColumnCell( int iYColumnNumber ) ;

	/**
	  	setXColumnCount() と insertXColumn() の下請関数です。
	  
	  	X列を１つ、指定の位置に追加します。
	  	この関数は、 
	  	m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	  	m_CDcdGridCellCont
	  	の増減だけを行います。
	  	adjustProp() は行いません。
	   @param iXColumnNumber
	  	X列番号を指定してください。
	  	新しく追加されたX列が、このX列番号になります。
	  	範囲は 0 以上 getXColumnNumber() 以下で、
	  	0 なら先頭・getXColumnNumber() なら末尾への追加となります。
	  	  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	   @return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	int insertXColumn_insertColumnCell( int iXColumnNumber ) ;
	
	/**
	  	setYColumnCount() と eraseYColumn() の下請関数です。
	  
	  	Y列を１つ、削除します。
	  	この関数は、 
	  	m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	  	m_CDcdGridCellCont
	  	の増減だけを行います。
	  	adjustProp() は行いません。
	   @param iYColumnNumber
	  	Y列番号を指定してください。
	  	範囲は 0 以上 getYColumnNumber() 未満です。
	  	  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	   @return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	int eraseYColumn_eraseColumnCell( int iYColumnNumber ) ;

	/**
	  	setXColumnCount() と eraseXColumn() の下請関数です。
	  
	  	X列を１つ、削除します。
	  	この関数は、 
	  	m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	  	m_CDcdGridCellCont
	  	の増減だけを行います。
	  	adjustProp() は行いません。
	   @param iXColumnNumber
	  	X列番号を指定してください。
	  	範囲は 0 以上 getXColumnNumber() 未満です。
	  	  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	   @return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	int eraseXColumn_eraseColumnCell( int iXColumnNumber ) ;

	/**
	  	Y列番号・X列番号に関係する属性の正規化を行います。
	  	Y列やX列を追加・削除した場合には、この関数を使ってY列番号・
	  	X列番号の正規化を行います。
	  	正規化は、以下の順に行います。
	  
	  
	  	- m_iXFixColumnCount
	  	- m_iXFixafterColumnNumber
	  	- m_iYFixColumnCount
	  	- m_iYFixafterColumnNumber
	  
	  	- CDcdGridCell::m_iXAttachCellCount
	  	- CDcdGridCell::m_iYAttachCellCount
	  
	  	- CDcdGridCell::m_pcellAttachTo
	 */
	virtual void adjustProp() ;
 
	/**
	  	getXColumnZone(),getXColumnBorderZone(),getXColumnZoneOverlap()
	  	getYColumnZone(),getYColumnBorderZone(),getYColumnZoneOverlap()
	  	の結果のキャッシュを
	  
	  	-	m_zonecontXColumnBorderZoneCache ;
	  	-	m_zonecontXColumnZoneCache ;
	  	-	m_zonecontXColumnZoneOverlapCache ;
	  	-	m_zonecontYColumnBorderZoneCache ;
	  	-	m_zonecontYColumnZoneCache ;
	  	-	m_zonecontXYColumnZoneOverlapCache ;
	  
	  	に作成します。
	@param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	@return
		- true : キャッシュを作成しました。
		- false: キャッシュがすでに存在します。
	*/
	bool createZoneCache( IfDcdTarget* pIfDcdTarget ) ;

	/**
	  	getXColumnZone(),getXColumnBorderZone(),getXColumnZoneOverlap()
	  	getYColumnZone(),getYColumnBorderZone(),getYColumnZoneOverlap()
	  	の結果のキャッシュ
	  
	  	-	m_zonecontXColumnBorderZoneCache ;
	  	-	m_zonecontXColumnZoneCache ;
	  	-	m_zonecontXColumnZoneOverlapCache ;
	  	-	m_zonecontYColumnBorderZoneCache ;
	  	-	m_zonecontYColumnZoneCache ;
	  	-	m_zonecontXYColumnZoneOverlapCache ;
	  
	  	を破棄します。
	 */
	void destroyZoneCache() ;
	///@}
	// --------------------------------
	///@name	DcDrawの下請関数
	// --------------------------------
	///@{

	/**
		「指定のX罫線(縦罫線)の、指定のY列の位置が、結合セルによって表示されない」
		場合を判定します。
	@param iXColumnNumber
		対象の罫線のX列Indexを指定してください。
	@param iYColumnNumber
		描画場所のY列Indexを指定してください。
	*/
	bool IsXBorderOverlappedByAttachedCell( int iXColumnNumber , int iYColumnNumber ) ;


	/**
		「指定のY罫線(横罫線)の、指定のX列の位置が、結合セルによって表示されない」
		場合を判定します。
	@param iXColumnNumber
		描画場所のX列Indexを指定してください。
	@param iYColumnNumber
		Y罫線(横罫線)の列Indexを指定してください。
	*/
	bool IsYBorderOverlappedByAttachedCell( int iXColumnNumber , int iYColumnNumber ) ;


	/**
		DcDrawの下請け関数です。
		X列の罫線を描画します。
		Y列の固定列側への描画・スクロール可能列側への描画の２つから選択することができます。
	@param isYFixColumn
		- true: Y列の固定列側への描画
		- false: Y列のスクロール可能列側への描画
	@param pTarget 
		描画領域を指定してください。
		この描画領域は、クリッピングされている必要があります。
	@param iXColumnNumber
	  	 X列番号を指定してください。範囲は、-1以上 getXColumnCount() 未満です。
	  	-	-1 ;	左端の罫線オブジェクトに対する描画。
	  	-	getXColumnCount()-1 , INT_MAX ;	
	  		右端の罫線オブジェクトに対する描画。
	@return
		- true:何らかの描画を行いました。
		- false:描画を行いませんでした。
	*/
	bool DcDraw_DrawXColumn( bool isYFixColumn , CaDcdTargetClip* pTarget , int iXColumnNumber ) ;


	/**
		DcDrawの下請け関数です。
		Y列の罫線を描画します。
		X列の固定列側への描画・スクロール可能列側への描画の２つから選択することができます。
	@param isXFixColumn
		- true: X列の固定列側への描画
		- false: X列のスクロール可能列側への描画
	@param pTarget 
		描画領域を指定してください。
		この描画領域は、クリッピングされている必要があります。
	@param iYColumnNumber
	  	 Y列番号を指定してください。範囲は、-1以上 getYColumnCount() 未満です。
	  	-	-1 ;	左端の罫線オブジェクトに対する描画。
	  	-	getYColumnCount()-1 , INT_MAX ;	
	  		右端の罫線オブジェクトに対する描画。
	@return
		- true:何らかの描画を行いました。
		- false:描画を行いませんでした。
	*/
	bool DcDraw_DrawYColumn( bool isXFixColumn , CaDcdTargetClip* pTarget , int iYColumnNumber ) ;

	///@}
 public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CDcdGrid() ;
	virtual ~CDcdGrid() ;
	
 private:
	CDcdGrid( const CDcdGrid& ev ){} ;
	void operator=( const CDcdGrid& ev ){} ;
	
 public:
	// ********************************
	///@name	IfDcDraw
	// ********************************
	///@{
	/**
	 	描画を要求します。
	 	この関数は、 pIfDcdTarget に、描画を行います。
	 @param pIfDcdTarget  [in]
	 	このオブジェクトに描画を行わせたいDCと領域を指定してください。
	 @return
	 	描画を行った場合は真・この領域への描画ができなかった場合は偽です。
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
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
	
	///@}
 protected:
	// --------------------------------
	///@name 行・列・セルの初期化
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
	  	   CDcdLine オブジェクトを new で生成し、
	  	pCDcdGridXColumn の IfDcDraw インターフェースに登録します。
	  	このときの属性は、太さ１の黒の実線
	  	となります。
	 */
	virtual void OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) ;
	
	/**
	  	this は、Column が破棄される直前に、この関数を呼び出します。
	  	破棄される Column に対して、 IfDcDraw インターフェースオブジェクトの
	  	登録解除・破棄をはじめとした
	  	後始末を行います。
	  
	  	この関数をオーバライドすることにより、 Column に特有の後始末を
	  	行うことができます。
	  	
	   @param iXColumnNumber [in]
	  	  破棄される Column の列番号です。
	   @param pCDcdGridXColumn [in,out]
	  	  破棄される CDcdGridXColumn オブジェクトです。
	  	  この関数はこのオブジェクトに対して、後始末を行うことができます。
	  	
	   [オーバライド]
	  	pCDcdGridXColumn の IfDcDraw インターフェースを登録解除し、
	  	オブジェクトを delete で破棄します。
	 */
	virtual void OnDeleteXColumn( int iXColumnNumber , 
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
	  	   CDcdLine オブジェクトを new で生成し、
	  	pCDcdGridYColumn の IfDcDraw インターフェースに登録します。
	  	このときの属性は、太さ１の黒の実線
	  	となります。
	 */
	virtual void OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;
	
	/**
	  	this は、Column が破棄される直前に、この関数を呼び出します。
	  	破棄される Column に対して、 IfDcDraw インターフェースオブジェクトの
	  	登録解除・破棄をはじめとした
	  	後始末を行います。
	  
	  	この関数をオーバライドすることにより、 Column に特有の後始末を
	  	行うことができます。
	  	
	   @param iYColumnNumber [in]
	  	  破棄される Column の列番号です。
	   @param pCDcdGridYColumn [in,out]
	  	  破棄される CDcdGridYColumn オブジェクトです。
	  	  この関数はこのオブジェクトに対して、後始末を行うことができます。
	  	
	   [オーバライド]
	  	pCDcdGridYColumn の IfDcDraw インターフェースを登録解除し、
	  	オブジェクトを delete で破棄します。
	 */
	virtual void OnDeleteYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;

	/**
	  	this は、新しい Cell が生成された直後に、この関数を呼び出します。
	  	新しい Cell に対して、 IfDcDraw インターフェースオブジェクト
	  	の生成・登録をはじめとした
	  	初期化を行います。
	  
	  	この関数をオーバライドすることにより、 Cell に特有の初期化を
	  	行うことができます。
	  	
	   @param iXColumnNumber [in]
	  	  新しい Cell のX列番号です。
	   @param iYColumnNumber [in]
	  	  新しい Cell のY列番号です。
	   @param pCDcdGridCell [in,out]
	  	  新しく生成された CDcdGridCell オブジェクトです。
	  	  この関数はこのオブジェクトに対して、初期化を行うことができます。
	  	
	   [オーバライド]
	  	   CDcdTextbox オブジェクトを new で生成し、
	  	pCDcdGridCell の IfDcDraw インターフェースに登録します。
	  	このときの属性は、
	  
	  		- フォントはストックオブジェクトの DEFAULT_GUI_FONT 
	  		- テキスト配置は 
	  			CdDrawTextFormat::H_LEFT | 
	  			CdDrawTextFormat::V_SINGLELINT_CENTER
	  		- 背景色は 白
	  		- テキストの上下・左右の枠領域の太さは論理単位で１
	  
	  	となります。
	 */
	virtual void OnCreateCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) ;
	
	/**
	  	this は、Cell が破棄される直前に、この関数を呼び出します。
	  	破棄される Cell に対して、 IfDcDraw インターフェースオブジェクトの
	  	登録解除・破棄をはじめとした
	  	後始末を行います。
	  
	  	この関数をオーバライドすることにより、 Cell に特有の後始末を
	  	行うことができます。
	  	
	   @param iXColumnNumber [in]
	  	  破棄される Cell のX列番号です。
	   @param iYColumnNumber [in]
	  	  破棄される Cell のY列番号です。
	   @param pCDcdGridCell [in,out]
	  	  破棄される CDcdGridCell オブジェクトです。
	  	  この関数はこのオブジェクトに対して、後始末を行うことができます。
	  	
	   [オーバライド]
	  	pCDcdGridCell の IfDcDraw インターフェースを登録解除し、
	  	オブジェクトを delete で破棄します。
	 */
	virtual void OnDeleteCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) ;
	///@}
 public:
	// ********************************
	///	@name Y列・X列の数
	// ********************************
	///@{
	/**
	   @return
	  	現在のY列の数を返します。初期状態では、０を返します。
	 */
	virtual int		getYColumnCount() ;
	
	/**
	   @param ev [in]
	  	Y列の数を指定してください。
	 */
	virtual CDcdGrid& setYColumnCount( int ev ) ;
	
	/**
	   @return
	  	現在のX列の数を返します。初期状態では、０を返します。
	 */
	virtual int		getXColumnCount() ;

	/**
	   @param ev [in]
	  	X列の数を指定してください。
	 */
	virtual CDcdGrid& setXColumnCount( int ev ) ;

	///@}
	
 public:
	// ********************************
	///	@name Y列・X列を挿入/削除
	// ********************************
	///@{
	/**
	  	Y列を１つ、指定の位置に追加します。
	   @param iYColumnNumber
	  	Y列番号を指定してください。
	  	新しく追加されたY列が、このY列番号になります。
	  	範囲は 0 以上 getYColumnNumber() 以下で、
	  	0 なら先頭・getYColumnNumber() なら末尾への追加となります。
	  	  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	   @return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	virtual int insertYColumn( int iYColumnNumber ) ;

	/**
	  	X列を１つ、指定の位置に追加します。
	   @param iXColumnNumber
	  	X列番号を指定してください。
	  	新しく追加されたX列が、このX列番号になります。
	  	範囲は 0 以上 getXColumnNumber() 以下で、
	  	0 なら先頭・getXColumnNumber() なら末尾への追加となります。
	  	  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	   @return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	virtual int insertXColumn( int iXColumnNumber ) ;
	
	/**
	  	Y列を１つ、削除します。
	   @param iYColumnNumber
	  	Y列番号を指定してください。
	  	範囲は 0 以上 getYColumnNumber() 未満です。
	  	  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	   @return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	virtual int eraseYColumn( int iYColumnNumber ) ;
	/**
	  	X列を１つ、削除します。
	   @param iXColumnNumber
	  	X列番号を指定してください。
	  	範囲は 0 以上 getXColumnNumber() 未満です。
	  	  ただし、 INT_MAX を指定すると、末尾を指定したことになります。
	   @return
	  	成功したら0以上、エラーなら負の数です。
	   -	-2 ;	//	インデクスが不正
	 */
	virtual int eraseXColumn( int iXColumnNumber ) ;
	///@}
	
 public:
	// ********************************
	///	@name Y列・X列・セルオブジェクト
	// ********************************
	///@{
	/**
	@return
		グリッドの外枠の枠線オブジェクトを返します。
		上端のオブジェクトを返します。
	*/
	virtual CDcdGridYBorder* getCDcdGridYBorderTop()
	{	return &m_CDcdGridYBorderTop ;};

	/**
	 	  指定されたY列番号の、Y列オブジェクト CDcdGridYColumn のポインタを
	  	取得することができます。このポインタを使って、Y列に対する操作を
	  	Y列うことができます。
	   @param iYColumnNumber [in] 
	  	 Y列番号を指定してください。範囲は、-1以上 getYColumnCount() 未満です。
	  	 ただし、 INT_MAX を指定すると、最終Y列を指定したことになります。
	   @return
	  	  対応するY列オブジェクトを返します。
	  	  インデクスが不正な場合は、NULLを返します。
	  
	  	  返されたオブジェクトの破棄の責務は、thisにあります。
	  	  該当するY列が CDcdGrid の別のメソッドによって削除されると、返された
	  	ポインタは無効になります。
	  	   thisが破棄されたときにも、返されたポインタは無効になります。
	 */
	virtual CDcdGridYColumn*	getYColumn( int iYColumnNumber )  ;

	/**
	  	  指定されたY列番号の、罫線オブジェクト CDcdGridYBorder のポインタを
	  	取得することができます。このポインタを使って、Y列の罫線に対する操作を
	  	行うことができます。
	   @param iYColumnNumber [in] 
	  	 Y列番号を指定してください。範囲は、-1以上 getYColumnCount() 未満です。
	  	-	-1 ;	上端の罫線オブジェクト（m_CDcdGridYBorderTop）を返します。
	  	-	getYColumnCount()-1 , INT_MAX ;	
	  		下端の罫線オブジェクト（m_CDcdGridYBorderBottom）を返します。
	   @return
	  	 対応するY列罫線オブジェクトを返します。
	  	 インデクスが不正な場合は、NULLを返します。
	  
	  	  返されたオブジェクトの破棄の責務は、thisにあります。
	  	  該当するY列が CDcdGrid の別のメソッドによって削除されると、返された
	  	ポインタは無効になります。
	  	   thisが破棄されたときにも、返されたポインタは無効になります。
	 */
	virtual CDcdGridYBorder*	getYBorder( int iYColumnNumber )  ;

	/**
	@return
		グリッドの外枠の枠線オブジェクトを返します。
		下端のオブジェクトを返します。
	*/
	virtual CDcdGridYBorder* getCDcdGridYBorderBottom(){ return &m_CDcdGridYBorderBottom ;};

	/**
	@return
		グリッドの外枠の枠線オブジェクトを返します。
		左端のオブジェクトを返します。
	*/
	virtual CDcdGridXBorder* getCDcdGridXBorderTop(){	return &m_CDcdGridXBorderTop ;};

	/**
	  	  指定されたX列番号の、X列オブジェクト CDcdGridYColumn のポインタを
	  	取得することができます。このポインタを使って、X列に対する操作を
	  	行うことができます。
	   @param iXColumnNumber [in] 
	  	 X列番号を指定してください。範囲は、-1以上 getXColumnCount() 未満です。
	  	 ただし、 INT_MAX を指定すると、最終X列を指定したことになります。
	   @return
	  	 対応するX列オブジェクトを返します。
	  	 インデクスが不正な場合は、NULLを返します。
	  
	  	  返されたオブジェクトの破棄の責務は、thisにあります。
	  	  該当するX列が CDcdGrid の別のメソッドによって削除されると、返された
	  	ポインタは無効になります。
	  	   thisが破棄されたときにも、返されたポインタは無効になります。
	 */
	virtual CDcdGridXColumn*	getXColumn( int iXColumnNumber )  ;

	/**
	  	  指定されたX列番号の、罫線オブジェクト CDcdGridXBorder のポインタを
	  	取得することができます。このポインタを使って、X列の罫線に対する操作を
	  	行うことができます。
	   @param iXColumnNumber [in] 
	  	 X列番号を指定してください。範囲は、-1以上 getYColumnCount() 未満です。
	  	-	-1 ;	左端の罫線オブジェクト（m_CDcdGridXBorderTop）を返します。
	  	-	getXColumnCount()-1 , INT_MAX ;	
	  		右端の罫線オブジェクト（m_CDcdGridXBorderBottom）を返します。
	   @return
	  	 対応するX列罫線オブジェクトを返します。
	  	 インデクスが不正な場合は、NULLを返します。
	  
	  	  返されたオブジェクトの破棄の責務は、thisにあります。
	  	  該当するX列が CDcdGrid の別のメソッドによって削除されると、返された
	  	ポインタは無効になります。
	  	   thisが破棄されたときにも、返されたポインタは無効になります。
	 */
	virtual CDcdGridXBorder*	getXBorder( int iXColumnNumber )  ;

	/**
	@return
		グリッドの外枠の枠線オブジェクトを返します。
		右端のオブジェクトを返します。
	*/
	virtual CDcdGridXBorder* getCDcdGridXBorderBottom()
	{ return &m_CDcdGridXBorderBottom ;};

	/**
		指定の CDcdGridYColumn オブジェクトの、列番号を返します。
	@param pCDcdGridYColumn [in]
		YColumn オブジェクトを指定してください。
	@return
		列番号を返します。範囲は 0 以上 getYColumnCount() 未満です。
		Y列オブジェクトが CDcdGrid オブジェクトに集約されていない場合は、
		INT_MIN を返します。
	*/
	virtual int getYColumnNumberOfCoulmn( CDcdGridYColumn*	pCDcdGridYColumn ) ;
	/**
		@see YColumnNumberOfCoulmn() 
	*/
	virtual int getXColumnNumberOfCoulmn( CDcdGridXColumn*	pCDcdGridXColumn ) ;

	/**
		指定の CDcdGridYBorder オブジェクトの、列番号を返します。
	@param pCDcdGridYBorder [in]
		YBorder オブジェクトを指定してください。
	@return
		列番号を返します。範囲は -1 以上 getYColumnCount() 未満です。
		オブジェクトが CDcdGrid オブジェクトに集約されていない場合は、
		INT_MIN を返します。
	 	-	-1 ;	上端の罫線オブジェクト（m_CDcdGridYBorderTop）
	 	-	getYColumnCount()-1  ;	下端の罫線オブジェクト（m_CDcdGridYBorderBottom）・	@n
		もしくは m_CDcdGridYColumnCont の末尾の要素です。
	*/
	virtual int getYColumnNumberOfBorder( CDcdGridYBorder*	pCDcdGridYBorder ) ;

	
	/**
		指定の CDcdGridXBorder オブジェクトの、列番号を返します。
	@param pCDcdGridXBorder [in]
		XBorder オブジェクトを指定してください。
	@return
		列番号を返します。範囲は -1 以上 getXColumnCount() 未満です。
		オブジェクトが CDcdGrid オブジェクトに集約されていない場合は、
		INT_MIN を返します。
	 	-	-1 ;	左端の罫線オブジェクト（m_CDcdGridXBorderTop）
	 	-	getXColumnCount()-1  ;	右端の罫線オブジェクト（m_CDcdGridXBorderBottom）・	@n
		もしくは m_CDcdGridXColumnCont の末尾の要素です。
	*/
	virtual int getXColumnNumberOfBorder( CDcdGridXBorder*	pCDcdGridXBorder ) ;

	/**
	  	  指定されたY列・X列番号の、セルオブジェクト CDcdGridCell のポインタを
	  	取得することができます。このポインタを使って、セルに対する操作を
	  	行うことができます。
	   @param iXColumnNumber [in] 
	  	 X列番号を指定してください。範囲は、0以上 getYColumnCount() 未満です。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @param iYColumnNumber [in] 
	  	 Y列番号を指定してください。範囲は、0以上 getYColumnCount() 未満です。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @return
	  	  対応するセルオブジェクトを返します。
	  	  インデクスが不正な場合は、NULLを返します。
	  
	  	  返されたオブジェクトの破棄の責務は、thisにあります。
	  	  該当するX列が CDcdGrid の別のメソッドによって削除されると、返された
	  	ポインタは無効になります。
	  	   thisが破棄されたときにも、返されたポインタは無効になります。
	 */
	virtual CDcdGridCell*	getCell( int iXColumnNumber , int iYColumnNumber );
 

	/**
		指定の CDcdGridCell オブジェクトの、列番号を返します。
	@param pCDcdGridCell [in]
		CDcdGridCell オブジェクトを指定してください。
	@return
		X列番号を返します。
		オブジェクトが CDcdGrid オブジェクトに集約されていない場合は、
		INT_MIN です。
	*/
	virtual int getXColumnNumberOfCell( 
		CDcdGridCell* pCDcdGridCell ) ;
	/**
		指定の CDcdGridCell オブジェクトの、列番号を返します。
	@param pCDcdGridCell [in]
		CDcdGridCell オブジェクトを指定してください。
	@return
		Y列番号を返します。
		オブジェクトが CDcdGrid オブジェクトに集約されていない場合は、
		INT_MIN です。
	*/
	virtual int getYColumnNumberOfCell( 
		CDcdGridCell* pCDcdGridCell ) ;
	
	///@}

 public:
	
	// ********************************
	///	@name Y列・X列の位置
	// ********************************
	///@{
	/**
	  	Y列の位置を返します。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iYColumnNumber [in]
	  	Y列番号を指定してください。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @return
	  	Y列の範囲を返します。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	  	
	 */
	virtual CdDcdZone	getYColumnZone( 
			IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) ;
	/**
	  	X列の位置を返します。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iXColumnNumber [in]
	  	X列番号を指定してください。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @return
	  	X列の範囲を返します。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual CdDcdZone	getXColumnZone( 
			IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) ;
	
	/**
	  	Y列の下側の境界線の位置を返します。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iYColumnNumber [in]
	  	Y列番号を指定してください。範囲は-1以上 getYColumnCount() 未満です。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @return
	  	Y列の境界線の範囲を返します。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual CdDcdZone	getYColumnBorderZone( 
			IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) ;

	/**
	  	X列の右側の境界線の位置を返します。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iXColumnNumber [in]
	  	X列番号を指定してください。範囲は-1以上 getXColumnCount() 未満です。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @return
	  	X列の境界線の範囲を返します。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual CdDcdZone	getXColumnBorderZone( 
			IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) ;

	/**
	  	セルの位置を返します。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iXColumnNumber [in]
	  	X列番号を指定してください。範囲は0以上 getXColumnCount() 未満です。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @param iYColumnNumber [in]
	  	Y列番号を指定してください。範囲は0以上 getYColumnCount() 未満です。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @return
	  	セルの位置を返します。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual CdDcdZoneXy	getCellZone( 
		IfDcdTarget* pIfDcdTarget , int iXColumnNumber , int iYColumnNumber ) ;

	/**
	  	Y座標に対応する、Y列番号を調べます。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iPos [in]
	  	Y座標を指定してください。
	   @param pbIsBorder [out]
	  	この関数は、 iPos が境界線上にある場合は true 、
	  	 iPos が列の範囲にあるなら false です。
	   @return
	  	Y列番号を返します。
	  
	  	- Y列番号 = -1 , *pbIsBorder=false : グリッドの上の外側です。
		- Y列番号 = -1 , *pbIsBorder=true : グリッドの上の境界線です。
		- Y列番号 = 0 以上 getYColumnCount()未満 , *pbIsBorder = false : 
	  		グリッドのY列範囲です。
	  	- Y列番号 = 0 以上 getYColumnCount()未満 , *pbIsBorder = true : 
	  		グリッドのY列下側の境界線の範囲です。
	  	- Y列番号 = getYColumnCount() , *pbIsBorder = false : 
	  		グリッドの下の外側です。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual int getYColumnNumberOfPos( 
		IfDcdTarget* pIfDcdTarget , int iPos , bool* pbIsBorder ) ;

	/**
	  	X座標に対応する、X列番号を調べます。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iPos [in]
	  	X座標を指定してください。
	   @param pbIsBorder [out]
	  	この関数は、 iPos が境界線上にある場合は true 、
	  	 iPos が列の範囲にあるなら false です。
	   @return
	  	X列番号を返します。
	  
	  	- X列番号 = -1 , *pbIsBorder=false : グリッドの左の外側です。
	  	- X列番号 = -1 , *pbIsBorder=true : グリッドの左の境界線です。
	  	- X列番号 = 0 以上 getXColumnCount()未満 , *pbIsBorder = false : 
	  		グリッドのX列範囲です。
	  	- X列番号 = 0 以上 getXColumnCount()未満 , *pbIsBorder = true : 
	  		グリッドのX列右側の境界線の範囲です。
	  	- X列番号 = getXColumnCount() , *pbIsBorder = false : 
	  		グリッドの右の外側です。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual int getXColumnNumberOfPos( 
		IfDcdTarget* pIfDcdTarget , int iPos , bool* pbIsBorder ) ;


	/**
	  	X,Y 座標に対応する、セルを調べます。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param aCdDcdPosXy [in]
	  	XY座標を指定してください。
	   @return
	  	セルオブジェクトを返します。
	  	指定の座標がセルの範囲に位置していない場合は、NULLを返します。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual CDcdGridCell* getCellOfPos( 
		IfDcdTarget* pIfDcdTarget , const CdDcdPosXy& aCdDcdPosXy ) ;

	///@}
 public:
	// ********************************
	///	@name	スクロール
	// ********************************
	///@{
	
	///@see m_iXFixColumnCount
	virtual int	getXFixColumnCount() ;
	///@see m_iXFixColumnCount
	virtual CDcdGrid& setXFixColumnCount( int ev ) ;
	///@see m_iXFixafterColumnNumber
	virtual int	getXFixafterColumnNumber() ;
	///@see m_iXFixafterColumnNumber
	virtual CDcdGrid& setXFixafterColumnNumber( int ev ) ;
	///@see m_iYFixColumnCount
	virtual int	getYFixColumnCount() ;
	///@see m_iYFixColumnCount
	virtual CDcdGrid& setYFixColumnCount( int ev ) ;
	///@see m_iYFixafterColumnNumber
	virtual int	getYFixafterColumnNumber() ;
	///@see m_iYFixafterColumnNumber
	virtual CDcdGrid& setYFixafterColumnNumber( int ev ) ;
	
	/**
	  	指定の描画領域において、１ページ分のスクロールを行った場合の
	  	 FixafterColumnNumber を求めます。
	  
	  	この関数は、 FixafterColumnNumber が指定した値になっている場合に
	  	おいて、「１ページ分のスクロールをするには、 FixafterColumnNumber 
	  	をいくつに変更すればよいか」を求めます。
	   @param pIfDcdTarget [in]
	  	描画領域を指定してください。
	   @param iFixafterColumnNumber [in]
	  	１ページ分のスクロールを行う場合の基準になる、 FixafterColumnNumber
	  	を指定してください。
	   @param bPagedown [in]
	  	- false ;	//	Pageup方向(-方向)のスクロール
	  	- true ;	//	Pagedown方向(+方向)のスクロール
	   @return 
	  	１ページ分のスクロールを行うための、新しい
	  	 FixafterColumnNumber を返します。@n
	  	bPagedown が真で getXColumnCount() 、
	  	bPagedown が偽で getXFixColumnCount() - 1 の場合、
	  	これ以上のスクロール操作ができないことを示します。
	 */
	int calcXFixafterColumnNumberPagemove( IfDcdTarget* pIfDcdTarget , 
		int iFixafterColumnNumber , bool bPagedown ) ;
	
	/**
	  	指定の描画領域において、１ページ分のスクロールを行った場合の
	  	 FixafterColumnNumber を求めます。
	  
	  	この関数は、 FixafterColumnNumber が指定した値になっている場合に
	  	おいて、「１ページ分のスクロールをするには、 FixafterColumnNumber 
	  	をいくつに変更すればよいか」を求めます。
	   @param pIfDcdTarget [in]
	  	描画領域を指定してください。
	   @param iFixafterColumnNumber [in]
	  	１ページ分のスクロールを行う場合の基準になる、 FixafterColumnNumber
	  	を指定してください。
	   @param bPagedown [in]
	  	- false ;	//	Pageup方向(-方向)のスクロール
	  	- true ;	//	Pagedown方向(+方向)のスクロール
	   @return 
	  	１ページ分のスクロールを行うための、新しい
	  	 FixafterColumnNumber を返します。@n
	  	bPagedown が真で getXColumnCount() 、
	  	bPagedown が偽で getXFixColumnCount() - 1 の場合、
	  	これ以上のスクロール操作ができないことを示します。
	 */
	int calcYFixafterColumnNumberPagemove( IfDcdTarget* pIfDcdTarget , 
		int iFixafterColumnNumber , bool bPagedown ) ;

	/**
	  	Y列の位置を返しますが、スクロール機能によって非表示になっている
	  	Y列（ YFixafterColumnNumber 未満）の位置も返します。この場合、
	  	このY列の位置は、固定Y列に重なったり、グリッドの一番上よりも上に
	  	なることがあります。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iYColumnNumber [in]
	  	Y列番号を指定してください。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @return
	  	Y列の範囲を返します。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual CdDcdZone	getYColumnZoneOverlap( 
			IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) ;
	/**
	  	X列の位置を返しますが、スクロール機能によって非表示になっている
	  	X列（ XFixafterColumnNumber 未満）の位置も返します。この場合、
	  	このX列の位置は、固定X列に重なったり、グリッドの一番左よりも左に
	  	なることがあります。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iXColumnNumber [in]
	  	X列番号を指定してください。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @return
	  	X列の範囲を返します。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual CdDcdZone	getXColumnZoneOverlap( 
			IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) ;

	/**
	  	セルの位置を返しますが、スクロール機能によって非表示になっている
	  	セルの位置も返します。この場合、
	  	このセルの位置は、固定Y列・X列に重なったり、
	  	グリッドの一番左よりも左・一番上よりも上に
	  	なることがあります。
	   @param pIfDcdTarget [in]
	  	描画対象を指定してください。 
	   @param iXColumnNumber [in]
	  	X列番号を指定してください。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @param iYColumnNumber [in]
	  	Y列番号を指定してください。
	  	INT_MAX は、最終列を指定したものとみなします。
	   @return
	  	セルの範囲を返します。
	  
	   @attention
	  	この関数は、createZoneCacneの影響を受けます。
	  	これらの関数 を連続して呼び出す場合は、
	  	前もって createZoneCache() を呼び出すと、
	  	パフォーマンスが改善されます。
	 */
	virtual CdDcdZoneXy	getCellZoneOverlap( 
		IfDcdTarget* pIfDcdTarget , int iXColumnNumber , int iYColumnNumber ) ;
	
	///@}
 public:
	// ********************************
	///	@name	CDcdGrid-操作
	// ********************************
	///@{
	/**
		ある Cell から、指定された XColumn,YColumnの数だけ移動した場所の
		Cell を求めることができます。
		  移動の際は、AttachedCell はスキップして移動します。
		  移動は、先に XColumn ・ 次に YColumn を移動します。
		  CDcdGrid の範囲を越えての移動は行いません。
		範囲を越えての移動をしようとした場合、
		移動先の Cell の ColumnNumber は、 0 ・ 
		または ColumnCount - 1 となります。
	 @param pCDcdGridCell [in]
		移動元のセルを指定してください。
	 @param iXColumnMoveCount [in]
		移動する XColumn の量を指定してください。
		XColumn が 負の数の場合は左への移動、
		正の数の場合は右への移動となります。
	 @param iYColumnMoveCount [in]
		移動する YColumn の量を指定してください。
		YColumn が 負の数の場合は上への移動、
		正の数の場合は下への移動となります。
	 @param bSkipScrolloutColumn [in]
		真なら、ScrolloutColumn を飛び越えて移動します。
		偽なら、ScrolloutColumn へも移動します。
		このとき、必要なら スクロールします
		（FixafterColumnNumber を変更します）。
	 @return 
		移動先のセルを返します。
	 */
	CDcdGridCell* calcMovedCell( CDcdGridCell* pCDcdGridCell , 
		int iXColumnMoveCount , int iYColumnMoveCount ,
		bool bSkipScrolloutColumn = false ) ;


	/**
		列番号 iXColumnNumber 全体を、IfDcdTargetの領域に完全に
		表示することのできる、最小の 
		XFixafterColumnNumber を求めます。
	 @param pIfDcdTarget [in]
		描画対象の pIfDcTarget インターフェースを指定してください。
	 @param iXColumnNumber [in]
		表示を行いたい列の列番号を指定してください。
	 @return 
		列番号 iXColumnNumber に対する
		"XFixafterColumnNumberMinForColumn"
		（列に対する最小のFixafterColumnNumber）を返します。
		この値の最大値は、 iXColumnNumber です。
		FixafterColumnNumnberForColumnNumber が iXColumnNumber に
		等しい場合、FocusCellColumnNumber の列全体がウインドウに
		表示されるとは限りません。
		（列の幅がウインドウのサイズを上回るほど大きい場合が
		これにあたります）@n
		iXColumnNumber が FixColumn の場合は、エラーを示す -1 を返します。
	 */
	int calcXFixafterColumnNumberMinForColumn( 
		IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) ;
	
	/**
		列番号 iYColumnNumber 全体を、IfDcdTargetの領域に完全に
		表示することのできる、最小の 
		YFixafterColumnNumber を求めます。
	 @param pIfDcdTarget [in]
		描画対象の pIfDcTarget インターフェースを指定してください。
	 @param iYColumnNumber [in]
		表示を行いたい列の列番号を指定してください。
	 @return 
		列番号 iYColumnNumber に対する
		"YFixafterColumnNumberMinForColumn"
		（列に対する最小のFixafterColumnNumber）を返します。
		この値の最大値は、 iYColumnNumber です。
		FixafterColumnNumnberForColumnNumber が iYColumnNumber に
		等しい場合、FocusCellColumnNumber の列全体がウインドウに
		表示されるとは限りません。
		（列の幅がウインドウのサイズを上回るほど大きい場合が
		これにあたります）@n
		iYColumnNumber が FixColumn の場合は、エラーを示す -1 を返します。
	 */
	int calcYFixafterColumnNumberMinForColumn(
		IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) ;

	/**
		IfDcdTargetの領域内で全域を表示できている
		最大の ColumnNumber をを求めます。
	 @param pIfDcdTarget [in]
		描画対象の pIfDcTarget インターフェースを指定してください。
	 @return 
		列番号 を返します。
		-	-1 ;	//	全域を表示できている列がひとつもない場合
	 */
	int getXColumnNumberMaxInDcdTarget( 
		IfDcdTarget* pIfDcdTarget ) ;
	
	/**
		IfDcdTargetの領域内で全域を表示できている
		最大の ColumnNumber をを求めます。
	 @param pIfDcdTarget [in]
		描画対象の pIfDcTarget インターフェースを指定してください。
	 @return 
		列番号 を返します。
		-	-1 ;	//	全域を表示できている列がひとつもない場合
	 */
	int getYColumnNumberMaxInDcdTarget( 
		IfDcdTarget* pIfDcdTarget ) ;
	
	///@}

};

} //namespace DcdGrid
} //namespace DcDrawLib

#endif /*CDcdGrid_h*/
