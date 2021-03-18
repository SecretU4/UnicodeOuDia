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
//	CentDedDiaCont.h
// ****************************************************************
*/
#ifndef  CentDedDiaCont_h
#define  CentDedDiaCont_h
/** @file */

#include "Cont/CaContFilter.h"
#include "CentDedDia.h"

class CentDedEkiCont ;

// ****************************************************************
//	CentDedDiaCont
// ****************************************************************
/**
 * @brief
 *	CentDedDia �I�u�W�F�N�g�̃R���e�i�N���X�ł��B
 *	
 *	���̃N���X���̂́A IfCont< CentDedDia > �C���^�[�t�F�[�X��
 *	�T�|�[�g���܂��B���̃C���^�[�t�F�[�X�ɂ��A CentDedDia �I�u�W�F�N�g��
 *	�ǉ��E�폜���邱�Ƃ��ł��܂��B
 *
 *	�܂��A getIfContGet() ���\�b�h�ɂ��A
 *	IfCont< CentDedDia* > �C���^�[�t�F�[�X���擾���邱�Ƃ��ł��܂��B
 *	���̃C���^�[�t�F�[�X�ɂ��A�R���e�i���� CentDedDia �I�u�W�F�N�g��
 *	���ڃA�N�Z�X�i���\�b�h�ďo�j���s�����Ƃ��ł��܂��B
 *
 * @attention
 *	this �� get() ���\�b�h�́A�_�C���I�u�W�F�N�g�̃R�s�[��Ԃ��܂��B
 *	get() ���\�b�h�ŕԂ��ꂽ�I�u�W�F�N�g�ɑ΂��āA
 *	CentDedDia �I�u�W�F�N�g���X�V���郁�\�b�h���Ăяo���Ă��A
 *	�R���e�i���̃_�C���I�u�W�F�N�g���X�V���邱�Ƃ͂ł��܂���B\n
 *	�R���e�i���̃_�C���I�u�W�F�N�g�̃��\�b�h���Ăяo���ꍇ�́A
 *	getIfContGet() �� IfContGet<CentDedDia*>* ���擾���Ă���A
 *	���̃C���^�[�t�F�[�X�o�R�� CentDedDia* ���擾���A���̃|�C���^��
 *	���\�b�h���Ăяo���Ă��������B
 *	
 *	���̃R���e�i�� set() �E insert() �́A�w�肳�ꂽ CentDedDia �I�u�W�F�N�g
 *	���R�s�[�R���X�g���N�^�ŃR�s�[������ŁA�R���e�i�ɕێ����܂��B
 *	set()�E insert() �Ŏw�肵���I�u�W�F�N�g�́A�֐��I����͔j�����Ă�
 *	���܂��܂���B
 *
 *	���̃I�u�W�F�N�g���ێ����� CentDedDia �́A�w�w�̐��x�����ׂ�
 *	�����łȂ��Ă͂Ȃ�܂���B
 *	
 * @attention
 *	 CentDedDia::m_strName �����́A����q�ƂȂ�܂��B
 *	�R���e�i���ɓ��� CentDedDia::m_strName �����I�u�W�F�N�g��
 *	�����i�[���邱�Ƃ͂ł��܂���B
 */
class CentDedDiaCont : public CaContFilter< CentDedDia , CentDedDia* >
{
// ********************************
//	�C���i�[�^�C�v
// ********************************
public:
	typedef CaContFilter< CentDedDia , CentDedDia* >	super ;
// ********************************
///@name ����
// ********************************
///@{
private:
	/**
	 *	���̃R���e�i�Ɋ܂܂���Ԃ́w�w�����x�̐��i�_�C���Ɋ܂܂��w�̐��j�B
	 *
	 *	���̒l�́A��Ԃ������Ă��� CentDedRosen �I�u�W�F�N�g��
	 *	 CentDedEki �̐��ɓ������Ȃ�܂��B
	 *
	 *	���̒l�́A�R���e�i�ɗv�f (  CentDedDia ) �I�u�W�F�N�g��ǉ�
	 *	����ꍇ�ɕK�v�ɂȂ�܂��B
	 */
	int m_iEkiCount ;
	
	/**
	 *	���̃R���e�i�Ɋ܂܂���Ԃ́w��Ԏ�ʁx�̐��B
	 *
	 *	���̒l�́A��Ԃ������Ă��� CentDedRosen �I�u�W�F�N�g��
	 *	 CentDedRessyasyubetsu �̐��ɓ������Ȃ�܂��B
	 *
	 *	���̒l�́A�R���e�i�ɗv�f ( CentDedDia ) �I�u�W�F�N�g��ǉ�
	 *	����ꍇ�ɕK�v�ɂȂ�܂��B
	 */
	int m_iRessyasyubetsuCount ;
	
///@}

// --------------------------------
///@name CaContFilter-�I�[�o���C�h�\�ȉ��z�֐�
// --------------------------------
///@{
 protected:
	/**
	 *	  this �́A����Ώۂ̃R���e�i m_pAdaptee �ɑ΂��ėv�f��ǉ�
	 *	����Ƃ��ɁA���̊֐����Ăяo���āA  ElementType1 �̒l value ���A
	 *	 ElementType2 �ɕϊ����܂��B
	 *
	 *	onSet() �Ăяo���ƁA onErase() �Ăяo���͑΂ɂȂ��Ă��܂��B
	 *	 onSet() �ł���l��Ԃ����ꍇ�A���̗v�f�� m_pAdaptee ����
	 *	��菜�����Ƃ��ɁA�K�� onSet() �ŕԂ����l�������Ƃ���
	 *	 onErase() ���Ăяo����܂��B
	 *	
	 *	@param value [in] (const ElementType1&)
	 *	  �ϊ�����ׂ��l���w�肵�Ă��������B
	 *	
	 *	@param piResult [out]
	 *	  ���̊֐��́A�l value �̕ϊ��ɐ��������Ƃ��͂��̒l�� 0 �ȏ�A
	 *	���s�����Ƃ��͕��̐��ɂ��܂��B
	 *	\n�֐��I����ɂ��̒l�����̐��ł���ꍇ�A this �͗v�f��
	 *	�R���e�i�Ɋi�[���܂���B���̏ꍇ�Aset() �E insert() ��
	 *	���s�ƂȂ�A *piResult �� set() �E insert() �̖߂�l�ƂȂ�܂��B
	 *	
	 *	@return (ElementType2)
	 *	  value ��ϊ��������ʂ�Ԃ��܂��B�A���A�ϊ��Ɏ��s���A
	 *	 *piResult �����̐��ł���ꍇ�́A���̖߂�l�ɂ͈Ӗ�������܂���B
	 *
	 *	
	 *	<H4>
	 *	�y�I�[�o���C�h�z
	 *	</H4>
	 *	value �̃R�s�[�� new �Ő������āA���̃|�C���^��Ԃ��܂��B
	 *	�A���A�R�s�[��̃C���X�^���X�̉w���́A this ��  m_iEkiCount ��
	 *	���킹�܂��B
	 */
	virtual adaptee_value_type onSet( const value_type& value , int* piResult ) ;
	
	/**
	 *	  get() ���\�b�h�́A����Ώۂ̃R���e�i m_pAdaptee ����擾��������
	 *	���̊֐����Ăяo���āA  ElementType2 �̒l value ���A
	 *	 ElementType1 �ɕϊ����܂��B
	 *	
	 *	@param value [in] (const ElementType2&)
	 *	  �ϊ�����ׂ��l���w�肵�Ă��������B
	 *	
	 *	@return (ElementType1)
	 *	  value ��ϊ��������ʂ�Ԃ��܂��B
	 *	
	 *	<H4>
	 *	�y�I�[�o���C�h�z
	 *	</H4>
	 *	  ElementType2 �̒l���A ElementType1 �ɕϊ����鏈��������
	 *	���Ă��������B�ϊ����ʂ̒l�͖߂�l�Ƃ��Ă��������B
	 */
	virtual value_type onGet( const adaptee_value_type& value )const ;
	
	/**
	 *	  this �́A����Ώۂ̃R���e�i m_pAdaptee ����v�f����菜�����O�ɁA
	 *	���̊֐����Ăяo���܂��B
	 *
	 *
	 *	onSet() �Ăяo���ƁA onErase() �Ăяo���͑΂ɂȂ��Ă��܂��B
	 *	 onSet() �ł���l��Ԃ����ꍇ�A���̗v�f�� m_pAdaptee ����
	 *	��菜�����Ƃ��ɁA�K�� onSet() �ŕԂ����l�������Ƃ���
	 *	 onErase() ���Ăяo����܂��B
	 *	
	 *	@param value [in] (const ElementType2&)
	 *	  ����Ώۂ̃R���e�i m_pAdaptee �����菜���v�f���w�肵�Ă��������B
	 *
	 *	<H4>
	 *	�y�I�[�o���C�h�z
	 *	</H4>
	 *	  �v�f�� delete ���܂��B
	 */
	virtual void onErase( const adaptee_value_type& value ) ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param iEkiCount [in]]
	 *	�w�̐��B\n
	 * @param iRessyasyubetsuCount [in]
	 *	���̃R���e�i�Ɋ܂܂���Ԃ́w��Ԏ�ʁx�̐��B
	 *	���̒l�́A��Ԃ������Ă��� CentDedRosen �I�u�W�F�N�g��
	 *	 CentDedRessyasyubetsu �̐��ɓ������Ȃ�܂��B
	 */
	CentDedDiaCont( int iEkiCount , int iRessyasyubetsuCount ) ;

	CentDedDiaCont( const CentDedDiaCont& value );
	
	/**
	 *	���̃N���X�ւ̑�����s���܂����A
	 *	this �́w�w�x�̐� ( m_iEkiCount ) �͕ύX���܂���B
	 *
	 *	this ����܂���w��ԁx( CentDedRessya )  �̃R�s�[�ɂ́A
	 *	CentDedRessya& operator=( const CentDedRessya& value ) 
	 *	���g���܂��B
	 */
	CentDedDiaCont& operator=( const CentDedDiaCont& value );

	virtual ~CentDedDiaCont();
// ********************************
///@name IfCont
// ********************************
///@{
 public:
	/**
	 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 * 	�v�f���㏑�����܂��B
	 * <H4>
	 * �y�I�[�o���C�h�z
	 * </H4>
	 *	element �̃R�s�[�� new �Ő������Ă���A�����
	 *	����ΏۃR���e�i m_pAdaptee �Ɋi�[���܂��B
	 *	\n m_pAdaptee �ɁA�����̃_�C���I�u�W�F�N�g�����݂���ꍇ�́A
	 *	���\�b�h�͎��s���܂��B
	 *
	 * @param element [in]
	 * 	�v�f���w�肵�Ă��������B
	 * @param iIndex [in]
	 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 * 	�͈͂͂O�ȏ� size() �����ł��B
	 *	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 * 	0�ȏ�͐����A���̐��̓G���[�ł�
	 *	-	-1 ;	//	iIndex ���s���ł��B
	 *	-	-2 ;	//	element �ɂ̓_�C�������w�肳��Ă��܂���B
	 *	-	-3 ;	//	���łɓ����̃_�C�������݂��܂��B
	 */
	virtual int set( const CentDedDia& element , int iIndex ) ;

	/**
	 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 * 	�v�f��ǉ����܂��B
	 * <H4>
	 * �y�I�[�o���C�h�z
	 * </H4>
	 *	element �̃R�s�[�� new �Ő������Ă���A�����
	 *	����ΏۃR���e�i m_pAdaptee �Ɋi�[���܂��B
	 *	\n m_pAdaptee �ɁA�����̃_�C���I�u�W�F�N�g�����݂���ꍇ�́A
	 *	���\�b�h�͎��s���܂��B
	 *
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
	 *	-	-1 ;	//	�C���f�N�X���s���ł��B
	 *	-	-2 ;	//	element �ɂ̓_�C�������w�肳��Ă��܂���B
	 *	-	-3 ;	//	���łɓ����̃_�C�������݂��܂��B
	 */
	virtual int insert( const CentDedDia& element , int iIndex = INT_MAX ) ;
///@}
	
// ********************************
//	CentDedDiaCont
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	virtual int getEkiCount()const ;
	virtual int getRessyasyubetsuCount()const ;
	///@}
	// ********************************
	///@name CentDedDiaCont-����
	// ********************************
	///@{
	/**
	 * @return 
	 *	�R���e�i���̃_�C���I�u�W�F�N�g CentDedDia �ւ̃|�C���^��
	 *	�A�N�Z�X���邽�߂� IfContGet<CentDedDia*>* ��Ԃ��܂��B
	 */
	IfContGet<CentDedDia*>* getIfContGet(){	return getAdaptee() ;	};
	const IfContGet<CentDedDia*>* getIfContGet()const{	return getAdaptee() ;	};

	/**
	 *	�w��̃_�C����������
	 *	�w�_�C���x ( CentDedDia ) �I�u�W�F�N�g�́A
	 *	�C���f�N�X�𒲂ׂ܂��B
	 * @param strName [in]
	 *	�w�_�C�����x���w�肵�Ă��������B
	 * @return 
	 *	���������� 0 �ȏ�̃C���f�N�X�A�G���[�Ȃ畉�̐��ł��B
	 *	-	-1 ;	//	�I�u�W�F�N�g���݂���܂���B
	 */
	int findCentDedDiaByName( const string& strName )const ;
	///@}
	// ********************************
	///@name CentDedDiaCont-���� �w�̑���
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
	 *	���̃R���e�i�Ɋ܂܂�邷�ׂĂ�
	 *	�w�_�C���x ( CentDedDia )�ɑ΂��A
	 *	�w�w�����x�I�u�W�F�N�g���A�w��̈ʒu�ɑ}�����܂��B
	 * @param iEkiOrder [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wIndex�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� m_iEkiCount �ȉ��ł��B
	 *	INT_MAX ���w�肷��ƁA�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 *	���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	 */
	int insertCentDedEkiJikoku(	int iEkiIndex = INT_MAX ) ;
	
	/**
	 *	���́w�_�C���R���e�i�x�Ɋ܂܂�邷�ׂĂ�
	 *	�w�_�C���x ( CentDedDia )�ɑ΂��A
	 *	�w�w�����x�I�u�W�F�N�g���A�w��̈ʒu����폜���܂��B
	 * @param iEkiOrder [in]
	 *	�I�u�W�F�N�g��}������ʒu���w�wIndex�x�Ŏw�肵�Ă��������B
	 *	�͈͂� 0 �ȏ� m_iEkiCount �����ł��B
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
	 * @param piDiaIndex [out]
	 *	���̊֐��͂��̕ϐ��ɁA�w��Ԏ�ʁx�̗�Ԃ���������
	 *	�_�C���̃C���f�N�X���������݂܂��B
	 *	�s�v�Ȃ� NULL �ł����܂��܂���B
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
		int* piDiaIndex ,
		ERessyahoukou* peRessyahoukou ,
		int* piRessyaIndex ) ;

	///@}

	
};






#endif /*CentDedDiaCont_h*/
