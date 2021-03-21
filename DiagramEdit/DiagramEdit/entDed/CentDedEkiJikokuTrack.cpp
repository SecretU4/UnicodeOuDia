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
//$Id: CentDedEkiJikokuTrack.cpp 378 2016-11-16 21:10:54Z okm $

#include "stdafx.h"
#include "CentDedEkiJikokuTrack.h"
#include "CentDedEkiJikokuTrackCont.h"
#include "CentDedEki.h"
#include "CentDedEkiJikokuCont.h"
#include "CentDedRessya.h"
#include "CentDedRosen.h"

namespace entDed{


	// ********************************
	//	コンストラクタ
	// ********************************
CentDedEkiJikokuTrack::CentDedEkiJikokuTrack() 
{
}
CentDedEkiJikokuTrack::CentDedEkiJikokuTrack( 
		CdDedJikoku nyusenJikoku ,
		CentDedEkiTrackSelector track ) 
		: m_NyusenJikoku( nyusenJikoku )
		, m_Track( track )
{
}

CentDedEkiJikokuTrack& 
CentDedEkiJikokuTrack::operator=( const CentDedEkiJikokuTrack& value ) 
{
	CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = dynamic_cast<CentDedEkiJikokuTrackCont*>( getParent() ) ;
	if ( pEkiJikokuTrackCont != NULL )
	{
		int iResult = pEkiJikokuTrackCont->setable( value , pEkiJikokuTrackCont->getIndex( this ) ) ;
		if ( iResult < 0 ){
			throw( LException() ) ;
		}
	}
	super::operator=( value ) ; 
	// --------------------------------
	m_NyusenJikoku = value.m_NyusenJikoku ;
	m_Track = value.m_Track ;

	return *this ;
}
	// ********************************
	//@name CParentBase-操作
	// ********************************
void CentDedEkiJikokuTrack::setParent( CParentBase* pParent )
{
	super::setParent( pParent ) ;
	adjust() ;
}

	// ********************************
	//@name CentDedEkiJikokuTrack-属性
	// ********************************
CdDedJikoku CentDedEkiJikokuTrack::getNyusenJikoku()const
{ return m_NyusenJikoku ;}

void CentDedEkiJikokuTrack::setNyusenJikoku( const CdDedJikoku value )
{ 
	//△setNyusenJikoku:CentDedEkiJikokuTrack が『駅時刻』の一部である場合で、
	//　駅扱が『運行なし』または『経由なし』の場合、NULL以外の時刻の設定はエラー(例外)
	CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = dynamic_cast<CentDedEkiJikokuTrackCont*>( getParent() ) ;
	if ( pEkiJikokuTrackCont != NULL )
	{
		CentDedEkiJikoku* pEkiJikoku = pEkiJikokuTrackCont->getEkiJikoku() ;
		if ( pEkiJikoku != NULL )
		{
			if ( pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None
				|| pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				if ( !value.isNull() )
				{
					throw( LException() ) ;
				}
			}
		}
	}

	m_NyusenJikoku = value ;
}
	
CentDedEkiTrackSelector CentDedEkiJikokuTrack::getTrack()const
{ return m_Track ;}

void CentDedEkiJikokuTrack::setTrack( const CentDedEkiTrackSelector& value )
{ 
	// CentDedEkiJikokuTrack が路線(CentDedRosen)の一部である
	//場合で、番線指定子が『番線コンテナ』CentDedEkiTrackCont の要素に対応して
	//いない場合はエラー。(例外スロー)
	CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = dynamic_cast<CentDedEkiJikokuTrackCont*>( getParent() ) ;
	if ( pEkiJikokuTrackCont != NULL )
	{
	
		const CentDedEki* pEki = pEkiJikokuTrackCont->getEki() ;
		if ( pEki != NULL )
		{
			const CentDedEkiTrackCont* pEkTrackCont = pEki->getEkiTrackCont() ;
			if ( !value.isNull() && value.getiIndex() >= pEkTrackCont->size() )
			{
				throw( LException() ) ;	//	番線のIndexが、CentDedEkiTrackContの要素に対応していません
			}
		}
	}
	//△setEkiTrack:CentDedEkiJikokuTrack が『駅時刻』の一部である場合で、
	//　駅扱が『運行なし』または『経由なし』の場合、NULL以外の番線の設定はエラー(例外)
	if ( pEkiJikokuTrackCont != NULL )
	{
		CentDedEkiJikoku* pEkiJikoku = pEkiJikokuTrackCont->getEkiJikoku() ;
		if ( pEkiJikoku != NULL )
		{
			if ( pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None
				|| pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				if ( !value.isNull() )
				{
					throw( LException() ) ;
				}
			}
		}
	}

	// --------------------------------
	m_Track = value ;
}

	// ********************************
	//@name CentDedEkiJikokuTrack-操作
	// ********************************
void CentDedEkiJikokuTrack::adjust() 
{
	//△CentDedEkiJikokuTrack が路線(CentDedRosen)の一部である場合で、
	//番線指定子が『番線コンテナ』CentDedEkiTrackCont の要素に
	//対応していない場合は、『指定なし』に変更する
	CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = dynamic_cast<CentDedEkiJikokuTrackCont*>( getParent() ) ;
	if ( pEkiJikokuTrackCont != NULL )
	{
		const CentDedEki* pEki = pEkiJikokuTrackCont->getEki() ;
		if ( pEki != NULL )
		{
			const CentDedEkiTrackCont* pEkTrackCont = pEki->getEkiTrackCont() ;
			if ( !this->m_Track.isNull() && this->m_Track.getiIndex() >= pEkTrackCont->size() )
			{
				this->m_Track.setNull() ;	//	番線のIndexが、CentDedEkiTrackContの要素に対応していません
			}
		}
	}

	//△CentDedEkiJikokuTrack が『駅時刻』の一部である場合で、
	//　駅扱が『運行なし』または『経由なし』の場合、着時刻・発時刻はNULL。
	//　入線は、番線Index・入線時刻ともにNULLを設定する。
	if ( pEkiJikokuTrackCont != NULL )
	{
		CentDedEkiJikoku* pEkiJikoku = pEkiJikokuTrackCont->getEkiJikoku() ;
		if ( pEkiJikoku != NULL )
		{
			if ( pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None
				|| pEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				m_Track.setNull() ;
				m_NyusenJikoku.setNull() ;
			}
		}
	}
}
	
	
	// ********************************
	//@name CentDedRosen-子オブジェクトの増減の通知
	// ********************************
void CentDedEkiJikokuTrack::onEkiTrackInsert( int iEkiTrackIndex )
{
	//△番線の追加(OnInsertEkiTrack):駅時刻入線オブジェクトの番線指定子の指定
	//方式がインデクスの場合、インデクスは、コンテナへの追加に合わせてシフトさせる。
	if ( !m_Track.isNull() && m_Track.getiIndex() >= iEkiTrackIndex )
	{
		m_Track.setIndex( m_Track.getiIndex() + 1 ) ;
	}
}

void CentDedEkiJikokuTrack::onEkiTrackErase( int iEkiTrackIndex )
{
	//△番線の削除(OnEraseEkiTrack):駅時刻入線オブジェクトの番線指定子の指定方式
	//がインデクスの場合、インデクスは、コンテナへの削除に合わせてシフトさせる。
	//　駅時刻入線オブジェクトの番線指定子の指定方式がインデクスで、その
	// インデクスが削除対象のものである場合、『指定なし』に変更する
	if ( !m_Track.isNull() )
	{
		if ( m_Track.getiIndex() > iEkiTrackIndex )
		{
			m_Track.setIndex( m_Track.getiIndex() - 1 ) ;
		}
		else if ( m_Track.getiIndex() == iEkiTrackIndex )
		{
			m_Track.setNull() ;
		}
	}
}









} //namespace entDed


