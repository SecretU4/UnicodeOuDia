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
//	CdFilenameStr.h
// ****************************************************************
*/
/** @file */
#ifndef  CdFilenameStr_h
#define  CdFilenameStr_h

#include <string>
#include <vector>

// ****************************************************************
//	CdFilenameStr
// ****************************************************************
/** @brief
* 【概要】
* 	  ドライブ・ディレクトリ・ファイルを含んだ文字列を保持します。
* 	  これらの各要素を解析し、フルパス名との間の変換を行うことができます。
* 
* 【使い方１－フルパス文字列の構成要素を取得】
*
* １． フルパス文字列を構成要素に分解する場合は、このオブジェクトを生成し、
*	フルパス文字列を setFullpathFilename() で渡してください。
*	  setFullpathFileName() は、渡されたフルパスファイル名を解析して、
*	構成要素に分解し、要素をthisの属性に設定します。
*
* ２．  setFullpathFilename() が終了したら、属性を参照することにより、
*	フルパス文字列の構成要素を取得できます。
*
* @b フルパスファイル名から拡張子を取得する例
* @code
	CdFilenameStr	aCdFilenameStr ;
	aCdFilenameStr.setFullpathFilename( "c:\\windows\\system32\\readme.txt" ) ;
	string	strExt = aCdFilenameStr.Extension() ;
	//strExt = "txt" となります。
* @endcode
*
* 【使い方２－フルパス文字列を構築する】
*
* １． フルパス文字列を構築する場合は、このオブジェクトの各属性に、
*	構成要素を設定してください。
*
* ２．  その後、 FullpathFilename() を呼び出してください。FullpathFilename() は
*	属性をもとに、フルパスファイル名を編成して返します。
*/
class CdFilenameStr
{
// ********************************
//	インナータイプ
// ********************************
 public:
	/**
	*	ディレクトリを格納するためのコンテナです。
	* 	ディレクトリは、添え字の小さい方から順に格納されます。
	*/
	typedef std::vector<std::string>	ContstrDir ;
// ********************************
/// @name	属性
// ********************************
///@{
 private:
	/**
	* 	ドライブ文字です。 ":" は含みません。
	* 	ドライブ文字がない場合は、空文字列です。
	*
	*	例:
	*	 "C:\Windows\System32\readme.txt" の場合は、
	*	この属性は "C" となります。
	*/
	std::string					m_strDrive ;
	
	/**
	*	ディレクトリを、格納しています。
	* 	ディレクトリは、添え字の小さい方から順に格納されます。
	*
	*	例:
	*	 "C:\Windows\System32\readme.txt" の場合は、
	*	この属性は
	*
	* -		[0]="Windows"
	* -		[1]="System32"
	*
	*	となります。
	*/
	ContstrDir			m_contstrDir ;
	
	/**
	* 	ベースファイル名です。
	* 	拡張子を含みません。
	*
	*
	*	例:
	*	 "C:\Windows\System32\readme.txt" の場合は、
	*	この属性は "readme" となります。
	*/
	std::string					m_strBaseFilename ;
	
	/**
	* 	拡張子です。"."は含みません。ない場合は、空文字列です。
	*
	*	例:
	*	 "C:\Windows\System32\readme.txt" の場合は、
	*	この属性は "txt" となります。
	*/
	std::string					m_strExtension ;
	
	/**
	* 	このパスのディレクトリが絶対指定であれば偽、相対パスなら真です。
	*
	*	例:
	*	 "C:\Windows\System32\readme.txt" の場合は、
	*	この属性は true となります。
	*/
	bool						m_bIsRelativePath ;
	
	/**
	* 	このパスが、ファイル名のある形式であるなら真です。
	* 	この場合は、一番右の '\' の右側はファイル名とみなされます。
	* 	このパスが、ファイル名のない形式であれば偽です。
	* 	この場合は、一番右の '\' の右側もディレクトリとみなします。
	*
	*	コンストラクタ・または setIsValidFilename() により、あらかじめ明示的な
	*	設定が必要な属性です。
	*/
	bool						m_bIsValidFilename ;
///@}

// ********************************
//	コンストラクタ・デストラクタ
// ********************************
 public:
	CdFilenameStr() ;
	/**
	* @param strFilename [in]
	* 	フルパス名（ドライブ・ディレクトリ・ファイル名が混合した文字列）
	* 	を指定してください。
	* @param bIsValidFilename [in]
	* 	このパスが、ファイル名のある形式であるなら真です。
	* 	この場合は、一番右の '\' の右側はファイル名とみなされます。
	* 	このパスが、ファイル名のない形式であれば偽です。
	* 	この場合は、一番右の '\' の右側もディレクトリとみなします。
	*/
	CdFilenameStr( std::string strFilename , bool bIsValidFilename = true ) ;

// ********************************
//	CdFilenameStr
// ********************************
 public:
	// ********************************
	///	@name 属性
	// ********************************
	///@{

	/**
	* 	ドライブ文字です。
	* 	ドライブ文字がない場合は、空文字列です。
	*/
	std::string			Drive() const ;
	CdFilenameStr& 		setDrive( const std::string& ev ) ;
	
	/**
	* 	ディレクトリを返します。
	* 	ディレクトリは、添え字の小さい方から順に格納されています。
	*/
	ContstrDir		Dirs()const  ;
	CdFilenameStr& 	setDirs( const ContstrDir& ev ) ;
	
	/**
	* @return
	* 	ディレクトリの数（階数）を返します。
	*/
	int DirCount()const ;
	
	/**
	* 	ディレクトリを返します。
	* @param index [in]
	* 	ディレクトリの階数（Dirsの添字）を、０以上DirCount()未満の数で
	*	指定してください。
	* @return
	* 	ディレクトリを返します。
	*/
	std::string DirAt( int idx )const ;
	
	/**
	* 	ディレクトリを末尾に追加します。
	* @param ev [in]
	* 	追加するディレクトリの名前を指定してください。
	*/
	CdFilenameStr& 	addDirLast( const std::string& ev ) ;
	
	/**
	* 	ディレクトリを指定の位置に追加します。
	* @param index [in]
	* 	追加する場所を、０以上DirCount()以下の数で指定してください。
	* @param ev [in]
	* 	追加するディレクトリの名前を指定してください。
	*/
	CdFilenameStr& 	addDirAt( int index , const std::string& ev ) ;
	
	/**
	* 	ディレクトリの末尾を削除します。
	*/
	CdFilenameStr& 	delDirLast() ;
	/**
	* 	ディレクトリを削除します。
	* @param index [in]
	* 	削除するディレクトリを、０以上DirCount()未満の数で指定してください。
	*/
	CdFilenameStr& 	delDirAt( int index ) ;
	
	
	/**
	* 	ベースファイル名です。
	* 	拡張子を含みません。
	*/
	std::string				BaseFilename() const ;
	CdFilenameStr& 			setBaseFilename( const std::string& ev ) ;
	
	/**
	* 	拡張子です。
	*/
	std::string					Extension() const ;
	CdFilenameStr& 				setExtension( const std::string& ev ) ;
	
	/**
	* 	このパスが絶対パスであれば偽、相対パスなら真です。
	*/
	bool						IsRelativePath() const ;
	CdFilenameStr&				setIsRelativePath( bool ev ) ;
	
	/**
	* 	このパスが、ファイル名のある形式であるなら真です。
	* 	この場合は、フルパス文字列を解析する場合に、
	* 	一番右の "\" の右側をファイル名とみなされます。
	* 	このパスが、ファイル名のない形式であれば偽です。
	* 	この場合は、フルパス文字列を解析する場合に、
	* 	一番右の "\" の右側もディレクトリとみなします。
	*/
	bool						IsValidFilename() const ;
	CdFilenameStr&				setIsValidFilename( bool ev ) ;
	
	/**
	* @return
	* 	ベースファイル名と拡張子を結合したファイル名を返します。
	*/
	std::string 				Filename() const ;

	/**
	* @param ev [in]
	* 	ベースファイル名と拡張子を結合したファイル名を指定してください。
	* @return
	* 	このオブジェクトを返します。
	*/
	CdFilenameStr& 				setFilename( std::string ev ) ;
	
	///@}
	
	// ********************************
	///	@name 操作
	// ********************************
	///@{
	
	/**
	* @return
	* 	フルパスファイル名を取得することができます。
	* 	属性の各要素を結合して、フルパス文字列を作成します。
	* 
	* 	m_bIsValidFilename が真の場合は、ファイル名があってもなくても、
	* 	ディレクトリ名のあとに '\' がつきます。
	* 	m_bIsValidFilename が偽の場合は、
	* 	ディレクトリ名のあとに '\' がつきません。また、ファイル名は
	* 	出力されません。
	*/
	std::string 				FullpathFilename() const ;
	
	/**
	* 	フルパスファイル名を解析することができます。
	* @param strFilename [in]
	* 	フルパス名（ドライブ・ディレクトリ・ファイル名が混合した文字列）
	* 	を指定してください。
	* @param bIsValidFilename [in]
	* 	このパスが、ファイル名のある形式であるなら真です。
	* 	この場合は、一番右の '\' の右側はファイル名とみなされます。
	* 	このパスが、ファイル名のない形式であれば偽です。
	* 	この場合は、一番右の '\' の右側もディレクトリとみなします。
	* 	指定しない場合は、現在のモードを維持します。
	* @return
	* 	このオブジェクトを返します。
	*/
	CdFilenameStr& setFullpathFilename( std::string ev , 
										bool bIsValidFilename ) ;
	/** @overload */
	CdFilenameStr& setFullpathFilename( std::string ev ) ;

	/**
	* 	ディレクトリを、evにしたがって相対移動します。
	* 
	* 	   ev のディレクトリが相対指定なら、thisのディレクトリを
	* 	 ev のディレクトリにしたがって相対移動します。
	* 	   ev のディレクトリが絶対指定なら、 this のディレクトリは
	* 	ev に置き換えます。
	* 	   ev にディレクトリ以外の要素が含まれている場合、
	* 	this のものを ev のものに置き換えます。
	* @param ev [in]
	* 	移動先を指定してください。
	*/
	CdFilenameStr& ChangeDir( const CdFilenameStr& ev ) ;
	
	/**
	* 	  ディレクトリを、evからの相対指定に変換します。
	* 	 this・evのディレクトリは、絶対指定でなくてはなりません。
	* 	どちらかが相対指定である場合は、この関数は失敗します。
	* 	 thisにディレクトリ以外の要素が指定されていた場合、それは
	* 	維持されます。
	* 	  ev にディレクトリ以外の要素が指定されていて
	* 	 this に対応する要素が指定されていない場合は、
	* 	 ev のものを this にコピーします。
	* @param ev [in]
	* 	移動元を指定してください。
	* @return
	* 	-	0:成功
	* 	-	-1 ;	// 	 ドライブが異なるため、相対パスにはできません。
	* 	-	-2 ;	//	 thisが相対パスです
	* 	-	-3 ;	//	 evが相対パスです
	*/
	int ChangeToRelativeDir( const CdFilenameStr& ev ) ;
	
	///@}
	
	// ********************************
	//	演算子
	// ********************************
	
	/** FullpathFilename() と等価です */
	operator std::string()const{	return FullpathFilename() ; } ;
};

#endif /*CdFilenameStr_h*/

