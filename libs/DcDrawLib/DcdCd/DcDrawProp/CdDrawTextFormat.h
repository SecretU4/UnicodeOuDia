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
//****************************************************************
//	CdDrawTextFormat.h
//****************************************************************
*/
/** @file */
#ifndef  CdDrawTextFormat_h
#define  CdDrawTextFormat_h

namespace DcDrawLib{
namespace DcdCd{
namespace DcDrawProp{

// ****************************************************************
//	CdDrawTextFormat
// ****************************************************************
/**
 @brief
  �e�L�X�g�`��̌`�����w�肷��A�f�[�^�N���X�ł��B

  ���̃N���X�́A�v���b�g�t�H�[���Ɉˑ����܂���B
*/
class CdDrawTextFormat
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	/**	�������̃e�L�X�g�z�u	*/
	enum EHolizontal
	{
		/**	����(����l)	*/
		H_LEFT ,				//	DT_LEFT 
		/**	������	*/
		H_CENTER ,				//	DT_CENTER , 
		/**	�E��	*/
		H_RIGHT ,				//	DT_RIGHT
	};
	
	/**	�c�����̃e�L�X�g�z�u	*/
	enum EVertical
	{
		/**	�P��s�ŁA���	*/
		V_SINGLELINT_TOP ,		//	DT_SINGLELINE | DT_TOP
		
		/**	�P��s�ŁA����(����l)	*/
		V_SINGLELINT_CENTER ,	//	DT_SINGLELINE | DT_VCENTER�@(
		
		/**	�P��s�ŁA����	*/
		V_SINGLELINT_BOTTOM ,	//	DT_SINGLELINE | DT_BOTTOM
		
		/**	�����s				*/
		V_MULTILINE ,			//	0

		/**	�����s�ŁA�܂�Ԃ��͒P��̓r���ł��s���܂�	*/
		V_MULTILINE_WORDBREAK ,	//	DT_WORDBREAK
		
		/**	
			�����s�ŁA�܂�Ԃ��͒P��̓r���ł��s���܂�
			�� DBCS�i�_�u���o�C�g�����Z�b�g�̕�����j�ŉ��s�����̂�h
			���܂��B���̂��߁A���s�K���� SBCS ������Ɠ����ɂȂ�܂��B
		*/
		V_NOFULLWIDTHCHARBREAK,	//	DT_WORDBREAK | DT_NOFULLWIDTHCHARBREAK
		
	};
	
	
	/**	�ȗ�����	*/
	enum EEllipses
	{
		/**	�ȗ��Ȃ�(����l)	*/
		NOELLIPSIS ,			//	0
		/**
		 	������̍Ō�̕����������`�̈�ɔ[�܂�؂�Ȃ��ꍇ�A
		 	�͂ݏo���������؂����A�����ɏȗ������i...�j���ǉ�����܂��B
		 	������̍Ō�ł͂Ȃ��ꏊ�ɂ���P�ꂪ�����`�̈悩��͂ݏo���ꍇ�́A
		 	�ȗ��L���Ȃ��Ő؂����܂��B 
		 */
		END_ELLIPSIS ,			//	DT_END_ELLIPSIS
		/**
		 	�w�肵�������`�̈�Ɏ��܂�悤�ɁA�K�v�ɉ����ăe�L�X�g�̓r����
		 	�ȗ����� (...) �ɒu�������܂��B�~�L���i\�j���܂܂�Ă���
		 	�e�L�X�g�̏ꍇ�A�Ō�̉~�L���̌��̃e�L�X�g���\�Ȍ���ێ�
		 	����܂��B 
		 */
		PATH_ELLIPSIS ,			//	DT_PATH_ELLIPSIS
		/**
		 	�����`�̈���ɔ[�܂�Ȃ�����������ꍇ�A�����؂����������ŁA
		 	�K���ȗ��L���i...�j��ǉ����܂��B 
		 */
		WORD_ELLIPSIS ,			//	DT_WORD_ELLIPSIS
	};
	
	
	/**	������/�E����	*/
	enum EReading
	{
		/**	������(����l)	*/
		R_LEFT			 ,		//	0
		/**	�E����	*/
		R_RIGHT ,					//	DT_RTLREADING
	};
	
	/**
	 �A���p�T���h�u&�v�̉����`��w���B

	 �A���p�T���h���j�[���j�b�N�v���t�B�N�X����(�����`��w��)�Ƃ���
	�������邩�ۂ����w�肵�܂��B
	���̋@�\�́A���j���[�e�L�X�g��`�悷��ꍇ�Ɏg�p���܂��B
	*/
	enum EAmpersand
	{
		/** & �����̂܂ܕ`�悵�܂��B(����l)  */
		EAmpersand_NoPrefix ,	//DT_NOPREFIX,
		
		/** 
		& �̎��� & �ȊO�̕���������ꍇ�A 
		& �͕`�悹���ɁA&�̎��̕����ɉ�����t�^���ĕ`�悵�܂��B

		& ��2�A�������ꍇ�A & �������Ȃ��ŕ`�悵�܂��B
		*/
		EAmpersand_NormalPrefix ,	//	0

	};
// ********************************
///@name	����
// ********************************
///@{
 private:
	/**	
	�������̃e�L�X�g�z�u�B
	����l��H_LEFT(����)
	*/
	EHolizontal	m_eHolizontal ;
	
	/**	
	�c�����̃e�L�X�g�z�u�B
	����l�� V_SINGLELINT_CENTER (�P��s�ŁA����)
	*/
	EVertical	m_eVertical ;

	/**	
	�ȗ������B	
	����l�́ANOELLIPSIS �ȗ��Ȃ�(����l)
	*/
	EEllipses	m_eEllipses ;

	/**	
	������/�E�����B
	����l�� R_LEFT	(������)
	*/
	EReading	m_eReading ;

	/**
	�A���p�T���h�u&�v�̉����`��w���B
	����l�� EAmpersand_NoPrefix 
	*/
	EAmpersand m_eAmpresand ;

	
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
		�e������ݒ肷��R���X�g���N�^�ł��B
	 */
	CdDrawTextFormat( 
		EHolizontal eHolizontal = H_LEFT ,
		EVertical eVertical = V_SINGLELINT_CENTER,
		EEllipses eEllipse = NOELLIPSIS ,
		EReading eReading = R_LEFT ,
		EAmpersand eAmpresand = EAmpersand_NoPrefix ) :
		m_eHolizontal( eHolizontal ) ,
		m_eVertical( eVertical ) ,
		m_eEllipses( eEllipse ) ,
		m_eReading( eReading ) ,
		m_eAmpresand( eAmpresand ) {} ;
		

// ********************************
//	CdDrawTextFormat
// ********************************
 public:
	EHolizontal getHorizontal()const 
	{	return m_eHolizontal ;};
	CdDrawTextFormat& setHorizontal( EHolizontal ev ) 
	{	m_eHolizontal = ev ;	return *this ;};
	EVertical getVertical()const 
	{	return m_eVertical ;};
	CdDrawTextFormat& setVertical( EVertical ev ) 
	{	m_eVertical = ev ;	return *this ;};
	EEllipses getEllipses()const 
	{	return m_eEllipses ;};
	CdDrawTextFormat& setEllipses( EEllipses ev ) 
	{	m_eEllipses = ev ;	return *this ;};
	
	
	EReading getReading()const{	return m_eReading ;};
	CdDrawTextFormat& setReading( EReading ev ) 
	{	m_eReading = ev ;	return *this ;};

	EAmpersand getAmpresand()const{	return m_eAmpresand ;};
	CdDrawTextFormat& setAmpersand( EAmpersand ev )
	{	m_eAmpresand = ev ;	return *this ;};


};

} //namespace DcDrawProp
} //namespace DcdCd
} //namespace DcDrawLib

#endif /*CdDrawTextFormat_h*/

