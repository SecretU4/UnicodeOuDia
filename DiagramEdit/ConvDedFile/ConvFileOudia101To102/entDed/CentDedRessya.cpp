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
//	CentDedRessya.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include "CentDedRessya.h"
#include "CdDedJikan.h"

#ifdef _MFC_VER 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif


// ****************************************************************
//	CentDedRessya
// ****************************************************************

// --------------------------------
//@name CentDedRosen��CentDedRessyaCont ��p�����o�֐�
// --------------------------------
int CentDedRessya::onSetCentDedEki(const Mu<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder) 
{
	int iRv = 0 ;
	return ( iRv ) ;
}
int CentDedRessya::insertCentDedEkiJikoku( 
		const CentDedEkiJikoku& aCentEkiJikoku , 
		int iEkiOrder ) 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iRv >= 0 ){
		if ( iEkiOrder == INT_MAX ){
			iEkiOrder = (int)m_CentDedEkiJikokuCont.size()  ;
		}
		if ( !( 0 <= iEkiOrder && iEkiOrder <= (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	�C���f�N�X���s���ł��B
		}
	}
	if ( iRv >= 0 ){
		m_CentDedEkiJikokuCont.insert( 
			m_CentDedEkiJikokuCont.begin() + iEkiOrder , 
			new CentDedEkiJikoku( aCentEkiJikoku ) ) ;		
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedRessya::eraseCentDedEkiJikoku( int iEkiOrder ) 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iRv >= 0 ){
		if ( iEkiOrder == INT_MAX ){
			iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ;
		}
		if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	�C���f�N�X���s���ł��B
		}
	}
	if ( iRv >= 0 ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;		
		m_CentDedEkiJikokuCont.erase( 
			m_CentDedEkiJikokuCont.begin() + iEkiOrder ) ;
		delete pCentDedEkiJikoku ;
	}
	// --------------------------------
	return ( iRv ) ;
}

// ********************************
//	�R���X�g���N�^
// ********************************
CentDedRessya::CentDedRessya( 
		int iEkiJikokuCount ,
		ERessyahoukou	eRessyahoukou ) :
	m_bIsNull( true ) ,
	m_eRessyahoukou( eRessyahoukou ) ,
	m_iRessyasyubetsuIndex( 0 )
{
	while ( (int)m_CentDedEkiJikokuCont.size() < iEkiJikokuCount ){
		m_CentDedEkiJikokuCont.push_back( new CentDedEkiJikoku ) ;
	}
}

CentDedRessya::CentDedRessya( const CentDedRessya& value ) :
	m_bIsNull( value.m_bIsNull ) ,
	m_eRessyahoukou( value.m_eRessyahoukou ) ,
	m_iRessyasyubetsuIndex( value.m_iRessyasyubetsuIndex ) ,
	m_strRessyabangou( value.m_strRessyabangou ),
	m_strRessyamei( value.m_strRessyamei ),
	m_strGousuu( value.m_strGousuu ),
	m_strBikou( value.m_strBikou )
{
	int iEkiOrder ;
	for ( iEkiOrder = 0 ; 
			iEkiOrder < (int)value.m_CentDedEkiJikokuCont.size() ; iEkiOrder ++ ){
		m_CentDedEkiJikokuCont.push_back( new CentDedEkiJikoku( 
			*value.m_CentDedEkiJikokuCont[iEkiOrder] ) ) ;
	} 
}
CentDedRessya& CentDedRessya::operator=( const CentDedRessya& value )
{
	m_bIsNull = value.m_bIsNull ;
	m_iRessyasyubetsuIndex = value.m_iRessyasyubetsuIndex ;
	m_strRessyabangou = value.m_strRessyabangou ;
	m_strRessyamei = value.m_strRessyamei;
	m_strGousuu = value.m_strGousuu;
	m_strBikou = value.m_strBikou;


	int iEkiOrder ;
	for ( iEkiOrder = 0 ; 
			iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ; iEkiOrder ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[iEkiOrder] ;
		if ( iEkiOrder < (int)value.m_CentDedEkiJikokuCont.size() ){
			*pCentDedEkiJikoku = *value.m_CentDedEkiJikokuCont[iEkiOrder] ;
		}	else	{
			*pCentDedEkiJikoku = CentDedEkiJikoku() ;
		}
	} 
	return *this ;
}

CentDedRessya::~CentDedRessya() 
{
	while ( m_CentDedEkiJikokuCont.size() > 0 )
	{
		CentDedEkiJikoku*	pCentDedEkiJikoku = m_CentDedEkiJikokuCont.back() ;
		m_CentDedEkiJikokuCont.pop_back() ;
		delete pCentDedEkiJikoku ;
	}
}

// ********************************
//	CentDedRessya
// ********************************
	// ********************************
	//@name ����
	// ********************************
ERessyahoukou	CentDedRessya::getRessyahoukou()const
{
		return m_eRessyahoukou ;
};
int	CentDedRessya::getRessyasyubetsuIndex()const
{
		return m_iRessyasyubetsuIndex ; 
};
CentDedRessya& CentDedRessya::setRessyasyubetsuIndex( int value )
{
		m_bIsNull = false ;
		m_iRessyasyubetsuIndex = value ; return *this ;
};
	
	// ********************************
	//@name ���-CentDedEkiJikoku
	// ********************************

int CentDedRessya::getCentDedEkiJikokuCount()const 
{
	return ( (int)m_CentDedEkiJikokuCont.size() ) ;
}

CentDedEkiJikoku CentDedRessya::
getCentDedEkiJikoku( int iEkiOrder )const 
{
	CentDedEkiJikoku	aCentDedEkiJikoku ;
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( ( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ) ){
		aCentDedEkiJikoku = *m_CentDedEkiJikokuCont[iEkiOrder] ;
	}
	return ( aCentDedEkiJikoku ) ;
}


CentDedRessya& CentDedRessya::
setCentDedEkiJikoku( int iEkiOrder , const CentDedEkiJikoku& value ) 
{
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ){
		m_bIsNull = false ;
		*m_CentDedEkiJikokuCont[iEkiOrder] = value ;
	}
	return *this ;
}
	// ********************************
	//@name �w�wOrder�x�P�ʂ̑���
	// ********************************
int CentDedRessya::EkiIndexOfEkiOrder( int iEkiOrder )const  
{
	int iRv = iEkiOrder ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = (int)m_CentDedEkiJikokuCont.size() - 1 - iEkiOrder ;
	}
	return ( iRv ) ;
}

int CentDedRessya::EkiOrderOfEkiIndex( int iEkiIndex ) const
{
	int iRv = iEkiIndex ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = (int)m_CentDedEkiJikokuCont.size() - 1 - iEkiIndex ;
	}
	return ( iRv ) ;
}


CentDedRessya& CentDedRessya::modifyCentDedEkiJikoku( 
	int iEkiOrder , 
	const CentDedEkiJikoku& value ) 
{
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ){
		m_bIsNull = false ;
	
		//	�ύX�O�̎�����ۑ�
		CdDedJikoku jikokuChakujikokuPrev = 
				m_CentDedEkiJikokuCont[iEkiOrder]->getChakujikoku() ;
		CdDedJikoku jikokuHatsujikokuPrev = 
				m_CentDedEkiJikokuCont[iEkiOrder]->getHatsujikoku() ;
		CdDedJikoku jikokuChakujikoku = value.getChakujikoku() ;
		CdDedJikoku jikokuHatsujikoku =  value.getHatsujikoku() ;
		
		//	�w�����̕ύX
		m_CentDedEkiJikokuCont[iEkiOrder]->set( 
			value.getEkiatsukai() , value.getChakujikoku() , value.getHatsujikoku() ) ;

		//	���̌�̎����̌J�グ�E�J����
		if ( !jikokuHatsujikoku.isNull() && !jikokuHatsujikokuPrev.isNull() )
		{
			//	���������ύX�O�E�ύX������͂���Ă���ꍇ�́A
			//	�������̓��͑O�E���͌�̍��������߂āA
			//	���̉w�ȍ~����J�������s���܂��B
			CdDedJikan	aCdDedJikan = jikokuHatsujikoku.subJikoku( 
					jikokuHatsujikokuPrev ) ;
			modifyRessyaJikoku( 
				aCdDedJikan , 
				CdDedJikokuOrder( iEkiOrder + 1 , CdDedJikokuOrder::EkiJikokuItem_Chaku ) ) ;
		}
		else if ( !jikokuChakujikoku.isNull() && !jikokuChakujikokuPrev.isNull() )
		{
			//	�������ɂ��J�グ�E�J�����͂ł��Ȃ����A
			//	���������ύX�O�E�ύX������͂���Ă���ꍇ�́A
			//	�������̍��������߂āA
			//	���̉w�̔������ȍ~����J�������s���܂��B
			CdDedJikan	aCdDedJikan = jikokuChakujikoku.subJikoku( 
					jikokuChakujikokuPrev ) ;
			modifyRessyaJikoku(
				aCdDedJikan , 
				CdDedJikokuOrder( iEkiOrder , CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ) ;
		}
	}
	return *this ;
}

int CentDedRessya::getSihatsuEki() const
{
	int	iRv = -1 ;
	// --------------------------------
	int iEkiOrder = 0 ;
	for ( iEkiOrder = 0 ; 
			iRv == -1 && 
			iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ; 
			iEkiOrder ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;
		if ( pCentDedEkiJikoku->getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None ){
			iRv = iEkiOrder ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedRessya::setSihatsuEki( int iEkiOrder ) 
{
	int	iRv = 0 ;

	if ( iRv >= 0 ){
		if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	�w�wIndex�x���s���ł��B
		}
	}

	// --------------------------------
	int iEkiOrderCurr = 0 ;
	for ( iEkiOrderCurr = 0 ; 
			iEkiOrderCurr < iEkiOrder; 
			iEkiOrderCurr ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrderCurr ] ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}
	{
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrderCurr ] ;
		if ( !pCentDedEkiJikoku->getHatsujikoku().isNull() ){
			//	���������ݒ肳��Ă���ꍇ����
			//	���������������܂��B
			//	�i���������ݒ肳��Ă��Ȃ��ꍇ�ɒ�������
			//	�������Ă��܂��ƁA���̉w�̉w������
			//	�^�s�Ȃ� Ekiatsukai_None �ɂȂ��Ă��܂����߂ł��j
			pCentDedEkiJikoku->setChakujikoku( CdDedJikoku() ) ;
	
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedRessya::getSyuuchakuEki() const
{
	int	iRv = -1 ;
	// --------------------------------
	int iEkiOrder = 0 ;
	for ( iEkiOrder = (int)m_CentDedEkiJikokuCont.size() - 1 ; 
			iRv == -1 && 
			iEkiOrder >= 0 ; 
			iEkiOrder -- )
	{
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;
		if ( pCentDedEkiJikoku->getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None )
		{
			iRv = iEkiOrder ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedRessya::setSyuuchakuEki( int iEkiOrder ) 
{
	int	iRv = 0 ;

	if ( iRv >= 0 ){
		if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	�w�wIndex�x���s���ł��B
		}
	}

	// --------------------------------
	{
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;
		if ( !pCentDedEkiJikoku->getChakujikoku().isNull() ){
			//	���������ݒ肳��Ă���ꍇ����
			//	���������������܂��B
			//	�i���������ݒ肳��Ă��Ȃ��ꍇ�ɔ�������
			//	�������Ă��܂��ƁA���̉w�̉w������
			//	�^�s�Ȃ� Ekiatsukai_None �ɂȂ��Ă��܂����߂ł��j
			pCentDedEkiJikoku->setHatsujikoku( CdDedJikoku() ) ;

		}
	}
	int iEkiOrderCurr = 0 ;
	for ( iEkiOrderCurr = iEkiOrder + 1  ; 
			iEkiOrderCurr < (int)m_CentDedEkiJikokuCont.size() ; 
			iEkiOrderCurr ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrderCurr ] ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}
	// --------------------------------
	return ( iRv ) ;
}

bool CentDedRessya::isRunBetweenNextEki( int iEkiOrder )const 
{
	bool bRv = false ;
	if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() - 1 ) )
	{
		bRv = false ;	//	�w�wIndex�x���s���ł��B
	}
	else
	{
		CentDedEkiJikoku* pEkijikoku = m_CentDedEkiJikokuCont[ iEkiOrder ] ;
		CentDedEkiJikoku* pEkijikokuNext = m_CentDedEkiJikokuCont[ iEkiOrder + 1 ] ;
		if ( 
			( pEkijikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya 
				|| pEkijikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
			&& ( pEkijikokuNext->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya 
				|| pEkijikokuNext->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
		)
		{
			bRv = true ;
		}

	}
	return bRv ;
}

int CentDedRessya::getRunFirstEkiOrder()const 
{
	int iRv = -1 ;
	for ( int iEkiOrder = 0 ; 
		iRv == -1 && iEkiOrder < (int)m_CentDedEkiJikokuCont.size() - 1 ; 
		iEkiOrder ++ )
	{
		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			iRv = iEkiOrder ;
		}
	}
	return iRv ;
}
	
int CentDedRessya::getRunLastEkiOrder()const 
{
	int iRv = -1 ;
	for ( int iEkiOrder = m_CentDedEkiJikokuCont.size() - 2 ; 
		iRv == -1 && iEkiOrder >= 0 ; 
		iEkiOrder -- )
	{
		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			iRv = iEkiOrder + 1 ;
		}
	}
	return iRv ;
}

void CentDedRessya::adjustByEkijikokukeisiki(
		int iEkiOrder ,
		bool bChakujikokuHyouji , bool bHatsujikokuHyouji ) 
{
	if ( !m_bIsNull )
	{
		bool bSihatsuEki = ( getSihatsuEki() == iEkiOrder ) ;
		bool bSyuuchakuEki = ( getSyuuchakuEki() == iEkiOrder ) ;

		CentDedEkiJikoku aEkiJikoku = getCentDedEkiJikoku(iEkiOrder) ;
		aEkiJikoku.adjustByEkijikokukeisiki( 
			bChakujikokuHyouji , bHatsujikokuHyouji,
			bSihatsuEki , bSyuuchakuEki ) ;
		setCentDedEkiJikoku( iEkiOrder , aEkiJikoku ) ;
	}
}


	// ********************************
	//@name �w����Order�x�P�ʂ̑���
	// ********************************
CdDedJikokuOrder CentDedRessya::incJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder )const 
{
	CdDedJikokuOrder jikokuOrderRv = aJikokuOrder ;


	//	- aJikokuOrder �� EkiOrder>=this.size() (�Ō�̉wOrder�̎�) �Ȃ�A@n
	//		aJikokuOrder �����̂܂ܕԂ��܂��B
	//	- aJikokuOrder ��NULL��� �Ȃ�AaJikokuOrder �����̂܂ܕԂ��܂��B
	if ( !aJikokuOrder.getIsNull() && 
		aJikokuOrder.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() )
	{
		//	- aJikokuOrder ���������̏ꍇ�́A�����wOrder�̔�����
		if ( jikokuOrderRv.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku )
		{
			jikokuOrderRv.setEkiOrder( jikokuOrderRv.getEkiOrder() , 
				CdDedJikokuOrder::EkiJikokuItem_Hatsu );
		}
		else if ( jikokuOrderRv.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
		{
			//- aJikokuOrder ���������̏ꍇ�́A���̉wOrder�̒�����
			jikokuOrderRv.setEkiOrder( jikokuOrderRv.getEkiOrder() + 1 , 
				CdDedJikokuOrder::EkiJikokuItem_Chaku );
		}
	}
	return jikokuOrderRv ;
}

CdDedJikokuOrder CentDedRessya::decJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder )const 
{
	CdDedJikokuOrder jikokuOrderRv = aJikokuOrder ;

	//	- aJikokuOrder ��NULL��� �Ȃ�AaJikokuOrder �����̂܂ܕԂ��܂��B
	if ( !aJikokuOrder.getIsNull() )
	{ 
		//- aJikokuOrder �� EkiOrder>=this.size() (�Ō�̉wOrder�̎�) �Ȃ�A@n
		//	�Ō�̉wOrder�̔�����
		if ( aJikokuOrder.getEkiOrder() >= (int)m_CentDedEkiJikokuCont.size() )
		{
			jikokuOrderRv.setEkiOrder( m_CentDedEkiJikokuCont.size() - 1, 
				CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ;
		}
		//- aJikokuOrder ���������̏ꍇ�́A�����wOrder�̒�����
		else if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
		{
			jikokuOrderRv.setEkiOrder( aJikokuOrder.getEkiOrder() , 
				CdDedJikokuOrder::EkiJikokuItem_Chaku ) ; 
		}
		//- aJikokuOrder ���������̏ꍇ�́A���̉wOrder�̔�����
		//- aJikokuOrder �� EkiOrder=0 �̒��Ȃ�ANULL���
		else if (  aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku )
		{
			jikokuOrderRv.setEkiOrder( aJikokuOrder.getEkiOrder() - 1 , 
				CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ; 
		}
	}
	return jikokuOrderRv ;
}



CdDedJikoku CentDedRessya::getEkiJikoku( CdDedJikokuOrder aJikokuOrder )const 
{
	CdDedJikoku	aCdDedJikoku ;
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= aJikokuOrder.getEkiOrder() && 
				aJikokuOrder.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	�p�����[�^���s��
		}
	}
	if ( iRv >= 0 ){
		if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu ){
			aCdDedJikoku = 
				m_CentDedEkiJikokuCont[ aJikokuOrder.getEkiOrder() ]->getHatsujikoku() ;
		}	else	{
			aCdDedJikoku = 
				m_CentDedEkiJikokuCont[ aJikokuOrder.getEkiOrder() ]->getChakujikoku() ;
		}
	}
	return ( aCdDedJikoku ) ;
}

int CentDedRessya::setEkiJikoku( 
		const CdDedJikoku& aCdDedJikoku ,
		CdDedJikokuOrder aJikokuOrder ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= aJikokuOrder.getEkiOrder() && 
				aJikokuOrder.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	�p�����[�^���s��
		}
	}
	if ( iRv >= 0 ){
		if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu ){
			m_CentDedEkiJikokuCont[ aJikokuOrder.getEkiOrder() ]->setHatsujikoku(
				aCdDedJikoku ) ;
		}	else	{
			m_CentDedEkiJikokuCont[ aJikokuOrder.getEkiOrder() ]->setChakujikoku(
				aCdDedJikoku ) ;
		}
	}
	return ( iRv ) ;
}

int CentDedRessya::modifyRessyaJikoku( 
	const CdDedJikan& aCdDedJikan , 
	const CdDedJikokuOrder& aJikokuOrder ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= aJikokuOrder.getEkiOrder() && 
				aJikokuOrder.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() ) ){
			iRv = -1 ;	//	�p�����[�^���s��
		}
	}
	if ( iRv >= 0 ){
		CdDedJikokuOrder iJikokuOrderCurr ;
		for ( iJikokuOrderCurr = aJikokuOrder ;
			iJikokuOrderCurr.getEkiOrder() < (int)m_CentDedEkiJikokuCont.size() ;
			iJikokuOrderCurr = incJikokuOrder( iJikokuOrderCurr ) )
		{
			CdDedJikoku aCdDedJikoku = getEkiJikoku( iJikokuOrderCurr ) ;
			if ( !aCdDedJikoku.isNull() )
			{
				aCdDedJikoku = aCdDedJikoku.addSeconds( 
					aCdDedJikan.getTotalSeconds() ) ;
				setEkiJikoku( aCdDedJikoku , iJikokuOrderCurr ) ;
			}
		}
	}
	return ( iRv ) ;
	
}

CdDedJikokuOrder CentDedRessya::findrevJikoku( 
	const CdDedJikokuOrder& jikokuOrder )const 
{
	CdDedJikokuOrder aJikokuOrder = jikokuOrder ;
	CdDedJikokuOrder iRv  ;
	
	for ( ; 
		iRv.getIsNull() && aJikokuOrder.getEkiOrder() >= 0 ; 
		aJikokuOrder = decJikokuOrder(  aJikokuOrder ) )
	{
		CdDedJikoku	aCdDedJikoku = getEkiJikoku( aJikokuOrder ) ;
		if ( !aCdDedJikoku.isNull() )
		{
			iRv = aJikokuOrder ;
		}
	}
	return ( iRv ) ;
}
	
	
	// ********************************
	//@name ����
	// ********************************
bool CentDedRessya::isNull()const 
{
	return ( m_bIsNull ) ;
}

void CentDedRessya::clear() 
{
	m_bIsNull = true ;
	m_iRessyasyubetsuIndex = 0 ;
	m_strRessyabangou.erase() ;
	m_strRessyamei.erase() ;
	m_strGousuu.erase() ;
	m_strBikou.erase() ;	

	for ( int iEkiOrder = 0 ; 
			iEkiOrder < (int)m_CentDedEkiJikokuCont.size() ; 
			iEkiOrder ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}

}

void CentDedRessya::pasteEkiJikoku( const CentDedRessya& aCentDedRessyaSrc ) 
{
	
	int iEkiOrder = 0 ;
	for ( iEkiOrder = 0 ; 
		iEkiOrder < (int)m_CentDedEkiJikokuCont.size()  ; 
			iEkiOrder ++ )
	{
		CentDedEkiJikoku aCentDedEkiJikokuSrc = 
			aCentDedRessyaSrc.getCentDedEkiJikoku( iEkiOrder ) ;
		if ( aCentDedEkiJikokuSrc.getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None  )
		{
			CentDedEkiJikoku* pCentDedEkiJikokuDst = m_CentDedEkiJikokuCont[iEkiOrder] ;
			pCentDedEkiJikokuDst->setEkiatsukai( aCentDedEkiJikokuSrc.getEkiatsukai() ) ;
			
			if ( !aCentDedEkiJikokuSrc.getChakujikoku().isNull() )
			{
				pCentDedEkiJikokuDst->setChakujikoku( aCentDedEkiJikokuSrc.getChakujikoku() ) ;
			}
			if ( !aCentDedEkiJikokuSrc.getHatsujikoku().isNull() )
			{
				pCentDedEkiJikokuDst->setHatsujikoku( aCentDedEkiJikokuSrc.getHatsujikoku() ) ;
			}
			
		}
	}
}

int CentDedRessya::direct( 
		const CentDedRessya& aRessyaSihatsu ) 
{
	int iRv = 0 ;

	int iEkiOrderSyuuchaku = -1 ;
	int iEkiOrderSihatsu = -1 ;

	//	this��Ԃ̏I���w�E�n����Ԃ̎n���w�̎擾
	if ( iRv >= 0 )
	{
		iEkiOrderSyuuchaku = getRunLastEkiOrder() ;
		iEkiOrderSihatsu = aRessyaSihatsu.getRunFirstEkiOrder() ;
		if ( iEkiOrderSyuuchaku == -1 )
		{
			iRv = -1 ;	//	���̗�Ԃɂ͉w�������w�肳��Ă��܂���B
		}
		else if ( iEkiOrderSihatsu == -1 )
		{
			iRv = -2 ;	//	�n����Ԃɂ͉w�������w�肳��Ă��܂���B
		}
		else if ( !( iEkiOrderSyuuchaku <= iEkiOrderSihatsu ) )
		{
			iRv = -3 ;	//	aRessyaSihatsu �Ƃ̒��ʉ��͂ł��܂���B\n
			//aRessyaSihatsu �̎n���w�́A	this �̏I���w�Ɠ������A����ȍ~�łȂ��Ă͂Ȃ�܂���B
		}
	}
	//iEkiOrderSyuuchaku = this��Ԃ̏I���w�̉wOrder
	//iEkiOrderSihatsu = aRessyaSihatsu �̎n���w�̉wOrder

	//	�I���w�`�n���w�܂ł̊Ԃ́A�o�R�Ȃ��Ƃ��܂��B
	if ( iRv <= 0 )
	{
		for ( int iEkiOrder = iEkiOrderSyuuchaku + 1 ;
			iEkiOrder < iEkiOrderSihatsu ;
			iEkiOrder ++ )
		{
			setCentDedEkiJikoku( 
				iEkiOrder , 
				CentDedEkiJikoku( CentDedEkiJikoku::Ekiatsukai_Keiyunasi , CdDedJikoku() , CdDedJikoku() ) 
				);
		}
	}

	//	�n����Ԃ̎n���w
	//
	//�n���w�̎���(���ʉ���������)�́A�ȉ��̂悤�ɂȂ�܂��B
	//- �w���F�ς��܂���B
	//- �������F
	//  - this��Ԃɒ��������w�肳��Ă����ꍇ�F���̒�����
	//  - this��Ԃɒ��������Ȃ��A���������w�肳��Ă����ꍇ�F�r���w�~�܂��Ԃ̔�����
	//  - this��Ԃɒ����������������w�肳��Ă��Ȃ��ꍇ�F�������͂Ȃ�
	//- ������
	//  - �n����Ԃɔ��������w�肳��Ă����ꍇ�F���̔������𒼒ʉ�������Ԃ̔������Ƃ��܂��B
	//  - �n����Ԃɔ��������Ȃ��A���������w�肳��Ă����ꍇ�F�r���w�n����Ԃ̒��������A�V������Ԃ̔������Ƃ��܂��B
	//  - �n����Ԃɒ����������������w�肳��Ă��Ȃ��ꍇ�F�������͂Ȃ�
	if ( iRv <= 0 )
	{
		CentDedEkiJikoku	aCentDedEkiJikokuSyuuchaku = getCentDedEkiJikoku( iEkiOrderSihatsu ) ;
		CentDedEkiJikoku	aCentDedEkiJikokuSihatsu = aRessyaSihatsu.getCentDedEkiJikoku( iEkiOrderSihatsu ) ;

		CentDedEkiJikoku	aCentDedEkiJikokuNew = aCentDedEkiJikokuSyuuchaku ;
		//- �������F
		if ( !aCentDedEkiJikokuSyuuchaku.getChakujikoku().isNull() )
		{
			//�@�r���w�~�܂�̗�Ԃɒ��������w�肳��Ă����ꍇ�F���̒�����
			aCentDedEkiJikokuNew.setChakujikoku( aCentDedEkiJikokuSyuuchaku.getChakujikoku() ) ;
		}
		else if ( !aCentDedEkiJikokuSyuuchaku.getHatsujikoku().isNull() )
		{
			//�@�r���w�~�܂�̗�Ԃɒ��������Ȃ��A���������w�肳��Ă����ꍇ�F�r���w�~�܂��Ԃ̔�����
			aCentDedEkiJikokuNew.setChakujikoku( aCentDedEkiJikokuSyuuchaku.getHatsujikoku() ) ;
		}
		else
		{
			//�@�r���w�~�܂�̗�Ԃɒ����������������w�肳��Ă��Ȃ��ꍇ�F�������͂Ȃ�
			aCentDedEkiJikokuNew.setChakujikoku( CdDedJikoku() ) ;
		}


		//- ������
		if ( !( aCentDedEkiJikokuSihatsu.getHatsujikoku().isNull() ) )
		{
			//  - �n����Ԃɔ��������w�肳��Ă����ꍇ�F���̔������𒼒ʉ�������Ԃ̔������Ƃ��܂��B
			aCentDedEkiJikokuNew.setHatsujikoku( aCentDedEkiJikokuSihatsu.getHatsujikoku() ) ;
		}
		else if ( !( aCentDedEkiJikokuSihatsu.getChakujikoku().isNull() ) )
		{
			//  - �n����Ԃɔ��������Ȃ��A���������w�肳��Ă����ꍇ�F�r���w�n����Ԃ̒��������A�V������Ԃ̔������Ƃ��܂��B
			aCentDedEkiJikokuNew.setHatsujikoku( aCentDedEkiJikokuSihatsu.getChakujikoku() ) ;
		}
		else
		{
			//  - �n����Ԃɒ����������������w�肳��Ă��Ȃ��ꍇ�F�������͂Ȃ�
			aCentDedEkiJikokuNew.setHatsujikoku( CdDedJikoku() ) ;
		}
		setCentDedEkiJikoku( iEkiOrderSihatsu , aCentDedEkiJikokuNew ) ;
	}

	//	�n���w����̉w
	if ( iRv <= 0 )
	{
		for ( int iEkiOrder = iEkiOrderSihatsu + 1 ; 
			iEkiOrder < (int)m_CentDedEkiJikokuCont.size()  ; 
				iEkiOrder ++ )
		{
			CentDedEkiJikoku	aCentDedEkiJikokuSihatsu = aRessyaSihatsu.getCentDedEkiJikoku( iEkiOrder ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikokuSihatsu ) ;
		}
	}
	return iRv ;
}

int CentDedRessya::undirect(
		int iEkiOrder , 
		CentDedRessya* pCentDedRessyaSyuuchaku ,
		CentDedRessya* pCentDedRessyaSihatsu )const 
{
	int iRv = 0 ;


	//���r���w�~�܂��Ԃ̏I���wOrder������
	//��([�I���wOrder�̉w�ƏI���wOrder-1�̉w�̊Ԃɗ�ԉ^�s���Ȃ�]
	//���̏������U�̊Ԃ́A�I���wOrder--����B
	//���I���wOrder��0�Ȃ�G���[)
	//��[�I���wOrder==0]���G���[
	int iEkiOrderSyuuchaku = -1 ;
	if ( iRv >= 0 )
	{
		for ( iEkiOrderSyuuchaku = iEkiOrder ;
			iEkiOrderSyuuchaku > 0 && !isRunBetweenNextEki( iEkiOrderSyuuchaku - 1 ) ;
			iEkiOrderSyuuchaku -- )
		{
		}
		if ( iEkiOrderSyuuchaku == 0 )
		{
			iRv = -1 ;	//	�w��̉wOrder�ł́A���f�͂ł��܂���
		}
	}

	//���r���w�n����Ԃ̎n���wIndex������
	//��([�n���wOrder�̉w�Ǝn���wOrder+1�̉w�̊Ԃɗ�ԉ^�s���Ȃ�]
	//���̏������U�̊Ԃ́A�n���wrOder++����B)
	//��[�n���wOrder==�w��-1]���G���[
	int iEkiOrderSihatsu = -1 ;
	if ( iRv >= 0 )
	{
		for ( iEkiOrderSihatsu = iEkiOrder ;
			iEkiOrderSihatsu < (int)m_CentDedEkiJikokuCont.size() - 1 && 
				!isRunBetweenNextEki( iEkiOrderSihatsu ) ;
			iEkiOrderSihatsu ++ )
		{
		}
		if ( iEkiOrderSihatsu == m_CentDedEkiJikokuCont.size() - 1 )
		{
			iRv = -1 ;	//	�w��̉wOrder�ł́A���f�͂ł��܂���
		}
	}
	//�����f�����Ԃ̃R�s�[��2�쐬�B
	//�������r���w�~�܂��ԁE�r���w�n����ԂƂ���B
	//���r���w�~�܂��Ԃ̕����A�I���wOrder�œ��w�ǂ܂�ɂ���
	//���r���w�n����Ԃ̕����A�n���wOrder�œ��w�n���ɂ���
	if ( iRv >= 0 )
	{
		*pCentDedRessyaSyuuchaku = *this ;
		pCentDedRessyaSyuuchaku->setSyuuchakuEki( iEkiOrderSyuuchaku ) ;
		*pCentDedRessyaSihatsu = *this ;
		pCentDedRessyaSihatsu->setSihatsuEki( iEkiOrderSihatsu ) ;
	}	

	return iRv ;
}
