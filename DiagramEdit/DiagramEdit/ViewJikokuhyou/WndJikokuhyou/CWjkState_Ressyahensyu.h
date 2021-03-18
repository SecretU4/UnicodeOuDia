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
//	CWjkState_Ressyahensyu.h
// $Id: CWjkState_Ressyahensyu.h 241 2016-01-05 06:14:33Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWjkState_Ressyahensyu_h
#define  CWjkState_Ressyahensyu_h

#include "CWjkState.h"
#include "OuDlg/CKeyinputSenderToModalDlg.h"
#include "DedRosenFileData\EditCmd\EditCmd.h"

namespace ViewJikokuhyou{ namespace WndJikokuhyou{
	using namespace OuMfc::OuDlg;
	using namespace DedRosenFileData::EditCmd;
// ****************************************************************
//	CWjkState_Ressyahensyu
// ****************************************************************
/**
  @brief
 	�w�����\�x�O���b�h�E�C���h�E�́w��ԁx�̈�ł��B
 	�w��ԕҏW���[�h�x���������܂��B
*/
class CWjkState_Ressyahensyu : 
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
	/**
	   �e�E�C���h�E�ւ̃L�[���͂��_�@�� ModalDialog ���J���ꍇ�A
	  ���[�_���_�C�A���O�̓���̃G�f�B�b�g�R���g���[���ɁA
	  �L�[���̓��b�Z�[�W�i WM_KEYDOWN , WM_KEYUP �j��]�����܂��B
	 */
	CKeyinputSenderToModalDlg	m_CKeyinputSenderToModalDlg ;
	///@}

private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
	 	- false ;	//	[�t�H�[�J�X�Z�����ړ�]
	 	- true ;	//	[�t�H�[�J�X�Z���E�ړ�]
	 	
	 �����l�� false �ł����A���[�U�[�̃��j���[����ŕς��܂��B
	 */
	bool m_bJikokuhyouFocusMoveRight ;
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
	 */
	void OnUpdate_All() ;


	/**
	OnUpdate() �̉����֐��ł��B
	OnUpdate() �� pHint �� 
	CRfEditCmd_Ressya �I�u�W�F�N�g�̏ꍇ�̏������s���܂��B

	CRfEditCmd_Ressya �����ƂɁA
	�r���[�𕔕��I�ɍX�V���܂��B
	 */
	void OnUpdate_CentDedRessya( 
		Ou<CRfEditCmd_Ressya> pCommand ) ;
	///@}

protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
	 	���݃t�H�[�J�X�̂���Z���ɑΉ����āA
	 	�w��ԁx�E�w�w�����x�����ꂩ��
	 	�v���p�e�B�_�C�A���O���J���A
	 	�v���p�e�B�̕ҏW���s���܂��B
	 
	 	execCDlgRessyaProp() �E
	 	execCDlgEkijikokuProp() �̂����ꂩ�ɈϏ����܂��B
	 
	  @param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	 @return
	  @param bInsert [in]
	 	- true ;	�t�H�[�J�X�̂���Z���̈ʒu�ɁA
	 	�V������Ԃ�}�����܂��B 
	 	- false ;	�t�H�[�J�X�̂���Z���̈ʒu�́A
	 	��Ԃ̃v���p�e�B���X�V���܂��B
	 	(�t�H�[�J�X�Z�����A��ԉE�̋󔒂̗�ɂ���ꍇ�́A
	 	�����ւ̑}���Ƃ��ē��삵�܂�)
	 @return
	 	-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
	 	-	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A
	 			//	�ύX�͔������܂���ł����B
	 	-	-1 ;	//	X��ԍ����s���ł��B
	 	-	-2 ;	//	Y��ԍ����s���ł��B

	 */
	int execJikokuhyouPropDlg( bool bInsert , BOOL bQueryEnable  ) ;
	
	/**
	 	���݃t�H�[�J�X�̂���Z����X��ԍ��ɑΉ�����
	 	�w��ԁx�v���p�e�B�_�C�A���O���J���A
	 	�v���p�e�B�̕ҏW���s���܂��B
	 @param bInsert [in]
	 	- true ;	�t�H�[�J�X�̂���Z���̈ʒu�ɁA
	 	�V������Ԃ�}�����܂��B 
	 	- false ;	�t�H�[�J�X�̂���Z���̈ʒu�́A
	 	��Ԃ̃v���p�e�B���X�V���܂��B
	 	(�t�H�[�J�X�Z�����A��ԉE�̋󔒂̗�ɂ���ꍇ�́A
	 	�����ւ̑}���Ƃ��ē��삵�܂�)
	 @param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	 @return
	 @return
	 	-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
	 	-	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A@n
	 				�ύX�͔������܂���ł����B
	 	-	-1 ;	//	X��ԍ����s���ł��B
	*/
	int execCDlgRessyaProp( bool bInsert , BOOL bQueryEnable ) ;
	
	/**
	 	���݃t�H�[�J�X�̂���Z����X��EY��ԍ��ɑΉ�����
	 	�w�w�x�v���p�e�B�_�C�A���O���J���A
	 	�v���p�e�B�̕ҏW���s���܂��B
	  @param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	 @return
	  @return
	*/
	int execCDlgEkiProp( BOOL bQueryEnable ) ;

	/**
	 	���݃t�H�[�J�X�̂���Z����X��EY��ԍ��ɑΉ�����
	 	�w�w�����x�v���p�e�B�_�C�A���O���J���A
	 	�v���p�e�B�̕ҏW���s���܂��B
	@param bInsert [in]
	 	- true ;	�t�H�[�J�X�̂���Z���̈ʒu�ɁA
	 	�V������Ԃ�}�����܂��B 
	 	- false ;	�t�H�[�J�X�̂���Z���̈ʒu�́A
	 	��Ԃ̃v���p�e�B���X�V���܂��B
	 	(�t�H�[�J�X�Z�����A��ԉE�̋󔒂̗�ɂ���ꍇ�́A
	 	�����ւ̑}���Ƃ��ē��삵�܂�)
	  @param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	 @return
	  @return
	 	-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
	 	-	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A@n
	 				�ύX�͔������܂���ł����B
	 	-	-1 ;	//	X��ԍ����s���ł��B
	 	-	-2 ;	//	Y��ԍ����s���ł��B
	 */
	int execCDlgEkijikokuProp( bool bInsert , BOOL bQueryEnable ) ;


	/**
	�t�H�[�J�X�Z���ړ����[�h m_bJikokuhyouFocusMoveRight �ɏ]���A
	�t�H�[�J�X�Z�����A���̈ʒu�Ɉړ����܂��B

	@param bNextEkiOrder [in]
	 	m_bJikokuhyouFocusMoveRight ���U�ŁA���݂̃t�H�[�J�X�Z�����A
	 	�����\���̉w�����̒������ɂ���ꍇ�́A�t�H�[�J�X�̈ړ����
	 	�w�肵�܂��B
	 	- true ;	//	�t�H�[�J�X�Z�������̉wOrder�Ɉړ����܂��B
	 	- false ;	//	�t�H�[�J�X�Z���𓯂��w�̔������Ɉړ����܂��B
	@return 
	 	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	virtual int moveFocusCellToNext( bool bNextEkiOrder ) ;
	
	/**
	�t�H�[�J�X�Z���ړ����[�h m_bJikokuhyouFocusMoveRight �ɏ]���A
	�t�H�[�J�X�Z�����A�O�̈ʒu�Ɉړ����܂��B

	@param bNextEkiOrder [in]
	 	m_bJikokuhyouFocusMoveRight ���U�ŁA���݂̃t�H�[�J�X�Z�����A
	 	�����\���̉w�����̔������ɂ���ꍇ�́A�t�H�[�J�X�̈ړ����
	 	�w�肵�܂��B
	 	- true ;	//	�t�H�[�J�X�Z����O�̉wOrder�Ɉړ����܂��B
	 	- false ;	//	�t�H�[�J�X�Z���𓯂��w�̒������Ɉړ����܂��B
	@return 
	 	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 */
	virtual int moveFocusCellToPrev( bool bNextEkiOrder ) ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CWjkState_Ressyahensyu( 
		CWndJikokuhyou*	pCWndDcdGrid );
	virtual ~CWjkState_Ressyahensyu() ;

protected:
	// ********************************
	//	CWjkState
	// ********************************
	// ********************************
	///@name CWjkState-����
	// ********************************
	///@{
	/**
	 *	���̏�Ԃւ̓��ꓮ����s���܂��B
	 *
	 *	CWndJikokuhyou �́A�w�J�����g��ԁx��this �ɐݒ肵��
	 *	����ɁA���̊֐����Ăяo���܂��B
	 *
	 *	�y�I�[�o���C�h�z
	 *	���ꓮ����������Ă��������B
	 */
	virtual void onEnter() ;
	/**
	 *	���̏�Ԃ���̑ޏꓮ����s���܂��B
	 *
	 *	CWndJikokuhyou �́A�w�J�����g��ԁx��this ���瑼�ɐݒ肷��
	 *	���O�ɁA���̊֐����Ăяo���܂��B
	 *
	 *	�y�I�[�o���C�h�z
	 *	�ޏꓮ����������Ă��������B
	 */
	virtual void onExit() ;
	///@}
	// ********************************
	///@name CView ����̈Ϗ�
	// ********************************
	///@{
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	///@}
	// ********************************
	///@name ���b�Z�[�W�n���h���E�R�}���h�n���h��-CWnd
	// ********************************
	///@{
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	virtual void OnWM_IME_STARTCOMPOSITION() ;

	// --------------------------------

	/**	
		[�ҏW]-[�؂���]
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	���݂̃t�H�[�J�X�Z���ł́A���s�ł��܂���
	*/
	virtual int OnEditCut_Process( BOOL bQueryEnable );

	/**	[�ҏW]-[�R�s�[]	
	@return
		iRv = -1 ;	//	���݂̃t�H�[�J�X�Z���ł́A���s�ł��܂���
	*/
	virtual int OnEditCopy_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[�\��t��]	
	@return
		-	-1 ;	//	���݂̃t�H�[�J�X�Z���ł́A���s�ł��܂���
		-	-2 ;	//	�N���b�v�{�[�h�Ƀf�[�^������܂���B
	*/
	virtual int OnEditPaste_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[����]
	@return
		-	-1 ;	//	���݂̃t�H�[�J�X�Z���ł́A���s�ł��܂���
	*/
	virtual int OnEditClear_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[�����̂ݓ\��t��]
	@return
		-	-1 ;	//	���݂̃t�H�[�J�X�Z���ł́A���s�ł��܂���
		-	-2 ;	//	�N���b�v�{�[�h�Ƀf�[�^������܂���B
	*/
	virtual int OnEditPasteEkiJikoku_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[���ׂđI��]	
		��ԑI�����[�h(CWjkState_Ressyasentaku ) 
		�ɈϏ����܂��B
	*/
	virtual int OnEditSelectAll_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [�����\]-[��Ԃ̃v���p�e�B] */
	virtual int OnJikokuhyouRessyaProp_Process( BOOL bQueryEnable );
	/** [�����\]-[��Ԃ�}��] 
		��s��}������
	@return
		-	-1 ;	//	X��ԍ����s���ł��B
	*/
	virtual int OnJikokuhyouRessyaInsert_Process( BOOL bQueryEnable );
	/** [�����\]-[�t�H�[�J�X���ړ�] 
	 @param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��E�I������Ă��邩��@n
					���肾�����s���܂��B�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͂��łɑI������Ă��܂�
		-	0 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͑I������Ă��܂���
	*/
	virtual int OnJikokuhyouFocusMoveDown_Process( BOOL bQueryEnable );
	/** [�����\]-[�t�H�[�J�X�E�ړ�] 
	 @param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��E�I������Ă��邩��@n
					���肾�����s���܂��B�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͂��łɑI������Ă��܂�
		-	0 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͑I������Ă��܂���
	*/
	virtual int OnJikokuhyouFocusMoveRight_Process( BOOL bQueryEnable );
	/** [�����\]-[�ŏ����v���ԗ�ԂɈړ�] 
	 	�t�H�[�J�X�Z�����A���݃t�H�[�J�X�Z���̂���w�Ǝ��̉w�̊Ԃ�
	 	����ŏ����v�b���̗�ԂɈړ����܂��B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1  ;	�Z���̏ꏊ���s��
		-	-2 ;	�t�H�[�J�X�Z�����I���w�ɂ���ꍇ�́A@n
					���̋@�\�͎��s�ł��܂���B
		-	-21 ;	�w�ԍŏ����v�b����Ԃ�����ł��܂���B@n
					������%s�w��%s�w�̗����ɐݒ肳�ꂽ��Ԃ��P�{������܂���B
	*/
	virtual int OnJikokuhyouEKikanSaisyouSec_Process( BOOL bQueryEnable );

	/** [�����\]-[���בւ�] 
		���̊֐��́AOn...() �R�}���h�n���h���EOnUpdate...() �R�}���h�n���h����
		���������s���܂��B

		�t�H�[�J�X�̂���w�����ŗ�Ԃ��\�[�g���܂��B
		�t�H�[�J�X����Ԏ�ʁE��Ԗ��E�����ɂ���ꍇ�́A
		��Ԏ�ʁE��Ԗ��E�����Ń\�[�g���܂��B
	*/
	virtual int OnJikokuhyouSort_Process( BOOL bQueryEnable );

	/** [�����\]-[��Ԕԍ��ň�{��] 
		���̊֐��́AOn...() �R�}���h�n���h���EOnUpdate...() �R�}���h�n���h����
		���������s���܂��B

		�S��Ԃ��Ԕԍ��ň�{�����܂��B
	*/
	virtual int OnJikokuhyouUnify_Process( BOOL bQueryEnable );

	// --------------------------------
	/** [�w����]-[�w�����̃v���p�e�B] 
	 @return
	 	-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
	 	-	0 ;	//	�_�C�A���O���L�����Z���ŏI���������߁A@n
	 				�ύX�͔������܂���ł����B
	 	-	-1 ;	//	X��ԍ����s���ł��B
	 	-	-2 ;	//	Y��ԍ����s���ł��B
	*/
	virtual int OnJikokuhyouEkijikokuProp_Process( BOOL bQueryEnable );

	/** [�w����]-[��������] 
	 	�t�H�[�J�X�Z���̈ʒu�́w����Order�x�� �wNull�����x�ɕύX���܂��B
		���̌��ʁA�����������������wNULL�����x�ɂȂ����ꍇ�́A
		�w�����w�^�s�Ȃ��x�ɂ��܂��B


	 	�h�L�������g�ɔ��f���A
	 	UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B
	 
		�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
	@return
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ��B
	*/
	virtual int OnJikokuhyouJikokuSakujo_Process( BOOL bQueryEnable );

	/** [�w����]-[�ʉ�] 
		�t�H�[�J�X�Z���̈ʒu�́w�w�����x���w�ʉ߁x�ɕύX���܂��B
		�w�����͒������E�������Ƃ�NULL�ɂ��܂��B

		�h�L�������g�ɔ��f���A
		UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B

		�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B

	@return
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
	*/
	virtual int OnJikokuhyouTsuuka_Process( BOOL bQueryEnable );
	
	/** [�w����]-[�ʉ�-���] 
		�t�H�[�J�X�Z���̈ʒu�́w�w�����x���w��ԁx�w�^�s�Ȃ��x
		�w�o�R�Ȃ��x�Ȃ�A
		�w�ʉ߁x�ɕύX���܂��B�w�����͕ύX���܂���B

		�t�H�[�J�X�Z���̈ʒu���w�ʉ߁x�Ȃ�A
		�w��ԁx�ɕύX���܂��B�w�����͕ύX���܂���B

		�h�L�������g�ɔ��f���A
		UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B

		�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
	@return
		-	-11  //	�Z���̏ꏊ���s��
		-	-1 	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
	*/
	virtual int  OnJikokuhyouTsuukateisya_Process( BOOL bQueryEnable );

	/** [�w����]-[�o�R�Ȃ�] 
		�t�H�[�J�X�Z���̈ʒu�́w�w�����x���w�o�R�Ȃ��x�ɕύX���܂��B

		�h�L�������g�ɔ��f���A
		UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B
		�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B
	@return
		-	-11  //	�Z���̏ꏊ���s��
		-	-1 	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
	*/
	virtual int OnJikokuhyouKeiyunasi_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [�w����]-[���w�n��] 
	@return 
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
	*/
	virtual int OnJikokuhyouSihatsu_Process( BOOL bQueryEnable );
	/** [�w����]-[���w�~��] 
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
	*/
	virtual int OnJikokuhyouSyuuchaku_Process( BOOL bQueryEnable );

	/** [�w����]-[���ʉ�] 
		�r���w�~�܂�̗�ԂƁA���̓r���w�n���̗�Ԃ𒼒ʉ����܂��B
		�h�L�������g�ɔ��f���A
		UpdateAllSubDocview() �ŁA�h�L�������g�̔��f���s���܂��B
		�t�H�[�J�X�����̈ʒu�Ɉړ����܂��B

	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	@return 
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-12 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
		-	-13;	//	�Z���̈ʒu���A�I���w����
		-	-14 ;	//	�Ή�����n����Ԃ�������܂���B
					
	�m�P�n�t�H�[�J�X���A��Ԃ̏I���w������̉w�ɂ���ꍇ�́A
		���̋@�\�͎g�p�ł��܂���B

	�m�Q�n���ʉ��̑ΏۂɂȂ�r���w�n�����
	  ���ʉ��̑ΏۂƂȂ�r���w�n����Ԃ́A�ȉ��̏����𖞂�������Ԃł��B

	  �E�t�H�[�J�X�̂�����(�r���w�~�܂�̗��)�Ɠ�����Ԏ��
	  �E�t�H�[�J�X�̂���w���n���w�Ƃ�����
	  �E�n���w�̔��������A�I����Ԃ̒���������12���Ԉȓ�
	  �E�����\�r���[��ŁA�t�H�[�J�X�̂����Ԃ̉E���ɂ�����

	  �ΏۂƂȂ��Ԃ���������ꍇ�́A���̒��ł����Ƃ������ɂ����Ԃ�
	  ���ʉ��̑ΏۂƂ��܂��B

	�m�R�n�@���ʉ����s�������ʍ쐬�����V������Ԃ́A���ʉ������w��
	�w�����́A�ȉ��̂悤�ɂȂ�܂��B

	- �w���F�r���w�~�܂�̗�ԂƓ����B
	- ������
		- �r���w�~�܂�̗�Ԃɒ��������w�肳��Ă����ꍇ�F
			���̒�����
		- �r���w�~�܂�̗�Ԃɒ��������Ȃ��A���������w�肳��Ă����ꍇ�F
			�r���w�~�܂��Ԃ̔�����
		- �r���w�~�܂�̗�Ԃɒ����������������w�肳��Ă��Ȃ��ꍇ�F
			�������͂Ȃ�
	- ������
		- �r���w�n����Ԃɔ��������w�肳��Ă����ꍇ�F
			���̔������𒼒ʉ�������Ԃ̔������Ƃ��܂��B
		- �r���w�n����Ԃɔ��������Ȃ��A���������w�肳��Ă����ꍇ�F
			�r���w�n����Ԃ̒��������A�V������Ԃ̔������Ƃ��܂��B
		- �r���w�n����Ԃɒ����������������w�肳��Ă��Ȃ��ꍇ�F
			�������͂Ȃ�
	*/
	virtual int OnJikokuhyouDirect_Process( BOOL bQueryEnable );

	/** [�w����]-[���f] 
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	@return 
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-12 ;	//	�Z���̈ʒu������̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ��B
		-	-21 ;	//	���̗�Ԃ̎n���w�E�I���w�ł͕��f�͂ł��܂���B
		-	-22 ;	//	�w�����ɒ����������������w�肳��Ă��Ȃ��w�ł́A���̋@�\�͎g�p�ł��܂���
		-	-31 ;	//	�w��̉wOrder�ł́A���f�͂ł��܂���
	*/
	virtual int OnJikokuhyouUndirect_Process(BOOL bQueryEnable );

	// --------------------------------
	/** [�w����]-[�A������] 
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͂��łɑI������Ă��܂�
		-	0 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͑I������Ă��܂���
		-	-1 ;	//	���݁A���̃R�}���h�͑I���ł��܂���
	*/
	virtual int OnJikokuhyouRenzoku_Process( BOOL bQueryEnable );
	// --------------------------------
	/** [�w����]-[�w������}��] 
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
		-	-2 ;	//	��ԉ��̉w�ł́A���̑���͂ł��܂���B
	*/
	virtual int OnJikokuhyouEkijikokuInsert_Process( BOOL bQueryEnable );
	/** [�w����]-[�w�������폜] 
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
		-	-2 ;	//	��ԉ��̉w�ł́A���̑���͂ł��܂���B
	*/
	virtual int OnJikokuhyouEkijikokuErase_Process( BOOL bQueryEnable );
	/** 
		[�w����]-[�w�����ύX] 

		�w�w�����ύX�x�_�C�A���O��\�����A���͓��e��
		m_EkijikokuModifyOperation �ɕۑ����܂��B
		�܂��A
		m_EkijikokuModifyOperation �̓��e�ɂ��������āA
		�t�H�[�J�X�ʒu�̉w������ύX���܂��B
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
				�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
				�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂��B
	@return
		-	0 :	����
		-	-1 :	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
	*/
	virtual int OnJikokuhyouModifyEkijikokuCmd_Process( BOOL bQueryEnable );

	/**
		[�w����]-[�w�����ύX�̍Ď��s]

		�O��́w�w�����ύX�x�_�C�A���O�Őݒ肳�ꂽ
		m_EkijikokuModifyOperation �̓��e�ɂ��������āA
		�t�H�[�J�X�ʒu�̉w������ύX���܂��B
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
				�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
				�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂��B
	@return
		-	0 :	����
		-	-1 :	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
	*/
	virtual int OnJikokuhyouModifyEkijikokuCmdRepeat_Process( 
		BOOL bQueryEnable );
	// --------------------------------
	/** [�w����]-[�A��1���C��]-[-1��������] 
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
	*/
	virtual int OnJikokuhyouEkijikokuDec_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[-1��] 
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
	*/
	virtual int OnJikokuhyouEkijikokuDecNoMove_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[�t�H�[�J�X������] 
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
	*/
	virtual int OnJikokuhyouEkijikokuNext_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[�t�H�[�J�X��O��] 
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
	*/
	virtual int OnJikokuhyouEkijikokuPrev_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[+1��������] 
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			iRv = -11  ;	//	�Z���̏ꏊ���s��
			iRv = -1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
	*/
	virtual int OnJikokuhyouEkijikokuInc_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[+1��] 
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
			iRv = -11  ;	//	�Z���̏ꏊ���s��
			iRv = -1 ;	//	�Z���̈ʒu���A����̗�Ԃ̓���̎����̏ꏊ�ł͂Ȃ�
	*/
	virtual int OnJikokuhyouEkijikokuIncNoMove_Process( BOOL bQueryEnable );
	// --------------------------------

	///@}
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{
	/**
	 	Shift �L�[��������Ă���΁A�J�����g��Ԃ��w��ԑI�����[�h�x��
	 	�J�ڂ����܂��B
	 	
	 	Shift �L�[��������Ă��Ȃ��ꍇ�́A
	 	�w��ԑI�����[�h�x�� OnSetFocusCell() �ɈϏ����܂�
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
	  �I���Ԑ���0�ȏ�ɂȂ�����I�����[�h�ɑJ�ڂ��܂��B
	
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

#endif /*CWjkState_Ressyahensyu_h*/
