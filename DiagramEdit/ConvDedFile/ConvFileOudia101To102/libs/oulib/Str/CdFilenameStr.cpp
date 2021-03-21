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
//	CdFilenameStr.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "Str\CdFilenameStr.h"
#include "Str\CStrCharSizeMb.h"

// ****************************************************************
//	CdFilenameStr
// ****************************************************************

// ********************************
//	コンストラクタ・デストラクタ
// ********************************
CdFilenameStr::CdFilenameStr() 
	: m_bIsRelativePath( false ) 
	, m_bIsValidFilename( true ) 
{
}
	//[in]strFilename
	//	フルパス名（ドライブ・ディレクトリ・ファイル名が混合した文字列）
	//	を指定してください。
	//[in]bIsValidFilename
	//	このパスが、ファイル名のある形式であるなら真です。
	//	この場合は、一番右の '\' の右側はファイル名とみなされます。
	//	このパスが、ファイル名のない形式であれば偽です。
	//	この場合は、一番右の '\' の右側もディレクトリとみなします。
CdFilenameStr::
CdFilenameStr( std::string strFilename , bool bIsValidFilename ) 
{
	setFullpathFilename( strFilename, bIsValidFilename ) ;
}


// ********************************
//	CdFilenameStr
// ********************************
	// --------------------------------
	//	属性
	// --------------------------------

std::string	CdFilenameStr::Drive() const 
{
	return ( m_strDrive ) ;
}
CdFilenameStr& CdFilenameStr::setDrive( const std::string& ev ) 
{
	m_strDrive = ev ;
	return ( *this ) ;
}
	
CdFilenameStr::ContstrDir	CdFilenameStr::Dirs()const
{
	return ( m_contstrDir ) ;
}

CdFilenameStr& CdFilenameStr::setDirs( const CdFilenameStr::ContstrDir& ev ) 
{
	m_contstrDir = ev ;
	return ( *this ) ;
}
	
	
int CdFilenameStr::DirCount()const 
{
	return ( m_contstrDir.size() ) ;
}

std::string CdFilenameStr::DirAt( int idx )const 
{
	if ( 0 <= idx && idx < (int)m_contstrDir.size() ){
		return ( m_contstrDir.at( idx ) ) ;
	}
	return ( "" ) ;
}
	
CdFilenameStr& 	CdFilenameStr::addDirLast( const std::string& ev ) 
{
	m_contstrDir.push_back( ev ) ;
	return ( *this ) ;
}

CdFilenameStr& 	CdFilenameStr::addDirAt( int index , const std::string& ev ) 
{
	m_contstrDir.insert( m_contstrDir.begin() + index , ev ) ;
	return ( *this ) ;
}
	
CdFilenameStr& 	CdFilenameStr::delDirLast() 
{
	m_contstrDir.pop_back() ;
	return ( *this ) ;
}
CdFilenameStr& 	CdFilenameStr::delDirAt( int index ) 
{
	m_contstrDir.erase( m_contstrDir.begin() + index ) ;
	return ( *this ) ;
}
	
std::string CdFilenameStr::BaseFilename() const 
{
	return ( m_strBaseFilename ) ;
}

CdFilenameStr& CdFilenameStr::setBaseFilename( const std::string& ev ) 
{
	m_strBaseFilename = ev ;
	return ( *this ) ;
}
	
std::string CdFilenameStr::Extension() const 
{
	return ( m_strExtension ) ;
}

CdFilenameStr& CdFilenameStr::setExtension( const std::string& ev ) 
{
	m_strExtension = ev ;
	return ( *this ) ;
}
	
bool CdFilenameStr::IsRelativePath() const 
{
	return ( m_bIsRelativePath ) ;
}

CdFilenameStr& CdFilenameStr::setIsRelativePath( bool ev ) 
{
	m_bIsRelativePath = ev  ;
	return ( *this ) ;
}
	
bool CdFilenameStr::IsValidFilename() const 
{
	return ( m_bIsValidFilename ) ;
}

CdFilenameStr& CdFilenameStr::setIsValidFilename( bool ev ) 
{
	m_bIsValidFilename = ev  ;
	return ( *this ) ;
}
	
std::string CdFilenameStr::	Filename() const 
{
	std::string	strRv = m_strBaseFilename ;
	if ( !m_strExtension.empty() ){
		strRv += "." ;
		strRv += m_strExtension ;
	}
	return ( strRv ) ;
}
	
CdFilenameStr& CdFilenameStr::setFilename( std::string ev ) 
{
	CStrCharSizeMb	ite( ev ) ;
	int	iBidx ;
	for ( iBidx = ite.BidxLast() ; iBidx >  0 ; iBidx = ite.BidxNextChar( iBidx , -1 ) ) {
		if ( ite.CsizeOfBidx( iBidx ) == 1 ){
			if ( ev[iBidx] == '.' ) {
				break ;	//	iExtPeriod = 拡張子の前の'.'のインデクスです。
			}
			if ( ev[iBidx]  == '\\' || ev[iBidx]  == ':' ){
				iBidx = -1 ;
				break ;
					//iBidx = -1は拡張子がみつからなかったことを示します。
			}
		}
	}
	//iBidx = 拡張子の前の'.'のインデクスです。
	//	みつからなければ-1です
	if ( iBidx > 0 ){
		m_strBaseFilename = ev.substr( 0 , iBidx ) ; 
		m_strExtension    = ev.substr( iBidx + 1 ) ; 
	}	else	{
		m_strBaseFilename = ev ;
		m_strExtension.erase() ;
	}
	return ( *this ) ;
}
	
// --------------------------------
	
std::string CdFilenameStr::FullpathFilename() const 
{
	std::string	strRv ;

	//ドライブ
	if ( !m_strDrive.empty() ){
		strRv += m_strDrive ;
		strRv += ':' ;
	}

	if ( !m_bIsRelativePath ){
		strRv += '\\' ;
	}
	
	int idxDir ;
	for ( idxDir = 0 ; idxDir < (int)m_contstrDir.size() ; idxDir ++ ){
		std::string strDir = m_contstrDir[ idxDir ] ;
		strRv += strDir ;
		if ( idxDir < (int)m_contstrDir.size() - 1 || m_bIsValidFilename ){
			strRv += '\\' ;
		}
	}
	if ( m_bIsValidFilename ){
		strRv += Filename() ;
	}
	return ( strRv ) ;
}

CdFilenameStr& CdFilenameStr::setFullpathFilename( std::string ev ) 
{
	// --------------------------------
	//	すべて削除
	// --------------------------------
	m_strDrive.erase() ;
	m_contstrDir.clear() ;
	m_bIsRelativePath = true ;
	m_strBaseFilename.erase() ;
	m_strExtension.erase() ;
	// --------------------------------
	//	ドライブ名
	// --------------------------------
	{
		CStrCharSizeMb	ite( ev )  ;
		int	iBidx ;
		for ( iBidx = 0 ; iBidx < ite.ByteLength() ; iBidx = ite.BidxNextChar( iBidx ) ) {
			if ( ite.CsizeOfBidx( iBidx ) == 1 ){
				if ( ev[ iBidx ] == ':' ) {
					break ;	
					//iBidx = ドライブ名のあとの':'のインデクスです。
				}
				if (ev[ iBidx ] == '\\' || ev[ iBidx ] == '.' ){
					iBidx = ite.ByteLength() ;	
					//iBidx = ite.ByteLength()  は、
					//		ドライブ名がないことを示します。
				}
			}
		}
		if ( iBidx < ite.ByteLength()  ){
			m_strDrive = ev.substr( 0 , iBidx ) ; 
			ev = ev.substr( iBidx + 1 ) ; 
		}
	}	
	//ev = ドライブと次の':'を削除したものに
	//	なりました。

	// --------------------------------
	//	ファイル名	
	// --------------------------------
	if ( m_bIsValidFilename ){
		CStrCharSizeMb	ite( ev )  ;
		int	iBidx ;
		for ( iBidx = ite.BidxLast() ; iBidx >= 0 ; iBidx = ite.BidxNextChar( iBidx , -1 ) ){
			if ( ite.CsizeOfBidx( iBidx ) == 1 ){
				if ( ev[ iBidx ] == '\\' ){
					break ;	//	iBidx = ファイル名の直前の'\'か':'のインデクスです。
				}
			}
		}
		setFilename( ev.substr( iBidx + 1 ) ) ;
		ev = ev.substr( 0 , iBidx + 1 ) ; 
	}
	//ev = ファイル名を削除したものに
	//	なりました。

	// --------------------------------
	//	先頭と末尾の '\' を扱う
	// --------------------------------
	if ( ev.length() > 0 ){
		CStrCharSizeMb	ite( ev )  ;
		if ( ite.CsizeOfBidx( 0 ) == 1 && ev[0] == '\\' ){
			m_bIsRelativePath = false ;	
			//	ディレクトリの先頭が'\' なら、絶対パスです。
			ev = ev.substr( 1 ) ;
		}		
	}
	//ev=先頭の '\' を削除しました。

	if ( ev.length() > 0 ){
		CStrCharSizeMb	ite( ev )  ;
		if ( ite.CsizeOfBidx( ite.BidxLast() ) == 1 && ev[ite.BidxLast()] == '\\' ){
			ev = ev.substr( 0 , ite.BidxLast() ) ;
		}		
	}
	//ev=末尾の '\' を削除しました。

	// --------------------------------
	//	ディレクトリを、 '\' を境界で
	//	切り離します。
	// --------------------------------
	while( ev.length() > 0 ){
		CStrCharSizeMb	ite( ev )  ;
		int	iBidx ;
		for ( iBidx = 0 ; iBidx < ite.ByteLength() ; iBidx = ite.BidxNextChar( iBidx ) ){
			if ( ite.CsizeOfBidx( iBidx ) == 1 ){
				if ( ev[ iBidx ] == '\\' ) {
					break ;	
					//iBidx = ドライブ名のあとの'\'のインデクスです。
				}
			}
		}
		m_contstrDir.push_back( ev.substr( 0 , iBidx ) ) ; 
		ev = ev.substr( iBidx ) ; 
		ite.scan( ev ) ;
		if ( ite.ByteLength() > 0 ){
			if ( ite.CsizeOfBidx( 0 ) == 1 ){
				if ( ev[0] == '\\' ) {
					ev = ev.substr( 1 ) ;
				}
			}
		}
	}	

	return ( *this ) ;
}
CdFilenameStr& CdFilenameStr::setFullpathFilename( std::string ev , 
										bool bIsValidFilename ) 
{
	m_bIsValidFilename = bIsValidFilename ;
	return ( setFullpathFilename( ev ) ) ;
}
	
CdFilenameStr& CdFilenameStr::ChangeDir( const CdFilenameStr& ev ) 
{
	// --------------------------------
	//	ディレクトリ
	// --------------------------------
	if ( ev.IsRelativePath() ){
		//	相対パスの場合は、ディレクトリは相対移動となります。
		int idx ;
		for ( idx = 0 ; idx < ev.DirCount() ; idx ++ ){
			std::string strDir = ev.DirAt( idx ) ;
			if ( strDir == "." ){
			}	else if ( strDir == ".." ){
				if ( m_contstrDir.size() > 0 ){
					m_contstrDir.pop_back() ;
				}
			}	else	{
				m_contstrDir.push_back( strDir ) ;
			}			
		}
	}	else	{
		//	絶対パスの場合は、ディレクトリはおきかえになります。
		m_contstrDir.clear() ;
		int idx ;
		for ( idx = 0 ; idx < ev.DirCount() ; idx ++ ){
			m_contstrDir.push_back( ev.DirAt( idx ) ) ;
		}
	}
	// --------------------------------
	//	ドライブ
	// --------------------------------
	if ( ev.Drive().length() > 0 ){
		setDrive( ev.Drive() ) ;
	}
	// --------------------------------
	//	ファイル名
	// --------------------------------
	if ( ev.Filename().length() > 0 ){
		setFilename( ev.Filename() ) ;
	}
	return ( *this ) ;
}

int CdFilenameStr::ChangeToRelativeDir( const CdFilenameStr& ev ) 
{
	int	merrRv = 0 ;

	CdFilenameStr	aFilenameStrBase( ev ) ;
	// --------------------------------
	//	ドライブ
	// --------------------------------
	if ( merrRv >= 0 ){
		if ( Drive().length() > 0 && ev.Drive().length() > 0 
				&& Drive() != ev.Drive() ){
			//	双方別々のドライブが指定されている場合は、
			//	相対パスへの変換はできません。
			merrRv = -1 ;	//	 ドライブが異なるため、相対パスにはできません。
		}	else	{
			setDrive( "" ) ;
			aFilenameStrBase.setDrive( "" ) ;
		}
	}

	// --------------------------------
	//	ディレクトリ
	// --------------------------------
	if ( merrRv >= 0 ){
		if ( IsRelativePath() ){
			merrRv = -2 ;	//	 thisが相対パスです
		}	else if ( aFilenameStrBase.IsRelativePath() ){
			merrRv = -3 ;	//	 evが相対パスです
		} 
	}
	if ( merrRv >= 0 ){
		//thisを相対パスに変更します。
		setIsRelativePath( true ) ;
		aFilenameStrBase.setIsRelativePath( true ) ;
		
		while ( DirCount() > 0 
				&& aFilenameStrBase.DirCount() > 0 
				&& DirAt( 0 ) == aFilenameStrBase.DirAt( 0 ) 
				&& DirAt( 0 ) != "." 
				&& DirAt( 0 ) != ".." ){
			delDirAt( 0 ) ;
			aFilenameStrBase.delDirAt( 0 ) ;
		} 
		//	先頭よりの共通のディレクトリを削除します。

		//	
		int iLi ;
		for ( iLi = 0 ; iLi < aFilenameStrBase.DirCount() ; iLi ++ ){
			addDirAt( 0 , ".." ) ;
		}
	}
	// --------------------------------
	//	ファイル名
	// --------------------------------
	if ( merrRv >= 0 ){
		if ( Filename().length() > 0 ){
			if ( aFilenameStrBase.Filename().length() > 0 ){
				setFilename( ev.Filename() ) ;
			}
		}
	}
	return ( merrRv ) ;
};


