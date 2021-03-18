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
//	CentDedRessyaCont.h
// $Id: CentDedRessyaCont.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CentDedRessyaCont_h
#define  CentDedRessyaCont_h

#include "Mu/CMuiCopied.h"

#include "CentDed.h"
#include "CentDedRessya.h"

// ****************************************************************
//	CentDedRessyaCont
// ****************************************************************
/**
 @brief
	�y�T�v�z
	�w��ԃR���e�i�x�N���X�B
	�����H���ɑ����铯�������́A0�ȏ㕡���́w��ԁx(CentDedRessya) 
	�I�u�W�F�N�g��ێ�����R���e�i�ł��B
	
	���̃N���X���̂́A Mui< CentDedRessya > �C���^�[�t�F�[�X��
	�T�|�[�g���܂��B���̃C���^�[�t�F�[�X�ɂ��A CentDedRessya �I�u�W�F�N�g��
	�ǉ��E�폜���邱�Ƃ��ł��܂��B

	�܂��A getMuPtr() ���\�b�h�ɂ��A
	Mu< CentDedRessya* > �C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
	���̃C���^�[�t�F�[�X�ɂ��A�R���e�i���� CentDedRessya �I�u�W�F�N�g��
	���ڃA�N�Z�X�i���\�b�h�ďo�j���s�����Ƃ��ł��܂��B

 @attention
	this �� get() ���\�b�h�́ACentDedRessya �I�u�W�F�N�g�̃R�s�[��Ԃ��܂��B
	get() ���\�b�h�ŕԂ��ꂽ�I�u�W�F�N�g�ɑ΂��āA
	CentDedRessya �I�u�W�F�N�g���X�V���郁�\�b�h���Ăяo���Ă��A
	�R���e�i���� CentDedRessya �I�u�W�F�N�g���X�V���邱�Ƃ͂ł��܂���B\n
	�R���e�i���� CentDedRessya �I�u�W�F�N�g�̃��\�b�h���Ăяo���ꍇ�́A
	getMuPtr() �� Mu<CentDedRessya*>* ���擾���Ă���A
	���̃C���^�[�t�F�[�X�o�R�� CentDedRessya* ���擾���A���̃|�C���^��
	���\�b�h���Ăяo���Ă��������B
	
	���̃R���e�i�� set() �E insert() �́A�w�肳�ꂽ CentDedRessya �I�u�W�F�N�g
	���R�s�[�R���X�g���N�^�ŃR�s�[������ŁA�R���e�i�ɕێ����܂��B
	set()�E insert() �Ŏw�肵���I�u�W�F�N�g�́A�֐��I����͔j�����Ă�
	���܂��܂���B

	���̃I�u�W�F�N�g���ێ����� CentDedRessya �́A
	�w��ԕ����x (CentDedRessya::m_eRessyahoukou) �E
	�w�w�̐��x ( CentDedRessya::m_CentDedEkiJikokuCont.size() )
	�����ׂē����ɂȂ�܂��B
	�܂��A�w��Ԏ��Index�x  (CentDedRessya::m_iRessyasyubetsuIndex ) �́A
	this �̑��� �w��Ԏ�ʐ��x ( m_iRessyasyubetsuCount )������
	��������܂��B
	set() , insert() �́A�w�肳�ꂽ CentDedRessya ��
	�w��ԕ����x (CentDedRessya::m_eRessyahoukou) �E
	�w�w�̐��x ( CentDedRessya::m_CentDedEkiJikokuCont.size() ) �E
	�w��Ԏ��Index�x  (CentDedRessya::m_iRessyasyubetsuIndex ) 
	���C�����������ŁA�R���e�i�ɕۑ����܂��B
 */
class CentDedRessyaCont : public CMuiCopied< CentDedRessya >
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	typedef CMuiCopied< CentDedRessya > super ;
	
public:
	// ********************************
	///@name �W��
	// ********************************
	///@{
	///@}
	// ********************************
	///@name ����
	// ********************************
	///@{
	
	/**
		���̃R���e�i�Ɋ܂܂���Ԃ́w�w�����x�̐��i�_�C���Ɋ܂܂��w�̐��j�B
	
		���̒l�́A��Ԃ������Ă��� CentDedRosen �I�u�W�F�N�g��
		 CentDedEki �̐��ɓ������Ȃ�܂��B
	
		���̒l�́A�R���e�i�Ɂw��ԁx ( CentDedRessya ) �I�u�W�F�N�g��ǉ�
		����ꍇ�ɕK�v�ɂȂ�܂��B
	 */
	int m_iEkiCount ;
	
	/**
	 @param eRessyahoukou [in]
		���̃R���e�i�Ɋi�[�����w��ԁx�̗�ԕ����B
		-	���� :	Ressyahoukou_Kudari 
		-	��� : 	Ressyahoukou_Nobori 
		�R���X�g���N�^�Ō��܂�܂��B
	
		���̒l�́A�R���e�i�Ɂw��ԁx ( CentDedRessya ) �I�u�W�F�N�g��ǉ�
		����ꍇ�ɕK�v�ɂȂ�܂��B
	 */
	ERessyahoukou m_eRessyahoukou ;
	
	/**
		���̃R���e�i�Ɋ܂܂���Ԃ́w��Ԏ�ʐ��x�B
	
		���̒l�́A��Ԃ������Ă��� CentDedRosen �I�u�W�F�N�g��
		CentDedRessyasyubetsu �̐��ɓ������Ȃ�܂��B
	
		���̒l�́A�R���e�i�Ɂw��ԁx ( CentDedRessya ) �I�u�W�F�N�g��ǉ�
		����ꍇ�ɕK�v�ɂȂ�܂��B
	 */
	int m_iRessyasyubetsuCount ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	 @param iEkiCount [in]]
		�w��ԃR���e�i�x�Ɋ܂܂��w�̐��B\n
	 @param eRessyahoukou [in]
		���̃R���e�i�Ɋi�[�����w��ԁx�̗�ԕ����B
		-	���� :	Ressyahoukou_Kudari 
		-	��� : 	Ressyahoukou_Nobori 
	 @param iRessyasyubetsuCount [in]
		���̃R���e�i�Ɋ܂܂���Ԃ́w��Ԏ�ʐ��x�B
	
		���̒l�́A��Ԃ������Ă��� CentDedRosen �I�u�W�F�N�g��
		CentDedRessyasyubetsu �̐��ɓ������Ȃ�܂��B
	
		���̒l�́A�R���e�i�Ɂw��ԁx ( CentDedRessya ) �I�u�W�F�N�g��ǉ�
		����ꍇ�ɕK�v�ɂȂ�܂��B
	 */
	CentDedRessyaCont( 
		int iEkiCount ,
		ERessyahoukou m_eRessyahoukou ,
		int iRessyasyubetsuCount 
	) ;


	CentDedRessyaCont( const CentDedRessyaCont& value );
	
	/**
		���̃N���X�ւ̑�����s���܂����A
		this �́w�w�x�̐� ( m_iEkiCount ) �͕ύX���܂���B
	
		this ����܂���w��ԁx( CentDedRessya )  �̃R�s�[�ɂ́A
		CentDedRessya& operator=( const CentDedRessya& value ) 
		���g���܂��B
	 */
	CentDedRessyaCont& operator=( const CentDedRessyaCont& value );

	virtual ~CentDedRessyaCont();

public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	///@}
public:
	// ********************************
	///@name Mui
	// ********************************
	///@{
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f�̃R�s�[��ǉ����܂��B
	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �ȉ��ł��B
	 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int insert( const CentDedRessya& element , int iIndex = INT_MAX ) 
	{
		if ( element.getCentDedEkiJikokuCount() == m_iEkiCount && 
			element.getRessyahoukou() ==  m_eRessyahoukou && 
			element.getRessyasyubetsuIndex() < m_iRessyasyubetsuCount )
		{
			return super::insert( element , iIndex ) ;
		}
		// --------------------------------
		CentDedRessya aCentDedRessya = CentDedRessya( m_iEkiCount , m_eRessyahoukou ) ;
		aCentDedRessya = element ;

		//	�}��������Ԃ̎��Index���K��ȏ�Ȃ�A�O�ɕύX
		if ( aCentDedRessya.getRessyasyubetsuIndex() >= m_iRessyasyubetsuCount ){
			aCentDedRessya.setRessyasyubetsuIndex( m_iRessyasyubetsuCount - 1 ) ;
		}
		return super::insert( aCentDedRessya , iIndex ) ;
	}
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f���㏑�����܂��B
	 @param element [in]
	 	�v�f���w�肵�Ă��������B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int set( const CentDedRessya& element , int iIndex ) 
	{
		if ( element.getCentDedEkiJikokuCount() == m_iEkiCount && 
			element.getRessyahoukou() ==  m_eRessyahoukou && 
			element.getRessyasyubetsuIndex() < m_iRessyasyubetsuCount )
		{
			return super::set( element , iIndex ) ;
		}
		// --------------------------------
		CentDedRessya aCentDedRessya = CentDedRessya( m_iEkiCount , m_eRessyahoukou ) ;
		aCentDedRessya = element ;

		//	�}��������Ԃ̎��Index���K��ȏ�Ȃ�A�O�ɕύX
		if ( aCentDedRessya.getRessyasyubetsuIndex() >= m_iRessyasyubetsuCount ){
			aCentDedRessya.setRessyasyubetsuIndex( m_iRessyasyubetsuCount - 1 ) ;
		}
		return super::set( aCentDedRessya , iIndex ) ;
	}
	///@}
	// ********************************
	///@name CentDedRessyaCont-����
	// ********************************
	///@{
	ERessyahoukou getRessyahoukou()const{	return m_eRessyahoukou ;};
	int getEkiCount()const{	return m_iEkiCount ;};
	int getRessyasyubetsuCount()const{	return m_iRessyasyubetsuCount ;};

	///@}
	// ********************************
	///@name CentDedRessyaCont-����
	// ********************************
	///@{

	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	��̗�Ԃ�ǉ����܂��B
	 @param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �ȉ��ł��B
	 	�O�́A�擪�Esize()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	 */
	virtual int insertBlank( int iIndex = INT_MAX ) ;
	
	/**
		�w�wOrder(�w������Index)�x���A�w�wIndex�x�ɕϊ����܂��B
	 @param iEkiOrder [in]
		�w�wOrder�x���w�肵�Ă��������B
	 @return 
		0�ȏ�́w�wIndex�x��Ԃ��܂��B
		�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	virtual int EkiIndexOfEkiOrder( int iEkiOrder )const ;
	
	/**
		�w�wIndex�x���w�wOrder(�w������Index)�x�ɕϊ����܂��B
	 @param iEkiIndex [in]
		�w�wIndex�x���w�肵�Ă��������B
	 @return 
		0�ȏ�́w�wOrder�x��Ԃ��܂��B
		�������s���ȏꍇ�́A -1 ��Ԃ��܂��B
	 */
	virtual int EkiOrderOfEkiIndex( int iEkiIndex )const ;

	/**
		pCentDedRessyaCont �Ɋi�[����Ă����Ԃ̂����A
		 iEkiOrder �̉w�Ǝ��̉w�̊Ԃ̉w�ԍŏ����v�b���̗�Ԃ�
		�������A���̏��v���Ԃ����߂܂��B
	 @param iEkiOrder [in]
		�ŏ����v�b�����v�Z����w�́A
		�w�wOrder�x���w�肵�Ă��������B
	 @param pidxRessya [out]
		���̊֐��͂����ɁA�w�ԍŏ����v�b���̗�Ԃ̗�ԃC���f�N�X��
		�������݂܂��B
		�w�ԍŏ����v�b���̗�Ԃ��݂���Ȃ��ꍇ�A���̊֐��͂��̕ϐ���
		-1 ���������݂܂��B
	 @return
		�w�ԍŏ����v�b����Ԃ��܂��B
		�w�ԍŏ����v�b���̗�Ԃ��݂���Ȃ��ꍇ�A���̊֐���
		����l�� 0 ��Ԃ��܂��B
		
		  �ׂ荇���`�w�Ƃa�w�̊Ԃ́w�w�ԍŏ����v�b���x�́A�u���w�ɒ�Ԃ���
		��Ԃ̂����A�`�w�̔������Ƃa�w�̒��������ł��Z�����́v�ƂȂ�܂��B
		  ���̂Ƃ��A�`�w�̒��������w�肳��Ă��Ĕ��������ȗ�����Ă���ꍇ�́A
		���������������Ƃ݂Ȃ��܂��B�܂��A�a�w�̒��������ȗ�����Ă��Ĕ�������
		�w�肳��Ă���ꍇ���A���������������Ƃ݂Ȃ��܂��B
		
		  ���w�ɒ�Ԃ����Ԃ��ЂƂ��Ȃ��ꍇ�́A�`�w�E�a�w��ʉ߂����Ԃ�
		�w�肳��Ă���ʉߎ��������ƂɁA�w�ԍŏ����v�b�������߂܂��B���̏ꍇ�A
		�����ΏۂƂȂ�̂́A�ȉ��̂��ׂĂ̗�Ԃł��B
		
			- �`�w��ʉ�(�ʉߎ����w�肠��)�E�a�w��ʉ�(�ʉߎ����w�肠��)
			- �`�w�ɒ��                  �E�a�w��ʉ�(�ʉߎ����w�肠��)
			- �`�w��ʉ�(�ʉߎ����w�肠��)�E�a�w�ɒ��
	 */
	virtual int findEkikanSaisyouSec( 
		int iEkiOrder , 
		int* pidxRessya )const ;

	/**
		�w��̗��Index ���H����ŉ^�s����Ă���Ō�̉w
		(getRunLastEkiOrder())�̉w������肠�ƂŁA
		iEkiOrder ���ŏ��̉^�s�w(getRunFirstEkiOrder())
		�Ƃ����Ԃ��������܂��B
		����́A[���ʉ�]�̑Ώۂ̌����ɑ������܂��B
	@param idxRessya [in]
		�����̐擪�ƂȂ�A���Index���w�肵�Ă��������B
	@param iEkiOrder [in]
		�n���w�̉wOrder���w�肵�Ă��������B
	@return
		�ΏۂƂȂ��Ԃ̗��Index ��Ԃ��܂��B
		������Ȃ��ꍇ�́A -1 ��Ԃ��܂��B


�@	  ���ʉ��̑ΏۂƂȂ�r���w�n����Ԃ́A�ȉ��̏����𖞂�������Ԃł��B

�@	  - �E�t�H�[�J�X�̂�����(�r���w�~�܂�̗��)�Ɠ�����Ԏ��
�@	  - �E�t�H�[�J�X�̂���w���ŏ��̉^�s��ԂƂȂ���
�@	  - �E[�n���w�̔������E�I����Ԃ̒������̗������L���ȏꍇ��] \n
		�n���w�̔��������A�I����Ԃ̒���������12���Ԉȓ�
�@	  - �E�����\�r���[��ŁA�t�H�[�J�X�̂����Ԃ̉E���ɂ�����

�@	  �ΏۂƂȂ��Ԃ���������ꍇ�́A���̒��ł����Ƃ������ɂ����Ԃ𒼒ʉ��̑ΏۂƂ��܂��B
		
	*/
	virtual int findTrainToDirect(
		int idxRessya , 
		int iEkiOrder  ) const ;  

	/**
		�w��̉w Order �̉w�������A
		�w�����`���E�n���E�I���ɍ��킹�ĕύX���܂��B

		�ύX���e�́A CentDedEkiJikoku::adjustByEkijikokukeisiki 
		�̐������Q�Ƃ��Ă��������B

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
	///@name CentDedRessyaCont-�w���E��Ԏ�ʐ��̕ύX
	// ********************************
	///@{
	/**
		���̃R���e�i�Ɋ܂܂�邷�ׂĂ�
		�w�_�C���x ( CentDedDia )�ɑ΂��A
		�w�w�x�I�u�W�F�N�g�̑����̕ύX��ʒm���܂��B

		�������e�́BCentDedRessya::onSetCentDedEki() �̐������Q�Ƃ��Ă��������B

	@see CentDedRessya::onSetCentDedEki() 
	@param iEkiOrder [in]
		�I�u�W�F�N�g��}������ʒu���w�wOrder�x�Ŏw�肵�Ă��������B
		�͈͂� 0 �ȏ� m_iEkiCount �ȉ��ł��B
	@return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 */
	int onSetCentDedEki( const Mu<CentDedEkiCont::CdDedEki>* pCentDedEkiCont , int iEkiOrder ) ;

	/**
		���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂĂ�
		�w��ԁx ( CentDedRessya )�ɑ΂��A
		�w�w�����x�I�u�W�F�N�g���A�w��̈ʒu�ɑ}�����܂��B
	 @param iEkiOrder [in]
		�I�u�W�F�N�g��}������ʒu���w�wOrder�x�Ŏw�肵�Ă��������B
		�͈͂� 0 �ȏ� m_iEkiCount �ȉ��ł��B
		INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�C���f�N�X���s���ł��B
	 */
	int insertCentDedEkiJikoku(	int iEkiOrder = INT_MAX ) ;
	
	/**
		���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂẮw��ԁx ( CentDedRessya )��
		�΂��A
		�w�w�����x�I�u�W�F�N�g���A�w��̈ʒu����폜���܂��B
	 @param iEkiOrder [in]
		�I�u�W�F�N�g��}������ʒu���w�wOrder�x�Ŏw�肵�Ă��������B
		�͈͂� 0 �ȏ� m_iEkiCount �����ł��B
		INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�C���f�N�X���s���ł��B
	 */
	int eraseCentDedEkiJikoku( int iEkiOrder = INT_MAX ) ;

	/**
		�w��Ԏ�ʁx�̒ǉ��ɔ����A
		���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂĂ�
		�w��ԁx ( CentDedRessya ) �́w��Ԏ��Index�x���C�����܂��B
	
		���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂĂ�
		�w��ԁx ( CentDedRessya ) �̂����A
		���� iRessyasyubetsuIndex �ȏ�� �w��Ԏ��Index�x������
		�w��ԁx ( CentDedRessya ) �́w��Ԏ��Index�x�� 1 ���Z���܂��B
	
		�܂��A������ this �� m_iRessyasyubetsuCount �� 1 ���Z���܂��B
	
	 @param iRessyasyubetsuIndex [in]
		��Ԏ�ʂ̒ǉ��ʒu���w�肵�Ă��������B
		�͈͂� 0 �ȏ� m_iRessyasyubetsuCount �ȉ��ł��B
		INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�C���f�N�X���s���ł��B
	 */
	int insertRessyasyubetsuIndex( int iRessyasyubetsuIndex = INT_MAX ) ;
	
	/**
		�w��Ԏ�ʁx�̍폜�ɔ����A
		���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂĂ�
		�w��ԁx ( CentDedRessya ) �́w��Ԏ��Index�x���C�����܂��B
	
		���́w��ԃR���e�i�x�Ɋ܂܂�邷�ׂĂ�
		�w��ԁx ( CentDedRessya ) �̂����A
		���� iRessyasyubetsuIndex ���傫�� �w��Ԏ��Index�x������
		�w��ԁx ( CentDedRessya ) �́w��Ԏ��Index�x�� 1 ���Z���܂��B
	
		�܂��A������ this �� m_iRessyasyubetsuCount �� 1 ���Z���܂��B
	
	 @param iRessyasyubetsuIndex [in]
		�폜�����Ԏ��Index���w�肵�Ă��������B
		�͈͂� 0 �ȏ� m_iRessyasyubetsuCount �����ł��B
		INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�C���f�N�X���s���ł��B
		-	-3 ;	//	�w��Ԏ�ʁx�� iRessyasyubtsuIndex �̗�Ԃ����݂��܂��B
	 */
	int eraseRessyasyubetsuIndex( int iRessyasyubetsuIndex  = INT_MAX ) ;

	/**
		���̃R���e�i�ɁA�w�肳�ꂽ�w��Ԏ�ʁx�̗�Ԃ����邩�ۂ��𒲂ׂ܂��B
	 @param iRessyasyubetsuIndex [in]
		�w��Ԏ��Index�x���w�肵�Ă��������B
		�͈͂́A 0 �ȏ� ��Ԏ�ʂ̐������ł��B
		INT_MAX �́A�����̗�Ԏ�ʂ��w�肵�����̂Ƃ݂Ȃ��܂��B
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
		int* piRessyaIndex ) ;
	///@}
};


#endif /*CentDedRessyaCont_h*/
