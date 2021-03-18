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
//	CdDedJikoku.cpp
// ****************************************************************
*/
#include "stdafx.h"

#include "CdDedJikoku.h"
#include "str\strprintf.h"

using namespace std ;

#ifndef _CONSOLE
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

namespace entDed{
	using namespace OuLib::Str;

// ****************************************************************
//	CdDedJikoku::CConv
// ****************************************************************
CdDedJikoku::CConv::CConv() 
	: m_bNoColon( false )
	, m_eHour( EHour_Zero )
	, m_eSecond( ESecond_Output )
{
} ;

CdDedJikoku::CConv::CConv( 
	bool bNoColon ,
	CdDedJikoku::CConv::EHour	eHour  ,
	CdDedJikoku::CConv::ESecond eSecond ) 
	: m_bNoColon( bNoColon )
	, m_eHour( eHour )
	, m_eSecond( eSecond )
{
}

		
string CdDedJikoku::CConv::encode( const CdDedJikoku& aJikoku )const 
{
	string	strRv ;
	if ( !aJikoku.isNull() ){
		//	��
		if ( m_eHour == EHour_ZeroToNone )
		{
			//char	szLs[16] ;
			//sprintf( szLs , "%d" , aJikoku.getHour() ) ;
			//strRv += szLs ;
			strRv += strprintf( "%d" , aJikoku.getHour() );
		} 
		else if ( m_eHour == EHour_ZeroToSpace )
		{
			//char	szLs[16] ;
			//sprintf( szLs , "%2d" , aJikoku.getHour() ) ;
			//strRv += szLs ;
			strRv += strprintf( "%2d" , aJikoku.getHour() );
		}
		else
		{
			//char	szLs[16] ;
			//sprintf( szLs , "%02d" , aJikoku.getHour() ) ;
			//strRv += szLs ;
			strRv += strprintf( "%02d" , aJikoku.getHour() );
		}
		//	���̂��̃R����
		if ( !m_bNoColon )
		{
			strRv += ":" ;
		}
		//	��
		{
			strRv += strprintf( "%02d" , aJikoku.getMinute()  );
		}
		//	�b
		if ( m_eSecond == ESecond_Output ||
			( m_eSecond == ESecond_NotIfZero && aJikoku.getSecond() != 0 ) )
		{
			//	���̂��̃R����
			if ( !m_bNoColon )
			{
				strRv += ":" ;
			}
			{
				strRv += strprintf( "%02d" , aJikoku.getSecond() );
			}
		}
	}
	return ( strRv ) ;

};




// ****************************************************************
//	CdDedJikoku
// ****************************************************************
const int iSecondsOfADay = 24 * 60 * 60 ;

// --------------------------------
//@name �����֐�
// --------------------------------
int CdDedJikoku::adjustTotalSeconds( int iTotalSeconds ) 
{
	iTotalSeconds %= iSecondsOfADay ;
	if ( iTotalSeconds < 0 ){
		iTotalSeconds = iSecondsOfADay + iTotalSeconds ;
	}
	return ( iTotalSeconds ) ;
}

// ********************************
//	�R���X�g���N�^
// ********************************
CdDedJikoku::CdDedJikoku() : 
		m_iTotalSeconds( INT_MIN )
{
}

CdDedJikoku::CdDedJikoku( int iTotalSeconds ) 
{
	m_iTotalSeconds = adjustTotalSeconds( iTotalSeconds ) ;
}
	
CdDedJikoku::CdDedJikoku( int iHour , int iMinute , int iSecond ) 
{
	m_iTotalSeconds = adjustTotalSeconds( iHour * 60 * 60 + iMinute * 60 + iSecond ) ; 
}
CdDedJikoku::CdDedJikoku( const string& strTime ) 
	: m_iTotalSeconds( INT_MIN ) 
{
	decode( strTime ) ;
}

// ********************************
//	CdDedJikoku
// ********************************
	// ********************************
	//@name ����
	// ********************************
CdDedJikoku& CdDedJikoku::setTotalSeconds( int value ) 
{
	m_iTotalSeconds = adjustTotalSeconds( value ) ;
	return ( *this ) ;
}
	
CdDedJikoku& CdDedJikoku::setTime( int iHour , int iMinute , int iSecond ) 
{
	m_iTotalSeconds = adjustTotalSeconds( iHour * 60 * 60 + iMinute * 60 + iSecond ) ; 
	return ( *this ) ;
}
	
CdDedJikoku& CdDedJikoku::setNull() 
{
	m_iTotalSeconds = INT_MIN ;
	return ( *this ) ;
}
	
	// ********************************
	//@name ����
	// ********************************
int CdDedJikoku::compare( const CdDedJikoku& value )const 
{
	if ( m_iTotalSeconds > value.m_iTotalSeconds ){
		return ( 1 ) ;
	}	else if ( m_iTotalSeconds < value.m_iTotalSeconds ){
		return ( -1 ) ;
	}
	return ( 0 ) ;
}

int CdDedJikoku::compare( 
		const CdDedJikoku& value , 
		const CdDedJikoku& jikokuKitenJikoku )const 
{
	int iThisTotalSeconds = this->m_iTotalSeconds ;
	if ( iThisTotalSeconds < jikokuKitenJikoku.m_iTotalSeconds )
	{
		iThisTotalSeconds += TOTALSECONDS_A_DAY ;
	}

	int iValueTotalSeconds = value.m_iTotalSeconds ;
	if ( iValueTotalSeconds < jikokuKitenJikoku.m_iTotalSeconds )
	{
		iValueTotalSeconds += TOTALSECONDS_A_DAY ;
	}

	if ( iThisTotalSeconds > iValueTotalSeconds ){
		return ( 1 ) ;
	}	else if ( iThisTotalSeconds < iValueTotalSeconds ){
		return ( -1 ) ;
	}
	return ( 0 ) ;
}


CdDedJikoku& CdDedJikoku::addSeconds( int value ) 
{
	if ( !isNull() ){
		m_iTotalSeconds += value ;
		m_iTotalSeconds = adjustTotalSeconds( m_iTotalSeconds ) ;
	}
	return *this ;
}

int CdDedJikoku::subJikoku( const CdDedJikoku& value  )const 
{
	int iRv = 0 ; 
	if ( !isNull() && !value.isNull() ){
		iRv = m_iTotalSeconds - value.m_iTotalSeconds ;

		if ( iRv > 12*60*60 ){
			iRv -= 24*60*60 ;
		}	else if ( iRv < -12*60*60 ){
			iRv += 24*60*60 ;
		} 
	} 
	return ( iRv ) ;
}
	

int CdDedJikoku::decode( const string& value ) 
{
	int iRv = 0 ;

	string	strValue = value ;

	//	�����񂪋󕶎���Ȃ�A�wNull��ԁx�Ƃ��܂��B
	if ( value.empty() ){
		setNull() ;
		return ( 0 ) ;
	}

	//	�R�������Ȃ��ꍇ�͒ǉ�
	{
		string::size_type pos = strValue.find( ":" ) ;
		if ( pos == string::npos ){
			//	�R����������܂���B��������2����؂�ŃR������}�����܂��B
			if ( strValue.size() > 2 ){
				strValue.insert( strValue.size() - 2 , ":" ) ; 
			}
			if ( strValue.size() > 5 ){
				strValue.insert( strValue.size() - 5 , ":" ) ; 
			}
		} 
	}
	//strValue = "13:15:45","9:15"
	
	//	�b���Ȃ��ꍇ�͒ǉ�
	if ( strValue.size() <= 5 ){
		strValue += ":00" ;
	}
	//strValue = "13:15:45","9:15:00"

	//	����10�̈ʂ��Ȃ��ꍇ�͒ǉ�
	if ( strValue.size() <= 7 ){
		strValue = string( "0" ) + strValue ;
	}
	//	����10�̈ʂ��X�y�[�X�̏ꍇ�́A�X�y�[�X�� "0" �ɕύX
	if ( strValue.size() > 0 && strValue[0] == ' ' ){
		strValue[0] = '0' ;
	}

	//strValue = "13:15:45","09:15:00"

	int iHour = -1 ;
	int iMinute = -1 ;
	int iSecond = -1 ;
	if ( strValue.size() == 8 ){
		//	��
		{
			string	strLs = strValue.substr( 0 , 2 ) ;
			if ( strLs.find_first_not_of( "0123456789" ) == string::npos ){
				iHour = atoi( strLs.c_str() ) ;
			}
		}
		//	��
		{
			string	strLs = strValue.substr( 3 , 2 ) ;
			if ( strLs.find_first_not_of( "0123456789" ) == string::npos ){
				iMinute = atoi( strLs.c_str() ) ;
			}
		}
		//	�b
		{
			string	strLs = strValue.substr( 6 , 2 ) ;
			if ( strLs.find_first_not_of( "0123456789" ) == string::npos ){
				iSecond = atoi( strLs.c_str() ) ;
			}
		}
	}	else	{
		iRv = -1 ;	//	���ڐ����s�����Ă��܂��B
		return ( iRv ) ;
	}
	
	if ( 0 <= iHour && iHour < 24 && 
			0 <= iMinute && iMinute < 60 && 
			0 <= iSecond && iSecond < 60 ){
		setTime( iHour , iMinute , iSecond ) ;
	}	else	{
		iRv = -2 ;	//	���E���E�b�̕\�L���s���ł��B
	}
	
	return ( iRv ) ;
}

} //namespace entDed
