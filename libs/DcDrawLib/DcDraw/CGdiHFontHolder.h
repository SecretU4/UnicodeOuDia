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
//	CGdiHFontHolder.h
//	$Id: CGdiHFontHolder.h 92 2012-09-21 10:56:03Z okm $
// ****************************************************************
#ifndef  DcDraw_CGdiHFontHolder_h
#define  DcDraw_CGdiHFontHolder_h
/** @file */
#include <windows.h>
#include "DcdCd\DcDrawProp\CdFontProp.h"

namespace DcDrawLib{
namespace DcDraw{

	using namespace DcdCd::DcDrawProp;


/**
@brief
	�t�H���g�n���h����ێ�����I�u�W�F�N�g�ł��B

	�f�X�g���N�^�ł̓n���h�����폜���܂��B
*/
class CGdiHFontHolder
{
private:
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
		�t�H���g�̑�����ێ����܂��B
	*/
	CdFontProp	m_FontProp ;
	/**
		�t�H���g�n���h����ێ����܂��B
		�R���X�g���N�^�Ō��܂�܂��B
		�f�X�g���N�^�́A���̃n���h���� DeleteObject() �ō폜���܂��B
	*/
	HFONT	m_hFont ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CGdiHFontHolder( 
		const CdFontProp& aFontProp ,
		HFONT hFont ) 
		: m_FontProp( aFontProp ) 
		, m_hFont( hFont )
	{
	};
	virtual ~CGdiHFontHolder()
	{	
		if ( m_hFont != NULL )
		{
			DeleteObject( m_hFont ) ;
			m_hFont = NULL ;
		}
	};
public:
	// ********************************
	///@name	CGdiHFontHolder-����
	// ********************************
	///@{
	CdFontProp	getFontProp()const{	return m_FontProp ;};
	HFONT	getHFont(){	return m_hFont ;};
	///@}

};

} //namespace DcDraw
} //namespace DcDrawLib

#endif //DcDraw_DcDraw_CGdiHFontHolder_h
