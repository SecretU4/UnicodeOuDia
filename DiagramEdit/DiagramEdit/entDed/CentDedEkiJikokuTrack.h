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
//$Id: CentDedEkiJikokuTrack.h 378 2016-11-16 21:10:54Z okm $
#ifndef  entDed_CentDedEkiJikokuTrack_h
#define  entDed_CentDedEkiJikokuTrack_h

#include "NsMu\CChildBase.h"
#include "CdDedJikoku.h"
#include "CentDedEkiTrackSelector.h"

namespace entDed{
	using namespace OuLib::NsMu ;
	using namespace std ;
/**
@brief
  『入線』を表します。
  
  この値は、ダイヤグラムビューでは、駅の在線を示す水平の列車線の描画に使われます。
  
  属性として、入線時刻(CentDedEkiJikoku)・発着番線(CentDedEkiTrackSelector)
を持ちます。

  既定値では、入線時刻・発着番線ともNULLです。

  発着番線がNULLの場合、ダイヤグラムの在線線は本線に描画されます。
  
  入線時刻がNULLの場合、入線時刻=着時刻とみなします。始発駅で入線時刻=NULLの場合、在線線は描画されません。

制約
 -------------------------------- 
△番線指定子がインデクスの場合、そのインデクスは、駅の番線コンテナ
(CentDedEkiTrackCont)に対応していなくてはなりません。

△CentDedEkiJikokuTrack が『駅時刻』の一部である場合で、
　駅扱が『運行なし』または『経由なし』の場合、着時刻・発時刻はNULL。
　入線は、番線Index・入線時刻ともにNULL。

操作のエラー検査・修正
 -------------------------------- 

△番線の追加(OnInsertEkiTrack):駅時刻入線オブジェクトの番線指定子の指定
方式がインデクスの場合、インデクスは、コンテナへの追加に合わせてシフトさせる。

△番線の削除(OnEraseEkiTrack):駅時刻入線オブジェクトの番線指定子の指定方式
がインデクスの場合、インデクスは、コンテナへの削除に合わせてシフトさせる。
　駅時刻入線オブジェクトの番線指定子の指定方式がインデクスで、その
 インデクスが削除対象のものである場合、『指定なし』に変更する

△setNyusenJikoku:CentDedEkiJikokuTrack が『駅時刻』の一部である場合で、
　駅扱が『運行なし』または『経由なし』の場合、NULL以外の時刻の設定はエラー(例外)

△setEkiTrack: CentDedEkiJikokuTrack が路線(CentDedRosen)の一部である
場合で、番線指定子が『番線コンテナ』CentDedEkiTrackCont の要素に対応して
いない場合はエラー。(例外スロー)

△setEkiTrack:CentDedEkiJikokuTrack が『駅時刻』の一部である場合で、
　駅扱が『運行なし』または『経由なし』の場合、NULL以外の番線の設定はエラー(例外)


△operator= : CentDedEkiJikokuTrackCont::set()が失敗するような代入はエラー

 
 制約に合うように属性を修正(adjust)
 -------------------------------- 

△CentDedEkiJikokuTrack が路線(CentDedRosen)の一部である場合で、番線指定子が
『番線コンテナ』CentDedEkiTrackCont の要素に対応していない場合は、
『指定なし』に変更する

△CentDedEkiJikokuTrack が『駅時刻』の一部である場合で、
　駅扱が『運行なし』または『経由なし』の場合、着時刻・発時刻はNULL。
　入線は、番線Index・入線時刻ともにNULLを設定する。

 
*/
class CentDedEkiJikokuTrack : public CChildBase
{
	typedef CChildBase	super ;
public:
	/**
		以下の場合にスローされます。

		CentDedEkiJikokuTrack が『駅時刻』の一部である場合で、
　		駅扱が『運行なし』または『経由なし』の場合に、NULL以外の時刻・番線Indexを指定

		番線指定子がインデクスの場合で、そのインデクスが、駅の番線コンテナ
		(CentDedEkiTrackCont)に対応していない場合
	*/
	class LException
	{
	};
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
	  入線時刻
	*/
	CdDedJikoku m_NyusenJikoku ;
	
	/**
	  発着番線
	*/
	CentDedEkiTrackSelector m_Track ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	///@{
	/** 
	  デフォルトコンストラクタは、
	  入線時刻・発着番線ともにNULLに初期化します。 
	*/
	CentDedEkiJikokuTrack(); 
	/**
	@param nyusenJikoku
	  入線時刻
	@param track
	  発着番線
	*/
	CentDedEkiJikokuTrack( 
		CdDedJikoku nyusenJikoku ,
		CentDedEkiTrackSelector track ); 
	/** 
	△operator= : CentDedEkiJikokuTrackCont::set()が失敗するような代入はエラー
	
	@exception LException 
	*/
	CentDedEkiJikokuTrack& operator=( const CentDedEkiJikokuTrack& value ) ;
public:
	// ********************************
	///@name CParentBase-操作
	// ********************************
	///@{
	virtual void setParent( CParentBase* pParent );
	///@}

public:
	// ********************************
	///@name CentDedEkiJikokuTrack-属性
	// ********************************
	///@{
	/**@see m_NyusenJikoku */
	CdDedJikoku getNyusenJikoku()const;
	/**@see m_NyusenJikoku */
	void setNyusenJikoku( const CdDedJikoku value );
	
	/**@see m_Track */
	CentDedEkiTrackSelector getTrack()const;
	/**
	@see m_Track 
	@exception LException
		 CentDedEkiJikokuTrack が路線(CentDedRosen)の一部である
		場合で、番線指定子が『番線コンテナ』CentDedEkiTrackCont の要素に対応して
		いない場合はエラー。(例外スロー)
	*/
	void setTrack( const CentDedEkiTrackSelector& value );
	///@}

public:
	// ********************************
	///@name CentDedEkiJikokuTrack-操作
	// ********************************
	///@{
	/**
		this の属性が制約に反している場合、制約に合うように、属性を
		修正します。


	△CentDedEkiJikokuTrack が路線(CentDedRosen)の一部である場合で、
	番線指定子が『番線コンテナ』CentDedEkiTrackCont の要素に
	対応していない場合は、『指定なし』に変更する
	*/
	void adjust() ;
	
	///@}
public:
	// ********************************
	///@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
	///@{
	/**
		CentDedEkiTrackCont に CentDedEkiTrack が追加された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiTrackIndex
		追加された CentDedEkiTrack のインデクス。
	*/
	virtual void onEkiTrackInsert( int iEkiTrackIndex ); 
	/**
		CentDedEkiTrackCont から CentDedEkiTrack が削除された直後、
		CentDedEkiTrackCont から呼び出されます。
	@param iEkiTrackIndex
		削除された CentDedEkiTrack のインデクス。
	*/
	virtual void onEkiTrackErase( int iEkiTrackIndex ); 

	///@}
};



} //namespace entDed

#endif //entDed_CentDedEkiJikokuTrack_h
