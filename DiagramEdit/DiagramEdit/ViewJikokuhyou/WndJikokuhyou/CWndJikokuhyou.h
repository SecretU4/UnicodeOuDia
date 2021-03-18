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
//	CWndJikokuhyou.h
//	$Id: CWndJikokuhyou.h 368 2016-08-19 11:11:10Z okm $
// ****************************************************************
*/
/** @file */
#ifndef  CWndJikokuhyou_CWndJikokuhyou_h
#define  CWndJikokuhyou_CWndJikokuhyou_h

#include "NsOu/Ou.h"
#include "NsMu/CMup_vector.h"
#include "NsMu/CaMuCast.h"
#include "DcdGrid/WndDcdGrid3/WndDcdGrid3.h"
#include "CJikokuhyouDoc.h"
#include "..\..\DedRosenFileData\EditCmd\CRfEditCmd_Ressya.h"
#include "..\..\entDed\CentDedRosen.h"
#include "..\..\entDed\CentDedRessya_EkijikokuModifyOperation2.h"
#include "ViewJikokuhyou\WndJikokuhyou\CWjkStateMachine.h"
#include "ViewJikokuhyou\JikokuhyouColSpec\JikokuhyouColSpec.h"

namespace ViewJikokuhyou{ 
namespace WndJikokuhyou{
	
	using namespace DcDrawLib::DcdGrid::WndDcdGrid3;
	using namespace JikokuhyouColSpec;

// ****************************************************************
//	CWndJikokuhyou
// ****************************************************************
/**
@brief
�y�T�v�z CJikokuhyouView �ŗp����A�O���b�h�E�C���h�E�ł��B

@note
�@���̃E�C���h�E(WndDcdGrid3)�ŁAWM_IME_STARTCOMPOSITION ����������ƁA
��肪�������܂��B
�@IME��ON�ɂ�����Ԃŕ����L�[�������āw��Ԃ̃v���p�e�B�x�_�C�A���O��
�J�����Ƃ��ɁA�ϊ���╶���񂪃_�C�A���O�̃R���g���[���ɕ\������܂���B
�@�Ȃ��A�w�w�����̃v���p�e�B�x�_�C�A���O�ł́A�ϊ���╶���񂪃R���g���[����
 �\������܂���B����́A���R�͕s���ł��B

 */
class CWndJikokuhyou : public CWndDcdGrid
{
public:
	// ********************************
	//	�C���i�[�^�C�v
	// ********************************
	typedef CWndDcdGrid super ;

	friend class CWjkState ;
	friend class CWjkState_Ressyahensyu ;	
		//OnUpdate_setRessya,OnUpdate_All,OnUpdate_setAllRessyaBorder
	friend class CWjkState_Renzoku ;
		//OnUpdate_setRessya,OnUpdate_All,OnUpdate_setAllRessyaBorder

	/** �����\�r���[�̃��[�h��\���񋓂ł��B */
	enum EStateIdx 
	{
		StateIdx_Ressyahensyu = 0 ,	///< ��ԕҏW���[�h
		StateIdx_Renzoku ,			///< �A�����̓��[�h
	};

	/** �����\�r���[�̉w�����ł́u���בւ��v�̃��[�h��\���񋓂ł��B */
	enum EEkijikokuSort 
	{
		EEkijikokuSort_Ekiatsukai = 0 ,	///< �w���ł̃\�[�g
		EEkijikokuSort_Transfer ,	///< ��p�\�[�g
	};

	/** 
		createCmd() ���\�b�h�Ő�������R�}���h�I�u�W�F�N�g�̎�ނ��w�肵�܂��B
	*/
	enum ECreateCmd
	{
		/**
		�@�t�H�[�J�X�ʒu�ɐV�K��Ԃ�}�����邽�߂̃R�}���h�𐶐����܂��B

		�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z����������ԏ�ɂ���ꍇ: 
		 
		 - m_iIndexDst = �t�H�[�J�X�Z���̗��Index�Am_iIndexSize = 0
		 - m_CentDedRessyaCont = ����(NULL�ł͂Ȃ��B����̗��(��Ԏ��Index=0))
		 - CaMuiSelect = ���Y��Ԃ�I���B

		 �@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���ꍇ:

		 - m_iIndexDst = �������Index+1�Am_iIndexSize = 0
		 - m_CentDedRessyaCont = ����(NULL�ł͂Ȃ��B����̗��(��Ԏ��Index=0)��Ԏ��Index=0)
		 - CaMuiSelect = ���Y��Ԃ�I���B

		 �@�����\�r���[��ŕ����I��ON:

		 - NULL��Ԃ��܂�([14/05/18]��:�����I��OFF�̏ꍇ�Ɠ�������)

		�@�ȉ��̃��j���[�R�}���h�Ŏg�p���܂��B

		 - �\��t���E��Ԃ̃v���p�e�B(��)�E��Ԃ�}���E�w�����̃v���p�e�B(��) @n
		    ��=�t�H�[�J�X�ʒu���V�K�A�C�e���ɂ���ꍇ�̂�
		*/
		ECreateCmd_NewItem  , 

		/**
		�@�t�H�[�J�X�Z�����1��Ԃ�ΏۂƂ����R�}���h�𐶐����܂��B

		�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z����������ԏ�ɂ���ꍇ: 

		 - m_iIndexDst = �t�H�[�J�X�Z���̗��Index�Am_iIndexSize = 1
		 - m_CentDedRessyaCont = �t�H�[�J�X�Z����̗��1�̃R�s�[
		 - m_CaMuiSelect = �t�H�[�J�X�Z����̗�Ԃ�I���B

		�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���ꍇ: 

		 - NULL��Ԃ��܂��B

		�@�����\�r���[��ŕ����I��ON

		 - NULL��Ԃ��܂�([14/05/18]��:�����I��OFF�̏ꍇ�Ɠ�������)

		�@�ȉ��̃��j���[�R�}���h�Ŏg�p���܂��B

		  - �����̂ݓ\��t���E�A�����́E���ʉ��E���f @n
		  - �A�����̓��[�h�ł� ��������,[�����폜],[�ʉ�],[�ʉ�-���],[�o�R�Ȃ�]
		  
		*/
		ECreateCmd_Focus , 

		/**
		�@�����̒P���܂��͕����I������Ă����Ԃ�ΏۂƂ���
		�R�}���h�𐶐����܂��B

		�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z����������ԏ�ɂ���ꍇ: 

		 - m_iIndexDst = �t�H�[�J�X�Z���̗��Index�Am_iIndexSize = 1
		 - m_CentDedRessyaCont = �t�H�[�J�X�Z���̂�����1�̃R�s�[
		 - CaMuiSelect = ���Y��Ԃ�I���B

		�@�����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���ꍇ: 

		 - NULL��Ԃ��܂��B

		�@�����\�r���[��ŕ����I��ON

		 - m_iIndexDst = �I������Ă����Ԃ̐擪index
		 - m_iIndexSize = �I������Ă����Ԃ̖���index-�擪index+1
		 - m_CentDedRessyaCont = �I������Ă����Ԃ̐擪index����
		  ����index�܂ł̗�Ԃ̃R�s�[
		 - CaMuiSelect �́A�Z���I���ɍ��킹�ė�Ԃ�I���B
		
		�@�ȉ��̃��j���[�R�}���h�Ŏg�p���܂��B

		 - �؂���E�R�s�[�E�����E
		  ���������E�ʉ߁E�ʉ�-��ԁE�o�R�Ȃ��E���w�n���E���w�~�܂�E���f
		  �w�����̑}���E�w�������폜�E�w�����ύX�E�w�����ύX�̍Ď��s�E
		  �A��1���C��
		  - ��Ԃ̃v���p�e�B(��)�E�w�����̃v���p�e�B(��)
		    ��=�t�H�[�J�X�ʒu�������A�C�e���ɂ���ꍇ�̂�

		*/
		ECreateCmd_Select , 

		/**
		�@�S��Ԃ�ΏۂƂ����R�}���h�𐶐����܂��B

		  �����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z������ԏ�ɂ���ꍇ: 
		
		 - m_iIndexDst = 0�Am_iIndexSize = ��Ԃ̐�
		 - m_CentDedRessyaCont = �S��Ԃ̃R�s�[
		 - m_CaMuiSelect2 �́A�S��Ԃ�I���B

		  �����\�r���[��ŕ����I����OFF�E�t�H�[�J�X�Z�����V�K��Ԉʒu�ɂ���ꍇ: 
		 
		 - m_iIndexDst = 0�Am_iIndexSize = ��Ԃ̐�
		 - m_CentDedRessyaCont = �S��Ԃ̃R�s�[
		 - CaMuiSelect2 �́A�S��Ԃ�I���B

		  �����\�r���[��ŕ����I��ON
		
		 - m_iIndexDst = �I������Ă����Ԃ̐擪index
		 - m_iIndexSize = �I������Ă����Ԃ̖���index-�擪index+1
		 - m_CentDedRessyaCont = �I������Ă����Ԃ̐擪index����
			����index�܂ł̗�Ԃ̃R�s�[
		 - m_CaMuiSelect2 �́A�Z���̑I���ɍ��킹�ė�Ԃ�I���B

		  �ȉ��̃��j���[�R�}���h�Ŏg�p���܂��B
			
		 - �ŏ����v���ԗ�ԂɈړ��E���בւ��E��Ԕԍ��ň�{��
		*/
		ECreateCmd_All ,
	};

private:
	// ********************************
	///@name	�W��
	// ********************************
	///@{
	/**
		�w��ԁx�I�u�W�F�N�g�ւ̃|�C���^��ێ�����R���e�i�ł��B
		�J�����g��Ԃ�ێ����A��ԑJ�ڎ��̓���E�ޏꓮ��̌Ăяo�����s���܂��B
	*/
	CWjkStateMachine	m_StateMachine ;
	///@}

private:
	// ********************************
	///@name ����
	// ********************************
	///@{
	/**
		�\��t���ړ���(�b)�ł��B
	
		�����l�� 0 �ł��B
		�R�}���h ID_Jikokuhyou_ViewProp -> CDlgJikokuhyouViewProp 
		�ɂ���Đݒ�ł��܂��B
	 */
	CdDedJikan m_jikanPasteIdouryou ;
	/**
		�ʉ߉w�̉w������\�����邩�ۂ��̎w��ł��B
	
		- true ; �ʉ߉w�̉w������\�����܂��B(default)
		- false ; �ʉ߉w�̉w������\�������ɁA�ʉ߃}�[�N "�" ��\�����܂��B
	 */
	bool m_bDisplayTsuukaEkiJikoku ;

	/**
		�S�w�̉w������\�����邩�ۂ��̎w��

		-true ; �w�̉w�����`��(CentDedEki::m_eEkijikokukeisiki )�Ƃ͖��֌W�ɁA
			�����\�r���[�ɑS�w�̒���������\�����܂��B
		-false ; (default)
	*/
	bool m_bDisplayAllEkiJikoku ;

	/** 
		�����\�r���[�̉w�����ł́u���בւ��v�̃��[�h�B 
		����́A�w���ł̃\�[�g�ł��B
		�ŏ��� OnUpdate() �ŁA .ini �t�@�C������ǂݍ��݂܂��B
	 */
	EEkijikokuSort	m_eEkijikokuSort ;

	/**
		�J�グ�E�J�艺���̗L���E�����������܂��B
		
		����́A�L���ł��B
		�ŏ��� OnUpdate() �ŁA .ini �t�@�C������ǂݍ��݂܂��B
	 */
	bool	m_bModifyEkijikoku ;

	/**
		�w�w�����ύX�x�̑���̓��e��ێ����܂��B
		
		set... ���\�b�h�ŕύX�ł��܂��B
	*/
	CentDedRessya_EkijikokuModifyOperation2	m_EkijikokuModifyOperation2 ;
	///@}
private:
	// --------------------------------
	///@name	�����f�[�^
	// --------------------------------
	///@{
	/**
	 	���O�̃y�[�X�g����ŁA�N���b�v�{�[�h�̗�ԂɓK�p�����ړ����ł��B
	 
	 	�����l�� 0 �ł��B
	 	���̃r���[�ŗ�Ԃ̃R�s�[�E�؂���̓�����s����
	 	�i�N���b�v�{�[�h�ւ̗�Ԃ̊i�[���s�����j�Ƃ��ɁA
		0 �ɂȂ�܂��B
	 	���̌�́w��Ԃ̓\��t���x���s�����Ƃ��ɂ́A
	 	�N���b�v�{�[�h���̗�Ԃ̊e�w�̎�����
	 
	 	(m_jikanPasteIdouryou + m_jikanPasteIdouryouPrevValue )
	 
	 	�̒l��\��t���āA���̌�
	 
	 	 m_jikanPasteIdouryouPrevValue += m_jikanPasteIdouryou 
	 
	 	�Ƃ��܂��B
	 */
	CdDedJikan m_jikanPasteIdouryouPrevValue ;

	/**
	 	���̕ϐ��� true �̂Ƃ��́A
	 	������r���[�̍X�V���A���Ƀr���[���A�N�e�B�u�������܂�
	 	�ۗ����Ă��邱�Ƃ������܂��B

		�����l�� true �ł��B����́A�ŏ��̉�ʂ̍X�V�͕K��
		OnUpdate_All() �ōs���K�v�����邽�߂ł��B

		�ʏ�� false �ł��B
	 	�u���̃r���[���A�N�e�B�u�łȂ��Ƃ��̑S�X�V
		( OnUpdate_All() �j�v����A
	 	�u�r���[���A�N�e�B�u�ɂȂ�܂ł̊ԁv���� true �ɂȂ�܂��B

		���̕ϐ��� true �̂Ƃ��́A
		�u�r���[���A�N�e�B�u�ȏ�Ԃł� OnUpdate_All() �v
		�܂ŁA������X�V����͍s���܂���B
		���̏ꍇ�́A OnUpdate�̉����֐�( OnUpdate_SetYColumn() , 
		OnUpdate_setRessya() ,OnUpdate_setAllRessyaBorder() �Ȃ�) 
		�́A�����s�킸��return ���܂��B

	 	���̒l�� true �̂Ƃ��ɁA�r���[���A�N�e�B�u�����ꂽ��A
	 	OnUpdate_All() �����s���܂��B
	 
	 */
	bool m_bUpdate_All_Requested ;

	/**
		������Ԃ� false �B
		����� OnUpdate() �ŁA�@.ini �t�@�C������
		�\���Ɋւ���ݒ��ǂݍ��񂾂� true �ɕς��܂��B
	*/
	bool m_bReadCWndJikokuhyouDefault ;

	///@}

protected:
	// --------------------------------
	///@name �����֐�
	// --------------------------------
	///@{
	/**
	  @return
	 	�Ή�����h�L�������g�I�u�W�F�N�g��Ԃ��܂��B
	 */
	CJikokuhyouDoc*	GetDocument() ;
	
	/**
	  @return
	 	���̃O���b�h��������ԕ�����Ԃ��܂��B
	 */
	ERessyahoukou getRessyahoukou() ;
	

	/**
	  @return
	 	CentDedDia �I�u�W�F�N�g��Ԃ��܂��B
	  @attention
	 	���̊֐��� OnCreate() �E�y�т���ȑO��
	 	�Ăяo�����Ƃ��́A�߂�l��NULL�ɂȂ�܂��B
	 	�Ăяo�������ɒ��ӂ��Ă��������B
	 */
	const CentDedDia*	getCentDedDia();
	

	/**
	  @return
	 	CentDedRessyaCont �I�u�W�F�N�g��Ԃ��܂��B
	  @attention
	 	���̊֐��� OnCreate() �E�y�т���ȑO��
	 	�Ăяo�����Ƃ��́A�߂�l��NULL�ɂȂ�܂��B
	 	�Ăяo�������ɒ��ӂ��Ă��������B
	 */
	const CentDedRessyaCont*	getCentDedRessyaCont() ;


	bool getUpdate_All_Requested()const{	return m_bUpdate_All_Requested ;};

	///@}

	// --------------------------------
	///@name updateUI...() �E�Z���̍X�V
	///@note CWjkState �h���N���X��������p���܂��B
	// --------------------------------
	///@{
	/**
	 	�֘A����h�L�������g CJikokuhyouDoc �̓��e���A���̃E�C���h�E�Ɋ��S��
	 	���f���܂��B
	 	���̂Ƃ��A�E�C���h�E�̍X�V�ĕ`����������܂��B
	 */
	virtual void  updateUIAll() ;

	/**
	 	�֘A����h�L�������g CJikokuhyouDoc �̓��e�ɏ]���āA��ԏ��̗���X�V���܂��B

		Y��̐��E�����̍��ږ���͍X�V���܂���B		

	 	- 1. ��Ԃ̐��ɏ]���āAX�񐔂�ݒ肵�܂��B
	 	- 2. ���ׂĂ̗�Ԃ�ݒ肵�܂��B
	 	- 3. �e��Ԃ̉E���̌r����ݒ肵�܂��B
	 */
	virtual void  updateUISetAllRessya() ;
	/**
	�Z�����̗�Ԃ�u�������܂��B

	Y��̐��E�����̍��ږ���͍X�V���܂���B		

	@param iDstRessyaIndex [in]
		�@�폜�E�ǉ��ΏۂƂȂ��Ԃ̗��Index���w�肵�Ă��������B
	@param iDstDelCount [in] 
		�@�폜�����(�u���ɂ���Ď�����)��Ԃ̐����w�肵�Ă��������B
	@param iInsertCount [in]
		�@�ǉ������(�u���ɂ���ĐV���ɐ�����ύX���ꂽ)��Ԃ̐����w�肵�Ă��������B
	*/
	void updateUI_ReplaceRessya( 
		int iDstRessyaIndex , 
		int iDstDelCount , 
		int iInsertCount ) ;

	///@}
protected:
	// --------------------------------
	///@name MFC�R�}���h�n���h�������֐�
	// --------------------------------
	///@{
	/** [�t�@�C��]-[�����\CSV�t�@�C��]-[CSV�փG�N�X�|�[�g]
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
				�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂��B
	@return
		0�ȏ�͐����A���̐��̓G���[�ł��B
	*/
	int OnFileExportJikokuhyoucsv_Process( BOOL bQueryEnable ) ;
	
	/** [�t�@�C��]-[�����\CSV�t�@�C��]-[CSV����C���|�[�g]
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
				�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂��B
	@return
		0�ȏ�͐����A���̐��̓G���[�ł��B
		-	-1  ;	//	�Z���̏ꏊ���s��
		-	-2 ;	//	Cancel����܂����B
		-	-11 ;	//	�t�@�C����������܂���B
		-	-12 ;	//	CSV�̉��߂Ɏ��s���܂����B
		-	-101 ; // �s�����Ȃ����܂��B
		-	-102 ; // �񂪏��Ȃ����܂��B
		-	-103 ; // �t�@�C���`�����F���ł��܂���
		-	-104 ; // �t�@�C���`�����F���ł��܂���
		-	-111 ; // �w����������܂���B
		-	-121 ; // iDiaIndex ���s���ł��B
		-	-122 ; // iRessyaIndex ���s���ł��B 
	*/
	int OnFileImportJikokuhyoucsv_Process( BOOL bQueryEnable ) ; 

	/** [�����\]-[�����\�r���[�̃v���p�e�B]
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
				 �G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂��B
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	�_�C�A���O�{�b�N�X�ł̓��͂��K�p����܂����B
		-	0 ;	//	�_�C�A���O�{�b�N�X�ł̓��͂��L�����Z������܂����B
	*/
	int OnJikokuhyouViewProp_Process( BOOL bQueryEnable ) ;

	/** [�w����]-[�_�C���O�����ֈړ�]
	@param bQueryEnable [in]
		- TRUE ;	�R�}���h�����ݎ��s�ł��邩�ۂ��̔��肾�����s���܂��B@n
					�G���[���b�Z�[�W�̕\���͍s���܂���B
		- FALSE ;	�R�}���h�����s���܂��B @n
				�G���[�����������ꍇ�́A�G���[���b�Z�[�W�{�b�N�X��\�����܂��B
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	-11  ;	//	�Z���̏ꏊ���s��
		-	-2 ;	//	�_�C���O�����r���[�̃I�[�v���Ɏ��s���܂���
		-	-3 ;	//	�_�C���O�����r���[�̃I�[�v���Ɏ��s���܂���
	*/
	int OnJikokuhyouDiagramHeIdou_Process( BOOL bQueryEnable ) ; 

	/** [�\��]-[�ʉ߉w�̉w������\��] 
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	1 	(bQueryEnable==TRUE�̏ꍇ)[�S������\��]���L���ł��B
		-	0 	(bQueryEnable==TRUE�̏ꍇ)[�S������\��]�������ł��B
	*/
	int OnVIEWDisplayTsuukaEkiJikoku_Process( BOOL bQueryEnable ) ; 

	/** [�\��]-[�S������\��] 
	@return
		0�ȏ�͐����A�G���[�Ȃ畉�̐��ł��B
		-	1 	(bQueryEnable==TRUE�̏ꍇ)[�S������\��]���L���ł��B
		-	0 	(bQueryEnable==TRUE�̏ꍇ)[�S������\��]�������ł��B
	*/
	int OnViewDisplayallekijikoku_Process( BOOL bQueryEnable ) ; 

	/** �\��t���ړ��X�e�[�^�X�o�[
	@return
		�X�e�[�^�X�o�[�e�L�X�g��Ԃ��܂��B
		�A�����̓��[�h�Ȃ�A�w�A�����̓��[�h�x��Ԃ��܂��B
		����ȊO�Ȃ�A�\��t���ړ��ʂ̕������Ԃ��܂��B
	*/
	CString OnUpdateINDICATOR_PasteZoubun_Process() ; 

	///@}

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
	 	�V������E�s�̃T�C�Y�����v�Z���֎~���܂�(�`�捂�����̂���)
	 */
	virtual void OnCreateXColumn( int iXColumnNumber , 
		CDcdGridXColumn* pCDcdGridXColumn ) ;
	
	/**
	�@this �́A�V���� Column ���������ꂽ����ɁA���̊֐����Ăяo���܂��B
	�V���� Column �ɑ΂��āA IfDcDraw �C���^�[�t�F�[�X�I�u�W�F�N�g
	�̐����E�o�^���͂��߂Ƃ���
	���������s���܂��B

	�@���̊֐����I�[�o���C�h���邱�Ƃɂ��A Column �ɓ��L�̏�������
	�s�����Ƃ��ł��܂��B

	  @param iYColumnNumber [in]
	 	  �V���� Column �̗�ԍ��ł��B
	  @param pCDcdGridYColumn [in,out]
	 	  �V�����������ꂽ CDcdGridYColumn �I�u�W�F�N�g�ł��B
	 	  ���̊֐��͂��̃I�u�W�F�N�g�ɑ΂��āA���������s�����Ƃ��ł��܂��B
	 	
	 	
	  [�I�[�o���C�h]
	 	�V������E�s�̃T�C�Y�����v�Z���֎~���܂�(�`�捂�����̂���)
	 */
	virtual void OnCreateYColumn( int iYColumnNumber , 
		CDcdGridYColumn* pCDcdGridYColumn ) ;
	
	///@}
	// ********************************
	//	CWndDcdGrid2
	// ********************************
protected:
	// --------------------------------
	///@name CWndDcdGrid2-�C�x���g�����̂��߂̉��z�֐�
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
	 CWjkState �ɈϏ����܂��B
	  
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
	�@CWjkState �ɈϏ����܂��B
	  
	   @param iFixafterColumnNumber [in]
	  	�V���� FixafterColumnNumber �ł��B
	 */
	virtual void OnSetXFixafterColumnNumber( int iFixafterColumnNumber ) ;

	/**
	 this �́AFixafterColumnNumber ���ω������Ƃ�
	�i�X�N���[���ʒu���ω������Ƃ��j�ɁA���̉��z�֐����Ăяo���܂��B
	�N���X���[�U�[�́A���̉��z�֐����I�[�o���C�h���āA�K�v�ȏ�����
	�����ł��܂��B

	�@this �́A�N���X���[�U�[�� 
	setYFixafterColumnNumber() �Œl��ݒ肵���Ƃ��̂ق��A
	�L�[�{�[�h�Ńt�H�[�J�X�Z�����ړ��������ʃX�N���[�������������Ƃ��E
	�X�N���[���o�[�ŃE�C���h�E���X�N���[�������Ƃ��ɂ�
	���̉��z�֐����Ăяo���܂��B

	[�I�[�o���C�h]
	�@CWjkState �ɈϏ����܂��B
	  
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
	//	�R���X�g���N�^
	// ********************************
	CWndJikokuhyou();
	virtual ~CWndJikokuhyou();

public:
	// ********************************
	///@name	CWndJikokuhyou-���/�W��
	// ********************************
	///@{
	CWjkStateMachine* getStateMachine()
	{
		return &m_StateMachine ;
	}
	///@}
public:
	// ********************************
	///@name CWndJikokuhyou-����
	// ********************************
	///@{


	int getPasteIdouryou()const{ return m_jikanPasteIdouryou ;};

	bool getDisplayTsuukaEkiJikoku()const ;
	/**
	 @return
		- 1 ;	�ݒ��ύX���āA�E�C���h�E���ĕ`�悵�܂����B
		- 0 ;	�\�����e�͕ω����܂���ł����B
	*/
	int setDisplayTsuukaEkiJikoku( bool value ) ;

	bool getDisplayAllEkiJikoku()const;
	/**
	 @return
		- 1 ;	�ݒ��ύX���āA�E�C���h�E���ĕ`�悵�܂����B
		- 0 ;	�\�����e�͕ω����܂���ł����B
	*/
	int setDisplayAllEkiJikoku( bool value );

	EEkijikokuSort	getEkijikokuSort()const{	return m_eEkijikokuSort ;};
	void setEkijikokuSort( EEkijikokuSort eEkijikokuSort ){	m_eEkijikokuSort = eEkijikokuSort ;};

	bool getModifyEkijikoku()const{	return m_bModifyEkijikoku ;};
	void setModifyEkijikoku( bool value );

	CentDedRessya_EkijikokuModifyOperation2 getEkijikokuModifyOperation2()const
	{	return m_EkijikokuModifyOperation2 ;}
	void setEkijikokuModifyOperation2( const CentDedRessya_EkijikokuModifyOperation2& value )
	{	m_EkijikokuModifyOperation2 = value ;};

	///@}
public:
	// ********************************
	///@name CJikokuhyouView ����̈Ϗ�
	// ********************************
	///@{
	/**
	  	�e�E�C���h�E�� CJikokuhyouView �́AOnUpdate() ��
	  	���̃��\�b�h�ɈϏ����Ă��������B
	 */
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	/**
	  	�e�E�C���h�E�� CJikokuhyouView OnActivateView() ��
	  	���̃��\�b�h�ɈϏ����Ă��������B
	 */
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) ;
	///@}

public:
	// ********************************
	///@name static CWndJikokuhyou-����
	// ********************************
	///@{
	/**
	 CdYColSpec(Y��̕\�����e) ��
	CdDedJikokuOrder(�w�����̗v�f����肷��l) �ɕϊ����܂��B
	@param aYColSpec [in]
		Y��̕\�����e���w�肵�Ă��������B
	@return 
		CdDedJikokuOrder(�w�����̗v�f����肷��l)��Ԃ��܂��B
		aYColSpec ���w�����łȂ��ꍇ�́ANULL��Ԃ��܂��B
	*/
	static CdDedJikokuOrder CdDedJikokuOrderOf( 
		const CdYColSpec& aYColSpec ) ;

	/**
	 CdDedJikokuOrder(�w�����̗v�f����肷��l) ��
	CdYColSpec(Y��̕\�����e) 
	�ɕϊ����܂��B
	@param aJikokuOrder [in]
		CdDedJikokuOrder(�w�����̗v�f����肷��l) ���w�肵�Ă��������B
	@return 
		CdYColSpec(Y��̕\�����e) ��Ԃ��܂��B
		aJikokuOrder ���������Ȃ��ꍇ�́ANULL��Ԃ��܂��B
	*/
	static CdYColSpec CdYColSpecOf( 
		const CdDedJikokuOrder& aJikokuOrder ) ;
	///@}
public:
	// ********************************
	///@name CWndJikokuhyou-����
	// ********************************
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
		���̑Ή��\�́A CentDedRessyaCont�ECentDedRessya �ɕύX������
		�����疳���ɂȂ�܂��B���̂��߁ACentDedRessyaCont�ECentDedRessya  ��
		�ύX�̉\��������󋵂ł́A�Ή��\���č쐬����K�v������܂��B	
	*/
	CdXColSpecCont createXColSpecCont() ;


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
		���̑Ή��\�́A CentDedEkiCont�ECentDedEki �ɕύX������
		�����疳���ɂȂ�܂��B���̂��߁A CentDedEkiCont�ECentDedEki �ɕύX��
		�\��������󋵂ł́A�Ή��\���č쐬����K�v������܂��B	
	*/
	CdYColSpecCont createYColSpecCont() ;

	/**
	@return 
		�t�H�[�J�X�Z���̗�̕\�����e��Ԃ��܂��B
	*/
	CdXColSpec getXColSpecOfFocus() ;
	
	/**
	@return 
		�t�H�[�J�X�Z���̗�̕\�����e��Ԃ��܂��B
	*/
	CdYColSpec getYColSpecOfFocus() ;
	
	/**
	�t�H�[�J�X�Z���ړ����[�h bJikokuhyouFocusToRight �ɏ]���A
	�t�H�[�J�X�Z�����A���̈ʒu�Ɉړ����܂��B
	@param bJikokuhyouFocusToRight [in]
		- false ;	//	�t�H�[�J�X���ړ����[�h 
		- true ;	//	�t�H�[�J�X�E�ړ����[�h
	 @param bNextEkiOrder [in]
		m_bJikokuhyouFocusMoveRight ���U�ŁA���݂̃t�H�[�J�X�Z�����A
		�����\���̉w�����̒������ɂ���ꍇ�́A�t�H�[�J�X�̈ړ����
		�w�肵�܂��B
		- true ;	//	�t�H�[�J�X�Z�������̉wOrder�Ɉړ����܂��B
		- false ;	//	�t�H�[�J�X�Z���𓯂��w�̔������Ɉړ����܂��B
	 @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	virtual int moveFocusCellToNext( 
		bool bJikokuhyouFocusToRight , 
		bool bNextEkiOrder ) ;
	
	/**
	�t�H�[�J�X�Z���ړ����[�h bJikokuhyouFocusToRight �ɏ]���A
	�t�H�[�J�X�Z�����A�O�̈ʒu�Ɉړ����܂��B
	@param bJikokuhyouFocusToRight [in]
		- false ;	//	�t�H�[�J�X���ړ����[�h 
		- true ;	//	�t�H�[�J�X�E�ړ����[�h
	@param bNextEkiOrder [in]
		m_bJikokuhyouFocusMoveRight ���U�ŁA���݂̃t�H�[�J�X�Z�����A
		�����\���̉w�����̔������ɂ���ꍇ�́A�t�H�[�J�X�̈ړ����
		�w�肵�܂��B
		- true ;	//	�t�H�[�J�X�Z����O�̉wOrder�Ɉړ����܂��B
		- false ;	//	�t�H�[�J�X�Z���𓯂��w�̒������Ɉړ����܂��B
	 @return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
	*/
	virtual int moveFocusCellToPrev( 
		bool bJikokuhyouFocusToRight , 
		bool bNextEkiOrder ) ;



	/**
	EditCmd::CRfEditCmd_Ressya �I�u�W�F�N�g���́A�I�����ꂽ���ׂĂ�
	��Ԃɑ΂��āA m_CdModifyEkijikokuCmd
	�̓��e�����s���܂��B

	@param pCmd [in]
		�R�}���h��K�p�����Ԃ��i�[���A�I�������I�u�W�F�N�g���w�肵�Ă��������B
	@param aCdJikokuOrder [in]
		�R�}���h��K�p���鎞��Order���w�肵�Ă��������B
	@return 
		���������� 0 �ȏ�A�G���[�Ȃ畉�̐��ł��B
		-	1 ;	//	��Ԃ̒ǉ��E�܂��̓v���p�e�B�̕ύX���s���܂����B
		-	-1 ;	//	X��ԍ����s���ł��B

		�G���[�����������ꍇ�́A�t�H�[�J�X���G���[�̔���������ԂɈړ����܂��B
		�G���[���Ȃ��ꍇ�́A�t�H�[�J�X�͈ړ����܂���B
	*/
	int execCdModifyEkijikokuCmd(
		Ou<EditCmd::CRfEditCmd_Ressya> pCmd ,
		CdDedJikokuOrder aCdJikokuOrder ) ;




	/**
	DcdGrid�ł̑I����e�ɉ������A�ҏW�R�}���h�I�u�W�F�N�g
	(CRfEditCmd_Ressya)�𐶐����܂��B
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
	bool createCmd( ECreateCmd eCreateCmd , Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>* ppCmd );

	/**
	�I��͈̗͂�Ԃ�ێ�����A�ҏW�R�}���h�I�u�W�F�N�g
	(CRfEditCmd_Ressya)�𐶐����܂��B
	@param iRessyaIndex [in]
		�擪�̗��Index ���w�肵�Ă��������B
	@param iRessyaCount [in]
		��Ԃ̐����w�肵�Ă��������B
	@param ppCmd [out] 
		���������R�}���h��Ԃ��܂��B
		NULL ���w�肷�邱�Ƃ��ł��܂��B���̏ꍇ�A���̊֐���
		�R�}���h�𐶐������ɁA�R�}���h�̐������\���ۂ�������Ԃ��܂��B
	@return
		ppCmd���L����Ou�ł���ꍇ�́A�R�}���h�̐����ɐ��������� true��Ԃ��܂��B
		ppCmd=NULL �̏ꍇ�́A�R�}���h�̐������\�ł����true��Ԃ��܂��B
		�R�}���h�������ł��Ȃ��ꍇ�� false ��Ԃ��܂��B

		���������I�u�W�F�N�g�́A�ȉ��̑����ɂȂ�܂��B
		- m_iIndexDst = �I������Ă����Ԃ̐擪index
		- m_iIndexSize = iRessyaCount
		- m_CentDedRessyaCont = iRessyaIndex����iRessyaCount �܂ł�
			��Ԃ̃R�s�[
		- m_CaMuiSelect �́A�S��Ԃ�I���B

	@note
	  �ȉ��̃��j���[�R�}���h�Ŏg�p���܂��B
		���ʉ�(���ʉ��ΏۂƂȂ���Index�܂ł̃R�}���h�I�u�W�F�N�g�𐶐����A
		�R�}���h��ǉ����܂��B)
	*/
	bool createCmd( int iRessyaIndex , int iRessyaCount , 
		Ou<DedRosenFileData::EditCmd::CRfEditCmd_Ressya>* ppCmd) ;


	///@}

// ----------------------------------------------------------------
//	MFC
// ----------------------------------------------------------------
// �A�g���r���[�g
public:

// �I�y���[�V����
public:
	//{{AFX_VIRTUAL(CWndJikokuhyou)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CWndJikokuhyou)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnJikokuhyouRessyaProp();
	afx_msg void OnUpdateJikokuhyouRessyaProp(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouRessyaInsert();
	afx_msg void OnUpdateJikokuhyouRessyaInsert(CCmdUI* pCmdUI);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditPasteEkiJikoku();
	afx_msg void OnUpdateEditPasteEkiJikoku(CCmdUI* pCmdUI);
	afx_msg void OnEditSelectAll();
	afx_msg void OnUpdateEditSelectAll(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouTsuuka();
	afx_msg void OnUpdateJikokuhyouTsuuka(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouKeiyunasi();
	afx_msg void OnUpdateJikokuhyouKeiyunasi(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouSihatsu();
	afx_msg void OnUpdateJikokuhyouSihatsu(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouSyuuchaku();
	afx_msg void OnUpdateJikokuhyouSyuuchaku(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouRenzoku();
	afx_msg void OnUpdateJikokuhyouRenzoku(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouViewProp();
	afx_msg void OnJikokuhyouFocusMoveDown();
	afx_msg void OnUpdateJikokuhyouFocusMoveDown(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouFocusMoveRight();
	afx_msg void OnUpdateJikokuhyouFocusMoveRight(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuProp();
	afx_msg void OnUpdateJikokuhyouEkijikokuProp(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuInsert();
	afx_msg void OnUpdateJikokuhyouEkijikokuInsert(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuErase();
	afx_msg void OnUpdateJikokuhyouEkijikokuErase(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouModifyEkijikokuCmd();
	afx_msg void OnUpdateJikokuhyouModifyEkijikokuCmd(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouModifyEkijikokuCmdRepeat();
	afx_msg void OnUpdateJikokuhyouModifyEkijikokuCmdRepeat(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouJikokuSakujo();
	afx_msg void OnUpdateJikokuhyouJikokuSakujo(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuDec();
	afx_msg void OnUpdateJikokuhyouEkijikokuDec(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuNext();
	afx_msg void OnUpdateJikokuhyouEkijikokuNext(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuInc();
	afx_msg void OnUpdateJikokuhyouEkijikokuInc(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouEKikanSaisyouSec();
	afx_msg void OnUpdateJikokuhyouEKikanSaisyouSec(CCmdUI* pCmdUI);
	afx_msg void OnJikokuhyouSort();
	afx_msg void OnUpdateJikokuhyouSort(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouDiagramHeIdou();
	afx_msg void OnUpdateJikokuhyouDiagramHeIdou(CCmdUI* pCmdUI);
	afx_msg void OnVIEWDisplayTsuukaEkiJikoku();
	afx_msg void OnUpdateVIEWDisplayTsuukaEkiJikoku(CCmdUI* pCmdUI);
	afx_msg void OnFileExportJikokuhyoucsv();
	afx_msg void OnFileImportJikokuhyoucsv();
	afx_msg void OnJikokuhyouEkijikokudecnomove();
	afx_msg void OnUpdateJikokuhyouEkijikokudecnomove(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuincnomove();
	afx_msg void OnUpdateJikokuhyouEkijikokuincnomove(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouEkijikokuPrev();
	afx_msg void OnUpdateJikokuhyouEkijikokuPrev(CCmdUI *pCmdUI);
	afx_msg void OnUpdateINDICATOR_PasteZoubun(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouTsuukateisya();
	afx_msg void OnUpdateJikokuhyouTsuukateisya(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouDirect();
	afx_msg void OnUpdateJikokuhyouDirect(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouUndirect();
	afx_msg void OnUpdateJikokuhyouUndirect(CCmdUI *pCmdUI);
	afx_msg void OnViewDisplayallekijikoku();
	afx_msg void OnUpdateViewDisplayallekijikoku(CCmdUI *pCmdUI);
	afx_msg void OnJikokuhyouUnify();
	afx_msg void OnUpdateJikokuhyouUnify(CCmdUI *pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

} // namespace WndJikokuhyou 
} // namespace ViewJikokuhyou

#endif /*CWndJikokuhyou_CWndJikokuhyou_h*/
