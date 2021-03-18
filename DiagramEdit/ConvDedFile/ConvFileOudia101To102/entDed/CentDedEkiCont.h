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
//	CentDedEkiCont.h
//	$Id: CentDedEkiCont.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CentDedEkiCont_h
#define  CentDedEkiCont_h

#include "Mu/CMuiCopied.h"

#include "CentDed.h"
#include "CentDedEki.h"
#include "CdDedjikokuOrder.h"

// ****************************************************************
//	CentDedEkiCont
// ****************************************************************
/**
 @brief
  �w�w�x(CentDedEki) �I�u�W�F�N�g�̃R���e�i�ł��B

  	���̃N���X���̂́A Mui< CentDedEki > �C���^�[�t�F�[�X��
  	�T�|�[�g���܂��B���̃C���^�[�t�F�[�X�ɂ��A CentDedEki �I�u�W�F�N�g��
  	�ǉ��E�ύX�E�폜���邱�Ƃ��ł��܂��B
  
  	  �����Ȃ��� getMuPtr() ���\�b�h�ɂ��A Mu< const CentDedEki* >
  	�C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
  	  ���̃C���^�[�t�F�[�X���g���ƁA�R���e�i���� CentDedEki 
  	�I�u�W�F�N�g�ɒ��ڃA�N�Z�X���邱�Ƃ��ł��܂����A
  	CentDedEki �I�u�W�F�N�g�̑�����ύX���邱�Ƃ͂ł��܂���B
  	�����̕ύX�́A set() ���\�b�h���g��Ȃ��Ă͂Ȃ�܂���B
  
  	  �܂��A��ԕ���( ERessyahoukou )�̈������Ƃ� getMuPtr() 
  	���\�b�h�ɂ��A ��ԕ����ʂ�
  		Mu< CentDedEkiCont::CdDedEki >
  	�C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
  	���̕��@�ŁA�w�wOrder�x�ɑΉ�����w�̏����擾���邱�Ƃ��ł��܂��B
  	
   @attention
  	this �� get() ���\�b�h�́A CentDedEki �I�u�W�F�N�g�̃R�s�[��Ԃ��܂��B
  	get() ���\�b�h�ŕԂ��ꂽ�I�u�W�F�N�g�ɑ΂��āA
  	CentDedEki �I�u�W�F�N�g���X�V���郁�\�b�h���Ăяo���Ă��A
  	�R���e�i���̉w�I�u�W�F�N�g���X�V���邱�Ƃ͂ł��܂���B
  	�R���e�i���̉w�I�u�W�F�N�g�̃��\�b�h���Ăяo���ꍇ�́A
  	getMuPtr() �� Mu<const CentDedEki*>* ���擾���Ă���A
  	���̃C���^�[�t�F�[�X�o�R�� CentDedEki* ���擾���A���̃|�C���^��
  	���\�b�h���Ăяo���Ă��������B
  

	<H4>
	�y�wIndex �� �wOrder , ����Order�z
	</H4>
	  �w�H���x ( CentDedRosen ) �I�u�W�F�N�g���̓����
	�w�w�x ( CentDedEki )�I�u�W�F�N�g���w�肷����@�A�y��
	�w��ԁx ( CentDedRessya )�I�u�W�F�N�g���̓����
	�w�w�����x ( CentDedEkiJikoku ) �I�u�W�F�N�g���w�肷����@�ɂ́A
	�w�wIndex�x�E�w�wOrder�x�̂Q������܂��B�ǂ�����A
	0 �ȏ� ( �w�̐�) ���� �̐����ŁA�w�w�x���w�肵�܂��B
	
	  �w�wIndex�x�́A�H���̉����Ԃ̎n���w�i����Ԃ̏I���w�j�� 0 �E 
	�����Ԃ̏I���w�i����Ԃ̎n���w�j �� ( �w�̐� - 1 ) �ƂȂ�܂��B
	
	  �w�wOeder�x�́A��Ԃ̕����ʂ̃C���f�N�X�ł��B�����ԁE�����
	�Ƃ��Ɏn���w�� 0 �E �I���w�� ( �w�̐� - 1 ) ��
	�Ȃ�܂��B

	  �]���āA�w�wIndex�x�� 0 �̉w�́A�����ԂɂƂ��Ắw�wOeder�x ��
	 0 �ł����A����ԂɂƂ��Ắw�wOrder�x �� �i�w�̐� - 1 �j�ƂȂ�܂��B 
	
	  �w�H���x ( CentDedRosen ) �N���X�ł́A�����Ƃ���
	�w�w�x( CentDedEki ) �I�u�W�F�N�g���w�肷��̂Ɂw�wIndex�x���g���܂��B
	�w�w�x��ێ�����R���e�i CentDedRosen::m_CentDedEkiCont �̓Y������
	�w�wIndex�x�ɂȂ��Ă��܂��B@n
	  ����Ƃ͑ΏƓI�ɁA�w��ԁx(�N���X�ł́A�����Ƃ���
	�w�w�����x ( CentDedEkiJikoku ) �I�u�W�F�N�g���w�肷��̂ɂ�
	�w�wOrder�x���g���܂��B�w�w�����x ( CentDedEkiJikoku ) ��ێ�����R���e�i
	  CentDedRessya::m_CentDedEkiJikokuCont �̓Y�������A�w�wOrder�x 
	�ƂȂ�܂��B
	  �ǂ���̃N���X�ɂ����Ă��A�w�wIndex�x�Ɓw�wOrder�x�̑��ݕϊ����s��
	���\�b�h EkiIndexOfEkiOrder() , EkiOrderOfEkiIndex() ��񋟂��Ă��܂��B
	
	�w����Order�x�́A�w��ԁx�I�u�W�F�N�g���ŁA����̎���
	�i����w�̒��E���̂����ꂩ�j���w�肷�鏇�����ł��B
	�w����Order�x�́A�ȉ��̖@���������܂��B
	�l�͈̔͂́A0 �ȏ� �w�̐�*2 �����ł��B
	
	- �w�wOrder�x*2 + 0 �E�E�E�w�wOrder�x�̉w�̒�����(�Ƃ���ȍ~)
	��ύX���܂��B
	- �w�wOrder�x*2 + 1 �E�E�E�w�wOrder�x�̉w�̔�����(�Ƃ���ȍ~)
	��ύX���܂��B
	

<H4>
�y����Order�Ǝ����\Index�z
</H4>
	�����\Index�́A�����\��ŉwOrder�ɑΉ����钅�����E��������
	���s�ڂɈʒu���邩�������܂��B
	���̒l�͊e�w�̉w�����`���̉e�����󂯂܂��B

(��)
  ������
	- �wOrder=0 �w�����`��=������  ; 
		- ������(����Order=0) �̎����\Index=�Ȃ� 
		- ������(����Order=1)�̎����\Index=0 
	- �wOrder=1 �w�����`��=������  ; 
		- ������(����Order=2)�̎����\Index=�Ȃ� 
		- ������(����Order=3)�̎����\Index=1 
	- �wOrder=2 �w�����`��=����    ; 
		- ������(����Order=4)�̎����\Index=2 
		- ������(����Order=5)�̎����\Index=3 
	- �wOrder=3 �w�����`��=���蒅���� ; 
		- ������(����Order=6)�̎����\Index=4 
		- ������(����Order=7)�̎����\Index=�Ȃ� 
	- �wOrder=4 �w�����`��=��蒅���� ; 
		- �������̎����\Index=�Ȃ� 
		- �������̎����\Index=5 
	- �wOrder=5(�I���w) �w�����`��=������  ; 
		- �������̎����\Index=6 
		- �������̎����\Index=�Ȃ� 


*/
class CentDedEkiCont : public CMuiCopied< CentDedEki >
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	typedef CMuiCopied< CentDedEki >	super ;

	/** �����\�r���[�̉w���̗�̎�ނ�\���񋓂ł��B */
	enum EEkiColumnType
	{
		EEkiColumnType_Chaku = 0 ,	///<������
		EEkiColumnType_Hatsu = 1 ,	///<������
	};
	// ****************************************************************
	//	CentDedEkiCont::CdDedEki
	// ****************************************************************
	/**
	   @brief
	  	�w�̏���ێ�����A�P���f�[�^�N���X�ł��B
	  	CentDedEkiCont::getMuPtr() ���\�b�h�ɂ��A 
	  	Mu< CentDedEkiCont::CdDedEki > �C���^�[�t�F�[�X���擾����ƁA
	  	�R���e�i���̉w�̑������A���̌`���Ŏ擾���邱�Ƃ��ł��܂��B
	  
	  	���̒P���f�[�^�N���X�Ŏ擾������́A��ԕ���{����,���}�ɍ��킹��
	  	�`���ɂȂ��Ă��܂��B
	  	�Ⴆ�΁A�w�����`����[���蒅����]�ƂȂ��Ă���w���������ꍇ�A
	  
	  	���̉w�� CentDedEkiCont::CdDedEki �I�u�W�F�N�g����������Ŏ擾�����
	  		- m_bChakujikokuHyouji = true ;
	  		- m_bHatsujikokuHyouji = false ;
	  
	  	�����w�� CentDedEkiCont::CdDedEki �I�u�W�F�N�g���������Ŏ擾�����
	  		- m_bChakujikokuHyouji = false ;
	  		- m_bHatsujikokuHyouji = true ;
	  
	  	�ƂȂ�܂��B
	 */
	class CdDedEki
	{
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
		  	�������\������B
		 */
		bool m_bChakujikokuHyouji ;
	
		/**
		  	�w�����`���B
		  	�������\������B
		 */
		bool m_bHatsujikokuHyouji ;
		
		/**
		  	�w�w�K�́x��\���񋓂ł��B
		  
		  	�K��l�́A Ekikibo_Ippan 
		 */
		CentDedEki::EEkikibo	m_eEkikibo ;
	
		/**
		  	���̉w�̉��i�I���w���j�ɁA���E������B
		  
		   	���̑����� true �̉w�ł́A�����\��ʂ̉w���̉�����
		  	�������E����`�悵�܂��B
		   	���̑����́A�w�r���[�Ǝ����\�r���[�ɓK�p����܂��B
		 */
		bool m_bKyoukaisen ;

		/**
			�_�C���O������ԏ��\��
		
			���̑����� true �̉w�ł́A�_�C���O�����r���[�ɂ����āA
			��Ԃ̗�ԏ���`�悵�܂��B

			����l�� false �ł��B
		*/	
		CentDedEki::EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyouji ;

		///@}
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	 public:
		CdDedEki() : 
			m_bChakujikokuHyouji( false ) , 
			m_bHatsujikokuHyouji( false ) ,
			m_eEkikibo( CentDedEki::Ekikibo_Ippan ) ,
			m_bKyoukaisen( false ) , 
			m_eDiagramRessyajouhouHyouji( CentDedEki::DiagramRessyajouhouHyouji_Origin ){};

		CdDedEki(
			const std::string&	strEkimei ,
			bool bChakujikokuHyouji ,
			bool bHatsujikokuHyouji ,
			CentDedEki::EEkikibo	eEkikibo ,
			bool bKyoukaisen , 
			CentDedEki::EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyouji ):
			m_strEkimei( strEkimei ),
			m_bChakujikokuHyouji( bChakujikokuHyouji ) ,
			m_bHatsujikokuHyouji( bHatsujikokuHyouji ) ,
			m_eEkikibo( eEkikibo ) ,
			m_bKyoukaisen( bKyoukaisen ), 
			m_eDiagramRessyajouhouHyouji( eDiagramRessyajouhouHyouji ) {};

	// ********************************
	//	CentDedEkiCont::CdDedEki
	// ********************************
	 public:
		// ********************************
		///@name CentDedEkiCont::CdDedEki-����
		// ********************************
		///@{
		std::string	getEkimei()const{	return m_strEkimei ;};
		CdDedEki& setEkimei( const std::string& value ){	
			m_strEkimei = value ;return *this ; } ;
		bool getChakujikokuHyouji()const{	return m_bChakujikokuHyouji ;};
		CdDedEki& setChakujikokuHyouji( bool value ){	
			m_bChakujikokuHyouji = value ; return *this ; } ;
		bool getHatsujikokuHyouji()const{ return m_bHatsujikokuHyouji ;};
		CdDedEki& setHatsujikokuHyouji( bool value ){
			m_bHatsujikokuHyouji = value ; return *this ; } ;
		CentDedEki::EEkikibo	getEkikibo()const{ return m_eEkikibo ;};
		CdDedEki& setEkikibo( CentDedEki::EEkikibo value ){
			m_eEkikibo = value ; return *this ; } ;
		bool getKyoukaisen()const{ return m_bKyoukaisen ;};
		CdDedEki& setKyoukaisen( bool value ){
			m_bKyoukaisen = value ; return *this ; } ;
		CentDedEki::EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyouji()const
		{	return m_eDiagramRessyajouhouHyouji ;};
		CdDedEki& setDiagramRessyajouhouHyouji( CentDedEki::EDiagramRessyajouhouHyouji value )
		{	m_eDiagramRessyajouhouHyouji = value ; return *this ;};

		/**
		   @return 
		  	�����̗����̎�����\������w�ł͐^�ł��B
		 */
		bool isHatsuChakuHyouji()const
		{	return m_bChakujikokuHyouji && m_bHatsujikokuHyouji;};
	
		///@}
	};

private:
	// ----------------------------------------------------------------
	//	CentDedEkiCont::ContKudari
	// ----------------------------------------------------------------
	/**
	   @brief
	  	����́w�wOrder�x ���C���f�N�X�Ƃ����A
	  		 Mu< CentDedEkiCont::CdDedEki > 
	  	���쐬���邽�߂̃A�_�v�^�ł��B
	 */
	class ContKudari : public Mu< CdDedEki >
	{
	public:
		// ********************************
		//	Mu< CentDedEkiCont::CdDedEki >
		// ********************************
		/**
		   @return 
		  	�R���e�i�Ɋi�[����Ă���f�[�^�̌���Ԃ��܂��B 
 		 */
		virtual int  size()const ; 
		/**
		  	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă��� 
		  	�f�[�^��Ԃ��܂��B 
		   @param iEkiOrder [in] 
		  	���������́w�wOrder�x���w�肵�Ă��������B 
		  	�͈͂͂O�ȏ� size() �����ł��B
		  	 INT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 */
		virtual CdDedEki get(int iEkiOrder )const ;
	
		
	} m_xContKudari ;
	friend class ContKudari ;
	// ----------------------------------------------------------------
	//	CentDedEkiCont::ContNobori
	// ----------------------------------------------------------------
	/**
	   @brief
	  	���́w�wOrder�x ���C���f�N�X�Ƃ����A	
	  		 Mu< CentDedEkiCont::CdDedEki > 
	  	���쐬���邽�߂̃A�_�v�^�ł��B
	 */
	class ContNobori : public Mu< CdDedEki >
	{
	public:
		// ********************************
		//	Mu< CentDedEkiCont::CdDedEki >
		// ********************************
		/**
		   @return 
		  	�R���e�i�Ɋi�[����Ă���f�[�^�̌���Ԃ��܂��B 
 		 */
		virtual int  size()const ; 
		/**
		  	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă��� 
		  	�f�[�^��Ԃ��܂��B 
		   @param iEkiOrder [in] 
		  	�������́w�wOrder�x���w�肵�Ă��������B 
		  	�͈͂͂O�ȏ� size() �����ł��B
		  	 INT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 */
		virtual CdDedEki get(int iEkiOrder )const ;
	
	} m_xContNobori ;
	friend class ContNobori ;
	
private:
	// ********************************
	///@name ���
	// ********************************
	///@{	
	///@}



public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CentDedEkiCont() ;
	CentDedEkiCont( const CentDedEkiCont& value ) ;
	CentDedEkiCont& operator=( const CentDedEkiCont& value ) ;
	virtual ~CentDedEkiCont() ;
	
public:
	// ********************************
	///@name	CMuiCopied<CentDedEki>
	// ********************************
	///@{

	/**
		��{�N���X�� Mu<CentDedEki*>* getMuPtr() �́A
		���̃N���X�̃I�[�o�[���[�h
		Mu<CdDedEki>* getMuPtr( ERessyahoukou eRessyahoukou )
		�ɂ���ĉB������܂��B
		���̉B�����������邽�߁A�ȉ��̐錾���s���Ă��܂��B
		����́A�ȉ��̃R�[�h�Ɠ����ł��B
	@code
	Mu<CentDedEki*>* getMuPtr()
	{	
		return super::getMuPtr() ;
	};
	const Mu<const CentDedEki*>* getMuPtr()const
	{
		return super::getMuPtr() ;
	};
	@endcode
	*/
	super::getMuPtr ;
	///@}


// ********************************
//	CentDedEkiCont
// ********************************
public:
	// ********************************
	///@name CentDedEkiCont-����
	// ********************************
	///@{
	/**
		�w�wOrder�x ���C���f�N�X�ɂ��āA�R���e�i���̉w�I�u�W�F�N�g��
		�����擾���邽�߂̃C���^�[�t�F�[�X��Ԃ��܂��B
	
		���̃C���^�[�t�F�[�X�������ƁA�w�wOrder�x���C���f�N�X�Ɏw�肵�āA
		�Ή�����w�̏��� CentDedEkiCont::CdDedEki �`����
		�擾���邱�Ƃ��ł��܂��B
	 @param eRessyahoukou [in]
		��ԕ������w�肵�Ă��������B
	 @return 
		�R���e�i���̉w�I�u�W�F�N�g CentDedEki �I�u�W�F�N�g�̑�����Ԃ�
		�C���^�[�t�F�[�X��Ԃ��܂��B
	 */
	Mu<CdDedEki>* getMuPtr( ERessyahoukou eRessyahoukou )
	{
		if ( eRessyahoukou == Ressyahoukou_Nobori ){
			return &m_xContNobori ;	
		}
		return &m_xContKudari ;	
	};
	const Mu<CdDedEki>* getMuPtr( ERessyahoukou eRessyahoukou )const
	{
		if ( eRessyahoukou == Ressyahoukou_Nobori ){
			return &m_xContNobori ;	
		}
		return &m_xContKudari ;	
	};
	
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
	int EkiIndexOfEkiOrder( ERessyahoukou eRessyahoukou , int iEkiOrder )const ;
	
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
	int EkiOrderOfEkiIndex( ERessyahoukou eRessyahoukou , int iEkiIndex )const;

	///@}

};



#endif /*CentDedEkiCont_h*/
