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
//	$Id: CConvCsvDocument.cpp 285 2016-06-05 08:10:51Z okm $
// ****************************************************************
/** @file */
#include "CConvCsvDocument.h"

namespace OuLib{
namespace Str{
namespace CsvDocument{

using std::string ;


// ****************************************************************
//	CCsvDecoder
// ****************************************************************
/**
@brief
	CSVファイルの内容を解釈して CdCsvDocument オブジェクトを
	構成する際の状態機械です。

【使い方】

1.  インスタンスを生成してください。

2.  CSVファイルの内容を addChar() メソッドで解釈させてください。

3.  CSVファイルの内容をすべて addChar() に渡した後は、 addEof() を
呼び出してください。
　この状態で CdCsvDocument の構成が終了します。getCdCsvDocument() で
 構成したドキュメントを取得することができます。

4.  新しいCSVファイルを解釈させる場合は、
　新しいインスタンスを生成しなくてはなりません。
*/
class CCsvDecoder
{
public:
	// ********************************
	///@name インナータイプ
	// ********************************
	///@{
	enum EState
	{
		/**
			引用符の外側
		*/
		EState_OuterQuote ,
		/**
			引用符の内側
		*/
		EState_InnerQuote ,
		/**
			引用符の内側の、1個目の引用符の直後
		*/
		EState_QuoteInnerQuote ,
	};
	///@}
private:
	// ********************************
	///@name 状態 
	// ********************************
	///@{
	/**
		現在の状態
	*/
	EState m_EState ;
	/**
		現在構成中のドキュメント
	*/
	CdCsvDocument	m_CdCsvDocument ;
	/**
		現在構成中の行
	*/
	CdCsvRow	m_CdCsvRow ;
	/**
		現在構成中のセルの文字列
	*/
	std::string	m_strCellData ;
	///@}
private:
	// --------------------------------
	///@name addChar() の下請関数
	// --------------------------------
	///@{
	void addChar_EState_OuterQuote( char ch ) ;
	void addChar_EState_InnerQuote( char ch ) ;
	void addChar_EState_QuoteInnerQuote( char ch ) ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CCsvDecoder()
		: m_EState( EState_OuterQuote ) 
	{
	};
	// ********************************
	///@name 状態 
	// ********************************
	///@{
	CdCsvDocument	getCdCsvDocument()
	{	return m_CdCsvDocument ;};
	///@}
	// ********************************
	///@name 操作
	// ********************************
	///@{
	/**
		CSVファイルの内容を解釈させます。
	@param ch [in]
		ファイルの内容のキャラクタを指定してください。
	*/
	void addChar( char ch ) ;
	/**
		CSVファイルの解釈を終了させます。
	@return
		-	0 ;	//	成功
		-	-1 ;	//	引用符が閉じていません
	//	
	*/
	int addEof() ;
	///@}
};
void CCsvDecoder::addChar_EState_OuterQuote( char ch ) 
{
			if ( ch == '\n' )
			{
				if ( m_strCellData.size() > 0 
						|| m_CdCsvRow.getCellCont()->size() )
				{
					m_CdCsvRow.getCellCont()->insert( CdCsvCell( m_strCellData ) , INT_MAX ) ;
					m_strCellData.erase() ;
				}
				{
					m_CdCsvDocument.getRowCont()->insert( m_CdCsvRow ) ;
					m_CdCsvRow.getCellCont()->erase( 0 , INT_MAX ) ;

				}

			}
			else if ( ch == ',' )
			{
				{
					m_CdCsvRow.getCellCont()->insert( CdCsvCell( m_strCellData ) , INT_MAX ) ;
					m_strCellData.erase() ;
				}
			}
			else if ( ch == '\"' )
			{
				m_EState = EState_InnerQuote ;
			}
			else
			{
				m_strCellData += ch ;
			}
}
void CCsvDecoder::addChar_EState_InnerQuote( char ch ) 
{
			if ( ch == '\n' )
			{
				m_strCellData += ch ;
			}
			else if ( ch == ',' )
			{
				m_strCellData += ch ;
			}
			else if ( ch == '\"' )
			{
				m_EState = EState_QuoteInnerQuote ;
			}
			else
			{
				m_strCellData += ch ;
			}
}
void CCsvDecoder::addChar_EState_QuoteInnerQuote( char ch ) 
{
			if ( ch == '\n' )
			{
				m_EState = EState_OuterQuote ;
				addChar_EState_OuterQuote( ch ) ; 
			}
			else if ( ch == ',' )
			{
				m_EState = EState_OuterQuote ;
				addChar_EState_OuterQuote( ch ) ; 
			}
			else if ( ch == '\"' )
			{
				m_strCellData += ch ;
				m_EState = EState_InnerQuote ;
			}
			else
			{
				m_EState = EState_OuterQuote ;
				addChar_EState_OuterQuote( ch ) ; 
			}
}

void CCsvDecoder::addChar( char ch ) 
{
	switch( m_EState )
	{
	case EState_OuterQuote :
		//	引用符の外側
		{
			addChar_EState_OuterQuote( ch ) ;
		}
		break ;
	case EState_InnerQuote :
		//	引用符の内側
		{
			addChar_EState_InnerQuote( ch ) ;
		}
		break ;
	case EState_QuoteInnerQuote :
		//	引用符の内側の、1個目の引用符の直後
		{
			addChar_EState_QuoteInnerQuote( ch ) ;
		}
		break ;
	}
}
int CCsvDecoder::addEof() 
{
	int iRv = 0 ;
	switch( m_EState )
	{
	case EState_OuterQuote :
	case EState_QuoteInnerQuote :
		//	引用符の内側の、1個目の引用符の直後
		{
			if ( m_strCellData.size() > 0 
						|| m_CdCsvRow.getCellCont()->size() )
			{
				m_CdCsvRow.getCellCont()->insert( CdCsvCell( m_strCellData ) , INT_MAX ) ;
				m_strCellData.erase() ;
			}
			if ( m_CdCsvRow.getCellCont()->size() > 0 
					|| m_CdCsvRow.getCellCont()->size() > 0 )
			{
				m_CdCsvDocument.getRowCont()->insert( m_CdCsvRow ) ;
				m_CdCsvRow.getCellCont()->erase( 0 , INT_MAX ) ;

			}
		}
		break ;
	case EState_InnerQuote :
		//	引用符の内側
		{
			iRv = -1 ;	//	引用符が閉じていません
		}
		break ;
	}

	return iRv ;
}

// ****************************************************************
	// --------------------------------
	//@name 下請関数
	// --------------------------------
std::string CConvCsvDocument::encodeCell( const CdCsvCell& aCdCsvCell ) 
{
	string strCell = aCdCsvCell.getData() ;
	string strRv ;

	bool bMustQuote = false ;
	for ( int idx = 0 ; idx < (int)strCell.size() ; idx ++ )
	{
		if ( strCell[idx] == '\n' )
		{
			bMustQuote = true ;
			strRv += strCell[idx] ;
		}
		else if ( strCell[idx] == '\"' )
		{
			bMustQuote = true ;
			strRv += "\"\"" ;
		}
		else
		{
			strRv += strCell[idx] ;
		}
	}
	if ( bMustQuote )
	{
		strRv = string( "\"" ) + strRv + "\"" ;
	}

	return strRv ;
}
	// ********************************
	//	コンストラクタ
	// ********************************
CConvCsvDocument::CConvCsvDocument(void)
{
}

CConvCsvDocument::~CConvCsvDocument(void)
{
}
	// ********************************
	//@name	CConvCsvDocument
	// ********************************
string CConvCsvDocument::encode( const CdCsvDocument* pCdCsvDocument ) 
{
	string strRv ;

	const Mu< const CdCsvRow& >* pRowCont = pCdCsvDocument->getRowCont() ;
	for ( int idxRow = 0 ; 
			idxRow < pRowCont->size() ;
			idxRow ++ )
	{
		CdCsvRow	aCdCsvRow = pRowCont->get( idxRow ) ;


		string strRow ;
		const Mu< CdCsvCell >* pCellCont = aCdCsvRow.getCellCont() ;
		for ( int idxCell = 0 ; idxCell < pCellCont->size() ; idxCell ++ )
		{
			if ( idxCell > 0 )
			{
				strRow += ',' ;
			}

			string strCell ;
			CdCsvCell	aCdCsvCell = pCellCont->get( idxCell ) ;
			strCell = encodeCell( aCdCsvCell ) ;

			strRow += strCell ;
		}

		strRv += strRow ;
		strRv += '\n' ;
	}
	return strRv ;
}
int CConvCsvDocument::decode( CdCsvDocument* pCdCsvDocument 
		, const string& strCsvText ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 )
	{
		CCsvDecoder	aCCsvDecoder ;
		for ( int idxChar = 0 ; idxChar < (int)strCsvText.size() ; idxChar ++ )
		{
			aCCsvDecoder.addChar( strCsvText[idxChar] ) ;
		}
		int iResult = aCCsvDecoder.addEof() ;
		//-	-1 ;	//	引用符が閉じていません
		if ( iResult < 0 )
		{
			iRv = iResult ;
		}
		else
		{
			*pCdCsvDocument = aCCsvDecoder.getCdCsvDocument() ;
		}
	}
	return iRv ;
}


} //namespace CsvDocument{
} //namespace Str{
} //namespace OuLib{

