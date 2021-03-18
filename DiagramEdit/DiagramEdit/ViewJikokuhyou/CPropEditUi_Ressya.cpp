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
//	$Id: CPropEditUi_Ressya.cpp 357 2016-08-18 16:59:16Z okm $
// ****************************************************************

#include "stdafx.h"
#include "CPropEditUi_Ressya.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

	// ********************************
	//@name �G���[���b�Z�[�W
	// ********************************
	// ��Ԏ�ʂ��͈͊O�ł��B
const char* const CPropEditUi_Ressya::ERRMSG_INVALID_RESSYASYUBETSU = "Invalid Ressyasyubetsu." ;



	// ================================
	//@name �I�[�o�[���C�g�̕K�v�ȃ��\�b�h1-Target�Ɉˑ����鏈��
	// ================================
void CPropEditUi_Ressya::UiDataFromTarget( UIDATA* pUiData ) 
{
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		CentDedRessya* pRessya = m_pTarget->get( i ) ;

		/* ��Ԃ�Null���ۂ����w�肷��`�F�b�N�{�b�N�X�ł��B */
		if ( i == 0 )
		{
			pUiData->iIsNull = (int)pRessya->isNull() ;
		}
		else if ( pUiData->iIsNull != (int)pRessya->isNull() )
		{
			pUiData->iIsNull = -1 ;	// ����
		}

		/* ��Ԕԍ� */
		if ( i == 0 )
		{
			pUiData->strRessyabangou = pRessya->getRessyabangou() ;
		}
		else if ( pUiData->strRessyabangou != pRessya->getRessyabangou() )
		{
			pUiData->strRessyabangou = "" ;
		}

		/* strRessyabangou �̕ҏW�̗L���E�����Btrue �Ȃ�L���ł� */
		pUiData->bRessyabangouIsEnable =  ( pUiData->iIsNull != 1 ) ;

		//target �������̏ꍇ�́A��Ԕԍ��͖����ł��B
		if ( i > 0 ){	pUiData->bRessyabangouIsEnable = false ;}

		/* ��Ԏ�ʂ�Index */
		if ( i == 0 )
		{
			pUiData->iRessyasyubetsuIndex = pRessya->getRessyasyubetsuIndex() ;
		}
		else if ( pUiData->iRessyasyubetsuIndex != pRessya->getRessyasyubetsuIndex() )
		{
			pUiData->iRessyasyubetsuIndex = -1 ;	//	�I���Ȃ�
		}

		/** iRessyasyubetsuIndex �̕ҏW�̗L���E�����Btrue �Ȃ�L���ł� */
		pUiData->bRessyasyubetsuIndexIsEnable =  ( pUiData->iIsNull != 1 ) ;

		/** ��Ԗ� */
		if ( i == 0 )
		{
			pUiData->strRessyamei = pRessya->getRessyamei() ;
		}
		else if ( pUiData->strRessyamei != pRessya->getRessyamei() )
		{
			pUiData->strRessyamei = "" ;
		}

		/** strRessyamei �̕ҏW�̗L���E�����Btrue �Ȃ�L���ł� */
		pUiData->bRessyameiIsEnable =  ( pUiData->iIsNull != 1 ) ;

		
		/** ���� */
		if ( i == 0 )
		{
			pUiData->strGousuu = pRessya->getGousuu() ;
		}
		else if ( pUiData->strGousuu != pRessya->getGousuu() )
		{
			pUiData->strGousuu = "" ;
		}
		/** strGousuu �̕ҏW�̗L���E�����Btrue �Ȃ�L���ł� */
		pUiData->bGousuuIsEnable =  ( pUiData->iIsNull != 1 ) ;

		/** ���l */
		if ( i == 0 )
		{
			pUiData->strBikou = pRessya->getBikou() ;
		}
		else if ( pUiData->strBikou != pRessya->getBikou() )
		{
			pUiData->strBikou = "" ;
		}
		/** strBikou �̕ҏW�̗L���E�����Btrue �Ȃ�L���ł� */
		pUiData->bBikouIsEnable =  ( pUiData->iIsNull != 1 ) ; 

		

		//UiDataFromTarget( &aUiData , pRessya ) ;
		//if ( i == 0 )
		//{
		//	m_UiData = aUiData ;
		//}
		//else
		//{
		//	if ( m_UiData.iIsNull >= 0 
		//		&&  m_UiData.iIsNull != aUiData.iIsNull )
		//	{
		//		m_UiData.iIsNull = -1 ;
		//	}
		//	if ( m_UiData.strRessyabangou.length() > 0 
		//		&& m_UiData.strRessyabangou != aUiData.strRessyabangou )
		//	{
		//		m_UiData.strRessyabangou.erase() ;
		//	}
		//	if ( m_UiData.iRessyasyubetsuIndex >= 0 
		//		&& m_UiData.iRessyasyubetsuIndex != aUiData.iRessyasyubetsuIndex )
		//	{
		//		m_UiData.iRessyasyubetsuIndex = -1 ; 
		//	}
		//	if ( m_UiData.strRessyamei.length() >= 0 
		//		&& m_UiData.strRessyamei != aUiData.strRessyamei )
		//	{
		//		m_UiData.strRessyamei.erase() ;
		//	}
		//	if ( m_UiData.strGousuu.length() >= 0 
		//		&& m_UiData.strGousuu != aUiData.strGousuu )
		//	{
		//		m_UiData.strGousuu.erase() ;
		//	}
		//	if ( m_UiData.strBikou.length() >= 0 
		//		&& m_UiData.strBikou != aUiData.strBikou )
		//	{
		//		m_UiData.strBikou.erase() ;
		//	}
		//}
	}
}

void CPropEditUi_Ressya::AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
{
	int iRv = 0 ; 

	/* ��Ԃ�Null���ۂ����w�肷��`�F�b�N�{�b�N�X�B */
	if ( bStartEdit || pUiDataPrev->iIsNull != pUiData->iIsNull)
	{
		//	��s(NULL)�ł���ꍇ�́A
		//	���̍��ڂ����ׂĖ����ɂ��܂��B
		//	��s�łȂ��ꍇ�͑��̍��ڂ͗L���ɂ��܂����A
		//	�^�[�Q�b�g�������̏ꍇ�͗�Ԕԍ��͖����ɂ��܂��B
		if ( pUiData->iIsNull == 1 )	//	��Ԃ���s�̏ꍇ�́A���̓��͍��ڂ͖���
		{
			pUiData->bRessyabangouIsEnable = false ;
			pUiData->bRessyasyubetsuIndexIsEnable = false ;
			pUiData->bRessyameiIsEnable = false ;
			pUiData->bGousuuIsEnable = false ;
			pUiData->bBikouIsEnable = false ;
		}
		else
		{
			if ( m_pTarget->size() > 1 )
			{
				pUiData->bRessyabangouIsEnable = false ;
			}
			else
			{
				pUiData->bRessyabangouIsEnable = true ;
			}
			pUiData->bRessyasyubetsuIndexIsEnable = true ;
			pUiData->bRessyameiIsEnable = true ;
			pUiData->bGousuuIsEnable = true ;
			pUiData->bBikouIsEnable = true ;
		}
	}
	/* ��Ԕԍ� */
	if ( bStartEdit || pUiDataPrev->strRessyabangou != pUiData->strRessyabangou)
	{
		//	�C���Ȃ��B
	}
	/* ��Ԏ�ʂ�Index */
	if ( bStartEdit || pUiDataPrev->iRessyasyubetsuIndex != pUiData->iRessyasyubetsuIndex)
	{
		/*
		//	�͈͊O�̒l�𐳋K��
		if ( m_iRessyasyubetsuCount <= pUiData->iRessyasyubetsuIndex   )
		{
			pUiData->iRessyasyubetsuIndex = m_iRessyasyubetsuCount - 1 ;
		}
		if ( pUiData->iRessyasyubetsuIndex < ( m_pTarget->size() > 1 ? -1 : 0 ) )
		{
			pUiData->iRessyasyubetsuIndex = 0 ; 
		}
		*/
		//	�����ł̐��K�����s�킸�ɁACheckUiData() �ŃG���[���o���܂��B
	}
	/* ��Ԗ� */
	if ( bStartEdit || pUiDataPrev->strRessyamei != pUiData->strRessyamei)
	{
		//	�C���Ȃ��B
	}

	/* ���� */
	if ( bStartEdit || pUiDataPrev->strGousuu != pUiData->strGousuu)
	{
		//	�C���Ȃ��B
	}

	/* ���l */
	if ( bStartEdit || pUiDataPrev->strBikou != pUiData->strBikou)
	{
		//	�C���Ȃ��B
	}

}

int CPropEditUi_Ressya::CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	
	/* ��Ԃ�Null���ۂ����w�肷��`�F�b�N�{�b�N�X�B */
	if ( bNewItem || pUiDataStartEdit->iIsNull != pUiData->iIsNull)
	{
		//	�G���[�`�F�b�N�Ȃ�
	}

	/* ��Ԏ�ʂ�Index */
	if ( bNewItem || pUiDataStartEdit->iRessyasyubetsuIndex != pUiData->iRessyasyubetsuIndex)
	{
		int iIndexLowerBound = 0 ;
		if ( m_pTarget->size() > 1 ){	iIndexLowerBound = -1 ;}
		if ( !( iIndexLowerBound <= pUiData->iRessyasyubetsuIndex 
			&& pUiData->iRessyasyubetsuIndex < m_iRessyasyubetsuCount ) )
		{
			iRv = -1 ;
			ShowError( ERRMSG_INVALID_RESSYASYUBETSU ) ;
			SetFocus( offsetof( UIDATA , iRessyasyubetsuIndex ) ) ;
		}
	}

	/* ��Ԗ� */
	if ( bNewItem || pUiDataStartEdit->strRessyamei != pUiData->strRessyamei)
	{
		//	�G���[�`�F�b�N�Ȃ�
	}

	/* ���� */
	if ( bNewItem || pUiDataStartEdit->strGousuu != pUiData->strGousuu)
	{
		//	�G���[�`�F�b�N�Ȃ�
	}

	/* ���l */
	if ( bNewItem || pUiDataStartEdit->strBikou != pUiData->strBikou)
	{
		//	�G���[�`�F�b�N�Ȃ�
	}
	return iRv ;
}

int CPropEditUi_Ressya::UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		CentDedRessya* pRessya = m_pTarget->get( i ) ;


		//	iIsNull ���ω������ꍇ
		if ( bNewItem || pUiDataStartEdit->iIsNull != pUiData->iIsNull )
		{
			pRessya->setIsNull( pUiData->iIsNull == 1 ) ;
		}

		//	iIsNull�ȊO�ɕύX��������ꂽ�ꍇ�́A
		//	�ύX���Ԃɔ��f���܂��B
		//	�A���ANull�̗�Ԃɂ͕ύX�������܂���
		//	(������ݒ肷�邱�Ƃɂ��ANULL��Ԃ̗�Ԃ���NULL�ɕω����邽�߂ł�)�B
		if ( !pRessya->isNull() )
		{
			if ( bNewItem || pUiDataStartEdit->strRessyabangou != pUiData->strRessyabangou  )
			{
				pRessya->setRessyabangou( pUiData->strRessyabangou ) ;
			}
			if ( bNewItem || pUiDataStartEdit->iRessyasyubetsuIndex != pUiData->iRessyasyubetsuIndex  )
			{
				pRessya->setRessyasyubetsuIndex(  pUiData->iRessyasyubetsuIndex ) ;
			}
			if ( bNewItem || pUiDataStartEdit->strRessyamei != pUiData->strRessyamei  )
			{
				pRessya->setRessyamei(  pUiData->strRessyamei ) ;
			}
			if ( bNewItem || pUiDataStartEdit->strGousuu != pUiData->strGousuu  )
			{
				pRessya->setGousuu(  pUiData->strGousuu ) ;
			}
			if ( bNewItem || pUiDataStartEdit->strBikou != pUiData->strBikou  )
			{
				pRessya->setBikou(  pUiData->strBikou ) ;
			}
		}

	}
	return iRv ;
}
	
	// ********************************
	//	�R���X�g���N�^
	// ********************************
CPropEditUi_Ressya::CPropEditUi_Ressya( 
    bool bNewItem , 
	Mu<CentDedRessya*>* pTarget ,
	int iRessyasyubetsuCount 
	) 
	: CPropEditUi2( bNewItem )
	, m_pTarget( pTarget ) 
	, m_iRessyasyubetsuCount( iRessyasyubetsuCount ) 
{
}
	
	

} //namespace ViewJikokuhyou

