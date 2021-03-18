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
// $Id: CConvFile_Oudia05To06.cpp 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
#include "stdafx.h"
#include <vector>
#include <string>
using namespace std ;

#include "CConvFile_Oudia05To06.h"
#include "Str\OuPropertiesText\CConvNodeContainer.h"
#include "Str\OuPropertiesText\CDirectory.h"
#include "Str\strLf.h"
#include "Str\strToVector.h"
#include "Str\vectorToFile.h"
#include "ou\dynamic_castOu.h"
static const char nameFileType[] = "FileType" ;
static const char valueFileTypeLeftFormat[] = "OuDia.5" ;
static const char valueFileTypeRightFormat[] = "OuDia.6" ;
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia05To06 Ver 0.01" ;

// ****************************************************************
//	CConvFile_Oudia05To06
// ****************************************************************
CConvFile_Oudia05To06::CConvFile_Oudia05To06()
{
}
CConvFile_Oudia05To06::~CConvFile_Oudia05To06()
{
}
	// ********************************
	//@name IfConvFile
	// ********************************

/**

�y�ϊ����e�z

�@.oud �t�@�C�� �� Oudia.5 �ł́A [DispProp\DiaRessyajouhouHyoujiEkiOrderKudari] �ɁA
 �wOrder�ŁA�_�C���O�����r���[�̗�ԏ��\�����w�肳��Ă��܂����B

   .oud �t�@�C���� OuDia.6 �ł́A [Rosen.Eki(n).DiagramRessyajouhouHyoujiKudari] �ŁA
���̉w�ɗ�ԏ���\�����邩�ۂ����w�肳��Ă��܂��B

  Eki(n) �́A�f�B���N�g���̖��O�ł͂Ȃ��A 0����n�܂�C���f�N�X n �� [Eki] �f�B���N�g���B

�@�ϊ����e�͈ȉ��̒ʂ�ł��B
 
@code
int iEkiOrder = ( [DispProp\DiaRessyajouhouHyoujiEkiOrderKudari] �ɋL���ꂽ���� ) ;
[Rosen.Eki(iEkiOrder).DiagramRessyajouhouHyoujiKudari]=1 
@endcode




*/
const char nameDispProp[] = "DispProp" ;
const char nameDiaRessyajouhouHyoujiEkiOrderKudari[]="DiaRessyajouhouHyoujiEkiOrderKudari" ;
const char nameDiaRessyajouhouHyoujiEkiOrderNobori[]="DiaRessyajouhouHyoujiEkiOrderNobori" ;

const char nameRosen[] = "Rosen" ;
const char nameEki[] = "Eki" ;
const char nameDiagramRessyajouhouHyoujiKudari[] = "DiagramRessyajouhouHyoujiKudari" ;
const char nameDiagramRessyajouhouHyoujiNobori[] = "DiagramRessyajouhouHyoujiNobori" ;
const char nameDiagramRessyajouhouHyouji_Not[] = "DiagramRessyajouhouHyouji_Not" ;


int CConvFile_Oudia05To06::LeftToRight( 
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

	OuPropertiesText::CNodeContainer	nodecontainerLeftFormat ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		int iResult = aConv.decode( 
			strLeftFormat , 
			&nodecontainerLeftFormat ,
			&strErrorInfoString ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	�t�@�C�����������t�H�[�}�b�g�ł͂���܂���B
		}
	}
	//nodecontainerLeftFormat = LeftFile�̓��e��ێ����Ă��܂��B


	// --------------------------------
	//	�����Ԃ̏���
	// --------------------------------
	//int iEkiOrder = ( [DispProp.DiaRessyajouhouHyoujiEkiOrderKudari] �ɋL���ꂽ���� ) ;
	//
	//	[Rosen.Eki[0].DiagramRessyajouhouHyoujiKudari]�`
	//	[Rosen.Eki[iEkiOrder-1].DiagramRessyajouhouHyoujiKudari]
	//	�ɁADiagramRessyajouhouHyouji_Not ��ݒ�
	if ( iRv >= 0 )
	{
		int iEkiOrder = -1 ;
		if ( iRv >= 0 )
		{
			Ou<OuPropertiesText::CDirectory> pCDirectory ;
			pCDirectory = dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameDispProp , 0 ) ) ; 
			//pCDirectory = [DispProp] 
			if ( pCDirectory != NULL )
			{
				string strValue = pCDirectory->getCNodeContainer()->getValue( 
					nameDiaRessyajouhouHyoujiEkiOrderKudari ) ;
				//strValue = [DispProp\DiaRessyajouhouHyoujiEkiOrderKudari]
				if ( !strValue.empty() )
				{
					iEkiOrder = atoi( strValue.c_str() ) ;

					//[DispProp\DiaRessyajouhouHyoujiEkiOrderKudari] �͍폜
					pCDirectory->getCNodeContainer()->eraseInName( 
						nameDiaRessyajouhouHyoujiEkiOrderKudari , 0 , INT_MAX ) ;
				}
				else
				{
					iRv = -12 ;	//	DiaRessyajouhouHyoujiEkiOrderKudari ��������܂���B
				}
			}
		}
		//iEkiOrder = �_�C���O������ł̗�ԏ��\���ʒu

		//	[Rosen.Eki[0].DiagramRessyajouhouHyoujiKudari]�`
		//	[Rosen.Eki[iEkiOrder-1].DiagramRessyajouhouHyoujiKudari]
		//	�ɁADiagramRessyajouhouHyouji_Not ��ݒ�
		if ( iRv >= 0 )
		{
			Ou<OuPropertiesText::CDirectory> pCDirectory ;
			pCDirectory = dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameRosen , 0 ) ) ; 
			//pCDirectory = [Rosen]
			if ( pCDirectory != NULL )
			{
				for ( int idxEkiOrder = 0 ; idxEkiOrder < iEkiOrder ; idxEkiOrder ++ )
				{
					Ou<OuPropertiesText::CDirectory> pCDirectoryEki = 
						dynamic_castOu<OuPropertiesText::CDirectory>( 
							pCDirectory->getCNodeContainer()->getInName( nameEki , idxEkiOrder ) ) ; 
					//pCDirectory = [Rosen.Eki[idxEkiOrder]]
					if ( pCDirectoryEki != NULL )
					{
						pCDirectoryEki->getCNodeContainer()->setValue( 
							nameDiagramRessyajouhouHyoujiKudari , 
							nameDiagramRessyajouhouHyouji_Not ) ;
					}
					//[Rosen.Eki[idxEkiOrder].nameDiagramRessyajouhouHyoujiKudari] 
					//	�� "DiagramRessyajouhouHyouji_Not" ��ݒ肵�܂����B
				}
			}
		}
	}

	// --------------------------------

	// --------------------------------
	//	����Ԃ̏���
	// --------------------------------
	//int iEkiOrder = ( [DispProp.DiaRessyajouhouHyoujiEkiOrderNobori] �ɋL���ꂽ���� ) ;
	//
	//[Rosen.Eki[Rosen.Eki �̐� - 1].DiagramRessyajouhouHyoujiNobori]
	//[Rosen.Eki[Rosen.Eki �̐� - iEkiOrder ].DiagramRessyajouhouHyoujiNobori]
	//	�ɁADiagramRessyajouhouHyouji_Not ��ݒ�
	if ( iRv >= 0 )
	{
		int iEkiOrder = -1 ;
		if ( iRv >= 0 )
		{
			Ou<OuPropertiesText::CDirectory> pCDirectory ;
			pCDirectory = dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameDispProp , 0 ) ) ; 
			//pCDirectory = [DispProp] 
			if ( pCDirectory != NULL )
			{
				string strValue = pCDirectory->getCNodeContainer()->getValue( 
					nameDiaRessyajouhouHyoujiEkiOrderNobori ) ;
				//strValue = [DispProp\DiaRessyajouhouHyoujiEkiOrderNobori]
				if ( !strValue.empty() )
				{
					iEkiOrder = atoi( strValue.c_str() ) ;

					//[DispProp\DiaRessyajouhouHyoujiEkiOrderNobori] �͍폜
					pCDirectory->getCNodeContainer()->eraseInName( 
						nameDiaRessyajouhouHyoujiEkiOrderNobori  , 0 , INT_MAX ) ;
				}
				else
				{
					iRv = -22 ;	//	DiaRessyajouhouHyoujiEkiOrderNobori ��������܂���B
				}
			}
		}
		//iEkiOrider = �_�C���O������ł̗�ԏ��\���ʒu
		//	[DispProp.DiaRessyajouhouHyoujiEkiOrderNobori] �ɋL����Ă�������
		if ( iRv >= 0 )
		{
			int iEkiIndex = -1 ;
			Ou<OuPropertiesText::CDirectory> pCDirectory ;
			pCDirectory = dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameRosen , 0 ) ) ; 
			//pCDirectory = [Rosen]
			if ( pCDirectory != NULL )
			{
				int iEkiIndex = pCDirectory->getCNodeContainer()->sizeInName( nameEki ) ;
				for ( int idxEkiOrder = 0 ; idxEkiOrder < iEkiOrder ; idxEkiOrder ++ )
				{
					iEkiIndex -- ;

					Ou<OuPropertiesText::CDirectory> pCDirectoryEki = 
						dynamic_castOu<OuPropertiesText::CDirectory>( 
							pCDirectory->getCNodeContainer()->getInName( nameEki , iEkiIndex ) ) ; 
					//pCDirectory = [Rosen.Eki[iEkiIndex]]
					if ( pCDirectoryEki != NULL )
					{
						pCDirectoryEki->getCNodeContainer()->setValue( 
							nameDiagramRessyajouhouHyoujiNobori , 
							nameDiagramRessyajouhouHyouji_Not ) ;
					}
					//[Rosen.Eki[iEkiIndex].nameDiagramRessyajouhouHyoujiNobori] 
					//	�� "DiagramRessyajouhouHyouji_Not" ��ݒ肵�܂����B
				}

			}
		}
	}

	// --------------------------------

	//FileType��ύX
	if ( iRv >= 0 )
	{
		nodecontainerLeftFormat.setValue( 
			nameFileType , 
			valueFileTypeRightFormat ) ;
	}
	//FileTypeAppComment�𖖔��ɒǉ�
	if ( iRv >= 0 )
	{
		nodecontainerLeftFormat.setValue( 
			nameFileTypeAppComment , 
			valueFileTypeAppComment ) ;
	}

	
	// --------------------------------
	string strRightFormat ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		strRightFormat = aConv.encode( 
			&nodecontainerLeftFormat ) ;
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

int CConvFile_Oudia05To06::isLeftFormat( 
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
	OuPropertiesText::CNodeContainer	nodecontainerLeftFormat ;
	if ( iRv >= 0 )
	{
		OuPropertiesText::CConvNodeContainer	aConv ;
		int iResult = aConv.decode( 
			strLeftFormat , 
			&nodecontainerLeftFormat ,
			&strErrorInfoString ) ;
		if ( iResult < 0 )
		{
			iRv = -11 ;	//	�t�@�C�����������t�H�[�}�b�g�ł͂���܂���B
		}
	}
	if ( iRv >= 0 )
	{
		string strValue = nodecontainerLeftFormat.getValue(
			nameFileType ) ;
		if ( strValue != valueFileTypeLeftFormat )
		{
			iRv = -1 ;	//	FileType ������������܂���B
		}
	}
	return iRv ;
}

bool CConvFile_Oudia05To06::RightToLeftIsSupported() 
{
	return false ;
}

int CConvFile_Oudia05To06::RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	return -2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
}

int CConvFile_Oudia05To06::isRightFormat( 
		const IfByteBuffer* pRightFormat ) 
{
	return -2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
};




