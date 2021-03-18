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
//	CconvDcdPosOnZone_DcdZone.h
// ****************************************************************
*/
/** @file */
#ifndef  CconvDcdPosOnZone_DcdZone_h
#define  CconvDcdPosOnZone_DcdZone_h
#include "DcdCd\Pos\CdDcdZone.h"
#include "DcdCd\Pos\CconvDcdPosOnZone.h"

namespace DcDrawLib{
namespace DcdCd{
namespace Pos{


// ****************************************************************
//	CconvDcdPosOnZone_DcdZone
// ****************************************************************
/**
 @brief
	�y�T�v�z
	  �Q�̈ꎟ�����W�n�̊ԂŁA���W��ϊ����܂��B
	
	  ���̃N���X�́A���W�n Zone1 ��̍��W�l���A Zone2 ��̍��W�l��
	�ϊ����邱�Ƃ��ł��܂��B
	
	  ���W�n Zone1 �� Zone2 �́A CdDcdZone �^�̑��� m_Zone1,m_Zone2 �Ƃ���
	�\���܂��B
	  m_Zone1,m_Zone2 �́A�����w��͈́x�� 
	���W�n Zone1 �E ���W�n Zone2 �ŕ\�������W�l�ł��B
	
	  �i��j
	
	  ���W�n���A
	
	-	m_Zone1 = { Pos=0 , Size=10 }
	-	m_Zone2 = { Pos=0 , Size=20 }
	
	�ł���ꍇ�A����́A
	  �u���W�n Zone1 �ł͈̔� { Pos=0 , Size=10 } �́A
	���W�n Zone2 �ł� { Pos=0 , Size=20 } �ƂȂ�v���Ƃ��Ӗ����܂��B
	
	  ���̏�ԂŁA
	
	  Zone1��̈ʒu 5 �� Zone2 �ɕϊ�����ƁA 10 �ƂȂ�܂��B
	
	  �܂��AZone1 ��͈̔�(CdDcdZone){ Pos= 3 , Size=5 } ���A
	Zone2 �ɕϊ�����ƁA{ Pos=6 , Size=10 } �ƂȂ�܂��B
	
 */
class CconvDcdPosOnZone_DcdZone : public CconvDcdPosOnZone
{
 private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		���W�n Zone1 �ł́A�w��͈́x�̍��W�l�B
	 */
	CdDcdZone	m_Zone1 ;
	
	/**
		���W�n Zone2 �ł́A�w��͈́x�̍��W�l�B
	 */
	CdDcdZone	m_Zone2 ;
	
	///@}
 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	 @param aZone1 [in]
		���W�n Zone1 �ł́A�w��͈́x�̍��W�l�B\n
		Size �ɂ́A 0 ���w�肵�Ȃ��ł��������i�[������Z�ɂȂ�܂��j�B
	 @param aZone2 [in]
		���W�n Zone2 �ł́A�w��͈́x�̍��W�l�B\n
		Size �ɂ́A 0 ���w�肵�Ȃ��ł��������i�[������Z�ɂȂ�܂��j�B
	 */
	CconvDcdPosOnZone_DcdZone( 
		const CdDcdZone& aZone1 ,
		const CdDcdZone& aZone2 ) ;

	/**
	 ���̃R���X�g���N�^�́A m_Zone1 , m_Zone2 �Ƃ��A
		Pos=0 , Size=1 �ɏ��������܂��B
	 */
	CconvDcdPosOnZone_DcdZone() ;

	virtual ~CconvDcdPosOnZone_DcdZone() ;

 public:
	// ********************************
	///@name CconvDcdPosOnZone_DcdZone-����
	// ********************************
	///@{
	CdDcdZone	getZone1()const ;
	CconvDcdPosOnZone_DcdZone& setZone1( const CdDcdZone& value ) ;
	CdDcdZone	getZone2()const ;
	CconvDcdPosOnZone_DcdZone& setZone2( const CdDcdZone& value ) ;
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
		m_Zone1.getSize()=0�̏ꍇ�́Am_posZone2Org �ɂȂ�܂��B
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
		m_Zone2.getSize()=0�̏ꍇ�́Am_posZone1Org �ɂȂ�܂��B
	 */
	virtual DcdPos Zone1PosFromZone2( DcdPos value )const ;


	///@}
	
	
};

} //namespace Pos
} //namespace DcdCd
} //namespace DcDrawLib




#endif /*CconvDcdPosOnZone_DcdZone_h*/
