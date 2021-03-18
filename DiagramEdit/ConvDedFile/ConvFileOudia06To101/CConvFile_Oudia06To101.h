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
// $Id: CConvFile_Oudia06To101.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
#ifndef  CConvFile_Oudia06To101_h
#define  CConvFile_Oudia06To101_h
/** @file */
#include "IfConvFile.h"
/**
@brief
	OuDia�t�@�C�� Ver.6 �� Ver.1.01 �ɕϊ����܂��B

	�ϊ����e�́A�ȉ��̂Ƃ���ł��B

	@code
	��4.0��[FileType]

	  "OuDia.6"��"OuDia.1.01" �ɕϊ����܂��B

	��4.1��[Rosen.Ressyasyubetsu[]]

	��4.1.1��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]

	��[Rosen.Ressyasyubetsu]�ɁA[Rosen.Ressyasyubetsu.JikokuhyouFont]���Ȃ��ꍇ�B
	   ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 �Ƃ��܂��B

	��[Rosen.Ressyasyubetsu]�ɁA[Rosen.Ressyasyubetsu.JikokuhyouFont]������ꍇ�B
�@	  ��[DispProp.JikokuhyouFont[]]�ɓ����t�H���g������ꍇ�B
  �@	��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
			DispProp.JikokuhyouFont[]�́A����t�H���g�̃C���f�N�X
�@	  ��[DispProp.JikokuhyouFont[]]�ɓ����t�H���g���Ȃ��ꍇ�B
�@�@	��[DispProp.JikokuhyouFont[]]�̗v�f����8�ȓ��̏ꍇ�B
�@�@�@	  ��[DispProp.JikokuhyouFont[]]�̖����ɗv�f��ǉ����A
�@�@�@�@	[Rosen.Ressyasyubetsu.JikokuhyouFont]�̓��e���R�s�[
  �@�@	  ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
  �@�@�@	����ǉ�����DispProp.JikokuhyouFont[] �̃C���f�N�X
�@�@	��else
�@�@�@	  ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 �Ƃ��܂��B

	��4.1.2��[Rosen.Ressyasyubetsu.JikokuhyouFont]
�@	  �d�l����͔p�~����܂����A�R���o�[�^�͂��̒l��ҏW���܂���B

	��4.2��[DispProp.JikokuhyouFont[]]

�@	  �ϊ��́A[Rosen.Ressyasyubetsu.JikokuhyouFontIndex[]]�̕ϊ��Ɠ����ɍs���܂��B
	@endcode



*/
class CConvFile_Oudia06To101 : public IfConvFile
{
public:
	CConvFile_Oudia06To101();
	virtual ~CConvFile_Oudia06To101();
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
		-	-1 ;	//	FileType ������������܂���B
		-	-11 ;	//	�t�@�C�����������t�H�[�}�b�g�ł͂���܂���B
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

	�y�����z

�@	  .oud �t�@�C�� �� Oudia.5 �ł́A [FileType] �ɁA"OuDia.5" ���L�q����Ă��܂��B
		
	@param pLeftFormat [in]
		LeftFormat �̃f�[�^���w�肵�Ă��������B
	@return  
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 �ȏ� ;	//	�ϊ��\�ȃt�H�[�}�b�g�ł��B
		-	-1 ;	//	FileType ������������܂���B
		-	-11 ;	//	�t�@�C�����������t�H�[�}�b�g�ł͂���܂���B
	*/
	virtual int isLeftFormat( 
		const IfByteBuffer* pLeftFormat)  ; 

	/**
	@return 
		- true ;	//	RightToLeft(),isRightFormat() ���\�b�h���T�|�[�g���Ă��܂��B
		- false ;	//	RightToLeft(),isRightFormat() ���\�b�h���T�|�[�g���Ă��܂���B
	*/
	virtual bool RightToLeftIsSupported() ; 

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





#endif //CConvFile_Oudia06To101_h


