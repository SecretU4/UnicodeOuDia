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
//	CFocus.h
//$Id: CFocus.h 296 2016-06-11 05:40:21Z okm $
// ****************************************************************
*/
/** @file 

*/
#if !defined(DcDraw_DcdGrid_WndDcdGrid3_CFocus_h)
#define DcDraw_DcdGrid_WndDcdGrid3_CFocus_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/**
@file
���̃w�b�_�t�@�C����P�̂ŃC���N���[�h���邱�Ƃ͂ł��܂���B
����ɁA CWndDcdGrid.h ���C���N���[�h���Ă��������B

���̃w�b�_�t�@�C���́ACWndDcdGrid.h �̖����ŃC���N���[�h���Ă��܂��B
���̂��߁A���̃N���X���� CWndDcdGrid.h ���C���N���[�h���邱�Ƃ͂ł��܂���B
*/

#include <afxwin.h>
#include "NsOu\Ou.h"
#include "DcDraw\IfDcDraw.h"
#include "DcdGrid\CDcdGridCell.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

// ----------------------------------------------------------------
//	WndDcdGrid3::CFocus
// ----------------------------------------------------------------
/**
 @brief
	CWndDcdGrid �̃t�H�[�J�X�E�X�N���[���̐�����N���X���������̂ł��B
	
	���̃N���X�́A CWndDcdGrid  �������I�ɐ������邽�߂ɑ��݂��܂��B
	����ȊO�̗��p���l�͂���܂���B
 */
class CFocus
{
	friend class CWndDcdGrid ;
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
	/**
		�t�H�[�J�X�Z���ɑ΂��āA�t�H�[�J�X�}�[�N��`�悷��
		DcDraw �I�u�W�F�N�g�ł��B
	
		�ʏ�́Athis �� CreateDcDrawFocusCell() ���z�֐����A
		CDcdRectangle �I�u�W�F�N�g�𐶐��E�o�^���܂��B
		�܂��A DeleteDcDrawFocusCell() ���z�֐����A
		���̃I�u�W�F�N�g��o�^�����E�j�����܂��B
		
	 */
	Ou<IfDcDraw>	m_pIfDcDrawFocusCell ;
	///@}
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		FocusCell �� XColumnNumber
		
		 CDcdGridWnd �E�C���h�E�́A�O���b�h�E�C���h�E�̂��ׂĂ�Cell��
		�����̂ЂƂ� FocusCell �Ƃ��Ďw�肵�܂��BFocusCell�͓_����
		�g���Ŏ�����܂��B
		(Cell���ЂƂ��Ȃ��ꍇ�́A�l�͂O�Ƃ��܂����A
		���̒l�͈Ӗ��������܂���)
	
		  FocusCell��ColumnNumber �́A�K���E�C���h�E��
		�iIfDcdTarget �I�u�W�F�N�g�̗̈���j�ɑ��݂��܂��B
		Scrollout����Ă���Z���E�E�C���h�E�̊O���ɂ���Z����
		FocusCell�ɂȂ邱�Ƃ͂���܂���B
		  �܂��AAttachedCell�i�팋���Z���j��FocusCell�ɂȂ邱�Ƃ͂���܂���B
		
		  ���̏����𖞂������߁AFocusCell �ƁACDcdGrid��
		 FixafterColumnNumber �́A��ɐ��K������܂��B
		(���̐��K���́A adjustProp() �ōs���܂�)�B
	 */
	int	m_iFocusCellXColumnNumber ;

	/**
		FocusCell �� YColumnNumber
		
		 CDcdGridWnd �E�C���h�E�́A�O���b�h�E�C���h�E�̂��ׂĂ�Cell��
		�����̂ЂƂ� FocusCell �Ƃ��Ďw�肵�܂��BFocusCell�͓_����
		�g���Ŏ�����܂��B
		(Cell���ЂƂ��Ȃ��ꍇ�́A�l�͂O�Ƃ��܂����A
		���̒l�͈Ӗ��������܂���)
	
		  FocusCell��ColumnNumber �́A�K���E�C���h�E��
		�iIfDcdTarget �I�u�W�F�N�g�̗̈���j�ɑ��݂��܂��B
		Scrollout����Ă���Z���E�E�C���h�E�̊O���ɂ���Z����
		FocusCell�ɂȂ邱�Ƃ͂���܂���B
		  �܂��AAttachedCell�i�팋���Z���j��FocusCell�ɂȂ邱�Ƃ͂���܂���B
		
		  ���̏����𖞂������߁AFocusCell �ƁACDcdGrid��
		 FixafterColumnNumber �́A��ɐ��K������܂��B
		(���̐��K���́A adjustProp() �ōs���܂�)�B
	 */
	int	m_iFocusCellYColumnNumber ; 


	/**
	  �t�H�[�J�X�Z�����E�C���h�E�O�ɂȂ�ꍇ�́A
	  �t�H�[�J�X�Z���ƃX�N���[���ʒu�̒�����@���w�肵�܂��B

		- false; �t�H�[�J�X�Z�����E�C���h�E���Ɉړ�������B
		- true; (�f�t�H���g)�t�H�[�J�X�Z�����E�C���h�E���ɂȂ�悤��@n
		�X�N���[���ʒu��ύX����B
	*/
	bool m_bFixafterColumnNumberChange ;

	/**
		- false: (�f�t�H���g)�E�C���h�E�Ƀt�H�[�J�X���Ȃ��Ƃ��́A@n
			�t�H�[�J�X�}�[�N���������܂��B
		- true: �E�C���h�E�Ƀt�H�[�J�X���Ȃ��Ƃ��ɂ��A@n
			�t�H�[�J�X�}�[�N���������܂���B
	 */
	bool	m_bIsFocusmarkShowEvery ;
	///@}
private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/** 
		�����l��ۑ����܂��B
	
		�����l�� -1 �i�����l�j�ł��B
	
		���̒l�́A update_updateDisplay() ���ɁA�O��l��r���s���̂Ɏg���܂��B
		�O��l��r���s������́A�l���X�V���܂��B
	
		�܂��AOnPaint() �ł��A�l���X�V���܂��B
	 */
	int	m_iFocusCellXColumnNumber_Sid ;
	/** 
		�����l��ۑ����܂��B
	
		�����l�� -1 �i�����l�j�ł��B
	
		���̒l�́A update_updateDisplay() ���ɁA�O��l��r���s���̂Ɏg���܂��B
		�O��l��r���s������́A�l���X�V���܂��B
	
		�܂��AOnPaint() �ł��A�l���X�V���܂��B
	 */
	int m_iFocusCellYColumnNumber_Sid ;
	///@}

protected:
	// --------------------------------
	///@name	WndDcdGrid3-�t�H�[�J�X-�����֐�
	// --------------------------------
	///@{
	/**
		this �́AOnCreate() ���炱�̊֐����Ăяo���܂��B
	
		m_pIfDcDrawFocusCell �̐����E�o�^���s���܂��B
	 */
	virtual void CreateDcDrawFocusCell() ;
	/**
		this �́AOnDestroy() ���炱�̊֐����Ăяo���܂��B
	
		CWndDcdGrid �ɑ΂��āA m_pIfDcDrawFocusCell 
		�̓o�^�����E�j�����s���܂��B
	 */	
	virtual void DeleteDcDrawFocusCell() ;
	///@}
protected:
	// --------------------------------
	///@name CWndDcdGrid ����̈Ϗ�
	// --------------------------------
	///@{
	/**
	- �����̕␳
	- �����̕ω���CWndDcdGrid�ɒʒm

	���s���܂��B

	�y1.�����̕␳�z

	  �ΏۂƂȂ�̂́A�ȉ��̑����ł��B
		
	- m_iFocusCellXColumnNumber 
	- m_iFocusCellYColumnNumber 
	- m_pCDcdGrid->m_iXFixafterColumnNumber
	- m_pCDcdGrid->m_iYFixafterColumnNumber

	  ���K���ɍۂ��āAm_iFocurCellXColumnNumber �� m_pCDcdGrid->m_iXFixafterColumnNumber 
	�̒l�����������ꍇ�A�ǂ����ύX���邩���A�t���O�őI���ł��܂��B

	- [FocurCellColumnNumber �ύX]  �t�H�[�J�X�Z�����A�E�C���h�E����
	�ړ����܂��B
	�X�N���[���ʒu��ύX�����Ƃ��́A��������g�p���܂��B
	- [FixafterColumnNumber �ύX]  �t�H�[�J�X�Z����
	�E�C���h�E���
	�\�������悤�ɁA FixafterColumnNumber ��ύX���܂��B
	�t�H�[�J�X�ʒu��ύX�����Ƃ��́A��������g�p���܂��B
		

	�P�DFocusCell ���팋���Z���ɂȂ����ꍇ�E�E�EFocusCell��	�����Z���Ɉړ����܂��B

	�Q�DFocusCellColumnNumber �� �E�C���h�E�͈̔�
		�iIfDcdTarget::getZone()�̗̈�)�Ɏ��܂��Ă��Ȃ��ꍇ�E�E�E

	- [FixafterColumnNumber �ύX]
	FocusCellColumnNumber ���A��ʏ�̈�ԉE���� ColumnNumber �ɂ��܂��B
	- [FocurCellColumnNumber �ύX]
	FocusCellColumnNumber ���E�C���h�E�͈̔͂Ɏ��܂�܂ŁA
	FixafterColumnNumber�����Z���܂��B
	���̌��ʂƂȂ� FixafterColumnNumber ���A
	 FixafterColumnNumberMaxForColumn �ƌĂт܂��B
		
	�R�D FocusCellColumnNumber �� ColumnScrollout �ɂȂ����ꍇ�E�E�E
		- [FixafterColumnNumber �ύX]
		FocusCellColumnNumber �� FixafterColumnNumber �Ɠ����ɂ��܂��B
		- [FocurCellColumnNumber �ύX]
		�X�N���[���ʒu�𐳋K�����āA�t�H�[�J�X�Z�����\�������悤�ɂ��܂��B
		FixafterColumnNumber���AFocusCell��ColumnNumber�Ɠ����ɂ��܂��B

	�S�DFocusCell ��0�ȏ� ColumnCount�����łȂ��ꍇ�E�E�EFocusCell��
		�����̒l�ɂ��܂��B
		
	�T�DFocusCell ���팋���Z���ɂȂ����ꍇ�E�E�EFocusCell��
		�����Z���Ɉړ����܂��B

	�y2.�����̕ω���CWndDcdGrid�ɒʒm�z

	  �������ω������ꍇ�́ACWndDcdGrid �ɑ΂��āA�ȉ��̃��\�b�h��
	�Ăяo���܂��B�A

	- CWndDcdGrid::OnSetFocusCell()
	- CWndDcdGrid::OnSetXFixafterColumnNumber()
	- CWndDcdGrid::OnSetYFixafterColumnNumber()

	 @return 
		���K���̌��ʁA���炩�̒l��ω��������ꍇ�͐^�ł��B
	 */
	bool update_adjustProp() ;

	/**
	  update() �̉����֐��ł��B

	  �����̕ω����A��ʏ�ɔ��f���܂��B
	  �ΏۂƂȂ�̂́A�ȉ��̑����ł��B

	- m_iFocusCellXColumnNumber 
	- m_iFocusCellYColumnNumber 
	- m_pCDcdGrid->m_iXFixafterColumnNumber
	- m_pCDcdGrid->m_iYFixafterColumnNumber

	  ���̕ω����@�m���邽�߂ɁAthis �͈ȉ��̑����ɑO��l��ێ����Ă��܂��B

	- m_iFocusCellXColumnNumber_Sid
	- m_iFocusCellYColumnNumber_Sid
	- m_CdScrollbarPropX_Sid
	- m_CdScrollbarPropY_Sid

	m_iFocusCellColumnNumber�E�E�E�ύX�O�ƕύX��̃Z���𖳌������A
	�ĕ`����s�킹�܂��B

	FixafterColumnNumber�E�E�E�E�C���h�E���Grid���X�N���[�����܂��B
	�܂��A�X�N���[���o�[������ύX���܂��B


	@return 
		���炩�̒l�̕ω�����ʏ�ɔ��f�������ꍇ�͐^�ł��B
	 */
	bool update_updateScreen() ;
	/**
	  CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B
  	  pIfDcdTarget �ɁA�`����s���܂��B

	�y�I�[�o���C�h�z
	  m_pIfDcDrawFocusCell �ŁA�t�H�[�J�X�}�[�N��`�悵�܂��B

	@param pIfDcdTarget  [in]
	 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 	CWndDcdGrid�̃N���C�A���g�̈�� IfDcdTarget ���w�肵�Ă��������B
	@return
	 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	*/
	virtual bool OnPaint( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		�X�N���[���E�t�H�[�J�X�𐳋K���E�Đݒ肵�܂��B
	*/
	void OnSize(UINT nType, int cx, int cy);

	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		�t�H�[�J�X�Z���̈ʒu���X�V���܂��B
	*/
	void OnSetFocus(CWnd* pOldWnd);
	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		�t�H�[�J�X�Z���̈ʒu���X�V���܂��B
	*/
	void OnKillFocus(CWnd* pNewWnd);

	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		�E�C���h�E�S��𖳌������A
		�ĕ`���v�����܂��B
		���̂Ƃ��A�X�N���[���o�[�̑����̍Đݒ�E
		�t�H�[�J�X�Z���̐��K�����s���܂��B
	 */
	virtual void InvalidateGrid() ;
	///@}


public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CFocus( CWndDcdGrid* pCWndDcdGrid ) ;
	virtual ~CFocus() ;
public:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	virtual Ou<IfDcDraw>	getIfDcDrawFocusCell() ;
	virtual void setIfDcDrawFocusCell( Ou<IfDcDraw> value ) ;
	///@}
public:
	// ********************************
	///@name CWndDcdGrid::CFocus ����
	// ********************************
	///@{
	/**
	@return
		�t�H�[�J�X�Z���̗�ԍ���Ԃ��܂��B
		�t�H�[�J�X�Z���ʒu���s��̏ꍇ�́A
		ColumnNumberPosXy_NULL() ��Ԃ��܂��B
	*/
	CdDcdPosXy	getFocusCellColumnNumber() ;

	/**
	@return
		�t�H�[�J�X�Z���̗�ԍ����w�肵�܂��B
	*/
	void setFocusCellColumnNumber( const CdDcdPosXy& value ) ;

	/**
	 @return
		�t�H�[�J�X�Z���̈ʒu��Ԃ��܂��B
	 */
	CDcdGridCell*	getFocusCell() ;

	/**
	 @param value [in]
		�t�H�[�J�X�Z�����w�肵�܂��B
	 */
	void setFocusCell( 
		CDcdGridCell* value ) ;


	bool	getFixafterColumnNumberChange()  ;
	void setFixafterColumnNumberChange( bool value ) ;

	bool	getIsFocusmarkShowEvery()  ;
	void setIsFocusmarkShowEvery( bool value ) ;

	///@}
};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif // !defined(DcDraw_DcdGrid_WndDcdGrid3_CFocus_h)

