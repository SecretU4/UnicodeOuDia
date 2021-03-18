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
// ****************************************************************
// $Id: CdRessyasyubetsuYColSpec.h 179 2014-05-05 13:50:33Z okm $
// ****************************************************************
/** @file */
#pragma once
#ifndef ViewRessyasyubetsu_CdRessyasyubetsuYColSpec_h
#define ViewRessyasyubetsu_CdRessyasyubetsuYColSpec_h

namespace ViewRessyasyubetsu{ namespace RessyasyubetsuColSpec{
/**
@brief
  ��Ԏ�ʃr���[�� CWndDcdGridRessyasyubetsu �ɂ����āA�O���b�h��Y��ɕ\��
  ���ׂ����e���L�q�����A�P���f�[�^�N���X�ł��B

  ���̒l�� NULL ��Ԃ������܂��B
*/
class CdRessyasyubetsuYColSpec
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	/** ��̎�� */
	enum EColumnType
	{
		/**	�w�b�_�� */
		ColumnType_Head = 0 ,
		/**	��Ԏ�ʗ� */
		ColumnType_Ressyasyubetsu ,
		/**	�V�K�ǉ��ʒu */
		ColumnType_NewRessyasyubetsu ,

		/**	NULL��Ԃ������܂� */
		ColumnType_NULL = -1 
	};
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/** ��̎�� */
	EColumnType	m_eColumnType ;
	
	/** 
		��Ԏ��Index �B
		m_eColumnType �� ColumnType_Ressyasyubetsu �̏ꍇ�́A
		0 �ȏ��Ԏ�ʐ������̗�Ԏ�� Index ��\���܂��B
		
		���̑��̏ꍇ�͈Ӗ��������܂���B
		����l�� -1 �ł��B
	*/
	int m_iRessyasyubetsuIndex ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	@param eColumnType 
		��̎�� 
	@param iRessyasyubetsuIndex 
		��Ԏ��Index 
	*/
	CdRessyasyubetsuYColSpec( 
		EColumnType eColumnType , 
		int iRessyasyubetsuIndex ) 
		: m_eColumnType( eColumnType )
		, m_iRessyasyubetsuIndex( iRessyasyubetsuIndex ){}
	CdRessyasyubetsuYColSpec( 
		EColumnType eColumnType ) 
		: m_eColumnType( eColumnType )
		, m_iRessyasyubetsuIndex( -1 ){}

	CdRessyasyubetsuYColSpec()
		: m_eColumnType( ColumnType_NULL ) 
		, m_iRessyasyubetsuIndex( -1 ){}
	
public:
	// ********************************
	///@name CdRessyasyubetsuYColSpec-����
	// ********************************
	EColumnType	getColumnType()const{	return m_eColumnType ;};
	int getRessyasyubetsuIndex()const{	return m_iRessyasyubetsuIndex ;};

	/**
		�l��ݒ肵�܂��B
	@param eColumnType 
		��̎�� 
	@param iRessyasyubetsuIndex 
		��Ԏ��Index 
	*/
	void set( EColumnType eColumnType , 
		int iRessyasyubetsuIndex ) 
	{
		m_eColumnType = eColumnType ;
		m_iRessyasyubetsuIndex = iRessyasyubetsuIndex ;
	}

	bool isNull()const{	return m_eColumnType == ColumnType_NULL ;};
	/* 
		this ��NULL��Ԃɂ��܂��B
	*/
	void setNull(){	*this = CdRessyasyubetsuYColSpec() ;};	

	/**
		���̃I�u�W�F�N�g�Ƃ̊ԂŁA���������ꂩ�ۂ��𔻒肵�܂��B
	@param value
		��r�Ώۂ��w�肵�Ă��������B
	@return
		����������ł���� true 
	*/
	bool isEqualTo( const CdRessyasyubetsuYColSpec& value )const
	{
		bool bRv = false ;
		if ( m_eColumnType == value.m_eColumnType )
		{
			//	ColumnType_Ressyasyubetsu ��̏ꍇ�́A
			//	m_iRessyasyubetsuIndex �̈�v��K�v�Ƃ��܂��B
			if ( m_eColumnType == ColumnType_Ressyasyubetsu )
			{
				bRv = ( m_iRessyasyubetsuIndex == value.m_iRessyasyubetsuIndex ) ;
			}
			else
			{
				bRv = true ;
			}
		}
		return bRv ;
	}
	bool operator==(const CdRessyasyubetsuYColSpec& value )const
	{	return isEqualTo( value ) ;}
	bool operator!=(const CdRessyasyubetsuYColSpec& value )const
	{	return !isEqualTo( value ) ;}
};
} } //namespace RessyasyubetsuColSpec namespace ViewRessyasyubetsu

#endif/*ViewRessyasyubetsu_CdRessyasyubetsuYColSpec_h*/
