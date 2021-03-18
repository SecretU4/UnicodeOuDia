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
/** @file */
//$Id: CentDedEkiTrackCont.cpp 378 2016-11-16 21:10:54Z okm $


#include "stdafx.h"

#include "CentDedEkiTrackCont.h"
#include "CentDedRosen.h"
#include "CentDedEki.h"

namespace entDed{

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CentDedEkiTrackCont::CentDedEkiTrackCont() 
{
	super::insert( CentDedEkiTrack( CentDedEkiTrack::ETrackType_NoboriMain ) ) ;
	super::insert( CentDedEkiTrack( CentDedEkiTrack::ETrackType_KudariMain ) ) ;
}


CentDedEkiTrackCont& CentDedEkiTrackCont::operator=( const CentDedEkiTrackCont& value )
{
	const Mu<const CentDedEkiTrack*>* muSrc = value.getMuPtr() ;
	
	int idxSrc ;
	//	�]�������A���{���̑O�B
	//	�]���悪 Named �Ȃ�㏑���B�]���悪 ���{���Ȃ烋�[�v�I�� 
	for ( idxSrc = 0  
		; muSrc->get( idxSrc )->getTrackType() 
			==  CentDedEkiTrack::ETrackType_Named 
		; idxSrc ++ )
	{
		if ( this->get( idxSrc ).getTrackType() ==  CentDedEkiTrack::ETrackType_Named )
		{
			this->set( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
		else
		{
			this->insert( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
	}
	
	//	�]�������A���{��
	//	�]���悪 Named �Ȃ�폜�B�]���悪 ���{���Ȃ� 
	while( this->get( idxSrc ).getTrackType() != CentDedEkiTrack::ETrackType_NoboriMain )
	{
		this->erase( idxSrc ) ;
	}
	
	//	�]�������A���{���Ɖ���{���̊ԁB
	//	�]���悪 Named �Ȃ�㏑���B�]���悪 ����{���Ȃ烋�[�v�I�� 
	for ( idxSrc ++  
		; muSrc->get( idxSrc )->getTrackType() 
			==  CentDedEkiTrack::ETrackType_Named 
		; idxSrc ++ )
	{
		if ( this->get( idxSrc ).getTrackType() ==  CentDedEkiTrack::ETrackType_Named )
		{
			this->set( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
		else
		{
			this->insert( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
	}
	
	//	�]�������A���{��
	//	�]���悪 Named �Ȃ�폜�B�]���悪 ���{���Ȃ� 
	while( this->get( idxSrc ).getTrackType() != CentDedEkiTrack::ETrackType_KudariMain )
	{
		this->erase( idxSrc ) ;
	}
	
	//	�]�������A����{���̌��
	//	�]���悪 Named �Ȃ�㏑���B�]���悪 ����{���Ȃ烋�[�v�I�� 
	for ( idxSrc ++  
		; idxSrc < muSrc->size()
		; idxSrc ++ )
	{
		if ( this->get( idxSrc ).getTrackType() ==  CentDedEkiTrack::ETrackType_Named )
		{
			this->set( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
		else
		{
			this->insert( *muSrc->get( idxSrc ) , idxSrc ) ;
		}
	}
	
	//	�]����̗]����폜
	this->erase( idxSrc , INT_MAX ) ; 
	
	
	return *this ;
}

// ********************************
//@name Mui
// ********************************
int CentDedEkiTrackCont::insert( const CentDedEkiTrack& element ,  int iIndex) 
{
	int iRv = 0; 
	if ( iIndex == INT_MAX )
	{
		iIndex = size() ;
	}
	
	if ( element.getTrackType() != CentDedEkiTrack::ETrackType_Named )
	{
		iRv = -11 ;	//	�{����ǉ����邱�Ƃ͏o���܂���B
	}
	if ( iRv >= 0 )
	{
		iRv = super::insert( element ,  iIndex ) ;
	}
	//	  ���̃R���e�i�� CentDedEki �̎q�I�u�W�F�N�g�ŁA
	//	���� CentDedEki �� CentDedRosen �ɕ�܂���Ă���ꍇ�A insert() 
	//	���\�b�h�́ACentDedRosen::onEkiTrackInsert( iEkiIndex , iEkiTrackIndex ) 
	//	�ɏ������Ϗ����܂��B
	if ( iRv >= 0 )
	{
		CentDedRosen* pRosen = getRosen() ;
		CentDedEki* pEki = getEki() ;
		if ( pRosen != NULL && pEki != NULL )
		{
			int iEkiIndex = pRosen->getCentDedEkiCont()->getIndex( pEki ) ;
			pRosen->onEkiTrackInsert( iEkiIndex , iIndex ) ; 
		}
	}

	return iRv ;
}
int CentDedEkiTrackCont::erase( int iIndex  , int iSize ) 
{
	int iRv = 0 ;
	if ( iIndex == INT_MAX && iSize != INT_MAX )
	{
		iIndex = (int)size() - iSize ;
	}
	else if ( iIndex != INT_MAX && iSize == INT_MAX )
	{
		iSize = (int)size() - iIndex ;
	}
	if ( !( 0 <= iIndex && iIndex + iSize <= (int)size() ) )
	{
		iRv = -1 ;	//	�C���f�N�X���͈͊O�ł��B
	}
	// --------------------------------	
	if ( iRv >= 0 )
	{
		for ( int i = 0 ; i < iSize ; i ++ )
		{
			if ( getMuPtr()->get( iIndex + i )->getTrackType() != CentDedEkiTrack::ETrackType_Named )
			{
				iRv = -11 ;	//	�{�����폜���邱�Ƃ͏o���܂���B
			}
		}
	}
	// --------------------------------	
	if ( iRv >= 0 )
	{
		iRv = super::erase( iIndex , iSize ) ; 
	}
	// --------------------------------	
	//	  ���̃R���e�i�� CentDedEki �̎q�I�u�W�F�N�g�ŁA
	//	���� CentDedEki �� CentDedRosen �ɕ�܂���Ă���ꍇ�A erase() 
	//	���\�b�h�́ACentDedRosen::onEkiTrackInsert( iEkiIndex , iEkiTrackIndex )
	//	�ɏ������Ϗ����܂��B
	if ( iRv >= 0 )
	{
		CentDedRosen* pRosen = getRosen() ;
		CentDedEki* pEki = getEki() ;
		if ( pRosen != NULL && pEki != NULL )
		{
			int iEkiIndex = pRosen->getCentDedEkiCont()->getIndex( pEki ) ;
			for ( int idx = iIndex + iSize - 1 ; idx >= iIndex ; idx-- )
			{
				pRosen->onEkiTrackErase( iEkiIndex , idx ) ; 
			}
		}
	}
	// --------------------------------	
	return iRv ;
}
int CentDedEkiTrackCont::set( const CentDedEkiTrack& element , int iIndex ) 
{
	int iRv = 0 ; 
	if ( iIndex == INT_MAX )
	{
		iIndex = size() - 1 ;
	}

	if ( iRv >= 0 )
	{
		iRv = setable( element , iIndex ) ;
	}
	if ( iRv >= 0 )
	{
		iRv = super::set( element ,  iIndex ) ;
	}
	return iRv ; 
}
	// ********************************
	//@name CentDedEkiTrackCont-�֘A
	// ********************************

CentDedRosen* CentDedEkiTrackCont::getRosen() 
{
	if ( getEki() == NULL ){	return NULL ;}
	CentDedEkiCont* pEkiCont = dynamic_cast<CentDedEkiCont*>( getEki()->getParent() ) ;
	if ( pEkiCont == NULL ){	return NULL ;}
	return pEkiCont->getRosen() ;
}
const CentDedRosen* CentDedEkiTrackCont::getRosen()const 
{
	if ( getEki() == NULL ){	return NULL ;}
	const CentDedEkiCont* pEkiCont = dynamic_cast<const CentDedEkiCont*>( getEki()->getParent() ) ;
	if ( pEkiCont == NULL ){	return NULL ;}
	return pEkiCont->getRosen() ;
}


	// ********************************
	///@name CentDedEkiTrackCont-����
	// ********************************
int  CentDedEkiTrackCont::setable(  const CentDedEkiTrack& element , int iIndex ) const
{
	int iRv = 0 ;
	if ( iIndex == INT_MAX )
	{
		iIndex = size() - 1 ;
	}
	if ( iRv >= 0 )
	{
		if ( getMuPtr()->get( iIndex )->getTrackType() != element.getTrackType() )
		{
			iRv = -11 ;	//	�Ԑ���ʂ̈قȂ�I�u�W�F�N�g���㏑�����邱�Ƃ͂ł��܂���B
		}
	}

	return iRv ;
}

int  CentDedEkiTrackCont::getIndex( const CentDedEkiTrack* element ) const
{
	const Mu<const CentDedEkiTrack*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;
}

void CentDedEkiTrackCont::adjust() 
{
	Mu<CentDedEkiTrack*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		pMu->get( idx )->adjust() ;
	}
}


int CentDedEkiTrackCont::findRessyaOfEkiTrack( 
		int index , 
		int* piDiaIndex , 
		ERessyahoukou* pRessyahoukou , int* piRessyaIndex ) const
{
	const CentDedRosen* pRosen = getRosen() ;
	const CentDedEki* pEki = getEki() ;
	if ( pRosen != NULL )
	{
		int iEkiIndex = pRosen->getCentDedEkiCont()->getIndex( pEki ) ;
		for ( int iDiaIndex = 0 ; iDiaIndex < pRosen->getCentDedDiaCont()->size() ; iDiaIndex++ )
		{
			const CentDedDia* pDia = pRosen->getCentDedDiaCont()->getMuPtr()->get( iDiaIndex ) ; 
			for ( int iRessyahoukou = Ressyahoukou_Kudari ; 
					iRessyahoukou <= Ressyahoukou_Nobori ; 
					iRessyahoukou ++ ){
				ERessyahoukou	eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
				int iEkiOrder = pRosen->getCentDedEkiCont()->EkiOrderOfEkiIndex( eRessyahoukou , iEkiIndex ) ; 
				const CentDedRessyaCont* pRessyaCont = pDia->getCentDedRessyaCont( eRessyahoukou ) ;
				for ( int iRessyaIndex = 0  ; iRessyaIndex < pRessyaCont->size() ; iRessyaIndex++ )
				{
					const CentDedRessya* pRessya = pRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
					const CentDedEkiJikokuTrackCont* pEkiJikokuTrackCont = pRessya->getCentDedEkiJikokuCont()->getMuPtr()->get( iEkiOrder )->getEkiJikokuTrackCont() ;
					for ( int iEkiJikokuTrackIndex = 0 ; iEkiJikokuTrackIndex < pEkiJikokuTrackCont->size() ; iEkiJikokuTrackIndex++ )
					{
						const CentDedEkiJikokuTrack* pEkiJikokuTrack = pEkiJikokuTrackCont->getMuPtr()->get( iEkiJikokuTrackIndex ) ;
						CentDedEkiTrackSelector aTrackSelector = pEkiJikokuTrack->getTrack() ;
						if ( !aTrackSelector.isNull() && aTrackSelector.getiIndex() == index )
						{
							*piDiaIndex = iDiaIndex ;
							*pRessyahoukou = eRessyahoukou ;
							*piRessyaIndex = iRessyaIndex ;
							return 1 ;
						}
					}
				}
			}
		}


	}
	return 0 ;
}



} //namespace entDed


