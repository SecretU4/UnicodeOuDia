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
//$Id: CentDedEkiJikokuCont.cpp 378 2016-11-16 21:10:54Z okm $
/** @file */
#include "stdafx.h"
#include "CentDedEkiJikokuCont.h"
#include "CentDedRosen.h"
#include "CentDedRessya.h"

namespace entDed{

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CentDedEkiJikokuCont::CentDedEkiJikokuCont() 
{
}
CentDedEkiJikokuCont& CentDedEkiJikokuCont::operator=( const CentDedEkiJikokuCont& value ) 
{
	CentDedRosen* pRosen = getRosen() ;

	//��operator=: this ���H���̈ꕔ�ł���ꍇ�́A�w�����̐��͕ύX���܂���
	if ( pRosen != NULL )
	{
		int i ; 
		for ( i = 0 ;i < this->size() && i < value.size() ; i ++ )
		{
			this->set( value.get( i ) , i ) ; 
		}
		//	�E�ӂ̕����v�f�����Ȃ��ꍇ�́A���ӂ̎c��v�f�͋�Ŗ��߂܂��B
		for ( ; i < this->size() ; i++ )
		{
			this->set( CentDedEkiJikoku() , i ) ; 
		}
	}
	else
	{
		super::operator =( value ) ;
	}
	return *this ;
}


	// ********************************
	///@name Mui
	// ********************************
int CentDedEkiJikokuCont::insert( const CentDedEkiJikoku& element , int iIndex )
{
	CentDedRosen* pRosen = getRosen() ;

	//	��Ԃ��H���̈ꕔ�ł���ꍇ�̓G���[�B
	//	(���Ƃ��Ɖw���Ɖw�����̐�����v���Ă��Ȃ��ꍇ�́A�G���[�ɂ��Ȃ��ق���
	//	�悢��������܂���B)
	if ( pRosen != NULL && pRosen->getCentDedEkiCont()->size() == size() )
	{
		return -11 ;	//	��Ԃ��H���̈ꕔ�ł���ꍇ�A�w�����̒ǉ��͂ł��܂���B
	}

	return super::insert( element , iIndex ) ;
}
	
int CentDedEkiJikokuCont::erase( int iIndex  , int iSize ) 
{
	CentDedRosen* pRosen = getRosen() ;

	//	��Ԃ��H���̈ꕔ�ł���ꍇ�̓G���[�B
	if ( pRosen != NULL && pRosen->getCentDedEkiCont()->size()  == size() )
	{
		return -11 ;	//	��Ԃ��H���̈ꕔ�ł���ꍇ�A�w�����̍폜�͂ł��܂���B
	}
	return super::erase( iIndex , iSize ) ;
}
	
int CentDedEkiJikokuCont::set( const CentDedEkiJikoku& element , int iIndex )
{
	return super::set( element , iIndex ) ;
}


	// ********************************
	//@name CentDedEkiJikokuCont-�֘A
	// ********************************
CentDedRosen* CentDedEkiJikokuCont::getRosen()
{
	CentDedRessya* pRessya = getRessya() ;
	if ( pRessya == NULL ){	return NULL ;}
	CentDedRessyaCont* pDiaCont = dynamic_cast<CentDedRessyaCont*>( pRessya->getParent() ) ;
	if ( pDiaCont == NULL ){	return NULL ;}
	return pDiaCont->getRosen() ;
}
const CentDedRosen* CentDedEkiJikokuCont::getRosen()const
{
	const CentDedRessya* pRessya = getRessya() ;
	if ( pRessya == NULL ){	return NULL ;}
	const CentDedRessyaCont* pDiaCont = dynamic_cast<const CentDedRessyaCont*>( pRessya->getParent() ) ;
	if ( pDiaCont == NULL ){	return NULL ;}
	return pDiaCont->getRosen() ;
}

	// ********************************
	//@name CentDedEkiJikokuTrackCont-����
	// ********************************
int CentDedEkiJikokuCont::setable(  const CentDedEkiJikoku& element , int iIndex )const 
{
	const CentDedRosen* pCentDedRosen = getRosen() ;
	if ( pCentDedRosen != NULL )
	{
	}
	return 0 ; 
}

int CentDedEkiJikokuCont::getIndex( const CentDedEkiJikoku* element )const
{
	const Mu<const CentDedEkiJikoku*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;
}
void CentDedEkiJikokuCont::adjust()
{
	//���w����(CentDedEkiJikoku)�̗v�f�����w�R���e�i(CentDedEkiCont)
	//�ƈقȂ�ꍇ�́A�w������ǉ��E�폜���܂��B
	CentDedRosen* pCentDedRosen = getRosen() ;
	if ( pCentDedRosen != NULL )
	{
		CentDedEkiCont* pCentDedEkiCont = pCentDedRosen->getCentDedEkiCont() ;
		//	�w���������Ȃ��ꍇ�͒ǉ�
		while ( size() < pCentDedEkiCont->size() )
		{
			insert( CentDedEkiJikoku() ) ; 
		}
		//	�w�����������ꍇ�͍폜
		while( size() >  pCentDedEkiCont->size() )
		{
			erase( INT_MAX ) ;
		}

	}

	// --------------------------------
	Mu<CentDedEkiJikoku*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		pMu->get( idx )->adjust() ;
	}
}

	// ********************************
	//@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
void CentDedEkiJikokuCont::onEkiInsert( int iEkiOrder )
{
	super::insert( CentDedEkiJikoku() , iEkiOrder ) ;
}

void CentDedEkiJikokuCont::onEkiErase( int iEkiOrder  )
{
	super::erase( iEkiOrder ) ;
}

void CentDedEkiJikokuCont::onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex )
{
	getMuPtr()->get( iEkiOrder )->onEkiTrackInsert(  iEkiTrackIndex ) ;
}
void CentDedEkiJikokuCont::onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex )
{
	getMuPtr()->get( iEkiOrder )->onEkiTrackErase( iEkiTrackIndex ) ;
}



}; //namespace entDed

