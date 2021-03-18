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
//	CconvCentDed_01.h
// ****************************************************************
*/
#ifndef  convCentDed_h
#define  convCentDed_h

/** @file */

#include "CentDedEki.h"
#include "CentDedRessyasyubetsu.h"
#include "CentDedEkiJikoku.h"
#include "CentDedRessya.h"
#include "CentDedRessyaCont.h"
#include "CentDedDia.h"
#include "CentDedRosen.h"
#include "str/CdConnectedString2.h"
#include "DcDraw/CDcdFreeLine.h"

// ****************************************************************
//	CconvCentDed_01
// ****************************************************************
/**
 *	@brief
 *	  DiagramEdit �̃G���e�B�e�B�N���X�̃I�u�W�F�N�g�̑����f�[�^�̓��e���A
 *	���̃f�[�^�`���ɕϊ�����֐������^���Ă��܂��B
 *
 *	   CdConnectedString2 �I�u�W�F�N�g�Ƃ̊Ԃ̕ϊ����T�|�[�g���Ă��܂��B
 *	
 */
class CconvCentDed_01
{
// ********************************
//	CconvCentDed_01
// ********************************
 public:

	// ********************************
	//	CentDedEki
	// ********************************
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g�ɁA
	 *	  CentDedEki �̑�����ǉ����܂��B
	 *	@param aCentDedEki [in]
	 *	  CentDedEki ���w�肵�Ă��������B
	 *	@param pCdConnectedString [in,out]
	 *	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	 *	�ǉ����܂��B
	 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	 *	�ێ����܂��B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
	 *	-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
	 *	-	-32 ;	//	Ekikibo �̒l���s���ł��B
	 */
	int CentDedEki_To_CdConnectedString( 
			const CentDedEki& aCentDedEki , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g����A
	 *	  CentDedEki_To_CdConnectedString() �֐��ɂ���č쐬���ꂽ
	 *	�A�C�e����ǂݍ��݁A CentDedEki �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	@param pCentDedEki [out]
	 *	  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	 *	@param aCdConnectedString [in]
	 *	  ������ێ����Ă��� CdConnectedString �I�u�W�F�N�g���w�肵�Ă��������B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
	 *	-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
	 *	-	-32 ;	//	Ekikibo �̒l���s���ł��B
	 */
	int CentDedEki_From_CdConnectedString( 
			CentDedEki* pCentDedEki ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	// ********************************
	//	CentDedRessyasyubetsu
	// ********************************
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g�ɁA
	 *	  CentDedRessyasyubetsu �̑�����ǉ����܂��B
	 *	@param aCentDedRessyasyubetsu [in]
	 *	  CentDedRessyasyubetsu ���w�肵�Ă��������B
	 *	@param pCdConnectedString [in,out]
	 *	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	 *	�ǉ����܂��B
	 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	 *	�ێ����܂��B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
	 *	-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
	 *	-	-32 ;	//	Ekikibo �̒l���s���ł��B
	 */
	int CentDedRessyasyubetsu_To_CdConnectedString( 
			const CentDedRessyasyubetsu& aCentDedRessyasyubetsu , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g����A
	 *	  CentDedRessyasyubetsu_To_CdConnectedString() �֐��ɂ���č쐬���ꂽ
	 *	�A�C�e����ǂݍ��݁A CentDedRessyasyubetsu �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	@param pCentDedRessyasyubetsu [out]
	 *	  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	 *	@param aCdConnectedString [in]
	 *	  ������ێ����Ă��� CdConnectedString �I�u�W�F�N�g���w�肵�Ă��������B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
	 *	-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
	 *	-	-32 ;	//	Ekikibo �̒l���s���ł��B
	 */
	int CentDedRessyasyubetsu_From_CdConnectedString( 
			CentDedRessyasyubetsu* pCentDedRessyasyubetsu ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	/**
	 *	CentDedRessyasyubetsu::ESenStyle �̒l�ƁA
	 *	�u�����v������ bool ���������ƂɁA
	 *	CDcdFreeLine::CdLineProp �I�u�W�F�N�g�ɑ�����
	 *	�ݒ肵�܂��B
	 * @param aCOLORREF [in] 
	 *	���̐F���w�肵�Ă��������B
	 * @param eSenStyle [in]
	 *	���̌`����w�肵�Ă��������B
	 * @param bIsBold [in]
	 *	�����Ȃ� true , �����łȂ��Ȃ� false ���w�肵�Ă��������B
	 * @param pCdLineProp [out]
	 *	���̊֐��͂��̃I�u�W�F�N�g�ɁA
	 *	������ݒ肵�܂��B
	 */
	void CentDedRessyasyubetsu_to_CDcdFreeLineProp(
		COLORREF aCOLORREF ,
		CentDedRessyasyubetsu::ESenStyle eSenStyle , 
		bool bIsBold , 
		CDcdFreeLine::CdLineProp* pCdLineProp )	;
	
	// ********************************
	//	CentDedEkiJikoku
	// ********************************
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g�ɁA
	 *	  CentDedEkiJikoku �̑�����ǉ����܂��B
	 *	@param aCentDedEkiJikoku [in]
	 *	  CentDedEkiJikoku ���w�肵�Ă��������B
	 *	@param pCdConnectedString [in,out]
	 *	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	 *	�ǉ����܂��B
	 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	 *	�ێ����܂��B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedEkiJikoku_To_CdConnectedString( 
			const CentDedEkiJikoku& aCentDedEkiJikoku , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g����A
	 *	  CentDedEkiJikoku_To_CdConnectedString() �֐��ɂ���č쐬���ꂽ
	 *	�A�C�e����ǂݍ��݁A CentDedEkiJikoku �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	@param pCentDedEkiJikoku [out]
	 *	  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	 *	@param aCdConnectedString [in]
	 *	  ������ێ����Ă��� CdConnectedString �I�u�W�F�N�g���w�肵�Ă��������B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedEkiJikoku_From_CdConnectedString( 
			CentDedEkiJikoku* pCentDedEkiJikoku ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	// ********************************
	//	CentDedRessya
	// ********************************
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g�ɁA
	 *	  CentDedRessya �̑�����ǉ����܂��B
	 *	@param pCentDedRessya [in]
	 *	  CentDedRessya ���w�肵�Ă��������B
	 *	@param pCdConnectedString [in,out]
	 *	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	 *	�ǉ����܂��B
	 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	 *	�ێ����܂��B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedRessya_To_CdConnectedString( 
			const CentDedRessya* pCentDedRessya , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g����A
	 *	  CentDedRessya_To_CdConnectedString() �֐��ɂ���č쐬���ꂽ
	 *	�A�C�e����ǂݍ��݁A CentDedRessya �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	  �������A
	 *
	 *		- ��ԕ���
	 *		- �I�u�W�F�N�g����܂��� �w�w�����x �̐�
	 *
	 *	�́A�ύX���܂���B���̒l�́A�֐��ďo���ɂ���Đݒ肳��Ă���
	 *	�K�v������܂��B
	 *	@param pCentDedRessya [in,out]
	 *	  ���̊֐��͂��̃I�u�W�F�N�g�ɁA��Ԃ̑����𔽉f���܂��B
	 *	\n �������A�I�u�W�F�N�g�̑����w��ԕ����x��
	 *	��܂��� �w�w�����x �̐��͕ύX���܂���B
	 *	���̒l�́A�֐��ďo���ɂ���Đݒ肳��Ă���K�v������܂��B
	 *	@param aCdConnectedString [in]
	 *	  ������ێ����Ă��� CdConnectedString �I�u�W�F�N�g���w�肵�Ă��������B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedRessya_From_CdConnectedString( 
			CentDedRessya* pCentDedRessya ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	
	// ********************************
	//	CentDedRessyaCont
	// ********************************
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g�ɁA
	 *	  CentDedRessyaCont �̑�����ǉ����܂��B
	 *	@param pCentDedRessyaCont [in]
	 *	  CentDedRessya ���w�肵�Ă��������B
	 *	@param pCdConnectedString [in,out]
	 *	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	 *	�ǉ����܂��B
	 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	 *	�ێ����܂��B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedRessyaCont_To_CdConnectedString( 
			const CentDedRessyaCont* pCentDedRessyaCont , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g����A
	 *	  CentDedRessya_To_CdConnectedString() �֐��ɂ���č쐬���ꂽ
	 *	�A�C�e����ǂݍ��݁A CentDedRessya �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	@param pCentDedRessya [in,out]
	 *	  ���̊֐��͂��̃R���e�i�̖����ɁA
	 *	aCdConnectedString �I�u�W�F�N�g�ɕۑ�����Ă��鑮���̃I�u�W�F�N�g��
	 *	�ǉ����܂��B
	 *	\n �������A�ǉ������I�u�W�F�N�g�� �w�w�����x �̐��́A
	 *	m_iEkiCount �Ɍ��܂��Ă��܂��B aCdConectedString �ɕۑ�����Ă���
	 *	��Ԃ������葽���w�w�����x��ێ����Ă����ꍇ�́A�I���w���̎�����
	 *	�؎̂ĂƂȂ�܂��B
	 *	@param aCdConnectedString [in]
	 *	  ������ێ����Ă��� CdConnectedString �I�u�W�F�N�g���w�肵�Ă��������B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedRessyaCont_From_CdConnectedString( 
			CentDedRessyaCont* pCentDedRessyaCont ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	
	// ********************************
	//	CentDedDia
	// ********************************
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g�ɁA
	 *	  CentDedDia �̑�����ǉ����܂��B
	 *	@param pCentDedDia [in]
	 *	  CentDedDia ���w�肵�Ă��������B
	 *	@param pCdConnectedString [in,out]
	 *	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	 *	�ǉ����܂��B
	 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	 *	�ێ����܂��B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedDia_To_CdConnectedString( 
			const CentDedDia* pCentDedDia , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g����A
	 *	  CentDedDia_To_CdConnectedString() �֐��ɂ���č쐬���ꂽ
	 *	�A�C�e����ǂݍ��݁A CentDedDia �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	@param pCentDedDia [out]
	 *	  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	 *	@param aCdConnectedString [in]
	 *	  ������ێ����Ă��� CdConnectedString �I�u�W�F�N�g���w�肵�Ă��������B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-12 ;	//	DiagramEkiatsukai �̒l���s���ł��B
	 */
	int CentDedDia_From_CdConnectedString( 
			CentDedDia* pCentDedDia ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	// ********************************
	//	CentDedRosen
	// ********************************
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g�ɁA
	 *	  CentDedRosen �̑�����ǉ����܂��B
	 *	@param pCentDedRosen [in]
	 *	  CentDedRosen ���w�肵�Ă��������B
	 *	@param pCdConnectedString [in,out]
	 *	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	 *	�ǉ����܂��B
	 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	 *	�ێ����܂��B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 */
	int CentDedRosen_To_CdConnectedString( 
			const CentDedRosen* pCentDedRosen , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g����A
	 *	  CentDedRosen_To_CdConnectedString() �֐��ɂ���č쐬���ꂽ
	 *	�A�C�e����ǂݍ��݁A CentDedRosen �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	@param pCentDedRosen [out]
	 *	  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	 *	@param aCdConnectedString [in]
	 *	  ������ێ����Ă��� CdConnectedString �I�u�W�F�N�g���w�肵�Ă��������B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-2 ;	//	�w��Ԏ�ʁx�́A���Ȃ��Ƃ����
	 *				//	���݂��Ȃ��Ă͂Ȃ�܂���B
	 *	-	-52 ;	//	�N�_�����̐ݒ肪�s�K�؂ł��B
	 */
	int CentDedRosen_From_CdConnectedString( 
			CentDedRosen* pCentDedRosen ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	
};	
#endif /*convCentDed_h*/
	
