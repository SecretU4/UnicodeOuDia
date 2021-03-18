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
//	CconvContentPosToDcdTarget.h
// ****************************************************************
*/
/** @file */
#ifndef  DcDrawa_DcdCd_Pos_CconvContentPosToDcdTarget_h
#define  DcDrawa_DcdCd_Pos_CconvContentPosToDcdTarget_h
#include "DcdCd\Pos\CconvContentPosToTargetXy.h"
#include "DcDraw\CaContentPosToDcdTarget_Dim.h"
#include "DcDraw\IfDcdTarget.h"

// ****************************************************************
//	CconvContentPosToDcdTarget
// ****************************************************************
/**
@brief
  X,Y 座標系の間で、ContentPos(コンテント座標)を
描画対象の IfDcdTarget の座標に変換する方法を提供するクラスです。
 */
class CconvContentPosToDcdTarget
{
public:
	// ********************************
	//	 内部クラス
	// ********************************
	// ****************************************************************
	//	CaConvX
	// ****************************************************************
	class CaConvX : public CaContentPosToDcdTarget_Dim
	{
	protected:
		// --------------------------------
		///@name オーバライド
		// --------------------------------
		///@{
		/**
		@return 
			IfDcdTarget の描画領域を返します。
		*/
		virtual CdDcdZone calcCdDcdZone( IfDcdTarget* pIfDcdTarget ) ;
		///@}

	public:
		// ********************************
		//	コンストラクタ
		// ********************************
		CaConvX(
			DcdSize sizeDcdMargin );
		// ********************************
		///@name CconvContentPosToTargetDim-関連
		// ********************************
		///@{
		virtual CconvContentPosToTarget* getCconvContentPosToTarget() ;
		virtual const CconvContentPosToTarget* getCconvContentPosToTarget()const  ;
		///@}
	};
	friend class CaConvX ;
	// ****************************************************************
	//	CaConvY
	// ****************************************************************
	class CaConvY : public CaContentPosToDcdTarget_Dim
	{
	protected:
		// --------------------------------
		///@name オーバライド
		// --------------------------------
		///@{
		/**
		@return 
			IfDcdTarget の描画領域を返します。
		*/
		virtual CdDcdZone calcCdDcdZone( IfDcdTarget* pIfDcdTarget ) ;
		///@}

	public:
		// ********************************
		//	コンストラクタ
		// ********************************
		CaConvY(
			DcdSize sizeDcdMargin );
		// ********************************
		///@name CconvContentPosToTargetDim-関連
		// ********************************
		///@{
		virtual CconvContentPosToTarget* getCconvContentPosToTarget() ;
		virtual const CconvContentPosToTarget* getCconvContentPosToTarget()const  ;
		///@}
	};
	friend class CaConvY ;
private:
	// ********************************
	///@name 集約
	// ********************************
	///@{
	/**
		座標を変換する CconvContentPosToTarget オブジェクトです。
	 */
	CconvContentPosToTargetXy	m_CconvContentPosToTargetXy ;
	
	/**
		X座標を変換する CconvContentPosToTarget オブジェクトです。
		このオブジェクトは、実際には 
		m_CconvContentPosToTargetXy.m_convX へのアダプタです。
	*/
	CaConvX	m_convX ;

	/**
		X座標を変換する CconvContentPosToTarget オブジェクトです。
		このオブジェクトは、実際には 
		m_CconvContentPosToTargetXy.m_convY へのアダプタです。
	*/
	CaConvY	m_convY ;
	///@}
private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	///@}
protected:
	// --------------------------------
	///@name 下請関数
	// --------------------------------
	///@{
	/**
		m_sizeDcdMarginXRight , m_sizeDcdMarginYBottom が
		適用された領域を算出します。
	@param pIfDcdTarget [in]
		描画対象の IfDcdTarget を指定してください。
		NULL は指定できません。
	@return
		算出後の領域です。
	*/
	virtual CdDcdZoneXy calcMarginAppliedZone( IfDcdTarget* pIfDcdTarget ) ;
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/** m_convX,m_convY の両方に、モードを設定します */
	CconvContentPosToDcdTarget( 
		CconvContentPosToTarget::EMode	eMode ,
		DcdSize	sizeDcdMarginXRight = 0 ,
		DcdSize	sizeDcdMarginYBottom = 0 );

	/** m_convX,m_convY を EModePosAndRate として初期化します。*/
	CconvContentPosToDcdTarget( 
		DcdPos	iContentPosX ,
		double dTargetPosPerContentX ,
		DcdPos	iContentPosY ,
		double dTargetPosPerContentY ,
		DcdSize	sizeDcdMarginXRight = 0 ,
		DcdSize	sizeDcdMarginYBottom = 0 ) ;

	/**
		m_convX,m_convY を EModeZone として初期化します。
	@param zoneContent[in]
		TargetZoneに表示するコンテントの始点と大きさ。
	*/
	CconvContentPosToDcdTarget( 
		const CdDcdZoneXy&	zonexyContent ,
		DcdSize	sizeDcdMarginXRight = 0 ,
		DcdSize	sizeDcdMarginYBottom = 0 ) ;

	CconvContentPosToDcdTarget() ;

	virtual ~CconvContentPosToDcdTarget() ;

public:
	// ********************************
	///@name CconvContentPosToDcdTarget-集約
	// ********************************
	///@{
	CaConvX* getX()
	{
		return &m_convX ;
	};
	const CaConvX* getX()const
	{
		return &m_convX ;
	};
	CaConvY* getY() 
	{
		return &m_convY ;
	};
	const CaConvY* getY()const 
	{
		return &m_convY ;
	};
	///@}
	
	// ********************************
	///@name CconvContentPosToDcdTarget-属性
	// ********************************
	///@{
	DcdSize	getDcdMarginXRight()const ;
	void setDcdMarginXRight( DcdSize value ) ;
	DcdSize	getDcdMarginYBottom()const ;
	void setDcdMarginYBottom( DcdSize value ) ;
	///@}
	// ********************************
	///@name CconvContentPosToDcdTarget-操作
	// ********************************
	///@{
	/**
	@return
		m_convX,m_convY の、 TargetPosへの変換モード。
	@attention
		m_convX,m_convY で変換モードが異なる場合は、この関数の戻り値は
		未定義です。
	*/
	virtual CconvContentPosToTarget::EMode	getMode()const ;

	/**
	@param value [in]
		m_convX,m_convY の、 TargetPosへの変換モードを指定してください。
	*/
	virtual void setMode( CconvContentPosToTarget::EMode	value ) ;

	/**
	@return 
		TargetPosの左上に描画されるContentの、ContentPos座標。
	*/
	virtual CdDcdPosXy getContentPos()const ;

	/**
	@param value [in]
		TargetPosの左上に描画されるContentの、ContentPos座標を設定。
	*/
	virtual void setContentPos( const CdDcdPosXy& value ) ;

	/**
		TargetZoneに表示するコンテントの始点と拡大率を設定することができます。
	@param posContentPos [in]
		TargetPosの左上に描画されるContentの、ContentPos座標。
	@param dTargetPosPerContentX [in]
		X方向の拡大率。コンテント座標１あたりの、TargetPos の数。
	@param dTargetPosPerContentY [in]
		Y方向の拡大率。コンテント座標１あたりの、TargetPos の数。
	@param pIfDcdTarget [in]
		描画対象の IfDcdTarget を指定してください。
	@note
		これら値を取得するときは、 
		getX() , getY() を使用して、
		m_convX,m_convY のポインタを取得し、そのオブジェクトから
		値を取得してください。
	*/
	virtual void setContentPosAndRate( 
		const CdDcdPosXy& posContentPos , 
		double dTargetPosPerContentX , 
		double dTargetPosPerContentY , 
		IfDcdTarget* pIfDcdTarget ) ;


	/** 
		TargetZoneに表示するコンテントの始点と大きさを取得することができます。
	@param pIfDcdTarget [in]
		描画対象の IfDcdTarget を指定してください。
	@return
		TargetZoneに表示するコンテントの位置と大きさ。
	*/
	CdDcdZoneXy getContentZone( IfDcdTarget* pIfDcdTarget ) ;

	/**
		TargetZoneに表示するコンテントの始点と大きさを設定することができます。
	@param zoneContent[in]
		TargetZoneに表示するコンテントの始点と大きさ。
	@param pIfDcdTarget [in]
		描画対象の IfDcdTarget を指定してください。
	*/
	virtual void setContentZone( const CdDcdZoneXy& zoneContent , 
		IfDcdTarget* pIfDcdTarget ) ;
	///@}
	// ********************************
	///@name CconvContentPosToDcdTarget-座標変換
	// ********************************
	///@{
	/**
		ContentPos 上の座標
		を、
		TargetZone 上の座標
		に変換します。
	@param value [in]
  		変換前の値を指定して下さい。
	@param pIfDcdTarget [in]
		描画対象の IfDcdTarget を指定してください。
	@return
  		変換後の値を返します。
	 */
	virtual CdDcdPosXy ContentPosToTarget( 
		const CdDcdPosXy& value ,
		IfDcdTarget* pIfDcdTarget ) ;
	
	/**
		TargetZone 上の座標
		を、
		ContentPos 上の座標
		に変換します。
	@param value [in]
  		変換前の値を指定して下さい。
	@param pIfDcdTarget [in]
		描画対象の IfDcdTarget を指定してください。
	 */
	virtual CdDcdPosXy ContentPosFromTarget( 
		const CdDcdPosXy& value ,
		IfDcdTarget* pIfDcdTarget ) ;

	/**
		ContentPos 上の座標
		を、
		TargetZone 上の座標
		に変換します。
	@param value [in]
  		変換前の値を指定して下さい。
	@param pIfDcdTarget [in]
		描画対象の IfDcdTarget を指定してください。
	 */
	virtual CdDcdZoneXy ContentZoneToTarget( 
		const CdDcdZoneXy& value ,
		IfDcdTarget* pIfDcdTarget ) ;
	
	/**
		TargetZone 上の座標
		を、
		ContentPos 上の座標
		に変換します。
	@param value [in]
  		変換前の値を指定して下さい。
	@param pIfDcdTarget [in]
		描画対象の IfDcdTarget を指定してください。
	 */
	virtual CdDcdZoneXy ContentZoneFromTarget( 
		const CdDcdZoneXy& value ,
		IfDcdTarget* pIfDcdTarget ) ;
	///@}
};

#endif /*DcDrawa_DcdCd_Pos_CconvContentPosToDcdTarget_h*/
