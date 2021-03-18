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
//	CConverter_WinGdi.h
// ****************************************************************
*/
/** @file */
#ifndef  CConverter_WinGdi_h
#define  CConverter_WinGdi_h

#include <windows.h>

#include "str\tstring.h"
#include "NsOu\Ou.h"

#include "DcdCd\Pos\CdDcdPosXy.h"
#include "DcdCd\Pos\CdDcdZoneXy.h"
#include "DcdCd\Pos\CdDcdSizeXy.h"

#include "DcdCd\DcDrawProp\CdDrawTextProp.h"
#include "DcdCd\DcDrawProp\CdColorProp.h"
#include "DcdCd\DcDrawProp\CdFontProp.h"
#include "DcdCd\DcDrawProp\CdPenProp.h"
#include "DcdCd\DcDrawProp\CdBrushProp.h"
#include "CGdiHFontHolder.h"
#include "CGdiHPenHolder.h"
#include "CGdiHBrushHolder.h"
#include "CdWinGdi_DrawText_Format.h"

namespace DcDrawLib{
namespace DcDraw{

	using namespace DcdCd::Pos;
	using namespace OuLib::NsOu;


// ****************************************************************
//	CConverter_WinGdi
// ****************************************************************
/**
	CConverter_WinGdi �̊֐��̐錾�ł��B
	���݂́A�w��Ȃ�(�񉼑z�E��static �����o�֐�) �Ƃ��Ă��܂��B
*/
#define CConverter_WinGdi_METHOD 

/**
 @brief
 �y�T�v�z
 	WIN32�Ŏg�p����\���̂ƁADcDraw�Ŏg�p����N���X�Ƃ̊Ԃ̑��ݕϊ���
 	�s���܂��B
*/
class CConverter_WinGdi
{
public:
	// ********************************
	///	@name ���W�������֐��Q
	// ********************************
	///@{
	/**
		POINT �^�� CdDcdPosXy �ɕϊ����܂��B
	 @param aPOINT [in]
		�ϊ���
	 @param pCdDcdPosXy [out]
		���̊֐��͂��̃A�h���X�ɁA�ϊ������l���������݂܂��B
	 */
	CConverter_WinGdi_METHOD 
		void toCdDcdPosXy( const POINT& aPOINT , CdDcdPosXy* pCdDcdPosXy ) ; 

	CConverter_WinGdi_METHOD
		CdDcdPosXy CdDcdPosXyOf( const POINT& aPOINT ) 
	{
		CdDcdPosXy	aCdDcdPosXy ;
		toCdDcdPosXy( aPOINT , &aCdDcdPosXy ) ;
		return ( aCdDcdPosXy ) ;
	};
	
	/**
		CdDcdPosXy �� POINT �^�ɕϊ����܂��B
	 @param aCdDcdPosXy [in]
		�ϊ���
	 @param pPOINT [out]
		���̊֐��͂��̃A�h���X�ɁA�ϊ������l���������݂܂��B
	 */
	CConverter_WinGdi_METHOD 
		void toPOINT( const CdDcdPosXy& aCdDcdPosXy , POINT* pPOINT ) ;
	
	CConverter_WinGdi_METHOD
		POINT POINTOf( const CdDcdPosXy& aCdDcdPosXy ) 
	{
		POINT	aPOINT ;
		toPOINT( aCdDcdPosXy  , &aPOINT ) ;
		return ( aPOINT ) ;
	};

	/**
		RECT �^�� CdDcdZoneXy �ɕϊ����܂��B
	 @param aPOINT [in]
		�ϊ���
	 @param pCdDcdZoneXy [out]
		���̊֐��͂��̃A�h���X�ɁA�ϊ������l���������݂܂��B
	 */
	CConverter_WinGdi_METHOD 
		void toCdDcdZoneXy( const RECT& aRECT , CdDcdZoneXy* pCdDcdZoneXy ) ; 

	CConverter_WinGdi_METHOD 
		CdDcdZoneXy CdDcdZoneXyOf( const RECT& aRECT ) 
	{
		CdDcdZoneXy	aCdDcdZoneXy ;
		toCdDcdZoneXy( aRECT , &aCdDcdZoneXy ) ;
		return ( aCdDcdZoneXy ) ;
	};
	
	/**
		CdDcdZoneXy �� RECT �^�ɕϊ����܂��B
	 @param aCdDcdPosXy [in]
		�ϊ���
	 @param pPOINT [out]
		���̊֐��͂��̃A�h���X�ɁA�ϊ������l���������݂܂��B
	 */
	CConverter_WinGdi_METHOD 
		void toRECT( const CdDcdZoneXy& aCdDcdZoneXy , RECT* pRECT ) ;
	
	CConverter_WinGdi_METHOD RECT RECTOf( const CdDcdZoneXy& aCdDcdZoneXy ) 
	{
		RECT	aRECT ;
		toRECT( aCdDcdZoneXy  , &aRECT ) ;
		return ( aRECT ) ;
	};

	///@}
	// ********************************
	///	@name Color�������֐��Q
	// ********************************
	///@{
	/**
		COLORREF ���ACdColorProp �ɕϊ����܂��B
	@param value [in]
		�ϊ����̒l���w�肵�Ă��������B
	@return 
		�ϊ���̒l���w�肵�Ă��������B
	*/
	CConverter_WinGdi_METHOD 
		CdColorProp CdColorPropOf( COLORREF value );

	/**
		CdColorProp �� COLORREF �ɕϊ����܂��B
	@param value [in]
		�ϊ����̒l���w�肵�Ă��������B
	@return 
		�ϊ���̒l���w�肵�Ă��������B
	*/
	CConverter_WinGdi_METHOD 
		COLORREF COLORREFOf( const CdColorProp& value );

	/**
		 �V�X�e���J���[�̑������A
		CdColorProp �I�u�W�F�N�g�֕ϊ����܂��B
	 @param fnObject [in]
	 	GetSysColor() �Ŏw�肷��A�\���v�f
		�̒萔���w�肵�Ă��������B
	 @return
	 	 CdColorProp �\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD 
		CdColorProp CdColorPropOfSysColor( int nIndex ) ;
	
	///@}
	// ********************************
	///	@name Font�������֐��Q
	// ********************************
	///@{
	
	/**
		CdFontProp�I�u�W�F�N�g�̓��e���A LOGFONT �\���̂֕ϊ����܂��B
	
	 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 	PointTextHeight �Ŏw�肳��Ă���ꍇ�́ALOGFONT�ɕϊ�
	 	����ۂɂ́A���̕ϊ��ɂ́A�t�H���g�̕`����s��HDC���K�v�ł��B
	 	�����A���̃P�[�X��HDC�̎w����ȗ������ꍇ�́A�X�N���[��DC��
	 	���Ƃ�LOGFONT�\���̂��쐬���܂��B

		CdFontProp::m_strFacename ���󕶎���Ƃ����ꍇ�́A
		DEFAULT_GUI_FONT �ō̗p����Ă���t�H���g���[�����܂��B
	 @param aCdFontProp [in]
	 	�t�H���g�������w�肵�Ă��������B
	 @param pLOGFONT [out]
	 	���̊֐��͂��̍\���̂ɁA�������������݂܂��B
	 @param hDc [in]
	 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 	PointTextHeight �Ŏw�肳��Ă���ꍇ�́ALOGFONT�ɕϊ�
	 	����ۂɂ́A���̕ϊ��ɂ́A�t�H���g�̕`����s��HDC���K�v�ł��B
	 	�����ɂ́A����HDC���w�肵�Ă��������B
	 	�����A���̃P�[�X��HDC�̎w����ȗ������ꍇ�́A�X�N���[��DC��
	 	���Ƃ�LOGFONT�\���̂��쐬���܂��B
	 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 	Logicalunit... �Ŏw�肳��Ă���ꍇ�́A����HDC�ɂ�
	 	�Ӗ�������܂���B
	*/
	CConverter_WinGdi_METHOD 
		void toLOGFONT( const CdFontProp& aCdFontProp , 
			LOGFONT*	pLOGFONT ,
			HDC hDc = NULL ) ;

	/**
		CdFontProp�I�u�W�F�N�g����A LOGFONT �\���̂֕ϊ����܂��B
		�����́AtoLOGFONT �Ɠ����ł�
	
	 @retval 
	 	�쐬����LOGFONT�\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD 
		LOGFONT LOGFONTOf( const CdFontProp& aCdFontProp , 
			HDC hDc = NULL ) 
	{
		LOGFONT	aLOGFONT ;
		toLOGFONT( aCdFontProp , &aLOGFONT , hDc ) ;
		return ( aLOGFONT ) ;
	};

	/**
		 LOGFONT �\���̂̓��e���ACdFontProp�I�u�W�F�N�g�֕ϊ����܂��B
		�������ACdFontProp�ۗ̕L������ʂ�LOGFONT�\���̂������Ȃ����߁A
		�ϊ����CdFontProp�I�u�W�F�N�g�ł́A��񂪈ꕔ�����܂��B
	 @param aLOGFONT [in]
	 	LOGFONT�\���̂��w�肵�Ă��������B
	 @param pCdFontProp [out]
	 	���̊֐��͂��̃I�u�W�F�N�g�\���̂ɁA�������������݂܂��B
	*/
	CConverter_WinGdi_METHOD void toCdFontProp( 
			const LOGFONT&	aLOGFONT ,
			CdFontProp* pCdFontProp ) ;

	/**
		�X�g�b�N�I�u�W�F�N�g�̑������A
		CdFontProp�I�u�W�F�N�g�֕ϊ����܂��B
		�������ACdFontProp�ۗ̕L������ʂ�LOGFONT�\���̂������Ȃ����߁A
		�ϊ����CdFontProp�I�u�W�F�N�g�ł́A��񂪈ꕔ�����܂��B
	 @param fnObject [in]
	 	GetStockObject() �Ŏw�肷��A�X�g�b�N�t�H���g�I�u�W�F�N�g
		�̒萔���w�肵�Ă��������B
	 @param pCdFontProp [out]
	 	���̊֐��͂��̃I�u�W�F�N�g�\���̂ɁA�������������݂܂��B
	*/
	CConverter_WinGdi_METHOD void toCdFontProp( 
			int fnObject ,
			CdFontProp* pCdFontProp ) ;

	/**
		 LOGFONT �\���̂̓��e���ACdFontProp�I�u�W�F�N�g�֕ϊ����܂��B
		�����́AtoCdFontProp �Ɠ����ł�
	 @param aLOGFONT [in]
	 	LOGFONT�\���̂��w�肵�Ă��������B
	 @return
	 	 CdFontProp �\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD CdFontProp CdFontPropOf( 
			const LOGFONT&	aLOGFONT )
	{
		CdFontProp	rv ;
		toCdFontProp( aLOGFONT , &rv ) ;
		return ( rv ) ;
	};
	/**
		 �X�g�b�N�I�u�W�F�N�g�̑������A
		CdFontProp�I�u�W�F�N�g�֕ϊ����܂��B
		�����́AtoCdFontProp �Ɠ����ł�
	 @param fnObject [in]
	 	GetStockObject() �Ŏw�肷��A�X�g�b�N�t�H���g�I�u�W�F�N�g
		�̒萔���w�肵�Ă��������B
	 @return
	 	 CdFontProp �\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD CdFontProp CdFontPropOf( int fnObject )
	{
		CdFontProp	rv ;
		toCdFontProp( fnObject , &rv ) ;
		return ( rv ) ;
	};

	/**
	 	CdFontProp�I�u�W�F�N�g�̑��������ƂɁA�t�H���g�𐶐����܂�
	 @param aCdFontProp [in]
	 	�t�H���g�������w�肵�Ă��������B
	 @param hDc [in]
	 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 	PointTextHeight �Ŏw�肳��Ă���ꍇ�́ALOGFONT�ɕϊ�
	 	����ۂɂ́A���̕ϊ��ɂ́A�t�H���g�̕`����s��HDC���K�v�ł��B
		�����ɂ́A����HDC���w�肵�Ă��������B
	 	�����A���̃P�[�X��HDC�̎w����ȗ������ꍇ�́A�X�N���[��DC��
	 	���Ƃ�LOGFONT�\���̂��쐬���܂��B
	 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 	Logicalunit... �Ŏw�肳��Ă���ꍇ�́A����HDC�ɂ�
	 	�Ӗ�������܂���B
	 @return
		�t�H���g�̃n���h����Ԃ��܂��B
		���̃n���h���̔j���̐Ӗ��́A�֐��ďo���ɂ���܂��B
		�֐��ďo���́A�n���h�����s�v�ɂȂ����� DeleteObject() ��
		�n���h����������Ȃ��Ă͂Ȃ�܂���B
	*/
	CConverter_WinGdi_METHOD 
		HFONT	CreateFont(  const CdFontProp& aCdFontProp , 
			HDC hDc = NULL ) ;

	/**
	 	CdFontProp�I�u�W�F�N�g�̑��������ƂɁA�t�H���g�𐶐����܂�
	 @param aCdFontProp [in]
	 	�t�H���g�������w�肵�Ă��������B
	 @param hDc [in]
	 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 	PointTextHeight �Ŏw�肳��Ă���ꍇ�́ALOGFONT�ɕϊ�
	 	����ۂɂ́A���̕ϊ��ɂ́A�t�H���g�̕`����s��HDC���K�v�ł��B
		�����ɂ́A����HDC���w�肵�Ă��������B
	 	�����A���̃P�[�X��HDC�̎w����ȗ������ꍇ�́A�X�N���[��DC��
	 	���Ƃ�LOGFONT�\���̂��쐬���܂��B
	 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 	Logicalunit... �Ŏw�肳��Ă���ꍇ�́A����HDC�ɂ�
	 	�Ӗ�������܂���B
	 @return
		�t�H���g�̃n���h����ێ����� CGdiHFontHolder ��Ԃ��܂��B
		�n���h���̐����ɂ����ꍇ�́ANULL�ł��B
	*/
	CConverter_WinGdi_METHOD  
		Ou<CGdiHFontHolder>	createGdiHFontHolder( 
			const CdFontProp& aCdFontProp , 
			HDC hDc = NULL ) ;
	

	/**
	 	CdFontProp�I�u�W�F�N�g�̑�����DC�����ƂɁA
		�w��̃e�L�X�g��`�悵���ꍇ�̑傫�����v�Z���܂��B
	 @param strTextExtent [in]
		���̊֐��́A���̕������\���ł��镝��Ԃ��܂��B
	 @param iLinesExtent [in]
		���̊֐��́A���̍s����\���ł��鍂����Ԃ��܂��B
	 @param aCdDrawTextProp [in]
	 	�t�H���g�������w�肵�Ă��������B
	 @param hDc [in]
	 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 	PointTextHeight �Ŏw�肳��Ă���ꍇ�́ALOGFONT�ɕϊ�
	 	����ۂɂ́A���̕ϊ��ɂ́A�t�H���g�̕`����s��HDC���K�v�ł��B
	 	�����ɂ́A����HDC���w�肵�Ă��������B
	 	�����A���̃P�[�X��HDC�̎w����ȗ������ꍇ�́A�X�N���[��DC��
	 	���Ƃ�LOGFONT�\���̂��쐬���܂��B
	 	CdFontProp �I�u�W�F�N�g�ɐݒ肳��Ă��鍂��������
	 	Logicalunit... �Ŏw�肳��Ă���ꍇ�́A����HDC�ɂ�
	 	�Ӗ�������܂���B
	 @return
		�t�H���g�̃n���h����Ԃ��܂��B
		���̃n���h���̔j���̐Ӗ��́A�֐��ďo���ɂ���܂��B
		�֐��ďo���́A�n���h�����s�v�ɂȂ����� DeleteObject() ��
		�n���h����������Ȃ��Ă͂Ȃ�܂���B
	*/
	CConverter_WinGdi_METHOD CdDcdSizeXy	DrawtextCalcrect( 
		const tstring& strExtent ,
		int iLinesExtent ,
		const CdDrawTextProp& aCdDrawTextProp , 
		HDC hDc = NULL ) ;
	
	/**
		CdDrawTextFormat �I�u�W�F�N�g�̑��������ƂɁA
		CdWinGdi_DrawText_Format �I�u�W�F�N�g�𐶐����܂��B
		���̒l�́A Win32 �� DrawText() �� uiFlags �p�����[�^��
		�n�����Ƃ��ł��܂��B
	@param aCdDrawTextFormat [in]
		�ϊ��O�̒l���w�肵�Ă��������B
	@return 
		�ϊ���̒l��Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD 
		CdWinGdi_DrawText_Format	CdWinGdi_DrawText_FormatOf(
			const CdDrawTextFormat& aCdDrawTextFormat ) ;

	///@}
	
	// ********************************
	///	@name Pen�������֐��Q
	// ********************************
	
	///@{
	
	/**
		CdPenProp�I�u�W�F�N�g�̓��e���A LOGPEN �\���̂֕ϊ����܂��B
	
	 @param aCdPenProp [in]
	 	�y���������w�肵�Ă��������B
	 @param pLOGPEN [out]
	 	���̊֐��͂��̍\���̂ɁA�������������݂܂��B
	*/
	CConverter_WinGdi_METHOD 
		void toLOGPEN( const CdPenProp& aCdPenProp , 
			LOGPEN*	pLogPen ) ;

	/**
		CdPenProp�I�u�W�F�N�g����A LOGPEN �\���̂֕ϊ����܂��B
		�����́AtoLOGPEN �Ɠ����ł�
	
	 @retval 
	 	�쐬����LOGFONT�\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD LOGPEN LOGPENOf( const CdPenProp& aCdPenProp ) 
	{
		LOGPEN	aLOGPEN ;
		toLOGPEN( aCdPenProp , &aLOGPEN ) ;
		return ( aLOGPEN ) ;
	};

	/**
		 LOGPEN �\���̂̓��e���ACdPenProp�I�u�W�F�N�g�֕ϊ����܂��B
	 @param aLOGPEN [in]
	 	LOGPEN�\���̂��w�肵�Ă��������B
	 @param pCdPenProp [out]
	 	���̊֐��͂��̃I�u�W�F�N�g�\���̂ɁA�������������݂܂��B
	*/
	CConverter_WinGdi_METHOD void toCdPenProp( 
			const LOGPEN&	aLOGPEN ,
			CdPenProp* pCdPenProp ) ;

	/**
		�X�g�b�N�I�u�W�F�N�g�̑������A
		CdPenProp�I�u�W�F�N�g�֕ϊ����܂��B
	 @param fnObject [in]
	 	GetStockObject() �Ŏw�肷��A�X�g�b�N�t�H���g�I�u�W�F�N�g
		�̒萔���w�肵�Ă��������B
	 @param pCdPenProp [out]
	 	���̊֐��͂��̃I�u�W�F�N�g�\���̂ɁA�������������݂܂��B
	*/
	CConverter_WinGdi_METHOD void toCdPenProp( 
			int fnObject ,
			CdPenProp* pCdPenProp ) ;
	
	/**
		 LOGPEN �\���̂̓��e���ACdPenProp�I�u�W�F�N�g�֕ϊ����܂��B
	 @param aLOGPEN [in]
	 	LOGPEN�\���̂��w�肵�Ă��������B
	 @return
	 	 CdPenProp �\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD CdPenProp CdPenPropOf( 
			const LOGPEN&	aLOGPEN ){
		CdPenProp	rv ;
		toCdPenProp( aLOGPEN , &rv ) ;
		return ( rv ) ;
	};
	/**
		�X�g�b�N�I�u�W�F�N�g�̑������A
		CdPenProp�I�u�W�F�N�g�֕ϊ����܂��B
	 @param fnObject [in]
	 	GetStockObject() �Ŏw�肷��A�X�g�b�N�t�H���g�I�u�W�F�N�g
		�̒萔���w�肵�Ă��������B
	 @return
	 	 CdPenProp �\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD CdPenProp CdPenPropOf( 
						int fnObject )
	{
		CdPenProp	rv ;
		toCdPenProp( fnObject , &rv ) ;
		return ( rv ) ;
	};

	/**
	 	CdPenProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 @param aCdPenProp [in]
	 	�y���������w�肵�Ă��������B
	 @return
		�y���̃n���h����Ԃ��܂��B
		���̃n���h���̔j���̐Ӗ��́A�֐��ďo���ɂ���܂��B
		�֐��ďo���́A�n���h�����s�v�ɂȂ����� DeleteObject() ��
		�n���h����������Ȃ��Ă͂Ȃ�܂���B
	*/
	CConverter_WinGdi_METHOD HPEN	CreatePen(  const CdPenProp& aCdPenProp ) ;
	
	/**
	 	CdPenProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 @param aCdPenProp [in]
	 	�y���������w�肵�Ă��������B
	 @return
		�y���̃n���h����ێ����� CGdiHPenHolder ��Ԃ��܂��B
		�n���h���̐����ɂ����ꍇ�́ANULL�ł��B
	*/
	CConverter_WinGdi_METHOD Ou<CGdiHPenHolder>		createGdiHPenHolder(  const CdPenProp& aCdPenProp ) ;
	///@}

	// ********************************
	///	@name Brush�������֐��Q
	// ********************************
	
	///@{
	/**
		CdBrushProp�I�u�W�F�N�g�̓��e���A LOGBRUSH �\���̂֕ϊ����܂��B
	
	 @param aCdBrushProp [in]
	 	�u���V�������w�肵�Ă��������B
	 @param pLOGBRUSH [out]
	 	���̊֐��͂��̍\���̂ɁA�������������݂܂��B
	*/
	CConverter_WinGdi_METHOD void toLOGBRUSH( const CdBrushProp& aCdBrushProp , 
			LOGBRUSH*	pLogbrush ) ;
	/**
		CdBrushProp�I�u�W�F�N�g����A LOGBRUSH �\���̂֕ϊ����܂��B
		�����́AtoLOGBRUSH �Ɠ����ł�
	
	 @retval 
	 	�쐬����LOGBRUSH�\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD 
		LOGBRUSH LOGBRUSHOf( const CdBrushProp& aCdBrushProp ) 
	{
		LOGBRUSH	aLOGBRUSH ;
		toLOGBRUSH( aCdBrushProp , &aLOGBRUSH ) ;
		return ( aLOGBRUSH ) ;
	};

	/**
		 LOGBRUSH �\���̂̓��e���ACdBrushProp�I�u�W�F�N�g�֕ϊ����܂��B
	 @param aLOGBRUSH [in]
	 	LOGBRUSH�\���̂��w�肵�Ă��������B
	 @param pCdBrushProp [out]
	 	���̊֐��͂��̃I�u�W�F�N�g�\���̂ɁA�������������݂܂��B
	*/
	CConverter_WinGdi_METHOD void toCdBrushProp( 
			const LOGBRUSH&	aLOGBRUSH ,
			CdBrushProp* pCdBrushProp ) ;

	/**
		�X�g�b�N�I�u�W�F�N�g�̑������A
		CdBrushProp�I�u�W�F�N�g�֕ϊ����܂��B
	 @param fnObject [in]
	 	GetStockObject() �Ŏw�肷��A�X�g�b�N�t�H���g�I�u�W�F�N�g
		�̒萔���w�肵�Ă��������B
	 @param pCdBrushProp [out]
	 	���̊֐��͂��̃I�u�W�F�N�g�\���̂ɁA�������������݂܂��B
	*/
	CConverter_WinGdi_METHOD void toCdBrushProp( 
			int fnObject ,
			CdBrushProp* pCdBrushProp ) ;
	
	/**
		 LOGBRUSH �\���̂̓��e���ACdBrushProp�I�u�W�F�N�g�֕ϊ����܂��B
		�����́AtoCdBrushProp �Ɠ����ł�
	 @param aLOGBRUSH [in]
	 	LOGBRUSH�\���̂��w�肵�Ă��������B
	 @return
	 	 CdBrushProp �\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD CdBrushProp CdBrushPropOf( 
			const LOGBRUSH&	aLOGBRUSH )
	{
		CdBrushProp	rv ;
		toCdBrushProp( aLOGBRUSH , &rv ) ;
		return ( rv ) ;
	};
	/**
		 �X�g�b�N�I�u�W�F�N�g�̑�����
		CdBrushProp�I�u�W�F�N�g�֕ϊ����܂��B
	 @param fnObject [in]
	 	GetStockObject() �Ŏw�肷��A�X�g�b�N�t�H���g�I�u�W�F�N�g
		�̒萔���w�肵�Ă��������B
	 @return
	 	 CdBrushProp �\���̂�Ԃ��܂��B
	*/
	CConverter_WinGdi_METHOD CdBrushProp CdBrushPropOf( 
						int fnObject )
	{
		CdBrushProp	rv ;
		toCdBrushProp( fnObject , &rv ) ;
		return ( rv ) ;
	};

	/**
	 	CdBrushProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 @param aCdBrushProp [in]
	 	�y���������w�肵�Ă��������B
	 @return
		�y���̃n���h����Ԃ��܂��B
		���̃n���h���̔j���̐Ӗ��́A�֐��ďo���ɂ���܂��B
		�֐��ďo���́A�n���h�����s�v�ɂȂ����� DeleteObject() ��
		�n���h����������Ȃ��Ă͂Ȃ�܂���B
	*/
	CConverter_WinGdi_METHOD 
		HBRUSH	CreateBrush(  const CdBrushProp& aCdBrushProp ) ;
	
	/**
	 	CdBrushProp�I�u�W�F�N�g�̑��������ƂɁA�u���V�𐶐����܂�
	 @param aCdBrushProp [in]
	 	�u���V�������w�肵�Ă��������B
	 @return
		�u���V�̃n���h����ێ����� CGdiHBrushHolder ��Ԃ��܂��B
		�n���h���̐����ɂ����ꍇ�́ANULL�ł��B
	*/
	CConverter_WinGdi_METHOD 
		Ou<CGdiHBrushHolder> createGdiHBrushHolder( 
			const CdBrushProp& aCdBrushProp ) ;
	///@}
	// ********************************
	///@name	�_�����W�ƃf�o�C�X���W�̕ϊ�	
	// ********************************
	///@{
	/**
		�f�o�C�X���W��_�����W�֕ϊ����܂�
	 @param value [in] 
		�ϊ��O�̍��W�l���w�肵�Ă��������B
	 @param hdc [in] 
		�f�o�C�X�R���e�L�X�g�̃n���h�����w�肵�܂��B 
	 */
	CConverter_WinGdi_METHOD 
		CdDcdPosXy DPtoLP( const CdDcdPosXy& value , HDC hDc ) ;  

	/**
		�_�����W���f�o�C�X���W�֕ϊ����܂�
	 @param value [in] 
		�ϊ��O�̍��W�l���w�肵�Ă��������B
	 @param hdc [in] 
		�f�o�C�X�R���e�L�X�g�̃n���h�����w�肵�܂��B 
	 */
	CConverter_WinGdi_METHOD 
		CdDcdPosXy LPtoDP( const CdDcdPosXy& value , HDC hDc ) ;  

	/**
		�f�o�C�X���W��_�����W�֕ϊ����܂�
	 @param value [in] 
		�ϊ��O�̍��W�l���w�肵�Ă��������B
	 @param hdc [in] 
		�f�o�C�X�R���e�L�X�g�̃n���h�����w�肵�܂��B 
	 */
	CConverter_WinGdi_METHOD 
		CdDcdSizeXy DPtoLP( const CdDcdSizeXy& value , HDC hDc ) ;  

	/**
		�_�����W���f�o�C�X���W�֕ϊ����܂�
	 @param value [in] 
		�ϊ��O�̍��W�l���w�肵�Ă��������B
	 @param hdc [in] 
		�f�o�C�X�R���e�L�X�g�̃n���h�����w�肵�܂��B 
	 */
	CConverter_WinGdi_METHOD 
		CdDcdSizeXy LPtoDP( const CdDcdSizeXy& value , HDC hDc ) ;  


	/**
		�f�o�C�X���W��_�����W�֕ϊ����܂�
	 @param value [in] 
		�ϊ��O�̍��W�l���w�肵�Ă��������B
	 @param hdc [in] 
		�f�o�C�X�R���e�L�X�g�̃n���h�����w�肵�܂��B 
	 */
	CConverter_WinGdi_METHOD 
		CdDcdZoneXy DPtoLP( const CdDcdZoneXy& value , HDC hDc ) ;  

	/**
		�_�����W���f�o�C�X���W�֕ϊ����܂�
	 @param value [in] 
		�ϊ��O�̍��W�l���w�肵�Ă��������B
	 @param hdc [in] 
		�f�o�C�X�R���e�L�X�g�̃n���h�����w�肵�܂��B 
	 */
	CConverter_WinGdi_METHOD 
		CdDcdZoneXy LPtoDP( const CdDcdZoneXy& value , HDC hDc ) ;  
	///@}
};
// ****************************************************************
//	���ʊ֐�
// ****************************************************************
/**
 *	�w��̃f�o�C�X �� HDC �� 
 *	GetDeviceCaps() �̒l�̂��������L�q����
 *	��������쐬���܂��B
 *	���̕�����͉ǃe�L�X�g�ł���A
 *	�f�o�b�O�ȊO�̎g�����͂���܂���B
 *
 * @param hDc [in]
 *	�ΏۂƂȂ�f�o�C�X�� HDC ���w�肵�Ă��������B
 * @return
 *	�������Ԃ��܂��B
 *
 *	�ΏۂƂȂ�f�o�C�X�̑����l�́A�ȉ��̂��̂ł��B
 *
 *	- TECHNOLOGY
 *	- HORZSIZE
 *	- VERTSIZE
 *	- HORZRES
 *	- VERTRES
 *	- LOGPIXELSX
 *	- LOGPIXELSY
 *	- PHYSICALWIDTH
 *	- PHYSICALHEIGHT
 *	- PHYSICALOFFSETX
 *	- PHYSICALOFFSETY
 */	
std::string	DeviceCapsToString( HDC hDc ) ;

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*CConverter_WinGdi_h*/


