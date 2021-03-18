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
//	CWndDcdGridEki.cpp
//	$Id: CWndDcdGridEki.cpp 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
#include "stdafx.h"

#include "..\resource.h"

#include "DcDraw/CDcdTargetGetDC.h"
#include "logmsg/LogMsg.h"
#include "NsOu/OuNew.h"
#include "NsOu/dynamic_castOu.h"

#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcDraw\CDcdTarget.h"
#include "DcDraw\CDcDeviceUnitSizeX.h"
#include "DcDraw\CDcDeviceUnitSizeY.h"
#include "DcDraw\CDcdText.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDraw\CDcdLine.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CConverter_Wingdi.h"

#include "..\entDed\CentDedRosen.h"
#include "..\DiagramEdit.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "CDlgEkiProp.h"
#include "CWndDcdGridEki.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/** 配列 a の要素数を返します。 */
#define arrayof(a) (sizeof(a)/sizeof(a[0]))


namespace ViewEki{
	

using namespace std ;

// ****************************************************************
//	CWndDcdGridEki
// ****************************************************************
// --------------------------------
//@name 下請関数
// --------------------------------

CDcdTextbox	CWndDcdGridEki::getCDcdEkimei()const
{
	string strExtent = getCDiagramEditDoc()->getCDedRosenFileData()->getCdDedDispProp().createEkimeiExtentString() ;
	//strExtent = 路線ファイルデータに保存されている値をもとにして、
	//	作成した、文字列幅の基準文字列です。

	//CdFontProp aCdFontProp( getCDiagramEditDoc()->getCDedRosenFileData()->
	//	getCdDedDispProp().getJikokuhyouFont() ) ;
	CdFontProp aCdFontProp(	CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
	return CDcdTextbox( "" ,
		aCdFontProp ,
		strExtent , 1 , 2 , 2 , CdPenProp() , 
		CConverter_WinGdi().CdBrushPropOf( WHITE_BRUSH ) ) ;
};
	
CDcdTextbox	CWndDcdGridEki::getCDcdEkijikokukeisiki()const
{
	//CdFontProp aCdFontProp( getCDiagramEditDoc()->getCDedRosenFileData()->
	//	getCdDedDispProp().getJikokuhyouFont() ) ;
	CdFontProp aCdFontProp(	CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
	return CDcdTextbox( "" ,
		aCdFontProp ,
		"京都京都京都" , 1 , 2 , 2 , CdPenProp() , 
		CConverter_WinGdi().CdBrushPropOf( WHITE_BRUSH ) ) ;
};
	
CDcdTextbox	CWndDcdGridEki::getCDcdEkikibo()const
{
	//CdFontProp aCdFontProp( getCDiagramEditDoc()->getCDedRosenFileData()->
	//	getCdDedDispProp().getJikokuhyouFont() ) ;
	CdFontProp aCdFontProp(	CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
	return CDcdTextbox( "" ,
		aCdFontProp ,
		"京都京都京都" , 1 , 2 , 2 , CdPenProp() , 
		CConverter_WinGdi().CdBrushPropOf( WHITE_BRUSH ) ) ;
};
	


CdEkiXColSpecCont CWndDcdGridEki::createXColSpecCont() 
{
	CdEkiXColSpecCont aSpecCont( 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont() ) ;
	return aSpecCont ;
}
CdEkiYColSpecCont CWndDcdGridEki::createYColSpecCont() 
{
	CdEkiYColSpecCont aSpecCont( 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont() ) ;
	return aSpecCont ;
}	
CdEkiXColSpec CWndDcdGridEki::getXColSpecOfFocus() 
{
	CdEkiXColSpec aSpec ;
	CdDcdPosXy aPos = getCFocus()->getFocusCellColumnNumber() ;
	if ( aPos != getCFocus()->ColumnNumberPosXy_NULL() )
	{
		CdEkiXColSpecCont aSpecCont( 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont() ) ;
		aSpec = aSpecCont.ColumnNumberToSpec( aPos.getX() ) ;
	}
	return aSpec ;
}	
CdEkiYColSpec CWndDcdGridEki::getYColSpecOfFocus() 
{
	CdEkiYColSpec aSpec ;
	CdDcdPosXy aPos = getCFocus()->getFocusCellColumnNumber() ;
	if ( aPos != getCFocus()->ColumnNumberPosXy_NULL() )
	{
		CdEkiYColSpecCont aSpecCont( 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont() ) ;
		aSpec = aSpecCont.ColumnNumberToSpec( aPos.getY() ) ;
	}
	return aSpec ;
}	
	
	
	
bool CWndDcdGridEki::
createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Eki>* ppCmd )
{
	bool bRv = false ;
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Eki> pCmd ;

	CdEkiYColSpecCont aCdYColSpecCont = createYColSpecCont() ;
	CdEkiYColSpec  aCdYColSpecOfFocus = getYColSpecOfFocus() ;

	// ********************************
	//	ECreateCmd_NewItem
	//　新規アイテムを対象としたコマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_NewItem )
	{
		//ビュー上で複数選択がOFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{
			//	新規アイテムの、初期オブジェクト
			//	駅Indexが0の場合は、駅時刻形式を「上り着時刻」とします。
			CentDedEki aNewEki ;
			if ( aCdYColSpecOfFocus.getEkiIndex() == 0 )
			{
				aNewEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
			}


			//	ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 
			//
			//- m_iIndexDst = フォーカスセルのアイテムIndex、m_iIndexSize = 0
			//- m_CentDedEkiCont = 新規作成時のアイテムの既定値
			//- CaMuiSelect = 当該アイテムを選択。
			if ( aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_Eki )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
						new CRfEditCmd_Eki( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getEkiIndex() , 
							0 , m_bAdjustByEkijikokukeisiki ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewEki , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			//　ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合:
			//- m_iIndexDst = 末尾アイテムIndex+1、m_iIndexSize = 0
			//- m_CentDedEkiCont = 新規作成時のアイテムの既定値
			//- CaMuiSelect = 当該アイテムを選択。
			else if ( aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
						new CRfEditCmd_Eki( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getEkiIndex() , 
							0 , m_bAdjustByEkijikokukeisiki ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewEki , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}
		}
		// 　ビュー上で複数選択ON:
		//	 - NULLを返します([14/05/18]旧:複数選択OFFの場合と同じ動作)

	}
	// ********************************
	//	ECreateCmd_Focus
	//　フォーカスセル上の1列車を対象としたコマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_Focus )
	{
		//ビュー上で複数選択がOFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{
			//ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 
			//- m_iIndexDst = フォーカスセルのアイテムIndex、m_iIndexSize = 1
			//- m_CentDedRessyaCont = フォーカスセル上のアイテム1個のコピー
			//- m_CaMuiSelect = フォーカスセル上のアイテムを選択。
			if ( aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_Eki )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
						new CRfEditCmd_Eki( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getEkiIndex() , 
							1 , m_bAdjustByEkijikokukeisiki ) ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			//ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合: 
			//- NULLを返します。
		}
		//ビュー上で複数選択ON
		// - NULLを返します([14/05/18]旧:複数選択OFFの場合と同じ動作)

	}
	// ********************************
	//	ECreateCmd_Select
	//　既存の単数または複数選択されている列車を対象とした
	//	コマンドを生成します。
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select )
	{
		//ビュー上で複数選択がOFF・フォーカスセルが既存アイテム上にある場合: 
		//- m_iIndexDst = フォーカスセルのアイテムIndex、m_iIndexSize = 1
		//- m_CentDedRessyaCont = フォーカスセルのあるアイテム1個のコピー
		//- CaMuiSelect = 当該列車を選択。
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_Eki )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
					new CRfEditCmd_Eki( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						aCdYColSpecOfFocus.getEkiIndex() , 
						1 , m_bAdjustByEkijikokukeisiki ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		//　時刻表ビュー上で複数選択がOFF・フォーカスセルが新規列車位置にある場合: 
		// - NULLを返します。

		//　時刻表ビュー上で複数選択ON
		// - m_iIndexDst = 選択されている列車の先頭index
		// - m_iIndexSize = 選択されている列車の末尾index-先頭index+1
		// - m_CentDedRessyaCont = 選択されている列車の先頭indexから
		//  末尾indexまでの列車のコピー
		// - CaMuiSelect は、フォーカスセルに合わせて列車を選択。
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
		//
		//- m_iIndexDst = 0、m_iIndexSize = アイテムの数
		//- m_CentDedRessyaCont = 全アイテムのコピー
		//- m_CaMuiSelect は、全アイテムを選択。
		//
		// ビュー上で複数選択がOFF・フォーカスセルが新規アイテム位置にある場合: 
		//
		//- m_iIndexDst = 0、m_iIndexSize = アイテムの数
		//- m_CentDedRessyaCont = 全アイテムのコピー
		//- CaMuiSelect は、全アイテムを選択。
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& ( aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_Eki 
			|| aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_NewEki ) )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
					new CRfEditCmd_Eki( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						0 , 
						aCdYColSpecCont.getEkiCount() ,
						m_bAdjustByEkijikokukeisiki ) ) ;
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
			deque<int> contiEkiIndex ;
			for ( int iColumnNumber = 0 ; iColumnNumber < getCXDcdGrid()->getYColumnCount() ;iColumnNumber ++ )
			{
				if ( getCSelect()->getYColumnNumberSelected( iColumnNumber ) )
				{
					CdEkiYColSpec aCdYColSpec = aCdYColSpecCont.ColumnNumberToSpec( iColumnNumber ) ;
					if ( aCdYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_Eki )
					{
						contiEkiIndex.push_back( aCdYColSpec.getEkiIndex() ) ;
					}
				}
			}
			//contiEkiIndex = 列の複数選択が実施されている場合は、
			//	選択されている駅Indexが格納されます。
			//	そうでない場合は、空です。

			if ( contiEkiIndex.size() > 1 )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					//	コマンドオブジェクト内に、選択されている駅の先頭から末尾までの
					//	駅を格納します(先頭・末尾以外には、選択されていない駅が
					//	含まれている場合もあります)
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
						new CRfEditCmd_Eki( 
							*getCDiagramEditDoc()->getCDedRosenFileData() ,
							contiEkiIndex.front() , 
							contiEkiIndex.back() - contiEkiIndex.front() + 1 ,
							m_bAdjustByEkijikokukeisiki ) ) ;

					//	コマンドオブジェクトの
					//	m_CentDedRessyaContSrc  内の列車を選択します。
					pCmd->getCaMuiSelect()->setSelectAll( false ) ;
					for ( int i = 0 ; i < (int)contiEkiIndex.size() ; i ++ )
					{
						pCmd->getCaMuiSelect()->setSelect( contiEkiIndex[i] - contiEkiIndex.front()  , true ) ;
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

/**
	CentDedEki::EEkijikokukeisiki と、文字列リソースIDの対応表
*/
struct {
	CentDedEki::EEkijikokukeisiki	m_eValue ;
	int m_iId ;
}	nameEEkijikokukeisiki[] = {
	{ CentDedEki::Jikokukeisiki_Hatsu ,IDS_WORD_Jikokukeisiki_Hatsu } ,
	{ CentDedEki::Jikokukeisiki_Hatsuchaku ,IDS_WORD_Jikokukeisiki_Hatsuchaku } ,
	{ CentDedEki::Jikokukeisiki_KudariChaku ,IDS_WORD_Jikokukeisiki_KudariChaku } ,
	{ CentDedEki::Jikokukeisiki_NoboriChaku ,IDS_WORD_Jikokukeisiki_NoboriChaku } ,
};

/**
	CentDedEki::EEkikibo と、文字列リソースIDの対応表
*/
struct {
	CentDedEki::EEkikibo	m_eValue ;
	int m_iId ;
}	nameEkikibo[] = {
	{ CentDedEki::Ekikibo_Ippan , IDS_WORD_Ekikibo_Ippan } ,
	{ CentDedEki::Ekikibo_Syuyou , IDS_WORD_Ekikibo_Syuyou } ,
};


void CWndDcdGridEki::OnUpdate_setCentDedEki_To_Column( 
	int iYColumnNumber , const CentDedEki& aCentDedEki )
{
	if ( m_bWaitForActivate )
	{
		//	ビューの更新が更新されているなら、後続の処理は行いません
		return;
	}
	// ****************************************************************
	//	ビューの更新が保留されていない
	// ****************************************************************

	bool bIsNull = aCentDedEki.getEkimei().empty() ;

	// --------------------------------
	//	列のサイズを設定
	// --------------------------------
	{
		CDcdTargetGetDC	aCDcdTarget( NULL ) ;
		// --------------------------------
		//	Y列
		// --------------------------------
		{
			CdDcdSizeXy	sizeEkimei ;
			CDcdTextbox	aCDcdTextbox( 
				getCDcdEkimei() ) ;
			aCDcdTextbox.getItemSize( 
				&aCDcdTarget , &sizeEkimei ) ;

			getCXDcdGrid()->getYColumn( iYColumnNumber )
				->setColumnSize( sizeEkimei.getY() ) ;
		}
	}
	// --------------------------------
	//	セルの属性を設定
	// --------------------------------
	{
		//	駅名列の DcDraw の属性を設定
		Ou<CDcdTextbox>	pCDcdTextbox = 
			(getCXDcdGrid()->getCell( 0 , iYColumnNumber )->getIfDcDraw());
		*pCDcdTextbox = this->getCDcdEkimei() ;
	}
	{
		//	駅名列の DcDraw の属性を設定
		Ou<CDcdTextbox>	pCDcdTextbox = 
			(getCXDcdGrid()->getCell( 1 , iYColumnNumber )->getIfDcDraw());
		*pCDcdTextbox = this->getCDcdEkijikokukeisiki() ;
	}
	{
		//	駅規模
		Ou<CDcdTextbox>	pCDcdTextbox = 
			(getCXDcdGrid()->getCell( 2 , iYColumnNumber )->getIfDcDraw());
		*pCDcdTextbox = this->getCDcdEkikibo() ;
	}

	
	// --------------------------------
	//	セルのテキストを設定
	// --------------------------------
	//	駅名
	{
		Ou<CDcdTextbox>(getCXDcdGrid()
			->getCell( 	0 , iYColumnNumber )->getIfDcDraw())
				->setText( aCentDedEki.getEkimei() )  ;	
	}
	//	駅時刻形式
	{
		string	strEkijikokukeisiki ;
		if ( !bIsNull )
		{
			int idx ;	
			for ( idx = 0 ; 
				idx < arrayof( nameEEkijikokukeisiki ) ; idx ++ )
			{
				if ( nameEEkijikokukeisiki[idx].m_eValue 
					== aCentDedEki.getEkijikokukeisiki() )
				{
					CString	strLs ;
					strLs.LoadString( nameEEkijikokukeisiki[idx].m_iId ) ;
					strEkijikokukeisiki = (LPCSTR)strLs ;
					break ;
				}
			}
		}
		Ou<CDcdTextbox>(getCXDcdGrid()
			->getCell( 1 , iYColumnNumber )->getIfDcDraw())->
				setText( strEkijikokukeisiki )  ;	
	}
	//	駅規模
	{
		string	strEkikibo ;
		if ( !bIsNull ){
			int idx ;	
			for ( idx = 0 ; idx < arrayof( nameEkikibo ) ;	idx ++ ){
				if ( nameEkikibo[idx].m_eValue == 
						aCentDedEki.getEkikibo() )
				{
					CString	strLs ;
					strLs.LoadString( nameEkikibo[idx].m_iId ) ;
					strEkikibo = (LPCSTR)strLs ;
					break ;
				}
			}
		}
		Ou<CDcdTextbox>(getCXDcdGrid()->
			getCell( 2 , iYColumnNumber )->getIfDcDraw())
				->setText( strEkikibo )  ;	
		
	}
	// --------------------------------
	//	境界線
	// --------------------------------
	{
		CdPenProp aCdPenProp = getCdPenPropNormal() ;
		if ( !bIsNull ){
			if ( aCentDedEki.getKyoukaisen() ){
				aCdPenProp = getCdPenPropBold() ;
			}
		}
		Ou<CDcdLine>
			( getCXDcdGrid()->getYBorder( iYColumnNumber )->getIfDcDraw())
				->setCdPenProp( aCdPenProp ) ;
	}

	// --------------------------------
	//	グリッド全体を更新領域とします
	// --------------------------------
	//	境界線の太さが変動した場合は、
	//	境界線・およびそれより下のすべてのセルの更新が必要です。
	//	これに対応するため、 CWndDcdGridEki では、
	//	駅の属性の更新のたびに
	//	グリッド全域を更新します。
	InvalidateGrid() ;
}

void CWndDcdGridEki::OnUpdate_All() 
{
	CView *pView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	if ( GetParent() != pView )
	{
		// ****************************************************************
		//	ビューがアクティブではない
		// ****************************************************************
		m_bWaitForActivate = true ;
	}
	else
	{
		// ****************************************************************
		//	ビューがアクティブ
		// ****************************************************************
		CWaitCursor	aCWaitCursor ;	

		// --------------------------------
		//	ビューの更新を行うために OnUpdate_XXX() を呼び出すなら
		//	あらかじめ以下のフラグを false にしなくてはなりません
		m_bWaitForActivate = false ;

		//	コマンドオブジェクト実行によるセル移動でセル選択にならないように、
		//	セル選択を解除し、セル選択機能も一時的に中止します。
		clearSelect() ;
		CPropStack aPropStack( this ) ;
		aPropStack
			.CBoxSelect_setIsEnable( false )
			.CRandomSelect_setIsEnable( false )  ;


		// --------------------------------
		//	ビューを更新
		// --------------------------------
		CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
		const CentDedRosen*	pCentDedRosen = 
			pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedEki*>* pCentDedEkiContGet = 
			pCentDedRosen->getCentDedEkiCont()->getMuPtr() ;

		//	Y列数を増減させる
		getCXDcdGrid()->setYColumnCount( 
			pCentDedEkiContGet->size() + 2 ) ;

		//	駅名列の幅を設定する
		{
			CDcdTargetGetDC	aTarget ;
			CDcdTextbox aCDcd = this->getCDcdEkimei() ;
			CdDcdSizeXy	aCdDcdSizeXy ;
			aCDcd.getItemSize( &aTarget , &aCdDcdSizeXy ) ;
			getCXDcdGrid()->getXColumn( 0 )->setColumnSize( 
				aCdDcdSizeXy.getX() ) ;
		}

		//	各セルに、データを設定
		int idxEki ;
		for ( idxEki = 0 ; idxEki < pCentDedEkiContGet->size() ; 
				idxEki ++ ){
			const CentDedEki* pCentDedEki = pCentDedEkiContGet->get( idxEki ) ;
			OnUpdate_setCentDedEki_To_Column( idxEki + 1 , *pCentDedEki ) ;
		} 
		OnUpdate_setCentDedEki_To_Column( idxEki + 1 , CentDedEki() ) ;
		// ****************************************************************
	}
}

	// --------------------------------
	//@name メニューコマンドの下請関数
	// --------------------------------
int CWndDcdGridEki::OnEditCut_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki> pCmd ;
	Ou<CRfEditCmd_Eki>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}
	
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( CWndDcdGridEki::ECreateCmd_Select , ppCmd ) )
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
		getCDiagramEditDoc()->CentDedEki_To_Cliboard( 
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
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;	

}
int CWndDcdGridEki::OnEditCopy_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki> pCmd ;
	Ou<CRfEditCmd_Eki>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}
	
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( CWndDcdGridEki::ECreateCmd_Select , ppCmd ) )
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
		getCDiagramEditDoc()->CentDedEki_To_Cliboard( 
			pCmd->getCaMuiSelect() ) ;

		// -------------------------------- 
		//	フォーカスセルを、選択要素中で最大の駅Indexの次位に移動
		// --------------------------------
		{
			//	セル選択をクリアし、
			//	フォーカスセルの移動によるセル選択を無効化します。
			clearSelect() ;
			CPropStack	aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		
			//	選択要素中で最大の駅Index を求める
			int iEkiIndexMax = -1 ;
			{
				CaMuiSelect<CentDedEki>* pCaMuiSelect = pCmd->getCaMuiSelect() ;
				for ( int iIndex = pCaMuiSelect->getAdapteeMu()->size() - 1  ; 
					iEkiIndexMax == -1 && iIndex >= 0 ; iIndex -- )
				{
					if ( pCaMuiSelect->getSelect( iIndex ) )
					{
						iEkiIndexMax = iIndex + pCmd->getIndexDst() ;
					}
				}
			}
			//iEkiIndexMax = 選択されている列車のうち、最大のIndex

			//	移動先のフォーカスセル位置を決定
			int iYColumnNmber = -1 ;
			{
				CdEkiYColSpecCont aCdEkiYColSpecCont = createYColSpecCont() ;
				iYColumnNmber = aCdEkiYColSpecCont.ColumnNumberFromSpec( 
					CdEkiYColSpec( CdEkiYColSpec::ColumnType_Eki , iEkiIndexMax ) ) + 1 ;
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
int CWndDcdGridEki::OnEditPaste_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki> pCmd ;
	Ou<CRfEditCmd_Eki>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}
	
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( CWndDcdGridEki::ECreateCmd_NewItem , ppCmd ) )
		{
			iRv = -1 ;	//	セルの位置が正しくありません。
		}
	}
	if ( iRv >= 0 )
	{
		if ( !getCDiagramEditDoc()->CentDedEki_IsClipboardFormatAvailable() )
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
		CentDedEkiCont	aEkiCont ;
		getCDiagramEditDoc()->CentDedEki_From_Cliboard( &aEkiCont ) ;
		// --------------------------------
		//	コマンドオブジェクトの駅を編集
		// --------------------------------
		{
			//	CWndDcdGridEki::ECreateCmd_NewItem によって生成された
			//	新規アイテムは削除します。
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;

			//	コマンドにクリップボードからのアイテムを追加します。
			CaMui<CentDedEki> aCaMui( pCmd->getCaMuiSelect() ) ;
			aCaMui.insert( &aEkiCont , 0 , INT_MAX , 0 ) ;
		}
		// --------------------------------
		//	コマンドオブジェクトを実行
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}

	}
	return iRv ;

}
int CWndDcdGridEki::OnEditClear_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki> pCmd ;
	Ou<CRfEditCmd_Eki>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}
	
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( CWndDcdGridEki::ECreateCmd_Select , ppCmd ) )
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
		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;	

}

	/*	
		[編集]-[駅を挿入]
	@return
		成功したら0以上、エラーなら負の数です。
	*/
int CWndDcdGridEki:: OnEDITEkiInsert_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************
	if ( execEkiPropDlg( true , TRUE ) < 0 )
	{
		iRv = -1 ;	//	フォーカスの位置が不正です。
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		execEkiPropDlg( true , FALSE ) ;

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

int CWndDcdGridEki::OnEditEkiInvert_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	// ****************************************************************
	//	コマンドの実行可否の判定
	// ****************************************************************
	//	コマンドの実行の可否を判定します。
	//	コマンドが実行不可能なら、 iRv に負の数を設定してください。

	const CentDedRosen*	pCentDedRosen = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedEki*>* pCentDedEkiContGet = pCentDedRosen->getCentDedEkiCont()->getMuPtr() ;
	
	
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		//	コマンドを実行します。
		//	結果がエラーなら、iRv に負の数を設定します。

		CentDedRosen	aRosenNew ;
		if ( iRv >= 0 )
		{
			//	路線を取得後、上下を反転します。
			aRosenNew = *pCentDedRosen ;
			aRosenNew.invert() ;

			//	更新コマンドを生成
		}
		// --------------------------------
		//	コマンドを生成・実行
		// --------------------------------
		if ( iRv >= 0 )
		{
			OuNew<CRfEditCmd> pCmd(
				new CRfEditCmd_Rosen( aRosenNew )  
			);
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
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

	/*	
		[編集]-[駅のプロパティ]
	*/
int CWndDcdGridEki:: OnEDITEkiProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	//	フォーカスセルが新規アイテム位置にあるときは、
	//	「新規アイテムのプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdEkiYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}

	if ( execEkiPropDlg( bInsert , TRUE ) < 0 )
	{
		iRv = -1 ;	//	-1 ;	//	フォーカスセルの位置が不正です。
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	コマンドの実行
		// ****************************************************************
		//	コマンドを実行します。
		//	結果がエラーなら、iRv に負の数を設定します。

		execEkiPropDlg( bInsert , FALSE ) ;

		// ****************************************************************
		//	エラーメッセージ
		// ****************************************************************
		// ****************************************************************
	}
	return iRv ;
}

// ********************************
//	コンストラクタ
// ********************************
CWndDcdGridEki::CWndDcdGridEki()
	: m_bAdjustByEkijikokukeisiki( true ) 
 	, m_bWaitForActivate( true )
	, m_bInitialUpdateComplete( false )
{
	getCSelect()->setSelectMode( CSelect::SelectMode_YColumn ) ;

}
CWndDcdGridEki::~CWndDcdGridEki()
{
}

	// ********************************
	//@name CWndDcdGridEki-属性
	// ********************************
bool CWndDcdGridEki::getAdjustByEkijikokukeisiki()const 
{
	return m_bAdjustByEkijikokukeisiki ;
}
int CWndDcdGridEki::setAdjustByEkijikokukeisiki( bool value ) 
{
	int iRv = 0 ;
	if ( m_bAdjustByEkijikokukeisiki != value )
	{
		m_bAdjustByEkijikokukeisiki = value ;

		//	.ini ファイルに保存
		getCDiagramEditApp()->writeCWndDcdGridEkiProp( this ) ;
		
		iRv = 1 ;
	}
	return iRv ;
}



	// ********************************
	//@name CEkiView からの委譲
	// ********************************
void CWndDcdGridEki::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC )
	{
		//	ビューの内容をドキュメントに反映させる指令です。
		//	後続の処理は行いません。
		return ;
	}
	// --------------------------------
	//	初回のOnUpdate()
	//	.iniファイルからプロパティを読み込み
	// --------------------------------
	if ( !m_bInitialUpdateComplete )
	{
		getCDiagramEditApp()->readCWndDcdGridEkiProp( this ) ;
		// --------------------------------
		m_bInitialUpdateComplete = true ;
	}

	// --------------------------------
	//	更新コマンドを取得
	// --------------------------------
	Ou<CRfEditCmd> pCmd ;
	if ( pHint != NULL 
		&& pHint->IsKindOf(RUNTIME_CLASS(CRfEditCmdHolder)) )
	{
		CRfEditCmdHolder* pHolder = 
			(CRfEditCmdHolder*)pHint ;
		pCmd = pHolder->getCmd() ; 
	}
	//pCmd=編集コマンド CRfEditCmd 。
	//	NULLなら、全更新が要求されています。

	//pHint= 
	//	pHintが CRfEditCmdHolder オブジェクトなら、
	//	対応する編集コマンド CRfEditCmd を保持しています。
	//	この場合、this は CRfEditCmd の内容に最適化した
	//	更新を行います。
	//	NULLなら、全更新が要求されています。

	if ( m_bWaitForActivate )
	{
		//	全更新が保留されている場合は、
		//	コマンドを無視して、全更新を行います。
		pCmd = Ou<CRfEditCmd>() ;
	}

	// --------------------------------
	{
		CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
		const CentDedRosen*	pCentDedRosen = 
			pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedEki*>* pCentDedEkiContGet 
			= pCentDedRosen->getCentDedEkiCont()->getMuPtr() ;

		if ( dynamic_castOu<CRfEditCmd_Comment>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Dia>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Ressya>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd )||
			dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>
				( pCmd ) 
		)
		{
			//	このビューは、
			//		コメントの変更
			//		ダイヤの変更
			//		ダイヤのプロパティの変更
			//		列車の変更
			//		列車の直通化
			//		列車種別の変更
			//		列車種別の入替
			//	の場合は、更新を行いません。
			//
		}
		else if ( dynamic_castOu<CRfEditCmd_Eki>( pCmd ) )
		{	
			//		駅の変更
			Ou<CRfEditCmd_Eki>	pCommand 
				= dynamic_castOu<CRfEditCmd_Eki>( pCmd );

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
			CentDedEkiCont	aCentDedEkiContSrc 
				= *pCommand->getCentDedEkiContSrc() ;
			int iGensyouSize = 
				pCommand->getSizeDst() - aCentDedEkiContSrc.size() ;
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
			iOkikaeSize = 
				min( pCommand->getSizeDst() , aCentDedEkiContSrc.size() ) ;
			int iZoukaSize = 
				aCentDedEkiContSrc.size() - pCommand->getSizeDst() ;
			if ( iZoukaSize > 0 )
			{
				for ( int cnt = 0 ; cnt < iZoukaSize ; cnt ++ )
				{
					getCXDcdGrid()->insertYColumn( 
						pCommand->getIndexDst() + iOkikaeSize + cnt + 1 , 
						true ) ; 
				}
			}
			// --------------------------------
			//	要素の更新
			// --------------------------------
			{					
				for ( int cnt = 0 ; cnt < aCentDedEkiContSrc.size() ; cnt ++ )
				{
					int iEkiIndex = pCommand->getIndexDst() + cnt ;
					const CentDedEki*	pCentDedEki 
						= pCentDedEkiContGet->get( iEkiIndex ) ;
					OnUpdate_setCentDedEki_To_Column( 
						iEkiIndex + 1 , *pCentDedEki ) ;
				}
			}
			// --------------------------------
		}
		else
		{
			//CRfEditCmd_DedRosenFileDataProp
			//	  路線ファイルのプロパティの変更は、
			//	フォントの変化を伴うため、全更新が必要です。
			//CRfEditCmd_Rosen
			//CRfEditCmd_RosenFileData
			//	駅を包含するオブジェクトです。これが更新された場合は、
			//	全更新が必要です。

			//	全要素を更新
			OnUpdate_All() ;
		}
	}
	// --------------------------------
	//	列選択範囲を設定
	// --------------------------------
	{
		CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
		const CentDedRosen*	pCentDedRosen = 
			pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedEki*>* pCentDedEkiContGet 
			= pCentDedRosen->getCentDedEkiCont()->getMuPtr() ;

		int iYColumnBegin = createYColSpecCont().ColumnNumberFromSpec( 
			CdEkiYColSpec( CdEkiYColSpec::ColumnType_Eki , 0 ) ) ;

		getCSelect()->setColumnNumberSelectLimit(
			CdDcdZoneXy( 
				CdDcdZone( 0 , INT_MAX ) , 
				CdDcdZone( iYColumnBegin , pCentDedEkiContGet->size()   ) 
			) );
	}
}

void CWndDcdGridEki::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	if ( bActivate && m_bWaitForActivate ){
		OnUpdate_All() ;
	}
}





	// ********************************
	//@name CWndDcdGridEki-操作
	// ********************************
	
int CWndDcdGridEki::execEkiPropDlg( bool bInsert , BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki>	pCmd ;
	Ou<CRfEditCmd_Eki>*	ppCmd = NULL ;
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
		CdEkiXColSpec	aXColSpec = getXColSpecOfFocus() ;
		int iFocus = -1 ;
		switch( aXColSpec.getColumnType() )
		{
		case aXColSpec.ColumnType_Ekimei:
			iFocus = 0 ; 
			break ;
		case aXColSpec.ColumnType_Ekijikokukeisiki:
			iFocus = 1 ;
			break ;
		case aXColSpec.ColumnType_Ekikibo:
			iFocus = 2 ;
			break ;
		}
		CDlgEkiProp	aDlg( 
			pCmd->getCaMuiSelect()->getMuPtr() ,
			&m_bAdjustByEkijikokukeisiki , 
			iFocus , 
			&m_CKeyinputSenderToModalDlg , 
			this ) ;
		if ( aDlg.DoModal() == IDOK )
		{
			iRv = 1 ;

			//	[駅時刻を駅時刻形式で正規化]の設定を、
			//	次に実行するコマンドに反映します。
			pCmd->setAdjustByEkijikokukeisiki( m_bAdjustByEkijikokukeisiki ) ;
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

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
BEGIN_MESSAGE_MAP(CWndDcdGridEki,CWndDcdGridEki::super)
	//{{AFX_MSG_MAP(CWndDcdGridEki)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYUP()
	ON_COMMAND(ID_EDIT_EkiProp, OnEDITEkiProp)
	ON_COMMAND(ID_EDIT_EkiInsert, OnEDITEkiInsert)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_EDIT_EKI_INVERT, &CWndDcdGridEki::OnEditEkiInvert)
	ON_UPDATE_COMMAND_UI(ID_EDIT_EKI_INVERT, &CWndDcdGridEki::OnUpdateEditEkiInvert)
	ON_UPDATE_COMMAND_UI(ID_EDIT_EkiInsert, &CWndDcdGridEki::OnUpdateEditEkiinsert)
	ON_UPDATE_COMMAND_UI(ID_EDIT_EkiProp, &CWndDcdGridEki::OnUpdateEditEkiprop)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

int CWndDcdGridEki::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (super::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// --------------------------------
	//	列の数を指定
	// --------------------------------
	getCXDcdGrid()->setXColumnCount( 3 ) ;
	getCXDcdGrid()->setYColumnCount( 2 ) ;
	getCXDcdGrid()->setYFixColumnCount( 1 ) ;

	// --------------------------------
	//	列のサイズを設定
	// --------------------------------
	{
		CDcdTargetGetDC	aCDcdTarget( NULL ) ;
		// --------------------------------
		//	X列
		// --------------------------------
		{
			//	駅名
			CDcdGridXColumn* pCDcdGridXColumn = getCXDcdGrid()->getXColumn( 0 ) ;
			CdDcdSizeXy	sizeEkimei ;
			CDcdTextbox	aCDcdTextbox( getCDcdEkimei() ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeEkimei ) ;
			pCDcdGridXColumn->setColumnSize( sizeEkimei.getX() ) ;
		}
		{
			//	駅時刻形式
			CDcdGridXColumn* pCDcdGridXColumn = getCXDcdGrid()->getXColumn( 1 ) ;
			CdDcdSizeXy	sizeEkijikokukeisiki ;
			CDcdTextbox	aCDcdTextbox( 
				getCDcdEkijikokukeisiki() ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeEkijikokukeisiki ) ;

			pCDcdGridXColumn->setColumnSize( sizeEkijikokukeisiki.getX() ) ;
		}
		{
			//	駅規模
			CDcdGridXColumn* pCDcdGridXColumn = getCXDcdGrid()->getXColumn( 2 ) ;
			CdDcdSizeXy	sizeEkikibo ;
			CDcdTextbox	aCDcdTextbox( 
				getCDcdEkikibo() ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeEkikibo ) ;

			pCDcdGridXColumn->setColumnSize( sizeEkikibo.getX() ) ;
		}
		// --------------------------------
		//	Y列
		// --------------------------------
		{
			CdDcdSizeXy	sizeEkimei ;
			CDcdTextbox	aCDcdTextbox( 
				getCDcdEkimei() ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeEkimei ) ;

			getCXDcdGrid()->getYColumn( 0 )->setColumnSize( sizeEkimei.getY() ) ;
			getCXDcdGrid()->getYColumn( 1 )->setColumnSize( sizeEkimei.getY() ) ;
		}
	}
	// --------------------------------
	//	最上行にテキストを設定
	// --------------------------------
	{
		CConverter_WinGdi	aConv ;
		
		CdDrawTextProp	aCdDrawTextProp( 
			aConv.CdFontPropOf( DEFAULT_GUI_FONT ) ,
			aConv.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( aConv.CdColorPropOfSysColor( COLOR_MENU ) ) ;



		{
			//	駅名
			CDcdGridCell* pCDcdGridCell = getCXDcdGrid()->getCell( 0 , 0 ) ;

			Ou<CDcdTextbox>	pCDcdTextbox = 
				pCDcdGridCell->getIfDcDraw() ;
			pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
			pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;

			CString	aString ;
			aString.LoadString( IDS_WORD_Ekimei ) ;
			Ou<CDcdTextbox>(pCDcdGridCell->getIfDcDraw())->setText( (LPCTSTR)aString ) ;
		}
		{
			//	駅時刻形式
			CDcdGridCell* pCDcdGridCell = getCXDcdGrid()->getCell( 1 , 0 ) ;

			Ou<CDcdTextbox>	pCDcdTextbox = 
				pCDcdGridCell->getIfDcDraw() ;
			pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
			pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;

			CString	aString ;
			aString.LoadString( IDS_WORD_Jikokukeisiki ) ;
			Ou<CDcdTextbox>(pCDcdGridCell->getIfDcDraw())->setText( (LPCTSTR)aString ) ;
		}
		{
			//	駅規模
			CDcdGridCell* pCDcdGridCell = getCXDcdGrid()->getCell( 2 , 0 ) ;

			Ou<CDcdTextbox>	pCDcdTextbox = 
				pCDcdGridCell->getIfDcDraw() ;
			pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
			pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;

			CString	aString ;
			aString.LoadString( IDS_WORD_Ekikibo ) ;
			Ou<CDcdTextbox>(pCDcdGridCell->getIfDcDraw())->setText( (LPCTSTR)aString ) ;
		}
	}
	// --------------------------------
	//	フォーカスセルの初期位置を設定
	// --------------------------------
	getCFocus()->setFocusCell( getCXDcdGrid()->getCell( 0 , 1 ) ) ;	
	
	return 0;
}

void CWndDcdGridEki::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	LogMsg( "CWndDcdGridEki::OnKeyDown(%08X,%04X,%08X)" , nChar, nRepCnt, nFlags) ; 

	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	//	フォーカスセルが新規アイテム位置にあるときは、
	//	「新規アイテムのプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdEkiYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}

	// ****************************************************************


	//	文字キーが押されていて、ダイアログボックスが開いていない場合は
	//	ダイアログボックスを開きます。
	if ( CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown() && 
			m_CKeyinputSenderToModalDlg.startSend() >= 0 )
	{
		m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) ;
		execEkiPropDlg( bInsert , FALSE ) ;
		m_CKeyinputSenderToModalDlg.endSend() ;
	}
	//	すでにダイアログが起動中→ダイアログボックスにメッセージを転送
	else	
	{
		if ( !m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) )
		{
			CWndDcdGridEki::super::OnKeyDown(nChar, nRepCnt, nFlags);
		}
	}
			
}

void CWndDcdGridEki::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	コマンドの有効・無効判定
	// ****************************************************************

	//	フォーカスセルが新規アイテム位置にあるときは、
	//	「新規アイテムのプロパティ入力を行い、それを末尾に挿入する」という
	//	動作になります。
	bool bInsert = false ;
	CdEkiYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}

	// ****************************************************************
	//	コマンドの実行
	// ****************************************************************
	if ( execEkiPropDlg( bInsert , FALSE ) < 0 )
	{
		iRv = -1 ;	//	-1 ;	//	フォーカスセルの位置が不正です。
	}
	// ****************************************************************

	CWndDcdGridEki::super::OnLButtonDblClk(nFlags, point);
}

void CWndDcdGridEki::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if ( !m_CKeyinputSenderToModalDlg.OnKeyUp( nChar , nRepCnt , nFlags ) )
	{
		CWndDcdGridEki::super::OnKeyUp(nChar, nRepCnt, nFlags);
	}
}

void CWndDcdGridEki::OnEDITEkiProp() 
{
	OnEDITEkiProp_Process( FALSE );
}
void CWndDcdGridEki::OnUpdateEditEkiprop(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEDITEkiProp_Process( TRUE ) >= 0 ) ;
}


void CWndDcdGridEki::OnEDITEkiInsert() 
{
	OnEDITEkiInsert_Process( FALSE ) ;
}
void CWndDcdGridEki::OnUpdateEditEkiinsert(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEDITEkiInsert_Process( TRUE ) >= 0 ) ;
}


void CWndDcdGridEki::OnEditClear() 
{
	OnEditClear_Process( FALSE ) ;
}

void CWndDcdGridEki::OnEditCut() 
{
	OnEditCut_Process( FALSE ) ;
}

void CWndDcdGridEki::OnEditCopy() 
{
	OnEditCopy_Process( FALSE ) ;

}

void CWndDcdGridEki::OnEditPaste() 
{
	OnEditPaste_Process( FALSE ) ;
	
}

void CWndDcdGridEki::OnUpdateEditClear(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditClear_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridEki::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditCut_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridEki::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditCopy_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridEki::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditPaste_Process( TRUE ) >= 0 ) ;
}


void CWndDcdGridEki::OnEditEkiInvert()
{
	OnEditEkiInvert_Process( FALSE ) ;
}

void CWndDcdGridEki::OnUpdateEditEkiInvert(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEditEkiInvert_Process( TRUE ) >= 0 ) ;
}



void CWndDcdGridEki::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CMenu	aMenu ;
	aMenu.LoadMenu( IDR_MENU_EKIVIEW_CONTEXT ) ;
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

} //namespace ViewEki
