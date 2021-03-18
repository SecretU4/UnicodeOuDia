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
//	stringSplit.h
// ****************************************************************
*/
/** @file 
*	@brief
* �y�T�v�z
* 	��������A��؂�ƂȂ镶���ŕ�������֐� splitc ,�������A������ joinc 
*	�����^���Ă��܂��B
*/
#ifndef  stringSplit_h
#define  stringSplit_h

#ifndef  NO_OuLib_NAMESPACE
/** @namespace
*/
namespace OuLib{
#endif /*NO_OuLib_NAMESPACE*/

/**
* 	���������؂蕶���ɕ������āA������̗v�f���i�[�����R���e�i��Ԃ��܂��B
* 	������� STL �E�R���e�i�� STL �̕�����N���X��ΏۂƂ���STL�R���e�i��
* 	�z�肵�Ă��܂��B
* @param StringContainerType
*	STL�������ΏۂƂ���STL�R���e�i���w�肵�Ă��������B
* 	�����Ŏw�肵���^���A�߂�l�̌^�ƂȂ�܂��B	\n
* 	�i��j std::deque<std::string>  std::vector<std::string> �Ȃ�
* @param chSplit [in]
* 	  ��؂蕶�����w�肵�Ă��������B
* @param eStr [in]
* 	  �����̑ΏۂƂȂ镶������w�肵�Ă��������B
* @param bDropEmpty [in]
*	-  �^�Ȃ�A��؂蕶���̊Ԃ��󕶎���̏ꍇ�A
*	���̏ꏊ�ɑΉ�����v�f�i�󕶎���j��
*	�R���e�i�Ɋi�[���܂���B\n
*	-   �U�Ȃ�A��؂蕶���̊Ԃ��󕶎���̏ꍇ�ł��A\n
*	������R���e�i�Ɋi�[���܂��B
*	  ����l�͋U�ł��B
* @return
* 	  ������̕�������i�[�����R���e�i��Ԃ��܂��B
*
* @b �g�p��
* @code
	string	aConnectedString( "PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1" ) ;
	deque<string>	strRv3= splitc< deque<string> >( ';' , aConnectString ) ;
	//	strRv3[0] = "PROTOCOL=TCP"
	//	strRv3[1] = "REMOTEIPADDR=192.168.0.1"
	//	�ƂȂ�܂�
	//
* @endcode
*
* @note
*	eStr ���󕶎���̏ꍇ�A
*	 bDropEmpty ���U�Ȃ�A���̊֐��͋󕶎���P���i�[����
*	�R���e�i��Ԃ��܂�(�󕶎�����v�f�Ƃ݂Ȃ�����ł�)�B
*	 bDropEmpty ���^�Ȃ�A���̊֐��͗v�f�O��
*	�R���e�i��Ԃ��܂�(�󕶎���͎̂Ă邩��ł�)�B
*	
*/
template< class StringContainerType > 
StringContainerType splitc( 
		typename StringContainerType::value_type::const_reference chSplit , 
		typename StringContainerType::const_reference strEv ,
		bool bDropEmpty = false )
{
	StringContainerType	contRv ;
	typedef typename StringContainerType::value_type	StringType ;
	typedef typename StringType::size_type				StringSizeType ;

	StringSizeType	len = strEv.length() ;
	StringSizeType	posItemBegin = 0 ;
	while ( posItemBegin <= len ){
		// --------------------------------
		//	CdItem�͈̔͂�����
		// --------------------------------
		StringSizeType posSplit = 
			strEv.find( chSplit , posItemBegin ) ;
		if ( posSplit == StringType::npos ){
			posSplit = len ;
		}
		//posSplit = ������̏I�[���A�A�C�e����؂蕶�����w���Ă��܂��B 
		//posItemBegin�`posSplit = ����̃A�C�e��

		{
			StringType strItem = 
				strEv.substr( posItemBegin , posSplit - posItemBegin ) ;
			if ( !( strItem.empty() && bDropEmpty ) ){
				contRv.push_back( strItem ) ;
			}
		}
		posItemBegin = posSplit + 1  ;
	}
	return ( contRv ) ;
}

/**
* 	�R���e�i�Ɋi�[����Ă��镶������A��؂蕶����}�����Č������܂��B
* 	������� STL �E�R���e�i�� STL �̕�����N���X��ΏۂƂ���STL�R���e�i��
* 	�z�肵�Ă��܂��B
* @param StringContainerType
* 	STL�������ΏۂƂ���STL�R���e�i���w�肵�Ă��������B
* 	�����Ŏw�肵���^���AcontStr�̌^�ƂȂ�܂��B	\n
* 	�i��j std::deque<std::string>  std::vector<std::string> �Ȃ�
* @param chSplit [in]
* 	��؂蕶�����w�肵�Ă��������B
* @param contStr [in]
* 	������������������i�[�����R���e�i���w�肵�Ă��������B
* @param bDropEmpty [in]
*	-   �^�Ȃ�A�R���e�i�̗v�f�ɋ󕶎��񂪂���ꍇ�A
*	���̗v�f�͖������܂��i�Ή������؂蕶����
*	�����㕶����ɒǉ����܂���j�B
*	-   �U�Ȃ�A�R���e�i�̗v�f�ɋ󕶎��񂪂���ꍇ�A
*	��؂蕶�������������㕶����ɒǉ����܂��B
*	  ����l�͋U�ł��B
* @return
* 	������̕������Ԃ��܂��B
*
* @b �g�p��
* @code
	deque<string>	strRv3 ;
	strRv3.push_back( "PROTOCOL=TCP" ) ;
	strRv3.push_back( "REMOTEIPADDR=192.168.0.1" ) ;
	string	aConnectedString = joinc( ';' , strRv3 ) ;
	//	aConnectedString="PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1" 
	//	�ƂȂ�܂�
	//
* @endcode
*/
template< class StringContainerType > 
typename StringContainerType::value_type joinc(
	typename StringContainerType::value_type::const_reference chSplit , 
	const StringContainerType& contStr  ,
	bool bDropEmpty = false )
{
	typedef typename StringContainerType::value_type	StringType ;
	StringType	strRv ;

	// --------------------------------
	//	���ʕ�����̃T�C�Y���T�Z
	// --------------------------------
	{
		long	lSize = 0 ;
		typename StringContainerType::const_iterator	ite ;
		for ( ite = contStr.begin() ; ite != contStr.end() ; ite ++ ){
			if ( !( ite->empty() && bDropEmpty ) ){
				if ( !strRv.empty() ){
					lSize += 1 ;
				}
				lSize += (long)ite->size() ;
			}
		}
		strRv.reserve( lSize ) ;
	}
	// --------------------------------
	{
		typename StringContainerType::const_iterator	ite ;
		for ( ite = contStr.begin() ; ite != contStr.end() ; ite ++ ){
			if ( !( ite->empty() && bDropEmpty ) ){
				if ( ite != contStr.begin() ){
					strRv += chSplit ;
				}
				strRv += *ite ;
			}
		}
	}
	return ( strRv ) ;
}

#ifndef  NO_OuLib_NAMESPACE
};
#endif /*NO_OuLib_NAMESPACE*/


#endif /*stringSplit_h*/
