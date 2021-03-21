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
// $Id: CConvFile_Oudia06To101.cpp 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
#include "stdafx.h"
#include <vector>
#include <string>
using namespace std ;

#include "CConvFile_Oudia06To101.h"
#include "Str\OuPropertiesText\CConvNodeContainer.h"
#include "Str\OuPropertiesText\CDirectory.h"
#include "Str\strLf.h"
#include "Str\strToInt.h"
#include "Str\strToVector.h"
#include "Str\vectorToFile.h"
#include "ou\dynamic_castOu.h"
#include "ou\OuNew.h"

static const char nameFileType[] = "FileType" ;
static const char valueFileTypeLeftFormat[] = "OuDia.6" ;
static const char valueFileTypeRightFormat[] = "OuDia.1.01" ;
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia06To101 Ver 0.01" ;

// ****************************************************************
//	CConvFile_Oudia06To101
// ****************************************************************
CConvFile_Oudia06To101::CConvFile_Oudia06To101()
{
}
CConvFile_Oudia06To101::~CConvFile_Oudia06To101()
{
}
	// ********************************
	//@name IfConvFile
	// ********************************

const char nameRosen[] = "Rosen" ;
const char nameRessyasyubetsu[] = "Ressyasyubetsu" ;
const char nameJikokuhyouFontIndex[] = "JikokuhyouFontIndex" ;
const char nameDispProp[] = "DispProp" ;
const char nameJikokuhyouFont[] = "JikokuhyouFont" ;




int CConvFile_Oudia06To101::LeftToRight( 
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
	//	＜4.0＞[FileType]
	//
	//  "OuDia.6"→"OuDia.1.01" に変換します。
	// --------------------------------
	if ( iRv >= 0 )
	{
		nodecontainerLeftFormat.setValue( 
			nameFileType , 
			valueFileTypeRightFormat ) ;
	}
	/* --------------------------------
	＜4.1＞[Rosen.Ressyasyubetsu[]]

	＜4.1.1＞[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]

	◇[Rosen.Ressyasyubetsu]に、[Rosen.Ressyasyubetsu.JikokuhyouFont]がない場合。
	   □[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 とします。

	◇[Rosen.Ressyasyubetsu]に、[Rosen.Ressyasyubetsu.JikokuhyouFont]がある場合。
	  ◇[DispProp.JikokuhyouFont[]]に同じフォントがある場合。
		□[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
			DispProp.JikokuhyouFont[]の、同一フォントのインデクス
		.
	  ◇[DispProp.JikokuhyouFont[]]に同じフォントがない場合。
		◇[DispProp.JikokuhyouFont[]]の要素数が8以内の場合。
　		  □[DispProp.JikokuhyouFont[]]の末尾に要素を追加し、
　　		[Rosen.Ressyasyubetsu.JikokuhyouFont]の内容をコピー
　		  □[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
　　		今回追加したDispProp.JikokuhyouFont[] のインデクス
		◇else
　		  □[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 とします。

	＜4.1.2＞[Rosen.Ressyasyubetsu.JikokuhyouFont]
	  仕様からは廃止されますが、コンバータはこの値を編集しません。
	 -------------------------------- */
	if ( iRv >= 0 )
	{
		int idxRessyasyubetsu = 0 ; 
		
		Ou<OuPropertiesText::CDirectory> pdirRosen = 
			dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameRosen , 0 ) ) ; 
		//pdirRosen = [Rosen] 

		Ou<OuPropertiesText::CDirectory> pdirDispProp = 
			dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameDispProp , 0 ) ) ; 
		//pdirDispProp = [DispProp] 
		if ( pdirRosen != NULL && pdirDispProp != NULL )
		{
			int cRessyasyubetsu = pdirRosen->getCNodeContainer()->sizeInName( nameRessyasyubetsu ) ;
			//cRessyasyubetsu = [Rosen.Ressyasyubetsu] の数 

			for ( idxRessyasyubetsu = 0 ; 
				iRv >= 0 && idxRessyasyubetsu < cRessyasyubetsu ; 
				idxRessyasyubetsu ++ )
			{
				Ou<OuPropertiesText::CDirectory> pdirRessyasyubetsu = 
					dynamic_castOu<OuPropertiesText::CDirectory>( 
					pdirRosen->getCNodeContainer()->getInName( nameRessyasyubetsu , idxRessyasyubetsu ) ) ; 
				if ( pdirRessyasyubetsu != NULL )
				{
					//pdirRessyasyubetsu = [Rosen.Ressyasyubetsu[]] 
					int iJikokuhyouFontIndex = 0 ;
					string strJikokuhyouFont = pdirRessyasyubetsu->getCNodeContainer()->getValue( nameJikokuhyouFont ) ;

					//◇[Rosen.Ressyasyubetsu]に、[Rosen.Ressyasyubetsu.JikokuhyouFont]がない場合。
					//   □[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 とします。
					if ( strJikokuhyouFont.length() == 0 )
					{
						iJikokuhyouFontIndex = 0 ;
					}
					//◇[Rosen.Ressyasyubetsu]に、[Rosen.Ressyasyubetsu.JikokuhyouFont]がある場合。
					else
					{
						int cJikokuhyouFont = pdirDispProp->getCNodeContainer()->sizeInName( nameJikokuhyouFont ) ;
						int idxJikokuhyouFont = 0 ; 
						for ( idxJikokuhyouFont = 0 ; 
							idxJikokuhyouFont < cJikokuhyouFont ; 
							idxJikokuhyouFont ++ )
						{
							string strJikokuhyouFontInJikokuhyou ;
							
							Ou<OuPropertiesText::CPropertyString> pnodeJikokuhyouFont = 
								dynamic_castOu<OuPropertiesText::CPropertyString>( 
								pdirDispProp->getCNodeContainer()->getInName( nameJikokuhyouFont , idxJikokuhyouFont ) ) ;
							if ( pnodeJikokuhyouFont != NULL )
							{
								strJikokuhyouFontInJikokuhyou = pnodeJikokuhyouFont->getValue() ;
							}
							if ( strJikokuhyouFont == strJikokuhyouFontInJikokuhyou )
							{
								break ;
							}
						}
						//  ◇[DispProp.JikokuhyouFont[]]に同じフォントがある場合。
						//	  □[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
						//		DispProp.JikokuhyouFont[]の、同一フォントのインデクス
						if ( idxJikokuhyouFont < cJikokuhyouFont )
						{
							iJikokuhyouFontIndex = idxJikokuhyouFont ;
						}
						//  ◇[DispProp.JikokuhyouFont[]]に同じフォントがない場合。
						else
						{
							//    ◇[DispProp.JikokuhyouFont[]]の要素数が8以内の場合。
							//      □[DispProp.JikokuhyouFont[]]の末尾に要素を追加し、
							//	      [Rosen.Ressyasyubetsu.JikokuhyouFont]の内容をコピー
							//      □[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
							//	      今回追加したDispProp.JikokuhyouFont[] のインデクス
							if ( cJikokuhyouFont < 8 )
							{
								pdirDispProp->getCNodeContainer()->insertInName(
									OuNew<OuPropertiesText::CPropertyString>( new
										OuPropertiesText::CPropertyString( 
										nameJikokuhyouFont , strJikokuhyouFont ) ) ) ;
								iJikokuhyouFontIndex = cJikokuhyouFont ;
							}
							//    ◇else
							//      □[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 とします。
							else
							{
								iJikokuhyouFontIndex = 0 ;
							}
						}
					}


					// --------------------------------
					pdirRessyasyubetsu->getCNodeContainer()->setValue( 
						nameJikokuhyouFontIndex , 
						OuLib::stringOf( iJikokuhyouFontIndex ) ) ;
				}
			}
		}
	}


	/* --------------------------------
	＜4.2＞[DispProp.JikokuhyouFont[]]

	  変換は、[Rosen.Ressyasyubetsu.JikokuhyouFontIndex[]]の変換と同時に行います。
	 -------------------------------- */

/*	// --------------------------------
	//(1)[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]
	//  [Rosen.Ressyasyubetsu.JikokuhyouFontIndex]を新設しました。
	//  この値は、0～7で、この列車種別の時刻表示で使用するフォントを指定します。
	//  この値は、[DispProp.JikokuhyouFont]のインデクスを指定します。
	//  【変換内容】この値は、0を割り当てます。
	// --------------------------------
	if ( iRv >= 0 )
	{
		int idxRessyasyubetsu = 0 ; 
		
		Ou<OuPropertiesText::CDirectory> pdirRosen = 
			dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameRosen , 0 ) ) ; 
		//pdirRosen = [Rosen] 
		if ( pdirRosen != NULL )
		{
			int cRessyasyubetsu = pdirRosen->getCNodeContainer()->sizeInName( nameRessyasyubetsu ) ;
			//cRessyasyubetsu = [Rosen.Ressyasyubetsu] の数 

			for ( idxRessyasyubetsu = 0 ; 
				iRv >= 0 && idxRessyasyubetsu < cRessyasyubetsu ; 
				idxRessyasyubetsu ++ )
			{
				Ou<OuPropertiesText::CDirectory> pdirRessyasyubetsu = 
					dynamic_castOu<OuPropertiesText::CDirectory>( 
					nodecontainerLeftFormat.getInName( nameRessyasyubetsu , idxRessyasyubetsu ) ) ; 
				//pdirRessyasyubetsu = [Rosen.Ressyasyubetsu[]] 

				if ( pdirRessyasyubetsu != NULL )
				{
					pdirRessyasyubetsu->getCNodeContainer()->setValue( 
						nameJikokuhyouFontIndex , "0" ) ;
				}
			}
		}
	}
	// --------------------------------
	//(2)[DispProp.JikokuhyouFont]
	//　この値は8つのエントリを持ちます。
	//
	//  【変換内容】この値は、従来の[DispProp.JikokuhyouFont](1つ)を、8つに複製します。
	// --------------------------------
	if ( iRv >= 0 )
	{
		Ou<OuPropertiesText::CDirectory> pdirDispProp = 
			dynamic_castOu<OuPropertiesText::CDirectory>( 
			nodecontainerLeftFormat.getInName( nameDispProp , 0 ) ) ;
		//pdirDispProp = [DispProp]

		string strValue = pdirDispProp->getCNodeContainer()->getValue( nameJikokuhyouFont ) ;
		//strValue = [DispProp.JikokuhyouFont]

		if ( !strValue.empty() )
		{
			while( pdirDispProp->getCNodeContainer()->sizeInName( nameJikokuhyouFont ) < 8 ) 
			{
				pdirDispProp->getCNodeContainer()->insertInName( 
					OuNew<OuPropertiesText::CPropertyString>( new OuPropertiesText::CPropertyString( 
					nameJikokuhyouFont , strValue ) )
				) ;
			}
		}
	}
*/
	// --------------------------------
	//FileTypeAppCommentを末尾に追加
	// --------------------------------
	if ( iRv >= 0 )
	{
		nodecontainerLeftFormat.setValue( 
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

int CConvFile_Oudia06To101::isLeftFormat( 
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

bool CConvFile_Oudia06To101::RightToLeftIsSupported() 
{
	return false ;
}

int CConvFile_Oudia06To101::RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
}

int CConvFile_Oudia06To101::isRightFormat( 
		const IfByteBuffer* pRightFormat ) 
{
	return -2 ;	//	このメソッドはサポートされていません。
};




