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
//	CaDcdTargetClip.cpp
// ****************************************************************
*/
#include "CaDcdTargetClip.h"
#include "CConverter_WinGdi.h"


// ****************************************************************
//	CaDcdTargetClip
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CaDcdTargetClip::CaDcdTargetClip( 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdZoneXy& zonexyZoneClip ) 
{
	m_zonexyZoneClip = zonexyZoneClip ;
	m_pIfDcdTarget = pIfDcdTarget ;
	
	// --------------------------------
	m_hRgnSid = NULL ;
	m_hRgnNew = NULL ;
	
}
CaDcdTargetClip::~CaDcdTargetClip()
{
	invalidate() ;
}

// ********************************
//	IfValidate
// ********************************
int CaDcdTargetClip::validate()
{
	int iRv = 1 ;
	
	if ( isValid() ){
		return ( 0 ) ;
	}
	// --------------------------------
	//	DCの既存のリージョンを保存
	// --------------------------------
	if ( iRv >= 0 ){
			m_hRgnSid = CreateRectRgn( 0 , 0 , 0 , 0 ) ;
			if ( m_hRgnSid == NULL ){
				iRv = -1 ;	//	HRGN の生成に失敗しました
			}
	}
	if ( iRv >= 0 ){
			int	iLi = GetClipRgn( getHdc() , m_hRgnSid ) ;
			if ( iLi == 0 ){
				DeleteObject( m_hRgnSid ) ;
				m_hRgnSid = NULL ;
			}	else if ( iLi < 0 ){
				iRv = -2 ;	//	DCのリージョン取得に失敗しました。
			}	else	{
				iRv += 0 ;
			}
	}
	//m_hRgnSid = それまでのクリップリージョン。
	//	それまでのＤＣにクリップリージョンがないなら、NULLです。

	// --------------------------------
	//	新しいリージョンを生成
	// --------------------------------
	if ( iRv >= 0 ){
			CdDcdZoneXy	zonexyZoneClip = m_zonexyZoneClip ;
			CConverter_WinGdi	aConverter ;
			zonexyZoneClip = aConverter.LPtoDP( m_zonexyZoneClip , getHdc() ) ;  
			//	SelectClipRgn() 関数は、
			//	リージョンの座標がデバイス単位で指定されているものと仮定します。

			m_hRgnNew = CreateRectRgn( zonexyZoneClip.getX().getPos()
									, zonexyZoneClip.getY().getPos()
									, zonexyZoneClip.getX().getEndPos()
									, zonexyZoneClip.getY().getEndPos() ) ;


			if ( m_hRgnNew == NULL ){
				iRv = -3 ;	//	HRGN の生成に失敗しました
			}
	}
	//m_hRgnNew = m_zonexyZoneClip で指定された領域の矩形のリージョン。
		
	if ( iRv >= 0 ){
			if ( m_hRgnSid != NULL ){
				if ( CombineRgn( m_hRgnNew , m_hRgnNew , m_hRgnSid , RGN_AND ) 
															== ERROR ){
					iRv = -4 ;	//	CombineRgn() に失敗しました
				}
			}
	}
	//m_hRgnNew = DcDrawRq() で指定された領域に、
	//	それまでのクリップリージョンを組み合わせたもの
	
	// --------------------------------
	//	新しいリージョンを生成
	// --------------------------------
	if ( iRv >= 0 ){
		if ( SelectClipRgn( getHdc() , m_hRgnNew ) == ERROR ){
			iRv = -5 ;	//	SelectClipRgn() に失敗
		}
	}



	return ( iRv ) ;
}

void CaDcdTargetClip::invalidate()
{
	SelectClipRgn( getHdc() , m_hRgnSid ) ;
	if ( m_hRgnNew != NULL ){
		DeleteObject( m_hRgnNew ) ;
		m_hRgnNew = NULL ;
	}
	if ( m_hRgnSid != NULL ){
		DeleteObject( m_hRgnSid ) ;
		m_hRgnSid = NULL ;
	}
	
	
}

bool CaDcdTargetClip::isValid()
{
	return ( m_hRgnNew != NULL ) ;
}

// ********************************
//	IfDcdTarget
// ********************************
HDC	CaDcdTargetClip::getHdc() 
{
	return ( m_pIfDcdTarget->getHdc() ) ;

}
CdDcdZoneXy CaDcdTargetClip::getZone() 
{
	return ( m_pIfDcdTarget->getZone()  ) ;
}
CdDcdZoneXy CaDcdTargetClip::getDrawableZone() 
{
	CdDcdZoneXy	zonexyCross( m_zonexyZoneClip.CrossZone( m_pIfDcdTarget->getDrawableZone() ) ) ;
	return ( zonexyCross ) ;
}

// ********************************
//	CaDcdTargetClip
// ********************************
bool CaDcdTargetClip::isDrawable() 
{
	CdDcdZoneXy	zonexyCross( m_zonexyZoneClip.CrossZone( m_pIfDcdTarget->getDrawableZone() ) ) ;
	if ( zonexyCross.getX().getSize() > 0 && zonexyCross.getY().getSize() > 0 ){
		return ( true ) ;
	}	
	return ( false ) ;
}
