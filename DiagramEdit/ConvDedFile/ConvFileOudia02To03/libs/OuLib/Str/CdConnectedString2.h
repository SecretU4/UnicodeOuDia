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
//	CdConnectedString2.h
// ****************************************************************
*/
/** @file */
#ifndef  CdConnectedString2_h
#define  CdConnectedString2_h

#include <string>
#include <deque>
#include <vector>

// ****************************************************************
//	CdConnectedString2
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
 * 	
 * 		�i��j"PROTOCOL=TCP;REMOTEIPADDR=192.168.0.1;REMOTEPORT=8001"
 * 	
 * 	���A�w�A��������x�B
 * 	
 * 	��؂蕶���ŋ�؂�ꂽ������P��
 * 	
 * 		�i��j\n
 *			"PROTOCOL=TCP"	\n
 * 			"REMOTEIPADDR=192.168.0.1"	\n
 * 			"REMOTEPORT=8001"
 * 	
 * 	���w�A�C�e���x
 * 	
 * 	�A�C�e������=�̍���
 * 		�i��j\n
 *			"PROTOCOL"			\n
 * 			"REMOTEIPADDR"		\n
 * 			"REMOTEPORT"
 *
 * 	���w���ږ��x
 *
 * 	�A�C�e������=�̉E��
 *
 * 		�i��j\n
 *			"TCP"				\n
 * 			"192.168.0.1"		\n
 * 			"8001"
 *
 * 	���w�l�x�ƌĂ�ł��܂��B
 * 	
 * 	���̃N���X�́A�A����������̃A�C�e����ҏW����@�\��A
 * 	�A�C�e�����̍��ږ��E�l��ҏW����@�\�������Ă��܂��B
 * 	
 *	 ���̃N���X�́A CdConnectedString �̏�ʃo�[�W�����ɂ�����܂��B
 *	CdConnectedString �ɁA�T�u�A�C�e���̕ҏW�@�\���ǉ�����Ă��܂��B
 * <H4> 	
 * �y�T�u�A�C�e���z
 * </H4> 	
 *
 *	  �A�C�e���́w���ږ��x�̂����A�擪���ɓ���̕���������A�C�e���́A
 *	��̃T�u�A�C�e���Ƃ��Ĉ������Ƃ��ł��܂��B
 *	
 *	  getSubitem() �֐��́Athis ���ێ�����A�C�e���̂����A���
 *	�T�u�A�C�e�����擾���āA�V���� CdConnectedString2 �I�u�W�F�N�g��
 *	�i�[���܂��B
 *
 * 	�i��j this �� "Items.name"�E"Items.value"�E"Attribute" �Ƃ���
 *	�w���ږ��x�̂R�̃A�C�e����ێ����Ă���Ƃ��ɁA
 *	���� strSubitemName �� "Items." ���w�肵�� getSubitem() ���Ăяo���ƁA
 * 	getSubitem() �֐��͐V���� CdConnectedString2 �I�u�W�F�N�g��
 *	"name"�E"value" �Ƃ����w���ږ��x�ŃA�C�e����ǉ����܂��B
 *	�i�w���ږ��x����́A strSubitemName �̕�������폜���܂��B�j
 */
class CdConnectedString2 
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	
	// ****************************************************************
	//	CdConnectedString2::CdItem
	// ****************************************************************
	/**
	* @brief
	* �y�T�v�z
	*	�A�C�e���P�̓��e��\���\���̂ł��B
	*/
	class CdItem
	{
	// ********************************
	///@name ����
	// ********************************
	 private:
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
		
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	 public:
		CdItem( const std::string& strName = "" , 
			const std::string& strValue = "" )
			: m_strName( strName ) , m_strValue( strValue )	{};
	
	// ********************************
	//	CdConnectedString2::CdItem
	// ********************************
	 public:
		// ********************************
		///@name ����
		// ********************************
		std::string	getName()const {	return m_strName ; };
		CdItem& setName( const std::string& value ){
			m_strName = value; return *this ; };
		std::string	getValue()const{	return m_strValue ;};
		CdItem& setValue( const std::string& value ){
			m_strValue = value ; return *this ; } ;
		
	};

	/** �A�C�e����ێ�����R���e�i�̌^��\���܂��B*/
	typedef std::deque<CdItem>	CdItemCont ;

// ********************************
///@name	����
// ********************************
///@{
 private:
	/**	�A�C�e���Ԃ̋�؂蕶���ł��B�f�t�H���g�� ";" �ł�	*/
	char		m_chSplit ;

	
	/**	���ڂƒl�̊Ԃ̋�؂蕶���ł��B�f�t�H���g�� "=" �ł� */
	char		m_chEqualChar ;

	/**	
	 *	�w�l�x�̂Ȃ��w�A�C�e���x�� encode() �ŏo�͂��邩�ۂ��̎w��ł��B
	 * - true ;	//	encode() �́A�w�l�x�̂Ȃ��w�A�C�e���x��
	 *			//	�o�͂��܂��i����l�j�B
	 * - false ;	//	encode() �́A�w�l�x�̂Ȃ��w�A�C�e���x��
	 *			//	�o�͂��܂���B
	 *
	 * @attention
	 *	���ׂẴA�C�e���ɂ��āA�w�l�x�̎擾����� getValue() �ōs���Ă���
	 *  �i�u�w���ږ��x�ɑΉ�����A�C�e�����Ȃ��ꍇ�v�ƁA
	 *	�u�w���ږ��x�ɑΉ�����A�C�e���͂��邪�w�l�x���󕶎���̏ꍇ�v��
	 *	���ꎋ���Ă���j�ꍇ�́A���̑����� false �ɂ��邱�Ƃ��ł��܂��B
	 *	���̏ꍇ�A encode() ���������镶����̃T�C�Y���팸���邱�Ƃ�
	 *	�ł��܂��B
	 */
	bool		m_bEncodeNoValue ;
	
// ********************************
///@name	���
// ********************************
///@{
 private:
	/**	�A�C�e����ێ�����R���e�i�ł��B */
	CdItemCont	m_contItem ;

///@}

// --------------------------------
///@name �����f�[�^
// --------------------------------
///@{
 private:
	/**
	 *	������Ԃł͋�̔z��ł��B
	 *
	 *	find() �֐��́A���̔z��ɁACdItem::m_strName �̎�����
	 *	�C���f�N�X���쐬���܂��B
	 *	
	 *	�i��j
	 *
	 *	- m_contItem[0].m_strName = "C" ;
	 *	- m_contItem[1].m_strName = "A" ;
	 *	- m_contItem[2].m_strName = "B" ;
	 *
	 *	�̂Ƃ��A���̔z��́A
	 *
	 *	- m_contiOrderIdx[0] = 1 ;	//m_contItem[1] ���������łP��
	 *	- m_contiOrderIdx[1] = 2 ;
	 *	- m_contiOrderIdx[2] = 0 ;	//m_contItem[0] ����������3��
	 *
	 *	�ƂȂ�܂��B
	 */
	mutable std::vector<int>	m_contiOrderIdx ;
///@}


// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param chSplit [in]
	 * 	�A�C�e���Ԃ̋�؂蕶�����w�肵�Ă��������B
	 * @param chEqualChar [in]
	 * 	���ڂƒl�̊Ԃ̋�؂蕶�����w�肵�Ă��������B
	 * @param bEncodeNoValue [in]	
	 *	�w�l�x�̂Ȃ��w�A�C�e���x�� encode() �ŏo�͂��邩�ۂ��̎w��ł��B
	 * - true ;	//	encode() �́A�w�l�x�̂Ȃ��w�A�C�e���x��
	 *			//	�o�͂��܂��i����l�j�B
	 * - false ;	//	encode() �́A�w�l�x�̂Ȃ��w�A�C�e���x��
	 *			//	�o�͂��܂���
	 */
	CdConnectedString2( char chSplit = ';' , char chEqualChar = '=' , 
		bool bEncodeNoValue = true ) ;
	
	/**
	 * @param ev [in]
	 * 	�A����������w�肵�Ă��������B
	 * @param chSplit [in]
	 * 	��؂蕶�����w�肵�Ă��������B
	 * @param chEqualChar [in]
	 * 	���ڂƒl�̊Ԃ̋�؂蕶�����w�肵�Ă��������B
	 */
	CdConnectedString2( const std::string& ev ,  char chSplit = ';' , 
		char chEqualChar = '=' , bool bEncodeNoValue = true ) ;
	
	virtual ~CdConnectedString2() ;

// ********************************
///@name	�R���e�i����
// ********************************
///@{
 public:
	/**
	 * @return
	 * 	�A�C�e���̐���Ԃ��܂��B
	 */
	int size()const ;
	
	/**
	 * 	�w��̈ʒu�ɂ���A�C�e�����Q�Ƃ��܂��B
	 * @param idx [in]
	 * 	�O�ȏ�size()�����̃C���f�N�X���w�肵�Ă��������B
	 *
	 * @return
	 * 	�A�C�e����Ԃ��܂��B
	 */
	const CdItem& at( int idx )const ;
	
	/**
	 * 	�w��̈ʒu�ɐV�����A�C�e����}�����܂��B
	 * @param idx [in]
	 * 	�O�ȏ�size()�ȉ��̃C���f�N�X���w�肵�Ă��������B
	 * 	INT_MAX �Ȃ�A�����ɒǉ����܂��B
	 * @param ev [in]
	 * 	�}������A�C�e�����w�肵�Ă��������B
	 * @return
	 * 	����������0�ȏ�A���s�����畉�̐��ł�
	 *	-	-1 ;	//	�C���f�N�X���͈͊O�ł��B
	 */
	int insert( const CdItem& ev , int idx = INT_MAX ) ;

	/**
	 * 	�w��̈ʒu����A�C�e�����������܂��B
	 * @param idx [in]
	 * 	�O�ȏ�size()�����̃C���f�N�X���w�肵�Ă��������B
	 * 	INT_MAX �Ȃ�A�����̂��̂��폜���܂��B
	 * @return
	 * 	����������0�ȏ�A���s�����畉�̐��ł�
	 */
	int erase( int idx = INT_MAX ) ;
	
	/**
	* 	�w��̈ʒu�̃A�C�e����u�������܂��B
	* @param idx [in]
	* 	�O�ȏ�size()�ȉ��̃C���f�N�X���w�肵�Ă��������B
	* 	INT_MAX �́A�����Ƃ݂Ȃ��܂��B
	* @param ev [in]
	* 	�}������A�C�e�����w�肵�Ă��������B
	* @return
	* 	����������0�ȏ�A���s�����畉�̐��ł�
	*/
	int modify( const CdItem& ev , int idx = INT_MAX ) ;

	/**
	* 	�w��̍��ږ������A�C�e���̈ʒu�𒲂ׂ܂�
	* @param strName [in]
	* 	���ږ����w�肵�Ă��������B
	* @return
	* 	����������0�ȏ�̃C���f�N�X�A������Ȃ����-1�ł�
	*/
	int find( std::string strName )const ;
	
	/**
	*	���ׂẴA�C�e����j�����܂��B
	*/
	void clear() ;
	
///@}

// ********************************
//	CdConnectedString���L
// ********************************
 public:
	// ********************************
	///@name	����
	// ********************************
	///@{
	char getSplit()const {	return ( m_chSplit ) ; } ;
	CdConnectedString2& setSplit( char chSplit ){
		m_chSplit = chSplit ; return ( *this ) ;} ;

	char getEqualChar()const{	return ( m_chEqualChar ) ; } ;
	CdConnectedString2& setEqualChar( char ev ){	
		m_chEqualChar = ev ; return ( *this ) ;} ;

	bool getEncodeNoValue()const{ return m_bEncodeNoValue ;};
	CdConnectedString2& setEncodeNoValue( bool value ){
		m_bEncodeNoValue = value ; return *this ; } ;
	///@}
	
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
	* 	�w��̍��ږ������A�C�e���̒l��Ԃ��܂��B
	* @param strName [in]
	* 	���ږ����w�肵�Ă��������B
	* @return
	* 	����������A�l��Ԃ��܂��B
	* 	���ڂ����݂��Ȃ��ꍇ�́A�󕶎����Ԃ��܂��B
	*/
	std::string getValue( std::string strName )const ;
	
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
	int setItem( const std::string& strName , const std::string& strValue ) ;


	/**
	* 	�w��̍��ږ������A�C�e�����폜���܂�
	* @param strName [in]
	* 	���ږ����w�肵�Ă��������B
	* @return
	* 	����������A�폜�����A�C�e���̌��X�������ʒu�̃C���f�N�X�A
	* 	������Ȃ����-1�ł�
	*/
	int remove( std::string strName ) ;

	/**
	* @return
	* 	���̃I�u�W�F�N�g���ێ����Ă���A�C�e���Ƌ�؂蕶�������ƂɁA
	* 	�A����������쐬���A�����Ԃ��܂��B
	*/
	std::string encode()const ;

	/**
	* 	�w��̘A����������A���̃I�u�W�F�N�g�Ɋi�[���܂��B
	* @param strEv [in]
	* 	�A����������w�肵�Ă��������B
	* @return
	* 	����������0�ȏ�A���s�����畉�̐��ł�
	*/
	int decode( const std::string&	strEv ) ;

	/**
	 * 	���� CdConnectedString ���ێ����Ă���
	 *	�A�C�e���i�����j���A�T�u�A�C�e���Ƃ��đ}�����܂��B
	 *
	 * @param strSubitemName [in]
	 * 	�T�u�A�C�e�������w�肵�Ă��������B
	 * @param aCdConnectedString [in]
	 * 	�T�u�A�C�e����ێ����Ă��� aCdConnectedString 
	 *	���w�肵�Ă��������B
	 * @return
	 * 	����������0�ȏ�A���s�����畉�̐��ł�
	 *
	 * 
	 *	<H4>
	 * �y����z
	 *	</H4>
	 *	�T�u�A�C�e���́w���ږ��x�́A
	 *	strSubitemName +  (aCdConnectedString���̃A�C�e���̍��ږ�)
	 *	�ƂȂ�܂��B
	 *	
	 * (��)	
	 *	
	 *	�w���ږ��x�� "Name" �E�w�l�x�� "Untitled" ��
	 *	�A�C�e���P��ێ�����
	 *	 CdConnectedString ������B
	 *	
	 *	���̊֐��ɁA��L�̃I�u�W�F�N�g�� aCdConnectedString �Ƃ��ēn���B
	 *	strSubitemName �ɂ� "Items." ���w��B
	 *
	 *	���̏ꍇ�A���̊֐��� this �ɁA 
	 *	�w���ږ��x�� "Items.Name" �E�w�l�x�� "Untitled" 
	 *	�A�C�e����ǉ����܂��B
	 *	
	 *	
	 */
	int setSubitem( const std::string& strSubitemName , 
		const CdConnectedString2& aCdConnectedString ) ;
	
	/**
	 * 	this ���ێ����Ă���A�C�e������A�T�u�A�C�e��
	 *	(�w���ږ��x���T�u�A�C�e�����Ŏn�܂鍀��)��
	 *	�I�����āA�w��� CdConnectedString 
	 *	�I�u�W�F�N�g�ɒǉ����܂��B
	 *
	 * @param strSubitemName [in]
	 * 	�T�u�A�C�e�������w�肵�Ă��������B
	 * @param pCdConnectedString [in,out]
	 * 	���̊֐��͂��̃I�u�W�F�N�g�ɁA�擾�����T�u�A�C�e����
	 *	�ǉ����܂��B
	 *	���̃I�u�W�F�N�g������܂ŕێ����Ă����A�C�e����
	 *	�������܂��B
	 * @return
	 * 	����������0�ȏ�A���s�����畉�̐��ł�
	 *
	 * 
	 *	<H4>
	 * �y����z
	 *	</H4>
	 *	�T�u�A�C�e���́w���ږ��x�́A
	 *	strSubitemName +  (aCdConnectedString���̃A�C�e���̍��ږ�)
	 *	�ƂȂ�܂��B
	 *	
	 * (��)	
	 *	
	 *	 this �ɁA 
	 *	�w���ږ��x�� "Items.Name" �E�w�l�x�� "Untitled" 
	 *	�̃A�C�e��������B
	 *	
	 *	���̊֐��ɁA
	 *	strSubitemName �� "Items." ���w�肵�Ă��̊֐����Ăяo���B
	 *
	 *	���̏ꍇ�A���̊֐��� pCdConnectedString �ɁA
	 *	�w���ږ��x�� "Name" �E�w�l�x�� "Untitled" 
	 *	�̃A�C�e����ǉ����܂��B
	 */
	int getSubitem( const std::string& strSubitemName , 
		CdConnectedString2* pCdConnectedString )const ;
	
	/**
	 * 	this ���ێ����Ă���A�C�e������A�T�u�A�C�e����
	 *	(�w���ږ��x���T�u�A�C�e�����Ŏn�܂鍀��)��
	 *	�폜���܂��B
	 * @param strSubitemName [in]
	 * 	�T�u�A�C�e�������w�肵�Ă��������B
	 * @return
	 * 	����������폜�����A�C�e���̐���Ԃ��܂�( 0 �ȏ�)�B
	 *	���s�����畉�̐��ł�
	 */
	int removeSubitem( const std::string& strSubitemName ) ;
	

	///@}
// ********************************
///@name	���Z�q
// ********************************
///@{
 public:
	/** encode() �Ɠ����ł� */
	operator std::string()const {	return encode() ;	};
///@}
};




#endif /*CdConnectedString_h*/

