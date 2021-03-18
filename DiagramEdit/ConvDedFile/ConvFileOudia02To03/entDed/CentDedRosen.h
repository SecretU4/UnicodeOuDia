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
using namespace std ;

#include "CentDed.h"
#include "CentDedEkiCont.h"
#include "CentDedRessyasyubetsuCont.h"
#include "CentDedDiaCont.h"
#include "Cont/CaCont_vector.h"

// ****************************************************************
//	CentDedRosen
// ****************************************************************
/**
 *	@brief
 *	�y�T�v�z  DiagramEdit �́A�w�H���x�P��\���܂��B
 *	  ���̃N���X�́A DiagramEdit �̃G���e�B�e�B�N���X CentDed... ��
 *	���[�g�ƂȂ�N���X�ł��B�ȉ��̃N���X�̃I�u�W�F�N�g���܂��܂��B
 *	
 *	- �w�w�x ( CentDedEki ) �F 0 �ȏ㕡���̃I�u�W�F�N�g���܂��܂��B
 *
 *	- �w��Ԏ�ʁx ( CentDedRessyasyubetsu ) �F 1 �ȏ㕡���̃I�u�W�F�N�g��
 *	��܂��܂��B
 *
 *	- �w�_�C���x ( CentDedDia ) �F 0 �ȏ㕡���̃I�u�W�F�N�g���܂��܂��B
 *	�w�_�C���x ( CentDedDia ) �́A�w��ԁx ( CentDedRessya ) ���O�ȏ㕡��
 *	��܂��Ă��܂��B����ɁA�w��ԁx�́A�w�w�����x ( CentDedEkiJikoku ) ��
 *	�w�w�x�̐�������܂��Ă��܂��B
 *
 *	\n this �ɕ�܂���� CentDedDia �́A CentDedDia::m_strName ����ӂłȂ��Ă�
 *	�Ȃ�܂���B������ CentDedDia �� insertCentDedDia() �œo�^���悤�Ƃ���ƁA
 *	�G���[�ƂȂ�܂��B
 *
 *  �w�w�x�I�u�W�F�N�g��ǉ��E�폜�����ꍇ�Athis �͕�܂��Ă���
 *	���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
 *	�w�w�����x ( CentDedEkiJikoku )�I�u�W�F�N�g�̒ǉ��E�폜���s���܂��B
 *	
 *	  �w��Ԏ�ʁx�I�u�W�F�N�g���폜�����ꍇ�A this �͕�܂��Ă��邷�ׂĂ�
 *	�w��ԁx�I�u�W�F�N�g�̂����A�폜���ꂽ�w��Ԏ��Index�x�����w��ԁx
 *	�ɑ΂��āA�w��Ԏ��Index�x��0(����̗�Ԏ��)�ɕύX���܂��B
 *
 *
 *	  �w�wIndex�x�́A�H���̉����Ԃ̎n���w�i����Ԃ̏I���w�j�� 0 �E 
 *	�����Ԃ̏I���w�i����Ԃ̎n���w�j �� ( �w�̐� - 1 ) �ƂȂ�܂��B
 * @see CentDedRessya
 *	�y�wIndex �� �wOrder�z ���Q�Ƃ��Ă��������B
 */
class CentDedRosen
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
public:

protected:
	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedEkiCont
	// ----------------------------------------------------------------
	/**
	 *	@brief
	 *  �w�H���x�I�u�W�F�N�g�ɕ�܂����A
	 *	�w�w�x(CentDedEki) �I�u�W�F�N�g�̃R���e�i�ł��B
	 *
	 *  �w�w�x�I�u�W�F�N�g��ǉ��E�폜�����ꍇ�A
	 *	this �͊֘A����w�H���x����܂��Ă���
	 *	���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
	 *	�w�w�����x ( CentDedEkiJikoku )�I�u�W�F�N�g�̒ǉ��E�폜���s���܂��B
	 *	
	 */
	class CXCentDedEkiCont : public CentDedEkiCont
	{
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	public:
		typedef CentDedEkiCont	super ;
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	 private:
		/**
		 *	�w�H���x�I�u�W�F�N�g�Ƃ̊֘A�ł��B
		 *
		 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		 *	���̃I�u�W�F�N�g�́Athis�̔j����܂Ő������Ȃ��Ă͂Ȃ�܂���B
		 */
		CentDedRosen*	m_pCentDedRosen ;
	///@}
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	 public:
		/**
		 * @param pCentDedRosen [in]
		 *	�w�H���x�I�u�W�F�N�g�Ƃ̊֘A�ł��B
		 *	\n���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		 *	���̃I�u�W�F�N�g�́Athis�̔j����܂Ő������Ȃ��Ă͂Ȃ�܂���B
		 *
		 * @attention
		 *	���̃R���X�g���N�^�́A
		 *	pCentDedRosen �Ɋ܂܂��S�Ă̗�Ԃ̉w�����A this �̉w����
		 *	�����ɒ������܂��B
		 */
		CXCentDedEkiCont( CentDedRosen* pCentDedRosen ) ;

	 private:
		CXCentDedEkiCont( const CXCentDedEkiCont& value ){} ;
		CXCentDedEkiCont& operator=( const CXCentDedEkiCont& value ){} ;
	 public:
		virtual ~CXCentDedEkiCont() ;
		
	// ********************************
	//	IfCont
	// ********************************
	 public:
		/**
		 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
		 *	�v�f��u�������܂��B
		 * @param element [in]
		 * 	�v�f���w�肵�Ă��������B
		 * @param iIndex [in]
		 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 * 	�͈͂͂O�ȏ� size() �ȉ��ł��B
		 * 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		 *	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 * @return
		 * 	0�ȏ�͐����A���̐��̓G���[�ł�
		 *
		 *	<H4>
		 *	�y�I�[�o���C�h�z
		 *	</H4>
		 *	CentDedEki �I�u�W�F�N�g��ǉ�����̂ɉ����āA
		 *	m_pCentDedRosen ����܂��Ă���S�Ă̗�Ԃ̂����A
		 *	iIndex �̉w���n���E�I���Ƃ����Ԃ̉w������
		 *	�␳���܂��B
		 */
	 	virtual int  set (const CentDedEki& element, int iIndex) ;

		/**
		 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
		 * 	�v�f��ǉ����܂��B
		 * @param element [in]
		 * 	�v�f���w�肵�Ă��������B
		 * @param iIndex [in]
		 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 * 	�͈͂͂O�ȏ� size() �ȉ��ł��B
		 * 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		 *	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 * @return
		 * 	0�ȏ�͐����A���̐��̓G���[�ł�
		 *
		 *	<H4>
		 *	�y�I�[�o���C�h�z
		 *	</H4>
		 *	CentDedEki �I�u�W�F�N�g��ǉ�����̂ɉ����āA
		 *	m_pCentDedRosen ����܂��Ă���S�Ă̗�Ԃɑ΂��āA
		 *	�w�����̒ǉ����s���܂��B
		 */
		virtual int insert( const CentDedEki& element , int iIndex = INT_MAX );
		/**
		 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
		 * 	�v�f���폜���܂��B
		 * @param iIndex [in]
		 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 * 	�͈͂͂O�ȏ� size() �����ł��B
		 * 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 * @param iSize [in]
		 * 	�폜����v�f�̐����w�肵�Ă��������B
		 * 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
		 * @attention
		 *	iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
		 * @return
		 * 	0�ȏ�͐����A���̐��̓G���[�ł�
		 *
		 *	<H4>
		 *	�y�I�[�o���C�h�z
		 *	</H4>
		 *	CentDedEki �I�u�W�F�N�g���폜����̂ɉ����āA
		 *	m_pCentDedRosen ����܂��Ă���S�Ă̗�Ԃɑ΂��āA
		 *	�w�����̍폜���s���܂��B
		 */
		virtual int erase( int iIndex  , int iSize = 1 ) ;
	};
	friend class CXCentDedEkiCont ;

	// ----------------------------------------------------------------
	//	CentDedRosen::CXCentDedRessyasyubetsuCont
	// ----------------------------------------------------------------
	/**
	 *	@brief
	 *  �w�H���x�I�u�W�F�N�g�ɕ�܂����A
	 *	�w��Ԏ�ʁx(CentDedRessyasyubetsu) �I�u�W�F�N�g�̃R���e�i�ł��B
	 *	
	 *	�ʏ�̗�Ԏ�ʃR���e�i�ɉ����āA�ȉ��̂悤�ȓ��������݂��܂��B
	 *	
	 *	
	 * �P�D  �w��Ԏ�ʁx�I�u�W�F�N�g��ǉ��E�폜�����ꍇ�A
	 *	this �͊֘A����w�H���x����܂��Ă���
	 *	���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
	 *	�w��Ԏ��Index�x ( CentDedRessya::m_iRessyasyubetsuIndex )
	 *	�̏C�����s���܂��B
	 *
	 *	�Q�D  �Ή������Ԃ� m_pCentDedRosen ���ɑ��݂���ꍇ�A
	 *	���̗�Ԏ�ʂ��폜���邱�Ƃ͂ł��܂���B
	 *	  �ʏ�A�w��Ԏ�ʁx�̃R���e�i��u��������ꍇ�́A 
	 *	m_pCentDedRosen ����A���ׂĂ̗�Ԃ��폜���Ă����K�v������܂��B
	 */
	class CXCentDedRessyasyubetsuCont : public CentDedRessyasyubetsuCont
	{
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	public:
		typedef CentDedRessyasyubetsuCont	super ;
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	 private:
		/**
		 *	�w�H���x�I�u�W�F�N�g�Ƃ̊֘A�ł��B
		 *
		 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		 *	���̃I�u�W�F�N�g�́Athis�̔j����܂Ő������Ȃ��Ă͂Ȃ�܂���B
		 */
		CentDedRosen*	m_pCentDedRosen ;
	///@}
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	 public:
		/**
		 * @param pCentDedRosen [in]
		 *	�w�H���x�I�u�W�F�N�g�Ƃ̊֘A�ł��B
		 *	\n���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		 *	���̃I�u�W�F�N�g�́Athis�̔j����܂Ő������Ȃ��Ă͂Ȃ�܂���B
		 *
		 */
		CXCentDedRessyasyubetsuCont( CentDedRosen* pCentDedRosen ) ;

	 private:
		CXCentDedRessyasyubetsuCont( const CXCentDedRessyasyubetsuCont& value ){} ;
		CXCentDedRessyasyubetsuCont& operator=( const CXCentDedRessyasyubetsuCont& value ){} ;
	 public:
		virtual ~CXCentDedRessyasyubetsuCont() ;
		
	// ********************************
	//	IfCont
	// ********************************
	 public:
		/**
		 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
		 * 	�v�f��ǉ����܂��B
		 * @param element [in]
		 * 	�v�f���w�肵�Ă��������B
		 * @param iIndex [in]
		 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 * 	�͈͂͂O�ȏ� size() �ȉ��ł��B
		 * 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		 *	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 * @return
		 * 	0�ȏ�͐����A���̐��̓G���[�ł�
		 *	-	-1 ;	//	iIndex ���s���ł��B
		 *
		 *	<H4>
		 *	�y�I�[�o���C�h�z
		 *	</H4>
		 *	CentDedRessyasyubetsu �I�u�W�F�N�g��ǉ�����̂ɉ����āA
		 *	���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
		 *	�w��Ԏ��Index�x ( CentDedRessya::m_iRessyasyubetsuIndex )
		 *	�̏C�����s���܂��B
		 */
		virtual int insert( const CentDedRessyasyubetsu& element , int iIndex = INT_MAX );
		/**
		 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
		 * 	�v�f���폜���܂��B
		 * @param iIndex [in]
		 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 * 	�͈͂͂O�ȏ� size() �����ł��B
		 * 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 * @param iSize [in]
		 * 	�폜����v�f�̐����w�肵�Ă��������B
		 * 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
		 * @attention
		 *	iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
		 * @return
		 * 	0�ȏ�͐����A���̐��̓G���[�ł�
		 *	-	-1 ;	//	iIndex ���s���ł��B
		 *	-	-11 ;	//	�폜�Ώۂ̗�Ԏ�ʂ̗�Ԃ����݂��܂��B
		 *
		 *	<H4>
		 *	�y�I�[�o���C�h�z
		 *	</H4>
		 *	CentDedRessyasyubetsu �I�u�W�F�N�g���폜����̂ɉ����āA
		 *	���ׂẮw��ԁx ( CentDedRessya ) �ɑ΂��āA
		 *	�w��Ԏ��Index�x ( CentDedRessya::m_iRessyasyubetsuIndex )
		 *	�̏C�����s���܂��B
		 */
		virtual int erase( int iIndex  , int iSize = 1 ) ;

	};
	friend class CXCentDedRessyasyubetsuCont ;



// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 *	�H���̖��̂ł��B
	 *	�i��j "�ߓS����" �Ȃ�
	 */
	string	m_strName ;
	
	/**
	 *	�_�C���̋N�_�����ł��B
	 *	���̎����́A�_�C���O�����̍��[�̎����ƂȂ�܂��B
	 *
	 *	����l�� 00:00:00 �ł��B
	 * @attention
	 *	���̒l�́A Null ��Ԃɂ��Ȃ��ł��������B
	 */
	CdDedJikoku	m_jikokuKitenJikoku ;
	
	/**
	 *	�R�����g�B
	 *	CDedCommentDoc,CDedCommentView �ŕҏW���܂��B
	 */
	string	m_strComment ;
	
///@}
// ********************************
///@name ���
// ********************************
///@{
 private:
	/**
	 *	���́w�H���x�ɂ���w�w�x ( CentDedEki ) ��ێ����܂��B
	 *
	 *	���̃R���e�i���� CentDedEki �I�u�W�F�N�g��
	 *	�����E�j���̐Ӗ���this�ɂ���܂��B
	 *
	 *	������Ԃł́A�v�f���� 0 �ƂȂ�܂��B
	 */
	CXCentDedEkiCont*	m_pCentDedEkiCont ;
	
	/**
	 *	���́w�H���x�ɂ���w��Ԏ�ʁx ( CentDedRessyasyubetsu ) ��ێ����܂��B
	 *
	 *	���̃R���e�i���� CentDedRessyasyubetsu �I�u�W�F�N�g��
	 *	�����E�j���̐Ӗ���this�ɂ���܂��B
	 *
	 *	������Ԃł́A�v�f���� 1 �ƂȂ�܂��B
	 *	�w��Ԏ�ʁx�́A���Ȃ��Ƃ���͑��݂��Ȃ��Ă͂Ȃ�܂���B
	 */
	CXCentDedRessyasyubetsuCont*	m_pCentDedRessyasyubetsuCont ;
	
	/**
	 *	���́w�H���x�ɂ���w�_�C���x ( CentDedDia ) ��ێ����܂��B
	 *
	 *	���̃R���e�i���� CentDedDia �I�u�W�F�N�g��
	 *	�����E�j���̐Ӗ���this�ɂ���܂��B
	 *
	 *
	 * @attention
	 *	this �́A CentDedDia::m_strName ������q�Ƃ��Ĉ����܂��B
	 *	\n ���̃R���e�i���� CentDedDia �́A CentDedDia::m_strName ��
	 *	��ӂłȂ��Ă͂Ȃ�܂���B
	 *
	 *	������Ԃł́A�v�f���� 0 �ƂȂ�܂��B
	 */
	CentDedDiaCont	m_CentDedDiaCont ;
	
///@}
	
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param strName [in]
	 *	�H���̖��̂ł��B	\n
	 *	�i��j "�ߓS����" �Ȃ�
	 */
	CentDedRosen() ;
	
	CentDedRosen( const CentDedRosen& value );
	CentDedRosen& operator=( const CentDedRosen& value );

	virtual ~CentDedRosen() ;

	
// ********************************
//	CentDedRosen
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	string	getName()const{	return m_strName ;};
	CentDedRosen& setName( const string& value ){
		m_strName = value ; return *this ; } ;
	CdDedJikoku	getKitenJikoku()const{	return m_jikokuKitenJikoku ;};
	CentDedRosen& setKitenJikoku( const CdDedJikoku& value ){
		m_jikokuKitenJikoku = value ; return *this ; 
	} ;
	string	getComment()const{return m_strComment ;};
	CentDedRosen& setComment( const string& value ){
		m_strComment = value ;	return *this ; 
	} ;
	///@}
	
	// ********************************
	///@name ���-CentDedEki
	// ********************************
	///@{
	/**
	 * @return 
	 *	�w�w�x ( CentDedEki ) �I�u�W�F�N�g�̃R���e�i�ւ�
	 *	�C���^�[�t�F�[�X��Ԃ��܂��B
	 *	���̃C���^�[�t�F�[�X�́A CentDedEki �I�u�W�F�N�g��H����
	 *	�ǉ��E�폜���邽�߂̃C���^�[�t�F�[�X�ł��B
	 */
	CentDedEkiCont* getCentDedEkiCont(){	return m_pCentDedEkiCont ; } ;
	const CentDedEkiCont* getCentDedEkiCont()const{	return m_pCentDedEkiCont ; } ;
	
	/**
	 *	�w�wIndex�x ���C���f�N�X�ɂ��āA�R���e�i���̉w�I�u�W�F�N�g��
	 *	�A�N�Z�X���邱�Ƃ̂ł��� IfContGet<CentDedEki*> �C���^�[�t�F�[�X��
	 *	�擾���邱�Ƃ��ł��܂��B
	 * @return 
	 *	�R���e�i���̗v�f�̃I�u�W�F�N�g��
	 *	�A�N�Z�X���邽�߂� IfContGet<CentDedEki*>* ��Ԃ��܂��B
	 *
	 *	���̃C���^�[�t�F�[�X��
	 */
	IfContGet<const CentDedEki*>* getCentDedEkiContGet()
	{
		return m_pCentDedEkiCont->getIfContGet() ;
	};
	const IfContGet<const CentDedEki*>* getCentDedEkiContGet()const
	{
		return m_pCentDedEkiCont->getIfContGet() ;
	};
	
	/**
	 *	�w�wOrder�x ���C���f�N�X�ɂ��āA�R���e�i���̉w�I�u�W�F�N�g�̏�񂪎擾�ł���
	 *	 IfContGet<CentDedEkiCont::CdDedEki> �C���^�[�t�F�[�X��
	 *	�擾���邱�Ƃ��ł��܂��B
	 * @param eRessyahoukou [in]
	 *	��ԕ������w�肵�Ă��������B
	 * @return 
	 *	�R���e�i���̉w�I�u�W�F�N�g CentDedEki �ւ̃|�C���^��
	 *	�A�N�Z�X���邽�߂� IfContGet<CentDedEki*>* ��Ԃ��܂��B
	 */
	IfContGet<CentDedEkiCont::CdDedEki>* getCentDedEkiContGet( ERessyahoukou eRessyahoukou )
	{
		return m_pCentDedEkiCont->getIfContGet( eRessyahoukou ) ;
	};
	const IfContGet<CentDedEkiCont::CdDedEki>* getCentDedEkiContGet( ERessyahoukou eRessyahoukou )const
	{
		return m_pCentDedEkiCont->getIfContGet( eRessyahoukou ) ;
	};
	
	///@}
	
	// ********************************
	///@name ���-CentDedRessyasyubetsu
	// ********************************
	///@{
	/**
	 * @return 
	 *	�w��Ԏ�ʁx ( CentDedRessyasyubetsu ) �I�u�W�F�N�g�̃R���e�i�ւ�
	 *	�C���^�[�t�F�[�X��Ԃ��܂��B
	 *	���̃C���^�[�t�F�[�X�́A CentDedRessyasyubetsu �I�u�W�F�N�g��H����
	 *	�ǉ��E�폜���邽�߂̃C���^�[�t�F�[�X�ł��B
	 */
	CentDedRessyasyubetsuCont* getCentDedRessyasyubetsuCont()
	{
		return m_pCentDedRessyasyubetsuCont ; 
	} ;
	const CentDedRessyasyubetsuCont* getCentDedRessyasyubetsuCont()const
	{
		return m_pCentDedRessyasyubetsuCont ; 
	} ;
	
	/**
	 *	�w��Ԏ��Index�x ���C���f�N�X�ɂ��āA
	 *	�R���e�i���̗�Ԏ�ʃI�u�W�F�N�g��
	 *	�A�N�Z�X���邱�Ƃ̂ł��� IfContGet<CentDedRessyasyubetsu*> 
	 *	�C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
	 * @return 
	 *	�R���e�i���̗v�f�̃I�u�W�F�N�g��
	 *	�A�N�Z�X���邽�߂� IfContGet<CentDedRessyasyubetsu*>* ��Ԃ��܂��B
	 *
	 *	���̃C���^�[�t�F�[�X��
	 */
	IfContGet<CentDedRessyasyubetsu*>* getCentDedRessyasyubetsuContGet()
	{
		return m_pCentDedRessyasyubetsuCont->getIfContGet() ;
	};
	const IfContGet<CentDedRessyasyubetsu*>* 
		getCentDedRessyasyubetsuContGet()const
	{
		return m_pCentDedRessyasyubetsuCont->getIfContGet() ;
	};

	
	/**
	 *	�Q�́w��Ԏ�ʁx��Index�����ւ��܂��B
	 *
	 *	�w��̗�Ԏ��Index�������ׂĂ̗�Ԃ�Index���A
	 *	����ւ��܂��B
	 *	
	 * @param iRessyasyubetsuIndexA , iRessyasyubetsuIndexB [in]
	 *	�w��Ԏ��Index�x���w�肵�Ă��������B
	 *	�͈͂́A 0 �ȏ� ��Ԏ�ʂ̐������ł��B
	 *	INT_MAX �́A�����̗�Ԏ�ʂ��w�肵�����̂Ƃ݂Ȃ��܂��B
	 *	iRessyasyubetsuIndexA �� iRessyasyubetsuIndexB �́A
	 *	�قȂ�l�łȂ��Ă͂Ȃ�܂���B
	 * @return 
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-1 ;	//	��Ԏ��Index���s���ł��B
	 */
	int swapRessyasyubetsu( int iRessyasyubetsuIndexA ,
		int iRessyasyubetsuIndexB ) ;
	
	///@}
	// ********************************
	///@name ���-CentDedDia
	// ********************************
	///@{
	/**
	 * @return 
	 *	�w�_�C���x ( CentDedDia ) �I�u�W�F�N�g�̃R���e�i�ւ�
	 *	�C���^�[�t�F�[�X��Ԃ��܂��B
	 *	���̃C���^�[�t�F�[�X�́A CentDedDia �I�u�W�F�N�g��H����
	 *	�ǉ��E�폜���邽�߂̃C���^�[�t�F�[�X�ł��B
	 */
	CentDedDiaCont* getCentDedDiaCont(){	return &m_CentDedDiaCont ;};
	const CentDedDiaCont* getCentDedDiaCont()const{	return &m_CentDedDiaCont ;};

	/**
	 * @return 
	 *	�w�_�C���x ( CentDedDia ) �I�u�W�F�N�g�̃R���e�i�ւ�
	 *	�C���^�[�t�F�[�X��Ԃ��܂��B
	 *	���̃C���^�[�t�F�[�X�́A CentDedDia �I�u�W�F�N�g�ւ̃|�C���^��
	 *	�A�N�Z�X���邽�߂̃C���^�[�t�F�[�X�ł��B
	 */
	IfContGet<CentDedDia*>* getCentDedDiaContGet()
	{
		return m_CentDedDiaCont.getIfContGet() ;
	};
	const IfContGet<CentDedDia*>* getCentDedDiaContGet()const
	{
		return m_CentDedDiaCont.getIfContGet() ;
	};
	///@}
	
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 *	���ׂĂ̑�����j�����܂��B
	 */
	void clear() ;
	///@}
};





#endif /*CentDedRosen_h*/
