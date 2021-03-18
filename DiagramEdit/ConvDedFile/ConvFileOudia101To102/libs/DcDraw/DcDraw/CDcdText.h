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
//	CDcdText.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdText_h
#define  CDcdText_h

#include <string>

#include "str\tstring.h"

#include "DcDraw\/IfDcDraw.h"
#include "DcdCd\DcDrawProp\CdDrawTextProp.h"

// ****************************************************************
//	CDcdText
// ****************************************************************
/**
* @brief
* �y�T�v�z
* 	   DcDraw���f���ɂ�����A�e�L�X�g�̕`����s���A�C�e���ł��B
*
*	  ���̃I�u�W�F�N�g�ɑ΂��� DcDraw() ���Ăяo���ƁA�w�肳�ꂽ�̈��
*	���� m_strText �̃e�L�X�g���������݂܂��B
*/
class CDcdText : public IfDcDraw
{
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	*	�`�悷�镶����ł��B
	*	�f�t�H���g�ł͋󕶎���ł��B
	*/
	tstring			m_strText ;
	
	/**
	*	�e�L�X�g��`�悷��ۂ̑�����ێ����܂��B
	*	�f�t�H���g�ł́ADEFAULT_GUI_FONT ��P��s�ŕ`�悵�܂��B
	*/
	CdDrawTextProp	m_CdDrawTextProp ;
	
	/**
	*	���̕`�敔�i�̑傫���̖ڈ��ƂȂ�
	*	������ł��B
	*	getItemSize() �́A���̕������\���ł��镝��Ԃ��܂��B
	*	getItemSize() ���g��Ȃ��̂ł���΁A���̑����͎g���܂���B
	*
	*	�f�t�H���g�͋󕶎���ł��B���̏ꍇ�AgetItemSize() �́A
	*	m_strText ��`�悷��̂ɕK�v�ȃT�C�Y��Ԃ��܂��B
	*/
	tstring			m_strExtent ;
	
	/**
	*	���̕`�敔�i�̑傫���̍s���ł�
	*	getItemSize() �́A���̍s����\���ł��鍂����Ԃ��܂��B
	*	getItemSize() ���g��Ȃ��̂ł���΁A���̑����͎g���܂���B
	*
	*	�f�t�H���g�͂P�ł��B
	*/
	int				m_iLinesExtent ;
	
///@}

	
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	* @param strText [in]
	*	�`�悷�镶����ł��B
	* @param aCdDrawTextProp [in]
	*	�e�L�X�g��`�悷��ۂ̑�����ێ����܂��B
	*	�f�t�H���g�ł́ADEFAULT_GUI_FONT ��P��s�ŕ`�悵�܂��B
	* @param strExtent [in]
	*	���̕`�敔�i�̑傫���̖ڈ��ƂȂ�
	*	������ł�
	*	�f�t�H���g�͋󕶎���ł��B���̏ꍇ�AgetItemSize() �́A
	*	strText ��`�悷��̂ɕK�v�ȃT�C�Y��Ԃ��܂��B
	* @param iLinesExtent [in]
	*	���̕`�敔�i�̑傫���̍s���ł�
	*	getItemSize() �́A���̍s����\���ł��鍂����Ԃ��܂��B
	*	�f�t�H���g�͂P�ł��B
	*/
	CDcdText( 
		const tstring&			strText,
		const CdDrawTextProp&	aCdDrawTextProp ,
		const tstring&			strExtent = TEXT("") ,
		int						iLinesExtent = 1 
	) ;
	
	CDcdText() ;
	
	virtual ~CDcdText() ;
	
// ********************************
///@name	IfDcDraw
// ********************************
///@{
 public:
	/**
	* 	�`���v�����܂��B
	* 	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B
	*
	*	�y�I�[�o���C�h�z
	*	  �n���ꂽ�̈�ɁA m_strText ��`�悵�܂��B
	* @param pIfDcdTarget  [in]
	* 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	* @return
	* 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	*/
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	* 	���̃I�u�W�F�N�g���`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	* 	���̑傫���𒲂ׂ邱�Ƃ��ł��܂��B
	* 	�֐��Ăяo������������ IfDcDraw �I�u�W�F�N�g��`�悷��ꍇ�ɂ́A
	* 	�֐��Ăяo�����́A���̊֐��ŃA�C�e���̑傫���𒲂ׂāA
	* 	�K�؂ȃ��C�A�E�g���l���Ă���ADcDraw() �����s���邱�Ƃ��ł��܂��B
	*
	*	�y�I�[�o���C�h�z
	*	  m_strExtent �� m_lineExtent �����ƂɁA�̈�̃T�C�Y���v�Z���܂��B
	* @param pIfDcdTarget [in]
	* 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	* @param pCdDcdSizeXy [out]
	* 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	* 	���̊֐��͂��̃A�h���X�ɁA���̃A�C�e���̃T�C�Y��Ԃ��܂��B
	* 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��Ȃ��ꍇ�́A
	* 	���̒l�͕s��ł��B
	* @return
	* 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��āA
	* 	���̑傫���� *pCdDcdSizeXy�ɏ������񂾏ꍇ�͐^�ł��B
	* 	�����łȂ��ꍇ�́A�U�ł��B
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
///@}
// ********************************
//	CDcdText
// ********************************
 public:
	// ********************************
	///	@name ����
	// ********************************
	///@{
	virtual tstring			getText(){	return m_strText ;	} ;
	virtual CDcdText& setText( const tstring& ev ){	
		m_strText = ev ;	return *this ; } ;
	virtual CdDrawTextProp	getCdDrawTextProp(){	return m_CdDrawTextProp ;};
	virtual CDcdText& setCdDrawTextProp( const CdDrawTextProp& ev ){
		m_CdDrawTextProp = ev ;	return *this ; } ;
	virtual tstring			getExtent(){	return m_strExtent ;	} ;
	virtual CDcdText& setExtent( const tstring& ev ){
		m_strExtent = ev ;	return *this ;	};
	virtual int				getLinesExtent(){	return m_iLinesExtent ;	} ;
	virtual CDcdText& setLinesExtent( int ev ){
		m_iLinesExtent = ev ;	return *this ; } ;
	///@}
};
#endif /*CDcdText_h*/
