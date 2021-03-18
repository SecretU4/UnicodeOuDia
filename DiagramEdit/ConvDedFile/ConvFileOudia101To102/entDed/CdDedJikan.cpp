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
//	CdDedJikan.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include <deque>
using namespace std ;

#include "CdDedJikan.h"
#include "str/stringSplit.h"
#include "str/strprintf.h"


#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif


// ****************************************************************
//	CdDedJikan::CConv
// ****************************************************************
CdDedJikan::CConv::CConv() 
	: m_bNoSecond( false )
	, m_bPlusDisplay( false ) 
	, m_bPlusToSpace( false ) 
{
};

CdDedJikan::CConv::CConv( 
			bool bNoSecond ,
			bool bPlusDisplay ,
			bool bPlusToSpace  ) 
	: m_bNoSecond( bNoSecond )
	, m_bPlusDisplay( bPlusDisplay ) 
	, m_bPlusToSpace( bPlusToSpace ) 
{
}

std::string CdDedJikan::CConv::encode( const CdDedJikan& aJikan )const 
{
	string	strRv ;
	{
		//  ����
		if ( m_bPlusDisplay )
		{
			strRv += "- +"[ sign( aJikan.getTotalSeconds() ) + 1 ] ;
		} 
		else if ( m_bPlusToSpace )
		{
			strRv += "-  "[ sign( aJikan.getTotalSeconds() ) + 1 ] ;
		}
		else
		{
			if ( aJikan.getTotalSeconds() < 0 )
			{
				strRv += "- +"[ sign( aJikan.getTotalSeconds() ) + 1 ] ;
			}
		}

		//	��
		{
			//char	szLs[16] ;
			//sprintf( szLs , "%d" , aJikan.getHour() ) ;
			//strRv += szLs ;
			strRv += OuLib::strprintf( "%d" , aJikan.getHour() ) ;
		}
		//	���̂��̃R����
		{
			strRv += ":" ;
		}
		//	��
		{
			//char	szLs[16] ;
			//sprintf( szLs , "%02d" , aJikan.getMinute() ) ;
			//strRv += szLs ;
			strRv += OuLib::strprintf( "%02d" , aJikan.getMinute() ) ;
		}
		if ( !m_bNoSecond )
		{
			//	���̂��̃R����
			{
				strRv += ":" ;
			}
			//	�b
			{
				//char	szLs[16] ;
				//sprintf( szLs , "%02d" , aJikan.getSecond() ) ;
				//strRv += szLs ;
				strRv += OuLib::strprintf( "%02d" , aJikan.getSecond()  ) ;
			}
		}
	}
	return ( strRv ) ;

};



// ****************************************************************
//	CdDedJikan
// ****************************************************************

// ********************************
//	�R���X�g���N�^
// ********************************
	
CdDedJikan::CdDedJikan( int iSign , int iHour , int iMinute , int iSecond ) :
	m_iTotalSeconds( 
		sign( iSign ) * ( iHour * 60 * 60 + iMinute * 60 + iSecond ) ) 
{
}
CdDedJikan::CdDedJikan( const string& strTime ) 
	: m_iTotalSeconds( 0 )
{
	decode( strTime ) ;
}

// ********************************
//	CdDedJikan
// ********************************
	// ********************************
	//@name ����
	// ********************************
	
CdDedJikan& CdDedJikan::setTime( int iSign , int iHour , int iMinute , int iSecond ) 
{
	m_iTotalSeconds = 
		sign( iSign ) * ( iHour * 60 * 60 + iMinute * 60 + iSecond ) ; 
	return ( *this ) ;
}
	
	
	// ********************************
	//@name ����
	// ********************************
int CdDedJikan::compare( const CdDedJikan& value )const 
{
	if ( m_iTotalSeconds > value.m_iTotalSeconds ){
		return ( 1 ) ;
	}	else if ( m_iTotalSeconds < value.m_iTotalSeconds ){
		return ( -1 ) ;
	}
	return ( 0 ) ;
}
	
CdDedJikan& CdDedJikan::addSeconds( int value ) 
{
		m_iTotalSeconds += value ;

	return *this ;
}

int CdDedJikan::subJikan( const CdDedJikan& value )const
{
	int iRv = 0 ; 

		iRv = m_iTotalSeconds - value.m_iTotalSeconds ;

	return ( iRv ) ;
}

int CdDedJikan::decode( const string& value ) 
{
	int	iRv = 0 ;
	
	deque<string>	contstrValue = 
		OuLib::splitc< deque<string> >( ':' , value ) ;
	//contstrValue = strValue �� ":" �ŋ�؂�܂��B
	//	�i��j 
	//	strValue = "13:15:45" �̏ꍇ�A
	//		contstrValue[0]="13"
	//		contstrValue[1]="15"
	//		contstrValue[2]="45"
	//	strValue = "-9:15" �̏ꍇ�A
	//		contstrValue[0]="-9"
	//		contstrValue[1]="15"
	

	//	�b���Ȃ��ꍇ�͒ǉ�
	if ( contstrValue.size() == 2 ){
		contstrValue.push_back( "00" ) ;
	}
	//strValue = "13:15:45","9:15:00"
	//

	if ( contstrValue.size() != 3 ){
		//	contstrValue ���A���E���E�b�łȂ��ꍇ�́A�s���ł��B
		m_iTotalSeconds = 0 ;
		iRv = -1 ;	//	���ڐ����s�����Ă��܂��B
		return ( iRv ) ;
	}
	// --------------------------------
	int iSign = 0 ;
	int iHour = -1 ;
	int iMinute = -1 ;
	int iSecond = -1 ;


	//	+ ������ǉ����܂��B
	{
		string	strLs = contstrValue[0] ;

		if (  strLs.length() > 0 ){
			if ( strLs[0] == ' ' ){
				strLs[0] = '+' ;
			}	else if ( strLs[0] != '+' && strLs[0] != '-' ){
				strLs = string( "+" ) + strLs ;
			}
		}
		contstrValue[0] = strLs ;
	}



	//strValue = "13:15:45","09:15:00"

	{
		//	�����E��
		{
			string	strLs = contstrValue[0] ;
			if ( strLs.length() > 0 ){
				if ( strLs[0] == '+' ){
					iSign = 1 ;
				}	else if ( strLs[0] == '-' ){
					iSign = -1 ;
				}
				strLs.erase( 0 , 1 ) ;
				if ( strLs.find_first_not_of( "0123456789" ) == string::npos ){
					iHour = atoi( strLs.c_str() ) ;
				}
			}
		}
		//	��
		{
			string	strLs = contstrValue[1] ;
			if ( strLs.length() > 0 ){
				if ( strLs.find_first_not_of( "0123456789" ) == string::npos ){
					iMinute = atoi( strLs.c_str() ) ;
				}
			}
		}
		//	�b
		{
			string	strLs = contstrValue[2] ;
			if ( strLs.length() > 0 ){
				if ( strLs.find_first_not_of( "0123456789" ) == string::npos ){
					iSecond = atoi( strLs.c_str() ) ;
				}
			}
		}
	}
	
	if ( iHour >= 0 && iMinute >= 0 && iSecond >= 0 ){
		setTime( iSign , iHour , iMinute , iSecond ) ;
	}	else	{
		m_iTotalSeconds = 0 ;
		iRv = -2 ;	//	���E���E�b�̕\�L���s���ł��B
	}
	
	return ( iRv ) ;
}

