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
//	CDcdFreeLine.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdFreeLine_h
#define  CDcdFreeLine_h


#include "DcDraw/IfDcDraw.h"
#include "DcDraw/CdDcdFreeLineProp.h"

// ****************************************************************
//	CDcdFreeLine
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 * IfDcdTarget �Ŏw�肳�ꂽ�̈���́A�����Ŏw�肳�ꂽ�Q�̍��W�̊ԂɁA
 * ������`�悵�܂��B
 * 
 * 	���̃N���X�́A IfDcdTarget::getZone() �̗̈�O�ւ̐��̕`���
 *	�N���b�v���܂��B
 * 
 * ���̃N���X�ł́A���̃X�^�C���E�F�́A CDcdFreeLine::CdLineProp ��
 * �w�肵�܂��B
 * ���̃N���X�́A���̃X�^�C���Ƃ��āA�ʏ�� Win32 �̃y���ł̓T�|�[�g
 * ����Ȃ��u�����̔j���v�u�����̓_���v�Ȃǂ̕`�悪�ł��܂��B
 * 
 */
class CDcdFreeLine : public IfDcDraw
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:

// ********************************
///@name	����
// ********************************
///@{
 private:
	/**
	 *	�N�_�̍��W�B
	 */
	CdDcdPosXy	m_posOrg ;
	/**
	 *	�I�_�̍��W�B
	 */
	CdDcdPosXy	m_posDst ;
	
	/**
	 *	�P���f�[�^�N���X�ł��B���̌`��ƐF�̑�����ێ����܂��B
	 */
	CdDcdFreeLineProp	m_CdLineProp ;
	
	/**
	 *	DcdTarget�͈̔͂ɁA�N�_�ƏI�_��␳����w��ł��B
	 *
	 *	���̑������^�Ȃ�A���̃N���X�� DcDraw() �́A
	 *	m_posOrg , m_posDst �� DcdTarget��Zone �̓����ɕ␳���Ă���
	 *	�`����s���܂��B
	 *
	 *	����ɂ��A�`��� DcdTarget �� Zone �͈̔͂ŃN���b�s���O
	 *	���邱�Ƃ��ł��܂����A�ʏ�͂��̕��@���g�킸�A
	 *	DC �ɃN���b�s���O�̈��ݒ肷��i CaDcdTargetClip ���g���j
	 *	�����ȒP�ł��B
	 *	
	 *	����l�� false �ł��B
	 */
	bool m_bAdjustForDcdTarget ;
	
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param posOrg [in]
	 *	�N�_�̍��W�B
	 * @param posDst [in]
	 *	�I�_�̍��W�B
	 * @param aCdLineProp [in]
	 *	�P���f�[�^�N���X�ł��B���̌`��ƐF�̑�����ێ����܂��B
	 */
	CDcdFreeLine( const CdDcdPosXy& posOrg , const CdDcdPosXy& posDst , 
		const CdDcdFreeLineProp& aCdLineProp ) :
		m_posOrg( posOrg ) , m_posDst( posDst ) ,
		m_CdLineProp( aCdLineProp ) , 
		m_bAdjustForDcdTarget( false ) {};
	/**
	 * @param aCdLineProp [in]
	 *	�P���f�[�^�N���X�ł��B���̌`��ƐF�̑�����ێ����܂��B
	 */
	CDcdFreeLine( const CdDcdFreeLineProp& aCdLineProp ) :
		m_CdLineProp( aCdLineProp ) , 
		m_bAdjustForDcdTarget( false ){};
	
	CDcdFreeLine() : 
		m_bAdjustForDcdTarget( false ){};

// ********************************
///@name	IfDcDraw
// ********************************
///@{
 public:
	/**
	 * 	�`���v�����܂��B
	 * 	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B
	 * @param pIfDcdTarget  [in]
	 * 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 * @return
	 * 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	 */
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	 * 	���̃I�u�W�F�N�g���`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 * 	���̑傫���𒲂ׂ邱�Ƃ��ł��܂��B
	 * 	�֐��Ăяo������������ IfDcDraw �I�u�W�F�N�g��`�悷��ꍇ�ɂ́A
	 * 	�֐��Ăяo�����́A���̊֐��ŃA�C�e���̑傫���𒲂ׂāA
	 * 	�K�؂ȃ��C�A�E�g���l���Ă���ADcDraw() �����s���邱�Ƃ��ł��܂��B
	 * @param pIfDcdTarget [in]
	 * 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 * @param pCdDcdSizeXy [out]
	 * 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 * 	���̊֐��͂��̃A�h���X�ɁA���̃A�C�e���̃T�C�Y��Ԃ��܂��B
	 * 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��Ȃ��ꍇ�́A
	 * 	���̒l�͕s��ł��B
	 * @return
	 * 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��āA
	 * 	���̑傫���� *pCdDcdSizeXy�ɏ������񂾏ꍇ�͐^�ł��B
	 * 	�����łȂ��ꍇ�́A�U�ł��B
	 *
	 * [�I�[�o���C�h]
	 *	  ���̋N�_�ƏI�_��\�� m_posOrg , m_posDst ���͂ޒ����`�̈�ɁA
	 *	�y���̑��������������̈��Ԃ��܂��B
	 */
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
///@}

// ********************************
//	CDcdFreeLine
// ********************************
 public:
	// ********************************
	///@name	����
	// ********************************
	///@{
	CdDcdPosXy	getOrg()const{	return 	m_posOrg ;};
	CDcdFreeLine& setOrg( const CdDcdPosXy& value ){
		m_posOrg = value ; return *this ; } ;
	CdDcdPosXy	getDst()const{	return m_posDst ;};
	CDcdFreeLine& setDst( const CdDcdPosXy& value ){
		m_posDst = value ; return *this ; } ;
	CdDcdFreeLineProp	getCdLineProp()const{	return m_CdLineProp ;};
	CDcdFreeLine& setCdLineProp( const CdDcdFreeLineProp& value ){
		m_CdLineProp = value ; return *this ; } ;
	bool getAdjustForDcdTarget()const{ return m_bAdjustForDcdTarget ;};
	CDcdFreeLine& setAdjustForDcdTarget( bool value ){
		m_bAdjustForDcdTarget = value ; return *this ; } ;
	///@}

};

#endif /*CDcdFreeLine_h*/


