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
//	CentDedDia.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CentDedDia.h"
#include "CentDedDiaCont.h"

using namespace std ;

#ifdef _MFC_VER 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif


namespace entDed{

// ****************************************************************
//	CentDedDia
// ****************************************************************

// ********************************
//	�R���X�g���N�^
// ********************************
CentDedDia::CentDedDia(const string& strName  )
: m_strName( strName ) 
{
	m_CentDedRessyaCont[0] = new CXRessyaCont( 
		this , 
		Ressyahoukou_Kudari ) ;
	m_CentDedRessyaCont[1] = new CXRessyaCont( 
		this , 
		Ressyahoukou_Nobori ) ;
}

CentDedDia::CentDedDia( 
		int iEkiCount ) 
{
	m_CentDedRessyaCont[0] = new CXRessyaCont( 
		this , 
		iEkiCount , Ressyahoukou_Kudari ) ;
	m_CentDedRessyaCont[1] = new CXRessyaCont( 
		this , 
		iEkiCount , Ressyahoukou_Nobori ) ;
}

CentDedDia::CentDedDia( 
		const string& strName ,
		int iEkiCount ) :
	m_strName( strName ) 
{
	m_CentDedRessyaCont[0] = new CXRessyaCont( 
		this , 
		iEkiCount , Ressyahoukou_Kudari ) ;
	m_CentDedRessyaCont[1] = new CXRessyaCont( 
		this , 
		iEkiCount , Ressyahoukou_Nobori ) ;
}


CentDedDia::CentDedDia( const CentDedDia& value ) :
	m_strName( value.m_strName ) 
{
	m_CentDedRessyaCont[0] = new CXRessyaCont( this , *value.m_CentDedRessyaCont[0] ) ;
	m_CentDedRessyaCont[1] = new CXRessyaCont( this , *value.m_CentDedRessyaCont[1] ) ;
}

CentDedDia& CentDedDia::operator=( const CentDedDia& value )
{
	super::operator=( value ) ; 
	// --------------------------------
	CentDedDiaCont* pDiaCont = dynamic_cast<CentDedDiaCont*>( getParent() ) ;
	if ( pDiaCont != NULL )
	{
		/*
		���㏑��(operator=): ���̃I�u�W�F�N�g���e�I�u�W�F�N�g CentDedDiaCont �̎q�ł���ꍇ�ŁA������̃_�C�������󕶎���ł���ꍇ�A�������͓������O�̃_�C���� CentDedDiaCont �ɂ���ꍇ�͗�O�X���[�B
	�@	  (��������ACentDedDiaCont::set()�ɓn���ƃG���[�ɂȂ�悤�ȃI�u�W�F�N�g�ł���ꍇ�́A����͗�O�X���[�Ƃ��܂�)
		*/
		int iResult = pDiaCont->setable( value , pDiaCont->getIndex( this ) ) ;
		if( iResult < 0 )
		{
			throw LException() ;
		}
	}

	// --------------------------------
	m_strName = value.m_strName ;
	*m_CentDedRessyaCont[0] = *value.m_CentDedRessyaCont[0] ;	
	*m_CentDedRessyaCont[1] = *value.m_CentDedRessyaCont[1] ;	
	
	return *this ;
}
		
CentDedDia::~CentDedDia()
{
	delete m_CentDedRessyaCont[0] ;
	delete m_CentDedRessyaCont[1] ;

}

	// ********************************
	//@name CChildBase-����
	// ********************************
void CentDedDia::setParent( CParentBase* pParent )
{
	super::setParent( pParent ) ; 
	adjust() ;
}
	// ********************************
	//@name CentDedDia-����
	// ********************************
void CentDedDia::setName( const std::string& value )
{
	//	���㏑��(operator=): ���̃I�u�W�F�N�g���e�I�u�W�F�N�g CentDedDiaCont �̎q�ł���ꍇ�ŁA
	//	�_�C�������󕶎���ł���ꍇ�͗�O�X���[�B
	if ( value.length() == 0 )
	{
		throw LException() ;
	}
	// --------------------------------
	CentDedDiaCont* pDiaCont = dynamic_cast<CentDedDiaCont*>( getParent() ) ;
	if ( pDiaCont != NULL )
	{
		/*
		���㏑��(operator=): ���̃I�u�W�F�N�g���e�I�u�W�F�N�g CentDedDiaCont �̎q�ł���ꍇ�ŁA
			�������͓������O�̃_�C���� CentDedDiaCont �ɂ���ꍇ�͗�O�X���[�B
		*/
		int iResult = pDiaCont->findCentDedDiaByName( value ) ;
		if( iResult >= 0 && iResult != pDiaCont->getIndex( this ) )
		{
			throw LException() ;
		}
	}
	// --------------------------------
	m_strName = value ; 
}





	// ********************************
	//@name CentDedDia-����
	// ********************************
void CentDedDia::adjustByEkijikokukeisiki(
		const CentDedEkiCont* pCentDedEkiCont ,
		int iEkiIndex )
{
	int iRv = 0 ;

	//		INT_MAX �́A�������w�肵�����ƂɂȂ�܂��B
	if ( iRv >= 0 )
	{
		if ( iEkiIndex == INT_MAX )
		{
			iEkiIndex = pCentDedEkiCont->size() - 1 ;
		}
		if ( !( 0 <= iEkiIndex && iEkiIndex < pCentDedEkiCont->size() ) )
		{
			iRv = -1 ;	//	iEkiIndex ������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		for ( int iRessyahoukou = Ressyahoukou_Kudari ;
			iRessyahoukou <= Ressyahoukou_Nobori ;
			iRessyahoukou ++ )
		{
			ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;

			int iEkiOrder = pCentDedEkiCont->EkiOrderOfEkiIndex( eRessyahoukou , iEkiIndex ) ;
			CentDedEkiCont::CdDedEki aDedEki = pCentDedEkiCont->getMuPtr( eRessyahoukou )->get( iEkiOrder ) ;

			CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont( eRessyahoukou ) ;

			pCentDedRessyaCont->adjustByEkijikokukeisiki( iEkiOrder , 
				aDedEki.getChakujikokuHyouji() , 
				aDedEki.getHatsujikokuHyouji() ) ;

		}
	}
}

void CentDedDia::adjust()
{
	int iRessyahoukou = 0 ; 
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
			iRessyahoukou <= Ressyahoukou_Nobori ; 
			iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->adjust() ;
	}
}


	// ********************************
	//@name CentDedDia-�w���E��Ԏ�ʐ��̕ύX
	// ********************************

int CentDedDia::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const
{
	int iRv = 0 ;
	ERessyahoukou eRessyahoukouFound = Ressyahoukou_Kudari ;
	int iRessyaIndexFound = -1 ;
	// --------------------------------
	if ( iRv >= 0 ){
			int iRessyahoukou = 0 ;
			for ( iRessyahoukou = Ressyahoukou_Kudari ; 
					iRv == 0 && iRessyahoukou <= Ressyahoukou_Nobori ; 
					iRessyahoukou ++ ){
				ERessyahoukou	eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
				
				iRv = m_CentDedRessyaCont[iRessyahoukou]->
					isExistRessyaOfRessyasyubetsu( 
						iRessyasyubetsuIndex , &iRessyaIndexFound ) ;
				if ( iRv == 1 ){
					eRessyahoukouFound = eRessyahoukou ;
				}
			}
	}
	// --------------------------------
	if ( peRessyahoukou != NULL ){
		*peRessyahoukou = eRessyahoukouFound ;
	}
	if ( piRessyaIndex != NULL ){
		*piRessyaIndex = iRessyaIndexFound ;
	}

	return ( iRv ) ;
}
	// ********************************
	//@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
void CentDedDia::onEkiInsert( int iEkiIndex )
{
	int iRessyahoukou = 0 ; 
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
			iRessyahoukou <= Ressyahoukou_Nobori ; 
			iRessyahoukou ++ ){
		if ( iRessyahoukou == Ressyahoukou_Kudari ){ 
			m_CentDedRessyaCont[iRessyahoukou]->onEkiInsert( 
				m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( 
					iEkiIndex ) 
			) ;
		}	else if ( iRessyahoukou == Ressyahoukou_Nobori ){ 
			m_CentDedRessyaCont[iRessyahoukou]->onEkiInsert( 
				m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( 
					iEkiIndex ) + 1 
			) ;
			//	���� +1 �̈Ӗ��E�E�E
			//	�S�w�̘H���ɁA�n���w�ł���wIndex0��ǉ�����ꍇ�A
			//	���̃R���e�i�̉wOrder 4(����)  �ɒǉ����Ȃ��Ă͂Ȃ�܂���B 
		}
	}
}

void CentDedDia::onEkiErase( int iEkiIndex  )
{
	int iRessyahoukou = 0 ; 
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
			iRessyahoukou <= Ressyahoukou_Nobori ; 
			iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onEkiErase( 
			m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( iEkiIndex ) ) ;
	}
}

void CentDedDia::onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex )
{
	int iRessyahoukou = 0 ;
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
		iRessyahoukou <= Ressyahoukou_Nobori ; iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onEkiTrackInsert( 
			m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( iEkiIndex ) , iEkiTrackIndex ) ;
	}
}

void CentDedDia::onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex )
{
	int iRessyahoukou = 0 ;
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
		iRessyahoukou <= Ressyahoukou_Nobori ; iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onEkiTrackErase( 
			m_CentDedRessyaCont[iRessyahoukou]->EkiOrderOfEkiIndex( iEkiIndex ) , iEkiTrackIndex ) ;
	}
}

void CentDedDia::onRessyasyubetsuInsert( int iRessyasyubetsuIndex )
{
	int iRessyahoukou = 0 ;
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
		iRessyahoukou <= Ressyahoukou_Nobori ; iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onRessyasyubetsuInsert( iRessyasyubetsuIndex ) ;
	}
}

void CentDedDia::onRessyasyubetsuErase( int iRessyasyubetsuIndex )
{
	int iRessyahoukou = 0 ;
	for ( iRessyahoukou = Ressyahoukou_Kudari ; 
		iRessyahoukou <= Ressyahoukou_Nobori ; iRessyahoukou ++ ){
		m_CentDedRessyaCont[iRessyahoukou]->onRessyasyubetsuErase( iRessyasyubetsuIndex ) ;
	}
}



} //namespace entDed
