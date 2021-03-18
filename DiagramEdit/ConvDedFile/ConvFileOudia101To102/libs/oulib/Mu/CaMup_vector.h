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
//	CaMup_vector.h
// $Id: CaMup_vector.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  Mu_CaMup_vector_h
#define  Mu_CaMup_vector_h
#include <assert.h>
#include "./Mu/Mup.h"


// ****************************************************************
//	CaMup_vector
// ****************************************************************
/**
@brief
   Mu,Mui,Mup �C���^�[�t�F�[�X�ŁASTL�̃����_���A�N�Z�X�R���e�i
�i�����_���A�N�Z�X�����q���T�|�[�g����R���e�i�B
std::vector �� std::deque�j�𑀍삷��A�A�_�v�^�N���X�ł��B
	
   ���̃N���X�̃I�u�W�F�N�g�́A����ΏۂƂȂ��̃R���e�i�Ɗ֘A��
	�����܂��B
 
 	  �R���e�i���̗v�f�̌^�́A�f�t�H���g�R���X�g���N�^�� = ��
	���p�\�ł���K�v������܂��B

 @param ContType
	����Ώۂ̃R���e�i�̌^���w�肵�Ă��������B
	���̌^�́A�i�[����v�f�̌^���e���v���[�g�p�����[�^�Ɏw�肵��
	 std::vector �� std::deque �łȂ��Ă͂Ȃ�܂���B
	�i�[����v�f�̌^���e���v���[�g�p�����[�^�Ɏw�肵��


 �y�g�����z
 
�P�D  �ʏ�́A���炩���ߑ���ΏۃI�u�W�F�N�g�iAdaptee�j
 �i������ STL�����_���A�N�Z�X�R���e�i�istd::vector �� std::deque �j�j
	 �𐶐����Ă��������B

�Q�D  ���̃N���X�̃e���v���[�g�����ɂ́A����ΏۃI�u�W�F�N�g�̌^��
	�w�肵�Ă��������B�܂��A�R���X�g���N�^�ł́A����ΏۃI�u�W�F�N�g
	�ւ̃|�C���^���w�肵�Ă��������B

@code
	std::vector<int>	aVector ;
	CaMup_vector< std::vector<int>	>	aCont( &aVector )  ;
@endcode

	(���Ƃ��� setAdaptee() �ő���Ώۂ�ݒ肷�邱�Ƃ��ł��܂�)�B

 �R�D  ����Ȍ�́A Mup �C���^�[�t�F�[�X�̃��\�b�h�𗘗p���āA
 �R���e�i�𑀍삷�邱�Ƃ��ł��܂��B

 <H4>
	�y�R���e�i���̗v�f�̃C���X�^���X�ɂ��āz
 </H4>
	 �R���e�i�̃T�C�Y��ύX���郁�\�b�h���Ăяo�����ꍇ�A
	�R���e�i���̃C���X�^���X�̍Ċ��蓖�Ă��������܂��B
  �Ċ��蓖�Ă���������ƁAgetpMu()->get() �Ŏ擾����
  �|�C���^�͖����ɂȂ�܂��B


*/
template< class ContType >
class CaMup_vector : public Mup< typename ContType::value_type >
{
public:
	/**
		����Ώۂ̃R���e�i�̌^
	*/
	typedef ContType	cont_type ;


private:	
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		����Ώۂ́ASTL�����_���A�N�Z�X�R���e�i�ł��B
	
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		����Ώۂ́A���̊֘A���L���ȊԂ͐������Ȃ��Ă͂Ȃ�܂���B
	*/
	ContType*	m_pAdaptee ;
	
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	 @param pContType [in]
	   ����Ώۂ́ASTL�����_���A�N�Z�X�R���e�i�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		����Ώۂ́A���̊֘A���L���ȊԂ͐������Ȃ��Ă͂Ȃ�܂���B\n
	*/
	CaMup_vector( ContType* pContType )
		: m_pAdaptee( pContType ){};
	
	/**
	 *   ���̃R���X�g���N�^�́A
	 *	����Ώۂ� STL�����_���A�N�Z�X�R���e�i m_pAdaptee 
	 *	���A���̃N���X�Ő������܂��B
	 */
	CaMup_vector()
		: m_pAdaptee( NULL ){};
	
private:
	/**
		���̃N���X�̃R�s�[�͕s�\�ł��B
	*/
	CaMup_vector( const CaMup_vector& element )
		: m_pAdaptee( NULL )
	{
		assert( false ) ;
	};
	
	/**
		���̃N���X�̃R�s�[�͕s�\�ł��B
	*/
	CaMup_vector& operator=( const CaMup_vector& element )
	{
		*m_pAdaptee = *element.m_pAdaptee ;
		return *this ; 
	};
public:
	virtual ~CaMup_vector()
	{
	};
	
	
public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	/**
	 @return
	 	�R���e�i�Ɋi�[����Ă���v�f�̌���Ԃ��܂��B
	*/
	virtual int	size()const
	{
		if ( m_pAdaptee == NULL )
		{
			return 0 ;
		}
		return (int)m_pAdaptee->size() ; 
	} ;
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���
	 	�v�f��Ԃ��܂��B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
	
		�C���f�N�X���s���ȏꍇ�̓���͖���`�ł��B
	*/
	virtual value_type get( int iIndex )const
	{
		if ( m_pAdaptee == NULL )
		{
			return *( (value_type*)NULL ) ;
		}

		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_pAdaptee->size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_pAdaptee->size() ) )
		{
			return *( (value_type*)NULL ) ; 
		}
		return (*m_pAdaptee)[iIndex] ;
	} ;
	///@}
	
public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f��ǉ����܂��B
	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �ȉ��ł��B
	 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
		-	-1 ;	//	iIndex���s��
	*/
	virtual int insert( const value_type& element , int iIndex = INT_MAX ) 
	{
		assert( 0 <= m_pAdaptee->size() && m_pAdaptee->size() <= INT_MAX ) ; 
		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_pAdaptee->size() ; 
		}
		if ( !( 0 <= iIndex && iIndex <= (int)m_pAdaptee->size() ) )
		{
			return -1 ;	//	iIndex���s��
		}
		m_pAdaptee->insert( m_pAdaptee->begin() + iIndex , element ) ;
		return ( 0 ) ;
	};
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
	 	�v�f���폜���܂��B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
	 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @param iSize [in]
	 	�폜����v�f�̐����w�肵�Ă��������B
	 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
	 @attention
		iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
		-	-1 ;	//	iIndex���s��
	*/
	virtual int erase( int iIndex  , int iSize = 1 ) 
	{
		assert( 0 <= m_pAdaptee->size() && m_pAdaptee->size() <= INT_MAX ) ; 

		if ( iIndex == INT_MAX && iSize == INT_MAX )
		{
			return -1 ;	//	iIndex���s��
		}
		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_pAdaptee->size() - iSize ; 
		}
		if ( iSize == INT_MAX )
		{
			iSize = (int)m_pAdaptee->size() - iIndex ; 
		}
		if ( !( 0 <= iIndex && iIndex + iSize <= (int)m_pAdaptee->size() ) )
		{
			return -1 ;	//	iIndex���s��
		}
		// --------------------------------
		m_pAdaptee->erase( 
			m_pAdaptee->begin() + iIndex , 
			m_pAdaptee->begin() + iIndex + iSize ) ;
		return ( 0 ) ;
	}
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f���㏑�����܂��B
	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
		-	-1 ;	//	iIndex���s��
	*/
	virtual int set( const value_type& element , int iIndex ) 
	{
		if ( iIndex == INT_MAX )
		{
			assert( 0 <= m_pAdaptee->size() && m_pAdaptee->size() <= INT_MAX ) ; 
			iIndex = (int)m_pAdaptee->size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_pAdaptee->size() ) )
		{
			return -1 ;	//	iIndex���s��
		}
		(*m_pAdaptee)[iIndex] = element ;
		return ( 0 ) ;
	}
	///@}
public:
	// ********************************
	///@name	Mup
	// ********************************
	///@{
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���v�f�ւ�
	 	�� const �ȃ|�C���^���擾���邱�Ƃ��ł��܂��B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �ȉ��ł��B
	 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		INT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���v�f�ւ�
	 	�� const �ȃ|�C���^��Ԃ��܂��B
	 	iSize ���͈͊O�̏ꍇ�́A NULL ��Ԃ��܂��B
	*/
	virtual value_type* getp( int iIndex ) 
	{
		if ( m_pAdaptee == NULL )
		{
			return NULL ;
		}

		if ( iIndex == INT_MAX )
		{
			iIndex = (int)m_pAdaptee->size() - 1 ; 
		}
		if ( !( 0 <= iIndex && iIndex < (int)m_pAdaptee->size() ) )
		{
			return NULL ; 
		}
		return &(*m_pAdaptee)[iIndex] ;
	}
	///@}

public:
	// ********************************
	///@name CaMup_vector-�֘A
	// ********************************
	///@{
	ContType*	getAdaptee(){	return m_pAdaptee ;};
	const ContType*	getAdaptee()const{	return m_pAdaptee ;};
	void setAdaptee( ContType*	pAdaptee )
	{
		m_pAdaptee = pAdaptee ;
	};
	
	///@}

};

#endif /*Mu_CaMup_vector_h*/
