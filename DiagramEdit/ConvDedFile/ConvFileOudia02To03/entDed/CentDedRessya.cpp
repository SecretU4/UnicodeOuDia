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

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

#include "CentDedRessya.h"
#include "CdDedJikan.h"

// ****************************************************************
//	CentDedRessya
// ****************************************************************

// --------------------------------
///@name CentDedRosen��CentDedRessyaCont ��p�����o�֐�
// --------------------------------
int CentDedRessya::onSetCentDedEki(const IfContGet<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder) 
{
	int iRv = 0 ;
	
	CentDedEkiCont::CdDedEki	aCdDedEki = pCentDedEkiCont->get( iEkiOrder ) ;

	// --------------------------------
	//	�P�D�@�w�����`�����i�u�����v����j�u�������̂݁v�ɕύX�����ꍇ�A
	//		����������������E�������������Ȃ�
	//	�̎n���w�E�I���w�̉w������
	//		�������������Ȃ��E����������������i����܂ł̒������j
	//	�ɕύX
	if ( !aCdDedEki.getChakujikokuHyouji() && 
				aCdDedEki.getHatsujikokuHyouji() && 
				( iEkiOrder == getSihatsuEki() || iEkiOrder == getSyuuchakuEki() ) ){
		CentDedEkiJikoku	aCentDedEkiJikoku = getCentDedEkiJikoku( iEkiOrder ) ;
		if ( !aCentDedEkiJikoku.getChakujikoku().isNull() && 
			aCentDedEkiJikoku.getHatsujikoku().isNull() ){
			aCentDedEkiJikoku.set( aCentDedEkiJikoku.getEkiatsukai() ,
				CdDedJikoku() , aCentDedEkiJikoku.getChakujikoku() ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikoku ) ;
		}

	}
	


	//	�Q�D�@�w�����`�����i�u�������̂݁v����j�u�����v�ɕύX�����ꍇ�A
	//		�������������Ȃ��E����������������
	//	�̏I���w�̎�����
	//		����������������i����܂ł̔������j�E�������������Ȃ�
	//	�ɕύX
	if ( aCdDedEki.isHatsuChakuHyouji() && 
				iEkiOrder == getSyuuchakuEki() ){
		CentDedEkiJikoku	aCentDedEkiJikoku = getCentDedEkiJikoku( iEkiOrder ) ;
		if ( aCentDedEkiJikoku.getChakujikoku().isNull() && 
			!aCentDedEkiJikoku.getHatsujikoku().isNull() ){
			aCentDedEkiJikoku.set( aCentDedEkiJikoku.getEkiatsukai() ,
				aCentDedEkiJikoku.getHatsujikoku() , CdDedJikoku() ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikoku ) ;
		}

	}


	//	�R�D�@�w�����`�����i�u�����v����j�u�������̂݁v�ɕύX�����ꍇ�A
	//		�������������Ȃ��E����������������
	//	�̎n���w�E�I���w�̉w������
	//		����������������i����܂ł̔������j�E�������������Ȃ�
	//	�ɕύX
	if ( aCdDedEki.getChakujikokuHyouji() && 
				!aCdDedEki.getHatsujikokuHyouji() && 
				( iEkiOrder == getSihatsuEki() || iEkiOrder == getSyuuchakuEki() ) ){
		CentDedEkiJikoku	aCentDedEkiJikoku = getCentDedEkiJikoku( iEkiOrder ) ;
		if ( aCentDedEkiJikoku.getChakujikoku().isNull() && 
			!aCentDedEkiJikoku.getHatsujikoku().isNull() ){
			aCentDedEkiJikoku.set( aCentDedEkiJikoku.getEkiatsukai() ,
				aCentDedEkiJikoku.getHatsujikoku() , CdDedJikoku() ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikoku ) ;
		}

	}
	



	//	�S�D�@�w�����`�����i�u�������̂݁v�i���蒅�����E��蒅�����j�j����u�����v�ɕύX�����ꍇ�A
	//		����������������E�������������Ȃ�
	//	�̎n���w�̉w������
	//		�������������Ȃ��E����������������i����܂ł̒������j
	//	�ɕύX
	if ( aCdDedEki.isHatsuChakuHyouji() && 
				iEkiOrder == getSihatsuEki() ){
		CentDedEkiJikoku	aCentDedEkiJikoku = getCentDedEkiJikoku( iEkiOrder ) ;
		if ( !aCentDedEkiJikoku.getChakujikoku().isNull() && 
			aCentDedEkiJikoku.getHatsujikoku().isNull() ){
			aCentDedEkiJikoku.set( aCentDedEkiJikoku.getEkiatsukai() ,
				CdDedJikoku() , aCentDedEkiJikoku.getChakujikoku()  ) ;
			setCentDedEkiJikoku( iEkiOrder , aCentDedEkiJikoku ) ;
		}

	}


	// --------------------------------
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
			iEkiOrder = m_CentDedEkiJikokuCont.size()  ;
		}
		if ( !( 0 <= iEkiOrder && iEkiOrder <= m_CentDedEkiJikokuCont.size() ) ){
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
			iEkiOrder = m_CentDedEkiJikokuCont.size() - 1 ;
		}
		if ( !( 0 <= iEkiOrder && iEkiOrder < m_CentDedEkiJikokuCont.size() ) ){
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
		ERessyahoukou	eRessyahoukou ,
		int	iRessyasyubetsuIndex ) :
	m_bIsNull( true ) ,
	m_eRessyahoukou( eRessyahoukou ) ,
	m_iRessyasyubetsuIndex( iRessyasyubetsuIndex )
{
	while ( m_CentDedEkiJikokuCont.size() < iEkiJikokuCount ){
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
			iEkiOrder < value.m_CentDedEkiJikokuCont.size() ; iEkiOrder ++ ){
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
			iEkiOrder < m_CentDedEkiJikokuCont.size() ; iEkiOrder ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[iEkiOrder] ;
		if ( iEkiOrder < value.m_CentDedEkiJikokuCont.size() ){
			*pCentDedEkiJikoku = *value.m_CentDedEkiJikokuCont[iEkiOrder] ;
		}	else	{
			*pCentDedEkiJikoku = CentDedEkiJikoku() ;
		}
	} 
	return *this ;
}

CentDedRessya::~CentDedRessya() 
{
	while ( m_CentDedEkiJikokuCont.size() > 0 ){
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
	return ( m_CentDedEkiJikokuCont.size() ) ;
}

CentDedEkiJikoku CentDedRessya::
getCentDedEkiJikoku( int iEkiOrder )const 
{
	CentDedEkiJikoku	aCentDedEkiJikoku ;
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( ( 0 <= iEkiOrder && iEkiOrder < m_CentDedEkiJikokuCont.size() ) ){
		aCentDedEkiJikoku = *m_CentDedEkiJikokuCont[iEkiOrder] ;
	}
	return ( aCentDedEkiJikoku ) ;
}


CentDedRessya& CentDedRessya::
setCentDedEkiJikoku( int iEkiOrder , const CentDedEkiJikoku& value ) 
{
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( 0 <= iEkiOrder && iEkiOrder < m_CentDedEkiJikokuCont.size() ){
		m_bIsNull = false ;
		*m_CentDedEkiJikokuCont[iEkiOrder] = value ;
	}
	return *this ;
}
	// ********************************
	//@name �w�wOrder�x�P�ʂ̑���
	// ********************************
int CentDedRessya::EkiIndexOfEkiOrder( int iEkiOrder ) 
{
	int iRv = iEkiOrder ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_CentDedEkiJikokuCont.size() - 1 - iEkiOrder ;
	}
	return ( iRv ) ;
}

int CentDedRessya::EkiOrderOfEkiIndex( int iEkiIndex ) 
{
	int iRv = iEkiIndex ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_CentDedEkiJikokuCont.size() - 1 - iEkiIndex ;
	}
	return ( iRv ) ;
}


CentDedRessya& CentDedRessya::modifyCentDedEkiJikoku( int iEkiOrder , 
		const CentDedEkiJikoku& value ) 
{
	if ( iEkiOrder == INT_MAX ){
		iEkiOrder = m_CentDedEkiJikokuCont.size() - 1 ;
	}
	if ( 0 <= iEkiOrder && iEkiOrder < m_CentDedEkiJikokuCont.size() ){
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
		if ( !jikokuHatsujikoku.isNull() && !jikokuHatsujikokuPrev.isNull() ){
			CdDedJikan	aCdDedJikan = jikokuHatsujikoku.subJikoku( 
					jikokuHatsujikokuPrev ) ;
			modifyRessyaJikoku( aCdDedJikan , iEkiOrder * 2 + 2 ) ;
		}	else if ( !jikokuChakujikoku.isNull() && !jikokuChakujikokuPrev.isNull() ){
			CdDedJikan	aCdDedJikan = jikokuChakujikoku.subJikoku( 
					jikokuChakujikokuPrev ) ;
			modifyRessyaJikoku( aCdDedJikan , iEkiOrder * 2 + 1 ) ;
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
			iEkiOrder < m_CentDedEkiJikokuCont.size() ; 
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
		if ( !( 0 <= iEkiOrder && iEkiOrder < m_CentDedEkiJikokuCont.size() ) ){
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
	for ( iEkiOrder = m_CentDedEkiJikokuCont.size() - 1 ; 
			iRv == -1 && 
			iEkiOrder >= 0 ; 
			iEkiOrder -- ){
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

int CentDedRessya::setSyuuchakuEki( int iEkiOrder ) 
{
	int	iRv = 0 ;

	if ( iRv >= 0 ){
		if ( !( 0 <= iEkiOrder && iEkiOrder < m_CentDedEkiJikokuCont.size() ) ){
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
			iEkiOrderCurr < m_CentDedEkiJikokuCont.size() ; 
			iEkiOrderCurr ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrderCurr ] ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}
	// --------------------------------
	return ( iRv ) ;
}


	// ********************************
	//@name �w����Order�x�P�ʂ̑���
	// ********************************


CdDedJikoku CentDedRessya::getEkiJikoku( int iJikokuOrder ) 
{
	CdDedJikoku	aCdDedJikoku ;
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= iJikokuOrder && 
				iJikokuOrder < m_CentDedEkiJikokuCont.size() * 2 ) ){
			iRv = -1 ;	//	�p�����[�^���s��
		}
	}
	if ( iRv >= 0 ){
		int iEkiOrder = iJikokuOrder / 2 ;
		bool bHatsu = ( ( iJikokuOrder % 2 ) != 0 );
		if ( bHatsu ){
			aCdDedJikoku = 
				m_CentDedEkiJikokuCont[ iEkiOrder ]->getHatsujikoku() ;
		}	else	{
			aCdDedJikoku = 
				m_CentDedEkiJikokuCont[ iEkiOrder ]->getChakujikoku() ;
		}
	}
	return ( aCdDedJikoku ) ;
}

int CentDedRessya::setEkiJikoku( 
		const CdDedJikoku& aCdDedJikoku ,
		int iJikokuOrder ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= iJikokuOrder && 
				iJikokuOrder < m_CentDedEkiJikokuCont.size() * 2 ) ){
			iRv = -1 ;	//	�p�����[�^���s��
		}
	}
	if ( iRv >= 0 ){
		int iEkiOrder = iJikokuOrder / 2 ;
		bool bHatsu = ( ( iJikokuOrder % 2 ) != 0 );
		if ( bHatsu ){
			m_CentDedEkiJikokuCont[ iEkiOrder ]->setHatsujikoku(
				aCdDedJikoku ) ;
		}	else	{
			m_CentDedEkiJikokuCont[ iEkiOrder ]->setChakujikoku(
				aCdDedJikoku ) ;
		}
	}
	return ( iRv ) ;
}

int CentDedRessya::modifyRessyaJikoku( 
		const CdDedJikan& aCdDedJikan , int iJikokuOrder ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !( 0 <= iJikokuOrder && 
				iJikokuOrder < m_CentDedEkiJikokuCont.size() * 2 ) ){
			iRv = -1 ;	//	�p�����[�^���s��
		}
	}
	if ( iRv >= 0 ){
		int iJikokuOrderCurr ;
		for ( iJikokuOrderCurr = iJikokuOrder ;
				iJikokuOrderCurr < m_CentDedEkiJikokuCont.size() * 2 ;
				iJikokuOrderCurr ++ ){
			CdDedJikoku aCdDedJikoku = getEkiJikoku( iJikokuOrderCurr ) ;
			if ( !aCdDedJikoku.isNull() ){
				aCdDedJikoku = aCdDedJikoku.addSeconds( 
					aCdDedJikan.getTotalSeconds() ) ;
				setEkiJikoku( aCdDedJikoku , iJikokuOrderCurr ) ;
			}
		}
	}
	return ( iRv ) ;
	
}

int CentDedRessya::findrevJikoku( int iJikokuOrder ) 
{
	int iRv = -1 ;
	
	for ( ; iRv == -1 && iJikokuOrder >= 0 ; iJikokuOrder -- ){
		CdDedJikoku	aCdDedJikoku = getEkiJikoku( iJikokuOrder ) ;
		if ( !aCdDedJikoku.isNull() ){
			iRv = iJikokuOrder ;
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
			iEkiOrder < m_CentDedEkiJikokuCont.size() ; 
			iEkiOrder ++ ){
		CentDedEkiJikoku*	pCentDedEkiJikoku = 
			m_CentDedEkiJikokuCont[ iEkiOrder ] ;
		pCentDedEkiJikoku->setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
	}

}

