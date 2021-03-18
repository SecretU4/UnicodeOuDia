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
// ****************************************************************
//	$Id: CPropEditUi_Eki.h 357 2016-08-18 16:59:16Z okm $
// ****************************************************************

/** @file */
#ifndef  CPropEditUi_Eki_h
#define  CPropEditUi_Eki_h
#include <string>
#include "NsPropEditUi2\CPropEditUi2.h"
#include "entDed\CentDedEkiCont.h"

namespace ViewEki {

	using namespace std ;
	using namespace entDed ;
	using namespace OuLib::NsPropEditUi2 ;

/**
@brief
	CPropEditUi_Eki �ŕҏW���� UIDATA �\���̂ł�
*/
struct UIData_Eki
{
	/** �w�� */
	string strEkimei ;
	
	/** �w�����`�� 
	-	0�ȏ�: CentDedEki::EEkijikokukeisiki 
	-	-1 : �s��
	*/
	int iEkijikokukeisiki ;
	
	/** �w�K�� 
	-	0�ȏ�: CentDedEki::EEkikibo
	-	-1 : �s��
	*/
	int iEkikibo ;

	/** ���E������ 
	-	1: ���E������
	-	0: ���E���Ȃ�
	-	-1: �s��
	*/
	int  iKyoukaisen ;

	/** �_�C���O������ԏ��\���i����j 
	- 0�ȏ�: CentDedEki::EDiagramRessyajouhouHyouji 
	-	-1: �s��
	*/
	int iDiagramRessyajouhouHyoujiKudari ;

	/** �_�C���O������ԏ��\���i���j 
	- 0�ȏ�: CentDedEki::EDiagramRessyajouhouHyouji 
	-	-1: �s��
	*/
	int iDiagramRessyajouhouHyoujiNobori ;

	/**
		[�w�������w�����`���Ő��K��]�̐ݒ�ł��B
	*/
	bool bAdjustByEkijikokukeisiki ;

	UIData_Eki()
		: iEkijikokukeisiki( (int)CentDedEki::Jikokukeisiki_Hatsu )
		, iEkikibo( (int)CentDedEki::Ekikibo_Ippan ) 
		, iKyoukaisen( 0 ) // ���E���Ȃ�
		, iDiagramRessyajouhouHyoujiKudari( (int)CentDedEki::DiagramRessyajouhouHyouji_Origin )
		, iDiagramRessyajouhouHyoujiNobori( (int)CentDedEki::DiagramRessyajouhouHyouji_Origin )
		, bAdjustByEkijikokukeisiki( true )
	{
	}
};



/**
@brief
  �w�v���p�e�B�̕ҏW���s���N���X�ł��B
  
  ���̃N���X�͒��ۃN���X�ł��B
  ���̃N���X�́A�g�p����UI��(��FWindows,MFC)�ɂ͈ˑ����܂���B
�@�N���X���[�U�[�́A���̃N���X���p�����āA
 �w�I�[�o�[���C�g�̕K�v�ȃ��\�b�h2-UI�Ɉˑ����鏈���x�̉��z�֐��ɁA
 UI���Ɉˑ������������������Ă��������B


*/
class CPropEditUi_Eki : public CPropEditUi2< UIData_Eki >
{
public:
	// ********************************
	///@name �G���[���b�Z�[�W
	// ********************************
	///@{
	/// �w�����������܂�
	static const char* const ERRMSG_EKIMEI_TOO_LONG ;
	///@}
	

private:
	// ********************************
	///@name �֘A
	// ********************************
	///@{
	/**
	�@Target(�ҏW�Ώۂ̃v���p�e�B��ێ�����ϐ��ւ̃|�C���^)�B 
	�@�R���X�g���N�^�Ō��܂�܂��B
	*/
	Mu<CentDedEki*>* m_pTarget ;

	/**
		Target(�ҏW�Ώۂ̃v���p�e�B��ێ�����ϐ��ւ̃|�C���^)�B
		[�w�������w�����`���Ő��K��]�̐ݒ�ł��B
		�R���X�g���N�^�Ō��܂�܂��B
	*/
	bool* m_pbAdjustByEkijikokukeisiki ;
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
	//virtual void InitUiData( UIDATA* pUiData ) ;

	/**
		UiData �ɁATarget�̑����𔽉f���܂��B
		
		m_bNewItem �� false �̏ꍇ�ɂ����A CPropEditUi2::StartEdit() 
		����Ăяo����܂��B
		
		�N���X���[�U�[�́A���̊֐����I�[�o�[���C�h���āA
		Target �̓��e��UiData �ɔ��f���鏈�����������Ă��������B

	@param pUiData [out]
		UiData �̃I�u�W�F�N�g�B
	*/
	virtual void UiDataFromTarget( UIDATA* pUiData ) ; 

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
		bool bStartEdit );

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
		const UIDATA* pUiDataStartEdit ) ;
	
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
		const UIDATA* pUiDataStartEdit ) ;
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
		const std::string& strInfo = "" ) =0 ;
	
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

public:
	// ********************************
	//	�R���X�g���N�^
	// ********************************
	/**
	@param bNewItem [in]
		�ҏW�Ώۂ��w�肵�Ă��������B
		- true: �V�K�I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
		- false: �����I�u�W�F�N�g�ɑ΂���A�v���p�e�B�̕ҏW
	@param pTarget [in,out]
	�@Target(�ҏW�Ώۂ̃v���p�e�B��ێ�����ϐ��ւ̃|�C���^)�B 
	�@�R���X�g���N�^�Ō��܂�܂��B
	@param pbAdjustBuEkijikokukeisiki [in,out]
		�ҏW�ΏہB�R���X�g���N�^�Ō��܂�܂��B
		[�w�������w�����`���Ő��K��]�ł��B
	*/
	CPropEditUi_Eki( 
		bool bNewItem , 
		Mu<CentDedEki*>* pTarget ,
		bool* pbAdjustBuEkijikokukeisiki );
	
};

} //namespace ViewEki 



#endif /*CPropEditUi_Eki_h*/
