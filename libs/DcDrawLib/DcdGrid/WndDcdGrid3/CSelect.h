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
//	CSelect.h
//$Id: CSelect.h 296 2016-06-11 05:40:21Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdGrid_WndDcdGrid3_CSelect_h
#define  DcDraw_DcdGrid_WndDcdGrid3_CSelect_h

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>
#include "NsOu\Ou.h"
#include "DcDraw\IfDcDraw.h"
#include "DcdGrid\WndDcdGrid3\CSelectCell.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{
	
class CPropStack ;

// ****************************************************************
//	WndDcdGrid3::CSelect
// ****************************************************************
/**
@brief
	CWndDcdGrid ��CellSelect(�Z���I��)���N���X���������̂ł��B

 WndDcdGrid3::CWndDcdGrid ��̂��ׂẴZ���I����Ԃ�ێ�����N���X�ł��B
 �Z���P�̑I����Ԃ�ێ����� CSelectCell ���A�Z���̐������W�񂵂܂��B
 
 ���̃N���X�́A CWndDcdGrid  �������I�ɐ������邽�߂ɑ��݂��܂��B
����ȊO�̗��p���l�͂���܂���B

 �y�g�����z

(1) ���̃N���X�̃I�u�W�F�N�g�́A WndDcdGrid3::CWndDcdGrid �Ő�������܂��B
WndDcdGrid3::CWndDcdGrid::getCSelect() �ŁA�I�u�W�F�N�g�ɃA�N�Z�X�ł��܂��B

(2) �@WndDcdGrid3::CSelect::getCell() ���\�b�h�ŁA�Z���̑I���󋵂�
�\�� WndDcdGrid3::CSelectCell �I�u�W�F�N�g���擾���邱�Ƃ��ł��܂��B
 WndDcdGrid3::CSelectCell::setIsSelected() ���\�b�h��p���邱�Ƃɂ��A
�Z����I����Ԃɂ��邱�Ƃ��ł��܂��B

*/
class CSelect
{
	friend class CWndDcdGrid ;
public:
	// ****************************************************************
	//	CWndDcdGrid::CSelect::ESelectMode
	// ****************************************************************
	/**
		CWndDcdGrid�̃Z���I���̃��[�h��\���܂��B
	*/
	enum ESelectMode
	{ 
		/// (�f�t�H���g)�I���͕s�\�ł��B(CSelectCell::m_bIsSelected �͖���)
		SelectMode_NONE , 	
		/// X��EY�񗼕��̑I�����\�ł��B
		SelectMode_XY , 
		/// X��̑I���̂݉\�ł��BY��͏펞�S��I���ƂȂ�܂��B
		SelectMode_XColumn , 
		/// Y��̑I���̂݉\�ł��BX��͏펞�S��I���ƂȂ�܂��B
		SelectMode_YColumn ,
	};
protected:
	// --------------------------------
	//	�C���i�[�^�C�v
	// --------------------------------
	typedef	std::deque< CSelectCell* > CSelectYColumnCellCont ;
	typedef	std::deque< CSelectYColumnCellCont* > CSelectCellCont ;
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		�O���́A CWndDcdGrid �ւ̊֘A�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
		�R���X�g���N�^�Ō��܂�܂��B
	 */
	CWndDcdGrid*	m_pCWndDcdGrid ;

	/**
		�I���Z���ɑ΂��āA�I���}�[�N��`�悷��
		DcDraw �I�u�W�F�N�g�ł��B
	 */
	Ou<IfDcDraw>	m_pIfDcDrawSelect ;
	///@}

private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�I���}�[�N�̕`��̈�Ɍr�����܂߂邩�ۂ��̎w��ł��B
		- true: �I���}�[�N�̕`��̈�ɁA�Z���̉E���A�����̌r�����܂߂܂��B
			��ԍ��E���̌r��(�O���b�h�S�̂̍��E���̌r��)�͔͈͂Ɋ܂߂܂���B
		- false: �I���}�[�N�̕`��̈�ɁA�Z���̉E���A�����̌r�����܂߂܂���B

		����l�� true �ł��B
	*/
	bool m_bIncludeRbBorder ;

	/**
		CWndDcdGrid�̃Z���I���̃��[�h��\���܂��B
		����l�́A SelectMode_NONE �ł��B
	*/
	ESelectMode	m_eSelectMode ;

	/**
		�I���\�����͈́B
		�P�ʂ̓Z���ԍ��ł��B

		���̑����́A�Z���̐����傫���l���Ƃ邱�Ƃ��ł��܂��B@n
		(m_ColumnNumberSelectLimit.getX().getEndPos()
			>CDcdGrid::getXColumnCount()
		�ɂȂ邱�Ƃ��ł��܂��BY������l�ł��B)

		�I���\�Ȕ͈́B�f�t�H���g�́AX,Y�Ƃ� 
		Pos�� 0 �ASize��INT_MAX�ƂȂ�܂��B
	*/
	CdDcdZoneXy	m_ColumnNumberSelectLimit ;

	/**
	@brief CWndDcdGrid�S�̂̍X�V�̗L��/����

	  �Z���I���̕ύX���� CWndDcdGrid �S�̂��X�V���邩�ۂ����w�肵�܂��B

	  - true: (�f�t�H���g)�Z���I��(CSelectCell::m_bIsSelected)�̕ύX���ɁA
	  	CWndDcdGrid �S�̂��X�V���܂�( CWndDcdGrid::update())���Ăяo��)�B
	  - false: �Z���I��(CSelectCell::m_bIsSelected)�̕ύX���ɂ��A 
	  	CWndDcdGrid �S�̂̍X�V�͍s���܂���B

	  ������ false ���� true �ɕύX�����ꍇ�́ACWndDcdGrid �S�̂��X�V���܂��B

	  �u�Z���I���̕ύX���v�́A
	  	CSelectCell::m_bIsSelected �̕ω������w���܂��B
	*/
	bool m_bUpdateCWndDcdGrid ;

	///@}
 private:
	// ********************************
	///	@name �W��
	// ********************************
	///@{
	/**
	  	�Z���I�u�W�F�N�g��ێ�����R���e�i�ł��B
	  	
	  	���̃R���e�i�̗v�f���́AYColumn �̐��ɓ������Ȃ�܂��B
	  	���̃R���e�i�̊e�v�f�́A XColumn ���� CDcdGridCell ��ێ�����
	  	�R���e�i�ł��B
	  	
	  	���������āA
	  
	  	m_CDcdGridCellCont[Y��ԍ�][X��ԍ�]
	  
	  	�̌`���ŁA�Ή����� CDcdGridCell �I�u�W�F�N�g�ɃA�N�Z�X���ł��܂��B
	  
	  	�R���e�i���̃I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
	 */
	CSelectCellCont 	m_CSelectCellCont ;
	///@}
public:
	// ********************************
	///@name �萔
	// ********************************
	///@{
	///@}

private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
		CWndDcdGrid�̃Z���I���̃��[�h�̑O��l�B
		update_updateScreen() �ōX�V����܂��B
		
		���̑����́Am_eSelectMode �� SelectMode_NONE �̂Ƃ��ɁA
		���̃N���X�̏������y�ʉ����邽�߂Ɏg�p���܂��B
		
		m_eSelectMode �� SelectMode_NONE �ɕύX���ꂽ�ꍇ�́A
		�S�Ă̑I���Z�����������܂��B
		
		m_eSelectMode �� SelectMode_NONE �ł���Ԃ́A
		update_adjustProp()�Eupdate_updateScreen()�EOnPaint()��
		���������Ƀ��^�[�����܂��B
		
	*/
	ESelectMode	m_eSelectMode_Prev ;

	/**
		�I������Ă���Z���̐��B
		update_adjustProp() �ōX�V����܂��B
	*/
	int	m_iSelectedCellCount ;

	///@}

protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{


	/**
	  setYColumnCount() �� insertYColumn() �̉����֐��ł��B

	  Y����P�A�w��̈ʒu�ɒǉ����܂��B
	  ���̊֐��́A 
	    m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	    m_CDcdGridCellCont
	�̑����������s���܂��B
	adjustProp() �͍s���܂���B

	@param iYColumnNumber [in]
		  Y��ԍ����w�肵�Ă��������B
		�V�����ǉ����ꂽY�񂪁A����Y��ԍ��ɂȂ�܂��B
		�͈͂� 0 �ȏ� getYColumnNumber() �ȉ��ŁA
		0 �Ȃ�擪�EgetYColumnNumber() �Ȃ疖���ւ̒ǉ��ƂȂ�܂��B
		  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-2 ;	//	�C���f�N�X���s��
	 */
	int insertYColumn_insertColumnCell( int iYColumnNumber ) ;

	/**
	  setXColumnCount() �� insertXColumn() �̉����֐��ł��B

	  X����P�A�w��̈ʒu�ɒǉ����܂��B
	  ���̊֐��́A 
	    m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	    m_CDcdGridCellCont
	�̑����������s���܂��B
	  adjustProp() �͍s���܂���B

	@param iXColumnNumber [in]
		X��ԍ����w�肵�Ă��������B
		�V�����ǉ����ꂽX�񂪁A����X��ԍ��ɂȂ�܂��B
		�͈͂� 0 �ȏ� getXColumnNumber() �ȉ��ŁA
		0 �Ȃ�擪�EgetXColumnNumber() �Ȃ疖���ւ̒ǉ��ƂȂ�܂��B
		  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-2 ;	//	�C���f�N�X���s��
	 */
	int insertXColumn_insertColumnCell( int iXColumnNumber ) ;
	
	/**
  	setYColumnCount() �� eraseYColumn() �̉����֐��ł��B
  
  	Y����P�A�폜���܂��B
  	���̊֐��́A 
  	m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
  	m_CDcdGridCellCont
  	�̑����������s���܂��B
  	adjustProp() �͍s���܂���B

	@param iYColumnNumber [in]
  		Y��ԍ����w�肵�Ă��������B
  		�͈͂� 0 �ȏ� getYColumnNumber() �����ł��B
  		  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	@return
	  	����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	   -	-2 ;	//	�C���f�N�X���s��
	 */
	int eraseYColumn_eraseColumnCell( int iYColumnNumber ) ;

	/**
	setXColumnCount() �� eraseXColumn() �̉����֐��ł��B

	X����P�A�폜���܂��B
	���̊֐��́A 
	m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	m_CDcdGridCellCont
	�̑����������s���܂��B
	adjustProp() �͍s���܂���B

	@param iXColumnNumber [in]
	  	X��ԍ����w�肵�Ă��������B
	  	�͈͂� 0 �ȏ� getXColumnNumber() �����ł��B
	  	  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	@return
	  	����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	   -	-2 ;	//	�C���f�N�X���s��
	 */
	int eraseXColumn_eraseColumnCell( int iXColumnNumber ) ;

	/**
	�Z���I��ύX���́ACPropStack �C���X�^���X�𐶐����܂��B
	���̃I�u�W�F�N�g�́A�������Ԓ��͈ȉ��̑�����ݒ肵�܂��B

	- CSelect::m_bUpdateCWndDcdGrid = false

	 ����ɂ���āA�Z���I��ύX���̕`����œK�����܂��B
	 (�����̃Z���̑I����ύX����ꍇ�́A���̑�����false�ɂ�����Ԃ�
	 �Z���̑I����Ԃ�ύX���Ă���A���̑�����true�ɂ���
	 ��ʂ��ĕ`�悷��ق����A�������悭�Ȃ�܂��B) 
	*/
	Ou<CPropStack> createPropStackForSelectChange() ;

	///@}
protected:
	// --------------------------------
	///@name WndDcdGrid3::CDcdGrid ����̈Ϗ�
	// --------------------------------
	///@{
	/**
  	  this �́A�V���� Column ���������ꂽ����ɁA���̊֐����Ăяo���܂��B
  	  �V���� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g
  	�̐����E�o�^���͂��߂Ƃ������������s���܂��B
  
  	���̊֐����I�[�o���C�h���邱�Ƃɂ��A Column �ɓ��L�̏�������
  	�s�����Ƃ��ł��܂��B
  	
	@param iXColumnNumber [in]
	  	  �V���� Column �̗�ԍ��ł��B
	@param pCDcdGridXColumn [in,out]
	  	  �V�����������ꂽ CDcdGridXColumn �I�u�W�F�N�g�ł��B
	  	  ���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA���������s�����Ƃ��ł��܂��B
	  	
	[�I�[�o���C�h]
		 CSelectCell �I�u�W�F�N�g�̒ǉ��E�폜���s���܂��B
	 */
	virtual void OnCreateXColumn( int iXColumnNumber ) ;
	
	/**
	  this �́AColumn ���j������钼�O�ɁA���̊֐����Ăяo���܂��B
	  �j������� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g��
	�o�^�����E�j�����͂��߂Ƃ�����n�����s���܂��B

	���̊֐����I�[�o���C�h���邱�Ƃɂ��A Column �ɓ��L�̌�n����
	�s�����Ƃ��ł��܂��B
	  	
	@param iXColumnNumber [in]
	  	  �j������� Column �̗�ԍ��ł��B
	  	
	[�I�[�o���C�h]
	   CSelectCell �I�u�W�F�N�g�̒ǉ��E�폜���s���܂��B
	 */
	virtual void OnDeleteXColumn( int iXColumnNumber ) ;

	/**
	  this �́A�V���� Column ���������ꂽ����ɁA���̊֐����Ăяo���܂��B
	  �V���� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g
	�̐����E�o�^���͂��߂Ƃ������������s���܂��B

	  ���̊֐����I�[�o���C�h���邱�Ƃɂ��A Column �ɓ��L�̏�������
	�s�����Ƃ��ł��܂��B
	  	
	@param iYColumnNumber [in]
	  �V���� Column �̗�ԍ��ł��B

	[�I�[�o���C�h]
	   CSelectCell �I�u�W�F�N�g�̒ǉ��E�폜���s���܂��B
	 */
	virtual void OnCreateYColumn( int iYColumnNumber ) ;
	
	/**
	  this �́AColumn ���j������钼�O�ɁA���̊֐����Ăяo���܂��B
	  �j������� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g��
	�o�^�����E�j�����͂��߂Ƃ�����n�����s���܂��B

	    ���̊֐����I�[�o���C�h���邱�Ƃɂ��A Column �ɓ��L�̌�n����
	�s�����Ƃ��ł��܂��B

	@param iYColumnNumber [in]
		�j������� Column �̗�ԍ��ł��B

	[�I�[�o���C�h]
	   CSelectCell �I�u�W�F�N�g�̒ǉ��E�폜���s���܂��B
	 */
	virtual void OnDeleteYColumn( int iYColumnNumber ) ;

	///@}
protected:
	// --------------------------------
	///@name CWndDcdGrid ����̈Ϗ�
	// --------------------------------
	///@{
	/**
		CWndDcdGrid::update() �̉����֐��ł��B
	
		- �����̕␳
		- CSelectCell �ւ̈Ϗ�

		���s���܂��B

	�y1.�����̕␳�z

	1.ColumnNumberSelectLimit�ɂ��ACSelectCell::m_bIsSelected �̐��K���B

	1.1.m_eSelectMode �� SelectMode_NONE �̏ꍇ�A
	���ׂẴZ�����I���ɂ��܂��B

	1.2.m_eSelectMode �� SelectMode_XColumn �̏ꍇ�A
	����X��ԍ�(�c����)�̃Z���̑I���󋵂����ׂē���ɂ��܂��B

	1.2.1.�����ꂩ�̃Z���� CSelectCell::m_bIsSelected ��true�ɕύX����Ă�����A
	���ׂẴZ����true�ɂ��܂��B

	1.2.2.�����ꂩ�̃Z���� CSelectCell::m_bIsSelected ��false�ɕύX����Ă�����A
	���ׂẴZ����false�ɂ��܂��B

	1.2,3.�Z���̑I���󋵂��ύX����Ă��Ȃ��ꍇ�́A
	�S�ẴZ���̑I���󋵂��Am_ColumnNumberSelectLimit.getY().getPos() ��
	�I���󋵂Ɠ����ɂ��܂��B

	1.3. m_eSelectMode �� SelectMode_YColumn �̏ꍇ�A
	����Y��ԍ�(������)�̃Z���̑I���󋵂����ׂē���ɂ��܂��B
	���K���̕��@�́A SelectMode_XColumn �Ɠ��l�ł��B

	2.ColumnNumberSelectLimit�ɂ��ACSelectCell::m_bIsSelected �̐��K���B

	2.1.m_ColumnNumberSelectLimit �ȊO�̗̈悪�I������Ă����ꍇ��
	���̑I�����������܂��B
	
	 @return 
		���K���̌��ʁA���炩�̒l��ω��������ꍇ�͐^�ł��B
	 */
	bool update_adjustProp() ;

	/**
	CWndDcdGrid::update() �̉����֐��ł��B
	�����̕ω����A��ʏ�ɔ��f���܂��B

	CSelectCell::update_updateScreen() �ւ̈Ϗ����s���܂��B

	CSelectCell::update_updateScreen() �́Am_bIsSelected ��
	�ύX���ꂽ��A�Z���̗̈�𖳌������A�X�V���w�����܂��B
		
	@return 
		���炩�̒l�̕ω�����ʏ�ɔ��f�������ꍇ�͐^�ł��B
	 */
	bool update_updateScreen() ;


	/**
	CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

	�`���v�����܂��B
	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B

	@param pIfDcdTarget  [in]
	 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 	CWndDcdGrid�̃N���C�A���g�̈�� IfDcdTarget ���w�肵�Ă��������B
	@return
	 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	*/
	virtual bool OnPaint( IfDcdTarget* pIfDcdTarget ) ;

	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		���̃N���X�ł́A�����͂���܂���B
	*/
	void OnSize(UINT nType, int cx, int cy);

	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		���̃N���X�ł́A�����͂���܂���B
	*/
	void OnSetFocus(CWnd* pOldWnd);
	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		���̃N���X�ł́A�����͂���܂���B
	*/
	void OnKillFocus(CWnd* pNewWnd);
	/**
		CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

		�����͂���܂���
	 */
	virtual void InvalidateGrid( ) ;


	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	@param pCWndDcdGrid [in]
		�O���́A CWndDcdGrid �ւ̊֘A�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	 */
	CSelect( CWndDcdGrid* pCWndDcdGrid ) ;
	virtual ~CSelect() ;
public:
	// ********************************
	///@name CSelect �֘A
	// ********************************
	///@{
	CWndDcdGrid*	getCWndDcdGrid() ;
	Ou<IfDcDraw>	getIfDcDrawSelect() ;
	void setIfDcDrawSelect( Ou<IfDcDraw> value ) ;
	///@}


	// ********************************
	///@name CSelect ����
	// ********************************
	///@{
	bool getIncludeRbBorder()const ;
	void setIncludeRbBorder( bool ev )  ;
	ESelectMode	getSelectMode()const ;
	void setSelectMode( ESelectMode	value ) ;
	CdDcdZoneXy	getColumnNumberSelectLimit()const ;
	void setColumnNumberSelectLimit( const CdDcdZoneXy& value ) ;

	/**
	@return
		�I���\�����͈́B�P�ʂ̓Z���ԍ��ł��B
		�߂�l�́A�񐔈ȓ��ɐ��K������܂��B
		(�߂�l��
		CdDcdZoneXy::getX().getEndPos() �́A
		CDcdGrid::getXColumnCount() �ȉ��ɐ��K�����܂��B
	*/
	CdDcdZoneXy	getColumnNumberSelectLimitRegularized()const ;
 
	bool getUpdateCWndDcdGrid()const ;
	void setUpdateCWndDcdGrid( bool ev ) ;

	///@}
	// ********************************
	///@name CSelect �W��
	// ********************************
	///@{
	/**
	  	  �w�肳�ꂽY��EX��ԍ��́A�Z���I�u�W�F�N�g CSelectCell �̃|�C���^��
	  	�擾���邱�Ƃ��ł��܂��B���̃|�C���^���g���āA�Z���ɑ΂��鑀���
	  	�s�����Ƃ��ł��܂��B
	   @param iXColumnNumber [in] 
	  	 X��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getXColumnCount() �����ł��B
	   @param iYColumnNumber [in] 
	  	 Y��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getYColumnCount() �����ł��B
	   @return
	  	  �Ή�����Z���I�u�W�F�N�g��Ԃ��܂��B
	  	  �C���f�N�X���s���ȏꍇ�́ANULL��Ԃ��܂��B
	  
	  	  �Ԃ��ꂽ�I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
	  	  �Y������X�� CDcdGrid �̕ʂ̃��\�b�h�ɂ���č폜�����ƁA�Ԃ��ꂽ
	  	�|�C���^�͖����ɂȂ�܂��B
	  	   this���j�����ꂽ�Ƃ��ɂ��A�Ԃ��ꂽ�|�C���^�͖����ɂȂ�܂��B
	 */
	virtual CSelectCell*	getCell( int iXColumnNumber , int iYColumnNumber );
 

	/**
		�w��� CSelectCell �I�u�W�F�N�g�́A��ԍ���Ԃ��܂��B
	@param pCSelectCell [in]
		CDcdGridCell �I�u�W�F�N�g���w�肵�Ă��������B
	@return
		X��ԍ���Ԃ��܂��B
		�I�u�W�F�N�g�� CDcdGrid �I�u�W�F�N�g�ɏW�񂳂�Ă��Ȃ��ꍇ�́A
		INT_MIN �ł��B
	*/
	virtual int getXColumnNumberOfCell( 
		CSelectCell* pCSelectCell ) ;
	/**
		�w��� CSelectCell �I�u�W�F�N�g�́A��ԍ���Ԃ��܂��B
	@param pCSelectCell [in]
		CDcdGridCell �I�u�W�F�N�g���w�肵�Ă��������B
	@return
		Y��ԍ���Ԃ��܂��B
		�I�u�W�F�N�g�� CDcdGrid �I�u�W�F�N�g�ɏW�񂳂�Ă��Ȃ��ꍇ�́A
		INT_MIN �ł��B
	*/
	virtual int getYColumnNumberOfCell( 
		CSelectCell* pCSelectCell ) ;
	///@}
	// ********************************
	///@name CSelect ����
	// ********************************
	///@{
	

	/**
	�w��̃Z���̑I��\�����s���͈͂��A
	�_���P��(�ʏ�̓s�N�Z���B�N���C�A���g���W)�ŕԂ��܂��B

	@param pIfDcdTarget [in]
		�`��Ώۂ��w�肵�Ă��������B
	@param iXColumnNumber [in]
		�Z���̗�ԍ����w�肵�Ă��������B
	@param iYColumnNumber [in]
		�Z���̗�ԍ����w�肵�Ă��������B
	@param bIncludeRbBorder [in]
		true �Ȃ�A�͈͂ɁA�Z���̉E���A�����̌r�����܂߂܂��B
	@return 
		�Z���̑I��\���͈̔͂�Ԃ��܂��B
	@attention
		��ԍ��E���̌r��(�O���b�h�S�̂̍��E���̌r��)�͔͈͂Ɋ܂߂܂���B
	*/
	virtual CdDcdZoneXy getZoneOfCellSelection(
		IfDcdTarget* pIfDcdTarget , 
		int iXColumnNumber , int iYColumnNumber , bool bIncludeRbBorder ) ;

	/**
		�S�ẴZ����I�����܂��B
	*/
	virtual void selectAll() ;
	/**
		�S�ẴZ���̑I�����������܂��B
	*/
	virtual void clearSelect() ;

	/**
	@return 
		�I������Ă���Z���̐���Ԃ��܂��B
	*/
	int getSelectedCellCount()const ;

	/**
	@return 
		m_eSelectMode �� SelectMode_XColumn �̏ꍇ�A
		�I������Ă����̐���Ԃ��܂��B

		m_eSelectMode �� SelectMode_XColumn �ȊO�̏ꍇ��0�ł��B
	*/
	int getSelectedXColumnCount()const ;

	/**
	@return 
		m_eSelectMode �� SelectMode_YColumn �̏ꍇ�A
		�I������Ă����̐���Ԃ��܂��B

		m_eSelectMode �� SelectMode_YColumn �ȊO�̏ꍇ��0�ł��B
	*/
	int getSelectedYColumnCount()const ;

	/**
	  m_eSelectMode �� SelectMode_XColumn �̏ꍇ�A
	�w��̗� Index �̑I����Ԃ��擾���܂��B

	@param iColumnNumber [in]
	  	 X��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getXColumnCount() �����ł��B
	@return 
		�񂪑I������Ă���� true �B

		m_eSelectMode �� SelectMode_XColumn �ȊO�̏ꍇ�A
		���̃��\�b�h�͖����ł��B
	*/
	bool getXColumnNumberSelected( int iColumnNumber ) ;

	/**
	  m_eSelectMode �� SelectMode_XColumn �̏ꍇ�A
	�w��̗� Index �̑I����Ԃ�ݒ肵�܂��B
	  ���̃��\�b�h�ɂ��A�w�肳�ꂽ��̃Z���� 
	CSelectCell::m_bIsSelected �������ς��܂�

	@param iColumnNumber [in]
	  	 X��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getXColumnCount() �����ł��B
	@param bIsSelected [in]
		�I������ꍇ�� true �A �I����������ꍇ�� false �B

		m_eSelectMode �� SelectMode_XColumn �ȊO�̏ꍇ�A
		���̃��\�b�h�͖����ł��B
	*/
	void setXColumnNumberSelected( int iColumnNumber , bool bIsSelected ) ;

	/**
	  m_eSelectMode �� SelectMode_XColumn , SelectMode_YColumn �̏ꍇ�A
	�w��̗� Index �̑I����Ԃ��擾���܂��B

	@param iColumnNumber [in]
	  	 Y��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getYColumnCount() �����ł��B
	@return 
		�񂪑I������Ă���� true �B

		m_eSelectMode �� SelectMode_YColumn �ȊO�̏ꍇ�A
		���̃��\�b�h�͖����ł��B
	*/
	bool getYColumnNumberSelected( int iColumnNumber ) ;

	/**
	  m_eSelectMode �� SelectMode_YColumn �̏ꍇ�A
	  �w��̗� Index �̑I����Ԃ�ݒ肵�܂��B
	  ���̃��\�b�h�ɂ��A�w�肳�ꂽ��̃Z���� 
	CSelectCell::m_bIsSelected �������ς��܂�

	@param iColumnNumber [in]
	  	Y��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getYColumnCount() �����ł��B
	@param bIsSelected [in]
		�I������ꍇ�� true �A �I����������ꍇ�� false �B

		m_eSelectMode �� SelectMode_YColumn �ȊO�̏ꍇ�A
		���̃��\�b�h�͖����ł��B
	*/
	void setYColumnNumberSelected( int iColumnNumber , bool bIsSelected ) ;

	///@}


};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif //DcDraw_DcdGrid_WndDcdGrid3_CSelect_h
