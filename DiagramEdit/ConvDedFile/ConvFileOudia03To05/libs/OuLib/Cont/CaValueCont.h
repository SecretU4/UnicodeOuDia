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
//	CaValueCont.h
// ****************************************************************
*/
/** @file */
#ifndef  CaValueCont_h
#define  CaValueCont_h

#include "./IfValueCont.h"
// ****************************************************************
//	CaValueCont
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 *   �A�_�v�^�N���X�ł��B�l��ێ�����R���e�i 
 *	"IfValueCont< ElementType >" �𑀍�ΏۂƂ��A�R���e�i����
 *	�v�f�ւ̃|�C���^�E�Q�Ƃ�Ԃ� "IfContGet" �C���^�[�t�F�[�X�ɕϊ����܂��B
 * 
 * (��  �|�C���^��ێ�����R���e�i�ɂ́A���̃A�_�v�^�͎g���܂���)
 * 
 *   ���̃A�_�v�^�N���X���g���ƁA�ȉ��̃C���^�[�t�F�[�X���擾����
 *	���Ƃ��ł��܂��B�Ή����郁�\�b�h���Ăяo���Ă��������B
 *
 * 	- "IfContGet< ElementType* >" �E�E�E getIfContGetPtr()
 * 	- "IfContGet< const ElementType* >" �E�E�E getIfContGetConstPtr() 
 * 	- "IfContGet< ElementType& >" �E�E�E getIfContGetRef()
 * 	- "IfContGet< const ElementType& >" �E�E�E getIfContGetConstRef() 
 * 
 * @param ElementType
 *	����ΏۃI�u�W�F�N�g���i�[���Ă���f�[�^�̌^���w�肵�Ă��������B
 *	����ΏۃI�u�W�F�N�g�́A "IfCont<ElementType*>" �C���^�[�t�F�[�X��
 *	�T�|�[�g���܂��B
 *	���̃f�[�^�^�́A�l�^�łȂ��Ă͂Ȃ�܂���i�|�C���^�E�Q�Ƃ͎g�p�ł��܂���j
 */
template < class ElementType > class CaValueCont 
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
	IfValueCont<ElementType>*	m_pAdaptee ;
///@}

// ********************************
///@name ���
// ********************************
///@{
 private:
	// ********************************
	//	"IfContGet< ElementType* >" �E�E�E getIfContGetPtr()
	// ********************************
	/**
	 * @brief
	 *	CaValueCont::getIfContGetPtr() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
	 *	���������N���X�ł��B
	 */
	class XIfContGetPtr : public IfContGet< ElementType* >
	{
	 public:
		virtual int	size()const{
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetPtr) ) ;
			return pOuter->m_pAdaptee->size() ; } ;
		virtual ElementType* get( int idx )const {
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetPtr) ) ;
			ElementType*	pRv = pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xIfContGetPtr ;
	friend class XIfContGetPtr ;
	// ********************************
	// 	"IfContGet< const ElementType* >" �E�E�E getIfContGetConstPtr() 
	// ********************************
	/**
	 * @brief
	 *	CaValueCont::getIfContGetConstPtr() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
	 *	���������N���X�ł��B
	 */
	class XIfContGetConstPtr : public IfContGet< const ElementType* >
	{
	 public:
		virtual int	size()const{
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetConstPtr) ) ;
			return pOuter->m_pAdaptee->size() ; } ;
		virtual const ElementType* get( int idx )const {
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetConstPtr) ) ;
			ElementType*	pRv = pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xIfContGetConstPtr ;
	friend class XIfContGetConstPtr ;

	// ********************************
	// 	"IfContGet< ElementType& >" �E�E�E getIfContGetRef()
	// ********************************
	/**
	 * @brief
	 *	CaValueCont::getIfContGetRef() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
	 *	���������N���X�ł��B
	 */
	class XIfContGetRef : public IfContGet< ElementType& >
	{
	 public:
		virtual int	size()const{
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetRef) ) ;
			return pOuter->m_pAdaptee->size() ; } ;
		virtual ElementType& get( int idx )const {
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetRef) ) ;
			ElementType&	pRv = *pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xIfContGetRef ;
	friend class XIfContGetRef ;
	// ********************************
	// 	"IfContGet< const ElementType& >" �E�E�E getIfContGetConstRef() 
	// ********************************
	/**
	 * @brief
	 *	CaValueCont::getIfContGetConstRef() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
	 *	���������N���X�ł��B
	 */
	class XIfContGetConstRef : public IfContGet< const ElementType& >
	{
	 public:
		virtual int	size()const{
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetConstRef) ) ;
			return pOuter->m_pAdaptee->size() ; } ;
		virtual const ElementType& get( int idx )const {
			CaValueCont* pOuter = (CaValueCont*)((char*)this - offsetof(CaValueCont,m_xIfContGetConstRef) ) ;
			ElementType&	pRv = *pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xIfContGetConstRef ;
	friend class XIfContGetConstRef ;

///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	CaValueCont( IfValueCont<ElementType>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ) {};
 private:
	CaValueCont( const CaValueCont<ElementType>& ){};
	CaValueCont& operator=( const CaValueCont<ElementType>& ){ return *this ;};

// ********************************
//	CaValueCont
// ********************************
 public:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	IfValueCont<ElementType>*	getAdaptee(){	return m_pAdaptee ;};
	const IfValueCont<ElementType>*	getAdaptee()const{	return m_pAdaptee ;};
	CaValueCont& setAdaptee( IfValueCont<ElementType>*	value )
	{
		m_pAdaptee = value ; 	return *this ;
	};
	///@}
	// ********************************
	///@name ���
	// ********************************
	///@{
	IfContGet< ElementType* >* getIfContGetPtr(){
		return &m_xIfContGetPtr ;};
	IfContGet< const ElementType* >*  getIfContGetConstPtr(){
		return &m_xIfContGetConstPtr ;};
	IfContGet< ElementType& >* getIfContGetRef(){
		return m_xIfContGetRef ;};
	IfContGet< const ElementType& >* getIfContGetConstRef(){
		return &m_xIfContGetConstRef ;};

	const IfContGet< ElementType* >* getIfContGetPtr()const {
		return &m_xIfContGetPtr ;};
	const IfContGet< const ElementType* >*  getIfContGetConstPtr()const {
		return &m_xIfContGetConstPtr ;};
	const IfContGet< ElementType& >* getIfContGetRef()const {
		return m_xIfContGetRef ;};
	const IfContGet< const ElementType& >* getIfContGetConstRef()const {
		return &m_xIfContGetConstRef ;};
	///@}
};

#endif /*CaValueCont_h*/
