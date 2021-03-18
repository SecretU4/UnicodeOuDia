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
//	ViewJikokuhyou\WndJikokuhyou\CCellBuilder.cpp
//	$Id: CCellBuilder.cpp 366 2016-08-18 20:26:22Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include "CCellBuilder.h"
#include "..\..\resource.h"

namespace ViewJikokuhyou{
namespace WndJikokuhyou{
	using namespace OuLib::Str;
using DcDraw::CDcdTextboxV3 ;

// --------------------------------
//@name �`�揈���Ɏg�p���� �e�L�X�g�`�摮��
// --------------------------------

CdDrawTextProp	CCellBuilder::getCdDrawTextPropMenutext()const
{ 
	CdDedDispProp aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	CConverter_WinGdi	aConv ;
	return CdDrawTextProp( 
		aCdDedDispProp.getJikokuhyouFont(0) ,
		aConv.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
}

CdDrawTextProp	CCellBuilder::getCdDrawTextPropStandard()const
{ 
	CdDedDispProp aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		aCdDedDispProp.getJikokuhyouFont(0) ,
		CdColorProp( 0 , 0 , 0 ) ) ;
}

CdDrawTextProp	CCellBuilder::getCdDrawTextPropTsuuka()const
{ 
	CdDedDispProp aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	return CdDrawTextProp( 
		aCdDedDispProp.getJikokuhyouFont(0) ,
		CdColorProp( 128 , 128 , 128 ) ,
		CdDrawTextFormat( CdDrawTextFormat::H_CENTER ) ) ;
}

const CdDedJikoku::CConv&	
CCellBuilder::getCdDedJikokuConv()const 
{
	static CdDedJikoku::CConv aConv(
		true ,		//	NoColon 
		// ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" ���X�y�[�X�ɂ��܂��B
		CdDedJikoku::CConv::EHour_ZeroToSpace ,	
		CdDedJikoku::CConv::ESecond_NoSecond 	// �b����ɏo�͂��܂���B 
		) ;
	return aConv ;
}
	// --------------------------------
	//@name �`�揈���Ɏg�p���� �u���V����
	// --------------------------------

CdBrushProp CCellBuilder::getCdBrushPropMenutext()const
{
	CConverter_WinGdi	aConv ;
	return CdBrushProp( aConv.CdColorPropOfSysColor( COLOR_MENU ) ) ;
}

CdBrushProp	CCellBuilder::getCdBrushPropStandard()const
{
	return CdBrushProp( CdColorProp( 255 , 255 , 255 ) ) ;
}

	// --------------------------------
	//@name �`�揈���Ɏg�p���� DcDraw�I�u�W�F�N�g�̃v���g�^�C�v
	// --------------------------------

CDcdTextbox CCellBuilder::createCDcdXColumn0()const
{
	string strExtent = m_pCDedRosenFileData->
		getCdDedDispProp().createEkimeiExtentString() ;
	//strExtent = �H���t�@�C���f�[�^�ɕۑ�����Ă���l�����Ƃɂ��āA
	//	�쐬�����A�����񕝂̊������ł��B

	CDcdTextbox aCDcd( 
		"" , 
		getCdDrawTextPropMenutext() ,
		strExtent ,
		1 ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropMenutext() 
	) ;
	return ( aCDcd ) ;
}

CDcdTextboxV3 CCellBuilder::createCDcdXColumn0V()const
{
	string strExtent = m_pCDedRosenFileData->
		getCdDedDispProp().createEkimeiExtentString() ;
	//strExtent = �H���t�@�C���f�[�^�ɕۑ�����Ă���l�����Ƃɂ��āA
	//	�쐬�����A�����񕝂̊������ł��B

	CdDedDispProp	aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	CConverter_WinGdi	aConv ;

	CDcdTextboxV3 aCDcd( 
		"" , 
		aCdDedDispProp.getJikokuhyouVFont() ,
		getRessyameiTextExtent().getX() ,
		getRessyameiTextExtent().getY() ,
		aConv.CdColorPropOfSysColor( COLOR_MENUTEXT ) ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropMenutext() ) ;
	return ( aCDcd ) ;
}


CDcdTextbox CCellBuilder::createCDcdEkimei()const
{
	string strExtent = m_pCDedRosenFileData->
		getCdDedDispProp().createEkimeiExtentString() ;
	//strExtent = �H���t�@�C���f�[�^�ɕۑ�����Ă���l�����Ƃɂ��āA
	//	�쐬�����A�����񕝂̊������ł��B

	CDcdTextbox aCDcd( 
		"" , 
		getCdDrawTextPropStandard() ,
		strExtent ,
		1 ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropStandard() ) ;
	return ( aCDcd ) ;
}


CDcdTextbox CCellBuilder::createCDcdHatsuchaku()const
{
	string strExtent = MfcUtil::LoadCString( IDS_WORD_Chaku );

	//strExtent = �H���t�@�C���f�[�^�ɕۑ�����Ă���l�����Ƃɂ��āA
	//	�쐬�����A�����񕝂̊������ł��B


	CDcdTextbox aCDcd( 
		"" , 
		getCdDrawTextPropStandard() ,
		strExtent ,
		1 ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropStandard() ) ;
	return ( aCDcd ) ;
}

CDcdTextbox CCellBuilder::createCDcdRessyabangou(
	int iRessyasyubetsuIndex )const
{
	CdDedDispProp	aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;
	string strCellExtent( aCdDedDispProp.getJikokuhyouRessyaWidth() , '0' ) ;
	//strCellExtent = �Z���̑傫���̖ڈ��ƂȂ镶����ł��B
	//	�����\��ԃZ���̕�(������) CdDedDispProp::m_iJikokuhyouRessyaWidth
	//	�̐����� '0' �����񂾕�����ł�

	const CentDedRessyasyubetsu* pCentDedRessyasyubetsu
		= m_pCDedRosenFileData->getCentDedRosen()->getCentDedRessyasyubetsuCont()
		->getMuPtr()->get( iRessyasyubetsuIndex ) ;
	
	CdDrawTextProp aCdDrawTextProp = getCdDrawTextPropStandard() ;

	aCdDrawTextProp.setCdDrawTextFormat( CdDrawTextFormat( CdDrawTextFormat::H_CENTER ) ) ;
	aCdDrawTextProp.setTextColor( 
		pCentDedRessyasyubetsu->getJikokuhyouMojiColor() ) ;


	CDcdTextbox aCDcd( 
		"" , 
		aCdDrawTextProp ,
		strCellExtent ,
		1 ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropStandard() ) ;
	return ( aCDcd ) ;
}

CDcdTextboxV3 CCellBuilder::createCDcdRessyamei(
	int iRessyasyubetsuIndex )const
{
	const CentDedRessyasyubetsu* pCentDedRessyasyubetsu
		= m_pCDedRosenFileData->getCentDedRosen()->getCentDedRessyasyubetsuCont()
		->getMuPtr()->get( iRessyasyubetsuIndex ) ;

	CdDedDispProp	aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;

	CDcdTextboxV3 aCDcd( 
		"" , 
		aCdDedDispProp.getJikokuhyouVFont(),
		getRessyameiTextExtent().getX() ,
		getRessyameiTextExtent().getY() ,
		pCentDedRessyasyubetsu->getJikokuhyouMojiColor() ,
		RectangleTextFrameWidth , RectangleTextFrameWidth ,
		CdPenProp() ,
		getCdBrushPropStandard() ) ;
	return ( aCDcd ) ;
}

CDcdTextbox CCellBuilder::createCDcdEkijikoku(
	int iRessyasyubetsuIndex )const
{
	const CentDedRessyasyubetsu* pCentDedRessyasyubetsu
		= m_pCDedRosenFileData->getCentDedRosen()->getCentDedRessyasyubetsuCont()
		->getMuPtr()->get( iRessyasyubetsuIndex ) ;
	int idxFont = pCentDedRessyasyubetsu->getJikokuhyouFontIndex() ;
	

	CDcdTextbox aCDcd 
		= createCDcdRessyabangou( iRessyasyubetsuIndex ) ;
		
	CdDrawTextProp	aCdDrawTextProp = aCDcd.getCdDrawTextProp() ;
	aCdDrawTextProp.setCdFontProp(
		m_pCDedRosenFileData
			->getCdDedDispProp().getJikokuhyouFont( idxFont ) ) ;
	aCDcd.setCdDrawTextProp( aCdDrawTextProp ) ;

	return ( aCDcd ) ;
}

	// --------------------------------
	//@name update() �̉����֐�
	// --------------------------------
void CCellBuilder::update01_updateWithoutRessya(
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// ********************************
	//(1.1)�@CWndDcdGrid �̊O�g����DcDraw�I�u�W�F�N�g�ƁA�񕝂�ݒ�
	// ********************************
	update01_01_setGridBorder( 
		pCWndJikokuhyou ) ;


	// ********************************
	//(1.2)�@��̐���ݒ肵�܂��B
	//	X�񐔂�2�����Ȃ�2�ɂ��܂��B
	//	Y�񐔂́ACdYColSpecCont ��
	//	���o���ꂽ�񐔂Ƃ��܂��B
	// ********************************
	{
		int iXColumnNumberMax = -1 ;
		{
			int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Ekimei ) ) ;
			iXColumnNumberMax = max( iXColumnNumberMax , iXColumnNumber ) ;
		}
		{
			int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Chakuhatsu ) ) ;
			iXColumnNumberMax = max( iXColumnNumberMax , iXColumnNumber ) ;
		}

		pCDcdGrid->setXColumnCount( max( iXColumnNumberMax + 1 , 
			pCDcdGrid->getXColumnCount() ) ) ;
		pCDcdGrid->setYColumnCount( m_CdYColSpecCont.size() ) ;
	}
 
	// ********************************
	//(1.3)�@X��(ColumnType_Ekimei) �̊e�Z���ƁA���ׂĂ�Y��̍����E
	//	Y�񋫊E���EY�񋫊E���̍����ݒ�
	// ********************************
	{
		CdXColSpec aCdXColSpec( 
			CdXColSpec::ColumnType_Ekimei ) ;
		int iXColumnNumber = 
			m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

		// ================================
		//(1.3.1)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) �ƁA
		//	Y��(ColumnType_Ressyabangou)�̍����EY�񋫊E���EY�񋫊E���̍����ݒ�
		// ================================
		update01_03_01_setEkimei_Ressyabangou( 
			pCWndJikokuhyou ) ;

		// ================================
		//	(1.3.2)�@���l�ɁA�Z��(ColumnType_Ekimei, 
		//	ColumnType_Ressyasyubetsu�` ColumnType_Bikou ) �ƁA
		//	Y��(ColumnType_Ressyasyubetsu�` ColumnType_Bikou)�̍����E
		//	Y�񋫊E���EY�񋫊E���̍�����ݒ�B
		// ================================
		// --------------------------------
		//	(1.3.2.2)�Z��(ColumnType_Ekimei, ColumnType_Ressyasyubetsu)
		// --------------------------------
		update01_03_02_02_setEkimei_Ressyasyubetsu( 
			pCWndJikokuhyou ) ;

		// --------------------------------
		//	(1.3.2.3)�Z��(ColumnType_Ekimei, ColumnType_Ressyamei)
		// --------------------------------
		update01_03_02_03_setEkimei_Ressyamei( 
			pCWndJikokuhyou ) ;


		// --------------------------------
		//	(1.3.2.4)�Z��(ColumnType_Ekimei, ColumnType_Gousuu)
		// --------------------------------
		update01_03_02_04_setEkimei_Gousuu( 
			pCWndJikokuhyou ) ;

		
		// --------------------------------
		//	(1.3.2.5)�Z��(ColumnType_Ekimei, ColumnType_Gou)
		// --------------------------------
		update01_03_02_05_setEkimei_Gou( 
			pCWndJikokuhyou ) ;

		
		// --------------------------------
		//	�Z��(ColumnType_Ekimei,ColumnType_Ekijikoku_Chaku)
		//	�Z��(ColumnType_Ekimei,ColumnType_Ekijikoku_Hatsu)
		// --------------------------------
		update01_03_02_06_setEkimei_Chaku( 
			pCWndJikokuhyou ) ;
		update01_03_02_07_setEkimei_Hatsu( 
			pCWndJikokuhyou ) ;
		
		// --------------------------------
		//	(1.3.2.8)�Z��(ColumnType_Ekimei,ColumnType_Bikou)
		// --------------------------------
		update01_03_02_08_setEkimei_Bikou( 
			pCWndJikokuhyou ) ;
		
		// ================================
		//(1.3.3)�@X��(ColumnType_Ekimei ) �̕���ݒ�B
		//	���́A�w����� DcDraw �I�u�W�F�N�g�̕��Ƃ��܂��B
		// ================================
		CDcdGridXColumn* pCDcdGridXColumn = pCDcdGrid->getXColumn( 
			iXColumnNumber ) ;
		if ( pCDcdGridXColumn )
		{
			CDcdTextbox aCDcdTextbox =createCDcdXColumn0() ;
			CdDcdSizeXy aCdDcdSizeXy ;
			if ( aCDcdTextbox.getItemSize( 
				&aCDcdTarget , &aCdDcdSizeXy ) )
			{
				pCDcdGridXColumn->setColumnSize( aCdDcdSizeXy.getX() ) ;
			}
		}
		// ================================
		//	(1.3.4)�@X��(ColumnType_Ekimei ) �̋��E���� DcDraw�I�u�W�F�N�g��
		//	������ݒ�B
		//	(1.3.5)�@X��(ColumnType_Ekimei ) �̋��E���̕���ݒ�B
		// ================================
		{
			CDcdGridXBorder* pCDcdGridXBorder 
				= pCDcdGridXColumn->getCDcdGridXBorder() ;
			Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw() ;

			pCDcdLine->setCdPenProp( CdPenProp() ) ;	//NULLPEN

			CdDcdSizeXy aCdDcdSizeXy ;
			if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
			{
				pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
			}
		}
	}

	// ********************************
	//(1.4)�@X��(ColumnType_Chakuhatsu) �̊e�Z����ݒ�
	// ********************************
	{
		CdXColSpec aCdXColSpec( 
			CdXColSpec::ColumnType_Chakuhatsu ) ;
		int iXColumnNumber = 
			m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
		// ================================
		//(1.4.1)�@�Z��(ColumnType_Chakuhatsu, 
		//	ColumnType_Ekijikoku_Chaku�` ColumnType_Ekijikoku_Hatsu) ��ݒ�B
		// ================================
		update01_04_01_06_setChakuhatsu_Chaku( 
			pCWndJikokuhyou ) ;
		update01_04_01_07_setChakuhatsu_Hatsu( 
			pCWndJikokuhyou ) ;
		// ================================
		//	(1.4.3)�@X��(ColumnType_Chakuhatsu ) �̕���ݒ�B
		//	���́A������� DcDraw �I�u�W�F�N�g�̕��Ƃ��܂��B
		// ================================
		CDcdGridXColumn* pCDcdGridXColumn = pCDcdGrid->getXColumn( 
			iXColumnNumber ) ;
		if ( pCDcdGridXColumn )
		{
			CDcdTextbox aCDcdTextbox = 
				createCDcdHatsuchaku() ;
			CdDcdSizeXy aCdDcdSizeXy ;
			if ( aCDcdTextbox.getItemSize( 
				&aCDcdTarget , &aCdDcdSizeXy ) )
			{
				pCDcdGridXColumn->setColumnSize( aCdDcdSizeXy.getX() ) ;
			}
		}

		// ================================
		//	(1.4.4)�@X��(ColumnType_Chakuhatsu ) �̋��E���� 
		//	DcDraw�I�u�W�F�N�g�̑�����ݒ�B
		//(1.4.5)�@X��(ColumnType_Chakuhatsu ) �̋��E���̕���ݒ�B
		// ================================
		{
			CDcdGridXBorder* pCDcdGridXBorder 
				= pCDcdGridXColumn->getCDcdGridXBorder() ;
			Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw() ;

			pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;	

			CdDcdSizeXy aCdDcdSizeXy ;
			if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
			{
				pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
			}
		}
	}
}

void CCellBuilder::update01_01_setGridBorder( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;


	//	��
	{
		CDcdGridXBorder* pCDcdGridXBorder = pCDcdGrid->getCDcdGridXBorderTop() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw();
		pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
		}
	}
	//	�E
	{
		CDcdGridXBorder* pCDcdGridXBorder 
			= pCDcdGrid->getCDcdGridXBorderBottom() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw();
		pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
		}
	}
	//	��
	{
		CDcdGridYBorder* pCDcdGridYBorder = pCDcdGrid->getCDcdGridYBorderTop() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw();
		pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridYBorder->setColumnBorderSize( aCdDcdSizeXy.getY() ) ;
		}
	}
	//	��
	{
		CDcdGridYBorder* pCDcdGridYBorder 
			= pCDcdGrid->getCDcdGridYBorderBottom() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw();
		pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridYBorder->setColumnBorderSize( aCdDcdSizeXy.getY() ) ;
		}
	}
}

void CCellBuilder::update01_03_01_setEkimei_Ressyabangou( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ressyabangou ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != 0 )
		{
			//(1.3.*.1)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	�̌����Z���̑�����ݒ�B
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	��DcDraw�I�u�W�F�N�g�̌^��ݒ�
			//	( CDcdTextbox �Ƃ���)�B
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}

			//(1.3.*.3)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
			{
				*pCDcDrawCell = createCDcdXColumn0() ;
				pCDcDrawCell->setText( stringOf( 
					(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_Ressyabangou ) ) ) ;
			}
		}

		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn )
		{
			//(1.3.*.4)�@Y��(ColumnType_Ressyabangou) �̃Z���̍�����ݒ�
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;
				}
			}
			//	�@(1.3.*.5)�@Y��(ColumnType_Ressyabangou) �̋��E����
			//	DcDraw�I�u�W�F�N�g �ɑ�����ݒ�B
			//	�@(1.3.*.6)�@Y��ColumnType_Ressyabangou) �̋��E����
			//	������ݒ�
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNarrowLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}


void CCellBuilder::update01_03_02_02_setEkimei_Ressyasyubetsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;


	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ressyasyubetsu ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)�@�����Z���̑�����ݒ�B
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)�@�Z�� 
			//	��DcDraw�I�u�W�F�N�g�̌^��ݒ�
			//	( CDcdTextbox �Ƃ���)�B
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)�@�Z���� DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
			{
				*pCDcDrawCell = createCDcdXColumn0() ;
				pCDcDrawCell->setText( stringOf( 
					(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_RESSYASYUBETSU ) ) ) ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)�@Y�� �̃Z���̍�����ݒ�
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;					}
			}
			//	�@(1.3.*.5)�@Y�� �̋��E����
			//	DcDraw�I�u�W�F�N�g �ɑ�����ݒ�B
			//	�@(1.3.*.6)�@Y�� �̋��E����
			//	������ݒ�
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNarrowLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}


void CCellBuilder::update01_03_02_03_setEkimei_Ressyamei( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ressyamei ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextboxV3 CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)�@�����Z���̑�����ݒ�B
			pCDcdGridCell->setAttachCellCount( 2 , 3 ) ;

			//	(1.3.*.2)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	��DcDraw�I�u�W�F�N�g�̌^��ݒ�
			//	( CDcdTextbox �Ƃ���)�B
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
			{
				*pCDcDrawCell = createCDcdXColumn0V() ;
				pCDcDrawCell->setText( stringOf( 
					(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_Ressyamei ) ) ) ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)�@Y�� �̃Z���̍�����ݒ�
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;					}
			}
			//	�@(1.3.*.5)�@Y�� �̋��E����
			//	DcDraw�I�u�W�F�N�g �ɑ�����ݒ�B
			//	�@(1.3.*.6)�@Y�� �̋��E����
			//	������ݒ�
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}


void CCellBuilder::update01_03_02_04_setEkimei_Gousuu( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Gousuu ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)�@�����Z���̑�����ݒ�B
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)�@�Z����DcDraw�I�u�W�F�N�g�̌^��ݒ�
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)�@�Z����DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
			{
				*pCDcDrawCell = createCDcdXColumn0() ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)�@Y�� �̃Z���̍�����ݒ�
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;					}
			}
			//	�@(1.3.*.5)�@Y�� �̋��E����
			//	DcDraw�I�u�W�F�N�g �ɑ�����ݒ�B
			//	�@(1.3.*.6)�@Y�� �̋��E����
			//	������ݒ�
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}


void CCellBuilder::update01_03_02_05_setEkimei_Gou( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Gou ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;

		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)�@�����Z���̑�����ݒ�B
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)�@�Z����DcDraw�I�u�W�F�N�g�̌^��ݒ�
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)�@�Z����DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
			{
				*pCDcDrawCell = createCDcdXColumn0() ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)�@Y�� �̃Z���̍�����ݒ�
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;					}
			}
			//	�@(1.3.*.5)�@Y�� �̋��E����
			//	DcDraw�I�u�W�F�N�g �ɑ�����ݒ�B
			//	�@(1.3.*.6)�@Y�� �̋��E����
			//	������ݒ�
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNarrowLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}

void CCellBuilder::update01_03_02_06_setEkimei_Chaku( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		m_pCentDedRessyaCont->getRessyahoukou() ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
	if ( iXColumnNumber >= 0 )
	{
		for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; 
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

			CdYColSpec aCdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Chaku , 
				iEkiOrder ) ;
			int iYColumnNumber = 
				m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
			CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
				iXColumnNumber , iYColumnNumber ) ;

			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			if ( pCDcdGridCell != 0 )
			{
				//(1.3.*.1)�@�Z���̌����Z���̑�����ݒ�B
				
				//	���̗񂪒��ŁA���̗񂪔��Ȃ�A���̗������
				CdYColSpec aCdYColSpecNext  
					= m_CdYColSpecCont.ColumnNumberToSpec( iYColumnNumber + 1 ) ;
				if ( aCdYColSpec.getColumnType() 
						== aCdYColSpec.ColumnType_Ekijikoku_Chaku
					&& aCdYColSpecNext.getColumnType() 
						== aCdYColSpecNext.ColumnType_Ekijikoku_Hatsu
					&& aCdYColSpec.getEkiOrder() 
						== aCdYColSpecNext.getEkiOrder() )
				{
					pCDcdGridCell->setAttachCellCount( 1 , 2 ) ;
				}
				else
				{
					pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;
				}

				//	(1.3.*.2)�@�Z����DcDraw�I�u�W�F�N�g�̌^��ݒ�
				//	( CDcdTextbox �Ƃ���)�B
				{
					pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
						pCDcdGridCell->getIfDcDraw() ) ;
					if ( pCDcDrawCell == NULL )
					{
						pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
						pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
					}
				}
				//(1.3.*.3)�@�Z����DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
				{
					*pCDcDrawCell = createCDcdEkimei() ;
					pCDcDrawCell->setText( aCdDedEki.getEkimei() );
				}
			}
			CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
				iYColumnNumber ) ;
			if ( pCDcdGridYColumn )
			{
				//(1.3.*.4)�@Y��̃Z���̍�����ݒ�
				{
					CdDcdSizeXy aCdDcdSizeXy ;
					if ( pCDcDrawCell->getItemSize( 
						&aCDcdTarget , &aCdDcdSizeXy ) )
					{
						pCDcdGridYColumn->setColumnSize( 
							aCdDcdSizeXy.getY() ) ;
					}
				}
				//	�@(1.3.*.5)�@Y��(ColumnType_Ressyabangou) �̋��E����
				//	DcDraw�I�u�W�F�N�g �ɑ�����ݒ�B
				//	�@(1.3.*.6)�@Y��ColumnType_Ressyabangou) �̋��E����
				//	������ݒ�
				{
					CDcdGridYBorder* pCDcdGridYBorder 
						= pCDcdGridYColumn->getCDcdGridYBorder() ;
					Ou<CDcdLine> pCDcdLine = 
						pCDcdGridYBorder->getIfDcDraw() ;

					//	���̉w�̉w�����`�����u�����v AND
					//	���̗񂪒��ŁA���̗񂪔��Ȃ�A���Ɍr��
					CdYColSpec aCdYColSpecNext  
						= m_CdYColSpecCont.ColumnNumberToSpec( 
							iYColumnNumber + 1 ) ;
					if ( aCdDedEki.getChakujikokuHyouji() &&
						aCdDedEki.getHatsujikokuHyouji() &&
						aCdYColSpec.getColumnType() 
							== aCdYColSpec.ColumnType_Ekijikoku_Chaku && 
						aCdYColSpecNext.getColumnType() 
							== aCdYColSpecNext.ColumnType_Ekijikoku_Hatsu && 
						aCdYColSpec.getEkiOrder() 
							== aCdYColSpecNext.getEkiOrder() )
					{
						pCDcdLine->setCdPenProp( 
							getCdPenPropNarrowLine() ) ;
					}
					//	���̗񂪈قȂ�w�̗�B AND
					//	���w�Ɂw���E���x����������B
					//
					//	���������𖞂����ꍇ�́A
					//	���i���̉w�Ƃ̊ԁj�Ɍr��
					else if ( aCdYColSpecNext.isEkiJikoku() 
						&& aCdYColSpec.getEkiOrder() 
							!= aCdYColSpecNext.getEkiOrder() 
						&& aCdDedEki.getKyoukaisen() ) 
					{
						pCDcdLine->setCdPenProp( 
							getCdPenPropNarrowLine() ) ;
					}
					//	���̗񂪉w�����ȊO�̏ꍇ�́A����
					else if ( !aCdYColSpecNext.isEkiJikoku() )
					{
						pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;
					}
					else
					{
						pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;
					}

					// --------------------------------
					//	���̕�����A�񕝂�ݒ�
					CdDcdSizeXy aCdDcdSizeXy ;
					if ( pCDcdLine->getItemSize( 
						&aCDcdTarget , &aCdDcdSizeXy ) )
					{
						pCDcdGridYBorder->setColumnBorderSize( 
							aCdDcdSizeXy.getX() ) ;
					}
				}
			}
		}
	}
}

void CCellBuilder::update01_03_02_07_setEkimei_Hatsu( 
	CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		m_pCentDedRessyaCont->getRessyahoukou() ) ;

	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
	if ( iXColumnNumber >= 0 )
	{
		for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; 
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

			CdYColSpec aCdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
				iEkiOrder ) ;
			int iYColumnNumber = 
				m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
			CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
				iXColumnNumber , iYColumnNumber ) ;

			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			if ( pCDcdGridCell != 0 )
			{
				//(1.3.*.1)�@�Z���̌����Z���̑�����ݒ�B
				
				pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

				//	(1.3.*.2)�@�Z����DcDraw�I�u�W�F�N�g�̌^��ݒ�
				//	( CDcdTextbox �Ƃ���)�B
				{
					pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
						pCDcdGridCell->getIfDcDraw() ) ;
					if ( pCDcDrawCell == NULL )
					{
						pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
						pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
					}
				}
				//(1.3.*.3)�@�Z����DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
				{
					*pCDcDrawCell = createCDcdEkimei() ;
					pCDcDrawCell->setText( aCdDedEki.getEkimei() );
				}
			}

			CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
				iYColumnNumber ) ;
			if ( pCDcdGridYColumn )
			{
				//(1.3.*.4)�@Y��̃Z���̍�����ݒ�
				{
					CdDcdSizeXy aCdDcdSizeXy ;
					if ( pCDcDrawCell->getItemSize( 
						&aCDcdTarget , &aCdDcdSizeXy ) )
					{
						pCDcdGridYColumn->setColumnSize( 
							aCdDcdSizeXy.getY() ) ;
					}
				}
				//	�@(1.3.*.5)�@Y��(ColumnType_Ressyabangou) �̋��E����
				//	DcDraw�I�u�W�F�N�g �ɑ�����ݒ�B
				//	�@(1.3.*.6)�@Y��ColumnType_Ressyabangou) �̋��E����
				//	������ݒ�
				{
					CDcdGridYBorder* pCDcdGridYBorder 
						= pCDcdGridYColumn->getCDcdGridYBorder() ;
					Ou<CDcdLine> pCDcdLine = 
						pCDcdGridYBorder->getIfDcDraw() ;

					CdYColSpec aCdYColSpecNext  
						= m_CdYColSpecCont.ColumnNumberToSpec( 
							iYColumnNumber + 1 ) ;
					//	���̗񂪈قȂ�w�̗�B
					//	���w�Ɂw���E���x����������B
					//
					//	���������𖞂����ꍇ�́A
					//	���i���̉w�Ƃ̊ԁj�Ɍr��
					if ( aCdYColSpecNext.isEkiJikoku() 
						&& aCdYColSpec.getEkiOrder() 
							!= aCdYColSpecNext.getEkiOrder() 
						&& aCdDedEki.getKyoukaisen() ) 
					{
						pCDcdLine->setCdPenProp( 
							getCdPenPropNarrowLine() ) ;
					}
					//	���̗񂪉w�����ȊO�̏ꍇ�́A����
					else if ( !aCdYColSpecNext.isEkiJikoku() )
					{
						pCDcdLine->setCdPenProp( getCdPenPropBoldLine() ) ;
					}
					else
					{
						pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;
					}

					// --------------------------------
					//	���̕�����A�񕝂�ݒ�
					CdDcdSizeXy aCdDcdSizeXy ;
					if ( pCDcdLine->getItemSize( 
						&aCDcdTarget , &aCdDcdSizeXy ) )
					{
						pCDcdGridYBorder->setColumnBorderSize( 
							aCdDcdSizeXy.getX() ) ;
					}
				}
			}
		}
	}
}

void CCellBuilder::update01_03_02_08_setEkimei_Bikou( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Ekimei ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;

	if ( iXColumnNumber >= 0 )
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Bikou ) ;
		int iYColumnNumber = m_CdYColSpecCont.ColumnNumberFromSpec( 
			aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;

		typedef CDcdTextboxV3 CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		if ( pCDcdGridCell != NULL )
		{
			//(1.3.*.1)�@�����Z���̑�����ݒ�B
			pCDcdGridCell->setAttachCellCount( 2 , 1 ) ;

			//	(1.3.*.2)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	��DcDraw�I�u�W�F�N�g�̌^��ݒ�
			//	( CDcdTextbox �Ƃ���)�B
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//(1.3.*.3)�@�Z��(ColumnType_Ekimei,ColumnType_Ressyabangou) 
			//	DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
			{
				*pCDcDrawCell = createCDcdXColumn0V() ;
				pCDcDrawCell->setLinesExtentX ( getBikouTextExtent().getX() ) ;
				pCDcDrawCell->setLinesExtentY ( getBikouTextExtent().getY() ) ;
				pCDcDrawCell->setText( stringOf( 
					(LPCTSTR)MfcUtil::LoadCString( 
					IDS_WORD_Bikou ) ) ) ;
			}
		}
		CDcdGridYColumn* pCDcdGridYColumn = pCDcdGrid->getYColumn( 
			iYColumnNumber ) ;
		if ( pCDcdGridYColumn != NULL )
		{
			//(1.3.*.4)�@Y�� �̃Z���̍�����ݒ�
			{
				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcDrawCell->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYColumn->setColumnSize( aCdDcdSizeXy.getY() ) ;
				}
			}
			//	�@(1.3.*.5)�@Y�� �̋��E����
			//	DcDraw�I�u�W�F�N�g �ɑ�����ݒ�B
			//	�@(1.3.*.6)�@Y�� �̋��E����
			//	������ݒ�
			{
				CDcdGridYBorder* pCDcdGridYBorder 
					= pCDcdGridYColumn->getCDcdGridYBorder() ;
				Ou<CDcdLine> pCDcdLine = pCDcdGridYBorder->getIfDcDraw() ;
				pCDcdLine->setCdPenProp( getCdPenPropNullLine() ) ;

				CdDcdSizeXy aCdDcdSizeXy ;
				if ( pCDcdLine->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) )
				{
					pCDcdGridYBorder->setColumnBorderSize( 
						aCdDcdSizeXy.getX() ) ;
				}
			}
		}
	}
}

void CCellBuilder::update01_04_01_06_setChakuhatsu_Chaku( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		m_pCentDedRessyaCont->getRessyahoukou() ) ;
	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Chakuhatsu ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
	if ( iXColumnNumber >= 0 )
	{
		for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; 
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

			CdYColSpec aCdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Chaku , 
				iEkiOrder ) ;
			int iYColumnNumber = 
				m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
			CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
				iXColumnNumber , iYColumnNumber ) ;

			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			if ( pCDcdGridCell != 0 )
			{
				//(1.4.1.*.1)�@�Z���̌����Z���̑�����ݒ�B
				pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;
			
				//	(1.4.1.*.2)�@�Z����DcDraw�I�u�W�F�N�g�̌^��ݒ�
				//	( CDcdTextbox �Ƃ���)�B
				{
					pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
						pCDcdGridCell->getIfDcDraw() ) ;
					if ( pCDcDrawCell == NULL )
					{
						pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
						pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
					}
				}
				//(1.4.1.*.3)�@�Z����DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
				{
					*pCDcDrawCell = createCDcdHatsuchaku();
					pCDcDrawCell->setText( stringOf( 
						(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_Chaku ) ) );
				}
			}
		}
	}
	
}
void CCellBuilder::update01_04_01_07_setChakuhatsu_Hatsu( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		m_pCentDedRessyaCont->getRessyahoukou() ) ;
	// --------------------------------
	CdXColSpec aCdXColSpec( 
		CdXColSpec::ColumnType_Chakuhatsu ) ;
	int iXColumnNumber = 
		m_CdXColSpecCont.ColumnNumberFromSpec( aCdXColSpec ) ;
	if ( iXColumnNumber >= 0 )
	{
		for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; 
			iEkiOrder ++ )
		{
			CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

			CdYColSpec aCdYColSpec( 
				CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
				iEkiOrder ) ;
			int iYColumnNumber = 
				m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
			CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
				iXColumnNumber , iYColumnNumber ) ;

			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			if ( pCDcdGridCell != 0 )
			{
				//(1.4.1.*.1)�@�Z���̌����Z���̑�����ݒ�B
				pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;
			
				//	(1.4.1.*.2)�@�Z����DcDraw�I�u�W�F�N�g�̌^��ݒ�
				//	( CDcdTextbox �Ƃ���)�B
				{
					pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
						pCDcdGridCell->getIfDcDraw() ) ;
					if ( pCDcDrawCell == NULL )
					{
						pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
						pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
					}
				}
				//(1.4.1.*.3)�@�Z����DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
				{
					*pCDcDrawCell = createCDcdHatsuchaku();
					pCDcDrawCell->setText( stringOf( 
						(LPCTSTR)MfcUtil::LoadCString( 
						IDS_WORD_Hatsu ) ) );
				}
			}
		}
	}
}


void CCellBuilder::update02_02_updateRessya( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;

	// ================================
	//�@(2.2.1)�@�Z��(ColumnType_Ressya ,
	//	ColumnType_Ressyabangou) ��ݒ�
	// ================================
	update02_02_01_setRessya_Ressyabangou( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;

	// ================================
	//�@(2.2.2)�@���l�ɁA�Z��(ColumnType_Ressya, 
	//	ColumnType_Ressyasyubetsu�` ColumnType_Bikou ) ��ݒ�B
	// ================================

	// --------------------------------
	//	(2.2.2.2)�Z��(ColumnType_Ressya, ColumnType_Ressyasyubetsu)
	// --------------------------------
	update02_02_02_02_setRessya_Ressyasyubetsu( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;

	// --------------------------------
	//	(2.2.2.3)�Z��(ColumnType_Ressya, ColumnType_Ressyamei)
	// --------------------------------
	update02_02_02_03_setRessya_Ressyamei( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;

	// --------------------------------
	//	(2.2.2.4)�Z��(ColumnType_Ressya, ColumnType_Gousuu)
	// --------------------------------
	update02_02_02_04_setRessya_Gousuu( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;


	// --------------------------------
	//	(2.2.2.5)�Z��(ColumnType_Ressya, ColumnType_Gou)
	// --------------------------------
	update02_02_02_05_setRessya_Gou( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;


	// --------------------------------
	//	(2.2.2.6)�Z��(ColumnType_Ressya,ColumnType_Ekijikoku_Chaku)
	//	(2.2.2.7)�Z��(ColumnType_Ressya,ColumnType_Ekijikoku_Hatsu)
	// --------------------------------
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		m_pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont()->getMuPtr(
		pCentDedRessya->getRessyahoukou() ) ;
	for ( int iEkiOrder = 0 ; iEkiOrder < muCdDedEki->size() ; iEkiOrder ++ )
	{
		update02_02_02_06_setRessya_Chaku( 
			iXColumnNumber , 
			pCentDedRessya ,
			iEkiOrder , 
			pCWndJikokuhyou ) ;
		update02_02_02_07_setRessya_Hatsu( 
			iXColumnNumber , 
			pCentDedRessya ,
			iEkiOrder , 
			pCWndJikokuhyou ) ;
	}
	// --------------------------------
	//	(2.2.2.8)�Z��(ColumnType_Ressya,ColumnType_Bikou)
	// --------------------------------
	update02_02_02_08_setRessya_Bikou( 
		iXColumnNumber , 
		pCentDedRessya ,
		pCWndJikokuhyou ) ;

	// ================================
	//�@(2.2.3)�@X��(ColumnType_Ressya ) �̕���ݒ�B
	//	���́A�w������� DcDraw �I�u�W�F�N�g�̕��Ƃ��܂��B
	// ================================
	CDcdGridXColumn* pCDcdGridXColumn 
		= pCDcdGrid->getXColumn( iXColumnNumber ) ;
	{
		{
			CDcdGridCell* pCDcdGridCell 
				= pCDcdGrid->getCell( iXColumnNumber , 0 ) ;
			CdDcdSizeXy	aCdDcdSizeXy ;
			if ( pCDcdGridCell->getIfDcDraw()->getItemSize( 
					&aCDcdTarget , &aCdDcdSizeXy ) ){
				pCDcdGridXColumn->setColumnSize( aCdDcdSizeXy.getX() ) ;
			}
		}
	}

	// ================================
	//�@(2.2.4)�@X��(ColumnType_Ressya ) �̋��E���� 
	//	DcDraw�I�u�W�F�N�g�̑�����ݒ�B
	//�@(2.2.5)�@X��(ColumnType_Ressya ) �̋��E���̕���ݒ�B
	// ================================
	{
		CDcdGridXBorder* pCDcdGridXBorder 
			= pCDcdGridXColumn->getCDcdGridXBorder() ;
		Ou<CDcdLine> pCDcdLine = pCDcdGridXBorder->getIfDcDraw() ;

		pCDcdLine->setCdPenProp( getCdPenPropNarrowLine() ) ;

		CdDcdSizeXy aCdDcdSizeXy ;
		if ( pCDcdLine->getItemSize( &aCDcdTarget , &aCdDcdSizeXy ) )
		{
			pCDcdGridXBorder->setColumnBorderSize( aCdDcdSizeXy.getX() ) ;
		}
	}
	// ================================
	//	X����ĕ`��̈�Ƃ��܂��B
	// ================================
	{
		CdDcdZoneXy	aCdDcdZoneXy ;
		//X��͈̔�
		{
			CdDcdZone	zoneXColumnZone = pCDcdGrid->getXColumnZone( 
				&aCDcdTarget , 
				iXColumnNumber ) ;
			CdDcdZone	zoneXColumnBorderZone = pCDcdGrid->getXColumnBorderZone( 
				&aCDcdTarget , 
				iXColumnNumber ) ;
			
			aCdDcdZoneXy.setX( 
				zoneXColumnZone.ZoneOr( zoneXColumnBorderZone ) ) ;
		}
		//Y��͈̔�
		{
			CdDcdZone	zoneYColumnTop = pCDcdGrid->getYColumnZone( 
				&aCDcdTarget , 
				0 ) ;
			CdDcdZone	zoneYColumnBottom = pCDcdGrid->getYColumnZone( 
				&aCDcdTarget , 
				INT_MAX ) ;
			aCdDcdZoneXy.setY( 
				zoneYColumnTop.ZoneOr( zoneYColumnBottom ) ) ;
		}
		CConverter_WinGdi	aConv ;
		pCWndJikokuhyou->InvalidateRect( 
			&aConv.RECTOf( aCdDcdZoneXy ) ) ; 
	}
}

void CCellBuilder::update02_02_01_setRessya_Ressyabangou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Ressyabangou ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	CdDedDispProp	aCdDedDispProp = m_pCDedRosenFileData->getCdDedDispProp() ;
	string strCellExtent( aCdDedDispProp.getJikokuhyouRessyaWidth() , '0' ) ;
	//strCellExtent = �Z���̑傫���̖ڈ��ƂȂ镶����ł��B
	//	�����\��ԃZ���̕�(������) CdDedDispProp::m_iJikokuhyouRessyaWidth
	//	�̐����� '0' �����񂾕�����ł�

	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//�@(2.2.*.1)�@�Z��(ColumnType_Ressya,ColumnType_Ressyabangou) ��
		//	�����Z����ݒ�
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//�@(2.2.*.2)�@�Z�� ��	DcDraw�I�u�W�F�N�g�̌^��ݒ�
		//	( CDcdTextbox �Ƃ���)�B
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}

		//�@(2.2.*.3)�@�Z���� DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
		{
			int idxRessyasyubetsu 
					= pCentDedRessya->getRessyasyubetsuIndex() ;
			string strText = pCentDedRessya->getRessyabangou() ;
			
			*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu ) ;
			pCDcDrawCell->setText( strText );
		}
	}
}


void CCellBuilder::update02_02_02_02_setRessya_Ressyasyubetsu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Ressyasyubetsu ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//�@(2.2.*.1)�@�Z��(ColumnType_Ressya,ColumnType_Ressyabangou) ��
		//	�����Z����ݒ�
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//�@(2.2.*.2)�@�Z�� ��	DcDraw�I�u�W�F�N�g�̌^��ݒ�
		//	( CDcdTextbox �Ƃ���)�B
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}

		//�@(2.2.*.3)�@�Z���� DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;
			const CentDedRessyasyubetsu* pCentDedRessyasyubetsu = NULL ;
			{
				pCentDedRessyasyubetsu = 
					pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr()
						->get( idxRessyasyubetsu ) ;
				if ( pCentDedRessyasyubetsu == NULL )
				{
					pCentDedRessyasyubetsu = 
						pCentDedRosen->getCentDedRessyasyubetsuCont()
						->getMuPtr()->get( 0 ) ;
				}
			}
			//pCentDedRessyasyubetsu = ��Ԏ�ʃI�u�W�F�N�g
			//	(�w�肪�Ȃ��Ȃ�A��Ԏ��[0])

			string strText ;
			if ( !pCentDedRessya->isNull() )
			{
				strText = pCentDedRessyasyubetsu->getRyakusyou() ;
			}
			*pCDcDrawCell = createCDcdEkijikoku( idxRessyasyubetsu );
			pCDcDrawCell->setText( strText );
		}
	}

}
	
void CCellBuilder::update02_02_02_03_setRessya_Ressyamei( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Ressyamei ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextboxV3 CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//�@(2.2.*.1)�@�Z��(ColumnType_Ressya,ColumnType_Ressyabangou) ��
		//	�����Z����ݒ�
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//�@(2.2.*.2)�@�Z�� ��	DcDraw�I�u�W�F�N�g�̌^��ݒ�
		//	( CDcdTextbox �Ƃ���)�B
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}
		//�@(2.2.*.3)�@�Z���� DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;
			string strText ;
			if ( !pCentDedRessya->isNull() )
			{
				strText = pCentDedRessya->getRessyamei() ;
			}
			*pCDcDrawCell = createCDcdRessyamei( idxRessyasyubetsu );
			pCDcDrawCell->setText( strText );
		}
	}


}
	
void CCellBuilder::update02_02_02_04_setRessya_Gousuu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Gousuu ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//�@(2.2.*.1)�@�Z��(ColumnType_Ressya,ColumnType_Ressyabangou) ��
		//	�����Z����ݒ�
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//�@(2.2.*.2)�@�Z�� ��	DcDraw�I�u�W�F�N�g�̌^��ݒ�
		//	( CDcdTextbox �Ƃ���)�B
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}
		//�@(2.2.*.3)�@�Z���� DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;
			string strText = pCentDedRessya->getGousuu() ;
			*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
			pCDcDrawCell->setText( strText );
		}
	}
}
	
void CCellBuilder::update02_02_02_05_setRessya_Gou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Gou ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextbox CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//�@(2.2.*.1)�@�Z���̌����Z����ݒ�
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//�@(2.2.*.2)�@�Z�� ��	DcDraw�I�u�W�F�N�g�̌^��ݒ�
		//	( CDcdTextbox �Ƃ���)�B
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}
		//�@(2.2.*.3)�@�Z���� DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;

			CString	strText ;
			if ( !pCentDedRessya->getGousuu().empty() )
			{
				strText.LoadString( IDS_WORD_GOUSUU2 ) ;
			}

			*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
			pCDcDrawCell->setText( (LPCTSTR)strText );
		}
	}
}

void CCellBuilder::update02_02_02_06_setRessya_Chaku( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		int iEkiOrder ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		pCentDedRosen->getCentDedEkiCont()->getMuPtr(
			pCentDedRessya->getRessyahoukou() ) ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ekijikoku_Chaku , 
			iEkiOrder ) ;
		int iYColumnNumber = 
			m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;
		// --------------------------------
		if ( pCDcdGridCell != 0 )
		{
			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			// --------------------------------
			//�@(2.2.*.1)�@�Z���̌����Z����ݒ�
			pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

			//�@(2.2.*.2)�@�Z�� ��	DcDraw�I�u�W�F�N�g�̌^��ݒ�
			//	( CDcdTextbox �Ƃ���)�B
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//�@(2.2.*.3)�@�Z���� DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
			{
				CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;

				int idxRessyasyubetsu 
					= pCentDedRessya->getRessyasyubetsuIndex() ;
				
				//	��v�w�ł́A�󗓂Ɏ�v�w�\�L���s���܂��B
				//	�N�_�E�I�_�E�����w�̂����ꂩ�ł���ꍇ�A
				//	���E���ɐڂ��Ă���w�ł���ꍇ�͏����܂��B
				bool bIsSyuyouEkiHyouki = false ;
				if ( aCdDedEki.getEkikibo() == CentDedEki::Ekikibo_Syuyou 
					&&	0 < iEkiOrder 
					&& iEkiOrder < muCdDedEki->size() - 1 
					&& 	!aCdDedEki.isHatsuChakuHyouji() )
				{
					//	���E���ɐڂ��Ă���w�ł���ꍇ�͏����܂��B
					CentDedEkiCont::CdDedEki aCentDedEkiTonari ;
					if ( iEkiOrder > 0 )
					{
						aCentDedEkiTonari = muCdDedEki->get( iEkiOrder - 1 ) ;
					}

					if ( !aCentDedEkiTonari.getKyoukaisen()  && 
						!aCdDedEki.getKyoukaisen() )
					{
						bIsSyuyouEkiHyouki = true ;
					}
				}
				//bIsSyuyouEkiHyouji = �󗓂Ɏ�v�w�\�L���s���܂��B

				CentDedEkiJikoku	aCentDedEkiJikoku =
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
				CdDedJikoku aCdDedJikoku 
							= aCentDedEkiJikoku.getChakujikoku() ;


				// --------------------------------
				//	�w�����ɍ��킹�āA�Z���ɕ�����\��
				// --------------------------------
				switch( aCentDedEkiJikoku.getEkiatsukai() )
				{
				case CentDedEkiJikoku::Ekiatsukai_None :
					{
						if ( bIsSyuyouEkiHyouki )
						{
							//	��v�w�ł̕\�L�i�����̏ꍇ�͏����j
							//	"----"
							*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_SYUYOU ) ) ;
						}
						else
						{
							//	���̑��̉w�ł̕\�L
							//	"�E�E"
							*pCDcDrawCell = createCDcdRessyabangou(  idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_IPPAN ) ) ;
						}
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Keiyunasi :
					{
						*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
						pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
								IDS_WORD_JIKOKUHYOU_KEIYUNASI ) );//"||"
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Tsuuka :
					{
						if ( !aCdDedJikoku.isNull() && m_bDisplayTsuukaEkiJikoku )
						{
							//	�ʉ߉w�̉w�������ݒ肳��Ă���A
							//	�w�ʉ߉w�̉w������\������x�w��ɂȂ��Ă���ꍇ��
							//	������\��
							*pCDcDrawCell = createCDcdRessyabangou( idxRessyasyubetsu );
							string strText = getCdDedJikokuConv().encode( aCdDedJikoku ) ;
							pCDcDrawCell->setText(strText ) ;
							pCDcDrawCell->setCdDrawTextProp( 
								getCdDrawTextPropTsuuka() ) ;
						}	
						else
						{
							*pCDcDrawCell = createCDcdRessyabangou( 
								idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
								IDS_WORD_JIKOKUHYOU_TSUUKA ) );	//" �"
						}
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Teisya :
					{
						//	��ԉw�̉w�������w�肳��Ă���
						if ( !aCdDedJikoku.isNull() )
						{
							*pCDcDrawCell = createCDcdEkijikoku( 
								idxRessyasyubetsu );
							string strText = getCdDedJikokuConv().encode( aCdDedJikoku ) ;
							pCDcDrawCell->setText(strText ) ;
						}
						//	��ԉw�̉w�������w�肳��Ă��Ȃ�
						else 
						{
							*pCDcDrawCell = createCDcdRessyabangou(
								idxRessyasyubetsu );

							//	[�����\�r���[��̔������̕\������Z�o
							CdYColSpec aCdYColSpec( 
								CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
								iEkiOrder ) ;
							int iYColumnNumberHatsu = 
								m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;


							//	�����\�r���[�㔭�����̕\������ AND 
							//	�n���w�̏ꍇ�� "�E�E" �\��
							if ( iYColumnNumberHatsu >= 0 && 
								pCentDedRessya->getSihatsuEki() == iEkiOrder )
							{
								pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_IPPAN ) ) ;
							}
							//	�r���E�I���w�̏ꍇ�E�������̂ݕ\���̏ꍇ�� " �� " �\��
							else	
							{
								pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_TEISYA ) ) ;
							}
						}
					}
					break ;
				}
				//  �P�D�`�w�́w�w�����`���x���w�����x
				//  �Q�D��Ԃe�́A�`�w�ł̉w�����w��ԁx���w�ʉ߁x�̂����ꂩ
				//  �R�D��Ԃe�́A�`�w�̒���������
				//  �S�D��Ԃe�́A�`�w�̑O�̉w�ł̉w�����w�o�R�Ȃ��x
				//
				//  ���̏ꍇ�́A�����\�r���[��ł́A��Ԃe�̂`�w�ł̒������� " || " �\���Ƃ��܂��B
				{
					CentDedEkiJikoku aCentDedEkijikokuPrev ;
					if ( 0 <= iEkiOrder - 1 
						&& iEkiOrder - 1 < muCdDedEki->size() ) 
					{
						aCentDedEkijikokuPrev = 
							pCentDedRessya->getCentDedEkiJikoku(
								iEkiOrder - 1 ) ;
					}
					//aCentDedEkijikokuPrev = �O�̉w�̉w����

					if ( aCdDedEki.isHatsuChakuHyouji() && 
						( aCentDedEkiJikoku.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Teisya || 
							aCentDedEkiJikoku.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Tsuuka ) && 
						aCentDedEkiJikoku.getChakujikoku().isNull() && 
						aCentDedEkijikokuPrev.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
					{
						pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
							IDS_WORD_JIKOKUHYOU_KEIYUNASI ) );	//"||"
					}
				}
			}
		}
	}
}
	
void CCellBuilder::update02_02_02_07_setRessya_Hatsu( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		int iEkiOrder ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	const Mu<CentDedEkiCont::CdDedEki>* muCdDedEki = 
		pCentDedRosen->getCentDedEkiCont()->getMuPtr(
			pCentDedRessya->getRessyahoukou() ) ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	{
		CdYColSpec aCdYColSpec( 
			CdYColSpec::ColumnType_Ekijikoku_Hatsu , 
			iEkiOrder ) ;
		int iYColumnNumber = 
			m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
		CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
			iXColumnNumber , iYColumnNumber ) ;
		// --------------------------------
		if ( pCDcdGridCell != 0 )
		{
			typedef CDcdTextbox CDcDrawCell ;
			Ou<CDcDrawCell> pCDcDrawCell ;
			// --------------------------------
			//�@(2.2.*.1)�@�Z���̌����Z����ݒ�
			pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

			//�@(2.2.*.2)�@�Z�� ��	DcDraw�I�u�W�F�N�g�̌^��ݒ�
			//	( CDcdTextbox �Ƃ���)�B
			{
				pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
					pCDcdGridCell->getIfDcDraw() ) ;
				if ( pCDcDrawCell == NULL )
				{
					pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
					pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
				}
			}
			//�@(2.2.*.3)�@�Z���� DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
			{
				CentDedEkiCont::CdDedEki aCdDedEki = muCdDedEki->get( iEkiOrder ) ;
				int idxRessyasyubetsu 
					= pCentDedRessya->getRessyasyubetsuIndex() ;
				//	��v�w�ł́A�󗓂Ɏ�v�w�\�L���s���܂��B
				//	�N�_�E�I�_�E�����w�̂����ꂩ�ł���ꍇ�A
				//	���E���ɐڂ��Ă���w�ł���ꍇ�͏����܂��B
				bool bIsSyuyouEkiHyouki = false ;
				if ( aCdDedEki.getEkikibo() == CentDedEki::Ekikibo_Syuyou 
					&&	0 < iEkiOrder 
					&& iEkiOrder < muCdDedEki->size() - 1 
					&& 	!aCdDedEki.isHatsuChakuHyouji() )
				{
					//	���E���ɐڂ��Ă���w�ł���ꍇ�͏����܂��B
					CentDedEkiCont::CdDedEki aCentDedEkiTonari ;
					if ( iEkiOrder > 0 )
					{
						aCentDedEkiTonari = muCdDedEki->get( iEkiOrder - 1 ) ;
					}

					if ( !aCentDedEkiTonari.getKyoukaisen()  && 
						!aCdDedEki.getKyoukaisen() )
					{
						bIsSyuyouEkiHyouki = true ;
					}
				}
				//bIsSyuyouEkiHyouji = �󗓂Ɏ�v�w�\�L���s���܂��B

				CentDedEkiJikoku	aCentDedEkiJikoku =
					pCentDedRessya->getCentDedEkiJikoku( iEkiOrder ) ;
				CdDedJikoku aCdDedJikoku 
					= aCentDedEkiJikoku.getHatsujikoku() ;

				// --------------------------------
				//	�w�����ɍ��킹�āA�Z���ɕ�����\��
				// --------------------------------
				switch( aCentDedEkiJikoku.getEkiatsukai() )
				{
				case CentDedEkiJikoku::Ekiatsukai_None :
					{
						if ( bIsSyuyouEkiHyouki )
						{
							//	��v�w�ł̕\�L�i�����̏ꍇ�͏����j
							//	"----"
							*pCDcDrawCell = createCDcdRessyabangou(
								idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_SYUYOU ) ) ;
						}
						else
						{
							//	���̑��̉w�ł̕\�L
							//	"�E�E"
							*pCDcDrawCell = createCDcdRessyabangou( 
								idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_IPPAN ) ) ;
						}
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Keiyunasi :
					{
						*pCDcDrawCell = createCDcdRessyabangou( 
							idxRessyasyubetsu );
						pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
								IDS_WORD_JIKOKUHYOU_KEIYUNASI ) );//"||"
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Tsuuka :
					{
						if ( !aCdDedJikoku.isNull() && m_bDisplayTsuukaEkiJikoku )
						{
							//	�ʉ߉w�̉w�������ݒ肳��Ă���A
							//	�w�ʉ߉w�̉w������\������x�w��ɂȂ��Ă���ꍇ��
							//	������\��
							string strText = getCdDedJikokuConv().encode( aCdDedJikoku ) ;
							pCDcDrawCell->setText(strText ) ;
							pCDcDrawCell->setCdDrawTextProp( 
								getCdDrawTextPropTsuuka() ) ;
						}	
						else
						{
							*pCDcDrawCell = createCDcdRessyabangou( 
								idxRessyasyubetsu );
							pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
								IDS_WORD_JIKOKUHYOU_TSUUKA ) );	//" �"
						}
					}
					break ;
				 case CentDedEkiJikoku::Ekiatsukai_Teisya :
					{
						//	��ԉw�̉w�������w�肳��Ă���
						if ( !aCdDedJikoku.isNull() )
						{
							*pCDcDrawCell = createCDcdEkijikoku( 
								idxRessyasyubetsu );
							string strText = getCdDedJikokuConv().encode( aCdDedJikoku ) ;
							pCDcDrawCell->setText(strText ) ;
						}
						//	��ԉw�̉w�������w�肳��Ă��Ȃ�
						else 
						{
							*pCDcDrawCell = createCDcdRessyabangou( 
								idxRessyasyubetsu );

							//	[�����\�r���[��̒������̕\������Z�o
							CdYColSpec aCdYColSpec( 
								CdYColSpec::ColumnType_Ekijikoku_Chaku , 
								iEkiOrder ) ;
							int iYColumnNumberChaku = 
								m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;

							//	�����\�r���[��ɒ������̕\������ AND 
							//	�I���w�̏ꍇ�� "�E�E" �\��
							if ( iYColumnNumberChaku >= 0 && 
								pCentDedRessya->getSyuuchakuEki() == iEkiOrder )
							{
								pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_UNKOUNASI_IPPAN ) ) ;
							}
							//	�n���E�r���w�̏ꍇ�E�������̂ݕ\���̏ꍇ�� " �� " �\��
							else	
							{
								pCDcDrawCell->setText( (LPCTSTR)MfcUtil::LoadCString( 
									IDS_WORD_JIKOKUHYOU_TEISYA ) ) ;
							}
						}
					}
					break ;
				}
				//  �P�D�`�w�́w�w�����`���x���w�����x
				//  �Q�D��Ԃe�́A�`�w�ł̉w�����w��ԁx���w�ʉ߁x�̂����ꂩ
				//  �R�D��Ԃe�́A�`�w�̔���������
				//  �S�D��Ԃe�́A�`�w�̎��̉w�ł̉w�����w�o�R�Ȃ��x
				//
				//	  ���̏ꍇ�́A�����\�r���[��ł́A��Ԃe�̂`�w�ł̔������� 
				//	" || " �\���Ƃ��܂�
				{
					CentDedEkiJikoku aCentDedEkijikokuNext ;
					if ( 0 <= iEkiOrder + 1 
						&& iEkiOrder + 1 < muCdDedEki->size() ) 
					{
						aCentDedEkijikokuNext = 
							pCentDedRessya->getCentDedEkiJikoku( 
								iEkiOrder + 1 ) ;
					}
					//aCentDedEkijikokuNext = ���̉w�̉w����

					if ( aCdDedEki.isHatsuChakuHyouji() && 
						( aCentDedEkiJikoku.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Teisya || 
							aCentDedEkiJikoku.getEkiatsukai() == 
								CentDedEkiJikoku::Ekiatsukai_Tsuuka ) && 
						aCentDedEkiJikoku.getHatsujikoku().isNull() && 
						aCentDedEkijikokuNext.getEkiatsukai() == 
							CentDedEkiJikoku::Ekiatsukai_Keiyunasi )
					{
						pCDcDrawCell->setText( (LPCSTR)MfcUtil::LoadCString( 
							IDS_WORD_JIKOKUHYOU_KEIYUNASI ) );	//"||"
					}

				}
			}
		}
	}
}	
void CCellBuilder::update02_02_02_08_setRessya_Bikou( 
		int iXColumnNumber , 
		const CentDedRessya* pCentDedRessya ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid* pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	const CentDedRosen* pCentDedRosen = 
		m_pCDedRosenFileData->getCentDedRosen() ;
	// --------------------------------
	CDcdTargetGetDC	aCDcdTarget( NULL ) ;
	// --------------------------------
	CdYColSpec aCdYColSpec( 
		CdYColSpec::ColumnType_Bikou ) ;
	int iYColumnNumber = 
		m_CdYColSpecCont.ColumnNumberFromSpec( aCdYColSpec , false ) ;
	CDcdGridCell* pCDcdGridCell = pCDcdGrid->getCell( 
		iXColumnNumber , iYColumnNumber ) ;
	// --------------------------------
	if ( pCDcdGridCell != 0 )
	{
		typedef CDcdTextboxV3 CDcDrawCell ;
		Ou<CDcDrawCell> pCDcDrawCell ;
		// --------------------------------
		//�@(2.2.*.1)�@�Z��(ColumnType_Ressya,ColumnType_Ressyabangou) ��
		//	�����Z����ݒ�
		pCDcdGridCell->setAttachCellCount( 1 , 1 ) ;

		//�@(2.2.*.2)�@�Z�� ��	DcDraw�I�u�W�F�N�g�̌^��ݒ�
		//	( CDcdTextbox �Ƃ���)�B
		{
			pCDcDrawCell = dynamic_castOu<CDcDrawCell>( 
				pCDcdGridCell->getIfDcDraw() ) ;
			if ( pCDcDrawCell == NULL )
			{
				pCDcDrawCell = OuNew<CDcDrawCell>( new CDcDrawCell ) ;
				pCDcdGridCell->setIfDcDraw( pCDcDrawCell ) ;
			}
		}
		//�@(2.2.*.3)�@�Z���� DcDraw�I�u�W�F�N�g�ɁA������ݒ�B
		{
			int idxRessyasyubetsu 
				= pCentDedRessya->getRessyasyubetsuIndex() ;
			string strText = pCentDedRessya->getBikou() ;
			*pCDcDrawCell = createCDcdRessyamei( 
				idxRessyasyubetsu );
			pCDcDrawCell->setLinesExtentX ( getBikouTextExtent().getX() ) ;
			pCDcDrawCell->setLinesExtentY ( getBikouTextExtent().getY() ) ;
			pCDcDrawCell->setText( strText );
		}
	}
}

	// ********************************
	//	�R���X�g���N�^
	// ********************************
CCellBuilder::CCellBuilder( 
		const CDedRosenFileData* pCDedRosenFileData ,
		const CentDedRessyaCont* pCentDedRessyaCont,
		bool bDisplayTsuukaEkiJikoku ,
		bool bDisplayAllJikoku ) :
		m_pCentDedRessyaCont( pCentDedRessyaCont ) ,
		m_pCDedRosenFileData( pCDedRosenFileData ) , 
		m_CdXColSpecCont( pCentDedRessyaCont ) ,
		m_CdYColSpecCont( 
			pCDedRosenFileData->getCentDedRosen()->getCentDedEkiCont() ,
			pCentDedRessyaCont->getRessyahoukou() , bDisplayAllJikoku ) ,
		m_bDisplayTsuukaEkiJikoku( bDisplayTsuukaEkiJikoku ) 
{
}

	// ********************************
	//@name	CCellBuilder-����
	// ********************************
void CCellBuilder::update( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{

	//�@(1)�@�O���b�h�̂����A��ԏ��ȊO�̂��ׂĂ̕�����ݒ肵�܂��B
	update01_updateWithoutRessya(
		pCWndJikokuhyou ) ;

	//�@(2)�@��ԏ���ݒ肵�܂��B
	updateAllRessya( 
		pCWndJikokuhyou ) ;
	
	// --------------------------------
	pCWndJikokuhyou->InvalidateGrid() ;
}

void CCellBuilder::updateAllRessya( 
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	//�@(2.1)�@X��̐���ݒ肵�܂��BCdXColSpecCont 
	//	�Ŏw�肳�ꂽ�񐔂Ƃ��܂��B
	CDcdGrid*	pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;
	pCDcdGrid->setXColumnCount( m_CdXColSpecCont.size() ) ;

	//�@(2.2)�@X��(ColumnType_Ressya )�ɁA��ԏ���ݒ�
	for ( int iRessyaIndex = 0 ; iRessyaIndex < m_pCentDedRessyaCont->size() ; 
		iRessyaIndex ++ )
	{
		int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec(
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iRessyaIndex ) ) ;
		if ( iXColumnNumber >= 0 )
		{
			update02_02_updateRessya( 
				iXColumnNumber , 
				m_pCentDedRessyaCont->getMuPtr()->get( iRessyaIndex ) ,
				pCWndJikokuhyou ) ;
		}
	}

	//�@(2.3)�@X��(ColumnType_NewRessya )�ɁA��ԏ���ݒ�B
	//	X��(ColumnType_Ressya )�Ɠ��l�B
	{
		int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec(
			CdXColSpec( 
				CdXColSpec::ColumnType_NewRessya  ) ) ;
		if ( iXColumnNumber >= 0 )
		{
			CentDedRessya aRessya( m_pCentDedRessyaCont->createNullRessya() ) ;

			update02_02_updateRessya( 
				iXColumnNumber , 
				&aRessya ,
				pCWndJikokuhyou ) ;
		}
	}
}


void CCellBuilder::replaceRessya( 
		int iDstRessyaIndex , 
		int iDstDelCount , 
		int iInsertCount ,
		CWndJikokuhyou* pCWndJikokuhyou ) 
{
	CDcdGrid*	pCDcdGrid = pCWndJikokuhyou->getCXDcdGrid() ;

	// --------------------------------
	//	�������̗v�f�̍폜
	// --------------------------------
	int iGensyouSize = iDstDelCount - iInsertCount ;
	if ( iGensyouSize > 0 )
	{
		int iXColumnNumberToDelete = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iDstRessyaIndex ) ) ;
		if ( iXColumnNumberToDelete == -1 )
		{
			iXColumnNumberToDelete = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_NewRessya ) ) ;
		}
		for ( int cnt = 0 ; cnt < iGensyouSize ; cnt ++ )
		{
			pCWndJikokuhyou->getCXDcdGrid()->eraseXColumn( 
				iXColumnNumberToDelete ) ;
		}
	}
	// --------------------------------
	//	�������̗v�f�̒ǉ�
	// --------------------------------
	int iZoukaSize = iInsertCount - iDstDelCount ;
	if ( iZoukaSize > 0 )
	{
		int iXColumnNumberToInsert = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iDstRessyaIndex + iDstDelCount ) ) ;
		for ( int cnt = 0 ; cnt < iZoukaSize ; cnt ++ ){
			pCWndJikokuhyou->getCXDcdGrid()->insertXColumn( 
				iXColumnNumberToInsert , 
				true ) ; 
		}
	}
	// --------------------------------
	//	�v�f�̍X�V
	// --------------------------------
	{					
		for ( int cnt = 0 ; cnt < iInsertCount ; cnt ++ )
		{
			int iXColumnNumber = m_CdXColSpecCont.ColumnNumberFromSpec( 
				CdXColSpec( 
					CdXColSpec::ColumnType_Ressya ,
					iDstRessyaIndex + cnt ) ) ;

			update02_02_updateRessya( 
				iXColumnNumber , 
				m_pCentDedRessyaCont->getMuPtr()->get( iDstRessyaIndex + cnt ) ,
				pCWndJikokuhyou ) ;
		}
	}
	// --------------------------------
	//	�O���b�h�̍X�V
	// --------------------------------
	CdDcdZone	zoneX ;
	if ( iInsertCount > 0 )
	{
		int iXColumnNumber1 = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iDstRessyaIndex ) ) ;
		int iXColumnNumber2 = m_CdXColSpecCont.ColumnNumberFromSpec( 
			CdXColSpec( 
				CdXColSpec::ColumnType_Ressya ,
				iDstRessyaIndex + iInsertCount - 1 ) )  ;
		CdDcdZone	zoneX1 = pCWndJikokuhyou->getXColumnZone( iXColumnNumber1 ) ;
		CdDcdZone	zoneX2 = pCWndJikokuhyou->getXColumnZone( iXColumnNumber2 ) ;
		zoneX.setBeginEndPos( zoneX1.getPos() , zoneX2.getEndPos() ) ; 

	}
	CdDcdZone	zoneY ;
	{
		CdDcdZone	zoneY1 = pCWndJikokuhyou->getYColumnBorderZone( 0 ) ;
		CdDcdZone	zoneY2 = pCWndJikokuhyou->getYColumnBorderZone( pCDcdGrid->getYColumnCount() - 1 ) ;
		zoneY.setBeginEndPos( zoneY1.getPos() , zoneY2.getEndPos() ) ;
		//zoneRessya = �O���b�h��̗�Ԃ̗̈�
	}
	CdDcdZoneXy	zonexyInvalidate( zoneX , zoneY ) ;
	// --------------------------------
	pCWndJikokuhyou->InvalidateRect( 
		&CConverter_WinGdi().RECTOf( zonexyInvalidate ) , TRUE ) ;
}


} //namespace ViewJikokuhyou
} //namespace WndJikokuhyou

