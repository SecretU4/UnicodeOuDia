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
//	CDedRessyaSoater.cpp
//	$Id: CDedRessyaSoater.cpp 378 2016-11-16 21:10:54Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include <vector>
#include "NsMu\CMup_vector.h"
#include "CDedRessyaSoater.h"

namespace entDed{


	// --------------------------------
	//@name sort �̉����֐�(template�p�^�[��)
	// --------------------------------
void CDedRessyaSoater::makeRessyaIndex( 
		int iRessyaIndex , int iRessyaCount , 
		Mui<int>* muRessyaIndexOrder ) 
{
	muRessyaIndexOrder->erase( 0 , INT_MAX ) ;
	for ( int idx = 0 ; idx < iRessyaCount ; idx ++ )
	{
		muRessyaIndexOrder->insert( iRessyaIndex + idx ) ; 
	}
}




void CDedRessyaSoater::sortRessyaByRessyaIndexOrder( 
		const Mu<int>* muRessyaIndexOrder,
		CentDedRessyaCont* pRessyaCont ) 
{
	std::vector<int>	contiRessyaIndexOrder ;
	contiRessyaIndexOrder.resize( muRessyaIndexOrder->size() ) ;
	for ( int idx = 0 ; idx < muRessyaIndexOrder->size() ; idx ++ )
	{
		contiRessyaIndexOrder[idx] = muRessyaIndexOrder->get( idx ) ;
	}
	//contiRessyaIndexOrder=muRessyaIndexOrder �̕����B�������݉\�B

	for ( int idxBeforeSort = 0 ; 
		idxBeforeSort < (int)contiRessyaIndexOrder.size() - 1 ; 
		idxBeforeSort ++ )
	{
		int idxMin = idxBeforeSort ;

		for ( int idxCompare = idxMin + 1 ; 
			idxCompare < (int)contiRessyaIndexOrder.size() ;
			idxCompare ++ )
		{
			if ( contiRessyaIndexOrder[idxMin] > 
				contiRessyaIndexOrder[idxCompare] )
			{
				idxMin = idxCompare ;
			}
		}
		//idxMin = contRessyaIndexOrder[idxBeforeSort�ȍ~]�̒��ŁA
		//	�ŏ��̒l�����C���f�N�X
		//contRessyaIndexOrder[idxBeforeSort],
		//contRessyaIndexOrder[idxMin] = ����ւ��̕K�v�̂�����Index

		// --------------------------------
		//	pRessyaCont �̓��e�����ւ�	
		// --------------------------------
		{
			CentDedRessya	aRessya1 = pRessyaCont->get( contiRessyaIndexOrder[idxBeforeSort] ) ;
			CentDedRessya	aRessya2 = pRessyaCont->get( contiRessyaIndexOrder[idxMin] ) ;
			pRessyaCont->set( aRessya2 , contiRessyaIndexOrder[idxBeforeSort] ) ;
			pRessyaCont->set( aRessya1 , contiRessyaIndexOrder[idxMin] ) ;
		}
		// --------------------------------
		//	contiRessyaIndexOrder �̓��e�����ւ�	
		// --------------------------------
		{
			int i1 = contiRessyaIndexOrder[idxBeforeSort] ;
			int i2 = contiRessyaIndexOrder[idxMin] ;
			contiRessyaIndexOrder[idxBeforeSort] = i2 ;
			contiRessyaIndexOrder[idxMin] = i1 ;
		}
	}
}





	// ********************************
	//@name ����
	// ********************************
void CDedRessyaSoater::sort( 
		CentDedRessyaCont* pRessyaCont ,
		IfProgress* pIfProgress ) 
{
	// --------------------------------
	//	�\�[�g���s�����Index��ێ������R���e�i�ɁA
	//	�A�Ԃ̗��Index���i�[���܂��B
	CMup_vector<int>	muRessyaIndexOrder ;	
	makeRessyaIndex( 0 , pRessyaCont->size() , &muRessyaIndexOrder ) ;

	// --------------------------------
	//	�w�肳�ꂽ���Index�̗�Ԃ��A
	//	�w�肳�ꂽ�w����Order�Ń\�[�g���܂��B
	sortRessyaIndex( 
		pRessyaCont ,
		&muRessyaIndexOrder ,
		pIfProgress ) ;

	// --------------------------------
	//	��� index (int)��ێ������R���e�i�ɏ]���āA
	//	��ԃR���e�i�̗�Ԃ̕��я����A
	//	����ւ��܂��B
	sortRessyaByRessyaIndexOrder( 
		&muRessyaIndexOrder , 
		pRessyaCont ) ;
}

} //namespace entDed
