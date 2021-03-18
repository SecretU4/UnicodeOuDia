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
//	CRfEditCmd_Ressya.cpp
// $Id: CRfEditCmd_Ressya.cpp 366 2016-08-18 20:26:22Z okm $
// ****************************************************************
*/
#include "stdafx.h"
#include <stdlib.h>
#include "NsOu/OuNew.h"
#include "NsMu/CaMui.h"
#include "CRfEditCmd_Ressya.h"

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

#ifndef min
#define min	__min	 
#endif /*min*/

namespace DedRosenFileData{ namespace EditCmd{

// ****************************************************************
//	CRfEditCmd_Ressya
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CRfEditCmd_Ressya::CRfEditCmd_Ressya( 
		int iDiaIndex ,
		ERessyahoukou eERessyahoukou ,
		int iIndexDst , 
		int iSizeDst , 
		const CentDedRessyaCont& aCentDedRessyaContSrc ) :
	m_iDiaIndex( iDiaIndex ) ,
	m_ERessyahoukou( eERessyahoukou ) ,
	m_iIndexDst( iIndexDst ) ,
	m_iSizeDst( iSizeDst ) ,
	m_CentDedRessyaContSrc( aCentDedRessyaContSrc ) ,
	m_CaMuiSelect( &m_CentDedRessyaContSrc , m_CentDedRessyaContSrc.getMuPtr() ) ,
	m_pCentDedRessyaContOld( NULL ) 
{
	m_CaMuiSelect.setSelectAll( true ) ;
}


CRfEditCmd_Ressya::CRfEditCmd_Ressya( 
		const CDedRosenFileData& aCDedRosenFileData ,
		int iDiaIndex ,
		ERessyahoukou eRessyahoukou , 
		int iIndex , 
		int iSize ) 
		:
		m_iDiaIndex( iDiaIndex ) ,
		m_ERessyahoukou( eRessyahoukou ) ,
		m_iIndexDst( iIndex ) ,
		m_iSizeDst( iSize ) ,
		m_CentDedRessyaContSrc( aCDedRosenFileData.getCentDedRosen()->getCentDedDiaCont()
			->getMuPtr()->get( iDiaIndex )
			->getCentDedRessyaCont(eRessyahoukou )->createEmptyCont() ) ,
		m_CaMuiSelect( &m_CentDedRessyaContSrc , m_CentDedRessyaContSrc.getMuPtr() ) ,
		m_pCentDedRessyaContOld( NULL ) 
{
	const CentDedRessyaCont* pCentDedRessyaCont = aCDedRosenFileData.getCentDedRosen()->getCentDedDiaCont()->getMuPtr()->get( iDiaIndex )->getCentDedRessyaCont(eRessyahoukou) ; 

	CaMui<CentDedRessya> aMui( &m_CaMuiSelect ) ;
	aMui.insert( pCentDedRessyaCont , iIndex , iSize ) ;

	m_CaMuiSelect.setSelectAll( true ) ;
}


CRfEditCmd_Ressya::~CRfEditCmd_Ressya()
{
	if ( m_pCentDedRessyaContOld != NULL ){
		delete m_pCentDedRessyaContOld ;
		m_pCentDedRessyaContOld = NULL ;
	}
}

// ********************************
///	CRfEditCmd-����
// ********************************
int CRfEditCmd_Ressya::execute( 
		CDedRosenFileData* pCDedRosenFileData ) 
{
	int iRv = 0 ;
	// --------------------------------
	CentDedRosen*	pCentDedRosen = pCDedRosenFileData->getCentDedRosen() ;
	CentDedDia*	pCentDedDia = NULL ;
	if ( iRv >= 0 ){
		pCentDedDia =  pCentDedRosen->getCentDedDiaCont()->getMuPtr()->get( m_iDiaIndex ) ;
		if ( pCentDedDia == NULL ){
			iRv = -2 ;	//	m_iDiaIndex �̒l���s���ł��B
		}
	}
	CentDedRessyaCont*	pCentDedRessyaCont = NULL ;
	if ( iRv >= 0 ){
		pCentDedRessyaCont = pCentDedDia->getCentDedRessyaCont( m_ERessyahoukou ) ;
		if ( m_iIndexDst == INT_MAX ){
			m_iIndexDst = pCentDedRessyaCont->size() ;
		}
		if ( !( 0 <= m_iIndexDst && 
				m_iIndexDst <= pCentDedRessyaCont->size() - m_iSizeDst ) ){
			iRv = -1 ;	//	m_iIndexDst �̒l���s���ł��B
		}
	}
	// --------------------------------
	//	�폜�v�f�̕ۑ�
	// --------------------------------
	if ( iRv >= 0 ){
		if ( m_pCentDedRessyaContOld != NULL ){
			delete m_pCentDedRessyaContOld ;
			m_pCentDedRessyaContOld = NULL ;
		}
		m_pCentDedRessyaContOld = new CentDedRessyaCont( 
			pCentDedRessyaCont->createEmptyCont() ) ;
		CaMui<CentDedRessya>	aCaCont( m_pCentDedRessyaContOld ) ;
		aCaCont.insert( 
			pCentDedRessyaCont , 
			m_iIndexDst , 
			m_iSizeDst , 0 ) ;

	}

	// --------------------------------
	//	�������̗v�f�̍폜
	// --------------------------------
	if ( iRv >= 0 ){
		int iGensyouSize = m_iSizeDst - m_CentDedRessyaContSrc.size() ;
		if ( iGensyouSize > 0 ){
			int iResult = pCentDedRessyaCont->erase( 
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
	if ( iRv >= 0 ){
		iOkikaeSize = min( m_iSizeDst , m_CentDedRessyaContSrc.size() ) ;
		for ( int cnt = 0 ; iRv >= 0 && cnt < iOkikaeSize ; cnt ++ ){
			int iResult = pCentDedRessyaCont->set( 
				m_CentDedRessyaContSrc.get( cnt ) , 
				m_iIndexDst + cnt )  ;
			if ( iResult < 0 ){
				iRv = -13 ;	//	�v�f�̒u�������Ɏ��s���܂����B
			}
		}
	}

	// --------------------------------
	//	�������̗v�f�̒ǉ�
	// --------------------------------
	if ( iRv >= 0 ){
		int iZoukaSize = m_CentDedRessyaContSrc.size() - m_iSizeDst ;
		if ( iZoukaSize > 0 ){
			for ( int cnt = 0 ; iRv >= 0 && cnt < iZoukaSize ; cnt ++ ){
				int iResult = pCentDedRessyaCont->insert(
					m_CentDedRessyaContSrc.get( iOkikaeSize + cnt ) ,
					m_iIndexDst + iOkikaeSize + cnt ) ; 
				if ( iResult < 0 ){
					iRv = -12 ;	//	�v�f�̒ǉ��Ɏ��s���܂����B
				}
			}
		}

	}

	return ( iRv ) ;
}
Ou<CRfEditCmd> 
CRfEditCmd_Ressya::createUndoCmd()  
{
	if ( m_pCentDedRessyaContOld != NULL ){
		OuNew<CRfEditCmd>	pCmd(  
			new CRfEditCmd_Ressya( 
				m_iDiaIndex ,
				m_ERessyahoukou , 
				m_iIndexDst , 
				m_CentDedRessyaContSrc.size() ,
				*m_pCentDedRessyaContOld 
			) ) ;
		delete m_pCentDedRessyaContOld ;
		m_pCentDedRessyaContOld = NULL ;
		return pCmd ; 
	}
	return ( Ou<CRfEditCmd>() ) ;
}
	

} } // namespace EditCmd namespace DedRosenFileData

