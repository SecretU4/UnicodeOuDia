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
//	CentDedRessya.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessya_h
#define  CentDedRessya_h


#include <deque>
using namespace std ;


#include "Cont/Ccont_deque.h"
#include "cont/CaContGet_ptref.h"

#include "CentDed.h"
#include "CentDedEkiJikoku.h"
#include "CdDedJikan.h"
#include "CentDedEkiCont.h"


// ****************************************************************
//	CentDedRessya
// ****************************************************************
/**
 * @brief
 *	�y�T�v�z  DiagramEdit �́A�H����ŉ^�s�����w��ԁx�P�{��\���܂��B
 *	
 *	���̃N���X�̃C���X�^���X�́A�ʏ�́w�H���x�i CentDedRosen �j��
 *	��܂���܂��B
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
 *	���̃N���X�́A�w�H���x�i CentDedRosen �j�ɑ��݂���
 *	�w�w�x ( CentDedEki )�̐������A�w�w�����x(CentDedEkiJikoku�j
 *	�I�u�W�F�N�g��ێ����܂��B�w�H���x ( CentDedRosen )�ɕ�܂����
 *	���ׂẮw��ԁx( CentDedRessya )����܂���
 *	�w�w�����x ( CentDedEkiJikoku ) �I�u�W�F�N�g�̐��́A
 *	�w�H���x ( CentDedRosen )�́w�w�x ( CentDedEki ) �̐��Ɠ����łȂ��Ă�
 *	�Ȃ�܂���B
 *	  ���̓������Ƃ邽�߁A�w��ԁx ( CentDedRessya ) �ɑ΂���
 *	�w�w�����x ( CentDedEkiJikoku ) �I�u�W�F�N�g�̒ǉ��E�폜�̑���͐���
 *	����Ă��܂��B
 *	�w�w�����x�̒ǉ��E�폜�̑���́A�w�H���x�I�u�W�F�N�g�ɑ΂��Ă̂�
 *	��������̂Ƃ��܂��B���̃N���X�� 
 *	�w�H���x ( CentDedRosen ) �E�w�_�C���x ( CentDedDia ) 
 *	�� friend �N���X�Ɏw�肵�Ă���̂͂��̂��߂ł��B
 *	
 *	�܂��A���̃N���X���ێ�����A�w��Ԏ��Index�x�����́A
 *	�w�H���x( CentDedRosen )���ێ�����w��Ԏ�ʁx ( CentDedRessyasyubetsu )
 *	�I�u�W�F�N�g�ɑΉ����܂��B
 *	
 *	���̃I�u�W�F�N�g�́A�L���ȗ�ԃf�[�^�������Ȃ��wNull��ԁx��
 *	�Ƃ邱�Ƃ��ł��܂��B
 *	�wNull��ԁx�̗�Ԃ́A�w�����\�r���[�x�ł͋�s�Ƃ��ĕ\������܂��B
 *	
 *	<H4>
 *	�y�wIndex �� �wOrder , ����Order�z
 *	</H4>
 *	  �w�H���x ( CentDedRosen ) �I�u�W�F�N�g���̓����
 *	�w�w�x ( CentDedEki )�I�u�W�F�N�g���w�肷����@�A�y��
 *	�w��ԁx ( CentDedRessya )�I�u�W�F�N�g���̓����
 *	�w�w�����x ( CentDedEkiJikoku ) �I�u�W�F�N�g���w�肷����@�ɂ́A
 *	�w�wIndex�x�E�w�wOrder�x�̂Q������܂��B�ǂ�����A
 *	0 �ȏ� ( �w�̐�) ���� �̐����ŁA�w�w�x���w�肵�܂��B
 *	
 *	  �w�wIndex�x�́A�H���̉����Ԃ̎n���w�i����Ԃ̏I���w�j�� 0 �E 
 *	�����Ԃ̏I���w�i����Ԃ̎n���w�j �� ( �w�̐� - 1 ) �ƂȂ�܂��B
 *	
 *	  �w�wOeder�x�́A��Ԃ̕����ʂ̃C���f�N�X�ł��B�����ԁE�����
 *	�Ƃ��Ɏn���w�� 0 �E �I���w�� ( �w�̐� - 1 ) ��
 *	�Ȃ�܂��B
 *
 *	  �]���āA�w�wIndex�x�� 0 �̉w�́A�����ԂɂƂ��Ắw�wOeder�x ��
 *	 0 �ł����A����ԂɂƂ��Ắw�wOrder�x �� �i�w�̐� - 1 �j�ƂȂ�܂��B 
 *	
 *	  �w�H���x ( CentDedRosen ) �N���X�ł́A�����Ƃ���
 *	�w�w�x( CentDedEki ) �I�u�W�F�N�g���w�肷��̂Ɂw�wIndex�x���g���܂��B
 *	�w�w�x��ێ�����R���e�i CentDedRosen::m_CentDedEkiCont �̓Y������
 *	�w�wIndex�x�ɂȂ��Ă��܂��B
 *	\n  ����Ƃ͑ΏƓI�ɁA�w��ԁx(�N���X�ł́A�����Ƃ���
 *	�w�w�����x ( CentDedEkiJikoku ) �I�u�W�F�N�g���w�肷��̂ɂ�
 *	�w�wOrder�x���g���܂��B�w�w�����x ( CentDedEkiJikoku ) ��ێ�����R���e�i
 *	  CentDedRessya::m_CentDedEkiJikokuCont �̓Y�������A�w�wOrder�x 
 *	�ƂȂ�܂��B
 *	  �ǂ���̃N���X�ɂ����Ă��A�w�wIndex�x�Ɓw�wOrder�x�̑��ݕϊ����s��
 *	���\�b�h EkiIndexOfEkiOrder() , EkiOrderOfEkiIndex() ��񋟂��Ă��܂��B
 *	
 *	�w����Order�x�́A�w��ԁx�I�u�W�F�N�g���ŁA����̎���
 *	�i����w�̒��E���̂����ꂩ�j���w�肷�鏇�����ł��B
 *	�w����Order�x�́A�ȉ��̖@���������܂��B
 *	�l�͈̔͂́A0 �ȏ� �w�̐�*2 �����ł��B
 *	
 *	- �w�wOrder�x*2 + 0 �E�E�E�w�wOrder�x�̉w�̒�����(�Ƃ���ȍ~)
 *	��ύX���܂��B
 *	- �w�wOrder�x*2 + 1 �E�E�E�w�wOrder�x�̉w�̔�����(�Ƃ���ȍ~)
 *	��ύX���܂��B
 *	
 */
class CentDedRessya
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
 public:
	typedef deque< CentDedEkiJikoku* > CentDedEkiJikokuCont ;
	
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 *	���̗�Ԃ��wNull��ԁx�Ȃ�^�A
	 *	�L���ȗ�ԑ�����ێ����Ă���̂Ȃ�U�ł��B
	 *	
	 *	���̑������^�̏ꍇ�A���� 
	 *	-	m_iRessyasyubetsuIndex,
	 *	-	m_strRessyabangou ;
	 *	-	m_strRessyamei ;
	 *	-	m_strGousuu ;
	 *	-	m_strBikou ;
	 *
	 *	����сA
	 *		m_CentDedEkiJikokuCont �Ɋi�[����Ă��� 
	 *	CentDedEkiJikoku �́A�Ӗ��������܂���B
	 *	
	 *	�K��l�� true �ł��B
	 *	set...() ���\�b�h�ŁAm_eRessyahoukou �ȊO��
	 *	�����ꂩ�̑�����ݒ肵���Ƃ��ɂ́A
	 *	�����I�ɋU�ɕς��܂��B
	 *	clear() �ŁA�^�ƂȂ�܂��B
	 */
	bool m_bIsNull ;

	/**
	 *	���̗�Ԃ̗�ԕ����������܂��B
	 *	
	 *	�K��l�� Ressyahoukou_Kudari �ł��B
	 *
	 *	�R���X�g���N�^�Ō��܂�܂��B
	 */
	ERessyahoukou	m_eRessyahoukou ;

	/**
	 *	���̗�Ԃ́w��Ԏ�ʁx���A
	 *	�w��Ԏ��Index�x�ŕێ����܂��B
	 *	
	 *	�K��l�� 0 �ł��B
	 */
	int	m_iRessyasyubetsuIndex ;
	
	/**
	 *	���̗�Ԃ́w��Ԕԍ��x�B
	 *	
	 *	�K��l�͋󕶎���ł��B
	 */
	string m_strRessyabangou ;
	
	/**
	 *	���̗�Ԃ́w��Ԗ��x�B
	 *	
	 *	�K��l�͋󕶎���ł��B
	 */
	string m_strRessyamei ;
	
	/**
	 *	���̗�Ԃ́w�����x�B
	 *	
	 *	�K��l�͋󕶎���ł��B
	 */
	string m_strGousuu ;
	
	/**
	 *	���̗�Ԃ́w���l�x�B
	 *	
	 *	�K��l�͋󕶎���ł��B
	 */
	string m_strBikou ;
	
///@}
// ********************************
///@name ���
// ********************************
///@{
 private:
	/**
	 *	���̗�Ԃ̊e�w�̎����B
	 *	�v�f���́A�w�w�x( CentDedEki ) �̐��ɓ������Ȃ�܂��B
	 *	�Y�����́w�wOrder�x�ł��B
	 *
	 *	���̃R���e�i���̃I�u�W�F�N�g�̐����E�j���̐Ӗ���this�ɂ���܂��B
	 *
	 *	������Ԃł́A�v�f���� 0 �ƂȂ�܂��B
	 *
	 *	���ׂẮw�w�����x��
	 *	�w�^�s�Ȃ��x(Ekiatsukai_None ),
	 *	�̏ꍇ�A���̗�Ԃ́wNull��ԁx�ƂȂ�܂��B
	 */
	CentDedEkiJikokuCont	m_CentDedEkiJikokuCont ;

///@}

// --------------------------------
///@name CentDedRosen��CentDedRessyaCont ��p�����o�֐�
// --------------------------------
///@{
 protected:
	/**
	 *	�w�w�x�I�u�W�F�N�g�̑����̕ύX��ʒm���܂��B
	 *	
	 *	���̊֐��́A�w�n���w�E�I���w�̉w�����`���ύX�ɔ����A�������E�������̏C���x
	 *	���s�킹�܂��B
	 * @param iEkiOrder [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wOrder�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� m_iEkiCount �ȉ��ł��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 */
	int onSetCentDedEki( const IfContGet<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder ) ;

	/**
	 *	�w�w�����x�I�u�W�F�N�g���A�w��̈ʒu�ɑ}�����܂��B
	 * @param aCentEkiJikoku [in]
	 *	�}������w�w�����x�I�u�W�F�N�g���w�肵�Ă��������B
	 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
	 *	���̃I�u�W�F�N�g�́A���̊֐��I����͔j���ł��܂��B
	 * @param iEkiOrder [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wOrder�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� getCentEkiJikokuCount() �ȉ��ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�C���f�N�X���s���ł��B
	 */
	int insertCentDedEkiJikoku( const CentDedEkiJikoku& aCentEkiJikoku , 
		int iEkiOrder = INT_MAX ) ;
	
	/**
	 *	�w�w�����x�I�u�W�F�N�g���A�w��̈ʒu����폜���܂��B
	 * @param iEkiOrder [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wOrder�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�C���f�N�X���s���ł��B
	 */
	int eraseCentDedEkiJikoku( int iEkiOrder = INT_MAX ) ;

	//	�w�����̒ǉ��E�폜�̂���
	friend class CentDedRessyaCont ;
///@}
	

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	*	���̗�Ԃ�NULL��Ԃɏ��������܂��B
	 * @param iEkiJikokuCount [in]
	 *	���̗�Ԃ����s����H���́w�w�x�̐����w�肵�Ă��������B
	 *	���̃R���X�g���N�^�ł́A m_CentDedEkiJikokuCont �̗v�f�����A
	 *	���̈����ŏ��������܂��B
	 *	�i�[����� CentDedEkiJikoku �́A 
	 *	CentDedEkiJikoku::m_eEkiatsukai	�� Ekiatsukai_None �ƂȂ�܂��B
	 * @param eRessyahoukou [in]
	 *	���̗�Ԃ̗�ԕ����������܂��B
	 */
	CentDedRessya( 
		int iEkiJikokuCount , 
		ERessyahoukou	eRessyahoukou ) ;
private:
	/**
	*	���̗�Ԃ��w��̗�Ԏ�ʂŏ��������܂��B
	 * @param iEkiJikokuCount [in]
	 *	���̗�Ԃ����s����H���́w�w�x�̐����w�肵�Ă��������B
	 *	���̃R���X�g���N�^�ł́A m_CentDedEkiJikokuCont �̗v�f�����A
	 *	���̈����ŏ��������܂��B
	 *	�i�[����� CentDedEkiJikoku �́A 
	 *	CentDedEkiJikoku::m_eEkiatsukai	�� Ekiatsukai_None �ƂȂ�܂��B
	 * @param eRessyahoukou [in]
	 *	���̗�Ԃ̗�ԕ����������܂��B
	 * @param iRessyasyubetsuIndex [in]
	 *	���̗�Ԃ́w��Ԏ�ʁx���A
	 *	�w��Ԏ��Index�x�ŕێ����܂��B
	 *	\n
	 *	�K��l�� 0 �ł��B
	 */
	CentDedRessya( 
		int iEkiJikokuCount , 
		ERessyahoukou	eRessyahoukou ,
		int	iRessyasyubetsuIndex ) ;
	
public:
	/**
	 *	�R�s�[�R���X�g���N�^�B
	 */
	CentDedRessya( const CentDedRessya& value );

	/**
	 *	���̃N���X�ւ̑�����s���܂����A
	 *	this �́w��ԕ����x ( m_eRessyahoukou ) �E
	 *	�w�w�����x (CentDedEkiJikoku ) �̐��͕ύX���܂���B
	 *
	 *	this �� m_CentDedEkiJikokuCont �̐��� value �� m_CentDedEkiJikokuCount
	 *	��菭�Ȃ��ꍇ�́A�s������ this �� m_CentDedEkiJikokuCount �v�f��
	 *	�w�^�s�Ȃ��x�ƂȂ�܂��B
	 *
	 *	this �� m_CentDedEkiJikokuCont �̐��� value �� m_CentDedEkiJikokuCount
	 *	��葽���ꍇ�́A�ߏ蕪�� value �� m_CentDedEkiJikokuCount �v�f��
	 *	�̂Ă܂��B
	 */
	CentDedRessya& operator=( const CentDedRessya& value );
 public:
	virtual ~CentDedRessya() ;
		
// ********************************
//	CentDedRessya
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	ERessyahoukou	getRessyahoukou()const ;
	int	getRessyasyubetsuIndex()const ;
	CentDedRessya& setRessyasyubetsuIndex( int value ) ;
	string getRessyabangou()const{
		return m_strRessyabangou ;};
	CentDedRessya& setRessyabangou( const string& value ){
		m_bIsNull = false ;
		m_strRessyabangou = value ; return *this ; } ;
	string getRessyamei()const{
		return m_strRessyamei ;};
	CentDedRessya& setRessyamei( const string& value ){
		m_bIsNull = false ;
		 m_strRessyamei = value ; return *this ; } ;
	string getGousuu()const{
		return m_strGousuu ;};
	CentDedRessya& setGousuu( const string& value ){
		m_bIsNull = false ;
		 m_strGousuu = value ; return *this ; } ;
	string getBikou()const{
		return m_strBikou ;};
	CentDedRessya& setBikou( const string& value ){
		m_bIsNull = false ;
		 m_strBikou = value ; return *this ; } ;
	///@}
	
	// ********************************
	///@name ���-CentDedEkiJikoku
	// ********************************
	///@{
	
	/**
	 * @return
	 *	�w�w�����x �̐���Ԃ��܂��B
	 */
	int getCentDedEkiJikokuCount()const ;
	
	/**
	 *	�w�wOrder�x�ɑΉ�����A�w�w�����x�I�u�W�F�N�g���擾����
	 *	���Ƃ��ł��܂��B
	 * @param iEkiOrder [in]
	 *	�w�wOrder�x���w�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return 
	 *	�Ή�����w�w�����x�I�u�W�F�N�g
	 */
	CentDedEkiJikoku getCentDedEkiJikoku( int iEkiOrder )const ;

	/**
	 *	�w�wOrder�x�ɑΉ�����A�w�w�����x�I�u�W�F�N�g��ݒ肷��
	 *	���Ƃ��ł��܂��B
	 * @param iEkiOrder [in]
	 *	�w�wOrder�x���w�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @param value [in]
	 *	�w�w�����x���w�肵�Ă��������B
	 * @return 
	 *	�Ή�����w�w�����x�I�u�W�F�N�g
	 */
	CentDedRessya& setCentDedEkiJikoku( int iEkiOrder , 
		const CentDedEkiJikoku& value ) ;

	
	///@}
	// ********************************
	///@name �w�wOrder�x�P�ʂ̑���
	// ********************************
	///@{
	/**
	 *	�w�wOrder(�w������Index)�x���A�w�wIndex�x�ɕϊ����܂��B
	 * @param iEkiOrder [in]
	 *	�w�wOrder�x���w�肵�Ă��������B
	 * @return 
	 *	0�ȏ�́w�wIndex�x��Ԃ��܂��B
	 *	�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	int EkiIndexOfEkiOrder( int iEkiOrder )const  ;
	
	/**
	 *	�w�wIndex�x���w�wOrder(�w������Index)�x�ɕϊ����܂��B
	 * @param iEkiIndex [in]
	 *	�w�wIndex�x���w�肵�Ă��������B
	 * @return 
	 *	0�ȏ�́w�wOrder�x��Ԃ��܂��B
	 *	�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	int EkiOrderOfEkiIndex( int iEkiIndex )const  ;
	
	/**
	 *	�w�wOrder�x�ɑΉ�����A�w�w�����x�I�u�W�F�N�g���A�ύX����
	 *	���Ƃ��ł��܂��B
	 *
	 *	���̂Ƃ��A�w�������x�E�w�������x���ύX���ꂽ��A
	 *	�Ȍ�̉w���������ׂČJ�艺���܂��B
	 *
	 *	�i��j
	 *
	 *	  ����܂ł�(this��)�w�������x�� 10:00 �ŁA
	 *	�V����(value ��)�w�������x�� 10:03 �̏ꍇ�́A
	 *	���́w�wOrder�x�́w�������x�ƁA
	 *	�����肠�Ƃ́w�wOrder�x�́w�������x�w�������x�����ׂāA
	 *	�R���J�艺���܂��B
	 *	
	 *	  ����܂ł�(this��)�w�������x�� IsNull �ŁA
	 *	�V����(value ��)�w�������x�� 10:03 �̏ꍇ�́A
	 *	���́w�wOrder�x�́w�������x������ 10:03 �ɍX�V���܂��B
	 *	���́w�wOrder�x�́w�������x�ƁA
	 *	�����肠�Ƃ́w�wOrder�x�́w�������x�E�w�������x�ɂ͉e����
	 *	�^���܂���B
	 *
	 *	  ����܂ł�(this��)�w�������x�� 10:00 �ŁA
	 *	�V����(value ��)�w�������x�� IsNull �̏ꍇ�́A
	 *	���́w�wOrder�x�́w�������x������ IsNull �ɍX�V���܂��B
	 *	���́w�wOrder�x�́w�������x�ƁA
	 *	�����肠�Ƃ́w�wOrder�x�́w�������x�E�w�������x�ɂ͉e����
	 *	�^���܂���B
	 *
	 *	  �w�������x�Ɋւ��Ă��A�ύX���ꂽ�ꍇ�́A���̍��ɏ]����
	 *	�����肠�Ƃ́w�wOrder�x�́w�������x�E�w�������x�̌J��グ/�J�艺����
	 *	�s���܂��B
	 *
	 *	
	 *
	 * @param iEkiOrder [in]
	 *	�w�wOrder�x���w�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @param value [in]
	 *	�w�w�����x���w�肵�Ă��������B
	 * @return 
	 *	�Ή�����w�w�����x�I�u�W�F�N�g
	 */
	CentDedRessya& modifyCentDedEkiJikoku( int iEkiOrder , 
		const CentDedEkiJikoku& value ) ;
	
	/**
	 * @return
	 *	���̗�Ԃ̎n���w�́w�wOrder�x��Ԃ��܂��B
	 *	���ׂẮw�w�����x���w�^�s�Ȃ��x�̏ꍇ�́A-1 ��Ԃ��܂��B
	 *	���̏ꍇ�A���̗�Ԏ��̂��w�^�s�Ȃ��x�ƂȂ�܂��B
	 */
	int getSihatsuEki()const ;

	/**
	 *	���̗�Ԃ̎n���w��ݒ肵�܂��B
	 *	�w�wOrder�x���n���w�����������w�̂��ׂẮw�w�����x��
	 *	������ Ekiatsukai_None �ɕς��܂��B
	 * @param iEkiOrder [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wOrder�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�w�wOrder�x���s���ł��B
	 */
	int setSihatsuEki( int iEkiOrder ) ;
	
	/**
	 * @return
	 *	���̗�Ԃ̏I���w�́w�wOrder�x��Ԃ��܂��B
	 *	���ׂẮw�w�����x���w�^�s�Ȃ��x�̏ꍇ�́A-1 ��Ԃ��܂��B
	 *	���̏ꍇ�A���̗�Ԏ��̂��w�^�s�Ȃ��x�ƂȂ�܂��B
	 */
	int getSyuuchakuEki()const ;

	/**
	 *	���̗�Ԃ̏I���w��ݒ肵�܂��B
	 *	�w�wOrder�x���I���w�����傫���w�̂��ׂẮw�w�����x��
	 *	������ Ekiatsukai_None �ɕς��܂��B
	 * @param iEkiOrder [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wOrder�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�w�wOrder�x���s���ł��B
	 */
	int setSyuuchakuEki( int iEkiOrder ) ;
	///@}
	// ********************************
	///@name �w����Order�x�P�ʂ̑���
	// ********************************
	///@{
	
	/**
	 *	���̗�Ԃ́A�w����Order�x�ɑΉ����鎞�����擾���܂��B
	 *	
	 * @param iJikokuOrder [in]
	 *	�擾���鎞���́w����Order�x���w�肵�Ă��������B
	 * @return
	 *	�Ή����鎞����Ԃ��܂��B
	 *	�p�����[�^���s���ȏꍇ�́A Null��Ԃ̎�����Ԃ��܂��B
	 */
	CdDedJikoku getEkiJikoku( int iJikokuOrder )const  ;
	
	/**
	 *	���̗�Ԃ́A�w����Order�x�ɑΉ����鎞����ύX���܂��B
	 * @attention
	 *	���̊֐��́A�w��̉w�����ȍ~�̉w������
	 *	�J��グ�^�J�艺���͍s���܂���B
	 * @param aCdDedJikoku [in]
	 *	�������w�肵�Ă��������B
	 * @param iJikokuOrder [in]
	 *	�ύX���鎞���́w����Order�x���w�肵�Ă��������B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	- 	-1 ;	//	�p�����[�^���s��
	 *
	 */
	int setEkiJikoku( const CdDedJikoku& aCdDcdJikoku , int iJikokuOrder ) ;
	
	/**
	 *	���̗�Ԃ́A�w��̎����ȍ~�̎�����ύX���܂��B
	 *	�w�肵���w�����ȍ~�́A��wNull�x��Ԃ̂��ׂẲw�̎������A
	 *	�J��グ�^�J�艺���܂��B
	 *	
	 * @param iJikokuOrder [in]
	 *	�ύX���鎞���́w����Order�x���w�肵�Ă��������B
	 * @param aCdDedJikan [in]
	 *	�J��グ�E�J�艺�����s�����Ԃ��w�肵�Ă��������B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 *	- 	-1 ;	//	�p�����[�^���s��
	 *
	 */
	int modifyRessyaJikoku(  
		const CdDedJikan& aCdDedJikan , int iJikokuOrder ) ;
	
	/**
	 *	���̗�Ԃ́A�w��́w����Order�x�ȑO�ŁA
	 *	��wNull�x��Ԃ̎������A
	 *	��Ɍ������āi�w����Order�x0�̕��Ɍ������āj�������܂��B
	 *	
	 * @param iJikokuOrder [in]
	 *	�����̋N�_�ƂȂ�ύX���鎞�����w����Order�x�Ŏw�肵�Ă��������B
	 * @return
	 *	��Null��Ԃ̎��������������ꍇ�́A0 �ȏ�́w����Order�x���擾���܂��B
	 *	������Ȃ������ꍇ��A�p�����[�^���s���ȏꍇ�́A
	 *	-1 ��Ԃ��܂��B
	 */
	int findrevJikoku( int iJikokuOrder )const ;
	
	
	///@}
	
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 * @return
	 *	���̗�Ԃ��wNull��ԁx�Ȃ�^�ł��B
	 *
	 *	���ׂẮw�w�����x��
	 *	�w�^�s�Ȃ��x(Ekiatsukai_None ),
	 *	�̏ꍇ�A���̗�Ԃ́wNull��ԁx�ƂȂ�܂��B
	 */
	bool isNull()const ;
	/**
	 *	���̗�Ԃ��wNull��ԁx�Ƃ��܂��B
	 */
	void clear() ;
	
	
	
	///@}
};
#endif /*CentDedRessya_h*/
