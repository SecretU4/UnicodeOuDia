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
//	CDcdFillrect.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdFillrect_h
#define  CDcdFillrect_h

#include "IfDcDraw.h"
#include "DcdCd\DcDrawProp\CdBrushProp.h"

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CDcdFillrect
// ****************************************************************
/**
 @brief
 �y�T�v�z
 	   DcDraw���f���I�u�W�F�N�g�ł��B�̈���̑S�ʂ�h��Ԃ��܂��B

	  ���̃I�u�W�F�N�g�ɑ΂��� DcDraw() ���Ăяo���ƁA���̗̈�S�̂�
	�����Ŏw�肳�ꂽ�F�i�n�b�`�p�^�[�����j�œh��܂��B

	ROP��K�p���邱�Ƃ͂ł��܂���B	
*/
class CDcdFillrect : public IfDcDraw
{
// ********************************
///	@name ����
// ********************************
///@{
 private:
	/**
		�h��Ԃ��Ɏg�p����u���V�̑�����ێ����܂��B
	*/
	CdBrushProp	m_CdBrushProp	;
///@}
	
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	@param aCdBrushProp [in]
		�h��Ԃ��Ɏg�p����u���V�̑������w�肵�Ă��������B
	*/
	CDcdFillrect( const CdBrushProp& aCdBrushProp ) ;
	CDcdFillrect() ;
	virtual ~CDcdFillrect() ;
	
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
	*	  �n���ꂽ�̈���A�u���V�œh��Ԃ��܂��B
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
	*	  ���̃N���X�ł́A�T�|�[�g���Ă��܂���B
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
	*	@n
	*	�y�I�[�o���C�h�z  �U��Ԃ��܂��B
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;

///@}
// ********************************
//	CDcdFillrect
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	virtual CdBrushProp	getCdBrushProp()const{	return m_CdBrushProp	;	} ;
	virtual CDcdFillrect& setCdBrushProp( const CdBrushProp& ev )
	{	m_CdBrushProp	= ev ;	return *this ; } ;
	///@}
};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*CDcdFillrect_h*/
