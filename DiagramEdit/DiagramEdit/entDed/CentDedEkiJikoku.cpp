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
//	CentDedEkiJikoku.cpp
//	$Id: CentDedEkiJikoku.cpp 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include "CentDedEkiJikoku.h"
#include "CentDedEkiJikokuCont.h"

namespace entDed{

// ****************************************************************
//	CentDedEkiJikoku::CXEkiJikokuTrackCont
// ****************************************************************
CentDedEkiJikoku*
CentDedEkiJikoku::CXEkiJikokuTrackCont::getEkiJikoku() 
{
	CentDedEkiJikoku* pOuter = (CentDedEkiJikoku*)( ((char*)this) - offsetof( CentDedEkiJikoku , m_EkiJikokuTrackCont ) ) ;
	return pOuter ;
}

const CentDedEkiJikoku* 
CentDedEkiJikoku::CXEkiJikokuTrackCont::getEkiJikoku()const 
{
	const CentDedEkiJikoku* pOuter = (const CentDedEkiJikoku*)( ((char*)this) - offsetof( CentDedEkiJikoku , m_EkiJikokuTrackCont ) ) ;
	return pOuter ;
}


// ****************************************************************
//	CentDedEkiJikoku
// ****************************************************************


// ********************************
//	コンストラクタ
// ********************************
CentDedEkiJikoku::CentDedEkiJikoku() :
		m_eEkiatsukai( Ekiatsukai_None ) 
{
};
CentDedEkiJikoku::CentDedEkiJikoku( 
		EEkiatsukai	eEkiatsukai , 
		CdDedJikoku	jikokuChakujikoku , 
		CdDedJikoku	jikokuHatsujikoku ) 
{
	set( eEkiatsukai , jikokuChakujikoku , jikokuHatsujikoku ) ;			
};

CentDedEkiJikoku& CentDedEkiJikoku::operator=( const CentDedEkiJikoku& value ) 
{
	CentDedEkiJikokuCont* pEkiJikokuCont = dynamic_cast<CentDedEkiJikokuCont*>( getParent() ) ;
	if ( pEkiJikokuCont != NULL )
	{
		int iResult = pEkiJikokuCont->setable( value , pEkiJikokuCont->getIndex( this ) ) ;
		if ( iResult < 0 ){
			throw( LException() ) ;
		}
	}
	super::operator=( value ) ; 

	// --------------------------------
	m_eEkiatsukai = value.m_eEkiatsukai ;
	m_jikokuChakujikoku = value.m_jikokuChakujikoku ;
	m_jikokuHatsujikoku = value.m_jikokuHatsujikoku ;
	m_EkiJikokuTrackCont = value.m_EkiJikokuTrackCont ;

	return *this ;
}

	// ********************************
	//@name CParentBase-操作
	// ********************************
void CentDedEkiJikoku::setParent( CParentBase* pParent )
{
	super::setParent( pParent ) ; 
	adjust() ;
}


	// ********************************
	//@name CentDedEkiJikoku-属性
	// ********************************
CentDedEkiJikoku::EEkiatsukai	CentDedEkiJikoku::getEkiatsukai()const{	return m_eEkiatsukai ;};

CentDedEkiJikoku& CentDedEkiJikoku::setEkiatsukai( CentDedEkiJikoku::EEkiatsukai value )
{
	m_eEkiatsukai = value ;
	if ( m_eEkiatsukai == Ekiatsukai_None ||
		m_eEkiatsukai == Ekiatsukai_Keiyunasi  ){
		m_jikokuChakujikoku.setNull() ;
		m_jikokuHatsujikoku.setNull() ;
	}

	//	駅扱が変化したとき):adjustを実行する
	//(駅扱が『運行なし』または『経由なし』の場合、
	//入線は、番線Index・入線時刻ともにNULL にするため)
	adjust() ;

	return *this ; 
} ;

CdDedJikoku	CentDedEkiJikoku::getChakujikoku( bool bHatsuIfNull )const
{
	if ( bHatsuIfNull && m_jikokuChakujikoku.isNull() ){
		return m_jikokuHatsujikoku ;
	}
	return m_jikokuChakujikoku ;
};

CentDedEkiJikoku& CentDedEkiJikoku::setChakujikoku( const CdDedJikoku& value )
{
	m_jikokuChakujikoku = value ; 

	//	- 	m_eEkiatsukai == Ekiatsukai_None ・
	//		または Ekiatsukai_Keiyunasi の駅に対して
	//		着・発のいずれかに 非Null 時刻を設定すると、this の
	//		m_eEkiatsukai = Ekiatsukai_Teisya となります。
	if ( 
		( m_eEkiatsukai == Ekiatsukai_None ||  
		  m_eEkiatsukai == Ekiatsukai_Keiyunasi ) && 
		( !m_jikokuChakujikoku.isNull() ||
		  ! m_jikokuHatsujikoku.isNull() )   ){
		m_eEkiatsukai = Ekiatsukai_Teisya ;

		//	駅扱が変化したとき):adjustを実行する
		//(駅扱が『運行なし』または『経由なし』の場合、
		//入線は、番線Index・入線時刻ともにNULL にするため)
		adjust() ;
	}
		
	return *this ;
};

CdDedJikoku	CentDedEkiJikoku::getHatsujikoku( bool bChakuIfNull )const{
	if ( bChakuIfNull && m_jikokuHatsujikoku.isNull() ){
		return m_jikokuChakujikoku ;
	}
	return m_jikokuHatsujikoku ;
};

CentDedEkiJikoku& CentDedEkiJikoku::setHatsujikoku( const CdDedJikoku& value )
{
	m_jikokuHatsujikoku = value ; 

	//- 	m_eEkiatsukai == Ekiatsukai_None ・
	//	または Ekiatsukai_Keiyunasi の駅に対して
	//	着・発のいずれかに 非Null 時刻を設定すると、this の
	//	m_eEkiatsukai = Ekiatsukai_Teisya となります。
	if ( 
		( m_eEkiatsukai == Ekiatsukai_None ||  
		  m_eEkiatsukai == Ekiatsukai_Keiyunasi ) && 
		( !m_jikokuChakujikoku.isNull() ||
		  ! m_jikokuHatsujikoku.isNull() )   ){
		m_eEkiatsukai = Ekiatsukai_Teisya ;

		//	駅扱が変化したとき):adjustを実行する
		//(駅扱が『運行なし』または『経由なし』の場合、
		//入線は、番線Index・入線時刻ともにNULL にするため)
		adjust() ;


	}
	return *this ;
};



CentDedEkiJikoku& CentDedEkiJikoku::set( 
		EEkiatsukai	eEkiatsukai , 
		CdDedJikoku	jikokuChakujikoku , 
		CdDedJikoku	jikokuHatsujikoku )
{
	m_eEkiatsukai = eEkiatsukai ; 
	m_jikokuChakujikoku =  jikokuChakujikoku ;
	m_jikokuHatsujikoku =  jikokuHatsujikoku ;


	if ( m_eEkiatsukai == Ekiatsukai_None ||
		m_eEkiatsukai == Ekiatsukai_Keiyunasi  )
	{
		m_jikokuChakujikoku.setNull() ;
		m_jikokuHatsujikoku.setNull() ;
	}
	//	駅扱が変化したとき):adjustを実行する
	//(駅扱が『運行なし』または『経由なし』の場合、
	//入線は、番線Index・入線時刻ともにNULL にするため)
	adjust() ;

	return ( *this ) ;
};

	// ********************************
	//@name CentDedEkiJikoku-操作
	// ********************************
void CentDedEkiJikoku::adjustByEkijikokukeisiki(
		bool bChakujikokuHyouji , bool bHatsujikokuHyouji ,
		bool bIsSihatsueki , bool bSyuuchakueki ) 
{
	//○[駅時刻形式に着時刻あり・発時刻なし、
	//  駅時刻に着時刻なし、発時刻あり]
	//  着時刻には発時刻をコピー、発時刻はNULL。
	if ( bChakujikokuHyouji && !bHatsujikokuHyouji && 
		m_jikokuChakujikoku.isNull() && !m_jikokuHatsujikoku.isNull() )
	{
		m_jikokuChakujikoku = m_jikokuHatsujikoku ;
		m_jikokuHatsujikoku.setNull() ;
	}
	//○[駅時刻形式に着時刻なし・発時刻あり
	//  駅時刻に着時刻あり、発時刻なし]
	//  発時刻には着時刻をコピー、着時刻はNULL。
	else if ( !bChakujikokuHyouji && bHatsujikokuHyouji && 
		!m_jikokuChakujikoku.isNull() && m_jikokuHatsujikoku.isNull() )
	{
		m_jikokuHatsujikoku = m_jikokuChakujikoku ;
		m_jikokuChakujikoku.setNull() ;
	}
	//○[駅が始発駅・
	//  駅時刻形式に着時刻あり・発時刻あり、
	//  駅時刻に着時刻あり、発時刻なし]
	//  発時刻には着時刻をコピー、着時刻はNULL。
	else if ( bIsSihatsueki && 
		bChakujikokuHyouji && bHatsujikokuHyouji && 
		!m_jikokuChakujikoku.isNull() && m_jikokuHatsujikoku.isNull() )
	{
		m_jikokuHatsujikoku = m_jikokuChakujikoku ;
		m_jikokuChakujikoku.setNull() ;
	}
	//○[駅が終着駅・
	//  駅時刻形式に着時刻あり・発時刻あり
	//  駅時刻に着時刻なし、発時刻あり]
	//  着時刻には発時刻をコピー、発時刻はNULL。
	else if ( bSyuuchakueki && 
		bChakujikokuHyouji && bHatsujikokuHyouji && 
		m_jikokuChakujikoku.isNull() && !m_jikokuHatsujikoku.isNull() )
	{
		m_jikokuChakujikoku = m_jikokuHatsujikoku ;
		m_jikokuHatsujikoku.setNull() ;
	}


}

void CentDedEkiJikoku::adjust() 
{
	m_EkiJikokuTrackCont.adjust() ;
}


} //namespace entDed
