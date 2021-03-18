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
//	CWndDcdGridEki.cpp
//	$Id: CWndDcdGridEki.cpp 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
#include "stdafx.h"

#include "..\resource.h"

#include "DcDraw/CDcdTargetGetDC.h"
#include "logmsg/LogMsg.h"
#include "NsOu/OuNew.h"
#include "NsOu/dynamic_castOu.h"

#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcDraw\CDcdTarget.h"
#include "DcDraw\CDcDeviceUnitSizeX.h"
#include "DcDraw\CDcDeviceUnitSizeY.h"
#include "DcDraw\CDcdText.h"
#include "DcDraw\CaDcdTargetItemPosition.h"
#include "DcDraw\CDcdLine.h"
#include "DcDraw\CDcdTargetGetDC.h"
#include "DcDraw\CConverter_Wingdi.h"

#include "..\entDed\CentDedRosen.h"
#include "..\DiagramEdit.h"
#include "..\CRfEditCmdHolder.h"
#include "..\DedRosenFileData\EditCmd\EditCmd.h"
#include "CDlgEkiProp.h"
#include "CWndDcdGridEki.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/** �z�� a �̗v�f����Ԃ��܂��B */
#define arrayof(a) (sizeof(a)/sizeof(a[0]))


namespace ViewEki{
	

using namespace std ;

// ****************************************************************
//	CWndDcdGridEki
// ****************************************************************
// --------------------------------
//@name �����֐�
// --------------------------------

CDcdTextbox	CWndDcdGridEki::getCDcdEkimei()const
{
	string strExtent = getCDiagramEditDoc()->getCDedRosenFileData()->getCdDedDispProp().createEkimeiExtentString() ;
	//strExtent = �H���t�@�C���f�[�^�ɕۑ�����Ă���l�����Ƃɂ��āA
	//	�쐬�����A�����񕝂̊������ł��B

	//CdFontProp aCdFontProp( getCDiagramEditDoc()->getCDedRosenFileData()->
	//	getCdDedDispProp().getJikokuhyouFont() ) ;
	CdFontProp aCdFontProp(	CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
	return CDcdTextbox( "" ,
		aCdFontProp ,
		strExtent , 1 , 2 , 2 , CdPenProp() , 
		CConverter_WinGdi().CdBrushPropOf( WHITE_BRUSH ) ) ;
};
	
CDcdTextbox	CWndDcdGridEki::getCDcdEkijikokukeisiki()const
{
	//CdFontProp aCdFontProp( getCDiagramEditDoc()->getCDedRosenFileData()->
	//	getCdDedDispProp().getJikokuhyouFont() ) ;
	CdFontProp aCdFontProp(	CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
	return CDcdTextbox( "" ,
		aCdFontProp ,
		"���s���s���s" , 1 , 2 , 2 , CdPenProp() , 
		CConverter_WinGdi().CdBrushPropOf( WHITE_BRUSH ) ) ;
};
	
CDcdTextbox	CWndDcdGridEki::getCDcdEkikibo()const
{
	//CdFontProp aCdFontProp( getCDiagramEditDoc()->getCDedRosenFileData()->
	//	getCdDedDispProp().getJikokuhyouFont() ) ;
	CdFontProp aCdFontProp(	CConverter_WinGdi().CdFontPropOf( DEFAULT_GUI_FONT ) ) ;
	return CDcdTextbox( "" ,
		aCdFontProp ,
		"���s���s���s" , 1 , 2 , 2 , CdPenProp() , 
		CConverter_WinGdi().CdBrushPropOf( WHITE_BRUSH ) ) ;
};
	


CdEkiXColSpecCont CWndDcdGridEki::createXColSpecCont() 
{
	CdEkiXColSpecCont aSpecCont( 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont() ) ;
	return aSpecCont ;
}
CdEkiYColSpecCont CWndDcdGridEki::createYColSpecCont() 
{
	CdEkiYColSpecCont aSpecCont( 
		getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont() ) ;
	return aSpecCont ;
}	
CdEkiXColSpec CWndDcdGridEki::getXColSpecOfFocus() 
{
	CdEkiXColSpec aSpec ;
	CdDcdPosXy aPos = getCFocus()->getFocusCellColumnNumber() ;
	if ( aPos != getCFocus()->ColumnNumberPosXy_NULL() )
	{
		CdEkiXColSpecCont aSpecCont( 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont() ) ;
		aSpec = aSpecCont.ColumnNumberToSpec( aPos.getX() ) ;
	}
	return aSpec ;
}	
CdEkiYColSpec CWndDcdGridEki::getYColSpecOfFocus() 
{
	CdEkiYColSpec aSpec ;
	CdDcdPosXy aPos = getCFocus()->getFocusCellColumnNumber() ;
	if ( aPos != getCFocus()->ColumnNumberPosXy_NULL() )
	{
		CdEkiYColSpecCont aSpecCont( 
			getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen()->getCentDedEkiCont() ) ;
		aSpec = aSpecCont.ColumnNumberToSpec( aPos.getY() ) ;
	}
	return aSpec ;
}	
	
	
	
bool CWndDcdGridEki::
createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Eki>* ppCmd )
{
	bool bRv = false ;
	Ou<DedRosenFileData::EditCmd::CRfEditCmd_Eki> pCmd ;

	CdEkiYColSpecCont aCdYColSpecCont = createYColSpecCont() ;
	CdEkiYColSpec  aCdYColSpecOfFocus = getYColSpecOfFocus() ;

	// ********************************
	//	ECreateCmd_NewItem
	//�@�V�K�A�C�e����ΏۂƂ����R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_NewItem )
	{
		//�r���[��ŕ����I����OFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{
			//	�V�K�A�C�e���́A�����I�u�W�F�N�g
			//	�wIndex��0�̏ꍇ�́A�w�����`�����u��蒅�����v�Ƃ��܂��B
			CentDedEki aNewEki ;
			if ( aCdYColSpecOfFocus.getEkiIndex() == 0 )
			{
				aNewEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
			}


			//	�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 
			//
			//- m_iIndexDst = �t�H�[�J�X�Z���̃A�C�e��Index�Am_iIndexSize = 0
			//- m_CentDedEkiCont = �V�K�쐬���̃A�C�e���̊���l
			//- CaMuiSelect = ���Y�A�C�e����I���B
			if ( aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_Eki )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
						new CRfEditCmd_Eki( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getEkiIndex() , 
							0 , m_bAdjustByEkijikokukeisiki ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewEki , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			//�@�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ:
			//- m_iIndexDst = �����A�C�e��Index+1�Am_iIndexSize = 0
			//- m_CentDedEkiCont = �V�K�쐬���̃A�C�e���̊���l
			//- CaMuiSelect = ���Y�A�C�e����I���B
			else if ( aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
						new CRfEditCmd_Eki( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getEkiIndex() , 
							0 , m_bAdjustByEkijikokukeisiki ) ) ;
					pCmd->getCaMuiSelect()->insert( aNewEki , INT_MAX ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}
		}
		// �@�r���[��ŕ����I��ON:
		//	 - NULL��Ԃ��܂�([14/05/18]��:�����I��OFF�̏ꍇ�Ɠ�������)

	}
	// ********************************
	//	ECreateCmd_Focus
	//�@�t�H�[�J�X�Z�����1��Ԃ�ΏۂƂ����R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_Focus )
	{
		//�r���[��ŕ����I����OFF
		if ( getCSelect()->getSelectedCellCount() == 0 )
		{
			//�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 
			//- m_iIndexDst = �t�H�[�J�X�Z���̃A�C�e��Index�Am_iIndexSize = 1
			//- m_CentDedRessyaCont = �t�H�[�J�X�Z����̃A�C�e��1�̃R�s�[
			//- m_CaMuiSelect = �t�H�[�J�X�Z����̃A�C�e����I���B
			if ( aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_Eki )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
						new CRfEditCmd_Eki( 
							*getCDiagramEditDoc()->getCDedRosenFileData() , 
							aCdYColSpecOfFocus.getEkiIndex() , 
							1 , m_bAdjustByEkijikokukeisiki ) ) ;
					pCmd->getCaMuiSelect()->setSelectAll( true ) ;
				}
			}

			//�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ: 
			//- NULL��Ԃ��܂��B
		}
		//�r���[��ŕ����I��ON
		// - NULL��Ԃ��܂�([14/05/18]��:�����I��OFF�̏ꍇ�Ɠ�������)

	}
	// ********************************
	//	ECreateCmd_Select
	//�@�����̒P���܂��͕����I������Ă����Ԃ�ΏۂƂ���
	//	�R�}���h�𐶐����܂��B
	// ********************************
	if ( eCreateCmd == ECreateCmd_Select )
	{
		//�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 
		//- m_iIndexDst = �t�H�[�J�X�Z���̃A�C�e��Index�Am_iIndexSize = 1
		//- m_CentDedRessyaCont = �t�H�[�J�X�Z���̂���A�C�e��1�̃R�s�[
		//- CaMuiSelect = ���Y��Ԃ�I���B
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_Eki )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
					new CRfEditCmd_Eki( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						aCdYColSpecOfFocus.getEkiIndex() , 
						1 , m_bAdjustByEkijikokukeisiki ) ) ;
				pCmd->getCaMuiSelect()->setSelectAll( true ) ;
			}
		}

		//�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���ꍇ: 
		// - NULL��Ԃ��܂��B

		//�@�����\�r���[��ŕ����I��ON
		// - m_iIndexDst = �I������Ă����Ԃ̐擪index
		// - m_iIndexSize = �I������Ă����Ԃ̖���index-�擪index+1
		// - m_CentDedRessyaCont = �I������Ă����Ԃ̐擪index����
		//  ����index�܂ł̗�Ԃ̃R�s�[
		// - CaMuiSelect �́A�t�H�[�J�X�Z���ɍ��킹�ė�Ԃ�I���B
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
		//
		//- m_iIndexDst = 0�Am_iIndexSize = �A�C�e���̐�
		//- m_CentDedRessyaCont = �S�A�C�e���̃R�s�[
		//- m_CaMuiSelect �́A�S�A�C�e����I���B
		//
		// �r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ: 
		//
		//- m_iIndexDst = 0�Am_iIndexSize = �A�C�e���̐�
		//- m_CentDedRessyaCont = �S�A�C�e���̃R�s�[
		//- CaMuiSelect �́A�S�A�C�e����I���B
		if ( getCSelect()->getSelectedCellCount() == 0 
			&& ( aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_Eki 
			|| aCdYColSpecOfFocus.getColumnType() == CdEkiYColSpec::ColumnType_NewEki ) )
		{
			bRv = true ;
			if ( ppCmd != NULL )
			{
				pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
					new CRfEditCmd_Eki( 
						*getCDiagramEditDoc()->getCDedRosenFileData() , 
						0 , 
						aCdYColSpecCont.getEkiCount() ,
						m_bAdjustByEkijikokukeisiki ) ) ;
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
			deque<int> contiEkiIndex ;
			for ( int iColumnNumber = 0 ; iColumnNumber < getCXDcdGrid()->getYColumnCount() ;iColumnNumber ++ )
			{
				if ( getCSelect()->getYColumnNumberSelected( iColumnNumber ) )
				{
					CdEkiYColSpec aCdYColSpec = aCdYColSpecCont.ColumnNumberToSpec( iColumnNumber ) ;
					if ( aCdYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_Eki )
					{
						contiEkiIndex.push_back( aCdYColSpec.getEkiIndex() ) ;
					}
				}
			}
			//contiEkiIndex = ��̕����I�������{����Ă���ꍇ�́A
			//	�I������Ă���wIndex���i�[����܂��B
			//	�����łȂ��ꍇ�́A��ł��B

			if ( contiEkiIndex.size() > 1 )
			{
				bRv = true ;
				if ( ppCmd != NULL )
				{
					//	�R�}���h�I�u�W�F�N�g���ɁA�I������Ă���w�̐擪���疖���܂ł�
					//	�w���i�[���܂�(�擪�E�����ȊO�ɂ́A�I������Ă��Ȃ��w��
					//	�܂܂�Ă���ꍇ������܂�)
					pCmd = OuNew<DedRosenFileData::EditCmd::CRfEditCmd_Eki>( 
						new CRfEditCmd_Eki( 
							*getCDiagramEditDoc()->getCDedRosenFileData() ,
							contiEkiIndex.front() , 
							contiEkiIndex.back() - contiEkiIndex.front() + 1 ,
							m_bAdjustByEkijikokukeisiki ) ) ;

					//	�R�}���h�I�u�W�F�N�g��
					//	m_CentDedRessyaContSrc  ���̗�Ԃ�I�����܂��B
					pCmd->getCaMuiSelect()->setSelectAll( false ) ;
					for ( int i = 0 ; i < (int)contiEkiIndex.size() ; i ++ )
					{
						pCmd->getCaMuiSelect()->setSelect( contiEkiIndex[i] - contiEkiIndex.front()  , true ) ;
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

/**
	CentDedEki::EEkijikokukeisiki �ƁA�����񃊃\�[�XID�̑Ή��\
*/
struct {
	CentDedEki::EEkijikokukeisiki	m_eValue ;
	int m_iId ;
}	nameEEkijikokukeisiki[] = {
	{ CentDedEki::Jikokukeisiki_Hatsu ,IDS_WORD_Jikokukeisiki_Hatsu } ,
	{ CentDedEki::Jikokukeisiki_Hatsuchaku ,IDS_WORD_Jikokukeisiki_Hatsuchaku } ,
	{ CentDedEki::Jikokukeisiki_KudariChaku ,IDS_WORD_Jikokukeisiki_KudariChaku } ,
	{ CentDedEki::Jikokukeisiki_NoboriChaku ,IDS_WORD_Jikokukeisiki_NoboriChaku } ,
};

/**
	CentDedEki::EEkikibo �ƁA�����񃊃\�[�XID�̑Ή��\
*/
struct {
	CentDedEki::EEkikibo	m_eValue ;
	int m_iId ;
}	nameEkikibo[] = {
	{ CentDedEki::Ekikibo_Ippan , IDS_WORD_Ekikibo_Ippan } ,
	{ CentDedEki::Ekikibo_Syuyou , IDS_WORD_Ekikibo_Syuyou } ,
};


void CWndDcdGridEki::OnUpdate_setCentDedEki_To_Column( 
	int iYColumnNumber , const CentDedEki& aCentDedEki )
{
	if ( m_bWaitForActivate )
	{
		//	�r���[�̍X�V���X�V����Ă���Ȃ�A�㑱�̏����͍s���܂���
		return;
	}
	// ****************************************************************
	//	�r���[�̍X�V���ۗ�����Ă��Ȃ�
	// ****************************************************************

	bool bIsNull = aCentDedEki.getEkimei().empty() ;

	// --------------------------------
	//	��̃T�C�Y��ݒ�
	// --------------------------------
	{
		CDcdTargetGetDC	aCDcdTarget( NULL ) ;
		// --------------------------------
		//	Y��
		// --------------------------------
		{
			CdDcdSizeXy	sizeEkimei ;
			CDcdTextbox	aCDcdTextbox( 
				getCDcdEkimei() ) ;
			aCDcdTextbox.getItemSize( 
				&aCDcdTarget , &sizeEkimei ) ;

			getCXDcdGrid()->getYColumn( iYColumnNumber )
				->setColumnSize( sizeEkimei.getY() ) ;
		}
	}
	// --------------------------------
	//	�Z���̑�����ݒ�
	// --------------------------------
	{
		//	�w����� DcDraw �̑�����ݒ�
		Ou<CDcdTextbox>	pCDcdTextbox = 
			(getCXDcdGrid()->getCell( 0 , iYColumnNumber )->getIfDcDraw());
		*pCDcdTextbox = this->getCDcdEkimei() ;
	}
	{
		//	�w����� DcDraw �̑�����ݒ�
		Ou<CDcdTextbox>	pCDcdTextbox = 
			(getCXDcdGrid()->getCell( 1 , iYColumnNumber )->getIfDcDraw());
		*pCDcdTextbox = this->getCDcdEkijikokukeisiki() ;
	}
	{
		//	�w�K��
		Ou<CDcdTextbox>	pCDcdTextbox = 
			(getCXDcdGrid()->getCell( 2 , iYColumnNumber )->getIfDcDraw());
		*pCDcdTextbox = this->getCDcdEkikibo() ;
	}

	
	// --------------------------------
	//	�Z���̃e�L�X�g��ݒ�
	// --------------------------------
	//	�w��
	{
		Ou<CDcdTextbox>(getCXDcdGrid()
			->getCell( 	0 , iYColumnNumber )->getIfDcDraw())
				->setText( aCentDedEki.getEkimei() )  ;	
	}
	//	�w�����`��
	{
		string	strEkijikokukeisiki ;
		if ( !bIsNull )
		{
			int idx ;	
			for ( idx = 0 ; 
				idx < arrayof( nameEEkijikokukeisiki ) ; idx ++ )
			{
				if ( nameEEkijikokukeisiki[idx].m_eValue 
					== aCentDedEki.getEkijikokukeisiki() )
				{
					CString	strLs ;
					strLs.LoadString( nameEEkijikokukeisiki[idx].m_iId ) ;
					strEkijikokukeisiki = (LPCSTR)strLs ;
					break ;
				}
			}
		}
		Ou<CDcdTextbox>(getCXDcdGrid()
			->getCell( 1 , iYColumnNumber )->getIfDcDraw())->
				setText( strEkijikokukeisiki )  ;	
	}
	//	�w�K��
	{
		string	strEkikibo ;
		if ( !bIsNull ){
			int idx ;	
			for ( idx = 0 ; idx < arrayof( nameEkikibo ) ;	idx ++ ){
				if ( nameEkikibo[idx].m_eValue == 
						aCentDedEki.getEkikibo() )
				{
					CString	strLs ;
					strLs.LoadString( nameEkikibo[idx].m_iId ) ;
					strEkikibo = (LPCSTR)strLs ;
					break ;
				}
			}
		}
		Ou<CDcdTextbox>(getCXDcdGrid()->
			getCell( 2 , iYColumnNumber )->getIfDcDraw())
				->setText( strEkikibo )  ;	
		
	}
	// --------------------------------
	//	���E��
	// --------------------------------
	{
		CdPenProp aCdPenProp = getCdPenPropNormal() ;
		if ( !bIsNull ){
			if ( aCentDedEki.getKyoukaisen() ){
				aCdPenProp = getCdPenPropBold() ;
			}
		}
		Ou<CDcdLine>
			( getCXDcdGrid()->getYBorder( iYColumnNumber )->getIfDcDraw())
				->setCdPenProp( aCdPenProp ) ;
	}

	// --------------------------------
	//	�O���b�h�S�̂��X�V�̈�Ƃ��܂�
	// --------------------------------
	//	���E���̑������ϓ������ꍇ�́A
	//	���E���E����т����艺�̂��ׂẴZ���̍X�V���K�v�ł��B
	//	����ɑΉ����邽�߁A CWndDcdGridEki �ł́A
	//	�w�̑����̍X�V�̂��т�
	//	�O���b�h�S����X�V���܂��B
	InvalidateGrid() ;
}

void CWndDcdGridEki::OnUpdate_All() 
{
	CView *pView = getCDiagramEditApp()->getCMainFrame()->
		getMDIChildActiveView() ;
	if ( GetParent() != pView )
	{
		// ****************************************************************
		//	�r���[���A�N�e�B�u�ł͂Ȃ�
		// ****************************************************************
		m_bWaitForActivate = true ;
	}
	else
	{
		// ****************************************************************
		//	�r���[���A�N�e�B�u
		// ****************************************************************
		CWaitCursor	aCWaitCursor ;	

		// --------------------------------
		//	�r���[�̍X�V���s�����߂� OnUpdate_XXX() ���Ăяo���Ȃ�
		//	���炩���߈ȉ��̃t���O�� false �ɂ��Ȃ��Ă͂Ȃ�܂���
		m_bWaitForActivate = false ;

		//	�R�}���h�I�u�W�F�N�g���s�ɂ��Z���ړ��ŃZ���I���ɂȂ�Ȃ��悤�ɁA
		//	�Z���I�����������A�Z���I���@�\���ꎞ�I�ɒ��~���܂��B
		clearSelect() ;
		CPropStack aPropStack( this ) ;
		aPropStack
			.CBoxSelect_setIsEnable( false )
			.CRandomSelect_setIsEnable( false )  ;


		// --------------------------------
		//	�r���[���X�V
		// --------------------------------
		CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
		const CentDedRosen*	pCentDedRosen = 
			pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedEki*>* pCentDedEkiContGet = 
			pCentDedRosen->getCentDedEkiCont()->getMuPtr() ;

		//	Y�񐔂𑝌�������
		getCXDcdGrid()->setYColumnCount( 
			pCentDedEkiContGet->size() + 2 ) ;

		//	�w����̕���ݒ肷��
		{
			CDcdTargetGetDC	aTarget ;
			CDcdTextbox aCDcd = this->getCDcdEkimei() ;
			CdDcdSizeXy	aCdDcdSizeXy ;
			aCDcd.getItemSize( &aTarget , &aCdDcdSizeXy ) ;
			getCXDcdGrid()->getXColumn( 0 )->setColumnSize( 
				aCdDcdSizeXy.getX() ) ;
		}

		//	�e�Z���ɁA�f�[�^��ݒ�
		int idxEki ;
		for ( idxEki = 0 ; idxEki < pCentDedEkiContGet->size() ; 
				idxEki ++ ){
			const CentDedEki* pCentDedEki = pCentDedEkiContGet->get( idxEki ) ;
			OnUpdate_setCentDedEki_To_Column( idxEki + 1 , *pCentDedEki ) ;
		} 
		OnUpdate_setCentDedEki_To_Column( idxEki + 1 , CentDedEki() ) ;
		// ****************************************************************
	}
}

	// --------------------------------
	//@name ���j���[�R�}���h�̉����֐�
	// --------------------------------
int CWndDcdGridEki::OnEditCut_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki> pCmd ;
	Ou<CRfEditCmd_Eki>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}
	
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( CWndDcdGridEki::ECreateCmd_Select , ppCmd ) )
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
		getCDiagramEditDoc()->CentDedEki_To_Cliboard( 
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
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;	

}
int CWndDcdGridEki::OnEditCopy_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki> pCmd ;
	Ou<CRfEditCmd_Eki>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}
	
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( CWndDcdGridEki::ECreateCmd_Select , ppCmd ) )
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
		getCDiagramEditDoc()->CentDedEki_To_Cliboard( 
			pCmd->getCaMuiSelect() ) ;

		// -------------------------------- 
		//	�t�H�[�J�X�Z�����A�I��v�f���ōő�̉wIndex�̎��ʂɈړ�
		// --------------------------------
		{
			//	�Z���I�����N���A���A
			//	�t�H�[�J�X�Z���̈ړ��ɂ��Z���I���𖳌������܂��B
			clearSelect() ;
			CPropStack	aPropStack( this ) ;
			aPropStack
				.CBoxSelect_setIsEnable( false )
				.CRandomSelect_setIsEnable( false )  ;
		
			//	�I��v�f���ōő�̉wIndex �����߂�
			int iEkiIndexMax = -1 ;
			{
				CaMuiSelect<CentDedEki>* pCaMuiSelect = pCmd->getCaMuiSelect() ;
				for ( int iIndex = pCaMuiSelect->getAdapteeMu()->size() - 1  ; 
					iEkiIndexMax == -1 && iIndex >= 0 ; iIndex -- )
				{
					if ( pCaMuiSelect->getSelect( iIndex ) )
					{
						iEkiIndexMax = iIndex + pCmd->getIndexDst() ;
					}
				}
			}
			//iEkiIndexMax = �I������Ă����Ԃ̂����A�ő��Index

			//	�ړ���̃t�H�[�J�X�Z���ʒu������
			int iYColumnNmber = -1 ;
			{
				CdEkiYColSpecCont aCdEkiYColSpecCont = createYColSpecCont() ;
				iYColumnNmber = aCdEkiYColSpecCont.ColumnNumberFromSpec( 
					CdEkiYColSpec( CdEkiYColSpec::ColumnType_Eki , iEkiIndexMax ) ) + 1 ;
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
int CWndDcdGridEki::OnEditPaste_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki> pCmd ;
	Ou<CRfEditCmd_Eki>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}
	
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( CWndDcdGridEki::ECreateCmd_NewItem , ppCmd ) )
		{
			iRv = -1 ;	//	�Z���̈ʒu������������܂���B
		}
	}
	if ( iRv >= 0 )
	{
		if ( !getCDiagramEditDoc()->CentDedEki_IsClipboardFormatAvailable() )
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
		CentDedEkiCont	aEkiCont ;
		getCDiagramEditDoc()->CentDedEki_From_Cliboard( &aEkiCont ) ;
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�̉w��ҏW
		// --------------------------------
		{
			//	CWndDcdGridEki::ECreateCmd_NewItem �ɂ���Đ������ꂽ
			//	�V�K�A�C�e���͍폜���܂��B
			pCmd->getCaMuiSelect()->erase( 0 , INT_MAX ) ;

			//	�R�}���h�ɃN���b�v�{�[�h����̃A�C�e����ǉ����܂��B
			CaMui<CentDedEki> aCaMui( pCmd->getCaMuiSelect() ) ;
			aCaMui.insert( &aEkiCont , 0 , INT_MAX , 0 ) ;
		}
		// --------------------------------
		//	�R�}���h�I�u�W�F�N�g�����s
		// --------------------------------
		{
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}

	}
	return iRv ;

}
int CWndDcdGridEki::OnEditClear_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki> pCmd ;
	Ou<CRfEditCmd_Eki>* ppCmd = NULL ;
	if ( !bQueryEnable ){	ppCmd = &pCmd ;}
	
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( iRv >= 0 )
	{
		if ( !createCmd( CWndDcdGridEki::ECreateCmd_Select , ppCmd ) )
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
		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************

		// ****************************************************************
	}
	return iRv ;	

}

	/*	
		[�ҏW]-[�w��}��]
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
int CWndDcdGridEki:: OnEDITEkiInsert_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************
	if ( execEkiPropDlg( true , TRUE ) < 0 )
	{
		iRv = -1 ;	//	�t�H�[�J�X�̈ʒu���s���ł��B
	}

	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		execEkiPropDlg( true , FALSE ) ;

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

int CWndDcdGridEki::OnEditEkiInvert_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;

	// ****************************************************************
	//	�R�}���h�̎��s�ۂ̔���
	// ****************************************************************
	//	�R�}���h�̎��s�̉ۂ𔻒肵�܂��B
	//	�R�}���h�����s�s�\�Ȃ�A iRv �ɕ��̐���ݒ肵�Ă��������B

	const CentDedRosen*	pCentDedRosen = getCDiagramEditDoc()->getCDedRosenFileData()->getCentDedRosen() ;
	const Mu<const CentDedEki*>* pCentDedEkiContGet = pCentDedRosen->getCentDedEkiCont()->getMuPtr() ;
	
	
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		//	�R�}���h�����s���܂��B
		//	���ʂ��G���[�Ȃ�AiRv �ɕ��̐���ݒ肵�܂��B

		CentDedRosen	aRosenNew ;
		if ( iRv >= 0 )
		{
			//	�H�����擾��A�㉺�𔽓]���܂��B
			aRosenNew = *pCentDedRosen ;
			aRosenNew.invert() ;

			//	�X�V�R�}���h�𐶐�
		}
		// --------------------------------
		//	�R�}���h�𐶐��E���s
		// --------------------------------
		if ( iRv >= 0 )
		{
			OuNew<CRfEditCmd> pCmd(
				new CRfEditCmd_Rosen( aRosenNew )  
			);
			getCDiagramEditDoc()->executeEditCmd( pCmd ) ;
		}
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

	/*	
		[�ҏW]-[�w�̃v���p�e�B]
	*/
int CWndDcdGridEki:: OnEDITEkiProp_Process( BOOL bQueryEnable )
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	//	�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���Ƃ��́A
	//	�u�V�K�A�C�e���̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdEkiYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}

	if ( execEkiPropDlg( bInsert , TRUE ) < 0 )
	{
		iRv = -1 ;	//	-1 ;	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
	}
	// ****************************************************************
	if ( !bQueryEnable && iRv >= 0 )
	{
		// ****************************************************************
		//	�R�}���h�̎��s
		// ****************************************************************
		//	�R�}���h�����s���܂��B
		//	���ʂ��G���[�Ȃ�AiRv �ɕ��̐���ݒ肵�܂��B

		execEkiPropDlg( bInsert , FALSE ) ;

		// ****************************************************************
		//	�G���[���b�Z�[�W
		// ****************************************************************
		// ****************************************************************
	}
	return iRv ;
}

// ********************************
//	�R���X�g���N�^
// ********************************
CWndDcdGridEki::CWndDcdGridEki()
	: m_bAdjustByEkijikokukeisiki( true ) 
 	, m_bWaitForActivate( true )
	, m_bInitialUpdateComplete( false )
{
	getCSelect()->setSelectMode( CSelect::SelectMode_YColumn ) ;

}
CWndDcdGridEki::~CWndDcdGridEki()
{
}

	// ********************************
	//@name CWndDcdGridEki-����
	// ********************************
bool CWndDcdGridEki::getAdjustByEkijikokukeisiki()const 
{
	return m_bAdjustByEkijikokukeisiki ;
}
int CWndDcdGridEki::setAdjustByEkijikokukeisiki( bool value ) 
{
	int iRv = 0 ;
	if ( m_bAdjustByEkijikokukeisiki != value )
	{
		m_bAdjustByEkijikokukeisiki = value ;

		//	.ini �t�@�C���ɕۑ�
		getCDiagramEditApp()->writeCWndDcdGridEkiProp( this ) ;
		
		iRv = 1 ;
	}
	return iRv ;
}



	// ********************************
	//@name CEkiView ����̈Ϗ�
	// ********************************
void CWndDcdGridEki::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if ( lHint == LHINT_SUBVIEW_TO_ROOTDOC )
	{
		//	�r���[�̓��e���h�L�������g�ɔ��f������w�߂ł��B
		//	�㑱�̏����͍s���܂���B
		return ;
	}
	// --------------------------------
	//	�����OnUpdate()
	//	.ini�t�@�C������v���p�e�B��ǂݍ���
	// --------------------------------
	if ( !m_bInitialUpdateComplete )
	{
		getCDiagramEditApp()->readCWndDcdGridEkiProp( this ) ;
		// --------------------------------
		m_bInitialUpdateComplete = true ;
	}

	// --------------------------------
	//	�X�V�R�}���h���擾
	// --------------------------------
	Ou<CRfEditCmd> pCmd ;
	if ( pHint != NULL 
		&& pHint->IsKindOf(RUNTIME_CLASS(CRfEditCmdHolder)) )
	{
		CRfEditCmdHolder* pHolder = 
			(CRfEditCmdHolder*)pHint ;
		pCmd = pHolder->getCmd() ; 
	}
	//pCmd=�ҏW�R�}���h CRfEditCmd �B
	//	NULL�Ȃ�A�S�X�V���v������Ă��܂��B

	//pHint= 
	//	pHint�� CRfEditCmdHolder �I�u�W�F�N�g�Ȃ�A
	//	�Ή�����ҏW�R�}���h CRfEditCmd ��ێ����Ă��܂��B
	//	���̏ꍇ�Athis �� CRfEditCmd �̓��e�ɍœK������
	//	�X�V���s���܂��B
	//	NULL�Ȃ�A�S�X�V���v������Ă��܂��B

	if ( m_bWaitForActivate )
	{
		//	�S�X�V���ۗ�����Ă���ꍇ�́A
		//	�R�}���h�𖳎����āA�S�X�V���s���܂��B
		pCmd = Ou<CRfEditCmd>() ;
	}

	// --------------------------------
	{
		CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
		const CentDedRosen*	pCentDedRosen = 
			pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedEki*>* pCentDedEkiContGet 
			= pCentDedRosen->getCentDedEkiCont()->getMuPtr() ;

		if ( dynamic_castOu<CRfEditCmd_Comment>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Dia>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_DiaProp>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Ressya>( pCmd ) || 
			dynamic_castOu<CRfEditCmd_Ressyasyubetsu>( pCmd )||
			dynamic_castOu<CRfEditCmd_RessyasyubetsuSwap>
				( pCmd ) 
		)
		{
			//	���̃r���[�́A
			//		�R�����g�̕ύX
			//		�_�C���̕ύX
			//		�_�C���̃v���p�e�B�̕ύX
			//		��Ԃ̕ύX
			//		��Ԃ̒��ʉ�
			//		��Ԏ�ʂ̕ύX
			//		��Ԏ�ʂ̓���
			//	�̏ꍇ�́A�X�V���s���܂���B
			//
		}
		else if ( dynamic_castOu<CRfEditCmd_Eki>( pCmd ) )
		{	
			//		�w�̕ύX
			Ou<CRfEditCmd_Eki>	pCommand 
				= dynamic_castOu<CRfEditCmd_Eki>( pCmd );

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
			CentDedEkiCont	aCentDedEkiContSrc 
				= *pCommand->getCentDedEkiContSrc() ;
			int iGensyouSize = 
				pCommand->getSizeDst() - aCentDedEkiContSrc.size() ;
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
			iOkikaeSize = 
				min( pCommand->getSizeDst() , aCentDedEkiContSrc.size() ) ;
			int iZoukaSize = 
				aCentDedEkiContSrc.size() - pCommand->getSizeDst() ;
			if ( iZoukaSize > 0 )
			{
				for ( int cnt = 0 ; cnt < iZoukaSize ; cnt ++ )
				{
					getCXDcdGrid()->insertYColumn( 
						pCommand->getIndexDst() + iOkikaeSize + cnt + 1 , 
						true ) ; 
				}
			}
			// --------------------------------
			//	�v�f�̍X�V
			// --------------------------------
			{					
				for ( int cnt = 0 ; cnt < aCentDedEkiContSrc.size() ; cnt ++ )
				{
					int iEkiIndex = pCommand->getIndexDst() + cnt ;
					const CentDedEki*	pCentDedEki 
						= pCentDedEkiContGet->get( iEkiIndex ) ;
					OnUpdate_setCentDedEki_To_Column( 
						iEkiIndex + 1 , *pCentDedEki ) ;
				}
			}
			// --------------------------------
		}
		else
		{
			//CRfEditCmd_DedRosenFileDataProp
			//	  �H���t�@�C���̃v���p�e�B�̕ύX�́A
			//	�t�H���g�̕ω��𔺂����߁A�S�X�V���K�v�ł��B
			//CRfEditCmd_Rosen
			//CRfEditCmd_RosenFileData
			//	�w���܂���I�u�W�F�N�g�ł��B���ꂪ�X�V���ꂽ�ꍇ�́A
			//	�S�X�V���K�v�ł��B

			//	�S�v�f���X�V
			OnUpdate_All() ;
		}
	}
	// --------------------------------
	//	��I��͈͂�ݒ�
	// --------------------------------
	{
		CDiagramEditDoc* pCDiagramEditDoc = getCDiagramEditDoc() ;
		const CentDedRosen*	pCentDedRosen = 
			pCDiagramEditDoc->getCDedRosenFileData()->getCentDedRosen() ;
		const Mu<const CentDedEki*>* pCentDedEkiContGet 
			= pCentDedRosen->getCentDedEkiCont()->getMuPtr() ;

		int iYColumnBegin = createYColSpecCont().ColumnNumberFromSpec( 
			CdEkiYColSpec( CdEkiYColSpec::ColumnType_Eki , 0 ) ) ;

		getCSelect()->setColumnNumberSelectLimit(
			CdDcdZoneXy( 
				CdDcdZone( 0 , INT_MAX ) , 
				CdDcdZone( iYColumnBegin , pCentDedEkiContGet->size()   ) 
			) );
	}
}

void CWndDcdGridEki::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	if ( bActivate && m_bWaitForActivate ){
		OnUpdate_All() ;
	}
}





	// ********************************
	//@name CWndDcdGridEki-����
	// ********************************
	
int CWndDcdGridEki::execEkiPropDlg( bool bInsert , BOOL bQueryEnable ) 
{
	int iRv = 0 ;
	Ou<CRfEditCmd_Eki>	pCmd ;
	Ou<CRfEditCmd_Eki>*	ppCmd = NULL ;
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
		CdEkiXColSpec	aXColSpec = getXColSpecOfFocus() ;
		int iFocus = -1 ;
		switch( aXColSpec.getColumnType() )
		{
		case aXColSpec.ColumnType_Ekimei:
			iFocus = 0 ; 
			break ;
		case aXColSpec.ColumnType_Ekijikokukeisiki:
			iFocus = 1 ;
			break ;
		case aXColSpec.ColumnType_Ekikibo:
			iFocus = 2 ;
			break ;
		}
		CDlgEkiProp	aDlg( 
			pCmd->getCaMuiSelect()->getMuPtr() ,
			&m_bAdjustByEkijikokukeisiki , 
			iFocus , 
			&m_CKeyinputSenderToModalDlg , 
			this ) ;
		if ( aDlg.DoModal() == IDOK )
		{
			iRv = 1 ;

			//	[�w�������w�����`���Ő��K��]�̐ݒ���A
			//	���Ɏ��s����R�}���h�ɔ��f���܂��B
			pCmd->setAdjustByEkijikokukeisiki( m_bAdjustByEkijikokukeisiki ) ;
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

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
BEGIN_MESSAGE_MAP(CWndDcdGridEki,CWndDcdGridEki::super)
	//{{AFX_MSG_MAP(CWndDcdGridEki)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYUP()
	ON_COMMAND(ID_EDIT_EkiProp, OnEDITEkiProp)
	ON_COMMAND(ID_EDIT_EkiInsert, OnEDITEkiInsert)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_EDIT_EKI_INVERT, &CWndDcdGridEki::OnEditEkiInvert)
	ON_UPDATE_COMMAND_UI(ID_EDIT_EKI_INVERT, &CWndDcdGridEki::OnUpdateEditEkiInvert)
	ON_UPDATE_COMMAND_UI(ID_EDIT_EkiInsert, &CWndDcdGridEki::OnUpdateEditEkiinsert)
	ON_UPDATE_COMMAND_UI(ID_EDIT_EkiProp, &CWndDcdGridEki::OnUpdateEditEkiprop)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

int CWndDcdGridEki::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (super::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// --------------------------------
	//	��̐����w��
	// --------------------------------
	getCXDcdGrid()->setXColumnCount( 3 ) ;
	getCXDcdGrid()->setYColumnCount( 2 ) ;
	getCXDcdGrid()->setYFixColumnCount( 1 ) ;

	// --------------------------------
	//	��̃T�C�Y��ݒ�
	// --------------------------------
	{
		CDcdTargetGetDC	aCDcdTarget( NULL ) ;
		// --------------------------------
		//	X��
		// --------------------------------
		{
			//	�w��
			CDcdGridXColumn* pCDcdGridXColumn = getCXDcdGrid()->getXColumn( 0 ) ;
			CdDcdSizeXy	sizeEkimei ;
			CDcdTextbox	aCDcdTextbox( getCDcdEkimei() ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeEkimei ) ;
			pCDcdGridXColumn->setColumnSize( sizeEkimei.getX() ) ;
		}
		{
			//	�w�����`��
			CDcdGridXColumn* pCDcdGridXColumn = getCXDcdGrid()->getXColumn( 1 ) ;
			CdDcdSizeXy	sizeEkijikokukeisiki ;
			CDcdTextbox	aCDcdTextbox( 
				getCDcdEkijikokukeisiki() ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeEkijikokukeisiki ) ;

			pCDcdGridXColumn->setColumnSize( sizeEkijikokukeisiki.getX() ) ;
		}
		{
			//	�w�K��
			CDcdGridXColumn* pCDcdGridXColumn = getCXDcdGrid()->getXColumn( 2 ) ;
			CdDcdSizeXy	sizeEkikibo ;
			CDcdTextbox	aCDcdTextbox( 
				getCDcdEkikibo() ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeEkikibo ) ;

			pCDcdGridXColumn->setColumnSize( sizeEkikibo.getX() ) ;
		}
		// --------------------------------
		//	Y��
		// --------------------------------
		{
			CdDcdSizeXy	sizeEkimei ;
			CDcdTextbox	aCDcdTextbox( 
				getCDcdEkimei() ) ;
			aCDcdTextbox.getItemSize( &aCDcdTarget , &sizeEkimei ) ;

			getCXDcdGrid()->getYColumn( 0 )->setColumnSize( sizeEkimei.getY() ) ;
			getCXDcdGrid()->getYColumn( 1 )->setColumnSize( sizeEkimei.getY() ) ;
		}
	}
	// --------------------------------
	//	�ŏ�s�Ƀe�L�X�g��ݒ�
	// --------------------------------
	{
		CConverter_WinGdi	aConv ;
		
		CdDrawTextProp	aCdDrawTextProp( 
			aConv.CdFontPropOf( DEFAULT_GUI_FONT ) ,
			aConv.CdColorPropOfSysColor( COLOR_MENUTEXT ) ) ;
		CdBrushProp	aCdBrushProp( aConv.CdColorPropOfSysColor( COLOR_MENU ) ) ;



		{
			//	�w��
			CDcdGridCell* pCDcdGridCell = getCXDcdGrid()->getCell( 0 , 0 ) ;

			Ou<CDcdTextbox>	pCDcdTextbox = 
				pCDcdGridCell->getIfDcDraw() ;
			pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
			pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;

			CString	aString ;
			aString.LoadString( IDS_WORD_Ekimei ) ;
			Ou<CDcdTextbox>(pCDcdGridCell->getIfDcDraw())->setText( (LPCTSTR)aString ) ;
		}
		{
			//	�w�����`��
			CDcdGridCell* pCDcdGridCell = getCXDcdGrid()->getCell( 1 , 0 ) ;

			Ou<CDcdTextbox>	pCDcdTextbox = 
				pCDcdGridCell->getIfDcDraw() ;
			pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
			pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;

			CString	aString ;
			aString.LoadString( IDS_WORD_Jikokukeisiki ) ;
			Ou<CDcdTextbox>(pCDcdGridCell->getIfDcDraw())->setText( (LPCTSTR)aString ) ;
		}
		{
			//	�w�K��
			CDcdGridCell* pCDcdGridCell = getCXDcdGrid()->getCell( 2 , 0 ) ;

			Ou<CDcdTextbox>	pCDcdTextbox = 
				pCDcdGridCell->getIfDcDraw() ;
			pCDcdTextbox->setCdDrawTextProp( aCdDrawTextProp ) ;
			pCDcdTextbox->setCdBrushProp( aCdBrushProp )  ;

			CString	aString ;
			aString.LoadString( IDS_WORD_Ekikibo ) ;
			Ou<CDcdTextbox>(pCDcdGridCell->getIfDcDraw())->setText( (LPCTSTR)aString ) ;
		}
	}
	// --------------------------------
	//	�t�H�[�J�X�Z���̏����ʒu��ݒ�
	// --------------------------------
	getCFocus()->setFocusCell( getCXDcdGrid()->getCell( 0 , 1 ) ) ;	
	
	return 0;
}

void CWndDcdGridEki::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	LogMsg( "CWndDcdGridEki::OnKeyDown(%08X,%04X,%08X)" , nChar, nRepCnt, nFlags) ; 

	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	//	�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���Ƃ��́A
	//	�u�V�K�A�C�e���̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdEkiYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}

	// ****************************************************************


	//	�����L�[��������Ă��āA�_�C�A���O�{�b�N�X���J���Ă��Ȃ��ꍇ��
	//	�_�C�A���O�{�b�N�X���J���܂��B
	if ( CKeyinputSenderToModalDlg::AnyLetterOrDigitKeyIsDown() && 
			m_CKeyinputSenderToModalDlg.startSend() >= 0 )
	{
		m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) ;
		execEkiPropDlg( bInsert , FALSE ) ;
		m_CKeyinputSenderToModalDlg.endSend() ;
	}
	//	���łɃ_�C�A���O���N�������_�C�A���O�{�b�N�X�Ƀ��b�Z�[�W��]��
	else	
	{
		if ( !m_CKeyinputSenderToModalDlg.OnKeyDown( nChar , nRepCnt , nFlags ) )
		{
			CWndDcdGridEki::super::OnKeyDown(nChar, nRepCnt, nFlags);
		}
	}
			
}

void CWndDcdGridEki::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	int iRv = 0 ;
	// ****************************************************************
	//	�R�}���h�̗L���E��������
	// ****************************************************************

	//	�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���Ƃ��́A
	//	�u�V�K�A�C�e���̃v���p�e�B���͂��s���A����𖖔��ɑ}������v�Ƃ���
	//	����ɂȂ�܂��B
	bool bInsert = false ;
	CdEkiYColSpec aYColSpec = getYColSpecOfFocus() ;
	if ( aYColSpec.getColumnType() == CdEkiYColSpec::ColumnType_NewEki )
	{
		bInsert = true ;
	}

	// ****************************************************************
	//	�R�}���h�̎��s
	// ****************************************************************
	if ( execEkiPropDlg( bInsert , FALSE ) < 0 )
	{
		iRv = -1 ;	//	-1 ;	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
	}
	// ****************************************************************

	CWndDcdGridEki::super::OnLButtonDblClk(nFlags, point);
}

void CWndDcdGridEki::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if ( !m_CKeyinputSenderToModalDlg.OnKeyUp( nChar , nRepCnt , nFlags ) )
	{
		CWndDcdGridEki::super::OnKeyUp(nChar, nRepCnt, nFlags);
	}
}

void CWndDcdGridEki::OnEDITEkiProp() 
{
	OnEDITEkiProp_Process( FALSE );
}
void CWndDcdGridEki::OnUpdateEditEkiprop(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEDITEkiProp_Process( TRUE ) >= 0 ) ;
}


void CWndDcdGridEki::OnEDITEkiInsert() 
{
	OnEDITEkiInsert_Process( FALSE ) ;
}
void CWndDcdGridEki::OnUpdateEditEkiinsert(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEDITEkiInsert_Process( TRUE ) >= 0 ) ;
}


void CWndDcdGridEki::OnEditClear() 
{
	OnEditClear_Process( FALSE ) ;
}

void CWndDcdGridEki::OnEditCut() 
{
	OnEditCut_Process( FALSE ) ;
}

void CWndDcdGridEki::OnEditCopy() 
{
	OnEditCopy_Process( FALSE ) ;

}

void CWndDcdGridEki::OnEditPaste() 
{
	OnEditPaste_Process( FALSE ) ;
	
}

void CWndDcdGridEki::OnUpdateEditClear(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditClear_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridEki::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditCut_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridEki::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditCopy_Process( TRUE ) >= 0 ) ;
}

void CWndDcdGridEki::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable( OnEditPaste_Process( TRUE ) >= 0 ) ;
}


void CWndDcdGridEki::OnEditEkiInvert()
{
	OnEditEkiInvert_Process( FALSE ) ;
}

void CWndDcdGridEki::OnUpdateEditEkiInvert(CCmdUI *pCmdUI)
{
	pCmdUI->Enable( OnEditEkiInvert_Process( TRUE ) >= 0 ) ;
}



void CWndDcdGridEki::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CMenu	aMenu ;
	aMenu.LoadMenu( IDR_MENU_EKIVIEW_CONTEXT ) ;
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

} //namespace ViewEki
