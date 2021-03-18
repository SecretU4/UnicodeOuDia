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
//	CDcdGridCell.h
// ****************************************************************
*/
/** @file */
#ifndef  CDcdGridCell_h
#define  CDcdGridCell_h
#include <deque>


#include "DcDraw/IfDcDraw.h"
#include "NsOu/Ou.h"

namespace DcDrawLib{
namespace DcdGrid{
	using namespace OuLib::NsOu;
	using namespace DcDraw;

// ****************************************************************
//	CDcdGridCell
// ****************************************************************
/**
 @brief
 �y�T�v�z
	DcdGrid �̃Z���I�u�W�F�N�g�ł��B

	IfDcDraw �I�u�W�F�N�g�Ɗ֘A������� ���� IfDcDraw �I�u�W�F�N�g���g����
	�Z���̒��g��`�悵�܂��B

	CDcdGrid �́A�ʏ�� CDcdTextbox �I�u�W�F�N�g�𐶐����āA
	this �Ɗ֘A���� IfDcDraw �I�u�W�F�N�g�Ƃ��ēo�^���܂��

 */
class CDcdGridCell
{
	friend class CDcdGrid ;

	typedef	std::deque< CDcdGridCell* > CDcdGridYColumnCellCont ;
private:
	// ********************************
	/// @name 	CDcdGrid �Ɋ֌W���鑮��/�֘A
	// ********************************
	///@{
	/**
		���̃I�u�W�F�N�g��ێ�����O���b�h�I�u�W�F�N�g�ւ̃|�C���^�ł��B
		�R���X�g���N�^�Ō��܂�܂��B
		�j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́Athis���������������Ȃ��Ă͂Ȃ�܂���B

		���̊֘A�́A	m_iYAttachCellCount , m_iXAttachCellCount ���ύX���ꂽ����
		���̂��ׂẴZ���̑������X�V����̂Ɏg���܂��B
	*/
	CDcdGrid*	m_pCDcdGrid ;
	/**
		���̃I�u�W�F�N�g���W�񂵂Ă���R���e�i�ł��B
		���̃R���e�i�ɂ́A����Y��ɂ��� CDcdGridCell �I�u�W�F�N�g���i�[����Ă��܂��B

		���̊֘A�́ACDcdGrid ���AgetColumnNumberOfCell() ���s�����ɎQ�Ƃ��܂��B
		�R���X�g���N�^�Ō��܂�܂��B
	*/
	CDcdGridYColumnCellCont* m_pCont ;

	/**
		�ʏ��NULL�ł��B
		���̃Z���������Z���̈�ԍ���ȊO�Ɉʒu���Ă���ꍇ�́A
		���̃Z�����������Ă���ł�����ɂ�����̂��w���܂��B
		���̊֘A�́A CDcdGrid ���ݒ肵�܂��B
	 */
	CDcdGridCell*	m_pcellAttachTo ;

	///@}
 private:
	// ********************************
	/// @name CDcdGridCell �ŗL�̊֘A
	// ********************************
	///@{
	
	/**
		this �ɑ΂��錻�݂̕`��I�u�W�F�N�g���w���|�C���^�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�́A���̊֘A���L���ȊԂ͐������Ȃ��Ă͂Ȃ�܂���B
	
		�ʏ�́A CDcdGrid::OnCreateCell() ���C���X�^���X�𐶐��E�o�^���A
		 CDcdGrid::OnDeleteCell() ���C���X�^���X��o�^�����E�j�����܂��B
		
		�f�t�H���g��  CDcdGrid::OnCreateCell() �̎����́A
		CDcdTextbox �C���X�^���X�𐶐��E�o�^���܂��B
		���̂Ƃ��̑����́A
	
			- �t�H���g�̓X�g�b�N�I�u�W�F�N�g�� DEFAULT_GUI_FONT 
			- �e�L�X�g�z�u�� 
				CdDrawTextFormat::H_LEFT | 
				CdDrawTextFormat::V_SINGLELINT_CENTER
			- �w�i�F�� ��
			- �e�L�X�g�̏㉺�E���E�̘g�̈�̑����͘_���P�ʂłP
	
		�ƂȂ�܂��B
	 */
	Ou<IfDcDraw>			m_pIfDcDraw ;
	
	///@}
private:
	// ********************************
	/// @name CDcdGridCell �ŗL�̑���
	// ********************************
	///@{
	/**
		���̃Z����Y�����Ɍ������Ă���Z���̐��B
	
		- ���̃Z���������Z���̍���̃Z���̏ꍇ�́A
		�������Ă���Z����Y�����̐��ł��B
		- ���̃Z�����P�Ƃ̃Z���̏ꍇ��1�B
		- ���̃Z���������Z���̍���ȊO�ł���΁A���̒l�͈Ӗ��������܂���B
	
		�����l��1�B���\�b�h�ŕύX�ł��܂��B
	 */
	int	m_iYAttachCellCount ;

	/**
		���̃Z����X�����Ɍ������Ă���Z���̐��B
	
		- ���̃Z���������Z���̍���̃Z���̏ꍇ�́A
		�������Ă���Z����X�����̐��ł��B
		- ���̃Z�����P�Ƃ̃Z���̏ꍇ��1�B
		- ���̃Z���������Z���̍���ȊO�ł���΁A���̒l�͈Ӗ��������܂���B
	
		�����l��1�B���\�b�h�ŕύX�ł��܂��B
	 */
	int	m_iXAttachCellCount ;


	///@}

// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	 @param [in] pCDcdGrid 
		���̃I�u�W�F�N�g��ێ�����O���b�h�I�u�W�F�N�g�ւ̃|�C���^�ł��B
	 @param [in] pCDcdGridYColumnCellCont 
		CDcdGrid �ɂ����āA���̃I�u�W�F�N�g���W�񂷂�R���e�i�ւ̃|�C���^�ł��B
	 */
	CDcdGridCell( CDcdGrid*	pCDcdGrid , 
		CDcdGridYColumnCellCont* pCDcdGridYColumnCellCont  ) ;
	
 private:
	CDcdGridCell( const CDcdGridCell& ev ){} ;
	void operator=( CDcdGridCell& ev ) {};

// ********************************
//	CDcdGridCell
// ********************************
public:
	// ********************************
	/// @name 	CDcdGrid �Ɋ֌W���鑮��/�֘A
	// ********************************
	///@{
	CDcdGrid*	getCDcdGrid() ;


	/**
		�ʏ��NULL�ł��B
		���̃Z���������Z���̈�ԍ���ȊO�Ɉʒu���Ă���ꍇ�́A
		���̃Z�����������Ă���ł�����ɂ�����̂��w���܂��B
		���̊֘A�́A CDcdGrid ���ݒ肵�܂��B
	 */
	virtual CDcdGridCell*	getAttachTo() ;

	///@}
	// ********************************
	/// @name 	���/����
	// ********************************
	///@{
	///@}

	// ********************************
	/// @name	CDcdGridCell �ŗL�̊֘A
	// ********************************
	///@{
	virtual Ou<IfDcDraw> getIfDcDraw() ;
	virtual void setIfDcDraw( Ou<IfDcDraw> value ) ;


	///@}
	// ********************************
	/// @name CDcdGridCell �ŗL�̑���
	// ********************************
	///@{

	///@see m_iYAttachCellCount
	virtual int	getYAttachCellCount() ;
	
	///@see m_iXAttachCellCount
	virtual int	getXAttachCellCount() ;

	/**
		�����Z���̐���ݒ肵�܂��B
		�����̍���Ɉʒu����Z���ɁA���̒l��ݒ肵�Ă��������B
	
		�������A�Z���̐����O���b�h�͈̔͂��z���Ă���ꍇ�́A���K����
		�s���܂��B
	 @param iXAttachCellCount [in]
		X�����Ɍ�������Z���̐����w�肵�Ă��������B
	 @param iYAttachCellCount [in]
		Y�����Ɍ�������Z���̐����w�肵�Ă��������B
	 @return
		��������΂O�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	0 ;	//	�����Z���̐��ɕύX�͂���܂���B
		-	1 ;	//	�����Z���̐����ύX����܂����B
		-	-1 ;	//	�l�͈̔͂��s���ł�
	 */
	int	setAttachCellCount( 
		int iXAttachCellCount , 
		int iYAttachCellCount ) ;


	///@}
};

} //namespace DcdGrid
} //namespace DcDrawLib

#endif /*CDcdGridCell_h*/
