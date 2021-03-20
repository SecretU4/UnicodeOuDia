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
//	CconvContentPosToTargetXy.h
// ****************************************************************
*/
/** @file */
#ifndef  DcDrawa_DcdCd_Pos_CconvContentPosToTargetXy_h
#define  DcDrawa_DcdCd_Pos_CconvContentPosToTargetXy_h
#include "DcdCd\Pos\CdDcdZoneXy.h"
#include "DcdCd\Pos\CconvContentPosToTarget.h"

namespace DcDrawLib{
namespace DcdCd{
namespace Pos{


// ****************************************************************
//	CconvContentPosToTargetXy
// ****************************************************************
/**
 @brief
  X,Y 座標系の間で、ContentPos(コンテント座標)を
TargetPos(ターゲット座標)に変換する方法を提供するクラスです。
 */
class CconvContentPosToTargetXy
{
private:
	// ********************************
	///@name 集約
	// ********************************
	///@{
	/**
		X 方向の座標を変換する CconvContentPosToTarget オブジェクトです。
	 */
	CconvContentPosToTarget	m_convX ;
	
	/**
		Y 方向の座標を変換する CconvContentPosToTarget オブジェクトです。
	 */
	CconvContentPosToTarget	m_convY ;
	
	///@}
public:
	// ********************************
	//	コンストラクタ
	// ********************************
	/** m_convX,m_convY の両方に、モードを設定します */
	CconvContentPosToTargetXy( 
		CconvContentPosToTarget::EMode	eMode ) ;

	/** m_convX,m_convY を EModePosAndRate として初期化します。*/
	CconvContentPosToTargetXy( 
		DcdPos	iContentPosX ,
		double dTargetPosPerContentX ,
		DcdPos	iContentPosY ,
		double dTargetPosPerContentY ) ;

	/** m_convX,m_convY を EModeZone として初期化します。*/
	CconvContentPosToTargetXy( 
		DcdPos	iContentPosX ,
		DcdSize	iContentSizeX ,
		DcdPos	iContentPosY ,
		DcdSize	iContentSizeY ) ;

	/**
		m_convX,m_convY を EModeZone として初期化します。
	@param zoneContent[in]
		TargetZoneに表示するコンテントの始点と大きさ。
	*/
	CconvContentPosToTargetXy( 
		const CdDcdZoneXy&	zonexyContent ) ;

	CconvContentPosToTargetXy() ;

	virtual ~CconvContentPosToTargetXy() ;


public:
	// ********************************
	///@name CconvContentPosToTargetXy-集約
	// ********************************
	///@{
	CconvContentPosToTarget* getX()
	{	return  &m_convX;	};
	const CconvContentPosToTarget* getX()const 
	{	return  &m_convX;	};
	CconvContentPosToTarget* getY() 
	{	return  &m_convY;	};
	const CconvContentPosToTarget* getY()const  
	{	return  &m_convY;	};
	///@}
	
	// ********************************
	///@name CconvContentPosToTargetXy-操作
	// ********************************
	///@{
	/**
	@return
		m_convX,m_convY の、 TargetPosへの変換モード。
	@attention
		m_convX,m_convY で変換モードが異なる場合は、この関数の戻り値は
		未定義です。
	*/
	CconvContentPosToTarget::EMode	getMode()const ;

	/**
	@param value [in]
		m_convX,m_convY の、 TargetPosへの変換モードを指定してください。
	*/
	void setMode( CconvContentPosToTarget::EMode	value ) ;
	
	/**
		TargetZoneに表示するコンテントの始点と拡大率を設定することができます。
	@param posContentPos [in]
		TargetPosの左上に描画されるContentの、ContentPos座標。
	@param dTargetPosPerContentX [in]
		X方向の拡大率。コンテント座標１あたりの、TargetPos の数。
	@param dTargetPosPerContentY [in]
		Y方向の拡大率。コンテント座標１あたりの、TargetPos の数。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		m_eMode=EModePosAndRate のときは、この値は省略することができます。
		m_eMode=EModeZone のときは必須です。
	@note
		これら値を取得するときは、 getX() , getY() を使用して、
		m_convX,m_convY のポインタを取得し、そのオブジェクトから
		値を取得してください。
	*/
	void setContentPosAndRate( 
		const CdDcdPosXy& posContentPos , 
		double dTargetPosPerContentX , 
		double dTargetPosPerContentY , 
		const CdDcdZoneXy* pTargetZone ) ;
	
	/** 
		TargetZoneに表示するコンテントの始点と大きさを取得することができます。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		m_eMode=EModeZone のときは、この値は省略することができます。
		m_eMode=EModePosAndRate のときは必須です。
	@return
		TargetZoneに表示するコンテントの位置と大きさ。
	*/
	CdDcdZoneXy getContentZone( const CdDcdZoneXy* pTargetZone ) ;

	/**
		TargetZoneに表示するコンテントの始点と大きさを設定することができます。
	@param zoneContent[in]
		TargetZoneに表示するコンテントの始点と大きさ。
	@param pTargetZone[in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
		m_eMode=EModeZone のときは、この値は省略することができます。
		m_eMode=EModePosAndRate のときは必須です。
	*/
	void setContentZone( const CdDcdZoneXy& zoneContent , const CdDcdZoneXy* pTargetZone ) ;
	///@}
	// ********************************
	///@name CconvContentPosToTargetXy-座標変換
	// ********************************
	///@{
	/**
		ContentPos 上の座標
		を、
		TargetZone 上の座標
		に変換します。
	@param value [in]
  		変換前の値を指定して下さい。
	@param aTargetZone [in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
	@return
  		変換後の値を返します。
	 */
	virtual CdDcdPosXy ContentPosToTarget( 
		const CdDcdPosXy& value ,
		const CdDcdZoneXy& aTargetZone ) ;
	
	/**
		TargetZone 上の座標
		を、
		ContentPos 上の座標
		に変換します。
	@param value [in]
  		変換前の値を指定して下さい。
	@param aTargetZone [in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
	 */
	virtual CdDcdPosXy ContentPosFromTarget( 
		const CdDcdPosXy& value ,
		const CdDcdZoneXy& aTargetZone ) ;

	/**
		ContentPos 上の座標
		を、
		TargetZone 上の座標
		に変換します。
	@param value [in]
  		変換前の値を指定して下さい。
	@param aTargetZone [in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
	 */
	virtual CdDcdZoneXy ContentZoneToTarget( 
		const CdDcdZoneXy& value ,
		const CdDcdZoneXy& aTargetZone ) ;
	
	/**
		TargetZone 上の座標
		を、
		ContentPos 上の座標
		に変換します。
	@param value [in]
  		変換前の値を指定して下さい。
	@param aTargetZone [in]
		このクラスで座標変換を行う際に対象となる TargetZone を指定して
		ください。
	 */
	virtual CdDcdZoneXy ContentZoneFromTarget( 
		const CdDcdZoneXy& value ,
		const CdDcdZoneXy& aTargetZone ) ;
	///@}
};

} //namespace Pos
} //namespace DcdCd
} //namespace DcDrawLib

#endif /*DcDrawa_DcdCd_Pos_CconvContentPosToTargetXy_h*/
