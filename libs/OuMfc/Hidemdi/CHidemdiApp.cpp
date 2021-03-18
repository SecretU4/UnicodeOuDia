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
//	CHidemdiApp.cpp
// ****************************************************************
*/

#include <afxadv.h>
#include "CHidemdiApp.h"

namespace OuMfc{
namespace Hidemdi{


// ****************************************************************
//	CHidemdiApp
// ****************************************************************
//--------------------------------
//	�����֐�
//--------------------------------
BOOL CHidemdiApp::RegisterRootDoctmpl
						( CHidemdiRootDoctmpl* prootdoctemplateEv ) 
		//[Attention]
		//	InitInstance() ��Doctemplate�𐶐������Ƃ��ɁA
		//	���[�gDoctemplate�I�u�W�F�N�g�̃|�C���^���A���̃��\�b�h��
		//	�o�^���Ă��������B
{
	m_pdoctemplateRoot = prootdoctemplateEv ;
	return ( TRUE ) ;
}


CHidemdiRootDoctmpl*	CHidemdiApp::pRootDoctmpl() 
		//	���[�gDoc/View�̃e���v���[�g�ւ�
		//	�|�C���^��Ԃ��܂�
{
	return ( m_pdoctemplateRoot ) ;
}

CHidemdiRootDoc* CHidemdiApp::pRootDoc() 
		//	���[�gDoc�ւ̃|�C���^��Ԃ��܂�
{
	CDocument*	pRv = NULL ;
	if ( m_pdoctemplateRoot != NULL ){
		POSITION	LPosition = m_pdoctemplateRoot->GetFirstDocPosition() ;
		while( LPosition != NULL ){
			pRv = m_pdoctemplateRoot->GetNextDoc( LPosition ) ;
		}
	}
	//ASSERT( pRv != NULL ) ;
	return ( (CHidemdiRootDoc*)pRv ) ;
}

int CHidemdiApp::RemoveFromRecentFileList( LPCTSTR lpszEFilename ) 
		//	�t�@�C�������AMRU���X�g����폜���܂�
		//lpszEFilename
		//	�폜����t�@�C������Ԃ��܂�
		//[r]
		//	�폜�����G���g���̐���Ԃ��܂�
{
	int	iRv = 0 ;
	if ( m_pRecentFileList != NULL ){
		int	iLIdx ;
		for ( iLIdx = 0 ; iLIdx < m_pRecentFileList->GetSize() ; iLIdx ++ ){
			if ( (*m_pRecentFileList)[iLIdx] == lpszEFilename ){
				m_pRecentFileList->Remove( iLIdx ) ;
				iLIdx -- ;
				iRv ++ ;
			}
		}
	}
	return ( iRv ) ;
}

//----------------------------------------------------------------
//	MFC
//----------------------------------------------------------------

BEGIN_MESSAGE_MAP(CHidemdiApp, CHidemdiApp::super)
	//{{AFX_MSG_MAP(CHidemdiApp)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CHidemdiApp::CHidemdiApp()
{
	m_pdoctemplateRoot = NULL ;
		//[Attention]
		//	InitInstance() ��CDocTemplate��o�^����Ƃ��ɁA
		//	���[�gDoc/View�̃e���v���[�g�ւ�
		//	�|�C���^��ێ����Ă��������B
}

BOOL CHidemdiApp::InitInstance()
{
	return ( TRUE ) ;
}


void CHidemdiApp::OnFileNew() 
{
	m_pdoctemplateRoot->OpenDocumentFile( NULL ) ;
}

void CHidemdiApp::OnFileSave() 
{
	CHidemdiRootDoc*	pLRootDoc = pRootDoc() ;
	if ( pLRootDoc != NULL ){
		pLRootDoc->OnCmdMsg( ID_FILE_SAVE , 0 , NULL , NULL ) ;
	}
	
}

void CHidemdiApp::OnFileSaveAs() 
{
	CHidemdiRootDoc*	pLRootDoc = pRootDoc() ;
	if ( pLRootDoc != NULL ){
		pLRootDoc->OnCmdMsg( ID_FILE_SAVE_AS , 0 , NULL , NULL ) ;
	}
			//[Attention]
			//	�R�}���h�n���h���𑼂̃R�}���h�^�[�Q�b�g��
			//	�Ϗ��������ꍇ�́A�Ϗ���I�u�W�F�N�g�ɑ΂��āA
			//	CCmdTarget::OnCmdMsg() ���Ăяo���Ă��������B
			//
			//virtual BOOL CCmdTarget::OnCmdMsg( UINT nID
			//	, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo );
			//[r]
			//���b�Z�[�W���������ꂽ�Ƃ��� 0 �ȊO��Ԃ��܂��B����ȊO�� 0 ��
			//	�Ԃ��܂��B
			//nID
			//   �R�}���h ID ���w�肵�Ă��������B
			//nCode
			//	0���w�肵�Ă��������B
			//pExtra
			//	NULL���w�肵�Ă��������B
			//pHandlerInfo 
			//	NULL���w�肵�Ă��������B
}

void CHidemdiApp::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	CHidemdiRootDoc*	pLRootDoc = pRootDoc() ;
	if ( pLRootDoc != NULL ){
		pCmdUI->DoUpdate( pLRootDoc , FALSE ) ;
			//[Attention]
			//	�㏑���ۑ��E���O�����ĕۑ��̃R�}���h�́A���[�g�h�L�������g��
			//	�Ϗ����܂�

			//[Attention]
			//	�R�}���h��OnUpdate...()�����𑼂̃R�}���h�^�[�Q�b�g��
			//	�Ϗ��������ꍇ�́ACCmdUi::DoUpdate() ���Ăяo���Ă��������B
			//
			//BOOL CCmdUI::DoUpdate(CCmdTarget* pTarget
			//					, BOOL bDisableIfNoHndler)
			//	  �R�}���h��OnUpdate...()���\�b�h���A
			//	�w���CCmdTarget�I�u�W�F�N�g�ɑ΂��ČĂяo���܂��B
			//pTarget
			//	  OnUpdate...()���\�b�h���Ăяo��
			//	CCmdTarget�I�u�W�F�N�g���w�肵�Ă��������B
			//bDisableIfNoHndler
			//	�^�Ȃ�A�ďo��̃R�}���h��OnUpdate...()���\�b�h���Ȃ��ꍇ�ɁA
			//	���̃R�}���h���֎~��ԂƂȂ�܂��B
	}
}

void CHidemdiApp::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	CHidemdiRootDoc*	pLRootDoc = pRootDoc() ;
	if ( pLRootDoc != NULL ){
		pCmdUI->DoUpdate( pLRootDoc , FALSE ) ;
	}
}


BOOL CHidemdiApp::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	CHidemdiRootDoc* pCHidemdiRootDoc = pRootDoc() ;

	if ( pCHidemdiRootDoc != NULL )
	{
		if ( pCHidemdiRootDoc->OnCmdMsg( nID , nCode , pExtra , pHandlerInfo ) )
		{
			return TRUE ;
		}
	}

	return CWinApp::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

} //namespace Hidemdi
} //namespace OuMfc

