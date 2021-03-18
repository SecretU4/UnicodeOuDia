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
// CDlgRosenFileProp_FontColor.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"

#include "DcDraw/CDcdTargetOnPaint.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/CConverter_WinGdi.h"
#include "str/stringsplit.h"
#include "MfcUtil\MfcUtil.h"

#include "..\DiagramEdit.h"
#include "CDlgRosenFileProp.h"
#include "CDlgRosenFileProp_FontColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace ViewRosen{
	using namespace OuMfc::MfcUtil ;
	using namespace OuLib::Str;
using namespace std ;

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp_FontColor �_�C�A���O

using DcDraw::CDcdTextboxV3 ;

CDlgRosenFileProp* CDlgRosenFileProp_FontColor::GetParent() 
{
	return static_cast<CDlgRosenFileProp*>( CWnd::GetParent() ) ;
}

void CDlgRosenFileProp_FontColor::updateUIState() 
{
	// --------------------------------
	//	�t�H���g
	// --------------------------------
	{
		CListBox*	pListBox = (CListBox*)GetDlgItem( IDC_LIST_FONT ) ;
		int idx = pListBox->GetCurSel() ;
		// --------------------------------
		//	�T���v���\��
		// --------------------------------
		CdFontProp*	pCdFontProp = NULL ;
		if ( 0 <= idx && idx < sizeof(m_arFontProp) / sizeof(m_arFontProp[0]) )
		{
			pCdFontProp = &m_arFontProp[idx] ;
		}
		if ( pCdFontProp != NULL )
		{
			CdDrawTextProp	aCdDrawTextProp = m_pdcdrawFont->getCdDrawTextProp() ;
			aCdDrawTextProp.setCdFontProp( *pCdFontProp ) ;
			m_pdcdrawFont->setCdDrawTextProp( aCdDrawTextProp ) ;
			// --------------------------------
			m_pdcdrawFontV->setCdFontProp( *pCdFontProp ) ;

		}

		CRect	aRect = GetDlgControlRect( this , IDC_STATIC_FONT ) ;
		InvalidateRect( &aRect ) ;
	}


	// --------------------------------
	//	�J���[
	// --------------------------------
	{
		CListBox*	pListBox = (CListBox*)GetDlgItem( IDC_LIST_COLOR ) ;
		
		int idx = pListBox->GetCurSel() ;
		COLORREF*	pColor = NULL ;
		if ( 0 <= idx && idx < sizeof(m_arColor) / sizeof(m_arColor[0]) ) 
		{
			pColor = &m_arColor[idx] ;
		}
		// --------------------------------
		if ( pColor != NULL )
		{
			CConverter_WinGdi	aConv ;
			m_pdcdrawColor->setCdBrushProp( CdBrushProp( aConv.CdColorPropOf( *pColor ) ) ) ;
		}
		
		CRect	aRect = GetDlgControlRect( this , IDC_STATIC_COLOR ) ;
		InvalidateRect( &aRect ) ;
	}
}

bool CDlgRosenFileProp_FontColor::VerticalFontIsChoosed() 
{
	CListBox*	pListBox = (CListBox*)GetDlgItem( IDC_LIST_FONT ) ;
	int idx = pListBox->GetCurSel() ;
	return ( idx == CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT+0 ) ;
}

// ********************************
//	CDlgRosenFileProp_FontColor
// ********************************
void CDlgRosenFileProp_FontColor::updateUI()
{
	CDlgRosenFileProp::CPropEditorData*	pPropEditorData = GetParent()->getPropEditorData() ;
	CConverter_WinGdi	aConv ;

	CdDedDispProp	aDispProp = pPropEditorData->getUIDispProp() ;
	// --------------------------------
	//	m_arFontProp 
	// --------------------------------
	{
		int idx = 0 ;
		for ( ; idx < CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT ; idx ++ )
		{
			m_arFontProp[idx] = aDispProp.getJikokuhyouFont( idx ) ;
		}
		m_arFontProp[idx++] = aDispProp.getJikokuhyouVFont() ;
		m_arFontProp[idx++] = aDispProp.getDiaEkimeiFont() ;
		m_arFontProp[idx++] = aDispProp.getDiaJikokuFont() ;
		m_arFontProp[idx++] = aDispProp.getDiaRessyaFont() ;
		m_arFontProp[idx++] = aDispProp.getViewCommentFont() ;
	}
	// --------------------------------
	//	m_arColor 
	// --------------------------------
	{
		int idx = 0 ;
		m_arColor[idx++] = aConv.COLORREFOf( aDispProp.getDiaMojiColor() ) ;
		m_arColor[idx++] = aConv.COLORREFOf( aDispProp.getDiaJikuColor() ) ;
	}
	// --------------------------------

	UpdateData( FALSE ) ;
	updateUIState() ;
}
int CDlgRosenFileProp_FontColor::updatePropEditorData()
{
	updateUIState() ;

	CDlgRosenFileProp::CPropEditorData*	pPropEditorData = GetParent()->getPropEditorData() ;

	int iRv = 0 ;
	if ( iRv >= 0 ){
		if ( !UpdateData() ){
			iRv = -1 ;	
		}
	}
	if ( iRv >= 0 )
	{
		CdDedDispProp	aDispProp = pPropEditorData->getUIDispProp() ;
		// --------------------------------
		//	m_arFontProp
		// --------------------------------
		{	
			int idx = 0 ;
			for ( ; idx < CentDedRessyasyubetsu::JIKOKUHYOUFONT_COUNT ; idx ++ )
			{
				aDispProp.setJikokuhyouFont( idx , m_arFontProp[idx] ) ;
			}
			aDispProp.setJikokuhyouVFont( m_arFontProp[idx++] ) ;
			aDispProp.setDiaEkimeiFont( m_arFontProp[idx++] ) ;
			aDispProp.setDiaJikokuFont( m_arFontProp[idx++] ) ;
			aDispProp.setDiaRessyaFont( m_arFontProp[idx++] ) ;
			aDispProp.setViewCommentFont( m_arFontProp[idx++] ) ;
		}
		// --------------------------------
		//	m_arColor
		// --------------------------------
		{
			int idx = 0 ;
			CConverter_WinGdi	aConv ;
			aDispProp.setDiaMojiColor( aConv.CdColorPropOf( m_arColor[idx++] ) );
			aDispProp.setDiaJikuColor( aConv.CdColorPropOf( m_arColor[idx++] ) ) ;
		}

		// --------------------------------

		pPropEditorData->setUIDispProp( aDispProp ) ;

	}
	return ( iRv ) ;
}

// ****************************************************************


CDlgRosenFileProp_FontColor::CDlgRosenFileProp_FontColor(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRosenFileProp_FontColor::IDD, pParent)
	, m_pdcdrawFont( NULL ) 
	, m_pdcdrawFontV( NULL )
	, m_pdcdrawColor( NULL ) 
{
	//{{AFX_DATA_INIT(CDlgRosenFileProp_FontColor)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CDlgRosenFileProp_FontColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRosenFileProp_FontColor)
	// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRosenFileProp_FontColor, CDialog)
	//{{AFX_MSG_MAP(CDlgRosenFileProp_FontColor)
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_LBN_SELCHANGE(IDC_LIST_FONT, OnSelchangeListFont)
	ON_LBN_SELCHANGE(IDC_LIST_COLOR, OnSelchangeListColor)
	ON_BN_CLICKED(IDC_BUTTON_FONT_CHANGE, OnButtonFontChange)
	ON_BN_CLICKED(IDC_BUTTON_COLOR_CHANGE, OnButtonColorChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRosenFileProp_FontColor ���b�Z�[�W �n���h��

BOOL CDlgRosenFileProp_FontColor::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// --------------------------------
	//	�t�H���g���X�g�{�b�N�X
	// --------------------------------
	{
		CString	strLs ;
		GetDlgItem( IDC_LIST_FONT_ITEMS )->GetWindowText( strLs ) ;

		deque< string > arstr = splitc< deque< string > >( ',' , (LPCTSTR)strLs ) ;


		CListBox*	pListBox = (CListBox*)GetDlgItem( IDC_LIST_FONT ) ;
		int idx ;
		for ( idx = 0 ; idx < (int)arstr.size() ; idx ++ ){
			pListBox->AddString( arstr[ idx ].c_str() ) ;
		}
		pListBox->SetCurSel( 0 ) ; 
	}
	// --------------------------------
	//	�F���X�g�{�b�N�X
	// --------------------------------
	{
		CString	strLs ;
		GetDlgItem( IDC_LIST_COLOR_ITEMS )->GetWindowText( strLs ) ;

		deque< string > arstr = splitc< deque< string > >( ',' , (LPCTSTR)strLs ) ;


		CListBox*	pListBox = (CListBox*)GetDlgItem( IDC_LIST_COLOR ) ;
		int idx ;
		for ( idx = 0 ; idx < (int)arstr.size() ; idx ++ ){
			pListBox->AddString( arstr[ idx ].c_str() ) ;
		}
		pListBox->SetCurSel( 0 ) ; 
	}

	// --------------------------------
	//	�t�H���g���{
	// --------------------------------
	m_pdcdrawFont = new CDcdTextbox(
			 CdPenProp( 1 ) , 2 , 2 , 
			"�H��10 10:00" , CdDrawTextProp( ) ,  
			"" , 1 )  ;
	
	m_pdcdrawFontV = new CDcdTextboxV3(
		"�H��10 10:00" , CdFontProp() ,
		1 , 8 , 
		CdColorProp( 0 , 0 , 0 ) ,
		2 , 2 , 
		CdPenProp( 1 ) )  ;
	
	m_pdcdrawColor =new CDcdRectangle(
			 CdPenProp( 1 ) ) ;
	// --------------------------------
	updateUIState() ;

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CDlgRosenFileProp_FontColor::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	
	CDcdTargetOnPaint	aDcdTarget( GetSafeHwnd() , &dc.m_ps ) ;
	// --------------------------------
	//	�t�H���g�̌��{�\��
	// --------------------------------
	{
		CListBox*	pListBox = (CListBox*)GetDlgItem( IDC_LIST_FONT ) ;


		CRect	aRect = GetDlgControlRect( this , IDC_STATIC_FONT );

		CaDcdTargetItemPosition	aDcdTargetItemPosition( &aDcdTarget , 
			CdDcdZoneXy( CdDcdZone( aRect.left , aRect.right - aRect.left ) , 
				CdDcdZone( aRect.top , aRect.bottom - aRect.top ) ) ) ;
	
		if ( VerticalFontIsChoosed() )
		{
			m_pdcdrawFontV->DcDraw( &aDcdTargetItemPosition )  ;
		}
		else
		{
			m_pdcdrawFont->DcDraw( &aDcdTargetItemPosition ) ;
		}
	}
	// --------------------------------
	//	�F�̌��{�\��
	// --------------------------------
	{
		CRect	aRect = GetDlgControlRect( this , IDC_STATIC_COLOR );

		CaDcdTargetItemPosition	aDcdTargetItemPosition( &aDcdTarget , 
			CdDcdZoneXy( CdDcdZone( aRect.left , aRect.right - aRect.left ) , 
				CdDcdZone( aRect.top , aRect.bottom - aRect.top ) ) ) ;
		 
		m_pdcdrawColor->DcDraw( &aDcdTargetItemPosition ) ;				
	}
	
		

}

void CDlgRosenFileProp_FontColor::OnDestroy() 
{
	if ( m_pdcdrawColor != NULL ){
		delete m_pdcdrawColor ;
		m_pdcdrawColor = NULL ;
	}
	if ( m_pdcdrawFontV != NULL )
	{
		delete m_pdcdrawFontV ;
		m_pdcdrawFontV = NULL ;
	}
	if ( m_pdcdrawFont != NULL ){
		delete m_pdcdrawFont ;
		m_pdcdrawFont = NULL ;
	}
	CDialog::OnDestroy();
	

	
}

void CDlgRosenFileProp_FontColor::OnSelchangeListFont() 
{
	updateUIState() ;
	
}

void CDlgRosenFileProp_FontColor::OnSelchangeListColor() 
{
	updateUIState() ;
	
}

void CDlgRosenFileProp_FontColor::OnButtonFontChange() 
{
	// --------------------------------
	//	�t�H���g
	// --------------------------------
	{
		CListBox*	pListBox = (CListBox*)GetDlgItem( IDC_LIST_FONT ) ;
		
		int idx = pListBox->GetCurSel() ;
		CdFontProp*	pCdFontProp = NULL ;
		if ( 0 <= idx && idx < sizeof(m_arFontProp) / sizeof(m_arFontProp[0]) )
		{
			pCdFontProp = &m_arFontProp[idx] ;
		}
		// --------------------------------
		if ( pCdFontProp != NULL ){
			CConverter_WinGdi	aConverter ;
			CFontDialog	aCFontDialog( &aConverter.LOGFONTOf( *pCdFontProp ) , 
				CF_SCREENFONTS , NULL , this ) ;
			if ( aCFontDialog.DoModal() == IDOK ){
				pCdFontProp->setFacename( (LPCSTR)aCFontDialog.GetFaceName() ) ;
				pCdFontProp->setPointTextHeight( aCFontDialog.GetSize() / 10 ) ;
				pCdFontProp->setBold( aCFontDialog.IsBold() != FALSE ) ;
				pCdFontProp->setItaric( aCFontDialog.IsItalic() != FALSE ) ;
				pCdFontProp->setStrikeOut( aCFontDialog.IsStrikeOut()  != FALSE ) ;
				pCdFontProp->setUnderline( aCFontDialog.IsUnderline()  != FALSE ) ;

				updateUIState() ;
			}
		}
	}
	
}

void CDlgRosenFileProp_FontColor::OnButtonColorChange() 
{
	// --------------------------------
	//	�J���[
	// --------------------------------
	{
		CListBox*	pListBox = (CListBox*)GetDlgItem( IDC_LIST_COLOR ) ;
		
		int idx = pListBox->GetCurSel() ;
		COLORREF*	pColor = NULL ;
		if ( 0 <= idx && idx < sizeof(m_arColor) / sizeof(m_arColor[0]) ) 
		{
			pColor = &m_arColor[idx] ;
		}
		// --------------------------------
		if ( pColor != NULL ){
			CColorDialog	aCColorDialog( *pColor , 0 , this ) ;
			if ( aCColorDialog.DoModal() == IDOK ) { 
				*pColor = aCColorDialog.GetColor() ;

				updateUIState() ;
			}
		}
	}
	
}
} //namespace ViewRosen
