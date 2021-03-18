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
//	CentDedDgrRessya.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include "CentDedDgrRessya.h"
#include "logmsg/LogMsg.h"
#include "CentDedDgrDia.h"

using namespace std ;

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif //_CONSOLE

namespace entDgr{

/** �����̏�����ێ����܂��B */
const CdDedJikoku::CConv	g_CdDedJikokuConv(
	true ,		//	NoColon 
	// ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" ���폜���܂��B
	CdDedJikoku::CConv::EHour_ZeroToNone ,	
	CdDedJikoku::CConv::ESecond_NoSecond 	// �b����ɏo�͂��܂���B 
	) ;
// ****************************************************************
//	CentDedDgrRessya
// ****************************************************************
	// --------------------------------
	//@name readCentDedRessya() �̉����֐�
	// --------------------------------
	/*
		readCentDedRessya() �̉����֐�
		(01)CentDedDgrRessya�̑����̂����ACentDedRessya �݂̂Ō��肷�鑮����ݒ�
	*/
void CentDedDgrRessya::readCentDedRessya_01_readProp( const CentDedRessya* pCentDedRessya ) 
{
	m_bIsNull = pCentDedRessya->isNull() ;
	m_eRessyahoukou = pCentDedRessya->getRessyahoukou() ;
	m_iRessyasyubetsuIndex = pCentDedRessya->getRessyasyubetsuIndex() ;
	m_strRessyabangou = pCentDedRessya->getRessyabangou() ;
	m_strRessyamei = pCentDedRessya->getRessyamei() ;
	m_strGousuu = pCentDedRessya->getGousuu() ;

	m_DgrXZone = CdDcdZone() ;
}
	/*
		readCentDedRessya() �̉����֐�
		(02)CentDedDgrEkiJikoku �𐶐����A CentDedEkiJikoku �Ō��܂鑮��������B
	*/
void CentDedDgrRessya::readCentDedRessya_02_CreateCentDedEkiJikoku( 
		const CentDedRessya* pCentDedRessya ) 
{
	//	���O�̉w�̉w�����B
	CdDedJikoku	aCdDedJikokuLastStation ;


	//	���O�̉w�̉w�����ł�X���W�BaCdDedJikokuLastStation ��NULL�̏ꍇ��
	//	�����ł��B
	//	�ŏ��́uNULL�łȂ��w�����v�����������ꍇ�́A���̉w�������瓱�o���ꂽ
	//	X���W�ɂȂ�܂��B
	//	2�ӏ��ڈȍ~�́uNULL�łȂ��w�����v�ȍ~�́A
	//	�O�̉w��������̌o�ߎ��Ԃ����Z���܂��B
	//
	//	iXZahyouLastStation = iXZahyouLastStation 
	//		+ ( ���̉w�̉w���� - aCdDedJikokuLastStation ) 
	//
	//	����ɂ��A24:00���܂������đ����Ԃł́A
	//	24:00�ȍ~�̉w�����ɑΉ����� X���W�� 24:00 ����(24*60*60=86400) �ȏ�
	//	�ɂȂ�܂��B
	int	iXZahyouLastStation = 0 ;

	for ( int iEkiOrder = 0 ; 
		iEkiOrder < pCentDedRessya->getCentDedEkiJikokuCount() ; 
		iEkiOrder ++ )
	{
		CentDedEkiJikoku aCentDedEkiJikoku 
			= pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;

		//	�w��������AX���W���v�Z	
		int iDgrXZahyou[2] = { INT_MIN , INT_MIN } ;
		for ( int iChakuHatsu = 0 ; iChakuHatsu < 2 ; iChakuHatsu ++ )
		{
			int iX = INT_MIN ;
			CdDedJikokuOrder::EEkiJikokuItem eEkiJikokuItem = CdDedJikokuOrder::EkiJikokuItem_Chaku ;
			if ( iChakuHatsu == 1 )
			{
				eEkiJikokuItem = CdDedJikokuOrder::EkiJikokuItem_Hatsu ; 
			}


			CdDedJikokuOrder	aCdDedJikokuOrder ;
			aCdDedJikokuOrder.setEkiOrder( iEkiOrder , 
				eEkiJikokuItem ) ;
			CdDedJikoku	aCdDedJikoku 
				= pCentDedRessya->getEkiJikoku( aCdDedJikokuOrder ) ;

			if ( aCdDedJikoku.isNull() )
			{
				//	NULL �����Ȃ�A�����Ȃ�
			}
			else if ( aCdDedJikokuLastStation.isNull() )
			{
				//	1��ڈȍ~�́A��NULL����
				iX = aCdDedJikoku.getTotalSeconds() ;	//	�ŏ��́A��NULL����
			}
			else
			{
				//	2��ڈȍ~�́A��NULL����
				CdDedJikan	aCdDedJikan 
					= aCdDedJikoku.subJikoku( aCdDedJikokuLastStation ) ;
				iX = iXZahyouLastStation + aCdDedJikan.getTotalSeconds() ;
			}
			// --------------------------------
			if ( iX != INT_MIN )
			{
				aCdDedJikokuLastStation = aCdDedJikoku ;
				iXZahyouLastStation = iX ;
			}
			iDgrXZahyou[iChakuHatsu] = iX ;
		}

		CentDedDgrEkiJikoku	aCentDedDgrEkiJikoku( 
			aCentDedEkiJikoku.getEkiatsukai() ,
			iDgrXZahyou[0] ,
			iDgrXZahyou[1] ) ;
		
		m_MuCentDedDgrEkiJikoku.insert( aCentDedDgrEkiJikoku ) ;
	}
}

void CentDedDgrRessya::readCentDedRessya_03_updateDgrXZone() 
{
	int iDgrXMin = INT_MIN ;
	int iDgrXMax = INT_MIN ;
	for ( int idx = 0 ; idx < m_MuCentDedDgrEkiJikoku.size() ; idx ++ )
	{
		CentDedDgrEkiJikoku	aCentDedDgrEkiJikoku 
			= m_MuCentDedDgrEkiJikoku.get( idx ) ;
		if ( aCentDedDgrEkiJikoku.getDgrXPosChaku() != INT_MIN )
		{
			if ( iDgrXMin == INT_MIN || 
				iDgrXMin > aCentDedDgrEkiJikoku.getDgrXPosChaku() )
			{
				iDgrXMin = aCentDedDgrEkiJikoku.getDgrXPosChaku() ;
			}
			if ( iDgrXMax == INT_MIN || 
				iDgrXMax < aCentDedDgrEkiJikoku.getDgrXPosChaku() )
			{
				iDgrXMax = aCentDedDgrEkiJikoku.getDgrXPosChaku() ;
			}
		}

		if ( aCentDedDgrEkiJikoku.getDgrXPosHatsu() != INT_MIN )
		{
			if ( iDgrXMin == INT_MIN || 
				iDgrXMin > aCentDedDgrEkiJikoku.getDgrXPosHatsu() )
			{
				iDgrXMin = aCentDedDgrEkiJikoku.getDgrXPosHatsu() ;
			}
			if ( iDgrXMax == INT_MIN || 
				iDgrXMax < aCentDedDgrEkiJikoku.getDgrXPosHatsu() )
			{
				iDgrXMax = aCentDedDgrEkiJikoku.getDgrXPosHatsu() ;
			}
		}
	}
	if ( iDgrXMin != INT_MIN && iDgrXMax != INT_MIN )
	{
		m_DgrXZone.setBeginEndPos( iDgrXMin , iDgrXMax ) ;

		//	iDgrXMin��iDgrXMax������̏ꍇ�́A��O�I�ɃT�C�Y��1�Ƃ��܂�
		if ( m_DgrXZone.getSize() == 0 )
		{
			m_DgrXZone.setSize( 1 ) ;
		}
	}
}

void CentDedDgrRessya::readCentDedRessya_04_updateShouldRessyajouhouDraw(
	const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) 
{
	bool	bFirstRessyajouhouHyoujiIsSet = false ;
	for ( int iEkiOrder = 0 ;
		iEkiOrder < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrder ++ )
	{
		bool	bShouldRessyajouhouDraw = false ;

		CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;

		CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki = 
			pMuCdDedDgrEki->get( iEkiOrder ) ;

		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			//	��Ԑ��̑��݂���w�ԁA
			CentDedDgrEki::EDiagramRessyajouhouHyouji	
				eDiagramRessyajouhouHyouji = 
					aCdDedDgrEki.getDiagramRessyajouhouHyouji() ;

			//	(1)  [���̗�Ԃ̗�ԏ�񂪂܂�1�ӏ����`�悳��Ă��Ȃ�]
			//		��ԏ��`�悪�u�\�����Ȃ��v�ȊO�̉w�ԁB
			if ( !bFirstRessyajouhouHyoujiIsSet && 
				eDiagramRessyajouhouHyouji !=
				CentDedDgrEki::DiagramRessyajouhouHyouji_Not ) 
			{
				bShouldRessyajouhouDraw = true ;
			}

			//	(2)  ��ԏ��`�悪�u��ɕ\���v�̉w��
			if ( eDiagramRessyajouhouHyouji ==
				CentDedDgrEki::DiagramRessyajouhouHyouji_Anytime )
			{
				bShouldRessyajouhouDraw = true ;

			}

		}

		pCentDedDgrEkiJikoku->setShouldRessyajouhouDraw( 
			bShouldRessyajouhouDraw ) ;
		if ( bShouldRessyajouhouDraw )
		{
			bFirstRessyajouhouHyoujiIsSet = true ;
		}

	}

	//	1�ӏ�����ԏ��`��ʒu���Ȃ��ꍇ�́A
	//	�ŏ��̗�Ԑ��ʒu�ɕ`�悵�܂��B
	for ( int iEkiOrder = 0 ;
		!bFirstRessyajouhouHyoujiIsSet 
			&& iEkiOrder < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrder ++ )
	{
		bool	bShouldRessyajouhouDraw = false ;

		CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;

		CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki = 
			pMuCdDedDgrEki->get( iEkiOrder ) ;

		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			//	��Ԑ��̑��݂���w�ԁA
				bShouldRessyajouhouDraw = true ;
		}

		pCentDedDgrEkiJikoku->setShouldRessyajouhouDraw( 
			bShouldRessyajouhouDraw ) ;
		if ( bShouldRessyajouhouDraw )
		{
			bFirstRessyajouhouHyoujiIsSet = true ;
		}

	}

}


//	(05)�o�R�Ȃ��̑O��̒���������₤
void CentDedDgrRessya::readCentDedRessya_05_complementKeiyunasiSide() 
{
	for ( int iEkiOrderBefore = 0 ; 
		iEkiOrderBefore < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrderBefore ++ )
	{
		// --------------------------------
		//	iEkiOrderBefore �ȍ~�ŁA�ȉ��̉w�����̕��т�T���܂��B
		//	(1)�w��={���,�ʉ�}�̂����ꂩ
		//	(2)�u�w��={�o�R�Ȃ�}�v��1�ȏ�̕���
		//	(3)�w��={���,�ʉ�}�̂����ꂩ
		// --------------------------------
		//	(1)�w��={���,�ʉ�}�̂����ꂩ �̉w��T��
		CentDedDgrEkiJikoku	ekijikokuBefore = 
			m_MuCentDedDgrEkiJikoku.get( iEkiOrderBefore ) ;
		if ( !(  
			( ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Teisya || 
			  ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
		) )
		{
			continue ;
		}
		//iEkiOrderBefore,ekijikokuBefore = (1)�w��={���,�ʉ�}�̂����ꂩ

		int iEkiOrderAfter = INT_MIN ;
		CentDedDgrEkiJikoku	ekijikokuAfter ;
		for ( iEkiOrderAfter = iEkiOrderBefore + 1  ;
				iEkiOrderAfter < m_MuCentDedDgrEkiJikoku.size() ;
				iEkiOrderAfter ++ )
		{
			ekijikokuAfter = 
				m_MuCentDedDgrEkiJikoku.get( iEkiOrderAfter ) ;
			if ( ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				//	(2)�u�w��={�o�R�Ȃ�}�v
				//		�̕���
				continue ;
			}
			else if ( ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Teisya || 
			  ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
			{
				//	(3)�w��={���,�ʉ�}�̂����ꂩ
				break ;
			}
			else
			{
				//	�����ɂ��Ă͂܂�Ȃ��w����
				//(��F����������̉w�E�^�s�Ȃ��̉w)
				iEkiOrderAfter = INT_MIN ;
				break ;
			}
		}
		if ( iEkiOrderAfter == INT_MIN 
			|| iEkiOrderAfter == m_MuCentDedDgrEkiJikoku.size() )
		{
			//	�����𖞂����w��������܂���
			continue ;
		}
		//iEkiOrderAfter,ekijikokuAfter = (3)�w��={���,�ʉ�}�̂����ꂩ
		if ( iEkiOrderBefore + 1 == iEkiOrderAfter )
		{
			//	(2)�u�w��={�o�R�Ȃ�}�v���܂܂�Ă��܂���B
			continue ;
		}

		//- �A�������o�R�Ȃ��̒��O�ɒ��������Ȃ� 
		//		AND �o�R�Ȃ��̒���ɒ�����������ꍇ
		//	���O�̒�������₢�܂��B
		if ( ekijikokuBefore.getDgrXPosChaku() == INT_MIN && 
			ekijikokuAfter.getDgrXPosChaku() != INT_MIN )
		{
			ekijikokuBefore.setDgrXPosChaku( ekijikokuAfter.getDgrXPosChaku());
		}
		
		//- �A�������o�R�Ȃ��̒��O�ɔ��������Ȃ� 
		//		AND �o�R�Ȃ��̒���ɔ�����������ꍇ
		//	���O�̔�������₢�܂��B
		if ( ekijikokuBefore.getDgrXPosHatsu() == INT_MIN && 
			ekijikokuAfter.getDgrXPosHatsu() != INT_MIN )
		{
			ekijikokuBefore.setDgrXPosHatsu( ekijikokuAfter.getDgrXPosHatsu() ) ;
		}

		//- �A�������o�R�Ȃ��̒��O�ɒ����������� 
		//		AND �o�R�Ȃ��̒���ɒ��������Ȃ��ꍇ�́A
		//	����̒�������₢�܂��B
		if ( ekijikokuBefore.getDgrXPosChaku() != INT_MIN && 
			ekijikokuAfter.getDgrXPosChaku() == INT_MIN )
		{
			ekijikokuAfter.setDgrXPosChaku(ekijikokuBefore.getDgrXPosChaku() );
		}
		//- �A�������o�R�Ȃ��̒��O�ɔ����������� 
		//		AND �o�R�Ȃ��̒���ɔ��������Ȃ��ꍇ�́A
		//	����̔�������₢�܂��B
		if ( ekijikokuBefore.getDgrXPosHatsu() != INT_MIN && 
			ekijikokuAfter.getDgrXPosHatsu() == INT_MIN )
		{
			ekijikokuAfter.setDgrXPosHatsu(ekijikokuBefore.getDgrXPosHatsu());
		}


		m_MuCentDedDgrEkiJikoku.set( 
			ekijikokuBefore ,
			iEkiOrderBefore ) ;
		m_MuCentDedDgrEkiJikoku.set( 
			ekijikokuAfter ,
			iEkiOrderAfter ) ;
		// --------------------------------
		//	���̌����J�n�ʒu�����߂�
		// --------------------------------
		{
			//	(1)�w��={���,�ʉ�}�̂����ꂩ
			//	(3)�w��={���,�ʉ�}�̂����ꂩ
			//	�̗��������������ꍇ�́A
			//	���̌����� (3)�w��={���,�ʉ�}�̂����ꂩ
			//	����n�߂܂��B
			iEkiOrderBefore = iEkiOrderAfter - 1;
		}
	}
}

void CentDedDgrRessya::readCentDedRessya_06_complementLongStop_01(
	const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) 
{
	// --------------------------------
	//	�����Ԓ�Ԃ̒�������₤
	// --------------------------------
	for ( int iEkiOrderBefore = 0 ; 
		iEkiOrderBefore < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrderBefore ++ )
	{
		// --------------------------------
		//	iEkiOrderBefore �ȍ~�ŁA�ȉ��̉w�����̕��т�T���܂��B
		//	(1)(������=���� or ������=����) AND �w��={���,�ʉ�}�̂����ꂩ
		//	(2)�u������=�Ȃ��A������=�Ȃ��A�w��={�ʉ�,�o�R�Ȃ�}�̂����ꂩ�v
		//		��0�ȏ�̕���
		//	(3)������=�Ȃ��A������=���� AND ��Ԃ̏I���w�łȂ�
		// --------------------------------
		//	(1)(������=���� or ������=����) AND �w��={���,�ʉ�}�̂����ꂩ
		//	�̉w��T��
		CentDedDgrEkiJikoku	ekijikokuBefore = 
			m_MuCentDedDgrEkiJikoku.get( iEkiOrderBefore ) ;
		if ( !( 
			( ekijikokuBefore.getDgrXPosChaku() != INT_MIN || 
			  ekijikokuBefore.getDgrXPosHatsu() != INT_MIN ) && 
			( ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Teisya || 
			  ekijikokuBefore.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
		) )
		{
			continue ;
		}
		//iEkiOrderBefore,ekijikokuBefore = 
		//	(1)(������=���� or ������=����) AND �w��={���,�ʉ�}�̂����ꂩ

		int iEkiOrderAfter = INT_MIN ;
		CentDedDgrEkiJikoku	ekijikokuAfter ;
		for ( iEkiOrderAfter = iEkiOrderBefore + 1  ;
				iEkiOrderAfter < m_MuCentDedDgrEkiJikoku.size() ;
				iEkiOrderAfter ++ )
		{

			ekijikokuAfter = 
				m_MuCentDedDgrEkiJikoku.get( iEkiOrderAfter ) ;
			if ( ekijikokuAfter.getDgrXPosChaku() == INT_MIN && 
				ekijikokuAfter.getDgrXPosHatsu() == INT_MIN && 
				( ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Teisya || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Tsuuka || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Keiyunasi ) )
			{
				//	(2)�u������=�Ȃ��A������=�Ȃ��A�w��={���,�ʉ�,�o�R�Ȃ�}��
				//		�����ꂩ�v��0�ȏ�̕���
				continue ;
			}
			else if ( ekijikokuAfter.getDgrXPosChaku() == INT_MIN && 
				ekijikokuAfter.getDgrXPosHatsu() != INT_MIN &&
				iEkiOrderAfter < getSyuuchakuEki() )
			{
				//	(3)������=�Ȃ��A������=���� AND ��Ԃ̏I���w�łȂ�
				break ;
			}
			else
			{
				//	�����ɂ��Ă͂܂�Ȃ��w����
				//(��F����������̉w�E�^�s�Ȃ��̉w)
				iEkiOrderAfter = INT_MIN ;
				break ;
			}
		}
		if ( iEkiOrderAfter == INT_MIN 
			|| iEkiOrderAfter == m_MuCentDedDgrEkiJikoku.size() )
		{
			//	�����𖞂����w��������܂���
			continue ;
		}
		//iEkiOrderAfter,ekijikokuAfter = 
		//	(3)������=�Ȃ��A������=���� AND ��Ԃ̏I���w�łȂ�

		// --------------------------------
		//	(1)�̔�����{�Ȃ���Β�����}+(1)�`(3)�Ԃ̉w�ԍŏ����v�b��
		//		��(3)�̔�����-60�b�Ȃ�A
		//	(3)�̒�����=(1)�̔�����+(1)�`(3)�Ԃ̉w�ԍŏ����v�b��
		//	�Ƃ��܂��B
		// --------------------------------

		int iDgrXPos = ekijikokuBefore.getDgrXPosHatsu() ;
		if ( iDgrXPos == INT_MIN )
		{
			iDgrXPos = ekijikokuBefore.getDgrXPosChaku() ;
		}
		iDgrXPos += calcEkikanSaisyouSec( 
			pMuCdDedDgrEki ,
			iEkiOrderBefore ,
			iEkiOrderAfter ) ; 
		//iDgrXPos = (1)�̔�����(�Ȃ���Β�����)+(1)�`(3)�Ԃ̉w�ԍŏ����v�b��

		if ( iDgrXPos < ekijikokuAfter.getDgrXPosHatsu() - 60 )
		{
			//	(1)�̔�����(�Ȃ���Β�����)+(1)�`(3)�Ԃ̉w�ԍŏ����v�b��
			//		��(3)�̔�����-60�b�Ȃ�A
			//	(3)�̒�����=(1)�̔�����+(1)�`(3)�Ԃ̉w�ԍŏ����v�b��
			//	�Ƃ��܂��B
			ekijikokuAfter.setDgrXPosChaku( iDgrXPos ) ;
			m_MuCentDedDgrEkiJikoku.set( ekijikokuAfter ,iEkiOrderAfter ) ;
		}
		// --------------------------------
		//	���̌����J�n�ʒu�����߂�
		// --------------------------------
		{
			//	(1)(������=���� or ������=����) AND �w��={���,�ʉ�}�̂����ꂩ
			//	(3)������=�Ȃ��A������=����
			//	�̗��������������ꍇ�́A
			//	���̌����� (3)������=�Ȃ��A������=����
			//	����n�߂܂��B
			iEkiOrderBefore = iEkiOrderAfter - 1;
		}
	}
}

	//	(06_02)�����Ԓ�Ԃ�����
	//		(�����Ԓ�Ԃ̒�����=����E������=�Ȃ� �̉w�ɁA��������₤)
void CentDedDgrRessya::readCentDedRessya_06_complementLongStop_02( 
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) 
{
	// --------------------------------
	//	�����Ԓ�Ԃ̒�������₤
	// --------------------------------
	for ( int iEkiOrderBefore = 0 ; 
		iEkiOrderBefore < m_MuCentDedDgrEkiJikoku.size() ; 
		iEkiOrderBefore ++ )
	{
		// --------------------------------
		//	iEkiOrderBefore �ȍ~�ŁA�ȉ��̉w�����̕��т�T���܂��B
		//	(1)������=����A������=�Ȃ�
		//	(2)�u������=�Ȃ��A������=�Ȃ��A�w��={�ʉ�,�o�R�Ȃ�}�̂����ꂩ�v
		//		��0�ȏ�̕���
		//	(3)������=����A�w��={���,�ʉ�}�̂����ꂩ
		// --------------------------------
		//	(1)������=����A������=�Ȃ�
		//	�̉w��T��
		CentDedDgrEkiJikoku	ekijikokuBefore = 
			m_MuCentDedDgrEkiJikoku.get( iEkiOrderBefore ) ;
		if ( !( 
			ekijikokuBefore.getDgrXPosChaku() != INT_MIN && 
			ekijikokuBefore.getDgrXPosHatsu() == INT_MIN 
		) )
		{
			continue ;
		}
		//iEkiOrderBefore,ekijikokuBefore = (1)������=����A������=�Ȃ�

		int iEkiOrderAfter = INT_MIN ;
		CentDedDgrEkiJikoku	ekijikokuAfter ;
		for ( iEkiOrderAfter = iEkiOrderBefore + 1  ;
				iEkiOrderAfter < m_MuCentDedDgrEkiJikoku.size() ;
				iEkiOrderAfter ++ )
		{
			ekijikokuAfter = 
				m_MuCentDedDgrEkiJikoku.get( iEkiOrderAfter ) ;
			if ( ekijikokuAfter.getDgrXPosChaku() == INT_MIN && 
				ekijikokuAfter.getDgrXPosHatsu() == INT_MIN && 
				( ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Teisya || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Tsuuka || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Keiyunasi ) )
			{
				//	(2)�u������=�Ȃ��A������=�Ȃ��A
				//		�w��={���,�ʉ�,�o�R�Ȃ�}�̂����ꂩ�v
				//		��0�ȏ�̕���
				continue ;
			}
			else if ( ekijikokuAfter.getDgrXPosChaku() != INT_MIN && 
				( ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Teisya || 
				  ekijikokuAfter.getEkiatsukai() == 
					CentDedEkiJikoku::Ekiatsukai_Tsuuka ) )
			{
				//	(3)������=����A�w��={���,�ʉ�}�̂����ꂩ
				break ;
			}
			else
			{
				//	�����ɂ��Ă͂܂�Ȃ��w����
				//(��F����������̉w�E�^�s�Ȃ��̉w)
				iEkiOrderAfter = INT_MIN ;
				break ;
			}
		}
		if ( iEkiOrderAfter == INT_MIN 
			|| iEkiOrderAfter == m_MuCentDedDgrEkiJikoku.size() )
		{
			//	�����𖞂����w��������܂���
			continue ;
		}
		//iEkiOrderAfter,ekijikokuAfter = (3)������=����A
		//		�w��={���,�ʉ�}�̂����ꂩ

		// --------------------------------
		//	(1)�̒�������(3)�̒�����-(1)�`(3)�Ԃ̉w�ԍŏ����v�b��-60�b�Ȃ�A
		//	(1)�̔�����=(3)�̒�����-(1)�`(3)�Ԃ̉w�ԍŏ����v�b��
		//	�Ƃ��܂��B
		// --------------------------------
		int iDgrXPos = ekijikokuAfter.getDgrXPosChaku() ;
		iDgrXPos -= calcEkikanSaisyouSec( 
			pMuCdDedDgrEki ,
			iEkiOrderBefore ,
			iEkiOrderAfter ) ; 
		//iDgrXPos = (3)�̒�����-(1)�`(3)�Ԃ̉w�ԍŏ����v�b��

		if ( ekijikokuBefore.getDgrXPosChaku() < iDgrXPos - 60 )
		{
			//	(1)�̒�������(3)�̒�����-(1)�`(3)�Ԃ̉w�ԍŏ����v�b��-60�b�Ȃ�A
			//	(1)�̔�����=(3)�̒�����-(1)�`(3)�Ԃ̉w�ԍŏ����v�b��
			//	�Ƃ��܂��B
			ekijikokuBefore.setDgrXPosHatsu( iDgrXPos ) ;
			m_MuCentDedDgrEkiJikoku.set( ekijikokuBefore ,iEkiOrderBefore ) ;
		}
		// --------------------------------
		//	���̌����J�n�ʒu�����߂�
		// --------------------------------
		{
			//	(1)������=����A�w��={���,�ʉ�}�̂����ꂩ
			//	(3)������=�Ȃ��A������=����
			//	�̗��������������ꍇ�́A
			//	���̌����� (3)������=�Ȃ��A������=����
			//	����n�߂܂��B
			iEkiOrderBefore = iEkiOrderAfter - 1;
		}
	}
}

	//(08)CentDedDgrRessyasen�̃R���e�i�𐶐����A
	//  CentDedDgrEkijikoku::m_iDgrXPosOnRessyasen
	//���C��
void CentDedDgrRessya::readCentDedRessya_08_updateRessyasenCont(
	const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) 
{
	m_pCentDedDgrRessyasenCont->erase( 0 , INT_MAX ) ;

	Mu<CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku 
		= this->getMuCentDedDgrEkiJikoku() ;

	int iRessyasenKitenEkiOrder = 0 ;
	int iResult = 0 ;
	//(01)
	//�w��Ԑ��N�_�wOrder�x��T���܂��B
	while ( ( iResult = updateRessyasenCont_01_calcRessyasenKiten( 
			iRessyasenKitenEkiOrder , 
			&iRessyasenKitenEkiOrder ) ) >= 0 )
	{
		//iRessyasenKitenEkiOrder = �w��Ԑ��N�_�wOrder�x


		// --------------------------------
		int iRessyasenSyuutenEkiOrder = INT_MIN ;

		//(02)�w��Ԑ��N�_�wOrder�x�ɑΉ�����w��Ԑ��I�_�wOrder�x���������܂��B
		//	
		//	  (1)�@�w��Ԑ��I�_�wOrder�x�̏����́A
		//�u�������E�������̗������w�肳��Ă���v OR
		//�u ���̉w�̉w�������w�^�s�Ȃ��x �v OR
		//�u�u�w�wOrder�x���A���̗�Ԃɂ�����̏I���w�v 
		//	  �Ώۉw���݂���Ȃ���΁A��Ԑ��I�_�wOrder�̌���͎��s�ƂȂ�܂�
		//  (�o�R�Ȃ��̒��O�́A��Ԑ��̏I�_�ɂ͂Ȃ�܂���
		//  �@(���̎��_�ł̗�Ԑ��N�_�ƏI�_�́A�o�R�Ȃ����܂������Ƃ�����܂��B)
		//
		//	  (2)�@���̎��_�ŁA�w��Ԑ��I�_�wOrder�x�ɒ���������������
		//�ݒ肳��Ă��Ȃ��ꍇ�́A
		//�n���w�����Ɍ������āA�������E�������̂����ꂩ���w�肳��Ă���
		//�w���������܂��B
		//	  ���̌��ʁw��Ԑ��I�_�wOrder�x�ɑ�������w���Ȃ��ꍇ�́A
		//��Ԑ��I�_�wOrder�̌���͎��s�ƂȂ�܂��B
		{
			int iResult = updateRessyasenCont_02_calcRessyasenSyuuten(
				iRessyasenKitenEkiOrder , 
				&iRessyasenSyuutenEkiOrder ) ;

			//iResult = 
			//	-	0 ;	//	�w��Ԑ��I�_�wOrder�x���݂���܂����B
			//	-	-1 ;	//	��Ԑ��I�_�w������܂���B
			//				//	���̋�ԂɊւ��ẮA��Ԑ����쐬�ł��܂���B
			if ( iResult == -1 )
			{
				iRessyasenKitenEkiOrder ++ ;
				continue ;
			}
			//iRessyasenSyuutenEkiOrder = �w��Ԑ��I�_�wOrder�x�i�␳�O�j
		}
		//(04)
		//	�w�_�C���O������Ԑ��x�I�u�W�F�N�g����
		//	�w��Ԑ��N�_�wOrder�x�Ɓw��Ԑ��I�_�wOrder�x�̊Ԃ�
		//	�r���w�ŁA�������E�������̂����ꂩ���w�肳��Ă����v�w������΁A
		//	�����
		//	�w��Ԑ��I�_�wOrder�x�Ɓw��Ԑ��I�_�����x�ɂ��܂��B
		updateRessyasenCont_04_adjustRessyasenSyuuten4( 
			pMuCdDedDgrEki ,
			iRessyasenKitenEkiOrder ,
			&iRessyasenSyuutenEkiOrder ) ;
		LogMsgL(3, "updateRessyasenCont_adjustRessyasenSyuuten4()4"
			" Kiten=%d Syuuten=%d" ,
			iRessyasenKitenEkiOrder ,iRessyasenSyuutenEkiOrder ) ;

		// --------------------------------
		{
			bool	bRetryRequested = false ;
			do{
				bRetryRequested = false ;

				//	�w��Ԑ��N�_�x�Ɓw��Ԑ��I�_�x�̊ԂɁA��Ԑ��𐶐�
				CentDedDgrRessyasen	aRessyasen(
					iRessyasenKitenEkiOrder ,iRessyasenSyuutenEkiOrder ) ;
				m_pCentDedDgrRessyasenCont->insert( aRessyasen ) ;

				//(05)
				//�w��Ԑ��R���e�i CentDedDgrRessyasenCont �x�̖�����
				//�w��Ԑ� CentDedDgrRessyasen�x�̓r���w�̒��ŁA
				//��Ԑ��̈ʒu(CentDedDgrEkiJikoku::m_iDgrXPosRessyasen)��
				//�������E������
				//(CentDedDgrEkiJikoku::m_iDgrXPosChaku,m_iDgrXPosHatsu)��
				//����60 �b�ȏ゠��ꍇ�́A���̉w���w��Ԑ��I�_�wOrder�x��
				//	���܂��B
				{
					int iResult=updateRessyasenCont_05_adjustRessyasenSyuuten5(
						&iRessyasenSyuutenEkiOrder ) ;
					//iResult = 
					//-	0 ;	//	�w��Ԑ��I�_�wOrder�x�̕␳�̕K�v�͂���܂���
					//		//	�ł����B
					//-	1 ;	//	�w��Ԑ��I�_�wOrder�x�̕␳���s���܂����B
					if ( iResult == 1 )
					{
						//iRessyasenSyuutenEkiOrder = 
						//	�w��Ԑ��I�_�wOrder�x�͏C������܂����B

						//	�����̗�Ԑ����폜
						m_pCentDedDgrRessyasenCont->erase( INT_MAX ) ;

						bRetryRequested = true ;
					}
				}
			}	while ( bRetryRequested ) ;
		}


		//(06)	�R���e�i�����̗�Ԑ����r���Ɂu�o�R�Ȃ��v���܂ޏꍇ�A
		//	���̗�Ԑ����u�o�R�Ȃ��v�܂łɒZ�k���܂��B
		//	(1)�u�o�R�Ȃ��v���O�̉w�E����̉w�̒��E���������u��Ԑ��w�����v��
		//	�u�������܂��B
		//	(2)��Ԑ��́u�o�R�Ȃ��v���O�܂łɒZ�k���܂��B
		//	(3)��Ԑ��I�_���u�o�R�Ȃ��v�̒��O�Ƃ��܂��B
		{
			int iResult = updateRessyasenCont_06_reduceToKeiyunasi( 
						&iRessyasenSyuutenEkiOrder ) ;
		}
		//	��Ԑ��N�_�w�́A���O�̏I�_�w�Ƃ��܂��B
		iRessyasenKitenEkiOrder = iRessyasenSyuutenEkiOrder ;

	}
}

int CentDedDgrRessya::updateRessyasenCont_01_calcRessyasenKiten( 
		int iEkiOrder ,
		int* piRessyasenKitenEkiOrder ) 
{
	//	�w��Ԑ��N�_�wOrder�x�̏����́A
	//	�u�������E�������̂����ꂩ���w�肳��Ă��� AND 
	//	���́w�wOrder�x�̉w�����w��ԁx���w�ʉ߁x�v
	Mu<CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku 
		= this->getMuCentDedDgrEkiJikoku() ;

	for ( ; iEkiOrder < pMuCentDedDgrEkiJikoku->size() - 1 ; 
			iEkiOrder ++ )
	{
		CentDedDgrEkiJikoku*	pEkiJikokuCurr = 
			pMuCentDedDgrEkiJikoku->get( iEkiOrder ) ;
		CentDedDgrEkiJikoku*	pEkiJikokuNext = 
			pMuCentDedDgrEkiJikoku->get( iEkiOrder + 1 ) ;
 
		int iDgrXPosHatsu = pEkiJikokuCurr->getDgrXPosHatsu( true ) ;
		if ( iDgrXPosHatsu != INT_MIN && 
			( pEkiJikokuNext->getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Teisya ||
			  pEkiJikokuNext->getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka ) ){
			*piRessyasenKitenEkiOrder = iEkiOrder ;
			return ( 0 ) ;
		} 
	}	
	return -1 ;	//	iEkiOrder �ȍ~�ŁA��Ԑ��N�_�w������܂���B
}

int CentDedDgrRessya::updateRessyasenCont_02_calcRessyasenSyuuten( 
		int iRessyasenKitenEkiOrder ,
		int* piRessyasenSyuutenEkiOrder ) 
{
	int iRv = 0 ;
	Mu<CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku 
		= this->getMuCentDedDgrEkiJikoku() ;

	int iSyuuchakuEki = getSyuuchakuEki()  ;
	int iRessyasenSyuutenEkiOrder = -1 ;

	//	  (1)�@�w��Ԑ��I�_�wOrder�x�̏����́A
	//�u�������E�������̗������w�肳��Ă���v OR
	//�u ���̉w�̉w�������w�^�s�Ȃ��x �v OR
	//�u�u�w�wOrder�x���A���̗�Ԃɂ�����̏I���w�v 
	//	  �Ώۉw���݂���Ȃ���΁A��Ԑ��I�_�wOrder�̌���͎��s�ƂȂ�܂�
	//  (�o�R�Ȃ��̒��O�́A��Ԑ��̏I�_�ɂ͂Ȃ�܂���
	//  �@(���̎��_�ł̗�Ԑ��N�_�ƏI�_�́A�o�R�Ȃ����܂������Ƃ�����܂��B)

	if ( iRv >= 0 )
	{
		for ( int iEkiOrder = iRessyasenKitenEkiOrder + 1 ; 
			iRessyasenSyuutenEkiOrder < 0 && 
				iEkiOrder <= iSyuuchakuEki ;
			iEkiOrder ++ )
		{
			CentDedDgrEkiJikoku	aEkiJikokuCurr = 
				*pMuCentDedDgrEkiJikoku->get( iEkiOrder ) ;
			CentDedDgrEkiJikoku	aEkiJikokuNext ;
			if ( iEkiOrder + 1 < pMuCentDedDgrEkiJikoku->size() )
			{
				aEkiJikokuNext = 
					*pMuCentDedDgrEkiJikoku->get( iEkiOrder + 1 ) ;
			}
			//aEkijikokuCurr = iEkiOrder �̉w����
			//aEkiJikokuNext = iEkiOder �̎��̉w�̉w�����B
			//	iEkiOrder���I���w�̏ꍇ�́ANULL�ƂȂ�܂��B


			int jikokuChaku = aEkiJikokuCurr.getDgrXPosChaku( false ) ;
			int	jikokuHatsu = aEkiJikokuCurr.getDgrXPosHatsu( false ) ;
			if ( jikokuChaku != INT_MIN && jikokuHatsu != INT_MIN )
			{
				//�u�������E�������̗������w�肳��Ă���v 
				iRessyasenSyuutenEkiOrder = iEkiOrder ;
			}
			else if ( aEkiJikokuNext.getEkiatsukai() == 
						CentDedEkiJikoku::Ekiatsukai_None ) 
			{
				//	�u���̉w�̉w�������w�^�s�Ȃ��x�v  
				iRessyasenSyuutenEkiOrder = iEkiOrder ;
			}
			else if ( iEkiOrder == iSyuuchakuEki )
			{
				//	�u�u�w�wOrder�x���A���̗�Ԃɂ�����̏I���w�v 
				iRessyasenSyuutenEkiOrder = iEkiOrder ;
			}
		}
		if ( iRessyasenSyuutenEkiOrder < 0 )
		{
			iRv = -1 ;	//	��Ԑ��I�_������ł��܂���B(�ʏ�͔������܂���)
		}
	}
	// iRessyasenSyuutenEkiOrder = �����肵����Ԑ��I�_�wOrder

	//	(2)�@���̎��_�ŁA�w��Ԑ��I�_�wOrder�x�ɒ���������������
	//	�ݒ肳��Ă��Ȃ��ꍇ�́A
	//	�n���w�����Ɍ������āA�������E�������̂����ꂩ���w�肳��Ă���
	//	�w���������܂��B
	//	  ���̌��ʁw��Ԑ��I�_�wOrder�x�ɑ�������w���Ȃ��ꍇ�́A
	//	��Ԑ��I�_�wOrder�̌���͎��s�ƂȂ�܂��B
	if ( iRv >= 0 )
	{
		for ( ; iRessyasenSyuutenEkiOrder > iRessyasenKitenEkiOrder ; 
			iRessyasenSyuutenEkiOrder -- )
		{
			CentDedDgrEkiJikoku	aEkiJikokuCurr = 
				*pMuCentDedDgrEkiJikoku->get( iRessyasenSyuutenEkiOrder ) ;
			int jikokuChaku = aEkiJikokuCurr.getDgrXPosChaku( false ) ;
			int	jikokuHatsu = aEkiJikokuCurr.getDgrXPosHatsu( false ) ;
			if ( jikokuChaku != INT_MIN || jikokuHatsu != INT_MIN )
			{
				//�u�������E�������̂ǂ��炩���w�肳��Ă���v 
				break ;
			}
		}
		if ( iRessyasenSyuutenEkiOrder == iRessyasenKitenEkiOrder )
		{
			iRv = -1 ;	//	��Ԑ��I�_������ł��܂���B
		}
		//iRessyasenSyuutenEkiOrder = 
		//	�������E�������̂����ꂩ���w�肳�ꂽ�A�w��Ԑ��I�_�wOrder�x
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		*piRessyasenSyuutenEkiOrder = iRessyasenSyuutenEkiOrder ;
	}
	return ( iRv ) ;
}

int CentDedDgrRessya::updateRessyasenCont_04_adjustRessyasenSyuuten4( 
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iRessyasenKitenEkiOrder ,
		int* piRessyasenSyuutenEkiOrder ) 
{
	int iRessyasenSyuutenEkiOrder = *piRessyasenSyuutenEkiOrder ;
	// --------------------------------
	//	�w��v�w�x��T���܂��B
	// --------------------------------
	Mu<CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku 
		= this->getMuCentDedDgrEkiJikoku() ;
	for ( int iEkiOrder = iRessyasenKitenEkiOrder + 1 ;
		iEkiOrder < iRessyasenSyuutenEkiOrder ; 
		iEkiOrder ++ )
	{
		CentDedDgrEkiCont::CdDedDgrEki aCdDedDgrEki = 
			pMuCdDedDgrEki->get( iEkiOrder ) ;
		CentDedDgrEkiJikoku aCentDedDgrEkiJikoku = 
			*pMuCentDedDgrEkiJikoku->get( iEkiOrder ) ;
		int jikokuToueki = aCentDedDgrEkiJikoku.getDgrXPosChaku( true ) ;

		if ( jikokuToueki != INT_MIN && 
			aCdDedDgrEki.getIsSyuyoueki() )
		{
			//	�w��Ԑ��N�_�wOrder�x�Ɓw��Ԑ��I�_�wOrder�x�̊Ԃ�
			//	�r���w�ŁA�������E�������̂����ꂩ���w�肳��Ă����v�w
			//	������΁A�����
			//	�w��Ԑ��I�_�wOrder�x�Ƃ��܂��B
			*piRessyasenSyuutenEkiOrder = iEkiOrder ;
			return 	1 ;	//	�w��Ԑ��I�_�wOrder�x�̕␳���s���܂����B
		}
		if ( aCentDedDgrEkiJikoku.getEkiatsukai() == 
				CentDedEkiJikoku::Ekiatsukai_Tsuuka && 
			( jikokuToueki != INT_MIN  ) )
		{
			//�u�ʉ߉w�ŁA
			//���������������̂����ꂩ���w�肳��Ă���v 
			*piRessyasenSyuutenEkiOrder = iEkiOrder ;
			return 	1 ;	//	�w��Ԑ��I�_�wOrder�x�̕␳���s���܂����B
		}


	}
	return 0 ;
}


int CentDedDgrRessya::updateRessyasenCont_05_adjustRessyasenSyuuten5( 
		int* piRessyasenSyuutenEkiOrder ) 
{
	int iRv = 0 ;
	CentDedDgrRessyasen aCentDedDgrRessyasen 
		= m_pCentDedDgrRessyasenCont->get( INT_MAX ) ;

	for ( int iEkiOrder = *piRessyasenSyuutenEkiOrder - 1 ;
		iRv==0 && iEkiOrder > aCentDedDgrRessyasen.getRessyasenKitenEkiOrder();
		iEkiOrder -- )
	{
		CentDedDgrEkiJikoku	aEkiJikoku = m_MuCentDedDgrEkiJikoku.get( 
			iEkiOrder ) ;

		//��Ԑ��̈ʒu(CentDedDgrEkiJikoku::m_iDgrXPosRessyasen)��
		//�������E������(CentDedDgrEkiJikoku::m_iDgrXPosChaku,m_iDgrXPosHatsu)��
		//����60 �b�ȏ゠��
		//�ꍇ�́A���̉w���w��Ԑ��I�_�wOrder�x�Ƃ��܂��B
		int iDgrXPosChakuHatsu = aEkiJikoku.getDgrXPosHatsu( true ) ;
		int iDgrXPosRessyasen = aEkiJikoku.getDgrXPosRessyasen() ;
		if ( iDgrXPosChakuHatsu != INT_MIN && 
			abs( iDgrXPosChakuHatsu - iDgrXPosRessyasen ) >= 60 )
		{
			*piRessyasenSyuutenEkiOrder = iEkiOrder ;
			iRv = 1 ;	//	�w��Ԑ��I�_�wOrder�x�̕␳���s���܂����B
		}
	}
	return iRv ;
}



int CentDedDgrRessya::updateRessyasenCont_06_reduceToKeiyunasi( 
		int* piRessyasenSyuutenEkiOrder ) 
{
	int iRv = 0 ;
	CentDedDgrRessyasen aCentDedDgrRessyasen = m_pCentDedDgrRessyasenCont->get(
		INT_MAX ) ;
	// --------------------------------
	//	��Ԑ����Ɋ܂܂��A
	//	�o�R�Ȃ��̎n�_�ƏI�_������
	// --------------------------------
	int iEkiOrderBeforeKeiyunasi = INT_MIN ;
	int iEkiOrderAfterKeiyunasi = INT_MIN ;
	for ( int iEkiOrder = aCentDedDgrRessyasen.getRessyasenKitenEkiOrder()+1 ;
		iEkiOrderBeforeKeiyunasi == INT_MIN 
			&& iEkiOrder < *piRessyasenSyuutenEkiOrder ;
		iEkiOrder ++ )
	{
		CentDedDgrEkiJikoku	aEkiJikokuNext = m_MuCentDedDgrEkiJikoku.get( 
			iEkiOrder + 1 ) ;

		if ( aEkiJikokuNext.getEkiatsukai() 
			== CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
		{
			iEkiOrderBeforeKeiyunasi = iEkiOrder ;
		}
	}
	if ( iEkiOrderBeforeKeiyunasi != INT_MIN )
	{
		int iEkiOrder = 0 ;
		for ( iEkiOrder = iEkiOrderBeforeKeiyunasi + 1 ;
			iEkiOrderAfterKeiyunasi == INT_MIN 
				&& iEkiOrder < *piRessyasenSyuutenEkiOrder ;
			iEkiOrder ++ )
		{
			CentDedDgrEkiJikoku	aEkiJikoku = m_MuCentDedDgrEkiJikoku.get( 
				iEkiOrder ) ;

			//�w�����w�o�R�Ȃ��x�̏I�[�n�_��T���܂��B
			if ( aEkiJikoku.getEkiatsukai() 
				!= CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
			{
				iEkiOrderAfterKeiyunasi = iEkiOrder ;
			}
		}
		//iEkiOrderAfterKeiyunasi = iEkiOrderBeforeKeiyunasi �Ȍ�ōŏ���
		//	�u�w�����w�o�R�Ȃ��x�ȊO�̉w�v�̉wOrder�B
		//	�A���A���ꂪ�u��Ԑ��I�_�wOrder�̏ꍇ�v�́AINT_MIN�ƂȂ�܂��B
	}

	//iEkiOrderBeforeKeiyunasi = �w�o�R�Ȃ��x���O�̉wOrder
	//iEkiOrderAfterKeiyunasi = �w�o�R�Ȃ��x����̉wOrder
	//	�A���A�u�w�o�R�Ȃ��x����̉wOrder�v��
	//	�u��Ԑ��I�_�wOrder�̏ꍇ�v�́AINT_MIN�ƂȂ�܂��B

	if ( iEkiOrderBeforeKeiyunasi != INT_MIN ) 
	{
		//	�w�o�R�Ȃ��x���O�̉wOrder��
		//	�����������A��Ԑ���̎����ɕύX���܂�
		CentDedDgrEkiJikoku aCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.get( iEkiOrderBeforeKeiyunasi ) ;
		aCentDedDgrEkiJikoku.setDgrXPosChaku( 
			aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ;
		aCentDedDgrEkiJikoku.setDgrXPosHatsu( 
			aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ;
		m_MuCentDedDgrEkiJikoku.set( 
			aCentDedDgrEkiJikoku , iEkiOrderBeforeKeiyunasi ) ;

		if ( iEkiOrderAfterKeiyunasi != INT_MIN )
		{
			//	�w�o�R�Ȃ��x����̉wOrder��
			//	�����������A��Ԑ���̎����ɕύX���܂�
			CentDedDgrEkiJikoku aCentDedDgrEkiJikoku = 
				m_MuCentDedDgrEkiJikoku.get( iEkiOrderAfterKeiyunasi ) ;
			aCentDedDgrEkiJikoku.setDgrXPosChaku( 
				aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ;
			aCentDedDgrEkiJikoku.setDgrXPosHatsu( 
				aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ;
			m_MuCentDedDgrEkiJikoku.set( 
				aCentDedDgrEkiJikoku , iEkiOrderAfterKeiyunasi ) ;
		}

		//	�����̗�Ԑ���u�������܂��B
		m_pCentDedDgrRessyasenCont->erase( INT_MAX ) ;
		aCentDedDgrRessyasen.setSyuuten( iEkiOrderBeforeKeiyunasi ) ;
		m_pCentDedDgrRessyasenCont->insert( aCentDedDgrRessyasen ) ;

		//�w�����w�o�R�Ȃ��x�̉w����������ꍇ�́A
		//���̒��O���w��Ԑ��I�_�wOrder�x�Ƃ��܂��B
		*piRessyasenSyuutenEkiOrder = iEkiOrderBeforeKeiyunasi ;

		iRv = 1 ;
	}
	return iRv ;
}

// --------------------------------
//@name �����֐�
// --------------------------------



// ********************************
//	�R���X�g���N�^
// ********************************
CentDedDgrRessya::CentDedDgrRessya( 
		const CentDedRosen* pCentDedRosen ,
		const CentDedDgrDia* pCentDedDgrDia ,
		const CentDedRessya* pCentDedRessya ) 
	: m_bIsNull( true ) 
	, m_eRessyahoukou( pCentDedRessya->getRessyahoukou() ) 
	, m_iRessyasyubetsuIndex( 0 )
	, m_pCentDedDgrDia( pCentDedDgrDia ) 
	, m_pCentDedDgrRessyasenCont( NULL ) 
{
	m_pCentDedDgrRessyasenCont = new CentDedDgrRessyasenCont(
		this ) ;

	readCentDedRessya( pCentDedRosen ,
		pCentDedDgrDia ,
		pCentDedRessya ) ; 

}
	
CentDedDgrRessya::CentDedDgrRessya( 
	const CentDedDgrDia* pCentDedDgrDia )
	: m_bIsNull( true ) 
	, m_eRessyahoukou( Ressyahoukou_Kudari ) 
	, m_iRessyasyubetsuIndex( 0 )
	, m_pCentDedDgrDia( pCentDedDgrDia ) 
	, m_pCentDedDgrRessyasenCont( NULL ) 
{
	m_pCentDedDgrRessyasenCont = new CentDedDgrRessyasenCont(
		this ) ;
}

CentDedDgrRessya::CentDedDgrRessya( const CentDedDgrRessya& value )
	: m_bIsNull( value.m_bIsNull ) 
	, m_eRessyahoukou( value.m_eRessyahoukou ) 
	, m_iRessyasyubetsuIndex( value.m_iRessyasyubetsuIndex )
	, m_strRessyabangou( value.m_strRessyabangou ) 
	, m_strRessyamei( value.m_strRessyamei ) 
	, m_strGousuu( value.m_strGousuu ) 
	, m_DgrXZone( value.m_DgrXZone ) 
	, m_pCentDedDgrDia( value.m_pCentDedDgrDia ) 
	, m_MuCentDedDgrEkiJikoku( value.m_MuCentDedDgrEkiJikoku )
	, m_pCentDedDgrRessyasenCont( NULL ) 
{
	m_pCentDedDgrRessyasenCont = new CentDedDgrRessyasenCont(
		this ) ;

	*m_pCentDedDgrRessyasenCont = *value.m_pCentDedDgrRessyasenCont ;
}


CentDedDgrRessya& CentDedDgrRessya::operator=( const CentDedDgrRessya& value )
{
	m_bIsNull = value.m_bIsNull ;
	m_eRessyahoukou = value.m_eRessyahoukou ;
	m_iRessyasyubetsuIndex = value.m_iRessyasyubetsuIndex ;
	m_strRessyabangou = value.m_strRessyabangou ;
	m_strRessyamei = value.m_strRessyamei ;
	m_strGousuu = value.m_strGousuu ;
	m_DgrXZone = value.m_DgrXZone ;
	m_MuCentDedDgrEkiJikoku = value.m_MuCentDedDgrEkiJikoku ;
	*m_pCentDedDgrRessyasenCont = *value.m_pCentDedDgrRessyasenCont ;

	return *this ;
}

CentDedDgrRessya::~CentDedDgrRessya() 
{
	delete m_pCentDedDgrRessyasenCont ;	m_pCentDedDgrRessyasenCont = NULL ;
}
	
// ********************************
//	CentDedDgrRessya
// ********************************
	// ********************************
	//@name ����
	// ********************************
bool CentDedDgrRessya::getIsNull()const
{
	return m_bIsNull ;
}
ERessyahoukou	CentDedDgrRessya::getRessyahoukou()const 
{
	return m_eRessyahoukou ;
}
CentDedDgrRessya& CentDedDgrRessya::setRessyahoukou( ERessyahoukou value ) 
{
	m_eRessyahoukou = value ;
	return *this ;
}

int	CentDedDgrRessya::getRessyasyubetsuIndex()const
{
	return m_iRessyasyubetsuIndex ;
};
void CentDedDgrRessya::setRessyasyubetsuIndex( int value )
{
	m_iRessyasyubetsuIndex = value ; 
};


string CentDedDgrRessya::getRessyabangou()const
{
		return m_strRessyabangou ;
};
CentDedDgrRessya& CentDedDgrRessya::setRessyabangou( const string& value )
{
		m_bIsNull = false ;
		m_strRessyabangou = value ; 
		return *this ; 
} ;
string CentDedDgrRessya::getRessyamei()const
{
		return m_strRessyamei ;
};
CentDedDgrRessya& CentDedDgrRessya::setRessyamei( const string& value )
{
		m_bIsNull = false ;
		 m_strRessyamei = value ; 
		return *this ; 
} ;
string CentDedDgrRessya::getGousuu()const
{
		return m_strGousuu ;
};
CentDedDgrRessya& CentDedDgrRessya::setGousuu( const string& value )
{
		m_bIsNull = false ;
		 m_strGousuu = value ; 
		return *this ; 
} ;
CdDcdZone	CentDedDgrRessya::getDgrXZone()const
{
	return m_DgrXZone ;
};

	// ********************************
	//@name ���
	// ********************************
Mu< CentDedDgrEkiJikoku* >* 
CentDedDgrRessya::getMuCentDedDgrEkiJikoku() 
{
	return m_MuCentDedDgrEkiJikoku.getMuPtr() ;
}
const Mu< const CentDedDgrEkiJikoku* >* 
CentDedDgrRessya::getMuCentDedDgrEkiJikoku()const 
{
	return m_MuCentDedDgrEkiJikoku.getMuPtr() ;
}

Mu< CentDedDgrRessyasen* >* CentDedDgrRessya::
	getCentDedDgrRessyasenCont()
{
	return m_pCentDedDgrRessyasenCont->getMuPtr() ;
}
const Mu< const CentDedDgrRessyasen* >* CentDedDgrRessya::
	getCentDedDgrRessyasenCont()const 
{
	return ((const CentDedDgrRessyasenCont*)m_pCentDedDgrRessyasenCont)->getMuPtr() ;
}


	// ********************************
	//@name ����
	// ********************************
void CentDedDgrRessya::clear()
{
	m_bIsNull = NULL ;
	m_eRessyahoukou = Ressyahoukou_Kudari ;
	m_iRessyasyubetsuIndex = 0 ;
	m_strRessyabangou.erase() ;
	m_strRessyamei.erase() ;
	m_strGousuu.erase() ;
	m_DgrXZone.setPos( 0 ).setSize( 0 ) ;
	m_MuCentDedDgrEkiJikoku.erase( 0 , INT_MAX ) ;
	m_pCentDedDgrRessyasenCont->erase( 0 , INT_MAX ) ;
}
int CentDedDgrRessya::readCentDedRessya(
		const CentDedRosen* pCentDedRosen ,
		const CentDedDgrDia* pCentDedDgrDia ,
		const CentDedRessya* pCentDedRessya ) 
{
	int iRv = 0 ;
	//	��܂���I�u�W�F�N�g��S�ăN���A���ANULL��Ԃɂ��܂�
	clear() ;

	//(01)CentDedDgrRessya�̑����̂����ACentDedRessya �݂̂Ō��肷�鑮����ݒ�
	readCentDedRessya_01_readProp( pCentDedRessya ) ;

	//(02)CentDedDgrEkiJikoku �𐶐����A CentDedEkiJikoku �Ō��܂鑮��������B
	readCentDedRessya_02_CreateCentDedEkiJikoku( pCentDedRessya ) ;

	//(03)CentDedDgrRessya�̈ȉ��̑������ACentDedDgrEkiJikoku�̑�����
	//	���Ƃɐ����B
	//	CdDcdZone	m_zoneDgrXZahyou
	readCentDedRessya_03_updateDgrXZone() ;

	//(04)CentDedDgrEkijikoku�̈ȉ��̑������ACentDedDgrEki �̑��������ƂɌ���B
	//	m_bShouldRessyajouhouDraw //��ԏ������̉w�̏ꏊ�ɕ`�悷��Ȃ�^�ł��B
	readCentDedRessya_04_updateShouldRessyajouhouDraw(
		pCentDedDgrDia->getCentDedDgrEkiCont()->getMuPtr( m_eRessyahoukou ) ) ;

	//	(05)�o�R�Ȃ��̑O��̒���������₤
	readCentDedRessya_05_complementKeiyunasiSide() ; 

	//	(06_01)�����Ԓ�Ԃ�����
	//		(�����Ԓ�Ԃ̒�����=�Ȃ��E������=���� �̉w�ɁA��������₤)
	readCentDedRessya_06_complementLongStop_01( 
		pCentDedDgrDia->getCentDedDgrEkiCont()->getMuPtr( m_eRessyahoukou ) ) ;

	//	(06_02)�����Ԓ�Ԃ�����
	//		(�����Ԓ�Ԃ̒�����=����E������=�Ȃ� �̉w�ɁA��������₤)
	readCentDedRessya_06_complementLongStop_02( 
		pCentDedDgrDia->getCentDedDgrEkiCont()->getMuPtr( m_eRessyahoukou ) ) ;

	//(08)CentDedDgrRessyasen�̃R���e�i�𐶐����A
	//  CentDedDgrEkijikoku::m_iDgrXPosOnRessyasen
	//���C��
	readCentDedRessya_08_updateRessyasenCont( 
		pCentDedDgrDia->getCentDedDgrEkiCont()->getMuPtr( m_eRessyahoukou ) ) ;
	
	return ( iRv ) ;
}

int CentDedDgrRessya::getSihatsuEki()const 
{
	int	iRv = -1 ;
	// --------------------------------
	int iEkiOrder = 0 ;
	for ( iEkiOrder = 0 ; 
			iRv == -1 && 
			iEkiOrder < (int)m_MuCentDedDgrEkiJikoku.size() ; 
			iEkiOrder ++ )
	{
		const CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;
		if ( pCentDedDgrEkiJikoku->getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None )
		{
			iRv = iEkiOrder ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

int CentDedDgrRessya::getSyuuchakuEki()const 
{
	int	iRv = -1 ;
	// --------------------------------
	int iEkiOrder = 0 ;
	for ( iEkiOrder = (int)m_MuCentDedDgrEkiJikoku.size() - 1 ; 
			iRv == -1 && 
			iEkiOrder >= 0 ; 
			iEkiOrder -- )
	{
		const CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = 
			m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;
		if ( pCentDedDgrEkiJikoku->getEkiatsukai() != 
				CentDedEkiJikoku::Ekiatsukai_None )
		{
			iRv = iEkiOrder ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}

bool CentDedDgrRessya::isRunBetweenNextEki( int iEkiOrder )const 
{
	bool bRv = false ;
	if ( !( 0 <= iEkiOrder && iEkiOrder < (int)m_MuCentDedDgrEkiJikoku.size() - 1 ) )
	{
		bRv = false ;	//	�w�wIndex�x���s���ł��B
	}
	else
	{
		const CentDedDgrEkiJikoku* pEkijikoku 
			= m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder ) ;
		const CentDedDgrEkiJikoku* pEkijikokuNext 
			= m_MuCentDedDgrEkiJikoku.getMuPtr()->get( iEkiOrder + 1 ) ;
		if ( 
			( pEkijikoku->getEkiatsukai()
					==CentDedEkiJikoku::Ekiatsukai_Teisya
				|| pEkijikoku->getEkiatsukai() 
					== CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
			&& ( pEkijikokuNext->getEkiatsukai() 
					== CentDedEkiJikoku::Ekiatsukai_Teisya 
				|| pEkijikokuNext->getEkiatsukai() 
					== CentDedEkiJikoku::Ekiatsukai_Tsuuka ) 
		)
		{
			bRv = true ;
		}

	}
	return bRv ;
}

int CentDedDgrRessya::calcEkikanSaisyouSec(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iEkiOrderBefore ,
		int iEkiOrderAfter )const 
{
	int iRv = 0 ;
	for ( int iEkiOrder = iEkiOrderBefore ;
		iEkiOrder < iEkiOrderAfter ;
		iEkiOrder ++ )
	{
		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki = 
				pMuCdDedDgrEki->get( iEkiOrder ) ;
			iRv += aCdDedDgrEki.getEkikanSaisyouSec() ;
		}
	}
	return iRv ;
}

int CentDedDgrRessya::calcDgrYEkikanSize(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iEkiOrderBefore ,
		int iEkiOrderAfter )const 
{
	int iRv = 0 ;
	for ( int iEkiOrder = iEkiOrderBefore ;
		iEkiOrder < iEkiOrderAfter ;
		iEkiOrder ++ )
	{
		if ( isRunBetweenNextEki( iEkiOrder ) )
		{
			CentDedDgrEkiCont::CdDedDgrEki	aCdDedDgrEki = 
				pMuCdDedDgrEki->get( iEkiOrder ) ;
			iRv += aCdDedDgrEki.getDgrYSizeEkikan() ;
		}
	}
	return iRv ;
}


void CentDedDgrRessya::modifyDgrXPos( int iSeconds ) 
{
	int idx ;
	for ( idx = 0 ; idx < m_MuCentDedDgrEkiJikoku.size() ; idx ++ )
	{
		CentDedDgrEkiJikoku	aCentDedDgrEkiJikoku 
			= m_MuCentDedDgrEkiJikoku.get( idx ) ;
		aCentDedDgrEkiJikoku.modifyDgrXPos( iSeconds ) ;
		m_MuCentDedDgrEkiJikoku.set( aCentDedDgrEkiJikoku , idx ) ;
	}
	{
		m_DgrXZone.setPos( m_DgrXZone.getPos() + iSeconds ) ;
	}
}

int CentDedDgrRessya::getDgrXPosOfJikokuOrder(
		CdDedJikokuOrder aCdDedJikokuOrder , 
		int* piDgrXPos )const 
{
	int iRv = 0 ;
	int iDgrXPos = INT_MIN ;

	const Mu<const CentDedDgrEkiJikoku*>* muCentDedDgrEkiJikoku = this->getMuCentDedDgrEkiJikoku() ;

	const CentDedDgrEkiJikoku*	pCentDedDgrEkiJikoku = muCentDedDgrEkiJikoku->get( aCdDedJikokuOrder.getEkiOrder() ) ;
	if ( !( pCentDedDgrEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya || 
		pCentDedDgrEkiJikoku->getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka ) )
	{
		iRv = -1 ;	//	���̉w�̍��W���擾�ł��܂���B
	}
	else if ( pCentDedDgrEkiJikoku->getDgrXPosRessyasen() != INT_MIN )
	{
		//	���̉w�ɗ�Ԑ�X���W������(��Ԑ��̓r��)�Ȃ�A
		//	����X���W���̗p
		iDgrXPos = pCentDedDgrEkiJikoku->getDgrXPosRessyasen() ;
	}
	else if ( aCdDedJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku)
	{
		//	�w��̉w����Order��������
		//	�������̍��W���擾(�Ȃ���Δ�)
		iDgrXPos = pCentDedDgrEkiJikoku->getDgrXPosChaku( true ) ;
		if ( iDgrXPos == INT_MIN )
		{
			iRv = -1 ;	//	���̉w�̍��W���擾�ł��܂���B
		}
	}
	else
	{
		//	�w��̉w����Order��������
		//	�������̍��W���擾(�Ȃ���Β�)
		iDgrXPos = pCentDedDgrEkiJikoku->getDgrXPosHatsu( true ) ;
		if ( iDgrXPos == INT_MIN )
		{
			iRv = -1 ;	//	���̉w�̍��W���擾�ł��܂���B
		}
	}
	// --------------------------------
	if ( piDgrXPos != NULL )
	{
		*piDgrXPos = iDgrXPos ;
	}
	return iRv ;
}


int CentDedDgrRessya::getDgrXPosOfEkiOrder(
		int iEkiOrder , 
		int* piDgrXPos )const 
{
	int iDgrXPos = 0 ;
	int iRv = -1 ;
	if ( iRv == -1 )
	{
		iRv = this->getDgrXPosOfJikokuOrder( 
			CdDedJikokuOrder( iEkiOrder , CdDedJikokuOrder::EkiJikokuItem_Hatsu )  , 
			&iDgrXPos ) ;

	}
	if ( iRv == -1 )
	{
		//	�wOrder�̒������̍��W���擾
		iRv = this->getDgrXPosOfJikokuOrder( 
			CdDedJikokuOrder( iEkiOrder , CdDedJikokuOrder::EkiJikokuItem_Chaku ) , 
			&iDgrXPos ) ;

	}
	// --------------------------------
	if ( piDgrXPos != NULL ){
		*piDgrXPos = iDgrXPos ;
	}
	return ( iRv ) ;

	// ----------------------------------------------------------------
}

} //namespace entDgr
