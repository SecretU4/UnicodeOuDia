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
//	CaMup.h
// ****************************************************************
*/
/** @file */
#ifndef  CaMup_h
#define  CaMup_h

#include "./Mup.h"

namespace OuLib{

#ifndef NO_NSMU
namespace NsMu{
#endif//NO_NSMU

// ****************************************************************
//	CaMup
// ****************************************************************
/**
 @brief
   �A�_�v�^�N���X�ł��B�l��ێ�����R���e�i 
	"Mup< ElementType >" �𑀍�ΏۂƂ��A�R���e�i����
	�v�f�ւ̃|�C���^�E�Q�Ƃ�Ԃ� "Mu" �C���^�[�t�F�[�X�ɕϊ����܂��B
 
 (��  �|�C���^��ێ�����R���e�i�ɂ́A���̃A�_�v�^�͎g���܂���)
 
   ���̃A�_�v�^�N���X���g���ƁA�ȉ��̃C���^�[�t�F�[�X���擾����
	���Ƃ��ł��܂��B�Ή����郁�\�b�h���Ăяo���Ă��������B

 	- "Mu< ElementType* >" �E�E�E getMuPtr()
 	- "Mu< const ElementType* >" �E�E�E getMuConstPtr() 
 	- "Mu< ElementType& >" �E�E�E getMuConstRef()
 	- "Mu< const ElementType& >" �E�E�E getMuConstRef() 
 
 @param ElementType
	����ΏۃI�u�W�F�N�g���i�[���Ă���f�[�^�̌^���w�肵�Ă��������B
	����ΏۃI�u�W�F�N�g�́A "Mup<ElementType>" �C���^�[�t�F�[�X��
	�T�|�[�g���܂��B
	���̃f�[�^�^�́A�l�^��z�肵�Ă��܂�
	�i�|�C���^�E�Q�Ƃ��i�[����R���e�i�𑀍�Ώۂɂ���Ӗ��͂���܂���j�B
 */
template < class ElementType > class CaMup 
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		����ΏۃI�u�W�F�N�g�ƂȂ�A�R���e�i�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́Athis�Ƃ̊֘A���ۂ���Ă���Ԃ́A
		�������Ȃ��Ă͂Ȃ�܂���B
	 */
	Mup<ElementType>*	m_pAdaptee ;
	///@}

private:
	// ********************************
	///@name ���
	// ********************************
	///@{
	// ********************************
	//	"Mu< ElementType* >" �E�E�E getMuPtr()
	// ********************************
	/**
	 @brief
		CaMup::getMuPtr() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
		���������N���X�ł��B
	 */
	class XMuPtr : public Mu< ElementType* >
	{
	public:
		virtual int	size()const
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuPtr) ) ;
			return pOuter->m_pAdaptee->size() ; 
		} ;
		virtual ElementType* get( int idx )const 
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuPtr) ) ;
			ElementType*	pRv = pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xMuPtr ;
	friend class XMuPtr ;
	//*******************************
	// 	"Mu< const ElementType* >" �E�E�E getMuConstPtr() 
	//*******************************
	/**
	 @brief
		CaMup::getMuConstPtr() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
		���������N���X�ł��B
	 */
	class XMuConstPtr : public Mu< const ElementType* >
	{
	public:
		virtual int	size()const
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuConstPtr) ) ;
			return pOuter->m_pAdaptee->size() ; 
		} ;
		virtual const ElementType* get( int idx )const 
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuConstPtr) ) ;
			ElementType*	pRv = pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xMuConstPtr ;
	friend class XMuConstPtr ;

	// ********************************
	// 	"Mu< ElementType& >" �E�E�E getMuRef()
	// ********************************
	/**
	 @brief
		CaMup::getMuRef() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
		���������N���X�ł��B
	 */
	class XMuRef : public Mu< ElementType& >
	{
	 public:
		virtual int	size()const
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuRef) ) ;
			return pOuter->m_pAdaptee->size() ; 
		} ;
		virtual ElementType& get( int idx )const 
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuRef) ) ;
			ElementType&	pRv = *pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xMuRef ;
	friend class XMuRef ;
	// ********************************
	// 	"Mu< const ElementType& >" �E�E�E getMuConstRef() 
	// ********************************
	/**
	 @brief
		CaMup::getMuConstRef() ���\�b�h���Ԃ��C���^�[�t�F�[�X��
		���������N���X�ł��B
	 */
	class XMuConstRef : public Mu< const ElementType& >
	{
	 public:
		virtual int	size()const
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuConstRef) ) ;
			return pOuter->m_pAdaptee->size() ; 
		} ;
		virtual const ElementType& get( int idx )const 
		{
			CaMup* pOuter = (CaMup*)((char*)this - offsetof(CaMup,m_xMuConstRef) ) ;
			ElementType&	pRv = *pOuter->m_pAdaptee->getp( idx ) ;
			return ( pRv ) ;
		};
	}	m_xMuConstRef ;
	friend class XMuConstRef ;

	///@}
// ********************************
//	�R���X�g���N�^
// ********************************
public:
	CaMup() : 
		m_pAdaptee( NULL ) {};
	CaMup( Mup<ElementType>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ) {};
private:
	CaMup( const CaMup<ElementType>& ){};
	CaMup& operator=( const CaMup<ElementType>& ){ return *this ;};

public:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	Mup<ElementType>*	getAdaptee(){	return m_pAdaptee ;};
	const Mup<ElementType>*	getAdaptee()const{	return m_pAdaptee ;};
	CaMup& setAdaptee( Mup<ElementType>*	value )
	{	m_pAdaptee = value ; 	return *this ;	};
	///@}
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
	@return 
		ElementType �ɃA�N�Z�X���邽�߂� Mu�C���^�[�t�F�[�X�B
	*/
	Mu< ElementType* >* getMuPtr()
	{	return &m_xMuPtr ;};
	/**
	@return 
		ElementType �ɃA�N�Z�X���邽�߂� Mu�C���^�[�t�F�[�X�B
	*/
	const Mu< ElementType* >* getMuPtr()const 
	{	return &m_xMuPtr ;};
	/**
	@return 
		ElementType �ɃA�N�Z�X���邽�߂� Mu�C���^�[�t�F�[�X�B
	*/
	Mu< const ElementType* >*  getMuConstPtr()
	{	return &m_xMuConstPtr ;};
	/**
	@return 
		ElementType �ɃA�N�Z�X���邽�߂� Mu�C���^�[�t�F�[�X�B
	*/
	const Mu< const ElementType* >*  getMuConstPtr()const 
	{	return &m_xMuConstPtr ;};
	/**
	@return 
		ElementType �ɃA�N�Z�X���邽�߂� Mu�C���^�[�t�F�[�X�B
	*/
	Mu< ElementType& >* getMuRef()
	{	return m_xMuRef ;};
	/**
	@return 
		ElementType �ɃA�N�Z�X���邽�߂� Mu�C���^�[�t�F�[�X�B
	*/
	const Mu< ElementType& >* getMuRef()const 
	{	return m_xMuRef ;};
	/**
	@return 
		ElementType �ɃA�N�Z�X���邽�߂� Mu�C���^�[�t�F�[�X�B
	*/
	Mu< const ElementType& >* getMuConstRef()
	{	return &m_xMuConstRef ;};
	/**
	@return 
		ElementType �ɃA�N�Z�X���邽�߂� Mu�C���^�[�t�F�[�X�B
	*/
	const Mu< const ElementType& >* getMuConstRef()const 
	{	return &m_xMuConstRef ;};
	///@}
};

#ifndef NO_NSMU
} //namespace NsMu
#endif//NO_NSMU

} //namespace OuLib

#endif /*CaMup_h*/
