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
//	stringSplit.h
// ****************************************************************
*/
/** @file 
*	@brief
* 【概要】
* 	文字列を、区切りとなる文字で分割する関数 splitc ,文字列を連結する joinc 
*	を収録しています。
*/
#ifndef  stringSplit_h
#define  stringSplit_h

#ifndef  NO_OuLib_NAMESPACE
/** @namespace
*/
namespace OuLib{
#endif /*NO_OuLib_NAMESPACE*/

/**
* 	文字列を区切り文字に分割して、分割後の要素を格納したコンテナを返します。
* 	文字列は STL ・コンテナは STL の文字列クラスを対象とするSTLコンテナを
* 	想定しています。
* @param StringContainerType
*	STL文字列を対象としたSTLコンテナを指定してください。
* 	ここで指定した型が、戻り値の型となります。	\n
* 	（例） std::deque<std::string>  std::vector<std::string> など
* @param chSplit [in]
* 	  区切り文字を指定してください。
* @param eStr [in]
* 	  分割の対象となる文字列を指定してください。
* @param bDropEmpty [in]
*	-  真なら、区切り文字の間が空文字列の場合、
*	その場所に対応する要素（空文字列）を
*	コンテナに格納しません。\n
*	-   偽なら、区切り文字の間が空文字列の場合でも、\n
*	それをコンテナに格納します。
*	  既定値は偽です。
* @return
* 	  分割後の文字列を格納したコンテナを返します。
*
* @b 使用例
* @code
	string	aConnectedString( "PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1" ) ;
	deque<string>	strRv3= splitc< deque<string> >( ';' , aConnectString ) ;
	//	strRv3[0] = "PROTOCOL=TCP"
	//	strRv3[1] = "REMOTEIPADDR=192.168.0.1"
	//	となります
	//
* @endcode
*
* @note
*	eStr が空文字列の場合、
*	 bDropEmpty が偽なら、この関数は空文字列１つを格納した
*	コンテナを返します(空文字列も要素とみなすからです)。
*	 bDropEmpty が真なら、この関数は要素０の
*	コンテナを返します(空文字列は捨てるからです)。
*	
*/
template< class StringContainerType > 
StringContainerType splitc( 
		typename StringContainerType::value_type::const_reference chSplit , 
		typename StringContainerType::const_reference strEv ,
		bool bDropEmpty = false )
{
	StringContainerType	contRv ;
	typedef typename StringContainerType::value_type	StringType ;
	typedef typename StringType::size_type				StringSizeType ;

	StringSizeType	len = strEv.length() ;
	StringSizeType	posItemBegin = 0 ;
	while ( posItemBegin <= len ){
		// --------------------------------
		//	CdItemの範囲を決定
		// --------------------------------
		StringSizeType posSplit = 
			strEv.find( chSplit , posItemBegin ) ;
		if ( posSplit == StringType::npos ){
			posSplit = len ;
		}
		//posSplit = 文字列の終端か、アイテム区切り文字を指しています。 
		//posItemBegin〜posSplit = 今回のアイテム

		{
			StringType strItem = 
				strEv.substr( posItemBegin , posSplit - posItemBegin ) ;
			if ( !( strItem.empty() && bDropEmpty ) ){
				contRv.push_back( strItem ) ;
			}
		}
		posItemBegin = posSplit + 1  ;
	}
	return ( contRv ) ;
}

/**
* 	コンテナに格納されている文字列を、区切り文字を挿入して結合します。
* 	文字列は STL ・コンテナは STL の文字列クラスを対象とするSTLコンテナを
* 	想定しています。
* @param StringContainerType
* 	STL文字列を対象としたSTLコンテナを指定してください。
* 	ここで指定した型が、contStrの型となります。	\n
* 	（例） std::deque<std::string>  std::vector<std::string> など
* @param chSplit [in]
* 	区切り文字を指定してください。
* @param contStr [in]
* 	結合したい文字列を格納したコンテナを指定してください。
* @param bDropEmpty [in]
*	-   真なら、コンテナの要素に空文字列がある場合、
*	その要素は無視します（対応する区切り文字も
*	結合後文字列に追加しません）。
*	-   偽なら、コンテナの要素に空文字列がある場合、
*	区切り文字だけを結合後文字列に追加します。
*	  既定値は偽です。
* @return
* 	結合後の文字列を返します。
*
* @b 使用例
* @code
	deque<string>	strRv3 ;
	strRv3.push_back( "PROTOCOL=TCP" ) ;
	strRv3.push_back( "REMOTEIPADDR=192.168.0.1" ) ;
	string	aConnectedString = joinc( ';' , strRv3 ) ;
	//	aConnectedString="PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1" 
	//	となります
	//
* @endcode
*/
template< class StringContainerType > 
typename StringContainerType::value_type joinc(
	typename StringContainerType::value_type::const_reference chSplit , 
	const StringContainerType& contStr  ,
	bool bDropEmpty = false )
{
	typedef typename StringContainerType::value_type	StringType ;
	StringType	strRv ;

	// --------------------------------
	//	結果文字列のサイズを概算
	// --------------------------------
	{
		long	lSize = 0 ;
		typename StringContainerType::const_iterator	ite ;
		for ( ite = contStr.begin() ; ite != contStr.end() ; ite ++ ){
			if ( !( ite->empty() && bDropEmpty ) ){
				if ( !strRv.empty() ){
					lSize += 1 ;
				}
				lSize += ite->size() ;
			}
		}
		strRv.reserve( lSize ) ;
	}
	// --------------------------------
	{
		typename StringContainerType::const_iterator	ite ;
		for ( ite = contStr.begin() ; ite != contStr.end() ; ite ++ ){
			if ( !( ite->empty() && bDropEmpty ) ){
				if ( ite != contStr.begin() ){
					strRv += chSplit ;
				}
				strRv += *ite ;
			}
		}
	}
	return ( strRv ) ;
}

#ifndef  NO_OuLib_NAMESPACE
};
#endif /*NO_OuLib_NAMESPACE*/


#endif /*stringSplit_h*/
