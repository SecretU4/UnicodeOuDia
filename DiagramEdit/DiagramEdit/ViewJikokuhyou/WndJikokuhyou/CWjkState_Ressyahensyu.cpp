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
//	CWjkState_Ressyahensyu.cpp
// $Id: CWjkState_Ressyahensyu.cpp 357 2016-08-18 16:59:16Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"



#include "logmsg/LogMsg.h"
#include "DcDraw/CDcdLine.h"
#include "NsOu/OuNew.h"
#include "NsOu/dynamic_castOu.h"
#include "NsMu\CaMui.h"

#include "CWjkState_Ressyahensyu.h"
#include "CWjkState_Renzoku.h"
#include "..\..\DiagramEdit.h"
#include "..\CDlgRessyaProp.h"
#include "..\CDlgEkiJikokuProp.h"
#include "..\CDlgModifyEkijikokuOperation2.h"
#include "..\..\CRfEditCmdHolder.h"
#include "..\..\DedRosenFileData\EditCmd\EditCmd.h"

#include "..\..\entDed\CDedRessyaSoater_Ressyasyubetsu.h"
#include "..\..\entDed\CDedRessyaSoater_Bikou.h"
#include "..\..\entDed\CDedRessyaSoater_Ekiatsukai.h"
#include "..\..\entDed\CRessyaContUnifier.h"
#include "..\..\entDgr\CDedRessyaSoater_Transfer.h"

#include "..\..\CDlgProgress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



namespace ViewJikokuhyou{ namespace WndJikokuhyou{

// ****************************************************************
//	CWjkState_Ressyahensyu
// ****************************************************************
// --------------------------------
//@name OnUpdate�����֐�
// --------------------------------
void CWjkState_Ressyahensyu::OnUpdate_All() 
{
	LogMsg( "CWjkState_Ressyahensyu::OnUpdate_All()" ) ;
 
	getCWndDcdGrid()->updateUIAll() ;

	LogMsg( "CWjkState_Ressyahensyu::OnUpdate_All()=" ) ;
}


void CWjkState_Ressyahensyu::OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) 
{
	int iDiaIndex = GetDocument()->getDiaIndex() ;
	if ( !( pCommand->getDiaIndex() == iDiaIndex && 
		pCommand->getRessyahoukou() == GetDocument()->getRessyahoukou() ) )
	{
		return ;
	}
	//	��Ԃ̃Z����u������
	getCWndDcdGrid()->updateUI_ReplaceRessya( 
		pCommand->getIndexDst() ,
		pCommand->getSizeDst() ,
		pCommand->getCentDedRessyaContSrc()->size() ) ;

}



int CWjkState_Ressyahensyu::
		execJikokuhyouPropDlg( bool bInsert , BOOL bQueryEnable  ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	
	//iType = { 0: �w�����̕ҏW,1: ��Ԃ̕ҏW,2;�w�̕ҏW } 
	int iType = -1 ;

	if ( iRv >= 0 && iType == -1 )
	{
		//	�w�v���p�e�B�_�C�A���O�̎g�p�𔻒�
		int iResult = execCDlgEkiProp( TRUE ) ;
		if ( iResult >= 0 )
		{
			iType = 2;	//	�w�̕ҏW
		}
	}
	if ( iRv >= 0 && iType == -1 )
	{
		int iResult = execCDlgEkijikokuProp( bInsert , TRUE ) ;
		if ( iResult >= 0 )
		{	
			iType = 0 ;	// �w�����̕ҏW
		}
	}
	if ( iRv >= 0 && iType == -1 )
	{
		int iResult = execCDlgRessyaProp( bInsert , TRUE ) ;
		//iResult = 
 		//	-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
 		//	-	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A
 		//		//	�ύX�͔������܂���ł����B
 		//	-	-1 ;	//	X��ԍ����s���ł��B
 		//	-	-2 ;	//	Y��ԍ����s���ł��B
		if ( iResult >= 0 )
		{	
			iType = 1 ;	// ��Ԃ̕ҏW
		}
		else
		{
			iRv = iResult ;
		}
	}
	//iType = { 0: �w�����̕ҏW,1: ��Ԃ̕ҏW,2;�w�̕ҏW } 
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		if ( iType == 2 ) //	2;�w�̕ҏW
		{
			iRv = execCDlgEkiProp( FALSE ) ;
		}
		if ( iType == 1 ) //	1: ��Ԃ̕ҏW
		{
			// --------------------------------
			//	�w��ԃv���p�e�B�x�_�C�A���O���J��
			// --------------------------------
			iRv = execCDlgRessyaProp( bInsert , FALSE ) ;
			//iRv = 
	 		//	-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
	 		//	-	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A@n
	 		//			�ύX�͔������܂���ł����B
	 		//	-	-1 ;	//	X��ԍ����s���ł��B
		}
		if ( iType == 0 )	//0: �w�����̕ҏW,, } 
		{
			// --------------------------------
			//	�w�w�����̃v���p�e�B�x�_�C�A���O���J��
			// --------------------------------
			iRv = execCDlgEkijikokuProp( bInsert , FALSE ) ;
			//iRv = 
	 		//	-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
	 		//	-	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A
	 		//		//	�ύX�͔������܂���ł����B
	 		//	-	-1 ;	//	X��ԍ����s���ł��B
	 		//	-	-2 ;	//	Y��ԍ����s���ł��B
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;
}


int CWjkState_Ressyahensyu::
	execCDlgRessyaProp( bool bInsert , BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( bInsert )
		{
			if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_NewItem , ppCmd ) )
			{
				iRv = -1 ;	//	��ԑI���ʒu������������܂���B
			}
		}
		else
		{
			if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
			{
				iRv = -1 ;	//	��ԑI���ʒu������������܂���B
			}
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�w��ԃv���p�e�B�x�_�C�A���O���J��
		// --------------------------------
		CdYColSpecCont	aYColSpecCont
			= getCWndDcdGrid()->createYColSpecCont() ;

		int iFocus = getCWndDcdGrid()->getCFocus()
			->getFocusCellColumnNumber().getY() + 1 ;
		CdYColSpec	aYColSpec = 
			getCWndDcdGrid()->getYColSpecOfFocus() ;
		if ( aYColSpec.getColumnType() 
			== CdYColSpec::ColumnType_Gou )
		{
			iFocus = 4	;	//	����
		}
		if ( aYColSpec.getColumnType() 
			== CdYColSpec::ColumnType_Bikou )
		{
			iFocus = 5	;	//	���l
		}

		CDlgRessyaProp	aDlg( 
			bInsert , 
			pCmd->getCaMuiSelect()->getMuPtr() , 
			iFocus , 
			&m_CKeyinputSenderToModalDlg , 
			getCWndDcdGrid() );
		if ( aDlg.DoModal() == IDOK )
		{
			iRv = 1 ;
		}
		//iRv = 
		//	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
		//	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A
		//		//	�ύX�͔������܂���ł����B
		//pCentDedRessyaSelectedCont = 
		//	�_�C�A���O��OK�ŏI�������ꍇ�́A
		//	pCentDedRessyaSelectedCont->m_pRessyaContAdaptee ��
		//	���e���ύX����Ă��܂��B


		// --------------------------------
		//	�_�C�A���OOK���̏���
		// --------------------------------
		if ( iRv == 1 )
		{
			// --------------------------------
			//	�ҏW�R�}���h�����s
			// --------------------------------
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;

			// --------------------------------
			//	�t�H�[�J�X�Z�����A�V�ݗ�Ԃ̎n���w��
			//	�ڂ��܂��B
			// --------------------------------
			if ( bInsert )
			{
				//	�t�H�[�J�X�Z�����A�V�ݗ�Ԃ�X��Ɉړ�
				CDcdGridCell*	pCell = getCWndDcdGrid()->
					getCXDcdGrid()->calcMovedCell( 
						getCWndDcdGrid()->getCFocus()->getFocusCell() , 
						-1 , 
						0 ) ;
				if ( pCell )
				{
					getCWndDcdGrid()->getCFocus()->setFocusCell( pCell ) ;
				}
			}

			// --------------------------------
			//	�t�H�[�J�X�Z����Y��ԍ���
			//	��Ԕԍ��E��Ԏ�ʁE��Ԗ��E�����E���l��
			//	�����ꂩ�ɂ���ꍇ�����A���̈ʒu�Ƀt�H�[�J�X��
			//	�ړ����܂��B
			// --------------------------------
			{
				CdYColSpecCont	aYColSpecCont
					= getCWndDcdGrid()->createYColSpecCont() ;

				int iYColumnNumber = getCWndDcdGrid()->getCFocus()
					->getFocusCellColumnNumber().getY() ;
				if ( !( aYColSpecCont.getColumnNumber_Ekijikoku_begin() 
						<= iYColumnNumber && 
						iYColumnNumber 
						 < aYColSpecCont.getColumnNumber_Ekijikoku_end()
				) )
				{
					moveFocusCellToNext( true ) ;
				}
			}
		}
		
	}
	return iRv ;
}

int  CWjkState_Ressyahensyu::
	execCDlgEkiProp( BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	int iEkiIndex = -1 ;
	{
		CdXColSpec	aXColSpecFocus = 
			getCWndDcdGrid()->getXColSpecOfFocus() ;
		CdYColSpec	aYColSpecFocus = 
			getCWndDcdGrid()->getYColSpecOfFocus() ;
		if (  
			( aXColSpecFocus.getColumnType() == 
				CdXColSpec::ColumnType_Ekimei ||
			  aXColSpecFocus.getColumnType() == 
				CdXColSpec::ColumnType_Chakuhatsu ) && 
			aYColSpecFocus.getEkiOrder() >= 0 
		)
		{
			const CentDedEkiCont* pCentDedEkiCont = 
				getCDiagramEditDoc()->getCDedRosenFileData()
				->getCentDedRosen()->getCentDedEkiCont() ;
			iEkiIndex = pCentDedEkiCont->EkiOrderOfEkiIndex( 
				getCWndDcdGrid()->getRessyahoukou() ,
				aYColSpecFocus.getEkiOrder() ) ;
		}
		else
		{
			iRv = -1 ;	//	�Z���̈ʒu���w���ł͂���܂���B
		}
	}
	//iEkiIndex = �wIndex
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		CEkiView* pCEkiView = NULL ;
		getCDiagramEditApp()->openCEkiDoc( &pCEkiView ) ;
		if ( pCEkiView != NULL )
		{
			pCEkiView->openCDlgEkiProp( iEkiIndex ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;
}



int CWjkState_Ressyahensyu::
	execCDlgEkijikokuProp( bool bInsert , BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	CdDedJikokuOrder	aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		if ( bInsert )
		{
			if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_NewItem , ppCmd ) )
			{
				iRv = -1 ;	//	��ԑI���ʒu������������܂���B
			}
		}
		else
		{
			if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
			{
				iRv = -1 ;	//	��ԑI���ʒu������������܂���B
			}
		}
	}
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
				getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -2 ;	//	Y��ԍ����s���ł��B
		}
	}
	//aCdJikokuOrder = �ҏW�Ώۂ̎���Order�ł�

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�w�w�����̃v���p�e�B�x�_�C�A���O���J��
		// --------------------------------
		bool bJikokuModify = getCWndDcdGrid()->getModifyEkijikoku() ;

		CDlgEkijikokuProp	aDlg( 
			pCmd->getCaMuiSelect()->getMuPtr() , 
			&bJikokuModify ,
			aCdJikokuOrder.getEkiOrder() ,
			aCdJikokuOrder.getEkiJikokuItem() 
				== CdDedJikokuOrder::EkiJikokuItem_Hatsu ? 2 : 1  , 
			&m_CKeyinputSenderToModalDlg ,  
			getCWndDcdGrid()  ) ;
		if ( aDlg.DoModal() == IDOK )
		{
			iRv = 1 ;
		}
		// --------------------------------
		//	�_�C�A���OOK���̏���
		// --------------------------------
		if ( iRv == 1 )
		{
			//	CWndJikokuhyou �I�u�W�F�N�g��
			//	�J�グ�E�J�����̐ݒ�𔽉f
			getCWndDcdGrid()->setModifyEkijikoku( bJikokuModify ) ;

			// --------------------------------
			//	�ҏW�R�}���h�����s
			// --------------------------------
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;

			// --------------------------------
			//	�t�H�[�J�X�Z�����ڂ��܂��B
			// --------------------------------
			if ( bInsert )
			{
				// --------------------------------
				//	�t�H�[�J�X�Z�����A�V�ݗ�Ԃ̎��̉w��
				//	�ڂ��܂��B
				// --------------------------------

				//	�t�H�[�J�X�Z�����A�V�ݗ�Ԃ�X��Ɉړ�
				{
					CDcdGridCell*	pCell = getCWndDcdGrid()->
						getCXDcdGrid()->calcMovedCell( 
							getCWndDcdGrid()->getCFocus()->getFocusCell() , 
							-1 , 
							0 ) ;
					if ( pCell ){
						getCWndDcdGrid()->getCFocus()->setFocusCell( pCell ) ;
					}
				}
				//	�t�H�[�J�X�Z�������ֈڂ��܂��B
				moveFocusCellToNext( true ) ;	
			}
			else 
			{
				//	�t�H�[�J�X�Z�������ֈڂ��܂��B
				moveFocusCellToNext( true ) ;
			}
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;

}

int CWjkState_Ressyahensyu::
	moveFocusCellToNext( bool bNextEkiOrder ) 
{
	int iRv = 0 ;
	iRv = getCWndDcdGrid()->moveFocusCellToNext( m_bJikokuhyouFocusMoveRight , bNextEkiOrder ) ;
	return iRv ;
}

int CWjkState_Ressyahensyu::
	moveFocusCellToPrev( bool bNextEkiOrder ) 
{
	int iRv = 0 ;
	iRv = getCWndDcdGrid()->moveFocusCellToPrev( m_bJikokuhyouFocusMoveRight , bNextEkiOrder ) ;
	return iRv ;
}

// ********************************
//	�R���X�g���N�^
// ********************************
CWjkState_Ressyahensyu::
	CWjkState_Ressyahensyu( 
		CWndJikokuhyou*	pCWndDcdGrid )
	: super( pCWndDcdGrid )
	, m_bJikokuhyouFocusMoveRight( false ) 
{
}
CWjkState_Ressyahensyu::
	~CWjkState_Ressyahensyu() 
{
}

	// ********************************
	//	CWjkState
	// ********************************
		// ********************************
		//@name ����
		// ********************************
void CWjkState_Ressyahensyu::onEnter() 
{

	//	�I��͈͂̐ݒ�
	getCWndDcdGrid()->getCSelect()->setSelectMode( CSelect::SelectMode_XColumn ) ;

	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	if ( pCentDedRessyaCont != NULL )
	{
		const Mu<const CentDedRessya*>* pMuCentDedRessyaCont = pCentDedRessyaCont->getMuPtr() ;
		getCWndDcdGrid()->getCSelect()->setColumnNumberSelectLimit(
			CdDcdZoneXy( 
				CdDcdZone( 2 , pMuCentDedRessyaCont->size() ) , 
				CdDcdZone( 0 , INT_MAX ) 
			) );
	}

	//	���̏�Ԃɓ��ꎞ�́A�S��ԑI��������
	getCWndDcdGrid()->clearSelect() ;
	

}
void CWjkState_Ressyahensyu::onExit() 
{
}

	// ********************************
	//@name CView ����̈Ϗ�
	// ********************************
void CWjkState_Ressyahensyu::
	OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC )
	{
		return ;
	}
	// --------------------------------
	//pHint= 
	//	pHint�� CRfEditCmdHolder �I�u�W�F�N�g�Ȃ�A
	//	�Ή�����ҏW�R�}���h CRfEditCmd ��ێ����Ă��܂��B
	//	���̏ꍇ�Athis �� CRfEditCmd �̓��e�ɍœK������
	//	�X�V���s���܂��B
	//	NULL�Ȃ�A�S�X�V���v������Ă��܂��B


	//	���̃r���[����A�N�e�B�u�ŁA�S�X�V���v������Ă���ꍇ��
	//	�X�V�͍s���܂���B
	CView *pActiveView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	if ( pActiveView != getCWndDcdGrid()->GetParent() && getCWndDcdGrid()->getUpdate_All_Requested() )
	{
		//	���̃r���[����A�N�e�B�u�ŁA�S�X�V���v������Ă���ꍇ��
		//	���ׂĂ̍X�V���s���܂���B
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
				//	�̏ꍇ�́A�X�V���s���܂���B
				bUpdateComplete = true ;
			}
			else if ( dynamic_castOu<CRfEditCmd_Ressya>( pCmd )	) 
			{
				//	��Ԃ̕ύX
				Ou<CRfEditCmd_Ressya>	pCommand = 
					dynamic_castOu<CRfEditCmd_Ressya>( pCmd );
				OnUpdate_CentDedRessya( pCommand ) ;
				bUpdateComplete = true ;
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
			}
		}
		// --------------------------------
		if ( !bUpdateComplete )
		{
			//	�S�v�f���X�V
			OnUpdate_All() ;
		}
	}

	// --------------------------------
	//	��I��͈͂�ݒ�
	// --------------------------------
	{
		getCWndDcdGrid()->getCSelect()->setSelectMode( CSelect::SelectMode_XColumn ) ;
		const Mu<const CentDedRessya*>* pMuCentDedRessyaCont = getCentDedRessyaCont()->getMuPtr() ;
		getCWndDcdGrid()->getCSelect()->setColumnNumberSelectLimit(
			CdDcdZoneXy( 
				CdDcdZone( 2 , pMuCentDedRessyaCont->size() ) , 
				CdDcdZone( 0 , INT_MAX ) 
			) );
	}

	super::OnUpdate(pSender,  lHint,  pHint) ;
}

	// ********************************
	//@name ���b�Z�[�W�n���h���E�R�}���h�n���h��-CWnd
	// ********************************
void CWjkState_Ressyahensyu::
	OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	LogMsg( "CWjkState_Ressyahensyu::OnKeyDown %02x %d %02x" , nChar , nRepCnt , nFlags ) ;

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	//	�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���Ƃ��́A
	//	�u�V�K��Ԃ̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdXColSpec aXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
	if ( aXColSpec.getColumnType() == CdXColSpec::ColumnType_NewRessya )
	{
		bInsert = true ;
	}	

	// ****************************************************************

	//	�����L�[��������Ă��āA�_�C�A���O�{�b�N�X���J���Ă��Ȃ��ꍇ��
	//	�_�C�A���O�{�b�N�X���J���܂��B
	if ( CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown() && 
			m_CKeyinputSenderToModalDlg.startSend() >= 0 )
	{
		m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) ;
		execJikokuhyouPropDlg( bInsert , FALSE ) ;
		m_CKeyinputSenderToModalDlg.endSend() ;
	}
	//	���łɃ_�C�A���O���N�������_�C�A���O�{�b�N�X�Ƀ��b�Z�[�W��]��
	else
	{
		if ( !m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) )
		{
			super::OnKeyDown(  nChar , nRepCnt , nFlags  ) ;
		}
	}
}

void CWjkState_Ressyahensyu::
	OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	LogMsg( "CWjkState_Ressyahensyu::OnKeyUp %02x %d %02x" , nChar , nRepCnt , nFlags ) ;

	{
		if ( !m_CKeyinputSenderToModalDlg.OnKeyUp( nChar , nRepCnt , nFlags ) )
		{
			super::OnKeyUp(  nChar , nRepCnt , nFlags  ) ;
		}
	}
}
void CWjkState_Ressyahensyu::
	OnLButtonDblClk(UINT nFlags, CPoint point)
{
	//	�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���Ƃ��́A
	//	�u�V�K��Ԃ̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdXColSpec aXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
	if ( aXColSpec.getColumnType() == CdXColSpec::ColumnType_NewRessya )
	{
		bInsert = true ;
	}	

	execJikokuhyouPropDlg( bInsert , FALSE ) ;
	super::OnLButtonDblClk(  nFlags , point ) ;
}

void CWjkState_Ressyahensyu::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	LogMsg( "CWjkState_Ressyahensyu::OnChar %02x %d %02x" , nChar , nRepCnt , nFlags ) ;

	{
		super::OnChar( nChar, nRepCnt, nFlags ) ;
	}
}

void CWjkState_Ressyahensyu::OnWM_IME_STARTCOMPOSITION() 
{
	{
		super::OnWM_IME_STARTCOMPOSITION() ;
	}
}

// --------------------------------
int CWjkState_Ressyahensyu::
OnEditCut_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�폜������Ԃ��擾
		// --------------------------------
		CentDedRessyaCont	aCentDedRessyaCont( getCentDedRessyaCont()->createEmptyCont() ) ;
		CaMui<CentDedRessya> aCaMui( &aCentDedRessyaCont ) ;
		aCaMui.insert( pCmd->getCaMuiSelect() ) ;

		// -------------------------------- 
		//	��Ԃ��N���b�v�{�[�h�Ɋi�[
		//	�w�\��t���ړ���(�b)�x�̒l�́A�O�ɂ��܂��B
		// --------------------------------
		getCDiagramEditDoc()->CentDedRessyaCont_To_Cliboard( 
			aCentDedRessyaCont ) ;
		getCWndDcdGrid()->m_jikanPasteIdouryou = 0 ;
		getCWndDcdGrid()->m_jikanPasteIdouryouPrevValue = 0 ;
		
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		{
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;	
}


int CWjkState_Ressyahensyu::
OnEditCopy_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�폜������Ԃ��擾
		// --------------------------------
		CentDedRessyaCont	aCentDedRessyaCont( getCentDedRessyaCont()->createEmptyCont() ) ;
		CaMui<CentDedRessya> aCaMui( &aCentDedRessyaCont ) ;
		aCaMui.insert( pCmd->getCaMuiSelect() ) ;

		// -------------------------------- 
		//	��Ԃ��N���b�v�{�[�h�Ɋi�[
		//	�w�\��t���ړ���(�b)�x�̒l�́A�O�ɂ��܂��B
		// --------------------------------
		getCDiagramEditDoc()->CentDedRessyaCont_To_Cliboard( 
			aCentDedRessyaCont ) ;
		getCWndDcdGrid()->m_jikanPasteIdouryou = 0 ;
		getCWndDcdGrid()->m_jikanPasteIdouryouPrevValue = 0 ;
		
		// -------------------------------- 
		//	�t�H�[�J�X�Z�����A�I���Ԓ��ōő�̗��Index�̎��ʂɈړ�
		// --------------------------------
		{
			//	�t�H�[�J�X�Z���̈ړ��ɂ��Z���I���𖳌������܂��B
			CPropStack	aPropStack( getCWndDcdGrid() ) ;
			aPropStack.CSelect_setSelectMode( CSelect::SelectMode_NONE ) ;
		
			int iRessyaIndexMax = -1 ;
			{
				CaMuiSelect<CentDedRessya>* pCaMuiSelect = pCmd->getCaMuiSelect() ;
				for ( int iRessyaIndex = pCaMuiSelect->getAdapteeMu()->size() - 1  ; 
					iRessyaIndexMax == -1 && iRessyaIndex >= 0 ; iRessyaIndex -- )
				{
					if ( pCaMuiSelect->getSelect( iRessyaIndex ) )
					{
						iRessyaIndexMax = iRessyaIndex + pCmd->getIndexDst() ;
					}
				}
			}
			//iRessyaIndexMax = �I������Ă����Ԃ̂����A�ő��Index
			
			int iXColumnNumber = -1 ;
			{
				CdXColSpecCont aCdXColSpecCont = getCWndDcdGrid()->createXColSpecCont() ;
				iXColumnNumber = aCdXColSpecCont.ColumnNumberFromSpec( CdXColSpec( 
								CdXColSpec::ColumnType_Ressya , 
								iRessyaIndexMax ) ) + 1 ;
			}
			//iXColumnNumber = �I������Ă����Ԃ̂����A�ő��Index�̗�Ԃ̉E�̗�ԍ�
			//	���ꂪ�A���̃t�H�[�J�X�Z���̗�ԍ��ɂȂ�܂��B

			int iYColumnNmber = -1 ;
			{
				CDcdGridCell* pCDcdGridCell = getCWndDcdGrid()->getCFocus()->getFocusCell() ;
				if ( pCDcdGridCell != NULL )
				{
					iYColumnNmber = getCWndDcdGrid()->getCXDcdGrid()->getYColumnNumberOfCell( pCDcdGridCell ) ;
				}
			}
			//iYColumnNmber = ���݂̃t�H�[�J�X�Z���B���̃t�H�[�J�X�Z���������ʒu�ɂȂ�܂��B

			{
				CDcdGridCell* pCDcdGridCellNew = getCWndDcdGrid()->getCXDcdGrid()->getCell( 
					iXColumnNumber , iYColumnNmber ) ; 
				if ( pCDcdGridCellNew != NULL ){
					getCWndDcdGrid()->getCFocus()->setFocusCell( pCDcdGridCellNew ) ;
				}
			}

		}

		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWjkState_Ressyahensyu::
OnEditPaste_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable )
	{
		ppCmd = &pCmd ;
	}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_NewItem , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		if ( !getCDiagramEditDoc()->
				CentDedRessyaCont_IsClipboardFormatAvailable() )
		{
			iRv = -2 ;	//	�N���b�v�{�[�h�Ƀf�[�^������܂���B
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�N���b�v�{�[�h�����Ԃ��擾
		// --------------------------------
		CentDedRessyaCont	aCentDedRessyaCont( 
			getCentDedRessyaCont()->createEmptyCont()) ;
		getCDiagramEditDoc()->CentDedRessyaCont_From_Cliboard( 
			&aCentDedRessyaCont ) ;
		//aCentDedRessyaCont = �N���b�v�{�[�h���̗��

		// --------------------------------
		//	�\��t�����ԂɈړ��ʂ����Z
		// --------------------------------
		{
			CdDedJikan	aCdDedJikan = getCWndDcdGrid()->m_jikanPasteIdouryouPrevValue + 
				getCWndDcdGrid()->m_jikanPasteIdouryou ;
			int iInsertIndex ;
			for ( iInsertIndex = 0 ; iInsertIndex < aCentDedRessyaCont.size() ; 
				iInsertIndex ++ )
			{
				CentDedRessya*	pCentDedRessya = 
					aCentDedRessyaCont.getMuPtr()->get( iInsertIndex ) ;
				pCentDedRessya->modifyRessyaJikoku( 
					aCdDedJikan , 
					CdDedJikokuOrder( 0 , CdDedJikokuOrder::EkiJikokuItem_Chaku ) ) ;
			}
		}
		// --------------------------------
		//	�\��t���ړ���(�b)��ǉ�
		// --------------------------------
		getCWndDcdGrid()->m_jikanPasteIdouryouPrevValue += 
			getCWndDcdGrid()->m_jikanPasteIdouryou ;
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		{
			//	CWndJikokuhyou::ECreateCmd_NewTrain �ɂ���Đ������ꂽ
			//	�V�K�A�C�e���͍폜���܂��B
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;

			//	�R�}���h�ɃN���b�v�{�[�h����̃A�C�e����ǉ����܂��B
			CaMui<CentDedRessya> aCaMui( pCmd->getCaMuiSelect() ) ;
			aCaMui.insert( &aCentDedRessyaCont , 0 , INT_MAX , 0 ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}

	}
	return iRv ;

}


int CWjkState_Ressyahensyu::
OnEditClear_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		{
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;		
}




int CWjkState_Ressyahensyu::
OnEditPasteEkiJikoku_Process( BOOL bQueryEnable )
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
	if ( iRv >= 0 )
	{
		if ( !getCDiagramEditDoc()->
				CentDedRessyaCont_IsClipboardFormatAvailable() )
		{
			iRv = -2 ;	//	�N���b�v�{�[�h�Ƀf�[�^������܂���B
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�N���b�v�{�[�h�����Ԃ��擾
		// --------------------------------
		CentDedRessyaCont	aCentDedRessyaCont( 
			getCentDedRessyaCont()->createEmptyCont()) ;
		getCDiagramEditDoc()->CentDedRessyaCont_From_Cliboard( 
			&aCentDedRessyaCont ) ;
		//aCentDedRessyaCont = �N���b�v�{�[�h���̗��

		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		{
			CentDedRessya* pCentDedRessya = pCmd->getCaMuiSelect()->getMuPtr()->get( 0 ) ;
			pCentDedRessya->pasteEkiJikoku( aCentDedRessyaCont.get( 0 ) ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
	}
	return iRv ;	

}


int CWjkState_Ressyahensyu::OnEditSelectAll_Process( 
	BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		getCWndDcdGrid()->selectAll() ;
	}
	return iRv ;
}

// --------------------------------

int CWjkState_Ressyahensyu::
	OnJikokuhyouRessyaProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	//	�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���Ƃ��́A
	//	�u�V�K��Ԃ̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdXColSpec aXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
	if ( aXColSpec.getColumnType() == CdXColSpec::ColumnType_NewRessya )
	{
		bInsert = true ;
	}

	iRv = execCDlgRessyaProp( bInsert , TRUE ) ;

	//iRv = 
	// 	-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
	//	-	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A@n
	//				�ύX�͔������܂���ł����B
	//	-	-1 ;	//	X��ԍ����s���ł��B

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		iRv = execCDlgRessyaProp( bInsert , FALSE ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
OnJikokuhyouRessyaInsert_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_NewItem , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		//	��Ԃ̑}���̏ꍇ�́A����(��Ԏ��Index=0)�ł͂Ȃ��A
		//	NULL��Ԃ�}�����܂��B
		//	Command ���̗�Ԃ�u�������܂��B
		{
			Mu<CentDedRessya*>* pmuRessya = pCmd->getCaMuiSelect()->getMuPtr() ;
			pmuRessya->get( 0 )->setIsNull( true ) ; 
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
	OnJikokuhyouFocusMoveDown_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( !m_bJikokuhyouFocusMoveRight )
	{
		iRv = 1 ;	//(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͂��łɑI������Ă��܂�
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		m_bJikokuhyouFocusMoveRight = false ;
		
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CWjkState_Ressyahensyu::
	OnJikokuhyouFocusMoveRight_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( m_bJikokuhyouFocusMoveRight )
	{
		iRv = 1 ;	//(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͂��łɑI������Ă��܂�
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		m_bJikokuhyouFocusMoveRight = true ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
	OnJikokuhyouEKikanSaisyouSec_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString strErrorMessage ;
	const CentDedRessyaCont* pCentDedRessyaCont = getCentDedRessyaCont() ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	CdYColSpec aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;
	if ( iRv >= 0 )
	{
		if ( !( aCdYColSpec.getColumnType() == CdYColSpec::ColumnType_Ekijikoku_Chaku || 
				aCdYColSpec.getColumnType() == CdYColSpec::ColumnType_Ekijikoku_Hatsu ) )
		{
			iRv = -1 ;	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
		}
	}
	if ( iRv >= 0 )
	{
		if ( !( 0 <= aCdYColSpec.getEkiOrder() 
			&& aCdYColSpec.getEkiOrder() <  pCentDedRessyaCont->getEkiCount() - 1 ) )
		{
			iRv = -2 ;	//	�t�H�[�J�X�Z�����I���w�ɂ���ꍇ�͎��s�ł��܂���B
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		int iEkikanSaisyouSecRessyaIndex = -1 ;

		pCentDedRessyaCont->findEkikanSaisyouSec( 
			aCdYColSpec.getEkiOrder() , &iEkikanSaisyouSecRessyaIndex ) ;
		
		if ( iEkikanSaisyouSecRessyaIndex >= 0 )
		{
			CdXColSpecCont aXColSpecCont 
				= getCWndDcdGrid()->createXColSpecCont() ;
			CDcdGridCell* pcellCurrent 
				= getCWndDcdGrid()->getCFocus()->getFocusCell() ;
			int iXColumnNumberNew = aXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Ressya ,
					iEkikanSaisyouSecRessyaIndex ) ) ;
			int iYColumnNumberNew = getCWndDcdGrid()->getCXDcdGrid()
				->getYColumnNumberOfCell( pcellCurrent );
			
			CDcdGridCell* pcellNew 
				= getCWndDcdGrid()->getCXDcdGrid()->getCell( 
					iXColumnNumberNew , 
					iYColumnNumberNew ) ; 
			getCWndDcdGrid()->getCFocus()->setFocusCell( pcellNew ) ;
		}
		else	
		{
			const CentDedRosen* pCentDedRosen = getCDiagramEditDoc()
				->getCDedRosenFileData()->getCentDedRosen() ;
			const Mu<CentDedEkiCont::CdDedEki>* pCentDedEkiCont 
				= pCentDedRosen->getCentDedEkiCont()
					->getMuPtr( getRessyahoukou() ) ;
			CString	strFmt ;
			strFmt.LoadString( IDS_ERR_EkikanSaisyouSecIsNone ) ;
			CString strEkimei0 = pCentDedEkiCont->get( 
				aCdYColSpec.getEkiOrder() ).getEkimei().c_str() ;
			CString strEkimei1 = pCentDedEkiCont->get( 
				aCdYColSpec.getEkiOrder() + 1 ).getEkimei().c_str() ;
			CString aStr ;
			aStr.Format( strFmt , strEkimei0 , strEkimei1 ) ;
			
			strErrorMessage = aStr ;
			iRv = -21 ;	//	�w�ԍŏ����v�b����Ԃ�����ł��܂���B
						//	������%s�w��%s�w�̗����ɐݒ肳�ꂽ��Ԃ��P�{��
						//	����܂���B"
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
			case -2 :	//	�t�H�[�J�X�Z�����I���w�ɂ���ꍇ�́A
						//	���̋@�\�͎��s�ł��܂���
			case -21 :	//	�w�ԍŏ����v�b����Ԃ�����ł��܂���B
				break ;
			default:
				strErrorMessage.Format( _T( "Error=%d" ) , iRv ) ;
				break ;
			}
			if ( strErrorMessage.GetLength() > 0 )
			{
				getCWndDcdGrid()->MessageBox( strErrorMessage , NULL , 
					MB_OK | MB_ICONEXCLAMATION ) ;
			}
		}
		// ****************************************************************
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
	OnJikokuhyouSort_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<EditCmd::CRfEditCmd_Ressya> pCmd ;
	Ou<EditCmd::CRfEditCmd_Ressya>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;	}

	CdYColSpec aCdYColSpec = getCWndDcdGrid()->getYColSpecOfFocus() ;

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	bool bRessyasyubetsuSort = false ;
	CdDedJikokuOrder aJikokuOrder  ;
	bool bBikouSort = false ;
	if ( iRv >= 0 )
	{
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_All , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		if ( 
			aCdYColSpec.getColumnType() == 
				CdYColSpec::ColumnType_Ressyabangou || 
			aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Ressyasyubetsu || 
			aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Ressyamei || 
			aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Gousuu || 
			aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Gou )
		{
			bRessyasyubetsuSort = true ;
		}
		else if ( aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Bikou )
 		{
			//	�t�H�[�J�X�Z�������l��ɂ���ꍇ�́A���l�Ń\�[�g
			bBikouSort = true ;
		}
		else if ( aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Ekijikoku_Chaku )
		{
			aJikokuOrder.setEkiOrder( aCdYColSpec.getEkiOrder() , CdDedJikokuOrder::EkiJikokuItem_Chaku ) ;
		}
		else if ( aCdYColSpec.getColumnType() == 
			CdYColSpec::ColumnType_Ekijikoku_Hatsu )
		{
			aJikokuOrder.setEkiOrder( aCdYColSpec.getEkiOrder() , CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ;
		}
		else
		{
			iRv = -1 ;	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
		}
	}
	//bRessyasyubetsuSort = ��Ԏ�ʂŃ\�[�g����ꍇ��true ;
	//iJikokuOrder = �w��̃Z���ɑΉ�����w����Order�x
	//bBikouSort = ���l�Ń\�[�g����ꍇ��true ;

	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		CWaitCursor	aCursor ;	

		// --------------------------------
		//	�Ώۗ�Ԃ��擾���A�\�[�g�p�̃R���e�i�Ɉړ�
		// --------------------------------
		CentDedRessyaCont aCentDedRessyaCont( getCentDedRessyaCont()->createEmptyCont() ) ;
		CaMui<CentDedRessya> aCaMui( &aCentDedRessyaCont ) ;
		aCaMui.insert( pCmd->getCaMuiSelect() ) ;


		// --------------------------------
		//	�Ώۗ�Ԃ��\�[�g
		// --------------------------------
		if ( bRessyasyubetsuSort )
		{
			//	��Ԏ�ʂŃ\�[�g
			CDedRessyaSoater_Ressyasyubetsu	aSoater ;
			aSoater.sort( &aCentDedRessyaCont , NULL ) ;
		}
		else if ( bBikouSort )
		{
			//	���l�Ń\�[�g
			CDedRessyaSoater_Bikou	aSoater ;
			aSoater.sort( &aCentDedRessyaCont , NULL ) ;

		}
		else
		{
			if ( getCWndDcdGrid()->getEkijikokuSort() 
				== CWndJikokuhyou::EEkijikokuSort_Ekiatsukai )
			{
				//	�w���\�[�g

				//	�N�_����
				CdDedJikoku jikokuKitenJikoku = getCDiagramEditDoc()
					->getCDedRosenFileData()->getCentDedRosen()
					->getKitenJikoku() ;

				//	�w�����Ń\�[�g
				CDedRessyaSoater_Ekiatsukai	aSoater( 
					aJikokuOrder ,
					jikokuKitenJikoku ) ;

				aSoater.sort( &aCentDedRessyaCont , NULL ) ;

			}
			else if ( getCWndDcdGrid()->getEkijikokuSort() 
				== CWndJikokuhyou::EEkijikokuSort_Transfer )
			{
				//	��p�\�[�g

				//	�i���_�C�A���O�̍쐬
				CWnd* pWndToDisable = AfxGetMainWnd() ;
				pWndToDisable->EnableWindow( FALSE ) ;

				CDlgProgress	aDlg ;
				aDlg.Create( pWndToDisable ) ;
				aDlg.ShowWindow( SW_SHOW ) ;
				aDlg.CenterWindow() ;

				//	�\�[�g�I�u�W�F�N�g�𐶐�
				CDedRessyaSoater_Transfer	aRessyaContTransferSort( 
					getCDiagramEditDoc()->getCDedRosenFileData()
						->getCentDedRosen() , 
					getCentDedDia() , 
					aJikokuOrder ) ;
				aRessyaContTransferSort.validate() ;

				//	��p�\�[�g
				aRessyaContTransferSort.sort(
					&aCentDedRessyaCont ,
					&aDlg ) ;

				pWndToDisable->EnableWindow( TRUE ) ;
				aDlg.DestroyWindow() ;
			}
		}
		// --------------------------------
		//	�\�[�g�p�̃R���e�i�̓��e���R�}���h�I�u�W�F�N�g��
		//	�����߂�
		// --------------------------------
		{
			for ( int i = 0 ; i < pCmd->getCaMuiSelect()->size() ; i ++ )
			{
				pCmd->getCaMuiSelect()->set( aCentDedRessyaCont.get( i ) , i ) ;
			}
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
	}
	return iRv ;
}

int CWjkState_Ressyahensyu::
OnJikokuhyouUnify_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_All , ppCmd ) )
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
		CWaitCursor	aCursor ;	
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		{
			//	�i���_�C�A���O�̍쐬
			CWnd* pWndToDisable = AfxGetMainWnd() ;
			pWndToDisable->EnableWindow( FALSE ) ;
			CDlgProgress	aDlg ;
			aDlg.Create( pWndToDisable ) ;
			aDlg.ShowWindow( SW_SHOW ) ;
			aDlg.CenterWindow() ;

			//	�ҏW��������s
			{
				Mui<CentDedRessya>* muCentDedRessya = 
					pCmd->getCaMuiSelect() ;
				entDed::CRessyaContUnifier	aUnifier ;
				aUnifier.unify( 
					muCentDedRessya ,
					&aDlg ) ;
			}

			//	�i���_�C�A���O�����
			pWndToDisable->EnableWindow( TRUE ) ;
			aDlg.DestroyWindow() ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
	}
	return iRv ;
}



// --------------------------------

int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	//	�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���Ƃ��́A
	//	�u�V�K��Ԃ̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdXColSpec aXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
	if ( aXColSpec.getColumnType() == CdXColSpec::ColumnType_NewRessya )
	{
		bInsert = true ;
	}	
	iRv = execJikokuhyouPropDlg( bInsert , TRUE ) ;

	//iRv = 
	//	-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
	//	-	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A
	//			//	�ύX�͔������܂���ł����B
	//	-	-1 ;	//	X��ԍ����s���ł��B
	//	-	-2 ;	//	Y��ԍ����s���ł��B

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		iRv = execJikokuhyouPropDlg( bInsert , FALSE ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}

	return iRv ;
}

int CWjkState_Ressyahensyu::
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
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
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

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
		//	�����\���ŁA���Ƀt�H�[�J�X������ꍇ�A
		//	���Ɉړ����܂��B
		{
			moveFocusCellToNext( false ) ;
		}
	}
	return iRv ;

}



int CWjkState_Ressyahensyu
	::OnJikokuhyouTsuuka_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
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
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			CentDedEkiJikoku aCentDedEkiJikoku =
				pCentDedRessya->getCentDedEkiJikoku( aCdYColSpec.getEkiOrder() ) ;
			aCentDedEkiJikoku.setEkiatsukai( CentDedEkiJikoku::Ekiatsukai_Tsuuka ) ;

			//	�w������NULL�ɂ���
			//	���̂ق����֗�
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
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
	}
	return iRv ;

}



int CWjkState_Ressyahensyu::
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
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
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;
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
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}


int CWjkState_Ressyahensyu::
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
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
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;
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
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Ressyahensyu::
	OnJikokuhyouSihatsu_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
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
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			//	�R���e�i�̗�Ԃ�ҏW
			pCentDedRessya->setSihatsuEki(  aCdYColSpec.getEkiOrder() ) ;

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
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Ressyahensyu::
	OnJikokuhyouSyuuchaku_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
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
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			//	�R���e�i�̗�Ԃ�ҏW
			pCentDedRessya->setSyuuchakuEki(  aCdYColSpec.getEkiOrder() ) ;

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
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}



int CWjkState_Ressyahensyu::
	OnJikokuhyouDirect_Process( BOOL bQueryEnable )
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
	const CentDedRessyaCont* pCentDedRessyaCont = NULL ;
	const CentDedRessya* pCentDedRessya = NULL ;
	int idxRessyaSyuuchaku = -1 ;
	if ( iRv >= 0 )
	{
		pCentDedRessyaCont = getCentDedRessyaCont() ;
		CdXColSpec aCdXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
		idxRessyaSyuuchaku = aCdXColSpec.getRessyaIndex() ;
		pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( aCdXColSpec.getRessyaIndex() ) ;
	}

	//���r���w�~�܂��Ԃ��擾�@�@�@�@�@�@CentDedRessyaCont
	//��[�t�H�[�J�X�Z���̈ʒu���A���̗�Ԃ̏I���wOrder����]���G���[
	if ( iRv >= 0 )
	{
		if ( aCdYColSpec.getEkiOrder() < pCentDedRessya->getSyuuchakuEki() )
		{
			iRv = -13;	//	�Z���̈ʒu���A�I���w����
		}
	}
	//idxRessyaSyuuchaku = �t�H�[�J�X�̂���ʒu�̗��
	//pCentDedRessya = �t�H�[�J�X�Z���̂���ʒu�̗��


	//���Ή�����r���w�n����Ԃ�����      CentDedRessyaCont
	//��[�Ή������Ԃ��Ȃ�]�������I��
	int idxRessyaSihatsu = -1 ;
	if ( iRv >= 0 )
	{
		idxRessyaSihatsu = pCentDedRessyaCont->findTrainToDirect(
			idxRessyaSyuuchaku  , 
			aCdYColSpec.getEkiOrder() ) ;
		if ( idxRessyaSihatsu < 0 )
		{
			iRv = -14 ;	//	�Ή�����n����Ԃ�������܂���B
		}
	}
	//idxRessyaSihatsu = �Ή�����n����Ԃ̃C���f�N�X

	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�𐶐�
		// --------------------------------
		if ( !getCWndDcdGrid()->createCmd( idxRessyaSyuuchaku , idxRessyaSihatsu - idxRessyaSyuuchaku + 1  , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g���̗�Ԃ�ҏW
		// --------------------------------
		if ( iRv >= 0 )
		{
			CentDedRessya aRessyaSyuuchaku = pCmd->getCaMuiSelect()->get( 0 ) ; 
			CentDedRessya aCentDedRessyaToDirect = pCmd->getCaMuiSelect()->get( INT_MAX ) ;
			int iResult = aRessyaSyuuchaku.direct( aCentDedRessyaToDirect ) ;
			//iResult = 
			//-	-1 ;	//	���̗�Ԃɂ͉w�������w�肳��Ă��܂���B
			//-	-2 ;	//	�n����Ԃɂ͉w�������w�肳��Ă��܂���B
			//-	-3 ;	//	aRessyaSihatsu �Ƃ̒��ʉ��͂ł��܂���B\n
			//	//aRessyaSihatsu �̎n���w�́A	this �̏I���w�Ɠ������A
			//	//	����ȍ~�łȂ��Ă͂Ȃ�܂���B

			if ( iResult < 0 )
			{
				iRv = iResult  ;
			}
			else
			{
				pCmd->getCaMuiSelect()->set( aRessyaSyuuchaku , 0 ); 
				pCmd->getCaMuiSelect()->erase( INT_MAX , 1 ); 
			}
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
		if ( iRv >= 0 )
		{
			moveFocusCellToNext( true ) ;
		}

		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		CString strErrorMsg ;
		if ( iRv < 0 )
		{
			//switch( iRv )
			//{
			//default:
				strErrorMsg.Format( _T( "Error(%d)" ) , iRv ) ;	
			//	break ;
			//}
			if ( strErrorMsg.IsEmpty() )
			{
				getCWndDcdGrid()->MessageBox( 
					strErrorMsg , NULL , MB_ICONSTOP ) ;
			}
		}

		// ****************************************************************
	}
	return iRv ;

}

int CWjkState_Ressyahensyu::
	OnJikokuhyouUndirect_Process( BOOL bQueryEnable )

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
	const CentDedRessyaCont* pCentDedRessyaCont = NULL ;
	const CentDedRessya* pCentDedRessya = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedRessyaCont = getCentDedRessyaCont() ;
		CdXColSpec aCdXColSpec = getCWndDcdGrid()->getXColSpecOfFocus() ;
		pCentDedRessya = pCentDedRessyaCont->getMuPtr()->get( aCdXColSpec.getRessyaIndex() ) ;
	}

	//�����j���[[�w����]-[���f]
	//��
	//�����f�����Ԃ��擾	CentDedRessyaCont
	//��[!(���̗�Ԃ̎n���wOrder<�t�H�[�J�X�Z���̈ʒu<�I���wOrder)]���G���[
	if ( iRv >= 0 )
	{
		if ( !( pCentDedRessya->getSihatsuEki() < aCdYColSpec.getEkiOrder() 
			&& aCdYColSpec.getEkiOrder() < pCentDedRessya->getSyuuchakuEki()
		) )
		{
			iRv = -21 ;	//	���̗�Ԃ̎n���w�E�I���w�ł͕��f�͂ł��܂���B
		}
	}
	//��[�w�����ɒ����������������w�肳��Ă��Ȃ��w�ł́A���̋@�\�͎g�p�ł��܂���]���G���[
	if ( iRv >= 0 )
	{
		CentDedEkiJikoku	aCentDedEkiJikoku 
			= pCentDedRessya->getCentDedEkiJikoku( 
				aCdYColSpec.getEkiOrder() ) ;
		if ( aCentDedEkiJikoku.getChakujikoku().isNull() && 
			aCentDedEkiJikoku.getHatsujikoku().isNull() )
		{
			iRv = -22 ;	//	�w�����ɒ����������������w�肳��Ă��Ȃ��w�ł́A���̋@�\�͎g�p�ł��܂���
		}
	}
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g���̗�Ԃ�ҏW
		// --------------------------------
		CentDedRessya aRessyaSyuuchaku( getCentDedRessyaCont()->createNullRessya() ) ;
		CentDedRessya aRessyaSihatsu( getCentDedRessyaCont()->createNullRessya() ) ;
		if ( iRv >= 0 )
		{
			CentDedRessya aRessya = pCmd->getCaMuiSelect()->get( 0 ) ; 

			int iResult = pCentDedRessya->undirect( 
				aCdYColSpec.getEkiOrder() , 
				&aRessyaSyuuchaku, 
				&aRessyaSihatsu ) ;
			//iResult = 
			//	-	-1 ;	//	�w��̉wOrder�ł́A���f�͂ł��܂���
			if ( iResult < 0 )
			{
				iRv = iResult - 30 ;
			}
			else
			{
				pCmd->getCaMuiSelect()->set( aRessyaSyuuchaku , 0 ) ;
				pCmd->getCaMuiSelect()->insert( aRessyaSihatsu , 1 ) ; 
			}
			//iRv = 
			//	-	-31 ;	//	�w��̉wOrder�ł́A���f�͂ł��܂���
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		if ( iRv >= 0 )
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		if ( iRv >= 0 ){
			moveFocusCellToNext( true ) ;
		}

		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		CString strErrorMsg ;
		if ( iRv < 0 )
		{
			//switch( iRv )
			//{
			//default:
				strErrorMsg.Format( _T( "Error(%d)" ) , iRv ) ;	
			//	break ;
			//}
			if ( strErrorMsg.IsEmpty() )
			{
				getCWndDcdGrid()->MessageBox( 
					strErrorMsg , NULL , MB_ICONSTOP ) ;
			}
		}
	}
	return iRv ;

}

int CWjkState_Ressyahensyu::
	OnJikokuhyouRenzoku_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	CWjkState* pCState = 
		getCWndDcdGrid()->getStateMachine()->getCStateContGet()->get( 
			CWndJikokuhyou::StateIdx_Renzoku ) ;
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
			CWndJikokuhyou::StateIdx_Renzoku ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;
}



int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuInsert_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
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
	if ( iRv >= 0 ){
		if ( !( 0 <= aCdYColSpec.getEkiOrder() && 
			aCdYColSpec.getEkiOrder() 
			< getCentDedRessyaCont()->getEkiCount() - 1 ) )
		{
			iRv = -2 ;	//	��ԉ��̉w�ł́A���̑���͂ł��܂���B
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
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;

		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			int iEkiOrderCurr = 0 ;
			for ( iEkiOrderCurr = pCentDedRessyaCont->getEkiCount() - 1 ;
					iEkiOrderCurr > aCdYColSpec.getEkiOrder() ;
					iEkiOrderCurr -- ){
				CentDedEkiJikoku aCentDedEkiJikoku = 
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrderCurr - 1 ) ;
				pCentDedRessya->setCentDedEkiJikoku( iEkiOrderCurr , 
					aCentDedEkiJikoku ) ;
			}
			CentDedEkiJikoku aCentDedEkiJikoku ;
			pCentDedRessya->setCentDedEkiJikoku( iEkiOrderCurr , 
				aCentDedEkiJikoku ) ;

		}	
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;


}



int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuErase_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
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
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;

			int iEkiOrderCurr ;
			for ( iEkiOrderCurr = aCdYColSpec.getEkiOrder() ;
					iEkiOrderCurr < pCentDedRessyaCont->getEkiCount() - 1 ;
					iEkiOrderCurr ++ ){
				CentDedEkiJikoku aCentDedEkiJikoku = 
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrderCurr + 1 ) ;
				pCentDedRessya->setCentDedEkiJikoku( iEkiOrderCurr , 
					aCentDedEkiJikoku ) ;
			}
			CentDedEkiJikoku aCentDedEkiJikoku ;
			pCentDedRessya->setCentDedEkiJikoku( iEkiOrderCurr , 
				aCentDedEkiJikoku ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;

}
// --------------------------------
int CWjkState_Ressyahensyu::
OnJikokuhyouModifyEkijikokuCmd_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
		}
	}
	//aCdJikokuOrder = �w��̃Z���ɑΉ�����w����Order�x
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		bool bRepeat = false ;
		do{
			bRepeat = false ;
			// --------------------------------
			//	�_�C�A���O���N��
			// --------------------------------
			CDlgModifyEkijikokuOperation2 aCDlgModifyEkijikokuOperation2( 
				getCWndDcdGrid()->getEkijikokuModifyOperation2() , 
				getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->
					getCentDedEkiCont()->getMuPtr( getCWndDcdGrid()->getRessyahoukou() ) , 
				getCWndDcdGrid() ) ;
			if ( aCDlgModifyEkijikokuOperation2.DoModal() == IDOK )
			{
				getCWndDcdGrid()->setEkijikokuModifyOperation2(
					aCDlgModifyEkijikokuOperation2.getCentDedRessya_EkijikokuModifyOperation2() ) ;

				// --------------------------------
				//	�w�����ύX�̓�������s
				// --------------------------------
				int iResult = getCWndDcdGrid()->execCdModifyEkijikokuCmd(
					pCmd , 
					aCdJikokuOrder ) ;
				if  ( iResult < 0 )
				{
					//	�G���[�����������ꍇ�́A�_�C�A���O���ēx�J���܂��B
					bRepeat = true ;
				}
				else
				{
					// --------------------------------
					//	�t�H�[�J�X�Z�������ֈڂ��܂��B
					// --------------------------------
					moveFocusCellToNext( true ) ;
				}
			}
		}	while ( bRepeat ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;




}


int CWjkState_Ressyahensyu::OnJikokuhyouModifyEkijikokuCmdRepeat_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
		}
	}
	//aCdJikokuOrder = �w��̃Z���ɑΉ�����w����Order�x
	if ( iRv >= 0 )
	{
		if ( getCWndDcdGrid()->getEkijikokuModifyOperation2().isNull() )
		{
			iRv = -1 ;	//	�O��́u�w�����ύX�v�������ł��B
		}
	}

	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		{
				// --------------------------------
				//	�w�����ύX�̓�������s
				// --------------------------------
				int iResult = getCWndDcdGrid()->execCdModifyEkijikokuCmd(
					pCmd , 
					aCdJikokuOrder ) ;
				if  ( iResult >= 0 )
				{
					//	�t�H�[�J�X�Z�������ֈڂ��܂��B
					moveFocusCellToNext( true ) ;
				}
		}
	}
	return iRv ; 

}

// --------------------------------
int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuDec_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;
		}
	}
	//aCdJikokuOrder = �w��̃Z���ɑΉ�����w����Order�x
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;	
			
			pCentDedRessya->modifyRessyaJikoku( CdDedJikan(  -1 * 60 ) , 
				aCdJikokuOrder ) ;
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
		{
			moveFocusCellToNext( false ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;
			

}

int CWjkState_Ressyahensyu::
OnJikokuhyouEkijikokuDecNoMove_Process( BOOL bQueryEnable )
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;
		}
	}
	//aCdJikokuOrder = �w��̃Z���ɑΉ�����w����Order�x
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;	
			
			pCentDedRessya->modifyRessyaJikoku( CdDedJikan(  -1 * 60 ) , 
				aCdJikokuOrder ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;

}


int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuNext_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	CDcdGridCell*	pCDcdGridCell = NULL ;
	if ( iRv >= 0 )
	{
		pCDcdGridCell = getCWndDcdGrid()->getCFocus()->getFocusCell() ;
		if ( pCDcdGridCell == NULL )
		{
			iRv = -11  ;	//	�Z���̏ꏊ���s��
		}
	}
	//pCDcdGridCell = �ҏW���̃Z��
	
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		{
			moveFocusCellToNext( false ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;
}



int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuPrev_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	CDcdGridCell*	pCDcdGridCell = NULL ;
	if ( iRv >= 0 )
	{
		pCDcdGridCell = getCWndDcdGrid()->getCFocus()->getFocusCell() ;
		if ( pCDcdGridCell == NULL )
		{
			iRv = -11  ;	//	�Z���̏ꏊ���s��
		}
	}
	//pCDcdGridCell = �ҏW���̃Z��
	
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		{
			moveFocusCellToPrev( false ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;
}

int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuInc_Process( BOOL bQueryEnable ) 
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;
		}
	}
	//aCdJikokuOrder = �w��̃Z���ɑΉ�����w����Order�x
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;		
	
			pCentDedRessya->modifyRessyaJikoku( CdDedJikan(  +1 * 60 ) , 
				aCdJikokuOrder ) ;
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
		{
			moveFocusCellToNext( false ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;
}



int CWjkState_Ressyahensyu::
	OnJikokuhyouEkijikokuIncNoMove_Process( BOOL bQueryEnable ) 
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
		if ( !getCWndDcdGrid()->createCmd( CWndJikokuhyou::ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	��ԑI���ʒu������������܂���B
		}
	}
	CdDedJikokuOrder aCdJikokuOrder ;
	if ( iRv >= 0 )
	{
		aCdJikokuOrder = getCWndDcdGrid()->CdDedJikokuOrderOf( 
			getCWndDcdGrid()->getYColSpecOfFocus() ) ;
		if ( aCdJikokuOrder.getIsNull() )
		{
			iRv = -1 ;
		}
	}
	//aCdJikokuOrder = �w��̃Z���ɑΉ�����w����Order�x
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
		// --------------------------------
		const CentDedRessyaCont* pCentDedRessyaCont  =  getCentDedRessyaCont() ;
		Mu<CentDedRessya*>* muCentDedRessya =  pCmd->getCaMuiSelect()->getMuPtr() ;
		for ( int i = 0 ; iRv >= 0 && i < muCentDedRessya->size() ; i++ )
		{
			CentDedRessya* pCentDedRessya = muCentDedRessya->get( i ) ;		
			
			pCentDedRessya->modifyRessyaJikoku( CdDedJikan(  +1 * 60 ) , 
				aCdJikokuOrder ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;
			
			

}


		// ********************************
		//@name	CWndDcdGrid
		// ********************************
void CWjkState_Ressyahensyu::OnSetFocusCell( 
		CDcdGridCell* pCDcdGridCell ) 
{
}

void CWjkState_Ressyahensyu::OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) 
{
	super::OnChangeSelectCell( iXColumnNumber , iYColumnNumber , bIsSelected );
}



} } // namespace WndJikokuhyou namespace ViewJikokuhyou
