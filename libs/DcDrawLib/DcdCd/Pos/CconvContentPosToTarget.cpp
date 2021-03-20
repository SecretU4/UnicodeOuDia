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
// $Id: CconvContentPosToTarget.cpp 313 2016-06-11 13:20:04Z okm $
// ****************************************************************
*/
#include <STDDEF.H>
#include "DcdCd\Pos\CconvContentPosToTarget.h"
#include "DcdCd\Pos\CconvDcdPosOnZone_PosOrgAndRate.h"
#include "DcdCd\Pos\CconvDcdPosOnZone_DcdZone.h"

namespace DcDrawLib{
namespace DcdCd{
namespace Pos{


// ****************************************************************
//	CconvContentPosToTarget
// ****************************************************************
	// --------------------------------
	//@name 下請関数
	// --------------------------------
DcdSize CconvContentPosToTarget::TargetPosPerContentToContentSize( 
	double dTargetPosPerContent , 
	const CdDcdZone* pTargetZone ) 
{
	DcdSize	iRv = 0 ;
	if ( pTargetZone->getSize() != 0 && 
		m_dTargetPosPerContent != (double)0 )
	{
		iRv =  (DcdSize)( (double)pTargetZone->getSize() / m_dTargetPosPerContent ) ; 
	}

	return( iRv ) ;
}

double CconvContentPosToTarget::TargetPosPerContentFromContentSize( 
	DcdSize iContentSize , 
	const CdDcdZone* pTargetZone ) 
{
	double	dRv = 0 ;
	if ( pTargetZone->getSize() != 0 && m_iContentSize != 0 )
	{
		dRv = (double)pTargetZone->getSize() / (double)m_iContentSize ;
	}
	return dRv ;
}


void CconvContentPosToTarget::
	synchronizeProp( const CdDcdZone* pTargetZone ) 
{
	// --------------------------------
	//	(1)属性設定時の同期
	// --------------------------------
	//　TargetZone を指定する操作において、TargetZone.Sizeが0の場合、
	//	TargetZone にNULLが指定された場合は、
	//	同期処理は行われません。
	if ( pTargetZone != NULL && 
		pTargetZone->getSize() != 0 )
	{
		if ( m_eSynchronizeState == ESynchronizeState_TargetPosPerContent )
		{
			//	m_dTargetPosPerContent が属性設定同期待ち。

			m_dTargetPosPerContent = TargetPosPerContentFromContentSize(
				m_iContentSize , pTargetZone );
			
			//	プロパティの属性設定同期を解除
			m_eSynchronizeState = ESynchronizeState_None ;

			//	プロパティのキャッシュ用に属性を更新
			m_iTargetSize_Prev = pTargetZone->getSize() ;
		}
		else if ( m_eSynchronizeState == ESynchronizeState_ContentSize )
		{
			// m_iContentSize が属性設定同期待ち。
			m_iContentSize = TargetPosPerContentToContentSize(
				m_dTargetPosPerContent , pTargetZone ) ;

			//	プロパティの属性設定同期を解除
			m_eSynchronizeState = ESynchronizeState_None ;

			//	プロパティのキャッシュ用に属性を更新
			m_iTargetSize_Prev = pTargetZone->getSize() ;
		}
	}


	// --------------------------------
	//	(2)属性取得時の同期
	// --------------------------------

	if ( pTargetZone != NULL )
	{
		if ( m_iTargetSize_Prev == pTargetZone->getSize() )	
		{
			//	指定された TargetZone の Size が前回と同じなら、	
			//	属性の同期 SynchronizeProp を行いません。
			//	これを、『プロパティのキャッシュ』
			//	PropCache と呼称します。
		}
		else
		{
			if ( pTargetZone->getSize() == 0 )
			{
				//　 PosAndRate モードでの『属性の同期』の際に、
				//	TargetZone.Size=0が
				//	指定された場合は、ContentSize は更新せず、
				//	前値を継続します。 
			}
			else
			{
				if ( m_eMode == EModePosAndRate )
				{
					//	このクラスの PosAndRate モードでは、
					//	ユーザーがTargetZoneを
					//	指定する操作を行うたびに、属性 ContentSize を
					//	更新します。ContentSize は、
					//	TargetZone のSize が変化する毎に、値が変化します。
					m_iContentSize = TargetPosPerContentToContentSize(
						m_dTargetPosPerContent , pTargetZone ) ;
				}
				else
				{
					//	Zone モードでも同様に、TargetPosPerContent を指定、
					//	取得すること
					//	ができます。このクラスのユーザーがTargetZoneを
					//	指定する操作を行うたび、
					//	TargetPosPerContentを更新します。
					m_dTargetPosPerContent = TargetPosPerContentFromContentSize(
						m_iContentSize , pTargetZone );
				}
			}
			//	プロパティのキャッシュ用に属性を更新
			m_iTargetSize_Prev = pTargetZone->getSize() ;
		}
	}
}

	// ********************************
	//	コンストラクタ
	// ********************************
CconvContentPosToTarget::CconvContentPosToTarget() :
	m_eMode( EModePosAndRate ) , 
	m_iContentPos( 0 ) ,
	m_dTargetPosPerContent( 1 ) ,
	m_iContentSize( 1 ),
	m_eSynchronizeState( ESynchronizeState_None ) ,
	m_iTargetSize_Prev( 0 ) {}
	
CconvContentPosToTarget::CconvContentPosToTarget( 
	EMode	eMode ) :
	m_eMode( eMode ) , 
	m_iContentPos( 0 ) ,
	m_dTargetPosPerContent( 1 ) ,
	m_iContentSize( 1 ) ,
	m_eSynchronizeState( ESynchronizeState_None ) ,
	m_iTargetSize_Prev( 0 ) {}

CconvContentPosToTarget::CconvContentPosToTarget( 
		DcdPos	iContentPos ,
		double dTargetPosPerContent ) :
	m_eMode( EModePosAndRate ) , 
	m_iContentPos( iContentPos ) ,
	m_dTargetPosPerContent( dTargetPosPerContent ) ,
	m_iContentSize( 1 ) , 
	m_eSynchronizeState( ESynchronizeState_ContentSize ) ,
	m_iTargetSize_Prev( 0 ) {}

CconvContentPosToTarget::CconvContentPosToTarget( 
		const CdDcdZone& zoneContent ) :
	m_eMode( EModeZone ) , 
	m_iContentPos( zoneContent.getPos() ) ,
	m_dTargetPosPerContent( 1 ) ,
	m_iContentSize( zoneContent.getSize() ) ,
	m_eSynchronizeState( ESynchronizeState_TargetPosPerContent ) ,
	m_iTargetSize_Prev( 0 ) {}


	// ********************************
	//@name CconvContentPosToTarget-属性
	// ********************************
CconvContentPosToTarget::EMode	CconvContentPosToTarget::getMode()const 
{
	return m_eMode ;
}
void CconvContentPosToTarget::setMode( EMode	value ) 
{
	m_eMode = value ;
}

DcdPos	CconvContentPosToTarget::getContentPos()const 
{
	return m_iContentPos ;
}
void CconvContentPosToTarget::setContentPos( DcdPos value ) 
{
	m_iContentPos = value ;
}

double CconvContentPosToTarget::getTargetPosPerContent()const 
{
	return m_dTargetPosPerContent ;
}
DcdSize	CconvContentPosToTarget::getContentSize()const 
{
	return m_iContentSize ;
}


	// ********************************
	//@name CconvContentPosToTarget-TargetPosPerContent,ContentSize の取得・設定
	// ********************************

double CconvContentPosToTarget::getTargetPosPerContent( 
	const CdDcdZone* pTargetZone ) 
{
	//	プロパティの同期
	synchronizeProp( pTargetZone ) ;

	return m_dTargetPosPerContent ;
}

void CconvContentPosToTarget::setTargetPosPerContent( 
	double value , const CdDcdZone* pTargetZone ) 
{
	m_dTargetPosPerContent = value ;

	/// m_iContentSize が属性設定同期待ち。
	m_eSynchronizeState = ESynchronizeState_ContentSize ;

	//	プロパティの同期
	synchronizeProp( pTargetZone ) ;
}

DcdSize CconvContentPosToTarget::getContentSize( 
	const CdDcdZone* pTargetZone ) 
{
	//	プロパティの同期
	synchronizeProp( pTargetZone ) ;

	return m_iContentSize ;
}

void CconvContentPosToTarget::setContentSize( 
	DcdSize value , const CdDcdZone* pTargetZone ) 
{
	m_iContentSize = value ;

	// m_dTargetPosPerContent が属性設定同期待ち。
	m_eSynchronizeState = ESynchronizeState_TargetPosPerContent ;

	//	プロパティの同期
	synchronizeProp( pTargetZone ) ;
}

void CconvContentPosToTarget::setContentPosAndRate( 
		DcdPos posContentPos , 
		double dTargetPosPerContent ,
		const CdDcdZone* pTargetZone ) 
{
	setContentPos( posContentPos ) ;
	setTargetPosPerContent( dTargetPosPerContent , pTargetZone ) ;

	//	プロパティの同期
	synchronizeProp( pTargetZone ) ;
}


CdDcdZone CconvContentPosToTarget::getContentZone( 
	const CdDcdZone* pTargetZone ) 
{
	//	プロパティの同期
	synchronizeProp( pTargetZone ) ;

	return CdDcdZone( getContentPos() , getContentSize( pTargetZone ) ) ;
}
void CconvContentPosToTarget::setContentZone( 
	const CdDcdZone& zoneContent , 
	const CdDcdZone* pTargetZone ) 
{
	setContentPos( zoneContent.getPos() ) ;
	setContentSize( zoneContent.getSize() , pTargetZone ) ;

	//	プロパティの同期
	synchronizeProp( pTargetZone ) ;
}
	// ********************************
	//@name CconvContentPosToTarget-座標変換
	// ********************************


DcdPos	CconvContentPosToTarget::ContentPosToTarget( 
		DcdPos posContent , const CdDcdZone& aTargetZone ) 
{
	DcdPos posRv =  0 ;

	//	プロパティの同期
	synchronizeProp( &aTargetZone ) ;

	if ( m_eMode == EModePosAndRate )
	{
		CconvDcdPosOnZone_PosOrgAndRate	aConv( 
			m_iContentPos , aTargetZone.getPos() , m_dTargetPosPerContent ) ;
		posRv  =aConv.Zone1PosToZone2( posContent ) ;
	}
	else if ( m_eMode == EModeZone )
	{
		CconvDcdPosOnZone_DcdZone	aConv( 
			CdDcdZone( m_iContentPos , m_iContentSize ),
			aTargetZone ) ;
		posRv  = aConv.Zone1PosToZone2( posContent ) ;
	}
	return posRv;
}

CdDcdZone CconvContentPosToTarget::ContentZoneToTarget( 
		const CdDcdZone& zoneContent , const CdDcdZone& aTargetZone ) 
{
	CdDcdZone	zoneRv  ; 

	//	プロパティの同期
	synchronizeProp( &aTargetZone ) ;

	if ( m_eMode == EModePosAndRate )
	{
		CconvDcdPosOnZone_PosOrgAndRate	aConv( 
			m_iContentPos , aTargetZone.getPos() , m_dTargetPosPerContent ) ;
		zoneRv = aConv.Zone1ToZone2( zoneContent ) ;
	}
	else if ( m_eMode == EModeZone )
	{
		CconvDcdPosOnZone_DcdZone	aConv( 
			CdDcdZone( m_iContentPos , m_iContentSize ),
			aTargetZone ) ;
		zoneRv = aConv.Zone1ToZone2( zoneContent ) ;
	}
	return zoneRv ;
}

DcdPos CconvContentPosToTarget::ContentPosFromTarget( 
		DcdPos posTarget , const CdDcdZone& aTargetZone ) 
{
	DcdPos posRv =  0 ;

	//	プロパティの同期
	synchronizeProp( &aTargetZone ) ;

	if ( m_eMode == EModePosAndRate )
	{
		CconvDcdPosOnZone_PosOrgAndRate	aConv( 
			m_iContentPos , aTargetZone.getPos() , m_dTargetPosPerContent ) ;
		posRv  = aConv.Zone1PosFromZone2( posTarget ) ;
	}
	else if ( m_eMode == EModeZone )
	{
		CconvDcdPosOnZone_DcdZone	aConv( 
			CdDcdZone( m_iContentPos , m_iContentSize ),
			aTargetZone ) ;
		posRv  = aConv.Zone1PosFromZone2( posTarget ) ;
	}
	return posRv;
}

CdDcdZone CconvContentPosToTarget::ContentZoneFromTarget( 
		const CdDcdZone& zoneTarget , const CdDcdZone& aTargetZone ) 
{
	CdDcdZone	zoneRv  ; 

	//	プロパティの同期
	synchronizeProp( &aTargetZone ) ;


	if ( m_eMode == EModePosAndRate )
	{
		CconvDcdPosOnZone_PosOrgAndRate	aConv( 
			m_iContentPos , aTargetZone.getPos() , m_dTargetPosPerContent ) ;
		zoneRv =  aConv.Zone1FromZone2( zoneTarget ) ;
	}
	else if ( m_eMode == EModeZone )
	{
		CconvDcdPosOnZone_DcdZone	aConv( 
			CdDcdZone( m_iContentPos , m_iContentSize ),
			aTargetZone ) ;
		zoneRv =  aConv.Zone1FromZone2( zoneTarget ) ;
	}
	return zoneRv ;
}

} //namespace Pos
} //namespace DcdCd
} //namespace DcDrawLib
