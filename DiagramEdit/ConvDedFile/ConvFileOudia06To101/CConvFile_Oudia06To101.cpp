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
// $Id: CConvFile_Oudia06To101.cpp 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
#include "stdafx.h"
#include <vector>
#include <string>
using namespace std ;

#include "CConvFile_Oudia06To101.h"
#include "Str\OuPropertiesText\CConvNodeContainer.h"
#include "Str\OuPropertiesText\CDirectory.h"
#include "Str\strLf.h"
#include "Str\strToInt.h"
#include "Str\strToVector.h"
#include "Str\vectorToFile.h"
#include "ou\dynamic_castOu.h"
#include "ou\OuNew.h"

static const char nameFileType[] = "FileType" ;
static const char valueFileTypeLeftFormat[] = "OuDia.6" ;
static const char valueFileTypeRightFormat[] = "OuDia.1.01" ;
static const char nameFileTypeAppComment[] = "FileTypeAppComment" ;
static const char valueFileTypeAppComment[] = "ConvFileOudia06To101 Ver 0.01" ;

// ****************************************************************
//	CConvFile_Oudia06To101
// ****************************************************************
CConvFile_Oudia06To101::CConvFile_Oudia06To101()
{
}
CConvFile_Oudia06To101::~CConvFile_Oudia06To101()
{
}
	// ********************************
	//@name IfConvFile
	// ********************************

const char nameRosen[] = "Rosen" ;
const char nameRessyasyubetsu[] = "Ressyasyubetsu" ;
const char nameJikokuhyouFontIndex[] = "JikokuhyouFontIndex" ;
const char nameDispProp[] = "DispProp" ;
const char nameJikokuhyouFont[] = "JikokuhyouFont" ;




int CConvFile_Oudia06To101::LeftToRight( 
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
	//	��4.0��[FileType]
	//
	//  "OuDia.6"��"OuDia.1.01" �ɕϊ����܂��B
	// --------------------------------
	if ( iRv >= 0 )
	{
		nodecontainerLeftFormat.setValue( 
			nameFileType , 
			valueFileTypeRightFormat ) ;
	}
	/* --------------------------------
	��4.1��[Rosen.Ressyasyubetsu[]]

	��4.1.1��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]

	��[Rosen.Ressyasyubetsu]�ɁA[Rosen.Ressyasyubetsu.JikokuhyouFont]���Ȃ��ꍇ�B
	   ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 �Ƃ��܂��B

	��[Rosen.Ressyasyubetsu]�ɁA[Rosen.Ressyasyubetsu.JikokuhyouFont]������ꍇ�B
	  ��[DispProp.JikokuhyouFont[]]�ɓ����t�H���g������ꍇ�B
		��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
			DispProp.JikokuhyouFont[]�́A����t�H���g�̃C���f�N�X
		.
	  ��[DispProp.JikokuhyouFont[]]�ɓ����t�H���g���Ȃ��ꍇ�B
		��[DispProp.JikokuhyouFont[]]�̗v�f����8�ȓ��̏ꍇ�B
�@		  ��[DispProp.JikokuhyouFont[]]�̖����ɗv�f��ǉ����A
�@�@		[Rosen.Ressyasyubetsu.JikokuhyouFont]�̓��e���R�s�[
�@		  ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
�@�@		����ǉ�����DispProp.JikokuhyouFont[] �̃C���f�N�X
		��else
�@		  ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 �Ƃ��܂��B

	��4.1.2��[Rosen.Ressyasyubetsu.JikokuhyouFont]
	  �d�l����͔p�~����܂����A�R���o�[�^�͂��̒l��ҏW���܂���B
	 -------------------------------- */
	if ( iRv >= 0 )
	{
		int idxRessyasyubetsu = 0 ; 
		
		Ou<OuPropertiesText::CDirectory> pdirRosen = 
			dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameRosen , 0 ) ) ; 
		//pdirRosen = [Rosen] 

		Ou<OuPropertiesText::CDirectory> pdirDispProp = 
			dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameDispProp , 0 ) ) ; 
		//pdirDispProp = [DispProp] 
		if ( pdirRosen != NULL && pdirDispProp != NULL )
		{
			int cRessyasyubetsu = pdirRosen->getCNodeContainer()->sizeInName( nameRessyasyubetsu ) ;
			//cRessyasyubetsu = [Rosen.Ressyasyubetsu] �̐� 

			for ( idxRessyasyubetsu = 0 ; 
				iRv >= 0 && idxRessyasyubetsu < cRessyasyubetsu ; 
				idxRessyasyubetsu ++ )
			{
				Ou<OuPropertiesText::CDirectory> pdirRessyasyubetsu = 
					dynamic_castOu<OuPropertiesText::CDirectory>( 
					pdirRosen->getCNodeContainer()->getInName( nameRessyasyubetsu , idxRessyasyubetsu ) ) ; 
				if ( pdirRessyasyubetsu != NULL )
				{
					//pdirRessyasyubetsu = [Rosen.Ressyasyubetsu[]] 
					int iJikokuhyouFontIndex = 0 ;
					string strJikokuhyouFont = pdirRessyasyubetsu->getCNodeContainer()->getValue( nameJikokuhyouFont ) ;

					//��[Rosen.Ressyasyubetsu]�ɁA[Rosen.Ressyasyubetsu.JikokuhyouFont]���Ȃ��ꍇ�B
					//   ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 �Ƃ��܂��B
					if ( strJikokuhyouFont.length() == 0 )
					{
						iJikokuhyouFontIndex = 0 ;
					}
					//��[Rosen.Ressyasyubetsu]�ɁA[Rosen.Ressyasyubetsu.JikokuhyouFont]������ꍇ�B
					else
					{
						int cJikokuhyouFont = pdirDispProp->getCNodeContainer()->sizeInName( nameJikokuhyouFont ) ;
						int idxJikokuhyouFont = 0 ; 
						for ( idxJikokuhyouFont = 0 ; 
							idxJikokuhyouFont < cJikokuhyouFont ; 
							idxJikokuhyouFont ++ )
						{
							string strJikokuhyouFontInJikokuhyou ;
							
							Ou<OuPropertiesText::CPropertyString> pnodeJikokuhyouFont = 
								dynamic_castOu<OuPropertiesText::CPropertyString>( 
								pdirDispProp->getCNodeContainer()->getInName( nameJikokuhyouFont , idxJikokuhyouFont ) ) ;
							if ( pnodeJikokuhyouFont != NULL )
							{
								strJikokuhyouFontInJikokuhyou = pnodeJikokuhyouFont->getValue() ;
							}
							if ( strJikokuhyouFont == strJikokuhyouFontInJikokuhyou )
							{
								break ;
							}
						}
						//  ��[DispProp.JikokuhyouFont[]]�ɓ����t�H���g������ꍇ�B
						//	  ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
						//		DispProp.JikokuhyouFont[]�́A����t�H���g�̃C���f�N�X
						if ( idxJikokuhyouFont < cJikokuhyouFont )
						{
							iJikokuhyouFontIndex = idxJikokuhyouFont ;
						}
						//  ��[DispProp.JikokuhyouFont[]]�ɓ����t�H���g���Ȃ��ꍇ�B
						else
						{
							//    ��[DispProp.JikokuhyouFont[]]�̗v�f����8�ȓ��̏ꍇ�B
							//      ��[DispProp.JikokuhyouFont[]]�̖����ɗv�f��ǉ����A
							//	      [Rosen.Ressyasyubetsu.JikokuhyouFont]�̓��e���R�s�[
							//      ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=
							//	      ����ǉ�����DispProp.JikokuhyouFont[] �̃C���f�N�X
							if ( cJikokuhyouFont < 8 )
							{
								pdirDispProp->getCNodeContainer()->insertInName(
									OuNew<OuPropertiesText::CPropertyString>( new
										OuPropertiesText::CPropertyString( 
										nameJikokuhyouFont , strJikokuhyouFont ) ) ) ;
								iJikokuhyouFontIndex = cJikokuhyouFont ;
							}
							//    ��else
							//      ��[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]=0 �Ƃ��܂��B
							else
							{
								iJikokuhyouFontIndex = 0 ;
							}
						}
					}


					// --------------------------------
					pdirRessyasyubetsu->getCNodeContainer()->setValue( 
						nameJikokuhyouFontIndex , 
						OuLib::stringOf( iJikokuhyouFontIndex ) ) ;
				}
			}
		}
	}


	/* --------------------------------
	��4.2��[DispProp.JikokuhyouFont[]]

	  �ϊ��́A[Rosen.Ressyasyubetsu.JikokuhyouFontIndex[]]�̕ϊ��Ɠ����ɍs���܂��B
	 -------------------------------- */

/*	// --------------------------------
	//(1)[Rosen.Ressyasyubetsu.JikokuhyouFontIndex]
	//  [Rosen.Ressyasyubetsu.JikokuhyouFontIndex]��V�݂��܂����B
	//  ���̒l�́A0�`7�ŁA���̗�Ԏ�ʂ̎����\���Ŏg�p����t�H���g���w�肵�܂��B
	//  ���̒l�́A[DispProp.JikokuhyouFont]�̃C���f�N�X���w�肵�܂��B
	//  �y�ϊ����e�z���̒l�́A0�����蓖�Ă܂��B
	// --------------------------------
	if ( iRv >= 0 )
	{
		int idxRessyasyubetsu = 0 ; 
		
		Ou<OuPropertiesText::CDirectory> pdirRosen = 
			dynamic_castOu<OuPropertiesText::CDirectory>( 
				nodecontainerLeftFormat.getInName( nameRosen , 0 ) ) ; 
		//pdirRosen = [Rosen] 
		if ( pdirRosen != NULL )
		{
			int cRessyasyubetsu = pdirRosen->getCNodeContainer()->sizeInName( nameRessyasyubetsu ) ;
			//cRessyasyubetsu = [Rosen.Ressyasyubetsu] �̐� 

			for ( idxRessyasyubetsu = 0 ; 
				iRv >= 0 && idxRessyasyubetsu < cRessyasyubetsu ; 
				idxRessyasyubetsu ++ )
			{
				Ou<OuPropertiesText::CDirectory> pdirRessyasyubetsu = 
					dynamic_castOu<OuPropertiesText::CDirectory>( 
					nodecontainerLeftFormat.getInName( nameRessyasyubetsu , idxRessyasyubetsu ) ) ; 
				//pdirRessyasyubetsu = [Rosen.Ressyasyubetsu[]] 

				if ( pdirRessyasyubetsu != NULL )
				{
					pdirRessyasyubetsu->getCNodeContainer()->setValue( 
						nameJikokuhyouFontIndex , "0" ) ;
				}
			}
		}
	}
	// --------------------------------
	//(2)[DispProp.JikokuhyouFont]
	//�@���̒l��8�̃G���g���������܂��B
	//
	//  �y�ϊ����e�z���̒l�́A�]����[DispProp.JikokuhyouFont](1��)���A8�ɕ������܂��B
	// --------------------------------
	if ( iRv >= 0 )
	{
		Ou<OuPropertiesText::CDirectory> pdirDispProp = 
			dynamic_castOu<OuPropertiesText::CDirectory>( 
			nodecontainerLeftFormat.getInName( nameDispProp , 0 ) ) ;
		//pdirDispProp = [DispProp]

		string strValue = pdirDispProp->getCNodeContainer()->getValue( nameJikokuhyouFont ) ;
		//strValue = [DispProp.JikokuhyouFont]

		if ( !strValue.empty() )
		{
			while( pdirDispProp->getCNodeContainer()->sizeInName( nameJikokuhyouFont ) < 8 ) 
			{
				pdirDispProp->getCNodeContainer()->insertInName( 
					OuNew<OuPropertiesText::CPropertyString>( new OuPropertiesText::CPropertyString( 
					nameJikokuhyouFont , strValue ) )
				) ;
			}
		}
	}
*/
	// --------------------------------
	//FileTypeAppComment�𖖔��ɒǉ�
	// --------------------------------
	if ( iRv >= 0 )
	{
		nodecontainerLeftFormat.setValue( 
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

int CConvFile_Oudia06To101::isLeftFormat( 
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

bool CConvFile_Oudia06To101::RightToLeftIsSupported() 
{
	return false ;
}

int CConvFile_Oudia06To101::RightToLeft( 
		const IfByteBuffer* pRightFormat , 
		IfByteBuffer* pLeftFormat , 
		IfByteBuffer* pErrorInfoString ) 
{
	return -2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
}

int CConvFile_Oudia06To101::isRightFormat( 
		const IfByteBuffer* pRightFormat ) 
{
	return -2 ;	//	���̃��\�b�h�̓T�|�[�g����Ă��܂���B
};




