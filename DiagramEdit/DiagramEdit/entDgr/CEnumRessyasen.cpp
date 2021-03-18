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
//	CEnumRessyasen.cpp
// $Id: CEnumRessyasen.cpp 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
*/
#include "stdafx.h"
#include "CEnumRessyasen.h"

namespace entDgr{
	
// ****************************************************************
//	CEnumRessyasen
// ****************************************************************
	//*******************************
	//	�R���X�g���N�^
	//*******************************
CEnumRessyasen::CEnumRessyasen( 
		const CentDedDgrDia* pCentDedDgrDia ,
		const CdDcdZoneXy& zonexyDgrZone ,
		bool bDisplayRessyasenKudari ,
		bool bDisplayRessyasenNobori ) :
	m_pCentDedDgrDia( pCentDedDgrDia ) ,
	m_zonexyDgrZone( zonexyDgrZone ) ,
	m_bDisplayRessyasenKudari( bDisplayRessyasenKudari ) ,
	m_bDisplayRessyasenNobori( bDisplayRessyasenNobori )
{
}
CEnumRessyasen::~CEnumRessyasen() 
{
}

	// --------------------------------
	//@name CEnumRessyasen
	// --------------------------------
void CEnumRessyasen::onCentDedDgrRessya( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ) 
{
	//	�ΏۂƂȂ�`��̈���A
	//	�w�_�C���O�����G���e�B�e�B���W�n�x�ŕێ����܂��B
	//	����́A����`����s���͈͂�\���Ă��܂��B
	CdDcdZoneXy	zonexyDgrZone = m_zonexyDgrZone ;

	const Mu<const CentDedDgrRessyasen*>* pMuCentDedDgrRessyasen = 
		pCentDedDgrRessya->getCentDedDgrRessyasenCont() ;
	for ( int iRessyasenIdx = 0 ; 
			iRessyasenIdx < pMuCentDedDgrRessyasen->size() ;
			iRessyasenIdx ++ )
	{
		// --------------------------------
		//	��Ԑ����̏���
		// --------------------------------
		const CentDedDgrRessyasen*	pCentDedDgrRessyasen = 	
			pMuCentDedDgrRessyasen->get( iRessyasenIdx ) ;
		// --------------------------------
		//	��Ԑ����͂ދ�`�̈�����߂�
		// --------------------------------
		CdDcdZoneXy	zonexyDgrRessyasen ;
		CdDcdPosXy	posRessyasenKiten ;
		CdDcdPosXy	posRessyasenSyuuten ; 
		{
			posRessyasenKiten = 
				m_pCentDedDgrDia->calcDgrPosRessyasenKiten( 
				pCentDedDgrRessya , pCentDedDgrRessyasen ) ;
			posRessyasenSyuuten = 
				m_pCentDedDgrDia->calcDgrPosRessyasenSyuuten( 
				pCentDedDgrRessya , pCentDedDgrRessyasen ) ;

			CdDcdZone	zoneDgrX ;
			zoneDgrX.setBeginEndPos( 
				posRessyasenKiten.getX() , 
				posRessyasenSyuuten.getX() ) ;
			CdDcdZone	zoneDgrY ;
			zoneDgrY.setBeginEndPos( 
				posRessyasenKiten.getY() ,
				posRessyasenSyuuten.getY() ) ;

			if ( !( zoneDgrX.getSize() == 0 && zoneDgrY.getSize() == 0 ) )
			{
				if ( zoneDgrX.getSize() == 0 )
				{
					//	�n�_�ƏI�_��X���W������̏ꍇ(������)�́A��O�I�ɕ���1�Ƃ��܂�
					//	(0�Ƃ��Ă��܂��ƁA�����`�悳��܂���)
					zoneDgrX.setSize( 1 ) ;
				}
				if ( zoneDgrY.getSize() == 0 )
				{
					//	�n�_�ƏI�_��Y���W������̏ꍇ(������)�́A��O�I�ɕ���1�Ƃ��܂�
					//	(0�Ƃ��Ă��܂��ƁA�����`�悳��܂���)
					zoneDgrY.setSize( 1 ) ;
				}
			}

			zonexyDgrRessyasen.setX( zoneDgrX ).setY( zoneDgrY ) ;

		}


		CdDcdZoneXy	zonexyDgrRessyasenOnDgrZone = zonexyDgrZone.CrossZone( zonexyDgrRessyasen ) ;
		//zonexyDgrRessyasenOnDgrZone
		//	��Ԑ��ƕ`��̈�́A�����̈�
		//	���̒l�̃T�C�Y��0�Ȃ�A���̗�Ԑ��͕`��\�ȗ̈�ɂ͂���܂���B

		if ( zonexyDgrRessyasenOnDgrZone.getX().getSize() > 0 && 
			zonexyDgrRessyasenOnDgrZone.getY().getSize() > 0 )
		{
			//	���̗�Ԑ��́A�`��\�ȉw�Ԃɂ���܂��B
			onCentDedDgrRessyasen( 
				eRessyahoukou ,
				iRessyaIdx ,
				pCentDedDgrRessya ,
				iRessyasenIdx ,
				pCentDedDgrRessyasen ) ;
		}
	}
}

void CEnumRessyasen::onCentDedDgrRessyasen( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ) 
{
	int iEkiOrderRessyasenKiten = pCentDedDgrRessyasen->getRessyasenKitenEkiOrder() ;
	int iEkiOrderRessyasenSyuuten = pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() ;

	const Mu<const CentDedDgrEkiJikoku*>* pMuCentDedDgrEkiJikoku = 
		pCentDedDgrRessya->getMuCentDedDgrEkiJikoku() ;
	


	for ( int iEkiOrder = iEkiOrderRessyasenKiten ;
		iEkiOrder <= iEkiOrderRessyasenSyuuten ;
		iEkiOrder ++ )
	{
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku = 
			pCentDedDgrRessya->getMuCentDedDgrEkiJikoku()->get( iEkiOrder ) ;
		onCentDedDgrEkiJikoku( 
			eRessyahoukou , 
			iRessyaIdx , 
			pCentDedDgrRessya ,
			iRessyasenIdx ,
			pCentDedDgrRessyasen ,
			iEkiOrder ,
			pCentDedDgrEkiJikoku ) ;
	}


}
void CEnumRessyasen::onCentDedDgrEkiJikoku( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ,
		int iEkiOrder , 
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku ) 
{
}

	// ********************************
	//@name CEnumRessyasen-�֘A
	// ********************************
const CentDedDgrDia*	CEnumRessyasen::getCentDedDgrDia()
{	
		return m_pCentDedDgrDia ; 
} ;
	// ********************************
	//@name CEnumRessyasen-����
	// ********************************
CdDcdZoneXy	CEnumRessyasen::getDgrZone()
{
	return m_zonexyDgrZone ;
};

bool CEnumRessyasen::getDisplayRessyasen(  ERessyahoukou eRessyahoukou )const 
{
	bool bRv = false ;
	if ( eRessyahoukou == Ressyahoukou_Kudari ){
		bRv = m_bDisplayRessyasenKudari ;
	}	else if ( eRessyahoukou == Ressyahoukou_Nobori ) {
		bRv = m_bDisplayRessyasenNobori ;
	}
	return ( bRv ) ;
}
	// ********************************
	//@name CEnumRessyasen-����
	// ********************************
void CEnumRessyasen::execute() 
{
	//	�ΏۂƂȂ�`��̈���A
	//	�w�_�C���O�����G���e�B�e�B���W�n�x�ŕێ����܂��B
	//	����́A����`����s���͈͂�\���Ă��܂��B
	CdDcdZoneXy	zonexyDgrZone = m_zonexyDgrZone ;


	for ( int iRessyahoukou = Ressyahoukou_Kudari ;
		iRessyahoukou <= Ressyahoukou_Nobori ;
		iRessyahoukou ++ )
	{
		// --------------------------------
		//	��ԕ����̏��������s���邩�ۂ��̔���
		// --------------------------------
		ERessyahoukou	eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
		if ( !getDisplayRessyasen( eRessyahoukou ) ) 
		{
			//	���̕����̏����͍s���܂���B
			continue ;
		}
		// --------------------------------
		//	��ԕ������̏���
		// --------------------------------
		const Mu<const CentDedDgrRessya*>*	pMuCentDedDgrRessya = 
			m_pCentDedDgrDia->getCentDedDgrRessyaCont( eRessyahoukou );
		for ( int iRessyaIdx = 0 ; 
				iRessyaIdx < pMuCentDedDgrRessya->size() ;
				 iRessyaIdx ++ )
		{
			// --------------------------------
			//	��Ԗ��̏���
			// --------------------------------
			const CentDedDgrRessya* pCentDedDgrRessya = 
				pMuCentDedDgrRessya->get( iRessyaIdx ) ;
			if ( pCentDedDgrRessya->getIsNull() || 
				pCentDedDgrRessya->getCentDedDgrRessyasenCont()->size() <= 0 )
			{
				//	NULL��ԁE��Ԑ��̑S���Ȃ���Ԃ͑ΏۊO
				continue ;
			}
			// --------------------------------

			CentDedDgrRessya	aCentDedDgrRessya( *pCentDedDgrRessya ) ;
			//	��Ԃ̍ő��DgrX���W���_�C���O������
			//	���[��DgrX���W�ɂȂ�܂ŁA
			//	��ԑS�̂�DgrX���W��24���Ԃ����Z����B
			//
			//	���̏����́A��Ԃ��_�C���O�������[��
			//	�ׂ��ł���ꍇ�ɁA�K�v�ł��B
			//	���Ƃ��΁A�_�C���O�����̍��[�� 00:00:00
			//	�ɂȂ��Ă���_�C���̏ꍇ�A
			//	23:00 ���� 01:00 �Ɍ������đ����Ă����Ԃ�
			//	-01:00��01:00 
			//	 23:00��25:00
			//	�̂Q�ӏ��ɗ�Ԑ���`�悵�Ȃ��Ă͂Ȃ�܂���B
			//	���̃��[�v�ł́A��U��Ԃ̎�����
			//	-25:00��-23:00 
			//	�ɂ��܂��B
			while ( !( aCentDedDgrRessya.getDgrXZone().getEndPos() < 
				zonexyDgrZone.getX().getPos() ) )
			{
				aCentDedDgrRessya.modifyDgrXPos( - CdDedJikoku::TOTALSECONDS_A_DAY ) ;
			}

			//	�����ŁA24���ԉ��Z���܂��B����ɂ��A��Ԏ�����
			//	-01:00��01:00 
			//	�ƂȂ�܂��B
			aCentDedDgrRessya.modifyDgrXPos( + CdDedJikoku::TOTALSECONDS_A_DAY ) ;

			
			for ( ; aCentDedDgrRessya.getDgrXZone().getPos() < 
					zonexyDgrZone.getX().getEndPos() ;
				aCentDedDgrRessya.modifyDgrXPos( + CdDedJikoku::TOTALSECONDS_A_DAY ) )
			{
				// --------------------------------
				//	��Ԃ̕\���ʒu�i�Q�S���ԊԊu�j���̏���
				// --------------------------------
				CdDcdZone	zoneDgrXCross = zonexyDgrZone.getX().CrossZone(
					aCentDedDgrRessya.getDgrXZone() ) ;
				if ( zoneDgrXCross.getSize() > 0 )
				{
					//	���̗�Ԃ́A�ΏۂƂȂ�`��̈���ɂ���܂��B
					onCentDedDgrRessya( 
						eRessyahoukou ,
						iRessyaIdx ,
						&aCentDedDgrRessya ) ;
				}
			}
		}
	}
};

} //namespace entDgr
