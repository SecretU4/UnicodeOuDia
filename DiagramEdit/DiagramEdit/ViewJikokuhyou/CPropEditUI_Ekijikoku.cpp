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
//	$Id: CPropEditUI_Ekijikoku.cpp 357 2016-08-18 16:59:16Z okm $
// ****************************************************************

/** @file */

#include "stdafx.h"
#include "NsMu\CConvTable.h"
#include "CPropEditUi_EkiJikoku.h"
#include "str\CStrCharSizeMb.h"
#include "str\strLf.h"

namespace ViewJikokuhyou{
	using namespace OuLib::Str;

		
/** �_�C�A���O�{�b�N�X�ւ̎����̏�����ێ����܂��B */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	true ,		//	NoColon 
	CdDedJikoku::CConv::EHour_ZeroToNone ,		//	HourZeroToNone 
	CdDedJikoku::CConv::ESecond_NotIfZero ) ;	//	NoSecond


/**
	������UI�`�������߂��āA�����ɕϊ����܂��B
	�G�f�B�b�g�R���g���[���̓��e��2�������̏ꍇ�́A
	�O�̉w����Order�����ƂɁA����⊮���܂��B
@param strUIJikoku [in]
	UI�`���̎������w�肵�Ă��������B
@param jikokuRevOrder [in]
	���O�́w�w�����x�B
	���̒l�́AstrControl�����̂�(����2��)�̏ꍇ�A����⊮����̂Ɏg���܂��B
	�wNULL��ԁx�̏ꍇ�A���̕⊮�͍s���܂���B
@param pCdDedJikoku [out]
	���̊֐��́A������̉��߂ɐ���������A������̓��e��ϊ�����������
	�����ɏ������݂܂��B
@return
	���������� 0 �ȏ�B�����ւ̕ϊ����ł��Ȃ���Ε��̐��ł��B
	-	-1 ;	//	���ڐ����s�����Ă��܂��B
	-	-2 ;	//	���E���E�b�̕\�L���s���ł��B
*/
static int	getJikokuFromUI( 
	const string& strUIJikoku , 
	const CdDedJikoku& jikokuRevOrder , 
	CdDedJikoku* pCdDedJikoku ) 
{
	int	iRv = 0 ;
	CdDedJikoku	aCdDedJikoku ;
	string	strControl = CStrCharSizeMb::strToSingleByte( 
		OuLib::Str::strTrim( strUIJikoku ) ) ;

	int iResult = aCdDedJikoku.decode( strControl ) ;
	if ( iResult < 0 )
	{
		iRv = iResult ;
		//	�����񂪉��߂ł��܂���B
	}
	//iRv = 
	//-	-1 ;	//	���ڐ����s�����Ă��܂��B
	//-	-2 ;	//	���E���E�b�̕\�L���s���ł��B

	//	��������2���ŁA�O�̉w����������ꍇ�́A
	//	�������Ɏ���⊮
	if ( iRv == -1 && 
		 !jikokuRevOrder.isNull() && 
		strControl.size() == 2 && 
		isdigit( strControl[0] ) && 
		isdigit( strControl[1] ) )
	{
		int iMin = atoi( strControl.c_str() ) ;
		if ( 0 <= iMin && iMin < 60 )
		{
			aCdDedJikoku.setTime( jikokuRevOrder.getHour() , iMin ) ;
			CdDedJikan	jikanSub = aCdDedJikoku.subJikoku( 
				jikokuRevOrder ) ;
			if ( jikanSub.getTotalSeconds() < 0 )
			{
				aCdDedJikoku = aCdDedJikoku.getTotalSeconds() + 60*60 ;
			}
			//aCdDedJikoku = ���ݓ��͂��ꂽ2���̕�����ɁA
			//	jikokuRevOrder �Ȍ�ƂȂ鎞��⊮

			iRv = 0 ;	//	�����⊮�ɐ������܂����B 
		}
	}

	// --------------------------------
	if ( pCdDedJikoku != NULL )
	{
		*pCdDedJikoku = aCdDedJikoku ;
	}
	return iRv ;
}

	// ********************************
	//@name �G���[���b�Z�[�W
	// ********************************
const char* const CPropEditUi_EkiJikoku::ERRMSG_INVALID_CHAKUJIKOKU = "Invalid ChakuJikoku.";
const char* const CPropEditUi_EkiJikoku::ERRMSG_INVALID_HATSUJIKOKU = "Invalid HatsuJikoku.";




	// ================================
	//@name �����֐�
	// ================================


const CConvTable<CentDedEkiJikoku::EEkiatsukai,int>& getEkiatsukaiConvTable()
{
	static CConvTable<CentDedEkiJikoku::EEkiatsukai,int>	aTable ;
	if ( aTable.size() == 0 )
	{
		aTable.add( CentDedEkiJikoku::Ekiatsukai_None     , 0 ) ;//	�^�s�Ȃ�
		aTable.add( CentDedEkiJikoku::Ekiatsukai_Teisya   , 1 ) ;//	���
		aTable.add( CentDedEkiJikoku::Ekiatsukai_Tsuuka   , 2 ) ;//	�ʉ�
		aTable.add( CentDedEkiJikoku::Ekiatsukai_Keiyunasi, 3 ) ;// �o�R�Ȃ�
	}
	return aTable ;
}

	// ================================
	//@name UiData - Target�Ԃ̃f�[�^�]��
	// ================================

	

void CPropEditUi_EkiJikoku::UiDataFromTarget( UIDATA* pUiData ) 
{
	CdDedJikoku::CConv	aJikokuConv( g_CdDedJikokuConv ) ;
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		CentDedRessya* pRessya = m_pTarget->get( i ) ;
		CentDedEkiJikoku aEkiJikoku 
			= pRessya->getCentDedEkiJikoku( m_iEkiOrder ) ;

		/*	 �w�� 
			 -	 0: �^�s�Ȃ�
			 -	 1: ���
			 -	 2: �ʉ�
			 -	 3: �o�R�Ȃ�
			 -	-1: �I���Ȃ�
		*/
		if ( i == 0 )
		{
			pUiData->iEkiatsukai = getEkiatsukaiConvTable().rightFrom( 
				aEkiJikoku.getEkiatsukai() ) ;
		}
		else if ( pUiData->iEkiatsukai != getEkiatsukaiConvTable().rightFrom( 
			aEkiJikoku.getEkiatsukai() ) )
		{
			pUiData->iEkiatsukai = -1 ;
		}

		/* ������	*/
		if ( i == 0 )
		{
			//	�P��I�����A
			//	�w�����ʉ߁E��ԂȂ�A�L���ETarget�𔽉f
			//�@�@�o�R�Ȃ��Ȃ�L�����
			//�@�@�^�s�Ȃ��Ȃ�L�����
			if ( pUiData->iEkiatsukai == 1		// ���
				|| pUiData->iEkiatsukai ==2 )	// �ʉ�
			{
				pUiData->strChakujikoku = aJikokuConv.encode( 
					aEkiJikoku.getChakujikoku() ) ;
			}
			pUiData->bChakujikokuIsEnable = true ;
		}
		else 
		{
			//�����I�����́A�������͋�E����
			pUiData->strChakujikoku = "" ;
			pUiData->bChakujikokuIsEnable = false ;
		}

		/* ������	*/
		if ( i == 0 )
		{
			//	�P��I�����A
			//	�w�����ʉ߁E��ԂȂ�A�L���ETarget�𔽉f
			//�@�@�o�R�Ȃ��Ȃ�L�����
			//�@�@�^�s�Ȃ��Ȃ�L�����
			if ( pUiData->iEkiatsukai == 1		// ���
				|| pUiData->iEkiatsukai ==2 )	// �ʉ�
			{
				pUiData->strHatsujikoku 
					= aJikokuConv.encode( aEkiJikoku.getHatsujikoku() ) ;
			}
			pUiData->bHatsujikokuIsEnable = true ;
		}
		else
		{
			//�����I�����́A�������͋�E����
			pUiData->strHatsujikoku = "" ;
			pUiData->bHatsujikokuIsEnable = false ;
		}
	}
	// --------------------------------

	//	 �����̌J�グ�E�J�艺����ON/OFF�B
	pUiData->bModifyHatsujikoku = *m_pbModifyHatsujikoku ;

}
void CPropEditUi_EkiJikoku::AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
{
	//	�w��
	if ( bStartEdit || pUiDataPrev->iEkiatsukai != pUiData->iEkiatsukai )
	{
	}
	
	//	�w���Ɋ֌W���鐳�K��
	{
		//��[�P��I����]
		if ( m_pTarget->size() == 1 )
		{
			//�@���y�w���z�w�����^�s�Ȃ��E�o�R�Ȃ��ŁA
			//	�����������������ύX���ꂽ��A�w���͒�Ԃɂ���
			{
				if ( ( pUiData->iEkiatsukai == 0 || pUiData->iEkiatsukai == 3 )
					&& !bStartEdit
					&& ( pUiDataPrev->strChakujikoku != pUiData->strChakujikoku
					 || pUiDataPrev->strHatsujikoku != pUiData->strHatsujikoku)
				 )
				{
					pUiData->iEkiatsukai = 1 ;	
				}
			}
			//�@���y�������E�������z�w�����^�s�Ȃ��E�o�R�Ȃ��ɕύX���ꂽ��A
			//	�������E�������͖����ɂ���
			//�@���y�������E�������z�w������ԁE�ʉ߂ɕύX���ꂽ��A��
			//	�����E�������͗L���ɂ���B
			{
				if ( !bStartEdit 
					&& pUiDataPrev->iEkiatsukai !=  pUiData->iEkiatsukai )
				{
					if ( pUiData->iEkiatsukai == 0 
						|| pUiData->iEkiatsukai == 3 )
					{
						pUiData->bChakujikokuIsEnable = false ;
						pUiData->bHatsujikokuIsEnable = false ;
					}
					else 
					{
						pUiData->bChakujikokuIsEnable = true ;
						pUiData->bHatsujikokuIsEnable = true ;
					}
				}
			}
		}
		//���m�����I����]
		else if ( m_pTarget->size() > 1 )
		{
			//�@���y�������E�������z�������E�������͖����E��
			pUiData->bChakujikokuIsEnable = false ;
			pUiData->bHatsujikokuIsEnable = false ;
		}
	}


	//	���O�̎���Order�̉w�������擾
	//	���̒l�́A�����ȗ�����ĕ��݂̂����͂��ꂽ�Ƃ��ɁA
	//	����⊮����̂Ɏg���܂��B
	CdDedJikoku jikokuRevOrder ;
	if ( pUiData->bChakujikokuIsEnable )
	{
		CentDedRessya* pRessya = m_pTarget->get( 0 ) ;
		CdDedJikokuOrder aJikokuOrderRev = pRessya->findrevJikoku( 
			CdDedJikokuOrder( m_iEkiOrder - 1 , 
				CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ) ;
		if ( !aJikokuOrderRev.getIsNull() )
		{
			jikokuRevOrder = pRessya->getEkiJikoku( aJikokuOrderRev ) ;
		}
	}
	//jikokuRevOrder = ���O�̎���Order�̉w����

	/*  ������	*/
	if ( bStartEdit || pUiDataPrev->strChakujikoku != pUiData->strChakujikoku )
	{
		//�@���y�������z���������ύX���ꂽ��A
		//�@�@(1)������𔼊p�ɕϊ�
		//�@�@(2)��������2�����͂Ȃ�A����⊮���܂��B
		if ( pUiData->bChakujikokuIsEnable )
		{
			CdDedJikoku aJikoku ;
			int iResult = getJikokuFromUI( 
				pUiData->strChakujikoku , 
				jikokuRevOrder , 
				&aJikoku ) ;
			if ( iResult >= 0 )
			{
				pUiData->strChakujikoku = g_CdDedJikokuConv.encode( aJikoku ) ;
			}
		}
	}
	
	//	���O�̎���Order�𒅎����ōX�V�B
	//	���̒l�́A�����ȗ�����ĕ��݂̂����͂��ꂽ�Ƃ��ɁA
	//	����⊮����̂Ɏg���܂��B
	{
		CdDedJikoku aJikoku( pUiData->strChakujikoku ) ;
		if ( !aJikoku.isNull() )
		{
			jikokuRevOrder = aJikoku ;
		}
	}
		//jikokuRevOrder = ���O�̎���Order�̉w�����B
		//	�A���A�������̓��͂�����΁A�������B

	/* ������	*/
	if ( bStartEdit || pUiDataPrev->strHatsujikoku != pUiData->strHatsujikoku )
	{
		//�@���y�������z���������ύX���ꂽ��A
		//�@�@(1)������𔼊p�ɕϊ�
		//�@�@(2)��������2�����͂Ȃ�A����⊮���܂��B
		if ( pUiData->bHatsujikokuIsEnable )
		{
			CdDedJikoku aJikoku ;
			int iResult = getJikokuFromUI( 
				pUiData->strHatsujikoku , 
				jikokuRevOrder , 
				&aJikoku ) ;
			if ( iResult >= 0 )
			{
				pUiData->strHatsujikoku = g_CdDedJikokuConv.encode( aJikoku ) ;
			}
		}
	}
	//�@���y�������z���������ύX����A�w�����̌J�グ�E�J�艺���x=�w�L���x�ŁA
	//		�����������͍ς݂Ȃ�A�������̌J�グ�E�J�艺�����s���܂��B�@
	if ( !bStartEdit 
		&& pUiDataPrev->strChakujikoku != pUiData->strChakujikoku )
	{
		if ( pUiData->bModifyHatsujikoku )
		{
			//	�������̑O��l�E���ݒl�E�������̓��͂��擾
			CdDedJikoku	jikokuChakuPrev( pUiDataPrev->strChakujikoku ) ;
			CdDedJikoku	jikokuChaku( pUiData->strChakujikoku ) ;
			CdDedJikoku jikokuHatsu( pUiData->strHatsujikoku ) ;
			if ( !jikokuChakuPrev.isNull() 
				&& !jikokuChaku.isNull()
				&& !jikokuHatsu.isNull() )
			{
				jikokuHatsu.addSeconds( jikokuChaku.subJikoku( jikokuChakuPrev ) );
				pUiData->strHatsujikoku = g_CdDedJikokuConv.encode( jikokuHatsu ) ;
			}
		}
	}
}	

int CPropEditUi_EkiJikoku::CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	//	�w��
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iEkiatsukai != pUiData->iEkiatsukai )
		{
		}
	}
	//	������
	if ( iRv >= 0 )
	{
		if ( bNewItem 
			|| pUiDataStartEdit->strChakujikoku != pUiData->strChakujikoku )
		{
			//�@���y�������z���������󕶎���łȂ��Ȃ�A
			//	�l�̎����ւ̕ϊ������݂āA�s���Ȃ�G���[�\��
			CdDedJikoku aJikoku ;
			int iResult = aJikoku.decode( pUiData->strChakujikoku ) ;
			if ( iResult < 0 )
			{
				iRv =  -11 ;
			}
		}
	}
	//	������
	if ( iRv >= 0 )
	{
		if ( bNewItem 
			|| pUiDataStartEdit->strHatsujikoku != pUiData->strHatsujikoku )
		{

			//�@���y�������z���������󕶎���łȂ��Ȃ�A
			//	�l�̎����ւ̕ϊ������݂āA�s���Ȃ�G���[�\��
			CdDedJikoku aJikoku ;
			int iResult = aJikoku.decode( pUiData->strHatsujikoku ) ;
			if ( iResult < 0 )
			{
				iRv = -12 ;
			}
		}
	}
	// --------------------------------
	//	�G���[���b�Z�[�W��\�����܂�
	// --------------------------------
	if ( iRv < 0 )
	{
		switch( iRv )
		{
		case -11 :
			ShowError( ERRMSG_INVALID_CHAKUJIKOKU ) ;
			SetFocus( offsetof( UIDATA , strChakujikoku )) ;
			break ;
		case -12 :
			ShowError( ERRMSG_INVALID_HATSUJIKOKU ) ;
			SetFocus( offsetof( UIDATA , strHatsujikoku ) );
			break ;
		}
	}
	return iRv ;
}

int CPropEditUi_EkiJikoku::UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{

	int iRv = 0 ; 
	for ( int i = 0 ; iRv >= 0 && i < m_pTarget->size() ; i ++ )
	{
		CentDedRessya* pRessya = m_pTarget->get( i ) ; 
		CentDedEkiJikoku aEkiJikoku 
			= pRessya->getCentDedEkiJikoku( m_iEkiOrder ) ;
		
		if ( bNewItem 
			|| pUiDataStartEdit->iEkiatsukai != pUiData->iEkiatsukai )
		{
			aEkiJikoku.setEkiatsukai( 
				getEkiatsukaiConvTable().leftFrom(  pUiData->iEkiatsukai ) ) ;
		}
		// strChakujikoku
		if ( bNewItem 
			|| pUiDataStartEdit->strChakujikoku != pUiData->strChakujikoku )
		{
			if ( pUiData->bChakujikokuIsEnable )
			{
				CdDedJikoku	aJikoku ;
				int iResult = aJikoku.decode( pUiData->strChakujikoku ) ;
				if ( iResult >= 0 )
				{
					aEkiJikoku.setChakujikoku( aJikoku ) ;
				}
			}
		}
		// strHatsujikoku
		if ( bNewItem 
			|| pUiDataStartEdit->strHatsujikoku != pUiData->strHatsujikoku )
		{
			if ( pUiData->bHatsujikokuIsEnable )
			{
				CdDedJikoku	aJikoku ;
				int iResult = aJikoku.decode( pUiData->strHatsujikoku ) ;
				if ( iResult >= 0 )
				{
					aEkiJikoku.setHatsujikoku( aJikoku ) ;
				}
			}
		}
		// --------------------------------
		//	��Ԃɉw��������������(�J�グ�E�J�艺���̏ꍇ������܂�)
		if ( pUiData->bModifyHatsujikoku )
		{
			pRessya->modifyCentDedEkiJikoku( m_iEkiOrder , aEkiJikoku ) ;
		}
		else
		{
			pRessya->setCentDedEkiJikoku( m_iEkiOrder , aEkiJikoku ) ;
		}
	}
	
	if (  bNewItem || pUiDataStartEdit->bModifyHatsujikoku != pUiData->bModifyHatsujikoku  )
	{
		*m_pbModifyHatsujikoku = pUiData->bModifyHatsujikoku ;
	}
	return iRv ;
}	



	// ********************************
	//	�R���X�g���N�^
	// ********************************
CPropEditUi_EkiJikoku::CPropEditUi_EkiJikoku( 
		bool bNewItem , 
		Mu<CentDedRessya*>* pTarget , 
		bool* pbModifyHatsujikoku ,
		int iEkiOrder ) 
		: CPropEditUi2( bNewItem ) 
		, m_pTarget( pTarget ) 
		, m_pbModifyHatsujikoku( pbModifyHatsujikoku )
		, m_iEkiOrder( iEkiOrder )
{
}



} //namespace ViewJikokuhyou

