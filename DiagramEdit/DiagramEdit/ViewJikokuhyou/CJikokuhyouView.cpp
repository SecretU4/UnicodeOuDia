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
// CJikokuhyouView.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"

#include "NsOu/OuNew.h"
#include "str/strToInt.h"
#include "DcDraw/CDcdLine.h"
#include "DcDraw/CDcdTargetPrinter.h"
#include "DcDraw/CDcDeviceUnitSizeX.h"
#include "DcDraw/CDcDeviceUnitSizeY.h"
#include "DcDraw/CDcdText.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/CConverter_WinGdi.h"
#include "DcDraw/print/CaDcdTargetZoomDisplay.h"
#include "DcDrawMfc/CDcdTargetMfcPrintInfo.h"
#include "DcdGrid\WndDcdGrid3\WndDcdGrid3.h"
#include "DcdGrid\CaDcdGrid_PageSelector.h"
#include "LogMsg\LogMsg.h"

#include "..\DiagramEdit.h"
#include "..\Print\CconvCdPrintPageProp.h"
#include "CJikokuhyouView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewJikokuhyou{

using namespace std ;
using namespace DcDrawLib::DcDrawMfc;
using namespace DcDrawLib::DcDraw::Print;

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouView
// --------------------------------
//@name �����֐�
// --------------------------------
// ********************************
//@name ����
// ********************************
int CJikokuhyouView::setFocusToRessyaIndex( int iRessyaIdx  , int iEkiOrder ) 
{
	int iRv = 0 ;

	CdXColSpecCont aXColSpecCont = m_pCWndDcdGrid->createXColSpecCont() ;


	int iXColumnNumber = aXColSpecCont.ColumnNumberFromSpec( 
		CdXColSpec( 
			CdXColSpec::ColumnType_Ressya , iRessyaIdx ) ) ;
	if ( iRv >= 0 )
	{
		if ( iXColumnNumber < 0  )
		{
			iRv = -1 ;
		}
	}
	if ( iRv >= 0 )
	{
		CdYColSpecCont aYColSpecCont = m_pCWndDcdGrid->createYColSpecCont() ;

		int iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec(
			CdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
				iEkiOrder ) , false ) ;
		if ( iYColumnNumber < 0 )
		{
			iYColumnNumber = aYColSpecCont.ColumnNumberFromSpec(
				CdYColSpec( 
					CdYColSpec::ColumnType_Ekijikoku_Chaku , 
					iEkiOrder ) , false ) ;
		}
		if ( iYColumnNumber < 0 )
		{
			iYColumnNumber = m_pCWndDcdGrid->getCXDcdGrid()->getYColumnNumberOfCell( 
				m_pCWndDcdGrid->getCFocus()->getFocusCell() )  ;
		}

		CDcdGridCell* pCell = m_pCWndDcdGrid->getCXDcdGrid()->getCell( 
			iXColumnNumber , iYColumnNumber ) ;
		if ( pCell != NULL )
		{
			m_pCWndDcdGrid->getCFocus()->setFocusCell( pCell )  ;
		}
	}
	return ( iRv ) ;
}

// ----------------------------------------------------------------

IMPLEMENT_DYNCREATE(CJikokuhyouView, CView)

CJikokuhyouView::CJikokuhyouView()
	: m_pCWndDcdGrid( NULL ) 
{
}

CJikokuhyouView::~CJikokuhyouView()
{
}


BEGIN_MESSAGE_MAP(CJikokuhyouView, CView)
	//{{AFX_MSG_MAP(CJikokuhyouView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouView �`��

void CJikokuhyouView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���̈ʒu�ɕ`��p�̃R�[�h��ǉ����Ă�������
}

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouView �f�f

#ifdef _DEBUG
void CJikokuhyouView::AssertValid() const
{
	CView::AssertValid();
}

void CJikokuhyouView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJikokuhyouView ���b�Z�[�W �n���h��

int CJikokuhyouView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_pCWndDcdGrid = new CWndJikokuhyou() ;
	m_pCWndDcdGrid->Create( this ) ;
	m_pCWndDcdGrid->ShowWindow( SW_SHOW ) ;
	
	return 0;
}

void CJikokuhyouView::OnDestroy() 
{
	//	�_�C���O�����r���[�̑����� .ini �t�@�C���ɏ������݁B
	getCDiagramEditApp()->writeCWndJikokuhyouViewProp( m_pCWndDcdGrid ) ;
	if ( m_pCWndDcdGrid != NULL )
	{
		m_pCWndDcdGrid->DestroyWindow() ;
		delete m_pCWndDcdGrid ;
		m_pCWndDcdGrid = NULL ;	
	}
	CView::OnDestroy();
}

void CJikokuhyouView::OnSize(UINT nType, int cx, int cy) 
{
	if ( nType == SIZE_MAXIMIZED   //�E�B���h�E�͍ő�\������܂��B
		|| nType == SIZE_RESTORED  // �E�B���h�E�̓T�C�Y�ύX����܂����ASIZE_MINIMIZED �� SIZE_MAXIMIZED �͓K�p����܂���B
	){
		m_pCWndDcdGrid->MoveWindow( 0 , 0 , cx , cy , TRUE ) ;
		return ;
	}
	
	CView::OnSize(nType, cx, cy);
	
}

void CJikokuhyouView::OnSetFocus(CWnd* pOldWnd) 
{
	//CView::OnSetFocus(pOldWnd);
	CWnd*	pControl = GetNextDlgTabItem( (CWnd*)NULL , FALSE ) ;
	pControl->SetFocus() ;
	
}

void CJikokuhyouView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC ){
		return ;
	}
	// --------------------------------
	m_pCWndDcdGrid->OnUpdate( pSender, lHint, pHint) ;
}


BOOL CJikokuhyouView::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	//	�R�}���h�n���h���́A�\�Ȃ� CWndDcdGrid �ɈϏ����܂��B
	if ( m_pCWndDcdGrid != NULL && 
		m_pCWndDcdGrid->OnCmdMsg( nID, nCode, pExtra, pHandlerInfo) )
	{
		return ( TRUE ) ;
	} 

	
	return CView::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CJikokuhyouView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	
}

BOOL CJikokuhyouView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	// �f�t�H���g�̈������
	return DoPreparePrinting( pInfo ) ;
	//return CView::OnPreparePrinting(pInfo);
}

void CJikokuhyouView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	//	���̎��_�ł́A 
	//	pInfo->m_rectDraw
	//	�̒l�͌��肵�Ă��܂���B

	//	��Ԃ��A��ԕҏW���[�h�ɕύX
	m_pCWndDcdGrid->getStateMachine()->setCurrentStateIdx( 
		m_pCWndDcdGrid->StateIdx_Ressyahensyu ) ;


	//	���̃r���[���A�N�e�B�u�ɂ��āA�X�V
	getCDiagramEditApp()->getCMainFrame()->MDIActivate( GetParent() ) ;
	m_pCWndDcdGrid->OnUpdate( NULL , 0 , NULL ) ;
	

	CView::OnBeginPrinting(pDC, pInfo);
}

void CJikokuhyouView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	//	���̎��_�ł́A 
	//	pInfo->m_rectDraw
	//	�̒l�͌��肵�Ă��܂���B

	if ( pInfo != NULL ){
		//	����Ɋւ��鏈��
		LogMsg( "CJikokuhyouView::OnPrepareDC() " ) ;
		LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;

		//	�����y�[�W�̈�����s���ꍇ�́A
		//CView::OnPrepareDC(pDC, pInfo);
		//	���Ăяo���Ă͂����܂���B
	}	else	{
		CView::OnPrepareDC(pDC, pInfo);
	}
}

/**
@return
	�����\�r���[�̈�����́A�L���v�V����
	(�㕔�̃^�C�g���E�����̃y�[�W�ԍ�)�̂��߂�
	�t�H���g������Ԃ��܂��B
*/
static CdDrawTextProp	getCdDrawTextPropStandard()
{ 
	const CDedRosenFileData* pCDedRosenFileData = 
		getCDiagramEditDoc()->getCDedRosenFileData() ;
	CdDedDispProp aCdDedDispProp = pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		aCdDedDispProp.getJikokuhyouFont(0) ,
		CdColorProp( 0 , 0 , 0 ) ) ;
}

void CJikokuhyouView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	LogMsg( "CJikokuhyouView::OnPrint() " ) ;
	LogMsg( CDcdTargetMfcPrintInfo::stringOf( pInfo ).c_str() ) ;

	// --------------------------------
	//	�`��ʂ��쐬
	// --------------------------------
	CDcdTargetMfcPrintInfo	aCDcdTargetMfcPrintInfo( pDC, pInfo ) ;

	LogMsg( "CJikokuhyouView::OnPrint()1" ) ;
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

	LogMsg( "CJikokuhyouView::OnPrint()2" ) ;
	// --------------------------------
	//	�_�����W��ݒ�
	// --------------------------------
	CaDcdTargetZoomDisplay	aCaDcdTargetZoomDisplay( 
		&aTargetInnerMargin , 
		aCDcdTargetMfcPrintInfo.getPrinterHdc() ) ;
	//aCaDcdTargetZoomDisplay = �]���������������`��̈�B
	//	�P�ʂ́A��ʏ�̂P�s�N�Z�������ɂȂ�܂����B

	LogMsg( "CJikokuhyouView::OnPrint()3" ) ;
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
		}
		//	�_�C����
		if ( !pCJikokuhyouDoc->getDiaName().empty() ){
			strText += pCJikokuhyouDoc->getDiaName() ;
			strText += " " ;
		}
		//	����
		{
			CString	strHoukou ;
			if ( pCJikokuhyouDoc->getRessyahoukou() == Ressyahoukou_Kudari ){
				strHoukou.LoadString( IDS_WORD_Kudari ) ;
			}	else	{
				strHoukou.LoadString( IDS_WORD_Nobori ) ;
			}
			strText += (LPCTSTR)strHoukou ;
			strText += " " ;
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

	LogMsg( "CJikokuhyouView::OnPrint()4" ) ;
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


	LogMsg( "CJikokuhyouView::OnPrint()5" ) ;
	// --------------------------------
	//	�O���b�h��`��
	// --------------------------------
	int iPage = 0 ;
	int iXPage = 0 ;
	{
		//	������ɂ́A�X�N���[���o�[�����삵�Ȃ��悤�ɂ��܂��B
		//	�X�N���[���ƍĕ`���}�~���܂��B
		CPropStack	aPropStack( m_pCWndDcdGrid ) ;
		aPropStack.CDcdGrid_setUpdateCWndDcdGrid( false )
			.CFocus_setFixafterColumnNumberChange( false );
			

		CDcdGrid*	pCDcdGrid = m_pCWndDcdGrid->getCXDcdGrid() ;
		CaDcdGrid_PageSelector	aCaDcdGrid_PageSelector( pCDcdGrid , pTargetGrid ) ;

		if ( (int)pInfo->m_nCurPage > aCaDcdGrid_PageSelector.getPageCount() ){
			//	�y�[�W�ԍ����傫�����܂��B
			//	���̏ꍇ�́A����͒��f���܂��B	
			pInfo->m_bContinuePrinting = false ;
			return ;
		}
			
		aCaDcdGrid_PageSelector.setPage( pInfo->m_nCurPage - 1 ) ;
		aCaDcdGrid_PageSelector.DcDraw() ;


		//OnPrint() �� 
		//pInfo->SetMaxPage( aCaDcdGrid_PageSelector.getPageCount() ) ;
		//	�����Ă����ʂ͂���܂���B
		//	(������[�v�́AOnBeginPrinting() �I�����_��
		//	�l�����Ƃɍs���邩��ł�)
		pInfo->SetMinPage( 1 ) ;
		pInfo->SetMaxPage( aCaDcdGrid_PageSelector.getPageCount() ) ;

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
		iXPage = aCaDcdGrid_PageSelector.getXPage() ;
	}

	LogMsg( "CJikokuhyouView::OnPrint()6" ) ;
	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ��̃e�L�X�g���쐬
	// --------------------------------
	{
		//�L���v�V�����Ƀy�[�W��ǉ�
		{
			string	strCaption = pdcdCaption->getText() ;
			CString	strSono ;
			strSono.Format( IDS_WORD_Sono , iXPage + 1 ) ;
			strCaption += (LPCTSTR)strSono ;
			strCaption += " " ;
			pdcdCaption->setText( strCaption ) ;
		}
		//�y�[�W�ԍ�������
		{
			string	strPage = stringOf( iPage + 1) ;
			pdcdPage->setText( strPage ) ;
		}
	}

	LogMsg( "CJikokuhyouView::OnPrint()7" ) ;
	// --------------------------------
	//	�L���v�V�����ƃy�[�W�ԍ���`��
	// --------------------------------
	{
			pdcdCaption->DcDraw( pTargetCaption ) ;
			pdcdPage->DcDraw( pTargetPage ) ;
	}
	// --------------------------------
	//CView::OnPrint(pDC, pInfo);
}

void CJikokuhyouView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	//	����I����ɉ�ʕ\����������������B
	//
	//	���̃N���X�́A������̓O���b�h�̃X�N���[���ʒu��
	//	�ꎞ�I�ɕύX���܂��B
	//	���̂Ƃ��� m_pCWndDcdGrid �ɍĕ`�悪��������ƁA
	//	��ʂɂ͈ꎞ�I�Ɉʒu�̕ύX���ꂽ�O���b�h��
	//	�`�悳��邽�߁A��ʂ�����܂��B
	m_pCWndDcdGrid->InvalidateGrid() ;

	// --------------------------------
	CView::OnEndPrinting(pDC, pInfo);
}


void CJikokuhyouView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	if ( m_pCWndDcdGrid != NULL )
	{
		m_pCWndDcdGrid->OnActivateView( bActivate, pActivateView, pDeactiveView ) ;
	}
	//CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
} //namespace ViewJikokuhyou
