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
// $Id: CConvFile_Oudia03To05.cpp 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
#include "stdafx.h"
#include <vector>
#include <string>
using namespace std ;
#include "CConvFile_Oudia03To05.h"
#include "Str\strToVector.h"
#include "Str\strLf.h"
#include "Str\strprintf.h"
#include "03\CconvCDedRosenFileData_03.h"
#include "CDedRosenFileData.h"
#include "CconvCDedRosenFileData.h"

static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia03To05 Ver 0.01" ;

// ****************************************************************
//	CConvFile_Oudia03To05
// ****************************************************************
CConvFile_Oudia03To05::CConvFile_Oudia03To05()
{
}
CConvFile_Oudia03To05::~CConvFile_Oudia03To05()
{
}
	// ********************************
	//@name IfConvFile
	// ********************************
int CConvFile_Oudia03To05::LeftToRight( 
		const IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pRightFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	int iRv = 0 ;
	string strErrorInfoString ;
	if ( iRv >= 0 )
	{
		int iResult = isLeftFormat( pLeftFormat ) ;
		//	-	-1 ;	//	FileType が正しくありません。
		//	-	-101 ;	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。	
		if ( iResult < 0 )
		{
			switch( iResult )
			{
			case -1 :	//	FileType が正しくありません。
				strErrorInfoString = "FileType Mismatch." ;
				break ;
			case -101 :	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。	
				strErrorInfoString = "Invalid Subitem Data." ;
				break ;
			}
			iRv = iResult ;
		}
	}
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

	CDedRosenFileData aCDedRosenFileData ;
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData_03	aConv ;
		int iResult = aConv.CDedRosenFileData_from_string(
			&aCDedRosenFileData , 
			strLeftFormat ) ;
		//	-	-1 ;	//	FileType が正しくありません。
		//	-	-11 ;	//	Rosen の内容が不正
		//	-	-21 ;	//	DispProp の内容が不正
		//	-	-101 ;	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。	
		if ( iResult < 0 )
		{
			switch( iResult )
			{
			case -1 :	//	FileType が正しくありません。
				strErrorInfoString = "FileType Mismatch." ;
				break ;
			case -11 :	//	Rosen の内容が不正
				strErrorInfoString = "Invalid Rosen Data." ;
				break ;
			case -21 :	//	DispProp の内容が不正
				strErrorInfoString = "Invalid DispProp Data." ;
				break ;
			case -101 :	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。	
				strErrorInfoString = "Invalid Subitem Data." ;
				break ;
			}
			iRv = iResult ;
		}

	}
	//aCDedRosenFileData = 路線ファイルを読み込むことができました。

	//aCDedRosenFileData　に集約されている列車種別には、
	//	種別名 CentDedRessyasyubetsu::m_strSyubetsumei が
	//	空文字列のものが混ざっている可能性があります
	//	(CconvCDedRosenFileData_03 のバグ)。
	//	しかし、これは CconvCDedRosenFileData(Ver.5)では
	//	エラーになってしまいます・
	//	このため、aCDedRosenFileData の
	//	列車種別名が空文字列のものがあれば、
	//	仮の列車種別名を設定します。
	if ( iRv >= 0 )
	{
		CentDedRosen* pCentDedRosen = aCDedRosenFileData.getCentDedRosen() ;
		CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont = 
			pCentDedRosen->getCentDedRessyasyubetsuCont() ;
		for ( int idxRessyasyubetsu = 0 ; 
			idxRessyasyubetsu < pCentDedRessyasyubetsuCont->size() ;
			idxRessyasyubetsu ++ )
		{
			CentDedRessyasyubetsu aCentDedRessyasyubetsu = 
				pCentDedRessyasyubetsuCont->get( idxRessyasyubetsu ) ;
			if ( aCentDedRessyasyubetsu.getSyubetsumei().empty() )
			{
				aCentDedRessyasyubetsu.setSyubetsumei( 
					OuLib::strprintf( "%d" , idxRessyasyubetsu + 1 ) ) ;
				pCentDedRessyasyubetsuCont->set( 
					aCentDedRessyasyubetsu , 
					idxRessyasyubetsu ) ;
			}
		}
	}


	string strRightFormat ;
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData	aConv ;
		int iResult = aConv.CDedRosenFileData_to_string( 
			aCDedRosenFileData ,
			&strRightFormat ) ;
		//	-	-11 ;	//	Ekimei が指定されていません。
		//	-	-22 ;	//	Ekijikokukeisiki の値が不正です。
		//	-	-32 ;	//	Ekikibo の値が不正です。
		//	-	-111 ;	//	Syubetsumei が指定されていません。
		//	-	-152 ;	//	DiagramSenStyle の値が不正です。
		//	-	-212 ;	//	DiagramEkiatsukai の値が不正です。
		if ( iResult < 0 )
		{
			switch( iResult )
			{
			case -11 :	//	Ekimei が指定されていません。
				strErrorInfoString = "Ekimei is not valid." ;
				break ;
			case -22 :	//	Ekijikokukeisiki の値が不正です。
				strErrorInfoString = "Ekijikokukeisiki is not valid." ;
				break ;
			case -32 :	//	Ekikibo の値が不正です。
				strErrorInfoString = "Ekikibo is not valid." ;
				break ;
			case -111 :	//	Syubetsumei が指定されていません。
				strErrorInfoString = "Syubetsumei is not valid." ;
				break ;
			case -152 :	//	DiagramSenStyle の値が不正です。
				strErrorInfoString = "DiagramSenStyle is not valid." ;
				break ;
			case -212 :	//	DiagramEkiatsukai の値が不正です。
				strErrorInfoString = "DiagramEkiatsukai is not valid." ;
				break ;
			}
			//	-	-211 ;	//	Ekimei が指定されていません。
			//	-	-222 ;	//	Ekijikokukeisiki の値が不正です。
			//	-	-232 ;	//	Ekikibo の値が不正です。
			//	-	-311 ;	//	Syubetsumei が指定されていません。
			//	-	-352 ;	//	DiagramSenStyle の値が不正です。
			//	-	-412 ;	//	DiagramEkiatsukai の値が不正です。
			iRv = iResult - 200 ;
		}
	}

	//FileTypeAppCommentを末尾に追加
	if ( iRv >= 0 )
	{
		strRightFormat += "\n" ;
		strRightFormat += OuLib::strprintf( "%s=%s" , 
			nameFileTypeAppComment , 
			valueFileTypeAppComment ) ;
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

int CConvFile_Oudia03To05::isLeftFormat( 
		const IfByteBuffer* pLeftFormat) 
{
	int iRv = 0 ;
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
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData_03	aConv ;
		int iResult = aConv.isEncodeAbleFormat( 
			strLeftFormat ) ;
		//	-	0 ;	//	解釈可能です。
		//	-	-1 ;	//	FileType が正しくありません。
		//	-	-101 ;	//	カレントサブアイテム入場コマンドと退場コマンドが対応しません。	
		if ( iResult < 0 )
		{
			iRv = iResult ;
		}
	}
	return iRv ;
}

bool CConvFile_Oudia03To05::RightToLeftIsSupported() 
{
	return false ;
}

int CConvFile_Oudia03To05::RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
}

int CConvFile_Oudia03To05::isRightFormat( 
		const IfByteBuffer* pRightFormat ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
};




