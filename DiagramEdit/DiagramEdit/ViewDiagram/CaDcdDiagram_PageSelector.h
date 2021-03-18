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
//	CaDcdDiagram_PageSelector.h
// ****************************************************************
*/
/** @file */
#ifndef  CaDcdDiagram_PageSelector_h
#define  CaDcdDiagram_PageSelector_h

#include "CDcdDiagram2.h"

namespace ViewDiagram{

// ****************************************************************
//	CaDcdDiagram_PageSelector
// ****************************************************************
/**
   @brief
   �y�T�v�z
     CDcdDiagram2 �̃A�_�v�^�ƂȂ�N���X�ł��B
  
     �_�C���O�����̈���ɕK�v�ȃy�[�W���𒲂ׂ܂��B
  �܂��A�w��̈���y�[�W�ԍ��ɍ��킹�āACDcdDiagtram2 �̑������ꎞ�I��
  �ύX���܂��B
   
   <H4>
   �y�g�����z
   </H4>
   
   �P�D  ���̃N���X�̃I�u�W�F�N�g�𐶐����Ă��������B�R���X�g���N�^�ł́A
  	������s�� CDcdDiagram2 �I�u�W�F�N�g���w�肵�Ȃ��Ă͂Ȃ�܂���B

    �� �I�u�W�F�N�g������AgetPageCount() ��0�Ȃ�A����ł���y�[�W�͂���܂���B
  	
   �Q�D  setXPage() , setYPage() �E�܂��� setPage() ��
  	�y�[�W�ԍ����w�肵�Ă��������B
  	 this �̓y�[�W�ԍ��ɍ��킹�āA CDcdDiagram2::Zone_Dgr ���ꎞ�I��
  	�ړ����܂��B
   
   @attention
  	MFC �ł̓y�[�W�ԍ��̒l�� 1 �N�_�ŕ\�����Ă��܂����A
  	���̃N���X�ł̓y�[�W�ԍ��� 0 �N�_�ŕ\�����܂��B
   
   �R�D  DcDraw() ���Ăяo���ƁA���̃y�[�W�̕`����s�����Ƃ��ł��܂��B
  	�����ɂ́A �������v�����^��DC�^����v���r���[��ʂ�DC
  	�ɐڑ����� IfDcdTarget �I�u�W�F�N�g���w�肵�Ă��������B
      CDcdTargetPrinter ���A CDcdTargetMfcPrintInfo �I�u�W�F�N�g��
  	�w�肷�邱�ƂɂȂ�܂��B
   
   �S�D  �f�X�g���N�^�́A this ���ύX���� CDcdGrid �̑�����߂��܂��B
   
 */
class CaDcdDiagram_PageSelector : public IfDcDraw
{
private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
		������s�� CDcdDiagram2 �I�u�W�F�N�g�ł��B
	  	���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
	  	���̃I�u�W�F�N�g�� this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	  	�R���X�g���N�^�Ō��܂�܂��B
	  
	  	���̃N���X�̃y�[�W���́A
	  	 m_pCDcdDiagram2->getZone_Dgr().getSize()
	  	���P�y�[�W�Ƃ��Čv�Z���܂��B
	 */
	CDcdDiagram2*	m_pCDcdDiagram2 ;
	///@}
private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
	  	�P�y�[�W������̃_�C�A�O�����̈���͈͂��A
	  	�w�_�C���O�����G���e�B�e�B���W�n�x�Ŏw�肵�܂��B
	  
	  	�R���X�g���N�^�Ō��܂�܂��B

		���̒l��X��0�Ȃ�AgetXPageCount() ��0�ɂȂ�܂��B
		���̒l��Y��0�Ȃ�AgetYPageCount() ��0�ɂȂ�܂��B
		���̏ꍇ�A getPageCount() �̖߂�l�� 0 �ɂȂ�܂��B
		 getPageCount() �� 0�̏ꍇ�A �_�C���O�����̈���͂ł��܂���B
	 */
	CdDcdSizeXy	m_sizePage_Dgr ;

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
private:
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
		�R���X�g���N�^�̎��_�ł́A 
		�_�C���O�����̕\�����(�ʒu�E�\���͈́E�g�嗦)��
		�ۑ����܂��B
		���̒l�́A�f�X�g���N�^��  m_pCDcdDiagram2 �ɕ��A���܂��B
	*/
	CconvContentPosToDcdTarget	m_CconvContentPosToDcdTargetPrev ;

	///@}
 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	 @param pCDcdDiagram2 [in]
		������s�� CDcdDiagram2 �I�u�W�F�N�g�ł��B
		���̃I�u�W�F�N�g�̔j���̐Ӗ��̓N���X���[�U�[�ɂ���܂��B
		���̃I�u�W�F�N�g�� this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
	@param sizePage_Dgr [in]
		�P�y�[�W������̃_�C�A�O�����̈���͈͂��A
		�w�_�C���O�����G���e�B�e�B���W�n�x�Ŏw�肵�Ă��������B
	*/
	
	CaDcdDiagram_PageSelector( 
		CDcdDiagram2*	pCDcdDiagram2 ,
		const CdDcdSizeXy&	sizePage_Dgr ) ;
	
	virtual ~CaDcdDiagram_PageSelector() ;

public:
	// ********************************
	///@name 	IfDcDraw
	// ********************************
	///@{
	/**
	   	�`���v�����܂��B
	   	���̊֐��́A pIfDcdTarget �ɁA�`����s���܂��B
	   @param pIfDcdTarget  [in]
	   	���̃I�u�W�F�N�g�ɕ`����s�킹����DC�Ɨ̈���w�肵�Ă��������B
	   @return
	   	�`����s�����ꍇ�͐^�E���̗̈�ւ̕`�悪�ł��Ȃ������ꍇ�͋U�ł��B
	  	<H4>
	  	�y�I�[�o���C�h�z
	  	</H4>
	  	���݂̃y�[�W�ԍ��i m_iXPage �Em_iYPage ) �̃_�C���O������
	  	�`�悵�܂��B
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
	  	<H4>
	  	�y�I�[�o���C�h�z
	  	</H4>
	  	���̃��\�b�h�̓T�|�[�g����܂���B false ��Ԃ��܂��B
	 */
	virtual bool getItemSize( IfDcdTarget* pIfDcdTarget , 
							CdDcdSizeXy* pCdDcdSizeXy ) ;
	
	///@}
public:
	// ********************************
	///@name CaDcdDiagram_PageSelector.�֘A
	// ********************************
	///@{
	CDcdDiagram2* getCDcdDiagram2(){	return m_pCDcdDiagram2 ;};
	
	///@}
	// ********************************
	///@name CaDcdDiagram_PageSelector.����
	// ********************************
	///@{
	CdDcdSizeXy	getPage_Dgr(){	return m_sizePage_Dgr ;};

	/**
	   @return 
	  	CDcdDiagram2 �̈���ɕK�v�ȃy�[�W�́AX�����̐���Ԃ��܂��B
		����ł��Ȃ��ꍇ�́A 0 ��Ԃ��܂��B
	 */
	virtual int getXPageCount() ;

	/**
	   @return 
	  	CDcdDiagram2 �̈���ɕK�v�ȃy�[�W�́AY�����̐���Ԃ��܂��B
		����ł��Ȃ��ꍇ�́A 0 ��Ԃ��܂��B
	 */
	virtual int getYPageCount() ;

	/**
	   @return 
	  	CDcdDiagram2 �̈���ɕK�v�ȃy�[�W�̐���Ԃ��܂��B
	  	���̃y�[�W���́AX �����EY�����̃y�[�W���̐ςł��B
		����ł��Ȃ��ꍇ�́A 0 ��Ԃ��܂��B
	 */
	virtual int getPageCount() ;
	
	virtual int getXPage() ;

	/**
	  	X�����̃y�[�W�ԍ����ړ����܂��B
	  	���̊֐��́A�y�[�W�ԍ���
	   ���킹�āA CDcdDiagram2 �� Zone_Dgr ���ړ����܂��B
	   @param value [in]
	  	�y�[�W�ԍ����w�肵�Ă��������B
	  	���̒l�́A 0 �ȏ� getXPageCount() �����ł��B
	  	INT_MAX �́A�Ō�̃y�[�W���w�肵�����̂Ƃ݂Ȃ��܂��B
	 */
	virtual CaDcdDiagram_PageSelector& setXPage( int value ) ;

	virtual int getYPage() ;

	/**
	  	X�����̃y�[�W�ԍ����ړ����܂��B
	  	���̊֐��́A�y�[�W�ԍ���
	   ���킹�āA CDcdDiagram2 �� Zone_Dgr ���ړ����܂��B
	   @param value [in]
	  	�y�[�W�ԍ����w�肵�Ă��������B
	  	���̒l�́A 0 �ȏ� getYPageCount() �����ł��B
	  	INT_MAX �́A�Ō�̃y�[�W���w�肵�����̂Ƃ݂Ȃ��܂��B
	   @attention
	  	MFC �ł̓y�[�W�ԍ��̒l�� 1 �N�_�ŕ\�����Ă��܂����A
	  	���̃N���X�ł̓y�[�W�ԍ��� 0 �N�_�ŕ\�����܂��B
	 */
	virtual CaDcdDiagram_PageSelector& setYPage( int value ) ;
	
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
	virtual CaDcdDiagram_PageSelector& setPage( int value ) ;
	
	///@}
	
};

} //namespace ViewDiagram


#endif /*CaDcdDiagram_PageSelector_h*/
