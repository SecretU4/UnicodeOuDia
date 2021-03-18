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
//	CHidemdiMainfrm.h
// ****************************************************************
*/
/** @file */
#ifndef  CHidemdiMainfrm_h
#define  CHidemdiMainfrm_h

#include <afxwin.h>

namespace OuMfc{
namespace Hidemdi{

// ****************************************************************
//	CHidemdiMainfrm
// ****************************************************************
/** @brief
 * �y�T�v�z
 *   Hidemdi �A�v���P�[�V�����ɂ�����AMDI�t���[���E�C���h�E�N���X�ł��B
 *
 *   Hidemdi �A�v���P�[�V�����̃��C���t���[���E�C���h�E�́A���̃N���X��
 *	�h���N���X�łȂ��Ă͂Ȃ�܂���B
 *
 *	  Hidemdi �A�v���P�[�V�����ł́A�I�y���[�^�̃��j���[����ɉ����āA
 *	�T�uView���J���̂́A���C���t���[���E�C���h�E�̐Ӗ��ł��B
 *	�A�v���P�[�V�����́A CHidemdiMainMDIFrameWnd ���p������
 *	�w���C���t���[���E�C���h�E�x�N���X���쐬���A������UI�@�\��
 *	��������K�v������܂��B
 *
 *	�y�g�����z
 *	Doc/View���f����MFC�A�v���P�[�V�����ɂ�����A
 *	��ʓI�ȃ��C���E�C���h�E�̎g�����Ɠ����ł��B
 *	
 *	  CHidemdiApp�h���N���X �� InitInstance() �̃I�[�o���C�h���ŁA
 *	�ȉ��̏������o�āA���C���t���[���E�C���h�E���쐬���Ă��������B
 *
 *	�P�D  �I�u�W�F�N�g�𐶐����܂��B
 *
 *	�Q�D CFrameWnd::LoadFrame() �ŃE�C���h�E���쐬���܂��B
 *
 *	�R�D CWinApp::m_pMainWnd �ɁA���̃I�u�W�F�N�g�̃|�C���^���Z�b�g���܂��B
 *
 *	���̃I�u�W�F�N�g�̌�n���́AMFC�̃t���[�����[�N���s���܂��B
 *
 * @see ��L�̎菇�̗�́ACHidemdiRootDoctmpl �̐������������������B
 *
 * @attention
 *	���C���t���[���E�C���h�E�𐶐�����Ƃ���
 *	CFrameWnd::LoadFrame() �ɓn��ID�ƁA
 *	HidemdiRootDoctmpl() �̃R���X�g���N�^�̑�������
 *	�n��ID�́A�����l�ɂ��ׂ��ł��B
 *	(���̃h�L�������g�e���v���[�g�����p����
 *	���j���[�E�A�C�R���E�A�N�Z�����[�^�ƁA���C���t���[���E�C���h�E
 *	�����p���� ���j���[�E�A�C�R���E�A�N�Z�����[�^ ��
 *	����ł���ׂ��ł��j
 */
class CHidemdiMainfrm : public CMDIFrameWnd
{
// ********************************
//	�]���^
// ********************************
 public:
	typedef CMDIFrameWnd	super ;

// ********************************
///@name	����
// ********************************
///@{
 private:
	/**
	 *	�^�Ȃ�A�w���[�g�h�L�������g�x�ɕύX��
	 *	�������Ƃ��ɁA�^�C�g���o�[�� "*" ��\�����܂��B
	 *
	 *	�����l�� false �ł����A���\�b�h��
	 *	�ύX�ł��܂����B
	 * @attention
	 *	���̋@�\�́A���ݓ��삵�Ă��܂���B
	 *	����́A OnUpdateFrameTitle() ���Ăяo�����
	 *	�񐔂����Ȃ����߂ł��B
	 */
	bool m_bIsModifiedSign ;

///@}

// --------------------------------
//	CFrameWnd
// --------------------------------
 protected:
	/**
	 * 	�t���[�����[�N���Ăяo���֐��ł��B
	 *
	 *	���̊֐��ł́A���C���t���[���E�C���h�E��
	 *	�^�C�g���o�[���X�V���܂��B
	 * @param bAddToTitle [in]
	 *	- true ;	�^�C�g���o�[�ɁA�A�v���P�[�V��������
	 *		�h�L�������g����t�����܂��B
	 *	- false ;	�^�C�g���o�[�́A�A�v���P�[�V�������݂̂Ƃ��܂��B
	 *
	 * �y�I�[�o���C�h�z
	 *	MainwndTitlebarUpdate() ���Ăяo���āA
	 *	�^�C�g���o�[���X�V���܂��B
	 */
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle)  ;


// --------------------------------
//	CHidemdiMainfrm
// --------------------------------
 protected:
	/**
	* 	���C���E�C���h�E�̃^�C�g���o�[���A�ŐV�̏�ԂɍX�V���܂�
	*
	* �y�I�[�o���C�h�z
	* 	 MainwndTitlebarStrGet() �̌��ʂ��^�C�g���o�[�ɃZ�b�g���܂�
	*/
	virtual BOOL MainwndTitlebarUpdate() ;

	/**
	* 	���C���E�C���h�E�̃^�C�g���o�[�ɃZ�b�g���ׂ��������
	* 	�쐬���ĕԂ��܂��B
	*
	*	���̊֐����I�[�o���C�h���邱�Ƃɂ��A
	*	�^�C�g���o�[������̍쐬���@��ύX���邱�Ƃ��ł��܂��B
	*
	* @param pRString [out]
	* 	  ���̊֐��͂��̕�����I�u�W�F�N�g�ɁA�^�C�g���o�[�������
	* 	�Z�b�g���܂��B
	* 	  �K�v�Ȃ��Ȃ�NULL�ł��܂��܂���B
	*
	* �y�I�[�o���C�h�z
	* 	 AfxGetAppName() �̌��ʂƁA���ݕҏW���Ă���t�@�C��������
	* 	��������쐬���܂��B
	*
	*	(��) "document.ext - ApplicationName"
	*/
	virtual void MainwndTitlebarStrGet( CString* pRString ) ;


// ********************************
//	CHidemdiMainfrm
// ********************************
 public:
	// ********************************
	///@name	����
	// ********************************
	///@{
	bool getIsModifiedSign()  ;
	void setIsModifiedSign( bool value ) ;
	///@}

		
//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------
	DECLARE_DYNAMIC(CHidemdiMainfrm)
public:
	CHidemdiMainfrm();

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CHidemdiMainfrm)
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CHidemdiMainfrm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �R���g���[�� �o�[�p�����o

// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CHidemdiMainfrm)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


} //namespace Hidemdi
} //namespace OuMfc

#endif /*CHidemdiMainfrm_h*/
