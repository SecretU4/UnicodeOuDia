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
//	CaDcdGrid_PageSelector.h
// ****************************************************************
*/
/** @file */
#ifndef  CaDcdGrid_PageSelector_h
#define  CaDcdGrid_PageSelector_h

#include "DcdGrid\CDcdGrid.h"
#include "DcDraw\IfDcdTarget.h"

namespace DcDrawLib{
namespace DcdGrid{

// ****************************************************************
//	CaDcdGrid_PageSelector
// ****************************************************************
/**
   @brief
   �y�T�v�z
     CDcdGrid �̃A�_�v�^�ƂȂ�N���X�ł��B
     MFC �� DocView ���f���ɂ��������^����v���r���[���s���ہA
     �w��̈���y�[�W�ԍ��ɍ��킹�āACDcdGrid �̑������ꎞ�I��
   �ύX���܂��B
   
   �y�g�����z
   
   �P�D  ���炩���߁A �������v�����^��DC�^����v���r���[��ʂ�DC
  	�ɐڑ����� IfDcdTarget �I�u�W�F�N�g�𐶐����Ă��������B
      CDcdTargetPrinter ���A CDcdTargetMfcPrintInfo �I�u�W�F�N�g��
  	�������邱�ƂɂȂ�܂��B
   
   ��   CDcdTargetPrinter �E CDcdTargetMfcPrintPreview �I�u�W�F�N�g��
   �ΏۂƂ��� CaDcdTargetItemPosition ���쐬���A������w�肷�邱�Ƃ�
   �ł��܂��B
   
   �Q�D  ���̃N���X�̃I�u�W�F�N�g�𐶐����Ă��������B�R���X�g���N�^�ł́A
  	������s�� CDcdGrid �I�u�W�F�N�g�ƁA�`���ƂȂ� IfDcdTarget 
  	�I�u�W�F�N�g���w�肵�Ȃ��Ă͂Ȃ�܂���B
   
   ��  ���̃N���X�̃R���X�g���N�^�́A�ΏۂƂȂ� CDcdGrid �� IfDcdTarget 
   �����Ƃɂ��āA�e�y�[�W���Ƃ� X,Y ��
    FixafterCOlumnNumber( �X�N���[���ʒu ) ���v�Z���A�����̃R���e�i
    contiYFixafterColumnNumber �E contiXFixafterColumnNumber �ɕۑ����܂��B
   
   �R�D  setXPage() , setYPage() �E�܂��� setPage() ��
  	�y�[�W�ԍ����w�肵�Ă��������B
  	 this �̓y�[�W�ԍ��ɍ��킹�āA CDcdGrid �� FixafterColumnNumber ��
  	�ړ����܂��B
   
   @attention
  	MFC �ł̓y�[�W�ԍ��̒l�� 1 �N�_�ŕ\�����Ă��܂����A
  	���̃N���X�ł̓y�[�W�ԍ��� 0 �N�_�ŕ\�����܂��B
   
   �S�D  DcDraw() ���Ăяo���ƁA���̃y�[�W�̕`����s�����Ƃ��ł��܂��B
   
   �T�D  �f�X�g���N�^�́A this ���ύX���� CDcdGrid �̑�����߂��܂��B

   �U�D�@���̃N���X���g���Ĉ���������Ƃ́A�E�C���h�E�� CDcdGrid ��
   �ĕ`����s���Ă��������B

	@b�y���R�z@n
	�@����I����ɃE�C���h�E��̃O���b�h�̕\��������錻�ۂ�
	 �������邽�߂ł��B@n
	  ���̃N���X�́A������̓O���b�h�̃X�N���[���ʒu���ꎞ�I�ɕύX���܂��B
	  ���̂Ƃ��� m_pCWndDcdGrid �ɍĕ`�悪��������ƁA��ʂɂ͈ꎞ�I��
	�ʒu�̕ύX���ꂽ�O���b�h���`�悳��邽�߁A��ʂ�����܂��B
 */
class CaDcdGrid_PageSelector
{
// ********************************
///@name �֘A
// ********************************
///@{
 private:
	/**
	  	������s�� CDcdGrid �I�u�W�F�N�g�ł��B
	  	���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
	  	���̃I�u�W�F�N�g�� this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	  	�R���X�g���N�^�Ō��܂�܂��B
	 */
	CDcdGrid*	m_pCDcdGrid ;
	
	/**
	  	����^����v���r���[��ʂ� IfDcdTarget �I�u�W�F�N�g�B
	  	���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
	  	���̃I�u�W�F�N�g�� this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	  	�R���X�g���N�^�Ō��܂�܂��B
	 */
	 IfDcdTarget* m_pIfDcdTarget ;
	
///@}
// ********************************
///@name ����
// ********************************
///@{
 private:
	/**
	   	�v�����^�̈�����s���ꍇ�́A�y�[�W���� FixafterColumnNumber ��
	   	�ێ����Ă��܂��B
	   	  �K�v�ȃy�[�W���́A
	   	contiYFixafterColumnNumber.size() *  contiXFixafterColumnNumber.size() 
	   	�ƂȂ�܂��B
	 */
	std::deque<int>	m_contiYFixafterColumnNumber ;
	
	/**
	   @see m_contiYFixafterColumnNumber
	 */
	std::deque<int>	m_contiXFixafterColumnNumber ;
	
	/**
	  	X�����̃y�[�W�ԍ��B���̒l�́A 0 �ȏ� getXPageCount() �����ł��B
	   @attention
	  	MFC �ł̓y�[�W�ԍ��̒l�� 1 �N�_�ŕ\�����Ă��܂����A
	  	���̃N���X�ł̓y�[�W�ԍ��� 0 �N�_�ŕ\�����܂��B
	  	
	  	�����l�� 0 �ł����A���\�b�h�ŕύX�ł��܂��B
	 */
	int m_iXPage ;
	
	/**
	  	Y�����̃y�[�W�ԍ��B���̒l�́A 0 �ȏ� getYPageCount() �����ł��B
	   @attention
	  	MFC �ł̓y�[�W�ԍ��̒l�� 1 �N�_�ŕ\�����Ă��܂����A
	  	���̃N���X�ł̓y�[�W�ԍ��� 0 �N�_�ŕ\�����܂��B
	  	
	  	�����l�� 0 �ł����A���\�b�h�ŕύX�ł��܂��B
	 */
	int m_iYPage ;
	
///@}
// --------------------------------
///@name �����f�[�^
// --------------------------------
///@{
 private:
	/**
	  	�R���X�g���N�^�̎��_�ł́A m_pCDcdGrid �� FixafterColumnNumber ��
	  	�ێ����܂��B
	  	���̒l�́A�f�X�g���N�^��  m_pCDcdGrid �ɕ��A���܂��B
	 */
	int m_iYFixafterColumnNumberSid ;

	/**
	   @see iYFixafterColumnNumberSid
	 */
	int m_iXFixafterColumnNumberSid ;
	
///@}
// ********************************
//	�R���X�g���N�^
// ********************************
 public:
	/**
	   @param pCDcdGrid [in]
	  	������s�� CDcdGrid �I�u�W�F�N�g�ł��B
	  	���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
	  	���̃I�u�W�F�N�g�� this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	  	�R���X�g���N�^�Ō��܂�܂��B
	   @param pIfDcdTarget [in]
	  	����^����v���r���[��ʂ� IfDcdTarget �I�u�W�F�N�g�B
	  	���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
	  	���̃I�u�W�F�N�g�� this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	  	�R���X�g���N�^�Ō��܂�܂��B
	 */
	
	CaDcdGrid_PageSelector( 
		CDcdGrid*	pCDcdGrid ,
		IfDcdTarget* pIfDcdTarget ) ;
	
	virtual ~CaDcdGrid_PageSelector() ;


// ********************************
//	CaDcdGrid_PageSelector
// ********************************
 public:
	// ********************************
	///@name CaDcdGrid_PageSelector �֘A
	// ********************************
	///@{
	virtual CDcdGrid*	getCDcdGrid() ;
	virtual IfDcdTarget* getIfDcdTarget() ;
	
	///@}
	// ********************************
	///@name CaDcdGrid_PageSelector ����
	// ********************************
	///@{
	virtual void getYFixafterColumnNumber( std::deque<int>* pvalue ) ;
	virtual void getXFixafterColumnNumber( std::deque<int>* pvalue ) ;

	/**
	  @return 
	  	Grid �̈���ɕK�v�ȃy�[�W�́AX�����̐���Ԃ��܂��B
	 */
	virtual int getXPageCount() ;

	/**
	   @return 
	  	Grid �̈���ɕK�v�ȃy�[�W�́AY�����̐���Ԃ��܂��B
	 */
	virtual int getYPageCount() ;

	virtual int getXPage() ;

	/**
	  	X�����̃y�[�W�ԍ����ړ����܂��B
	  	���̊֐��́A�y�[�W�ԍ���
	   ���킹�āA CDcdGrid �� FixafterColumnNumber ���ړ����܂��B
	   @param value [in]
	  	�y�[�W�ԍ����w�肵�Ă��������B
	  	���̒l�́A 0 �ȏ� getXPageCount() �����ł��B
	  	INT_MAX �́A�Ō�̃y�[�W���w�肵�����̂Ƃ݂Ȃ��܂��B
	 */
	virtual CaDcdGrid_PageSelector& setXPage( int value ) ;

	virtual int getYPage() ;

	/**
	  	X�����̃y�[�W�ԍ����ړ����܂��B
	  	���̊֐��́A�y�[�W�ԍ���
	   ���킹�āA CDcdGrid �� FixafterColumnNumber ���ړ����܂��B
	   @param value [in]
	  	�y�[�W�ԍ����w�肵�Ă��������B
	  	���̒l�́A 0 �ȏ� getYPageCount() �����ł��B
	  	INT_MAX �́A�Ō�̃y�[�W���w�肵�����̂Ƃ݂Ȃ��܂��B
	   @attention
	  	MFC �ł̓y�[�W�ԍ��̒l�� 1 �N�_�ŕ\�����Ă��܂����A
	  	���̃N���X�ł̓y�[�W�ԍ��� 0 �N�_�ŕ\�����܂��B
	 */
	virtual CaDcdGrid_PageSelector& setYPage( int value ) ;


	/**
	   @return 
	  	Grid �̈���ɕK�v�ȃy�[�W�̐���Ԃ��܂��B
	  	���̃y�[�W���́AX �����EY�����̃y�[�W���̐ςł��B
	 */
	virtual int getPageCount() ;

	/**
	   @return
	  	���ݕ\�����Ă���y�[�W�ԍ��ł��B
	  	���̃y�[�W�ԍ��́A�w�ώZ�y�[�W�ԍ��x�ł��B
	  
	  	<H4>
	  	�y�ώZ�y�[�W�ԍ��z
	  	</H4>
	  	�w�ώZ�y�[�W�ԍ��x�́A����̃y�[�W�̃y�[�W�ԍ����O�Ƃ��A
	  	�Ȍ�͉������������Ƀy�[�W�ԍ������Z�������̂ł��B
	  
	  	���Ƃ��΁AX�����̃y�[�W�����R�AY�����̃y�[�W�����S�̃O���b�h�̏ꍇ�A
	  
	  	- X�����y�[�W�ԍ�=0,Y�����y�[�W�ԍ�=0 �̐ώZ�y�[�W�ԍ� = 0 
	  	- X�����y�[�W�ԍ�=1,Y�����y�[�W�ԍ�=0 �̐ώZ�y�[�W�ԍ� = 1 
	  	- X�����y�[�W�ԍ�=2,Y�����y�[�W�ԍ�=0 �̐ώZ�y�[�W�ԍ� = 2 
	  	- X�����y�[�W�ԍ�=0,Y�����y�[�W�ԍ�=1 �̐ώZ�y�[�W�ԍ� = 3 
	  	- X�����y�[�W�ԍ�=1,Y�����y�[�W�ԍ�=1 �̐ώZ�y�[�W�ԍ� = 4 
	  
	  	�ƂȂ�܂��B
	  
	  	�l�͈̔͂́A 0 �ȏ� getPageCont() �����ł��B
	   @attention
	  	MFC �ł̓y�[�W�ԍ��̒l�� 1 �N�_�ŕ\�����Ă��܂����A
	  	���̃N���X�ł̓y�[�W�ԍ��� 0 �N�_�ŕ\�����܂��B
	 */
	virtual int getPage() ;


	/**
	  	�w�ώZ�y�[�W�ԍ��x���w�肵�܂��B
	  	@param iPage [in]
	  	�w�ώZ�y�[�W�ԍ��x���w�肵�Ă��������B
	  	�l�͈̔͂́A 0 �ȏ� getPageCont() �����ł��B
	  	�A���AINT_MAX ���w�肷��ƁA�ŏI�y�[�W���w�肵�����ƂɂȂ�܂��B
	 */
	virtual CaDcdGrid_PageSelector& setPage( int value ) ;
	
	///@}
	// ********************************
	///@name CaDcdGrid_PageSelector ����
	// ********************************
	///@{
	/**
	  	CDcdGrid �́Am_iPage �Ŏw�肳��Ă���y�[�W���A
	  	IfDcdTarget �ɏo�͂��܂��B
	   @return
	  	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B 
	 */
	virtual bool DcDraw() ;
	///@}
};


} //namespace DcdGrid
} //namespace DcDrawLib




#endif /*CaDcdGrid_PageSelector_h*/
