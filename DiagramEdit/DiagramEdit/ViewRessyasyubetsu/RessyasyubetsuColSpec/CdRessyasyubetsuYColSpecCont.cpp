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
// $Id: CdRessyasyubetsuYColSpecCont.cpp 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
#include "stdafx.h"
#include "CdRessyasyubetsuYColSpecCont.h"

namespace ViewRessyasyubetsu{ namespace RessyasyubetsuColSpec{

/// �w�b�_��̐�
const int HEADER_COUNT = 1 ;	

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CdRessyasyubetsuYColSpecCont::CdRessyasyubetsuYColSpecCont( 
		const CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont ) 
	: m_iRessyasyubetsuCount( pCentDedRessyasyubetsuCont->size() ) 
{
}
CdRessyasyubetsuYColSpecCont::CdRessyasyubetsuYColSpecCont() 
	: m_iRessyasyubetsuCount( 0 )
{
}

	// ********************************
	//@name CdRessyasyubetsuYColSpec-����
	// ********************************
int CdRessyasyubetsuYColSpecCont::getRessyasyubetsuCount()const
{	return m_iRessyasyubetsuCount ;};

	// ********************************
	//@name CWndJikokuhyou_CdXColSpecCont-����
	// ********************************
void CdRessyasyubetsuYColSpecCont::scan( 
		const CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont ) 
{
	m_iRessyasyubetsuCount = pCentDedRessyasyubetsuCont->size() ;
}

int CdRessyasyubetsuYColSpecCont::size() 
{
	return m_iRessyasyubetsuCount + HEADER_COUNT + 1 ;	//	�w�b�_��ƐV�K�ǉ��ʒu�����Z
}

CdRessyasyubetsuYColSpec CdRessyasyubetsuYColSpecCont::ColumnNumberToSpec( 
		int iColumnNumber ) 
{
	CdRessyasyubetsuYColSpec	aSpec ;
	
	//	�w�b�_��
	if ( iColumnNumber == 0 )
	{
		aSpec.set( CdRessyasyubetsuYColSpec::ColumnType_Head , -1 ) ;
	}
	//	��Ԏ�ʗ�
	else if ( HEADER_COUNT <= iColumnNumber && 
		iColumnNumber < HEADER_COUNT + m_iRessyasyubetsuCount )
	{
		aSpec.set( CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu , iColumnNumber - HEADER_COUNT ) ;
	}
	//	�V�K�ǉ��ʒu
	else if ( iColumnNumber == HEADER_COUNT + m_iRessyasyubetsuCount )
	{
		aSpec.set( CdRessyasyubetsuYColSpec::ColumnType_NewRessyasyubetsu , m_iRessyasyubetsuCount ) ;
	}
	return aSpec ;
}

int CdRessyasyubetsuYColSpecCont::ColumnNumberFromSpec( 
		const CdRessyasyubetsuYColSpec& aSpec ) 
{
	int iColumnNumber= -1 ;
	//	�w�b�_�� 
	if ( aSpec.getColumnType() == CdRessyasyubetsuYColSpec::ColumnType_Head )
	{
		iColumnNumber = 0 ;
	}
	//	��Ԏ�ʗ� 
	else if ( aSpec.getColumnType() == 
		CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu )
	{
		iColumnNumber = HEADER_COUNT + aSpec.getRessyasyubetsuIndex() ;
	}
	//	�V�K�ǉ��ʒu
	else if ( aSpec.getColumnType() == 
		CdRessyasyubetsuYColSpec::ColumnType_NewRessyasyubetsu )
	{
		iColumnNumber = HEADER_COUNT + m_iRessyasyubetsuCount ;
	}
	return iColumnNumber ;
}

void CdRessyasyubetsuYColSpecCont::clear() 
{
	*this = CdRessyasyubetsuYColSpecCont() ;
};

} } //namespace RessyasyubetsuColSpec namespace ViewRessyasyubetsu
