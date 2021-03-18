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
//	CdFilenameStr.cpp
// ****************************************************************
*/
#include "Str\CdFilenameStr.h"
#include "Str\CStrCharSizeMb.h"

// ****************************************************************
//	CdFilenameStr
// ****************************************************************

// ********************************
//	�R���X�g���N�^�E�f�X�g���N�^
// ********************************
CdFilenameStr::CdFilenameStr() 
	: m_bIsRelativePath( false ) 
	, m_bIsValidFilename( true ) 
{
}
	//[in]strFilename
	//	�t���p�X���i�h���C�u�E�f�B���N�g���E�t�@�C��������������������j
	//	���w�肵�Ă��������B
	//[in]bIsValidFilename
	//	���̃p�X���A�t�@�C�����̂���`���ł���Ȃ�^�ł��B
	//	���̏ꍇ�́A��ԉE�� '\' �̉E���̓t�@�C�����Ƃ݂Ȃ���܂��B
	//	���̃p�X���A�t�@�C�����̂Ȃ��`���ł���΋U�ł��B
	//	���̏ꍇ�́A��ԉE�� '\' �̉E�����f�B���N�g���Ƃ݂Ȃ��܂��B
CdFilenameStr::
CdFilenameStr( std::string strFilename , bool bIsValidFilename ) 
{
	setFullpathFilename( strFilename, bIsValidFilename ) ;
}


// ********************************
//	CdFilenameStr
// ********************************
	// --------------------------------
	//	����
	// --------------------------------

std::string	CdFilenameStr::Drive() const 
{
	return ( m_strDrive ) ;
}
CdFilenameStr& CdFilenameStr::setDrive( const std::string& ev ) 
{
	m_strDrive = ev ;
	return ( *this ) ;
}
	
CdFilenameStr::ContstrDir	CdFilenameStr::Dirs()const
{
	return ( m_contstrDir ) ;
}

CdFilenameStr& CdFilenameStr::setDirs( const CdFilenameStr::ContstrDir& ev ) 
{
	m_contstrDir = ev ;
	return ( *this ) ;
}
	
	
int CdFilenameStr::DirCount()const 
{
	return ( m_contstrDir.size() ) ;
}

std::string CdFilenameStr::DirAt( int idx )const 
{
	if ( 0 <= idx && idx < m_contstrDir.size() ){
		return ( m_contstrDir.at( idx ) ) ;
	}
	return ( "" ) ;
}
	
CdFilenameStr& 	CdFilenameStr::addDirLast( const std::string& ev ) 
{
	m_contstrDir.push_back( ev ) ;
	return ( *this ) ;
}

CdFilenameStr& 	CdFilenameStr::addDirAt( int index , const std::string& ev ) 
{
	m_contstrDir.insert( m_contstrDir.begin() + index , ev ) ;
	return ( *this ) ;
}
	
CdFilenameStr& 	CdFilenameStr::delDirLast() 
{
	m_contstrDir.pop_back() ;
	return ( *this ) ;
}
CdFilenameStr& 	CdFilenameStr::delDirAt( int index ) 
{
	m_contstrDir.erase( m_contstrDir.begin() + index ) ;
	return ( *this ) ;
}
	
std::string CdFilenameStr::BaseFilename() const 
{
	return ( m_strBaseFilename ) ;
}

CdFilenameStr& CdFilenameStr::setBaseFilename( const std::string& ev ) 
{
	m_strBaseFilename = ev ;
	return ( *this ) ;
}
	
std::string CdFilenameStr::Extension() const 
{
	return ( m_strExtension ) ;
}

CdFilenameStr& CdFilenameStr::setExtension( const std::string& ev ) 
{
	m_strExtension = ev ;
	return ( *this ) ;
}
	
bool CdFilenameStr::IsRelativePath() const 
{
	return ( m_bIsRelativePath ) ;
}

CdFilenameStr& CdFilenameStr::setIsRelativePath( bool ev ) 
{
	m_bIsRelativePath = ev  ;
	return ( *this ) ;
}
	
bool CdFilenameStr::IsValidFilename() const 
{
	return ( m_bIsValidFilename ) ;
}

CdFilenameStr& CdFilenameStr::setIsValidFilename( bool ev ) 
{
	m_bIsValidFilename = ev  ;
	return ( *this ) ;
}
	
std::string CdFilenameStr::	Filename() const 
{
	std::string	strRv = m_strBaseFilename ;
	if ( !m_strExtension.empty() ){
		strRv += "." ;
		strRv += m_strExtension ;
	}
	return ( strRv ) ;
}
	
CdFilenameStr& CdFilenameStr::setFilename( std::string ev ) 
{
	CStrCharSizeMb	ite( ev ) ;
	int	iBidx ;
	for ( iBidx = ite.BidxLast() ; iBidx >  0 ; iBidx = ite.BidxNextChar( iBidx , -1 ) ) {
		if ( ite.CsizeOfBidx( iBidx ) == 1 ){
			if ( ev[iBidx] == '.' ) {
				break ;	//	iExtPeriod = �g���q�̑O��'.'�̃C���f�N�X�ł��B
			}
			if ( ev[iBidx]  == '\\' || ev[iBidx]  == ':' ){
				iBidx = -1 ;
				break ;
					//iBidx = -1�͊g���q���݂���Ȃ��������Ƃ������܂��B
			}
		}
	}
	//iBidx = �g���q�̑O��'.'�̃C���f�N�X�ł��B
	//	�݂���Ȃ����-1�ł�
	if ( iBidx > 0 ){
		m_strBaseFilename = ev.substr( 0 , iBidx ) ; 
		m_strExtension    = ev.substr( iBidx + 1 ) ; 
	}	else	{
		m_strBaseFilename = ev ;
		m_strExtension.erase() ;
	}
	return ( *this ) ;
}
	
// --------------------------------
	
std::string CdFilenameStr::FullpathFilename() const 
{
	std::string	strRv ;

	//�h���C�u
	if ( !m_strDrive.empty() ){
		strRv += m_strDrive ;
		strRv += ':' ;
	}

	if ( !m_bIsRelativePath ){
		strRv += '\\' ;
	}
	
	int idxDir ;
	for ( idxDir = 0 ; idxDir < m_contstrDir.size() ; idxDir ++ ){
		std::string strDir = m_contstrDir[ idxDir ] ;
		strRv += strDir ;
		if ( idxDir < m_contstrDir.size() - 1 || m_bIsValidFilename ){
			strRv += '\\' ;
		}
	}
	if ( m_bIsValidFilename ){
		strRv += Filename() ;
	}
	return ( strRv ) ;
}

CdFilenameStr& CdFilenameStr::setFullpathFilename( std::string ev ) 
{
	// --------------------------------
	//	���ׂč폜
	// --------------------------------
	m_strDrive.erase() ;
	m_contstrDir.clear() ;
	m_bIsRelativePath = true ;
	m_strBaseFilename.erase() ;
	m_strExtension.erase() ;
	// --------------------------------
	//	�h���C�u��
	// --------------------------------
	{
		CStrCharSizeMb	ite( ev )  ;
		int	iBidx ;
		for ( iBidx = 0 ; iBidx < ite.ByteLength() ; iBidx = ite.BidxNextChar( iBidx ) ) {
			if ( ite.CsizeOfBidx( iBidx ) == 1 ){
				if ( ev[ iBidx ] == ':' ) {
					break ;	
					//iBidx = �h���C�u���̂��Ƃ�':'�̃C���f�N�X�ł��B
				}
				if (ev[ iBidx ] == '\\' || ev[ iBidx ] == '.' ){
					iBidx = ite.ByteLength() ;	
					//iBidx = ite.ByteLength()  �́A
					//		�h���C�u�����Ȃ����Ƃ������܂��B
				}
			}
		}
		if ( iBidx < ite.ByteLength()  ){
			m_strDrive = ev.substr( 0 , iBidx ) ; 
			ev = ev.substr( iBidx + 1 ) ; 
		}
	}	
	//ev = �h���C�u�Ǝ���':'���폜�������̂�
	//	�Ȃ�܂����B

	// --------------------------------
	//	�t�@�C����	
	// --------------------------------
	if ( m_bIsValidFilename ){
		CStrCharSizeMb	ite( ev )  ;
		int	iBidx ;
		for ( iBidx = ite.BidxLast() ; iBidx >= 0 ; iBidx = ite.BidxNextChar( iBidx , -1 ) ){
			if ( ite.CsizeOfBidx( iBidx ) == 1 ){
				if ( ev[ iBidx ] == '\\' ){
					break ;	//	iBidx = �t�@�C�����̒��O��'\'��':'�̃C���f�N�X�ł��B
				}
			}
		}
		setFilename( ev.substr( iBidx + 1 ) ) ;
		ev = ev.substr( 0 , iBidx + 1 ) ; 
	}
	//ev = �t�@�C�������폜�������̂�
	//	�Ȃ�܂����B

	// --------------------------------
	//	�擪�Ɩ����� '\' ������
	// --------------------------------
	if ( ev.length() > 0 ){
		CStrCharSizeMb	ite( ev )  ;
		if ( ite.CsizeOfBidx( 0 ) == 1 && ev[0] == '\\' ){
			m_bIsRelativePath = false ;	
			//	�f�B���N�g���̐擪��'\' �Ȃ�A��΃p�X�ł��B
			ev = ev.substr( 1 ) ;
		}		
	}
	//ev=�擪�� '\' ���폜���܂����B

	if ( ev.length() > 0 ){
		CStrCharSizeMb	ite( ev )  ;
		if ( ite.CsizeOfBidx( ite.BidxLast() ) == 1 && ev[ite.BidxLast()] == '\\' ){
			ev = ev.substr( 0 , ite.BidxLast() ) ;
		}		
	}
	//ev=������ '\' ���폜���܂����B

	// --------------------------------
	//	�f�B���N�g�����A '\' �����E��
	//	�؂藣���܂��B
	// --------------------------------
	while( ev.length() > 0 ){
		CStrCharSizeMb	ite( ev )  ;
		int	iBidx ;
		for ( iBidx = 0 ; iBidx < ite.ByteLength() ; iBidx = ite.BidxNextChar( iBidx ) ){
			if ( ite.CsizeOfBidx( iBidx ) == 1 ){
				if ( ev[ iBidx ] == '\\' ) {
					break ;	
					//iBidx = �h���C�u���̂��Ƃ�'\'�̃C���f�N�X�ł��B
				}
			}
		}
		m_contstrDir.push_back( ev.substr( 0 , iBidx ) ) ; 
		ev = ev.substr( iBidx ) ; 
		ite.scan( ev ) ;
		if ( ite.ByteLength() > 0 ){
			if ( ite.CsizeOfBidx( 0 ) == 1 ){
				if ( ev[0] == '\\' ) {
					ev = ev.substr( 1 ) ;
				}
			}
		}
	}	

	return ( *this ) ;
}
CdFilenameStr& CdFilenameStr::setFullpathFilename( std::string ev , 
										bool bIsValidFilename ) 
{
	m_bIsValidFilename = bIsValidFilename ;
	return ( setFullpathFilename( ev ) ) ;
}
	
CdFilenameStr& CdFilenameStr::ChangeDir( const CdFilenameStr& ev ) 
{
	// --------------------------------
	//	�f�B���N�g��
	// --------------------------------
	if ( ev.IsRelativePath() ){
		//	���΃p�X�̏ꍇ�́A�f�B���N�g���͑��Έړ��ƂȂ�܂��B
		int idx ;
		for ( idx = 0 ; idx < ev.DirCount() ; idx ++ ){
			std::string strDir = ev.DirAt( idx ) ;
			if ( strDir == "." ){
			}	else if ( strDir == ".." ){
				if ( m_contstrDir.size() > 0 ){
					m_contstrDir.pop_back() ;
				}
			}	else	{
				m_contstrDir.push_back( strDir ) ;
			}			
		}
	}	else	{
		//	��΃p�X�̏ꍇ�́A�f�B���N�g���͂��������ɂȂ�܂��B
		m_contstrDir.clear() ;
		int idx ;
		for ( idx = 0 ; idx < ev.DirCount() ; idx ++ ){
			m_contstrDir.push_back( ev.DirAt( idx ) ) ;
		}
	}
	// --------------------------------
	//	�h���C�u
	// --------------------------------
	if ( ev.Drive().length() > 0 ){
		setDrive( ev.Drive() ) ;
	}
	// --------------------------------
	//	�t�@�C����
	// --------------------------------
	if ( ev.Filename().length() > 0 ){
		setFilename( ev.Filename() ) ;
	}
	return ( *this ) ;
}

int CdFilenameStr::ChangeToRelativeDir( const CdFilenameStr& ev ) 
{
	int	merrRv = 0 ;

	CdFilenameStr	aFilenameStrBase( ev ) ;
	// --------------------------------
	//	�h���C�u
	// --------------------------------
	if ( merrRv >= 0 ){
		if ( Drive().length() > 0 && ev.Drive().length() > 0 
				&& Drive() != ev.Drive() ){
			//	�o���ʁX�̃h���C�u���w�肳��Ă���ꍇ�́A
			//	���΃p�X�ւ̕ϊ��͂ł��܂���B
			merrRv = -1 ;	//	 �h���C�u���قȂ邽�߁A���΃p�X�ɂ͂ł��܂���B
		}	else	{
			setDrive( "" ) ;
			aFilenameStrBase.setDrive( "" ) ;
		}
	}

	// --------------------------------
	//	�f�B���N�g��
	// --------------------------------
	if ( merrRv >= 0 ){
		if ( IsRelativePath() ){
			merrRv = -2 ;	//	 this�����΃p�X�ł�
		}	else if ( aFilenameStrBase.IsRelativePath() ){
			merrRv = -3 ;	//	 ev�����΃p�X�ł�
		} 
	}
	if ( merrRv >= 0 ){
		//this�𑊑΃p�X�ɕύX���܂��B
		setIsRelativePath( true ) ;
		aFilenameStrBase.setIsRelativePath( true ) ;
		
		while ( DirCount() > 0 
				&& aFilenameStrBase.DirCount() > 0 
				&& DirAt( 0 ) == aFilenameStrBase.DirAt( 0 ) 
				&& DirAt( 0 ) != "." 
				&& DirAt( 0 ) != ".." ){
			delDirAt( 0 ) ;
			aFilenameStrBase.delDirAt( 0 ) ;
		} 
		//	�擪���̋��ʂ̃f�B���N�g�����폜���܂��B

		//	
		int iLi ;
		for ( iLi = 0 ; iLi < aFilenameStrBase.DirCount() ; iLi ++ ){
			addDirAt( 0 , ".." ) ;
		}
	}
	// --------------------------------
	//	�t�@�C����
	// --------------------------------
	if ( merrRv >= 0 ){
		if ( Filename().length() > 0 ){
			if ( aFilenameStrBase.Filename().length() > 0 ){
				setFilename( ev.Filename() ) ;
			}
		}
	}
	return ( merrRv ) ;
};


