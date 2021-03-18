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
//	CSelect.cpp
//$Id: CSelect.cpp 324 2016-06-12 03:03:55Z okm $
// ****************************************************************
*/
/** @file */
#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CPropStack.h"
#include "DcdGrid\WndDcdGrid3\CXDcdGrid_ZoneCacheTemp.h"

#include "NsOu\OuNew.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CDcdFillrectRop.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "LogMsg\LogMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

// ----------------------------------------------------------------
//	WndDcdGrid3::CSelect
// ----------------------------------------------------------------
	// --------------------------------
	//@name �����֐�
	// --------------------------------

int CSelect::insertYColumn_insertColumnCell( int iYColumnNumber ) 
{
	int iRv = 0 ;

	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iRv >= 0 ){
		if ( iYColumnNumber == INT_MAX ){
			iYColumnNumber = pCDcdGrid->getYColumnCount() ;
		}
		if ( !( 0 <= iYColumnNumber && iYColumnNumber <= pCDcdGrid->getYColumnCount() ) ){
			iRv = -2 ;	//	�C���f�N�X���s���ł�	
		}
	}
	if ( iRv >= 0 ){
		//	Cell�I�u�W�F�N�g
		m_CSelectCellCont.insert( 
			m_CSelectCellCont.begin() + iYColumnNumber ,
			new CSelectYColumnCellCont ) ;
		int iXColumnNumber ;
		for ( iXColumnNumber = 0 ; 
				iXColumnNumber < pCDcdGrid->getXColumnCount() ; 
				iXColumnNumber ++ ){
			CSelectCell*	pCSelectCell = new CSelectCell( this , m_CSelectCellCont[ iYColumnNumber ] ) ;
			
			m_CSelectCellCont[ iYColumnNumber ]->push_back( pCSelectCell );
		}
		
	}
	return ( iRv ) ;
}

int CSelect::insertXColumn_insertColumnCell( int iXColumnNumber ) 
{
	int	iRv = 0 ;
	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iRv >= 0 ){
		if ( iXColumnNumber == INT_MAX ){
			iXColumnNumber = pCDcdGrid->getXColumnCount() ;
		}
		if ( !( 0 <= iXColumnNumber && 
				iXColumnNumber <= pCDcdGrid->getXColumnCount() ) ){
			iRv = -2 ;	//	�C���f�N�X���s���ł�	
		}
	}
	if ( iRv >= 0 ){
		int iYColumnNumber ;
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < pCDcdGrid->getYColumnCount() ; 
				iYColumnNumber ++ ){
			CSelectCell*	pCSelectCell = new CSelectCell( this , m_CSelectCellCont[iYColumnNumber] ) ;
			m_CSelectCellCont[iYColumnNumber]->insert( 
				m_CSelectCellCont[iYColumnNumber]->begin() + iXColumnNumber ,
				pCSelectCell ) ;
			
		}
	}
	return ( iRv ) ;
}
	
int CSelect::eraseYColumn_eraseColumnCell( int iYColumnNumber ) 
{
	int iRv = 0 ;
	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iRv >= 0 ){
		if ( iYColumnNumber == INT_MAX ){
			iYColumnNumber = pCDcdGrid->getYColumnCount() - 1 ;
		}
		if ( !( 0 <= iYColumnNumber && 
				iYColumnNumber < pCDcdGrid->getYColumnCount() ) ){
			iRv = -2 ;	//	�C���f�N�X���s���ł�	
		}
	}
	if ( iRv >= 0 ){
		int iXColumnNumber ;
		for ( iXColumnNumber = pCDcdGrid->getXColumnCount() - 1  ; 
				iXColumnNumber >= 0  ; 
				iXColumnNumber -- ){
			CSelectCell*	pCSelectCell = 
				m_CSelectCellCont[ iYColumnNumber ]->back();
			
			m_CSelectCellCont[ iYColumnNumber ]->pop_back();
			
			delete pCSelectCell ;
			pCSelectCell = NULL ;
		}
		CSelectYColumnCellCont* pCSelectYColumnCellCont = m_CSelectCellCont[iYColumnNumber] ;
		delete pCSelectYColumnCellCont ;
		pCSelectYColumnCellCont = NULL ;

		m_CSelectCellCont.erase( 
			m_CSelectCellCont.begin() + iYColumnNumber ) ;
	}
	return ( iRv ) ;
}

int CSelect::eraseXColumn_eraseColumnCell( int iXColumnNumber ) 
{
	int iRv = 0 ;
	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iRv >= 0 ){
		if ( iXColumnNumber == INT_MAX ){
			iXColumnNumber = pCDcdGrid->getXColumnCount() - 1 ;
		}
		if ( !( 0 <= iXColumnNumber && 
				iXColumnNumber < pCDcdGrid->getXColumnCount() ) ){
			iRv = -2 ;	//	�C���f�N�X���s���ł�	
		}
	}
	if ( iRv >= 0 ){
		int iYColumnNumber ;
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < pCDcdGrid->getYColumnCount() ; 
				iYColumnNumber ++ ){
			CSelectCell*	pCSelectCell = 
				(*m_CSelectCellCont[iYColumnNumber])[iXColumnNumber] ;

			m_CSelectCellCont[iYColumnNumber]->erase( 
				m_CSelectCellCont[iYColumnNumber]->begin() + iXColumnNumber ) ;
			
			delete pCSelectCell ;
			pCSelectCell = NULL ;
		}
	}
	return ( iRv ) ;
}

Ou<CPropStack> CSelect::createPropStackForSelectChange() 
{
	OuNew<CPropStack> pPropStack( new CPropStack( getCWndDcdGrid() ) ) ;
	pPropStack->CSelect_setUpdateCWndDcdGrid( false ) ;
	return pPropStack ;

}

	// --------------------------------
	//@name CWndDcdGrid::CDcdGrid ����̈Ϗ�
	// --------------------------------
void CSelect::OnCreateXColumn( int iXColumnNumber )
{
	insertXColumn_insertColumnCell( iXColumnNumber ) ;
}	
		
void CSelect::OnDeleteXColumn( int iXColumnNumber ) 
{
	eraseXColumn_eraseColumnCell( iXColumnNumber ) ;
}

void CSelect::OnCreateYColumn( int iYColumnNumber ) 
{
	insertYColumn_insertColumnCell( iYColumnNumber ) ;
}
void CSelect::OnDeleteYColumn( int iYColumnNumber ) 
{
	eraseYColumn_eraseColumnCell( iYColumnNumber ) ;
}

	// --------------------------------
	//@name CWndDcdGrid ����̈Ϗ�
	// --------------------------------
bool CSelect::update_adjustProp() 
{
	bool bRv = false ;

	LogMsg( "CSelect::update_adjustProp() " ) ;

	if ( m_eSelectMode_Prev == SelectMode_NONE
		&& m_eSelectMode == SelectMode_NONE )
	{
		//	m_eSelectMode �� SelectMode_NONE �ł���Ԃ́A
		//	update_adjustProp()�Eupdate_updateScreen()�EOnPaint()��
		//	���������Ƀ��^�[�����܂��B
	}	
	else
	{
		CSelect* pCSelect = m_pCWndDcdGrid->getCSelect() ;
		CdDcdZoneXy	zonexyColumnNumberLimit = 
			pCSelect->getColumnNumberSelectLimitRegularized() ;
		//zonexyColumnNumberLimit = �Z���I���\�͈�

		//	�Z���I��ύX���̕`����œK�����܂��B
		Ou<CPropStack> pPropStack = createPropStackForSelectChange() ;

		// --------------------------------
		//	X�񃂁[�h�EY�񃂁[�h�ɂ��ACSelectCell::m_bIsSelected �̐��K���B
		// --------------------------------
		//1.1.m_eSelectMode �� SelectMode_NONE �̏ꍇ�A
		//���ׂẴZ�����I���ɂ��܂��B
		if ( m_pCWndDcdGrid->getCSelect()->getSelectMode() 
			== CSelect::SelectMode_NONE )
		{
			//	���ׂẴZ���̑I�����������܂��B
			clearSelect() ;
		}
		//	  1.2. m_eSelectMode �� SelectMode_XColumn �̏ꍇ�A
		//		����X��ԍ�(�c����)�̃Z���̑I���󋵂����ׂē���ɂ��܂��B
		//
		else if ( m_pCWndDcdGrid->getCSelect()->getSelectMode() 
			== CSelect::SelectMode_XColumn )
		{

			for ( int iXColumnNumber = zonexyColumnNumberLimit.getX().getPos() ;
				iXColumnNumber < zonexyColumnNumberLimit.getX().getEndPos() ;
				iXColumnNumber ++ )
			{
				//	�Z���I���󋵂��m�肵���� true �ł��B
				bool bColumnSelectIsFixed = false ;
				bool bColumnSelect = false ;

				//		1.2.1.�����ꂩ�̃Z���� CSelectCell::m_bIsSelected ��true��
				//		�ύX����Ă�����A
				//		���ׂẴZ����true�ɂ��܂��B
				//
				//		1.2.2.�����ꂩ�̃Z���� CSelectCell::m_bIsSelected ��
				//		false�ɕύX����Ă�����A
				//		���ׂẴZ����false�ɂ��܂��B
				for ( int iYColumnNumber = zonexyColumnNumberLimit.getY().getPos() ;
					!bColumnSelectIsFixed && 
						iYColumnNumber < zonexyColumnNumberLimit.getY().getEndPos() ;
					iYColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					if ( pCSelectCell->getIsSelected_Prev() != 
						pCSelectCell->getIsSelected() )
					{
						//	�Z���̑I���󋵂��ύX����Ă��܂��B
						//	���̗�̂��ׂẴZ���̑I���󋵂��m�肵�܂��B
						bColumnSelectIsFixed = true ;
						bColumnSelect = pCSelectCell->getIsSelected() ;
					}
				}
				//		1.2.3.�Z���̑I���󋵂��ύX����Ă��Ȃ��ꍇ�́A
				//		�S�ẴZ���̑I���󋵂��Am_ColumnNumberSelectLimit.getY().getPos() ��
				//		�I���󋵂Ɠ����ɂ��܂��B
				//		
				if ( !bColumnSelectIsFixed )	//	�Z���̑I���󋵂��ύX����Ă��Ȃ�
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , zonexyColumnNumberLimit.getY().getPos() ) ;
					if ( pCSelectCell != NULL )	//	Y�񐔂�0�̏ꍇ�́ApCSelectCell��NULL�ɂȂ�܂��B
					{
						bColumnSelectIsFixed = true ;
						bColumnSelect = pCSelectCell->getIsSelected() ;
					}
				}

				for ( int iYColumnNumber = zonexyColumnNumberLimit.getY().getPos() ;
						iYColumnNumber < zonexyColumnNumberLimit.getY().getEndPos() ;
					iYColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					if ( pCSelectCell->getIsSelected() != bColumnSelect )
					{
						pCSelectCell->setIsSelected( bColumnSelect ) ;
						bRv = true ;
					}
				}
			}
		}
		//	1.3.m_eSelectMode �� SelectMode_YColumn �̏ꍇ�A
		//	����Y��ԍ�(������)�̃Z���̑I���󋵂����ׂē���ɂ��܂��B
		else if ( m_pCWndDcdGrid->getCSelect()->getSelectMode() 
			== CSelect::SelectMode_YColumn )
		{
			for ( int iYColumnNumber = zonexyColumnNumberLimit.getY().getPos() ;
				iYColumnNumber < zonexyColumnNumberLimit.getY().getEndPos() ;
				iYColumnNumber ++ )
			{
				//	�Z���I���󋵂��m�肵���� true �ł��B
				bool bColumnSelectIsFixed = false ;
				bool bColumnSelect = false ;

				//		1.1.�����ꂩ�̃Z���� CSelectCell::m_bIsSelected ��true��
				//		�ύX����Ă�����A
				//		���ׂẴZ����true�ɂ��܂��B
				//
				//		1.2.�����ꂩ�̃Z���� CSelectCell::m_bIsSelected ��false�ɕύX����Ă�����A
				//		���ׂẴZ����false�ɂ��܂��B
				for ( int iXColumnNumber = zonexyColumnNumberLimit.getX().getPos() ;
					!bColumnSelectIsFixed && 
						iXColumnNumber < zonexyColumnNumberLimit.getX().getEndPos() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					if ( pCSelectCell->getIsSelected_Prev() != 
						pCSelectCell->getIsSelected() )
					{
						//	�Z���̑I���󋵂��ύX����Ă��܂��B
						//	���̗�̂��ׂẴZ���̑I���󋵂��m�肵�܂��B
						bColumnSelectIsFixed = true ;
						bColumnSelect = pCSelectCell->getIsSelected() ;
					}
				}
				//		1.3.�Z���̑I���󋵂��ύX����Ă��Ȃ��ꍇ�́A
				//		�S�ẴZ���̑I���󋵂��Am_ColumnNumberSelectLimit.getY().getPos() ��
				//		�I���󋵂Ɠ����ɂ��܂��B
				//		
				if ( !bColumnSelectIsFixed )	//	�Z���̑I���󋵂��ύX����Ă��Ȃ�
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						zonexyColumnNumberLimit.getX().getPos() , iYColumnNumber ) ;
					if ( pCSelectCell != NULL )	//	X�񐔂�0�̏ꍇ�́ApCSelectCell��NULL�ɂȂ�܂��B
					{
						bColumnSelectIsFixed = true ;
						bColumnSelect = pCSelectCell->getIsSelected() ;
					}
				}

				for ( int iXColumnNumber = zonexyColumnNumberLimit.getX().getPos() ;
						iXColumnNumber < zonexyColumnNumberLimit.getX().getEndPos() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelect->getCell( 
						iXColumnNumber , iYColumnNumber ) ;
					if ( pCSelectCell->getIsSelected() != bColumnSelect )
					{
						pCSelectCell->setIsSelected( bColumnSelect ) ;
						bRv = true ;
					}
				}
			}
		}
			
		// --------------------------------
		//	ColumnNumberSelectLimit�ɂ��ACSelectCell::m_bIsSelected �̐��K���B
		// --------------------------------
		//	  2. m_ColumnNumberSelectLimit �ȊO�̗̈悪�I������Ă����ꍇ��
		//	    ���̑I�����������܂��B
		{
			CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

			for ( int iYColumnNumber = 0 ;
				iYColumnNumber < pCXDcdGrid->getYColumnCount() ;
				iYColumnNumber ++ )
			{
				for ( int iXColumnNumber = 0 ;
						iXColumnNumber < pCXDcdGrid->getXColumnCount() ;
					iXColumnNumber ++ )
				{
					if ( !zonexyColumnNumberLimit.IsInner( 
						CdDcdPosXy( iXColumnNumber , iYColumnNumber ) ) )
					{
						//	m_ColumnNumberSelectLimit �ȊO�̗̈�ł��B
						//	���̃Z���́A���ׂđI�������ɂ��܂��B
						CSelectCell* pCSelectCell = pCSelect->getCell( 
							iXColumnNumber , iYColumnNumber ) ;
						if ( pCSelectCell->getIsSelected() )
						{
							pCSelectCell->setIsSelected( false ) ;
							bRv = true ;
						}
					}
				}
			}
		}
		// --------------------------------
		//	m_iSelectedCellCount �̍X�V
		// --------------------------------
		{
			m_iSelectedCellCount = 0 ;
			for ( int iYColumnNumber = 0 ; 
				iYColumnNumber < (int)m_CSelectCellCont.size() ; 
				iYColumnNumber ++ )
			{
				CSelectYColumnCellCont* pCSelectYColumnCellCont = 
					m_CSelectCellCont[iYColumnNumber] ;
				for ( int iXColumnNumber = 0 ; 
					iXColumnNumber < (int)pCSelectYColumnCellCont->size() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelectYColumnCellCont->at( iXColumnNumber ) ;
					if ( pCSelectCell->getIsSelected() )
					{
						m_iSelectedCellCount ++ ;
					}
				}
			}

		}
		// --------------------------------
		//	CSelectCell �ɈϏ�
		// --------------------------------
		{
			for ( int iYColumnNumber = 0 ; 
				iYColumnNumber < (int)m_CSelectCellCont.size() ; 
				iYColumnNumber ++ )
			{
				CSelectYColumnCellCont* pCSelectYColumnCellCont = 
					m_CSelectCellCont[iYColumnNumber] ;
				for ( int iXColumnNumber = 0 ; 
					iXColumnNumber < (int)pCSelectYColumnCellCont->size() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelectYColumnCellCont->at( iXColumnNumber ) ;
					bRv |= pCSelectCell->update_adjustProp() ;
				}
			}
		}

	}

	LogMsg( "CSelect::update_adjustProp()=%d ",bRv  ) ;

	return bRv ;
}

bool CSelect::update_updateScreen() 
{
	bool bRv = false ;


	if ( m_eSelectMode_Prev == SelectMode_NONE
		&& m_eSelectMode == SelectMode_NONE )
	{
		//	m_eSelectMode �� SelectMode_NONE �ł���Ԃ́A
		//	update_adjustProp()�Eupdate_updateScreen()�EOnPaint()��
		//	���������Ƀ��^�[�����܂��B
	}	
	else
	{
		//	ZoneCache �𐶐�
		//	(CSelect::getZoneOfCellSelection()�ɂ��
		//	�T�C�Y�擾�������Ȃ�܂�)

		CDcdTargetGetDC	aTarget( getCWndDcdGrid()->GetSafeHwnd() ) ;
		CXDcdGrid_ZoneCacheTemp aZoneCacheTemp( 
				getCWndDcdGrid()->getCXDcdGrid() , 
				&aTarget ) ;

		// --------------------------------
		//	CSelectCell �ɈϏ�
		// --------------------------------
		{
			CDcdTargetGetDC	aTarget( m_pCWndDcdGrid->GetSafeHwnd() ) ;

			for ( int iYColumnNumber = 0 ; 
				iYColumnNumber < (int)m_CSelectCellCont.size() ; 
				iYColumnNumber ++ )
			{
				CSelectYColumnCellCont* pCSelectYColumnCellCont = 
					m_CSelectCellCont[iYColumnNumber] ;
				for ( int iXColumnNumber = 0 ; 
					iXColumnNumber < (int)pCSelectYColumnCellCont->size() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelectYColumnCellCont->at( iXColumnNumber ) ;
					bRv |= pCSelectCell->update_updateScreen( &aTarget ) ;
				}
			}
		}
	}
	// --------------------------------
	//	�O��l���X�V
	// --------------------------------
	m_eSelectMode_Prev = m_eSelectMode ;

	// --------------------------------
	return bRv ;
}

bool CSelect::OnPaint( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;
	LogMsg( "CSelect::OnPaint()" ) ; 

	if ( m_eSelectMode == SelectMode_NONE )
	{
		//	m_eSelectMode �� SelectMode_NONE �ł���Ԃ́A
		//	update_adjustProp()�Eupdate_updateScreen()�EOnPaint()��
		//	���������Ƀ��^�[�����܂��B
	}	
	else
	{
		//	ZoneCache �𐶐�
		//	(CSelect::getZoneOfCellSelection()�ɂ��
		//	�T�C�Y�擾�������Ȃ�܂�)
		CXDcdGrid_ZoneCacheTemp	aZoneCacheTemp( 
			m_pCWndDcdGrid->getCXDcdGrid() , 
			pIfDcdTarget ) ;

		// --------------------------------
		//	CSelectCell ���I����ԂȂ�`��
		// --------------------------------
		{
			CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
			
			for ( int iYColumnNumber = 0 ; 
				iYColumnNumber < (int)m_CSelectCellCont.size() ; 
				iYColumnNumber ++ )
			{
				CSelectYColumnCellCont* pCSelectYColumnCellCont = 
					m_CSelectCellCont[iYColumnNumber] ;
				for ( int iXColumnNumber = 0 ; 
					iXColumnNumber < (int)pCSelectYColumnCellCont->size() ;
					iXColumnNumber ++ )
				{
					CSelectCell* pCSelectCell = pCSelectYColumnCellCont->at( iXColumnNumber ) ;
					if ( pCSelectCell->getIsSelected() )
					{
						CdDcdZoneXy	zoneCell = getZoneOfCellSelection(
							pIfDcdTarget , 
							iXColumnNumber , iYColumnNumber , m_bIncludeRbBorder ) ;

						if ( !( zoneCell.getX().getSize() > 0 && 
								zoneCell.getY().getSize() > 0 ) ){
							//	�Z���̃T�C�Y���O�̏ꍇ�́A
							//	�㑱�̏����͍s���܂���
							continue ;
						}

						CaDcdTargetItemPosition	aCDcdTargetItemPosition( 
							pIfDcdTarget ,
							zoneCell ) ;
						
						if ( aCDcdTargetItemPosition.isDrawable() )
						{
							m_pIfDcDrawSelect->DcDraw( &aCDcdTargetItemPosition ) ;
							
							bRv = true ;
						}

					}
				}
			}
		}
	}
	LogMsg( "CSelect::OnPaint()=" ) ; 

	return bRv ;
}


void CSelect::OnSize(UINT nType, int cx, int cy)
{
	if ( cx == 0 || cy == 0 ){
		//	���̂Q�̂����̂����ꂩ��0�̏ꍇ�A�����
		//	Create() �ŃT�C�Y���w�肹���ɃE�C���h�E��
		//	�����������̂Ǝv���܂��B
		//	���̏ꍇ�́A���[�U�[�ɂ͉��������Ȃ��킯�ł�����A
		//	�t�H�[�J�X�Z���̈ʒu�̍œK���Ȃǂ͂����Ȃ�
		//	�K�v������܂���B
		//
		//	�܂��A���̑傫���̂Ƃ��� adjustProp() ��
		//	�s���ƁA�t�H�[�J�X�ʒu�͖������� (0,0) ��
		//	�ړ����Ă��܂��܂��B���̂��߁A
		//	adjustProp() �͂��Ȃ�����
		//	�悢�ł��傤�B
		return ;
	}

}

void CSelect::OnSetFocus(CWnd* pOldWnd)
{
}

void CSelect::OnKillFocus(CWnd* pNewWnd)
{
}

void CSelect::InvalidateGrid( ) 
{
	//	���̃N���X�̉�ʕ`��͂��ׂ�OnPaint�ōs���܂��B
	//	InvalidateGrid�ł́A���ʂȏ����͕s�v�ł��B

}


	// ********************************
	//	�R���X�g���N�^
	// ********************************
CSelect::CSelect( CWndDcdGrid* pCWndDcdGrid ) 
	: m_pCWndDcdGrid( pCWndDcdGrid )
	, m_bIncludeRbBorder( true ) 
	, m_eSelectMode( SelectMode_NONE ) 
	, m_ColumnNumberSelectLimit( CdDcdZone( 0 , INT_MAX ) , CdDcdZone( 0 , INT_MAX ) )
	, m_bUpdateCWndDcdGrid( true ) 
	, m_eSelectMode_Prev( SelectMode_NONE ) 
	, m_iSelectedCellCount( 0 ) 
{
	m_pIfDcDrawSelect = OuNew<CDcdFillrectRop>( new CDcdFillrectRop( 
		CdBrushProp( CdColorProp( 0 , 0 , 0 ) , CdBrushProp::SOLID ) ,
		R2_NOTXORPEN 
		) ) ;
	
}

CSelect::~CSelect() 
{
	//	CSelectCell �I�u�W�F�N�g��j�����܂��B
	while( m_CSelectCellCont.size() > 0 )
	{
		CSelectYColumnCellCont* pCSelectYColumnCellCont = m_CSelectCellCont.back() ;
		while( pCSelectYColumnCellCont->size() > 0 )
		{
			CSelectCell* pCSelectCell = pCSelectYColumnCellCont->back() ;
			delete pCSelectCell ;	pCSelectCell = NULL ;
			pCSelectYColumnCellCont->pop_back() ;
		}
		delete pCSelectYColumnCellCont ; pCSelectYColumnCellCont = NULL ;
		m_CSelectCellCont.pop_back() ;
	}
}

// ********************************
//@name �֘A
// ********************************
CWndDcdGrid*	CSelect::getCWndDcdGrid()
{
	return m_pCWndDcdGrid ;
}
Ou<IfDcDraw>	CSelect::getIfDcDrawSelect() 
{
	return m_pIfDcDrawSelect ;
}
void CSelect::setIfDcDrawSelect( Ou<IfDcDraw> value ) 
{
	m_pIfDcDrawSelect = value ;
}



	// ********************************
	//@name ����
	// ********************************	
bool CSelect::getIncludeRbBorder()const 
{
	return m_bIncludeRbBorder ;
}
void CSelect::setIncludeRbBorder( bool ev )  
{
	m_bIncludeRbBorder = ev ;
}
CSelect::ESelectMode	CSelect::getSelectMode()const 
{
	return m_eSelectMode ;
}
void CSelect::setSelectMode( ESelectMode	value ) 
{
	m_eSelectMode = value ;
	m_pCWndDcdGrid->update() ;
}

CdDcdZoneXy	CSelect::getColumnNumberSelectLimit()const 
{
	return m_ColumnNumberSelectLimit ;
}
void CSelect::setColumnNumberSelectLimit( const CdDcdZoneXy& value ) 
{
	m_ColumnNumberSelectLimit = value ;
	m_pCWndDcdGrid->update() ;
}

CdDcdZoneXy	CSelect::getColumnNumberSelectLimitRegularized()const 
{
	CdDcdZoneXy	zonexyRv = m_ColumnNumberSelectLimit ;
	CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	//	X��
	{
		CdDcdZone	aZone = zonexyRv.getX() ;
		if ( aZone.getEndPos() > pCXDcdGrid->getXColumnCount() )
		{
			aZone.setEndPos( pCXDcdGrid->getXColumnCount() ) ;
			zonexyRv.setX( aZone ) ;
		}
	}
	//	Y��
	{
		CdDcdZone	aZone = zonexyRv.getY() ;
		if ( aZone.getEndPos() > pCXDcdGrid->getYColumnCount() )
		{
			aZone.setEndPos( pCXDcdGrid->getYColumnCount() ) ;
			zonexyRv.setY( aZone ) ;
		}
	}
	return zonexyRv ;
}

bool CSelect::getUpdateCWndDcdGrid()const 
{
	return m_bUpdateCWndDcdGrid ;
}

void CSelect::setUpdateCWndDcdGrid( bool ev ) 
{
	if ( m_bUpdateCWndDcdGrid != ev )
	{
		//�@������ false ���� true �ɕύX�����ꍇ�́ACWndDcdGrid �S�̂��X�V���܂��B
		if ( ev )
		{
			m_pCWndDcdGrid->update() ;
		}
		m_bUpdateCWndDcdGrid = ev ;
	}
}



	// ********************************
	//@name CWndDcdGrid::CSelect �W��
	// ********************************
CSelectCell* 
CSelect::getCell( int iXColumnNumber , int iYColumnNumber )
{
	CDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if ( iXColumnNumber == INT_MAX ){
		iXColumnNumber = pCDcdGrid->getXColumnCount() - 1 ;
	}
	if ( iYColumnNumber == INT_MAX ){
		iYColumnNumber = pCDcdGrid->getYColumnCount() - 1 ;
	}
	if ( 0 <= iXColumnNumber && iXColumnNumber < pCDcdGrid->getXColumnCount() && 
		0 <= iYColumnNumber && iYColumnNumber < pCDcdGrid->getYColumnCount() ){
		return ( (*m_CSelectCellCont[iYColumnNumber])[iXColumnNumber] ) ;
	}
	return ( NULL ) ;
}


int CSelect::getXColumnNumberOfCell( 
		CSelectCell* pCSelectCell ) 
{
	int iXColumnNumber = INT_MIN ;
	// --------------------------------
	if ( pCSelectCell != NULL )
	{
		for ( int idx = 0 ; 
				iXColumnNumber == INT_MIN && idx < (int)pCSelectCell->m_pCont->size() ; 
				idx ++ )
		{
			if ( pCSelectCell->m_pCont->at(idx) == pCSelectCell )
			{
				iXColumnNumber = idx ;
			}
		}
		
	}
	return iXColumnNumber ;
}
int CSelect::getYColumnNumberOfCell( 
	CSelectCell* pCSelectCell ) 
{
	int iYColumnNumber = INT_MIN ;
	// --------------------------------
	if ( pCSelectCell != NULL )
	{
		for ( int idx = 0 ; 
				iYColumnNumber == INT_MIN && idx < (int)m_CSelectCellCont.size() ; 
				idx ++ )
		{
			if ( m_CSelectCellCont[idx] == pCSelectCell->m_pCont )
			{
				iYColumnNumber = idx ;
			}
		}
		
	}
	// --------------------------------
	return iYColumnNumber ;
}

	// ********************************
	//@name CSelect ����
	// ********************************

CdDcdZoneXy CSelect::getZoneOfCellSelection(
	IfDcdTarget* pIfDcdTarget , 
	int iXColumnNumber , int iYColumnNumber , bool bIncludeRbBorder ) 
{
	CdDcdZoneXy	aZoneXy ;
	CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	CDcdGridCell* pCell = pCXDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;

	if ( pCell->getAttachTo() == NULL )	//	�����Z���ł͂Ȃ�
	{
		aZoneXy = pCXDcdGrid->getCellZone( pIfDcdTarget , iXColumnNumber , iYColumnNumber ) ;
		
		//X������(����)�r��
		{

			if ( bIncludeRbBorder && 
				iXColumnNumber + pCell->getXAttachCellCount() < pCXDcdGrid->getXColumnCount() )
			{
				//	�͈͂Ɍr�����܂߂�(�O���b�h�S�̂̌r���͏���)
				CdDcdZone	zoneCurrent = aZoneXy.getX() ;

				CdDcdZone	zoneBorder = pCXDcdGrid->getXColumnBorderZone( 
					pIfDcdTarget , 
					iXColumnNumber + pCell->getXAttachCellCount() - 1 ) ;

				zoneCurrent.setEndPos( zoneBorder.getEndPos() ) ;
				aZoneXy.setX( zoneCurrent ) ;
			}
		}
		//Y������(����)�r��
		{
			if ( bIncludeRbBorder && 
				iYColumnNumber + pCell->getYAttachCellCount() < pCXDcdGrid->getYColumnCount() )
			{
				//	�͈͂Ɍr�����܂߂�(�O���b�h�S�̂̌r���͏���)
				CdDcdZone	zoneCurrent = aZoneXy.getY() ;

				CdDcdZone	zoneBorder = pCXDcdGrid->getYColumnBorderZone( 
					pIfDcdTarget , 
					iYColumnNumber + pCell->getYAttachCellCount() - 1 ) ;

				zoneCurrent.setEndPos( zoneBorder.getEndPos() ) ;
				aZoneXy.setY( zoneCurrent ) ;
			}
		}
	}
	return aZoneXy ;

}

void CSelect::selectAll() 
{
	{
		//	�Z���I��ύX���̕`����œK�����܂��B
		Ou<CPropStack> pPropStack = createPropStackForSelectChange() ;


		CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
		CSelect* pCSelect = m_pCWndDcdGrid->getCSelect() ;
		CdDcdZoneXy	zonexyColumnNumberSelectLimit = pCSelect->getColumnNumberSelectLimitRegularized() ;

		for ( int iYColumnNumber = zonexyColumnNumberSelectLimit.getY().getPos() ;
			iYColumnNumber < zonexyColumnNumberSelectLimit.getY().getEndPos()  ;
			iYColumnNumber ++ )
		{
			for ( int iXColumnNumber = zonexyColumnNumberSelectLimit.getX().getPos() ;
				iXColumnNumber < zonexyColumnNumberSelectLimit.getX().getEndPos() ;
				iXColumnNumber ++ )
			{
				//	m_ColumnNumberSelectLimit �ȓ��̗̈�ł��B
				//	���̃Z���́A���ׂđI�����܂��B
				CSelectCell* pCSelectCell = pCSelect->getCell( 
					iXColumnNumber , iYColumnNumber ) ;
				pCSelectCell->setIsSelected( true ) ;
			}
		}
	}
}

void  CSelect::clearSelect() 
{
	{
		//	�Z���I��ύX���̕`����œK�����܂��B
		Ou<CPropStack> pPropStack = createPropStackForSelectChange() ;



		CXDcdGrid* pCXDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
		CSelect* pCSelect = m_pCWndDcdGrid->getCSelect() ;

		for ( int iYColumnNumber = 0 ;
			iYColumnNumber < pCXDcdGrid->getYColumnCount() ;
			iYColumnNumber ++ )
		{
			for ( int iXColumnNumber = 0 ;
					iXColumnNumber < pCXDcdGrid->getXColumnCount() ;
				iXColumnNumber ++ )
			{
				//	���ׂẴZ����I�������ɂ��܂��B
				CSelectCell* pCSelectCell = pCSelect->getCell( 
					iXColumnNumber , iYColumnNumber ) ;
				pCSelectCell->setIsSelected( false ) ;
			}
		}
	}
}

int CSelect::getSelectedCellCount()const 
{
	return m_iSelectedCellCount ;
}

int CSelect::getSelectedXColumnCount()const 
{
	int iRv = 0 ;
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_XColumn && 
		zonexyColumnNumberSelectLimit.getX().getSize() > 0 )
	{
		iRv = m_iSelectedCellCount 
			/ zonexyColumnNumberSelectLimit.getY().getSize() ;
	}
	return iRv ;
}

int CSelect::getSelectedYColumnCount()const 
{
	int iRv = 0 ;
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_YColumn && 
		zonexyColumnNumberSelectLimit.getY().getSize() > 0 )
	{
		iRv = m_iSelectedCellCount 
			/ zonexyColumnNumberSelectLimit.getX().getSize() ;
	}
	return iRv ;
}

bool CSelect::getXColumnNumberSelected( int iColumnNumber ) 
{
	bool bRv = false ;
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_XColumn  )
	{
		CSelectCell* pCell = getCell( iColumnNumber , 
			zonexyColumnNumberSelectLimit.getY().getPos() );
		if ( pCell != NULL )
		{
			bRv = pCell->getIsSelected() ;
		}
	}
	return bRv ;
}

void CSelect::setXColumnNumberSelected( int iColumnNumber , bool bIsSelected ) 
{
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_XColumn  )
	{
		CSelectCell* pCell = getCell( iColumnNumber , 
			zonexyColumnNumberSelectLimit.getY().getPos() );
		if ( pCell != NULL )
		{
			pCell->setIsSelected( bIsSelected ) ;
		}
	}
}


bool CSelect::getYColumnNumberSelected( int iColumnNumber ) 
{
	bool bRv = false ;

	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_YColumn  )
	{
		CSelectCell* pCell = getCell(  
			zonexyColumnNumberSelectLimit.getX().getPos() ,
			iColumnNumber );
		if ( pCell != NULL )
		{
			bRv = pCell->getIsSelected() ;
		}
	}
	return bRv ;
	
}



void CSelect::setYColumnNumberSelected( int iColumnNumber , bool bIsSelected ) 
{
	CdDcdZoneXy	zonexyColumnNumberSelectLimit = 
		getColumnNumberSelectLimitRegularized() ;

	if ( m_eSelectMode == SelectMode_YColumn  )
	{
		CSelectCell* pCell = getCell(  
			zonexyColumnNumberSelectLimit.getX().getPos() ,
			iColumnNumber );
		if ( pCell != NULL )
		{
			pCell->setIsSelected( bIsSelected ) ;
		}
	}
}



} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib
