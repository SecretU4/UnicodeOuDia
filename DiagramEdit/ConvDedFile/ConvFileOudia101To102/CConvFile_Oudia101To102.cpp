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
// $Id: CConvFile_Oudia101To102.cpp 174 2014-05-05 13:26:26Z okm $
// ****************************************************************

#include "stdafx.h"
#include "CConvFile_Oudia101To102.h"

#include <string>
#include <vector>

#include "Str\strToVector.h"
#include "Str\strLf.h"
#include "Str\strToWstr.h"
#include "ou\dynamic_castOu.h"
#include "ou\OuNew.h"
#include "DcdCd\DcDrawProp\CconvDcDrawProp.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DedRosenFileData\CconvCDedRosenFileData.h"


namespace ConvFile_Oudia101To102{


static const char nameFileType[] = "FileType" ;
static const char valueFileTypeLeftFormat[] = "OuDia.1.01" ;
static const char valueFileTypeRightFormat[] = "OuDia.1.02" ;
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia101To102 Ver 0.01" ;


// ****************************************************************
//	CConvFile_Oudia101To102
// ****************************************************************
	// --------------------------------
	//@name 下請関数
	// --------------------------------
CdFontProp CConvFile_Oudia101To102::createVFontPropFromHFont( 
		const CdFontProp& aCdFontProp ) 
{
	int iRv = 0 ;

	CdFontProp	aCdFontPropV = aCdFontProp ;
	aCdFontPropV.setFacename( string( "@" ) + aCdFontPropV.getFacename() ) ;
	CConverter_WinGdi	aConv ;
	Ou<CGdiHFontHolder>	aHFontHolder = aConv.createGdiHFontHolder( aCdFontPropV ) ;
	if ( aHFontHolder != NULL )
	{
		LOGFONT	aLOGFONT ;
		int iResult = GetObject( aHFontHolder->getHFont() , sizeof(aLOGFONT) , &aLOGFONT ) ;
		if ( iResult == 0 ){
			iRv = -2 ;	//	GetObjectに失敗
		}
		else
		{
			aCdFontPropV.setFacename( OuLib::stringOf( aLOGFONT.lfFaceName ) ) ;
		}
	}
	return aCdFontPropV ;
}


	// ********************************
	//	コンストラクタ
	// ********************************

CConvFile_Oudia101To102::CConvFile_Oudia101To102()
{
}
CConvFile_Oudia101To102::~CConvFile_Oudia101To102()
{
}
	// ********************************
	//@name IfConvFile
	// ********************************
int CConvFile_Oudia101To102::LeftToRight( 
		const IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pRightFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	int iRv = 0 ;
	string strErrorInfoString ;
	// --------------------------------
	//	ファイルフォーマットの確認
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult = isLeftFormat( pLeftFormat ) ;
		//	-	-1 ;	//	FileType が正しくありません。
		//	-	-11 ;	//	ファイルが正しいフォーマットではありません。
		if ( iResult < 0 )
		{
			switch( iResult )
			{
			case -1 :	//	FileType が正しくありません。
				strErrorInfoString = "FileType Mismatch." ;
				break ;
			case -11 :	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。	
				strErrorInfoString = "File Format Error." ;
				break ;
			}
			iRv = iResult ;
		}
		//iRv = 
		//	-	-1 ;	//	FileType が正しくありません。
		//	-	-11 ;	//	ファイルが正しいフォーマットではありません。
	}
	// --------------------------------
	//	バイト列を 
	//	OuPropertiesText::CNodeContainer に読み込み
	// --------------------------------
	string strLeftFormat ;
	if ( iRv >= 0 )
	{
		vector<char> binLeftFormat ;
		binLeftFormat.resize( pLeftFormat->size() ) ;
		if ( binLeftFormat.size() > 0 )
		{
			pLeftFormat->read( 
				&binLeftFormat[0] , 
				0 , 
				binLeftFormat.size() ) ;
		}
		strLeftFormat = OuLib::stringOf( binLeftFormat ) ;
		strLeftFormat = OuLib::strLfOf( strLeftFormat ) ;
	}
	//strLeftFormat = LeftFile の内容

	CNodeContainer	nodecontRoot ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		int iResult = aConv.decode( 
			strLeftFormat , 
			&nodecontRoot ,
			&strErrorInfoString ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	ファイルが正しいフォーマットではありません。
		}
	}
	//nodecontRoot = LeftFileの内容を保持しています。

	// --------------------------------
	//□FileType
	//	  "OuDia.1.01"→"OuDia.1.02" に変換します。
	// --------------------------------
	if ( iRv >= 0 )
	{
		nodecontRoot.setValue( 
			nameFileType , 
			valueFileTypeRightFormat ) ;
	}
	// --------------------------------
	//	CDedRosenFileを生成
	// --------------------------------
	CDedRosenFileData	aCDedRosenFileData ;
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData	aConv ;
		ErrorInfo::COuErrorInfoContainer	aErrorInfoConteiner ;

		int iResult = aConv.CDedRosenFileData_from_OuPropertiesText( 
			&aCDedRosenFileData ,
			&nodecontRoot ,
			&aErrorInfoConteiner ) ;
		if ( iResult < 0 )
		{
			iRv = -21 ;	//	CDedRosenFileData への変換に失敗しました。
			strErrorInfoString = aErrorInfoConteiner.toOuErrorInfoText() ;
		}
	}
	

	// --------------------------------
	//□Rosen.Eki[0].Ekijikokukeisiki
	//	　"Jikokukeisiki_Hatsu"→"Jikokukeisiki_NoboriChaku" に変更
	// --------------------------------
	CentDedRosen* pCentDedRosen = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedRosen = aCDedRosenFileData.getCentDedRosen() ;
		if ( pCentDedRosen->getCentDedEkiCont()->size() > 0 ) 
		{
			CentDedEki aCentDedEki = pCentDedRosen->getCentDedEkiCont()->get( 0 ) ;
			if ( aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsu )
			{
				aCentDedEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
			}
			pCentDedRosen->getCentDedEkiCont()->set( aCentDedEki ,0 );
			pCentDedRosen->adjustByEkijikokukeisiki( 0 ) ;
		}
	}
	// --------------------------------
	//□Rosen.Eki[末尾].Ekijikokukeisiki
	//	　"Jikokukeisiki_Hatsu"→"Jikokukeisiki_KudariChaku" に変更
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCentDedRosen = aCDedRosenFileData.getCentDedRosen() ;
		if ( pCentDedRosen->getCentDedEkiCont()->size() > 0 ) 
		{
			CentDedEki aCentDedEki = pCentDedRosen->getCentDedEkiCont()->get( INT_MAX ) ;
			if ( aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsu )
			{
				aCentDedEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_KudariChaku ) ;
			}
			pCentDedRosen->getCentDedEkiCont()->set( aCentDedEki ,INT_MAX );
			pCentDedRosen->adjustByEkijikokukeisiki( INT_MAX ) ;
		}
	}
	// --------------------------------
	//□DispProp.JikokuhyouVFont
	//	　DispProp.JikokuhyouFont[0] のフェイス名の先頭に "@" を付与して 
	//	CreateFont() を行います。
	//	　生成されたフォントの属性を、この値にセットします。
	// --------------------------------
	if ( iRv >= 0 )
	{
		CdDedDispProp aCdDedDispProp = aCDedRosenFileData.getCdDedDispProp() ;
		CdFontProp	aCdFontProp = aCdDedDispProp.getJikokuhyouFont( 0 ) ;
		aCdFontProp = createVFontPropFromHFont( aCdFontProp ) ;
		aCdDedDispProp.setJikokuhyouVFont( aCdFontProp ) ;
		aCDedRosenFileData.setCdDedDispProp( aCdDedDispProp ) ;
	}
	// --------------------------------
	//	CDedRosenFileを ルートノードに反映する
	// --------------------------------
	if ( iRv >= 0 )
	{
		//	ルートノードは一旦空にする。
		nodecontRoot.erase( 0 , INT_MAX ) ;

		CconvCDedRosenFileData	aConv ;

		int iResult = aConv.CDedRosenFileData_to_OuPropertiesText( 
			&aCDedRosenFileData ,
			&nodecontRoot ) ;
		if ( iResult < 0 )
		{
			iRv = -22 ;	//	CDedRosenFileData への変換に失敗しました。
		}
	}

	// --------------------------------
	//□FileTypeAppComment
	//	"ConvFileOudia101To102 Ver 0.01"
	// --------------------------------
	if ( iRv >= 0 )
	{
		nodecontRoot.setValue( 
			nameFileTypeAppComment , 
			valueFileTypeAppComment ) ;
	}

	
	// --------------------------------
	//	CConvNodeContainer を
	//	バイト列に変換
	// --------------------------------
	string strRightFormat ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		strRightFormat = aConv.encode( 
			&nodecontRoot ) ;
	}


	//strRightFormat = RightFile の内容
	vector<char> binRightFormat ;
	if ( iRv >= 0 )
	{
		strRightFormat = OuLib::strCrlfOf( strRightFormat ) ;
		binRightFormat = OuLib::vectorCharOf( strRightFormat ) ;
	}
	// --------------------------------
	if ( pRightFormat != NULL )
	{
		pRightFormat->size_reset( binRightFormat.size() ) ;
		if ( binRightFormat.size() > 0 )
		{
			pRightFormat->write( &binRightFormat[0] , 0 , binRightFormat.size() ) ;
		}
	}
	if ( pErrorInfoString != NULL )
	{
		pErrorInfoString->size_reset( strErrorInfoString.size() ) ;
		if ( strErrorInfoString.size() > 0 )
		{
			pErrorInfoString->write( strErrorInfoString.c_str() , 0 , strErrorInfoString.size() ) ;
		}
	}
	return iRv ;
}

int CConvFile_Oudia101To102::isLeftFormat( 
		const IfByteBuffer* pLeftFormat)  
{
	int iRv = 0 ;
	string strErrorInfoString ;

	string strLeftFormat ;
	if ( iRv >= 0 )
	{
		vector<char> binLeftFormat ;
		binLeftFormat.resize( pLeftFormat->size() ) ;
		if ( binLeftFormat.size() > 0 )
		{
			pLeftFormat->read( 
				&binLeftFormat[0] , 
				0 , 
				binLeftFormat.size() ) ;
		}
		strLeftFormat = OuLib::stringOf( binLeftFormat ) ;
		strLeftFormat = OuLib::strLfOf( strLeftFormat ) ;
	}
	//strLeftFormat = pLeftFormat を格納した文字列です。
	OuPropertiesText::CNodeContainer	nodecontRoot ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		int iResult = aConv.decode( 
			strLeftFormat , 
			&nodecontRoot ,
			&strErrorInfoString ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	ファイルが正しいフォーマットではありません。
		}
	}
	if ( iRv >= 0 )
	{
		string strValue = nodecontRoot.getValue(
			nameFileType ) ;
		if ( strValue != valueFileTypeLeftFormat )
		{
			iRv = -1 ;	//	FileType が正しくありません。
		}
	}
	return iRv ;
}

bool CConvFile_Oudia101To102::RightToLeftIsSupported()
{
	return false ;
}

int CConvFile_Oudia101To102::RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
}
int CConvFile_Oudia101To102::isRightFormat( 
		const IfByteBuffer* pRightFormat ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
};


} //namespace ConvFile_Oudia101To102
