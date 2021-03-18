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


#include "CentDed.h"
#include "CentDedEkiJikokuCont.h"
#include "CentDedEkiJikoku.h"
#include "CdDedJikan.h"
#include "CentDedEkiCont.h"
#include "CdDedJikokuOrder.h"

namespace entDed{
	using namespace OuLib::NsMu ;
	using namespace std ;

// ****************************************************************
//	CentDedRessya
// ****************************************************************
/**
@brief
   DiagramEdit �́A�H����ŉ^�s�����w��ԁx�P�{��\���܂��B
	
���̃N���X�̃C���X�^���X�́A�ʏ�́w�H���x�i CentDedRosen �j��
��܂���܂��B

���ۂɂ́A

  - �w�H���x (CentDedRosen) ���w�_�C���x ( CentDedDia ) ��
�O�ȏ㕡�����
  - �e�w�_�C���x ( CentDedDia ) ���w��ԁx (CentDedRessya ) ��
�O�ȏ㕡�����

�Ƃ����֌W�ɂȂ��Ă��܂��B

���̃N���X�́A�w�H���x�i CentDedRosen �j�ɑ��݂���
�w�w�x ( CentDedEki )�̐������A�w�w�����x(CentDedEkiJikoku�j
�I�u�W�F�N�g��ێ����܂��B�w�H���x ( CentDedRosen )�ɕ�܂����
���ׂẮw��ԁx( CentDedRessya )����܂���
�w�w�����x ( CentDedEkiJikoku ) �I�u�W�F�N�g�̐��́A
�w�H���x ( CentDedRosen )�́w�w�x ( CentDedEki ) �̐��Ɠ����łȂ��Ă�
�Ȃ�܂���B

  ���̓������Ƃ邽�߁A�w��ԁx ( CentDedRessya ) �ɑ΂���
�w�w�����x ( CentDedEkiJikoku ) �I�u�W�F�N�g�̒ǉ��E�폜�̑���͐���
����Ă��܂��B

  �܂��A���̃N���X���ێ�����A�w��Ԏ��Index�x�����́A
�w�H���x( CentDedRosen )���ێ�����w��Ԏ�ʁx ( CentDedRessyasyubetsu )
�I�u�W�F�N�g�ɑΉ����܂��B

���̃I�u�W�F�N�g�́A�L���ȗ�ԃf�[�^�������Ȃ��wNull��ԁx��
�Ƃ邱�Ƃ��ł��܂��B
�wNull��ԁx�̗�Ԃ́A�w�����\�r���[�x�ł͋�s�Ƃ��ĕ\������܂��B

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
�w�wIndex�x�ɂȂ��Ă��܂��B

  ����Ƃ͑ΏƓI�ɁA�w��ԁx(�N���X�ł́A�����Ƃ���
�w�w�����x ( CentDedEkiJikoku ) �I�u�W�F�N�g���w�肷��̂ɂ�
�w�wOrder�x���g���܂��B�w�w�����x ( CentDedEkiJikoku ) ��ێ�����R���e�i
  CentDedEkiJikokuCont �̃C���f�N�X���A�w�wOrder�x �ƂȂ�܂��B
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


����
 -------------------------------- 
����Ԃ��H���̈ꕔ�ł���ꍇ�A��Ԏ��Index�́ACentDedRessyasyubetsuCont(��Ԏ�ʃR���e�i)�ɑΉ����Ă��Ȃ��Ă͂Ȃ�Ȃ�



����̃G���[�����E�C��
 -------------------------------- 
����Ԏ�ʂ̒ǉ�(OnInsertRessyasyubetsu):�@��Ԃ̗�Ԏ�ʃC���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B

����Ԏ�ʂ̍폜(OnEraseRessyasyubetsu):�@��Ԃ̗�Ԏ�ʃC���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B
�@��Ԃ̗�Ԏ�ʃC���f�N�X���폜�Ώۂ̏ꍇ�A�C���f�N�X��0�ɂ���

��setRessyasyubetsuIndex: ��Ԃ��H��(CentDedRosen)�̈ꕔ�ł���ꍇ�ŁA��Ԏ��Index����Ԏ�ʃR���e�i CentDedRessyasyubetsuCont �ɑΉ����Ă��Ȃ��ꍇ�̓G���[�B

��setParent:adjust�����s����

��operator= : this ����ԃR���e�i�̈ꕔ�ł���ꍇ�A�w��ԕ����x ( m_eRessyahoukou )�͕ύX���܂���B

 ����ɍ����悤�ɑ������C��(adjust)
 -------------------------------- 
����Ԃ��e�I�u�W�F�N�g CentDedRessyaCont �̈ꕔ�ł���ꍇ�A��ԕ����́A�e�I�u�W�F�N�g�ł����ԃR���e�i�̗�ԕ����Ɠ���Ƃ��܂��B

����Ԏ��Index��CentDedRessyasyubetsuCont(��Ԏ�ʃR���e�i)�͈̔͊O�ł���ꍇ�́A��Ԏ��Index��0�Ƃ��܂��B

��CentDedEkiJikokuCont(�w�����R���e�i)�ɁAadjust()���Ϗ����܂��B

	
*/
class CentDedRessya : public CChildBase
{
	typedef CChildBase	super ;
public:
	// ****************************************************************
	//	�C���i�[�^�C�v
	// ****************************************************************
	/**
	  ���̃N���X�ɕ�܂����w�w�����x(CentDedEkiJikokuTrack) �I�u�W�F�N�g
	�̃R���e�i�ł��B
	*/
	class CXEkiJikokuCont : public CentDedEkiJikokuCont
	{
	public:
		// ********************************
		///@name CentDedEkiJikokuCont-�֘A
		// ********************************
		///@{
		/**
		@return
			���̃R���e�i�� CentDedEkiJikoku �ɕ�܂���Ă���ꍇ�́A
			CentDedEkiJikoku �̃A�h���X�B
			�����łȂ��Ȃ�NULL�B
		*/
		 virtual CentDedRessya* getRessya() ;
		/**
		@return
			���̃R���e�i�� CentDedEkiJikoku �ɕ�܂���Ă���ꍇ�́A
			CentDedEkiJikoku �̃A�h���X�B
			�����łȂ��Ȃ�NULL�B
		*/
		virtual const CentDedRessya* getRessya()const ;
		///@}
	};
	/**
		setRessyasyubetsuIndex �ŃX���[������O�B
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
		���̗�Ԃ��wNull��ԁx�Ȃ�^�A
		�L���ȗ�ԑ�����ێ����Ă���̂Ȃ�U�ł��B
		
		���̑������^�̏ꍇ�A���� 
		-	m_iRessyasyubetsuIndex,
		-	m_strRessyabangou ;
		-	m_strRessyamei ;
		-	m_strGousuu ;
		-	m_strBikou ;
	
		����сA
			m_CentDedEkiJikokuCont �Ɋi�[����Ă��� 
		CentDedEkiJikoku �́A�Ӗ��������܂���B
		
		�K��l�� true �ł��B
		set...() ���\�b�h�ŁAm_eRessyahoukou �ȊO��
		�����ꂩ�̑�����ݒ肵���Ƃ��ɂ́A
		�����I�ɋU�ɕς��܂��B
		clear() �ŁA�^�ƂȂ�܂��B
	 */
	bool m_bIsNull ;

	/**
		���̗�Ԃ̗�ԕ����������܂��B
		
		�K��l�� Ressyahoukou_Kudari �ł��B
	
		�R���X�g���N�^�Ō��܂�܂��B
	 */
	ERessyahoukou	m_eRessyahoukou ;

	/**
		���̗�Ԃ́w��Ԏ�ʁx���A
		�w��Ԏ��Index�x�ŕێ����܂��B
		
		�K��l�� 0 �ł��B
	*/
	int	m_iRessyasyubetsuIndex ;
	
	/**
		���̗�Ԃ́w��Ԕԍ��x�B
		
		�K��l�͋󕶎���ł��B
	 */
	std::string m_strRessyabangou ;
	
	/**
		���̗�Ԃ́w��Ԗ��x�B
		
		�K��l�͋󕶎���ł��B
	 */
	std::string m_strRessyamei ;
	
	/**
		���̗�Ԃ́w�����x�B
		
		�K��l�͋󕶎���ł��B
	 */
	std::string m_strGousuu ;
	
	/**
		���̗�Ԃ́w���l�x�B
		
		�K��l�͋󕶎���ł��B
	 */
	std::string m_strBikou ;
	
	///@}
 private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		���̗�Ԃ̊e�w�̎����B
		�v�f���́A�w�w�x( CentDedEki ) �̐��ɓ������Ȃ�܂��B
		�Y�����́w�wOrder�x�ł��B
	
		������Ԃł́A�v�f���� 0 �ƂȂ�܂��B
	
		���ׂẮw�w�����x��
		�w�^�s�Ȃ��x(Ekiatsukai_None ),
		�̏ꍇ�A���̗�Ԃ́wNull��ԁx�ƂȂ�܂��B
	 */
	CXEkiJikokuCont	m_CentDedEkiJikokuCont ;

	///@}

	

 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
		���̗�Ԃ�NULL��Ԃɏ��������܂��B
	 @param iEkiCount [in]
		���̗�Ԃ����s����H���́w�w�x�̐����w�肵�Ă��������B
		���̃R���X�g���N�^�ł́A m_CentDedEkiJikokuCont �̗v�f�����A
		���̈����ŏ��������܂��B
		�i�[����� CentDedEkiJikoku �́A 
		CentDedEkiJikoku::m_eEkiatsukai	�� Ekiatsukai_None �ƂȂ�܂��B
	 @param eRessyahoukou [in]
		���̗�Ԃ̗�ԕ����������܂��B
	 */
	CentDedRessya( 
		int iEkiCount , 
		ERessyahoukou	eRessyahoukou ) ;

public:
	/**
		���̃N���X�ւ̑�����s���܂����A
		this �́w��ԕ����x ( m_eRessyahoukou ) �E
		�w�w�����x (CentDedEkiJikoku ) �̐��͕ύX���܂���B
	
		this �� m_CentDedEkiJikokuCont �̐��� value �� m_CentDedEkiJikokuCount
		��菭�Ȃ��ꍇ�́A�s������ this �� m_CentDedEkiJikokuCount �v�f��
		�w�^�s�Ȃ��x�ƂȂ�܂��B
	
		this �� m_CentDedEkiJikokuCont �̐��� value �� m_CentDedEkiJikokuCount
		��葽���ꍇ�́A�ߏ蕪�� value �� m_CentDedEkiJikokuCount �v�f��
		�̂Ă܂��B
	 */
	CentDedRessya& operator=( const CentDedRessya& value );
public:
	// ********************************
	///@name CParentBase-����
	// ********************************
	///@{
	/**
	��setParent:adjust�����s����
	*/
	virtual void setParent( CParentBase* pParent );
	///@}

 public:
	// ********************************
	///@name CentDedRessya-����
	// ********************************
	///@{
	/** 
	@see m_bIsNull
	 @return
		���̗�Ԃ��wNull��ԁx�Ȃ�^�ł��B
	 */
	bool isNull()const ;

	/** @see m_bIsNull */
	CentDedRessya& setIsNull( bool value );

	///@see m_eRessyahoukou
	ERessyahoukou	getRessyahoukou()const ;
	///@see m_iRessyasyubetsuIndex
	int	getRessyasyubetsuIndex()const ;

	/**
	@see m_iRessyasyubetsuIndex


	�@��setRessyasyubetsuIndex: ��Ԃ��H��(CentDedRosen)�̈ꕔ�ł���ꍇ�ŁA
	��Ԏ��Index����Ԏ�ʃR���e�i CentDedRessyasyubetsuCont �ɑ�
	�����Ă��Ȃ��ꍇ�̓G���[�B

	@exception LException 
		��Ԃ��H��(CentDedRosen)�̈ꕔ�ł���ꍇ�ŁA
	��Ԏ��Index����Ԏ�ʃR���e�i CentDedRessyasyubetsuCont �ɑ�
	�����Ă��Ȃ�
	*/
	CentDedRessya& setRessyasyubetsuIndex( int value ) ;

	///@see m_strRessyabangou
	std::string getRessyabangou()const{
		return m_strRessyabangou ;};
	///@see m_strRessyabangou
	CentDedRessya& setRessyabangou( const std::string& value ){
		m_bIsNull = false ;
		m_strRessyabangou = value ; return *this ; } ;
	///@see m_strRessyamei
	std::string getRessyamei()const{
		return m_strRessyamei ;};
	///@see m_strRessyamei
	CentDedRessya& setRessyamei( const std::string& value ){
		m_bIsNull = false ;
		 m_strRessyamei = value ; return *this ; } ;
	///@see m_strGousuu
	std::string getGousuu()const{
		return m_strGousuu ;};
	///@see m_strGousuu
	CentDedRessya& setGousuu( const std::string& value ){
		m_bIsNull = false ;
		 m_strGousuu = value ; return *this ; } ;
	///@see m_strBikou
	std::string getBikou()const{
		return m_strBikou ;};
	///@see m_strBikou
	CentDedRessya& setBikou( const std::string& value ){
		m_bIsNull = false ;
		 m_strBikou = value ; return *this ; } ;
	///@}
	
	// ********************************
	///@name ���-CentDedEkiJikoku
	// ********************************
	///@{


	/** @see m_CentDedEkiJikokuCont */
	CentDedEkiJikokuCont* getCentDedEkiJikokuCont() 
	{	return &m_CentDedEkiJikokuCont ;}
	/** @see m_CentDedEkiJikokuCont */
	const CentDedEkiJikokuCont*	getCentDedEkiJikokuCont()const 
	{	return &m_CentDedEkiJikokuCont ;}

	
	/**
	 @return
		�w�w�����x �̐���Ԃ��܂��B
	 */
	int getCentDedEkiJikokuCount()const ;
	
	/**
		�w�wOrder�x�ɑΉ�����A�w�w�����x�I�u�W�F�N�g���擾����
		���Ƃ��ł��܂��B
	 @param iEkiOrder [in]
		�w�wOrder�x���w�肵�Ă��������B
		�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
		INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return 
		�Ή�����w�w�����x�I�u�W�F�N�g
	 */
	CentDedEkiJikoku getCentDedEkiJikoku( int iEkiOrder )const ;

	/**
		�w�wOrder�x�ɑΉ�����A�w�w�����x�I�u�W�F�N�g��ݒ肷��
		���Ƃ��ł��܂��B
		  this ��NULL��Ԃ̏ꍇ�A���̃��\�b�h���Ăяo����
		NULL��ԑ����͉�������܂��B
	 @param iEkiOrder [in]
		�w�wOrder�x���w�肵�Ă��������B
		�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
		INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @param value [in]
		�w�w�����x���w�肵�Ă��������B
	 @return 
		�Ή�����w�w�����x�I�u�W�F�N�g
	 */
	CentDedRessya& setCentDedEkiJikoku( 
		int iEkiOrder , 
		const CentDedEkiJikoku& value ) ;
	///@}
	// ********************************
	///@name �w�wOrder�x�P�ʂ̑���
	// ********************************
	///@{
	/**
		�w�wOrder(�w������Index)�x���A�w�wIndex�x�ɕϊ����܂��B
	 @param iEkiOrder [in]
		�w�wOrder�x���w�肵�Ă��������B
	 @return 
		0�ȏ�́w�wIndex�x��Ԃ��܂��B
		�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	int EkiIndexOfEkiOrder( int iEkiOrder )const  ;
	
	/**
		�w�wIndex�x���w�wOrder(�w������Index)�x�ɕϊ����܂��B
	 @param iEkiIndex [in]
		�w�wIndex�x���w�肵�Ă��������B
	 @return 
		0�ȏ�́w�wOrder�x��Ԃ��܂��B
		�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	int EkiOrderOfEkiIndex( int iEkiIndex )const  ;
	
	/**
		�w�wOrder�x�ɑΉ�����A�w�w�����x�I�u�W�F�N�g���A�ύX����
		���Ƃ��ł��܂��B
	
		���̂Ƃ��A�w�������x�E�w�������x���ύX���ꂽ��A
		�Ȍ�̉w���������ׂČJ�艺���܂��B
	
		  this ��NULL��Ԃ̏ꍇ�A���̃��\�b�h���Ăяo����
		NULL��ԑ����͉�������܂��B

		�i��j
	
		  ����܂ł�(this��)�w�������x�� 10:00 �ŁA
		�V����(value ��)�w�������x�� 10:03 �̏ꍇ�́A
		���́w�wOrder�x�́w�������x�ƁA
		�����肠�Ƃ́w�wOrder�x�́w�������x�w�������x�����ׂāA
		�R���J�艺���܂��B
		
		  ����܂ł�(this��)�w�������x�� IsNull �ŁA
		�V����(value ��)�w�������x�� 10:03 �̏ꍇ�́A
		���́w�wOrder�x�́w�������x������ 10:03 �ɍX�V���܂��B
		���́w�wOrder�x�́w�������x�ƁA
		�����肠�Ƃ́w�wOrder�x�́w�������x�E�w�������x�ɂ͉e����
		�^���܂���B
	
		  ����܂ł�(this��)�w�������x�� 10:00 �ŁA
		�V����(value ��)�w�������x�� IsNull �̏ꍇ�́A
		���́w�wOrder�x�́w�������x������ IsNull �ɍX�V���܂��B
		���́w�wOrder�x�́w�������x�ƁA
		�����肠�Ƃ́w�wOrder�x�́w�������x�E�w�������x�ɂ͉e����
		�^���܂���B
	
		  �w�������x�Ɋւ��Ă��A�ύX���ꂽ�ꍇ�́A���̍��ɏ]����
		�����肠�Ƃ́w�wOrder�x�́w�������x�E�w�������x�̌J��グ/�J�艺����
		�s���܂��B
	
	@param pCentDedEkiCont [in]
		�w�R���e�i���w�肵�Ă��������B
	 @param iEkiOrder [in]
		�w�wOrder�x���w�肵�Ă��������B
		�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
		INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @param value [in]
		�w�w�����x���w�肵�Ă��������B
	 @return 
		�Ή�����w�w�����x�I�u�W�F�N�g
	 */
	CentDedRessya& modifyCentDedEkiJikoku( 
		int iEkiOrder , 
		const CentDedEkiJikoku& value ) ;
	
	/**
	 @return
		���̗�Ԃ̎n���w�́w�wOrder�x��Ԃ��܂��B
		���ׂẮw�w�����x���w�^�s�Ȃ��x�̏ꍇ�́A-1 ��Ԃ��܂��B
		���̏ꍇ�A���̗�Ԏ��̂��w�^�s�Ȃ��x�ƂȂ�܂��B
	 */
	int getSihatsuEki()const ;

	/**
		���̗�Ԃ̎n���w��ݒ肵�܂��B
		�w�wOrder�x���n���w�����������w�̂��ׂẮw�w�����x��
		������ Ekiatsukai_None �ɕς��܂��B
	 @param iEkiOrder [in]
		�n���w���w�wOrder�x�Ŏw�肵�Ă��������B
		�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�w�wOrder�x���s���ł��B
	 */
	int setSihatsuEki( int iEkiOrder ) ;
	
	/**
	 @return
		���̗�Ԃ̏I���w�́w�wOrder�x��Ԃ��܂��B
		���ׂẮw�w�����x���w�^�s�Ȃ��x�̏ꍇ�́A-1 ��Ԃ��܂��B
		���̏ꍇ�A���̗�Ԏ��̂��w�^�s�Ȃ��x�ƂȂ�܂��B
	 */
	int getSyuuchakuEki()const ;

	/**
		���̗�Ԃ̏I���w��ݒ肵�܂��B
		�w�wOrder�x���I���w�����傫���w�̂��ׂẮw�w�����x��
		������ Ekiatsukai_None �ɕς��܂��B
	 @param iEkiOrder [in]
		�I���w���w�wOrder�x�Ŏw�肵�Ă��������B
		�͈͂� 0 �ȏ� getCentEkiJikokuCount() �����ł��B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�w�wOrder�x���s���ł��B
	 */
	int setSyuuchakuEki( int iEkiOrder ) ;

	/**
		��Ԃ��w��� �w�wOrder�x�ƁA���́w�wOrder�x�̊Ԃ�
		�^�s���Ă��邩�ۂ��𒲂ׂ܂��B

		�u�w��� �w�wOrder�x�ƁA���́w�wOrder�x�̊Ԃ�
		�^�s���Ă���v�́A
		�w��� �w�wOrder�x�ƁA���́w�wOrder�x�̗�����
		�w��ԁx�܂��́w�ʉ߁x�̏ꍇ���A����ɊY�����܂��B
		�_�C���O�����r���[�ł́A���̗�Ԃ̂��̉w�Ԃɂ͗�Ԑ���
		�`�悳��܂��B

	@param iEkiOrder [in]
		�ΏۂƂȂ�w�Ԃ̋N�_���́w�wOrder�x���w�肵�Ă��������B
		�͈͂́A0�ȏ�A(�w�̐�-1)�����ł��B
	@return
		��Ԃ� iEkiOrder �Ǝ��̉w�̊Ԃ��^�s���Ă���Ȃ� true �ł��B
		�����łȂ��ꍇ�́A false �ł��B
		�������͈͊O�̏ꍇ���Afalse �ł��B
	@attention
		�ǂ��炩�̉w�E�܂��͗����̉w���w�o�R�Ȃ��x�̏ꍇ�́A
		�u�w�̊Ԃ��^�s���Ă���v�Ƃ݂͂Ȃ��܂���B
		���̏ꍇ�A���̃��\�b�h�̖߂�l�͋U�ƂȂ�܂��B
	*/
	bool isRunBetweenNextEki( int iEkiOrder )const ;

	/**
	@return
		���̗�Ԃ��H����ŉ^�s����Ă����Ԃ́A�ŏ��́w�wOrder�x��Ԃ��܂��B
		���ׂĂ̋�Ԃ��^�s���Ă��Ȃ��ꍇ�́A-1 ��Ԃ��܂��B
		�u�^�s����Ă����ԁv�ɂ��ẮAisRunBetweenNextEki() ��
		�Q�Ƃ��Ă��������B

		getSihatsuEki() �Ǝ����ړI�̊֐��ł��B
		�������A�n���w���w�o�R�Ȃ��x�̏ꍇ�́A���̊֐��͂��̉w��
		�w�^�s����Ă���x�Ƃ݂͂Ȃ��܂���B
	 */
	int getRunFirstEkiOrder()const ;
	
	/**
	@return
		���̗�Ԃ��H����ŉ^�s����Ă���A�Ō�́w�wOrder�x��Ԃ��܂��B
		���ׂĂ̋�Ԃ��^�s���Ă��Ȃ��ꍇ�́A-1 ��Ԃ��܂��B
		�u�^�s����Ă����ԁv�ɂ��ẮAisRunBetweenNextEki() ��
		�Q�Ƃ��Ă��������B

		getSyuuchakuEki() �Ǝ����ړI�̊֐��ł��B
		�������A�I���w���w�o�R�Ȃ��x�̏ꍇ�́A���̊֐��͂��̉w��
		�w�^�s����Ă���x�Ƃ݂͂Ȃ��܂���B
	 */
	int getRunLastEkiOrder()const ;
	
	/**
		�w��̉w Order �̉w�������A
		�w�����`���E�n���E�I���ɍ��킹�ĕύX���܂��B

		�ύX���e�́A CentDedEkiJikoku::adjustByEkijikokukeisiki 
		�̐������Q�Ƃ��Ă��������B

		this ��NULL��Ԃ̏ꍇ�A���̃��\�b�h�͉������܂���B

	@see CentDedEkiJikoku::adjustByEkijikokukeisiki 

	@param iEkiOrder [in]
		�wOrder���w�肵�Ă��������B
	@param bChakujikokuHyouji [in]
		�w�����`���B
		�������\������B
	@param bHatsujikokuHyouji [in]
		�w�����`���B
		�������\������B
	*/
	void adjustByEkijikokukeisiki(
		int iEkiOrder ,
		bool bChakujikokuHyouji , bool bHatsujikokuHyouji ) ;
	

	///@}
	// ********************************
	///@name �w����Order�x�P�ʂ̑���
	//*******************************
	///@{
	/**
	    CdDedJikokuOrder ���A���̉w�����ɐi�߂܂��B
	@param aJikokuOrder [in]
		�i�߂�Ώۂ́A	CdDedJikokuOrder ���w�肵�Ă��������B
	@return 
		- aJikokuOrder ���������̏ꍇ�́A�����wOrder�̔�����
		- aJikokuOrder ���������̏ꍇ�́A���̉wOrder�̒�����
		- aJikokuOrder �� EkiOrder>=this.size() (�Ō�̉wOrder�̎�) �Ȃ�A@n
			aJikokuOrder �����̂܂ܕԂ��܂��B
		- aJikokuOrder ��NULL��� �Ȃ�AaJikokuOrder �����̂܂ܕԂ��܂��B
	@attention
		���̊֐��́A�w�����`��(�������E��������\�����邩�ۂ�)�̑������󂯂܂���
	*/
	CdDedJikokuOrder incJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder )const ;

	/**
	    CdDedJikokuOrder ���A�O�̉w�����Ɉړ����܂��B
	@param aJikokuOrder [in]
		�ړ��Ώۂ́A	CdDedJikokuOrder ���w�肵�Ă��������B
	@return 
		- aJikokuOrder ���������̏ꍇ�́A�����wOrder�̒�����
		- aJikokuOrder ���������̏ꍇ�́A���̉wOrder�̔�����
		- aJikokuOrder �� EkiOrder>=this.size() (�Ō�̉wOrder�̎�) �Ȃ�A@n
			�Ō�̉wOrder�̔�����
		- aJikokuOrder �� EkiOrder=0 �Ȃ�ANULL���
		- aJikokuOrder ��NULL��� �Ȃ�AaJikokuOrder �����̂܂ܕԂ��܂��B
	@attention
		���̊֐��́A�w�����`��(�������E��������\�����邩�ۂ�)�̑������󂯂܂���
	*/
	CdDedJikokuOrder decJikokuOrder( 
		const CdDedJikokuOrder& aJikokuOrder )const ;

	
	/**
		���̗�Ԃ́A�w����Order�x�ɑΉ����鎞�����擾���܂��B
		
	 @param aJikokuOrder [in]
		�擾���鎞���́w����Order�x���w�肵�Ă��������B
	 @return
		�Ή����鎞����Ԃ��܂��B
		�p�����[�^���s���ȏꍇ�́A Null��Ԃ̎�����Ԃ��܂��B

	*/
	CdDedJikoku getEkiJikoku( CdDedJikokuOrder aJikokuOrder )const  ;
	
	/**
		���̗�Ԃ́A�w����Order�x�ɑΉ����鎞����ύX���܂��B
	 @attention
		���̊֐��́A�w��̉w�����ȍ~�̉w������
		�J��グ�^�J�艺���͍s���܂���B
	 @param aCdDedJikoku [in]
		�������w�肵�Ă��������B
	 @param aJikokuOrder [in]
		�ύX���鎞���́w����Order�x���w�肵�Ă��������B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		- 	-1 ;	//	�p�����[�^���s��
	 */
	int setEkiJikoku( const CdDedJikoku& aCdDcdJikoku , CdDedJikokuOrder aJikokuOrder ) ;
	
	/**
		���̗�Ԃ́A�w��̎����ȍ~�̎�����ύX���܂��B
		�w�肵���w�����ȍ~�́A��wNull�x��Ԃ̂��ׂẲw�̎������A
		�J��グ�^�J�艺���܂��B
		
	@param pCentDedEkiCont [in]
		�w�R���e�i���w�肵�Ă��������B
	@param aCdDedJikan [in]
		�J��グ�E�J�艺�����s�����Ԃ��w�肵�Ă��������B
	@param iJikokuOrder [in]
		�ύX���鎞���́w����Order�x���w�肵�Ă��������B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		- 	-1 ;	//	�p�����[�^���s��
	*/
	int modifyRessyaJikoku(  
		const CdDedJikan& aCdDedJikan , 
		const CdDedJikokuOrder& aJikokuOrder) ;
	
	/**
		���̗�Ԃ́A�w��́w����Order�x�ȑO�ŁA
		��wNull�x��Ԃ̎������A
		��Ɍ������āi�w����Order�x0�̕��Ɍ������āj�������܂��B
		
	@param pCentDedEkiCont [in]
		�w�R���e�i���w�肵�Ă��������B
	 @param aJikokuOrder [in]
		�����̋N�_�ƂȂ�ύX���鎞�����w����Order�x�Ŏw�肵�Ă��������B
	 @return
		��Null��Ԃ̎��������������ꍇ�́A0 �ȏ�́w����Order�x���擾���܂��B
		������Ȃ������ꍇ��A�p�����[�^���s���ȏꍇ�́A
		NULL��Ԃ̃I�u�W�F�N�g��Ԃ��܂��B
	 */
	CdDedJikokuOrder findrevJikoku( 
		const CdDedJikokuOrder& aJikokuOrder )const ;

	///@}
	
	// ********************************
	///@name CentDedRessya-����
	// ********************************
	///@{
	/**
		���̗�Ԃ��wNull��ԁx�Ƃ��܂��B
	 */
	void clear() ;

	/**
		���̗�Ԃ̉w�������A���̗�Ԃ̉w�����ɏ㏑�����܂��B
	@param aCentDedRessyaSrc [in]
		���̊֐��́A���̗�Ԃ̉w�������Athis�̉w�����ɏ㏑�����܂��B
		aCentDedRessyaSrc �̉w�����w�^�s�Ȃ��x�̉w�̎����́A
		this �̉w�����ɂ͏㏑�����܂���B
		�܂��A�������E��������NULL�̏ꍇ�́A
		���̉w������ this �ɏ㏑�����܂���B
	*/
	void pasteEkiJikoku( const CentDedRessya& aCentDedRessyaSrc ) ;

	/**
		���̗�ԂƑ��̗�Ԃ𒼒ʉ����܂��B
	@param aRessyaSihatsu [in]
		�n����Ԃ̃C���f�N�X���w�肵�Ă��������B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	���̗�Ԃɂ͉w�������w�肳��Ă��܂���B
		-	-2 ;	//	�n����Ԃɂ͉w�������w�肳��Ă��܂���B
		-	-3 ;	//	aRessyaSihatsu �Ƃ̒��ʉ��͂ł��܂���B
			//aRessyaSihatsu �̎n���w�́A	this �̏I���w�Ɠ������A����ȍ~�łȂ��Ă͂Ȃ�܂���B
	@attention
		aRessyaSihatsu �̎n���w�́A
		this �̏I���w�Ɠ������A����ȍ~�łȂ��Ă�
		�Ȃ�܂���B
		this�̏I���w<aRessyaSihatsu �̎n���w�Ȃ�A
		���̊Ԃ̉w�̉w����[�o�R�Ȃ�]�Ƃ��܂��B

		�n���w�̎���(���ʉ���������)�́A�ȉ��̂悤�ɂȂ�܂��B

		- �w���F�ς��܂���B
		- �������F
		  - this��Ԃɒ��������w�肳��Ă����ꍇ�F���̒�����
		  - this��Ԃɒ��������Ȃ��A���������w�肳��Ă����ꍇ�F�r���w�~�܂��Ԃ̔�����
		  - this��Ԃɒ����������������w�肳��Ă��Ȃ��ꍇ�F�������͂Ȃ�
		- ������
		  - �n����Ԃɔ��������w�肳��Ă����ꍇ�F���̔������𒼒ʉ�������Ԃ̔������Ƃ��܂��B
		  - �n����Ԃɔ��������Ȃ��A���������w�肳��Ă����ꍇ�F�r���w�n����Ԃ̒��������A�V������Ԃ̔������Ƃ��܂��B
		  - �n����Ԃɒ����������������w�肳��Ă��Ȃ��ꍇ�F�������͂Ȃ�

		�n���w�̗�ԏ��(��Ԕԍ��E��Ԗ��E�����E���l)�͈ȉ��̂悤�ɂȂ�܂��B
		
		- this��Ԃ��󕶎���A�n����Ԃ���񂠂�̏ꍇ�A�n����Ԃ̏����󂯌p���܂��B
		- this��Ԃ���񂠂�A�n����Ԃ��󕶎���̏ꍇ�Athis��Ԃ̏����󂯌p���܂��B
		- this��Ԃ��n����Ԃ���񂠂�̏ꍇ�Athis��Ԃ̏����󂯌p���܂��B

	*/
	virtual int direct( 
		const CentDedRessya& aRessyaSihatsu ) ;

	/**
		���̗�Ԃ��w��̉w�ŕ��f�����A�Q�̗�Ԃ��쐬���܂��B

	@param iEkiOrder[in]
		��������w�̉wOrder���w�肵�Ă��������B
	@param pCentDedRessyaSyuuchaku [out]
		���̊֐��͂��̗�ԃI�u�W�F�N�g�ɁA�����������w�~�܂��Ԃ̗�Ԃ̏���
		�㏑�����܂��B
		���̃I�u�W�F�N�g�� ��ԕ����E�w���́A���炩����
		this �Ɠ����ɂ���K�v������܂��B
	@param 	pCentDedRessyaSihatsu [out]
		���̊֐��͂��̗�ԃI�u�W�F�N�g�ɁA�����������w�n���̗�Ԃ̏���
		�㏑�����܂��B
		���̃I�u�W�F�N�g�� ��ԕ����E�w���́A���炩����
		this �Ɠ����ɂ���K�v������܂��B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�w��̉wOrder�ł́A���f�͂ł��܂���

	*/
	virtual int undirect(
		int iEkiOrder , 
		CentDedRessya* pCentDedRessyaSyuuchaku ,
		CentDedRessya* pCentDedRessyaSihatsu )const ;

	/**
		this �̑���������ɔ����Ă���ꍇ�A����ɍ����悤�ɁA������
		�C�����܂��B

		����Ԃ��e�I�u�W�F�N�g CentDedRessyaCont �̈ꕔ�ł���ꍇ�A
		��ԕ����́A�e�I�u�W�F�N�g�ł����ԃR���e�i�̗�ԕ����Ɠ���Ƃ��܂��B

		����Ԏ��Index��CentDedRessyasyubetsuCont(��Ԏ�ʃR���e�i)��
		�͈͊O�ł���ꍇ�́A��Ԏ��Index��0�Ƃ��܂��B

		��CentDedEkiJikokuCont(�w�����R���e�i)�ɁAadjust()���Ϗ����܂��B


	*/
	void adjust() ;
	///@}
public:
	// ********************************
	///@name CentDedRosen-�q�I�u�W�F�N�g�̑����̒ʒm
	// ********************************
	///@{
	/**
		m_CentDedEkiCont �� CentDedEki ���ǉ����ꂽ����A
		m_CentDedEkiCont ����Ăяo����܂��B
	@param iEkiOrder
		�ǉ����ꂽ CentDedEki �̉wOrder(�w�C���f�N�X�ł͂���܂���)�B
	*/
	virtual void onEkiInsert( int iEkiOrder )
	{	m_CentDedEkiJikokuCont.onEkiInsert( iEkiOrder ) ;}

	/**
		m_CentDedEkiCont ���� CentDedEki ���폜���ꂽ����A
		m_CentDedEkiCont ����Ăяo����܂��B
	@param iEkiOrder
		�폜���ꂽ CentDedEki �̉wOrder(�w�C���f�N�X�ł͂���܂���)�B
	*/
	virtual void onEkiErase( int iEkiOrder  )
	{	m_CentDedEkiJikokuCont.onEkiErase( iEkiOrder ) ;}

	/**
		CentDedEkiTrackCont �� CentDedEkiTrack ���ǉ����ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiOrder
		CentDedEkiTrackCont ���ǉ����ꂽ CentDedEki �̉wOrder(�w�C���f�N�X�ł͂���܂���)�B
	@param iEkiTrackIndex
		�ǉ����ꂽ CentDedEkiTrack �̃C���f�N�X�B
	*/
	virtual void onEkiTrackInsert( int iEkiOrder , int iEkiTrackIndex ) 
	{	m_CentDedEkiJikokuCont.onEkiTrackInsert( iEkiOrder , iEkiTrackIndex ) ;}

	/**
		CentDedEkiTrackCont ���� CentDedEkiTrack ���폜���ꂽ����A
		CentDedEkiTrackCont ����Ăяo����܂��B
	@param iEkiOrder
		CentDedEkiTrackCont ���폜���ꂽ CentDedEki �̉wOrder(�w�C���f�N�X�ł͂���܂���)�B
	@param iEkiTrackIndex
		�폜���ꂽ CentDedEkiTrack �̐擪�̃C���f�N�X�B
	*/
	virtual void onEkiTrackErase( int iEkiOrder , int iEkiTrackIndex )
	{	m_CentDedEkiJikokuCont.onEkiTrackErase( iEkiOrder , iEkiTrackIndex ) ;}

	/**
		CentDedRessyasyubetsuCont �� CentDedRessyasyubetsu ���ǉ����ꂽ����A
		CentDedRessyasyubetsuCont ����Ăяo����܂��B

	����Ԏ�ʂ̒ǉ�(OnInsertRessyasyubetsu):�@��Ԃ̗�Ԏ�ʃC���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B

	@param iRessyasyubetsuIndex
		�ǉ����ꂽ CentDedRessyasyubetsu  �̃C���f�N�X�B
	*/
	virtual void onRessyasyubetsuInsert( int iRessyasyubetsuIndex ); 

	/**
		CentDedRessyasyubetsuCont ���� CentDedRessyasyubetsu ���폜���ꂽ����A
		CentDedRessyasyubetsuCont ����Ăяo����܂��B

		����Ԏ�ʂ̍폜(OnEraseRessyasyubetsu):�@��Ԃ̗�Ԏ�ʃC���f�N�X�́A�R���e�i�ւ̒ǉ��ɍ��킹�ăV�t�g������B
�@		  ��Ԃ̗�Ԏ�ʃC���f�N�X���폜�Ώۂ̏ꍇ�A�C���f�N�X��0�ɂ���
		
	@param iRessyasyubetsuIndex
		�폜���ꂽ CentDedRessyasyubetsu  �̃C���f�N�X�B
	*/
	virtual void onRessyasyubetsuErase( int iRessyasyubetsuIndex ); 


	///@}
};

} //namespace entDed

#endif /*CentDedRessya_h*/
