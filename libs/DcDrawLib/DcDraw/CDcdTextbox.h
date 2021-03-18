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
//	CDcdTextbox.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdTextbox_h
#define  CDcdTextbox_h
#include <string>
#include "str/tstring.h"

#include "DcDraw\CDcdFillrect.h"
#include "DcDraw\CDcdRectangle.h"
#include "DcDraw\CDcdText.h"
#include "DcdCd\DcDrawProp\CdPenProp.h"

#include <string>

namespace DcDrawLib{
namespace DcDraw{

// ****************************************************************
//	CDcdTextbox
// ****************************************************************
/**
 * @brief
 * �y�T�v�z
 * 	   DcDraw���f���ɂ�����A�w�i�F���E�g���Ńe�L�X�g�̕`����s��
 *	�A�C�e���ł��B
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
 *	�R�D  �g�̈�̓����ɁA���� m_CdDrawTextProp �ŁA
 *	�e�L�X�g m_strText ��`�悵�܂��B
 *
 *	<H4>
 * �y���̃N���X�̑����z
 *	</H4>
 *	  ���̃N���X�̑����́A���ۂɂ͂��̃N���X����܂���I�u�W�F�N�g
 *	m_CDcdFillrect , m_CDcdRectangle , m_CDcdText �̑����ƂȂ�܂��B
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
 *	CdDrawTextProp	m_CdDrawTextProp ;
 *	</H5>
 *	�e�L�X�g��`�悷��ۂ̑�����ێ����܂��B
 *
 *	<H5>
 *	tstring			m_strExtent;
 *	</H5>
 *	���̕`�敔�i�̑傫���̖ڈ��ƂȂ�
 *	������ł�
 *	getItemSize() �́A���̕������\���ł��镝��Ԃ��܂��B
 *	�ȗ�������AstrText�Ɠ����Ƃ݂Ȃ��܂��B
 *
 * <H5>
 *	int	m_iLinesExtent ;
 * </H5>
 *	���̕`�敔�i�̑傫���̍s���ł� getItemSize() �́A
 *	���̍s����\���ł��鍂����Ԃ��܂��B 
 *	getItemSize() ���g��Ȃ��̂ł���΁A���̑����͎g���܂���B
 *	�f�t�H���g�͂P�ł��B 
 *
 * <H5>
 *	CdBrushProp	m_CdBrushProp ;
 * </H5>
 *	�h��Ԃ��Ɏg�p����u���V�̑����B
 *
 * @note
 *	CDcdRectangleText��CDcdTextbox �̈Ⴂ�́A�y���̑�����
 *	SOLID�łȂ��ꍇ�ɖ��炩�ɂȂ�܂��B
 *	���̂Ƃ��A CDcdRectangleText �ł́A�g���̕`�悳��Ȃ�������DC�̔w�i�F��
 *	�Ȃ�܂����A CDcdTextbox �̏ꍇ�́A�g���̕`�悳��Ȃ�������
 *	���߃��[�h�Ƃ��܂��i�܂�A�w�i�u���V�����f����܂��j�B
 */
class CDcdTextbox : public IfDcDraw
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
	 *	CDcdText::m_strText ,
	 *	CDcdText::m_CdDrawTextProp ,
	 *	CDcdText::m_strExtent ,
	 *	CDcdText::m_iLinesExtent 
	 *	�́A���̃N���X�̃����o�֐��o�R�ő���ł��܂��B
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
	
///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	* @param strText [in]
	*	�`�悷�镶����ł��B
	* @param aCdDrawTextProp [in]
	*	�e�L�X�g��`�悷��ۂ̑�����ێ����܂��B
	* @param strExtent [in]
	*	���̕`�敔�i�̑傫���̖ڈ��ƂȂ�
	*	������ł�
	*	getItemSize() �́A���̕������\���ł��镝��Ԃ��܂��B
	*	�ȗ�������AstrText�Ɠ����Ƃ݂Ȃ��܂��B
	* @param iLinesExtent [in]
	*	���̕`�敔�i�̑傫���̍s���ł�
	*	getItemSize() �́A���̍s����\���ł��鍂����Ԃ��܂��B
	*	�ȗ�������A�P�Ƃ݂Ȃ��܂��B
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
	*/
	CDcdTextbox( 
		const tstring&			strText  ,
		const CdDrawTextProp&	aCdDrawTextProp ,
		const tstring&			strExtent = TEXT( "" ) ,
		int						iLinesExtent = 1 ,
		int						logicalunitFrameWidth  = 0 ,
		int						logicalunitFrameHeight = 0  ,
		const CdPenProp&		aCdPenProp = CdPenProp() ,
		const CdBrushProp& 		aCdBrushProp = CdBrushProp() );

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
	* @param aCdDrawTextProp [in]
	*	�e�L�X�g��`�悷��ۂ̑�����ێ����܂��B
	* @param strExtent [in]
	*	���̕`�敔�i�̑傫���̖ڈ��ƂȂ�
	*	������ł�
	*	getItemSize() �́A���̕������\���ł��镝��Ԃ��܂��B
	*	�ȗ�������AstrText�Ɠ����Ƃ݂Ȃ��܂��B
	* @param iLinesExtent [in]
	*	���̕`�敔�i�̑傫���̍s���ł�
	*	getItemSize() �́A���̍s����\���ł��鍂����Ԃ��܂��B
	*	�ȗ�������A�P�Ƃ݂Ȃ��܂��B
	* @param aCdBrushProp [in]
	*	�h��Ԃ��Ɏg�p����u���V�̑������w�肵�Ă��������B
	*	�ȗ�������ANULLBRUSH�Ƃ݂Ȃ��܂��B
	*/
	CDcdTextbox( 
		const CdPenProp&		aCdPenProp ,
		int						logicalunitFrameWidth  = 0 ,
		int						logicalunitFrameHeight = 0  ,
		const tstring&			strText = TEXT( "" ) ,
		const CdDrawTextProp&	aCdDrawTextProp = CdDrawTextProp() ,
		const tstring&			strExtent = TEXT( "" ) ,
		int						iLinesExtent = 1 ,
		const CdBrushProp& 		aCdBrushProp = CdBrushProp() );



	CDcdTextbox() ;
	
	virtual ~CDcdTextbox() ;

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
//	CDcdTextbox
// ********************************
 public:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	 * @return
	 *	�g���Ɏg���y���̑����B
	 */
	virtual CdPenProp	getCdPenProp(){	
		return m_CDcdRectangle.getCdPenProp()	;	} ;
	virtual CDcdTextbox& setCdPenProp( const CdPenProp& ev ){
		m_CDcdRectangle.setCdPenProp( ev ) ;	return *this ;}

	virtual int	getFrameWidth(){	return m_logicalunitFrameWidth ;};
	virtual CDcdTextbox& setFrameWidth( int ev ){
		m_logicalunitFrameWidth = ev ;	return *this ; } ;

	virtual int	getFrameHeight(){	return m_logicalunitFrameHeight ;};
	virtual CDcdTextbox&  setFrameHeight( int ev ){
		m_logicalunitFrameHeight = ev ;	return *this ; } ;
	
	/**
	 * @return
	 *	�`�悷�镶����ł��B
	 */
	virtual tstring			getText(){	
		return m_CDcdText.getText() ;	} ;
	virtual CDcdTextbox& setText( const tstring& ev ){	
		m_CDcdText.setText( ev ) ; 	return *this ; } ;
	/**
	 * @return
	 *	�e�L�X�g��`�悷��ۂ̑�����ێ����܂��B
	 */
	virtual CdDrawTextProp	getCdDrawTextProp(){
		return m_CDcdText.getCdDrawTextProp() ;};
	virtual CDcdTextbox& setCdDrawTextProp( 
			const CdDrawTextProp& ev ){
		m_CDcdText.setCdDrawTextProp( ev ) ; 	return *this ; } ;
	/**
	 * @return
	 *	���̕`�敔�i�̑傫���̖ڈ��ƂȂ�
	 *	������ł�
	 *	getItemSize() �́A���̕������\���ł��镝��Ԃ��܂��B
	 *	getItemSize() ���g��Ȃ��̂ł���΁A���̑����͎g���܂���B
	 */
	virtual tstring			getExtent(){
		return m_CDcdText.getExtent() ; } ;
	virtual CDcdTextbox&  setExtent( const tstring& ev ){
		m_CDcdText.setExtent( ev ) ;	return *this ; };
	/**
	 * @return
	 *	���̕`�敔�i�̑傫���̍s���ł�
	 *	getItemSize() �́A���̍s����\���ł��鍂����Ԃ��܂��B
	 *	getItemSize() ���g��Ȃ��̂ł���΁A���̑����͎g���܂���B
	 */
	virtual int				getLinesExtent(){
		return m_CDcdText.getLinesExtent() ; } ;
	virtual CDcdTextbox& setLinesExtent( int ev ){
		m_CDcdText.setLinesExtent( ev ) ; 	return *this ; } ;

	/**
	 * @return
	 *	�h��Ԃ��Ɏg�p����u���V�̑����B
	 */
	virtual CdBrushProp	getCdBrushProp(){	
		return m_CDcdFillrect.getCdBrushProp()	;	} ;
	virtual CDcdTextbox& setCdBrushProp( const CdBrushProp& ev ){
		m_CDcdFillrect.setCdBrushProp( ev ) ;	return *this ;}
	///@}
	
	
};

} //namespace DcDraw
} //namespace DcDrawLib

#endif /*CDcdTextbox_h*/
