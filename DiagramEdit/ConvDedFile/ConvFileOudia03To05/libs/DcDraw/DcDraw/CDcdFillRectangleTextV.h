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
//	CDcdFillRectangleTextV.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdFillRectangleTextV_h
#define  CDcdFillRectangleTextV_h
#include <string>
using namespace std ;
#include "str/tstring.h"

#include "DcDraw/CDcdFillrect.h"
#include "DcDraw/CDcdRectangle.h"
#include "DcDraw/CDcdText.h"
#include "DcDraw/CdPenProp.h"
#include "DcDraw/CConverter_WinGdi.h"

#include <string>

// ****************************************************************
//	CDcdFillRectangleTextV
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 * 	   DcDraw���f���ɂ�����A�`��A���S���Y�������������I�u�W�F�N�g�ł��B
 *	  �c�����̓��{����������t�H���g�ŕ`�悵�܂��B
 *	  �w�i�F���E�g���ł��B
 *
 *	  ���̃N���X�ł́ADcDraw�Ŏw�肳�ꂽ�̈�̊O�ӂ��㉺���E�ɁA
 *
 *		- m_logicalunitFrameWidth 
 *		- m_logicalunitFrameHeight 
 *	
 *	���̘g�̈���m�ۂ��A���̓����� m_strText �̃e�L�X�g���������݂܂��B
 *
 *	  ���̃I�u�W�F�N�g�ɑ΂��� DcDraw() ���Ăяo���ƁA�ȉ��̏������s���܂��B
 *
 *	�P�D  �܂��A�̈�S�̂��A�u���V���� m_CdBrushProp �œh��Ԃ��܂��B
 *
 *	�Q�D  �̈�̊O�ӓ����ɁA�w��̃y������ m_CdPenProp �Řg����
 *	�`�悵�܂��B
 *
 *	�R�D  �g�̈�̓����ɁA
 *	�e�L�X�g m_strText ��`�悵�܂��B
 *
 *	<H4>
 * �y���̃N���X�̑����z
 *	</H4>
 *	  ���̃N���X�̑����́A���ۂɂ͂��̃N���X����܂���I�u�W�F�N�g
 *	m_CDcdFillrect , m_CDcdRectangle , m_CDcdText �̑����ƂȂ�܂��B
 *
 * <H5>
 *	CdBrushProp	m_CdBrushProp ;
 * </H5>
 *	�h��Ԃ��Ɏg�p����u���V�̑����B
 *
 *	<H5>
 *	CdPenProp	m_CdPenProp
 *	</H5>
 *	�g����`�悷�邽�߂̃y���̑����B
 *
 *	<H5>
 *	int	m_logicalunitFrameWidth ;
 *	</H5>
 *	�e�L�X�g�̍��E�̘g�̈�̑������A�_���P�ʂŕێ����܂��B
 *	�����E�E�����ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
 *
 *	<H5>
 *	int	m_logicalunitFrameHeight ;
 *	</H5>
 *	�e�L�X�g�̏㉺�̘g�̈�̑������A�_���P�ʂŕێ����܂��B
 *	�㑤�E�������ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
 *
 *	<H5>
 *	tstring			m_strText ;
 *	</H5>
 *	�`�悷�镶����ł��B
 *
 *	<H5>
 *	CdFontProp	m_CdFontProp ;
 *	</H5>
 *	�e�L�X�g��`�悷��ۂ̃t�H���g��ێ����܂��B
 *
 *	<H5>
 *	COLORREF	m_colorrefText ;
 *	</H5>
 *	�e�L�X�g��`�悷��ꍇ�̕����F�ł��B
 *	�f�t�H���g�͍��ł��B
 *
 *	
 * <H5>
 *	int	m_iLinesExtentX ;
 * </H5>
 *	���̕`�敔�i�ɕ\���ł���AX�����i�������j�̕�������ێ����܂��B
 *	�ڍׂ́A m_iLinesExtentY �̐������Q�Ƃ��Ă��������B
 *
 * <H5>
 *	int	m_iLinesExtentY ;
 * </H5>
 *	���̕`�敔�i�ɕ\���ł���AY�����i�c�����j�̕�������ێ����܂��B
 *
 *	 getItemSize() �́A �ȉ��̒l��Ԃ��܂��B
 *	-	X������ m_strExtent ��X�����̃T�C�Y�~m_LinesExtectX 
 *	-	Y������ m_strExtent ��Y�����̃T�C�Y�~m_LinesExtectY 
 *
 *
 *	<H5>
 *	tstring			m_strExtent;
 *	</H5>
 *	�P�s�̕��̖ڈ��ƂȂ镶���̕��ł��B
 *	�����ɂ͒ʏ�A�S�p�̊����P�������w�肵�Ă��������B
 *	�ȗ�������A"��" �P�����Ƃ݂Ȃ��܂��B
 *
 *
 */
class CDcdFillRectangleTextV : public IfDcDraw
{
// --------------------------------
///@name	���
// --------------------------------
///@{
 private:
	/**
	 *	�w�i��`�悷��I�u�W�F�N�g�ł��B
	 *
	 *	���̃I�u�W�F�N�g�̑��� CDcdFillrect::m_CdBrushProp �́A
	 *	���̃N���X�̃����o�֐��o�R�ő���ł��܂��B
	 */
	CDcdFillrect		m_CDcdFillrect ;
	/**
	 *	�g����`�悷��I�u�W�F�N�g�ł��B
	 *
	 *	���̃I�u�W�F�N�g�̑��� CDcdRectangle::m_CdPenProp �́A
	 *	���̃N���X�̃����o�֐��o�R�ő���ł��܂��B
	 */
	CDcdRectangle		m_CDcdRectangle ;
	
	/**
	 *	�e�L�X�g��`�悷��I�u�W�F�N�g�ł��B
	 *
	 *	���̃I�u�W�F�N�g�̑��� 
	 *	CDcdText::m_CdDrawTextProp::m_CdFontProp ,
	 *	CDcdText::m_CdDrawTextProp::m_colorrefText ,
	 *	CDcdText::m_strExtent ,
	 *
	 *	�́A���̃N���X�̃����o�֐��o�R�ő���ł��܂��B
	 *
	 *	���̃I�u�W�F�N�g�̑��� CDcdText::m_strText �ɂ́A
	 *	�L���Ȓl������܂���B
	 *	���̒l�́ADcDraw() �̂Ƃ��ɁAm_strText �̓��e���P�������Z�b�g����
	 *	�`�悵�܂��B
	 */
	CDcdText			m_CDcdText ;
///@}
// ********************************
/// @name ����
// ********************************
///@{
 private:
	/**
	*	�e�L�X�g�̍��E�̘g�̈�̑������A�_���P�ʂŕێ����܂��B
	*	�����E�E�����ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
	*/
	int	m_logicalunitFrameWidth ;

	/**
	*	�e�L�X�g�̏㉺�̘g�̈�̑������A�_���P�ʂŕێ����܂��B
	*	�㑤�E�������ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
	*/
	int	m_logicalunitFrameHeight ;
	
	/**
	 *	�`�悷�镶����ł��B
	 */
	tstring			m_strText ;

	/**
	 *	�e�L�X�g��`�悷��ۂ̃t�H���g��ێ����܂��B
	CdFontProp	m_CdFontProp ;
	 */
	
	/**
	 *	���̕`�敔�i�ɕ\���ł���AX�����i�������j�̕�������ێ����܂��B
	 *	�ڍׂ́A m_iLinesExtentY �̐������Q�Ƃ��Ă��������B
	 */
	int	m_iLinesExtentX ;

	/**
	 *	���̕`�敔�i�ɕ\���ł���AY�����i�c�����j�̕�������ێ����܂��B
	 *
	 *	 getItemSize() �́A �ȉ��̒l��Ԃ��܂��B
	 *	-	X������ m_strExtent ��X�����̃T�C�Y�~m_LinesExtectX 
	 *	-	Y������ m_strExtent ��Y�����̃T�C�Y�~m_LinesExtectY 
	 *
	 */
	int	m_iLinesExtentY ;

///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 * @param strText [in]
	 *	�`�悷�镶����ł��B
	 * @param aCdFontProp [in]
	 *	�e�L�X�g��`�悷��ۂ̃t�H���g��ێ����܂��B
	 * @param iLinesExtentX [in]
	 *	���̕`�敔�i�ɕ\���ł���AX�����i�������j�̕�������ێ����܂��B
	 * @param iLinesExtentY [in]
	 *	���̕`�敔�i�ɕ\���ł���AY�����i�c�����j�̕�������ێ����܂��B
	 *	 getItemSize() �́A �ȉ��̒l��Ԃ��܂��B
	 *	-	X������ m_strExtent ��X�����̃T�C�Y�~m_LinesExtectX 
	 *	-	Y������ m_strExtent ��Y�����̃T�C�Y�~m_LinesExtectY 
	 * @param colorrefText [in]
	 *	�e�L�X�g��`�悷��ꍇ�̕����F�ł��B
	 * @param logicalunitFrameWidth [in]
	 *	�e�L�X�g�̍��E�̘g�̈�̑������A�_���P�ʂŎw�肵�Ă��������B
	 *	�����E�E�����ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
	 * @param logicalunitFrameHeight [in]
	 *	�e�L�X�g�̏㉺�̘g�̈�̑������A�_���P�ʂŎw�肵�Ă��������B
	 *	�㑤�E�������ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
	 *	logicalunitFrameHeight �������ȗ������ꍇ�́A logicalunitFrameWidth 
	 *	�Ɠ����ł���Ƃ݂Ȃ���܂��B
	 *	logicalunitFrameHeight �E logicalunitFrameWidth �̗�����
	 *	�ȗ������ꍇ�́A �O �Ƃ݂Ȃ��܂�
	 * @param aCdPenProp [in]
	 *	�g����`�悷�邽�߂̃y���̑���
	 * @param aCdBrushProp [in]
	 *	�h��Ԃ��Ɏg�p����u���V�̑������w�肵�Ă��������B
	 *	�ȗ�������ANULLBRUSH�Ƃ݂Ȃ��܂��B
	 * @param strExtent [in]
	 *	�ȗ�������A"��" �P�����Ƃ݂Ȃ��܂��B
	 *	�P�s�̕��ƍ����̖ڈ��ƂȂ镶���̕��ł��B
	 *	�����ɂ͒ʏ�A�S�p�̊����P�������w�肵�Ă��������B
	 */
	CDcdFillRectangleTextV( 
		const tstring&			strText  ,
		const CdFontProp&	aCdFontProp ,
		int						iLinesExtentX ,
		int						iLinesExtentY ,
		COLORREF	colorrefText = RGB( 0 , 0 , 0 ) , 
		int						logicalunitFrameWidth  = 0 ,
		int						logicalunitFrameHeight = 0  ,
		const CdPenProp&		aCdPenProp = CdPenProp() ,
		const CdBrushProp& 		aCdBrushProp = CdBrushProp() ,
		const tstring&			strExtent = TEXT( "" ) ) ;

	/**
	 *	��̃R���X�g���N�^�Ƃ́A�����̏����������قȂ�܂��B
	 * @param aCdPenProp [in]
	 *	�g����`�悷�邽�߂̃y���̑���
	 * @param logicalunitFrameWidth [in]
	 *	�e�L�X�g�̍��E�̘g�̈�̑������A�_���P�ʂŎw�肵�Ă��������B
	 *	�����E�E�����ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
	 * @param logicalunitFrameHeight [in]
	 *	�e�L�X�g�̏㉺�̘g�̈�̑������A�_���P�ʂŎw�肵�Ă��������B
	 *	�㑤�E�������ꂼ��ɁA���̃T�C�Y�̕����m�ۂ��܂��B
	 *	logicalunitFrameHeight �������ȗ������ꍇ�́A logicalunitFrameWidth 
	 *	�Ɠ����ł���Ƃ݂Ȃ���܂��B
	 *	logicalunitFrameHeight �E logicalunitFrameWidth �̗�����
	 *	�ȗ������ꍇ�́A �O �Ƃ݂Ȃ��܂�
	 * @param strText [in]
	 *	�`�悷�镶����ł��B
	 * @param aCdFontProp [in]
	 *	�e�L�X�g��`�悷��ۂ̃t�H���g��ێ����܂��B
	 * @param iLinesExtentX [in]
	 *	���̕`�敔�i�ɕ\���ł���AX�����i�������j�̕�������ێ����܂��B
	 * @param iLinesExtentX [in]
	 *	���̕`�敔�i�ɕ\���ł���AY�����i�c�����j�̕�������ێ����܂��B
	 *	 getItemSize() �́A �ȉ��̒l��Ԃ��܂��B
	 *	-	X������ m_strExtent ��X�����̃T�C�Y�~m_LinesExtectX 
	 *	-	Y������ m_strExtent ��Y�����̃T�C�Y�~m_LinesExtectY 
	 * @param aCdBrushProp [in]
	 *	�h��Ԃ��Ɏg�p����u���V�̑������w�肵�Ă��������B
	 *	�ȗ�������ANULLBRUSH�Ƃ݂Ȃ��܂��B
	 * @param strExtent [in]
	 *	�ȗ�������A"��" �P�����Ƃ݂Ȃ��܂��B
	 *	�P�s�̕��ƍ����̖ڈ��ƂȂ镶���̕��ł��B
	 *	�����ɂ͒ʏ�A�S�p�̊����P�������w�肵�Ă��������B
	 */
	CDcdFillRectangleTextV( 
		const CdPenProp&		aCdPenProp ,
		int						logicalunitFrameWidth  = 0 ,
		int						logicalunitFrameHeight = 0  ,
		const tstring&			strText = TEXT( "" ) ,
		const CdFontProp&	aCdFontProp = CdFontProp() ,
		int						iLinesExtentX = 1 ,
		int						iLinesExtentY = 1 ,
		COLORREF	colorrefText = RGB( 0 , 0 , 0 ) , 
		const CdBrushProp& 		aCdBrushProp = CdBrushProp() ,
		const tstring&			strExtent = TEXT( "" ) ) ;



	CDcdFillRectangleTextV() ;
	
	virtual ~CDcdFillRectangleTextV() ;

// ********************************
///@name	IfDcDraw
// ********************************
///@{
 public:
	/**
	* 	�`���v�����܂��B
	* 	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B
	*
	*	�y�I�[�o���C�h�z
	*	  �n���ꂽ�̈�ɁA m_strText ��`�悵�܂��B
	* @param pIfDcdTarget  [in]
	* 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	* @return
	* 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	*/
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	* 	���̃I�u�W�F�N�g���`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	* 	���̑傫���𒲂ׂ邱�Ƃ��ł��܂��B
	* 	�֐��Ăяo������������ IfDcDraw �I�u�W�F�N�g��`�悷��ꍇ�ɂ́A
	* 	�֐��Ăяo�����́A���̊֐��ŃA�C�e���̑傫���𒲂ׂāA
	* 	�K�؂ȃ��C�A�E�g���l���Ă���ADcDraw() �����s���邱�Ƃ��ł��܂��B
	*
	*	�y�I�[�o���C�h�z
	*	  Extent �� LinesExtent �����ƂɌv�Z�����e�L�X�g�̈�̃T�C�Y��
	*	m_logicalunitFrameWidth ,m_logicalunitFrameHeight �������āA
	*	�̈�̃T�C�Y���v�Z���܂��B
	* @param pIfDcdTarget [in]
	* 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	* @param pCdDcdSizeXy [out]
	* 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	* 	���̊֐��͂��̃A�h���X�ɁA���̃A�C�e���̃T�C�Y��Ԃ��܂��B
	* 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��Ȃ��ꍇ�́A
	* 	���̒l�͕s��ł��B
	* @return
	* 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��āA
	* 	���̑傫���� *pCDcdSizeXy�ɏ������񂾏ꍇ�͐^�ł��B
	* 	�����łȂ��ꍇ�́A�U�ł��B
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
///@}
// ********************************
//	CDcdFillRectangleTextV
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 * @return
	 *	�h��Ԃ��Ɏg�p����u���V�̑����B
	 */
	virtual CdBrushProp	getCdBrushProp(){	
		return m_CDcdFillrect.getCdBrushProp()	;	} ;
	virtual CDcdFillRectangleTextV& setCdBrushProp( const CdBrushProp& ev ){
		m_CDcdFillrect.setCdBrushProp( ev ) ;	return *this ;}
	/**
	 * @return
	 *	�g���Ɏg���y���̑����B
	 */
	virtual CdPenProp	getCdPenProp(){	
		return m_CDcdRectangle.getCdPenProp()	;	} ;
	virtual CDcdFillRectangleTextV& setCdPenProp( const CdPenProp& ev ){
		m_CDcdRectangle.setCdPenProp( ev ) ;	return *this ;}

	virtual int	getFrameWidth(){	return m_logicalunitFrameWidth ;};
	virtual CDcdFillRectangleTextV& setFrameWidth( int ev ){
		m_logicalunitFrameWidth = ev ;	return *this ; } ;

	virtual int	getFrameHeight(){	return m_logicalunitFrameHeight ;};
	virtual CDcdFillRectangleTextV&  setFrameHeight( int ev ){
		m_logicalunitFrameHeight = ev ;	return *this ; } ;
	
	virtual tstring			getText(){	
		return m_strText ;	} ;
	virtual CDcdFillRectangleTextV& setText( const tstring& ev ){	
		m_strText = ev ; 	return *this ; } ;

	virtual CdFontProp	getCdFontProp(){
		return m_CDcdText.getCdDrawTextProp().getCdFontProp() ;};
	virtual CDcdFillRectangleTextV& setCdFontProp( 
			const CdFontProp& ev ){
		CdDrawTextProp	aCdDrawTextProp = m_CDcdText.getCdDrawTextProp() ;
		aCdDrawTextProp.setCdFontProp( ev ) ;
		m_CDcdText.setCdDrawTextProp( aCdDrawTextProp ) ; return *this ; } ;

	virtual COLORREF	getTextColor()
	{	
		CConverter_WinGdi	aConv ;
		return aConv.COLORREFOf( m_CDcdText.getCdDrawTextProp().getTextColor() );	
	};
	virtual CDcdFillRectangleTextV& setTextColor( COLORREF ev )
	{
		CdDrawTextProp	aCdDrawTextProp = m_CDcdText.getCdDrawTextProp() ;
		CConverter_WinGdi	aConv ;
		aCdDrawTextProp.setTextColor( aConv.CdColorPropOf( ev ) ) ;
		m_CDcdText.setCdDrawTextProp( aCdDrawTextProp ) ; return *this ; 
	} ;

	virtual int				getLinesExtentX(){
		return m_iLinesExtentX ; } ;
	virtual CDcdFillRectangleTextV& setLinesExtentX( int ev ){
		m_iLinesExtentX = ev ; 	return *this ; } ;
	virtual int				getLinesExtentY(){
		return m_iLinesExtentY ; } ;
	virtual CDcdFillRectangleTextV& setLinesExtentY( int ev ){
		m_iLinesExtentY = ev ; 	return *this ; } ;

	virtual tstring			getExtent(){
		return m_CDcdText.getExtent() ; } ;
	virtual CDcdFillRectangleTextV&  setExtent( const tstring& ev ){
		m_CDcdText.setExtent( ev ) ;	return *this ; };
	///@}
	
	
};


#endif /*CDcdFillRectangleTextV_h*/
