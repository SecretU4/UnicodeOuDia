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
// CaConvFile_Oudia02To03.h: CaConvFile_Oudia02To03 �N���X�̃C���^�[�t�F�C�X
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CACONVFILE_OUDIA02TO03_H__C6796EB2_3AB2_477C_8B68_CDF1F244CB53__INCLUDED_)
#define AFX_CACONVFILE_OUDIA02TO03_H__C6796EB2_3AB2_477C_8B68_CDF1F244CB53__INCLUDED_
/** @file */
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IfConvFile.h"
/**
@brief
	ConvFile2Dll �̃N���X
*/
class CaConvFile_Oudia02To03 : public IfConvFile  
{
public:
	CaConvFile_Oudia02To03();
	virtual ~CaConvFile_Oudia02To03();
public:
	// ********************************
	///@name IfConvFile
	// ********************************
	///@{
	/**
		LeftFormat ���� RightFormat �ւ̕ϊ����s���܂��B
	@param pLeftFormat [in]
		LeftFormat �̃f�[�^���w�肵�Ă��������B
	@param pRightFormat [out]
		���̊֐��͕ϊ�������������A
		���̃o�b�t�@�ɁARightFormat �̃f�[�^���������݂܂��B
	@param pErrorInfoString [out] 
		���̊֐��͕ϊ������s������A
		���̃o�b�t�@�ɃG���[�̓��e�������������
		�������݂܂��B
		�A���A���ׂĂ� ConvFile �N���X�����̋@�\���T�|�[�g���Ă���킯�ł�
		����܂���B
	@return  
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	pLeftFormat �͐����� LeftFormat �ł͂���܂���B
	*/
	virtual int LeftToRight( 
		const IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pRightFormat , 
		IfByteBuffer* pErrorInfoString ) ; 

	/**
		LeftFormat ���ϊ��\�ȃt�H�[�}�b�g�ł��邩�ۂ���
		���肵�܂��B
		
		���̊֐��� LeftFormat �̃f�[�^�̓����ɑ΂��ĊȒP�Ȍ�����
		�s���܂��B
		���̊֐����������Ă��A LeftToRight() ����������Ƃ�
		����܂���B
	@param pLeftFormat [in]
		LeftFormat �̃f�[�^���w�肵�Ă��������B
	@return  
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 �ȏ� ;	//	�ϊ��\�ȃt�H�[�}�b�g�ł��B
		-	-1 ;	//	pLeftFormat �͐����� LeftFormat �ł͂���܂���B
	*/
	virtual int isLeftFormat( 
		const IfByteBuffer* pLeftFormat)  ; 

	/**
	@return 
		- true ;	//	RightToLeft(),isRightFormat() ���\�b�h���T�|�[�g���Ă��܂��B
		- false ;	//	RightToLeft(),isRightFormat() ���\�b�h���T�|�[�g���Ă��܂���B
	*/
	virtual bool RightToLeftIsSupported(); 

	/**
		RightFormat ���� LeftFormat �ւ̕ϊ����s���܂��B
	@param pRightFormat [in]
		RightFormat �̃f�[�^���w�肵�Ă��������B
	@param pLeftFormat [out]
		���̊֐��͕ϊ�������������A
		���̃o�b�t�@�ɁALeftFormat �̃f�[�^���������݂܂��B
	@param pErrorInfoString [out] 
		���̊֐��͕ϊ������s������A
		���̃o�b�t�@�ɃG���[�̓��e�������������
		�������݂܂��B
		�A���A���ׂĂ� ConvFile �N���X�����̋@�\���T�|�[�g���Ă���킯�ł�
		����܂���B
		�s�v�ł����NULL�ł����܂��܂���B
	@return  
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	pLeftFormat �͐����� LeftFormat �ł͂���܂���B
		-	-2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
	*/
	virtual int RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) ; 

	/**
		RightFormat ���ϊ��\�ȃt�H�[�}�b�g�ł��邩�ۂ���
		���肵�܂��B
		
		���̊֐��� RightFormat �̃f�[�^�̓����ɑ΂��ĊȒP�Ȍ�����
		�s���܂��B
		���̊֐����������Ă��A LeftFromRight() ����������Ƃ�
		����܂���B
	@param pRightFormat [in]
		RightFormat �̃f�[�^���w�肵�Ă��������B
	@return  
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 �ȏ� ;	//	�ϊ��\�ȃt�H�[�}�b�g�ł��B
		-	-1 ;	//	pRightFormat �͐����� RightFormat �ł͂���܂���B
		-	-2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
	*/
	virtual int isRightFormat( 
		const IfByteBuffer* pRightFormat ) ; 
	///@}

};

#endif // !defined(AFX_CACONVFILE_OUDIA02TO03_H__C6796EB2_3AB2_477C_8B68_CDF1F244CB53__INCLUDED_)
