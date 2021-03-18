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
//	CentDedDgrDia.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrDia_h
#define  CentDedDgrDia_h

#include "CentDedDgrEki.h"
#include "CentDedDgrEkiCont.h"
#include "CentDedDgrRessya.h"
#include "CentDedDgrRessyasyubetsu.h"
#include "NsMu/CMuiCopied.h"

namespace entDgr{

// ****************************************************************
//	CentDedDgrDia
// ****************************************************************
/**
@brief
�y�T�v�z
�w�_�C���O�����G���e�B�e�B�N���X�Q�x�́w�_�C���O�����_�C���x�N���X�ł��B
�w�_�C���x �P��\���܂��B�w�_�C���O�����G���e�B�e�B�N���X�Q�x��
���[�g�R���e�i�Ƃ��Ĉʒu���܂��B

���̃N���X�́A
 - �w�_�C���O�����w�x(CentDedDgrEki)�I�u�W�F�N�g
 - �w�_�C���O������Ԏ�ʁx(CentDedDgrRessyastybetsu)�I�u�W�F�N�g
 - �w�_�C���O������ԁx(CentDedDgrRessya)�I�u�W�F�N�g

�I�u�W�F�N�g���܂��܂��B
  �w�_�C���O������ԁx�I�u�W�F�N�g�́A����E���ǂ���̗�Ԃ�
�ێ����܂��B

<H4>
�y�g�����P�E�E�E�w�H���x (CentDedRosen) �̏������S�ɔ��f����z
</H4>
 
 �P�D  �R���X�g���N�^�ŃI�u�W�F�N�g�𐶐����Ă��������B
 
 �Q�D  readCentDedRosen() �֐����Ăяo���Ă��������B���̊֐��́A
	�w�H���x (CentDedRosen) �I�u�W�F�N�g�Ɋ܂܂��
	�w�w�x (CentDedEki) �E�w�_�C���x (CentDedDia) �E
	�w��Ԏ�ʁx (CentDedResstasyubetsu) �E
	�w��ԁx (CentDedRessya) �I�u�W�F�N�g�����ƂɁA
	�w�_�C���O�����w�x (CentDedDgrEki) �E
	�w�_�C���O������Ԏ�ʁx (CentDedDgrResstastyvetsu) �E
	�w�_�C���O������ԁx (CentDedDgrRessya) �I�u�W�F�N�g�𐶐����܂��B
 
 �R�D  ����ŁA�_�C���O�����̗�Ԑ���`�悷���񂪂��ׂđ��������Ƃ�
 �Ȃ�܂��B
 
   this �� getDgrYPosOfEki() ���\�b�h�ŁA�e�w��Y���W���擾���邱�Ƃ�
 �ł��܂��B
 
�@�w�_�C���O������ԁx CentDedDgrRessya �I�u�W�F�N�g�́A

	- �w�����́w�_�C���O�����w�����x CentDedDgrEkiJikoku �I�u�W�F�N�g
	- 0�ȏ�́w�_�C���O������Ԑ��x CentDedDgrRessyasen �I�u�W�F�N�g

���܂��Ă��܂��B
 
�@ �w�_�C���O������Ԑ��x CentDedDgrRessyasen �I�u�W�F�N�g�̑����Ƃ��āA
 
 	- CentDedDgrRessyasen::m_iRessyasenKitenEkiOrder �E�E�E
    ��Ԑ��N�_�wOrder�B �w�wOrder�x�ŕ\���܂��B
 	- CentDedDgrRessyasen::m_iRessyasenSyuutenEkiOrder �E�E�E
    ��Ԑ��I�_�wOrder�B �w�wOrder�x�ŕ\���܂��B
 
 ������܂��B

  �ȉ���2�_�����Ԓ������A��Ԑ��ƂȂ�܂��B
  
- �y�n�_�z
	- X���W�F�@��Ԑ��N�_�wOrder�̉w�����́A������������X���W
�@	  (CentDedDgrEkiJikoku::m_iDgrXPosHatsu)
	- Y���W�F�@��Ԑ��N�_�w��Y���W(CentDedDgrDia::getDgrYPosOfEki() �ŋ��߂邱�Ƃ��ł��܂�)

- �y�I�_�z
	- X���W�F�@��Ԑ��I�_�wOrder�̉w�����́A������������X���W
�@	  (CentDedDgrEkiJikoku::m_iDgrXPosChaku)
	- Y���W�F�@��Ԑ��I�_�w��Y���W(CentDedDgrDia::getDgrYPosOfEki() �ŋ��߂邱�Ƃ��ł��܂�)

 ��Ԑ��͐܂���ł��̂ŁA
 ��̗�Ԃɂ��A�܂���̊p�̐��{�P�����A
 �w�_�C���O������Ԑ��x CentDedDgrRessyasen �I�u�W�F�N�g�����݂��܂��B
 
 �ڍׂ́A�w�_�C���O�����G���e�B�e�B���W�n�x�̐������������������B
 
<H4>
�y�g�����Q�E�E�E�w��ԁx (CentDedRessya) ��ύX����ꍇ�z
</H4>
 
   ����w��ԁx (CentDedRessya) �̑����E�y�ѕ�܂��Ă���
	�w�w�����x (CentDedEkiJikoku) ���ύX���ꂽ�ꍇ�́A
 �w�_�C���O�����_�C���x (CentDedDgrDia) �I�u�W�F�N�g�ɕ�܂���Ă��� 
 �w�_�C���O������ԁx (CentDedDgrRessya) �I�u�W�F�N�g�ɑ΂��āA
  CentDedDgrRessya::readCentDedRessya() ���\�b�h���Ăяo���Ă��������B
 
 
<H4>
�w�_�C���O�����G���e�B�e�B���W�x
</H4>
 
   �w�_�C���O�����G���e�B�e�B�N���X�Q�x�́A�w�_�C���O�����x�̗�Ԑ���
 ���W���v�Z����\�͂������Ă��܂��B
 
   ���̍��W�v�Z�́A�w�_�C���O�����G���e�B�e�B�N���X�Q�x���L�̍��W�n��
 �g���čs���܂��B
   �Ȍ�A���̍��W�n���w�_�C���O�����G���e�B�e�B���W�n�x�ƕ\�L���܂��B
 �܂��A�w�_�C���O�����G���e�B�e�B���W�n�x�� 
 X���W���w�_�C���O�����G���e�B�e�BX���W�x(DgrX)�E
 Y���W���w�_�C���O�����G���e�B�e�BY���W�x(DgrY)�ƕ\�L���܂��B
   
   �ʏ�̃_�C���O�����ł́AX�����̍��W�͎����EY�����̍��W�͘H����
 �N�_����̓��̂��\���܂��B
   �w�_�C���O�����G���e�B�e�BX���W�x�́A�ʏ�̃_�C���O�����Ɠ��l�A
 ������\���܂��B�l�̒P�ʂ͕b�ŁA�ߑO�O������̌o�ߕb����\���܂��B
 �@���̒l�́A24*60*60 (24:00:00) �ȏ�ɂȂ�ꍇ������܂��B
  
   �w�_�C���O�����G���e�B�e�BY���W�x�́A�w�w�ԍŏ����v�b���x
 ����{�Ƃ����l���g���܂��B
   ���̒l�́A�u���̘H���́i�����Ԃ́j�N�_����́A�ő��̊e�w��Ԃ�
 ���v�b���v��b�P�ʂŕ\�������̂ƂȂ�܂��B
 
   ���ۂɁw�_�C���O�����r���[�x�Ƀ_�C���O������`�悷��ۂ́A
 �w�_�C���O�����G���e�B�e�B���W�n�x�̒l���A�r���[�̃E�C���h�E���W�n��
 �ϊ�����K�v������܂��B���̏����́A
 �w�_�C���O�����G���e�B�e�B�N���X�Q�x�ɂ͂���܂���̂ŁA
 �N���X���[�U�[�̑��ōs���K�v������܂�(��: CDcdDiagram �N���X)�B
 
   �w�_�C���O�����G���e�B�e�B�N���X�Q�x�ł́AY���W�̌v�Z�����ƂȂ�
 �w�w�ԍŏ��b���x���v�Z����ہA�w�H���G���e�B�e�B�N���X�Q�x��
 �w�_�C���x (CentDedDia)�Ɋ܂܂�邷�ׂẮw��ԁx�̉w�������Q�Ƃ��āA
 �ŏ��b�������߂܂�( readCentDedRosen_02_updateEkiCont() )�B
*/
class CentDedDgrDia
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�_�C���̖��̂ł��B
	
		�i��j "�����_�C��" �Ȃ�
	
		readCentDedRosen() �ŁA���܂�܂��B
	 */
	std::string	m_strName ;

	/**
		�_�C���O�����̍��[�́w�_�C���O�����G���e�B�e�BX���W�x�ł��B
	
		�f�t�H���g�ł�  0 �ł��B���̏ꍇ�A
		�_�C���O�����̍��[�� 00:00:00 �ƂȂ�܂��B
	 */
	int m_iDgrXPosMin ;

	/**
	�_�C���O�����̊���̉w�ԕ��B

	��Ԑݒ�̂Ȃ��w�Ԃ́A�_�C���O�����r���[��ł�
	�c�����̕����w�_�C���O�����G���e�B�e�BY���W�x�P��(�b)�Ŏw�肵�܂��B

	����l�� 60 �ł��B
	*/
	int	m_iDgrYSizeEkikanDefault ;

	///@}
	
private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		�w�_�C���O�����w�x�I�u�W�F�N�g��ێ����܂��B
	
		�C���f�N�X�́A�w�wIndex�x�ł���A����̎n����0�ƂȂ�܂��B
		�����Ԃ́w�wOrder�x�Ɠ����ł�
	 */
	CentDedDgrEkiCont	m_CentDedDgrEkiCont ;

	/**
		�w�_�C���O������Ԏ�ʉw�x�I�u�W�F�N�g��ێ����܂��B
	
		�C���f�N�X�́A�w�wIndex�x�ł���A����̎n����0�ƂȂ�܂��B
		�����Ԃ́w�wOrder�x�Ɠ����ł�
	 */
	CMuiCopied< CentDedDgrRessyasyubetsu >	m_MuCentDedDgrRessyasyubetsu ;

	
	/**
		�w�_�C���O������ԁx�I�u�W�F�N�g��ێ����܂��B
	
		m_CentDedDgrRessyaCont �̓Y�����́A
	
		- [0] �������� Ressyahoukou_Kudari
		- [1] ������� Ressyahoukou_Nobori
	
		�ƂȂ�܂��B
	
		m_CentDedDgrRessyaCont[] �̃C���f�N�X�́A�w���Index�x�ł��B
	*/
	CMuiCopied< CentDedDgrRessya >	m_CentDedDgrRessyaCont[2] ;
	///@}

private:
	// --------------------------------
	///@name readCentDedRosen() �̉����֐�
	// --------------------------------
	///@{
	/**
		CentDedEki::EDiagramRessyajouhouHyouji ��
		CentDedDgrEki::EDiagramRessyajouhouHyouji ��
		�ϊ����܂��B
	*/
	CentDedDgrEki::EDiagramRessyajouhouHyouji 
		CentDedEki_to_CentDedDgrEki_EDiagramRessyajouhouHyouji( 
			CentDedEki::EDiagramRessyajouhouHyouji  eValue ) ;

	/**
		readCentDedRosen() �̉����֐��ł��B	(1)CentDedDgrDia�̑�����ݒ�

		�@CentDedDgrDia�̈ȉ��̑������ACentDedRosen,CentDedDia ���猈��

		//	�_�C���̖��̂ł��B
		std::string	m_strName ;	

		//	�_�C���O�����̍��[�́w�_�C���O�����G���e�B�e�BX���W�x�ł��B
		int m_iXZahyouMin ;

		//	�_�C���O�����̊���̉w�ԕ��B
		int	m_iDiagramDgrYZahyouKyoriDefault ;
	*/
	void readCentDedRosen_01_updateCentDedDgrDiaProp(
		const CentDedRosen* pCentDedRosen ,
		const CentDedDia* pCentDedDia ) ;

	/**
		readCentDedRosen() �̉����֐��ł��B	(2)CentDedDgrEki�𐶐�
	
		�w�H���G���e�B�e�B�N���X�Q�x�́w�w�x�I�u�W�F�N�g��
		�w�_�C���x�I�u�W�F�N�g���Q�Ƃ��āA�w�_�C���O�����w�x�I�u�W�F�N�g��
		�������A m_CentDedDgrEkiCont �R���e�i�Ɋi�[���܂��B
		  
		   m_CentDedDgrEkiCont ������܂ŕێ����Ă����I�u�W�F�N�g�͔j�����܂��B
		
		  �܂��A m_CentDedDgrRessyaCont ���̂��ׂĂ�
		�w�_�C���O������ԁx�I�u�W�F�N�g���j�����܂��B
	
		���̂Ƃ��A���ׂĂ̗�Ԃ��������āA
		�w�w�ԍŏ����v�b���x CentDedDgrEki::m_iEkikanSaisyouSec ��
		���肵�܂��B
	 @param pCentDedEkiCont [in]
		�w�H���G���e�B�e�B�N���X�Q�x�́w�w�x�I�u�W�F�N�g�̃R���e�i��
		�w�肵�Ă��������B
		���̃R���e�i�̃C���f�N�X�́A�w�wIndex�x�i�����Ԃ́w�wOrder�x�j
		�łȂ��Ă͂Ȃ�܂���B
	 @param pCentDedDia [in]
		�ΏۂƂȂ�w�_�C���x�I�u�W�F�N�g���w�肵�Ă��������B
	 */
	void readCentDedRosen_02_updateEkiCont( 
		const Mu< const CentDedEki* >* pCentDedEkiCont , 
		const CentDedDia* pCentDedDia ) ;
	
	/**
		readCentDedRosen() �̉����֐��ł��B
		(3)CentDedDgrRessyasyubetsu�𐶐�
	
		�w�H���G���e�B�e�B�N���X�Q�x�́w��Ԏ�ʁx�I�u�W�F�N�g
		���Q�Ƃ��āA�w�_�C���O������Ԏ�ʁx�I�u�W�F�N�g��
		�������A m_MuCentDedDgrRessyasyubetsu �R���e�i�Ɋi�[���܂��B
		  
	   m_MuCentDedDgrRessyasyubetsu ������܂ŕێ����Ă����I�u�W�F�N�g�͔j�����܂��B
		
	 @param pMuRessyasyubetsu [in]
		�w�H���G���e�B�e�B�N���X�Q�x�́w��Ԏ�ʁx�I�u�W�F�N�g�̃R���e�i��
		�w�肵�Ă��������B
	 */
	void readCentDedRosen_03_updateMuRessyasyubetsu( 
		const Mu< const CentDedRessyasyubetsu* >* pMuRessyasyubetsu ) ;
	
	/**
		readCentDedRosen() �̉����֐��ł��B
		(4)CentDedDgrRessya,CentDedDgrEkiJikoku�𐶐�
	
		�w�H���G���e�B�e�B�N���X�Q�x��
		�w�_�C���x�I�u�W�F�N�g���Q�Ƃ��āA���E���肷�ׂĂ̗�Ԃ�
		�w�_�C���O������ԁx�I�u�W�F�N�g��
		�������A m_CentDedDgrRessyaCont �R���e�i�Ɋi�[���܂��B
		����ɂ���āA
		�w�_�C���O�����w�����xCentDedDgrEkiJikoku �E
		�w�_�C���O������Ԑ��xCentDedDgrRessyasen 
		�I�u�W�F�N�g���������܂��B
	
		   m_CentDedDgrRessyaCont ������܂ŕێ����Ă����I�u�W�F�N�g��
		�j�����܂��B

		CentDedDgrRessya�̈ȉ��̑������ACentDedRessya �̑������琶���B
			- m_bIsNull 
			- m_eRessyahoukou 
			- m_iRessyasyubetsuIndex 
			- m_strRessyabangou 
			- m_strRessyamei 
			- m_strGousuu 
			- //m_strBikou 

		CentDedDgrEkiJikoku�̈ȉ��̑������ACentDedEkiJikoku�̑��������Ƃɐ����B
			- m_eEkiatsukai //�w��
			- int	m_iDgrXZahyouChaku // INT_MIN��NULL�l�������܂��B
			- int	m_iDgrXZahyouHatsu // INT_MIN��NULL�l�������܂��B

		CentDedDgrRessya�̈ȉ��̑������ACentDedDgrEkiJikoku�̑��������Ƃɐ����B
			- int	m_iDgrXZahyouMin
			- int	m_iDgrXZahyouMax

	 @param pCentDedRosen [in]
		�ΏۂƂȂ�w�_�C���x���܂���H���I�u�W�F�N�g���w�肵�Ă��������B
	 @param pCentDedDia [in]
		�ΏۂƂȂ�w�_�C���x�I�u�W�F�N�g���w�肵�Ă��������B
	 */
	void readCentDedRosen_04_updateRessyaCont( 
		const CentDedRosen* pCentDedRosen , 
		const CentDedDia* pCentDedDia ) ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CentDedDgrDia() ;
	virtual ~CentDedDgrDia() ;
	
	
 public:
	// ********************************
	///@name	CentDedDgrDia-�����֐�
	// ********************************
	///@{
	///@}

 public:
	// ********************************
	///@name CentDedDgrDia-����
	// ********************************
	///@{
	virtual std::string	getName()const;
	virtual int getDgrXPosMin()const ;
	virtual CentDedDgrDia& setDgrXPosMin( int value ) ;
	virtual int getDgrYSizeEkikanDefault()const;
	///@}

	// ********************************
	///@name CentDedDgrDia-���
	// ********************************
	///@{
	CentDedDgrEkiCont*	getCentDedDgrEkiCont();
	const CentDedDgrEkiCont*	getCentDedDgrEkiCont()const;
	
	Mui< CentDedDgrRessyasyubetsu >*	getMuCentDedDgrRessyasyubetsu() ;
	const Mu< const CentDedDgrRessyasyubetsu* >*	getMuCentDedDgrRessyasyubetsu()const ;


	/**
		�w�_�C���O������ԁx�I�u�W�F�N�g��ێ�����R���e�i�ւ�
		�C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		-	���� :	Ressyahoukou_Kudari 
		-	��� : 	Ressyahoukou_Nobori 	
	 @return
		�R���e�i�ւ̃C���^�[�t�F�[�X��Ԃ��܂��B
	
		���̃R���e�i�̃C���f�N�X�́A�w���Index�x�ł��B
	 */
	virtual Mui< CentDedDgrRessya >*	getCentDedDgrRessyaCont( 
		 ERessyahoukou eRessyahoukou ) ;

	/**
		�w�_�C���O������ԁx�I�u�W�F�N�g��ێ�����R���e�i�ւ�
		�C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		-	���� :	Ressyahoukou_Kudari 
		-	��� : 	Ressyahoukou_Nobori 	
	 @return
		�R���e�i�ւ̃C���^�[�t�F�[�X��Ԃ��܂��B
	
		���̃R���e�i�̃C���f�N�X�́A�w���Index�x�ł��B
	 */
	virtual const Mu< const CentDedDgrRessya* >*	getCentDedDgrRessyaCont( 
		 ERessyahoukou eRessyahoukou )const ;
	///@}

	// ********************************
	///@name CentDedDgrDia-����
	// ********************************
	///@{
	/**
		�w�H���x (CentDedRosen) �I�u�W�F�N�g�Ɋ܂܂��
		�w�w�x (CentDedEki) �E�w�_�C���x (CentDedDia) �E
		�w��ԁx (CentDedRessya) �I�u�W�F�N�g�����ƂɁA
		�w�_�C���O�����w�x (CentDedDgrEki) �E
		�w�_�C���O������ԁx (CentDedDgrRessya) �I�u�W�F�N�g�𐶐����܂��B
	
		   m_CentDedDgrRessyaCont ������܂ŕێ����Ă����I�u�W�F�N�g��
		�j�����܂��B
		
	 @param pCentDedRosen [in]
		�ǂݎ��w�H���x�I�u�W�F�N�g���w�肵�ĉ������B
	 @param pCentDedDia [in]
		�ΏۂƂȂ�w�_�C���x�I�u�W�F�N�g���w�肵�Ă��������B
	 */
	virtual void readCentDedRosen( 
		const CentDedRosen* pCentDedRosen , 
		const CentDedDia* pCentDedDia ) ;
	
	
	/**
		�w�wOrder(�w������Index)�x���A�w�wIndex�x�ɕϊ����܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		�̂����ꂩ�ł��B
	 @param iEkiOrder [in]
		�w�wOrder�x���w�肵�Ă��������B
	 @return 
		0�ȏ�́w�wIndex�x��Ԃ��܂��B
		�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	virtual int EkiIndexOfEkiOrder( ERessyahoukou eRessyahoukou , 
		int iEkiOrder )const ;
	
	/**
		�w�wIndex�x���w�wOrder(�w������Index)�x�ɕϊ����܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		�̂����ꂩ�ł��B
	 @param iEkiIndex [in]
		�w�wIndex�x���w�肵�Ă��������B
	 @return 
		0�ȏ�́w�wOrder�x��Ԃ��܂��B
		�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	virtual int EkiOrderOfEkiIndex(  ERessyahoukou eRessyahoukou , 
		int iEkiIndex )const ;
	
	/**
	 @return
		�w�_�C���O�����G���e�B�e�B���W�n�x�͈̔͂�Ԃ��܂��B
	
		�w�_�C���O�����G���e�B�e�BX���W�x�͈̔͂́A 
		Pos �� m_iXZahyouMin  , Size �� 24*60*60 �܂łł��B
		����́A�u�_�C���O�����͍��[�̎����� m_iXZahyouMin �ƂȂ��Ă���A
		���ɂQ�S���ԕ��̒����������Ă���v���Ƃ������܂��B
	
	   �w�_�C���O�����G���e�B�e�BY���W�x�̒l�͈̔͂́APos �� 0 �E Size ��
		�N�_����I�_�܂ł̊e�w�Ԃ́w�w�ԍŏ��b���x�ƁA
		�S���̉w�́w�w�̕��x�����v�������̂ƂȂ�܂��B
	 */
	virtual CdDcdZoneXy	getZone()const ;

	/**
		�w�wIndex�x�ɑΉ�����A�w�_�C���O�����G���e�B�e�BY���W�x�̒l��
		���߂܂��B
	 @param iEkiIndex [in]
		�w�wIndex�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ�Am_CentDedDgrEkiCont.size() �����ł��B
		INT_MAX�́A�����i�����Ԃ̏I���w�j���w�肵�����ƂɂȂ�܂��B
		����́A�w�_�C���O�����G���e�B�e�BY���W�x�̍ő�l�ƂȂ�܂��B
	 @return
		�w�wIndex�x�ɑΉ�����w�_�C���O�����G���e�B�e�BY���W�x��Ԃ��܂��B
		�l�� 0 �ȏ�ł��B
		�w�wIndex�x���s���ȏꍇ�́A -1 ��Ԃ��܂��B
	
	 */
	virtual int getDgrYPosOfEki( int iEkiIndex )const ;
	
	/**
		�w�wOrder�x�ɑΉ�����A�w�_�C���O�����G���e�B�e�BY���W�x�̒l��
		���߂܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		�̂����ꂩ�ł��B
	 @param iEkiOrder [in]
		�w�wOrder�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ�Am_CentDedDgrEkiCont.size() �����ł��B
		INT_MAX�́A�����i�I���w�j���w�肵�����ƂɂȂ�܂��B
		����́A�w�_�C���O�����G���e�B�e�BY���W�x�̍ő�l�ƂȂ�܂��B
	 @return
		�w�wOrder�x�ɑΉ�����w�_�C���O�����G���e�B�e�BY���W�x��Ԃ��܂��B
		�l�� 0 �ȏ�ł��B
		�w�wOrder�x���s���ȏꍇ�́A -1 ��Ԃ��܂��B
	
	 */
	virtual int getDgrYPosOfEki( ERessyahoukou eRessyahoukou , 
		int iEkiOrder )const ;

	/**
		�Q�̉w�̊Ԃ́w�_�C���O�����G���e�B�e�BY���W�x�ɂ��
		�w�w�ԕ��x�̍��v�����߂܂��B
		���̒l�́A�e�w�̉w���͊܂߂܂���B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		�̂����ꂩ�ł��B
	 @param iEkiOrderOrg [in]
		�N�_���́w�wOrder�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ�Am_CentDedDgrEkiCont.size() �����ł��B
		INT_MAX�́A�����i�I���w�j���w�肵�����ƂɂȂ�܂��B
	 @param iEkiOrderDst [in]
		�I�_���́w�wOrder�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ�Am_CentDedDgrEkiCont.size() �����ł��B
		INT_MAX�́A�����i�I���w�j���w�肵�����ƂɂȂ�܂��B
	 @return
		�w�_�C���O�����G���e�B�e�BY���W�x��ł̋�����Ԃ��܂��B
		�l�� 0 �ȏ�ł��B
		�p�����[�^���s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	virtual int getDgrYSizeEkikan( 
			ERessyahoukou eRessyahoukou , 
			int iEkiOrderOrg ,
			int iEkiOrderDst )const ;
	
	
	/**
		�Q�̉w�̊Ԃ́w�w�ԍŏ��b���x�̘a��
		���߂܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
		- Ressyahoukou_Kudari
		- Ressyahoukou_Nobori
		�̂����ꂩ�ł��B
	 @param iEkiOrderOrg [in]
		�N�_���́w�wOrder�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ�Am_CentDedDgrEkiCont.size() �����ł��B
		INT_MAX�́A�����i�I���w�j���w�肵�����ƂɂȂ�܂��B
	 @param iEkiOrderDst [in]
		�w�wOrder�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ�Am_CentDedDgrEkiCont.size() �����ł��B
		INT_MAX�́A�����i�I���w�j���w�肵�����ƂɂȂ�܂��B
	 @return
		�w�wOrder�x�ɑΉ�����w�w�ԍŏ��b���x�̒l��Ԃ��܂��B
		�l�� 0 �ȏ�ł��B
		�p�����[�^���s���ȏꍇ�́A -1 ��Ԃ��܂��B
	
	 */
	virtual int getEkikanSaisyouSec( 
			ERessyahoukou eRessyahoukou , 
			int iEkiOrderOrg ,
			int iEkiOrderDst )const ;
	
	

	/**
		��Ԑ��̎n�_��
		�w�_�C���O�����G���e�B�e�B���W�x���Z�o���܂��B
	@param pCentDedDgrRessya [in]
		��Ԑ����܂����ԃI�u�W�F�N�g���w�肵�Ă��������B
	@param pCentDedDgrRessya [in]
		��Ԑ��I�u�W�F�N�g���w�肵�Ă��������B
	@return
		��Ԑ��̎n�_�̃_�C���O�����G���e�B�e�B���W�ł��B
	*/
	virtual CdDcdPosXy	calcDgrPosRessyasenKiten( 
		const CentDedDgrRessya* pCentDedDgrRessya , 
		const CentDedDgrRessyasen* pCentDedDgrRessyasen )const ;

	/**
		��Ԑ��̏I�_��
		�w�_�C���O�����G���e�B�e�B���W�x���Z�o���܂��B
	@param pCentDedDgrRessya [in]
		��Ԑ����܂����ԃI�u�W�F�N�g���w�肵�Ă��������B
	@param pCentDedDgrRessya [in]
		��Ԑ��I�u�W�F�N�g���w�肵�Ă��������B
	@return
		��Ԑ��̎n�_�̃_�C���O�����G���e�B�e�B���W�ł��B
	*/
	virtual CdDcdPosXy	calcDgrPosRessyasenSyuuten( 
		const CentDedDgrRessya* pCentDedDgrRessya , 
		const CentDedDgrRessyasen* pCentDedDgrRessyasen )const ;

	/**
		�_�C���O������ԃI�u�W�F�N�g����A
		�w���莞����ԃI�u�W�F�N�g�x�𐶐����܂��B
	
	�w���莞����ԃI�u�W�F�N�g�x

		���ׂĂ̒ʉ߉w�E��ԉw�̉w�����Ƃ��āA
		��Ԑ��I�u�W�F�N�g�ɏ������������ݒ肳��܂��B

		��Ԑ��N�_�̉w�����́A���̉w�̔������ƂȂ�܂��B
		��Ԑ����Ԃ̉w�����́A���E���Ƃ���Ԑ��Ɖw���̌�_�̎����ƂȂ�܂��B
		��Ԑ��I�_�̉w�����́A���̉w�̒������ƂȂ�܂��B

	@param pCentDedDgrRessya [in]
		�ΏۂƂȂ��ԃI�u�W�F�N�g���w�肵�Ă��������B
	@param pCentDedRessya [out]
		���̊֐��́A���̗�ԃI�u�W�F�N�g�ɁA�w���莞���x���������݂܂��B

	@return
		��� 0 �ł��B
	*/
	virtual void createEstimateRessya( 
		const CentDedDgrRessya* pCentDedDgrRessya ,
		CentDedRessya* pCentDedRessya )const ;

	/**
		�_�C���O������ԃI�u�W�F�N�g����A
		�w���莞����ԃI�u�W�F�N�g�x�𐶐����܂��B
	
	�w���莞����ԃI�u�W�F�N�g�x

		���ׂĂ̒ʉ߉w�E��ԉw�̉w�����Ƃ��āA
		��Ԑ��I�u�W�F�N�g�ɏ������������ݒ肳��܂��B

		��Ԑ��N�_�̉w�����́A���̉w�̔������ƂȂ�܂��B
		��Ԑ����Ԃ̉w�����́A���E���Ƃ���Ԑ��Ɖw���̌�_�̎����ƂȂ�܂��B
		��Ԑ��I�_�̉w�����́A���̉w�̒������ƂȂ�܂��B

	@note createEstimateRessya() �Ƃ̈Ⴂ�́A�o�R�Ȃ���Ԃɂ��铯��w���ɁA
		���ꎞ����ݒ肷�邱�Ƃł��B

	@param pCentDedDgrRessya [in]
		�ΏۂƂȂ��ԃI�u�W�F�N�g���w�肵�Ă��������B
	@param pCentDedRessya [out]
		���̊֐��́A���̗�ԃI�u�W�F�N�g�ɁA�w���莞���x���������݂܂��B

	@return
		��� 0 �ł��B
	*/
	virtual void createEstimateRessya2( 
		const CentDedDgrRessya* pCentDedDgrRessya ,
		CentDedRessya* pCentDedRessya )const ;

	///@}

};

} //namespace entDgr

#endif /*CentDedDgrDia_h*/
