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
//	CWndDcdGridRessyasyubetsu.h
//	$Id: CWndDcdGridRessyasyubetsu.h 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWndDcdGridRessyasyubetsu_h
#define  CWndDcdGridRessyasyubetsu_h

#include "DcdGrid/WndDcdGrid3/WndDcdGrid3.h"
#include "OuDlg/CKeyinputSenderToModalDlg.h"
#include "DcDraw/CDcdFreeLine.h"

#include "CDcdFreeLine_StyleSample.h"
#include "..\entDed\CconvCentDed.h"
#include "ViewRessyasyubetsu\RessyasyubetsuColSpec\RessyasyubetsuColSpec.h"

namespace ViewRessyasyubetsu{ 

	using namespace RessyasyubetsuColSpec ;
	using namespace DcDrawLib::DcdGrid::WndDcdGrid3 ;
// ****************************************************************
//	CWndDcdGridRessyasyubetsu
// ****************************************************************
/**
@brief
 �y�T�v�z CRessyasyubetsuView �ŗp����A�O���b�h�E�C���h�E�ł��B
 */
class CWndDcdGridRessyasyubetsu : public CWndDcdGrid
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	typedef CWndDcdGrid super ;

	/** 
		createCmd() ���\�b�h�Ő�������R�}���h�I�u�W�F�N�g�̎�ނ��w�肵�܂��B
	*/
	enum ECreateCmd
	{
		/**
		�@�r���[�̃t�H�[�J�X�ʒu�ɐV�K�A�C�e����}�����邽�߂̃R�}���h�𐶐����܂��B

		�@�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 
		 
		 - m_iIndexDst = �t�H�[�J�X�Z���̃A�C�e��Index�Am_iIndexSize = 0
		 - m_CentDedEkiCont = �V�K�쐬���̃A�C�e���̊���l
		 - CaMuiSelect = ���Y�A�C�e����I���B

		 �@�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ:

		 - m_iIndexDst = �����A�C�e��Index+1�Am_iIndexSize = 0
		 - m_CentDedEkiCont = �V�K�쐬���̃A�C�e���̊���l
		 - CaMuiSelect = ���Y�A�C�e����I���B

		 �@�r���[��ŕ����I��ON:

		 - NULL��Ԃ��܂�([14/05/18]��:�����I��OFF�̏ꍇ�Ɠ�������)

		�@�ȉ��̃��j���[�R�}���h�Ŏg�p���܂��B

		 - �\��t���E�A�C�e���̃v���p�e�B(��)�E�A�C�e����}�� @n
		    ��=�t�H�[�J�X�ʒu���V�K�A�C�e���ɂ���ꍇ�̂�
		*/
		ECreateCmd_NewItem , 

		/**
		�@�t�H�[�J�X�Z����̃A�C�e��1��ΏۂƂ����R�}���h�𐶐����܂��B

		�@�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 

		 - m_iIndexDst = �t�H�[�J�X�Z���̃A�C�e��Index�Am_iIndexSize = 1
		 - m_CentDedRessyaCont = �t�H�[�J�X�Z����̃A�C�e��1�̃R�s�[
		 - m_CaMuiSelect = �t�H�[�J�X�Z����̃A�C�e����I���B

		�@�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ: 

		 - NULL��Ԃ��܂��B

		�@�r���[��ŕ����I��ON

		 - NULL��Ԃ��܂�([14/05/18]��:�����I��OFF�̏ꍇ�Ɠ�������)

		�@�ȉ��̃��j���[�R�}���h�Ŏg�p���܂��B

		 - [�ҏW]-[���],[�ҏW]-[����]

		*/
		ECreateCmd_Focus , 

		/**
		�@�����̒P���܂��͕����I������Ă���A�C�e����ΏۂƂ���
		�R�}���h�𐶐����܂��B

		�@�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 

		 - m_iIndexDst = �t�H�[�J�X�Z���̃A�C�e��Index�Am_iIndexSize = 1
		 - m_CentDedRessyaCont = �t�H�[�J�X�Z���̂���A�C�e��1�̃R�s�[
		 - CaMuiSelect = ���Y��Ԃ�I���B

		�@�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ: 

		 - NULL��Ԃ��܂��B

		�@�r���[��ŕ����I��ON

		 - m_iIndexDst = �I������Ă���A�C�e���̐擪index
		 - m_iIndexSize = �I������Ă���A�C�e���̖���index-�擪index+1
		 - m_CentDedRessyaCont = �I������Ă���A�C�e���̐擪index����
		  ����index�܂ł̃A�C�e���̃R�s�[
		 - CaMuiSelect �́A�Z���I���ɍ��킹�ăA�C�e����I���B
		
		�@�ȉ��̃��j���[�R�}���h�Ŏg�p���܂��B

		 - �؂���E�R�s�[�E�����E
		 - �A�C�e���̃v���p�e�B(��) @n
		    ��=�t�H�[�J�X�ʒu�������A�C�e���ɂ���ꍇ�̂�
		*/
		ECreateCmd_Select , 

		/**
		�@�S�A�C�e����ΏۂƂ����R�}���h�𐶐����܂��B

		  �r���[��ŕ����I����OFF�E�t�H�[�J�X�Z���������A�C�e����ɂ���ꍇ: 
		
		 - m_iIndexDst = 0�Am_iIndexSize = �A�C�e���̐�
		 - m_CentDedRessyaCont = �S�A�C�e���̃R�s�[
		 - m_CaMuiSelect �́A�S�A�C�e����I���B

		  �r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K�A�C�e���ʒu�ɂ���ꍇ: 
		 
		 - m_iIndexDst = 0�Am_iIndexSize = �A�C�e���̐�
		 - m_CentDedRessyaCont = �S�A�C�e���̃R�s�[
		 - CaMuiSelect �́A�S�A�C�e����I���B

		  �r���[��ŕ����I��ON
		
		 - m_iIndexDst = �I������Ă���A�C�e���̐擪index
		 - m_iIndexSize = �I������Ă���A�C�e���̖���index-�擪index+1
		 - m_CentDedRessyaCont = �I������Ă���A�C�e���̐擪index����
			����index�܂ł̃A�C�e���̃R�s�[
		 - m_CaMuiSelect �́A�Z���̑I���ɍ��킹�ăA�C�e����I���B

		  �ȉ��̃��j���[�R�}���h�Ŏg�p���܂��B
			
		 - (�ΏۂȂ�)
		*/
		ECreateCmd_All ,
	};
private:
	// ********************************
	///@name	���
	// ********************************
	///@{
	/**
	  �e�E�C���h�E�ւ̃L�[���͂��_�@�� ModalDialog ���J���ꍇ�A
	 ���[�_���_�C�A���O�̓���̃G�f�B�b�g�R���g���[���ɁA
	 �L�[���̓��b�Z�[�W�i WM_KEYDOWN , WM_KEYUP �j��]�����܂��B
	
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́A�N���X���[�U�[�i�w�]�����E�C���h�E�x�j
		�ɂ���܂��B
		���̃I�u�W�F�N�g�́A this ��蒷���������Ȃ��Ă͂Ȃ�܂���B
		�s�v�ł���� NULL �ł����܂��܂���B
		�R���X�g���N�^�Ō��܂�܂��B
	 */
	CKeyinputSenderToModalDlg	m_CKeyinputSenderToModalDlg ;
	///@}

	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
	 �ʏ�� false �B
	���̃r���[���A�N�e�B�u�łȂ��Ƃ��� 
	�S�X�V�i OnUpdate_All() ���Ăяo���j���K�v�ɂȂ��Ă���A
	�r���[���A�N�e�B�u�ɂȂ�܂ł̊Ԃ��� true �ɂȂ�܂��B

	 ���̕ϐ��� true �̂Ƃ��́A
	�r���[�̍X�V���A���Ƀr���[���A�N�e�B�u�������܂�
	�ۗ����Ă��邱�Ƃ������܂��B

	 �r���[���A�N�e�B�u�łȂ��Ƃ��� OnUpdate_All() ��
	�v�����ꂽ��A���̕ϐ��� true �ɂ��A
	OnUpdate_All() �͎��s���܂���B

	 ���̒l�� true �̂Ƃ��ɁA�r���[���A�N�e�B�u�����ꂽ��A
	OnUpdate_All() �����s���܂��B
	 */
	bool m_bUpdate_All_Requested ;

	///@}
	
protected:
	// --------------------------------
	///@name	�����֐�
	// --------------------------------
	///@{


	/**
		�S�Ă�X��ɂ��Ă� �w��ԍ�-�\�����e�x�̑Ή��\�𐶐����܂��B
		�������ꂽ CdXColSpecCont() ����
		CdXColSpec �I�u�W�F�N�g��
		�擾���邱�Ƃɂ��A�e�񖈂ɕK�v�ȕ\�����e���擾���邱�Ƃ��ł��܂��B
	@return 
		�S�Ă�X��ɂ��Ă� �w��ԍ�-�\�����e�x�̑Ή��\�ł���
		 CdXColSpecCont �I�u�W�F�N�g��Ԃ��܂��B
		
	@attention
	 	���̊֐��� OnCreate() �E�y�т���ȑO��
	 	�Ăяo�����Ƃ��́A�߂�l��NULL��ԂɂȂ�܂��B
	 	�Ăяo�������ɒ��ӂ��Ă��������B

	@attention
		���̑Ή��\�́A CentDedEkiCont �ɕύX������
		�����疳���ɂȂ�܂��B���̂��߁ACentDedEkiCont  ��
		�ύX�̉\��������󋵂ł́A�Ή��\���č쐬����K�v������܂��B	
	*/
	CdRessyasyubetsuXColSpecCont createXColSpecCont();


	/**
		�S�Ă�Y��ɂ��Ă� �w��ԍ�-�\�����e�x�̑Ή��\�𐶐����܂��B
		�������ꂽ CdYColSpecCont() ����
		CdYColSpec �I�u�W�F�N�g��
		�擾���邱�Ƃɂ��A�e�񖈂ɕK�v�ȕ\�����e���擾���邱�Ƃ��ł��܂��B
	@return 
		�S�Ă�Y��ɂ��Ă� �w��ԍ�-�\�����e�x�̑Ή��\�ł���
		 CdYColSpecCont �I�u�W�F�N�g��Ԃ��܂��B
		
	@attention
	 	���̊֐��� OnCreate() �E�y�т���ȑO��
	 	�Ăяo�����Ƃ��́A�߂�l��NULL��ԂɂȂ�܂��B
	 	�Ăяo�������ɒ��ӂ��Ă��������B

	@attention
		���̑Ή��\�́A CentDedEkiCont �ɕύX������
		�����疳���ɂȂ�܂��B���̂��߁ACentDedEkiCont  ��
		�ύX�̉\��������󋵂ł́A�Ή��\���č쐬����K�v������܂��B	
	*/
	CdRessyasyubetsuYColSpecCont createYColSpecCont();

	/**
	@return 
		�t�H�[�J�X�Z���̗�̕\�����e��Ԃ��܂��B
	*/
	CdRessyasyubetsuXColSpec getXColSpecOfFocus();

	/**
	@return 
		�t�H�[�J�X�Z���̗�̕\�����e��Ԃ��܂��B
	*/
	CdRessyasyubetsuYColSpec getYColSpecOfFocus() ;
	
	/**
	DcdGrid�ł̑I����e�ɉ������A�ҏW�R�}���h�I�u�W�F�N�g
	(CRfEditCmd_Ressyasyubetsu)�𐶐����܂��B
	@param eCreateCmd [in]
		��������R�}���h�̎�ނ��w�肵�Ă��������B
	@param ppCmd [out] 
		���������R�}���h��Ԃ��܂��B
		NULL ���w�肷�邱�Ƃ��ł��܂��B���̏ꍇ�A���̊֐���
		�R�}���h�𐶐������ɁA�R�}���h�̐������\���ۂ�������Ԃ��܂��B
	@return
		ppCmd���L����Ou�ł���ꍇ�́A�R�}���h�̐����ɐ��������� true��Ԃ��܂��B
		ppCmd=NULL �̏ꍇ�́A�R�}���h�̐������\�ł����true��Ԃ��܂��B
		�R�}���h�������ł��Ȃ��ꍇ�� false ��Ԃ��܂��B
		�t�H�[�J�X�Z����I���Z������Ԃ̈ʒu�ɂȂ��ꍇ�́Afalse�ƂȂ�܂��B
	*/
	bool createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressyasyubetsu>* ppCmd );


	///@}
	// --------------------------------
	///@name OnUpdate �̉����֐�
	// --------------------------------
	///@{
	/**
	 �O���b�h�� �w���Y��ɁA
	�w��Ԏ�ʁx�̓��e��ݒ肵�܂��B
	�ݒ���s�����Z���́A�X�V�̈�Ƃ��܂��B
	@attention
		�O���b�h�� ��Ԏ�ʔԍ��� X��͍X�V���܂���B
		���̏����̂��߂ɂ́A�eY��ɑ΂��Ă��̊֐����Ăяo������ɁA
		�O���b�h�S�̂ɑ΂���
		OnUpdate_setRessyasyubetsuNoXColumn() ��
		�Ăяo���K�v������܂��B
	@param iYColumnNumber [in]
		Y��ԍ����w�肵�Ă��������B
	@param CentDedRessyasyubetsu [in]
		�w��Ԏ�ʁx�I�u�W�F�N�g���w�肵�Ă��������B
	*/
	void OnUpdate_setCentDedRessyasyubetsu_To_Column( 
		int iYColumnNumber , 
		const CentDedRessyasyubetsu& aCentDedRessyasyubetsu ) ;

	/**
	 ��Ԏ�ʔԍ����X�V���܂��B

	 �O���b�h�� ��Ԏ�ʔԍ��� X��ɁA
	"0"�`"9" �̔ԍ���ݒ肵�܂�(10�ڈȍ~�ɂ́A�󔒂�ݒ肵�܂�)�B

	 �ݒ���s�����Z���́A�X�V�̈�Ƃ��܂��B
	@note
		�w�����̒��̋��E���̑������ϓ������ꍇ�́A
		Y��ԍ��Ŏw�肳�ꂽ�Z�������ł͂Ȃ��A
		���E���E����т����艺�̂��ׂẴZ���̍X�V���K�v�ɂȂ�܂��B
		����ɑΉ����邽�߁A CWndDcdGridEki �ł́A
		�w�̑����̍X�V�̂��тɃO���b�h�S����X�V���Ă��܂��B
	*/
	void OnUpdate_setRessyasyubetsuNoXColumn() ;

	/**
	 OnUpdate() �̉����֐��ł��B
	�֘A����h�L�������g�̓��e���A���̃E�C���h�E�Ɋ��S��
	���f���܂��B

	 OnUpdate() �� pHint �� NULL �̍ۂ̓���ł��B

	 ���̂Ƃ��A�E�C���h�E�̍X�V�ĕ`����������܂��B
	 */
	virtual void  OnUpdate_All() ;
	///@}
protected:
	// --------------------------------
	///@name ���j���[�R�}���h�̉����֐�
	// --------------------------------
	///@{
	/**	
		[�ҏW]-[�؂���]
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 :	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
		-	-2 :	//	��Ԏ�ʂ�1�ł���΁A���̃��j���[�R�}���h�͖���
		-	-3 :	//�폜���悤�Ƃ��Ă����Ԏ�ʂ̗�Ԃ����݂��܂�
	*/
	int OnEditCut_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[�R�s�[]	
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
	*/
	int OnEditCopy_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[�\��t��]
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 :	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
		-	-2 :	//	�N���b�v�{�[�h�ɗ�Ԏ�ʂ̃f�[�^������܂���
		-	-3 ;	//	�N���b�v�{�[�h����̃f�[�^�擾�Ɏ��s  ;
	*/
	int OnEditPaste_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[����]
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 :	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
		-	-2 :	//	��Ԏ�ʂ�1�ł���΁A���̃��j���[�R�}���h�͖���
		-	-3 :	//�폜���悤�Ƃ��Ă����Ԏ�ʂ̗�Ԃ����݂��܂�
	*/
	int OnEditClear_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[��Ԏ�ʂ�}��]	*/
	int OnEDITRessyasyubetsuInsert_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[���]
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 :	//	�t�H�[�J�X�Z���̈ʒu������
	*/
	int OnRessyasyubetsuUp_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[����]	
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 :	//	�t�H�[�J�X�Z���̈ʒu������
	*/
	int OnRessyasyubetsuDown_Process( BOOL bQueryEnable );
	/**	[�ҏW]-[��Ԏ�ʂ̃v���p�e�B]	*/
	int OnEDITRessyasyubetsuProp_Process( BOOL bQueryEnable );
	///@}

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CWndDcdGridRessyasyubetsu();
	virtual ~CWndDcdGridRessyasyubetsu();

	// ********************************
	///@name	CDcdGrid
	// ********************************
	///@{
	///@}
protected:
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{

	// --------------------------------
	///@name	�C�x���g�����̂��߂̉��z�֐�
	// --------------------------------
	///@{
	///@}
 public:
	// ********************************
	///@name  CRessyasyubetsuView ����̈Ϗ�
	// ********************************
	///@{
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	///@}
public:
	// ********************************
	///@name CWndDcdGridRessyasyubetsu-����
	// ********************************
	///@{
	/**
		���݃t�H�[�J�X�̂���Z���ɑΉ����āA
		�w��Ԏ�ʁx�v���p�e�B�_�C�A���O���J���A
		��Ԏ�ʃv���p�e�B�̕ҏW���s���܂��B
	 @param bInsert [in]
		- true ;	�t�H�[�J�X�̂���Z���̈ʒu�ɁA
		�V�����w��}�����܂��B 
		- false ;	�t�H�[�J�X�̂���Z���̈ʒu�́A
		�w�̃v���p�e�B���X�V���܂��B
		(�t�H�[�J�X�Z�����A��ԉ��̋󔒂̗�ɂ���ꍇ�́A
		�����ւ̑}���Ƃ��ē��삵�܂�)
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
		-	-2 ;	//	�_�C�A���O�{�b�N�X�� Cancel ����܂����B
	*/
	int execRessyasyubetsuPropDlg( bool bInsert/*=false*/ ,BOOL bQueryEnable );
	///@}
	
// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// �A�g���r���[�g
public:

// �I�y���[�V����
public:
	//{{AFX_VIRTUAL(CWndDcdGridRessyasyubetsu)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CWndDcdGridRessyasyubetsu)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//[�ҏW]
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);
	afx_msg void OnEDITRessyasyubetsuInsert();
	afx_msg void OnUpdateRessyasyubetsuInsert(CCmdUI *pCmdUI);
	afx_msg void OnRessyasyubetsuUp();
	afx_msg void OnUpdateRessyasyubetsuUp(CCmdUI* pCmdUI);
	afx_msg void OnRessyasyubetsuDown();
	afx_msg void OnUpdateRessyasyubetsuDown(CCmdUI* pCmdUI);
	afx_msg void OnEDITRessyasyubetsuProp();
	afx_msg void OnUpdateRessyasyubetsuProp(CCmdUI *pCmdUI);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

} //namespace ViewRessyasyubetsu

#endif /*CWndDcdGridRessyasyubetsu_h*/
