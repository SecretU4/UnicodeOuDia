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
//	CdDedDispProp.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDedDispProp_h
#define  CdDedDispProp_h

#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcdCd\DcDrawProp\CdColorProp.h"

#include "entDed\CentDed.h"
#include "entDed\CentDedRessyasyubetsu.h"

namespace DedRosenFileData{
	using namespace DcDrawLib::DcdCd::DcDrawProp;
// ****************************************************************
//	CdDedDispProp
// ****************************************************************
/**
  @brief
 	�y�T�v�z  DiagramEdit �̕\���Ɋ֌W����v���p�e�B��ێ�����
 	�P���f�[�^�N���X�ł��B
 */
class CdDedDispProp
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		 �����\��ʁE�������t�H���g�B

		�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
		�����Ĉȉ��̑������ǉ�����܂��B
		- [1]��Bold
		- [2]��Itaric
		- [3] �� Bold | Itaric 
	 */
	CdFontProp	m_arJikokuhyouFont[entDed::CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT] ;

	/**
		 �����\��ʁE�c�����t�H���g�B

		�K��l�́A	CdFontProp( 9 ,"@�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropJikokuhyouVFont ;

	/**
		 �_�C����ʉw���t�H���g�B
		�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropDiaEkimeiFont ;

	/**
		 �_�C����ʎ����t�H���g�B
		�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropDiaJikokuFont ;

	/**
		 �_�C����ʗ�ԃt�H���g�B
		�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropDiaRessyaFont ;

	/**
		 �R�����g�r���[�t�H���g�B
		�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B
	 */
	CdFontProp	m_fontpropViewComment ;

	/**
		 �_�C����ʕ����F�B
		�K��l�́A���B
	 */
	CdColorProp	m_colorDiaMojiColor ;
	/**
		 �_�C����ʔw�i�F�B
		�K��l�́A���B
	 */
	CdColorProp	m_colorDiaHaikeiColor ;

	/**
		 �_�C����ʗ�Ԑ��F�B
		�K��l�́A���B

	@todo
	 ���̃t�B�[���h�́A�t�@�C���t�H�[�}�b�g�������ɔp�~���܂��B
	*/
	CdColorProp	m_colorDiaRessyaColor ;

	/**
		 �_�C����ʏc�����F�B
		�K��l�́A���B
	 */
	CdColorProp	m_colorDiaJikuColor ;

	/**
		�w�����̕���ێ����܂��B
		�P�ʂ́A�S�p�ł̕������ł��B
		�܂�A�w�����̕��́A
	
			�����̍��� �~ m_iEkimeiLength 
		
		�ƂȂ�܂��B
		�f�t�H���g�l�� 6 �Ƃ��܂��B�ŏ��l�� 1�E�ő�l��29(���p�Ȃ�58) �ł��B
	 */
	int m_iEkimeiLength ;

	/**
		�����\�r���[�́A��ԗ��̕���ێ����܂��B
		�P�ʂ́A���p�ł̕������ł��B

		��ԗ��̕��́A �����̍����~m_iJikokuhyouRessyaWidth / 2 �ƂȂ�܂��B

		�K��l�� 5 �Ƃ��܂��B�ŏ��l�� 4,�ő�l��8�ł��B
	*/
	int m_iJikokuhyouRessyaWidth ;


	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CdDedDispProp() ;
	
	
public:
	// ********************************
	///@name CdDedDispProp-����
	// ********************************
	///@{
	/**
	@param idx [in]
		�C���f�N�X���w�肵�Ă��������B
		�͈͂́A 0 �ȏ�A JIKOKUHYOUFONT_COUNT �����ł��B
	*/
	CdFontProp	getJikokuhyouFont( int idx )const;

	/**
	@param idx [in]
		�C���f�N�X���w�肵�Ă��������B
		�͈͂́A 0 �ȏ�A JIKOKUHYOUFONT_COUNT �����ł��B
	@param value [in]
		�t�H���g�������w�肵�Ă��������B
	*/
	CdDedDispProp& setJikokuhyouFont( int idx , const CdFontProp& value );

	CdFontProp	getJikokuhyouVFont()const;
	CdDedDispProp& setJikokuhyouVFont( const CdFontProp& value );

	CdFontProp	getDiaEkimeiFont()const;
	CdDedDispProp& setDiaEkimeiFont( const CdFontProp& value );
	CdFontProp	getDiaJikokuFont()const;
	CdDedDispProp& setDiaJikokuFont( const CdFontProp& value );
	CdFontProp	getDiaRessyaFont()const;
	CdDedDispProp& setDiaRessyaFont( const CdFontProp& value );
	CdFontProp	getViewCommentFont()const;
	CdDedDispProp& setViewCommentFont( const CdFontProp& value );
		
	CdColorProp	getDiaMojiColor()const;
	CdDedDispProp& setDiaMojiColor( const CdColorProp& value );
	CdColorProp	getDiaHaikeiColor()const;
	CdDedDispProp& setDiaHaikeiColor( const CdColorProp& value );
	CdColorProp	getDiaRessyaColor()const;
	CdDedDispProp& setDiaRessyaColor( const CdColorProp& value );
	CdColorProp	getDiaJikuColor()const;
	CdDedDispProp& setDiaJikuColor( const CdColorProp& value );
	
	int getEkimeiLength()const;
	CdDedDispProp& setEkimeiLength( int value );
	int getJikokuhyouRessyaWidth()const;
	CdDedDispProp& setJikokuhyouRessyaWidth( int value );
	/**
	 @return
		�w���̕����擾���邽�߂̕�������쐬���܂��B
		���̊֐��́A�S�p������ m_iEkimeiLength �������ׂ�
		������i���e�͎g��Ȃ��j��Ԃ��܂��B
	 */
	std::string createEkimeiExtentString()const ;

	/**
		���ׂĂ̑������A
		������ԁi�f�t�H���g�R���X�g���N�^�Ő���������ԁj
		�ɂ��܂��B
	 */
	void clear() ;
	///@}
};

} //namespace DedRosenFileData

#endif /*CdDedDispProp_h*/


