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
/** @file */
// ****************************************************************
//	CPropEditUi2.h
// ****************************************************************
#ifndef  OuLib_DocView_CPropEditUi2_h
#define  OuLib_DocView_CPropEditUi2_h

#include <string>

namespace OuLib{
namespace NsPropEditUi2{

/**
@brief
  �I�u�W�F�N�g�̃v���p�e�B�ƁA���̃v���p�e�B��ҏW����Ui�Ƃ̊Ԃł́A
�f�[�^�����̎菇�����������N���X�ł��B

�@���̃N���X�́ATarget,Ui,UiData ��3�̗v�f�̊Ԃł̃f�[�^�����̎菇��
�������܂��B
�@
Target
 --------------------------------

�@�ҏW�̑ΏۂƂȂ�v���p�e�B�����I�u�W�F�N�g�ł��B
�@�N���X���[�U�[�́A�T�u�N���X�̃����o�[�ϐ��Ƃ��āATarget �ւ̃|�C���^��
�ǉ����Ă��������B


Ui
 --------------------------------

�@�ҏW���s��Ui�̃I�u�W�F�N�g�ł��B
�@MFC�A�v���P�[�V�����̏ꍇ�AUi�͒ʏ�́ACDialog �̔h���N���X��
�I�u�W�F�N�g�ł��B
�@
�@�N���X���[�U�[�́A�T�u�N���X�̃����o�[�ϐ��Ƃ��āAUi�ւ̃|�C���^��ǉ�
���Ă��������B

UiData
 --------------------------------

�@Ui�̌��݂̕\�����e��ێ�����f�[�^�̃I�u�W�F�N�g�ł��B

�@UiData�̌^�́A�ʏ�͍\���̂ƂȂ�܂��B���̍\���̂ɂ́A Ui �̕\�����e��
�ׂĂ�ێ����邽�߂̃f�[�^�����o���������Ă��������B
  �Ⴆ�΁AUi��Ƀe�L�X�g�{�b�N�X������Ȃ�AUiData�ɂ́A���̃e�L�X�g
�{�b�N�X�̓��͓��e������ string �̃����o�[�ϐ����K�v�ł��B
�@
�@UiData�̌^�́ACPropEditUi2 �̃e���v���[�g���� ARG_UIDATA �Ŏw�肵�Ă��������B

�@UiData�̃C���X�^���X�́A CPropEditUi2 �ɂ���āA�����E�j������܂��B
�@
�@���̃N���X�́A���ۃ��\�b�h UiDataFromTarget(),UiDataToTarget() ��
�K�؂Ȏ����E�K�؂ȏ����ŌĂяo�����Ƃɂ��ATarget ��UiData �̊Ԃ�
�f�[�^�������s���܂��B�܂��A���ۃ��\�b�h UiDataToUi(),UiDataFromUi() �ŁA
 UiData �� Ui �Ƃ̃f�[�^�������s���܂��B�N���X���[�U�[�́A CPropEditUi2 ��
 �T�u�N���X�ŁA����璊�ۃ��\�b�h���������Ă��������B

�g����
 ================================
(1)�@�N���X���[�U�[�́A�v���p�e�B�̕ҏW�̊J�n���ɁACPropEditUi2 �N���X��
�h���N���X�̃I�u�W�F�N�g���쐬���A CPropEditUi2::StartEdit() ���Ăяo����
���������B

�@ CPropEditUi2::StartEdit() �́A UiDataFromTarget() �ŁATarget �̓��e��
 UiData �ɓ]�����܂��B���ɁAAdjustProp() ���Ăяo���āAUiData �𐳋K��
���܂��B���̌�A���K������ UiData �̓��e���A UiDataToUi() �� Ui �ɓ]�����܂��B

�@MFC�A�v���P�[�V�����̏ꍇ�A�N���X���[�U�[�́A�ʏ�� CDialog �̔h���N���X
�ƂȂ�܂��B CDialog::OnInitDialog() �ŁACPropEditUi2 �h���N���X��
�I�u�W�F�N�g�𐶐����A CPropEditUi2::StartEdit() ���Ăяo���Ă��������B

(2)�@Ui ��ŉ��炩�̕ύX���s��ꂽ��A OnUiChanged() ���Ăяo���Ă��������B

�@CPropEditUi2::OnUiChanged() �́A UiDataFromUi() �ŁAUi �̓��e�� UiData ��
�]��������A AdjustUiData() ���Ăяo���āAUiData �𐳋K�����܂��B
�@���̌�A���K������ UiData �̓��e���A UiDataToUi() �� Ui �ɓ]�����܂��B

�@MFC�A�v���P�[�V�����̏ꍇ�́AUi��̃e�L�X�g�{�b�N�X���� EN_KILLFOCUS 
�C�x���g������ꂽ�Ƃ��E�`�F�b�N�{�b�N�X���� BN_CLICKED �C�x���g��
����ꂽ�Ƃ��ɁA CPropEditUi2::OnUiChanged() ���Ăяo���Ă��������B

(3)�@�N���X���[�U�[�́A�ҏW��ƏI�����ɁA CPropEditUi2::EndEdit() ��
�Ăяo���Ă��������B CPropEditUi2::EndEdit()  ������I��������A
�N���X���[�U�[�́AUi ����āA�v���p�e�B�ҏW���I�����Ă��������B

�@ CPropEditUi2::EndEdit() �́AUiDataFromUi() �� Ui �̓��e�� UiData ��
�]��������A AdjustUiData() ��y��яo���āAUiData �𐳋K�����܂��B
����ɁA���K���������ʂ� �AUiDataToUi() �ɓ]�����܂��B
�@�����ŁA CPropEditUi2::EndEdit() �́A CheckUiData() ���Ăяo���āA
 UiData �̒l�̌��؂��s���܂��BUiData �̒l���s��(��F�L���͈͊O��A
�����G���[)�ł������ꍇ�́A CheckUiData() �̓G���[���b�Z�[�W��\�����܂��B
�܂��A SetFocus() �ŁA���̂��� Ui �Ƀt�H�[�J�X��ݒ肵�܂��B

@param ARG_UIDATA
  UiData �̌^���w�肵�Ă��������B�ʏ�́AUi��̕\�����e��ێ����邽�߂�
�f�[�^�����o�����\���̂��w�肵�Ă��������B
*/
template < class ARG_UIDATA >
class CPropEditUi2
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	/**
		UiData �̌^�B�e���v���[�g�p�����[�^�Ō��܂�܂��B
	*/
	typedef ARG_UIDATA	UIDATA ;

private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�ҏW�Ώۂ�ێ����܂��B�R���X�g���N�^�Ō��܂�܂��B
		
		- true: �V�K�I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
		- false: �����I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
	*/
	bool m_bNewItem ;
	
	/**
		UiData �̃I�u�W�F�N�g�B
		
		���̃I�u�W�F�N�g�̔j���̐Ӗ��́Athis �ɂ���܂��B
		this�́A StartEdit() ���ɁANewUiData() �ŃI�u�W�F�N�g�𐶐����A
		 EndEdit() ���ɁA DeleteUiData() �Ŕj�����܂��B

		NewUiData()�EDeleteUiData() ���I�[�o�[���C�h���邱�Ƃɂ��A
		UIDATA�̔h���N���X�̃C���X�^���X���AUiData �Ƃ��ėp���邱�Ƃ��ł��܂��B
	*/
	UIDATA* m_pUiData ;
	
	/**
		CPropEditUi2::StartEdit() �I�����_�ł� UiData �̃R�s�[�ł��B
		CPropEditUi2::StartEdit() �I���O�܂ł́A���̒l��NULL�ł��B
	*/
	UIDATA* m_pUiDataStartEdit ;
	
	
	/**
		�O��� AdjustUiData() ���s���_�ł́AUiData �̃R�s�[�ł��B
		CPropEditUi2::StartEdit() �I���O�܂ł́A���̒l��NULL�ł��B
	*/
	UIDATA* m_pUiDataPrev ;
	
	///@}
private:
    // ================================
    ///@name �����f�[�^
    // ================================
    ///@{
	/**
		�ʏ��false�Bpublic���\�b�h�����s���̊Ԃ�true�ł��B
		���\�b�h���ł�UI����ɂ��C�x���g���������A�ē�����������̂�
		�h�~���邽�߂̃t���O�ł��B
	*/
    bool m_bMethodProcessing ;
    ///@}

protected:
	// ================================
	/** @name �I�[�o�[���C�g�̕K�v�ȃ��\�b�h1-Target�Ɉˑ����鏈��
		Target �� UiData �Ƃ̊Ԃ̃f�[�^�����̂��߂̃��\�b�h�ł��B
		���̃O���[�v�̃��\�b�h�́A Ui �̊��ɂ͈ˑ����܂���B
	*/
	// ================================
	///@{
	
	/**
		UiData ���A�V�KTarget�̃v���p�e�B�̕ҏW�̂��߂�
		���������܂��B
		
		m_bNewItem �� true �̏ꍇ�ɂ����A CPropEditUi2::StartEdit() 
		����Ăяo����܂��B
	
		�ʏ�A UiData �́AUIDATA�̃f�t�H���g�R���X�g���N�^�ŏ���������܂��B
		�N���X���[�U�[�́AUiData �ɁA�f�t�H���g�R���X�g���N�^�ƈقȂ�
		�����l��^�������ꍇ�́A���̃����o�֐����I�[�o�[���C�h���Ă��������B

	@param pUiData [out]
		UiData �̃I�u�W�F�N�g�B
	*/
	virtual void InitUiData( UIDATA* pUiData ) { }

	/**
		UiData �ɁATarget�̑����𔽉f���܂��B
		
		m_bNewItem �� false �̏ꍇ�ɂ����A CPropEditUi2::StartEdit() 
		����Ăяo����܂��B
		
		�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
		Target �̓��e��UiData �ɔ��f���鏈�����������Ă��������B

	@param pUiData [out]
		UiData �̃I�u�W�F�N�g�B
	*/
	virtual void UiDataFromTarget( UIDATA* pUiData ) = 0 ; 

	/**
		UiData �̓��e�𐳋K�����܂��B
		
		CPropEditUi2::StartEdit(),CPropEditUi2::OnUiChanged(),
		CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
		����Ăяo����܂��B
		
		�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
		UiData�̃����o�̓��e�𐳋K�����鏈�����������Ă��������B
		
		���̊֐��ł́A���͓��e�ɑ΂���G���[���b�Z�[�W�̕\���͂����߂��܂���B
		�G���[���b�Z�[�W�̕\���́ACheckUiData() �ōs���Ă��������B
	
	���K���̗�
	 --------------------------------
	-	�e�L�X�g�{�b�N�X�ɑS�p�œ��͂��ꂽ�e�L�X�g���A���p�ɕϊ�����B
	-	����`�F�b�N�{�b�N�X��ON�̂Ƃ��ɂ̓e�L�X�g�{�b�N�X��L���A
		OFF�̎��ɂ͖���(�O���[)�ɂ���

	@param pUiData [in,out]
		UiData �̃I�u�W�F�N�g�B
	@param pUiDataPrev [in]
		�O��� AdjustUiData() �I����� UiData �̃R�s�[�ł��B
		���̊֐��ł́A pUiDataPrev �� pUiData �̒l���r���邱�Ƃɂ��A
		�u���񃆁[�U�[�ɂ���ĕύX���ꂽUiData�����o�[�v�𔻒f���邱�Ƃ�
		�ł��܂��B
		���̊֐��� CPropEditUi2::StartEdit() ����Ăяo���ꂽ�ꍇ�́A
		���̈�����NULL�ƂȂ�܂��B
	@param bStartEdit [in]
		- true: ���̊֐��́A CPropEditUi2::StartEdit() ����Ăяo����Ă��܂��B
			���̏ꍇ�́ApUiDataPrev �͖����ł��B
			�֐��ł́A UiData �̂��ׂẴf�[�^�̐��K�����s���Ă��������B
		- false: ���̊֐��́A CPropEditUi2::StartEdit() �ȊO����
			�Ăяo����Ă��܂��B
			pUiData �� pUiDataPrev ���r���邱�Ƃɂ��
			����ω����� UiData �����o�[�ϐ��𔻒f���邱�Ƃ��o���܂��B
			���̊֐��ł́AUiData �̂����A����ω������f�[�^�����o�[������
			���K�����Ă��������B
	
	
	���̊֐��̃R�[�f�B���O�̗�
	 --------------------------------
	@code
	virtual void AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )
	{
		if ( bStartEdit || pUiDataPrev->�����o�[�� != pUiData->�����o�[��)
		{
			// pUiData->�����o�[�� �̐��K�����s���R�[�h�B
		}
	}
	@endcode
	*/
	virtual void AdjustUiData( 
		UIDATA* pUiData , 
		const UIDATA* pUiDataPrev , 
		bool bStartEdit )=0;

	/**
		UiData �̓��e�����؂��A��肪����΃G���[���b�Z�[�W��\�����܂��B
		
		CPropEditUi2::EndEdit()
		����Ăяo����܂��B
		
		�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
		UiData�̃����o�̓��e�����؂��鏈�����������Ă��������B
		���͓��e�ɖ�肪����΁AShowError()�ŃG���[���b�Z�[�W��\�����A
		SetFocus()�ŁA�t�H�[�J�X����̂���UI�ɐݒ肵�Ă��������B
		
		�V�K�I�u�W�F�N�g�ɑ΂���v���p�e�B�̕ҏW�̏ꍇ�́A
		UiData�̂��ׂẴ����o�[�����؂���K�v������܂��B
		�܂��A�K�{�̃����o�[���u�����N�ł���ꍇ�́A
		�G���[���b�Z�[�W��\������ׂ��ł��B

		�����I�u�W�F�N�g�ɑ΂���v���p�e�B�ҏW�̏ꍇ�́A
		���[�U�[�ɂ���Ēl�̕ύX���ꂽ�����o�[�݂̂����؂��Ă��������B
		pUiData �� pUiDataStartEdit �Ƃ̊ԂňႢ�̂���f�[�^�����o�[���A
		���[�U�[�ɂ���Ēl�̕ύX���ꂽ�����o�[�ł��B
		
	@param bNewItem [in]
		-true: �V�K�I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
		-false: �����I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
	@param pUiData [in]
		UiData �̃I�u�W�F�N�g�B
	@param pUiDataStartEdit [in]
		StartEdit()�I����� UiData �̃R�s�[�ł��B
		���̊֐��ł́A pUiDataStartEdit �� pUiData �̒l���r���邱�Ƃɂ��A
		�u���[�U�[�ɂ���ĕύX���ꂽUiData�����o�[�v�𔻒f���邱�Ƃ�
		�ł��܂��B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		0�ȊO��Ԃ����ꍇ�A�߂�l�́ACPropEditUi2::EndEdit() ��
		�߂�l�ƂȂ�܂��B
		
	���̊֐��̃R�[�f�B���O�̗�
	 --------------------------------
	@code
	virtual int CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
	{
		int iRv = 0 ; 
		
		if ( bNewItem || pUiDataStartEdit->�����o�[�� != pUiData->�����o�[��)
		{
			//	pUiData->�����o�[�� �̌��؂��s���R�[�h�B
			
			if ( pUiData->�����o�[�� �ɃG���[������ )
			{
				ShowError( �G���[�̗��R������������ );
				SetFocus( offsetof( UIDATA , �����o�[�� ) );
				iRv = -1 ;
			}
		}
		return iRv ;
	}
	@endcode
	*/
	virtual int CheckUiData( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) = 0 ;
	
	/**
		UiData �̓��e���ATarget�ɔ��f���܂��B
		
		CPropEditUi2::EndEdit()
		����Ăяo����܂��B
		
		�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
		UiData�̃����o�̓��e���ATarget �̃v���p�e�B�ɔ��f���鏈����
		�������Ă��������B
		
		�V�K�I�u�W�F�N�g�ɑ΂���v���p�e�B�̕ҏW�̏ꍇ�́A
		UiData�̂��ׂẴ����o�[���ATarget�ɔ��f����K�v������܂��B

		�����I�u�W�F�N�g�ɑ΂���v���p�e�B�ҏW�̏ꍇ�́A
		���[�U�[�ɂ���Ēl�̕ύX���ꂽ�����o�[�݂̂�
		Target�ɔ��f���Ă��������B
		pUiData �� pUiDataStartEdit �Ƃ̊ԂňႢ�̂���f�[�^�����o�[���A
		���[�U�[�ɂ���Ēl�̕ύX���ꂽ�����o�[�ł��B
		
		CPropEditUi2 �́A CheckUiData() ������I��������ɂ���
		UiDataToTarget() ���Ăяo���܂��B
		�]���܂��āA���̊֐��ł́ACheckUiData() �ł���Ă���悤��
		�l�̌��؂��s���K�v�͂���܂���B
		
	@param bNewItem [in]
		-true: �V�K�I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
		-false: �����I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
	@param pUiData [in]
		UiData �̃I�u�W�F�N�g�B
	@param pUiDataStartEdit [in]
		StartEdit()�I����� UiData �̃R�s�[�ł��B
		���̊֐��ł́A pUiDataStartEdit �� pUiData �̒l���r���邱�Ƃɂ��A
		�u���[�U�[�ɂ���ĕύX���ꂽUiData�����o�[�v�𔻒f���邱�Ƃ�
		�ł��܂��B
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		0�ȊO��Ԃ����ꍇ�A�߂�l�́ACPropEditUi2::EndEdit() ��
		�߂�l�ƂȂ�܂��B
		
		
	���̊֐��̃R�[�f�B���O�̗�
	 --------------------------------
	@code
	virtual int UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) 
	{
		int iRv = 0 ; 
		
		if ( bNewItem || pUiDataStartEdit->�����o�[�� != pUiData->�����o�[��)
		{
			//	pUiData->�����o�[�� ���ATarget �ɔ��f����R�[�h
		}
		return iRv ;
	}
	@endcode
	*/
	virtual int UiDataToTarget( 
		bool bNewItem , 
		const UIDATA* pUiData , 
		const UIDATA* pUiDataStartEdit ) = 0 ;
	///@}

protected:
	// ================================
	/** @name �I�[�o�[���C�g�̕K�v�ȃ��\�b�h2-UI�Ɉˑ����鏈��
		UiData �� Ui �Ƃ̊Ԃ̃f�[�^�����̂��߂̃��\�b�h�ł��B
		���̃O���[�v�̃��\�b�h�́A Ui �̊�(Windows,MFC�Ȃ�)
		�Ɉˑ����鏈���������������܂��B
	*/
	// ================================
	///@{
	/**
		UiData�̓��e��Ui�ɔ��f���܂��B
		
		CPropEditUi2::StartEdit(),CPropEditUi2::OnUiChanged(),
		CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
		����Ăяo����܂��B
		
		�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
		UiData�̃����o�̓��e��Ui�ɕ\�����鏈�����������Ă��������B
	@param pUiData [in]
		UiData �̃I�u�W�F�N�g�B
	*/
	virtual void UiDataToUi( const UIDATA* pUiData )=0 ;
	
	
	/**
		Ui�̓��͓��e��UiData�ɔ��f���܂��B
		
		CPropEditUi2::OnUiChanged(),
		CPropEditUi2::OnUiDataChanged(),CPropEditUi2::EndEdit()
		����Ăяo����܂��B
		
		�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
		Ui �ւ̕ύX���e��UiData �ɔ��f���鏈�����������Ă��������B
	@param pUiData [out]
		UiData �̃I�u�W�F�N�g�B
	*/
	virtual void UiDataFromUi( UIDATA* pUiData ) =0 ;
	
	/**
		��ʏ�ɃG���[���b�Z�[�W��\�����܂��B

		�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
		�G���[���b�Z�[�W��\�����鏈�����������Ă��������B
		
		MFC�A�v���P�[�V�����ł́A�ʏ�́A���b�Z�[�W�{�b�N�X��\�����܂��B
	@param strErrorReason [in]
		�G���[�̓��e������������
	@param strInfo [in]
        �G���[�̕⏕��������������B�s�v�ł���΁A�󕶎����
        �w�肵�Ă��������B
	*/
	virtual void ShowError( 
		const std::string& strErrorReason ,
		const std::string& strInfo ) =0 ;
	
	/**
		Ui ��̓���̃R���g���[���ɁA�t�H�[�J�X��ݒ肵�܂��B

		�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
		�w�肳�ꂽ�R���g���[���Ƀt�H�[�J�X��ݒ肷�鏈�����������Ă��������B
		
	@param iOffsetofUiDataMember [in]
		�t�H�[�J�X��ݒ肷��ҏW���ڂ��w�肵�Ă��������B
		UiData���̑ΏۂƂȂ�f�[�^�����o�́A�\���̂̐擪�A�h���X�����
		�I�t�Z�b�g���w�肵�Ă��������B

	��:�t�H�[�J�X���AUiData�̃����o strNumber ����͂���R���g���[���ɐݒ�
		����ꍇ�́A�ȉ��̂悤�ɂ��Ă��������B
	@code
		SetFocus( offsetof(UIDATA,strNumber ) ) ;
	@endcode
	*/
	virtual void SetFocus( int iOffsetofUiDataMember ) =0 ;
	
	
	
	///@}

protected:
	// ================================
	/** @name UIDATA �̃I�u�W�F�N�g�����Ɋւ��郁�\�b�h
		UiData �� UIDATA�̔h���N���X�̃C���X�^���X���g�p����ꍇ�ɂ́A
		�����̃��\�b�h���I�[�o�[���C�h���Ă��������B
	*/
	// ================================
	///@{
	/**
		UiData �I�u�W�F�N�g�𐶐����܂��B
		
		CPropEditUi2::StartEdit() ����Ăяo����܂��B
		
		m_pUiData �� UIDATA �̔h���N���X�̃I�u�W�F�N�g�ɂ��邱�Ƃ��ł��܂��B
		���̏ꍇ�́A���̊֐����I�[�o�[���C�h���āA�h���N���X�̃I�u�W�F�N�g��
		�������鏈�����������Ă��������B
		
		NewUiData() ���I�[�o�[���C�h�����Ƃ��́A DeleteUiData() �E
		 CopyUiData() ���I�[�o�[���C�h����K�v������܂��B
	@return
		�������ꂽ�I�u�W�F�N�g�̃A�h���X��Ԃ��܂��B
	*/
	virtual UIDATA* NewUiData(){ return new UIDATA() ;}

	/**
		NewUiData() �Ő������� �I�u�W�F�N�g���폜���܂��B
		
		CPropEditUi2::EndEdit() �E�f�X�g���N�^����Ăяo����܂��B
		
		NewUiData() ���I�[�o�[���C�h�����ꍇ�́A DeleteUiData() ��
		�I�[�o�[���C�h���āA NewUiData() �Ő��������I�u�W�F�N�g���폜����
		�������������Ă��������B
	@param pUiData [in]
		�폜����I�u�W�F�N�g���w�肵�Ă��������B
	*/
	virtual void DeleteUiData( UIDATA* pUiData ){ delete pUiData ;} 

	/**
		UiData �I�u�W�F�N�g�̓��e���R�s�[���܂��B
		
		NewUiData() ���I�[�o�[���C�h�����ꍇ�́A CopyUiData() ��
		�I�[�o�[���C�h���āA NewUiData() �Ő��������I�u�W�F�N�g��
		�����o�[�����ׂăR�s�[���鏈�����������Ă��������B
	@param pDst [out]
		�R�s�[��̃I�u�W�F�N�g���w�肵�Ă��������B
	@param pSrc [in]
		�R�s�[���̃I�u�W�F�N�g���w�肵�Ă��������B
	*/
	virtual void CopyUiData( UIDATA* pDst , const UIDATA* pSrc )
	{ *pDst = *pSrc ;}

	///@}
protected:
	// ================================
	///@name	�����֐�
	// ================================
	///@{
	/**
		m_pUiData�Em_pUiDataStartEdit�Em_pUiDataPrev 
		���폜���ANULL�ɏ��������܂��B
	*/
	void DeleteUiDatas()
	{
		if ( m_pUiData != NULL )
		{
			DeleteUiData( m_pUiData ) ; 
			m_pUiData = NULL ; 
		}
		if ( m_pUiDataStartEdit != NULL )
		{
			DeleteUiData( m_pUiDataStartEdit ) ; 
			m_pUiDataStartEdit = NULL ; 
		}
		if ( m_pUiDataPrev != NULL )
		{
			DeleteUiData( m_pUiDataPrev ) ; 
			m_pUiDataPrev = NULL ; 
		}
	}
	///@}



public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	@param bNewItem [in]
		�ҏW�Ώۂ��w�肵�Ă��������B
		- true: �V�K�I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
		- false: �����I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
	*/
	CPropEditUi2( bool bNewItem )
		: m_bNewItem( bNewItem ) 
		, m_pUiData( NULL ) 
		, m_pUiDataStartEdit( NULL ) 
		, m_pUiDataPrev( NULL ) 
		, m_bMethodProcessing( false ) 
	{
	}
	virtual ~CPropEditUi2()
	{
		DeleteUiDatas() ;
	}
	

public:
	// ********************************
	///@name  CPropEditUi2-����
	// ********************************
	///@{
	/**
	@return
		���݂�UiData�ւ̃|�C���^�ł��B

	  ���̃|�C���^���g���āACPropEditUi2�̔h���N���X�O����A
	UiData��ύX���邱�Ƃ��ł��܂��B
	  UiData��h���N���X�O����ύX�����ꍇ�́A
	OnUiDataChanged() ���Ăяo���Ă��������B
	*/
	UIDATA* GetUiData()const{ return m_pUiData ;}
	///@}
public:
	// ********************************
	///@name  CPropEditUi2-����
	// ********************************
	///@{
	/**
		�ҏW������J�n���܂��B
		UiData��Target�̃f�[�^�ŏ��������A�����
		Ui�ɔ��f���܂��B

		�I�u�W�F�N�g�ɑ΂��đ���public���\�b�h�����s���ɁA
		���̃��\�b�h���Ăяo�����ꍇ(�ē������������ꍇ)�A
		���̃��\�b�h�͉��������Ƀ��^�[�����܂��B
	*/
    void StartEdit()
    {
        int iRv = 0;
        if (m_bMethodProcessing)
        {
            iRv = -11;  //  �ē��͂ł��܂���B
        }
        else
        {
            m_bMethodProcessing = true; //  �ē��}�~
            // --------------------------------
			
            if (iRv >= 0)
            {
				//	UiData �I�u�W�F�N�g�̔j���B
				DeleteUiDatas();

				//	UiData �I�u�W�F�N�g��������
				m_pUiData = NewUiData() ;
                if (m_bNewItem)
                {
                    InitUiData( m_pUiData );
                }
                else
                {
                    UiDataFromTarget( m_pUiData );
                }
                
 				//	UiData ��\��
                AdjustUiData( m_pUiData , NULL , true );
                UiDataToUi( m_pUiData );

				//	m_pUiDataStartEdit�E m_pUiDataPrev ��
				//	UiData�̃R�s�[��ێ�����
                m_pUiDataStartEdit = NewUiData() ;
                CopyUiData( m_pUiDataStartEdit , m_pUiData ) ;
                m_pUiDataPrev = NewUiData() ;
                CopyUiData( m_pUiDataPrev , m_pUiData ) ;
            }

            // --------------------------------
            m_bMethodProcessing = false;
        }
    }
	/**
		UI���ύX���ꂽ�Ƃ��ɌĂяo���Ă��������B
		UiData�ɁAUI�̃f�[�^����荞�݂܂��B
		���̌�AAdjustUiData() ��UiData �̐��K�����s���A
		���ʂ�UI�ɔ��f���܂��B

		�I�u�W�F�N�g�ɑ΂��đ���public���\�b�h�����s���ɁA
		���̃��\�b�h���Ăяo�����ꍇ(�ē������������ꍇ)�A
		���̃��\�b�h�͉��������Ƀ��^�[�����܂��B
	*/
	void OnUiChanged()
	{
	    int iRv = 0;
	    if (m_bMethodProcessing)
	    {
	        iRv = -11;  //  �ē��͂ł��܂���B
	    }
	    else
	    {
	        m_bMethodProcessing = true; //
	        // --------------------------------
	        if (iRv >= 0)
	        {
	            UiDataFromUi( m_pUiData );
                AdjustUiData( m_pUiData , m_pUiDataPrev , false );
                CopyUiData( m_pUiDataPrev , m_pUiData ) ;
	            UiDataToUi( m_pUiData );
	        }
	        // --------------------------------
	        m_bMethodProcessing = false; //
	    }
	}
	/**
		UI�͕ύX����Ă��Ȃ����AUiData���ύX���ꂽ�Ƃ���
		AdjustUiData() ��UiData �̐��K�����s���A
		���ʂ�UI�ɔ��f���܂��B

		�I�u�W�F�N�g�ɑ΂��đ���public���\�b�h�����s���ɁA
		���̃��\�b�h���Ăяo�����ꍇ(�ē������������ꍇ)�A
		���̃��\�b�h�͉��������Ƀ��^�[�����܂��B
	*/
    void OnUiDataChanged()
    {
        int iRv = 0;
        if (m_bMethodProcessing)
        {
            iRv = -11;  //  �ē��͂ł��܂���B
        }
        else
        {
            m_bMethodProcessing = true; //
            // --------------------------------
            if (iRv >= 0)
            {
                AdjustUiData( m_pUiData , m_pUiDataPrev , false );
                CopyUiData( m_pUiDataPrev , m_pUiData ) ;
	            UiDataToUi( m_pUiData );
            }

            // --------------------------------
            m_bMethodProcessing = false;
        }
	}
	/**
		�ҏW����̏I�������݂܂��B
		Ui����UiData�ɒl����荞�݁AAdjustUiData()��
		���؂��s���܂��B���̂Ƃ��A�G���[�����o���ꂽ��A
		ShowError() �ŃG���[��\�����A�����𒆒f���܂��B
		�G���[��������Ȃ��ꍇ�́AUiData�̒l��
		UiDataToTarget() �ŁATarget() �ɓ]�����܂��B

		�I�u�W�F�N�g�ɑ΂��đ���public���\�b�h�����s���ɁA
		���̃��\�b�h���Ăяo�����ꍇ(�ē������������ꍇ)�A
		�A���̃��\�b�h�͉��������Ƀ��^�[�����܂�(�߂�l��-11)
	
	@return
		����������0�ȏ�A�G���[�Ȃ畉�̐��ł��B
		-   -11: �ē��������������߁A���������Ƀ��^�[�����܂���
		-	0�ł�-11�ł��Ȃ�: CheckUiData(),UiDataToTarget() �̖߂�l�B
	*/
	int EndEdit()
	{
	    int iRv = 0;
	    if (m_bMethodProcessing)
	    {
	        iRv = -11;  //  �ē��͂ł��܂���B
	    }
	    else
	    {
	        m_bMethodProcessing = true; //
	        // --------------------------------
	        if (iRv >= 0)
	        {
	            UiDataFromUi( m_pUiData );
				AdjustUiData( m_pUiData , m_pUiDataPrev , false );
                CopyUiData( m_pUiDataPrev , m_pUiData ) ;
	            UiDataToUi( m_pUiData );
	        }
	        if (iRv >= 0)
	        {
	            int iResult = CheckUiData( 
	            	m_bNewItem , m_pUiData , m_pUiDataStartEdit ) ;
	            if (iResult != 0 )
	            {
	                iRv = iResult ;
	            }
	        }
	        if (iRv >= 0)
	        {
	            int iResult = UiDataToTarget( 
	            	m_bNewItem , m_pUiData , m_pUiDataStartEdit ) ;
	            if (iResult != 0 )
	            {
	                iRv = iResult ;
	            }
	        }
	        // --------------------------------
	        m_bMethodProcessing = false;
	    }
	    return iRv;
	}
	///@}

};

} //namespace NsPropEditUi2
} //namespace OuLib


#endif /*OuLib_DocView_CPropEditUi2_h*/
