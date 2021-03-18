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
//	CRfEditCmd_Eki.cpp
// $Id: CRfEditCmd_Eki.cpp 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
#include "stdafx.h"
#include "NsOu/OuNew.h"
#include "NsMu/CaMui.h"
#include "CRfEditCmd_Eki.h"


#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif


namespace DedRosenFileData{ namespace EditCmd{


// ****************************************************************
//	CRfEditCmd_Eki
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CRfEditCmd_Eki::CRfEditCmd_Eki( 
		int iIndexDst ,
		int iSizeDst ,
		const CentDedEkiCont& aCentDedEkiContSrc ,
		bool bAdjustByEkijikokukeisiki ):
	m_iIndexDst( iIndexDst ) ,
	m_iSizeDst( iSizeDst ) ,
	m_CentDedEkiContSrc( aCentDedEkiContSrc ) ,
	m_CaMuiSelect( &m_CentDedEkiContSrc ,  m_CentDedEkiContSrc.getMuPtr() ) ,
	m_bAdjustByEkijikokukeisiki( bAdjustByEkijikokukeisiki ),
	m_pCentDedEkiContOld( NULL ) ,
	m_pCentDedRosen( NULL ) 
{
	m_CaMuiSelect.setSelectAll( true ) ;
}

CRfEditCmd_Eki::CRfEditCmd_Eki( 
		const CDedRosenFileData& aCDedRosenFileData ,
		int iIndexDst , 
		int iSizeDst ,
		bool bAdjustByEkijikokukeisiki ):
	m_iIndexDst( iIndexDst ) ,
	m_iSizeDst( iSizeDst ) ,
	m_CentDedEkiContSrc() ,
	m_bAdjustByEkijikokukeisiki( bAdjustByEkijikokukeisiki ),
	m_CaMuiSelect( &m_CentDedEkiContSrc ,  m_CentDedEkiContSrc.getMuPtr() ) ,
	m_pCentDedEkiContOld( NULL ) ,
	m_pCentDedRosen( NULL ) 
{
	const CentDedEkiCont* pCentDedEkiCont = aCDedRosenFileData.getCentDedRosen()->getCentDedEkiCont() ; 

	CaMui<CentDedEki> aMui( &m_CaMuiSelect ) ;
	aMui.insert( pCentDedEkiCont , iIndexDst , iSizeDst ) ;

	m_CaMuiSelect.setSelectAll( true ) ;
}
	



CRfEditCmd_Eki::~CRfEditCmd_Eki() 
{
	if ( m_pCentDedEkiContOld != NULL )
	{
		delete m_pCentDedEkiContOld ;
		m_pCentDedEkiContOld = NULL ;
	}
	if ( m_pCentDedRosen !=  NULL ) 
	{
		delete m_pCentDedRosen ;
		m_pCentDedRosen = NULL ;
	}
}
// ********************************
//@name	CRfEditCmd-����
// ********************************
int CRfEditCmd_Eki::execute( CDedRosenFileData* pCDedRosenFileData ) 
{
	int iRv = 0 ;
	// --------------------------------
	CentDedRosen*	pCentDedRosen = pCDedRosenFileData->getCentDedRosen() ;
	CentDedEkiCont*	pCentDedEkiCont = pCentDedRosen->getCentDedEkiCont() ;
	if ( iRv >= 0 ){
		if ( m_iIndexDst == INT_MAX && m_iSizeDst == INT_MAX ){
			iRv = -1 ;	//	m_iIndexDst �̒l���s���ł��B
		}	else	{
			if ( m_iIndexDst == INT_MAX ){
				m_iIndexDst = pCentDedEkiCont->size()  - m_iSizeDst ;
			}	else if ( m_iSizeDst == INT_MAX ){
				m_iSizeDst = pCentDedEkiCont->size() - m_iIndexDst ;
			}
			if ( !( 0 <= m_iIndexDst && 
				m_iIndexDst + m_iSizeDst<= pCentDedEkiCont->size() ) ){
				iRv = -1 ;	//	m_iIndexDst �̒l���s���ł��B
			}
		}
	}
	// --------------------------------
	//	�폜�f�[�^��ۑ�
	// --------------------------------
	if ( iRv >= 0 ){
		if ( m_pCentDedEkiContOld != NULL ){
			delete m_pCentDedEkiContOld ;
			m_pCentDedEkiContOld = NULL ;
		}
		if ( m_pCentDedRosen != NULL ){
			delete m_pCentDedRosen ;
			m_pCentDedRosen = NULL ;
		}
		//	[�w�������w�����`���ɐ��K������]�ݒ�=OFF
		//	AND �v�f��u�����E�܂��͒ǉ����s�����ꍇ
		//	(�w�������ω����Ă��Ȃ��ꍇ)
		if ( !m_bAdjustByEkijikokukeisiki &&
			m_iSizeDst <= m_CentDedEkiContSrc.size() )
		{
			m_pCentDedEkiContOld = new CentDedEkiCont() ;
			CaMui<CentDedEki>	aCaCont( m_pCentDedEkiContOld ) ;
			aCaCont.insert( 
				pCentDedEkiCont , 
				m_iIndexDst , 
				m_iSizeDst , 0 ) ;
		}
		//	[�w�������w�����`���ɐ��K������]�ݒ�=ON
		//	OR �v�f�̍팸 �̏ꍇ�́A
		//	�H���S�̂�ۑ�����K�v������܂�
		//	(�ҏW����ŏ��ł���w�������������邽��)
		else
		{
			m_pCentDedRosen = new CentDedRosen( *pCentDedRosen ) ; 
		}
	}
	// --------------------------------
	//	�������̗v�f�̍폜
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iGensyouSize = m_iSizeDst - m_CentDedEkiContSrc.size() ;
		if ( iGensyouSize > 0 ){
			int iResult = pCentDedEkiCont->erase( 
				m_iIndexDst + m_iSizeDst - iGensyouSize , 
				iGensyouSize
			) ;
			if ( iResult < 0 ){
				iRv = -11 ;	//	�v�f�̍폜�Ɏ��s���܂����B
			}
		}
	}
	// --------------------------------
	//	�v�f�̒u������
	// --------------------------------
	int iOkikaeSize = 0 ;
	if ( iRv >= 0 )
	{
		iOkikaeSize = min( m_iSizeDst , m_CentDedEkiContSrc.size() ) ;
		for ( int cnt = 0 ; iRv >= 0 && cnt < iOkikaeSize ; cnt ++ ){
			int iResult = pCentDedEkiCont->set( 
				m_CentDedEkiContSrc.get( cnt ) , 
				m_iIndexDst + cnt )  ;
			if ( iResult < 0 ){
				iRv = -13 ;	//	�v�f�̒u�������Ɏ��s���܂����B
			}
		}
	}
	// --------------------------------
	//	�������̗v�f�̒ǉ�
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iZoukaSize = m_CentDedEkiContSrc.size() - m_iSizeDst ;
		if ( iZoukaSize > 0 )
		{
			for ( int cnt = 0 ; iRv >= 0 && cnt < iZoukaSize ; cnt ++ )
			{
				int iResult = pCentDedEkiCont->insert(
					m_CentDedEkiContSrc.get( iOkikaeSize + cnt ) ,
					m_iIndexDst + iOkikaeSize + cnt ) ; 
				if ( iResult < 0 )
				{
					iRv = -12 ;	//	�v�f�̒ǉ��Ɏ��s���܂����B
				}
			}
		}

	}
	// --------------------------------
	//	[�w�������w�����`���ɐ��K������]�ݒ�B
	// --------------------------------
	if ( iRv >= 0 && m_bAdjustByEkijikokukeisiki )
	{
		for ( int cnt = 0 ; 
			iRv >= 0 && cnt < m_CentDedEkiContSrc.size() ;
			cnt ++ )
		{
			pCentDedRosen->adjustByEkijikokukeisiki( m_iIndexDst + cnt ) ;
		}
	}
	// --------------------------------
	return ( iRv ) ;
}
	
Ou<CRfEditCmd> CRfEditCmd_Eki::createUndoCmd() 
{
	if ( m_pCentDedEkiContOld != NULL )
	{
		OuNew<CRfEditCmd>	pCmd( 
			new CRfEditCmd_Eki( 
				m_iIndexDst ,
				m_CentDedEkiContSrc.size() ,
				*m_pCentDedEkiContOld ,
				false ) ) ;
		delete m_pCentDedEkiContOld ;
		m_pCentDedEkiContOld = NULL ;
		return pCmd ;
	}
	if ( m_pCentDedRosen != NULL )
	{
		OuNew<CRfEditCmd>	pCmd( 
			new CRfEditCmd_Rosen( 
				*m_pCentDedRosen  ) ) ;
		delete m_pCentDedRosen ;
		m_pCentDedRosen = NULL ;
		return pCmd ;
	}
	return ( Ou<CRfEditCmd>() ) ;
}
	
} } // namespace EditCmd namespace DedRosenFileData
