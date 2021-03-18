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
//	CconvDcdPosOnZone_PosOrgAndRate.h
// $Id: CconvDcdPosOnZone_PosOrgAndRate.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CconvDcdPosOnZone_PosOrgAndRate_h
#define  CconvDcdPosOnZone_PosOrgAndRate_h
#include "DcdCd\Pos\CdDcdZone.h"
#include "DcdCd\Pos\CconvDcdPosOnZone.h"
// ****************************************************************
//	CconvDcdPosOnZone_PosOrgAndRate
// ****************************************************************
/**
 @brief
	�y�T�v�z
	  �Q�̈ꎟ�����W�n�̊ԂŁA���W��ϊ����܂��B
	
	  ���̃N���X�́A���W�n Zone1 ��̍��W�l���A Zone2 ��̍��W�l��
	�ϊ����邱�Ƃ��ł��܂��B
	
	  ���W�n Zone1 �� Zone2 �́A
	  
      - m_posZone1Org �FDcdPos	Zone1�̎n�_
      - m_posZone2Org �FDcdPos	Zone2�̎n�_
      - m_dZone2PerZone1 �Fdouble Zone1�ł̍��W1�ɑΉ�����AZone2�ł̍��W
	 
	�ŕ\���܂��B

  �i��1�j���W�n���A
	-	m_posZone1Org = 0 
	-	m_posZone2Org = 0 
	-	m_dZone2PerZone1 = 2

	�ł���ꍇ�A����́A
	  �u���W�n Zone1 �̈ʒu 0 ��Zone2 �̈ʒu 0 �ƂȂ�B
	  ���̈ʒu����Ƃ��āAZone1�̋���1���AZone2�̋��� m_dZone2PerZone1 �ƂȂ�v
	���Ƃ��Ӗ����܂��B
	
	  ���̏�ԂŁA
	
	  Zone1��̈ʒu 5 �� Zone2 �ɕϊ�����ƁA 10 �ƂȂ�܂��B
	
	  �܂��AZone1 ��͈̔�(CdDcdZone){ Pos= 3 , Size=5 } ���A
	Zone2 �ɕϊ�����ƁA{ Pos=6 , Size=10 } �ƂȂ�܂��B
	
  �i��2�j���W�n���A
	-	m_posZone1Org = 5 
	-	m_posZone2Org = 0 
	-	m_dZone2PerZone1 = 2

	�ł���ꍇ�A����́A
	  �u���W�n Zone1 �̈ʒu 0 ��Zone2 �̈ʒu 0 �ƂȂ�B
	  ���̈ʒu����Ƃ��āAZone1�̋���1���AZone2�̋��� m_dZone2PerZone1 �ƂȂ�v
	���Ƃ��Ӗ����܂��B
	
	  ���̏�ԂŁA
	
	  Zone1��̈ʒu 5 �� Zone2 �ɕϊ�����ƁA 0 �ƂȂ�܂��B
	
	  �܂��AZone1 ��͈̔�(CdDcdZone){ Pos= 3 , Size=5 } ���A
	Zone2 �ɕϊ�����ƁA{ Pos=-4 , Size=10 } �ƂȂ�܂��B

@ref cconvdcdposonzone_posorgandrate_towindowscroll

@ref cconvdcdposonzone_posorgandrate 
 
 */
class CconvDcdPosOnZone_PosOrgAndRate : public CconvDcdPosOnZone
{
 private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		���W�n Zone1 �̎n�_�B����l=0
	 */
	DcdPos	m_posZone1Org ;
	
	/**
		���W�n Zone2�̎n�_�B����l=0
	 */
	DcdPos	m_posZone2Org ;

	/**
    	 Zone1�ł̍��W1�ɑΉ�����AZone2�ł̍��W�B
		0 ���w�肵���ꍇ�̓���́A�ʂ̃��\�b�h�̐������Q�Ƃ��Ă��������B
		����l=1
	*/
	double m_dZone2PerZone1 ;
	///@}
 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	@param posZone1Org [in]
		���W�n Zone1 �̎n�_�B
	@param posZone2Org [in]
		���W�n Zone2�̎n�_
	@param dZone2PerZone1 [in]
    	 Zone1�ł̍��W1�ɑΉ�����AZone2�ł̍��W
		0 ���w�肵�Ȃ��ł��������i�[������Z�ɂȂ�܂��j�B
	*/
	CconvDcdPosOnZone_PosOrgAndRate( 
		DcdPos	posZone1Org , 
		DcdPos	posZone2Org ,
		double dZone2PerZone1 ) ;

	/**
	 ���̃R���X�g���N�^�́A����������l�ɏ��������܂��B
	 */
	CconvDcdPosOnZone_PosOrgAndRate() ;

	virtual ~CconvDcdPosOnZone_PosOrgAndRate() ;

 public:
	// ********************************
	///@name CconvDcdPosOnZone_PosOrgAndRate-����
	// ********************************
	///@{
	/**
		���W�n Zone1 �̎n�_�B����l=0
	 */
	DcdPos	getZone1Org()const{	return m_posZone1Org ;};
	void setZone1Org( DcdPos value )
	{	m_posZone1Org = value ;};
	DcdPos	getZone2Org()const{	return m_posZone2Org ;};
	void setZone2Org( DcdPos value )
	{	m_posZone2Org = value ;};
	double getZone2PerZone1()const{	return m_dZone2PerZone1 ;};
	void setZone2PerZone1( double value )
	{	m_dZone2PerZone1 = value ;};
	///@}
	
	// ********************************
	///@name CconvDcdPosOnZone-����
	// ********************************
	///@{
	/**
		Zone1 �̍��W�n
		�ł̈ʒu���A
		Zone2 �̍��W�n
		�ɕϊ����܂��B
	 @param value [in]
		�ϊ��O�̒l���w�肵�ĉ������B
	 @return
		�ϊ���̒l��Ԃ��܂��B
		
		m_dZone2PerZone1=0�̏ꍇ�́Am_posZone2Org �ɂȂ�܂��B
	 */
	virtual DcdPos Zone1PosToZone2( DcdPos value )const ;
	
	/**
		Zone2 �̍��W�n
		�ł̈ʒu���A
		Zone1 �̍��W�n
		�ɕϊ����܂��B
	 @param value [in]
		�ϊ��O�̒l���w�肵�ĉ������B
	 @return
		�ϊ���̒l��Ԃ��܂��B
		m_dZone2PerZone1=0�̏ꍇ�́Am_posZone1Org �ɂȂ�܂��B
	 */
	virtual DcdPos Zone1PosFromZone2( DcdPos value )const ;

	/**
		Zone1 �̍��W�n
		�ł͈̔͂��A
		Zone2 �̍��W�n
		�ɕϊ����܂��B
	 @param value [in]
		�ϊ��O�̒l���w�肵�ĉ������B
	 @return
		�ϊ���̒l��Ԃ��܂��B
		m_dZone2PerZone1=0�̏ꍇ�́ACdDcdZone(m_posZone1Org,0) �ɂȂ�܂��B
	 */
	virtual CdDcdZone Zone1ToZone2( const CdDcdZone& value )const ;
	
	/**
		Zone2 �̍��W�n
		�ł͈̔͂��A
		Zone1 �̍��W�n
		�ɕϊ����܂��B
	 @param value [in]
		�ϊ��O�̒l���w�肵�ĉ������B
	 @return
		�ϊ���̒l��Ԃ��܂��B
		m_dZone2PerZone1=0�̏ꍇ�́ACdDcdZone(m_posZone2Org,0) �ɂȂ�܂��B
	 */
	virtual CdDcdZone Zone1FromZone2( const CdDcdZone& value )const ;
	///@}
	
	
};


/**
@page cconvdcdposonzone_posorgandrate_towindowscroll CconvDcdPosOnZone_PosOrgAndRate ���g�����X�N���[���\�E�C���h�E�ւ̍��W�ϊ�

�@CconvDcdPosOnZone_PosOrgAndRate ���g���āA�h�L�������g�S�̂̍��W���A
�X�N���[���\�ȃE�C���h�E�̏�̍��W�ɕϊ����邱�Ƃ��ł��܂��B

	- Zone1=�h�L�������g�S�̂̍��W�n
	- Zone2=�E�C���h�E��̍��W�n

(1)�@�ȉ��̂悤�ɑ�����ݒ肵�Ă��������B

	- Zone1Org=�E�C���h�E��ō���ɕ\������A�h�L�������g�̍��W�B
	- Zone2PerZone1=�E�C���h�E��ł̕\���{���B2�Ȃ�A�h�L�������g��1�̒������A
		�E�C���h�E��2�h�b�g�ɕ\�����܂��B
	- Zone2Org=�E�C���h�E�̍���̍��W�B

(2)Zone1PosToZone2,Zone1ToZone2 �ŁA�h�L�������g���W���E�C���h�E��̍��W��
�ϊ��ł��܂��B

*/


#endif /*CconvDcdPosOnZone_PosOrgAndRate_h*/
