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
// CDedCommentView.cpp : �C���v�������e�[�V���� �t�@�C��
// $Id: CDedCommentView.cpp 295 2016-06-11 05:14:13Z okm $

#include "stdafx.h"

#include "NsOu/OuNew.h"
#include "NsOu/dynamic_castOu.h"
#include "str/strLf.h"
#include "str/strToInt.h"
#include "LogMsg\LogMsg.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDrawMfc/CDcdTargetMfcPrintInfo.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/print/CaDcdTargetZoomDisplay.h"

#include "..\DiagramEdit.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "..\Print\CconvCdPrintPageProp.h"
#include "CDedCommentView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewComment{

using namespace std ;
/////////////////////////////////////////////////////////////////////////////
// CDedCommentView

void CDedCommentView::OnUpdate_All() 
{

	LogMsg( "CDedCommentView::OnUpdate_All() View�̍X�V" ) ;

	CDiagramEditDoc* pRootDoc = getCDiagramEditDoc() ;

	//	�t�H���g���ύX����Ă�����A�t�H���g��ݒ�
	CdFontProp	aCdFontProp = pRootDoc->getCDedRosenFileData()->getCdDedDispProp().getViewCommentFont() ;
	if ( m_CdFontProp != aCdFontProp ){
		if ( m_CFont.GetSafeHandle() != NULL ){
			m_CFont.DeleteObject() ;
		}

		CDC* pDc = GetEditCtrl().GetDC() ;
		CConverter_WinGdi	aConv ;
		m_CFont.CreateFontIndirect( &aConv.LOGFONTOf( aCdFontProp , pDc->GetSafeHdc() ) ) ;
		
		GetEditCtrl().SetFont( &m_CFont ) ;
		// --------------------------------
		if ( pDc != NULL ){
			GetEditCtrl().ReleaseDC( pDc ) ;
			pDc = NULL ;
		}
		m_CdFontProp = aCdFontProp ;
	}
	
	//	�e�L�X�g���X�V	
	string strLs = pRootDoc->getCDedRosenFileData()->getCentDedRosen()->getComment() ;
	{
		int iLineNum = GetEditCtrl().GetFirstVisibleLine() ;
		int iStartChar , iEndChar ;
		GetEditCtrl().GetSel( iStartChar , iEndChar ) ;
		GetEditCtrl().SetWindowText( strCrlfOf( strLs ).c_str() ) ;
		if ( iStartChar > GetEditCtrl().GetWindowTextLength() ){
			iStartChar = GetEditCtrl().GetWindowTextLength() ;
		}
		if ( iEndChar > GetEditCtrl().GetWindowTextLength() ){
			iEndChar = GetEditCtrl().GetWindowTextLength() ;
		}
		GetEditCtrl().LineScroll( iLineNum ) ;
		GetEditCtrl().SetSel( iStartChar , iStartChar , FALSE ) ;
	}

	// --------------------------------
	m_bUpdate_All_Requested = false ;

	LogMsg( "CDedCommentView::OnUpdate_All()=" ) ;

}

void CDedCommentView::OnUpdate_Comment( Ou<CRfEditCmd_Comment> pCommand )
{
	CView *pView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	
	if ( this != pView )
	{
		LogMsg( "CDedCommentView::OnUpdate_Comment() "
			"���̃r���[�ɂ��X�V��this �ɔ��f���܂��B" ) ;

		int iLineNum = GetEditCtrl().GetFirstVisibleLine() ;
		int iStartChar , iEndChar ;
		GetEditCtrl().GetSel( iStartChar , iEndChar ) ;
		GetEditCtrl().SetWindowText( strCrlfOf( pCommand->getComment() ).c_str() ) ;
		if ( iStartChar > GetEditCtrl().GetWindowTextLength() ){
			iStartChar = GetEditCtrl().GetWindowTextLength() ;
		}
		if ( iEndChar > GetEditCtrl().GetWindowTextLength() ){
			iEndChar = GetEditCtrl().GetWindowTextLength() ;
		}
		GetEditCtrl().SetSel( iStartChar , iStartChar ) ;
		GetEditCtrl().LineScroll( iLineNum ) ;

	}
	else
	{
		LogMsg( "CDedCommentView::OnUpdate_Comment() "
			"this�ɂ��X�V�Ȃ̂ŁA���̃r���[�ɂ͔��f���܂���B" ) ;
	}

}

IMPLEMENT_DYNCREATE(CDedCommentView, CEditView)

CDedCommentView::CDedCommentView(): 
	m_bUpdate_All_Requested( false ) ,
	m_bIsChanged( false )
{
}

CDedCommentView::~CDedCommentView()
{
}


BEGIN_MESSAGE_MAP(CDedCommentView, CDedCommentView::super)
	//{{AFX_MSG_MAP(CDedCommentView)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_WM_DESTROY()
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDedCommentView �`��

void CDedCommentView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
}

/////////////////////////////////////////////////////////////////////////////
// CDedCommentView �f�f

#ifdef _DEBUG
void CDedCommentView::AssertValid() const
{
	super::AssertValid();
}

void CDedCommentView::Dump(CDumpContext& dc) const
{
	super::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDedCommentView ���b�Z�[�W �n���h��

void CDedCommentView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if ( lHint ==  LHINT_SUBVIEW_TO_ROOTDOC  )
	{
		//[Attention]
		//	(lHint== LHINT_SUBVIEW_TO_ROOTDOC )�̏ꍇ�́A
		//	�r���[�̓��e�����[�gDoc�ɔ��f����
		//	���������B
		if ( m_bIsChanged )
		{
			// --------------------------------
			//	�R�}���h�̐����E���s
			// --------------------------------
			CString	strLs ;
			GetEditCtrl().GetWindowText( strLs ) ;
			OuNew<CRfEditCmd> pCmd( 
				new CRfEditCmd_Comment( strLfOf( (LPCTSTR)strLs ) ) ) ;
			int  iResult = getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			ASSERT( iResult >= 0 ) ;
			
			// --------------------------------
			m_bIsChanged = false ;
		}
	}	else	{
		//[Attention]
		//	(lHint!= LHINT_SUBVIEW_TO_ROOTDOC )�̏ꍇ�́A
		//	���[�gDoc�̓��e���r���[��
		//	���f���Ă��������B

		//pHint= 
		//	pHint�� CRfEditCmdHolder �I�u�W�F�N�g�Ȃ�A
		//	�Ή�����ҏW�R�}���h CRfEditCmd ��ێ����Ă��܂��B
		//	���̏ꍇ�Athis �� CRfEditCmd �̓��e�ɍœK������
		//	�X�V���s���܂��B
		//	NULL�Ȃ�A�S�X�V���v������Ă��܂��B
		if ( m_bUpdate_All_Requested )
		{
			//	�S�X�V���ۗ�����Ă���ꍇ�́A
			//	���̌�̓R�}���h�ɂ��œK�����ꂽ�P�̂̂����Ȃ�X�V�v���ɑ΂��Ă��A�S�X�V���s���܂��B
			pHint = NULL ;
		}

		Ou<CRfEditCmd> pCmd ;
		if ( pHint != NULL && pHint->IsKindOf( RUNTIME_CLASS( CRfEditCmdHolder ) ) ){
			CRfEditCmdHolder* pCHolder = (CRfEditCmdHolder*)pHint ;
			pCmd = pCHolder->getCmd() ;
		}
		if ( pCmd != NULL ){
			if ( 
				dynamic_castOu<CRfEditCmd_Comment>( pCmd ) 
			) {
				//	�R�����g���ύX���ꂽ��A�����ݒ肵�܂��B
				//	�A���A���̃r���[���A�N�e�B�u�ȏꍇ�́A���̍X�V�͍s���܂���B
				Ou<CRfEditCmd_Comment>	pCommand = 
					dynamic_castOu<CRfEditCmd_Comment>( pCmd ) ;
				OnUpdate_Comment( pCommand ) ;
			}	else if ( 
				dynamic_castOu<CRfEditCmd_Dia>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_Eki>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_Ressya>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd ) ||
				dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd ) 
			){
				//	���̃r���[�́A
				//		�_�C���̕ύX
				//		�_�C���̃v���p�e�B�̕ύX
				//		�w�̕ύX
				//		��Ԃ̕ύX
				//		��Ԃ̒��ʉ�
				//		��Ԏ�ʂ̕ύX
				//		��Ԏ�ʂ̓���
				//	�̏ꍇ�́A�X�V���s���܂���B
			}
			else
			{
				//	�S�X�V����
				//CRfEditCmd_DedRosenFileDataProp
				//	�t�H���g���X�V�����ꍇ������܂��̂ŁA�S�X�V���K�v�ł�
				//CRfEditCmd_Rosen
				//CRfEditCmd_RosenFileData
				//	CentDedRosen ���܂���I�u�W�F�N�g�̒u�����B
				pHint = NULL ;
			}
		}
		
		//	�œK�����ꂽ�X�V���Ȃ��ꍇ�́A
		//	�S�X�V�v��
		if ( pHint == NULL ){
			if ( getCDiagramEditApp()->getCMainFrame()->getMDIChildActiveView() != this ){
				//	���̃r���[����A�X�V���v������܂����B
				//	�r���[�̍X�V�́A���̃r���[���A�N�e�B�u�ɂȂ�܂�
				//	�ۗ����܂��B
				LogMsg( "CDedCommentView::OnUpdate() View�̍X�V��ۗ�" ) ;
				m_bUpdate_All_Requested = true ;
				return ;
			}
			//	�r���[�̑S�X�V
			OnUpdate_All() ;
		}
	}
}

void CDedCommentView::OnChange() 
{
	// TODO: ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A�R���g���[���́A lParam �}�X�N
	// ���ł̘_���a�� ENM_CHANGE �t���O�t���� CRichEditCrtl().SetEventMask()
	// ���b�Z�[�W���R���g���[���֑��邽�߂� CEditView::OnInitDialog() �֐����I�[�o�[
	// ���C�h���Ȃ����肱�̒ʒm�𑗂�܂���B
	
	getCDiagramEditDoc()->SetModifiedFlag( TRUE ) ;
	m_bIsChanged = true ;
	
}

void CDedCommentView::OnFilePrintPreview() 
{
	//	�v���r���[��L���ɂ��܂��B
	super::OnFilePrintPreview() ;
}

void CDedCommentView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	if ( !bActivate ){
		//[Attention]
		//	���̃r���[����A�N�e�B�u�ɂȂ����Ƃ��ɂ́A
		//	OnUpdate(lHint=LHINT_SUBVIEW_TO_ROOTDOC)���Ăяo���āA
		//	���̃r���[�̓��e��
		//	���[�gDoc�ɔ��f�����������ŁA����Ƀ��[�gDoc�̓��e��
		//	���ׂẴT�uDoc/View�ɔ��f�����Ă��������B


		// --------------------------------
		//	�w�H���x�h�L�������g�̍X�V
		// --------------------------------
		OnUpdate( this , LHINT_SUBVIEW_TO_ROOTDOC , NULL ) ;


	}
	if ( m_bUpdate_All_Requested && bActivate ){
		//	�r���[�̍X�V���ۗ�����Ă����ԂŁA
		//	�r���[���A�N�e�B�u�ɂȂ����Ƃ��́A
		//	�r���[�̍X�V���s�킹�܂��B
		OnUpdate_All() ;
	}
	
	
	super::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

void CDedCommentView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	if ( m_bUpdate_All_Requested ){
		//	�r���[�̍X�V���ۗ�����Ă���ꍇ�́A
		//	�r���[�̍X�V���s�킹�܂��B
		OnUpdate_All() ;
	}
	
	super::OnBeginPrinting(pDC, pInfo);
}

void CDedCommentView::OnDestroy() 
{
	CFont	aCFont ;
	aCFont.CreateStockObject( SYSTEM_FONT ) ;
	GetEditCtrl().SetFont( &aCFont ) ;

	super::OnDestroy();
}


BOOL CDedCommentView::PreCreateWindow(CREATESTRUCT& cs) 
{
	
	BOOL bRv = super::PreCreateWindow(cs);

	//	�����X�N���[���o�[���폜���A
	//	�e�L�X�g���E�[�Ő܂�Ԃ��悤�ɕύX
	if ( bRv ){
		cs.style &=~( WS_HSCROLL ) ;
		cs.style &=~( ES_AUTOHSCROLL ) ;
	}
	return ( bRv ) ;
}


CdDrawTextProp	CDedCommentView::getCdDrawTextPropStandard()
{ 
	const CDedRosenFileData* pCDedRosenFileData = 
		getCDiagramEditDoc()->getCDedRosenFileData() ;
	CdDedDispProp aCdDedDispProp = pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		m_CdFontProp ,
		CdColorProp( 0 , 0 , 0 ) ) ;
}



void CDedCommentView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	super::OnPrint( pDC , pInfo ) ;
	return ;


	//	�ȉ��̃R�[�h�́A�y�[�W�ԍ���
	//	�\�����悤�Ƃ������̂ł����A
	//	ASSERT�ɂȂ��Ă��܂��܂��B
	//	���̂��߁A���ʂ͓��삳���܂���B
/*
	//attention
	//	���̃N���X�́A�y�[�W���Ƃ̊J�n�ʒu��
	//	�L���b�V�����Ă��܂��iCEditView::m_aPageStart�j�B
	//	�Ƃ��낪�A�}�b�v���[�h��
	//	�ύX���Ă���ꍇ�A�v���r���[�\�����ɃE�C���h�E�T�C�Y��
	//	�ύX����ƁA�L���b�V���Ǝ��ۂ̕\�����H�������
	//	���܂��AASSERT�ɂȂ��Ă��܂��܂��B
	//	�ȉ��̂R�֐������s���邱�Ƃɂ��A�L���b�V�����N���A�ł���
	//	���Ƃ�������܂����B
	//	
	//	OnPrepareDC ����� ���̊֐����Ăяo����܂��B
	//	OnPrepareDC����Ăяo���ꂽ�ꍇ�́A
	//	���̋�Ԃ̎��s�͔�����ׂ��ł��B
	//	b �́AOnPrepareDC�����s���ł��邱�Ƃ������t���O�ł��B
	static bool b = false ;
	if ( !b ){
		b = true ;

		//attention
		//	�ȉ������s����ƁA�v�����^DC�����܂��B
		//	���R�͕s���ł��B
		//
		//	CPrintInfo	aCPrintInfo = *pInfo ;
		
		super::OnEndPrinting( pDC, pInfo ) ;
		super::OnBeginPrinting( pDC, pInfo ) ;
		super::OnPrepareDC( pDC, pInfo ) ;

		b = false ;

		//attention
		//	��������ƁA�v�����^DC�����܂��B
		//	���R�͓�ł��B
		//
		//	*pInfo = aCPrintInfo ;
	}



	LogMsg( "CDedCommentView::OnPrint() " ) ;
	LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;

	// --------------------------------
	//	�`��ʂ��쐬
	// --------------------------------
	CDcdTargetMfcPrintInfo	aCDcdTargetMfcPrintInfo( pDC, pInfo ) ;

	LogMsg( "CDedCommentView::OnPrint()1" ) ;

	// --------------------------------
	//	�]�����������̈���쐬
	// --------------------------------
	CaDcdTargetItemPosition	aTargetInnerMargin( &aCDcdTargetMfcPrintInfo , 
		CdDcdZoneXy() ) ;
	{
		LogMsg( DeviceCapsToString( 
			aCDcdTargetMfcPrintInfo.getPrinterHdc() ).c_str() ) ;
	
		CconvCdPrintPageProp aCconvCdPrintPageProp ;
		CdDcdZoneXy	zonexyInneraMargin = 
			aCconvCdPrintPageProp.calcZoneInnerMargin( 
				getCDiagramEditApp()->getCdPrintPageProp() , 
				aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
		if ( zonexyInneraMargin.getX().getSize() <= 0 ){
			zonexyInneraMargin.setX( 
				aCDcdTargetMfcPrintInfo.getZone().getX() ) ;
		}
		if ( zonexyInneraMargin.getY().getSize() <= 0 ){
			zonexyInneraMargin.setY( 
				aCDcdTargetMfcPrintInfo.getZone().getY() ) ;
		}

		aTargetInnerMargin.setZone( zonexyInneraMargin ) ;

	}

	//aTargetInnerMargin = �]���������������`��̈�B
	//	�P�ʂ̓v�����^�̃s�N�Z���ł��B


	LogMsg( "CDedCommentView::OnPrint()2" ) ;

	// --------------------------------
	//	�_�����W��ݒ�
	// --------------------------------
	CaDcdTargetZoomDisplay	aCaDcdTargetZoomDisplay( 
		&aTargetInnerMargin , 
		aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
	//aCaDcdTargetZoomDisplay = �]���������������`��̈�B
	//	�P�ʂ́A��ʏ�̂P�s�N�Z�������ɂȂ�܂����B
	IfDcdTarget*	pTarget =  &aCaDcdTargetZoomDisplay ;
	
	//pTarget = �`����s���̈�B
	//	�P�ʂ́A��ʏ�̂P�s�N�Z�������ɂȂ�܂����B

	LogMsg( "CDedCommentView::OnPrint()3" ) ;
	// --------------------------------
	//	�y�[�W�ԍ���DcDraw�I�u�W�F�N�g���i���쐬
	// --------------------------------
	
	//memo: �L���v�V�����̈���͍s��Ȃ����Ƃɂ��܂����B
	//	Ou<CDcdText>	pdcdCaption ;
	//	{
	//		const CentDedRosen* pCentDedRosen = 
	//			getCDiagramEditDoc()->getCDedRosenFileData()
	//				->getCentDedRosen() ;
	//			CJikokuhyouDoc* pCJikokuhyouDoc = 
	//				(CJikokuhyouDoc*)GetDocument() ;
	//		
	//			string	strText ;
	//			//	�H����
	//			if ( !pCentDedRosen->getName().empty() ){
	//				strText += pCentDedRosen->getName() ;
	//				strText += " " ;
	//			}
	//		
	//			pdcdCaption = OuNew<CDcdText>( new CDcdText( 
	//				strText , getCdDrawTextPropStandard() ) ) ;
	//		}

	Ou<CDcdText>	pdcdPage ;
	{
		CdDrawTextProp	aProp = getCdDrawTextPropStandard() ;
		CdDrawTextFormat	aFormat = aProp.getCdDrawTextFormat() ;
		aFormat.setHorizontal( aFormat.H_CENTER ) ;
		aProp.setCdDrawTextFormat( aFormat ) ;
		pdcdPage = OuNew<CDcdText>( new CDcdText( "" ,aProp , "99" ) ) ;
	}
	//pdcdPage = �y�[�W�ԍ���DcDraw�I�u�W�F�N�g
	
	// --------------------------------
	//	�y�[�W�ԍ��̕��i�E
	//	CEditView �e�L�X�g�̃��C�A�E�g�����߂�	
	// --------------------------------
	
	//memo: �L���v�V�����̈���͍s��Ȃ����Ƃɂ��܂����B
	//	Ou<CaDcdTargetItemPosition>	pTargetCaption ;

	Ou<CaDcdTargetItemPosition>	pTargetEditView ;
	Ou<CaDcdTargetItemPosition>	pTargetPage ;
	{
		CdDcdZoneXy	zoneEditView = pTarget->getZone() ;
		//zoneEditView=�]���������������`��̈�B
		//	��������y�[�W�ԍ������������̂��A
		//	�ŏI�I�ɃG�f�B�b�g�r���[�ɋL���ꂽ���e��
		//	�������̈�ł��B


		//memo: �L���v�V�����̈���͍s��Ȃ����Ƃɂ��܂����B
		//	pdcdCaption->getItemSize( pTarget , &aSize ) ;
		//	CdDcdZoneXy zoneCaption( zoneEditView.getX() , 
		//		CdDcdZone( zoneEditView.getY().getPos() , aSize.getY() ) ) ;
		//	zoneEditView.setY( CdDcdZone().setBeginEndPos( 
		//		zoneCaption.getY().getEndPos() + aSize.getY() , 
		//		zoneEditView.getY().getEndPos() ) ) ;
		//	//zoneCaption = �S�̈�̏㕔���A�L���v�V�����p�Ɋ��蓖�ĂĂ��܂��B
		//	//zoneEditView = �S�̈悩��A�㕔�̃L���v�V�����̈��������
		//	//	�̈�ł��B
		//	
		//	pTargetCaption = OuNew<CaDcdTargetItemPosition>( 
		//		new CaDcdTargetItemPosition( pTarget , zoneCaption ) ) ;

		// --------------------------------
		//	�y�[�W�ԍ��̗̈� IfDcdTarget
		// --------------------------------
		{
			CdDcdSizeXy	aSize ;
			pdcdPage->getItemSize( pTarget , &aSize ) ;
			CdDcdZoneXy zonePage( zoneEditView.getX() , 
				CdDcdZone( zoneEditView.getY().getEndPos() - aSize.getY() ,
				aSize.getY() ) ) ;
			//zonePage = �S�̈�̉������A�y�[�W�p�Ɋ��蓖�ĂĂ��܂��B
			pTargetPage = OuNew<CaDcdTargetItemPosition>(
				new CaDcdTargetItemPosition( pTarget , zonePage ) ) ;
			//pTargetPage=�y�[�W�p��IfDcdTarget

			zoneEditView.setY( CdDcdZone().setBeginEndPos( 
				zoneEditView.getY().getPos() , //zoneCaption.getY().getEndPos() , 
				zonePage.getY().getPos() - aSize.getY()) ) ;
			//zoneEditView = �㕔�̃L���v�V�����ɑ����āA�����̃y�[�W�̈���������̈�ł��B
		}

		// --------------------------------
		//	�R���e���c�̈� IfDcdTarget
		// --------------------------------
		pTargetEditView = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( pTarget , zoneEditView ) ) ;
	}
	// --------------------------------
	//	CEditView��̃e�L�X�g��`��
	// --------------------------------
	int iPage = 0 ;
	{
		CRect	rectDrawSid = pInfo->m_rectDraw ;

		// --------------------------------
		//	�v�����^�p�̃t�H���g��ݒ�
		//	�i���̊֐�����DC�̃}�b�v���[�h��ύX���Ă��܂��B
		//	CEdit �̃f�t�H���g�̃t�H���g�́A���̕ύX���l�����Ă��Ȃ����߁A
		//	�v�����^�p�̃t�H���g��V�����}�b�v���[�h��
		//	���킹�����̂ɕύX����K�v������܂��j
		// --------------------------------
		Ou<CGdiHFontHolder>	pHFontHolder ;
		CFont	aCFont ;
		CFont*	pFontSid = NULL ;
		{
			pHFontHolder = pTargetEditView->createGdiHFontHolder( getCdDrawTextPropStandard().getCdFontProp() ) ;
			aCFont.Attach( pHFontHolder->getHFont() ) ;
			pFontSid = GetPrinterFont() ;
			SetPrinterFont( &aCFont ) ;
		}
		// --------------------------------
		//	pInfo->m_rectDraw ���A
		//	�y�[�W���������̈�ɏC�����܂��B
		// --------------------------------
		CConverter_WinGdi	aConv ;
		pInfo->m_rectDraw = aConv.RECTOf( pTargetEditView->getZone() ) ;
		// --------------------------------
		//	�������
		// --------------------------------
		super::OnPrint(pDC, pInfo);
		// --------------------------------
		//	pInfo->m_rectDraw �𕜋A
		// --------------------------------
		pInfo->m_rectDraw = rectDrawSid ;

		// --------------------------------
		//	�v�����^�p�̃t�H���g��߂�
		// --------------------------------
		{
			SetPrinterFont( pFontSid ) ;
			pFontSid = NULL ;
			aCFont.Detach() ;
		}


		// --------------------------------
		iPage = pInfo->m_nCurPage - 1 ;
	}
	//iPage = �y�[�W�ԍ�(0�N�_)
	LogMsg( "CDedCommentView::OnPrint()6" ) ;
	// --------------------------------
	//	�y�[�W�ԍ��̃e�L�X�g���쐬
	// --------------------------------
	{
		//�y�[�W�ԍ�������
		{
			string	strPage = OuLib::stringOf( iPage + 1) ;
			pdcdPage->setText( strPage ) ;
		}
	}

	LogMsg( "CDedCommentView::OnPrint()7" ) ;
	// --------------------------------
	//	�y�[�W�ԍ���`��
	// --------------------------------
	{
		//memo: �L���v�V�����̈���͍s��Ȃ����Ƃɂ��܂����B
		//
		//	pdcdCaption->DcDraw( pTargetCaption ) ;

		pdcdPage->DcDraw( pTargetPage ) ;
	}
*/
}
} //namespace ViewComment
