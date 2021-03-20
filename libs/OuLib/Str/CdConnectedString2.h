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
//	CdConnectedString2.h
// ****************************************************************
*/
/** @file */
#ifndef  CdConnectedString2_h
#define  CdConnectedString2_h

#include <string>
#include <deque>
#include <vector>

namespace OuLib{
namespace Str{

// ****************************************************************
//	CdConnectedString2
// ****************************************************************
/**
@brief
  １バイトの区切り文字（デフォルトは';'）で区切られた
(項目名)=(値) の形式の『連結文字列』を保持する単純データクラスです。

『連結文字列』は、以下のようなものを指します。

	（例）"PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1;REMOTEPORT=8001"

このクラスでは、『連結文字列』内の区切り文字で区切られた文字列１つ

	（例）
		"PROTOCOL=TCP"
		"REMOTEIPADDR=192.168.0.1"
		"REMOTEPORT=8001"

を『アイテム』

アイテム内の=の左側

	（例）
		"PROTOCOL"			
		"REMOTEIPADDR"		
		"REMOTEPORT"

を『項目名』

アイテム内の=の右側

	（例）
		"TCP"				
		"192.168.0.1"		
		"8001"

を『値』と呼んでいます。

このクラスは、連結文字列内のアイテムを編集する機能や、
アイテム内の項目名・値を編集する機能を持っています。

 このクラスは、 CdConnectedString の上位バージョンにあたります。
CdConnectedString に、サブアイテムの編集機構が追加されています。

 <H4> 	
 【サブアイテム】
 </H4> 	

  アイテムの『項目名』のうち、先頭よりに同一の文字列を持つアイテムは、
一つのサブアイテムとして扱うことができます。

  getSubitem() 関数は、this が保持するアイテムのうち、一つの
サブアイテムを取得して、新しい CdConnectedString2 オブジェクトに
格納します。

（例） this が "Items.name"・"Items.value"・"Attribute" という
『項目名』の３つのアイテムを保持しているときに、
引数 strSubitemName に "Items." を指定して getSubitem() を呼び出すと、
getSubitem() 関数は新しい CdConnectedString2 オブジェクトに
"name"・"value" という『項目名』でアイテムを追加します。
（『項目名』からは、 strSubitemName の文字列を削除します。）
 */
class CdConnectedString2 
{
// ********************************
//	インナータイプ
// ********************************
 public:
	
	// ****************************************************************
	//	CdConnectedString2::CdItem
	// ****************************************************************
	/**
	 @brief
	 【概要】
		アイテム１つの内容を表す構造体です。
	*/
	class CdItem
	{
	private:
		// ********************************
		///@name 属性
		// ********************************
		///@{
		/**
		  	アイテム内の、項目名。
		 	値部分がない場合は、アイテム文字列全体が項目名になります。
		 */
		std::string	m_strName ;

		/**
		 	アイテム内の、値。
		 	値部分がない場合は、空文字列になります。
		 */
		std::string	m_strValue ;
		///@}
		
	 public:
		// ********************************
		//	コンストラクタ
		// ********************************
		CdItem( const std::string& strName = "" , 
			const std::string& strValue = "" )
			: m_strName( strName ) , m_strValue( strValue )	{};
	
	 public:
		// ********************************
		///@name CdConnectedString2::CdItem-属性
		// ********************************
		///@{
		std::string	getName()const {	return m_strName ; };
		CdItem& setName( const std::string& value ){
			m_strName = value; return *this ; };
		std::string	getValue()const{	return m_strValue ;};
		CdItem& setValue( const std::string& value ){
			m_strValue = value ; return *this ; } ;
		///@}
		
	};

	/** アイテムを保持するコンテナの型を表します。*/
	typedef std::deque<CdItem>	CdItemCont ;

private:
	// ********************************
	///@name	属性
	// ********************************
	///@{
	/**	アイテム間の区切り文字です。デフォルトは ";" です	*/
	char		m_chSplit ;

	
	/**	項目と値の間の区切り文字です。デフォルトは "=" です */
	char		m_chEqualChar ;

	/**	
		『値』のない『アイテム』を encode() で出力するか否かの指定です。
	 - true ;		encode() は、『値』のない『アイテム』を
					出力します（既定値）。
	 - false ;	encode() は、『値』のない『アイテム』を
					出力しません。
	
	 @attention
		すべてのアイテムについて、『値』の取得を常に getValue() で行っている
	  （「『項目名』に対応するアイテムがない場合」と、
		「『項目名』に対応するアイテムはあるが『値』が空文字列の場合」を
		同一視している）場合は、この属性を false にすることができます。
		この場合、 encode() が生成する文字列のサイズを削減することが
		できます。
	 */
	bool		m_bEncodeNoValue ;
	///@}
	
private:
	// ********************************
	///@name	包含
	// ********************************
	///@{
	/**	アイテムを保持するコンテナです。 */
	CdItemCont	m_contItem ;

	///@}

private:
	// --------------------------------
	///@name 内部データ
	// --------------------------------
	///@{
	/**
		初期状態では空の配列です。
	
		find() 関数は、この配列に、CdItem::m_strName の辞書順
		インデクスを作成します。
		
		（例）
	
		- m_contItem[0].m_strName = "C" ;
		- m_contItem[1].m_strName = "A" ;
		- m_contItem[2].m_strName = "B" ;
	
		のとき、この配列は、
	
		- m_contiOrderIdx[0] = 1 ;	//m_contItem[1] が辞書順で１位
		- m_contiOrderIdx[1] = 2 ;
		- m_contiOrderIdx[2] = 0 ;	//m_contItem[0] が辞書順で3位
	
		となります。
	 */
	mutable std::vector<int>	m_contiOrderIdx ;
	///@}


// ********************************
//	コンストラクタ
// ********************************
 public:
	/**
	 @param chSplit [in]
	 	アイテム間の区切り文字を指定してください。
	 @param chEqualChar [in]
	 	項目と値の間の区切り文字を指定してください。
	 @param bEncodeNoValue [in]	
		『値』のない『アイテム』を encode() で出力するか否かの指定です。
	 - true ;	//	encode() は、『値』のない『アイテム』を
				//	出力します（既定値）。
	 - false ;	//	encode() は、『値』のない『アイテム』を
				//	出力しません
	 */
	CdConnectedString2( char chSplit = ';' , char chEqualChar = '=' , 
		bool bEncodeNoValue = true ) ;
	
	/**
	 @param ev [in]
	 	連結文字列を指定してください。
	 @param chSplit [in]
	 	区切り文字を指定してください。
	 @param chEqualChar [in]
	 	項目と値の間の区切り文字を指定してください。
	 @param bEncodeNoValue [in]	
		『値』のない『アイテム』を encode() で出力するか否かの指定です。
	 - true ;	//	encode() は、『値』のない『アイテム』を
				//	出力します（既定値）。
	 - false ;	//	encode() は、『値』のない『アイテム』を
				//	出力しません
	 */
	CdConnectedString2( const std::string& ev ,  char chSplit = ';' , 
		char chEqualChar = '=' , bool bEncodeNoValue = true ) ;
	
	virtual ~CdConnectedString2() ;

 public:
	// ********************************
	///@name	コンテナ操作
	// ********************************
	///@{
	/**
	 @return
	 	アイテムの数を返します。
	 */
	int size()const ;
	
	/**
	　指定の位置にあるアイテムを参照します。
	 @param idx [in]
	 	０以上size()未満のインデクスを指定してください。
	
	 @return
	 	アイテムを返します。
	 */
	const CdItem& at( int idx )const ;
	
	/**
	　指定の位置に新しいアイテムを挿入します。
	 @param idx [in]
	 	０以上size()以下のインデクスを指定してください。
	 	INT_MAX なら、末尾に追加します。
	 @param ev [in]
	 	挿入するアイテムを指定してください。
	 @return
	 	成功したら0以上、失敗したら負の数です
		-	-1 ;	//	インデクスが範囲外です。
	 */
	int insert( const CdItem& ev , int idx = INT_MAX ) ;

	/**
	　指定の位置からアイテムを除去します。
	 @param idx [in]
	 	０以上size()未満のインデクスを指定してください。
	 	INT_MAX なら、末尾のものを削除します。
	 @return
	 	成功したら0以上、失敗したら負の数です
	 */
	int erase( int idx = INT_MAX ) ;
	
	/**
 	　指定の位置のアイテムを置き換えます。
	 @param idx [in]
	 	０以上size()以下のインデクスを指定してください。
	 	INT_MAX は、末尾とみなします。
	 @param ev [in]
	 	挿入するアイテムを指定してください。
	 @return
	 	成功したら0以上、失敗したら負の数です
	*/
	int modify( const CdItem& ev , int idx = INT_MAX ) ;

	/**
	  指定の項目名を持つアイテムの位置を調べます
	 @param strName [in]
	 	項目名を指定してください。
	 @return
	 	成功したら0以上のインデクス、見つからなければ-1です
	*/
	int find( std::string strName )const ;
	
	/**
		すべてのアイテムを破棄します。
	*/
	void clear() ;
	
	///@}

 public:
	// ********************************
	///@name	CdConnectedString2-属性
	// ********************************
	///@{
	char getSplit()const {	return ( m_chSplit ) ; } ;
	CdConnectedString2& setSplit( char chSplit ){
		m_chSplit = chSplit ; return ( *this ) ;} ;

	char getEqualChar()const{	return ( m_chEqualChar ) ; } ;
	CdConnectedString2& setEqualChar( char ev ){	
		m_chEqualChar = ev ; return ( *this ) ;} ;

	bool getEncodeNoValue()const{ return m_bEncodeNoValue ;};
	CdConnectedString2& setEncodeNoValue( bool value ){
		m_bEncodeNoValue = value ; return *this ; } ;
	///@}
	
	// ********************************
	///@name	CdConnectedString2-操作
	// ********************************
	///@{
	/**
 	指定の項目名を持つアイテムの値を返します。
	 @param strName [in]
	 	項目名を指定してください。
	 @return
	 	成功したら、値を返します。
	 	項目が存在しない場合は、空文字列を返します。
	*/
	std::string getValue( std::string strName )const ;
	
	/**
 	指定の項目名を持つアイテムの値を変更します。
 	このとき、指定の項目名を持つアイテムが存在しなければ、
 	新しいアイテムを追加した上で、項目名・値をセットします。
	 @param strName [in]
	 	項目名を指定してください。
	 @param strValue [in]
	 	値を指定してください。
	 @return
	 	成功したら0以上、失敗したら負の数です
	*/
	int setItem( const std::string& strName , const std::string& strValue ) ;


	/**
	 	指定の項目名を持つアイテムを削除します
	 @param strName [in]
	 	項目名を指定してください。
	 @return
	 	成功したら、削除したアイテムの元々あった位置のインデクス、
	 	見つからなければ-1です
	*/
	int remove( std::string strName ) ;

	/**
	 @return
	 	このオブジェクトが保持しているアイテムと区切り文字をもとに、
	 	連結文字列を作成し、それを返します。
	*/
	std::string encode()const ;

	/**
 	指定の連結文字列を、このオブジェクトに格納します。
	 @param strEv [in]
	 	連結文字列を指定してください。
	 @return
	 	成功したら0以上、失敗したら負の数です
	*/
	int decode( const std::string&	strEv ) ;

	/**
 	他の CdConnectedString が保持している
	アイテム（複数）を、サブアイテムとして挿入します。
	
	 @param strSubitemName [in]
	 	サブアイテム名を指定してください。
	 @param aCdConnectedString [in]
	 	サブアイテムを保持している aCdConnectedString 
		を指定してください。
	 @return
	 	成功したら0以上、失敗したら負の数です
	
	 
		<H4>
	 【解説】
		</H4>
		サブアイテムの『項目名』は、
		strSubitemName +  (aCdConnectedString内のアイテムの項目名)
		となります。
		
	 (例)	
		
		『項目名』が "Name" ・『値』が "Untitled" の
		アイテム１つを保持した
		 CdConnectedString がある。
		
		この関数に、上記のオブジェクトを aCdConnectedString として渡す。
		strSubitemName には "Items." を指定。
	
		この場合、この関数は this に、 
		『項目名』が "Items.Name" ・『値』が "Untitled" 
		アイテムを追加します。
		
		
	 */
	int setSubitem( const std::string& strSubitemName , 
		const CdConnectedString2& aCdConnectedString ) ;
	
	/**
 	this が保持しているアイテムから、サブアイテム
	(『項目名』がサブアイテム名で始まる項目)を
	選択して、指定の CdConnectedString 
	オブジェクトに追加します。

	 @param strSubitemName [in]
	 	サブアイテム名を指定してください。
	 @param pCdConnectedString [in,out]
	 	この関数はこのオブジェクトに、取得したサブアイテムを
		追加します。
		このオブジェクトがそれまで保持していたアイテムは
		温存します。
	 @return
	 	成功したら0以上、失敗したら負の数です
	
	 
		<H4>
	 【解説】
		</H4>
		サブアイテムの『項目名』は、
		strSubitemName +  (aCdConnectedString内のアイテムの項目名)
		となります。
		
	 (例)	
		
		 this に、 
		『項目名』が "Items.Name" ・『値』が "Untitled" 
		のアイテムがある。
		
		この関数に、
		strSubitemName に "Items." を指定してこの関数を呼び出す。
	
		この場合、この関数は pCdConnectedString に、
		『項目名』が "Name" ・『値』が "Untitled" 
		のアイテムを追加します。
	 */
	int getSubitem( const std::string& strSubitemName , 
		CdConnectedString2* pCdConnectedString )const ;
	
	/**
 	this が保持しているアイテムから、サブアイテムを
	(『項目名』がサブアイテム名で始まる項目)を
	削除します。

	 @param strSubitemName [in]
	 	サブアイテム名を指定してください。
	 @return
	 	成功したら削除したアイテムの数を返します( 0 以上)。
		失敗したら負の数です
	 */
	int removeSubitem( const std::string& strSubitemName ) ;
	

	///@}
 public:
	// ********************************
	///@name	CdConnectedString2-演算子
	// ********************************
	///@{
	/** encode() と等価です */
	operator std::string()const {	return encode() ;	};
	///@}
};


} //namespace OuLib{
} //namespace Str{


#endif /*CdConnectedString_h*/

