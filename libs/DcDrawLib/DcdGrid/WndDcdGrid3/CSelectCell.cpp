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
//$Id: CSelectCell.cpp 324 2016-06-12 03:03:55Z okm $
// ****************************************************************
*/
/** @file */


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CSelectCell.h"
#include "DcdGrid\WndDcdGrid3\CSelect.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "LogMsg\LogMsg.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{


// ****************************************************************
//	WndDcdGrid3::CSelectCell
// ****************************************************************
		// ********************************
		//	�R���X�g���N�^
		// ********************************
CSelectCell::CSelectCell(
		CSelect* pOuter , 
		CSelectYColumnCellCont* pCont ) 
		: m_pOuter( pOuter )
		, m_pCont( pCont ) 
		, m_bIsSelected( false ) 
		, m_bIsSelected_Prev( false ) 
{
}
		// --------------------------------
		//@name CWndDcdGrid ����̈Ϗ�
		// --------------------------------
bool CSelectCell::update_adjustProp() 
{
	bool bRv = false ;
	return bRv ;
}


bool CSelectCell::update_updateScreen( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;


	if ( m_bIsSelected_Prev != m_bIsSelected )
	{
		int iXColumnNumber = m_pOuter->getXColumnNumberOfCell( this ) ;
		int iYColumnNumber = m_pOuter->getYColumnNumberOfCell( this ) ;

		//	�C�x���g�����̂��߂̉��z�֐��Ăяo��
		m_pOuter->getCWndDcdGrid()->OnChangeSelectCell( 
			iXColumnNumber , iYColumnNumber , m_bIsSelected ) ;

		//	�I���X�V���́A�̈�𖳌������܂��B
		{
			CdDcdZoneXy	zonexyCell = m_pOuter->getZoneOfCellSelection(
				pIfDcdTarget , 
				iXColumnNumber , iYColumnNumber , 
				m_pOuter->getIncludeRbBorder() ) ;

			m_pOuter->getCWndDcdGrid()->InvalidateRect( 
				&CConverter_WinGdi().RECTOf( zonexyCell ) , true ) ;
		}
		m_bIsSelected_Prev = m_bIsSelected ;
		bRv = true ;
	}
	return bRv ;
}


		// ********************************
		///@name CSelectCell ����
		// ********************************
bool CSelectCell::getIsSelected()const 
{
	return m_bIsSelected ;
}
void CSelectCell::setIsSelected( bool value ) 
{
	//LogMsg( "CSelectCell::setIsSelected( %d )" , value ) ;

	//	�I�����[�h�� CSelect::SelectMode_NONE �̏ꍇ�́A
	//	�I����Ԃɂł��܂���B
	if ( m_pOuter->getSelectMode() == CSelect::SelectMode_NONE )
	{
		value = false ;
	}


	if ( m_bIsSelected != value )
	{
		m_bIsSelected = value ;

		if ( m_pOuter->getUpdateCWndDcdGrid() )
		{
			//	CWndDcdGrid �̑S�Ă̏W��I�u�W�F�N�g���X�V
			m_pOuter->getCWndDcdGrid()->update() ;
		}
	}
	//LogMsg( "\tm_bIsSelected=%d m_bIsSelected_Prev=%d" , m_bIsSelected , m_bIsSelected_Prev ) ;
	//LogMsg( "CSelectCell::setIsSelected()=" ) ;
}

bool CSelectCell::getIsSelected_Prev()const 
{
	return m_bIsSelected_Prev ;
}

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib
