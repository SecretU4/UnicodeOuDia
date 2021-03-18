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
//	CDcdGrid.h
// ****************************************************************
*/
/** @file */

#ifndef  CDcdGrid_h
#define  CDcdGrid_h
#include <limits.h>

#include <deque>

#include "DcDraw/IfDcDraw.h"
#include "DcDraw/CaDcdTargetClip.h"

#include "DcdGrid/CDcdGridYColumn.h"
#include "DcdGrid/CDcdGridXColumn.h"
#include "DcdGrid/CDcdGridCell.h"

namespace DcDrawLib{
namespace DcdGrid{

// ****************************************************************
//	CDcdGrid
// ****************************************************************
/**
@brief
 �O���b�h��`�悷��N���X�ł��B
  
  �C�ӂ̐���Y��EX����쐬���A�Z���Ƀe�L�X�g��z�u���邱�Ƃ��ł��܂��B
  �e�L�X�g��z�u�������ƁA DcDraw() ���\�b�h���g���āA�C�ӂ�DC
(IfDcdTarget�I�u�W�F�N�g)�ɑ΂��ăO���b�h�̕`����s�����Ƃ��ł��܂��B

�g�����|�O���b�h���`�����ăZ���Ƀe�L�X�g��`��
 ================================================================

�P�D  setYColumnCount() �E setXColumnCount() ���g���A�O���b�h��Y�񐔁E
X�񐔂��w�肵�Ă��������B

�Q�D  �eY��EX��̃T�C�Y�i�����E���j��ݒ肵�Ă��������BY��ԍ��EX��ԍ���
�w�肵�āi���ォ��0�N�_�̐����j getYColumn() �E getXColumn() ��
�Ăяo�����Ƃɂ��AY��EX���\�� CDcdGridYColumn �E CDcdGridXColumn �I�u�W�F�N�g��
�|�C���^���擾���邱�Ƃ��ł��܂��B
�eY��EX��̃T�C�Y�́A�����I�u�W�F�N�g�ɑ΂���
 CDcdGridXColumn::setColumnSize() , CDcdGridYColumn::setColumnSize() 
�Őݒ肵�Ă��������B�P�ʂ́A�_���P�ʂł��B

�R�D  Y��ԍ��EX��ԍ����w�肵�� getCell() ���Ăяo�����Ƃɂ��A�Z����\��
 CDcdGridCell �I�u�W�F�N�g�̃|�C���^���擾���邱�Ƃ��ł��܂��B
CDcdGridCell �́A�Z���̒��g��`�悷�� IfDcDraw �I�u�W�F�N�g��
�֘A�������Ă���A
�֘A���� IfDcDraw �I�u�W�F�N�g���g���ĕ`����s���܂��B
  this �́A�f�t�H���g�ł� CDcdGridCell �I�u�W�F�N�g��
 IfDcDraw �I�u�W�F�N�g�Ƃ��āA CDcdTextbox �I�u�W�F�N�g�𐶐�����
�o�^���܂�����̂��߁A CDcdTextbox �I�u�W�F�N�g�� m_strText ������
�e�L�X�g��ݒ肷��ƁA CDcdGrid �̓Z���̒��Ƀe�L�X�g��`�悵�܂��B

(��) �Z���ԍ� (1,0) �ɁA������ "0000" ���Z�b�g���Ă��܂��B
@code
Ou<CDcdTextbox>(pCDcdGrid->getCell( 1 , 0 )->getIfDcDraw())->setText( "0000" )  ;	
@endcode

�S�D  getItemSize() ���Ăяo�����Ƃɂ��A���̃O���b�h�̑傫����
�_���P�ʂŎ擾���邱�Ƃ��ł��܂��B�܂��A DcDraw() �ŔC�ӂ�DC�ɃO���b�h��
�`�悳���邱�Ƃ��ł��܂��B

@attention
CDcdGridXColumn , CDcdGridYColumn �́A�f�t�H���g�ł�
 m_bAutoColumnSize , m_bAutoColumnBorderSize ���^�ɂȂ��Ă��܂��B
���̑������^���ƁA�O���b�h�̕`��Ɏ��Ԃ�������܂��B
��̐��������ꍇ�́A CDcdGridXColumn ,  CDcdGridYColumn ��
m_bAutoColumnSize,m_bAutoColumnBorderSize ���U�ɂ��������ŁA
m_iColumnSize,m_iColumnBorderSize �ɖ����I��
�l��ݒ肷�邱�Ƃ������߂��܂��B
 */
class CDcdGrid : public IfDcDraw
{
private:
	// --------------------------------
	//	�C���i�[�^�C�v
	// --------------------------------
	typedef	std::deque<CDcdGridYColumn*>	CDcdGridYColumnCont ;
	typedef	std::deque<CDcdGridXColumn*>	CDcdGridXColumnCont ;
	typedef	std::deque< CDcdGridCell* > CDcdGridYColumnCellCont ;
	typedef	std::deque< CDcdGridYColumnCellCont* > CDcdGridCellCont ;
	friend class CDcdGridYColumn ;
	friend class CDcdGridXColumn ;
	friend class CDcdGridCell ;
	
	
	
 private:
	// ********************************
	///	@name �W��
	// ********************************
	///@{

	/**
		Y��̐擪(��[)�̌r����\���I�u�W�F�N�g�ł��B
	*/
	CDcdGridYBorder	m_CDcdGridYBorderTop ;

	/**
	  	Y��I�u�W�F�N�g��ێ�����R���e�i�ł��B�v�f���́A���  Y�� 
	  	�ł��B
	  
	  	�擪�̗v�f(�Y����0)��Y��ԍ�0�A
	  	2�Ԗځi�Y����1�j��Y��ԍ�1�A
	  	3�Ԗ�(�Y����2)��Y��ԍ�2�E�E�E�ƂȂ�܂��B
	  
	  	  �R���X�g���N�^�ł́A��ƂȂ�܂��B
	  	���̌�́A
	  		setYColumnCount() 
	  	���A�R���e�i�ɑ΂���Y��I�u�W�F�N�g�̒ǉ��E�폜���s���܂��B
	  
	  	�R���e�i���̃I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
	 */
	CDcdGridYColumnCont		m_CDcdGridYColumnCont ;


	/**
		Y��̖���(���[)�̌r����\���I�u�W�F�N�g�ł��B
	*/
	CDcdGridYBorder	m_CDcdGridYBorderBottom ;

	/**
		X��̐擪(���[)�̌r����\���I�u�W�F�N�g�ł��B
	*/
	CDcdGridXBorder	m_CDcdGridXBorderTop ;

	/**
	  	X��I�u�W�F�N�g��ێ�����R���e�i�ł��B�v�f���́A���  X�� 
	  	�ł��B
	  
	  	�擪�̗v�f(�Y����0)��X��ԍ�0�A
	  	2�Ԗځi�Y����1�j��X��ԍ�1�A
	  	3�Ԗ�(�Y����2)��X��ԍ�2�E�E�E�ƂȂ�܂��B
	  
	  	  �R���X�g���N�^�ł́A��ƂȂ�܂��B
	  	���̌�́A
	  		setYColumnCount() 
	  	���A�R���e�i�ɑ΂���X��I�u�W�F�N�g�̒ǉ��E�폜��X�񂢂܂��B
	  
	  	�R���e�i���̃I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
	 */
	CDcdGridXColumnCont 	m_CDcdGridXColumnCont ;

	/**
		X��̖���(�E�[)�̌r����\���I�u�W�F�N�g�ł��B
	*/
	CDcdGridXBorder	m_CDcdGridXBorderBottom ;

	
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
	CDcdGridCellCont 	m_CDcdGridCellCont ;
	///@}
	// ********************************
	/// @name ����
	// ********************************
	///@{

	/**
	  	�X�N���[���@�\�ɂ�����A�Œ�Y��
	  	�i�X�N���[���̑Ώۂ��珜�O�����Y��j�̐��ł��B
	  
	  	�͈͂́A0�ȏ� Y�񐔈ȉ��ł��B
	  	Y�񐔂��ω������Ƃ��Athis�͂��̑��������͈̔͂ɐ��K�����܂��B
	  	
	  	�����l��0�ł��B
	 */
	int	m_iYFixColumnCount ;

	/**
	  	�X�N���[���@�\�ɂ����āA��ԏ㑤�Ɉʒu����Y��ԍ��ł��B
	  	�������A�Œ�Y��̐����P�ȏ�ł���ꍇ�A���̒l�͌Œ�Y��̉��ׂ�Y��ԍ�
	  	�ƂȂ�܂��B
	  	
	  	�Ⴆ�΁Am_iYFixColumnCount ��1�ŁA���̒l��2�̏ꍇ�A
	  	DcDraw() �ł̕`�挋�ʂ́A�ォ��Y��ԍ�0�EY��ԍ�2�̏��ł��B
	  	
	  	�͈͂́Am_iFixRiwCount �ȏ� Y�񐔖����ł��B
	  	Y�񐔂��ω������Ƃ��A����� m_iYFixColumnCount ���ω������Ƃ��ɁA
	  	this�͂��̑��������͈̔͂ɐ��K�����܂��B
	  	
	  	�����l��0�ł��B
	 */
	int	m_iYFixafterColumnNumber ;

	/**
	  	�X�N���[���@�\�ɂ�����A�Œ�X��
	  	�i�X�N���[���̑Ώۂ��珜�O�����X��j�̐��ł��B
	  
	  	�͈͂́A0�ȏ� X�񐔈ȉ��ł��B
	  	X�񐔂��ω������Ƃ��Athis�͂��̑��������͈̔͂ɐ��K�����܂��B
	  	
	  	�����l��0�ł��B
	 */
	int	m_iXFixColumnCount ;
	
	/**
	  	�X�N���[���@�\�ɂ����āA��ԍ����Ɉʒu����X��ԍ��ł��B
	  	�������A�Œ�X��̐����P�ȏ�ł���ꍇ�A���̒l�͌Œ�X��̉E�ׂ�X��ԍ�
	  	�ƂȂ�܂��B
	  	
	  	�Ⴆ�΁Am_iXFixColumnCount ��1�ŁA���̒l��2�̏ꍇ�A
	  	DcDraw() �ł̕`�挋�ʂ́A������X��ԍ�0�EX��ԍ�2�̏��ł��B
	  	
	  	�͈͂́Am_iXFixColumnCount �ȏ� X�񐔖����ł��B
	  	X�񐔂��ω������Ƃ��A����� m_iXFixColumnCount ���ω������Ƃ��ɁA
	  	this�͂��̑��������͈̔͂ɐ��K�����܂��B
	  	
	  	�����l��0�ł��B
	 */
	int	m_iXFixafterColumnNumber ;

	///@}
private:
	// --------------------------------
	///@name	�����f�[�^( createZoneCache() )
	// --------------------------------
	///@{
	/**
	  	�ʏ�͗v�f�O�ł��B
	  	createZoneCache() ���� destroyZoneCache() �܂ł̊��Ԃ�
	  	getXColumnBorderZone() �̌��ʂ�ێ����܂��B
	  	�Y�����́A��ԍ��{�P�ƂȂ�܂��B
	 */
	std::deque< CdDcdZone >	m_zonecontXColumnBorderZoneCache ;
	/**
	  	�ʏ�͗v�f�O�ł��B
	  	createZoneCache() ���� destroyZoneCache() �܂ł̊��Ԃ�
	  	getXColumnZone() �̌��ʂ�ێ����܂��B
	  	�Y�����́A��ԍ��ƂȂ�܂��B
	 */
	std::deque< CdDcdZone >	m_zonecontXColumnZoneCache ;

	/**
	  	�ʏ�͗v�f�O�ł��B
	  	createZoneCache() ���� destroyZoneCache() �܂ł̊��Ԃ�
	  	getXColumnZoneOverlap() �̌��ʂ�ێ����܂��B
	  	�Y�����́A��ԍ��ƂȂ�܂��B
	 */
	std::deque< CdDcdZone >	m_zonecontXColumnZoneOverlapCache ;

	/**
	  	�ʏ�͗v�f�O�ł��B
	  	createZoneCache() ���� destroyZoneCache() �܂ł̊��Ԃ�
	  	getYColumnBorderZone() �̌��ʂ�ێ����܂��B
	  	�Y�����́A��ԍ��{�P�ƂȂ�܂��B
	 */
	std::deque< CdDcdZone >	m_zonecontYColumnBorderZoneCache ;
	/**
	  	�ʏ�͗v�f�O�ł��B
	  	createZoneCache() ���� destroyZoneCache() �܂ł̊��Ԃ�
	  	getYColumnZone() �̌��ʂ�ێ����܂��B
	  	�Y�����́A��ԍ��ƂȂ�܂��B
	 */
	std::deque< CdDcdZone >	m_zonecontYColumnZoneCache ;
	/**
	  	�ʏ�͗v�f�O�ł��B
	  	createZoneCache() ���� destroyZoneCache() �܂ł̊��Ԃ�
	  	getYColumnZoneOverlap() �̌��ʂ�ێ����܂��B
	  	�Y�����́A��ԍ��ƂȂ�܂��B
	 */
	std::deque< CdDcdZone >	m_zonecontYColumnZoneOverlapCache ;
	///@}


protected:
	// --------------------------------
	///@name	�����֐�
	// --------------------------------
	///@{
	/**
	  	�w���X��͈̔͂̑傫�������߂܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iXColumnNumberSrc [in]
	  	�N�_��X��ԍ����w�肵�Ă��������B
	  	bSrcIsBorder ���^�̏ꍇ�����A-1���w��ł��܂��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @param bSrcIsBorder [in]
	  	�N�_��X��ԍ����A����X��ԍ��̋��E�������w�肵�Ă���Ȃ�^
	   @param iXColumnNumberDst [in]
	  	�I�_��X��ԍ����w�肵�Ă��������B
	  	bDstIsBorder ���^�̏ꍇ�����A-1���w��ł��܂��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @param bDstIsBorder [in]
	  	�I�_��X��ԍ����A����X��ԍ��̋��E�������w�肵�Ă���Ȃ�^
	   @return
	  	�T�C�Y��Ԃ��܂��B
	  
	  	�i��j
	  
	  	��ԍ�-1�̋��E������A��ԍ�2�̗�܂ł͈̔͂����߂�ꍇ�́A
	  	( iXColumnNumberSrc ,bSrcIsBorder ,
	  		iXColumnNumberDst ,bDstIsBorder) = ( -1 , true , 2 , false )
	  	�ƂȂ�܂�
	 */
	int getXColumnsSize( 	IfDcdTarget* pIfDcdTarget ,
			int iXColumnNumberSrc , bool bSrcIsBorder ,
			int iXColumnNumberDst , bool bDstIsBorder) ;

	/**
	  	�w���Y��͈̔͂̑傫�������߂܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iYColumnNumberSrc [in]
	  	�N�_��Y��ԍ����w�肵�Ă��������B
	  	bSrcIsBorder ���^�̏ꍇ�����A-1���w��ł��܂��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @param bSrcIsBorder [in]
	  	�N�_��Y��ԍ����A����Y��ԍ��̋��E�������w�肵�Ă���Ȃ�^
	   @param iYColumnNumberDst [in]
	  	�I�_��Y��ԍ����w�肵�Ă��������B
	  	bDstIsBorder ���^�̏ꍇ�����A-1���w��ł��܂��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @param bDstIsBorder [in]
	  	�I�_��Y��ԍ����A����Y��ԍ��̋��E�������w�肵�Ă���Ȃ�^
	   @return
	  	�T�C�Y��Ԃ��܂��B
	  
	  	�i��j
	  
	  	��ԍ�-1�̋��E������A��ԍ�2�̗�܂ł͈̔͂����߂�ꍇ�́A
	  	( iYColumnNumberSrc ,bSrcIsBorder ,
	  		iYColumnNumberDst ,bDstIsBorder) = ( -1 , true , 2 , false )
	  	�ƂȂ�܂�
	 */
	int getYColumnsSize( 	IfDcdTarget* pIfDcdTarget ,
			int iYColumnNumberSrc , bool bSrcIsBorder ,
			int iYColumnNumberDst , bool bDstIsBorder) ;

	/**
	  	setYColumnCount() �� insertYColumn() �̉����֐��ł��B
	  
	  	Y����P�A�w��̈ʒu�ɒǉ����܂��B
	  	���̊֐��́A 
	  	m_CDcdGridXColumnCont,m_CDcdGridYColumnCont,
	  	m_CDcdGridCellCont
	  	�̑����������s���܂��B
	  	adjustProp() �͍s���܂���B
	   @param iYColumnNumber
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
	   @param iXColumnNumber
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
	   @param iYColumnNumber
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
	   @param iXColumnNumber
	  	X��ԍ����w�肵�Ă��������B
	  	�͈͂� 0 �ȏ� getXColumnNumber() �����ł��B
	  	  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	   @return
	  	����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	   -	-2 ;	//	�C���f�N�X���s��
	 */
	int eraseXColumn_eraseColumnCell( int iXColumnNumber ) ;

	/**
	  	Y��ԍ��EX��ԍ��Ɋ֌W���鑮���̐��K�����s���܂��B
	  	Y���X���ǉ��E�폜�����ꍇ�ɂ́A���̊֐����g����Y��ԍ��E
	  	X��ԍ��̐��K�����s���܂��B
	  	���K���́A�ȉ��̏��ɍs���܂��B
	  
	  
	  	- m_iXFixColumnCount
	  	- m_iXFixafterColumnNumber
	  	- m_iYFixColumnCount
	  	- m_iYFixafterColumnNumber
	  
	  	- CDcdGridCell::m_iXAttachCellCount
	  	- CDcdGridCell::m_iYAttachCellCount
	  
	  	- CDcdGridCell::m_pcellAttachTo
	 */
	virtual void adjustProp() ;
 
	/**
	  	getXColumnZone(),getXColumnBorderZone(),getXColumnZoneOverlap()
	  	getYColumnZone(),getYColumnBorderZone(),getYColumnZoneOverlap()
	  	�̌��ʂ̃L���b�V����
	  
	  	-	m_zonecontXColumnBorderZoneCache ;
	  	-	m_zonecontXColumnZoneCache ;
	  	-	m_zonecontXColumnZoneOverlapCache ;
	  	-	m_zonecontYColumnBorderZoneCache ;
	  	-	m_zonecontYColumnZoneCache ;
	  	-	m_zonecontXYColumnZoneOverlapCache ;
	  
	  	�ɍ쐬���܂��B
	@param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	@return
		- true : �L���b�V�����쐬���܂����B
		- false: �L���b�V�������łɑ��݂��܂��B
	*/
	bool createZoneCache( IfDcdTarget* pIfDcdTarget ) ;

	/**
	  	getXColumnZone(),getXColumnBorderZone(),getXColumnZoneOverlap()
	  	getYColumnZone(),getYColumnBorderZone(),getYColumnZoneOverlap()
	  	�̌��ʂ̃L���b�V��
	  
	  	-	m_zonecontXColumnBorderZoneCache ;
	  	-	m_zonecontXColumnZoneCache ;
	  	-	m_zonecontXColumnZoneOverlapCache ;
	  	-	m_zonecontYColumnBorderZoneCache ;
	  	-	m_zonecontYColumnZoneCache ;
	  	-	m_zonecontXYColumnZoneOverlapCache ;
	  
	  	��j�����܂��B
	 */
	void destroyZoneCache() ;
	///@}
	// --------------------------------
	///@name	DcDraw�̉����֐�
	// --------------------------------
	///@{

	/**
		�u�w���X�r��(�c�r��)�́A�w���Y��̈ʒu���A�����Z���ɂ���ĕ\������Ȃ��v
		�ꍇ�𔻒肵�܂��B
	@param iXColumnNumber
		�Ώۂ̌r����X��Index���w�肵�Ă��������B
	@param iYColumnNumber
		�`��ꏊ��Y��Index���w�肵�Ă��������B
	*/
	bool IsXBorderOverlappedByAttachedCell( int iXColumnNumber , int iYColumnNumber ) ;


	/**
		�u�w���Y�r��(���r��)�́A�w���X��̈ʒu���A�����Z���ɂ���ĕ\������Ȃ��v
		�ꍇ�𔻒肵�܂��B
	@param iXColumnNumber
		�`��ꏊ��X��Index���w�肵�Ă��������B
	@param iYColumnNumber
		Y�r��(���r��)�̗�Index���w�肵�Ă��������B
	*/
	bool IsYBorderOverlappedByAttachedCell( int iXColumnNumber , int iYColumnNumber ) ;


	/**
		DcDraw�̉������֐��ł��B
		X��̌r����`�悵�܂��B
		Y��̌Œ�񑤂ւ̕`��E�X�N���[���\�񑤂ւ̕`��̂Q����I�����邱�Ƃ��ł��܂��B
	@param isYFixColumn
		- true: Y��̌Œ�񑤂ւ̕`��
		- false: Y��̃X�N���[���\�񑤂ւ̕`��
	@param pTarget 
		�`��̈���w�肵�Ă��������B
		���̕`��̈�́A�N���b�s���O����Ă���K�v������܂��B
	@param iXColumnNumber
	  	 X��ԍ����w�肵�Ă��������B�͈͂́A-1�ȏ� getXColumnCount() �����ł��B
	  	-	-1 ;	���[�̌r���I�u�W�F�N�g�ɑ΂���`��B
	  	-	getXColumnCount()-1 , INT_MAX ;	
	  		�E�[�̌r���I�u�W�F�N�g�ɑ΂���`��B
	@return
		- true:���炩�̕`����s���܂����B
		- false:�`����s���܂���ł����B
	*/
	bool DcDraw_DrawXColumn( bool isYFixColumn , CaDcdTargetClip* pTarget , int iXColumnNumber ) ;


	/**
		DcDraw�̉������֐��ł��B
		Y��̌r����`�悵�܂��B
		X��̌Œ�񑤂ւ̕`��E�X�N���[���\�񑤂ւ̕`��̂Q����I�����邱�Ƃ��ł��܂��B
	@param isXFixColumn
		- true: X��̌Œ�񑤂ւ̕`��
		- false: X��̃X�N���[���\�񑤂ւ̕`��
	@param pTarget 
		�`��̈���w�肵�Ă��������B
		���̕`��̈�́A�N���b�s���O����Ă���K�v������܂��B
	@param iYColumnNumber
	  	 Y��ԍ����w�肵�Ă��������B�͈͂́A-1�ȏ� getYColumnCount() �����ł��B
	  	-	-1 ;	���[�̌r���I�u�W�F�N�g�ɑ΂���`��B
	  	-	getYColumnCount()-1 , INT_MAX ;	
	  		�E�[�̌r���I�u�W�F�N�g�ɑ΂���`��B
	@return
		- true:���炩�̕`����s���܂����B
		- false:�`����s���܂���ł����B
	*/
	bool DcDraw_DrawYColumn( bool isXFixColumn , CaDcdTargetClip* pTarget , int iYColumnNumber ) ;

	///@}
 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CDcdGrid() ;
	virtual ~CDcdGrid() ;
	
 private:
	CDcdGrid( const CDcdGrid& ev ){} ;
	void operator=( const CDcdGrid& ev ){} ;
	
 public:
	// ********************************
	///@name	IfDcDraw
	// ********************************
	///@{
	/**
	 	�`���v�����܂��B
	 	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B
	 @param pIfDcdTarget  [in]
	 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 @return
	 	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	*/
	virtual bool DcDraw( IfDcdTarget* pIfDcdTarget ) ;
	
	/**
	 	���̃I�u�W�F�N�g���`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 	���̑傫���𒲂ׂ邱�Ƃ��ł��܂��B
	 	�֐��Ăяo������������ IfDcDraw �I�u�W�F�N�g��`�悷��ꍇ�ɂ́A
	 	�֐��Ăяo�����́A���̊֐��ŃA�C�e���̑傫���𒲂ׂāA
	 	�K�؂ȃ��C�A�E�g���l���Ă���ADcDraw() �����s���邱�Ƃ��ł��܂��B
	 @param pIfDcdTarget [in]
	 	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	 @param pCdDcdSizeXy [out]
	 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă���ꍇ�́A
	 	���̊֐��͂��̃A�h���X�ɁA���̃A�C�e���̃T�C�Y��Ԃ��܂��B
	 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��Ȃ��ꍇ�́A
	 	���̒l�͕s��ł��B
	 @return
	 	���̃I�u�W�F�N�g�̕`�悷��A�C�e���̑傫�������܂��Ă��āA
	 	���̑傫���� *pCdDcdSizeXy�ɏ������񂾏ꍇ�͐^�ł��B
	 	�����łȂ��ꍇ�́A�U�ł��B
	*/
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
	
	///@}
 protected:
	// --------------------------------
	///@name �s�E��E�Z���̏�����
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
	  	   CDcdLine �I�u�W�F�N�g�� new �Ő������A
	  	pCDcdGridXColumn �� IfDcDraw �C���^�[�t�F�[�X�ɓo�^���܂��B
	  	���̂Ƃ��̑����́A�����P�̍��̎���
	  	�ƂȂ�܂��B
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
	  	pCDcdGridXColumn �� IfDcDraw �C���^�[�t�F�[�X��o�^�������A
	  	�I�u�W�F�N�g�� delete �Ŕj�����܂��B
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
	  	   CDcdLine �I�u�W�F�N�g�� new �Ő������A
	  	pCDcdGridYColumn �� IfDcDraw �C���^�[�t�F�[�X�ɓo�^���܂��B
	  	���̂Ƃ��̑����́A�����P�̍��̎���
	  	�ƂȂ�܂��B
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
	  	pCDcdGridYColumn �� IfDcDraw �C���^�[�t�F�[�X��o�^�������A
	  	�I�u�W�F�N�g�� delete �Ŕj�����܂��B
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
	  	   CDcdTextbox �I�u�W�F�N�g�� new �Ő������A
	  	pCDcdGridCell �� IfDcDraw �C���^�[�t�F�[�X�ɓo�^���܂��B
	  	���̂Ƃ��̑����́A
	  
	  		- �t�H���g�̓X�g�b�N�I�u�W�F�N�g�� DEFAULT_GUI_FONT 
	  		- �e�L�X�g�z�u�� 
	  			CdDrawTextFormat::H_LEFT | 
	  			CdDrawTextFormat::V_SINGLELINT_CENTER
	  		- �w�i�F�� ��
	  		- �e�L�X�g�̏㉺�E���E�̘g�̈�̑����͘_���P�ʂłP
	  
	  	�ƂȂ�܂��B
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
	  	pCDcdGridCell �� IfDcDraw �C���^�[�t�F�[�X��o�^�������A
	  	�I�u�W�F�N�g�� delete �Ŕj�����܂��B
	 */
	virtual void OnDeleteCell( int iXColumnNumber , int iYColumnNumber , 
		CDcdGridCell* pCDcdGridCell ) ;
	///@}
 public:
	// ********************************
	///	@name Y��EX��̐�
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
	///	@name Y��EX���}��/�폜
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
	   @return
	  	����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	   -	-2 ;	//	�C���f�N�X���s��
	 */
	virtual int insertYColumn( int iYColumnNumber ) ;

	/**
	  	X����P�A�w��̈ʒu�ɒǉ����܂��B
	   @param iXColumnNumber
	  	X��ԍ����w�肵�Ă��������B
	  	�V�����ǉ����ꂽX�񂪁A����X��ԍ��ɂȂ�܂��B
	  	�͈͂� 0 �ȏ� getXColumnNumber() �ȉ��ŁA
	  	0 �Ȃ�擪�EgetXColumnNumber() �Ȃ疖���ւ̒ǉ��ƂȂ�܂��B
	  	  �������A INT_MAX ���w�肷��ƁA�������w�肵�����ƂɂȂ�܂��B
	   @return
	  	����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	   -	-2 ;	//	�C���f�N�X���s��
	 */
	virtual int insertXColumn( int iXColumnNumber ) ;
	
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
	///	@name Y��EX��E�Z���I�u�W�F�N�g
	// ********************************
	///@{
	/**
	@return
		�O���b�h�̊O�g�̘g���I�u�W�F�N�g��Ԃ��܂��B
		��[�̃I�u�W�F�N�g��Ԃ��܂��B
	*/
	virtual CDcdGridYBorder* getCDcdGridYBorderTop()
	{	return &m_CDcdGridYBorderTop ;};

	/**
	 	  �w�肳�ꂽY��ԍ��́AY��I�u�W�F�N�g CDcdGridYColumn �̃|�C���^��
	  	�擾���邱�Ƃ��ł��܂��B���̃|�C���^���g���āAY��ɑ΂��鑀���
	  	Y�񂤂��Ƃ��ł��܂��B
	   @param iYColumnNumber [in] 
	  	 Y��ԍ����w�肵�Ă��������B�͈͂́A-1�ȏ� getYColumnCount() �����ł��B
	  	 �������A INT_MAX ���w�肷��ƁA�ŏIY����w�肵�����ƂɂȂ�܂��B
	   @return
	  	  �Ή�����Y��I�u�W�F�N�g��Ԃ��܂��B
	  	  �C���f�N�X���s���ȏꍇ�́ANULL��Ԃ��܂��B
	  
	  	  �Ԃ��ꂽ�I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
	  	  �Y������Y�� CDcdGrid �̕ʂ̃��\�b�h�ɂ���č폜�����ƁA�Ԃ��ꂽ
	  	�|�C���^�͖����ɂȂ�܂��B
	  	   this���j�����ꂽ�Ƃ��ɂ��A�Ԃ��ꂽ�|�C���^�͖����ɂȂ�܂��B
	 */
	virtual CDcdGridYColumn*	getYColumn( int iYColumnNumber )  ;

	/**
	  	  �w�肳�ꂽY��ԍ��́A�r���I�u�W�F�N�g CDcdGridYBorder �̃|�C���^��
	  	�擾���邱�Ƃ��ł��܂��B���̃|�C���^���g���āAY��̌r���ɑ΂��鑀���
	  	�s�����Ƃ��ł��܂��B
	   @param iYColumnNumber [in] 
	  	 Y��ԍ����w�肵�Ă��������B�͈͂́A-1�ȏ� getYColumnCount() �����ł��B
	  	-	-1 ;	��[�̌r���I�u�W�F�N�g�im_CDcdGridYBorderTop�j��Ԃ��܂��B
	  	-	getYColumnCount()-1 , INT_MAX ;	
	  		���[�̌r���I�u�W�F�N�g�im_CDcdGridYBorderBottom�j��Ԃ��܂��B
	   @return
	  	 �Ή�����Y��r���I�u�W�F�N�g��Ԃ��܂��B
	  	 �C���f�N�X���s���ȏꍇ�́ANULL��Ԃ��܂��B
	  
	  	  �Ԃ��ꂽ�I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
	  	  �Y������Y�� CDcdGrid �̕ʂ̃��\�b�h�ɂ���č폜�����ƁA�Ԃ��ꂽ
	  	�|�C���^�͖����ɂȂ�܂��B
	  	   this���j�����ꂽ�Ƃ��ɂ��A�Ԃ��ꂽ�|�C���^�͖����ɂȂ�܂��B
	 */
	virtual CDcdGridYBorder*	getYBorder( int iYColumnNumber )  ;

	/**
	@return
		�O���b�h�̊O�g�̘g���I�u�W�F�N�g��Ԃ��܂��B
		���[�̃I�u�W�F�N�g��Ԃ��܂��B
	*/
	virtual CDcdGridYBorder* getCDcdGridYBorderBottom(){ return &m_CDcdGridYBorderBottom ;};

	/**
	@return
		�O���b�h�̊O�g�̘g���I�u�W�F�N�g��Ԃ��܂��B
		���[�̃I�u�W�F�N�g��Ԃ��܂��B
	*/
	virtual CDcdGridXBorder* getCDcdGridXBorderTop(){	return &m_CDcdGridXBorderTop ;};

	/**
	  	  �w�肳�ꂽX��ԍ��́AX��I�u�W�F�N�g CDcdGridYColumn �̃|�C���^��
	  	�擾���邱�Ƃ��ł��܂��B���̃|�C���^���g���āAX��ɑ΂��鑀���
	  	�s�����Ƃ��ł��܂��B
	   @param iXColumnNumber [in] 
	  	 X��ԍ����w�肵�Ă��������B�͈͂́A-1�ȏ� getXColumnCount() �����ł��B
	  	 �������A INT_MAX ���w�肷��ƁA�ŏIX����w�肵�����ƂɂȂ�܂��B
	   @return
	  	 �Ή�����X��I�u�W�F�N�g��Ԃ��܂��B
	  	 �C���f�N�X���s���ȏꍇ�́ANULL��Ԃ��܂��B
	  
	  	  �Ԃ��ꂽ�I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
	  	  �Y������X�� CDcdGrid �̕ʂ̃��\�b�h�ɂ���č폜�����ƁA�Ԃ��ꂽ
	  	�|�C���^�͖����ɂȂ�܂��B
	  	   this���j�����ꂽ�Ƃ��ɂ��A�Ԃ��ꂽ�|�C���^�͖����ɂȂ�܂��B
	 */
	virtual CDcdGridXColumn*	getXColumn( int iXColumnNumber )  ;

	/**
	  	  �w�肳�ꂽX��ԍ��́A�r���I�u�W�F�N�g CDcdGridXBorder �̃|�C���^��
	  	�擾���邱�Ƃ��ł��܂��B���̃|�C���^���g���āAX��̌r���ɑ΂��鑀���
	  	�s�����Ƃ��ł��܂��B
	   @param iXColumnNumber [in] 
	  	 X��ԍ����w�肵�Ă��������B�͈͂́A-1�ȏ� getYColumnCount() �����ł��B
	  	-	-1 ;	���[�̌r���I�u�W�F�N�g�im_CDcdGridXBorderTop�j��Ԃ��܂��B
	  	-	getXColumnCount()-1 , INT_MAX ;	
	  		�E�[�̌r���I�u�W�F�N�g�im_CDcdGridXBorderBottom�j��Ԃ��܂��B
	   @return
	  	 �Ή�����X��r���I�u�W�F�N�g��Ԃ��܂��B
	  	 �C���f�N�X���s���ȏꍇ�́ANULL��Ԃ��܂��B
	  
	  	  �Ԃ��ꂽ�I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
	  	  �Y������X�� CDcdGrid �̕ʂ̃��\�b�h�ɂ���č폜�����ƁA�Ԃ��ꂽ
	  	�|�C���^�͖����ɂȂ�܂��B
	  	   this���j�����ꂽ�Ƃ��ɂ��A�Ԃ��ꂽ�|�C���^�͖����ɂȂ�܂��B
	 */
	virtual CDcdGridXBorder*	getXBorder( int iXColumnNumber )  ;

	/**
	@return
		�O���b�h�̊O�g�̘g���I�u�W�F�N�g��Ԃ��܂��B
		�E�[�̃I�u�W�F�N�g��Ԃ��܂��B
	*/
	virtual CDcdGridXBorder* getCDcdGridXBorderBottom()
	{ return &m_CDcdGridXBorderBottom ;};

	/**
		�w��� CDcdGridYColumn �I�u�W�F�N�g�́A��ԍ���Ԃ��܂��B
	@param pCDcdGridYColumn [in]
		YColumn �I�u�W�F�N�g���w�肵�Ă��������B
	@return
		��ԍ���Ԃ��܂��B�͈͂� 0 �ȏ� getYColumnCount() �����ł��B
		Y��I�u�W�F�N�g�� CDcdGrid �I�u�W�F�N�g�ɏW�񂳂�Ă��Ȃ��ꍇ�́A
		INT_MIN ��Ԃ��܂��B
	*/
	virtual int getYColumnNumberOfCoulmn( CDcdGridYColumn*	pCDcdGridYColumn ) ;
	/**
		@see YColumnNumberOfCoulmn() 
	*/
	virtual int getXColumnNumberOfCoulmn( CDcdGridXColumn*	pCDcdGridXColumn ) ;

	/**
		�w��� CDcdGridYBorder �I�u�W�F�N�g�́A��ԍ���Ԃ��܂��B
	@param pCDcdGridYBorder [in]
		YBorder �I�u�W�F�N�g���w�肵�Ă��������B
	@return
		��ԍ���Ԃ��܂��B�͈͂� -1 �ȏ� getYColumnCount() �����ł��B
		�I�u�W�F�N�g�� CDcdGrid �I�u�W�F�N�g�ɏW�񂳂�Ă��Ȃ��ꍇ�́A
		INT_MIN ��Ԃ��܂��B
	 	-	-1 ;	��[�̌r���I�u�W�F�N�g�im_CDcdGridYBorderTop�j
	 	-	getYColumnCount()-1  ;	���[�̌r���I�u�W�F�N�g�im_CDcdGridYBorderBottom�j�E	@n
		�������� m_CDcdGridYColumnCont �̖����̗v�f�ł��B
	*/
	virtual int getYColumnNumberOfBorder( CDcdGridYBorder*	pCDcdGridYBorder ) ;

	
	/**
		�w��� CDcdGridXBorder �I�u�W�F�N�g�́A��ԍ���Ԃ��܂��B
	@param pCDcdGridXBorder [in]
		XBorder �I�u�W�F�N�g���w�肵�Ă��������B
	@return
		��ԍ���Ԃ��܂��B�͈͂� -1 �ȏ� getXColumnCount() �����ł��B
		�I�u�W�F�N�g�� CDcdGrid �I�u�W�F�N�g�ɏW�񂳂�Ă��Ȃ��ꍇ�́A
		INT_MIN ��Ԃ��܂��B
	 	-	-1 ;	���[�̌r���I�u�W�F�N�g�im_CDcdGridXBorderTop�j
	 	-	getXColumnCount()-1  ;	�E�[�̌r���I�u�W�F�N�g�im_CDcdGridXBorderBottom�j�E	@n
		�������� m_CDcdGridXColumnCont �̖����̗v�f�ł��B
	*/
	virtual int getXColumnNumberOfBorder( CDcdGridXBorder*	pCDcdGridXBorder ) ;

	/**
	  	  �w�肳�ꂽY��EX��ԍ��́A�Z���I�u�W�F�N�g CDcdGridCell �̃|�C���^��
	  	�擾���邱�Ƃ��ł��܂��B���̃|�C���^���g���āA�Z���ɑ΂��鑀���
	  	�s�����Ƃ��ł��܂��B
	   @param iXColumnNumber [in] 
	  	 X��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getYColumnCount() �����ł��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @param iYColumnNumber [in] 
	  	 Y��ԍ����w�肵�Ă��������B�͈͂́A0�ȏ� getYColumnCount() �����ł��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	  	  �Ή�����Z���I�u�W�F�N�g��Ԃ��܂��B
	  	  �C���f�N�X���s���ȏꍇ�́ANULL��Ԃ��܂��B
	  
	  	  �Ԃ��ꂽ�I�u�W�F�N�g�̔j���̐Ӗ��́Athis�ɂ���܂��B
	  	  �Y������X�� CDcdGrid �̕ʂ̃��\�b�h�ɂ���č폜�����ƁA�Ԃ��ꂽ
	  	�|�C���^�͖����ɂȂ�܂��B
	  	   this���j�����ꂽ�Ƃ��ɂ��A�Ԃ��ꂽ�|�C���^�͖����ɂȂ�܂��B
	 */
	virtual CDcdGridCell*	getCell( int iXColumnNumber , int iYColumnNumber );
 

	/**
		�w��� CDcdGridCell �I�u�W�F�N�g�́A��ԍ���Ԃ��܂��B
	@param pCDcdGridCell [in]
		CDcdGridCell �I�u�W�F�N�g���w�肵�Ă��������B
	@return
		X��ԍ���Ԃ��܂��B
		�I�u�W�F�N�g�� CDcdGrid �I�u�W�F�N�g�ɏW�񂳂�Ă��Ȃ��ꍇ�́A
		INT_MIN �ł��B
	*/
	virtual int getXColumnNumberOfCell( 
		CDcdGridCell* pCDcdGridCell ) ;
	/**
		�w��� CDcdGridCell �I�u�W�F�N�g�́A��ԍ���Ԃ��܂��B
	@param pCDcdGridCell [in]
		CDcdGridCell �I�u�W�F�N�g���w�肵�Ă��������B
	@return
		Y��ԍ���Ԃ��܂��B
		�I�u�W�F�N�g�� CDcdGrid �I�u�W�F�N�g�ɏW�񂳂�Ă��Ȃ��ꍇ�́A
		INT_MIN �ł��B
	*/
	virtual int getYColumnNumberOfCell( 
		CDcdGridCell* pCDcdGridCell ) ;
	
	///@}

 public:
	
	// ********************************
	///	@name Y��EX��̈ʒu
	// ********************************
	///@{
	/**
	  	Y��̈ʒu��Ԃ��܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iYColumnNumber [in]
	  	Y��ԍ����w�肵�Ă��������B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	  	Y��͈̔͂�Ԃ��܂��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	  	
	 */
	virtual CdDcdZone	getYColumnZone( 
			IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) ;
	/**
	  	X��̈ʒu��Ԃ��܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iXColumnNumber [in]
	  	X��ԍ����w�肵�Ă��������B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	  	X��͈̔͂�Ԃ��܂��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual CdDcdZone	getXColumnZone( 
			IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) ;
	
	/**
	  	Y��̉����̋��E���̈ʒu��Ԃ��܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iYColumnNumber [in]
	  	Y��ԍ����w�肵�Ă��������B�͈͂�-1�ȏ� getYColumnCount() �����ł��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	  	Y��̋��E���͈̔͂�Ԃ��܂��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual CdDcdZone	getYColumnBorderZone( 
			IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) ;

	/**
	  	X��̉E���̋��E���̈ʒu��Ԃ��܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iXColumnNumber [in]
	  	X��ԍ����w�肵�Ă��������B�͈͂�-1�ȏ� getXColumnCount() �����ł��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	  	X��̋��E���͈̔͂�Ԃ��܂��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual CdDcdZone	getXColumnBorderZone( 
			IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) ;

	/**
	  	�Z���̈ʒu��Ԃ��܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iXColumnNumber [in]
	  	X��ԍ����w�肵�Ă��������B�͈͂�0�ȏ� getXColumnCount() �����ł��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @param iYColumnNumber [in]
	  	Y��ԍ����w�肵�Ă��������B�͈͂�0�ȏ� getYColumnCount() �����ł��B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	  	�Z���̈ʒu��Ԃ��܂��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual CdDcdZoneXy	getCellZone( 
		IfDcdTarget* pIfDcdTarget , int iXColumnNumber , int iYColumnNumber ) ;

	/**
	  	Y���W�ɑΉ�����AY��ԍ��𒲂ׂ܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
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
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual int getYColumnNumberOfPos( 
		IfDcdTarget* pIfDcdTarget , int iPos , bool* pbIsBorder ) ;

	/**
	  	X���W�ɑΉ�����AX��ԍ��𒲂ׂ܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iPos [in]
	  	X���W���w�肵�Ă��������B
	   @param pbIsBorder [out]
	  	���̊֐��́A iPos �����E����ɂ���ꍇ�� true �A
	  	 iPos ����͈̔͂ɂ���Ȃ� false �ł��B
	   @return
	  	X��ԍ���Ԃ��܂��B
	  
	  	- X��ԍ� = -1 , *pbIsBorder=false : �O���b�h�̍��̊O���ł��B
	  	- X��ԍ� = -1 , *pbIsBorder=true : �O���b�h�̍��̋��E���ł��B
	  	- X��ԍ� = 0 �ȏ� getXColumnCount()���� , *pbIsBorder = false : 
	  		�O���b�h��X��͈͂ł��B
	  	- X��ԍ� = 0 �ȏ� getXColumnCount()���� , *pbIsBorder = true : 
	  		�O���b�h��X��E���̋��E���͈̔͂ł��B
	  	- X��ԍ� = getXColumnCount() , *pbIsBorder = false : 
	  		�O���b�h�̉E�̊O���ł��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual int getXColumnNumberOfPos( 
		IfDcdTarget* pIfDcdTarget , int iPos , bool* pbIsBorder ) ;


	/**
	  	X,Y ���W�ɑΉ�����A�Z���𒲂ׂ܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param aCdDcdPosXy [in]
	  	XY���W���w�肵�Ă��������B
	   @return
	  	�Z���I�u�W�F�N�g��Ԃ��܂��B
	  	�w��̍��W���Z���͈̔͂Ɉʒu���Ă��Ȃ��ꍇ�́ANULL��Ԃ��܂��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual CDcdGridCell* getCellOfPos( 
		IfDcdTarget* pIfDcdTarget , const CdDcdPosXy& aCdDcdPosXy ) ;

	///@}
 public:
	// ********************************
	///	@name	�X�N���[��
	// ********************************
	///@{
	
	///@see m_iXFixColumnCount
	virtual int	getXFixColumnCount() ;
	///@see m_iXFixColumnCount
	virtual CDcdGrid& setXFixColumnCount( int ev ) ;
	///@see m_iXFixafterColumnNumber
	virtual int	getXFixafterColumnNumber() ;
	///@see m_iXFixafterColumnNumber
	virtual CDcdGrid& setXFixafterColumnNumber( int ev ) ;
	///@see m_iYFixColumnCount
	virtual int	getYFixColumnCount() ;
	///@see m_iYFixColumnCount
	virtual CDcdGrid& setYFixColumnCount( int ev ) ;
	///@see m_iYFixafterColumnNumber
	virtual int	getYFixafterColumnNumber() ;
	///@see m_iYFixafterColumnNumber
	virtual CDcdGrid& setYFixafterColumnNumber( int ev ) ;
	
	/**
	  	�w��̕`��̈�ɂ����āA�P�y�[�W���̃X�N���[�����s�����ꍇ��
	  	 FixafterColumnNumber �����߂܂��B
	  
	  	���̊֐��́A FixafterColumnNumber ���w�肵���l�ɂȂ��Ă���ꍇ��
	  	�����āA�u�P�y�[�W���̃X�N���[��������ɂ́A FixafterColumnNumber 
	  	�������ɕύX����΂悢���v�����߂܂��B
	   @param pIfDcdTarget [in]
	  	�`��̈���w�肵�Ă��������B
	   @param iFixafterColumnNumber [in]
	  	�P�y�[�W���̃X�N���[�����s���ꍇ�̊�ɂȂ�A FixafterColumnNumber
	  	���w�肵�Ă��������B
	   @param bPagedown [in]
	  	- false ;	//	Pageup����(-����)�̃X�N���[��
	  	- true ;	//	Pagedown����(+����)�̃X�N���[��
	   @return 
	  	�P�y�[�W���̃X�N���[�����s�����߂́A�V����
	  	 FixafterColumnNumber ��Ԃ��܂��B@n
	  	bPagedown ���^�� getXColumnCount() �A
	  	bPagedown ���U�� getXFixColumnCount() - 1 �̏ꍇ�A
	  	����ȏ�̃X�N���[�����삪�ł��Ȃ����Ƃ������܂��B
	 */
	int calcXFixafterColumnNumberPagemove( IfDcdTarget* pIfDcdTarget , 
		int iFixafterColumnNumber , bool bPagedown ) ;
	
	/**
	  	�w��̕`��̈�ɂ����āA�P�y�[�W���̃X�N���[�����s�����ꍇ��
	  	 FixafterColumnNumber �����߂܂��B
	  
	  	���̊֐��́A FixafterColumnNumber ���w�肵���l�ɂȂ��Ă���ꍇ��
	  	�����āA�u�P�y�[�W���̃X�N���[��������ɂ́A FixafterColumnNumber 
	  	�������ɕύX����΂悢���v�����߂܂��B
	   @param pIfDcdTarget [in]
	  	�`��̈���w�肵�Ă��������B
	   @param iFixafterColumnNumber [in]
	  	�P�y�[�W���̃X�N���[�����s���ꍇ�̊�ɂȂ�A FixafterColumnNumber
	  	���w�肵�Ă��������B
	   @param bPagedown [in]
	  	- false ;	//	Pageup����(-����)�̃X�N���[��
	  	- true ;	//	Pagedown����(+����)�̃X�N���[��
	   @return 
	  	�P�y�[�W���̃X�N���[�����s�����߂́A�V����
	  	 FixafterColumnNumber ��Ԃ��܂��B@n
	  	bPagedown ���^�� getXColumnCount() �A
	  	bPagedown ���U�� getXFixColumnCount() - 1 �̏ꍇ�A
	  	����ȏ�̃X�N���[�����삪�ł��Ȃ����Ƃ������܂��B
	 */
	int calcYFixafterColumnNumberPagemove( IfDcdTarget* pIfDcdTarget , 
		int iFixafterColumnNumber , bool bPagedown ) ;

	/**
	  	Y��̈ʒu��Ԃ��܂����A�X�N���[���@�\�ɂ���Ĕ�\���ɂȂ��Ă���
	  	Y��i YFixafterColumnNumber �����j�̈ʒu���Ԃ��܂��B���̏ꍇ�A
	  	����Y��̈ʒu�́A�Œ�Y��ɏd�Ȃ�����A�O���b�h�̈�ԏ�������
	  	�Ȃ邱�Ƃ�����܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iYColumnNumber [in]
	  	Y��ԍ����w�肵�Ă��������B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	  	Y��͈̔͂�Ԃ��܂��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual CdDcdZone	getYColumnZoneOverlap( 
			IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) ;
	/**
	  	X��̈ʒu��Ԃ��܂����A�X�N���[���@�\�ɂ���Ĕ�\���ɂȂ��Ă���
	  	X��i XFixafterColumnNumber �����j�̈ʒu���Ԃ��܂��B���̏ꍇ�A
	  	����X��̈ʒu�́A�Œ�X��ɏd�Ȃ�����A�O���b�h�̈�ԍ���������
	  	�Ȃ邱�Ƃ�����܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iXColumnNumber [in]
	  	X��ԍ����w�肵�Ă��������B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	  	X��͈̔͂�Ԃ��܂��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual CdDcdZone	getXColumnZoneOverlap( 
			IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) ;

	/**
	  	�Z���̈ʒu��Ԃ��܂����A�X�N���[���@�\�ɂ���Ĕ�\���ɂȂ��Ă���
	  	�Z���̈ʒu���Ԃ��܂��B���̏ꍇ�A
	  	���̃Z���̈ʒu�́A�Œ�Y��EX��ɏd�Ȃ�����A
	  	�O���b�h�̈�ԍ��������E��ԏ�������
	  	�Ȃ邱�Ƃ�����܂��B
	   @param pIfDcdTarget [in]
	  	�`��Ώۂ��w�肵�Ă��������B 
	   @param iXColumnNumber [in]
	  	X��ԍ����w�肵�Ă��������B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @param iYColumnNumber [in]
	  	Y��ԍ����w�肵�Ă��������B
	  	INT_MAX �́A�ŏI����w�肵�����̂Ƃ݂Ȃ��܂��B
	   @return
	  	�Z���͈̔͂�Ԃ��܂��B
	  
	   @attention
	  	���̊֐��́AcreateZoneCacne�̉e�����󂯂܂��B
	  	�����̊֐� ��A�����ČĂяo���ꍇ�́A
	  	�O������ createZoneCache() ���Ăяo���ƁA
	  	�p�t�H�[�}���X�����P����܂��B
	 */
	virtual CdDcdZoneXy	getCellZoneOverlap( 
		IfDcdTarget* pIfDcdTarget , int iXColumnNumber , int iYColumnNumber ) ;
	
	///@}
 public:
	// ********************************
	///	@name	CDcdGrid-����
	// ********************************
	///@{
	/**
		���� Cell ����A�w�肳�ꂽ XColumn,YColumn�̐������ړ������ꏊ��
		Cell �����߂邱�Ƃ��ł��܂��B
		  �ړ��̍ۂ́AAttachedCell �̓X�L�b�v���Ĉړ����܂��B
		  �ړ��́A��� XColumn �E ���� YColumn ���ړ����܂��B
		  CDcdGrid �͈̔͂��z���Ă̈ړ��͍s���܂���B
		�͈͂��z���Ă̈ړ������悤�Ƃ����ꍇ�A
		�ړ���� Cell �� ColumnNumber �́A 0 �E 
		�܂��� ColumnCount - 1 �ƂȂ�܂��B
	 @param pCDcdGridCell [in]
		�ړ����̃Z�����w�肵�Ă��������B
	 @param iXColumnMoveCount [in]
		�ړ����� XColumn �̗ʂ��w�肵�Ă��������B
		XColumn �� ���̐��̏ꍇ�͍��ւ̈ړ��A
		���̐��̏ꍇ�͉E�ւ̈ړ��ƂȂ�܂��B
	 @param iYColumnMoveCount [in]
		�ړ����� YColumn �̗ʂ��w�肵�Ă��������B
		YColumn �� ���̐��̏ꍇ�͏�ւ̈ړ��A
		���̐��̏ꍇ�͉��ւ̈ړ��ƂȂ�܂��B
	 @param bSkipScrolloutColumn [in]
		�^�Ȃ�AScrolloutColumn ���щz���Ĉړ����܂��B
		�U�Ȃ�AScrolloutColumn �ւ��ړ����܂��B
		���̂Ƃ��A�K�v�Ȃ� �X�N���[�����܂�
		�iFixafterColumnNumber ��ύX���܂��j�B
	 @return 
		�ړ���̃Z����Ԃ��܂��B
	 */
	CDcdGridCell* calcMovedCell( CDcdGridCell* pCDcdGridCell , 
		int iXColumnMoveCount , int iYColumnMoveCount ,
		bool bSkipScrolloutColumn = false ) ;


	/**
		��ԍ� iXColumnNumber �S�̂��AIfDcdTarget�̗̈�Ɋ��S��
		�\�����邱�Ƃ̂ł���A�ŏ��� 
		XFixafterColumnNumber �����߂܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� pIfDcTarget �C���^�[�t�F�[�X���w�肵�Ă��������B
	 @param iXColumnNumber [in]
		�\�����s��������̗�ԍ����w�肵�Ă��������B
	 @return 
		��ԍ� iXColumnNumber �ɑ΂���
		"XFixafterColumnNumberMinForColumn"
		�i��ɑ΂���ŏ���FixafterColumnNumber�j��Ԃ��܂��B
		���̒l�̍ő�l�́A iXColumnNumber �ł��B
		FixafterColumnNumnberForColumnNumber �� iXColumnNumber ��
		�������ꍇ�AFocusCellColumnNumber �̗�S�̂��E�C���h�E��
		�\�������Ƃ͌���܂���B
		�i��̕����E�C���h�E�̃T�C�Y������قǑ傫���ꍇ��
		����ɂ�����܂��j@n
		iXColumnNumber �� FixColumn �̏ꍇ�́A�G���[������ -1 ��Ԃ��܂��B
	 */
	int calcXFixafterColumnNumberMinForColumn( 
		IfDcdTarget* pIfDcdTarget , int iXColumnNumber ) ;
	
	/**
		��ԍ� iYColumnNumber �S�̂��AIfDcdTarget�̗̈�Ɋ��S��
		�\�����邱�Ƃ̂ł���A�ŏ��� 
		YFixafterColumnNumber �����߂܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� pIfDcTarget �C���^�[�t�F�[�X���w�肵�Ă��������B
	 @param iYColumnNumber [in]
		�\�����s��������̗�ԍ����w�肵�Ă��������B
	 @return 
		��ԍ� iYColumnNumber �ɑ΂���
		"YFixafterColumnNumberMinForColumn"
		�i��ɑ΂���ŏ���FixafterColumnNumber�j��Ԃ��܂��B
		���̒l�̍ő�l�́A iYColumnNumber �ł��B
		FixafterColumnNumnberForColumnNumber �� iYColumnNumber ��
		�������ꍇ�AFocusCellColumnNumber �̗�S�̂��E�C���h�E��
		�\�������Ƃ͌���܂���B
		�i��̕����E�C���h�E�̃T�C�Y������قǑ傫���ꍇ��
		����ɂ�����܂��j@n
		iYColumnNumber �� FixColumn �̏ꍇ�́A�G���[������ -1 ��Ԃ��܂��B
	 */
	int calcYFixafterColumnNumberMinForColumn(
		IfDcdTarget* pIfDcdTarget , int iYColumnNumber ) ;

	/**
		IfDcdTarget�̗̈���őS���\���ł��Ă���
		�ő�� ColumnNumber �������߂܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� pIfDcTarget �C���^�[�t�F�[�X���w�肵�Ă��������B
	 @return 
		��ԍ� ��Ԃ��܂��B
		-	-1 ;	//	�S���\���ł��Ă���񂪂ЂƂ��Ȃ��ꍇ
	 */
	int getXColumnNumberMaxInDcdTarget( 
		IfDcdTarget* pIfDcdTarget ) ;
	
	/**
		IfDcdTarget�̗̈���őS���\���ł��Ă���
		�ő�� ColumnNumber �������߂܂��B
	 @param pIfDcdTarget [in]
		�`��Ώۂ� pIfDcTarget �C���^�[�t�F�[�X���w�肵�Ă��������B
	 @return 
		��ԍ� ��Ԃ��܂��B
		-	-1 ;	//	�S���\���ł��Ă���񂪂ЂƂ��Ȃ��ꍇ
	 */
	int getYColumnNumberMaxInDcdTarget( 
		IfDcdTarget* pIfDcdTarget ) ;
	
	///@}

};

} //namespace DcdGrid
} //namespace DcDrawLib

#endif /*CDcdGrid_h*/
