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
/*��
// ****************************************************************
//	CconvCDedRosenFileData_03.h
// ****************************************************************
*/
#ifndef  CconvCDedRosenFileData_03_h
#define  CconvCDedRosenFileData_03_h
/** @file */
#include "CconvCdDedDispProp_03.h"
#include "str/CdConnectedString2.h"

// ****************************************************************
//	CconvCDedRosenFileData_03
// ****************************************************************
/**
 *	@brief
 *	  �w�H���t�@�C���x�f�[�^ ( CDedRosenFileData ) �̓��e���A����
 *	�f�[�^�`���ɕϊ�����֐������^���Ă��܂��B
 *	
 *	 �w�H���t�@�C���x�f�[�^��  CdConnectedString2 �I�u�W�F�N�g�Ƃ̊Ԃ�
 *	�ϊ����T�|�[�g���Ă��܂��B 
 *	
 *	<H4>
 *	�y�H���t�@�C�� (.ded) �z
 *	</H4>
 *	  �w�H���t�@�C���x�́A�H���t�@�C���f�[�^�N���X��
 *	 CDedRosenFileData_To_string() �ŕ�����ɕϊ����A���̕�����S�̂�
 *	�ۑ������e�L�X�g�t�@�C���ł��B
 *	
 *	   CDedRosenFileData_To_string() �֐��́A
 *	   CDedRosenFileData �I�u�W�F�N�g���ێ�����f�[�^��
 *	�ȉ��̎菇�ŕ�����ɕϊ����܂��B
 *	
 *	  �P�D   CdConnectedString2 �I�u�W�F�N�g�𐶐����Ă��������B���̂Ƃ��A
 *	�A�C�e���Ԃ̋�؂蕶��( CdConnectedString2::m_chSplit ) �� "\n" �A
 *	���ڂƒl�̊Ԃ̋�؂蕶��( CdConnectedString2::m_chEqualChar ) ��
 *	 "=" �Ƃ��Ă��������B
 *	
 *	  �Q�D  CDedRosenFileData �I�u�W�F�N�g�̓��e���A
 *	 CDedRosenFileData_to_CdConnectedString() �ŁACdConnectedString2 ��
 *	�ǉ����Ă��������B
 *	
 *	  �R�D  CdConnectedString2::encode() �ɂ���ē����镶���񂪁A
 *	�w�H���t�@�C���x�`���̕�����ł��B������t�@�C���ɕۑ����邱�Ƃɂ��A
 *	 �w�H���t�@�C���x�ƂȂ�܂��B
 */
class CconvCDedRosenFileData_03
{
// ********************************
//	CconvCDedRosenFileData_03
// ********************************
 public:
	// ********************************
	//	CdDedDispProp
	// ********************************
	/**
	 * @return
	 *	CdDedDispProp_to_CdConnectedString() �̓��e��
	 *	�t�@�C���ɕۑ�����ۂɒǉ�����A�C�e�� "FileType" �̒l�ł��B
	 *
	 * @attention 
	 *	���̃N���X�� CdDedDispProp_to_CdConnectedString() �֐���
	 *	 "FileType" �A�C�e����t�^����킯�ł͂���܂���B
	 *	 "FileType" �A�C�e����t�^����i���肷��j�̂́A
	 *	�֐��ďo���̐Ӗ��ł��B
	 */
	string getFileType(){	return "OuDia.3" ; } ;
	
	
	
	// ********************************
	//	CDedRosenFileData
	// ********************************
	/**
	 *	  CdConnectedString �I�u�W�F�N�g�ɁA
	 *	  CDedRosenFileData �̑�����ǉ����܂��B
	 *	@param aCDedRosenFileData [in]
	 *	  CDedRosenFileData ���w�肵�Ă��������B
	 *	@param pCdConnectedString [in,out]
	 *	  ���̊֐��́A���̃I�u�W�F�N�g�ɁA CdConnectedString2::CdItem ��
	 *	�ǉ����܂��B
	 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă��� CdConnectedString2::CdItem ��
	 *	�ێ����܂��B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-11 ;	//	Rosen �̓��e���s��
	 *	-	-21 ;	//	DispProp �̓��e���s��
	 */
	int CDedRosenFileData_to_CdConnectedString( 
			const CDedRosenFileData& aCDedRosenFileData , 
			CdConnectedString2* pCdConnectedString ) ;
	
	/**
	 *	  CdConnectedString �I�u�W�F�N�g����A
	 *	  CDedRosenFileData_To_CdConnectedString() �֐��ɂ���č쐬���ꂽ
	 *	�A�C�e����ǂݍ��݁A CDedRosenFileData �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	@param pCDedRosenFileData [out]
	 *	  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	 *	@param aCdConnectedString [in]
	 *	  ������ێ����Ă��� CdConnectedString �I�u�W�F�N�g���w�肵�Ă��������B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *		-	-1 ;	//	FileType ������������܂���B
	 *		-	-11 ;	//	Rosen �̓��e���s��
	 *		-	-21 ;	//	DispProp �̓��e���s��
	 */
	int CDedRosenFileData_from_CdConnectedString( 
			CDedRosenFileData* pCDedRosenFileData ,
			const CdConnectedString2& aCdConnectedString ) ;
	
	/**
		  CdConnectedString �I�u�W�F�N�g��
		���̃N���X�ŉ��߉\�ȃt�H�[�}�b�g���ۂ��𔻒肵�܂��B
	@param aCdConnectedString [in]
		  ������ێ����Ă��� CdConnectedString �I�u�W�F�N�g���w�肵�Ă��������B
	@return
		-	0 ;	//	���߉\�ł��B
		-	-1 ;	//	FileType ������������܂���B
		
	@note
		FileType �̒l�𔻒肵�܂��B
	*/
	int isEncodeAbleFormat( 
			const CdConnectedString2& aCdConnectedString ) ;
	
	
	/**
	 *	  CDedRosenFileData �̕ێ�����f�[�^����A
	 *	�w�H���t�@�C���x(.ded) �`���̕�������쐬���܂��B
	 *
	 *	@param aCDedRosenFileData [in]
	 *	  CDedRosenFileData ���w�肵�Ă��������B
	 *	@param pString [out]
	 *	  ���̊֐��́A���̕�����I�u�W�F�N�g�ɁA
	 *	�w�H���t�@�C���x(.ded) �`���̕������ݒ肵�܂��B
	 *	  ���̃I�u�W�F�N�g������܂ŕێ����Ă���������͔j�����܂��B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-11 ;	//	Rosen �̓��e���s��
	 *	-	-21 ;	//	DispProp �̓��e���s��
	 */
	int CDedRosenFileData_to_string( 
			const CDedRosenFileData& aCDedRosenFileData , 
			string* pString ) ;
	
	/**
	 *	  CDedRosenFileData_to_string() �Ő�������
	 *	�w�H���t�@�C���x(.ded) �`���̕���������߂��A
	 *	 CDedRosenFileData �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	@param pCDedRosenFileData [out]
	 *	  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	 *	@param aString [in]
	 *	  CDedRosenFileData_to_string() �Ő�������
	 *	�w�H���t�@�C���x(.oud) �`���̕�������w�肵�Ă��������B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *		-	-1 ;	//	FileType ������������܂���B
	 *		-	-11 ;	//	Rosen �̓��e���s��
	 *		-	-21 ;	//	DispProp �̓��e���s��
	 *		-	-101 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
	 */
	int CDedRosenFileData_from_string( 
			CDedRosenFileData* pCDedRosenFileData ,
			const string& aString ) ;

	/**
		�t�@�C���̓��e���i�[����������
		���̃N���X�ŉ��߉\�ȃt�H�[�}�b�g���ۂ��𔻒肵�܂��B
	@param aString [in]
		  CDedRosenFileData_to_string() �Ő�������
		�w�H���t�@�C���x(.oud) �`���̕�������w�肵�Ă��������B
	@return
		-	0 ;	//	���߉\�ł��B
		-	-1 ;	//	FileType ������������܂���B
		-	-101 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
		
	@note
		FileType �̒l�𔻒肵�܂��B
	*/
	int isEncodeAbleFormat( 
			const string& aString  ) ;
	
};
#endif /*CconvCDedRosenFileData_03_h*/
