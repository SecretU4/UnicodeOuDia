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
//$Id: CSelectCell.h 212 2014-08-02 19:35:30Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdGrid_WndDcdGrid3_CSelectCell_h
#define  DcDraw_DcdGrid_WndDcdGrid3_CSelectCell_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DcDraw\IfDcdTarget.h"
#include <deque>

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

	using namespace DcDraw;

class CSelect ;

// ----------------------------------------------------------------
//	WndDcdGrid3::CSelectCell
// ----------------------------------------------------------------
/**
@brief
	CWndDcdGrid�̂�CellSelect(�Z���I��)�ɂ�����A
		�Z���P�̏�Ԃ������܂��B
*/
class CSelectCell
{ 
public:
	friend class CSelect ;
	typedef CSelect outer ;
	typedef	std::deque< CSelectCell* > CSelectYColumnCellCont ;
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		this ���܂���ACSelect �ւ̊֘A�B
		���̃I�u�W�F�N�g�́A�֘A���L���ȊԂ͐������Ȃ��Ă͂Ȃ�܂���B
	*/
	CSelect*	m_pOuter ;
	/**
		this ���W�񂵂Ă���R���e�i�ł��B
		���̃R���e�i�ɂ́A����Y��ɂ��� CSelectCell �I�u�W�F�N�g���i�[����Ă��܂��B

		���̊֘A�́ACSelect ���AgetColumnNumberOfCell() ���s�����ɎQ�Ƃ��܂��B
		�R���X�g���N�^�Ō��܂�܂��B
	*/
	CSelectYColumnCellCont*	m_pCont ;
	///@}
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�Z���̑I����ԁB
		�I������Ă����� true�B
		����l��false�B
	*/
	bool m_bIsSelected ;

	/**
		m_bIsSelected �̑O��l�B
		�ŋ߂� adjust_updateScreen() �̎��_�ɂ�����l��ێ����܂��B
	*/
	bool m_bIsSelected_Prev ;

	///@}
protected:
	// --------------------------------
	///@name CWndDcdGrid ����̈Ϗ�
	// --------------------------------
	///@{
	/**
	update() �̉����֐��ł��B
	�����̕␳���s���܂��B
	
	[�I�[�o���C�h]�@�����͂���܂���B
	
	 @return 
		���K���̌��ʁA���炩�̒l��ω��������ꍇ�͐^�ł��B
	 */
	bool update_adjustProp() ;

	/**
	update() �̉����֐��ł��B
	�����̕ω����A��ʏ�ɔ��f���܂��B
	
	[�I�[�o���C�h]�@
		�������ω�������A
		invalidateGrid() �ŁA�Z���̍ĕ`����s���܂��B
		�ΏۂƂȂ�̂́A�ȉ��̑����ł��B

		- m_bSelected	

	@param pIfDcdTarget [in]
		�`��Ώۂ��w�肵�Ă��������B
	@return 
		���炩�̒l�̕ω�����ʏ�ɔ��f�������ꍇ�͐^�ł��B
	 */
	bool update_updateScreen( IfDcdTarget* pIfDcdTarget ) ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CSelectCell(
		CSelect* pOuter , 
		CSelectYColumnCellCont* pCont ) ;
public:
	// ********************************
	///@name CSelectCell ����
	// ********************************
	///@{
	bool getIsSelected()const ;

	/**
	m_bIsSelected ��ύX���܂��B

	CSelect::m_bUpdateCWndDcdGrid �� true �ŁA
	�������ύX���ꂽ�ꍇ�́A
	CWndDcdGrid::update() ���Ăяo���āA
	�ύX�� CWndDcdGrid �ɏW�񂳂�Ă���
	�S�ẴI�u�W�F�N�g�ɔ��f���܂��B

	@attention
		CSelect::m_bUpdateCWndDcdGrid �� true �̏ꍇ�A
		���̊֐��́A�������Ԃ������Ȃ�܂��B
		(���R�FCWndDcdGrid::update() �͏������Ԃ������Ȃ邽�߂ł��B)@n
		������ CSelectCell �I�u�W�F�N�g�ɑ΂��ĘA������
		CSelectCell::setIsSelected() ���Ăяo���ꍇ�́A@n
		(1)CSelect::m_bUpdateCWndDcdGrid �� false�ɂ��Ă���@n 
		(2)CSelectCell::setIsSelected() ���A�Ώۂ̂��ׂẴZ���ɑ΂��Ď��s@n 
		(3)CSelect::m_bUpdateCWndDcdGrid �� true �ɂ��ǂ�@n 
		�Ƃ������@���Ƃ邱�Ƃɂ��A�������Ԃ̒Z�k�����҂ł��܂��B

	@param value [in]
		m_bIsSelected �ɐݒ肷��l���w�肵�Ă��������B
		
	*/
	void setIsSelected( bool value ) ;

	bool getIsSelected_Prev()const ;
	///@}
};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif //DcDraw_DcdGrid_WndDcdGrid3_CSelectCell_h
