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
//	CDcdDiagram_CStopMarkDraw.cpp
//	$Id: CDcdDiagram_CStopMarkDraw.cpp 367 2016-08-19 10:14:24Z okm $
// ****************************************************************
/** @file */
#include "stdafx.h"
#include <math.h>

#include "CDcdDiagram_CStopMarkDraw.h"

namespace ViewDiagram{

// ********************************
//	�R���X�g���N�^
// ********************************
CDcdDiagram_CStopMarkDraw::CDcdDiagram_CStopMarkDraw( CDcdDiagram* pCDcdDiagram , 
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
void CDcdDiagram_CStopMarkDraw::onCentDedDgrEkiJikoku( 
		ERessyahoukou eRessyahoukou ,
		int iRessyaIdx ,
		const CentDedDgrRessya* pCentDedDgrRessya ,
		int iRessyasenIdx ,
		const CentDedDgrRessyasen* pCentDedDgrRessyasen ,
		int iEkiOrder , 
		const CentDedDgrEkiJikoku* pCentDedDgrEkiJikoku ) 
{
	if ( m_pCDcdDiagram->getStopMarkDraw() != 
		CDcdDiagram::EStopMarkDraw_DrawOnBriefStop )
	{
		//	���݂̃��[�h�ł́A��ԃ}�[�N�̕`����s���܂���B
		return ;
	}
	if ( iEkiOrder == pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() )
	{
		//	��Ԑ��I�_�ɂ́A�e�L�X�g�̕`����s���܂���
		return ;
	}
	// --------------------------------
	//	���̗�Ԏ�ʂŕ`����s�����ۂ��𔻒�
	// --------------------------------
	CentDedRessyasyubetsu::EStopMarkDrawType	eStopMarkDrawType = 
		CentDedRessyasyubetsu::EStopMarkDrawType_DrawOnStop ;
	{
		int idxRessyasyubetsu = pCentDedDgrRessya->getRessyasyubetsuIndex() ;
		if ( 0 <= idxRessyasyubetsu && 
			idxRessyasyubetsu < getCentDedDgrDia()->getMuCentDedDgrRessyasyubetsu()->size() )
		{
			const CentDedDgrRessyasyubetsu* pCentDedDgrRessyasyubetsu = 
				getCentDedDgrDia()->getMuCentDedDgrRessyasyubetsu()->get( idxRessyasyubetsu ) ;
			eStopMarkDrawType = pCentDedDgrRessyasyubetsu->getStopMarkDrawType() ;
		}
	}
	//eStopMarkDrawType = ��ԉw�`�惂�[�h


	// --------------------------------
	//	��ԃ}�[�N��`�悷��ʒu���Z�o
	// --------------------------------
	int iX_Dcd = 0 ;
	int iY_Dcd = 0 ;
	{
		int iY_Dgr = getCentDedDgrDia()->getDgrYPosOfEki( 
			pCentDedDgrRessya->getRessyahoukou() , iEkiOrder ) ;
		int iX_Dgr = 0 ;
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
	//	��Ԏ��Ԃ��Z�o
	// --------------------------------
	int iStopSeconds = 0 ;
	{
		if ( pCentDedDgrEkiJikoku->getDgrXPosChaku() != INT_MIN && 
			pCentDedDgrEkiJikoku->getDgrXPosHatsu() != INT_MIN )
		{
			iStopSeconds = pCentDedDgrEkiJikoku->getDgrXPosHatsu() - 
				pCentDedDgrEkiJikoku->getDgrXPosChaku() ;
		}
	}

	// --------------------------------
	//	���w���n���w�ł��I���w�ł��Ȃ�
	//	��Ԏ�ʂ���ԉw�𖾎� AND ���w���Z���Ԓ��(60�b����)
	//	�ł���΁A��ԃ}�[�N��`��
	// --------------------------------
	if ( pCentDedDgrRessya->getSihatsuEki() < iEkiOrder &&
		iEkiOrder < pCentDedDgrRessya->getSyuuchakuEki() && 
		eStopMarkDrawType == 
			CentDedRessyasyubetsu::EStopMarkDrawType_DrawOnStop && 
		pCentDedDgrEkiJikoku->getEkiatsukai() == 
			CentDedEkiJikoku::Ekiatsukai_Teisya && 
		iStopSeconds < 60 )
	{
		//// --------------------------------
		////	��ԃ}�[�N�̕`��(��)
		//// --------------------------------
		//{
		//	// --------------------------------
		//	//	�O�p�`�̂R�ӂ��Z�o
		//	// --------------------------------
		//	CdDcdPosXy	posRessyasen_Pos1_Dcd ;
		//	CdDcdPosXy	posRessyasen_Pos2_Dcd ;
		//	{
		//		CdDcdPosXy	posRessyasen_Pos1_Dgr( 
		//		pCentDedDgrRessyasen->getRessyasenKitenJikoku() ,
		//		getCentDedDgrDia()->getYZahyouOfEki( 
		//		pCentDedDgrRessya->getRessyahoukou() , 
		//		pCentDedDgrRessyasen->getRessyasenKitenEkiOrder() ) 
		//		) ;
		//		CdDcdPosXy	posRessyasen_Pos2_Dgr( 
		//		pCentDedDgrRessyasen->getRessyasenSyuutenJikoku() ,
		//		getCentDedDgrDia()->getYZahyouOfEki( 
		//		pCentDedDgrRessya->getRessyahoukou() , 
		//		pCentDedDgrRessyasen->getRessyasenSyuutenEkiOrder() ) 
		//		) ;
		//		//posRessyasen_Pos1_Dgr,posRessyasen_Pos2_Dgr = 
		//		//	�w�_�C���O�����G���e�B�e�B��Ԑ��x�̋N�_�ƏI�_�̍��W
		//		//	�P�ʂ́A�w�_�C���O�����G���e�B�e�B���W�n�x

		//		posRessyasen_Pos1_Dcd = m_pCDcdDiagram->DgrToDcd( m_pIfDcdTarget , 
		//		posRessyasen_Pos1_Dgr ) ;
		//		posRessyasen_Pos2_Dcd = m_pCDcdDiagram->DgrToDcd( m_pIfDcdTarget , 
		//		posRessyasen_Pos2_Dgr ) ;
		//	}
		//	//posRessyasen_Pos1_Dgr,posRessyasen_Pos2_Dgr = 
		//	//	�w�_�C���O�����G���e�B�e�B��Ԑ��x�̋N�_�ƏI�_�̍��W
		//	//	�P�ʂ́A IfDcdTarget �̍��W


		//	CdDcdPosXy	posTriangle_Dcd[3] ;
		//	{
		//		//	�O�p�`�̑傫���B
		//		//	�P�ʂ́ADC�̘_�����W�B
		//		//	���̒l�́A
		//		//		����������񓙕ӎO�p�`�̒��_�܂ł̒����B
		//		//		�񓙕ӎO�p�`�̒��
		//		//	�ɁA�K�p����܂��B
		//		//	����������񓙕ӎO�p�`�̒�ӂ܂ł̒����́A 
		//		//	dTriangleSize / 2 �Ƃ��܂��B
		//		const double dTriangleSize = 6 ;

		//		if ( pCentDedDgrRessya->getRessyahoukou() == 
		//			Ressyahoukou_Kudari )
		//		{
		//			double dRessyasen_x_len = posRessyasen_Pos2_Dcd.getX() - 
		//			posRessyasen_Pos1_Dcd.getX() ;
		//			double dRessyasen_y_len =  posRessyasen_Pos2_Dcd.getY() - 
		//			posRessyasen_Pos1_Dcd.getY() ;
		//			double dRessyasen =  dRessyasen_x_len / dRessyasen_y_len ;

		//			//int iRessyasen_deg = (int)( RadToDeg( atan( dRessyasen ) ) ) ;
		//			//double e_x_len = ( dTriangleSize * sin( DegToRad( iRessyasen_deg ) ) ) ;
		//			//double e_y_len = ( dTriangleSize * cos( DegToRad( iRessyasen_deg ) ) ) ;

		//			double dRessyasen_rad = atan( dRessyasen ) ;
		//			double e_x_len = ( dTriangleSize * sin( dRessyasen_rad ) ) ;
		//			double e_y_len = ( dTriangleSize * cos( dRessyasen_rad ) ) ;


		//			//	�O�p�`�̒��_�����߂܂��B
		//			//	�Ō�� +0.5 �́A�����_�ȉ��̒[�����l�̌ܓ����邽�߂̂��̂ł��B
		//			posTriangle_Dcd[0].setX( (DcdPos)( iX_Dcd + e_x_len                       + 0.5 ) ) ;
		//			posTriangle_Dcd[0].setY( (DcdPos)( iY_Dcd + e_y_len                       + 0.5 ) ) ;
		//			posTriangle_Dcd[1].setX( (DcdPos)( iX_Dcd - e_x_len * 0.5 + e_y_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[1].setY( (DcdPos)( iY_Dcd - e_y_len * 0.5 - e_x_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[2].setX( (DcdPos)( iX_Dcd - e_x_len * 0.5 - e_y_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[2].setY( (DcdPos)( iY_Dcd - e_y_len * 0.5 + e_x_len * 0.5 + 0.5 ) ) ;

		//		}
		//		else
		//		{
		//			double dRessyasen_x_len = posRessyasen_Pos2_Dcd.getX() - 
		//			posRessyasen_Pos1_Dcd.getX() ;
		//			double dRessyasen_y_len =  posRessyasen_Pos1_Dcd.getY() - 
		//			posRessyasen_Pos2_Dcd.getY() ;
		//			double dRessyasen =  dRessyasen_x_len / dRessyasen_y_len ;

		//			//int iRessyasen_deg = (int)( RadToDeg( atan( dRessyasen ) ) ) ;
		//			//double e_x_len = ( dTriangleSize * sin( DegToRad( iRessyasen_deg ) ) ) ;
		//			//double e_y_len = ( dTriangleSize * cos( DegToRad( iRessyasen_deg ) ) ) ;
		//			double dRessyasen_rad = atan( dRessyasen ) ;
		//			double e_x_len = ( dTriangleSize * sin( dRessyasen_rad ) ) ;
		//			double e_y_len = ( dTriangleSize * cos( dRessyasen_rad ) ) ;

		//			//	�O�p�`�̒��_�����߂܂��B
		//			//	�Ō�� +0.5 �́A�����_�ȉ��̒[�����l�̌ܓ����邽�߂̂��̂ł��B
		//			posTriangle_Dcd[0].setX( (DcdPos)( iX_Dcd + e_x_len                       + 0.5 ) ) ;
		//			posTriangle_Dcd[0].setY( (DcdPos)( iY_Dcd - e_y_len                       + 0.5 ) ) ;
		//			posTriangle_Dcd[1].setX( (DcdPos)( iX_Dcd - e_x_len * 0.5 + e_y_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[1].setY( (DcdPos)( iY_Dcd + e_y_len * 0.5 + e_x_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[2].setX( (DcdPos)( iX_Dcd - e_x_len * 0.5 - e_y_len * 0.5 + 0.5 ) ) ;
		//			posTriangle_Dcd[2].setY( (DcdPos)( iY_Dcd + e_y_len * 0.5 - e_x_len * 0.5 + 0.5 ) ) ;
		//		}
		//	}
		//	//posTriangle = �R�p�`�̂R�_
		//	// --------------------------------
		//	CdPenProp	aCdPenProp( 1 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::SOLID ) ;
		//	HPEN hPen = m_pIfDcdTarget->CreatePen( aCdPenProp ) ;
		//	HPEN hPenPrev = (HPEN)SelectObject( m_pIfDcdTarget->getHdc() , hPen ) ;

		//	CdBrushProp	aCdBrushProp( CdColorProp( 0 , 0 , 0 ) , CdBrushProp::NULLBRUSH ) ;
		//	HBRUSH hBrush = m_pIfDcdTarget->CreateBrush( aCdBrushProp ) ;
		//	HBRUSH hBrushPrev = (HBRUSH)SelectObject( m_pIfDcdTarget->getHdc() , hBrush ) ;


		//	POINT pointTriangle[3] ;
		//	CConverter_WinGdi aConv ;
		//	pointTriangle[0] = aConv.POINTOf( posTriangle_Dcd[0] ) ;
		//	pointTriangle[1] = aConv.POINTOf( posTriangle_Dcd[1] ) ;
		//	pointTriangle[2] = aConv.POINTOf( posTriangle_Dcd[2] ) ;

		//	Polygon( 
		//		m_pIfDcdTarget->getHdc() , 
		//		pointTriangle , 
		//		3 //	�R�p�`
		//		) ;
		//	// --------------------------------
		//	//	GDI�I�u�W�F�N�g�̑I��������
		//	if ( hPenPrev != NULL )
		//	{
		//		SelectObject( m_pIfDcdTarget->getHdc() , hPenPrev ) ;
		//		hPenPrev = NULL ;
		//	}
		//	if ( hBrushPrev != NULL )
		//	{
		//		SelectObject( m_pIfDcdTarget->getHdc() , hBrushPrev ) ;
		//		hBrushPrev = NULL ;
		//	}
		//}

		// --------------------------------
		//	��ԃ}�[�N�̕`��(��)
		// --------------------------------
		{
			CdPenProp	aCdPenProp( 1 , CdColorProp( 0 , 0 , 0 ) , CdPenProp::SOLID ) ;
			Ou<CGdiHPenHolder>	pHPenHolder = m_pIfDcdTarget->createGdiHPenHolder( aCdPenProp ) ;
			HPEN hPenPrev = (HPEN)SelectObject( m_pIfDcdTarget->getHdc() , pHPenHolder->getHPen() ) ;

			CdBrushProp	aCdBrushProp( CdColorProp( 0 , 0 , 0 ) , CdBrushProp::NULLBRUSH ) ;
			Ou<CGdiHBrushHolder> pHBrushHolder = m_pIfDcdTarget->createGdiHBrushHolder( aCdBrushProp ) ;
			HBRUSH hBrushPrev = (HBRUSH)SelectObject( m_pIfDcdTarget->getHdc() , pHBrushHolder->getHBrush() ) ;

			Ellipse( 
				m_pIfDcdTarget->getHdc() , 
				iX_Dcd - 2 , 
				iY_Dcd - 2 , 
				iX_Dcd + 3 , 
				iY_Dcd + 3 ) ;
			// --------------------------------
			//	GDI�I�u�W�F�N�g�̑I��������
			if ( hPenPrev != NULL )
			{
				SelectObject( m_pIfDcdTarget->getHdc() , hPenPrev ) ;
				hPenPrev = NULL ;
			}
			if ( hBrushPrev != NULL )
			{
				SelectObject( m_pIfDcdTarget->getHdc() , hBrushPrev ) ;
				hBrushPrev = NULL ;
			}
		}

	}
}
} //namespace ViewDiagram
