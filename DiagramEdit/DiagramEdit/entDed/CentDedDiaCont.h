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
//	CentDedDiaCont.h
// ****************************************************************
*/
#ifndef  CentDedDiaCont_h
#define  CentDedDiaCont_h
/** @file */

#include "NsMu/CMuiCopiedParent.h"
#include "CentDedDia.h"

namespace entDed{

//前方参照
class CentDedRosen ;



// ****************************************************************
//	CentDedDiaCont
// ****************************************************************
/**
@brief
  CentDedDia オブジェクトのコンテナクラスです。

このクラス自体は、 Mui< CentDedDia > インターフェースを
サポートします。このインターフェースにより、 CentDedDia オブジェクトを
追加・削除することができます。

また、 getMuPtr() メソッドにより、
Mui< CentDedDia* > インターフェースを取得することができます。
このインターフェースにより、コンテナ内の CentDedDia オブジェクトに
直接アクセス（メソッド呼出）を行うことができます。

	
制約
 -------------------------------- 
○ダイヤコンテナに、同じ名前のダイヤが複数あってはならない。

○ダイヤコンテナに、空文字列のダイヤがあってはならない。



操作のエラー検査・修正
 -------------------------------- 
○ダイヤの追加(insert):同じ名前のダイヤがすでにある場合はエラー。
　空文字列のダイヤの追加はエラー。

○ダイヤの上書き(set):同じ名前のダイヤが既にある場合はエラー。
　空文字列のダイヤの上書きはエラー。


制約に合うように属性を修正(adjust)
 -------------------------------- 
○すべてのCentDedDia(ダイヤ)に、adjust()を委譲する。



*/
class CentDedDiaCont : public CMuiCopiedParent< CentDedDia >
{
	typedef CMuiCopiedParent< CentDedDia >	super ;

public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	コンテナ内の、インデクスで指定された場所に、
	要素を追加します。

	<H4>
	【オーバライド】
	</H4>
	○ダイヤの追加(insert):同じ名前のダイヤがすでにある場合はエラー。
	　空文字列のダイヤの追加はエラー。

	
	@param element [in]
		要素を指定してください。
	@param iIndex [in]
		０から始まるインデクスを指定してください。
		範囲は０以上 size() 以下です。
		０は、先頭・size()なら末尾への追加になります。
		但し、INT_MAX は、末尾を指定したものとみなします。
	@return
		0以上は成功、負の数はエラーです
		-	-1 ;	//	インデクスが不正です。
		-	-2 ;	//	element にはダイヤ名が指定されていません。
		-	-3 ;	//	すでに同名のダイヤが存在します。
	 */
	virtual int insert( const CentDedDia& element , int iIndex = INT_MAX ) ;

	/**
		コンテナ内の、インデクスで指定された場所に、
		要素を上書きします。
	<H4>
	【オーバライド】
	</H4>
	○ダイヤの上書き(set):同じ名前のダイヤが既にある場合はエラー。
	　空文字列のダイヤの上書きはエラー。
	
	@param element [in]
		要素を指定してください。
	@param iIndex [in]
		０から始まるインデクスを指定してください。
		範囲は０以上 size() 未満です。
		但し、INT_MAX は、末尾を指定したものとみなします。
	@return
		0以上は成功、負の数はエラーです
		-	-1 ;	//	iIndex が不正です。
		-	-2 ;	//	element にはダイヤ名が指定されていません。
		-	-3 ;	//	すでに同名のダイヤが存在します。
	*/
	virtual int set( const CentDedDia& element , int iIndex ) ;

	///@}
	

 public:
	// ********************************
	///@name CentDedDiaCont-関連
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
	virtual const CentDedRosen* getRosen()const { return NULL ;}
	
	///@}
	// ********************************
	///@name CentDedDiaCont-操作
	// ********************************
	///@{
	/**
		set() が可能か否かを判断します。

	○ダイヤの上書き(set):同じ名前のダイヤが既にある場合はエラー。
	　空文字列のダイヤの上書きはエラー。


	@param element
		要素を指定してください。 
	@param iIndex
		０から始まるインデクスを指定してください。 範囲は０以上 size() 
		未満です。 但し、INT_MAX は、末尾を指定したものとみなします。 
	@return
		-	0以上: set() が可能。
		-	負の数: set()は、この戻り値で失敗します。
		-	-2 ;	//	element にはダイヤ名が指定されていません。
		-	-3 ;	//	すでに同名のダイヤが存在します。
	 */
	virtual int  setable(  const CentDedDia& element , int iIndex )const ;

	/**
		element がこのコンテナの子である場合は、インデクスを返します。
	@param element
		要素を指定してください。 
	@return
		element がこのコンテナの子である場合は、インデクスを返します。
		そうでない場合は、 -1 です。
	*/
	virtual int  getIndex( const CentDedDia* element )const ;
	/**
		this の属性が制約に反している場合、制約に合うように、属性を
		修正します。

		△このコンテナが CentDedRosen の子オブジェクトである場合、
		m_iEkiCount と m_iRessyasyubetsuCount は、CentDedRosenに合わせます。

		○すべてのCentDedRessya(列車)に、adjust()を委譲する。
	*/
	void adjust() ;

	/**
		指定のダイヤ名を持つ
		『ダイヤ』 ( CentDedDia ) オブジェクトの、
		インデクスを調べます。
	 @param strName [in]
		『ダイヤ名』を指定してください。
	 @return 
		成功したら 0 以上のインデクス、エラーなら負の数です。
		-	-1 ;	//	オブジェクトがみつかりません。
	*/
	int findCentDedDiaByName( const std::string& strName )const ;
	///@}
	// ********************************
	///@name CentDedDiaCont-操作 駅数・列車種別数の変更
	// ********************************
	///@{



	/**
		このコンテナに、指定された『列車種別』の列車があるか否かを調べます。
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
		int* piRessyaIndex ) const;

	///@}
public:
	// ********************************
	///@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
	///@{
	/**
		m_CentDedEkiCont に CentDedEki が追加された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiIndex
		追加された CentDedEki のインデクス。
	*/
	virtual void onEkiInsert( int iEkiIndex ); 
	/**
		m_CentDedEkiCont から CentDedEki が削除された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiIndex
		削除された CentDedEki のインデクス。
	*/
	virtual void onEkiErase( int iEkiIndex  ); 
	/**
		CentDedEkiTrackCont に CentDedEkiTrack が追加された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiIndex
		CentDedEkiTrackCont が追加された CentDedEki の駅Index。
	@param iEkiTrackIndex
		追加された CentDedEkiTrack のインデクス。
	*/
	virtual void onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex ); 
	/**
		CentDedEkiTrackCont から CentDedEkiTrack が削除された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiIndex
		CentDedEkiTrackCont が削除された CentDedEki の駅Index。
	@param iEkiTrackIndex
		削除された CentDedEkiTrack の先頭のインデクス。
	*/
	virtual void onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex ); 

	/**
		CentDedRessyasyubetsuCont に CentDedRessyasyubetsu が追加された直後、
		CentDedRessyasyubetsuCont から呼び出されます。
	@param iRessyasyubetsuIndex
		追加された CentDedRessyasyubetsu  のインデクス。
	*/
	virtual void onRessyasyubetsuInsert( int iRessyasyubetsuIndex ); 

	/**
		CentDedRessyasyubetsuCont から CentDedRessyasyubetsu が削除された直後、
		CentDedRessyasyubetsuCont から呼び出されます。
	@param iRessyasyubetsuIndex
		削除された CentDedRessyasyubetsu  のインデクス。
	*/
	virtual void onRessyasyubetsuErase( int iRessyasyubetsuIndex ); 



	///@}
	
};

} //namespace entDed





#endif /*CentDedDiaCont_h*/
