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
//	CXDcdGrid.h
//	$Id: CXDcdGrid.h 387 2016-11-20 08:43:33Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  DcDraw_DcdGrid_WndDcdGrid3_CXDcdGrid_h
#define  DcDraw_DcdGrid_WndDcdGrid3_CXDcdGrid_h

#include "DcdGrid\CDcdGrid.h"
#include "WinUtil\CdScrollbarProp.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

// ****************************************************************
//	WndDcdGrid3::CXDcdGrid
// ****************************************************************
/**
@brief
	CWndDcdGrid �ɕ�܂����ACDcdGrid �ł��B
	
	���̃N���X�́A CWndDcdGrid  �������I�ɐ������邽�߂ɑ��݂��܂��B
	����ȊO�̗��p���l�͂���܂���B
	this �́ACDcdGrid �̃I�[�o���C�h�\�ȉ��z�֐��Ăяo�����A
	�O���� CWndDcdGrid �ɈϏ����܂��B
 */
class CXDcdGrid : public CDcdGrid
{
	friend class CWndDcdGrid ;

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
	///@}
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	@brief�@CWndDcdGrid�S�̂̍X�V�̗L��/����

	  �X�N���[���ʒu�̕ύX���� CWndDcdGrid �S�̂��X�V���邩�ۂ����w�肵�܂��B

	- true: (�f�t�H���g)�X�N���[���ʒu�̕ύX���ɁACWndDcdGrid �S�̂��X�V���܂�( CWndDcdGrid::update())���Ăяo��)�B
	- false: �X�N���[���ʒu�̕ύX���ɂ��A CWndDcdGrid �S�̂̍X�V�͍s���܂���B

	������ false ���� true �ɕύX�����ꍇ�́ACWndDcdGrid �S�̂��X�V���܂��B

	�u�X�N���[���ʒu�̕ύX���v�́A�ȉ��̃��\�b�h�Ăяo���̂��Ƃ��w���܂��B

	- WndDcdGrid3::CXDcdGrid::setXFixafterColumnNumber() , 
	- WndDcdGrid3::CXDcdGrid::setYFixafterColumnNumber(),
	- WndDcdGrid3::CXDcdGrid::setXFixColumnCount(),
	- WndDcdGrid3::CXDcdGrid::setYFixColumnCount() 
	*/
	bool m_bUpdateCWndDcdGrid ;
	///@}
private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/** 
		���݂̃X�N���[���o�[�̑�����ۑ����܂��B
		�����l�� NULL�ł��B
	
		���̒l�́A update_updateDisplay() ���ɁA�O��l��r���s���̂Ɏg���܂��B
		m_CFocus.m_iPos �́Am_iXFixafterColumnNumber �̑O��l�ƂȂ�܂��B

		�܂��AOnPaint() �ł��A�l���X�V���܂��B
	
		InvalidateGrid() �ł́A�����������l�ɖ߂��܂��B
	*/
	WinUtil::CdScrollbarProp	m_CdScrollbarPropX_Sid ;
	/** 
		���݂̃X�N���[���o�[�̑�����ۑ����܂��B
		�����l�� NULL�ł��B
	
		���̒l�́A update_updateDisplay() ���ɁA�O��l��r���s���̂Ɏg���܂��B
		m_CFocus.m_iPos �́Am_iXFixafterColumnNumber �̑O��l�ƂȂ�܂��B

		�܂��AOnPaint() �ł��A�l���X�V���܂��B
	
		InvalidateGrid() �ł́A�����������l�ɖ߂��܂��B
	*/
	WinUtil::CdScrollbarProp	m_CdScrollbarPropY_Sid ;
	///@}
public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CXDcdGrid( CWndDcdGrid* pCWndDcdGrid ) ;
	virtual ~CXDcdGrid() ;
	// ****************************************************************
	//	CDcdGrid
	// ****************************************************************
protected:
	// --------------------------------
	///@name CDcdGrid-�s�E��E�Z���̏�����
	// --------------------------------
	///@{
	/**
	this �́A�V���� Column ���������ꂽ����ɁA���̊֐����Ăяo���܂��B
	�V���� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g
	�̐����E�o�^���͂��߂Ƃ���
	���������s���܂��B

	���̊֐����I�[�o���C�h���邱�Ƃɂ��A Column �ɓ��L�̏�������
	�s�����Ƃ��ł��܂��B
		
	 @param iXColumnNumber [in]
		  �V���� Column �̗�ԍ��ł��B
	 @param pCDcdGridXColumn [in,out]
		  �V�����������ꂽ CDcdGridXColumn �I�u�W�F�N�g�ł��B
		  ���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA���������s�����Ƃ��ł��܂��B
		
	 [�I�[�o���C�h]
		�O���́A CWndDcdGrid ( m_pCWndDcdGrid )�ֈϏ����܂��B
		CWndDcdGrid::OnCreateXColumn() ���Ăяo���܂��B
	 */
	virtual void OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) ;
	
	/**
	this �́AColumn ���j������钼�O�ɁA���̊֐����Ăяo���܂��B
	�j������� Column �ɑ΂��āA
	 IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g��	
	�o�^�����E�j�����͂��߂Ƃ���
	��n�����s���܂��B

	���̊֐����I�[�o���C�h���邱�Ƃɂ��A Column �ɓ��L�̌�n����
	�s�����Ƃ��ł��܂��B
		
	 @param iXColumnNumber [in]
		  �j������� Column �̗�ԍ��ł��B
	 @param pCDcdGridXColumn [in,out]
		  �j������� CDcdGridXColumn �I�u�W�F�N�g�ł��B
		  ���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA��n�����s�����Ƃ��ł��܂��B
		
		
	 [�I�[�o���C�h]
		�O���́A CWndDcdGrid ( m_pCWndDcdGrid )�ֈϏ����܂��B
		CWndDcdGrid::OnDeleteXColumn() ���Ăяo���܂��B
	 */
	virtual void OnDeleteXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) ;

	/**
	this �́A�V���� Column ���������ꂽ����ɁA���̊֐����Ăяo���܂��B
	�V���� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g
	�̐����E�o�^���͂��߂Ƃ���
	���������s���܂��B

	���̊֐����I�[�o���C�h���邱�Ƃɂ��A Column �ɓ��L�̏�������
	�s�����Ƃ��ł��܂��B
		
	 @param iYColumnNumber [in]
		  �V���� Column �̗�ԍ��ł��B
	 @param pCDcdGridYColumn [in,out]
		  �V�����������ꂽ CDcdGridYColumn �I�u�W�F�N�g�ł��B
		  ���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA���������s�����Ƃ��ł��܂��B
		
		
	 [�I�[�o���C�h]
		�O���́A CWndDcdGrid ( m_pCWndDcdGrid )�ֈϏ����܂��B
		CWndDcdGrid::OnCreateYColumn() ���Ăяo���܂��B
	 */
	virtual void OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;
	
	/**
	this �́AColumn ���j������钼�O�ɁA���̊֐����Ăяo���܂��B
	�j������� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X
	�I�u�W�F�N�g��	
	�o�^�����E�j�����͂��߂Ƃ���
	��n�����s���܂��B

	���̊֐����I�[�o���C�h���邱�Ƃɂ��A Column �ɓ��L�̌�n����
	�s�����Ƃ��ł��܂��B
		
	 @param iYColumnNumber [in]
		  �j������� Column �̗�ԍ��ł��B
	 @param pCDcdGridYColumn [in,out]
		  �j������� CDcdGridYColumn �I�u�W�F�N�g�ł��B
		  ���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA��n�����s�����Ƃ��ł��܂��B
		
		
	 [�I�[�o���C�h]
		�O���́A CWndDcdGrid ( m_pCWndDcdGrid )�ֈϏ����܂��B
		CWndDcdGrid::OnDeleteYColumn() ���Ăяo���܂��B
	 */
	virtual void OnDeleteYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;

	/**
	this �́A�V���� Cell ���������ꂽ����ɁA���̊֐����Ăяo���܂��B
	�V���� Cell �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g
	�̐����E�o�^���͂��߂Ƃ���
	���������s���܂��B

	���̊֐����I�[�o���C�h���邱�Ƃɂ��A Cell �ɓ��L�̏�������
	�s�����Ƃ��ł��܂��B
		
	 @param iXColumnNumber [in]
		  �V���� Cell ��X��ԍ��ł��B
	 @param iYColumnNumber [in]
		  �V���� Cell ��Y��ԍ��ł��B
	 @param pCDcdGridCell [in,out]
		  �V�����������ꂽ CDcdGridCell �I�u�W�F�N�g�ł��B
		  ���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA���������s�����Ƃ��ł��܂��B
		
		
	 [�I�[�o���C�h]
		�O���́A CWndDcdGrid ( m_pCWndDcdGrid )�ֈϏ����܂��B
		CWndDcdGrid::OnCreateCell() ���Ăяo���܂��B
	 */
	virtual void OnCreateCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) ;
	
	/**
	this �́ACell ���j������钼�O�ɁA���̊֐����Ăяo���܂��B
	�j������� Cell �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g��
	�o�^�����E�j�����͂��߂Ƃ���
	��n�����s���܂��B

	���̊֐����I�[�o���C�h���邱�Ƃɂ��A Cell �ɓ��L�̌�n����
	�s�����Ƃ��ł��܂��B
		
	 @param iXColumnNumber [in]
		  �j������� Cell ��X��ԍ��ł��B
	 @param iYColumnNumber [in]
		  �j������� Cell ��Y��ԍ��ł��B
	 @param pCDcdGridCell [in,out]
		  �j������� CDcdGridCell �I�u�W�F�N�g�ł��B
		  ���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA��n�����s�����Ƃ��ł��܂��B
		
		
	 [�I�[�o���C�h]
		�O���́A CWndDcdGrid ( m_pCWndDcdGrid )�ֈϏ����܂��B
		CWndDcdGrid::OnDeleteCell() ���Ăяo���܂��B
	 */
	virtual void OnDeleteCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) ;
	///@}
public:
	// ********************************
	///	@name CDcdGrid-Y��EX��̐�
	// ********************************
	///@{
	/**
	 @return
		���݂�Y��̐���Ԃ��܂��B������Ԃł́A�O��Ԃ��܂��B
	 */
	virtual int		getYColumnCount() ;
	
	/**
	 @param ev [in]
		Y��̐����w�肵�Ă��������B
	 */
	virtual CDcdGrid& setYColumnCount( int ev ) ;
	
	/**
	 @return
		���݂�X��̐���Ԃ��܂��B������Ԃł́A�O��Ԃ��܂��B
	 */
	virtual int		getXColumnCount() ;

	/**
	 @param ev [in]
		X��̐����w�肵�Ă��������B
	 */
	virtual CDcdGrid& setXColumnCount( int ev ) ;

	///@}
public:
	// ********************************
	///	@name CDcdGrid-Y��EX���}��/�폜
	// ********************************
	///@{
	/**
	  Y����P�A�w��̈ʒu�ɒǉ����܂��B
	 @param iYColumnNumber
		Y��ԍ����w�肵�Ă��������B
		�V�����ǉ����ꂽY�񂪁A����Y��ԍ��ɂȂ�܂��B
		�͈͂� 0 �ȏ� getYColumnNumber() �ȉ��ŁA
		0 �Ȃ�擪�EgetYColumnNumber() �Ȃ疖���ւ̒ǉ��ƂȂ�܂��B
		  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	 @param bFixafterColumnNumberChange [in]
		- false	�E�E�E  [FocurCellColumnNumber �ύX]  �t�H�[�J�X�Z�����A
		�E�C���h�E����
		�ړ����܂��B
		- true �E�E�E 	[FixafterColumnNumber �ύX]  �t�H�[�J�X�Z����
		�E�C���h�E���
		�\�������悤�ɁA FixafterColumnNumber ��ύX���܂��B
	 @return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	 -	-2 ;	//	�C���f�N�X���s��
	 */
	virtual int insertYColumn( int iYColumnNumber ,
		bool bFixafterColumnNumberChange ) ;

	/**
	  X����P�A�w��̈ʒu�ɒǉ����܂��B
	 @param iXColumnNumber
		X��ԍ����w�肵�Ă��������B
		�V�����ǉ����ꂽX�񂪁A����X��ԍ��ɂȂ�܂��B
		�͈͂� 0 �ȏ� getXColumnNumber() �ȉ��ŁA
		0 �Ȃ�擪�EgetXColumnNumber() �Ȃ疖���ւ̒ǉ��ƂȂ�܂��B
		  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	 @param bFixafterColumnNumberChange [in]
		- false	�E�E�E  [FocurCellColumnNumber �ύX]  �t�H�[�J�X�Z�����A
		�E�C���h�E����
		�ړ����܂��B
		- true �E�E�E 	[FixafterColumnNumber �ύX]  �t�H�[�J�X�Z����
		�E�C���h�E���
		�\�������悤�ɁA FixafterColumnNumber ��ύX���܂��B
	 @return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	 -	-2 ;	//	�C���f�N�X���s��
	 */
	virtual int insertXColumn( int iXColumnNumber , 
		bool bFixafterColumnNumberChange ) ;
	
	/**
	  Y����P�A�폜���܂��B
	 @param iYColumnNumber
		Y��ԍ����w�肵�Ă��������B
		�͈͂� 0 �ȏ� getYColumnNumber() �����ł��B
		  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	 @return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	 -	-2 ;	//	�C���f�N�X���s��
	 */
	virtual int eraseYColumn( int iYColumnNumber ) ;
	/**
	  X����P�A�폜���܂��B
	 @param iXColumnNumber
		X��ԍ����w�肵�Ă��������B
		�͈͂� 0 �ȏ� getXColumnNumber() �����ł��B
		  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	 @return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	 -	-2 ;	//	�C���f�N�X���s��
	 */
	virtual int eraseXColumn( int iXColumnNumber ) ;
	///@}
	
public:
	// ********************************
	///	@name	CDcdGrid-�X�N���[��
	// ********************************
	///@{
	virtual int	getXFixColumnCount() ;
	/**
	�@�X�N���[���ʒu�̕ύX���ɂ́ACWndDcdGrid �S�̂��X�V���܂�
	 ( CWndDcdGrid::update())���Ăяo��)�B
	*/
	virtual CDcdGrid& setXFixColumnCount( int ev ) ;
	virtual int	getXFixafterColumnNumber() ;
	/**
	�@�X�N���[���ʒu�̕ύX���ɂ́ACWndDcdGrid �S�̂��X�V���܂�
	 ( CWndDcdGrid::update())���Ăяo��)�B
	*/
	virtual CDcdGrid& setXFixafterColumnNumber( int ev ) ;
	virtual int	getYFixColumnCount() ;
	/**
	�@�X�N���[���ʒu�̕ύX���ɂ́ACWndDcdGrid �S�̂��X�V���܂�
	 ( CWndDcdGrid::update())���Ăяo��)�B
	*/
	virtual CDcdGrid& setYFixColumnCount( int ev ) ;
	virtual int	getYFixafterColumnNumber() ;
	/**
	�@�X�N���[���ʒu�̕ύX���ɂ́ACWndDcdGrid �S�̂��X�V���܂�
	 ( CWndDcdGrid::update())���Ăяo��)�B
	*/
	virtual CDcdGrid& setYFixafterColumnNumber( int ev ) ;
	///@}

	// ****************************************************************
	//	WndDcdGrid3::CXDcdGrid
	// ****************************************************************
protected:
	// ********************************
	///@name CWndDcdGrid ����� ����
	// ********************************
	///@{
	/**
	  �����̑Ó��������؂��A�l��␳���܂��B
	@return
		���炩�̑����̍X�V���s������ true �B
	*/
	bool update_adjustProp() ;
	/**
	  ���������ƂɁA��ʂ��X�V���܂��B
	@return
		���炩�̉�ʍX�V���s������ true �B
	*/
	bool update_updateScreen() ;

	/**
	  CWndDcdGrid �̓��ꃁ�\�b�h�̈Ϗ����󂯂܂��B

	  �E�C���h�E�S��𖳌������A�ĕ`���v�����܂��B
	  ���̂Ƃ��A�X�N���[���o�[�̑����̍Đݒ�E
	�t�H�[�J�X�Z���̐��K�����s���܂��B
	
	 @param bErase [in]
		�X�V���[�W�������̔w�i���������邩�ǂ������w�肵�܂��B
		(�E�C���h�E�̔w�i�F�����������`����s���Ă���ꍇ�́A
		true �ɂ���K�v������܂��B
		NULL PEN �� NULL BRUSH���g�p���ĕ`����s���Ă���ꍇ���A����ɊY�����܂�)�B
	 @attention
		CWnd::Invalidate() �ł́A�X�N���[���o�[��t�H�[�J�X�Z����
		�œK���͍s���܂���B
		�O���b�h�S�̂̍ĕ`����s���ꍇ�́A CWnd::Invalidate() �̑����
		���̊֐����Ăяo���Ȃ��Ă͂Ȃ�܂���B
	 */
	virtual void InvalidateGrid( 
		bool bErase = true ) ;
	///@}
public:
	// ********************************
	///@name WndDcdGrid3::CXDcdGrid �֘A
	// ********************************
	///@{
	CWndDcdGrid*	getCWndDcdGrid() {
		return m_pCWndDcdGrid ; } ;
	///@}

	// ********************************
	///@name WndDcdGrid3::CXDcdGrid ����
	// ********************************
	///@{
	bool getUpdateCWndDcdGrid()const ;
	void setUpdateCWndDcdGrid( bool value ) ;
	///@}

protected:
	// ================================
	///@name CXDcdGrid_ZoneCacheTemp �ɁAcreateZoneCache�����J
	// ================================
	friend class CXDcdGrid_ZoneCacheTemp ;
	bool createZoneCache( IfDcdTarget* pIfDcdTarger );
	void destroyZoneCache();
};

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif /*DcDraw_DcdGrid_WndDcdGrid3_CXDcdGrid_h*/
