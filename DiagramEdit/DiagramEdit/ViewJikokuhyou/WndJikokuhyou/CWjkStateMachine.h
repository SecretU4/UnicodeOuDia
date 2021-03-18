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
//	CWjkStateMachine.h
// ****************************************************************
*/
/** @file */
#ifndef  ViewJikokuhyou_CWjkStateMachine_h
#define  ViewJikokuhyou_CWjkStateMachine_h

#include "NsOu\Ou.h"
#include "NsMu\CMup_vector.h"
#include "NsMu\CaMuCast.h"

#include "ViewJikokuhyou\WndJikokuhyou\CWjkState.h"

namespace ViewJikokuhyou{ namespace WndJikokuhyou{

// ****************************************************************
//	CWjkStateMachine
// ****************************************************************
/**
@brief
  CWndJikokuhyou �̏�ԋ@�B��\���N���X�ł��B

�@���̃N���X�́A��Ԃ�\�� CWjkState �I�u�W�F�N�g��
 �R���e�i�Ƃ��ē����܂��B

  �܂��A���̃N���X�̓J�����g��Ԃ�ێ����܂��B��ԑJ�ڎ���
����E�ޏꓮ��̌Ăяo�����s���܂��B

  
�y�g�����z

(1)  add() �ŁACWndJikokuhyou �I�u�W�F�N�g��ǉ����Ă��������B

(2)  setCurrentStateIdx() �ŁA�����̃J�����g��Ԃ��w�肵�Ă��������B

(3)  getCurrentState() �ŁA�J�����g��Ԃ� CWjkState �I�u�W�F�N�g�ւ̃|�C���^���擾���邱�Ƃ��ł��܂��B
  ���̃|�C���^�ɑ΂��ă��\�b�h���Ăяo�����Ƃɂ��A��ԑJ�ڂɉ������������s�킹�邱�Ƃ��ł��܂��B

(4)  setCurrentStateIdx() �ŁA��ԑJ�ڐ���w�肷�邱�Ƃɂ��A�J�����g��Ԃ�J�ڂ����邱�Ƃ��ł��܂��B

*/
class CWjkStateMachine 
{
private:
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
		�w�J�����g��ԁx��\���܂��B
	
		�w�J�����g��ԁx�́A m_CStateCont �R���e�i�̃C���f�N�X�Ŏ����܂��B
		-1 �́A�ǂ̏�Ԃɂ������Ă��Ȃ���Ԃł��B
	 */
	int m_iCurrentStateIdx ;
	///@}
	// ********************************
	///@name	�W��
	// ********************************
	///@{
	/**
		�w��ԁx�I�u�W�F�N�g�ւ̃|�C���^��ێ�����R���e�i�ł��B
	
		add() �ŃI�u�W�F�N�g��ǉ����邱�Ƃ��ł��܂��B
	 */
	CMup_vector< Ou< CWjkState > >	m_CStateCont ;

	/**
		m_CStateCont �̃A�_�v�^�ł��B
	
		Mu �C���^�[�t�F�[�X��񋟂��܂��B
	 */
	CaMuCast< CWjkState* , Ou< CWjkState > >
		m_CStateContGet ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CWjkStateMachine() ;

	// ********************************
	///@name	CWjkStateMachine-����
	// ********************************
	///@{
	int getCurrentStateIdx() ;

	/**
		�w�J�����g��ԁx��ύX���܂��B
	
		���̊֐��́A�ȉ��̏��ŏ������s���܂��B
	
		-# �V�����w�J�����g��ԁx�� CWjkState �I�u�W�F
		�N�g�ɑ΂��āA CWjkState::canEnter() ��
		�Ăяo���āA����\���ۂ��𒲂ׂ�B
			����s�\�Ȃ�A�㑱�̏����͍s��Ȃ��B
		-# ����܂ł́w�J�����g��ԁx�� CWjkState 
		�I�u�W�F�N�g�ɑ΂��āA CWjkState::onExit() ��
		�Ăяo���āA�ޏꓮ����s�킹��B
		-# �J�����g��Ԃ����� m_iCurrentStateIdx ���X�V�B
		-# �V�����w�J�����g��ԁx�� CWjkState 
		�I�u�W�F�N�g�ɑ΂��āACWjkState::onEnter() ��
		�Ăяo���āA���ꓮ����s�킹��B
	
		���� value �� m_iCurrentStateIdx ���������ꍇ�ł��A
		CWjkState::onExit() , 
		CWjkState::onEnter() �̌Ăяo���͍s���܂��B
		
	@param value [in]
		���́w�J�����g��ԁx���w�肵�Ă��������B
		�w�J�����g��ԁx�́A m_CStateCont �R���e�i�̃C���f�N�X�Ŏ����܂��B
	@return
		��ԑJ�ڂ����������� 0 �ȏ�A�J�ڂł��Ȃ���Ε��̐��ł��B
		�J�ڐ�̏�Ԃ� canEnter() �����̐���Ԃ����ꍇ�́A
		���̐���Ԃ��āA��ԑJ�ڂ͎��s���܂��B
	*/
	int setCurrentStateIdx( int value ) ;
	///@}

	// ********************************
	///@name	CWjkStateMachine-�W�� 
	// ********************************
	///@{
	Mu< CWjkState* >*	getCStateContGet()
	{	return &m_CStateContGet ;};
	///@}

	// ********************************
	///@name	CWjkStateMachine-���� 
	// ********************************
	///@{
	/**
		��Ԃ�ǉ����܂��B
	*/
	void add( Ou< CWjkState > pState ) ;
	
	/**
	@return 
		�J�����g��Ԃ̃I�u�W�F�N�g��Ԃ��܂��B
		 m_iCurrentStateIdx == -1 �̏ꍇ�� NULL ��Ԃ��܂��B

		���̊֐��̖߂�l�́A getCStateContGet( getCurrentStateIdx() ) 
		�Ɠ����ł��B
	*/
	CWjkState* getCurrentState() ;


	///@}
};

} } // namespace WndJikokuhyou namespace ViewJikokuhyou

#endif //ViewJikokuhyou_CWjkStateMachine_h
