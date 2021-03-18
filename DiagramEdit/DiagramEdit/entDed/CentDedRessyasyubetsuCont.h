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
//	CentDedRessyasyubetsuCont.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessyasyubetsuCont_h
#define  CentDedRessyasyubetsuCont_h

#include "NsMu/CMuiCopiedParent.h"

#include "CentDed.h"
#include "CentDedRessyasyubetsu.h"

namespace entDed{
	using namespace OuLib::NsMu;


//	前方参照宣言
class CentDedRosen ;

// ****************************************************************
//	CentDedRessyasyubetsuCont
// ****************************************************************
/**
@brief
 『列車種別』( CentDedRessyasyubetsu ) オブジェクトのコンテナです。

  このクラス自体は、 Mui< CentDedRessyasyubetsu > インターフェースを
サポートします。このインターフェースにより、
CentDedRessyasyubetsu オブジェクトを
追加・削除することができます。

  getMuPtr() メソッドにより、 Mu< CentDedRessyasyubetsu* > 
インターフェースを取得することができます。
  このインターフェースを使うと、コンテナ内の CentDedRessyasyubetsu 
オブジェクトに直接アクセスすることができます。
	
@attention
  this の get() メソッドは、 CentDedRessyasyubetsu オブジェクトの
コピーを返します。
  get() メソッドで返されたオブジェクトに対して、
CentDedRessyasyubetsu オブジェクトを更新するメソッドを呼び出しても、
コンテナ内の列車種別オブジェクトを更新することはできません。\n
コンテナ内の列車種別オブジェクトのメソッドを呼び出す場合は、
getMuPtr() で Mu<CentDedRessyasyubetsu*>* を取得してから、
そのインターフェース経由で CentDedRessyasyubetsu* を取得し、そのポインタに
メソッドを呼び出してください。

制約
 -------------------------------- 
△路線の一部である場合は、最低１つの『列車種別』が必要。(これは、路線のコンストラクタで実施)

△コンテナ内の『列車種別』は、長さ1以上の名前を持たなくてはならない

(△)列車の列車種別インデクスは、CentDedRessyasyuebtsu の範囲内でなくてはならない

操作のエラー検査・修正
 -------------------------------- 

rinji
△列車種別の追加(insert):このコンテナが路線の一部である場合、名前が空の列車種別の追加はエラー

(△)列車種別の追加(insert):　列車の列車種別インデクスは、コンテナへの追加に合わせてシフトさせる。

○列車種別の削除(erase):　列車種別が0個になるような削除はエラー

(△)列車種別の削除(erase):　列車の列車種別インデクスは、コンテナへの追加に合わせてシフトさせる。
　列車の列車種別インデクスが削除対象の場合、インデクスは0にする

○番線の上書き(set): nameが空の CentDedRessyasyubetsuを上書きするとエラー。

△コンテナの代入(operator=):コンテナが路線の一部である場合で、右辺の要素数が0の場合は、
インデクス0番の列車種別を追加して、列車種別の数が0にならないようにする


△削除対象の列車種別のインデクスを持つ列車の検索(findRessyaOfRessyasyubetsu):
削除対象の列車種別表す列車種別インデクスを持つ列車オブジェクトを検索する


制約に合うように属性を修正(adjust)
 -------------------------------- 

○すべてのCentDedRessyasyubetsu(列車種別)に、adjust()を委譲する。




 */
class CentDedRessyasyubetsuCont : public CMuiCopiedParent< CentDedRessyasyubetsu >
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	typedef CMuiCopiedParent< CentDedRessyasyubetsu >	super ;

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
	○コンテナの生成(コンストラクタ): インデクス0番の列車種別を設定する。
	*/
	CentDedRessyasyubetsuCont() ;
	
	/**
	△コンテナの代入(operator=):コンテナが路線の一部である場合で、右辺の要素数が0の場合は、
	インデクス0番の列車種別を追加して、列車種別の数が0にならないようにする
	*/
	CentDedRessyasyubetsuCont& operator=( const CentDedRessyasyubetsuCont& value ) ;

public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素を追加します。

	rinji
	△列車種別の追加(insert):このコンテナが路線の一部である場合、名前が空の列車種別の追加はエラー

	(△)列車種別の追加(insert):　列車の列車種別インデクスは、
	コンテナへの追加に合わせてシフトさせる。


	 @param element [in]
	 	要素を指定してください。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 以下です。
	 	０は、先頭・size()なら末尾への追加になります。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	0以上は成功、負の数はエラーです
	*/
	virtual int insert( const CentDedRessyasyubetsu& element , int iIndex = INT_MAX );
	
	/**
	 	コンテナ内の、インデクスで指定された場所の
	 	要素を削除します。

	△列車種別の削除(erase):　列車種別が0個になるような削除はエラー
	
	(△)列車種別の削除(erase):　列車の列車種別インデクスは、
	コンテナへの追加に合わせてシフトさせる。
	  列車の列車種別インデクスが削除対象の場合、インデクスは0にする

	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 未満です。
	 	但し、INT_MAX は、末尾を指定したものとみなします。
	 @param iSize [in]
	 	削除する要素の数を指定してください。
	 	但し、INT_MAX は、 iIndex から末尾までを表します。
	 @attention
		iIndex と iSize の両方を INT_MAX にすることはできません。
	 @return
	 	0以上は成功、負の数はエラーです
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) ;
	
	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素を上書きします。

	○番線の上書き(set): nameが空の CentDedRessyasyubetsuを上書きするとエラー。
		
	@param element [in]
	 	要素を指定してください。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 未満です。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	0以上は成功、負の数はエラーです
		-	-11; //○番線の上書き(set): nameが空の CentDedRessyasyubetsuを上書きするとエラー。
	*/
	virtual int set( const CentDedRessyasyubetsu& element , int iIndex ) ;
	///@}

 public:
	// ********************************
	///@name CentDedRessyasyubetsuCont-関連
	// ********************************
	///@{
	/**
	@return
		このコンテナが CentDedRosen に包含されている場合は、
		CentDedRosen のアドレス。
		そうでないならNULL。
	*/
	 virtual CentDedRosen* getRosen(){ return NULL ;}
	/**
	@return
		このコンテナが CentDedRosen に包含されている場合は、
		CentDedRosen のアドレス。
		そうでないならNULL。
	*/
	virtual const CentDedRosen* getRosen()const{ return NULL ;}
	///@}
 public:
	// ********************************
	///@name CentDedRessyasyubetsuCont-操作
	// ********************************
	///@{

	/**
		set() が可能か否かを判断します。

	○番線の上書き(set): nameが空の CentDedRessyasyubetsuを上書きするとエラー。
	
	@param element
		要素を指定してください。 
	@param iIndex
		０から始まるインデクスを指定してください。 範囲は０以上 size() 
		未満です。 但し、INT_MAX は、末尾を指定したものとみなします。 
	@return
		-	0以上: set() が可能。
		-	負の数: set()は、この戻り値で失敗します。
		-	-11; //○番線の上書き(set): nameが空の CentDedRessyasyubetsuを上書きするとエラー。
	 */
	virtual int  setable(  const CentDedRessyasyubetsu& element , int iIndex )const ;

	/**
		element がこのコンテナの子である場合は、インデクスを返します。
	@param element
		要素を指定してください。 
	@return
		element がこのコンテナの子である場合は、インデクスを返します。
		そうでない場合は、 -1 です。
	*/
	virtual int  getIndex( const CentDedRessyasyubetsu* element )const ;

	/**
	  Rosen に、指定された『列車種別』の列車があるか否かを調べます。
	@param iRessyasyubetsuIndex [in]
		『列車種別Index』を指定してください。
		範囲は、 0 以上 列車種別の数未満です。
		INT_MAX は、末尾の列車種別を指定したものとみなします。
	 @param piDiaIndex [out]
		この関数はこの変数に、『列車種別』の列車が見つかった
		ダイヤのインデクスを書き込みます。
		不要なら NULL でもかまいません。
	@param peRessyahoukou [out]
		この関数はこの変数に、『列車種別』の列車が見つかった
		ダイヤの列車方向を書き込みます。
		不要なら NULL でもかまいません。
	@param piRessyaIndex [out]
		この関数はこの変数に、『列車種別』の列車が見つかった
		列車Index を書き込みます。
		不要なら NULL でもかまいません。
	@return 
		-	1; //	指定の列車種別の列車が存在します。
		-	0; //	指定の列車種別の列車は存在しません。
		-	-1 ;	//	インデクスが不正
	 */
	int isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piDiaIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const ;
	///@}
};


} //namespace entDed

#endif /*CentDedRessyasyubetsuCont_h*/
