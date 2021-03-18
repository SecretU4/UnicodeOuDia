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
//	CDcdFillRectangleTextV2.cpp
// ****************************************************************
*/
//#include "stdafx.h"

#include <deque>
using namespace std ;

#include "CDcdFillRectangleTextV2.h"

#include "str/CStrCharSizeMb.h"
#include "Cont/CCont_deque.h"
#include "logmsg/logmsg.h"
#include "DcDraw/CaDcdTargetItemPosition.h"
#include "DcDraw/CConverter_WinGdi.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

// ****************************************************************
//	CDcdFillRectangleTextV2
// ****************************************************************
// --------------------------------
//@name �����֐�
// --------------------------------
HFONT CDcdFillRectangleTextV2::CreateVFont( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ) 
{
	HFONT hfontVertical =NULL ;
	{
		CdFontProp	aCdFontPropV = fontHorizontal ;
		string strFacename = aCdFontPropV.getFacename() ;
		if ( !( strFacename.size() >= 1 && strFacename.substr( 0 , 1 ) 
				== "@" ) ){
			strFacename = string( "@" ) + strFacename ;
		}
		aCdFontPropV.setFacename( strFacename ) ;
		aCdFontPropV.setIsEscapementVertical() ;
		hfontVertical = pIfDcdTarget->CreateFont( aCdFontPropV ) ;
	}
	return ( hfontVertical ) ;
}
CdDcdSizeXy CDcdFillRectangleTextV2::calcZenkakuCharExtent(
		IfDcdTarget* pIfDcdTarget , const CdFontProp& aCdFontProp ) 
{
	CdDcdSizeXy	sizeExtent ;
	{
		HFONT hFont = pIfDcdTarget->CreateFont( aCdFontProp ) ;
		// --------------------------------
		HFONT hFontOld = (HFONT)SelectObject( 
			pIfDcdTarget->getHdc() , 
			hFont ) ;
		TEXTMETRIC	aTEXTMETRIC ;
		GetTextMetrics( pIfDcdTarget->getHdc() , &aTEXTMETRIC ) ;
		sizeExtent.setX( aTEXTMETRIC.tmHeight ) ;
		sizeExtent.setY( aTEXTMETRIC.tmMaxCharWidth ) ;

		sizeExtent.setX( max( sizeExtent.getX() , sizeExtent.getY() ) ) ;
		sizeExtent.setY( sizeExtent.getX() ) ;

		// --------------------------------
		if ( hFontOld != NULL ){
			SelectObject( pIfDcdTarget->getHdc() , hFontOld ) ;
		}
	}
	return sizeExtent ;
}


CDcdText CDcdFillRectangleTextV2::createCDcdTextH( 
		const CdFontProp&	aCdFontProp , 
		CdColorProp colorrefText ) 
{
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

static bool isSpace( const string& aStr )
{
	static char* kyoukai[] = {
		" " , "�@" ,
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ ){
		if ( aStr == kyoukai[idx] ) {
			return true ;
		}
	}
	return ( false ) ;
}

static bool isKyoukai( const string& aStr )
{
	static char* kyoukai[] = {
		"," , "�C" ,
		"." , "�D" ,
		      "�B" , 
		      "�A" , 
	};
	for ( int idx = 0 ; idx < sizeof(kyoukai) / sizeof(kyoukai[0]) ; idx ++ ){
		if ( aStr == kyoukai[idx] ) {
			return true ;
		}
	}
	return ( false ) ;
}

int CDcdFillRectangleTextV2::StringToMojiretsuyouso( 
		const string& aStr , 
		IfValueCont<CMojiretsuyouso>* pCMojiretsuyousoCont ) 
{
	int iRv = 0 ;
	
	//	���̃R���e�i������܂ŕێ����Ă����v�f�͔j�����܂��B
	pCMojiretsuyousoCont->erase( 0 , INT_MAX ) ;

	CStrCharSizeMb	aCStrCharSizeMb( aStr ) ;
	for ( int bidx = 0 ; 
			bidx < aCStrCharSizeMb.ByteLength() ; 
			bidx = aCStrCharSizeMb.BidxNextChar( bidx ) ){
		string strChar = aStr.substr( bidx , 
			aCStrCharSizeMb.CsizeOfBidx( bidx ) ) ;
		CMojiretsuyouso*	pCMojiretsuyousoPrev = pCMojiretsuyousoCont->getp( INT_MAX ) ;
		//strChar = ����̕����B
		//aCMojiretsuyousoPrev = ���O�̕�����v�f

		if ( aCStrCharSizeMb.CsizeOfBidx( bidx ) == 1 ){
			//	����̕����͋󔒈ȊO�̂P�o�C�g�����ŁA
			//	( ���O�̕�����v�f�� V_HANKAKU �A
			//	���A���O�̕�����v�f����؂蕶����󔒂ŏI����Ă��Ȃ�
			//	) 
			//	�ꍇ�́A���O�̕�����v�f�ɕ�����ǉ����܂��B
			//
			//	����̕����͂P�o�C�g�����ł���ꍇ�́A������v�f��ǉ����܂��B

			string strCharPrev ;
			if ( pCMojiretsuyousoPrev != NULL ){
				strCharPrev = pCMojiretsuyousoPrev->getBubunMojiretsu().substr( 
					pCMojiretsuyousoPrev->getBubunMojiretsu().size() - 1 , 1 ) ;
			}
			//strCharPrev = ���O�̕�����v�f�̖����̕���

			if ( !isSpace( strChar ) && 
				pCMojiretsuyousoPrev != NULL && 
				pCMojiretsuyousoPrev->getType() == CMojiretsuyouso::V_HANKAKU &&
				!isKyoukai( strCharPrev ) && !isSpace( strCharPrev ) ){
				pCMojiretsuyousoPrev->setBubunMojiretsu( 
					pCMojiretsuyousoPrev->getBubunMojiretsu() + strChar ) ;
			}	else	{
				CMojiretsuyouso	aCMojiretsuyouso ;

				aCMojiretsuyouso.setBubunMojiretsu( strChar ) ;
				aCMojiretsuyouso.setType( CMojiretsuyouso::V_HANKAKU ) ;

				pCMojiretsuyousoCont->insert( aCMojiretsuyouso ) ;
			}
		}	else if ( aCStrCharSizeMb.CsizeOfBidx( bidx ) == 2 ){
			//	����̕����͂Q�o�C�g�̋�؂蕶���ŁA
			//	( ���O�̕�����v�f�� V_ZENKAKU 
			//	) 
			//	�ꍇ�́A���O�̕�����v�f�ɕ�����ǉ����܂��B
			//
			//	����̕����͂Q�o�C�g�����ł���ꍇ�́A������v�f��ǉ����܂��B
			if ( isKyoukai( strChar ) && 
				pCMojiretsuyousoPrev != NULL && 
				pCMojiretsuyousoPrev->getType() == CMojiretsuyouso::V_ZENKAKU ){
				pCMojiretsuyousoPrev->setBubunMojiretsu( 
					pCMojiretsuyousoPrev->getBubunMojiretsu() + strChar ) ;
			}	else	{
				CMojiretsuyouso	aCMojiretsuyouso ;
				aCMojiretsuyouso.setBubunMojiretsu( strChar ) ;
				aCMojiretsuyouso.setType( CMojiretsuyouso::V_ZENKAKU ) ;
				pCMojiretsuyousoCont->insert( aCMojiretsuyouso ) ;

			}
		}

	}
	//pCMojiretsuyousoCont = ������� V_ZENKAKU �� V_HANKAKU �̂Q��
	//	�v�f�ɕ������܂����B
	//	V_ZENKAKU �́A�����Ƃ��đS�p�����P�ł��B
	//	�A���A[�S�p����][�S�p��؂蕶��]
	//	�́A[�S�p����+�S�p��؂蕶��]�̂P�̗v�f�ɂȂ��Ă��܂��B
	//	V_HANKAKU �́A�A���������p�������P�̗v�f�Ƃ��܂��B

	// --------------------------------	
	int idxMojiretsuyouso ;
	for ( idxMojiretsuyouso = 0 ; 
			idxMojiretsuyouso < pCMojiretsuyousoCont->size() ;
			idxMojiretsuyouso ++ ){
		//	����̕�����v�f�����p�p�����P�������Q���� 
		//	AND 
		//	( 
		//		( �O�̕�����v�f�����݂��Ȃ�)
		//		OR
		//		( �O�̕�����v�f���i�󔒈ȊO�̔��p������̗v�f�j�łȂ�)
		//	) 
		CMojiretsuyouso* pCMojiretsuyousoPrev = pCMojiretsuyousoCont->getp( idxMojiretsuyouso - 1 ) ;
		CMojiretsuyouso* pCMojiretsuyouso = pCMojiretsuyousoCont->getp( idxMojiretsuyouso ) ;
		string strCurr = pCMojiretsuyouso->getBubunMojiretsu() ;
		if ( pCMojiretsuyouso->getType() == CMojiretsuyouso::V_HANKAKU ){
			if ( 
				( strCurr.size() == 1 && isdigit( strCurr[0] ) ) || 
				( strCurr.size() == 2 && isdigit( strCurr[0] ) && isdigit( strCurr[1] ) ) 
			){

			if ( pCMojiretsuyousoPrev == NULL || 
				!(  
					pCMojiretsuyousoPrev->getType() == CMojiretsuyouso::V_HANKAKU && 
					!isSpace( pCMojiretsuyousoPrev->getBubunMojiretsu() ) 
				) 
			){
				pCMojiretsuyouso->setType( CMojiretsuyouso::H_HANKAKU ) ;
			}
			}
				
		}

	}
	

	// --------------------------------	
	return ( iRv ) ;
}

int CDcdFillRectangleTextV2::MojiretsuyousoToMojiretsuyousoPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ,
		IfContGet<CMojiretsuyouso>* pCMojiretsuyousoCont ,
		IfCont<CMojiretsuyousoPlace>* pCMojiretsuyousoPlaceCont ) 
{
	int iRv = 0 ;
	
	// --------------------------------
	CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;
	pCMojiretsuyousoPlaceCont->erase( 0 , INT_MAX ) ;
	// --------------------------------
	//	�t�H���g���쐬
	// --------------------------------
	HFONT hfontVertical = CreateVFont( pIfDcdTarget , fontHorizontal ) ;
	//hFontVertical = �c�����̃t�H���g
	
	CDcdText aCDcdText( createCDcdTextH( 
				fontHorizontal , CdColorProp( 0 , 0 , 0 ) ) ) ;
	//aCDcdText = �������e�L�X�g�p�́ADcDraw�I�u�W�F�N�g
	

	// --------------------------------
	int logicalunitYOffset = 0 ;
	int iXLineNumber = 0 ;
	
	int idxMojiretsuyousoCont ;
	for ( idxMojiretsuyousoCont = 0 ; 
			idxMojiretsuyousoCont < pCMojiretsuyousoCont->size() ;){
		CMojiretsuyouso	aCMojiretsuyouso = 
			pCMojiretsuyousoCont->get( idxMojiretsuyousoCont ) ;
		if ( aCMojiretsuyouso.getType() == CMojiretsuyouso::V_ZENKAKU || 
				aCMojiretsuyouso.getType() == CMojiretsuyouso::V_HANKAKU ){
			HFONT hFontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , 
				hfontVertical ) ;
			// --------------------------------
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
				idxMojiretsuyousoEnd < pCMojiretsuyousoCont->size() ;
				idxMojiretsuyousoEnd ++ ){
				CMojiretsuyouso	aCMojiretsuyousoEnd = 
					pCMojiretsuyousoCont->get( idxMojiretsuyousoEnd ) ;

				
				if ( aCMojiretsuyousoEnd.getType() != 
						aCMojiretsuyouso.getType() ){
					//	����́w����������x�́A idxMojiretsuyousoCont �̈ʒu��
					//	�w����������x�Ƃ͎�ނ��قȂ�܂��B
					break ;
				}


				string aString = strMojiretsu + 
					aCMojiretsuyousoEnd.getBubunMojiretsu() ;
				SIZE	aSize ;
				GetTextExtentPoint32( 
					pIfDcdTarget->getHdc() , 
					aString.c_str() , 
					(int)aString.size() , 
					&aSize ) ;
				
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
			//
			//	�܂��A���̏󋵂ŁAlogicalunitYOffset �� 0 �̏ꍇ�́A
			//	���݂̍s�ɉ����`��ł��Ȃ��������ƂɂȂ�܂��B
			//strMojiretsu = �������ꂽ���ʂ̕�����
			//logicalunitYSize = �������ꂽ���ʂ̕�����́AY�����̃T�C�Y
			//	�i�_���P�ʁj
			if ( idxMojiretsuyousoCont == idxMojiretsuyousoEnd ){
				logicalunitYOffset = 0 ;
				iXLineNumber ++ ;
				continue ;
			}
			CMojiretsuyousoPlace aCMojiretsuyousoPlace( 
				CMojiretsuyouso( strMojiretsu , aCMojiretsuyouso.getType() ) ,
				logicalunitYOffset , iXLineNumber , iXLineWidth ) ;
			pCMojiretsuyousoPlaceCont->insert( aCMojiretsuyousoPlace ) ;

			logicalunitYOffset += logicalunitYSize ;
			idxMojiretsuyousoCont = idxMojiretsuyousoEnd ;
			// --------------------------------
			SelectObject( pIfDcdTarget->getHdc() , hFontOld ) ;
			hFontOld = NULL ;
		}	else if ( aCMojiretsuyouso.getType() == 
				CMojiretsuyouso::H_HANKAKU ){
			// --------------------------------
			//	������ނ̘A�������w����������x��
			//	�����͍s���܂���B
			// --------------------------------
			string strMojiretsu ;
			int idxMojiretsuyousoEnd = idxMojiretsuyousoCont ;
			int logicalunitYSize = 0 ;
			int iXLineWidth = 0 ;
			{
				CMojiretsuyouso	aCMojiretsuyousoEnd = 
					pCMojiretsuyousoCont->get( idxMojiretsuyousoEnd ) ;
				
				string aString = strMojiretsu + 
					aCMojiretsuyousoEnd.getBubunMojiretsu() ;
				aCDcdText.setText( aString ) ;
				CdDcdSizeXy aCdDcdSizeXy ;
				aCDcdText.getItemSize( pIfDcdTarget , &aCdDcdSizeXy ) ;

				if ( logicalunitYOffset + aCdDcdSizeXy.getY() <= 
						zonexyTarget.getY().getSize() || 
					( logicalunitYOffset == 0 && strMojiretsu.size() == 0 ) ){
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
			//
			//	�܂��A���̏󋵂ŁAlogicalunitYOffset �� 0 �̏ꍇ�́A
			//	���݂̍s�ɉ����`��ł��Ȃ��������ƂɂȂ�܂��B
			//strMojiretsu = �������ꂽ���ʂ̕�����
			//logicalunitYSize = �������ꂽ���ʂ̕�����́AY�����̃T�C�Y
			//	�i�_���P�ʁj
			if ( idxMojiretsuyousoCont == idxMojiretsuyousoEnd ){
				logicalunitYOffset = 0 ;
				iXLineNumber ++ ;
				continue ;
			}
			CMojiretsuyousoPlace aCMojiretsuyousoPlace( 
				CMojiretsuyouso( strMojiretsu , aCMojiretsuyouso.getType() ) ,
				logicalunitYOffset , iXLineNumber , iXLineWidth ) ;
			pCMojiretsuyousoPlaceCont->insert( aCMojiretsuyousoPlace ) ;

			logicalunitYOffset += logicalunitYSize ;
			idxMojiretsuyousoCont = idxMojiretsuyousoEnd ;
		}
	}
	
	//rinji
	{
		CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;
		LogMsgL(3, "CDcdFillRectangleTextV2::MojiretsuyousoToMojiretsuyousoPlace"
			"(X.Pos=%d X.Size=%d Y.Pos=%d Y.Size=%d)" , 
			zonexyTarget.getX().getPos() , 
			zonexyTarget.getX().getSize() , 
			zonexyTarget.getY().getPos() , 
			zonexyTarget.getY().getSize() ) ;
		int idx ;
		for ( idx = 0 ; idx < pCMojiretsuyousoPlaceCont->size() ; idx ++ ){
			CMojiretsuyousoPlace aCMojiretsuyousoPlace = 
				pCMojiretsuyousoPlaceCont->get( idx ) ;
			LogMsgL(3, "\t[%d] \"%s\" %d iY=%d iX=%d iXLineWidth=%d" ,
				idx , 
				aCMojiretsuyousoPlace.getCMojiretsuyouso().getBubunMojiretsu().c_str() ,
				aCMojiretsuyousoPlace.getCMojiretsuyouso().getType() ,
				aCMojiretsuyousoPlace.getYOffset() ,
				aCMojiretsuyousoPlace.getXLineNumber() , 
				aCMojiretsuyousoPlace.getXLineWidth() ) ;

		}
	}
	
	
	
	// --------------------------------
	return ( iRv ) ;
}

bool CDcdFillRectangleTextV2::DcDrawMojiretsuyousoPlace( 
		IfDcdTarget* pIfDcdTarget ,
		const CdFontProp& fontHorizontal ,
		CdColorProp colorTextColor , 
		IfContGet<CMojiretsuyousoPlace>* pCMojiretsuyousoPlaceCont ) 
{
	bool bRv = false ;

	// --------------------------------
	CdDcdZoneXy	zonexyTarget = pIfDcdTarget->getZone() ;

	// --------------------------------
	//	�t�H���g���쐬
	// --------------------------------
	HFONT hfontVertical = CreateVFont( pIfDcdTarget , fontHorizontal ) ;
	CdDcdSizeXy	sizeExtent = calcZenkakuCharExtent( pIfDcdTarget , fontHorizontal) ;
	//hFontVertical = �c�����̃t�H���g
	//sizeExtent = �e�L�X�g�S�p�{�b�N�X�P����������̃T�C�Y�B
	//	�������A�T�C�Y�͐����`�ɂȂ�悤�ɍœK�����܂��B
	//	�܂�AX,Y�̂����A�傫�����̕ӂɍ��킹�܂��B

	CDcdText aCDcdText( createCDcdTextH( 
				fontHorizontal , colorTextColor ) ) ;
	//aCDcdText = �������e�L�X�g�p�́ADcDraw�I�u�W�F�N�g
	// --------------------------------
	int iLines = 1 ;
	if ( pCMojiretsuyousoPlaceCont->size() > 0 ){
		iLines = pCMojiretsuyousoPlaceCont->get( INT_MAX ).getXLineNumber() 
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
	for ( int idxCMojiretsuyousoPlaceCont = 0 ;
			idxCMojiretsuyousoPlaceCont < pCMojiretsuyousoPlaceCont->size() ;
			idxCMojiretsuyousoPlaceCont ++ ){
		CMojiretsuyousoPlace	aCMojiretsuyousoPlace = 
			pCMojiretsuyousoPlaceCont->get( idxCMojiretsuyousoPlaceCont ) ;
		CMojiretsuyouso	aCMojiretsuyouso = 
			aCMojiretsuyousoPlace.getCMojiretsuyouso() ;
		
		int iXPos = zonexyTarget.getX().getPos() + iXOffset + 
				( iLines - 1 - aCMojiretsuyousoPlace.getXLineNumber() ) 
				* sizeExtent.getX() ;
		int iYPos = zonexyTarget.getY().getPos() + 
				aCMojiretsuyousoPlace.getYOffset() ;
		string strChar = aCMojiretsuyouso.getBubunMojiretsu() ;
		
		if ( aCMojiretsuyouso.getType() == CMojiretsuyouso::V_ZENKAKU || 
				aCMojiretsuyouso.getType() == CMojiretsuyouso::V_HANKAKU )
		{
			// --------------------------------
			//	�c�����t�H���g
			// --------------------------------
			HFONT hfontOld = (HFONT)SelectObject( pIfDcdTarget->getHdc() , 
				hfontVertical ) ;
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
					- ( sizeExtent.getX() - aCMojiretsuyousoPlace.getXLineWidth() ) / 2 ,
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
		}	else if ( aCMojiretsuyouso.getType() == 
				CMojiretsuyouso::H_HANKAKU ){
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
CDcdFillRectangleTextV2::CDcdFillRectangleTextV2( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp  ,
		int						iLinesExtentX  ,
		int						iLinesExtentY  ,
		CdColorProp	colorrefText , 
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



CDcdFillRectangleTextV2::CDcdFillRectangleTextV2() 
	: m_iLinesExtentX ( 1 ) 
	, m_iLinesExtentY( 1 ) 
	, m_colorrefText( CdColorProp( 0 , 0 , 0 ) ) 
	, m_logicalunitFrameWidth( 0 )
	, m_logicalunitFrameHeight( 0 )
{
}
	
CDcdFillRectangleTextV2::~CDcdFillRectangleTextV2() 
{
}
// ********************************
//	IfDcDraw
// ********************************
bool CDcdFillRectangleTextV2::DcDraw( IfDcdTarget* pIfDcdTarget ) 
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
		CCont_deque<CMojiretsuyouso> aCMojiretsuyousoCont ;
		StringToMojiretsuyouso( m_strText , &aCMojiretsuyousoCont ) ;
		CCont_deque<CMojiretsuyousoPlace> aCMojiretsuyousoPlaceCont ;
		MojiretsuyousoToMojiretsuyousoPlace( &aCaDcdTargetItemPosition , m_CdFontProp , 
			&aCMojiretsuyousoCont , &aCMojiretsuyousoPlaceCont ) ;
		bRv = DcDrawMojiretsuyousoPlace( &aCaDcdTargetItemPosition , m_CdFontProp , 
			m_colorrefText , &aCMojiretsuyousoPlaceCont ) ;
	}
	return ( bRv ) ;
}
	

	
bool CDcdFillRectangleTextV2::getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) 
{
	bool bRv = false ;

	CdDcdSizeXy	sizeExtent = calcZenkakuCharExtent( pIfDcdTarget , m_CdFontProp ) ;

	pCdDcdSizeXy->setX( sizeExtent.getX() * m_iLinesExtentX + m_logicalunitFrameWidth * 2 ) ;
	pCdDcdSizeXy->setY( sizeExtent.getY() * m_iLinesExtentY + m_logicalunitFrameHeight * 2 ) ;
	return ( true ) ;
}
