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
//	CentDedEkiJikoku.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedEkiJikoku_h
#define  CentDedEkiJikoku_h

#include "CdDedJikoku.h"


// ****************************************************************
//	CentDedEkiJikoku
// ****************************************************************
/**
 * @brief
 *	�y�T�v�z  DiagramEdit �́A�P��Ԃ̂P�w�ɂ����鎞����\���܂��B
 *	�����Ƃ��āA�w�������x�w�������x��
 *	�w�w���x�o�^�s�Ȃ�,�o�R�Ȃ�,�ʉ�,��ԁp
 *	��ێ����܂��B
 */
class CentDedEkiJikoku
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	/**
	 *	�w�w���x��\���񋓂ł��B
	 */
	enum EEkiatsukai{
		/**
		 *	�^�s�Ȃ�(�K��l) �B
		 *
		 *	���̏ꍇ�A
		 *	������ ( m_jikokuChakujikoku )�E
		 *	������ ( m_jikokuHatsujikoku )
		 *	�́A�wNull��ԁx�ƂȂ�܂��B
		 */
		Ekiatsukai_None ,
		/**
		 *	 ���
		 *
		 *	���̏ꍇ�A
		 *	������ ( m_jikokuChakujikoku )�E
		 *	������ ( m_jikokuHatsujikoku )
		 *	�̏��Ȃ��Ƃ��P�́A��wNull��ԁx�łȂ��Ă͂Ȃ�܂���B
		 */
		Ekiatsukai_Teisya ,
		/**
		 *	 �ʉ�
		 */
		Ekiatsukai_Tsuuka ,
		/** 
		 *	�o�R�Ȃ�
		 *
		 *	���̏ꍇ�A
		 *	������ ( m_jikokuChakujikoku )�E
		 *	������ ( m_jikokuHatsujikoku )
		 *	�́A�wNull��ԁx�ƂȂ�܂��B
		 */
		Ekiatsukai_Keiyunasi ,
	};


// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 *	�w���B
	 */
	EEkiatsukai	m_eEkiatsukai ;
	
	/**
	 *	�������B
	 *
	 *	m_eEkiatsukai ��
	 *	�^�s�Ȃ� ( Ekiatsukai_None ),
	 *	�o�R�Ȃ� ( Ekiatsukai_Keiyunasi ) �̏ꍇ�́A
	 *	���̒l�͈Ӗ��������܂���B
	 */
	CdDedJikoku	m_jikokuChakujikoku ;
	
	/**
	 *	�������B
	 *
	 *	m_eEkiatsukai ��
	 *	�^�s�Ȃ� ( Ekiatsukai_None ),
	 *	�o�R�Ȃ� ( Ekiatsukai_Keiyunasi ) �̏ꍇ�́A
	 *	���̒l�͈Ӗ��������܂���B
	 */
	CdDedJikoku	m_jikokuHatsujikoku ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param eEkiatsukai [in]
	 *	�w���B
	 * @param jikokuChakujikoku [in]
	 *	�������B	\n
	 *	m_eEkiatsukai ��
	 *	�^�s�Ȃ� ( Ekiatsukai_None ),
	 *	�o�R�Ȃ� ( Ekiatsukai_Keiyunasi ) �̏ꍇ�́A
	 *	���̒l�͈Ӗ��������܂���B
	 * @param jikokuHatsujikoku [in]
	 *	�������B	\n
	 *	m_eEkiatsukai ��
	 *	�^�s�Ȃ� ( Ekiatsukai_None ),
	 *	�o�R�Ȃ� ( Ekiatsukai_Keiyunasi ) �̏ꍇ�́A
	 *	���̒l�͈Ӗ��������܂���B
	 */
	CentDedEkiJikoku( 
		EEkiatsukai	eEkiatsukai , 
		CdDedJikoku	jikokuChakujikoku , 
		CdDedJikoku	jikokuHatsujikoku ) 
	{
		set( eEkiatsukai , jikokuChakujikoku , jikokuHatsujikoku ) ;			
	};
	
	/** �f�t�H���g�R���X�g���N�^ */
	CentDedEkiJikoku() :
		m_eEkiatsukai( Ekiatsukai_None ) {};
	

// ********************************
//	CentDedEkiJikoku
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	EEkiatsukai	getEkiatsukai()const{	return m_eEkiatsukai ;};

	/**
	 *	�w����ݒ肵�܂��B
	 *	- 	Ekiatsukai_None �E�܂��� Ekiatsukai_Keiyunasi ��ݒ肷��ƁA
	 *		���E�������͂ǂ���� Null �����ƂȂ�܂��B
	 */
	CentDedEkiJikoku& setEkiatsukai( EEkiatsukai value ){
		m_eEkiatsukai = value ;
		if ( m_eEkiatsukai == Ekiatsukai_None ||
			m_eEkiatsukai == Ekiatsukai_Keiyunasi  ){
			m_jikokuChakujikoku.setNull() ;
			m_jikokuHatsujikoku.setNull() ;
		}
		return *this ; 
	} ;
	
	/**
	 *	���������Q�Ƃ��邱�Ƃ��ł��܂��B
	 * @param bHatsuIfNull [in]
	 *	- true ; �������� Null �����ŁA�������� Null �����łȂ��ꍇ�́A
	 *		��������Ԃ��܂��B
	 *	- false ; �������� Null �����Ȃ�A�������Ɋւ�炸
	 *		 Null ������Ԃ��܂��B
	 * @return
	 *		��������Ԃ��܂��B
	 */
	CdDedJikoku	getChakujikoku( bool bHatsuIfNull = false )const{
		if ( bHatsuIfNull && m_jikokuChakujikoku.isNull() ){
			return m_jikokuHatsujikoku ;
		}
		return m_jikokuChakujikoku ;
	};

	/**
	 *	��������ݒ肵�܂��B
	 *	- 	m_eEkiatsukai == Ekiatsukai_Teisya �̉w�ɑ΂���
	 *		���E�������� Null ������ݒ肷��ƁAthis ��
	 *		m_eEkiatsukai = Ekiatsukai_None �ƂȂ�܂��B
	 *	- 	m_eEkiatsukai == Ekiatsukai_None �E
	 *		�܂��� Ekiatsukai_Keiyunasi �̉w�ɑ΂���
	 *		���E���̂����ꂩ�� ��Null ������ݒ肷��ƁAthis ��
	 *		m_eEkiatsukai = Ekiatsukai_Teisya �ƂȂ�܂��B
	 */
	CentDedEkiJikoku& setChakujikoku( const CdDedJikoku& value ){
		m_jikokuChakujikoku = value ; 
		if ( m_eEkiatsukai == Ekiatsukai_Teisya && 
				m_jikokuChakujikoku.isNull() && 
			 	m_jikokuHatsujikoku.isNull() ){
			m_eEkiatsukai = Ekiatsukai_None ;
		}	else if ( 
			( m_eEkiatsukai == Ekiatsukai_None ||  
			  m_eEkiatsukai == Ekiatsukai_Keiyunasi ) && 
			( !m_jikokuChakujikoku.isNull() ||
			  ! m_jikokuHatsujikoku.isNull() )   ){
			m_eEkiatsukai = Ekiatsukai_Teisya ;
		}
			
		return *this ;
	};

	/**
	 *	���������Q�Ƃ��邱�Ƃ��ł��܂��B
	 * @param bChakuIfNull [in]
	 *	- true ; �������� Null �����ŁA�������� Null �����łȂ��ꍇ�́A
	 *		��������Ԃ��܂��B
	 *	- false ; �������� Null �����Ȃ�A�������Ɋւ�炸
	 *		 Null ������Ԃ��܂��B
	 * @return
	 *		��������Ԃ��܂��B
	 */
	CdDedJikoku	getHatsujikoku( bool bChakuIfNull = false )const{
		if ( bChakuIfNull && m_jikokuHatsujikoku.isNull() ){
			return m_jikokuChakujikoku ;
		}
		return m_jikokuHatsujikoku ;
	};

	/**
	 *	��������ݒ肵�܂��B
	 *	- 	m_eEkiatsukai == Ekiatsukai_Teisya �̉w�ɑ΂���
	 *		���E�������� Null ������ݒ肷��ƁAthis ��
	 *		m_eEkiatsukai = Ekiatsukai_None �ƂȂ�܂��B
	 *	- 	m_eEkiatsukai == Ekiatsukai_None �E
	 *		�܂��� Ekiatsukai_Keiyunasi �̉w�ɑ΂���
	 *		���E���̂����ꂩ�� ��Null ������ݒ肷��ƁAthis ��
	 *		m_eEkiatsukai = Ekiatsukai_Teisya �ƂȂ�܂��B
	 */
	CentDedEkiJikoku& setHatsujikoku( const CdDedJikoku& value )
	{
		m_jikokuHatsujikoku = value ; 
		if ( m_eEkiatsukai == Ekiatsukai_Teisya && 
				m_jikokuChakujikoku.isNull() && 
			 	m_jikokuHatsujikoku.isNull() ){
			m_eEkiatsukai = Ekiatsukai_None ;
		}	else if ( 
			( m_eEkiatsukai == Ekiatsukai_None ||  
			  m_eEkiatsukai == Ekiatsukai_Keiyunasi ) && 
			( !m_jikokuChakujikoku.isNull() ||
			  ! m_jikokuHatsujikoku.isNull() )   ){
			m_eEkiatsukai = Ekiatsukai_Teisya ;
		}
		return *this ;
	};

	/**
	 * @param eEkiatsukai [in]
	 *	�w���B
	 * @param jikokuChakujikoku [in]
	 *	�������B	\n
	 *	m_eEkiatsukai ��
	 *	������ ( Ekiatsukai_None ),
	 *	������ ( Ekiatsukai_Keiyunasi ) �̏ꍇ�́A
	 *	���̒l�͈Ӗ��������܂���B
	 * @param jikokuHatsujikoku [in]
	 *	�������B	\n
	 *	m_eEkiatsukai ��
	 *	������ ( Ekiatsukai_None ),
	 *	������ ( Ekiatsukai_Keiyunasi ) �̏ꍇ�́A
	 *	���̒l�͈Ӗ��������܂���B
	 *
	 *	- 	Ekiatsukai_None �E�܂��� Ekiatsukai_Keiyunasi ��ݒ肷��ƁA
	 *		���E�������͂ǂ���� Null �����ƂȂ�܂��B
	 *	- 	Ekiatsukai_Teisya �E���E���������ǂ���� Null �����̏ꍇ�A
	 *		m_eEkiatsukai = Ekiatsukai_None �ƂȂ�܂��B
	 */
	CentDedEkiJikoku& set( 
		EEkiatsukai	eEkiatsukai , 
		CdDedJikoku	jikokuChakujikoku , 
		CdDedJikoku	jikokuHatsujikoku )
	{
		m_eEkiatsukai = eEkiatsukai ; 
		m_jikokuChakujikoku =  jikokuChakujikoku ;
		m_jikokuHatsujikoku =  jikokuHatsujikoku ;


		if ( m_eEkiatsukai == Ekiatsukai_None ||
			m_eEkiatsukai == Ekiatsukai_Keiyunasi  ){
			m_jikokuChakujikoku.setNull() ;
			m_jikokuHatsujikoku.setNull() ;
		}	else if ( m_eEkiatsukai == Ekiatsukai_Teisya && 
				m_jikokuChakujikoku.isNull() && 
			 	m_jikokuHatsujikoku.isNull() ){
			m_eEkiatsukai = Ekiatsukai_None ;
		}
		return ( *this ) ;
	};

	///@}
};




#endif /*CentDedEkiJikoku_h*/
