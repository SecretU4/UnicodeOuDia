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
//	CaMui.h
// $Id: CaMui.h 10 2012-08-26 09:48:47Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CaMui_h
#define  CaMui_h
#include "./Mui.h"
// ****************************************************************
//	CaMui
// ****************************************************************
/**
 @brief
 �A�_�v�^�N���X�ł��B
 Mui �C���^�[�t�F�[�X���T�|�[�g���Ă���R���e�i�ɑ΂��A
 �����ǉ����܂��B
 
 ���̃N���X�̃C���X�^���X�́A Mui �C���^�[�t�F�[�X���T�|�[�g���Ă���
 �R���e�i�𑀍�ΏۃI�u�W�F�N�g�Ƃ��A����Ƃ̊֘A�������܂��B
 
 ���̃N���X�Œǉ�����鑀��́A�ȉ��̂��̂ł��B
 
 - insert()	//	���̃R���e�i�̓��e���A����ΏۃR���e�i�ɃR�s�[
 */
template < class ElementType > class CaMui
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
	Mui<ElementType>*	m_pAdaptee ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CaMui( Mui<ElementType>* pAdaptee ) : 
		m_pAdaptee( pAdaptee ){};
private:
	///	�R�s�[�͋֎~
	CaMui( const CaMui& value )
	{
		assert( false ) ;
	}
	///	�R�s�[�͋֎~
	CaMui& operator=( const CaMui& value )
	{
		assert( false ) ;
		return *this ;
	}
	
public:
	// ********************************
	///@name CaMui-�֘A
	// ********************************
	///@{
	Mui<ElementType>*	getAdaptee(){	return 	m_pAdaptee ;};
	const Mui<ElementType>*	getAdaptee()const{	return 	m_pAdaptee ;};
	CaMui& setAdaptee( Mui<ElementType>* value )
	{	m_pAdaptee = value ;	return *this ;};
	///@}
	// ********************************
	///@name CaMui-����
	// ********************************
	///@{
	/**
		����ΏۃI�u�W�F�N�g m_pAdaptee �̃R���e�i�ɁA
		���̃R���e�i�̗v�f��}�����܂��B
	 @param pMu [in]
		�R�s�[����v�f��ێ����Ă���R���e�i���w�肵�Ă��������B
	 @param iSrcIndex [in]
		�R�s�[����v�f�́A pMu ���ł̐擪�C���f�N�X�B
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� pMu->size() �����ł��B
	 	�A���AINT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @param iSize [in]
		�R�s�[����v�f�̐��B
	 	�A���AINT_MAX �́A iIndex ���疖���܂ł�\���܂��B
	 @param iIndex [in]
		m_pAdaptee ���ł́A�v�f���R�s�[����ʒu�B
	 	�O����n�܂�C���f�N�X���w�肵�Ă��������B
	 	�͈͂͂O�ȏ� m_pAdaptee->size() �ȉ��ł��B
	 	�O�́A�擪�Em_pAdaptee->size() size()�Ȃ疖���ւ̒ǉ��ɂȂ�܂��B
		INT_MAX �́A�������w�肵�����̂Ƃ݂Ȃ��܂��B
	 @attention
		iSrcIndex �� iSize �̗����� INT_MAX �ɂ��邱�Ƃ͂ł��܂���B
	 @return
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	iIndex���s��
		-	-2 ;	//	iSrcIndex���s��
	 */
	virtual int insert( 
			const Mu<ElementType>* pMu , 
			int iSrcIndex = 0 , int iSize = INT_MAX , int iIndex = INT_MAX )
	{
		int iRv = 0 ;
		if ( iRv >= 0 )
		{
			if ( iSrcIndex == INT_MAX && iSize == INT_MAX )
			{
				iRv = -2 ;	//	iSrcIndex ���s��
			}
		}
		if ( iRv >= 0 )
		{
			if ( iSrcIndex == INT_MAX )
			{
				iSrcIndex = pMu->size() - iSize ; 
			}
			if ( iSize == INT_MAX )
			{
				iSize = pMu->size() - iSrcIndex ; 
			}
			if ( !( 0 <= iSrcIndex && iSrcIndex + iSize<= (int)pMu->size() ) )
			{
				iRv = -2 ;	//	iSrcIndex���s��
			}
		}
		if ( iRv >= 0 )
		{
			if ( iIndex == INT_MAX )
			{
				iIndex = m_pAdaptee->size() ; 
			}
			if ( !( 0 <= iIndex && iIndex <= (int)m_pAdaptee->size() ) )
			{
				iRv = -1 ;	//	iIndex���s��
			}
		}
		// --------------------------------

		if ( iRv >= 0 )
		{
			for ( int cnt = 0 ; iRv >= 0 && cnt < iSize ; cnt ++ )
			{
				iRv = m_pAdaptee->insert( 
					pMu->get( iSrcIndex + cnt ) , 
					iIndex + cnt ) ;
			}
		}
		return ( iRv ) ;
	};
	///@}

};

#endif /*CaMui_h*/

