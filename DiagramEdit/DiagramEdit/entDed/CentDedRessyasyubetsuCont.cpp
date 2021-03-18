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
//	CentDedRessyasyubetsuCont.cpp
// ****************************************************************
*/
#include "stdafx.h"
#include "CentDedRessyasyubetsuCont.h"
#include "CentDedRosen.h"

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

namespace entDed{

// ****************************************************************
//	CentDedRessyasyubetsuCont
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CentDedRessyasyubetsuCont::CentDedRessyasyubetsuCont() 
{
}
CentDedRessyasyubetsuCont& 
CentDedRessyasyubetsuCont::operator=( const CentDedRessyasyubetsuCont& value ) 
{
	//	���R���e�i�̑��(operator=):�R���e�i���H���̈ꕔ�ł���ꍇ�ŁA�E�ӂ̗v�f����0�̏ꍇ�́A
	//	�C���f�N�X0�Ԃ̗�Ԏ�ʂ�ǉ����āA��Ԏ�ʂ̐���0�ɂȂ�Ȃ��悤�ɂ���
	if ( value.size() == 0 && getRosen() != NULL )
	{
		insert( CentDedRessyasyubetsu( "00" , "" ) ) ;
		erase( 1 , INT_MAX ) ; 
	}
	else
	{
		super::operator=( value ) ; 
	}
	return *this ;
}

	// ********************************
	///@name Mui
	// ********************************
int CentDedRessyasyubetsuCont::insert( const CentDedRessyasyubetsu& element , int iIndex )
{
	int iRv = 0 ; 
	if ( iIndex == INT_MAX )
	{
		iIndex = size() ;
	}

	//rinji
	//	����Ԏ�ʂ̒ǉ�(insert):���̃R���e�i���H���̈ꕔ�ł���ꍇ�A���O����̗�Ԏ�ʂ̒ǉ��̓G���[
	if ( getRosen() != NULL && element.getSyubetsumei().length() == 0 )
	{
		iRv = -11 ;	//	name����� CentDedRessyasyubetsu���㏑������ƃG���[�B
	}
	if ( iRv >= 0 )
	{
		iRv = super::insert( element , iIndex ) ; 
	}
	//	  ���̃R���e�i�� CentDedRosen �ɕ�܂���Ă���ꍇ�A insert() 
	//	���\�b�h�́ACentDedRosen::onRessyasyubetsuInsert( iEkiIndex ) 
	//	�ɏ������Ϗ����܂��B
	if ( iRv >= 0 )
	{
		CentDedRosen* pRosen = getRosen() ;
		if ( pRosen != NULL )
		{
			pRosen->onRessyasyubetsuInsert( iIndex ) ; 
		}
	}

	return iRv ;
}

int CentDedRessyasyubetsuCont::erase( int iIndex  , int iSize ) 
{
	int iRv = 0 ; 

	if ( iIndex == INT_MAX && iSize != INT_MAX )
	{
		iIndex = size() - iSize ;
	}
	else if ( iIndex != INT_MAX && iSize == INT_MAX )
	{
		iSize = size() - iIndex ;
	}
	// --------------------------------	
	if ( !( 0 <= iIndex && iIndex + iSize <= size() ) )
	{
		iRv = -1 ;	//	�C���f�N�X���͈͊O�ł��B
	}
	if ( iRv >= 0 )
	{
		if ( size() <= iSize && getRosen() != NULL )
		{
			iRv = -11 ;	//	����Ԏ�ʂ̍폜(erase):�@��Ԏ�ʂ�0�ɂȂ�悤�ȍ폜�̓G���[

		}
	}
	if ( iRv >= 0 )
	{
		iRv = super::erase( iIndex , iSize ) ;
	}
	//	  ���̃R���e�i��  CentDedRosen �ɕ�܂���Ă���ꍇ�A erase() 
	//	���\�b�h�́ACentDedRosen::onEkiErase( iEkiIndex )
	//	�ɏ������Ϗ����܂��B
	if ( iRv >= 0 )
	{
		CentDedRosen* pRosen = getRosen() ;
		if ( pRosen != NULL )
		{
			for ( int idx = iIndex + iSize - 1 ; idx >= iIndex ; idx-- )
			{
				pRosen->onRessyasyubetsuErase( idx ) ; 
			}
		}
	}

	return iRv ;
}
int CentDedRessyasyubetsuCont::set( const CentDedRessyasyubetsu& element , int iIndex ) 
{
	int iRv = setable( element , iIndex ) ;
	if ( iRv < 0 )
	{
		return iRv ;
	}
	return super::set( element , iIndex ) ;
}

	// ********************************
	//@name CentDedRessyasyubetsuCont-����
	// ********************************
int CentDedRessyasyubetsuCont::setable(  const CentDedRessyasyubetsu& element , int iIndex )const 
{
	int iRv = 0 ;
	if ( iIndex == INT_MAX )
	{
		iIndex = size() - 1 ;
	}

	if ( element.getSyubetsumei().length() == 0 )
	{
		//���Ԑ��̏㏑��(set): name����� CentDedRessyasyubetsu���㏑������ƃG���[�B
		iRv = -11 ;	//	
	}

	return iRv ;
}

int CentDedRessyasyubetsuCont::getIndex( const CentDedRessyasyubetsu* element )const 
{
	const Mu<const CentDedRessyasyubetsu*>* pMu = getMuPtr() ;
	for ( int idx = 0 ; idx < pMu->size() ; idx ++ ){
		if ( pMu->get( idx ) == element ){	return idx ;}
	}
	return -1 ;
}

int CentDedRessyasyubetsuCont::isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		int* piDiaIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const 
{
	const CentDedRosen* pRosen = getRosen() ;
	if ( pRosen  != NULL )
	{
		return pRosen->getCentDedDiaCont()->isExistRessyaOfRessyasyubetsu(
			iRessyasyubetsuIndex , 
			piDiaIndex , 
			peRessyahoukou , 
			piRessyaIndex ) ;
	}
	return 0 ;
}



} //namespace entDed

