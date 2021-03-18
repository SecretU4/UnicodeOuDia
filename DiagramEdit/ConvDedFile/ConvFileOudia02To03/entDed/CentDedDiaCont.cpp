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
//	CentDedDiaCont.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CentDedDiaCont.h"
#include "Cont/CaCont.h"
#include "Cont/CCont_deque.h"

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif



// ****************************************************************
//	CentDedDiaCont
// ****************************************************************
// --------------------------------
//@name CaContFilter-�I�[�o���C�h�\�ȉ��z�֐�
// --------------------------------
CentDedDiaCont::adaptee_value_type 
CentDedDiaCont::onSet( const value_type& value , int* piResult ) 
{
	CentDedDia* pCentDedDia = new CentDedDia( m_iEkiCount , m_iRessyasyubetsuCount ) ;
	*pCentDedDia = value ;
	return ( pCentDedDia ) ;
}
CentDedDiaCont::value_type 
CentDedDiaCont::onGet( const adaptee_value_type& value )const 
{
	return ( *value ) ;
}
	
void CentDedDiaCont::onErase( const adaptee_value_type& value ) 
{
	delete value ;
}

// ********************************
//	�R���X�g���N�^
// ********************************
CentDedDiaCont::CentDedDiaCont( int iEkiCount , int iRessyasyubetsuCount ) 
	:
	CaContFilter< CentDedDia , CentDedDia* >( new CCont_deque< CentDedDia*> ) ,
	m_iEkiCount( iEkiCount ) , 
	m_iRessyasyubetsuCount( iRessyasyubetsuCount ) 
{
}

CentDedDiaCont::CentDedDiaCont( const CentDedDiaCont& value )
	:
	CaContFilter< CentDedDia , CentDedDia* >( new CCont_deque< CentDedDia*> ) ,
	m_iEkiCount( value.m_iEkiCount ) ,
	m_iRessyasyubetsuCount( value.m_iRessyasyubetsuCount ) 
{
	//	value �̃_�C�����Athis�ɃR�s�[���Ă��܂��B
	CaCont< CentDedDia >	aCaCont_this( this ) ;
	aCaCont_this.insert( &value ) ;

}
	
CentDedDiaCont& CentDedDiaCont::operator=( const CentDedDiaCont& value )
{
	//	�ێ����Ă���_�C�����A���ׂĔj�����܂��B
	erase( 0 , INT_MAX ) ;
	//	value �̃_�C�����Athis�ɃR�s�[���Ă��܂��B
	CaCont< CentDedDia >	aCaCont_this( this ) ;
	aCaCont_this.insert( &value ) ;

	return *this ;
}

CentDedDiaCont::~CentDedDiaCont()
{
	IfCont< CentDedDia* >* pAdaptee = getAdaptee() ;
	setAdaptee( NULL ) ;
	delete pAdaptee ;
}
// ********************************
//@name IfCont
// ********************************
int CentDedDiaCont::set( const CentDedDia& element , int iIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( element.getName().empty() ){
			iRv = -2 ;	//	element �ɂ̓_�C�������w�肳��Ă��܂���B
		}
	}
	if ( iRv >= 0 ){
		int iIndexFind = findCentDedDiaByName( element.getName() ) ;
		if ( iIndexFind >= 0 && iIndexFind != iIndex ){
			//	�����C���f�N�X�ɑ΂��ẮA���O�������ł����܂��܂���B
			iRv = -3 ;	//	���łɓ����̃_�C�������݂��܂��B
		}
	}
	if ( iRv >= 0 ){
		iRv = super::set( element , iIndex ) ;
	}
	return iRv ;
};
int CentDedDiaCont::insert( const CentDedDia& element , int iIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( element.getName().empty() ){
			iRv = -2 ;	//	element �ɂ̓_�C�������w�肳��Ă��܂���B
		}
	}
	if ( iRv >= 0 ){
		int iIndexFind = findCentDedDiaByName( element.getName() ) ;
		if ( iIndexFind >= 0 ){
			iRv = -3 ;	//	���łɓ����̃_�C�������݂��܂��B
		}
	}
	if ( iRv >= 0 ){
		iRv = super::insert( element , iIndex ) ;
	}
	return iRv ;
}

// ********************************
//	CentDedDiaCont
// ********************************
	// ********************************
	//@name ����
	// ********************************
int CentDedDiaCont::getEkiCount()const
{
	return m_iEkiCount ;
};
int CentDedDiaCont::getRessyasyubetsuCount()const
{
	return m_iRessyasyubetsuCount ;
};

	// ********************************
	//@name CentDedDiaCont-����
	// ********************************
int CentDedDiaCont::findCentDedDiaByName( const string& strName )const 
{
	const IfContGet< CentDedDia* >* pIfContGet = getIfContGet() ;
	int iRv = -1 ;
	for ( int idx = 0 ; iRv == -1 && idx < pIfContGet->size() ; idx ++ ){
		if ( strName == pIfContGet->get( idx )->getName() ){
			iRv = idx ;
		}
	}
	return ( iRv ) ;
}
	// ********************************
	//@name CentDedDiaCont-���� �w�̑���
	// ********************************
int CentDedDiaCont::onSetCentDedEki( const CentDedEkiCont* pCentDedEkiCont , int iEkiIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		int iDiaIndex ;
		IfContGet< CentDedDia* >* pIfContGet = getIfContGet() ;
		for ( iDiaIndex = 0 ; iDiaIndex < pIfContGet->size() ; iDiaIndex ++ ){
			pIfContGet->get( iDiaIndex )->onSetCentDedEki( pCentDedEkiCont , iEkiIndex ) ;
		}
	}
	return ( iRv ) ;
}
int CentDedDiaCont::insertCentDedEkiJikoku(	int iEkiIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		m_iEkiCount ++ ;

		int iDiaIndex ;
		IfContGet< CentDedDia* >* pIfContGet = getIfContGet() ;
		for ( iDiaIndex = 0 ; iDiaIndex < pIfContGet->size() ; iDiaIndex ++ ){
			pIfContGet->get( iDiaIndex )->insertCentDedEkiJikoku( iEkiIndex ) ;
		}
	}
	return ( iRv ) ;
}
int CentDedDiaCont::eraseCentDedEkiJikoku( int iEkiIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		m_iEkiCount -- ;

		int iDiaIndex ;
		IfContGet< CentDedDia* >* pIfContGet = getIfContGet() ;
		for ( iDiaIndex = 0 ; iDiaIndex < pIfContGet->size() ; iDiaIndex ++ ){
			pIfContGet->get( iDiaIndex )->eraseCentDedEkiJikoku( iEkiIndex ) ;
		}
	}
	return ( iRv ) ;
}

int CentDedDiaCont::insertRessyasyubetsuIndex( int iRessyasyubetsuIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndex == INT_MAX ){
			iRessyasyubetsuIndex = getRessyasyubetsuCount() ;
		}
		if ( !( 0 <= iRessyasyubetsuIndex && 
				iRessyasyubetsuIndex <= getRessyasyubetsuCount() ) ){
			iRv = -1 ;	//	�C���f�N�X���s��
		}
	}
	// --------------------------------
	if ( iRv >= 0 ){
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iDiaIndex < size() ; iDiaIndex ++ ){
			CentDedDia*	pCentDedDia = getIfContGet()->get( iDiaIndex ) ;
			iRv = pCentDedDia->insertRessyasyubetsuIndex( 
					iRessyasyubetsuIndex ) ;
		}
	}
	if ( iRv >= 0 ){
		m_iRessyasyubetsuCount ++ ;
	}
	return ( iRv ) ;
}
int CentDedDiaCont::eraseRessyasyubetsuIndex( int iRessyasyubetsuIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndex == INT_MAX ){
			iRessyasyubetsuIndex = getRessyasyubetsuCount() - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndex && 
				iRessyasyubetsuIndex < getRessyasyubetsuCount() ) ){
			iRv = -1 ;	//	�C���f�N�X���s��
		}
	}
	if ( iRv >= 0 ){
		if ( isExistRessyaOfRessyasyubetsu( 
			iRessyasyubetsuIndex , NULL , NULL , NULL ) > 0 ){
			iRv = -3 ;	//	�w��Ԏ�ʁx�� iRessyasyubtsuIndex �̗�Ԃ����݂��܂��B
		}
	}
	// --------------------------------
	//	iRessyasyubetsuIndex �ȏ�́w��Ԏ��Index�x������
	//	��Ԃ́w��Ԏ��Index�x���A�|�P
	if ( iRv >= 0 ){
		IfContGet<CentDedDia*>* pIfContGet = getIfContGet() ; 
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iDiaIndex < pIfContGet->size() ; iDiaIndex ++ ){
			CentDedDia*	pCentDedDia = pIfContGet->get( iDiaIndex ) ;
			iRv = pCentDedDia->eraseRessyasyubetsuIndex(
				 iRessyasyubetsuIndex );
		}
	}
	if ( iRv >= 0 ){
		m_iRessyasyubetsuCount -- ;
	}
	return ( iRv ) ;
}
int CentDedDiaCont::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piDiaIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) 
{
	int iRv = 0 ;
	int iDiaIndexFound = -1 ;
	ERessyahoukou eRessyahoukouFound = Ressyahoukou_Kudari ;
	int iRessyaIndexFound = -1 ;
	// --------------------------------
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndex == INT_MAX ){
			iRessyasyubetsuIndex = getRessyasyubetsuCount() - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndex && 
				iRessyasyubetsuIndex < getRessyasyubetsuCount() ) ){
			iRv = -1 ;	//	�C���f�N�X���s��

		}
	}
	// --------------------------------
	if ( iRv >= 0 ){

		IfContGet<CentDedDia*>* pIfContGet = getIfContGet() ; 
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iRv == 0 && iDiaIndex < pIfContGet->size() ; iDiaIndex ++ ){
			CentDedDia*	pCentDedDia = pIfContGet->get( iDiaIndex ) ;
			iRv = pCentDedDia->isExistRessyaOfRessyasyubetsu(  
					iRessyasyubetsuIndex , 
					&eRessyahoukouFound , 
					&iRessyaIndexFound )  ;
			if ( iRv == 1 ){
				iDiaIndexFound = iDiaIndex ;
			}
		}
	}
	// --------------------------------
	if ( piDiaIndex != NULL ){
		*piDiaIndex = iDiaIndexFound ;
	}
	if ( peRessyahoukou != NULL ){
		*peRessyahoukou = eRessyahoukouFound ;
	}
	if ( piRessyaIndex != NULL ){
		*piRessyaIndex = iRessyaIndexFound ;
	}

	return ( iRv ) ;
	
}



/*
// --------------------------------
//@name CentDedRosen ��p�����o�֐�
// --------------------------------
int CentDedDiaCont::insertCentDedEkiJikoku(	int iEkiIndex ) 
{

	int iRv = 0 ;
	if ( iRv >= 0 ){
		int idxDia = 0 ;
		for ( idxDia = 0 ; iRv >= 0 && idxDia < m_xCont.size() ; idxDia ++ ){
			iRv = m_xCont.get( idxDia )->insertCentDedEkiJikoku( iEkiIndex ) ;
		}
	}
	if ( iRv >= 0 ){
		m_iEkiCount ++ ;
	}
	return ( iRv ) ;
}
int CentDedDiaCont::eraseCentDedEkiJikoku( int iEkiIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		int idxDia = 0 ;
		for ( idxDia = 0 ; iRv >= 0 && idxDia < m_xCont.size() ; idxDia ++ ){
			iRv = m_xCont.get( idxDia )->eraseCentDedEkiJikoku( iEkiIndex ) ;
		}
	}
	if ( iRv >= 0 ){
		m_iEkiCount -- ;
	}
	return ( iRv ) ;
}

// ********************************
//	�R���X�g���N�^
// ********************************
CentDedDiaCont::CentDedDiaCont( int iEkiCount ) 
	: m_iEkiCount( iEkiCount )
{
}

CentDedDiaCont::CentDedDiaCont( const CentDedDiaCont& value )
	: m_iEkiCount( value.m_iEkiCount )
{
	insert( &value , 0 , value.size() , 0 ) ;
}
	
CentDedDiaCont& CentDedDiaCont::operator=( const CentDedDiaCont& value )
{
	erase( 0 , size() ) ;
	insert( &value , 0 , value.size() , 0 ) ;
	return *this ;
}

CentDedDiaCont::~CentDedDiaCont()
{
	erase( 0 , size() ) ;
}

// ********************************
//	CentDedDiaCont
// ********************************

// ********************************
//	�R���e�i����
// ********************************
	// ********************************
	//@name ���-CentDedRessya
	// ********************************
int CentDedDiaCont::size()const 
{
	return m_xCont.size() ;	
}

CentDedDia* CentDedDiaCont::getp( int idx )const 
{
	return m_xCont.get( idx ) ;
}

int CentDedDiaCont::set( const CentDedDia& value , int iIndex ) 
{
	int iRv = 0 ;
	if ( !( 0 <= iIndex && iIndex < m_xCont.size() ) ){
		iRv = -1 ;	//	�C���f�N�X���s���ł��B
	}
	if ( iRv >= 0 ){
		CentDedDia* pCentDedDia = m_xCont.get( iIndex ) ;
		if ( pCentDedDia != NULL ){
			delete pCentDedDia ;
		}
	}
	if ( iRv >= 0 ){
		CentDedDia* pCentDedDia = new CentDedDia( m_iEkiCount ) ;
		*pCentDedDia = value ;
		int iResult = m_xCont.set( pCentDedDia , iIndex ) ;
		if ( iResult < 0 ){
			delete pCentDedDia ;
		}
	}
	return ( iRv ) ;
}
	
int CentDedDiaCont::insert( const CentDedDia& value , int iIndex , int iSize ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX ){
			iIndex = m_xCont.size() ;
		}
		if ( !( 0 <= iIndex && iIndex <= m_xCont.size() ) ){
			iRv = -1 ;	//	iIndex ���s���ł��B
		}
	}
	if ( iRv >= 0 ){
		for ( int cnt = 0 ; cnt < iSize ; cnt ++ ){
			CentDedDia* pCentDedDia = new CentDedDia( m_iEkiCount ) ;
			*pCentDedDia = value ;
			int iResult = m_xCont.insert( pCentDedDia , iIndex + cnt ) ;
			if ( iResult < 0 ){
				delete pCentDedDia ;
				iRv = -1 ;	//	iIndex ���s���ł��B
			}
		}
	}
	return ( iRv ) ;
}

int CentDedDiaCont::insert( const CentDedDiaCont* pSrc , 
		int iSrcIndex , int iSize , int iIndex ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX ){
			iIndex = m_xCont.size() ;
		}
		if ( !( 0 <= iIndex && iIndex <= m_xCont.size() ) ){
			iRv = -1 ;	//	iIndex ���s���ł��B
		}
	}
	if ( iRv >= 0 ){
		if ( iSrcIndex == INT_MAX ){
			iSrcIndex = pSrc->size() - iSize ;
		}
		if ( !( 0 <= iSrcIndex && iSrcIndex <= pSrc->size() - iSize ) ){
			iRv = -2 ;	//	iSrcIndex ���s���ł��B
		}
	}
	if ( iRv >= 0 ){
		for ( int cnt = 0 ; cnt < iSize ; cnt ++ ){
			CentDedDia* pCentDedDia = new CentDedDia( m_iEkiCount ) ;
			*pCentDedDia = *pSrc->getp( iIndex + cnt ) ;
			int iResult = m_xCont.insert( pCentDedDia , iIndex + cnt ) ;
			if ( iResult < 0 ){
				delete pCentDedDia ;
				iRv = -1 ;
			}
		}
	}
	return ( iRv ) ;
}
	
int CentDedDiaCont::erase( int iIndex , int iSize ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX && iSize == INT_MAX ){
			iRv = -1 ;	//	iIndex ���s���ł��B
		}
	}
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX ){
			iIndex = m_xCont.size() - iSize ;
		}
		if ( iSize == INT_MAX ){
			iSize = m_xCont.size() - iIndex ;
		}
		if ( !( 0 <= iIndex && iIndex <= m_xCont.size() - iSize ) ){
			iRv = -1 ;	//	iIndex ���s���ł��B
		}
	}
	if ( iRv >= 0 ){
		for ( int cnt = 0 ; cnt < iSize ; cnt ++ ){
			CentDedDia* pCentDedDia = m_xCont.get( iIndex ) ;
			if ( pCentDedDia != NULL ){
				delete pCentDedDia ;
			}
			m_xCont.erase( iIndex ) ;
		}
	}
	return ( iRv ) ;
};
*/
