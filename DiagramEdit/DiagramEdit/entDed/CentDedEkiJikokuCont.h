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
//$Id: CentDedEkiJikokuCont.h 378 2016-11-16 21:10:54Z okm $
/** @file */
#ifndef  entDed_CentDedEkiJikokuCont_h
#define  entDed_CentDedEkiJikokuCont_h

#include "NsMu\CMuiCopiedParent.h"
#include "CentDedEkiJikoku.h"

namespace entDed{

//	前方参照宣言
class CentDedRessya ;
class CentDedEkiJikoku ;
	

/**
@brief
  『駅時刻』オブジェクトのコンテナです。


制約
 -------------------------------- 

△列車が路線の一部である場合、要素数は駅の数に一致していなくてはならない

操作のエラー検査・修正
 -------------------------------- 

△operator=: this が路線の一部である場合は、駅時刻の数は変更しません

△駅時刻の追加(insert)：　列車が路線の一部である場合はエラー。

△駅時刻の削除(erase):　列車が路線の一部である場合はエラー。


△駅の追加(OnInsertEki):　列車の駅時刻は、駅の追加に合わせてシフトさせる。

△駅の削除(OnEraseEki):　列車の駅時刻は、駅の削除に合わせてシフトさせる。



制約に合うように属性を修正(adjust)
 -------------------------------- 

△駅時刻(CentDedEkiJikoku)の要素数が駅コンテナ(CentDedEkiCont)と異なる場合は、駅時刻を追加・削除します。

○CentDedEkiJikoku(駅時刻)に、adjust()を委譲します。


*/
class CentDedEkiJikokuCont : public CMuiCopiedParent< CentDedEkiJikoku >
{
public:
	typedef  public CMuiCopiedParent< CentDedEkiJikoku > super ;
	
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
		要素数0で初期化します。
	*/
	CentDedEkiJikokuCont() ;

	/**
	△operator=: this が路線の一部である場合は、駅時刻の数は変更しません
	*/
	CentDedEkiJikokuCont& operator=( const CentDedEkiJikokuCont& value ) ;

public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素を追加します。

		△駅時刻の追加(insert)：　列車が路線の一部である場合はエラー。

	 @param element [in]
	 	要素を指定してください。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 以下です。
	 	０は、先頭・size()なら末尾への追加になります。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	0以上は成功、負の数はエラーです
		-	-11 ;	//	列車が路線の一部である場合、駅時刻の追加はできません。
	*/
	virtual int insert( const CentDedEkiJikoku& element , int iIndex = INT_MAX );
	
	/**
	 	コンテナ内の、インデクスで指定された場所の
	 	要素を削除します。

		△駅時刻の削除(erase):　列車が路線の一部である場合はエラー。

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
		-	-11 ;	//	列車が路線の一部である場合、駅時刻の削除はできません。
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) ;
	
	/**
	 	コンテナ内の、インデクスで指定された場所に、
	 	要素を上書きします。

	@param element [in]
	 	要素を指定してください。
	 @param iIndex [in]
	 	０から始まるインデクスを指定してください。
	 	範囲は０以上 size() 未満です。
		但し、INT_MAX は、末尾を指定したものとみなします。
	 @return
	 	0以上は成功、負の数はエラーです
		-	-11; //番線指定子が『番線コンテナ』CentDedEkiTrackCont の要素に対応していません
	*/
	virtual int set( const CentDedEkiJikoku& element , int iIndex ) ;
	///@}

 public:
	// ********************************
	///@name CentDedEkiJikokuCont-関連
	// ********************************
	///@{
	/**
	@return
		このコンテナが CentDedRessya に包含されている場合は、
		CentDedRessya のアドレス。
		そうでないならNULL。
	*/
	 virtual CentDedRessya* getRessya(){ return NULL ;}
	/**
	@return
		このコンテナが CentDedRessya に包含されている場合は、
		CentDedRessya のアドレス。
		そうでないならNULL。
	*/
	virtual const CentDedRessya* getRessya()const{ return NULL ;}

	/**
	@return
		このコンテナが CentDedRosen に包含されている場合は、
		CentDedRosen のアドレス。
		そうでないならNULL。
	*/
	CentDedRosen* getRosen() ;
	/**
	@return
		このコンテナが CentDedRosen に包含されている場合は、
		CentDedRosen のアドレス。
		そうでないならNULL。
	*/
	const CentDedRosen* getRosen()const ;
	///@}
public:
	// ********************************
	///@name CentDedEkiJikokuCont-操作
	// ********************************
	///@{

	/**
		set() が可能か否かを判断します。
		このクラスでは、常に0を返します。

	@param element
		要素を指定してください。 
	@param iIndex
		０から始まるインデクスを指定してください。 範囲は０以上 size() 
		未満です。 但し、INT_MAX は、末尾を指定したものとみなします。 
	@return
		-	0以上: set() が可能。
		-	負の数: set()は、この戻り値で失敗します。
	 */
	virtual int  setable(  const CentDedEkiJikoku& element , int iIndex )const ;

	/**
		element がこのコンテナの子である場合は、インデクスを返します。
	@param element
		要素を指定してください。 
	@return
		element がこのコンテナの子である場合は、インデクスを返します。
		そうでない場合は、 -1 です。
	*/
	virtual int  getIndex( const CentDedEkiJikoku* element )const ;
	/**
		this の属性が制約に反している場合、制約に合うように、属性を
		修正します。


		△駅時刻(CentDedEkiJikoku)の要素数が駅コンテナ(CentDedEkiCont)と異なる場合は、駅時刻を追加・削除します。

		○CentDedEkiJikoku(駅時刻)に、adjust()を委譲します。


	*/
	void adjust() ;
	///@}
public:
	// ********************************
	///@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
	///@{
	/**
		m_CentDedEkiCont に CentDedEki が追加された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiOrder
		追加された CentDedEki の駅Order(駅インデクスではありません)。
	*/
	virtual void onEkiInsert( int iEkiOrder );

	/**
		m_CentDedEkiCont から CentDedEki が削除された直後、
		m_CentDedEkiCont から呼び出されます。
	@param iEkiOrder
		削除された CentDedEki の駅Order(駅インデクスではありません)。
	*/
	virtual void onEkiErase( int iEkiOrder  ); 
	/**
		CentDedEkiTrackCont に CentDedEkiTrack が追加された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiOrder
		CentDedEkiTrackCont が追加された CentDedEki の駅Order(駅インデクスではありません)。
	@param iEkiTrackIndex
		追加された CentDedEkiTrack のインデクス。
	*/
	virtual void onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex ); 
	/**
		CentDedEkiTrackCont から CentDedEkiTrack が削除された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiOrder
		CentDedEkiTrackCont が削除された CentDedEki の駅Order(駅インデクスではありません)。
	@param iEkiTrackIndex
		削除された CentDedEkiTrack の先頭のインデクス。
	*/
	virtual void onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex ); 

	///@}

};

} //namespace entDed


#endif //entDed_CentDedEkiJikokuCont_h
