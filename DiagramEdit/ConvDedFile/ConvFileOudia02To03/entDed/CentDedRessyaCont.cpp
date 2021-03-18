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
#include "stdafx.h"

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

#include "Cont/CCont_deque.h"
#include "Cont/CaCont.h"
#include "CentDedRessyaCont.h"

// ****************************************************************
//	CentDedRessyaCont
// ****************************************************************
// --------------------------------
//@name CaContFilter-�I�[�o���C�h�\�ȉ��z�֐�
// --------------------------------
CentDedRessyaCont::adaptee_value_type 
CentDedRessyaCont::onSet( const value_type& value , int* piResult ) 
{
	CentDedRessya* pCentDedRessya = new CentDedRessya( m_iEkiCount , m_eRessyahoukou ) ;
	*pCentDedRessya = value ;

	//	�}��������Ԃ̎��Index���K��ȏ�Ȃ�A�O�ɕύX
	if ( pCentDedRessya->getRessyasyubetsuIndex() >= m_iRessyasyubetsuCount ){
		pCentDedRessya->setRessyasyubetsuIndex( m_iRessyasyubetsuCount - 1 ) ;
	}

	return ( pCentDedRessya ) ;
}	
CentDedRessyaCont::value_type 
CentDedRessyaCont::onGet( const adaptee_value_type& value )const 
{
	return ( *value ) ;
}
void CentDedRessyaCont::onErase( const adaptee_value_type& value ) 
{
	delete value ;
}


// ********************************
//	�R���X�g���N�^
// ********************************
CentDedRessyaCont::CentDedRessyaCont( 
		int iEkiCount ,
		ERessyahoukou eRessyahoukou , 
		int iRessyasyubetsuCount )
	: super( new CCont_deque< CentDedRessya* > ) 
	, m_iEkiCount( iEkiCount ) 
	, m_eRessyahoukou( eRessyahoukou )
	, m_iRessyasyubetsuCount( iRessyasyubetsuCount ) 
{
}


CentDedRessyaCont::CentDedRessyaCont( const CentDedRessyaCont& value )
	: super( new CCont_deque< CentDedRessya* > ) 
	, m_iEkiCount( value.m_iEkiCount ) 
	, m_eRessyahoukou( value.m_eRessyahoukou ) 
	, m_iRessyasyubetsuCount( value.m_iRessyasyubetsuCount ) 
{
	//	value �̗�Ԃ��Athis�ɃR�s�[���Ă��܂��B
	CaCont< CentDedRessya >	aCaCont_this( this ) ;
	aCaCont_this.insert( &value ) ;

}
	
CentDedRessyaCont& CentDedRessyaCont::operator=( const CentDedRessyaCont& value )
{
	//	�ێ����Ă����Ԃ��A���ׂĔj�����܂��B
	erase( 0 , INT_MAX ) ;
	//	value �̗�Ԃ��Athis�ɃR�s�[���Ă��܂��B
	CaCont< CentDedRessya >	aCaCont_this( this ) ;
	aCaCont_this.insert( &value ) ;

	return *this ;
}

CentDedRessyaCont::~CentDedRessyaCont()
{
	erase( 0 , INT_MAX ) ;
	
	IfCont< CentDedRessya* >* pAdaptee = getAdaptee() ;
	setAdaptee( NULL ) ;
	delete pAdaptee ;
/*
	//	�w��ԁx�I�u�W�F�N�g���폜���܂��B
	{
		while ( m_CentDedRessyaCont.size() > 0 ){
			CentDedRessya*	pCentDedRessya = m_CentDedRessyaCont.back() ;
			m_CentDedRessyaCont.pop_back() ;
			delete pCentDedRessya ;
		}
	}
*/
}

// ********************************
//	CentDedRessyaCont
// ********************************
int CentDedRessyaCont::insertBlank( int iIndex )
{
	return ( super::insert( CentDedRessya( m_iEkiCount , m_eRessyahoukou ) , iIndex ) ) ;
}
	

int CentDedRessyaCont::EkiIndexOfEkiOrder( int iEkiOrder ) 
{
	int iRv = iEkiOrder ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_iEkiCount - 1 - iEkiOrder ;
	}
	return ( iRv ) ;
}

int CentDedRessyaCont::EkiOrderOfEkiIndex( int iEkiIndex ) 
{
	int iRv = iEkiIndex ;
	if ( m_eRessyahoukou == Ressyahoukou_Nobori ){
		iRv = m_iEkiCount - 1 - iEkiIndex ;
	}
	return ( iRv ) ;
}


// --------------------------------
//@name CentDedRessya ���� 
//	CentDedEkiJikoku �𑝌�
// --------------------------------
int CentDedRessyaCont::onSetCentDedEki( const IfContGet<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder ) 
{
	int iRv = 0 ;

	IfContGet<CentDedRessya*>*	pIfContGet = getIfContGet() ;
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

	IfContGet<CentDedRessya*>*	pIfContGet = getIfContGet() ;
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
	IfContGet<CentDedRessya*>*	pIfContGet = getIfContGet() ;
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
				IfContGet< CentDedRessya* >* pCentDedRessyaContGet = getIfContGet() ;
	
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
				IfContGet< CentDedRessya* >* pCentDedRessyaContGet = getIfContGet() ;
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
	IfContGet< CentDedRessya* >* pCentDedRessyaContGet = getIfContGet() ;

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
	
				IfContGet< CentDedRessya* >* pCentDedRessyaContGet = getIfContGet() ;
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

