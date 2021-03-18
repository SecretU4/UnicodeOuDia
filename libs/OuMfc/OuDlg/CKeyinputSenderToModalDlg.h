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
//	CKeyinputSenderToModalDlg.h
// ****************************************************************
*/
/** @file */
#ifndef  CKeyinputSenderToModalDlg_h
#define  CKeyinputSenderToModalDlg_h

#include <windows.h>
#include <deque>

namespace OuMfc{
namespace OuDlg{

// ****************************************************************
//	CKeyinputSenderToModalDlg
// ****************************************************************
/**
 @brief
 �y�T�v�z  �e�E�C���h�E�ւ̃L�[���͂��_�@�� ModalDialog ���J���ꍇ�A
 ���[�_���_�C�A���O�̓���̃G�f�B�b�g�R���g���[���ɁA
 �L�[���̓��b�Z�[�W�i WM_KEYDOWN , WM_KEYUP �j��]�����܂��B
 
   ���̃N���X���g���ƁA���C���E�C���h�E�ŕ����L�[���������Ƃ���
	���[�_���_�C�A���O���N������Ɠ����ɁA���̃_�C�A���O�̃R���g���[���ɁA
	�����ꂽ������ݒ肷�邱�Ƃ��ł��܂��B
	  ���Ƃ��΁A
 
 -# �e�E�C���h�E��� "A" �Ɠ��͂���ƁA
 -# ���[�_���_�C�A���O�{�b�N�X���J���A
 -# ���[�_���_�C�A���O��́A����̃G�f�B�b�g�R���g���[���Ƀt�H�[�J�X��
 �ݒ肳��A
 -# ���̃G�f�B�b�g�R���g���[���� "A" �����͂���Ă���
 
 �Ƃ������Ƃ��ł��܂��B
 
   ���̃N���X�ł́A��L�̗��
 
 - �e�E�C���h�E���w�]�����e�E�C���h�E�x
 - ���[�_���_�C�A���O���w�]����_�C�A���O�x
 - ���[�_���_�C�A���O��̃G�f�B�b�g�R�����g�[�����w�]����R���g���[���x
 
 �ƌď̂��܂��B
 
 <H4>
 �y���̃N���X�̏�ԁz
 </H4>

   ���̃N���X�̃I�u�W�F�N�g�́A�ȉ��̂悤�ȏ�Ԃ������܂��B
 
 <H5>
 �P�D��]�����
 </H5>
 
   �ʏ�̏�Ԃł��B�w�]�����E�C���h�E�x�́A
  WM_KEYDOWN �E WM_KEYUP ���A�������g�ŏ������܂��B
   �w�]�����E�C���h�E�x�́A�w�]����_�C�A���O�x���N������ۂɁA
  CKeyinputSenderToModalDlg �I�u�W�F�N�g�̏�Ԃ�
 �w�Q�D�]����R���g���[���o�^�҂��x�ɑJ�ڂ��܂��B
 
 
 <H5>
 �Q�D�]�����E�]����R���g���[���o�^�҂�
 </H5>
 
   �w�]�����E�C���h�E�x�́A�w�]����R���g���[���x
 �i�ʏ�́A�G�f�B�b�g�R���g���[���j�ւ̃��b�Z�[�W�̓]�����s���Ă��܂����A
 �w�]����R���g���[���x�̏������ł��Ă��܂���B���̂��߁A�]�����ꂽ
 ���b�Z�[�W�́A CKeyinputSenderToModalDlg �ɒ~�����Ă��܂��B
 
 
 <H5>
 �R�D�]�����E�]����R���g���[���o�^�ς�
 </H5>
 
   �w�]�����E�C���h�E�x�́A�w�]����R���g���[���x
 �i�ʏ�́A�G�f�B�b�g�R���g���[���j�ւ̃��b�Z�[�W�̓]�����s���Ă��܂��B
 ���b�Z�[�W�́A�w�]����R���g���[���x�ɓ��B���Ă��܂��B
 
 
 <H4>
 �y�g�����z
 </H4>
 
 <H5>
 ���w�]�����E�C���h�E�x���̏���
 </H5>
 
 �P�D  �w�]�����E�C���h�E�x�I�u�W�F�N�g�́A CKeyinputSenderToModalDlg 
 �̃I�u�W�F�N�g�𐶐����A�ێ����Ă��������B���̃N���X�̃I�u�W�F�N�g�́A
 �w�]�����E�C���h�E�x���������Ă���Ԓ��͐��������Ă��������B
 
 �Q�D  �w�]�����E�C���h�E�x�ł́A OnKeyDown() �E OnKeyUp() 
 ���I�[�o���C�h���Ă��������B�����֐��ł́A CKeyinputSenderToModalDlg 
 �I�u�W�F�N�g�� CKeyinputSenderToModalDlg::OnKeyDown() �E 
  CKeyinputSenderToModalDlg::OnKeyUp() �E 
	�ւ̈Ϗ����s���Ă��������B
 
 <H5>
 ���w�]�����E�C���h�E�x�Łw�]����_�C�A���O�x���J���^�C�~���O
 </H5>
	�ʏ�A�u�w�]�����E�C���h�E�x�ŕ����L�[���������Ƃɂ��
	�w�]����_�C�A���O�x���J���A
	���̃L�[���͓��e���w�]����_�C�A���O�x�̃R���g���[���ɔ��f�����v
	�Ƃ�������ɂȂ�܂��B�w�]�����E�C���h�E�x�ŕ����L�[�������ꂽ���ǂ�����
	����́A�w�]�����E�C���h�E�x�� OnKeyDown() ��

	CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown()

	���Ăяo�����Ƃɂ�蔻�f�ł��܂��B

 <H5>
 ���w�]�����E�C���h�E�x����A�w�]����_�C�A���O�x���J��
 </H5>
 
 �P�D  �w�]�����E�C���h�E�x�́A�w�]����_�C�A���O�x���J���󋵂ɂȂ�����A
  CKeyinputSenderToModalDlg::startSend() ���Ăяo���āA�]����
 �J�n���Ă��������B

   �w�]�����E�C���h�E�x�� OnKeyDown() �Łw�]����_�C�A���O�x���J���ꍇ�́A
  CKeyinputSenderToModalDlg::startSend() ���Ăяo������ŁA 
  CKeyinputSenderToModalDlg::OnKeyDown() ���Ăяo���Ă��������B
   ���̌��܂�́A OnKeyUp()  �ɂ����Ă͂܂�܂��B
 
 �Q�D  �]�����J�n���Ă���A�w�]����_�C�A���O�x�� CDialog::DoModal() ��
 �N�����Ă��������B
 
 �R�D  CDialog::DoModal() �����^�[��������A 
  CKeyinputSenderToModalDlg::endSend()  ���Ăяo���āA�]����
 �I�����Ă��������B
 
 
 <H5>
 ���w�]����_�C�A���O�x���̏���
 </H5>
 
 �P�D  �w�]����_�C�A���O�x�́A�e�E�C���h�E�ƂȂ�w�]�����E�C���h�E�x��
 �ێ����Ă��� CKeyinputSenderToModalDlg �I�u�W�F�N�g�ɑ΂��āA
 ���\�b�h�ďo���s���K�v������܂��B���̂��߁A�w�]����_�C�A���O�x�N���X�́A
  CKeyinputSenderToModalDlg �|�C���^�̕ϐ���ێ����A�R���X�g���N�^��
 ����������悤�ɂ��Ȃ��Ă͂Ȃ�܂���B
 
 �Q�D  �w�]����_�C�A���O�x�́AOnShowWindow() �ŁA�w�]����R���g���[���x
 �Ƀt�H�[�J�X��ݒ肵�Ă��������B����́A CDialog::GotoDlgCtrl() ��
 �s���܂��B
   �w�]����R���g���[���x�Ƀt�H�[�J�X��ݒ肵�Ă���A
  CKeyinputSenderToModalDlg::registerCtrl() �ŁA�w�]����R���g���[���x
  ��o�^���Ă��������B����ɂ���āA���b�Z�[�W�̓]�����n�܂�܂��B
 
 �R�D  �w�]����_�C�A���O�x�́A OnDestroy() ��
  CKeyinputSenderToModalDlg::unregisterCtrl() ���Ăяo���A
 �w�]����R���g���[���x�̓o�^���������Ă��������B
 
 */
class CKeyinputSenderToModalDlg
{
// ********************************
///@name �֘A
// ********************************
 private:
	/**
		������Ԃł� NULL �ł��B
		�o�^����Ă���w�]���R���g���[���x������Ԃ́A
		���̃R���g���[����HWND�ƂȂ�܂��B
	 */
	HWND	m_hwndControl ;
	

// --------------------------------
///@name �����f�[�^
// --------------------------------
 private:
	/**
		������Ԃł͋U�ł��B
		�w�]�����E�C���h�E�x�����b�Z�[�W�]�����̊Ԃ����^�ł��B
	 */
	bool	m_bIsSend ;

	
	/**
	 @brief
	  CKeyinputSenderToModalDlg ��
		�]�����郁�b�Z�[�W��ێ�����\���̂ł��B
		PostMessage() �֐��̌ďo�ɕK�v�Ȓl��ێ����܂��B
	*/
	struct MsgToPost{
		  UINT Msg ;       ///< ���b�Z�[�W
		  WPARAM wParam ;  ///< ���b�Z�[�W�̍ŏ��̃p�����[�^
		  LPARAM lParam ;  ///< ���b�Z�[�W�� 2 �Ԗڂ̃p�����[�^
	};
	/**
		this ���u�Q�D�]�����E�]����R���g���[���o�^�҂��v��Ԃ̊Ԃ́A
		�]����֓]�����ׂ����b�Z�[�W��ێ����܂��B
		registerControl() �ɂ���� �w�]����R���g���[���x���o�^���ꂽ��A
		this �́A�����ɕێ����Ă��郁�b�Z�[�W�𑗐M���āA
		���̃R���e�i����ɂ��܂��B
	
		endSend() �œ]�����I�������ꍇ�́Athis �͂��̃R���e�i���A
		�P�ɋ�ɂ��܂��B
	 */
	std::deque< MsgToPost >	m_contmsgToSend ;
	
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	CKeyinputSenderToModalDlg() ;
	


// ********************************
//	CKeyinputSenderToModalDlg
// ********************************
 public:
	// ********************************
	///@name �w�]�����E�C���h�E�x����̑���
	// ********************************
	///@{
	/**
		  �w�]�����E�C���h�E�x�́A OnKeyDown() ��K���I�[�o���C�h���A
		���̃��\�b�h���Ăяo���Ă��������B
		�����́A�w�]�����E�C���h�E�x�� OnKeyDown() �œn���ꂽ���̂�
		�w�肵�Ă��������B
	@see CWnd::OnKeyDown()
	@param nChar [in]
		�w�肳�ꂽ�L�[�̉��z�L�[ �R�[�h���w�肵�܂��B
	@param nRepCnt [in]
		���s�[�g �J�E���g (���[�U�[���L�[�������������Ƃ��ɌJ��Ԃ�
		�L�[����̉�) ���w�肵�܂��B
	@param nFlags [in]
		�X�L���� �R�[�h�A�L�[�ϊ��R�[�h�A���O�̃L�[��ԁA�����
		�R���e�L�X�g �R�[�h���w�肵�܂��B
	@return
		���̊֐������b�Z�[�W��]��������A�^�ł��B
		���̊֐����^��Ԃ����ꍇ�́A�����Ƃ���
		�w�]�����E�C���h�E�x�̊�{�N���X�̏���
		�iCWnd::OnKeyDown() �j
		�͌Ăяo���Ȃ��ł��������B
	 */
	virtual bool OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags );

	/**
		  �w�]�����E�C���h�E�x�́A OnKeyUp() ��K���I�[�o���C�h���A
		���̃��\�b�h���Ăяo���Ă��������B
		�����́A�w�]�����E�C���h�E�x�� OnKeyUp() �œn���ꂽ���̂�
		�w�肵�Ă��������B
	@see CWnd::OnKeyUp()
	@param nChar [in]
		�w�肳�ꂽ�L�[�̉��z�L�[ �R�[�h���w�肵�܂��B
	@param nRepCnt [in]
		���s�[�g �J�E���g (���[�U�[���L�[�������������Ƃ��ɌJ��Ԃ�
		�L�[����̉�) ���w�肵�܂��B
	@param nFlags [in]
		�X�L���� �R�[�h�A�L�[�ϊ��R�[�h�A���O�̃L�[��ԁA�����
		�R���e�L�X�g �R�[�h���w�肵�܂��B
	@return
		���̊֐������b�Z�[�W��]��������A�^�ł��B
		���̊֐����^��Ԃ����ꍇ�́A�����Ƃ��� 
		�w�]�����E�C���h�E�x�̊�{�N���X�̏���
		�iCWnd::OnKeyUp()  �j
		�͌Ăяo���Ȃ��ł��������B

	 */
	virtual bool OnKeyUp( UINT nChar, UINT nRepCnt, UINT nFlags );

	
	/**
		 ���b�Z�[�W�]�����J�n���܂��B
		
		 �w�]�����E�C���h�E�x�́A�w�]����_�C�A���O�x���J���󋵂ɂȂ�����A
		 CKeyinputSenderToModalDlg::startSend() ���Ăяo���āA�]����
		�J�n���Ă��������B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	���łɓ]�����ł��B
	*/
	virtual int startSend() ;
	
	/**
		 ���b�Z�[�W�]�����ɁA���b�Z�[�W�̓]�����I�����܂��B
		
		 �w�]�����E�C���h�E�x�́A�w�]����_�C�A���O�x��
		 CDialog::DoModal() �����^�[��������A
		  CKeyinputSenderToModalDlg::endSend()  ���Ăяo���āA
		�]�����I�����Ă��������B
	 */
	virtual void endSend() ;
	
	///@}
	// ********************************
	///@name �w�]����_�C�A���O�x����̑���
	// ********************************
	///@{
	/**
		�w�]����_�C�A���O�x�́A�w�]����R���g���[���x�Ƀt�H�[�J�X��
		�ݒ肵�Ă���A CKeyinputSenderToModalDlg::registerCtrl() �ŁA
		�w�]����R���g���[���x ��o�^���Ă��������B����ɂ���āA
		���b�Z�[�W�̓]�����n�܂�܂��B
	  @param hwndControl [in]
		�]����R���g���[���� HWND ���w�肵�Ă��������B
	  @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;
			//	���M���łȂ����A���łɁw�]����R���g���[���x��
			//	�o�^�ς݂ł�
	 */
	virtual int registerCtrl( HWND hwndControl ) ;
	
	/**
		�w�]����_�C�A���O�x�́A OnDestroy() �� 
		CKeyinputSenderToModalDlg::unregisterCtrl() ���Ăяo���A
		�w�]����R���g���[���x�̓o�^���������Ă��������B
	 */
	virtual void unregisterCtrl() ;
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 @return
		 ���b�Z�[�W�]�����Ȃ�^�ł��B
	 */
	virtual bool isSend() ;
	
	/**
	 @return
		�o�^����Ă���w�]����R���g���[���x��Ԃ��܂��B
		�o�^����Ă��Ȃ��Ƃ��́ANULL��Ԃ��܂��B
	 */
	virtual HWND getControl() ;
	///@}
	// ********************************
	///@name 
	// ********************************
	///@{
	/**
	 @return
		���݉�����Ă���L�[���A�����L�[�ł���ΐ^�ł��B
		�������A�����L�[���Q������Ă���ꍇ�͋U�ƂȂ�܂��B
		�܂��ACtrl,Alt��������Ă���ꍇ���A�U�ƂȂ�܂��B
	 */
	static bool AnyLetterOrDigitKeyIsDown() ;
	///@}
};

} //namespace OuDlg
} //namespace OuMfc

#endif /*CKeyinputSenderToModalDlg_h*/
