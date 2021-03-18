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
// $Id: CaContentPosToDcdTarget_Dim.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdCd_Pos_CaContentPosToDcdTarget_Dim_h
#define  DcDraw_DcdCd_Pos_CaContentPosToDcdTarget_Dim_h
#include "DcdCd\Pos\CconvContentPosToTarget.h"
#include "DcDraw\IfDcdTarget.h"

class CconvContentPosToDcdTarget ;	//	outerの参照

// ****************************************************************
//	CaContentPosToDcdTarget_Dim
// ****************************************************************
/**
@brief
  CaContentPosToDcdTarget_Dim は、
  CconvContentPosToDcdTarget に集約されます。
  
  このクラスは抽象クラスです。
  IfDcdTarget* を引数としたメソッド呼び出しを、
  calcCdDcdZone() 関数で 描画領域に変換して、
  m_pCconvContentPosToTarget に委譲します。
*/
class CaContentPosToDcdTarget_Dim
{
public:
	// ********************************
	//	インナータイプ
	// ********************************
	
private:
	// ********************************
	///@name 関連
	// ********************************
	///@{
	///@}
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/**	
		IfDcdTarget の右・下の余裕領域を保持します。
		IfDcdTarget の座標系で指定します。
	
		座標系によっては、右下のコンテンツが
		画面外(IfDcdTargetの領域外)になる場合があります。
		
		この値を1以上にすることにより、コンテンツを
		画面内のやや右上に表示させることができます。
	*/
	DcdSize m_sizeDcdMargin ;
	///@}

protected:
	// --------------------------------
	///@name オーバライド
	// --------------------------------
	///@{
	/**
	@return 
		IfDcdTarget の描画領域を返します。
	*/
	virtual CdDcdZone calcCdDcdZone( IfDcdTarget* pIfDcdTarget ) = 0 ;
	///@}

public:
	// ********************************
	//	コンストラクタ
	// ********************************
	CaContentPosToDcdTarget_Dim(
		DcdSize sizeDcdMargin );
	virtual ~CaContentPosToDcdTarget_Dim(){} ;


public:
	// ********************************
	///@name CconvContentPosToTarget-属性
	// ********************************
	///@{
	CconvContentPosToTarget::EMode	getMode()const ;
	void setMode( CconvContentPosToTarget::EMode	value ) ;

	DcdPos	getContentPos()const ;
	void setContentPos( DcdPos value ) ;

	double getTargetPosPerContent()const ;
	DcdSize	getContentSize()const ;
	///@}
	
public:
	// ********************************
	///@name CconvContentPosToTarget-TargetPosPerContent,ContentSize 取得・設定
	// ********************************
	///@{
	/**
		拡大率を取得することができます。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULLなら、属性の同期を行いません。
	@return
		拡大率。コンテント座標１あたりの、TargetPos の数。

	*/
	double getTargetPosPerContent( 
		IfDcdTarget* pIfDcdTarget ) ;

	/**
		拡大率を設定することができます。
	@param value[in]
		拡大率。コンテント座標１あたりの、TargetPos の数。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULLなら、属性の同期を行いません。
	*/
	void setTargetPosPerContent( double value , 
		IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZoneに表示するコンテントの大きさを取得することができます。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULLなら、属性の同期を行いません。
	@return
		TargetZoneに表示するコンテントの大きさ。
	*/
	DcdSize getContentSize( IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZoneに表示するコンテントの大きさを設定することができます。
	@param value[in]
		TargetZoneに表示するコンテントの大きさ。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULLなら、属性の同期を行いません。
	*/
	void setContentSize( DcdSize value , IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZoneに表示するコンテントの始点と拡大率を設定することができます。
	@param posContentPos [in]
		TargetPosの左上に描画されるContentの、ContentPos座標。
	@param dTargetPosPerContentX [in]
		拡大率。コンテント座標１あたりの、TargetPos の数。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULLなら、属性の同期を行いません。
	*/
	void setContentPosAndRate( 
		DcdPos posContentPos , 
		double dTargetPosPerContent ,
		IfDcdTarget* pIfDcdTarget ) ;

	/** 
		TargetZoneに表示するコンテントの始点と大きさを取得することができます。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULLなら、属性の同期を行いません。
	@return
		TargetZoneに表示するコンテントの位置と大きさ。
	*/
	CdDcdZone getContentZone( IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZoneに表示するコンテントの始点と大きさを設定することができます。
	@param zoneContent[in]
		TargetZoneに表示するコンテントの始点と大きさ。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULLなら、属性の同期を行いません。
	*/
	void setContentZone( const CdDcdZone& zoneContent , 
		IfDcdTarget* pIfDcdTarget ) ;


	///@}
public:
	// ********************************
	///@name CconvContentPosToTarget-座標変換
	// ********************************
	///@{
	/**
		ContentPos 上の座標を、TargetZone 上の座標に変換します。
	@param posContent [in]
		変換対象の座標を指定してください。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULL は指定できません。
	*/
	DcdPos	ContentPosToTarget( 
		DcdPos posContent , IfDcdTarget* pIfDcdTarget ) ;

	/**
		ContentPos 上の座標を、TargetZone 上の座標に変換します。
	@param posContent [in]
		変換対象の座標を指定してください。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULL は指定できません。
	*/
	CdDcdZone	ContentZoneToTarget( 
		const CdDcdZone& zoneContent , IfDcdTarget* pIfDcdTarget) ;

	/**
		TargetZone 上の座標を、ContentPos に変換します。
	@param posTarget[in]
		変換対象の座標を指定してください。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULL は指定できません。
	*/
	DcdPos	ContentPosFromTarget( 
		DcdPos posTarget , IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZone 上の座標を、ContentPos に変換します。
	@param zoneTarget [in]
		変換対象の座標を指定してください。
	@param pIfDcdTarget[in]
		描画対象を指定してください。
		NULL は指定できません。
	*/
	CdDcdZone	ContentZoneFromTarget( 
		const CdDcdZone& zoneTarget , IfDcdTarget* pIfDcdTarget ) ;

	///@}
public:
	// ********************************
	///@name CconvContentPosToTargetDim-関連
	// ********************************
	///@{
	virtual CconvContentPosToTarget* getCconvContentPosToTarget()=0 ;
	virtual const CconvContentPosToTarget* getCconvContentPosToTarget()const=0  ;
	///@}
public:
	// ********************************
	///@name CaContentPosToDcdTarget_Dim-属性
	// ********************************
	///@{
	DcdSize getDcdMargin()const ;
	void setDcdMargin(DcdSize value ) ;
	///@}
};

#endif //DcDraw_DcdCd_Pos_CaContentPosToDcdTarget_Dim_h
