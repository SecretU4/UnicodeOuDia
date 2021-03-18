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
//	CconvWinDia.h
// ****************************************************************
*/
#ifndef  CconvWinDia_h
#define  CconvWinDia_h

/** @file */ 
#include <string>
#include "..\DedRosenFileData\CDedRosenFileData.h"

namespace WinDia{ 
	using namespace DedRosenFileData;
// ****************************************************************
//	CconvWinDia
// ****************************************************************
/**
 *	@brief
 *	�y�T�v�z
 *	DiagramEdit �̃G���e�B�e�B�N���X�̃I�u�W�F�N�g�̑����f�[�^�̓��e���A
 *	WinDia �t�@�C���ɕϊ�����֐������^���Ă��܂��B
 *	
 *	<H4>
 *	�y�g�����P�|WinDia�t�@�C���̓ǂݍ��݁z
 *	</H4>
 *	
 * �P�D  WinDia�t�@�C���̓��e���A�e�L�X�g���[�h�� string ��
 *	�ǂݍ���ł��������B
 *	����́A stringFromFile() ���g���܂��B
 *
 * �Q�D  CDedRosenFileData_From_WinDiaFileString() �֐��ŁA
 *	����������߂��Ă��������B
 *	���̊֐��́A������̓��e�� CentDedRosen �I�u�W�F�N�g�ɔ��f���܂��B
 *	
 *	<H4>
 *	�y�g�����Q�|WinDia�t�@�C���ɕۑ��z
 *	</H4>
 *	
 * �P�D  CentDedRosenFileData_To_WinDiaFileString() �֐��ŁA
 *	������𐶐����Ă��������B
 *
 * �Q�D  �P�D�Ő���������������A�e�L�X�g���[�h�Ńt�@�C����
 *	�ۑ����Ă��������B
 *	����́A stringToFile() ���g���܂��B
 */
class CconvWinDia
{
// ********************************
//	CconvWinDia
// ********************************
public:

	// ********************************
	//	CDedRosenFileData
	// ********************************
	/**
	 *	  WinDia �t�@�C���`���̕����� �����߂��A
	 *	 CDedRosenFileData �I�u�W�F�N�g�ɔ��f���܂��B
	 *	
	 *	@param pCDedRosenFileData [out]
	 *	  ���̊֐��͂��̃I�u�W�F�N�g�ɁA�����𔽉f���܂��B
	 *	@param strWinDiaFileString [in]
	 *	  WinDia �t�@�C���`���̕����� ���w�肵�Ă�������
	 *	(���s�����́A "\n" �łȂ��Ă͂Ȃ�܂���B
	 *	�t�@�C�����e�L�X�g���[�h�œǂݍ��񂾓��e���i�[���Ă�������)�B
	 *	@return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-21 ;	//	Train00 �̔ԍ������̒l���s�K�؂ł��B
	 */
	int CDedRosenFileData_From_WinDiaFileString(
			CDedRosenFileData* pCDedRosenFileData ,
			const std::string& strWinDiaFileString ) ;

	/**
	 *	 CDedRosenFileData �I�u�W�F�N�g�����ƂɁA
	 *	  WinDia �t�@�C���`���̕����� ���쐬���܂��B
	 *	
	 * @param pCDedRosenFileData [in]
	 *	  CDedRosenFileData ���w�肵�Ă��������B
	 * @param idxDia [in]
	 *	�ۑ�����_�C���̃C���f�N�X���w�肵�ĉ������B
	 * @param pstrWinDiaFileString [out]
	 *	���̊֐��͂��̃I�u�W�F�N�g��
	 *	  WinDia �t�@�C���`���̕����� ���������݂܂��B
	 * @return
	 *	  ���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	- 21 ;	//	WinDIA �`���ł́A��Ԏ�ʂ�24��ނ܂łɐ�������Ă��܂��B
	 *	- 22 ;	//	���̂̒��������p�T�����𒴂����Ԏ�ʂ�����܂��B
	 *			//	WinDIA �`���ɕۑ����邽�߂ɂ́A���ׂĂ̗�Ԏ�ʗ��̂�
	 *			//	�S�p�Q�����ȓ��łȂ��Ă͂Ȃ�܂���B
	 *	- 1 ;	//	idxDia �̎w�肪�s���ł��B
	 */
	int CDedRosenFileData_To_WinDiaFileString( 
			const CDedRosenFileData* pCDedRosenFileData ,
			int idxDia ,
			std::string* pstrWinDiaFileString ) ;
};

} //namespace WinDia
#endif /*convWinDia_h*/
