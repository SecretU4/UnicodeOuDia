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
// ****************************************************************
//	CdDedJikoku
// ****************************************************************
/**
 @brief
 �y�T�v�z
	  �b�P�ʂ̎�����\���P���f�[�^�N���X�ł��B
	
	  ���t�̊T�O�͂���܂���B
	  ����̊Ԃ́A00:00 ����̂Q�S���Ԃ̎�����\���܂��B
	  00:00�ȑO�E24:00�ȍ~�̎������w�肵���ꍇ�́A�T�C�N���b�N�����l��
	�ێ����܂��B
	  ���Ƃ��΁A���̃N���X�̃I�u�W�F�N�g�� 25:00 ��ݒ肵�悤�Ƃ���ƁA
	�I�u�W�F�N�g�� 1:00 ��ێ����܂��B
	
	  ���̃N���X�́A�����I�ɂ� 00:00 ����̌o�ߕb���𑮐� m_iTotalSeconds 
	�ŕێ����܂��B���E���E�b�́A���̃N���X�̔h�������Ƃ��Ĉʒu�t�����܂��B

	  ���̃N���X�́A�wNull��ԁx�������Ƃ��ł��܂��B����́A
	�uthis ���L���Ȏ�����ێ����Ă��Ȃ��v���Ƃ������l�ł��B

	���̃N���X���ێ����鎞���́A CConv::encode() �ŕ����񉻂��邱�Ƃ��ł��܂��B

	(��)  "10:30:45"

	�܂��ACConv::encode() �ō쐬������������A deocde() �ŉ��߂��邱�Ƃ�
	�ł��܂��B
 */
class CdDedJikoku
{
public:
	// ********************************
	//	�萔
	// ********************************
	/**
		24���Ԃ̕b��
	*/
	static const int TOTALSECONDS_A_DAY = 24*60*60 ;

public:
	// ****************************************************************
	//	CdDedJikoku::CConv
	// ****************************************************************
	/**
		CdDedJikoku �̓��e�𕶎��񉻂���N���X�ł��B
		�����Ƃ��āA������̃t�H�[�}�b�g��ێ����܂��B
	*/
	class CConv
	{
	public:
		/** ���̕ϊ����@ */
		enum EHour
		{
			/** ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" �Ƃ��܂��B*/ 
			EHour_Zero ,
			/** ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" ���폜���܂��B */
			EHour_ZeroToNone ,	
			/** ���� 00 ���� 09 �̏ꍇ�A10�̈ʂ� "0" ���X�y�[�X�ɂ��܂��B*/ 
			EHour_ZeroToSpace ,
		};
		/** �b�̕ϊ����@ */
		enum ESecond
		{
			/** �b����ɏo�͂��܂��B */
			ESecond_Output ,
			/** �b����ɏo�͂��܂���B */
			ESecond_NoSecond ,
			/** �b��0�Ȃ�A�b���o�͂��܂���B */
			ESecond_NotIfZero ,
		};
	private:
		/** 
			- true: ���F���F�b �̊Ԃ̃R���� ":" ���o�͂��܂��� 
			- false: ���F���F�b �̊Ԃ̃R���� ":" ���o�͂��܂� 
		*/
		bool m_bNoColon ;

		/** ���̕ϊ����@ */
		EHour	m_eHour ;
		
		/** �b�̕ϊ����@ */
		ESecond m_eSecond ;

	public:
		CConv() ;

		/**
		@param bNoColon [in]
			 ���F���F�b �̊Ԃ̃R���� ":" ���o�͂��܂��� 
		@param eHour [in]
			���̕ϊ����@���w�肵�Ă��������B
		@param eSecond [in]
			�b�̕ϊ����@���w�肵�Ă��������B
		*/
		CConv( 
			bool bNoColon ,
			EHour	eHour  ,
			ESecond eSecond ) ;
		
		bool getNoColon()const
		{	return m_bNoColon ;};
		CConv& setNoColon( bool value )
		{	m_bNoColon = value ; return *this ;};

		EHour	getHour()const{	return m_eHour ;};
		CConv& setHour( EHour value )
		{	m_eHour = value ; return *this ;};
		
		ESecond	getSecond()const{	return m_eSecond ;};
		CConv& setSecond( ESecond value )
		{	m_eSecond = value ; return *this ;};


		/**
			�����𕶎���ŕ\�����܂��B
		 @param aJikoku [in]
			�������w�肵�Ă��������B
		 @return
			aJikoku �𕶎��񉻂������̂�Ԃ��܂��B
			aJikoku ���wNull��ԁx�̏ꍇ�́A�󕶎����Ԃ��܂��B
		*/
		std::string encode( const CdDedJikoku& aJikoku )const ;

	};

private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		 00:00 ����̌o�ߕb����ێ����܂��B
		�L���Ȓl�͈̔͂́A 0 �ȏ� 24*60*60 ����
		( 0:00 �ȏ� 24:00 ����)�ł��B
	
		�������A�wNull��ԁx�̂Ƃ��́AINT_MIN �ƂȂ�܂��B
		�f�t�H���g�R���X�g���N�^�ł́A�wNull��ԁx�Ƃ��܂��B
	 */
	int	m_iTotalSeconds ;
	///@}

 protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		�o�ߕb���𐳋K�����܂��B
	
		�l�� 0 �ȏ� 24*60*60 ����
		( 0:00 �ȏ� 24:00 ����)�Ƃ��܂��B
		
	 @param iTotalSeconds [in]
		���K���O�̌o�ߕb�����w�肵�Ă��������B
		���̐��ł����܂��܂���B
			-1 �́A�wNull��ԁx�Ƃ݂͂Ȃ��܂���B
	 @return
		���K����̒l��Ԃ��܂��B
	 
		�i��j
	
		- iTotalSeconds = -1 �̏ꍇ�̖߂�l�́A 23:59:59 
		- iTotalSeconds = 24*60*60 �̏ꍇ�̖߂�l�́A 0  
	 */
	static int adjustTotalSeconds( int iTotalSeconds ) ;

	///@}
 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		�wNull��ԁx�ɏ��������܂��B
	 */
	CdDedJikoku() ;
	
	/**
	 @param iTotalSeconds [in]
		 00:00 ����̌o�ߕb�����w�肵�Ă��������B
		0 �ȏ� 24*60*60 ����( 0:00 �ȏ� 24:00 ����)
		�͈̔͊O�̒l���w�肵���ꍇ�́A���̊֐���
		������	0 �ȏ� 24*60*60 ����( 0:00 �ȏ� 24:00 ����)
		�ɐ��K�����Ă��� m_iTotalSeconds ��
		�ݒ肵�܂��B
	 @attention
		-1 �́A�wNull��ԁx�Ƃ݂͂Ȃ����A23:59:59 ��
		�݂Ȃ��܂��B
	*/
	CdDedJikoku( int iTotalSeconds ) ;
	
	/**
	 @param iHour [in]
		���B�͈͂� 0 �ȏ� 24 �����B
	 @param iMinute [in]
		���B�͈͂� 0 �ȏ� 60 �����B
	 @param iSecond [in]
		�b�B�͈͂� 0 �ȏ� 60 �����B
	 */
	CdDedJikoku( int iHour , int iMinute , int iSecond = 0 ) ;

	/**
		������������g���ď��������܂��B
	 @param value [in]
		������������w�肵�Ă��������B
		
	 (��)����������̗�
		-	"13:15:45"
		-	"13:15"
		-	"131545"
		-	"1315"
		-	"9:15:45"
		-	"9:15"
		-	"91545"
		-	"915"
	 */
	CdDedJikoku( const std::string& strTime ) ;

public:
	// ********************************
	//	CdDedJikoku
	// ********************************
	// ********************************
	///@name CdDedJikoku-����
	// ********************************
	///@{

	int getTotalSeconds()const{	return m_iTotalSeconds ; } ;
	/**
	 @param iTotalSeconds [in]
		 00:00 ����̌o�ߕb�����w�肵�Ă��������B
		0 �ȏ� 24*60*60 ����( 0:00 �ȏ� 24:00 ����)
		�͈̔͊O�̒l���w�肵���ꍇ�́A���̊֐���
		������	0 �ȏ� 24*60*60 ����( 0:00 �ȏ� 24:00 ����)
		�ɐ��K�����Ă��� m_iTotalSeconds ��
		�ݒ肵�܂��B
	*/
	CdDedJikoku& setTotalSeconds( int value ) ;
	
	/**
	 @return
		���B
	 @attention
		this �� �wNull��ԁx�̏ꍇ�́A0��Ԃ��܂��B
	 */
	int getHour()const{	return m_iTotalSeconds / ( 60 * 60 )  ; } ;
	
	/**
	 @return
		���B
	 @attention
		this �� �wNull��ԁx�̏ꍇ�́A0��Ԃ��܂��B
	 */
	int getMinute()const{	return m_iTotalSeconds / ( 60 ) % ( 60 )  ; } ;
	
	/**
	 @return
		�b�B
	 @attention
		this �� �wNull��ԁx�̏ꍇ�́A0��Ԃ��܂��B
	 */
	int getSecond()const{	return m_iTotalSeconds % ( 60 )  ; } ;
	
	/**
		�������A�ݒ肵�܂��B
	 @param iHour [in]
		���B�͈͂� 0 �ȏ� 24 �����B
	 @param iMinute [in]
		���B�͈͂� 0 �ȏ� 60 �����B
	 @param iSecond [in]
		�b�B�͈͂� 0 �ȏ� 60 �����B
	 */
	CdDedJikoku& setTime( int iHour , int iMinute , int iSecond = 0 ) ;
	
	/**
	 @return
		this ���wNull��ԁx�Ȃ�^��Ԃ��܂��B
	 */
	bool isNull()const{	return m_iTotalSeconds == INT_MIN ; } ;

	/**
		this ���wNull��ԁx�Ƃ��܂��B
	 */
	CdDedJikoku& setNull() ;
	
	///@}
	
	// ********************************
	///@name CdDedJikoku-����
	// ********************************
	///@{
	/**
		�Q�̎������A��r���܂��B
	 @param value [in]
		��r�Ώۂ̃I�u�W�F�N�g���w�肵�Ă��������B
	 @return
		this - value ���s�������ʂ̕�����Ԃ��܂��B
		-	+1 ;	//	this > value�B
					//	�܂��́A this ����wNull��ԁx�� value �� �wNull��ԁx
		-	0 ;		//	this == value�B
					//	�܂��́A this �� value �� �wNull��ԁx
		-	-1 ;	//	this < value�B
					//	�܂��́A this ���wNull��ԁx�� value �� ��wNull��ԁx
	*/
	int compare( const CdDedJikoku& value )const ;
	
	/**
		�Q�̎������A��r���܂��B
	 @param value [in]
		��r�Ώۂ̃I�u�W�F�N�g���w�肵�Ă��������B
	 @param jikokuKitenJikoku [in]
		�_�C���O�����N�_�������w�肵�Ă��������B
		���̊֐��́A�\�[�g���ɁA���̒l���ł�������������
		�݂Ȃ��܂��B
		(��F���̎�����5:00���w�肳�ꂽ�ꍇ�́A5:00<23:59<0:00<4:59 �Ƃ��Ĕ�r���s���܂�)
	 @return
		this - value ���s�������ʂ̕�����Ԃ��܂��B
		-	+1 ;	//	this > value�B
					//	�܂��́A this ����wNull��ԁx�� value �� �wNull��ԁx
		-	0 ;		//	this == value�B
					//	�܂��́A this �� value �� �wNull��ԁx
		-	-1 ;	//	this < value�B
					//	�܂��́A this ���wNull��ԁx�� value �� ��wNull��ԁx
	*/
	int compare( 
		const CdDedJikoku& value , 
		const CdDedJikoku& jikokuKitenJikoku )const ;
	


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
		this ���ێ����Ă��鎞���ɑ΂��āA�b�������Z���܂��B
	 @param value [in]
		���Z����b�����w�肵�Ă��������B
		���̐����w�肷�邱�Ƃ��ł��܂��B
	 @attention
		this �� �wNull��ԁx�̏ꍇ�́A�wNull��ԁx�̂܂ܕς��܂���B
	 */
	CdDedJikoku& addSeconds( int value ) ;

	/** addSeconds() �Ɠ����ł� */
	CdDedJikoku& operator+=( int value ) {
		return addSeconds( value ) ; } ;
	/** addSeconds() �Ɠ����ł��B*/
	CdDedJikoku& operator-=( int value ) {
		return addSeconds( -value ) ; } ;



	/**
		�Q�̎����̍����A�b���ŕԂ��܂��B
		���́A��Βl���P�Q���Ԉȉ��̑��Ƃ��܂��B
	 @param value [in]
		��r�Ώۂ̃I�u�W�F�N�g���w�肵�Ă��������B
	 @return
		this - value ���s�������ʂ̕b����Ԃ��܂��B
		this < value �̏ꍇ�́A���̐���Ԃ��܂��B\n
		�������Athis - value �̐�Βl���P�Q���Ԃ𒴂��Ă���ꍇ�́A
		�t����łP�Q���Ԗ����̒l��Ԃ��܂��B
		
		(��) 
		
		this �� 1:00 �� value �� 23:00 �̏ꍇ�A�P���v�Z�ł� -22 ���Ԃł����A
		���̒l�̐�Βl��12���Ԃ𒴂��Ă��܂��B���̏ꍇ�A+2 ���Ԃ�Ԃ��܂�
	
		��  1:00 ��23:00 �̂Q�Q���ԑO�ł�����܂����A
		�i�����́j1:00 �� 23:00�̂Q���Ԍ�ł���Ƃ������܂��B
		���̊֐����Ԃ��̂́A��Βl�̏��������̒l�ł��B
	 @attention
		this �E value �̂����ꂩ�� �wNull��ԁx�̏ꍇ�́A0��Ԃ��܂��B
	 */
	int subJikoku( const CdDedJikoku& value  )const ;

	/**
		encode() �ɂ���Đ������ꂽ�����������
		��͂��Athis �̑����ɔ��f���܂��B
	
		���������񂪉��ߕs�\�ȏꍇ�́Athis �� �wNull��ԁx
		�ƂȂ�܂��B
	 @param value [in]
		������������w�肵�Ă��������B
	 @return
		���������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	���ڐ����s�����Ă��܂��B
		-	-2 ;	//	���E���E�b�̕\�L���s���ł��B
	
	 (��)����������̗�
		-	"13:15:45"
		-	"13:15"
		-	"131545"
		-	"1315"
		-	"9:15:45"
		-	"9:15"
		-	"91545"
		-	"915"
	
	 */
	int decode( const std::string& value ) ;
	///@}
};


#endif /*CdDedJikoku_h*/
