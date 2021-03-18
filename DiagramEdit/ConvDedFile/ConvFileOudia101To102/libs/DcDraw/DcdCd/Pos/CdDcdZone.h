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
//	./CdDcdZone.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDcdZone_h
#define  CdDcdZone_h

#include "./DcdType.h"

// ****************************************************************
//	CdDcdZone.h
// ****************************************************************
/**
 @brief 
 �y�T�v�z
 	  �P�����̍��W��ԏ�́A�͈͂�\���P���f�[�^�N���X�ł��B
 	  �N�_�ʒu���W�ƁA���͈̔͂̑傫����\���܂��B
*/
class CdDcdZone
{
public:
	// --------------------------------
	///@name	�����֐�
	// --------------------------------
	///@{
	/**
	 	�l�̕�����\���l��Ԃ��܂��B
	 @param ev [in]
	 	���������؂���l���w�肵�Ă��������B
	 @return
	 	�l��	@n
	 		�O�Ȃ�O�A		@n
	 		���̐��Ȃ�P	@n
	 		���̐��Ȃ�|�P	@n
	 	��Ԃ��܂��B
	*/
	static int Sign( int ev ){
		if ( ev > 0 ){	return ( 1 ) ;}
		else if ( ev < 0 ){	return ( -1 ) ;}
		return ( 0 ) ;
	};
	///@}
private:
	// ********************************
	///@name	����
	// ********************************
	///@{
	///	�N�_�ʒu�ł��B
	DcdPos m_iPos ;
	
	///  �͈͂̑傫���ł��B
	DcdSize m_iSize ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CdDcdZone() : m_iPos( 0 ) , m_iSize( 0 ) {} ;
	
	/**
	 	�N�_�ʒu����P�͈̔͂�\���I�u�W�F�N�g�𐶐����܂�
	 @param iPos [in]
	 	�N�_�ʒu���w�肵�Ă��������B
	*/
	CdDcdZone( DcdPos iPos ) 
		: m_iPos( iPos ) , m_iSize( 1 ) {} ;
	
	/**
	 @param iPos [in]
	 	�N�_�ʒu���w�肵�Ă��������B
	 @param iSize ; [in]
	   �͈͂̑傫���ł��B
	*/
	CdDcdZone( DcdPos iPos , DcdSize iSize ) 
		: m_iPos( iPos ) , m_iSize( iSize ) {} ;
	
 public:
	// ********************************
	///@name	CdDcdZone-����
	// ********************************
	///@{
	DcdPos getPos()const{	return ( m_iPos ) ;	};
	CdDcdZone& setPos( DcdPos ev ){	m_iPos = ev ;	return ( *this ) ;	};
	DcdSize getSize()const{	return ( m_iSize ) ;};
	CdDcdZone& setSize( DcdSize ev ){	m_iSize = ev ;	return ( *this ) ;	};
	
	/**
	  @return
	    �͈͂̏I�_�ʒu�̎��̈ʒu��Ԃ��܂��B
	  	���̈ʒu�́A�͈͂ɂ͊܂܂�܂���B
	*/
	DcdPos getEndPos()const{	return m_iPos + m_iSize ; } ;
	
	/**
	    �͈͂̏I�_�ʒu�̎��̈ʒu���w�肵�܂��B
	  	 ���̈ʒu�́A�͈͂ɂ͊܂܂�܂���B
	 	
	 	���̊֐��́A value �����ƂɁAm_iSize �����肵�܂��B
	 	m_iPos �ɂ́A�e����^���܂���B
	*/
	CdDcdZone& setEndPos( DcdPos value ){
		m_iSize = value - m_iPos ; return *this ; } ;
	
	/**
	    �͈͂̋N�_�ʒu�ƏI�_�ʒu��ݒ肵�܂��B
	  @param posBegin [in]
	 	�N�_�ʒu���w�肵�Ă��������B
	  @param posEnd [in]
	  	 �I�_�ʒu���w�肵�Ă��������B
	 	���̈ʒu�́A�͈͂ɂ͊܂܂�܂���B
	*/
	CdDcdZone& setBeginEndPos( DcdPos posBegin , DcdPos posEnd ){
		m_iPos = posBegin ;
		m_iSize = posEnd - posBegin ; 
		return *this ;
	};
		
	
	///@}
	
	// ********************************
	///@name	CdDcdZone-����
	// ********************************
	///@{
	
	/**
	 @return
	 	  �͈͂̑傫���̕���������킷����Ԃ��܂��B
	 		�͈͂��O�Ȃ�O�A
	 		���̐��Ȃ�P
	 		���̐��Ȃ�|�P
	 	��Ԃ��܂��B
	*/
	int getSizeSign()const{	return ( Sign( getSize() ) ) ;	};
	
	/**
	 	  �͈͂̑傫����\���l�̕������A���̐��E�܂��͕��̐��ɕύX���܂��B
	 	  ���̏ꍇ�ł��A���W�͈͕͂ς��܂���B
	 	(��) Pos = 1,Size=5�̃I�u�W�F�N�g�ɁA ev=-1 �ł��̃��\�b�h���Ăяo����
	 	Pos = 5 ,Size=-5 �ɂȂ�܂��B
	 @param ev [in]
	 	�����𐳂̐��ɂ���Ȃ�P�E���̐��ɂ���Ȃ�|�P���w�肵�Ă��������B
	*/
	CdDcdZone& setSizeSign( int ev = 1 ){
		if ( getSizeSign() == -Sign( ev ) ){
			//	�����𔽓]���܂��B
			m_iPos = m_iPos + m_iSize - getSizeSign() ;
			m_iSize = -m_iSize ;
		}
		return ( *this ) ;
	};
	
	
	/**
	 	����CdDcdZone�Ƃ̔�r���s���܂��B
	 @param ev [in]
	 	��r�Ώۂ��w�肵�Ă��������B
	 @return
	 	���ׂĂ̑����������ł���ΐ^�ł��B
	*/
	bool IsEqualTo( const CdDcdZone& ev )const{	
		return ( m_iPos == ev.m_iPos && m_iSize == ev.m_iSize );
	};
	
	/**
	  	���͈̔͂ƁA�w�肳�ꂽ�ʂ͈̔͂Ƃ̊ԂŁA�������Ă���͈͂�
	  	���߂܂��B
	  @param ev [in]
	  	���������߂�ΏۂɂȂ� CdDcdZone �I�u�W�F�N�g���w�肵�Ă��������B
	  @return
	  	���͈̔͂ƁAev �Ƃ��������Ă���̈��Ԃ��܂��B
	    - this �� ev �̂����ꂩ�� Size ���O�ł���΁A�N�_��this�Ɠ����A
	  	�T�C�Y���O�̃I�u�W�F�N�g��Ԃ��܂��B
	    - this��ev�̕������قȂ�ꍇ�́Aev�̕��̕����𔽓]���āA
	  	�����͈͂����߂܂��B���̏ꍇ�A�߂�l�̕�����
	  	this�Ɠ��������ɂȂ�܂��B
	    - this �� ev �Ɍ������Ă���̈悪�Ȃ��ꍇ�́A�N�_��this�Ɠ����A
	  	�T�C�Y���O�̃I�u�W�F�N�g��Ԃ��܂��B
	 */
	CdDcdZone CrossZone( const CdDcdZone& ev )const{
		//	this �� ev �̂����ꂩ�� Size ���O�ł���΁A�N�_��this�Ɠ����A
		//	�T�C�Y���O�̃I�u�W�F�N�g��Ԃ��܂��B
		if ( getSizeSign() == 0 || ev.getSizeSign() == 0 ){
			return ( CdDcdZone( m_iPos , 0 ) ) ;
		}	
		
		//	�T�C�Y�̕������قȂ�ꍇ�́A�����̕��̕����𔽓]���܂��B
		CdDcdZone	aZone( ev ) ;
		if ( getSizeSign() == -aZone.getSizeSign() ){
			aZone.setSizeSign( -aZone.getSizeSign() ) ;
		}
		
		//	�������������̏ꍇ
		if ( getSizeSign() == 1 )
		{
			DcdPos	aPos = m_iPos ;
			if ( m_iPos < aZone.m_iPos ){
				aPos = aZone.m_iPos ;
			}
			DcdPos	aEndPos = getEndPos() ;
			if ( getEndPos() > aZone.getEndPos() ){
				aEndPos = aZone.getEndPos() ;
			}
			if ( aPos <= aEndPos ){
				return ( CdDcdZone( aPos , aEndPos - aPos ) ) ;
			}
			return ( CdDcdZone( m_iPos , 0 ) ) ;
		}
		
		//	�������������̏ꍇ
			DcdPos	aPos = m_iPos ;
			if ( m_iPos > aZone.m_iPos ){
				aPos = aZone.m_iPos ;
			}
			DcdPos	aEndPos = getEndPos() ;
			if ( getEndPos() < aZone.getEndPos() ){
				aEndPos = aZone.getEndPos() ;
			}
			if ( aPos >= aEndPos ){
				return ( CdDcdZone( aPos , aEndPos - aPos ) ) ;
			}
			return ( CdDcdZone( m_iPos , 0 ) ) ;
	};
	
	/**
	  	���͈̔͂ƁA�w�肳�ꂽ�ʂ͈̔͂��܂ށA
		�ł��������͈͂����߂܂��B
	  @param ev [in]
	  	��܂����߂�ΏۂɂȂ� CdDcdZone �I�u�W�F�N�g���w�肵�Ă��������B
	  @return
	  	���͈̔͂ƁAev ���܂���̈��Ԃ��܂��B
	    - this��ev�̕������قȂ�ꍇ�́Aev�̕��̕����𔽓]���āA
	  	�����͈͂����߂܂��B���̏ꍇ�A�߂�l�̕�����
	  	this�Ɠ��������ɂȂ�܂��B
	 */
	CdDcdZone ZoneOr( const CdDcdZone& ev )const{
		CdDcdZone	zoneRv ;

		//	�T�C�Y�̕������قȂ�ꍇ�́A�����̕��̕����𔽓]���܂��B
		CdDcdZone	aZone( ev ) ;
		if ( getSizeSign() == -aZone.getSizeSign() ){
			aZone.setSizeSign( -aZone.getSizeSign() ) ;
		}


		//	������0���������̏ꍇ
		if ( getSizeSign() >= 0 )
		{
			//	aPos �́Am_iPos��0�ɋ߂��ق��Ƃ��܂��B
			DcdPos	aPos = m_iPos ;
			if ( m_iPos > aZone.m_iPos ){
				aPos = aZone.m_iPos ;
			}
			//	aEndPos �́AgetEndPos() ��0���牓�����B
			DcdPos	aEndPos = getEndPos() ;
			if ( getEndPos() < aZone.getEndPos() ){
				aEndPos = aZone.getEndPos() ;
			}

			zoneRv.setBeginEndPos( aPos , aEndPos ) ;
		}
		//	�������������̏ꍇ
		else
		{
			//	aPos �́Am_iPos��0�ɋ߂��ق��Ƃ��܂��B
			DcdPos	aPos = m_iPos ;
			if ( m_iPos < aZone.m_iPos ){
				aPos = aZone.m_iPos ;
			}
			//	aEndPos �́AgetEndPos() ��0���牓�����B
			DcdPos	aEndPos = getEndPos() ;
			if ( getEndPos() > aZone.getEndPos() ){
				aEndPos = aZone.getEndPos() ;
			}

			zoneRv.setBeginEndPos( aPos , aEndPos ) ;
		}
		return ( zoneRv ) ;
	};



	/**
	 	�w��̈ʒu�����͈̔͂Ɋ܂܂�Ă��邩�ǂ����𔻒f���܂��B
	 @param ev [in]
	 	���肷��ʒu���w�肵�Ă��������B
	 @return
	 	�ʒu�����͈̔͂Ɋ܂܂�Ă���ΐ^�ł��B
	*/
	bool IsInner( DcdPos ev )const{	
		if ( getSizeSign() == -1 ){
			return ( m_iPos >= ev && ev > getEndPos() ) ;
		}
		return ( m_iPos <= ev && ev < getEndPos() ) ;
	};
	
	/**
	 	�w��͈̔͂����͈̔͂Ɋ܂܂�Ă��邩�ǂ����𔻒f���܂��B
	 @param ev [in]
	 	���肷��ʒu���w�肵�Ă��������B
	 @return
	 	�ʒu�����͈̔͂Ɋ܂܂�Ă���ΐ^�ł��B
	*/
	bool IsInner( CdDcdZone& ev )const{	
		CdDcdZone	aZone( ev ) ;
		aZone.setSizeSign( getSizeSign() ) ;
		if ( CrossZone( aZone ).IsEqualTo( aZone ) ){
			return ( true ) ;
		}
		return ( false ) ;
	};
	///@}
	// ********************************
	///@name	���Z�q	
	// ********************************
	///@{
	/// IsEqualTo() �Ƃ��ē��삵�܂��B
	bool operator ==( const CdDcdZone& ev )const{	
		return (  IsEqualTo( ev ) ) ; 
	};
	/// IsEqualTo() �Ƃ��ē��삵�܂��B
	bool operator !=( const CdDcdZone& ev )const{
		return ( !IsEqualTo( ev ) ) ; 
	};
	///@}
	
};


#endif /*CdDcdZone_h*/
