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
/** @file */
#include "stdafx.h"
#include "CentDedRosen.h"
#include "CentDedDiaCont.h"
#include "NsMu/CaMui.h"
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
//	CentDedDiaCont
// ****************************************************************

// ********************************
//	�R���X�g���N�^
// ********************************


// ********************************
//@name Mui
// ********************************

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
int CentDedDiaCont::set( const CentDedDia& element , int iIndex ) 
{
	if ( iIndex == INT_MAX )
	{
		iIndex = size() - 1 ;
	}
	int iRv = setable( element , iIndex ) ;
	if ( iRv >= 0 ){
		iRv = super::insert( element , iIndex ) ;
	}
	return iRv ;
};
// ********************************
//	CentDedDiaCont
// ********************************
	// ********************************
	//@name CentDedDiaCont-����
	// ********************************
int CentDedDiaCont::setable(  const CentDedDia& element , int iIndex )const 
{
	int idx ;
	if ( element.getName().length() == 0 ) 
	{
		return -2 ;	//	element �ɂ̓_�C�������w�肳��Ă��܂���B
	}
	for ( idx = 0 ; idx < size() ; idx ++ )
	{
		const CentDedDia* pDiaExist = getMuPtr()->get( idx ) ; 
		//	�قȂ�C���f�N�X�ɁA�������O�̃_�C��������΁A�G���[�ł�
		if ( idx != iIndex && element.getName() == pDiaExist->getName() )
		{
			return -3 ;	//	���łɓ����̃_�C�������݂��܂��B
		}
	}
	return 0 ;
}

int  CentDedDiaCont::getIndex( const CentDedDia* element )const 
{
	const Mu<const CentDedDia*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;

}

void CentDedDiaCont::adjust() 
{
	Mu<CentDedDia*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		pMu->get( idx )->adjust() ;
	}
}




int CentDedDiaCont::findCentDedDiaByName( const string& strName )const 
{
	const Mu< const CentDedDia* >* pIfContGet = getMuPtr() ;
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

int CentDedDiaCont::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piDiaIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const
{
	int iRv = 0 ;
	int iDiaIndexFound = -1 ;
	ERessyahoukou eRessyahoukouFound = Ressyahoukou_Kudari ;
	int iRessyaIndexFound = -1 ;
	// --------------------------------
	if ( iRv >= 0 ){

		const Mu<const CentDedDia*>* pIfContGet = getMuPtr() ; 
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iRv == 0 && iDiaIndex < pIfContGet->size() ; iDiaIndex ++ ){
			const CentDedDia*	pCentDedDia = pIfContGet->get( iDiaIndex ) ;
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
	// ********************************
	//@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
void CentDedDiaCont::onEkiInsert( int iEkiIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onEkiInsert( iEkiIndex ) ;
	}
}

void CentDedDiaCont::onEkiErase( int iEkiIndex  )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onEkiErase( iEkiIndex ) ;
	}
}
void CentDedDiaCont:: onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onEkiTrackInsert( iEkiIndex , iEkiTrackIndex ) ;
	}
}
void CentDedDiaCont::onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onEkiTrackErase( iEkiIndex , iEkiTrackIndex ) ;
	}
}
void CentDedDiaCont::onRessyasyubetsuInsert( int iRessyasyubetsuIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onRessyasyubetsuInsert( iRessyasyubetsuIndex ) ;
	}
}
void CentDedDiaCont::onRessyasyubetsuErase( int iRessyasyubetsuIndex )
{
	Mu<CentDedDia*>* muDia = getMuPtr() ;
	for ( int i = 0 ; i < muDia->size() ; i ++ )
	{
		CentDedDia* pDia = muDia->get( i ) ; 
		pDia->onRessyasyubetsuErase( iRessyasyubetsuIndex ) ;
	}
}



	///@}
} //namespace entDed

