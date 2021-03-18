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
//	CGdiCache.h
// ****************************************************************
*/
/** @file */
#ifndef  CGdiCache_h
#define  CGdiCache_h

#include <windows.h>
#include <map>
#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcdCd\DcDrawProp\CdPenProp.h"
#include "DcdCd\DcDrawProp\CdBrushProp.h"

// ****************************************************************
//	CGdiCache
// ****************************************************************
/**
 * @brief
 *	GDI�I�u�W�F�N�g�̑����ƁA�n���h���̑Ώƕ\��ێ����܂��B
 *	�Ώƕ\�ɃG���g�����Ȃ��ꍇ�́AGDI�I�u�W�F�N�g�̃n���h���𐶐����āA
 *	�Ώƕ\�ɒǉ����܂��B
 *
 *	�Ώƕ\�ɒǉ������G���g����GDI�I�u�W�F�N�g�̃n���h���̔j���̐Ӗ��́A
 *	this �ɂ���܂��B
 *
 * �y�g�����z
 *
 *	�P�D  �R���X�g���N�^�ŃI�u�W�F�N�g�𐶐����Ă��������B
 *
 *	�Q�D  CreateFont() ���g���ƁA�w�肳�ꂽ���� CdFontProp �ɑΉ�����
 *	�t�H���g�n���h���𐶐����ĕԂ��܂��B�����ɁA�����ƃn���h����Ώƕ\
 *	 m_HFONTMap �ɓo�^���܂��B
 *	  ���ɓ��������� CreateFont() ���Ăяo���ꂽ�ꍇ�́A�O���
 *	�t�H���g�n���h����Ԃ��܂��B
 *	
 *	�R�D  �f�X�g���N�^�ł́A�Ώƕ\ m_HFONTMap �ɓo�^����Ă���
 *	�t�H���g�n���h�������ׂĉ�����܂��B
 */
class CGdiCache
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:

	typedef std::map< CdFontProp , HFONT >	HFONTMap ;
	typedef std::map< CdPenProp , HPEN >	HPENMap ;
	typedef std::map< CdBrushProp , HBRUSH >	HBRUSHMap ;

// ********************************
///@name �W��
// ********************************
///@{
 private:
	/**
	 *	�t�H���g�����ƃt�H���g�n���h���̑Ώƕ\�ł��B
	 *	HFONT �̔j���̐Ӗ��� this �ɂ���܂��B
	 */
	HFONTMap	m_HFONTMap ;
	/**
	 *	�y�������ƃy���n���h���̑Ώƕ\�ł��B
	 *	HPEN �̔j���̐Ӗ��� this �ɂ���܂��B
	 */
	HPENMap	m_HPENMap ;
	/**
	 *	�u���V�����ƃu���V�n���h���̑Ώƕ\�ł��B
	 *	HBRUSH �̔j���̐Ӗ��� this �ɂ���܂��B
	 */
	HBRUSHMap	m_HBRUSHMap ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	CGdiCache() ;
	virtual ~CGdiCache() ;

// ********************************
//	CGdiCache
// ********************************
 public:
	/**
	 * 	CdFontProp�I�u�W�F�N�g�̑��������ƂɁA�t�H���g�𐶐����܂�
	 * @param aCdFontProp [in]
	 * 	�t�H���g�������w�肵�Ă��������B
	 * @param hDc [in]
	 * 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 * 	PointTextHeight �Ŏw�肳��Ă���ꍇ�́ALOGFONT�ɕϊ�
	 * 	����ۂɂ́A���̕ϊ��ɂ́A�t�H���g�̕`����s��HDC���K�v�ł��B
	 * 	�����ɂ́A����HDC���w�肵�Ă��������B
	 * 	�����A���̃P�[�X��HDC�� NULL ���w�肵���ꍇ�́A�X�N���[��DC��
	 * 	���Ƃ�LOGFONT�\���̂��쐬���܂��B
	 * 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 * 	Logicalunit... �Ŏw�肳��Ă���ꍇ�́A����HDC�ɂ�
	 * 	�Ӗ�������܂���B
	 * @return
	 *	�t�H���g�̃n���h����Ԃ��܂��B
	 *	���̃n���h���̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *	�֐��ďo���́A�n���h����������Ă͂����܂���B
	 */
	virtual HFONT	CreateFont(  const CdFontProp& aCdFontProp , 
			HDC hDc ) ;
	
	/**
	 * 	CdPenProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 * @param aCdPenProp [in]
	 * 	�y���������w�肵�Ă��������B
	 * @return
	 *	�y���̃n���h����Ԃ��܂��B
	 *	���̃n���h���̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *	�֐��ďo���́A�n���h����������Ă͂����܂���B
	 */
	virtual HPEN	CreatePen(  const CdPenProp& aCdPenProp ) ;

	/**
	 * 	CdBrushProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 * @param aCdBrushProp [in]
	 * 	�y���������w�肵�Ă��������B
	 * @return
	 *	�y���̃n���h����Ԃ��܂��B
	 *	���̃n���h���̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *	�֐��ďo���́A�n���h����������Ă͂����܂���B
	 */
	virtual HBRUSH	CreateBrush(  const CdBrushProp& aCdBrushProp ) ;
};
#endif /*CGdiCache_h*/

