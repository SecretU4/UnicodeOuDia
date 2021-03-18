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
using namespace std ;

#include "CentDed.h"
#include "CentDedRessya.h"
#include "CentDedRessyaCont.h"
class CentDedEkiCont ;

// ****************************************************************
//	CentDedDia
// ****************************************************************
/**
 *	@brief
 *	�y�T�v�z  DiagramEdit �́A�H���Őݒ肳��Ă���w�_�C���x�P����
 *	�\���܂��B
 *	
 *	���̃N���X�̃C���X�^���X�́A�ʏ�́w�H���x ( CentDedRosen ) �ɕ��
 *	����܂��B
 *	
 *	���ۂɂ́A
 *	
 *	- �w�H���x (CentDedRosen) ���w�_�C���x ( CentDedDia ) ��
 *	�O�ȏ㕡�����
 *	- �e�w�_�C���x ( CentDedDia ) ���w��ԁx (CentDedRessya ) ��
 *	�O�ȏ㕡�����
 *	
 *	�Ƃ����֌W�ɂȂ��Ă��܂��B
 *	
 *	  ���̃N���X�́A�w��ԁx ( CentDedRessya ) ���A����E���̕ʂ�
 *	�ێ����܂��B
 *	  �w��ԁx�̒ǉ��E�폜�́A���̃N���X�̃��\�b�h�ɂȂ��Ă��܂��B
 *
 * 
 *	�@���̃N���X�́A�����Ƃ��āw�w�̐��x�E�w��Ԏ�ʐ��x��ێ����܂��B
 *	�������A�����͔h�������ƂȂ��Ă��܂��B
 *
 * <h5>int EkiCount</h5>
 *	���̃_�C���ɑ��݂���w�w�̐��x�ł��B
 *	���̑����́A m_CentDedRessyaCont[]->m_iEkiCount �����ƂɌ��܂�܂��B
 * <h5>int RessyasyubetsuCount</h5>
 *	�w��Ԏ�ʐ��x�B��Ԏ�ʂ̎�ނ̐��ł��B
 *	���̑����́A m_CentDedRessyaCont[]->m_iRessyasyubetsuCount �����Ƃ�
 *	���܂�܂��B
 */
class CentDedDia
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:

// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 *	�_�C���̖��̂ł��B
	 *
	 *	�i��j "�����_�C��" �Ȃ�
	 *
	 * @see CentDedRosen
	 *	 CentDedRosen �́A���̑���������q�Ƃ��Ĉ����܂��B
	 *	CentDedRosen �ɕ�܂���� CentDedDia �ł́A
	 *	���̑����͈�ӂłȂ��Ă͂Ȃ�܂���B
	 */
	string	m_strName ;
///@}
// ********************************
///@name ���
// ********************************
///@{
 private:
	/**
	 *	���́w�_�C���x���ŉ^�s����Ă����Ԃ�
	 *	�w��ԁx ( CentDedRessya ) ��ێ����܂��B
	 *
	 *	���̕ϐ��́A�v�f�� 2 �̔z��ł��B\n
	 *	[0] ��	���� ( Ressyahoukou_Kudari ) ���	\n
	 *	[1] ��	��� ( Ressyahoukou_Nobori ) ���	\n
	 *	��ێ����܂��B
	 *
	 *	���̃R���e�i���� CentDedRessya �I�u�W�F�N�g��
	 *	�����E�j���̐Ӗ���this�ɂ���܂��B
	 *
	 *	������Ԃł́A�v�f���� 0 �ƂȂ�܂��B
	 */
	CentDedRessyaCont*	m_CentDedRessyaCont[2] ;
	
///@}


// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 *	���̃R���X�g���N�^�́A 
	 *	CentDedDia_From_CdConnectedString() ��
	 *	�t�@�C���̓��e���擾����Ƃ��ɁA
	 *	�ǂݎ���Ƃ��Ďw�肷��I�u�W�F�N�g�̐����Ɏg���܂��B
	 * @param iEkiCount [in]
	 *	�_�C���Ɋ܂܂��w�̐��B\n
	 * @param iRessyasyubetsuCount [in]
	 *	��Ԏ�ʂ̐�
	 */
	CentDedDia( int iEkiCount , int iRessyasyubetsuCount ) ;

	/**
	 * @param strName [in]
	 *	�_�C���̖��̂ł��B	\n
	 *	�i��j "�����_�C��" �Ȃ�
	 * @param iEkiCount [in]]
	 *	�_�C���Ɋ܂܂��w�̐��B\n
	 * @param iRessyasyubetsuCount [in]
	 *	��Ԏ�ʂ̐�
	 */
	CentDedDia( 
		const string& strName  ,
		int iEkiCount , int iRessyasyubetsuCount ) ;

	CentDedDia( const CentDedDia& value );
	
	/**
	 *	���̃N���X�ւ̑�����s���܂����A
	 *	this �́w�w�x�̐� ( m_iEkiCount ) �͕ύX���܂���B
	 *
	 *	this ����܂���w��ԁx( CentDedRessya )  �̃R�s�[�ɂ́A
	 *	CentDedRessya& operator=( const CentDedRessya& value ) 
	 *	���g���܂��B
	 */
	CentDedDia& operator=( const CentDedDia& value );

	virtual ~CentDedDia();
		
// ********************************
//	CentDedDia
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	string	getName()const{	return m_strName ;};
	CentDedDia& setName( const string& value ){
		m_strName = value ; return *this ; } ;

	int getEkiCount()const
	{
		return m_CentDedRessyaCont[ Ressyahoukou_Kudari ]->
			getEkiCount() ;
	};
	int getRessyasyubetsuCount()const
	{
		return m_CentDedRessyaCont[ Ressyahoukou_Kudari ]->
			getRessyasyubetsuCount() ;
	};

	/**
	 * @param eRessyahoukou [in]
	 *	��ԕ������w�肵�Ă��������B
	 *	-	���� :	Ressyahoukou_Kudari 
	 *	-	��� : 	Ressyahoukou_Nobori 
	 */
	CentDedRessyaCont* getpCentDedRessyaCont( 
			ERessyahoukou eRessyahoukou )const
	{
		return m_CentDedRessyaCont[ eRessyahoukou ] ;
	};
	
	/**
	 * @param eRessyahoukou [in]
	 *	��ԕ������w�肵�Ă��������B
	 *	-	���� :	Ressyahoukou_Kudari 
	 *	-	��� : 	Ressyahoukou_Nobori 
	 */
	IfContGet< CentDedRessya* >* getCentDedRessyaContGet( 
			ERessyahoukou eRessyahoukou )const
	{
		return m_CentDedRessyaCont[ eRessyahoukou ]->getIfContGet() ;
	};
	
	
	///@}

	// ********************************
	///@name CentDedDia-�w���E��Ԏ�ʐ��̕ύX
	// ********************************
	///@{
	/**
	 *	���̃R���e�i�Ɋ܂܂�邷�ׂĂ�
	 *	�w�_�C���x ( CentDedDia )�ɑ΂��A
	 *	�w�w�x�I�u�W�F�N�g�̑����̕ύX��ʒm���܂��B
	 *	
	 *	���̊֐��́A�w�n���w�E�I���w�̉w�����`���ύX�ɔ����A�������E�������̏C���x
	 *	���s�킹�܂��B
	 * @param iEkiOrder [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wIndex�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� m_iEkiCount �ȉ��ł��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 */
	int onSetCentDedEki( const CentDedEkiCont* pCentDedEkiCont , int iEkiIndex ) ;

	/**
	 *	���̃_�C���Ɋ܂܂�邷�ׂẮw��ԁx ( CentDedRessya )�ɑ΂��A
	 *	�w�w�����x�I�u�W�F�N�g���A�w��̈ʒu�ɑ}�����܂��B
	 * @param iEkiIndex [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wIndex�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� getCentEkiJikokuCount() �ȉ��ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�C���f�N�X���s���ł��B
	 */
	int insertCentDedEkiJikoku(	int iEkiIndex = INT_MAX ) ;
	
	/**
	 *	���̃_�C���Ɋ܂܂�邷�ׂẮw��ԁx ( CentDedRessya )�ɑ΂��A
	 *	�w�w�����x�I�u�W�F�N�g���A�w��̈ʒu����폜���܂��B
	 * @param iEkiOrder [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wIndex�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�C���f�N�X���s���ł��B
	 */
	int eraseCentDedEkiJikoku( int iEkiIndex = INT_MAX ) ;

	/**
	 *	�w��Ԏ�ʁx�̒ǉ��ɔ����A
	 *	���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂĂ�
	 *	�w��ԁx ( CentDedRessya ) �́w��Ԏ��Index�x���C�����܂��B
	 *
	 *	���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂĂ�
	 *	�w��ԁx ( CentDedRessya ) �̂����A
	 *	���� iRessyasyubetsuIndex �ȏ�� �w��Ԏ��Index�x������
	 *	�w��ԁx ( CentDedRessya ) �́w��Ԏ��Index�x�� 1 ���Z���܂��B
	 *
	 *	�܂��A������ this �� m_iRessyasyubetsuCount �� 1 ���Z���܂��B
	 *
	 * @param iRessyasyubetsuIndex [in]
	 *	��Ԏ�ʂ̒ǉ��ʒu���w�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� m_iRessyasyubetsuCount �ȉ��ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�C���f�N�X���s���ł��B
	 */
	int insertRessyasyubetsuIndex( int iRessyasyubetsuIndex = INT_MAX ) ;
	
	/**
	 *	�w��Ԏ�ʁx�̍폜�ɔ����A
	 *	���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂĂ�
	 *	�w��ԁx ( CentDedRessya ) �́w��Ԏ��Index�x���C�����܂��B
	 *
	 *	���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂĂ�
	 *	�w��ԁx ( CentDedRessya ) �̂����A
	 *	���� iRessyasyubetsuIndex ���傫�� �w��Ԏ��Index�x������
	 *	�w��ԁx ( CentDedRessya ) �́w��Ԏ��Index�x�� 1 ���Z���܂��B
	 *
	 *	�܂��A������ this �� m_iRessyasyubetsuCount �� 1 ���Z���܂��B
	 *
	 * @param iRessyasyubetsuIndex [in]
	 *	�폜�����Ԏ��Index���w�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� m_iRessyasyubetsuCount �����ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�C���f�N�X���s���ł��B
	 *	-	-3 ;	//	�w��Ԏ�ʁx�� iRessyasyubtsuIndex �̗�Ԃ����݂��܂��B
	 */
	int eraseRessyasyubetsuIndex( int iRessyasyubetsuIndex  = INT_MAX ) ;

	/**
	 *	���̃R���e�i�ɁA�w�肳�ꂽ�w��Ԏ�ʁx�̗�Ԃ����邩�ۂ��𒲂ׂ܂��B
	 * @param iRessyasyubetsuIndex [in]
	 *	�w��Ԏ��Index�x���w�肵�Ă��������B
	 *	�͈͂́A 0 �ȏ� ��Ԏ�ʂ̐������ł��B
	 *	INT_MAX �́A�����̗�Ԏ�ʂ��w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @param peRessyahoukou [out]
	 *	���̊֐��͂��̕ϐ��ɁA�w��Ԏ�ʁx�̗�Ԃ���������
	 *	�_�C���̗�ԕ������������݂܂��B
	 *	�s�v�Ȃ� NULL �ł����܂��܂���B
	 * @param piRessyaIndex [out]
	 *	���̊֐��͂��̕ϐ��ɁA�w��Ԏ�ʁx�̗�Ԃ���������
	 *	���Index ���������݂܂��B
	 *	�s�v�Ȃ� NULL �ł����܂��܂���B
	 * @return 
	 *	-	1; //	�w��̗�Ԏ�ʂ̗�Ԃ����݂��܂��B
	 *	-	0; //	�w��̗�Ԏ�ʂ̗�Ԃ͑��݂��܂���B
	 *	-	-1 ;	//	�C���f�N�X���s��
	 */
	int isExistRessyaOfRessyasyubetsu( 
		int iRessyasyubetsuIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) ;

	///@}

};


#endif /*CentDedDia_h*/


