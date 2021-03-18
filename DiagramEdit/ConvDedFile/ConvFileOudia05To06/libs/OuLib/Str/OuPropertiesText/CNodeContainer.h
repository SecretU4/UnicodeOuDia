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
/** @file */
//$Id: CNodeContainer.h 10 2012-08-26 09:48:47Z okm $
#pragma once
#include <deque>
#include "Cont\IfCont.h"
#include "str\OuPropertiesText\CNode.h"
#include "str\OuPropertiesText\CPropertyString.h"
#include "str\OuPropertiesText\CInNameIndexContainer.h"
#include "str\OuPropertiesText\IfNodeContainerConst.h"

/**
@brief
  OuPropertiesText を扱うクラス群を集約しています。

*/
namespace OuPropertiesText{


// ****************************************************************
//	CNodeContainer
// ****************************************************************
/**
@brief
	Node オブジェクトを保持するコンテナです。

	コンテナに Ou<CNode> を格納するすべてのpublicメソッド
	(set()・insert() など)は、
	引数で渡された CNode の clone を格納します。
	コンテナ内の Ou<CNode> を取得するすべてのメソッドは、
	コンテナ内の CNode への参照を返します。
*/
class CNodeContainer : public IfCont< Ou<CNode> >
{
public:
	typedef Ou<CNode>	ElementType ;
	typedef std::deque< Ou<CNode> >	ElementTypeStlCont ;
private:
	// ----------------------------------------------------------------
	//	CNodeContainer::CaConst
	// ----------------------------------------------------------------
	/**
		CNodeContainer に対して、
		IfNodeContainerConst インターフェースを介して
		アクセスするためのアダプタクラスです。
		
		CNodeContainer は、このアダプタを集約しており、
		getIfNodeContainerConst() メソッドで、
		このアダプタへのポインタを返します。
	*/
	class CaConst : public IfNodeContainerConst 
	{
	public:
		// ********************************
		///@name	IfNodeContainerConst-Propertyの取得
		// ********************************
		///@{
		/**
			Property の Name に対応する Value を取得します。
		@param strName [in]
			Property の Name を指定してください。
		@return
			対応するValueを返します。

			Nameに対応する Property が見つからない場合は、
			空文字列を返します。

			Name に対応する 2個以上のCPropertyString インスタンスが存在
			する場合は、InNameIndex が最も小さい CPropertyString の Value 
			を返します。
		*/
		virtual string getValue( const string& strName )const ;
		///@}

	public:
		// ********************************
		///@name	IfContGet
		// ********************************
		///@{
		
		/**
		 * @return
		 * 	コンテナに格納されている要素の個数を返します。
		 */
		virtual int	size()const ;
		/**
		 * 	コンテナ内の、インデクスで指定された場所に格納されている
		 * 	要素を返します。
		 *
		 * @param iIndex [in]
		 * 	０から始まるインデクスを指定してください。
		 * 	範囲は０以上 size() 未満です。
		 *	但し、INT_MAX は、末尾を指定したものとみなします。
		 * @return
		 * 	インデクスで指定された要素を返します。
		 */
		virtual Ou<const CNode> get( int iIndex )const ;
		
		///@}
		
	public:
		// ********************************
		///@name	CNodeContainer-InNameIndexでのアクセス
		// ********************************
		///@{
		
		/**
	 		指定の Name を持つ要素の個数を返します。
		 @param strName [in]
			Name を指定してください。
		 @return
	 		要素の個数を返します。
		*/
		virtual int	sizeInName( const string& strName )const ;
		/**
	 		コンテナ内の、指定の Name を持つ要素を返します。
		 @param strName [in]
			Name を指定してください。
		 @param iInNameIndex [in]
	 		InNameIndex を指定してください。
			InNameIndex は、このコンテナ内の同じ Name を持つ Node 内での、
			０から始まるインデクスです。
			範囲は０以上 sizeInName() 未満です。
			但し、INT_MAX は、末尾を指定したものとみなします。
		 @return
	 		インデクスで指定された要素を返します。
		*/
		virtual Ou<const CNode> getInName( const string& strName , int iInNameIndex )const ;
		
		

		/**
			InNameIndex をコンテナのインデクスに変換します。
		@param strName [in]
			Name を指定してください。
		@param iInNameIndex [in]
	 		０から始まるインデクスを指定してください。
	 		範囲は０以上 sizeInName() 未満です。
	 		但し、INT_MAX は、末尾を指定したものとみなします。
		@return
			インデクス を返します。
			-	-1 ;	//	インデクスが不正です。
		*/
		virtual int indexOfInNameIndex( 
			const string& strName ,
			int iInNameIndex )const ;
		/**
			コンテナのインデクスを、InNameIndex に変換します。
		@param iIndex [in]
	 		０から始まるインデクスを指定してください。
	 		範囲は０以上 size() 未満です。
	 		但し、INT_MAX は、末尾を指定したものとみなします。
		@return
			InNameIndex を返します。
		*/
		virtual int indexToInNameIndex( 
			int iIndex )const ;

		///@}
	};
	friend class CaConst ;

private:
	// ********************************
	///@name	集約
	// ********************************
	///@{
	/**
		Ou<CNode>[ index ] の形式で、ノードを保持します。
	*/
	ElementTypeStlCont	m_contCNode ;

	/**
		CNodeContainer に対して、
		IfNodeContainerConst インターフェースを介して
		アクセスするためのアダプタクラスです。
		
		CNodeContainer は、このアダプタを集約しており、
		getIfNodeContainerConst() メソッドで、
		このアダプタへのポインタを返します。
	*/
	CaConst	m_CaConst ;
	///@}

	// --------------------------------
	///@name	内部データ
	// --------------------------------
	///@{
	/**
		index[ Name ][InNameIndex ] の形式で、
		Index と InNameIndex の対照表を保持します。
	*/
	CInNameIndexContainer	m_CInNameIndexContainer;
	///@}
	
private:
	// --------------------------------
	///@name	下請関数
	// --------------------------------
	///@{
	/**
		Property の Name に対応する CPropertyString があれば、
		その要素へのポインタを取得することができます。
		このオブジェクトの属性を変更することにより、
		コンテナ内の Property を変更することができます。
	@param strName [in]
		Property の Name を指定してください。
	@return
		対応する CPropertyString への参照を返します。

		Nameに対応する Property が見つからない場合は、
		NULLを返します。

		Name に対応する 2個以上のCPropertyString インスタンスが存在
		する場合は、InNameIndex が最も小さい CPropertyString の CPropertyString 
		を返します。
	*/
	Ou<CPropertyString> getCPropertyString( const string& strName )const ;
	///@}
	
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CNodeContainer();
	virtual ~CNodeContainer();
	/**
		value が集約する全ての Node の
		コピーを作成し、それを集約します。
		value とオブジェクトを共有することはありません。
	*/
	CNodeContainer( const CNodeContainer& value );
	/**
		value が集約する全ての Node の
		コピーを作成し、それを集約します。
		value とオブジェクトを共有することはありません。
	*/
	CNodeContainer& operator=( const CNodeContainer& value );
public:
	// ********************************
	///@name	集約
	// ********************************
	///@{
	/**
	@return
		Node オブジェクトを保持するコンテナを参照するインターフェースです。\n
		このインターフェースからは、CNodeContainer 内の全てのノードに対する
		Ou<const CNode> を取得することができますが、
		ノードの追加・変更・削除はできません。
	*/
	virtual const IfNodeContainerConst* getIfNodeContainerConst()const ;
	///@}
public:
	// ********************************
	///@name	CNodeContainer-Propertyの取得･設定
	// ********************************
	///@{
	/**
		Property の Name と Value を設定します。
	@param strName [in]
		Property の Name を指定してください。
	@param strValue [in]
		Property の Value を指定してください。

		Name に対応する Property (CPropertyString) が
		this のコンテナ内に存在しない場合は、
		CPropertyString オブジェクトをコンテナに新規追加します。

		Name に対応する CPropertyString が存在している場合は、その
		CPropertyStroing オブジェクトの Value を上書きします。
		同じ名前を持つ2個以上のCPropertyString インスタンスが存在
		する場合は、InNameIndex が最も小さい CPropertyString の Value 
		を上書きます。
	*/
	virtual void setValue( const string& strName , 
		const string& strValue ) ;

	/**
		Property の Name に対応する Value を取得します。
	@param strName [in]
		Property の Name を指定してください。
	@return
		対応するValueを返します。

		Nameに対応する Property が見つからない場合は、
		空文字列を返します。

		Name に対応する 2個以上のCPropertyString インスタンスが存在
		する場合は、InNameIndex が最も小さい CPropertyString の Value 
		を返します。
	*/
	virtual string getValue( const string& strName )const ;
	///@}

public:
	// ********************************
	///@name	IfContGet
	// ********************************
	///@{
	
	/**
	 * @return
	 * 	コンテナに格納されている要素の個数を返します。
	 */
	virtual int	size()const ;
	/**
	 * 	コンテナ内の、インデクスで指定された場所に格納されている
	 * 	要素を返します。
	 *
	 * @param iIndex [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 未満です。
	 *	但し、INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	インデクスで指定された要素を返します。
	 */
	virtual ElementType get( int iIndex )const ;
	
	///@}
public:
	// ********************************
	///@name	IfCont
	// ********************************
	///@{
	
	/**
	 * 	コンテナ内の、インデクスで指定された場所に、
	 * 	要素を上書きします。
	 * @param element [in]
	 * 	要素を指定してください。
	 * @param iIndex [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 未満です。
	 *	但し、INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	0以上は成功、負の数はエラーです
	 */
	virtual int set( const ElementType& element , int iIndex ) ;

	/**
	 * 	コンテナ内の、インデクスで指定された場所に、
	 * 	要素を追加します。
	 * @param element [in]
	 * 	要素を指定してください。
	 * @param iIndex [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 以下です。
	 * 	０は、先頭・size()なら末尾への追加になります。
	 *	但し、INT_MAX は、末尾を指定したものとみなします。
	 * @return
	 * 	0以上は成功、負の数はエラーです
	 */
	virtual int insert( const ElementType& element , int iIndex = INT_MAX ) ;
	
	/**
	 * 	コンテナ内の、インデクスで指定された場所の
	 * 	要素を削除します。
	 * @param iIndex [in]
	 * 	０から始まるインデクスを指定してください。
	 * 	範囲は０以上 size() 未満です。
	 * 	但し、INT_MAX は、末尾を指定したものとみなします。
	 * @param iSize [in]
	 * 	削除する要素の数を指定してください。
	 * 	但し、INT_MAX は、 iIndex から末尾までを表します。
	 * @attention
	 *	iIndex と iSize の両方を INT_MAX にすることはできません。
	 * @return
	 * 	0以上は成功、負の数はエラーです
	 */
	virtual int erase( int iIndex  , int iSize = 1 ) ;
	
	///@}
public:
	// ********************************
	///@name	CNodeContainer-InNameIndexでのアクセス
	// ********************************
	///@{
	
	/**
	 	指定の Name を持つ要素の個数を返します。
	 @param strName [in]
		Name を指定してください。
	 @return
	 	要素の個数を返します。
	*/
	virtual int	sizeInName( const string& strName )const ;
	/**
	 	コンテナ内の、指定の Name を持つ要素を返します。
	 @param strName [in]
		Name を指定してください。
	 @param iInNameIndex [in]
	 	InNameIndex を指定してください。
		InNameIndex は、このコンテナ内の同じ Name を持つ Node 内での、
		０から始まるインデクスです。
		範囲は０以上 sizeInName() 未満です。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	インデクスで指定された要素を返します。
	*/
	virtual ElementType getInName( const string& strName , int iInNameIndex )const ;
	
	
	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素を上書きします。
	@param element [in]
	 	要素を指定してください。
	@param iInNameIndex [in]
	 	０から始まるInNameIndexを指定してください。
	 	範囲は０以上 size() 未満です。
		但し、INT_MAX は、末尾を指定したものとみなします。
	@return
	 	0以上は成功、負の数はエラーです
	*/
	virtual int setInName( 
		const ElementType& element , 
		int iInNameIndex ) ;

	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素を追加します。
	@param element [in]
	 	要素を指定してください。
	@param iInNameIndex [in]
	 	０から始まるInNameIndexを指定してください。
	 	範囲は０以上 sizeInName() 以下です。
	 	０は、先頭・sizeInName()なら末尾への追加になります。
		但し、INT_MAX は、末尾を指定したものとみなします。
	@return
	 	0以上は成功、負の数はエラーです
	*/
	virtual int insertInName( 
		const ElementType& element , 
		int iInNameIndex = INT_MAX ) ;
	
	/**
	 	コンテナ内の、インデクスで指定された場所の
	 	要素を削除します。
	@param strName [in]
		Name を指定してください。
	@param iInNameIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 sizeInName() 未満です。
	 	但し、INT_MAX は、末尾を指定したものとみなします。
	@param iSize [in]
	 	削除する要素の数を指定してください。
	 	但し、INT_MAX は、 iIndex から末尾までを表します。
	@attention
		iIndex と iSize の両方を INT_MAX にすることはできません。
	@return
	 	0以上は成功、負の数はエラーです
	*/
	virtual int eraseInName( const string& strName , 
		int  iInNameIndex  , int iSize = 1 ) ;
	/**
		InNameIndex をコンテナのインデクスに変換します。
	@param strName [in]
		Name を指定してください。
	@param iInNameIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 sizeInName() 未満です。
	 	但し、INT_MAX は、末尾を指定したものとみなします。
	@return
		インデクス を返します。
		-	-1 ;	//	インデクスが不正です。
	*/
	virtual int indexOfInNameIndex( 
		const string& strName ,
		int iInNameIndex )const ;
	/**
		コンテナのインデクスを、InNameIndex に変換します。
	@param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 未満です。
	 	但し、INT_MAX は、末尾を指定したものとみなします。
	@return
		InNameIndex を返します。
	*/
	virtual int indexToInNameIndex( 
		int iIndex )const ;

	///@}
	
};


};	//namespace OuPropertiesText
