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
//	CDedRessyaSoater_Ekiatsukai.cpp
//	$Id: CDedRessyaSoater_Ekiatsukai.cpp 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include <algorithm>
#include "CDedRessyaSoater_Ekiatsukai.h"
#include "NsMu\CaMui.h"
#include "NsMu\CMup_vector.h"

namespace entDed{

using namespace std ;


// ****************************************************************
//	CDedRessyaSoater_Ekiatsukai_CompareFunction
// ****************************************************************
/**
	const Mu<const CentDedRessya*> �Ŏw�肳�ꂽ��ԃR���e�i����
	��Ԃ̏��ɏ]���A
	��ԃC���f�N�X���r����֐��I�u�W�F�N�g�ł��B

*/
class CDedRessyaSoater_Ekiatsukai_CompareFunction
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		��ԃR���e�i�B
	*/
	const Mu<const CentDedRessya*>* m_muCentDedRessya ;
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	�\�[�g�̑ΏۂƂȂ鎞��Order�B
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

	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		�w�����A���я������������l�ɕϊ����܂��B
	@param eEkiatsukai [in]
		�w�����w�肵�Ă��������B
	@return
		�w���̕��я���\�������l��Ԃ��܂��B
		��ԁE�ʉ߁E�o�R�Ȃ��E�^�s�Ȃ��̏��ƂȂ�܂��B
	*/
	int sortOrderOfEEkiatsukai( CentDedEkiJikoku::EEkiatsukai eEkiatsukai ) 
	{
		int iRv = 0 ;
		switch( eEkiatsukai )
		{
		case CentDedEkiJikoku::Ekiatsukai_Teisya:	iRv = 0 ;	break ;
		case CentDedEkiJikoku::Ekiatsukai_Tsuuka:	iRv = 1 ;	break ;
		case CentDedEkiJikoku::Ekiatsukai_Keiyunasi:	iRv = 2 ;	break ;
		case CentDedEkiJikoku::Ekiatsukai_None:	iRv = 3 ;	break ;
		}
		return iRv ;
	}
	///@}
public:
	CDedRessyaSoater_Ekiatsukai_CompareFunction( 
		const Mu<const CentDedRessya*>* muCentDedRessya ,
		CdDedJikokuOrder jikokuOrder ,
		const CdDedJikoku& jikokuKitenJikoku ) 
		: m_muCentDedRessya( muCentDedRessya )
		, m_JikokuOrder( jikokuOrder )
		, m_jikokuKitenJikoku( jikokuKitenJikoku )
	{
	};
	/**
	@return
		(m_muCentDedRessya->get(left) < m_muCentDedRessya->get(right) 
		�Ȃ�^�ł��B

	@note
	  ��r��́A
			- �w��wIndex�̉w���́A��ԁE�ʉ߁E�o�R�Ȃ��E�^�s�Ȃ��̏�
			- �w������NULL�łȂ����̂�NULL�̂��̂Ƃł́ANULL�łȂ����̂���B
			- �w�����̏��������̂���
			- �w�����������Ȃ�RessyaIdx�̏������ق�����B
	*/
	bool operator()( 
		int idxleft , 
		int idxright )
	{
		const CentDedRessya* pRessyaLeft = 
			m_muCentDedRessya->get( idxleft ) ;
		const CentDedRessya* pRessyaRight = 
			m_muCentDedRessya->get( idxright ) ;
		CentDedEkiJikoku	aEkiJikokuLeft = pRessyaLeft->getCentDedEkiJikoku( m_JikokuOrder.getEkiOrder() ) ;
		CentDedEkiJikoku	aEkiJikokuRight = pRessyaRight->getCentDedEkiJikoku( m_JikokuOrder.getEkiOrder() ) ;
		
		// --------------------------------
		//	- �w��wIndex�̉w���́A��ԁE�ʉ߁E�o�R�Ȃ��E�^�s�Ȃ��̏�
		// --------------------------------
		{
			int iEkiatsukaiLeft = sortOrderOfEEkiatsukai( aEkiJikokuLeft.getEkiatsukai() ) ;
			int iEkiatsukaiRight = sortOrderOfEEkiatsukai( aEkiJikokuRight.getEkiatsukai() ) ;
			if ( iEkiatsukaiLeft < iEkiatsukaiRight )
			{
				return true ;
			}
			else if ( iEkiatsukaiLeft > iEkiatsukaiRight )
			{
				return false ;
			}
		}

		// --------------------------------
		//	�\�[�g�Ώۂ̉w����Order�̉w�������擾���܂��B
		//	NULL�̏ꍇ�́A���Ȃ甭�E���Ȃ璅�ő��
		// --------------------------------
		//	�\�[�g�Ώۂ̉w����Order�̉w�������擾���܂��B
		CdDedJikokuOrder	aJikokuOrderLeft = m_JikokuOrder ;
		CdDedJikoku	aJikokuLeft = pRessyaLeft->getEkiJikoku( aJikokuOrderLeft ) ;
		CdDedJikokuOrder	aJikokuOrderRight = m_JikokuOrder ;
		CdDedJikoku	aJikokuRight = pRessyaRight->getEkiJikoku( aJikokuOrderRight ) ;
		
		//	�\�[�g�Ώۂ̉w����Order���������ŁA
		//	��Ԃ̔�������NULL�̏ꍇ�́A���������擾���܂��B
		//	�\�[�g�Ώۂ̉w����Order���������ŁA
		//	��Ԃ̒�������NULL�̏ꍇ�́A���������擾���܂��B
		if ( aJikokuLeft.isNull() )
		{
			aJikokuOrderLeft.EkiJikokuItemInvert() ;
			
			aJikokuLeft = pRessyaLeft->getEkiJikoku( aJikokuOrderLeft ) ;
		}
		if ( aJikokuRight.isNull() )
		{
			aJikokuOrderRight.EkiJikokuItemInvert() ;

			aJikokuRight = pRessyaRight->getEkiJikoku( aJikokuOrderRight ) ;
		}

		// --------------------------------
		//	- �w������NULL�łȂ����̂�NULL�̂��̂Ƃł́ANULL�łȂ����̂���B
		// --------------------------------
		if ( !aJikokuLeft.isNull() && aJikokuRight.isNull() )
		{
			//	left�͔�NULL�ŁAright��NULL
			return true ;
		}
		else if ( aJikokuLeft.isNull() && !aJikokuRight.isNull() )
		{
			//	left��NULL�ŁAright�͔�NULL
			return false ;
		}


		// --------------------------------
		//	- �w�����̏��������̂���
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
		//	�������Ɣ������ł́A����������
		// --------------------------------
		if ( aJikokuOrderLeft.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku && 
			aJikokuOrderRight.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu ) 
		{
			return true ;
		}
		else if ( aJikokuOrderLeft.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu && 
			aJikokuOrderRight.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku ) 
		{
			return false ;
		}
		// --------------------------------
		//	- �w�����������Ȃ�RessyaIdx�̏������ق�����B
		// --------------------------------
		if ( idxleft < idxright )
		{
			return true ;
		}
		else if ( idxleft > idxright )
		{
			return false ;
		}
		// --------------------------------
		return false ;
	}

};



// ****************************************************************
//	CDedRessyaSoater_Ekiatsukai
// ****************************************************************
	// ********************************
	//	�R���X�g���N�^
	// ********************************
CDedRessyaSoater_Ekiatsukai::CDedRessyaSoater_Ekiatsukai(
		CdDedJikokuOrder  aJikokuOrder,  
  		const CdDedJikoku &  jikokuKitenJikoku ) 
		: m_JikokuOrder( aJikokuOrder ) 
		, m_jikokuKitenJikoku( jikokuKitenJikoku ) 
{
}

CDedRessyaSoater_Ekiatsukai::~CDedRessyaSoater_Ekiatsukai() 
{
}
	

	// ********************************
	//@name ����
	// ********************************



void CDedRessyaSoater_Ekiatsukai::sortRessyaIndex( 
		const CentDedRessyaCont* pRessyaCont , 
		Mui<int>* muRessyaIndexOrder , 
		IfProgress* pIfProgress ) 
{
	bool bAbort = false ;

	const Mu<const CentDedRessya*>* pCentDedRessyaCont = pRessyaCont->getMuPtr() ; 
	//pCentDedRessyaCont = CentDedRessyaCont �I�u�W�F�N�g�ւ̃|�C���^��ێ�����
	//	�R���e�i�ł��B

	// --------------------------------
	//	�\�[�g�p�w�����̃R���e�i�̓��e�ɏ]���A
	//	�C���f�N�X���\�[�g
	// --------------------------------
	{
		//	�\�[�g�� std::sort ���g�����߁A
		//	�C���f�N�X�R���e�i�� std::vector �Ɉ�U�R�s�[����
		CMup_vector<int>	contiRessyaIndexOrder ;
		CaMui<int>( &contiRessyaIndexOrder ).insert( muRessyaIndexOrder , 0 , INT_MAX ) ;

		//	std::vector �̓��e���\�[�g
		std::sort( 
			contiRessyaIndexOrder.getAdaptee()->begin() ,
			contiRessyaIndexOrder.getAdaptee()->end() ,
			CDedRessyaSoater_Ekiatsukai_CompareFunction( 
				pCentDedRessyaCont ,
				m_JikokuOrder ,
				m_jikokuKitenJikoku ) ) ;


		//	�\�[�g���ʂ��A���̃R���e�i�ɖ߂�
		muRessyaIndexOrder->erase( 0 , INT_MAX ) ;
		CaMui<int>( muRessyaIndexOrder ).insert( &contiRessyaIndexOrder , 0 , INT_MAX ) ;
	}
};

} //namespace entDed
