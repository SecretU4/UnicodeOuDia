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
//	CentDedRosen.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRosen_h
#define  CentDedRosen_h

#include <deque>

#include "CentDed.h"
#include "CentDedEkiCont.h"
#include "CentDedRessyasyubetsuCont.h"
#include "CentDedDiaCont.h"
#include "NsMu/CaMup_vector.h"

namespace entDed{

// ****************************************************************
//	CentDedRosen
// ****************************************************************
/**
@brief
  DiagramEdit �́A�w�H���x�P��\���܂��B
  ���̃N���X�́A DiagramEdit �̃G���e�B�e�B�N���X CentDed... ��
���[�g�ƂȂ�N���X�ł��B�ȉ��̃N���X�̃I�u�W�F�N�g���܂��܂��B
	
	- �w�w�x ( CentDedEki ) �F 0 �ȏ㕡���̃I�u�W�F�N�g���܂��܂��B
	- �w��Ԏ�ʁx ( CentDedRessyasyubetsu ) �F 1 �ȏ㕡���̃I�u�W�F�N�g��
	��܂��܂��B
	- �w�_�C���x ( CentDedDia ) �F 0 �ȏ㕡���̃I�u�W�F�N�g���܂��܂��B
	�w�_�C���x ( CentDedDia ) �́A�w��ԁx ( CentDedRessya ) ���O�ȏ㕡��
	��܂��Ă��܂��B����ɁA�w��ԁx�́A�w�w�����x ( CentDedEkiJikoku ) ��
	�w�w�x�̐�������܂��Ă��܂��B

  this �ɕ�܂���� CentDedDia �́A CentDedDia::m_strName ����ӂłȂ��Ă�
�Ȃ�܂���B������ CentDedDia �� insertCentDedDia() �œo�^���悤�Ƃ���ƁA
�G���[�ƂȂ�܂��B

  �w�w�x�I�u�W�F�N�g��ǉ��E�폜�����ꍇ�Athis �͕�܂��Ă���
���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
�w�w�����x ( CentDedEkiJikoku )�I�u�W�F�N�g�̒ǉ��E�폜���s���܂��B

  �w��Ԏ�ʁx�I�u�W�F�N�g���폜�����ꍇ�A this �͕�܂��Ă��邷�ׂĂ�
�w��ԁx�I�u�W�F�N�g�̂����A�폜���ꂽ�w��Ԏ��Index�x�����w��ԁx
�ɑ΂��āA�w��Ԏ��Index�x��0(����̗�Ԏ��)�ɕύX���܂��B

  �w�wIndex�x�́A�H���̉����Ԃ̎n���w�i����Ԃ̏I���w�j�� 0 �E 
�����Ԃ̏I���w�i����Ԃ̎n���w�j �� ( �w�̐� - 1 ) �ƂȂ�܂��B

����
 -------------------------------- 

���@�_�C���̋N�_����(m_jikokuKitenJikoku) �́ANULL���w�肷�邱�Ƃ͂ł��܂���B


����̃G���[�����E�C��
 -------------------------------- 


����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 



*/
class CentDedRosen
{

protected:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedEkiCont
	// ----------------------------------------------------------------
	/**
	@brief
	  �w�H���x�I�u�W�F�N�g�ɕ�܂����A
		�w�w�x(CentDedEki) �I�u�W�F�N�g�̃R���e�i�ł��B
	
	  �w�w�x�I�u�W�F�N�g��ǉ��E�폜�����ꍇ�A
		this �͊֘A����w�H���x����܂��Ă���
		���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
		�w�w�����x ( CentDedEkiJikoku )�I�u�W�F�N�g�̒ǉ��E�폜���s���܂��B
		
	 */
	class CXCentDedEkiCont : public CentDedEkiCont
	{
	public:
		// ********************************
		//	�C���i�[�^�C�v
		// ********************************
		typedef CentDedEkiCont	super ;
	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************


	public:
		// ********************************
		///@name	Mui
		// ********************************
		///@{
		/**
		 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
		 	�v�f��ǉ����܂��B
		 @param element [in]
		 	�v�f���w�肵�Ă��������B
		 @param iIndex [in]
		 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 	�͈͂͂O�ȏ� size() �ȉ��ł��B
		 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
			�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 @return
		 	0�ȏ�͐����A���̐��̓G���[�ł�
		
			<H4>
			�y�I�[�o���C�h�z
			</H4>
			CentDedEki �I�u�W�F�N�g��ǉ�����̂ɉ����āA
			m_pCentDedRosen ����܂��Ă���S�Ă̗�Ԃɑ΂��āA
			�w�����̒ǉ����s���܂��B
		 */
		virtual int insert( const CentDedEki& element , int iIndex = INT_MAX );
		/**
		 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
		 	�v�f���폜���܂��B
		 @param iIndex [in]
		 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 	�͈͂͂O�ȏ� size() �����ł��B
		 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 @param iSize [in]
		 	�폜����v�f�̐����w�肵�Ă��������B
		 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
		 @attention
			iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
		 @return
		 	0�ȏ�͐����A���̐��̓G���[�ł�
		
			<H4>
			�y�I�[�o���C�h�z
			</H4>
			CentDedEki �I�u�W�F�N�g���폜����̂ɉ����āA
			m_pCentDedRosen ����܂��Ă���S�Ă̗�Ԃɑ΂��āA
			�w�����̍폜���s���܂��B
		 */
		virtual int erase( int iIndex  , int iSize = 1 ) ;
		///@}
		// ********************************
		///@name CentDedEkiCont-�֘A
		// ********************************
		///@{
		/**
		@return
			�O���� CentDedRosen �I�u�W�F�N�g��Ԃ��܂��B
		*/
		CentDedRosen* getRosen();
		/**
		@return
			�O���� CentDedRosen �I�u�W�F�N�g��Ԃ��܂��B
		*/
		const CentDedRosen* getRosen()const ;
		///@}
	} ;
	friend class CXCentDedEkiCont ;

	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedRessyasyubetsuCont
	// ----------------------------------------------------------------
	/**
	@brief
	  �w�H���x�I�u�W�F�N�g�ɕ�܂����A
		�w��Ԏ�ʁx(CentDedRessyasyubetsu) �I�u�W�F�N�g�̃R���e�i�ł��B
		
		�ʏ�̗�Ԏ�ʃR���e�i�ɉ����āA�ȉ��̂悤�ȓ��������݂��܂��B
		
		
	�P�D  �w��Ԏ�ʁx�I�u�W�F�N�g��ǉ��E�폜�����ꍇ�A
		this �͊֘A����w�H���x����܂��Ă���
		���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
		�w��Ԏ��Index�x ( CentDedRessya::m_iRessyasyubetsuIndex )
		�̏C�����s���܂��B
	
	�Q�D  �w��Ԏ�ʁx�I�u�W�F�N�g���폜�����ꍇ�A���̗�Ԏ�ʂ������
	�̗�Ԏ�ʃC���f�N�X�́A0�ɕύX����B
	 */
	class CXCentDedRessyasyubetsuCont : public CentDedRessyasyubetsuCont
	{
	public:
		// ********************************
		//	�C���i�[�^�C�v
		// ********************************
		typedef CentDedRessyasyubetsuCont	super ;
	public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************
		CXCentDedRessyasyubetsuCont() ;
	public:
		// ********************************
		///@name	Mui
		// ********************************
		///@{
		/*kyuusi
		 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
		 	�v�f��ǉ����܂��B
		 @param element [in]
		 	�v�f���w�肵�Ă��������B
		 @param iIndex [in]
		 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 	�͈͂͂O�ȏ� size() �ȉ��ł��B
		 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
			�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 @return
		 	0�ȏ�͐����A���̐��̓G���[�ł�
			-	-1 ;	//	iIndex ���s���ł��B
			-	-11 ;	//	name����� CentDedRessyasyubetsu���㏑������ƃG���[�B		
			<H4>
			�y�I�[�o���C�h�z
			</H4>
			CentDedRessyasyubetsu �I�u�W�F�N�g��ǉ�����̂ɉ����āA
			���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
			�w��Ԏ��Index�x ( CentDedRessya::m_iRessyasyubetsuIndex )
			�̏C�����s���܂��B
		virtual int insert( const CentDedRessyasyubetsu& element , int iIndex = INT_MAX );
		 */
		/*kyuusi
		 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
		 	�v�f���폜���܂��B
		 @param iIndex [in]
		 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 	�͈͂͂O�ȏ� size() �����ł��B
		 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 @param iSize [in]
		 	�폜����v�f�̐����w�肵�Ă��������B
		 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
		 @attention
			iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
		 @return
		 	0�ȏ�͐����A���̐��̓G���[�ł�
			-	-1 ;	//	iIndex ���s���ł��B
			-	-11 ;	//	�폜�Ώۂ̗�Ԏ�ʂ̗�Ԃ����݂��܂��B
		
			<H4>
			�y�I�[�o���C�h�z
			</H4>
			CentDedRessyasyubetsu �I�u�W�F�N�g���폜����̂ɉ����āA
			���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
			�w��Ԏ��Index�x ( CentDedRessya::m_iRessyasyubetsuIndex )
			�̏C�����s���܂��B
		virtual int erase( int iIndex  , int iSize = 1 ) ;
		 */
		///@}

		// ********************************
		///@name CentDedRessyasyubetsuCont-�֘A
		// ********************************
		///@{
		/**
		@return
			�O���� CentDedRosen �I�u�W�F�N�g��Ԃ��܂��B
		*/
		virtual CentDedRosen* getRosen();
		/**
		@return
			�O���� CentDedRosen �I�u�W�F�N�g��Ԃ��܂��B
		*/
		virtual const CentDedRosen* getRosen()const ;
		///@}
	};
	friend class CXCentDedRessyasyubetsuCont ;

	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedDiaCont
	// ----------------------------------------------------------------
	/**
	@brief
	  �w�H���x�I�u�W�F�N�g�ɕ�܂����A
		�w�_�C���x(CentDedDia) �I�u�W�F�N�g�̃R���e�i�ł��B
		
	 */
	class CXCentDedDiaCont : public CentDedDiaCont
	{
		typedef CentDedDiaCont super ;
	 public:
		// ********************************
		//	�R���X�g���N�^
		// ********************************

	 public:
		// ********************************
		///@name CentDedDiaCont-�֘A
		// ********************************
		///@{
		/**
		@return
			���̃R���e�i�� CentDedRosen �ɕ�܂���Ă���ꍇ�́A
			CentDedRosen �̃A�h���X�B
			�����łȂ��Ȃ�NULL�B
		*/
		virtual CentDedRosen* getRosen();
		/**
		@return
			���̃R���e�i�� CentDedRosen �ɕ�܂���Ă���ꍇ�́A
			CentDedRosen �̃A�h���X�B
			�����łȂ��Ȃ�NULL�B
		*/
		virtual const CentDedRosen* getRosen()const ;
		
		///@}
	};
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�H���̖��̂ł��B
		�i��j "�ߓS����" �Ȃ�
	 */
	std::string	m_strName ;
	
	/**
		�_�C���̋N�_�����ł��B
		���̎����́A�_�C���O�����̍��[�̎����ƂȂ�܂��B
	
		����l�� 00:00:00 �ł��B
	 @attention
		���̒l�́A Null ��Ԃɂ��Ȃ��ł��������B
	 */
	CdDedJikoku	m_jikokuKitenJikoku ;
	
	/**
		�_�C���O�����̊���̉w�ԕ��B

		��Ԑݒ�̂Ȃ��w�Ԃ́A�_�C���O�����r���[��ł�
		�c�����̕����w�_�C���O�����G���e�B�e�BY���W�x�P��(�b)�Ŏw�肵�܂��B
	
		����l�� 60 �ł��B
	*/
	int	m_iDiagramDgrYZahyouKyoriDefault ;
	
	/**
		�R�����g�B
		CDedCommentDoc,CDedCommentView �ŕҏW���܂��B
	 */
	std::string	m_strComment ;
	
	///@}
private:
	// ********************************
	///@name ���
	// ********************************
	///@{

	/**
		���́w�H���x�ɂ���w�w�x ( CentDedEki ) ��ێ����܂��B
	
		���̃R���e�i���� CentDedEki �I�u�W�F�N�g��
		�����E�j���̐Ӗ���this�ɂ���܂��B
	
		������Ԃł́A�v�f���� 0 �ƂȂ�܂��B
	 */
	CXCentDedEkiCont	m_CentDedEkiCont ;
	
	/**
		���́w�H���x�ɂ���w��Ԏ�ʁx ( CentDedRessyasyubetsu ) ��ێ����܂��B
	
		���̃R���e�i���� CentDedRessyasyubetsu �I�u�W�F�N�g��
		�����E�j���̐Ӗ���this�ɂ���܂��B
	
		������Ԃł́A�v�f���� 1 �ƂȂ�܂��B
		�w��Ԏ�ʁx�́A���Ȃ��Ƃ���͑��݂��Ȃ��Ă͂Ȃ�܂���B
	 */
	CXCentDedRessyasyubetsuCont	m_CentDedRessyasyubetsuCont ;
	
	/**
		���́w�H���x�ɂ���w�_�C���x ( CentDedDia ) ��ێ����܂��B
	
		���̃R���e�i���� CentDedDia �I�u�W�F�N�g��
		�����E�j���̐Ӗ���this�ɂ���܂��B
	
	 @attention
		this �́A CentDedDia::m_strName ������q�Ƃ��Ĉ����܂��B
		���̃R���e�i���� CentDedDia �́A CentDedDia::m_strName ��
		��ӂłȂ��Ă͂Ȃ�܂���B
	
		������Ԃł́A�v�f���� 0 �ƂȂ�܂��B
	 */
	CXCentDedDiaCont	m_CentDedDiaCont ;
	///@}
	
 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		������Ԃł́A��Ԏ�ʂ̗v�f���� 1 �ƂȂ�܂��B
		�w��Ԏ�ʁx�́A���Ȃ��Ƃ���͑��݂��Ȃ��Ă͂Ȃ�܂���B
	 */
	CentDedRosen() ;
	
	CentDedRosen( const CentDedRosen& value );
	CentDedRosen& operator=( const CentDedRosen& value );


	
// ********************************
//	CentDedRosen
// ********************************
 public:
	// ********************************
	///@name CentDedRosen-����
	// ********************************
	///@{
	/** @see m_strName */
	std::string	getName()const{	return m_strName ;};
	/** @see m_strName */
	CentDedRosen& setName( const std::string& value )
	{	m_strName =value ; return *this ; } ;
	/** @see m_jikokuKitenJikoku */
	CdDedJikoku	getKitenJikoku()const{	return m_jikokuKitenJikoku ;};
	/** @see m_jikokuKitenJikoku */
	CentDedRosen& setKitenJikoku( const CdDedJikoku& value )
	{	m_jikokuKitenJikoku = value ; return *this ; } ;
	/** @see m_iDiagramDgrYZahyouKyoriDefault */
	int	getDiagramDgrYZahyouKyoriDefault()const
	{	return m_iDiagramDgrYZahyouKyoriDefault ;};
	/** @see m_iDiagramDgrYZahyouKyoriDefault */
	CentDedRosen& setDiagramDgrYZahyouKyoriDefault( int value )
	{	m_iDiagramDgrYZahyouKyoriDefault = value ; return *this ;};
	/** @see m_strComment */
	std::string	getComment()const{return m_strComment ;};
	/** @see m_strComment */
	CentDedRosen& setComment( const std::string& value )
	{	m_strComment = value ;	return *this ; 	} ;
	///@}
	
	// ********************************
	///@name CentDedRosen-���
	// ********************************
	///@{
	/**
	 @return 
		�w�w�x ( CentDedEki ) �I�u�W�F�N�g�̃R���e�i�ւ�
		�C���^�[�t�F�[�X��Ԃ��܂��B
		���̃C���^�[�t�F�[�X�́A CentDedEki �I�u�W�F�N�g��H����
		�ǉ��E�폜���邽�߂̃C���^�[�t�F�[�X�ł��B
	@attention
		���̃R���e�i�ɑ΂��āA������Z�q���g�p���Ă͂����܂���B
		�K���A�R���e�i�̃��\�b�h���g���ėv�f�̒ǉ��E�폜���s���Ă��������B
		���� CentDedEkiCont �̓��e��CentDedRosen �ɃR�s�[����ꍇ�́A
		CaMui::insert() ���g�p���邱�Ƃ��ł��܂��B
	@code
		CaMui<CentDedEki>	aCaCont( aCentDedRosen().getCentDedEkiCont() ) ; 
		aCaCont.insert( &aCentDedEkiCont ) ;
	@endcode
	*/
	CentDedEkiCont* getCentDedEkiCont(){	return &m_CentDedEkiCont ; } ;
	/** @see m_CentDedEkiCont */
	const CentDedEkiCont* getCentDedEkiCont()const{	return &m_CentDedEkiCont ; } ;

	/**
	@return 
		�w��Ԏ�ʁx ( CentDedRessyasyubetsu ) �I�u�W�F�N�g�̃R���e�i�ւ�
		�C���^�[�t�F�[�X��Ԃ��܂��B
		���̃C���^�[�t�F�[�X�́A CentDedRessyasyubetsu �I�u�W�F�N�g��H����
		�ǉ��E�폜���邽�߂̃C���^�[�t�F�[�X�ł��B
	@attention
		���̃R���e�i�ɑ΂��āA������Z�q���g�p���Ă͂����܂���B
		�K���A�R���e�i�̃��\�b�h���g���ėv�f�̒ǉ��E�폜���s���Ă��������B
		���� CentDedRessyasyubetsuCont �̓��e��CentDedRosen �ɃR�s�[����ꍇ�́A
		CaMui::insert() ���g�p���邱�Ƃ��ł��܂��B
	@code
			CaMui<CentDedRessyasyubetsu>	aCaCont( pCentDedRosen->getCentDedRessyasyubetsuCont() ) ; 
			aCaCont.insert( &aCentDedRessyasyubetsuCont ) ;
	@endcode
	 */
	CentDedRessyasyubetsuCont* getCentDedRessyasyubetsuCont()
	{
		return &m_CentDedRessyasyubetsuCont ; 
	} ;
	/** @see m_CentDedRessyasyubetsuCont */
	const CentDedRessyasyubetsuCont* getCentDedRessyasyubetsuCont()const
	{
		return &m_CentDedRessyasyubetsuCont ; 
	} ;
	
	/**
	 @return 
		�w�_�C���x ( CentDedDia ) �I�u�W�F�N�g�̃R���e�i�ւ�
		�C���^�[�t�F�[�X��Ԃ��܂��B
		���̃C���^�[�t�F�[�X�́A CentDedDia �I�u�W�F�N�g��H����
		�ǉ��E�폜���邽�߂̃C���^�[�t�F�[�X�ł��B
	@attention
		���̃R���e�i�ɑ΂��āA������Z�q���g�p���Ă͂����܂���B
		�K���A�R���e�i�̃��\�b�h���g���ėv�f�̒ǉ��E�폜���s���Ă��������B
		���� CentDedRessyasyubetsuCont �̓��e��CentDedRosen �ɃR�s�[����ꍇ�́A
		CaMui::insert() ���g�p���邱�Ƃ��ł��܂��B
	@code
			CaMui<CentDedDia>	aCaCont( pCentDedRosen->getCentDedDiaCont() ) ; 
			aCaCont.insert( &aCentDedDia ) ;
	@endcode
	 */
	CentDedDiaCont* getCentDedDiaCont(){	return &m_CentDedDiaCont ;};
	/** @see m_CentDedDiaCont */
	const CentDedDiaCont* getCentDedDiaCont()const{	return &m_CentDedDiaCont ;};

	///@}
	
	// ********************************
	///@name CentDedRosen-����
	// ********************************
	///@{
	/**
		���̘H���t�@�C���ɁA���̘H���t�@�C����g����܂��B
	@param rosenToAdd [in]
		�ǉ�����H�����w�肵�Ă��������B
	@param iEkiIndexToInsert [in]
		�H���t�@�C����g�����wIndex���w�肵�Ă��������B

	(1)�@OuDia�́A�w�ǉ�����H���t�@�C���x�̂��ׂẲw���A
	�w���ݕҏW���Ă���H���t�@�C���x�́w�g�����x�ɒǉ����܂��B

	(1.1)�@�w���ݕҏW���Ă���H���t�@�C���x�̑g�����w��
	�w�ǉ�����H���t�@�C���x�̋N�_�E�w�������ł���ꍇ�A
	OuDia�͂���2�w�𓯈�w�Ƃ݂Ȃ��܂��B
	  �w�ǉ�����H���t�@�C���x�̏I�_�ɂ��Ă��A���l�ł��B

	(2)�@OuDia�́A�w�ǉ�����H���t�@�C���x�̂��ׂĂ̗�Ԏ�ʂ�
	�w���ݕҏW���Ă���H���t�@�C���x�ɒǉ����܂��B
	  �A���A�����̗�Ԏ�ʂ��w���ݕҏW���Ă���H���t�@�C���x��
	  ���łɑ��݂��Ă���ꍇ�́AOuDia�͂��̗�Ԏ�ʂ�ǉ����܂���B

	(3)�@OuDia�́A�w�ǉ�����H���t�@�C���x�̂��ׂẴ_�C����
	�w���ݕҏW���Ă���H���t�@�C���x�ɒǉ����܂��B
	  �A���A�����̃_�C�����w���ݕҏW���Ă���H���t�@�C���x��
	  ���łɑ��݂��Ă���ꍇ�́AOuDia�͂��̃_�C����ǉ����܂���B

	(4)�@OuDia�́A�w�ǉ�����H���t�@�C���x�̂��ׂĂ�
	�_�C���̂��ׂĂ̗�Ԃ��A�w���ݕҏW���Ă���H���t�@�C���x�́A
	�����̃_�C���ɒǉ����܂��B

	(5)�@OuDia�́A�w�ǉ�����H���t�@�C���x�̃R�����g���A
	�w���ݕҏW���Ă���H���t�@�C���x�̃R�����g�̖����ɒǉ����܂��B
	*/
	void insert( const CentDedRosen& rosenToAdd , int iEkiIndexToInsert ) ;

	/**
		���̘H���̈ꕔ�w�Ԃ̘H�����쐬���܂��B
	@param iEkiIndex [in]
		�쐬����H���̋N�_�w�Ƃ���wIndex���w�肵�Ă��������B
	@param iEkiCount [in]
		�쐬����H���̉w�����w�肵�Ă��������B
	@return
		�������ꂽ�H����Ԃ��܂��B

	(1)�@�V�������������H���t�@�C���́A
	�w���ݕҏW���Ă���H���t�@�C���x����A
	�w�肳�ꂽ�͈͈ȊO�̉w���폜�������̂ɂȂ�܂��B

	(2)�@�V�������������H�����^�]��ԂɊ܂܂�Ȃ���Ԃ́A�폜���܂��B
	*/
	CentDedRosen createSubRosen( 
		int iEkiIndex , int iEkiCount )const ;

	/**
		�S�_�C���E�S��Ԃ́A�w��̉wIndex�̉w�������A
		�w�����`���E�n���E�I���ɍ��킹�ĕύX���܂��B

		�ύX���e�́A CentDedEkiJikoku::adjustByEkijikokukeisiki()
		���Q�Ƃ��Ă��������B

	@see CentDedEkiJikoku::adjustByEkijikokukeisiki 

	@param iEkiIndex [in]
		�wIndex���w�肵�Ă��������B
	*/
	void adjustByEkijikokukeisiki( int iEkiIndex ) ;

	/**
	�H���t�@�C���𔽓]���܂��B

	(1)�@�H���t�@�C���̉w�̏����̕��я����t�ɂ��܂��B

	(2)�@�w�̃v���p�e�B�́A�ȉ��̕ϊ����s���܂��B

	(2.1)�w���͂��̂܂�

	(2.2)�w�����`��
		- ���蒅��������蒅����
		- ��蒅���������蒅����

	(2.3)���E��
		- �w�̏�����ύX��A�N�_��(�wIndex�̏�������)��1�w�V�t�g����B
		- �V�������葤�I�_(�wIndex�̍ł��傫���w)�̋��E���͖����ɂ���B

	(2.4)�_�C���O������ԏ��
	  ����̓��e�Ə��̓��e�����ւ��܂��B

	(3)�H���t�@�C���Ɋ܂܂�邷�ׂĂ̗�Ԃ̉w�����̕��я����t�ɂ��܂��B
	*/
	void invert();

	/**
		�Q�́w��Ԏ�ʁx��Index�����ւ��܂��B
	
		�w��̗�Ԏ��Index�������ׂĂ̗�Ԃ�Index���A
		����ւ��܂��B
		
	 @param iRessyasyubetsuIndexA , iRessyasyubetsuIndexB [in]
		�w��Ԏ��Index�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ� ��Ԏ�ʂ̐������ł��B
		INT_MAX �́A�����̗�Ԏ�ʂ��w�肵�����̂Ƃ݂Ȃ��܂��B
		iRessyasyubetsuIndexA �� iRessyasyubetsuIndexB �́A
		�قȂ�l�łȂ��Ă͂Ȃ�܂���B
	 @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-1 ;	//	��Ԏ��Index���s���ł��B
	 */
	int swapRessyasyubetsu( int iRessyasyubetsuIndexA ,
		int iRessyasyubetsuIndexB ) ;
	

	/**
		���ׂĂ̑�����j�����܂��B
	 */
	void clear() ;
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




#endif /*CentDedRosen_h*/
