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
//	WndDcdGrid_CFocus.cpp
// ****************************************************************
*/
/** @file */
#include "CWndDcdGrid.h"

#include "NsOu\OuNew.h"
#include "DcDraw\CDcdRectangle.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CaDcdTargetItemPosition.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

// ****************************************************************
//	WndDcdGrid3::CFocus
// ****************************************************************
	// --------------------------------
	//@name	CWndDcdGrid-�t�H�[�J�X
	// --------------------------------
void CFocus::CreateDcDrawFocusCell() 
{
	OuNew<CDcdRectangle>	pCDcdRectangle( new CDcdRectangle( 
				CdPenProp( 1 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::DOT ) ) ) ;
	setIfDcDrawFocusCell( pCDcdRectangle ) ;
}
void CFocus::DeleteDcDrawFocusCell() 
{
	setIfDcDrawFocusCell( Ou<IfDcDraw>() ) ;
}


// --------------------------------
//@name CWndDcdGrid ����̈Ϗ�
// --------------------------------
bool CFocus::update_adjustProp() 
{
	bool bRv = false ;

	CXDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	CDcdTargetGetDC	aCDcdTarget( m_pCWndDcdGrid->GetSafeHwnd() ) ;

	int	iFocusCellXColumnNumber = m_iFocusCellXColumnNumber ;
	int iFocusCellYColumnNumber = m_iFocusCellYColumnNumber ;
	int iXFixafterColumnNumber = m_pCDcdGrid->getXFixafterColumnNumber() ;
	int iYFixafterColumnNumber = m_pCDcdGrid->getYFixafterColumnNumber() ;

	// --------------------------------
	//	�y1.�����̕␳�z
	// --------------------------------

	//  �P�DFocusCell ���팋���Z���ɂȂ����ꍇ�E�E�EFocusCell��
	//	�����Z���Ɉړ����܂��B
	{
		CDcdGridCell*	pCell = m_pCDcdGrid->getCell( 
			iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ;
		if ( pCell != NULL ){
			if ( pCell->getAttachTo() != NULL ){
				pCell = pCell->getAttachTo() ;
				iFocusCellXColumnNumber = m_pCDcdGrid->getXColumnNumberOfCell( pCell ) ;
				iFocusCellYColumnNumber = m_pCDcdGrid->getYColumnNumberOfCell( pCell ) ;

			}
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 0" ) ;

	//	�Q�DFocusCellColumnNumber �� �E�C���h�E�͈̔�
	//	�iIfDcdTarget::getZone()�̗̈�)�Ɏ��܂��Ă��Ȃ��ꍇ�E�E�E
	//	[FixafterColumnNumber �ύX]
	//	FocusCellColumnNumber ���A��ʏ�̈�ԉE���� ColumnNumber �ɂ��܂��B
	//	[FocusCellColumnNumber �ύX]
	//	FocusCellColumnNumber ���E�C���h�E�͈̔͂Ɏ��܂�܂ŁA
	//	FixafterColumnNumber�����Z���܂��B
	//	���̌��ʂƂȂ� FixafterColumnNumber ���A
	//	 FixafterColumnNumberMaxForColumn �ƌĂт܂��B
	{
		int iColumnNumberMaxInDcdTarget = 
				m_pCDcdGrid->getXColumnNumberMaxInDcdTarget( &aCDcdTarget ) ;
		if ( iFocusCellXColumnNumber > iColumnNumberMaxInDcdTarget ){
			//LogMsg( "CWndDcdGrid::adjustProp() 01" ) ;
			if ( !m_bFixafterColumnNumberChange ){
				iFocusCellXColumnNumber = m_pCDcdGrid->
					getXColumnNumberMaxInDcdTarget( &aCDcdTarget )  ;
				if ( iFocusCellXColumnNumber < 0 ){
					iFocusCellXColumnNumber = 0 ;
				}
			}	else	{
				int iXFixafterColumnNumberMinForColumn = m_pCDcdGrid->
					calcXFixafterColumnNumberMinForColumn( &aCDcdTarget , 
						iFocusCellXColumnNumber ) ;

				iXFixafterColumnNumber = iXFixafterColumnNumberMinForColumn ;

				//bRv�̍X�V�́A���̊֐��̖����ōs���܂��B
			}
			//LogMsg( "CWndDcdGrid::adjustProp() 02" ) ;
		}
	}
	{
		int iColumnNumberMaxInDcdTarget = 
				m_pCDcdGrid->getYColumnNumberMaxInDcdTarget( &aCDcdTarget ) ;
		if ( iFocusCellYColumnNumber > iColumnNumberMaxInDcdTarget ){
			//LogMsg( "CWndDcdGrid::adjustProp() 03" ) ;
			if ( !m_bFixafterColumnNumberChange ){
				iFocusCellYColumnNumber = m_pCDcdGrid->
					getYColumnNumberMaxInDcdTarget( &aCDcdTarget )  ;
				if ( iFocusCellYColumnNumber < 0 ){
					iFocusCellYColumnNumber = 0 ;
				}
			}	else	{
				int iYFixafterColumnNumberMinForColumn = m_pCDcdGrid->
					calcYFixafterColumnNumberMinForColumn( &aCDcdTarget , 
						iFocusCellYColumnNumber ) ;

				iYFixafterColumnNumber = iYFixafterColumnNumberMinForColumn ;

				//bRv�̍X�V�́A���̊֐��̖����ōs���܂��B
			}
			//LogMsg( "CWndDcdGrid::adjustProp() 04" ) ;
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 1" ) ;


	//	�R�D FocusCellColumnNumber �� ColumnScrollout �ɂȂ����ꍇ�E�E�E
	//	[FixafterColumnNumber �ύX]
	//	FocusCellColumnNumber �� FixafterColumnNumber �Ɠ����ɂ��܂��B
	//	[FocurCellColumnNumber �ύX]
	//	�X�N���[���ʒu�𐳋K�����āA�t�H�[�J�X�Z�����\�������悤�ɂ��܂��B
	//	FixafterColumnNumber���AFocusCell��ColumnNumber�Ɠ����ɂ��܂��B
	{
		if ( m_pCDcdGrid->getXFixColumnCount() <= iFocusCellXColumnNumber && 
				iFocusCellXColumnNumber < iXFixafterColumnNumber ){
			
			if ( !m_bFixafterColumnNumberChange ){
				iFocusCellXColumnNumber = iXFixafterColumnNumber ;
			}	else	{
				iXFixafterColumnNumber = iFocusCellXColumnNumber ;
				//bRv�̍X�V�́A���̊֐��̖����ōs���܂��B
			}
		}
		if ( m_pCDcdGrid->getYFixColumnCount() <= iFocusCellYColumnNumber && 
				iFocusCellYColumnNumber < iYFixafterColumnNumber ){
			
			if ( !m_bFixafterColumnNumberChange ){
				iFocusCellYColumnNumber = iYFixafterColumnNumber ;
			}	else	{
				iYFixafterColumnNumber =  iFocusCellYColumnNumber ;
				//bRv�̍X�V�́A���̊֐��̖����ōs���܂��B
			}
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 2" ) ;

	//  �S�DFocusCell ��0�ȏ� ColumnCount�����łȂ��ꍇ�E�E�EFocusCell��
	//	�����̒l�ɂ��܂��B
	{
		if ( iFocusCellXColumnNumber >= m_pCDcdGrid->getXColumnCount() ){
			iFocusCellXColumnNumber = m_pCDcdGrid->getXColumnCount() - 1 ;
		}
		if ( iFocusCellXColumnNumber < 0 ){
			iFocusCellXColumnNumber = 0 ;
		}
		if ( iFocusCellYColumnNumber >= m_pCDcdGrid->getYColumnCount() ){
			iFocusCellYColumnNumber = m_pCDcdGrid->getYColumnCount() - 1 ;
		}
		if ( iFocusCellYColumnNumber < 0 ){
			iFocusCellYColumnNumber = 0 ;
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 3" ) ;

	//  �T�DFocusCell ���팋���Z���ɂȂ����ꍇ�E�E�EFocusCell��
	//	�����Z���Ɉړ����܂��B
	{
		CDcdGridCell*	pCell = m_pCDcdGrid->getCell( 
			iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ;
		if ( pCell != NULL ){
			if ( pCell->getAttachTo() != NULL ){
				pCell = pCell->getAttachTo() ;
				iFocusCellXColumnNumber = m_pCDcdGrid->getXColumnNumberOfCell( pCell ) ;
				iFocusCellYColumnNumber = m_pCDcdGrid->getYColumnNumberOfCell( pCell ) ;
			}
		}
	}
	//LogMsg( "CWndDcdGrid::adjustProp() 4" ) ;
	//LogMsg( "CWndDcdGrid::adjustProp() =" ) ;

	// ----------------------------------------------------------------
	//	�y2.�����̕ω���CWndDcdGrid�ɒʒm�z
	// ----------------------------------------------------------------
	if ( m_iFocusCellXColumnNumber != iFocusCellXColumnNumber || 
		m_iFocusCellYColumnNumber != iFocusCellYColumnNumber )
	{
		m_iFocusCellXColumnNumber = iFocusCellXColumnNumber ; 
		m_iFocusCellYColumnNumber = iFocusCellYColumnNumber ;
		bRv = true ;
	}


	if ( m_pCDcdGrid->getXFixafterColumnNumber() != iXFixafterColumnNumber )
	{
		m_pCDcdGrid->setXFixafterColumnNumber( iXFixafterColumnNumber ) ;
		bRv = true ;
	}
	if ( m_pCDcdGrid->getYFixafterColumnNumber() != iYFixafterColumnNumber )
	{
		m_pCDcdGrid->setYFixafterColumnNumber( iYFixafterColumnNumber ) ;
		bRv = true ;
	}

	return ( bRv ) ;
}

bool CFocus::update_updateScreen() 
{
	bool	bRv = true ;
	CXDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	CDcdTargetGetDC	aCDcdTarget( m_pCWndDcdGrid->GetSafeHwnd() ) ;
	
	// --------------------------------
	//	�y2.�����̕ω���CWndDcdGrid�ɒʒm�z
	// --------------------------------
	if ( m_iFocusCellXColumnNumber_Sid != m_iFocusCellXColumnNumber ||
			m_iFocusCellYColumnNumber_Sid != m_iFocusCellYColumnNumber )
	{
		// --------------------------------
		//	�C�x���g�����̂��߂̉��z�֐�
		// --------------------------------
		CDcdGridCell*	pCDcdGridCell = m_pCDcdGrid->getCell( 
				m_iFocusCellXColumnNumber , m_iFocusCellYColumnNumber ) ;
		if ( pCDcdGridCell != NULL )
		{
			m_pCWndDcdGrid->OnSetFocusCell( pCDcdGridCell ) ;
		}
	}
	// ----------------------------------------------------------------
	//	�t�H�[�J�X�Z���ړ����́A
	//	�t�H�[�J�X�Z���̋��ʒu�ƐV�ʒu���ĕ`��
	// ----------------------------------------------------------------
	if ( m_iFocusCellXColumnNumber_Sid != m_iFocusCellXColumnNumber ||
			m_iFocusCellYColumnNumber_Sid != m_iFocusCellYColumnNumber )
	{
		m_pCWndDcdGrid->InvalidateCell( m_iFocusCellXColumnNumber_Sid , 
			m_iFocusCellYColumnNumber_Sid ) ;
		m_pCWndDcdGrid->InvalidateCell( m_iFocusCellXColumnNumber , 
			m_iFocusCellYColumnNumber ) ;
		
		// --------------------------------
		m_iFocusCellXColumnNumber_Sid = m_iFocusCellXColumnNumber ;
		m_iFocusCellYColumnNumber_Sid = m_iFocusCellYColumnNumber ;
		bRv = true ;
	}
	return ( bRv ) ;
}
bool CFocus::OnPaint( IfDcdTarget* pIfDcdTarget ) 
{
	bool bRv = false ;
	CXDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	// --------------------------------	
	//	�t�H�[�J�X�}�[�N
	// --------------------------------	
	if ( m_pIfDcDrawFocusCell != NULL ){
		if ( m_bIsFocusmarkShowEvery || 
			CWnd::GetFocus() == m_pCWndDcdGrid ) {

			CdDcdZoneXy	zoneFocusCell = m_pCDcdGrid->getCellZone( 
				pIfDcdTarget ,
				m_iFocusCellXColumnNumber , m_iFocusCellYColumnNumber ) ;
	
			CaDcdTargetItemPosition	aCDcdTargetItemPosition( pIfDcdTarget ,
				zoneFocusCell ) ;
			if ( aCDcdTargetItemPosition.isDrawable() ){
				m_pIfDcDrawFocusCell->DcDraw( &aCDcdTargetItemPosition ) ;
				
				bRv = true ;
			}
		}
	}
	

	return bRv ;
}
	
void CFocus::OnSize(UINT nType, int cx, int cy)
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
	//	���̏ꍇ�̃t�H�[�J�X�ړ��́A
	//	m_iXFixafterColumnNumber_Sid,m_iYFixafterColumnNumber_Sid�ɂ����
	//	�ĕ`�悳��邽�߁A�N���A����K�v�͂���܂���B
	//m_iFocusCellXColumnNumber_Sid = -1 ;
	//m_iFocusCellYColumnNumber_Sid = -1 ;

}

void CFocus::OnSetFocus(CWnd* pOldWnd)
{
	CDcdGridCell* pCell = getFocusCell() ;
	int iFocusCellXColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getXColumnNumberOfCell( pCell ) ; 
	int iFocusCellYColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ; 
	m_pCWndDcdGrid->InvalidateCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ;
}
void CFocus::OnKillFocus(CWnd* pNewWnd)
{
	CDcdGridCell* pCell = getFocusCell() ;
	int iFocusCellXColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getXColumnNumberOfCell( pCell ) ; 
	int iFocusCellYColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getYColumnNumberOfCell( pCell ) ; 
	m_pCWndDcdGrid->InvalidateCell( iFocusCellXColumnNumber , iFocusCellYColumnNumber ) ;
}

void CFocus::InvalidateGrid()
{
	//	���̃N���X�̉�ʕ`��͂��ׂ�OnPaint�ōs���܂��B
	//	InvalidateGrid�ł́A���ʂȏ����͕s�v�ł��B


}

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CFocus::CFocus( CWndDcdGrid* pCWndDcdGrid ) 
	: m_pCWndDcdGrid( pCWndDcdGrid )
	, m_iFocusCellXColumnNumber( 0 )
	, m_iFocusCellYColumnNumber( 0 )
	, m_bFixafterColumnNumberChange( true )
	, m_bIsFocusmarkShowEvery( false )
	, m_iFocusCellXColumnNumber_Sid( -1 )
	, m_iFocusCellYColumnNumber_Sid( -1 )
{

	CreateDcDrawFocusCell() ;
}

CFocus::~CFocus() 
{
	DeleteDcDrawFocusCell() ;
}
	// ********************************
	//@name �֘A
	// ********************************
Ou<IfDcDraw>	CFocus::getIfDcDrawFocusCell() 
{
	return ( m_pIfDcDrawFocusCell ) ;
}
void CFocus::setIfDcDrawFocusCell( Ou<IfDcDraw> value ) 
{
	m_pIfDcDrawFocusCell = value ;
}
	// ********************************
	///@name CWndDcdGrid-�t�H�[�J�X
	// ********************************

CdDcdPosXy	CFocus::getFocusCellColumnNumber() 
{
	CdDcdPosXy	posXy( ColumnNumberPosXy_NULL() ) ;
	CXDcdGrid* pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	if( 0 <= m_iFocusCellXColumnNumber && 
		m_iFocusCellXColumnNumber < pCDcdGrid->getXColumnCount() && 
		0 <= m_iFocusCellYColumnNumber && 
		m_iFocusCellYColumnNumber < pCDcdGrid->getYColumnCount() )
	{
		posXy.setX( m_iFocusCellXColumnNumber ) ;
		posXy.setY( m_iFocusCellYColumnNumber ) ;
	}
	return posXy ;
}

void CFocus::setFocusCellColumnNumber( const CdDcdPosXy& value ) 
{
	if ( m_iFocusCellXColumnNumber == value.getX() &&
		m_iFocusCellYColumnNumber == value.getY() )
	{
		return ;
	}
	m_iFocusCellXColumnNumber = value.getX() ;
	m_iFocusCellYColumnNumber = value.getY() ;

	//	�����̕ύX�����ƂɁA�E�C���h�E�\���̍X�V�������s���܂��B
	m_pCWndDcdGrid->update() ;
}

CDcdGridCell*	CFocus::getFocusCell() 
{
	CDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
	return ( m_pCDcdGrid->getCell( 
		m_iFocusCellXColumnNumber , m_iFocusCellYColumnNumber ) ) ;
}


void CFocus::setFocusCell( CDcdGridCell* value ) 
{
	if ( value == NULL ){
		return ;
	}

	CXDcdGrid* m_pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;

	int iXColumnNumber = m_pCDcdGrid->getXColumnNumberOfCell( value ) ;
	int iYColumnNumber = m_pCDcdGrid->getYColumnNumberOfCell( value )  ;

	if ( m_iFocusCellXColumnNumber == iXColumnNumber &&
		m_iFocusCellYColumnNumber == iYColumnNumber )
	{
		return ;
	}
	m_iFocusCellXColumnNumber = iXColumnNumber ;
	m_iFocusCellYColumnNumber = iYColumnNumber ;

	//	�����̕ύX�����ƂɁA�E�C���h�E�\���̍X�V�������s���܂��B
	m_pCWndDcdGrid->update() ;
}


bool	CFocus::getFixafterColumnNumberChange()
{
	return m_bFixafterColumnNumberChange ;
}
void CFocus::setFixafterColumnNumberChange( bool value ) 
{
	m_bFixafterColumnNumberChange = value ;
}

bool	CFocus::getIsFocusmarkShowEvery()
{
	return m_bIsFocusmarkShowEvery ;
}
void CFocus::setIsFocusmarkShowEvery( bool value ) 
{
	if ( m_bIsFocusmarkShowEvery != value ){
		m_bIsFocusmarkShowEvery = value ;
		m_pCWndDcdGrid->InvalidateCell( 
			m_iFocusCellXColumnNumber , m_iFocusCellYColumnNumber ) ;
	}
}

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib
