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
//	CentDedDgrRessya.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrRessya_h
#define  CentDedDgrRessya_h

#include "NsMu\CMuiCopied.h"
#include "DcDraw\CDcdFreeLine.h"

#include "..\entDed\CentDedRosen.h"
#include "CentDedDgrEkiCont.h"
#include "CentDedDgrEkiJikoku.h"
#include "CentDedDgrRessyasen.h"
#include "CentDedDgrRessyasenCont.h"

namespace entDgr{

using namespace DcDrawLib::DcdCd::Pos;

class CentDedDgrDia ;

// ****************************************************************
//	CentDedDgrRessya
// ****************************************************************
/**
	@brief
	�y�T�v�z
	�w�_�C���O�����G���e�B�e�B�N���X�Q�x�́w�_�C���O������ԁx�N���X�ł��B
	�w��ԁx
	
	���̃N���X�́A
	 - �w�_�C���O������Ԑ��x(CentDedDgrRessyasen)
	
	�I�u�W�F�N�g���܂��܂��B

	�y�g�����z
	
	�P�D  �R���X�g���N�^�ŃI�u�W�F�N�g�𐶐�������A
	 readCentDedRessya() ���\�b�h�ŁA �w��ԁx CentDedRessya �I�u�W�F�N�g��
	���e��ǂݎ���Ă��������B
	  ���̊֐��́A�w��ԁx CentDedRessya �ɕ�܂���Ă���e�w��
	�w�w�����x CentDedEkiJikoku ��ǂݎ���āA
	�Ή�����w��Ԑ��x CentDedDgrRessyasen �I�u�W�F�N�g��
	�������A�R���e�i�Ɋi�[���܂��B

	�Q�D  �w�_�C���O������Ԑ��x��

	- ��Ԑ��N�_�w�̉wOrder
	- ��Ԑ��I�_�w�̉wOrder

	����A CentDedDgrDia::getYZahyouOfEki() �֐����g�����Ƃɂ��A

  - ��Ԑ��N�_�w�́w�_�C���O�����G���e�B�e�BY���W�x
  - ��Ԑ��I�_�w�́w�_�C���O�����G���e�B�e�BY���W�x

	�����߂邱�Ƃ��ł��܂��B
	�������Č��肵���N�_�w��X,Y ���W����I�_�w��X,Y���W�܂ł̒������A
	���̗�Ԃ̗�Ԑ��ɂȂ�܂��B
 */
class CentDedDgrRessya
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		���̗�Ԃ��wNull��ԁx�Ȃ�^�A
		�L���ȗ�ԑ�����ێ����Ă���̂Ȃ�U�ł��B
		
		���̑������^�̏ꍇ�A���̑S�Ă̑����E
		����сA�W��I�u�W�F�N�g�́A�Ӗ��������܂���B
		
		�R���X�g���N�^�� readCentDedRessya() �� CentDedRessya �����Ƃ�
		���܂�܂��B
	 */
	bool m_bIsNull ;

	/**
		���̗�Ԃ̗�ԕ����������܂��B
		
		�K��l�� Ressyahoukou_Kudari �ł��B
		
		�R���X�g���N�^�� readCentDedRessya() �� CentDedRessya �����Ƃ�
		���܂�܂��B
	 */
	ERessyahoukou	m_eRessyahoukou ;

	/**
		���̗�Ԃ́w��Ԏ�ʁx���A
		�w��Ԏ��Index�x�ŕێ����܂��B
		
		�K��l�� 0 �ł��B
	*/
	int	m_iRessyasyubetsuIndex ;
	
	
	/**
		���̗�Ԃ́w��Ԕԍ��x�B
		
		�K��l�͋󕶎���ł��B
		
		�R���X�g���N�^�� readCentDedRessya() �� CentDedRessya �����Ƃ�
		���܂�܂��B
	 */
	std::string m_strRessyabangou ;
	
	/**
		���̗�Ԃ́w��Ԗ��x�B
		
		�K��l�͋󕶎���ł��B
		
		�R���X�g���N�^�� readCentDedRessya() �� CentDedRessya �����Ƃ�
		���܂�܂��B
	 */
	std::string m_strRessyamei ;
	
	/**
		���̗�Ԃ́w�����x�B
		
		�K��l�͋󕶎���ł��B
		
		�R���X�g���N�^�� readCentDedRessya() �� CentDedRessya �����Ƃ�
		���܂�܂��B
	 */
	std::string m_strGousuu ;
	
	/**
		���ׂĂ̗�Ԑ����܂ށA�w�_�C���O�����G���e�B�e�BX���W�x�͈̔́B
		���̗�Ԃ�NULL�Ȃ�APos=0,Size=0 �ɂȂ�܂��B

		�N�_�ƏI�_�ƂŁw�_�C���O�����G���e�B�e�BX���W�x�������̏ꍇ�́A
		��O�I�ɃT�C�Y��1�ɂȂ�܂��B
	*/
	CdDcdZone	m_DgrXZone ;
	///@}
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		���̗�Ԃ��܂���w�_�C���O�����_�C���x�ւ̊֘A�B
		
		���̊֘A�́Am_pCentDedDgrRessyasenCont ����A
		Mu< CdDedDgrEki >�@�ɃA�N�Z�X���邽�߂ɕK�v�ɂȂ�܂��B

		�R���X�g���N�^�Ō��܂�܂��B
	*/
	const CentDedDgrDia*	m_pCentDedDgrDia ;	

	///@}
private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		���̗�Ԃ̊e�w�̉w�����B
		�R���X�g���N�^�� readCentDedRessya() �Ō��܂�܂��B
	 */
	CMuiCopied< CentDedDgrEkiJikoku > m_MuCentDedDgrEkiJikoku ;
	/**
		���̗�Ԃ̗�Ԑ��B
		�R���X�g���N�^�� readCentDedRessya() �Ō��܂�܂��B
	 */
	CentDedDgrRessyasenCont*	m_pCentDedDgrRessyasenCont ;

	///@}

private:
	// --------------------------------
	///@name readCentDedRessya() �̉����֐�
	// --------------------------------
	///@{
	/**
		readCentDedRessya() �̉����֐�

		(01)CentDedDgrRessya�̑����̂����ACentDedRessya �݂̂Ō��肷�鑮����ݒ�
	*/
	void readCentDedRessya_01_readProp( const CentDedRessya* pCentDedRessya ) ;
	/**
		readCentDedRessya() �̉����֐�

		(02)CentDedDgrEkiJikoku �𐶐����A CentDedEkiJikoku �Ō��܂鑮��������B
	*/
	void readCentDedRessya_02_CreateCentDedEkiJikoku( 
		const CentDedRessya* pCentDedRessya ) ;

	/**
		readCentDedRessya() �̉����֐�

		(03)CentDedDgrRessya�̈ȉ��̑������ACentDedDgrEkiJikoku�̑��������Ƃɐ����B

		CdDcdZone	m_zoneDgrXZahyou
	*/
	void readCentDedRessya_03_updateDgrXZone() ;

	/**
		readCentDedRessya() �̉����֐�

		(04)CentDedDgrEkijikoku�̈ȉ��̑������ACentDedDgrEki �̑��������ƂɌ���B
		m_bShouldRessyajouhouDraw //��ԏ������̉w�̏ꏊ�ɕ`�悷��Ȃ�^�ł��B

			��ԏ��`��̏����́A��Ԑ��̑��݂���w�Ԃɂ�����A
			�ȉ��̂����ꂩ�̏����𖞂����w�ԁB
			
			(1)   [���̗�Ԃ̗�ԏ�񂪂܂�1�ӏ����`�悳��Ă��Ȃ�]�ꍇ�́A
				��ԏ��`�悪�u�\�����Ȃ��v�ȊO�̉w�ԁB
			(2)  ��ԏ��`�悪�u��ɕ\���v�̉w��
			
		���̏����ɍ�����ԏ��`��ʒu���Ȃ��ꍇ�́A
		�ŏ��̗�Ԑ��ʒu�ɕ`�悵�܂�(�u�\�����Ȃ��v�ł����Ă�)�B
	*/
	void readCentDedRessya_04_updateShouldRessyajouhouDraw(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) ;

	/**
		readCentDedRessya() �̉����֐�

		(05)�o�R�Ȃ��̑O��̒���������₤
		
		- �A�������o�R�Ȃ��̒��O�ɒ��������Ȃ� AND 
			�o�R�Ȃ��̒���ɒ�����������ꍇ�́A���O�̒�������₢�܂��B
		- �A�������o�R�Ȃ��̒��O�ɔ��������Ȃ� AND 
			�o�R�Ȃ��̒���ɔ�����������ꍇ�́A���O�̔�������₢�܂��B

		- �A�������o�R�Ȃ��̒��O�ɒ����������� AND 
			�o�R�Ȃ��̒���ɒ��������Ȃ��ꍇ�́A����̒�������₢�܂��B
		- �A�������o�R�Ȃ��̒��O�ɔ����������� AND 
			�o�R�Ȃ��̒���ɔ��������Ȃ��ꍇ�́A����̔�������₢�܂��B

	*/
	void readCentDedRessya_05_complementKeiyunasiSide() ;

	/**
		readCentDedRessya() �̉����֐�

		(06_01)�����Ԓ�Ԃ�����
			(�����Ԓ�Ԃ̒�����=�Ȃ��E������=���� �̉w�ɁA��������₤)

		�ȉ��̉w�����̕��т�T���܂��B
		- (1)������=����A�w��={���,�ʉ�}�̂����ꂩ
		- (2)�u������=�Ȃ��A������=�Ȃ��A�w��={�ʉ�,�o�R�Ȃ�}�̂����ꂩ�v��
			0�ȏ�̕���
		- (3)������=�Ȃ��A������=���� AND ��Ԃ̏I���w�łȂ�
		
		(1)�̔�����+(1)�`(3)�Ԃ̉w�ԍŏ����v�b����(3)�̔�����-60�b�Ȃ�A@n
		(3)�̒�����=(1)�̔�����+(1)�`(3)�Ԃ̉w�ԍŏ����v�b��
		�Ƃ��܂��B
	*/
	void readCentDedRessya_06_complementLongStop_01(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) ;

	/**
		readCentDedRessya() �̉����֐�

		(06_02)�����Ԓ�Ԃ�����
			(�����Ԓ�Ԃ̒�����=����E������=�Ȃ� �̉w�ɁA��������₤)

		�ȉ��̉w�����̕��т�T���܂��B

		- (1)������=����A������=�Ȃ�
		- (2)�u������=�Ȃ��A������=�Ȃ��A�w��={�ʉ�,�o�R�Ȃ�}�̂����ꂩ�v��
			0�ȏ�̕���
		- (3)������=����A�w��={���,�ʉ�}�̂����ꂩ

		(1)�̒�������(3)�̒�����-(1)�`(3)�Ԃ̉w�ԍŏ����v�b��-60�b�Ȃ�A@n
		(1)�̔�����=(3)�̒�����-(1)�`(3)�Ԃ̉w�ԍŏ����v�b��
		�Ƃ��܂��B
	*/
	void readCentDedRessya_06_complementLongStop_02(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) ;

	/**
	(08)CentDedDgrRessyasen�̃R���e�i�𐶐����A
	  CentDedDgrEkijikoku::m_iDgrXPosOnRessyasen
	���C��
	*/
	void readCentDedRessya_08_updateRessyasenCont(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ) ;

	///@}

	// --------------------------------
	///@name readCentDedRessya_08_updateRessyasenCont() �̉����֐�
	// --------------------------------
	///@{

	/**
		readCentDedRessya_08_updateRessyasenCont() �̉����֐��ł��B
	
	(01)�w��Ԑ��N�_�wOrder�x��T���܂��B

	 @param pCentDedRessya [in]
		�ΏۂƂȂ��ԃI�u�W�F�N�g���w�肵�ĉ������B
	 @param iEkiOrder [in]
		���̊֐��́A���́w�wOrder�x�ȍ~�ŁA
		�w��Ԑ��N�_�wOrder�x��T���܂��B
	 @param piRessyasenKitenEkiOrder [out]
		���̊֐��́A����������A
		�w��Ԑ��N�_�wOrder�x�����̕ϐ��ɏ������݂܂��B
	 @return
		����������A0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 ;	//	�w��Ԑ��N�_�wOrder�x���݂���܂����B
		-	-1 ;	//	iEkiOrder �ȍ~�ŁA��Ԑ��N�_�w������܂���B
	
	
		�w��Ԑ��N�_�wOrder�x�̏����́A
		�u�������E�������̂����ꂩ���w�肳��Ă��� AND 
		���́w�wOrder�x�̉w�����w��ԁx���w�ʉ߁x�v
	*/
	int updateRessyasenCont_01_calcRessyasenKiten( 
		int iEkiOrder ,
		int* piRessyasenKitenEkiOrder ) ;

	/**
		readCentDedRessya_08_updateRessyasenCont() �̉����֐��ł��B
	
		(02)�w��Ԑ��N�_�wOrder�x�ɑΉ�����w��Ԑ��I�_�wOrder�x���������܂��B
	
	�@	  (1)�@�w��Ԑ��I�_�wOrder�x�̏����́A
		�u�������E�������̗������w�肳��Ă���v OR
		�u ���̉w�̉w�������w�^�s�Ȃ��x �v OR
		�u�u�w�wOrder�x���A���̗�Ԃɂ�����̏I���w�v 
	�@	  �Ώۉw���݂���Ȃ���΁A��Ԑ��I�_�wOrder�̌���͎��s�ƂȂ�܂�
		  (�o�R�Ȃ��̒��O�́A��Ԑ��̏I�_�ɂ͂Ȃ�܂���
		  �@(���̎��_�ł̗�Ԑ��N�_�ƏI�_�́A�o�R�Ȃ����܂������Ƃ�����܂��B)

	�@	  (2)�@���̎��_�ŁA�w��Ԑ��I�_�wOrder�x�ɒ���������������
		�ݒ肳��Ă��Ȃ��ꍇ�́A
		�n���w�����Ɍ������āA�������E�������̂����ꂩ���w�肳��Ă���
		�w���������܂��B
�@		  ���̌��ʁw��Ԑ��I�_�wOrder�x�ɑ�������w���Ȃ��ꍇ�́A
		��Ԑ��I�_�wOrder�̌���͎��s�ƂȂ�܂��B

	 @param iRessyasenKitenEkiOrder [in]
		�w��Ԑ��N�_�wOrder�x���w�肵�ĉ������B
	 @param piRessyasenSyuutenEkiOrder [out]
		���̊֐��́A����������A
		�w��Ԑ��I�_�wOrder�x�����̕ϐ��ɏ������݂܂��B
	 @return
		����������A0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 ;	//	�w��Ԑ��I�_�wOrder�x���݂���܂����B
		-	-1 ;	//	��Ԑ��I�_�w������܂���B
					//	���̋�ԂɊւ��ẮA��Ԑ����쐬�ł��܂���B
	 */
	int updateRessyasenCont_02_calcRessyasenSyuuten( 
		int iRessyasenKitenEkiOrder ,
		int* piRessyasenSyuutenEkiOrder ) ;
	
	/**
		readCentDedRessya_08_updateRessyasenCont() �̉����֐��ł��B
	
		(04)�w�_�C���O������Ԑ��x�I�u�W�F�N�g����
		�w��Ԑ��N�_�wOrder�x�Ɓw��Ԑ��I�_�wOrder�x�̊Ԃ�
		�r���w�ŁA
	
		�u�������E�������̂����ꂩ���w�肳��Ă����v�w�vOR
	
		�u�ʉ߉w�ŁA
		���������������̂����ꂩ���w�肳��Ă���v 
	
		 ������΁A
		������w��Ԑ��I�_�wOrder�x�ɂ��܂��B
	
	 @param pMuCdDedDgrEki [in]
		�w�_�C���O�����w�x���ւ̃C���^�[�t�F�[�X���w�肵�ĉ������B
	 @param iRessyasenKitenEkiOrder [in]
		�w��Ԑ��N�_�wOrder�x���w�肵�ĉ������B
	 @param piRessyasenSyuutenEkiOrder [in,out]
		�w��Ԑ��I�_�wOrder�x���w�肵�Ă��������B
		���̊֐��́A����������A���̒l���㏑���C�����܂��B
	 @return
		����������A0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 ;	//	�w��Ԑ��I�_�wOrder�x�̕␳�̕K�v�͂���܂���ł����B
		-	1 ;	//	�w��Ԑ��I�_�wOrder�x�̕␳���s���܂����B
	 */
	int updateRessyasenCont_04_adjustRessyasenSyuuten4( 
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iRessyasenKitenEkiOrder ,
		int* piRessyasenSyuutenEkiOrder ) ;


	/**
		readCentDedRessya_08_updateRessyasenCont() �̉����֐��ł��B
	
		(05)�w��Ԑ��R���e�i CentDedDgrRessyasenCont �x�̖�����
		�w��Ԑ� CentDedDgrRessyasen�x�̓r���w�̒��ŁA
		��Ԑ��̈ʒu(CentDedDgrEkiJikoku::m_iDgrXPosRessyasen)��
		�������E������(CentDedDgrEkiJikoku::m_iDgrXPosChaku,m_iDgrXPosHatsu)��
		����60 �b�ȏ゠��ꍇ�́A���̉w���w��Ԑ��I�_�wOrder�x�Ƃ��܂��B
	 @param pCentDedDgrRessyasen [in,out]
		�w��Ԑ��I�_�wOrder�x���w�肵�Ă��������B
		���̊֐��́A����������A���̒l���㏑���C�����܂��B
	 @return
		����������A0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 ;	//	�w��Ԑ��I�_�wOrder�x�̕␳�̕K�v�͂���܂���ł����B
		-	1 ;	//	�w��Ԑ��I�_�wOrder�x�̕␳���s���܂����B
	 */
	int updateRessyasenCont_05_adjustRessyasenSyuuten5( 
		int* piRessyasenSyuutenEkiOrder ) ;

	/**
		readCentDedRessya_08_updateRessyasenCont()�̉����֐��ł��B

		(06)�R���e�i�����̗�Ԑ����r���Ɂu�o�R�Ȃ��v���܂ޏꍇ�A
		���̗�Ԑ����u�o�R�Ȃ��v�܂łɒZ�k���܂��B

		- (1)�u�o�R�Ȃ��v���O�̉w�E����̉w�̒��E���������u��Ԑ��w�����v
			�ɒu�������܂��B
		- (2)��Ԑ��́u�o�R�Ȃ��v���O�܂łɒZ�k���܂��B
		- (3)��Ԑ��I�_���u�o�R�Ȃ��v�̒��O�Ƃ��܂��B
		
	
	 @param pCentDedDgrRessyasen [in,out]
		�w��Ԑ��I�_�wOrder�x���w�肵�Ă��������B
		���̊֐��́A����������A���̒l���㏑���C�����܂��B
	 @return
		����������A0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 ;	//	�w��Ԑ��x�w�w�����x�w�I�_�wOrder�x�̕␳�̕K�v��
			����܂���ł����B
		-	1 ;	//	�w��Ԑ��x�w�w�����x�w�I�_�wOrder�x�̕␳���s���܂����B
	*/
	int updateRessyasenCont_06_reduceToKeiyunasi( 
		int* piRessyasenSyuutenEkiOrder ) ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		readCentDedRessya() ���s���܂��B
	 @param pCentDedRosen [in]
		CentDedRessya �I�u�W�F�N�g���܂��Ă���
		CentDedRosen �I�u�W�F�N�g���w�肵�Ă��������B
		���̃I�u�W�F�N�g�́A��Ԏ�ʂɊւ��鑮��
		- m_CdLineProp
		- m_CdDrawTextProp 
		�����肷��̂Ɏg���܂��B
	 @param pCentDedDgrDia [in]
		this ���܂��Ă���w�_�C���O�����w�x�I�u�W�F�N�g��
		�w�_�C���x�I�u�W�F�N�g���w�肵�Ă��������B
		���̃I�u�W�F�N�g�́A�w�Ԃ̊T�Z���v���������߂�̂Ɏg���܂��B
	 @param pCentDedRessya [in]
		�ΏۂƂȂ��ԃI�u�W�F�N�g���w�肵�Ă��������B
	*/
	CentDedDgrRessya( 
		const CentDedRosen* pCentDedRosen ,
		const CentDedDgrDia* pCentDedDgrDia ,
		const CentDedRessya* pCentDedRessya ) ; 
	
	/** 
		NULL �̗�Ԃ𐶐����܂��B
	 @param pCentDedDgrDia [in]
		this ���܂��Ă���w�_�C���O�����w�x�I�u�W�F�N�g��
		�w�_�C���x�I�u�W�F�N�g���w�肵�Ă��������B
		���̃I�u�W�F�N�g�́A�w�Ԃ̊T�Z���v���������߂�̂Ɏg���܂��B
	*/
	CentDedDgrRessya( 
		const CentDedDgrDia* pCentDedDgrDia ) ;

	/**
		�R�s�[�R���X�g���N�^�Ŏw��ł���̂́A
		���� m_pCentDedDgrDia ������ԂɌ��肳��܂��B
	*/
	CentDedDgrRessya( const CentDedDgrRessya& value ) ;
private:
	CentDedDgrRessya& operator=( const CentDedDgrRessya& value );
public:
	virtual ~CentDedDgrRessya() ;
	
// ********************************
//	CentDedDgrRessya
// ********************************
	// ********************************
	///@name CentDedDgrRessya-����
	// ********************************
	///@{
	bool getIsNull()const ;
	ERessyahoukou	getRessyahoukou()const ;
	CentDedDgrRessya& setRessyahoukou( ERessyahoukou value ) ;
	int	getRessyasyubetsuIndex()const ;
	void setRessyasyubetsuIndex( int value ) ;

	std::string getRessyabangou()const ;
	CentDedDgrRessya& setRessyabangou( const std::string& value ) ;
	std::string getRessyamei()const ;
	CentDedDgrRessya& setRessyamei( const std::string& value ) ;
	std::string getGousuu()const ;
	CentDedDgrRessya& setGousuu( const std::string& value ) ;
	CdDcdZone	getDgrXZone()const ;
	///@}
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		���̗�Ԃ��܂���w�_�C���O�����_�C���x�ւ̊֘A�B
		
		m_pCentDedDgrRessyasenCont ��
		CentDedEkiCont �ւ̊֘A��K�v�Ƃ��܂��B

		�R���X�g���N�^�Ō��܂�܂��B
	*/
	const CentDedDgrDia*	getCentDedDgrDia()const
	{ return m_pCentDedDgrDia ;}	

	///@}
	
	// ********************************
	///@name CentDedDgrRessya-���
	// ********************************
	///@{
	Mu< CentDedDgrEkiJikoku* >* getMuCentDedDgrEkiJikoku() ;
	const Mu< const CentDedDgrEkiJikoku* >* getMuCentDedDgrEkiJikoku()const ;
	Mu< CentDedDgrRessyasen* >* getCentDedDgrRessyasenCont() ;
	const Mu< const CentDedDgrRessyasen* >* getCentDedDgrRessyasenCont()const ;
	///@}
	// ********************************
	///@name CentDedDgrRessya-����
	// ********************************
	///@{
	/**
		���ׂĂ̑����E��܃I�u�W�F�N�g���N���A���܂��B
		���̗�Ԃ́A NULL �ƂȂ�܂��B
	*/
	void clear() ;


	/**
		CentDedRessya �I�u�W�F�N�g�̓��e�����ƂɁA
		this �̑����E�y�� �w�_�C���O������Ԑ��x (CentDedDgrRessyasen)
		�I�u�W�F�N�g�𐶐����܂��B
	 @param pCentDedRosen [in]
		CentDedRessya �I�u�W�F�N�g���܂��Ă���
		CentDedRosen �I�u�W�F�N�g���w�肵�Ă��������B
		���̃I�u�W�F�N�g�́A��Ԏ�ʂɊւ��鑮��
		- m_CdLineProp
		- m_CdDrawTextProp 
		�����肷��̂Ɏg���܂��B
	 @param pCentDedDgrDia [in]
		this ���܂��Ă���w�_�C���O�����w�x�I�u�W�F�N�g��
		�w�_�C���x�I�u�W�F�N�g���w�肵�Ă��������B
		���̃I�u�W�F�N�g�́A�w�Ԃ̊T�Z���v���������߂�̂Ɏg���܂��B
	 @param pCentDedRessya [in]
		�ΏۂƂȂ��ԃI�u�W�F�N�g���w�肵�Ă��������B
	 */
	virtual int readCentDedRessya(
		const CentDedRosen* pCentDedRosen ,
		const CentDedDgrDia* pCentDedDgrDia ,
		const CentDedRessya* pCentDedRessya ) ; 

	/**
	 @return
		���̗�Ԃ̎n���w�́w�wOrder�x��Ԃ��܂��B
		���ׂẮw�w�����x���w�^�s�Ȃ��x�̏ꍇ�́A-1 ��Ԃ��܂��B
		���̏ꍇ�A���̗�Ԏ��̂��w�^�s�Ȃ��x�ƂȂ�܂��B
	 */
	int getSihatsuEki()const ;

	/**
	 @return
		���̗�Ԃ̏I���w�́w�wOrder�x��Ԃ��܂��B
		���ׂẮw�w�����x���w�^�s�Ȃ��x�̏ꍇ�́A-1 ��Ԃ��܂��B
		���̏ꍇ�A���̗�Ԏ��̂��w�^�s�Ȃ��x�ƂȂ�܂��B
	 */
	int getSyuuchakuEki()const ;

	/**
		��Ԃ��w��� �w�wOrder�x�ƁA���́w�wOrder�x�̊Ԃ�
		�^�s���Ă��邩�ۂ��𒲂ׂ܂��B

		�u�w��� �w�wOrder�x�ƁA���́w�wOrder�x�̊Ԃ�
		�^�s���Ă���v�́A
		�w��� �w�wOrder�x�ƁA���́w�wOrder�x�̗�����
		�w��ԁx�܂��́w�ʉ߁x�̏ꍇ���A����ɊY�����܂��B
		�_�C���O�����r���[�ł́A���̗�Ԃ̂��̉w�Ԃɂ͗�Ԑ���
		�`�悳��܂��B

	@param iEkiOrder [in]
		�ΏۂƂȂ�w�Ԃ̋N�_���́w�wOrder�x���w�肵�Ă��������B
		�͈͂́A0�ȏ�A(�w�̐�-1)�����ł��B
	@return
		��Ԃ� iEkiOrder �Ǝ��̉w�̊Ԃ��^�s���Ă���Ȃ� true �ł��B
		�����łȂ��ꍇ�́A false �ł��B
		�������͈͊O�̏ꍇ���Afalse �ł��B
	@attention
		�ǂ��炩�̉w�E�܂��͗����̉w���w�o�R�Ȃ��x�̏ꍇ�́A
		�u�w�̊Ԃ��^�s���Ă���v�Ƃ݂͂Ȃ��܂���B
		���̏ꍇ�A���̃��\�b�h�̖߂�l�͋U�ƂȂ�܂��B
	*/
	bool isRunBetweenNextEki( int iEkiOrder )const ;

	/**
		�w��̂Q�̉w�Ԃ̊Ԃ́A�w�ԍŏ����v�b�����Z�o���܂��B
		�^�s�Ȃ��E�o�R�Ȃ��̉w��(�_�C���O������Ԑ��̕`�悳��Ȃ��w��)��
		���v�b���͊܂݂܂���B
	@param pMuCdDedDgrEki [in]
		�w�̏��̃}���`�I�u�W�F�N�g���w�肵�Ă��������B
	@param iEkiOrderBefore [in]
		�n���w���̉wOrder���w�肵�Ă��������B
	@param iEkiOrderAfter [in]
		�I���w���̉wOrder���w�肵�Ă��������B
	@return
		�ŏ����v�b���̘a��Ԃ��܂��B
	*/
	int calcEkikanSaisyouSec(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iEkiOrderBefore ,
		int iEkiOrderAfter )const ; 

	/**
		�w��̂Q�̉w�̉w�Ԃ́ADgrY���W�����Z�o���܂��B
		�^�s�Ȃ��E�o�R�Ȃ��̉w��(�_�C���O������Ԑ��̕`�悳��Ȃ��w��)�E
		�w��DgrY���W�T�C�Y(��Ԑ����`�悳��Ȃ��̈�)��
		�܂݂܂���B
	@param pMuCdDedDgrEki [in]
		�w�̏��̃}���`�I�u�W�F�N�g���w�肵�Ă��������B
	@param iEkiOrderBefore [in]
		�n���w���̉wOrder���w�肵�Ă��������B
	@param iEkiOrderAfter [in]
		�I���w���̉wOrder���w�肵�Ă��������B
	@return
		�ŏ����v�b���̘a��Ԃ��܂��B
	*/
	int calcDgrYEkikanSize(
		const Mu<CentDedDgrEkiCont::CdDedDgrEki>* pMuCdDedDgrEki ,
		int iEkiOrderBefore ,
		int iEkiOrderAfter )const ; 


	/**
		���ׂẮw�_�C���O�����w�����x�I�u�W�F�N�g��
		�w�_�C���O�����G���e�B�e�BX���W�x�����Z�E���Z���܂�(NULL������ INT_MIN �͏����B
	 @param iSeconds [in]
		���Z�E���Z����l�i�b���E�w�_�C���O�����G���e�B�e�BX���W�x�j	
		���w�肵�ĉ������B
	 */
	virtual void modifyDgrXPos(	int iSeconds ) ; 

	
	/**
		�w��Ԑ��x�I�u�W�F�N�g�����Ƃɂ��āA
		�w����Order�x�ɑΉ�����	�w�_�C���O�����G���e�B�e�BX���W�x���擾���܂��B
	 @param aCdDcdJikokuOrder [in]
		�w����Order�x���w�肵�ĉ������B
	 @param piDgrXPos [out] 
		���̊֐��́A����������A
		�w����Order�x�ɑΉ�����A�w�_�C���O�����G���e�B�e�BX���W�x��
		���̃A�h���X�ɏ������݂܂��i���̐��̏ꍇ������܂��j�B
	 @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	��Ԃ��w��́w����Order�x���܂�
		�w��Ԑ��x�I�u�W�F�N�g���������Ă��܂���B
	
		�w��́w����Order�x���(������)�ŁA���ꂪ�w�_�C���O������Ԑ��x��
		�N�_�ɂȂ��Ă���ꍇ�E�E�E
		�w�_�C���O������Ԑ��x�̋N�_�̉w����
	
		�w��́w����Order�x���w�_�C���O������Ԑ��x��
		���ԓ_�ɂȂ��Ă���ꍇ�E�E�E
		���́w����Order�x���w�wOrder�x�ɕϊ����A��Ԑ���̍��W�����Ƃ�
		�T�Z���������B
	
		�w��́w����Order�x�������ŁA���ꂪ�w�_�C���O������Ԑ��x��
		�I�_�ɂȂ��Ă���ꍇ�E�E�E
		�w�_�C���O������Ԑ��x�̏I�_�̉w����
	
	@todo
		�߂�l�̎d�l��ύX���܂��BpiDgrXPos��߂�l�ɂ��A�����͌��炵�܂��B
	*/
	virtual int getDgrXPosOfJikokuOrder(
		CdDedJikokuOrder aCdDedJikokuOrder , 
		int* piDgrXPos )const ; 

	/**
		�w��Ԑ��x�I�u�W�F�N�g�����Ƃɂ��āA
		�w�wOrder�x�ɑΉ�����A��������
		�w�_�C���O�����G���e�B�e�BX���W�x���擾���܂��B
	 @param iEkiOrder [in]
		�w�wOrder�x���w�肵�ĉ������B
	 @param piDgrXPos [out] 
		���̊֐��́A����������A
		�w�wOrder�x�ɑΉ�����A�w�_�C���O�����G���e�B�e�BX���W�x��
		���̃A�h���X�ɏ������݂܂��i���̐��̏ꍇ������܂��j�B
	 @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	��Ԃ��w��́w�wOrder�x���܂�
		�w��Ԑ��x�I�u�W�F�N�g���������Ă��܂���B
	
		���̊֐��́A�_�C���O������Ɂw��ԏ��x��
		�`�悷��ہA�e�L�X�g�̈ʒu�����߂�̂Ɏg�����Ƃ�
		�z�肵�Ă��܂��B
		���̊֐����Ԃ��l�́A�ȉ��̃��[���ɑ���܂��B
	
		�w��́w�wOrder�x���w�_�C���O������Ԑ��x��
		�N�_�ɂȂ��Ă���ꍇ�E�E�E
		�w�_�C���O������Ԑ��x�̋N�_�̉w����
	
		�w��́w�wOrder�x���w�_�C���O������Ԑ��x��
		���ԓ_�ɂȂ��Ă���ꍇ�E�E�E
		���́w�wOrder�x�����ƂɁA�T�Z��������
	
		�w��́w�wOrder�x���w�_�C���O������Ԑ��x��
		�N�_�ɂ͂Ȃ��Ă��Ȃ����A�I�_�ɂ͂Ȃ��Ă���ꍇ�E�E�E
		�w�_�C���O������Ԑ��x�̏I�_�̉w����
	*/
	virtual int getDgrXPosOfEkiOrder(
		int iEkiOrder , 
		int* piDgrXPos )const ; 


	///@}

};

} //namespace entDgr
#endif /*CentDedDgrRessya_h*/


