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
//	CdDedJikoku.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDedJikoku_h
#define  CdDedJikoku_h
#include <string>
using namespace std ;
// ****************************************************************
//	CdDedJikoku
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 *	  �b�P�ʂ̎�����\���P���f�[�^�N���X�ł��B
 *	
 *	  ���t�̊T�O�͂���܂���B
 *	  ����̊Ԃ́A00:00 ����̂Q�S���Ԃ̎�����\���܂��B
 *	  00:00�ȑO�E24:00�ȍ~�̎������w�肵���ꍇ�́A�T�C�N���b�N�����l��
 *	�ێ����܂��B
 *	  ���Ƃ��΁A���̃N���X�̃I�u�W�F�N�g�� 25:00 ��ݒ肵�悤�Ƃ���ƁA
 *	�I�u�W�F�N�g�� 1:00 ��ێ����܂��B
 *	
 *	  ���̃N���X�́A�����I�ɂ� 00:00 ����̌o�ߕb���𑮐� m_iTotalSeconds 
 *	�ŕێ����܂��B���E���E�b�́A���̃N���X�̔h�������Ƃ��Ĉʒu�t�����܂��B
 *
 *	  ���̃N���X�́A�wNull��ԁx�������Ƃ��ł��܂��B����́A
 *	�uthis ���L���Ȏ�����ێ����Ă��Ȃ��v���Ƃ������l�ł��B
 *
 *	���̃N���X���ێ����鎞���́A encode() �ŕ����񉻂��邱�Ƃ��ł��܂��B
 *	\n(��)  "10:30:45"
 *	\m�܂��Aencode() �ō쐬������������A deocde() �ŉ��߂��邱�Ƃ�
 *	�ł��܂��B
 */
class CdDedJikoku
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	/** encode() �ɂ�镶���񉻂̌`�����w�肷��r�b�g�ł� */
	enum EFormat{
		/** ���F���F�b �̊Ԃ̃R���� ":" ���o�͂��܂��� */
		Format_NoColon = 1 ,
		/** ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" ���폜���܂��B */
		Format_HourZeroToNone = 2 ,
		/** 
		 *	���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" ���X�y�[�X�ɂ��܂��B 
		 *
		 *	Format_HourZeroToNone �� Format_HourZeroToSpace ��
		 *	�r���I�ł��B
		 */
		Format_HourZeroToSpace = 4 ,
		/** �b���o�͂��܂��� */
		Format_NoSecond = 8 ,
	};

// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 *	�f�t�H���g�́A������̏����̃I�v�V�������w�肵�܂��B
	 *	���̒l�̓r�b�g���ƂɈӖ��������܂��B
	 *	�r�b�g�̈Ӗ��́A EFormat ���Q�Ƃ��Ă��������B
	 *
	 *	���̒l�́A�������w�肵�Ȃ��� encode() �𗘗p�����ꍇ��
	 *	�K�p����܂��B 
	 */
	static unsigned int m_iFmt  ;

	/**
	 *	 00:00 ����̌o�ߕb����ێ����܂��B
	 *	�L���Ȓl�͈̔͂́A 0 �ȏ� 24*60*60 ����
	 *	( 0:00 �ȏ� 24:00 ����)�ł��B
	 *
	 *	�������A�wNull��ԁx�̂Ƃ��́A-1 �ƂȂ�܂��B
	 *	�f�t�H���g�R���X�g���N�^�ł́A�wNull��ԁx�Ƃ��܂��B
	 */
	int	m_iTotalSeconds ;
///@}

// --------------------------------
///@name �����֐�
// --------------------------------
///@{
 protected:
	/**
	 *	�o�ߕb���𐳋K�����܂��B
	 *
	 *	�l�� 0 �ȏ� 24*60*60 ����
	 *	( 0:00 �ȏ� 24:00 ����)�Ƃ��܂��B
	 *	
	 * @param iTotalSeconds [in]
	 *	���K���O�̌o�ߕb�����w�肵�Ă��������B
	 *	���̐��ł����܂��܂���B
	 *	\n	-1 �́A�wNull��ԁx�Ƃ݂͂Ȃ��܂���B
	 * @return
	 *	���K����̒l��Ԃ��܂��B
	 * 
	 *	�i��j
	 *
	 *	- iTotalSeconds = -1 �̏ꍇ�̖߂�l�́A 23:59:59 
	 *	- iTotalSeconds = 24*60*60 �̏ꍇ�̖߂�l�́A 0  
	 */
	static int adjustTotalSeconds( int iTotalSeconds ) ;

///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 *	�wNull��ԁx�ɏ��������܂��B
	 */
	CdDedJikoku() ;
	
	/**
	 * @param iTotalSeconds [in]
	 *	 00:00 ����̌o�ߕb����ێ����܂��B
	 *	�L���Ȓl�͈̔͂́A 0 �ȏ� 24*60*60 �����ł��B
	 *	\n�������A�wNull��ԁx�̂Ƃ��́A-1 �ƂȂ�܂��B
	 */
	CdDedJikoku( int iTotalSeconds ) ;
	
	/**
	 * @param iHour [in]
	 *	���B�͈͂� 0 �ȏ� 24 �����B
	 * @param iMinute [in]
	 *	���B�͈͂� 0 �ȏ� 60 �����B
	 * @param iSecond [in]
	 *	�b�B�͈͂� 0 �ȏ� 60 �����B
	 */
	CdDedJikoku( int iHour , int iMinute , int iSecond = 0 ) ;

	/**
	 *	������������g���ď��������܂��B
	 * @param value [in]
	 *	������������w�肵�Ă��������B
	 *	
	 * (��)����������̗�
	 *	-	"13:15:45"
	 *	-	"13:15"
	 *	-	"131545"
	 *	-	"1315"
	 *	-	"9:15:45"
	 *	-	"9:15"
	 *	-	"91545"
	 *	-	"915"
	 */
	CdDedJikoku( const string& strTime ) ;

// ********************************
//	CdDedJikoku
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	static unsigned int getFmt(){return m_iFmt  ;};
	static void setFmt( unsigned int value ){
		m_iFmt = value ; };

	int getTotalSeconds()const{	return m_iTotalSeconds ; } ;
	CdDedJikoku& setTotalSeconds( int value ) ;
	
	/**
	 * @return
	 *	���B
	 * @attention
	 *	this �� �wNull��ԁx�̏ꍇ�́A0��Ԃ��܂��B
	 */
	int getHour()const{	return m_iTotalSeconds / ( 60 * 60 )  ; } ;
	
	/**
	 * @return
	 *	���B
	 * @attention
	 *	this �� �wNull��ԁx�̏ꍇ�́A0��Ԃ��܂��B
	 */
	int getMinute()const{	return m_iTotalSeconds / ( 60 ) % ( 60 )  ; } ;
	
	/**
	 * @return
	 *	�b�B
	 * @attention
	 *	this �� �wNull��ԁx�̏ꍇ�́A0��Ԃ��܂��B
	 */
	int getSecond()const{	return m_iTotalSeconds % ( 60 )  ; } ;
	
	/**
	 *	�������A�ݒ肵�܂��B
	 * @param iHour [in]
	 *	���B�͈͂� 0 �ȏ� 24 �����B
	 * @param iMinute [in]
	 *	���B�͈͂� 0 �ȏ� 60 �����B
	 * @param iSecond [in]
	 *	�b�B�͈͂� 0 �ȏ� 60 �����B
	 */
	CdDedJikoku& setTime( int iHour , int iMinute , int iSecond = 0 ) ;
	
	/**
	 * @return
	 *	this ���wNull��ԁx�Ȃ�^��Ԃ��܂��B
	 */
	bool isNull()const{	return m_iTotalSeconds == -1 ; } ;

	/**
	 *	this ���wNull��ԁx�Ƃ��܂��B
	 */
	CdDedJikoku& setNull() ;
	
	///@}
	
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 *	�Q�̎������A��r���܂��B
	 * @param value [in]
	 *	��r�Ώۂ̃I�u�W�F�N�g���w�肵�Ă��������B
	 * @return
	 *	this - value ���s�������ʂ̕�����Ԃ��܂��B
	 *	-	+1 ;	//	this > value�B
	 *				//	�܂��́A this ����wNull��ԁx�� value �� �wNull��ԁx
	 *	-	0 ;		//	this == value�B
	 *				//	�܂��́A this �� value �� �wNull��ԁx
	 *	-	-1 ;	//	this < value�B
	 *				//	�܂��́A this ���wNull��ԁx�� value �� ��wNull��ԁx
	 */
	int compare( const CdDedJikoku& value )const ;
	
	/**	compare() �Ɠ����ł��B	 */
	bool operator>( const CdDedJikoku& value )const{
		return ( compare( value ) == 1 ) ; } ;
	/**	compare() �Ɠ����ł��B	 */
	bool operator>=( const CdDedJikoku& value )const{
		return ( compare( value ) != -1  ) ; } ;
	/**	compare() �Ɠ����ł��B	 */
	bool operator==( const CdDedJikoku& value )const{
		return ( compare( value ) == 0 ) ; } ;
	/**	compare() �Ɠ����ł��B	 */
	bool operator<=( const CdDedJikoku& value )const{
		return ( compare( value ) != 1  ) ; } ;
	/**	compare() �Ɠ����ł��B	 */
	bool operator<( const CdDedJikoku& value )const{
		return ( compare( value ) == -1 ) ; } ;

	/**
	 *	this ���ێ����Ă��鎞���ɑ΂��āA�b�������Z���܂��B
	 * @param value [in]
	 *	���Z����b�����w�肵�Ă��������B
	 *	���̐����w�肷�邱�Ƃ��ł��܂��B
	 * @attention
	 *	this �� �wNull��ԁx�̏ꍇ�́A�wNull��ԁx�̂܂ܕς��܂���B
	 */
	CdDedJikoku& addSeconds( int value ) ;

	/** addSeconds() �Ɠ����ł� */
	CdDedJikoku& operator+=( int value ) {
		return addSeconds( value ) ; } ;
	/** addSeconds() �Ɠ����ł��B
	 *
	 *	this ���ێ����Ă��鎞���ɑ΂��āA�b�������Z���܂��B
	 * @param value [in]
	 *	���Z����b�����w�肵�Ă��������B
	 *	���̐����w�肷�邱�Ƃ��ł��܂��B
	 * @attention
	 *	this �� �wNull��ԁx�̏ꍇ�́A�wNull��ԁx�̂܂ܕς��܂���B
	 */
	CdDedJikoku& operator-=( int value ) {
		return addSeconds( -value ) ; } ;



	/**
	 *	�Q�̎����̍����A�b���ŕԂ��܂��B
	 *	���́A��Βl���P�Q���Ԉȉ��̑��Ƃ��܂��B
	 * @param value [in]
	 *	��r�Ώۂ̃I�u�W�F�N�g���w�肵�Ă��������B
	 * @return
	 *	this - value ���s�������ʂ̕b����Ԃ��܂��B
	 *	this < value �̏ꍇ�́A���̐���Ԃ��܂��B\n
	 *	�������Athis - value �̐�Βl���P�Q���Ԃ𒴂��Ă���ꍇ�́A
	 *	�t����łP�Q���Ԗ����̒l��Ԃ��܂��B
	 *	
	 *	(��) 
	 *	
	 *	this �� 1:00 �� value �� 23:00 �̏ꍇ�A�P���v�Z�ł� -22 ���Ԃł����A
	 *	���̒l�̐�Βl��12���Ԃ𒴂��Ă��܂��B���̏ꍇ�A+2 ���Ԃ�Ԃ��܂�
	 *
	 *	��  1:00 ��23:00 �̂Q�Q���ԑO�ł�����܂����A
	 *	�i�����́j1:00 �� 23:00�̂Q���Ԍ�ł���Ƃ������܂��B
	 *	���̊֐����Ԃ��̂́A��Βl�̏��������̒l�ł��B
	 * @attention
	 *	this �E value �̂����ꂩ�� �wNull��ԁx�̏ꍇ�́A0��Ԃ��܂��B
	 */
	int subJikoku( const CdDedJikoku& value  )const ;


	/**
	 *	�Q�̎����̍����A�b���ŕԂ��܂��B
	 * @param value [in]
	 *	��r�Ώۂ̃I�u�W�F�N�g���w�肵�Ă��������B
	 * @param jikokuDateLine [in]
	 *	���t���E�̎������w�肵�Ă��������B\n
	 *	���̊֐��́A���t���E���ׂ��Ȃ��悤�Ɍv�Z���s���܂��B
	 * @return
	 *	this - value ���s�������ʂ̕b����Ԃ��܂��B
	 *	this < value �̏ꍇ�́A���̐���Ԃ��܂��B
	 *
	 *	jikokuDateLine �́A�l�� this �ȏ� value �ȉ��̊Ԃ�
	 *	�ʒu�����ꍇ�ɈӖ��������܂��B
	 *	
	 *	(��) this �� 1:00 �� value �� 5:00 �̏ꍇ�A
	 *	- jikokuDate �� 0:00 �Ȃ�A���̊֐��̖߂�l�� -4 ���Ԃł��B
	 *	- jikokuDate �� 3:00 �Ȃ�A���̊֐��́A
	 *		this ��1:00 ���u������1:00(25��)�v�Ƃ݂Ȃ��܂��B
	 *		�߂�l�́A( 25�� - 5�� )�Ƃ��Čv�Z���s�������ʂ� +20 ���Ԃ�
	 *		�Ȃ�܂��B
	 *	(��) this �� 5:00 �� value �� 1:00 �̏ꍇ�A
	 *	- jikokuDate �� 0:00 �Ȃ�A���̊֐��̖߂�l�� 4 ���Ԃł��B
	 *	- jikokuDate �� 3:00 �Ȃ�A���̊֐��́A
	 *		value ��1:00 ���u������1:00(25��)�v�Ƃ݂Ȃ��܂��B
	 *		�߂�l�́A( 5�� - 25�� )�Ƃ��Čv�Z���s�������ʂ� -20 ���Ԃ�
	 *		�Ȃ�܂��B
	 *
	 *	
	 * @attention
	 *	this �E value �̂����ꂩ�� �wNull��ԁx�̏ꍇ�́A0��Ԃ��܂��B
	 */
	int subJikoku( const CdDedJikoku& value , 
		const CdDedJikoku& jikokuDateLine )const ;


	/**
	 *	�����𕶎���ŕ\�����܂��B
	 * @param iFmt [in]
	 *	������̏����̃I�v�V�������w�肵�܂��B
	 *	���̒l�̓r�b�g���ƂɈӖ��������܂��B
	 *	�r�b�g�̈Ӗ��́A EFormat ���Q�Ƃ��Ă��������B
	 * @return
	 *	�����񉻂������̂�Ԃ��܂��B
	 *	this ���wNull��ԁx�̏ꍇ�́A�󕶎����Ԃ��܂��B
	 */
	string encode( unsigned int iFmt )const ;

	/**
	 *	�����𕶎���ŕ\�����܂��B
	 * @return
	 *	�����񉻂������̂�Ԃ��܂��B
	 *	this ���wNull��ԁx�̏ꍇ�́A�󕶎����Ԃ��܂��B
	 *
	 *	������̏����̃I�v�V�����́A m_iFmt �̒l���̗p���܂��B
	 */
	string encode()const{	return encode( m_iFmt ) ;};

	/**
	 *	encode() �ɂ���Đ������ꂽ�����������
	 *	��͂��Athis �̑����ɔ��f���܂��B
	 *
	 *	���������񂪉��ߕs�\�ȏꍇ�́Athis �� �wNull��ԁx
	 *	�ƂȂ�܂��B
	 * @param value [in]
	 *	������������w�肵�Ă��������B
	 * @return
	 *	���������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	���ڐ����s�����Ă��܂��B
	 *	-	-2 ;	//	���E���E�b�̕\�L���s���ł��B
	 *
	 * (��)����������̗�
	 *	-	"13:15:45"
	 *	-	"13:15"
	 *	-	"131545"
	 *	-	"1315"
	 *	-	"9:15:45"
	 *	-	"9:15"
	 *	-	"91545"
	 *	-	"915"
	 *
	 */
	int decode( const string& value ) ;

	
	///@}
	
};


#endif /*CdDedJikoku_h*/
