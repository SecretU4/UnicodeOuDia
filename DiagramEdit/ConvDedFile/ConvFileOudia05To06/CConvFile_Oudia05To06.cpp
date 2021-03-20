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
// $Id: CConvFile_Oudia05To06.cpp 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
#include "stdafx.h"
#include <vector>
#include <string>
using namespace std ;

#include "CConvFile_Oudia05To06.h"
#include "Str\OuPropertiesText\CConvNodeContainer.h"
#include "Str\OuPropertiesText\CDirectory.h"
#include "Str\strLf.h"
#include "Str\strToVector.h"
#include "Str\vectorToFile.h"
#include "ou\dynamic_castOu.h"
static const char nameFileType[] = "FileType" ;
static const char valueFileTypeLeftFormat[] = "OuDia.5" ;
static const char valueFileTypeRightFormat[] = "OuDia.6" ;
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia05To06 Ver 0.01" ;

// ****************************************************************
//	CConvFile_Oudia05To06
// ****************************************************************
CConvFile_Oudia05To06::CConvFile_Oudia05To06()
{
}
CConvFile_Oudia05To06::~CConvFile_Oudia05To06()
{
}
	// ********************************
	//@name IfConvFile
	// ********************************

/**

【変換内容】

　.oud ファイル の Oudia.5 では、 [DispProp\DiaRessyajouhouHyoujiEkiOrderKudari] に、
 駅Orderで、ダイヤグラムビューの列車情報表示が指定されていました。

   .oud ファイルの OuDia.6 では、 [Rosen.Eki(n).DiagramRessyajouhouHyoujiKudari] で、
その駅に列車情報を表示するか否かが指定されています。

  Eki(n) は、ディレクトリの名前ではなく、 0から始まるインデクス n の [Eki] ディレクトリ。

　変換内容は以下の通りです。
 
@code
int iEkiOrder = ( [DispProp\DiaRessyajouhouHyoujiEkiOrderKudari] に記された整数 ) ;
[Rosen.Eki(iEkiOrder).DiagramRessyajouhouHyoujiKudari]=1 
@endcode




*/
const char nameDispProp[] = "DispProp" ;
const char nameDiaRessyajouhouHyoujiEkiOrderKudari[]="DiaRessyajouhouHyoujiEkiOrderKudari" ;
const char nameDiaRessyajouhouHyoujiEkiOrderNobori[]="DiaRessyajouhouHyoujiEkiOrderNobori" ;

const char nameRosen[] = "Rosen" ;
const char nameEki[] = "Eki" ;
const char nameDiagramRessyajouhouHyoujiKudari[] = "DiagramRessyajouhouHyoujiKudari" ;
const char nameDiagramRessyajouhouHyoujiNobori[] = "DiagramRessyajouhouHyoujiNobori" ;
const char nameDiagramRessyajouhouHyouji_Not[] = "DiagramRessyajouhouHyouji_Not" ;


int CConvFile_Oudia05To06::LeftToRight( 
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

	OuPropertiesText::CNodeContainer	nodecontainerLeftFormat ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		int iResult = aConv.decode( 
			strLeftFormat , 
			&nodecontainerLeftFormat ,
			&strErrorInfoString ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	ファイルが正しいフォーマットではありません。
		}
	}
	//nodecontainerLeftFormat = LeftFileの内容を保持しています。


	// --------------------------------
	//	下り列車の処理
	// --------------------------------
	//int iEkiOrder = ( [DispProp.DiaRessyajouhouHyoujiEkiOrderKudari] に記された整数 ) ;
	//
	//	[Rosen.Eki[0].DiagramRessyajouhouHyoujiKudari]〜
	//	[Rosen.Eki[iEkiOrder-1].DiagramRessyajouhouHyoujiKudari]
	//	に、DiagramRessyajouhouHyouji_Not を設定
	if ( iRv >= 0 )
	{
		int iEkiOrder = -1 ;
		if ( iRv >= 0 )
		{
			Ou<OuPropertiesText::CDirectory> pCDirectory ;
			pCDirectory = dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameDispProp , 0 ) ) ; 
			//pCDirectory = [DispProp] 
			if ( pCDirectory != NULL )
			{
				string strValue = pCDirectory->getCNodeContainer()->getValue( 
					nameDiaRessyajouhouHyoujiEkiOrderKudari ) ;
				//strValue = [DispProp\DiaRessyajouhouHyoujiEkiOrderKudari]
				if ( !strValue.empty() )
				{
					iEkiOrder = atoi( strValue.c_str() ) ;

					//[DispProp\DiaRessyajouhouHyoujiEkiOrderKudari] は削除
					pCDirectory->getCNodeContainer()->eraseInName( 
						nameDiaRessyajouhouHyoujiEkiOrderKudari , 0 , INT_MAX ) ;
				}
				else
				{
					iRv = -12 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari が見つかりません。
				}
			}
		}
		//iEkiOrder = ダイヤグラム上での列車情報表示位置

		//	[Rosen.Eki[0].DiagramRessyajouhouHyoujiKudari]〜
		//	[Rosen.Eki[iEkiOrder-1].DiagramRessyajouhouHyoujiKudari]
		//	に、DiagramRessyajouhouHyouji_Not を設定
		if ( iRv >= 0 )
		{
			Ou<OuPropertiesText::CDirectory> pCDirectory ;
			pCDirectory = dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameRosen , 0 ) ) ; 
			//pCDirectory = [Rosen]
			if ( pCDirectory != NULL )
			{
				for ( int idxEkiOrder = 0 ; idxEkiOrder < iEkiOrder ; idxEkiOrder ++ )
				{
					Ou<OuPropertiesText::CDirectory> pCDirectoryEki = 
						dynamic_castOu<OuPropertiesText::CDirectory>( 
							pCDirectory->getCNodeContainer()->getInName( nameEki , idxEkiOrder ) ) ; 
					//pCDirectory = [Rosen.Eki[idxEkiOrder]]
					if ( pCDirectoryEki != NULL )
					{
						pCDirectoryEki->getCNodeContainer()->setValue( 
							nameDiagramRessyajouhouHyoujiKudari , 
							nameDiagramRessyajouhouHyouji_Not ) ;
					}
					//[Rosen.Eki[idxEkiOrder].nameDiagramRessyajouhouHyoujiKudari] 
					//	に "DiagramRessyajouhouHyouji_Not" を設定しました。
				}
			}
		}
	}

	// --------------------------------

	// --------------------------------
	//	上り列車の処理
	// --------------------------------
	//int iEkiOrder = ( [DispProp.DiaRessyajouhouHyoujiEkiOrderNobori] に記された整数 ) ;
	//
	//[Rosen.Eki[Rosen.Eki の数 - 1].DiagramRessyajouhouHyoujiNobori]
	//[Rosen.Eki[Rosen.Eki の数 - iEkiOrder ].DiagramRessyajouhouHyoujiNobori]
	//	に、DiagramRessyajouhouHyouji_Not を設定
	if ( iRv >= 0 )
	{
		int iEkiOrder = -1 ;
		if ( iRv >= 0 )
		{
			Ou<OuPropertiesText::CDirectory> pCDirectory ;
			pCDirectory = dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameDispProp , 0 ) ) ; 
			//pCDirectory = [DispProp] 
			if ( pCDirectory != NULL )
			{
				string strValue = pCDirectory->getCNodeContainer()->getValue( 
					nameDiaRessyajouhouHyoujiEkiOrderNobori ) ;
				//strValue = [DispProp\DiaRessyajouhouHyoujiEkiOrderNobori]
				if ( !strValue.empty() )
				{
					iEkiOrder = atoi( strValue.c_str() ) ;

					//[DispProp\DiaRessyajouhouHyoujiEkiOrderNobori] は削除
					pCDirectory->getCNodeContainer()->eraseInName( 
						nameDiaRessyajouhouHyoujiEkiOrderNobori  , 0 , INT_MAX ) ;
				}
				else
				{
					iRv = -22 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori が見つかりません。
				}
			}
		}
		//iEkiOrider = ダイヤグラム上での列車情報表示位置
		//	[DispProp.DiaRessyajouhouHyoujiEkiOrderNobori] に記されていた整数
		if ( iRv >= 0 )
		{
			int iEkiIndex = -1 ;
			Ou<OuPropertiesText::CDirectory> pCDirectory ;
			pCDirectory = dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameRosen , 0 ) ) ; 
			//pCDirectory = [Rosen]
			if ( pCDirectory != NULL )
			{
				int iEkiIndex = pCDirectory->getCNodeContainer()->sizeInName( nameEki ) ;
				for ( int idxEkiOrder = 0 ; idxEkiOrder < iEkiOrder ; idxEkiOrder ++ )
				{
					iEkiIndex -- ;

					Ou<OuPropertiesText::CDirectory> pCDirectoryEki = 
						dynamic_castOu<OuPropertiesText::CDirectory>( 
							pCDirectory->getCNodeContainer()->getInName( nameEki , iEkiIndex ) ) ; 
					//pCDirectory = [Rosen.Eki[iEkiIndex]]
					if ( pCDirectoryEki != NULL )
					{
						pCDirectoryEki->getCNodeContainer()->setValue( 
							nameDiagramRessyajouhouHyoujiNobori , 
							nameDiagramRessyajouhouHyouji_Not ) ;
					}
					//[Rosen.Eki[iEkiIndex].nameDiagramRessyajouhouHyoujiNobori] 
					//	に "DiagramRessyajouhouHyouji_Not" を設定しました。
				}

			}
		}
	}

	// --------------------------------

	//FileTypeを変更
	if ( iRv >= 0 )
	{
		nodecontainerLeftFormat.setValue( 
			nameFileType , 
			valueFileTypeRightFormat ) ;
	}
	//FileTypeAppCommentを末尾に追加
	if ( iRv >= 0 )
	{
		nodecontainerLeftFormat.setValue( 
			nameFileTypeAppComment , 
			valueFileTypeAppComment ) ;
	}

	
	// --------------------------------
	string strRightFormat ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		strRightFormat = aConv.encode( 
			&nodecontainerLeftFormat ) ;
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

int CConvFile_Oudia05To06::isLeftFormat( 
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
	OuPropertiesText::CNodeContainer	nodecontainerLeftFormat ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		int iResult = aConv.decode( 
			strLeftFormat , 
			&nodecontainerLeftFormat ,
			&strErrorInfoString ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	ファイルが正しいフォーマットではありません。
		}
	}
	if ( iRv >= 0 )
	{
		string strValue = nodecontainerLeftFormat.getValue(
			nameFileType ) ;
		if ( strValue != valueFileTypeLeftFormat )
		{
			iRv = -1 ;	//	FileType が正しくありません。
		}
	}
	return iRv ;
}

bool CConvFile_Oudia05To06::RightToLeftIsSupported() 
{
	return false ;
}

int CConvFile_Oudia05To06::RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
}

int CConvFile_Oudia05To06::isRightFormat( 
		const IfByteBuffer* pRightFormat ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
};




