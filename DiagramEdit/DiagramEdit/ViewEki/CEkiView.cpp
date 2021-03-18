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
// CEkiView.cpp : �C���v�������e�[�V���� �t�@�C��
//	$Id: CEkiView.cpp 295 2016-06-11 05:14:13Z okm $

#include "stdafx.h"

#include <sstream>

#include "logmsg/LogMsg.h"
#include "NsOu/OuNew.h"
#include "str/strToInt.h"
#include "DcDraw/print/CaDcdTargetZoomDisplay.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDrawMfc/CDcdTargetMfcPrintInfo.h"
#include "DcdGrid\CaDcdGrid_PageSelector.h"

#include "..\DiagramEdit.h"
#include "..\Print\CconvCdPrintPageProp.h"
#include "EkiColSpec\EkiColSpec.h"
#include "CEkiView.h"
#include "CDlgEkiProp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

	// ********************************
	//@name CEkiView-����
	// ********************************
namespace ViewEki{

using namespace std ;
using namespace EkiColSpec;
using namespace DcDrawLib::DcDraw::Print;
using namespace DcDrawLib::DcDrawMfc;


int CEkiView::openCDlgEkiProp( int iEkiIndex ) 
{
	int iRv = 0 ;

	CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
	const CentDedRosen*	pCentDedRosen = 
		pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
	const CentDedEkiCont* pCentDedEkiContGet = 
		pCentDedRosen->getCentDedEkiCont() ;

	//	iEkiIndex �� Y��ԍ��ɕϊ�
	CdEkiYColSpecCont	aYColSpecCont( pCentDedEkiContGet ) ;
	int iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec( 
		CdEkiYColSpec( CdEkiYColSpec::ColumnType_Eki ,
			iEkiIndex ) 
	) ;
	if ( iYColumnNumber < 0 )
	{
		iRv = -1 ;	//	��ԍ����s���ł��B
	}
	if ( iRv >= 0 )
	{
		//	�t�H�[�J�X�Z�����A�w��̈ʒu�Ɉړ�
		CdDcdPosXy posFocusCellColumnNumber 
			= m_pCWndDcdGrid->getCFocus()->getFocusCellColumnNumber() ;
		posFocusCellColumnNumber.setY( iYColumnNumber ) ;
		m_pCWndDcdGrid->getCFocus()->setFocusCellColumnNumber( posFocusCellColumnNumber ) ;

		//	�v���p�e�B�_�C�A���O���N��
		m_pCWndDcdGrid->execEkiPropDlg( false , FALSE ) ;
	}
	return iRv ;
}


/////////////////////////////////////////////////////////////////////////////
// CEkiView

IMPLEMENT_DYNCREATE(CEkiView, CView)

CEkiView::CEkiView()
	: m_pCWndDcdGrid( NULL ) 
{
}

CEkiView::~CEkiView()
{
}


BEGIN_MESSAGE_MAP(CEkiView, CView)
	//{{AFX_MSG_MAP(CEkiView)
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEkiView �`��

void CEkiView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
}
void CEkiView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	m_pCWndDcdGrid->OnUpdate(pSender, lHint, pHint);
}

/////////////////////////////////////////////////////////////////////////////
// CEkiView �f�f

#ifdef _DEBUG
void CEkiView::AssertValid() const
{
	CView::AssertValid();
}

void CEkiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEkiView ���b�Z�[�W �n���h��

int CEkiView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// --------------------------------	
	m_pCWndDcdGrid = new CWndDcdGridEki() ;
	m_pCWndDcdGrid->Create( this ) ;
	m_pCWndDcdGrid->ShowWindow( SW_SHOW ) ;
	
	return 0;
}

void CEkiView::OnDestroy() 
{
	m_pCWndDcdGrid->DestroyWindow() ;
	delete m_pCWndDcdGrid ;
	m_pCWndDcdGrid = NULL ;

	CView::OnDestroy();
}

void CEkiView::OnSize(UINT nType, int cx, int cy) 
{
	if ( nType == SIZE_MAXIMIZED   //�E�B���h�E�͍ő�\������܂��B
		|| nType == SIZE_RESTORED  // �E�B���h�E�̓T�C�Y�ύX����܂����ASIZE_MINIMIZED �� SIZE_MAXIMIZED �͓K�p����܂���B
	){
		m_pCWndDcdGrid->MoveWindow( 0 , 0 , cx , cy , TRUE ) ;
		return ;
	}
	
	CView::OnSize(nType, cx, cy);
	
}

void CEkiView::OnSetFocus(CWnd* pOldWnd) 
{
	//CView::OnSetFocus(pOldWnd);
	CWnd*	pControl = GetNextDlgTabItem( (CWnd*)NULL , FALSE ) ;
	pControl->SetFocus() ;
	
}




BOOL CEkiView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	// �f�t�H���g�̈������
	return DoPreparePrinting(pInfo);
}

void CEkiView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	m_pCWndDcdGrid->OnUpdate( NULL , 0 , NULL ) ;
	
	CView::OnBeginPrinting(pDC, pInfo);
}


void CEkiView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	if ( pInfo != NULL ){
		//	����Ɋւ��鏈��
		LogMsg( "CEkiView::OnPrepareDC() " ) ;
		LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;
	}	else	{
		CView::OnPrepareDC(pDC, pInfo);
	}
}

static CdDrawTextProp	getCdDrawTextPropStandard()
{ 
	return CdDrawTextProp( 
		CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ,
		CdColorProp( 0 , 0 , 0 ) ) ;
}


void CEkiView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	LogMsg( "CEkiView::OnPrint() " ) ;
	LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;

	// --------------------------------
	//	�`��ʂ��쐬
	// --------------------------------
	CDcdTargetMfcPrintInfo	aCDcdTargetMfcPrintInfo( pDC, pInfo ) ;

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

	// --------------------------------
	//	�_�����W��ݒ�
	// --------------------------------
	CaDcdTargetZoomDisplay	aCaDcdTargetZoomDisplay( 
		&aTargetInnerMargin , 
		aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
	//aCaDcdTargetZoomDisplay = �]���������������`��̈�B
	//	�P�ʂ́A��ʏ�̂P�s�N�Z�������ɂȂ�܂����B

	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ��̕��i���쐬
	// --------------------------------
	Ou<CDcdText>	pdcdCaption ;
	Ou<CDcdText>	pdcdPage ;
	{
		const CentDedRosen* pCentDedRosen = 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
		CJikokuhyouDoc* pCJikokuhyouDoc = (CJikokuhyouDoc*)GetDocument() ;

		string	strText ;
		//	�H����
		if ( !pCentDedRosen->getName().empty() ){
			strText += pCentDedRosen->getName() ;
			strText += " " ;

			CString	aString ;
			aString.LoadString( IDS_WORD_EKI ) ;
			strText += (LPCTSTR)aString ;
		}
		pdcdCaption = OuNew<CDcdText>( new CDcdText( 
			strText , getCdDrawTextPropStandard() ) ) ;
	}
	// --------------------------------
	{
		CdDrawTextProp	aProp = getCdDrawTextPropStandard() ;
		CdDrawTextFormat	aFormat = aProp.getCdDrawTextFormat() ;
		aFormat.setHorizontal( aFormat.H_CENTER ) ;
		aProp.setCdDrawTextFormat( aFormat ) ;
		pdcdPage = OuNew<CDcdText>( new CDcdText( "" ,aProp , "99" ) ) ;
	}

	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ��̕��i�E
	//	�O���b�h�̃��C�A�E�g�����߂�	
	// --------------------------------
	Ou<IfDcdTarget>	pTargetCaption ;
	Ou<IfDcdTarget>	pTargetGrid ;
	Ou<IfDcdTarget>	pTargetPage ;
	{
		CdDcdZoneXy	zoneGrid = aCaDcdTargetZoomDisplay.getZone() ;
		CdDcdSizeXy	aSize ;

		pdcdCaption->getItemSize( &aCaDcdTargetZoomDisplay , &aSize ) ;
		CdDcdZoneXy zoneCaption( zoneGrid.getX() , 
			CdDcdZone( zoneGrid.getY().getPos() , aSize.getY() ) ) ;
		zoneGrid.setY( CdDcdZone().setBeginEndPos( 
			zoneCaption.getY().getEndPos() , zoneGrid.getY().getEndPos() ) ) ;
		//zoneCaption = �S�̈�̏㕔���A�L���v�V�����p�Ɋ��蓖�ĂĂ��܂��B
		//zoneGrid = �S�̈悩��A�㕔�̃L���v�V�����̈���������̈�ł��B

		pdcdPage->getItemSize( &aCaDcdTargetZoomDisplay , &aSize ) ;
		CdDcdZoneXy zonePage( zoneGrid.getX() , 
			CdDcdZone( zoneGrid.getY().getEndPos() - aSize.getY() , aSize.getY() ) ) ;
		zoneGrid.setY( CdDcdZone().setBeginEndPos( 
			zoneCaption.getY().getEndPos() , zonePage.getY().getPos() ) ) ;
		//zonePage = �S�̈�̉������A�y�[�W�p�Ɋ��蓖�ĂĂ��܂��B
		//zoneGrid = �㕔�̃L���v�V�����ɑ����āA�����̃y�[�W�̈���������̈�ł��B


		pTargetCaption = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( &aCaDcdTargetZoomDisplay , zoneCaption ) ) ;
		pTargetGrid = OuNew<CaDcdTargetItemPosition>( 
			new CaDcdTargetItemPosition( &aCaDcdTargetZoomDisplay , zoneGrid ) ) ;
		pTargetPage = OuNew<CaDcdTargetItemPosition>(
			new CaDcdTargetItemPosition( &aCaDcdTargetZoomDisplay , zonePage ) ) ;
	}
	// --------------------------------
	//	�O���b�h��`��
	// --------------------------------
	int iPage = 0 ;
	{
		CDcdGrid*	pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
		CaDcdGrid_PageSelector	aCaDcdGrid_PageSelector( pCDcdGrid , pTargetGrid ) ;
		aCaDcdGrid_PageSelector.setPage( pInfo->m_nCurPage - 1 ) ;
		aCaDcdGrid_PageSelector.DcDraw() ;

		if ( (int)pInfo->m_nCurPage >= aCaDcdGrid_PageSelector.getPageCount() ){
			//�ŏI�y�[�W�����������A������[�v���I���܂��B
			//OnPrint() �� 
			//pInfo->SetMaxPage( aCaDcdGrid_PageSelector.getPageCount() ) ;
			//	�����Ă����ʂ͂���܂���B

			pInfo->m_bContinuePrinting = false ;
		}	else	{
			pInfo->m_bContinuePrinting = true ;
		}
		
		iPage = aCaDcdGrid_PageSelector.getPage() ;
	}
	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ��̃e�L�X�g���쐬
	// --------------------------------
	{
		//�y�[�W�ԍ�������
		{
			string	strPage = stringOf( iPage + 1) ;
			pdcdPage->setText( strPage ) ;
		}
	}
	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ���`��
	// --------------------------------
	{
			pdcdCaption->DcDraw( pTargetCaption ) ;
			pdcdPage->DcDraw( pTargetPage ) ;
	}
}


void CEkiView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	//	����I����ɉ�ʕ\����������������B
	//
	//	���̃N���X�́A������̓O���b�h�̃X�N���[���ʒu��
	//	�ꎞ�I�ɕύX���܂��B
	//	���̂Ƃ��� m_pCWndDcdGrid �ɍĕ`�悪��������ƁA
	//	��ʂɂ͈ꎞ�I�Ɉʒu�̕ύX���ꂽ�O���b�h��
	//	�`�悳��邽�߁A��ʂ�����܂��B
	m_pCWndDcdGrid->InvalidateGrid() ;

	CView::OnEndPrinting(pDC, pInfo);
}

void CEkiView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	if ( m_pCWndDcdGrid != NULL )
	{
		m_pCWndDcdGrid->OnActivateView( bActivate , pActivateView , pDeactiveView ) ;
	}
	//CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

BOOL CEkiView::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	//	�R�}���h�n���h���́A�\�Ȃ� CWndDcdGrid �ɈϏ����܂��B
	if ( m_pCWndDcdGrid != NULL && 
		m_pCWndDcdGrid->OnCmdMsg( nID , nCode , pExtra , pHandlerInfo ) )
	{
		return ( TRUE ) ;
	}
	
	return CView::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

} //namespace ViewEki
