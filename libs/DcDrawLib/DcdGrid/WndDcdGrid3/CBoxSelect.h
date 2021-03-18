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
//	CBoxSelect.h
//	$Id: CBoxSelect.h 212 2014-08-02 19:35:30Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdGrid_WndDcdGrid3_CBoxSelect_h
#define  DcDraw_DcdGrid_WndDcdGrid3_CBoxSelect_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>
#include "DcdGrid\WndDcdGrid3\CSelect.h"
#include "DcdGrid\WndDcdGrid3\CPropStack.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{
	
// ****************************************************************
//	WndDcdGrid3::CBoxSelect
// ****************************************************************
/**
@brief
 CWndDcdGrid ��ł́A���[�U�[��BoxSelect(���^�I�𑀍�)�ɂ��������āA
CSelect,CSelectCell �̑�����ύX���܂��B

���̃N���X�́A CWndDcdGrid  �������I�ɐ������邽�߂ɑ��݂��܂��B
����ȊO�̗��p���l�͂���܂���B

 �y�g�����z

(1) ���̃N���X�̃I�u�W�F�N�g�́A WndDcdGrid3::CWndDcdGrid �Ő�������܂��B
WndDcdGrid3::CWndDcdGrid::getCBoxSelect() �ŁA�I�u�W�F�N�g�ɃA�N�Z�X�ł��܂��B

(2) ���^�I�����g�p����Ƃ��́A�ŏ��Ɂ@WndDcdGrid3::CBoxSelect::setIsEnable ()
�ŁA���̋@�\��L���ɂ��Ă��������B

<H3>
BoxSelect(���^�I�𑀍�)	
</H3>
��Ctrl+Space�L�[@n
�@���������Ȃ�

��Ctrl+�O���b�h��ł̃}�E�X�N���b�N@n
�@���������Ȃ�

��Ctrl��Shift��������Ȃ���ԂŁA�O���b�h��ł̃}�E�X�N���b�N@n
  ���������Ȃ�

��Ctrl��Shift��������Ȃ���ԂŁA
 �h���b�O(MouseMove,�^�C�}�X�N���[��)�ȊO�ɂ��t�H�[�J�X�ړ�@n
  ���A���J�[�Z���͍X�V�BBoxSelect�̈��NULL�B
              ���ׂẴZ���̑I����Ԃ�����
              
��Ctrl��ON�AShift��OFF�ŁA�h���b�O�ȊO�ɂ��t�H�[�J�X�ړ�@n
  ���A���J�[�Z���͍X�V�BBoxSelect�̈�͂��̂܂܁B

��Shift�������ꂽ��ԂŁA�h���b�O�ȊO�ɂ��t�H�[�J�X�ړ�@n
  ���A���J�[�Z���͍X�V�����ɁA�A���J�[�Z���ƃt�H�[�J�X�Z���̊Ԃ�
    �I��̈�Ƃ���B

���h���b�O�ɂ��t�H�[�J�X�ړ�(MouseMove,�^�C�}�X�N���[��)@n
  ���A���J�[�Z���͍X�V�����ɁA�A���J�[�Z���ƃt�H�[�J�X�Z���̊Ԃ�
    �I��̈�Ƃ���B

 ���̃N���X�́A CWndDcdGrid  �������I�ɐ������邽�߂ɑ��݂��܂��B
	����ȊO�̗��p���l�͂���܂���B


*/
class CBoxSelect
{
	friend class CWndDcdGrid ;
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		�O���́A CWndDcdGrid �ւ̊֘A�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
		�R���X�g���N�^�Ō��܂�܂��B
	 */
	CWndDcdGrid*	m_pCWndDcdGrid ;

	///@}

private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		UI����ɂ�锠�^�I���̗L���E�������w�肵�܂��B
		����l�� true �ł��B
	*/
	bool m_bIsEnable ;

	/**
		�A���J�[�Z���B���^�I���̎n�_�ł��B

		���[�U�[��Shift�L�[��������Ă��Ȃ���ԂŃt�H�[�J�X�Z�����ړ������ꍇ�́A
		���̃N���X�̓A���J�[�Z�����t�H�[�J�X�Z���ōX�V���܂��B

		ColumnNumberPosXy_NULL() �Ȃ�A
		�A���J�[�Z�����s��ł��邱�Ƃ������܂��B
		update_adjustProp_updateColumnNumberSelect()�ōX�V����܂��B
		
		m_ColumnNumberAnchorCell �� m_ColumnNumberSelectLimit ��
		�O���ɂȂ����ꍇ�́A�����I��NULL�ƂȂ�܂��B
	*/
	CdDcdPosXy	m_ColumnNumberAnchorCell;

	/**
		���݂�BoxSelect(���^�I�𑀍�)�I��͈�

		�I��͈͂��Ȃ��ꍇ�A���̒l��
		ColumnNumberZoneXy_NULL()�Ɠ������Ȃ�܂��B
		
		update_adjustProp_updateColumnNumberSelect()��
		���o����܂��B
		�܂��A���\�b�h�Ŏw�肷�邱�Ƃ��ł��܂��B
	*/
	CdDcdZoneXy	m_ColumnNumberSelect ;

	///@}
 private:
	// ********************************
	///	@name �W��
	// ********************************
	///@{
	///@}
public:
	// ********************************
	///@name �萔
	// ********************************
	///@{
	/**
	@return
		�Z���̗�ԍ���NULL�l�B

		�Z���̗�ԍ��́A
		x,y������INT_MIN�Ȃ�ANULL�ł��邱�Ƃ������܂��B
	*/
	static CdDcdPosXy	ColumnNumberPosXy_NULL()
	{	return CdDcdPosXy( INT_MIN , INT_MIN ) ;};

	/**
	@return
		�I��͈͂�NULL�l�B

		m_ColumnNumberSelect �����̒l�ɓ������ꍇ��
		�I��͈͂��Ȃ����Ƃ������܂��B
	*/
	static CdDcdZoneXy	ColumnNumberZoneXy_NULL()
	{	return CdDcdZoneXy( CdDcdZone( 0 , 0 ) , CdDcdZone( 0 , 0 ) );};
	///@}

private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
		�t�H�[�J�X�Z���̑O��l�B
		�����l��NULL�������l�ł��B
		update_adjustProp() �ŁA�J�����g�̃t�H�[�J�X�Z���̒l���R�s�[����܂��B
	*/
	CdDcdPosXy	m_ColumnNumberFocus_Old ;


	/**
		BoxSelect(���^�I�𑀍�)�I��͈͂̑O��l�B
		�����l��NULL�������l�ł��B
		
		update_updateScreen()�ŉ�ʂ��X�V�����Ƃ��ɁA
		m_ColumnNumberSelect �̒l���R�s�[����܂��B
	*/
	CdDcdZoneXy	m_ColumnNumberSelect_Old ;



private:
	// --------------------------------
	///@name update_adjustProp �����֐�
	// --------------------------------
	///@{
	/**
		update_adjustProp()�̉����֐��ł��B

	�y1.�����̕␳�z


		�ΏۂƂȂ�̂́A�ȉ��̑����ł��B
		
		- m_ColumnNumberSelect , m_ColumnNumberAnchorCell
	
	(1)	�t�H�[�J�X�Z���̈ړ��ɏ]���āA
		m_ColumnNumberAnchorCell , m_ColumnNumberSelect ���X�V���܂��B
		
	(2)	m_ColumnNumberAnchorCell�Em_ColumnNumberSelect �𐳋K�����܂��B

	*/
	bool update_adjustProp_updateColumnNumberSelect() ;
	
	/**
		update_adjustProp()�̉����֐��ł��B

	�y2.�����̕ω���CWndDcdGrid�ɒʒm�z

	(3)	�I���Z���̏�Ԃ��ACSelectCell �ɔ��f���܂��B

	@note
		�I���Z�� CSelectCell �ւ� 
		update_adjustProp() �̈Ϗ��͍s���܂���B@n
		���R�FCSelectCell�ւ� update_adjustProp() ��
		�Ϗ��́A CSelect �̐Ӗ��ł��B
	*/
	bool update_adjustProp_updateCSelectCell() ;

	/**
	�Z���I��ύX���́ACPropStack �C���X�^���X�𐶐����܂��B
	���̃I�u�W�F�N�g�́A�������Ԓ��͈ȉ��̑�����ݒ肵�܂��B

	- CSelect::m_bUpdateCWndDcdGrid = false

	 ����ɂ���āA�Z���I��ύX���̕`����œK�����܂��B
	 (�����̃Z���̑I����ύX����ꍇ�́A���̑�����false�ɂ�����Ԃ�
	 �Z���̑I����Ԃ�ύX���Ă���A���̑�����true�ɂ���
	 ��ʂ��ĕ`�悷��ق����A�������悭�Ȃ�܂��B) 
	*/
	Ou<CPropStack> createPropStackForSelectChange() ;

	///@}


protected:
	// --------------------------------
	///@name CWndDcdGrid ����̈Ϗ�
	// --------------------------------
	///@{
	/**
		update() �̉����֐��ł��B
	
		- �����̕␳
		- �����̕ω���CWndDcdGrid�ɒʒm

		���s���܂��B

	�y1.�����̕␳�z

		�ΏۂƂȂ�̂́A�ȉ��̑����ł��B
		
		- m_ColumnNumberSelect , m_ColumnNumberAnchorCell
	
	(1)	�t�H�[�J�X�Z���̈ړ��ɏ]���āA
		m_ColumnNumberAnchorCell , m_ColumnNumberSelect ���X�V���܂��B
		
	(2)	m_ColumnNumberAnchorCell�Em_ColumnNumberSelect �𐳋K�����܂��B

	�y2.�����̕ω���CWndDcdGrid�ɒʒm�z

	(3)	�I���Z���̏�Ԃ��ACSelectCell �ɔ��f���܂��B

	 @return 
		���炩�̒l��ω��������ꍇ�͐^�ł��B
	 */
	bool update_adjustProp() ;

	/**
		update() �̉����֐��ł��B

	  	�����̕ω����A��ʏ�ɔ��f���܂��B
		�ΏۂƂȂ�̂́A�ȉ��̑����ł��B
		
	 @return 
		���炩�̒l�̕ω�����ʏ�ɔ��f�������ꍇ�͐^�ł��B

		���̃N���X�ł͏����͂���܂���(�ĕ`��́ACSelect �ɂčs���܂�)
	 */
	bool update_updateScreen() ;


	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

	 	�`���v�����܂��B
	 	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B

	 @param pIfDcdTarget  [in]
	 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 	CWndDcdGrid�̃N���C�A���g�̈�� IfDcdTarget ���w�肵�Ă��������B
	 @return
	 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B

		���̃N���X�ł͏����͂���܂���(�ĕ`��́ACSelect �ɂčs���܂�)
	*/
	virtual bool OnPaint( IfDcdTarget* pIfDcdTarget ) ;


	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		�I���Z���𐳋K���E�Đݒ肵�܂��B

		���̃N���X�ł͏����͂���܂���
	*/
	void OnSize(UINT nType, int cx, int cy);

	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		���̃N���X�ł́A�����͂���܂���B
	*/
	void OnSetFocus(CWnd* pOldWnd);
	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		���̃N���X�ł́A�����͂���܂���B
	*/
	void OnKillFocus(CWnd* pNewWnd);

	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		�E�C���h�E�S��𖳌������A
		�ĕ`���v�����܂��B
		���̂Ƃ��A�I���Z���̑����̍Đݒ�E���K�����s���܂��B
	
		���̃N���X�ł͏����͂���܂���(�ĕ`��́ACSelect �ɂčs���܂�)
	 */
	virtual void InvalidateGrid( ) ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	@param pCWndDcdGrid [in]
		�O���́A CWndDcdGrid �ւ̊֘A�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	 */
	CBoxSelect( CWndDcdGrid* pCWndDcdGrid ) ;
	virtual ~CBoxSelect() ;
public:
	// ********************************
	///@name CSelect �֘A
	// ********************************
	///@{
	CWndDcdGrid*	getCWndDcdGrid() ;
	///@}


	// ********************************
	///@name CSelect ����
	// ********************************
	///@{
	bool getIsEnable() ;
	void setIsEnable( bool value ) ;
	CdDcdPosXy	getColumnNumberAnchorCell();
	CdDcdZoneXy	getColumnNumberSelect()const ;
	void setColumnNumberSelect( const CdDcdZoneXy& value ) ;
	///@}
	// ********************************
	///@name CSelect �W��
	// ********************************
	///@{
	///@}
	// ********************************
	///@name CSelect ����
	// ********************************
	///@{
	/**
		���^�I�����������܂��B
	*/
	void clearSelect() ;
	///@}


};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif //DcDraw_DcdGrid_WndDcdGrid3_CSelect_h
