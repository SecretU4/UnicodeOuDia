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
//$Id: CentDedEkiTrackCont.h 378 2016-11-16 21:10:54Z okm $

#ifndef  entDed_CentDedEkiTrackCont_h
#define  entDed_CentDedEkiTrackCont_h

#include "NsMu\CMuiCopiedParent.h"
#include "CentDedEkiTrack.h"
#include "CentDed.h"


namespace entDed{

//	前方参照
class CentDedEki ;
class CentDedRosen ;

/**
@brief
  駅の『番線』のコンテナです。
  
  このコンテナが CentDedEki の子オブジェクトで、
その CentDedEki が CentDedRosen に包含されている場合、 insert() 
メソッドは、CentDedRosen::onEkiTrackInsert( iEkiIndex , iEkiTrackIndex ) 
に処理を委譲します。erase() も同様です。
  

制約
 -------------------------------- 

○常に『上り本線』・『下り本線』が１つずつ必要。

○『上り本線』・『下り本線』の追加・削除は禁止。

(△)駅時刻入線オブジェクトの番線指定子がインデクスの場合、インデクスは CentDedEkiTrackCont の範囲内でなくてはならない。


操作のエラー検査・修正
 -------------------------------- 

○コンテナの生成(コンストラクタ): 『上り本線』『下り本線』を設定する。

○番線の追加(insert):『本線』の追加はエラー

(△)番線の追加(insert):駅時刻入線オブジェクトの番線指定子の指定方式がインデクスの場合、インデクスは、コンテナへの追加に合わせてシフトさせる。

○番線の削除(erase):『本線』の削除はエラー

(△)番線の削除(erase):駅時刻入線オブジェクトの番線指定子の指定方式がインデクスの場合、インデクスは、コンテナへの追加に合わせてシフトさせる。
　駅時刻入線オブジェクトの番線指定子の指定方式がインデクスで、そのインデクスが削除対象のものである場合、『本線』に変更する

○番線の上書き(set): 番線種別の異なる CentDedEkiTrack を上書きするとエラー

○コンテナの代入(operator=):insert,erase,setを使用して、本線の追加禁止・削除禁止・上書き禁止の制約を避ける

△削除対象の番線のインデクスを持つ駅時刻入線の検索(findRessyaOfEkiTrack):削除対象の番線を表す番線インデクスを持つ駅時刻入線オブジェクトを検索する

制約に合うように属性を修正(adjust)
 -------------------------------- 

○すべてのCentDedEkiTrack(番線)に、adjust()を委譲する。


*/
class CentDedEkiTrackCont : public CMuiCopiedParent<CentDedEkiTrack>
{
	typedef  CMuiCopiedParent<CentDedEkiTrack>	super ;
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/**
		CentDedEki に包含されない、CentDedEkiTrackCont を生成します。
		CentDedEkiTrack は、上り本線と下り本線の２つからなります。

		○コンテナの生成(コンストラクタ): 『上り本線』『下り本線』を設定する。
	*/
	CentDedEkiTrackCont() ;
	
	/** 
	@todo
		代入は、個別の insert(),erase()に変更します。 
	*/
	CentDedEkiTrackCont& operator=( const CentDedEkiTrackCont& value );

public:
	// ********************************
	///@name Mui
	// ********************************
	///@{

	/**
		番線オブジェクトを追加します。
		但し、本線を追加することはできません。
	@param element
		要素を指定してください。 
	@param iIndex
		0 から始まるインデクスを指定してください。 
		範囲は０以上 size() 以下です。 ０は、先頭・size()なら末尾への
		追加になります。 但し、INT_MAX は、末尾を指定したものとみなします。 
	@return
		0以上は成功、負の数はエラーです。
		-	-1 ;	//	インデクスが範囲外です。
		-	-11 ;	//	本線を追加することは出来ません。

	*/
	virtual int insert( const CentDedEkiTrack& element ,  int iIndex=INT_MAX) ;
	/**
	 	番線オブジェクトを削除します。
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
		-	-1 ;	//	インデクスが範囲外です。
		-	-11 ;	//	本線を削除することは出来ません。
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) ;

	/**
		コンテナ内の、インデクスで指定された場所に、 要素を上書きします。 
		上書き後の要素の CChildItem::m_pParent には、this を登録します。

		番線種別の異なるオブジェクトを上書きすることはできません。		

	@param element
		要素を指定してください。 
	@param iIndex
		０から始まるインデクスを指定してください。 範囲は０以上 size() 
		未満です。 但し、INT_MAX は、末尾を指定したものとみなします。 
	@return
		成功したら0以上、エラーなら負の数です。
		-	-11 ;	//	番線種別の異なるオブジェクトを上書きすることはできません。
	*/
	virtual int set( const CentDedEkiTrack& element , int iIndex ) ;
	///@}

public:
	// ********************************
	///@name CentDedEkiTrackCont-関連
	// ********************************
	///@{
	/**
	@return
		このコンテナが CentDedEki に包含されている場合は、
		CentDedEki のアドレス。
		そうでないならNULL。
	*/
	virtual CentDedEki* getEki(){ return NULL ;}
	/**
	@return
		このコンテナが CentDedEki に包含されている場合は、
		CentDedEki のアドレス。
		そうでないならNULL。
	*/
	virtual const CentDedEki* getEki()const{ return NULL ;}

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
	///@name CentDedEkiTrackCont-操作
	// ********************************
	///@{
	/**
		set() が可能か否かを判断します。

		番線種別の異なるオブジェクトを上書きすることはできません。		
	@param element
		要素を指定してください。 
	@param iIndex
		０から始まるインデクスを指定してください。 範囲は０以上 size() 
		未満です。 但し、INT_MAX は、末尾を指定したものとみなします。 
	@return
		-	0以上: set() が可能。
		-	負の数: set()は、この戻り値で失敗します。
		-	-11 ;	//	番線種別の異なるオブジェクトを上書きすることはできません。
	 */
	virtual int  setable(  const CentDedEkiTrack& element , int iIndex )const ;

	/**
		element がこのコンテナの子である場合は、インデクスを返します。
	@param element
		要素を指定してください。 
	@return
		element がこのコンテナの子である場合は、インデクスを返します。
		そうでない場合は、 -1 です。
	*/
	virtual int  getIndex( const CentDedEkiTrack* element )const ;

	/**
		this の属性が制約に反している場合、制約に合うように、属性を
		修正します。

	○すべてのCentDedEkiTrack(番線)に、adjust()を委譲する。

	*/
	void adjust() ;


	/**
		この番線インデクスを持つ列車を検索します。

	@param index 
		番線のインデクスを指定してください。
	@param piDiaIndex [out]
		この番線を持つ列車がある場合、関数はダイヤindex を書き込みます。
	@param pRessyahoukou [out]
		この番線を持つ列車がある場合、関数は列車方向を書き込みます。
	@param piRessyaIndex [out]
		この番線を持つ列車がある場合、関数は列車 Index を書き込みます。
	@return
		-	1: この番線を持つ列車があります。
		-	0: この番線を持つ列車がありません。
	*/
	
	int findRessyaOfEkiTrack( 
		int index , 
		int* piDiaIndex , 
		ERessyahoukou* pRessyahoukou , int* piRessyaIndex )const ;

};

} //namespace entDed


#endif //entDed_CentDedEkiTrackCont_h



