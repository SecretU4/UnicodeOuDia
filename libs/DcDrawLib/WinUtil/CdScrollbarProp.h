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
//	CdScrollbarProp.h
// $Id: CdScrollbarProp.h 327 2016-06-12 04:20:29Z okm $
// ****************************************************************
*/
/** @file */
#ifndef WinUtil_CdScrollbarProp_h
#define WinUtil_CdScrollbarProp_h


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


namespace DcDrawLib{ namespace WinUtil{

// ****************************************************************
//	CdScrollbarProp
// ****************************************************************
/**
@brief
	�P���f�[�^�N���X�ł��B
	�X�N���[���o�[������ێ����܂��B

	���̃N���X�́A�L���Ȓl�������Ȃ� NULL ��Ԃ������Ƃ��ł��܂��B

	this �͑����ɑ΂��āA��Ɉȉ��̕␳���s���܂��B

	- m_iMax >= m_iMin 
	- m_iPage <= m_iMax - m_iMin + 1  
	- m_iPage >= 1 
	- m_iPos <= m_iMax 
	- m_iPos <= m_iMax - m_iPage + 1   (m_bAdjustPosByPage=true�̏ꍇ�̂�)
	- m_iPos >= m_iMin


*/
class CdScrollbarProp
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�X�N���[���o�[�̍ŏ��̈ʒu�B
		NULL��ԂɂȂ����Ƃ��ɂ́A���̒l�� 0 �ɏ���������܂��B
	*/
	int m_iMin ;
	/**
		�X�N���[���o�[�̍ő�̈ʒu�B
		NULL��ԂɂȂ����Ƃ��ɂ́A���̒l�� 0 �ɏ���������܂��B
	*/
	int m_iMax ;
	/**
		���ݕ\�����̃y�[�W���B
		NULL��ԂɂȂ����Ƃ��ɂ́A���̒l�� 1 �ɏ���������܂��B

		m_iMin = 0 �� m_iMax �� 5 �� m_iPage �� 1 �̏ꍇ�́A
		�X�N���[���o�[�̈ʒu�� 0����5�܂ł̒l���Ƃ�܂��B

		m_iMin = 0 �� m_iMax �� 5 �� m_iPage �� 2 �̏ꍇ�́A
		�X�N���[���o�[�̈ʒu�� 0����4�܂ł̒l���Ƃ�܂��B

		m_iMin = 0 �� m_iMax �� 5 �� m_iPage �� 6 �̏ꍇ�́A
		�X�N���[���o�[�͔�\��(�܂���Disable)�ƂȂ�܂��B
	*/
	int m_iPage ;
	/**
		�X�N���[���o�[�̈ʒu�B
		NULL��ԂɂȂ����Ƃ��ɂ́A���̒l�� 0 �ɏ���������܂��B
	*/
    int m_iPos; 

	/**
		this ��NULL��ԂȂ� true �ł��B
	*/
	bool m_bIsNull ;

	/**
		- true: �X�N���[���o�[�̎g�p���s�v�ȏꍇ�́A�X�N���[���o�[�𖳌��ɂ��܂��B
		- false:(����l)�X�N���[���o�[�̑��삪�s�v�ȏꍇ�́A�X�N���[���o�[���\���ɂ��܂��B

		���̒l�́A setNull() �ł��ω����܂���B
	@attention
		����ɑ�������t���O SIF_DISABLENOSCROLL ��
		�X�N���[���o�[�s�v�Ȉʒu�����w�肵��
		SetScrollInfo() ���Ăяo���ƁA�X�N���[���o�[��������
		�Ȃ�܂��B
		�������A���̌��  SIF_DISABLENOSCROLL �����E
		�X�N���[���o�[�K�v�Ȉʒu�����w�肵��
		SetScrollInfo() ���Ăяo���Ă��A
		�X�N���[���o�[�͖�������L���ɂ͂Ȃ�܂���B
		�����������邽�߂ɂ́A
		@code
		EnableScrollBar( (SB_HORZ or SB_VERT), ESB_ENABLE_BOTH ) ;
		@endcode
		���Ăяo���Ă���A
		SetScrollInfo()���Ăяo���Ă��������B
	*/
	bool m_bDisableNoScroll ;

	/**
		�y�[�W�����l���������K�����s�����ۂ��������܂��B

		�y�[�W�����l���������K�����́A�ȉ����w���܂��B

		- m_iPos <= m_iMax - m_iPage + 1  

		���̒l�́A setNull() �ł��ω����܂���B
		����l�� true �ł��B
	*/
	bool m_bAdjustPosByPage ;


	///@}
protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		������␳���܂��B
	*/
	void adjustProp() 
	{
		if ( !m_bIsNull )
		{
			if ( !( m_iMax >= m_iMin ) )
			{
				m_iMax = m_iMin ;
			}
			if ( !( m_iPage <= m_iMax - m_iMin + 1 ) )
			{
				m_iPage = m_iMax - m_iMin + 1 ;
			}
			if ( !( m_iPage >= 1 ) )
			{
				m_iPage = 1 ;
			}

			if ( !( m_iPos <= m_iMax ) )
			{
				m_iPos = m_iMax ;
			}

			if ( m_bAdjustPosByPage )
			{
				if ( !( m_iPos <= m_iMax - m_iPage + 1 ) )
				{
					m_iPos = m_iMax - m_iPage + 1 ;
				}
			}
			if ( !( m_iPos >= m_iMin ) )
			{
				m_iPos = m_iMin ;
			}
		}
	};
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		this ��NULL��Ԃɏ��������܂��B
	*/
	CdScrollbarProp()
		: m_iMin( 0 ) 
		, m_iMax( 0 ) 
		, m_iPage( 1 ) 
		, m_iPos( 0 )
		, m_bIsNull( true ) 
		, m_bDisableNoScroll( false ) 
		, m_bAdjustPosByPage( true ) 
	{} ;
	CdScrollbarProp(
		int iMin , 
		int iMax , 
		int iPage , 
		int iPos )
		: m_iMin( iMin ) 
		, m_iMax( iMax ) 
		, m_iPage( iPage ) 
		, m_iPos( iPos )
		, m_bIsNull( false ) 
		, m_bDisableNoScroll( false ) 
		, m_bAdjustPosByPage( true ) 
	{
		adjustProp() ;
	} ;
	CdScrollbarProp(
		int iMin , 
		int iMax , 
		int iPage , 
		int iPos , 
		bool bDisableNoScroll ,
		bool bAdjustPosByPage )
		: m_iMin( iMin ) 
		, m_iMax( iMax ) 
		, m_iPage( iPage ) 
		, m_iPos( iPos )
		, m_bIsNull( false ) 
		, m_bDisableNoScroll( bDisableNoScroll ) 
		, m_bAdjustPosByPage( bAdjustPosByPage ) 
	{
		adjustProp() ;
	} ;

public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	int getMin()const{	return m_iMin ;};
	int getMax()const{	return m_iMax ;};
	void setMinMax( int iMin , int iMax )
	{
		m_bIsNull = false ;
		m_iMin = iMin ;
		m_iMax = iMax ;
		adjustProp() ;
	};
	int getPage()const{	return m_iPage ;};
	void setPage( int value )
	{
		m_bIsNull = false ; 
		m_iPage = value ;
		adjustProp() ;
	};
	int getPos()const{	return m_iPos;}; 
	void setPos( int value )
	{
		m_bIsNull = false ; 
		m_iPos = value ;
		adjustProp() ;
	}; 

	bool getDisableNoScroll()const{	return m_bDisableNoScroll;};
	void setDisableNoScroll( bool value )
	{
		m_bIsNull = false ; 
		m_bDisableNoScroll = value ;
	}

	bool getAdjustPosByPage()const{	return m_bAdjustPosByPage ;};
	void setAdjustPosByPage( bool value )
	{
		m_bAdjustPosByPage = value ;
		adjustProp() ;
	}
	/** 
	@return
		-true : this �� NULL �B
		-false: this �� NULL�łȂ� �B
	*/
	bool isNull()const
	{
		return ( m_bIsNull ) ;
	};
	void setNull()
	{
		m_iMin = 0 ;
		m_iMax = 0 ;
		m_iPage = 1 ;
		m_iPos = 0 ;
		m_bIsNull = true ;
	};
	/**
		���ׂĂ̑�����ݒ肵�Athis �� ��NULL�Ƃ��܂��B
	@param iMin [in]
	@param iMax [in]
	@param iPage [in]
	@param iPos [in]
	*/
	void set( int iMin , int iMax , int iPage , int iPos )
	{
		m_iMin = iMin ;
		m_iMax = iMax ;
		m_iPage = iPage ;
		m_iPos = iPos ;
		m_bIsNull = false ;
		adjustProp() ;
	};
	///@}
public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�Q�� CdScrollbarProp ���r���܂��B
	@param value [in]
		��r�ΏۂƂȂ� CdScrollbarProp ���w�肵�Ă��������B
	@return
		- true : CdScrollbarProp ���������B�o����NULL�B
	*/
	bool isEqualTo( const CdScrollbarProp& value )const
	{
		if ( m_bIsNull && value.m_bIsNull )
		{
			return true ;
		}
		return ( m_iMin == value.m_iMin
			&& m_iMax == value.m_iMax
			&& m_iPage == value.m_iPage
			&& m_iPos == value.m_iPos 
			&& m_bDisableNoScroll == value.m_bDisableNoScroll  
			&& m_bAdjustPosByPage == value.m_bAdjustPosByPage ) ;
	};
	///@}
};

} } //namespace DcDrawLib{ namespace WinUtil{ 

#endif //WinUtil_CdScrollbarProp_h
