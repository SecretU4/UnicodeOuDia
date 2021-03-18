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
// $Id: CConvFile_Oudia101To102.cpp 174 2014-05-05 13:26:26Z okm $
// ****************************************************************

#include "stdafx.h"
#include "CConvFile_Oudia101To102.h"

#include <string>
#include <vector>

#include "Str\strToVector.h"
#include "Str\strLf.h"
#include "Str\strToWstr.h"
#include "ou\dynamic_castOu.h"
#include "ou\OuNew.h"
#include "DcdCd\DcDrawProp\CconvDcDrawProp.h"
#include "DcDraw\CConverter_WinGdi.h"
#include "DedRosenFileData\CconvCDedRosenFileData.h"


namespace ConvFile_Oudia101To102{


static const char nameFileType[] = "FileType" ;
static const char valueFileTypeLeftFormat[] = "OuDia.1.01" ;
static const char valueFileTypeRightFormat[] = "OuDia.1.02" ;
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia101To102 Ver 0.01" ;


// ****************************************************************
//	CConvFile_Oudia101To102
// ****************************************************************
	// --------------------------------
	//@name �����֐�
	// --------------------------------
CdFontProp CConvFile_Oudia101To102::createVFontPropFromHFont( 
		const CdFontProp& aCdFontProp ) 
{
	int iRv = 0 ;

	CdFontProp	aCdFontPropV = aCdFontProp ;
	aCdFontPropV.setFacename( string( "@" ) + aCdFontPropV.getFacename() ) ;
	CConverter_WinGdi	aConv ;
	Ou<CGdiHFontHolder>	aHFontHolder = aConv.createGdiHFontHolder( aCdFontPropV ) ;
	if ( aHFontHolder != NULL )
	{
		LOGFONT	aLOGFONT ;
		int iResult = GetObject( aHFontHolder->getHFont() , sizeof(aLOGFONT) , &aLOGFONT ) ;
		if ( iResult == 0 ){
			iRv = -2 ;	//	GetObject�Ɏ��s
		}
		else
		{
			aCdFontPropV.setFacename( OuLib::stringOf( aLOGFONT.lfFaceName ) ) ;
		}
	}
	return aCdFontPropV ;
}


	// ********************************
	//	�R���X�g���N�^
	// ********************************

CConvFile_Oudia101To102::CConvFile_Oudia101To102()
{
}
CConvFile_Oudia101To102::~CConvFile_Oudia101To102()
{
}
	// ********************************
	//@name IfConvFile
	// ********************************
int CConvFile_Oudia101To102::LeftToRight( 
		const IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pRightFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	int iRv = 0 ;
	string strErrorInfoString ;
	// --------------------------------
	//	�t�@�C���t�H�[�}�b�g�̊m�F
	// --------------------------------
	if ( iRv >= 0 )
	{
		int iResult = isLeftFormat( pLeftFormat ) ;
		//	-	-1 ;	//	FileType ������������܂���B
		//	-	-11 ;	//	�t�@�C�����������t�H�[�}�b�g�ł͂���܂���B
		if ( iResult < 0 )
		{
			switch( iResult )
			{
			case -1 :	//	FileType ������������܂���B
				strErrorInfoString = "FileType Mismatch." ;
				break ;
			case -11 :	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
				strErrorInfoString = "File Format Error." ;
				break ;
			}
			iRv = iResult ;
		}
		//iRv = 
		//	-	-1 ;	//	FileType ������������܂���B
		//	-	-11 ;	//	�t�@�C�����������t�H�[�}�b�g�ł͂���܂���B
	}
	// --------------------------------
	//	�o�C�g��� 
	//	OuPropertiesText::CNodeContainer �ɓǂݍ���
	// --------------------------------
	string strLeftFormat ;
	if ( iRv >= 0 )
	{
		vector<char> binLeftFormat ;
		binLeftFormat.resize( pLeftFormat->size() ) ;
		if ( binLeftFormat.size() > 0 )
		{
			pLeftFormat->read( 
				&binLeftFormat[0] , 
				0 , 
				binLeftFormat.size() ) ;
		}
		strLeftFormat = OuLib::stringOf( binLeftFormat ) ;
		strLeftFormat = OuLib::strLfOf( strLeftFormat ) ;
	}
	//strLeftFormat = LeftFile �̓��e

	CNodeContainer	nodecontRoot ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		int iResult = aConv.decode( 
			strLeftFormat , 
			&nodecontRoot ,
			&strErrorInfoString ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	�t�@�C�����������t�H�[�}�b�g�ł͂���܂���B
		}
	}
	//nodecontRoot = LeftFile�̓��e��ێ����Ă��܂��B

	// --------------------------------
	//��FileType
	//	  "OuDia.1.01"��"OuDia.1.02" �ɕϊ����܂��B
	// --------------------------------
	if ( iRv >= 0 )
	{
		nodecontRoot.setValue( 
			nameFileType , 
			valueFileTypeRightFormat ) ;
	}
	// --------------------------------
	//	CDedRosenFile�𐶐�
	// --------------------------------
	CDedRosenFileData	aCDedRosenFileData ;
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData	aConv ;
		ErrorInfo::COuErrorInfoContainer	aErrorInfoConteiner ;

		int iResult = aConv.CDedRosenFileData_from_OuPropertiesText( 
			&aCDedRosenFileData ,
			&nodecontRoot ,
			&aErrorInfoConteiner ) ;
		if ( iResult < 0 )
		{
			iRv = -21 ;	//	CDedRosenFileData �ւ̕ϊ��Ɏ��s���܂����B
			strErrorInfoString = aErrorInfoConteiner.toOuErrorInfoText() ;
		}
	}
	

	// --------------------------------
	//��Rosen.Eki[0].Ekijikokukeisiki
	//	�@"Jikokukeisiki_Hatsu"��"Jikokukeisiki_NoboriChaku" �ɕύX
	// --------------------------------
	CentDedRosen* pCentDedRosen = NULL ;
	if ( iRv >= 0 )
	{
		pCentDedRosen = aCDedRosenFileData.getCentDedRosen() ;
		if ( pCentDedRosen->getCentDedEkiCont()->size() > 0 ) 
		{
			CentDedEki aCentDedEki = pCentDedRosen->getCentDedEkiCont()->get( 0 ) ;
			if ( aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsu )
			{
				aCentDedEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_NoboriChaku ) ;
			}
			pCentDedRosen->getCentDedEkiCont()->set( aCentDedEki ,0 );
			pCentDedRosen->adjustByEkijikokukeisiki( 0 ) ;
		}
	}
	// --------------------------------
	//��Rosen.Eki[����].Ekijikokukeisiki
	//	�@"Jikokukeisiki_Hatsu"��"Jikokukeisiki_KudariChaku" �ɕύX
	// --------------------------------
	if ( iRv >= 0 )
	{
		pCentDedRosen = aCDedRosenFileData.getCentDedRosen() ;
		if ( pCentDedRosen->getCentDedEkiCont()->size() > 0 ) 
		{
			CentDedEki aCentDedEki = pCentDedRosen->getCentDedEkiCont()->get( INT_MAX ) ;
			if ( aCentDedEki.getEkijikokukeisiki() == CentDedEki::Jikokukeisiki_Hatsu )
			{
				aCentDedEki.setEkijikokukeisiki( CentDedEki::Jikokukeisiki_KudariChaku ) ;
			}
			pCentDedRosen->getCentDedEkiCont()->set( aCentDedEki ,INT_MAX );
			pCentDedRosen->adjustByEkijikokukeisiki( INT_MAX ) ;
		}
	}
	// --------------------------------
	//��DispProp.JikokuhyouVFont
	//	�@DispProp.JikokuhyouFont[0] �̃t�F�C�X���̐擪�� "@" ��t�^���� 
	//	CreateFont() ���s���܂��B
	//	�@�������ꂽ�t�H���g�̑������A���̒l�ɃZ�b�g���܂��B
	// --------------------------------
	if ( iRv >= 0 )
	{
		CdDedDispProp aCdDedDispProp = aCDedRosenFileData.getCdDedDispProp() ;
		CdFontProp	aCdFontProp = aCdDedDispProp.getJikokuhyouFont( 0 ) ;
		aCdFontProp = createVFontPropFromHFont( aCdFontProp ) ;
		aCdDedDispProp.setJikokuhyouVFont( aCdFontProp ) ;
		aCDedRosenFileData.setCdDedDispProp( aCdDedDispProp ) ;
	}
	// --------------------------------
	//	CDedRosenFile�� ���[�g�m�[�h�ɔ��f����
	// --------------------------------
	if ( iRv >= 0 )
	{
		//	���[�g�m�[�h�͈�U��ɂ���B
		nodecontRoot.erase( 0 , INT_MAX ) ;

		CconvCDedRosenFileData	aConv ;

		int iResult = aConv.CDedRosenFileData_to_OuPropertiesText( 
			&aCDedRosenFileData ,
			&nodecontRoot ) ;
		if ( iResult < 0 )
		{
			iRv = -22 ;	//	CDedRosenFileData �ւ̕ϊ��Ɏ��s���܂����B
		}
	}

	// --------------------------------
	//��FileTypeAppComment
	//	"ConvFileOudia101To102 Ver 0.01"
	// --------------------------------
	if ( iRv >= 0 )
	{
		nodecontRoot.setValue( 
			nameFileTypeAppComment , 
			valueFileTypeAppComment ) ;
	}

	
	// --------------------------------
	//	CConvNodeContainer ��
	//	�o�C�g��ɕϊ�
	// --------------------------------
	string strRightFormat ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		strRightFormat = aConv.encode( 
			&nodecontRoot ) ;
	}


	//strRightFormat = RightFile �̓��e
	vector<char> binRightFormat ;
	if ( iRv >= 0 )
	{
		strRightFormat = OuLib::strCrlfOf( strRightFormat ) ;
		binRightFormat = OuLib::vectorCharOf( strRightFormat ) ;
	}
	// --------------------------------
	if ( pRightFormat != NULL )
	{
		pRightFormat->size_reset( binRightFormat.size() ) ;
		if ( binRightFormat.size() > 0 )
		{
			pRightFormat->write( &binRightFormat[0] , 0 , binRightFormat.size() ) ;
		}
	}
	if ( pErrorInfoString != NULL )
	{
		pErrorInfoString->size_reset( strErrorInfoString.size() ) ;
		if ( strErrorInfoString.size() > 0 )
		{
			pErrorInfoString->write( strErrorInfoString.c_str() , 0 , strErrorInfoString.size() ) ;
		}
	}
	return iRv ;
}

int CConvFile_Oudia101To102::isLeftFormat( 
		const IfByteBuffer* pLeftFormat)  
{
	int iRv = 0 ;
	string strErrorInfoString ;

	string strLeftFormat ;
	if ( iRv >= 0 )
	{
		vector<char> binLeftFormat ;
		binLeftFormat.resize( pLeftFormat->size() ) ;
		if ( binLeftFormat.size() > 0 )
		{
			pLeftFormat->read( 
				&binLeftFormat[0] , 
				0 , 
				binLeftFormat.size() ) ;
		}
		strLeftFormat = OuLib::stringOf( binLeftFormat ) ;
		strLeftFormat = OuLib::strLfOf( strLeftFormat ) ;
	}
	//strLeftFormat = pLeftFormat ���i�[����������ł��B
	OuPropertiesText::CNodeContainer	nodecontRoot ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		int iResult = aConv.decode( 
			strLeftFormat , 
			&nodecontRoot ,
			&strErrorInfoString ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	�t�@�C�����������t�H�[�}�b�g�ł͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		string strValue = nodecontRoot.getValue(
			nameFileType ) ;
		if ( strValue != valueFileTypeLeftFormat )
		{
			iRv = -1 ;	//	FileType ������������܂���B
		}
	}
	return iRv ;
}

bool CConvFile_Oudia101To102::RightToLeftIsSupported()
{
	return false ;
}

int CConvFile_Oudia101To102::RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	return -2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
}
int CConvFile_Oudia101To102::isRightFormat( 
		const IfByteBuffer* pRightFormat ) 
{
	return -2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
};


} //namespace ConvFile_Oudia101To102
