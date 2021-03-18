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
//	CWjkState.h
// ****************************************************************
*/
/** @file */
#ifndef  CWjkState_h
#define  CWjkState_h
#include "DcdGrid\CDcdGridCell.h"

#include "entDed\CentDedDia.h"
#include "ViewJikokuhyou\CJikokuhyouDoc.h"

namespace ViewJikokuhyou{ namespace WndJikokuhyou{

using namespace DcDrawLib::DcdGrid;


class CWndJikokuhyou ;	// outer �ւ̎Q��

// ****************************************************************
//	CWjkState
// ****************************************************************
/**
   @brief
   �y�T�v�z
     CJikokuhyou�́w��ԁx�P��\�����ۃN���X�ł��B
     �w��ԁx���ɔh���N���X���쐬���A CWndJikokuhyou �ւ�
   �E�C���h�E���b�Z�[�W�n���h���E���j���[�R�}���h�n���h���ɑΉ����鏈����
   �������Ă��������B
   
     CWndJikokuhyou �I�u�W�F�N�g�́A�w��ԁx�̐��� CState ���W���
   �ێ����܂��B�܂��A�����w��ԁx�̂����̈���w�J�����g��ԁx�Ƃ��܂��B
   
     �w�J�����g��ԁx�́A CWndJikokuhyou::m_iCurrentStateIndex 
   �ŕ\���܂��B
 */	
class CWjkState
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	typedef CWndJikokuhyou outer ;
	
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
	  	  �O���� CWndJikokuhyou �I�u�W�F�N�g�ւ̃|�C���^�ł��B
	  	  ���̃I�u�W�F�N�g�́Athis ���j�������܂ł͐�������
	  	���Ȃ��Ă͂Ȃ�܂���B
	  	  �R���X�g���N�^�Ō��܂�܂��B
	 */
	CWndJikokuhyou*	m_pCWndDcdGrid ;
	///@}

protected:
	// --------------------------------
	///@name	�����֐�
	// --------------------------------
	///@{
	/**
	   @return
	  	�Ή�����h�L�������g�I�u�W�F�N�g��Ԃ��܂��B
	 */
	CJikokuhyouDoc*	GetDocument() ;
	
	/**
	   @return
	  	���̃O���b�h��������ԕ�����Ԃ��܂��B
	 */
	ERessyahoukou getRessyahoukou() ;
	
	
	/**
	   @return
	  	CentDedDia �I�u�W�F�N�g��Ԃ��܂��B
	 */
	const CentDedDia*	getCentDedDia();
	
	/**
	   @return
	  	CentDedRessyaCont �I�u�W�F�N�g��Ԃ��܂��B
	 */
	const CentDedRessyaCont*	getCentDedRessyaCont();
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CWjkState( CWndJikokuhyou*	pCWndDcdGrid ) ;
	virtual ~CWjkState() ;

public:
	// ********************************
	//	CWjkState
	// ********************************
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	CWndJikokuhyou*	getCWndDcdGrid();
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 @return
		���̏�ԂɑJ�ډ\�ł���� 0 �ȏ�ł��B
		�f�t�H���g�ł́A0�ł��B
		
		�y�I�[�o���C�h�z
		���̏�ԂɑJ�ڂ��邽�߂̏������w�肵�Ă��������B
	*/
	virtual int canEnter() ;
	/**
	 	���̏�Ԃւ̓��ꓮ����s���܂��B
	 
	 	CWndJikokuhyou �́A�w�J�����g��ԁx��this �ɐݒ肵��
	 	����ɁA���̊֐����Ăяo���܂��B
	 
	 	�y�I�[�o���C�h�z
	 	���ꓮ����������Ă��������B
	*/
	virtual void onEnter() = 0  ;
	/**
	 	���̏�Ԃ���̑ޏꓮ����s���܂��B
	 
	 	CWndJikokuhyou �́A�w�J�����g��ԁx��this ���瑼�ɐݒ肷��
	 	���O�ɁA���̊֐����Ăяo���܂��B
	 
	 	�y�I�[�o���C�h�z
	 	�ޏꓮ����������Ă��������B
	*/
	virtual void onExit() = 0  ;
	///@}
	// ********************************
	///@name CView ����̈Ϗ�
	// ********************************
	///@{
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) ;
	///@}
	// ********************************
	///@name CWndJikokuhyou����̈Ϗ�
	// ********************************
	///@{
	/**
	 	[�I�[�o���C�h] CWndJikokuhyou::super (CWndDcdGrid)��
	 	�����ɈϏ����܂��B
	*/
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	/**
	  	[�I�[�o���C�h] CWndJikokuhyou::super (CWndDcdGrid)��
	  	�����ɈϏ����܂��B
	 */
	virtual void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	/**
	  	[�I�[�o���C�h] CWndJikokuhyou::super (CWndDcdGrid)��
	  	�����ɈϏ����܂��B
	 */
	virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) ;
	/**
	  	[�I�[�o���C�h] CWndJikokuhyou::super (CWndDcdGrid)��
	  	�����ɈϏ����܂��B
	 */
	virtual void OnWM_IME_STARTCOMPOSITION() ;
	/**
	  	[�I�[�o���C�h] CWndJikokuhyou::super (CWndDcdGrid)��
	  	�����ɈϏ����܂��B
	 */
	virtual void OnLButtonDblClk(UINT nFlags, CPoint point) ;
	///@}
	// ********************************
	///@name View�̃R�}���h�n���h���̈Ϗ�
	// ********************************
	///@{
	// --------------------------------
	//	Edit
	/**	
		[�ҏW]-[�؂���]
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	���̃R�}���h�͑I���ł��܂���
	
		���̃N���X�ł́A��� -1 �ł��B
	*/
	virtual int OnEditCut_Process( BOOL bQueryEnable );

	/**	[�ҏW]-[�R�s�[]	*/
	virtual int OnEditCopy_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[�\��t��]	*/
	virtual int OnEditPaste_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[����]	*/
	virtual int OnEditClear_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[�����̂ݓ\��t��]	*/
	virtual int OnEditPasteEkiJikoku_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[���ׂđI��]	*/
	virtual int OnEditSelectAll_Process( BOOL bQueryEnable );

	// --------------------------------
	//	Jikokuhyou
	/** [�����\]-[��Ԃ̃v���p�e�B] */
	virtual int OnJikokuhyouRessyaProp_Process( BOOL bQueryEnable );
	/** [�����\]-[��Ԃ�}��] */
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
		-  -1 ;	//	���̃R�}���h�͑I���ł��܂���(���j���[������)
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
		-  -1 ;	//	���̃R�}���h�͑I���ł��܂���(���j���[������)
	*/
	virtual int OnJikokuhyouFocusMoveRight_Process( BOOL bQueryEnable );
	/** [�����\]-[�ŏ����v���ԗ�ԂɈړ�] */
	virtual int OnJikokuhyouEKikanSaisyouSec_Process( BOOL bQueryEnable );
	/** [�����\]-[���בւ�] */
	virtual int OnJikokuhyouSort_Process( BOOL bQueryEnable );
	/** [�����\]-[��Ԕԍ��ň�{��] */
	virtual int OnJikokuhyouUnify_Process( BOOL bQueryEnable );
	// [�����\]-[�����\�r���[�̃v���p�e�B] 
	//	�́ACWndJikokuhyou �ŏ������܂��B

	// --------------------------------
	//	Ekijikoku
	/** [�w����]-[�w�����̃v���p�e�B] */
	virtual int OnJikokuhyouEkijikokuProp_Process( BOOL bQueryEnable );
	/** [�w����]-[��������] */
	virtual int OnJikokuhyouJikokuSakujo_Process( BOOL bQueryEnable );
	/** [�w����]-[�ʉ�] */
	virtual int OnJikokuhyouTsuuka_Process( BOOL bQueryEnable );
	/** [�w����]-[�ʉ�-���] */
	virtual int OnJikokuhyouTsuukateisya_Process( BOOL bQueryEnable );
	/** [�w����]-[�o�R�Ȃ�] */
	virtual int OnJikokuhyouKeiyunasi_Process( BOOL bQueryEnable );
	// --------------
	/** [�w����]-[���w�n��] */
	virtual int OnJikokuhyouSihatsu_Process( BOOL bQueryEnable );
	/** [�w����]-[���w�~��] */
	virtual int OnJikokuhyouSyuuchaku_Process( BOOL bQueryEnable );
	/** [�w����]-[���ʉ�] */
	virtual int OnJikokuhyouDirect_Process( BOOL bQueryEnable );
	/** [�w����]-[���f] */
	virtual int OnJikokuhyouUndirect_Process( BOOL bQueryEnable );
	// --------------
	/** [�w����]-[�A������] 
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͂��łɑI������Ă��܂�
		-	0 ;	//	(bQueryEnable=TRUE�̏ꍇ)���̍��ڂ͑I������Ă��܂���
	*/
	virtual int OnJikokuhyouRenzoku_Process( BOOL bQueryEnable );
	// --------------
	/** [�w����]-[�w������}��] */
	virtual int OnJikokuhyouEkijikokuInsert_Process( BOOL bQueryEnable );
	/** [�w����]-[�w�������폜] */
	virtual int OnJikokuhyouEkijikokuErase_Process( BOOL bQueryEnable );
	/** [�w����]-[�w�����ύX] */
	virtual int OnJikokuhyouModifyEkijikokuCmd_Process( BOOL bQueryEnable );
	/** [�w����]-[�w�����ύX�̍Ď��s] */
	virtual int OnJikokuhyouModifyEkijikokuCmdRepeat_Process( 
		BOOL bQueryEnable );
	// --------------
	/** [�w����]-[�A��1���C��]-[-1��������] */
	virtual int OnJikokuhyouEkijikokuDec_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[-1��] */
	virtual int OnJikokuhyouEkijikokuDecNoMove_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[�t�H�[�J�X������] */
	virtual int OnJikokuhyouEkijikokuNext_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[�t�H�[�J�X��O��] */
	virtual int OnJikokuhyouEkijikokuPrev_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[+1��������] */
	virtual int OnJikokuhyouEkijikokuInc_Process( BOOL bQueryEnable );
	/** [�w����]-[�A��1���C��]-[+1��] */
	virtual int OnJikokuhyouEkijikokuIncNoMove_Process( BOOL bQueryEnable );
	///@}
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{
	/**
	 	[�I�[�o���C�h] CWndJikokuhyou::super (CWndDcdGrid)��
	 	�����ɈϏ����܂��B
	*/
	virtual void OnSetFocusCell( CDcdGridCell* pCDcdGridCell ) ;
	/**
		[�I�[�o���C�h] CWndJikokuhyou::super (CWndDcdGrid)��
		�����ɈϏ����܂��B
	*/
	virtual void OnSetXFixafterColumnNumber( int iFixafterColumnNumber ) ;
	/**
		[�I�[�o���C�h] CWndJikokuhyou::super (CWndDcdGrid)��
		�����ɈϏ����܂��B
	*/
	virtual void OnSetYFixafterColumnNumber( int iFixafterColumnNumber ) ;


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
		  �����͂���܂���B
	
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



#endif //CWjkState_h
