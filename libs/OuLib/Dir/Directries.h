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
//	dir\Directries.h
// ****************************************************************
*/
/** @file
* @brief
* 【概要】
*	  ディレクトリ内のファイルやディレクトリの一覧を取得する関数を
*	収録しています。
*/
#ifndef  Directries_h
#define  Directries_h
#include <string>
#include <deque>

namespace OuLib{
namespace Dir{


// ****************************************************************
//	IfDirCallback
// ****************************************************************
/**
 * @brief
 *	findDir() ・ findFile() 関数に登録するコールバックインターフェースです。
 */
class IfDirCallback
{
 public:
	/**
		見つかったファイル名・ディレクトリ名を、呼出元に通知します。
	 @param strName [in]
		見つかったファイル名・ディレクトリ名
	 */
	virtual void OnNameFound( const std::string& strName ) = 0 ;
};



// ****************************************************************
///@name ファイル/ディレクトリ検索
// ****************************************************************
///@{
/**
 	検索文字列に合致するディレクトリ名を検索します。

	通常のディレクトリ検索には Dirnames() を使用できます。

 	ディレクトリ名の指定には、*や?のワイルドカードを
 	使用することができます。
 	ワイルドカードは、検索文字列内の最下位の
 	ディレクトリ名にだけ、使用可能です
 		（例："c:\windows\*" "c:\windows\???" "c:\user\s*" ） 
	
	この関数は、ディレクトリをみつける毎に、登録された IfDirCallback 
	インターフェースの関数 IfDirCallback::OnNameFound() を呼び出します。
 @param strSearch [in]
 	　検索文字列を指定してください。
 @param bSubdirectrySearch [in]
 	　真なら、サブディレクトリを検索対象に含めます。
 @param pIfDirCallback [in]
	  この関数は、ディレクトリを見つけるごとに、
	 pIfDirCallback->OnNameFound() で、見つかった名前を通知します。
	 NULL は指定できません。
 @return
 	  成功したら、０以上（見つかった名前の数）、エラーなら負の数です。
		-	-1 ;	//	パラメータが不正です\n
			strSearch の末尾に "."  , ".." を指定することはできません。
 @attention
 	 strSearch の末尾に "." ( カレントディレクトリ ) , ".." (親ディレクトリ) を
	指定することはできません。この場合は、 -1 を返します。
	  カレントディレクトリの親ディレクトリのサブディレクトリを指定する場合は、"..\*"
	を指定してください。
 */
int findDir( const std::string& strSearch , 
						bool bSubdirectrySearch , 
						IfDirCallback* pIfDirCallback ) ;

/**
 	検索文字列に合致するファイル名を検索します。

	通常のディレクトリ検索には Filenames() を使用できます。

 	ファイル名の指定には、*や?のワイルドカードを
 	使用することができます。
 	ワイルドカードは、検索文字列内の最下位の
 	ファイル名にだけ、使用可能です
 		（例："c:\windows\*" "c:\windows\???" "c:\user\s*" ） 
	
	この関数は、ファイルをみつける毎に、登録された IfDirCallback 
	インターフェースの関数 IfDirCallback::OnNameFound() を呼び出します。
	ください。* @param strSearch [in]
 	　検索文字列を指定してください。
 @param bSubdirectrySearch [in]
 	　真なら、サブディレクトリを検索対象に含めます。
 @param pIfDirCallback [in]
	  この関数は、ファイルを見つけるごとに、
	 pIfDirCallback->OnNameFound() で、見つかった名前を通知します。
	 NULL は指定できません。
 @return
 	  成功したら、０以上（見つかった名前の数）、エラーなら不の数です。
 */
int  findFile( const std::string& strSearch , 
						bool bSubdirectrySearch ,
						IfDirCallback* pIfDirCallback ) ;

///@}
// ****************************************************************
///@name ディレクトリ作成
// ****************************************************************
///@{
/**
	サブディレクトリを作成します。
	複数段のサブディレクトリを一度に作成することができます。
@param strDir [in]
	ディレクトリを指定してください。
	末尾の "\" は、あってもなくてもかまいません。
@return
	成功したら 0 以上、エラーなら負の数です。
	-	1 ;	//	ディレクトリの作成に成功しました。
	-	0 ;	//	ディレクトリは既に存在していました。
	-	-1 ;	//	ディレクトリの作成に失敗しました。
*/
int mkdirs( const std::string& strDir ) ;

/** 
	指定されたディレクトリが空であれば、そのディレクトリを削除します。 
	指定されたディレクトリのサブディレクトリ内の空のディレクトリもすべて 
	削除します。 

	引数を指定しない場合は、カレントディレクトリを指定したものとみなします。 

@param strDir [in] 
	削除するディレクトリを指定してください。
@param pErrorStream [in]
@return 
	-	0 ;	//	ディレクトリは削除できました。 
	-	-1 ;	//	strDirの削除に失敗しました。 
	-	-2 ;	//	このディレクトリにはファイルがあります。 
	-	-3 ;	//	サブディレクトリの削除に失敗しました。 
*/ 
int rmempdir( const std::string& strDir , FILE* pErrorStream ) ;

///@}
// ****************************************************************
//	CDirCallback_StrContainer< class StrContainerType >
// ****************************************************************
/**
 @brief
	findDir() ・ findFile() 関数で検索したファイルを、
	STLコンテナに追加するコールバッククラスです。

【使い方】

  Dirnames() , Filenames() 関数を参考にしてください。

 @param StrContainerType
	std::string を格納するSTLコンテナを指定してください。@n
	(例) std::deque< std::string > std::vector< std::string >
*/
template< class StrContainerType >
class CDirCallback_StrContainer : public IfDirCallback
{
 private:
	// ********************************
	/// @name 関連	
	// ********************************
	///@{
	/**
		findDir() ・ findFile() 関数で検索したファイルを、
		追加するSTLコンテナ。
		このオブジェクトの破棄の責務は暮らすユーザーにあります。
		このオブジェクトは、 this より長く生存しなくては
		なりません。
	 */
	StrContainerType*	m_pStrContainerType ;
	///@}
 public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	 @param pStrContainerType [in]
		findDir() ・ findFile() 関数で検索したファイルを、
		追加するSTLコンテナ。
		このオブジェクトの破棄の責務はクラスユーザーにあります。
		このオブジェクトは、 this より長く生存しなくては
		なりません。
	 */
	CDirCallback_StrContainer( StrContainerType* pStrContainerType )
		: m_pStrContainerType( pStrContainerType ){};
 public:
	// ********************************
	///@name IfDirCallback	
	// ********************************
	///@{
	/**
		見つかったファイル名・ディレクトリ名を、呼出元に通知します。
	 @param strName [in]
		見つかったファイル名・ディレクトリ名
	
	 [オーバライド]
		m_pStrContainerType が指すコンテナに，push_back()メソッドで
		名前を追加します。
	 */
	virtual void OnNameFound( const std::string& strName ) 
	{
		m_pStrContainerType->push_back( strName ) ;
	};
	///@}
};

// ****************************************************************
///@name ファイル/ディレクトリ検索
// ****************************************************************
///@{

/**
 	Dirnames() Filenames() がファイル名の一覧を格納するコンテナ
 */
typedef std::deque<std::string> ContFilenames ;

/**
 	検索文字列に合致するディレクトリ名を検索し、
 	その一覧のコンテナを返します。
 	ディレクトリ名の指定には、*や?のワイルドカードを
 	使用することができます。
 	ワイルドカードは、検索文字列内の最下位の
 	ディレクトリ名にだけ、使用可能です
 		（例："c:\windows\*" "c:\windows\???" "c:\user\s*" ） 
@param strSearch
 	　検索文字列を指定してください。
@param bSubdirectrySearch
 	　真なら、サブディレクトリを検索対象に含めます。
@return
 	  検索文字列に合致するディレクトリ名を格納した
 	stlコンテナです。
@attention
 	 strSearch の末尾に "." ( カレントディレクトリ ) , ".." (親ディレクトリ) を
	指定することはできません。この場合は、 戻り値のコンテナは
	要素数が 0 になります。
 */
inline ContFilenames Dirnames( const std::string& strSearch , 
						bool bSubdirectrySearch )
{
	ContFilenames	aContFilename ;
	CDirCallback_StrContainer<ContFilenames>	aCallback( &aContFilename ) ;
	findDir( strSearch , bSubdirectrySearch , &aCallback ); 
	return ( aContFilename ) ;
}

/**
 	検索文字列に合致するファイル名を検索し、
 	その一覧のコンテナを返します。
 	ファイル名の指定には、*や?のワイルドカードを
 	使用することができます。
 	ワイルドカードは、検索文字列内の最下位の
 	ファイル名にだけ、使用可能です
 		（例："c:\windows\*" "c:\windows\???" "c:\user\s*" ） 
@param strSearch
 	　検索文字列を指定してください。
@param bSubdirectrySearch
 	　真なら、サブディレクトリを検索対象に含めます。
@return
 	  検索文字列に合致するファイル名を格納した
 	stlコンテナです。
 */
inline ContFilenames Filenames( const std::string& strSearch , 
						bool bSubdirectrySearch )
{
	ContFilenames	aContFilename ;
	CDirCallback_StrContainer<ContFilenames>	aCallback( &aContFilename ) ;
	findFile( strSearch , bSubdirectrySearch , &aCallback ); 
	return ( aContFilename ) ;
}
///@}


} //namespace Dir{
} //namespace OuLib{

#endif /*Directries_h*/

