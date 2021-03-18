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
//	CentDedDgrDia.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include "CentDedDgrEki.h"
#include "CentDedDgrRessya.h"
#include "CentDedDgrDia.h"
#include "DcdCd\Pos\CLineFunc.h"
#include "logmsg/LogMsg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


namespace entDgr{
using namespace std ;

// ****************************************************************
//	CentDedDgrDia
// ****************************************************************
// --------------------------------
//@name readCentDedRosen() �̉����֐�
// --------------------------------
CentDedDgrEki::EDiagramRessyajouhouHyouji 
CentDedDgrDia::CentDedEki_to_CentDedDgrEki_EDiagramRessyajouhouHyouji( 
	CentDedEki::EDiagramRessyajouhouHyouji eValue )
{
	CentDedDgrEki::EDiagramRessyajouhouHyouji eRessyajouhouHyouji = 
		CentDedDgrEki::DiagramRessyajouhouHyouji_Origin ;
	switch( eValue )
	{
	case CentDedEki::DiagramRessyajouhouHyouji_Anytime:
		eRessyajouhouHyouji = CentDedDgrEki::DiagramRessyajouhouHyouji_Anytime ;
		break ;
	case CentDedEki::DiagramRessyajouhouHyouji_Not:
		eRessyajouhouHyouji = CentDedDgrEki::DiagramRessyajouhouHyouji_Not ;
		break ;
	}
	return eRessyajouhouHyouji ;
}

	/*
		readCentDedRosen() �̉����֐��ł��B
		(1)CentDedDgrDia�̑�����ݒ�
	*/
void CentDedDgrDia::readCentDedRosen_01_updateCentDedDgrDiaProp(
		const CentDedRosen* pCentDedRosen ,
		const CentDedDia* pCentDedDia ) 
{
	m_strName = pCentDedDia->getName() ;
	m_iDgrXPosMin = pCentDedRosen->getKitenJikoku().getTotalSeconds() ;
	m_iDgrYSizeEkikanDefault = pCentDedRosen->getDiagramDgrYZahyouKyoriDefault() ;
}

void CentDedDgrDia::readCentDedRosen_02_updateEkiCont( 
		const Mu< const CentDedEki* >* pCentDedEkiCont , 
		const CentDedDia* pCentDedDia ) 
{
	LogMsg( "CentDedDgrDia::readCentDedRosen_updateEkiCont()" ); 

	int iRv = 0 ;
	// --------------------------------
	//	����܂ł�
	//	�w�_�C���O�����w�x
	//	�w�_�C���O������ԁx
	//	�I�u�W�F�N�g�͔j�����܂��B
	// --------------------------------
	if ( iRv >= 0 )
	{
		m_CentDedDgrEkiCont.erase( 0 , INT_MAX ) ;
		m_CentDedDgrRessyaCont[0].erase( 0 , INT_MAX ) ;
		m_CentDedDgrRessyaCont[1].erase( 0 , INT_MAX ) ;
	}

	// --------------------------------
	//	�e�w�́w�_�C���O�����w�x
	//	�I�u�W�F�N�g�𐶐�
	// --------------------------------
	int iEkiIndex = 0 ;
	for ( iEkiIndex = 0 ; 
			iRv >= 0 && iEkiIndex < pCentDedEkiCont->size() ;
			iEkiIndex ++ )
	{
		LogMsg( "\tEkiIndex[%d]%s" ,
			iEkiIndex , 
			pCentDedEkiCont->get( iEkiIndex )->getEkimei().c_str() ) ;
		// --------------------------------
		//	�����Ԃ̌���(�I�_�͏���)
		// --------------------------------
		int iEkikanSaisyouSecKudari = 0 ;
		{
			const CentDedRessyaCont* pCentDedRessyaCont = 
					pCentDedDia->getCentDedRessyaCont( Ressyahoukou_Kudari ) ;
			int iEkiOrder = pCentDedRessyaCont->EkiOrderOfEkiIndex(	iEkiIndex ) ;
			if ( 0 <= iEkiOrder && iEkiOrder < pCentDedEkiCont->size() - 1 )
			{
				iEkikanSaisyouSecKudari = 
					pCentDedRessyaCont->findEkikanSaisyouSec( 
						iEkiOrder , NULL ) ;
			}
		}
		// --------------------------------
		//	����Ԃ̌���(�I�_�͏���)
		// --------------------------------
		int iEkikanSaisyouSecNobori = 0 ;

		{
			const CentDedRessyaCont* pCentDedRessyaCont = 
					pCentDedDia->getCentDedRessyaCont( Ressyahoukou_Nobori ) ;
			int iEkiOrder = pCentDedRessyaCont->EkiOrderOfEkiIndex(	iEkiIndex ) - 1 ;
			if ( 0 <= iEkiOrder && iEkiOrder < pCentDedEkiCont->size() - 1 )
			{
				iEkikanSaisyouSecNobori = 
					pCentDedRessyaCont->findEkikanSaisyouSec( 
						iEkiOrder , NULL ) ;
			}
		}

		// --------------------------------
		LogMsg( "\tiEkikanSaisyouSecKudari=%d iEkikanSaisyouSecNobori=%d" , 
			iEkikanSaisyouSecKudari , iEkikanSaisyouSecNobori ) ;

		const CentDedEki* pCentDedEki = pCentDedEkiCont->get( iEkiIndex ) ;

		CentDedDgrEki	aCentDedDgrEki( 
			pCentDedEki->getEkimei() , 
			pCentDedEki->getEkikibo() == 
				CentDedEki::Ekikibo_Syuyou , 
			iEkikanSaisyouSecKudari , iEkikanSaisyouSecNobori , 
			m_iDgrYSizeEkikanDefault ,
			CentDedEki_to_CentDedDgrEki_EDiagramRessyajouhouHyouji( 
				pCentDedEki->getDiagramRessyajouhouHyoujiKudari() ) , 
			CentDedEki_to_CentDedDgrEki_EDiagramRessyajouhouHyouji(
				pCentDedEki->getDiagramRessyajouhouHyoujiNobori() ) 
		) ;
		
		m_CentDedDgrEkiCont.insert( aCentDedDgrEki ) ;


	}

	
	LogMsg( "CentDedDgrDia::readCentDedRosen_updateEkiCont()="  )  ;
	
}

void CentDedDgrDia::readCentDedRosen_03_updateMuRessyasyubetsu( 
		const Mu< const CentDedRessyasyubetsu* >* pMuRessyasyubetsu ) 
{
	// --------------------------------
	//	�w��Ԏ�ʁx�I�u�W�F�N�g��j��
	// --------------------------------
	m_MuCentDedDgrRessyasyubetsu.erase( 0 , INT_MAX ) ;

	// --------------------------------
	//	�w��Ԏ�ʁx�I�u�W�F�N�g��
	//	����
	// --------------------------------
	for ( int idx = 0 ; idx < pMuRessyasyubetsu->size() ; idx ++ )
	{
		const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = 
			pMuRessyasyubetsu->get( idx ) ;
		CentDedDgrRessyasyubetsu	aCentDedDgrRessyasyubetsu( 
			pCentDedRessyasyubetsu->getJikokuhyouMojiColor() ,
			pCentDedRessyasyubetsu->getCdDiagramLineStyle() ,
			pCentDedRessyasyubetsu->getStopMarkDrawType() ) ;
		m_MuCentDedDgrRessyasyubetsu.insert( aCentDedDgrRessyasyubetsu ) ;
	}
}

void CentDedDgrDia::readCentDedRosen_04_updateRessyaCont( 
		const CentDedRosen* pCentDedRosen , 
		const CentDedDia* pCentDedDia ) 
{
	LogMsg( "CentDedDgrDia::readCentDedRosen_updateRessyaCont()" )  ;


	// --------------------------------
	//	�e��Ԃ́w�_�C���O������ԁx�I�u�W�F�N�g��
	//	����
	// --------------------------------
	for ( int iRessyahoukou = Ressyahoukou_Kudari ;
			iRessyahoukou <= Ressyahoukou_Nobori ; 
			iRessyahoukou ++ )
	
	{
		ERessyahoukou eRessyahoukou = (ERessyahoukou)iRessyahoukou ;
	
		const CentDedRessyaCont* pCentDedRessyaCont = 
			pCentDedDia->getCentDedRessyaCont( eRessyahoukou ) ;
		const Mu<const CentDedRessya*>* pCentDedRessyaContGet = 
			pCentDedDia->getCentDedRessyaCont( eRessyahoukou )->getMuPtr() ;

		Mui< CentDedDgrRessya >*	pCentDedDgrRessyaCont = 
			getCentDedDgrRessyaCont( eRessyahoukou ) ;
		
		// --------------------------------
		//	��Ԃ���U�N���A
		// --------------------------------
		pCentDedDgrRessyaCont->erase( 0 , INT_MAX );
		
		// --------------------------------
		//	��ԃI�u�W�F�N�g�𐶐��E�ǉ�
		// --------------------------------
		for ( int iRessyaIdx = 0 ; 
				iRessyaIdx < pCentDedRessyaContGet->size() ;
				iRessyaIdx ++ )
		{
			const CentDedRessya* pCentDedRessya = pCentDedRessyaContGet->get( iRessyaIdx ) ;
			CentDedDgrRessya	aCentDedDgrRessya( 
				pCentDedRosen , this , pCentDedRessya ) ;
							
			pCentDedDgrRessyaCont->insert( aCentDedDgrRessya ) ;
		}
		
	}

	LogMsg( "CentDedDgrDia::readCentDedRosen_updateRessyaCont()=" )  ;
}


// ********************************
//	�R���X�g���N�^
// ********************************
CentDedDgrDia::CentDedDgrDia() :
	m_iDgrXPosMin( 0 ) ,
	m_iDgrYSizeEkikanDefault( 60 )
{
}
CentDedDgrDia::~CentDedDgrDia() 
{
}
	
// ********************************
//	CentDedDgrDia
// ********************************


	// ********************************
	//@name ����
	// ********************************
string	CentDedDgrDia::getName()const
{
	return m_strName ;
};
int CentDedDgrDia::getDgrXPosMin()const 
{
	return m_iDgrXPosMin ;
}
CentDedDgrDia& CentDedDgrDia::setDgrXPosMin( int value ) 
{
	m_iDgrXPosMin = value ;
	return *this ; 
}

int CentDedDgrDia::getDgrYSizeEkikanDefault()const
{
	return m_iDgrYSizeEkikanDefault ;
};

	// ********************************
	//@name ���
	// ********************************
CentDedDgrEkiCont*	CentDedDgrDia::getCentDedDgrEkiCont()
{
	return &m_CentDedDgrEkiCont ;
}
const CentDedDgrEkiCont* CentDedDgrDia::getCentDedDgrEkiCont()const
{
	return &m_CentDedDgrEkiCont ;
}

Mui< CentDedDgrRessyasyubetsu >*	
CentDedDgrDia::getMuCentDedDgrRessyasyubetsu()
{
	return &m_MuCentDedDgrRessyasyubetsu ;
};

const Mu< const CentDedDgrRessyasyubetsu* >*
CentDedDgrDia::getMuCentDedDgrRessyasyubetsu()const
{
	return m_MuCentDedDgrRessyasyubetsu.getMuPtr() ;
};

Mui< CentDedDgrRessya >*	CentDedDgrDia::getCentDedDgrRessyaCont( 
		 ERessyahoukou eRessyahoukou ) 
{
	Mui< CentDedDgrRessya >*	pRv = NULL ;
	if ( eRessyahoukou == Ressyahoukou_Kudari ){
		pRv = &m_CentDedDgrRessyaCont[0] ;
	}	else	{
		pRv = &m_CentDedDgrRessyaCont[1] ;
	}
	return ( pRv ) ;
}


const Mu< const CentDedDgrRessya* >*	
	CentDedDgrDia::getCentDedDgrRessyaCont( 
		 ERessyahoukou eRessyahoukou )const 
{
	const Mu< const CentDedDgrRessya* >*	pRv = NULL ;
	if ( eRessyahoukou == Ressyahoukou_Kudari ){
		pRv = m_CentDedDgrRessyaCont[0].getMuPtr() ;
	}	else	{
		pRv = m_CentDedDgrRessyaCont[1].getMuPtr() ;
	}
	return ( pRv ) ;
}


	// ********************************
	//@name ����
	// ********************************
void CentDedDgrDia::readCentDedRosen( 
		const CentDedRosen* pCentDedRosen , 
		const CentDedDia* pCentDedDia ) 
{
	int iRv = 0 ;
	
	//	(1)CentDedDgrDia�̑�����ݒ�
	if ( iRv >= 0 )
	{
		readCentDedRosen_01_updateCentDedDgrDiaProp( 
			pCentDedRosen , 
			pCentDedDia ) ;
	}
	//(2)CentDedDgrEki�𐶐�
	//�@CentDedDgrEki�̈ȉ��̑������ACentDedEki�̑������琶���B
	if ( iRv >= 0 )
	{
		readCentDedRosen_02_updateEkiCont( 
			pCentDedRosen->getCentDedEkiCont()->getMuPtr() ,
			pCentDedDia ) ;
	}
	//	(3)CentDedDgrRessyasyubetsu�𐶐�
	if ( iRv >= 0 ) 
	{
		readCentDedRosen_03_updateMuRessyasyubetsu( 
			pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ) ;
	}
	//	(4)CentDedDgrRessya,CentDedDgrEkiJikoku�𐶐�
	if ( iRv >= 0 )
	{
		readCentDedRosen_04_updateRessyaCont( 
			pCentDedRosen , 
			pCentDedDia ) ;
	}
	
}

int CentDedDgrDia::EkiIndexOfEkiOrder( 
		ERessyahoukou eRessyahoukou , int iEkiOrder )const 
{
	int iEkiIndex = iEkiOrder ;
	if ( eRessyahoukou == Ressyahoukou_Nobori ){
		iEkiIndex = m_CentDedDgrEkiCont.size() - 1 - iEkiOrder ;
	}
	return ( iEkiIndex ) ;
}

int CentDedDgrDia::EkiOrderOfEkiIndex(  ERessyahoukou eRessyahoukou , 
		int iEkiIndex )const 
{
	int iEkiOrder = iEkiIndex ;
	if ( eRessyahoukou == Ressyahoukou_Nobori ){
		iEkiOrder = m_CentDedDgrEkiCont.size() - 1 - iEkiIndex ;
	}
	return ( iEkiOrder ) ;
}

CdDcdZoneXy	CentDedDgrDia::getZone()const 
{
	int iYSize = getDgrYPosOfEki( INT_MAX )  ;
	if ( iYSize < 0 ){
		iYSize = 0 ;
	}
	return ( CdDcdZoneXy( 
		CdDcdZone( m_iDgrXPosMin , CdDedJikoku::TOTALSECONDS_A_DAY ) ,
		CdDcdZone( 0 , iYSize )  ) ) ;
}



int CentDedDgrDia::getDgrYPosOfEki( int iEkiIndex )const 
{
	//todo:�w���̎d�l���ǉ����ꂽ��A�w���̘a�����Z����K�v������܂��B

	return getDgrYSizeEkikan( 
			Ressyahoukou_Kudari , 
			0 ,
			iEkiIndex ) ; 
}

int CentDedDgrDia::getDgrYPosOfEki( ERessyahoukou eRessyahoukou , 
		int iEkiOrder )const 
{
	return getDgrYPosOfEki( 
		EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrder ) ) ; 

}

int CentDedDgrDia::getDgrYSizeEkikan( 
			ERessyahoukou eRessyahoukou , 
			int iEkiOrderOrg ,
			int iEkiOrderDst )const 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iEkiOrderOrg == INT_MAX ){
		iEkiOrderOrg = m_CentDedDgrEkiCont.size() - 1 ;
	}
	if ( iEkiOrderDst == INT_MAX ){
		iEkiOrderDst = m_CentDedDgrEkiCont.size() - 1 ;
	}
	// --------------------------------
	if ( !( 0 <= iEkiOrderOrg && iEkiOrderOrg < m_CentDedDgrEkiCont.size() ) ){
		return ( -1 ) ;	//		�w�wOrder�x���s��
	}
	if ( !( 0 <= iEkiOrderDst && iEkiOrderDst < m_CentDedDgrEkiCont.size() ) ){
		return ( -1 ) ;	//		�w�wOrder�x���s��
	}
	int iEkiIndexOrg = EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrderOrg ) ;
	int iEkiIndexDst = EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrderDst ) ;
	if ( iEkiIndexOrg > iEkiIndexDst ){
		int i = iEkiIndexOrg ;	iEkiIndexOrg = iEkiIndexDst ; iEkiIndexDst = i ;
	}
	// --------------------------------	
	const Mu<CentDedDgrEki>* pCentDedDgrEkiCont = getCentDedDgrEkiCont() ;

	int idx ;
	for ( idx = iEkiIndexOrg ; idx < iEkiIndexDst ; idx ++ ){
		iRv += pCentDedDgrEkiCont->get( idx ).getDgrYZahyouKyori() ;
	}

	return ( iRv ) ;
}


int CentDedDgrDia::getEkikanSaisyouSec( 
			ERessyahoukou eRessyahoukou , 
			int iEkiOrderOrg ,
			int iEkiOrderDst )const 
{
	int iRv = 0 ;
	// --------------------------------
	if ( iEkiOrderOrg == INT_MAX ){
		iEkiOrderOrg = m_CentDedDgrEkiCont.size() - 1 ;
	}
	if ( iEkiOrderDst == INT_MAX ){
		iEkiOrderDst = m_CentDedDgrEkiCont.size() - 1 ;
	}
	// --------------------------------
	if ( !( 0 <= iEkiOrderOrg && iEkiOrderOrg < m_CentDedDgrEkiCont.size() ) ){
		return ( -1 ) ;	//		�w�wOrder�x���s��
	}
	if ( !( 0 <= iEkiOrderDst && iEkiOrderDst < m_CentDedDgrEkiCont.size() ) ){
		return ( -1 ) ;	//		�w�wOrder�x���s��
	}
	int iEkiIndexOrg = EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrderOrg ) ;
	int iEkiIndexDst = EkiIndexOfEkiOrder( eRessyahoukou , iEkiOrderDst ) ;
	if ( iEkiIndexOrg > iEkiIndexDst ){
		int i = iEkiIndexOrg ;	iEkiIndexOrg = iEkiIndexDst ; iEkiIndexDst = i ;
	}
	// --------------------------------	
	const Mu<CentDedDgrEki>* pCentDedDgrEkiCont = getCentDedDgrEkiCont() ;

	int idx ;
	for ( idx = iEkiIndexOrg ; idx < iEkiIndexDst ; idx ++ ){
		if ( eRessyahoukou == Ressyahoukou_Kudari ){
			iRv += pCentDedDgrEkiCont->get( idx ).getEkikanSaisyouSecKudari() ;
		}	else if ( eRessyahoukou == Ressyahoukou_Nobori ){
			iRv += pCentDedDgrEkiCont->get( idx ).getEkikanSaisyouSecNobori() ;
		}
	}

	return ( iRv ) ;
}


CdDcdPosXy CentDedDgrDia::calcDgrPosRessyasenKiten( 
		const CentDedDgrRessya* pCentDedDgrRessya , 
		const CentDedDgrRessyasen* pCentDedDgrRessyasen )const 
{
	int iEkiOrderRessyasenKiten = pCentDedDgrRessyasen->getRessyasenKitenEkiOrder() ;
	CentDedDgrEkiJikoku	aEkiJikokuKiten = 
		*pCentDedDgrRessya->getMuCentDedDgrEkiJikoku()->get( iEkiOrderRessyasenKiten ) ;
	int iDgrXPosKiten = aEkiJikokuKiten.getDgrXPosHatsu( true ) ;
	int iDgrYPosKiten = this->getDgrYPosOfEki( 
			pCentDedDgrRessya->getRessyahoukou() , 
			iEkiOrderRessyasenKiten ) ;
	return CdDcdPosXy( iDgrXPosKiten , iDgrYPosKiten ) ;
}

CdDcdPosXy CentDedDgrDia::calcDgrPosRessyasenSyuuten( 
		const CentDedDgrRessya* pCentDedDgrRessya , 
		const CentDedDgrRessyasen* pCentDedDgrRessyasen )const 
{
	int iEkiOrderRessyasenSyuuten = pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() ;
	CentDedDgrEkiJikoku	aEkiJikokuSyuuten = 
		*pCentDedDgrRessya->getMuCentDedDgrEkiJikoku()->get( iEkiOrderRessyasenSyuuten ) ;
	int iDgrXPosSyuuten = aEkiJikokuSyuuten.getDgrXPosChaku( true ) ;
	int iDgrYPosSyuuten =this->getDgrYPosOfEki( 
			pCentDedDgrRessya->getRessyahoukou() , 
			iEkiOrderRessyasenSyuuten ) ;
	return CdDcdPosXy( iDgrXPosSyuuten , iDgrYPosSyuuten ) ;
}


void CentDedDgrDia::createEstimateRessya( 
		const CentDedDgrRessya* pCentDedDgrRessya ,
		CentDedRessya* pCentDedRessya )const 
{


	CentDedRessya	aCentDedRessya( 
		m_CentDedDgrEkiCont.size() ,
		pCentDedDgrRessya->getRessyahoukou() ) ;

	// --------------------------------
	//	�����̐ݒ�
	// --------------------------------
	{
		aCentDedRessya.setRessyabangou( 
			pCentDedDgrRessya->getRessyabangou() ) ;
		aCentDedRessya.setRessyamei( 
			pCentDedDgrRessya->getRessyamei() ) ;
		aCentDedRessya.setGousuu( 
			pCentDedDgrRessya->getGousuu() ) ;

	}
	// --------------------------------
	//	�w�����̐ݒ�
	// --------------------------------
	{
		const Mu<const CentDedDgrEkiJikoku*>*	pMuCentDedDgrEkiJikoku = pCentDedDgrRessya->getMuCentDedDgrEkiJikoku() ;
		for ( int iEkiOrder = 0 ; 
			iEkiOrder < pMuCentDedDgrEkiJikoku->size() ; 
			iEkiOrder ++ )
		{
			CentDedDgrEkiJikoku	aCentDedDgrEkiJikoku = *pMuCentDedDgrEkiJikoku->get( iEkiOrder ) ;

			CentDedEkiJikoku	aEkiJikoku = aCentDedRessya.getCentDedEkiJikoku( iEkiOrder ) ;

			// --------------------------------
			//	�w����ݒ�
			// --------------------------------
			aEkiJikoku.setEkiatsukai( aCentDedDgrEkiJikoku.getEkiatsukai() ) ;
			
			// --------------------------------
			//	���̉w��[�_�Ƃ����Ԑ�������
			// --------------------------------
			int idxRessyasenChaku = INT_MIN ;
			int idxRessyasenHatsu = INT_MIN ;
			const Mu<const CentDedDgrRessyasen*>* pMuRessyasen = pCentDedDgrRessya->getCentDedDgrRessyasenCont() ;
			for ( int idxRessyasen = 0 ; 
				idxRessyasen < pMuRessyasen->size() ; 
				idxRessyasen ++ )
			{
				const CentDedDgrRessyasen*	pCentDedDgrRessyasen = pMuRessyasen->get( idxRessyasen ) ;
				if ( pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() == iEkiOrder )
				{
					idxRessyasenChaku = idxRessyasen ;
				}
				if ( pCentDedDgrRessyasen->getRessyasenKitenEkiOrder() == iEkiOrder )
				{
					idxRessyasenHatsu = idxRessyasen ;
				}
			}
			//idxRessyasenChaku = 
			//	���̉wOrder����Ԑ��I�_�Ȃ�A���̗�Ԑ�Order�A�����łȂ��Ȃ�INT_MIN 
			//idxRessyasenHatsu = 
			//	���̉wOrder����Ԑ��N�_�Ȃ�A���̗�Ԑ�Order�A�����łȂ��Ȃ�INT_MIN 

			// --------------------------------
			//	�w������ݒ�
			// --------------------------------
			if ( idxRessyasenChaku != INT_MIN && aCentDedDgrEkiJikoku.getDgrXPosChaku( true ) != INT_MIN )
			{
				//	��Ԑ��̏I�_�Ȃ�A������DgrXPos�����Ƃɒ�������ݒ�
				aEkiJikoku.setChakujikoku( CdDedJikoku( aCentDedDgrEkiJikoku.getDgrXPosChaku( true ) ) ) ;
			}
			if ( idxRessyasenHatsu != INT_MIN && aCentDedDgrEkiJikoku.getDgrXPosHatsu( true ) != INT_MIN )
			{
				//	��Ԑ��̋N�_�Ȃ�A������DgrXPos�����Ƃɔ�������ݒ�
				aEkiJikoku.setHatsujikoku( CdDedJikoku( aCentDedDgrEkiJikoku.getDgrXPosHatsu( true ) ) ) ;
			}
			if ( idxRessyasenChaku == INT_MIN && 
				idxRessyasenHatsu == INT_MIN && 
				aCentDedDgrEkiJikoku.getDgrXPosRessyasen() != INT_MIN )
			{
				//	��Ԑ��N�_�E�I�_�łȂ� && �w������ DgrXPosRessyasen ������ꍇ�́A
				//	DgrXPosRessyasen �𒅁E���ɐݒ�
				aEkiJikoku.setChakujikoku( CdDedJikoku( aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ) ;
				aEkiJikoku.setHatsujikoku( CdDedJikoku( aCentDedDgrEkiJikoku.getDgrXPosRessyasen() ) ) ;
			}

			aCentDedRessya.setCentDedEkiJikoku( iEkiOrder , aEkiJikoku ) ;
		}
	}
	// --------------------------------
		
	if ( pCentDedRessya != NULL )
	{
		*pCentDedRessya = aCentDedRessya ;
	}
}

void CentDedDgrDia::createEstimateRessya2( 
		const CentDedDgrRessya* pCentDedDgrRessya ,
		CentDedRessya* pCentDedRessya )const
{
	// --------------------------------
	CentDedRessya	aCentDedRessya( 
		m_CentDedDgrEkiCont.size() ,
		pCentDedDgrRessya->getRessyahoukou() ) ;
	if ( pCentDedRessya == NULL )
	{
		pCentDedRessya = &aCentDedRessya ;
	}
	// --------------------------------
	{
		//	���莞������ԃI�u�W�F�N�g�𐶐�
		createEstimateRessya(
			pCentDedDgrRessya ,
			pCentDedRessya ) ;
	}
	{
		//	�w���ɃA�N�Z�X���� Mu �𐶐�
		const Mu< CentDedDgrEkiCont::CdDedDgrEki >* muEki =	getCentDedDgrEkiCont()->getMuPtr( pCentDedRessya->getRessyahoukou())  ;


		// --------------------------------
		//	�x������w�̏ꍇ�́A�����w��
		//	����w�������R�s�[����
		//	(�x������Ԃ̃\�[�g�̐��x���グ�邽��)
		// --------------------------------

		//	�S�����w�ɁA�w�������R�s�[���܂��B
		//
		//	���̎d�l�́AA-B-C|B-D�`���̎x�����H����
		//	TransferSort(��p�\�[�g)�̐��x���グ�邽�߂̂��̂ł��B
		//	B-D�ԗ�Ԃ�B�w�̉w������
		//	A-B-C�̊Ԃ� B �ɂ��ݒ肷�邱�Ƃɂ��A��p�\�[�g��
		//	���x�����܂�܂��B
		{
			for ( int iEkiOrderSrc = 0 ; iEkiOrderSrc < muEki->size() ; iEkiOrderSrc ++ )
			{
				CentDedDgrEkiCont::CdDedDgrEki	aEkiSrc = muEki->get(iEkiOrderSrc) ;

				CentDedEkiJikoku	aEkiJikokuSrc = 
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrderSrc ) ;
				if ( aEkiJikokuSrc.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Teisya ||
					aEkiJikokuSrc.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka )
				{
					for ( int iEkiOrder = 0 ; 
						iEkiOrder <  muEki->size() ;
						iEkiOrder ++ )
					{
						if ( iEkiOrderSrc != iEkiOrder )
						{
							CentDedDgrEkiCont::CdDedDgrEki aEki = muEki->get(iEkiOrder) ;

							if ( aEkiSrc.getEkimei() == aEki.getEkimei() )
							{
								CentDedEkiJikoku	aEkiJikoku = 
									pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
								if ( aEkiJikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_None ||
									aEkiJikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
								{
									pCentDedRessya->setCentDedEkiJikoku( iEkiOrder , aEkiJikokuSrc ) ;
								}
							}
						}
					}
				}
			}
		}

	}


}
} //namespace entDgr
