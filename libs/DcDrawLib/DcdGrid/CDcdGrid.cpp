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
//	CDcdGrid.cpp
// ****************************************************************
*/
#include <algorithm>
using namespace std ;
#include <assert.h>

#include "logmsg/LogMsg.h"
#include "NsOu/OuNew.h"

#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/CDcdLine.h"
#include "DcDraw/CDcdTextbox.h"
#include "DcDraw/CConverter_WinGdi.h"
#include "DcDraw/CaDcdTargetClip.h"
#include "CDcdGrid.h"

namespace DcDrawLib{
namespace DcdGrid{

// ****************************************************************
//	CDcdGrid
// ****************************************************************
// --------------------------------
//	�����֐�
// --------------------------------


 
int CDcdGrid::getYColumnsSize( IfDcdTarget* pIfDcdTarget ,
			int iYColumnNumberSrc , bool bSrcIsBorder ,
			int iYColumnNumberDst , bool bDstIsBorder) 
{
	int iRv = 0 ;
	if ( iYColumnNumberSrc == INT_MAX ){
		iYColumnNumberSrc = getYColumnCount() - 1 ;
	}
	if ( iYColumnNumberDst == INT_MAX ){
		iYColumnNumberDst = getYColumnCount() - 1 ;
	}
	
	int idx ;
	for ( idx = iYColumnNumberSrc ; idx <= iYColumnNumberDst ; idx ++ ){
		if ( !( idx == iYColumnNumberSrc && bSrcIsBorder ) )
		{
			CDcdGridYColumn*	pCDcdGridYColumn = getYColumn( idx ) ;
			//	�N�_���{�[�_�[�Ɏw�肳��Ă���ꍇ�́A
			//	�N�_�̗�̕��͊܂߂܂���B
			iRv += pCDcdGridYColumn->getColumnSize( pIfDcdTarget ) ;
		}
		if ( !( idx == iYColumnNumberDst && !bDstIsBorder ) ){
			if ( idx == -1 )
			{
				iRv += m_CDcdGridYBorderTop.getColumnBorderSize( pIfDcdTarget ) ;
			}
			else if ( idx == getYColumnCount() - 1 )
			{
				iRv += m_CDcdGridYBorderBottom.getColumnBorderSize( pIfDcdTarget ) ;
			}
			else
			{
				CDcdGridYBorder*	pCDcdGridYBorder= getYBorder( idx ) ;
				iRv += pCDcdGridYBorder->getColumnBorderSize( pIfDcdTarget ) ;
			}
		}
	}
	return ( iRv ) ;
}

int CDcdGrid::getXColumnsSize( IfDcdTarget* pIfDcdTarget ,
			int iXColumnNumberSrc , bool bSrcIsBorder ,
			int iXColumnNumberDst , bool bDstIsBorder) 
{
	int iRv = 0 ;
	if ( iXColumnNumberSrc == INT_MAX ){
		iXColumnNumberSrc = getXColumnCount() - 1 ;
	}
	if ( iXColumnNumberDst == INT_MAX ){
		iXColumnNumberDst = getXColumnCount() - 1 ;
	}
	
	int idx ;
	for ( idx = iXColumnNumberSrc ; idx <= iXColumnNumberDst ; idx ++ ){
		if ( !( idx == iXColumnNumberSrc && bSrcIsBorder ) )
		{
			CDcdGridXColumn*	pCDcdGridXColumn = getXColumn( idx ) ;
			//	�N�_���{�[�_�[�Ɏw�肳��Ă���ꍇ�́A
			//	�N�_�̗�̕��͊܂߂܂���B
			iRv += pCDcdGridXColumn->getColumnSize( pIfDcdTarget ) ;
		}
		if ( !( idx == iXColumnNumberDst && !bDstIsBorder ) ){
			//	�I�_���{�[�_�[�Ɏw�肳��Ă��Ȃ��ꍇ�́A
			//	�I�_�̗�̕��͊܂߂܂���B
			if ( idx == -1 )
			{
				iRv += m_CDcdGridXBorderTop.getColumnBorderSize( pIfDcdTarget ) ;
			}
			else if ( idx == getXColumnCount() - 1 )
			{
				iRv += m_CDcdGridXBorderBottom.getColumnBorderSize( pIfDcdTarget ) ;
			}
			else
			{
				CDcdGridXBorder*	pCDcdGridXBorder= getXBorder( idx ) ;
				iRv += pCDcdGridXBorder->getColumnBorderSize( pIfDcdTarget ) ;
			}
		}
	}
	return ( iRv ) ;
}

int CDcdGrid::insertYColumn_insertColumnCell( int iYColumnNumber ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iYColumnNumber == INT_MAX ){
			iYColumnNumber = getYColumnCount() ;
		}
		if ( !( 0 <= iYColumnNumber && iYColumnNumber <= getYColumnCount() ) ){
			iRv = -2 ;	//	�C���f�N�X���s���ł�	
		}
	}
	if ( iRv >= 0 )
	{
			CDcdGridYColumn* pCDcdGridYColumn = new CDcdGridYColumn( this ) ;
			m_CDcdGridYColumnCont.insert( 
				m_CDcdGridYColumnCont.begin() + iYColumnNumber , 
				pCDcdGridYColumn ) ; 
			
			OnCreateYColumn( iYColumnNumber , pCDcdGridYColumn ) ;
	}
	if ( iRv >= 0 ){
		//	Cell�I�u�W�F�N�g
		m_CDcdGridCellCont.insert( 
			m_CDcdGridCellCont.begin() + iYColumnNumber ,
			new CDcdGridYColumnCellCont ) ;
		int iXColumnNumber ;
		for ( iXColumnNumber = 0 ; 
				iXColumnNumber < getXColumnCount() ; 
				iXColumnNumber ++ ){
			CDcdGridCell*	pCDcdGridCell = new CDcdGridCell( this , m_CDcdGridCellCont[ iYColumnNumber ] ) ;
			
			m_CDcdGridCellCont[ iYColumnNumber ]->push_back( pCDcdGridCell );
		}
		for ( iXColumnNumber = 0 ; 
				iXColumnNumber < getXColumnCount() ; 
				iXColumnNumber ++ ){

			CDcdGridCell*	pCDcdGridCell = 
				(*m_CDcdGridCellCont[ iYColumnNumber ])[ iXColumnNumber ] ;
			OnCreateCell( iXColumnNumber , iYColumnNumber , 
				pCDcdGridCell ) ;
		}
		
	}
	return ( iRv ) ;
}
int CDcdGrid::insertXColumn_insertColumnCell( int iXColumnNumber ) 
{
	int	iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iXColumnNumber == INT_MAX ){
			iXColumnNumber = getXColumnCount() ;
		}
		if ( !( 0 <= iXColumnNumber && 
				iXColumnNumber <= getXColumnCount() ) ){
			iRv = -2 ;	//	�C���f�N�X���s���ł�	
		}
	}
	if ( iRv >= 0 )
	{
			CDcdGridXColumn* pCDcdGridXColumn = new CDcdGridXColumn( this ) ;
			m_CDcdGridXColumnCont.insert( 
				m_CDcdGridXColumnCont.begin() + iXColumnNumber , 
				pCDcdGridXColumn ) ; 
			
			OnCreateXColumn( iXColumnNumber , pCDcdGridXColumn ) ;
	}
	if ( iRv >= 0 ){
		int iYColumnNumber ;
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < getYColumnCount() ; 
				iYColumnNumber ++ ){
			CDcdGridCell*	pCDcdGridCell = new CDcdGridCell( this , m_CDcdGridCellCont[iYColumnNumber] ) ;
			m_CDcdGridCellCont[iYColumnNumber]->insert( 
				m_CDcdGridCellCont[iYColumnNumber]->begin() + iXColumnNumber ,
				pCDcdGridCell ) ;
			
		}
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < getYColumnCount() ; 
				iYColumnNumber ++ ){
			CDcdGridCell*	pCDcdGridCell = 
				(*m_CDcdGridCellCont[ iYColumnNumber ])[ iXColumnNumber ] ;
			OnCreateCell( iXColumnNumber , iYColumnNumber , 
				pCDcdGridCell ) ;
		}
	}
	return ( iRv ) ;
}
int CDcdGrid::eraseYColumn_eraseColumnCell( int iYColumnNumber ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iYColumnNumber == INT_MAX ){
			iYColumnNumber = getYColumnCount() - 1 ;
		}
		if ( !( 0 <= iYColumnNumber && 
				iYColumnNumber < getYColumnCount() ) ){
			iRv = -2 ;	//	�C���f�N�X���s���ł�	
		}
	}
	if ( iRv >= 0 ){
		int iXColumnNumber ;
		for ( iXColumnNumber = getXColumnCount() - 1  ; 
				iXColumnNumber >= 0  ; 
				iXColumnNumber -- ){
			CDcdGridCell*	pCDcdGridCell = 
				(*m_CDcdGridCellCont[ iYColumnNumber ])[iXColumnNumber] ;
			OnDeleteCell( iXColumnNumber , iYColumnNumber , 
				pCDcdGridCell ) ;

		}
		for ( iXColumnNumber = getXColumnCount() - 1  ; 
				iXColumnNumber >= 0  ; 
				iXColumnNumber -- ){
			CDcdGridCell*	pCDcdGridCell = 
				m_CDcdGridCellCont[ iYColumnNumber ]->back();
			
			m_CDcdGridCellCont[ iYColumnNumber ]->pop_back();
			
			delete pCDcdGridCell ;
			pCDcdGridCell = NULL ;
		}
		CDcdGridYColumnCellCont* pCDcdGridYColumnCellCont = m_CDcdGridCellCont[iYColumnNumber] ;
		delete pCDcdGridYColumnCellCont ;
		pCDcdGridYColumnCellCont = NULL ;

		m_CDcdGridCellCont.erase( 
			m_CDcdGridCellCont.begin() + iYColumnNumber ) ;
	}
	if ( iRv >= 0 ){
		{
			CDcdGridYColumn*	pCDcdGridYColumn = 
				m_CDcdGridYColumnCont[ iYColumnNumber ] ;
			
			OnDeleteYColumn( iYColumnNumber , pCDcdGridYColumn ) ;
			
			delete pCDcdGridYColumn ;
			m_CDcdGridYColumnCont.erase( 
				m_CDcdGridYColumnCont.begin() + iYColumnNumber ) ; 
		}
	}
	return ( iRv ) ;
}
int CDcdGrid::eraseXColumn_eraseColumnCell( int iXColumnNumber ) 
{
	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( iXColumnNumber == INT_MAX ){
			iXColumnNumber = getXColumnCount() - 1 ;
		}
		if ( !( 0 <= iXColumnNumber && 
				iXColumnNumber < getXColumnCount() ) ){
			iRv = -2 ;	//	�C���f�N�X���s���ł�	
		}
	}
	if ( iRv >= 0 ){
		int iYColumnNumber ;
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < getYColumnCount() ; 
				iYColumnNumber ++ ){
			CDcdGridCell*	pCDcdGridCell = 
				(*m_CDcdGridCellCont[iYColumnNumber])[iXColumnNumber] ;
			
			OnDeleteCell( iXColumnNumber , iYColumnNumber , 
				pCDcdGridCell ) ;
		}
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < getYColumnCount() ; 
				iYColumnNumber ++ ){
			CDcdGridCell*	pCDcdGridCell = 
				(*m_CDcdGridCellCont[iYColumnNumber])[iXColumnNumber] ;

			m_CDcdGridCellCont[iYColumnNumber]->erase( 
				m_CDcdGridCellCont[iYColumnNumber]->begin() + iXColumnNumber ) ;
			
			delete pCDcdGridCell ;
			pCDcdGridCell = NULL ;
		}
	}
	if ( iRv >= 0 ){
		{
			CDcdGridXColumn*	pCDcdGridXColumn = 
				m_CDcdGridXColumnCont[ iXColumnNumber ] ;
			
			OnDeleteXColumn( iXColumnNumber , pCDcdGridXColumn ) ;
			
			delete pCDcdGridXColumn ;
			m_CDcdGridXColumnCont.erase( 
				m_CDcdGridXColumnCont.begin() + iXColumnNumber ) ; 
		}
	}
	return ( iRv ) ;
}

 
void CDcdGrid::adjustProp() 
{
	// --------------------------------
	//	m_iXFixColumnCount
	//	m_iXFixafterColumnNumber
	//	m_iYFixColumnCount
	//	m_iYFixafterColumnNumber
	// --------------------------------
	if ( m_iXFixColumnCount > getXColumnCount() ){
		m_iXFixColumnCount = getXColumnCount() ;
	}
	// --------------------------------
	if ( m_iXFixafterColumnNumber > getXColumnCount() - 1 ){
		m_iXFixafterColumnNumber = getXColumnCount() - 1 ;
	}
	if ( m_iXFixafterColumnNumber < m_iXFixColumnCount ){
		m_iXFixafterColumnNumber = m_iXFixColumnCount ;
	}
	// --------------------------------
	if ( m_iYFixColumnCount > getYColumnCount() ){
		m_iYFixColumnCount = getYColumnCount() ;
	}
	// --------------------------------
	if ( m_iYFixafterColumnNumber > getYColumnCount() - 1 ){
		m_iYFixafterColumnNumber = getYColumnCount() - 1 ;
	}
	if ( m_iYFixafterColumnNumber < m_iYFixColumnCount ){
		m_iYFixafterColumnNumber = m_iYFixColumnCount ;
	}
	// --------------------------------
	//	�Z������
	//	CDcdGridCell::m_iXAttachCellCount
	//	CDcdGridCell::m_iYAttachCellCount
	// --------------------------------
	{
		int iYColumnNumber = 0 ;
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < getYColumnCount() ; 
				iYColumnNumber ++ ){
			int iXColumnNumber = 0 ;
			for ( iXColumnNumber = 0 ; 
					iXColumnNumber < getXColumnCount() ; 
					iXColumnNumber ++ ){
				CDcdGridCell*	pCell = 
					(*m_CDcdGridCellCont[iYColumnNumber])[iXColumnNumber] ;
				if ( pCell->m_iXAttachCellCount > 
						getXColumnCount() - iXColumnNumber ){
					pCell->m_iXAttachCellCount = 
						getXColumnCount() - iXColumnNumber ;
				}
				if ( pCell->m_iYAttachCellCount > 
						getYColumnCount() - iYColumnNumber ){
					pCell->m_iYAttachCellCount = 
						getYColumnCount() - iYColumnNumber ;
				}
			}
		}
	}
	// --------------------------------
	//	CDcdGridCell::m_pcellAttachTo
	// --------------------------------
	{
		//	��U�Am_pcellAttachTo �̓N���A���܂��B
		int iYColumnNumber = 0 ;
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < getYColumnCount() ; 
				iYColumnNumber ++ ){
			int iXColumnNumber = 0 ;
			for ( iXColumnNumber = 0 ; 
					iXColumnNumber < getXColumnCount() ; 
					iXColumnNumber ++ ){
				CDcdGridCell*	pCell = 
					(*m_CDcdGridCellCont[iYColumnNumber])[iXColumnNumber] ;
				pCell->m_pcellAttachTo = NULL ;
			}
		}
	}
	{
		//	���炽�߂āAm_pcellAttachTo ��ݒ肵�܂��B
		int iYColumnNumber = 0 ;
		for ( iYColumnNumber = 0 ; 
				iYColumnNumber < getYColumnCount() ; 
				iYColumnNumber ++ ){
			int iXColumnNumber = 0 ;
			for ( iXColumnNumber = 0 ; 
					iXColumnNumber < getXColumnCount() ; 
					iXColumnNumber ++ ){
				CDcdGridCell*	pCell = 
					(*m_CDcdGridCellCont[iYColumnNumber])[iXColumnNumber] ;
			
				if ( pCell->m_pcellAttachTo == NULL && 
					( pCell->m_iYAttachCellCount > 1 || 
						pCell->m_iXAttachCellCount > 1 )
				){
					int iYColumn ;
					for ( iYColumn = 0 ; 
							iYColumn <  pCell->m_iYAttachCellCount ; 
							iYColumn ++ )
					{
						int iXColumn ;
						for ( iXColumn = 0 ; 
								iXColumn <  pCell->m_iXAttachCellCount ; 
								iXColumn ++ ){
							if ( iYColumn > 0 || iXColumn > 0 )
							{
								CDcdGridCell*	pCellAttached = getCell( 
									iXColumnNumber + iXColumn , 
									iYColumnNumber + iYColumn ) ;
								pCellAttached->m_pcellAttachTo = pCell ;
							}
						}
					}
				}
			}
		}
	}
}

bool CDcdGrid::createZoneCache( 
			IfDcdTarget* pIfDcdTarget ) 
{
	if ( m_zonecontXColumnBorderZoneCache.size() != 0 ){
		return false ;
	}
	assert( m_zonecontXColumnBorderZoneCache.size() == 0 ) ;
	assert( m_zonecontXColumnZoneCache.size() == 0 );
	assert( m_zonecontXColumnZoneOverlapCache.size() == 0 );
	assert( m_zonecontYColumnBorderZoneCache.size() == 0 );
	assert( m_zonecontYColumnZoneCache.size() == 0 );
	assert( m_zonecontYColumnZoneOverlapCache.size()== 0 ) ;



	{
		DcdPos	iPos = pIfDcdTarget->getZone().getX().getPos() ;
		DcdPos	iPosOverlap = iPos ;
		int iXColumnNumber ;
		for ( iXColumnNumber = -1 ;iXColumnNumber < getXColumnCount() ; 
				iXColumnNumber ++ ){
			CDcdGridXColumn*	pCDcdGridXColumn = 
				getXColumn( iXColumnNumber ) ;
			CDcdGridXBorder*	pCDcdGridXBorder= 
				getXBorder( iXColumnNumber ) ;
			if ( iXColumnNumber == m_iXFixColumnCount ){
				iPosOverlap -= getXColumnsSize( pIfDcdTarget , 
					m_iXFixColumnCount , false , 
					m_iXFixafterColumnNumber - 1 , true ) ;
			}
			
			if ( iXColumnNumber >= 0 ){
				// --------------------------------
				//	��
				// --------------------------------
				
				DcdSize	iSize = pCDcdGridXColumn->getColumnSize( 
					pIfDcdTarget ) ;
				// --------------------------------
				//	iXColumnNumber ���Œ��
				// --------------------------------
				if ( iXColumnNumber < m_iXFixColumnCount ){
					m_zonecontXColumnZoneCache.push_back( 
						CdDcdZone( iPos , iSize ) ) ;
					iPos += iSize ;
					m_zonecontXColumnZoneOverlapCache.push_back( 
						CdDcdZone( iPosOverlap , iSize ) ) ;
					iPosOverlap += iSize ;
				}
				// --------------------------------
				//	iXColumnNumber ���X�N���[���A�E�g��
				// --------------------------------
				if ( m_iXFixColumnCount <= iXColumnNumber && 
						iXColumnNumber < m_iXFixafterColumnNumber ){
					m_zonecontXColumnZoneCache.push_back( 
						CdDcdZone( iPos , 0 ) ) ;
				
					m_zonecontXColumnZoneOverlapCache.push_back( 
						CdDcdZone( iPosOverlap , iSize ) ) ;
					iPosOverlap += iSize ;
				}
				// --------------------------------
				//	iXColumnNumber ���X�N���[���A�E�g��̂���
				// --------------------------------
				if ( m_iXFixafterColumnNumber <= iXColumnNumber ){
					m_zonecontXColumnZoneCache.push_back( 
						CdDcdZone( iPos , iSize ) ) ;
					iPos += iSize ;
				
					m_zonecontXColumnZoneOverlapCache.push_back( 
						CdDcdZone( iPosOverlap , iSize ) ) ;
					iPosOverlap += iSize ;
				}
				
			}
			// --------------------------------
			//	�g��
			// --------------------------------
			{
				DcdSize	iSize = pCDcdGridXBorder->getColumnBorderSize( 
					pIfDcdTarget ) ;
				// --------------------------------
				//	iXColumnNumber ���Œ��
				// --------------------------------
				if ( iXColumnNumber < m_iXFixColumnCount ){
					m_zonecontXColumnBorderZoneCache.push_back( 
						CdDcdZone( iPos , iSize ) ) ;
					iPos += iSize ;
					iPosOverlap += iSize ;
				}
				// --------------------------------
				//	iXColumnNumber ���X�N���[���A�E�g��
				// --------------------------------
				if ( m_iXFixColumnCount <= iXColumnNumber && 
						iXColumnNumber < m_iXFixafterColumnNumber ){
					m_zonecontXColumnBorderZoneCache.push_back( 
						CdDcdZone( iPos , 0 ) ) ;
				
					iPosOverlap += iSize ;
				}
				// --------------------------------
				//	iXColumnNumber ���X�N���[���A�E�g��̂���
				// --------------------------------
				if ( m_iXFixafterColumnNumber <= iXColumnNumber ){
					m_zonecontXColumnBorderZoneCache.push_back( 
						CdDcdZone( iPos , iSize ) ) ;
					iPos += iSize ;
					iPosOverlap += iSize ;
				}
			}
		}
	}
	{
		DcdPos	iPos = pIfDcdTarget->getZone().getY().getPos() ;
		DcdPos	iPosOverlap = iPos ;
		int iYColumnNumber ;
		for ( iYColumnNumber = -1 ;iYColumnNumber < getYColumnCount() ; 
				iYColumnNumber ++ ){
			CDcdGridYColumn*	pCDcdGridYColumn = 
				getYColumn( iYColumnNumber ) ;
			CDcdGridYBorder*	pCDcdGridYBorder= 
				getYBorder( iYColumnNumber ) ;
			if ( iYColumnNumber == m_iYFixColumnCount ){
				iPosOverlap -= getYColumnsSize( pIfDcdTarget , 
					m_iYFixColumnCount , false , 
					m_iYFixafterColumnNumber - 1 , true ) ;
			}
			
			if ( iYColumnNumber >= 0 ){
				// --------------------------------
				//	��
				// --------------------------------
				
				DcdSize	iSize = pCDcdGridYColumn->getColumnSize( 
					pIfDcdTarget ) ;
				// --------------------------------
				//	iYColumnNumber ���Œ��
				// --------------------------------
				if ( iYColumnNumber < m_iYFixColumnCount ){
					m_zonecontYColumnZoneCache.push_back( 
						CdDcdZone( iPos , iSize ) ) ;
					iPos += iSize ;
					m_zonecontYColumnZoneOverlapCache.push_back( 
						CdDcdZone( iPosOverlap , iSize ) ) ;
					iPosOverlap += iSize ;
				}
				// --------------------------------
				//	iYColumnNumber ���X�N���[���A�E�g��
				// --------------------------------
				if ( m_iYFixColumnCount <= iYColumnNumber && 
						iYColumnNumber < m_iYFixafterColumnNumber ){
					m_zonecontYColumnZoneCache.push_back( 
						CdDcdZone( iPos , 0 ) ) ;
				
					m_zonecontYColumnZoneOverlapCache.push_back( 
						CdDcdZone( iPosOverlap , iSize ) ) ;
					iPosOverlap += iSize ;
				}
				// --------------------------------
				//	iYColumnNumber ���X�N���[���A�E�g��̂���
				// --------------------------------
				if ( m_iYFixafterColumnNumber <= iYColumnNumber ){
					m_zonecontYColumnZoneCache.push_back( 
						CdDcdZone( iPos , iSize ) ) ;
					iPos += iSize ;
				
					m_zonecontYColumnZoneOverlapCache.push_back( 
						CdDcdZone( iPosOverlap , iSize ) ) ;
					iPosOverlap += iSize ;
				}
				
			}
			// --------------------------------
			//	�g��
			// --------------------------------
			{
				DcdSize	iSize = pCDcdGridYBorder->getColumnBorderSize( 
					pIfDcdTarget ) ;
				// --------------------------------
				//	iYColumnNumber ���Œ��
				// --------------------------------
				if ( iYColumnNumber < m_iYFixColumnCount ){
					m_zonecontYColumnBorderZoneCache.push_back( 
						CdDcdZone( iPos , iSize ) ) ;
					iPos += iSize ;
					iPosOverlap += iSize ;
				}
				// --------------------------------
				//	iYColumnNumber ���X�N���[���A�E�g��
				// --------------------------------
				if ( m_iYFixColumnCount <= iYColumnNumber && 
						iYColumnNumber < m_iYFixafterColumnNumber ){
					m_zonecontYColumnBorderZoneCache.push_back( 
						CdDcdZone( iPos , 0 ) ) ;
				
					iPosOverlap += iSize ;
				}
				// --------------------------------
				//	iYColumnNumber ���X�N���[���A�E�g��̂���
				// --------------------------------
				if ( m_iYFixafterColumnNumber <= iYColumnNumber ){
					m_zonecontYColumnBorderZoneCache.push_back( 
						CdDcdZone( iPos , iSize ) ) ;
					iPos += iSize ;
					iPosOverlap += iSize ;
				}
			}
		}
	}
	return true ;
}
void CDcdGrid::destroyZoneCache() 
{
	m_zonecontXColumnBorderZoneCache.clear() ;
	m_zonecontXColumnZoneCache.clear() ;
	m_zonecontXColumnZoneOverlapCache.clear() ;
	m_zonecontYColumnBorderZoneCache.clear() ;
	m_zonecontYColumnZoneCache.clear() ;
	m_zonecontYColumnZoneOverlapCache.clear() ;
}

	// --------------------------------
	//@name	DcDraw�̉����֐�
	// --------------------------------


bool CDcdGrid::IsXBorderOverlappedByAttachedCell( int iXColumnNumber , int iYColumnNumber ) 
{
	bool bIsOverlappedColumn = false ;
	{
		CDcdGridCell* pCellEndSide = getCell( iXColumnNumber + 1 , iYColumnNumber ) ;
		//	�w�肳�ꂽX�r��(�c��)��Y��̈ʒu�̉E�̃Z���������Z��
		if ( pCellEndSide != NULL && pCellEndSide->getAttachTo() != NULL )
		{
			//	������̃Z����XIndex���A�r����荶
			int iAttachToCellXColumnNumber = getXColumnNumberOfCell( pCellEndSide->getAttachTo() ) ;
			if ( iAttachToCellXColumnNumber < iXColumnNumber + 1 )
			{
				bIsOverlappedColumn = true  ;
			}
		}
	}
	return bIsOverlappedColumn ;
}

bool CDcdGrid::IsYBorderOverlappedByAttachedCell( int iXColumnNumber , int iYColumnNumber ) 
{
	bool bIsOverlappedColumn = false ;
	{
		CDcdGridCell* pCellEndSide = getCell( iXColumnNumber , iYColumnNumber + 1 ) ;
		//	�w�肳�ꂽY�r��(����)��X��̈ʒu�̉��̃Z���������Z��
		if ( pCellEndSide != NULL && pCellEndSide->getAttachTo() != NULL )
		{
			//	������̃Z����YIndex���A�r������
			int iAttachToCellYColumnNumber = getYColumnNumberOfCell( pCellEndSide->getAttachTo() ) ;
			if ( iAttachToCellYColumnNumber < iYColumnNumber + 1 )
			{
				bIsOverlappedColumn = true  ;
			}
		}
	}
	return bIsOverlappedColumn ;
}



bool CDcdGrid::DcDraw_DrawXColumn( bool isYFixColumn , CaDcdTargetClip* pTarget , int iXColumnNumber ) 
{
	bool bRv = false ;

	int iYColumnIndexLoopStart ;
	int iYColumnIndexLoopEnd ;


	//	�Œ�̈�̌r����X��͈�
	if ( isYFixColumn )
	{
		iYColumnIndexLoopStart = 0 ;
		iYColumnIndexLoopEnd = m_iYFixColumnCount ;
	}
	//	�X�N���[���̈�̌r����X��͈�
	else
	{
		iYColumnIndexLoopStart = m_iYFixColumnCount ;
		iYColumnIndexLoopEnd = getYColumnCount() ;
	}


	int iYColumnIndexBegin = INT_MIN ; 
	for ( int iYColumnIndex = iYColumnIndexLoopStart ; iYColumnIndex < iYColumnIndexLoopEnd ; iYColumnIndex++ )
	{
		//	�r���̎n�_������B
		//	�r���������Z���ł�������Ă��Ȃ���΁A�r���̎n�_�B
		if ( iYColumnIndexBegin == INT_MIN 
			&& !IsXBorderOverlappedByAttachedCell( iXColumnNumber , iYColumnIndex ) )
		{
			iYColumnIndexBegin = iYColumnIndex ;
		}
		//	�r���̏I�_
		//	�EiYColumnIndex �� m_iYFixColumnCount-1
		//	�E���� iYColumnIndex ���A�����Z���ŉB�����
		if ( iYColumnIndexBegin != INT_MIN 
			&& ( iYColumnIndex == iYColumnIndexLoopEnd - 1 
				|| IsXBorderOverlappedByAttachedCell( iXColumnNumber , iYColumnIndex + 1 ) ) )
		{
			CdDcdZoneXy	zonexyBorder ;
			zonexyBorder.setX( getXColumnBorderZone( pTarget , iXColumnNumber ) ) ;
			{
				CdDcdZone	aZone ;
				aZone.setBeginEndPos( getYColumnBorderZone( pTarget, iYColumnIndexBegin - 1 ).getPos() , 
					getYColumnBorderZone( pTarget , iYColumnIndex ).getEndPos() ) ;
				zonexyBorder.setY( aZone ) ;
			}

			CaDcdTargetItemPosition	aTarget( pTarget , zonexyBorder );
			if ( aTarget.isDrawable() )
			{
				bRv |= getXBorder( iXColumnNumber )->getIfDcDraw()->
					DcDraw( &aTarget ) ;
			}
			iYColumnIndexBegin = INT_MIN ; 
		}
	}
	return bRv ;
}

bool CDcdGrid::DcDraw_DrawYColumn( bool isXFixColumn , CaDcdTargetClip* pTarget , int iYColumnNumber ) 
{
	bool bRv = false ;
	int iXColumnIndexLoopStart ;
	int iXColumnIndexLoopEnd ;


	//	�Œ�̈�̌r����X��͈�
	if ( isXFixColumn )
	{
		iXColumnIndexLoopStart = 0 ;
		iXColumnIndexLoopEnd = m_iXFixColumnCount ;
	}
	//	�X�N���[���̈�̌r����X��͈�
	else
	{
		iXColumnIndexLoopStart = m_iXFixColumnCount ;
		iXColumnIndexLoopEnd = getXColumnCount() ;
	}


	int iXColumnIndexBegin = INT_MIN ; 
	for ( int iXColumnIndex = iXColumnIndexLoopStart ; iXColumnIndex < iXColumnIndexLoopEnd ; iXColumnIndex++ )
	{
		//	�r���̎n�_������B
		//	�r���������Z���ł�������Ă��Ȃ���΁A�r���̎n�_�B
		if ( iXColumnIndexBegin == INT_MIN 
			&& !IsYBorderOverlappedByAttachedCell( iXColumnIndex , iYColumnNumber ) )
		{
			iXColumnIndexBegin = iXColumnIndex ;
		}
		//	�r���̏I�_
		//	�EiXColumnIndex �� m_iXFixColumnCount-1
		//	�E���� iXColumnIndex ���A�����Z���ŉB�����
		if ( iXColumnIndexBegin != INT_MIN 
			&& ( iXColumnIndex == iXColumnIndexLoopEnd - 1 
				|| IsYBorderOverlappedByAttachedCell( iXColumnIndex + 1 , iYColumnNumber ) ) )
		{
			CdDcdZoneXy	zonexyBorder ;
			zonexyBorder.setY( getYColumnBorderZone( pTarget , iYColumnNumber ) ) ;
			{
				CdDcdZone	aZone ;
				aZone.setBeginEndPos( getXColumnBorderZone( pTarget, iXColumnIndexBegin - 1 ).getPos() , 
					getXColumnBorderZone( pTarget , iXColumnIndex ).getEndPos() ) ;
				zonexyBorder.setX( aZone ) ;
			}

			CaDcdTargetItemPosition	aTarget( pTarget , zonexyBorder );
			if ( aTarget.isDrawable() )
			{
				bRv |= getYBorder( iYColumnNumber )->getIfDcDraw()->
					DcDraw( &aTarget ) ;
			}
			iXColumnIndexBegin = INT_MIN ; 
		}
	}
	return bRv ;
}


// ********************************
//	�R���X�g���N�^
// ********************************
CDcdGrid::CDcdGrid() 
{
	{
		OuNew<IfDcDraw>	pCDcdLine = new CDcdLine( CdPenProp( 1 ) ) ;
		m_CDcdGridYBorderTop.setIfDcDraw( pCDcdLine ) ;
	}
	{
		OuNew<IfDcDraw>	pCDcdLine = new CDcdLine( CdPenProp( 1 ) ) ;
		m_CDcdGridYBorderBottom.setIfDcDraw( pCDcdLine ) ;
	}	{
		OuNew<IfDcDraw>	pCDcdLine = new CDcdLine( CdPenProp( 1 ) ) ;
		m_CDcdGridXBorderTop.setIfDcDraw( pCDcdLine ) ;
	}
	{
		OuNew<IfDcDraw>	pCDcdLine = new CDcdLine( CdPenProp( 1 ) ) ;
		m_CDcdGridXBorderBottom.setIfDcDraw( pCDcdLine ) ;
	}

	// --------------------------------
	m_iXFixColumnCount = 0 ;
	m_iXFixafterColumnNumber = 0 ;
	m_iYFixColumnCount = 0 ;
	m_iYFixafterColumnNumber = 0 ;
}
CDcdGrid::~CDcdGrid() 
{
	setXColumnCount( 0 ) ;
	setYColumnCount( 0 ) ;

	//	ColumnNumber -1 �� Column ���폜
	while ( m_CDcdGridXColumnCont.size() > 0 ){
		CDcdGridXColumn*	pCDcdGridXColumn = m_CDcdGridXColumnCont.back() ;
		
		OnDeleteXColumn( getXColumnNumberOfCoulmn( pCDcdGridXColumn ) , 
			pCDcdGridXColumn ) ;
		
		m_CDcdGridXColumnCont.pop_back() ;
		delete pCDcdGridXColumn ;
	}
	while ( m_CDcdGridYColumnCont.size() > 0 ){
		CDcdGridYColumn*	pCDcdGridYColumn = m_CDcdGridYColumnCont.back() ;

		OnDeleteYColumn( getYColumnNumberOfCoulmn( pCDcdGridYColumn ) , 
			pCDcdGridYColumn ) ;

		m_CDcdGridYColumnCont.pop_back() ;
		delete pCDcdGridYColumn ;
	}
}
	
// ********************************
//	IfDcDraw
// ********************************
bool CDcdGrid::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool	bRv = false ;
	bool bMustDestroyZoneCache = createZoneCache( pIfDcdTarget ) ;
	// --------------------------------

	CdDcdSizeXy	aCdDcdSizeXy ;
	getItemSize( pIfDcdTarget , &aCdDcdSizeXy ) ;
	//aCdDcdSizeXy = �O���b�h�̑傫��


	// --------------------------------
	//	�Z��
	// --------------------------------
	bool	bIsDisplay = false ;
	{
		int iValue = GetDeviceCaps( pIfDcdTarget->getHdc() , TECHNOLOGY ) ;
		if ( iValue == DT_RASDISPLAY ){
			bIsDisplay = true ;
		}
	}
	//bIsDisplay = �^�Ȃ�ApIfDcdTarget �̓f�B�X�v���C�ł��B
	//	�f�B�X�v���C�łȂ��ꍇ�i�v�����^�̏ꍇ�j�́A
	//	�N���b�v���[�W�������g���Ȃ��ꍇ������܂��B
	{
		//	�Z���̕`��́A ColumnNumber �̑傫�������珬�������Ɍ�������
		//	�s���܂��B
		//	����́AAttachCell �� AttachedCell ��
		//	 FixColumnCount -1 �̗�̌r��
		//	���܂����ł���ꍇ�ł��A FixColumn ����ɕ`�悷�邱�Ƃɂ��A
		//	FixColumn �̕������ɂ��邽�߂ł��B
		int iYColumnNumber ;
		for ( iYColumnNumber = getYColumnCount() - 1  ; iYColumnNumber >= 0 ;
				iYColumnNumber -- ){
			int iXColumnNumber ;
			for ( iXColumnNumber = getXColumnCount() - 1  ; 
					iXColumnNumber >= 0   ; iXColumnNumber -- ){
				// --------------------------------
				CdDcdZoneXy	aCdDcdZoneXy = getCellZone( pIfDcdTarget , 
					iXColumnNumber , iYColumnNumber ) ;
				if ( !( aCdDcdZoneXy.getX().getSize() > 0 && 
						aCdDcdZoneXy.getY().getSize() > 0 ) ){
					//	�Z���̃T�C�Y���O�̏ꍇ�́A
					//	�㑱�̏����͍s���܂���
					continue ;
				}
				CaDcdTargetItemPosition	aTarget( 
						pIfDcdTarget , aCdDcdZoneXy ) ;
				if ( !aTarget.isDrawable() ){
					//	�Z���̈ʒu���`��\�ȗ̈�łȂ��ꍇ�́A
					//	�㑱�̏����͍s���܂���
					continue ;
				}

				// --------------------------------

				//	���̃Z���́A�`��\�ȗ̈�ɂ������Ă��܂��B
				CDcdGridCell* pCell = 
					getCell( iXColumnNumber , iYColumnNumber ) ;
				if ( pCell->getXAttachCellCount() == 1 && 
						pCell->getYAttachCellCount() == 1 ){
					//	���̃Z���́A�ǂ̃Z���ɂ���������Ă��܂���B
					//	�Ɨ��Z���ł��B
					bRv |= pCell->getIfDcDraw()->DcDraw( &aTarget ) ;
				}	else 	{
					//	���̃Z���́A���̃Z�����猋������Ă��܂�
					CdDcdZoneXy	aCdDcdZoneXyScrolling = 
						getCellZoneOverlap( pIfDcdTarget ,
							iXColumnNumber ,
							iYColumnNumber )  ;
					CaDcdTargetItemPosition	aTargetItemPosition( 
						pIfDcdTarget , aCdDcdZoneXyScrolling ) ;
					if ( aTarget.isDrawable() ){
						if ( bIsDisplay ){
							//ClipRgn�g�p

							//	���̋�Ԃ́A�f�B�X�v���C�̏ꍇ�ɂ̂�
							//	�ʍs���܂��B
							//	CaDcdTargetClip(ClipRgn)�́A
							//	�v�����^�ɂ͖����ł��B
							CaDcdTargetClip	aTargetClip( 
								&aTargetItemPosition , 
								aCdDcdZoneXy ) ;
							aTargetClip.validate() ;
							bRv |= pCell->getIfDcDraw()->
								DcDraw( &aTargetClip ) ;
						}	else	{
							//ClipRgn�s�g�p
							bRv |= pCell->getIfDcDraw()->
								DcDraw( &aTargetItemPosition ) ;
						}
					}
				}
			}
		}
	}

	// --------------------------------
	//	Zone00�̌r���`��
	// --------------------------------
	{
		//	�N���b�v��ݒ�
		CdDcdZoneXy aZoneXyClip ;
		{
			CdDcdZone	zoneBorderX0 = getXColumnBorderZone( pIfDcdTarget , -1 ) ;
			CdDcdZone	zoneBorderX1 = getXColumnBorderZone( pIfDcdTarget , m_iXFixColumnCount ) ;
			CdDcdZone	zoneBorderY0 = getYColumnBorderZone( pIfDcdTarget , -1 ) ;
			CdDcdZone	zoneBorderY1 = getYColumnBorderZone( pIfDcdTarget , m_iYFixColumnCount ) ;
			aZoneXyClip.setX( CdDcdZone().setBeginEndPos( zoneBorderX0.getPos() , zoneBorderX1.getEndPos() ) ) ;
			aZoneXyClip.setY( CdDcdZone().setBeginEndPos( zoneBorderY0.getPos() , zoneBorderY1.getEndPos() ) ) ;
		}
		CaDcdTargetClip	aTargetClip( pIfDcdTarget , aZoneXyClip ) ;
		aTargetClip.validate() ;

		//	XBorder�̌r���`��
		for ( int iXColumnIndex = 0 ; iXColumnIndex < m_iXFixColumnCount && iXColumnIndex < getXColumnCount()  ; iXColumnIndex ++ )
		{
			DcDraw_DrawXColumn( true , &aTargetClip , iXColumnIndex ) ;
		}


		//	YBorder�̌r���`��
		for ( int iYColumnIndex = 0 ; iYColumnIndex < m_iYFixColumnCount && iYColumnIndex < getYColumnCount()  ; iYColumnIndex ++ )
		{
			DcDraw_DrawYColumn( true , &aTargetClip , iYColumnIndex ) ;
		}
		//��ԊO���̌r���́A�Ō�ɕ`�悵�܂�
		DcDraw_DrawXColumn( true , &aTargetClip , -1 ) ;
		DcDraw_DrawYColumn( true , &aTargetClip , -1 ) ;
	}
	// --------------------------------
	//	Zone10�̌r���`��
	// --------------------------------
	{
		//	�N���b�v��ݒ�
		CdDcdZoneXy aZoneXyClip ;
		{
			CdDcdZone	zoneBorderX0 = getXColumnZone( pIfDcdTarget , m_iXFixColumnCount ) ;
			CdDcdZone	zoneBorderX1 = getXColumnBorderZone( pIfDcdTarget , INT_MAX ) ;
			CdDcdZone	zoneBorderY0 = getYColumnBorderZone( pIfDcdTarget , -1 ) ;
			CdDcdZone	zoneBorderY1 = getYColumnBorderZone( pIfDcdTarget , m_iYFixColumnCount ) ;
			aZoneXyClip.setX( CdDcdZone().setBeginEndPos( zoneBorderX0.getPos() , zoneBorderX1.getEndPos() ) ) ;
			aZoneXyClip.setY( CdDcdZone().setBeginEndPos( zoneBorderY0.getPos() , zoneBorderY1.getEndPos() ) ) ;
		}
		CaDcdTargetClip	aTargetClip( pIfDcdTarget , aZoneXyClip ) ;
		aTargetClip.validate() ;

		//	XBorder�̌r���`��
		for ( int iXColumnIndex = m_iXFixColumnCount ; iXColumnIndex < getXColumnCount() - 1 ; iXColumnIndex ++ )
		{
			DcDraw_DrawXColumn( true , &aTargetClip , iXColumnIndex ) ;
		}
		//	YBorder�̌r���`��
		for ( int iYColumnIndex = 0 ; iYColumnIndex < m_iYFixColumnCount && iYColumnIndex < getYColumnCount()  ; iYColumnIndex ++ )
		{
			DcDraw_DrawYColumn( false , &aTargetClip , iYColumnIndex ) ;
		}
		//	��ԊO���̌r���́A�Ō�ɕ`�悵�܂��B
		DcDraw_DrawXColumn( true , &aTargetClip , getXColumnCount() -1 ) ;
		DcDraw_DrawYColumn( false , &aTargetClip , -1 ) ;

	}
	// --------------------------------
	//	Zone01�̌r���`��
	// --------------------------------
	{
		//	�N���b�v��ݒ�
		CdDcdZoneXy aZoneXyClip ;
		{
			CdDcdZone	zoneBorderX0 = getXColumnBorderZone( pIfDcdTarget , -1 ) ;
			CdDcdZone	zoneBorderX1 = getXColumnBorderZone( pIfDcdTarget , m_iXFixColumnCount ) ;
			CdDcdZone	zoneBorderY0 = getYColumnZone( pIfDcdTarget , m_iYFixColumnCount ) ;
			CdDcdZone	zoneBorderY1 = getYColumnBorderZone( pIfDcdTarget , INT_MAX ) ;
			aZoneXyClip.setX( CdDcdZone().setBeginEndPos( zoneBorderX0.getPos() , zoneBorderX1.getEndPos() ) ) ;
			aZoneXyClip.setY( CdDcdZone().setBeginEndPos( zoneBorderY0.getPos() , zoneBorderY1.getEndPos() ) ) ;
		}
		CaDcdTargetClip	aTargetClip( pIfDcdTarget , aZoneXyClip ) ;
		aTargetClip.validate() ;

		//	XBorder�̌r���`��
		for ( int iXColumnIndex = 0 ; iXColumnIndex < m_iXFixColumnCount && iXColumnIndex < getXColumnCount()  ; iXColumnIndex ++ )
		{
			DcDraw_DrawXColumn( false , &aTargetClip , iXColumnIndex ) ;
		}
		//	YBorder�̌r���`��
		for ( int iYColumnIndex = m_iYFixColumnCount ; iYColumnIndex < getYColumnCount() - 1 ; iYColumnIndex ++ )
		{
			DcDraw_DrawYColumn( true , &aTargetClip , iYColumnIndex ) ;
		}

		//	��ԊO���̌r���́A�Ō�ɕ`�悵�܂��B
		DcDraw_DrawXColumn( false , &aTargetClip , -1  ) ;
		DcDraw_DrawYColumn( true , &aTargetClip , getYColumnCount() -1 ) ;
	}
	// --------------------------------
	//	Zone11�̌r���`��
	// --------------------------------
	{
		//	�N���b�v��ݒ�
		CdDcdZoneXy aZoneXyClip ;
		{
			CdDcdZone	zoneBorderX0 = getXColumnZone( pIfDcdTarget , m_iXFixColumnCount ) ;
			CdDcdZone	zoneBorderX1 = getXColumnBorderZone( pIfDcdTarget , INT_MAX ) ;
			CdDcdZone	zoneBorderY0 = getYColumnZone( pIfDcdTarget , m_iYFixColumnCount ) ;
			CdDcdZone	zoneBorderY1 = getYColumnBorderZone( pIfDcdTarget , INT_MAX ) ;
			aZoneXyClip.setX( CdDcdZone().setBeginEndPos( zoneBorderX0.getPos() , zoneBorderX1.getEndPos() ) ) ;
			aZoneXyClip.setY( CdDcdZone().setBeginEndPos( zoneBorderY0.getPos() , zoneBorderY1.getEndPos() ) ) ;
		}
		CaDcdTargetClip	aTargetClip( pIfDcdTarget , aZoneXyClip ) ;
		aTargetClip.validate() ;

		//	XBorder�̌r���`��
		for ( int iXColumnIndex = m_iXFixColumnCount ; iXColumnIndex < getXColumnCount() - 1 ; iXColumnIndex ++ )
		{
			DcDraw_DrawXColumn( false , &aTargetClip , iXColumnIndex ) ;
		}
		//	YBorder�̌r���`��
		for ( int iYColumnIndex = m_iYFixColumnCount ; iYColumnIndex < getYColumnCount() - 1 ; iYColumnIndex ++ )
		{
			DcDraw_DrawYColumn( false , &aTargetClip , iYColumnIndex ) ;
		}
		//	��ԊO���̌r���́A�Ō�ɕ`�悵�܂��B
		DcDraw_DrawXColumn( false , &aTargetClip , getXColumnCount() -1 ) ;
		DcDraw_DrawYColumn( false , &aTargetClip , getYColumnCount() -1  ) ;
	}
	// --------------------------------
	if ( bMustDestroyZoneCache )
	{
		destroyZoneCache() ;
	}
	return ( bRv ) ;
}


bool CDcdGrid::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	bool	bRv = false ;
	// --------------------------------
	//	NULL�ی�
	// --------------------------------
	CdDcdSizeXy	aCdDcdSizeXy ;
	if ( pCdDcdSizeXy == NULL ){
		pCdDcdSizeXy = &aCdDcdSizeXy ;
	}
	// --------------------------------
	bRv = true ;
	*pCdDcdSizeXy = CdDcdSizeXy() ;
	{
		CdDcdZone	aCdDcdZoneA = getYColumnBorderZone( pIfDcdTarget , -1 ) ;
		CdDcdZone	aCdDcdZoneB = getYColumnBorderZone( 
			pIfDcdTarget , INT_MAX ) ;
		pCdDcdSizeXy->setY( aCdDcdZoneB.getEndPos() - aCdDcdZoneA.getPos() ) ;
	}
	{
		CdDcdZone	aCdDcdZoneA = getXColumnBorderZone( pIfDcdTarget , -1 ) ;
		CdDcdZone	aCdDcdZoneB = 
			getXColumnBorderZone( pIfDcdTarget , INT_MAX ) ;
		pCdDcdSizeXy->setX( aCdDcdZoneB.getEndPos() - aCdDcdZoneA.getPos() ) ;
	}
	return ( bRv ) ;
}
	
// ********************************
//	CDcdGrid
// ********************************
	// --------------------------------
	//@name �s�E��E�Z���̏�����
	// --------------------------------
void CDcdGrid::OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	//LogMsg( "CDcdGrid::OnCreateXColumn(%d)" , iXColumnNumber ) ;

	OuNew<IfDcDraw>	pCDcdLine = new CDcdLine( CdPenProp( 1 ) ) ;
	pCDcdGridXColumn->getCDcdGridXBorder()->setIfDcDraw( pCDcdLine ) ;
}
void CDcdGrid::OnDeleteXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) 
{
	//LogMsg( "CDcdGrid::OnDeleteXColumn(%d)" , iXColumnNumber ) ;
}

void CDcdGrid::OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
	//LogMsg( "CDcdGrid::OnCreateYColumn(%d)" , iYColumnNumber ) ;

	OuNew<IfDcDraw>	pCDcdLine = new CDcdLine( CdPenProp( 1 ) ) ;
	pCDcdGridYColumn->getCDcdGridYBorder()->setIfDcDraw( pCDcdLine ) ;
}
void CDcdGrid::OnDeleteYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) 
{
}

void CDcdGrid::OnCreateCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) 
{
	//LogMsg( "CDcdGrid::OnCreateCell(%d,%d)" , 
	//	iXColumnNumber , iYColumnNumber ) ;

	CdDrawTextProp	aCdDrawTextProp ;
	aCdDrawTextProp.setCdFontProp( 
		CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ; 
	OuNew<CDcdTextbox>	pCDcdTextbox = 
		new CDcdTextbox( 
			CdPenProp() ,
			1 , 1 , 
			TEXT( "" ) ,
			aCdDrawTextProp ,
			TEXT( "" ) ,
			1 ,
			CdBrushProp( CdColorProp( 255 , 255 , 255 ) ) );
	pCDcdGridCell->setIfDcDraw( pCDcdTextbox ) ;

}

	
void CDcdGrid::OnDeleteCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) 
{
	//LogMsg( "CDcdGrid::OnDeleteCell(%d,%d)" , 
	//	iXColumnNumber , iYColumnNumber ) ;
}


	// ********************************
	///	@name Y��EX��̐�
	// ********************************
int CDcdGrid::getYColumnCount() 
{
	return ( m_CDcdGridYColumnCont.size()  ) ;
}
CDcdGrid& CDcdGrid::setYColumnCount( int ev ) 
{
	int iError = 0 ;
	while ( iError >= 0 && getYColumnCount() < ev ){
		iError = insertYColumn_insertColumnCell( INT_MAX ) ;
	}
	while ( iError >= 0 && getYColumnCount() > ev ){
		iError = eraseYColumn_eraseColumnCell( INT_MAX ) ;
	}
	adjustProp() ;
	return ( *this ) ;
}
int CDcdGrid::getXColumnCount() 
{
	return ( m_CDcdGridXColumnCont.size() ) ;
}
CDcdGrid& CDcdGrid::setXColumnCount( int ev ) 
{
	int iError = 0 ;

	while ( iError >= 0 && getXColumnCount() < ev ){
		iError = insertXColumn_insertColumnCell( INT_MAX ) ;
	}
	while ( iError >= 0 && getXColumnCount() > ev ){
		iError = eraseXColumn_eraseColumnCell( INT_MAX ) ;
	}
	adjustProp() ;
	return ( *this ) ;
}
	// ********************************
	///	@name Y��EX���}��/�폜
	// ********************************
int CDcdGrid::insertYColumn( int iYColumnNumber ) 
{
	int	iRv = 0 ;
	if ( iRv >= 0 ){
		iRv = insertYColumn_insertColumnCell( iYColumnNumber ) ;
	}
	if ( iRv >= 0 ){
		adjustProp() ;
	}
	return ( iRv ) ;
}
int CDcdGrid::insertXColumn( int iXColumnNumber ) 
{
	int	iRv = 0 ;
	if ( iRv >= 0 ){
		iRv = insertXColumn_insertColumnCell( iXColumnNumber ) ;
	}
	if ( iRv >= 0 ){
		adjustProp() ;
	}
	return ( iRv ) ;
}
int CDcdGrid::eraseYColumn( int iYColumnNumber ) 
{
	int iRv = 0 ;	
	if ( iRv >= 0 ){
		iRv = eraseYColumn_eraseColumnCell( iYColumnNumber ) ;
	}
	if ( iRv >= 0 ){
		adjustProp() ;
	}
	return ( iRv ) ;
}
int CDcdGrid::eraseXColumn( int iXColumnNumber ) 
{
	int iRv = 0 ;	
	if ( iRv >= 0 ){
		iRv = eraseXColumn_eraseColumnCell( iXColumnNumber ) ;
	}
	if ( iRv >= 0 ){
		adjustProp() ;
	}
	return ( iRv ) ;
}

	// ********************************
	///	@name Y��EX��E�Z���I�u�W�F�N�g
	// ********************************
CDcdGridYColumn* CDcdGrid::getYColumn( int iYColumnNumber )  
{
	if ( iYColumnNumber == INT_MAX ){
		iYColumnNumber = getYColumnCount() - 1 ;
	}
	if ( !( 0 <= iYColumnNumber && iYColumnNumber < getYColumnCount() ) ){
		return ( NULL ) ;
	}
	return ( m_CDcdGridYColumnCont[ iYColumnNumber ] ) ; 
}
CDcdGridXColumn*	CDcdGrid::getXColumn( int iXColumnNumber )  
{
	if ( iXColumnNumber == INT_MAX ){
		iXColumnNumber = getXColumnCount() - 1 ;
	}
	if ( !( 0 <= iXColumnNumber && iXColumnNumber < getXColumnCount() ) ){
		return ( NULL ) ;
	}
	return ( m_CDcdGridXColumnCont[ iXColumnNumber ] ) ; 
}

CDcdGridYBorder*	CDcdGrid::getYBorder( int iYColumnNumber )  
{
	CDcdGridYBorder*	pCDcdGridYBorder = NULL ;
	if ( iYColumnNumber == INT_MAX )
	{
		iYColumnNumber = getYColumnCount() - 1 ;
	}
	if ( !( -1 <= iYColumnNumber && iYColumnNumber < getYColumnCount() ) )
	{
		return ( NULL ) ;
	}
	if ( iYColumnNumber == -1 )
	{
		pCDcdGridYBorder = &m_CDcdGridYBorderTop ;
	}
	else if ( iYColumnNumber == getYColumnCount() - 1 )
	{
		pCDcdGridYBorder = &m_CDcdGridYBorderBottom ;
	}
	else 
	{
		pCDcdGridYBorder =  m_CDcdGridYColumnCont[ iYColumnNumber ]->getCDcdGridYBorder() ; 
	}
	return pCDcdGridYBorder ;
}


CDcdGridXBorder*	CDcdGrid::getXBorder( int iXColumnNumber )  
{
	CDcdGridXBorder*	pCDcdGridXBorder = NULL ;
	if ( iXColumnNumber == INT_MAX )
	{
		iXColumnNumber = getXColumnCount() - 1 ;
	}
	if ( !( -1 <= iXColumnNumber && iXColumnNumber < getXColumnCount() ) )
	{
		return ( NULL ) ;
	}
	if ( iXColumnNumber == -1 )
	{
		pCDcdGridXBorder = &m_CDcdGridXBorderTop ;
	}
	else if ( iXColumnNumber == getXColumnCount() - 1 )
	{
		pCDcdGridXBorder = &m_CDcdGridXBorderBottom ;
	}
	else 
	{
		pCDcdGridXBorder =  m_CDcdGridXColumnCont[ iXColumnNumber ]->getCDcdGridXBorder() ; 
	}
	return pCDcdGridXBorder ;
}



int CDcdGrid::getYColumnNumberOfCoulmn( CDcdGridYColumn*	pCDcdGridYColumn ) 
{
	int iRv = INT_MIN ;
	for ( int idx = 0 ;  
			iRv == INT_MIN && idx < (int)m_CDcdGridYColumnCont.size() ; 
			idx ++ )
	{
		if ( pCDcdGridYColumn == m_CDcdGridYColumnCont[idx] )
		{
			iRv = idx ;
		}
	}
	return ( iRv ) ;
}
int CDcdGrid::getXColumnNumberOfCoulmn( CDcdGridXColumn*	pCDcdGridXColumn ) 
{
	int iRv = INT_MIN ;
	for ( int idx = 0 ;  
			iRv == INT_MIN && idx < (int)m_CDcdGridXColumnCont.size() ; 
			idx ++ )
	{
		if ( pCDcdGridXColumn == m_CDcdGridXColumnCont[idx] )
		{
			iRv = idx ;
		}
	}
	return ( iRv ) ;
}

int CDcdGrid::getYColumnNumberOfBorder( CDcdGridYBorder*	pCDcdGridYBorder ) 
{
	int iRv = INT_MIN ;

	if ( pCDcdGridYBorder ==  &m_CDcdGridYBorderTop )
	{
		iRv = -1 ;
	}
	else if ( pCDcdGridYBorder == &m_CDcdGridYBorderBottom )
	{
		iRv = m_CDcdGridYColumnCont.size() - 1 ;
	}
	else
	{
		for ( int idY = 0 ;  
				iRv == INT_MIN && idY < (int)m_CDcdGridYColumnCont.size() ; 
				idY ++ )
		{
			if ( pCDcdGridYBorder == m_CDcdGridYColumnCont[idY]->getCDcdGridYBorder() )
			{
				iRv = idY ;
			}
		}
	}
	return ( iRv ) ;
}


int CDcdGrid::getXColumnNumberOfBorder( CDcdGridXBorder*	pCDcdGridXBorder ) 
{
	int iRv = INT_MIN ;

	if ( pCDcdGridXBorder ==  &m_CDcdGridXBorderTop )
	{
		iRv = -1 ;
	}
	else if ( pCDcdGridXBorder == &m_CDcdGridXBorderBottom )
	{
		iRv = m_CDcdGridXColumnCont.size() - 1 ;
	}
	else
	{
		for ( int idx = 0 ;  
				iRv == INT_MIN && idx < (int)m_CDcdGridXColumnCont.size() ; 
				idx ++ )
		{
			if ( pCDcdGridXBorder == m_CDcdGridXColumnCont[idx]->getCDcdGridXBorder() )
			{
				iRv = idx ;
			}
		}
	}
	return ( iRv ) ;
}

CDcdGridCell* CDcdGrid::getCell( int iXColumnNumber , int iYColumnNumber ) 
{
	if ( iXColumnNumber == INT_MAX ){
		iXColumnNumber = getXColumnCount() - 1 ;
	}
	if ( iYColumnNumber == INT_MAX ){
		iYColumnNumber = getYColumnCount() - 1 ;
	}
	if ( 0 <= iXColumnNumber && iXColumnNumber < getXColumnCount() && 
		0 <= iYColumnNumber && iYColumnNumber < getYColumnCount() ){
		return ( (*m_CDcdGridCellCont[iYColumnNumber])[iXColumnNumber] ) ;
	}
	return ( NULL ) ;
}
int CDcdGrid::getXColumnNumberOfCell( 
		CDcdGridCell* pCDcdGridCell ) 
{
	int iXColumnNumber = INT_MIN ;
	// --------------------------------
	if ( pCDcdGridCell != NULL )
	{
		for ( int idx = 0 ; 
				iXColumnNumber == INT_MIN && idx < (int)pCDcdGridCell->m_pCont->size() ; 
				idx ++ )
		{
			if ( pCDcdGridCell->m_pCont->at(idx) == pCDcdGridCell )
			{
				iXColumnNumber = idx ;
			}
		}
		
	}
	return iXColumnNumber ;
}
int CDcdGrid::getYColumnNumberOfCell( 
		CDcdGridCell* pCDcdGridCell ) 
{
	int iYColumnNumber = INT_MIN ;
	// --------------------------------
	if ( pCDcdGridCell != NULL )
	{
		for ( int idx = 0 ; 
				iYColumnNumber == INT_MIN && idx < (int)m_CDcdGridCellCont.size() ; 
				idx ++ )
		{
			if ( m_CDcdGridCellCont[idx] == pCDcdGridCell->m_pCont )
			{
				iYColumnNumber = idx ;
			}
		}
		
	}
	// --------------------------------
	return iYColumnNumber ;
}
	

	// ********************************
	///	@name Y��EX��̈ʒu
	// ********************************
CdDcdZone	CDcdGrid::getYColumnZone( IfDcdTarget* pIfDcdTarget ,
	int iYColumnNumber ) 
{
	if ( iYColumnNumber == INT_MAX ){
		iYColumnNumber = getYColumnCount() - 1 ;
	}

	// --------------------------------
	//	�L���b�V��������΁A�����Ԃ��܂��B
	// --------------------------------
	if ( m_zonecontYColumnZoneCache.size() > 0 ){
		return ( m_zonecontYColumnZoneCache[ iYColumnNumber ] ) ;
	}


	CdDcdZone	aCdDcdZone ;
	// --------------------------------
	//	iYColumnNumber ���Œ��
	// --------------------------------
	if ( iYColumnNumber < m_iYFixColumnCount ){
		DcdPos	iPos = pIfDcdTarget->getZone().getY().getPos() ;
		iPos += getYColumnsSize( pIfDcdTarget , 
			-1 , true , iYColumnNumber - 1 , true ) ;
		DcdSize iSize = getYColumnsSize( pIfDcdTarget , 
			iYColumnNumber , false , iYColumnNumber , false ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}				
	// --------------------------------
	//	iYColumnNumber ���X�N���[���A�E�g��
	// --------------------------------
	if ( m_iYFixColumnCount <= iYColumnNumber && 
			iYColumnNumber < m_iYFixafterColumnNumber ){
		DcdPos	iPos = pIfDcdTarget->getZone().getY().getPos() ;
		iPos += getYColumnsSize( pIfDcdTarget , 
			-1 , true , m_iYFixColumnCount - 1 , true ) ;
		//	�T�C�Y�̓[���ł�
		aCdDcdZone.setPos( iPos ).setSize( 0 ) ;
	}				
	// --------------------------------
	//	iYColumnNumber ���X�N���[���A�E�g��̂���
	// --------------------------------
	if ( m_iYFixafterColumnNumber <= iYColumnNumber ){
		DcdPos	iPos = pIfDcdTarget->getZone().getY().getPos() ;
		iPos += getYColumnsSize( pIfDcdTarget , 
			-1 ,true , m_iYFixColumnCount - 1 , true ) ;
		iPos += getYColumnsSize( pIfDcdTarget ,
			m_iYFixafterColumnNumber , false , iYColumnNumber - 1 , true ) ;
		DcdSize iSize = getYColumnsSize( pIfDcdTarget , 
			iYColumnNumber , false , iYColumnNumber , false ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}
	return ( aCdDcdZone ) ;
}
CdDcdZone	
CDcdGrid::getXColumnZone( IfDcdTarget* pIfDcdTarget ,int iXColumnNumber ) 
{
	if ( iXColumnNumber == INT_MAX ){
		iXColumnNumber = getXColumnCount() - 1 ;
	}
	
	// --------------------------------
	//	�L���b�V��������΁A�����Ԃ��܂��B
	// --------------------------------
	if ( m_zonecontXColumnZoneCache.size() > 0 ){
		return ( m_zonecontXColumnZoneCache[ iXColumnNumber ] ) ;
	}
	
	
	
	CdDcdZone	aCdDcdZone ;
	// --------------------------------
	//	iXColumnNumber ���Œ��
	// --------------------------------
	if ( iXColumnNumber < m_iXFixColumnCount ){
		DcdPos	iPos = pIfDcdTarget->getZone().getX().getPos() ;
		iPos += getXColumnsSize( pIfDcdTarget , 
			-1 , true , iXColumnNumber - 1 , true ) ;
		DcdSize iSize = getXColumnsSize( pIfDcdTarget , 
			iXColumnNumber , false , iXColumnNumber , false ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}				
	// --------------------------------
	//	iXColumnNumber ���X�N���[���A�E�g��
	// --------------------------------
	if ( m_iXFixColumnCount <= iXColumnNumber && 
			iXColumnNumber < m_iXFixafterColumnNumber ){
		DcdPos	iPos = pIfDcdTarget->getZone().getX().getPos() ;
		iPos += getXColumnsSize( pIfDcdTarget , 
			-1 , true , m_iXFixColumnCount - 1 , true ) ;
		//	�T�C�Y�̓[���ł�
		aCdDcdZone.setPos( iPos ).setSize( 0 ) ;
	}				
	// --------------------------------
	//	iXColumnNumber ���X�N���[���A�E�g��̂���
	// --------------------------------
	if ( m_iXFixafterColumnNumber <= iXColumnNumber ){
		DcdPos	iPos = pIfDcdTarget->getZone().getX().getPos() ;
		iPos += getXColumnsSize( pIfDcdTarget , 
			-1 ,true , m_iXFixColumnCount - 1 , true ) ;
		iPos += getXColumnsSize( pIfDcdTarget ,
			m_iXFixafterColumnNumber , false , iXColumnNumber - 1 , true ) ;
		DcdSize iSize = getXColumnsSize( pIfDcdTarget , 
			iXColumnNumber , false , iXColumnNumber , false ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}
	return ( aCdDcdZone ) ;
}
CdDcdZone	
CDcdGrid::getYColumnBorderZone( IfDcdTarget* pIfDcdTarget ,int iYColumnNumber )
{
	if ( iYColumnNumber == INT_MAX ){
		iYColumnNumber = getYColumnCount() - 1 ;
	}

	// --------------------------------
	//	�L���b�V��������΁A�����Ԃ��܂��B
	// --------------------------------
	if ( m_zonecontYColumnBorderZoneCache.size() > 0 ){
		return ( m_zonecontYColumnBorderZoneCache[ iYColumnNumber + 1 ] ) ;
	}


	CdDcdZone	aCdDcdZone ;

	// --------------------------------
	//	iYColumnNumber ���Œ��
	// --------------------------------
	if ( iYColumnNumber < m_iYFixColumnCount ){
		DcdPos	iPos = pIfDcdTarget->getZone().getY().getPos() ;
		iPos += getYColumnsSize( pIfDcdTarget , 
			-1 , true , iYColumnNumber  , false ) ;
		DcdSize iSize = getYColumnsSize( pIfDcdTarget , 
			iYColumnNumber , true , iYColumnNumber , true ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}				
	// --------------------------------
	//	iYColumnNumber ���X�N���[���A�E�g��
	// --------------------------------
	if ( m_iYFixColumnCount <= iYColumnNumber && 
			iYColumnNumber < m_iYFixafterColumnNumber ){
		DcdPos	iPos = pIfDcdTarget->getZone().getY().getPos() ;
		iPos += getYColumnsSize( pIfDcdTarget , 
			-1 , true , m_iYFixColumnCount - 1 , true ) ;
		//	�T�C�Y�̓[���ł�
		aCdDcdZone.setPos( iPos ).setSize( 0 ) ;
	}				
	// --------------------------------
	//	iYColumnNumber ���X�N���[���A�E�g��̂���
	// --------------------------------
	if ( m_iYFixafterColumnNumber <= iYColumnNumber ){
		DcdPos	iPos = pIfDcdTarget->getZone().getY().getPos() ;
		iPos += getYColumnsSize( pIfDcdTarget , 
			-1 ,true , m_iYFixColumnCount - 1  , true ) ;
		iPos += getYColumnsSize( pIfDcdTarget ,
			m_iYFixafterColumnNumber , false , iYColumnNumber , false ) ;
		DcdSize iSize = getYColumnsSize( pIfDcdTarget , 
			iYColumnNumber , true , iYColumnNumber , true ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}
	return ( aCdDcdZone ) ;
}
CdDcdZone	
CDcdGrid::getXColumnBorderZone( IfDcdTarget* pIfDcdTarget ,int iXColumnNumber )
{
	if ( iXColumnNumber == INT_MAX ){
		iXColumnNumber = getXColumnCount() - 1 ;
	}

	// --------------------------------
	//	�L���b�V��������΁A�����Ԃ��܂��B
	// --------------------------------
	if ( m_zonecontXColumnBorderZoneCache.size() > 0 ){
		return ( m_zonecontXColumnBorderZoneCache[ iXColumnNumber + 1 ] ) ;
	}

	CdDcdZone	aCdDcdZone ;

	// --------------------------------
	//	iXColumnNumber ���Œ��
	// --------------------------------
	if ( iXColumnNumber < m_iXFixColumnCount ){
		DcdPos	iPos = pIfDcdTarget->getZone().getX().getPos() ;
		iPos += getXColumnsSize( pIfDcdTarget , 
			-1 , true , iXColumnNumber  , false ) ;
		DcdSize iSize = getXColumnsSize( pIfDcdTarget , 
			iXColumnNumber , true , iXColumnNumber , true ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}				
	// --------------------------------
	//	iXColumnNumber ���X�N���[���A�E�g��
	// --------------------------------
	if ( m_iXFixColumnCount <= iXColumnNumber && 
			iXColumnNumber < m_iXFixafterColumnNumber ){
		DcdPos	iPos = pIfDcdTarget->getZone().getX().getPos() ;
		iPos += getXColumnsSize( pIfDcdTarget , 
			-1 , true , m_iXFixColumnCount - 1 , true ) ;
		//	�T�C�Y�̓[���ł�
		aCdDcdZone.setPos( iPos ).setSize( 0 ) ;
	}				
	// --------------------------------
	//	iXColumnNumber ���X�N���[���A�E�g��̂���
	// --------------------------------
	if ( m_iXFixafterColumnNumber <= iXColumnNumber ){
		DcdPos	iPos = pIfDcdTarget->getZone().getX().getPos() ;
		iPos += getXColumnsSize( pIfDcdTarget , 
			-1 ,true , m_iXFixColumnCount - 1  , true ) ;
		iPos += getXColumnsSize( pIfDcdTarget ,
			m_iXFixafterColumnNumber , false , iXColumnNumber , false ) ;
		DcdSize iSize = getXColumnsSize( pIfDcdTarget , 
			iXColumnNumber , true , iXColumnNumber , true ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}
	// --------------------------------
	return ( aCdDcdZone ) ;
}

CdDcdZoneXy	CDcdGrid::getCellZone( 
		IfDcdTarget* pIfDcdTarget , int iXColumnNumber , int iYColumnNumber ) 
{
	CdDcdZoneXy	zonexyRv ;
	
	CDcdGridCell*	pcellLefttop = getCell( iXColumnNumber , iYColumnNumber ) ;
	if ( pcellLefttop != NULL ){
		CdDcdZoneXy	zonexyLefttop( 
					getXColumnZone( pIfDcdTarget , iXColumnNumber ) ,
					getYColumnZone( pIfDcdTarget , iYColumnNumber ) 
		) ;
		
		if ( pcellLefttop->getAttachTo() != NULL ){
			//	���̃Z���Ɍ������Ă���Z��
			//	(0,0)-(0,0)��Ԃ��܂��B
			1 ;
		}	else if ( pcellLefttop->getYAttachCellCount() == 1 &&  
			pcellLefttop->getXAttachCellCount() == 1 ){
			//	�Ɨ������i��������Ă��Ȃ��A�������Ă��Ȃ��j�Z��
			zonexyRv = zonexyLefttop ;
		}	else	{	
			CDcdGridCell*	pcellRightbottom = NULL ;
			//	���̃Z���Ɍ�������Ă���Z��
			pcellRightbottom = getCell( 
				iXColumnNumber + pcellLefttop->getXAttachCellCount() - 1 ,
				iYColumnNumber + pcellLefttop->getYAttachCellCount() - 1  
			) ;

			CdDcdZoneXy	zonexyRightbottom( 
				getXColumnZone( pIfDcdTarget , 
					getXColumnNumberOfCell( pcellRightbottom ) ) , 
				getYColumnZone( pIfDcdTarget , 
					getYColumnNumberOfCell( pcellRightbottom ) ) 
			) ;


			zonexyRv.setX( CdDcdZone( 
				zonexyLefttop.getX().getPos() , 
				zonexyRightbottom.getX().getEndPos() - 
					zonexyLefttop.getX().getPos() ) ) ;
			zonexyRv.setY( CdDcdZone( 
				zonexyLefttop.getY().getPos() , 
				zonexyRightbottom.getY().getEndPos() - 
					zonexyLefttop.getY().getPos() ) ) ;
			
		}
	}
	return ( zonexyRv ) ;
}


int CDcdGrid::getYColumnNumberOfPos( 
		IfDcdTarget* pIfDcdTarget , int iPos , bool* pbIsBorder ) 
{
	int		iColumnNumber = -2 ;
	bool	bIsBorder = false ;
	// --------------------------------
	//	���E��͈̔͊O/���E��̋��E��
	// --------------------------------
	{
		CdDcdZone	aCdDcdBorderZone = getYColumnBorderZone( 
			pIfDcdTarget , -1 ) ;
		if ( iPos < aCdDcdBorderZone.getPos() ){
			//	���E��͈̔͊O
			iColumnNumber = -1 ;
			bIsBorder = false ;
		}	else if ( aCdDcdBorderZone.IsInner( iPos ) ){
			//	���E��̋��E��
			iColumnNumber = -1 ;
			bIsBorder = true ;
			
		}
	}
	//iColumnNumber = -1 �Ȃ�A���E��͈̔͊O/���E��̋��E��
	//	-2 �Ȃ�A��ԍ�������ł��B

	// --------------------------------
	//	�O���b�h�͈͓�
	// --------------------------------
	if ( iColumnNumber == -2 ){
		for ( iColumnNumber = 0 ; 
				iColumnNumber < getYColumnCount() ;
				iColumnNumber ++ ){
			CdDcdZone	aCdDcdZone = getYColumnZone( 
				pIfDcdTarget , iColumnNumber ) ;
			CdDcdZone	aCdDcdBorderZone = getYColumnBorderZone( 
				pIfDcdTarget , iColumnNumber ) ;

			if ( aCdDcdZone.IsInner( iPos ) ){
				//	��͈͓̔�
				bIsBorder = false ;
				break ;
			}	else if ( aCdDcdBorderZone.IsInner( iPos ) ){
				//	��͈͓̔�
				bIsBorder = true ;
				break ;
			}
		}
	}


	// --------------------------------
	if ( pbIsBorder != NULL ){
		*pbIsBorder = bIsBorder ;
	}
	return ( iColumnNumber ) ;
}

int CDcdGrid::getXColumnNumberOfPos( 
		IfDcdTarget* pIfDcdTarget , int iPos , bool* pbIsBorder ) 
{
	int		iColumnNumber = -2 ;
	bool	bIsBorder = false ;
	// --------------------------------
	//	���E��͈̔͊O/���E��̋��E��
	// --------------------------------
	{
		CdDcdZone	aCdDcdBorderZone = getXColumnBorderZone( 
			pIfDcdTarget , -1 ) ;
		if ( iPos < aCdDcdBorderZone.getPos() ){
			//	���E��͈̔͊O
			iColumnNumber = -1 ;
			bIsBorder = false ;
		}	else if ( aCdDcdBorderZone.IsInner( iPos ) ){
			//	���E��̋��E��
			iColumnNumber = -1 ;
			bIsBorder = true ;
			
		}
	}
	//iColumnNumber = -1 �Ȃ�A���E��͈̔͊O/���E��̋��E��
	//	-2 �Ȃ�A��ԍ�������ł��B

	// --------------------------------
	//	�O���b�h�͈͓�
	// --------------------------------
	if ( iColumnNumber == -2 ){
		for ( iColumnNumber = 0 ; 
				iColumnNumber < getXColumnCount() ;
				iColumnNumber ++ ){
			CdDcdZone	aCdDcdZone = getXColumnZone( 
				pIfDcdTarget , iColumnNumber ) ;
			CdDcdZone	aCdDcdBorderZone = getXColumnBorderZone( 
				pIfDcdTarget , iColumnNumber ) ;

			if ( aCdDcdZone.IsInner( iPos ) ){
				//	��͈͓̔�
				bIsBorder = false ;
				break ;
			}	else if ( aCdDcdBorderZone.IsInner( iPos ) ){
				//	��͈͓̔�
				bIsBorder = true ;
				break ;
			}
		}
	}


	// --------------------------------
	if ( pbIsBorder != NULL ){
		*pbIsBorder = bIsBorder ;
	}
	return ( iColumnNumber ) ;
}

CDcdGridCell* CDcdGrid::getCellOfPos( 
		IfDcdTarget* pIfDcdTarget , const CdDcdPosXy& aCdDcdPosXy ) 
{
	bool bXIsBorder = false ;	
	int iXColumnNumber = getXColumnNumberOfPos( 
		pIfDcdTarget , aCdDcdPosXy.getX() , &bXIsBorder ) ;
	bool bYIsBorder = false ;	
	int iYColumnNumber = getYColumnNumberOfPos( 
		pIfDcdTarget , aCdDcdPosXy.getY() , &bYIsBorder ) ;
	if ( !bXIsBorder && !bYIsBorder && 
		0 <= iXColumnNumber && iXColumnNumber < getXColumnCount() &&
		0 <= iYColumnNumber && iYColumnNumber < getYColumnCount() ){
		CDcdGridCell*	pCell = getCell( iXColumnNumber , iYColumnNumber ) ;
		if ( pCell != NULL ){
			if ( pCell->getAttachTo() != NULL ){
				//	Attached �Z�����w�肵���ꍇ�́A
				//	Attach �Z���ɕϊ�
				pCell = pCell->getAttachTo() ;
			}
		}
		return ( pCell ) ;
	}
	return ( NULL ) ;	

}

	// ********************************
	///	@name	�X�N���[��
	// ********************************
int	CDcdGrid::getXFixColumnCount() 
{
	return ( m_iXFixColumnCount ) ;
}
CDcdGrid& CDcdGrid::setXFixColumnCount( int ev ) 
{
	m_iXFixColumnCount = ev ;
	adjustProp() ;
	return ( *this ) ;
}
int	CDcdGrid::getXFixafterColumnNumber() 
{
	return ( m_iXFixafterColumnNumber ) ;
}
CDcdGrid& CDcdGrid::setXFixafterColumnNumber( int ev ) 
{
	m_iXFixafterColumnNumber = ev ;
	adjustProp() ;
	return ( *this ) ;
}

int	CDcdGrid::getYFixColumnCount() 
{
	return ( m_iYFixColumnCount ) ;
}
CDcdGrid& CDcdGrid::setYFixColumnCount( int ev ) 
{
	m_iYFixColumnCount = ev ;
	adjustProp() ;
	return ( *this ) ;
}
int	CDcdGrid::getYFixafterColumnNumber() 
{
	return ( m_iYFixafterColumnNumber ) ;
}
CDcdGrid& CDcdGrid::setYFixafterColumnNumber( int ev ) 
{
	m_iYFixafterColumnNumber = ev ;
	adjustProp() ;
	return ( *this ) ;
}

int CDcdGrid::calcXFixafterColumnNumberPagemove( IfDcdTarget* pIfDcdTarget , 
		int iFixafterColumnNumber , bool bPagedown ) 
{
	int iRv = 0 ;
	if ( !bPagedown ){
		// --------------------------------
		//	Pageup
		// --------------------------------
		{
			int iFixafterColumnNumberNew = 
				calcXFixafterColumnNumberMinForColumn( 
					pIfDcdTarget , getXFixafterColumnNumber() - 1 ) ;
			if ( iFixafterColumnNumberNew < getXFixColumnCount() ){
				iFixafterColumnNumberNew = getXFixColumnCount() ;
			}
			if ( iFixafterColumnNumberNew == iFixafterColumnNumber ){
				iFixafterColumnNumberNew = iFixafterColumnNumber - 1 ;
			}					
			iRv = iFixafterColumnNumberNew ;
		}
	}	else	{
		// --------------------------------
		//	Pagedown
		// --------------------------------
		{
			int iFixafterColumnNumberNew = 
				getXColumnNumberMaxInDcdTarget( pIfDcdTarget ) ;
			if ( iFixafterColumnNumberNew < 0 )
			{
				//	iFixafterColumnNumberNew �����̐��Ȃ̂́A
				//	pIfDcdTarget �ɑS�̂�\���ł���񂪈��
				//	�Ȃ��ꍇ�ł��B
				//	���̏ꍇ�́A�������Ɏ��̗�Ƃ��ׂ��ł��B
				iFixafterColumnNumberNew = iFixafterColumnNumber   ;

			}	
			iFixafterColumnNumberNew ++ ;
			if ( iFixafterColumnNumberNew == iFixafterColumnNumber ){
				iFixafterColumnNumberNew = iFixafterColumnNumber + 1 ;
			}
			if ( iFixafterColumnNumberNew >= getXColumnCount() ){
				iFixafterColumnNumberNew = getXColumnCount() ;
			}
			iRv = iFixafterColumnNumberNew ;
		}

	}
	return ( iRv ) ;
}
	
int CDcdGrid::calcYFixafterColumnNumberPagemove( IfDcdTarget* pIfDcdTarget , 
		int iFixafterColumnNumber , bool bPagedown ) 
{
	int iRv = 0 ;
	if ( !bPagedown ){
		// --------------------------------
		//	Pageup
		// --------------------------------
		{
			int iFixafterColumnNumberNew = 
				calcYFixafterColumnNumberMinForColumn( 
					pIfDcdTarget , getYFixafterColumnNumber() - 1 ) ;
			if ( iFixafterColumnNumberNew < getYFixColumnCount() ){
				iFixafterColumnNumberNew = getYFixColumnCount() ;
			}
			if ( iFixafterColumnNumberNew == iFixafterColumnNumber ){
				iFixafterColumnNumberNew = iFixafterColumnNumber - 1 ;
			}					
				
			

			iRv = iFixafterColumnNumberNew ;
		}
	}	else	{
		// --------------------------------
		//	Pagedown
		// --------------------------------
		{
			int iFixafterColumnNumberNew = 
				getYColumnNumberMaxInDcdTarget( pIfDcdTarget ) ;
			if ( iFixafterColumnNumberNew < 0 )
			{
				//	iFixafterColumnNumberNew �����̐��Ȃ̂́A
				//	pIfDcdTarget �ɑS�̂�\���ł���񂪈��
				//	�Ȃ��ꍇ�ł��B
				//	���̏ꍇ�́A�������Ɏ��̗�Ƃ��ׂ��ł��B
				iFixafterColumnNumberNew = iFixafterColumnNumber   ;
			}	
			iFixafterColumnNumberNew ++ ;


			if ( iFixafterColumnNumberNew == iFixafterColumnNumber ){
				iFixafterColumnNumberNew = iFixafterColumnNumber + 1 ;
			}					
			if ( iFixafterColumnNumberNew >= getYColumnCount() ){
				iFixafterColumnNumberNew = getYColumnCount() ;
			}
			iRv = iFixafterColumnNumberNew ;
		}

	}
	return ( iRv ) ;
}




	// ********************************
	///	@name	�Z���̌���
	// ********************************

CdDcdZone	CDcdGrid::getYColumnZoneOverlap( 
			IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) 
{
	if ( iYColumnNumber == INT_MAX ){
		iYColumnNumber = getYColumnCount() - 1 ;
	}

	// --------------------------------
	//	�L���b�V��������΁A�����Ԃ��܂��B
	// --------------------------------
	if ( m_zonecontYColumnZoneOverlapCache.size() > 0 ){
		return ( m_zonecontYColumnZoneOverlapCache[ iYColumnNumber ] ) ;
	}


	CdDcdZone	aCdDcdZone ;
	// --------------------------------
	//	iYColumnNumber ���Œ��
	// --------------------------------
	if ( iYColumnNumber < m_iYFixColumnCount ){
		DcdPos	iPos = pIfDcdTarget->getZone().getY().getPos() ;
		iPos += getYColumnsSize( pIfDcdTarget , 
			-1 , true , iYColumnNumber - 1 , true ) ;
		DcdSize iSize = getYColumnsSize( pIfDcdTarget , 
			iYColumnNumber , false , iYColumnNumber , false ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}				
	// --------------------------------
	//	iYColumnNumber ���X�N���[���A�E�g��,�X�N���[���A�E�g��̂���
	// --------------------------------
	if ( m_iYFixColumnCount <= iYColumnNumber  ){
		DcdPos	iPos = pIfDcdTarget->getZone().getY().getPos() ;
		iPos += getYColumnsSize( pIfDcdTarget , 
			-1 , true , iYColumnNumber - 1 , true ) ;
		iPos -= getYColumnsSize( pIfDcdTarget , 
			m_iYFixColumnCount , false , m_iYFixafterColumnNumber - 1 , true ) ;
		DcdSize iSize = getYColumnsSize( pIfDcdTarget , 
			iYColumnNumber , false , iYColumnNumber , false ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}				
	return ( aCdDcdZone ) ;
}

CdDcdZone	CDcdGrid::getXColumnZoneOverlap( 
			IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) 
{
	if ( iXColumnNumber == INT_MAX ){
		iXColumnNumber = getXColumnCount() - 1 ;
	}

	// --------------------------------
	//	�L���b�V��������΁A�����Ԃ��܂��B
	// --------------------------------
	if ( m_zonecontXColumnZoneOverlapCache.size() > 0 ){
		return ( m_zonecontXColumnZoneOverlapCache[ iXColumnNumber ] ) ;
	}



	CdDcdZone	aCdDcdZone ;
	// --------------------------------
	//	iXColumnNumber ���Œ��
	// --------------------------------
	if ( iXColumnNumber < m_iXFixColumnCount ){
		DcdPos	iPos = pIfDcdTarget->getZone().getX().getPos() ;
		iPos += getXColumnsSize( pIfDcdTarget , 
			-1 , true , iXColumnNumber - 1 , true ) ;
		DcdSize iSize = getXColumnsSize( pIfDcdTarget , 
			iXColumnNumber , false , iXColumnNumber , false ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}				
	// --------------------------------
	//	iXColumnNumber ���X�N���[���A�E�g��,�X�N���[���A�E�g��̂���
	// --------------------------------
	if ( m_iXFixColumnCount <= iXColumnNumber  ){
		DcdPos	iPos = pIfDcdTarget->getZone().getX().getPos() ;
		iPos += getXColumnsSize( pIfDcdTarget , 
			-1 , true , iXColumnNumber - 1 , true ) ;
		iPos -= getXColumnsSize( pIfDcdTarget , 
			m_iXFixColumnCount , false , m_iXFixafterColumnNumber - 1 , true ) ;
		DcdSize iSize = getXColumnsSize( pIfDcdTarget , 
			iXColumnNumber , false , iXColumnNumber , false ) ;
		aCdDcdZone.setPos( iPos ).setSize( iSize ) ;
	}				
	// --------------------------------
	return ( aCdDcdZone ) ;
}

CdDcdZoneXy	CDcdGrid::getCellZoneOverlap( 
	IfDcdTarget* pIfDcdTarget , int iXColumnNumber , int iYColumnNumber ) 
{
	CdDcdZoneXy	zonexyRv ;
	
	CDcdGridCell*	pcellLefttop = getCell( iXColumnNumber , iYColumnNumber ) ;
	if ( pcellLefttop != NULL ){
		CdDcdZoneXy	zonexyLefttop( 
					getXColumnZoneOverlap( pIfDcdTarget , iXColumnNumber ) ,
					getYColumnZoneOverlap( pIfDcdTarget , iYColumnNumber ) 
		) ;
		
		if ( pcellLefttop->getAttachTo() != NULL ){
			//	���̃Z���Ɍ������Ă���Z��
			1 ;
		}	else if ( pcellLefttop->getYAttachCellCount() == 1 &&  
			pcellLefttop->getXAttachCellCount() == 1 ){
			//	�Ɨ������i��������Ă��Ȃ��A�������Ă��Ȃ��j�Z��
			zonexyRv = zonexyLefttop ;
		}	else	{
			CDcdGridCell*	pcellRightbottom = NULL ;
			//	���̃Z���Ɍ�������Ă���Z��
			pcellRightbottom = getCell( 
				iXColumnNumber + 
					pcellLefttop->getXAttachCellCount() - 1 ,
				iYColumnNumber + 
					pcellLefttop->getYAttachCellCount() - 1  
			) ;

			CdDcdZoneXy	zonexyRightbottom( 
				getXColumnZoneOverlap( pIfDcdTarget , 
					getXColumnNumberOfCell( pcellRightbottom ) ) , 
				getYColumnZoneOverlap( pIfDcdTarget , 
					getYColumnNumberOfCell( pcellRightbottom ) ) 
			) ;

			zonexyRv.setX( CdDcdZone( 
				zonexyLefttop.getX().getPos() , 
				zonexyRightbottom.getX().getEndPos() - 
					zonexyLefttop.getX().getPos() ) ) ;
			zonexyRv.setY( CdDcdZone( 
				zonexyLefttop.getY().getPos() , 
				zonexyRightbottom.getY().getEndPos() - 
					zonexyLefttop.getY().getPos() ) ) ;
				
		}
	}
	return ( zonexyRv ) ;
}
	
	// ********************************
	//	@name	����
	// ********************************
CDcdGridCell* CDcdGrid::calcMovedCell( 
	CDcdGridCell* pCDcdGridCell ,
	int iXColumnMoveCount , int iYColumnMoveCount , 
	bool bSkipScrolloutColumn ) 
{
	int iXColumnNumber = getXColumnNumberOfCell( pCDcdGridCell ) ;
	int iYColumnNumber = getYColumnNumberOfCell( pCDcdGridCell ) ;

	// --------------------------------	
	//	iXColumnNumber ���ړ�
	// --------------------------------	
	while ( 0 < iXColumnMoveCount ){
		CDcdGridCell*	pCell = getCell( iXColumnNumber , iYColumnNumber ) ;
		int iNewColumnNumber = iXColumnNumber + pCell->getXAttachCellCount() ;
		pCell = getCell( iNewColumnNumber , iYColumnNumber ) ;
		if( pCell == NULL ){
			break ;
		}
		iXColumnNumber = iNewColumnNumber ;


		//	bSkipScrolloutColumn ��
		//	�^�ŁA Cell(iXColumnNumber,iYColumnNumber)��
		//	 ScrolloutColumn �ł���Ȃ�A
		//	ScrolloutColumn ���щz���Ĉړ����܂�
		//	�i���[�v�J�E���^ iXColumnMoveCount �����炵�܂���j�B
		//
		//	�������A Cell(iXColumnNumber,iYColumnNumber) ��
		//	�����Z���ŁA
		//	�팋���Z���̈ꕔ�� ScrolloutColumn ��
		//	�Ȃ��Ă��Ȃ��ꍇ�́A
		//	���̃Z���ւ̈ړ��͉\�Ƃ��܂��B
		if ( bSkipScrolloutColumn ){
			if ( getXFixColumnCount() <= iXColumnNumber && 
					iXColumnNumber < getXFixafterColumnNumber() ){
				pCell = getCell( iXColumnNumber , iYColumnNumber ) ;
				if ( iXColumnNumber + pCell->getXAttachCellCount() <=
						getXFixafterColumnNumber() ){
					//	�����Z���ł����A�A�S���̔팋���Z����
					//	 ScrolloutColumn �ɂȂ��Ă��܂��B
					//
					//	ScrolloutColumn ���щz���Ĉړ����܂�
					//	�i���[�v�J�E���^ iXColumnMoveCount �����炵�܂���j�B
					continue ;
				}
			}
		}


		iXColumnMoveCount -- ;
	}
	while ( 0 > iXColumnMoveCount ){
		CDcdGridCell*	pCell = getCell( iXColumnNumber - 1 , iYColumnNumber );

		if( pCell == NULL ){
			break ;
		}
		if ( pCell->getAttachTo() != NULL ){
			pCell = pCell->getAttachTo() ;
		}
		iXColumnNumber = iXColumnNumber - pCell->getXAttachCellCount() ;

		//	bSkipScrolloutColumn ��
		//	�^�ŁA Cell(iXColumnNumber,iYColumnNumber)��
		//	 ScrolloutColumn �ł���Ȃ�A
		//	ScrolloutColumn ���щz���Ĉړ����܂�
		//	�i���[�v�J�E���^ iXColumnMoveCount �����炵�܂���j�B
		//
		//	�������A Cell(iXColumnNumber,iYColumnNumber) ��
		//	�����Z���ŁA
		//	�팋���Z���̈ꕔ�� ScrolloutColumn ��
		//	�Ȃ��Ă��Ȃ��ꍇ�́A
		//	���̃Z���ւ̈ړ��͉\�Ƃ��܂��B
		if ( bSkipScrolloutColumn ){
			if ( getXFixColumnCount() <= iXColumnNumber && 
					iXColumnNumber < getXFixafterColumnNumber() ){
				pCell = getCell( iXColumnNumber , iYColumnNumber ) ;
				if ( iXColumnNumber + pCell->getXAttachCellCount() <=
						getXFixafterColumnNumber() ){
					//	�����Z���ł����A�A�S���̔팋���Z����
					//	 ScrolloutColumn �ɂȂ��Ă��܂��B
					//
					//	ScrolloutColumn ���щz���Ĉړ����܂�
					//	�i���[�v�J�E���^ iXColumnMoveCount �����炵�܂���j�B
					continue ;
				}
			}
		}

		iXColumnMoveCount ++ ;
	}
	// --------------------------------	
	//	iYColumnNumber ���ړ�
	// --------------------------------	

	while ( 0 < iYColumnMoveCount ){
		CDcdGridCell*	pCell = getCell( iXColumnNumber , iYColumnNumber ) ;
		int iNewColumnNumber = iYColumnNumber + pCell->getYAttachCellCount() ;
		pCell = getCell( iXColumnNumber , iNewColumnNumber ) ;
		if( pCell == NULL ){
			break ;
		}
		iYColumnNumber = iNewColumnNumber ;

		//	bSkipScrolloutColumn ��
		//	�^�ŁA Cell(iXColumnNumber,iYColumnNumber)��
		//	 ScrolloutColumn �ł���Ȃ�A
		//	ScrolloutColumn ���щz���Ĉړ����܂�
		//	�i���[�v�J�E���^ iYColumnMoveCount �����炵�܂���j�B
		//
		//	�������A Cell(iXColumnNumber,iYColumnNumber) ��
		//	�����Z���ŁA
		//	�팋���Z���̈ꕔ�� ScrolloutColumn ��
		//	�Ȃ��Ă��Ȃ��ꍇ�́A
		//	���̃Z���ւ̈ړ��͉\�Ƃ��܂��B
		if ( bSkipScrolloutColumn ){
			if ( getYFixColumnCount() <= iYColumnNumber && 
					iYColumnNumber < getYFixafterColumnNumber() ){
				pCell = getCell( iXColumnNumber , iYColumnNumber ) ;
				if ( iYColumnNumber + pCell->getYAttachCellCount() <=
						getYFixafterColumnNumber() ){
					//	�����Z���ł����A�A�S���̔팋���Z����
					//	 ScrolloutColumn �ɂȂ��Ă��܂��B
					//
					//	ScrolloutColumn ���щz���Ĉړ����܂�
					//	�i���[�v�J�E���^ iYColumnMoveCount �����炵�܂���j�B
					continue ;
				}
			}
		}


		iYColumnMoveCount -- ;
	}
	while ( 0 > iYColumnMoveCount ){
		CDcdGridCell*	pCell = getCell( iXColumnNumber , iYColumnNumber - 1 ) ;
		if( pCell == NULL ){
			break ;
		}
		if ( pCell->getAttachTo() != NULL ){
			pCell = pCell->getAttachTo() ;
		}	
		iYColumnNumber = iYColumnNumber - pCell->getYAttachCellCount() ;

		//	bSkipScrolloutColumn ��
		//	�^�ŁA Cell(iXColumnNumber,iYColumnNumber)��
		//	 ScrolloutColumn �ł���Ȃ�A
		//	ScrolloutColumn ���щz���Ĉړ����܂�
		//	�i���[�v�J�E���^ iYColumnMoveCount �����炵�܂���j�B
		//
		//	�������A Cell(iXColumnNumber,iYColumnNumber) ��
		//	�����Z���ŁA
		//	�팋���Z���̈ꕔ�� ScrolloutColumn ��
		//	�Ȃ��Ă��Ȃ��ꍇ�́A
		//	���̃Z���ւ̈ړ��͉\�Ƃ��܂��B
		if ( bSkipScrolloutColumn ){
			if ( getYFixColumnCount() <= iYColumnNumber && 
					iYColumnNumber < getYFixafterColumnNumber() ){
				pCell = getCell( iXColumnNumber , iYColumnNumber ) ;
				if ( iYColumnNumber + pCell->getYAttachCellCount() <=
						getYFixafterColumnNumber() ){
					//	�����Z���ł����A�A�S���̔팋���Z����
					//	 ScrolloutColumn �ɂȂ��Ă��܂��B
					//
					//	ScrolloutColumn ���щz���Ĉړ����܂�
					//	�i���[�v�J�E���^ iYColumnMoveCount �����炵�܂���j�B
					continue ;
				}
			}
		}

		iYColumnMoveCount ++ ;
	}

	// --------------------------------
	//	iXColumnNumber,iYColumnNumber ��
	//	�팋���Z���̏ꍇ�́A
	//	�����Z����Ԃ�
	// --------------------------------
	CDcdGridCell*	pCell = getCell( iXColumnNumber , iYColumnNumber ) ;
	{
		if ( pCell->getAttachTo() != NULL ){
			pCell = pCell->getAttachTo() ;
		}
	}
	return( pCell ) ;
}


int CDcdGrid::calcXFixafterColumnNumberMinForColumn( 
		IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) 
{
	// --------------------------------
	//	FixColumnNumber ���ǂ����̔���
	// --------------------------------
	if ( !( getXFixColumnCount() <= iXColumnNumber && 
			iXColumnNumber < getXColumnCount() ) ){
		return ( -1 ) ;	
		//	iXColumnNumber �� FixColumn �̏ꍇ�́A�G���[������ -1 ��Ԃ��܂��B
	}
	// --------------------------------
	//	�X�N���[������̈�����߂�
	// --------------------------------
	DcdSize	sizeScroll ;
	{
		CdDcdZoneXy	zoneTarget = pIfDcdTarget->getZone() ;
		{
			DcdSize sizeFix = getXColumnBorderZone( 
				pIfDcdTarget , getXFixColumnCount() - 1 )
				.getEndPos() - zoneTarget.getX().getPos() ;
			sizeScroll = zoneTarget.getX().getSize() - sizeFix ;
		}
	}
	//sizeScroll = �E�C���h�E��ŁA�X�N���[�����s���̈�
	//	�i�Œ�񕔕����������̈�j
	
	// --------------------------------
	//	iFixafterColumnNumberMinForColumn 
	//	�����߂�B
	// --------------------------------
	int iFixafterColumnNumberMinForColumn = iXColumnNumber ;
	
	for ( iFixafterColumnNumberMinForColumn = iXColumnNumber ;
			iFixafterColumnNumberMinForColumn > 
				getXFixColumnCount() ; 
			iFixafterColumnNumberMinForColumn -- ){
		DcdSize	sizeColumns = getXColumnsSize( 
			pIfDcdTarget ,
			iFixafterColumnNumberMinForColumn - 1 , false , 
			iXColumnNumber , true ) ;
		
		if ( sizeScroll < sizeColumns ){
			break ;
		}
	}
	
	return ( iFixafterColumnNumberMinForColumn ) ;
	 
	
}
int CDcdGrid::calcYFixafterColumnNumberMinForColumn(
		IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) 
{
	// --------------------------------
	//	FixColumnNumber ���ǂ����̔���
	// --------------------------------
	if ( !( getYFixColumnCount() <= iYColumnNumber && 
			iYColumnNumber < getYColumnCount() ) ){
		return ( -1 ) ;	
		//	iYColumnNumber �� FixColumn �̏ꍇ�́A�G���[������ -1 ��Ԃ��܂��B
	}
	// --------------------------------
	//	�X�N���[������̈�����߂�
	// --------------------------------
	DcdSize	sizeScroll ;
	{
		CdDcdZoneXy	zoneTarget = pIfDcdTarget->getZone() ;
		{
			DcdSize sizeFix = getYColumnBorderZone( 
				pIfDcdTarget , getYFixColumnCount() - 1 )
				.getEndPos() - zoneTarget.getY().getPos() ;
			sizeScroll = zoneTarget.getY().getSize() - sizeFix ;
		}
	}
	//sizeScroll = �E�C���h�E��ŁA�X�N���[�����s���̈�
	//	�i�Œ�񕔕����������̈�j
	
	// --------------------------------
	//	iFixafterColumnNumberMinForColumn 
	//	�����߂�B
	// --------------------------------
	int iFixafterColumnNumberMinForColumn = iYColumnNumber ;
	
	for ( iFixafterColumnNumberMinForColumn = iYColumnNumber ;
			iFixafterColumnNumberMinForColumn > 
				getYFixColumnCount() ; 
			iFixafterColumnNumberMinForColumn -- ){
		DcdSize	sizeColumns = getYColumnsSize( 
			pIfDcdTarget ,
			iFixafterColumnNumberMinForColumn - 1 , false , 
			iYColumnNumber , true ) ;
		
		if ( sizeScroll < sizeColumns ){
			break ;
		}
	}
	
	return ( iFixafterColumnNumberMinForColumn ) ;
}

int CDcdGrid::getXColumnNumberMaxInDcdTarget( 
		IfDcdTarget* pIfDcdTarget ) 
{
	DcdPos posEndPos = pIfDcdTarget->getZone().getX().getEndPos() ;
	int iColumnNumber = getXColumnNumberOfPos( 
		pIfDcdTarget , posEndPos , NULL ) - 1 ;
	if ( m_iXFixColumnCount <= iColumnNumber && 
			iColumnNumber < m_iXFixafterColumnNumber ){
		iColumnNumber = m_iXFixColumnCount - 1 ;
	}
	if ( iColumnNumber == -2 ){
		iColumnNumber = -1 ;
	}
	return ( iColumnNumber ) ;
}
	
int CDcdGrid::getYColumnNumberMaxInDcdTarget( 
		IfDcdTarget* pIfDcdTarget ) 
{
	DcdPos posEndPos = pIfDcdTarget->getZone().getY().getEndPos() ;
	int iColumnNumber = getYColumnNumberOfPos( 
		pIfDcdTarget , posEndPos , NULL ) - 1 ;
	if ( m_iYFixColumnCount <= iColumnNumber && 
			iColumnNumber < m_iYFixafterColumnNumber ){
		iColumnNumber = m_iYFixColumnCount - 1 ;
	}
	if ( iColumnNumber == -2 ){
		iColumnNumber = -1 ;
	}
	return ( iColumnNumber ) ;
}

} //namespace DcdGrid
} //namespace DcDrawLib
