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
//	IfDcdTarget.h
// ****************************************************************
*/
/** @file */
#ifndef  IfDcdTarget_h
#define  IfDcdTarget_h

#include "DcdCd\Pos\CdDcdZoneXy.h"
#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcdCd\DcDrawProp\CdPenProp.h"
#include "DcdCd\DcDrawProp\CdBrushProp.h"
#include ".\CGdiHFontHolder.h"
#include ".\CGdiHPenHolder.h"
#include ".\CGdiHBrushHolder.h"
#include "Ou\Ou.h"

// ****************************************************************
//	IfDcdTarget
// ****************************************************************
/**
  @brief
  �y�T�v�z
 	DcDraw���f���ɂ�����A�`����s���̈��\���I�u�W�F�N�g�̃C���^�[�t�F�[�X
  	�ł��B
 
  	  ���Ƃ��΁A�E�C���h�E��WM_PAINT���b�Z�[�W������������A�E�C���h�E�́A
  	���̃C���^�[�t�F�[�X���T�|�[�g����N���X CdDcdTargetOnPaint �𐶐����A
  	����� IfDcDraw �C���^�[�t�F�[�X���T�|�[�g����`��I�u�W�F�N�g�ɓn���܂��B
 */
class IfDcdTarget
{
 public:
	/**
	 @return
	 	�`����s��DC���擾���܂��B
	 	����HDC�̔j���̐Ӗ��́Athis�ɂ���܂��B
	*/
	virtual HDC	getHdc() = 0 ;
	
	/**
	 @return
	 	�`��̕K�v�ȗ̈�̍��W�͈͂��擾���邱�Ƃ��ł��܂��B
	 	�P�ʂ́A�_���P�ʂł��B
	*/
	virtual CdDcdZoneXy getZone() = 0 ;
	
	/**
	 @return
	 	�`�悪�L���Ȕ͈͂��擾�ł��܂��B
	 	�ʏ�́AgetZone()�Ɠ����̈�ƂȂ�܂��B
	 
	 	�E�C���h�E��WM_PAINT�ɂ��`��̏ꍇ�A���̊֐����Ԃ��̂́A
	 	�ĕ`�悪�K�v�ȗ̈�ƂȂ�܂��B
	 	���̗̈�𖳎����Ă����܂��܂���B�������A���͈̔͊O�ւ̕`���
	 	�Ӗ�������܂���̂ŁA���͈̔͊O�ւ̕`���}������悤�ɂ���΁A
	 	�`�揈���̌����̉��P�����҂ł��܂��B
	*/
	virtual CdDcdZoneXy getDrawableZone() = 0 ;
	
	/**
	 	CdFontProp�I�u�W�F�N�g�̑��������ƂɁA�t�H���g�𐶐����܂�
	 @param aCdFontProp [in]
	 	�t�H���g�������w�肵�Ă��������B
	 @return
		�t�H���g�̃n���h����ێ����� CGdiHFontHolder ��Ԃ��܂��B
	*/
	virtual Ou<CGdiHFontHolder>	createGdiHFontHolder(  const CdFontProp& aCdFontProp ) = 0 ;
	
	/**
	 	CdPenProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 @param aCdPenProp [in]
	 	�y���������w�肵�Ă��������B
	 @return
		�y���̃n���h����ێ����� CGdiHPenHolder ��Ԃ��܂��B
	*/
	virtual  Ou<CGdiHPenHolder>		createGdiHPenHolder(  const CdPenProp& aCdPenProp ) = 0 ;

	/**
	 	CdBrushProp�I�u�W�F�N�g�̑��������ƂɁA�u���V�𐶐����܂�
	 @param aCdBrushProp [in]
	 	�u���V�������w�肵�Ă��������B
	 @return
		�u���V�̃n���h����ێ����� CGdiHBrushHolder ��Ԃ��܂��B
	*/
	virtual Ou<CGdiHBrushHolder>	createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) = 0 ;

	virtual ~IfDcdTarget(){};
};

#endif /*IfDcdTarget_h*/
