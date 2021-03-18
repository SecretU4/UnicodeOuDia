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
//	CHidemdiRootDoc.h
// ****************************************************************
*/
/** @file */
#ifndef  CHidemdiRootDoc_h
#define  CHidemdiRootDoc_h

#include <afxwin.h>

namespace OuMfc{
namespace Hidemdi{


// ****************************************************************
//	CHidemdiRootDoc
// ****************************************************************
/** @brief
* �y�T�v�z
*   Hidemdi �̃��[�gDoc/View�̃h�L�������g�N���X�ł��B
*   �p�����āA�h�L�������g�f�[�^�S�̂̃f�[�^�̕ێ����ł���悤�ȃf�[�^�����o��
* �ǉ����Ă��������B
*   �܂��A�ȉ��̊֐����I�[�o���C�h���Ă��������B
*
*  -	virtual BOOL OnNewDocument();
*  -	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
*  -	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
*  -	virtual void DeleteContents();
*/
class CHidemdiRootDoc : public CDocument
{
// ********************************
//	�]���^
// ********************************
 public:
	typedef CDocument	super ;


// ********************************
//	CHidemdiRootDoc
// ********************************
 public:
	/**
	* 	���ׂẴT�uDocview�ɑ΂��āAUpdateAllViews()�����s���܂�
	* @param pSender
	* 	�h�L�������g��ύX�����r���[�ւ̃|�C���^�B
	* ���ׂẴr���[���X�V����Ƃ��ɂ� NULL ���w�肵�܂��B
	* @param lHint
	* 	�ύX�Ɋւ�������w�肵�܂��B
	* 	�������A LHINT_SUBVIEW_TO_ROOTDOC ���w�肳�ꂽ�ꍇ�́A���ׂĂ�Docview�ɑ΂��āA
	* 	���e�����[�g�h�L�������g�ɔ��f���A�K�v�Ȃ�΃��[�gDoc�ɑ΂���
	* 	SetModifiedFlag()�����s�����܂��B
	* @param pHint
	* 	�ύX�Ɋւ����񂪊i�[����Ă���I�u�W�F�N�g�ւ̃|�C���^�B
	*/
	virtual void UpdateAllSubDocviews( CView* pSender , LPARAM lHint = 0L , CObject* pHint = NULL );

//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------
protected: // �V���A���C�Y�@�\�݂̂���쐬���܂��B
	CHidemdiRootDoc();
	DECLARE_DYNCREATE(CHidemdiRootDoc)

public:
	//{{AFX_VIRTUAL(CHidemdiRootDoc)
	public:
	virtual void SetTitle(LPCTSTR lpszTitle);
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL


public:
	virtual ~CHidemdiRootDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//{{AFX_MSG(CHidemdiRootDoc)
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileClose();
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSaveAs(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

} //namespace Hidemdi
} //namespace OuMfc


#endif /*CHidemdiRootDoc_h*/
