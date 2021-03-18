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
//	CStrCharSizeMb.cpp
// ****************************************************************
*/
#include <mbstring.h>
#include "CStrCharSizeMb.h"



// ****************************************************************
//	CStrCharSizeMb
// ****************************************************************
// ********************************
//	�R���X�g���N�^
// ********************************
CStrCharSizeMb::CStrCharSizeMb() 
{
	m_ariBidx.push_back( 0 ) ;
}
	
CStrCharSizeMb::CStrCharSizeMb( const std::string& ev ) 
{
	scan( ev ) ;
}
	
// ********************************
//	CStrCharSizeMb
// ********************************
CStrCharSizeMb& CStrCharSizeMb::scan( const std::string& ev ) 
{
	m_ariBidx.clear() ;

	int idx ;
	for ( idx = 0 ; idx < ev.length() ; ){
		m_ariBidx.push_back( idx ) ;
		unsigned char	ch = (unsigned char)ev[idx] ;
		int iSize = _mbclen( &ch ) ;
		idx += iSize ;
	}

	m_ariBidx.push_back( idx ) ;
	return *this ;

}
	
int CStrCharSizeMb::ByteLength()const 
{
	return ( m_ariBidx.back() ) ;
}
	
int CStrCharSizeMb::CharLength()const 
{
	return ( m_ariBidx.size() - 1 ) ;
}
	
int CStrCharSizeMb::CidxOfBidx( int iBidx , int* piOffset )const 
{
	if ( piOffset != NULL ){
		*piOffset = 0 ;
	}
	
	
	if ( iBidx < 0 ){
		return ( -1 ) ;
	}	else if ( iBidx >= ByteLength() ){
		return ( CharLength() );
	}
	
	//�V�[�P���V�����T�[�`
	//{
	//	int	idx  ;
	//	for ( idx = 0 ; idx < m_ariBidx.size() ; idx ++ ){
	//		if ( m_ariBidx[idx] == iBidx ){
	//			return ( idx ) ; 
	//		}
	//	}
	//}

	//�o�C�i���T�[�`
	int idx = -1 ; 
	int idxBegin = 0 ; 
	int idxEnd = m_ariBidx.size() - 1 ;
	while ( idxBegin <= idxEnd ){
		idx = ( idxBegin + idxEnd ) / 2 ;
		if ( m_ariBidx[idx] == iBidx ){
			break ;
		}	else if ( iBidx < m_ariBidx[idx] ){
			idxEnd = idx - 1 ;
		}	else	{
			idxBegin = idx + 1 ;
		}
	}
	if ( !( idxBegin <= idxEnd ) ){
		//	�o�C�i���T�[�`�Ō��ʂ�������Ȃ������ꍇ�A
		//	idxEnd�́A�����Ώۂ�菬�����A�Ŋ�̒l�̃C���f�N�X���w���Ă��܂��B
		idx = idxEnd ;	
	}
	if ( piOffset != NULL ){
		*piOffset = iBidx - m_ariBidx[idx] ;
	}

	return ( idx ) ;
}
int CStrCharSizeMb::BidxOfCidx( int iCidx )const 
{
	if ( iCidx < 0 ){
		return ( -1 ) ;
	}	else if ( iCidx >= CharLength() ){
		return ( ByteLength() );
	}
	
	return ( m_ariBidx[ iCidx ] ) ;
}
	
int CStrCharSizeMb::CsizeOfBidx( int iBidx )const 
{
	if ( iBidx < 0 ){
		//iBidx �����̐�: 0��Ԃ��܂��B
		return ( 0 ) ;	
	}	else if ( iBidx >= ByteLength() ){
		//iBidx ��ByteLength() �ȏ� : 0��Ԃ��܂��B
		return ( 0 );
	}
	
	int iOffset = 0 ;
	int iCidx = CidxOfBidx( iBidx , &iOffset ) ;
	if ( iOffset != 0 ){
		//iBidx �������̂Q�o�C�g��: 0��Ԃ��܂��B
		return ( 0 ) ;
	}
	return ( CsizeOfCidx( iCidx ) ) ;
}

int CStrCharSizeMb::CsizeOfCidx( int iCidx )const 
{
	if ( iCidx < 0 ){
		return ( 0 ) ;	//	iCidx �����̐�/CharLength() �ȏ� : 0��Ԃ��܂��B
	}	else if ( iCidx >= CharLength() ){
		return ( 0 );	//	iCidx �����̐�/CharLength() �ȏ� : 0��Ԃ��܂��B
	}
	
	return ( m_ariBidx[ iCidx + 1 ] - m_ariBidx[ iCidx ] ) ;
}
	
int CStrCharSizeMb::BidxNextChar( int iBidx , int iCharOffset )const 
{
	int iCidx = CidxOfBidx( iBidx ) ;
	//if ( iCidx == -2 ){
	//	return ( -2 ) ;	//	iBidx �������̂Q�o�C�g�ڂ��w���Ă��� : -2 ��Ԃ��܂��B
	//}
	
	iCidx += iCharOffset ;
	return ( BidxOfCidx( iCidx ) ) ;
	
}

int CStrCharSizeMb::CidxLast()const 
{
	return ( CharLength() - 1 ) ;
}
	
int CStrCharSizeMb::BidxLast()const 
{
	return ( BidxOfCidx( CharLength() - 1 ) ) ;
}



static const char* const hantozen_table[] = {
	"��" , "�K" , 
	"��" , "�M" ,
	"��" , "�O" ,
	"��" , "�Q" ,
	"��" , "�S" ,
	"��" , "�U" ,
	"��" , "�W" ,
	"��" , "�Y" , 
	"��" , "�[" ,
	"��" , "�]" ,
	"��" , "�_" ,
	"��" , "�a" ,
	"��" , "�d" ,
	"��" , "�f" ,
	"��" , "�h" ,
	"��" , "�o" ,
	"��" , "�p" ,
	"��" , "�s" ,
	"��" , "�u" ,
	"��" , "�v" , 
	"��" , "�x" ,
	"��" , "�y" ,
	"��" , "�{" ,
	"��" , "�|" ,
};

std::string CStrCharSizeMb::strToSingleByte( const std::string& strEv , 
						int* piResult ) 
{
	int iResult = 0 ;
	std::string	strRv ;
	bool bDakutenChange = true ;
	
	// --------------------------------
	CStrCharSizeMb	aCStrCharSizeMb( strEv ) ;
	int iBidx ;
	for ( iBidx = 0 ; iBidx < aCStrCharSizeMb.ByteLength() ; 
				iBidx = aCStrCharSizeMb.BidxNextChar( iBidx ) ){
		if ( aCStrCharSizeMb.CsizeOfBidx( iBidx ) == 1 ){
			strRv += strEv[iBidx] ;
		}	else	{
			unsigned short ch = 0 ;
			ch |= (unsigned char)strEv[iBidx] ;
			ch <<= 8 ;
			ch |= (unsigned char)strEv[iBidx+1] ;
			
			//	�ϊ��\�ɂ��ϊ�
			int idxTbl ; 
			for ( idxTbl = 1 ; 
				idxTbl < sizeof(hantozen_table) / sizeof(hantozen_table[0]) ;
				idxTbl += 2 ){
				unsigned short chTbl = 0 ;
				chTbl |= (unsigned char)hantozen_table[idxTbl][0] ;
				chTbl <<= 8 ;
				chTbl |= (unsigned char)hantozen_table[idxTbl][1] ;

				if ( ch == chTbl ){
					strRv += hantozen_table[idxTbl - 1 ] ;
					break ;
				}
			}
			if ( idxTbl < sizeof(hantozen_table) / sizeof(hantozen_table[0]) ){
				continue ;
			}
			
			// --------------------------------
			//	�֐��ɂ��ϊ�
			unsigned short ch2 = _mbctombb( ch ) ;
			if ( ch == ch2 ){
				strRv += (char)( ( ch2 >> 8 ) & 0xff ) ;
				strRv += (char)( ( ch2 >> 0 ) & 0xff ) ;
				iResult = -1 ;
			}	else	{
				strRv += (char)( ( ch2 >> 0 ) & 0xff ) ;
				if ( iResult == 0 ){
					iResult = 1 ;
				}
			}
		}
	}
	
	
	// --------------------------------
	if ( piResult != NULL ){
		*piResult = iResult ;
	}
	return ( strRv ) ;
}

std::string CStrCharSizeMb::strToDoubleByte( const std::string& strEv , 
						int* piResult ) 
{
	int iResult = 0 ;
	std::string	strRv ;
	bool bDakutenChange = true ;
	
	// --------------------------------
	CStrCharSizeMb	aCStrCharSizeMb( strEv ) ;
	int iBidx ;
	for ( iBidx = 0 ; iBidx < aCStrCharSizeMb.ByteLength() ; 
				iBidx = aCStrCharSizeMb.BidxNextChar( iBidx ) ){
		if ( aCStrCharSizeMb.CsizeOfBidx( iBidx ) == 2 ){
			strRv += strEv[iBidx] ;
			strRv += strEv[iBidx+1] ;
		}	else	{
			unsigned short ch = (unsigned char)strEv[iBidx];
			
			//	�ϊ��\�ɂ��ϊ�
			if ( bDakutenChange ){
				char b0 = strEv[iBidx] ;
				char b1 = 0 ;
				if ( iBidx < aCStrCharSizeMb.ByteLength() - 1 ){
					b1 = strEv[iBidx+1] ;
				}
				int idxTbl ; 
				for ( idxTbl = 0 ; 
					idxTbl < sizeof(hantozen_table)/sizeof(hantozen_table[0]) ;
					idxTbl += 2 ){
					if ( b0 == hantozen_table[idxTbl][0] && 
							b1 == hantozen_table[idxTbl][1] ){
						strRv += hantozen_table[idxTbl+1][0] ; 
						strRv += hantozen_table[idxTbl+1][1] ;
						if ( b1 != '\0' ){
							//	�ϊ�����������Q�����g�������߁A
							//	iBidx �͂Q�����ڂɈڂ��Ă����܂��B
							iBidx ++ ;
						}
						break ;
					}
				}
				if ( idxTbl<sizeof(hantozen_table)/sizeof(hantozen_table[0] )){
					if ( iResult == 0 ){
						iResult = 1 ;
					}
					continue ;
				}
			}
			// --------------------------------
			//	�֐��ɂ��ϊ�
			unsigned short ch2 = _mbbtombc( ch ) ;
			if ( ch == ch2 ){
				strRv += (char)( ( ch2 >> 0 ) & 0xff ) ;
				iResult = -1 ;
			}	else	{
				strRv += (char)( ( ch2 >> 8 ) & 0xff ) ;
				strRv += (char)( ( ch2 >> 0 ) & 0xff ) ;
				if ( iResult == 0 ){
					iResult = 1 ;
				}
			}
		}
	}
	
	
	// --------------------------------
	if ( piResult != NULL ){
		*piResult = iResult ;
	}
	return ( strRv ) ;
}
