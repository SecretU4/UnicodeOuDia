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
// cdeddiagramview.cpp : �C���v�������e�[�V���� �t�@�C��
//	$Id: CDedDiagramView.cpp 295 2016-06-11 05:14:13Z okm $

#include "stdafx.h"

#include "NsMu/CaMuPtref.h"
#include "NsOu/dynamic_castOu.h"
#include "NsOu/OuNew.h"
#include "LogMsg\LogMsg.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDrawMfc/CDcdTargetMfcPrintInfo.h"
#include "DcDraw/print/CaDcdTargetZoomDisplay.h"
#include "str/strToInt.h"

#include "..\diagramedit.h"
#include "..\entDed\CentDedRosen.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "..\Print\CconvCdPrintPageProp.h"
#include "CaDcdDiagram_PageSelector.h"
#include "cdeddiagramview.h"
#include "CDlgDiagramViewProp.h"

namespace ViewDiagram{

using namespace std ;
using namespace DcDrawLib::DcDraw::Print;
using namespace DcDrawLib::DcDrawMfc;

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView
/**
	�_�C���O�������W�̋��e�덷�l
*/
const int ALLOWED_DIFFERENCE = 1 ;

// --------------------------------
//@name OnUpdate�����֐�
// --------------------------------
void CDedDiagramView::OnUpdate_All() 
{
	CWaitCursor	aCWaitCursor ;

	LogMsg( "CDedDiagramView::OnUpdate_All()" ) ; 
	// --------------------------------
	//	�w�_�C���O�����w�x�I�u�W�F�N�g�𐶐�
	// --------------------------------
	const CentDedRosen* pCentDedRosen = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;

	if ( m_pCentDedDgrDia == NULL ){
		m_pCentDedDgrDia = new CentDedDgrDia ;
		LogMsg( "CDedDiagramView::OnUpdate_All()1" ) ; 
		m_pCentDedDgrDia->readCentDedRosen( pCentDedRosen , getCentDedDia() ) ; 
		LogMsg( "CDedDiagramView::OnUpdate_All()2" ) ; 
		m_pCWndDiagram->setCentDedDgrDia( m_pCentDedDgrDia ) ;
	}	else	{
		LogMsg( "CDedDiagramView::OnUpdate_All()3" ) ; 
		m_pCentDedDgrDia->readCentDedRosen( pCentDedRosen , getCentDedDia() ) ; 
		LogMsg( "CDedDiagramView::OnUpdate_All()4" ) ; 
	}
	// --------------------------------
	CdDedDispProp	aCdDedDispProp = getCDiagramEditDoc()->getCDedRosenFileData()->getCdDedDispProp() ;
	m_pCWndDiagram->readCdDedDispProp( aCdDedDispProp ) ;
	LogMsg( "CDedDiagramView::OnUpdate_All()5" ) ; 
	
	// --------------------------------
	m_pCWndDiagram->onUpdateCentDedDgrDia() ;

	LogMsg( "CDedDiagramView::OnUpdate_All()=" ) ; 

	m_bUpdate_All_Requested = false ;
}


void CDedDiagramView::OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) 
{
	int iDiaIndex = GetDocument()->getDiaIndex() ;
	if ( !( pCommand->getDiaIndex() == iDiaIndex ) ){
		return ;
	}

	ERessyahoukou	eRessyahoukou = pCommand->getRessyahoukou() ;
	const CentDedRessyaCont*	pCentDedRessyaContSrc = 
		pCommand->getCentDedRessyaContSrc() ;
	// --------------------------------
	//	�������̗v�f�̍폜
	// --------------------------------
	int iGensyouSize = pCommand->getSizeDst() - pCentDedRessyaContSrc->size() ;
	if ( iGensyouSize > 0 ){
		for ( int cnt = 0 ; cnt < iGensyouSize ; cnt ++ ){
			m_pCentDedDgrDia->getCentDedDgrRessyaCont( eRessyahoukou )->erase( 
				pCommand->getIndexDst() + 
				pCommand->getSizeDst() - iGensyouSize ) ;
		}
	}
	// --------------------------------
	//	�v�f�̒u��
	// --------------------------------
	int iOkikaeSize = 0 ;
	iOkikaeSize = min( pCommand->getSizeDst() , pCentDedRessyaContSrc->size() ) ;
	{
		for ( int cnt = 0 ; cnt < iOkikaeSize ; cnt ++ )
		{
			int idxRessya = pCommand->getIndexDst() + cnt ;
			const CentDedRosen*	pCentDedRosen = 
				getCDiagramEditDoc()->getCDedRosenFileData()->
				getCentDedRosen() ;
			const Mu<const CentDedRessya*>* pCentDedRessyaContGet = 
				getCentDedDia()->getCentDedRessyaCont( eRessyahoukou )->getMuPtr() ;

			const CentDedRessya* pCentDedRessya = pCentDedRessyaContGet->get( 
				idxRessya )  ;
			CentDedDgrRessya	aCentDedDgrRessya( pCentDedRosen , 
				m_pCentDedDgrDia , 
				pCentDedRessya ) ;

			m_pCentDedDgrDia->getCentDedDgrRessyaCont( eRessyahoukou )->set(
				aCentDedDgrRessya , idxRessya ) ;
			
		}
	}
	// --------------------------------
	//	�������̗v�f�̒ǉ�
	// --------------------------------
	int iZoukaSize = pCentDedRessyaContSrc->size() - pCommand->getSizeDst() ;
	if ( iZoukaSize > 0 ){
		for ( int cnt = 0 ; cnt < iZoukaSize ; cnt ++ ){
			int idxRessya = pCommand->getIndexDst() + iOkikaeSize + cnt ;

			const CentDedRosen*	pCentDedRosen = 
				getCDiagramEditDoc()->getCDedRosenFileData()->
				getCentDedRosen() ;
			const Mu<const CentDedRessya*>* pCentDedRessyaContGet = 
				getCentDedDia()->getCentDedRessyaCont( eRessyahoukou )->getMuPtr() ;

			const CentDedRessya* pCentDedRessya = pCentDedRessyaContGet->get( 
				idxRessya )  ;
			CentDedDgrRessya	aCentDedDgrRessya( pCentDedRosen , 
				m_pCentDedDgrDia , 
				pCentDedRessya ) ;

			m_pCentDedDgrDia->getCentDedDgrRessyaCont( eRessyahoukou )->insert(
				aCentDedDgrRessya , idxRessya ) ;
		}
	}

	m_pCWndDiagram->onUpdateCentDedDgrRessya() ;

}


/**
  ����(�␳�Ώےl)���A�����P�ʂ̔{���}��(�덷���e�l) �Ȃ�A
  �Ŋ�̑����P�ʂ̔{�����x�̒l�ɕ␳���܂��B

(��)iUnit=5,iAllowedDifference=1 �̏ꍇ�Avalue�ɑ΂��錋�ʂ͈ȉ��̂Ƃ���ł��B

�@- value=3 �Ȃ� return=3
�@- value=4 �Ȃ� return=5
�@- value=5 �Ȃ� return=5
�@- value=6 �Ȃ� return=5
�@- value=7 �Ȃ� return=7


�@���̊֐��́A�ȉ��̂��߂Ɏg���܂��B

	�uCDcdDiagram::getZone_Dgr()�Ŏ擾����(�`��͈͂̕�(�_�C���O�������W�n))��
	�����P�ʂ̔{���}��(�덷���e�l)�Ȃ�A(�`��͈͂̕�(�_�C���O�������W�n))��
	�Ŋ�̑����P�ʂ̔{�����x�̒l�ɕ␳����v

@param value [in]
	�␳�Ώےl���w�肵�Ă��������B�͈͂�0�ȏ�ł��B
@param iUnit [in]
	�����P�ʂ��w�肵�Ă��������B�͈͂�1�ȏ�ł��B
@param iAllowedDifference [in]
	�덷���e�l
@return
	�␳���ꂽ�l��Ԃ��܂��B
*/
static int adjustForNearestUnit( int value , int iUnit , int iAllowedDifference ) 
{

	//�␳�P�F(���ݒl%�����P��)��(�덷���e�l) �Ȃ�A
	//�@���ݒl=���ݒl-(���ݒl%�����P��)
	//
	//(��)
	//�@�����P��=1800
	//�@���ݒl=1801
	//�@(�덷���e�l)=1
	//�̏ꍇ
	//�@(1801%1800)=1 (���ݒl%�����P��)
	//�@1801-(1801%1800)=1800
	//
	if ( value % iUnit <= iAllowedDifference )
	{
		value = value - ( value % iUnit ) ; 
	}

	//�␳�Q�F(���ݒl%�����P��)��(�����P��-�덷���e�l) �Ȃ�A
	//�@���ݒl=���ݒl+(�����P��-(���ݒl%�����P��))
	//
	//(��)
	//�@�����P��=1800
	//�@���ݒl=3599
	//�@(�덷���e�l)=1
	//�̏ꍇ
	//�@(3599%1800)=1799 (���ݒl%�����P��)
	//�@3599+(1800-(3599%1800))=3600
	else if ( ( value % iUnit ) >= ( iUnit - iAllowedDifference ) )
	{
		value = value + ( iUnit - ( value % iUnit ) ) ; 
	}
	return value ;
}



	// --------------------------------
	//@param ���b�Z�[�W �}�b�v�֐��̉����֐�
	// --------------------------------
int CDedDiagramView::OnDiagramXDgrSizeInc_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;	

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	//	���������k��
	CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getX() ;

	//	�E�C���h�E�ւ̕\���͈͂̑����P�ʂ��Z�o
	//	
	//	�_�C���O�����S�̂���ʓ��Ɏ��܂��Ă��Ȃ��ꍇ:30��
	//	�_�C���O�����S�̂���ʓ��Ɏ��܂��Ă���ꍇ  :12����
	int iUnit = 30*60 ;
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() >= 
				m_pCentDedDgrDia->getZone().getX().getSize() )
		{
			iUnit = m_pCentDedDgrDia->getZone().getX().getSize() / 2 ;
		}
		if ( iUnit == 0 )
		{
			iUnit = 1 ;	//	���Ƃ̊���Z�ɔ����āA0 �� 1 �ɂ��Ă����܂��B
		}
	}
		//iUnit = �E�C���h�E�ւ̕\���͈͂̑����P��(�_�C���O�����G���e�B�e�BX���W)

	//	�`��͈͂̕�(�_�C���O�������W�n)�������P�ʂ̔{���ɋ߂��ꍇ�́A
	//	�����P�ʂ̔{�����x�̒l�ɕ␳����
	//	����́ACDcdDiagram �ɑ΂��� setZone_Dgr() �Őݒ肵��
	//	�w�`����s���̈�͈̔�(�_�C���O�����G���e�B�e�B���W�n)�x�� 
	//	getZone_Dgr() �Ŏ擾�����l����v���Ȃ��ꍇ�����邽�߂ł��B
	zoneCWndDiagram_Dgr.setSize( 
		adjustForNearestUnit( 
			zoneCWndDiagram_Dgr.getSize() , iUnit , ALLOWED_DIFFERENCE ) ) ;

	if ( iRv >= 0 )
	{
		//	�E�C���h�E��Ƀ_�C���O�������\������Ă��Ȃ��ꍇ�́A
		//	X�����̕\���͈͕͂ύX�ł��܂���B
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getX().getSize() <= 0 )
		{
			iRv = -2 ;	//	�_�C���O�����͕\������Ă��܂���B
		}
	}
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getEndPos() >= 
			m_pCentDedDgrDia->getZone().getX().getEndPos() )
		{
			//	����ȏ�\���͈͂��L���邱�Ƃ͂ł��܂���B
			iRv = -1 ;	//���݂͎��s�ł��܂���(�G���[���b�Z�[�W�͕\�����܂���)
		}
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		DcdSize	iDcdSize = zoneCWndDiagram_Dgr.getSize() ;
		int iMod = iDcdSize % (iUnit) ;
		if ( iMod == 0 ){
			iDcdSize += (iUnit) ;
		}	else	{
			iDcdSize += ( (iUnit) - iMod ) ;
		}
		zoneCWndDiagram_Dgr.setSize( iDcdSize ) ;

		LogMsg( "\t" "zoneCWndDiagram_Dgr=%d,%d" , 
			zoneCWndDiagram_Dgr.getPos() , zoneCWndDiagram_Dgr.getSize() ) ;

		zonexyCWndDiagram_Dgr.setX( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;
		// --------------------------------
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	LogMsg( "CDedDiagramView::OnDiagramXDgrSizeInc_Process()=%d" , iRv ) ;
	return iRv ;
}
int CDedDiagramView::OnDiagramXDgrSizeDec_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;	
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	// 
	CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getX() ;

	//	�E�C���h�E�ւ̕\���͈͂̑����P�ʂ��Z�o
	//	
	//	�_�C���O�����S�̂���ʓ��Ɏ��܂��Ă��Ȃ��ꍇ:30��
	//	�_�C���O�����S�̂���ʓ��Ɏ��܂��Ă���ꍇ  :12����
	int iUnit = 30*60 ;
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() 
				> m_pCentDedDgrDia->getZone().getX().getSize() )
		{
			iUnit = m_pCentDedDgrDia->getZone().getX().getSize() / 2 ;
		}
		if ( iUnit == 0 )
		{
			iRv = -2 ;	//	�_�C���O�����͕\������Ă��܂���B
		}
	}
		//iUnit=�E�C���h�E�ւ̕\���͈͂̑����P��(�_�C���O�����G���e�B�e�BX���W)


	//	�`��͈͂̕�(�_�C���O�������W�n)�������P�ʂ̔{���ɋ߂��ꍇ�́A
	//	�����P�ʂ̔{�����x�̒l�ɕ␳����
	//	����́ACDcdDiagram �ɑ΂��� setZone_Dgr() �Őݒ肵��
	//	�w�`����s���̈�͈̔�(�_�C���O�����G���e�B�e�B���W�n)�x�� 
	//	getZone_Dgr() �Ŏ擾�����l����v���Ȃ��ꍇ�����邽�߂ł��B
	zoneCWndDiagram_Dgr.setSize( 
		adjustForNearestUnit( 
			zoneCWndDiagram_Dgr.getSize() , iUnit , ALLOWED_DIFFERENCE ) ) ;

	if ( iRv >= 0 )
	{
		//	�E�C���h�E��Ƀ_�C���O�������\������Ă��Ȃ��ꍇ�́A
		//	X�����̕\���͈͕͂ύX�ł��܂���B
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getX().getSize() <= 0 )
		{
			iRv = -2 ;	//	�_�C���O�����͕\������Ă��܂���B
		}
	}
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() <= (iUnit) )
		{
			//	����ȏ�\���͈͂��L���邱�Ƃ͂ł��܂���B
			iRv = -1 ;	//���݂͎��s�ł��܂���(�G���[���b�Z�[�W�͕\�����܂���)
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		DcdSize	iDcdSize = zoneCWndDiagram_Dgr.getSize() ;
		int iMod = iDcdSize % (iUnit) ;
		if ( iMod == 0 ){
			iDcdSize -= (iUnit) ;
		}	else	{
			iDcdSize -= iMod  ;
		}
		zoneCWndDiagram_Dgr.setSize( iDcdSize ) ;

		LogMsg( "\t" "zoneCWndDiagram_Dgr=%d,%d" , 
			zoneCWndDiagram_Dgr.getPos() , zoneCWndDiagram_Dgr.getSize() ) ;

		zonexyCWndDiagram_Dgr.setX( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
	}
	LogMsg( "CDedDiagramView::OnDiagramXDgrSizeDec_Process()=%d" , iRv ) ;
	return iRv ;
}
int CDedDiagramView::OnDiagramYDgrSizeInc_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;	
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	
	//	�c�������k��
	// 
	//	�c�������k���́A�\���͈͂��P�i�K���₵�܂��B

	CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getY() ;

	//	�E�C���h�E�ւ̕\���͈͂̑����P�ʂ��Z�o
	//	
	//	�_�C���O�����S�̂���ʓ��Ɏ��܂��Ă��Ȃ��ꍇ:
	//		�_�C���O�����S�̂̃T�C�Y��1/10
	//	�_�C���O�����S�̂���ʓ��Ɏ��܂��Ă���ꍇ  :
	//		�_�C���O�����S�̂̃T�C�Y��1/2
	int iUnit = m_pCentDedDgrDia->getZone().getY().getSize() / 10 ;
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() 
				>= m_pCentDedDgrDia->getZone().getY().getSize() )
		{
			iUnit = m_pCentDedDgrDia->getZone().getY().getSize() / 2 ;
		}
		if ( iUnit == 0 ){
			iUnit = 1 ;	//	���Ƃ̊���Z�ɔ����āA0 �� 1 �ɂ��Ă����܂��B
		}
	}
		//iUnit=�E�C���h�E�ւ̕\���͈͂̑����P��(�_�C���O�����G���e�B�e�BY���W)


	//	�`��͈͂̕�(�_�C���O�������W�n)�������P�ʂ̔{���ɋ߂��ꍇ�́A
	//	�����P�ʂ̔{�����x�̒l�ɕ␳����
	//	����́ACDcdDiagram �ɑ΂��� setZone_Dgr() �Őݒ肵��
	//	�w�`����s���̈�͈̔�(�_�C���O�����G���e�B�e�B���W�n)�x�� 
	//	getZone_Dgr() �Ŏ擾�����l����v���Ȃ��ꍇ�����邽�߂ł��B
	zoneCWndDiagram_Dgr.setSize( 
		adjustForNearestUnit( 
			zoneCWndDiagram_Dgr.getSize() , iUnit , ALLOWED_DIFFERENCE ) ) ;

	if ( iRv >= 0 )
	{
		//	�E�C���h�E��Ƀ_�C���O�������\������Ă��Ȃ��ꍇ�́A
		//	Y�����̕\���͈͕͂ύX�ł��܂���B
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getY().getSize() <= 0 )
		{
			iRv = -2 ;	//	�_�C���O�����͕\������Ă��܂���B
		}
	}
	if ( iRv >= 0 )
	{
		//	�͈͂́A�w�_�C���O�����G���e�B�e�BY���W�x�̃T�C�Y��10�{�l�ȉ��ł��B
		if ( zoneCWndDiagram_Dgr.getSize() 
				>= m_pCentDedDgrDia->getZone().getY().getSize() * 10 )
		{
			//	����ȏ�\���͈͂��L���邱�Ƃ͂ł��܂���B
			iRv = -1 ;	//���݂͎��s�ł��܂���(�G���[���b�Z�[�W�͕\�����܂���)
		}
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		DcdSize	iDcdSize = zoneCWndDiagram_Dgr.getSize() ;
		int iMod = iDcdSize % iUnit ;
		if ( iMod == 0 ){
			iDcdSize += iUnit ;
		}	else	{
			iDcdSize += ( iUnit - iMod ) ;
		}
		zoneCWndDiagram_Dgr.setSize( iDcdSize ) ;
		zonexyCWndDiagram_Dgr.setY( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;
		// --------------------------------
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 ://	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnDiagramYDgrSizeDec_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getY() ;

	//	�E�C���h�E�ւ̕\���͈͂̑����P�ʂ��Z�o
	//	
	//	�_�C���O�����S�̂���ʓ��Ɏ��܂��Ă��Ȃ��ꍇ:
	//		�_�C���O�����S�̂̃T�C�Y��1/10
	//	�_�C���O�����S�̂���ʓ��Ɏ��܂��Ă���ꍇ  :
	//		�_�C���O�����S�̂̃T�C�Y��1/2
	int iUnit = m_pCentDedDgrDia->getZone().getY().getSize() / 10 ;
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() 
				> m_pCentDedDgrDia->getZone().getY().getSize() )
		{
			iUnit = m_pCentDedDgrDia->getZone().getY().getSize() / 2 ;
		}
		if ( iUnit == 0 ){
			iUnit = 1 ;	//	���Ƃ̊���Z�ɔ����āA0 �� 1 �ɂ��Ă����܂��B
		}
		//	�͈͂́A�w�_�C���O�����G���e�B�e�BY���W�x�̃T�C�Y��10�{�l�ȉ��ł��B

	}

	//	�`��͈͂̕�(�_�C���O�������W�n)�������P�ʂ̔{���ɋ߂��ꍇ�́A
	//	�����P�ʂ̔{�����x�̒l�ɕ␳����
	//	����́ACDcdDiagram �ɑ΂��� setZone_Dgr() �Őݒ肵��
	//	�w�`����s���̈�͈̔�(�_�C���O�����G���e�B�e�B���W�n)�x�� 
	//	getZone_Dgr() �Ŏ擾�����l����v���Ȃ��ꍇ�����邽�߂ł��B
	zoneCWndDiagram_Dgr.setSize( 
		adjustForNearestUnit( 
			zoneCWndDiagram_Dgr.getSize() , iUnit , ALLOWED_DIFFERENCE ) ) ;

	if ( iRv >= 0 )
	{
		//	�E�C���h�E��Ƀ_�C���O�������\������Ă��Ȃ��ꍇ�́A
		//	Y�����̕\���͈͕͂ύX�ł��܂���B
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getY().getSize() <= 0 )
		{
			iRv = -2 ;	//	�_�C���O�����͕\������Ă��܂���B
		}
	}
	if ( iRv >= 0 )
	{
		if ( zoneCWndDiagram_Dgr.getSize() <= (iUnit) ){
			//	����ȏ�\���͈͂��L���邱�Ƃ͂ł��܂���B
			iRv = -1 ;	//���݂͎��s�ł��܂���(�G���[���b�Z�[�W�͕\�����܂���)
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		DcdSize	iDcdSize = zoneCWndDiagram_Dgr.getSize() ;
		int iMod = iDcdSize % (iUnit) ;
		if ( iMod == 0 ){
			iDcdSize -= (iUnit) ;
		}	else	{
			iDcdSize -= iMod  ;
		}
		zoneCWndDiagram_Dgr.setSize( iDcdSize ) ;

		LogMsg( "\t" "zoneCWndDiagram_Dgr=%d,%d" , 
			zoneCWndDiagram_Dgr.getPos() , zoneCWndDiagram_Dgr.getSize() ) ;

		zonexyCWndDiagram_Dgr.setY( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;
		
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
	}
	LogMsg( "CDedDiagramView::OnDiagramYDgrSizeDec_Process()=%d" , iRv ) ;
	return iRv ;
}
int CDedDiagramView::OnDiagramYDgrSizeReset_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMsg ;	
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		//	�E�C���h�E��Ƀ_�C���O�������\������Ă��Ȃ��ꍇ�́A
		//	Y�����̕\���͈͕͂ύX�ł��܂���B
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getY().getSize() <= 0 )
		{
			iRv = -2 ;	//	�_�C���O�����͕\������Ă��܂���B
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		CdDcdZoneXy	zonexyCWndDiagram_Dgr = m_pCWndDiagram->getZone_Dgr() ;
		CdDcdZone	zoneCWndDiagram_Dgr = zonexyCWndDiagram_Dgr.getY() ;

		zoneCWndDiagram_Dgr = m_pCentDedDgrDia->getZone().getY() ;

		zonexyCWndDiagram_Dgr.setY( zoneCWndDiagram_Dgr ) ;
		m_pCWndDiagram->setZone_Dgr( zonexyCWndDiagram_Dgr ) ;

		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		if ( iRv < 0 )
		{
			switch( iRv )
			{
			case -1 :	//	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
				break ;
			default:
				strErrorMsg.Format( _T( "Error %d") , iRv ) ;
				break ;
			}
			if ( strErrorMsg.GetLength() > 0 )
			{
				MessageBox( strErrorMsg , 0 , MB_ICONERROR ) ;
			}
		}
		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramMemoriDown_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	int idxVlineMode = m_pCWndDiagram->getVlineMode() ;
	bool	bRv = true ;	
	if ( idxVlineMode <= 0 ){
		iRv = -1 ;	//	�R�}���h�𖳌�
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		m_pCWndDiagram->setVlineMode( idxVlineMode - 1 ) ;

		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnDiagramMemoriUp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	int idxVlineMode = m_pCWndDiagram->getVlineMode() ;
	if ( idxVlineMode + 1 >= m_pCWndDiagram->getVlineChoices( NULL ) ){
		iRv = -1 ;	//	�R�}���h�𖳌�
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		m_pCWndDiagram->setVlineMode( idxVlineMode + 1 ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramRessyabangou_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( m_pCWndDiagram->getDisplayRessyabangou() )
	{
		iRv = 1 ;
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		m_pCWndDiagram->setDisplayRessyabangou( 
			!m_pCWndDiagram->getDisplayRessyabangou() ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnUpdateDiagramRessyamei_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( m_pCWndDiagram->getDisplayRessyamei() )
	{
		iRv = 1 ;
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		m_pCWndDiagram->setDisplayRessyamei( 
			!m_pCWndDiagram->getDisplayRessyamei() ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramRessyasenKudari_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( m_pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Kudari ) )
	{
		iRv = 1 ;
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		m_pCWndDiagram->setDisplayRessyasen( Ressyahoukou_Kudari , 
			!m_pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Kudari ) ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramRessyasenNobori_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( m_pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Nobori ) )
	{
		iRv = 1 ;
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		m_pCWndDiagram->setDisplayRessyasen( Ressyahoukou_Nobori , 
			!m_pCWndDiagram->getDisplayRessyasen( Ressyahoukou_Nobori ) ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnDiagramHideIppanekiEkimei_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( m_pCWndDiagram->getHideIppanekiEkimei() )
	{
		iRv = 1 ;	
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		m_pCWndDiagram->setHideIppanekiEkimei( 
			!m_pCWndDiagram->getHideIppanekiEkimei() ) ;	
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}
int CDedDiagramView::OnDiagramStopmarkdraw_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( m_pCWndDiagram->getStopMarkDraw() == 
			CDcdDiagram::EStopMarkDraw_DrawOnBriefStop ) 
	{
		iRv = 1 ;
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		CDcdDiagram::EStopMarkDraw eStopMarkDraw 
			= CDcdDiagram::EStopMarkDraw_Nothing ;
		if ( m_pCWndDiagram->getStopMarkDraw() == 
			CDcdDiagram::EStopMarkDraw_Nothing )
		{
			eStopMarkDraw =CDcdDiagram::EStopMarkDraw_DrawOnBriefStop ;
		}
		m_pCWndDiagram->setStopMarkDraw( eStopMarkDraw ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnViewUpdate_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�����s
		// ****************************************************************
		//	�r���[��S�X�V���܂��B
		OnUpdate( NULL , 0 , NULL ) ;
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}

int CDedDiagramView::OnDiagramViewProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		//	�E�C���h�E���ŁA�_�C���O������`�悷��̈�̑傫�������߂܂��B
		//	�P�ʂ́A IfDcdTarget ��̍��W�ł��B
		CdDcdZoneXy	zoneDiagramZoneDcd = m_pCWndDiagram->calcDiagramZoneDcd() ;

		CDlgDiagramViewProp aDlg( 
			m_pCentDedDgrDia->getZone() ,
			//	�E�C���h�E��X���������A�_�C���O�������\���\�ȑ傫���ł��邩
			//	�ۂ����w��
			zoneDiagramZoneDcd.getX().getSize() > 0 ,
			//	�E�C���h�E��Y���������A�_�C���O�������\���\�ȑ傫���ł��邩
			//	�ۂ����w��
			zoneDiagramZoneDcd.getY().getSize() > 0 ,
			m_pCWndDiagram->getZone_Dgr() ,
			m_pCWndDiagram->getVlineMode() ,
			this ) ;
		if ( aDlg.DoModal() == IDOK ){
			m_pCWndDiagram->setZone_Dgr( aDlg.getCWndDiagramZone_Dgr() );
			m_pCWndDiagram->setVlineMode( aDlg.getVlineMode() ) ;
		}	
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;
}


// ********************************
//	CDedDiagramView
// ********************************
	// ********************************
	//@name CDedDiagramView-����
	// ********************************
int CDedDiagramView::setZone_Dgr( 
		const CdDedJikoku& aCdDedJikoku ,
		int iEkiIndex , bool bEkiIndexIsBottom ) 
{
	CdDcdZoneXy	zonexyZone_Dgr = m_pCWndDiagram->getZone_Dgr() ;
	
	//X���W��ύX
	if ( !aCdDedJikoku.isNull() ){
		CdDcdZone	aCdDcdZone = zonexyZone_Dgr.getX() ;
		aCdDcdZone.setPos( aCdDedJikoku.getTotalSeconds() ) ;
		zonexyZone_Dgr.setX( aCdDcdZone ) ;
	}
	//Y���W��ύX
	if ( 0 <= iEkiIndex && iEkiIndex < getCentDedDia()->getEkiCount() ){
		CdDcdZone	aCdDcdZone = zonexyZone_Dgr.getY() ;
		int iYZahyou = m_pCentDedDgrDia->getDgrYPosOfEki( iEkiIndex ) ;
		if ( bEkiIndexIsBottom ){
			iYZahyou = iYZahyou - aCdDcdZone.getSize() ;
		}
		aCdDcdZone.setPos( iYZahyou ) ;
		zonexyZone_Dgr.setY( aCdDcdZone ) ;
	}
		
	return m_pCWndDiagram->setZone_Dgr( zonexyZone_Dgr ) ;
}

// ----------------------------------------------------------------
IMPLEMENT_DYNCREATE(CDedDiagramView, CView)

CDedDiagramView::CDedDiagramView()
	: m_pCentDedDgrDia( NULL )
	, m_pCWndDiagram( NULL ) 
	, m_bUpdate_All_Requested( false ) 
{
}

CDedDiagramView::~CDedDiagramView()
{
	if ( m_pCentDedDgrDia != NULL ){
		delete m_pCentDedDgrDia ;
		m_pCentDedDgrDia = NULL ;
	}
}


BEGIN_MESSAGE_MAP(CDedDiagramView, CView)
	//{{AFX_MSG_MAP(CDedDiagramView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_Diagram_ViewProp, OnDiagramViewProp)
	ON_COMMAND(ID_Diagram_XDgrSize_Inc, OnDiagramXDgrSizeInc)
	ON_UPDATE_COMMAND_UI(ID_Diagram_XDgrSize_Inc, OnUpdateDiagramXDgrSizeInc)
	ON_COMMAND(ID_Diagram_XDgrSize_Dec, OnDiagramXDgrSizeDec)
	ON_UPDATE_COMMAND_UI(ID_Diagram_XDgrSize_Dec, OnUpdateDiagramXDgrSizeDec)
	ON_COMMAND(ID_Diagram_YDgrSize_Inc, OnDiagramYDgrSizeInc)
	ON_UPDATE_COMMAND_UI(ID_Diagram_YDgrSize_Inc, OnUpdateDiagramYDgrSizeInc)
	ON_COMMAND(ID_Diagram_YDgrSize_Dec, OnDiagramYDgrSizeDec)
	ON_UPDATE_COMMAND_UI(ID_Diagram_YDgrSize_Dec, OnUpdateDiagramYDgrSizeDec)
	ON_COMMAND(ID_Diagram_Memori_Down, OnDiagramMemoriDown)
	ON_UPDATE_COMMAND_UI(ID_Diagram_Memori_Down, OnUpdateDiagramMemoriDown)
	ON_COMMAND(ID_Diagram_Memori_Up, OnDiagramMemoriUp)
	ON_UPDATE_COMMAND_UI(ID_Diagram_Memori_Up, OnUpdateDiagramMemoriUp)
	ON_COMMAND(ID_Diagram_Ressyabangou, OnDiagramRessyabangou)
	ON_UPDATE_COMMAND_UI(ID_Diagram_Ressyabangou, OnUpdateDiagramRessyabangou)
	ON_COMMAND(ID_Diagram_Ressyamei, OnDiagramRessyamei)
	ON_UPDATE_COMMAND_UI(ID_Diagram_Ressyamei, OnUpdateDiagramRessyamei)
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_Diagram_YDgrSize_Reset, OnDiagramYDgrSizeReset)
	ON_UPDATE_COMMAND_UI(ID_Diagram_YDgrSize_Reset, OnUpdateDiagramYDgrSizeReset)
	ON_COMMAND(ID_Diagram_RessyasenKudari, OnDiagramRessyasenKudari)
	ON_UPDATE_COMMAND_UI(ID_Diagram_RessyasenKudari, OnUpdateDiagramRessyasenKudari)
	ON_COMMAND(ID_Diagram_RessyasenNobori, OnDiagramRessyasenNobori)
	ON_UPDATE_COMMAND_UI(ID_Diagram_RessyasenNobori, OnUpdateDiagramRessyasenNobori)
	ON_COMMAND(ID_Diagram_HideIppanekiEkimei, OnDiagramHideIppanekiEkimei)
	ON_UPDATE_COMMAND_UI(ID_Diagram_HideIppanekiEkimei, OnUpdateDiagramHideIppanekiEkimei)
	ON_COMMAND(ID_VIEW_UPDATE, OnViewUpdate)
	//}}AFX_MSG_MAP
	// �W������R�}���h
	ON_COMMAND(ID_Diagram_StopMarkDraw, &CDedDiagramView::OnDiagramStopmarkdraw)
	ON_UPDATE_COMMAND_UI(ID_Diagram_StopMarkDraw, &CDedDiagramView::OnUpdateDiagramStopmarkdraw)
	ON_COMMAND(ID_FILE_PRINT, &CDedDiagramView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDedDiagramView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView �`��

void CDedDiagramView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
}

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView �f�f

#ifdef _DEBUG
void CDedDiagramView::AssertValid() const
{
	CView::AssertValid();
}

void CDedDiagramView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDedDiagramView ���b�Z�[�W �n���h��



void CDedDiagramView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC ){
		return ;
	}
	// --------------------------------

	//pHint= 
	//	pHint�� CRfEditCmdHolder �I�u�W�F�N�g�Ȃ�A
	//	�Ή�����ҏW�R�}���h CRfEditCmd ��ێ����Ă��܂��B
	//	���̏ꍇ�Athis �� CRfEditCmd �̓��e�ɍœK������
	//	�X�V���s���܂��B
	//	NULL�Ȃ�A�S�X�V���v������Ă��܂��B

	if ( m_bUpdate_All_Requested )
	{
		//	�S�X�V���ۗ�����Ă���ꍇ�́A
		//	���̌�̓R�}���h�ɂ��œK�����ꂽ�P�̂̂����Ȃ�
		//	�X�V�v���ɑ΂��Ă��A�S�X�V���s���܂��B
		//memo:CDedDiagramView�̑S�X�V
		//	������s��Ȃ��ƁA
		//	(1)�_�C���O�����r���[���J������Ԃɂ���
		//	(2)�w��ǉ�
		//		( m_bUpdate_All_Requested =true �ƂȂ�܂����A
		//		�r���[���A�N�e�B�u�łȂ����߁A
		//		CentDedDgrDia::m_CentDedDgrEkiCont ��
		//		�X�V���s���܂���B
		//	(3)���̉w�ɉ^�s�����Ԃ���͂���
		//		�ҏW�R�}���h�� CRfEditCmd_Ressya 
		//		�Ȃ̂ŁA��Ԃ̍X�V���s���܂��B
		//		�������ACentDedDgrDia::m_CentDedDgrEkiCont ��
		//		�X�V����Ă��Ȃ����߁A�A�v���P�[�V�����G���[�ɂȂ�܂��B
		//		
		pHint = NULL ;
	}


	// --------------------------------
	//	CRfEditCmd �ɍœK�����ꂽ�X�V
	// --------------------------------
	Ou<CRfEditCmd> pCmd ;
	if ( pHint != NULL && pHint->IsKindOf( 
		RUNTIME_CLASS( CRfEditCmdHolder ) ) )
	{
		CRfEditCmdHolder* pHolder = 
			(CRfEditCmdHolder*)pHint ;
		pCmd = pHolder->getCmd() ; 
	}
	//pCmd = (pCmd��NULL�łȂ��ꍇ��)�Ή�����ҏW�R�}���h

	if ( pCmd != NULL )
	{
		if ( dynamic_castOu<CRfEditCmd_Comment>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Dia>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd ) ) 
		{
			//	���̃r���[�́A
			//		�R�����g�̕ύX
			//		�_�C���̕ύX
			//		�_�C���̃v���p�e�B�̕ύX
			//		��Ԏ�ʂ̓���
			//	�̏ꍇ�́A�X�V���s���܂���B
		}
		else if ( dynamic_castOu<CRfEditCmd_Ressya>( pCmd ) )
		{
			//	��Ԃ̕ύX
			Ou<CRfEditCmd_Ressya>	pCommand = 
				dynamic_castOu<CRfEditCmd_Ressya>( pCmd );
			OnUpdate_CentDedRessya( pCommand ) ;
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

			pHint = NULL ;	//	�S�X�V�̗v��
		}
	}

	if ( pHint == NULL )	//	�S�X�V
	{
		// --------------------------------		
		//	�S�v�f���X�V
		// --------------------------------
		CView *pView = getCDiagramEditApp()->getCMainFrame()->
			getMDIChildActiveView() ;
		if ( this == pView ){
			OnUpdate_All() ;
		}	else	{
			LogMsg( "CDedDiagramView::OnUpdate()" 
				"m_bUpdate_All_Requested=true" ) ;
			m_bUpdate_All_Requested = true ;
		}
	}

}

int CDedDiagramView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// --------------------------------
	m_pCWndDiagram = new CWndDiagram() ;
	m_pCWndDiagram->Create( this ) ;
	m_pCWndDiagram->ShowWindow( SW_SHOW ) ;

	return 0;
}

void CDedDiagramView::OnDestroy() 
{
	//	�_�C���O�����r���[�̑����� .ini �t�@�C���ɏ������݁B
	getCDiagramEditApp()->writeCWndDiagramViewProp( m_pCWndDiagram ) ;

	m_pCWndDiagram->setCentDedDgrDia( NULL ) ;
	if ( m_pCWndDiagram != NULL ){
		m_pCWndDiagram->DestroyWindow() ;
		delete m_pCWndDiagram ;
		m_pCWndDiagram = NULL ;
	}

	CView::OnDestroy();
	

	
}

void CDedDiagramView::OnSize(UINT nType, int cx, int cy) 
{
	if ( nType == SIZE_MAXIMIZED	//�E�B���h�E�͍ő�\������܂��B
		|| nType == SIZE_RESTORED 	// �E�B���h�E�̓T�C�Y�ύX����܂����A
									//	SIZE_MINIMIZED �� SIZE_MAXIMIZED ��
									//	�K�p����܂���B
	){
		//memo:CDedDiagramView::OnSize()
		//	���̊֐����g���ƁA���T�C�Y���ɃE�C���h�E�̑S�̈悪�����ɂȂ�܂��B
		m_pCWndDiagram->MoveWindow( 0 , 0 , cx , cy , TRUE ) ; 

		////memo:CDedDiagramView::OnSize()
		////	���̊֐����g���Ă��A���T�C�Y���ɃE�C���h�E��
		////	�S�̈悪�����ɂȂ�܂�
		//m_pCWndDiagram->SetWindowPos( 
		//	NULL , 
		//	0 , 0 , 
		//	cx , cy , 
		//	SWP_NOACTIVATE	//	�E�B���h�E���A�N�e�B�u�ɂ��܂���B
		//	                //	���̃t���O���ݒ肳��Ă��Ȃ��ƁA
		//	                //	�E�B���h�E�̓A�N�e�B�u�ɂȂ�A
		//	                //	�ŏ�ʂ܂��͔�ŏ�ʂ̃E�B���h�E 
		//	                //	�O���[�v�̂����ꂩ�̐擪�Ɉړ�����܂� 
		//	                //(�p�����[�^ pWndInsertAfter �̐ݒ�Ɉˑ����܂�)�B
		//	| SWP_NOZORDER	//  ���݂̏�����ێ����܂� 
		//	                //	(pWndInsertAfter �𖳎����܂�)�B
		//	| SWP_NOMOVE ) ;// ���݈ʒu��ێ����܂� 
		//	                //(x �p�����[�^�� y �p�����[�^�𖳎����܂�)�B

		////memo:CDedDiagramView::OnSize()
		////	���̊֐����g���Ă��A���T�C�Y���ɃE�C���h�E��
		////	�S�̈悪�����ɂȂ�܂��B
		//m_pCWndDiagram->MoveWindow( 0 , 0 , cx , cy , FALSE ) ; 

		return ;
	}
	
	
	CView::OnSize(nType, cx, cy);
}


void CDedDiagramView::OnDiagramViewProp() 
{
	OnDiagramViewProp_Process( FALSE );
}

void CDedDiagramView::OnDiagramXDgrSizeInc() 
{
	OnDiagramXDgrSizeInc_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramXDgrSizeInc(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramXDgrSizeInc_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramXDgrSizeDec() 
{
	OnDiagramXDgrSizeDec_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramXDgrSizeDec(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramXDgrSizeDec_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramYDgrSizeInc() 
{
	OnDiagramYDgrSizeInc_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramYDgrSizeInc(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramYDgrSizeInc_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramYDgrSizeDec() 
{
	OnDiagramYDgrSizeDec_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramYDgrSizeDec(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramYDgrSizeDec_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramYDgrSizeReset() 
{
	OnDiagramYDgrSizeReset_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramYDgrSizeReset(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(	OnDiagramYDgrSizeReset_Process( TRUE ) >= 0 );
}


void CDedDiagramView::OnDiagramMemoriDown() 
{
	OnDiagramMemoriDown_Process( FALSE ) ;
}
void CDedDiagramView::OnUpdateDiagramMemoriDown(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnDiagramMemoriDown_Process( TRUE ) >= 0 );
}

void CDedDiagramView::OnDiagramMemoriUp() 
{
	OnDiagramMemoriUp_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramMemoriUp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnDiagramMemoriUp_Process( TRUE ) >= 0 );
}


void CDedDiagramView::OnDiagramRessyabangou() 
{
	OnDiagramRessyabangou_Process( FALSE ) ;
}
void CDedDiagramView::OnUpdateDiagramRessyabangou(CCmdUI* pCmdUI) 
{
	int iResult = OnDiagramRessyabangou_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
	
}

void CDedDiagramView::OnDiagramRessyamei() 
{
	OnUpdateDiagramRessyamei_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramRessyamei(CCmdUI* pCmdUI) 
{
	int iResult = OnUpdateDiagramRessyamei_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}


void CDedDiagramView::OnDiagramRessyasenKudari() 
{
	OnDiagramRessyasenKudari_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramRessyasenKudari(CCmdUI* pCmdUI) 
{
	int iResult = OnDiagramRessyasenKudari_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}

void CDedDiagramView::OnDiagramRessyasenNobori() 
{
	OnDiagramRessyasenNobori_Process( FALSE );
}

void CDedDiagramView::OnUpdateDiagramRessyasenNobori(CCmdUI* pCmdUI) 
{
	int iResult = OnDiagramRessyasenNobori_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}


void CDedDiagramView::OnDiagramHideIppanekiEkimei() 
{
	OnDiagramHideIppanekiEkimei_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramHideIppanekiEkimei(CCmdUI* pCmdUI) 
{
	int iResult = OnDiagramHideIppanekiEkimei_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}

void CDedDiagramView::OnDiagramStopmarkdraw()
{
	OnDiagramStopmarkdraw_Process( FALSE ) ;
}

void CDedDiagramView::OnUpdateDiagramStopmarkdraw(CCmdUI *pCmdUI)
{
	int iResult = OnDiagramStopmarkdraw_Process( TRUE ) ;
	pCmdUI->Enable( iResult >= 0 ) ;
	pCmdUI->SetCheck( iResult >= 1 ) ;
}

void CDedDiagramView::OnViewUpdate() 
{
	OnViewUpdate_Process( FALSE );
}



BOOL CDedDiagramView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	BOOL bRv = TRUE ;

	// �f�t�H���g�̈������
	CaDcdDiagram_PageSelector	aPageSelector( 
		m_pCWndDiagram->getCDcdDiagram() , 
		m_sizePrintSize_Dgr ) ;
	if ( bRv )
	{
		if ( aPageSelector.getPageCount() == 0 )
		{
			//	�������y�[�W������܂���B
			bRv = FALSE ;
		}
	}
	if ( bRv )
	{
		//	�E�C���h�E��Ƀ_�C���O�������\������Ă��Ȃ��ꍇ�́A
		//	����͍s���܂���B
		if ( m_pCWndDiagram->calcDiagramZoneDcd().getX().getSize() <= 0 ||
			m_pCWndDiagram->calcDiagramZoneDcd().getY().getSize() <= 0 )
		{
			//	�������y�[�W������܂���B
			bRv = FALSE ;
		}
	}
	// --------------------------------

	if ( bRv )
	{
		pInfo->SetMinPage( 1 ) ;
		pInfo->SetMaxPage( aPageSelector.getPageCount()  ) ;

		bRv = DoPreparePrinting(pInfo);
	}
	
	return bRv ;
}

void CDedDiagramView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	//	���̎��_�ł́A 
	//	pInfo->m_rectDraw
	//	�̒l�͌��肵�Ă��܂���B

	if ( m_bUpdate_All_Requested ){
		OnUpdate_All() ;
	}


	CView::OnBeginPrinting(pDC, pInfo);
}

void CDedDiagramView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	//	���̎��_�ł́A 
	//	pInfo->m_rectDraw
	//	�̒l�͌��肵�Ă��܂���B

	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	
	CView::OnPrepareDC(pDC, pInfo);
}


static CdDrawTextProp	getCdDrawTextPropStandard()
{ 
	const CDedRosenFileData* pCDedRosenFileData = 
		getCDiagramEditDoc()->getCDedRosenFileData() ;
	CdDedDispProp aCdDedDispProp = pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		aCdDedDispProp.getDiaJikokuFont() ,
		CdColorProp( 0 , 0 , 0 ) ) ;
}


void CDedDiagramView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	LogMsg( "CDedDiagramView::OnPrint() " ) ;
	LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;

	// --------------------------------
	//	�`��ʂ��쐬
	// --------------------------------
	CDcdTargetMfcPrintInfo	aCDcdTargetMfcPrintInfo( pDC, pInfo ) ;

	LogMsg( "CDedDiagramView::OnPrint()1" ) ;
	
	// --------------------------------
	//	�]�����������̈���쐬
	// --------------------------------
	CaDcdTargetItemPosition	aTargetInnerMargin( &aCDcdTargetMfcPrintInfo , 
		CdDcdZoneXy() ) ;
	{
		LogMsg( DeviceCapsToString( 
			aCDcdTargetMfcPrintInfo.getPrinterHdc() ).c_str() ) ;
	
		CconvCdPrintPageProp aCconvCdPrintPageProp ;
		CdDcdZoneXy	zonexyInneraMargin = 
			aCconvCdPrintPageProp.calcZoneInnerMargin( 
				getCDiagramEditApp()->getCdPrintPageProp() , 
				aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
		if ( zonexyInneraMargin.getX().getSize() <= 0 ){
			zonexyInneraMargin.setX( 
				aCDcdTargetMfcPrintInfo.getZone().getX() ) ;
		}
		if ( zonexyInneraMargin.getY().getSize() <= 0 ){
			zonexyInneraMargin.setY( 
				aCDcdTargetMfcPrintInfo.getZone().getY() ) ;
		}

		aTargetInnerMargin.setZone( zonexyInneraMargin ) ;

	}

	//aTargetInnerMargin = �]���������������`��̈�B
	//	�P�ʂ̓v�����^�̃s�N�Z���ł��B

	LogMsg( "CDedDiagramView::OnPrint()2" ) ;
	// --------------------------------
	//	�_�����W��ݒ�
	// --------------------------------
	CaDcdTargetZoomDisplay	aCaDcdTargetZoomDisplay( 
		&aTargetInnerMargin , 
		aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
	//aCaDcdTargetZoomDisplay = �]���������������`��̈�B
	//	�P�ʂ́A��ʏ�̂P�s�N�Z�������ɂȂ�܂����B

	LogMsg( "CDedDiagramView::OnPrint()3" ) ;
	
	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ��̕��i���쐬
	// --------------------------------
	Ou<CDcdText>	pdcdCaption ;
	Ou<CDcdText>	pdcdPage ;
	{
		const CentDedRosen* pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		CJikokuhyouDoc* pCJikokuhyouDoc = (CJikokuhyouDoc*)GetDocument() ;

		string	strText ;
		//	�H����
		if ( !pCentDedRosen->getName().empty() ){
			strText += pCentDedRosen->getName() ;
			strText += " " ;
		}
		//	�_�C����
		if ( !pCJikokuhyouDoc->getDiaName().empty() ){
			strText += pCJikokuhyouDoc->getDiaName() ;
			strText += " " ;
		}
		pdcdCaption = OuNew<CDcdText>( new CDcdText( 
			strText , getCdDrawTextPropStandard() ) ) ;
	}
	// --------------------------------
	{
		CdDrawTextProp	aProp = getCdDrawTextPropStandard() ;
		CdDrawTextFormat	aFormat = aProp.getCdDrawTextFormat() ;
		aFormat.setHorizontal( aFormat.H_CENTER ) ;
		aProp.setCdDrawTextFormat( aFormat ) ;
		pdcdPage = OuNew<CDcdText>( new CDcdText( "" ,aProp , "99" ) ) ;
	}

	LogMsg( "CDedDiagramView::OnPrint()4" ) ;
	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ��̕��i�E
	//	�O���b�h�̃��C�A�E�g�����߂�	
	// --------------------------------
	Ou<IfDcdTarget>	pTargetCaption ;
	Ou<IfDcdTarget>	pTargetGrid ;
	Ou<IfDcdTarget>	pTargetPage ;
	{
		CdDcdZoneXy	zoneGrid = aCaDcdTargetZoomDisplay.getZone() ;
		CdDcdSizeXy	aSize ;

		pdcdCaption->getItemSize( &aCaDcdTargetZoomDisplay , &aSize ) ;
		CdDcdZoneXy zoneCaption( zoneGrid.getX() , 
			CdDcdZone( zoneGrid.getY().getPos() , aSize.getY() ) ) ;
		zoneGrid.setY( CdDcdZone().setBeginEndPos( 
			zoneCaption.getY().getEndPos() , zoneGrid.getY().getEndPos() ) ) ;
		//zoneCaption = �S�̈�̏㕔���A�L���v�V�����p�Ɋ��蓖�ĂĂ��܂��B
		//zoneGrid = �S�̈悩��A�㕔�̃L���v�V�����̈���������̈�ł��B

		pdcdPage->getItemSize( &aCaDcdTargetZoomDisplay , &aSize ) ;
		CdDcdZoneXy zonePage( zoneGrid.getX() , 
			CdDcdZone( zoneGrid.getY().getEndPos() - aSize.getY() , 
				aSize.getY() ) ) ;
		zoneGrid.setY( CdDcdZone().setBeginEndPos( 
			zoneCaption.getY().getEndPos() , zonePage.getY().getPos() ) ) ;
		//zonePage = �S�̈�̉������A�y�[�W�p�Ɋ��蓖�ĂĂ��܂��B
		//zoneGrid = �㕔�̃L���v�V�����ɑ����āA�����̃y�[�W�̈��������
		//			�̈�ł��B


		pTargetCaption = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( 
				&aCaDcdTargetZoomDisplay , zoneCaption ) ) ;
		pTargetGrid = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( 
				&aCaDcdTargetZoomDisplay , zoneGrid ) ) ;
		pTargetPage = OuNew<CaDcdTargetItemPosition>(
			new CaDcdTargetItemPosition( 
				&aCaDcdTargetZoomDisplay , zonePage ) ) ;
	}
	// --------------------------------
	//	�_�C���O������`��
	// --------------------------------
	int iPage = 0 ;
	int iXPage = 0 ;
	{
		CDcdDiagram2*	pCDcdDiagram2 = m_pCWndDiagram->getCDcdDiagram() ;
		CaDcdDiagram_PageSelector	aPageSelector( 
			pCDcdDiagram2 , 
			m_sizePrintSize_Dgr ) ;
		aPageSelector.setPage( pInfo->m_nCurPage - 1 ) ;
		aPageSelector.DcDraw( pTargetGrid ) ;

		if ( (int)pInfo->m_nCurPage >= aPageSelector.getPageCount() ){
			//�ŏI�y�[�W�����������A������[�v���I���܂��B
			pInfo->m_bContinuePrinting = false ;
		}	else	{
			pInfo->m_bContinuePrinting = true ;
		}


		iPage = aPageSelector.getPage() ;
		iXPage = aPageSelector.getXPage() ;
	}

	LogMsg( "CDedDiagramView::OnPrint()5" ) ;
	LogMsg( "CDedDiagramView::OnPrint()6" ) ;
	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ��̃e�L�X�g���쐬
	// --------------------------------
	{
		//�L���v�V�����Ƀy�[�W��ǉ�
		{
			string	strCaption = pdcdCaption->getText() ;
			CString	strSono ;
			strSono.Format( IDS_WORD_Sono , iXPage + 1 ) ;
			strCaption += (LPCTSTR)strSono ;
			strCaption += " " ;
			pdcdCaption->setText( strCaption ) ;
		}
		//�y�[�W�ԍ�������
		{
			string	strPage = stringOf( iPage + 1) ;
			pdcdPage->setText( strPage ) ;
		}
	}

	LogMsg( "CDedDiagramView::OnPrint()7" ) ;
	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ���`��
	// --------------------------------
	{
			pdcdCaption->DcDraw( pTargetCaption ) ;
			pdcdPage->DcDraw( pTargetPage ) ;
	}
	// --------------------------------
	
	//CView::OnPrint(pDC, pInfo);
}

void CDedDiagramView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{

	//	����I����ɉ�ʕ\����������������B
	//
	//	���̃N���X�́A������̓X�N���[���ʒu��
	//	�ꎞ�I�ɕύX���܂��B
	//	���̂Ƃ��� m_pCWndDiagram �ɍĕ`�悪��������ƁA
	//	��ʂɂ͈ꎞ�I�Ɉʒu�̕ύX���ꂽ�R���e���c��
	//	�`�悳��邽�߁A��ʂ�����܂��B
	m_pCWndDiagram->Invalidate() ;
	
	CView::OnEndPrinting(pDC, pInfo);
}

void CDedDiagramView::OnSetFocus(CWnd* pOldWnd) 
{
	//CView::OnSetFocus(pOldWnd);
	CWnd*	pControl = GetNextDlgTabItem( (CWnd*)NULL , FALSE ) ;
	pControl->SetFocus() ;
	
}


void CDedDiagramView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	LogMsg( "CDedDiagramView::OnActivateView(%d,,)" , bActivate ) ;
	
	if ( bActivate && m_bUpdate_All_Requested ){
		OnUpdate_All() ;
	}
	
	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}



void CDedDiagramView::OnFilePrint()
{
	//	������ɁA�P�y�[�W�Ɉ������_�C���O�����͈̔͂�ۑ�
	m_sizePrintSize_Dgr = m_pCWndDiagram->getZone_Dgr().getSize() ;

	CView::OnFilePrint() ;
}

void CDedDiagramView::OnFilePrintPreview()
{
	//	������ɁA�P�y�[�W�Ɉ������_�C���O�����͈̔͂�ۑ�
	m_sizePrintSize_Dgr = m_pCWndDiagram->getZone_Dgr().getSize() ;

	CView::OnFilePrintPreview() ;
}
} // namespace ViewDiagram
