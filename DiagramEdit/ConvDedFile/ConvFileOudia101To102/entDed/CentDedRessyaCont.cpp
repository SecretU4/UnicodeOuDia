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
//	CentDedRessyaCont.cpp
// ****************************************************************
*/
/** @file*/

#include "stdafx.h"
#include <algorithm>
#include "Mu\CMup_deque.h"
#include "Mu\CaMui.h"
#include "str\strtoint.h"
#include "logmsg\LogMsg.h"
#include "CentDedRessyaCont.h"
using namespace std ;

//#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//#endif


// ****************************************************************
//	CentDedRessyaCont
// ****************************************************************

// ********************************
//	コンストラクタ
// ********************************
CentDedRessyaCont::CentDedRessyaCont( 
		int iEkiCount ,
		ERessyahoukou eRessyahoukou , 
		int iRessyasyubetsuCount )
	:
	 m_iEkiCount( iEkiCount ) 
	, m_eRessyahoukou( eRessyahoukou )
	, m_iRessyasyubetsuCount( iRessyasyubetsuCount ) 
{
}


CentDedRessyaCont::CentDedRessyaCont( const CentDedRessyaCont& value )
	: super( value )
	, m_iEkiCount( value.m_iEkiCount ) 
	, m_eRessyahoukou( value.m_eRessyahoukou ) 
	, m_iRessyasyubetsuCount( value.m_iRessyasyubetsuCount ) 
{
}
	
CentDedRessyaCont& CentDedRessyaCont::operator=( const CentDedRessyaCont& value )
{
	//	保持している列車を、すべて破棄します。
	erase( 0 , INT_MAX ) ;

	//	value の列車を、thisにコピーしています。
	CaMui< CentDedRessya >	aCaCont_this( this ) ;
	aCaCont_this.insert( &value ) ;

	return *this ;
}

CentDedRessyaCont::~CentDedRessyaCont()
{
	//	コンテナが保持しているポインタの要素は
	//	erase()->onErase() により、
	//	delete で削除しなくてはなりません。
	erase( 0 , INT_MAX ) ;
}

// ********************************
//	CentDedRessyaCont
// ********************************
int CentDedRessyaCont::insertBlank( int iIndex )
{
	return ( super::insert( CentDedRessya( m_iEkiCount , m_eRessyahoukou ) , iIndex ) ) ;
}
	

int CentDedRessyaCont::EkiIndexOfEkiOrder( int iEkiOrder )const 
{
	int iRv = iEkiOrder ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_iEkiCount - 1 - iEkiOrder ;
	}
	return ( iRv ) ;
}

int CentDedRessyaCont::EkiOrderOfEkiIndex( int iEkiIndex )const 
{
	int iRv = iEkiIndex ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_iEkiCount - 1 - iEkiIndex ;
	}
	return ( iRv ) ;
}

int CentDedRessyaCont::findEkikanSaisyouSec( 
		int iEkiOrder , 
		int* pidxRessya )const 
{
	// --------------------------------
			int iSaisyouSyouSecTeisya = -1 ;
			//iSaisyouSyouSecTeisya = 
			//	iEkiiIndex ・ iEkiIndex + 1 の両駅に停車する列車のうちの、
			//	最小駅間所要秒数 
			int iSaisyouSyouSec = -1 ;
			//iSaisyouSyouSec = 
			//	iEkiiIndex ・ iEkiIndex + 1 の最小駅間所要秒数
			//	片方・または両駅が通過駅の列車を含みます。

			int iSaisyouSyouSecTeisyaRessyaIdx = -1 ;
			//iSaisyouSyouSecTeisyaRessyaIdx = 
			//	iSaisyouSyouSecTeisya に対応する列車Index 
			int iSaisyouSyouSecRessyaIdx = -1 ;
			//iSaisyouSyouSecRessyaIdx = 
			//	iSaisyouSyouSec に対応する列車Index 
			
			const Mu<const CentDedRessya*>* pCentDedRessyaContGet =
				this->getMuPtr() ;
			if ( 0 <= iEkiOrder && iEkiOrder < this->getEkiCount() - 1 ){
				int iRessyaIndex = 0 ;
				for ( iRessyaIndex = 0 ; 
						iRessyaIndex < this->size() ; 
						iRessyaIndex ++ ){
					const CentDedRessya* pCentDedRessya = 
						pCentDedRessyaContGet->get( iRessyaIndex ) ;
					CentDedEkiJikoku aEkiJikokuCurr = 
						pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
					CentDedEkiJikoku aEkiJikokuNext = 
						pCentDedRessya->getCentDedEkiJikoku( iEkiOrder + 1 ) ;

					CdDedJikoku	jikokuHatsu = 
						aEkiJikokuCurr.getHatsujikoku( true ) ;
					CdDedJikoku	jikokuChaku = 
						aEkiJikokuNext.getChakujikoku( true ) ;
					if ( !jikokuHatsu.isNull() && !jikokuChaku.isNull() ){
						int iSyoyouSec = jikokuChaku.subJikoku( jikokuHatsu ) ;
						if ( iSaisyouSyouSec == -1 || 
								iSaisyouSyouSec > iSyoyouSec ){
							iSaisyouSyouSec = iSyoyouSec ;
							iSaisyouSyouSecRessyaIdx = iRessyaIndex ;
						}
						
						if ( aEkiJikokuCurr.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Teisya && 
							aEkiJikokuNext.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Teisya ){
							if ( iSaisyouSyouSecTeisya == -1 || 
									iSaisyouSyouSecTeisya > iSyoyouSec ){
								iSaisyouSyouSecTeisya = iSyoyouSec ;
								iSaisyouSyouSecTeisyaRessyaIdx = iRessyaIndex ;
							}
						} 
					}
					
				}
			}
			LogMsg( "CentDedRessyaCont::findEkikanSaisyouSec( iEkiOrder=%d )"
				" iSaisyouSyoyouSecTeisya=%d RessyaIdx=%d "
				" iSaisyouSyoyouSec=%d RessyaIdx=%d" , 
				iEkiOrder , 
				iSaisyouSyouSecTeisya ,
				iSaisyouSyouSecTeisyaRessyaIdx , 
				iSaisyouSyouSec ,
				iSaisyouSyouSecRessyaIdx ) ; 

			if ( iSaisyouSyouSecTeisya >= 0 ){
				iSaisyouSyouSec = iSaisyouSyouSecTeisya ;
				iSaisyouSyouSecRessyaIdx = iSaisyouSyouSecTeisyaRessyaIdx ;
			}
			if ( iSaisyouSyouSec < 0 ){
					iSaisyouSyouSec = 0 ;
			}
			// --------------------------------
			if ( pidxRessya != NULL ){
				*pidxRessya = iSaisyouSyouSecRessyaIdx ;
			}
			return ( iSaisyouSyouSec ) ;

}



/**
	CentDedRessyaCont::sort() に使用する
	並べかえ用駅時刻オブジェクト。
*/
class CdRessyaForSort_Ekijikoku
{
public:
	/**
		CdRessyaForSort_Ekijikoku の比較を行う関数オブジェクトです。
	*/
	class CCompareFunction
	{
		/**
		ダイヤグラム起点時刻を指定してください。
		この関数は、ソート時に、この値を最も小さい時刻と
		みなします。
		(例：この時刻に5:00が指定された場合は、5:00<23:59<0:00<4:59 として比較を行います)
		*/
		CdDedJikoku m_jikokuKitenJikoku ;
	public:
		CCompareFunction( 
			const CdDedJikoku& jikokuKitenJikoku ) 
			: m_jikokuKitenJikoku( jikokuKitenJikoku )
		{
		};
		/**
		@return
			left < right なら真です。

		@note
		  比較基準は、
			- 駅時刻がNULLでないものとNULLのものとでは、NULLでないものが先。
			- Ekijikokuの小さいほうが先。
			- Ekijikokuが同じなら、着時刻が先。
			- Ekijikokuも着/発も同じならRessyaIdxの小さいほうが先。
		*/
		bool operator()( 
			const CdRessyaForSort_Ekijikoku& left , 
			const CdRessyaForSort_Ekijikoku& right )
		{
			// --------------------------------
			//	片方がNULLの場合の比較
			// --------------------------------
			if ( !left.getJikoku().isNull() && right.getJikoku().isNull() )
			{
				//	leftはNULLで、rightは非NULL
				return true ;
			}
			else if ( left.getJikoku().isNull() && !right.getJikoku().isNull() )
			{
				//	leftは非NULLで、rightはNULL
				return false ;
			}
			// --------------------------------
			//	m_Jikoku はどちらもNULLではない・もしくはどちらもNULL
			//	m_Jikoku は等しい
			// --------------------------------
			int iResult = left.getJikoku().compare( right.getJikoku() , m_jikokuKitenJikoku ) ;
			if ( iResult == -1 )
			{
				return true ;
			}
			else if ( iResult == 1 )
			{
				return false ;
			}

			// --------------------------------
			//	m_Jikoku は等しい
			//	Ekijikokuが同じなら、着時刻が先。
			// --------------------------------
			if ( !left.getIsHatsuJikoku() &&
				right.getIsHatsuJikoku() )
			{
				return true ;
			}
			else if ( left.getIsHatsuJikoku() != right.getIsHatsuJikoku() )
			{
				return false ;
			}
			
			// --------------------------------
			// m_Jikoku , m_bIsHatsuJikoku は等しい
			//	- Ekijikokuも着/発も同じならRessyaIdxの小さいほうが先。
			// --------------------------------
			if ( left.getRessyaIdx() < right.getRessyaIdx() )
			{
				return true ;
			}
			return false ;
		}

	};

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/** 列車インデクス */
	int m_iRessyaIdx ;

	/** 駅時刻 */
	CdDedJikoku m_Jikoku ;
	/** 
	-	false : m_Jikoku は、着時刻
	-	true  : m_Jikoku は、発時刻
	*/
	bool	m_bIsHatsuJikoku ;
	///@}

public:
	CdRessyaForSort_Ekijikoku( 
		int iRessyaIdx , 
		const CdDedJikoku& aJikoku , 
		bool bIsHatsuJikoku ) 
		: m_iRessyaIdx( iRessyaIdx ) 
		, m_Jikoku( aJikoku ) 
		, m_bIsHatsuJikoku( bIsHatsuJikoku ){} ;
	CdRessyaForSort_Ekijikoku()
		: m_iRessyaIdx( 0 ) 
		, m_Jikoku() 
		, m_bIsHatsuJikoku( false ){} ;


	// ********************************
	///@name 属性
	// ********************************
	///@{
	int getRessyaIdx()const{	return m_iRessyaIdx ;};
	void setRessyaIdx( int value ){	m_iRessyaIdx = value ;};
	CdDedJikoku getJikoku()const{	return m_Jikoku ;};
	bool getIsHatsuJikoku()const{	return m_bIsHatsuJikoku ;};
	///@}

};
/**
	CentDedRessyaCont::sort() に使用する
	並べかえ用列車オブジェクト
*/
class CdRessyaForSort_Ressya
{
public:
	/**
		CdRessyaForSort の比較を行う関数オブジェクトです。
	*/
	class CCompareFunction
	{
	public:
		CCompareFunction( ) 
		{
		};
		/**
		@return
			left < right なら真です。

		@note
		  比較基準は、
			- NULLでないものとNULLのものとでは、NULLでないものが先。
			- 列車種別Indexの小さいほうが先。
			- 列車名が辞書順で早い方が先。
			- 号数を整数化した場合に早い方が先。
			- 号数が辞書順で早い方が先。
		*/
		bool operator()( 
			const CdRessyaForSort_Ressya& left , 
			const CdRessyaForSort_Ressya& right )
		{
			// --------------------------------
			//	片方がNULLの場合の比較
			//	- NULLでないものとNULLのものとでは、NULLでないものが先。
			// --------------------------------
			if ( !left.getIsNull() && right.getIsNull() )
			{
				//	leftはNULLで、rightは非NULL
				return true ;
			}
			else if ( left.getIsNull() && !right.getIsNull() )
			{
				//	leftは非NULLで、rightはNULL
				return false ;
			}
			// --------------------------------
			//	- 列車種別Indexの小さいほうが先。
			// --------------------------------
			if ( left.getRessyasyubetsuIndex() < right.getRessyasyubetsuIndex() )
			{
				return true ;
			}
			else if ( left.getRessyasyubetsuIndex() > right.getRessyasyubetsuIndex() )
			{
				return false ;
			}

			// --------------------------------
			//	- 列車名が辞書順で早い方が先。
			// --------------------------------
			if ( left.getRessyamei() < right.getRessyamei() )
			{
				return true ;
			}
			else if ( left.getRessyamei() > right.getRessyamei() )
			{
				return false ;
			}

			// --------------------------------
			//	- 号数を整数化した場合に早い方が先。
			// --------------------------------
			{
				int iLeftGousuu = OuLib::intOf( left.getGousuu() ) ;
				int iRightGousuu = OuLib::intOf( right.getGousuu() ) ;
				if ( iLeftGousuu < iRightGousuu )
				{
					return true ;
				}
				else if ( iLeftGousuu > iRightGousuu )
				{
					return false ;
				}
			}
			// --------------------------------
			//	- 号数が辞書順で早い方が先。
			// --------------------------------
			if ( left.getGousuu()  < right.getGousuu() )
			{
				return true ;
			}
			return false ;
		}

	};

private:
	// ********************************
	///@name 属性
	// ********************************
	///@{
	/** 列車インデクス */
	int m_iRessyaIdx ;
	/**
		この列車が『Null状態』なら真、
		有効な列車属性を保持しているのなら偽です。
		
		この属性が真の場合、属性 
		-	m_iRessyasyubetsuIndex,
		-	m_strRessyabangou ;
		-	m_strRessyamei ;
		-	m_strGousuu ;
		-	m_strBikou ;
	
		および、
			m_CentDedEkiJikokuCont に格納されている 
		CentDedEkiJikoku は、意味を持ちません。
		
		規定値は true です。
		set...() メソッドで、m_eRessyahoukou 以外の
		いずれかの属性を設定したときには、
		自動的に偽に変わります。
		clear() で、真となります。
	 */
	bool m_bIsNull ;

	/**
		この列車の『列車種別』を、
		『列車種別Index』で保持します。
		
		規定値は 0 です。
	*/
	int	m_iRessyasyubetsuIndex ;
	
	/**
		この列車の『列車名』。
		
		規定値は空文字列です。
	 */
	string m_strRessyamei ;
	
	/**
		この列車の『号数』。
		
		規定値は空文字列です。
	 */
	string m_strGousuu ;
	///@}
public:
	CdRessyaForSort_Ressya( 
		int iRessyaIdx , 
		bool bIsNull ,
		int	iRessyasyubetsuIndex ,
		const string& strRessyamei ,
		const string& strGousuu )
		: m_iRessyaIdx( iRessyaIdx ) 
		, m_bIsNull( bIsNull )
		, m_iRessyasyubetsuIndex( iRessyasyubetsuIndex )
		, m_strRessyamei( strRessyamei )
		, m_strGousuu( strGousuu ){} ;
	CdRessyaForSort_Ressya()
		: m_iRessyaIdx( 0 ) 
		, m_bIsNull( true )
		, m_iRessyasyubetsuIndex( 0 )
		, m_strRessyamei()
		, m_strGousuu(){} ;
	// ********************************
	///@name 属性
	// ********************************
	///@{
	int getRessyaIdx()const{	return m_iRessyaIdx ;};
	void setRessyaIdx( int value ){	m_iRessyaIdx = value ;};
	bool getIsNull()const{	return m_bIsNull ;};
	int	getRessyasyubetsuIndex()const{	return m_iRessyasyubetsuIndex ;};
	string getRessyamei()const{	return m_strRessyamei ;};
	string getGousuu()const{	return m_strGousuu ;};
	///@}
};	


int CentDedRessyaCont::findTrainToDirect(
		int idxRessya , 
		int iEkiOrder  )const 
{
	const CentDedRessya* pCentDedRessyaSyuuchaku = getMuPtr()->get( idxRessya ) ;
	CdDedJikoku jikokuSyuuchaku ;
	{
		int iEkiOrderSyuuchaku = pCentDedRessyaSyuuchaku->getRunLastEkiOrder() ;
		jikokuSyuuchaku = pCentDedRessyaSyuuchaku->getCentDedEkiJikoku( iEkiOrderSyuuchaku ).getChakujikoku( true ) ;
	}
	//jikokuSyuuchaku = this列車の終着駅の着時刻（NULLの場合もあります）

	int iRv = -1 ;
	for ( idxRessya ++ ; iRv == -1 && idxRessya  < getMuPtr()->size() ; idxRessya ++ )
	{
		const CentDedRessya* pCentDedRessyaSihatsu = getMuPtr()->get( idxRessya ) ;
		//	  - ・フォーカスのある列車(途中駅止まりの列車)と同じ列車種別
		if ( pCentDedRessyaSyuuchaku->getRessyasyubetsuIndex() == 
			pCentDedRessyaSihatsu->getRessyasyubetsuIndex() )
		{
			//	  - ・フォーカスのある駅を始発駅とする列車
			if ( iEkiOrder == pCentDedRessyaSihatsu->getRunFirstEkiOrder() )
			{
				//	  - ・終着列車の着時刻も始発駅の発時刻も指定されている場合は、
				//	  - ・始発駅の発時刻が、終着列車の着時刻から12時間以内
				//	  - ・終着列車の着時刻・始発駅の発時刻のどちらかが欠けている場合は、
				//		無条件に直通化の対象となります。
				CdDedJikoku jikokuSihatsu = pCentDedRessyaSihatsu->getCentDedEkiJikoku( iEkiOrder ).getHatsujikoku( true ) ;
				if ( !jikokuSyuuchaku.isNull() && !jikokuSihatsu.isNull() )
				{
					CdDedJikan aJikan = jikokuSihatsu.subJikoku( jikokuSyuuchaku ) ;
					if ( CdDedJikan() <= aJikan )
					{
						iRv = idxRessya ;
					} 
				}
				else
				{
					//	  - ・始発駅の発時刻が、終着列車の着時刻から12時間以内
					iRv = idxRessya ;
				}
			}
		}
	}
	return iRv ;
}

void CentDedRessyaCont::adjustByEkijikokukeisiki(
		int iEkiOrder ,
		bool bChakujikokuHyouji , bool bHatsujikokuHyouji ) 
{
	for ( int idxRessya = 0 ; idxRessya < size() ; idxRessya ++ )
	{
		CentDedRessya* pRessya = getMuPtr()->get( idxRessya ) ;
		pRessya->adjustByEkijikokukeisiki( 
			iEkiOrder ,
			bChakujikokuHyouji , bHatsujikokuHyouji ) ;
	}
}


// --------------------------------
//@name CentDedRessya 内の 
//	CentDedEkiJikoku を増減
// --------------------------------
int CentDedRessyaCont::onSetCentDedEki( const Mu<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder ) 
{
	int iRv = 0 ;

	Mu<CentDedRessya*>*	pIfContGet = getMuPtr() ;
	if ( iRv >= 0 ){
		int idxRessya = 0 ;
		for ( idxRessya = 0 ; 
				idxRessya < pIfContGet->size() ;
				idxRessya ++ ){
			CentDedRessya*	pCentDedRessya = pIfContGet->get( idxRessya ) ;

			iRv = pCentDedRessya->onSetCentDedEki( 
					pCentDedEkiCont , 
					iEkiOrder ) ;
				//-1 ; // インデクスが不正です。 
		}
	}
	return ( iRv ) ;
}

int CentDedRessyaCont::insertCentDedEkiJikoku(	int iEkiOrder ) 
{
	int iRv = 0 ;

	Mu<CentDedRessya*>*	pIfContGet = getMuPtr() ;
	if ( iRv >= 0 ){
		m_iEkiCount ++ ;
		int idxRessya = 0 ;
		for ( idxRessya = 0 ; 
				idxRessya < pIfContGet->size() ;
				idxRessya ++ ){
			CentDedRessya*	pCentDedRessya = pIfContGet->get( idxRessya ) ;

			iRv = pCentDedRessya->insertCentDedEkiJikoku( 
					CentDedEkiJikoku() , 
					iEkiOrder ) ;
				//-1 ; // インデクスが不正です。 
		}
	}
	return ( iRv ) ;
}
	
int CentDedRessyaCont::eraseCentDedEkiJikoku( int iEkiOrder ) 
{
	int iRv = 0 ;
	Mu<CentDedRessya*>*	pIfContGet = getMuPtr() ;
	if ( iRv >= 0 ){
		m_iEkiCount -- ;

		int idxRessya = 0 ;
		for ( idxRessya = 0 ; 
				idxRessya < pIfContGet->size() ;
				idxRessya ++ ){
			CentDedRessya*	pCentDedRessya = pIfContGet->get( idxRessya ) ;
			iRv = pCentDedRessya->eraseCentDedEkiJikoku( iEkiOrder ) ;
			//-1 ; // インデクスが不正です。 
		}
	}
	return ( iRv ) ;
}
int CentDedRessyaCont::insertRessyasyubetsuIndex( int iRessyasyubetsuIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndex == INT_MAX ){
			iRessyasyubetsuIndex = m_iRessyasyubetsuCount ;
		}
		if ( !( 0 <= iRessyasyubetsuIndex && 
				iRessyasyubetsuIndex <= m_iRessyasyubetsuCount ) ){
			iRv = -1 ;	//	インデクスが不正
		}
	}
	// --------------------------------
	if ( iRv >= 0 ){
				Mu< CentDedRessya* >* pCentDedRessyaContGet = getMuPtr() ;
	
				int iRessyaCount = pCentDedRessyaContGet->size() ;
				int iRessyaIndex ;
				for ( iRessyaIndex = 0 ; iRessyaIndex < iRessyaCount ; iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					if ( iRessyasyubetsuIndexCurr >= iRessyasyubetsuIndex ){
						iRessyasyubetsuIndexCurr ++ ;
						pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;
					} 
				}
				m_iRessyasyubetsuCount ++ ;
	}
	return ( iRv ) ;
	
	
}
	
int CentDedRessyaCont::eraseRessyasyubetsuIndex( int iRessyasyubetsuIndex ) 
{
	int iRv = 0 ;

	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndex == INT_MAX ){
			iRessyasyubetsuIndex = m_iRessyasyubetsuCount - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndex && 
				iRessyasyubetsuIndex < m_iRessyasyubetsuCount ) ){
			iRv = -1 ;	//	インデクスが不正
		}
	}
	if ( iRv >= 0 ){
		if ( isExistRessyaOfRessyasyubetsu( 
			iRessyasyubetsuIndex , NULL ) > 0 ){
			iRv = -3 ;	//	『列車種別』が iRessyasyubtsuIndex の列車が存在します。
		}
	}
	// --------------------------------
	if ( iRv >= 0 ){
				Mu< CentDedRessya* >* pCentDedRessyaContGet = getMuPtr() ;
				int iRessyaCount = pCentDedRessyaContGet->size() ;

				int iRessyaIndex ;
				for ( iRessyaIndex = 0 ; iRessyaIndex < iRessyaCount ; iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					if ( iRessyasyubetsuIndexCurr > iRessyasyubetsuIndex ){
						iRessyasyubetsuIndexCurr -- ;
						pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;
					}	else if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndex ){
						iRessyasyubetsuIndexCurr = 0 ;
						pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;
					} 
				}
				
				m_iRessyasyubetsuCount -- ;
	}
	return ( iRv ) ;
	
}

int CentDedRessyaCont::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piRessyaIndex ) 
{
	int iRv = 0 ;
	Mu< CentDedRessya* >* pCentDedRessyaContGet = getMuPtr() ;

	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndex == INT_MAX ){
			iRessyasyubetsuIndex = m_iRessyasyubetsuCount - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndex && 
				iRessyasyubetsuIndex < m_iRessyasyubetsuCount ) ){
			iRv = -1 ;	//	インデクスが不正
		}
	}
	
	int iRessyaIndexFound = -1 ;
	if ( iRv >= 0 ){
	
				Mu< CentDedRessya* >* pCentDedRessyaContGet = getMuPtr() ;
				int iRessyaCount = pCentDedRessyaContGet->size() ;

				int iRessyaIndex ;
				for ( iRessyaIndex = 0 ; 
						iRv == 0 && iRessyaIndex < iRessyaCount ; 
						iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					// --------------------------------
					if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndex ){
						iRessyaIndexFound = iRessyaIndex ;
						iRv = 1 ;	//	指定の列車種別の列車が存在します。
					}
				}
	}
	// --------------------------------
	if ( iRv == 1 ){
		if ( piRessyaIndex != NULL ){
			*piRessyaIndex = iRessyaIndexFound ;
		}
	}
	
	return ( iRv ) ;
}

