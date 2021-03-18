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
//	CentDedDgrEkiJikoku.h
//	$Id: CentDedDgrEkijikoku.h 241 2016-01-05 06:14:33Z okm $
// ****************************************************************
*/
/** @file */
#ifndef CentDedDgrEkiJikoku_h
#define CentDedDgrEkiJikoku_h
#include "entDed\CentDedEkiJikoku.h"

namespace entDgr{
	using namespace entDed;
// ****************************************************************
//	CentDedDgrEkiJikoku
// ****************************************************************
/**
@brief 
  �_�C���O������ɂ�����A��Ԃ̊e�w�ł̉w������\���܂��B
  
  ���̃N���X�́A CentDedDgrRessya �ɏW�񂳂�܂��B

  CentDedDgrRessya : CentDedDgrEkiJikoku �̑��d�x�́A1 : �w�� �ł��B
*/
class CentDedDgrEkiJikoku
{
private:
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
		�w���B
	 */
	CentDedEkiJikoku::EEkiatsukai	m_eEkiatsukai ;
	
	/**
		�������ɑΉ�����_�C���O����X���W�B
		���̐��E24:00:00 �ȏ��\�����Ƃ�����܂��B

		�A���A INT_MIN ��NULL(�w��Ȃ�)��\���܂��B
	
		m_eEkiatsukai ��
		�^�s�Ȃ� ( Ekiatsukai_None ),
		�o�R�Ȃ� ( Ekiatsukai_Keiyunasi ) �̏ꍇ�́A
		���̒l�͈Ӗ��������܂���B
	 */
	int m_iDgrXPosChaku ;
	
	/**
		�������ɑΉ�����_�C���O����X���W�B

		�A���A INT_MIN ��NULL(�w��Ȃ�)��\���܂��B
	
		m_eEkiatsukai ��
		�^�s�Ȃ� ( Ekiatsukai_None ),
		�o�R�Ȃ� ( Ekiatsukai_Keiyunasi ) �̏ꍇ�́A
		���̒l�͈Ӗ��������܂���B
	 */
	int m_iDgrXPosHatsu ;
	
	
	/**
		�_�C���O������Ԑ���X���W

		���̉w�������_�C���O������Ԑ��̒��ԂɂȂ�ꍇ�́A
		�_�C���O������Ԑ��ƁA���̉w(��Y���W�E����)�Ƃ̌�_��
		�_�C���O����X���W��ێ����܂��B
		�����łȂ��ꍇ�́AINT_MIN �ł��B
		INT_MIN ��NULL(�w��Ȃ�)��\���܂��B

		���̐��E24:00:00 �ȏ��\�����Ƃ�����܂��B
		
		
		���̉w�������_�C���O������Ԑ��̒[�_�ɂ���ꍇ���A
		���̒l�� NULL �ɂȂ�܂��B

		m_eEkiatsukai ��
		�^�s�Ȃ� ( Ekiatsukai_None ),
		�o�R�Ȃ� ( Ekiatsukai_Keiyunasi ) �̏ꍇ�́A
		���̒l�͈Ӗ��������܂���B
		
		(��j
		
		�O�w����̉w�ԍŏ����v�������ȉ��̂Ƃ���̘H�����������Ƃ��܂��B

		@code
		-------------------
		�wOrder0 �� 
		�wOrder1 �� 01
		�wOrder2 �� 01
		-------------------
		@endcode

		�����Ɉȉ��̂悤�ȗ�Ԃ��ݒ肳��A��Ԑ����wOrder0-�wOrder2��
		�ݒ肳�ꂽ�ꍇ�A

		@code
		-------------------
		�wOrder0 �� 10:00
		�wOrder1 �� 10:01
		�wOrder2 �� 10:03
		-------------------
		@endcode

		�wOrder1�� m_iDgrXPosRessyasen �́A 10:01:30
		(10:00�`10:03�����Ԓ����� �wOrder1 �̌�_)
		�ɂȂ�܂��B
		
	 */
	int m_iDgrXPosRessyasen ;


	/**
		���̉w�����̈ʒu�ɗ�ԏ��(��Ԕԍ��E��Ԗ��E����)��
		�`�悷��K�v������Ȃ� true �B

		����� false �ł����A CentDedDgrRessya::readCentDedRessya() 
		�ɂ���Đݒ肳��܂��B
	*/
	bool m_bShouldRessyajouhouDraw ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CentDedDgrEkiJikoku() :
		m_eEkiatsukai( CentDedEkiJikoku::Ekiatsukai_None ),
		m_iDgrXPosChaku( INT_MIN ) ,
		m_iDgrXPosHatsu( INT_MIN ) ,
		m_iDgrXPosRessyasen( INT_MIN ) ,
		m_bShouldRessyajouhouDraw( false )
	{
	}
	
	CentDedDgrEkiJikoku( 
		CentDedEkiJikoku::EEkiatsukai eEkiatsukai , 
		int iDgrXPosChaku ,
		int iDgrXPosHatsu ,
		int iDgrXPosRessyasen = INT_MIN ) :
		m_eEkiatsukai( eEkiatsukai ),
		m_iDgrXPosChaku( iDgrXPosChaku ) ,
		m_iDgrXPosHatsu( iDgrXPosHatsu ) ,
		m_iDgrXPosRessyasen( iDgrXPosRessyasen ),
		m_bShouldRessyajouhouDraw( false )
	{
	}

public:
	// ********************************
	///@name CentDedDgrEkiJikoku-����
	// ********************************
	///@{
	CentDedEkiJikoku::EEkiatsukai getEkiatsukai()const 
	{	return 	m_eEkiatsukai ;};
	
	/**
		�������� X���W �ł��B
	@param bHatsuIfNull [in]
		-	false ;	//	��������NULL�Ȃ� NULL(INT_MIX) ��Ԃ��܂��B
		-	true  ;	//	��������NULL�Ȃ� ������(INT_MIX) ��Ԃ��܂��B
	*/
	int getDgrXPosChaku( bool bHatsuIfNull = false )const
	{
		int iRv = m_iDgrXPosChaku ;
		if ( iRv == INT_MIN && bHatsuIfNull )
		{
			iRv = m_iDgrXPosHatsu ;
		}
		return iRv ;
	};
	void setDgrXPosChaku( int value )
	{	m_iDgrXPosChaku = value ;};

	/**
		�������� X���W �ł��B
	@param bChakuIfNull [in]
		-	false ;	//	��������NULL�Ȃ� NULL(INT_MIX) ��Ԃ��܂��B
		-	true  ;	//	��������NULL�Ȃ� ������(INT_MIX) ��Ԃ��܂��B
	*/
	int getDgrXPosHatsu( bool bChakuIfNull = false )const
	{
		int iRv = m_iDgrXPosHatsu ;
		if ( iRv == INT_MIN && bChakuIfNull )
		{
			iRv = m_iDgrXPosChaku ;
		}
		return iRv ;
	};
	void setDgrXPosHatsu( int value )
	{	m_iDgrXPosHatsu = value ;};

	int getDgrXPosRessyasen()const
	{	return m_iDgrXPosRessyasen ;};
	void setDgrXPosRessyasen( int value )
	{	m_iDgrXPosRessyasen = value ; };

	bool getShouldRessyajouhouDraw()const
	{	return m_bShouldRessyajouhouDraw ;};
	void setShouldRessyajouhouDraw( bool value )
	{	m_bShouldRessyajouhouDraw = value ;};

	///@}
	// ********************************
	///@name CentDedDgrEkiJikoku-����
	// ********************************
	///@{
	/**
		���ׂẮw�_�C���O�����w�����x�I�u�W�F�N�g��
		�w�_�C���O�����G���e�B�e�BX���W�x�����Z�E���Z���܂�(NULL������ INT_MIN �͏����B
	 @param iSeconds [in]
		���Z�E���Z����l�i�b���E�w�_�C���O�����G���e�B�e�BX���W�x�j	
		���w�肵�ĉ������B
	 */
	virtual void modifyDgrXPos( int iSeconds ) 
	{
		if ( m_iDgrXPosChaku != INT_MIN )
		{
			m_iDgrXPosChaku += iSeconds ;
		}
		if ( m_iDgrXPosHatsu != INT_MIN )
		{
			m_iDgrXPosHatsu += iSeconds ;
		}
		if ( m_iDgrXPosRessyasen != INT_MIN )
		{
			m_iDgrXPosRessyasen += iSeconds ;
		}
	}
	///@}
};


} //namespace entDgr

#endif /*CentDedDgrEkiJikoku_h*/


