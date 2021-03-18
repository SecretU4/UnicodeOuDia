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
//	CentDedRessya_EkijikokuModifyOperation2.cpp
// ****************************************************************
#include "stdafx.h"

#include "CentDedRessya_EkijikokuModifyOperation2.h"

// ****************************************************************
//	CentDedRessya_EkijikokuModifyOperation2
// ****************************************************************
// ********************************
//	CentDedRessya_EkijikokuModifyOperation2-����
// ********************************
int CentDedRessya_EkijikokuModifyOperation2::
	execute( CentDedRessya* pCentDedRessya , CdDedJikokuOrder aJikokuOrder ) 
{
	int iRv = 0 ;
	
	// --------------------------------
	CentDedRessya	aCentDedRessya( *pCentDedRessya ) ;
	if ( aJikokuOrder.getEkiOrder() == INT_MAX )
	{
		aJikokuOrder.setEkiOrder( pCentDedRessya->getCentDedEkiJikokuCount() - 1 , CdDedJikokuOrder::EkiJikokuItem_Hatsu ) ;
	}
	if ( !( 0 <= aJikokuOrder.getEkiOrder() && 
		aJikokuOrder.getEkiOrder() < pCentDedRessya->getCentDedEkiJikokuCount() ) )
	{
		iRv = -1 ;	//	aJikokuOrder ���͈͊O�ł��B
	}
	//aCentDedRessya = ����ΏۂƂȂ���
	//aJikokuOrder = ����Order

	// --------------------------------
	//	�P�D�V�����w��������
	// --------------------------------
	if ( iRv >= 0 )
	{
		if ( getSetEkiatsukai() )
		{

			CentDedEkiJikoku aCentDedEkiJikoku = aCentDedRessya.getCentDedEkiJikoku( aJikokuOrder.getEkiOrder() ) ;
			CentDedEkiJikoku::EEkiatsukai eEkiatsukai = getEkiatsukai() ;
			if ( eEkiatsukai == CentDedEkiJikoku::Ekiatsukai_Teisya &&
				aCentDedEkiJikoku.getChakujikoku().isNull() && 
				aCentDedEkiJikoku.getHatsujikoku().isNull() )
			{
				//	�������E�������Ƃ��ɐݒ肳��Ă��Ȃ��w������
				//	��ԂɕύX���邱�Ƃ͂ł��܂���B
				iRv = -15 ;	

				// --------------------------------
				//	�ȉ��̏ꍇ�̓���[�u
				//		�w�����ύX������e.�w��=��ԂɕύX
				//		�w�����ύX������e.�w����=�w�����̃R�s�[
				//		�w�����ύX������e.�w�����̃R�s�[��=�����ݒ肠��
				//		�w�����ύX�Ώ�.�w�����K�p�Ώۉw����=���E���Ƃ��Ɏ����ݒ�Ȃ�
				//	�w�����ԂɕύX���Ă���A
				// --------------------------------
				if ( iRv == -15 )
				{
					CdDedJikoku aCdDedJikokuSrc = 
						aCentDedRessya.getEkiJikoku( m_iJikokuOrderCopySrc ) ;
					if ( m_eOperation == OperationCopy && 
						!aCdDedJikokuSrc.isNull() )
					{
						{
							//�w���̕ύX
							aCentDedEkiJikoku.setEkiatsukai( eEkiatsukai ) ;
							aCentDedRessya.setCentDedEkiJikoku( aJikokuOrder.getEkiOrder() , aCentDedEkiJikoku ) ;
							iRv = 0 ;
						}
					}
				}
			}
			else
			{
				//�w���̕ύX
				aCentDedEkiJikoku.setEkiatsukai( eEkiatsukai ) ;
				aCentDedRessya.setCentDedEkiJikoku( aJikokuOrder.getEkiOrder() , aCentDedEkiJikoku ) ;
			}
		}


	}
	//aCentDedRessya = �w�����ύX����܂����B
	
	// --------------------------------
	//	�Q�D�����̕ύX
	// --------------------------------
	if ( iRv >= 0 )
	{
		if ( m_eOperation == OperationModify )
		{
			CdDedJikan	aCdDedJikan( m_iSeconds * 60 ) ;
			aCentDedRessya.modifyRessyaJikoku( 
				aCdDedJikan , 
				aJikokuOrder ) ;
		}
		else if ( m_eOperation == OperationCopy )
		{
			CdDedJikoku aCdDedJikokuSrc = 
				aCentDedRessya.getEkiJikoku( m_iJikokuOrderCopySrc ) ;
			CdDedJikoku aCdDedJikokuDst = 
				aCentDedRessya.getEkiJikoku( aJikokuOrder ) ;

			//	�����́A�P���ɑ�����܂��B
			{
				CentDedEkiJikoku aCentDedEkiJikoku = 
					aCentDedRessya.getCentDedEkiJikoku( aJikokuOrder.getEkiOrder() ) ;
				aCdDedJikokuSrc.addSeconds( m_iSeconds * 60 ) ;
				if ( aJikokuOrder.getEkiJikokuItem() == CdDedJikokuOrder::EkiJikokuItem_Chaku)
				{
					aCentDedEkiJikoku.setChakujikoku( aCdDedJikokuSrc ) ;
				}
				else
				{
					aCentDedEkiJikoku.setHatsujikoku( aCdDedJikokuSrc ) ;
				}
				aCentDedRessya.setCentDedEkiJikoku( 
					aJikokuOrder.getEkiOrder() , aCentDedEkiJikoku  ) ;
			}
		}
		else if ( m_eOperation == OperationToNull )
		{
			//	NULL ��ݒ�
			aCentDedRessya.setEkiJikoku( CdDedJikoku()  , aJikokuOrder ) ;
		}
	}
	//aCentDedRessya = �w�������ύX����܂����B



	


	// --------------------------------
	//	�w���E�������E��������ύX
	// --------------------------------
	if ( iRv >= 0 )
	{
		*pCentDedRessya = aCentDedRessya ;
	}	
	return ( iRv ) ;
}
