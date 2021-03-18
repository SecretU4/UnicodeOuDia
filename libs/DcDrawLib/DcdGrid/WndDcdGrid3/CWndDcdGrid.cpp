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
// CWndDcdGrid.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CPropStack.h"
#include "NsOu/OuNew.h"
#include "DcDraw/CDcdTargetGetDC.h"
#include "DcDraw/CDcdTargetOnPaint.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/CDcdRectangle.h"
#include "LogMsg/LogMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{


/////////////////////////////////////////////////////////////////////////////
// CWndDcdGrid

///	�u�̈�O�h���b�O�X�N���[���v�̃^�C�}ID
const UINT_PTR OutsideDrag_TIMERID = 1 ;

// --------------------------------
//@name	�����֐�
// --------------------------------
bool CWndDcdGrid::update() 
{
	bool bRv = false ;
	if ( GetSafeHwnd() != NULL )
	{

		if ( !m_bDisable_UpdateAll )
		{
			//LogMsg( "CWndDcdGrid::update()" ) ;

			m_bDisable_UpdateAll = true ;
			// --------------------------------
			bRv |= m_pCDcdGrid->update_adjustProp() ;
			bRv |= m_pCFocus->update_adjustProp() ;
			bRv |= m_pCSelect->update_adjustProp() ;

			bRv |= m_pCBoxSelect->update_adjustProp() ;
			bRv |= m_pCRandomSelect->update_adjustProp() ;
			if ( bRv )
			{
				//	CBoxSelect,CRandomSelect �́A CSelect���X�V���܂��B
				//	���̍X�V�ɑ΂��鐳�K�����s���K�v�����邽�߁A
				//	�ēx CSelet::update_adjustProp() ���s���Ă��܂��B
				bRv |= m_pCSelect->update_adjustProp() ;
				bRv |= m_pCFocus->update_adjustProp() ;
				bRv |= m_pCDcdGrid->update_adjustProp() ;
			}

			// --------------------------------
			bRv |= m_pCDcdGrid->update_updateScreen() ;
			bRv |= m_pCFocus->update_updateScreen() ;
			bRv |= m_pCSelect->update_updateScreen() ;
			bRv |= m_pCBoxSelect->update_updateScreen() ;
			bRv |= m_pCRandomSelect->update_updateScreen() ;
			// --------------------------------
			m_bDisable_UpdateAll = false ;

			//LogMsg( "CWndDcdGrid::update()=%d" , bRv ) ;
		}
	}
	return ( bRv ) ;
}

Ou<CPropStack>  CWndDcdGrid::createPropStackForMovingFocusCell()
{
	OuNew<CPropStack> pPropStack( new CPropStack( this ) ) ;
	pPropStack->CFocus_setFixafterColumnNumberChange( true ) ;
	return pPropStack ;

}
Ou<CPropStack> CWndDcdGrid::createPropStackForScroll() 
{
	OuNew<CPropStack> pPropStack( new CPropStack( this ) ) ;
	pPropStack->CFocus_setFixafterColumnNumberChange( false ) ;
	return pPropStack ;
}

// ********************************
//	�R���X�g���N�^
// ********************************
CWndDcdGrid::CWndDcdGrid()
	: m_iOutsideDrag_TimeMs( 100 )
	, m_bOutsideDrag_TimerOn( false ) 
	, m_bDisable_UpdateAll( false ) 
	, m_bLButtonIsDown( false ) 
{
	m_pCDcdGrid = new CXDcdGrid( this ) ;

	m_pCFocus = new CFocus( this ) ;

	m_pCSelect = new CSelect( this ) ;

	m_pCBoxSelect = new CBoxSelect( this ) ;

	m_pCRandomSelect = new CRandomSelect( this ) ;

}

CWndDcdGrid::~CWndDcdGrid()
{
	delete m_pCRandomSelect ; m_pCRandomSelect = NULL ;
	delete m_pCBoxSelect ;m_pCBoxSelect = NULL ;
	delete m_pCSelect ;	m_pCSelect = NULL ;
	delete m_pCFocus ;	m_pCFocus = NULL ;
	delete m_pCDcdGrid ;m_pCDcdGrid = NULL ;
}

// ********************************
//	CDcdGrid
// ********************************
	// --------------------------------
	//@name �s�E��E�Z���̏�����
	// --------------------------------
void CWndDcdGrid::OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	m_pCDcdGrid->CDcdGrid::OnCreateXColumn( iXColumnNumber , 
		pCDcdGridXColumn ) ;

	//	CSelect �ɈϏ�
	m_pCSelect->OnCreateXColumn( iXColumnNumber ) ;
}
	
void CWndDcdGrid::OnDeleteXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	m_pCDcdGrid->CDcdGrid::OnDeleteXColumn( iXColumnNumber , 
		pCDcdGridXColumn ) ;

	//	CSelect �ɈϏ�
	m_pCSelect->OnDeleteXColumn( iXColumnNumber ) ;
}

void CWndDcdGrid::OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
	m_pCDcdGrid->CDcdGrid::OnCreateYColumn( iYColumnNumber , 
		pCDcdGridYColumn ) ;

	//	CSelect �ɈϏ�
	m_pCSelect->OnCreateYColumn( iYColumnNumber ) ;
}

void CWndDcdGrid::OnDeleteYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
	m_pCDcdGrid->CDcdGrid::OnDeleteYColumn( iYColumnNumber , 
		pCDcdGridYColumn ) ;

	//	CSelect �ɈϏ�
	m_pCSelect->OnDeleteYColumn( iYColumnNumber ) ;
}

void CWndDcdGrid::OnCreateCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) 
{
	m_pCDcdGrid->CDcdGrid::OnCreateCell( 
		iXColumnNumber , iYColumnNumber , 
		pCDcdGridCell ) ;
}
	
void CWndDcdGrid::OnDeleteCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) 
{
	m_pCDcdGrid->CDcdGrid::OnDeleteCell( 
		iXColumnNumber , iYColumnNumber , 
		pCDcdGridCell ) ;
}

	// ********************************
	//	@name Y��EX��̈ʒu
	// ********************************
CdDcdZone	CWndDcdGrid::getYColumnZone( 
			int iYColumnNumber ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getYColumnZone( 
			&aCDcdTarget , iYColumnNumber ) ;
};
		
CdDcdZone	CWndDcdGrid::getXColumnZone( 
			int iXColumnNumber ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getXColumnZone( 
			&aCDcdTarget  , iXColumnNumber ) ;
};
	
CdDcdZone	CWndDcdGrid::getYColumnBorderZone( 
			int iYColumnNumber ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getYColumnBorderZone( 
			&aCDcdTarget  , iYColumnNumber ) ;
};

CdDcdZone	CWndDcdGrid::getXColumnBorderZone( 
			int iXColumnNumber ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getXColumnBorderZone( 
			 &aCDcdTarget  , iXColumnNumber ) ;
};

CdDcdZoneXy	CWndDcdGrid::getCellZone( 
		int iXColumnNumber , int iYColumnNumber ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getCellZone( 
			&aCDcdTarget  , iXColumnNumber , iYColumnNumber ) ;
};
	

int CWndDcdGrid::getYColumnNumberOfPos( 
		int iPos , bool* pbIsBorder ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getYColumnNumberOfPos( 
			&aCDcdTarget  , iPos , pbIsBorder ) ;
};

int CWndDcdGrid::getXColumnNumberOfPos( 
		int iPos , bool* pbIsBorder ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getXColumnNumberOfPos( 
			&aCDcdTarget  , iPos , pbIsBorder ) ;
};


CDcdGridCell* CWndDcdGrid::getCellOfPos( 
		const CdDcdPosXy& aCdDcdPosXy ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getCellOfPos( 
			&aCDcdTarget  , aCdDcdPosXy ) ;
};

CdDcdSizeXy CWndDcdGrid::calcIncreaseOnOutsideDrag( const POINT& pos ) 
{
	CdDcdSizeXy	sizeFixafterColumnNumberIncrease ;

	CRect	rectClient ;
	GetClientRect( &rectClient ) ; 

	//	�t�H�[�J�X�Z���̗�ԍ�
	CdDcdPosXy	posFocusCellColumnNumber = getCFocus()->getFocusCellColumnNumber() ;

	//	X����
	if ( m_pCDcdGrid->getXFixColumnCount() <= posFocusCellColumnNumber.getX() &&
		posFocusCellColumnNumber.getX() < m_pCDcdGrid->getXColumnCount() )
	{
		//	�t�H�[�J�X�Z�����A�X�N���[���\��ɂ���

		//	[���ւ̃X�N���[�����\(FixColumnCount < FixafterColumnNumber)
		//	AND �}�E�X�J�[�\����X���W���AFixColumn���荶 ]
		//	�^�C�}�ł̉E�X�N���[��
		if ( m_pCDcdGrid->getXFixColumnCount() < m_pCDcdGrid->getXFixafterColumnNumber() )	//	���ւ̃X�N���[�����\
		{
			int iScrollColumnStartPos = rectClient.left ;
			if ( m_pCDcdGrid->getXFixColumnCount() > 0 )
			{
				CdDcdZone	aZone = getXColumnBorderZone( m_pCDcdGrid->getXFixColumnCount() - 1 ) ;
				if ( iScrollColumnStartPos < aZone.getEndPos() )
				{
					iScrollColumnStartPos = aZone.getEndPos() ;
				}
			}
			//	iScrollColumnStartPos = �X�N���[���\��̍�����X���W
			if ( pos.x < iScrollColumnStartPos )
			{
				//	���ւ́u�̈�O�h���b�O�X�N���[���v���K�v�ȏ�
				sizeFixafterColumnNumberIncrease.setX( -1 );
			}
		}
		//	[�E�ւ̃X�N���[�����\( FixafterColumnNumber < ColumnCount - 1 )
		//	AND �}�E�X�J�[�\����X���W���AGrid�E�܂��̓E�C���h�E�̃N���C�A���g���W���E ]
		//	�^�C�}�ł̍��X�N���[��
		if ( m_pCDcdGrid->getXFixafterColumnNumber() < m_pCDcdGrid->getXColumnCount() - 1 )	//	�E�ւ̃X�N���[�����\
		{
			int iScrollColumnEndPos = rectClient.right ;
			{
				CdDcdZone	aZone = getXColumnBorderZone( m_pCDcdGrid->getXColumnCount() - 1 ) ;
				if ( iScrollColumnEndPos > aZone.getPos() ) 
				{
					iScrollColumnEndPos = aZone.getPos() ;
				}
			}
			if ( iScrollColumnEndPos < pos.x )
			{
				//	�E�ւ́u�̈�O�h���b�O�X�N���[���v���K�v�ȏ�
				sizeFixafterColumnNumberIncrease.setX( +1 );
			}
		}
	}

	//	Y����
	if ( m_pCDcdGrid->getYFixColumnCount() <= posFocusCellColumnNumber.getY() &&
		posFocusCellColumnNumber.getY() < m_pCDcdGrid->getYColumnCount() )
	{
		//	�t�H�[�J�X�Z�����A�X�N���[���\��ɂ���

		//	[��ւ̃X�N���[�����\(FixColumnCount < FixafterColumnNumber)
		//	AND �}�E�X�J�[�\����Y���W���AFixColumn����� ]
		//	�^�C�}�ł̉E�X�N���[��
		if ( m_pCDcdGrid->getYFixColumnCount() < m_pCDcdGrid->getYFixafterColumnNumber() )	//	���ւ̃X�N���[�����\
		{
			int iScrollColumnStartPos = rectClient.top ;
			if ( m_pCDcdGrid->getYFixColumnCount() > 0 )
			{
				CdDcdZone	aZone = getYColumnBorderZone( m_pCDcdGrid->getYFixColumnCount() - 1 ) ;
				if ( iScrollColumnStartPos < aZone.getEndPos() )
				{
					iScrollColumnStartPos = aZone.getEndPos() ;
				}
			}
			//	iScrollColumnStartPos = �X�N���[���\��̏㑤��Y���W
			if ( pos.y < iScrollColumnStartPos )
			{
				//	��ւ́u�̈�O�h���b�O�X�N���[���v���K�v�ȏ�
				sizeFixafterColumnNumberIncrease.setY( -1 );
			}
		}
		//	[�E�ւ̃X�N���[�����\( FixafterColumnNumber < ColumnCount - 1 )
		//	AND �}�E�X�J�[�\����Y���W���AColumn��艺�A�܂��̓E�C���h�E��艺 ]
		//	�^�C�}�ł̍��X�N���[��
		if ( m_pCDcdGrid->getYFixafterColumnNumber() < m_pCDcdGrid->getYColumnCount() - 1 )	//	�E�ւ̃X�N���[�����\
		{
			int iScrollColumnEndPos = rectClient.bottom ;
			{
				CdDcdZone	aZone = getYColumnBorderZone( m_pCDcdGrid->getYColumnCount() - 1 ) ;
				if ( iScrollColumnEndPos > aZone.getPos() ) 
				{
					iScrollColumnEndPos = aZone.getPos() ;
				}
			}
			//	iScrollColumnStartPos = �X�N���[���\��̏㑤��Y���W
			if ( iScrollColumnEndPos < pos.y )
			{
				//	���ւ́u�̈�O�h���b�O�X�N���[���v���K�v�ȏ�
				sizeFixafterColumnNumberIncrease.setY( +1 );
			}
		}
	}

	return sizeFixafterColumnNumberIncrease ;
}
	// ********************************
	//	@name	�Z���̌���
	// ********************************
CdDcdZone	CWndDcdGrid::getYColumnZoneOverlap( 
			int iYColumnNumber ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getYColumnZoneOverlap( 
			&aCDcdTarget  , iYColumnNumber ) ;
}
CdDcdZone	CWndDcdGrid::getXColumnZoneOverlap( 
			int iXColumnNumber ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getXColumnZoneOverlap( 
			&aCDcdTarget  , iXColumnNumber ) ;
}

CdDcdZoneXy	CWndDcdGrid::getCellZoneOverlap( 
		int iXColumnNumber , int iYColumnNumber ) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	return m_pCDcdGrid->getCellZoneOverlap( 
		&aCDcdTarget  , iXColumnNumber , iYColumnNumber ) ;
}
// ********************************
//	@name	����
// ********************************

// ********************************
//	CWndDcdGrid
// ********************************
	// --------------------------------
	//@name	�C�x���g�����̂��߂̉��z�֐�
	// --------------------------------
void CWndDcdGrid::OnSetFocusCell( CDcdGridCell* pcdcdgridcell ) 
{
	if ( pcdcdgridcell!= NULL ){
		LogMsg( "onsetfocuscell( x=%d y=%d )" , 
			m_pCDcdGrid->getXColumnNumberOfCell( pcdcdgridcell ) ,
			m_pCDcdGrid->getYColumnNumberOfCell( pcdcdgridcell ) ) ;
	}	else	{
		LogMsg( "onsetfocuscell( null )" ) ;
	}
}
void CWndDcdGrid::OnSetXFixafterColumnNumber( int iFixafterColumnNumber ) 
{
	LogMsg( "CWndDcdGrid::OnSetXFixafterColumnNumber(%d)" , 
		iFixafterColumnNumber ) ;
}
void CWndDcdGrid::OnSetYFixafterColumnNumber( int iFixafterColumnNumber ) 
{
	LogMsg( "CWndDcdGrid::OnSetYFixafterColumnNumber(%d)" , 
		iFixafterColumnNumber ) ;
}

void CWndDcdGrid::OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected )
{
	//LogMsg( "CWndDcdGrid::OnChangeSelectCell(%d,%d,%d)" , 
	//	iXColumnNumber , iYColumnNumber , bIsSelected ) ;
}

	// ********************************
	//@name �֘A
	// ********************************

	// ********************************
	//@name ���
	// ********************************
CXDcdGrid*	CWndDcdGrid::getCXDcdGrid() 
{
	return m_pCDcdGrid ;
}
CFocus*	CWndDcdGrid::getCFocus() 
{
	return m_pCFocus ;
}

CSelect*	CWndDcdGrid::getCSelect() 
{
	return m_pCSelect ;
}

CBoxSelect*	CWndDcdGrid::getCBoxSelect() 
{
	return m_pCBoxSelect ;
}
CRandomSelect*	CWndDcdGrid::getCRandomSelect() 
{
	return m_pCRandomSelect ;
}

	// ********************************
	//@name	�\�z
	// ********************************
BOOL CWndDcdGrid::Create( 
	const RECT& rect, CWnd* pParentWnd, UINT nID )
{
	return CreateEx( 0 
		, AfxRegisterWndClass( CS_DBLCLKS //| CS_HREDRAW | CS_VREDRAW 
			, LoadCursor( NULL , IDC_ARROW ) 
			, (HBRUSH)GetStockObject( WHITE_BRUSH ) 
			, NULL ) 
		, "CWndDcdGrid"	//	���̕����񂪕\������邱�Ƃ͂���܂���
		, WS_CHILD | WS_VSCROLL | WS_HSCROLL | WS_TABSTOP
		, rect
		, pParentWnd
		, nID
		, NULL ) ;
}

BOOL CWndDcdGrid::Create( CWnd* pParentWnd, UINT nID )
{
	return CreateEx( 0 
		, AfxRegisterWndClass( CS_DBLCLKS //| CS_HREDRAW | CS_VREDRAW 
			, LoadCursor( NULL , IDC_ARROW ) 
			, (HBRUSH)GetStockObject( WHITE_BRUSH ) 
			, NULL ) 
		, "CWndDcdGrid"	//	���̕����񂪕\������邱�Ƃ͂���܂���
		, WS_CHILD | WS_VSCROLL | WS_HSCROLL | WS_TABSTOP
		, CRect( 0 , 0 , 0 , 0 ) 
		, pParentWnd
		, nID
		, NULL ) ;
}

	// ********************************
	//@name CWndDcdGrid-����
	// ********************************

bool CWndDcdGrid::isShiftPressed()
{
	SHORT	iVal = GetKeyState( VK_SHIFT ) ;
	return ( ( iVal & 0x8000 ) != 0 ) ;
}
bool CWndDcdGrid::isCtrlPressed()
{
	SHORT	iVal = GetKeyState( VK_CONTROL ) ;
	return ( ( iVal & 0x8000 ) != 0 ) ;
}

void CWndDcdGrid::selectAll() 
{
	m_pCBoxSelect->clearSelect() ;
	m_pCSelect->selectAll() ;
}


void CWndDcdGrid::clearSelect() 
{
	m_pCBoxSelect->clearSelect() ;
	m_pCSelect->clearSelect() ;
}

	// ********************************
	//@name CWndDcdGrid-�E�C���h�E�X�V
	// ********************************
int  CWndDcdGrid::InvalidateXColumnBorder( int iXColumnNumber , 
	bool bErase ) 
{
	int iRv = 0 ;

	// --------------------------------
	//	�ĕ`��̈�����߂�
	// --------------------------------
	CRect	rectClient ;
	CdDcdZone	zoneClient ;
	if ( iRv >= 0 ){
		GetClientRect( &rectClient ) ;
		zoneClient.setPos( rectClient.left ).setSize( rectClient.right - rectClient.left ) ;
	}
	//rectClient = �N���C�A���g�̈�̋�`
	//zoneClient = �N���C�A���g�̈�̕�

	CdDcdZone	zoneInvalidate ;
	if ( iRv >= 0 ){
		CdDcdZone	zoneBorder = getXColumnBorderZone( iXColumnNumber ) ;
		zoneInvalidate = zoneBorder.CrossZone( zoneClient ) ;
	}
	//zoneInvalidate = �N���C�A���g�̈撆�ŁA���E���̈�
	
	// --------------------------------
	//	�ĕ`��
	// --------------------------------
	if ( iRv >= 0 ){
		if ( zoneInvalidate.getSize() > 0 ){
			CRect	rectInvalidate = rectClient ;
			rectInvalidate.left = zoneInvalidate.getPos() ;
			rectInvalidate.right = zoneInvalidate.getEndPos() ;
			InvalidateRect( rectInvalidate , bErase ) ;
			iRv = 1 ;
		}
	}	
	

	return ( iRv ) ;
	
}

int CWndDcdGrid::InvalidateYColumnBorder( int iYColumnNumber ,
	bool bErase ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	�ĕ`��̈�����߂�
	// --------------------------------
	CRect	rectClient ;
	CdDcdZone	zoneClient ;
	if ( iRv >= 0 ){
		GetClientRect( &rectClient ) ;
		zoneClient.setPos( rectClient.top ).setSize( rectClient.bottom - rectClient.top ) ;
	}
	//rectClient = �N���C�A���g�̈�̋�`
	//zoneClient = �N���C�A���g�̈�̕�

	CdDcdZone	zoneInvalidate ;
	if ( iRv >= 0 ){
		CdDcdZone	zoneBorder = getYColumnBorderZone( iYColumnNumber ) ;
		zoneInvalidate = zoneBorder.CrossZone( zoneClient ) ;
	}
	//zoneInvalidate = �N���C�A���g�̈撆�ŁA���E���̈�
	
	// --------------------------------
	//	�ĕ`��
	// --------------------------------
	if ( iRv >= 0 ){
		if ( zoneInvalidate.getSize() > 0 ){
			CRect	rectInvalidate = rectClient ;
			rectInvalidate.top = zoneInvalidate.getPos() ;
			rectInvalidate.bottom = zoneInvalidate.getEndPos() ;
			InvalidateRect( rectInvalidate , bErase ) ;
			iRv = 1 ;
		}
	}	
	

	return ( iRv ) ;
}

int CWndDcdGrid::InvalidateCell( int iXColumnNumber , int iYColumnNumber , 
	bool bErase ) 
{
	int iRv = 0 ;
	// --------------------------------
	//	�ĕ`��̈�����߂�
	// --------------------------------
	CRect	rectClient ;
	CdDcdZoneXy	zoneClient ;
	if ( iRv >= 0 ){
		GetClientRect( &rectClient ) ;
		zoneClient.setX( CdDcdZone( rectClient.left , rectClient.right - rectClient.left ) )
			.setY( CdDcdZone( rectClient.top , rectClient.bottom - rectClient.top ) ) ;
	}
	//rectClient = �N���C�A���g�̈�̋�`
	//zoneClient = �N���C�A���g�̈�̕�

	CdDcdZoneXy	zoneInvalidate ;
	if ( iRv >= 0 ){
		CdDcdZoneXy	zoneCell = getCellZone( iXColumnNumber , iYColumnNumber ) ;
		zoneInvalidate = zoneCell.CrossZone( zoneClient ) ;
	}
	//zoneInvalidate = �N���C�A���g�̈撆�ŁA���E���̈�
	
	// --------------------------------
	//	�ĕ`��
	// --------------------------------
	if ( iRv >= 0 ){
		if ( zoneInvalidate.getX().getSize() > 0 && 
				zoneInvalidate.getY().getSize() > 0 ){
			CRect	rectInvalidate = rectClient ;
			rectInvalidate.left = zoneInvalidate.getX().getPos() ;
			rectInvalidate.right = zoneInvalidate.getX().getEndPos() ;
			rectInvalidate.top = zoneInvalidate.getY().getPos() ;
			rectInvalidate.bottom = zoneInvalidate.getY().getEndPos() ;
			InvalidateRect( rectInvalidate , bErase ) ;
			iRv = 1 ;
		}
	}	
	
	return ( iRv ) ;
}

 void CWndDcdGrid::InvalidateGrid( 
		bool bErase )
{
	m_pCDcdGrid->InvalidateGrid( bErase ) ;
	m_pCFocus->InvalidateGrid() ;
	m_pCSelect->InvalidateGrid() ;
	m_pCBoxSelect->InvalidateGrid() ;
	m_pCRandomSelect->InvalidateGrid() ;
	
	super::Invalidate( bErase ) ;

	//	�S�̂̑������X�V
	update() ;
 }

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
BEGIN_MESSAGE_MAP(CWndDcdGrid, CWnd)
	//{{AFX_MSG_MAP(CWndDcdGrid)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CWndDcdGrid ���b�Z�[�W �n���h��

void CWndDcdGrid::OnPaint() 
{
	// --------------------------------
	//	�`��
	// --------------------------------
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
		
		CDcdTargetOnPaint	aCDcdTarget( GetSafeHwnd() , &dc.m_ps ) ;
		
		{
			CdDcdZoneXy	aDrawableZone = aCDcdTarget.getDrawableZone() ;
			//LogMsgL( 3 , "CWndDcdGrid::OnPaint() x=%d,%d y=%d,%d" ,
			//	aDrawableZone.getX().getPos() , 
			//	aDrawableZone.getX().getSize() , 
			//	aDrawableZone.getY().getPos() , 
			//	aDrawableZone.getY().getSize() ) ;
		}
		// --------------------------------	
		//	Grid
		// --------------------------------	
		m_pCDcdGrid->DcDraw( &aCDcdTarget );
		
		// --------------------------------	
		//	�t�H�[�J�X�}�[�N
		// --------------------------------	
		m_pCFocus->OnPaint(  &aCDcdTarget ) ;

		// --------------------------------	
		//	�I���}�[�N
		// --------------------------------	
		m_pCSelect->OnPaint(  &aCDcdTarget ) ;


		// --------------------------------	
		//	BoxSelect
		// --------------------------------	
		m_pCBoxSelect->OnPaint(  &aCDcdTarget ) ;
		
		// --------------------------------	
		//	RandomSelect
		// --------------------------------	
		m_pCRandomSelect->OnPaint(  &aCDcdTarget ) ;


	}
}


void CWndDcdGrid::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	
	SCROLLINFO	aSCROLLINFO ;
	memset ( &aSCROLLINFO , 0 , sizeof(aSCROLLINFO) ) ;
	aSCROLLINFO.cbSize = sizeof(aSCROLLINFO) ;
	aSCROLLINFO.fMask = SIF_ALL ;
	GetScrollInfo( SB_HORZ , &aSCROLLINFO , SIF_ALL ) ;
	
	if ( pScrollBar == NULL )
	{
		switch( nSBCode )
		{
		 case SB_LINELEFT:
			{
				{
					//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setXFixafterColumnNumber( m_pCDcdGrid->getXFixafterColumnNumber() - 1 ) ;
				}
			}
			break ; 
		 case SB_LINERIGHT:
			{
				{
					//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setXFixafterColumnNumber( m_pCDcdGrid->getXFixafterColumnNumber() + 1 ) ;
				}
			}
			break ; 
		 case SB_PAGELEFT:
			{
				int iFixafterColumnNumber = m_pCDcdGrid->getXFixafterColumnNumber() ;
				int iFixafterColumnNumberNew = m_pCDcdGrid->
					calcXFixafterColumnNumberPagemove( &aCDcdTarget , 
						iFixafterColumnNumber , false ) ;

				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setXFixafterColumnNumber( iFixafterColumnNumberNew ) ;
				}
			}
			break ;
		 case SB_PAGERIGHT:
			{
				int iFixafterColumnNumber = m_pCDcdGrid->getXFixafterColumnNumber() ;
				int iFixafterColumnNumberNew = m_pCDcdGrid->
					calcXFixafterColumnNumberPagemove( &aCDcdTarget , 
						iFixafterColumnNumber , true ) ;

				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setXFixafterColumnNumber( iFixafterColumnNumberNew ) ;
				}
			}
			break ;
		 case SB_THUMBPOSITION :
			{
				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setXFixafterColumnNumber( nPos ) ;
				}
			}
			break ;
		 case SB_THUMBTRACK :
			{
				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setXFixafterColumnNumber( nPos ) ;
				}
			}
			break ;
		 case SB_ENDSCROLL:
			{
			}
			break ;
		}
	}
	else
	{
		super::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}	

void CWndDcdGrid::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;
	
	SCROLLINFO	aSCROLLINFO ;
	memset ( &aSCROLLINFO , 0 , sizeof(aSCROLLINFO) ) ;
	aSCROLLINFO.cbSize = sizeof(aSCROLLINFO) ;
	aSCROLLINFO.fMask = SIF_ALL ;
	GetScrollInfo( SB_VERT , &aSCROLLINFO , SIF_ALL ) ;
	
	if ( pScrollBar == NULL )
	{
		switch( nSBCode )
		{
		 case SB_LINEUP:
			{
				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setYFixafterColumnNumber( m_pCDcdGrid->getYFixafterColumnNumber() - 1 ) ;
				}
			}
			break ; 
		 case SB_LINEDOWN:
			{
				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setYFixafterColumnNumber( m_pCDcdGrid->getYFixafterColumnNumber() + 1 ) ;
				}
			}
			break ; 
		 case SB_PAGEUP:
			{
				int iFixafterColumnNumber = m_pCDcdGrid->getYFixafterColumnNumber() ;
				int iFixafterColumnNumberNew = m_pCDcdGrid->
					calcYFixafterColumnNumberPagemove( &aCDcdTarget , 
						iFixafterColumnNumber , false ) ;
				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setYFixafterColumnNumber( iFixafterColumnNumberNew ) ;
				}
			}
			break ;
		 case SB_PAGEDOWN:
			{
				int iFixafterColumnNumber = m_pCDcdGrid->getYFixafterColumnNumber() ;
				int iFixafterColumnNumberNew = m_pCDcdGrid->
					calcYFixafterColumnNumberPagemove( &aCDcdTarget , 
						iFixafterColumnNumber , true ) ;
				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setYFixafterColumnNumber( iFixafterColumnNumberNew ) ;
				}
			}
			break ;
		 case SB_THUMBPOSITION :
			{
				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setYFixafterColumnNumber( nPos ) ;
				}
			}
			break ;
		 case SB_THUMBTRACK :
			{
				//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
				{
					Ou<CPropStack> pPropStack = createPropStackForScroll() ;

					m_pCDcdGrid->setYFixafterColumnNumber( nPos ) ;
				}
			}
			break ;
		 case SB_ENDSCROLL:
			{
			}
			break ;
		}
	}
	else
	{
		super::OnVScroll(nSBCode, nPos, pScrollBar);
	}
	
}

void CWndDcdGrid::OnSize(UINT nType, int cx, int cy) 
{
	
	if ( cx == 0 || cy == 0 )
	{
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
	super::OnSize(nType, cx, cy);

	//	�W��C���X�^���X�ɈϏ�
	m_pCFocus->OnSize( nType, cx, cy) ;
	m_pCSelect->OnSize( nType, cx, cy) ;
	m_pCBoxSelect->OnSize( nType, cx, cy);
	m_pCRandomSelect->OnSize( nType, cx, cy) ;
	

	//	�E�C���h�E�T�C�Y�ɂ��������āA�X�N���[���o�[�E�t�H�[�J�X���X�V
	{
		Ou<CPropStack> pPropStack = createPropStackForScroll() ;

		update() ;
	}

}

void CWndDcdGrid::OnSetFocus(CWnd* pOldWnd) 
{
	//	�W��C���X�^���X�ɈϏ�
	m_pCFocus->OnSetFocus( pOldWnd ) ;
	m_pCSelect->OnSetFocus( pOldWnd ) ;
	m_pCBoxSelect->OnSetFocus( pOldWnd );
	m_pCRandomSelect->OnSetFocus( pOldWnd ) ;

	super::OnSetFocus(pOldWnd);
}

void CWndDcdGrid::OnKillFocus(CWnd* pNewWnd) 
{
	//(3.1)�E�C���h�E�t�H�[�J�X���������ꍇ�́A�}�E�X�L���v�`��OFF
	//	�}�E�X�̃L���v�`�����
	ReleaseCapture() ;

	//	�u�̈�O�h���b�O�X�N���[���v�^�C�}��������܂��B
	if ( m_bOutsideDrag_TimerOn )
	{
		KillTimer( OutsideDrag_TIMERID ) ;
		m_bOutsideDrag_TimerOn = false ;
	}

	//	�t�H�[�J�X���������Ƃ��ɂ́A
	//	���{�^�����������������B
	m_bLButtonIsDown = false ;

	//	�W��C���X�^���X�ɈϏ�
	m_pCRandomSelect->OnKillFocus( pNewWnd )  ;
	m_pCBoxSelect->OnKillFocus( pNewWnd ) ;
	m_pCSelect->OnKillFocus( pNewWnd ) ;
	m_pCFocus->OnKillFocus( pNewWnd ) ;

	super::OnKillFocus(pNewWnd);
}

void CWndDcdGrid::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//	���{�^����������
	m_bLButtonIsDown = true ;
	m_posxyCursorPosOnLButtonDown = CdDcdPosXy( point.x , point.y ) ;

	//(4.1)�}�E�X���{�^����������(LButtonDown)
	//�@�}�E�X�̃L���v�`��ON
	//	�t�H�[�J�X���ړ�
	if ( m_bLButtonIsDown )	//   �}�E�X�̍��{�^����������Ă���ꍇ�ɐݒ肵�܂��B
	{
		//	�t�H�[�J�X�Z�����J�[�\���ʒu�Ɉړ�
		CDcdGridCell*	pCell = getCellOfPos( CdDcdPosXy( point.x , point.y ) ) ;
		if ( pCell != NULL )
		{
			//	�}�E�X�J�[�\���́A�ǂ����̃Z���̏�ɂ���܂��B
			//	��������O���b�h�̊O�Ƀ}�E�X���h���b�O���ꂽ�Ƃ��ɁA
			//	�u�̈�O�h���b�O�X�N���[���v���N�����܂��B

			//�@�E�C���h�E�̃t�H�[�J�X���ړ�
			SetFocus() ;

			//�@�t�H�[�J�X�Z�����ړ�
			{
				Ou<CPropStack> pPropStack = createPropStackForMovingFocusCell() ;

				m_pCFocus->setFocusCell( pCell ) ;
			}


			//�@�}�E�X�̃L���v�`��ON
			SetCapture() ;

			//	�u�̈�O�h���b�O�X�N���[���v�̃^�C�}�[ON
			SetTimer( OutsideDrag_TIMERID , m_iOutsideDrag_TimeMs , NULL ) ;
			m_bOutsideDrag_TimerOn = true ;
		}
	}

	//	�W��C���X�^���X�ɈϏ�
	//m_pCFocus->OnLButtonDown(nFlags, point) ;
	//m_pCSelect->OnLButtonDown(nFlags, point) ;
	//m_pCBoxSelect->OnLButtonDown(nFlags, point) ;
	m_pCRandomSelect->OnLButtonDown(nFlags, point)  ;
	
	super::OnLButtonDown(nFlags, point);
}
void CWndDcdGrid::OnLButtonUp(UINT nFlags, CPoint point)
{
	//((4.2)�}�E�X���{�^�����(LButtonUp)
	//	�}�E�X�̃L���v�`�����
	ReleaseCapture() ;

	//	�u�̈�O�h���b�O�X�N���[���v�^�C�}��������܂��B
	if ( m_bOutsideDrag_TimerOn )
	{
		KillTimer( OutsideDrag_TIMERID ) ;
		m_bOutsideDrag_TimerOn = false ;
	}

	//	���{�^�����������������B
	m_bLButtonIsDown = false ;

	//	�W��C���X�^���X�ɈϏ�
	//m_pCFocus->OnLButtonUp(nFlags, point) ;
	//m_pCSelect->OnLButtonUp(nFlags, point) ;
	//m_pCBoxSelect->OnLButtonUp(nFlags, point) ;
	m_pCRandomSelect->OnLButtonUp(nFlags, point)  ;

	CWnd::OnLButtonUp(nFlags, point);
}

void CWndDcdGrid::OnMouseMove(UINT nFlags, CPoint point)
{
	//(4.1)�}�E�X���{�^����������(LButtonDown)
	//�@�}�E�X�̃L���v�`��ON
	//	�J�[�\����Grid���ɂ���΁A
	//	�t�H�[�J�X�Z�����J�[�\���ʒu�Ɉړ�
	if ( m_bLButtonIsDown )	//   �}�E�X�̍��{�^����������Ă���ꍇ�ɐݒ肵�܂��B
	{

		//	�J�[�\�����u�̈�O�h���b�O�X�N���[���v��
		//	�K�v�Ȉʒu�ɂ��邩�ۂ��𒲂ׂ܂��B
		CdDcdSizeXy	sizeFixafterColumnNumberIncrease = 
			calcIncreaseOnOutsideDrag( point ) ;
		if ( sizeFixafterColumnNumberIncrease.getX() != 0 ||
			sizeFixafterColumnNumberIncrease.getY() != 0 )
		{
			//	�u�̈�O�h���b�O�X�N���[���v��
			//	�K�v�ȏꍇ�́A�t�H�[�J�X�̈ړ��͍s���܂���
			//	(OnTimer()�ŁA�t�H�[�J�X�̈ړ����s���܂�)
		}
		else
		{
			CRect rectClient ;
			GetClientRect( &rectClient ) ;
			if ( rectClient.left <= point.x && point.x < rectClient.right && 
				rectClient.top <= point.y && point.y < rectClient.bottom )
			{
				//	�}�E�X���N���C�A���g�̈���Ȃ�A
				//	�t�H�[�J�X�Z�����J�[�\���ʒu�Ɉړ�
				CDcdGridCell*	pCell = getCellOfPos( CdDcdPosXy( point.x , point.y ) ) ;
				if ( pCell != NULL )
				{
					//�@�t�H�[�J�X�Z�����ړ�
					{
						//	�X�N���[���ʒu���X�V���܂��B
						//	�A���J�[�Z���́A�ێ����܂�
						Ou<CPropStack> pPropStack = createPropStackForMovingFocusCell() ;

						m_pCFocus->setFocusCell( pCell ) ;
					}
				}
			}
		}
	}
	//	�W��C���X�^���X�ɈϏ�
	//m_pCFocus->OnMouseMove(nFlags, point)) ;
	//m_pCSelect->OnMouseMove(nFlags, point) ;
	//m_pCBoxSelect->OnMouseMove(nFlags, point) ;
	m_pCRandomSelect->OnMouseMove(nFlags, point)  ;

	CWnd::OnMouseMove(nFlags, point);
}

void CWndDcdGrid::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CDcdTargetGetDC	aCDcdTarget( GetSafeHwnd() ) ;

	switch( nChar ){
	 case VK_LEFT :	
		{
			CDcdGridCell*	pCell = m_pCDcdGrid->calcMovedCell( 
				m_pCFocus->getFocusCell() , -1 , 0 ) ;
			//�@�t�H�[�J�X�Z�����ړ�
			{
				Ou<CPropStack> pPropStack = createPropStackForMovingFocusCell() ;

				m_pCFocus->setFocusCell( pCell ) ;
				
			}
		}
		break ;
	 case VK_RIGHT :	
		{
			CDcdGridCell*	pCell = m_pCDcdGrid->calcMovedCell( 
				m_pCFocus->getFocusCell() , +1 , 0 ) ;
			//�@�t�H�[�J�X�Z�����ړ�
			{
				Ou<CPropStack> pPropStack = createPropStackForMovingFocusCell() ;

				m_pCFocus->setFocusCell( pCell ) ;
			}
		}
		break ;
	 case VK_UP :	
		{
			CDcdGridCell*	pCell = m_pCDcdGrid->calcMovedCell( 
				m_pCFocus->getFocusCell() , 0 , -1 ) ;
			//�@�t�H�[�J�X�Z�����ړ�
			{
				Ou<CPropStack> pPropStack = createPropStackForMovingFocusCell() ;

				m_pCFocus->setFocusCell( pCell ) ;
			}
		}
		break ;
	 case VK_DOWN :	
		{
			CDcdGridCell*	pCell = m_pCDcdGrid->calcMovedCell( 
				m_pCFocus->getFocusCell() , 0 , +1 ) ;
			//�@�t�H�[�J�X�Z�����ړ�
			{
				Ou<CPropStack> pPropStack = createPropStackForMovingFocusCell() ;

				m_pCFocus->setFocusCell( pCell ) ;
			}
		}
		break ;
	 case VK_PRIOR ://PageUp	
		{
			//	VK_SHIFT ��������Ă��܂���B
			//	Y ������ PageUP�ł�
			int iFixafterColumnNumber = m_pCDcdGrid->getYFixafterColumnNumber() ;
			int iFixafterColumnNumberNew = m_pCDcdGrid->
				calcYFixafterColumnNumberPagemove( &aCDcdTarget , 
					iFixafterColumnNumber , false ) ;

			//setYFixafterColumnNumber( iFixafterColumnNumberNew ) ;

			//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
			{
				Ou<CPropStack> pPropStack = createPropStackForScroll() ;

				m_pCDcdGrid->setYFixafterColumnNumber( iFixafterColumnNumberNew ) ;
			}
			
		}
		break ;
	 case VK_NEXT :	//PageDown	
		{
			//	Y ������ PageDown�ł�
			int iFixafterColumnNumber = m_pCDcdGrid->getYFixafterColumnNumber() ;
			int iFixafterColumnNumberNew = m_pCDcdGrid->
				calcYFixafterColumnNumberPagemove( &aCDcdTarget , 
					iFixafterColumnNumber , true ) ;
			//setYFixafterColumnNumber( iFixafterColumnNumberNew ) ;
			
			//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
			{
				Ou<CPropStack> pPropStack = createPropStackForScroll() ;

				m_pCDcdGrid->setYFixafterColumnNumber( iFixafterColumnNumberNew ) ;
			}
		}
		break ;
	 case VK_HOME :
		{
			//	VK_SHIFT ��������Ă��܂��B
			//	X ������ PageUP�ł�

			int iFixafterColumnNumber = m_pCDcdGrid->getXFixafterColumnNumber() ;
			int iFixafterColumnNumberNew = m_pCDcdGrid->
				calcXFixafterColumnNumberPagemove( &aCDcdTarget , 
					iFixafterColumnNumber , false ) ;

			//setXFixafterColumnNumber( iFixafterColumnNumberNew ) ;

			//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
			{
				Ou<CPropStack> pPropStack = createPropStackForScroll() ;

				m_pCDcdGrid->setXFixafterColumnNumber( iFixafterColumnNumberNew ) ;
			}
		}
		break ;
	 case VK_END :
		{
			//	VK_SHIFT ��������Ă��܂��B
			//	X ������ PageDown�ł�
			int iFixafterColumnNumber = m_pCDcdGrid->getXFixafterColumnNumber() ;
			int iFixafterColumnNumberNew = m_pCDcdGrid->
				calcXFixafterColumnNumberPagemove( &aCDcdTarget , 
					iFixafterColumnNumber , true ) ;
			//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
			{
				Ou<CPropStack> pPropStack = createPropStackForScroll() ;

				m_pCDcdGrid->setXFixafterColumnNumber( iFixafterColumnNumberNew ) ;
			}			
		}
		break ;

	 default:
		{
			//	�W��C���X�^���X�ɈϏ�
			//m_pCFocus->OnKeyDown(nChar, nRepCnt, nFlags) ;
			//m_pCSelect->OnKeyDown(nChar, nRepCnt, nFlags);
			//m_pCBoxSelect->OnKeyDown(nChar, nRepCnt, nFlags) ;
			m_pCRandomSelect->OnKeyDown(nChar, nRepCnt, nFlags) ;

			super::OnKeyDown(nChar, nRepCnt, nFlags);
		}
	}

	
}

int CWndDcdGrid::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	return 0;
}

void CWndDcdGrid::OnDestroy() 
{
	CWnd::OnDestroy();
}


BOOL CWndDcdGrid::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	if ( nFlags == 0 )
	{
		int iYMove = zDelta / (-WHEEL_DELTA) ;
		//iYMove = Y�����Ɉړ����鐔�B

		//	�X�N���[���̕ύX(PageUp,PageDown,Home,End�L�[���܂�)
		{
			//	�X�N���[���ʒu�ɍ��킹�ăt�H�[�J�X�ʒu���X�V���܂��B
			//	�A���J�[�Z���́AShift��������Ă�����ێ����܂��B
			//	Shift��������Ă��Ȃ��ꍇ�͍X�V���܂��B
			Ou<CPropStack> pPropStack = createPropStackForScroll() ;

			m_pCDcdGrid->setYFixafterColumnNumber( m_pCDcdGrid->getYFixafterColumnNumber() + iYMove ) ;
		}

		return ( TRUE ) ;
	}	
	return super::OnMouseWheel(nFlags, zDelta, pt);
}



void CWndDcdGrid::OnTimer(UINT_PTR nIDEvent)
{
	//	�u�̈�O�h���b�O�X�N���[���v
	if ( nIDEvent == OutsideDrag_TIMERID )
	{
		CPoint	point ;
		GetCursorPos( &point ) ;
		ScreenToClient( &point ) ;

		//	�J�[�\�����u�̈�O�h���b�O�X�N���[���v��
		//	�K�v�Ȉʒu�ɂ��邩�ۂ��𒲂ׂ܂��B
		CdDcdSizeXy	sizeFixafterColumnNumberIncrease = 
			calcIncreaseOnOutsideDrag( point ) ;
		if ( sizeFixafterColumnNumberIncrease.getX() != 0 ||
			sizeFixafterColumnNumberIncrease.getY() != 0 )
		{
			//	�u�̈�O�h���b�O�X�N���[���v��
			//	�K�v�ȏꍇ�́A�X�N���[�����s���܂��B

			// --------------------------------
			//	�t�H�[�J�X�Z�����ړ���������@
			// --------------------------------
			//memo:
			//	�^�C�}��FixafterColumnNumber��ω���������@�ł́A
			//	�t�H�[�J�X�Z�����Ǐ]���Ȃ����߁A
			//	�s���R�ȓ����ɂȂ�܂��B
			//	���̂��߁A�^�C�}�Ńt�H�[�J�X�Z����
			//	�ړ������邱�Ƃɂ��܂����B
			CDcdGridCell*	pCell = m_pCFocus->getFocusCell() ;
			if ( pCell != NULL )
			{
				pCell = m_pCDcdGrid->calcMovedCell( pCell , 
					sizeFixafterColumnNumberIncrease.getX() , 
					sizeFixafterColumnNumberIncrease.getY() ) ; 

				//	�t�H�[�J�X�Z���̈ړ�
				{
					//	�X�N���[���ʒu���X�V���܂��B
					//	�A���J�[�Z���́A�ێ����܂�(���̃^�C�}���L���ȏꍇ��
					//	�h���b�O���̂���)�B
					Ou<CPropStack> pPropStack = createPropStackForMovingFocusCell() ;

					m_pCFocus->setFocusCell( pCell ) ;
				}
			}
		}
	}
	else
	{
		CWnd::OnTimer(nIDEvent);
	}
}
void CWndDcdGrid::OnRButtonDown(UINT nFlags, CPoint point)
{

	//	�E�@�t�H�[�J�X�Z���ȊO�̃Z�����E�N���b�N�����ꍇ�́A
	//	�t�H�[�J�X�Z�����N���b�N���ꂽ�Z���Ɉړ�����B
	//	���̂Ƃ��A�Z���̕����I���͉�������B���̌�A�R���e�L�X�g���j���[��\������
	//	�E�@�t�H�[�J�X�Z�����E�N���b�N�����ꍇ�E�������̓Z���ȊO�̏ꏊ��
	//	�E�N���b�N�����ꍇ�́A�Z���̕����I�����ێ�����B���̌�A�R���e�L�X�g���j���[��\������
	//�y���R�z
	//	�Z���𕡐��I��������ԂŁA�t�H�[�J�X�Z���ȊO�̃Z�����E�N���b�N����ƁA
	//	�Z���������I�����ꂽ�܂܁A�R���e�L�X�g���j���[���\������Ă��܂��܂��B
	//	����́AMicrosoft Excel �Ȃǂ̈�ʓI�ȃ\�t�g�E�G�A�Ƃ͓��삪�قȂ�A�s�ւɊ����܂��B

	//	�E�{�^���������ꂽ�Ƃ��́A���̃E�C���h�E�ɖ����I��
	//	�t�H�[�J�X��ݒ肷��K�v������܂��B
	//
	//�y���R�z
	//	���̃E�C���h�E���J��������́A���̃E�C���h�E��
	//	�t�H�[�J�X�������Ă��܂���B
	//	�܂��A�E�C���h�E�͉E�{�^���������������ł́A
	//	�t�H�[�J�X�𓾂܂���B
	//	���̂��߁ACWndDcdGrid2::CFocus::m_bIsFocusmarkShowEvery ��
	//	false�̏ꍇ�́A�Z�����E�N���b�N�ł��A���̃Z���Ƀt�H�[�J�X�}�[�N���`�悳��܂���B
	SetFocus() ;

	{
		//	�}�E�X���N���C�A���g�̈���ŁA�t�H�[�J�X�Z���ȊO�̃Z���ɂ���Ȃ�A
		//	�t�H�[�J�X�Z�����J�[�\���ʒu�Ɉړ�
		CRect rectClient ;
		GetClientRect( &rectClient ) ;
		if ( rectClient.left <= point.x && point.x < rectClient.right && 
			rectClient.top <= point.y && point.y < rectClient.bottom )
		{
			CDcdGridCell*	pCell = getCellOfPos( CdDcdPosXy( point.x , point.y ) ) ;
			CDcdGridCell*	pCellFocus = getCFocus()->getFocusCell() ;
			if ( pCell != NULL && pCell != pCellFocus )
			{
				//	�`����œK��
				Ou<CPropStack> pPropStack = createPropStackForMovingFocusCell() ;

				//�t�H�[�J�X�Z�����J�[�\���ʒu�Ɉړ�
				m_pCFocus->setFocusCell( pCell ) ;
				

				//�Z���̑I������������
				m_pCBoxSelect->clearSelect() ;
				m_pCSelect->clearSelect() ;
			}
		}
	}
	CWnd::OnRButtonDown(nFlags, point);
}

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

