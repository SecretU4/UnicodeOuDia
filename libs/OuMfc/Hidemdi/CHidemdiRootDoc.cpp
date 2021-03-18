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
//	CHidemdiRootDoc.cpp
// ****************************************************************
*/

#include "CHidemdiRootDoc.h"
#include "CHidemdiApp.h"

namespace OuMfc{
namespace Hidemdi{


// ****************************************************************
//	CHidemdiRootDoc
// ****************************************************************
// ********************************
//	CHidemdiRootDoc
// ********************************
void CHidemdiRootDoc::UpdateAllSubDocviews( CView* pSender	
								, LPARAM lHint , CObject* pHint )
		//	���ׂẴT�uDocview�ɑ΂��āAUpdateAllViews()�����s���܂�
		//pSender
		//	�h�L�������g��ύX�����r���[�ւ̃|�C���^�B
		//���ׂẴr���[���X�V����Ƃ��ɂ� NULL ���w�肵�܂��B
		//lHint
		//	�ύX�Ɋւ�������w�肵�܂��B
		//	�������A LHINT_SUBVIEW_TO_ROOTDOC ���w�肳�ꂽ�ꍇ�́A
		//	���ׂĂ�Docview�ɑ΂��āA
		//	���e�����[�g�h�L�������g�ɔ��f���A�K�v�Ȃ�΃��[�gDoc�ɑ΂���
		//	SetModifiedFlag()�����s�����܂��B
		//pHint
		//	�ύX�Ɋւ����񂪊i�[����Ă���I�u�W�F�N�g�ւ̃|�C���^�B
{
	POSITION	LPosition = AfxGetApp()->GetFirstDocTemplatePosition() ;

	//	���ׂẴT�uDocView�ւ́AUpdateAllViews() �Ăяo��
	while( LPosition != NULL ){
		CDocTemplate*	pLDocTemplate = AfxGetApp()
						->GetNextDocTemplate( LPosition ) ;
		if ( pLDocTemplate != GetDocTemplate() ){
			POSITION	LPosition = pLDocTemplate->GetFirstDocPosition() ;
			while( LPosition != NULL ){
				CDocument*	pLDocument = 
					pLDocTemplate->GetNextDoc( LPosition ) ;
				pLDocument->UpdateAllViews( pSender	, lHint , pHint ) ;
			}
		}
	}
}

//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------
IMPLEMENT_DYNCREATE(CHidemdiRootDoc, CDocument)

BEGIN_MESSAGE_MAP(CHidemdiRootDoc, CHidemdiRootDoc::super)
	//{{AFX_MSG_MAP(CHidemdiRootDoc)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CHidemdiRootDoc::CHidemdiRootDoc()
{

}

CHidemdiRootDoc::~CHidemdiRootDoc()
{
}

#ifdef _DEBUG
void CHidemdiRootDoc::AssertValid() const
{
	super::AssertValid();
}

void CHidemdiRootDoc::Dump(CDumpContext& dc) const
{
	super::Dump(dc);
}
#endif //_DEBUG

BOOL CHidemdiRootDoc::SaveModified() 
	//	SaveAllModifiedSubDocviews�i�j
	//	�i���ׂẴT�uDocview�ɑ΂���SaveModofied�����s����j
	//	�����s���Ă���A�������g��SaveModified�����s���܂�)
{
	BOOL	bRv = TRUE ;
	bRv = ((CHidemdiApp*)AfxGetApp())->pRootDoctmpl()
									->SaveAllModifiedSubDocviews() ;
	if ( bRv ){
		bRv = super::SaveModified();
	}
	return ( bRv ) ;
}




void CHidemdiRootDoc::SetTitle(LPCTSTR lpszTitle) 
{
	//[Attention]
	//	�h�L�������g�𖼑O�����ĕۑ������ꍇ�Ȃǂ́A
	//	������ OnUpdateFrameTitle() ���Ăяo���Ȃ��ƁA
	//	���C���t���[���E�C���h�E�̃^�C�g���o�[���ς��܂���B
	super::SetTitle(lpszTitle);
	( (CFrameWnd*)AfxGetMainWnd() )->OnUpdateFrameTitle( TRUE ) ;
}

void CHidemdiRootDoc::OnFileSave() 
{
	BOOL	bRv = TRUE ;

	//[Attention]
	//	���̃R�}���h���b�Z�[�W�̏ꍇ�́A�����I�ɂ�
	//	SaveModified()���Ă΂�܂���̂ŁA�����I��
	//	SaveAllModifiedSubDocviews�i�j
	//	�i���ׂẴT�uDocview�ɑ΂���SaveModofied�����s����j
	//	�����s���Ă���A�������g�̏��������s���܂�
	bRv = ((CHidemdiApp*)AfxGetApp())->pRootDoctmpl()
								->SaveAllModifiedSubDocviews() ;

	if ( bRv ){
		super::OnFileSave() ;
	}

}

void CHidemdiRootDoc::OnFileSaveAs() 
{
	BOOL	bRv = TRUE ;

	//[Attention]
	//	���̃R�}���h���b�Z�[�W�̏ꍇ�́A�����I�ɂ�
	//	SaveModified()���Ă΂�܂���̂ŁA�����I��
	//	SaveAllModifiedSubDocviews�i�j
	//	�i���ׂẴT�uDocview�ɑ΂���SaveModofied�����s����j
	//	�����s���Ă���A�������g�̏��������s���܂�
	bRv = ((CHidemdiApp*)AfxGetApp())->pRootDoctmpl()
								->SaveAllModifiedSubDocviews() ;

	if ( bRv ){
		super::OnFileSaveAs() ;
	}
}


void CHidemdiRootDoc::OnFileClose() 
{
	//attention
	// RootDoc �ɑ΂��� ID_FILE_CLOSE �́A
	//	�������Ă͂����܂���
	//	�i���[�g�h�L�������g���O�ɂȂ��Ă��܂��܂��B
	//	Hidemdi �A�v���P�[�V�����́A��ɂP��
	//	���[�g�h�L�������g�I�u�W�F�N�g�������Ȃ��Ă͂Ȃ�܂���)
	//	
	//	RootDoc �̃��j���[�����
	//	 FILE_CLOSE ���폜���Ȃ��Ă͂Ȃ�܂���B
	ASSERT( 0 ) ;
	//CHidemdiRootDoc::super::OnFileClose();
}


void CHidemdiRootDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( ((CHidemdiApp*)AfxGetApp())->pRootDoc()->IsModified() ) ;
}

void CHidemdiRootDoc::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( ((CHidemdiApp*)AfxGetApp())->pRootDoc()->IsModified() ) ;
}

} //namespace Hidemdi
} //namespace OuMfc

