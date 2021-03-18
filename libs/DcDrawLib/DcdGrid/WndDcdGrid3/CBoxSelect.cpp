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
//	CBoxSelect.cpp
//	$Id: CBoxSelect.cpp 324 2016-06-12 03:03:55Z okm $
// ****************************************************************
*/
/** @file */
#include "DcdGrid\WndDcdGrid3\CBoxSelect.h"
#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CPropStack.h"
#include "DcdGrid\CDcdGridCell.h"
#include "logmsg\logmsg.h"
#include "NsOu\OuNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

	// --------------------------------
	///@name update_adjustProp �����֐�
	// --------------------------------
bool CBoxSelect::update_adjustProp_updateColumnNumberSelect() 
{
	bool bRv = false ;

	//	�ύX�Ώۂ̒l�̃L���b�V��
	CdDcdZoneXy	zonexyColumnNumberSelectNew = m_ColumnNumberSelect ;
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
	//��Shift�������ꂽ��ԂŁA�h���b�O�ȊO�ɂ��t�H�[�J�X�ړ�
	//	  ��BoxSelect �A���J�[�Z���͍X�V�����ɁA
	//		�A���J�[�Z���ƃt�H�[�J�X�Z���̊Ԃ�I��̈�Ƃ���B
	//���h���b�O�ɂ��t�H�[�J�X�ړ�(MouseMove,�^�C�}�X�N���[��)
	//	  ��BoxSelect�@�A���J�[�Z���͍X�V�����ɁA
	//		�A���J�[�Z���ƃt�H�[�J�X�Z���̊Ԃ�I��̈�Ƃ���B
	// --------------------------------
	if ( aColumnNumberFocus != CFocus::ColumnNumberPosXy_NULL() && 
		zonexyColumnNumberSelectLimit.IsInner( aColumnNumberFocus ) &&
		posxyColumnNumberAnchorCellNew != ColumnNumberPosXy_NULL() )
	{	//	�t�H�[�J�X�Z����NULL�ȊO�őI���\�̈�B
		//	�A���J�[�Z����NULL�ȊO�B
		bool bBoxSelecting = false ;
		if ( m_pCWndDcdGrid->isShiftPressed() && 
			!m_pCWndDcdGrid->isDragging() && 
			m_ColumnNumberFocus_Old != aColumnNumberFocus ) 
		{	//��Shift�������ꂽ��ԂŁA�h���b�O�ȊO�ɂ��t�H�[�J�X�ړ�
			//	  ��BoxSelect �A���J�[�Z���͍X�V�����ɁA
			//		�A���J�[�Z���ƃt�H�[�J�X�Z���̊Ԃ�I��̈�Ƃ���B
			bBoxSelecting = true ;
		}
		else if ( m_pCWndDcdGrid->isDragging() && 
			m_ColumnNumberFocus_Old != aColumnNumberFocus ) 
		{	//���h���b�O�ɂ��t�H�[�J�X�ړ�(MouseMove,�^�C�}�X�N���[��)
			//	  ��BoxSelect�@�A���J�[�Z���͍X�V�����ɁA
			//		�A���J�[�Z���ƃt�H�[�J�X�Z���̊Ԃ�I��̈�Ƃ���B
			bBoxSelecting = true ;
		}
		if ( bBoxSelecting )
		{

			//		�A���J�[�Z���ƃt�H�[�J�X�Z���̊Ԃ�I��̈�Ƃ���B
			//  �@��[FocusCell�� m_ColumnNumberSelectLimit�͈͓̔�]

			//X
			{
				int iPosMin = min( aColumnNumberFocus.getX() , posxyColumnNumberAnchorCellNew.getX() ) ;
				int iPosMax = max( aColumnNumberFocus.getX() , posxyColumnNumberAnchorCellNew.getX() ) ;
				zonexyColumnNumberSelectNew.setX( CdDcdZone( iPosMin , iPosMax - iPosMin + 1 ) ) ;
			}
			//Y
			{
				int iPosMin = min( aColumnNumberFocus.getY() , posxyColumnNumberAnchorCellNew.getY() ) ;
				int iPosMax = max( aColumnNumberFocus.getY() , posxyColumnNumberAnchorCellNew.getY() ) ;
				zonexyColumnNumberSelectNew.setY( CdDcdZone( iPosMin , iPosMax - iPosMin + 1 ) ) ;
			}
			//bRv�̍X�V�́A���̊֐��̖����ōs���܂��B
		}
	}
	
	// --------------------------------
	//��Ctrl��Shift��������Ȃ���ԂŁA�h���b�O(MouseMove,�^�C�}�X�N���[��)�ȊO�ɂ��t�H�[�J�X�ړ�
	//�@��BoxSelect �A���J�[�Z���͍X�V�BBoxSelect�̈��NULL�B
	//              ���ׂẴZ���̑I����Ԃ�����
	// --------------------------------
	if ( m_ColumnNumberFocus_Old != aColumnNumberFocus )
	{
		//	CRandomSelect::update_adjustProp_updateColumnNumberSelect()��
		//	CBoxSelect::update_adjustProp_updateColumnNumberSelect() ��
		//	���l�̏���������܂��B
		if ( !m_pCWndDcdGrid->isCtrlPressed() && 
			!m_pCWndDcdGrid->isShiftPressed() && 
			!m_pCWndDcdGrid->isDragging() && 
			m_ColumnNumberFocus_Old != aColumnNumberFocus ) 
		{
			//��Ctrl��Shift��������Ȃ���ԂŁA
			//�h���b�O(MouseMove,�^�C�}�X�N���[��)�ȊO�ɂ��t�H�[�J�X�ړ�

			//�A���J�[�Z���͍X�V�BBoxSelect�̈��NULL�B
			posxyColumnNumberAnchorCellNew = aColumnNumberFocus ;
			zonexyColumnNumberSelectNew =  ColumnNumberZoneXy_NULL();

			// ���ׂẴZ���̑I����Ԃ�����
			bClearSelectRequired = true ;

			//bRv�̍X�V�́A���̊֐��̖����ōs���܂��B
		}
	}
	// --------------------------------
	//��Ctrl��ON�AShift��OFF�ŁA�h���b�O�ȊO�ɂ��t�H�[�J�X�ړ�
	//�@��BoxSelect �A���J�[�Z���͍X�V�BBoxSelect�̈�͂��̂܂܁B
	// --------------------------------
	if ( aColumnNumberFocus != CFocus::ColumnNumberPosXy_NULL() && 
		zonexyColumnNumberSelectLimit.IsInner( aColumnNumberFocus ) )
	{	//	�t�H�[�J�X�Z����NULL�ȊO�őI���\�̈�B
		//	�A���J�[�Z����NULL�ȊO�B

		if ( m_pCWndDcdGrid->isCtrlPressed() && 
			!m_pCWndDcdGrid->isShiftPressed() && 
			!m_pCWndDcdGrid->isDragging() && 
			m_ColumnNumberFocus_Old != aColumnNumberFocus ) 
		{	//��Ctrl��Shift��������Ȃ���ԂŁA
			//�h���b�O(MouseMove,�^�C�}�X�N���[��)�ȊO�ɂ��t�H�[�J�X�ړ�

			//�A���J�[�Z���͍X�V�BBoxSelect�̈�͂��̂܂܁B
			posxyColumnNumberAnchorCellNew = aColumnNumberFocus ;
		}
	}

	// ----------------------------------------------------------------
	//	posxyColumnNumberAnchorCellNew�Em_ColumnNumberSelect �𐳋K�����܂��B
	// ----------------------------------------------------------------
	// --------------------------------
	//	�I���Z�����A�����ŕ␳
	// --------------------------------


	//	�I���Z���́A�I���\�����͈͓��ɂ���B
	//��[m_ColumnNumberSelect!=NULL]
	//�@��m_ColumnNumberSelect �́A m_ColumnNumberSelectLimit �͈͓̔��ɂ���B
	//�@��[SelectMode=SelectMode_XColumn]
	//     m_ColumnNumberSelect.Y = m_ColumnNumberSelectLimit.Y
	//�@��[SelectMode=SelectMode_YColumn]
	//     m_ColumnNumberSelect.X = m_ColumnNumberSelectLimit.X
	if ( zonexyColumnNumberSelectNew != ColumnNumberZoneXy_NULL() ) 
	{
		//�@��m_ColumnNumberSelect �́A m_ColumnNumberSelectLimit �͈͓̔��ɂ���B
		zonexyColumnNumberSelectNew = 
			zonexyColumnNumberSelectLimit.CrossZone( zonexyColumnNumberSelectNew ) ;


		//�@��[SelectMode=SelectMode_XColumn]
		//     m_ColumnNumberSelect.Y = m_ColumnNumberSelectLimit.Y
		if ( pCSelect->getSelectMode() == CSelect::SelectMode_XColumn )
		{
			zonexyColumnNumberSelectNew.setY( zonexyColumnNumberSelectLimit.getY() ) ;
		}
		//�@��[SelectMode=SelectMode_YColumn]
		//     m_ColumnNumberSelect.X = m_ColumnNumberSelectLimit.X
		if ( pCSelect->getSelectMode() == CSelect::SelectMode_YColumn )
		{
			zonexyColumnNumberSelectNew.setX( zonexyColumnNumberSelectLimit.getX() ) ;
		}

	}
	// ----------------------------------------------------------------
	//	�����̍X�V
	// ----------------------------------------------------------------
	if ( m_ColumnNumberSelect != zonexyColumnNumberSelectNew )
	{
		m_ColumnNumberSelect = zonexyColumnNumberSelectNew ;
		bRv = true ;
	}
	if ( m_ColumnNumberAnchorCell != posxyColumnNumberAnchorCellNew )
	{
		m_ColumnNumberAnchorCell = posxyColumnNumberAnchorCellNew ;
		bRv = true ;
	}
	if ( bClearSelectRequired ){	// ���ׂẴZ���̑I����Ԃ�����
		m_pCWndDcdGrid->getCSelect()->clearSelect() ;
		bRv = true ;
	}
	// --------------------------------
	//	�O��l�̍X�V
	// --------------------------------
	m_ColumnNumberFocus_Old = aColumnNumberFocus ;
	// --------------------------------
	
	LogMsg( "CBoxSelect::update_adjustProp_updateColumnNumberSelect\n"
		"\tm_ColumnNumberSelect.x=(%d,%d) y=(%d,%d)\n" ,
		m_ColumnNumberSelect.getX().getPos() , 
		m_ColumnNumberSelect.getX().getSize() , 
		m_ColumnNumberSelect.getY().getPos() , 
		m_ColumnNumberSelect.getY().getSize() ) ; 

	return bRv ;	
}

bool CBoxSelect::update_adjustProp_updateCSelectCell()
{
	bool bRv = false ;
	
	CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	CSelect* pCSelect = m_pCWndDcdGrid->getCSelect() ;

	{
		Ou<CPropStack> pPropStack = createPropStackForSelectChange() ;

		// --------------------------------
		//	�Z���̑I���󋵂̕ω���
		//	CSelectCell �ɔ��f���܂�
		// --------------------------------
		for ( int iYColumnNumber = 0 ; 
			iYColumnNumber < pCXDcdGrid->getYColumnCount() ; 
			iYColumnNumber ++ )
		{
			for ( int iXColumnNumber = 0 ; 
				iXColumnNumber < pCXDcdGrid->getXColumnCount() ; 
				iXColumnNumber ++ )
			{
				
				bool bSelected = m_ColumnNumberSelect.IsInner( 
					CdDcdPosXy( iXColumnNumber , iYColumnNumber ) ) ;
				bool bSelectedOld =  m_ColumnNumberSelect_Old.IsInner( 
					CdDcdPosXy( iXColumnNumber , iYColumnNumber ) ) ;

				if ( bSelectedOld != bSelected )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					pCSelectCell->setIsSelected( bSelected ) ;
					bRv = true ;
				}
			}
		}
	}
	return bRv ;
}

Ou<CPropStack> CBoxSelect::createPropStackForSelectChange() 
{
	OuNew<CPropStack> pPropStack( new CPropStack( getCWndDcdGrid() ) ) ;
	pPropStack->CSelect_setUpdateCWndDcdGrid( false ) ;
	return pPropStack ;

}



	// --------------------------------
	//@name CWndDcdGrid ����̈Ϗ�
	// --------------------------------
bool CBoxSelect::update_adjustProp() 
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
		//	�Z���I�����N���A����
		m_ColumnNumberAnchorCell = ColumnNumberPosXy_NULL() ;
		m_ColumnNumberSelect = ColumnNumberZoneXy_NULL() ;
	}

	return bRv ;	
}
bool CBoxSelect::update_updateScreen() 
{
	//	���̃N���X�ł͏����͂���܂���(�ĕ`��́ACSelect �ɂčs���܂�)
	m_ColumnNumberSelect_Old = m_ColumnNumberSelect ;
	return false ;
}


bool CBoxSelect::OnPaint( IfDcdTarget* pIfDcdTarget ) 
{
	//	���̃N���X�ł͏����͂���܂���(�ĕ`��́ACSelect �ɂčs���܂�)
	return false ;
}

void CBoxSelect::InvalidateGrid( ) 
{
	//	���̃N���X�ł͏����͂���܂���(�ĕ`��́ACSelect �ɂčs���܂�)
}
void CBoxSelect::OnSize(UINT nType, int cx, int cy)
{
	//	���̃N���X�ł́A�����͂���܂���B
}
void CBoxSelect::OnSetFocus(CWnd* pOldWnd)
{
	//	���̃N���X�ł́A�����͂���܂���B
}

void CBoxSelect::OnKillFocus(CWnd* pNewWnd)
{
	//	���̃N���X�ł́A�����͂���܂���B
}

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CBoxSelect::CBoxSelect( CWndDcdGrid* pCWndDcdGrid ) 
	: m_pCWndDcdGrid( pCWndDcdGrid ) 
	, m_bIsEnable( true ) 
	, m_ColumnNumberAnchorCell( ColumnNumberPosXy_NULL()  ) 
	, m_ColumnNumberSelect( ColumnNumberZoneXy_NULL() )
	, m_ColumnNumberFocus_Old( ColumnNumberPosXy_NULL() ) 
	, m_ColumnNumberSelect_Old( ColumnNumberZoneXy_NULL() )
{
}


CBoxSelect::~CBoxSelect() 
{
}
	// ********************************
	//@name CSelect �֘A
	// ********************************
CWndDcdGrid* CBoxSelect::getCWndDcdGrid() 
{
	return m_pCWndDcdGrid ;
}

	// ********************************
	//@name CSelect ����
	// ********************************
bool CBoxSelect::getIsEnable()
{
	return m_bIsEnable ;
}
void CBoxSelect::setIsEnable( bool value ) 
{
	m_bIsEnable = value ;
}
CdDcdPosXy	CBoxSelect::getColumnNumberAnchorCell()
{
	return m_ColumnNumberAnchorCell ;
}
CdDcdZoneXy	CBoxSelect::getColumnNumberSelect()const 
{
	return m_ColumnNumberSelect ;
}
void CBoxSelect::setColumnNumberSelect( const CdDcdZoneXy& value ) 
{
	m_ColumnNumberSelect = value ;
	m_pCWndDcdGrid->update() ;
}

	// ********************************
	//@name CSelect �W��
	// ********************************
	// ********************************
	//@name CSelect ����
	// ********************************
void CBoxSelect::clearSelect() 
{
	m_ColumnNumberSelect = ColumnNumberZoneXy_NULL() ;
	m_pCWndDcdGrid->update() ;
}


} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib


