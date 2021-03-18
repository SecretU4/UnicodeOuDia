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
//$Id: CconvDcDrawProp.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
/** @file */
#pragma once
#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcdCd\DcDrawProp\CdColorProp.h"
#include "DcdCd\DcDrawProp\CdDcdFreeLineProp.h"
#include "str\CdConnectedString2.h"

/**
	DcDraw�̒P���f�[�^�̕ϊ��@�\��񋟂��܂��B
*/
class CconvDcDrawProp
{
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CconvDcDrawProp(void);
	virtual ~CconvDcDrawProp(void);

public:
	// ********************************
	///@name CdFontProp
	// ********************************
	///@{
	/**
	  	CdFontProp �̑������A CdConnectedString2 �I�u�W�F�N�g�ɒǉ����܂��B
	   @param aCdFontProp [in]
	  	�ϊ��ΏۂƂȂ� CdFontProp ���w�肵�Ă��������B
	   @param pCdConnectedString2 [in,out]
	  	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	  	�ǉ����܂��B
	  	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	  	�ێ����܂��B
	   @return
	  	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 */
	int CdFontProp_to_CdConnnectedString2( 
		const CdFontProp& aCdFontProp ,
		CdConnectedString2*	pCdConnectedString );

	/**
	  	 CdConnectedString2 �I�u�W�F�N�g����A
	  	 CdFontProp_to_CdConnectedString2() �Œǉ����� CdItem ��ǂݎ��A
	  	CdFontProp �I�u�W�F�N�g�̑����ɔ��f���܂��B
	   @param pCdFontProp [out]
	  	���̊֐��͂��̃I�u�W�F�N�g�̑����ɁA������̓��e�𔽉f���܂��B
	   @param aCdConnectedString [in]
	  	 CdFontProp_to_CdConnectedString2() �Œǉ����� CdItem ������
	  	 CdConnectedString2 �I�u�W�F�N�g���w�肵�Ă��������B
	   @return
	  	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	  	-	-12 ;	//	PointTextHeight �̒l���s��
	  	-	-22 ;	//	LogicalunitTextHeight �̒l���s��
	  	-	-32 ;	//	LogicalunitCellHeight �̒l���s��
	  	-	-42 ;	//	Facename �̒l���s��
	  	-	-52 ;	//	Bold �̒l���s��
	  	-	-62 ;	//	Itaric �̒l���s��
	  	-	-72 ;	//	Underline �̒l���s��
	  	-	-82 ;	//	StrikeOut �̒l���s��
	  	-	-92 ;	//	Escapement �̒l���s��
	 */
	int CdFontProp_from_CdConnectedString2( CdFontProp* pCdFontProp ,
		const CdConnectedString2& aCdConnectedString ) ;


	/**
	  	CdFontProp �̑������A������ɕϊ����܂��B
	   @param aCdFontProp [in]
	  	�ϊ��ΏۂƂȂ� CdFontProp ���w�肵�Ă��������B
	   @return
	  	�ϊ����ʂ�Ԃ��܂��B
	 */
	std::string CdFontProp_to_string( const CdFontProp& aCdFontProp );

	/**
	  	 CdFontProp_to_string() �ō쐬��������������߂��A
	  	CdFontProp �I�u�W�F�N�g�̑����ɔ��f���܂��B
	   @param pCdFontProp [out]
	  	���̊֐��͂��̃I�u�W�F�N�g�̑����ɁA������̓��e�𔽉f���܂��B
	   @param aString [in]
	  	 CdFontProp_to_string() �ō쐬������������w�肵�Ă��������B
	   @return
	  	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	  	-	-12 ;	//	PointTextHeight �̒l���s��
	  	-	-22 ;	//	LogicalunitTextHeight �̒l���s��
	  	-	-32 ;	//	LogicalunitCellHeight �̒l���s��
	  	-	-42 ;	//	Facename �̒l���s��
	  	-	-52 ;	//	Bold �̒l���s��
	  	-	-62 ;	//	Itaric �̒l���s��
	  	-	-72 ;	//	Underline �̒l���s��
	  	-	-82 ;	//	StrikeOut �̒l���s��
	  	-	-92 ;	//	Escapement �̒l���s��
	 */
	int CdFontProp_from_string( 
		CdFontProp* pCdFontProp , 
		const std::string& aString  );
	///@}
	// ********************************
	///@name CdColorProp
	// ********************************
	///@{
	/**
		aCdColorProp �𕶎���ɕϊ����܂��B
	@param aCdColorProp [in]
		�ϊ����̒l���w�肵�Ă��������B
	@return
		�ϊ����ʂ�Ԃ��܂��B
	*/
	std::string CdColorProp_to_string( const CdColorProp& aCdColorProp );

	/**
		������� aCdColorProp �ɕϊ����܂��B
	@param aString [in]
		�ϊ����̒l���w�肵�Ă��������B
	@return
		�ϊ����ʂ�Ԃ��܂��B
	 */
	CdColorProp CdColorProp_from_string( const std::string& aString  );
	///@}
	// ********************************
	///@name CdDcdFreeLineProp
	// ********************************
	///@{
	/**
	  	CdDcdFreeLineProp �̑������A CdConnectedString2 �I�u�W�F�N�g�ɒǉ����܂��B
	@param aCdDcdFreeLineProp [in]
	  	�ϊ��ΏۂƂȂ� CdDcdFreeLineProp ���w�肵�Ă��������B
	@param pCdConnectedString2 [in,out]
	  	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	  	�ǉ����܂��B
	  	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	  	�ێ����܂��B
	@return
	  	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B

	*/
	int CdDcdFreeLineProp_to_CdConnectedString2( 
		const CdDcdFreeLineProp& aCdDcdFreeLineProp ,
		CdConnectedString2*	pCdConnectedString ) ;

	/**
	  	CdDcdFreeLineProp �̑������A������ɕϊ����܂��B
	@param aCdDcdFreeLineProp [in]
	  	�ϊ��ΏۂƂȂ� CdFontProp ���w�肵�Ă��������B
	@return
	  	�ϊ����ʂ�Ԃ��܂��B
		���s�����ꍇ�͋󕶎���ƂȂ�܂��B
	*/
	std::string CdDcdFreeLineProp_to_string( 
		const CdDcdFreeLineProp& aCdDcdFreeLineProp );

	/**
	  	CdDcdFreeLineProp_to_CdConnectedString2 �ō쐬����
		*pCdConnectedString �̓��e���A
		CdDcdFreeLineProp �I�u�W�F�N�g�ɔ��f���܂��B
	@param pCdDcdFreeLineProp [out]
		���̊֐��͂��̃I�u�W�F�N�g�̑����ɁA������̓��e�𔽉f���܂��B
	@param aCdConnectedString [in]
		 CdDcdFreeLineProp_to_CdConnectedString2() �Œǉ����� CdItem ������
		 CdConnectedString2 �I�u�W�F�N�g���w�肵�Ă��������B
	@return
	  	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11 ;	//	LogicalunitWidth �̒l���s���ł�
		-	-12 ;	//	Color �̒l���s���ł�

	*/
	int CdDcdFreeLineProp_from_CdConnectedString2( 
		CdDcdFreeLineProp* pCdDcdFreeLineProp ,
		const CdConnectedString2*	pCdConnectedString ) ;

	/**
	  	CdDcdFreeLineProp_to_CdConnectedString2 �ō쐬����
		*pCdConnectedString �̓��e���A
		CdDcdFreeLineProp �I�u�W�F�N�g�ɔ��f���܂��B
	@param pCdDcdFreeLineProp [out]
		���̊֐��͂��̃I�u�W�F�N�g�̑����ɁA������̓��e�𔽉f���܂��B
	@param aString [in]
		 CdDcdFreeLineProp_to_string() �Ő�������
		 ��������w�肵�Ă��������B
	@return
	  	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11 ;	//	LogicalunitWidth �̒l���s���ł�
		-	-12 ;	//	Color �̒l���s���ł�
	*/
	int CdDcdFreeLineProp_from_string( 
		CdDcdFreeLineProp* pCdDcdFreeLineProp ,
		const std::string& aString  );

	///@}

};
