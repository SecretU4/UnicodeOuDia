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
#if !defined(AFX_CDLGROSENFILEPROP_FONTCOLOR_H__25C7879F_3AA8_41A9_9B19_3A1AFBB4F97E__INCLUDED_)
#define AFX_CDLGROSENFILEPROP_FONTCOLOR_H__25C7879F_3AA8_41A9_9B19_3A1AFBB4F97E__INCLUDED_
// CDlgRosenFileProp_FontColor.h : �w�b�_�[ �t�@�C��
//	$Id: CDlgRosenFileProp_FontColor.h 179 2014-05-05 13:50:33Z okm $
//
/** @file */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DcDraw/CDcdTextbox.h"
#include "DcDraw/CDcdRectangle.h"
#include "DcDraw/CDcdTextboxV3.h"

namespace ViewRosen{
	using namespace DcDrawLib ;	

class CDlgRosenFileProp ;

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp_FontColor �_�C�A���O

/**
  @brief
 	�w�H���t�@�C���̃v���p�e�B�x�_�C�A���O��
 	�w�t�H���g�E�F�x�y�[�W����������A���[�h���X�_�C�A���O�ł��B
*/
class CDlgRosenFileProp_FontColor : public CDialog
{
private:
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
	 	�t�H���g�B
	 	�K��l�́A	CdFontProp( 9 ,"�l�r �S�V�b�N"  ) �B

		- 0�`CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT	�����\��ʃt�H���g
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+0 �����\��ʁE�c�����t�H���g
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+1	�_�C����ʉw���t�H���g�B
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+2 �_�C����ʎ����t�H���g�B
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+3 �_�C����ʗ�ԃt�H���g�B
		- CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+4 �R�����g�r���[�t�H���g�B
	 */
	CdFontProp	m_arFontProp[entDed::CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+5] ;


	/**
	 	�_�C����ʕ����F�B
	 	�K��l�́A���B

		- 0	�_�C����ʕ����F�B
		- 1	�_�C����ʏc�����F�B
	*/
	COLORREF	m_arColor[2] ;
	///@}

private:
	// --------------------------------
	//	�����f�[�^
	// --------------------------------
	/**
	 	�t�H���g�̃T���v����`�悷�� DcDraw �I�u�W�F�N�g
	 	OnInitDialog() �Ő����EOnDestroy() �Ŕj�����܂��B
	*/
	CDcdTextbox*	m_pdcdrawFont ;

	/**
	 	�t�H���g�̃T���v����`�悷�� DcDraw �I�u�W�F�N�g
	 	OnInitDialog() �Ő����EOnDestroy() �Ŕj�����܂��B
	*/
	DcDraw::CDcdTextboxV3*	m_pdcdrawFontV ;

	/**
	 	�F�̃T���v����`�悷�� DcDraw �I�u�W�F�N�g
	 	OnInitDialog() �Ő����EOnDestroy() �Ŕj�����܂��B
	*/
	CDcdRectangle*	m_pdcdrawColor ;
protected:
	// --------------------------------
	//	�����֐�
	// --------------------------------
	CDlgRosenFileProp* GetParent() ;
	/**
	 	UI�̏�Ԃ��X�V����(��:�R���g���[���̗L���E�����A���͒l�̐��K��)
	 */
	virtual void updateUIState() ;

	/**
	@return 
		���X�g�R���g���[���ŏc�����t�H���g���I������Ă����� true �ł��B
	*/
	bool VerticalFontIsChoosed() ;

 public:
	// ********************************
	//	CDlgRosenFileProp_FontColor
	// ********************************
	/**
		�ҏW�Ώۃf�[�^��UI�ɔ��f���� 
	*/
	void updateUI() ;

	/**
�@�@�@	UI�̌��݂̓��͓��e���擾���A�ҏW�Ώۃf�[�^�ɔ��f������
	@return 
	 	����������  0 �ȏ�A�G���[�Ȃ畉�̐��ł��B

		-	-1 ;	�G���[���������A���b�Z�[�W�{�b�N�X���\������܂����B
	*/
	int updatePropEditorData();


// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// �R���X�g���N�V����
public:
	CDlgRosenFileProp_FontColor(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgRosenFileProp_FontColor)
	enum { IDD = IDD_RosenFileProp_FontColor };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgRosenFileProp_FontColor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgRosenFileProp_FontColor)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeListFont();
	afx_msg void OnSelchangeListColor();
	afx_msg void OnButtonFontChange();
	afx_msg void OnButtonColorChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace ViewRosen

#endif // !defined(AFX_CDLGROSENFILEPROP_FONTCOLOR_H__25C7879F_3AA8_41A9_9B19_3A1AFBB4F97E__INCLUDED_)
