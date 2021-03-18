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
//	CDedRessyaSoater_Transfer.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include <algorithm>
#include "CDedRessyaSoater_Transfer.h"
#include "NsMu\CaMui.h"
#include "NsMu\CMup_vector.h"
#include "NsMu\CaMup_vector.h"
#include "CentDedDgrRessya.h"



namespace entDgr{
using namespace std ;

// ****************************************************************
//	CDedRessyaSoater_Transfer
// ****************************************************************
	// --------------------------------
	//@name �����֐�
	// --------------------------------
bool CDedRessyaSoater_Transfer::sortRessyaIndex_TransferFromSortedRessyaAtEki( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		int iEkiOrder , 
		int iMaxTransferSec ,
		IfProgress* pIfProgress )
{
	bool bAbort = false ;
	const CentDedRessyaCont* pRessyaCont = pEstimateRessyaCont ;
	const CentDedEkiCont* pEkiCont = m_pDedRosen->getCentDedEkiCont() ;

	//�@�@�@�@�@�@���S�\�[�g�O��Ԃ̃��[�v(�����̒x���ق��������ق�)
	//�@�@�@�@�@�@�@�@���S�\�[�g���Ԃ̃��[�v(�����̒x���ق��������ق�)
	//�@�@�@�@�@�@�@�@�@�@��[�抷�wIndex�ŁA�\�[�g���ԁ��\�[�g�O��Ԃ�
	//�@�@�@�@�@�@�@�@�@�@�@�@��p��10���ȓ��ŉ\]
	//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒���ɁA
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
	for ( int idxRessyaIndexBeforeSort = (int)pcontRessyaIndexBeforeSort->size() - 1 ; 
		!bAbort && idxRessyaIndexBeforeSort >= 0 ;
		idxRessyaIndexBeforeSort -- )
	{
		int iRessyaIndexBeforeSort = pcontRessyaIndexBeforeSort->at( idxRessyaIndexBeforeSort ) ;
		const CentDedRessya*	pRessyaBeforeSort = pRessyaCont->getMuPtr()->get( iRessyaIndexBeforeSort ) ;

		CentDedEkiJikoku	aEkiJikokuBeforeSort = pRessyaBeforeSort->getCentDedEkiJikoku( iEkiOrder ) ;

		int idxRessyaIndexAfterSort = -1 ;
		for ( idxRessyaIndexAfterSort = (int)pcontRessyaIndexAfterSort->size() - 1 ;
			idxRessyaIndexAfterSort >= 0 ; 
			idxRessyaIndexAfterSort -- )
		{
			int iRessyaIndexAfterSort = pcontRessyaIndexAfterSort->at( idxRessyaIndexAfterSort ) ;
			const CentDedRessya*	pRessyaAfterSort = pRessyaCont->getMuPtr()->get( iRessyaIndexAfterSort ) ;
			CentDedEkiJikoku	aEkiJikokuAfterSort = pRessyaAfterSort->getCentDedEkiJikoku( iEkiOrder ) ;

			//	��p�\�̔���
			int iNorikaeSec = calcNorikaeSec( 
				aEkiJikokuAfterSort , 
				aEkiJikokuBeforeSort ,
				m_pDedRosen->getKitenJikoku() ) ;
			//iNorikaeSec = ��芷������(�b��)
			//	��芷���s�\�Ȃ�A-1 ;

			if ( iNorikaeSec >= 0 && iNorikaeSec <= iMaxTransferSec )
			{
				//	��芷���\
				break ;
			}
		}
		//idxRessyaIndexAfterSort =
		//	��芷�����ƂȂ�A�\�[�g����
		//	������Ȃ��ꍇ�́AidxRessyaIndexAfterSort=-1 ; 

		if ( 0 <= idxRessyaIndexAfterSort )
		{
			//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
			//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒���ɁA
			//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
			pcontRessyaIndexBeforeSort->erase( 
					pcontRessyaIndexBeforeSort->begin() + idxRessyaIndexBeforeSort ) ;

			//	�\�[�g���Ԃ̒���ȍ~�ŁA�}���������
			for ( idxRessyaIndexAfterSort ++ ;
				idxRessyaIndexAfterSort < (int)pcontRessyaIndexAfterSort->size() ;
				idxRessyaIndexAfterSort ++ )
			{
				int iRessyaIndexAfterSort = pcontRessyaIndexAfterSort->at( idxRessyaIndexAfterSort ) ;
				const CentDedRessya*	pRessyaAfterSort = pRessyaCont->getMuPtr()->get( iRessyaIndexAfterSort ) ;
				CentDedEkiJikoku	aEkiJikokuAfterSort = pRessyaAfterSort->getCentDedEkiJikoku( iEkiOrder ) ;

				if ( aEkiJikokuAfterSort.getHatsujikoku().isNull() || 
					aEkiJikokuBeforeSort.getHatsujikoku( true ).compare(
						aEkiJikokuAfterSort.getHatsujikoku( true ) ,
						m_pDedRosen->getKitenJikoku() ) <= 0 )
				{
					break ;
				}
			}
			//idxRessyaIndexAfterSort = ��Ԃ̑}����

			pcontRessyaIndexAfterSort->insert( 
				pcontRessyaIndexAfterSort->begin() + idxRessyaIndexAfterSort ,
				iRessyaIndexBeforeSort ) ;
		}

		// --------------------------------
		if ( pIfProgress != NULL )
		{
			int iResult = pIfProgress->onNotifyProgress( 
				pcontRessyaIndexAfterSort->size() ,
				pRessyaCont->size() ) ;
			if ( iResult != 0 )
			{
				bAbort = true ;
			}

		}

	}

	return bAbort ;
}


bool CDedRessyaSoater_Transfer::sortRessyaIndex_TransferToSortedRessyaAtEki( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		int iEkiOrder , 
		int iMaxTransferSec ,
		IfProgress* pIfProgress )
{
	bool bAbort = false ;
	const CentDedRessyaCont* pRessyaCont = pEstimateRessyaCont ;
	const CentDedEkiCont* pEkiCont = m_pDedRosen->getCentDedEkiCont() ;

	//�@�@�@�@�@�@���S�\�[�g�O��Ԃ̃��[�v
	//�@�@�@�@�@�@�@�@���S�\�[�g���Ԃ̃��[�v(�����̑����ق����x���ق�)
	//�@�@�@�@�@�@�@�@�@�@��[�抷�wIndex�ŁA�\�[�g�O��ԁ��\�[�g���Ԃ�
	//�@�@�@�@�@�@�@�@�@�@�@�@��p���w�蕪�ȓ��ŉ\]
	//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒��O�ɁA
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
	for ( int idxRessyaIndexBeforeSort = 0 ; 
		!bAbort && idxRessyaIndexBeforeSort < (int)pcontRessyaIndexBeforeSort->size() ;
		idxRessyaIndexBeforeSort ++ )
	{
		const CentDedRessya*	pRessyaBeforeSort = pRessyaCont->getMuPtr()->get( 
			pcontRessyaIndexBeforeSort->at( idxRessyaIndexBeforeSort ) ) ;
		CentDedEkiJikoku	aEkiJikokuBeforeSort = pRessyaBeforeSort->getCentDedEkiJikoku( iEkiOrder ) ;

		int idxRessyaIndexAfterSort = -1 ;
		for ( idxRessyaIndexAfterSort = 0 ;
			idxRessyaIndexAfterSort < (int)pcontRessyaIndexAfterSort->size()  ; 
			idxRessyaIndexAfterSort ++ )
		{
			const CentDedRessya*	pRessyaAfterSort = pRessyaCont->getMuPtr()->get( 
				pcontRessyaIndexAfterSort->at( idxRessyaIndexAfterSort ) ) ;
			CentDedEkiJikoku	aEkiJikokuAfterSort = pRessyaAfterSort->getCentDedEkiJikoku( iEkiOrder ) ;

			//	��p�\�̔���
			int iNorikaeSec = calcNorikaeSec( 
				aEkiJikokuBeforeSort , 
				aEkiJikokuAfterSort ,
				m_pDedRosen->getKitenJikoku() ) ;
			//iNorikaeSec = ��芷������(�b��)
			//	��芷���s�\�Ȃ�A-1 ;

			if ( iNorikaeSec >= 0 && iNorikaeSec <= iMaxTransferSec )
			{
				//	��芷���\
				break ;
			}
		}
		//idxRessyaIndexAfterSort =
		//	��芷����ƂȂ�A�\�[�g����
		//	������Ȃ��ꍇ�́AidxRessyaIndexAfterSort=pcontRessyaIndexAfterSort->size() ; 

		if ( idxRessyaIndexAfterSort < (int)pcontRessyaIndexAfterSort->size() )
		{
			//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
			//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒���ɁA
			//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
			int iRessyaIndexBeforeSort = pcontRessyaIndexBeforeSort->at( idxRessyaIndexBeforeSort ) ;
			pcontRessyaIndexBeforeSort->erase( 
					pcontRessyaIndexBeforeSort->begin() + idxRessyaIndexBeforeSort ) ;
			idxRessyaIndexBeforeSort -- ;



			//	�\�[�g���Ԃ̒��O�ȑO�ŁA�}���������
			for ( idxRessyaIndexAfterSort -- ;
				idxRessyaIndexAfterSort >= 0 ;
				idxRessyaIndexAfterSort -- )
			{
				int iRessyaIndexAfterSort = pcontRessyaIndexAfterSort->at( idxRessyaIndexAfterSort ) ;
				const CentDedRessya*	pRessyaAfterSort = pRessyaCont->getMuPtr()->get( iRessyaIndexAfterSort ) ;
				CentDedEkiJikoku	aEkiJikokuAfterSort = pRessyaAfterSort->getCentDedEkiJikoku( iEkiOrder ) ;

				if ( aEkiJikokuAfterSort.getChakujikoku().isNull() || 
					aEkiJikokuAfterSort.getChakujikoku( true ).compare(
						aEkiJikokuBeforeSort.getChakujikoku( true ) ,
						m_pDedRosen->getKitenJikoku() ) <= 0 )
				{
					break ;
				}
			}
			idxRessyaIndexAfterSort ++ ;
			//idxRessyaIndexAfterSort = ��Ԃ̑}����

			pcontRessyaIndexAfterSort->insert( 
				pcontRessyaIndexAfterSort->begin() + idxRessyaIndexAfterSort ,
				iRessyaIndexBeforeSort ) ;
		}

		// --------------------------------
		if ( pIfProgress != NULL )
		{
			int iResult = pIfProgress->onNotifyProgress( 
				pcontRessyaIndexAfterSort->size() ,
				pRessyaCont->size() ) ;
			if ( iResult != 0 )
			{
				bAbort = true ;
			}

		}

	}

	return bAbort ;
}

bool CDedRessyaSoater_Transfer::sortRessyaIndex_TransferFromSortedRessya( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		CdDedJikokuOrder aEkijikokuOrder  , 
		IfProgress* pIfProgress ) 
{
	bool bAbort = false ;
	ERessyahoukou	eRessyahoukou = pEstimateRessyaCont->getRessyahoukou() ;
	const CentDedRessyaCont* pRessyaCont = pEstimateRessyaCont ;
	const CentDedEkiCont* pEkiCont = m_pDedRosen->getCentDedEkiCont() ;

	//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw(F)��肠�Ƃ̒�ԉw��10���ȓ��ɏ�芷���̂ł���\�[�g���Ԃ̌��ɔz�u
	//�@�@����芷���wOrder�̃��[�v(�\�[�g�Ώۉw+1�`�I���w)
	//�@�@�@�@��[���̉w����v�w]
	//�@�@�@�@�@�@���S�\�[�g�O��Ԃ̃��[�v
	//�@�@�@�@�@�@�@�@���S�\�[�g���Ԃ̃��[�v(�����̒x���ق��������ق�)
	//�@�@�@�@�@�@�@�@�@�@��[�抷�wIndex�ŁA�\�[�g���ԁ��\�[�g�O��Ԃ�
	//�@�@�@�@�@�@�@�@�@�@�@�@��p��10���ȓ��ŉ\]
	//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒���ɁA
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
	//�@�@���\�[�g�O��Ԃ�1�{�ł�����������A���̃��[�v���Ď��s
	int iRessyaIndexBeforSortCount ;
	do{
		iRessyaIndexBeforSortCount = pcontRessyaIndexBeforeSort->size() ;

		for ( int iEkiOrder = aEkijikokuOrder.getEkiOrder() ; 
			!bAbort && iEkiOrder <= pEkiCont->size() - 1 ;
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki	aEki = pEkiCont->getMuPtr(eRessyahoukou)->get( iEkiOrder ) ;
			if ( aEki.getEkikibo() == CentDedEki::Ekikibo_Syuyou )
			{
				//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw(F)��肠�Ƃ̒�ԉw��
				//	10���ȓ��ɏ�芷���̂ł���\�[�g���Ԃ̌��ɔz�u
				bAbort = sortRessyaIndex_TransferFromSortedRessyaAtEki( 
					pEstimateRessyaCont ,
					pcontRessyaIndexBeforeSort , 
					pcontRessyaIndexAfterSort , 
					iEkiOrder , 
					10 * 60 , 
					pIfProgress ) ; 
			}
		}

	} while( !bAbort && iRessyaIndexBeforSortCount > (int)pcontRessyaIndexBeforeSort->size() ) ;
	



	//
	//�@�@����芷���wOrder�̃��[�v(�\�[�g�Ώۉw+1�`�I���w)
	//�@�@�@�@��[���̉w��NOT(��v�w)]
	//�@�@�@�@�@�@���S�\�[�g�O��Ԃ̃��[�v
	//�@�@�@�@�@�@�@�@���S�\�[�g���Ԃ̃��[�v(�����̒x���ق��������ق�)
	//�@�@�@�@�@�@�@�@�@�@��[�抷�wIndex�ŁA�\�[�g���ԁ��\�[�g�O��Ԃ�
	//�@�@�@�@�@�@�@�@�@�@�@�@��p��10���ȓ��ŉ\]
	//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒���ɁA
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
	//�@�@���\�[�g�O��Ԃ�1�{�ł�����������A���̃��[�v���Ď��s

	do{
		iRessyaIndexBeforSortCount = pcontRessyaIndexBeforeSort->size() ;

		for ( int iEkiOrder = aEkijikokuOrder.getEkiOrder() ; 
			!bAbort && iEkiOrder <= pEkiCont->size() - 1 ;
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki	aEki = pEkiCont->getMuPtr(eRessyahoukou)->get( iEkiOrder ) ;
			if ( aEki.getEkikibo() != CentDedEki::Ekikibo_Syuyou )
			{
				//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw(F)��肠�Ƃ̒�ԉw��
				//	10���ȓ��ɏ�芷���̂ł���\�[�g���Ԃ̌��ɔz�u
				bAbort = sortRessyaIndex_TransferFromSortedRessyaAtEki( 
					pEstimateRessyaCont ,
					pcontRessyaIndexBeforeSort , 
					pcontRessyaIndexAfterSort , 
					iEkiOrder , 
					10 * 60 , 
					pIfProgress ) ; 
			}
		}

	} while( !bAbort && iRessyaIndexBeforSortCount > (int)pcontRessyaIndexBeforeSort->size() ) ;




	//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw(F)��肠�Ƃ̒�ԉw�ŏ�芷���̂ł���\�[�g���Ԃ�T���B
	//�@�@����芷���wOrder�̃��[�v(�\�[�g�Ώۉw+1�`�I���w)
	//�@�@�@�@�@�@���S�\�[�g�O��Ԃ̃��[�v
	//�@�@�@�@�@�@�@�@���S�\�[�g���Ԃ̃��[�v(�����̒x���ق��������ق�)
	//�@�@�@�@�@�@�@�@�@�@��[�抷�wIndex�ŁA�\�[�g���ԁ��\�[�g�O��Ԃ̏�p���\]
	//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ́u���בւ��p�w�����v�ɁA
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���Ԃ́u���בւ��p�w�����v�̉w�����E�������R�s�[�B
	//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒���ɁA
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
	//�@�@���\�[�g�O��Ԃ�1�{�ł�����������A���̃��[�v���Ď��s

	do{
		iRessyaIndexBeforSortCount = pcontRessyaIndexBeforeSort->size() ;

		for ( int iEkiOrder = aEkijikokuOrder.getEkiOrder()  ; 
			!bAbort && iEkiOrder <= pEkiCont->size() - 1 ;
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki	aEki = pEkiCont->getMuPtr(eRessyahoukou)->get( iEkiOrder ) ;
			{
				//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw(F)��肠�Ƃ̒�ԉw��
				//	��芷���̂ł���\�[�g���Ԃ̌��ɔz�u
				bAbort = sortRessyaIndex_TransferFromSortedRessyaAtEki( 
					pEstimateRessyaCont ,
					pcontRessyaIndexBeforeSort , 
					pcontRessyaIndexAfterSort , 
					iEkiOrder , 
					INT_MAX , 
					pIfProgress ) ; 
			}
		}

	} while( !bAbort && iRessyaIndexBeforSortCount > (int)pcontRessyaIndexBeforeSort->size() ) ;

	return bAbort ;
}


bool CDedRessyaSoater_Transfer::sortRessyaIndex_TransferToSortedRessya( 
		const CentDedRessyaCont* pEstimateRessyaCont ,
		std::vector<int>* pcontRessyaIndexBeforeSort , 
		std::vector<int>* pcontRessyaIndexAfterSort , 
		CdDedJikokuOrder aEkijikokuOrder  , 
		IfProgress* pIfProgress ) 
{
	bool bAbort = false ;
	ERessyahoukou	eRessyahoukou = pEstimateRessyaCont->getRessyahoukou() ;
	const CentDedRessyaCont* pRessyaCont = pEstimateRessyaCont ;
	const CentDedEkiCont* pEkiCont = m_pDedRosen->getCentDedEkiCont() ;
	//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw(F)���O�̒�ԉw��10���ȓ��ɏ�芷���̂ł���\�[�g���Ԃ̑O�ɔz�u
	//�@�@����芷���wOrder�̃��[�v(�\�[�g�Ώۉw-1�`�N�_�w)
	//�@�@�@�@��[���̉w���I���wor��v�w]
	//�@�@�@�@�@�@���S�\�[�g�O��Ԃ̃��[�v
	//�@�@�@�@�@�@�@�@���S�\�[�g���Ԃ̃��[�v(�����̑����ق����x���ق�)
	//�@�@�@�@�@�@�@�@�@�@��[�抷�wIndex�ŁA�\�[�g�O��ԁ��\�[�g���Ԃ�
	//�@�@�@�@�@�@�@�@�@�@�@�@��p��10���ȓ��ŉ\]
	//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒��O�ɁA
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
	//�@�@���\�[�g�O��Ԃ�1�{�ł�����������A���̃��[�v���Ď��s

	int iRessyaIndexBeforSortCount ;
	do{
		iRessyaIndexBeforSortCount = pcontRessyaIndexBeforeSort->size() ;

		for ( int iEkiOrder = aEkijikokuOrder.getEkiOrder()  ; 
			!bAbort && iEkiOrder >= 0 ;
			iEkiOrder -- )
		{
			CentDedEkiCont::CdDedEki	aEki = pEkiCont->getMuPtr(eRessyahoukou)->get( iEkiOrder ) ;
			if ( aEki.getEkikibo() == CentDedEki::Ekikibo_Syuyou )
			{
				bAbort = sortRessyaIndex_TransferToSortedRessyaAtEki( 
					pEstimateRessyaCont ,
					pcontRessyaIndexBeforeSort , 
					pcontRessyaIndexAfterSort , 
					iEkiOrder , 
					10 * 60 , 
					pIfProgress ) ; 
			}
		}

	} while( !bAbort && iRessyaIndexBeforSortCount > (int)pcontRessyaIndexBeforeSort->size() ) ;


	//
	//�@�@����芷���wOrder�̃��[�v(�\�[�g�Ώۉw-1�`�N�_�w)
	//�@�@�@�@��[���̉w��NOT(�I���wor��v�w)]
	//�@�@�@�@�@�@���S�\�[�g�O��Ԃ̃��[�v
	//�@�@�@�@�@�@�@�@���S�\�[�g���Ԃ̃��[�v(�����̑����ق����x���ق�)
	//�@�@�@�@�@�@�@�@�@�@��[�抷�wIndex�ŁA�\�[�g�O��ԁ��\�[�g���Ԃ�
	//�@�@�@�@�@�@�@�@�@�@�@�@��p��10���ȓ��ŉ\]
	//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒��O�ɁA
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
	//�@�@���\�[�g�O��Ԃ�1�{�ł�����������A���̃��[�v���Ď��s
	do{
		iRessyaIndexBeforSortCount = pcontRessyaIndexBeforeSort->size() ;

		for ( int iEkiOrder = aEkijikokuOrder.getEkiOrder()  ; 
			!bAbort && iEkiOrder >= 0 ;
			iEkiOrder -- )
		{
			CentDedEkiCont::CdDedEki	aEki = pEkiCont->getMuPtr(eRessyahoukou)->get( iEkiOrder ) ;
			if ( aEki.getEkikibo() != CentDedEki::Ekikibo_Syuyou )
			{
				bAbort = sortRessyaIndex_TransferToSortedRessyaAtEki( 
					pEstimateRessyaCont ,
					pcontRessyaIndexBeforeSort , 
					pcontRessyaIndexAfterSort , 
					iEkiOrder , 
					10 * 60 , 
					pIfProgress ) ; 
			}
		}

	} while( !bAbort && iRessyaIndexBeforSortCount > (int)pcontRessyaIndexBeforeSort->size() ) ;

	//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw(F)���O�̒�ԉw�ŏ�芷���̂ł���\�[�g���Ԃ�T���B
	//�@�@����芷���wOrder�̃��[�v(�\�[�g�Ώۉw-1�`�N�_�w)
	//�@�@�@�@�@�@���S�\�[�g�O��Ԃ̃��[�v
	//�@�@�@�@�@�@�@�@���S�\�[�g���Ԃ̃��[�v(�����̒x���ق��������ق�)
	//�@�@�@�@�@�@�@�@�@�@��[�抷�wIndex�ŁA�\�[�g�O��ԁ��\�[�g���Ԃ̏�p���\]
	//�@�@�@�@�@�@�@�@�@�@�@�@���\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�́A�ΏۂƂȂ����\�[�g���Ԃ̒��O�ɁA
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�}��
	//�@�@���\�[�g�O��Ԃ�1�{�ł�����������A���̃��[�v���Ď��s
	//
	do{
		iRessyaIndexBeforSortCount = pcontRessyaIndexBeforeSort->size() ;

		for ( int iEkiOrder = aEkijikokuOrder.getEkiOrder() ; 
			!bAbort && iEkiOrder >= 0 ;
			iEkiOrder -- )
		{
			CentDedEkiCont::CdDedEki	aEki = pEkiCont->getMuPtr(eRessyahoukou)->get( iEkiOrder ) ;
			{
				bAbort = sortRessyaIndex_TransferToSortedRessyaAtEki( 
					pEstimateRessyaCont ,
					pcontRessyaIndexBeforeSort , 
					pcontRessyaIndexAfterSort , 
					iEkiOrder , 
					INT_MAX , 
					pIfProgress ) ; 
			}
		}

	} while( !bAbort && iRessyaIndexBeforSortCount > (int)pcontRessyaIndexBeforeSort->size() ) ;

	return bAbort ;
}


	// ********************************
	//	�R���X�g���N�^
	// ********************************
CDedRessyaSoater_Transfer::CDedRessyaSoater_Transfer(
	const CentDedRosen* pDedRosen , 
	const CentDedDia* pDedDia ,
	CdDedJikokuOrder  aCdDedJikokuOrder ) :  
	m_bIsValid( false ) ,
	m_pDedRosen( pDedRosen ) ,
	m_pDedDia( pDedDia ) ,
	m_JikokuOrder( aCdDedJikokuOrder ) 
{
}

CDedRessyaSoater_Transfer::~CDedRessyaSoater_Transfer() 
{
	invalidate() ;
}
	


int CDedRessyaSoater_Transfer::validate()  
{
	if ( isValid() )
	{
		return 0 ;
	}
	// --------------------------------
	int iRv = 1 ;
	//���\�[�g�Ώۂ̗�ԃR���e�i����A���莞������Ԃ�ێ�������Ԃ𐶐�
	//�@���\�[�g�Ώۂ̗�ԃR���e�i���܂��� CentDedDia ����ACentDedDgrDia �𐶐�
	//�@���\�[�g�Ώۂ̗�Ԃ̐��莞��CentDedRessyaCont�𐶐�
	//�@�@	���\�[�g�Ώۂ̑S��Ԃ̃��[�v
	//�@�@�@�@	��CentDedDgrRessya����A���莞������CentDedRessya�𐶐����A�R���e�i�ɒǉ�
	if ( iRv >= 1 )
	{
		m_CentDedDgrDia.readCentDedRosen(
			m_pDedRosen , 
			m_pDedDia );

	}


	// --------------------------------
	if ( iRv >= 1 )
	{
		m_bIsValid = true ;
	}
	else
	{
		invalidate() ;
	}
	return iRv ;
}
	
void CDedRessyaSoater_Transfer::invalidate() 
{
	m_bIsValid = false ;
}
	
bool CDedRessyaSoater_Transfer::isValid() 
{
	return m_bIsValid ;
}
	// ********************************
	//@name ����
	// ********************************


/**
	���Index���A�w�肳�ꂽ�w����Order�̎����Ŕ�r����֐��I�u�W�F�N�g�ł��B
*/
class CCompareRessyaIndex_Ekijikoku
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		��ԃR���e�i�B
	*/
	const CentDedRessyaCont* m_pRessyaCont ;

	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�w����Order�x���w�肵�Ă��������B
	*/
	CdDedJikokuOrder m_JikokuOrder ;

	/**
		�_�C���O�����N�_�������w�肵�Ă��������B
		���̊֐��́A�\�[�g���ɁA���̒l���ł�������������
		�݂Ȃ��܂��B
		(��F���̎�����5:00���w�肳�ꂽ�ꍇ�́A5:00<23:59<0:00<4:59 �Ƃ��Ĕ�r���s���܂�)
	*/
	CdDedJikoku m_jikokuKitenJikoku ;
	///@}
public:
	/**
	@param pRessyaCont [in]
		��ԃR���e�i�B
	@param iJikokuOrder [in]
		�w����Order�x���w�肵�Ă��������B
	@param jikokuKitenJikoku [in]
		�_�C���O�����N�_�������w�肵�Ă��������B
		���̊֐��́A�\�[�g���ɁA���̒l���ł�������������
		�݂Ȃ��܂��B
		(��F���̎�����5:00���w�肳�ꂽ�ꍇ�́A5:00<23:59<0:00<4:59 �Ƃ��Ĕ�r���s���܂�)
	*/
	CCompareRessyaIndex_Ekijikoku( 
		const CentDedRessyaCont* pRessyaCont ,
		const CdDedJikokuOrder& aJikokuOrder ,
		CdDedJikoku jikokuKitenJikoku )
		: 
		m_pRessyaCont( pRessyaCont ) ,
		m_JikokuOrder( aJikokuOrder ) ,
		m_jikokuKitenJikoku( jikokuKitenJikoku )
	{
	};
	/**
	@return
		left < right �Ȃ�^�ł��B

	@note
	  ��r��́A
			- �w������NULL�łȂ����̂�NULL�̂��̂Ƃł́ANULL�łȂ����̂���B
			- Ekijikoku�̏������ق�����B
			- Ekijikoku�������Ȃ�A����������B
			- Ekijikoku����/���������Ȃ�RessyaIdx�̏������ق�����B
	*/
	bool operator()( int left , int right )
	{
		const CentDedRessya*	pRessyaLeft = m_pRessyaCont->getMuPtr()->get( left ) ;
		const CentDedRessya*	pRessyaRight = m_pRessyaCont->getMuPtr()->get( right ) ;
		CentDedEkiJikoku	aEkiJikokuLeft = pRessyaLeft->getCentDedEkiJikoku( m_JikokuOrder.getEkiOrder()  ) ;
		CentDedEkiJikoku	aEkiJikokuRight = pRessyaRight->getCentDedEkiJikoku( m_JikokuOrder.getEkiOrder() ) ;
		CdDedJikoku aJikokuLeft ;
		bool bLeftIsHatsu = false ;
		CdDedJikoku aJikokuRight ;
		bool bRightIsHatsu = false ;

		if ( m_JikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku )
		{
			//	�������ŗD�悵�Ĕ�r
			aJikokuLeft = aEkiJikokuLeft.getChakujikoku() ;	
			bLeftIsHatsu = false ;
			if ( aEkiJikokuLeft.getChakujikoku().isNull() &&
				!aEkiJikokuLeft.getHatsujikoku().isNull() )
			{
				aJikokuLeft = aEkiJikokuLeft.getHatsujikoku() ;
				bLeftIsHatsu = true ;
			}
			aJikokuRight = aEkiJikokuRight.getChakujikoku() ;
			bRightIsHatsu = false ;
			if ( aEkiJikokuRight.getChakujikoku().isNull() &&
				!aEkiJikokuRight.getHatsujikoku().isNull() )
			{
				aJikokuRight = aEkiJikokuRight.getHatsujikoku() ;
				bLeftIsHatsu = true ;
			}
		}
		else
		{
			//	�������ŗD�悵�Ĕ�r

			aJikokuLeft = aEkiJikokuLeft.getHatsujikoku() ;	
			bLeftIsHatsu = true ;
			if ( !aEkiJikokuLeft.getChakujikoku().isNull() &&
				  aEkiJikokuLeft.getHatsujikoku().isNull() )
			{
				aJikokuLeft = aEkiJikokuLeft.getChakujikoku() ;
				bLeftIsHatsu = false ;
			}
			aJikokuRight = aEkiJikokuRight.getHatsujikoku() ;
			bRightIsHatsu = true ;
			if ( !aEkiJikokuRight.getChakujikoku().isNull() &&
				  aEkiJikokuRight.getHatsujikoku().isNull() )
			{
				aJikokuRight = aEkiJikokuRight.getChakujikoku() ;
				bLeftIsHatsu = false ;
			}

		}
		// --------------------------------
		//	�Е���NULL�̏ꍇ�̔�r
		// --------------------------------
		if ( !aJikokuLeft.isNull() && aJikokuRight.isNull() )
		{
			//	left��NULL�ŁAright�͔�NULL
			return true ;
		}
		else if ( aJikokuLeft.isNull() && !aJikokuRight.isNull() )
		{
			//	left�͔�NULL�ŁAright��NULL
			return false ;
		}
		// --------------------------------
		//	m_Jikoku �͂ǂ����NULL�ł͂Ȃ��E�������͂ǂ����NULL
		//	�����̔�r
		// --------------------------------
		int iResult = aJikokuLeft.compare( aJikokuRight , m_jikokuKitenJikoku ) ;
		if ( iResult == -1 )
		{
			return true ;
		}
		else if ( iResult == 1 )
		{
			return false ;
		}
		// --------------------------------
		// 	Ekijikoku�������Ȃ�A����������B
		// --------------------------------
		if ( !bLeftIsHatsu && bRightIsHatsu )
		{
			return true ;
		}
		else if ( bLeftIsHatsu && !bRightIsHatsu )
		{
			return false ;
		}

		// --------------------------------
		// �����E�����Ƃ��ɓ������ꍇ�́A���Index���������ق�����
		// --------------------------------
		if ( left < right )
		{
			return true ;
		}
		return false ;
	}

};


void CDedRessyaSoater_Transfer::sortRessyaIndex( 
		const CentDedRessyaCont* pRessyaCont , 
		Mui<int>* muRessyaIndexOrder , 
		IfProgress* pIfProgress ) 
{
	bool bAbort = false ;
	const CentDedEkiCont* pEkiCont = m_pDedRosen->getCentDedEkiCont() ;
	CdDedJikokuOrder aEkijikokuOrder = m_JikokuOrder ;
	ERessyahoukou eRessyahoukou = pRessyaCont->getRessyahoukou() ;

	//��pRessyaCont����A���莞������ԃR���e�i���쐬
	//	validate() �ŁAm_pDedRosen�� m_pDedDia �Ɋ܂܂��S��Ԃ�
	//	���莞�� CentDedRessya �𐶐����A���̓��e��ێ����܂��B

	CentDedRessyaCont aEstimateRessyaCont = pRessyaCont->createEmptyCont() ;
	for ( int idxRessya = 0 ; idxRessya < pRessyaCont->size() ; idxRessya ++ )
	{
		const CentDedRessya* pCentDedRessya = pRessyaCont->getMuPtr()->get( idxRessya ) ;
		CentDedDgrRessya	aCentDedDgrRessya( 
			m_pDedRosen , 
			&m_CentDedDgrDia , 
			pCentDedRessya ) ;

		CentDedRessya aEstimateRessya( aEstimateRessyaCont.createNullRessya() ) ; 
		m_CentDedDgrDia.createEstimateRessya2( 
			&aCentDedDgrRessya ,
			&aEstimateRessya ) ;
		aEstimateRessyaCont.insert( aEstimateRessya ) ;
	}
	//aEstimateRessyaCont = pRessyaCont �ɐ��莞����ǉ����܂����B
	CentDedRessyaCont*	pEstimateRessyaCont = &aEstimateRessyaCont ;

	//���\�[�g�O�w�C���f�N�X�R���e�i�𐶐�
	vector<int>	contRessyaIndexBeforSort ;
	vector<int>	contRessyaIndexAfterSort ;
	{
		contRessyaIndexBeforSort.reserve( muRessyaIndexOrder->size() ) ;
		contRessyaIndexAfterSort.reserve( muRessyaIndexOrder->size() ) ; 
		CaMui<int>( &CaMup_vector<vector<int>>( &contRessyaIndexBeforSort ) ).insert( muRessyaIndexOrder ) ; ;
	}

	//���w�����̂���(���)���̂��A�\�[�g��R���e�i�Ɉڂ�
	if ( !bAbort )
	{
		for ( int idx = 0 ; idx < (int)contRessyaIndexBeforSort.size() ; idx++ )
		{
			int iRessyaIndex = contRessyaIndexBeforSort[idx] ;

			const CentDedRessya* pRessya = pEstimateRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
			CentDedEkiJikoku aEkiJikoku = pRessya->getCentDedEkiJikoku( aEkijikokuOrder.getEkiOrder() ) ;
			CdDedJikoku	aJikoku = pRessya->getEkiJikoku( aEkijikokuOrder ) ;

			if ( aEkiJikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya )
			{
				contRessyaIndexAfterSort.push_back( iRessyaIndex ) ;
				contRessyaIndexBeforSort.erase(	contRessyaIndexBeforSort.begin() + idx ) ;
				idx -- ;
			}
		}
	}

	if ( !bAbort )
	{
		if ( pIfProgress != NULL )
		{
			int iResult = pIfProgress->onNotifyProgress( 
				contRessyaIndexAfterSort.size() ,
				pEstimateRessyaCont->size() ) ;
			if ( iResult != 0 )
			{
				bAbort = true ;
			}
		}
	}	

	//���\�[�g��R���e�i���A�w�����Ń\�[�g����B
	//
	//@code
	//�\�[�g��
	//RessyaIdx ��2   ��5   ��
	//G         ��0012��0020��
	//��/�� �@�@�����@����  ��
	//@endcode	        
	//
	//@code
	//�\�[�g�O
	//RessyaIdx ��0   ��1   ��3   ��4   ��6   ��
	//G         ��NULL��NULL��NULL��NULL��NULL��
	//��/�� �@�@����  ����  ����  ����  ����  ��
	//@endcode	        
	if ( !bAbort )
	{
		std::sort( 
			contRessyaIndexAfterSort.begin() , 
			contRessyaIndexAfterSort.end() ,
			CCompareRessyaIndex_Ekijikoku( 
				pEstimateRessyaCont , 
				aEkijikokuOrder , 
				m_pDedRosen->getKitenJikoku() ) 
			) ;
	}



	if ( aEkijikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku)
	{
		//	�������Ń\�[�g�̏ꍇ

		//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw���O�̒�ԉw�ŏ�芷���̂ł���\�[�g���Ԃ̑O�ɔz�u
		if ( !bAbort )
		{
			bAbort = sortRessyaIndex_TransferToSortedRessya( 
				pEstimateRessyaCont ,
				&contRessyaIndexBeforSort , 
				&contRessyaIndexAfterSort , 
				aEkijikokuOrder , 
				pIfProgress ) ; 
		}

		//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw��肠�Ƃ̒�ԉw�ŏ�芷���̂ł���\�[�g���Ԃ̌��ɔz�u
		if ( !bAbort )
		{
			bAbort = sortRessyaIndex_TransferFromSortedRessya( 
				pEstimateRessyaCont ,
				&contRessyaIndexBeforSort , 
				&contRessyaIndexAfterSort , 
				aEkijikokuOrder , 
				pIfProgress ) ; 
		}

		//���\�[�g�O��Ԃ��A���ׂĂ̒�ԉw�ŏ�芷���̂ł���\�[�g���Ԃ̌��ɔz�u
		if ( !bAbort )
		{
			bAbort = sortRessyaIndex_TransferFromSortedRessya( 
				pEstimateRessyaCont ,
				&contRessyaIndexBeforSort , 
				&contRessyaIndexAfterSort , 
				CdDedJikokuOrder( 0 , CdDedJikokuOrder::EkiJikokuItem_Chaku )  , 
				pIfProgress ) ; 
		}
	}
	else
	{
		//	�������Ń\�[�g

		//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw��肠�Ƃ̒�ԉw�ŏ�芷���̂ł���\�[�g���Ԃ̌��ɔz�u
		if ( !bAbort )
		{
			bAbort = sortRessyaIndex_TransferFromSortedRessya( 
				pEstimateRessyaCont ,
				&contRessyaIndexBeforSort , 
				&contRessyaIndexAfterSort , 
				aEkijikokuOrder , 
				pIfProgress ) ; 
		}

		//���\�[�g�O��Ԃ��A�\�[�g�Ώۉw���O�̒�ԉw�ŏ�芷���̂ł���\�[�g���Ԃ̑O�ɔz�u
		if ( !bAbort )
		{
			bAbort = sortRessyaIndex_TransferToSortedRessya( 
				pEstimateRessyaCont ,
				&contRessyaIndexBeforSort , 
				&contRessyaIndexAfterSort , 
				aEkijikokuOrder , 
				pIfProgress ) ; 
		}
		//���\�[�g�O��Ԃ��A���ׂĂ̒�ԉw�ŏ�芷���̂ł���\�[�g���Ԃ̑O�ɔz�u
		if ( !bAbort )
		{
			bAbort = sortRessyaIndex_TransferToSortedRessya( 
				pEstimateRessyaCont ,
				&contRessyaIndexBeforSort , 
				&contRessyaIndexAfterSort , 
				CdDedJikokuOrder( pEkiCont->size() - 1 , CdDedJikokuOrder::EkiJikokuItem_Hatsu) , 
				pIfProgress ) ; 
		}

	}


	//���c�����\�[�g�O���(�\�[�g�Ώۉw(F)����̗��p���s�\�ȗ��)���\�[�g���ԂɈړ�
	//�@�@�@�@�@�@���S�\�[�g�O��Ԃ̃��[�v
	//�@�@�@�@�@�@�@�@��[�I���w���\�[�g�Ώۉw����]�\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�̐擪�ɑ}��
	//�@�@�@�@�@�@�@�@��[else]�\�[�g�O��Ԃ��\�[�g�O��ԃR���e�i����폜���A
	//�@�@�@�@�@�@�@�@�@�@�@�@�@�\�[�g���ԃR���e�i�̖����ɑ}��
	if ( !bAbort )
	{
		int idxTo = 0 ;
		for ( int idx = 0 ; idx < (int)contRessyaIndexBeforSort.size() ; idx ++ )
		{
			int iRessyaIndex = contRessyaIndexBeforSort[idx] ;

			const CentDedRessya* pRessya = pRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
			if ( !pRessya->isNull() && pRessya->getSyuuchakuEki() > aEkijikokuOrder.getEkiOrder() )
			{
				contRessyaIndexBeforSort.erase(
					contRessyaIndexBeforSort.begin() + idx ) ;
				idx -- ;

				contRessyaIndexAfterSort.insert( 
					contRessyaIndexAfterSort.begin() + idxTo , 
					iRessyaIndex ) ;
				idxTo ++ ;

			}
		}
	}
	


	//�ŏI�I�Ƀ\�[�g�ł��Ȃ��������Index�́A�����ɒǉ�
	{
		contRessyaIndexAfterSort.insert( 
			contRessyaIndexAfterSort.end() ,
			contRessyaIndexBeforSort.begin() ,
			contRessyaIndexBeforSort.end() ) ;
		contRessyaIndexBeforSort.clear() ;
	}

	//�\�[�g���ʂ� muRessyaIndexOrder �Ɋi�[
	{
		muRessyaIndexOrder->erase( 0 , INT_MAX ) ;
		CaMui<int>( muRessyaIndexOrder ).insert( &CaMup_vector<vector<int>>( &contRessyaIndexAfterSort ) ) ; ;
	}
};


int CDedRessyaSoater_Transfer::calcNorikaeSec( 
	const CentDedEkiJikoku& aEkiJikokuFrom , 
	const CentDedEkiJikoku& aEkiJikokuTo ,
	const CdDedJikoku& jikokuKitenJikoku ) 
{
	int iNorikaeSec = -1 ;
	if ( aEkiJikokuFrom.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya &&
		aEkiJikokuTo.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya )
	{

		//	��芷������Ԓ���������芷�����Ԕ�����
		CdDedJikoku	jikokuFrom = aEkiJikokuFrom.getChakujikoku() ;
		CdDedJikoku	jikokuTo = aEkiJikokuTo.getHatsujikoku() ;
		// --------------------------------
		if ( !jikokuFrom.isNull() && !jikokuTo.isNull() )
		{
			int iComp = jikokuTo.compare( jikokuFrom , jikokuKitenJikoku ) ;
			if ( iComp >= 0 )
			{
				//	�������͒�������肠��(�_�C���O�����N�_�������܂����ł��Ȃ�)

				iNorikaeSec = jikokuTo.subJikoku( jikokuFrom ) ;
				if ( iNorikaeSec < 0 )
				{
					iNorikaeSec = -1 ;
				}
			}
		}
	}
		//iNorikaeSec = ��芷������(�b��)
		//	��芷���s�\�Ȃ�A-1 ;

	return iNorikaeSec ;
}

} //namespace entDgr
