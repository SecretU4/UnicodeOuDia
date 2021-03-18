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
//	CaByteBuffer_string.h
// ****************************************************************
/** @file */
#ifndef  CaByteBuffer_string_h
#define  CaByteBuffer_string_h

#include <string>
#include "..\..\ConvDedFile\interface\IfByteBuffer.h"

namespace ConvFile{

// ****************************************************************
//	CaByteBuffer_string
// ****************************************************************
/**
@brief
  std::string  ��
   IfByteBuffer �C���^�[�t�F�[�X�ő��삷�邽�߂̃A�_�v�^�N���X�ł��B
*/
class CaByteBuffer_string : public IfByteBuffer 
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	std::string*	m_pstring ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CaByteBuffer_string( std::string* pstring )
		: m_pstring( pstring )
	{
	};


public:
	// ********************************
	///@name IfByteBuffer	
	// ********************************
	///@{
	/**
		�o�b�t�@�̃T�C�Y��ύX���܂��B
		���̊֐����Ăяo���ƁA�o�b�t�@���ɂ���܂ŕێ����Ă���
		�f�[�^�͔j������܂��B
	@param iBytes [in] 
		�o�b�t�@�̃o�C�g�����w�肵�Ă��������B
	@return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1;	//	���������m�ۂł��܂���B
	*/
	virtual int size_reset( int iBytes ) 
	{
		m_pstring->resize( iBytes ) ;
		return 0 ;
	};

	/**
	@return 
		�o�b�t�@�̃o�C�g����Ԃ��܂��B
	*/
	virtual int size()const 
	{
		return m_pstring->size() ;
	};

	/**
		�o�b�t�@�̎w��̈ʒu�Ƀf�[�^���������݂܂��B
	@param pData [in]
		�f�[�^�̐擪�A�h���X���w�肵�Ă��������B
	@param iPos [in]
		�o�b�t�@��́A�f�[�^���������ވʒu���A�o�C�g�C���f�N�X�Ŏw�肵�Ă��������B
	@param iBytes [in]
		�������ރo�C�g�����w�肵�Ă��������B
	@return 
		�������񂾃o�C�g����Ԃ��܂��B
		���̐��̓G���[�ł��B
	*/
	virtual int write( const char* pData , int iPos , int iBytes ) 
	{
		if ( iBytes > (int)m_pstring->size() - iPos ) 
		{
			iBytes = m_pstring->size() - iPos ; 
		}
		if ( iBytes < 0 )
		{
			iBytes = 0 ;
		}
		if ( iBytes > 0 )
		{
			for ( int idx = 0 ; idx < iBytes ; idx ++ )
			{
				(*m_pstring)[iPos+idx] = pData[idx] ;
			}
		}
		return iBytes ;
	};


	/**
		�o�b�t�@�̎w��̈ʒu����f�[�^��ǂݍ��݂܂��B
	@param pData [out]
		���̊֐��͂��̃A�h���X�ɁA�ǂݍ��񂾃f�[�^���������݂܂��B
	@param iPos [in]
		�o�b�t�@��́A�f�[�^��ǂݏo���ʒu���A
		�o�C�g�C���f�N�X�Ŏw�肵�Ă��������B
	@param iBytes [in]
		�ǂݍ��ރo�C�g�����w�肵�Ă��������B
	@return 
		�ǂݍ��ނ񂾃o�C�g����Ԃ��܂��B
		���̐��̓G���[�ł��B
	*/
	virtual int read( char* pData , int iPos , int iBytes )const
	{
		if ( iBytes > (int)m_pstring->size() - iPos ) 
		{
			iBytes = m_pstring->size() - iPos ; 
		}
		if ( iBytes < 0 )
		{
			iBytes = 0 ;
		}
		if ( iBytes > 0 )
		{
			memcpy( pData , &m_pstring->c_str()[iPos] , iBytes ) ;
		}
		return iBytes ;
	};

	///@}
};

} //namespace ConvFile

#endif //CaByteBuffer_string_h
