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
//	CHidemdiRootDoctmpl.h
// ****************************************************************
*/
/** @file */
#ifndef  crootdoctemplate_h
#define  crootdoctemplate_h

#include <afxwin.h>

namespace OuMfc{
namespace Hidemdi{


// ****************************************************************
//	CHidemdiRootDoctmpl
// ****************************************************************
/** @brief
�y�T�v�z
  Hidemdi �A�v���P�[�V�����ɂ�����A���[�gDoc/View�̃e���v���[�g�ł��B
  ���[�gDoctemplate�́A�A�v���P�[�V�����ɂP�������݂��܂��B
  ���[�gDoctemplate �́A�ȉ��̃I�u�W�F�N�g�𐶐��E�Ǘ������ڂ������܂��B

 - ���[�gDocument(CHidemdiRootDoc�̔h���N���X) 
 
�y�g�����z

  Doc/View���f����MFC�A�v���P�[�V�����ɂ�����A
  ��ʓI��DocTemplate�̎g�����Ɠ����ł��B�A���A
	
<H4>
�iCHidemdiApp::InitInstance() �I�[�o���C�h�̗�i�ꕔ�j�j
</H4>

@code

	{
		CHidemdiRootDoctmpl* pDocTemplate;
		pDocTemplate = new CHidemdiRootDoctmpl(		
			IDR_HIDEMDTYPE,	
			RUNTIME_CLASS(CHidemditestDoc));
		AddDocTemplate(pDocTemplate);
		RegisterRootDoctmpl( pDocTemplate ) ;
	}

		�F
		�i�����j
		�F

	// ���C�� MDI �t���[�� �E�B���h�E���쐬
	CMainFrame* pMainFrame = new CMainFrame;

	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

@endcode

*/
class CHidemdiRootDoctmpl : public CMultiDocTemplate
{
// ********************************
//	�]���^
// ********************************
 public:
	typedef CMultiDocTemplate	super ;

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 *	�����́ACMultiDocTemplate �Ɠ����ł��B
	 *
	 * @param nIDResource [in]
	 *	 �h�L�������g�^�Ŏg�����\�[�X�� ID ���w�肵�܂��B
	 *	���j���[�A�A�C�R���A�A�N�Z�����[�^ �e�[�u���A�����񃊃\�[�X��
	 *	�w��ł��܂��B
	 * @param pDocClass [in]
	 *	  ���[�g Document �� RUNTIME_CLASS ���w�肵�Ă��������B
	 */
	CHidemdiRootDoctmpl( UINT nIDResource
				, CRuntimeClass* pDocClass ) ;
	virtual ~CHidemdiRootDoctmpl() ;

// ********************************
//	CDocTemplate
// ********************************
 public:
	/**
	* �y�I�[�o���C�h�z
	* 	�����̃h�L�������g�����ׂĕ��Ă���A
	* 	�V�����h�L�������g�𐶐����܂��B
	*/
	virtual CDocument* OpenDocumentFile( LPCTSTR lpszPathName
								, BOOL bMakeVisible = TRUE ) ;
	
	/**
	* �y�I�[�o���C�h�z
	* 	���ׂẴT�uDocview��ۑ����Ă���A����Docview��ۑ����܂�
	*/
	virtual BOOL SaveAllModified( );
	
	/**
	* �y�I�[�o���C�h�z
	* 	���ׂẴT�uDocview��CloseAllDocuments�����s���Ă���A
	* 	����Docview����܂�
	*/
	virtual void CloseAllDocuments( BOOL bEndSession );
// ********************************
//	CHidemdiRootDoctmpl
// ********************************
 public:
	/**
	* 	���ׂẴT�uDocview��ۑ����܂�
	* @return
	* 	���ׂẴT�uDocview����铮�삪����I��������^�A
	* 	�������r���ŃL�����Z�����ꂽ��U��Ԃ��܂��B
	*/
	virtual BOOL SaveAllModifiedSubDocviews( );
	
	/**
	* 	���ׂẴT�uDocview����܂�
	*/
	virtual void CloseAllSubDocuviews( BOOL bEndSession );

};

/**
 *	CView::OnUpdate()�� lHint �����Ɏw�肷�邱�Ƃ̂ł���l�ł��B
 *
 *	�T�uView�ɑ΂��āA�u�ҏW���̃f�[�^�����[�gDocument�ɔ��f����v
 *	���Ƃ��w�����܂��B
 *
 *  �ȉ��̊֐��� lHint �ɁA���̒l���w�肷�邱�Ƃ��ł��܂��B
 *
 *	- void CHidemdiRootDoc::UpdateAllSubDocviews( 
 *		CView* pSender , LPARAM lHint = 0L , CObject* pHint = NULL );
 *	- void CHidemdiRootDoctmpl::UpdateAllSubDocviews( CView* pSender
 *		, LPARAM lHint = 0L, CObject* pHint = NULL );
 *	- void CHidemdiSubDoc::UpdateAllViews(CView* pSender, 
 *		LPARAM lHint = 0L, CObject* pHint = NULL );
 *
 *  ��L�֐��Ŏw�肵�����̒l�́A�ŏI�I��
 *	�T�uView�� lHint �Ɏw�肳��܂��B
 *
 *	- void CView::OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint );
 */
const LPARAM LHINT_SUBVIEW_TO_ROOTDOC = -1 ;

} //namespace Hidemdi
} //namespace OuMfc

#endif /*crootdoctemplate_h*/

