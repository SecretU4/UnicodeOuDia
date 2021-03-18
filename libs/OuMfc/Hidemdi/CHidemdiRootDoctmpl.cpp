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
//	CHidemdiRootDoctmpl.cpp
// ****************************************************************
*/

#include "CHidemdiRootDoctmpl.h"
#include "CHidemdiRootFrame.h"
#include "CHidemdiRootView.h"
#include "CHidemdiApp.h" 

namespace OuMfc{
namespace Hidemdi{


// ****************************************************************
//	CHidemdiCSubdoctemplate
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CHidemdiRootDoctmpl::CHidemdiRootDoctmpl( UINT nIDResource
				, CRuntimeClass* pDocClass ) : 
	super( nIDResource , 
		pDocClass , 
		RUNTIME_CLASS(CHidemdiRootFrame) , 
		RUNTIME_CLASS(CHidemdiRootView) ) 
{
}
CHidemdiRootDoctmpl::~CHidemdiRootDoctmpl() 
{
}

// ********************************
//	CDocTemplate
// ********************************
CDocument* CHidemdiRootDoctmpl::OpenDocumentFile( LPCTSTR lpszPathName
								, BOOL bMakeVisible ) 
		//�y�I�[�o���C�h�z
		//	�����̃h�L�������g�����ׂĕ��Ă���A
		//	�V�����h�L�������g�𐶐����܂��B
{

	CDocument*	pRv = NULL ;
	BOOL	bLSaveIsContinued = TRUE ;

	//--------------------------------
	//	���[�g�h�L�������g��ۑ�
	//--------------------------------
	if ( bLSaveIsContinued ){
		bLSaveIsContinued = super::SaveAllModified() ;
			//bLSaveIsContinued = ���[�g�h�L�������g�̕ۑ���
			//	�L�����Z�����ꂽ��U�ł�
	}
	if ( bLSaveIsContinued )
	{
		//--------------------------------
		//	���ׂẴT�u�h�L�������g�����
		//--------------------------------
		CloseAllSubDocuviews( FALSE ) ;

		//--------------------------------
		//	���[�g�h�L�������g���Ȃ��Ȃ琶��
		//	����Ȃ�A�����̗v�f��j��
		//--------------------------------
		CDocument*	pDocument = ((CHidemdiApp*)AfxGetApp())->pRootDoc() ;
		if ( pDocument == NULL )
		{
			//	���[�gDocument���Ȃ��Ȃ琶��
			pDocument = CreateNewDocument();

		}	else	{
			pDocument->DeleteContents() ;
		}

		//--------------------------------
		//	�t�@�C�������w�肳��Ă�����A
		//	�t�@�C�����J��
		//--------------------------------
		if (lpszPathName == NULL)
		{
			// create a new document - with default document name
			SetDefaultTitle(pDocument);

			// avoid creating temporary compound file when starting up invisible
			if (!bMakeVisible)
				pDocument->m_bEmbedded = TRUE;

			if (!pDocument->OnNewDocument())
			{
				// user has be alerted to what failed in OnNewDocument
				TRACE0("CDocument::OnNewDocument returned FALSE.\n");
				//pFrame->DestroyWindow();
				return NULL;
			}

			// it worked, now bump untitled count
			m_nUntitledCount++;
		}
		else
		{
			// open an existing document
			CWaitCursor wait;
			if (!pDocument->OnOpenDocument(lpszPathName))
			{
				// user has be alerted to what failed in OnOpenDocument
				TRACE0("CDocument::OnOpenDocument returned FALSE.\n");
				//pFrame->DestroyWindow();
				return NULL;
			}
			pDocument->SetPathName(lpszPathName);
		}
		pRv = pDocument ;
	}

	return ( pRv ) ;
};
/*sankou
CDocument* CMultiDocTemplate::OpenDocumentFile(LPCTSTR lpszPathName,
	BOOL bMakeVisible)
{
	CDocument* pDocument = CreateNewDocument();
	if (pDocument == NULL)
	{
		TRACE0("CDocTemplate::CreateNewDocument returned NULL.\n");
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
		return NULL;
	}
	ASSERT_VALID(pDocument);

	BOOL bAutoDelete = pDocument->m_bAutoDelete;
	pDocument->m_bAutoDelete = FALSE;   // don't destroy if something goes wrong
	CFrameWnd* pFrame = CreateNewFrame(pDocument, NULL);
	pDocument->m_bAutoDelete = bAutoDelete;
	if (pFrame == NULL)
	{
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
		delete pDocument;       // explicit delete on error
		return NULL;
	}
	ASSERT_VALID(pFrame);

	if (lpszPathName == NULL)
	{
		// create a new document - with default document name
		SetDefaultTitle(pDocument);

		// avoid creating temporary compound file when starting up invisible
		if (!bMakeVisible)
			pDocument->m_bEmbedded = TRUE;

		if (!pDocument->OnNewDocument())
		{
			// user has be alerted to what failed in OnNewDocument
			TRACE0("CDocument::OnNewDocument returned FALSE.\n");
			pFrame->DestroyWindow();
			return NULL;
		}

		// it worked, now bump untitled count
		m_nUntitledCount++;
	}
	else
	{
		// open an existing document
		CWaitCursor wait;
		if (!pDocument->OnOpenDocument(lpszPathName))
		{
			// user has be alerted to what failed in OnOpenDocument
			TRACE0("CDocument::OnOpenDocument returned FALSE.\n");
			pFrame->DestroyWindow();
			return NULL;
		}
		pDocument->SetPathName(lpszPathName);
	}

	InitialUpdateFrame(pFrame, pDocument, bMakeVisible);
	return pDocument;
}

*/

BOOL CHidemdiRootDoctmpl::SaveAllModified( )
		//�y�I�[�o���C�h�z
		//	���ׂẴT�uDocview��ۑ����Ă���A����Docview��ۑ����܂�
{
	BOOL	bLSaveIsContinued = TRUE ;
	if ( bLSaveIsContinued ){
		bLSaveIsContinued = super::SaveAllModified() ;
	}
	return ( bLSaveIsContinued ) ;
}
	
void CHidemdiRootDoctmpl::CloseAllDocuments( BOOL bEndSession )
{
		//�y�I�[�o���C�h�z
		//	���ׂẴT�uDocview��CloseAllDocuments�����s���Ă���A
		//	����Docview����܂�
	CloseAllSubDocuviews( bEndSession ) ;
	super::CloseAllDocuments( bEndSession ) ;
}
// ********************************
//	CHidemdiRootDoctmpl
// ********************************
BOOL CHidemdiRootDoctmpl::SaveAllModifiedSubDocviews( )
{
	BOOL	bLSaveIsContinued = TRUE ;

	POSITION	LPosition = AfxGetApp()->GetFirstDocTemplatePosition() ;
	while( LPosition != NULL && bLSaveIsContinued ){
		CDocTemplate*	pLDocTemplate = AfxGetApp()
							->GetNextDocTemplate( LPosition ) ;

		if ( pLDocTemplate != this ){
			bLSaveIsContinued = pLDocTemplate->SaveAllModified() ;
				//bLSaveIsContinued = �T�u�h�L�������g�̕ۑ���
				//	�L�����Z�����ꂽ��U�ł�
		}
	}

	return ( bLSaveIsContinued ) ;
}

void CHidemdiRootDoctmpl::CloseAllSubDocuviews( BOOL bEndSession )
		//	���ׂẴT�uDocview����܂�
{

	POSITION	LPosition = AfxGetApp()->GetFirstDocTemplatePosition() ;
	while( LPosition != NULL ){
		CDocTemplate*	pLDocTemplate = AfxGetApp()
						->GetNextDocTemplate( LPosition ) ;

		if ( pLDocTemplate != this ){
			pLDocTemplate->CloseAllDocuments( bEndSession ) ;
		}
	}
}

} //namespace Hidemdi
} //namespace OuMfc

