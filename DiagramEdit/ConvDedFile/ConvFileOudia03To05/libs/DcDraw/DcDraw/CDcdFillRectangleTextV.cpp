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
//	CDcdFillRectangleTextV.cpp
// ****************************************************************
*/
//#include "stdafx.h"

#include <deque>
using namespace std ;

#include "CDcdFillRectangleTextV.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/CConverter_WinGdi.h"
#include "str/CStrCharSizeMb.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

// ********************************
//	�R���X�g���N�^
// ********************************
CDcdFillRectangleTextV::CDcdFillRectangleTextV( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp  ,
		int						iLinesExtentX  ,
		int						iLinesExtentY  ,
		COLORREF	colorrefText , 
		int						logicalunitFrameWidth   ,
		int						logicalunitFrameHeight   ,
		const CdPenProp&		aCdPenProp ,
		const CdBrushProp& 		aCdBrushProp ,
		const tstring&			strExtent )
	: m_CDcdFillrect( aCdBrushProp ) 
	, m_CDcdRectangle(  aCdPenProp ) 
	, m_CDcdText( "" , CdDrawTextProp( aCdFontProp , CConverter_WinGdi().CdColorPropOf( colorrefText ) ) , strExtent)
	, m_logicalunitFrameWidth( logicalunitFrameWidth )
	, m_logicalunitFrameHeight( logicalunitFrameHeight )
	, m_strText( strText ) 
	, m_iLinesExtentX( iLinesExtentX )
	, m_iLinesExtentY( iLinesExtentY ) 
{
	if ( m_CDcdText.getExtent().empty() ){
		m_CDcdText.setExtent( "��" ) ;
	}
}


CDcdFillRectangleTextV::CDcdFillRectangleTextV( 
		const CdPenProp&		aCdPenProp ,
		int						logicalunitFrameWidth ,
		int						logicalunitFrameHeight ,
		const tstring&			strText ,
		const CdFontProp&	aCdFontProp ,
		int						iLinesExtentX ,
		int						iLinesExtentY ,
		COLORREF	colorrefText , 
		const CdBrushProp& 		aCdBrushProp ,
		const tstring&			strExtent 
	) 
	: m_CDcdFillrect( aCdBrushProp ) 
	, m_CDcdRectangle(  aCdPenProp ) 
	, m_CDcdText( "" , CdDrawTextProp( aCdFontProp , CConverter_WinGdi().CdColorPropOf( colorrefText ) ) , strExtent)
	, m_logicalunitFrameWidth( logicalunitFrameWidth )
	, m_logicalunitFrameHeight( logicalunitFrameHeight )
	, m_strText( strText ) 
	, m_iLinesExtentX( iLinesExtentX )
	, m_iLinesExtentY( iLinesExtentY ) 
{
	if ( m_CDcdText.getExtent().empty() ){
		m_CDcdText.setExtent( "��" ) ;
	}
}

CDcdFillRectangleTextV::CDcdFillRectangleTextV() 
	: m_logicalunitFrameWidth( 0 )
	, m_logicalunitFrameHeight( 0 )
	, m_iLinesExtentX ( 1 ) 
	, m_iLinesExtentY( 1 ) 
{
	if ( m_CDcdText.getExtent().empty() ){
		m_CDcdText.setExtent( "��" ) ;
	}
}
	
CDcdFillRectangleTextV::~CDcdFillRectangleTextV() 
{
}
// ********************************
//	IfDcDraw
// ********************************
bool CDcdFillRectangleTextV::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool	bRv = false ;

	//	�w�i�u���V
	{
		if ( m_CDcdFillrect.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}
	//	�g��
	{
		if ( m_CDcdRectangle.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}

	// --------------------------------
	//	�e�L�X�g
	// --------------------------------

	//	m_CDcdText �́A�㉺���E�����񂹂ɂ��܂��B
	//	����́A���p�����P������\������ۂɁA�����ɕ\�����邽�߂ł��B
	{
		CdDrawTextProp	aCdDrawTextProp = m_CDcdText.getCdDrawTextProp() ;
		aCdDrawTextProp.setCdDrawTextFormat( 
			CdDrawTextFormat(
				 CdDrawTextFormat::H_CENTER , 
				CdDrawTextFormat::V_SINGLELINT_CENTER 
			) 
		) ;
		m_CDcdText.setCdDrawTextProp( aCdDrawTextProp ) ;
	}

	CdDcdZoneXy	aCdDcdZoneXy ;
	{
		aCdDcdZoneXy = pIfDcdTarget->getZone() ;
		aCdDcdZoneXy.setX( CdDcdZone( 
			aCdDcdZoneXy.getX().getPos() + m_logicalunitFrameWidth , 
			aCdDcdZoneXy.getX().getSize() - m_logicalunitFrameWidth * 2 )
			)  ;
		aCdDcdZoneXy.setY( CdDcdZone( 
			aCdDcdZoneXy.getY().getPos() + m_logicalunitFrameHeight , 
			aCdDcdZoneXy.getY().getSize() - m_logicalunitFrameHeight * 2 )
			)  ;
	}
	//aCdDcdZoneXy = �e�L�X�g��`�悷��̈�ł��B
	//	IfDcdTarget�̗̈悩��A�㉺���E�̘g�̈���������̈�ł��B

	CdDcdSizeXy	sizeExtent ;
	{	
		bRv = m_CDcdText.getItemSize( pIfDcdTarget , &sizeExtent ) ;
		if ( !bRv ){
			return ( bRv ) ;
		}
		sizeExtent.setX( max( sizeExtent.getX() , sizeExtent.getY() ) ) ;
		sizeExtent.setY( sizeExtent.getX() ) ;
	}
	//sizeExtent = �e�L�X�g�P����������̃T�C�Y�B
	//	�������A�T�C�Y�͐����`�ɂȂ�悤�ɍœK�����܂��B
	//	�܂�AX,Y�̂����A�傫�����̕ӂɍ��킹�܂��B

	// ----------------------------------------------------------------
	//	�c�����t�H���g�𐶐�
	// ----------------------------------------------------------------
	HFONT hfontVertical = NULL ;
	{
		CdFontProp	aCdFontPropV = m_CDcdText.getCdDrawTextProp().getCdFontProp() ;
		string strFacename = aCdFontPropV.getFacename() ;
		if ( !( strFacename.size() >= 1 && strFacename.substr( 0 , 1 ) == "@" ) ){
			strFacename = string( "@" ) + strFacename ;
		}
		aCdFontPropV.setFacename( strFacename ) ;
		aCdFontPropV.setIsEscapementVertical() ;
		hfontVertical = pIfDcdTarget->CreateFont( aCdFontPropV ) ;

		if ( hfontVertical != NULL ){
			string strFacenameSelected  ;
			{
				HFONT hfontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , hfontVertical ) ;
				int iLen = GetTextFace( pIfDcdTarget->getHdc() , 0 , NULL ) ;
				vector<TCHAR>	szFace( iLen + 1 ) ;
				GetTextFace( pIfDcdTarget->getHdc() , (int)szFace.size() , &szFace[0] ) ;
				strFacenameSelected = &szFace[0] ;
				if ( hfontOld != NULL ){
					SelectObject( pIfDcdTarget->getHdc() , hfontOld ) ;
					hfontOld = NULL ;
				}
			}
			//strFacenameSelected = ���ۂɍ쐬���ꂽ�t�H���g��
			//	�^�C�v�t�F�C�X���B�v���ƈقȂ�ꍇ������܂��B

			if ( strFacenameSelected != aCdFontPropV.getFacename() ){
				hfontVertical = NULL ;
			}
		}
	}
	//hfontVertical = �c�����p�̃t�H���g
	//	�������A���Ғʂ�̃t�H���g�������ł��Ȃ�
	//	�i�v�������t�H���g�̃^�C�v�t�F�C�X���ƁA
	//	���ۂɐ��������t�H���g�̃^�C�v�t�F�C�X�����قȂ�j�ꍇ��
	//	NULL �Ƃ��܂��B
	//	���̏ꍇ�A�c�����t�H���g�͎g�p���܂���B

	// ----------------------------------------------------------------
	//	�c�����t�H���g���g���Ȃ��ꍇ�̂��߁A
	//	�ꕔ�̕�����ϊ��i"�[" �� "|"�Ɂj
	// ----------------------------------------------------------------
	string	strText = m_strText ;
	if ( hfontVertical == NULL ){
		//	"-","�|","�","�[" �́A�c�_�ɕύX���܂��B 
		CStrCharSizeMb	aCStrCharSizeMb( strText ) ;
		int iBidx = 0 ;
		for ( iBidx = 0 ; iBidx < aCStrCharSizeMb.ByteLength() ;
				iBidx = aCStrCharSizeMb.BidxNextChar( iBidx ) ){
			string strChar = strText.substr( iBidx , aCStrCharSizeMb.CsizeOfBidx( iBidx ) ) ;
			if ( strChar == "-" || strChar == "�|" ||
					strChar == "�" || strChar == "�[" ){
				strText.erase( iBidx , aCStrCharSizeMb.CsizeOfBidx( iBidx ) ) ;
				strText.insert( iBidx , "|" ) ;
				aCStrCharSizeMb.scan( strText ) ;
			}
		}
	}
	//strText = �c�����t�H���g���g���Ȃ��ꍇ�́A
	//	�ꕔ�̕�����ϊ��i"�[" �� "|"�Ɂj���܂����B

	// --------------------------------
	//	������`�悷��̂ɕK�v��
	//	�S�p�u���b�N�����J�E���g
	// --------------------------------
	deque<int> ariBidx ;
	{
		CStrCharSizeMb	aCStrCharSizeMb( strText ) ;
		int iBidx = 0 ;
		for ( iBidx = 0 ; iBidx < aCStrCharSizeMb.ByteLength() ;
				iBidx = aCStrCharSizeMb.BidxNextChar( iBidx ) ){
			ariBidx.push_back( iBidx ) ;
		}
		ariBidx.push_back( iBidx ) ;
	}
	//ariBidx=�����̎n�܂�̃C���f�N�X��ێ������z��ł��B
	//	�v�f���́A�������{�P�i���p�����E�S�p�������P�Ɛ����܂��j

	{
		for ( int idx = 0 ; idx < (int)ariBidx.size() - 2 ; idx ++ ){
			if ( ariBidx[idx] + 1 == ariBidx[idx+1] && 
					ariBidx[idx+1] + 1 == ariBidx[idx+2] ){
				//	���݂̈ʒu����́A�P�o�C�g�������Q�A�����Ă��܂��B
				//	����́A�Q�o�C�g���������ɂ��܂��B
				ariBidx.erase( ariBidx.begin() + idx + 1 , ariBidx.begin() + idx + 2 ) ;
			}
		}
	}
	//ariBidx=�����̎n�܂�̃C���f�N�X��ێ������z��ł�
	//	(1�o�C�g�������Q�A�����Ă���ꍇ�́A�Q�o�C�g��g�ɂ��܂�)�B
	//	�v�f���́A�S�p�������{�P
	//	�i���p�����Q�̑g�́A�S�p�������P�Ɛ����܂��B
	//	���p�������P��������ꍇ�́A�P�Ɛ����܂��B)

	int iLines = 0 ;	
	int iXOffset = 0 ;
	{
		iLines = ( (int)ariBidx.size() - 1 + m_iLinesExtentY - 1 ) 
			/ m_iLinesExtentY ;
		iXOffset = 
			( aCdDcdZoneXy.getX().getSize() - iLines * sizeExtent.getX() ) 
			/ 2 ;
	}
	//iLines = m_strText ��\������̂ɕK�v�ȁA�������̍s��
	//iXOffset = m_strText �̕`��́A���[�̍��W�B
	//	����́AaCdDcdZoneXy.X.Pos ����̃I�t�Z�b�g�ł�


	// --------------------------------
	//	�S�p�̃u���b�N�P�ʂŁA������`��
	// --------------------------------
	for ( int idxChar = 0 ; idxChar < (int)ariBidx.size() - 1 ; idxChar ++ ){
		int idxCharY = idxChar % m_iLinesExtentY ;
		int idxCharX = idxChar / m_iLinesExtentY ;
		
		CdDcdZoneXy	zoneChar( 
			CdDcdZone( 
				aCdDcdZoneXy.getX().getPos() + iXOffset + 
				( iLines - 1 - idxCharX ) * sizeExtent.getX() ,
				sizeExtent.getX() ) ,
			CdDcdZone( 
				aCdDcdZoneXy.getY().getPos() + idxCharY * sizeExtent.getY() ,
				sizeExtent.getY() ) 
		) ;
		string strChar = strText.substr( 
			ariBidx[idxChar], 
			ariBidx[idxChar+1] - ariBidx[idxChar] ) ;
		//strChar=����\�����镶���ł��B
		//	�S�p�����̏ꍇ�͂P�����ƂȂ�܂����A
		//	���p�����̏ꍇ�́A���p�������Q�A�����Ă���ꍇ�͂Q�����A
		//	���p�������P�̏ꍇ�͂P�����ƂȂ�܂��B

		CStrCharSizeMb	aCStrCharSizeMb( strChar ) ;
		if ( aCStrCharSizeMb.CsizeOfBidx( 0 ) > 1 && hfontVertical != NULL ){
			// --------------------------------
			//	�S�p�����i�P�����j
			// --------------------------------
			CConverter_WinGdi	aConv ;
			
			HFONT hfontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , hfontVertical ) ;
			int iBkModeOld = SetBkMode( pIfDcdTarget->getHdc() , TRANSPARENT ) ;
			COLORREF colTextColorOld = SetTextColor( 
				pIfDcdTarget->getHdc() , 
				aConv.COLORREFOf( m_CDcdText.getCdDrawTextProp().getTextColor() ) ) ;

			TextOut( pIfDcdTarget->getHdc() , 
				zoneChar.getX().getEndPos() + 1 ,	//	���́{�P�́A���ۂ̉�ʂ�������Œ��������l
				zoneChar.getY().getPos() , 
				strChar.c_str() , 
				(int)strChar.size() ) ;
			
			SetTextColor( pIfDcdTarget->getHdc() , colTextColorOld ) ;
			SetBkMode( pIfDcdTarget->getHdc() , iBkModeOld ) ;
			if ( hfontOld != NULL ){
				SelectObject( pIfDcdTarget->getHdc() , hfontOld ) ;
				hfontOld = NULL ;
			}
			bRv = true ;
		}	else	{
			// --------------------------------
			//	���p�����i�P�������Q�����j
			//	����́A�ʏ�̃t�H���g�ŕ`�悵�܂��B
			// --------------------------------
		m_CDcdText.setText( strChar ) ;
		
		CaDcdTargetItemPosition	aTarget( pIfDcdTarget ,  zoneChar ) ;
		if ( m_CDcdText.DcDraw( &aTarget ) ) {
			bRv = true ;
		}
	} 
	} 
	
	return ( bRv ) ;
}
	
bool CDcdFillRectangleTextV::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	bool bRv = false ;
	CdDcdSizeXy	sizeExtent ;
	{	
		bRv = m_CDcdText.getItemSize( pIfDcdTarget , &sizeExtent ) ;
		if ( !bRv ){
			return ( bRv ) ;
		}
		sizeExtent.setX( max( sizeExtent.getX() , sizeExtent.getY() ) ) ;
		sizeExtent.setY( sizeExtent.getX() ) ;
	}
	//sizeExtent = �e�L�X�g�P����������̃T�C�Y�B
	//	�������A�T�C�Y�͐����`�ɂȂ�悤�ɍœK�����܂��B
	//	�܂�AX,Y�̂����A�傫�����̕ӂɍ��킹�܂��B


	pCdDcdSizeXy->setX( sizeExtent.getX() * m_iLinesExtentX + m_logicalunitFrameWidth * 2 ) ;
	pCdDcdSizeXy->setY( sizeExtent.getY() * m_iLinesExtentY + m_logicalunitFrameHeight * 2 ) ;
	return ( true ) ;
	}
