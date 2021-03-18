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
//	CentDedDia.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDia_h
#define  CentDedDia_h

#include <deque>

#include "CentDed.h"
#include "CentDedRessya.h"
#include "CentDedRessyaCont.h"

namespace entDed{

class CentDedEkiCont ;

// ****************************************************************
//	CentDedDia
// ****************************************************************
/**
@brief
 DiagramEdit �́A�H���Őݒ肳��Ă���w�_�C���x�P����\���܂��B

���̃N���X�̃C���X�^���X�́A�ʏ�́w�H���x ( CentDedRosen ) �ɕ��
����܂��B

���ۂɂ́A

- �w�H���x (CentDedRosen) ���w�_�C���x ( CentDedDia ) ��
�O�ȏ㕡�����
- �e�w�_�C���x ( CentDedDia ) ���w��ԁx (CentDedRessya ) ��
�O�ȏ㕡�����

�Ƃ����֌W�ɂȂ��Ă��܂��B

  ���̃N���X�́A�w��ԁx ( CentDedRessya ) ���A����E���̕ʂ�
�ێ����܂��B

�@���̃N���X�́A�����Ƃ��āw�w�̐��x�E�w��Ԏ�ʐ��x��ێ����܂��B
�������A�����͔h�������ƂȂ��Ă��܂��B

<h5>int EkiCount</h5>
���̃_�C���ɑ��݂���w�w�̐��x�ł��B
���̑����́A m_CentDedRessyaCont[]->m_iEkiCount �����ƂɌ��܂�܂��B

<h5>int RessyasyubetsuCount</h5>
�w��Ԏ�ʐ��x�B��Ԏ�ʂ̎�ނ̐��ł��B
���̑����́A m_CentDedRessyaCont[]->m_iRessyasyubetsuCount �����Ƃ�
���܂�܂��B

����
 -------------------------------- 

����̃G���[�����E�C��
 -------------------------------- 


���㏑��(operator=): ���̃I�u�W�F�N�g���e�I�u�W�F�N�g CentDedDiaCont �̎q�ł���ꍇ�ŁA������̃_�C�������󕶎���ł���ꍇ�A�������͓������O�̃_�C���� CentDedDiaCont �ɂ���ꍇ�͗�O�X���[�B
�@(��������ACentDedDiaCont::set()�ɓn���ƃG���[�ɂȂ�悤�ȃI�u�W�F�N�g�ł���ꍇ�́A����͗�O�X���[�Ƃ��܂�)

��setName:���̃I�u�W�F�N�g���e�I�u�W�F�N�g CentDedDiaCont �̎q�ł���ꍇ�ŁA������̃_�C�������󕶎���ł���ꍇ�A�������͓������O�̃_�C���� CentDedDiaCont �ɂ���ꍇ�͗�O�X���[�Ƃ��܂��B
�@(�����ύX��̃I�u�W�F�N�g���ACentDedDiaCont::set()�ɓn���ƃG���[�ɂȂ�悤�ȃI�u�W�F�N�g�ł���ꍇ�́A�G���[�Ƃ��܂�)

��setParent:adjust�����s����

 ����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 

����ԃR���e�i(CentDedRessyaCont)��adjust()���Ϗ����܂��B


*/
class CentDedDia : public CChildBase
{
	typedef CChildBase	super ;
public:
	// ****************************************************************
	//	�C���i�[�^�C�v
	// ****************************************************************
	/**
	�@CentDedDia �ɕ�܂���Ă���w��ԁx�R���e�i�ł��B
	*/
	class CXRessyaCont : public CentDedRessyaCont
	{
		typedef CentDedRessyaCont super ;
	 public:
		// ********************************
		///@name �֘A
		// ********************************
		///@{
		/**
			�e�I�u�W�F�N�g�ւ̃|�C���^�ł��B�R���X�g���N�^�Ō��܂�܂��B
		*/
		CentDedDia* m_pDia ;
	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************
		CXRessyaCont( 
			CentDedDia* pCentDedDia , 
			ERessyahoukou m_eRessyahoukou ) 
			: 
			super( 0 ,
				m_eRessyahoukou ) ,
		  	m_pDia( pCentDedDia )
		{}
		CXRessyaCont( 
			CentDedDia* pCentDedDia , 
			int iEkiCount ,
			ERessyahoukou m_eRessyahoukou ) 
			: 
			super( iEkiCount ,
				m_eRessyahoukou ) ,
		  	m_pDia( pCentDedDia )
		{}


		CXRessyaCont( 
			CentDedDia* pCentDedDia , 
			const CentDedRessyaCont& value )
			: 
			super( value ) ,
		  	m_pDia( pCentDedDia )
		{}

	 public:
		// ********************************
		///@name CentDedRessyaCont-�֘A
		// ********************************
		///@{
		/**
		@return
			���̃R���e�i�� CentDedDia �ɕ�܂���Ă���ꍇ�́A
			CentDedDia �̃A�h���X�B
			�����łȂ��Ȃ�NULL�B
		*/
		virtual CentDedDia* getDia(){ return m_pDia ;}
		/**
		@return
			���̃R���e�i�� CentDedRessya �ɕ�܂���Ă���ꍇ�́A
			CentDedRessya �̃A�h���X�B
			�����łȂ��Ȃ�NULL�B
		*/
		virtual const CentDedDia* getDia()const{ return m_pDia ;}
	};
	/**
		������Z�q��Aset...() �ŃX���[������O�ł��B
	*/
	class LException
	{
	};


	// ****************************************************************
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	  	�_�C���̖��̂ł��B
	  
	  	�i��j "�����_�C��" �Ȃ�
	  
	   @see CentDedRosen
	  	 CentDedRosen �́A���̑���������q�Ƃ��Ĉ����܂��B
	  	CentDedRosen �ɕ�܂���� CentDedDia �ł́A
	  	���̑����͈�ӂłȂ��Ă͂Ȃ�܂���B
	 */
	std::string	m_strName ;
	///@}
private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		���́w�_�C���x���ŉ^�s����Ă����Ԃ�
		�w��ԁx ( CentDedRessya ) ��ێ����܂��B
	
		���̕ϐ��́A�v�f�� 2 �̔z��ł��B

		- [0] ��	���� ( Ressyahoukou_Kudari ) ���	
		- [1] ��	��� ( Ressyahoukou_Nobori ) ���	
	
		���̃R���e�i���� CentDedRessya �I�u�W�F�N�g��
		�����E�j���̐Ӗ���this�ɂ���܂��B
	
		������Ԃł́A�v�f���� 0 �ƂȂ�܂��B
	*/
	CXRessyaCont*	m_CentDedRessyaCont[2] ;
	
	///@}


public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	   @param strName [in]
	  	�_�C���̖��̂ł��B	\n
	  	�i��j "�����_�C��" �Ȃ�
	*/
	CentDedDia( const string& strName = "" ) ;

	/**
	  	���̃R���X�g���N�^�́A 
	  	CentDedDia_From_CdConnectedString() ��
	  	�t�@�C���̓��e���擾����Ƃ��ɁA
	  	�ǂݎ���Ƃ��Ďw�肷��I�u�W�F�N�g�̐����Ɏg���܂��B
	   @param iEkiCount [in]
	  	�_�C���Ɋ܂܂��w�̐��B
	 */
	CentDedDia( int iEkiCount ) ;

	/**
	   @param strName [in]
	  	�_�C���̖��̂ł��B	\n
	  	�i��j "�����_�C��" �Ȃ�
	   @param iEkiCount [in]]
	  	�_�C���Ɋ܂܂��w�̐��B
	 */
	CentDedDia( 
		const std::string& strName  ,
		int iEkiCount ) ;


	CentDedDia( const CentDedDia& value );
	
	/**
	  	���̃N���X�ւ̑�����s���܂����A
	  	this �́w�w�x�̐� ( m_iEkiCount ) �͕ύX���܂���B
	  
		���㏑��(operator=): ���̃I�u�W�F�N�g���e�I�u�W�F�N�g CentDedDiaCont 
		�̎q�ł���ꍇ�ŁA������̃_�C�������󕶎���ł���ꍇ�A
		�������͓������O�̃_�C���� CentDedDiaCont �ɂ���ꍇ�͗�O�X���[�B
		�@(��������ACentDedDiaCont::set()�ɓn���ƃG���[�ɂȂ�悤��
		�@�I�u�W�F�N�g�ł���ꍇ�́A����͗�O�X���[�Ƃ��܂�)

	 */
	CentDedDia& operator=( const CentDedDia& value );

	virtual ~CentDedDia();

public:
	// ********************************
	///@name CChildBase-����
	// ********************************
	///@{
	/**
	�@��setParent:adjust�����s����
	*/
	virtual void setParent( CParentBase* pParent );
	///@}
public:
	// ********************************
	///@name CentDedDia-����
	// ********************************
	///@{
	std::string	getName()const{	return m_strName ;};
	
	/**
	��setName:���̃I�u�W�F�N�g���e�I�u�W�F�N�g CentDedDiaCont �̎q�ł���
	�ꍇ�ŁA������̃_�C�������󕶎���ł���ꍇ�A�������͓������O�̃_�C����
	 CentDedDiaCont �ɂ���ꍇ�͗�O�X���[�Ƃ��܂��B
	�@(�����ύX��̃I�u�W�F�N�g���ACentDedDiaCont::set()�ɓn���ƃG���[��
	�@�Ȃ�悤�ȃI�u�W�F�N�g�ł���ꍇ�́A�G���[�Ƃ��܂�)
	*/
	void setName( const std::string& value );

	int getEkiCount()const
	{
		return m_CentDedRessyaCont[ Ressyahoukou_Kudari ]->
			getEkiCount() ;
	};
	///@}
	// ********************************
	///@name CentDedDia-���
	// ********************************
	///@{
	/**
	   @param eRessyahoukou [in]
	  	��ԕ������w�肵�Ă��������B
	  	-	���� :	Ressyahoukou_Kudari 
	  	-	��� : 	Ressyahoukou_Nobori 
	 */
	CentDedRessyaCont* getCentDedRessyaCont( 
			ERessyahoukou eRessyahoukou )
	{
		return m_CentDedRessyaCont[ eRessyahoukou ] ;
	};
	/**
	   @param eRessyahoukou [in]
	  	��ԕ������w�肵�Ă��������B
	  	-	���� :	Ressyahoukou_Kudari 
	  	-	��� : 	Ressyahoukou_Nobori 
	 */
	const CentDedRessyaCont* getCentDedRessyaCont( 
			ERessyahoukou eRessyahoukou )const
	{
		return m_CentDedRessyaCont[ eRessyahoukou ] ;
	};
	///@}
	// ********************************
	///@name CentDedDia-����
	// ********************************
	///@{

	/**
		�w��̉w Order �̉w�������A
		�w�����`���E�n���E�I���ɍ��킹�ĕύX���܂��B

		�ύX���e�́A CentDedEkiJikoku::adjustByEkijikokukeisiki 
		�̐������Q�Ƃ��Ă��������B

	@see CentDedEkiJikoku::adjustByEkijikokukeisiki 

	@param pCentDedEkiCont [in]
		�w�R���e�i���w�肵�Ă��������B
	@param iEkiIndex [in]
		�wIndex���w�肵�Ă��������B
		INT_MAX �́A�������w�肵�����ƂɂȂ�܂��B
	*/
	void adjustByEkijikokukeisiki(
		const CentDedEkiCont* pCentDedEkiCont ,
		int iEkiIndex );
	///@}

	/**
		this �̑���������ɔ����Ă���ꍇ�A����ɍ����悤�ɁA������
		�C�����܂��B

		����ԃR���e�i(CentDedRessyaCont)��adjust()���Ϗ����܂��B

	*/
	void adjust() ;

public:
	// ********************************
	///@name CentDedDia-�w���E��Ԏ�ʐ��̕ύX
	// ********************************
	///@{

	/**
	  	���̃R���e�i�ɁA�w�肳�ꂽ�w��Ԏ�ʁx�̗�Ԃ����邩�ۂ��𒲂ׂ܂��B
	   @param iRessyasyubetsuIndex [in]
	  	�w��Ԏ��Index�x���w�肵�Ă��������B
	  	�͈͂́A 0 �ȏ� ��Ԏ�ʂ̐������ł��B
	  	INT_MAX �́A�����̗�Ԏ�ʂ��w�肵�����̂Ƃ݂Ȃ��܂��B
	   @param peRessyahoukou [out]
	  	���̊֐��͂��̕ϐ��ɁA�w��Ԏ�ʁx�̗�Ԃ���������
	  	�_�C���̗�ԕ������������݂܂��B
	  	�s�v�Ȃ� NULL �ł����܂��܂���B
	   @param piRessyaIndex [out]
	  	���̊֐��͂��̕ϐ��ɁA�w��Ԏ�ʁx�̗�Ԃ���������
	  	���Index ���������݂܂��B
	  	�s�v�Ȃ� NULL �ł����܂��܂���B
	   @return 
	  	-	1; //	�w��̗�Ԏ�ʂ̗�Ԃ����݂��܂��B
	  	-	0; //	�w��̗�Ԏ�ʂ̗�Ԃ͑��݂��܂���B
	  	-	-1 ;	//	�C���f�N�X���s��
	 */
	int isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) const ;

	///@}
public:
	// ********************************
	///@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
	///@{
	/**
		m_CentDedEkiCont �� CentDedEki ���ǉ����ꂽ����A
		m_CentDedEkiCont ����Ăяo����܂��B
	@param iEkiIndex
		�ǉ����ꂽ CentDedEki �̃C���f�N�X�B
	*/
	virtual void onEkiInsert( int iEkiIndex );

	/**
		m_CentDedEkiCont ���� CentDedEki ���폜���ꂽ����A
		m_CentDedEkiCont ����Ăяo����܂��B
	@param iEkiIndex
		�폜���ꂽ CentDedEki �̃C���f�N�X�B
	*/
	virtual void onEkiErase( int iEkiIndex  );

	/**
		CentDedEkiTrackCont �� CentDedEkiTrack ���ǉ����ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiIndex
		CentDedEkiTrackCont ���ǉ����ꂽ CentDedEki �̉wIndex�B
	@param iEkiTrackIndex
		�ǉ����ꂽ CentDedEkiTrack �̃C���f�N�X�B
	*/
	virtual void onEkiTrackInsert( int iEkiIndex , int iEkiTrackIndex );

	/**
		CentDedEkiTrackCont ���� CentDedEkiTrack ���폜���ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiIndex
		CentDedEkiTrackCont ���폜���ꂽ CentDedEki �̉wIndex�B
	@param iEkiTrackIndex
		�폜���ꂽ CentDedEkiTrack �̐擪�̃C���f�N�X�B
	*/
	virtual void onEkiTrackErase( int iEkiIndex , int iEkiTrackIndex );

	/**
		CentDedRessyasyubetsuCont �� CentDedRessyasyubetsu ���ǉ����ꂽ����A
		CentDedRessyasyubetsuCont ����Ăяo����܂��B
	@param iRessyasyubetsuIndex
		�ǉ����ꂽ CentDedRessyasyubetsu  �̃C���f�N�X�B
	*/
	virtual void onRessyasyubetsuInsert( int iRessyasyubetsuIndex );

	/**
		CentDedRessyasyubetsuCont ���� CentDedRessyasyubetsu ���폜���ꂽ����A
		CentDedRessyasyubetsuCont ����Ăяo����܂��B
	@param iRessyasyubetsuIndex
		�폜���ꂽ CentDedRessyasyubetsu  �̃C���f�N�X�B
	*/
	virtual void onRessyasyubetsuErase( int iRessyasyubetsuIndex );



	///@}
};

} //namespace entDed

#endif /*CentDedDia_h*/


