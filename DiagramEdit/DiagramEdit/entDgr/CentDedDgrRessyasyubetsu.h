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
//	CentDedDgrRessyasyubetsu.h
// ****************************************************************
*/
/** @file */
#ifndef  CentDedDgrRessyasyubetsu_h
#define  CentDedDgrRessyasyubetsu_h
#include "DcdCd\DcDrawProp\CdColorProp.h"
#include "DcdCd\DcDrawProp\CdDcdFreeLineProp.h"
#include "entDed\CentDedRessyasyubetsu.h"

namespace entDgr{

// ****************************************************************
//	CentDedDgrRessyasyubetsu
// ****************************************************************
/**
@brief
�y�T�v�z
�w�_�C���O�����G���e�B�e�B�N���X�Q�x�́w��Ԏ�ʁx�N���X�ł��B
�w�_�C���x (CentDedDgrDia) �Ɋ܂܂��w��Ԏ�ʁx�P��\���܂��B

���̃N���X�́A�w�_�C���O�����_�C���x (CentDedDgrDia) �ɕ�܂���܂��B

CentDedDgrDia : CentDedDgrRessyasyubetsu �̑��d�x�́A

�P�F�i�w��Ԏ�ʁx�̐��j 

�ƂȂ�܂��B

����́A

�i�w�H���x(CentDedRosen)�j�F�i�w��Ԏ�ʁx�iCentDedRessyasyubetsu�j�j

�̑��d�x�Ɠ����ł��B

�y�g�����z

  �����ł́A���̃N���X�̃I�u�W�F�N�g�𐶐�����̂́A
�w�_�C���O�����_�C���x (CentDedDgrDia) �N���X�ɂ̃��\�b�h�����ł��B
�N���X���[�U�[�͂��̃N���X�̃I�u�W�F�N�g�𒼐ڐ�������p���͂Ȃ��A
�w�_�C���O�����_�C���x (CentDedDgrDia) �N���X�ɂ���Đ������ꂽ
�I�u�W�F�N�g�̑������Q�Ƃ��邾���ł��B

 */
class CentDedDgrRessyasyubetsu
{
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�����\�����F(�_�C���O�����̗�ԏ��̕����F�����˂܂�)
	
		�K��l�́A���B
	 */
	CdColorProp	m_colorJikokuhyouMojiColor ;

	/**
		��Ԑ�(����)�̐��̌`�󑮐��B
	*/
	CentDedRessyasyubetsu::CdDiagramLineStyle	m_CdDiagramLineStyle ;

	/**
		��Ԏ�ʖ��́A��ԉw�����̕��@�B
		����l�́A EStopMarkDrawType_DrawOnStop �B
	*/
	CentDedRessyasyubetsu::EStopMarkDrawType m_eStopMarkDrawType ;
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CentDedDgrRessyasyubetsu() :
	  m_eStopMarkDrawType( CentDedRessyasyubetsu::EStopMarkDrawType_DrawOnStop )
	  {}
	
	CentDedDgrRessyasyubetsu(
		const CdColorProp& colorJikokuhyouMojiColor ,
		CentDedRessyasyubetsu::CdDiagramLineStyle aCdDiagramLineStyle ,
		//const CdDcdFreeLineProp& aLineProp ,
		CentDedRessyasyubetsu::EStopMarkDrawType eStopMarkDrawType ) 
		:
		m_colorJikokuhyouMojiColor( colorJikokuhyouMojiColor ) ,
		m_CdDiagramLineStyle( aCdDiagramLineStyle ) ,
		m_eStopMarkDrawType( eStopMarkDrawType ){}
public:
	// ********************************
	///@name CentDedDgrRessyasyubetsu::����
	// ********************************
	CdColorProp	getJikokuhyouMojiColor()const
	{	return m_colorJikokuhyouMojiColor ;};
	CentDedRessyasyubetsu::CdDiagramLineStyle	getCdDiagramLineStyle()const
	{	return m_CdDiagramLineStyle ;};
	CentDedRessyasyubetsu::EStopMarkDrawType getStopMarkDrawType()const
	{	return m_eStopMarkDrawType ;};

};

} //namespace entDgr



#endif /*CentDedDgrRessyasyubetsu_h*/


