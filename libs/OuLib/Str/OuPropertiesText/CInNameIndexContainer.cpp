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
/** @file */
//$Id: CInNameIndexContainer.cpp 286 2016-06-05 08:57:24Z okm $

#include "CInNameIndexContainer.h"

#include <deque>
#include <string>
#include <map>

namespace OuLib{
namespace Str{
namespace OuPropertiesText{


	// ********************************
	//	�R���X�g���N�^
	// ********************************
CInNameIndexContainer::CInNameIndexContainer():
	m_iNodeCount( 0 ) 
{
}
CInNameIndexContainer::~CInNameIndexContainer()
{
}
	// ********************************
	//@name	Mu
	// ********************************
int	CInNameIndexContainer::size()const 
{
	return m_iNodeCount ;
}
	// ********************************
	//@name	Mui
	// ********************************
int CInNameIndexContainer::insert( const std::string& element , int iIndex ) 
{
	if ( iIndex == INT_MAX )
	{
		iIndex = m_iNodeCount ;
	}
	if ( !( 0 <= iIndex && iIndex <= m_iNodeCount ) ) 
	{
		return -1 ;
	}

	// --------------------------------
	// iIndex �ȏ�̒l������ Index �͂��ׂĉ��Z
	// --------------------------------

	int iAddCount = m_iNodeCount - iIndex ;
	//iAddCount = iIndex�ȏ�̒l������ m_NameIndexCont[][] �̐�
	//	���̒l�́A iIndex�ȏ�̒l�������邽�тɌ��Z���܂��B
	//	0�ɂȂ�����A���̏����͒��f���܂��B

	for ( NameIndexCont::iterator ite = m_NameIndexCont.begin() ;
		0 < iAddCount && ite != m_NameIndexCont.end() ;
		ite ++ ) 
	{
		InNameIndexCont&	aInNameIndexCont = ite->second ;
		int idxInNameIndex ;
		for ( idxInNameIndex = 0 ;
			idxInNameIndex < (int)aInNameIndexCont.size() ;
			idxInNameIndex ++ ) 
		{
			if ( aInNameIndexCont[idxInNameIndex] >= iIndex )
			{
				aInNameIndexCont[idxInNameIndex] ++ ;
				iAddCount -- ;
			}
		}
	}

	// --------------------------------
	// iIndex ��}��
	// --------------------------------
	{
		NameIndexCont::iterator ite = m_NameIndexCont.find( element ) ;
		if ( ite == m_NameIndexCont.end() )
		{
			m_NameIndexCont[element] = InNameIndexCont() ;
		}
		InNameIndexCont&	aInNameIndexCont = m_NameIndexCont[element] ;
		int idxInNameIndex = -1 ;
		int idxLeft = 0 ;
		int idxRight = (int)aInNameIndexCont.size() - 1 ;
		while ( idxInNameIndex == -1 && idxLeft <= idxRight )
		{
			int iCentral = ( idxLeft + idxRight ) / 2 ;
			if ( aInNameIndexCont[iCentral] == iIndex )
			{
				idxInNameIndex = iCentral ;
			}
			else if ( iIndex <  aInNameIndexCont[iCentral] )
			{
				idxRight = iCentral - 1 ;
			}
			else if ( aInNameIndexCont[iCentral]  < iIndex )
			{
				idxLeft = iCentral + 1 ;
			}
		}
		//  3   5    7
		//	�ƕ���ł��鎞�� 4 ����������ƁA
		//  L   C    R
		//  LCR
		//	�ƂȂ�A���́A
		//  CR  L
		//	�ƂȂ�܂��B���̏ꍇ�́A�}�����ׂ��ʒu��L�̏ꏊ�ł�
		//
		//  3   5    7
		//	�ƕ���ł��鎞�� 2 ����������ƁA
		//  L   C    R
		//  LCR
		//	�ƂȂ�A���́A
		//R CL
		//	�ƂȂ�܂��B���̏ꍇ�ł��A�}�����ׂ��ʒu��L�̏ꏊ�ł�
		//
		//  3   5    7
		//	�ƕ���ł��鎞�� 9 ����������ƁA
		//  L   C    R
		//          LCR
		//	�ƂȂ�A���́A
		//          RC    L
		//	�ƂȂ�܂��B���̏ꍇ�ł��A�}�����ׂ��ʒu��L�̏ꏊ�ł�
		//
		//
		if ( idxRight < idxLeft )
		{
			//	�}���ʒu������
			idxInNameIndex = idxLeft ;
		}
		aInNameIndexCont.insert( 
			aInNameIndexCont.begin() + idxInNameIndex , 
			iIndex ) ;
		m_iNodeCount ++ ;
	}

	return 0 ;
}
	
int CInNameIndexContainer::erase( int iIndex  , int iSize ) 
{
	if ( iIndex == INT_MAX && iSize == INT_MAX )
	{
		return -1 ;
	}
	if ( iIndex == INT_MAX )
	{
		iIndex = m_iNodeCount - iSize ;
	}
	if ( iSize == INT_MAX )
	{
		iSize = m_iNodeCount - iIndex ;
	}
	if ( !( 0 <= iIndex && iIndex+iSize <= m_iNodeCount ) ) 
	{
		return -1 ;
	}


	//iIndex �ȏ�AiIndex + iSize �����̒l���폜
	//iIndex + iSize �ȏ�̒l�́A iSize �����Z
	{
		for ( NameIndexCont::iterator ite = m_NameIndexCont.begin() ;
			ite != m_NameIndexCont.end() ;
			ite ++ ) 
		{
			InNameIndexCont&	aInNameIndexCont = ite->second ;
			int idxInNameIndex ;
			for ( idxInNameIndex = 0 ;
				idxInNameIndex < (int)aInNameIndexCont.size() ;
				idxInNameIndex ++ ) 
			{
				if ( iIndex <= aInNameIndexCont[idxInNameIndex] && 
					aInNameIndexCont[idxInNameIndex] < iIndex + iSize )
				{
					aInNameIndexCont.erase( 
						aInNameIndexCont.begin() + idxInNameIndex ) ;
					m_iNodeCount --;
					idxInNameIndex -- ;
				}
				else if ( iIndex + iSize <= aInNameIndexCont[idxInNameIndex] )
				{
					aInNameIndexCont[idxInNameIndex] -= iSize ;
				}
			}
		}
	}
	//	��̃R���e�i���폜
	{
		for ( NameIndexCont::iterator ite = m_NameIndexCont.begin() ;
			ite != m_NameIndexCont.end() ; ) 
		{
			InNameIndexCont&	aInNameIndexCont = ite->second ;
			if ( aInNameIndexCont.size() == 0 )
			{
				ite = m_NameIndexCont.erase( ite ) ;
			}
			else
			{
				ite ++ ;
			}
		}
	}
	return 0 ;
}
	// ********************************
	//@name	CNodeContainer-InNameIndex�ł̃A�N�Z�X
	// ********************************
int	CInNameIndexContainer::sizeInName( const std::string& element )const 
{
	int iRv = 0 ;

	// iIndex ��}��
	{
		NameIndexCont::const_iterator ite = m_NameIndexCont.find( element ) ;
		if ( ite == m_NameIndexCont.end() )
		{
		}
		else
		{
			const InNameIndexCont&	aInNameIndexCont = ite->second ;
			iRv = (int)aInNameIndexCont.size() ;
		}
	}

	return iRv ;
}

int CInNameIndexContainer::indexOfInNameIndex( 
		const std::string& element ,
		int iInNameIndex )const 
{
	int iRv = 0 ;
	// iIndex ��}��
	{
		NameIndexCont::const_iterator ite = m_NameIndexCont.find( element ) ;
		if ( ite == m_NameIndexCont.end() )
		{
			iRv = -1 ;	//	�C���f�N�X���s���ł��B
		}
		else
		{
			const InNameIndexCont&	aInNameIndexCont = ite->second ;
			if ( iInNameIndex == INT_MAX )
			{
				iInNameIndex = (int)aInNameIndexCont.size() - 1 ;
			}
			
			if ( !( 0 <= iInNameIndex && iInNameIndex < (int)aInNameIndexCont.size() ) )
			{
				iRv = -1 ;	//	�C���f�N�X���s���ł��B
			}
			else
			{
				iRv = aInNameIndexCont[iInNameIndex] ;
			}
		}
	}
	return iRv ;

}
int CInNameIndexContainer::indexToInNameIndex( 
		const std::string& element ,
		int iIndex )const 
{
	if ( iIndex == INT_MAX )
	{
		iIndex = m_iNodeCount - 1 ;
	}
	if ( !( 0 <= iIndex && iIndex < m_iNodeCount ) ) 
	{
		return -1 ;
	}



	int iRv = 0 ;
	// iIndex ������
	{
		
		NameIndexCont::const_iterator ite = m_NameIndexCont.find( element ) ;
		if ( ite == m_NameIndexCont.end() )
		{
			iRv = -1 ;
		}
		else
		{
			const InNameIndexCont&	aInNameIndexCont = ite->second ;

			int idxInNameIndex = -1 ;
			int idxLeft = 0 ;
			int idxRight = (int)aInNameIndexCont.size() - 1 ;
			while ( idxInNameIndex == -1 && idxLeft <= idxRight )
			{
				int iCentral = ( idxLeft + idxRight ) / 2 ;
				if ( aInNameIndexCont[iCentral] == iIndex )
				{
					idxInNameIndex = iCentral ;
				}
				else if ( iIndex <  aInNameIndexCont[iCentral] )
				{
					idxRight = iCentral - 1 ;
				}
				else if ( aInNameIndexCont[iCentral]  < iIndex )
				{
					idxLeft = iCentral + 1 ;
				}
			}
			iRv = idxInNameIndex ;
		}
	}

	return iRv ;



}


} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{
