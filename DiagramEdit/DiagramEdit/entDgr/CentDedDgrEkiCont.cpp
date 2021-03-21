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
//	CentDedDgrEkiCont.cpp
//	$Id: CentDedDgrEkiCont.cpp 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
*/
#include "stdafx.h"
#include "CentDedDgrEkiCont.h"

namespace entDgr{

// ----------------------------------------------------------------
//	CentDedDgrEkiCont::ContKudari
// ----------------------------------------------------------------
		// ********************************
		//	Mu< CentDedDgrEkiCont::CdDedDgrEki >
		// ********************************
int  CentDedDgrEkiCont::ContKudari::size()const 
{
	CentDedDgrEkiCont* pOuter = 
		(CentDedDgrEkiCont*)((char*)this - offsetof( CentDedDgrEkiCont , m_xContKudari ) ) ; 
	return pOuter->size() ;
}
CentDedDgrEkiCont::CdDedDgrEki CentDedDgrEkiCont::ContKudari::get(int iEkiOrder )const 
{
	CentDedDgrEkiCont* pOuter = 
		(CentDedDgrEkiCont*)((char*)this - offsetof( CentDedDgrEkiCont , m_xContKudari ) ) ; 

	int iEkiIndex = pOuter->EkiIndexOfEkiOrder( Ressyahoukou_Kudari , iEkiOrder ) ;
	const CentDedDgrEki*	pCentDedDgrEki = pOuter->getMuPtr()->get( iEkiIndex ) ;

	const std::string& strEkimei = pCentDedDgrEki->getEkimei() ;
	bool  bIsSyuyoueki = pCentDedDgrEki->getIsSyuyoueki() ;
	int iEkikanSaisyouSec = pCentDedDgrEki->getEkikanSaisyouSecKudari() ;
	int	iDiagramDgrYZahyouKyoriDefault = pCentDedDgrEki->getDgrYSizeEkikanDefault() ;
	CentDedDgrEki::EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyouji 
		= pCentDedDgrEki->getDiagramRessyajouhouHyoujiKudari() ;
	int iYZahyouSize = pCentDedDgrEki->getDgrYSize() ;
	int	iDgrYZahyouKyori = pCentDedDgrEki->getDgrYZahyouKyori() ;
	// --------------------------------
	CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki( 
		strEkimei ,
		bIsSyuyoueki ,
		iEkikanSaisyouSec ,
		iDiagramDgrYZahyouKyoriDefault ,
		eDiagramRessyajouhouHyouji ,
		iYZahyouSize ,
		iDgrYZahyouKyori ) ;
	return aCdDedDgrEki ;
}

// ----------------------------------------------------------------
//	CentDedDgrEkiCont::ContNobori
// ----------------------------------------------------------------
		// ********************************
		//	Mu< CentDedEkiCont::CdDedEki >
		// ********************************
int CentDedDgrEkiCont::ContNobori::size()const 
{
	CentDedDgrEkiCont* pOuter = 
		(CentDedDgrEkiCont*)((char*)this - offsetof( CentDedDgrEkiCont , m_xContNobori ) ) ; 
	return pOuter->size() ;
}
CentDedDgrEkiCont::CdDedDgrEki CentDedDgrEkiCont::ContNobori::get(int iEkiOrder )const 
{
	CentDedDgrEkiCont* pOuter = 
		(CentDedDgrEkiCont*)((char*)this - offsetof( CentDedDgrEkiCont , m_xContNobori ) ) ; 

	int iEkiIndex = pOuter->EkiIndexOfEkiOrder( Ressyahoukou_Nobori , iEkiOrder ) ;
	const CentDedDgrEki*	pCentDedDgrEki = pOuter->getMuPtr()->get( iEkiIndex ) ;

	int iEkiIndexForEkikanSaisyouSec = iEkiIndex-1 ;
	const CentDedDgrEki*	pCentDedDgrEkiForEkikanSaisyouSec = NULL ;
	if ( 0 <= iEkiIndexForEkikanSaisyouSec && 
		iEkiIndexForEkikanSaisyouSec < pOuter->size() ) 
	{
		pCentDedDgrEkiForEkikanSaisyouSec = pOuter->getMuPtr()->get( iEkiIndexForEkikanSaisyouSec ) ;
	}
	//pCentDedDgrEkiForEkikanSaisyouSec = 上り列車の駅間最小所要秒数・
	//	Y座標幅を取得するための、 CentDedDgrEki 。
	//	駅Indexは、-1 した値になります。

	// --------------------------------
	const std::string& strEkimei = pCentDedDgrEki->getEkimei() ;
	bool  bIsSyuyoueki = pCentDedDgrEki->getIsSyuyoueki() ;
	int iEkikanSaisyouSec = 0 ;
	int	iDiagramDgrYZahyouKyoriDefault = 0 ;
	if ( pCentDedDgrEkiForEkikanSaisyouSec != NULL )
	{
		iEkikanSaisyouSec = pCentDedDgrEkiForEkikanSaisyouSec->getEkikanSaisyouSecNobori() ;
		pCentDedDgrEkiForEkikanSaisyouSec->getDgrYSizeEkikanDefault() ;

	}
	CentDedDgrEki::EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyouji 
		= pCentDedDgrEki->getDiagramRessyajouhouHyoujiNobori() ;
	int iYZahyouSize = pCentDedDgrEki->getDgrYSize() ;

	int	iDgrYZahyouKyori = 0 ;
	if ( pCentDedDgrEkiForEkikanSaisyouSec != NULL )
	{
		iDgrYZahyouKyori = pCentDedDgrEkiForEkikanSaisyouSec->getDgrYZahyouKyori() ;
	}
	// --------------------------------
	CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki( 
		strEkimei ,
		bIsSyuyoueki ,
		iEkikanSaisyouSec ,
		iDiagramDgrYZahyouKyoriDefault ,
		eDiagramRessyajouhouHyouji ,
		iYZahyouSize ,
		iDgrYZahyouKyori ) ;
	return aCdDedDgrEki ;

}
	
CentDedDgrEkiCont::CentDedDgrEkiCont() 
{
}
CentDedDgrEkiCont::CentDedDgrEkiCont( const CentDedDgrEkiCont& value ) :
	super( value ) 
{
}
CentDedDgrEkiCont& CentDedDgrEkiCont::operator=( const CentDedDgrEkiCont& value ) 
{
	super::operator =( value ) ;
	return *this ;
}
CentDedDgrEkiCont::~CentDedDgrEkiCont() 
{
}

// ********************************
//	CentDedEkiCont
// ********************************
int CentDedDgrEkiCont::EkiIndexOfEkiOrder( ERessyahoukou eRessyahoukou , int iEkiOrder )const 
{
	int iRv = iEkiOrder ;
	if ( eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = size() - 1 - iEkiOrder ;
	}
	return ( iRv ) ;
}
int CentDedDgrEkiCont::EkiOrderOfEkiIndex(  ERessyahoukou eRessyahoukou , int iEkiIndex )const 
{
	int iRv = iEkiIndex ;
	if ( eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = size() - 1 - iEkiIndex ;
	}
	return ( iRv ) ;
};

} //namespace entDgr
