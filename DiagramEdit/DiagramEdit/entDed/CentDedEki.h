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
//	CentDedEki.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedEki_h
#define  CentDedEki_h

#include <string>
#include "NsMu\CChildBase.h"
#include "CentDedEkiTrackCont.h"

namespace entDed{

	using OuLib::NsMu::CChildBase ;

// ****************************************************************
//	CentDedEki
// ****************************************************************
/**
@brief
  DiagramEdit �́A�H���ɂ���w�ЂƂ�\���܂��B

  �����Ƃ��āA�w�w���x�E�w�w�����`���x�E�w�w�K�́x��ێ����܂��B
  �܂��ACentDedEkiTrackCont ���܂��܂��B

����
 -------------------------------- 


����̃G���[�����E�C��
 -------------------------------- 

���e�I�u�W�F�N�g�̕ύX(setParent()):  adjust()�����s����

���㏑��(operator=) : ���̃I�u�W�F�N�g���A�e�I�u�W�F�N�gCentDedEkiCont �̎q�ł���ꍇ�ŁA������� CentDedEkiCont::set() �ŃG���[�ɂȂ�ꍇ�A��O�X���[�ɂȂ�܂��B

����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 
��CentDedEkiTrackCont(�Ԑ��R���e�i)�ɁAadjust()���Ϗ�����B

*/
class CentDedEki : public CChildBase
{
	typedef CChildBase	super ;
public:
	// ****************************************************************
	//	�C���i�[�^�C�v
	// ****************************************************************
	/**
		�w�w�����`���x��\���񋓂ł��B
	 */
	enum EEkijikokukeisiki
	{
		/**
			�������݂̂̕\���B(�K��l)
		
			(�������A�I���w�ł͒������݂̂�\�����܂�)
		 */
		Jikokukeisiki_Hatsu = 0 ,
		
		/**
			�����\���B
		
			����E���Ƃ��A���������̎�����\���B
			(�n���w�E�I���w�ł�����������\��)
		 */
		Jikokukeisiki_Hatsuchaku ,

		/**
			���蒅�\���B
		
			-	�����Ԃł́A�������݂̂̕\���B
			-	����Ԃł́A�������݂̂̕\���B
			(�������A�I���w�ł͒������݂̂�\�����܂�)
		 */
		Jikokukeisiki_KudariChaku ,
		
		/**
			��蒅�\���B
		
			-	�����Ԃł́A�������݂̂̕\���B
			(�������A�I���w�ł͒������݂̂�\�����܂�)
			-	����Ԃł́A�������݂̂̕\���B
		 */
		Jikokukeisiki_NoboriChaku ,
		
	};
	
	/**
		�w�w�K�́x��\���񋓂ł��B
	 */
	enum EEkikibo
	{
		/**
			��ʉw�B(�K��l)
		 */
		Ekikibo_Ippan = 0 ,
		/**
			��v�w�B
		
			��v�w�ł́A�_�C���O�����̌r���������ɂȂ�܂��B
		 */
		Ekikibo_Syuyou ,
	};
	
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

	/**
		���̃N���X���X���[�����O
	*/
	class LException
	{
	};
	

private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�w��
	
		�K��l�́A�󕶎���B
	 */
	std::string	m_strEkimei ;
	
	/**
		�w�����`���B
	
		�K��l�́A Jikokukeisiki_Hatsuhyouji 
	 */
	EEkijikokukeisiki	m_eEkijikokukeisiki ;
	
	/**
		�w�w�K�́x��\���񋓂ł��B
	
		�K��l�́A Ekikibo_Ippan 
	 */
	EEkikibo	m_eEkikibo ;
	
	/**
		���E������B
	
	  ���̑����� true �̉w�ł́A�����\��ʂ�
		��������̉��ɁA�������E����`�悵�܂��B
	  ���̑����́A�w�r���[�Ǝ����\�r���[�ɓK�p����܂��B
	 */
	bool m_bKyoukaisen ;

	/**
		�_�C���O������ԏ��\���i����j
	
		����l�� DiagramRessyajouhouHyouji_Origin �ł��B
	*/	
	EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyoujiKudari ;
	
	/**
		�_�C���O������ԏ��\���i���j
	
		���̑����� true �̉w�ł́A�_�C���O�����r���[�ɂ����āA
		�����Ԃ̗�ԏ���`�悵�܂��B

		����l�� DiagramRessyajouhouHyouji_Origin �ł��B
	*/
	EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyoujiNobori ;

	
	
	///@}
private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
	@brief
		CentDedEki �ɕ�܂���� CentDedEkiTrackCont
	*/
	class CXentDedEkiTrackCont : public CentDedEkiTrackCont
	{
	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************
		

	public:
		// ********************************
		///@name CentDedEkiTrackCont-�֘A
		// ********************************
		///@{
		/**
		@return
			�O���� CentDedEki �I�u�W�F�N�g��Ԃ��܂��B
		*/
		virtual CentDedEki* getEki();
		/**
		@return
			�O���� CentDedEki �I�u�W�F�N�g��Ԃ��܂��B
		*/
		virtual const CentDedEki* getEki()const;
	};
	
	/** CentDedEki �ɕ�܂���� CentDedEkiTrackCont */	
	CXentDedEkiTrackCont m_EkiTrackCont ;
	///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	CentDedEki() ;
	
	/**
	 @param strEkimei [in]
		�w��
	 @param eEkijikokukeisiki [in]
		�w�����`���B
	 @param eEkikibo [in]
		�w�w�K�́x��\���񋓂ł��B
	 @param bKyoukaisen [in]
		���E������B
	  ���̑����� true �̉w�ł́A�����\��ʂ�
		��������̉��ɁA�������E����`�悵�܂��B
	  ���̑����́A�w�r���[�Ǝ����\�r���[�ɓK�p����܂��B
	  
	@param eDiagramRessyajouhouHyoujiKudari
		�_�C���O������ԏ��\���i����j
	@param eDiagramRessyajouhouHyoujiNobori
		�_�C���O������ԏ��\���i���j
	*/
	CentDedEki( const std::string& strEkimei , 
			EEkijikokukeisiki	eEkijikokukeisiki ,
			EEkikibo	eEkikibo , 
			bool bKyoukaisen , 
			EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyoujiKudari 
				= DiagramRessyajouhouHyouji_Origin ,
			EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyoujiNobori 
				= DiagramRessyajouhouHyouji_Origin ) ;

	/** 
		���̃I�u�W�F�N�g���A�e�I�u�W�F�N�gCentDedEkiCont ��
		�q�ł���ꍇ�ŁA������� CentDedEkiCont::set() �ŃG���[��
		�Ȃ�ꍇ�A��O�X���[�ɂȂ�܂��B
	@param value 
		�����
	@exception LException 
	*/
	CentDedEki& operator=( const CentDedEki& value ) ;


	

public:
	// ********************************
	///@name CParentBase-����
	// ********************************
	///@{
	/** ���e�I�u�W�F�N�g�̕ύX(setParent()):  adjust()�����s���� */
	virtual void setParent( CParentBase* pParent ) ;
	///@}

public:
	// ********************************
	///@name CentDedEki-����
	// ********************************
	///@{
	/** @see m_strEkimei */
	std::string	getEkimei()const{	return m_strEkimei ;};
	/** @see m_strEkimei */
	void setEkimei( const std::string& value ){
		m_strEkimei = value ; } ;
	/** @see m_eEkijikokukeisiki */
	EEkijikokukeisiki	getEkijikokukeisiki()const{
		return 	m_eEkijikokukeisiki ;};
	/** @see m_eEkijikokukeisiki */
	void setEkijikokukeisiki( EEkijikokukeisiki	value ){
		m_eEkijikokukeisiki = value ; } ;
	/** @see m_eEkikibo */
	EEkikibo	getEkikibo()const{	return 	m_eEkikibo ;};
	/** @see m_eEkikibo */
	void setEkikibo( EEkikibo value ){
		m_eEkikibo = value ; } ;
	/** @see m_bKyoukaisen */
	bool getKyoukaisen()const{	return m_bKyoukaisen ; };
	/** @see m_bKyoukaisen */
	void setKyoukaisen( bool value ){	m_bKyoukaisen = value ; } ;

	/** @see m_eDiagramRessyajouhouHyoujiKudari */
	EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyoujiKudari()const
	{	return m_eDiagramRessyajouhouHyoujiKudari ;};
	/** @see m_eDiagramRessyajouhouHyoujiKudari */
	void setDiagramRessyajouhouHyoujiKudari( EDiagramRessyajouhouHyouji value )
	{	m_eDiagramRessyajouhouHyoujiKudari = value ;};
	/** @see m_eDiagramRessyajouhouHyoujiNobori */
	EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyoujiNobori()const
	{	return m_eDiagramRessyajouhouHyoujiNobori ;};
	/** @see m_eDiagramRessyajouhouHyoujiNobori */
	void setDiagramRessyajouhouHyoujiNobori( EDiagramRessyajouhouHyouji value )
	{	m_eDiagramRessyajouhouHyoujiNobori = value ;};

	///@}
	// ********************************
	///@name CentDedEki-���
	// ********************************
	///@{
	/** @see m_EkiTrackCont  */
	CentDedEkiTrackCont* getEkiTrackCont(){ return &m_EkiTrackCont ;}
	/** @see m_EkiTrackCont */
	const CentDedEkiTrackCont* getEkiTrackCont()const
	{ return &m_EkiTrackCont ;}
	///@}
	
	// ********************************
	///@name CentDedEki-����
	// ********************************
	///@{
	/**
		this �̑���������ɔ����Ă���ꍇ�A����ɍ����悤�ɁA������
		�C�����܂��B

		���̃N���X�ł́A�����͂���܂���B

	*/
	void adjust() ;
	///@}
};

} //namespace entDed

#endif /*CentDedEki_h*/
