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
/** @file */
//$Id: CNodeContainer.h 10 2012-08-26 09:48:47Z okm $
#pragma once
#include <deque>
#include "Cont\IfCont.h"
#include "str\OuPropertiesText\CNode.h"
#include "str\OuPropertiesText\CPropertyString.h"
#include "str\OuPropertiesText\CInNameIndexContainer.h"
#include "str\OuPropertiesText\IfNodeContainerConst.h"

/**
@brief
  OuPropertiesText �������N���X�Q���W�񂵂Ă��܂��B

*/
namespace OuPropertiesText{


// ****************************************************************
//	CNodeContainer
// ****************************************************************
/**
@brief
	Node �I�u�W�F�N�g��ێ�����R���e�i�ł��B

	�R���e�i�� Ou<CNode> ���i�[���邷�ׂĂ�public���\�b�h
	(set()�Einsert() �Ȃ�)�́A
	�����œn���ꂽ CNode �� clone ���i�[���܂��B
	�R���e�i���� Ou<CNode> ���擾���邷�ׂẴ��\�b�h�́A
	�R���e�i���� CNode �ւ̎Q�Ƃ�Ԃ��܂��B
*/
class CNodeContainer : public IfCont< Ou<CNode> >
{
public:
	typedef Ou<CNode>	ElementType ;
	typedef std::deque< Ou<CNode> >	ElementTypeStlCont ;
private:
	// ----------------------------------------------------------------
	//	CNodeContainer::CaConst
	// ----------------------------------------------------------------
	/**
		CNodeContainer �ɑ΂��āA
		IfNodeContainerConst �C���^�[�t�F�[�X�����
		�A�N�Z�X���邽�߂̃A�_�v�^�N���X�ł��B
		
		CNodeContainer �́A���̃A�_�v�^���W�񂵂Ă���A
		getIfNodeContainerConst() ���\�b�h�ŁA
		���̃A�_�v�^�ւ̃|�C���^��Ԃ��܂��B
	*/
	class CaConst : public IfNodeContainerConst 
	{
	public:
		// ********************************
		///@name	IfNodeContainerConst-Property�̎擾
		// ********************************
		///@{
		/**
			Property �� Name �ɑΉ����� Value ���擾���܂��B
		@param strName [in]
			Property �� Name ���w�肵�Ă��������B
		@return
			�Ή�����Value��Ԃ��܂��B

			Name�ɑΉ����� Property ��������Ȃ��ꍇ�́A
			�󕶎����Ԃ��܂��B

			Name �ɑΉ����� 2�ȏ��CPropertyString �C���X�^���X������
			����ꍇ�́AInNameIndex ���ł������� CPropertyString �� Value 
			��Ԃ��܂��B
		*/
		virtual string getValue( const string& strName )const ;
		///@}

	public:
		// ********************************
		///@name	IfContGet
		// ********************************
		///@{
		
		/**
		 * @return
		 * 	�R���e�i�Ɋi�[����Ă���v�f�̌���Ԃ��܂��B
		 */
		virtual int	size()const ;
		/**
		 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���
		 * 	�v�f��Ԃ��܂��B
		 *
		 * @param iIndex [in]
		 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
		 * 	�͈͂͂O�ȏ� size() �����ł��B
		 *	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 * @return
		 * 	�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
		 */
		virtual Ou<const CNode> get( int iIndex )const ;
		
		///@}
		
	public:
		// ********************************
		///@name	CNodeContainer-InNameIndex�ł̃A�N�Z�X
		// ********************************
		///@{
		
		/**
	 		�w��� Name �����v�f�̌���Ԃ��܂��B
		 @param strName [in]
			Name ���w�肵�Ă��������B
		 @return
	 		�v�f�̌���Ԃ��܂��B
		*/
		virtual int	sizeInName( const string& strName )const ;
		/**
	 		�R���e�i���́A�w��� Name �����v�f��Ԃ��܂��B
		 @param strName [in]
			Name ���w�肵�Ă��������B
		 @param iInNameIndex [in]
	 		InNameIndex ���w�肵�Ă��������B
			InNameIndex �́A���̃R���e�i���̓��� Name ������ Node ���ł́A
			�O����n�܂�C���f�N�X�ł��B
			�͈͂͂O�ȏ� sizeInName() �����ł��B
			�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		 @return
	 		�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
		*/
		virtual Ou<const CNode> getInName( const string& strName , int iInNameIndex )const ;
		
		

		/**
			InNameIndex ���R���e�i�̃C���f�N�X�ɕϊ����܂��B
		@param strName [in]
			Name ���w�肵�Ă��������B
		@param iInNameIndex [in]
	 		�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 		�͈͂͂O�ȏ� sizeInName() �����ł��B
	 		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		@return
			�C���f�N�X ��Ԃ��܂��B
			-	-1 ;	//	�C���f�N�X���s���ł��B
		*/
		virtual int indexOfInNameIndex( 
			const string& strName ,
			int iInNameIndex )const ;
		/**
			�R���e�i�̃C���f�N�X���AInNameIndex �ɕϊ����܂��B
		@param iIndex [in]
	 		�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 		�͈͂͂O�ȏ� size() �����ł��B
	 		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
		@return
			InNameIndex ��Ԃ��܂��B
		*/
		virtual int indexToInNameIndex( 
			int iIndex )const ;

		///@}
	};
	friend class CaConst ;

private:
	// ********************************
	///@name	�W��
	// ********************************
	///@{
	/**
		Ou<CNode>[ index ] �̌`���ŁA�m�[�h��ێ����܂��B
	*/
	ElementTypeStlCont	m_contCNode ;

	/**
		CNodeContainer �ɑ΂��āA
		IfNodeContainerConst �C���^�[�t�F�[�X�����
		�A�N�Z�X���邽�߂̃A�_�v�^�N���X�ł��B
		
		CNodeContainer �́A���̃A�_�v�^���W�񂵂Ă���A
		getIfNodeContainerConst() ���\�b�h�ŁA
		���̃A�_�v�^�ւ̃|�C���^��Ԃ��܂��B
	*/
	CaConst	m_CaConst ;
	///@}

	// --------------------------------
	///@name	�����f�[�^
	// --------------------------------
	///@{
	/**
		index[ Name ][InNameIndex ] �̌`���ŁA
		Index �� InNameIndex �̑Ώƕ\��ێ����܂��B
	*/
	CInNameIndexContainer	m_CInNameIndexContainer;
	///@}
	
private:
	// --------------------------------
	///@name	�����֐�
	// --------------------------------
	///@{
	/**
		Property �� Name �ɑΉ����� CPropertyString ������΁A
		���̗v�f�ւ̃|�C���^���擾���邱�Ƃ��ł��܂��B
		���̃I�u�W�F�N�g�̑�����ύX���邱�Ƃɂ��A
		�R���e�i���� Property ��ύX���邱�Ƃ��ł��܂��B
	@param strName [in]
		Property �� Name ���w�肵�Ă��������B
	@return
		�Ή����� CPropertyString �ւ̎Q�Ƃ�Ԃ��܂��B

		Name�ɑΉ����� Property ��������Ȃ��ꍇ�́A
		NULL��Ԃ��܂��B

		Name �ɑΉ����� 2�ȏ��CPropertyString �C���X�^���X������
		����ꍇ�́AInNameIndex ���ł������� CPropertyString �� CPropertyString 
		��Ԃ��܂��B
	*/
	Ou<CPropertyString> getCPropertyString( const string& strName )const ;
	///@}
	
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CNodeContainer();
	virtual ~CNodeContainer();
	/**
		value ���W�񂷂�S�Ă� Node ��
		�R�s�[���쐬���A������W�񂵂܂��B
		value �ƃI�u�W�F�N�g�����L���邱�Ƃ͂���܂���B
	*/
	CNodeContainer( const CNodeContainer& value );
	/**
		value ���W�񂷂�S�Ă� Node ��
		�R�s�[���쐬���A������W�񂵂܂��B
		value �ƃI�u�W�F�N�g�����L���邱�Ƃ͂���܂���B
	*/
	CNodeContainer& operator=( const CNodeContainer& value );
public:
	// ********************************
	///@name	�W��
	// ********************************
	///@{
	/**
	@return
		Node �I�u�W�F�N�g��ێ�����R���e�i���Q�Ƃ���C���^�[�t�F�[�X�ł��B\n
		���̃C���^�[�t�F�[�X����́ACNodeContainer ���̑S�Ẵm�[�h�ɑ΂���
		Ou<const CNode> ���擾���邱�Ƃ��ł��܂����A
		�m�[�h�̒ǉ��E�ύX�E�폜�͂ł��܂���B
	*/
	virtual const IfNodeContainerConst* getIfNodeContainerConst()const ;
	///@}
public:
	// ********************************
	///@name	CNodeContainer-Property�̎擾��ݒ�
	// ********************************
	///@{
	/**
		Property �� Name �� Value ��ݒ肵�܂��B
	@param strName [in]
		Property �� Name ���w�肵�Ă��������B
	@param strValue [in]
		Property �� Value ���w�肵�Ă��������B

		Name �ɑΉ����� Property (CPropertyString) ��
		this �̃R���e�i���ɑ��݂��Ȃ��ꍇ�́A
		CPropertyString �I�u�W�F�N�g���R���e�i�ɐV�K�ǉ����܂��B

		Name �ɑΉ����� CPropertyString �����݂��Ă���ꍇ�́A����
		CPropertyStroing �I�u�W�F�N�g�� Value ���㏑�����܂��B
		�������O������2�ȏ��CPropertyString �C���X�^���X������
		����ꍇ�́AInNameIndex ���ł������� CPropertyString �� Value 
		���㏑���܂��B
	*/
	virtual void setValue( const string& strName , 
		const string& strValue ) ;

	/**
		Property �� Name �ɑΉ����� Value ���擾���܂��B
	@param strName [in]
		Property �� Name ���w�肵�Ă��������B
	@return
		�Ή�����Value��Ԃ��܂��B

		Name�ɑΉ����� Property ��������Ȃ��ꍇ�́A
		�󕶎����Ԃ��܂��B

		Name �ɑΉ����� 2�ȏ��CPropertyString �C���X�^���X������
		����ꍇ�́AInNameIndex ���ł������� CPropertyString �� Value 
		��Ԃ��܂��B
	*/
	virtual string getValue( const string& strName )const ;
	///@}

public:
	// ********************************
	///@name	IfContGet
	// ********************************
	///@{
	
	/**
	 * @return
	 * 	�R���e�i�Ɋi�[����Ă���v�f�̌���Ԃ��܂��B
	 */
	virtual int	size()const ;
	/**
	 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�Ɋi�[����Ă���
	 * 	�v�f��Ԃ��܂��B
	 *
	 * @param iIndex [in]
	 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 * 	�͈͂͂O�ȏ� size() �����ł��B
	 *	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 * 	�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
	 */
	virtual ElementType get( int iIndex )const ;
	
	///@}
public:
	// ********************************
	///@name	IfCont
	// ********************************
	///@{
	
	/**
	 * 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 * 	�v�f���㏑�����܂��B
	 * @param element [in]
	 * 	�v�f���w�肵�Ă��������B
	 * @param iIndex [in]
	 * 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 * 	�͈͂͂O�ȏ� size() �����ł��B
	 *	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 * @return
	 * 	0�ȏ�͐����A���̐��̓G���[�ł�
	 */
	virtual int set( const ElementType& element , int iIndex ) ;

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
	 */
	virtual int insert( const ElementType& element , int iIndex = INT_MAX ) ;
	
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
	 */
	virtual int erase( int iIndex  , int iSize = 1 ) ;
	
	///@}
public:
	// ********************************
	///@name	CNodeContainer-InNameIndex�ł̃A�N�Z�X
	// ********************************
	///@{
	
	/**
	 	�w��� Name �����v�f�̌���Ԃ��܂��B
	 @param strName [in]
		Name ���w�肵�Ă��������B
	 @return
	 	�v�f�̌���Ԃ��܂��B
	*/
	virtual int	sizeInName( const string& strName )const ;
	/**
	 	�R���e�i���́A�w��� Name �����v�f��Ԃ��܂��B
	 @param strName [in]
		Name ���w�肵�Ă��������B
	 @param iInNameIndex [in]
	 	InNameIndex ���w�肵�Ă��������B
		InNameIndex �́A���̃R���e�i���̓��� Name ������ Node ���ł́A
		�O����n�܂�C���f�N�X�ł��B
		�͈͂͂O�ȏ� sizeInName() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @return
	 	�C���f�N�X�Ŏw�肳�ꂽ�v�f��Ԃ��܂��B
	*/
	virtual ElementType getInName( const string& strName , int iInNameIndex )const ;
	
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f���㏑�����܂��B
	@param element [in]
	 	�v�f���w�肵�Ă��������B
	@param iInNameIndex [in]
	 	�O����n�܂�InNameIndex���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	@return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int setInName( 
		const ElementType& element , 
		int iInNameIndex ) ;

	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ�ɁA
	 	�v�f��ǉ����܂��B
	@param element [in]
	 	�v�f���w�肵�Ă��������B
	@param iInNameIndex [in]
	 	�O����n�܂�InNameIndex���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� sizeInName() �ȉ��ł��B
	 	�O�́A�擪�EsizeInName()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	@return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int insertInName( 
		const ElementType& element , 
		int iInNameIndex = INT_MAX ) ;
	
	/**
	 	�R���e�i���́A�C���f�N�X�Ŏw�肳�ꂽ�ꏊ��
	 	�v�f���폜���܂��B
	@param strName [in]
		Name ���w�肵�Ă��������B
	@param iInNameIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� sizeInName() �����ł��B
	 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	@param iSize [in]
	 	�폜����v�f�̐����w�肵�Ă��������B
	 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
	@attention
		iIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
	@return
	 	0�ȏ�͐����A���̐��̓G���[�ł�
	*/
	virtual int eraseInName( const string& strName , 
		int  iInNameIndex  , int iSize = 1 ) ;
	/**
		InNameIndex ���R���e�i�̃C���f�N�X�ɕϊ����܂��B
	@param strName [in]
		Name ���w�肵�Ă��������B
	@param iInNameIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� sizeInName() �����ł��B
	 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	@return
		�C���f�N�X ��Ԃ��܂��B
		-	-1 ;	//	�C���f�N�X���s���ł��B
	*/
	virtual int indexOfInNameIndex( 
		const string& strName ,
		int iInNameIndex )const ;
	/**
		�R���e�i�̃C���f�N�X���AInNameIndex �ɕϊ����܂��B
	@param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
	 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	@return
		InNameIndex ��Ԃ��܂��B
	*/
	virtual int indexToInNameIndex( 
		int iIndex )const ;

	///@}
	
};


};	//namespace OuPropertiesText
