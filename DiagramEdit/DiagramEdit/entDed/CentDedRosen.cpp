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
//	CentDedRosen.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include <assert.h>

#include "NsMu/CaMui.h" 
#include "CentDedRosen.h"

using namespace std ;


#ifdef _MFC_VER 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

namespace entDed{

const char nameRessyasyubetsuDefault[] = "����" ; 

// ----------------------------------------------------------------
//	CentDedRosen::CXCentDedEkiCont
// ----------------------------------------------------------------
	// ********************************
	//	�R���X�g���N�^
	// ********************************

	// ********************************
	//	Mui
	// ********************************

int CentDedRosen::CXCentDedEkiCont::insert( const CentDedEki& element , int iIndex )
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX ){
			iIndex = size() ;
		}
		if ( !( 0 <= iIndex && iIndex <= size() ) ){
			iRv = -1 ;
		}
	}	
	if ( iRv >= 0 ){
		iRv = super::insert( element , iIndex ) ;
	}
	return ( iRv ) ;
}
int CentDedRosen::CXCentDedEkiCont::erase( int iIndex  , int iSize ) 
{
	int iRv = 0 ;
	
	if ( iRv >= 0 ){
		if ( iIndex == INT_MAX && iSize == INT_MAX ){
			iRv = -1 ;
		}	else if ( iIndex == INT_MAX ){
			iIndex = size() - iSize ;
		}	else if ( iSize == INT_MAX ){
			iSize = size() - iIndex ;
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= size() ) ){
			iRv = -1 ;
		}
	}	
	
	if ( iRv >= 0 ){
		iRv = super::erase( iIndex , iSize ) ;
	}

	return ( iRv ) ;
};
		// ********************************
		//@name CentDedEkiCont-�֘A
		// ********************************
CentDedRosen*  CentDedRosen::CXCentDedEkiCont::getRosen()
{
	CentDedRosen* pOuter = (CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedEkiCont ) ) ;
	return pOuter ;
}
const CentDedRosen*  CentDedRosen::CXCentDedEkiCont::getRosen()const 
{
	const CentDedRosen* pOuter = (const CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedEkiCont ) ) ;
	return pOuter ;
}

// ----------------------------------------------------------------
//	CentDedRosen::CXCentDedRessyasyubetsuCont
// ----------------------------------------------------------------
	// ********************************
	//	�R���X�g���N�^
	// ********************************
CentDedRosen::CXCentDedRessyasyubetsuCont::	CXCentDedRessyasyubetsuCont() 
{
	//����̗�Ԏ�ʂ̒ǉ��́ACentDedRosen::CentDedRosen �ōs���܂��B
}
	// ********************************
	//	Mui
	// ********************************


		// ********************************
		//@name CentDedEkiCont-�֘A
		// ********************************
CentDedRosen* CentDedRosen::CXCentDedRessyasyubetsuCont::getRosen()
{
	CentDedRosen* pOuter = (CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedRessyasyubetsuCont ) ) ;
	return pOuter ;
}
const CentDedRosen* CentDedRosen::CXCentDedRessyasyubetsuCont:: getRosen()const 
{
	const CentDedRosen* pOuter = (const CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedRessyasyubetsuCont ) ) ;
	return pOuter ;
}

// ----------------------------------------------------------------
//	CentDedRosen::CXCentDedDiaCont
// ----------------------------------------------------------------
		// ********************************
		//	�R���X�g���N�^
		// ********************************

		// ********************************
		//@name CentDedDiaCont-�֘A
		// ********************************
CentDedRosen* CentDedRosen::CXCentDedDiaCont::getRosen()
{
	CentDedRosen* pOuter = (CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedDiaCont ) ) ;
	return pOuter ;
}
const CentDedRosen* CentDedRosen::CXCentDedDiaCont::getRosen()const 
{
	const CentDedRosen* pOuter = (const CentDedRosen*)( ((char*)this) - offsetof( CentDedRosen , m_CentDedDiaCont ) ) ;
	return pOuter ;
}
		

// ****************************************************************
//	CentDedRosen
// ****************************************************************

// ********************************
//	�R���X�g���N�^
// ********************************
CentDedRosen::CentDedRosen() 
	: m_jikokuKitenJikoku( 0 , 0 , 0 ) 
	, m_iDiagramDgrYZahyouKyoriDefault( 60 )
{
	//	�f�t�H���g�́w��Ԏ�ʁx�̖��O��ݒ肵�܂��B
	m_CentDedRessyasyubetsuCont.insert( 
		CentDedRessyasyubetsu( nameRessyasyubetsuDefault , ""  ) , 
		INT_MAX ) ;
}
	

CentDedRosen::CentDedRosen( const CentDedRosen& value )
	: m_CentDedRessyasyubetsuCont( value.m_CentDedRessyasyubetsuCont ) 
{
	m_strName = value.m_strName ;
	m_jikokuKitenJikoku = value.m_jikokuKitenJikoku ;
	m_iDiagramDgrYZahyouKyoriDefault = value.m_iDiagramDgrYZahyouKyoriDefault ;
	m_strComment = value.m_strComment ;

	CaMui<CentDedEki>( &m_CentDedEkiCont ).insert( &value.m_CentDedEkiCont , 0 , INT_MAX , 0 ) ;
	m_CentDedDiaCont = value.m_CentDedDiaCont ;
}
	
CentDedRosen& CentDedRosen::operator=( const CentDedRosen& value )
{
	// --------------------------------
	//	����܂ł̒l��j��
	// --------------------------------

	m_CentDedDiaCont.erase( 0 , INT_MAX ) ;

	//	�f�t�H���g��Ԃ݂̂ɂ��܂��B
	m_CentDedRessyasyubetsuCont.erase( 1 , INT_MAX ) ;
	m_CentDedRessyasyubetsuCont.set( 
		CentDedRessyasyubetsu( nameRessyasyubetsuDefault , ""  ) , 
		INT_MAX ) ;

	m_CentDedEkiCont.erase( 0 , INT_MAX ) ;

	// --------------------------------
	//	�l���R�s�[
	// --------------------------------
	
	m_strName = value.m_strName ;
	m_jikokuKitenJikoku = value.m_jikokuKitenJikoku ;
	m_iDiagramDgrYZahyouKyoriDefault = value.m_iDiagramDgrYZahyouKyoriDefault ;
	m_strComment = value.m_strComment ;
	m_CentDedEkiCont = value.m_CentDedEkiCont ;
	m_CentDedRessyasyubetsuCont = value.m_CentDedRessyasyubetsuCont ;

	m_CentDedDiaCont = value.m_CentDedDiaCont ;

	return ( *this ) ;
}

	
// ********************************
//	CentDedRosen
// ********************************
	// ********************************
	//@name ����
	// ********************************
	// ********************************
	//@name ���-CentDedEki
	// ********************************
	
	// ********************************
	//@name ���-CentDedRessyasyubetsu
	// ********************************

	
	// ********************************
	//@name ���-CentDedDia
	// ********************************

	// ********************************
	//@name ����
	// ********************************
void CentDedRosen::insert( 
	const CentDedRosen& rosenToAdd_enter ,
	int iEkiIndexToInsert ) 
{
	CentDedRosen rosenToAdd = rosenToAdd_enter ;
	//���g�����wIndex��(�N�_��)�E�g�����Index��(�I�_��)������
	//	��[�g����悪�n���w]
	//�@�@	���g�����wIndex��=-1
	//�@�@	���g�����wIndex��=���͂��ꂽ�g�����̉wIndex
	//	��[�g����悪���ԉw]
	//�@�@	���g�����wIndex��=���͂��ꂽ�g�����̉wIndex
	//�@�@	���g�����wIndex��=���͂��ꂽ�g�����̉wIndex
	//	��[�g����悪�I���w]
	//�@�@	���g�����wIndex��=�w��-1
	//�@�@	���g�����wIndex��=�w��
	int iEkiIndexToInsertMin = -1 ;
	int iEkiIndexToInsertMax = -1 ;
	{
		//��[�g����悪�n���w]
		if ( iEkiIndexToInsert == 0 )
		{
			iEkiIndexToInsertMin = -1 ;
			iEkiIndexToInsertMax = iEkiIndexToInsert ;
		}
		//��[�g����悪���ԉw]
		//	���g�����wIndex��=���͂��ꂽ�g�����̉wIndex
		//	���g�����wIndex��=���͂��ꂽ�g�����̉wIndex
		else if ( 0 < iEkiIndexToInsert &&
			iEkiIndexToInsert < getCentDedEkiCont()->size() - 1 )
		{
			iEkiIndexToInsertMin = iEkiIndexToInsert ;
			iEkiIndexToInsertMax = iEkiIndexToInsert ;
		}
		//��[�g����悪�I���w]
		//	���g�����wIndex��=�w��-1
		//	���g�����wIndex��=�w��
		else
		{
			iEkiIndexToInsertMin = getCentDedEkiCont()->size() - 1 ;
			iEkiIndexToInsertMax = getCentDedEkiCont()->size() ;
		}
	}
	//��[�g����悪���ԉw]�Ȃ�A���̉w�𕪊�
	if ( 0 < iEkiIndexToInsertMin &&
			iEkiIndexToInsertMax < getCentDedEkiCont()->size() - 1 )
	{
		//�@���g�����wIndex��=���͂��ꂽ�g�����̉wIndex
		//�@���g�����wIndex��=���͂��ꂽ�g�����̉wIndex+1
		iEkiIndexToInsertMax = iEkiIndexToInsertMin + 1 ;

		//�@���g�����wIndex���Ɠ����w���A�g�����wIndex+1�̈ʒu�ɒǉ�
		//�@���g�����wIndex���̉w�͉��蒅����
		//�@���g�����wIndex��̉w�͏�蒅����
		{
			CentDedEkiCont* pCentDedEkiCont = getCentDedEkiCont() ;
			CentDedEki*	pDedEkiInsertMin = pCentDedEkiCont->getMuPtr()->get( iEkiIndexToInsertMin ) ;
			pCentDedEkiCont->insert( *pDedEkiInsertMin , iEkiIndexToInsertMax ) ;
			CentDedEki*	pDedEkiInsertMax = pCentDedEkiCont->getMuPtr()->get( iEkiIndexToInsertMax ) ;
			pDedEkiInsertMin->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_KudariChaku ) ;
			pDedEkiInsertMax->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
		}

		//���S�_�C���̃��[�v
		CentDedDiaCont* pCentDedDiaCont = &m_CentDedDiaCont ;
		int idxDia ;
		for ( idxDia = 0 ; idxDia < pCentDedDiaCont->size() ; idxDia ++ )
		{
			CentDedDia* pCentDedDia = pCentDedDiaCont->getMuPtr()->get( idxDia ) ;
			//�������ԑS��Ԃ̃��[�v
			//���@���g�����wOrder���E�g�����wOrder������߂�
			{
				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( Ressyahoukou_Kudari ) ;
				int iEkiOrderToInsertMin = -1 ;
				int iEkiOrderToInsertMax = -1 ;
				{
					int iEkiOrder1 = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin ) ;
					int iEkiOrder2 = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax ) ;
					iEkiOrderToInsertMin = min( iEkiOrder1 , iEkiOrder2 ) ;
					iEkiOrderToInsertMax = max( iEkiOrder1 , iEkiOrder2 ) ;
				}

				for ( int idxRessya = 0 ; idxRessya < pCentDedRessyaCont->size() ; idxRessya ++ )
				{
					CentDedRessya* pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( idxRessya ) ;
					CentDedEkiJikoku aEkiJikokuToInserMin = pCentDedRessya->getCentDedEkiJikoku( iEkiOrderToInsertMin ) ;
					CentDedEkiJikoku aEkiJikokuToInserMax = pCentDedRessya->getCentDedEkiJikoku( iEkiOrderToInsertMax ) ;

					//���@��[�g�����wOrder�����n���w�̗��]
					//���@���g�����wOrder��ɁA�g�����Order�����R�s�[
					//���@���g�����wOrder���́A�^�s�Ȃ��Ƃ���B
					if ( pCentDedRessya->getSihatsuEki() == iEkiOrderToInsertMin )
					{
						aEkiJikokuToInserMax = aEkiJikokuToInserMin ;
						aEkiJikokuToInserMin.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
					}
					//���@��[�g�����wIndex�������ԉw�̗��]
					//���@���@���g�����wOrder��ɁA�g�����wOrder���̉w�������R�s�[
					else if ( pCentDedRessya->getSihatsuEki() < iEkiOrderToInsertMin && 
						iEkiOrderToInsertMin < pCentDedRessya->getSyuuchakuEki() ) 
					{
						aEkiJikokuToInserMax = aEkiJikokuToInserMin ;
					}
					//���@��[�g�����wOrder�����I���w�̗��]
					//���@�@�g�����wOrder���́A���̂܂܂Ƃ���B
					//���@�@�g�����wOrder��́A�^�s�Ȃ��Ƃ���B
					else if ( pCentDedRessya->getSyuuchakuEki() == iEkiOrderToInsertMin )
					{
						aEkiJikokuToInserMax.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
					}

					pCentDedRessya->setCentDedEkiJikoku( iEkiOrderToInsertMin , aEkiJikokuToInserMin ) ;
					pCentDedRessya->setCentDedEkiJikoku( iEkiOrderToInsertMax , aEkiJikokuToInserMax ) ;
				}
			}

			//������ԑS��Ԃ̃��[�v
			//  �@���g�����wOrder���E�g�����wOrder������߂�
			{
				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( Ressyahoukou_Nobori ) ;
				int iEkiOrderToInsertMin = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin ) ;
				int iEkiOrderToInsertMax = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax ) ;
				for ( int idxRessya = 0 ; idxRessya < pCentDedRessyaCont->size() ; idxRessya ++ )
				{
					CentDedRessya* pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( idxRessya ) ;
					CentDedEkiJikoku aEkiJikokuToInserMin = pCentDedRessya->getCentDedEkiJikoku( iEkiOrderToInsertMax ) ;
					CentDedEkiJikoku aEkiJikokuToInserMax = pCentDedRessya->getCentDedEkiJikoku( iEkiOrderToInsertMin ) ;

					//��[�g�����wOrder�傪�n���w�̗��]
					//���g�����wOrder���́A���̂܂܂Ƃ���B
					//���g�����wOrder��́A�^�s�Ȃ��Ƃ���B
					if ( pCentDedRessya->getSihatsuEki() == iEkiOrderToInsertMax )
					{
						aEkiJikokuToInserMax.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
					}
					//��[�g�����wIndex�傪���ԉw�̗��]
					//���@���g�����wIndex���ɁA�g�����wIndex��̉w�������R�s�[
					//���@���g�����wIndex���̉w�������w�����`��(�������̂�)�ɍ��킹�ĕ␳
					//���@��(�g�����wIndex���̔�������NULL�ɕύX)
					//���@���g�����wIndex��̉w�������w�����`��(�������̂�)�ɍ��킹�ĕ␳
					//���@��(�g�����wIndex��̒�������NULL�ɕύX)
					else if ( pCentDedRessya->getSihatsuEki() < iEkiOrderToInsertMax && 
						iEkiOrderToInsertMax < pCentDedRessya->getSyuuchakuEki() ) 
					{
						aEkiJikokuToInserMin = aEkiJikokuToInserMax ;
					}
					//��[�g�����wIndex�傪�I���w�̗��]
					//���g�����wIndex���ɁA�w�������R�s�[
					//���g�����wIndex��́A�^�s�Ȃ��Ƃ���B
					else if ( pCentDedRessya->getSyuuchakuEki() == iEkiOrderToInsertMax )
					{
						aEkiJikokuToInserMin = aEkiJikokuToInserMax ;
						aEkiJikokuToInserMax.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ;
					}

					pCentDedRessya->setCentDedEkiJikoku( iEkiOrderToInsertMin , aEkiJikokuToInserMin ) ;
					pCentDedRessya->setCentDedEkiJikoku( iEkiOrderToInsertMax , aEkiJikokuToInserMax ) ;
				}
			}
		}
		//���g�����wIndex���̉w�������w�����`���ɍ��킹�ĕ␳
		//���@���w�������w�����`���ɍ��킹�ĕ␳
		//���@�@�@��[�w�����`���ɒ���������E�������Ȃ��A
		//���@  �@���w�����ɒ������Ȃ��A����������]
		//���@  �@���������ɂ͔��������R�s�[�A��������NULL�B
		//���@  �@��[�w�����`���ɒ������Ȃ��E����������
		//���@  �@���w�����ɒ���������A�������Ȃ�]
		//���@  �@���������ɂ͒��������R�s�[�A��������NULL�B
		//���@  �@��[�w���n���w�E
		//���@  �@���w�����`���ɒ���������E����������A
		//���@  �@���w�����ɒ���������A�������Ȃ�]
		//���@  �@���������ɂ͒��������R�s�[�A��������NULL�B
		//���@  �@��[�w���I���w�E
		//���@  �@�@�w�����`���ɒ���������E����������
		//���@  �@�@�w�����ɒ������Ȃ��A����������]
		//���@  �@�@�������ɂ͔��������R�s�[�A��������NULL�B
		//���g�����wIndex��̉w�������w�����`���ɍ��킹�ĕ␳
		adjustByEkijikokukeisiki( iEkiIndexToInsertMin ) ;
		adjustByEkijikokukeisiki( iEkiIndexToInsertMax ) ;
	}
	//��[�g����悪�N�_�w]�Ȃ�A���̉w�̉w�����`����[��蒅����]�Ƃ���
	//�@�@��[�g�����wIndex��=-1,�g�����wIndex��=0]
	//�@�@�@�@�g�����wIndex�����蒅�����Ƃ���
	//  �@���g�����wIndex��̉w�������w�����`���ɍ��킹�ĕ␳
	else if ( iEkiIndexToInsertMin == -1 &&
			iEkiIndexToInsertMax == 0 )
	{
		CentDedEkiCont* pCentDedEkiCont = getCentDedEkiCont() ;
		CentDedEki*	pDedEkiInsert = pCentDedEkiCont->getMuPtr()->get( iEkiIndexToInsertMax ) ;
		pDedEkiInsert->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
		adjustByEkijikokukeisiki( iEkiIndexToInsertMax ) ;
	}
	//��[�g����悪�I�_�w]�Ȃ�A���̉w�̉w�����`����[���蒅����]�Ƃ���
	//�@�@��[�g����悪Index��=�w��-1 AND �g�����wIndex��=�w��]
	//�@�@�@�@�g�����wIndex�������蒅�����Ƃ���
	//  �@���g�����wIndex���̉w�������w�����`���ɍ��킹�ĕ␳
	else if ( iEkiIndexToInsertMin == getCentDedEkiCont()->size() - 1 &&
			iEkiIndexToInsertMax == getCentDedEkiCont()->size() ) 
	{
		CentDedEkiCont* pCentDedEkiCont = getCentDedEkiCont() ;
		CentDedEki*	pDedEkiInsert = pCentDedEkiCont->getMuPtr()->get( iEkiIndexToInsertMin ) ;
		pDedEkiInsert->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_KudariChaku ) ;
		adjustByEkijikokukeisiki( iEkiIndexToInsertMin ) ;
	}




	//���w��ǉ�
	//�@�@���g�����H���t�@�C���̉w�����ׂĒǉ�����B
	//�@�@�@�ǉ�����wIndex�́A�g�����wIndex��+1�B
	//		��[�g�����H���t�@�C���̋N�_�w�̉w�����`���������ȊO]
	//		  ���̉w�̉w�����`����[��蒅����]�Ƃ���
	//		��[�g�����H���t�@�C���̏I�_�w�̉w�����`���������ȊO]
	//		  ���̉w�̉w�����`����[���蒅����]�Ƃ���
	//�@�@���g�����wIndex��ɁA�ǉ������w�������Z
	{
		CentDedEkiCont* pCentDedEkiCont = &m_CentDedEkiCont ;
		const CentDedEkiCont* pCentDedEkiContToAdd = rosenToAdd.getCentDedEkiCont() ;
		for ( int idxEki = 0 ; idxEki < pCentDedEkiContToAdd->size() ; idxEki ++ )
		{
			CentDedEki aEki = *pCentDedEkiContToAdd->getMuPtr()->get( idxEki ) ;
			if ( idxEki == 0 && aEki.getEkijikokukeisiki() != CentDedEki::Jikokukeisiki_Hatsuchaku )
			{
				aEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
			}
			else if ( idxEki == pCentDedEkiContToAdd->size() - 1 && 
				aEki.getEkijikokukeisiki() != CentDedEki::Jikokukeisiki_Hatsuchaku )
			{
				aEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_KudariChaku ) ;
			}

			pCentDedEkiCont->insert( 
				aEki ,
				iEkiIndexToInsertMin + 1 + idxEki ) ;


			iEkiIndexToInsertMax ++ ;

		}
	}

	//��[�g����悪���ԉw]�Ȃ�A�g�����wIndex���r���w�ƂȂ��Ԃ́A
	//�@�@�@�@�@�@�@�@�@�@�ǉ����ꂽ�w�̉w�������o�R�Ȃ��ɂ���B
	if ( 0 < iEkiIndexToInsertMin &&
			iEkiIndexToInsertMax < getCentDedEkiCont()->size() - 1 )
	{
		//�@�@���S��Ԃ̃��[�v
		//�@�@�@�@������E���̃��[�v
		//�@�@�@�@  �@���g�����wOrder���E�g�����wOrder������߂�
		//�@�@�@�@�@�@��[�n���w���g�����wOrder�����O AND 
		//�@�@�@�@�@�@�@�I���w���g�����wOrder�����]
		//�@�@�@�@�@�@�@�g�����wOrder��+1�`�g�����wOrder��-1�̉w������
		//�@�@�@�@�@�@�@�o�R�Ȃ��ɂ���B
		CentDedDiaCont* pCentDedDiaCont = &m_CentDedDiaCont ;
		int idxDia ;
		for ( idxDia = 0 ; idxDia < pCentDedDiaCont->size() ; idxDia ++ )
		{
			CentDedDia* pCentDedDia = pCentDedDiaCont->getMuPtr()->get( idxDia ) ;
			//�������ԑS��Ԃ̃��[�v
			//���@���g�����wOrder���E�g�����wOrder������߂�
			for ( int iRessyahoukou = Ressyahoukou_Kudari ;
				iRessyahoukou <= Ressyahoukou_Nobori ;
				iRessyahoukou ++ )
			{
				ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;

				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;
				int iEkiOrderToInsertMin = -1 ;
				int iEkiOrderToInsertMax = -1 ;
				{
					int iEkiOrder1 = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin ) ;
					int iEkiOrder2 = pCentDedRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax ) ;
					iEkiOrderToInsertMin = min( iEkiOrder1 , iEkiOrder2 ) ;
					iEkiOrderToInsertMax = max( iEkiOrder1 , iEkiOrder2 ) ;
				}

				for ( int idxRessya = 0 ; idxRessya < pCentDedRessyaCont->size() ; idxRessya ++ )
				{
					//�@�@�@�@�@�@��[�n���w���g�����wOrder�����O AND 
					//�@�@�@�@�@�@�@�I���w���g�����wOrder�����]
					//�@�@�@�@�@�@�@�g�����wOrder��+1�`�g�����wOrder��-1�̉w������
					//�@�@�@�@�@�@�@�o�R�Ȃ��ɂ���B
					CentDedRessya* pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( idxRessya ) ;
					if ( pCentDedRessya->getSihatsuEki() < iEkiOrderToInsertMin && 
						iEkiOrderToInsertMax < pCentDedRessya->getSyuuchakuEki() )
					{

						CentDedEkiJikoku aEkijikokuKeiyunasi( 
							CentDedEkiJikoku::Ekiatsukai_Keiyunasi ,
							CdDedJikoku() , CdDedJikoku() ) ;
						for ( int iEkiOrder = iEkiOrderToInsertMin + 1 ;
							iEkiOrder <= iEkiOrderToInsertMax - 1 ;
							iEkiOrder ++ )
						{
							pCentDedRessya->setCentDedEkiJikoku( iEkiOrder ,aEkijikokuKeiyunasi ) ; 
						}
					}
				}
			}
		}
	}
	//����Ԏ�ʂ̃}�[�W
	//�@�@���g�����H���t�@�C���̗�Ԏ�ʂɂ�郋�[�v
	//�@�@�@�@��[�����̗�Ԏ�ʂ��ҏW���̘H���t�@�C���ɑ��݂��Ȃ�]��Ԏ�ʂ�
	//�@�@�@�@�@�ҏW���̘H���t�@�C���ɒǉ�
	//�@�@�@�@����Ԏ�ʑΏƕ\(�g�����H���t�@�C���̗�Ԏ��Index��
	//�@�@�@�@�@�g�����H���t�@�C���̗�Ԏ��Index �̑Ώƕ\���쐬
	deque<int>	arRessyasyubetsuIdx_AddedToThis ;
	{
		CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont = this->getCentDedRessyasyubetsuCont() ;
		const CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuContToAdd = rosenToAdd.getCentDedRessyasyubetsuCont() ;
		

		const Mu<const CentDedRessyasyubetsu*>* muCentDedRessyasyubetsuToAdd =
				pCentDedRessyasyubetsuContToAdd->getMuPtr() ;
		for ( int idxToAdd = 0 ; idxToAdd < muCentDedRessyasyubetsuToAdd->size() ; idxToAdd ++ )
		{
			const CentDedRessyasyubetsu* pCentDedRessyasyubetsuToAdd = 
				muCentDedRessyasyubetsuToAdd->get( idxToAdd ) ;

			Mu<CentDedRessyasyubetsu*>* muCentDedRessyasyubetsuThis =
				pCentDedRessyasyubetsuCont->getMuPtr() ;
			int idxThis = 0 ;
			for ( idxThis = 0 ; idxThis < muCentDedRessyasyubetsuThis->size() ; idxThis ++ )
			{
				const CentDedRessyasyubetsu* pCentDedRessyasyubetsuThis = muCentDedRessyasyubetsuThis->get( idxThis ) ;
				if ( pCentDedRessyasyubetsuThis->getSyubetsumei() == 
					pCentDedRessyasyubetsuToAdd->getSyubetsumei() )
				{
					break ;
				}
			}
			//idxThis = �w�ǉ�����H���t�@�C���x�̗�Ԏ��[idxToAdd] �Ɠ�����
			//	this�̗�Ԏ�ʂ̃C���f�N�X�B
			//	�Ȃ���΁A  muCentDedRessyasyubetsuThis->size()

			if ( idxThis == muCentDedRessyasyubetsuThis->size() )
			{
				//	�����̎�ʂ��Ȃ��ꍇ�́A
				//	this �ɒǉ����܂��B
				pCentDedRessyasyubetsuCont->insert( *pCentDedRessyasyubetsuToAdd ) ;
			}
			arRessyasyubetsuIdx_AddedToThis.push_back( idxThis ) ;
		}

	}
	//arRessyasyubetsuIdx_AddedToThis[�ǉ�����H���t�@�C���x�̗�Ԏ�ʃC���f�N�X] = 
	//	this�̗�Ԏ�ʃC���f�N�X

	//���_�C���̃}�[�W
	//�@�@���g�����H���t�@�C���̃_�C���ɂ�郋�[�v
	//�@�@�@�@��[�����̃_�C�����ҏW���̘H���t�@�C���ɑ��݂��Ȃ�]��̃_�C����
	//�@�@�@�@�@�ҏW���̘H���t�@�C���ɒǉ�
	//�@�@�@�@���_�C���Ώƕ\(�g�����H���t�@�C���̃_�C��Index��
	//�@�@�@�@�@�g�����H���t�@�C���̃_�C��Index �̑Ώƕ\���쐬

	deque<int>	arDiaIdx_AddedToThis ;
	{
		CentDedDiaCont* pCentDedDiaCont = this->getCentDedDiaCont() ;
		const CentDedDiaCont* pCentDedDiaContToAdd = rosenToAdd.getCentDedDiaCont() ;
		
		const Mu<const CentDedDia*>* muCentDedDiaToAdd =
				pCentDedDiaContToAdd->getMuPtr() ;
		for ( int idxToAdd = 0 ; idxToAdd < muCentDedDiaToAdd->size() ; idxToAdd ++ )
		{
			const CentDedDia* pCentDedDiaToAdd = 
				muCentDedDiaToAdd->get( idxToAdd ) ;

			Mu<CentDedDia*>* muCentDedDiaThis =
				pCentDedDiaCont->getMuPtr() ;
			int idxThis = 0 ;
			for ( idxThis = 0 ; idxThis < muCentDedDiaThis->size() ; idxThis ++ )
			{
				const CentDedDia* pCentDedDiaThis = muCentDedDiaThis->get( idxThis ) ;
				if ( pCentDedDiaThis->getName() == 
					pCentDedDiaToAdd->getName() )
				{
					break ;
				}
			}
			//idxThis = �w�ǉ�����H���t�@�C���x�̃_�C���Ɠ�����
			//	this�̃_�C���̃C���f�N�X�B
			//	�Ȃ���΁A  muCentDedDiaThis->size()

			if ( idxThis == muCentDedDiaThis->size() )
			{
				//	�����̃_�C�����Ȃ��ꍇ�́A
				//	this ��
				//	��Ԃ���̃_�C����ǉ����܂��B
				//	�i�_�C���I�u�W�F�N�g�𒼐ڒǉ�����ƁA��Ԃ��ǉ�����邽�߁A
				//	���܂������܂���) 
				CentDedEkiCont* pCentDedEkiCont = this->getCentDedEkiCont() ;
				CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont = this->getCentDedRessyasyubetsuCont() ;
				CentDedDia	diaNew( pCentDedEkiCont->size() ) ;
				diaNew.setName( pCentDedDiaToAdd->getName() ) ;
				pCentDedDiaCont->insert( diaNew ) ;
			}
			arDiaIdx_AddedToThis.push_back( idxThis ) ;
		}

	}
	//arDiaIdx_AddedToThis[�ǉ�����H���t�@�C���x�̃_�C���C���f�N�X] = 
	//	this�̃_�C���C���f�N�X

	//���g�����H���t�@�C���̗�Ԃ��A�ҏW���̘H���t�@�C���ɒǉ�
	//�@�@���g�����H���t�@�C���̃_�C���ɂ�郋�[�v
	//�@�@�@�@���S��Ԃ̃��[�v
	//�@�@�@�@�@�@����Ԃ�ǉ��B
	//�@�@�@�@�@�@�@�ǉ�����_�C���́A�_�C���Ώƕ\�ɂ��������ĕϊ�
	//�@�@�@�@�@�@�@��Ԏ��Index�́A��Ԏ�ʑΏƕ\�ɏ]���ĕϊ�
	//
	{
		const Mu<const CentDedDia*>* muCentDedDiaToAdd =
			((const CentDedDiaCont*)rosenToAdd.getCentDedDiaCont())->getMuPtr() ;

		for ( int idxDiaToAdd = 0 ; idxDiaToAdd < muCentDedDiaToAdd->size() ; idxDiaToAdd ++ )
		{
			const CentDedDia* pCentDedDiaToAdd = muCentDedDiaToAdd->get( idxDiaToAdd ) ;

			Mu<CentDedDia*>* muCentDedDiaThis =	this->getCentDedDiaCont()->getMuPtr() ;
			CentDedDia* pCentDedDiaThis = muCentDedDiaThis->get( arDiaIdx_AddedToThis[idxDiaToAdd] ) ;
			//pCentDedDiaThis = ��Ԃ̃R�s�[��ƂȂ� CentDedDia ;

			//�����ԁ������
			for ( int idxRessyahoukou = (int)Ressyahoukou_Kudari ;
				idxRessyahoukou <= (int)Ressyahoukou_Nobori ;
				idxRessyahoukou ++ )
			{

				ERessyahoukou eRessyahoukou = (ERessyahoukou)idxRessyahoukou ;
				const CentDedRessyaCont* pCentDedRessyaContToAdd = pCentDedDiaToAdd->getCentDedRessyaCont( eRessyahoukou ) ;
				const Mu<const CentDedRessya*>* muCentDedRessyaToAdd = pCentDedRessyaContToAdd->getMuPtr() ;
				CentDedRessyaCont* pCentDedRessyaContThis = pCentDedDiaThis->getCentDedRessyaCont( eRessyahoukou ) ;

				int iEkiOrderToInsert = -1 ;
				if ( eRessyahoukou == Ressyahoukou_Kudari )
				{
					iEkiOrderToInsert = pCentDedRessyaContThis->EkiOrderOfEkiIndex( iEkiIndexToInsertMin + 1 ) ;
				}
				else
				{
					iEkiOrderToInsert = pCentDedRessyaContThis->EkiOrderOfEkiIndex( iEkiIndexToInsertMax - 1 ) ;
				}
				//iEkiOrderToInsert = �g�����H���t�@�C���̉wOrder0�̗�Ԃ�}������A
				//	this�̉wOrder

				for ( int idxRessyaToAdd = 0 ; idxRessyaToAdd < muCentDedRessyaToAdd->size() ; idxRessyaToAdd ++ )
				{
					//	���ݕҏW���̘H���t�@�C���ɁA�g�����H���t�@�C���̗�Ԃ�}��
					//	��Ԏ�ʁE�w�����́A���̂��ƂɏC��
					const CentDedRessya* pRessyaToAdd = muCentDedRessyaToAdd->get( idxRessyaToAdd ) ;
					pCentDedRessyaContThis->insert( *pRessyaToAdd ) ;
					CentDedRessya* pRessyaAdded = pCentDedRessyaContThis->getMuPtr()->get( INT_MAX ) ;
					//pRessyaAdded = �g�����H���t�@�C���ɒǉ����ꂽ���
					//	��Ԏ�ʁE�w�����́A���̂��ƂɏC��

					//	��Ԏ�ʃC���f�N�X���A
					//	���ݕҏW���̘H���t�@�C���ɍ��킹�čX�V�B
					pRessyaAdded->setRessyasyubetsuIndex( 
						arRessyasyubetsuIdx_AddedToThis[ pRessyaToAdd->getRessyasyubetsuIndex() ] ) ;

					//	�w�������C��
					for ( int iEkiOrder = 0 ; iEkiOrder < pCentDedRessyaContThis->getEkiCount() ; iEkiOrder ++ )
					{
						int iEkiOrderToAdd = iEkiOrder - iEkiOrderToInsert ;
						//iEkiOrderToAdd = this��iEkiOrder�ɑΉ�����A
						//	�g�����H���t�@�C���̉wOrder

						if ( 0 <= iEkiOrderToAdd && iEkiOrderToAdd < pCentDedRessyaContToAdd->getEkiCount() )
						{
							//	�g�����H���t�@�C���̉wOrder�ɑΉ�����ꍇ�́A
							//	�g�����H���t�@�C���̉w�������R�s�[
							CentDedEkiJikoku aEkiJikokuToAdd = pRessyaToAdd->getCentDedEkiJikoku( iEkiOrderToAdd ) ; 
							pRessyaAdded->setCentDedEkiJikoku( iEkiOrder , aEkiJikokuToAdd ) ; 
						}
						else
						{
							//	�g�����H���t�@�C���̉wOrder�ɑΉ����Ȃ��w�ɑ΂��ẮA
							//	�^�s�Ȃ���ݒ�
							pRessyaAdded->setCentDedEkiJikoku( iEkiOrder , CentDedEkiJikoku() ) ; 
						}
					}


				}
			}	
		}
	}


	//��[�g�����wIndex���Ƒg�����wIndex��+1�ŁA�w��������]�w�𕹍�
	if ( 0 <= iEkiIndexToInsertMin )
	{
		CentDedEkiCont* pCentDedEkiContThis = getCentDedEkiCont() ;
		CentDedEki*	pEkiToInsertMin = pCentDedEkiContThis->getMuPtr()->get( iEkiIndexToInsertMin ) ;
		CentDedEki*	pEkiToInsertMin_1 = pCentDedEkiContThis->getMuPtr()->get( iEkiIndexToInsertMin + 1 ) ;
		if ( pEkiToInsertMin->getEkimei() == pEkiToInsertMin_1->getEkimei() )
		{
			//�@�@���g�����wIndex���̉w�����`���𔭒��ɕύX
			pEkiToInsertMin->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_Hatsuchaku ) ;

			//�@�@���S�_�C���̃��[�v
			//        ���S�����Ԃ̃��[�v
			//�@�@�@�@�@�@��[�g�����wIndex�����^�s�Ȃ�]
			//�@�@�@�@�@�@�@�g�����wIndex��+1�̉w������g�����wIndex���ɃR�s�[
			//�@�@�@�@���S����Ԃ̃��[�v
			//�@�@�@�@�@�@��[�g�����wIndex�����^�s�Ȃ�]
			//�@�@�@�@�@�@�@�g�����wIndex��+1�̉w������g�����wIndex���ɃR�s�[
			CentDedDiaCont* pCentDedDiaCont = this->getCentDedDiaCont() ;
			for ( int idxDia = 0 ; idxDia < pCentDedDiaCont->size() ; idxDia ++ )
			{
				CentDedDia* pDia = pCentDedDiaCont->getMuPtr()->get( idxDia ) ;
				for ( int iRessyahoukou = Ressyahoukou_Kudari ;
					iRessyahoukou <= Ressyahoukou_Nobori ;
					iRessyahoukou ++ )
				{
					ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;

					CentDedRessyaCont* pRessyaCont = pDia->getCentDedRessyaCont( eRessyahoukou ) ;
					int iEkiOrderToInsertMin = pRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin ) ;
					int iEkiOrderToInsertMin_1 = pRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMin + 1 ) ;
					for ( int idxRessya = 0 ; idxRessya < pRessyaCont->size() ; idxRessya ++ )
					{
						CentDedRessya* pRessya = pRessyaCont->getMuPtr()->get( idxRessya ) ;
						
						CentDedEkiJikoku aEkijikoku = pRessya->getCentDedEkiJikoku( iEkiOrderToInsertMin ) ;
						if ( aEkijikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None )
						{
							aEkijikoku = pRessya->getCentDedEkiJikoku( iEkiOrderToInsertMin_1 ) ;
							pRessya->setCentDedEkiJikoku( iEkiOrderToInsertMin ,aEkijikoku ) ;
						}
					}
				}
			}
			//�@�@���g�����wIndex��+1�̉w���폜
			pCentDedEkiContThis->erase( iEkiIndexToInsertMin + 1 ) ;
			iEkiIndexToInsertMax -- ;
		}
	}

	//��[�g�����wIndex��Ƒg�����wIndex��-1�ŁA�w��������]�w�𕹍�
	if ( iEkiIndexToInsertMax < getCentDedEkiCont()->size() - 1 )
	{
		CentDedEkiCont* pCentDedEkiContThis = getCentDedEkiCont() ;
		CentDedEki*	pEkiToInsertMax = pCentDedEkiContThis->getMuPtr()->get( iEkiIndexToInsertMax ) ;
		CentDedEki*	pEkiToInsertMax_1 = pCentDedEkiContThis->getMuPtr()->get( iEkiIndexToInsertMax - 1 ) ;
		if ( pEkiToInsertMax->getEkimei() == pEkiToInsertMax_1->getEkimei() )
		{
			//���g�����wIndex��̉w�����`���𔭒��ɕύX
			pEkiToInsertMax->setEkijikokukeisiki( CentDedEki::Jikokukeisiki_Hatsuchaku ) ;
			//���S�_�C���̃��[�v
			//�@�@���S�����Ԃ̃��[�v��
			//�@�@�@�@��[�g�����wIndex�傪�^�s�Ȃ�]
			//�@�@�@�@�@�g�����wIndex��-1�̉w������g�����wIndex��ɃR�s�[
			//�@�@���S����Ԃ̃��[�v��
			//�@�@�@�@��[�g�����wIndex�傪�^�s�Ȃ�]
			//�@�@�@�@�@�g�����wIndex��-1�̉w������g�����wIndex��ɃR�s�[
			CentDedDiaCont* pCentDedDiaCont = this->getCentDedDiaCont() ;
			for ( int idxDia = 0 ; idxDia < pCentDedDiaCont->size() ; idxDia ++ )
			{
				CentDedDia* pDia = pCentDedDiaCont->getMuPtr()->get( idxDia ) ;
				for ( int iRessyahoukou = Ressyahoukou_Kudari ;
					iRessyahoukou <= Ressyahoukou_Nobori ;
					iRessyahoukou ++ )
				{
					ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;

					CentDedRessyaCont* pRessyaCont = pDia->getCentDedRessyaCont( eRessyahoukou ) ;
					int iEkiOrderToInsertMax = pRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax ) ;
					int iEkiOrderToInsertMax_1 = pRessyaCont->EkiOrderOfEkiIndex( iEkiIndexToInsertMax - 1 ) ;
					for ( int idxRessya = 0 ; idxRessya < pRessyaCont->size() ; idxRessya ++ )
					{
						CentDedRessya* pRessya = pRessyaCont->getMuPtr()->get( idxRessya ) ;
						
						CentDedEkiJikoku aEkijikoku = pRessya->getCentDedEkiJikoku( iEkiOrderToInsertMax ) ;
						if ( aEkijikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None )
						{
							aEkijikoku = pRessya->getCentDedEkiJikoku( iEkiOrderToInsertMax_1 ) ;
							pRessya->setCentDedEkiJikoku( iEkiOrderToInsertMax ,aEkijikoku ) ;
						}
					}
				}
			}
			//�@�@���g�����wIndex��-1�̉w���폜
			pCentDedEkiContThis->erase( iEkiIndexToInsertMax - 1 ) ;
			iEkiIndexToInsertMax -- ;
		}
	}
	//���A�w�ǉ�����H���t�@�C���x�̃R�����g���A�w���ݕҏW���Ă���H���t�@�C���x�̃R�����g�̖����ɒǉ��B
	{
		string strComment = this->getComment() ;
		strComment += "\n\n" ;
		strComment += rosenToAdd.getComment() ;
		this->setComment( strComment ) ;
	}
}

CentDedRosen CentDedRosen::createSubRosen( 
		int iEkiIndex , int iEkiCount )const 
{
	CentDedRosen rosenNew = *this ;
	/*	
	(1)�@�V�������������H���t�@�C���́A
	�w���ݕҏW���Ă���H���t�@�C���x����A
	�w�肳�ꂽ�͈͈ȊO�̉w���폜�������̂ɂȂ�܂��B
	*/
	{
		//	�w�V�������������H���t�@�C���x�̏I�_���̉w���폜
		rosenNew.getCentDedEkiCont()->erase( iEkiIndex + iEkiCount , INT_MAX ) ;
		//	�w�V�������������H���t�@�C���x�̋N�_���̉w���폜
		rosenNew.getCentDedEkiCont()->erase( 0 , iEkiIndex ) ;
	}
	/*
	(2)�@�V�������������H�����^�]��ԂɊ܂܂�Ȃ���Ԃ́A�폜���܂��B
	*/
	{
		Mu<CentDedDia*>* muCentDedDia = rosenNew.getCentDedDiaCont()->getMuPtr() ;

		for ( int idxDia = 0 ; idxDia < muCentDedDia->size() ; idxDia ++ )
		{
			CentDedDia* pCentDedDia = muCentDedDia->get( idxDia ) ;
			//pCentDedDia = �ΏۂƂȂ�_�C��

			//�����ԁ������
			for ( int idxRessyahoukou = (int)Ressyahoukou_Kudari ;
				idxRessyahoukou <= (int)Ressyahoukou_Nobori ;
				idxRessyahoukou ++ )
			{
				ERessyahoukou eRessyahoukou = (ERessyahoukou)idxRessyahoukou ;
				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;

				for ( int idxRessya = 0 ; idxRessya < pCentDedRessyaCont->size() ; idxRessya ++ )
				{
					bool bErase = false ;
					CentDedRessya* pRessya = pCentDedRessyaCont->getMuPtr()->get( idxRessya ) ;

					//	��Ԃ��^�s���Ă����Ԃ�����Ȃ���Ԃ́A
					//	�폜���܂��B
					if ( !bErase )
					{

						//	��Ԃ��^�s���Ă����Ԃ̍ŏ��̉wOrder��
						//	�������܂��B
						int iEkiOrder = 0 ;
						for ( iEkiOrder = 0 ; 
							iEkiOrder < pRessya->getCentDedEkiJikokuCount() ;
							iEkiOrder ++ )
						{
							if ( pRessya->isRunBetweenNextEki( iEkiOrder ) )
							{
								break ;
							}
						}
						//iEkiOrder = ��Ԃ��^�s���Ă����Ԃ̍ŏ��̉wOrder
						//	������Ȃ������ꍇ�́A
						//	pRessya->getCentDedEkiJikokuCount() �Ɠ������Ȃ�܂��B
						if ( iEkiOrder == pRessya->getCentDedEkiJikokuCount() )
						{
							bErase = true ;	
						}
					}


					//	��Ԃ��폜
					if ( bErase )
					{
						pCentDedRessyaCont->erase( idxRessya ) ;
						idxRessya -- ;
					}
				}
			}

		}
	}


	return rosenNew ;
}

void CentDedRosen::adjustByEkijikokukeisiki( int iEkiIndex ) 
{
	//���S�_�C���̃��[�v
	for ( int idxDia = 0 ; idxDia < m_CentDedDiaCont.size() ; idxDia ++ )
	{
		CentDedDia* pCentDedDia = m_CentDedDiaCont.getMuPtr()->get( idxDia ) ;
		pCentDedDia->adjustByEkijikokukeisiki(
			&m_CentDedEkiCont ,
			iEkiIndex ) ;
	}
}

void CentDedRosen::invert()
{
	//(0)�@�H���I�u�W�F�N�g�̃R�s�[���쐬
	CentDedRosen	aRosenBefore = *this ;


	//(1)�@�H���t�@�C���̉w�̏����̕��я����t�ɂ��܂��B
	//	�ŏ��̏�Ԃ̘H���t�@�C���̃R�s�[����A�w�������R�s�[���܂��B
	{
		for ( int idxEki = 0 ;idxEki < m_CentDedEkiCont.size() ; idxEki ++ )
		{
			CentDedEki	aEki = aRosenBefore.getCentDedEkiCont()->get( 
				m_CentDedEkiCont.size() - idxEki - 1 ) ;

			m_CentDedEkiCont.set( aEki , idxEki ) ;
		}
	}
	//(2)�@�w�̃v���p�e�B�́A�ȉ��̕ϊ����s���܂��B
	//�y�⑫�z
	//	this �̉w�̑�����ύX����ƁA�܂܂�Ă����Ԃ̒������E��������
	//	�w�n���w�E�I���w�̉w�����`���ύX�ɔ����A�������E�������̏C���x
	//	�ɂ��A�w�������ύX����܂��B
	//	aRosenBefore �́A���̕ύX���󂯂�O�̉w������ێ����܂��B
	{
		for ( int idxEki = 0 ; idxEki < m_CentDedEkiCont.size() ; idxEki ++ )  
		{
			CentDedEki*	pEki = m_CentDedEkiCont.getMuPtr()->get( idxEki ) ;

			//(2.1)�w���͂��̂܂�

			//(2.2)�w�����`��
			//	- ���蒅��������蒅����
			//	- ��蒅���������蒅����
			{
				CentDedEki::EEkijikokukeisiki eEkijikokukeisiki = pEki->getEkijikokukeisiki() ;
				if ( eEkijikokukeisiki == CentDedEki::Jikokukeisiki_KudariChaku )
				{
					eEkijikokukeisiki = CentDedEki::Jikokukeisiki_NoboriChaku ;
				}
				else if ( eEkijikokukeisiki == CentDedEki::Jikokukeisiki_NoboriChaku )
				{
					eEkijikokukeisiki = CentDedEki::Jikokukeisiki_KudariChaku ;
				}
				pEki->setEkijikokukeisiki( eEkijikokukeisiki ) ;
			}

			//(2.3)���E��
			//	- �w�̏�����ύX��A�N�_��(�wIndex�̏�������)��1�w�V�t�g����B
			//	- �V�������葤�I�_(�wIndex�̍ł��傫���w)�̋��E���͖����ɂ���B
			{
				CentDedEki*	pEkiNext = NULL ;
				if ( idxEki + 1 < m_CentDedEkiCont.size() )
				{
					pEkiNext = m_CentDedEkiCont.getMuPtr()->get( idxEki + 1 ) ;
				}

				if ( pEkiNext != NULL )
				{
					pEki->setKyoukaisen( pEkiNext->getKyoukaisen() ) ;
				}
				else
				{
					pEki->setKyoukaisen( false ) ;
				}
			}

			//(2.4)�_�C���O������ԏ��
			//	  ����̓��e�Ə��̓��e�����ւ��܂��B
			{
				CentDedEki::EDiagramRessyajouhouHyouji eRessyajouhouHyoujiKudari = pEki->getDiagramRessyajouhouHyoujiKudari() ;
				CentDedEki::EDiagramRessyajouhouHyouji eRessyajouhouHyoujiNobori = pEki->getDiagramRessyajouhouHyoujiNobori() ;
				pEki->setDiagramRessyajouhouHyoujiKudari( eRessyajouhouHyoujiNobori ) ;
				pEki->setDiagramRessyajouhouHyoujiNobori( eRessyajouhouHyoujiKudari ) ;
			}
		}
	}

	//(3)���ׂẴ_�C���ɂ��āA�����ԂƏ���Ԃ����ւ��܂��B
	//	���̂Ƃ��A�����Ԃ���U��ɂ��������ŁA
	//	�ŏ��̏��(�w�̏����̓���ւ����s���O��)�̘H���I�u�W�F�N�g�̃R�s�[����
	//	��Ԃ�}�����܂��B�������l�ł��B
	//�y�⑫�z
	//	this �̉w�̑�����ύX����ƁA�܂܂�Ă����Ԃ̒������E��������
	//	�w�n���w�E�I���w�̉w�����`���ύX�ɔ����A�������E�������̏C���x
	//	�ɂ��A�w�������ύX����܂��B
	//	aRosenBefore �́A���̕ύX���󂯂�O�̉w������ێ����܂��B
	//	������R�s�[���Ƃ��邱�Ƃɂ��A�w�����̕ύX������邱�Ƃ��ł��܂��B
	{
		for ( int idxDia = 0 ; idxDia < m_CentDedDiaCont.size() ; idxDia ++ )
		{
			CentDedDia* pDia = m_CentDedDiaCont.getMuPtr()->get( idxDia ) ;

			//	����E���̗�ԃR���e�i�ɃA�_�v�^��t��
			CaMui<CentDedRessya>	aRessyaContKudariAdapter( pDia->getCentDedRessyaCont( Ressyahoukou_Kudari ) ) ;
			CaMui<CentDedRessya>	aRessyaContNoboriAdapter( pDia->getCentDedRessyaCont( Ressyahoukou_Nobori ) ) ;

			//	�����ԃR���e�i�̓��e���폜��A
			//	���Ă̏���Ԃ̃R�s�[��ǉ�
			aRessyaContKudariAdapter.getAdaptee()->erase( 0 , INT_MAX ) ;
			aRessyaContKudariAdapter.insert( 
				aRosenBefore.getCentDedDiaCont()->getMuPtr()->get( idxDia )->getCentDedRessyaCont( Ressyahoukou_Nobori ) );

			//	����ԃR���e�i�̓��e���폜��A
			//	���Ă̏���Ԃ̃R�s�[��ǉ�
			aRessyaContNoboriAdapter.getAdaptee()->erase( 0 , INT_MAX ) ;
			aRessyaContNoboriAdapter.insert( 
				aRosenBefore.getCentDedDiaCont()->getMuPtr()->get( idxDia )->getCentDedRessyaCont( Ressyahoukou_Kudari ) );

		}
	}


}
int CentDedRosen::swapRessyasyubetsu( int iRessyasyubetsuIndexA ,
		int iRessyasyubetsuIndexB ) 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndexA == INT_MAX ){
			iRessyasyubetsuIndexA = m_CentDedRessyasyubetsuCont.size() - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndexA && 
				iRessyasyubetsuIndexA < m_CentDedRessyasyubetsuCont.size() ) ){
			iRv = -1 ;	//	�C���f�N�X���s��

		}
	}
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndexB == INT_MAX ){
			iRessyasyubetsuIndexB = m_CentDedRessyasyubetsuCont.size() - 1 ;
		}
		if ( !( 0 <= iRessyasyubetsuIndexB && 
				iRessyasyubetsuIndexB < m_CentDedRessyasyubetsuCont.size() ) ){
			iRv = -1 ;	//	�C���f�N�X���s��

		}
	}
	if ( iRv >= 0 ){
		if ( iRessyasyubetsuIndexA == iRessyasyubetsuIndexB ){
			iRv = -1 ;	//	�C���f�N�X���s��
		}
	}
	// --------------------------------
	//m_CentDedRessyasyubetsuCont �̓���ւ�
	if ( iRv >= 0 ){
		Mu<CentDedRessyasyubetsu*>*	pIfContGet = m_CentDedRessyasyubetsuCont.getMuPtr() ;
		CentDedRessyasyubetsu	aCentDedRessyasyubetsuA = 
			*pIfContGet->get( iRessyasyubetsuIndexA ) ;
		CentDedRessyasyubetsu	aCentDedRessyasyubetsuB = 
			*pIfContGet->get( iRessyasyubetsuIndexB ) ;
		*pIfContGet->get( iRessyasyubetsuIndexA )  = 
			aCentDedRessyasyubetsuB ; 
		*pIfContGet->get( iRessyasyubetsuIndexB )  = 
			aCentDedRessyasyubetsuA ; 

		// --------------------------------
		//	��Ԃ̓���ւ�
		// --------------------------------
		int iDiaIndex ;
		for ( iDiaIndex = 0 ; iDiaIndex < m_CentDedDiaCont.size() ; iDiaIndex ++ ){
			CentDedDia*	pCentDedDia = m_CentDedDiaCont.getMuPtr()->get( iDiaIndex ) ;
			int iRessyahoukou = 0 ;
			for ( iRessyahoukou = Ressyahoukou_Kudari ; 
					iRessyahoukou <= Ressyahoukou_Nobori ; 
					iRessyahoukou ++ ){
				ERessyahoukou	eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
				
				CentDedRessyaCont* pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;
				Mu< CentDedRessya* >* pCentDedRessyaContGet = pCentDedRessyaCont->getMuPtr() ;

				int iRessyaCount = pCentDedRessyaContGet->size() ;

				int iRessyaIndex ;

				//	iRessyasyubetsuIndexA -> iRessyasyubetsuIndexB
				//	iRessyasyubetsuIndexB -> iRessyasyubetsuIndexA 
				for ( iRessyaIndex = 0 ; 
						iRessyaIndex < iRessyaCount ; 
						iRessyaIndex ++ ){
					CentDedRessya*	pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIndex ) ;
					
					int iRessyasyubetsuIndexCurr = pCentDedRessya->getRessyasyubetsuIndex() ;
					if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndexA ){
						iRessyasyubetsuIndexCurr = iRessyasyubetsuIndexB ;	
					}	else if ( iRessyasyubetsuIndexCurr == iRessyasyubetsuIndexB ){
						iRessyasyubetsuIndexCurr = iRessyasyubetsuIndexA ;
					}
					pCentDedRessya->setRessyasyubetsuIndex( iRessyasyubetsuIndexCurr ) ;	
				}
			}
		}
	}

	return ( iRv ) ;
}

void CentDedRosen::clear() 
{
	m_strName.erase() ;
	m_jikokuKitenJikoku.setTime( 0 , 0 , 0 ) ;
	m_strComment.erase() ;

	m_CentDedDiaCont.erase( 0 , INT_MAX ) ;
	m_CentDedRessyasyubetsuCont.erase( 1 , INT_MAX ) ;
	m_CentDedEkiCont.erase( 0 , INT_MAX ) ;

	// --------------------------------
	{
		//	�w��Ԏ�ʁx�́A���Ȃ��Ƃ���͑��݂��Ȃ��Ă͂Ȃ�܂���B
		m_CentDedRessyasyubetsuCont.set( 
			CentDedRessyasyubetsu( nameRessyasyubetsuDefault , ""  ) , 0 ) ;
	}
};


	// ********************************
	//@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************

void CentDedRosen::onEkiInsert( int iEkiIndex )
{
	m_CentDedDiaCont.onEkiInsert( iEkiIndex ) ;
}
void CentDedRosen::onEkiErase( int iEkiIndex  )
{
	m_CentDedDiaCont.onEkiErase( iEkiIndex ) ;
}


void CentDedRosen::onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex )
{
	m_CentDedDiaCont.onEkiTrackInsert( iEkiIndex , iEkiTrackIndex ) ;
}
void CentDedRosen::onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex )
{
	m_CentDedDiaCont.onEkiTrackErase( iEkiIndex , iEkiTrackIndex ) ;
}
void CentDedRosen::onRessyasyubetsuInsert( int iRessyasyubetsuIndex )
{
	m_CentDedDiaCont.onRessyasyubetsuInsert( iRessyasyubetsuIndex ) ;
}

void CentDedRosen::onRessyasyubetsuErase( int iRessyasyubetsuIndex )
{
	m_CentDedDiaCont.onRessyasyubetsuErase( iRessyasyubetsuIndex ) ;
}



} //namespace entDed
