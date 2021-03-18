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
//	CVerticalTextElementBuilder.h
// ****************************************************************
*/
/** @file */
#ifndef  DcDrawLib_DcDraw_CVerticalTextElementBuilder_h
#define  DcDrawLib_DcDraw_CVerticalTextElementBuilder_h

#include "DcDraw\CVerticalTextElement.h"
#include "NsMu\Mui.h"

namespace DcDrawLib{
namespace DcDraw{
	using namespace OuLib::NsMu ;
	using namespace std ;

/**
@brief
	�e�L�X�g�����߂��āA�c�������̃e�L�X�g�\��������v�f��\���A�P���f�[�^�N���X�ł��B
	
	CVerticalTextElementBuilder::scan() ���\�b�h�́A���������͂��A
	��͌��ʂ� CVerticalTextElement �̃R���e�i�Ƃ��č\�����܂��B
*/
class CVerticalTextElementBuilder
{
protected:
	// ================================
	///@name �����֐�
	// ================================
	///@{
	/**
		��������(�S�p�E���p)���ۂ��𔻒f���܂��B
	@param aStr [in]
		���f���s���������w�肵�Ă��������B
	@return
		- true: aStr �� ��(�S�p�E���p)�ł��B
	*/
	static bool isSpace( const string& aStr );

	/**
		��������Ǔ_��( , . �A�B)���ۂ��𔻒f���܂��B
	@param aStr [in]
		���f���s���������w�肵�Ă��������B
	@return
		- true: aStr �� ��Ǔ_�ł��B
	*/
	static bool isDelimiter( const string& aStr );
	///@}
public:
	// ********************************
	///@name CVerticalTextElementBuilder-����
	// ********************************
	///@{
	/**
	  	����������߂��āA�w������v�f�x�̏W�����쐬���A�R���e�i�ɒǉ����܂��B
	@param aStr [in]
	  	���߂��镶������w�肵�Ă��������B
	@param pCStrElementCont [out]
	  	���̊֐��͂��̃R���e�i�̖����ɁA aStr �����߂���������v�f��
	  	�ǉ����܂��B	
	  	���̃R���e�i������܂ŕێ����Ă����v�f�͔j�����܂��B
	@param bTwoDegiLateral [in]
		- true: 2�����̔��p�������A [H_HANKAKU] �Ƃ��܂��B
		- false: 2�����̔��p�������A[V_HANKAKU] �Ƃ��܂��B
	  
	  
	  	�i�P�j�@��������w������v�f�x�ɕ���
	  	
	  	�@��������A���s�s�\�ȍ\���v�f�ɕ������܂��B���̕����ł́A
	  	����ȍ~���́u���s�s�\�ȍ\���v�f�v�ЂƂ��w������v�f�x�ƌĂт܂��B
	  	
	  	�@�w������v�f�x�́A�ȉ��̂R�̎�ނɋ敪����܂��B
	  	
	  		- [V_ZENKAKU]  �c�����t�H���g���g���ĕ`�悷��A�A�������S�p����
	  		- [V_HANKAKU]  �c�����t�H���g���g���ĕ`�悷��A�A���������p����
	  		- [H_HANKAKU]  �������t�H���g���g���ĕ`�悷��A�P�E�Q�����̔��p����
	  			�i���̑O��ɔ��p�������Ȃ����Ɓj
	  	
	  	
	  	�@�i��jbTwoDegiLateral=true �̏ꍇ
	  		������ "���s��12�^28�`1�^5�́A900���ɕύX" �́A
	  		�ȉ��́w������v�f�x�ɕ������܂��B
	  		- "��"	[V_ZENKAKU]
	  		- "�s"	[V_ZENKAKU]
	  		- "��"	[V_ZENKAKU]
	  		- "12" 		[H_HANKAKU]
	  		- "�^" 		[V_ZENKAKU]
	  		- "28" 		[H_HANKAKU]
	  		- "�`"		[V_ZENKAKU]
	  		- "1"			[H_HANKAKU]
	  		- "�^"		[V_ZENKAKU]
	  		- "5" 		[H_HANKAKU]
	  		- "�́A"		[V_ZENKAKU]
	  		- "900"		[V_HANKAKU]
	  		- "��"	[V_ZENKAKU]
	  		- "��"	[V_ZENKAKU]
	  		- "��"	[V_ZENKAKU]
	  		- "�X"	[V_ZENKAKU]
	  	
	  	�@��Ǔ_�̑O�ł͉��s���Ȃ��ق����]�܂����ł��B���̂��߁A��Ǔ_��
	  	�O�̕����́w������v�f�x�̈ꕔ�Ƃ��܂��B
	  	�@�A���������p�p�����̓r���ł͉��s���Ȃ��ق����]�܂����ł��B���̂��߁A
	  	�A���������p�p�����́A��́w������v�f�x�Ɋi�[������̂Ƃ��܂��B
	  	�������A�󔒂�L���ނ��o�������ꍇ�́A�����Łw������v�f�x��
	  	�I�����̂Ƃ��܂��B
	 */
	static void scan( 
		const std::string& aStr , 
		Mui<CVerticalTextElement>* muCVerticalTextElement ,
		bool bTwoDegiLateral = true ) ;

	///@}
};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*DcDrawLib_DcDraw_CVerticalTextElementBuilder_h*/



