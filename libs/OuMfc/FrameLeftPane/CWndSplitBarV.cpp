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
// CWndSplitBarV.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "CWndSplitBarV.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace OuMfc{
namespace FrameLeftPane{

/////////////////////////////////////////////////////////////////////////////
// CWndSplitBarV

// ********************************
//@param	�\�z
// ********************************
BOOL CWndSplitBarV::Create( CWnd* pParentWnd, 
			CWnd* pwndLeftPane ,
			UINT nID)
{
	BOOL	bRv = TRUE ;

	m_pwndLeftPane = pwndLeftPane ;
	
	CRect	aCRect( 0 , 0 , 
		GetSystemMetrics( SM_CXEDGE ) * 2 , 
		GetSystemMetrics( SM_CYEDGE ) * 2 ) ;

	CString	strClassName = AfxRegisterWndClass( 0 , 
		LoadCursor( NULL , IDC_SIZEWE ) , 
		NULL , NULL ) ;
	
	bRv = CWnd::Create( strClassName , _T("CWndSplitBarV"), 
		WS_CHILD | WS_VISIBLE , 
		aCRect, pParentWnd, nID, NULL);

	return ( bRv ) ;
}
//SM_CXEDGE,
//SM_CYEDGE ���̌��ʕt���̃E�B���h�E�̋��E���̕��ƍ������擾���܂��BSM_CXBORDER �� SM_CYBORDER �� 3D �łł��B 

// ********************************
//@param	����
// ********************************

void CWndSplitBarV::CMDIFrameWnd_RecalcLayout(
		CMDIFrameWnd* pCMDIFrameWnd ,
		CWnd* pwndLeftPane ,
		CWndSplitBarV* pCWndSplitBarV ,
		BOOL bNotify ) 

{
	CWnd*	wndMDIClient = pCMDIFrameWnd->GetDlgItem( AFX_IDW_PANE_FIRST ) ;
	//wndMDIClient=MDIClient �̃I�u�W�F�N�g

	// --------------------------------
	//	���̑�����s���Ԃ́A
	//	MDIClient �E�C���h�E���\����
	//	���Ȃ��ĂȂȂ�܂���B
	//	�������A���ł� MDIClient ��
	//	��\���ł���ꍇ�́A���̏�Ԃ�
	//	�ύX���܂���iPrintPreview��
	//	�\�����Ă���ꍇ���A����ɂ�����܂��j
	// --------------------------------
	bool	bMDIClientMustShow = false ;
	if ( wndMDIClient != NULL ){
		if ( wndMDIClient->IsWindowVisible() ){
			wndMDIClient->ShowWindow( SW_HIDE ) ;

			bMDIClientMustShow = true ;
		}
	}
	
	// --------------------------------
	//	��{�N���X�̎����ŁA
	//	MDIClient �E�C���h�E��z�u
	// --------------------------------
	pCMDIFrameWnd->CMDIFrameWnd::RecalcLayout(bNotify);

	// --------------------------------
	if ( pwndLeftPane->GetSafeHwnd() == NULL ||
		pCWndSplitBarV->GetSafeHwnd() == NULL ){

		// --------------------------------
		//	���̑�����s���Ԃ́A
		//	MDIClient �E�C���h�E���\����
		//	���Ȃ��ĂȂȂ�܂���B
		// --------------------------------
		if ( bMDIClientMustShow ){
			wndMDIClient->ShowWindow( SW_SHOW ) ;
		}
		return ;
	}


	//	���̎��_�ł́AMDIClient �̈ʒu�ƃT�C�Y�́A
	//	�����y�C���ƁA�X�v���b�g�o�[���Ȃ���Ԃ�
	//	���̂ɂȂ��Ă��܂��B

	// --------------------------------
	//	�e�E�C���h�E�̌��݂̈ʒu���擾
	// --------------------------------
	CRect	rectMDIClient ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		wndMDIClient->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectMDIClient = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	CRect	rectLeftpane ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		pwndLeftPane->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectLeftpane = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	CRect	rectSplitBarV ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		pCWndSplitBarV->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectSplitBarV = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	//rectMDIClient=MDIClient �̈ʒu�ƃT�C�Y
	//	(�����y�C���ƁA�X�v���b�g�o�[���Ȃ����)
	//rectLeftpane = LeftPane�̌��݂̈ʒu
	//rectSplitBarV = SplitBarV�̌��݂̈ʒu



	// --------------------------------
	//	�e�E�C���h�E�̐V�����ʒu���Z��
	// --------------------------------
	CRect	rectLeftpaneNew ;
	{
		rectLeftpaneNew = rectLeftpane  ;
		rectLeftpaneNew.left = rectMDIClient.left ;
		rectLeftpaneNew.right = rectLeftpaneNew.left + rectLeftpane.Width() ;
		if ( rectLeftpaneNew.right >= rectMDIClient.right - rectSplitBarV.Width() ){
			rectLeftpaneNew.right = rectMDIClient.right - rectSplitBarV.Width() ;
		}
		rectLeftpaneNew.top = rectMDIClient.top ;
		rectLeftpaneNew.bottom = rectMDIClient.bottom ;
	}
	CRect	rectSplitBarVNew ;
	{
		rectSplitBarVNew = rectSplitBarV ;
		rectSplitBarVNew.left = rectLeftpaneNew.right ;
		rectSplitBarVNew.right = rectSplitBarVNew.left + rectSplitBarV.Width() ;
		rectSplitBarVNew.top = rectMDIClient.top ;
		rectSplitBarVNew.bottom = rectMDIClient.bottom ;
	}
	CRect	rectMDIClientNew  ;
	{
		rectMDIClientNew = rectMDIClient  ;
		rectMDIClientNew.left = rectSplitBarVNew.right  ;
		if ( rectMDIClientNew.right < rectMDIClientNew.left ){
			rectMDIClientNew.right = rectMDIClientNew.left ; 
		}
		

	}
	//rectLeftpaneNew=�����y�C���� �̈ʒu�ƃT�C�Y
	//rectSplitBarVNew=�X�v���b�g�o�[�̈ʒu�ƃT�C�Y
	//rectMDIClientNew=MDIClient �̈ʒu�ƃT�C�Y
	//	(�����y�C���ƁA�X�v���b�g�o�[�̗̈���m�ۂ����T�C�Y)

	// --------------------------------
	//	�e�E�C���h�E�̐V�����ʒu��ݒ�
	// --------------------------------
	pwndLeftPane->SetWindowPos( NULL , 
		rectLeftpaneNew.left , 
		rectLeftpaneNew.top , 
		rectLeftpaneNew.Width() , 
		rectLeftpaneNew.Height() , 
		SWP_NOZORDER ) ;   
	pCWndSplitBarV->SetWindowPos( NULL , 
		rectSplitBarVNew.left , 
		rectSplitBarVNew.top , 
		rectSplitBarVNew.Width() , 
		rectSplitBarVNew.Height() , 
		SWP_NOZORDER ) ;   
	wndMDIClient->SetWindowPos( NULL , 
		rectMDIClientNew.left , 
		rectMDIClientNew.top , 
		rectMDIClientNew.Width() , 
		rectMDIClientNew.Height() , 
		SWP_NOZORDER ) ;   

	// --------------------------------
	//	���̑�����s���Ԃ́A
	//	MDIClient �E�C���h�E���\����
	//	���Ȃ��ĂȂȂ�܂���B
	// --------------------------------
	if ( bMDIClientMustShow ){
		wndMDIClient->ShowWindow( SW_SHOW ) ;
	}
}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
CWndSplitBarV::CWndSplitBarV() :
	m_pwndLeftPane( NULL ) , m_iDragPosX( -1 ) 
{
}

CWndSplitBarV::~CWndSplitBarV()
{
}


BEGIN_MESSAGE_MAP(CWndSplitBarV, CWnd)
	//{{AFX_MSG_MAP(CWndSplitBarV)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CWndSplitBarV ���b�Z�[�W �n���h��

void CWndSplitBarV::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	
	CRect	rectClient ;
	GetClientRect( &rectClient ) ;
	// �`��p���b�Z�[�W�Ƃ��� CWnd::OnPaint() ���Ăяo���Ă͂����܂���

	{
		CRect	rectFill = rectClient ;
		rectClient.right = rectClient.left + 1 ;
		FillRect(  dc.GetSafeHdc() , &rectFill , GetSysColorBrush( COLOR_3DLIGHT ) ) ;
	}
	{
		CRect	rectFill = rectClient ;
		rectClient.left  = rectClient.left + 1 ;
		rectClient.right = rectClient.right - 1 ;
		FillRect(  dc.GetSafeHdc() , &rectFill , GetSysColorBrush( COLOR_3DFACE ) ) ;
	}

	{
		CRect	rectFill = rectClient ;
		rectClient.left  = rectClient.right - 1 ;
		FillRect(  dc.GetSafeHdc() , &rectFill , GetSysColorBrush( COLOR_3DSHADOW ) ) ;
	}

//COLOR_3DDKSHADOW 3D �I�u�W�F�N�g�̈Â��e�̐F�B 
//COLOR_3DFACE, COLOR_BTNFACE 3D �I�u�W�F�N�g�̕\�ʐF�ƁA�_�C�A���O�{�b�N�X�̔w�i�F�B 
//COLOR_3DHILIGHT, COLOR_3DHIGHLIGHT, COLOR_BTNHILIGHT, COLOR_BTNHIGHLIGHT 3D �I�u�W�F�N�g�̍ł����邢�F�i�����ɖʂ����Ӂj�B 
//COLOR_3DLIGHT 3D �I�u�W�F�N�g�̖��邢�F�i�����ɖʂ����Ӂj�B 
//COLOR_3DSHADOW, COLOR_BTNSHADOW 3D �I�u�W�F�N�g�̉e�̐F�i�����ɖʂ��Ă��Ȃ��Ӂj�B 



}


void CWndSplitBarV::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_iDragPosX = point.x ;
	SetCapture() ;
	
	//CWnd::OnLButtonDown(nFlags, point);
}

void CWndSplitBarV::OnLButtonUp(UINT nFlags, CPoint point) 
{
	ReleaseCapture() ;
	m_iDragPosX = -1 ;
	
	//CWnd::OnLButtonUp(nFlags, point);
}

void CWndSplitBarV::OnMouseMove(UINT nFlags, CPoint point) 
{
	//CWnd::OnMouseMove(nFlags, point);


	if ( ( nFlags & MK_LBUTTON ) != MK_LBUTTON ){
		if ( m_iDragPosX != -1 ){
			ReleaseCapture() ;
			m_iDragPosX = -1 ;
		}
	} 
	if ( m_iDragPosX == -1 ){
		return ;
	}
	// --------------------------------
	//	�e�E�C���h�E�̌��݂̈ʒu���擾
	// --------------------------------
	CWnd*	wndMDIClient = GetParent()-> GetDlgItem( AFX_IDW_PANE_FIRST ) ;

	CRect	rectMDIClient ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		wndMDIClient->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectMDIClient = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	CRect	rectLeftpane ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		m_pwndLeftPane->GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectLeftpane = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	CRect	rectSplitBarV ;
	{
		WINDOWPLACEMENT aWINDOWPLACEMENT ;
		aWINDOWPLACEMENT.length = sizeof(aWINDOWPLACEMENT) ;
		GetWindowPlacement( &aWINDOWPLACEMENT ) ;
		rectSplitBarV = aWINDOWPLACEMENT.rcNormalPosition ;
	}
	//rectMDIClient=MDIClient �̈ʒu�ƃT�C�Y
	//	(�����y�C���ƁA�X�v���b�g�o�[���Ȃ����)
	//rectLeftpane = LeftPane�̌��݂̈ʒu
	//rectSplitBarV = SplitBarV�̌��݂̈ʒu

	// --------------------------------
	//	�e�E�C���h�E�̐V�����ʒu���Z��
	// --------------------------------
	CRect	rectSplitBarVNew ;
	{
		rectSplitBarVNew = rectSplitBarV ;
		rectSplitBarVNew.left = rectSplitBarV.left + ( point.x - m_iDragPosX ) ;
		if ( rectSplitBarVNew.left < rectLeftpane.left ){
			rectSplitBarVNew.left = rectLeftpane.left ;
		}
		if ( rectSplitBarVNew.left > rectMDIClient.right - rectSplitBarV.Width() ){
			rectSplitBarVNew.left = rectMDIClient.right - rectSplitBarV.Width() ;
		}
		rectSplitBarVNew.right = rectSplitBarVNew.left + rectSplitBarV.Width() ;
	}
	CRect	rectLeftpaneNew ;
	{
		rectLeftpaneNew = rectLeftpane  ;
		rectLeftpaneNew.right = rectSplitBarVNew.left ;
	}
	CRect	rectMDIClientNew  ;
	{
		rectMDIClientNew = rectMDIClient  ;
		rectMDIClientNew.left = rectSplitBarVNew.right  ;
	}
	// --------------------------------
	//	�e�E�C���h�E�̐V�����ʒu��ݒ�
	// --------------------------------
	m_pwndLeftPane->SetWindowPos( NULL , 
		rectLeftpaneNew.left , 
		rectLeftpaneNew.top , 
		rectLeftpaneNew.Width() , 
		rectLeftpaneNew.Height() , 
		SWP_NOZORDER ) ;   
	SetWindowPos( NULL , 
		rectSplitBarVNew.left , 
		rectSplitBarVNew.top , 
		rectSplitBarVNew.Width() , 
		rectSplitBarVNew.Height() , 
		SWP_NOZORDER ) ;   
	wndMDIClient->SetWindowPos( NULL , 
		rectMDIClientNew.left , 
		rectMDIClientNew.top , 
		rectMDIClientNew.Width() , 
		rectMDIClientNew.Height() , 
		SWP_NOZORDER ) ;   



	
}

} //namespace FrameLeftPane
} //namespace OuMfc
