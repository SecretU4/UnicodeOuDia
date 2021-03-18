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
//	CWjkState_Renzoku.h
//	$Id: CWjkState_Renzoku.h 368 2016-08-19 11:11:10Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWjkState_Renzoku_h
#define  CWjkState_Renzoku_h

#include <string>
#include "CWndJikokuhyou.h"
#include "CWjkState.h"
#include "OuDlg/CKeyinputSenderToModalDlg.h"
#include "DedRosenFileData\EditCmd\EditCmd.h"

namespace ViewJikokuhyou{ namespace WndJikokuhyou{
	using namespace DedRosenFileData::EditCmd;
// ****************************************************************
//	CWjkState_Renzoku
// ****************************************************************
/**
 * @brief
 *	�w�����\�x�O���b�h�E�C���h�E�́w��ԁx�̈�ł��B
 *	�w�A�����̓��[�h�x���������܂��B
 */
class CWjkState_Renzoku : 
	public CWjkState
{
 public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	typedef CWjkState	super ;

private:
	// ********************************
	///@name	���/�W��
	// ********************************
	///@{
	///@}

private:
	// --------------------------------
	///	@name �����f�[�^
	// --------------------------------
	///@{
	/**
		���ݘA�����͒��̃Z���́AX��ԍ��EY��ԍ��ł��B
	
		���[�h�J�n���iOnEnter�j�ƁA�V�����Z���ւ̘A�����͊J�n���ɁA
		�t�H�[�J�X�Z���̒l��ݒ肵�܂��B
	
		OnKeyDown() : 
		�Z���ɐ����Q���̓��͂����������Ƃ��ɂ́A
		���̕�������擾���A�w�������X�V���܂��B
		���̌�AstartEditCell() �ŁA�t�H�[�J�X�Z�����P���Ɉړ����܂��B
	
		OnSetFocusCell() : 
		�t�H�[�J�X�Z�������̒l�ƈقȂ�Z���Ɉړ������ꍇ�́A
		�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		�ɑJ�ڂ��܂��B
	*/
	int m_iXColumnNumberFocus ;

	/**
		���͒��̕��B
	*/
	std::string m_strMinutes ;
	///@}
 private:
	// --------------------------------
	///@name OnUpdate�����֐�
	// --------------------------------
	///@{
	/**
	OnUpdate() �̉����֐��ł��B
	�r���[�����S�ɍX�V���܂��B
	OnUpdate() �� pHint �� NULL �̏ꍇ�̏������s���܂��B

	���̂悤�ȍX�V�����������ꍇ�́A
	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
	�ɑJ�ڂ��܂��B
	OnUpdate() �́A�w��ԕҏW���[�h�x�ɈϏ����܂��B
	*/
	void OnUpdate_All() ;


	/**
	OnUpdate() �̉����֐��ł��B
	OnUpdate() �� pHint �� 
	CRfEditCmd_Ressya �I�u�W�F�N�g�̏ꍇ�̏������s���܂��B
 	*/
	void OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) ;
	
	
	///@}
 private:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
	�����̐��K�����s���܂��B

	- ��[�t�H�[�J�X�Z�����ҏW����Ԃ̒��������ł͂Ȃ�]Ressyahensyu�ɑJ��
	- ��[�t�H�[�J�X�ʒu�̉w����Ourder�ȑO�ɁA�w�����̓��͂��ꂽ�w������Ȃ�]Ressyahensyu�ɑJ��
	*/
	bool update_adjustProp() ;

	/**
		�����ɉ����āA��ʕ\�����X�V���܂��B

		- 1. �ҏW������A�w�����ōX�V
		- 2. �ҏW���̉w����Order�ɑ΂��āA�u���O�̉w�����̎�+�ҏW���̕��v��ݒ�

	@param bOnExit
		- false : onExit()�ȊO�̓�����s���܂��B
			�u2. �ҏW���̉w����Order�ɑ΂��āA�u���O�̉w�����̎�+�ҏW���̕��v��ݒ�v
			�̏������s���܂��B
		- true:   onExit() ���̓�����s���܂��B
			�u2. �ҏW���̉w����Order�ɑ΂��āA�u���O�̉w�����̎�+�ҏW���̕��v��ݒ�v
			�̏����͍s���܂���B
	*/
	bool update_updateScreen(bool bOnExit=false) ;

	/**
		�����̐��K���ƁA��ʕ\���X�V���s���܂��B
	*/
	bool update() ;

	/**
	�A�����̓��[�h�ɂ�����A�J�����g�Z���̎��̃Z�����v�Z���܂��B
	�Ώۂ́A�w�����̃Z���Ɍ��肳��܂��B
	@param pcellCurrent [in]
		�J�����g�Z�����w�肵�Ă��������B
	@param iSign [in]
		�ړ��������w�肵�Ă��������B
		-	+1 ;	//	�wOrder����������ق��Ɉړ����܂��B
		-	-1 ;	//	�wOrder����������ق��Ɉړ����܂��B
	@return
		���̃Z��������ł���΁A���̃Z���̃I�u�W�F�N�g��Ԃ��܂��B
		����ł��Ȃ��ꍇ�́ANULL��Ԃ��܂��B
	*/
	CDcdGridCell* calcCellToNext( CDcdGridCell* pcellCurrent , int iSign ) ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CWjkState_Renzoku( 
		CWndJikokuhyou*	pCWndDcdGrid );
	virtual ~CWjkState_Renzoku() ;

protected:
	// ********************************
	//	CWjkState
	// ********************************
	// ********************************
	///@name CWjkState-����
	// ********************************
	///@{
	/**
	 @return
		���̏�ԂɑJ�ډ\�ł���� 0 �ȏ�ł��B
		-	-1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ��B
		-	-2 ;	//	�Z���̈ʒu���O�ɁA�w�������ݒ肳��Ă��Ȃ�
	
	�y�I�[�o���C�h�z

	�ȉ��̏����̂P�ł��������Ă���ꍇ�́A��ԑI�����[�h��
	�J�n�ł��܂���B

	- �Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ��B
	- �Z���̈ʒu���O�ɁA�w�������ݒ肳��Ă��Ȃ�
	- �Z���̈ʒu���A�w�����̍ŉ��i�̃Z��
	
	*/
	virtual int canEnter() ;

	/**
		���̏�Ԃւ̓��ꓮ����s���܂��B
	
		CWndJikokuhyou �́A�w�J�����g��ԁx��this �ɐݒ肵��
		����ɁA���̊֐����Ăяo���܂��B
	
		�y�I�[�o���C�h�z
	
		m_iXColumnNumberFocus ���t�H�[�J�X�Z���ŕύX���܂��B

		m_strMinutes �͋󕶎���Ƃ��܂��B

		���̂����ŁA�\�����X�V���܂��B

		�ȉ��̏����̂P�ł��������Ă���ꍇ�́A��ԑI�����[�h��
		�J�n�ł��܂���B
	
		- �Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ��B
		- �Z���̈ʒu���O�ɁA�w�������ݒ肳��Ă��Ȃ�
		- �Z���̈ʒu���A�w�����̍ŉ��i�̃Z��
	
		���̏ꍇ�́A�����Ɂw��ԕҏW���[�h�x�ɑJ�ڂ��܂��B
	*/
	virtual void onEnter() ;
	/**
		���̏�Ԃ���̑ޏꓮ����s���܂��B
	
		CWndJikokuhyou �́A�w�J�����g��ԁx��this ���瑼�ɐݒ肷��
		���O�ɁA���̊֐����Ăяo���܂��B
	
		�y�I�[�o���C�h�z
	
		m_iXColumnNumberFocus �ɑΉ��������X�V���܂��B
	*/
	virtual void onExit() ;
	///@}
	// ********************************
	///@name CView ����̈Ϗ�
	// ********************************
	///@{
	/**
		pHint �� CHint_CentDedRessya �ŁA�Ȃ�����
		pCHint_CentDedRessya.m_eOperation == OperationUpdate �̏ꍇ�́A
		��̍Đݒ���s���܂��B
		���̌�A�t�H�[�J�X�Z���̈ʒu�ɁA
		���̏����ݒ���s���܂��B
	
		���̑��̏ꍇ�́A
		�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		�ɑJ�ڂ��܂��BOnUpdate() �͐V�������[�h�ɈϏ����܂��B
	*/
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	///@}
	// ********************************
	///@name ���b�Z�[�W�n���h���E�R�}���h�n���h��-CWnd
	// ********************************
	///@{

	/**
		"0"�`"9" ,BackSpace : ���ݓ��͒��̃Z���̕�������X�V���A
		��������Z���ɐݒ肵�܂��B
	
		���������S�����ɂȂ����i�������͂������j�ꍇ�́A���̕������擾���A
		�����ɕϊ����܂��B
		���̎������A���̗�Ԃ̒��O�̎��������������i�O�́j�ꍇ�́A
		�P���Ԃ����Z���܂��B
	
		���߂��������A�h�L�������g�ɔ��f���A
		UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B
		���̂Ƃ��� pHint �́A
		CHint_CentDedRessya �I�u�W�F�N�g
		( m_eOperation == OperationUpdate ) �Ƃ��܂��B
	
		startFocusCell() �ŁA�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
		���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
		���[�h��
		�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		�ɑJ�ڂ��܂��B
	
		"BS" :
	
		[����1�������͂��Ă���]
		���̂P�������폜���āA
		��������Z���ɐݒ肵�܂��B
		
		[�����O�������͂��Ă���]
		startFocusCell() �ŁA�t�H�[�J�X��O�̈ʒu�Ɉړ����܂��B
		���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
		���[�h��
		�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		�ɑJ�ڂ��܂��B
	
		"ESC" : 
		���[�h��
		�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		�ɑJ�ڂ��܂��B
	*/
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	/**
	*/
	virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	// --------------------------------

	/**[�w����]-[��������]
		�t�H�[�J�X�Z���̈ʒu�́w����Order�x�� �wNull�����x�ɕύX���܂��B
		�h�L�������g�ɔ��f���A
		UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B
		���̂Ƃ��� pHint �́A
		CHint_CentDedRessya �I�u�W�F�N�g
		( m_eOperation == OperationUpdate ) �Ƃ��܂��B
	
		calcCellToNext() �ŁA�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
		���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
		���[�h��
		�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		�ɑJ�ڂ��܂��B
	@return	
		-	-1 ;	//	�t�H�[�J�X�Z�����A��Ԃ̈ʒu�ł͂���܂���B
		-	-2 ;	//	�t�H�[�J�X�Z�����A�w�����̈ʒu�ł͂���܂���B
	*/
	virtual int OnJikokuhyouJikokuSakujo_Process( BOOL bQueryEnable );

	/** [�w����]-[�ʉ�] 
	�t�H�[�J�X�Z���̈ʒu�́w�w�����x���w�ʉ߁x�ɕύX���܂��B
	�w�����͒������E�������Ƃ�NULL�ɂ��܂��B

	�h�L�������g�ɔ��f���A
	UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B

	�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B

	���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
	���[�h��
	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
	�ɑJ�ڂ��܂��B
	*/
	virtual int OnJikokuhyouTsuuka_Process( BOOL bQueryEnable );

	/** [�w����]-[�ʉ�-���] 
	���̊֐��́AOn...() �R�}���h�n���h���EOnUpdate...() �R�}���h�n���h����
	���������s���܂��B

	�t�H�[�J�X�Z���̈ʒu�́w�w�����x���w��ԁx�w�^�s�Ȃ��x�w�o�R�Ȃ��x�Ȃ�A
	�w�ʉ߁x�ɕύX���܂��B�w�����͕ύX���܂���B

	�t�H�[�J�X�Z���̈ʒu���w�ʉ߁x�ŁA�w�����ɒ������E�������̂����ꂩ������Ȃ�A
	�w��ԁx�ɕύX���܂��B�w�����͕ύX���܂���B

	�h�L�������g�ɔ��f���A
	UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B

	�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B

	���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
	���[�h��
	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
	�ɑJ�ڂ��܂��B

	*/
	virtual int OnJikokuhyouTsuukateisya_Process( BOOL bQueryEnable );

	/** [�w����]-[�o�R�Ȃ�] 
	 �t�H�[�J�X�Z���̈ʒu�́w�w�����x���w�o�R�Ȃ��x�ɕύX���܂��B
	�h�L�������g�ɔ��f���A
	UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B
	���̂Ƃ��� pHint �́A
	CHint_CentDedRessya �I�u�W�F�N�g
	( m_eOperation == OperationUpdate ) �Ƃ��܂��B

	startFocusCell() �ŁA�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
	���̃t�H�[�J�X�ʒu���w�w�����x�łȂ��̂Ȃ�A
	���[�h��
	�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
	�ɑJ�ڂ��܂��B
	@return
		-	-1 ;	//	�t�H�[�J�X�Z�����A��Ԃ̈ʒu�ł͂���܂���B
		-	-2 ;	//	�t�H�[�J�X�Z�����A�w�����̈ʒu�ł͂���܂���B
	*/
	virtual int OnJikokuhyouKeiyunasi_Process( BOOL bQueryEnable );

	// --------------------------------
	/** [�w����]-[�A������] 
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͂��łɑI������Ă��܂�
		-	0 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͑I������Ă��܂���
		-	-1 ;	//	���݁A���̃R�}���h�͑I���ł��܂���
	*/
	virtual int OnJikokuhyouRenzoku_Process( BOOL bQueryEnable );
	///@}
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{
	/**
		�t�H�[�J�X�Z���̈ʒu���A�A�����͒��̃Z���ȊO�ɂȂ����ꍇ�́A
		�w�A�����̓��[�h�x->�w��ԕҏW���[�h�x
		�ɑJ�ڂ��܂��B
	*/
	virtual void OnSetFocusCell( CDcdGridCell* pCDcdGridCell ) ;

	/**
	  this �́AWndDcdGrid3::CSelectCell::m_bIsSelected ��
	  �ω������Ƃ��ɁA���̉��z�֐����Ăяo���܂��B
	  �N���X���[�U�[�́A���̉��z�֐����I�[�o���C�h���āA�K�v�ȏ�����
	�����ł��܂��B
	  
	  this �́A�N���X���[�U�[�� 
	CWndDcdGrid::CSelect::setColumnNumberSelect() ��
	�l��ݒ肵���Ƃ��̂ق��A
	�L�[�{�[�h�őI���Z����ύX�����Ƃ��ɂ�
	���̉��z�֐����Ăяo���܂��B
	
	[�I�[�o���C�h]
		�����͂���܂���
	
	@param iXColumnNumber [in]
		X��ԍ����w�肵�܂��B
	@param iYColumnNumber [in]
		X��ԍ����w�肵�܂��B
	@param bIsSelected [in]
		�V�����I����ԁB
	 */
	virtual void OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) ;
	///@}

};
} } // namespace WndJikokuhyou namespace ViewJikokuhyou

#endif /*CWjkState_Renzoku_h*/
