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
// CHidemdiSubDoc.cpp : �C���v�������e�[�V���� �t�@�C��
//
/** @file */

#include "CHidemdiSubDoc.h"
#include "CHidemdiRootDoctmpl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace OuMfc{
namespace Hidemdi{


/////////////////////////////////////////////////////////////////////////////
// CHidemdiSubDoc
// ********************************
//	CHidemdiSubDoc
// ********************************
CString	CHidemdiSubDoc::DocStr() 
		//	�h�L�������g�������Ԃ��܂�
{
	return ( m_strDocStr ) ;
}
//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------
IMPLEMENT_DYNCREATE(CHidemdiSubDoc, CDocument)

CHidemdiSubDoc::CHidemdiSubDoc()
{
}

/**
 *	�h�L�������g������i���[�gDocument���ŁA���̃T�uDoc/View��
 *	�ҏW���镔������肷�邽�߂̕�����j
 *	���󕶎���ɂ��܂��B
 */	
BOOL CHidemdiSubDoc::OnNewDocument()
{
	if (!super::OnNewDocument())
		return FALSE;
	
	m_strDocStr.Empty() ;
	
	return TRUE;
}

CHidemdiSubDoc::~CHidemdiSubDoc()
{
}


BEGIN_MESSAGE_MAP(CHidemdiSubDoc, CHidemdiSubDoc::super)
	//{{AFX_MSG_MAP(CHidemdiSubDoc)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHidemdiSubDoc �f�f

#ifdef _DEBUG
void CHidemdiSubDoc::AssertValid() const
{
	super::AssertValid();
}

void CHidemdiSubDoc::Dump(CDumpContext& dc) const
{
	super::Dump(dc);
}
#endif //_DEBUG


	//[Attention]
	//	Serialize() ���\�b�h�́A���̃N���X�ł�̧�ق�����Ȃ����߁A
	//	���R�s�v�ł��B

/////////////////////////////////////////////////////////////////////////////
// CHidemdiSubDoc �R�}���h

/**
 *	�h�L�������g�̃f�B�X�N �t�@�C���̃t�� �p�X��ݒ肵�܂��B
 *
 *	CMultiDocTemplate::OpenDocumentFile() ����Ăяo����܂��B
 * @param lpszPathName [in]
 *	�h�L�������g�̃p�X�Ƃ��Ďg���镶����ւ̃|�C���^�B
 * @param bAddToMRU [in]
 *	�t�@�C������ MRU (�Ō�Ɏg�p���ꂽ) �t�@�C�� ���X�g�ɒǉ����邩�ǂ��������߂܂��B
 *	TRUE ���w�肷��ƒǉ�����AFALSE ���w�肷��ƒǉ�����܂���B
 *
 * [�I�[�o���C�h]
 *	�t�@�C�����Ƃ��ēn���ꂽ��������A�h�L�������g������Ƃ���
 *	�ۑ����܂��B
 */
void CHidemdiSubDoc::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU) 
{
	m_strDocStr = lpszPathName ;
		//[Attention]
		//	�t�@�C�����Ƃ��ēn���ꂽ��������A�h�L�������g������Ƃ���
		//	�ۑ����܂�

	SetTitle( lpszPathName ) ;
	//super::SetPathName(lpszPathName, FALSE);
		//[Attention]
		//	����̓t�@�C�����ł͂Ȃ��̂ŁA�t�@�C�����ɓ��������������s��
		//	CDocument::SetPathName() �ɈϏ����Ă͂����܂���B
		//	���ځA�^�C�g���ɃZ�b�g���܂��B
}


/**
 *	�h�L�������g�̃f�B�X�N �t�@�C���̃t�� �p�X��ݒ肵�܂��B
 *
 *	CMultiDocTemplate::OpenDocumentFile() ����Ăяo����܂��B
 * @param lpszPathName [in]
 *	�h�L�������g�̃p�X�Ƃ��Ďg���镶����ւ̃|�C���^�B
 *
 * [�I�[�o���C�h]
 *	�t�@�C�����Ƃ��ēn���ꂽ��������A�h�L�������g������Ƃ���
 *	�ۑ����܂��B
 */
BOOL CHidemdiSubDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	//if (!super::OnOpenDocument(lpszPathName))
	//	return FALSE;
		//[Attention]
		//	���̃N���X�ł�̧�ق�����Ȃ��̂ŁASerialize() ������
		//	��{�N���X�ďo�͍s���܂���B
	
	m_strDocStr = lpszPathName ;
		//[Attention]
		//	�t�@�C�����Ƃ��ēn���ꂽ��������A�h�L�������g������Ƃ���
		//	�ۑ����܂�

	return TRUE;
}

BOOL CHidemdiSubDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	//return CHidemdiSubDoc::super::OnSaveDocument(lpszPathName);
		//[Attention]
		//	���̃N���X�ł�̧�ق�����Ȃ��̂ŁASerialize() ������
		//	��{�N���X�ďo�͍s���܂���B
	
	return ( TRUE ) ;
}

/**
 *	���ׂẴr���[�ɑ΂��āAlHint�� LHINT_SUBVIEW_TO_ROOTDOC 
 *	(�r���[�̓��e���h�L�������g�ɔ��f����w��)�ɂ��āA
 *	OnUpdate()���Ăяo���܂��B�R���g���[���i�q�E�C���h�E�j
 *	�����r���[�ł́A���̂Ƃ��ɃR���g���[���̓��͓��e
 *	��ǂ݂Ƃ��āA��������[�g�h�L�������g�ɔ��f���܂�
 */
BOOL CHidemdiSubDoc::SaveModified() 
{
	UpdateAllViews( NULL , LHINT_SUBVIEW_TO_ROOTDOC , NULL ) ;
	
	return super::SaveModified();
}

void CHidemdiSubDoc::OnFileSave() 
{
	AfxGetApp()->OnCmdMsg( ID_FILE_SAVE , 0 , NULL , NULL ) ;
		//[Attention]
		//	�A�v���P�[�V�����N���X�ɈϏ����܂�
}

void CHidemdiSubDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	pCmdUI->DoUpdate( AfxGetApp() , FALSE ) ;
		//[Attention]
		//	�A�v���P�[�V�����N���X�ɈϏ����܂�
}

void CHidemdiSubDoc::OnFileSaveAs() 
{
	AfxGetApp()->OnCmdMsg( ID_FILE_SAVE_AS , 0 , NULL , NULL ) ;
		//[Attention]
		//	�A�v���P�[�V�����N���X�ɈϏ����܂�
	
}

void CHidemdiSubDoc::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	pCmdUI->DoUpdate( AfxGetApp() , FALSE ) ;
		//[Attention]
		//	�A�v���P�[�V�����N���X�ɈϏ����܂�
}


} //namespace Hidemdi
} //namespace OuMfc

