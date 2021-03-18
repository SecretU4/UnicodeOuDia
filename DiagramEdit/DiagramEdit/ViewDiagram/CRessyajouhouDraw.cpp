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
// ****************************************************************
//	CRessyajouhouDraw.cpp
//	$Id: CRessyajouhouDraw.cpp 367 2016-08-19 10:14:24Z okm $
// ****************************************************************
/** @file */
#include "stdafx.h"
#include <math.h>

#include "DcDraw\CDcdText.h"
#include "DcDraw\CConverter_Wingdi.h"

#include "CRessyajouhouDraw.h"

namespace ViewDiagram{

using namespace std ;

// ****************************************************************
///	�~����
const double Pi = 3.14159265 ;

/**
 	�p�x�̒P�ʂ��A�x���烉�W�A���֕ϊ����܂��B
 
 	180 �x = 1�� ���W�A��
  @param value [in]
 	�ϊ��Ώۂ̒l�B
  @return
 	�ϊ���̒l�B
*/
static double DegToRad( double value )
{
	return value * Pi / 180 ;
}

/**
 	�p�x�̒P�ʂ��A���W�A������x�֕ϊ����܂��B
 
 	180 �x = 1�� ���W�A��
  @param value [in]
 	�ϊ��Ώۂ̒l�B
  @return
 	�ϊ���̒l�B
*/
static double RadToDeg( double value )
{
	return value * 180 / Pi ;
}
	// ********************************
	//	�R���X�g���N�^
	// ********************************
CRessyajouhouDraw::CRessyajouhouDraw( CDcdDiagram* pCDcdDiagram , 
			IfDcdTarget* pIfDcdTarget , 
			bool bDisplayRessyasenKudari ,
			bool bDisplayRessyasenNobori ) :
	super( 
		pCDcdDiagram->getCentDedDgrDia() , 
		pCDcdDiagram->DgrFromDcd( pIfDcdTarget , pIfDcdTarget->getZone() ) , 
		bDisplayRessyasenKudari , 
		bDisplayRessyasenNobori ) ,
	m_pCDcdDiagram( pCDcdDiagram ) ,
	m_pIfDcdTarget( pIfDcdTarget ) 
{
};

// ********************************
//	CDcdDiagram::CEnumRessyasen
// ********************************

void CRessyajouhouDraw::onCentDedDgrEkiJikoku( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ,
		int iEkiOrder , 
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku ) 
{
	if ( iEkiOrder == pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() )
	{
		//	��Ԑ��I�_�ɂ́A�e�L�X�g�̕`����s���܂���
		return ;
	}
	if ( !pCentDedDgrEkiJikoku->getShouldRessyajouhouDraw() )
	{
		//	���̉w�����̈ʒu�ɂ́A�e�L�X�g�̕`����s���܂���B
		return ;
	}
	// --------------------------------
	//	�e�L�X�g�̐F��I��
	// --------------------------------
	CdColorProp	colorText ;
	{
		int idxRessyasyubetsu = pCentDedDgrRessya->getRessyasyubetsuIndex() ;
		if ( 0 <= idxRessyasyubetsu && 
			idxRessyasyubetsu < getCentDedDgrDia()->getMuCentDedDgrRessyasyubetsu()->size() )
		{
			const CentDedDgrRessyasyubetsu* pCentDedDgrRessyasyubetsu = 
				getCentDedDgrDia()->getMuCentDedDgrRessyasyubetsu()->get( idxRessyasyubetsu ) ;
			colorText = pCentDedDgrRessyasyubetsu->getJikokuhyouMojiColor() ;
		}
	}
	//colorText = �e�L�X�g�̐F

	// --------------------------------
	//	��ԏ��e�L�X�g�̓��e���쐬��
	//	�傫�����v��
	// --------------------------------
	string	strRessyajouhou ;
	if ( m_pCDcdDiagram->getDisplayRessyabangou() )
	{
		if ( !pCentDedDgrRessya->getRessyabangou().empty() )
		{
			if ( !strRessyajouhou.empty() )
			{
				strRessyajouhou += ' ' ;
			}
			strRessyajouhou += pCentDedDgrRessya->getRessyabangou() ;
		}
	}
	if (  m_pCDcdDiagram->getDisplayRessyamei() )
	{
		if ( !pCentDedDgrRessya->getRessyamei().empty() )
		{
			if ( !strRessyajouhou.empty() )
			{
				strRessyajouhou += ' ' ;
			}
			strRessyajouhou += pCentDedDgrRessya->getRessyamei() ;
		}
		if ( !pCentDedDgrRessya->getGousuu().empty() )
		{
			if ( !strRessyajouhou.empty() )
			{
				strRessyajouhou += ' ' ;
			}
			strRessyajouhou += pCentDedDgrRessya->getGousuu() ;
			CString	aStr ;
			aStr.LoadString( IDS_WORD_GOUSUU2 ) ;
			strRessyajouhou += (LPCTSTR)aStr ;
		}
	}
	if ( strRessyajouhou.empty() )
	{
		return ;
	}
	//strRessyajouhou = �\�������ԏ��̕�����
	CdDcdSizeXy	sizexyText_Dcd ;
	{
		CDcdText	dcdText( strRessyajouhou , 
			m_pCDcdDiagram->getDiaRessyaFont() ) ;
		dcdText.getItemSize( m_pIfDcdTarget , &sizexyText_Dcd ) ;
	}
	//sizexyText_Dcd = ��ԏ��e�L�X�g�̕��ƍ���
	//	�i�����ɕ`�悵���ꍇ�̐��@�ł��j

	// --------------------------------
	//	��ԏ��̕`�悳��钼�����Z�o
	// --------------------------------
	CdDcdPosXy	posRessyasen_Pos1_Dcd ;
	CdDcdPosXy	posRessyasen_Pos2_Dcd ;
	{
		CdDcdPosXy	posDgrPosRessyasenKiten = 
			getCentDedDgrDia()->calcDgrPosRessyasenKiten( 
				pCentDedDgrRessya , 
				pCentDedDgrRessyasen ) ;
		CdDcdPosXy	posDgrPosRessyasenSyuuten = 
			getCentDedDgrDia()->calcDgrPosRessyasenSyuuten( 
				pCentDedDgrRessya , 
				pCentDedDgrRessyasen ) ;
		//posDgrPosRessyasenKiten,posDgrPosRessyasenSyuuten = 
		//	�w�_�C���O�����G���e�B�e�B��Ԑ��x�̋N�_�ƏI�_�̍��W
		//	�P�ʂ́A�w�_�C���O�����G���e�B�e�B���W�n�x

		posRessyasen_Pos1_Dcd = m_pCDcdDiagram->DgrToDcd( 
			m_pIfDcdTarget , 
			posDgrPosRessyasenKiten ) ;
		posRessyasen_Pos2_Dcd = m_pCDcdDiagram->DgrToDcd( 
			m_pIfDcdTarget , 
			posDgrPosRessyasenSyuuten ) ;
	}
	//posRessyasen_Pos1_Dcd,posRessyasen_Pos2_Dcd = 
	//	�w�_�C���O�����G���e�B�e�B��Ԑ��x�̋N�_�ƏI�_�̍��W
	//	�P�ʂ́A IfDcdTarget �̍��W

	// --------------------------------
	//	��ԏ��̕`�悳���w�̗�Ԑ���ł̈ʒu���Z�o
	// --------------------------------
	int iX_Dcd = 0 ;
	int iY_Dcd = 0 ;
	{
		int iY_Dgr = 0 ;
		int iX_Dgr = 0 ;
		iY_Dgr = getCentDedDgrDia()->getDgrYPosOfEki( 
			pCentDedDgrRessya->getRessyahoukou() , iEkiOrder ) ;
		int iResult = pCentDedDgrRessya->getDgrXPosOfEkiOrder( 
			iEkiOrder , &iX_Dgr ) ;
		if ( iResult < 0 ){
			return ;
		}
		//iX_Dgr,iY_Dgr = ��ԏ���\������w�̔������̍��W
		//	�P�ʂ́A�w�_�C���O�����G���e�B�e�B���W�n�x

		iX_Dcd = m_pCDcdDiagram->XDgrToDcd( m_pIfDcdTarget , iX_Dgr  ) ;
		iY_Dcd = m_pCDcdDiagram->YDgrToDcd( m_pIfDcdTarget , iY_Dgr  ) ;
	}
	//iX_Dcd,iY_Dcd = ��ԏ���\������w�̔������̍��W
	//	�P�ʂ́A IfDcdTarget �̍��W�n

	// --------------------------------
	//	�e�L�X�g�̈ʒu�Ɗp�x���v�Z
	// --------------------------------
	CdDcdPosXy	posText_Dcd ;
	int iDeg = 0 ;
	{
		double d = sizexyText_Dcd.getY() + 2 ;
		if ( pCentDedDgrRessya->getRessyahoukou() == 
			Ressyahoukou_Kudari )
		{
			double a = posRessyasen_Pos2_Dcd.getX() - 
				posRessyasen_Pos1_Dcd.getX() ;
			double b =  posRessyasen_Pos2_Dcd.getY() - 
				posRessyasen_Pos1_Dcd.getY() ;
			double a_b =  a / b ;
			int c = (int)( RadToDeg( atan( a_b ) ) ) ;
			int e = (int)( d / cos( DegToRad( c ) ) ) ;
			posText_Dcd = CdDcdPosXy( iX_Dcd + e , iY_Dcd ) ;
			iDeg = 270 + c ;
		}
		else
		{
			double a = posRessyasen_Pos2_Dcd.getX() - 
				posRessyasen_Pos1_Dcd.getX() ;
			double b =  posRessyasen_Pos1_Dcd.getY() - 
				posRessyasen_Pos2_Dcd.getY() ;
			double a_b =  a / b ;
			int c = (int)( RadToDeg( atan( a_b ) ) ) ;
			int e = (int)( d * cos( DegToRad( c ) ) ) ;
			int f = (int)( d * sin( DegToRad( c ) ) ) ;
			posText_Dcd = CdDcdPosXy( iX_Dcd - e , iY_Dcd - f ) ;
			iDeg = 90 -c ;
		}
	}
	//posText_Dcd = �e�L�X�g�̍�����W
	//iDeg = �e�L�X�g�̊p�x�i�P�ʂ͓x�j

	// --------------------------------
	//	�e�L�X�g�̕`��
	// --------------------------------
	{
		//	�t�H���g�̑���
		//	�p�x�w���ǉ����܂��B
		CdFontProp	aCdFontProp = m_pCDcdDiagram->getDiaRessyaFont() ;
		aCdFontProp.setEscapement( iDeg * 10 ) ;

		//	�t�H���g�̐���
		Ou<CGdiHFontHolder>	pHFontHolder = m_pIfDcdTarget->createGdiHFontHolder(
			aCdFontProp ) ;
		
		// --------------------------------
		//	�t�H���g�E�F�E�w�i���[�h�̑I��
		HFONT	hFontPrev = NULL ;
		hFontPrev = (HFONT)SelectObject( m_pIfDcdTarget->getHdc() , 
			pHFontHolder->getHFont() ) ;

		CConverter_WinGdi	aCConverter_WinGdi ;
		COLORREF	colorTextPrev = SetTextColor( 
			m_pIfDcdTarget->getHdc() , 
			aCConverter_WinGdi.COLORREFOf( colorText ) ) ;
		int iBkModePrev = SetBkMode( m_pIfDcdTarget->getHdc() , 
			TRANSPARENT ) ;
		// --------------------------------
		TextOut( m_pIfDcdTarget->getHdc() , 
			posText_Dcd.getX() , posText_Dcd.getY() ,
			strRessyajouhou.c_str() , strRessyajouhou.size() ) ;

		// --------------------------------
		//	�t�H���g�E�F�E�w�i���[�h�̑I��������
		{
			SetBkMode( m_pIfDcdTarget->getHdc() , iBkModePrev ) ;
			SetTextColor( m_pIfDcdTarget->getHdc() , colorTextPrev ) ;
		}
		if ( hFontPrev != NULL ){
			SelectObject( m_pIfDcdTarget->getHdc() , hFontPrev ) ;
			hFontPrev = NULL ;
		}
		// --------------------------------
		//	�t�H���g��j��
		if ( pHFontHolder != NULL )
		{
			pHFontHolder = Ou<CGdiHFontHolder>() ;
		}
	}
}

} //namespace ViewDiagram
