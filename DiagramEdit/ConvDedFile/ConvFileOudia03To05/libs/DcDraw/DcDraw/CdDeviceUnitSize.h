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
//	./CdDeviceUnitSize.h
// ****************************************************************
*/
/** @file */
#ifndef  CdDeviceUnitSize_h
#define  CdDeviceUnitSize_h

#include <windows.h>

#include "./DcdType.h"

// ****************************************************************
//	CdDeviceUnitSize
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 * 	�f�o�C�X�P�ʁi�s�N�Z�����j�ł̃T�C�Y��ێ����܂��B
 *
 *	���̃N���X�́ADPI�i�C���`������̃s�N�Z�����j�̒l�����ƂɁA
 *
 *		�f�o�C�X�P�ʁ|�����P��
 *
 *	�̕ϊ����s���܂��B
 *	  �����P�ʂ́A�ȉ��̂��̂��T�|�[�g���܂��B
 *
 *	- �|�C���g(1�C���`=72�|�C���g)
 *	- Twip(�P�C���`=72*20 Twip)
 *	- 1/1000 �C���`
 *	- �C���`�i�����j
 *	- ��m(1/1000 mm)(�P�C���`��25.4mm)
 *	- �����i�����j(�P�C���`��25.4mm)
 *	
 *	�h���N���X�ƂȂ� CdDeviceUnitSizeX �E CdDeviceUnitSizeY �ł́A
 *	�f�o�C�X�P�ʁ|�_���P�� �̕ϊ����ł���悤�ɂȂ�܂��B\n
 *	�����P�ʁ|�_���P�ʂ̕ϊ��́A
 *
 *		�����P�ʁ|�f�o�C�X�P�ʁ|�_���P��
 *		
 *	�̂悤�ɁA��U�f�o�C�X�P�ʂ��o�R����Ή\�ł��B
 *
 * �y�g�����z
 *
 * �P�D  �R���X�g���N�^�ł́ADPI���w�肵�Ă��������B
 *
 * �Q�D  ����Ȍ�́A�P���f�[�^�N���X�Ɠ��l�̎g�������ł��܂��B
 *
 *	�ʏ�́A�h���N���X�ƂȂ� CdDeviceUnitSizeX �E CdDeviceUnitSizeY ��
 *	�g���܂��B
 */
class CdDeviceUnitSize
{
// ********************************
/// @name ����
// ********************************
///@{
 private:
	/**
	 *	DPI �̒l�i�P�C���`������̃s�N�Z�����j�ł��B
	 *
	 *	����͒ʏ�ADC�����Ƃ�
	 *	( GetDeviceCaps(LOGPIXELSX) , GetDeviceCaps(LOGPIXELSY) )
	 *	���肵�܂��B
	 *	�R���X�g���N�^�Ō��܂�܂��B
	 * @attention
	 *	���̒l�� 0 �ɂ��Ă���ƁA���R�[������Z�ɂȂ�܂��B
	 */
	int m_iDpi ;

	/**
	 * 	�f�o�C�X�P�ʂł̃T�C�Y�ł��B
	 */
	DcdSize	m_sizeDeviceUnitSize ;
///@}
	
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param iDpi [in]
	 *	DPI �̒l�ł��B\n
	 *	����͒ʏ�ADC�����Ƃ�
	 *	( GetDeviceCaps(LOGPIXELSX) , GetDeviceCaps(LOGPIXELSY) )
	 *	���肵�܂��B
	 * @param sizeDeviceUnitSize [in]
	 * 	�f�o�C�X�P�ʂł̃T�C�Y�ł��B
	 */
	CdDeviceUnitSize( 
		int iDpi ,
		DcdSize	sizeDeviceUnitSize = 0 ) :
		m_iDpi( iDpi ) ,
		m_sizeDeviceUnitSize( sizeDeviceUnitSize ){};
	
	virtual ~CdDeviceUnitSize(){};

// ********************************
//	CdDeviceUnitSize
// ********************************
 public:
	
	// ********************************
	///@name CdDeviceUnitSize-����
	// ********************************
	///@{
	int getDpi()const{	return m_iDpi ;};
	CdDeviceUnitSize& setDpi( int value ){	m_iDpi = value ; return *this ; } ;
	DcdSize	getDeviceUnitSize()const{	return m_sizeDeviceUnitSize ;	} ;
	CdDeviceUnitSize& setDeviceUnitSize( DcdSize value ){
		m_sizeDeviceUnitSize = value ;	return *this ;	} ;
	
	/** setDeviceUnitSize() �Ɠ����ł� */
	CdDeviceUnitSize& operator=( DcdSize value ){
		return setDeviceUnitSize( value ) ; } ;
	/** getDeviceUnitSize() �Ɠ����ł� */
	operator DcdSize()const{	return getDeviceUnitSize() ; } ;
	///@}

	// ********************************
	///@name CdDeviceUnitSize-����
	// ********************************
	///@{
	/**
	 * @return
	 * 	�|�C���g�P�ʂŁA�T�C�Y���擾���܂�
	 */
	DcdSize	getPointSize()const{
		return MulDiv( m_sizeDeviceUnitSize , 72 , m_iDpi ) ;
	};
	/**
	 * 	�|�C���g�P�ʂŁA�T�C�Y��ݒ肵�܂�
	 * @param value [in]
	 *	�|�C���g�P�ʂł̃T�C�Y���w�肵�Ă��������B
	 */
	CdDeviceUnitSize& setPointSize( DcdSize	value ){
		m_sizeDeviceUnitSize = MulDiv( value , m_iDpi ,72 ) ;	
		return *this ; } ;
	
	
	/**
	 * @return
	 * 	Twip�P�ʂŁA�T�C�Y���擾���܂�
	 */
	DcdSize	getTwipSize()const{
		return MulDiv( m_sizeDeviceUnitSize , 72*20 , m_iDpi ) ;
	};
	/**
	 * 	Twip �P�ʂŁA�T�C�Y��ݒ肵�܂�
	 * @param ev [in]
	 *	Twip�P�ʂł̃T�C�Y���w�肵�Ă��������B
	 */
	CdDeviceUnitSize& setTwipSize( DcdSize	value ){
		m_sizeDeviceUnitSize = MulDiv( value , m_iDpi , 72*20 ) ;
		return *this ; } ;
	
	/**
	 * @return
	 * 	1/1000 �C���`�P�ʂŁA�T�C�Y���擾���܂�
	 */
	DcdSize	getMilliInchSize()const{
		return MulDiv( m_sizeDeviceUnitSize , 1000 , m_iDpi ) ;
	};
	/**
	 * 	1/1000 �C���` �P�ʂŁA�T�C�Y��ݒ肵�܂�
	 * @param ev [in]
	 *	1/1000 �C���`�P�ʂł̃T�C�Y���w�肵�Ă��������B
	 */
	CdDeviceUnitSize& setMilliInchSize( DcdSize	value ){
		m_sizeDeviceUnitSize = MulDiv( value , m_iDpi , 1000 ) ;
		return *this ; } ;
	
	
	/**
	 * @return
	 * 	�ʂ��P�ʂŁA�T�C�Y���擾���܂�
	 */
	DcdSize	getMicroMetersSize()const{
		return MulDiv( m_sizeDeviceUnitSize , 25400 , m_iDpi ) ;
	};
	/**
	 * 	�ʂ� �P�ʂŁA�T�C�Y��ݒ肵�܂�
	 * @param ev [in]
	 *	�ʂ� �P�ʂł̃T�C�Y���w�肵�Ă��������B
	 */
	CdDeviceUnitSize& setMicroMetersSize( DcdSize	value ){
		m_sizeDeviceUnitSize = MulDiv( value , m_iDpi , 25400 ) ;
		return *this ; } ;
	
	/**
	 * @return
	 * 	�C���`�P�ʁi�����j�ŁA�T�C�Y���擾���܂�
	 */
	double	getInchSize()const{
		return (double)m_sizeDeviceUnitSize * 1 / m_iDpi ;
	};
	/**
	 * 	�C���` �P��(����)�ŁA�T�C�Y��ݒ肵�܂�
	 * @param ev [in]
	 *	�C���`�P�ʂł̃T�C�Y���w�肵�Ă��������B
	 */
	CdDeviceUnitSize& setInchSize( double value ){
		m_sizeDeviceUnitSize = (DcdSize)( value * m_iDpi / 1 ) ;
		return *this ; } ;
	
	
	/**
	 * @return
	 * 	�����P�ʁi�����j�ŁA�T�C�Y���擾���܂�
	 */
	double	getMmSize()const{
		return (double)m_sizeDeviceUnitSize * 25.4 / m_iDpi ;
	};
	/**
	 * 	���� �P�ʁi�����j�ŁA�T�C�Y��ݒ肵�܂�
	 * @param ev [in]
	 *	���� �P�ʂł̃T�C�Y���w�肵�Ă��������B
	 */
	CdDeviceUnitSize& setMmSize( double	value ){
		m_sizeDeviceUnitSize = (DcdSize)( value * m_iDpi / 25.4 ) ;
		return *this ; } ;
	
	
	///@}
};

#endif /*CdDeviceUnitSize_h*/
