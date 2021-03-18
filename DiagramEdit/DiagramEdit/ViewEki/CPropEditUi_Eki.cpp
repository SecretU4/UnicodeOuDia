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
// ****************************************************************
//	$Id: CPropEditUi_Eki.cpp 357 2016-08-18 16:59:16Z okm $
// ****************************************************************

/** @file */
#include "stdafx.h"
#include "CPropEditUi_Eki.h"

namespace ViewEki {


	// ********************************
	//@name �G���[���b�Z�[�W
	// ********************************
	/// �w�����������܂�
const char* const CPropEditUi_Eki::ERRMSG_EKIMEI_TOO_LONG = "Ekimei is too long(Limit is 58 characters)." ;
	

//	// ================================
//	//@name �����֐�
//	// ================================
//
//void CPropEditUi_Eki::UiDataFromTarget( 
//		UIDATA* pUiData , 
//		const CentDedEki* pTarget ) 
//{
//	// �w�� 
//	pUiData->strEkimei = pTarget->getEkimei() ;
//
//	// �w�����`�� 
//	pUiData->iEkijikokukeisiki = (int)pTarget->getEkijikokukeisiki() ;
//	
//	// �w�K�� 
//	pUiData->iEkikibo = (int)pTarget->getEkikibo() ;
//
//	// ���E������ 
//	pUiData->iKyoukaisen = (int)pTarget->getKyoukaisen() ;
//
//	// �_�C���O������ԏ��\���i����j 
//	pUiData->iDiagramRessyajouhouHyoujiKudari = (int)pTarget->getDiagramRessyajouhouHyoujiKudari() ;
//
//	// �_�C���O������ԏ��\���i���j 
//	pUiData->iDiagramRessyajouhouHyoujiNobori = (int)pTarget->getDiagramRessyajouhouHyoujiNobori() ;
//
//}
//
//int CPropEditUi_Eki::UiDataToTarget( 
//		const UIDATA& aUiDataPrev , 
//		const UIDATA& aUiDataModified , 
//		CentDedEki* pTarget  ) 
//{
//	int iRv = 0 ;
//	// �w�� 
//	if ( iRv >= 0 
//		&& aUiDataPrev.strEkimei != pUiData->strEkimei )
//	{
//		pTarget->setEkimei( pUiData->strEkimei ) ;
//	}
//
//	// �w�����`�� 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iEkijikokukeisiki 
//			!= aUiDataModified.iEkijikokukeisiki )
//	{
//		pTarget->setEkijikokukeisiki( 
//			(CentDedEki::EEkijikokukeisiki)aUiDataModified.iEkijikokukeisiki ) ;
//	}
//	// �w�K�� 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iEkikibo != aUiDataModified.iEkikibo )
//	{
//		pTarget->setEkikibo( (CentDedEki::EEkikibo)aUiDataModified.iEkikibo ) ;
//	}
//
//	// ���E������ 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iKyoukaisen 
//			!= aUiDataModified.iKyoukaisen )
//	{
//		pTarget->setKyoukaisen( aUiDataModified.iKyoukaisen != 0 );
//	}
//
//	// �_�C���O������ԏ��\���i����j 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iDiagramRessyajouhouHyoujiKudari
//			!= aUiDataModified.iDiagramRessyajouhouHyoujiKudari )
//	{
//		pTarget->setDiagramRessyajouhouHyoujiKudari(
//			(CentDedEki::EDiagramRessyajouhouHyouji)aUiDataModified.iDiagramRessyajouhouHyoujiKudari ) ;
//	}
//
//	// �_�C���O������ԏ��\���i���j 
//	if ( iRv >= 0 
//		&& aUiDataPrev.iDiagramRessyajouhouHyoujiNobori 
//			!= aUiDataModified.iDiagramRessyajouhouHyoujiNobori )
//	{
//		pTarget->setDiagramRessyajouhouHyoujiNobori(
//			(CentDedEki::EDiagramRessyajouhouHyouji)aUiDataModified.iDiagramRessyajouhouHyoujiNobori ) ;
//	}
//
//	return iRv ;
//}
	// ================================
	//	�I�[�o�[���C�g�̕K�v�ȃ��\�b�h1-Target�Ɉˑ����鏈��
	// ================================
void CPropEditUi_Eki::UiDataFromTarget( UIDATA* pUiData ) 
{
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		const CentDedEki* pTarget = m_pTarget->get( i ) ; 
		// �w�� 
		if ( i == 0 )
		{
			pUiData->strEkimei = pTarget->getEkimei() ;
		}
		else if ( pUiData->strEkimei != pTarget->getEkimei() )
		{
			pUiData->strEkimei = "" ;
		}

		// �w�����`�� 
		if ( i == 0 )
		{
			pUiData->iEkijikokukeisiki = (int)pTarget->getEkijikokukeisiki() ;
		}
		else if ( pUiData->iEkijikokukeisiki != (int)pTarget->getEkijikokukeisiki() )
		{
			pUiData->iEkijikokukeisiki = -1 ;	//-1 : �s��
		}
		// �w�K�� 
		if ( i == 0 )
		{
			pUiData->iEkikibo = (int)pTarget->getEkikibo() ;
		}
		else if ( pUiData->iEkikibo != (int)pTarget->getEkikibo() )
		{
			pUiData->iEkikibo = -1 ;	//	�s��
		}
		// ���E������ 
		if ( i == 0 )
		{
			pUiData->iKyoukaisen = (int)pTarget->getKyoukaisen() ;
		}
		else if ( pUiData->iKyoukaisen != (int)pTarget->getKyoukaisen() )
		{
			pUiData->iKyoukaisen = -1 ;	// �s��
		}
		// �_�C���O������ԏ��\���i����j
		if ( i == 0 )
		{
			pUiData->iDiagramRessyajouhouHyoujiKudari = (int)pTarget->getDiagramRessyajouhouHyoujiKudari() ;
		}
		else if ( pUiData->iDiagramRessyajouhouHyoujiKudari != (int)pTarget->getDiagramRessyajouhouHyoujiKudari() )
		{
			pUiData->iDiagramRessyajouhouHyoujiKudari = -1 ;	//-1: �s��
		}
		// �_�C���O������ԏ��\���i���j 
		if ( i == 0 )
		{
			pUiData->iDiagramRessyajouhouHyoujiNobori = (int)pTarget->getDiagramRessyajouhouHyoujiNobori() ;
		}
		else if ( pUiData->iDiagramRessyajouhouHyoujiNobori != (int)pTarget->getDiagramRessyajouhouHyoujiNobori() )
		{
			pUiData->iDiagramRessyajouhouHyoujiNobori = -1 ;	// �s��
		}
	}

	// [�w�������w�����`���Ő��K��]�̐ݒ�
	pUiData->bAdjustByEkijikokukeisiki = *m_pbAdjustByEkijikokukeisiki ;
}
	
void CPropEditUi_Eki::AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
{
	/* �w�� */
	if ( bStartEdit || pUiDataPrev->strEkimei != pUiData->strEkimei)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}
	/* �w�����`�� */
	if ( bStartEdit || pUiDataPrev->iEkijikokukeisiki != pUiData->iEkijikokukeisiki)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}
	/* �w�K�� */
	if ( bStartEdit || pUiDataPrev->iEkikibo != pUiData->iEkikibo)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}

	/* ���E������ */
	if ( bStartEdit || pUiDataPrev->iKyoukaisen != pUiData->iKyoukaisen)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}

	/* �_�C���O������ԏ��\���i����j */
	if ( bStartEdit || pUiDataPrev->iDiagramRessyajouhouHyoujiKudari != pUiData->iDiagramRessyajouhouHyoujiKudari)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}

	/* �_�C���O������ԏ��\���i���j */
	if ( bStartEdit || pUiDataPrev->iDiagramRessyajouhouHyoujiNobori != pUiData->iDiagramRessyajouhouHyoujiNobori)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}

	/*	[�w�������w�����`���Ő��K��]�̐ݒ�ł��B*/
	if ( bStartEdit || pUiDataPrev->bAdjustByEkijikokukeisiki != pUiData->bAdjustByEkijikokukeisiki)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}

}

int CPropEditUi_Eki::CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	/* �w�� */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->strEkimei != pUiData->strEkimei)
		{
			if ( pUiData->strEkimei.length() > 58 )
			{
				ShowError( ERRMSG_EKIMEI_TOO_LONG ) ;
				SetFocus( offsetof( UIDATA , strEkimei )) ;
				iRv = -1 ;	//	�w�����������܂��B
			}
		}
	}
	/* �w�����`�� */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iEkijikokukeisiki != pUiData->iEkijikokukeisiki)
		{
			// pUiData->�����o�[�� �̃G���[�`�F�b�N���s���R�[�h�B
		}
	}
	/* �w�K�� */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iEkikibo != pUiData->iEkikibo)
		{
			// pUiData->�����o�[�� �̃G���[�`�F�b�N���s���R�[�h�B
		}
	}
	/* ���E������ */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iKyoukaisen != pUiData->iKyoukaisen)
		{
			// pUiData->�����o�[�� �̃G���[�`�F�b�N���s���R�[�h�B
		}
	}
	/* �_�C���O������ԏ��\���i����j */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iDiagramRessyajouhouHyoujiKudari != pUiData->iDiagramRessyajouhouHyoujiKudari)
		{
			// pUiData->�����o�[�� �̃G���[�`�F�b�N���s���R�[�h�B
		}
	}
	/* �_�C���O������ԏ��\���i���j */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iDiagramRessyajouhouHyoujiNobori != pUiData->iDiagramRessyajouhouHyoujiNobori)
		{
			// pUiData->�����o�[�� �̃G���[�`�F�b�N���s���R�[�h�B
		}
	}
	/*	[�w�������w�����`���Ő��K��]�̐ݒ�ł��B*/
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->bAdjustByEkijikokukeisiki != pUiData->bAdjustByEkijikokukeisiki)
		{
			// pUiData->�����o�[�� �̃G���[�`�F�b�N���s���R�[�h�B
		}
	}
	return iRv ;
}




int CPropEditUi_Eki::UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ;
	for ( int i = 0 ; iRv >= 0 && i < m_pTarget->size() ; i ++ )
	{
		CentDedEki* pTarget= m_pTarget->get( i ) ; 
		/* �w�� */
		if ( bNewItem || pUiDataStartEdit->strEkimei != pUiData->strEkimei)
		{
			pTarget->setEkimei( pUiData->strEkimei ) ;
		}
		/* �w�����`�� */
		if ( bNewItem || pUiDataStartEdit->iEkijikokukeisiki != pUiData->iEkijikokukeisiki)
		{
			pTarget->setEkijikokukeisiki( 
				(CentDedEki::EEkijikokukeisiki)pUiData->iEkijikokukeisiki ) ;
		}
		/* �w�K�� */
		if ( bNewItem || pUiDataStartEdit->iEkikibo != pUiData->iEkikibo)
		{
			pTarget->setEkikibo( (CentDedEki::EEkikibo)pUiData->iEkikibo ) ;
		}
		/* ���E������ */
		if ( bNewItem || pUiDataStartEdit->iKyoukaisen != pUiData->iKyoukaisen)
		{
			pTarget->setKyoukaisen( pUiData->iKyoukaisen != 0 );
		}
		/* �_�C���O������ԏ��\���i����j */
		if ( bNewItem || pUiDataStartEdit->iDiagramRessyajouhouHyoujiKudari != pUiData->iDiagramRessyajouhouHyoujiKudari)
		{
			pTarget->setDiagramRessyajouhouHyoujiKudari(
				(CentDedEki::EDiagramRessyajouhouHyouji)pUiData->iDiagramRessyajouhouHyoujiKudari ) ;
		}
		/* �_�C���O������ԏ��\���i���j */
		if ( bNewItem || pUiDataStartEdit->iDiagramRessyajouhouHyoujiNobori != pUiData->iDiagramRessyajouhouHyoujiNobori)
		{
			pTarget->setDiagramRessyajouhouHyoujiNobori(
				(CentDedEki::EDiagramRessyajouhouHyouji)pUiData->iDiagramRessyajouhouHyoujiNobori ) ;
		}
	}
	/*	[�w�������w�����`���Ő��K��]�̐ݒ�ł��B*/
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->bAdjustByEkijikokukeisiki != pUiData->bAdjustByEkijikokukeisiki)
		{
			// [�w�������w�����`���Ő��K��]�̐ݒ�
			*m_pbAdjustByEkijikokukeisiki = pUiData->bAdjustByEkijikokukeisiki ;
		}
	}
	return iRv ;
}


	// ********************************
	//	�R���X�g���N�^
	// ********************************
CPropEditUi_Eki::CPropEditUi_Eki( 
	bool bNewItem , 
	Mu<CentDedEki*>* pTarget ,
	bool* pbAdjustByEkijikokukeisiki )
	: CPropEditUi2( bNewItem ) 
	, m_pTarget( pTarget ) 
	, m_pbAdjustByEkijikokukeisiki( pbAdjustByEkijikokukeisiki ) 
{	
};

} //namespace ViewEki 



