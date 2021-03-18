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
//	CaDcdTargetZoomDisplay.h
// ****************************************************************
*/
/** @file */
#ifndef  CaDcdTargetZoomDisplay_h
#define  CaDcdTargetZoomDisplay_h

#include <windows.h>
#include "DcDraw/IfDcdTarget.h"
//#include "CDcdTargetMfcPrintInfo.h"


// ****************************************************************
//	CaDcdTargetZoomDisplay
// ****************************************************************
/**
 * @brief
 *	�y�T�v�z
 *   ���/����v���r���[�̕`��̈�ł��� IfDcdTarget �I�u�W�F�N�g��
 * �^�[�Q�b�g�Ƃ���A�A�_�v�^�N���X�ł��B�^�[�Q�b�g��DC�ɁA
 * �f�B�X�v���C�ɏ������_�����W��ݒ肵�܂��B
 * 
 * <H4>
 * �y���W�n�ɂ��āz
 * </H4>
 *  �^�[�Q�b�g�I�u�W�F�N�g�ƂȂ� IfDcdTarget �I�u�W�F�N�g�� DC ��
 * ���W�n�́A����̏ꍇ������v���r���[�̏ꍇ���A
 *   �v�����^�̂P�h�b�g���P�_���P�� 
 * �łȂ��Ă͂Ȃ�܂���B
 * 
 *   ���̃N���X�́A�ΏۂƂȂ� DC �̍��W�n���A�f�B�X�v���C��ʂ�
 * ���������̂ɕύX���܂��B
 *   ���Ƃ��΁A 
 * 
 * 	�f�B�X�v���C��DPI�F�v�����^��DPI �� �P�F�S 
 * 
 * �̏ꍇ�́A���̃N���X��DC�̃}�b�s���O���[�h��ύX���āA
 * 
 * 	�P�_���P�ʁF�v�����^�̂S�h�b�g
 * 
 * �ƂȂ�悤�ɂ��܂��B
 *   ����ɂ��AIfDcDraw �I�u�W�F�N�g�ɂ��̃I�u�W�F�N�g��n����
 * �`�悷��ƁA�قډ�ʂ̑傫���ɏ�����������ʂ𓾂邱�Ƃ��ł��܂��B
 * 
 * <H4>
 * �y�g�����z
 * </H4>
 * 
 * �P�D  ���炩���߁A ���/����v���r���[�̕`��̈�ł��� IfDcdTarget 
 * �I�u�W�F�N�g�𐶐����Ă��Ȃ��Ă͂Ȃ�܂���B
 * 
 * �Q�D  �R���X�g���N�^�ł́A�^�[�Q�b�g��IfDcdTarget �ƁA�v�����^��DC��
 * �w�肵�Ă��������B�v�����^�� DC �́ADPI�̌v�Z���s���ꍇ�ɕK�v�ł��B
 *   �R���X�g���N�^�́A�w�肳�ꂽ DC ����v�����^��DPI���擾���āA
 * ���̌v�Z�����ƂɃ}�b�s���O���[�h��ύX���܂��B
 * 
 * �R�D  ���̃I�u�W�F�N�g�� IfDcDraw �C���^�[�t�F�[�X�ɓn���āA�`���
 * �s�����Ƃ��ł��܂��B
 * 
 * �S�D  ���̃N���X�̃f�X�g���N�^�́A�Q�D�ŕύX�����}�b�s���O���[�h��
 * ���ɖ߂��܂��B
 */
class CaDcdTargetZoomDisplay : public IfDcdTarget 
{
// ********************************
///@name �֘A
// ********************************
///@{
 private:
	/**
	 *  �^�[�Q�b�g�I�u�W�F�N�g�ł��B
	 *
	 *	���/����v���r���[�̕`��̈�ł��� IfDcdTarget �I�u�W�F�N�g�ł��B
	 *
	 *	 �^�[�Q�b�g�I�u�W�F�N�g�ƂȂ� IfDcdTarget �I�u�W�F�N�g�� DC ��
	 *	���W�n�́A����̏ꍇ������v���r���[�̏ꍇ���A
	 *	�v�����^�̂P�h�b�g���P�_���P�� �łȂ��Ă͂Ȃ�܂���B
	 *	
	 *	  ���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
	 *	  ���̃I�u�W�F�N�g�́Athis ���j�������܂ł͐������Ȃ��Ă͂Ȃ�܂���B
	 *	
	 *	  �R���X�g���N�^�Ō��܂�܂��B
	 */
	IfDcdTarget* m_pTarget ;

	/**
	 *  �v�����^�� DC �ւ̃n���h���ł��B
	 *
	 *	����̏ꍇ�A
	   @code
	  	m_pTarget->getHdc() = �v�����^��DC
	 	this->m_hPrinterHdc = �v�����^��DC
	   @endcode
	 *	����v���r���[�̏ꍇ�A
	   @code
	 	m_pTarget->getHdc() = �v���r���[��ʂ�DC
	 	this->m_hPrinterHdc = �v�����^��DC
	   @endcode
	 *	�ƂȂ�܂��B
	 */
	HDC	m_hPrinterHdc ;
///@}
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	 * 	  �`��̕K�v�ȗ̈�̍��W�͈́B
	 *	  �`��̈�̍��W�l�́A���̃N���X�ɂ��A�}�b�v���[�h���f�B�X�v���C��
	 *	���������̂ɕύX����Ă��܂��B
	 *	
	 *	�R���X�g���N�^�Ō��܂�܂��B
	 */
	CdDcdZoneXy	m_zonexyZone ;
	
	
///@}

// --------------------------------
///@name �����f�[�^
// --------------------------------
///@{
 private:
	/**
	 *	�R���X�g���N�^�ɂ�����ASaveDC() �̖߂�l��ۑ����܂��B
	 *	SaveDC() �����s�����ꍇ�́A 0 �ƂȂ�܂��B
	 */
	int	m_iSaveDcId ;
///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param pTarget [in]
	 *  �^�[�Q�b�g�I�u�W�F�N�g�ł��B@n
	 *	���/����v���r���[�̕`��̈�ł��� IfDcdTarget �I�u�W�F�N�g�ł��B@n
	 *	 �^�[�Q�b�g�I�u�W�F�N�g�ƂȂ� IfDcdTarget �I�u�W�F�N�g�� DC ��
	 *	���W�n�́A����̏ꍇ������v���r���[�̏ꍇ���A
	 *	�v�����^�̂P�h�b�g���P�_���P�� �łȂ��Ă͂Ȃ�܂���B@n
	 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
	 *	���̃I�u�W�F�N�g�́Athis ���j�������܂ł͐������Ȃ��Ă͂Ȃ�܂���B
	 * @param hPrinterHdc [in]
	 *  �v�����^�� DC �ւ̃n���h���ł��B@n
	 *	���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
	 *	���̃I�u�W�F�N�g�́Athis ���j�������܂ł͐������Ȃ��Ă͂Ȃ�܂���B
	 */
	CaDcdTargetZoomDisplay( 
		IfDcdTarget* pTarget ,
		HDC	hPrinterHdc ) ;
	virtual ~CaDcdTargetZoomDisplay() ; 

// ********************************
///@name	IfDcdTarget
// ********************************
///@{
 public:
	/**
	 * @return
	 * 	�`����s��DC���擾���܂��B
	 * 	����HDC�̔j���̐Ӗ��́Athis�ɂ���܂��B
	 *
	 *	�y�I�[�o���C�h�z
	 *
	 *	����̏ꍇ�A���̊֐����Ԃ��̂� �v�����^��DC�ł��B
	 *	����v���r���[�̏ꍇ�́A���̊֐����Ԃ��̂́A�v���r���[��ʂ�DC�ł��B
	 *
	 *	����v���r���[�̏ꍇ�́A�v�����^��DC�� getPrinterHdc() �Ŏ擾�ł��܂��B
	 */
	virtual HDC	getHdc() ;
	
	/**
	 * @return
	 * 	�`��̕K�v�ȗ̈�̍��W�͈͂��擾���邱�Ƃ��ł��܂��B
	 * 	�P�ʂ́A�_���P�ʂł��B
	 */
	virtual CdDcdZoneXy getZone() ;
	
	/**
	 * @return
	 * 	�`�悪�L���Ȕ͈͂��擾�ł��܂��B
	 * 	�ʏ�́AgetZone()�Ɠ����̈�ƂȂ�܂��B
	 * 
	 * 	�E�C���h�E��WM_PAINT�ɂ��`��̏ꍇ�A���̊֐����Ԃ��̂́A
	 * 	�ĕ`�悪�K�v�ȗ̈�ƂȂ�܂��B
	 * 	���̗̈�𖳎����Ă����܂��܂���B�������A���͈̔͊O�ւ̕`���
	 * 	�Ӗ�������܂���̂ŁA���͈̔͊O�ւ̕`���}������悤�ɂ���΁A
	 * 	�`�揈���̌����̉��P�����҂ł��܂��B
	 */
	virtual CdDcdZoneXy getDrawableZone() ;

	/**
	 	CdFontProp�I�u�W�F�N�g�̑��������ƂɁA�t�H���g�𐶐����܂�
	 @param aCdFontProp [in]
	 	�t�H���g�������w�肵�Ă��������B
	 @return
		�t�H���g�̃n���h����ێ����� CGdiHFontHolder ��Ԃ��܂��B
	*/
	virtual Ou<CGdiHFontHolder>	createGdiHFontHolder(  const CdFontProp& aCdFontProp )
	{
		return m_pTarget->createGdiHFontHolder( aCdFontProp ) ;
	};
	
	/**
	 	CdPenProp�I�u�W�F�N�g�̑��������ƂɁA�y���𐶐����܂�
	 @param aCdPenProp [in]
	 	�y���������w�肵�Ă��������B
	 @return
		�y���̃n���h����ێ����� CGdiHPenHolder ��Ԃ��܂��B
	*/
	virtual  Ou<CGdiHPenHolder>		createGdiHPenHolder(  const CdPenProp& aCdPenProp ) 
	{
		return m_pTarget->createGdiHPenHolder( aCdPenProp ) ;
	};

	/**
	 	CdBrushProp�I�u�W�F�N�g�̑��������ƂɁA�u���V�𐶐����܂�
	 @param aCdBrushProp [in]
	 	�u���V�������w�肵�Ă��������B
	 @return
		�u���V�̃n���h����ێ����� CGdiHBrushHolder ��Ԃ��܂��B
	*/
	virtual Ou<CGdiHBrushHolder>	createGdiHBrushHolder(  const CdBrushProp& aCdBrushProp ) 
	{
		return m_pTarget->createGdiHBrushHolder( aCdBrushProp ) ;
	};

///@}
// ********************************
//	CaDcdTargetZoomDisplay_h
// ********************************
 public:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	///@}
};


#endif /*CaDcdTargetZoomDisplay_h*/
