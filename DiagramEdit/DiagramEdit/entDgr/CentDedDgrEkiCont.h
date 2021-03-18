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
//	CentDedDgrEkiCont.h
//	$Id: CentDedDgrEkiCont.h 295 2016-06-11 05:14:13Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrEkiCont_h
#define  CentDedDgrEkiCont_h

#include "NsMu\CMuiCopied.h"
#include "entDed\CentDed.h"
#include "CentDedDgrEki.h"

namespace entDgr{
	using namespace entDed;
	using namespace OuLib::NsMu;

// ****************************************************************
//	CentDedDgrEkiCont
// ****************************************************************
/**
 @brief
	�_�C���O�����́w�w�x(CentDedEki) �I�u�W�F�N�g�̃R���e�i�ł��B

	���̃N���X���̂́A Mui< CentDedDgrEki > �C���^�[�t�F�[�X��
	�T�|�[�g���܂��B���̃C���^�[�t�F�[�X�ɂ��A CentDedDgrEki �I�u�W�F�N�g��
	�ǉ��E�ύX�E�폜���邱�Ƃ��ł��܂��B

	  �����Ȃ��� getMuPtr() ���\�b�h�ɂ��A Mu< const CentDedDgrEki* >
	�C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
	  ���̃C���^�[�t�F�[�X���g���ƁA�R���e�i���� CentDedDgrEki 
	�I�u�W�F�N�g�ɒ��ڃA�N�Z�X���邱�Ƃ��ł��܂����A
	CentDedEki �I�u�W�F�N�g�̑�����ύX���邱�Ƃ͂ł��܂���B
	�����̕ύX�́A set() ���\�b�h���g��Ȃ��Ă͂Ȃ�܂���B

  	�܂��A��ԕ���( ERessyahoukou )�̈������Ƃ� getMuPtr() 
  	���\�b�h�ɂ��A ��ԕ����ʂ�
  		Mu< CentDedDgrEkiCont::CdDedDgrEki >
  	�C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
  	���̕��@�ŁA�w�wOrder�x�ɑΉ�����w�̏����擾���邱�Ƃ��ł��܂��B
  	
   @attention
  	this �� get() ���\�b�h�́A CentDedDgrEki �I�u�W�F�N�g�̃R�s�[��Ԃ��܂��B
  	get() ���\�b�h�ŕԂ��ꂽ�I�u�W�F�N�g�ɑ΂��āA
  	CentDedEki �I�u�W�F�N�g���X�V���郁�\�b�h���Ăяo���Ă��A
  	�R���e�i���̉w�I�u�W�F�N�g���X�V���邱�Ƃ͂ł��܂���B
  	�R���e�i���̉w�I�u�W�F�N�g�̃��\�b�h���Ăяo���ꍇ�́A
  	getMuPtr() �� Mu<const CentDedDgrEki*>* ���擾���Ă���A
  	���̃C���^�[�t�F�[�X�o�R�� CentDedDgrEki* ���擾���A���̃|�C���^��
  	���\�b�h���Ăяo���Ă��������B
*/
class CentDedDgrEkiCont : public CMuiCopied< CentDedDgrEki >
{
public:
	typedef CMuiCopied< CentDedDgrEki >	super ;
	// ****************************************************************
	//	CentDedDgrEkiCont::CdDedDgrEki
	// ****************************************************************
	/**
	   @brief
	  	�w�̏���ێ�����A�P���f�[�^�N���X�ł��B
	  	CentDedDgrEkiCont::getMuPtr() ���\�b�h�ɂ��A 
	  	Mu< CentDedDgrEkiCont::CdDedDgrEki > �C���^�[�t�F�[�X���擾����ƁA
	  	�R���e�i���̉w�̑������A���̌`���Ŏ擾���邱�Ƃ��ł��܂��B
	  
	  	���̒P���f�[�^�N���X�Ŏ擾������́A��ԕ���{����,���}�ɍ��킹��
	  	�`���ɂȂ��Ă��܂��B
	  
	  	�ƂȂ�܂��B
	 */
	class CdDedDgrEki
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
		 	��v�w�Ȃ�^�ł��B
		 */
		bool  m_bIsSyuyoueki ;
	
		/**
			���̉w���玟�̉wOrder�܂ł�
		 	�ŏ����v�b���ł��B
	 
		 	�I�_�w�ł́A���̒l�� 0 �ł��B
	 
		 	�܂��A���̉w�Ԃł̉w�ԍŏ����v�b�����v�Z�s�\�i�f�[�^�Ȃ��j�̏ꍇ�́A
		 	 0 �ł��B
		 */
		int m_iEkikanSaisyouSec ;

		/**
			�_�C���O�����̊���̉w�ԕ��B

			��Ԑݒ�̂Ȃ��w�Ԃ́A�_�C���O�����r���[��ł�
			�c�����̕����w�_�C���O�����G���e�B�e�BY���W�x�P��(�b)�Ŏw�肵�܂��B
	
			����l�� 60 �ł��B
		*/
		int	m_iDgrYSizeEkikanDefault ;

		/**
			�_�C���O������ԏ��\��
	
			����l�� DiagramRessyajouhouHyouji_Origin �ł��B
		*/
		CentDedDgrEki::EDiagramRessyajouhouHyouji m_eDiagramRessyajouhouHyouji ;

		/**
			���̉w��Y���W�̍����B
			���ʂ́A0�ł��B
			�����̂��߂̗\�񂳂�Ă��܂��B
		*/
		int m_iDgrYSize ;

		/**
			�O�̉wOrder���炱�̉wOrder�܂ł�
		 	�w�_�C���O�����G���e�B�e�BY���W�x�ł̋����B
	 
		 	�I�_�w�ł́A���̒l�� 0 �ł��B
		*/
		int m_iDgrYSizeEkikan ;
		///@}
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	 public:
		CdDedDgrEki() : 
			m_bIsSyuyoueki( false ) , 
			m_iEkikanSaisyouSec( 0 ) ,
			m_iDgrYSizeEkikanDefault( 0 ) ,
			m_eDiagramRessyajouhouHyouji( CentDedDgrEki::DiagramRessyajouhouHyouji_Origin ) ,
			m_iDgrYSize( 0 ) ,
			m_iDgrYSizeEkikan( 0 ) 
		{} ;

		CdDedDgrEki(
			const std::string& strEkimei ,
			bool  bIsSyuyoueki ,
			int iEkikanSaisyouSec ,
			int	iDgrYSizeEkikanDefault ,
			CentDedDgrEki::EDiagramRessyajouhouHyouji eDiagramRessyajouhouHyouji ,
			int iDgrYSize ,
			int iDgrYSizeEkikan ) :
			m_strEkimei( strEkimei ) ,
			m_bIsSyuyoueki( bIsSyuyoueki ) ,
			m_iEkikanSaisyouSec( iEkikanSaisyouSec ) ,
			m_iDgrYSizeEkikanDefault( iDgrYSizeEkikanDefault ),
			m_eDiagramRessyajouhouHyouji( eDiagramRessyajouhouHyouji ) ,
			m_iDgrYSize( iDgrYSize ) ,
			m_iDgrYSizeEkikan( iDgrYSizeEkikan ) 
		{}



	// ********************************
	//	CentDedDgrEkiCont::CdDedDgrEki
	// ********************************
	 public:
		// ********************************
		///@name CentDedDgrEkiCont::CdDedDgrEki::����
		// ********************************
		///@{
		std::string	getEkimei()const{	return m_strEkimei ;};
		bool  getIsSyuyoueki()const{	return m_bIsSyuyoueki ;};
		int getEkikanSaisyouSec()const{	return m_iEkikanSaisyouSec ;};
		int	getDgrYSizeEkikanDefault()const{	return m_iDgrYSizeEkikanDefault ;};
		CentDedDgrEki::EDiagramRessyajouhouHyouji getDiagramRessyajouhouHyouji()const
		{	return m_eDiagramRessyajouhouHyouji ;};
		int getDgrYSize()const{	return m_iDgrYSize ;};
		int getDgrYSizeEkikan()const{	return m_iDgrYSizeEkikan ;};
		///@}
	};

private:
	// ----------------------------------------------------------------
	//	CentDedDgrEkiCont::ContKudari
	// ----------------------------------------------------------------
	/**
	   @brief
	  	����́w�wOrder�x ���C���f�N�X�Ƃ����A
	  		 Mu< CentDedDgrEkiCont::CdDedDgrEki > 
	  	���쐬���邽�߂̃A�_�v�^�ł��B
	 */
	class ContKudari : public Mu< CdDedDgrEki >
	{
	public:
		// ********************************
		//	Mu< CentDedDgrEkiCont::CdDedDgrEki >
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
		virtual CdDedDgrEki get(int iEkiOrder )const ;
	
		
	} m_xContKudari ;
	friend class ContKudari ;
	// ----------------------------------------------------------------
	//	CentDedDgrEkiCont::ContNobori
	// ----------------------------------------------------------------
	/**
	   @brief
	  	���́w�wOrder�x ���C���f�N�X�Ƃ����A	
	  		 Mu< CentDedDgrEkiCont::CdDedDgrEki > 
	  	���쐬���邽�߂̃A�_�v�^�ł��B
	 */
	class ContNobori : public Mu< CdDedDgrEki >
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
		virtual CdDedDgrEki get(int iEkiOrder )const ;
	
	} m_xContNobori ;
	friend class ContNobori ;
	
private:
	// ********************************
	///@name ���
	// ********************************
	///@{	
	///@}

// ********************************
//	�R���X�g���N�^
// ********************************
public:
	CentDedDgrEkiCont() ;
	CentDedDgrEkiCont( const CentDedDgrEkiCont& value ) ;
	CentDedDgrEkiCont& operator=( const CentDedDgrEkiCont& value ) ;
	virtual ~CentDedDgrEkiCont() ;

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
	Mu<CdDedDgrEki>* getMuPtr( ERessyahoukou eRessyahoukou )
	{
		if ( eRessyahoukou == Ressyahoukou_Nobori ){
			return &m_xContNobori ;	
		}
		return &m_xContKudari ;	
	};
	const Mu<CdDedDgrEki>* getMuPtr( ERessyahoukou eRessyahoukou )const
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
	int EkiOrderOfEkiIndex(  ERessyahoukou eRessyahoukou , int iEkiIndex )const ;
	///@}
};


} //namespace entDgr

#endif /*CentDedDgrEkiCont_h*/
