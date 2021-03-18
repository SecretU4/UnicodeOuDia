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
//	CentDedRessyasyubetsu.cpp
// ****************************************************************
*/
/** @file */

#include "stdafx.h"
#include "CentDedRessyasyubetsu.h"
#include "CentDedRessyasyubetsuCont.h"

namespace entDed{


// ****************************************************************
//	CentDedRessyasyubetsu
// ****************************************************************
	// ********************************
	//	�R���X�g���N�^
	// ********************************
CentDedRessyasyubetsu::	CentDedRessyasyubetsu( 
			const std::string& strSyubetsumei ,
			const std::string& strRyakusyou ,
			CdColorProp	colorJikokuhyouMojiColor , 
			CdColorProp	colorDiagramSenColor ,
			ESenStyle	eDiagramSenStyle ,
			bool bDiagramSenIsBold ) :
		m_strSyubetsumei( strSyubetsumei ) ,
		m_strRyakusyou( strRyakusyou ) ,
		m_colorJikokuhyouMojiColor( colorJikokuhyouMojiColor ) , 
		m_iJikokuhyouFontIndex( 0 ) ,
		m_CdDiagramLineStyle( colorDiagramSenColor , eDiagramSenStyle , bDiagramSenIsBold ) ,
		m_eStopMarkDrawType( EStopMarkDrawType_DrawOnStop )
{
};

CentDedRessyasyubetsu::CentDedRessyasyubetsu() :
		m_colorJikokuhyouMojiColor( CdColorProp( 0 , 0 , 0 ) ) , 
		m_iJikokuhyouFontIndex( 0 ) ,
		m_eStopMarkDrawType( EStopMarkDrawType_DrawOnStop )
{
};

CentDedRessyasyubetsu& 
CentDedRessyasyubetsu::operator=( const CentDedRessyasyubetsu& value ) 
{
	//	���̃I�u�W�F�N�g���A�e�I�u�W�F�N�gCentDedEkiTrackCont ��
	//	�q�ł���ꍇ�ŁA������� CentDedEkiTrackCont::set() �ŃG���[��
	//	�Ȃ�ꍇ�A��O�X���[�ɂȂ�܂��B
	CentDedRessyasyubetsuCont* pParent 
		= dynamic_cast<CentDedRessyasyubetsuCont*>( getParent() ) ;
	if ( pParent != NULL )
	{
		if ( pParent->setable( value , pParent->getIndex( this ) ) )
		{
			throw( LException() ) ;
		}
	}

	//	�����o�[�̃R�s�[
	m_strSyubetsumei = value.m_strSyubetsumei ;
	m_strRyakusyou = value.m_strRyakusyou ;
	m_colorJikokuhyouMojiColor  = value.m_colorJikokuhyouMojiColor ;
	m_iJikokuhyouFontIndex  = value.m_iJikokuhyouFontIndex ;
	m_CdDiagramLineStyle  = value.m_CdDiagramLineStyle ;
	m_eStopMarkDrawType  = value.m_eStopMarkDrawType ;
	// --------------------------------
	super::operator=( value ) ;
	return *this ;
}

	// ********************************
	//@name CParentBase-����
	// ********************************
void CentDedRessyasyubetsu::setParent( CParentBase* pParent ) 
{
	super::setParent( pParent ) ;
	adjust() ;
}



	// ********************************
	//@name CentDedRessyasyubetsu-����
	// ********************************
CentDedRessyasyubetsu& 
CentDedRessyasyubetsu::setSyubetsumei( const std::string& value )
{
	//	���̃I�u�W�F�N�g���A�e�I�u�W�F�N�g CentDedRessyasyubetsu 
	//	�̎q�ł���ꍇ�A�󕶎���ւ̕ύX�̓G���[�Ƃ��܂��B
	CentDedRessyasyubetsuCont* pParent 
		= dynamic_cast<CentDedRessyasyubetsuCont*>( getParent() ) ;
	if ( pParent != NULL )
	{
		if ( value.length() == 0 )
		{
			throw( LException() ) ;
		}
	}

	m_strSyubetsumei = value ; 


	return *this ; 
} ;

CentDedRessyasyubetsu& 
CentDedRessyasyubetsu::setJikokuhyouFontIndex( int value )
{
	//	�͈͊O�Ȃ��O�X���[
	if ( !( 0 <= value && value < JIKOKUHYOUFONT_COUNT ) )
	{
		throw( LException() ) ;
	}
	m_iJikokuhyouFontIndex = value ; 


	return *this ;
};

	// ********************************
	//@name CentDedRessyasyubetsu-����
	// ********************************
void CentDedRessyasyubetsu::adjust() 
{
	
};

} //namespace entDed



