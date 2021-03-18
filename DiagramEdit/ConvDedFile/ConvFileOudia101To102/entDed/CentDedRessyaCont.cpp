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


(��: 

	OuDia - ��Ԏ����\�����ƂɁA�_�C���O������`�悷��Win32�A�v���P�[�V
�����B

Copyright (C) 2006-2017 take-okm 

���̃v���O�����̓t���[�\�t�g�E�F�A�ł��B���Ȃ��͂�����A�t���[�\�t�g�E�F�A��
�c�ɂ���Ĕ��s���ꂽGNU ��ʌ��O���p������(�o�[�W����3���A����ȍ~�̃o�[�W��
���̂����ǂꂩ)����߂�����̉��ōĔЕz�܂��͉��� ���邱�Ƃ��ł��܂��B

���̃v���O�����͗L�p�ł��邱�Ƃ�����ĔЕz����܂����A*�S���̖��ۏ� *�ł��B
���Ɖ\���̕ۏ؂����ړI�ւ̓K�����́A���O�Ɏ����ꂽ���̂� �܂߁A�S������
���܂���B�ڂ�����GNU ��ʌ��O���p���������������������B

���Ȃ��͂��̃v���O�����Ƌ��ɁAGNU ��ʌ��O���p�������̃R�s�[���ꕔ �󂯎��
�Ă���͂��ł��B�����󂯎���Ă��Ȃ���΁A<http://www.gnu.org/licenses/> ��
�������������B

)

  �����āA���ʂȗ�O�Ƃ��āAtake-okm �͂��̃v���O�����̃R�[�h�� 
  "MFC(Microsoft Foundation Class library) Version 9.0" 
  (  ���邢�� "MFC Version 9.0" �Ɠ������C�Z���X���K�p���ꂽ
  "MFC Version 9.0" �̉��ς��ꂽ�o�[�W����)�ƃ����N���A
  �����N���ꂽ���҂��܂ތ������앨��Еz���鋖��^���܂��B
  ���Ȃ��� "MFC" �ȊO�Ŏg���Ă��邷�ׂ�
  �̃R�[�h�Ɋւ��Ă͑S�ʓI��GNU��ʌ��O���p�����_�񏑂ɏ]��Ȃ����
  �Ȃ�܂���B���Ȃ������̃t�@�C�������ς����Ȃ�΁A���Ȃ��͂��̗�O
  �����Ȃ��̃o�[�W�����̃t�@�C���Ɉ��������݂��邱�Ƃ��ł��܂����A��
  ������`���͂���܂���B������O��݂������Ȃ���΁A���̗�O������
  ���Ȃ��̃o�[�W��������͍폜���Ă��������B)
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
//	�R���X�g���N�^
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
	//	�ێ����Ă����Ԃ��A���ׂĔj�����܂��B
	erase( 0 , INT_MAX ) ;

	//	value �̗�Ԃ��Athis�ɃR�s�[���Ă��܂��B
	CaMui< CentDedRessya >	aCaCont_this( this ) ;
	aCaCont_this.insert( &value ) ;

	return *this ;
}

CentDedRessyaCont::~CentDedRessyaCont()
{
	//	�R���e�i���ێ����Ă���|�C���^�̗v�f��
	//	erase()->onErase() �ɂ��A
	//	delete �ō폜���Ȃ��Ă͂Ȃ�܂���B
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
			//	iEkiiIndex �E iEkiIndex + 1 �̗��w�ɒ�Ԃ����Ԃ̂����́A
			//	�ŏ��w�ԏ��v�b�� 
			int iSaisyouSyouSec = -1 ;
			//iSaisyouSyouSec = 
			//	iEkiiIndex �E iEkiIndex + 1 �̍ŏ��w�ԏ��v�b��
			//	�Е��E�܂��͗��w���ʉ߉w�̗�Ԃ��܂݂܂��B

			int iSaisyouSyouSecTeisyaRessyaIdx = -1 ;
			//iSaisyouSyouSecTeisyaRessyaIdx = 
			//	iSaisyouSyouSecTeisya �ɑΉ�������Index 
			int iSaisyouSyouSecRessyaIdx = -1 ;
			//iSaisyouSyouSecRessyaIdx = 
			//	iSaisyouSyouSec �ɑΉ�������Index 
			
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
	CentDedRessyaCont::sort() �Ɏg�p����
	���ׂ����p�w�����I�u�W�F�N�g�B
*/
class CdRessyaForSort_Ekijikoku
{
public:
	/**
		CdRessyaForSort_Ekijikoku �̔�r���s���֐��I�u�W�F�N�g�ł��B
	*/
	class CCompareFunction
	{
		/**
		�_�C���O�����N�_�������w�肵�Ă��������B
		���̊֐��́A�\�[�g���ɁA���̒l���ł�������������
		�݂Ȃ��܂��B
		(��F���̎�����5:00���w�肳�ꂽ�ꍇ�́A5:00<23:59<0:00<4:59 �Ƃ��Ĕ�r���s���܂�)
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
			left < right �Ȃ�^�ł��B

		@note
		  ��r��́A
			- �w������NULL�łȂ����̂�NULL�̂��̂Ƃł́ANULL�łȂ����̂���B
			- Ekijikoku�̏������ق�����B
			- Ekijikoku�������Ȃ�A����������B
			- Ekijikoku����/���������Ȃ�RessyaIdx�̏������ق�����B
		*/
		bool operator()( 
			const CdRessyaForSort_Ekijikoku& left , 
			const CdRessyaForSort_Ekijikoku& right )
		{
			// --------------------------------
			//	�Е���NULL�̏ꍇ�̔�r
			// --------------------------------
			if ( !left.getJikoku().isNull() && right.getJikoku().isNull() )
			{
				//	left��NULL�ŁAright�͔�NULL
				return true ;
			}
			else if ( left.getJikoku().isNull() && !right.getJikoku().isNull() )
			{
				//	left�͔�NULL�ŁAright��NULL
				return false ;
			}
			// --------------------------------
			//	m_Jikoku �͂ǂ����NULL�ł͂Ȃ��E�������͂ǂ����NULL
			//	m_Jikoku �͓�����
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
			//	m_Jikoku �͓�����
			//	Ekijikoku�������Ȃ�A����������B
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
			// m_Jikoku , m_bIsHatsuJikoku �͓�����
			//	- Ekijikoku����/���������Ȃ�RessyaIdx�̏������ق�����B
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
	///@name ����
	// ********************************
	///@{
	/** ��ԃC���f�N�X */
	int m_iRessyaIdx ;

	/** �w���� */
	CdDedJikoku m_Jikoku ;
	/** 
	-	false : m_Jikoku �́A������
	-	true  : m_Jikoku �́A������
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
	///@name ����
	// ********************************
	///@{
	int getRessyaIdx()const{	return m_iRessyaIdx ;};
	void setRessyaIdx( int value ){	m_iRessyaIdx = value ;};
	CdDedJikoku getJikoku()const{	return m_Jikoku ;};
	bool getIsHatsuJikoku()const{	return m_bIsHatsuJikoku ;};
	///@}

};
/**
	CentDedRessyaCont::sort() �Ɏg�p����
	���ׂ����p��ԃI�u�W�F�N�g
*/
class CdRessyaForSort_Ressya
{
public:
	/**
		CdRessyaForSort �̔�r���s���֐��I�u�W�F�N�g�ł��B
	*/
	class CCompareFunction
	{
	public:
		CCompareFunction( ) 
		{
		};
		/**
		@return
			left < right �Ȃ�^�ł��B

		@note
		  ��r��́A
			- NULL�łȂ����̂�NULL�̂��̂Ƃł́ANULL�łȂ����̂���B
			- ��Ԏ��Index�̏������ق�����B
			- ��Ԗ����������ő���������B
			- �����𐮐��������ꍇ�ɑ���������B
			- �������������ő���������B
		*/
		bool operator()( 
			const CdRessyaForSort_Ressya& left , 
			const CdRessyaForSort_Ressya& right )
		{
			// --------------------------------
			//	�Е���NULL�̏ꍇ�̔�r
			//	- NULL�łȂ����̂�NULL�̂��̂Ƃł́ANULL�łȂ����̂���B
			// --------------------------------
			if ( !left.getIsNull() && right.getIsNull() )
			{
				//	left��NULL�ŁAright�͔�NULL
				return true ;
			}
			else if ( left.getIsNull() && !right.getIsNull() )
			{
				//	left�͔�NULL�ŁAright��NULL
				return false ;
			}
			// --------------------------------
			//	- ��Ԏ��Index�̏������ق�����B
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
			//	- ��Ԗ����������ő���������B
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
			//	- �����𐮐��������ꍇ�ɑ���������B
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
			//	- �������������ő���������B
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
	///@name ����
	// ********************************
	///@{
	/** ��ԃC���f�N�X */
	int m_iRessyaIdx ;
	/**
		���̗�Ԃ��wNull��ԁx�Ȃ�^�A
		�L���ȗ�ԑ�����ێ����Ă���̂Ȃ�U�ł��B
		
		���̑������^�̏ꍇ�A���� 
		-	m_iRessyasyubetsuIndex,
		-	m_strRessyabangou ;
		-	m_strRessyamei ;
		-	m_strGousuu ;
		-	m_strBikou ;
	
		����сA
			m_CentDedEkiJikokuCont �Ɋi�[����Ă��� 
		CentDedEkiJikoku �́A�Ӗ��������܂���B
		
		�K��l�� true �ł��B
		set...() ���\�b�h�ŁAm_eRessyahoukou �ȊO��
		�����ꂩ�̑�����ݒ肵���Ƃ��ɂ́A
		�����I�ɋU�ɕς��܂��B
		clear() �ŁA�^�ƂȂ�܂��B
	 */
	bool m_bIsNull ;

	/**
		���̗�Ԃ́w��Ԏ�ʁx���A
		�w��Ԏ��Index�x�ŕێ����܂��B
		
		�K��l�� 0 �ł��B
	*/
	int	m_iRessyasyubetsuIndex ;
	
	/**
		���̗�Ԃ́w��Ԗ��x�B
		
		�K��l�͋󕶎���ł��B
	 */
	string m_strRessyamei ;
	
	/**
		���̗�Ԃ́w�����x�B
		
		�K��l�͋󕶎���ł��B
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
	///@name ����
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
	//jikokuSyuuchaku = this��Ԃ̏I���w�̒������iNULL�̏ꍇ������܂��j

	int iRv = -1 ;
	for ( idxRessya ++ ; iRv == -1 && idxRessya  < getMuPtr()->size() ; idxRessya ++ )
	{
		const CentDedRessya* pCentDedRessyaSihatsu = getMuPtr()->get( idxRessya ) ;
		//	  - �E�t�H�[�J�X�̂�����(�r���w�~�܂�̗��)�Ɠ�����Ԏ��
		if ( pCentDedRessyaSyuuchaku->getRessyasyubetsuIndex() == 
			pCentDedRessyaSihatsu->getRessyasyubetsuIndex() )
		{
			//	  - �E�t�H�[�J�X�̂���w���n���w�Ƃ�����
			if ( iEkiOrder == pCentDedRessyaSihatsu->getRunFirstEkiOrder() )
			{
				//	  - �E�I����Ԃ̒��������n���w�̔��������w�肳��Ă���ꍇ�́A
				//	  - �E�n���w�̔��������A�I����Ԃ̒���������12���Ԉȓ�
				//	  - �E�I����Ԃ̒������E�n���w�̔������̂ǂ��炩�������Ă���ꍇ�́A
				//		�������ɒ��ʉ��̑ΏۂƂȂ�܂��B
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
					//	  - �E�n���w�̔��������A�I����Ԃ̒���������12���Ԉȓ�
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
//@name CentDedRessya ���� 
//	CentDedEkiJikoku �𑝌�
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
				//-1 ; // �C���f�N�X���s���ł��B 
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
				//-1 ; // �C���f�N�X���s���ł��B 
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
			//-1 ; // �C���f�N�X���s���ł��B 
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
			iRv = -1 ;	//	�C���f�N�X���s��
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
			iRv = -1 ;	//	�C���f�N�X���s��
		}
	}
	if ( iRv >= 0 ){
		if ( isExistRessyaOfRessyasyubetsu( 
			iRessyasyubetsuIndex , NULL ) > 0 ){
			iRv = -3 ;	//	�w��Ԏ�ʁx�� iRessyasyubtsuIndex �̗�Ԃ����݂��܂��B
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
			iRv = -1 ;	//	�C���f�N�X���s��
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
						iRv = 1 ;	//	�w��̗�Ԏ�ʂ̗�Ԃ����݂��܂��B
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

