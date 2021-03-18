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
//	CDcdTextboxV3.cpp
// ****************************************************************
*/
#include <deque>
#include "str\CStrCharSizeMb.h"
#include "NsMu\CMup_deque.h"
#include "logmsg\logmsg.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DcDraw\CVerticalTextElement.h"
#include "DcDraw\CVerticalTextElementBuilder.h"
#include "CDcdTextboxV3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

namespace DcDrawLib{
namespace DcDraw{
	using namespace OuLib::Str ;
// ****************************************************************
//	CDcdTextboxV3
// ****************************************************************
// --------------------------------
//@name �����֐�
// --------------------------------

Ou<CGdiHFontHolder> CDcdTextboxV3::CreateVFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ) 
{
	Ou<CGdiHFontHolder> pfontVertical ;
	{
		CdFontProp	aCdFontPropV = fontHorizontal ;
		aCdFontPropV.setIsEscapementVertical() ;
		pfontVertical = pIfDcdTarget->createGdiHFontHolder( aCdFontPropV ) ;
	}
	return ( pfontVertical ) ;
}

Ou<CGdiHFontHolder> CDcdTextboxV3::CreateHFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ) 
{
	Ou<CGdiHFontHolder> pfontVertical ;
	{
		CdFontProp	aCdFontPropV = fontHorizontal ;
		aCdFontPropV.setIsEscapementHolyzontal() ;
		pfontVertical = pIfDcdTarget->createGdiHFontHolder( aCdFontPropV ) ;
	}
	return ( pfontVertical ) ;
}


CdDcdSizeXy CDcdTextboxV3::calcZenkakuCharExtent(
		IfDcdTarget* pIfDcdTarget , const CdFontProp& aCdFontProp ) 
{
	CdDcdSizeXy	sizeExtent ;
	{
		Ou<CGdiHFontHolder> pFontHolder = pIfDcdTarget->createGdiHFontHolder( aCdFontProp ) ;
		// --------------------------------
		HFONT hFontOld = (HFONT)SelectObject( 
			pIfDcdTarget->getHdc() , 
			pFontHolder->getHFont() ) ;
		TEXTMETRIC	aTEXTMETRIC ;
		GetTextMetrics( pIfDcdTarget->getHdc() , &aTEXTMETRIC ) ;

		//	TEXTMETRIC::tmMaxCharWidth �́AWindows7�傫����(���{��ɂ�)
		//	Windows7��Windows10�Ƃł́AGetTextMetrics() �֐��ɂ���ē����� 
		//	TEXTMETRIC::tmMaxCharWidth
		//	(https://msdn.microsoft.com/en-us/library/windows/desktop/dd145132(v=vs.85).aspx) 
		//	�̒l���قȂ�܂��B
		//	"���l�r �S�V�b�N" ��9�|�C���g�̃t�H���g�̏ꍇ�ATEXTMETRIC::tmMaxCharWidth �̒l�́A
		//	Windows7�ł� 13�AWindows10 �ł� 24 �ƂȂ�܂��B
		//	Windows10 ��24�͗]��ɂ��傫�����܂��B���̂��߁A�����̃T�C�Y��
		//	TEXTMETRIC.tmHeight ���������ƂɌ��߂邱�Ƃɂ��܂����B
		
		//// �ȑO�̃R�[�h
		//	sizeExtent.setX( aTEXTMETRIC.tmHeight ) ;
		//	sizeExtent.setY( aTEXTMETRIC.tmMaxCharWidth ) ;
		//	sizeExtent.setX( max( sizeExtent.getX() , sizeExtent.getY() ) ) ;
		//	sizeExtent.setY( sizeExtent.getX() ) ;

		sizeExtent.setX( aTEXTMETRIC.tmHeight ).setY( aTEXTMETRIC.tmHeight ) ;

		// --------------------------------
		if ( hFontOld != NULL ){
			SelectObject( pIfDcdTarget->getHdc() , hFontOld ) ;
		}
	}
	return sizeExtent ;
}


CDcdText CDcdTextboxV3::createCDcdTextH( 
		const CdFontProp&	aCdFontPropArg , 
		const CdColorProp& colorrefText ) 
{
	CdFontProp	aCdFontProp = aCdFontPropArg ;
	aCdFontProp.setIsEscapementHolyzontal() ;

	CDcdText	aCDcdText( 
		"" , 
		CdDrawTextProp( aCdFontProp , colorrefText ) , 
		"00" ) ;
	//	aCDcdText �́A�㉺���E�����񂹂ɂ��܂��B
	//	����́A���p�����P������\������ۂɁA�����ɕ\�����邽�߂ł��B
	{
		CdDrawTextProp	aCdDrawTextProp = aCDcdText.getCdDrawTextProp() ;
		aCdDrawTextProp.setCdDrawTextFormat( 
			CdDrawTextFormat(
				 CdDrawTextFormat::H_CENTER , 
				CdDrawTextFormat::V_SINGLELINT_CENTER 
			) 
		) ;
		aCDcdText.setCdDrawTextProp( aCdDrawTextProp ) ;
	}
	return aCDcdText ;
}


int CDcdTextboxV3::VerticalTextElementToElementPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aCdFontProp ,
		const Mu<CVerticalTextElement>* pCStrElementCont ,
		Mui<CStrElementPlace>* pCStrElementPlaceCont ) 
{
	int iRv = 0 ;
	
	// --------------------------------
	CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;
	pCStrElementPlaceCont->erase( 0 , INT_MAX ) ;
	// --------------------------------
	//	�t�H���g���쐬
	// --------------------------------
	Ou<CGdiHFontHolder> fontVertical ; 
	Ou<CGdiHFontHolder> fontHolyzontal ; 
	{
		fontVertical = CreateVFont( 
			pIfDcdTarget , aCdFontProp ) ;
		fontHolyzontal = CreateHFont( 
			pIfDcdTarget , aCdFontProp ) ;
	}
	CDcdText aCDcdText( createCDcdTextH( 
				aCdFontProp , CdColorProp( 0 , 0 , 0 ) ) ) ;
	//aCDcdText = �������e�L�X�g�p�́ADcDraw�I�u�W�F�N�g
	// --------------------------------
	int logicalunitYOffset = 0 ;	//���݂́ADcDraw�̈�㕔�����Y���W
	int iXLineNumber = 0 ;			//���݂́AX�����̍s�ԍ�
	
	int idxMojiretsuyousoCont ;
	for ( idxMojiretsuyousoCont = 0 ; 
			idxMojiretsuyousoCont < pCStrElementCont->size() ;){
		CVerticalTextElement	aCStrElement = 
			pCStrElementCont->get( idxMojiretsuyousoCont ) ;

		//	�c����(���p�E�S�p)
		if ( aCStrElement.getType() == CVerticalTextElement::V_ZENKAKU || 
				aCStrElement.getType() == CVerticalTextElement::V_HANKAKU )
		{
			HFONT hFontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , 
				fontVertical->getHFont() ) ;
			// --------------------------------
			//	����������̌������s�����߂ɁA
			//	������ނ̘A�������w����������x��
			//	�I�[��T���܂��B
			//	�A���A�s�ɕ\���ł��Ȃ��ꍇ�́A
			//	������ł��؂�܂��B
			// --------------------------------
			string strMojiretsu ;
			int idxMojiretsuyousoEnd = idxMojiretsuyousoCont ;
			int logicalunitYSize = 0 ;
			int iXLineWidth = 0 ;
			for ( idxMojiretsuyousoEnd = idxMojiretsuyousoCont ;
				idxMojiretsuyousoEnd < pCStrElementCont->size() ;
				idxMojiretsuyousoEnd ++ ){
				CVerticalTextElement	aCStrElementEnd = 
					pCStrElementCont->get( idxMojiretsuyousoEnd ) ;

				
				if ( aCStrElementEnd.getType() != 
						aCStrElement.getType() )
				{
					//	����́w����������x�́A idxMojiretsuyousoCont �̈ʒu��
					//	�w����������x�Ƃ͎�ނ��قȂ�܂��B
					break ;
				}


				string aString = strMojiretsu + 
					aCStrElementEnd.getString() ;
				SIZE	aSize ;
				GetTextExtentPoint32( 
					pIfDcdTarget->getHdc() , 
					aString.c_str() , 
					(int)aString.size() , 
					&aSize ) ;
				//
				if ( logicalunitYOffset + aSize.cx <= 
						zonexyTarget.getY().getSize() || 
					( logicalunitYOffset == 0 && strMojiretsu.size() == 0 ) ){
					//	����̕����́A���̍s�iiXLineNumber �̍s�j��
					//	�\���ł��܂��B
					//
					//	���@�s�̐擪�ɂ͕K���P�w����������x��
					//	���݂�����K�v������܂��B
					strMojiretsu = aString ;
					logicalunitYSize = aSize.cx ;
					iXLineWidth = aSize.cy ;
				}	else	{
					break ;
				}
			}
			//idxMojiretsuyousoEnd = ���������w����������x�̎��̃C���f�N�X
			//	�w����������x�����݂̍s�iiXLineNumber�j�Ɉ���`��ł��Ȃ�
			//	�ꍇ�́A
			//	idxMojiretsuyousoCont == idxMojiretsuyousoEnd �ƂȂ�܂��B
			//strMojiretsu = �������ꂽ���ʂ̕�����
			//logicalunitYSize = �������ꂽ���ʂ̕�����́AY�����̃T�C�Y
			//	�i�_���P�ʁj


			if ( idxMojiretsuyousoCont == idxMojiretsuyousoEnd )
			{
				//	1�������\���ł��Ȃ������ꍇ�́A
				//	���̍s�ւ̕\�������݂܂��B
				logicalunitYOffset = 0 ;
				iXLineNumber ++ ;
				continue ;
			}
			//	�������ʂ����ƂɁACStrElementPlace �I�u�W�F�N�g�𐶐����A
			//	�R���e�i�Ɋi�[���܂��B
			CStrElementPlace aCStrElementPlace( 
				CVerticalTextElement( strMojiretsu , aCStrElement.getType() ) ,
				logicalunitYOffset , iXLineNumber , iXLineWidth ) ;
			pCStrElementPlaceCont->insert( aCStrElementPlace ) ;
			
			//���݂́ADcDraw�̈�㕔�����Y���W���A��ɐi�߂�
			logicalunitYOffset += logicalunitYSize ;

			idxMojiretsuyousoCont = idxMojiretsuyousoEnd ;
			// --------------------------------
			SelectObject( pIfDcdTarget->getHdc() , hFontOld ) ;
			hFontOld = NULL ;
		}
		//	������������
		else if ( aCStrElement.getType() == 
				CVerticalTextElement::H_HANKAKU )
		{
			// --------------------------------
			//	������ނ̘A�������w����������x��
			//	�����͍s���܂���B
			// --------------------------------
			string strMojiretsu ;
			int idxMojiretsuyousoEnd = idxMojiretsuyousoCont ;
			int logicalunitYSize = 0 ;
			int iXLineWidth = 0 ;
			{
				CVerticalTextElement	aCStrElementEnd = 
					pCStrElementCont->get( idxMojiretsuyousoEnd ) ;
				
				string aString = strMojiretsu + 
					aCStrElementEnd.getString() ;
				aCDcdText.setText( aString ) ;
				CdDcdSizeXy aCdDcdSizeXy ;
				aCDcdText.getItemSize( pIfDcdTarget , &aCdDcdSizeXy ) ;

				if ( logicalunitYOffset + aCdDcdSizeXy.getY() <= 
						zonexyTarget.getY().getSize() || 
					( logicalunitYOffset == 0 && strMojiretsu.size() == 0 ) )
				{
					//	����̕����́A���̍s�iiXLineNumber �̍s�j��
					//	�\���ł��܂��B
					//
					//	���@�s�̐擪�ɂ͕K���P�w����������x��
					//	���݂�����K�v������܂��B
					strMojiretsu = aString ;
					logicalunitYSize = aCdDcdSizeXy.getY() ;
					iXLineWidth = aCdDcdSizeXy.getX() ;
					idxMojiretsuyousoEnd ++ ;
				}
			}
			//idxMojiretsuyousoEnd = ���������w����������x�̎��̃C���f�N�X
			//	�w����������x�����݂̍s�iiXLineNumber�j�Ɉ���`��ł��Ȃ�
			//	�ꍇ�́A
			//	idxMojiretsuyousoCont == idxMojiretsuyousoEnd �ƂȂ�܂��B
			//strMojiretsu = �������ꂽ���ʂ̕�����
			//logicalunitYSize = �������ꂽ���ʂ̕�����́AY�����̃T�C�Y
			//	�i�_���P�ʁj

			if ( idxMojiretsuyousoCont == idxMojiretsuyousoEnd )
			{
				//	1�������\���ł��Ȃ������ꍇ�́A
				//	���̍s�ւ̕\�������݂܂��B
				logicalunitYOffset = 0 ;
				iXLineNumber ++ ;
				continue ;
			}
			CStrElementPlace aCStrElementPlace( 
				CVerticalTextElement( strMojiretsu , aCStrElement.getType() ) ,
				logicalunitYOffset , iXLineNumber , iXLineWidth ) ;
			pCStrElementPlaceCont->insert( aCStrElementPlace ) ;

			//���݂́ADcDraw�̈�㕔�����Y���W���A��ɐi�߂�
			logicalunitYOffset += logicalunitYSize ;

			idxMojiretsuyousoCont = idxMojiretsuyousoEnd ;
		}
	}
	
	//debug
	{
		CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;
		LogMsgL(3, "CDcdTextboxV3::MojiretsuyousoToMojiretsuyousoPlace"
			"(X.Pos=%d X.Size=%d Y.Pos=%d Y.Size=%d)" , 
			zonexyTarget.getX().getPos() , 
			zonexyTarget.getX().getSize() , 
			zonexyTarget.getY().getPos() , 
			zonexyTarget.getY().getSize() ) ;
		int idx ;
		for ( idx = 0 ; idx < pCStrElementPlaceCont->size() ; idx ++ ){
			CStrElementPlace aCStrElementPlace = 
				pCStrElementPlaceCont->get( idx ) ;
			LogMsgL(3, "\t[%d] \"%s\" %d iY=%d iX=%d iXLineWidth=%d" ,
				idx , 
				aCStrElementPlace.getCStrElement().getString().c_str() ,
				aCStrElementPlace.getCStrElement().getType() ,
				aCStrElementPlace.getYOffset() ,
				aCStrElementPlace.getXLineNumber() , 
				aCStrElementPlace.getXLineWidth() ) ;

		}
	}
	
	
	
	// --------------------------------
	return ( iRv ) ;
}

bool CDcdTextboxV3::DcDrawElementPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& aFontProp ,
		const CdColorProp&  colorTextColor , 
		const Mu<CStrElementPlace>* pCStrElementPlaceCont ) 
{
	bool bRv = false ;

	// --------------------------------
	CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;

	// --------------------------------
	//	�t�H���g���쐬
	// --------------------------------
	Ou<CGdiHFontHolder>  pfontVertical = CreateVFont( 
		pIfDcdTarget , 
		aFontProp ) ; 
	CdDcdSizeXy	sizeExtent = calcZenkakuCharExtent( pIfDcdTarget , aFontProp) ;
	//hFontVertical = �c�����̃t�H���g
	//sizeExtent = �e�L�X�g�S�p�{�b�N�X�P����������̃T�C�Y�B
	//	�������A�T�C�Y�͐����`�ɂȂ�悤�ɍœK�����܂��B
	//	�܂�AX,Y�̂����A�傫�����̕ӂɍ��킹�܂��B
	
	CDcdText aCDcdText( createCDcdTextH( 
				aFontProp , colorTextColor ) ) ;
	//aCDcdText = �������e�L�X�g�p�́ADcDraw�I�u�W�F�N�g
	// --------------------------------
	int iLines = 1 ;
	if ( pCStrElementPlaceCont->size() > 0 ){
		iLines = pCStrElementPlaceCont->get( INT_MAX ).getXLineNumber() 
			+ 1 ;
	}
	//iLines = X�����̍s��

	int iXOffset = 0 ;
	{
		iXOffset = 
			( zonexyTarget.getX().getSize() - iLines * sizeExtent.getX() ) 
			/ 2 ;
	}
	//iXOffset = m_strText �̕`��́A���[�̍��W�B
	//	����́AzonexyTarget.X.Pos ����̃I�t�Z�b�g�ł�

	// --------------------------------
	//	������`��
	// --------------------------------
	for ( int idxCStrElementPlaceCont = 0 ;
			idxCStrElementPlaceCont < pCStrElementPlaceCont->size() ;
			idxCStrElementPlaceCont ++ ){
		CStrElementPlace	aCStrElementPlace = 
			pCStrElementPlaceCont->get( idxCStrElementPlaceCont ) ;
		CVerticalTextElement	aCStrElement = 
			aCStrElementPlace.getCStrElement() ;
		
		int iXPos = zonexyTarget.getX().getPos() + iXOffset + 
				( iLines - 1 - aCStrElementPlace.getXLineNumber() ) 
				* sizeExtent.getX() ;
		int iYPos = zonexyTarget.getY().getPos() + 
				aCStrElementPlace.getYOffset() ;
		string strChar = aCStrElement.getString() ;
		
		if ( aCStrElement.getType() == CVerticalTextElement::V_ZENKAKU || 
				aCStrElement.getType() == CVerticalTextElement::V_HANKAKU )
		{
			// --------------------------------
			//	�c�����t�H���g
			// --------------------------------
			HFONT hfontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , 
				pfontVertical->getHFont() ) ;
			int iBkModeOld = SetBkMode( pIfDcdTarget->getHdc() , 
				TRANSPARENT ) ;
			CConverter_WinGdi	aConv ;
			COLORREF colTextColorOld = SetTextColor( 
				pIfDcdTarget->getHdc() , 
				aConv.COLORREFOf( colorTextColor ) ) ;
			// --------------------------------
			TextOut( pIfDcdTarget->getHdc() , 
				//	���́{�P�́A���ۂ̉�ʂ�������Œ��������l
				iXPos + sizeExtent.getX() + 1 
					- ( sizeExtent.getX() - aCStrElementPlace.getXLineWidth() ) / 2 ,
				iYPos , 
				strChar.c_str() , 
				(int)strChar.size() ) ;
			// --------------------------------
			SetTextColor( pIfDcdTarget->getHdc() , colTextColorOld ) ;
			SetBkMode( pIfDcdTarget->getHdc() , iBkModeOld ) ;
			if ( hfontOld != NULL ){
				SelectObject( pIfDcdTarget->getHdc() , hfontOld ) ;
				hfontOld = NULL ;
			}
			bRv = true ;
		}	else if ( aCStrElement.getType() == 
				CVerticalTextElement::H_HANKAKU ){
			// --------------------------------
			//	�������t�H���g
			// --------------------------------
			CdDcdZoneXy	zoneChar( 
				CdDcdZone( iXPos, sizeExtent.getX() ) , 
				CdDcdZone( iYPos , sizeExtent.getY() ) ) ;
			aCDcdText.setText( strChar ) ;
			CaDcdTargetItemPosition	aTarget( pIfDcdTarget ,  zoneChar ) ;
			if ( aCDcdText.DcDraw( &aTarget ) ) {
				bRv = true ;
			}
		}
	}


	return ( bRv ) ;
}


// ********************************
//	�R���X�g���N�^
// ********************************

CDcdTextboxV3::CDcdTextboxV3( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp  ,
		int						iLinesExtentX  ,
		int						iLinesExtentY  ,
		const CdColorProp&	colorrefText , 
		int						logicalunitFrameWidth   ,
		int						logicalunitFrameHeight   ,
		const CdPenProp&		aCdPenProp ,
		const CdBrushProp& 		aCdBrushProp ) 
	: m_CDcdFillrect( aCdBrushProp ) 
	, m_CDcdRectangle(  aCdPenProp ) 
	, m_strText( strText ) 
	, m_CdFontProp( aCdFontProp ) 
	, m_iLinesExtentX( iLinesExtentX )
	, m_iLinesExtentY( iLinesExtentY ) 
	, m_colorrefText( colorrefText ) 
	, m_logicalunitFrameWidth( logicalunitFrameWidth )
	, m_logicalunitFrameHeight( logicalunitFrameHeight )
{
}



CDcdTextboxV3::CDcdTextboxV3() 
	: m_iLinesExtentX ( 1 ) 
	, m_iLinesExtentY( 1 ) 
	, m_colorrefText( CdColorProp( 0 , 0 , 0 ) ) 
	, m_logicalunitFrameWidth( 0 )
	, m_logicalunitFrameHeight( 0 )
{
}
	
CDcdTextboxV3::~CDcdTextboxV3() 
{
}
// ********************************
//	IfDcDraw
// ********************************
bool CDcdTextboxV3::DcDraw( IfDcdTarget* pIfDcdTarget ) 
{
	bool	bRv = false ;

	// --------------------------------
	//	�w�i�u���V�̕`��
	// --------------------------------
	{
		if ( m_CDcdFillrect.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}
	// --------------------------------
	//	�g���̕`��
	// --------------------------------
	{
		if ( m_CDcdRectangle.DcDraw( pIfDcdTarget ) ) {
			bRv = true ;
		}
	}

	// ********************************
	//	�e�L�X�g�̕`��
	// ********************************
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

	{
		CaDcdTargetItemPosition aCaDcdTargetItemPosition( 
			pIfDcdTarget , 
			aCdDcdZoneXy ) ;
		CMup_deque<CVerticalTextElement> aCStrElementCont ;

		CVerticalTextElementBuilder::scan( m_strText , &aCStrElementCont ,m_CdFontProp.isVerticalFacename()) ;

		CMup_deque<CStrElementPlace> aCStrElementPlaceCont ;
		VerticalTextElementToElementPlace( 
			&aCaDcdTargetItemPosition , 
			m_CdFontProp , 
			&aCStrElementCont , 
			&aCStrElementPlaceCont ) ;

		bRv = DcDrawElementPlace( 
			&aCaDcdTargetItemPosition , 
			m_CdFontProp , 
			m_colorrefText , 
			&aCStrElementPlaceCont ) ;
	}
	return ( bRv ) ;
}

	
bool CDcdTextboxV3::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	bool bRv = false ;

	CdDcdSizeXy	sizeExtent = calcZenkakuCharExtent( pIfDcdTarget , m_CdFontProp ) ;

	pCdDcdSizeXy->setX( sizeExtent.getX() * m_iLinesExtentX + m_logicalunitFrameWidth * 2 ) ;
	pCdDcdSizeXy->setY( sizeExtent.getY() * m_iLinesExtentY + m_logicalunitFrameHeight * 2 ) ;
	return ( true ) ;
}

} //namespace DcDraw
} //namespace DcDrawLib

