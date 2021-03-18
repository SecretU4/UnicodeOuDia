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
//	$Id: CXDcdGrid.cpp 387 2016-11-20 08:43:33Z okm $
// ****************************************************************
*/
/** @file */
#include "CWndDcdGrid.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "WinUtil\CconvWinUser.h"
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
//	WndDcdGrid3::CXDcdGrid
// ----------------------------------------------------------------
// ********************************
//	�R���X�g���N�^
// ********************************
CXDcdGrid::CXDcdGrid( CWndDcdGrid* pCWndDcdGrid ) 
	: m_bUpdateCWndDcdGrid( true ) 
	, m_pCWndDcdGrid( pCWndDcdGrid ) 
{
}
CXDcdGrid::~CXDcdGrid() 
{
}
// ********************************
//	CDcdGrid
// ********************************
	// --------------------------------
	//@name �s�E��E�Z���̏�����
	// --------------------------------
void CXDcdGrid::OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	m_pCWndDcdGrid->OnCreateXColumn( iXColumnNumber , 
		pCDcdGridXColumn ) ;
}
	
void CXDcdGrid::OnDeleteXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	m_pCWndDcdGrid->OnDeleteXColumn( iXColumnNumber , 
		pCDcdGridXColumn ) ;
}

void CXDcdGrid::OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
	m_pCWndDcdGrid->OnCreateYColumn( iYColumnNumber , 
		pCDcdGridYColumn ) ;
}

void CXDcdGrid::OnDeleteYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
	m_pCWndDcdGrid->OnDeleteYColumn( iYColumnNumber , 
		pCDcdGridYColumn ) ;
}

void CXDcdGrid::OnCreateCell( 
		int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) 
{
	m_pCWndDcdGrid->OnCreateCell( 
		iXColumnNumber , iYColumnNumber , 
		pCDcdGridCell ) ;
}
	
void CXDcdGrid::OnDeleteCell( 
		int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) 
{
	m_pCWndDcdGrid->OnDeleteCell( 
		iXColumnNumber , iYColumnNumber , 
		pCDcdGridCell ) ;
}
	
	// ********************************
	//	@name Y��EX��̐�
	// ********************************
int CXDcdGrid::getYColumnCount() 
{
	return CDcdGrid::getYColumnCount() ;
};
	
CDcdGrid& CXDcdGrid::setYColumnCount( int ev ) 
{
	//LogMsg( "CWndDcdGrid::setYColumnCount()" ) ;

	CDcdGrid::setYColumnCount( ev ) ;
	m_pCWndDcdGrid->InvalidateGrid() ;

	//LogMsg( "CWndDcdGrid::setYColumnCount()=" ) ;

	return *this ;
};
	
int		CXDcdGrid::getXColumnCount() 
{
	return CDcdGrid::getXColumnCount() ;
};

CDcdGrid& CXDcdGrid::setXColumnCount( int ev ) 
{
	CDcdGrid::setXColumnCount( ev ) ;
	m_pCWndDcdGrid->InvalidateGrid() ;

	return *this ;
};

	// ********************************
	//	@name Y��EX���}��/�폜
	// ********************************
int CXDcdGrid::insertYColumn( int iYColumnNumber , 
		bool bFixafterColumnNumberChange ) 
{
	int iRv = CDcdGrid::insertYColumn( iYColumnNumber ) ;
	//	�t�H�[�J�X�ʒu�E�X�N���[���ʒu�E�I�����Đݒ�
	m_pCWndDcdGrid->InvalidateGrid() ;

	if ( iRv >= 0 )
	{

		//	�t�H�[�J�X�Z���̂����E�܂��͂������Index�̏������ꏊ��
		//	�񂪒ǉ����ꂽ�ꍇ�́A�t�H�[�J�X�Z����
		//	�}���ɂ���Ă��ꂽ��ɒǏ]�����܂��B
		CDcdGridCell* pCell = m_pCWndDcdGrid->getCFocus()->getFocusCell() ;
		int iFocusCellXColumnNumber = getXColumnNumberOfCell( pCell ) ; 
		int iFocusCellYColumnNumber = getYColumnNumberOfCell( pCell ) ; 
		if ( iFocusCellYColumnNumber >= iYColumnNumber )
		{
			iFocusCellYColumnNumber ++ ;
			m_pCWndDcdGrid->getCFocus()->setFocusCell( 
				getCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ) ;
		}
	}
	return ( iRv ) ;
};
int CXDcdGrid::insertXColumn( int iXColumnNumber ,
		bool bFixafterColumnNumberChange ) 
{
	int iRv = CDcdGrid::insertXColumn( iXColumnNumber ) ;
	//	�t�H�[�J�X�ʒu�E�X�N���[���ʒu�E�I�����Đݒ�
	m_pCWndDcdGrid->InvalidateGrid() ;

	if ( iRv >= 0 )
	{
		//	�t�H�[�J�X�Z���̂����E�܂��͂������Index�̏������ꏊ��
		//	�񂪒ǉ����ꂽ�ꍇ�́A�t�H�[�J�X�Z����
		//	�}���ɂ���Ă��ꂽ��ɒǏ]�����܂��B
		CDcdGridCell* pCell = m_pCWndDcdGrid->getCFocus()->getFocusCell() ;
		int iFocusCellXColumnNumber = getXColumnNumberOfCell( pCell ) ; 
		int iFocusCellYColumnNumber = getYColumnNumberOfCell( pCell ) ; 
		if ( iFocusCellXColumnNumber >= iXColumnNumber ){
			iFocusCellXColumnNumber ++ ;
			m_pCWndDcdGrid->getCFocus()->setFocusCell( 
				getCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ) ;
		}
	}
	return ( iRv ) ;
};

int CXDcdGrid::eraseYColumn( int iYColumnNumber ) 
{
	int iRv = CDcdGrid::eraseYColumn( iYColumnNumber ) ;
	//	�t�H�[�J�X�ʒu�E�X�N���[���ʒu�E�I�����Đݒ�
	m_pCWndDcdGrid->InvalidateGrid() ;

	if ( iRv >= 0 )
	{

		CDcdGridCell* pCell = m_pCWndDcdGrid->getCFocus()->getFocusCell() ;
		//	�Z���̐���0�ɂȂ�������́A���̖߂�l��NULL�ɂȂ�܂��B

		if ( pCell != NULL )
		{
			//	�t�H�[�J�X�Z���̂�������Index�̏������ꏊ����
			//	�񂪍폜���ꂽ�ꍇ�́A�t�H�[�J�X�Z����
			//	�폜�ɂ���Ă��ꂽ��ɒǏ]�����܂��B
			int iFocusCellXColumnNumber = getXColumnNumberOfCell( pCell ) ; 
			int iFocusCellYColumnNumber = getYColumnNumberOfCell( pCell ) ; 
			if ( iFocusCellYColumnNumber > iYColumnNumber )
			{
				iFocusCellYColumnNumber -- ;
				m_pCWndDcdGrid->getCFocus()->setFocusCell( 
					getCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ) ;
			}
		}
		
	}
	return ( iRv ) ;
};

int CXDcdGrid::eraseXColumn( int iXColumnNumber ) 
{
	int iRv = CDcdGrid::eraseXColumn( iXColumnNumber ) ;
	//	�t�H�[�J�X�ʒu�E�X�N���[���ʒu�E�I�����Đݒ�
	m_pCWndDcdGrid->InvalidateGrid() ;

	if ( iRv >= 0 )
	{

		CDcdGridCell* pCell = m_pCWndDcdGrid->getCFocus()->getFocusCell() ;
		//	�Z���̐���0�ɂȂ�������́A���̖߂�l��NULL�ɂȂ�܂��B

		if ( pCell != NULL )
		{
			//	�t�H�[�J�X�Z���̂�������Index�̏������ꏊ����
			//	�񂪍폜���ꂽ�ꍇ�́A�t�H�[�J�X�Z����
			//	�폜�ɂ���Ă��ꂽ��ɒǏ]�����܂��B
			int iFocusCellXColumnNumber = getXColumnNumberOfCell( pCell ) ; 
			int iFocusCellYColumnNumber = getYColumnNumberOfCell( pCell ) ; 
			if ( iFocusCellXColumnNumber > iXColumnNumber )
			{
				iFocusCellXColumnNumber -- ;
				m_pCWndDcdGrid->getCFocus()->setFocusCell( 
					getCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ) ;
			}
		}
	}
	return ( iRv ) ;
};



	// ********************************
	//	@name	�X�N���[��
	// ********************************
int	CXDcdGrid::getXFixColumnCount() 
{
	return CDcdGrid::getXFixColumnCount() ;
}
CDcdGrid& CXDcdGrid::setXFixColumnCount( int ev ) 
{
	CDcdGrid::setXFixColumnCount( ev ) ;
	if ( m_bUpdateCWndDcdGrid )
	{
		m_pCWndDcdGrid->InvalidateGrid() ;
	}
	return *this ;
}
int	CXDcdGrid::getXFixafterColumnNumber() 
{
	return CDcdGrid::getXFixafterColumnNumber() ;
}
CDcdGrid& CXDcdGrid::setXFixafterColumnNumber( int ev ) 
{
	CDcdGrid::setXFixafterColumnNumber( ev ) ;

	//	�����̕ύX�����ƂɁA�E�C���h�E�\���̍X�V�������s���܂��B
	if ( m_bUpdateCWndDcdGrid )
	{
		m_pCWndDcdGrid->update() ;
	}
	return *this ;
}
int	CXDcdGrid::getYFixColumnCount() 
{
	return CDcdGrid::getYFixColumnCount() ;
}
CDcdGrid& CXDcdGrid::setYFixColumnCount( int ev ) 
{
	CDcdGrid::setYFixColumnCount( ev ) ;
	if ( m_bUpdateCWndDcdGrid )
	{
		m_pCWndDcdGrid->InvalidateGrid() ;
	}
	return *this ;
}
int	CXDcdGrid::getYFixafterColumnNumber() 
{
	return CDcdGrid::getYFixafterColumnNumber() ;
}
CDcdGrid& CXDcdGrid::setYFixafterColumnNumber( int ev ) 
{
	CDcdGrid::setYFixafterColumnNumber( ev ) ;
	
	//	�����̕ύX�����ƂɁA�E�C���h�E�\���̍X�V�������s���܂��B
	if ( m_bUpdateCWndDcdGrid )
	{
		m_pCWndDcdGrid->update() ;
	}
	return *this ;
}


bool CXDcdGrid::update_adjustProp() 
{
	bool bRv = false ;

	return bRv ;
}

bool CXDcdGrid::update_updateScreen() 
{
	bool bRv = false ;
	CDcdTargetGetDC	aCDcdTarget( m_pCWndDcdGrid->GetSafeHwnd() ) ;


	// ----------------------------------------------------------------
	//	�C�x���g�����̂��߂̉��z�֐��Ăяo��
	// ----------------------------------------------------------------
	if ( getXFixafterColumnNumber() != m_CdScrollbarPropX_Sid.getPos() ) 
	{
		//	�C�x���g�����̂��߂̉��z�֐�
		m_pCWndDcdGrid->OnSetXFixafterColumnNumber( getXFixafterColumnNumber() ) ;
	}
	if ( getYFixafterColumnNumber() != m_CdScrollbarPropY_Sid.getPos() ) 
	{
		//	�C�x���g�����̂��߂̉��z�֐�
		m_pCWndDcdGrid->OnSetYFixafterColumnNumber( getYFixafterColumnNumber() ) ;
	}

	// ----------------------------------------------------------------
	//	X�����N���C�A���g�̈�X�N���[��
	// ----------------------------------------------------------------
	if ( !m_CdScrollbarPropX_Sid.isNull() && 
		m_CdScrollbarPropX_Sid.getPos() != 
		getXFixafterColumnNumber() )
	{
		{
			// --------------------------------
			//	�X�N���[������̈�����߂�
			// --------------------------------
			CRect	rectScroll ;
			{
				CRect	rectClient ;
				m_pCWndDcdGrid->GetClientRect( &rectClient ) ;
				rectScroll = rectClient ;
				{
					DcdSize sizeFix = getXColumnBorderZone( 
						&aCDcdTarget , getXFixColumnCount() - 1 )
						.getEndPos() ;
					rectScroll.left = sizeFix ;
				}
			}
			//rectScroll = �E�C���h�E��ŁA�X�N���[�����s���̈�
			//	�i�Œ�񕔕����������̈�j

			// --------------------------------
			//	�X�N���[���ʂ����߂�
			// --------------------------------
			int iAmount = 0 ;
			CRect	rectScrollSrc ;
			{
				rectScrollSrc = rectScroll ;
				if ( m_CdScrollbarPropX_Sid.getPos() < 
						getXFixafterColumnNumber() ){
					for ( int iColumnNumber = m_CdScrollbarPropX_Sid.getPos() ;
						iColumnNumber < getXFixafterColumnNumber() ;
						iColumnNumber ++ )
					{
						iAmount -= getXColumn( iColumnNumber )->getColumnSize( &aCDcdTarget ) ;
						iAmount -= getXBorder( iColumnNumber )->getColumnBorderSize( &aCDcdTarget ) ;
					}

					rectScrollSrc.left += - iAmount ;
		
				} else if ( getXFixafterColumnNumber() < 
						m_CdScrollbarPropX_Sid.getPos() ){
					for ( int iColumnNumber = m_CdScrollbarPropX_Sid.getPos() - 1 ;
						iColumnNumber >= getXFixafterColumnNumber() ;
						iColumnNumber -- )
					{
						iAmount += getXColumn( iColumnNumber )->getColumnSize( &aCDcdTarget ) ;
						iAmount += getXBorder( iColumnNumber )->getColumnBorderSize( &aCDcdTarget ) ;
					}



					rectScrollSrc.right -= iAmount ;
				}
			}
			//iAmount = �X�N���[����(���̐��͍�/��ɃX�N���[��)
			//rectScrollSrc = �X�N���[���ňړ��ƂȂ�̈�ł��B
			//	rectScroll �̈悩��A�X�N���[���Ŕ�\���ɂȂ�̈�����������̂ł��B
			//	�������A���̒l�� left >= right �ɂȂ����ꍇ�A�X�N���[���ňړ��ƂȂ�
			//	�̈悪�S���Ȃ����Ƃ������܂��B
			//	���̏ꍇ�́A�X�N���[���̈�S�̂𖳌�������
			//	�ĕ`����s�킹�܂��B

			// --------------------------------
			//	��ʂ��X�N���[���E�܂��͖������ɂ��
			//	�X�V
			// --------------------------------
			if ( iAmount != 0 )
			{
				if ( rectScrollSrc.left >= rectScrollSrc.right )
				{
					m_pCWndDcdGrid->InvalidateRect( rectScroll ) ;
				}
				else
				{
					//	����́A�����ɂȂ�Ȃ��̈悪����܂��B
					//m_pCWndDcdGrid->ScrollWindow( iAmount , 0 , &rectScrollSrc ) ;
		
					m_pCWndDcdGrid->ScrollWindow( iAmount , 0 , &rectScroll , &rectScroll ) ;
				}
				bRv = true ;
			}
		}
	}
	// ----------------------------------------------------------------
	//	X�����X�N���[���o�[������ݒ�
	// ----------------------------------------------------------------
	{
		WinUtil::CdScrollbarProp	aScrollbarPropX ;

		int iPage = 
			getXColumnNumberMaxInDcdTarget( &aCDcdTarget ) - 
			getXFixafterColumnNumber() + 1 ;

		//	�X�N���[���o��\������ꍇ�A�X�N���[���o�[�̃y�[�W���́A�P�Ƃ��܂��B
		//
		//	�y�[�W�����A��Œ�񐔂�菬�����ꍇ�́A
		//	�X�N���[���o�[�̕\�����K�v�ł��B
		//	���̏ꍇ�̓y�[�W����1�Ƃ��܂��B
		if ( iPage < getXColumnCount() - 
				getXFixColumnCount() ){
			//	�X�N���[���o�[���K�v
			iPage = 1 ;
		}

		aScrollbarPropX.set(
			getXFixColumnCount() ,
			getXColumnCount() - 1 ,
			iPage ,
			getXFixafterColumnNumber() ) ;
		if ( !m_CdScrollbarPropX_Sid.isEqualTo( aScrollbarPropX ) )
		{
			SCROLLINFO	aScrollinfo = 
				WinUtil::CconvWinUser::SCROLLINFOof( aScrollbarPropX ) ;
			m_pCWndDcdGrid->SetScrollInfo( SB_HORZ , &aScrollinfo ) ; 
		
			m_CdScrollbarPropX_Sid = aScrollbarPropX ;
			bRv = true ;
		}

	}
	// ----------------------------------------------------------------
	//	Y�����N���C�A���g�̈�X�N���[��
	// ----------------------------------------------------------------
	if ( !m_CdScrollbarPropY_Sid.isNull() &&
		m_CdScrollbarPropY_Sid.getPos() != 
			getYFixafterColumnNumber() )
	{

		{ 
			// --------------------------------
			//	�X�N���[������̈�����߂�
			// --------------------------------
			CRect	rectScroll ;
			{
				CRect	rectClient ;
				m_pCWndDcdGrid->GetClientRect( &rectClient ) ;
				rectScroll = rectClient ;
				{
					DcdSize sizeFix = getYColumnBorderZone( 
						&aCDcdTarget , getYFixColumnCount() - 1 )
						.getEndPos() ;
					rectScroll.top = sizeFix ;
				}
			}
			//rectScroll = �E�C���h�E��ŁA�X�N���[�����s���̈�
			//	�i�Œ�񕔕����������̈�j
		
			// --------------------------------
			//	�X�N���[���ʂ����߂�
			// --------------------------------
			int iAmount = 0 ;
			CRect	rectScrollSrc ;
			{
				rectScrollSrc = rectScroll ;
				if ( m_CdScrollbarPropY_Sid.getPos() < 
						getYFixafterColumnNumber() ){
					
					for ( int iColumnNumber = m_CdScrollbarPropY_Sid.getPos() ;
						iColumnNumber < getYFixafterColumnNumber() ;
						iColumnNumber ++ )
					{
						iAmount -= getYColumn( iColumnNumber )->getColumnSize( &aCDcdTarget ) ;
						iAmount -= getYBorder( iColumnNumber )->getColumnBorderSize( &aCDcdTarget ) ;
					}
							
					rectScrollSrc.top += - iAmount ;
		
				} else if ( getYFixafterColumnNumber() < 
						m_CdScrollbarPropY_Sid.getPos() ){
					for ( int iColumnNumber = m_CdScrollbarPropY_Sid.getPos() - 1 ;
						iColumnNumber >= getYFixafterColumnNumber() ;
						iColumnNumber -- )
					{
						iAmount += getYColumn( iColumnNumber )->getColumnSize( &aCDcdTarget ) ;
						iAmount += getYBorder( iColumnNumber )->getColumnBorderSize( &aCDcdTarget ) ;
					}

					rectScrollSrc.bottom -= iAmount ;
				}
			}
			//iAmount = �X�N���[����(���̐��͍�/��ɃX�N���[��)
			//rectScrollSrc = �X�N���[���ňړ��ƂȂ�̈�ł��B
			//	rectScroll �̈悩��A�X�N���[���Ŕ�\���ɂȂ�̈�����������̂ł��B
			//	�������A���̒l�� top >= bottom �ɂȂ����ꍇ�A�X�N���[���ňړ��ƂȂ�
			//	�̈悪�S���Ȃ����Ƃ������܂��B
			//	���̏ꍇ�́A�X�N���[���̈�S�̂𖳌�������
			//	�ĕ`����s�킹�܂��B
		
			// --------------------------------
			//	��ʂ��X�N���[���E�܂��͖������ɂ��
			//	�X�V
			// --------------------------------
			if ( iAmount != 0 ){
				if ( rectScrollSrc.top >= rectScrollSrc.bottom ){
					m_pCWndDcdGrid->InvalidateRect( rectScroll ) ;
				}	else	{
					//	����́A�����ɂȂ�Ȃ��̈悪����܂�
					//ScrollWindow( 0 , iAmount , &rectScrollSrc ) ;	
					
					m_pCWndDcdGrid->ScrollWindow(  0 , iAmount , &rectScroll , &rectScroll ) ;
				}
				bRv = true ;
			}
		}
	}
	// ----------------------------------------------------------------
	//	Y�����X�N���[���o�[������ݒ�
	// ----------------------------------------------------------------
	{
		WinUtil::CdScrollbarProp	aScrollbarPropY ;

		int iPage = 
			getYColumnNumberMaxInDcdTarget( &aCDcdTarget ) - 
			getYFixafterColumnNumber() + 1 ;

		//	�X�N���[���o��\������ꍇ�A�X�N���[���o�[�̃y�[�W���́A�P�Ƃ��܂��B
		//
		//	�y�[�W�����A��Œ�񐔂�菬�����ꍇ�́A
		//	�X�N���[���o�[�̕\�����K�v�ł��B
		//	���̏ꍇ�̓y�[�W����1�Ƃ��܂��B
		if ( iPage < getYColumnCount() - 
				getYFixColumnCount() ){
			//	�X�N���[���o�[���K�v
			iPage = 1 ;
		}


		aScrollbarPropY.set(
			getYFixColumnCount() ,
			getYColumnCount() - 1 ,
			iPage ,
			getYFixafterColumnNumber() ) ;
		if ( !m_CdScrollbarPropY_Sid.isEqualTo( aScrollbarPropY ) )
		{
			SCROLLINFO	aScrollinfo =
				WinUtil::CconvWinUser::SCROLLINFOof( aScrollbarPropY ) ;
			m_pCWndDcdGrid->SetScrollInfo( SB_VERT , &aScrollinfo ) ; 
		
			m_CdScrollbarPropY_Sid = aScrollbarPropY ;
			bRv = true ;
		}
	}

	return bRv ;
}

void CXDcdGrid::InvalidateGrid( 
		bool bErase ) 
{
	//	���S�ȍĕ`��̂��߁A���ׂĂ̑O��l���N���A���܂��B
	m_CdScrollbarPropX_Sid.setNull() ;
	m_CdScrollbarPropY_Sid.setNull() ;
}

// ********************************
//@name CXDcdGrid ����
// ********************************
bool CXDcdGrid::getUpdateCWndDcdGrid()const 
{
	return m_bUpdateCWndDcdGrid ;
}
void CXDcdGrid::setUpdateCWndDcdGrid( bool value ) 
{
	if ( m_bUpdateCWndDcdGrid != value )
	{
		//�@������ false ���� true �ɕύX�����ꍇ�́ACWndDcdGrid �S�̂��X�V���܂��B
		if ( value )
		{
			m_pCWndDcdGrid->update() ;
		}

		m_bUpdateCWndDcdGrid = value ;
	}
}
	// ================================
	//@name CXDcdGrid_ZoneCacheTemp �ɁAcreateZoneCache�����J
	// ================================
bool CXDcdGrid::createZoneCache( IfDcdTarget* pIfDcdTarger )
{
	LogMsg( "CXDcdGrid::createZoneCache()" ) ;
	return CDcdGrid::createZoneCache( pIfDcdTarger ) ;
};
void CXDcdGrid::destroyZoneCache()
{
	CDcdGrid::destroyZoneCache() ;
	LogMsg( "CXDcdGrid::destroyZoneCache()" ) ;
};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib
