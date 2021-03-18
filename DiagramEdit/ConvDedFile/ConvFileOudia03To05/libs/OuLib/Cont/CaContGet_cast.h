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
//	CaContGet_cast.h
// ****************************************************************
*/
/** @file */
#ifndef  CaContGet_cast_h
#define  CaContGet_cast_h
#include "./IfContGet.h"
// ****************************************************************
//	CaContGet_cast.h
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 *   �A�_�v�^�N���X�ł��B
 *	"IfContGet< ElementType2 >" �^�̃R���e�i�I�u�W�F�N�g�𑀍�ΏۂƂ��A
 *	����Ώۂ� IfContGet< ElementType2 >" �C���^�[�t�F�[�X���A
 *	IfContGet< ElementType1 >" �C���^�[�t�F�[�X�ɕϊ����܂��B
 *
 *	���̃N���X�� get() ���\�b�h�́A����Ώ� ( m_pAdaptee ) �Ɋi�[����Ă���
 *	ElementType2 �^�̗v�f���A static_cast<ElementType1> �ŕϊ����Ă���
 *	�Ԃ��܂��B
 * 
 *   ���̃N���X�̗p�r�́A��Ɉȉ��̂悤�ȏꍇ�ł�
 * �i CBase �́A�R���e�i�Ɋi�[����N���X�̗�ł��j�B
 * 
 * ��  �I�u�W�F�N�g�̃|�C���^���i�[����Ă��� �A
 *  IfContGet< CBase* > �C���^�[�t�F�[�X���T�|�[�g�����R���e�i��
 * ���̃I�u�W�F�N�g�ɑ��삳����ꍇ�A���̃I�u�W�F�N�g�ɂ�
 *  "IfContGet< const CBase* >" ��n�������i���̃I�u�W�F�N�g����́A
 *  CBase ��ύX���������Ȃ��j�B
 * 
@code
	CaCont_vector< vector< CBase* > >	aCaCont_vector_ptr ;
	CaContGet_cast< const CBase* , CBase* > aCaContGet_cast( &aCaCont_vector_ptr ) ;
	//aCaContGet_cast = IfContGet< const CBase* > ���T�|�[�g���Ă��܂��B
	//	���̃C���^�[�t�F�[�X�ɂ��A
	//	�R���e�i���̃I�u�W�F�N�g��ύX�s�\�Ȍ`�ŎQ�Ƃ��邱�Ƃ��ł��܂��B
@endcode
 * 
 *   ��  ���̗�ł́A���ʂ̃|�C���^���g���Ă��܂����A�������Ƃ� Ou ��
 * �s�����Ƃ��\�ł�
 *
 * ��  int ���i�[����Ă���i IfContGet< int > �C���^�[�t�F�[�X��
 *	�T�|�[�g�����j�R���e�i��
 * ���̃I�u�W�F�N�g�ɎQ�Ƃ�����ꍇ�A�Q�Ƃ��鑤�̃I�u�W�F�N�g��
 *  "IfContGet< long > " ��n�������B
 * 
 * 
 * @param ElementType1
 *	�L���X�g��̗v�f�̌^���w�肵�Ă��������B
 *	���̃N���X�́A "IfContGet< ElementType1 >" �C���^�[�t�F�[�X��
 *	�T�|�[�g���܂��B
 * @param ElementType2
 *	����ΏۃI�u�W�F�N�g m_pAdaptee ���i�[���Ă���v�f�̌^��
 *	�w�肵�Ă��������B
 */
template < class ElementType1 , class ElementType2 > class CaContGet_cast : 
	public IfContGet< ElementType1 > 
{
// ********************************
///@name �֘A
// ********************************
///@{
 private:
	/**
	 *	����ΏۃI�u�W�F�N�g�ƂȂ�A�R���e�i�ł��B
	 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
	 *	���̃I�u�W�F�N�g�́Athis�Ƃ̊֘A���ۂ���Ă���Ԃ́A
	 *	�������Ȃ��Ă͂Ȃ�܂���B
	 */
	IfContGet<ElementType2>*	m_pAdaptee ;
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	CaContGet_cast( IfContGet<ElementType2>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ){};
	
	
// ********************************
//	IfContGet
// ********************************
 public:
	/**
	 * @return
	 * 	�R���e�i�Ɋi�[����Ă���f�[�^�̌���Ԃ��܂��B
	 */
	virtual int	size()const{	return m_pAdaptee->size() ; } ;
	
	// --------------------------------

	/**
	 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���
	 * 	�v�f��Ԃ��܂��B
	 * @param idx [in]
	 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 * 	�͈͂͂O�ȏ� size() �����ł��B
	 *	INT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 * 	�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
	 */
	virtual ElementType1 get( int idx )const {
		ElementType1 pRv = static_cast<ElementType1>( m_pAdaptee->get( idx ) ) ;
		return ( pRv ) ;
	};
	
// ********************************
//	CaContGet_cast
// ********************************
 public:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	IfContGet<ElementType2>*	getAdaptee(){	return m_pAdaptee ;};
	const IfContGet<ElementType2>*	getAdaptee()const{	return m_pAdaptee ;};
	CaContGet_cast<ElementType1,ElementType2>& setAdaptee( IfContGet<ElementType2>*	value )
	{
		m_pAdaptee = value ; 	return *this ;
	};
	///@}
};

#endif /*CaContGet_cast_h*/


