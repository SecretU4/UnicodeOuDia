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
//	CWndDcdGrid.h
// ****************************************************************
*/
/** @file */
#ifndef DcDraw_DcdGrid_WndDcdGrid3_CWndDcdGrid_H
#define DcDraw_DcdGrid_WndDcdGrid3_CWndDcdGrid_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>
#include "DcdGrid\WndDcdGrid3\CXDcdGrid.h"
#include "DcdGrid\WndDcdGrid3\CFocus.h"
#include "DcdGrid\WndDcdGrid3\CSelect.h"
#include "DcdGrid\WndDcdGrid3\CSelectCell.h"
#include "DcdGrid\WndDcdGrid3\CBoxSelect.h"
#include "DcdGrid\WndDcdGrid3\CRandomSelect.h"
#include "NsOu/Ou.h"
#include "DcdGrid\CDcdGrid.h"

namespace DcDrawLib{
namespace DcdGrid{
namespace WndDcdGrid3{

class CPropStack ;

// ****************************************************************
//	CWndDcdGrid
// ****************************************************************
/**
@brief
�@�N���C�A���g�̈��CDcdGrid �ɂ��O���b�h��\������E�C���h�E�ł��B

�@CWndDcdGrid �́A�L�[�{�[�h����ɂ��t�H�[�J�X�Z���̑���A�Z���͈͂̑I���̋@�\���񋟂��܂��B

�@���̃N���X�́A�ȉ��̃N���X�̃I�u�W�F�N�g���W�񂵂܂��B�����́A�݂��ɋ������삵�܂��B

- WndDcdGrid3::CXDcdGrid(��{�N���X�FCDcdGrid)@n
  �O���b�h�ɕ`�悷��R���e���c@n
  �X�N���[���ʒu�́A���̃I�u�W�F�N�g�̑����ł��B
- WndDcdGrid3::CFocus@n
  �t�H�[�J�X�Z���B
- WndDcdGrid3::CSelect@n
  �I���Z���B
- WndDcdGrid3::CBoxSelect @n
  CWndDcdGrid ��ł́A���[�U�[��BoxSelect(���^�I�𑀍�)�ɂ��������āA
  CSelect,CSelectCell �̑�����ύX���܂��B
- WndDcdGrid3::CRandomSelect @n
  CWndDcdGrid ��ł́A���[�U�[��RandomSelect(�ʂ̃Z���I�𑀍�)��
  ���������āACSelect,CSelectCell �̑�����ύX���܂��B

��1�����̃N���X�̐Ӗ�

���E�C���h�E�̐����E�j��

���W�񂷂�I�u�W�F�N�g�𐶐��E�j��

�@���̃N���X���W�񂷂� WndDcdGrid3::CXDcdGrid,WndDcdGrid3::CFocus,
 WndDcdGrid3::CSelect,WndDcdGrid3::CBoxSelect,WndDcdGrid3::CRandomSelect
�̐����E�j�����s���܂��B

���E�C���h�E�ւ�UI����ւ̉���

���W�񂷂�I�u�W�F�N�g�ɑ΂��čX�V�v�����Ϗ�

�@CWndDcdGrid::update() ����A�e�W��I�u�W�F�N�g�ɑ΂��āA
 update_adjustProp() , update_updateScreen() ���Ϗ����܂��B
�@�W��I�u�W�F�N�g�́A�������ύX���ꂽ�Ƃ��ɂ́A CWndDcdGrid::update() 
 ���Ăяo�����Ƃɂ��A���̏W��I�u�W�F�N�g�ɍX�V���˗����܂��B
 (��F�t�H�[�J�X�Z�����ړ����ꂽ�Ƃ��ɁA�t�H�[�J�X�Z����
 ��ʓ��Ɏ��܂�悤�ɃX�N���[���j


��2���g����

��2.1���\�z

(1)�E�C���h�E�𐶐�

�@CWndDcdGrid �́A�q�E�C���h�E�Ƃ��ē��삵�܂��B
�@�ȉ��̎菇�ŃE�C���h�E�𐶐��E�\�����邱�Ƃ��ł��܂��B

(1.1)�@�e�E�C���h�E�� OnCreate() �� CWndDcdGrid::Create() 
�ŃE�C���h�E�𐶐��B

(1.2)�@CWndDcdGrid::ShowWindow() �ŃE�C���h�E��\����A
CWndDcdGrid::UpdateWindow() �ŃN���C�A���g�̈���X�V

��2.2���e�E�C���h�E�ɕK�v�ȏ���

��2.2.1���e�E�C���h�E��OnSize

�@CWndDcdGrid�@�e�E�C���h�E��OnSize() �ł́ACWndDcdGrid�̈ʒu�E�T�C�Y�𒲐߂��Ă��������B
@code
void CMainWnd::OnSize(UINT nType, int cx, int cy) 
{
	
	if ( nType == SIZE_MAXIMIZED   //�E�B���h�E�͍ő�\������܂��B
		|| nType == SIZE_RESTORED  // �E�B���h�E�̓T�C�Y�ύX����܂����ASIZE_MINIMIZED �� SIZE_MAXIMIZED �͓K�p����܂���B
	){
		m_pCWndDcdGrid->MoveWindow( 0 , 0 , cx , cy , TRUE ) ;
	}	else	{
		super::OnSize(nType, cx, cy);
	}
}
@endcode

��2.2.2���e�E�C���h�E��OnSetFocus

�@�e�E�C���h�E�� CWndDcdGrid �ȊO�̎q�E�C���h�E�������Ȃ��ꍇ�́A CWndDcdGrid() �Ƀt�H�[�J�X���ړ����Ă��������B

@code
void CMainWnd::OnSetFocus(CWnd* pOldWnd) 
{
	//super::OnSetFocus(pOldWnd);
	
	CWnd*	pControl = GetNextDlgTabItem( (CWnd*)NULL , FALSE ) ;
	pControl->SetFocus() ;
}
@endcode

��2.3���O���b�h�ւ̃R���e���c�̕\��

(1)WndDcdGrid3::CXDcdGrid �I�u�W�F�N�g�ւ̃|�C���^���擾

�@CWndDcdGrid::getCXDcdGrid() �ŁAWndDcdGrid3::CXDcdGrid
 �I�u�W�F�N�g�ւ̃|�C���^���擾���Ă��������B
�@����Ȍ�́A���̂̃|�C���^���g���āA�O���b�h�ɃR���e���c���w�肵�܂��B

(2)X��EY��̐���ݒ�

�@X��EY��̐����w�肵�Ă��������B

 - WndDcdGrid3::CXDcdGrid::setXColumnCount(),
 - WndDcdGrid3::CXDcdGrid::setYColumnCount())�B

�@�ȉ��̃��\�b�h���g���āAX��EY����P���ǉ��E�폜���邱�Ƃ��ł��܂��B

 - WndDcdGrid3::CXDcdGrid::insertXColumn(),
 - WndDcdGrid3::CXDcdGrid::eraseXColumn()
 - WndDcdGrid3::CXDcdGrid::insertYColumn(),
 - WndDcdGrid3::CXDcdGrid::eraseYColumn()


(3)�eX��EY��̕��E�e�r���̑�����ݒ�(�����ݒ�̏ꍇ�͏���)

�@X��EY��̕��E�e�r���̑����������ݒ�ɂ��Ȃ��ꍇ�́A������ݒ肵�Ă��������B

�@X��EY��̕��E�e�r���̑����́A�ȉ��̑����ɂ���ĕύX�ł��܂��B

 - CDcdGridXColumn::m_iColumnSize,
 - CDcdGridYColumn::m_iColumnSize,
 - CDcdGridXBorder::m_iColumnBorderSize,
 - CDcdGridYBorder::m_iColumnBorderSize

�@X��EY��̕��E�e�r���̑����̎����ݒ��ON/OFF�́A�ȉ��̑����ɂ���ĕύX�ł��܂��B

 - CDcdGridXColumn::m_bAutoColumnSize
 - CDcdGridYColumn::m_bAutoColumnSize
 - CDcdGridXBorder::m_bAutoColumnBorderSize
 - CDcdGridYBorder::m_bAutoColumnBorderSize

 @attention
	CDcdGridXColumn,CDcdGridYColumn �́A�f�t�H���g�ł�
	m_bAutoColumnSize,m_bAutoColumnBorderSize ���^�ɂȂ��Ă��܂��B
	���̑������^���ƁA�O���b�h�̕`��Ɏ��Ԃ�������܂��B


(4)�e�r���E�e�Z���� IfDcDraw �I�u�W�F�N�g�ɑ�����ݒ�

�@�ڍׂ́A CDcdGrid �̐������Q�Ƃ��Ă��������B

(5)�E�C���h�E�̃N���C�A���g�̈�̍X�V�v��

�@�O���b�h�� WndDcdGrid3::CXDcdGrid �E
 �������� WndDcdGrid3::CXDcdGrid�̏W��I�u�W�F�N�g �ɑ΂��āA
 �O���b�h�̕`��`���ύX����悤�ȑ�����s�����ꍇ�́A
 CWndDcdGrid::InvalidateGrid() ���Ăяo���āACWndDcdGrid ��
 �N���C�A���g�̈�̍X�V��v�����Ă��������B
   ����ɂ��A�`��`��̕ύX���e���E�C���h�E�̃N���C�A���g�̈�ɔ��f����܂��B

�@�uWndDcdGrid3::CXDcdGrid�̏W��I�u�W�F�N�g�v�́A�ȉ��̂��̂��w���܂��B

- CDcdGridXColumn ,
- CDcdGridYColumn , 
- CDcdGridXBorder �ƁA����ɏW�񂳂�Ă��� IfDcDraw �I�u�W�F�N�g , 
- CDcdGridYBorder �ƁA����ɏW�񂳂�Ă��� IfDcDraw �I�u�W�F�N�g , 
- CDcdGridCell �ƁA����ɏW�񂳂�Ă��� IfDcDraw �I�u�W�F�N�g , 

  �A���A�P�̃Z���̃T�C�Y��ς����ɕ\�����e������ύX����ꍇ�́A
  CWndDcdGrid::InvalidateGrid() �̑���� CWndDcdGrid::InvalidateCell()
  ���Ăяo���Ă��������ʂ�����܂��B
  ������̂ق����A��ʍX�V�ɂ����鎞�Ԃ��Z���Ȃ�A
  ����������炷���Ƃ��ł��܂��B


��2.4���t�H�[�J�X�Z���̈ړ�

(1)WndDcdGrid3::CFocus �I�u�W�F�N�g�ւ̃|�C���^���擾

�@CWndDcdGrid::getCFocus() �ŁAWndDcdGrid3::CFocus 
 �I�u�W�F�N�g�ւ̃|�C���^���擾���Ă��������B
�@����Ȍ�́A���̂̃|�C���^���g���āA�t�H�[�J�X�𑀍삷�邱�Ƃ��ł��܂��B

(2)�t�H�[�J�X���ړ�

�@WndDcdGrid3::CFocus::setFocusCell() �ŁA�t�H�[�J�X�Z�����ړ����邱�Ƃ��ł��܂��B

�@���̃��\�b�h�́A�ȉ��̑����̉e�����󂯂܂��B�K�v�Ȃ�A�ȉ��̑�����ݒ肵�Ă��������B

- WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange
- WndDcdGrid3::CSelect::m_bKeepAnchor



��2.5���X�N���[��

(1)WndDcdGrid3::CXDcdGrid �I�u�W�F�N�g�ւ̃|�C���^���擾

�@CWndDcdGrid::getCXDcdGrid() �ŁAWndDcdGrid3::CXDcdGrid 
 �I�u�W�F�N�g�ւ̃|�C���^���擾���Ă��������B
�@����Ȍ�́A���̂̃|�C���^���g���āA�O���b�h�̃X�N���[���ʒu��
 �擾�E�ݒ�ł��܂��B

(2)�X�N���[���̑�����ݒ�

  WndDcdGrid3::CXDcdGrid �̈ȉ��̃��\�b�h�ŁA�X�N���[���̑�����ݒ肵�Ă��������B

  - WndDcdGrid3::CXDcdGrid::setXFixafterColumnNumber() , 
  - WndDcdGrid3::CXDcdGrid::setYFixafterColumnNumber(),
  - WndDcdGrid3::CXDcdGrid::setXFixColumnCount(),
  - WndDcdGrid3::CXDcdGrid::setYFixColumnCount() 
	

�y�⑫�z�����̃��\�b�h�́A�E�C���h�E�̃N���C�A���g�̈���X�V���܂��B
�����̃��\�b�h���Ăяo�������Ƃ́A CWndDcdGrid::InvalidateGrid() ��
�Ăяo���K�v�͂���܂���B

�@�����̃��\�b�h�́A�ȉ��̑����̉e�����󂯂܂��B�K�v�Ȃ�A�ȉ��̑�����
�ݒ肵�Ă��������B

- WndDcdGrid3::CXDcdGrid::m_bUpdateCWndDcdGrid
- WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange

��2.6���Z���I��

(1)WndDcdGrid3::CSelect �I�u�W�F�N�g�ւ̃|�C���^���擾

�@CWndDcdGrid::getCSelect() �ŁAWndDcdGrid3::CSelect �I�u�W�F�N�g�ւ�
 �|�C���^���擾���Ă��������B
 �@����Ȍ�́A���̂̃|�C���^���g���āA�I���Z���𑀍삷�邱�Ƃ��ł��܂��B

(2)�Z���I���̃��[�h�Ɣ͈͂�ݒ�
�@
�@�ȉ��̑�����ݒ肵�Ă��������B

- WndDcdGrid3::CSelect::m_eSelectMode  (�Z���I���̃��[�h)
- WndDcdGrid3::CSelect::m_ColumnNumberSelectLimit  (�Z���I���͈̔�)


(3)�Z���I����Ԃ̐ݒ�

�@WndDcdGrid3::CSelect::getCell() ���\�b�h�ŁA�Z���̑I���󋵂�
�\�� WndDcdGrid3::CSelectCell �I�u�W�F�N�g���擾���邱�Ƃ��ł��܂��B
 WndDcdGrid3::CSelectCell::setIsSelected() ���\�b�h��p���邱�Ƃɂ��A
�Z����I����Ԃɂ��邱�Ƃ��ł��܂��B

(4)�Z���I��������

  CWndDcdGrid::clearSelect() ���Ăяo�����Ƃɂ��ABoxSelect,RandomSelect 
�o���̑I���������ł��܂��B


��2.7���O���b�h�̃E�C���h�E�ȊO�ւ̕`��(��F���)

�@WndDcdGrid3::CXDcdGrid �́AIfDcDraw �C���^�[�t�F�[�X���T�|�[�g���Ă��܂��B
 ���̂��߁ACWndDcdGrid �����łȂ��A�C�ӂ� DC(IfDcdTarger �I�u�W�F�N�g)��
 �O���b�h��`�悷�邱�Ƃ��ł��܂��B
 ����ɂ��ACWndDcdGrid �̃N���C�A���g�̈�ɕ\�����Ă���O���b�h��
 �v�����^�Ɉ�����邱�Ƃ��ł��܂��B

�@�������A�E�C���h�E�ȊO�� IfDcdTarget �ɃO���b�h��`�悷��Ԃ́A
 �ȉ��̑������ꎞ�I�ɕύX���邱�Ƃ������߂��܂��B
-  WndDcdGrid3::CXDcdGrid::m_bUpdateCWndDcdGrid = false 
-  WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange = false 

	�y���R�z
	  �Ⴆ�΃v�����^�ɃO���b�h�S�̂��������ꍇ�́A�X�N���[���ʒu��
	 �ύX���Ȃ��畡���������s���K�v������܂��B���̂Ƃ��A����瑮����
	 true �̂܂܂ł́A����ʒu���w�肷�邽�߂ɃX�N���[���ʒu��ύX�����Ƃ��ɁA
	 �E�C���h�E�̃X�N���[���o�[�ʒu���s�v�ɕύX����܂��B

 �@���̏����́ACPropStack ���g���ƕ֗��ł��B�ȉ��́A��������̗�ł��B
@code
void CDelivedGrid::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	//	����p���� IfDcdTarget �I�u�W�F�N�g�𐶐�
	CDcdTargetMfcPrintInfo	aCDcdTargetMfcPrintInfo( pDC, pInfo ) ;

	//	�X�N���[���ƍĕ`���}�~���܂��B
	CPropStack	aPropStack( this ) ;
	aPropStack.CDcdGrid_setUpdateCWndDcdGrid( false )
		.CFocus_setFixafterColumnNumberChange( false );

	//	this �ɁApCWndDcdGrid�X�N���[���ʒu��ݒ�
	this->getCXDcdGrid ()->setYFixafterColumnNumber( page )

	//	IfDcdTarget�ɕ`��
	this->getCXDcdGrid ()->DcDraw( &aCDcdTargetMfcPrintInfo ) ;
}
@endcode

*/
class CWndDcdGrid : public CWnd 
{
	friend class CXDcdGrid ;	//update() �̌Ăяo��������
	friend class CFocus ;	//update() �̌Ăяo��������
	friend class CSelect ;	//update() �̌Ăяo��������
	friend class CSelectCell ;	//update() �̌Ăяo��������
	friend class CBoxSelect ;	//update() �̌Ăяo��������
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************


public:
	typedef CWnd super ;

private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�u�̈�O�h���b�O�X�N���[���v�̃^�C�}���ԊԊu�B
		�P�ʂ̓~���b�ł��B
		����l�́A100ms�ł��B
	*/
	UINT m_iOutsideDrag_TimeMs ;
	///@}
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		�ʏ��false�ł��B

		���̃E�C���h�E�ō��{�^���N���b�N����Ă���A
		�{�^�����������܂ŁE
		�������̓E�C���h�E���t�H�[�J�X�������܂ł̊Ԃ���true�ł��B

		
		�E�C���h�E���t�H�[�J�X�𓾂����_�Ŋ���
		�}�E�X���{�^���������������Ă����ꍇ�́Afalse�ł��B
	*/
	bool m_bLButtonIsDown ;
	/**
		�}�E�X�̍��{�^�������̃E�C���h�E��ōŌ�ɉ���������ꂽ
		���́A�}�E�X�J�[�\���̍��W��ێ����܂��B
		�P�ʂ́A�E�C���h�E�̃N���C�A���g���W(�f�o�C�X���W)�ł��B
	*/
	CdDcdPosXy	m_posxyCursorPosOnLButtonDown ;
	///@}
	// ********************************
	///@name ���
	// ********************************
	///@{
	/**
		���̃E�C���h�E�ɕ`����s�� CDcdGrid �I�u�W�F�N�g�ł��B
		�R���X�g���N�^�Ő����E�f�X�g���N�^�Ŕj�����܂��B
	 */
	CXDcdGrid*	m_pCDcdGrid ;
	
	/**
		CWndDcdGrid �̃t�H�[�J�X�E�X�N���[���̐�����N���X���������̂ł��B
		�R���X�g���N�^�Ő����E�f�X�g���N�^�Ŕj�����܂��B
	 */
	CFocus*	m_pCFocus ;
	
	/**
		CWndDcdGrid �̃Z���I���̐�����N���X���������̂ł��B
		�R���X�g���N�^�Ő����E�f�X�g���N�^�Ŕj�����܂��B
	 */
	CSelect*	m_pCSelect ;

	/**
		CWndDcdGrid ��ł́A���[�U�[��BoxSelect(���^�I�𑀍�)�ɂ��������āA
		CSelect,CSelectCell �̑�����ύX���܂��B
	 */
	CBoxSelect*	m_pCBoxSelect ;
	/**
		CWndDcdGrid ��ł́A���[�U�[��RandomSelect(�ʂ̃Z���I�𑀍�)��
		���������āACSelect,CSelectCell �̑�����ύX���܂��B
	 */
	CRandomSelect*	m_pCRandomSelect ;
	///@}
private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
	-	true ;	�^�C�}�X�N���[���̃^�C�}��ON�B
	*/
	bool m_bOutsideDrag_TimerOn ;

	/**
	  �ʏ�� false �B
	  this �́Aupdate() �̌Ăяo����}���������ꍇ�� true �Ƃ��܂��B
	
	-true: update() �̌Ăяo�����֎~���Ă��܂��B
		���̊Ԃ�(�W�񂵂Ă��� CXDcdGrid,CFocusScroll,CSelect �����)
		update() �Ăяo���͂��ׂāA���������� return ���܂��B

		update() �̍ē�������邽�߂ɗp�����܂��B
	*/
	bool m_bDisable_UpdateAll ;


	///@}

protected:
	// --------------------------------
	///@name	�����֐�
	// --------------------------------
	///@{
	/**
	�����̕ύX�����ƂɁA�E�C���h�E�\���̍X�V�������s���܂��B
	WndDcdGrid3::CWndDcdGrid �̂��ׂĂ̕�܃I�u�W�F�N�g�̍X�V���s���܂��B

	���̃N���X�� update() �́A�W��I�u�W�F�N�g������Ăяo����܂��B

	@attention	���̊֐��́A�����I�u�W�F�N�g�ɑ΂���ē����֎~���Ă��܂��B
		�ē��Ăяo���́A���������� false ��Ԃ��� return ���܂��B

	@return 
		���K���̌��ʁA���炩�̒l��ω��������ꍇ�͐^�ł��B
	 */
	virtual bool update( ) ; 

	/**
	�t�H�[�J�X�Z���ړ����́ACPropStack �C���X�^���X�𐶐����܂��B
	���̃I�u�W�F�N�g�́A�������Ԓ��͈ȉ��̑�����ݒ肵�܂��B

	- WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange = true

	 UI����ɂ��t�H�[�J�X�Z���ړ����ɁA
	 �X�N���[���ʒu���Ǐ]����悤�ɂ��܂��B
	*/
	Ou<CPropStack> createPropStackForMovingFocusCell() ;

	/**
	�X�N���[�����́ACPropStack �C���X�^���X�𐶐����܂��B
	���̃I�u�W�F�N�g�́A�������Ԓ��͈ȉ��̑�����ݒ肵�܂��B

	- WndDcdGrid3::CFocus::m_bFixafterColumnNumberChange = false

	 UI����ɂ��X�N���[���o�[�ʒu�̕ύX�ɁA
	 �t�H�[�J�X�Z�����Ǐ]����悤�ɂ��܂��B
	*/
	Ou<CPropStack> createPropStackForScroll() ;

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CWndDcdGrid();
	virtual ~CWndDcdGrid();

// ********************************
//	CDcdGrid
// ********************************
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
		��܂��Ă��� CXDcdGrid �I�u�W�F�N�g( m_pCDcdGrid ) �ɑ΂��āA
		CDcdGrid::OnCreateXColumn() ���Ăяo���܂��B
	 */
	virtual void OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) ;
	
	/**
	this �́AColumn ���j������钼�O�ɁA���̊֐����Ăяo���܂��B
	�j������� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g��
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
		��܂��Ă��� CXDcdGrid �I�u�W�F�N�g( m_pCDcdGrid ) �ɑ΂��āA
		CDcdGrid::OnDeleteXColumn() ���Ăяo���܂��B
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
		��܂��Ă��� CXDcdGrid �I�u�W�F�N�g( m_pCDcdGrid ) �ɑ΂��āA
		CDcdGrid::OnCreateYColumn() ���Ăяo���܂��B
	 */
	virtual void OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;
	
	/**
	this �́AColumn ���j������钼�O�ɁA���̊֐����Ăяo���܂��B
	�j������� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g��
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
		��܂��Ă��� CXDcdGrid �I�u�W�F�N�g( m_pCDcdGrid ) �ɑ΂��āA
		CDcdGrid::OnDeleteYColumn() ���Ăяo���܂��B
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
		��܂��Ă��� CXDcdGrid �I�u�W�F�N�g( m_pCDcdGrid ) �ɑ΂��āA
		CDcdGrid::OnCreateCell() ���Ăяo���܂��B
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
		��܂��Ă��� CXDcdGrid �I�u�W�F�N�g( m_pCDcdGrid ) �ɑ΂��āA
		CDcdGrid::OnDeleteCell() ���Ăяo���܂��B
	 */
	virtual void OnDeleteCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) ;
	///@}
public:
	// ********************************
	///	@name CDcdGrid-Y��EX��̈ʒu
	// ********************************
	///@{
	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	Y��̈ʒu��Ԃ��܂��B

	@param iYColumnNumber [in]
		Y��ԍ����w�肵�Ă��������B
	@return
		Y��͈̔͂�Ԃ��܂��B
	 */
	virtual CdDcdZone	getYColumnZone( 
			int iYColumnNumber ) ;
		
	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	X��̈ʒu��Ԃ��܂��B

	@param iXColumnNumber [in]
		X��ԍ����w�肵�Ă��������B
	@return
		X��͈̔͂�Ԃ��܂��B
	
	@attention
		���̊֐��́AcreateZoneCache�̉e�����󂯂܂��B
		�����̊֐� ��A�����ČĂяo���ꍇ�́A
		�O������ createZoneCache() ���Ăяo���ƁA
		�p�t�H�[�}���X�����P����܂��B
	 */
	virtual CdDcdZone	getXColumnZone( 
			int iXColumnNumber ) ;
	
	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	Y��̉����̋��E���̈ʒu��Ԃ��܂��B

	@param iYColumnNumber [in]
		Y��ԍ����w�肵�Ă��������B�͈͂�-1�ȏ� getYColumnCount() �����ł��B
	@return
		Y��̋��E���͈̔͂�Ԃ��܂��B
	 */
	virtual CdDcdZone	getYColumnBorderZone( 
			int iYColumnNumber ) ;

	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	X��̉E���̋��E���̈ʒu��Ԃ��܂��B

	@param iXColumnNumber [in]
		X��ԍ����w�肵�Ă��������B�͈͂�-1�ȏ� getXColumnCount() �����ł��B
	@return
		X��̋��E���͈̔͂�Ԃ��܂��B
	 */
	virtual CdDcdZone	getXColumnBorderZone( 
			int iXColumnNumber ) ;
	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	�Z���̈ʒu��Ԃ��܂��B

	@param iXColumnNumber [in]
		X��ԍ����w�肵�Ă��������B�͈͂�0�ȏ� getXColumnCount() �����ł��B
	@param iYColumnNumber [in]
		Y��ԍ����w�肵�Ă��������B�͈͂�0�ȏ� getYColumnCount() �����ł��B
	@return
		�Z���̈ʒu��Ԃ��܂��B
	 */
	virtual CdDcdZoneXy	getCellZone( 
		int iXColumnNumber , int iYColumnNumber ) ;

	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	Y���W�ɑΉ�����AY��ԍ��𒲂ׂ܂��B
	
	@param iPos [in]
		Y���W���w�肵�Ă��������B
	@param pbIsBorder [out]
		���̊֐��́A iPos �����E����ɂ���ꍇ�� true �A
		 iPos ����͈̔͂ɂ���Ȃ� false �ł��B
	@return
	 	Y��ԍ���Ԃ��܂��B
	 
	 	- Y��ԍ� = -1 , *pbIsBorder=false : �O���b�h�̏�̊O���ł��B
	 	- Y��ԍ� = -1 , *pbIsBorder=true : �O���b�h�̏�̋��E���ł��B
	 	- Y��ԍ� = 0 �ȏ� getYColumnCount()���� , *pbIsBorder = false : 
	 		�O���b�h��Y��͈͂ł��B
	 	- Y��ԍ� = 0 �ȏ� getYColumnCount()���� , *pbIsBorder = true : 
	 		�O���b�h��Y�񉺑��̋��E���͈̔͂ł��B
	 	- Y��ԍ� = getYColumnCount() , *pbIsBorder = false : 
	 		�O���b�h�̉��̊O���ł��B
	 */
	virtual int getYColumnNumberOfPos( 
		int iPos , bool* pbIsBorder ) ;
	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	X���W�ɑΉ�����AX��ԍ��𒲂ׂ܂��B
	
	@param iPos [in]
		X���W���w�肵�Ă��������B
	@param pbIsBorder [out]
		���̊֐��́A iPos �����E����ɂ���ꍇ�� true �A
		 iPos ����͈̔͂ɂ���Ȃ� false �ł��B
	@return
		X��ԍ���Ԃ��܂��B
	
		- X��ԍ� = -1 , *pbIsBorder=false : �O���b�h�̍��̊O���ł��B
		- X��ԍ� = -1 , *pbIsBorder=true : �O���b�h�̍��̋��E���ł��B
		- X��ԍ� = 0 �ȏ� getXColumnCount()���� ,pbIsBorder = false : 
			�O���b�h��X��͈͂ł��B
		- X��ԍ� = 0 �ȏ� getXColumnCount()���� , *pbIsBorder = true : 
			�O���b�h��X��E���̋��E���͈̔͂ł��B
		- X��ԍ� = getXColumnCount() ,pbIsBorder = false : 
			�O���b�h�̉E�̊O���ł��B
	
	@attention
		���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
		�����̊֐� ��A�����ČĂяo���ꍇ�́A
		�O������ createZoneCache() ���Ăяo���ƁA
		�p�t�H�[�}���X�����P����܂��B
	 */
	virtual int getXColumnNumberOfPos( 
		int iPos , bool* pbIsBorder ) ;
	
	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	X,Y ���W�ɑΉ�����A�Z���𒲂ׂ܂��B

	@param aCdDcdPosXy [in]
		XY���W���w�肵�Ă��������B
	@return
		�Z���I�u�W�F�N�g��Ԃ��܂��B
		�w��̍��W���Z���͈̔͂Ɉʒu���Ă��Ȃ��ꍇ�́ANULL��Ԃ��܂��B
	 */
	virtual CDcdGridCell* getCellOfPos( 
		const CdDcdPosXy& aCdDcdPosXy ) ;

	///@}
public:
	// ********************************
	///	@name	CDcdGrid-�X�N���[��
	// ********************************
	///@{

	/**
	�w��̃}�E�X�J�[�\���ʒu�ł́u�̈�O�h���b�O�X�N���[���v
	�̉ۂƁA�\�ł���΃X�N���[���̕������Z�o���܂��B

	@param pos [in]
		�}�E�X�J�[�\���̍��W���A�N���C�A���g���W�Ŏw�肵�Ă��������B
		���̊֐��́A
		�u�}�E�X���h���b�O����Ă��̍��W�ɂ���ꍇ�ɁA�X�N���[�����K�v���v
		�𔻒肵�܂��B
	@return 
		X,Y���ꂼ��ɂ��āA�u�O���b�h�O�ł̃}�E�X�h���b�O�ɂ��X�N���[���v
		�̉ۂ�Ԃ��܂��B

	@note
		�߂�l�̈Ӗ��́AX�̏ꍇ�͈ȉ��̂悤�ɂȂ�܂��B
		-	 0 ;�u�̈�O�h���b�O�X�N���[���v�͕s�v
		-	-1 ;�J�[�\���́A�̈�O(��)(Y���W�Ȃ��)�ł��B@n
			����(Y�Ȃ牺��)�́u�̈�O�h���b�O�X�N���[���v��@n
			�s�����Ƃ��ł��܂��B
		-	+1 ;�J�[�\���́A�̈�O(�E)(Y���W�Ȃ牺)�ł��B@n
			�E��(Y�Ȃ牺��)�́u�̈�O�h���b�O�X�N���[���v��@n
			�s�����Ƃ��ł��܂��B
	*/
	CdDcdSizeXy calcIncreaseOnOutsideDrag( const POINT& pos ) ;

	///@}
public:
	// ********************************
	///	@name	CDcdGrid-�Z���̌���
	// ********************************
	///@{

	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	Y��̈ʒu��Ԃ��܂����A�X�N���[���@�\�ɂ���Ĕ�\���ɂȂ��Ă���
	Y��i YFixafterColumnNumber �����j�̈ʒu���Ԃ��܂��B���̏ꍇ�A
	����Y��̈ʒu�́A�Œ�Y��ɏd�Ȃ�����A�O���b�h�̈�ԏ�������
	�Ȃ邱�Ƃ�����܂��B

	@param iYColumnNumber [in]
		Y��ԍ����w�肵�Ă��������B
	@return
		Y��͈̔͂�Ԃ��܂��B
	 */
	virtual CdDcdZone	getYColumnZoneOverlap( 
			int iYColumnNumber ) ;
	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	X��̈ʒu��Ԃ��܂����A�X�N���[���@�\�ɂ���Ĕ�\���ɂȂ��Ă���
	X��i XFixafterColumnNumber �����j�̈ʒu���Ԃ��܂��B���̏ꍇ�A
	����X��̈ʒu�́A�Œ�X��ɏd�Ȃ�����A�O���b�h�̈�ԍ���������
	�Ȃ邱�Ƃ�����܂��B
	
	@param iXColumnNumber [in]
		X��ԍ����w�肵�Ă��������B
	@return
		X��͈̔͂�Ԃ��܂��B
	 */
	virtual CdDcdZone	getXColumnZoneOverlap( 
			int iXColumnNumber ) ;

	/**
	�E�C���h�E�̃N���C�A���g�̈���ł́A
	�Z���̈ʒu��Ԃ��܂����A�X�N���[���@�\�ɂ���Ĕ�\���ɂȂ��Ă���
	�Z���̈ʒu���Ԃ��܂��B���̏ꍇ�A
	���̃Z���̈ʒu�́A�Œ�Y��EX��ɏd�Ȃ�����A
	�O���b�h�̈�ԍ��������E��ԏ�������
	�Ȃ邱�Ƃ�����܂��B
	
	@param iXColumnNumber [in]
		X��ԍ����w�肵�Ă��������B
	@param iYColumnNumber [in]
		Y��ԍ����w�肵�Ă��������B
	@return
		�Z���͈̔͂�Ԃ��܂��B
	 */
	virtual CdDcdZoneXy	getCellZoneOverlap( 
		int iXColumnNumber , int iYColumnNumber ) ;
	
	///@}
protected:
	// ********************************
	//	CWndDcdGrid
	// ********************************

	// --------------------------------
	///@name	CWndDcdGrid-�C�x���g�����̂��߂̉��z�֐�
	// --------------------------------
	///@{
	/**
	  this �́A�t�H�[�J�X�Z�����ړ������Ƃ��ɁA���̉��z�֐����Ăяo���܂��B
	  �N���X���[�U�[�́A���̉��z�֐����I�[�o���C�h���āA�K�v�ȏ�����
	�����ł��܂��B
	  
	  this �́A�N���X���[�U�[�� setFocusCell() �Ńt�H�[�J�X�Z�����ړ�����
	�Ƃ��̂ق��A�L�[�{�[�h�Ńt�H�[�J�X�Z�����ړ������Ƃ��E�X�N���[���o�[��
	�E�C���h�E���X�N���[���������ʃt�H�[�J�X�Z�����ړ������Ƃ��E
	�E�C���h�E�T�C�Y���ω��������ʃt�H�[�J�X�Z�����ړ������Ƃ��ɂ��A
	���̉��z�֐����Ăяo���܂��B

	[�I�[�o���C�h]
	  �����͂���܂���B
	
	@param pCDcdGridCell [in]
		�V�����t�H�[�J�X�Z���ł��B
	 */
	virtual void OnSetFocusCell( CDcdGridCell* pCDcdGridCell ) ;

	/**
	  this �́AFixafterColumnNumber ���ω������Ƃ�
	�i�X�N���[���ʒu���ω������Ƃ��j�ɁA���̉��z�֐����Ăяo���܂��B
	  �N���X���[�U�[�́A���̉��z�֐����I�[�o���C�h���āA�K�v�ȏ�����
	�����ł��܂��B
	  
	  this �́A�N���X���[�U�[�� 
	setXFixafterColumnNumber() �Œl��ݒ肵���Ƃ��̂ق��A
	�L�[�{�[�h�Ńt�H�[�J�X�Z�����ړ��������ʃX�N���[�������������Ƃ��E
	�X�N���[���o�[�ŃE�C���h�E���X�N���[�������Ƃ��ɂ�
	���̉��z�֐����Ăяo���܂��B

	[�I�[�o���C�h]
	  �����͂���܂���B
	
	@param iFixafterColumnNumber [in]
		�V���� FixafterColumnNumber �ł��B
	 */
	virtual void OnSetXFixafterColumnNumber( int iFixafterColumnNumber ) ;

	/**
	  this �́AFixafterColumnNumber ���ω������Ƃ�
	�i�X�N���[���ʒu���ω������Ƃ��j�ɁA���̉��z�֐����Ăяo���܂��B
	  �N���X���[�U�[�́A���̉��z�֐����I�[�o���C�h���āA�K�v�ȏ�����
	�����ł��܂��B
	  
	  this �́A�N���X���[�U�[�� 
	setYFixafterColumnNumber() �Œl��ݒ肵���Ƃ��̂ق��A
	�L�[�{�[�h�Ńt�H�[�J�X�Z�����ړ��������ʃX�N���[�������������Ƃ��E
	�X�N���[���o�[�ŃE�C���h�E���X�N���[�������Ƃ��ɂ�
	���̉��z�֐����Ăяo���܂��B

	[�I�[�o���C�h]
	  �����͂���܂���B
	
	 @param iFixafterColumnNumber [in]
		�V���� FixafterColumnNumber �ł��B
	 */
	virtual void OnSetYFixafterColumnNumber( int iFixafterColumnNumber ) ;

	/**
	  this �́AWndDcdGrid3::CSelectCell::m_bIsSelected ��
	  �ω������Ƃ��ɁA���̉��z�֐����Ăяo���܂��B
	  �N���X���[�U�[�́A���̉��z�֐����I�[�o���C�h���āA�K�v�ȏ�����
	�����ł��܂��B
	  
	  this �́A�N���X���[�U�[�� 
	CWndDcdGrid::CSelect::setColumnNumberSelect() ��
	�l��ݒ肵���Ƃ��̂ق��A
	�L�[�{�[�h�őI���Z����ύX�����Ƃ��ɂ�
	���̉��z�֐����Ăяo���܂��B
	
	[�I�[�o���C�h]
		  �����͂���܂���B
	
	@param iXColumnNumber [in]
		X��ԍ����w�肵�܂��B
	@param iYColumnNumber [in]
		X��ԍ����w�肵�܂��B
	@param bIsSelected [in]
		�V�����I����ԁB
	 */
	virtual void OnChangeSelectCell( 
		int iXColumnNumber , int iYColumnNumber , bool bIsSelected ) ;

	///@}


public:
	// ********************************
	///@name CWndDcdGrid-����
	// ********************************
	///@{
	UINT getOutsideDrag_TimeMs()const{	return m_iOutsideDrag_TimeMs ;};
	void setOutsideDrag_TimeMs( UINT value )
	{	m_iOutsideDrag_TimeMs = value ;};
	///@}
	// ********************************
	///@name ���
	// ********************************
	///@{
	virtual bool getLButtonIsDown()const{	return m_bLButtonIsDown ;};
	virtual CdDcdPosXy	getCursorPosOnLButtonDown()const
	{	return m_posxyCursorPosOnLButtonDown ;};

	/**
	@return
		���̃E�C���h�E��DcdGrid�ォ���
		�}�E�X�̃h���b�O���s���Ă���Ԃ��� true �ł��B
	*/
	virtual bool isDragging()const
	{	return m_bOutsideDrag_TimerOn ;};
	///@}

public:
	// ********************************
	///@name CWndDcdGrid-���
	// ********************************
	///@{
	CXDcdGrid*	getCXDcdGrid() ;
	CFocus*	getCFocus() ;
	CSelect*	getCSelect() ;
	CBoxSelect*	getCBoxSelect() ;
	CRandomSelect*	getCRandomSelect() ; 
	///@}
public:
	// ********************************
	///@name CWndDcdGrid-�\�z
	// ********************************
	///@{
	/**
	  �E�C���h�E��HWND�𐶐����܂��B

	@param rect [in]
		�E�C���h�E�̃T�C�Y�ƈʒu���w�肵�܂��B
		CRect �I�u�W�F�N�g�܂��� RECT �\���̂��w��ł��܂��B
	@param pParentWnd [in]
		�R���g���[���̐e�E�B���h�E (CDialog�̏ꍇ������) ���w�肵�܂��B
		NULL �͎w��ł��܂���B
	@param nID [in]
		�R���g���[���� ID ���w�肵�܂��B
	 */
	BOOL Create( const RECT& rect, CWnd* pParentWnd, UINT nID = 0 );

	/**
	�T�C�Y�O�ŁA�E�C���h�E��HWND�𐶐����܂��B
	�e�E�C���h�E�̃T�C�Y�����ƂɈʒu�����肷��ꍇ�ɂ́A
	��������g�����Ƃ��ł��܂��B
	
	@param pParentWnd [in]
		�R���g���[���̐e�E�B���h�E (CDialog�̏ꍇ������) ���w�肵�܂��B
		NULL �͎w��ł��܂���B
	@param nID [in]
		�R���g���[���� ID ���w�肵�܂��B
	 */
	BOOL Create( CWnd* pParentWnd, UINT nID  = 0 );
	///@}
public:
	// ********************************
	///@name CWndDcdGrid-����
	// ********************************
	///@{
	/**
	@return
		SHIFT�L�[��������Ă�����true 
	*/
	static bool isShiftPressed() ;

	/**
	@return
		Ctrl�L�[��������Ă�����true 
	*/
	static bool isCtrlPressed() ;

	/**
		���ׂẴZ����I�����܂��B

	@note
		BoxSelect �́A������Ԃɂ��܂��B
		BoxSelect�őS�Z����I������ƁA�I�����
		RandomSelect�ňꕔ�Z���̑I�����������邱�Ƃ��ł��Ȃ��Ȃ�܂��B
		�����������邽�߂ł��B
	*/
	virtual void selectAll() ;


	/**
		�Z���I�����������܂��B

		BoxSelect �̑I����������Ԃɂ��܂��B
	*/
	virtual void clearSelect() ;



public:
	// ********************************
	///@name CWndDcdGrid-�E�C���h�E�X�V
	// ********************************
	///@{
	/**
	�E�C���h�E��́A
	X��̉E���̋��E���̕`��ʒu�𖳌������A
	�ĕ`���v�����܂��B

	@param iXColumnNumber [in]
		X��ԍ����w�肵�Ă��������B�͈͂�-1�ȏ� getXColumnCount() �����ł��B
	@param bErase [in]
		�X�V���[�W�������̔w�i���������邩�ǂ������w�肵�܂��B
		(�E�C���h�E�̔w�i�F�����������`����s���Ă���ꍇ�́A
		true �ɂ���K�v������܂��B
		NULL PEN �� NULL BRUSH���g�p���ĕ`����s���Ă���ꍇ���A����ɊY�����܂�)�B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 ;	//	�ĕ`��̈�͂���܂���B
		-	1 ;	//	�ĕ`��̗v�����s���܂����B
	@attention
		���E���̕`��ʒu���܂ޗ̈��
		CWnd::Invalidate() ��ACWnd::InvalidateRect() �ȂǂŁA
		�����������ꍇ�́A���߂Ă��̊֐����Ăяo���Ȃ��Ă��A
		�Z���͎��� WM_PAINT �ōĕ`�悳��܂��B
	 */	 
	virtual int InvalidateXColumnBorder( int iXColumnNumber ,
		bool bErase = true ) ;
	/**
	�E�C���h�E��́A
	Y��̉����̋��E���̕`��ʒu�𖳌������A
	�ĕ`���v�����܂��B

	@param iYColumnNumber [in]
		Y��ԍ����w�肵�Ă��������B�͈͂�-1�ȏ� getYColumnCount() �����ł��B
	@param bErase [in]
		�X�V���[�W�������̔w�i���������邩�ǂ������w�肵�܂��B
		(�E�C���h�E�̔w�i�F�����������`����s���Ă���ꍇ�́A
		true �ɂ���K�v������܂��B
		NULL PEN �� NULL BRUSH���g�p���ĕ`����s���Ă���ꍇ���A����ɊY�����܂�)�B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 ;	//	�ĕ`��̈�͂���܂���B
		-	1 ;	//	�ĕ`��̗v�����s���܂����B
	@attention
		�Z���̕`��ʒu���܂ޗ̈��
		CWnd::Invalidate() ��ACWnd::InvalidateRect() �ȂǂŁA
		�����������ꍇ�E���邢�̓O���b�h�E�C���h�E�S�̂� 
		CWndDcdGrid::Invalidate() �� CWnd::Invalidate() �Ŗ�����
		�����ꍇ�́A���߂Ă��̊֐����Ăяo���Ȃ��Ă��A
		�Z���͎��� WM_PAINT �ōĕ`�悳��܂��B
	 */	 
	virtual int InvalidateYColumnBorder( int iYColumnNumber ,
		bool bErase = true ) ;
	/**
	�E�C���h�E��̎w��̃Z���̕`��ʒu�𖳌������A
	�ĕ`���v�����܂��B

	@param iXColumnNumber [in] 
		 X��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getXColumnCount() �����ł��B
	@param iYColumnNumber [in] 
		 Y��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getYColumnCount() �����ł��B
	@param bErase [in]
		�X�V���[�W�������̔w�i���������邩�ǂ������w�肵�܂��B
		(�E�C���h�E�̔w�i�F�����������`����s���Ă���ꍇ�́A
		true �ɂ���K�v������܂��B
		NULL PEN �� NULL BRUSH���g�p���ĕ`����s���Ă���ꍇ���A����ɊY�����܂�)�B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 ;	//	�ĕ`��̈�͂���܂���B
		-	1 ;	//	�ĕ`��̗v�����s���܂����B
	@attention
		�Z���̕`��ʒu���܂ޗ̈��
		CWnd::Invalidate() ��ACWnd::InvalidateRect() �ȂǂŁA
		�����������ꍇ�E���邢�̓O���b�h�E�C���h�E�S�̂� 
		CWndDcdGrid::Invalidate() �� CWnd::Invalidate() �Ŗ�����
		�����ꍇ�́A���߂Ă��̊֐����Ăяo���Ȃ��Ă��A
		�Z���͎��� WM_PAINT �ōĕ`�悳��܂��B
	 */	 
	virtual int InvalidateCell( int iXColumnNumber , int iYColumnNumber ,
		bool bErase = true ) ;

	/**
	�E�C���h�E�S��𖳌������A
	�ĕ`���v�����܂��B
	���̂Ƃ��A�X�N���[���o�[�̑����̍Đݒ�E
	�t�H�[�J�X�Z���̐��K�����s���܂��B

	Column �� ColumnSize�EColumnBorderSize �̕���ύX�����ꍇ�́A
	���̊֐����Ăяo���āA�ĕ`����s���Ă��������B
	�iColumn �� AutoColumnSize �EAutoColumnBorderSize ������
	�L���ȏꍇ�ŁA IfDcDraw ��u�������� CDcdGrid �̑傫����ύX�����ꍇ��
	����Ɋ܂݂܂��j�B
	
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
	
// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CWndDcdGrid)
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CWndDcdGrid)
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

} //namespace WndDcdGrid3
} //namespace DcdGrid
} //namespace DcDrawLib

#endif //DcDraw_DcdGrid_WndDcdGrid3_CWndDcdGrid_H

