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
//	CWjkState_Renzoku.cpp
//	$Id: CWjkState_Renzoku.cpp 368 2016-08-19 11:11:10Z okm $
// ****************************************************************
*/
#include "stdafx.h"


#include <imm.h>

#include "NsOu\Ou.h"
#include "NsOu\OuNew.h"
#include "NsOu\dynamic_castOu.h"
#include "logmsg\LogMsg.h"
#include "DcDraw\CDcdLine.h"
#include "DcDraw\CDcdTextbox.h"
#include "str\strprintf.h"
#include "str\strtoint.h"

#include "..\CDlgRessyaProp.h"
#include "..\CDlgEkiJikokuProp.h"
#include "..\..\DiagramEdit.h"
#include "..\..\CRfEditCmdHolder.h"
#include "..\..\DedRosenFileData\EditCmd\EditCmd.h"
#include "CWjkState_Renzoku.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{ namespace WndJikokuhyou{
using namespace std ;
using namespace OuLib ;

// ****************************************************************
//	CWjkState_Renzoku
// ****************************************************************
// --------------------------------
//@name OnUpdate�����֐�
// --------------------------------
void CWjkState_Renzoku::OnUpdate_All() 
{
	LogMsg( "CWjkState_Renzoku::OnUpdate_All()" ) ;

	//	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
	//	�ɑJ�ڂ��܂��B
	//	OnUpdate() �́A�w��ԕҏW���[�h�x�ɈϏ����܂��B
	getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
		CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
	CWjkState* pCState = 
		getCWndDcdGrid()->getStateMachine()->getCStateContGet()->get( 
		CWndJikokuhyou::StateIdx_Ressyahensyu  ) ;
	pCState->OnUpdate( NULL , 0 , NULL ) ;

	LogMsg( "CWjkState_Renzoku::OnUpdate_All()=" ) ;
}


void CWjkState_Renzoku::OnUpdate_CentDedRessya( 
	Ou<CRfEditCmd_Ressya> pCommand ) 
{
	//	���̃r���[�ɑ΂����Ԃ̕ύX�łȂ��ꍇ�́A�㑱�����s���܂���B
	int iDiaIndex = GetDocument()->getDiaIndex() ;
	if ( !( pCommand->getDiaIndex() == iDiaIndex && 
		pCommand->getRessyahoukou() == GetDocument()->getRessyahoukou() ) ){
			return ;
	}
	const CentDedRessyaCont*	pCentDedRessyaContSrc = 
		pCommand->getCentDedRessyaContSrc() ;
	if ( !( pCommand->getSizeDst() == 1 && 
		pCentDedRessyaContSrc->size() == 1 ) )
	{
			//	�P�{�̗�Ԃ̒u�����ȊO�̏ꍇ�́A
			//	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
			//	�ɑJ�ڂ��܂��B
			//	OnUpdate() �́A�w��ԕҏW���[�h�x�ɈϏ����܂��B
			getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
				CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
			CWjkState* pCState = 
				getCWndDcdGrid()->getStateMachine()->getCStateContGet()->get( 
				CWndJikokuhyou::StateIdx_Ressyahensyu  ) ;

			pCState->OnUpdate( NULL , 0 , NULL ) ; ;
			//	���݂́A���̏ꍇ�̍X�V�͑S�X�V�����ɂ��Ă��܂��B
			//	�œK���̗]�n������܂��B
			//
			//	�A�����[�h�œ��͒��̗��(m_iXColumnNumberFocus)
			//	���O�̗�ɑ΂��ė�Ԃ̒ǉ���폜�����������ꍇ�A
			//	m_iXColumnNumberFocus �́A�A�����͂��s���Ă���
			//	����w���Ȃ��Ȃ��Ă��܂��B
			//	���̂��߁AendEditCell() �Ő������A�����̓��[�h����������
			//	���Ƃ��ł��܂���B
			//	pCommand �����Ԃ̑����𔻒f���A
			//	��������Ƃ� m_iXColumnNumberFocus �𒲐����Ă���
			//	endEditCell() ���Ăяo�����Ƃɂ��A
			//	�X�V�ʂ��ŏ��ɂ��邱�Ƃ��ł��܂��B
			//
			//pCState->OnUpdate( NULL , 0 , 
			//	&CRfEditCmdHolder( pCommand ) ) ;

	}
	else
	{
		//	�P�{�̗��
		int iRessyaIndex = pCommand->getIndexDst() ;
		getCWndDcdGrid()->updateUI_ReplaceRessya( iRessyaIndex , 1 , 1 ) ;
	}
}

// --------------------------------
//@name �����֐�
// --------------------------------
bool CWjkState_Renzoku::update_adjustProp() 
{
	int iRv = 0 ;


	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	CdDcdPosXy	posFocusCell = getCWndDcdGrid()->getCFocus()->getFocusCellColumnNumber() ;

	// --------------------------------
	int iRessyaIndex = -1 ;		//	�t�H�[�J�X�Z���̗��Index
	const CentDedRessya* pCentDedRessya = NULL ;	//	�t�H�[�J�X�Z���̗�ԃI�u�W�F�N�g
	CdDedJikokuOrder aJikokuOrder ;	//	�t�H�[�J�X�Z���̎���Order
	if ( iRv >= 0 )
	{
		CdXColSpec aXColSpec = 
			getCWndDcdGrid()->getXColSpecOfFocus() ;
		if ( aXColSpec.getColumnType() == 
			CdXColSpec::ColumnType_Ressya )
		{
			iRessyaIndex = aXColSpec.getRessyaIndex()  ;
			pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
		}
		else
		{
			iRv = -1 ;	//	�t�H�[�J�X�Z�����A��Ԃ̈ʒu�ł͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	�t�H�[�J�X�Z�����A�w�����̈ʒu�ł͂���܂���B
		}
	}
	//iRessyaIndex = �t�H�[�J�X�Z���̗��Index
	//pCentDedRessya = �t�H�[�J�X�Z���̗�ԃI�u�W�F�N�g
	//aJikokuOrder = �t�H�[�J�X�Z���̎���Order

	// --------------------------------
	//  ��[�t�H�[�J�X�ʒu�̉w����Ourder�ȑO�ɁA�w�����̓��͂��ꂽ�w������Ȃ�]Ressyahensyu�ɑJ��
	if ( iRv >= 0 )
	{
		CdDedJikokuOrder	aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
			pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
		if ( aJikokuOrderRev.getIsNull() )
		{
			iRv = -3 ;	//	�t�H�[�J�X�ʒu�̉w����Ourder�ȑO�ɁA�w�����̓��͂��ꂽ�w������Ȃ�
		}
	}
	//  ��[�t�H�[�J�X�Z�����ҏW����Ԃ̒��������ł͂Ȃ�]Ressyahensyu�ɑJ��
	if ( iRv >= 0 )
	{
		if ( posFocusCell.getX() != m_iXColumnNumberFocus )
		{
			iRv = -4 ;	//	�t�H�[�J�X�Z�����A�ҏW����Ԃł͂���܂���B
		}
	}
	// --------------------------------
	if ( iRv < 0 )
	{
		//iRv
		//	-1 ;	//	�t�H�[�J�X�Z�����A��Ԃ̈ʒu�ł͂���܂���B
		//	-2 ;	//	�t�H�[�J�X�Z�����A�w�����̈ʒu�ł͂���܂���B
		//	-3 ;	//	�t�H�[�J�X�ʒu�̉w����Ourder�ȑO�ɁA�w�����̓��͂��ꂽ�w������Ȃ�
		//	-4 ;	//	�t�H�[�J�X�Z�����A�ҏW����Ԃł͂���܂���B
		getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
	}
	return ( iRv != 0 ) ;

}

bool CWjkState_Renzoku::update_updateScreen( bool bOnExit ) 
{
	int iRv = 0 ;

	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	// --------------------------------
	int iRessyaIndex = -1 ;
	const CentDedRessya* pCentDedRessya = NULL ;
	CdDedJikokuOrder aJikokuOrder ;
	CdDcdPosXy	posFocusCell = getCWndDcdGrid()->getCFocus()->getFocusCellColumnNumber() ;

	
	if ( iRv >= 0 )
	{
		if ( m_iXColumnNumberFocus < 0 )
		{
			iRv = -1 ;
		}
	}
	CdXColSpec aXColSpec ;
	CdYColSpec aYColSpec ;
	if ( iRv >= 0 )
	{
		CdXColSpecCont aXColSpecCont(
			getCWndDcdGrid()->createXColSpecCont() ) ;
		CdYColSpecCont aYColSpecCont = 
			getCWndDcdGrid()->createYColSpecCont() ;


		aXColSpec = aXColSpecCont.ColumnNumberToSpec( m_iXColumnNumberFocus ) ;
		if ( aXColSpec.getColumnType() == 
			CdXColSpec::ColumnType_Ressya )
		{
			iRessyaIndex = aXColSpec.getRessyaIndex() ;
			pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
		}
		else
		{
			iRv = -1 ;	//	�t�H�[�J�X�Z�����A��Ԃ̈ʒu�ł͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		aYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( aYColSpec ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	�t�H�[�J�X�Z�����A�w�����̈ʒu�ł͂���܂���B
		}
	}
	//posFocusCell = �t�H�[�J�X�Z��
	//iRessyaIndex = �A�����͒�(m_iXColumnNumberFocus)�̗��Index
	//pCentDedRessya = �A�����͒�(m_iXColumnNumberFocus)�̗�ԃI�u�W�F�N�g
	//aJikokuOrder = �t�H�[�J�X�Z���̎���Order

	// --------------------------------
	//	- 1. �ҏW������A�w�����ōX�V
	// --------------------------------

	//	�ҏW���̗�ԗ���X�V
	if ( iRv >= 0 )
	{
		getCWndDcdGrid()->updateUI_ReplaceRessya( iRessyaIndex , 1 , 1 ) ;
		iRv = 1 ;
	}
	// --------------------------------
	//	- 2. �ҏW���̉w����Order�ɑ΂��āA�u���O�̉w�����̎�+�ҏW���̕��v��ݒ�
	// --------------------------------
	//	�ҏW���Z���ɁA����ǉ�
	if ( iRv >= 0 )
	{
		if ( !bOnExit )
		{
			//	�t�H�[�J�X�Z���ʒu�ɁA�ҏW���̉w������ǉ�

			CdDedJikokuOrder	aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
				pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
			if ( aJikokuOrderRev.getIsNull() )
			{
				iRv = -5 ;	//	�t�H�[�J�X�ʒu�̑O�ɁA�w�����̓��͂��ꂽ�w������Ȃ�
			}
			else
			{
				CdDedJikoku	aJikokuRev = pCentDedRessya->getEkiJikoku( aJikokuOrderRev ) ;
				string	strJikoku = strprintf( "%2d%-2s" , 
					aJikokuRev.getHour() ,
					m_strMinutes.c_str() ) ;
				CDcdGridCell* pCell = getCWndDcdGrid()->getCFocus()->getFocusCell() ;
				Ou<CDcdTextbox>	pCDcdTextbox = pCell->getIfDcDraw() ;
				pCDcdTextbox->setText( strJikoku ) ;
				getCWndDcdGrid()->InvalidateCell( posFocusCell.getX() , posFocusCell.getY() ) ;

				iRv = 1 ;
			}
		}
	}
	return ( iRv > 0 ) ;
}

bool CWjkState_Renzoku::update() 
{
	bool bRv = false ;
	bRv |= update_adjustProp() ;
	bRv |= update_updateScreen() ;
	return bRv ;
}


CDcdGridCell* CWjkState_Renzoku::calcCellToNext( CDcdGridCell* pcellCurrent , int iSign ) 
{
	CDcdGridCell* pcellNext = NULL ;
	if ( iSign < 0 )
	{
		iSign = -1 ;
	}
	else 
	{
		iSign = +1 ;
	}
	// --------------------------------

	//	�J�����g�Z���̎��̉w�����Z�����������܂��B
	CdYColSpecCont aYColSpecCont = getCWndDcdGrid()->createYColSpecCont() ;
	for ( CDcdGridCell* pCell = getCWndDcdGrid()->getCXDcdGrid()->calcMovedCell( pcellCurrent , 0 , iSign ) ;
		pcellNext == NULL && pCell != NULL ;
		pCell = getCWndDcdGrid()->getCXDcdGrid()->calcMovedCell( pCell , 0 , iSign ) )
	{
		int iYColumnNumberNext = getCWndDcdGrid()->getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ;

		//	Y��ԍ���������ȊO(�w�����J�n�ʒu����w�����I���ʒu�͈̔͂̊O)�Ɉړ������ꍇ�́A���[�v�I��
		if ( !(
			aYColSpecCont.getColumnNumber_Ekijikoku_begin() <= iYColumnNumberNext && 
			iYColumnNumberNext < aYColSpecCont.getColumnNumber_Ekijikoku_end() ) ) 
		{
			break ;
		}

		// Y��ԍ��ɑΉ����鎞��Order���Ȃ���΁A���Ƀt�H�[�J�X���ړ�
		//	(�����E�����\�̓r���ɒ������E�������ȊO���o�ꂵ���ꍇ�ɔ����Ă��܂�)
		CdDedJikokuOrder	aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf(
			aYColSpecCont.ColumnNumberToSpec( iYColumnNumberNext ) );
		if ( aJikokuOrder.getIsNull() )
		{
			continue ;
		}
		pcellNext = pCell ;
	}

	return ( pcellNext ) ;
}


// ********************************
//	�R���X�g���N�^
// ********************************
CWjkState_Renzoku::
CWjkState_Renzoku( 
	CWndJikokuhyou*	pCWndDcdGrid )
	: super( pCWndDcdGrid )
	, m_iXColumnNumberFocus( -1 ) 
{
}
CWjkState_Renzoku::
~CWjkState_Renzoku() 
{
}

// ********************************
//	CWjkState
// ********************************
/**
	�w��̃E�C���h�E�́AIME��ON/OFF�ɂ��܂��B
 @param hWnd [in]
	�E�C���h�E�n���h�����w�肵�Ă��������B
 @param iOn [in]
	- TRUE ;	//	IME��ON�ɂ���
	- FALSE ;	//	IME��OFF�ɂ���
 @return
	-	1 ;	//	��Ԃ�ύX���܂����B
	-	0 ;	//	��Ԃ�ύX����K�v�͂���܂���ł����B
	-	-1 ;	//	�G���[(ImmGetContext() �Ɏ��s)
*/
static int ImeControl( HWND hWnd, BOOL iOn )
{
	int iRv = 0 ;

	HIMC hImc = ::ImmGetContext( hWnd );
	if ( hImc )
	{
		int j = (::ImmGetOpenStatus( hImc )) ? TRUE : FALSE;
		if ( j != iOn ){
			iRv = 1 ;
			::ImmSetOpenStatus( hImc, iOn );
		}
		::ImmReleaseContext( hWnd , hImc );
	}	else	{
		iRv = -1 ;	//	�G���[(ImmGetContext() �Ɏ��s)
	}
	return ( iRv ) ;
}

	// ********************************
	//@name CWjkState-����
	// ********************************
int CWjkState_Renzoku::canEnter() 
{
	int iRv = 0 ;

	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	CdDcdPosXy	posFocusCell = getCWndDcdGrid()->getCFocus()->getFocusCellColumnNumber() ;
	// --------------------------------
	int iRessyaIndex = -1 ;		//	�t�H�[�J�X�Z���̗��Index
	const CentDedRessya* pCentDedRessya = NULL ;	//	�t�H�[�J�X�Z���̗�ԃI�u�W�F�N�g
	CdDedJikokuOrder aJikokuOrder ;	//	�t�H�[�J�X�Z���̎���Order
	if ( iRv >= 0 )
	{
		iRessyaIndex = getCWndDcdGrid()->getXColSpecOfFocus().getRessyaIndex() ;

		if ( 0 <= iRessyaIndex 
				&& iRessyaIndex < pCentDedRessyaCont->getMuPtr()->size() )
		{
			pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( iRessyaIndex ) ;
		}
		else
		{
			iRv = -1 ;	//	�t�H�[�J�X�Z�����A��Ԃ̈ʒu�ł͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	�t�H�[�J�X�Z�����A�w�����̈ʒu�ł͂���܂���B
		}
	}
	//iRessyaIndex = �t�H�[�J�X�Z���̗��Index
	//pCentDedRessya = �t�H�[�J�X�Z���̗�ԃI�u�W�F�N�g
	//aJikokuOrder = �t�H�[�J�X�Z���̎���Order

	// --------------------------------
	//  ��[�t�H�[�J�X�ʒu�̉w����Ourder�ȑO�ɁA�w�����̓��͂��ꂽ�w������Ȃ�]Ressyahensyu�ɑJ��
	if ( iRv >= 0 )
	{
		CdDedJikokuOrder	aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
			pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
		if ( aJikokuOrderRev.getIsNull() )
		{
			iRv = -3 ;	//	�t�H�[�J�X�ʒu�̉w����Ourder�ȑO�ɁA�w�����̓��͂��ꂽ�w������Ȃ�
		}
	}
	// --------------------------------
	return ( iRv ) ;		
}

void CWjkState_Renzoku::onEnter() 
{
	int iRv = 0 ;

	//	�I��͈͂̐ݒ�
	getCWndDcdGrid()->getCSelect()->setSelectMode( CSelect::SelectMode_NONE ) ;

	//	
	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	const Mu<const CentDedRessya*>* pMuCentDedRessya = pCentDedRessyaCont->getMuPtr() ;
	CdDcdPosXy	posFocusCell = getCWndDcdGrid()->getCFocus()->getFocusCellColumnNumber() ;
	// --------------------------------
	int iRessyaIndex = -1 ;		//	�t�H�[�J�X�Z���̗��Index
	const CentDedRessya* pCentDedRessya = NULL ;	//	�t�H�[�J�X�Z���̗�ԃI�u�W�F�N�g
	CdDedJikokuOrder aJikokuOrder ;	//	�t�H�[�J�X�Z���̎���Order
	if ( iRv >= 0 )
	{
		iRessyaIndex = getCWndDcdGrid()->getXColSpecOfFocus().getRessyaIndex() ;

		if ( iRessyaIndex >= 0 )
		{
			pCentDedRessya = pMuCentDedRessya->get( iRessyaIndex ) ;
		}
		else
		{
			iRv = -1 ;	//	�t�H�[�J�X�Z�����A��Ԃ̈ʒu�ł͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	�t�H�[�J�X�Z�����A�w�����̈ʒu�ł͂���܂���B
		}
	}
	//iRessyaIndex = �t�H�[�J�X�Z���̗��Index
	//pCentDedRessya = �t�H�[�J�X�Z���̗�ԃI�u�W�F�N�g
	//aJikokuOrder = �t�H�[�J�X�Z���̎���Order

	// --------------------------------
	//  ��[�t�H�[�J�X�ʒu�̉w����Ourder�ȑO�ɁA�w�����̓��͂��ꂽ�w������Ȃ�]Ressyahensyu�ɑJ��
	if ( iRv >= 0 )
	{
		CdDedJikokuOrder	aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
			pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
		if ( aJikokuOrderRev.getIsNull() )
		{
			iRv = -3 ;	//	�t�H�[�J�X�ʒu�̉w����Ourder�ȑO�ɁA�w�����̓��͂��ꂽ�w������Ȃ�
		}
	}
	// --------------------------------
	if ( iRv >= 0 )
	{
		//	�A�����̓��[�h�ɓ�������A
		//	IME��OFF�ɂ��܂��B
		ImeControl( getCWndDcdGrid()->GetSafeHwnd() , FALSE ) ;

		m_iXColumnNumberFocus = posFocusCell.getX() ;

		update() ;
	}
	else
	{
		//	����Ɏ��s������A
		//	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		//	�ɑJ�ڂ��܂��B
		getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
	}

}
void CWjkState_Renzoku::onExit() 
{
	//	��ʂ̍X�V(�ҏW���}�[�N���N���A���܂�)
	update_updateScreen( true ) ;

	m_iXColumnNumberFocus = -1 ;
	m_strMinutes.clear() ;
}


	// ********************************
	//@name CView ����̈Ϗ�
	// ********************************
void CWjkState_Renzoku::
OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC ){
		return ;
	}

	//	���̃r���[����A�N�e�B�u�ŁA�S�X�V���v������Ă���ꍇ��
	//	�X�V�͍s���܂���B
	CView *pActiveView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	if ( pActiveView != getCWndDcdGrid()->GetParent() && getCWndDcdGrid()->getUpdate_All_Requested() )
	{
		//	���̃r���[����A�N�e�B�u�ŁA�S�X�V���v������Ă���ꍇ��
		//	���ׂĂ̍X�V���s���܂���B
		//	�܂��A��ԑI�����[�h�͑ޏꂵ�܂��B
		getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
	}
	else
	{
		bool bUpdateComplete = false ;
		// --------------------------------
		//	CRfEditCmd �ɍœK�����ꂽ�X�V
		// --------------------------------
		Ou<CRfEditCmd> pCmd ;
		if ( pHint != NULL && pHint->IsKindOf( RUNTIME_CLASS( CRfEditCmdHolder ) ) )
		{
			CRfEditCmdHolder* pHolder = 
				(CRfEditCmdHolder*)pHint ;
			pCmd = pHolder->getCmd() ; 
		}
		if ( pCmd != NULL )
		{
			if ( dynamic_castOu<CRfEditCmd_Comment>( pCmd ) || 
				dynamic_castOu<CRfEditCmd_Dia>( pCmd ) || 
				dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) || 
				dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd )
				) 
			{
				//	���̃r���[�́A
				//		�R�����g�̕ύX
				//		�_�C���̕ύX
				//		�_�C���̃v���p�e�B�̕ύX
				//		��Ԏ�ʂ̓���
				//	�̏ꍇ�́A�X�V�̕K�v������܂���B
				bUpdateComplete = true ;
			}
			else if ( dynamic_castOu<CRfEditCmd_Ressya>( pCmd )	) 
			{
				//	��Ԃ̕ύX
				Ou<CRfEditCmd_Ressya>	pCommand = dynamic_castOu<CRfEditCmd_Ressya>( pCmd );
				if ( pCommand->getSizeDst() == pCommand->getCentDedRessyaContSrc()->size() )
				{
					//	������Ԃ̒u����(��Ԃ̒ǉ��E�폜�Ȃ�)�̏ꍇ�����A
					//	���̏�Ԃŏ������܂��B
					OnUpdate_CentDedRessya( pCommand ) ;
					bUpdateComplete = true ;
				}
			}
			else
			{
				//CRfEditCmd_Eki
				//	�w�̕ύX�́A�S�X�V���K�v�ł��B
				//CRfEditCmd_Ressyasyubetsu
				//	��Ԏ�ʂ̕ύX�́A�S�X�V���K�v�ł��B
				//CRfEditCmd_DedRosenFileDataProp
				//	  �H���t�@�C���̃v���p�e�B�̕ύX�́A
				//	�t�H���g�̕ω��𔺂����߁A�S�X�V���K�v�ł��B
				//CRfEditCmd_Rosen
				//CRfEditCmd_RosenFileData
				//	�w���܂���I�u�W�F�N�g�ł��B���ꂪ�X�V���ꂽ�ꍇ�́A
				//	�S�X�V���K�v�ł��B
				//CRfEditCmd_RessyaDirect
				//	��Ԃ̒��ʉ��́A��Ԗ{���̑������������邽�߁A
			}
		}
		if ( !bUpdateComplete )
		{
			//	�œK���X�V�ȊO
			//	���[�h���w��ԕҏW�x�ɑJ�ڂ����āA
			//	OnUpdate() ���Ϗ����܂��B
			getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
				CWndJikokuhyou::StateIdx_Ressyahensyu ) ;

			//CWjkState* pCState = 
			//	getCWndDcdGrid()->getCStateContGet()->
			//	get( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
			//pCState->OnUpdate( pSender, lHint, pHint) ;

			OnUpdate_All() ;
		}
	}
	// --------------------------------
	//	��I��͈͂�ݒ�
	// --------------------------------
	{
		//	�A�����̓��[�h�ł́A�I���͋֎~
		getCWndDcdGrid()->getCSelect()->setSelectMode( CSelect::SelectMode_NONE ) ;
	}

	// --------------------------------
	//	�J�����g��̍X�V
	// --------------------------------
	{
		update_updateScreen() ;
	}

	super::OnUpdate(pSender,  lHint,  pHint) ;
}

// ********************************
//@name ���b�Z�[�W�n���h���E�R�}���h�n���h��
// ********************************
/**
*	�����̕����񂪉��������͂���Ă��邩��Ԃ��܂��B
*	�i�����̕�����́A " 000" �� "0000" �̌`���̂S�o�C�g�ŁA
*	�����͂̈ʒu�ɂ̓X�y�[�X�������Ă��܂��B�i��:" 0  " �E" 90 " �j�j
*/
static int JikokuLen( const string& aString )
{
	if ( aString[2] == ' ' )
	{
		return 2 ;
	}
	else if ( aString[3] == ' ' )
	{
		return 3 ;
	}
	return 4 ;
}

	// ********************************
	//@name ���b�Z�[�W�n���h���E�R�}���h�n���h��-CWnd
	// ********************************
void CWjkState_Renzoku::
OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int iRv = 0 ;

	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , &pCmd ) )
		{
			iRv = -1 ;	//	�t�H�[�J�X�Z������Ԃ̈ʒu�ł͂���܂���B
		}
	}
	CdDedJikokuOrder aJikokuOrder ;
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	�t�H�[�J�X�Z�����w�����̈ʒu�ł͂���܂���B
		}
	}

	// ****************************************************************
	//	�ҏW�̎��s
	// ****************************************************************

	// --------------------------------
	//	���͂��ꂽ�L�[���̉��ߏ���
	// --------------------------------
	if ( iRv >= 0 )
	{
		//	���̓��͒��̃o�b�N�X�y�[�X�����͒��̕������
		if ( nChar == VK_BACK && m_strMinutes.length() >= 1 )
		{
			m_strMinutes.erase( m_strMinutes.length() - 1 , 1 ) ;

			//	�����̐��K���ƁA��ʂ̍X�V
			update() ;
		}
		//	���̓��͂��Ȃ���Ԃł̃o�b�N�X�y�[�X���O�̉w�ɖ߂�
		else if ( nChar == VK_BACK && m_strMinutes.length() == 0 )
		{
			//	�o�b�N�X�y�[�X
			// --------------------------------
			//	�t�H�[�J�X���ړ�
			// --------------------------------
			//	startFocusCell() �ŁA�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
			//	���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
			//	���[�h��
			//	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
			//	�ɑJ�ڂ��܂��B
			CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , -1 ) ;
			if ( pcellNext != NULL )
			{
				getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
			}
			else
			{
				//	�t�H�[�J�X���w�����O�ɂȂ�����A��ԕҏW���[�h�ɑJ��
				getCWndDcdGrid()->getStateMachine()
					->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
			}

			//	�����̐��K���ƁA��ʂ̍X�V
			update() ;
		}
		//	ESC�L�[�Ȃ�A�A�����͂�ޏ�
		else if ( nChar == VK_ESCAPE )
		{	
			//	ESC
			getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
				CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}
		else
		{
			super::OnKeyDown(  nChar , nRepCnt , nFlags  ) ;
		}
	}
	if ( iRv >= 0 )
	{
		return ;
	}
	super::OnKeyDown(  nChar , nRepCnt , nFlags  ) ;
}

void CWjkState_Renzoku::
OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int iRv = 0 ;

	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , &pCmd ) )
		{
			iRv = -1 ;	//	�t�H�[�J�X�Z������Ԃ̈ʒu�ł͂���܂���B
		}
	}
	CdDedJikokuOrder aJikokuOrder ;
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	�t�H�[�J�X�Z�����w�����̈ʒu�ł͂���܂���B
		}
	}
	int iRessyaIndex = -1 ;
	if ( iRv >= 0 )
	{
		CdXColSpec aCdXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
		if ( aCdXColSpec.getColumnType() == CdXColSpec::ColumnType_Ressya )
		{
			iRessyaIndex = aCdXColSpec.getRessyaIndex() ;
		}
		else
		{
			iRv = -1 ;	//	�t�H�[�J�X�Z������Ԃ̈ʒu�ł͂���܂���B
		}
	}
	//iRessyaIndex = �t�H�[�J�X�Z���̗��Index
	//aCdJikokuOrder = �w��̃Z���ɑΉ�����w����Order�x
	// ****************************************************************
	//	�ҏW�̎��s
	// ****************************************************************
	CentDedRessya* pCentDedRessya = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 
	}
	CdDedJikokuOrder	aJikokuOrderRev ;	//	���O�w�̉w����Order
	CdDedJikoku	jikokuRev ;					//	���O�w�̉w����
	if ( iRv >= 0 )
	{
		aJikokuOrderRev = pCentDedRessya->findrevJikoku( 
			pCentDedRessya->decJikokuOrder( aJikokuOrder ) ) ;
		if ( aJikokuOrderRev.getIsNull() )
		{
			iRv = -3 ;	//	�t�H�[�J�X�ʒu�̉w����Ourder�ȑO�ɁA�w�����̓��͂��ꂽ�w������Ȃ�
		}
		else
		{
			jikokuRev = pCentDedRessya->getEkiJikoku( aJikokuOrderRev ) ;
		}
	}
	//aJikokuOrderRev =	//	���O�w�̉w����Order
	//jikokuRev = 		//	���O�w�̉w����
	// --------------------------------
	//	���͂��ꂽ�L�[���̉��ߏ���
	// --------------------------------
	if ( iRv >= 0 )
	{
		//	���̓��͂��Ȃ���ԁ�10�̈ʂ̓��͂���t
		if ( m_strMinutes.length() == 0  && '0' <= nChar && nChar <= '5' )
		{
			//	���̂P�O�̈ʂ����͂���܂����B
			m_strMinutes += nChar ;

			//	�����̐��K���ƁA��ʂ̍X�V
			update() ;
		}
		//	10�̈ʂ̂����͂��ꂽ��ԁ�1�̈ʂ̓��͂���t
		else if ( m_strMinutes.length() == 1 && 
			( '0' <= nChar && nChar <= '9' ) )
		{
			//	���̂P�̈ʂ����͂���܂����B
			m_strMinutes += nChar ;

			CdDedJikoku	jikokuCurrent(
				jikokuRev.getHour() ,
				intOf( m_strMinutes ) ,
				0 ) ;

			//	���͂��ꂽ�������O�̉w�̎�����菬�����ꍇ�́A
			//	���͎����ɂP���Ԃ����Z���܂��B
			CdDedJikan	jikanSub = jikokuCurrent.subJikoku( 
				jikokuRev ) ;
			if ( jikanSub.getTotalSeconds() < 0 )
			{
				jikokuCurrent = jikokuCurrent.getTotalSeconds() + 60*60 ;
			}


			// --------------------------------
			//	��Ԃ��擾���āA�ҏW
			// --------------------------------
			//	���͂��ꂽ������ݒ�
			pCentDedRessya->setEkiJikoku( jikokuCurrent , aJikokuOrder ) ;

			//	�w�����ԂɕύX
			{
				CentDedEkiJikoku aCentDedEkiJikoku =
					pCentDedRessya->getCentDedEkiJikoku( aJikokuOrder.getEkiOrder() ) ;
				aCentDedEkiJikoku.setEkiatsukai( 
					CentDedEkiJikoku::Ekiatsukai_Teisya ) ;
				pCentDedRessya->setCentDedEkiJikoku( aJikokuOrder.getEkiOrder() , 
					aCentDedEkiJikoku ) ;
			}
			//pCentDedRessya = �擾������Ԃ̃R�s�[�ɑ΂��āA
			//	�w�����̕ҏW���s���܂����B

			// --------------------------------
			//	�R�}���h�I�u�W�F�N�g�����s
			// --------------------------------
			{
				getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			}

			// --------------------------------

			//	�����폜
			m_strMinutes.clear()  ;

			// --------------------------------
			//	�t�H�[�J�X���ړ�
			// --------------------------------
			//	startFocusCell() �ŁA�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
			//	���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
			//	���[�h��
			//	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
			//	�ɑJ�ڂ��܂��B
			CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
			if ( pcellNext != NULL )
			{
				getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
			}
			else
			{
				//	�t�H�[�J�X���w�����O�ɂȂ�����A��ԕҏW���[�h�ɑJ��
				getCWndDcdGrid()->getStateMachine()
					->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
			}

			// --------------------------------
			//	�����̐��K���ƁA��ʂ̍X�V
			update() ;
		}
		else
		{
			super::OnChar(  nChar , nRepCnt , nFlags  ) ;
		}

	}
	if ( iRv >= 0 )
	{
		return ;
	}

	super::OnChar(  nChar , nRepCnt , nFlags  ) ;
}

// --------------------------------
int CWjkState_Renzoku::
	OnJikokuhyouJikokuSakujo_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ��B
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		{
			CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 


			//	�t�H�[�J�X�̂���w�̉w�������w��ԁx�ɕύX���A
			//	�t�H�[�J�X�̂��鎞����NULL�����ɂ��܂��B
			//
			//	����ɔ����āA���E���Ƃ�NULL�����ɂȂ�ƁA�w���� Ekiatsukai_None 
			//	�ɂȂ�܂��B
			CentDedEkiJikoku aCentDedEkiJikoku =
				pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;

			aCentDedEkiJikoku.setEkiatsukai( 
				CentDedEkiJikoku::Ekiatsukai_Teisya )	 ;
			if ( aCdYColSpec.getColumnType() == CdYColSpec::ColumnType_Ekijikoku_Chaku )
			{	//	�������̏���
				aCentDedEkiJikoku.setChakujikoku( CdDedJikoku() ) ;
			}
			else
			{	//	�������̏���
				aCentDedEkiJikoku.setHatsujikoku( CdDedJikoku() ) ;
			}
			//	����ɔ����āA���E���Ƃ�NULL�����ɂȂ�ƁA�w���� Ekiatsukai_None 
			//	�ɂȂ�܂��B
			if ( aCentDedEkiJikoku.getChakujikoku().isNull() && 
				aCentDedEkiJikoku.getHatsujikoku().isNull() )
			{
				aCentDedEkiJikoku.setEkiatsukai( 
					CentDedEkiJikoku::Ekiatsukai_None )	 ;
			}
			pCentDedRessya->setCentDedEkiJikoku( aCdYColSpec.getEkiOrder() , aCentDedEkiJikoku ) ;
			
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		//	startFocusCell() �ŁA�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
		//	���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
		//	���[�h��
		//	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		//	�ɑJ�ڂ��܂��B
		CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
		if ( pcellNext != NULL )
		{
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
		}
		else
		{
			//	�t�H�[�J�X���w�����O�ɂȂ�����A��ԕҏW���[�h�ɑJ��
			getCWndDcdGrid()->getStateMachine()
				->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}

		//	�����̐��K���ƁA��ʂ̍X�V
		update() ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Renzoku::
	OnJikokuhyouTsuuka_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ��B
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		{
			CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 

			CentDedEkiJikoku aCentDedEkiJikoku =
				pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;
			aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Tsuuka ) ;

			//	�w������NULL�ɂ���
			aCentDedEkiJikoku.setChakujikoku( CdDedJikoku() ) ;
			aCentDedEkiJikoku.setHatsujikoku( CdDedJikoku() ) ;

			pCentDedRessya->setCentDedEkiJikoku( aCdYColSpec.getEkiOrder() , aCentDedEkiJikoku ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		//	startFocusCell() �ŁA�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
		//	���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
		//	���[�h��
		//	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		//	�ɑJ�ڂ��܂��B
		CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
		if ( pcellNext != NULL )
		{
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
		}
		else
		{
			//	�t�H�[�J�X���w�����O�ɂȂ�����A��ԕҏW���[�h�ɑJ��
			getCWndDcdGrid()->getStateMachine()
				->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}

		//	�����̐��K���ƁA��ʂ̍X�V
		update() ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Renzoku::
	OnJikokuhyouTsuukateisya_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ��B
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		{
			CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 
			CentDedEkiJikoku aCentDedEkiJikoku =
					pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;
			
			if ( aCentDedEkiJikoku.getEkiatsukai() == CentDedEkiJikoku::Ekiatsukai_Tsuuka )
			{
				//�t�H�[�J�X�Z���̈ʒu���w�ʉ߁x�Ȃ�΁w��ԁx�ɕύX���܂��B�w�����͕ύX���܂���B
				aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Teisya ) ;
			}
			else
			{
				//�t�H�[�J�X�Z���̈ʒu�́w�w�����x���w��ԁx�w�^�s�Ȃ��x�w�o�R�Ȃ��x�Ȃ�A
				//�w�ʉ߁x�ɕύX���܂��B�w�����͕ύX���܂���B
				aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Tsuuka ) ;
			}

			pCentDedRessya->setCentDedEkiJikoku( aCdYColSpec.getEkiOrder() , aCentDedEkiJikoku ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		//	startFocusCell() �ŁA�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
		//	���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
		//	���[�h��
		//	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		//	�ɑJ�ڂ��܂��B
		CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
		if ( pcellNext != NULL )
		{
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
		}
		else
		{
			//	�t�H�[�J�X���w�����O�ɂȂ�����A��ԕҏW���[�h�ɑJ��
			getCWndDcdGrid()->getStateMachine()
				->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}

		//	�����̐��K���ƁA��ʂ̍X�V
		update() ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
		
	
}


int CWjkState_Renzoku::
	OnJikokuhyouKeiyunasi_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Focus , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdDedJikokuOrder	aJikokuOrder ;
	if ( iRv >= 0 )
	{
		aJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	�t�H�[�J�X�Z�����w�����̈ʒu�ł͂���܂���B
		}
	}
	CdYColSpec	aCdYColSpec ;
	if ( iRv >= 0 )
	{
		aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( !aCdYColSpec.isEkiJikoku() )
		{
			iRv = -1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ��B
		}
	}
	// --------------------------------
	//����12.3���A�����͎���[����]�\���̉w�̔������ɑ΂���
	//	[�o�R�Ȃ�]�R�}���h����𖳌��ɂ���
	// --------------------------------
	//�@�]���A�����\�r���[�̘A�����̓��[�h�ŁA�����\���̉w��
	//	���Ɏ���������
	//	����[�o�R�Ȃ�]���w�肷��
	//�ƁA�������Ɠ����ɒ�������[�o�R�Ȃ�]�ɂ���Ď�����������Ă��܂���肪����܂����@
	//�@���������邽�߁A�����\�r���[�̘A�����̓��[�h���ɂ́A�ȉ��̃��[����K�p���܂��B
	//�@�t�H�[�J�X�Z���ʒu��[����]�\���̉w��[������]�ɂ����ԂŁA
	//	���j���[�R�}���h[�w����]�|[�o�R�Ȃ�]�i�܂��́A "=" �L�[�j����͂����Ƃ��A���̉w�̉w������
	//	[�o�R�Ȃ�]�ɂ��܂���i�ύX���s���܂���j�B���̂Ƃ��A�t�H�[�J�X�Z���͎��̉w�Ɉڂ��܂��B
	bool bSkip = false ;
	if ( iRv >= 0 ){
		const Mu<CentDedEkiCont::CdDedEki>* pCdDedEkiContGet = 
			getCDiagramEditDoc()->getCDedRosenFileData()->
			getCentDedRosen()->getCentDedEkiCont()->getMuPtr( getRessyahoukou() ) ;
		CentDedEkiCont::CdDedEki	aCdDedEki = pCdDedEkiContGet->get( aJikokuOrder.getEkiOrder() ) ;
		if ( aCdDedEki.isHatsuChakuHyouji() && 
			aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Hatsu )
		{
			bSkip = true ;
		}
	}
	//bSkip = ����̃t�H�[�J�X�Z���ɑ΂���@[�o�R�Ȃ�]��
	//	�����Ƃ��܂��i�t�H�[�J�X�͎��Ɉڂ��܂��j�B

	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		if ( !bSkip )
		{
			// --------------------------------
			//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
			// --------------------------------
			{
				CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ; 

				CentDedEkiJikoku aCentDedEkiJikoku =
						pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;

				aCentDedEkiJikoku.setEkiatsukai( 
					CentDedEkiJikoku::Ekiatsukai_Keiyunasi ) ;

				pCentDedRessya->setCentDedEkiJikoku( aCdYColSpec.getEkiOrder() , aCentDedEkiJikoku ) ;
			}			
			// --------------------------------
			//	�R�}���h�I�u�W�F�N�g�����s
			// --------------------------------
			{
				getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			}
		}
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		//	startFocusCell() �ŁA�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
		//	���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
		//	���[�h��
		//	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		//	�ɑJ�ڂ��܂��B
		CDcdGridCell* pcellNext = calcCellToNext( getCWndDcdGrid()->getCFocus()->getFocusCell() , +1 ) ;
		if ( pcellNext != NULL )
		{
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNext ) ;
		}
		else
		{
			//	�t�H�[�J�X���w�����O�ɂȂ�����A��ԕҏW���[�h�ɑJ��
			getCWndDcdGrid()->getStateMachine()
				->setCurrentStateIdx( CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		}

		//	�����̐��K���ƁA��ʂ̍X�V
		update() ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;				


}



int CWjkState_Renzoku::
	OnJikokuhyouRenzoku_Process( BOOL bQueryEnable )
{
	int iRv = 1 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	CWjkState* pCState = 
		getCWndDcdGrid()->getStateMachine()->getCStateContGet()->get( 
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
	int iResult = pCState->canEnter() ;
	if ( iResult < 0 )
	{
		iRv = -1 ;	//	���݁A���̃R�}���h�͑I���ł��܂���
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		getCWndDcdGrid()->getStateMachine()->setCurrentStateIdx( 
			CWndJikokuhyou::StateIdx_Ressyahensyu ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;
}


	// ********************************
	//@name	CWndDcdGrid
	// ********************************
void CWjkState_Renzoku::OnSetFocusCell( 
	CDcdGridCell* pCDcdGridCell ) 
{
	//	�t�H�[�J�X�Z�����ړ������ꍇ�́A
	//	���͒��̕��̓N���A
	m_strMinutes.clear() ;

	update() ;
	super::OnSetFocusCell( pCDcdGridCell ) ; 
} 

void CWjkState_Renzoku::OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) 
{
	super::OnChangeSelectCell( 
		iXColumnNumber , iYColumnNumber , bIsSelected ); 
}

} } // namespace WndJikokuhyou namespace ViewJikokuhyou
