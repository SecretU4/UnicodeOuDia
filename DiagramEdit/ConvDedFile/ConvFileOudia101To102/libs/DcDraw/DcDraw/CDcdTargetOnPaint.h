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
//	CDcdTargetOnPaint.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdTargetOnPaint_h
#define  CDcdTargetOnPaint_h

#include "./IfDcdTarget.h"
#include "./CGdiCache.h"

// ****************************************************************
//	CDcdTargetOnPaint
// ****************************************************************
/**
* @brief
* �y�T�v�z
*	�E�C���h�E��WM_PAINT�����������Ƃ��́A�`��̈��\���N���X�ł��B
*
* 	  ���̃N���X�́AWM_PAINT���b�Z�[�W�����������Ƃ��̃C�x���g�n���h����
* 	�X�^�b�N��ɐ������邱�Ƃ�z�肵�Ă��܂��B
* 	  DcDraw���f���ɂ�����A�`����s���̈��\���I�u�W�F�N�g�̃C���^�[�t�F�[�X
* 	�ł��B
*
* �y�g�����z
*
* �P�D WM_PAINT ���b�Z�[�W���E�C���h�E�ɓ��������Ƃ��ɂ����A
* 	�I�u�W�F�N�g���X�^�b�N��ɐ������Ă��������B
* 	  �g�����́A���̂R�ʂ肪����܂��B
*
* 	�i�P�j  BeginPaint() ���Ăяo���āA�R���X�g���N�^��PAINTSTRUCT��n����
* 	���������B
*
* 	�i�Q�j   MFC�A�v���P�[�V�����̏ꍇ�́ACPaintDC�I�u�W�F�N�g�𐶐�����
* 	���̃����o CPaintDC::m_ps ���R���X�g���N�^�ɓn���Ă��������B
*
* 	�i�R�j�E�C���h�E�n���h�����A�R���X�g���N�^�ɓn���Ă��������B
* 	���̃N���X�́A�R���X�g���N�^�� BeginPaint() ���Ăяo���ADC���擾���܂��B
* 	  ���̏ꍇ�Athis�̓f�X�g���N�^�ł�EndPaint() �����s���܂��B
*
* �Q�D   this �� IfDcDraw �I�u�W�F�N�g�ɓn���āA�`����s�킹�Ă��������B
* 
*/
class CDcdTargetOnPaint : public IfDcdTarget
{
// --------------------------------
///@name	�����f�[�^
// --------------------------------
///@{
 private:
	/**
	* 	�E�C���h�E�n���h���B
	* 	�R���X�g���N�^�Ō��܂�܂��B
	* 	���̃E�C���h�E��,this��蒷���������Ȃ��Ă͂Ȃ�܂���B
	*/
	HWND		m_hWnd ;
	
	/**
	* 	�`��̈��\���\���̂ł��B
	* 	�R���X�g���N�^�Ō��܂�܂��B
	* 
	* 	�R���X�g���N�^��PAINTSTRUCT���n���ꂽ�ꍇ�́A���̃A�h���X��
	* 	�ێ����܂��B
	* 	���̏ꍇ�AEndPaint() �̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
	* 	this���������Ă���Ԃ́AEndPaint()�����Ă͂����܂���B
	* 	�܂��APAINTSTRUCT��this���Ȃ����������Ȃ��Ă͂Ȃ�܂���B
	* 
	* 	�R���X�g���N�^��PAINTSTRUCT���n���ꂽ�Ȃ������ꍇ�́A
	* 	�R���X�g���N�^��PAINTSTRUCT�𐶐����ABeginPaint()���s���܂��B
	* 	���̏ꍇ�AEndPaint() �̐Ӗ��́Athis�ɂ���܂��B
	*/
	PAINTSTRUCT*	m_pPaintstruct ;
	
	/**
	* 	this���R���X�g���N�^��BeginPaint()���s�����ꍇ�͐^�ɂȂ�܂��B
	*/
	bool			m_bPaintstructEndPaintObligatory ;
	
	
	/**
	 *	GDI�I�u�W�F�N�g�̑����ƁA�n���h���̑Ώƕ\��ێ����܂��B
	 */
	CGdiCache	m_CGdiCache ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	* @param hWnd [in]
	* 	�E�C���h�E�n���h���B
	* 	���̃E�C���h�E��,this��蒷���������Ȃ��Ă͂Ȃ�܂���B
	* @param pPaintstruct [in]
	* 	�`��̈��\���\���̂ł��B
	* 	�R���X�g���N�^�Ō��܂�܂��B
	*/
	CDcdTargetOnPaint( HWND hWnd , PAINTSTRUCT* pPaintstruct ) ;

	/**
	* @param hWnd [in]
	* 	�E�C���h�E�n���h���B
	* 	���̃E�C���h�E��,this��蒷���������Ȃ��Ă͂Ȃ�܂���B
	*/
	CDcdTargetOnPaint( HWND hWnd ) ;
	
	virtual ~CDcdTargetOnPaint() ;

// ********************************
///@name	IfDcdTarget
// ********************************
///@{
 public:
	/**
	* @return
	* 	�`����s��DC���擾���܂��B
	* 	����HDC�̔j���̐Ӗ��́Athis�ɂ���܂��B
	*/
	virtual HDC	getHdc() ;
	
	/**
	* @return
	* 	�`��̕K�v�ȗ̈�̍��W�͈͂��擾���邱�Ƃ��ł��܂��B
	* 	�P�ʂ́A�_���P�ʂł��B
	*/
	virtual CdDcdZoneXy getZone() ;
	
	/**
	* @return
	* 	�`�悪�L���Ȕ͈͂��擾�ł��܂��B
	* 	�ʏ�́AgetZone()�Ɠ����̈�ƂȂ�܂��B
	* 
	* 	�E�C���h�E��WM_PAINT�ɂ��`��̏ꍇ�A���̊֐����Ԃ��̂́A
	* 	�ĕ`�悪�K�v�ȗ̈�ƂȂ�܂��B
	* 	���̗̈�𖳎����Ă����܂��܂���B�������A���͈̔͊O�ւ̕`���
	* 	�Ӗ�������܂���̂ŁA���͈̔͊O�ւ̕`���}������悤�ɂ���΁A
	* 	�`�揈���̌����̉��P�����҂ł��܂��B
	*/
	virtual CdDcdZoneXy getDrawableZone() ;

	/**
	 	CdFontProp�I�u�W�F�N�g�̑��������ƂɁA�t�H���g�𐶐����܂�
	 @param aCdFontProp [in]
	 	�t�H���g�������w�肵�Ă��������B
	 @return
		�t�H���g�̃n���h����ێ����� CGdiHFontHolder ��Ԃ��܂��B
	*/
	virtual Ou<CGdiHFontHolder>	createGdiHFontHolder(  const CdFontProp& aCdFontProp ) ;
	
	/**
	 	CdPenProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 @param aCdPenProp [in]
	 	�y���������w�肵�Ă��������B
	 @return
		�y���̃n���h����ێ����� CGdiHPenHolder ��Ԃ��܂��B
	*/
	virtual  Ou<CGdiHPenHolder>		createGdiHPenHolder(  const CdPenProp& aCdPenProp ) ;

	/**
	 	CdBrushProp�I�u�W�F�N�g�̑��������ƂɁA�u���V�𐶐����܂�
	 @param aCdBrushProp [in]
	 	�u���V�������w�肵�Ă��������B
	 @return
		�u���V�̃n���h����ێ����� CGdiHBrushHolder ��Ԃ��܂��B
	*/
	virtual Ou<CGdiHBrushHolder>	createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) ;



///@}
};



#endif /*CDcdTargetOnPaint_h*/
