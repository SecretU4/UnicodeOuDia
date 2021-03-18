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
// ****************************************************************
// $Id: CdYColSpecCont.cpp 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
#pragma once
#include "stdafx.h"
#include "CdYColSpecCont.h"

namespace ViewJikokuhyou{ namespace JikokuhyouColSpec{

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CdYColSpecCont::CdYColSpecCont( 
	const CentDedEkiCont* pCentDedEkiCont , 
	ERessyahoukou eRessyahoukou ,
	bool bDisplayAllJikoku ) 
	: m_eRessyahoukou( eRessyahoukou ) 
	, m_bDisplayAllJikoku( false )
	, m_iColumnNumber_Ekijikoku_begin( 0 ) 
	, m_iColumnNumber_Ekijikoku_end( 0 ) 
{
	scan( pCentDedEkiCont , eRessyahoukou , bDisplayAllJikoku ) ; 
}

CdYColSpecCont::CdYColSpecCont( ) 
	: m_eRessyahoukou( Ressyahoukou_Kudari ) 
	, m_bDisplayAllJikoku( false )
{
}

	// ********************************
	//@name CdYColSpec-�֘A
	// ********************************

	// ********************************
	//@name ����
	// ********************************
ERessyahoukou	CdYColSpecCont::getRessyahoukou()const 
{
	return m_eRessyahoukou ;
}
bool CdYColSpecCont::getDisplayAllJikoku()const 
{
	return m_bDisplayAllJikoku ;
}

int CdYColSpecCont::getColumnNumber_Ekijikoku_begin()const
{
	return m_iColumnNumber_Ekijikoku_begin ;
}
int CdYColSpecCont::getColumnNumber_Ekijikoku_end()const 
{
	return m_iColumnNumber_Ekijikoku_end ;
}

	// ********************************
	//@name CdYColSpec-����
	// ********************************
void CdYColSpecCont::scan( 
		const CentDedEkiCont* pCentDedEkiCont ,
		ERessyahoukou	eRessyahoukou ,
		bool bDisplayAllJikoku ) 
{
	// --------------------------------
	//	�����f�[�^�̍폜
	// --------------------------------
	clear() ;

	// --------------------------------
	//	�w��ԍ�-�\�����e�x�̑Ή��\���\�z
	// --------------------------------
	//	��Ԕԍ�
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Ressyabangou ) ) ;
	//	��Ԏ�� 
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Ressyasyubetsu ) ) ;
	//	��Ԗ�
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Ressyamei ) ) ;
	//	���� 
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Gousuu ) ) ;
	//	�u���v�\�� 
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Gou ) ) ;

	//	�w�����̐擪��̗�ԍ��B
	m_iColumnNumber_Ekijikoku_begin = m_contColumnSpec.size()  ;

	//	�w����
	{
		const Mu<CentDedEkiCont::CdDedEki>* muEki = 
			pCentDedEkiCont->getMuPtr( eRessyahoukou ) ;

		for( int iEkiOrder = 0 ; 
			iEkiOrder < muEki->size() ; iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki	aEki = muEki->get( iEkiOrder ) ;

			//	�������\������ �܂���[�S������\��] ���[�h�Ȃ�A���������ǉ�
			if ( aEki.getChakujikokuHyouji() || bDisplayAllJikoku )
			{
				m_contColumnSpec.insert( 
					CdYColSpec( CdYColSpec::ColumnType_Ekijikoku_Chaku , iEkiOrder ) ) ;
			}
			//	�������\������ �܂���[�S������\��] ���[�h�Ȃ�A���������ǉ�
			if ( aEki.getHatsujikokuHyouji() || bDisplayAllJikoku )
			{
				m_contColumnSpec.insert( 
					CdYColSpec( CdYColSpec::ColumnType_Ekijikoku_Hatsu , iEkiOrder ) ) ;
			}
		}
	}
	/* 		�w������� �I�[(�̎�) �� ��ԍ��B*/
	m_iColumnNumber_Ekijikoku_end = m_contColumnSpec.size()  ;
	/**	���l */
	m_contColumnSpec.insert( 
		CdYColSpec( CdYColSpec::ColumnType_Bikou ) ) ;
}



int CdYColSpecCont::size() 
{
	return m_contColumnSpec.size() ;
}

CdYColSpec CdYColSpecCont::ColumnNumberToSpec( int iYColumnNumber ) 
{
	CdYColSpec	aRv ;

	if ( 0 <= iYColumnNumber && iYColumnNumber < m_contColumnSpec.size() )
	{
		aRv = m_contColumnSpec.get( iYColumnNumber ) ;
	}

	return aRv ;
}




int CdYColSpecCont::ColumnNumberFromSpec( 
		const CdYColSpec& aCdYColumnSpec ,
		bool bResolveSameStation ) 
{
	int iRv = -1 ;
	// --------------------------------
	//	�\�����e�̈�v����������
	// --------------------------------
	for ( int iColumnNumber = 0 ; 
		iRv == -1 && iColumnNumber < m_contColumnSpec.size() ; 
		iColumnNumber ++ )
	{
		if ( m_contColumnSpec.get( iColumnNumber ) == aCdYColumnSpec )
		{
			iRv = iColumnNumber ;
		}
	}
	// --------------------------------
	//	�Ή�����\�����ڂ���\���ł���ꍇ�A����̗�ԍ���Ԃ��܂��B
	// --------------------------------
	if ( iRv == -1 && bResolveSameStation )
	{
		//- aCdYColumnSpec ���AColumnType_Ressyabangou(��Ԕԍ�)�`ColumnType_Gou(�u���v�\��) 
		//�܂łȂ�AColumnType_Ressyabangou�`ColumnType_Gou �̂����̂����ꂩ����������
		//�ŏ��̗�ԍ���Ԃ��܂��B
		if ( aCdYColumnSpec.isRessyaProp() )
		{
			for ( int iColumnNumber = 0 ; 
				iRv == -1 && iColumnNumber < m_contColumnSpec.size() ; 
				iColumnNumber ++ )
			{
				if ( m_contColumnSpec.get( iColumnNumber ).isRessyaProp() )
				{
					iRv = iColumnNumber ;
				}
			}
		}
		//- aCdYColumnSpec ��	ColumnType_Ekijikoku_Chaku(������)�Ȃ�΁A
		//�����wOrder�� ColumnType_Ekijikoku_Hatsu(������)��Ԃ��܂��B���̗����\���Ȃ�A
		//�wOrder��aCdYColumnSpec �����ŁAColumnType_Ekijikoku_Chaku �� 
		//ColumnType_Ekijikoku_Hatsu �̗�̂����A��ԑ傫����ԍ���Ԃ��܂��B
		//- aCdYColumnSpec ��	ColumnType_Ekijikoku_Hatsu(������)�̏ꍇ���A
		//ColumnType_Ekijikoku_Chaku �̏ꍇ�Ɠ��l�ł��B
		else if ( aCdYColumnSpec.isEkiJikoku() )
		{
			for ( int iColumnNumber = m_contColumnSpec.size() - 1 ;
				iRv == -1 && iColumnNumber >= 0 ;
				iColumnNumber -- )
			{
				CdYColSpec	aColumnSpecCurr = m_contColumnSpec.get( iColumnNumber ) ;
				if ( aColumnSpecCurr.isEkiJikoku() && 
					aColumnSpecCurr.getEkiOrder() <= aCdYColumnSpec.getEkiOrder() )
				{
					iRv = iColumnNumber ;
				}
			}
		}
		else if ( aCdYColumnSpec.getColumnType() == CdYColSpec::ColumnType_Bikou )
		{
			for ( int iColumnNumber = m_contColumnSpec.size() - 1 ;
				iRv == -1 && iColumnNumber >= 0 ;
				iColumnNumber -- )
			{
				CdYColSpec	aColumnSpecCurr = m_contColumnSpec.get( iColumnNumber ) ;
				if ( aColumnSpecCurr.getColumnType() != CdYColSpec::ColumnType_Bikou )
				{
					iRv = iColumnNumber ;
				}
			}
		}
	}

	return iRv ;
}

void CdYColSpecCont::clear() 
{
	m_eRessyahoukou = Ressyahoukou_Kudari ;
	m_bDisplayAllJikoku = false ;
	m_contColumnSpec.erase( 0 , INT_MAX ) ;
}
} } //namespace JikokuhyouColSpec namespace ViewJikokuhyou

