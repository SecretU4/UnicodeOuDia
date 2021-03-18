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
//	CentDedRessya_EkijikokuModifyOperation2.h
// ****************************************************************
#ifndef  CentDedRessya_EkijikokuModifyOperation2_h
#define  CentDedRessya_EkijikokuModifyOperation2_h
/** @file */

#include "CentDedRessya.h"

namespace entDed{

// ****************************************************************
//	CentDedRessya_EkijikokuModifyOperation2
// ****************************************************************
/**
 * @brief
 *	��Ԃɑ΂���w�w�����̕ύX�x����̓��e�ł��B
 *
 *	���̃N���X�̃I�u�W�F�N�g�Ɂw�w�����̕ύX�x�̓��e��ݒ肵��
 *	CentDedRessya_EkijikokuModifyOperation2::execute() �����s���邱�Ƃɂ��A
 *	�w�����̕ύX�����s���邱�Ƃ��ł��܂��B
 */
class CentDedRessya_EkijikokuModifyOperation2
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	/**
	 	�w�����ɑ΂��鑀��̓��e��\���񋓂ł��B
	 */
	enum EOperation 
	{
		/**
			�w������ύX���܂���B
		*/
		OperationNop ,
		
		/**
			�w�����̌J�グ�E�J�����B
		
			�ύX�Ώۂ̉w�������A
			 m_iSeconds �b�J�����܂��i���̐��Ȃ�
			�J�グ�ƂȂ�܂��j

			���̂Ƃ��A�ύX�Ώۂ̉w�����ȍ~�̎����͌J�グ�E�J������
			�Ȃ�܂��B
		*/
		OperationModify ,
		/**
			�w�����̃R�s�[�B
		
			�ύX�Ώۂ̉w�������A
			�w����Order�x��m_iJikokuOrderCopySrc �̎��� + m_iSeconds 
			�Ƃ��܂��B
		*/
		OperationCopy ,
		/**
		
			�ύX�Ώۂ̉w�������A
			�w��Ȃ��ɕύX���܂��B
		*/
		OperationToNull ,
	};
// ********************************
///@name	����
// ********************************
///@{
 private:
	/**
	 	�w����ύX���܂��B
	 	���̕ϐ��� true �̏ꍇ�A�w���̒l�́A m_eEkiatsukai �Ŏw�肵�܂��B
	 */
	bool m_bSetEkiatsukai ;
	/**
		�w��
	  @see m_bSetEkiatsukai ���Q�Ƃ��Ă��������B
	 
	 	m_bSetEkiatsukai ���U�̏ꍇ�́A���̕ϐ��͈Ӗ��������܂���B
	 */
	CentDedEkiJikoku::EEkiatsukai m_eEkiatsukai ;


	/**
		�����ύX�̕��@�B
	*/
	EOperation m_eOperation ;

	/**
		�w�����̌J�����E�������͉w�����̃R�s�[���̕b���B
	 @see m_eOperation
	*/
	int	m_iSeconds ;

	/**
		�w�����̃R�s�[�̏ꍇ�́A�R�s�[���̉w����Order�B
	 @see m_eOperation
	*/
	CdDedJikokuOrder m_iJikokuOrderCopySrc ;

///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	CentDedRessya_EkijikokuModifyOperation2() : 
		m_bSetEkiatsukai( false ) ,
		m_eEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ) ,
		m_eOperation( OperationNop ) , 
		m_iSeconds( 0 ) ,
		m_iJikokuOrderCopySrc( 0 , CdDedJikokuOrder::EkiJikokuItem_Chaku ){} ;
		
// ********************************
//	CentDedRessya_EkijikokuModifyOperation2
// ********************************
 public:
	// ********************************
	///@name CentDedRessya_EkijikokuModifyOperation2-����
	// ********************************
	///@{
	bool getSetEkiatsukai()const{ return m_bSetEkiatsukai ;};
	CentDedRessya_EkijikokuModifyOperation2& setSetEkiatsukai( bool value )
	{	m_bSetEkiatsukai = value ; return *this ; } ;
	CentDedEkiJikoku::EEkiatsukai getEkiatsukai()const
	{	return m_eEkiatsukai ; } ;
	CentDedRessya_EkijikokuModifyOperation2& setEkiatsukai( 
			CentDedEkiJikoku::EEkiatsukai value )
	{	m_eEkiatsukai = value ; return *this ; } ;

	EOperation getOperation()const{ return m_eOperation ;};
	CentDedRessya_EkijikokuModifyOperation2& setOperation( 
			EOperation value ){
		m_eOperation = value ; return *this ; } ;
	int getSeconds()const{ return m_iSeconds ;};
	CentDedRessya_EkijikokuModifyOperation2& setSeconds( int value )
	{	m_iSeconds = value ; return *this ; } ;
	CdDedJikokuOrder getJikokuOrderCopySrc()const{ return m_iJikokuOrderCopySrc ;};
	CentDedRessya_EkijikokuModifyOperation2& setJikokuOrderCopySrc( 
		const CdDedJikokuOrder& value )
	{	m_iJikokuOrderCopySrc = value ; return *this ; 	} ;

	/**
	@return
		- true:	this ��NULL��Ԃł��B
		
		NULL��Ԃ́A m_bSetEkiatsukai == false & m_eOperation == OperationNop
		�ł��邱�Ƃ������܂��B
	*/
	bool isNull()const{	return !m_bSetEkiatsukai && m_eOperation == OperationNop ;};

	/**
		this �� NULL ��Ԃɂ��܂��B
	*/
	void setNull(){	m_bSetEkiatsukai = false ;	m_eOperation = OperationNop ;};

	///@}
	// ********************************
	///@name CentDedRessya_EkijikokuModifyOperation2-����
	// ********************************
	///@{
	/**
		�w��́w��ԁx�ɑ΂��āA���̑������ێ����Ă���w�w�����̕ύX�x
		���s���܂��B
	
		���̂Ƃ��A�w�������x�E�w�������x���ύX���ꂽ��A
		�Ȍ�̉w���������ׂČJ�艺���܂��B
	
	
	 @param pCentDedRessya [in,out]
		���́w��ԁx�ɑ΂��āA���̑������ێ����Ă���w�w�����̕ύX�x
		���s���܂��B
	 @param aJikokuOrder [in]
		�w����Order�x���w�肵�Ă��������B
		�͈͂� 0 �ȏ� getCentEkiJikokuCount() * 2 �����ł��B
	 @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	aJikokuOrder ���͈͊O�ł��B
	*/
	virtual int execute( CentDedRessya* pCentDedRessya , CdDedJikokuOrder aJikokuOrder ) ;
	///@}
};

} //namespace entDed

#endif /*CentDedRessya_EkijikokuModifyOperation2_h*/
