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
//	strLf.cpp
// ****************************************************************
*/
#include "str\strLf.h"

namespace OuLib{


//	�����񒆂́A"\r\n" �� "\n" �ɕϊ����܂��B
//	�����񒆂́A"\n" �ɑ΂��ẮA�������܂���B
//[in]strEv 
//	�ϊ���������
//[retval]
//	�ϊ���̕�����
std::string strLfOf( const std::string& strEv ) 
{
	std::string	strRv ;
	std::string::const_iterator	iteSrc = strEv.begin() ;
	for ( ; iteSrc != strEv.end() ; iteSrc ++ ){
		if ( *iteSrc == '\r' && 
				iteSrc + 1 != strEv.end() && 
				*( iteSrc + 1 ) == '\n' ){
			//	"\r\n" ���݂��܂����B
			strRv += '\n' ;
			iteSrc ++ ;
		}	else if ( *iteSrc == '\n' ){
			//	"\n" ���݂��܂����B
			strRv += '\n' ;
		}	else	{
			//	���̑��̕�����
			strRv += *iteSrc ;
		}
	}
	return ( strRv ) ;
}

//	�����񒆂́A"\n" �� "\r\n" �ɕϊ����܂��B
//	�����񒆂́A"\r\n" �ɑ΂��ẮA�������܂���B
//[in]strEv 
//	�ϊ���������
//[retval]
//	�ϊ���̕�����
std::string strCrlfOf( const std::string& strEv ) 
{
	std::string	strRv ;
	std::string::const_iterator	iteSrc = strEv.begin() ;
	for ( ; iteSrc != strEv.end() ; iteSrc ++ ){
		if ( *iteSrc == '\r' && 
				iteSrc + 1 != strEv.end() && 
				*( iteSrc + 1 ) == '\n' ){
			//	"\r\n" ���݂��܂����B
			strRv += "\r\n" ;
			iteSrc ++ ;
		}	else if ( *iteSrc == '\n' ){
			//	"\n" ���݂��܂����B
			strRv += "\r\n" ;
		}	else	{
			//	���̑��̕�����
			strRv += *iteSrc ;
		}
	}
	return ( strRv ) ;
}

/*
* 	�����񒆂̍����E���邢�͉E���́A�A�������󔒗ނ̕������폜���܂��B
* @param strEv [in]
* 	�ϊ���������
* @param bLeft [in]
* 	�^�Ȃ�A�����̋󔒗ނ��폜���܂��B
* @param bRight [in]
* 	�^�Ȃ�A�E���̋󔒗ނ��폜���܂��B
* @param strSpaces [in]
* 	�󔒗ނƂ݂Ȃ���������ׂ���������w�肵�Ă��������B
*   ���̊֐��́A���̕�����Ɋ܂܂�Ă��Ȃ������́A�󔒂Ƃ݂͂Ȃ��܂���B
* @return
* 	�폜��̕�����
*/
std::string strTrim( const std::string& strEv , 
						bool bLeft , 
						bool bRight , 
						const std::string& strSpaces ) 
{
	std::string	strRv = strEv ;
	
	//	Left
	if ( bLeft ){
		std::string::size_type	pos = strRv.find_first_not_of( strSpaces ) ;
		if ( pos != std::string::npos ){
			strRv = strRv.substr( pos ) ;
		}
	}
	
	//	right
	if ( bRight ){
		std::string::size_type	pos = strRv.find_last_not_of( strSpaces ) ;
		if ( pos != std::string::npos ){
			strRv = strRv.substr( 0 , pos + 1 ) ;
		}
	}
	return ( strRv ) ;
}




} ;
