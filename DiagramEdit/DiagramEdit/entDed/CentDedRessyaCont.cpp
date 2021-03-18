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
//	$Id: CentDedRessyaCont.cpp 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
*/
/** @file*/

#include "stdafx.h"
#include <algorithm>
#include "NsMu\CMup_deque.h"
#include "NsMu\CaMui.h"
#include "str\strtoint.h"
#include "logmsg\LogMsg.h"
#include "CentDedRosen.h"
#include "CentDedDiaCont.h"
#include "CentDedRessyaCont.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace entDed{
	using namespace std ;
	using namespace OuLib::Str ;
// ****************************************************************
//	CentDedRessyaCont
// ****************************************************************

// ********************************
//	�R���X�g���N�^
// ********************************
CentDedRessyaCont::CentDedRessyaCont(
	ERessyahoukou eRessyahoukou )
	:
	 m_iEkiCount( 0 ) 
	, m_eRessyahoukou( eRessyahoukou )
{
}

CentDedRessyaCont::CentDedRessyaCont( 
		int iEkiCount ,
		ERessyahoukou eRessyahoukou )
	:
	 m_iEkiCount( iEkiCount ) 
	, m_eRessyahoukou( eRessyahoukou )
{
}


CentDedRessyaCont& CentDedRessyaCont::operator=( const CentDedRessyaCont& value )
{
	//	���̃R���e�i�� CentDedDia �̎q�I�u�W�F�N�g�ł���ꍇ�A
	//	m_iEkiCount,m_iRessyasyubetsuCount,m_eRessyahoukou �͕ύX���ꂸ�A��Ԃ�����
	//	�R�s�[����܂��B
	//	CentDedDia�̎q�łȂ��ꍇ�́A�S�������R�s�[���܂��B
	if ( getDia() == NULL )
	{
		m_iEkiCount = value.m_iEkiCount ; 
		m_eRessyahoukou = value.m_eRessyahoukou ; 
	}

	//��Ԃ̃R�s�[
	super::operator =( value ) ;

	return *this ;
}

	// ********************************
	//@name Mui
	// ********************************

int CentDedRessyaCont::insert( const CentDedRessya& element , int iIndex ) 
{
	return super::insert( element , iIndex ) ;

}

int CentDedRessyaCont::set( const CentDedRessya& element , int iIndex ) 
{
	return super::set( element , iIndex ) ;
}

	// ********************************
	//@name CentDedRessyaCont-�֘A
	// ********************************
CentDedRosen* CentDedRessyaCont::getRosen() 
{
	CentDedDia* pDia = getDia() ;
	if ( pDia == NULL ){	return NULL ;}
	CentDedDiaCont* pDiaCont = dynamic_cast<CentDedDiaCont*>( pDia->getParent() ) ;
	if ( pDiaCont == NULL ){	return NULL ;}
	return pDiaCont->getRosen() ;
}

const CentDedRosen* CentDedRessyaCont::getRosen()const 
{
	const CentDedDia* pDia = getDia() ;
	if ( pDia == NULL ){	return NULL ;}
	const CentDedDiaCont* pDiaCont = dynamic_cast<const CentDedDiaCont*>( pDia->getParent() ) ;
	if ( pDiaCont == NULL ){	return NULL ;}
	return pDiaCont->getRosen() ;
}


	// ********************************
	//@name CentDedRessyaCont-����
	// ********************************
int CentDedRessyaCont::setable(  const CentDedRessya& element , int iIndex )const 
{
	return 0 ;
}

int  CentDedRessyaCont::getIndex( const CentDedRessya* element )const 
{
	const Mu<const CentDedRessya*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;

}

void CentDedRessyaCont::adjust() 
{
	CentDedRosen* pRosen = getRosen() ;
	if ( pRosen!= NULL )
	{
		m_iEkiCount = pRosen->getCentDedEkiCont()->size() ;
	}

	Mu<CentDedRessya*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		pMu->get( idx )->adjust() ;
	}
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

	// ********************************
	//@name CentDedRessyaCont-�w���E��Ԏ�ʐ��̕ύX
	// ********************************


int CentDedRessyaCont::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piRessyaIndex ) 
{
	int iRv = 0 ;
	Mu< CentDedRessya* >* pCentDedRessyaContGet = getMuPtr() ;
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

	// ********************************
	//@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
void CentDedRessyaCont::onEkiInsert( int iEkiOrder )
{
	m_iEkiCount ++ ;
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onEkiInsert( iEkiOrder ) ;
	}
}

void CentDedRessyaCont::onEkiErase( int iEkiOrder  )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onEkiErase( iEkiOrder ) ;
	}
	m_iEkiCount -- ;
}
void CentDedRessyaCont::onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onEkiTrackInsert( iEkiOrder , iEkiTrackIndex ) ;
	}
}
void CentDedRessyaCont::onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onEkiTrackErase( iEkiOrder , iEkiTrackIndex ) ;
	}
}
void CentDedRessyaCont::onRessyasyubetsuInsert( int iRessyasyubetsuIndex )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onRessyasyubetsuInsert( iRessyasyubetsuIndex ) ;
	}
}
void CentDedRessyaCont::onRessyasyubetsuErase( int iRessyasyubetsuIndex )
{
	Mu<CentDedRessya*>* muRessya = getMuPtr() ;
	for ( int i = 0 ; i < muRessya->size() ; i++ )
	{
		muRessya->get( i )->onRessyasyubetsuErase( iRessyasyubetsuIndex ) ;
	}

}



} //namespace entDed
