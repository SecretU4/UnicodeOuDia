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
//	CWndDcdGridRessyasyubetsu.cpp
//	$Id: CWndDcdGridRessyasyubetsu.cpp 402 2016-11-26 09:45:48Z okm $
// ****************************************************************
*/
/** @file */
#include "stdafx.h"

#include "logmsg\LogMsg.h"
#include "NsOu\OuNew.h"
#include "NsOu\dynamic_castOu.h"
#include "str\strtoint.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CConverter_WinGdi.h"

#include "..\resource.h"
#include "..\entDed\CentDedRosen.h"
#include "..\DiagramEdit.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "CDlgRessyasyubetsuProp.h"

// ****************************************************************
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
// ****************************************************************

namespace ViewRessyasyubetsu{ 
using namespace std ;

// --------------------------------
///@name	X��ԍ�
// --------------------------------
///@{
/**
X��ԍ��F��Ԏ�ʔԍ�
*/
const int XCOLUMNNNO_RESSYASYUBETSUNO = 0 ;
/**
X��ԍ��F��Ԏ�ʖ�
*/
const int XCOLUMNNNO_RESSYASYUBETSU = 1 ;
/**
X��ԍ��F��Ԏ�ʗ���
*/
const int XCOLUMNNNO_RYAKUSYOU = 2 ;
/**
X��ԍ��F����
*/
const int XCOLUMNNNO_LINESTYLE = 3 ;
/**
X��ԍ��FX��
*/
const int XCOLUMNNCOUNT = 4 ;
///@}


// --------------------------------
///@name	Y��ԍ�
// --------------------------------
///@{
/**
Y��ԍ��F�w�b�_��
*/
const int YCOLUMNNNO_HEADER = 0 ;
/**
Y��ԍ��F��Ԏ�ʂ�0�Ԗ�
*/
const int YCOLUMNNNO_RESSYASYUBETSU_0 = 1 ;
/**
Y��ԍ��F��Ԏ�ʂ̌�̗�
*/
const int YCOLUMNNCOUNT_BLANK = 1 ;
///@}

/**
@return
	��Ԏ�ʃr���[�̃t�H���g�̑�����Ԃ��܂��B
*/
static CdFontProp createFontProp()
{
	return ( CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
}

	// --------------------------------
	//@name	�����֐�
	// --------------------------------
CdRessyasyubetsuXColSpecCont 
CWndDcdGridRessyasyubetsu::createXColSpecCont()
{
	CdRessyasyubetsuXColSpecCont aSpecCont( 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont() ) ;
	return aSpecCont ;
}

CdRessyasyubetsuYColSpecCont 
CWndDcdGridRessyasyubetsu::createYColSpecCont()
{
	CdRessyasyubetsuYColSpecCont aSpecCont( 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont() ) ;
	return aSpecCont ;
}

CdRessyasyubetsuXColSpec 
CWndDcdGridRessyasyubetsu::getXColSpecOfFocus()
{
	CdRessyasyubetsuXColSpec aSpec ;
	CdDcdPosXy aPos = getCFocus()->getFocusCellColumnNumber() ;
	if ( aPos != getCFocus()->ColumnNumberPosXy_NULL() )
	{
		CdRessyasyubetsuXColSpecCont aSpecCont( 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont() ) ;
		aSpec = aSpecCont.ColumnNumberToSpec( aPos.getX() ) ;
	}
	return aSpec ;
}

CdRessyasyubetsuYColSpec 
CWndDcdGridRessyasyubetsu::getYColSpecOfFocus() 
{
	CdRessyasyubetsuYColSpec aSpec ;
	CdDcdPosXy aPos = getCFocus()->getFocusCellColumnNumber() ;
	if ( aPos != getCFocus()->ColumnNumberPosXy_NULL() )
	{
		CdRessyasyubetsuYColSpecCont aSpecCont( 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedRessyasyubetsuCont() ) ;
		aSpec = aSpecCont.ColumnNumberToSpec( aPos.getY() ) ;
	}
	return aSpec ;
}
	
bool CWndDcdGridRessyasyubetsu::createCmd( 
	ECreateCmd eCreateCmd , 
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu>* ppCmd )
{
	bool bRv = false ;
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu> pCmd ;

	CdRessyasyubetsuYColSpecCont aCdYColSpecCont = createYColSpecCont() ;
	CdRessyasyubetsuYColSpec  aCdYColSpecOfFocus = getYColSpecOfFocus() ;

	// ********************************
	//	ECreateCmd_NewItem 
	//�@�r���[�̃t�H�[�J�X�ʒu�ɐV�K�A�C�e����}�����邽�߂̃R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_NewItem )
	{
		//�r���[��ŕ����I����OFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{


			//	�V�K�A�C�e���́A�����I�u�W�F�N�g
			CentDedRessyasyubetsu aNewRessyasyubetsu ;

			//�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 
			//- m_iIndexDst = �t�H�[�J�X�Z���̃A�C�e��Index�Am_iIndexSize = 0
			//- m_CentDedEkiCont = �V�K�쐬���̃A�C�e���̊���l
			//- CaMuiSelect = ���Y�A�C�e����I���B
			if ( aCdYColSpecOfFocus.getColumnType() 
				== CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<CRfEditCmd_Ressyasyubetsu>( 
						new CRfEditCmd_Ressyasyubetsu( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getRessyasyubetsuIndex() ,
							0 ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewRessyasyubetsu , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			 //�@�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ:
			 //- m_iIndexDst = �����A�C�e��Index+1�Am_iIndexSize = 0
			 //- m_CentDedEkiCont = �V�K�쐬���̃A�C�e���̊���l
			 //- CaMuiSelect = ���Y�A�C�e����I���B
			if ( aCdYColSpecOfFocus.getColumnType() 
				== CdRessyasyubetsuYColSpec::ColumnType_NewRessyasyubetsu )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<CRfEditCmd_Ressyasyubetsu>( 
						new CRfEditCmd_Ressyasyubetsu( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getRessyasyubetsuIndex() ,
							0 ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewRessyasyubetsu , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}
		}
		 //�@�r���[��ŕ����I��ON:
		 //- �����I��OFF�̏ꍇ�Ɠ�������
	}
	// ********************************
	//	ECreateCmd_Focus
	//�@�t�H�[�J�X�Z����̃A�C�e��1��ΏۂƂ����R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_Focus )
	{
		//�r���[��ŕ����I����OFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{

			//	�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 
			//
			//- m_iIndexDst = �t�H�[�J�X�Z���̃A�C�e��Index�Am_iIndexSize = 1
			//- m_CentDedRessyaCont = �t�H�[�J�X�Z����̃A�C�e��1�̃R�s�[
			//- m_CaMuiSelect = �t�H�[�J�X�Z����̃A�C�e����I���B
			if ( aCdYColSpecOfFocus.getColumnType() 
				== CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<CRfEditCmd_Ressyasyubetsu>( 
						new CRfEditCmd_Ressyasyubetsu( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getRessyasyubetsuIndex() ,
							1 ) ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			//	�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ: 
			//- NULL��Ԃ��܂��B
		}
		//	�r���[��ŕ����I��ON
		//- �����I��OFF�̏ꍇ�Ɠ�������

	}
	// ********************************
	//	ECreateCmd_Select
	//�@�����̒P���܂��͕����I������Ă���A�C�e����ΏۂƂ���
	//	�R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select )
	{
		//	�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 
		//- m_iIndexDst = �t�H�[�J�X�Z���̃A�C�e��Index�Am_iIndexSize = 1
		//- m_CentDedRessyaCont = �t�H�[�J�X�Z���̂���A�C�e��1�̃R�s�[
		//- CaMuiSelect = ���Y��Ԃ�I���B
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& aCdYColSpecOfFocus.getColumnType() 
				== CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<CRfEditCmd_Ressyasyubetsu>( 
					new CRfEditCmd_Ressyasyubetsu( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						aCdYColSpecOfFocus.getRessyasyubetsuIndex() ,
						1 ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		//	�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ: 
		//- NULL��Ԃ��܂��B

		//	�r���[��ŕ����I��ON
		//
		//- m_iIndexDst = �I������Ă���A�C�e���̐擪index
		//- m_iIndexSize = �I������Ă���A�C�e���̖���index-�擪index+1
		//- m_CentDedRessyaCont = �I������Ă���A�C�e���̐擪index����
		//	����index�܂ł̃A�C�e���̃R�s�[
		//- CaMuiSelect �́A�Z���I���ɍ��킹�ăA�C�e����I���B
		//
		//(A)�̈ʒu�ŏ������܂��B
	}




	// ********************************
	//		ECreateCmd_All ,
	//�@�S��Ԃ�ΏۂƂ����R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_All )
	{
		// �r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 
		//- m_iIndexDst = 0�Am_iIndexSize = �A�C�e���̐�
		//- m_CentDedRessyaCont = �S�A�C�e���̃R�s�[
		//- m_CaMuiSelect �́A�S�A�C�e����I���B
		//
		// �r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ: 
		//- m_iIndexDst = 0�Am_iIndexSize = �A�C�e���̐�
		//- m_CentDedRessyaCont = �S�A�C�e���̃R�s�[
		//- CaMuiSelect �́A�S�A�C�e����I���B
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& ( aCdYColSpecOfFocus.getColumnType() == CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu 
			|| aCdYColSpecOfFocus.getColumnType() == CdRessyasyubetsuYColSpec::ColumnType_NewRessyasyubetsu ) )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu>( 
					new CRfEditCmd_Ressyasyubetsu( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						0 , 
						aCdYColSpecCont.getRessyasyubetsuCount() ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		// �r���[��ŕ����I��ON
		//
		//- m_iIndexDst = �I������Ă���A�C�e���̐擪index
		//- m_iIndexSize = �I������Ă���A�C�e���̖���index-�擪index+1
		//- m_CentDedRessyaCont = �I������Ă���A�C�e���̐擪index����
		//����index�܂ł̃A�C�e���̃R�s�[
		//- m_CaMuiSelect �́A�Z���̑I���ɍ��킹�ăA�C�e����I���B
		//
		//(A)�̈ʒu�ŏ������܂��B
	}

	// ********************************
	//	(A)ECreateCmd_Select�EECreateCmd_All ��
	//�@�����I������Ă����Ԃ�ΏۂƂ���
	//	�R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select 
		|| eCreateCmd == ECreateCmd_All )
	{
		if ( getCSelect()->getSelectedCellCount() > 0 )
		{
			//	�I������Ă���A�C�e����Index���擾
			deque<int> contiSelectedItemIndex ;
			for ( int iColumnNumber = 0 ; iColumnNumber < getCXDcdGrid()->getYColumnCount() ;iColumnNumber ++ )
			{
				if ( getCSelect()->getYColumnNumberSelected( iColumnNumber ) )
				{
					CdRessyasyubetsuYColSpec aCdYColSpec = aCdYColSpecCont.ColumnNumberToSpec( iColumnNumber ) ;
					if ( aCdYColSpec.getColumnType() == CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu )
					{
						contiSelectedItemIndex.push_back( aCdYColSpec.getRessyasyubetsuIndex() ) ;
					}
				}
			}
			//contiSelectedItemIndex = ��̕����I�������{����Ă���ꍇ�́A
			//	�I������Ă����Ԏ��Index���i�[����܂��B
			//	�����łȂ��ꍇ�́A��ł��B

			if ( contiSelectedItemIndex.size() > 1 )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					//	�R�}���h�I�u�W�F�N�g���ɁA�I������Ă���w�̐擪���疖���܂ł�
					//	�w���i�[���܂�(�擪�E�����ȊO�ɂ́A�I������Ă��Ȃ��w��
					//	�܂܂�Ă���ꍇ������܂�)
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu>( 
						new CRfEditCmd_Ressyasyubetsu( 
							*getCDiagramEditDoc()->getCDedRosenFileData() ,
							contiSelectedItemIndex.front() , 
							contiSelectedItemIndex.back() - contiSelectedItemIndex.front() + 1 ) ) ;

					//	�R�}���h�I�u�W�F�N�g��
					//	m_CentDedRessyaContSrc  ���̗�Ԃ�I�����܂��B
					pCmd->getCaMuiSelect()->setSelectAll( false ) ;
					for ( int i = 0 ; i < (int)contiSelectedItemIndex.size() ; i ++ )
					{
						pCmd->getCaMuiSelect()->setSelect( 
							contiSelectedItemIndex[i] - contiSelectedItemIndex.front()  , 
							true ) ;
					}
				}
			}
		}
	}
	// ================================
	if ( ppCmd != NULL && pCmd != NULL )
	{
		*ppCmd = pCmd ;
	}
	return bRv ;
}


	// --------------------------------
	//@name OnUpdate �̉����֐�
	// --------------------------------
void CWndDcdGridRessyasyubetsu::OnUpdate_setCentDedRessyasyubetsu_To_Column( 
	int iYColumnNumber , 
	const CentDedRessyasyubetsu& aCentDedRessyasyubetsu ) 
{
	bool bIsNull = aCentDedRessyasyubetsu.isNull() ;

	CdFontProp fontpropDefault = createFontProp() ;

	// --------------------------------
	//	�s��Y�����T�C�Y��ݒ�
	// --------------------------------
	{
		CDcdTargetGetDC	aCDcdTarget( NULL ) ;

		CdDcdSizeXy	sizeRessyasyubetsumei ;
		CDcdTextbox	aCDcdTextbox( "���s���s���s" ,
			fontpropDefault , 
			"" , 1 , 2 , 2 ) ;
		aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsumei ) ;

		getCXDcdGrid()->getYColumn( iYColumnNumber )->setColumnSize( sizeRessyasyubetsumei.getY() ) ;
	}

	
	// --------------------------------
	//	���X�^�C���Z���� 
	//	CDcdFreeLine_StyleSample �I�u�W�F�N�g��ݒ�
	// --------------------------------
	{
		CDcdGridCell* pCDcdGridCell = 	getCXDcdGrid()->getCell( XCOLUMNNNO_LINESTYLE , iYColumnNumber ) ;
		Ou<CDcdFreeLine_StyleSample>	pCDedLineCentral = 
			dynamic_castOu<CDcdFreeLine_StyleSample>( 
			 pCDcdGridCell->getIfDcDraw() );
		if ( pCDedLineCentral == NULL )
		{
			OuNew<CDcdFreeLine_StyleSample>	pCDedLineCentral = 
				new CDcdFreeLine_StyleSample( CdDcdFreeLineProp( 
					0  ,
					CdColorProp( 0 ,0 , 0) ) ) ;
			pCDcdGridCell->setIfDcDraw( pCDedLineCentral ) ;
		}
	}
	// --------------------------------
	//	������ݒ�
	// --------------------------------
	{
		//	��ʖ�
		Ou<CDcdTextbox> pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RESSYASYUBETSU , iYColumnNumber )->getIfDcDraw() ;
		pCDcdTextbox->
			setText( aCentDedRessyasyubetsu.getSyubetsumei() )  ;	

		//	�t�H���g����
		CdDrawTextProp	aCdDrawTextProp = 
				pCDcdTextbox->getCdDrawTextProp() ;
		aCdDrawTextProp.setCdFontProp( fontpropDefault ) ;
		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp )  ;	
		
		//	�Z���𖳌���
		InvalidateCell( XCOLUMNNNO_RESSYASYUBETSU , iYColumnNumber ) ;
	}
	{
		//	����
		Ou<CDcdTextbox> pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RYAKUSYOU , iYColumnNumber )->getIfDcDraw() ;
		
		//���̂̃e�L�X�g
		pCDcdTextbox->setText( 
			aCentDedRessyasyubetsu.getRyakusyou() )  ;	
		
		//���̂̃t�H���g����
		CdDrawTextProp	aCdDrawTextProp = 
				pCDcdTextbox->getCdDrawTextProp() ;
		{
			aCdDrawTextProp.setTextColor( 
				aCentDedRessyasyubetsu.getJikokuhyouMojiColor() ) ;

			int idxFont = aCentDedRessyasyubetsu.getJikokuhyouFontIndex() ;
			aCdDrawTextProp.setCdFontProp( 
				getCDiagramEditDoc()->getCDedRosenFileData()
					->getCdDedDispProp().getJikokuhyouFont( idxFont ) ) ;
		}
		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp )  ;	

		//	�Z���𖳌���
		InvalidateCell( XCOLUMNNNO_RYAKUSYOU , iYColumnNumber ) ;
	}
	{
		//	���X�^�C��
		CdDcdFreeLineProp	aCdLineProp( 0 ) ;
		if ( !bIsNull ){
			CconvCentDed aCconvCentDed ;
			aCconvCentDed.CentDedRessyasyubetsu_to_CDcdFreeLineProp( 
				aCentDedRessyasyubetsu.getCdDiagramLineStyle() ,
				&aCdLineProp ) ;
		}
		Ou<CDcdFreeLine_StyleSample>	pCDcdFreeLine_StyleSample = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_LINESTYLE , iYColumnNumber )->getIfDcDraw() ;
		pCDcdFreeLine_StyleSample->setCdLineProp( aCdLineProp ) ;

		//	�Z���𖳌���
		InvalidateCell( XCOLUMNNNO_LINESTYLE , iYColumnNumber ) ;
	}
}


void CWndDcdGridRessyasyubetsu::OnUpdate_setRessyasyubetsuNoXColumn() 
{
	const CentDedRosen*	pCentDedRosen = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu = 
		pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;


	for ( int iYColumnNumber = 0 ; iYColumnNumber < getCXDcdGrid()->getYColumnCount() ; iYColumnNumber ++ )
	{
		Ou<CDcdTextbox> pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RESSYASYUBETSUNO , iYColumnNumber )->getIfDcDraw() ;

		string aStr ;
		if ( YCOLUMNNNO_RESSYASYUBETSU_0 <= iYColumnNumber &&
			iYColumnNumber < YCOLUMNNNO_RESSYASYUBETSU_0 + 10 && 
			iYColumnNumber < YCOLUMNNNO_RESSYASYUBETSU_0 + pMuCentDedRessyasyubetsu->size() )
		{
			aStr = stringOf( iYColumnNumber - YCOLUMNNNO_RESSYASYUBETSU_0 ) ;
		}
		pCDcdTextbox->setText( aStr )  ;	
		
		//	�Z�����X�V
		InvalidateCell( XCOLUMNNNO_RESSYASYUBETSUNO , iYColumnNumber ) ;
	}
}



void  CWndDcdGridRessyasyubetsu::OnUpdate_All() 
{
	CWaitCursor	aCWaitCursor ;	

	CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
	const CentDedRosen*	pCentDedRosen = 
		pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet 
		= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;
	{
		//	�R�}���h�I�u�W�F�N�g���s�ɂ��Z���ړ��ŃZ���I���ɂȂ�Ȃ��悤�ɁA
		//	�Z���I�����������A�Z���I���@�\���ꎞ�I�ɒ��~���܂��B
		clearSelect() ;
		CPropStack aPropStack( this ) ;
		aPropStack
			.CBoxSelect_setIsEnable( false )
			.CRandomSelect_setIsEnable( false )  ;

		// --------------------------------		
		//	�S�v�f���X�V
		// --------------------------------
		//	Y�񐔂𑝌�������
		getCXDcdGrid()->setYColumnCount( 
			pCentDedRessyasyubetsuContGet->size() + YCOLUMNNNO_RESSYASYUBETSU_0 + YCOLUMNNCOUNT_BLANK ) ;

		//	�e�Z���ɁA�f�[�^��ݒ�
		int idxRessyasyubetsu ;
		for ( idxRessyasyubetsu = 0 ; 
				idxRessyasyubetsu < 
					pCentDedRessyasyubetsuContGet->size() ; 
				idxRessyasyubetsu ++ )
		{
			const CentDedRessyasyubetsu*	pCentDedRessyasyubetsu = 
				pCentDedRessyasyubetsuContGet->get( idxRessyasyubetsu ) ;

			OnUpdate_setCentDedRessyasyubetsu_To_Column( 
				idxRessyasyubetsu + YCOLUMNNNO_RESSYASYUBETSU_0 , *pCentDedRessyasyubetsu ) ;
		} 
		OnUpdate_setCentDedRessyasyubetsu_To_Column( 
			idxRessyasyubetsu + YCOLUMNNNO_RESSYASYUBETSU_0 , CentDedRessyasyubetsu() ) ;

		// --------------------------------
		//	��Ԏ�ʔԍ����X�V
		// --------------------------------
		OnUpdate_setRessyasyubetsuNoXColumn() ;
	}
	m_bUpdate_All_Requested = false ;
}

	// --------------------------------
	//@name ���j���[�R�}���h�̉����֐�
	// --------------------------------
	//	[�ҏW]-[�؂���]
int CWndDcdGridRessyasyubetsu::OnEditCut_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMessage ;

	const CentDedRosen*	pCentDedRosen = 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu 
		= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;

	Ou<CRfEditCmd_Ressyasyubetsu> pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}


	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	�Z���̈ʒu������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		//	���݁A��Ԏ�ʂ�1�ł���΁A���̃��j���[�R�}���h�͖����Ƃ��܂��B
		if ( pMuCentDedRessyasyubetsu->size() <= 1 )
		{
			iRv = -2;	//	��Ԏ�ʂ�1�ł���΁A���̃��j���[�R�}���h�͖���
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************

		//	�폜���悤�Ƃ��Ă����Ԏ�ʂ̗�Ԃ�
		//	���݂���Ȃ�G���[�Ƃ��܂��B
		int iRessyasyubetsuIndex = -1 ;
		int iDiaIndex = -1 ;
		ERessyahoukou	eRessyahoukou = Ressyahoukou_Kudari ;
		if ( iRv >= 0 )
		{
			int idx ;
			for ( idx = 0 ; iRv >= 0 && idx < pCmd->getCaMuiSelect()->size() ;
				idx ++ )
			{
				iRessyasyubetsuIndex = pCmd->getIndexDst() + idx ;

				if ( pCentDedRosen->getCentDedDiaCont()
					->isExistRessyaOfRessyasyubetsu(
						iRessyasyubetsuIndex , &iDiaIndex , &eRessyahoukou , NULL )
					 != 0 )
				{
					iRv = -3 ;	//�폜���悤�Ƃ��Ă����Ԏ�ʂ̗�Ԃ����݂��܂�
				}
			}
		}
		//iRessyasyubetsuIndex = 
		//	iRv=-3�̏ꍇ�́A�폜���悤�Ƃ��Ă����Ԏ�ʂ�index
		//iDiaIndex = 
		//	iRv=-3�̏ꍇ�́A�폜���悤�Ƃ��Ă����Ԏ�ʂ����݂���_�C����index
		//eRessyahoukou = 
		//	iRv=-3�̏ꍇ�́A�폜���悤�Ƃ��Ă����Ԏ�ʂ����݂���_�C����index
		
		if ( iRv >= 0 )
		{
			// -------------------------------- 
			//	�N���b�v�{�[�h�ɓ]��
			// --------------------------------
			getCDiagramEditDoc()->CentDedRessyasyubetsu_To_Cliboard( 
				pCmd->getCaMuiSelect() ) ;
			// --------------------------------
			//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
			// --------------------------------
			{
				pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;
			}
			// --------------------------------
			//	�R�}���h�I�u�W�F�N�g�����s
			// --------------------------------
			{
				getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			}
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		if ( iRv < 0 )
		{
			//	�G���[���b�Z�[�W���\��
			if ( iRv == -3 )
			{
				CString	strRessyasyubetsuName = 
					pMuCentDedRessyasyubetsu->get( iRessyasyubetsuIndex )
					->getSyubetsumei().c_str()  ;
				CString	strDiaName = 
					pCentDedRosen->getCentDedDiaCont()->getMuPtr()->
					get( iDiaIndex )->getName().c_str() ;
				CString	strRessyahoukou ;
				if ( eRessyahoukou == Ressyahoukou_Kudari )
				{
					strRessyahoukou.LoadString( IDS_WORD_Kudari ) ;
				}
				else
				{
					strRessyahoukou.LoadString( IDS_WORD_Nobori ) ;
				}
				CString	strMsg ;
				strMsg.Format( IDS_ERR_ExistRessyaOfRessyasyubetsu ,
					strRessyasyubetsuName , strDiaName , strRessyahoukou ) ;
				strErrorMessage = strMsg ;
			}

			if ( strErrorMessage.IsEmpty() )
			{
				strErrorMessage.Format( _T( "Error(%d)" ) , iRv ) ; 
			}
			MessageBox( strErrorMessage , NULL , MB_ICONSTOP | MB_OK ) ; 
		}
		// ****************************************************************
	}
	return iRv ;	

}
	//	[�ҏW]-[�R�s�[]	
int CWndDcdGridRessyasyubetsu::OnEditCopy_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Ressyasyubetsu> pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	�Z���̈ʒu������������܂���B
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// -------------------------------- 
		//	�N���b�v�{�[�h�ɓ]��
		// --------------------------------
		getCDiagramEditDoc()->CentDedRessyasyubetsu_To_Cliboard( 
			pCmd->getCaMuiSelect() ) ;

		// -------------------------------- 
		//	�t�H�[�J�X�Z�����A�I��v�f���ōő�̗�Ԏ��Index�̎��ʂɈړ�
		// --------------------------------
		{
			//	�Z���I�����N���A���A
			//	�t�H�[�J�X�Z���̈ړ��ɂ��Z���I���𖳌������܂��B
			clearSelect() ;
			CPropStack	aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		
			//	�I��v�f���ōő�̗�Ԏ��Index �����߂�
			int iRessyasyubetsuIndexMax = -1 ;
			{
				CaMuiSelect<CentDedRessyasyubetsu>* pCaMuiSelect = pCmd->getCaMuiSelect() ;
				for ( int iIndex = pCaMuiSelect->getAdapteeMu()->size() - 1  ; 
					iRessyasyubetsuIndexMax == -1 && iIndex >= 0 ; iIndex -- )
				{
					if ( pCaMuiSelect->getSelect( iIndex ) )
					{
						iRessyasyubetsuIndexMax = iIndex + pCmd->getIndexDst() ;
					}
				}
			}
			//iRessyasyubetsuIndexMax = �I������Ă����Ԏ�ʂ̂����A�ő��Index

			//	�ړ���̃t�H�[�J�X�Z���ʒu������
			int iYColumnNmber = -1 ;
			{
				CdRessyasyubetsuYColSpecCont aCdYColSpecCont = createYColSpecCont() ;
				iYColumnNmber = aCdYColSpecCont.ColumnNumberFromSpec( 
					CdRessyasyubetsuYColSpec( CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu , iRessyasyubetsuIndexMax ) ) + 1 ;
			}
			//	�t�H�[�J�X���ړ�
			{
				CdDcdPosXy posxyFocusCellColumnNumber 
					= getCFocus()->getFocusCellColumnNumber() ;
				if ( iYColumnNmber >= 0 
					&& posxyFocusCellColumnNumber != getCFocus()->ColumnNumberPosXy_NULL() )
				{
					posxyFocusCellColumnNumber.setY( iYColumnNmber ) ;
					getCFocus()->setFocusCellColumnNumber( posxyFocusCellColumnNumber ) ;
				}
			}
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;


}
	//	[�ҏW]-[�\��t��]	
int CWndDcdGridRessyasyubetsu::OnEditPaste_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Ressyasyubetsu> pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_NewItem , ppCmd ) )
		{
			iRv = -1 ;	//	�Z���̈ʒu������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		if ( !getCDiagramEditDoc()->CentDedRessyasyubetsu_IsClipboardFormatAvailable() )
		{
			iRv = -2 ;	//	�N���b�v�{�[�h�ɉw�̃f�[�^������܂���
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// -------------------------------- 
		//	�N���b�v�{�[�h����f�[�^���擾
		// --------------------------------
		CentDedRessyasyubetsuCont	aRessyasyubetsuCont ;
		getCDiagramEditDoc()->CentDedRessyasyubetsu_From_Cliboard( &aRessyasyubetsuCont ) ;
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̉w��ҏW
		// --------------------------------
		{
			//	CWndDcdGridRessyasyubetsu::ECreateCmd_NewItem �ɂ���Đ������ꂽ
			//	�V�K�A�C�e���͍폜���܂��B
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;

			//	�R�}���h�ɃN���b�v�{�[�h����̃A�C�e����ǉ����܂��B
			CaMui<CentDedRessyasyubetsu> aCaMui( pCmd->getCaMuiSelect() ) ;
			aCaMui.insert( &aRessyasyubetsuCont , 0 , INT_MAX , 0 ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		if ( iRv < 0 )
		{
			CString strErrorMessage ;
			strErrorMessage.Format( _T( "Error=%d" ) , iRv ) ;

			MessageBox( strErrorMessage , NULL , MB_ICONSTOP | MB_OK ) ; 
		}
	}
	return iRv ;

}
	//	[�ҏW]-[����]	
int CWndDcdGridRessyasyubetsu::OnEditClear_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	CString	strErrorMessage ;

	const CentDedRosen*	pCentDedRosen = 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu 
		= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;

	Ou<CRfEditCmd_Ressyasyubetsu> pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}


	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Select , ppCmd ) )
		{
			iRv = -1 ;	//	�Z���̈ʒu������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		//	���݁A��Ԏ�ʂ�1�ł���΁A���̃��j���[�R�}���h�͖����Ƃ��܂��B
		if ( pMuCentDedRessyasyubetsu->size() <= 1 )
		{
			iRv = -2;	//	��Ԏ�ʂ�1�ł���΁A���̃��j���[�R�}���h�͖���
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************

		//	�폜���悤�Ƃ��Ă����Ԏ�ʂ̗�Ԃ�
		//	���݂���Ȃ�G���[�Ƃ��܂��B
		int iRessyasyubetsuIndex = -1 ;
		int iDiaIndex = -1 ;
		ERessyahoukou	eRessyahoukou = Ressyahoukou_Kudari ;
		if ( iRv >= 0 )
		{
			int idx ;
			for ( idx = 0 ; iRv >= 0 && idx < pCmd->getCaMuiSelect()->size() ;
				idx ++ )
			{
				iRessyasyubetsuIndex = pCmd->getIndexDst() + idx ;

				if ( pCentDedRosen->getCentDedDiaCont()
					->isExistRessyaOfRessyasyubetsu(
						iRessyasyubetsuIndex , &iDiaIndex , &eRessyahoukou , NULL )
					 != 0 )
				{
					iRv = -3 ;	//�폜���悤�Ƃ��Ă����Ԏ�ʂ̗�Ԃ����݂��܂�
				}
			}
		}
		//iRessyasyubetsuIndex = 
		//	iRv=-3�̏ꍇ�́A�폜���悤�Ƃ��Ă����Ԏ�ʂ�index
		//iDiaIndex = 
		//	iRv=-3�̏ꍇ�́A�폜���悤�Ƃ��Ă����Ԏ�ʂ����݂���_�C����index
		//eRessyahoukou = 
		//	iRv=-3�̏ꍇ�́A�폜���悤�Ƃ��Ă����Ԏ�ʂ����݂���_�C����index
		
		if ( iRv >= 0 )
		{
			// -------------------------------- 
			//	�N���b�v�{�[�h�ɓ]��
			// --------------------------------
			getCDiagramEditDoc()->CentDedRessyasyubetsu_To_Cliboard( 
				pCmd->getCaMuiSelect() ) ;
			// --------------------------------
			//	�R�}���h�I�u�W�F�N�g�̗�Ԃ�ҏW
			// --------------------------------
			{
				pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;
			}
			// --------------------------------
			//	�R�}���h�I�u�W�F�N�g�����s
			// --------------------------------
			{
				getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
			}
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		if ( iRv < 0 )
		{
			//	�G���[���b�Z�[�W���\��
			if ( iRv == -3 )
			{
				CString	strRessyasyubetsuName = 
					pMuCentDedRessyasyubetsu->get( iRessyasyubetsuIndex )
					->getSyubetsumei().c_str()  ;
				CString	strDiaName = 
					pCentDedRosen->getCentDedDiaCont()->getMuPtr()->
					get( iDiaIndex )->getName().c_str() ;
				CString	strRessyahoukou ;
				if ( eRessyahoukou == Ressyahoukou_Kudari )
				{
					strRessyahoukou.LoadString( IDS_WORD_Kudari ) ;
				}
				else
				{
					strRessyahoukou.LoadString( IDS_WORD_Nobori ) ;
				}
				CString	strMsg ;
				strMsg.Format( IDS_ERR_ExistRessyaOfRessyasyubetsu ,
					strRessyasyubetsuName , strDiaName , strRessyahoukou ) ;
				strErrorMessage = strMsg ;
			}

			if ( strErrorMessage.IsEmpty() )
			{
				strErrorMessage.Format( _T( "Error(%d)" ) , iRv ) ; 
			}
			MessageBox( strErrorMessage , NULL , MB_ICONSTOP | MB_OK ) ; 
		}
		// ****************************************************************
	}
	return iRv ;	

}
	//	[�ҏW]-[��Ԏ�ʂ�}��]	
int CWndDcdGridRessyasyubetsu::
OnEDITRessyasyubetsuInsert_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( execRessyasyubetsuPropDlg( true , TRUE ) < 0 )
	{
		iRv = -1 ;	//	�t�H�[�J�X�̈ʒu���s���ł��B
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		execRessyasyubetsuPropDlg( true , FALSE ) ;	

		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		if ( iRv < 0 )
		{
			CString strErrorMessage ;
			switch( iRv )
			{
			case -1 :	//	���݂͎��s�ł��܂���B
				break ;
			default:
				strErrorMessage.Format( _T( "Error=%d" ) , iRv ) ;
				break ;
			}
			if ( strErrorMessage.GetLength() > 0 )
			{
				MessageBox( strErrorMessage , NULL , MB_ICONSTOP | MB_OK ) ; 
			}
		}
		// ****************************************************************
	}
	return iRv ;

}
	//	[�ҏW]-[���]	*/
int CWndDcdGridRessyasyubetsu::OnRessyasyubetsuUp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	int iRessyasyubetsuIndex = -1 ;
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Focus , NULL ) )
		{
			iRv = -1 ;	//	�Z���̈ʒu������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		CdRessyasyubetsuYColSpecCont aYColSpecCont = createYColSpecCont() ;
		CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
		if ( aYColSpec.getColumnType() != aYColSpec.ColumnType_Ressyasyubetsu )
		{
			iRv = -1 ;
		}
		else
		{
			iRessyasyubetsuIndex = aYColSpec.getRessyasyubetsuIndex() ;
			if ( !( 1 <= iRessyasyubetsuIndex 
				&& iRessyasyubetsuIndex< aYColSpecCont.getRessyasyubetsuCount() ) )
			{
				iRv = -1 ;	//	�t�H�[�J�X�̈ʒu���s���ł��B(��ԏ�̗�Ԏ�ʂɂ͎g���܂���)
			}
		}
	}
	//iRessyasyubetsuIndex = �t�H�[�J�X�Z���̂���ʒu�̗�Ԏ��Index

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		{
			CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;
			if ( pCDcdGridCell != NULL ){
				CDcdGridCell*	pCDcdGridCellNew = getCXDcdGrid()->calcMovedCell( 
					pCDcdGridCell , 0 , -1 ) ;
				if ( pCDcdGridCellNew != NULL ){
					getCFocus()->setFocusCell( pCDcdGridCellNew ) ;	
				}
			}
		}
		// --------------------------------
		//	�R�}���h�𐶐��E���s
		// --------------------------------
		{
			OuNew<CRfEditCmd> pCmd( 
				new CRfEditCmd_RessyasyubetsuSwap( 
					iRessyasyubetsuIndex , 
					iRessyasyubetsuIndex - 1 ) 
			) ;
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;

}
	//	[�ҏW]-[����]	*/
int CWndDcdGridRessyasyubetsu::
OnRessyasyubetsuDown_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	int iRessyasyubetsuIndex = -1 ;
	if ( iRv >= 0 )
	{
		if ( !createCmd( ECreateCmd_Focus , NULL ) )
		{
			iRv = -1 ;	//	�Z���̈ʒu������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		CdRessyasyubetsuYColSpecCont aYColSpecCont = createYColSpecCont() ;
		CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
		if ( aYColSpec.getColumnType() != aYColSpec.ColumnType_Ressyasyubetsu )
		{
			iRv = -1 ;
		}
		else
		{
			iRessyasyubetsuIndex = aYColSpec.getRessyasyubetsuIndex() ;
			if ( !( 0 <= iRessyasyubetsuIndex 
				&& iRessyasyubetsuIndex< aYColSpecCont.getRessyasyubetsuCount() - 1 ) )
			{
				iRv = -1 ;	//	�t�H�[�J�X�̈ʒu���s���ł��B(��ԉ��̗�Ԏ�ʂɂ͎g���܂���)
			}
		}
	}
	//iRessyasyubetsuIndex = �t�H�[�J�X�Z���̂���ʒu�̗�Ԏ��Index

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		// --------------------------------
		//	�t�H�[�J�X���ړ�
		// --------------------------------
		{
			CDcdGridCell*	pCDcdGridCell = getCFocus()->getFocusCell() ;
			if ( pCDcdGridCell != NULL ){
				CDcdGridCell*	pCDcdGridCellNew = getCXDcdGrid()->calcMovedCell( 
					pCDcdGridCell , 0 , 1 ) ;
				if ( pCDcdGridCellNew != NULL ){
					getCFocus()->setFocusCell( pCDcdGridCellNew ) ;	
				}
			}
		}
		// --------------------------------
		//	�R�}���h�𐶐��E���s
		// --------------------------------
		{
			OuNew<CRfEditCmd> pCmd( 
				new CRfEditCmd_RessyasyubetsuSwap( 
					iRessyasyubetsuIndex , 
					iRessyasyubetsuIndex + 1 ) 
			) ;
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return ( iRv ) ;


}
	//	[�ҏW]-[��Ԏ�ʂ̃v���p�e�B]	*/
int CWndDcdGridRessyasyubetsu::
OnEDITRessyasyubetsuProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	//	�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���Ƃ��́A
	//	�u�V�K�A�C�e���̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}
	if ( execRessyasyubetsuPropDlg( bInsert , TRUE ) < 0 )
	{
		iRv = -1 ;	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		iRv = execRessyasyubetsuPropDlg( bInsert , FALSE ) ;

		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;

}



// ****************************************************************
//	CWndDcdGridRessyasyubetsu
// ****************************************************************


// ********************************
//	�R���X�g���N�^
// ********************************
CWndDcdGridRessyasyubetsu::CWndDcdGridRessyasyubetsu()
	: m_bUpdate_All_Requested( false ) 
{
	getCSelect()->setSelectMode( CSelect::SelectMode_YColumn ) ;
}
CWndDcdGridRessyasyubetsu::~CWndDcdGridRessyasyubetsu()
{
}

// ********************************
//@name	CDcdGrid
// ********************************

// ********************************
//@name	CWndDcdGrid
// ********************************

	// ********************************
	//@name CWndDcdGridRessyasyubetsu-����
	// ********************************

int CWndDcdGridRessyasyubetsu::
execRessyasyubetsuPropDlg( bool bInsert , BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Ressyasyubetsu>	pCmd ;
	Ou<CRfEditCmd_Ressyasyubetsu>*	ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;};

	// ****************************************************************
	//	�R�}���h�̎��s�ۂ̔���
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( bInsert )
		{
			if ( !createCmd( ECreateCmd_NewItem , ppCmd ) )
			{
				iRv = -1 ;	//	�Z���̈ʒu���s���ł��B
			}
		}
		else
		{
			if ( !createCmd( ECreateCmd_Select , ppCmd ) ) 
			{
				iRv = -1 ;
			}
		}
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		CdRessyasyubetsuXColSpec	aXColSpec = getXColSpecOfFocus() ;
		int iFocusItem = -1 ;
		switch( aXColSpec.getColumnType() )
		{
		case aXColSpec.ColumnType_Syubetsumei :	iFocusItem = 0 ;	break ;
		case aXColSpec.ColumnType_Ryakusyou :	iFocusItem = 1 ;	break ;
		case aXColSpec.ColumnType_DiagramLineStyle :	iFocusItem = 2 ;	break ;
		}
		CDlgRessyasyubetsuProp	aDlg( 
			bInsert , 
			pCmd->getCaMuiSelect()->getMuPtr() , 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCdDedDispProp() ,
			iFocusItem , 
			&m_CKeyinputSenderToModalDlg , this ) ;
		if ( aDlg.DoModal() == IDOK )
		{
			iRv = 1 ;
		}			
		// --------------------------------
		//	�_�C�A���OOK���̏���
		// --------------------------------
		if ( iRv == 1 )
		{
			// --------------------------------
			//	�ҏW�R�}���h�����s
			// --------------------------------
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
	}
	return iRv ;
		

}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
BEGIN_MESSAGE_MAP(CWndDcdGridRessyasyubetsu,CWndDcdGridRessyasyubetsu::super)
	//{{AFX_MSG_MAP(CWndDcdGridRessyasyubetsu)
	ON_WM_CREATE()
	ON_WM_KEYUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_Ressyasyubetsu_Prop, OnEDITRessyasyubetsuProp)
	ON_COMMAND(ID_Ressyasyubetsu_Insert, OnEDITRessyasyubetsuInsert)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_Ressyasyubetsu_Up, OnRessyasyubetsuUp)
	ON_UPDATE_COMMAND_UI(ID_Ressyasyubetsu_Up, OnUpdateRessyasyubetsuUp)
	ON_COMMAND(ID_Ressyasyubetsu_Down, OnRessyasyubetsuDown)
	ON_UPDATE_COMMAND_UI(ID_Ressyasyubetsu_Down, OnUpdateRessyasyubetsuDown)
	ON_UPDATE_COMMAND_UI(ID_Ressyasyubetsu_Insert, &CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuInsert)
	ON_UPDATE_COMMAND_UI(ID_Ressyasyubetsu_Prop, &CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuProp)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CWndDcdGridRessyasyubetsu::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (super::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// --------------------------------
	//	��Ԏ�ʃr���[�Ɏg�p����t�H���g
	// --------------------------------
	CdFontProp fontpropDefault = createFontProp() ;

	// --------------------------------
	//	��̐����w��
	// --------------------------------
	getCXDcdGrid()->setXColumnCount( XCOLUMNNCOUNT ) ;
	getCXDcdGrid()->setYColumnCount( YCOLUMNNNO_RESSYASYUBETSU_0 + YCOLUMNNCOUNT_BLANK ) ;
	getCXDcdGrid()->setYFixColumnCount( YCOLUMNNNO_RESSYASYUBETSU_0 ) ;

	// --------------------------------
	//	��̃T�C�Y��ݒ�
	// --------------------------------
	{
		CDcdTargetGetDC	aCDcdTarget( NULL ) ;
		// --------------------------------
		//	X��
		// --------------------------------
		{
			//	��ʔԍ�
			CdDcdSizeXy	sizeRessyasyubetsumei ;
			CDcdTextbox	aCDcdTextbox( 
				"0" ,
				fontpropDefault ,
				"" , 1 , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsumei ) ;
			getCXDcdGrid()->getXColumn( XCOLUMNNNO_RESSYASYUBETSUNO )->setColumnSize( sizeRessyasyubetsumei.getX() ) ;
		}
		{
			//	��ʖ�
			CdDcdSizeXy	sizeRessyasyubetsumei ;
			CDcdTextbox	aCDcdTextbox( 
				"���s���s���s���s���s���s" ,
				fontpropDefault ,
				"" , 1 , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsumei ) ;
			getCXDcdGrid()->getXColumn( XCOLUMNNNO_RESSYASYUBETSU )->setColumnSize( sizeRessyasyubetsumei.getX() ) ;
		}
		{
			//	����
			CdDcdSizeXy	sizeRessyasyubetsujikokukeisiki ;

			CDcdTextbox	aCDcdTextbox( 
				"���s�s" ,
				fontpropDefault ,
				"" , XCOLUMNNNO_RYAKUSYOU , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsujikokukeisiki ) ;

			getCXDcdGrid()->getXColumn( XCOLUMNNNO_RYAKUSYOU )->setColumnSize( sizeRessyasyubetsujikokukeisiki.getX() ) ;
		}
		{
			//	���X�^�C��
			CdDcdSizeXy	sizeRessyasyubetsukibo ;
			CDcdTextbox	aCDcdTextbox( 
				"���s���s���s" ,
				fontpropDefault ,
				"" , 1 , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsukibo ) ;

			getCXDcdGrid()->getXColumn( XCOLUMNNNO_LINESTYLE )->setColumnSize( sizeRessyasyubetsukibo.getX() ) ;
		}
		// --------------------------------
		//	Y��
		// --------------------------------
		{
			CdDcdSizeXy	sizeRessyasyubetsumei ;
			CDcdTextbox	aCDcdTextbox( 
				"���s���s���s���s���s���s" ,
				fontpropDefault ,
				"" , 1 , 2 , 2 ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeRessyasyubetsumei ) ;

			getCXDcdGrid()->getYColumn( YCOLUMNNNO_HEADER )->setColumnSize( sizeRessyasyubetsumei.getY() ) ;
			getCXDcdGrid()->getYColumn( YCOLUMNNNO_RESSYASYUBETSU_0 )->setColumnSize( sizeRessyasyubetsumei.getY() ) ;
		}
	}
	// --------------------------------
	//	�ŏ��ɑ����ƃe�L�X�g��ݒ�
	// --------------------------------
	{
		// ��ʔԍ�
		Ou<CDcdTextbox>	pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RESSYASYUBETSUNO , YCOLUMNNNO_HEADER )->getIfDcDraw() ;
		
		CConverter_WinGdi aCConverter_WinGdi ;
		
		CdDrawTextProp	aCdDrawTextProp( 
			fontpropDefault ,
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( 
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENU ) ) ;

		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
		pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;
	}
	{
		// ��ʖ�
		CString	aString ;
		aString.LoadString( IDS_WORD_Ressyasyubetsumei ) ;

		Ou<CDcdTextbox>	pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RESSYASYUBETSU , YCOLUMNNNO_HEADER )->getIfDcDraw() ;
		
		CConverter_WinGdi aCConverter_WinGdi ;
		
		CdDrawTextProp	aCdDrawTextProp( 
			fontpropDefault ,
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( 
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENU ) ) ;

		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
		pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;
		pCDcdTextbox->setText( (LPCTSTR)aString ) ;
	}
	{
		// ����
		CString	aString ;
		aString.LoadString( IDS_WORD_Ryakusyou ) ;

		Ou<CDcdTextbox>	pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_RYAKUSYOU , YCOLUMNNNO_HEADER )->getIfDcDraw() ;
		
		CConverter_WinGdi aCConverter_WinGdi ;


		CdDrawTextProp	aCdDrawTextProp( 
			fontpropDefault ,
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( 
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENU ) ) ;

		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
		pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;
		pCDcdTextbox->setText( (LPCTSTR)aString ) ;
	}
	{
		//	���X�^�C��
		CString	aString ;
		aString.LoadString( IDS_WORD_Senstyle ) ;

		Ou<CDcdTextbox>	pCDcdTextbox = 
			getCXDcdGrid()->getCell( XCOLUMNNNO_LINESTYLE , YCOLUMNNNO_HEADER )->getIfDcDraw() ;
		
		CConverter_WinGdi	aCConverter_WinGdi ;
		CdDrawTextProp	aCdDrawTextProp( 
			fontpropDefault ,
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( 
			aCConverter_WinGdi.CdColorPropOfSysColor( COLOR_MENU ) ) ;

		pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
		pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;
		pCDcdTextbox->setText( (LPCTSTR)aString ) ;
	}
	// --------------------------------
	//	�t�H�[�J�X�Z���̏����ʒu��ݒ�
	// --------------------------------
	getCFocus()->setFocusCell( getCXDcdGrid()->getCell( 0 , YCOLUMNNNO_RESSYASYUBETSU_0 ) ) ;	
	// --------------------------------
	//	�\���X�V
	// --------------------------------
	InvalidateGrid() ;

	
	return 0;
}

void CWndDcdGridRessyasyubetsu::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	//	�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���Ƃ��́A
	//	�u�V�K�A�C�e���̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}

	// ****************************************************************
	//	�R�}���h�̎��s
	// ****************************************************************
	//	�����L�[��������Ă��āA�_�C�A���O�{�b�N�X���J���Ă��Ȃ��ꍇ��
	//	�_�C�A���O�{�b�N�X���J���܂��B
	if ( CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown() && 
			m_CKeyinputSenderToModalDlg.startSend() >= 0 )
	{
		m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) ;
		execRessyasyubetsuPropDlg( bInsert , FALSE ) ;
		m_CKeyinputSenderToModalDlg.endSend() ;
	}
	//	���łɃ_�C�A���O���N�������_�C�A���O�{�b�N�X�Ƀ��b�Z�[�W��]��
	else	
	{
		if ( !m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) )
		{
			CWndDcdGridRessyasyubetsu::super::OnKeyDown(nChar, nRepCnt, nFlags);
		}
	}
			

}

void CWndDcdGridRessyasyubetsu::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	//	�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���Ƃ��́A
	//	�u�V�K�A�C�e���̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdRessyasyubetsuYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}
	// ****************************************************************
	//	�R�}���h�̎��s
	// ****************************************************************
	iRv = execRessyasyubetsuPropDlg( bInsert , FALSE ) ;
}

void CWndDcdGridRessyasyubetsu::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if ( !m_CKeyinputSenderToModalDlg.OnKeyUp( nChar , nRepCnt , nFlags ) )
	{
		CWndDcdGridRessyasyubetsu::super::OnKeyUp(nChar, nRepCnt, nFlags);
	}
}


void CWndDcdGridRessyasyubetsu::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC ){
		return ;
	}
	// --------------------------------
	

	CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
	const CentDedRosen*	pCentDedRosen = 
		pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedRessyasyubetsu*>* pCentDedRessyasyubetsuContGet 
		= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;

	//pHint= 
	//	pHint�� CRfEditCmdHolder �I�u�W�F�N�g�Ȃ�A
	//	�Ή�����ҏW�R�}���h CRfEditCmd ��ێ����Ă��܂��B
	//	���̏ꍇ�Athis �� CRfEditCmd �̓��e�ɍœK������
	//	�X�V���s���܂��B
	//	NULL�Ȃ�A�S�X�V���v������Ă��܂��B
	if ( m_bUpdate_All_Requested )
	{
		//	�S�X�V���ۗ�����Ă���ꍇ�́A
		//	���̌�̓R�}���h�ɂ��œK�����ꂽ�P�̂̂����Ȃ�X�V�v���ɑ΂��Ă��A�S�X�V���s���܂��B
		pHint = NULL ;
	}


	Ou<CRfEditCmd> pCmd ;
	if ( pHint != NULL && pHint->IsKindOf( RUNTIME_CLASS( CRfEditCmdHolder ) ) )
	{
		CRfEditCmdHolder* pHolder = 
			(CRfEditCmdHolder*)pHint ;
		pCmd = pHolder->getCmd() ; 
	}
	if ( pCmd != NULL )
	{
		if ( dynamic_castOu<CRfEditCmd_Comment>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Dia>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Eki>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Ressya>( pCmd )  
		)
		{
			//	���̃r���[�́A
			//		�R�����g�̕ύX
			//		�_�C���̕ύX
			//		�_�C���̑����̕ύX
			//		�w�̕ύX
			//		��Ԃ̕ύX
			//	�̏ꍇ�́A�X�V���s���܂���B
		}
		//	��Ԏ�ʂ̕ύX
		else if ( dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd ) )
		{
			Ou<CRfEditCmd_Ressyasyubetsu>	pCommand = 
				dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd );
			

			//	�R�}���h�I�u�W�F�N�g���s�ɂ��Z���ړ��ŃZ���I���ɂȂ�Ȃ��悤�ɁA
			//	�Z���I�����������A�Z���I���@�\���ꎞ�I�ɒ��~���܂��B
			clearSelect() ;
			CPropStack aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;

			// --------------------------------
			//	�������̗v�f�̍폜
			// --------------------------------
			const CentDedRessyasyubetsuCont*	pCentDedRessyasyubetsuContSrc = pCommand->getCentDedRessyasyubetsuContSrc() ;
			int iGensyouSize = pCommand->getSizeDst() - pCentDedRessyasyubetsuContSrc->size() ;
			if ( iGensyouSize > 0 ){
				for ( int cnt = 0 ; cnt < iGensyouSize ; cnt ++ ){
					getCXDcdGrid()->eraseYColumn( 
						pCommand->getIndexDst() + 
						pCommand->getSizeDst() - iGensyouSize 
						+ 1 ) ;
				}
			}
			// --------------------------------
			//	�������̗v�f�̒ǉ�
			// --------------------------------
			int iOkikaeSize = 0 ;
			iOkikaeSize = min( pCommand->getSizeDst() , pCentDedRessyasyubetsuContSrc->size() ) ;
			int iZoukaSize = pCentDedRessyasyubetsuContSrc->size() - pCommand->getSizeDst() ;
			if ( iZoukaSize > 0 ){
				for ( int cnt = 0 ; cnt < iZoukaSize ; cnt ++ ){
					getCXDcdGrid()->insertYColumn( 
						pCommand->getIndexDst() + iOkikaeSize + cnt + 1 , 
						true ) ; 
				}
			}
			// --------------------------------
			//	�v�f�̍X�V
			// --------------------------------
			{					
				for ( int cnt = 0 ; cnt < pCentDedRessyasyubetsuContSrc->size() ; cnt ++ ){
					int iRessyasyubetsuIndex = pCommand->getIndexDst() + cnt ;
					const CentDedRessyasyubetsu*	pCentDedRessyasyubetsu = pCentDedRessyasyubetsuContGet->get( iRessyasyubetsuIndex ) ;
					OnUpdate_setCentDedRessyasyubetsu_To_Column( 
						iRessyasyubetsuIndex + 1 , *pCentDedRessyasyubetsu ) ;
				}
			}
			// --------------------------------
			//	��Ԏ�ʔԍ����X�V
			// --------------------------------
			OnUpdate_setRessyasyubetsuNoXColumn() ;
		}
		//	��Ԏ�ʂ̓���
		else if ( dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd ) )
		{
			Ou<CRfEditCmd_RessyasyubetsuSwap>	pCommand = 
				dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>( pCmd );
			// --------------------------------
			//	�v�f�̍X�V
			// --------------------------------
			{					
				{
					int iRessyasyubetsuIndex = pCommand->getRessyasyubetsuIndexA() ;
					const CentDedRessyasyubetsu*	pCentDedRessyasyubetsu = 
						pCentDedRessyasyubetsuContGet->get( iRessyasyubetsuIndex ) ;
					OnUpdate_setCentDedRessyasyubetsu_To_Column( 
						iRessyasyubetsuIndex + 1 , *pCentDedRessyasyubetsu ) ;
				}
				{
					int iRessyasyubetsuIndex = pCommand->getRessyasyubetsuIndexB() ;
					const CentDedRessyasyubetsu*	pCentDedRessyasyubetsu = 
						pCentDedRessyasyubetsuContGet->get( iRessyasyubetsuIndex ) ;
					OnUpdate_setCentDedRessyasyubetsu_To_Column( 
						iRessyasyubetsuIndex + 1 , *pCentDedRessyasyubetsu ) ;
				}
			}
			// --------------------------------
			//	��Ԏ�ʔԍ����X�V
			// --------------------------------
			OnUpdate_setRessyasyubetsuNoXColumn() ;
		}
		else
		{
			//CRfEditCmd_DedRosenFileDataProp
			//	  �H���t�@�C���̃v���p�e�B�̕ύX�́A
			//	�t�H���g�̕ω��𔺂����߁A�S�X�V���K�v�ł��B
			//CRfEditCmd_Rosen
			//CRfEditCmd_RosenFileData
			//	��Ԏ�ʂ��܂���I�u�W�F�N�g�ł��B���ꂪ�X�V���ꂽ�ꍇ�́A
			//	�S�X�V���K�v�ł��B
			pHint = NULL ;
		}
	}
	if ( pHint == NULL )
	{
		// --------------------------------		
		//	�S�v�f���X�V
		// --------------------------------
		CView *pView = getCDiagramEditApp()->getCMainFrame()->
			getMDIChildActiveView() ;
		if ( GetParent() == pView )
		{
			OnUpdate_All() ;
		}
		else
		{
			LogMsg( "CWndDcdGridRessyasyubetsu::OnUpdate()" 
				"m_bUpdate_All_Requested=true" ) ;
			m_bUpdate_All_Requested = true ;
		}
	}
	
	// --------------------------------
	//	��I��͈͂�ݒ�
	// --------------------------------
	{
		CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
		const CentDedRosen*	pCentDedRosen = 
			pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedRessyasyubetsu*>* pMuCentDedRessyasyubetsu 
			= pCentDedRosen->getCentDedRessyasyubetsuCont()->getMuPtr() ;

		int iYColumnBegin = createYColSpecCont().ColumnNumberFromSpec( 
			CdRessyasyubetsuYColSpec( CdRessyasyubetsuYColSpec::ColumnType_Ressyasyubetsu , 0 ) ) ;

		getCSelect()->setColumnNumberSelectLimit(
			CdDcdZoneXy( 
				CdDcdZone( 0 , INT_MAX ) , 
				CdDcdZone( iYColumnBegin , pMuCentDedRessyasyubetsu->size()   ) 
			) );
	}

}

void CWndDcdGridRessyasyubetsu::OnEDITRessyasyubetsuProp() 
{
	OnEDITRessyasyubetsuProp_Process( FALSE ) ;
}


void CWndDcdGridRessyasyubetsu::OnEDITRessyasyubetsuInsert() 
{
	OnEDITRessyasyubetsuInsert_Process( FALSE );
}

void CWndDcdGridRessyasyubetsu::OnEditClear() 
{
	OnEditClear_Process( FALSE ) ;
	
}

void CWndDcdGridRessyasyubetsu::OnUpdateEditClear(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditClear_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnEditCut() 
{
	OnEditCut_Process( FALSE );
}

void CWndDcdGridRessyasyubetsu::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditCut_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnEditCopy() 
{
	OnEditCopy_Process( FALSE );
}

void CWndDcdGridRessyasyubetsu::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditCopy_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnEditPaste() 
{
	OnEditPaste_Process( FALSE );
}

void CWndDcdGridRessyasyubetsu::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditPaste_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnRessyasyubetsuUp() 
{
	OnRessyasyubetsuUp_Process( FALSE );

}

void CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuUp(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnRessyasyubetsuUp_Process( TRUE ) >= 0 ) ;

}

void CWndDcdGridRessyasyubetsu::OnRessyasyubetsuDown() 
{
	OnRessyasyubetsuDown_Process( FALSE ) ;
}

void CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuDown(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnRessyasyubetsuDown_Process( TRUE ) >= 0 ) ;
}
void CWndDcdGridRessyasyubetsu::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	LogMsg( "CWndDcdGridRessyasyubetsu::OnActivateView(%d,,)" , bActivate ) ;
	
	if ( bActivate && m_bUpdate_All_Requested )
	{
		OnUpdate_All() ;
	}
}

void CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuInsert(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEDITRessyasyubetsuInsert_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnUpdateRessyasyubetsuProp(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEDITRessyasyubetsuProp_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridRessyasyubetsu::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CMenu	aMenu ;
	aMenu.LoadMenu( IDR_MENU_RESSYASYUBETSUVIEW_CONTEXT ) ;
	CMenu* pContextMenu = aMenu.GetSubMenu( 0 ) ;

	//	�R���e�L�X�g���j���[���}�E�X�ȊO�ŌĂяo���ꂽ�ꍇ�́A
	//	�R���e�L�X�g���j���[�̕\���ʒu�́A�t�H�[�J�X�Z���̒����̈ʒu�Ƃ��܂��B
	if ( point.x ==-1 || point.y == -1 )
	{
		//	�R���e�L�X�g���j���[���}�E�X�ȊO�ŌĂяo����܂���
		CdDcdPosXy posxyFocusCellColumnNumber = getCFocus()->getFocusCellColumnNumber() ;
		if ( posxyFocusCellColumnNumber !=  
				CFocus::ColumnNumberPosXy_NULL() )
		{
			CdDcdZoneXy	zonexyFocusCell = getCellZone( 
				posxyFocusCellColumnNumber.getX() , 
				posxyFocusCellColumnNumber.getY() ) ;
			point.x = zonexyFocusCell.getX().getPos() + zonexyFocusCell.getX().getSize() / 2 ;
			point.y = zonexyFocusCell.getY().getPos() + zonexyFocusCell.getY().getSize() / 2 ;
			ClientToScreen( &point ) ;
		}
	}
	//point = �R���e�L�X�g���j���[�̕\���ʒu�B
	//	-1�̏ꍇ�́A�R���e�L�X�g���j���[�͕\���ł��܂���B

	if ( point.x >= 0 &&  point.y >= 0 )
	{
		pContextMenu->TrackPopupMenu( 
			TPM_LEFTALIGN | TPM_RIGHTBUTTON ,
			point.x , point.y , 
			AfxGetMainWnd() ) ;	//	this ���w�肷��ƁAApp��Doc��View ��
								//�R�}���h�`�F�[�������삵�܂���B
	}
	else
	{
		super::OnContextMenu(pWnd, point);
	}
}
} //namespace ViewRessyasyubetsu
