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
// $Id: CConvFile_Oudia03To05.cpp 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
#include "stdafx.h"
#include <vector>
#include <string>
using namespace std ;
#include "CConvFile_Oudia03To05.h"
#include "Str\strToVector.h"
#include "Str\strLf.h"
#include "Str\strprintf.h"
#include "03\CconvCDedRosenFileData_03.h"
#include "CDedRosenFileData.h"
#include "CconvCDedRosenFileData.h"

static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia03To05 Ver 0.01" ;

// ****************************************************************
//	CConvFile_Oudia03To05
// ****************************************************************
CConvFile_Oudia03To05::CConvFile_Oudia03To05()
{
}
CConvFile_Oudia03To05::~CConvFile_Oudia03To05()
{
}
	// ********************************
	//@name IfConvFile
	// ********************************
int CConvFile_Oudia03To05::LeftToRight( 
		const IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pRightFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	int iRv = 0 ;
	string strErrorInfoString ;
	if ( iRv >= 0 )
	{
		int iResult = isLeftFormat( pLeftFormat ) ;
		//	-	-1 ;	//	FileType ������������܂���B
		//	-	-101 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
		if ( iResult < 0 )
		{
			switch( iResult )
			{
			case -1 :	//	FileType ������������܂���B
				strErrorInfoString = "FileType Mismatch." ;
				break ;
			case -101 :	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
				strErrorInfoString = "Invalid Subitem Data." ;
				break ;
			}
			iRv = iResult ;
		}
	}
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

	CDedRosenFileData aCDedRosenFileData ;
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData_03	aConv ;
		int iResult = aConv.CDedRosenFileData_from_string(
			&aCDedRosenFileData , 
			strLeftFormat ) ;
		//	-	-1 ;	//	FileType ������������܂���B
		//	-	-11 ;	//	Rosen �̓��e���s��
		//	-	-21 ;	//	DispProp �̓��e���s��
		//	-	-101 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
		if ( iResult < 0 )
		{
			switch( iResult )
			{
			case -1 :	//	FileType ������������܂���B
				strErrorInfoString = "FileType Mismatch." ;
				break ;
			case -11 :	//	Rosen �̓��e���s��
				strErrorInfoString = "Invalid Rosen Data." ;
				break ;
			case -21 :	//	DispProp �̓��e���s��
				strErrorInfoString = "Invalid DispProp Data." ;
				break ;
			case -101 :	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
				strErrorInfoString = "Invalid Subitem Data." ;
				break ;
			}
			iRv = iResult ;
		}

	}
	//aCDedRosenFileData = �H���t�@�C����ǂݍ��ނ��Ƃ��ł��܂����B

	//aCDedRosenFileData�@�ɏW�񂳂�Ă����Ԏ�ʂɂ́A
	//	��ʖ� CentDedRessyasyubetsu::m_strSyubetsumei ��
	//	�󕶎���̂��̂��������Ă���\��������܂�
	//	(CconvCDedRosenFileData_03 �̃o�O)�B
	//	�������A����� CconvCDedRosenFileData(Ver.5)�ł�
	//	�G���[�ɂȂ��Ă��܂��܂��E
	//	���̂��߁AaCDedRosenFileData ��
	//	��Ԏ�ʖ����󕶎���̂��̂�����΁A
	//	���̗�Ԏ�ʖ���ݒ肵�܂��B
	if ( iRv >= 0 )
	{
		CentDedRosen* pCentDedRosen = aCDedRosenFileData.getCentDedRosen() ;
		CentDedRessyasyubetsuCont* pCentDedRessyasyubetsuCont = 
			pCentDedRosen->getCentDedRessyasyubetsuCont() ;
		for ( int idxRessyasyubetsu = 0 ; 
			idxRessyasyubetsu < pCentDedRessyasyubetsuCont->size() ;
			idxRessyasyubetsu ++ )
		{
			CentDedRessyasyubetsu aCentDedRessyasyubetsu = 
				pCentDedRessyasyubetsuCont->get( idxRessyasyubetsu ) ;
			if ( aCentDedRessyasyubetsu.getSyubetsumei().empty() )
			{
				aCentDedRessyasyubetsu.setSyubetsumei( 
					OuLib::strprintf( "%d" , idxRessyasyubetsu + 1 ) ) ;
				pCentDedRessyasyubetsuCont->set( 
					aCentDedRessyasyubetsu , 
					idxRessyasyubetsu ) ;
			}
		}
	}


	string strRightFormat ;
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData	aConv ;
		int iResult = aConv.CDedRosenFileData_to_string( 
			aCDedRosenFileData ,
			&strRightFormat ) ;
		//	-	-11 ;	//	Ekimei ���w�肳��Ă��܂���B
		//	-	-22 ;	//	Ekijikokukeisiki �̒l���s���ł��B
		//	-	-32 ;	//	Ekikibo �̒l���s���ł��B
		//	-	-111 ;	//	Syubetsumei ���w�肳��Ă��܂���B
		//	-	-152 ;	//	DiagramSenStyle �̒l���s���ł��B
		//	-	-212 ;	//	DiagramEkiatsukai �̒l���s���ł��B
		if ( iResult < 0 )
		{
			switch( iResult )
			{
			case -11 :	//	Ekimei ���w�肳��Ă��܂���B
				strErrorInfoString = "Ekimei is not valid." ;
				break ;
			case -22 :	//	Ekijikokukeisiki �̒l���s���ł��B
				strErrorInfoString = "Ekijikokukeisiki is not valid." ;
				break ;
			case -32 :	//	Ekikibo �̒l���s���ł��B
				strErrorInfoString = "Ekikibo is not valid." ;
				break ;
			case -111 :	//	Syubetsumei ���w�肳��Ă��܂���B
				strErrorInfoString = "Syubetsumei is not valid." ;
				break ;
			case -152 :	//	DiagramSenStyle �̒l���s���ł��B
				strErrorInfoString = "DiagramSenStyle is not valid." ;
				break ;
			case -212 :	//	DiagramEkiatsukai �̒l���s���ł��B
				strErrorInfoString = "DiagramEkiatsukai is not valid." ;
				break ;
			}
			//	-	-211 ;	//	Ekimei ���w�肳��Ă��܂���B
			//	-	-222 ;	//	Ekijikokukeisiki �̒l���s���ł��B
			//	-	-232 ;	//	Ekikibo �̒l���s���ł��B
			//	-	-311 ;	//	Syubetsumei ���w�肳��Ă��܂���B
			//	-	-352 ;	//	DiagramSenStyle �̒l���s���ł��B
			//	-	-412 ;	//	DiagramEkiatsukai �̒l���s���ł��B
			iRv = iResult - 200 ;
		}
	}

	//FileTypeAppComment�𖖔��ɒǉ�
	if ( iRv >= 0 )
	{
		strRightFormat += "\n" ;
		strRightFormat += OuLib::strprintf( "%s=%s" , 
			nameFileTypeAppComment , 
			valueFileTypeAppComment ) ;
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

int CConvFile_Oudia03To05::isLeftFormat( 
		const IfByteBuffer* pLeftFormat) 
{
	int iRv = 0 ;
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
	if ( iRv >= 0 )
	{
		CconvCDedRosenFileData_03	aConv ;
		int iResult = aConv.isEncodeAbleFormat( 
			strLeftFormat ) ;
		//	-	0 ;	//	���߉\�ł��B
		//	-	-1 ;	//	FileType ������������܂���B
		//	-	-101 ;	//	�J�����g�T�u�A�C�e������R�}���h�Ƒޏ�R�}���h���Ή����܂���B	
		if ( iResult < 0 )
		{
			iRv = iResult ;
		}
	}
	return iRv ;
}

bool CConvFile_Oudia03To05::RightToLeftIsSupported() 
{
	return false ;
}

int CConvFile_Oudia03To05::RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	return -2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
}

int CConvFile_Oudia03To05::isRightFormat( 
		const IfByteBuffer* pRightFormat ) 
{
	return -2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
};




