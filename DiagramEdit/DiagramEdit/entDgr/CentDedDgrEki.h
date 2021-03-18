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
//	CentDedDgrEki.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrEki_h
#define  CentDedDgrEki_h


#include <string>

namespace entDgr{

// ****************************************************************
//	CentDedDgrEki
// ****************************************************************
/**
@brief
�y�T�v�z
�w�_�C���O�����G���e�B�e�B�N���X�Q�x�́w�_�C���O�����w�x�N���X�ł��B
�w�_�C���x (CentDedDgrDia) �Ɋ܂܂��w�w�x�P��\���܂��B

���̃N���X�́A�w�_�C���O�����_�C���x (CentDedDgrDia) �ɕ�܂���܂��B

CentDedDgrDia : CentDedDgrEki �̑��d�x�́A

�P�F�i�w�w�x�̐��j 

�ƂȂ�܂��B

����́A

�i�w�H���x(CentDedRosen)�j�F�i�w�w�x�iCentDedEki�j�j

�̑��d�x�Ɠ����ł��B

���̃N���X�̑����Ƃ��āA�w���w�܂ł̉w�ԍŏ��b���x������܂��B
�w���w�܂ł̉w�ԍŏ��b���x����A�w�_�C���O�����G���e�B�e�BY���W�x�𓱏o���܂��B

�y�g�����z

  �����ł́A���̃N���X�̃I�u�W�F�N�g�𐶐�����̂́A
�w�_�C���O�����_�C���x (CentDedDgrDia) �N���X�ɂ̃��\�b�h�����ł��B
�N���X���[�U�[�͂��̃N���X�̃I�u�W�F�N�g�𒼐ڐ�������p���͂Ȃ��A
�w�_�C���O�����_�C���x (CentDedDgrDia) �N���X�ɂ���Đ������ꂽ
�I�u�W�F�N�g�̑������Q�Ƃ��邾���ł��B


 */
class CentDedDgrEki
{
public:
	/**
		�_�C���O������ԏ��\��
	*/
	enum EDiagramRessyajouhouHyouji
	{
		/**
			�n���w�̏ꍇ�ɂ͕\��(����l)
		*/
		DiagramRessyajouhouHyouji_Origin ,
		/**
			��ɕ\������B
		*/
		DiagramRessyajouhouHyouji_Anytime ,
		/**
			�\�����Ȃ��B
		*/
		DiagramRessyajouhouHyouji_Not ,
	};

private:	
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
	 	�w���B
	 */
	std::string  m_strEkimei ;
	
	/**
	 	��v�w�Ȃ�^�ł��B
	 */
	bool  m_bIsSyuyoueki ;
	
	/**
	 	�����Ԃ̉w�ԍŏ��b���B
	 
	 	���̑����́A���̉w�Ǝ��̉wIndex�܂ł̊Ԃ́A
		�����Ԃ̍ŏ����v�b���ł��B
	 
	 	���̒l�́A�w�_�C���O����Y���W�x�ł́A�w�ԕ��Ƃ���
	 	�g���܂��B�w�_�C���O�����x�ł̉w�ԕ��iY���W�j�́A
	 	m_iEkikanSaisyouSecKudari,m_iEkikanSaisyouSecNobori�̂���
	 	�������ق��̒l�ƂȂ�܂��B
	 
	 	�����Ԃ��猩�Ă̏I�_�w�ł́A���̒l�� 0 �ł��B
	 
	 	�܂��A���̉w�Ԃł̉w�ԍŏ����v�b�����v�Z�s�\�i�f�[�^�Ȃ��j�̏ꍇ�́A
	 	 0 �ł��B
	 */
	int m_iEkikanSaisyouSecKudari ;
	/**
	 	����Ԃ̉w�ԍŏ��b���B
	 
	 	���̑����́A���̉w�Ǝ��̉wIndex�܂ł̊Ԃ́A
		����Ԃ̍ŏ����v�b���ł��B
	 
	 	�����Ԃ��猩�Ă̏I�_�w�ł́A���̒l�� 0 �ł��B
	 
	 	�܂��A���̉w�Ԃł̉w�ԍŏ����v�b�����v�Z�s�\�i�f�[�^�Ȃ��j�̏ꍇ�́A
	 	 0 �ł��B
	 */
	int m_iEkikanSaisyouSecNobori ;

	/**
		�_�C���O�����̊���̉w�ԕ��B

		��Ԑݒ�̂Ȃ��w�Ԃ́A�_�C���O�����r���[��ł�
		�c�����̕����w�_�C���O�����G���e�B�e�BY���W�x�P��(�b)�Ŏw�肵�܂��B
	
		����l�� 60 �ł��B
	*/
	int	m_iDgrYSizeEkikanDefault ;

	/**
		�_�C���O������ԏ��\���i����j
	
		����l�� DiagramRessyajouhouHyouji_Origin �ł��B
	*/	
	EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyoujiKudari ;
	
	/**
		�_�C���O������ԏ��\���i���j
	
		����l�� DiagramRessyajouhouHyouji_Origin �ł��B
	*/
	EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyoujiNobori ;

	/**
		���̉w��Y���W�̍����B
		���ʂ́A0�ł��B
	*/
	int m_iDgrYSize ;
	///@}	

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 @param strEkimei [in]
		�w���B
	 @param bIsSyuyoueki [in]
		��v�w�Ȃ�^
	 @param iEkikanSaisyouSecKudari [in]
		�����Ԃ̉w�ԍŏ��b���B
	 @param iEkikanSaisyouSecNobori [in]
		����Ԃ̉w�ԍŏ��b���B
	 @param iDiagramDgrYZahyouKyoriDefault [in]
		�_�C���O�����̊���̉w�ԕ��B
	 @param eDiagramRessyajouhouHyoujiKudari [in]
		�_�C���O������ԏ��\���i����j
	 @param eDiagramRessyajouhouHyoujiNobori [in]
		�_�C���O������ԏ��\���i���j
	*/
	CentDedDgrEki( const std::string&  strEkimei ,
		bool bIsSyuyoueki , 
		int iEkikanSaisyouSecKudari ,
		int iEkikanSaisyouSecNobori , 
		int	iDiagramDgrYZahyouKyoriDefault , 
		EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyoujiKudari ,
		EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyoujiNobori 
		) ;
	

	CentDedDgrEki() ;
	
	virtual ~CentDedDgrEki();
	
// ********************************
//	CentDedDgrEki
// ********************************
 public:
	// ********************************
	///@name	CentDedDgrEki-����
	// ********************************
	///@{
	std::string  getEkimei()const{ return m_strEkimei ;};
	bool getIsSyuyoueki()const{	return m_bIsSyuyoueki ; } ;
	int getEkikanSaisyouSecKudari()const
	{	return m_iEkikanSaisyouSecKudari ; };
	int getEkikanSaisyouSecNobori()const
	{	return m_iEkikanSaisyouSecNobori ; };
	int	getDgrYSizeEkikanDefault()const
	{	return m_iDgrYSizeEkikanDefault ;};

	EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyoujiKudari()const
	{	return m_eDiagramRessyajouhouHyoujiKudari ;};
	EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyoujiNobori()const
	{	return m_eDiagramRessyajouhouHyoujiNobori ;};
	int getDgrYSize()const{	return m_iDgrYSize ;};
	///@}
	// ********************************
	///@name	CentDedDgrEki-����
	// ********************************
	///@{
	/**
	  @return
	 	���̉w���牺������̎��̉w�i�w�wIndex�x�����̉w�j�܂ł́A
	 	�w�_�C���O�����G���e�B�e�BY���W�x�ł̋�����Ԃ��܂��B
	 
	 	  ���̒l�́A�w�����Ԃ̉w�ԍŏ��b���x�Ɓw����Ԃ̉w�ԍŏ��b���x��
	 	�����̏������ق��ł��B
	 
	 	  �A���A�w�����Ԃ̉w�ԍŏ��b���x�� 0 �ȉ��E�w����Ԃ̉w�ԍŏ��b���x
	 	�� 1 �ȏ�̏ꍇ�́A���̒l�́w����Ԃ̉w�ԍŏ��b���x�ƂȂ�܂��B
	 	���΂ɁA�w����Ԃ̉w�ԍŏ��b���x�� 0 �ȉ��E
	 	�w�����Ԃ̉w�ԍŏ��b���x�� 1 �ȏ�̏ꍇ�́A���̒l��
	 	�w�����Ԃ̉w�ԍŏ��b���x�ƂȂ�܂��B
	 
	 	  ���̒l�̍ŏ��l��60�ł��B
	 */
	int getDgrYZahyouKyori()const ;
	///@}

};

} //namespace entDgr
#endif /*CentDedDgrEki_h*/
