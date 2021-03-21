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
//	CDcdDiagram2.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "str\StrToInt.h"
#include "DcDraw\CDcdText.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CDcdLine.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDraw\CaDcdTargetClip.h"
#include "DcdCd\DcDrawProp/CdPenProp.h"
#include "LogMsg\LogMsg.h"

#include "CDcdDiagram2.h"
#include "..\DiagramEdit.h"

namespace ViewDiagram{

using namespace std ;
using namespace OuLib::Str;
// ****************************************************************
//	CDcdDiagram2
// ****************************************************************
	// --------------------------------
	//@name 下請関数
	// --------------------------------
CdDcdFreeLineProp	CDcdDiagram2::getCdLinePropNormal()const
{
	return CdDcdFreeLineProp( 1 , m_pCDcdDiagram->getDiaJikuColor() ) ;
};

CdDcdFreeLineProp	CDcdDiagram2::getCdLinePropBold()const
{
	return CdDcdFreeLineProp( 2 , m_pCDcdDiagram->getDiaJikuColor() ) ;
};	

CDcdText	CDcdDiagram2::getCDcdTextJikoku()const
{
	return CDcdText( "" , 
		CdDrawTextProp( m_fontpropDiaJikokuFont , m_colorDiaMojiColor ) ,
		"00" ) ;
};

CDcdText	CDcdDiagram2::getCDcdTextEkimei()const
{
	string strExtent ;
	for ( int idx = 0 ; idx < m_iEkimeiLength ; idx ++ ){
		strExtent += "岡" ;
	}
	//strExtent = 路線ファイルデータに保存されている値をもとにして、
	//	作成した、文字列幅の基準文字列です。

	return CDcdText( "" , 
		CdDrawTextProp( m_fontpropDiaEkimeiFont , m_colorDiaMojiColor ) ,
		strExtent ) ;
};

	// ********************************
	//	コンストラクタ
	// ********************************
CDcdDiagram2::CDcdDiagram2( 
		CentDedDgrDia*	pCentDedDgrDia , 
		const CdDedDispProp& aCdDedDispProp ) 
	: m_fontpropDiaEkimeiFont( 9 ,"ＭＳ ゴシック"  )
	, m_fontpropDiaJikokuFont( 9 ,"ＭＳ ゴシック"  )
	, m_colorDiaMojiColor( CdColorProp( 0 , 0 , 0 ) ) 
	, m_iEkimeiLength( 6 )
	, m_bHideIppanekiEkimei( false ) 
{
	m_pCDcdDiagram = new CDcdDiagram( 
		pCentDedDgrDia , 
		aCdDedDispProp ) ;
	m_fontpropDiaEkimeiFont = aCdDedDispProp.getDiaEkimeiFont() ;
	m_fontpropDiaJikokuFont = aCdDedDispProp.getDiaJikokuFont() ;
	m_colorDiaMojiColor = aCdDedDispProp.getDiaMojiColor() ;
}


CDcdDiagram2::CDcdDiagram2() 
	: m_fontpropDiaEkimeiFont( 9 ,"ＭＳ ゴシック"  )
	, m_fontpropDiaJikokuFont( 9 ,"ＭＳ ゴシック"  )
	, m_colorDiaMojiColor( CdColorProp( 0 , 0 , 0 ) ) 
	, m_iEkimeiLength( 6 )
	, m_bHideIppanekiEkimei( false ) 
{
	m_pCDcdDiagram = new CDcdDiagram() ;
}
CDcdDiagram2::~CDcdDiagram2() 
{
	if ( m_pCDcdDiagram != NULL ){
		delete m_pCDcdDiagram ;
		m_pCDcdDiagram = NULL ;
	}
}
	
	// ********************************
	//@name IfDcDraw
	// ********************************

bool CDcdDiagram2::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;
	CentDedDgrDia* pCentDedDgrDia = m_pCDcdDiagram->getCentDedDgrDia() ;

	// --------------------------------
	//	ダイヤグラムの各構成要素のサイズを計算
	// --------------------------------
	CdDcdFreeLineProp	linepropNormal( getCdLinePropNormal() ) ;
	CdDcdFreeLineProp	linepropBold( getCdLinePropBold() ) ;

	CDcdText	dcdtextJikoku( getCDcdTextJikoku() ) ;
	CdDcdSizeXy	sizeJikoku ;
	dcdtextJikoku.getItemSize( pIfDcdTarget , &sizeJikoku ) ;
	//dcdtextJikoku = 時刻テキスト描画を行うDcDrawオブジェクトを生成しました。
	//sizeJikoku = 時刻テキスト描画を行うDcDrawオブジェクトのサイズ(論理座標)

	CDcdText	dcdtextEkimei( getCDcdTextEkimei() ) ;
	CdDcdSizeXy	sizeEkimei ;
	dcdtextEkimei.getItemSize( pIfDcdTarget , &sizeEkimei ) ;
	//dcdtextEkimei = 駅名テキストの描画を行うDcDrawオブジェクトを生成しました。
	//sizeEkimei = 駅名テキストの描画を行うDcDrawオブジェクトのサイズ(論理座標)

	CdDcdZoneXy	zonexyDiagram = calcDiagramZoneDcd( pIfDcdTarget );
	//zonexyDiagram = ダイヤグラムの描画を行う領域（論理座標）
	// --------------------------------
	CaDcdTargetItemPosition	targetDiagram( pIfDcdTarget , zonexyDiagram ) ;
		//targetDiagram = ダイヤグラムの描画を行う領域のDcDrawオブジェクト
	

	// --------------------------------
	//	描画を行う領域の計算	
	// --------------------------------
	CdDcdZoneXy	zonexyCentDedDgrDia = getCentDedDgrDia()->getZone() ;
	//zonexyCentDedDgrDia = ダイヤグラムの範囲を、
	//	『ダイヤグラムエンティティ座標系』で保持します。
	//	X座標は24時間分、Y座標は起点から終点までを表します。

	// --------------------------------
	//	時の描画
	// --------------------------------
	{
		CdDcdZoneXy	zonexyJikokuDcd = calcJikokuZoneDcd( pIfDcdTarget );
		//zonexyEkimeiDcd = 時表示部分のDcDraw座標による範囲

		CaDcdTargetItemPosition	targetitemposJikoku( pIfDcdTarget , zonexyJikokuDcd ) ;
		CaDcdTargetClip targetJikoku( &targetitemposJikoku , zonexyJikokuDcd ) ;

		//	時刻表示は、ダイヤグラム起点時刻の次の正時から開始(4:59なら5:00、5:00なら5:00)
		DcdPos posDgrXJikokuhyoujiOrg = zonexyCentDedDgrDia.getX().getPos() ;
		{
			int iMod = zonexyCentDedDgrDia.getX().getPos() % ( 60 * 60 ); 
			if ( iMod > 0 )
			{
				posDgrXJikokuhyoujiOrg += ( 60 * 60 ) - iMod ;
			}
		}
		//posDgrXJikokuhyoujiOrg = 時刻表示の開始位置
		//	ダイヤグラム起点時刻の次の正時から開始(4:59なら5:00、5:00なら5:00)

		for ( DcdPos posDgrX = posDgrXJikokuhyoujiOrg; 
				posDgrX <= zonexyCentDedDgrDia.getX().getEndPos() ; 
				posDgrX += 60 * 60 )
		{
			//posDgrX = ダイヤグラムエンティティ座標での、
			//	時刻表示の位置

			//	時刻のテキストを設定
			dcdtextJikoku.setText( 
				stringOf( CdDedJikoku( posDgrX ).getHour() ) ) ;

			//	座標を、Dgr→Dcdに変換
			DcdPos posDcdX = XDgrToDcd( pIfDcdTarget , posDgrX ) ;
			{
				CdDcdZoneXy	zonexyDcdZoneXy( 
					CdDcdZone( posDcdX , sizeJikoku.getX() ) ,
					zonexyJikokuDcd.getY() ) ;
				CaDcdTargetItemPosition	aTarget( &targetJikoku , zonexyDcdZoneXy ) ;
				if ( aTarget.isDrawable() )
				{
					dcdtextJikoku.DcDraw( &aTarget ) ;
					bRv = true ;
				}
			}
		}
	}
	// --------------------------------
	//	駅名左の罫線
	//	駅名右の罫線
	// --------------------------------
	{

		CdDcdZoneXy	zonexyEkimeiDcd = calcEkimeiZoneDcd( pIfDcdTarget );
		//zonexyEkimeiDcd = 駅名表示部分のDcDraw座標による範囲

		CaDcdTargetItemPosition	targetitemposEkimei( pIfDcdTarget , zonexyEkimeiDcd ) ;
		CaDcdTargetClip targetEkimei( &targetitemposEkimei , zonexyEkimeiDcd ) ;

		// --------------------------------
		//CDcdLine を使った罫線描画
		// --------------------------------
		{

			CdDcdZone	zoneDcdY ;
			{
				CdDcdZone	zoneDgrY ;
				{
					const Mu<CentDedDgrEki>*	pCentDedDgrEkiCont = 
						pCentDedDgrDia->getCentDedDgrEkiCont() ;
					zoneDgrY.setBeginEndPos( 
						pCentDedDgrDia->getDgrYPosOfEki( 0 ) ,
						pCentDedDgrDia->getDgrYPosOfEki( 
							pCentDedDgrEkiCont->size() - 1  ) );
				}
				//zoneDgrY = 始発駅・終着駅のダイヤグラム座標によるY座標範囲
				zoneDcdY = YDgrToDcd( &targetEkimei , zoneDgrY ) ;
				//zoneDcdY = 始発駅・終着駅のDcDrawe座標によるY座標範囲

				zoneDcdY = zonexyEkimeiDcd.getY().CrossZone( zoneDcdY ) ;
				//zoneDcdY =	縦線を描画する範囲の DcDraw座標
			}
			//zoneDcdY =	縦線を描画する範囲の DcDraw座標



			CDcdLine	aCDcdLine( 
				CdPenProp( 
					linepropBold.getLogicalunitWidth() , 
					linepropBold.getColor() ) ) ;
			{
				CaDcdTargetItemPosition	aTargetItemPosition( 
					&targetEkimei ,
					CdDcdZoneXy( 
						CdDcdZone( 
							zonexyEkimeiDcd.getX().getPos() , 
							linepropBold.getLogicalunitWidth() ) ,
						zoneDcdY 
					) ) ;
				if ( aTargetItemPosition.isDrawable() )
				{
					aCDcdLine.DcDraw( &aTargetItemPosition ) ;
					bRv = true ;
				}
			}
			{
				CaDcdTargetItemPosition	aTargetItemPosition( 
					&targetEkimei ,
					CdDcdZoneXy( 
						CdDcdZone( 
							zonexyEkimeiDcd.getX().getEndPos() - linepropBold.getLogicalunitWidth(), 
							linepropBold.getLogicalunitWidth() ) ,
						zoneDcdY 
					) ) ;
				if ( aTargetItemPosition.isDrawable() )
				{
					aCDcdLine.DcDraw( &aTargetItemPosition ) ;
					bRv = true ;
				}
			}
		}
	}
	// --------------------------------
	//	横罫線・駅名の描画
	// --------------------------------
	{
		CdDcdZoneXy	zonexyEkimeiDcd = calcEkimeiZoneDcd( pIfDcdTarget );
		//zonexyEkimeiDcd = 駅名表示部分のDcDraw座標によるY座標範囲

		CaDcdTargetItemPosition	targetitemposEkimei( pIfDcdTarget , zonexyEkimeiDcd ) ;
		CaDcdTargetClip targetEkimei( &targetitemposEkimei , zonexyEkimeiDcd ) ;


		const Mu<CentDedDgrEki>* pCentDedDgrEkiCont = 
			getCentDedDgrDia()->getCentDedDgrEkiCont() ;
		// --------------------------------
		//	駅名下の罫線
		// --------------------------------
		for ( int iEkiIndex = 0 ; 
				iEkiIndex < pCentDedDgrEkiCont->size() ; 
				iEkiIndex ++ )
		{
			CentDedDgrEki	aCentDedDgrEki = 
				pCentDedDgrEkiCont->get( iEkiIndex ) ;
			DcdPos posDgrY = getCentDedDgrDia()->getDgrYPosOfEki( iEkiIndex ) ;
			CDcdFreeLine	aCDcdFreeLine ;
			if ( aCentDedDgrEki.getIsSyuyoueki() )
			{
				aCDcdFreeLine.setCdLineProp( linepropBold ) ;
			}
			else
			{
				aCDcdFreeLine.setCdLineProp( linepropNormal ) ;
			}
			//	座標を、Dgr→Dcdに変換
			DcdPos	posDcdY = YDgrToDcd( pIfDcdTarget , posDgrY ) ;
			CdDcdZone	zoneDcdX = zonexyEkimeiDcd.getX() ;
			
			//	下罫線描画
			if ( targetEkimei.getZone().getY().getPos() - 1 <= posDcdY &&
				 posDcdY < targetEkimei.getZone().getY().getEndPos() + 1 )
			{
				aCDcdFreeLine.setOrg( CdDcdPosXy( 
					zoneDcdX.getPos() , 
					posDcdY ) ) ;
				aCDcdFreeLine.setDst( CdDcdPosXy( 
					zoneDcdX.getEndPos() , 
					posDcdY ) ) ;
				aCDcdFreeLine.DcDraw( &targetEkimei ) ;
			}
		}
		// --------------------------------
		//	駅名
		// --------------------------------
		for ( int iEkiIndex = 0 ; 
				iEkiIndex < pCentDedDgrEkiCont->size() ; 
				iEkiIndex ++ )
		{
			CentDedDgrEki	aCentDedDgrEki = 
				pCentDedDgrEkiCont->get( iEkiIndex ) ;
			DcdPos posDgrY = getCentDedDgrDia()->getDgrYPosOfEki( iEkiIndex ) ;
			dcdtextEkimei.setText( aCentDedDgrEki.getEkimei() ) ;

			//	駅名を描画
			if ( aCentDedDgrEki.getIsSyuyoueki() ||
				iEkiIndex == 0 ||
				iEkiIndex == pCentDedDgrEkiCont->size() - 1 ||
				!m_bHideIppanekiEkimei  )
			{
				//	始発駅・終着駅・主要駅・あるいは
				//	「一般駅の駅名表示を隠す指定」が偽の場合に
				//	駅名を描画します。
				//	(「一般駅の駅名表示を隠す指定」 が真の場合、
				//	始発駅・終着駅以外の一般駅は
				//	駅名を描画しません。)



				//	座標を、Dgr→Dcdに変換
				DcdPos	posDcdY = YDgrToDcd( &targetEkimei , posDgrY ) ;
				{
					CdDcdZoneXy	zonexyTextEkimei( 
						CdDcdZone( 
							zonexyEkimeiDcd.getX().getPos() + 
								linepropBold.getLogicalunitWidth() ,
							zonexyEkimeiDcd.getX().getSize() - 
								linepropBold.getLogicalunitWidth() ) ,
						CdDcdZone( 
							posDcdY - sizeEkimei.getY() , 
							sizeEkimei.getY() ) 
					) ;
					CaDcdTargetItemPosition	aTarget( &targetEkimei , zonexyTextEkimei ) ;
					if ( aTarget.isDrawable() )
					{
						dcdtextEkimei.DcDraw( &aTarget ) ;
						bRv = true ;
					}
				}
			}
		}
	}

	// --------------------------------
	//	ダイヤの描画
	// --------------------------------
	{
		bRv |= m_pCDcdDiagram->DcDraw( &targetDiagram ) ;
	}
	return ( bRv ) ;
}
	
bool CDcdDiagram2::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	return ( false ) ;
}
	
// ********************************
//	CDcdDiagram
// ********************************
	// ********************************
	//@name CDcdDiagram-関連
	// ********************************
CentDedDgrDia*	CDcdDiagram2::getCentDedDgrDia() 
{
	return m_pCDcdDiagram->getCentDedDgrDia() ;
}
CDcdDiagram2& CDcdDiagram2::setCentDedDgrDia( CentDedDgrDia* value ) 
{
	m_pCDcdDiagram->setCentDedDgrDia( value ) ; 
	return *this ;
}
	// ********************************
	//@name CDcdDiagram-属性-CdDedDispProp から読み込み可能
	// ********************************
CdFontProp	CDcdDiagram2::getDiaRessyaFont()const 
{
	return m_pCDcdDiagram->getDiaRessyaFont() ;
}
CDcdDiagram2& CDcdDiagram2::setDiaRessyaFont( const CdFontProp& value ) 
{
	m_pCDcdDiagram->setDiaRessyaFont( value ) ;
	return *this ;
}
CdColorProp	CDcdDiagram2::getDiaHaikeiColor()const 
{
	return m_pCDcdDiagram->getDiaHaikeiColor() ;
}
CDcdDiagram2& CDcdDiagram2::setDiaHaikeiColor( CdColorProp value ) 
{
	m_pCDcdDiagram->setDiaHaikeiColor( value ) ;
	return *this ;
}

CdColorProp	CDcdDiagram2::getDiaJikuColor()const 
{
	return m_pCDcdDiagram->getDiaJikuColor() ;
}
CDcdDiagram2& CDcdDiagram2::setDiaJikuColor( CdColorProp value ) 
{
	m_pCDcdDiagram->setDiaJikuColor( value ) ;
	return *this ;
}
	// ********************************
	//@name CDcdDiagram-属性-CdDedDispProp にはないもの
	// ********************************
bool	CDcdDiagram2::getDisplayRessyabangou()const 
{
	return m_pCDcdDiagram->getDisplayRessyabangou() ;
}
CDcdDiagram2& CDcdDiagram2::setDisplayRessyabangou( bool value ) 
{
	m_pCDcdDiagram->setDisplayRessyabangou( value ) ;
	return *this ;
}
bool	CDcdDiagram2::getDisplayRessyamei()const 
{
	return m_pCDcdDiagram->getDisplayRessyamei() ;
}
CDcdDiagram2& CDcdDiagram2::setDisplayRessyamei( bool value ) 
{
	m_pCDcdDiagram->setDisplayRessyamei( value ) ;
	return *this ;
}

double CDcdDiagram2::getDcdPerDgrX( IfDcdTarget* pIfDcdTarget ) 
{
	return m_pCDcdDiagram->getDcdPerDgrX( pIfDcdTarget ) ;
}

void CDcdDiagram2::setDcdPerDgrX(  IfDcdTarget* pIfDcdTarget , double dDcdPerDgr ) 
{
	m_pCDcdDiagram->setDcdPerDgrX( pIfDcdTarget , dDcdPerDgr ) ;
}

double CDcdDiagram2::getDcdPerDgrY( IfDcdTarget* pIfDcdTarget ) 
{
	return m_pCDcdDiagram->getDcdPerDgrY( pIfDcdTarget ) ;
}

void CDcdDiagram2::setDcdPerDgrY( IfDcdTarget* pIfDcdTarget , double dDcdPerDgr ) 
{
	m_pCDcdDiagram->setDcdPerDgrY( pIfDcdTarget , dDcdPerDgr ) ;
}

int	CDcdDiagram2::getVlineMode()const 
{
	return m_pCDcdDiagram->getVlineMode() ;
}

CDcdDiagram2& CDcdDiagram2::setVlineMode( int value ) 
{
	m_pCDcdDiagram->setVlineMode( value ) ;
	return *this ;
}

bool CDcdDiagram2::getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const 
{
	return m_pCDcdDiagram->getDisplayRessyasen( eRessyahoukou ) ;
}
CDcdDiagram2& CDcdDiagram2::setDisplayRessyasen( ERessyahoukou eRessyahoukou , 
		bool value ) 
{
	m_pCDcdDiagram->setDisplayRessyasen( eRessyahoukou , value ) ;
	return *this ;
}

int CDcdDiagram2::getVlinePitch()const 
{
	return m_pCDcdDiagram->getVlinePitch() ;
}

int CDcdDiagram2::getVlineMiddlePitch()const 
{
	return m_pCDcdDiagram->getVlineMiddlePitch() ;
}

int CDcdDiagram2::getVlineBoldPitch()const 
{
	return m_pCDcdDiagram->getVlineBoldPitch() ;
}

int CDcdDiagram2::getVlineChoices( 
		Mui<CDcdDiagram::VLINE>* pContVLINE )const 
{
	return m_pCDcdDiagram->getVlineChoices( pContVLINE ) ;
}

	// ********************************
	//@name CDcdDiagram-操作
	// ********************************

CDcdDiagram2& CDcdDiagram2::readCdDedDispProp( const CdDedDispProp& value ) 
{
	m_pCDcdDiagram->readCdDedDispProp( value ) ;
	m_fontpropDiaEkimeiFont = value.getDiaEkimeiFont() ;
	m_fontpropDiaJikokuFont = value.getDiaJikokuFont() ;
	m_colorDiaMojiColor = value.getDiaMojiColor() ;
	m_iEkimeiLength = value.getEkimeiLength() ;
	return *this ;
}


CdDcdZoneXy	CDcdDiagram2::getZone_Dgr( IfDcdTarget* pIfDcdTarget )const 
{
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		calcDiagramZoneDcd( pIfDcdTarget ) ) ;

	return m_pCDcdDiagram->getZone_Dgr( &aTarget ) ;
}
CDcdDiagram2& CDcdDiagram2::setZone_Dgr( 
	IfDcdTarget* pIfDcdTarget , const CdDcdZoneXy& value ) 
{
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		calcDiagramZoneDcd( pIfDcdTarget ) ) ;

	m_pCDcdDiagram->setZone_Dgr( &aTarget , value ) ;

	return *this ;
}


int CDcdDiagram2::calcCentDedDgrRessyasenOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdPosXy& aCdDcdPosXy ,  
		int iMerginPixels ,
		ERessyahoukou *pERessyahoukou , 
		int *piRessyaIdx , 
		int *piRessyasenIdx ) 
{
	LogMsg( "CDcdDiagram2::calcCentDedDgrRessyasenOfPoint(,(%d,%d)) " ,
		aCdDcdPosXy.getX() , aCdDcdPosXy.getY() ) ;
 
	CdDcdZoneXy	zonexyDiagram = calcDiagramZoneDcd( pIfDcdTarget ) ;
	if ( zonexyDiagram.getX().getSize() <= 0 || zonexyDiagram.getY().getSize() <= 0 ){
		return 0 ;
	}

	CaDcdTargetItemPosition	targetDiagram( pIfDcdTarget , zonexyDiagram ) ;
	//targetDiagram = ダイヤグラムの描画を行う領域
	//zonexyDiagram = ダイヤグラムの描画を行う領域

	return m_pCDcdDiagram->calcCentDedDgrRessyasenOfPoint( 
		&targetDiagram ,
		aCdDcdPosXy ,  
		iMerginPixels , 
		pERessyahoukou , 
		piRessyaIdx , 
		piRessyasenIdx ) ;
}
int CDcdDiagram2::calcEkiOrderOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		ERessyahoukou eRessyahoukou ,
		DcdPos posY_Dcd )  
{
	CdDcdZoneXy	zonexyDiagram = calcDiagramZoneDcd( pIfDcdTarget ) ;
	if ( zonexyDiagram.getX().getSize() <= 0 || zonexyDiagram.getY().getSize() <= 0 ){
		return -1 ;
	}

	CaDcdTargetItemPosition	targetDiagram( pIfDcdTarget , zonexyDiagram ) ;
	//targetDiagram = ダイヤグラムの描画を行う領域
	//zonexyDiagram = ダイヤグラムの描画を行う領域

	return m_pCDcdDiagram->calcEkiOrderOfPoint( 
		&targetDiagram ,
		eRessyahoukou ,  
		posY_Dcd ) ;
}

int CDcdDiagram2::calcEkiIndexOfPoint( 
		IfDcdTarget* pIfDcdTarget ,
		DcdPos posY_Dcd ) 
{
	int iRv = -1 ;

	for ( int iEkiIndex = 0 ; 
		iRv == -1 && 
		iEkiIndex < getCentDedDgrDia()->getCentDedDgrEkiCont()->size() ;
		iEkiIndex ++ )
	{
		DcdPos	posDgrYPosOfEki = 
			getCentDedDgrDia()->getDgrYPosOfEki( iEkiIndex ) ;
		DcdPos	posDcdYPosOfEki = YDgrToDcd( pIfDcdTarget , posDgrYPosOfEki ) ;
		if ( posY_Dcd <= posDcdYPosOfEki )
		{
			iRv = iEkiIndex ;
		}
	}

	return iRv ;
}

	// ********************************
	//@name CDcdDiagram-ダイヤグラム座標と、IfDcdTarget 上の座標を変換
	// ********************************
DcdPos CDcdDiagram2::XDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrToDcd( &aTarget , posSrc ) ;
}

DcdPos CDcdDiagram2::YDgrToDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->YDgrToDcd( &aTarget , posSrc ) ;
}

DcdPos CDcdDiagram2::XDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrFromDcd( &aTarget , posSrc ) ;
}

DcdPos CDcdDiagram2::YDgrFromDcd( IfDcdTarget* pIfDcdTarget , DcdPos posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->YDgrFromDcd( &aTarget , posSrc ) ;
}

CdDcdZone CDcdDiagram2::XDgrToDcd( IfDcdTarget* pIfDcdTarget ,
		const CdDcdZone& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrToDcd( &aTarget , zoneSrc ) ;
}

CdDcdZone CDcdDiagram2::YDgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->YDgrToDcd( &aTarget , zoneSrc ) ;
}

CdDcdZone CDcdDiagram2::XDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrFromDcd( &aTarget , zoneSrc ) ;
}

CdDcdZone CDcdDiagram2::YDgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZone& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->XDgrFromDcd( &aTarget , zoneSrc ) ;
}

CdDcdPosXy CDcdDiagram2::DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->DgrToDcd( &aTarget , posSrc ) ;
}

CdDcdPosXy CDcdDiagram2::DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdPosXy& posSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->DgrFromDcd( &aTarget , posSrc ) ;
}


CdDcdZoneXy CDcdDiagram2::DgrToDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->DgrToDcd( &aTarget , zoneSrc ) ;
}

CdDcdZoneXy CDcdDiagram2::DgrFromDcd( IfDcdTarget* pIfDcdTarget , 
		const CdDcdZoneXy& zoneSrc ) 
{
	CdDcdZoneXy	zonexyDiagramZoneDcd = calcDiagramZoneDcd( pIfDcdTarget ) ;
	CaDcdTargetItemPosition	aTarget( 
		pIfDcdTarget , 
		zonexyDiagramZoneDcd ) ;
	return m_pCDcdDiagram->DgrFromDcd( &aTarget , zoneSrc ) ;
};



	// ********************************
	//@name CDcdDiagram2-属性
	// ********************************
CdFontProp	CDcdDiagram2::getDiaEkimeiFont()const 
{
	return m_fontpropDiaEkimeiFont ;
}
CDcdDiagram2& CDcdDiagram2::setDiaEkimeiFont( const CdFontProp& value ) 
{
	m_fontpropDiaEkimeiFont = value ;
	return *this ;
}
CdFontProp	CDcdDiagram2::getDiaJikokuFont()const 
{
	return m_fontpropDiaJikokuFont ;
}
CDcdDiagram2& CDcdDiagram2::setDiaJikokuFont( const CdFontProp& value ) 
{
	m_fontpropDiaJikokuFont = value ;
	return *this ;
}
CdColorProp	CDcdDiagram2::getDiaMojiColor()const 
{
	return m_colorDiaMojiColor ;
}
CDcdDiagram2& CDcdDiagram2::setDiaMojiColor( CdColorProp value ) 
{
	m_colorDiaMojiColor = value ;
	return *this ;
}
CDcdDiagram2& CDcdDiagram2::setEkimeiLength( int value ) 
{
	m_iEkimeiLength = value ;
	return *this ;
}

bool CDcdDiagram2::getHideIppanekiEkimei()const 
{
	return m_bHideIppanekiEkimei ;
}
CDcdDiagram2& CDcdDiagram2::setHideIppanekiEkimei( bool value )  
{
	m_bHideIppanekiEkimei = value ;
	return *this ;
}

	
	// ********************************
	//@name CDcdDiagram2-操作
	// ********************************

CdDcdZoneXy CDcdDiagram2::calcDiagramZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const 
{
	// --------------------------------
	//	駅名表示・時刻の領域
	// --------------------------------
	CdDcdZoneXy	zonexyEkimei = calcEkimeiZoneDcd( pIfDcdTarget ) ;
	CdDcdZoneXy	zonexyJikoku = calcJikokuZoneDcd( pIfDcdTarget ) ;
	
	// --------------------------------
	CdDcdZoneXy	zonexyDiagram ;
	zonexyDiagram.setX( zonexyJikoku.getX() ) ;
	zonexyDiagram.setY( CdDcdZone( 
		pIfDcdTarget->getZone().getY().getPos()  + zonexyJikoku.getY().getSize() , 
		pIfDcdTarget->getZone().getY().getSize() - zonexyJikoku.getY().getSize() 
	) ) ;
	if ( zonexyDiagram.getX().getSize() < 0 )
	{
		zonexyDiagram.setX( CdDcdZone( zonexyDiagram.getX().getPos() , 0 ) ) ;
	}
	if ( zonexyDiagram.getY().getSize() < 0 )
	{
		zonexyDiagram.setY( CdDcdZone( zonexyDiagram.getY().getPos() , 0 ) ) ;
	}

	return zonexyDiagram ;
}

CdDcdZoneXy CDcdDiagram2::calcEkimeiZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const 
{
	// --------------------------------
	//	駅名表示の幅
	// --------------------------------
	DcdSize	sizeEkimeiX = 0 ;
	{
		CdDcdFreeLineProp	linepropBold( getCdLinePropBold() ) ;

		// --------------------------------
		//	テキストの左の太線
		sizeEkimeiX += linepropBold.getLogicalunitWidth() ;

		// --------------------------------
		//	テキストの幅
		CdDcdSizeXy	sizeTextEkimei ;
		CDcdText	dcdtextEkimei( getCDcdTextEkimei() ) ;
		dcdtextEkimei.getItemSize( pIfDcdTarget , &sizeTextEkimei ) ;
		//dcdtextEkimei = 駅名の描画を行う DcDraw オブジェクト
		//sizeTextEkimei = 駅名の描画を行う DcDraw オブジェクトの大きさ

		sizeEkimeiX += sizeTextEkimei.getX() ;

		// --------------------------------
		//	テキストの右の太線
		sizeEkimeiX += linepropBold.getLogicalunitWidth() ;
	}
	//sizeEkimeiX = 駅名欄の幅

	// --------------------------------
	CdDcdZoneXy	zonexyEki ;
	zonexyEki.setX( CdDcdZone( 
		pIfDcdTarget->getZone().getX().getPos() ,
		sizeEkimeiX ) ) ; 
	zonexyEki.setY( CdDcdZone( 
		pIfDcdTarget->getZone().getY().getPos() , 
		pIfDcdTarget->getZone().getY().getSize() ) ) ;

	if ( zonexyEki.getX().getSize() < 0 )
	{
		zonexyEki.setX( CdDcdZone( zonexyEki.getX().getPos() , 0 ) ) ;
	}
	if ( zonexyEki.getY().getSize() < 0 )
	{
		zonexyEki.setY( CdDcdZone( zonexyEki.getY().getPos() , 0 ) ) ;
	}


	return zonexyEki ;
}
	
CdDcdZoneXy CDcdDiagram2::calcJikokuZoneDcd( 
			IfDcdTarget* pIfDcdTarget )const 
{
	// --------------------------------
	//	時刻表示の高さ
	// --------------------------------
	DcdSize	sizeJikokuY = 0 ;
	{
		CDcdText	dcdtextJikoku( getCDcdTextJikoku() ) ;
		CdDcdSizeXy	sizeTextJikoku ;
		dcdtextJikoku.getItemSize( pIfDcdTarget , &sizeTextJikoku ) ;

		//dcdtextJikoku = 時の描画を行う DcDraw オブジェクト
		//sizeTextJikoku = 時の描画を行う DcDraw オブジェクトの大きさ

		sizeJikokuY = sizeTextJikoku.getY() ;
	}
	//sizeJikokuY=時刻表示の高さ

	// --------------------------------
	//	駅名表示の幅
	// --------------------------------
	CdDcdZoneXy	zonexyEkimei = calcEkimeiZoneDcd( pIfDcdTarget ) ;

	// --------------------------------
	CdDcdZoneXy	zonexyJikoku ;
	zonexyJikoku.setX( CdDcdZone( 
		pIfDcdTarget->getZone().getX().getPos()  + zonexyEkimei.getX().getSize() ,
		pIfDcdTarget->getZone().getX().getSize() - zonexyEkimei.getX().getSize() ) ) ; 
	zonexyJikoku.setY( CdDcdZone( 
		pIfDcdTarget->getZone().getY().getPos() , 
		sizeJikokuY ) ) ;

	if ( zonexyJikoku.getX().getSize() < 0 )
	{
		zonexyJikoku.setX( CdDcdZone( zonexyJikoku.getX().getPos() , 0 ) ) ;
	}
	if ( zonexyJikoku.getY().getSize() < 0 )
	{
		zonexyJikoku.setY( CdDcdZone( zonexyJikoku.getY().getPos() , 0 ) ) ;
	}


	return zonexyJikoku ;
}

} //namespace ViewDiagram



