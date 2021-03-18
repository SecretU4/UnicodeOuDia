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
//$Id: CentDedEkiTrack.h 378 2016-11-16 21:10:54Z okm $
#ifndef  entDed_CentDedEkiTrack_h
#define  entDed_CentDedEkiTrack_h

#include <string>
#include "NsMu\CChildBase.h"

namespace entDed{

using namespace std ;
using namespace OuLib::NsMu ;

/**
@brief
  駅の『番線』を表します
  
  『番線』には、以下の3種があります。
  
 - 上り本線
 - 下り本線
 - 名前つき番線
 

制約
 -------------------------------- 

△　このオブジェクトが『番線コンテナ』(CentDedEkiTrackCont)の一部である場合、番線の種類を変更することはできません。

操作のエラー検査・修正
 -------------------------------- 

△上書き(operator=) : このオブジェクトが、親オブジェクトCentDedEkiTrackCont の子である場合で、代入元が CentDedEkiTrackCont::set() でエラーになる場合、例外スローになります。

○親オブジェクトの変更(setParent()):  adjust()を実行する

制約に合うように属性を修正(adjust)
 -------------------------------- 

　特になし

*/
class CentDedEkiTrack : public CChildBase
{
	typedef CChildBase	super ;
public:
	// ****************************************************************
	//	インナータイプ
	// ****************************************************************
	
	/**
	 番線の種類
	*/
	enum ETrackType
	{
		/// 上り本線
		ETrackType_NoboriMain , 
		/// 下り本線
		ETrackType_KudariMain , 
		/// 名前つき番線
		ETrackType_Named , 
	};
	
	/**
		このクラスがスローする例外
	*/
	class LException
	{
	};
	
public:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**
		番線の種類
	*/
	ETrackType	m_eTrackType ;
	
	/** 名前。m_eTrackType が ETrackType_Named 以外の場合は無効です */
	string m_strName ;
	
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CentDedEkiTrack()  ;
	
	explicit CentDedEkiTrack( ETrackType eTrackType , const string& strName = "" ) ;
	/** 
		ETrackType_Named のオブジェクトを生成します 
	@param strName
		名前
	*/
	explicit CentDedEkiTrack( const string& strName ) ;

	/** 
		このオブジェクトが、親オブジェクトCentDedEkiTrackCont の
		子である場合で、代入元が CentDedEkiTrackCont::set() でエラーに
		なる場合、例外スローになります。
	@param value 
		代入元
	@exception LException 
	  value が種類の異なる番線です。
	*/
	CentDedEkiTrack& operator=( const CentDedEkiTrack& value ) ;
	
	
public:
	// ********************************
	///@name CParentBase-操作
	// ********************************
	///@{
	/** ○親オブジェクトの変更(setParent()):  adjust()を実行する */
	virtual void setParent( CParentBase* pParent ) ;
	///@}
public:
	// ********************************
	///@name CentDedEkiTrack-属性
	// ********************************
	///@{
	/** @see m_eTrackType */
	ETrackType	getTrackType()const{ return m_eTrackType ;}
	/** @see eTrackType */
	void setTrackType( ETrackType eTrackType );
	/** @see m_strName  */
	string getName()const{ return m_strName ;}
	/** @see m_strName */
	void setName( const string& value ){ m_strName = value ;}
	///@}

public:
	// ********************************
	///@name CentDedEkiTrack-操作
	// ********************************
	///@{
	/**
		this の属性が制約に反している場合、制約に合うように、属性を
		修正します。

		このクラスでは、処理はありません。

	*/
	void adjust() ;
	///@}
};

} //namespace entDed

#endif //entDed_CentDedEkiTrack_h



