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
//$Id: CInnameIndexContainer.h 63 2012-09-01 08:54:26Z okm $
#pragma once
#include <deque>
#include <string>
#include <map>

namespace OuLib{
namespace Str{
namespace OuPropertiesText{


/**
@brief
	Index �� InNameIndex �̕ϊ��@�\�����������N���X�ł��B
	
	���̃N���X�́ACNodeContainer �ɏW�񂳂�܂��B
	���̃N���X��P�̂Ŏg�����_�͂���܂���B
	
	���̃N���X�́A

		Index[ Name ][ InNameIndex ] 

	�̌`���̃R���e�i���N���X���������̂ł��B

*/
class CInNameIndexContainer
{
public:
	/**
		����� Name �ɂ�����AInNameIndex �� Index �̑Ώƕ\
		�ƂȂ�R���e�i�ł��B

		- �Y������ InNameIndex
		- �l�� Index

		�ƂȂ�܂��B
	*/
	typedef std::deque< int >	InNameIndexCont ;
	/**
		���ׂĂ� Name �ɂ�����AInNameIndex �� Index �̑Ώƕ\
		�ƂȂ�R���e�i�ł��B

		- �L�[�� Name
		- �l�� InNameIndexCont

		�ƂȂ�܂��B
	*/
	typedef std::map< std::string , InNameIndexCont >	NameIndexCont ;
private:
	// ********************************
	///@name �W��
	// ********************************
	///@{
	/**
		���ׂĂ� Index �̐��B
	*/
	int m_iNodeCount ;
	/**
		���ׂĂ� Name �ɂ�����AInNameIndex �� Index �̑Ώƕ\
		�ƂȂ�R���e�i�ł��B

		- �L�[�� Name
		- �l�� InNameIndexCont

		�ƂȂ�܂��B
	*/
	NameIndexCont	m_NameIndexCont ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CInNameIndexContainer();
	virtual ~CInNameIndexContainer();
public:

public:
	// ********************************
	///@name	Mu
	// ********************************
	///@{
	
	/**
	 * @return
	 * 	�R���e�i�Ɋi�[����Ă���v�f�̌���Ԃ��܂��B
	 */
	virtual int	size()const ;
	
	///@}
public:
	// ********************************
	///@name	Mui
	// ********************************
	///@{

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
	virtual int insert( const std::string& element , int iIndex = INT_MAX ) ;
	
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
	virtual int	sizeInName( const std::string& strName )const ;
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
		const std::string& strName ,
		int iInNameIndex )const ;
	/**
		�R���e�i�̃C���f�N�X���AInNameIndex �ɕϊ����܂��B
	@param strName [in]
		Name ���w�肵�Ă��������B
	@param iIndex [in]
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� size() �����ł��B
	 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	@return
		InNameIndex ��Ԃ��܂��B
	*/
	virtual int indexToInNameIndex( 
		const std::string& element ,
		int iIndex )const ;

	///@}
};


} //namespace OuPropertiesText{
} //namespace Str{
} //namespace OuLib{
