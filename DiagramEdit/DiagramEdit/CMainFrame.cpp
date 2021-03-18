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
// CMainFrame.cpp : CMainFrame �N���X�̓���̒�`���s���܂��B
//	$Id: CMainFrame.cpp 295 2016-06-11 05:14:13Z okm $
/** @file */

#include "stdafx.h"

#include "NsOu/OuNew.h"
#include "str/vectorToFile.h"
#include "str/strToWstr.h"
#include "str/tstring.h"
#include "str\OuPropertiesText\ErrorInfo\COuErrorInfoContainer.h"
#include "str\OuPropertiesText\CConvNodeContainer.h"


#include "DiagramEdit.h"
#include "CMainFrame.h"
#include "DedRosenFileData\EditCmd\EditCmd.h"
#include "DedRosenFileData\CconvCDedRosenFileData.h"
#include "ViewRosen\CDlgRosenFileProp.h"
#include "ViewRosen\CDlgDiaList.h"
#include "ViewRosen\CDlgRosenCreateSubRosen.h"
#include "ViewRosen\CDlgRosenfileInsert.h"

using namespace std ;
using namespace OuLib::Str ;
using namespace OuLib::Str::OuPropertiesText ;
using namespace OuLib::Str::OuPropertiesText::ErrorInfo ;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame
// --------------------------------
//	CFrameWnd
// --------------------------------
void CMainFrame::RecalcLayout( BOOL bNotify )
{
	CWndSplitBarV::CMDIFrameWnd_RecalcLayout( this , 
		&m_CDlgRosenView , &m_CWndSplitBarV , bNotify ) ;
}
void CMainFrame::OnSetPreviewMode( BOOL bPreview, CPrintPreviewState* pModeStuff )
{
	m_CDlgRosenView.EnableWindow( !bPreview ) ;
	super::OnSetPreviewMode(  bPreview, pModeStuff ) ;
}
	// --------------------------------
	//@name ���j���[�R�}���h�̉����֐�
	// --------------------------------
//	[�t�@�C��]-[�H���t�@�C���̑g����]
int CMainFrame::OnFileRosenFileInsert_Process( BOOL bQueryEnable ) 
{
	int iRv = 0; 
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	const CDedRosenFileData* pRosenFileDataCurrent = getCDiagramEditDoc()->getCDedRosenFileData() ;
	if ( iRv >= 0 )
	{
		//	�w��2�����Ȃ�A���̃R�}���h�͎g�p�ł��܂���B
		const CentDedEkiCont* pEkiCont = pRosenFileDataCurrent->getCentDedRosen()->getCentDedEkiCont() ;
		if ( pEkiCont->size() < 2 )
		{
			iRv = -21 ;	//	�w��2�����Ȃ�A���̃R�}���h�͎g�p�ł��܂���B
		}
	}

	if ( bQueryEnable || iRv < 0 )
	{
		return iRv ;
	}
	// ****************************************************************
	//	�R�}���h�̎��s
	// ****************************************************************
	CString strErrorMsgSub ;

	//(2)[�H���t�@�C���̑g����]�_�C�A���O
	CString strOudFilename ;
	int iEkiIndexToInsert = -1 ;
	{
		const CentDedEkiCont* pCentDedEkiCont = pRosenFileDataCurrent->getCentDedRosen()->getCentDedEkiCont() ;
		CDlgRosenfileInsert	aDlg( *pCentDedEkiCont , this ) ;
		int iResult = aDlg.DoModal() ;
		if ( iResult != IDOK )
		{
			iRv = -1 ;	//	���[�U�[�ɂ��L�����Z��
		}
		else
		{
			iEkiIndexToInsert = aDlg.getEkiIndexToInsert() ;
			strOudFilename = aDlg.getOudFilenameToInsert() ;
		}
	}
	//strOudFilename = �t�@�C���_�C�A���O�Ŏw�肳�ꂽ .oud �t�@�C����
	//iEkiIndexToInsert = �g�����wIndex
	
	// --------------------------------
	//	.oud�t�@�C����ǂݍ���
	//	CDedRosenFileData �𐶐�
	// --------------------------------
	CDedRosenFileData	rosenfiledataAdd ;
	if ( iRv >= 0 )
	{
		string strFileContent ;
		if ( iRv >= 0 )
		{
			int iResult = stringFromFile( 
				&strFileContent , 
				stringOf( (LPCTSTR)strOudFilename ) ) ;
			if ( iResult < 0 )
			{
				iRv = -11 ;	//	�t�@�C�����݂���܂���B
			}
		}
		if ( iRv >= 0 )
		{
			CconvCDedRosenFileData	aConv ;
			COuErrorInfoContainer	aCOuErrorInfoContainer ;
			int iResult = aConv.CDedRosenFileData_from_string( 
				&rosenfiledataAdd , 
				strFileContent , 
				&aCOuErrorInfoContainer ) ;
			if ( iResult < 0 )
			{
				strErrorMsgSub = aCOuErrorInfoContainer.toOuErrorInfoText().c_str() ;
				iRv = -12 ;	//	�t�@�C���̌`�����s���ł��B
			}
		}
	}
	//rosenfiledataAdd = �ǉ����� .oud �̃f�[�^��ێ����Ă��܂��B

	// --------------------------------
	//	rosenfiledataCurrent �̘H���̖�����
	//	rosenfiledataAdd �̘H����ǉ�
	// --------------------------------
	CDedRosenFileData rosenfiledataCurrent = *getCDiagramEditDoc()->getCDedRosenFileData() ;
	if ( iRv >= 0 )
	{
		CentDedRosen* prosenCurrent = rosenfiledataCurrent.getCentDedRosen() ;
		CentDedRosen* prosenAdd = rosenfiledataAdd.getCentDedRosen() ; 
		prosenCurrent->insert( *prosenAdd , iEkiIndexToInsert ) ;

		Ou< CRfEditCmd > pCmd = OuNew< CRfEditCmd >( new
			CRfEditCmd_Rosen( *prosenCurrent ) ) ;
		getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
	}
	// ****************************************************************
	//	�G���[���b�Z�[�W
	// ****************************************************************
	CString strErrorMsg ;
	if ( iRv < 0 )
	{
		switch( iRv )
		{
		case -1 :	//	�L�����Z��
			break ;
		case -11 :	//	�t�@�C�����݂���܂���B
			strErrorMsg.Format( IDS_ERR_FILENOTFOUND , strOudFilename ) ;
		case -12 :	//	�t�@�C���̌`�����s���ł��B
			strErrorMsg.Format( IDS_ERR_FILEFORMAT , strOudFilename ) ;
		default:
			strErrorMsg.Format( _T( "Error(%d)" ) , iRv ) ;
			break ;
		}
		if ( !strErrorMsgSub.IsEmpty() )
		{

			strErrorMsg += _T( "\n" ) ;
			strErrorMsg += strErrorMsgSub ;
		}
	}
	if ( !strErrorMsg.IsEmpty() )
	{
		MessageBox( strErrorMsg , NULL , MB_ICONSTOP ) ;
	}
	return iRv ;
}

//[�t�@�C��]-[�H���t�@�C���̐؂�o��]
int CMainFrame::OnFileRosenCreateSubRosen_Process( BOOL bQueryEnable ) 
{
	int iRv = 0;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	{
		int iEkiCount = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont()->size() ;
		if ( iEkiCount < 3 )
		{
			iRv = -31 ;	//	3�w�����̘H���ł́A�g�p�ł��܂���B
		}
	}
	if ( bQueryEnable || iRv < 0 )
	{
		return iRv ;
	}
	// ****************************************************************
	//	�R�}���h�̎��s
	// ****************************************************************
	CString strErrorMsgSub ;
	CDedRosenFileData rosenfiledataCurrent = *getCDiagramEditDoc()->getCDedRosenFileData() ;

	//(2)[�ꕔ�w�Ԃ̘H���t�@�C�����쐬]�_�C�A���O
	int iEkiIndex = 0 ;
	int iEkiCount = 0 ;
	if ( iRv >= 0 )
	{
		const CentDedEkiCont& aCentDedEkiCont = *rosenfiledataCurrent.getCentDedRosen()->getCentDedEkiCont() ;
		CDlgRosenCreateSubRosen	aDlg( aCentDedEkiCont , this ) ;
		int iResult = aDlg.DoModal() ;
		if ( iResult != IDOK )
		{
			iRv = -1 ;	//	���[�U�[�ɂ��L�����Z��
		}
		else
		{
			iEkiIndex = aDlg.getSihatsuEkiIndex() ;
			iEkiCount = aDlg.getSyuuchakuEkiIndex() + 1 - iEkiIndex ;
		}
	}
	//iEkiIndex = �V�����H���t�@�C���́A�n���wIndex
	//iEkiCount = �V�����H���t�@�C���̉w��


	//�@���O�����ĕۑ��_�C�A���O
	CString strNewOudFilename ;
	if ( iRv >= 0 )
	{
		CString	strExt ;
		getCDiagramEditApp()->pRootDoctmpl()->GetDocString( strExt , CDocTemplate::filterExt ) ;
		CFileDialog	aDlg( FALSE , strExt , NULL ,
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST,
			getCDiagramEditApp()->getCFileDialogOudFilter() , this ) ;
		int iResult = aDlg.DoModal() ;
		if ( iResult != IDOK )
		{
			iRv = -1 ;	//	���[�U�[�ɂ��L�����Z��
		}
		else
		{
			strNewOudFilename = aDlg.GetPathName() ;
		}
	}
	//strNewOudFilename = �V�����H���t�@�C����

	// --------------------------------
	//	rosenfiledataCurrent �̘H������A
	//	�ꕔ��Ԃ̘H��
	//	rosenfiledataSub �𐶐�
	// --------------------------------
	CDedRosenFileData	rosenfiledataSub ;
	if ( iRv >= 0 )
	{
		rosenfiledataSub = rosenfiledataCurrent ;
		*rosenfiledataSub.getCentDedRosen() = 
			rosenfiledataCurrent.getCentDedRosen()->createSubRosen( iEkiIndex , iEkiCount ) ;
	}
	// --------------------------------
	//	CDedRosenFileData ��
	//	.oud�t�@�C���ɕۑ�
	// --------------------------------
	OuPropertiesText::CNodeContainer	aCNodeContainer ;  
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData aConv ;
		int iResult = aConv.CDedRosenFileData_to_OuPropertiesText( 
			&rosenfiledataSub , 
			&aCNodeContainer ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	�H���f�[�^�̕ϊ��Ɏ��s���܂����B
		}
	}
	// --------------------------------
	//	FileTypeAppComment ��t�^
	// --------------------------------
	if ( iRv >= 0 )
	{
		string strFileTypeAppComment ;
		strFileTypeAppComment += AfxGetAppName() ;
		strFileTypeAppComment += " Ver. " ;
		strFileTypeAppComment += getCDiagramEditApp()->getProgramVer() ;
		aCNodeContainer.setValue( nameFileTypeAppComment , strFileTypeAppComment );
	}
	// --------------------------------
	//	�t�@�C���ɕۑ�
	// --------------------------------
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer aConv ;
		string strOudContent = aConv.encode( &aCNodeContainer ) ;
		int iResult = stringToFile( 
			strOudContent , 
			stringOf( (LPCTSTR)strNewOudFilename ) ) ;
		//iResult 
		//	-1: �t�@�C�����I�[�v���ł��܂���B
		//	-2 ; // �������݂Ɏ��s���܂����B 
		if ( iResult < 0 )
		{
			iRv = iResult - 20 ;
		}
		//iRv
		//	-21: �t�@�C�����I�[�v���ł��܂���B
		//	-22 ; // �������݂Ɏ��s���܂����B 
		
	}
	// ****************************************************************
	//	�G���[���b�Z�[�W
	// ****************************************************************
	CString strErrorMsg ;
	if ( iRv < 0 )
	{
		switch( iRv )
		{
		case -21:	//	�t�@�C�����I�[�v���ł��܂���B
			strErrorMsg.Format( IDS_ERR_FILECREATE , (LPCTSTR)strNewOudFilename ) ;
			break ;
		case -22: // �������݂Ɏ��s���܂����B 
			strErrorMsg.Format( IDS_ERR_FILEWRITE , (LPCTSTR)strNewOudFilename ) ;
			break ;
		case -1: // ���[�U�[�ɂ��L�����Z��
			break ;
		default:
			strErrorMsg.Format( _T( "Error(%d)" ) , iRv ) ;
			break ;
		}
		if ( !strErrorMsgSub.IsEmpty() )
		{

			strErrorMsg += _T( "\n" ) ;
			strErrorMsg += strErrorMsgSub ;
		}
	}
	if ( !strErrorMsg.IsEmpty() )
	{
		MessageBox( strErrorMsg , NULL , MB_ICONSTOP ) ;
	}
	return iRv ;

}

// ********************************
//	CMainFrame
// ********************************
	// ********************************
	//@name	����
	// ********************************
	/**
	 *	�w�H���t�@�C���̃v���p�e�B�x�_�C�A���O���J���܂��B
	 *
	 *	�_�C�A���O���wOK�x�ŕ���ꂽ��A�H���t�@�C����
	 *	�v���p�e�B���w���[�g�h�L�������g�x CDiagramEditDoc 
	 *	�ɔ��f���܂��B
	 * @return
	 *	0 �ȏ�͐����A�G���[�Ȃ畉�̐��ł��B 
	 *	-	1 ;	//	�wOK�x��������āA���͓��e��
	 *		�w���[�g�h�L�������g�x�ɔ��f���܂����B
	 *	-	0 ;	//	�wCancel�x��������܂����B
	 *	
	 */
int CMainFrame::execCDlgRosenFileProp() 
{
	int iRv = 0 ;
	
	// --------------------------------
	//	�r���[�̕ҏW���e�����[�g�h�L�������g�ɔ��f
	//	�i���ɁA�R�����g�r���[�j
	// --------------------------------
	getCDiagramEditDoc()->UpdateAllSubDocviews( NULL , LHINT_SUBVIEW_TO_ROOTDOC ) ;
	
	// --------------------------------
	const CDedRosenFileData*	pCDedRosenFileData = getCDiagramEditDoc()->getCDedRosenFileData() ;

	CDlgRosenFileProp	aPps( 
		pCDedRosenFileData , 
		this ) ;
	int iResult = aPps.DoModal() ;
	if ( iResult == IDOK ){
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̐����E���s
		// --------------------------------
		{
			Ou<CRfEditCmd> pCmd = aPps.getPropEditorData()->createEditCmd() ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;

		}

		iRv = 1 ;
	}
	return ( iRv ) ;
}
int CMainFrame::execCDlgDiaList() 
{
	int iRv = 0 ;

	CDlgDiaList	aDlg( getCDiagramEditDoc() , &m_CDlgRosenView ) ;
	aDlg.DoModal() ;
	
	return iRv ;
}

CView* CMainFrame::getMDIChildActiveView() 
{
	CView *pView = NULL ;
	{
		CMDIFrameWnd *pFrame = this ;
		CMDIChildWnd *pChild = pFrame->MDIGetActive();
		if ( pChild != NULL ){
			pView = pChild->GetActiveView();
		}
	}
	return pView ;
}

// ----------------------------------------------------------------



IMPLEMENT_DYNAMIC(CMainFrame, CHidemdiMainfrm)

BEGIN_MESSAGE_MAP(CMainFrame, CHidemdiMainfrm)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_ROSEN_FILE_PROP, OnRosenFileProp)
	ON_COMMAND(ID_WINDOW_ROSEN_VIEW, OnWindowRosenView)
	ON_COMMAND(ID_ROSEN_DIALIST, OnRosenDialist)
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_PasteZoubun, OnUpdateINDICATOR_PasteZoubun)
	ON_COMMAND(ID_FILE_ROSEN_FILE_INSERT, &CMainFrame::OnFileRosenfileInsert)
	ON_UPDATE_COMMAND_UI(ID_FILE_ROSEN_FILE_INSERT, &CMainFrame::OnUpdateFileRosenfileInsert)
	ON_COMMAND(ID_FILE_ROSEN_CREATE_SUB_ROSEN, &CMainFrame::OnFileRosenCreateSubRosen)
	ON_UPDATE_COMMAND_UI(ID_FILE_ROSEN_CREATE_SUB_ROSEN, &CMainFrame::OnUpdateFileRosenCreateSubRosen)
//	ON_COMMAND(ID_MENUITEM_OPEN, &CMainFrame::OnMenuitemOpen)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // �X�e�[�^�X ���C�� �C���W�P�[�^
	ID_INDICATOR_PasteZoubun , //	�\��t���ړ���
	ID_INDICATOR_KANA,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame �N���X�̍\�z/����

CMainFrame::CMainFrame()
{
	// TODO: ���̈ʒu�Ƀ����o�̏����������R�[�h��ǉ����Ă��������B
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CHidemdiMainfrm::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // �쐬�Ɏ��s
	}

	//attention Diagram�c�[���o�[�́AMainFrame�ɓ���
	//
	//	if (!m_wndToolBarDiagram.CreateEx(this, TBSTYLE_FLAT, 
	//		WS_CHILD | WS_VISIBLE | CBRS_TOP
	//		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//		!m_wndToolBarDiagram.LoadToolBar(IDR_DOCVIEW_Diagram))
	//	{
	//		TRACE0("Failed to create toolbar\n");
	//		return -1;      // �쐬�Ɏ��s
	//	}



	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // �쐬�Ɏ��s
	}

	// TODO: �c�[�� �o�[���h�b�L���O�\�ɂ��Ȃ��ꍇ�͈ȉ��̂R�s���폜
	//       ���Ă��������B
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//attention Diagram�c�[���o�[�́AMainFrame�ɓ���
	//	m_wndToolBarDiagram.EnableDocking(CBRS_ALIGN_ANY) ;
	//	DockControlBar(&m_wndToolBarDiagram);


	// ----------------------------------------------------------------
	// --------------------------------
	//	�����y�C��	
	// --------------------------------
	{
		m_CDlgRosenView.Create( m_CDlgRosenView.IDD , this ) ;
		m_CDlgRosenView.ShowWindow( SW_SHOW ) ;
	}

	// --------------------------------
	//	�����y�C���Ƃ̊Ԃ̃X�v���b�g�o�[	
	// --------------------------------
	{
		m_CWndSplitBarV.Create( this , &m_CDlgRosenView , 0 ) ;
	}



	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CHidemdiMainfrm::PreCreateWindow(cs) )
		return FALSE;
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C�����āAWindow �N���X��X�^�C����
	//       �C�����Ă��������B

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame �N���X�̐f�f

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CHidemdiMainfrm::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CHidemdiMainfrm::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame ���b�Z�[�W �n���h��


void CMainFrame::OnRosenFileProp() 
{
	execCDlgRosenFileProp() ;
}


/**
 *	[�E�C���h�E]��[�y�C���̐؂�ւ�]
 *	���j���[�R�}���h�̉����֐��ł��B
 */
void CMainFrame::OnWindowRosenView() 
{
	if ( ::IsChild( m_CDlgRosenView.GetSafeHwnd() , ::GetFocus() ) ){
		//	���y�C���Ƀt�H�[�J�X������Ƃ�
		//	MDIChild�E�C���h�E�Ƀt�H�[�J�X���ړ����܂��B
		CMDIChildWnd* pActive = MDIGetActive() ;
		if ( pActive != NULL ){
			pActive->SetFocus() ;
		}
	}	else	{
		//	���y�C���Ƀt�H�[�J�X���Ȃ��Ƃ�
		//	���y�C���Ƀt�H�[�J�X���ړ����܂��B
		m_CDlgRosenView.SetFocus() ;
	}
}
/**
 *	�w�\��t���ړ��ʁx�X�e�[�^�X�o�[�ւ̃e�L�X�g��ݒ肵�܂��B
 *
 * [�I�[�o���C�h]
 *	�󕶎����ݒ肵�܂��B
 *
 * @note
 *	CJikokuhyouView ���A�N�e�B�u�ȂƂ��́A
 *	CJikokuhyouView::OnUpdateINDICATOR_PasteZoubun()
 *	�Őݒ肳��܂��B
 */
void CMainFrame::OnUpdateINDICATOR_PasteZoubun(CCmdUI *pCmdUI)
{
    pCmdUI->Enable( FALSE ); 
    pCmdUI->SetText( "" ); 

}

void CMainFrame::OnRosenDialist() 
{
	execCDlgDiaList() ;	
}


//	[�t�@�C��]-[�H���t�@�C���̑g����]
void CMainFrame::OnFileRosenfileInsert()
{
	OnFileRosenFileInsert_Process( FALSE ) ;
}

void CMainFrame::OnUpdateFileRosenfileInsert(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnFileRosenFileInsert_Process( TRUE ) >= 0 ) ;
}

//	[�t�@�C��]-[�H���t�@�C���̐؂�o��]
void CMainFrame::OnFileRosenCreateSubRosen()
{
	OnFileRosenCreateSubRosen_Process( FALSE ) ;
}

void CMainFrame::OnUpdateFileRosenCreateSubRosen(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnFileRosenCreateSubRosen_Process( TRUE ) >= 0 ) ;
}

