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
//	CdConnectedString2.cpp
// ****************************************************************
*/
/** @file */
#include "stdafx.h"
#include "CdConnectedString2.h"
#include <algorithm>
#include <assert.h>

// ****************************************************************
//	OrderIdxSort
// ****************************************************************
/**
 * @brief
 *  m_contiOrderIdx ���Am_pcontItem->strName �̎������Ƀ\�[�g����
 *	�q��ł��B
 *
 *	���̃N���X�́A CdConnectedString2::m_contiOrderIdx ��
 *	�\�[�g����ۂɁA std::sort() �ɓn���֐��I�u�W�F�N�g�ł��B
 */
class OrderIdxSort
{
	/**	�A�C�e����ێ�����R���e�i�ւ̃����N�ł��B */
	const CdConnectedString2::CdItemCont*	m_pcontItem ;
 public:
	OrderIdxSort( const CdConnectedString2::CdItemCont* pcontItem ) 
		: m_pcontItem( pcontItem ) {};
	bool operator()( int value1 , int value2 )
	{
		return ( (*m_pcontItem)[value1].getName() < 
			(*m_pcontItem)[value2].getName() ) ;
	};
};

// ****************************************************************
//	CdConnectedString2::CdItem
// ****************************************************************

// ****************************************************************
//	CdConnectedString2
// ****************************************************************
CdConnectedString2::CdConnectedString2( 
	char chSplit , char chEqualChar , bool bEncodeNoValue ) 
		: m_chSplit( chSplit ) , m_chEqualChar( chEqualChar ) , 
		m_bEncodeNoValue ( bEncodeNoValue ) 
{
};

CdConnectedString2::CdConnectedString2( const std::string& ev ,  
	char chSplit , char chEqualChar , bool bEncodeNoValue ) 
		: m_chSplit( chSplit ) , m_chEqualChar( chEqualChar ) ,
		m_bEncodeNoValue ( bEncodeNoValue ) 
{
	decode( ev ) ;
};

CdConnectedString2::~CdConnectedString2()
{
} 

// ********************************
//@name	�R���e�i����
// ********************************
int CdConnectedString2::size()const
{
	return ( m_contItem.size() ) ; 
} ;
	
const CdConnectedString2::CdItem& CdConnectedString2::at( int idx )const
{
	return ( m_contItem[ idx ] ) ; 
} ;
	
int CdConnectedString2::insert( const CdItem& ev , int idx )
{
		if ( idx == INT_MAX ){
			idx = size() ;
		}
		if ( !( 0 <= idx && idx <= size() ) ){
			return -1 ;	//	�C���f�N�X���͈͊O�ł��B
		}
		m_contItem.insert( m_contItem.begin() + idx , ev ) ;

		//	�R���e�i�̓��e��ύX�����ꍇ�́A�C���f�N�X���j�����܂��B
		m_contiOrderIdx.resize( 0 ) ;

		return ( 0 ) ; 
} ;

int CdConnectedString2::erase( int idx )
{
		if ( idx == INT_MAX ){
			idx = size() - 1 ;
		}
		if ( !( 0 <= idx && idx < size() ) ){
			return -1 ;	//	�C���f�N�X���͈͊O�ł��B
		}
		m_contItem.erase( m_contItem.begin() + idx ) ;

		//	�R���e�i�̓��e��ύX�����ꍇ�́A�C���f�N�X���j�����܂��B
		m_contiOrderIdx.resize( 0 ) ;

		return ( 0 ) ; 
};

int CdConnectedString2::modify(  const CdItem& ev , int idx )
{
		if ( idx == INT_MAX ){
			idx = size() - 1 ;
		}
		if ( !( 0 <= idx && idx < size() ) ){
			return -1 ;
		}
		m_contItem[idx] = ev ;

		//	�R���e�i�̓��e��ύX�����ꍇ�́A�C���f�N�X���j�����܂��B
		m_contiOrderIdx.resize( 0 ) ;

		return ( 0 ) ; 
} ;


int CdConnectedString2::find( std::string strName )const
{
	/*oldcode
	// ----------------------------------------------------------------	
	//	���ʂ̃V�[�P���V�����T�[�`
	// ----------------------------------------------------------------	
		int idx ;
		for ( idx = 0 ; idx < size() && m_contItem[idx].getName() != strName 
								; idx ++ ){}
		if ( idx == size() ){
			idx = -1 ;
		}
		return ( idx ) ;
	*/
	// ----------------------------------------------------------------	
	//	�������\�[�g�����C���f�N�X m_contiOrderIdx ���g����
	//	�Q������
	// ----------------------------------------------------------------	
	// --------------------------------
	//	�C���f�N�X���쐬
	// --------------------------------
	if ( m_contiOrderIdx.size() == 0 && m_contItem.size() > 0 ){
		m_contiOrderIdx.resize( m_contItem.size() ) ;
		for ( int idx = 0 ; idx < (int)m_contiOrderIdx.size() ; idx ++ ){
			m_contiOrderIdx[idx] = idx ;
		}
		std::sort( 
			m_contiOrderIdx.begin() , 
			m_contiOrderIdx.end() ,
			OrderIdxSort( &m_contItem ) ) ;
	}
	// --------------------------------
	//	2������
	// --------------------------------
	int iBegin = 0 ;
	int iEnd = m_contiOrderIdx.size() - 1 ;
	int iCenter = 0 ;
	while ( iBegin <= iEnd ){
		iCenter = ( iBegin + iEnd ) / 2 ;
		std::string strCenter = m_contItem[ m_contiOrderIdx[ iCenter ] ].
			getName() ;
		
		if ( strCenter == strName ){
			break ;
		}	else if ( strCenter < strName ){
			iBegin = iCenter + 1 ;
		}	else	{
			iEnd = iCenter - 1 ;
		}
	}
	if ( iBegin > iEnd ){
		return -1 ;
	}
	return ( m_contiOrderIdx[ iCenter ] ) ;
	// ----------------------------------------------------------------	
};

void CdConnectedString2::clear()
{
		m_contItem.clear() ;

		//	�R���e�i�̓��e��ύX�����ꍇ�́A�C���f�N�X���j�����܂��B
		m_contiOrderIdx.resize( 0 ) ;
};
	
// ********************************
//	CdConnectedString���L
// ********************************
	// ********************************
	//@name	����
	// ********************************
std::string CdConnectedString2::getValue( std::string strName )const
{
		int idx = find( strName ) ;
		if ( idx < 0 ){
			return ( "" ) ;
		}
		return ( at( idx ).getValue() )  ;
}; 
	
	
int CdConnectedString2::setItem( const std::string& strName , 
	const std::string& strValue )
{
		int idx = find( strName ) ;
		if ( idx < 0 ){
			return insert( CdItem( strName ,strValue ) ) ;
		}
		
		CdItem	aCdItem( strName , strValue ) ;
		return ( modify( aCdItem , idx ) ) ;
}; 

int CdConnectedString2::remove( std::string strName )
{
		int idx = find( strName )  ;
		if ( idx >= 0 ){
			erase( idx ) ;

		}
		return ( idx ) ;
};
	

std::string CdConnectedString2::encode()const
{
	std::string	strRv ;
	// --------------------------------
	//	���ʕ�����̃T�C�Y���T�Z
	// --------------------------------
	{
		long	lSize = 0 ;
		int	idx ;
		for ( idx = 0 ; idx < (int)m_contItem.size() ; idx ++ ){
			CdItem aCdItem = m_contItem[ idx ] ;
			lSize += aCdItem.getName().size() ;
			lSize += aCdItem.getValue().size() ;
			lSize += 2 ;
		};
		strRv.reserve( lSize ) ;
	}
	// --------------------------------
	{
		int	idx ;
		for ( idx = 0 ; idx < (int)m_contItem.size() ; idx ++ ){
			CdItem aCdItem = m_contItem[ idx ] ;
			if ( aCdItem.getValue().empty() && !m_bEncodeNoValue ){
				// - false ;	//	encode() �́A�w�l�x�̂Ȃ��w�A�C�e���x��
				//			//	�o�͂��܂���B
				continue ;
			}

			if ( idx != 0 ){
				strRv += m_chSplit ;
			}
			strRv += aCdItem.getName() ;
			if ( !aCdItem.getValue().empty() ){
				strRv += m_chEqualChar ;
				strRv += aCdItem.getValue() ;
			}
		};
	}
	return ( strRv ) ;
		/*
		//	string ��� ������̕����x���Ȃ�܂��B
		//
		std::stringstream	sstrRv ;
		int	idx ;
		for ( idx = 0 ; idx < size() ; idx ++ ){
			if ( idx != 0 ){
				sstrRv << getSplit() ;
			}
			sstrRv << at( idx ).getName() ;
			if ( !at( idx ).getValue().empty() ){
				sstrRv << getEqualChar() ;
				sstrRv << at( idx ).getValue() ;
			}
		};
		return ( sstrRv.str() ) ;
		*/

};

int CdConnectedString2::decode( const std::string&	strEv )
{
		int iRv = 0 ;
		clear() ;

		//	�R���e�i�̓��e��ύX�����ꍇ�́A�C���f�N�X���j�����܂��B
		m_contiOrderIdx.resize( 0 ) ;

		std::string::size_type len = strEv.length() ;
		std::string::size_type posItemBegin = 0 ;
		while ( posItemBegin < len ){
			// --------------------------------
			//	CdItem�͈̔͂�����
			// --------------------------------
			std::string::size_type posSplit = 
				strEv.find( m_chSplit , posItemBegin ) ;
			if ( posSplit == std::string::npos ){
				posSplit = len ;
			}
			//posSplit = ������̏I�[���A�A�C�e����؂蕶�����w���Ă��܂��B 
			//posItemBegin�`posSplit = ����̃A�C�e��

			if ( posItemBegin < posSplit ){
		
				std::string strItem = 
					strEv.substr( posItemBegin , posSplit - posItemBegin ) ;
				// --------------------------------
				//	NAME��VALUE�ɕ������܂��B
				// --------------------------------
				std::string::size_type posEqualChar = 
					strItem.find( m_chEqualChar  ) ;
				if ( posEqualChar == std::string::npos ){
					posEqualChar = strItem.size() ;
				}
				//posEqualChar = strItem �� ������̏I�[���A
				//	�A�C�e����؂蕶�����w���Ă��܂��B 

				if ( posEqualChar == strItem.size() ){
					m_contItem.push_back( CdItem( strItem ) ) ;
				}	else	{
					m_contItem.push_back( 
						CdItem( strItem.substr( 0 , posEqualChar ) , 
							strItem.substr( posEqualChar + 1 ) ) ) ;
				}
				
			}

			posItemBegin = posSplit + 1  ;
		}
		return ( iRv ) ;

};

int CdConnectedString2::setSubitem( const std::string& strSubitemName , 
		const CdConnectedString2& aCdConnectedString ) 
{
	int iRv = 0 ;
	// --------------------------------	
	int idxSubitem ;
	for ( idxSubitem = 0 ; idxSubitem < aCdConnectedString.size() ; idxSubitem ++ ){
		CdConnectedString2::CdItem	aCdItem = aCdConnectedString.at( idxSubitem ) ;
		aCdItem.setName( strSubitemName + aCdItem.getName() ) ;
		
		insert( aCdItem ) ;
	}

	// --------------------------------	
	return ( iRv ) ;
}

	
int CdConnectedString2::getSubitem( const std::string& strSubitemName , 
		CdConnectedString2* pCdConnectedString )const 
{
	int iRv = 0 ;

	/*oldcode
	// ----------------------------------------------------------------	
	//	���ʂ̃V�[�P���V�����T�[�`
	// ----------------------------------------------------------------	
	int idxItem ;
	for ( idxItem = 0 ; idxItem < size() ; idxItem ++ ){
		CdConnectedString2::CdItem	aCdItem = at( idxItem ) ;
		std::string	strName = aCdItem.getName() ;
		if ( strName.compare( 0 , strSubitemName.length() , strSubitemName ) 
				== 0 ){
			strName.erase( 0 , strSubitemName.size() ) ;
			
			pCdConnectedString->insert( 
				CdItem( strName , aCdItem.getValue() ) ) ;
		}
	}

	// --------------------------------	
	return ( iRv ) ;
	*/
	// ----------------------------------------------------------------	
	// ----------------------------------------------------------------	
	//	�������\�[�g�����C���f�N�X m_contiOrderIdx ���g����
	//	�Q������
	// ----------------------------------------------------------------	
	// --------------------------------
	//	�C���f�N�X���쐬
	// --------------------------------
	if ( m_contiOrderIdx.size() == 0 && m_contItem.size() > 0 ){
		m_contiOrderIdx.resize( m_contItem.size() ) ;
		for ( int idx = 0 ; idx < (int)m_contiOrderIdx.size() ; idx ++ ){
			m_contiOrderIdx[idx] = idx ;
		}
		std::sort( 
			m_contiOrderIdx.begin() , 
			m_contiOrderIdx.end() ,
			OrderIdxSort( &m_contItem ) ) ;
	}

	// --------------------------------
	//	�i�������Łj�ŏ��̃T�u�A�C�e��������
	// --------------------------------
	int iOrderBegin = -1 ;
	{
		// --------------------------------
		//	2�������ŁA
		//	�ŏ��̃T�u�A�C�e���́A�������ł̏��ʂ������܂��B
		// --------------------------------
		{
			int iBegin = 0 ;
			int iEnd = m_contiOrderIdx.size() - 1 ;
			int iCenter = 0 ;
			while ( iBegin <= iEnd ){
				iCenter = ( iBegin + iEnd ) / 2 ;
				std::string strCenter = 
					m_contItem[ m_contiOrderIdx[ iCenter ] ].getName() ;
				std::string strCenterBefore ;
				if ( iCenter - 1 >= 0 ){
					strCenterBefore = 
					m_contItem[ m_contiOrderIdx[ iCenter - 1 ] ].getName() ;
				}
				
				int iCenterCompare = 
					strCenter.compare( 0 , strSubitemName.length() , 
						strSubitemName ) ; 
				int iCenterBeforeCompare = 
					strCenterBefore.compare( 0 , strSubitemName.length() , 
						strSubitemName ) ;
				if ( iCenterBeforeCompare < 0 && iCenterCompare == 0 ){
					break ;
				}	else if ( iCenterCompare < 0 ){
					iBegin = iCenter + 1 ;
				}	else if ( iCenterCompare > 0 ){
					iEnd = iCenter - 1 ;
				}	else if ( iCenterBeforeCompare == 0 && 
						iCenterCompare == 0 ){
					iEnd = iCenter - 1 ;
				}	else	{
					assert( 0 ) ;
				}
			}
			if ( iBegin <= iEnd ){
				iOrderBegin = iCenter ;
			}
		}
	}
	//iOrderBegin = �ŏ��̃T�u�A�C�e���́A�������ł̏��ʁB
	//	m_contItem[ m_contiOrderIdx[ iCenter ] ] ���A
	//	�ŏ��̃T�u�A�C�e���ƂȂ�܂��B
	//	�T�u�A�C�e����������Ȃ��ꍇ�́A -1 �ł��B
	
	// --------------------------------
	//	�T�u�A�C�e�������ɑ}��
	// --------------------------------
	if ( iOrderBegin >= 0 ){
		int iOrder ;
		for ( iOrder = iOrderBegin ; iOrder < (int)m_contiOrderIdx.size() ; 
					iOrder ++ ){
				std::string strName = m_contItem[ m_contiOrderIdx[ iOrder ] ].
					getName() ;
				int iCenterCompare = 
					strName.compare( 0 , strSubitemName.length() , 
						strSubitemName ) ; 
				
				if ( iCenterCompare != 0 ){
					break ;
				}

				strName.erase( 0 , strSubitemName.size() ) ;
				pCdConnectedString->insert( CdItem( strName , 
					m_contItem[ m_contiOrderIdx[ iOrder ] ].getValue() ) ) ;
		}
	}	
	return ( iRv ) ;
	// ----------------------------------------------------------------	
}
	
int CdConnectedString2::removeSubitem( const std::string& strSubitemName ) 
{
	int iRv = 0 ;
	// --------------------------------	
	int idxItem ;
	for ( idxItem = 0 ; idxItem < size() ; idxItem ++ ){
		CdConnectedString2::CdItem	aCdItem = at( idxItem ) ;
		std::string	strName = aCdItem.getName() ;
		if ( strName.compare( 0 , strSubitemName.length() , strSubitemName ) 
				== 0 ){
			erase( idxItem ) ;
			idxItem -- ;
			iRv ++ ;
		}
	}

	// --------------------------------	
	return ( iRv ) ;
}
	

