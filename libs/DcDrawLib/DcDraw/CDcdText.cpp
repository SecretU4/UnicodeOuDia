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
//	CDcdText.cpp
// ****************************************************************
*/
#include "./CDcdText.h"
#include "./CConverter_WinGdi.h"
#include "./CdWinGdi_DrawText_Format.h"

namespace DcDrawLib{
namespace DcDraw{

using namespace std ;
// ****************************************************************
//	CDcdText
// ****************************************************************
CDcdText::CDcdText( 
		const tstring&			strText,
		const CdDrawTextProp&	aCdDrawTextProp = CdDrawTextProp() ,
		const tstring&			strExtent ,
		int						iLinesExtent
	) :
	m_strText( strText ) ,
	m_CdDrawTextProp( aCdDrawTextProp ) ,
	m_strExtent( strExtent ) ,
	m_iLinesExtent( iLinesExtent ) 
{
	if ( m_CdDrawTextProp.getCdFontProp().getPointTextHeight() == 0 && 
		m_CdDrawTextProp.getCdFontProp().getLogicalunitTextHeight() == 0 && 
		m_CdDrawTextProp.getCdFontProp().getLogicalunitCellHeight() == 0 ){
		m_CdDrawTextProp.setCdFontProp( 
			CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
	}
}

	
CDcdText::CDcdText() :
	m_iLinesExtent( 1 ) 
{
}
	
CDcdText::~CDcdText() 
{
}
	
// ********************************
//	IfDcDraw
// ********************************
bool CDcdText::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	int		iRv = 0 ;
	bool	bRv = false ;
	
	// --------------------------------
	//	�t�H���g�̐���
	// --------------------------------

	Ou<CGdiHFontHolder> pFontHolder ;

	if ( iRv >= 0 && pFontHolder == NULL ){
		pFontHolder = pIfDcdTarget->createGdiHFontHolder( m_CdDrawTextProp.getCdFontProp() ) ;

		if ( pFontHolder == NULL ){
			iRv = -1 ;	//	�t�H���g�̍쐬�Ɏ��s���܂����B
		}
	}
	// --------------------------------
	bool	bSelectTool = false ;
	COLORREF	colorrefLTextSid = 0xffffffff;
	COLORREF	colorrefLBackSid = 0xffffffff;
	int			iLBkModeSid = -1 ;
	HFONT		hFontSid = NULL ;
	if ( iRv >= 0 ){
		bSelectTool = true ;
		hFontSid = (HFONT)SelectObject( pIfDcdTarget->getHdc() , pFontHolder->getHFont() ) ;

		CConverter_WinGdi	aConv ;
		colorrefLTextSid = SetTextColor( 
			pIfDcdTarget->getHdc() , 
			aConv.COLORREFOf( m_CdDrawTextProp.getTextColor() ) ) ;
		colorrefLBackSid = SetBkColor( 
			pIfDcdTarget->getHdc() , 	
			aConv.COLORREFOf( m_CdDrawTextProp.getBackColor() ) ) ;
		int	iLBkMode = TRANSPARENT ;
		if ( m_CdDrawTextProp.getIsOpaque() ){
			iLBkMode = OPAQUE ;
		}
		iLBkModeSid = SetBkMode( pIfDcdTarget->getHdc() , iLBkMode ) ;
	}
	
	if ( iRv >= 0 ){
		RECT	aRect ;
		aRect.left = pIfDcdTarget->getZone().getX().getPos() ;
		aRect.right = pIfDcdTarget->getZone().getX().getEndPos() ;
		aRect.top = pIfDcdTarget->getZone().getY().getPos() ;
		aRect.bottom = pIfDcdTarget->getZone().getY().getEndPos() ;
		DrawText( pIfDcdTarget->getHdc() , m_strText.c_str() , -1 ,
			&aRect , 
			CConverter_WinGdi().CdWinGdi_DrawText_FormatOf( 
				m_CdDrawTextProp.getCdDrawTextFormat() ) ) ;
		bRv = true ;
	}
	//--------------------------------
	if ( bSelectTool ){
		SetBkMode( pIfDcdTarget->getHdc() , iLBkModeSid  ) ;
		iLBkModeSid = -1 ;
		SetTextColor( pIfDcdTarget->getHdc() , colorrefLTextSid ) ;
		colorrefLTextSid = 0xffffffff ;
		SetBkColor( pIfDcdTarget->getHdc() , colorrefLBackSid ) ;
		colorrefLBackSid = 0xffffffff;
		SelectObject( pIfDcdTarget->getHdc() , hFontSid ) ;
		hFontSid = NULL ;
	}

	return ( bRv ) ;
}
	
bool CDcdText::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	int		iRv = 0 ;
	bool	bRv = false ;
	// --------------------------------
	//	�t�H���g�̐���
	// --------------------------------
	Ou<CGdiHFontHolder> pFontHolder ;
	if ( iRv >= 0 ){
		pFontHolder = pIfDcdTarget->createGdiHFontHolder( m_CdDrawTextProp.getCdFontProp() ) ;
		if ( pFontHolder == NULL ){
			iRv = -1 ;	//	�t�H���g�̍쐬�Ɏ��s���܂����B
		}
	}
	//--------------------------------
	//	GDI�I�u�W�F�N�g�̑I��
	//--------------------------------
	bool	bSelectTool = false ;
	COLORREF	colorrefLTextSid = 0xffffffff;
	COLORREF	colorrefLBackSid = 0xffffffff;
	HFONT		hFontSid = NULL ;
	if ( iRv >= 0 )
	{
		bSelectTool = true ;
		hFontSid = (HFONT)SelectObject( pIfDcdTarget->getHdc() , pFontHolder->getHFont() ) ;

		CConverter_WinGdi	aConv ;
		colorrefLTextSid = SetTextColor( 
			pIfDcdTarget->getHdc() , 
			aConv.COLORREFOf( m_CdDrawTextProp.getTextColor() ) ) ;
		colorrefLBackSid = SetBkColor( 
			pIfDcdTarget->getHdc() , 	
			aConv.COLORREFOf( m_CdDrawTextProp.getBackColor() ) ) ;
	}
	//--------------------------------
	
	string strExtent ;
	if ( iRv >= 0 ){
		strExtent = m_strExtent ;
		if ( strExtent.empty() ){
			strExtent = m_strText ;
		}
	}
	//strExtent = �e�L�X�g�̕��̌v�Z�̊�ƂȂ镶����B

	if ( iRv >= 0 ){
		//--------------------------------
		//	�e�L�X�g�̉����̌v�Z
		//--------------------------------
		{
			tstring	strLs ;
			strLs += strExtent ;
			CdWinGdi_DrawText_Format	aFlag( 
				CConverter_WinGdi().CdWinGdi_DrawText_FormatOf(
					m_CdDrawTextProp.getCdDrawTextFormat() ) ) ;
			aFlag.setCalcrect( CdWinGdi_DrawText_Format::CALCRECT )
				.setVertical( CdWinGdi_DrawText_Format::V_SINGLELINE_TOP )
				.setEllipses( CdWinGdi_DrawText_Format::NOELLIPSIS )  ;
			//aFlag = �w��̃t�H�[�}�b�g��P��s�E
			//	�ȗ��L���Ȃ��E�T�C�Y�v�Z�ɏC�����܂���

			RECT	aRect ;
			memset( &aRect , 0 , sizeof(aRect) ) ;
			DrawText(  pIfDcdTarget->getHdc() , 
					strLs.c_str() , -1 , &aRect , aFlag ) ;
				//LRect.right = �e�L�X�g m_strExtent �̕�
			pCdDcdSizeXy->setX( aRect.right - aRect.left ) ;
		}
		//--------------------------------
		//	�e�L�X�g�̍����̌v�Z
		//--------------------------------
		{
			tstring	strLs ;
			int	iLi ;
			for ( iLi = 0 ; iLi < m_iLinesExtent ; iLi ++ ){
				if ( iLi > 0 ){
					strLs += TEXT( '\n' ) ;
				}
				strLs += strExtent.c_str() ;
			}
				//strLs = m_strExtent���w��̍s���������c�ɕ��ׂ�������
			
			CdWinGdi_DrawText_Format	aFlag( 
				CConverter_WinGdi().CdWinGdi_DrawText_FormatOf( 
					m_CdDrawTextProp.getCdDrawTextFormat() ) ) ;
			aFlag.setCalcrect( CdWinGdi_DrawText_Format::CALCRECT )
				.setVertical( CdWinGdi_DrawText_Format::V_MULTILINE )
				.setEllipses( CdWinGdi_DrawText_Format::NOELLIPSIS )  ;
			//aFlag = �w��̃t�H�[�}�b�g�𕡐��s�E
			//	�ȗ��L���Ȃ��E�T�C�Y�v�Z�ɏC�����܂���

			RECT	aRect ;
			memset( &aRect , 0 , sizeof(aRect) ) ;
			DrawText( pIfDcdTarget->getHdc() , 
				strLs.c_str() , -1 , &aRect , aFlag ) ;
			//LRect.bottom = �e�L�X�g m_strExtent �̍���
			
			pCdDcdSizeXy->setY( aRect.bottom - aRect.top ) ;
		}		
	}
	//--------------------------------
	if ( bSelectTool ){
		SetTextColor( pIfDcdTarget->getHdc() , colorrefLTextSid ) ;
		colorrefLTextSid = 0xffffffff ;
		SetBkColor( pIfDcdTarget->getHdc() , colorrefLBackSid ) ;
		colorrefLBackSid = 0xffffffff;
		SelectObject( pIfDcdTarget->getHdc() , hFontSid ) ;
		hFontSid = NULL ;
	}
	return ( iRv >= 0 ) ;

}

} //namespace DcDraw
} //namespace DcDrawLib
