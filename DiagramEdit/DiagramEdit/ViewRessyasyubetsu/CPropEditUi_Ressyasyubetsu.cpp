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
//	$Id: CPropEditUi_Ressyasyubetsu.cpp 399 2016-11-26 08:45:03Z okm $
// ****************************************************************

/** @file */
#include "stdafx.h"
#include "CPropEditUi_Ressyasyubetsu.h"

namespace ViewRessyasyubetsu {

// ****************************************************************
//	CPropEditUi_Ressyasyubetsu
// ****************************************************************
	// ��ʖ����w�肳��Ă��܂���
const char* const CPropEditUi_Ressyasyubetsu::ERRMSG_SYUBETUSMEI_EMPTY = "Ressyasyubetsumei is empty." ;

	// ���̂��������܂�
const char* const CPropEditUi_Ressyasyubetsu::ERRMSG_RYAKUSYOULENGTH = "Ryakusyou is too long(Limit is 6 characters)." ;


	// ================================
	//  �I�[�o�[���C�g�̕K�v�ȃ��\�b�h1-Target�Ɉˑ����鏈��
	// ================================
void CPropEditUi_Ressyasyubetsu::UiDataFromTarget( UIDATA* pUiData ) 
{
	for ( int i = 0 ; i < m_pTarget->size() ; i ++ )
	{
		const CentDedRessyasyubetsu* pTarget = m_pTarget->get( i ) ; 

		/* ��Ԏ�ʖ� */
		if ( i == 0 )
		{
			pUiData->strSyubetsumei = pTarget->getSyubetsumei() ;
		}
		else if ( pUiData->strSyubetsumei != pTarget->getSyubetsumei() )
		{
			pUiData->strSyubetsumei = "" ;
		}
	
		/* ��Ԏ�ʖ��̗L���E���� �́A�ΏۊO */
	
		/** ���́i��ʖ��̗��́j */
		if ( i == 0 )
		{
			pUiData->strRyakusyou = pTarget->getRyakusyou();
		}
		else if ( pUiData->strRyakusyou != pTarget->getRyakusyou() )
		{
			pUiData->strRyakusyou = "" ;
		}
	
		/*	�����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)	*/
		if ( i == 0 )
		{
			pUiData->colorJikokuhyouMojiColor = pTarget->getJikokuhyouMojiColor() ;
		}
		else if ( pUiData->colorJikokuhyouMojiColor != pTarget->getJikokuhyouMojiColor() )
		{
			pUiData->colorJikokuhyouMojiColor.setIsNull( true ) ; 
		}
		/* �����\�r���[�ŁA���̗�Ԏ�ʂ̎�����\�����邽�߂̎����\�t�H���g */
		if ( i == 0 )
		{
			pUiData->iJikokuhyouFontIndex= pTarget->getJikokuhyouFontIndex() ;
		}
		else if ( pUiData->iJikokuhyouFontIndex != pTarget->getJikokuhyouFontIndex() )
		{
			pUiData->iJikokuhyouFontIndex = -1 ;
		}

		/* �_�C���O�������̐F */
		if ( i == 0 )
		{
			pUiData->colorDiagramSenColor = pTarget->getDiagramSenColor() ;
		}
		else if ( pUiData->colorDiagramSenColor != pTarget->getDiagramSenColor()  )
		{
			pUiData->colorDiagramSenColor.setIsNull( true )  ;
		}
	
		/* �_�C���O�������̐��X�^�C��	*/
		if ( i == 0 )
		{
			pUiData->iDiagramSenStyle = (int)pTarget->getDiagramSenStyle() ;
		}
		else if ( pUiData->iDiagramSenStyle = (int)pTarget->getDiagramSenStyle() )
		{
			pUiData->iDiagramSenStyle = -1 ;	// �s��
		}
		/* �_�C���O�������̐��X�^�C�����������ۂ����w�肵�܂��B*/
		if( i == 0 )
		{
			pUiData->iDiagramSenIsBold = (int)pTarget->getDiagramSenIsBold() ;
		} 
		else if ( pUiData->iDiagramSenIsBold != (int)pTarget->getDiagramSenIsBold() )
		{
			pUiData->iDiagramSenIsBold = -1 ;	// �s��	
		}

		/*  ��ԉw�����̕��@ */
		if ( i == 0 )
		{
			pUiData->iStopMarkDrawType = (int)pTarget->getStopMarkDrawType() ;
		}
		else if ( pUiData->iStopMarkDrawType != (int)pTarget->getStopMarkDrawType() )
		{
			pUiData->iStopMarkDrawType = -1 ;
		}
	}
}



void CPropEditUi_Ressyasyubetsu::AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
{
	/* ��Ԏ�ʖ� */
	if ( bStartEdit || pUiDataPrev->strSyubetsumei != pUiData->strSyubetsumei)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}
	
	/* ��Ԏ�ʖ��̗L���E���� */
	if ( bStartEdit || pUiDataPrev->bSyubetsumeiIsEnable != pUiData->bSyubetsumeiIsEnable)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}
	
	/* ���́i��ʖ��̗��́j */
	if ( bStartEdit || pUiDataPrev->strRyakusyou != pUiData->strRyakusyou)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}
	/* �����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)	*/
	if ( bStartEdit || pUiDataPrev->colorJikokuhyouMojiColor != pUiData->colorJikokuhyouMojiColor)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}

	/* �����\�r���[�ŁA���̗�Ԏ�ʂ̎�����\�����邽�߂̎����\�t�H���g */
	if ( bStartEdit || pUiDataPrev->iJikokuhyouFontIndex != pUiData->iJikokuhyouFontIndex)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}

	/* �_�C���O�������̐F */
	if ( bStartEdit || pUiDataPrev->colorDiagramSenColor != pUiData->colorDiagramSenColor)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}
	
	/* �_�C���O�������̐��X�^�C��*/	
	if ( bStartEdit || pUiDataPrev->iDiagramSenStyle != pUiData->iDiagramSenStyle)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}

	/* �_�C���O�������̐��X�^�C�����������ۂ����w�肵�܂��B*/
	if ( bStartEdit || pUiDataPrev->iDiagramSenIsBold != pUiData->iDiagramSenIsBold)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}
	
	/*	 ��ԉw�����̕��@ */
	if ( bStartEdit || pUiDataPrev->iStopMarkDrawType != pUiData->iStopMarkDrawType)
	{
		// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
	}
}


int CPropEditUi_Ressyasyubetsu::CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ;


	/* ��Ԏ�ʖ� */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->strSyubetsumei != pUiData->strSyubetsumei)
		{
			if ( pUiData->strSyubetsumei.length() == 0 )
			{
				iRv = -1 ;      //  ��ʖ����w�肳��Ă��܂���
				ShowError( ERRMSG_SYUBETUSMEI_EMPTY ) ;
				SetFocus( offsetof( UIDATA , strSyubetsumei )) ;
			}
		}
	}
		
	/* ��Ԏ�ʖ��̗L���E���� */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->bSyubetsumeiIsEnable != pUiData->bSyubetsumeiIsEnable)
		{
			// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
		}
	}
		
	/* ���́i��ʖ��̗��́j */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->strRyakusyou != pUiData->strRyakusyou)
		{
			if ( pUiData->strRyakusyou.length() > 6 )
			{
				iRv = -2 ;      //  ���̂��������܂�(���̂�6�����܂�(���p)�ł�)
				ShowError( ERRMSG_RYAKUSYOULENGTH ) ;
				SetFocus( offsetof( UIDATA , strRyakusyou )) ;
			}
		}
	}
	/* �����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)	*/
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->colorJikokuhyouMojiColor != pUiData->colorJikokuhyouMojiColor)
		{
			// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
		}
	}

	/* �����\�r���[�ŁA���̗�Ԏ�ʂ̎�����\�����邽�߂̎����\�t�H���g */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iJikokuhyouFontIndex != pUiData->iJikokuhyouFontIndex)
		{
			// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
		}
	}

	/* �_�C���O�������̐F */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->colorDiagramSenColor != pUiData->colorDiagramSenColor)
		{
			// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
		}
	}
		
	/* �_�C���O�������̐��X�^�C��*/	
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iDiagramSenStyle != pUiData->iDiagramSenStyle)
		{
			// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
		}
	}

	/* �_�C���O�������̐��X�^�C�����������ۂ����w�肵�܂��B*/
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iDiagramSenIsBold != pUiData->iDiagramSenIsBold)
		{
			// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
		}
	}
		
	/*	 ��ԉw�����̕��@ */
	if ( iRv >= 0 )
	{
		if ( bNewItem || pUiDataStartEdit->iStopMarkDrawType != pUiData->iStopMarkDrawType)
		{
			// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
		}
	}


	return iRv ;
}
int CPropEditUi_Ressyasyubetsu::UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
{
	int iRv = 0 ; 
	for ( int i = 0 ; iRv >= 0 && i < m_pTarget->size() ; i ++ )
	{
		CentDedRessyasyubetsu* pTarget = m_pTarget->get( i ) ; 

		/* ��Ԏ�ʖ� */
		if ( bNewItem || pUiDataStartEdit->strSyubetsumei != pUiData->strSyubetsumei)
		{
			pTarget->setSyubetsumei( pUiData->strSyubetsumei ) ;
		}
		
		/* ���́i��ʖ��̗��́j */
		if ( bNewItem || pUiDataStartEdit->strRyakusyou != pUiData->strRyakusyou)
		{
			pTarget->setRyakusyou( pUiData->strRyakusyou ) ;
		}
		/* �����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)	*/
		if ( bNewItem || pUiDataStartEdit->colorJikokuhyouMojiColor != pUiData->colorJikokuhyouMojiColor)
		{
			pTarget->setJikokuhyouMojiColor( pUiData->colorJikokuhyouMojiColor ) ;
		}

		/* �����\�r���[�ŁA���̗�Ԏ�ʂ̎�����\�����邽�߂̎����\�t�H���g */
		if ( bNewItem || pUiDataStartEdit->iJikokuhyouFontIndex != pUiData->iJikokuhyouFontIndex)
		{
			pTarget->setJikokuhyouFontIndex( pUiData->iJikokuhyouFontIndex ) ;
		}

		/* �_�C���O�������̐F */
		if ( bNewItem || pUiDataStartEdit->colorDiagramSenColor != pUiData->colorDiagramSenColor)
		{
			pTarget->setDiagramSenColor( pUiData->colorDiagramSenColor ) ;
		}
		
		/* �_�C���O�������̐��X�^�C��*/	
		if ( bNewItem || pUiDataStartEdit->iDiagramSenStyle != pUiData->iDiagramSenStyle)
		{
			pTarget->setDiagramSenStyle( (CentDedRessyasyubetsu::ESenStyle)pUiData->iDiagramSenStyle ) ;
		}

		/* �_�C���O�������̐��X�^�C�����������ۂ����w�肵�܂��B*/
		if ( bNewItem || pUiDataStartEdit->iDiagramSenIsBold != pUiData->iDiagramSenIsBold)
		{
			pTarget->setDiagramSenIsBold( pUiData->iDiagramSenIsBold == 1 ) ;
		}
		
		/*	 ��ԉw�����̕��@ */
		if ( bNewItem || pUiDataStartEdit->iStopMarkDrawType != pUiData->iStopMarkDrawType)
		{
			pTarget->setStopMarkDrawType( (CentDedRessyasyubetsu::EStopMarkDrawType)pUiData->iStopMarkDrawType ) ;
		}
	}
	return iRv ;
}



	// ********************************
	//	�R���X�g���N�^
	// ********************************
CPropEditUi_Ressyasyubetsu::CPropEditUi_Ressyasyubetsu(
	bool bNewItem , 
	Mu<CentDedRessyasyubetsu*>* pTarget )
	: CPropEditUi2( bNewItem )
	, m_pTarget( pTarget ) 
{
	
}

} //namespace ViewRessyasyubetsu 



