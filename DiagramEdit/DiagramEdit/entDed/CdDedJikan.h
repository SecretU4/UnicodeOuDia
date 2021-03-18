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
//	CdDedJikan.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDedJikan_h
#define  CdDedJikan_h
#include <string>

namespace entDed{

// ****************************************************************
//	CdDedJikan
// ****************************************************************
/**
 @brief
 �y�T�v�z
	  �b�P�ʂ̌o�ߎ��Ԃ�\���P���f�[�^�N���X�ł��B
	
	  ���̃N���X�́A�u����A���玞��B�܂ł̊Ԃ̎��ԁv�Ƃ������A
	���Ԃ̑��Βl��\���܂��B���̐������݂��܂��B

	  ���̃N���X�́A�����I�ɂ͕b���𑮐� m_iTotalSeconds 
	�ŕێ����܂��B
	  ���ԁE���E�b�́A���̃N���X�̔h�������Ƃ��Ĉʒu�t�����܂��B

	���̃N���X���ێ����鎞�Ԃ́A encode() �ŕ����񉻂��邱�Ƃ��ł��܂��B\n
 (��)  "10:30:45"\n
	�܂��Aencode() �ō쐬������������A deocde() �ŉ��߂��邱�Ƃ�
	�ł��܂��B

 */
class CdDedJikan
{
public:
	// ****************************************************************
	//	CdDedJikan::CConv
	// ****************************************************************
	/**
		CdDedJikoku �̓��e�𕶎��񉻂���N���X�ł��B
		�����Ƃ��āA������̃t�H�[�}�b�g��ێ����܂��B
	*/
	class CConv
	{
		/**	�b���o�͂��܂��� */
		bool m_bNoSecond ;

		/** �������̐��̏ꍇ�́A�擪�� "+" ��t�^���܂��B */
		bool m_bPlusDisplay ;
		/** 
			�������̐��̏ꍇ�́A�擪�ɃX�y�[�X��t�^���܂��B
		
			Format_PlusToNone �� Format_PlusToSpace ��
			�r���I�ł��B
		 */
		bool m_bPlusToSpace ;

	public:
		CConv() ;
		/**
		@param bNoSecond [in]
			�b���o�͂��܂��� 
		@param bPlusDisplay [in]
			 �������̐��̏ꍇ�́A�擪�� "+" ��t�^���܂��B 
		@param bPlusToSpace [in]
			�������̐��̏ꍇ�́A�擪�ɃX�y�[�X��t�^���܂��B 
		*/
		CConv( 
			bool bNoSecond ,
			bool bPlusDisplay ,
			bool bPlusToSpace  ) ;
		
		bool getNoSecond()const
		{	return m_bNoSecond ;};
		CConv& setNoSecond( bool value )
		{	m_bNoSecond = value ; return *this ;};

		bool getPlusDisplay()const
		{	return m_bPlusDisplay ;};
		CConv& setPlusDisplay( bool value )
		{	m_bPlusDisplay = value ; return *this ;};

		bool getPlusToSpace()const
		{	return m_bPlusToSpace ;};
		CConv& setPlusToSpace( bool value )
		{	m_bPlusToSpace = value ; return *this ;};

		/**
			���Ԃ𕶎���ŕ\�����܂��B
		 @param aJikoku [in]
			������̏����̃I�v�V�������w�肵�܂��B
			���̒l�̓r�b�g���ƂɈӖ��������܂��B
			�r�b�g�̈Ӗ��́A EFormat ���Q�Ƃ��Ă��������B
		 @return
			�����񉻂������̂�Ԃ��܂��B
			this ���wNull��ԁx�̏ꍇ�́A�󕶎����Ԃ��܂��B
		*/
		std::string encode( const CdDedJikan& aJikan )const ;

	};

private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		 �b����ێ����܂��B
		���̐��̏ꍇ������܂��B
	 */
	int	m_iTotalSeconds ;
	///@}
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
		�l�̕�����Ԃ��܂��B
		
		�l�����̒l�̐�Βl�Ŋ��������ɂȂ�܂��B
	 @param value [in]
		�ΏۂƂȂ�l���w�肵�Ă��������B
	 @return
		-	value > 0 �̂Ƃ��A +1
		-	value == 0 �̂Ƃ��A 0
		-	value < 0 �̂Ƃ��A -1
	 */
	static int sign( int value ){
		if ( value > 0 ){	return +1 ; } 
		else if ( value < 0 ){	return -1 ; } 
		return 0 ;
	};


	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		0 �ɏ��������܂��B
	 */
	CdDedJikan() : m_iTotalSeconds( 0 ){};
	
	/**
	 @param iTotalSeconds [in]
		�b�����w�肵�Ă��������B
	 */
	CdDedJikan( int iTotalSeconds ) : m_iTotalSeconds( iTotalSeconds ){};
	
	/**
		���F���F�b���w�肵�āA���Ԃ����������܂��B
	 @param iSign [in]
		�������w�肵�Ă��������B
		-	1 ;	//	���̐�
		-	0 ;	//	�[��
		-	-1 ;	//	���̐�
	 @param iHour [in]
		���B�͈͂� 0 �ȏ� �B
	 @param iMinute [in]
		���B�͈͂� 0 �ȏ� 60 �����B
	 @param iSecond [in]
		�b�B�͈͂� 0 �ȏ� 60 �����B
	
		���̐���ݒ肷��ꍇ�́A iSign �� -1 ���w�肵�A
		iHour , iMinute , iSecond �ɂ͐��̐����w�肵�Ă��������B
		
	 (��)
	
		�u�Q���ԑO�v��ݒ肷��ꍇ�́A	\n
		CdDedJikan( -1 , 2 , 0 , 0 ) 
		\n�ƂȂ�܂��B
	
		�u�Q���Ԍ�v��ݒ肷��ꍇ�́A	\n
		CdDedJikan( +1 , 2 , 0 , 0 ) 
		\n�ƂȂ�܂��B
		
	 */
	CdDedJikan( int iSign , int iHour , int iMinute , int iSecond = 0 ) ;

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
	CdDedJikan( const std::string& strTime ) ;

public:
	// ********************************
	//	CdDedJikan
	// ********************************
	// ********************************
	///@name CdDedJikan-����
	// ********************************
	///@{
	int getTotalSeconds()const{	return m_iTotalSeconds ; } ;
	CdDedJikan& setTotalSeconds( int value ){
		m_iTotalSeconds = value ;
		return ( *this ) ;
	};
	
	/** 
	 @return
		m_iTotalSeconds ��Ԃ��܂��B 
	 */
	operator int()const{	return getTotalSeconds() ; } ;
	
	/**
	 @return
		�l�̕�����Ԃ��܂��B
		-	1 ;	//	���̐�
		-	0 ;	//	�[��
		-	-1 ;	//	���̐�
	 */
	int getSign()const{	return sign( m_iTotalSeconds ) ; } ;
	
	/**
	 @return
		���B�l��0�ȏ�B
	 @attention
		this �����̐��̏ꍇ�ł��A���̒l�͐��i��Βl�j�ł��B
	 */
	int getHour()const{	return abs( m_iTotalSeconds / ( 60 * 60 ) ) ; } ;
	
	/**
	 @return
		���B
	 @attention
		this �����̐��̏ꍇ�ł��A���̒l�͐��i��Βl�j�ł��B
	 */
	int getMinute()const{	return abs( m_iTotalSeconds / ( 60 ) % ( 60 ) ) ; } ;
	
	/**
	 @return
		�b�B
	 @attention
		this �����̐��̏ꍇ�ł��A���̒l�͐��i��Βl�j�ł��B
	 */
	int getSecond()const{	return abs( m_iTotalSeconds % ( 60 ) ) ; } ;
	
	/**
		���Ԃ��A�ݒ肵�܂��B
	 @param iSign [in]
		�������w�肵�Ă��������B
		-	1 ;	//	���̐�
		-	0 ;	//	�[��
		-	-1 ;	//	���̐�
	 @param iHour [in]
		���B�͈͂� 0 �ȏ� �B
	 @param iMinute [in]
		���B�͈͂� 0 �ȏ� 60 �����B
	 @param iSecond [in]
		�b�B�͈͂� 0 �ȏ� 60 �����B
	
		���̐���ݒ肷��ꍇ�́A iSign �� -1 ���w�肵�A
		iHour , iMinute , iSecond �ɂ͐��̐����w�肵�Ă��������B
		
	 */
	CdDedJikan& setTime( int iSign , 
		int iHour , int iMinute , int iSecond = 0 ) ;
	
	
	///@}
	
	// ********************************
	///@name CdDedJikan-����
	// ********************************
	///@{
	/**
		�Q�̎��Ԃ��A��r���܂��B
	 @param value [in]
		��r�Ώۂ̃I�u�W�F�N�g���w�肵�Ă��������B
	 @return
		this - value ���s�������ʂ̕�����Ԃ��܂��B
		-	+1 ;	//	this > value�B
		-	0 ;		//	this == value�B
		-	-1 ;	//	this < value�B
	 */
	int compare( const CdDedJikan& value )const ;
	
	/**	compare() �Ɠ����ł��B	 */
	bool operator>( const CdDedJikan& value )const{
		return ( compare( value ) == 1 ) ; } ;
	/**	compare() �Ɠ����ł��B	 */
	bool operator>=( const CdDedJikan& value )const{
		return ( compare( value ) != -1  ) ; } ;
	/**	compare() �Ɠ����ł��B	 */
	bool operator==( const CdDedJikan& value )const{
		return ( compare( value ) == 0 ) ; } ;
	/**	compare() �Ɠ����ł��B	 */
	bool operator<=( const CdDedJikan& value )const{
		return ( compare( value ) != 1  ) ; } ;
	/**	compare() �Ɠ����ł��B	 */
	bool operator<( const CdDedJikan& value )const{
		return ( compare( value ) == -1 ) ; } ;
	
	/**
		this ���ێ����Ă��鎞�Ԃɑ΂��āA�b�������Z���܂��B
	 @param value [in]
		���Z����b�����w�肵�Ă��������B
		���̐����w�肷�邱�Ƃ��ł��܂��B
	 */
	CdDedJikan& addSeconds( int value ) ;

	/** addSeconds() �Ɠ����ł� */
	CdDedJikan& operator+=( int value ) {
		return addSeconds( value ) ; } ;

	/** addSeconds() �Ɠ����ł��B
	
		this ���ێ����Ă��鎞�Ԃɑ΂��āA�b�������Z���܂��B
	 @param value [in]
		���Z����b�����w�肵�Ă��������B
	 */
	CdDedJikan& operator-=( int value ) {
		return addSeconds( -value ) ; } ;

	
	/**
		�Q�̎��Ԃ̍����A�b���ŕԂ��܂��B
	 @param value [in]
		��r�Ώۂ̃I�u�W�F�N�g���w�肵�Ă��������B
	 @return
		this - value ���s�������ʂ̕b����Ԃ��܂��B
		this < value �̏ꍇ�́A���̐���Ԃ��܂��B
	
	 */
	int subJikan( const CdDedJikan& value )const ;

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

} //namespace entDed

#endif /*CdDedJikan_h*/
