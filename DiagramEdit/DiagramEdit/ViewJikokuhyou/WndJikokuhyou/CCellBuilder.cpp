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
//	ViewJikokuhyou\WndJikokuhyou\CCellBuilder.cpp
//	$Id: CCellBuilder.cpp 366 2016-08-18 20:26:22Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include "CCellBuilder.h"
#include "..\..\resource.h"

namespace ViewJikokuhyou{
namespace WndJikokuhyou{
	using namespace OuLib::Str;
using DcDraw::CDcdTextboxV3 ;

// --------------------------------
//@name 描画処理に使用する テキスト描画属性
// --------------------------------

CdDrawTextProp	CCellBuilder::getCdDrawTextPropMenutext()const
{ 
	CdDedDispProp aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	CConverter_WinGdi	aConv ;
	return CdDrawTextProp( 
		aCdDedDispProp.getJikokuhyouFont(0) ,
		aConv.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
}

CdDrawTextProp	CCellBuilder::getCdDrawTextPropStandard()const
{ 
	CdDedDispProp aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		aCdDedDispProp.getJikokuhyouFont(0) ,
		CdColorProp( 0 , 0 , 0 ) ) ;
}

CdDrawTextProp	CCellBuilder::getCdDrawTextPropTsuuka()const
{ 
	CdDedDispProp aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		aCdDedDispProp.getJikokuhyouFont(0) ,
		CdColorProp( 128 , 128 , 128 ) ,
		CdDrawTextFormat( CdDrawTextFormat::H_CENTER ) ) ;
}

const CdDedJikoku::CConv&	
CCellBuilder::getCdDedJikokuConv()const 
{
	static CdDedJikoku::CConv aConv(
		true ,		//	NoColon 
		// 時が 00 から 09 の場合、10の位の "0" をスペースにします。
		CdDedJikoku::CConv::EHour_ZeroToSpace ,	
		CdDedJikoku::CConv::ESecond_NoSecond 	// 秒を常に出力しません。 
		) ;
	return aConv ;
}
	// --------------------------------
	//@name 描画処理に使用する ブラシ属性
	// --------------------------------

CdBrushProp CCellBuilder::getCdBrushPropMenutext()const
{
	CConverter_WinGdi	aConv ;
	return CdBrushProp( aConv.CdColorPropOfSysColor( COLOR_MENU ) ) ;
}

CdBrushProp	CCellBuilder::getCdBrushPropStandard()const
{
	return CdBrushProp( CdColorProp( 255 , 255 , 255 ) ) ;
}

	// --------------------------------
	//@name 描画処理に使用する DcDrawオブジェクトのプロトタイプ
	// --------------------------------

CDcdTextbox CCellBuilder::createCDcdXColumn0()const
{
	string strExtent = m_pCDedRosenFileData->
		getCdDedDispProp().createEkimeiExtentString() ;
	//strExtent = 路線ファイルデータに保存されている値をもとにして、
	//	作成した、文字列幅の基準文字列です。

	CDcdTextbox aCDcd( 
		"" , 
		getCdDrawTextPropMenutext() ,
		strExtent ,
		1 ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropMenutext() 
	) ;
	return ( aCDcd ) ;
}

CDcdTextboxV3 CCellBuilder::createCDcdXColumn0V()const
{
	string strExtent = m_pCDedRosenFileData->
		getCdDedDispProp().createEkimeiExtentString() ;
	//strExtent = 路線ファイルデータに保存されている値をもとにして、
	//	作成した、文字列幅の基準文字列です。

	CdDedDispProp	aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	CConverter_WinGdi	aConv ;

	CDcdTextboxV3 aCDcd( 
		"" , 
		aCdDedDispProp.getJikokuhyouVFont() ,
		getRessyameiTextExtent().getX() ,
		getRessyameiTextExtent().getY() ,
		aConv.CdColorPropOfSysColor( COLOR_MENUTEXT ) ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropMenutext() ) ;
	return ( aCDcd ) ;
}


CDcdTextbox CCellBuilder::createCDcdEkimei()const
{
	string strExtent = m_pCDedRosenFileData->
		getCdDedDispProp().createEkimeiExtentString() ;
	//strExtent = 路線ファイルデータに保存されている値をもとにして、
	//	作成した、文字列幅の基準文字列です。

	CDcdTextbox aCDcd( 
		"" , 
		getCdDrawTextPropStandard() ,
		strExtent ,
		1 ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropStandard() ) ;
	return ( aCDcd ) ;
}


CDcdTextbox CCellBuilder::createCDcdHatsuchaku()const
{
	string strExtent = MfcUtil::LoadCString( IDS_WORD_Chaku );

	//strExtent = 路線ファイルデータに保存されている値をもとにして、
	//	作成した、文字列幅の基準文字列です。


	CDcdTextbox aCDcd( 
		"" , 
		getCdDrawTextPropStandard() ,
		strExtent ,
		1 ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropStandard() ) ;
	return ( aCDcd ) ;
}

CDcdTextbox CCellBuilder::createCDcdRessyabangou(
	int iRessyasyubetsuIndex )const
{
	CdDedDispProp	aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;
	string strCellExtent( aCdDedDispProp.getJikokuhyouRessyaWidth() , '0' ) ;
	//strCellExtent = セルの大きさの目安となる文字列です。
	//	時刻表列車セルの幅(文字数) CdDedDispProp::m_iJikokuhyouRessyaWidth
	//	の数だけ '0' が並んだ文字列です

	const CentDedRessyasyubetsu* pCentDedRessyasyubetsu
		= m_pCDedRosenFileData->getCentDedRosen()->getCentDedRessyasyubetsuCont()
		->getMuPtr()->get( iRessyasyubetsuIndex ) ;
	
	CdDrawTextProp aCdDrawTextProp = getCdDrawTextPropStandard() ;

	aCdDrawTextProp.setCdDrawTextFormat( CdDrawTextFormat( CdDrawTextFormat::H_CENTER ) ) ;
	aCdDrawTextProp.setTextColor( 
		pCentDedRessyasyubetsu->getJikokuhyouMojiColor() ) ;


	CDcdTextbox aCDcd( 
		"" , 
		aCdDrawTextProp ,
		strCellExtent ,
		1 ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropStandard() ) ;
	return ( aCDcd ) ;
}

CDcdTextboxV3 CCellBuilder::createCDcdRessyamei(
	int iRessyasyubetsuIndex )const
{
	const CentDedRessyasyubetsu* pCentDedRessyasyubetsu
		= m_pCDedRosenFileData->getCentDedRosen()->getCentDedRessyasyubetsuCont()
		->getMuPtr()->get( iRessyasyubetsuIndex ) ;

	CdDedDispProp	aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	CDcdTextboxV3 aCDcd( 
		"" , 
		aCdDedDispProp.getJikokuhyouVFont(),
		getRessyameiTextExtent().getX() ,
		getRessyameiTextExtent().getY() ,
		pCentDedRessyasyubetsu->getJikokuhyouMojiColor() ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropStandard() ) ;
	return ( aCDcd ) ;
}

CDcdTextbox CCellBuilder::createCDcdEkijikoku(
	int iRessyasyubetsuIndex )const
{
	const CentDedRessyasyubetsu* pCentDedRessyasyubetsu
		= m_pCDedRosenFileData->getCentDedRosen()->getCentDedRessyasyubetsuCont()
		->getMuPtr()->get( iRessyasyubetsuIndex ) ;
	int idxFont = pCentDedRessyasyubetsu->getJikokuhyouFontIndex() ;
	

	CDcdTextbox aCDcd 
		= createCDcdRessyabangou( iRessyasyubetsuIndex ) ;
		
	CdDrawTextProp	aCdDrawTextProp = aCDcd.getCdDrawTextProp() ;
	aCdDrawTextProp.setCdFontProp(
		m_pCDedRosenFileData
			->getCdDedDispProp().getJikokuhyouFont( idxFont ) ) ;
	aCDcd.setCdDrawTextProp( aCdDrawTextProp ) ;

	return ( aCDcd ) ;
}

	// --------------------------------
	//@name update() の下請関数
	// --------------------------------
void CCellBuilder::update01_updateWithoutRessya(
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// ********************************
	//(1.1)　CWndDcdGrid の外枠線のDcDrawオブジェクトと、列幅を設定
	// ********************************
	update01_01_setGridBorder( 
		pCWndJikokuhyou ) ;


	// ********************************
	//(1.2)　列の数を設定します。
	//	X列数が2未満なら2にします。
	//	Y列数は、CdYColSpecCont で
	//	導出された列数とします。
	// ********************************
	{
		int iXColumnNumberMax = -1 ;
		{
			int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Ekimei ) ) ;
			iXColumnNumberMax = max( iXColumnNumberMax , iXColumnNumber ) ;
		}
		{
			int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Chakuhatsu ) ) ;
			iXColumnNumberMax = max( iXColumnNumberMax , iXColumnNumber ) ;
		}

		pCDcdGrid->setXColumnCount( max( iXColumnNumberMax + 1 , 
			pCDcdGrid->getXColumnCount() ) ) ;
		pCDcdGrid->setYColumnCount( m_CdYColSpecCont.size() ) ;
	}
 
	// ********************************
	//(1.3)　X列(ColumnType_Ekimei) の各セルと、すべてのY列の高さ・
	//	Y列境界線・Y列境界線の高さ設定
	// ********************************
	{
		CdXColSpec aCdXColSpec( 
			CdXColSpec::ColumnType_Ekimei ) ;
		int iXColumnNumber = 
			m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

		// ================================
		//(1.3.1)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) と、
		//	Y列(ColumnType_Ressyabangou)の高さ・Y列境界線・Y列境界線の高さ設定
		// ================================
		update01_03_01_setEkimei_Ressyabangou( 
			pCWndJikokuhyou ) ;

		// ================================
		//	(1.3.2)　同様に、セル(ColumnType_Ekimei, 
		//	ColumnType_Ressyasyubetsu〜 ColumnType_Bikou ) と、
		//	Y列(ColumnType_Ressyasyubetsu〜 ColumnType_Bikou)の高さ・
		//	Y列境界線・Y列境界線の高さを設定。
		// ================================
		// --------------------------------
		//	(1.3.2.2)セル(ColumnType_Ekimei, ColumnType_Ressyasyubetsu)
		// --------------------------------
		update01_03_02_02_setEkimei_Ressyasyubetsu( 
			pCWndJikokuhyou ) ;

		// --------------------------------
		//	(1.3.2.3)セル(ColumnType_Ekimei, ColumnType_Ressyamei)
		// --------------------------------
		update01_03_02_03_setEkimei_Ressyamei( 
			pCWndJikokuhyou ) ;


		// --------------------------------
		//	(1.3.2.4)セル(ColumnType_Ekimei, ColumnType_Gousuu)
		// --------------------------------
		update01_03_02_04_setEkimei_Gousuu( 
			pCWndJikokuhyou ) ;

		
		// --------------------------------
		//	(1.3.2.5)セル(ColumnType_Ekimei, ColumnType_Gou)
		// --------------------------------
		update01_03_02_05_setEkimei_Gou( 
			pCWndJikokuhyou ) ;

		
		// --------------------------------
		//	セル(ColumnType_Ekimei,ColumnType_Ekijikoku_Chaku)
		//	セル(ColumnType_Ekimei,ColumnType_Ekijikoku_Hatsu)
		// --------------------------------
		update01_03_02_06_setEkimei_Chaku( 
			pCWndJikokuhyou ) ;
		update01_03_02_07_setEkimei_Hatsu( 
			pCWndJikokuhyou ) ;
		
		// --------------------------------
		//	(1.3.2.8)セル(ColumnType_Ekimei,ColumnType_Bikou)
		// --------------------------------
		update01_03_02_08_setEkimei_Bikou( 
			pCWndJikokuhyou ) ;
		
		// ================================
		//(1.3.3)　X列(ColumnType_Ekimei ) の幅を設定。
		//	幅は、駅名列の DcDraw オブジェクトの幅とします。
		// ================================
		CDcdGridXColumn* pCDcdGridXColumn = pCDcdGrid->getXColumn( 
			iXColumnNumber ) ;
		if ( pCDcdGridXColumn )
		{
			CDcdTextbox aCDcdTextbox =createCDcdXColumn0() ;
			CdDcdSizeXy aCdDcdSizeXy ;
			if ( aCDcdTextbox.getItemSize( 
				&aCDcdTarget , &aCdDcdSizeXy ) )
			{
				pCDcdGridXColumn->setColumnSize( aCdDcdSizeXy.getX() ) ;
			}
		}
		// ================================
		//	(1.3.4)　X列(ColumnType_Ekimei ) の境界線の DcDrawオブジェクトの
		//	属性を設定。
		//	(1.3.5)　X列(ColumnType_Ekimei ) の境界線の幅を設定。
		// ================================
		{
			CDcdGridXBorder* pCDcdGridXBorder 
				= pCDcdGridXColumn->getCDcdGridXBorder() ;
			Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw() ;

			pCDcdLine->setCdPenProp( CdPenProp() ) ;	//NULLPEN

			CdDcdSizeXy aCdDcdSizeXy ;
			if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
			{
				pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
			}
		}
	}

	// ********************************
	//(1.4)　X列(ColumnType_Chakuhatsu) の各セルを設定
	// ********************************
	{
		CdXColSpec aCdXColSpec( 
			CdXColSpec::ColumnType_Chakuhatsu ) ;
		int iXColumnNumber = 
			m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
		// ================================
		//(1.4.1)　セル(ColumnType_Chakuhatsu, 
		//	ColumnType_Ekijikoku_Chaku〜 ColumnType_Ekijikoku_Hatsu) を設定。
		// ================================
		update01_04_01_06_setChakuhatsu_Chaku( 
			pCWndJikokuhyou ) ;
		update01_04_01_07_setChakuhatsu_Hatsu( 
			pCWndJikokuhyou ) ;
		// ================================
		//	(1.4.3)　X列(ColumnType_Chakuhatsu ) の幅を設定。
		//	幅は、着発列の DcDraw オブジェクトの幅とします。
		// ================================
		CDcdGridXColumn* pCDcdGridXColumn = pCDcdGrid->getXColumn( 
			iXColumnNumber ) ;
		if ( pCDcdGridXColumn )
		{
			CDcdTextbox aCDcdTextbox = 
				createCDcdHatsuchaku() ;
			CdDcdSizeXy aCdDcdSizeXy ;
			if ( aCDcdTextbox.getItemSize( 
				&aCDcdTarget , &aCdDcdSizeXy ) )
			{
				pCDcdGridXColumn->setColumnSize( aCdDcdSizeXy.getX() ) ;
			}
		}

		// ================================
		//	(1.4.4)　X列(ColumnType_Chakuhatsu ) の境界線の 
		//	DcDrawオブジェクトの属性を設定。
		//(1.4.5)　X列(ColumnType_Chakuhatsu ) の境界線の幅を設定。
		// ================================
		{
			CDcdGridXBorder* pCDcdGridXBorder 
				= pCDcdGridXColumn->getCDcdGridXBorder() ;
			Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw() ;

			pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;	

			CdDcdSizeXy aCdDcdSizeXy ;
			if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
			{
				pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
			}
		}
	}
}

void CCellBuilder::update01_01_setGridBorder( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;


	//	左
	{
		CDcdGridXBorder* pCDcdGridXBorder = pCDcdGrid->getCDcdGridXBorderTop() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw();
		pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
		}
	}
	//	右
	{
		CDcdGridXBorder* pCDcdGridXBorder 
			= pCDcdGrid->getCDcdGridXBorderBottom() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw();
		pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
		}
	}
	//	上
	{
		CDcdGridYBorder* pCDcdGridYBorder = pCDcdGrid->getCDcdGridYBorderTop() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw();
		pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridYBorder->setColumnBorderSize( aCdDcdSizeXy.getY() ) ;
		}
	}
	//	下
	{
		CDcdGridYBorder* pCDcdGridYBorder 
			= pCDcdGrid->getCDcdGridYBorderBottom() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw();
		pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridYBorder->setColumnBorderSize( aCdDcdSizeXy.getY() ) ;
		}
	}
}

void CCellBuilder::update01_03_01_setEkimei_Ressyabangou( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ressyabangou ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != 0 )
		{
			//(1.3.*.1)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	の結合セルの属性を設定。
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	のDcDrawオブジェクトの型を設定
			//	( CDcdTextbox とする)。
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}

			//(1.3.*.3)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	DcDrawオブジェクトに、属性を設定。
			{
				*pCDcDrawCell = createCDcdXColumn0() ;
				pCDcDrawCell->setText( stringOf( 
					(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_Ressyabangou ) ) ) ;
			}
		}

		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn )
		{
			//(1.3.*.4)　Y列(ColumnType_Ressyabangou) のセルの高さを設定
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;
				}
			}
			//	　(1.3.*.5)　Y列(ColumnType_Ressyabangou) の境界線の
			//	DcDrawオブジェクト に属性を設定。
			//	　(1.3.*.6)　Y列ColumnType_Ressyabangou) の境界線の
			//	高さを設定
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNarrowLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}


void CCellBuilder::update01_03_02_02_setEkimei_Ressyasyubetsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;


	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ressyasyubetsu ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)　結合セルの属性を設定。
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)　セル 
			//	のDcDrawオブジェクトの型を設定
			//	( CDcdTextbox とする)。
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)　セルの DcDrawオブジェクトに、属性を設定。
			{
				*pCDcDrawCell = createCDcdXColumn0() ;
				pCDcDrawCell->setText( stringOf( 
					(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_RESSYASYUBETSU ) ) ) ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)　Y列 のセルの高さを設定
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;					}
			}
			//	　(1.3.*.5)　Y列 の境界線の
			//	DcDrawオブジェクト に属性を設定。
			//	　(1.3.*.6)　Y列 の境界線の
			//	高さを設定
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNarrowLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}


void CCellBuilder::update01_03_02_03_setEkimei_Ressyamei( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ressyamei ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextboxV3 CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)　結合セルの属性を設定。
			pCDcdGridCell->setAttachCellCount( 2 , 3 ) ;

			//	(1.3.*.2)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	のDcDrawオブジェクトの型を設定
			//	( CDcdTextbox とする)。
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	DcDrawオブジェクトに、属性を設定。
			{
				*pCDcDrawCell = createCDcdXColumn0V() ;
				pCDcDrawCell->setText( stringOf( 
					(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_Ressyamei ) ) ) ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)　Y列 のセルの高さを設定
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;					}
			}
			//	　(1.3.*.5)　Y列 の境界線の
			//	DcDrawオブジェクト に属性を設定。
			//	　(1.3.*.6)　Y列 の境界線の
			//	高さを設定
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}


void CCellBuilder::update01_03_02_04_setEkimei_Gousuu( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Gousuu ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)　結合セルの属性を設定。
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)　セルのDcDrawオブジェクトの型を設定
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)　セルのDcDrawオブジェクトに、属性を設定。
			{
				*pCDcDrawCell = createCDcdXColumn0() ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)　Y列 のセルの高さを設定
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;					}
			}
			//	　(1.3.*.5)　Y列 の境界線の
			//	DcDrawオブジェクト に属性を設定。
			//	　(1.3.*.6)　Y列 の境界線の
			//	高さを設定
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}


void CCellBuilder::update01_03_02_05_setEkimei_Gou( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Gou ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)　結合セルの属性を設定。
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)　セルのDcDrawオブジェクトの型を設定
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)　セルのDcDrawオブジェクトに、属性を設定。
			{
				*pCDcDrawCell = createCDcdXColumn0() ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)　Y列 のセルの高さを設定
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;					}
			}
			//	　(1.3.*.5)　Y列 の境界線の
			//	DcDrawオブジェクト に属性を設定。
			//	　(1.3.*.6)　Y列 の境界線の
			//	高さを設定
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNarrowLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}

void CCellBuilder::update01_03_02_06_setEkimei_Chaku( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		m_pCentDedRessyaCont->getRessyahoukou() ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
	if ( iXColumnNumber >= 0 )
	{
		for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; 
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

			CdYColSpec aCdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Chaku , 
				iEkiOrder ) ;
			int iYColumnNumber = 
				m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
			CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
				iXColumnNumber , iYColumnNumber ) ;

			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			if ( pCDcdGridCell != 0 )
			{
				//(1.3.*.1)　セルの結合セルの属性を設定。
				
				//	この列が着で、次の列が発なら、次の列を結合
				CdYColSpec aCdYColSpecNext  
					= m_CdYColSpecCont.ColumnNumberToSpec( iYColumnNumber + 1 ) ;
				if ( aCdYColSpec.getColumnType() 
						== aCdYColSpec.ColumnType_Ekijikoku_Chaku
					&& aCdYColSpecNext.getColumnType() 
						== aCdYColSpecNext.ColumnType_Ekijikoku_Hatsu
					&& aCdYColSpec.getEkiOrder() 
						== aCdYColSpecNext.getEkiOrder() )
				{
					pCDcdGridCell->setAttachCellCount( 1 , 2 ) ;
				}
				else
				{
					pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;
				}

				//	(1.3.*.2)　セルのDcDrawオブジェクトの型を設定
				//	( CDcdTextbox とする)。
				{
					pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
						pCDcdGridCell->getIfDcDraw() ) ;
					if ( pCDcDrawCell == NULL )
					{
						pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
						pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
					}
				}
				//(1.3.*.3)　セルのDcDrawオブジェクトに、属性を設定。
				{
					*pCDcDrawCell = createCDcdEkimei() ;
					pCDcDrawCell->setText( aCdDedEki.getEkimei() );
				}
			}
			CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
				iYColumnNumber ) ;
			if ( pCDcdGridYColumn )
			{
				//(1.3.*.4)　Y列のセルの高さを設定
				{
					CdDcdSizeXy aCdDcdSizeXy ;
					if ( pCDcDrawCell->getItemSize( 
						&aCDcdTarget , &aCdDcdSizeXy ) )
					{
						pCDcdGridYColumn->setColumnSize( 
							aCdDcdSizeXy.getY() ) ;
					}
				}
				//	　(1.3.*.5)　Y列(ColumnType_Ressyabangou) の境界線の
				//	DcDrawオブジェクト に属性を設定。
				//	　(1.3.*.6)　Y列ColumnType_Ressyabangou) の境界線の
				//	高さを設定
				{
					CDcdGridYBorder* pCDcdGridYBorder 
						= pCDcdGridYColumn->getCDcdGridYBorder() ;
					Ou<CDcdLine> pCDcdLine = 
						pCDcdGridYBorder->getIfDcDraw() ;

					//	この駅の駅時刻形式が「着発」 AND
					//	この列が着で、次の列が発なら、下に罫線
					CdYColSpec aCdYColSpecNext  
						= m_CdYColSpecCont.ColumnNumberToSpec( 
							iYColumnNumber + 1 ) ;
					if ( aCdDedEki.getChakujikokuHyouji() &&
						aCdDedEki.getHatsujikokuHyouji() &&
						aCdYColSpec.getColumnType() 
							== aCdYColSpec.ColumnType_Ekijikoku_Chaku && 
						aCdYColSpecNext.getColumnType() 
							== aCdYColSpecNext.ColumnType_Ekijikoku_Hatsu && 
						aCdYColSpec.getEkiOrder() 
							== aCdYColSpecNext.getEkiOrder() )
					{
						pCDcdLine->setCdPenProp( 
							getCdPenPropNarrowLine() ) ;
					}
					//	次の列が異なる駅の列。 AND
					//	当駅に『境界線』属性がある。
					//
					//	これら条件を満たす場合は、
					//	下（次の駅との間）に罫線
					else if ( aCdYColSpecNext.isEkiJikoku() 
						&& aCdYColSpec.getEkiOrder() 
							!= aCdYColSpecNext.getEkiOrder() 
						&& aCdDedEki.getKyoukaisen() ) 
					{
						pCDcdLine->setCdPenProp( 
							getCdPenPropNarrowLine() ) ;
					}
					//	次の列が駅時刻以外の場合は、太線
					else if ( !aCdYColSpecNext.isEkiJikoku() )
					{
						pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;
					}
					else
					{
						pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;
					}

					// --------------------------------
					//	線の幅から、列幅を設定
					CdDcdSizeXy aCdDcdSizeXy ;
					if ( pCDcdLine->getItemSize( 
						&aCDcdTarget , &aCdDcdSizeXy ) )
					{
						pCDcdGridYBorder->setColumnBorderSize( 
							aCdDcdSizeXy.getX() ) ;
					}
				}
			}
		}
	}
}

void CCellBuilder::update01_03_02_07_setEkimei_Hatsu( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		m_pCentDedRessyaCont->getRessyahoukou() ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
	if ( iXColumnNumber >= 0 )
	{
		for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; 
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

			CdYColSpec aCdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
				iEkiOrder ) ;
			int iYColumnNumber = 
				m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
			CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
				iXColumnNumber , iYColumnNumber ) ;

			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			if ( pCDcdGridCell != 0 )
			{
				//(1.3.*.1)　セルの結合セルの属性を設定。
				
				pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

				//	(1.3.*.2)　セルのDcDrawオブジェクトの型を設定
				//	( CDcdTextbox とする)。
				{
					pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
						pCDcdGridCell->getIfDcDraw() ) ;
					if ( pCDcDrawCell == NULL )
					{
						pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
						pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
					}
				}
				//(1.3.*.3)　セルのDcDrawオブジェクトに、属性を設定。
				{
					*pCDcDrawCell = createCDcdEkimei() ;
					pCDcDrawCell->setText( aCdDedEki.getEkimei() );
				}
			}

			CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
				iYColumnNumber ) ;
			if ( pCDcdGridYColumn )
			{
				//(1.3.*.4)　Y列のセルの高さを設定
				{
					CdDcdSizeXy aCdDcdSizeXy ;
					if ( pCDcDrawCell->getItemSize( 
						&aCDcdTarget , &aCdDcdSizeXy ) )
					{
						pCDcdGridYColumn->setColumnSize( 
							aCdDcdSizeXy.getY() ) ;
					}
				}
				//	　(1.3.*.5)　Y列(ColumnType_Ressyabangou) の境界線の
				//	DcDrawオブジェクト に属性を設定。
				//	　(1.3.*.6)　Y列ColumnType_Ressyabangou) の境界線の
				//	高さを設定
				{
					CDcdGridYBorder* pCDcdGridYBorder 
						= pCDcdGridYColumn->getCDcdGridYBorder() ;
					Ou<CDcdLine> pCDcdLine = 
						pCDcdGridYBorder->getIfDcDraw() ;

					CdYColSpec aCdYColSpecNext  
						= m_CdYColSpecCont.ColumnNumberToSpec( 
							iYColumnNumber + 1 ) ;
					//	次の列が異なる駅の列。
					//	当駅に『境界線』属性がある。
					//
					//	これら条件を満たす場合は、
					//	下（次の駅との間）に罫線
					if ( aCdYColSpecNext.isEkiJikoku() 
						&& aCdYColSpec.getEkiOrder() 
							!= aCdYColSpecNext.getEkiOrder() 
						&& aCdDedEki.getKyoukaisen() ) 
					{
						pCDcdLine->setCdPenProp( 
							getCdPenPropNarrowLine() ) ;
					}
					//	次の列が駅時刻以外の場合は、太線
					else if ( !aCdYColSpecNext.isEkiJikoku() )
					{
						pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;
					}
					else
					{
						pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;
					}

					// --------------------------------
					//	線の幅から、列幅を設定
					CdDcdSizeXy aCdDcdSizeXy ;
					if ( pCDcdLine->getItemSize( 
						&aCDcdTarget , &aCdDcdSizeXy ) )
					{
						pCDcdGridYBorder->setColumnBorderSize( 
							aCdDcdSizeXy.getX() ) ;
					}
				}
			}
		}
	}
}

void CCellBuilder::update01_03_02_08_setEkimei_Bikou( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Bikou ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextboxV3 CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)　結合セルの属性を設定。
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	のDcDrawオブジェクトの型を設定
			//	( CDcdTextbox とする)。
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)　セル(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	DcDrawオブジェクトに、属性を設定。
			{
				*pCDcDrawCell = createCDcdXColumn0V() ;
				pCDcDrawCell->setLinesExtentX ( getBikouTextExtent().getX() ) ;
				pCDcDrawCell->setLinesExtentY ( getBikouTextExtent().getY() ) ;
				pCDcDrawCell->setText( stringOf( 
					(LPCTSTR)MfcUtil::LoadCString( 
					IDS_WORD_Bikou ) ) ) ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)　Y列 のセルの高さを設定
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;
				}
			}
			//	　(1.3.*.5)　Y列 の境界線の
			//	DcDrawオブジェクト に属性を設定。
			//	　(1.3.*.6)　Y列 の境界線の
			//	高さを設定
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}

void CCellBuilder::update01_04_01_06_setChakuhatsu_Chaku( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		m_pCentDedRessyaCont->getRessyahoukou() ) ;
	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Chakuhatsu ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
	if ( iXColumnNumber >= 0 )
	{
		for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; 
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

			CdYColSpec aCdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Chaku , 
				iEkiOrder ) ;
			int iYColumnNumber = 
				m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
			CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
				iXColumnNumber , iYColumnNumber ) ;

			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			if ( pCDcdGridCell != 0 )
			{
				//(1.4.1.*.1)　セルの結合セルの属性を設定。
				pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;
			
				//	(1.4.1.*.2)　セルのDcDrawオブジェクトの型を設定
				//	( CDcdTextbox とする)。
				{
					pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
						pCDcdGridCell->getIfDcDraw() ) ;
					if ( pCDcDrawCell == NULL )
					{
						pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
						pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
					}
				}
				//(1.4.1.*.3)　セルのDcDrawオブジェクトに、属性を設定。
				{
					*pCDcDrawCell = createCDcdHatsuchaku();
					pCDcDrawCell->setText( stringOf( 
						(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_Chaku ) ) );
				}
			}
		}
	}
	
}
void CCellBuilder::update01_04_01_07_setChakuhatsu_Hatsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		m_pCentDedRessyaCont->getRessyahoukou() ) ;
	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Chakuhatsu ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
	if ( iXColumnNumber >= 0 )
	{
		for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; 
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

			CdYColSpec aCdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
				iEkiOrder ) ;
			int iYColumnNumber = 
				m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
			CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
				iXColumnNumber , iYColumnNumber ) ;

			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			if ( pCDcdGridCell != 0 )
			{
				//(1.4.1.*.1)　セルの結合セルの属性を設定。
				pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;
			
				//	(1.4.1.*.2)　セルのDcDrawオブジェクトの型を設定
				//	( CDcdTextbox とする)。
				{
					pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
						pCDcdGridCell->getIfDcDraw() ) ;
					if ( pCDcDrawCell == NULL )
					{
						pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
						pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
					}
				}
				//(1.4.1.*.3)　セルのDcDrawオブジェクトに、属性を設定。
				{
					*pCDcDrawCell = createCDcdHatsuchaku();
					pCDcDrawCell->setText( stringOf( 
						(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_Hatsu ) ) );
				}
			}
		}
	}
}


void CCellBuilder::update02_02_updateRessya( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// ================================
	//　(2.2.1)　セル(ColumnType_Ressya ,
	//	ColumnType_Ressyabangou) を設定
	// ================================
	update02_02_01_setRessya_Ressyabangou( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;

	// ================================
	//　(2.2.2)　同様に、セル(ColumnType_Ressya, 
	//	ColumnType_Ressyasyubetsu〜 ColumnType_Bikou ) を設定。
	// ================================

	// --------------------------------
	//	(2.2.2.2)セル(ColumnType_Ressya, ColumnType_Ressyasyubetsu)
	// --------------------------------
	update02_02_02_02_setRessya_Ressyasyubetsu( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;

	// --------------------------------
	//	(2.2.2.3)セル(ColumnType_Ressya, ColumnType_Ressyamei)
	// --------------------------------
	update02_02_02_03_setRessya_Ressyamei( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;

	// --------------------------------
	//	(2.2.2.4)セル(ColumnType_Ressya, ColumnType_Gousuu)
	// --------------------------------
	update02_02_02_04_setRessya_Gousuu( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;


	// --------------------------------
	//	(2.2.2.5)セル(ColumnType_Ressya, ColumnType_Gou)
	// --------------------------------
	update02_02_02_05_setRessya_Gou( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;


	// --------------------------------
	//	(2.2.2.6)セル(ColumnType_Ressya,ColumnType_Ekijikoku_Chaku)
	//	(2.2.2.7)セル(ColumnType_Ressya,ColumnType_Ekijikoku_Hatsu)
	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		pCentDedRessya->getRessyahoukou() ) ;
	for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; iEkiOrder ++ )
	{
		update02_02_02_06_setRessya_Chaku( 
			iXColumnNumber , 
			pCentDedRessya ,
			iEkiOrder , 
			pCWndJikokuhyou ) ;
		update02_02_02_07_setRessya_Hatsu( 
			iXColumnNumber , 
			pCentDedRessya ,
			iEkiOrder , 
			pCWndJikokuhyou ) ;
	}
	// --------------------------------
	//	(2.2.2.8)セル(ColumnType_Ressya,ColumnType_Bikou)
	// --------------------------------
	update02_02_02_08_setRessya_Bikou( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;

	// ================================
	//　(2.2.3)　X列(ColumnType_Ressya ) の幅を設定。
	//	幅は、駅時刻列の DcDraw オブジェクトの幅とします。
	// ================================
	CDcdGridXColumn* pCDcdGridXColumn 
		= pCDcdGrid->getXColumn( iXColumnNumber ) ;
	{
		{
			CDcdGridCell* pCDcdGridCell 
				= pCDcdGrid->getCell( iXColumnNumber , 0 ) ;
			CdDcdSizeXy	aCdDcdSizeXy ;
			if ( pCDcdGridCell->getIfDcDraw()->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) ){
				pCDcdGridXColumn->setColumnSize( aCdDcdSizeXy.getX() ) ;
			}
		}
	}

	// ================================
	//　(2.2.4)　X列(ColumnType_Ressya ) の境界線の 
	//	DcDrawオブジェクトの属性を設定。
	//　(2.2.5)　X列(ColumnType_Ressya ) の境界線の幅を設定。
	// ================================
	{
		CDcdGridXBorder* pCDcdGridXBorder 
			= pCDcdGridXColumn->getCDcdGridXBorder() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw() ;

		pCDcdLine->setCdPenProp( getCdPenPropNarrowLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
		}
	}
	// ================================
	//	X列を再描画領域とします。
	// ================================
	{
		CdDcdZoneXy	aCdDcdZoneXy ;
		//X列の範囲
		{
			CdDcdZone	zoneXColumnZone = pCDcdGrid->getXColumnZone( 
				&aCDcdTarget , 
				iXColumnNumber ) ;
			CdDcdZone	zoneXColumnBorderZone = pCDcdGrid->getXColumnBorderZone( 
				&aCDcdTarget , 
				iXColumnNumber ) ;
			
			aCdDcdZoneXy.setX( 
				zoneXColumnZone.ZoneOr( zoneXColumnBorderZone ) ) ;
		}
		//Y列の範囲
		{
			CdDcdZone	zoneYColumnTop = pCDcdGrid->getYColumnZone( 
				&aCDcdTarget , 
				0 ) ;
			CdDcdZone	zoneYColumnBottom = pCDcdGrid->getYColumnZone( 
				&aCDcdTarget , 
				INT_MAX ) ;
			aCdDcdZoneXy.setY( 
				zoneYColumnTop.ZoneOr( zoneYColumnBottom ) ) ;
		}
		CConverter_WinGdi	aConv ;
		pCWndJikokuhyou->InvalidateRect( 
			&aConv.RECTOf( aCdDcdZoneXy ) ) ; 
	}
}

void CCellBuilder::update02_02_01_setRessya_Ressyabangou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Ressyabangou ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	CdDedDispProp	aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;
	string strCellExtent( aCdDedDispProp.getJikokuhyouRessyaWidth() , '0' ) ;
	//strCellExtent = セルの大きさの目安となる文字列です。
	//	時刻表列車セルの幅(文字数) CdDedDispProp::m_iJikokuhyouRessyaWidth
	//	の数だけ '0' が並んだ文字列です

	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//　(2.2.*.1)　セル(ColumnType_Ressya,ColumnType_Ressyabangou) の
		//	結合セルを設定
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//　(2.2.*.2)　セル の	DcDrawオブジェクトの型を設定
		//	( CDcdTextbox とする)。
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}

		//　(2.2.*.3)　セルの DcDrawオブジェクトに、属性を設定。
		{
			int idxRessyasyubetsu 
					= pCentDedRessya->getRessyasyubetsuIndex() ;
			string strText = pCentDedRessya->getRessyabangou() ;
			
			*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu ) ;
			pCDcDrawCell->setText( strText );
		}
	}
}


void CCellBuilder::update02_02_02_02_setRessya_Ressyasyubetsu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Ressyasyubetsu ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//　(2.2.*.1)　セル(ColumnType_Ressya,ColumnType_Ressyabangou) の
		//	結合セルを設定
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//　(2.2.*.2)　セル の	DcDrawオブジェクトの型を設定
		//	( CDcdTextbox とする)。
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}

		//　(2.2.*.3)　セルの DcDrawオブジェクトに、属性を設定。
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;
			const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = NULL ;
			{
				pCentDedRessyasyubetsu = 
					pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr()
						->get( idxRessyasyubetsu ) ;
				if ( pCentDedRessyasyubetsu == NULL )
				{
					pCentDedRessyasyubetsu = 
						pCentDedRosen->getCentDedRessyasyubetsuCont()
						->getMuPtr()->get( 0 ) ;
				}
			}
			//pCentDedRessyasyubetsu = 列車種別オブジェクト
			//	(指定がないなら、列車種別[0])

			string strText ;
			if ( !pCentDedRessya->isNull() )
			{
				strText = pCentDedRessyasyubetsu->getRyakusyou() ;
			}
			*pCDcDrawCell = createCDcdEkijikoku( idxRessyasyubetsu );
			pCDcDrawCell->setText( strText );
		}
	}

}
	
void CCellBuilder::update02_02_02_03_setRessya_Ressyamei( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Ressyamei ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextboxV3 CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//　(2.2.*.1)　セル(ColumnType_Ressya,ColumnType_Ressyabangou) の
		//	結合セルを設定
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//　(2.2.*.2)　セル の	DcDrawオブジェクトの型を設定
		//	( CDcdTextbox とする)。
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}
		//　(2.2.*.3)　セルの DcDrawオブジェクトに、属性を設定。
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;
			string strText ;
			if ( !pCentDedRessya->isNull() )
			{
				strText = pCentDedRessya->getRessyamei() ;
			}
			*pCDcDrawCell = createCDcdRessyamei( idxRessyasyubetsu );
			pCDcDrawCell->setText( strText );
		}
	}


}
	
void CCellBuilder::update02_02_02_04_setRessya_Gousuu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Gousuu ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//　(2.2.*.1)　セル(ColumnType_Ressya,ColumnType_Ressyabangou) の
		//	結合セルを設定
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//　(2.2.*.2)　セル の	DcDrawオブジェクトの型を設定
		//	( CDcdTextbox とする)。
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}
		//　(2.2.*.3)　セルの DcDrawオブジェクトに、属性を設定。
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;
			string strText = pCentDedRessya->getGousuu() ;
			*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
			pCDcDrawCell->setText( strText );
		}
	}
}
	
void CCellBuilder::update02_02_02_05_setRessya_Gou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Gou ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//　(2.2.*.1)　セルの結合セルを設定
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//　(2.2.*.2)　セル の	DcDrawオブジェクトの型を設定
		//	( CDcdTextbox とする)。
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}
		//　(2.2.*.3)　セルの DcDrawオブジェクトに、属性を設定。
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;

			CString	strText ;
			if ( !pCentDedRessya->getGousuu().empty() )
			{
				strText.LoadString( IDS_WORD_GOUSUU2 ) ;
			}

			*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
			pCDcDrawCell->setText( (LPCTSTR)strText );
		}
	}
}

void CCellBuilder::update02_02_02_06_setRessya_Chaku( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		int iEkiOrder ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		pCentDedRosen->getCentDedEkiCont()->getMuPtr(
			pCentDedRessya->getRessyahoukou() ) ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ekijikoku_Chaku , 
			iEkiOrder ) ;
		int iYColumnNumber = 
			m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;
		// --------------------------------
		if ( pCDcdGridCell != 0 )
		{
			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			// --------------------------------
			//　(2.2.*.1)　セルの結合セルを設定
			pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

			//　(2.2.*.2)　セル の	DcDrawオブジェクトの型を設定
			//	( CDcdTextbox とする)。
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//　(2.2.*.3)　セルの DcDrawオブジェクトに、属性を設定。
			{
				CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

				int idxRessyasyubetsu 
					= pCentDedRessya->getRessyasyubetsuIndex() ;
				
				//	主要駅では、空欄に主要駅表記を行います。
				//	起点・終点・着発駅のいずれかである場合、
				//	境界線に接している駅である場合は除きます。
				bool bIsSyuyouEkiHyouki = false ;
				if ( aCdDedEki.getEkikibo() == CentDedEki::Ekikibo_Syuyou 
					&&	0 < iEkiOrder 
					&& iEkiOrder < muCdDedEki->size() - 1 
					&& 	!aCdDedEki.isHatsuChakuHyouji() )
				{
					//	境界線に接している駅である場合は除きます。
					CentDedEkiCont::CdDedEki aCentDedEkiTonari ;
					if ( iEkiOrder > 0 )
					{
						aCentDedEkiTonari = muCdDedEki->get( iEkiOrder - 1 ) ;
					}

					if ( !aCentDedEkiTonari.getKyoukaisen()  && 
						!aCdDedEki.getKyoukaisen() )
					{
						bIsSyuyouEkiHyouki = true ;
					}
				}
				//bIsSyuyouEkiHyouji = 空欄に主要駅表記を行います。

				CentDedEkiJikoku	aCentDedEkiJikoku =
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
				CdDedJikoku aCdDedJikoku 
							= aCentDedEkiJikoku.getChakujikoku() ;


				// --------------------------------
				//	駅時刻に合わせて、セルに文字を表示
				// --------------------------------
				switch( aCentDedEkiJikoku.getEkiatsukai() )
				{
				case CentDedEkiJikoku::Ekiatsukai_None :
					{
						if ( bIsSyuyouEkiHyouki )
						{
							//	主要駅での表記（着発の場合は除く）
							//	"----"
							*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_SYUYOU ) ) ;
						}
						else
						{
							//	その他の駅での表記
							//	"・・"
							*pCDcDrawCell = createCDcdRessyabangou(  idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_IPPAN ) ) ;
						}
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Keiyunasi :
					{
						*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
						pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
								IDS_WORD_JIKOKUHYOU_KEIYUNASI ) );//"||"
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Tsuuka :
					{
						if ( !aCdDedJikoku.isNull() && m_bDisplayTsuukaEkiJikoku )
						{
							//	通過駅の駅時刻が設定されており、
							//	『通過駅の駅時刻を表示する』指定になっている場合は
							//	時刻を表示
							*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
							string strText = getCdDedJikokuConv().encode( aCdDedJikoku ) ;
							pCDcDrawCell->setText(strText ) ;
							pCDcDrawCell->setCdDrawTextProp( 
								getCdDrawTextPropTsuuka() ) ;
						}	
						else
						{
							*pCDcDrawCell = createCDcdRessyabangou( 
								idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
								IDS_WORD_JIKOKUHYOU_TSUUKA ) );	//" ﾚ"
						}
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Teisya :
					{
						//	停車駅の駅時刻が指定されている
						if ( !aCdDedJikoku.isNull() )
						{
							*pCDcDrawCell = createCDcdEkijikoku( 
								idxRessyasyubetsu );
							string strText = getCdDedJikokuConv().encode( aCdDedJikoku ) ;
							pCDcDrawCell->setText(strText ) ;
						}
						//	停車駅の駅時刻が指定されていない
						else 
						{
							*pCDcDrawCell = createCDcdRessyabangou(
								idxRessyasyubetsu );

							//	[時刻表ビュー上の発時刻の表示列を算出
							CdYColSpec aCdYColSpec( 
								CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
								iEkiOrder ) ;
							int iYColumnNumberHatsu = 
								m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;


							//	時刻表ビュー上発時刻の表示あり AND 
							//	始発駅の場合は "・・" 表示
							if ( iYColumnNumberHatsu >= 0 && 
								pCentDedRessya->getSihatsuEki() == iEkiOrder )
							{
								pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_IPPAN ) ) ;
							}
							//	途中・終着駅の場合・着時刻のみ表示の場合は " ○ " 表示
							else	
							{
								pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_TEISYA ) ) ;
							}
						}
					}
					break ;
				}
				//  １．Ａ駅の『駅時刻形式』が『発着』
				//  ２．列車Ｆの、Ａ駅での駅扱が『停車』か『通過』のいずれか
				//  ３．列車Ｆの、Ａ駅の着時刻が空
				//  ４．列車Ｆの、Ａ駅の前の駅での駅扱が『経由なし』
				//
				//  この場合は、時刻表ビュー上では、列車ＦのＡ駅での着時刻は " || " 表示とします。
				{
					CentDedEkiJikoku aCentDedEkijikokuPrev ;
					if ( 0 <= iEkiOrder - 1 
						&& iEkiOrder - 1 < muCdDedEki->size() ) 
					{
						aCentDedEkijikokuPrev = 
							pCentDedRessya->getCentDedEkiJikoku(
								iEkiOrder - 1 ) ;
					}
					//aCentDedEkijikokuPrev = 前の駅の駅時刻

					if ( aCdDedEki.isHatsuChakuHyouji() && 
						( aCentDedEkiJikoku.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Teisya || 
							aCentDedEkiJikoku.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Tsuuka ) && 
						aCentDedEkiJikoku.getChakujikoku().isNull() && 
						aCentDedEkijikokuPrev.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
					{
						pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
							IDS_WORD_JIKOKUHYOU_KEIYUNASI ) );	//"||"
					}
				}
			}
		}
	}
}
	
void CCellBuilder::update02_02_02_07_setRessya_Hatsu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		int iEkiOrder ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		pCentDedRosen->getCentDedEkiCont()->getMuPtr(
			pCentDedRessya->getRessyahoukou() ) ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
			iEkiOrder ) ;
		int iYColumnNumber = 
			m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;
		// --------------------------------
		if ( pCDcdGridCell != 0 )
		{
			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			// --------------------------------
			//　(2.2.*.1)　セルの結合セルを設定
			pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

			//　(2.2.*.2)　セル の	DcDrawオブジェクトの型を設定
			//	( CDcdTextbox とする)。
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//　(2.2.*.3)　セルの DcDrawオブジェクトに、属性を設定。
			{
				CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;
				int idxRessyasyubetsu 
					= pCentDedRessya->getRessyasyubetsuIndex() ;
				//	主要駅では、空欄に主要駅表記を行います。
				//	起点・終点・着発駅のいずれかである場合、
				//	境界線に接している駅である場合は除きます。
				bool bIsSyuyouEkiHyouki = false ;
				if ( aCdDedEki.getEkikibo() == CentDedEki::Ekikibo_Syuyou 
					&&	0 < iEkiOrder 
					&& iEkiOrder < muCdDedEki->size() - 1 
					&& 	!aCdDedEki.isHatsuChakuHyouji() )
				{
					//	境界線に接している駅である場合は除きます。
					CentDedEkiCont::CdDedEki aCentDedEkiTonari ;
					if ( iEkiOrder > 0 )
					{
						aCentDedEkiTonari = muCdDedEki->get( iEkiOrder - 1 ) ;
					}

					if ( !aCentDedEkiTonari.getKyoukaisen()  && 
						!aCdDedEki.getKyoukaisen() )
					{
						bIsSyuyouEkiHyouki = true ;
					}
				}
				//bIsSyuyouEkiHyouji = 空欄に主要駅表記を行います。

				CentDedEkiJikoku	aCentDedEkiJikoku =
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
				CdDedJikoku aCdDedJikoku 
					= aCentDedEkiJikoku.getHatsujikoku() ;

				// --------------------------------
				//	駅時刻に合わせて、セルに文字を表示
				// --------------------------------
				switch( aCentDedEkiJikoku.getEkiatsukai() )
				{
				case CentDedEkiJikoku::Ekiatsukai_None :
					{
						if ( bIsSyuyouEkiHyouki )
						{
							//	主要駅での表記（着発の場合は除く）
							//	"----"
							*pCDcDrawCell = createCDcdRessyabangou(
								idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_SYUYOU ) ) ;
						}
						else
						{
							//	その他の駅での表記
							//	"・・"
							*pCDcDrawCell = createCDcdRessyabangou( 
								idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_IPPAN ) ) ;
						}
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Keiyunasi :
					{
						*pCDcDrawCell = createCDcdRessyabangou( 
							idxRessyasyubetsu );
						pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
								IDS_WORD_JIKOKUHYOU_KEIYUNASI ) );//"||"
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Tsuuka :
					{
						if ( !aCdDedJikoku.isNull() && m_bDisplayTsuukaEkiJikoku )
						{
							//	通過駅の駅時刻が設定されており、
							//	『通過駅の駅時刻を表示する』指定になっている場合は
							//	時刻を表示
							string strText = getCdDedJikokuConv().encode( aCdDedJikoku ) ;
							pCDcDrawCell->setText(strText ) ;
							pCDcDrawCell->setCdDrawTextProp( 
								getCdDrawTextPropTsuuka() ) ;
						}	
						else
						{
							*pCDcDrawCell = createCDcdRessyabangou( 
								idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
								IDS_WORD_JIKOKUHYOU_TSUUKA ) );	//" ﾚ"
						}
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Teisya :
					{
						//	停車駅の駅時刻が指定されている
						if ( !aCdDedJikoku.isNull() )
						{
							*pCDcDrawCell = createCDcdEkijikoku( 
								idxRessyasyubetsu );
							string strText = getCdDedJikokuConv().encode( aCdDedJikoku ) ;
							pCDcDrawCell->setText(strText ) ;
						}
						//	停車駅の駅時刻が指定されていない
						else 
						{
							*pCDcDrawCell = createCDcdRessyabangou( 
								idxRessyasyubetsu );

							//	[時刻表ビュー上の着時刻の表示列を算出
							CdYColSpec aCdYColSpec( 
								CdYColSpec::ColumnType_Ekijikoku_Chaku , 
								iEkiOrder ) ;
							int iYColumnNumberChaku = 
								m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;

							//	時刻表ビュー上に着時刻の表示あり AND 
							//	終着駅の場合は "・・" 表示
							if ( iYColumnNumberChaku >= 0 && 
								pCentDedRessya->getSyuuchakuEki() == iEkiOrder )
							{
								pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_IPPAN ) ) ;
							}
							//	始発・途中駅の場合・発時刻のみ表示の場合は " ○ " 表示
							else	
							{
								pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_TEISYA ) ) ;
							}
						}
					}
					break ;
				}
				//  １．Ａ駅の『駅時刻形式』が『発着』
				//  ２．列車Ｆの、Ａ駅での駅扱が『停車』か『通過』のいずれか
				//  ３．列車Ｆの、Ａ駅の発時刻が空
				//  ４．列車Ｆの、Ａ駅の次の駅での駅扱が『経由なし』
				//
				//	  この場合は、時刻表ビュー上では、列車ＦのＡ駅での発時刻は 
				//	" || " 表示とします
				{
					CentDedEkiJikoku aCentDedEkijikokuNext ;
					if ( 0 <= iEkiOrder + 1 
						&& iEkiOrder + 1 < muCdDedEki->size() ) 
					{
						aCentDedEkijikokuNext = 
							pCentDedRessya->getCentDedEkiJikoku( 
								iEkiOrder + 1 ) ;
					}
					//aCentDedEkijikokuNext = 次の駅の駅時刻

					if ( aCdDedEki.isHatsuChakuHyouji() && 
						( aCentDedEkiJikoku.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Teisya || 
							aCentDedEkiJikoku.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Tsuuka ) && 
						aCentDedEkiJikoku.getHatsujikoku().isNull() && 
						aCentDedEkijikokuNext.getEkiatsukai() == 
							CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
					{
						pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
							IDS_WORD_JIKOKUHYOU_KEIYUNASI ) );	//"||"
					}

				}
			}
		}
	}
}	
void CCellBuilder::update02_02_02_08_setRessya_Bikou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Bikou ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextboxV3 CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//　(2.2.*.1)　セル(ColumnType_Ressya,ColumnType_Ressyabangou) の
		//	結合セルを設定
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//　(2.2.*.2)　セル の	DcDrawオブジェクトの型を設定
		//	( CDcdTextbox とする)。
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}
		//　(2.2.*.3)　セルの DcDrawオブジェクトに、属性を設定。
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;
			string strText = pCentDedRessya->getBikou() ;
			*pCDcDrawCell = createCDcdRessyamei( 
				idxRessyasyubetsu );
			pCDcDrawCell->setLinesExtentX ( getBikouTextExtent().getX() ) ;
			pCDcDrawCell->setLinesExtentY ( getBikouTextExtent().getY() ) ;
			pCDcDrawCell->setText( strText );
		}
	}
}

	// ********************************
	//	コンストラクタ
	// ********************************
CCellBuilder::CCellBuilder( 
		const CDedRosenFileData* pCDedRosenFileData ,
		const CentDedRessyaCont* pCentDedRessyaCont,
		bool bDisplayTsuukaEkiJikoku ,
		bool bDisplayAllJikoku ) :
		m_pCentDedRessyaCont( pCentDedRessyaCont ) ,
		m_pCDedRosenFileData( pCDedRosenFileData ) , 
		m_CdXColSpecCont( pCentDedRessyaCont ) ,
		m_CdYColSpecCont( 
			pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont() ,
			pCentDedRessyaCont->getRessyahoukou() , bDisplayAllJikoku ) ,
		m_bDisplayTsuukaEkiJikoku( bDisplayTsuukaEkiJikoku ) 
{
}

	// ********************************
	//@name	CCellBuilder-操作
	// ********************************
void CCellBuilder::update( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{

	//　(1)　グリッドのうち、列車情報以外のすべての部分を設定します。
	update01_updateWithoutRessya(
		pCWndJikokuhyou ) ;

	//　(2)　列車情報を設定します。
	updateAllRessya( 
		pCWndJikokuhyou ) ;
	
	// --------------------------------
	pCWndJikokuhyou->InvalidateGrid() ;
}

void CCellBuilder::updateAllRessya( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	//　(2.1)　X列の数を設定します。CdXColSpecCont 
	//	で指定された列数とします。
	CDcdGrid*	pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	pCDcdGrid->setXColumnCount( m_CdXColSpecCont.size() ) ;

	//　(2.2)　X列(ColumnType_Ressya )に、列車情報を設定
	for ( int iRessyaIndex = 0 ; iRessyaIndex < m_pCentDedRessyaCont->size() ; 
		iRessyaIndex ++ )
	{
		int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec(
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iRessyaIndex ) ) ;
		if ( iXColumnNumber >= 0 )
		{
			update02_02_updateRessya( 
				iXColumnNumber , 
				m_pCentDedRessyaCont->getMuPtr()->get( iRessyaIndex ) ,
				pCWndJikokuhyou ) ;
		}
	}

	//　(2.3)　X列(ColumnType_NewRessya )に、列車情報を設定。
	//	X列(ColumnType_Ressya )と同様。
	{
		int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec(
			CdXColSpec( 
				CdXColSpec::ColumnType_NewRessya  ) ) ;
		if ( iXColumnNumber >= 0 )
		{
			CentDedRessya aRessya( m_pCentDedRessyaCont->createNullRessya() ) ;

			update02_02_updateRessya( 
				iXColumnNumber , 
				&aRessya ,
				pCWndJikokuhyou ) ;
		}
	}
}


void CCellBuilder::replaceRessya( 
		int iDstRessyaIndex , 
		int iDstDelCount , 
		int iInsertCount ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid*	pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;

	// --------------------------------
	//	減少分の要素の削除
	// --------------------------------
	int iGensyouSize = iDstDelCount - iInsertCount ;
	if ( iGensyouSize > 0 )
	{
		int iXColumnNumberToDelete = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iDstRessyaIndex ) ) ;
		if ( iXColumnNumberToDelete == -1 )
		{
			iXColumnNumberToDelete = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_NewRessya ) ) ;
		}
		for ( int cnt = 0 ; cnt < iGensyouSize ; cnt ++ )
		{
			pCWndJikokuhyou->getCXDcdGrid()->eraseXColumn( 
				iXColumnNumberToDelete ) ;
		}
	}
	// --------------------------------
	//	増加分の要素の追加
	// --------------------------------
	int iZoukaSize = iInsertCount - iDstDelCount ;
	if ( iZoukaSize > 0 )
	{
		int iXColumnNumberToInsert = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iDstRessyaIndex + iDstDelCount ) ) ;
		for ( int cnt = 0 ; cnt < iZoukaSize ; cnt ++ ){
			pCWndJikokuhyou->getCXDcdGrid()->insertXColumn( 
				iXColumnNumberToInsert , 
				true ) ; 
		}
	}
	// --------------------------------
	//	要素の更新
	// --------------------------------
	{					
		for ( int cnt = 0 ; cnt < iInsertCount ; cnt ++ )
		{
			int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Ressya ,
					iDstRessyaIndex + cnt ) ) ;

			update02_02_updateRessya( 
				iXColumnNumber , 
				m_pCentDedRessyaCont->getMuPtr()->get( iDstRessyaIndex + cnt ) ,
				pCWndJikokuhyou ) ;
		}
	}
	// --------------------------------
	//	グリッドの更新
	// --------------------------------
	CdDcdZone	zoneX ;
	if ( iInsertCount > 0 )
	{
		int iXColumnNumber1 = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iDstRessyaIndex ) ) ;
		int iXColumnNumber2 = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iDstRessyaIndex + iInsertCount - 1 ) )  ;
		CdDcdZone	zoneX1 = pCWndJikokuhyou->getXColumnZone( iXColumnNumber1 ) ;
		CdDcdZone	zoneX2 = pCWndJikokuhyou->getXColumnZone( iXColumnNumber2 ) ;
		zoneX.setBeginEndPos( zoneX1.getPos() , zoneX2.getEndPos() ) ; 

	}
	CdDcdZone	zoneY ;
	{
		CdDcdZone	zoneY1 = pCWndJikokuhyou->getYColumnBorderZone( 0 ) ;
		CdDcdZone	zoneY2 = pCWndJikokuhyou->getYColumnBorderZone( pCDcdGrid->getYColumnCount() - 1 ) ;
		zoneY.setBeginEndPos( zoneY1.getPos() , zoneY2.getEndPos() ) ;
		//zoneRessya = グリッド上の列車の領域
	}
	CdDcdZoneXy	zonexyInvalidate( zoneX , zoneY ) ;
	// --------------------------------
	pCWndJikokuhyou->InvalidateRect( 
		&CConverter_WinGdi().RECTOf( zonexyInvalidate ) , TRUE ) ;
}


} //namespace ViewJikokuhyou
} //namespace WndJikokuhyou

