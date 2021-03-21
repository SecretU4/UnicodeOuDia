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
//	CdConnectedString.h
// ****************************************************************
*/
/** @file */
#ifndef  CdConnectedString_h
#define  CdConnectedString_h

#include <string>
#include <deque>

namespace OuLib{
namespace Str{

// ****************************************************************
//	CdConnectedString
// ****************************************************************
/**
* @brief
* 【概要】
* 	１バイトの区切り文字（デフォルトは';'）で区切られた
* 	(項目名)=(値)の形式の『連結文字列』を保持する単純データクラスです。
* 	
* 		（例）"PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1;REMOTEPORT=8001"
* 	
* 	このクラスでは、上記形式の文字列全体
* 		（例）"PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1;REMOTEPORT=8001"
* 	を、『連結文字列』。
* 	区切り文字で区切られた文字列１つ
* 		（例）"PROTOCOL=TCP"
* 			"REMOTEIPADDR=192.168.0.1"
* 			"REMOTEPORT=8001"
* 	を『アイテム』
* 	アイテム内の=の左側
* 		（例）"PROTOCOL"
* 			"REMOTEIPADDR"
* 			"REMOTEPORT"
* 	を『項目名』
* 	アイテム内の=の右側
* 		（例）"TCP"
* 			"192.168.0.1"
* 			"8001"
* 	を『値』と呼んでいます。
* 	
* 	このクラスは、連結文字列内のアイテムを編集する機能や、
* 	アイテム内の項目名・値を編集する機能を持っています。
* 	
*/
class CdConnectedString 
{
// ********************************
//	インナー定義
// ********************************
 public:
	
	/**
	* @brief
	*	アイテム１つの内容を表す構造体です。
	*/
	struct ITEM
	{
		ITEM( const std::string& strName = "" , 
			const std::string& strValue = "" )
			: m_strName( strName ) , m_strValue( strValue )	{};
		
		/**
		* 	アイテム内の、項目名。
		*	値部分がない場合は、アイテム文字列全体が項目名になります。
		*/
		std::string	m_strName ;

		/**
		*	アイテム内の、値。
		*	値部分がない場合は、空文字列になります。
		*/
		std::string	m_strValue ;
	};

// ********************************
//	属性
// ********************************
 private:
	///	アイテム間の区切り文字です。デフォルトは';'です
	char		m_chSplit ;

	
	///	項目と値の間の区切り文字です。デフォルトは'='です
	char		m_chEqualChar ;

// --------------------------------
//	内部データ
// --------------------------------
 private:
	///	アイテムを保持するコンテナの型を表します。
	typedef std::deque<ITEM>	ITEMCont ;
	
	///	アイテムを保持するコンテナです。
	ITEMCont	m_contItem ;



// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	* @param chSplit [in]
	* 	アイテム間の区切り文字を指定してください。
	* @param chEqualChar [in]
	* 	項目と値の間の区切り文字を指定してください。
	*/
	CdConnectedString( char chSplit = ';' , char chEqualChar = '=' ) 
		: m_chSplit( chSplit ) , m_chEqualChar( chEqualChar ){};
	
	/**
	* @param ev [in]
	* 	連結文字列を指定してください。
	* @param chSplit [in]
	* 	区切り文字を指定してください。
	* @param chEqualChar [in]
	* 	項目と値の間の区切り文字を指定してください。
	*/
	CdConnectedString( const std::string& ev ,  char chSplit = ';' , 
										char chEqualChar = '=' ) 
		: m_chSplit( chSplit ) , m_chEqualChar( chEqualChar )
	{
		decode( ev ) ;
	};
	
	virtual ~CdConnectedString(){} ;

// ********************************
//	コンテナ操作
// ********************************
 public:
	/**
	* @return
	* 	アイテムの数を返します。
	*/
	int size()const{	return ( (int)m_contItem.size() ) ; } ;
	
	/**
	* 	指定の位置にあるアイテムを参照します。
	* @param idx [in]
	* 	０以上size()未満のインデクスを指定してください。
	* @return
	* 	アイテムを返します。
	*/
	ITEM at( int idx )const{	return ( m_contItem[ idx ] ) ; } ;
	
	
	/**
	* 	指定の位置に新しいアイテムを挿入します。
	* @param idx [in]
	* 	０以上size()以下のインデクスを指定してください。
	* 	-1なら、末尾に追加します。
	* @param ev [in]
	* 	挿入するアイテムを指定してください。
	* @return
	* 	成功したら0以上、失敗したら負の数です
	*/
	int insert( int idx , const ITEM& ev ){
		if ( idx < 0 ){
			idx = size() ;
		}
		if ( !( 0 <= idx && idx <= size() ) ){
			return -1 ;
		}
		m_contItem.insert( m_contItem.begin() + idx , ev ) ;
		return ( 0 ) ; 
	} ;

	/**
	* 	指定の位置からアイテムを除去します。
	* @param idx [in]
	* 	０以上size()未満のインデクスを指定してください。
	* @return
	* 	成功したら0以上、失敗したら負の数です
	*/
	int erase( int idx ){
		if ( !( 0 <= idx && idx < size() ) ){
			return -1 ;
		}
		m_contItem.erase( m_contItem.begin() + idx ) ;
		return ( 0 ) ; 
	};
	
	/**
	* 	指定の項目名を持つアイテムの位置を調べます
	* @param strName [in]
	* 	項目名を指定してください。
	* @return
	* 	成功したら0以上のインデクス、見つからなければ-1です
	*/
	int find( std::string strName )const{
		int idx ;
		for ( idx = 0 ; idx < size() && at( idx ).m_strName != strName 
								; idx ++ ){}
		if ( idx == size() ){
			idx = -1 ;
		}
		return ( idx ) ;
	};

	/**
	* 	指定の項目名を持つアイテムを削除します
	* @param strName [in]
	* 	項目名を指定してください。
	* @return
	* 	成功したら、削除したアイテムの元々あった位置のインデクス、
	* 	見つからなければ-1です
	*/
	int remove( std::string strName ){
		int idx = find( strName )  ;
		if ( idx >= 0 ){
			erase( idx ) ;
		}
		return ( idx ) ;
	};
	
	/**
	*	すべてのアイテムを破棄します。
	*/
	void clear(){
		m_contItem.clear() ;
	};
	
	/**
	* 	指定の項目名を持つアイテムの値を返します。
	* @param strName [in]
	* 	項目名を指定してください。
	* @return
	* 	成功したら、値を返します。
	* 	項目が存在しない場合は、空文字列を返します。
	*/
	std::string getValue( std::string strName )const{
		int idx = find( strName ) ;
		if ( idx < 0 ){
			return ( "" ) ;
		}
		return ( at( idx ).m_strValue )  ;
	}; 
	
	
	/**
	* 	指定の項目名を持つアイテムの値を変更します。
	* 	このとき、指定の項目名を持つアイテムが存在しなければ、
	* 	新しいアイテムを追加した上で、項目名・値をセットします。
	* @param strName [in]
	* 	項目名を指定してください。
	* @param strValue [in]
	* 	値を指定してください。
	* @return
	* 	成功したら0以上、失敗したら負の数です
	*/
	int setItem( const std::string& strName , const std::string& strValue ){
		int idx = remove( strName ) ;
		return ( insert( idx , ITEM( strName ,strValue ) ) ) ;
	}; 

// ********************************
//	CdConnectedString特有
// ********************************
 public:
	// ********************************
	//	属性
	// ********************************
	char getSplit()const {	return ( m_chSplit ) ; } ;
	CdConnectedString& setSplit( char chSplit ){
		m_chSplit = chSplit ; return ( *this ) ;} ;

	char getEqualChar()const{	return ( m_chEqualChar ) ; } ;
	CdConnectedString& setEqualChar( char ev ){	
		m_chEqualChar = ev ; return ( *this ) ;} ;

	/**
	* @return
	* 	このオブジェクトが保持しているアイテムと区切り文字をもとに、
	* 	連結文字列を作成し、それを返します。
	*/
	std::string encode()const{
		std::string	strRv ;
		int	idx ;
		for ( idx = 0 ; idx < size() ; idx ++ ){
			if ( idx != 0 ){
				strRv += getSplit() ;
			}
			strRv += at( idx ).m_strName ;
			if ( !at( idx ).m_strValue.empty() ){
				strRv += getEqualChar() ;
				strRv += at( idx ).m_strValue ;
			}
		};
		return ( strRv ) ;
	};

	/**
	* 	指定の連結文字列を、このオブジェクトに格納します。
	* @param strEv [in]
	* 	連結文字列を指定してください。
	* @return
	* 	成功したら0以上、失敗したら負の数です
	*/
	int decode( const std::string&	strEv ){
		int iRv = 0 ;
		clear() ;
		std::string	strLeft = strEv ;
		
		while ( !strLeft.empty() ){
			// --------------------------------
			//	次のITEMを切り出します。
			// --------------------------------
			std::string	strItem ;
			{

				int	idx ;
				for ( idx = 0 ; 
					idx < (int)strLeft.size() && strLeft[idx] != getSplit() ; 
					idx++ ){}
				
				//idx = 文字列の終端か、アイテム区切り文字を指しています。

				if ( idx == strLeft.size() ){
					strItem = strLeft ; 
					strLeft = "" ;
				}	else	{
					strItem = strLeft.substr( 0 , idx ) ;
					strLeft.erase( 0 , idx + 1 ) ;
				}
				
				//strItem = こんどのアイテム
				//strLeft = こんどのアイテム（と、その直後の区切り文字）を
				//	削除しました。
			}
			if ( strItem.empty() ){
				continue ;
			}
			// --------------------------------
			//	NAMEとVALUEに分離します。
			// --------------------------------
			{
				ITEM	aItem ;
			
				int	idx ;
				for ( idx = 0 ; 
					idx < (int)strItem.size() && strItem[idx] != getEqualChar() ; 
					idx++ ){}
				
				//idx = strItem の文字列の終端か、'='を指しています。

				if ( idx == strItem.size() ){
					aItem.m_strName = strItem ;
				}	else	{
					aItem.m_strName = strItem.substr( 0 , idx ) ;
					aItem.m_strValue = strItem.substr( idx + 1 )  ;
				};
				
				insert( -1 , aItem ) ;
			}
		}
		return ( iRv ) ;
	};
// ********************************
//	演算子
// ********************************
 public:
	/** encode() と等価です */
	operator std::string()const {	return encode() ;	};
};


} //namespace OuLib{
} //namespace Str{


#endif /*CdConnectedString_h*/

