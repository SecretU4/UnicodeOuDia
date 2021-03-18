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
//	CdConnectedString.h
// ****************************************************************
*/
/** @file */
#ifndef  CdConnectedString_h
#define  CdConnectedString_h

#include <string>
#include <deque>

// ****************************************************************
//	CdConnectedString
// ****************************************************************
/**
* @brief
* �y�T�v�z
* 	�P�o�C�g�̋�؂蕶���i�f�t�H���g��';'�j�ŋ�؂�ꂽ
* 	<���ږ�>=<�l>�̌`���́w�A��������x��ێ�����P���f�[�^�N���X�ł��B
* 	
* 		�i��j"PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1;REMOTEPORT=8001"
* 	
* 	���̃N���X�ł́A��L�`���̕�����S��
* 		�i��j"PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1;REMOTEPORT=8001"
* 	���A�w�A��������x�B
* 	��؂蕶���ŋ�؂�ꂽ������P��
* 		�i��j"PROTOCOL=TCP"
* 			"REMOTEIPADDR=192.168.0.1"
* 			"REMOTEPORT=8001"
* 	���w�A�C�e���x
* 	�A�C�e������=�̍���
* 		�i��j"PROTOCOL"
* 			"REMOTEIPADDR"
* 			"REMOTEPORT"
* 	���w���ږ��x
* 	�A�C�e������=�̉E��
* 		�i��j"TCP"
* 			"192.168.0.1"
* 			"8001"
* 	���w�l�x�ƌĂ�ł��܂��B
* 	
* 	���̃N���X�́A�A����������̃A�C�e����ҏW����@�\��A
* 	�A�C�e�����̍��ږ��E�l��ҏW����@�\�������Ă��܂��B
* 	
*/
class CdConnectedString 
{
// ********************************
//	�C���i�[��`
// ********************************
 public:
	
	/**
	* @brief
	*	�A�C�e���P�̓��e��\���\���̂ł��B
	*/
	struct ITEM
	{
		ITEM( const std::string& strName = "" , 
			const std::string& strValue = "" )
			: m_strName( strName ) , m_strValue( strValue )	{};
		
		/**
		* 	�A�C�e�����́A���ږ��B
		*	�l�������Ȃ��ꍇ�́A�A�C�e��������S�̂����ږ��ɂȂ�܂��B
		*/
		std::string	m_strName ;

		/**
		*	�A�C�e�����́A�l�B
		*	�l�������Ȃ��ꍇ�́A�󕶎���ɂȂ�܂��B
		*/
		std::string	m_strValue ;
	};

// ********************************
//	����
// ********************************
 private:
	///	�A�C�e���Ԃ̋�؂蕶���ł��B�f�t�H���g��';'�ł�
	char		m_chSplit ;

	
	///	���ڂƒl�̊Ԃ̋�؂蕶���ł��B�f�t�H���g��'='�ł�
	char		m_chEqualChar ;

// --------------------------------
//	�����f�[�^
// --------------------------------
 private:
	///	�A�C�e����ێ�����R���e�i�̌^��\���܂��B
	typedef std::deque<ITEM>	ITEMCont ;
	
	///	�A�C�e����ێ�����R���e�i�ł��B
	ITEMCont	m_contItem ;



// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	* @param chSplit [in]
	* 	�A�C�e���Ԃ̋�؂蕶�����w�肵�Ă��������B
	* @param chEqualChar [in]
	* 	���ڂƒl�̊Ԃ̋�؂蕶�����w�肵�Ă��������B
	*/
	CdConnectedString( char chSplit = ';' , char chEqualChar = '=' ) 
		: m_chSplit( chSplit ) , m_chEqualChar( chEqualChar ){};
	
	/**
	* @param ev [in]
	* 	�A����������w�肵�Ă��������B
	* @param chSplit [in]
	* 	��؂蕶�����w�肵�Ă��������B
	* @param chEqualChar [in]
	* 	���ڂƒl�̊Ԃ̋�؂蕶�����w�肵�Ă��������B
	*/
	CdConnectedString( const std::string& ev ,  char chSplit = ';' , 
										char chEqualChar = '=' ) 
		: m_chSplit( chSplit ) , m_chEqualChar( chEqualChar )
	{
		decode( ev ) ;
	};
	
	virtual ~CdConnectedString(){} ;

// ********************************
//	�R���e�i����
// ********************************
 public:
	/**
	* @return
	* 	�A�C�e���̐���Ԃ��܂��B
	*/
	int size()const{	return ( m_contItem.size() ) ; } ;
	
	/**
	* 	�w��̈ʒu�ɂ���A�C�e�����Q�Ƃ��܂��B
	* @param idx [in]
	* 	�O�ȏ�size()�����̃C���f�N�X���w�肵�Ă��������B
	* @return
	* 	�A�C�e����Ԃ��܂��B
	*/
	ITEM at( int idx )const{	return ( m_contItem[ idx ] ) ; } ;
	
	
	/**
	* 	�w��̈ʒu�ɐV�����A�C�e����}�����܂��B
	* @param idx [in]
	* 	�O�ȏ�size()�ȉ��̃C���f�N�X���w�肵�Ă��������B
	* 	-1�Ȃ�A�����ɒǉ����܂��B
	* @param ev [in]
	* 	�}������A�C�e�����w�肵�Ă��������B
	* @return
	* 	����������0�ȏ�A���s�����畉�̐��ł�
	*/
	int insert( int idx , const ITEM& ev ){
		if ( idx < 0 ){
			idx = size() ;
		}
		if ( !( 0 <= idx && idx <= size() ) ){
			return -1 ;
		}
		m_contItem.insert( m_contItem.begin() + idx , ev ) ;
		return ( 0 ) ; 
	} ;

	/**
	* 	�w��̈ʒu����A�C�e�����������܂��B
	* @param idx [in]
	* 	�O�ȏ�size()�����̃C���f�N�X���w�肵�Ă��������B
	* @return
	* 	����������0�ȏ�A���s�����畉�̐��ł�
	*/
	int erase( int idx ){
		if ( !( 0 <= idx && idx < size() ) ){
			return -1 ;
		}
		m_contItem.erase( m_contItem.begin() + idx ) ;
		return ( 0 ) ; 
	};
	
	/**
	* 	�w��̍��ږ������A�C�e���̈ʒu�𒲂ׂ܂�
	* @param strName [in]
	* 	���ږ����w�肵�Ă��������B
	* @return
	* 	����������0�ȏ�̃C���f�N�X�A������Ȃ����-1�ł�
	*/
	int find( std::string strName )const{
		int idx ;
		for ( idx = 0 ; idx < size() && at( idx ).m_strName != strName 
								; idx ++ ){}
		if ( idx == size() ){
			idx = -1 ;
		}
		return ( idx ) ;
	};

	/**
	* 	�w��̍��ږ������A�C�e�����폜���܂�
	* @param strName [in]
	* 	���ږ����w�肵�Ă��������B
	* @return
	* 	����������A�폜�����A�C�e���̌��X�������ʒu�̃C���f�N�X�A
	* 	������Ȃ����-1�ł�
	*/
	int remove( std::string strName ){
		int idx = find( strName )  ;
		if ( idx >= 0 ){
			erase( idx ) ;
		}
		return ( idx ) ;
	};
	
	/**
	*	���ׂẴA�C�e����j�����܂��B
	*/
	void clear(){
		m_contItem.clear() ;
	};
	
	/**
	* 	�w��̍��ږ������A�C�e���̒l��Ԃ��܂��B
	* @param strName [in]
	* 	���ږ����w�肵�Ă��������B
	* @return
	* 	����������A�l��Ԃ��܂��B
	* 	���ڂ����݂��Ȃ��ꍇ�́A�󕶎����Ԃ��܂��B
	*/
	std::string getValue( std::string strName )const{
		int idx = find( strName ) ;
		if ( idx < 0 ){
			return ( "" ) ;
		}
		return ( at( idx ).m_strValue )  ;
	}; 
	
	
	/**
	* 	�w��̍��ږ������A�C�e���̒l��ύX���܂��B
	* 	���̂Ƃ��A�w��̍��ږ������A�C�e�������݂��Ȃ���΁A
	* 	�V�����A�C�e����ǉ�������ŁA���ږ��E�l���Z�b�g���܂��B
	* @param strName [in]
	* 	���ږ����w�肵�Ă��������B
	* @param strValue [in]
	* 	�l���w�肵�Ă��������B
	* @return
	* 	����������0�ȏ�A���s�����畉�̐��ł�
	*/
	int setItem( const std::string& strName , const std::string& strValue ){
		int idx = remove( strName ) ;
		return ( insert( idx , ITEM( strName ,strValue ) ) ) ;
	}; 

// ********************************
//	CdConnectedString���L
// ********************************
 public:
	// ********************************
	//	����
	// ********************************
	char getSplit()const {	return ( m_chSplit ) ; } ;
	CdConnectedString& setSplit( char chSplit ){
		m_chSplit = chSplit ; return ( *this ) ;} ;

	char getEqualChar()const{	return ( m_chEqualChar ) ; } ;
	CdConnectedString& setEqualChar( char ev ){	
		m_chEqualChar = ev ; return ( *this ) ;} ;

	/**
	* @return
	* 	���̃I�u�W�F�N�g���ێ����Ă���A�C�e���Ƌ�؂蕶�������ƂɁA
	* 	�A����������쐬���A�����Ԃ��܂��B
	*/
	std::string encode()const{
		std::string	strRv ;
		int	idx ;
		for ( idx = 0 ; idx < size() ; idx ++ ){
			if ( idx != 0 ){
				strRv += getSplit() ;
			}
			strRv += at( idx ).m_strName ;
			if ( !at( idx ).m_strValue.empty() ){
				strRv += getEqualChar() ;
				strRv += at( idx ).m_strValue ;
			}
		};
		return ( strRv ) ;
	};

	/**
	* 	�w��̘A����������A���̃I�u�W�F�N�g�Ɋi�[���܂��B
	* @param strEv [in]
	* 	�A����������w�肵�Ă��������B
	* @return
	* 	����������0�ȏ�A���s�����畉�̐��ł�
	*/
	int decode( const std::string&	strEv ){
		int iRv = 0 ;
		clear() ;
		std::string	strLeft = strEv ;
		
		while ( !strLeft.empty() ){
			// --------------------------------
			//	����ITEM��؂�o���܂��B
			// --------------------------------
			std::string	strItem ;
			{

				int	idx ;
				for ( idx = 0 ; 
					idx < (int)strLeft.size() && strLeft[idx] != getSplit() ; 
					idx++ ){}
				
				//idx = ������̏I�[���A�A�C�e����؂蕶�����w���Ă��܂��B

				if ( idx == strLeft.size() ){
					strItem = strLeft ; 
					strLeft = "" ;
				}	else	{
					strItem = strLeft.substr( 0 , idx ) ;
					strLeft.erase( 0 , idx + 1 ) ;
				}
				
				//strItem = ����ǂ̃A�C�e��
				//strLeft = ����ǂ̃A�C�e���i�ƁA���̒���̋�؂蕶���j��
				//	�폜���܂����B
			}
			if ( strItem.empty() ){
				continue ;
			}
			// --------------------------------
			//	NAME��VALUE�ɕ������܂��B
			// --------------------------------
			{
				ITEM	aItem ;
			
				int	idx ;
				for ( idx = 0 ; 
					idx < (int)strItem.size() && strItem[idx] != getEqualChar() ; 
					idx++ ){}
				
				//idx = strItem �̕�����̏I�[���A'='���w���Ă��܂��B

				if ( idx == strItem.size() ){
					aItem.m_strName = strItem ;
				}	else	{
					aItem.m_strName = strItem.substr( 0 , idx ) ;
					aItem.m_strValue = strItem.substr( idx + 1 )  ;
				};
				
				insert( -1 , aItem ) ;
			}
		}
		return ( iRv ) ;
	};
// ********************************
//	���Z�q
// ********************************
 public:
	/** encode() �Ɠ����ł� */
	operator std::string()const {	return encode() ;	};
};




#endif /*CdConnectedString_h*/

