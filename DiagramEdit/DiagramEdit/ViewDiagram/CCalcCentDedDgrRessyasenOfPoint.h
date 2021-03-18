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
//	CCalcCentDedDgrRessyasenOfPoint.h
// $Id: CCalcCentDedDgrRessyasenOfPoint.h 94 2012-09-29 12:11:37Z okm $
// ****************************************************************
*/
#ifndef  CCalcCentDedDgrRessyasenOfPoint_h
#define  CCalcCentDedDgrRessyasenOfPoint_h

/** @file */
#include "entDgr\CEnumRessyasen.h"
#include "ViewDiagram\CDcdDiagram.h"

namespace ViewDiagram{

// ****************************************************************
//	CCalcCentDedDgrRessyasenOfPoint
// ****************************************************************
/**
 @brief
	CDcdDiagram::calcCentDedDgrRessyasenOfPoint() �֐����ł̂�
	�g�p����N���X�ł��B
	�`��̈���́A�w�����Ώۓ_�x��ʂ��Ă����Ԑ��𒲂ׂ܂��B

	�y�g�����z
	
	�P�D  �R���X�g���N�^�ŁA�I�u�W�F�N�g�𐶐����Ă��������B
	�R���X�g���N�^�̈����ɂ́A��Ԑ��̏���ێ����Ă��� CDcdDiagram 
	�I�u�W�F�N�g�ƁA�`���� IfDcdTarget �I�u�W�F�N�g�E
	�w�����Ώۓ_�x���w�肵�Ă��������B
	
	�Q�D  execute() ���Ăяo���Ă��������B
	 execute() �́A�w�����Ώۓ_�x��ʂ��Ԑ�����������A
	���̏��𑮐�  m_eRessyahoukou , m_iRessyaIdx , m_iRessyasenIdx 
	�ɏ������݂܂��B

 */
class CCalcCentDedDgrRessyasenOfPoint : public CEnumRessyasen
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	typedef CEnumRessyasen	super ;

private:
	// ********************************
	///@name	�֘A
	// ********************************
	/**
		DcdGrid�̕`����s���I�u�W�F�N�g�B 
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this �̔j������������܂� 
		�������Ȃ��Ă͂Ȃ�܂���B
	*/
	CDcdDiagram*	m_pCDcdDiagram ;
	/**
		DcdGrid�̕`���B 
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this �̔j������������܂� 
		�������Ȃ��Ă͂Ȃ�܂���B
	*/
	IfDcdTarget*	m_pIfDcdTarget ;


private:
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
		�w�����Ώۓ_�x(DcDraw���W)
		 execute() �́A���̍��W��ʂ��Ԑ�����������A
		���̏���
		 m_eRessyahoukou , m_iRessyaIdx , m_iRessyasenIdx 
		�ɐݒ肵�܂��B
	 */
	CdDcdPosXy m_CdDcdPosXy ;
	/**
		�����Ώۓ_�Ɨ�Ԑ��̊Ԃ̋����̍ő�l(DcDraw���W)�B
		
		���̊֐��́Am_CdDcdPosXy �Ɨ�Ԑ��Ƃ̋�����
		���̃s�N�Z�����ȉ��ł���΁A
		�um_CdDcdPosXy ���Ԑ����ʂ��Ă���v�Ƃ݂Ȃ��܂��B
		0 �Ȃ�A��Ԑ������W�ʒu�����S�ɒʂ��Ă���ꍇ�̂�
		�Y����Ԑ��Ƃ݂Ȃ��܂��B
	 */
	int m_iMerginPixels ;
	/**
		�����l�͕s��B
		��Ԑ������������ꍇ�́A���̗�ԕ����B
	 */
	ERessyahoukou m_eRessyahoukou ;
	/**
		�����l�� -1 ;
		��Ԑ������������ꍇ�́A���̗��Index�B
	 */
	int m_iRessyaIdx ;
	/**
		�����l�� -1 �B
		��Ԑ������������ꍇ�́A���̗�Ԑ�Index�B
	 */
	int m_iRessyasenIdx ;
	///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 @param pCDcdDiagram [in]
		�O���� CDcdDiagram �I�u�W�F�N�g�Ƃ̊֘A�ł��B 
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		 ���̃I�u�W�F�N�g�́A this �̔j������������܂� 
		�������Ȃ��Ă͂Ȃ�܂���B 
	 @param pIfDcdTarget  [in] 
		�`���B 
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this �̔j������������܂� 
		�������Ȃ��Ă͂Ȃ�܂���B
	 @param aCdDcdPosXy [in]
		�����Ώۂ̍��W�B
		 execute() �́A���̍��W��ʂ��Ԑ�����������A
		���̏���
		 m_eRessyahoukou , m_iRessyaIdx , m_iRessyasenIdx 
		�ɐݒ肵�܂��B
	 @param iMerginPixels [in]
		�����Ώۓ_�Ɨ�Ԑ��̊Ԃ̋����̍ő�l�B
	 @param bDisplayRessyasenKudari [in]
		�����Ԃ̏������s�����ۂ����w�肵�܂��B
		- true ;	//	�����Ԃ̏������s���B
		- false ;	//	�����Ԃ̏������s��Ȃ��B
	 @param bDisplayRessyasenNobori [in]
		����Ԃ̏������s�����ۂ����w�肵�܂��B
	 */
	CCalcCentDedDgrRessyasenOfPoint( CDcdDiagram* pCDcdDiagram , 
		IfDcdTarget* pIfDcdTarget ,
		const CdDcdPosXy& aCdDcdPosXy , int iMarginPixels ,
		bool bDisplayRessyasenKudari , bool bDisplayRessyasenNobori ) ;

// ********************************
//	CDcdDiagram::CEnumRessyasen
// ********************************
 protected:
	/**
		execute() �� onCentDedDgrRessya() �̏��ŌĂяo�����
		�֐��ł��B
	
		execute() �́A�`��\�̈�ɂ���
		�w�_�C���O������Ԑ��x CentDedDgrRessyasen �I�u�W�F�N�g���ɁA
		���̊֐����Ăяo���܂��B
		
	 @param eRessyahoukou [in]
		��ԕ����ł��B
	 @param iRessyaIdx [in]
		��ԃC���f�N�X�ł��B
	 @param aCentDedDgrRessya [in]
		�w�_�C���O������ԁx CentDedDgrRessya �I�u�W�F�N�g���w�肵�܂��B
	 @param iRessyasenIdx [in]
		��Ԑ��C���f�N�X�ł��B
	 @param aCentDedDgrRessyasen [in]
		�w�_�C���O������Ԑ��x CentDedDgrRessyasen 
		�I�u�W�F�N�g���w�肵�܂��B
		
	 �y�I�[�o���C�h�z
		�_�C���O������Ԑ��� �����Ώۓ_ ��ʂ邩�𔻒肵�܂��B
		�ʂ��Ă���ꍇ�́A���̑�����
		 m_eRessyahoukou , m_iRessyaIdx , m_iRessyasenIdx 
		�ɐݒ肵�܂��B
	 */
	virtual void onCentDedDgrRessyasen( 
			ERessyahoukou eRessyahoukou ,
			int iRessyaIdx ,
			const CentDedDgrRessya* pCentDedDgrRessya ,
			int iRessyasenIdx ,
			const CentDedDgrRessyasen* pCentDedDgrRessyasen ) ;
// ********************************
//	CCalcCentDedDgrRessyasenOfPoint
// ********************************
 public:
	// ********************************
	///@name CCalcCentDedDgrRessyasenOfPoint-����
	// ********************************
	///@{
	ERessyahoukou getRessyahoukou()const{	return m_eRessyahoukou ;};
	int getRessyaIdx()const{ return m_iRessyaIdx ;};
	int getRessyasenIdx()const{ return m_iRessyasenIdx ;};
	///@}

};

} //namespace ViewDiagram

#endif //CCalcCentDedDgrRessyasenOfPoint_h
