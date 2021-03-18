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
//	CRandomSelect.cpp
//	$Id: CRandomSelect.cpp 324 2016-06-12 03:03:55Z okm $
// ****************************************************************
*/
/** @file */

#include "DcdGrid\WndDcdGrid3\CRandomSelect.h"
#include "DcdGrid\WndDcdGrid3\CFocus.h"
#include "DcdGrid\WndDcdGrid3\CXDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

	// --------------------------------
	//@name �����֐�
	// --------------------------------
CSelectCell* CRandomSelect::getFocusSelectCell() 
{
	CSelectCell* pCell = NULL ;

	CdDcdPosXy	xyFocusCellColumnNumber =
		m_pCWndDcdGrid->getCFocus()->getFocusCellColumnNumber() ;
	if ( xyFocusCellColumnNumber != CFocus::ColumnNumberPosXy_NULL() )
	{
		pCell = m_pCWndDcdGrid->getCSelect()->getCell( 
			xyFocusCellColumnNumber.getX() ,
			xyFocusCellColumnNumber.getY() ) ;
	}
	return pCell ;
}

	// --------------------------------
	//@name update_adjustProp �����֐�
	// --------------------------------
bool CRandomSelect::update_adjustProp_updateColumnNumberSelect() 
{
	bool bRv = false ;

	//	�ύX�Ώۂ̒l�̃L���b�V��
	CdDcdPosXy posxyColumnNumberAnchorCellNew = m_ColumnNumberAnchorCell ;

	//	�����l��false�B
	//	���ׂẴZ���̑I����Ԃ���������K�v������Ɣ��f���ꂽ���_�� true �B
	bool bClearSelectRequired = false ;

	CdDcdPosXy	aColumnNumberFocus = 
		m_pCWndDcdGrid->getCFocus()->getFocusCellColumnNumber() ;
	//aColumnNumberFocus = �t�H�[�J�X�Z���̗�ԍ�

	// ----------------------------------------------------------------
	//	�A���J�[�Z���̐��K��(�A���J�[�Z�����O���b�h�͈̔͊O�Ȃ�A
	//	NULL �ɏC��
	// ----------------------------------------------------------------
	if ( posxyColumnNumberAnchorCellNew != ColumnNumberPosXy_NULL() )
	{
		if ( !( 
			0 <= m_ColumnNumberAnchorCell.getX() && 
			m_ColumnNumberAnchorCell.getX() < m_pCWndDcdGrid->getCXDcdGrid()->getXColumnCount() &&
			0 <= m_ColumnNumberAnchorCell.getY() && 
			m_ColumnNumberAnchorCell.getY() < m_pCWndDcdGrid->getCXDcdGrid()->getYColumnCount() ) )
		{
			posxyColumnNumberAnchorCellNew = ColumnNumberPosXy_NULL() ;
		}
	}

	// ----------------------------------------------------------------
	//	�t�H�[�J�X�Z���̈ړ��ɏ]����
	//	m_ColumnNumberSelect,m_ColumnNumberAnchorCell ���X�V���܂��B
	// ----------------------------------------------------------------

	CSelect*	pCSelect = m_pCWndDcdGrid->getCSelect() ;
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		pCSelect->getColumnNumberSelectLimitRegularized() ;
	//zonexyColumnNumberSelectLimit = �I���\�ȃZ���̗�ԍ��͈̔́B

	// --------------------------------
	//��Ctrl��Shift��������Ȃ���ԂŁA�h���b�O(MouseMove,�^�C�}�X�N���[��)�ȊO�ɂ��t�H�[�J�X�ړ�
	//�@�� �A���J�[�Z���͍X�V�B���ׂẴZ���̑I����Ԃ������B
	// --------------------------------

	if ( m_ColumnNumberFocus_Old != aColumnNumberFocus )
	{	//	�t�H�[�J�X�Z�����ړ�
		if ( !m_pCWndDcdGrid->isCtrlPressed() && 
			!m_pCWndDcdGrid->isShiftPressed() && 
			!m_pCWndDcdGrid->isDragging() )
		{	//��Ctrl��Shift��������Ȃ���ԂŁA
			//	�h���b�O(MouseMove,�^�C�}�X�N���[��)�ȊO�ɂ��t�H�[�J�X�ړ�
			
			//�A���J�[�Z���͍X�V�B
			posxyColumnNumberAnchorCellNew = aColumnNumberFocus ;

			// ���ׂẴZ���̑I����Ԃ�����
			bClearSelectRequired = true ;
		}
		// --------------------------------
	}
	
	// --------------------------------
	//	��Ctrl�������ꂽ��ԂŁA�h���b�O�ȊO�ɂ��t�H�[�J�X�ړ�
	//	�@���A���J�[�Z���̑I����Ԃ�I���ɂ���B
	//	�@�@�A���J�[�Z����NULL�ɂ���B(RandomSelect�̃A���J�[�Z���́A
	//	�@�@RandomSelect�ɂ�鏉��̑I���g�O�����s��ꂽ��ɁA
	//	�@�@1�񂾂��I����Ԃɂ��܂��B)
	// --------------------------------
	if ( m_ColumnNumberFocus_Old != aColumnNumberFocus )
	{	//	�t�H�[�J�X�Z�����ړ�
		if ( m_pCWndDcdGrid->isCtrlPressed() && 
			!m_pCWndDcdGrid->isDragging() )
		{
				//	���A���J�[�Z���̑I����Ԃ�I���ɂ���B
				{
					CSelectCell* pCell = NULL ;
					if ( m_ColumnNumberAnchorCell != CFocus::ColumnNumberPosXy_NULL() )
					{
						pCell = m_pCWndDcdGrid->getCSelect()->getCell( 
							m_ColumnNumberAnchorCell.getX() ,
							m_ColumnNumberAnchorCell.getY() ) ;
						if ( pCell != NULL )
						{
							pCell->setIsSelected( true ) ;
						}
						m_ColumnNumberAnchorCell = CFocus::ColumnNumberPosXy_NULL() ;
					}
				}
		}
	}



	// ----------------------------------------------------------------
	//	�����̍X�V
	// ----------------------------------------------------------------
	if ( m_ColumnNumberAnchorCell != posxyColumnNumberAnchorCellNew )
	{
		m_ColumnNumberAnchorCell = posxyColumnNumberAnchorCellNew ;
		bRv = true ;
	}
	if ( bClearSelectRequired )		// ���ׂẴZ���̑I����Ԃ�����
	{
		m_pCWndDcdGrid->getCSelect()->clearSelect() ;
		bRv = true ;
	}

	// --------------------------------
	//	�O��l���X�V
	// --------------------------------
	m_ColumnNumberFocus_Old = aColumnNumberFocus ;

	return bRv ;	
}

bool CRandomSelect::update_adjustProp_updateCSelectCell() 
{
	//	�Z���I����Ԃ̍X�V�́A OnLButtonDown(),OnKeyDown() �ōs�����߁A
	//	�����ł͏����͂���܂���B
	return false ;
}

	// --------------------------------
	//@name CWndDcdGrid ����̈Ϗ�
	// --------------------------------
bool CRandomSelect::update_adjustProp() 
{
	bool	bRv = false ;
	if ( m_bIsEnable )
	{
		//	�t�H�[�J�X�Z���̈ړ��ɏ]���āA
		//	m_ColumnNumberAnchorCell , m_ColumnNumberSelect ���X�V���܂��B
		//	
		//	m_ColumnNumberAnchorCell�Em_ColumnNumberSelect �𐳋K�����܂��B
		bRv |= update_adjustProp_updateColumnNumberSelect() ;

		//	�I���Z���̏�Ԃ��ACSelectCell �ɔ��f����
		bRv |= update_adjustProp_updateCSelectCell() ;
	}
	else
	{
		m_ColumnNumberAnchorCell = ColumnNumberPosXy_NULL() ;
	}

	return bRv ;	
}

bool CRandomSelect::update_updateScreen() 
{
	bool bRv = false ;
	//	���̃N���X�ł͏����͂���܂���(�ĕ`��́ACSelect �ɂčs���܂�)
	return bRv ;
}
bool CRandomSelect::OnPaint( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;
	//	���̃N���X�ł͏����͂���܂���(�ĕ`��́ACSelect �ɂčs���܂�)
	return bRv ;
}

void CRandomSelect::OnSize(UINT nType, int cx, int cy)
{
	//	���̃N���X�ł͏����͂���܂���
}

void CRandomSelect::OnSetFocus(CWnd* pOldWnd)
{
	//	���̃N���X�ł́A�����͂���܂���B
}

void CRandomSelect::OnKillFocus(CWnd* pNewWnd)
{
	//	���̃N���X�ł́A�����͂���܂���B
}




void CRandomSelect::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//	CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

	//��Ctrl+�O���b�h��ł̃}�E�X�N���b�N@n
	//	�@���A���J�[�Z���̑I����Ԃ�I���ɂ���B
	//	�@�� �t�H�[�J�X�Z���̑I����Ԃ��g�O������
	if ( m_bIsEnable )	//	�����_���I�����L��
	{
		CdDcdPosXy	posCursorPos( point.x , point.y ) ;
		CDcdGridCell* pCell = 
			m_pCWndDcdGrid->getCellOfPos( posCursorPos ) ;
		if ( pCell != NULL )
		{
			//	�}�E�X���Z����ɂ����ԂŃN���b�N
			if ( m_pCWndDcdGrid->isCtrlPressed() )	//	Ctrl��������
			{
				//	Ctrl+�O���b�h��ł̃}�E�X�N���b�N

				//	�� �t�H�[�J�X�Z���̑I����Ԃ��g�O������
				{
					CSelectCell* pCSelectCell = getFocusSelectCell() ;
					if ( pCSelectCell != NULL )
					{
						pCSelectCell->setIsSelected( 
							!pCSelectCell->getIsSelected() ) ;
					}
				}

				//	���A���J�[�Z���̑I����Ԃ�I���ɂ���B
				//note:
				//	���̏����́A�u�t�H�[�J�X�Z���̑I����Ԃ��g�O������v�������
				//	�s���K�v������܂��B
				//	�������t�̏ꍇ�́A
				//		�����_���Z���I���̂Ȃ���ԂŁACtrl+Space������
				//		�����_���Z���I���̂Ȃ���ԂŁACtrl�������Ȃ���t�H�[�J�X�Z�����N���b�N
				//	�̂����ꂩ�����s�����Ƃ��ɁA�t�H�[�J�X�Z������I����ԂɂȂ�܂��B
				{
					CSelectCell* pCell = NULL ;
					if ( m_ColumnNumberAnchorCell != CFocus::ColumnNumberPosXy_NULL() )
					{
						pCell = m_pCWndDcdGrid->getCSelect()->getCell( 
							m_ColumnNumberAnchorCell.getX() ,
							m_ColumnNumberAnchorCell.getY() ) ;
						m_ColumnNumberAnchorCell = CFocus::ColumnNumberPosXy_NULL() ;
						pCell->setIsSelected( true ) ;
					}
				}

			}
		}
	}
	
}


void CRandomSelect::OnLButtonUp(UINT nFlags, CPoint point) 
{
	//	CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B
	//
	//	���̃N���X�ł́A�����͂���܂���B
}

void CRandomSelect::OnMouseMove(UINT nFlags, CPoint point) 
{
	//	CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B
	//
	//	���̃N���X�ł́A�����͂���܂���B
}

void CRandomSelect::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	//	CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B
	//
	//��Ctrl+Space�L�[@n
	//�@���t�H�[�J�X�Z���̑I����Ԃ��g�O������
	if ( m_bIsEnable )	//	�����_���I�����L��
	{
		if ( m_pCWndDcdGrid->isCtrlPressed() && 
			nChar == VK_SPACE )
		{
				//	Ctrl+Space�L�[
				
				//	�� �t�H�[�J�X�Z���̑I����Ԃ��g�O������
				{
					CSelectCell* pCSelectCell = getFocusSelectCell() ;
					if ( pCSelectCell != NULL )
					{
						pCSelectCell->setIsSelected( 
							!pCSelectCell->getIsSelected() ) ;
					}
				}
				//	���A���J�[�Z���̑I����Ԃ�I���ɂ���B
				//note:
				//	���̏����́A�u�t�H�[�J�X�Z���̑I����Ԃ��g�O������v�������
				//	�s���K�v������܂��B
				//	�������t�̏ꍇ�́A
				//		�����_���Z���I���̂Ȃ���ԂŁACtrl+Space������
				//		�����_���Z���I���̂Ȃ���ԂŁACtrl�������Ȃ���t�H�[�J�X�Z�����N���b�N
				//	�̂����ꂩ�����s�����Ƃ��ɁA�t�H�[�J�X�Z������I����ԂɂȂ�܂��B
				{
					CSelectCell* pCell = NULL ;
					if ( m_ColumnNumberAnchorCell != CFocus::ColumnNumberPosXy_NULL() )
					{
						pCell = m_pCWndDcdGrid->getCSelect()->getCell( 
							m_ColumnNumberAnchorCell.getX() ,
							m_ColumnNumberAnchorCell.getY() ) ;
						m_ColumnNumberAnchorCell = CFocus::ColumnNumberPosXy_NULL() ;
						pCell->setIsSelected( true ) ;
					}
				}

		}
	}
}

void CRandomSelect::InvalidateGrid( ) 
{
	//	���̃N���X�ł͏����͂���܂���(�ĕ`��́ACSelect �ɂčs���܂�)
}

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CRandomSelect::CRandomSelect( CWndDcdGrid* pCWndDcdGrid ) 
	: m_pCWndDcdGrid( pCWndDcdGrid )
	, m_bIsEnable( true ) 
	, m_ColumnNumberFocus_Old( ColumnNumberPosXy_NULL() ) 
{
}
CRandomSelect::~CRandomSelect() 
{
}

	// ********************************
	//@name CSelect �֘A
	// ********************************
CWndDcdGrid* CRandomSelect::getCWndDcdGrid() 
{
	return m_pCWndDcdGrid ;
}

	// ********************************
	//@name CSelect ����
	// ********************************
bool CRandomSelect::getIsEnable() 
{
	return m_bIsEnable ;
}
void CRandomSelect::setIsEnable( bool value ) 
{
	m_bIsEnable = value ;
}
CdDcdPosXy	CRandomSelect::getColumnNumberAnchorCell()
{
	return m_ColumnNumberAnchorCell;
}


} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib
