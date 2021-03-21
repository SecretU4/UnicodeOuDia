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
//	CWndDcdGridRessyasyubetsu.cpp
//	$Id: CWndDcdGridRessyasyubetsu.cpp 402 2016-11-26 09:45:48Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "logmsg\LogMsg.h"
#include "NsOu\OuNew.h"
#include "NsOu\dynamic_castOu.h"
#include "str\strtoint.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CConverter_WinGdi.h"

#include "..\resource.h"
#include "..\entDed\CentDedRosen.h"
#include "..\DiagramEdit.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "CDlgRessyasyubetsuProp.h"

// ****************************************************************
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
// ****************************************************************

namespace ViewRessyasyubetsu{ 
using namespace std ;

// --------------------------------
///@name	X列番号
// --------------------------------
///@{
/**
X列番号：列車種別番号
*/
const int XCOLUMNNNO_RESSYASYUBETSUNO = 0 ;
/**
X列番号：列車種別名
*/
const int XCOLUMNNNO_RESSYASYUBETSU = 1 ;
/**
X列番号：列車種別略称
*/
const int XCOLUMNNNO_RYAKUSYOU = 2 ;
/**
X列番号：線種
*/
const int XCOLUMNNNO_LINESTYLE = 3 ;
/**
X列番号：X列数
*/
const int XCOLUMNNCOUNT = 4 ;
///@}


// --------------------------------
///@name	Y列番号
// --------------------------------
///@{
/**
Y列番号：ヘッダ列
*/
const int YCOLUMNNNO_HEADER = 0 ;
/**
Y列番号：列車種別の0番目
*/
const int YCOLUMNNNO_RESSYASYUBETSU_0 = 1 ;
/**
Y列番号：列車種別の後の列数
*/
const int YCOLUMNNCOUNT_BLANK = 1 ;
///@}

/**
@return
	列車種別ビューのフォントの属性を返します。
*/
static CdFontProp createFontProp()
{
	return ( CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
}

	// --------------------------------
	//@name	下請関数
	// --------------------------------
CdRessyasyubetsuXColSpecCont 
CWndDcdGridRessyasyubetsu::createXColSpecCont()
{
	CdRessyasyubetsuXColSpecCont aSpecCont( 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont() ) ;
	return aSpecCont ;
}

CdRessyasyubetsuYColSpecCont 
CWndDcdGridRessyasyubetsu::createYColSpecCont()
{
	CdRessyasyubetsuYColSpecCont aSpecCont( 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont() ) ;
	return aSpecCont ;
}

CdRessyasyubetsuXColSpec 
CWndDcdGridRessyasyubetsu::getXColSpecOfFocus()
{
	CdRessyasyubetsuXColSpec aSpec ;
	CdDcdPosXy aPos = getCFocus()->getFocusCellColumnNumber() ;
	if ( aPos != getCFocus()->ColumnNumberPosXy_NULL() )
	{
		CdRessyasyubetsuXColSpecCont aSpecCont( 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont() ) ;
		aSpec = aSpecCont.ColumnNumberToSpec( aPos.getX() ) ;
	}
	return aSpec ;
}

CdRessyasyubetsuYColSpec 
CWndDcdGridRessyasyubetsu::getYColSpecOfFocus() 
{
	CdRessyasyubetsuYColSpec aSpec ;
	CdDcdPosXy aPos = getCFocus()->getFocusCellColumnNumber() ;
	if ( aPos != getCFocus()->ColumnNumberPosXy_NULL() )
	{
		CdRessyasyubetsuYColSpecCont aSpecCont( 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont() ) ;
		aSpec = aSpecCont.ColumnNumberToSpec( aPos.getY() ) ;
	}
	return aSpec ;
}
	
bool CWndDcdGridRessyasyubetsu::createCmd( 
	ECreateCmd eCreateCmd , 
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu>* ppCmd )
{
	bool bRv = false ;
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu> pCmd ;

	CdRessyasyubetsuYColSpecCont aCdYColSpecCont = createYColSpecCont() ;
	CdRessyasyubetsuYColSpec  aCdYColSpecOfFocus = getYColSpecOfFocus() ;

	// ********************************
	//	ECreateCmd_NewItem 
	//　ビューのフォーカス位置に新規アイテムを挿入するためのコマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_NewItem )
	{
		//ビュー上で複数選択がOFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{


			//	新規アイテムの、初期オブジェクト
			CentDedRessyasyubetsu aNewRessyasyubetsu ;

			//ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 
			//- m_iIndexDst = フォーカスセルのアイテムIndex、m_iIndexSize = 0
			//- m_CentDedEkiCont = 新規作成時のアイテムの既定値
			//- CaMuiSelect = 当該アイテムを選択。
			if ( aCdYColSpecOfFocus.getColumnType() 
				== CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<CRfEditCmd_Ressyasyubetsu>( 
						new CRfEditCmd_Ressyasyubetsu( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getRessyasyubetsuIndex() ,
							0 ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewRessyasyubetsu , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			 //　ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合:
			 //- m_iIndexDst = 末尾アイテムIndex+1、m_iIndexSize = 0
			 //- m_CentDedEkiCont = 新規作成時のアイテムの既定値
			 //- CaMuiSelect = 当該アイテムを選択。
			if ( aCdYColSpecOfFocus.getColumnType() 
				== CdRessyasyubetsuYColSpec::ColumnType_NewRessyasyubetsu )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<CRfEditCmd_Ressyasyubetsu>( 
						new CRfEditCmd_Ressyasyubetsu( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getRessyasyubetsuIndex() ,
							0 ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewRessyasyubetsu , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}
		}
		 //　ビュー上で複数選択ON:
		 //- 複数選択OFFの場合と同じ動作
	}
	// ********************************
	//	ECreateCmd_Focus
	//　フォーカスセル上のアイテム1つを対象としたコマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_Focus )
	{
		//ビュー上で複数選択がOFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{

			//	ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 
			//
			//- m_iIndexDst = フォーカスセルのアイテムIndex、m_iIndexSize = 1
			//- m_CentDedRessyaCont = フォーカスセル上のアイテム1個のコピー
			//- m_CaMuiSelect = フォーカスセル上のアイテムを選択。
			if ( aCdYColSpecOfFocus.getColumnType() 
				== CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<CRfEditCmd_Ressyasyubetsu>( 
						new CRfEditCmd_Ressyasyubetsu( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getRessyasyubetsuIndex() ,
							1 ) ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			//	ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合: 
			//- NULLを返します。
		}
		//	ビュー上で複数選択ON
		//- 複数選択OFFの場合と同じ動作

	}
	// ********************************
	//	ECreateCmd_Select
	//　既存の単数または複数選択されているアイテムを対象とした
	//	コマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select )
	{
		//	ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 
		//- m_iIndexDst = フォーカスセルのアイテムIndex、m_iIndexSize = 1
		//- m_CentDedRessyaCont = フォーカスセルのあるアイテム1個のコピー
		//- CaMuiSelect = 当該列車を選択。
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& aCdYColSpecOfFocus.getColumnType() 
				== CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<CRfEditCmd_Ressyasyubetsu>( 
					new CRfEditCmd_Ressyasyubetsu( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						aCdYColSpecOfFocus.getRessyasyubetsuIndex() ,
						1 ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		//	ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合: 
		//- NULLを返します。

		//	ビュー上で複数選択ON
		//
		//- m_iIndexDst = 選択されているアイテムの先頭index
		//- m_iIndexSize = 選択されているアイテムの末尾index-先頭index+1
		//- m_CentDedRessyaCont = 選択されているアイテムの先頭indexから
		//	末尾indexまでのアイテムのコピー
		//- CaMuiSelect は、セル選択に合わせてアイテムを選択。
		//
		//(A)の位置で処理します。
	}




	// ********************************
	//		ECreateCmd_All ,
	//　全列車を対象としたコマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_All )
	{
		// ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 
		//- m_iIndexDst = 0、m_iIndexSize = アイテムの数
		//- m_CentDedRessyaCont = 全アイテムのコピー
		//- m_CaMuiSelect は、全アイテムを選択。
		//
		// ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合: 
		//- m_iIndexDst = 0、m_iIndexSize = アイテムの数
		//- m_CentDedRessyaCont = 全アイテムのコピー
		//- CaMuiSelect は、全アイテムを選択。
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& ( aCdYColSpecOfFocus.getColumnType() == CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu 
			|| aCdYColSpecOfFocus.getColumnType() == CdRessyasyubetsuYColSpec::ColumnType_NewRessyasyubetsu ) )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu>( 
					new CRfEditCmd_Ressyasyubetsu( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						0 , 
						aCdYColSpecCont.getRessyasyubetsuCount() ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		// ビュー上で複数選択ON
		//
		//- m_iIndexDst = 選択されているアイテムの先頭index
		//- m_iIndexSize = 選択されているアイテムの末尾index-先頭index+1
		//- m_CentDedRessyaCont = 選択されているアイテムの先頭indexから
		//末尾indexまでのアイテムのコピー
		//- m_CaMuiSelect は、セルの選択に合わせてアイテムを選択。
		//
		//(A)の位置で処理します。
	}

	// ********************************
	//	(A)ECreateCmd_Select・ECreateCmd_All で
	//　複数選択されている列車を対象とした
	//	コマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select 
		|| eCreateCmd == ECreateCmd_All )
	{
		if ( getCSelect()->getSelectedCellCount() > 0 )
		{
			//	選択されているアイテムのIndexを取得
			deque<int> contiSelectedItemIndex ;
			for ( int iColumnNumber = 0 ; iColumnNumber < getCXDcdGrid()->getYColumnCount() ;iColumnNumber ++ )
			{
				if ( getCSelect()->getYColumnNumberSelected( iColumnNumber ) )
				{
					CdRessyasyubetsuYColSpec aCdYColSpec = aCdYColSpecCont.ColumnNumberToSpec( iColumnNumber ) ;
					if ( aCdYColSpec.getColumnType() == CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu )
					{
						contiSelectedItemIndex.push_back( aCdYColSpec.getRessyasyubetsuIndex() ) ;
					}
				}
			}
			//contiSelectedItemIndex = 列の複数選択が実施されている場合は、
			//	選択されている列車種別Indexが格納されます。
			//	そうでない場合は、空です。

			if ( contiSelectedItemIndex.size() > 1 )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					//	コマンドオブジェクト内に、選択されている駅の先頭から末尾までの
					//	駅を格納します(先頭・末尾以外には、選択されていない駅が
					//	含まれている場合もあります)
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu>( 
						new CRfEditCmd_Ressyasyubetsu( 
							*getCDiagramEditDoc()->getCDedRosenFileData() ,
							contiSelectedItemIndex.front() , 
							contiSelectedItemIndex.back() - contiSelectedItemIndex.front() + 1 ) ) ;

					//	コマンドオブジェクトの
					//	m_CentDedRessyaContSrc  内の列車を選択します。
					pCmd->getCaMuiSelect()->setSelectAll( false ) ;
					for ( int i = 0 ; i < (int)contiSelectedItemIndex.size() ; i ++ )
					{
						pCmd->getCaMuiSelect()->setSelect( 
							contiSelectedItemIndex[i] - contiSelectedItemIndex.front()  , 
							true ) ;
					}
				}
			}
		}
	}
	// ================================
	if ( ppCmd != NULL && pCmd != NULL )
	{
		*ppCmd = pCmd ;
	}
	return bRv ;
}


	// --------------------------------
	//@name OnUpdate の下請関数
	// --------------------------------
void CWndDcdGridRessyasyubetsu::OnUpdate_setCentDedRessyasyubetsu_To_Column( 
	int iYColumnNumber , 
	const CentDedRessyasyubetsu& aCentDedRessyasyubetsu ) 
{
	bool bIsNull = aCentDedRessyasyubetsu.isNull() ;

	CdFontProp fontpropDefault = createFontProp() ;

	// --------------------------------
	//	行のY方向サイズを設定
	// --------------------------------
	{
		CDcdTargetGetDC	aCDcdTarget( NULL ) ;

		CdDcdSizeXy	sizeRessyasyubetsumei ;
		CDcdTextbox	aCDcdTextbox( "京都京都京都" ,
			fontpropDefault , 
			"" , 1 , 2 , 2 ) ;
		aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsumei ) ;

		getCXDcdGrid()->getYColumn( iYColumnNumber )->setColumnSize( sizeRessyasyubetsumei.getY() ) ;
	}

	
	// --------------------------------
	//	線スタイルセルに 
	//	CDcdFreeLine_StyleSample オブジェクトを設定
	// --------------------------------
	{
		CDcdGridCell* pCDcdGridCell = 	getCXDcdGrid()->getCell( XCOLUMNNNO_LINESTYLE , iYColumnNumber ) ;
		Ou<CDcdFreeLine_StyleSample>	pCDedLineCentral = 
			dynamic_castOu<CDcdFreeLine_StyleSample>( 
			 pCDcdGridCell->getIfDcDraw() );
		if ( pCDedLineCentral == NULL )
		{
			OuNew<CDcdFreeLine_StyleSample>	pCDedLineCentral = 
				new CDcdFreeLine_StyleSample( CdDcdFreeLineProp( 
					0  ,
					CdColorProp( 0 ,0 , 0) ) ) ;
			pCDcdGridCell->setIfDcDraw( pCDedLineCentral ) ;
		}
	}
	// --------------------------------
	//	属性を設定
	// --------------------------------
	{
		//	種別名
		Ou<CDcdTextbox> pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RESSYASYUBETSU , iYColumnNumber )->getIfDcDraw() ;
		pCDcdTextbox->
			setText( aCentDedRessyasyubetsu.getSyubetsumei() )  ;	

		//	フォント属性
		CdDrawTextProp	aCdDrawTextProp = 
				pCDcdTextbox->getCdDrawTextProp() ;
		aCdDrawTextProp.setCdFontProp( fontpropDefault ) ;
		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp )  ;	
		
		//	セルを無効化
		InvalidateCell( XCOLUMNNNO_RESSYASYUBETSU , iYColumnNumber ) ;
	}
	{
		//	略称
		Ou<CDcdTextbox> pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RYAKUSYOU , iYColumnNumber )->getIfDcDraw() ;
		
		//略称のテキスト
		pCDcdTextbox->setText( 
			aCentDedRessyasyubetsu.getRyakusyou() )  ;	
		
		//略称のフォント属性
		CdDrawTextProp	aCdDrawTextProp = 
				pCDcdTextbox->getCdDrawTextProp() ;
		{
			aCdDrawTextProp.setTextColor( 
				aCentDedRessyasyubetsu.getJikokuhyouMojiColor() ) ;

			int idxFont = aCentDedRessyasyubetsu.getJikokuhyouFontIndex() ;
			aCdDrawTextProp.setCdFontProp( 
				getCDiagramEditDoc()->getCDedRosenFileData()
					->getCdDedDispProp().getJikokuhyouFont( idxFont ) ) ;
		}
		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp )  ;	

		//	セルを無効化
		InvalidateCell( XCOLUMNNNO_RYAKUSYOU , iYColumnNumber ) ;
	}
	{
		//	線スタイル
		CdDcdFreeLineProp	aCdLineProp( 0 ) ;
		if ( !bIsNull ){
			CconvCentDed aCconvCentDed ;
			aCconvCentDed.CentDedRessyasyubetsu_to_CDcdFreeLineProp( 
				aCentDedRessyasyubetsu.getCdDiagramLineStyle() ,
				&aCdLineProp ) ;
		}
		Ou<CDcdFreeLine_StyleSample>	pCDcdFreeLine_StyleSample = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_LINESTYLE , iYColumnNumber )->getIfDcDraw() ;
		pCDcdFreeLine_StyleSample->setCdLineProp( aCdLineProp ) ;

		//	セルを無効化
		InvalidateCell( XCOLUMNNNO_LINESTYLE , iYColumnNumber ) ;
	}
}


void CWndDcdGridRessyasyubetsu::OnUpdate_setRessyasyubetsuNoXColumn() 
{
	const CentDedRosen*	pCentDedRosen = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu = 
		pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;


	for ( int iYColumnNumber = 0 ; iYColumnNumber < getCXDcdGrid()->getYColumnCount() ; iYColumnNumber ++ )
	{
		Ou<CDcdTextbox> pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RESSYASYUBETSUNO , iYColumnNumber )->getIfDcDraw() ;

		string aStr ;
		if ( YCOLUMNNNO_RESSYASYUBETSU_0 <= iYColumnNumber &&
			iYColumnNumber < YCOLUMNNNO_RESSYASYUBETSU_0 + 10 && 
			iYColumnNumber < YCOLUMNNNO_RESSYASYUBETSU_0 + pMuCentDedRessyasyubetsu->size() )
		{
			aStr = stringOf( iYColumnNumber - YCOLUMNNNO_RESSYASYUBETSU_0 ) ;
		}
		pCDcdTextbox->setText( aStr )  ;	
		
		//	セルを更新
		InvalidateCell( XCOLUMNNNO_RESSYASYUBETSUNO , iYColumnNumber ) ;
	}
}



void  CWndDcdGridRessyasyubetsu::OnUpdate_All() 
{
	CWaitCursor	aCWaitCursor ;	

	CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
	const CentDedRosen*	pCentDedRosen = 
		pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet 
		= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;
	{
		//	コマンドオブジェクト実行によるセル移動でセル選択にならないように、
		//	セル選択を解除し、セル選択機能も一時的に中止します。
		clearSelect() ;
		CPropStack aPropStack( this ) ;
		aPropStack
			.CBoxSelect_setIsEnable( false )
			.CRandomSelect_setIsEnable( false )  ;

		// --------------------------------		
		//	全要素を更新
		// --------------------------------
		//	Y列数を増減させる
		getCXDcdGrid()->setYColumnCount( 
			pCentDedRessyasyubetsuContGet->size() + YCOLUMNNNO_RESSYASYUBETSU_0 + YCOLUMNNCOUNT_BLANK ) ;

		//	各セルに、データを設定
		int idxRessyasyubetsu ;
		for ( idxRessyasyubetsu = 0 ; 
				idxRessyasyubetsu < 
					pCentDedRessyasyubetsuContGet->size() ; 
				idxRessyasyubetsu ++ )
		{
			const CentDedRessyasyubetsu*	pCentDedRessyasyubetsu = 
				pCentDedRessyasyubetsuContGet->get( idxRessyasyubetsu ) ;

			OnUpdate_setCentDedRessyasyubetsu_To_Column( 
				idxRessyasyubetsu + YCOLUMNNNO_RESSYASYUBETSU_0 , *pCentDedRessyasyubetsu ) ;
		} 
		OnUpdate_setCentDedRessyasyubetsu_To_Column( 
			idxRessyasyubetsu + YCOLUMNNNO_RESSYASYUBETSU_0 , CentDedRessyasyubetsu() ) ;

		// --------------------------------
		//	列車種別番号を更新
		// --------------------------------
		OnUpdate_setRessyasyubetsuNoXColumn() ;
	}
	m_bUpdate_All_Requested = false ;
}

	// --------------------------------
	//@name メニューコマンドの下請関数
	// --------------------------------
	//	[編集]-[切り取り]
int CWndDcdGridRessyasyubetsu::OnEditCut_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMessage ;

	const CentDedRosen*	pCentDedRosen = 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu 
		= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;

	Ou<CRfEditCmd_Ressyasyubetsu> pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}


	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	セルの位置が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		//	現在、列車種別が1であれば、このメニューコマンドは無効とします。
		if ( pMuCentDedRessyasyubetsu->size() <= 1 )
		{
			iRv = -2;	//	列車種別が1であれば、このメニューコマンドは無効
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************

		//	削除しようとしている列車種別の列車が
		//	存在するならエラーとします。
		int iRessyasyubetsuIndex = -1 ;
		int iDiaIndex = -1 ;
		ERessyahoukou	eRessyahoukou = Ressyahoukou_Kudari ;
		if ( iRv >= 0 )
		{
			int idx ;
			for ( idx = 0 ; iRv >= 0 && idx < pCmd->getCaMuiSelect()->size() ;
				idx ++ )
			{
				iRessyasyubetsuIndex = pCmd->getIndexDst() + idx ;

				if ( pCentDedRosen->getCentDedDiaCont()
					->isExistRessyaOfRessyasyubetsu(
						iRessyasyubetsuIndex , &iDiaIndex , &eRessyahoukou , NULL )
					 != 0 )
				{
					iRv = -3 ;	//削除しようとしている列車種別の列車が存在します
				}
			}
		}
		//iRessyasyubetsuIndex = 
		//	iRv=-3の場合は、削除しようとしている列車種別のindex
		//iDiaIndex = 
		//	iRv=-3の場合は、削除しようとしている列車種別が存在するダイヤのindex
		//eRessyahoukou = 
		//	iRv=-3の場合は、削除しようとしている列車種別が存在するダイヤのindex
		
		if ( iRv >= 0 )
		{
			// -------------------------------- 
			//	クリップボードに転送
			// --------------------------------
			getCDiagramEditDoc()->CentDedRessyasyubetsu_To_Cliboard( 
				pCmd->getCaMuiSelect() ) ;
			// --------------------------------
			//	コマンドオブジェクトの列車を編集
			// --------------------------------
			{
				pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;
			}
			// --------------------------------
			//	コマンドオブジェクトを実行
			// --------------------------------
			{
				getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			}
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		if ( iRv < 0 )
		{
			//	エラーメッセージを構成
			if ( iRv == -3 )
			{
				CString	strRessyasyubetsuName = 
					pMuCentDedRessyasyubetsu->get( iRessyasyubetsuIndex )
					->getSyubetsumei().c_str()  ;
				CString	strDiaName = 
					pCentDedRosen->getCentDedDiaCont()->getMuPtr()->
					get( iDiaIndex )->getName().c_str() ;
				CString	strRessyahoukou ;
				if ( eRessyahoukou == Ressyahoukou_Kudari )
				{
					strRessyahoukou.LoadString( IDS_WORD_Kudari ) ;
				}
				else
				{
					strRessyahoukou.LoadString( IDS_WORD_Nobori ) ;
				}
				CString	strMsg ;
				strMsg.Format( IDS_ERR_ExistRessyaOfRessyasyubetsu ,
					strRessyasyubetsuName , strDiaName , strRessyahoukou ) ;
				strErrorMessage = strMsg ;
			}

			if ( strErrorMessage.IsEmpty() )
			{
				strErrorMessage.Format( _T( "Error(%d)" ) , iRv ) ; 
			}
			MessageBox( strErrorMessage , NULL , MB_ICONSTOP | MB_OK ) ; 
		}
		// ****************************************************************
	}
	return iRv ;	

}
	//	[編集]-[コピー]	
int CWndDcdGridRessyasyubetsu::OnEditCopy_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Ressyasyubetsu> pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	セルの位置が正しくありません。
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// -------------------------------- 
		//	クリップボードに転送
		// --------------------------------
		getCDiagramEditDoc()->CentDedRessyasyubetsu_To_Cliboard( 
			pCmd->getCaMuiSelect() ) ;

		// -------------------------------- 
		//	フォーカスセルを、選択要素中で最大の列車種別Indexの次位に移動
		// --------------------------------
		{
			//	セル選択をクリアし、
			//	フォーカスセルの移動によるセル選択を無効化します。
			clearSelect() ;
			CPropStack	aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		
			//	選択要素中で最大の列車種別Index を求める
			int iRessyasyubetsuIndexMax = -1 ;
			{
				CaMuiSelect<CentDedRessyasyubetsu>* pCaMuiSelect = pCmd->getCaMuiSelect() ;
				for ( int iIndex = pCaMuiSelect->getAdapteeMu()->size() - 1  ; 
					iRessyasyubetsuIndexMax == -1 && iIndex >= 0 ; iIndex -- )
				{
					if ( pCaMuiSelect->getSelect( iIndex ) )
					{
						iRessyasyubetsuIndexMax = iIndex + pCmd->getIndexDst() ;
					}
				}
			}
			//iRessyasyubetsuIndexMax = 選択されている列車種別のうち、最大のIndex

			//	移動先のフォーカスセル位置を決定
			int iYColumnNmber = -1 ;
			{
				CdRessyasyubetsuYColSpecCont aCdYColSpecCont = createYColSpecCont() ;
				iYColumnNmber = aCdYColSpecCont.ColumnNumberFromSpec( 
					CdRessyasyubetsuYColSpec( CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu , iRessyasyubetsuIndexMax ) ) + 1 ;
			}
			//	フォーカスを移動
			{
				CdDcdPosXy posxyFocusCellColumnNumber 
					= getCFocus()->getFocusCellColumnNumber() ;
				if ( iYColumnNmber >= 0 
					&& posxyFocusCellColumnNumber != getCFocus()->ColumnNumberPosXy_NULL() )
				{
					posxyFocusCellColumnNumber.setY( iYColumnNmber ) ;
					getCFocus()->setFocusCellColumnNumber( posxyFocusCellColumnNumber ) ;
				}
			}
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;


}
	//	[編集]-[貼り付け]	
int CWndDcdGridRessyasyubetsu::OnEditPaste_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Ressyasyubetsu> pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_NewItem , ppCmd ) )
		{
			iRv = -1 ;	//	セルの位置が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		if ( !getCDiagramEditDoc()->CentDedRessyasyubetsu_IsClipboardFormatAvailable() )
		{
			iRv = -2 ;	//	クリップボードに駅のデータがありません
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// -------------------------------- 
		//	クリップボードからデータを取得
		// --------------------------------
		CentDedRessyasyubetsuCont	aRessyasyubetsuCont ;
		getCDiagramEditDoc()->CentDedRessyasyubetsu_From_Cliboard( &aRessyasyubetsuCont ) ;
		// --------------------------------
		//	コマンドオブジェクトの駅を編集
		// --------------------------------
		{
			//	CWndDcdGridRessyasyubetsu::ECreateCmd_NewItem によって生成された
			//	新規アイテムは削除します。
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;

			//	コマンドにクリップボードからのアイテムを追加します。
			CaMui<CentDedRessyasyubetsu> aCaMui( pCmd->getCaMuiSelect() ) ;
			aCaMui.insert( &aRessyasyubetsuCont , 0 , INT_MAX , 0 ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		if ( iRv < 0 )
		{
			CString strErrorMessage ;
			strErrorMessage.Format( _T( "Error=%d" ) , iRv ) ;

			MessageBox( strErrorMessage , NULL , MB_ICONSTOP | MB_OK ) ; 
		}
	}
	return iRv ;

}
	//	[編集]-[消去]	
int CWndDcdGridRessyasyubetsu::OnEditClear_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMessage ;

	const CentDedRosen*	pCentDedRosen = 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu 
		= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;

	Ou<CRfEditCmd_Ressyasyubetsu> pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}


	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	セルの位置が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		//	現在、列車種別が1であれば、このメニューコマンドは無効とします。
		if ( pMuCentDedRessyasyubetsu->size() <= 1 )
		{
			iRv = -2;	//	列車種別が1であれば、このメニューコマンドは無効
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************

		//	削除しようとしている列車種別の列車が
		//	存在するならエラーとします。
		int iRessyasyubetsuIndex = -1 ;
		int iDiaIndex = -1 ;
		ERessyahoukou	eRessyahoukou = Ressyahoukou_Kudari ;
		if ( iRv >= 0 )
		{
			int idx ;
			for ( idx = 0 ; iRv >= 0 && idx < pCmd->getCaMuiSelect()->size() ;
				idx ++ )
			{
				iRessyasyubetsuIndex = pCmd->getIndexDst() + idx ;

				if ( pCentDedRosen->getCentDedDiaCont()
					->isExistRessyaOfRessyasyubetsu(
						iRessyasyubetsuIndex , &iDiaIndex , &eRessyahoukou , NULL )
					 != 0 )
				{
					iRv = -3 ;	//削除しようとしている列車種別の列車が存在します
				}
			}
		}
		//iRessyasyubetsuIndex = 
		//	iRv=-3の場合は、削除しようとしている列車種別のindex
		//iDiaIndex = 
		//	iRv=-3の場合は、削除しようとしている列車種別が存在するダイヤのindex
		//eRessyahoukou = 
		//	iRv=-3の場合は、削除しようとしている列車種別が存在するダイヤのindex
		
		if ( iRv >= 0 )
		{
			// -------------------------------- 
			//	クリップボードに転送
			// --------------------------------
			getCDiagramEditDoc()->CentDedRessyasyubetsu_To_Cliboard( 
				pCmd->getCaMuiSelect() ) ;
			// --------------------------------
			//	コマンドオブジェクトの列車を編集
			// --------------------------------
			{
				pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;
			}
			// --------------------------------
			//	コマンドオブジェクトを実行
			// --------------------------------
			{
				getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			}
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		if ( iRv < 0 )
		{
			//	エラーメッセージを構成
			if ( iRv == -3 )
			{
				CString	strRessyasyubetsuName = 
					pMuCentDedRessyasyubetsu->get( iRessyasyubetsuIndex )
					->getSyubetsumei().c_str()  ;
				CString	strDiaName = 
					pCentDedRosen->getCentDedDiaCont()->getMuPtr()->
					get( iDiaIndex )->getName().c_str() ;
				CString	strRessyahoukou ;
				if ( eRessyahoukou == Ressyahoukou_Kudari )
				{
					strRessyahoukou.LoadString( IDS_WORD_Kudari ) ;
				}
				else
				{
					strRessyahoukou.LoadString( IDS_WORD_Nobori ) ;
				}
				CString	strMsg ;
				strMsg.Format( IDS_ERR_ExistRessyaOfRessyasyubetsu ,
					strRessyasyubetsuName , strDiaName , strRessyahoukou ) ;
				strErrorMessage = strMsg ;
			}

			if ( strErrorMessage.IsEmpty() )
			{
				strErrorMessage.Format( _T( "Error(%d)" ) , iRv ) ; 
			}
			MessageBox( strErrorMessage , NULL , MB_ICONSTOP | MB_OK ) ; 
		}
		// ****************************************************************
	}
	return iRv ;	

}
	//	[編集]-[列車種別を挿入]	
int CWndDcdGridRessyasyubetsu::
OnEDITRessyasyubetsuInsert_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( execRessyasyubetsuPropDlg( true , TRUE ) < 0 )
	{
		iRv = -1 ;	//	フォーカスの位置が不正です。
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		execRessyasyubetsuPropDlg( true , FALSE ) ;	

		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		if ( iRv < 0 )
		{
			CString strErrorMessage ;
			switch( iRv )
			{
			case -1 :	//	現在は実行できません。
				break ;
			default:
				strErrorMessage.Format( _T( "Error=%d" ) , iRv ) ;
				break ;
			}
			if ( strErrorMessage.GetLength() > 0 )
			{
				MessageBox( strErrorMessage , NULL , MB_ICONSTOP | MB_OK ) ; 
			}
		}
		// ****************************************************************
	}
	return iRv ;

}
	//	[編集]-[上へ]	*/
int CWndDcdGridRessyasyubetsu::OnRessyasyubetsuUp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	int iRessyasyubetsuIndex = -1 ;
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Focus , NULL ) )
		{
			iRv = -1 ;	//	セルの位置が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		CdRessyasyubetsuYColSpecCont aYColSpecCont = createYColSpecCont() ;
		CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
		if ( aYColSpec.getColumnType() != aYColSpec.ColumnType_Ressyasyubetsu )
		{
			iRv = -1 ;
		}
		else
		{
			iRessyasyubetsuIndex = aYColSpec.getRessyasyubetsuIndex() ;
			if ( !( 1 <= iRessyasyubetsuIndex 
				&& iRessyasyubetsuIndex< aYColSpecCont.getRessyasyubetsuCount() ) )
			{
				iRv = -1 ;	//	フォーカスの位置が不正です。(一番上の列車種別には使えません)
			}
		}
	}
	//iRessyasyubetsuIndex = フォーカスセルのある位置の列車種別Index

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		{
			CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;
			if ( pCDcdGridCell != NULL ){
				CDcdGridCell*	pCDcdGridCellNew = getCXDcdGrid()->calcMovedCell( 
					pCDcdGridCell , 0 , -1 ) ;
				if ( pCDcdGridCellNew != NULL ){
					getCFocus()->setFocusCell( pCDcdGridCellNew ) ;	
				}
			}
		}
		// --------------------------------
		//	コマンドを生成・実行
		// --------------------------------
		{
			OuNew<CRfEditCmd> pCmd( 
				new CRfEditCmd_RessyasyubetsuSwap( 
					iRessyasyubetsuIndex , 
					iRessyasyubetsuIndex - 1 ) 
			) ;
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;

}
	//	[編集]-[下へ]	*/
int CWndDcdGridRessyasyubetsu::
OnRessyasyubetsuDown_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	int iRessyasyubetsuIndex = -1 ;
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Focus , NULL ) )
		{
			iRv = -1 ;	//	セルの位置が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		CdRessyasyubetsuYColSpecCont aYColSpecCont = createYColSpecCont() ;
		CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
		if ( aYColSpec.getColumnType() != aYColSpec.ColumnType_Ressyasyubetsu )
		{
			iRv = -1 ;
		}
		else
		{
			iRessyasyubetsuIndex = aYColSpec.getRessyasyubetsuIndex() ;
			if ( !( 0 <= iRessyasyubetsuIndex 
				&& iRessyasyubetsuIndex< aYColSpecCont.getRessyasyubetsuCount() - 1 ) )
			{
				iRv = -1 ;	//	フォーカスの位置が不正です。(一番下の列車種別には使えません)
			}
		}
	}
	//iRessyasyubetsuIndex = フォーカスセルのある位置の列車種別Index

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		// --------------------------------
		//	フォーカスを移動
		// --------------------------------
		{
			CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;
			if ( pCDcdGridCell != NULL ){
				CDcdGridCell*	pCDcdGridCellNew = getCXDcdGrid()->calcMovedCell( 
					pCDcdGridCell , 0 , 1 ) ;
				if ( pCDcdGridCellNew != NULL ){
					getCFocus()->setFocusCell( pCDcdGridCellNew ) ;	
				}
			}
		}
		// --------------------------------
		//	コマンドを生成・実行
		// --------------------------------
		{
			OuNew<CRfEditCmd> pCmd( 
				new CRfEditCmd_RessyasyubetsuSwap( 
					iRessyasyubetsuIndex , 
					iRessyasyubetsuIndex + 1 ) 
			) ;
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;


}
	//	[編集]-[列車種別のプロパティ]	*/
int CWndDcdGridRessyasyubetsu::
OnEDITRessyasyubetsuProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	//	フォーカスセルが新規アイテム位置にあるときは、
	//	「新規アイテムのプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}
	if ( execRessyasyubetsuPropDlg( bInsert , TRUE ) < 0 )
	{
		iRv = -1 ;	//	フォーカスセルの位置が不正です。
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		iRv = execRessyasyubetsuPropDlg( bInsert , FALSE ) ;

		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}



// ****************************************************************
//	CWndDcdGridRessyasyubetsu
// ****************************************************************


// ********************************
//	コンストラクタ
// ********************************
CWndDcdGridRessyasyubetsu::CWndDcdGridRessyasyubetsu()
	: m_bUpdate_All_Requested( false ) 
{
	getCSelect()->setSelectMode( CSelect::SelectMode_YColumn ) ;
}
CWndDcdGridRessyasyubetsu::~CWndDcdGridRessyasyubetsu()
{
}

// ********************************
//@name	CDcdGrid
// ********************************

// ********************************
//@name	CWndDcdGrid
// ********************************

	// ********************************
	//@name CWndDcdGridRessyasyubetsu-操作
	// ********************************

int CWndDcdGridRessyasyubetsu::
execRessyasyubetsuPropDlg( bool bInsert , BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Ressyasyubetsu>	pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>*	ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;};

	// ****************************************************************
	//	コマンドの実行可否の判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( bInsert )
		{
			if ( !createCmd( ECreateCmd_NewItem , ppCmd ) )
			{
				iRv = -1 ;	//	セルの位置が不正です。
			}
		}
		else
		{
			if ( !createCmd( ECreateCmd_Select , ppCmd ) ) 
			{
				iRv = -1 ;
			}
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		CdRessyasyubetsuXColSpec	aXColSpec = getXColSpecOfFocus() ;
		int iFocusItem = -1 ;
		switch( aXColSpec.getColumnType() )
		{
		case aXColSpec.ColumnType_Syubetsumei :	iFocusItem = 0 ;	break ;
		case aXColSpec.ColumnType_Ryakusyou :	iFocusItem = 1 ;	break ;
		case aXColSpec.ColumnType_DiagramLineStyle :	iFocusItem = 2 ;	break ;
		}
		CDlgRessyasyubetsuProp	aDlg( 
			bInsert , 
			pCmd->getCaMuiSelect()->getMuPtr() , 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCdDedDispProp() ,
			iFocusItem , 
			&m_CKeyinputSenderToModalDlg , this ) ;
		if ( aDlg.DoModal() == IDOK )
		{
			iRv = 1 ;
		}			
		// --------------------------------
		//	ダイアログOK時の処理
		// --------------------------------
		if ( iRv == 1 )
		{
			// --------------------------------
			//	編集コマンドを実行
			// --------------------------------
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
	}
	return iRv ;
		

}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
BEGIN_MESSAGE_MAP(CWndDcdGridRessyasyubetsu,CWndDcdGridRessyasyubetsu::super)
	//{{AFX_MSG_MAP(CWndDcdGridRessyasyubetsu)
	ON_WM_CREATE()
	ON_WM_KEYUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_Ressyasyubetsu_Prop, OnEDITRessyasyubetsuProp)
	ON_COMMAND(ID_Ressyasyubetsu_Insert, OnEDITRessyasyubetsuInsert)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_Ressyasyubetsu_Up, OnRessyasyubetsuUp)
	ON_UPDATE_COMMAND_UI(ID_Ressyasyubetsu_Up, OnUpdateRessyasyubetsuUp)
	ON_COMMAND(ID_Ressyasyubetsu_Down, OnRessyasyubetsuDown)
	ON_UPDATE_COMMAND_UI(ID_Ressyasyubetsu_Down, OnUpdateRessyasyubetsuDown)
	ON_UPDATE_COMMAND_UI(ID_Ressyasyubetsu_Insert, &CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuInsert)
	ON_UPDATE_COMMAND_UI(ID_Ressyasyubetsu_Prop, &CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuProp)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CWndDcdGridRessyasyubetsu::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (super::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// --------------------------------
	//	列車種別ビューに使用するフォント
	// --------------------------------
	CdFontProp fontpropDefault = createFontProp() ;

	// --------------------------------
	//	列の数を指定
	// --------------------------------
	getCXDcdGrid()->setXColumnCount( XCOLUMNNCOUNT ) ;
	getCXDcdGrid()->setYColumnCount( YCOLUMNNNO_RESSYASYUBETSU_0 + YCOLUMNNCOUNT_BLANK ) ;
	getCXDcdGrid()->setYFixColumnCount( YCOLUMNNNO_RESSYASYUBETSU_0 ) ;

	// --------------------------------
	//	列のサイズを設定
	// --------------------------------
	{
		CDcdTargetGetDC	aCDcdTarget( NULL ) ;
		// --------------------------------
		//	X列
		// --------------------------------
		{
			//	種別番号
			CdDcdSizeXy	sizeRessyasyubetsumei ;
			CDcdTextbox	aCDcdTextbox( 
				"0" ,
				fontpropDefault ,
				"" , 1 , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsumei ) ;
			getCXDcdGrid()->getXColumn( XCOLUMNNNO_RESSYASYUBETSUNO )->setColumnSize( sizeRessyasyubetsumei.getX() ) ;
		}
		{
			//	種別名
			CdDcdSizeXy	sizeRessyasyubetsumei ;
			CDcdTextbox	aCDcdTextbox( 
				"京都京都京都京都京都京都" ,
				fontpropDefault ,
				"" , 1 , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsumei ) ;
			getCXDcdGrid()->getXColumn( XCOLUMNNNO_RESSYASYUBETSU )->setColumnSize( sizeRessyasyubetsumei.getX() ) ;
		}
		{
			//	略称
			CdDcdSizeXy	sizeRessyasyubetsujikokukeisiki ;

			CDcdTextbox	aCDcdTextbox( 
				"京都都" ,
				fontpropDefault ,
				"" , XCOLUMNNNO_RYAKUSYOU , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsujikokukeisiki ) ;

			getCXDcdGrid()->getXColumn( XCOLUMNNNO_RYAKUSYOU )->setColumnSize( sizeRessyasyubetsujikokukeisiki.getX() ) ;
		}
		{
			//	線スタイル
			CdDcdSizeXy	sizeRessyasyubetsukibo ;
			CDcdTextbox	aCDcdTextbox( 
				"京都京都京都" ,
				fontpropDefault ,
				"" , 1 , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsukibo ) ;

			getCXDcdGrid()->getXColumn( XCOLUMNNNO_LINESTYLE )->setColumnSize( sizeRessyasyubetsukibo.getX() ) ;
		}
		// --------------------------------
		//	Y列
		// --------------------------------
		{
			CdDcdSizeXy	sizeRessyasyubetsumei ;
			CDcdTextbox	aCDcdTextbox( 
				"京都京都京都京都京都京都" ,
				fontpropDefault ,
				"" , 1 , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsumei ) ;

			getCXDcdGrid()->getYColumn( YCOLUMNNNO_HEADER )->setColumnSize( sizeRessyasyubetsumei.getY() ) ;
			getCXDcdGrid()->getYColumn( YCOLUMNNNO_RESSYASYUBETSU_0 )->setColumnSize( sizeRessyasyubetsumei.getY() ) ;
		}
	}
	// --------------------------------
	//	最上列に属性とテキストを設定
	// --------------------------------
	{
		// 種別番号
		Ou<CDcdTextbox>	pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RESSYASYUBETSUNO , YCOLUMNNNO_HEADER )->getIfDcDraw() ;
		
		CConverter_WinGdi aCConverter_WinGdi ;
		
		CdDrawTextProp	aCdDrawTextProp( 
			fontpropDefault ,
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( 
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENU ) ) ;

		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
		pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;
	}
	{
		// 種別名
		CString	aString ;
		aString.LoadString( IDS_WORD_Ressyasyubetsumei ) ;

		Ou<CDcdTextbox>	pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RESSYASYUBETSU , YCOLUMNNNO_HEADER )->getIfDcDraw() ;
		
		CConverter_WinGdi aCConverter_WinGdi ;
		
		CdDrawTextProp	aCdDrawTextProp( 
			fontpropDefault ,
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( 
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENU ) ) ;

		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
		pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;
		pCDcdTextbox->setText( (LPCTSTR)aString ) ;
	}
	{
		// 略称
		CString	aString ;
		aString.LoadString( IDS_WORD_Ryakusyou ) ;

		Ou<CDcdTextbox>	pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RYAKUSYOU , YCOLUMNNNO_HEADER )->getIfDcDraw() ;
		
		CConverter_WinGdi aCConverter_WinGdi ;


		CdDrawTextProp	aCdDrawTextProp( 
			fontpropDefault ,
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( 
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENU ) ) ;

		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
		pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;
		pCDcdTextbox->setText( (LPCTSTR)aString ) ;
	}
	{
		//	線スタイル
		CString	aString ;
		aString.LoadString( IDS_WORD_Senstyle ) ;

		Ou<CDcdTextbox>	pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_LINESTYLE , YCOLUMNNNO_HEADER )->getIfDcDraw() ;
		
		CConverter_WinGdi	aCConverter_WinGdi ;
		CdDrawTextProp	aCdDrawTextProp( 
			fontpropDefault ,
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( 
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENU ) ) ;

		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
		pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;
		pCDcdTextbox->setText( (LPCTSTR)aString ) ;
	}
	// --------------------------------
	//	フォーカスセルの初期位置を設定
	// --------------------------------
	getCFocus()->setFocusCell( getCXDcdGrid()->getCell( 0 , YCOLUMNNNO_RESSYASYUBETSU_0 ) ) ;	
	// --------------------------------
	//	表示更新
	// --------------------------------
	InvalidateGrid() ;

	
	return 0;
}

void CWndDcdGridRessyasyubetsu::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	//	フォーカスセルが新規アイテム位置にあるときは、
	//	「新規アイテムのプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}

	// ****************************************************************
	//	コマンドの実行
	// ****************************************************************
	//	文字キーが押されていて、ダイアログボックスが開いていない場合は
	//	ダイアログボックスを開きます。
	if ( CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown() && 
			m_CKeyinputSenderToModalDlg.startSend() >= 0 )
	{
		m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) ;
		execRessyasyubetsuPropDlg( bInsert , FALSE ) ;
		m_CKeyinputSenderToModalDlg.endSend() ;
	}
	//	すでにダイアログが起動中→ダイアログボックスにメッセージを転送
	else	
	{
		if ( !m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) )
		{
			CWndDcdGridRessyasyubetsu::super::OnKeyDown(nChar, nRepCnt, nFlags);
		}
	}
			

}

void CWndDcdGridRessyasyubetsu::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	//	フォーカスセルが新規アイテム位置にあるときは、
	//	「新規アイテムのプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}
	// ****************************************************************
	//	コマンドの実行
	// ****************************************************************
	iRv = execRessyasyubetsuPropDlg( bInsert , FALSE ) ;
}

void CWndDcdGridRessyasyubetsu::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if ( !m_CKeyinputSenderToModalDlg.OnKeyUp( nChar , nRepCnt , nFlags ) )
	{
		CWndDcdGridRessyasyubetsu::super::OnKeyUp(nChar, nRepCnt, nFlags);
	}
}


void CWndDcdGridRessyasyubetsu::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC ){
		return ;
	}
	// --------------------------------
	

	CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
	const CentDedRosen*	pCentDedRosen = 
		pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet 
		= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;

	//pHint= 
	//	pHintが CRfEditCmdHolder オブジェクトなら、
	//	対応する編集コマンド CRfEditCmd を保持しています。
	//	この場合、this は CRfEditCmd の内容に最適化した
	//	更新を行います。
	//	NULLなら、全更新が要求されています。
	if ( m_bUpdate_All_Requested )
	{
		//	全更新が保留されている場合は、
		//	その後はコマンドによる最適化された単体のいかなる更新要求に対しても、全更新を行います。
		pHint = NULL ;
	}


	Ou<CRfEditCmd> pCmd ;
	if ( pHint != NULL && pHint->IsKindOf( RUNTIME_CLASS( CRfEditCmdHolder ) ) )
	{
		CRfEditCmdHolder* pHolder = 
			(CRfEditCmdHolder*)pHint ;
		pCmd = pHolder->getCmd() ; 
	}
	if ( pCmd != NULL )
	{
		if ( dynamic_castOu<CRfEditCmd_Comment>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Dia>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Eki>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Ressya>( pCmd )  
		)
		{
			//	このビューは、
			//		コメントの変更
			//		ダイヤの変更
			//		ダイヤの属性の変更
			//		駅の変更
			//		列車の変更
			//	の場合は、更新を行いません。
		}
		//	列車種別の変更
		else if ( dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd ) )
		{
			Ou<CRfEditCmd_Ressyasyubetsu>	pCommand = 
				dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd );
			

			//	コマンドオブジェクト実行によるセル移動でセル選択にならないように、
			//	セル選択を解除し、セル選択機能も一時的に中止します。
			clearSelect() ;
			CPropStack aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;

			// --------------------------------
			//	減少分の要素の削除
			// --------------------------------
			const CentDedRessyasyubetsuCont*	pCentDedRessyasyubetsuContSrc = pCommand->getCentDedRessyasyubetsuContSrc() ;
			int iGensyouSize = pCommand->getSizeDst() - pCentDedRessyasyubetsuContSrc->size() ;
			if ( iGensyouSize > 0 ){
				for ( int cnt = 0 ; cnt < iGensyouSize ; cnt ++ ){
					getCXDcdGrid()->eraseYColumn( 
						pCommand->getIndexDst() + 
						pCommand->getSizeDst() - iGensyouSize 
						+ 1 ) ;
				}
			}
			// --------------------------------
			//	増加分の要素の追加
			// --------------------------------
			int iOkikaeSize = 0 ;
			iOkikaeSize = min( pCommand->getSizeDst() , pCentDedRessyasyubetsuContSrc->size() ) ;
			int iZoukaSize = pCentDedRessyasyubetsuContSrc->size() - pCommand->getSizeDst() ;
			if ( iZoukaSize > 0 ){
				for ( int cnt = 0 ; cnt < iZoukaSize ; cnt ++ ){
					getCXDcdGrid()->insertYColumn( 
						pCommand->getIndexDst() + iOkikaeSize + cnt + 1 , 
						true ) ; 
				}
			}
			// --------------------------------
			//	要素の更新
			// --------------------------------
			{					
				for ( int cnt = 0 ; cnt < pCentDedRessyasyubetsuContSrc->size() ; cnt ++ ){
					int iRessyasyubetsuIndex = pCommand->getIndexDst() + cnt ;
					const CentDedRessyasyubetsu*	pCentDedRessyasyubetsu = pCentDedRessyasyubetsuContGet->get( iRessyasyubetsuIndex ) ;
					OnUpdate_setCentDedRessyasyubetsu_To_Column( 
						iRessyasyubetsuIndex + 1 , *pCentDedRessyasyubetsu ) ;
				}
			}
			// --------------------------------
			//	列車種別番号を更新
			// --------------------------------
			OnUpdate_setRessyasyubetsuNoXColumn() ;
		}
		//	列車種別の入替
		else if ( dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd ) )
		{
			Ou<CRfEditCmd_RessyasyubetsuSwap>	pCommand = 
				dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd );
			// --------------------------------
			//	要素の更新
			// --------------------------------
			{					
				{
					int iRessyasyubetsuIndex = pCommand->getRessyasyubetsuIndexA() ;
					const CentDedRessyasyubetsu*	pCentDedRessyasyubetsu = 
						pCentDedRessyasyubetsuContGet->get( iRessyasyubetsuIndex ) ;
					OnUpdate_setCentDedRessyasyubetsu_To_Column( 
						iRessyasyubetsuIndex + 1 , *pCentDedRessyasyubetsu ) ;
				}
				{
					int iRessyasyubetsuIndex = pCommand->getRessyasyubetsuIndexB() ;
					const CentDedRessyasyubetsu*	pCentDedRessyasyubetsu = 
						pCentDedRessyasyubetsuContGet->get( iRessyasyubetsuIndex ) ;
					OnUpdate_setCentDedRessyasyubetsu_To_Column( 
						iRessyasyubetsuIndex + 1 , *pCentDedRessyasyubetsu ) ;
				}
			}
			// --------------------------------
			//	列車種別番号を更新
			// --------------------------------
			OnUpdate_setRessyasyubetsuNoXColumn() ;
		}
		else
		{
			//CRfEditCmd_DedRosenFileDataProp
			//	  路線ファイルのプロパティの変更は、
			//	フォントの変化を伴うため、全更新が必要です。
			//CRfEditCmd_Rosen
			//CRfEditCmd_RosenFileData
			//	列車種別を包含するオブジェクトです。これが更新された場合は、
			//	全更新が必要です。
			pHint = NULL ;
		}
	}
	if ( pHint == NULL )
	{
		// --------------------------------		
		//	全要素を更新
		// --------------------------------
		CView *pView = getCDiagramEditApp()->getCMainFrame()->
			getMDIChildActiveView() ;
		if ( GetParent() == pView )
		{
			OnUpdate_All() ;
		}
		else
		{
			LogMsg( "CWndDcdGridRessyasyubetsu::OnUpdate()" 
				"m_bUpdate_All_Requested=true" ) ;
			m_bUpdate_All_Requested = true ;
		}
	}
	
	// --------------------------------
	//	列選択範囲を設定
	// --------------------------------
	{
		CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
		const CentDedRosen*	pCentDedRosen = 
			pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu 
			= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;

		int iYColumnBegin = createYColSpecCont().ColumnNumberFromSpec( 
			CdRessyasyubetsuYColSpec( CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu , 0 ) ) ;

		getCSelect()->setColumnNumberSelectLimit(
			CdDcdZoneXy( 
				CdDcdZone( 0 , INT_MAX ) , 
				CdDcdZone( iYColumnBegin , pMuCentDedRessyasyubetsu->size()   ) 
			) );
	}

}

void CWndDcdGridRessyasyubetsu::OnEDITRessyasyubetsuProp() 
{
	OnEDITRessyasyubetsuProp_Process( FALSE ) ;
}


void CWndDcdGridRessyasyubetsu::OnEDITRessyasyubetsuInsert() 
{
	OnEDITRessyasyubetsuInsert_Process( FALSE );
}

void CWndDcdGridRessyasyubetsu::OnEditClear() 
{
	OnEditClear_Process( FALSE ) ;
	
}

void CWndDcdGridRessyasyubetsu::OnUpdateEditClear(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditClear_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnEditCut() 
{
	OnEditCut_Process( FALSE );
}

void CWndDcdGridRessyasyubetsu::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditCut_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnEditCopy() 
{
	OnEditCopy_Process( FALSE );
}

void CWndDcdGridRessyasyubetsu::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditCopy_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnEditPaste() 
{
	OnEditPaste_Process( FALSE );
}

void CWndDcdGridRessyasyubetsu::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditPaste_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnRessyasyubetsuUp() 
{
	OnRessyasyubetsuUp_Process( FALSE );

}

void CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuUp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnRessyasyubetsuUp_Process( TRUE ) >= 0 ) ;

}

void CWndDcdGridRessyasyubetsu::OnRessyasyubetsuDown() 
{
	OnRessyasyubetsuDown_Process( FALSE ) ;
}

void CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuDown(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnRessyasyubetsuDown_Process( TRUE ) >= 0 ) ;
}
void CWndDcdGridRessyasyubetsu::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	LogMsg( "CWndDcdGridRessyasyubetsu::OnActivateView(%d,,)" , bActivate ) ;
	
	if ( bActivate && m_bUpdate_All_Requested )
	{
		OnUpdate_All() ;
	}
}

void CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuInsert(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEDITRessyasyubetsuInsert_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuProp(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEDITRessyasyubetsuProp_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CMenu	aMenu ;
	aMenu.LoadMenu( IDR_MENU_RESSYASYUBETSUVIEW_CONTEXT ) ;
	CMenu* pContextMenu = aMenu.GetSubMenu( 0 ) ;

	//	コンテキストメニューがマウス以外で呼び出された場合は、
	//	コンテキストメニューの表示位置は、フォーカスセルの中央の位置とします。
	if ( point.x ==-1 || point.y == -1 )
	{
		//	コンテキストメニューがマウス以外で呼び出されました
		CdDcdPosXy posxyFocusCellColumnNumber = getCFocus()->getFocusCellColumnNumber() ;
		if ( posxyFocusCellColumnNumber !=  
				CFocus::ColumnNumberPosXy_NULL() )
		{
			CdDcdZoneXy	zonexyFocusCell = getCellZone( 
				posxyFocusCellColumnNumber.getX() , 
				posxyFocusCellColumnNumber.getY() ) ;
			point.x = zonexyFocusCell.getX().getPos() + zonexyFocusCell.getX().getSize() / 2 ;
			point.y = zonexyFocusCell.getY().getPos() + zonexyFocusCell.getY().getSize() / 2 ;
			ClientToScreen( &point ) ;
		}
	}
	//point = コンテキストメニューの表示位置。
	//	-1の場合は、コンテキストメニューは表示できません。

	if ( point.x >= 0 &&  point.y >= 0 )
	{
		pContextMenu->TrackPopupMenu( 
			TPM_LEFTALIGN | TPM_RIGHTBUTTON ,
			point.x , point.y , 
			AfxGetMainWnd() ) ;	//	this を指定すると、App→Doc→View の
								//コマンドチェーンが動作しません。
	}
	else
	{
		super::OnContextMenu(pWnd, point);
	}
}
} //namespace ViewRessyasyubetsu
