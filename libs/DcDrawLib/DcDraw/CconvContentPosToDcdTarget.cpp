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
//	CconvContentPosToDcdTarget.cpp
// ****************************************************************
*/
#include "DcDraw\CconvContentPosToDcdTarget.h"

namespace DcDrawLib{
namespace DcDraw{

	// ********************************
	//	 内部クラス
	// ********************************
	// ****************************************************************
	//	CaConvX
	// ****************************************************************
CdDcdZone CconvContentPosToDcdTarget::CaConvX::calcCdDcdZone( 
	IfDcdTarget* pIfDcdTarget ) 
{
	CconvContentPosToDcdTarget* pOuter = (CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convX) ) ;

	CdDcdZone	zoneRv ;
	if ( pIfDcdTarget != NULL )
	{
		zoneRv = pOuter->calcMarginAppliedZone( pIfDcdTarget ).getX() ;
	}
	return zoneRv ;
}
		// ********************************
		//	コンストラクタ
		// ********************************
CconvContentPosToDcdTarget::CaConvX::CaConvX(
	DcdSize sizeDcdMargin )
	:CaContentPosToDcdTarget_Dim( 
		sizeDcdMargin )
{
}
		// ********************************
		///@name CconvContentPosToTargetDim-関連
		// ********************************
CconvContentPosToTarget* 
CconvContentPosToDcdTarget::CaConvX::getCconvContentPosToTarget() 
{
	CconvContentPosToDcdTarget* pOuter = (CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convX) ) ;
	return pOuter->m_CconvContentPosToTargetXy.getX() ;
}
const CconvContentPosToTarget* 
CconvContentPosToDcdTarget::CaConvX::getCconvContentPosToTarget()const  
{
	const CconvContentPosToDcdTarget* pOuter = (const CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convX) ) ;
	return pOuter->m_CconvContentPosToTargetXy.getX() ;
}
	// ****************************************************************
	//	CaConvY
	// ****************************************************************
CdDcdZone CconvContentPosToDcdTarget::CaConvY::calcCdDcdZone( IfDcdTarget* pIfDcdTarget ) 
{
	CconvContentPosToDcdTarget* pOuter = (CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convY) ) ;

	CdDcdZone	zoneRv ;
	if ( pIfDcdTarget != NULL )
	{
		zoneRv = pOuter->calcMarginAppliedZone( pIfDcdTarget ).getY() ;
	}
	return zoneRv ;
}

		// ********************************
		//	コンストラクタ
		// ********************************
CconvContentPosToDcdTarget::CaConvY::CaConvY(
	DcdSize sizeDcdMargin )
	:CaContentPosToDcdTarget_Dim( 
		sizeDcdMargin )
{
}
		// ********************************
		///@name CconvContentPosToTargetDim-関連
		// ********************************
CconvContentPosToTarget* 
CconvContentPosToDcdTarget::CaConvY::getCconvContentPosToTarget() 
{
	CconvContentPosToDcdTarget* pOuter = (CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convY) ) ;
	return pOuter->m_CconvContentPosToTargetXy.getY() ;
}
const CconvContentPosToTarget* 
CconvContentPosToDcdTarget::CaConvY::getCconvContentPosToTarget()const  
{
	const CconvContentPosToDcdTarget* pOuter = (const CconvContentPosToDcdTarget*)( 
		((char*)this)-offsetof(CconvContentPosToDcdTarget,m_convY) ) ;
	return pOuter->m_CconvContentPosToTargetXy.getY() ;
}

// ****************************************************************
//	CconvContentPosToDcdTarget
// ****************************************************************
	// --------------------------------
	//@name 下請関数
	// --------------------------------
CdDcdZoneXy CconvContentPosToDcdTarget::calcMarginAppliedZone( 
	IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	aCdDcdZoneXy = pIfDcdTarget->getZone() ;
	{
		CdDcdZone	zone = aCdDcdZoneXy.getX() ;
		if ( zone.getSize() >  m_convX.getDcdMargin() ){
			zone.setSize( zone.getSize() -  m_convX.getDcdMargin()  ) ;
		} else if ( zone.getSize() < - m_convX.getDcdMargin()  ){
			zone.setSize( zone.getSize() +  m_convX.getDcdMargin()  ) ;
		} else {
			zone.setSize( 0 ) ;
		}
		aCdDcdZoneXy.setX( zone ) ;
	}
	{
		CdDcdZone	zone = aCdDcdZoneXy.getY() ;
		if ( zone.getSize() >  m_convY.getDcdMargin()  ){
			zone.setSize( zone.getSize() - m_convY.getDcdMargin()   ) ;
		} else if ( zone.getSize() < -m_convY.getDcdMargin()   ){
			zone.setSize( zone.getSize() + m_convY.getDcdMargin()   ) ;
		} else {
			zone.setSize( 0 ) ;
		}
		aCdDcdZoneXy.setY( zone ) ;
	}
	return aCdDcdZoneXy ;
}
	///@}
	// ********************************
	//	コンストラクタ
	// ********************************
CconvContentPosToDcdTarget::CconvContentPosToDcdTarget( 
	CconvContentPosToTarget::EMode	eMode ,
	DcdSize	sizeDcdMarginXRight ,
	DcdSize	sizeDcdMarginYBottom )
	: m_CconvContentPosToTargetXy( eMode ) 
	, m_convX( sizeDcdMarginXRight )   
	, m_convY( sizeDcdMarginYBottom )   
{
}

CconvContentPosToDcdTarget::CconvContentPosToDcdTarget( 
		DcdPos	iContentPosX ,
		double dTargetPosPerContentX ,
		DcdPos	iContentPosY ,
		double dTargetPosPerContentY ,
		DcdSize	sizeDcdMarginXRight ,
		DcdSize	sizeDcdMarginYBottom ) 
	: m_CconvContentPosToTargetXy( 
		iContentPosX ,
		dTargetPosPerContentX ,
		iContentPosY ,
		dTargetPosPerContentY ) 
	, m_convX( sizeDcdMarginXRight )  
	, m_convY( sizeDcdMarginYBottom )   
{
}

CconvContentPosToDcdTarget::CconvContentPosToDcdTarget( 
		const CdDcdZoneXy&	zonexyContent ,
		DcdSize	sizeDcdMarginXRight ,
		DcdSize	sizeDcdMarginYBottom ) 
	: m_CconvContentPosToTargetXy( zonexyContent ) 
	, m_convX( sizeDcdMarginXRight )  
	, m_convY( sizeDcdMarginYBottom )   
{
}

CconvContentPosToDcdTarget::CconvContentPosToDcdTarget() 
	: m_convX( 0 )  
	, m_convY( 0 )   
{
}

CconvContentPosToDcdTarget::~CconvContentPosToDcdTarget() 
{
}


	// ********************************
	//@name CconvContentPosToDcdTarget-集約
	// ********************************

	// ********************************
	//@name CconvContentPosToDcdTarget-属性
	// ********************************
DcdSize	CconvContentPosToDcdTarget::getDcdMarginXRight()const 
{
	return m_convX.getDcdMargin() ;
}
void CconvContentPosToDcdTarget::setDcdMarginXRight( DcdSize value ) 
{
	return m_convX.setDcdMargin(value) ;
}
DcdSize	CconvContentPosToDcdTarget::getDcdMarginYBottom()const 
{
	return m_convY.getDcdMargin() ;
}
void CconvContentPosToDcdTarget::setDcdMarginYBottom( DcdSize value ) 
{
	return m_convY.setDcdMargin(value) ;
}

	// ********************************
	//@name CconvContentPosToDcdTarget-操作
	// ********************************
CconvContentPosToTarget::EMode	
CconvContentPosToDcdTarget::getMode()const 
{
	return m_CconvContentPosToTargetXy.getMode() ;
}

void CconvContentPosToDcdTarget::setMode( 
	CconvContentPosToTarget::EMode	value ) 
{
	m_CconvContentPosToTargetXy.setMode( value ) ;
}

CdDcdPosXy CconvContentPosToDcdTarget::getContentPos()const 
{
	return CdDcdPosXy( 
		m_CconvContentPosToTargetXy.getX()->getContentPos() ,
		m_CconvContentPosToTargetXy.getY()->getContentPos() );
}

void CconvContentPosToDcdTarget::setContentPos( const CdDcdPosXy& value ) 
{
	m_CconvContentPosToTargetXy.getX()->setContentPos( value.getX() ) ;
	m_CconvContentPosToTargetXy.getY()->setContentPos( value.getY() ) ;
}


void CconvContentPosToDcdTarget::setContentPosAndRate( 
		const CdDcdPosXy& posContentPos , 
		double dTargetPosPerContentX , 
		double dTargetPosPerContentY , 
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	aTargetZone ;
	CdDcdZoneXy* pTargetZone = NULL ;
	if ( pIfDcdTarget != NULL )
	{
		aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
		pTargetZone = &aTargetZone ;
	}

	m_CconvContentPosToTargetXy.setContentPosAndRate( 
		posContentPos , 
		dTargetPosPerContentX , 
		dTargetPosPerContentY , 
		pTargetZone ) ;
}

CdDcdZoneXy CconvContentPosToDcdTarget::getContentZone( 
	IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	aTargetZone ;
	CdDcdZoneXy* pTargetZone = NULL ;
	if ( pIfDcdTarget != NULL )
	{
		aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
		pTargetZone = &aTargetZone ;
	}
	// --------------------------------
	return m_CconvContentPosToTargetXy.getContentZone( 
		pTargetZone ) ;
}

void CconvContentPosToDcdTarget::setContentZone( 
	const CdDcdZoneXy& zoneContent , 
	IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy	aTargetZone ;
	CdDcdZoneXy* pTargetZone = NULL ;
	if ( pIfDcdTarget != NULL )
	{
		aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
		pTargetZone = &aTargetZone ;
	}
	// --------------------------------
	m_CconvContentPosToTargetXy.setContentZone( 
		zoneContent , 
		pTargetZone ) ;
}
	// ********************************
	//@name CconvContentPosToDcdTarget-座標変換
	// ********************************
CdDcdPosXy CconvContentPosToDcdTarget::ContentPosToTarget( 
		const CdDcdPosXy& value ,
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
	return m_CconvContentPosToTargetXy.ContentPosToTarget( 
		value , aTargetZone ) ;
}
CdDcdPosXy CconvContentPosToDcdTarget::ContentPosFromTarget( 
		const CdDcdPosXy& value ,
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
	return m_CconvContentPosToTargetXy.ContentPosFromTarget(
		value , aTargetZone ) ;

}

CdDcdZoneXy CconvContentPosToDcdTarget::ContentZoneToTarget( 
		const CdDcdZoneXy& value ,
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
	return m_CconvContentPosToTargetXy.ContentZoneToTarget( 
		value , aTargetZone ) ;
}

CdDcdZoneXy CconvContentPosToDcdTarget::ContentZoneFromTarget( 
		const CdDcdZoneXy& value ,
		IfDcdTarget* pIfDcdTarget ) 
{
	CdDcdZoneXy aTargetZone = calcMarginAppliedZone( pIfDcdTarget ) ; 
	return m_CconvContentPosToTargetXy.ContentZoneFromTarget(
		value , aTargetZone ) ;

}

} //namespace DcDraw
} //namespace DcDrawLib
