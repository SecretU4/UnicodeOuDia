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
//	CWndDcdGridEki.h
//	$Id: CWndDcdGridEki.h 261 2016-01-23 03:59:53Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWndDcdGridEki_h
#define  CWndDcdGridEki_h

#include "DcDraw\CDcdTextbox.h"
#include "DcdGrid\WndDcdGrid3\CWndDcdGrid.h"
#include "OuDlg\CKeyinputSenderToModalDlg.h"
#include "str\stringSplit.h"
#include "LogMsg\LogMsg.h"

#include "..\entDed\CentDedEki.h"
#include "..\DedRosenFileData\EditCmd\CRfEditCmd_Eki.h"
#include "EkiColSpec\CdEkiYColSpecCont.h"
#include "EkiColSpec\CdEkiXColSpecCont.h"

namespace ViewEki{

	using namespace OuMfc::OuDlg;
	using namespace DcDrawLib::DcDraw;
	using namespace DcDrawLib::DcdGrid::WndDcdGrid3;
	using namespace entDed ;
	using namespace EkiColSpec ;

// ****************************************************************
//	CWndDcdGridEki
// ****************************************************************
/**
	@brief
	�y�T�v�z CEkiView �ŗp����A�O���b�h�E�C���h�E�ł��B
 */
class CWndDcdGridEki : public CWndDcdGrid
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
	// ********************************
	///@name	����
	// ********************************
	///@{
	/**
		true�Ȃ�A�w�̃v���p�e�B���ύX���ꂽ�Ƃ��A
		���ׂẴ_�C���E��Ԃ̉w�������A
		�w�����`���ɐ��K�����܂��B

		[�w�̃v���p�e�B]�_�C�A���O�ŕύX�ł��܂��B

		����� true �ł��B
		���̑����́A .ini�t�@�C���ɕۑ�����܂��B
	*/
	bool m_bAdjustByEkijikokukeisiki ;
	///@}
	// --------------------------------
	///@name �����f�[�^
	// --------------------------------
	///@{
	/**
		���̕ϐ��� true �̂Ƃ��́A
		�r���[�̍X�V���A���Ƀr���[���A�N�e�B�u�������܂�
		�ۗ����Ă��܂��B
		
		�ʏ�� false �B
		�u�r���[���A�N�e�B�u�łȂ��Ƃ��̑S�X�V�v���i OnUpdate_All() �j�v
		����A
		�u�r���[���A�N�e�B�u�ɂȂ����Ƃ��v�܂ł� true �ɂȂ�܂��B
		
		�r���[���A�N�e�B�u�ȂƂ��� OnUpdate_All() ���Ăяo�����
		�r���[�̑S�X�V���s��ꂽ��A false�ɂȂ�܂��B
		
		�r���[����A�N�e�B�u�ȂƂ��� OnUpdate_All() ���Ăяo���ꂽ��
		true �ɂȂ�܂��B
		
		���̒l�� true �̏ꍇ�́AOnUpdate_All() �ȊO�̕����X�V��
		�S�čs���܂���B
		
		�����l�� true �ł��B
		���R�F OnUpdate_All()�ɂ��r���[�̍X�V����x���s���Ă��Ȃ�
		�ꍇ�́A�r���[�̕����I�ȍX�V�͂ł��Ȃ����߂ł��B
	 */
	bool m_bWaitForActivate  ;

	/**
		�����l��false�A����� OnUpdate() ���I�������� true �ɂȂ�܂��B
	*/
	bool m_bInitialUpdateComplete ;
	///@}
 public:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
	 @return
		�w����ɍ��킹������������ CDcdTextbox �I�u�W�F�N�g��
		�Ԃ��܂��B
	 */
	CDcdTextbox	getCDcdEkimei()const ;

	/**
	 @return
		�w�����`��
		�̗�ɍ��킹������������ CDcdTextbox �I�u�W�F�N�g��
		�Ԃ��܂��B
	 */
	CDcdTextbox	getCDcdEkijikokukeisiki()const ;

	/**
	 @return
		�w�����`��
		�̗�ɍ��킹������������ CDcdTextbox �I�u�W�F�N�g��
		�Ԃ��܂��B
	 */
	CDcdTextbox	getCDcdEkikibo()const ;

	/**
	 @return
		�w�̗�̉��̌r���Ɏg�p����y���̑�����Ԃ��܂��B\n
		�w�̑����Ɂw���E���x���ݒ肳��Ă��Ȃ��ꍇ�́A
		�w�̉��̌r���ɁA���̃y�����g���܂��B
	 */
	CdPenProp getCdPenPropNormal()const{	return CdPenProp( 1 ) ; } ; 
	/**
	 @return
		�w�̗�̉��̌r���Ɏg�p����y���̑�����Ԃ��܂��B\n
		�w�̑����Ɂw���E���x���ݒ肳��Ă���ꍇ�́A
		�w�̉��̌r���ɁA���̃y�����g���܂��B
	 */
	CdPenProp getCdPenPropBold()const{	return CdPenProp( 2 ) ; } ; 


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
	CdEkiXColSpecCont createXColSpecCont();


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
	CdEkiYColSpecCont createYColSpecCont();

	/**
	@return 
		�t�H�[�J�X�Z���̗�̕\�����e��Ԃ��܂��B
	*/
	CdEkiXColSpec getXColSpecOfFocus();

	/**
	@return 
		�t�H�[�J�X�Z���̗�̕\�����e��Ԃ��܂��B
	*/
	CdEkiYColSpec getYColSpecOfFocus() ;

	
	/**
	DcdGrid�ł̑I����e�ɉ������A�ҏW�R�}���h�I�u�W�F�N�g
	(CRfEditCmd_Eki)�𐶐����܂��B
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
	bool createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Eki>* ppCmd );

	///@}
protected:
	// --------------------------------
	///@name OnUpdate �̉����֐�
	// --------------------------------
	///@{
	/**
		�O���b�h�� Y��ԍ��Ŏw�肳�ꂽ��ɁA
		�w�w�x�̓��e��ݒ肵�܂��B

		�O���b�h�S�̂��X�V�̈�Ƃ��܂�( InvalidateGrid() )�B
	 @note
		�w�����̒��̋��E���̑������ϓ������ꍇ�́A
		Y��ԍ��Ŏw�肳�ꂽ�Z�������ł͂Ȃ��A
		���E���E����т����艺�̂��ׂẴZ���̍X�V���K�v�ɂȂ�܂��B
		����ɑΉ����邽�߁A CWndDcdGridEki �ł́A
		�w�̑����̍X�V�̂��тɃO���b�h�S����X�V���Ă��܂��B
	 @param iYColumnNumber [in]
		Y��ԍ����w�肵�Ă��������B
	 @param aCentDedEki [in]
		�w�w�x�I�u�W�F�N�g���w�肵�Ă��������B
	*/
	void OnUpdate_setCentDedEki_To_Column( int iYColumnNumber , 
			const CentDedEki& aCentDedEki ) ;

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
					�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂�	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	int OnEditCut_Process( BOOL bQueryEnable );
	/**	
		[�ҏW]-[�R�s�[]
	*/
	int OnEditCopy_Process( BOOL bQueryEnable );
	/**	
		[�ҏW]-[�\��t��]
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 ;	//	�t�H�[�J�X�Z���̈ʒu���s���ł��B
		-	-2 ;	//	�N���b�v�{�[�h�ɉw�̃f�[�^������܂���
		-	-3 ;	//	�N���b�v�{�[�h����̃f�[�^�擾�Ɏ��s  ;
	*/
	int OnEditPaste_Process( BOOL bQueryEnable );

	/**	
		[�ҏW]-[����]
	*/
	int OnEditClear_Process( BOOL bQueryEnable );

	/**	
		[�ҏW]-[�w��}��]
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	int  OnEDITEkiInsert_Process( BOOL bQueryEnable );

	/**	
		[�ҏW]-[�w�̔��]]
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	-1 :	���݂͎��s�ł��܂���B(�G���[���b�Z�[�W�͕\�����܂���)
		-	-2�ȉ�:	�G���[
	*/
	int  OnEditEkiInvert_Process( BOOL bQueryEnable );

	/**	
		[�ҏW]-[�w�̃v���p�e�B]
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	int  OnEDITEkiProp_Process( BOOL bQueryEnable );

	///@}

 public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	CWndDcdGridEki();
	virtual ~CWndDcdGridEki();

 protected:
	// ********************************
	///@name	CWndDcdGrid
	// ********************************
	///@{
	///@}
 public:
	// ********************************
	///@name CWndDcdGridEki-����
	// ********************************
	///@{
	bool getAdjustByEkijikokukeisiki()const ;
	int setAdjustByEkijikokukeisiki( bool value ) ;
	///@}
public:
	// ********************************
	///@name CEkiView ����̈Ϗ�
	// ********************************
	///@{
	/**
		View��OnUpdate���Ϗ�����܂��B
	*/
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	/**
		View��OnActivateView���Ϗ�����܂��B
	*/
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) ;
	///@}

public:
	// ********************************
	///@name CWndDcdGridEki-����
	// ********************************
	///@{



	/**
		���݃t�H�[�J�X�̂���Z���ɑΉ����āA
		�w�w�x�v���p�e�B�_�C�A���O���J���A
		�w�v���p�e�B�̕ҏW���s���܂��B
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
	int execEkiPropDlg( bool bInsert , BOOL bQueryEnable ) ;
	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// �A�g���r���[�g
public:

// �I�y���[�V����
public:
	//{{AFX_VIRTUAL(CWndDcdGridEki)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CWndDcdGridEki)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//[�ҏW]
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);
	afx_msg void OnEDITEkiInsert();
	afx_msg void OnUpdateEditEkiinsert(CCmdUI *pCmdUI);
	afx_msg void OnEDITEkiProp();
	afx_msg void OnUpdateEditEkiprop(CCmdUI *pCmdUI);
	afx_msg void OnEditEkiInvert();
	afx_msg void OnUpdateEditEkiInvert(CCmdUI *pCmdUI);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
};

} //namespace ViewEki

#endif /*CWndDcdGridEki_h*/
