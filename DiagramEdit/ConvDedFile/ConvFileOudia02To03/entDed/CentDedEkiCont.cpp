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
//	CentDedEkiCont.cpp
// ****************************************************************
*/
#include "stdafx.h"

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

#include "CentDedEkiCont.h"

// ----------------------------------------------------------------
//	CentDedEkiCont::ContKudari
// ----------------------------------------------------------------
int CentDedEkiCont::ContKudari::size()const 
{
	CentDedEkiCont* pAdaptee = (CentDedEkiCont*)( (char*)this - offsetof( CentDedEkiCont , CentDedEkiCont::m_xContKudari ) ) ;
	
	return pAdaptee->size() ;
}
CentDedEkiCont::CdDedEki CentDedEkiCont::ContKudari::get(int iEkiOrder )const 
{
	CentDedEkiCont* pAdaptee = (CentDedEkiCont*)( (char*)this - offsetof( CentDedEkiCont , CentDedEkiCont::m_xContKudari ) ) ;
	
	int iEkiIndex = pAdaptee->EkiIndexOfEkiOrder( Ressyahoukou_Kudari , iEkiOrder ) ;
	CentDedEki aCentDedEki = pAdaptee->m_CentDedEkiCont.get( iEkiIndex ) ;

	CentDedEkiCont::CdDedEki aCdDedEki( 
		aCentDedEki.getEkimei() , 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsuchaku || 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_KudariChaku , 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsuchaku || 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsu || 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_NoboriChaku ,
		aCentDedEki.getEkikibo() ,
		aCentDedEki.getKyoukaisen() ) ;

	if ( iEkiOrder == pAdaptee->size() - 1 ){
		//	終点駅では、駅時刻形式は『着発』以外なら、
		//	着時刻のみ表示とします。
		//	また、境界線属性はなしにします。
		if ( aCentDedEki.getEkijikokukeisiki() != CentDedEki::Jikokukeisiki_Hatsuchaku ){
			aCdDedEki.setChakujikokuHyouji( true ) ;
			aCdDedEki.setHatsujikokuHyouji( false ) ;
		}
		aCdDedEki.setKyoukaisen( false ) ;	
	}


	return ( aCdDedEki ) ;
	
}
// ----------------------------------------------------------------
//	CentDedEkiCont::ContNobori
// ----------------------------------------------------------------
int CentDedEkiCont::ContNobori::size()const 
{
	CentDedEkiCont* pAdaptee = (CentDedEkiCont*)( (char*)this - offsetof( CentDedEkiCont , CentDedEkiCont::m_xContNobori ) ) ;
	
	return pAdaptee->size() ;
}
CentDedEkiCont::CdDedEki CentDedEkiCont::ContNobori::get(int iEkiOrder )const 
{
	CentDedEkiCont* pAdaptee = (CentDedEkiCont*)( (char*)this - offsetof( CentDedEkiCont , CentDedEkiCont::m_xContNobori ) ) ;
	
	int iEkiIndex = pAdaptee->EkiIndexOfEkiOrder( Ressyahoukou_Nobori , iEkiOrder ) ;
	CentDedEki aCentDedEki = pAdaptee->m_CentDedEkiCont.get( iEkiIndex ) ;
	CentDedEki aCentDedEkiPrev ;
	if ( iEkiIndex > 0 ){
		aCentDedEkiPrev = pAdaptee->m_CentDedEkiCont.get( iEkiIndex - 1 ) ;
	}

	CentDedEkiCont::CdDedEki aCdDedEki( 
		aCentDedEki.getEkimei() , 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsuchaku || 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_NoboriChaku , 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsuchaku || 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsu || 
		aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_KudariChaku ,
		aCentDedEki.getEkikibo() ,
		aCentDedEkiPrev.getKyoukaisen() ) ;

	if ( iEkiOrder == pAdaptee->size() - 1 ){
		//	終点駅では、駅時刻形式は『着発』以外なら、
		//	着時刻のみ表示とします。
		//	また、境界線属性はなしにします。
		if ( aCentDedEki.getEkijikokukeisiki() != CentDedEki::Jikokukeisiki_Hatsuchaku ){
			aCdDedEki.setChakujikokuHyouji( true ) ;
			aCdDedEki.setHatsujikokuHyouji( false ) ;
		}
		aCdDedEki.setKyoukaisen( false ) ;	
	}


	return ( aCdDedEki ) ;
	
}
// ****************************************************************
//	CentDedEkiCont
// ****************************************************************
// ********************************
//	コンストラクタ
// ********************************
CentDedEkiCont::CentDedEkiCont() 
{
	m_pCaValueCont = new CaValueCont<CentDedEki>( &m_CentDedEkiCont ) ;
}
CentDedEkiCont::CentDedEkiCont( const CentDedEkiCont& value ) 
{
	m_pCaValueCont = new CaValueCont<CentDedEki>( &m_CentDedEkiCont ) ;
	m_CentDedEkiCont = value.m_CentDedEkiCont ;
}
CentDedEkiCont& CentDedEkiCont::operator=( const CentDedEkiCont& value ) 
{
	m_CentDedEkiCont = value.m_CentDedEkiCont ;
	return *this ;
}
CentDedEkiCont::~CentDedEkiCont() 
{
	delete m_pCaValueCont ;
}

// ********************************
//	CentDedEkiCont
// ********************************
	// ********************************
	//@name CentDedEkiCont-操作
	// ********************************
void CentDedEkiCont::getEkijikokukeisiki( 
		ERessyahoukou eRessyahoukou , int iEkiOrder ,
		int* piChaku , int* piHatsu )const 
{
	const IfContGet<CdDedEki>*	pIfContGet = getIfContGet( eRessyahoukou ) ;
	CdDedEki	aCdDedEki ;
	if ( iEkiOrder < pIfContGet->size() ){
		aCdDedEki = pIfContGet->get( iEkiOrder ) ;
	}
	if ( aCdDedEki.getChakujikokuHyouji() ){
		*piChaku = 1 ;
	}	else	{
		*piChaku = 0 ;
	}
	if ( aCdDedEki.getHatsujikokuHyouji() ){
		*piHatsu = 1 ;
	}	else	{
		*piHatsu = 0 ;
	}

}

int CentDedEkiCont::EkiIndexOfEkiOrder( 
	ERessyahoukou eRessyahoukou , int iEkiOrder )const 
{
	int iRv = iEkiOrder ;
	if ( eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = size() - 1 - iEkiOrder ;
	}
	return ( iRv ) ;
}
int CentDedEkiCont::EkiOrderOfEkiIndex(  
	ERessyahoukou eRessyahoukou , int iEkiIndex )const 
{
	int iRv = iEkiIndex ;
	if ( eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = size() - 1 - iEkiIndex ;
	}
	return ( iRv ) ;
}
